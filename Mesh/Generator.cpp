// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

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
#include "meshGRegionLocalMeshMod.h"
#include "meshRelocateVertex.h"
#include "meshRefine.h"
#include "discreteFace.h"
#include "BackgroundMesh.h"
#include "BoundaryLayers.h"
#include "ExtrudeParams.h"
#include "HighOrder.h"
#include "Field.h"
#include "Options.h"
#include "Generator.h"

#if defined(_OPENMP)
#include <omp.h>
#endif

#if defined(HAVE_DOMHEX)
#include "simple3D.h"
#include "yamakawa.h"
#include "pointInsertion.h"
#endif

#if defined(HAVE_OPTHOM)
#include "HighOrderMeshOptimizer.h"
#include "HighOrderMeshElasticAnalogy.h"
#endif

#if defined(HAVE_POST)
#include "PView.h"
#include "PViewData.h"
#endif

class EmbeddedCompatibilityTest {
public:
  void operator()(GRegion *gr)
  {
    std::vector<GEdge *> const &e = gr->embeddedEdges();
    std::vector<GFace *> const &f = gr->embeddedFaces();
    if(e.empty() && f.empty()) return;
    std::map<MEdge, GEdge *, Less_Edge> edges;
    std::map<MFace, GFace *, Less_Face> faces;
    std::vector<GEdge *>::const_iterator it = e.begin();
    std::vector<GFace *>::const_iterator itf = f.begin();
    for(; it != e.end(); ++it) {
      for(std::size_t i = 0; i < (*it)->lines.size(); ++i) {
        if(distance((*it)->lines[i]->getVertex(0),
                    (*it)->lines[i]->getVertex(1)) > 1.e-12)
          edges.insert(std::make_pair(
            MEdge((*it)->lines[i]->getVertex(0), (*it)->lines[i]->getVertex(1)),
            *it));
      }
    }
    for(; itf != f.end(); ++itf) {
      for(std::size_t i = 0; i < (*itf)->triangles.size(); ++i) {
        faces.insert(std::make_pair(MFace((*itf)->triangles[i]->getVertex(0),
                                          (*itf)->triangles[i]->getVertex(1),
                                          (*itf)->triangles[i]->getVertex(2)),
                                    *itf));
      }
    }
    Msg::Info("Searching for %d embedded mesh edges and %d embedded mesh faces "
              "in region %d",
              edges.size(), faces.size(), gr->tag());
    for(std::size_t k = 0; k < gr->getNumMeshElements(); k++) {
      for(int j = 0; j < gr->getMeshElement(k)->getNumEdges(); j++) {
        edges.erase(gr->getMeshElement(k)->getEdge(j));
      }
      for(int j = 0; j < gr->getMeshElement(k)->getNumFaces(); j++) {
        faces.erase(gr->getMeshElement(k)->getFace(j));
      }
    }
    if(edges.empty() && faces.empty()) {
      Msg::Info("All embedded edges and faces are present in the final mesh");
    }
    if(edges.size()) {
      char name[256];
      sprintf(name, "missingEdgesOnRegion%d.pos", gr->tag());
      Msg::Error("Region %d : %d mesh edges that should be embedded are "
                 "missing in the final mesh",
                 gr->tag(), (int)edges.size());
      Msg::Error("Saving the missing edges in file %s", name);
      FILE *f = fopen(name, "w");
      fprintf(f, "View \" \" {\n");
      for(std::map<MEdge, GEdge *, Less_Edge>::iterator it = edges.begin();
          it != edges.end(); ++it) {
        MVertex *v1 = it->first.getVertex(0);
        MVertex *v2 = it->first.getVertex(1);
        fprintf(f, "SL(%g,%g,%g,%g,%g,%g){%d,%d};\n", v1->x(), v1->y(), v1->z(),
                v2->x(), v2->y(), v2->z(), it->second->tag(),
                it->second->tag());
      }
      fprintf(f, "};\n");
      fclose(f);
    }
    if(faces.size()) {
      char name[256];
      sprintf(name, "missingFacesOnRegion%d.pos", gr->tag());
      Msg::Error("Volume %d : %d mesh faces that should be embedded are "
                 "missing in the final mesh",
                 gr->tag(), (int)faces.size());
      Msg::Error("Saving the missing faces in file %s", name);
      FILE *f = fopen(name, "w");
      fprintf(f, "View \" \" {\n");
      for(std::map<MFace, GFace *, Less_Face>::iterator it = faces.begin();
          it != faces.end(); ++it) {
        MVertex *v1 = it->first.getVertex(0);
        MVertex *v2 = it->first.getVertex(1);
        MVertex *v3 = it->first.getVertex(2);
        fprintf(f, "ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%d,%d,%d};\n", v1->x(),
                v1->y(), v1->z(), v2->x(), v2->y(), v2->z(), v3->x(), v3->y(),
                v3->z(), it->second->tag(), it->second->tag(),
                it->second->tag());
      }
      fprintf(f, "};\n");
      fclose(f);
    }
  }
};

template <class T>
static void
GetQualityMeasure(std::vector<T *> &ele, double &gamma, double &gammaMin,
                  double &gammaMax, double &minSICN, double &minSICNMin,
                  double &minSICNMax, double &minSIGE, double &minSIGEMin,
                  double &minSIGEMax, double quality[3][100])
{
  for(std::size_t i = 0; i < ele.size(); i++) {
    double g = ele[i]->gammaShapeMeasure();
    gamma += g;
    gammaMin = std::min(gammaMin, g);
    gammaMax = std::max(gammaMax, g);
    double s = ele[i]->minSICNShapeMeasure();
    minSICN += s;
    minSICNMin = std::min(minSICNMin, s);
    minSICNMax = std::max(minSICNMax, s);
    double e = ele[i]->minSIGEShapeMeasure();
    minSIGE += e;
    minSIGEMin = std::min(minSIGEMin, e);
    minSIGEMax = std::max(minSIGEMax, e);
    for(int j = 0; j < 100; j++) {
      if(s > (2 * j - 100) / 100. && s <= (2 * j - 98) / 100.) quality[0][j]++;
      if(g > j / 100. && g <= (j + 1) / 100.) quality[1][j]++;
      if(e > (2 * j - 100) / 100. && e <= (2 * j - 98) / 100.) quality[2][j]++;
    }
  }
}

void GetStatistics(double stat[50], double quality[3][100],
                   bool visibleOnly)
{
  for(int i = 0; i < 50; i++) stat[i] = 0.;

  GModel *m = GModel::current();

  if(!m) return;

  stat[0] = m->getNumVertices();
  stat[1] = m->getNumEdges();
  stat[2] = m->getNumFaces();
  stat[3] = m->getNumRegions();

  std::map<int, std::vector<GEntity *> > physicals[4];
  m->getPhysicalGroups(physicals);
  stat[45] = physicals[0].size() + physicals[1].size() + physicals[2].size() +
             physicals[3].size();

  for(GModel::viter it = m->firstVertex(); it != m->lastVertex(); ++it) {
    if(visibleOnly && !(*it)->getVisibility()) continue;
    stat[4] += (*it)->mesh_vertices.size();
    stat[5] += (*it)->points.size();
  }

  for(GModel::eiter it = m->firstEdge(); it != m->lastEdge(); ++it) {
    if(visibleOnly && !(*it)->getVisibility()) continue;
    stat[4] += (*it)->mesh_vertices.size();
    stat[6] += (*it)->lines.size();
  }

  for(GModel::fiter it = m->firstFace(); it != m->lastFace(); ++it) {
    if(visibleOnly && !(*it)->getVisibility()) continue;
    stat[4] += (*it)->mesh_vertices.size();
    stat[7] += (*it)->triangles.size();
    stat[8] += (*it)->quadrangles.size();
  }

  for(GModel::riter it = m->firstRegion(); it != m->lastRegion(); ++it) {
    if(visibleOnly && !(*it)->getVisibility()) continue;
    stat[4] += (*it)->mesh_vertices.size();
    stat[9] += (*it)->tetrahedra.size();
    stat[10] += (*it)->hexahedra.size();
    stat[11] += (*it)->prisms.size();
    stat[12] += (*it)->pyramids.size();
    stat[13] += (*it)->trihedra.size();
  }

  stat[14] = CTX::instance()->meshTimer[0];
  stat[15] = CTX::instance()->meshTimer[1];
  stat[16] = CTX::instance()->meshTimer[2];

  if(quality) {
    for(int i = 0; i < 3; i++)
      for(int j = 0; j < 100; j++) quality[i][j] = 0.;
    double minSICN = 0., minSICNMin = 1., minSICNMax = -1.;
    double minSIGE = 0., minSIGEMin = 1., minSIGEMax = -1.;
    double gamma = 0., gammaMin = 1., gammaMax = 0.;

    double N = stat[9] + stat[10] + stat[11] + stat[12] + stat[13];
    if(N) { // if we have 3D elements
      for(GModel::riter it = m->firstRegion(); it != m->lastRegion(); ++it) {
        if(visibleOnly && !(*it)->getVisibility()) continue;
        GetQualityMeasure((*it)->tetrahedra, gamma, gammaMin, gammaMax, minSICN,
                          minSICNMin, minSICNMax, minSIGE, minSIGEMin,
                          minSIGEMax, quality);
        GetQualityMeasure((*it)->hexahedra, gamma, gammaMin, gammaMax, minSICN,
                          minSICNMin, minSICNMax, minSIGE, minSIGEMin,
                          minSIGEMax, quality);
        GetQualityMeasure((*it)->prisms, gamma, gammaMin, gammaMax, minSICN,
                          minSICNMin, minSICNMax, minSIGE, minSIGEMin,
                          minSIGEMax, quality);
        GetQualityMeasure((*it)->pyramids, gamma, gammaMin, gammaMax, minSICN,
                          minSICNMin, minSICNMax, minSIGE, minSIGEMin,
                          minSIGEMax, quality);
      }
    }
    else { // 2D elements
      N = stat[7] + stat[8];
      for(GModel::fiter it = m->firstFace(); it != m->lastFace(); ++it) {
        if(visibleOnly && !(*it)->getVisibility()) continue;
        GetQualityMeasure((*it)->quadrangles, gamma, gammaMin, gammaMax,
                          minSICN, minSICNMin, minSICNMax, minSIGE, minSIGEMin,
                          minSIGEMax, quality);
        GetQualityMeasure((*it)->triangles, gamma, gammaMin, gammaMax, minSICN,
                          minSICNMin, minSICNMax, minSIGE, minSIGEMin,
                          minSIGEMax, quality);
      }
    }
    if(N) {
      stat[18] = minSICN / N;
      stat[19] = minSICNMin;
      stat[20] = minSICNMax;
      stat[21] = gamma / N;
      stat[22] = gammaMin;
      stat[23] = gammaMax;
      stat[24] = minSIGE / N;
      stat[25] = minSIGEMin;
      stat[26] = minSIGEMax;
    }
  }

#if defined(HAVE_POST)
  stat[27] = PView::list.size();
  for(std::size_t i = 0; i < PView::list.size(); i++) {
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

  // try to detect obvious mistakes in characteristic lenghts (one of the most
  // common cause for erroneous bug reports on the mailing list)
  double sumAllLc = 0.;
  for(GModel::viter it = m->firstVertex(); it != m->lastVertex(); ++it)
    sumAllLc +=
      (*it)->prescribedMeshSizeAtVertex() * CTX::instance()->mesh.lcFactor;
  sumAllLc /= (double)m->getNumVertices();
  if(!sumAllLc || pow(CTX::instance()->lc / sumAllLc, dim) > 1.e10)
    return !Msg::GetAnswer(
      "Your choice of mesh element sizes will likely produce a very\n"
      "large mesh. Do you really want to continue?\n\n"
      "(To disable this warning in the future, select `Enable expert mode'\n"
      "in the option dialog.)",
      1, "Cancel", "Continue");
  return false;
}

static void Mesh0D(GModel *m)
{
  m->getFields()->initialize();

  for(GModel::viter it = m->firstVertex(); it != m->lastVertex(); ++it) {
    GVertex *gv = *it;
    if(gv->mesh_vertices.empty())
      gv->mesh_vertices.push_back(new MVertex(gv->x(), gv->y(), gv->z(), gv));
    if(gv->points.empty())
      gv->points.push_back(new MPoint(gv->mesh_vertices.back()));
  }
  for(GModel::viter it = m->firstVertex(); it != m->lastVertex(); ++it) {
    GVertex *gv = *it;
    if(gv->getMeshMaster() != gv) {
      if(gv->correspondingVertices.empty()) {
        GVertex *master = dynamic_cast<GVertex *>(gv->getMeshMaster());
        if(master)
          gv->correspondingVertices[gv->mesh_vertices[0]] =
            master->mesh_vertices[0];
      }
    }
  }
}

static void Mesh1D(GModel *m)
{
  m->getFields()->initialize();

  if(TooManyElements(m, 1)) return;
  Msg::StatusBar(true, "Meshing 1D...");
  double t1 = Cpu();

  int prevNumThreads = Msg::GetMaxThreads();
  if(CTX::instance()->mesh.maxNumThreads1D > 0 &&
     CTX::instance()->mesh.maxNumThreads1D <= Msg::GetMaxThreads())
    Msg::SetNumThreads(CTX::instance()->mesh.maxNumThreads1D);

  // boundary layers are not yet thread-safe
  if(m->getFields()->getNumBoundaryLayerFields())
    Msg::SetNumThreads(1);

  for(GModel::eiter it = m->firstEdge(); it != m->lastEdge(); ++it) {
    // Extruded meshes are not yet fully thread-safe (not sure why!)
    if((*it)->meshAttributes.extrude &&
       (*it)->meshAttributes.extrude->mesh.ExtrudeMesh)
      Msg::SetNumThreads(1);
  }

  std::vector<GEdge *> temp;
  for(GModel::eiter it = m->firstEdge(); it != m->lastEdge(); ++it) {
    (*it)->meshStatistics.status = GEdge::PENDING;
    temp.push_back(*it);
  }

  Msg::ResetProgressMeter();

  int nIter = 0, nTot = m->getNumEdges();
  while(1) {
    int nPending = 0;
    const size_t sss = temp.size();
#if defined(_OPENMP)
#pragma omp parallel for schedule(dynamic)
#endif
    for(size_t K = 0; K < sss; K++) {
      GEdge *ed = temp[K];
      if(ed->meshStatistics.status == GEdge::PENDING) {
        ed->mesh(true);
#if defined(_OPENMP)
#pragma omp critical
#endif
        {
          nPending++;
        }
      }
      if(!nIter) Msg::ProgressMeter(nPending, nTot, false, "Meshing 1D...");
    }

    if(!nPending) break;
    if(nIter++ > 10) break;
  }

  Msg::SetNumThreads(prevNumThreads);

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

  if(!statreport) {
    Msg::Error("Could not open file '%s'",
               CTX::instance()->meshStatReportFileName.c_str());
    return;
  }

  double worst = 1, best = 0, avg = 0;
  double e_long = 0, e_short = 1.e22, e_avg = 0;
  int nTotT = 0, nTotE = 0, nTotGoodLength = 0, nTotGoodQuality = 0;
  int nUnmeshed = 0, numFaces = 0;

  if(CTX::instance()->createAppendMeshStatReport == 1) {
    fprintf(statreport, "2D stats\tname\t\t#faces\t\t#fail\t\t"
                        "#t\t\tQavg\t\tQbest\t\tQworst\t\t#Q>90\t\t#Q>90/#t\t"
                        "#e\t\ttau\t\t#Egood\t\t#Egood/#e\tCPU\n");
    if(m->empty()) {
      fclose(statreport);
      return;
    }
  }

  for(GModel::fiter it = m->firstFace(); it != m->lastFace(); ++it) {
    if((*it)->geomType() != GEntity::DiscreteSurface) {
      worst = std::min((*it)->meshStatistics.worst_element_shape, worst);
      best = std::max((*it)->meshStatistics.best_element_shape, best);
      avg += (*it)->meshStatistics.average_element_shape *
             (*it)->meshStatistics.nbTriangle;
      e_avg += (*it)->meshStatistics.efficiency_index;
      e_long = std::max((*it)->meshStatistics.longest_edge_length, e_long);
      e_short = std::min((*it)->meshStatistics.smallest_edge_length, e_short);
      if((*it)->meshStatistics.status == GFace::FAILED ||
         (*it)->meshStatistics.status == GFace::PENDING)
        nUnmeshed++;
      nTotT += (*it)->meshStatistics.nbTriangle;
      nTotE += (*it)->meshStatistics.nbEdge;
      nTotGoodLength += (*it)->meshStatistics.nbGoodLength;
      nTotGoodQuality += (*it)->meshStatistics.nbGoodQuality;
      numFaces++;
    }
  }

  Msg::Info("Efficiency index for surface mesh tau=%g ",
            100 * exp(e_avg / (double)nTotE));

  fprintf(statreport, "\t%16s\t%d\t\t%d\t\t", m->getName().c_str(), numFaces,
          nUnmeshed);
  fprintf(statreport, "%d\t\t%8.7f\t%8.7f\t%8.7f\t%d\t\t%8.7f\t", nTotT,
          avg / (double)nTotT, best, worst, nTotGoodQuality,
          (double)nTotGoodQuality / nTotT);
  fprintf(statreport, "%d\t\t%8.7f\t%d\t\t%8.7f\t%8.1f\n", nTotE,
          exp(e_avg / (double)nTotE), nTotGoodLength,
          (double)nTotGoodLength / nTotE, CTX::instance()->meshTimer[1]);
  fclose(statreport);
}

static void Mesh2D(GModel *m)
{
  m->getFields()->initialize();

  if(TooManyElements(m, 2)) return;
  Msg::StatusBar(true, "Meshing 2D...");
  double t1 = Cpu();

  int prevNumThreads = Msg::GetMaxThreads();
  if(CTX::instance()->mesh.maxNumThreads2D > 0 &&
     CTX::instance()->mesh.maxNumThreads2D <= Msg::GetMaxThreads())
    Msg::SetNumThreads(CTX::instance()->mesh.maxNumThreads2D);

  // boundary layers are not yet thread-safe
  if(m->getFields()->getNumBoundaryLayerFields())
    Msg::SetNumThreads(1);

  for(GModel::fiter it = m->firstFace(); it != m->lastFace(); ++it) {
    // STL remeshing is not yet thread-safe
    //    if((*it)->geomType() == GEntity::DiscreteSurface){
    //      if(static_cast<discreteFace *>(*it)->haveParametrization())
    //        Msg::SetNumThreads(1);
    //    }
    // Frontal-Delaunay for quads and co are not yet thread-safe
    if((*it)->getMeshingAlgo() == ALGO_2D_FRONTAL_QUAD ||
       (*it)->getMeshingAlgo() == ALGO_2D_PACK_PRLGRMS ||
       (*it)->getMeshingAlgo() == ALGO_2D_PACK_PRLGRMS_CSTR)
      Msg::SetNumThreads(1);
    // Periodic meshing is not yet thread-safe
    if((*it)->getMeshMaster() != *it)
      Msg::SetNumThreads(1);
    // Extruded meshes are not yet fully thread-safe (not sure why!)
    if((*it)->meshAttributes.extrude &&
       (*it)->meshAttributes.extrude->mesh.ExtrudeMesh)
      Msg::SetNumThreads(1);
  }

  for(GModel::fiter it = m->firstFace(); it != m->lastFace(); ++it)
    (*it)->meshStatistics.status = GFace::PENDING;

  // boundary layers are special: their generation (including vertices and curve
  // meshes) is global as it depends on a smooth normal field generated from the
  // surface mesh of the source surfaces
  if(!Mesh2DWithBoundaryLayers(m)) {
    std::set<GFace *, GEntityLessThan> f;
    for(GModel::fiter it = m->firstFace(); it != m->lastFace(); ++it)
      f.insert(*it);

    Msg::ResetProgressMeter();

    int nIter = 0, nTot = m->getNumFaces();
    while(1) {
      int nPending = 0;
      std::vector<GFace *> temp;
      temp.insert(temp.begin(), f.begin(), f.end());
#if defined(_OPENMP)
#pragma omp parallel for schedule(dynamic)
#endif
      for(size_t K = 0; K < temp.size(); K++) {
        if(temp[K]->meshStatistics.status == GFace::PENDING) {
          backgroundMesh::current()->unset();
          temp[K]->mesh(true);
#if defined(_OPENMP)
#pragma omp critical
#endif
          {
            nPending++;
          }
        }
        if(!nIter) Msg::ProgressMeter(nPending, nTot, false, "Meshing 2D...");
      }
      if(!nPending) break;
      // iter == 2 is for meshing re-parametrized surfaces; after that, we
      // serialize (self-intersections of 1D meshes are not thread safe)!
      if(nIter > 2) Msg::SetNumThreads(1);
      if(nIter++ > 10) break;
    }
  }

  Msg::SetNumThreads(prevNumThreads);

  double t2 = Cpu();
  CTX::instance()->meshTimer[1] = t2 - t1;
  Msg::StatusBar(true, "Done meshing 2D (%g s)", CTX::instance()->meshTimer[1]);

  PrintMesh2dStatistics(m);
}

static void
FindConnectedRegions(const std::vector<GRegion *> &del,
                     std::vector<std::vector<GRegion *> > &connected)
{
  std::vector<GRegion *> delaunay = del;
  // test: connected.resize(1); connected[0] = delaunay; return;

  const std::size_t nbVolumes = delaunay.size();
  if(!nbVolumes) return;
  while(delaunay.size()) {
    std::set<GRegion *> oneDomain;
    std::stack<GRegion *> _stack;
    GRegion *r = delaunay[0];
    _stack.push(r);
    while(!_stack.empty()) {
      r = _stack.top();
      _stack.pop();
      oneDomain.insert(r);
      std::vector<GFace *> faces = r->faces();
      for(std::vector<GFace *>::iterator it = faces.begin(); it != faces.end();
          ++it) {
        GFace *gf = *it;
        GRegion *other =
          (gf->getRegion(0) == r) ? gf->getRegion(1) : gf->getRegion(0);
        if(other != 0 && oneDomain.find(other) == oneDomain.end())
          _stack.push(other);
      }
    }
    std::vector<GRegion *> temp1, temp2;
    for(std::size_t i = 0; i < delaunay.size(); i++) {
      r = delaunay[i];
      if(oneDomain.find(r) == oneDomain.end())
        temp1.push_back(r);
      else
        temp2.push_back(r);
    }
    connected.push_back(temp2);
    delaunay = temp1;
  }
  Msg::Info("3D Meshing %d volumes with %d connected components",
            nbVolumes, connected.size());
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

void buildUniqueFaces(GRegion *gr, std::set<MFace, Less_Face> &bnd)
{
  for(std::size_t i = 0; i < gr->getNumMeshElements(); i++) {
    MElement *e = gr->getMeshElement(i);
    for(int j = 0; j < e->getNumFaces(); j++) {
      MFace f = e->getFace(j);
      std::set<MFace, Less_Face>::iterator it = bnd.find(f);
      if(it == bnd.end())
        bnd.insert(f);
      else
        bnd.erase(it);
    }
  }
}

bool MakeMeshConformal(GModel *gm, int howto)
{
  fs_cont search;
  buildFaceSearchStructure(gm, search);
  std::set<MFace, Less_Face> bnd;
  for(GModel::riter rit = gm->firstRegion(); rit != gm->lastRegion(); ++rit) {
    GRegion *gr = *rit;
    buildUniqueFaces(gr, bnd);
  }
  // bnd2 contains non conforming faces

  std::set<MFace, Less_Face> bnd2;
  for(std::set<MFace, Less_Face>::iterator itf = bnd.begin(); itf != bnd.end();
      ++itf) {
    GFace *gfound = findInFaceSearchStructure(*itf, search);
    if(!gfound) {
      bnd2.insert(*itf);
    }
  }
  bnd.clear();

  Msg::Info("%d hanging faces", bnd2.size());

  std::set<MFace, Less_Face> ncf;
  for(std::set<MFace, Less_Face>::iterator itf = bnd2.begin();
      itf != bnd2.end(); ++itf) {
    const MFace &f = *itf;
    if(f.getNumVertices() == 4) { // quad face
      std::set<MFace, Less_Face>::iterator it1 =
        bnd2.find(MFace(f.getVertex(0), f.getVertex(1), f.getVertex(2)));
      std::set<MFace, Less_Face>::iterator it2 =
        bnd2.find(MFace(f.getVertex(2), f.getVertex(3), f.getVertex(0)));
      if(it1 != bnd2.end() && it2 != bnd2.end()) {
        ncf.insert(MFace(f.getVertex(1), f.getVertex(2), f.getVertex(3),
                         f.getVertex(0)));
      }
      else {
        it1 = bnd2.find(MFace(f.getVertex(0), f.getVertex(1), f.getVertex(3)));
        it2 = bnd2.find(MFace(f.getVertex(3), f.getVertex(1), f.getVertex(2)));
        if(it1 != bnd2.end() && it2 != bnd2.end()) {
          ncf.insert(MFace(f.getVertex(0), f.getVertex(1), f.getVertex(2),
                           f.getVertex(3)));
        }
        else {
          Msg::Error("MakeMeshConformal: wrong mesh topology");
          return false;
        }
      }
    }
  }
  bnd2.clear();

  for(GModel::riter rit = gm->firstRegion(); rit != gm->lastRegion(); ++rit) {
    GRegion *gr = *rit;
    std::vector<MHexahedron *> remainingHexes;
    for(std::size_t i = 0; i < gr->hexahedra.size(); i++) {
      MHexahedron *e = gr->hexahedra[i];
      std::vector<MFace> faces;
      for(int j = 0; j < e->getNumFaces(); j++) {
        MFace f = e->getFace(j);
        std::set<MFace, Less_Face>::iterator it = ncf.find(f);
        if(it == ncf.end()) {
          faces.push_back(f);
        }
        else {
          faces.push_back(
            MFace(it->getVertex(0), it->getVertex(1), it->getVertex(3)));
          faces.push_back(
            MFace(it->getVertex(1), it->getVertex(2), it->getVertex(3)));
        }
      }
      // Hex is only surrounded by compatible elements
      if((int)faces.size() == e->getNumFaces()) {
        remainingHexes.push_back(e);
      }
      else {
        SPoint3 pp = e->barycenter();
        MVertex *newv = new MVertex(pp.x(), pp.y(), pp.z(), gr);
        gr->mesh_vertices.push_back(newv);
        for(std::size_t j = 0; j < faces.size(); j++) {
          MFace &f = faces[j];
          if(f.getNumVertices() == 4) {
            gr->pyramids.push_back(new MPyramid(f.getVertex(0), f.getVertex(1),
                                                f.getVertex(2), f.getVertex(3),
                                                newv));
          }
          else {
            gr->tetrahedra.push_back(new MTetrahedron(
              f.getVertex(0), f.getVertex(1), f.getVertex(2), newv));
          }
        }
      }
    }
    gr->hexahedra = remainingHexes;
    remainingHexes.clear();
    std::vector<MPrism *> remainingPrisms;
    for(std::size_t i = 0; i < gr->prisms.size(); i++) {
      MPrism *e = gr->prisms[i];
      std::vector<MFace> faces;
      for(int j = 0; j < e->getNumFaces(); j++) {
        MFace f = e->getFace(j);
        std::set<MFace, Less_Face>::iterator it = ncf.find(f);
        if(it == ncf.end()) {
          faces.push_back(f);
        }
        else {
          faces.push_back(
            MFace(it->getVertex(0), it->getVertex(1), it->getVertex(3)));
          faces.push_back(
            MFace(it->getVertex(1), it->getVertex(2), it->getVertex(3)));
        }
      }
      // Hex is only surrounded by compatible elements
      if((int)faces.size() == e->getNumFaces()) {
        remainingPrisms.push_back(e);
      }
      else {
        SPoint3 pp = e->barycenter();
        MVertex *newv = new MVertex(pp.x(), pp.y(), pp.z(), gr);
        gr->mesh_vertices.push_back(newv);
        for(std::size_t j = 0; j < faces.size(); j++) {
          MFace &f = faces[j];
          if(f.getNumVertices() == 4) {
            gr->pyramids.push_back(new MPyramid(f.getVertex(0), f.getVertex(1),
                                                f.getVertex(2), f.getVertex(3),
                                                newv));
          }
          else {
            gr->tetrahedra.push_back(new MTetrahedron(
              f.getVertex(0), f.getVertex(1), f.getVertex(2), newv));
          }
        }
      }
    }
    gr->prisms = remainingPrisms;
  }

  return true;
}

#if defined(HAVE_DOMHEX)
static void TestConformity(GModel *gm)
{
  fs_cont search;
  buildFaceSearchStructure(gm, search);
  int count = 0;
  for(GModel::riter rit = gm->firstRegion(); rit != gm->lastRegion(); ++rit) {
    GRegion *gr = *rit;
    std::set<MFace, Less_Face> bnd;
    double vol = 0.0;
    for(std::size_t i = 0; i < gr->getNumMeshElements(); i++) {
      MElement *e = gr->getMeshElement(i);
      vol += fabs(e->getVolume());
      for(int j = 0; j < e->getNumFaces(); j++) {
        MFace f = e->getFace(j);
        std::set<MFace, Less_Face>::iterator it = bnd.find(f);
        if(it == bnd.end())
          bnd.insert(f);
        else
          bnd.erase(it);
      }
    }
    printf("vol(%d) = %12.5E\n", gr->tag(), vol);

    for(std::set<MFace, Less_Face>::iterator itf = bnd.begin();
        itf != bnd.end(); ++itf) {
      GFace *gfound = findInFaceSearchStructure(*itf, search);
      if(!gfound) {
        count++;
      }
    }
  }
  if(!count)
    Msg::Info("Mesh Conformity: OK");
  else
    Msg::Error("Mesh is not conforming (%d hanging faces)!", count);
}
#endif

static void Mesh3D(GModel *m)
{
  m->getFields()->initialize();

  if(TooManyElements(m, 3)) return;
  Msg::StatusBar(true, "Meshing 3D...");
  double t1 = Cpu();

  int prevNumThreads = Msg::GetMaxThreads();
  if(CTX::instance()->mesh.maxNumThreads3D > 0 &&
     CTX::instance()->mesh.maxNumThreads3D <= Msg::GetMaxThreads())
    Msg::SetNumThreads(CTX::instance()->mesh.maxNumThreads3D);

  for(GModel::riter it = m->firstRegion(); it != m->lastRegion(); ++it) {
    // Extruded meshes are not yet fully thread-safe (not sure why!)
    if((*it)->meshAttributes.extrude &&
       (*it)->meshAttributes.extrude->mesh.ExtrudeMesh)
      Msg::SetNumThreads(1);
  }

  if(m->getNumRegions()) Msg::ProgressMeter(0, 100, false, "Meshing 3D...");

  // mesh the extruded volumes first
  std::for_each(m->firstRegion(), m->lastRegion(), meshGRegionExtruded());

  // then subdivide if necessary (unfortunately the subdivision is a
  // global operation, which can require changing the surface mesh!)
  SubdivideExtrudedMesh(m);

  // then mesh all the non-delaunay regions (front3D with netgen)
  std::vector<GRegion *> delaunay;
  std::for_each(m->firstRegion(), m->lastRegion(), meshGRegion(delaunay));

  // and finally mesh the delaunay regions (again, this is global; but
  // we mesh each connected part separately for performance and mesh
  // quality reasons)
  std::vector<std::vector<GRegion *> > connected;
  FindConnectedRegions(delaunay, connected);

  // remove quads elements for volumes that are recombined
  for(std::size_t i = 0; i < connected.size(); i++) {
    for(std::size_t j = 0; j < connected[i].size(); j++) {
      GRegion *gr = connected[i][j];
      if(CTX::instance()->mesh.recombine3DAll ||
         gr->meshAttributes.recombine3D) {
        std::vector<GFace *> f = gr->faces();
        for(std::vector<GFace *>::iterator it = f.begin(); it != f.end(); ++it)
          quadsToTriangles(*it, 1000000);
      }
    }
  }

#if defined(HAVE_DOMHEX)
  double time_recombination = 0., vol_element_recombination = 0.;
  double vol_hexa_recombination = 0.;
  int nb_elements_recombination = 0, nb_hexa_recombination = 0;
#endif

  for(std::size_t i = 0; i < connected.size(); i++) {
    MeshDelaunayVolume(connected[i]);

#if defined(HAVE_DOMHEX)
    // additional code for experimental hex mesh - will eventually be replaced
    // by new HXT-based code
    for(std::size_t j = 0; j < connected[i].size(); j++) {
      GRegion *gr = connected[i][j];
      bool treat_region_ok = false;
      if(CTX::instance()->mesh.algo3d == ALGO_3D_RTREE) {
        if(old_algo_hexa()) {
          Filler f;
          f.treat_region(gr);
          treat_region_ok = true;
        }
        else {
          Filler3D f;
          treat_region_ok = f.treat_region(gr);
        }
      }
      if(treat_region_ok && (CTX::instance()->mesh.recombine3DAll ||
                             gr->meshAttributes.recombine3D)) {
        if(CTX::instance()->mesh.optimize) {
          optimizeMeshGRegion opt;
          opt(gr);
        }
        double a = Cpu();
        // CTX::instance()->mesh.recombine3DLevel = 2;
        if(CTX::instance()->mesh.recombine3DLevel >= 0) {
          Recombinator rec;
          rec.execute(gr);
        }
        if(CTX::instance()->mesh.recombine3DLevel >= 1) {
          Supplementary sup;
          sup.execute(gr);
        }
        PostOp post;
        post.execute(gr, CTX::instance()->mesh.recombine3DLevel,
                     CTX::instance()->mesh.recombine3DConformity);
        // CTX::instance()->mesh.recombine3DConformity);
        // 0: no pyramid, 1: single-step, 2: two-steps (conforming),
        // true: fill non-conformities with trihedra
        RelocateVertices(gr, CTX::instance()->mesh.nbSmoothing);
        // while(LaplaceSmoothing (gr)){
        // }
        nb_elements_recombination += post.get_nb_elements();
        nb_hexa_recombination += post.get_nb_hexahedra();
        vol_element_recombination += post.get_vol_elements();
        vol_hexa_recombination += post.get_vol_hexahedra();
        time_recombination += (Cpu() - a);
      }
    }
#endif
  }

#if defined(HAVE_DOMHEX)
  if(CTX::instance()->mesh.recombine3DAll) {
    Msg::Info("Recombination timing:");
    Msg::Info(" - Cumulative time recombination: %g s", time_recombination);
    Msg::Info("Recombination cumulative statistics:");
    Msg::Info(" - Percentage of hexahedra (#)  : %g",
              nb_hexa_recombination * 100. / nb_elements_recombination);
    Msg::Info(" - Percentage of hexahedra (Vol): %g",
              vol_hexa_recombination * 100. / vol_element_recombination);
    // MakeMeshConformal(m, 1);
    TestConformity(m);
  }
#endif

  // ensure that all volume Jacobians are positive
  m->setAllVolumesPositive();

  if(Msg::GetVerbosity() > 98)
    std::for_each(m->firstRegion(), m->lastRegion(), EmbeddedCompatibilityTest());

  std::stringstream debugInfo;
  debugInfo << "No elements in volume ";
  bool emptyRegionFound = false;
  for(GModel::riter it = m->firstRegion(); it != m->lastRegion(); ++it) {
    GRegion *gr = *it;
    if(CTX::instance()->mesh.meshOnlyVisible && !gr->getVisibility())
      continue;
    if(gr->getNumMeshElements() == 0) {
      debugInfo << gr->tag() << " ";
      emptyRegionFound = true;
    }
  }
  if(emptyRegionFound) {
    debugInfo << std::endl;
    Msg::Error(debugInfo.str().c_str());
  }

  Msg::SetNumThreads(prevNumThreads);

  double t2 = Cpu();
  CTX::instance()->meshTimer[2] = t2 - t1;

  if(m->getNumRegions()) Msg::ProgressMeter(100, 100, false, "Meshing 3D...");

  Msg::StatusBar(true, "Done meshing 3D (%g s)", CTX::instance()->meshTimer[2]);
}

void OptimizeMesh(GModel *m, bool force)
{
  Msg::StatusBar(true, "Optimizing 3D mesh...");
  double t1 = Cpu();

  for(GModel::riter it = m->firstRegion(); it != m->lastRegion(); it++){
    optimizeMeshGRegion opt;
    opt(*it, force);
  }

  // Ensure that all volume Jacobians are positive
  m->setAllVolumesPositive();

  if(Msg::GetVerbosity() > 98)
    std::for_each(m->firstRegion(), m->lastRegion(), EmbeddedCompatibilityTest());

  double t2 = Cpu();
  Msg::StatusBar(true, "Done optimizing 3D mesh (%g s)", t2 - t1);
}

void OptimizeMeshNetgen(GModel *m, bool force)
{
  Msg::StatusBar(true, "Optimizing 3D mesh with Netgen...");
  double t1 = Cpu();

  for(GModel::riter it = m->firstRegion(); it != m->lastRegion(); it++){
    optimizeMeshGRegionNetgen opt;
    opt(*it, force);
  }

  // ensure that all volume Jacobians are positive
  m->setAllVolumesPositive();

  if(Msg::GetVerbosity() > 98)
    std::for_each(m->firstRegion(), m->lastRegion(), EmbeddedCompatibilityTest());

  double t2 = Cpu();
  Msg::StatusBar(true, "Done optimizing 3D mesh with Netgen (%g s)", t2 - t1);
}

void OptimizeHighOrderMesh(GModel *m)
{
#if defined(HAVE_OPTHOM)
  OptHomParameters p;
  p.nbLayers = CTX::instance()->mesh.hoNLayers;
  p.BARRIER_MIN = CTX::instance()->mesh.hoThresholdMin;
  p.BARRIER_MAX = CTX::instance()->mesh.hoThresholdMax;
  p.itMax = CTX::instance()->mesh.hoIterMax;
  p.optPassMax = CTX::instance()->mesh.hoPassMax;
  p.dim = GModel::current()->getDim();
  p.optPrimSurfMesh = CTX::instance()->mesh.hoPrimSurfMesh;
  p.optCAD = CTX::instance()->mesh.hoDistCAD;
  HighOrderMeshOptimizer(GModel::current(), p);
#else
  Msg::Error("High-order mesh optimization requires the OPTHOM module");
#endif
}

void OptimizeHighOrderMeshElastic(GModel *m)
{
#if defined(HAVE_OPTHOM)
  HighOrderMeshElasticAnalogy(m, false);
#else
  Msg::Error("High-order mesh optimization requires the OPTHOM module");
#endif
}

void SmoothMesh(GModel *m)
{
  Msg::StatusBar(true, "Smoothing 2D mesh...");
  double t1 = Cpu();

  for(GModel::fiter it = m->firstFace(); it != m->lastFace(); ++it) {
    GFace *gf = *it;
    laplaceSmoothing(gf);
  }

  double t2 = Cpu();
  Msg::StatusBar(true, "Done smoothing 2D mesh (%g s)", t2 - t1);
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

  for(GModel::fiter it = m->firstFace(); it != m->lastFace(); ++it) {
    GFace *gf = *it;
    bool blossom = (CTX::instance()->mesh.algoRecombine == 1 ||
                    CTX::instance()->mesh.algoRecombine == 3);
    int topo = CTX::instance()->mesh.recombineOptimizeTopology;
    recombineIntoQuads(gf, blossom, topo, true, .01);
  }

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

  m->clearLastMeshEntityError();
  m->clearLastMeshVertexError();

  int old = m->getMeshStatus(false);

  // Initialize pseudo random mesh generator with the same seed
  srand(CTX::instance()->mesh.randomSeed);

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
  if(m->getMeshStatus() == 3 && CTX::instance()->mesh.algo3d != ALGO_3D_HXT) {
    for(int i = 0; i < std::max(CTX::instance()->mesh.optimize,
                                CTX::instance()->mesh.optimizeNetgen);
        i++) {
      if(CTX::instance()->mesh.optimize > i) OptimizeMesh(m);
      if(CTX::instance()->mesh.optimizeNetgen > i) OptimizeMeshNetgen(m);
    }
  }

  // Subdivide into quads or hexas
  if(m->getMeshStatus() == 2 && CTX::instance()->mesh.algoSubdivide == 1)
    RefineMesh(m, CTX::instance()->mesh.secondOrderLinear, true);
  else if(m->getMeshStatus() == 3 && CTX::instance()->mesh.algoSubdivide == 2)
    RefineMesh(m, CTX::instance()->mesh.secondOrderLinear, false, true);

  // Create high order elements
  if(m->getMeshStatus() && CTX::instance()->mesh.order > 1)
    SetOrderN(m, CTX::instance()->mesh.order,
              CTX::instance()->mesh.secondOrderLinear,
              CTX::instance()->mesh.secondOrderIncomplete);

  // Optimize high order elements
  if(CTX::instance()->mesh.hoOptimize < 0 ||
     CTX::instance()->mesh.hoOptimize >= 2)
    OptimizeHighOrderMeshElastic(GModel::current());

  if(CTX::instance()->mesh.hoOptimize >= 1)
    OptimizeHighOrderMesh(GModel::current());

  Msg::Info("%d vertices %d elements", m->getNumMeshVertices(),
            m->getNumMeshElements());

  Msg::PrintErrorCounter("Mesh generation error summary");

  CTX::instance()->lock = 0;
  // ProfilerStop();
}
