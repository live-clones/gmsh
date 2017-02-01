// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include <stdlib.h>
#include <stack>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "Numeric.h"
#include "Context.h"
#include "OS.h"
#include "GModel.h"
#include "MPoint.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "MPyramid.h"
#include "meshGEdge.h"
#include "meshGFace.h"
#include "meshGFaceOptimize.h"
#include "meshGFaceBDS.h"
#include "meshGRegion.h"
#include "BackgroundMesh.h"
#include "BoundaryLayers.h"
#include "HighOrder.h"
#include "Generator.h"
#include "meshGFaceLloyd.h"
#include "CenterlineField.h"
#include "GFaceCompound.h"
#include "Field.h"
#include "Options.h"
#include "simple3D.h"
#include "yamakawa.h"
#include "meshGRegionRelocateVertex.h"

#include "pointInsertion.h"

#if defined(HAVE_OPTHOM)
#include "OptHomRun.h"
#include "OptHomElastic.h"
#endif

#if defined(HAVE_POST)
#include "PView.h"
#include "PViewData.h"
#endif

class TEST_IF_MESH_IS_COMPATIBLE_WITH_EMBEDDED_ENTITIES {
public:
  void operator () (GRegion *gr) {
    std::list<GEdge*> e = gr->embeddedEdges();
    std::list<GFace*> f = gr->embeddedFaces();
    if (e.empty() && f.empty())return;
    std::map<MEdge,GEdge*,Less_Edge> edges;
    std::map<MFace,GFace*,Less_Face> faces;
    std::list<GEdge*>::iterator it = e.begin();
    std::list<GFace*>::iterator itf = f.begin();
    for ( ; it != e.end() ; ++it){
      for (unsigned int i=0;i<(*it)->lines.size(); ++i){
	if (distance ((*it)->lines[i]->getVertex(0),(*it)->lines[i]->getVertex(1)) > 1.e-12)
	  edges.insert(std::make_pair(MEdge((*it)->lines[i]->getVertex(0),(*it)->lines[i]->getVertex(1)),*it));
      }
    }
    for ( ; itf != f.end() ; ++itf){
      for (unsigned int i=0;i<(*itf)->triangles.size(); ++i){
	faces.insert(std::make_pair(MFace((*itf)->triangles[i]->getVertex(0),(*itf)->triangles[i]->getVertex(1),(*itf)->triangles[i]->getVertex(2)),*itf));
      }
    }
    Msg::Info ("Searching for %d embedded mesh edges and %d embedded mesh faces in region %d", edges.size(),  faces.size(), gr->tag()); 
    for (unsigned int k=0;k<gr->getNumMeshElements();k++){
      for (int j=0;j<gr->getMeshElement(k)->getNumEdges();j++){
	edges.erase (gr->getMeshElement(k)->getEdge(j));
      }
      for (int j=0;j<gr->getMeshElement(k)->getNumFaces();j++){
	faces.erase (gr->getMeshElement(k)->getFace(j));
      }
    }
    if (edges.empty() && faces.empty()) {
      Msg::Info ("All embedded edges and faces are present in the final mesh"); 
    }
    if (edges.size()) {
      char name[256];
      sprintf(name,"missingEdgesOnRegion%d.pos",gr->tag());
      Msg::Error("Region %d : %d mesh edges that should be embedded are missing in the final mesh",gr->tag(), (int)edges.size());
      Msg::Error("Saving the missing edges in file %s",name);
      FILE *f = fopen(name,"w");
      fprintf(f,"View \" \" {\n");
      for (std::map<MEdge,GEdge*,Less_Edge>::iterator it =  edges.begin() ; it != edges.end(); ++it){
	MVertex *v1 = it->first.getVertex(0);
	MVertex *v2 = it->first.getVertex(1);
	fprintf(f,"SL(%g,%g,%g,%g,%g,%g){%d,%d};\n",v1->x(),v1->y(),v1->z(),v2->x(),v2->y(),v2->z(), it->second->tag(),it->second->tag());
      }
      fprintf(f,"};\n");
      fclose(f);
    }
    if (faces.size()) {
      char name[256];
      sprintf(name,"missingFacesOnRegion%d.pos",gr->tag());
      Msg::Error("Region %d : %d mesh faces that should be embedded are missing in the final mesh",gr->tag(), (int)faces.size());
      Msg::Error("Saving the missing faces in file %s",name);
      FILE *f = fopen(name,"w");
      fprintf(f,"View \" \" {\n");
      for (std::map<MFace,GFace*,Less_Face>::iterator it =  faces.begin() ; it != faces.end(); ++it){
	MVertex *v1 = it->first.getVertex(0);
	MVertex *v2 = it->first.getVertex(1);
	MVertex *v3 = it->first.getVertex(2);
	fprintf(f,"ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%d,%d,%d};\n",v1->x(),v1->y(),v1->z(),v2->x(),v2->y(),v2->z(),
		v3->x(),v3->y(),v3->z(),it->second->tag(),it->second->tag(),it->second->tag());
      }
      fprintf(f,"};\n");
      fclose(f);
    }
  }
};

template<class T>
static void GetQualityMeasure(std::vector<T*> &ele,
                              double &gamma, double &gammaMin, double &gammaMax,
                              double &minSICN, double &minSICNMin, double &minSICNMax,
                              double &rho, double &rhoMin, double &rhoMax,
                              double quality[3][100])
{
  for(unsigned int i = 0; i < ele.size(); i++){
    double g = ele[i]->gammaShapeMeasure();
    gamma += g;
    gammaMin = std::min(gammaMin, g);
    gammaMax = std::max(gammaMax, g);
    double s = ele[i]->minSICNShapeMeasure();
    minSICN += s;
    minSICNMin = std::min(minSICNMin, s);
    minSICNMax = std::max(minSICNMax, s);
    double r = ele[i]->rhoShapeMeasure();
    rho += r;
    rhoMin = std::min(rhoMin, r);
    rhoMax = std::max(rhoMax, r);
    for(int j = 0; j < 100; j++){
      if(s > (2*j-100) / 100. && s <= (2*j-98) / 100.) quality[0][j]++;
      if(g > j / 100. && g <= (j + 1) / 100.) quality[1][j]++;
      if(r > j / 100. && r <= (j + 1) / 100.) quality[2][j]++;
    }
  }
}

void GetStatistics(double stat[50], double quality[3][100])
{
  for(int i = 0; i < 50; i++) stat[i] = 0.;

  GModel *m = GModel::current();

  if(!m) return;

  stat[0] = m->getNumVertices();
  stat[1] = m->getNumEdges();
  stat[2] = m->getNumFaces();
  stat[3] = m->getNumRegions();

  std::map<int, std::vector<GEntity*> > physicals[4];
  m->getPhysicalGroups(physicals);
  stat[45] = physicals[0].size() + physicals[1].size() +
    physicals[2].size() + physicals[3].size();

  for(GModel::eiter it = m->firstEdge(); it != m->lastEdge(); ++it)
    stat[4] += (*it)->mesh_vertices.size();

  for(GModel::fiter it = m->firstFace(); it != m->lastFace(); ++it){
    // TODO: make this an option! if((*it)->getVisibility()){
    stat[5] += (*it)->mesh_vertices.size();
    stat[7] += (*it)->triangles.size();
    stat[8] += (*it)->quadrangles.size();
    //}
  }

  for(GModel::riter it = m->firstRegion(); it != m->lastRegion(); ++it){
    stat[6] += (*it)->mesh_vertices.size();
    stat[9] += (*it)->tetrahedra.size();
    stat[10] += (*it)->hexahedra.size();
    stat[11] += (*it)->prisms.size();
    stat[12] += (*it)->pyramids.size();
    stat[13] += (*it)->trihedra.size();
  }

  stat[14] = CTX::instance()->meshTimer[0];
  stat[15] = CTX::instance()->meshTimer[1];
  stat[16] = CTX::instance()->meshTimer[2];

  if(quality){
    for(int i = 0; i < 3; i++)
      for(int j = 0; j < 100; j++)
        quality[i][j] = 0.;
    double minSICN = 0., minSICNMin = 1., minSICNMax = -1.;
    double gamma = 0., gammaMin = 1., gammaMax = 0.;
    double rho = 0., rhoMin = 1., rhoMax = 0.;

    double N = stat[9] + stat[10] + stat[11] + stat[12] + stat[13];
    if(N){ // if we have 3D elements
      for(GModel::riter it = m->firstRegion(); it != m->lastRegion(); ++it){
        GetQualityMeasure((*it)->tetrahedra, gamma, gammaMin, gammaMax,
                          minSICN, minSICNMin, minSICNMax, rho, rhoMin, rhoMax, quality);
        GetQualityMeasure((*it)->hexahedra, gamma, gammaMin, gammaMax,
                          minSICN, minSICNMin, minSICNMax, rho, rhoMin, rhoMax, quality);
        GetQualityMeasure((*it)->prisms, gamma, gammaMin, gammaMax,
                          minSICN, minSICNMin, minSICNMax, rho, rhoMin, rhoMax, quality);
        GetQualityMeasure((*it)->pyramids, gamma, gammaMin, gammaMax,
                          minSICN, minSICNMin, minSICNMax, rho, rhoMin, rhoMax, quality);
      }
    }
    else{ // 2D elements
      N = stat[7] + stat[8];
      for(GModel::fiter it = m->firstFace(); it != m->lastFace(); ++it){
        GetQualityMeasure((*it)->quadrangles, gamma, gammaMin, gammaMax,
                          minSICN, minSICNMin, minSICNMax, rho, rhoMin, rhoMax, quality);
        GetQualityMeasure((*it)->triangles, gamma, gammaMin, gammaMax,
                          minSICN, minSICNMin, minSICNMax, rho, rhoMin, rhoMax, quality);
      }
    }
    if(N){
      stat[18] = minSICN / N; stat[19] = minSICNMin; stat[20] = minSICNMax;
      stat[21] = gamma / N;   stat[22] = gammaMin;   stat[23] = gammaMax;
      stat[25] = rho / N;     stat[25] = rhoMin;     stat[26] = rhoMax;
    }
  }

#if defined(HAVE_POST)
  stat[27] = PView::list.size();
  for(unsigned int i = 0; i < PView::list.size(); i++) {
    PViewData *data = PView::list[i]->getData(true);
    stat[28] += data->getNumPoints();
    stat[29] += data->getNumLines();
    stat[30] += data->getNumTriangles();
    stat[31] += data->getNumQuadrangles();
    stat[32] += data->getNumTetrahedra();
    stat[33] += data->getNumHexahedra();
    stat[34] += data->getNumPrisms();
    stat[35] += data->getNumPyramids();
    stat[36] += data->getNumStrings2D() + data->getNumStrings3D();
  }
#endif
}

static bool TooManyElements(GModel *m, int dim)
{
  if(CTX::instance()->expertMode || !m->getNumVertices()) return false;

  // try to detect obvious mistakes in characteristic lenghts (one of
  // the most common cause for erroneous bug reports on the mailing
  // list)
  double sumAllLc = 0.;
  for(GModel::viter it = m->firstVertex(); it != m->lastVertex(); ++it)
    sumAllLc += (*it)->prescribedMeshSizeAtVertex() * CTX::instance()->mesh.lcFactor;
  sumAllLc /= (double)m->getNumVertices();
  if(!sumAllLc || pow(CTX::instance()->lc / sumAllLc, dim) > 1.e10)
    return !Msg::GetAnswer
      ("Your choice of mesh element sizes will likely produce a very\n"
       "large mesh. Do you really want to continue?\n\n"
       "(To disable this warning in the future, select `Enable expert mode'\n"
       "in the option dialog.)", 1, "Cancel", "Continue");
  return false;
}

static bool CancelDelaunayHybrid(GModel *m)
{
  if(CTX::instance()->expertMode) return false;
  int n = 0;
  for(GModel::riter it = m->firstRegion(); it != m->lastRegion(); ++it)
    n += (*it)->getNumMeshElements();
  if(n)
    return !Msg::GetAnswer
      ("You are trying to generate a mixed structured/unstructured grid using\n"
       "the 3D Delaunay algorithm. This algorithm cannot garantee that the\n"
       "final mesh will be conforming. (You should probably use the 3D Frontal\n"
       "algorithm instead.) Do you really want to continue with the Delaunay?\n\n"
       "(To disable this warning in the future, select `Enable expert mode'\n"
       "in the option dialog.)", 1, "Cancel", "Continue");
  return false;
}

static void Mesh0D(GModel *m)
{
  for(GModel::viter it = m->firstVertex(); it != m->lastVertex(); ++it){
    GVertex *gv = *it;
    if(gv->mesh_vertices.empty())
      gv->mesh_vertices.push_back(new MVertex(gv->x(), gv->y(), gv->z(), gv));
    if(gv->points.empty())
      gv->points.push_back(new MPoint(gv->mesh_vertices.back()));
  }
  for(GModel::viter it = m->firstVertex(); it != m->lastVertex(); ++it){
    GVertex *gv = *it;
    if (gv->meshMaster() != gv){
      if (gv->correspondingVertices.empty()){
        GVertex *master = dynamic_cast<GVertex*>(gv->meshMaster());
        if(master)
          gv->correspondingVertices[gv->mesh_vertices[0]] = master->mesh_vertices[0];
      }
    }
  }
}

static void Mesh1D(GModel *m)
{
  if(TooManyElements(m, 1)) return;
  Msg::StatusBar(true, "Meshing 1D...");
  double t1 = Cpu();

  for(GModel::eiter it = m->firstEdge(); it != m->lastEdge(); ++it)
    (*it)->meshStatistics.status = GEdge::PENDING;

  Msg::ResetProgressMeter();

  int nIter = 0, nTot = m->getNumEdges();
  while(1){
    //    meshGEdge mesher;
    int nPending = 0;
    for(GModel::eiter it = m->firstEdge(); it != m->lastEdge(); ++it){
      if ((*it)->meshStatistics.status == GEdge::PENDING){
        (*it)->mesh(true);
        nPending++;
      }
      if(!nIter) Msg::ProgressMeter(nPending, nTot, false, "Meshing 1D...");
    }
    if(!nPending) break;
    if(nIter++ > 10) break;
  }

  double t2 = Cpu();
  CTX::instance()->meshTimer[0] = t2 - t1;
  Msg::StatusBar(true, "Done meshing 1D (%g s)", CTX::instance()->meshTimer[0]);
}

static void PrintMesh2dStatistics(GModel *m)
{
  FILE *statreport = 0;
  if(CTX::instance()->createAppendMeshStatReport == 1)
    statreport = Fopen(CTX::instance()->meshStatReportFileName.c_str(), "w");
  else if(CTX::instance()->createAppendMeshStatReport == 2)
    statreport = Fopen(CTX::instance()->meshStatReportFileName.c_str(), "a");
  else
    return;

  if(!statreport){
    Msg::Error("Could not open file '%s'",
               CTX::instance()->meshStatReportFileName.c_str());
    return;
  }

  double worst = 1, best = 0, avg = 0;
  double e_long = 0, e_short = 1.e22, e_avg = 0;
  int nTotT = 0, nTotE = 0, nTotGoodLength = 0, nTotGoodQuality = 0;
  int nUnmeshed = 0, numFaces = 0;

  if(CTX::instance()->createAppendMeshStatReport == 1){
    fprintf(statreport, "2D stats\tname\t\t#faces\t\t#fail\t\t"
            "#t\t\tQavg\t\tQbest\t\tQworst\t\t#Q>90\t\t#Q>90/#t\t"
            "#e\t\ttau\t\t#Egood\t\t#Egood/#e\tCPU\n");
    if(m->empty()){
      fclose(statreport);
      return;
    }
  }

  for(GModel::fiter it = m->firstFace() ; it != m->lastFace(); ++it){
    if((*it)->geomType() != GEntity::DiscreteSurface){
      worst = std::min((*it)->meshStatistics.worst_element_shape, worst);
      best = std::max((*it)->meshStatistics.best_element_shape, best);
      avg += (*it)->meshStatistics.average_element_shape *
        (*it)->meshStatistics.nbTriangle;
      e_avg += (*it)->meshStatistics.efficiency_index;
      e_long = std::max((*it)->meshStatistics.longest_edge_length, e_long);
      e_short = std::min((*it)->meshStatistics.smallest_edge_length, e_short);
      if ((*it)->meshStatistics.status == GFace::FAILED ||
          (*it)->meshStatistics.status == GFace::PENDING) nUnmeshed++;
      nTotT += (*it)->meshStatistics.nbTriangle;
      nTotE += (*it)->meshStatistics.nbEdge;
      nTotGoodLength += (*it)->meshStatistics.nbGoodLength;
      nTotGoodQuality += (*it)->meshStatistics.nbGoodQuality;
      numFaces++;
    }
  }

  Msg::Info("*** Efficiency index for surface mesh tau=%g ",
            100*exp(e_avg/(double)nTotE));

  fprintf(statreport,"\t%16s\t%d\t\t%d\t\t", m->getName().c_str(), numFaces,
          nUnmeshed);
  fprintf(statreport,"%d\t\t%8.7f\t%8.7f\t%8.7f\t%d\t\t%8.7f\t",
          nTotT, avg / (double)nTotT, best, worst, nTotGoodQuality,
          (double)nTotGoodQuality / nTotT);
  fprintf(statreport,"%d\t\t%8.7f\t%d\t\t%8.7f\t%8.1f\n",
          nTotE, exp(e_avg / (double)nTotE), nTotGoodLength,
          (double)nTotGoodLength / nTotE, CTX::instance()->meshTimer[1]);
  fclose(statreport);
}

static void Mesh2D(GModel *m)
{
  if(TooManyElements(m, 2)) return;
  Msg::StatusBar(true, "Meshing 2D...");
  double t1 = GetTimeInSeconds();

  for(GModel::fiter it = m->firstFace(); it != m->lastFace(); ++it)
    (*it)->meshStatistics.status = GFace::PENDING;

  // boundary layers are special: their generation (including vertices and curve
  // meshes) is global as it depends on a smooth normal field generated from the
  // surface mesh of the source surfaces
  if(!Mesh2DWithBoundaryLayers(m)){
    std::set<GFace*, GEntityLessThan> cf, f;
    for(GModel::fiter it = m->firstFace(); it != m->lastFace(); ++it)
      if ((*it)->geomType() == GEntity::CompoundSurface)
        cf.insert(*it);
      else
        f.insert(*it);

    Msg::ResetProgressMeter();

    int nIter = 0, nTot = m->getNumFaces();
    while(1){
      int nPending = 0;
      std::vector<GFace*> temp;
      temp.insert(temp.begin(), f.begin(), f.end());
#if defined(_OPENMP)
#pragma omp parallel for schedule (dynamic)
#endif
      for(size_t K = 0 ; K < temp.size() ; K++){
        if (temp[K]->meshStatistics.status == GFace::PENDING){
          backgroundMesh::current()->unset();
	  // meshGFace mesher(true);
          temp[K]->mesh(true);
#if defined(HAVE_BFGS)
          if(CTX::instance()->mesh.optimizeLloyd){
            if (temp[K]->geomType()==GEntity::CompoundSurface ||
                temp[K]->geomType()==GEntity::Plane ||
                temp[K]->geomType()==GEntity::RuledSurface) {
              if (temp[K]->meshAttributes.method != MESH_TRANSFINITE &&
                  !temp[K]->meshAttributes.extrude) {
                smoothing smm(CTX::instance()->mesh.optimizeLloyd, 6);
                //m->writeMSH("beforeLLoyd.msh");
                smm.optimize_face(temp[K]);
                int rec = ((CTX::instance()->mesh.recombineAll ||
                            temp[K]->meshAttributes.recombine) &&
                           !CTX::instance()->mesh.recombine3DAll);
                //m->writeMSH("afterLLoyd.msh");
                if (rec) recombineIntoQuads(temp[K]);
                //m->writeMSH("afterRecombine.msh");
              }
            }
          }
#endif
#if defined(_OPENMP)
#pragma omp critical
#endif
          {
            nPending++;
          }
        }
        if(!nIter) Msg::ProgressMeter(nPending, nTot, false, "Meshing 2D...");
      }
#if defined(_OPENMP)
#pragma omp master
#endif
      for(std::set<GFace*, GEntityLessThan>::iterator it = cf.begin();
          it != cf.end(); ++it){
        if ((*it)->meshStatistics.status == GFace::PENDING){
          backgroundMesh::current()->unset();
	  //          meshGFace mesher(true);
          (*it)->mesh(true);
#if defined(HAVE_BFGS)
          if(CTX::instance()->mesh.optimizeLloyd){
            if ((*it)->geomType()==GEntity::CompoundSurface ||
                (*it)->geomType()==GEntity::Plane ||
                (*it)->geomType()==GEntity::RuledSurface) {
              if ((*it)->meshAttributes.method != MESH_TRANSFINITE &&
                  !(*it)->meshAttributes.extrude) {
                smoothing smm(CTX::instance()->mesh.optimizeLloyd, 6);
                //m->writeMSH("beforeLLoyd.msh");
                smm.optimize_face(*it);
                int rec = ((CTX::instance()->mesh.recombineAll ||
                            (*it)->meshAttributes.recombine) &&
                           !CTX::instance()->mesh.recombine3DAll);
                //m->writeMSH("afterLLoyd.msh");
                if (rec) recombineIntoQuads(*it);
                //m->writeMSH("afterRecombine.msh");
              }
            }
          }
#endif
          nPending++;
        }
        if(!nIter) Msg::ProgressMeter(nPending, nTot, false, "Meshing 2D...");
      }
      if(!nPending) break;
      if(nIter++ > 10) break;
    }
  }

  // collapseSmallEdges(*m);

  double t2 = GetTimeInSeconds();
  CTX::instance()->meshTimer[1] = t2 - t1;
  Msg::StatusBar(true, "Done meshing 2D (%g s)", CTX::instance()->meshTimer[1]);

  PrintMesh2dStatistics(m);
}

static void FindConnectedRegions(std::vector<GRegion*> &delaunay,
                                 std::vector<std::vector<GRegion*> > &connected)
{
  const unsigned int nbVolumes = delaunay.size();
  if (!nbVolumes)return;
  while (delaunay.size()){
    std::set<GRegion*> oneDomain;
    std::stack<GRegion*> _stack;
    GRegion *r = delaunay[0];
    _stack.push(r);
    while(!_stack.empty()){
      r = _stack.top();
      _stack.pop();
      oneDomain.insert(r);
      std::list<GFace*> faces = r->faces();
      for (std::list<GFace*> :: iterator it = faces.begin(); it != faces.end() ; ++it){
        GFace *gf = *it;
        GRegion *other = gf->getRegion(0) == r ? gf->getRegion(1) : gf->getRegion(0);
        if (other != 0 && oneDomain.find(other) == oneDomain.end())
          _stack.push (other);
      }
    }
    std::vector<GRegion*> temp1,temp2;
    for (unsigned int i=0;i<delaunay.size();i++){
      r = delaunay[i];
      if (oneDomain.find(r) == oneDomain.end())temp1.push_back(r);
      else temp2.push_back(r);
    }
    connected.push_back(temp2);
    delaunay=temp1;
  }
  Msg::Info("Delaunay Meshing %d volumes with %d connected components",
            nbVolumes,connected.size());
}

template <class ITERATOR>
void fillv_(std::multimap<MVertex*, MElement*> &vertexToElement,
	    ITERATOR it_beg, ITERATOR it_end)
{
  for (ITERATOR IT = it_beg; IT != it_end ; ++IT){
    MElement *el = *IT;
    for(int j = 0; j < el->getNumVertices(); j++) {
      MVertex* e = el->getVertex(j);
      vertexToElement.insert(std::make_pair(e, el));
    }
  }
}

int LaplaceSmoothing(GRegion *gr)
{
  std::multimap<MVertex*, MElement*> vertexToElement;
  fillv_(vertexToElement, (gr)->tetrahedra.begin(), (gr)->tetrahedra.end());
  fillv_(vertexToElement, (gr)->hexahedra.begin(),  (gr)->hexahedra.end());
  fillv_(vertexToElement, (gr)->prisms.begin(),     (gr)->prisms.end());
  fillv_(vertexToElement, (gr)->pyramids.begin(),   (gr)->pyramids.end());
  int N=0;
  for (unsigned int i=0; i<gr->mesh_vertices.size();i++){
    MVertex *v = gr->mesh_vertices[i];
    std::multimap<MVertex*, MElement*>::iterator it = vertexToElement.lower_bound(v);
    std::multimap<MVertex*, MElement*>::iterator it_low = it;
    std::multimap<MVertex*, MElement*>::iterator it_up  = vertexToElement.upper_bound(v);
    double minQual = 1.e22;
    double volTot = 0.0;
    double xold=v->x(), yold=v->y(), zold=v->z();
    SPoint3 pNew (0,0,0);
    for (; it != it_up; ++it) {
      minQual= std::min(minQual,it->second->minSICNShapeMeasure());
      double vol = fabs(it->second->getVolume());
      SPoint3 cog = it->second->barycenter();
      pNew += cog * vol;
      volTot += vol;
    }
    pNew *= (1./volTot);
    v->setXYZ (pNew.x(),pNew.y(),pNew.z());
    double minQual2 = 1.e22;
    for (it = it_low; it != it_up; ++it) {
      minQual2 = std::min(minQual2,it->second->minSICNShapeMeasure());
      if (minQual2 < minQual){
	v->setXYZ (xold,yold,zold);
	break;
      }
    }
    if (minQual < minQual2) N++;
  }
  return N;
}

// JFR : use hex-splitting to resolve non conformity
//     : if howto == 1 ---> split hexes
//     : if howto == 2 ---> create transition elements

/*
 v3        v2
  x--------x
  |\       |
  |  \     |
  |    \   |
  |      \ |
  x--------x
  v0       v1
 */

void buildUniqueFaces (GRegion *gr, std::set<MFace,Less_Face> &bnd)
{
  for (unsigned int i=0;i<gr->getNumMeshElements();i++){
    MElement *e = gr->getMeshElement(i);
    for(int j=0;j<e->getNumFaces();j++){
      MFace f = e->getFace(j);
      std::set<MFace,Less_Face>::iterator it = bnd.find(f);
      if (it == bnd.end())bnd.insert(f);
      else bnd.erase(it);
    }
  }
}

bool MakeMeshConformal(GModel *gm, int howto)
{
  fs_cont search;
  buildFaceSearchStructure(gm, search);
  std::set<MFace,Less_Face> bnd;
  for (GModel::riter rit = gm->firstRegion(); rit != gm->lastRegion(); ++rit){
    GRegion *gr = *rit;
    buildUniqueFaces (gr,bnd);
  }
  // bnd2 contains non conforming faces

   std::set<MFace,Less_Face> bnd2;
  for (std::set<MFace,Less_Face>::iterator itf = bnd.begin(); itf != bnd.end(); ++itf){
    GFace *gfound = findInFaceSearchStructure (*itf,search);
    if (!gfound){
      bnd2.insert(*itf);
    }
  }
  bnd.clear();

  Msg::Info("%d hanging faces",bnd2.size());

  std::set<MFace,Less_Face> ncf;
  for (std::set<MFace,Less_Face>::iterator itf = bnd2.begin(); itf != bnd2.end(); ++itf){
    const MFace &f = *itf;
    if (f.getNumVertices() == 4){ // quad face
      std::set<MFace,Less_Face>::iterator it1 =
        bnd2.find (MFace(f.getVertex(0),f.getVertex(1),f.getVertex(2)));
      std::set<MFace,Less_Face>::iterator it2 =
        bnd2.find (MFace(f.getVertex(2),f.getVertex(3),f.getVertex(0)));
      if (it1 != bnd2.end() && it2 != bnd2.end()){
	ncf.insert(MFace(f.getVertex(1), f.getVertex(2),
                         f.getVertex(3),f.getVertex(0)));
      }
      else {
	it1 = bnd2.find (MFace(f.getVertex(0),f.getVertex(1),f.getVertex(3)));
	it2 = bnd2.find (MFace(f.getVertex(3),f.getVertex(1),f.getVertex(2)));
	if (it1 != bnd2.end() && it2 != bnd2.end()){
	  ncf.insert(MFace(f.getVertex(0), f.getVertex(1),
                           f.getVertex(2), f.getVertex(3)));
	}
	else {
	  Msg::Error("MakeMeshConformal: wrong mesh topology");
	  return false;
	}
      }
    }
  }
  bnd2.clear();

  for (GModel::riter rit = gm->firstRegion(); rit != gm->lastRegion(); ++rit){
    GRegion *gr = *rit;
    std::vector<MHexahedron*> remainingHexes;
    for (unsigned int i=0;i<gr->hexahedra.size();i++){
      MHexahedron *e = gr->hexahedra[i];
      std::vector<MFace> faces;
      for(int j=0;j<e->getNumFaces();j++){
	MFace f = e->getFace(j);
	std::set<MFace,Less_Face>::iterator it = ncf.find(f);
	if (it == ncf.end()){
	  faces.push_back(f);
	}
	else {
	  faces.push_back(MFace(it->getVertex(0),it->getVertex(1),it->getVertex(3)));
	  faces.push_back(MFace(it->getVertex(1),it->getVertex(2),it->getVertex(3)));
	}
      }
      // HEX IS ONLY SURROUNED BY COMPATIBLE ELEMENTS
      if ((int)faces.size() == e->getNumFaces()){
	remainingHexes.push_back(e);
      }
      else {
	SPoint3 pp = e->barycenter();
	MVertex *newv = new MVertex (pp.x(),pp.y(),pp.z(),gr);
	gr->mesh_vertices.push_back(newv);
	for (unsigned int j=0;j<faces.size();j++){
	  MFace &f = faces[j];
	  if (f.getNumVertices() == 4){
	    gr->pyramids.push_back(new MPyramid(f.getVertex(0), f.getVertex(1),
                                                f.getVertex(2), f.getVertex(3), newv));
	  }
	  else {
	    gr->tetrahedra.push_back(new MTetrahedron(f.getVertex(0), f.getVertex(1),
                                                      f.getVertex(2), newv));
	  }
	}
      }
    }
    gr->hexahedra = remainingHexes;
    remainingHexes.clear();
    std::vector<MPrism*> remainingPrisms;
    for (unsigned int i=0;i<gr->prisms.size();i++){
      MPrism *e = gr->prisms[i];
      std::vector<MFace> faces;
      for(int j=0;j<e->getNumFaces();j++){
	MFace f = e->getFace(j);
	std::set<MFace,Less_Face>::iterator it = ncf.find(f);
	if (it == ncf.end()){
	  faces.push_back(f);
	}
	else {
	  faces.push_back(MFace(it->getVertex(0),it->getVertex(1),it->getVertex(3)));
	  faces.push_back(MFace(it->getVertex(1),it->getVertex(2),it->getVertex(3)));
	}
      }
      // HEX IS ONLY SURROUNED BY COMPATIBLE ELEMENTS
      if ((int)faces.size() == e->getNumFaces()){
	remainingPrisms.push_back(e);
      }
      else {
	SPoint3 pp = e->barycenter();
	MVertex *newv = new MVertex (pp.x(),pp.y(),pp.z(),gr);
	gr->mesh_vertices.push_back(newv);
	for (unsigned int j=0;j<faces.size();j++){
	  MFace &f = faces[j];
	  if (f.getNumVertices() == 4){
	    gr->pyramids.push_back(new MPyramid(f.getVertex(0), f.getVertex(1),
                                                f.getVertex(2), f.getVertex(3), newv));
	  }
	  else {
	    gr->tetrahedra.push_back(new MTetrahedron(f.getVertex(0), f.getVertex(1),
                                                      f.getVertex(2), newv));
	  }
	}
      }
    }
    gr->prisms = remainingPrisms;
  }

  return true;
}

void TestConformity(GModel *gm)
{
  fs_cont search;
  buildFaceSearchStructure(gm, search);
  int count = 0;
  for (GModel::riter rit = gm->firstRegion(); rit != gm->lastRegion(); ++rit){
    GRegion *gr = *rit;
    std::set<MFace,Less_Face> bnd;
    double vol = 0.0;
    for (unsigned int i=0;i<gr->getNumMeshElements();i++){
      MElement *e = gr->getMeshElement(i);
      vol += fabs(e->getVolume());
      for(int j=0;j<e->getNumFaces();j++){
	MFace f = e->getFace(j);
	std::set<MFace,Less_Face>::iterator it = bnd.find(f);
	if (it == bnd.end())bnd.insert(f);
	else bnd.erase(it);
      }
    }
    printf("vol(%d) = %12.5E\n",gr->tag(),vol);

    for (std::set<MFace,Less_Face>::iterator itf = bnd.begin(); itf != bnd.end(); ++itf){
      GFace *gfound = findInFaceSearchStructure (*itf,search);
      if (!gfound){
	count ++;
      }
    }
  }
  if (!count)Msg::Info("Mesh Conformity: OK");
  else Msg::Error ("Mesh is not conforming (%d hanging faces)!",count);
}

static void Mesh3D(GModel *m)
{
  if(TooManyElements(m, 3)) return;
  Msg::StatusBar(true, "Meshing 3D...");
  double t1 = Cpu();

  // mesh the extruded volumes first
  std::for_each(m->firstRegion(), m->lastRegion(), meshGRegionExtruded());

  // then subdivide if necessary (unfortunately the subdivision is a
  // global operation, which can require changing the surface mesh!)
  SubdivideExtrudedMesh(m);

  // then mesh all the non-delaunay regions (front3D with netgen)
  std::vector<GRegion*> delaunay;
  std::for_each(m->firstRegion(), m->lastRegion(), meshGRegion(delaunay));

  // warn if attempting to use Delaunay for mixed meshes
  if(delaunay.size() && CancelDelaunayHybrid(m)) return;

  // and finally mesh the delaunay regions (again, this is global; but
  // we mesh each connected part separately for performance and mesh
  // quality reasons)
  std::vector<std::vector<GRegion*> > connected;
  FindConnectedRegions(delaunay, connected);

  // remove quads elements for volumes that are recombined
  // pragma OMP here ?
  for(unsigned int i = 0; i < connected.size(); i++){
    for(unsigned j = 0; j < connected[i].size(); j++){
      GRegion *gr = connected[i][j];
      if(CTX::instance()->mesh.recombine3DAll || gr->meshAttributes.recombine3D){
        std::list<GFace*> f = gr->faces();
        for(std::list<GFace*>::iterator it = f.begin(); it != f.end() ; ++it)
          quadsToTriangles(*it, 1000000);
      }
    }
  }

  double time_recombination = 0., vol_element_recombination = 0.;
  double vol_hexa_recombination = 0.;
  int nb_elements_recombination = 0, nb_hexa_recombination = 0;

  // pragma OMP here ?
  for(unsigned int i = 0; i < connected.size(); i++){
    MeshDelaunayVolume(connected[i]);

    // additional code for experimental hex mesh
    for(unsigned j = 0; j < connected[i].size(); j++){
      GRegion *gr = connected[i][j];
      bool treat_region_ok = false;
      if(CTX::instance()->mesh.algo3d == ALGO_3D_RTREE){
        if (old_algo_hexa()){
          Filler f;
          f.treat_region(gr);
          treat_region_ok = true;
        }
        else{
          Filler3D f;
          treat_region_ok = f.treat_region(gr);
        }
      }
      if(treat_region_ok && (CTX::instance()->mesh.recombine3DAll ||
                             gr->meshAttributes.recombine3D)){
        if (CTX::instance()->mesh.optimize){
          optimizeMeshGRegionGmsh opt;
          opt(gr);
        }
        double a = Cpu();

	//	CTX::instance()->mesh.recombine3DLevel = 2;

        if (CTX::instance()->mesh.recombine3DLevel >= 0){
          Recombinator rec;
          rec.execute(gr);
        }
        if (CTX::instance()->mesh.recombine3DLevel >= 1){
          Supplementary sup;
          sup.execute(gr);
        }
        PostOp post;
	printf("-----------> %d %d\n",CTX::instance()->mesh.recombine3DLevel,CTX::instance()->mesh.recombine3DConformity);
	post.execute(gr,CTX::instance()->mesh.recombine3DLevel,CTX::instance()->mesh.recombine3DConformity);
	//			     CTX::instance()->mesh.recombine3DConformity);
        // 0: no pyramid, 1: single-step, 2: two-steps (conforming),
        // true: fill non-conformities with trihedra
	RelocateVertices(gr, CTX::instance()->mesh.nbSmoothing);
        // while(LaplaceSmoothing (gr)){
        // }
	nb_elements_recombination += post.get_nb_elements();
	nb_hexa_recombination += post.get_nb_hexahedra();
	vol_element_recombination += post.get_vol_elements();
	vol_hexa_recombination += post.get_vol_hexahedra();
        // partial export
        //        stringstream ss;
        //        ss << "yamakawa_part_";
        //        ss << gr->tag();
        //        ss << ".msh";
        //        export_gregion_mesh(gr, ss.str().c_str());
        time_recombination += (Cpu() - a);
      }
    }
  }

  if(CTX::instance()->mesh.recombine3DAll){
    Msg::Info("RECOMBINATION timing:");
    Msg::Info(" --- CUMULATIVE TIME RECOMBINATION : %g s.", time_recombination);
    Msg::Info("RECOMBINATION CUMULATIVE STATISTICS:");
    Msg::Info(".... Percentage of hexahedra   (#) : %g",
              nb_hexa_recombination*100./nb_elements_recombination);
    Msg::Info(".... Percentage of hexahedra (Vol) : %g",
              vol_hexa_recombination*100./vol_element_recombination);
    //    MakeMeshConformal (m, 1);
    TestConformity(m);
  }

  // ensure that all volume Jacobians are positive
  m->setAllVolumesPositive();

  //  std::for_each(m->firstRegion(), m->lastRegion(), optimizeMeshGRegionNetgen());
  if (Msg::GetVerbosity() > 98) 
    std::for_each(m->firstRegion(), m->lastRegion(), TEST_IF_MESH_IS_COMPATIBLE_WITH_EMBEDDED_ENTITIES ());
  
  CTX::instance()->mesh.changed = ENT_ALL;
  double t2 = Cpu();
  CTX::instance()->meshTimer[2] = t2 - t1;
  Msg::StatusBar(true, "Done meshing 3D (%g s)", CTX::instance()->meshTimer[2]);
}

void OptimizeMeshNetgen(GModel *m)
{
  Msg::StatusBar(true, "Optimizing 3D mesh with Netgen...");
  double t1 = Cpu();

  std::for_each(m->firstRegion(), m->lastRegion(), optimizeMeshGRegionNetgen());
  // Ensure that all volume Jacobians are positive
  m->setAllVolumesPositive();

  if (Msg::GetVerbosity() > 98) 
    std::for_each(m->firstRegion(), m->lastRegion(), TEST_IF_MESH_IS_COMPATIBLE_WITH_EMBEDDED_ENTITIES ());
  
  double t2 = Cpu();
  Msg::StatusBar(true, "Done optimizing 3D mesh with Netgen (%g s)", t2 - t1);
}

void OptimizeMesh(GModel *m)
{
  Msg::StatusBar(true, "Optimizing 3D mesh...");
  double t1 = Cpu();

  std::for_each(m->firstRegion(), m->lastRegion(), optimizeMeshGRegionGmsh());
  // Ensure that all volume Jacobians are positive
  m->setAllVolumesPositive();

  if (Msg::GetVerbosity() > 98) 
    std::for_each(m->firstRegion(), m->lastRegion(), TEST_IF_MESH_IS_COMPATIBLE_WITH_EMBEDDED_ENTITIES ());
  
  CTX::instance()->mesh.changed = ENT_ALL;
  double t2 = Cpu();
  Msg::StatusBar(true, "Done optimizing 3D mesh (%g s)", t2 - t1);
}

void SmoothMesh(GModel *m)
{
  Msg::StatusBar(true, "Smoothing 2D mesh...");
  double t1 = Cpu();

  for(GModel::fiter it = m->firstFace(); it != m->lastFace(); ++it){
    GFace *gf = *it;
    laplaceSmoothing(gf);
  }

  CTX::instance()->mesh.changed = ENT_ALL;
  double t2 = Cpu();
  Msg::StatusBar(true, "Done smoothing 2D mesh (%g s)", t2 - t1);
}

void AdaptMesh(GModel *m)
{
  Msg::StatusBar(true, "Adapting 3D mesh...");
  double t1 = Cpu();

  for(int i = 0; i < 10; i++)
    std::for_each(m->firstRegion(), m->lastRegion(), adaptMeshGRegion());

  CTX::instance()->mesh.changed = ENT_ALL;
  double t2 = Cpu();
  Msg::StatusBar(true, "Done adaptating 3D mesh (%g s)", t2 - t1);
}

void RecombineMesh(GModel *m)
{
  Msg::StatusBar(true, "Recombining 2D mesh...");
  double t1 = Cpu();

  for(GModel::fiter it = m->firstFace(); it != m->lastFace(); ++it){
    GFace *gf = *it;
    recombineIntoQuads(gf);
  }

  CTX::instance()->mesh.changed = ENT_ALL;
  double t2 = Cpu();
  Msg::StatusBar(true, "Done recombining 2D mesh (%g s)", t2 - t1);
}

//#include <google/profiler.h>

void GenerateMesh(GModel *m, int ask)
{

  // ProfilerStart("gmsh.prof");
  if(CTX::instance()->lock) {
    Msg::Info("I'm busy! Ask me that later...");
    return;
  }
  CTX::instance()->lock = 1;

  Msg::ResetErrorCounter();

  int old = m->getMeshStatus(false);

  // Initialize pseudo random mesh generator with the same seed
  srand(1);

  // Change any high order elements back into first order ones
  SetOrder1(m);

  // 1D mesh
  if(ask == 1 || (ask > 1 && old < 1)) {
    std::for_each(m->firstRegion(), m->lastRegion(), deMeshGRegion());
    std::for_each(m->firstFace(), m->lastFace(), deMeshGFace());
    Mesh0D(m);
    Mesh1D(m);
  }

  // 2D mesh
  if(ask == 2 || (ask > 2 && old < 2)) {
    std::for_each(m->firstRegion(), m->lastRegion(), deMeshGRegion());
    Mesh2D(m);
  }

  // 3D mesh
  if(ask == 3) {
    Mesh3D(m);
  }

  // Orient the line and surface meshes so that they match the orientation of
  // the geometrical entities and/or the user orientation constraints
  if(m->getMeshStatus() >= 1)
    std::for_each(m->firstEdge(), m->lastEdge(), orientMeshGEdge());
  if(m->getMeshStatus() >= 2)
    std::for_each(m->firstFace(), m->lastFace(), orientMeshGFace());

  // Optimize quality of 3D tet mesh
  if(m->getMeshStatus() == 3){
    for(int i = 0; i < std::max(CTX::instance()->mesh.optimize,
                                CTX::instance()->mesh.optimizeNetgen); i++){
      if(CTX::instance()->mesh.optimize > i) OptimizeMesh(m);
      if(CTX::instance()->mesh.optimizeNetgen > i) OptimizeMeshNetgen(m);
    }
  }

  // Subdivide into quads or hexas
  if(m->getMeshStatus() == 2 && CTX::instance()->mesh.algoSubdivide == 1)
    RefineMesh(m, CTX::instance()->mesh.secondOrderLinear, true);
  else if(m->getMeshStatus() == 3 && CTX::instance()->mesh.algoSubdivide == 2)
    RefineMesh(m, CTX::instance()->mesh.secondOrderLinear, false, true);

  // Compute homology if necessary
  if(!Msg::GetErrorCount()) m->computeHomology();

  // Create high order elements
  if(m->getMeshStatus() && CTX::instance()->mesh.order > 1)
    SetOrderN(m, CTX::instance()->mesh.order, CTX::instance()->mesh.secondOrderLinear,
              CTX::instance()->mesh.secondOrderIncomplete);

  // Optimize high order elements
  if(CTX::instance()->mesh.hoOptimize){
#if defined(HAVE_OPTHOM)
    if(CTX::instance()->mesh.hoOptimize < 0){
      ElasticAnalogy(GModel::current(), false);
    }
    else{
      OptHomParameters p;
      p.nbLayers = CTX::instance()->mesh.hoNLayers;
      p.BARRIER_MIN = CTX::instance()->mesh.hoThresholdMin;
      p.BARRIER_MAX = CTX::instance()->mesh.hoThresholdMax;
      p.dim = GModel::current()->getDim();
      p.optPrimSurfMesh = CTX::instance()->mesh.hoOptPrimSurfMesh;
      HighOrderMeshOptimizer(GModel::current(), p);
    }
#else
    Msg::Error("High-order mesh optimization requires the OPTHOM module");
#endif
  }

  Msg::Info("%d vertices %d elements",
            m->getNumMeshVertices(), m->getNumMeshElements());

  Msg::PrintErrorCounter("Mesh generation error summary");

  CTX::instance()->lock = 0;
  CTX::instance()->mesh.changed = ENT_ALL;
  // ProfilerStop();
}
