// Gmsh - Copyright (C) 1997-2014 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

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

#if defined(HAVE_OPTHOM)
#include "OptHomRun.h"
#include "OptHomElastic.h"
#endif

#if defined(HAVE_POST)
#include "PView.h"
#include "PViewData.h"
#endif

static MVertex* isEquivalentTo(std::multimap<MVertex*, MVertex*> &m, MVertex *v)
{
  std::multimap<MVertex*, MVertex*>::iterator it = m.lower_bound(v);
  std::multimap<MVertex*, MVertex*>::iterator ite = m.upper_bound(v);
  if (it == ite) return v;
  MVertex *res = it->second; ++it;
  while (it !=ite){
    res = std::min(res,it->second); ++it;
  }
  if (res < v) return isEquivalentTo(m, res);
  return res;
}

static void buildASetOfEquivalentMeshVertices(GFace *gf,
                                              std::multimap<MVertex*, MVertex *> &equivalent,
                                              std::map<GVertex*, MVertex*> &bm)
{
  // an edge is degenerated when is length is considered to be
  // zero. In some cases, a model edge can be considered as too
  // small an is ignored.

  // for taking that into account, we loop over the edges
  // and create pairs of MVertices that are considered as
  // equal.

  std::list<GEdge*> edges = gf->edges();
  std::list<GEdge*> emb_edges = gf->embeddedEdges();
  std::list<GEdge*>::iterator it = edges.begin();

  while(it != edges.end()){
    if((*it)->isMeshDegenerated()){
      MVertex *va = *((*it)->getBeginVertex()->mesh_vertices.begin());
      MVertex *vb = *((*it)->getEndVertex()->mesh_vertices.begin());
      if (va != vb){
        equivalent.insert(std::make_pair(va, vb));
        equivalent.insert(std::make_pair(vb, va));
        bm[(*it)->getBeginVertex()] = va;
        bm[(*it)->getEndVertex()] = vb;
        printf("%d equivalent to %d\n", va->getNum(), vb->getNum());
      }
    }
    ++it;
  }

  it = emb_edges.begin();
  while(it != emb_edges.end()){
    if((*it)->isMeshDegenerated()){
      MVertex *va = *((*it)->getBeginVertex()->mesh_vertices.begin());
      MVertex *vb = *((*it)->getEndVertex()->mesh_vertices.begin());
      if (va != vb){
        equivalent.insert(std::make_pair(va, vb));
        equivalent.insert(std::make_pair(vb, va));
        bm[(*it)->getBeginVertex()] = va;
        bm[(*it)->getEndVertex()] = vb;
      }
    }
    ++it;
  }
}

struct geomThresholdVertexEquivalence
{
  // Initial MVertex associated to one given MVertex
  std::map<GVertex*, MVertex*> backward_map;
  // initiate the forward and backward maps
  geomThresholdVertexEquivalence(GModel *g);
  // restores the initial state
  ~geomThresholdVertexEquivalence ();
};

geomThresholdVertexEquivalence::geomThresholdVertexEquivalence(GModel *g)
{
  std::multimap<MVertex*, MVertex*> equivalenceMap;
  for (GModel::fiter it = g->firstFace(); it != g->lastFace(); ++it)
    buildASetOfEquivalentMeshVertices(*it, equivalenceMap, backward_map);
  // build the structure that identifiate geometrically equivalent
  // mesh vertices.
  for (std::map<GVertex*, MVertex*>::iterator it = backward_map.begin();
       it != backward_map.end(); ++it){
    GVertex *g = it->first;
    MVertex *v = it->second;
    MVertex *other = isEquivalentTo(equivalenceMap, v);
    if (v != other){
      printf("Finally : %d equivalent to %d\n", v->getNum(), other->getNum());
      g->mesh_vertices.clear();
      g->mesh_vertices.push_back(other);
      std::list<GEdge*> ed = g->edges();
      for (std::list<GEdge*>::iterator ite = ed.begin() ; ite != ed.end() ; ++ite){
        std::vector<MLine*> newl;
        for (unsigned int i = 0; i < (*ite)->lines.size(); ++i){
          MLine *l = (*ite)->lines[i];
          MVertex *v1 = l->getVertex(0);
          MVertex *v2 = l->getVertex(1);
          if (v1 == v && v2 != other){
            delete l;
            l = new MLine(other,v2);
            newl.push_back(l);
          }
          else if (v1 != other && v2 == v){
            delete l;
            l = new MLine(v1,other);
            newl.push_back(l);
          }
          else if (v1 != v && v2 != v)
            newl.push_back(l);
          else
            delete l;
        }
        (*ite)->lines = newl;
      }
    }
  }
}

geomThresholdVertexEquivalence::~geomThresholdVertexEquivalence()
{
  // restore the initial data
  for (std::map<GVertex*, MVertex*>::iterator it = backward_map.begin();
       it != backward_map.end() ; ++it){
    GVertex *g = it->first;
    MVertex *v = it->second;
    g->mesh_vertices.clear();
    g->mesh_vertices.push_back(v);
  }
}

template<class T>
static void GetQualityMeasure(std::vector<T*> &ele,
                              double &gamma, double &gammaMin, double &gammaMax,
                              double &eta, double &etaMin, double &etaMax,
                              double &rho, double &rhoMin, double &rhoMax,
                              double &disto, double &distoMin, double &distoMax,
                              double &scaledJacMin, double &scaledJacMax,
                              double quality[4][100])
{
  for(unsigned int i = 0; i < ele.size(); i++){
    double g = ele[i]->gammaShapeMeasure();
    gamma += g;
    gammaMin = std::min(gammaMin, g);
    gammaMax = std::max(gammaMax, g);
    double e = ele[i]->etaShapeMeasure();
    eta += e;
    etaMin = std::min(etaMin, e);
    etaMax = std::max(etaMax, e);
    double r = ele[i]->rhoShapeMeasure();
    rho += r;
    rhoMin = std::min(rhoMin, r);
    rhoMax = std::max(rhoMax, r);
    double jmin,jmax; ele[i]->scaledJacRange(jmin,jmax);
    double d = jmin;
    disto += d;
    distoMin = std::min(distoMin, d);
    distoMax = std::max(distoMax, d);
    scaledJacMin = std::min(scaledJacMin, jmin);
    scaledJacMax = std::max(scaledJacMax, jmax);

    for(int j = 0; j < 100; j++){
      if(g > j / 100. && g <= (j + 1) / 100.) quality[0][j]++;
      if(e > j / 100. && e <= (j + 1) / 100.) quality[1][j]++;
      if(r > j / 100. && r <= (j + 1) / 100.) quality[2][j]++;
      if(d > j / 100. && d <= (j + 1) / 100.) quality[3][j]++;
    }
  }
}

void GetStatistics(double stat[50], double quality[4][100])
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
    stat[5] += (*it)->mesh_vertices.size();
    stat[7] += (*it)->triangles.size();
    stat[8] += (*it)->quadrangles.size();
  }

  for(GModel::riter it = m->firstRegion(); it != m->lastRegion(); ++it){
    stat[6] += (*it)->mesh_vertices.size();
    stat[9] += (*it)->tetrahedra.size();
    stat[10] += (*it)->hexahedra.size();
    stat[11] += (*it)->prisms.size();
    stat[12] += (*it)->pyramids.size();
  }

  stat[13] = CTX::instance()->meshTimer[0];
  stat[14] = CTX::instance()->meshTimer[1];
  stat[15] = CTX::instance()->meshTimer[2];

  if(quality){
    for(int i = 0; i < 3; i++)
      for(int j = 0; j < 100; j++)
        quality[i][j] = 0.;
    double gamma = 0., gammaMin = 1., gammaMax = 0.;
    double eta = 0., etaMin = 1., etaMax = 0.;
    double rho = 0., rhoMin = 1., rhoMax = 0.;
    double disto = 0., distoMin=1., distoMax = 0.;
    double jmin = 1.e22, jmax = -1.e22;

    double N = stat[9] + stat[10] + stat[11] + stat[12];
    if(N){ // if we have 3D elements
      for(GModel::riter it = m->firstRegion(); it != m->lastRegion(); ++it){
        GetQualityMeasure((*it)->tetrahedra, gamma, gammaMin, gammaMax,
                          eta, etaMin, etaMax, rho, rhoMin, rhoMax,
                          disto, distoMin, distoMax, jmin, jmax, quality);
        GetQualityMeasure((*it)->hexahedra, gamma, gammaMin, gammaMax,
                          eta, etaMin, etaMax, rho, rhoMin, rhoMax,
                          disto, distoMin, distoMax, jmin, jmax, quality);
        GetQualityMeasure((*it)->prisms, gamma, gammaMin, gammaMax,
                          eta, etaMin, etaMax, rho, rhoMin, rhoMax,
                          disto, distoMin, distoMax,jmin, jmax, quality);
        GetQualityMeasure((*it)->pyramids, gamma, gammaMin, gammaMax,
                          eta, etaMin, etaMax, rho, rhoMin, rhoMax,
                          disto, distoMin, distoMax, jmin, jmax, quality);
      }
    }
    else{ // 2D elements
      N = stat[7] + stat[8];
      for(GModel::fiter it = m->firstFace(); it != m->lastFace(); ++it){
        GetQualityMeasure((*it)->quadrangles, gamma, gammaMin, gammaMax,
                          eta, etaMin, etaMax, rho, rhoMin, rhoMax,
                          disto, distoMin, distoMax, jmin, jmax, quality);
        GetQualityMeasure((*it)->triangles, gamma, gammaMin, gammaMax,
                          eta, etaMin, etaMax, rho, rhoMin, rhoMax,
                          disto, distoMin, distoMax, jmin, jmax, quality);
      }
    }
    if(N){
      stat[17] = gamma / N ;  stat[18] = gammaMin;  stat[19] = gammaMax;
      stat[20] = eta / N ;    stat[21] = etaMin;    stat[22] = etaMax;
      stat[23] = rho / N ;    stat[24] = rhoMin;    stat[25] = rhoMax;
      stat[46] = disto / N ;  stat[47] = distoMin;  stat[48] = distoMax;
    }
  }

#if defined(HAVE_POST)
  stat[26] = PView::list.size();
  for(unsigned int i = 0; i < PView::list.size(); i++) {
    PViewData *data = PView::list[i]->getData(true);
    stat[27] += data->getNumPoints();
    stat[28] += data->getNumLines();
    stat[29] += data->getNumTriangles();
    stat[30] += data->getNumQuadrangles();
    stat[31] += data->getNumTetrahedra();
    stat[32] += data->getNumHexahedra();
    stat[33] += data->getNumPrisms();
    stat[34] += data->getNumPyramids();
    stat[35] += data->getNumStrings2D() + data->getNumStrings3D();
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
    if (gv->meshMaster() != gv->tag()){
      if (gv->correspondingVertices.empty()){
	GVertex *master = m->getVertexByTag(abs(gv->meshMaster()));
	if(master)gv->correspondingVertices[gv->mesh_vertices[0]] = (master->mesh_vertices[0]);
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
    meshGEdge mesher;
    int nPending = 0;
    for(GModel::eiter it = m->firstEdge(); it != m->lastEdge(); ++it){
      if ((*it)->meshStatistics.status == GEdge::PENDING){
	mesher(*it);
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
  else return;

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
      avg += (*it)->meshStatistics.average_element_shape * (*it)->meshStatistics.nbTriangle;
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

  Msg::Info("*** Efficiency index for surface mesh tau=%g ", 100*exp(e_avg/(double)nTotE));

  fprintf(statreport,"\t%16s\t%d\t\t%d\t\t", m->getName().c_str(), numFaces, nUnmeshed);
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

  // skip short mesh edges
  //geomThresholdVertexEquivalence inst(m);

  // boundary layers are special: their generation (including vertices
  // and curve meshes) is global as it depends on a smooth normal
  // field generated from the surface mesh of the source surfaces
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
	  meshGFace mesher(true, CTX::instance()->mesh.multiplePasses);
	  mesher(temp[K]);

#if defined(HAVE_BFGS)
          if(CTX::instance()->mesh.optimizeLloyd){
            if (temp[K]->geomType()==GEntity::CompoundSurface ||
                temp[K]->geomType()==GEntity::Plane || temp[K]->geomType()==GEntity::RuledSurface) {
              if (temp[K]->meshAttributes.method != MESH_TRANSFINITE &&
                  !temp[K]->meshAttributes.extrude) {
                smoothing smm(CTX::instance()->mesh.optimizeLloyd,6);
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
          meshGFace mesher(true, CTX::instance()->mesh.multiplePasses);
          mesher(*it);

#if defined(HAVE_BFGS)
          if(CTX::instance()->mesh.optimizeLloyd){
            if ((*it)->geomType()==GEntity::CompoundSurface ||
                (*it)->geomType()==GEntity::Plane || (*it)->geomType()==GEntity::RuledSurface) {
              if ((*it)->meshAttributes.method != MESH_TRANSFINITE &&
                  !(*it)->meshAttributes.extrude) {
                smoothing smm(CTX::instance()->mesh.optimizeLloyd,6);
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
  // pragma OMP ICI ??
  for(unsigned int i = 0; i < connected.size(); i++){
    for(unsigned j=0;j<connected[i].size();j++){
      GRegion *gr = connected[i][j];
      if(CTX::instance()->mesh.recombine3DAll || gr->meshAttributes.recombine3D){
	std::list<GFace*> f = gr->faces();
	for (std::list<GFace*>::iterator it = f.begin();
	     it != f.end() ; ++it) quadsToTriangles (*it,1000000);
      }
    }
  }

  // pragma OMP ICI ??
  for(unsigned int i = 0; i < connected.size(); i++){
    MeshDelaunayVolume(connected[i]);

    //Additional code for hex mesh begin
    for(unsigned j=0;j<connected[i].size();j++){
      GRegion *gr = connected[i][j];
      //R-tree
      if(CTX::instance()->mesh.algo3d == ALGO_3D_RTREE){
	Filler f;
	f.treat_region(gr);
      }
      //Recombine3D into hex
      if(CTX::instance()->mesh.recombine3DAll || gr->meshAttributes.recombine3D){
	Recombinator rec;
	rec.execute();
	Supplementary sup;
	sup.execute();
	PostOp post;
	post.execute(0);
      }
    }
  }

  // Ensure that all volume Jacobians are positive
  m->setAllVolumesPositive();

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

  double t2 = Cpu();
  Msg::StatusBar(true, "Done optimizing 3D mesh (%g s)", t2 - t1);
}

void AdaptMesh(GModel *m)
{
  Msg::StatusBar(true, "Adapting 3D mesh...");
  double t1 = Cpu();

  for(int i = 0; i < 10; i++)
    std::for_each(m->firstRegion(), m->lastRegion(), adaptMeshGRegion());

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
      ElasticAnalogy(GModel::current(), CTX::instance()->mesh.hoThresholdMin, false);
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
