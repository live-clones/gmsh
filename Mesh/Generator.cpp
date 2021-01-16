// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
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
#include "HighOrderMeshFastCurving.h"
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
    std::map<MEdge, GEdge *, MEdgeLessThan> edges;
    std::map<MFace, GFace *, MFaceLessThan> faces;
    auto it = e.begin();
    auto itf = f.begin();
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
      Msg::Warning("Region %d : %d mesh edges that should be embedded are "
                   "missing in the final mesh",
                   gr->tag(), (int)edges.size());
      Msg::Info("Saving the missing edges in file %s", name);
      FILE *f = fopen(name, "w");
      fprintf(f, "View \" \" {\n");
      for(auto it = edges.begin(); it != edges.end(); ++it) {
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
      Msg::Warning("Volume %d : %d mesh faces that should be embedded are "
                   "missing in the final mesh",
                   gr->tag(), (int)faces.size());
      Msg::Info("Saving the missing faces in file %s", name);
      FILE *f = fopen(name, "w");
      fprintf(f, "View \" \" {\n");
      for(auto it = faces.begin(); it != faces.end(); ++it) {
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

void GetStatistics(double stat[50], double quality[3][100], bool visibleOnly)
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

  for(auto it = m->firstVertex(); it != m->lastVertex(); ++it) {
    if(visibleOnly && !(*it)->getVisibility()) continue;
    stat[4] += (*it)->mesh_vertices.size();
    stat[5] += (*it)->points.size();
  }

  for(auto it = m->firstEdge(); it != m->lastEdge(); ++it) {
    if(visibleOnly && !(*it)->getVisibility()) continue;
    stat[4] += (*it)->mesh_vertices.size();
    stat[6] += (*it)->lines.size();
  }

  for(auto it = m->firstFace(); it != m->lastFace(); ++it) {
    if(visibleOnly && !(*it)->getVisibility()) continue;
    stat[4] += (*it)->mesh_vertices.size();
    stat[7] += (*it)->triangles.size();
    stat[8] += (*it)->quadrangles.size();
  }

  for(auto it = m->firstRegion(); it != m->lastRegion(); ++it) {
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
      for(auto it = m->firstRegion(); it != m->lastRegion(); ++it) {
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
      for(auto it = m->firstFace(); it != m->lastFace(); ++it) {
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
  for(auto it = m->firstVertex(); it != m->lastVertex(); ++it)
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

  for(auto it = m->firstVertex(); it != m->lastVertex(); ++it) {
    GVertex *gv = *it;
    if(gv->mesh_vertices.empty())
      gv->mesh_vertices.push_back(new MVertex(gv->x(), gv->y(), gv->z(), gv));
    if(gv->points.empty())
      gv->points.push_back(new MPoint(gv->mesh_vertices.back()));
  }
  for(auto it = m->firstVertex(); it != m->lastVertex(); ++it) {
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
  if(CTX::instance()->abortOnError && Msg::GetErrorCount()) return;

  m->getFields()->initialize();

  if(TooManyElements(m, 1)) return;
  Msg::StatusBar(true, "Meshing 1D...");
  double t1 = Cpu(), w1 = TimeOfDay();

  int prevNumThreads = Msg::GetMaxThreads();
  if(CTX::instance()->mesh.maxNumThreads1D > 0 &&
     CTX::instance()->mesh.maxNumThreads1D <= Msg::GetMaxThreads())
    Msg::SetNumThreads(CTX::instance()->mesh.maxNumThreads1D);

  // boundary layers are not yet thread-safe
  if(m->getFields()->getNumBoundaryLayerFields()) Msg::SetNumThreads(1);

  for(auto it = m->firstEdge(); it != m->lastEdge(); ++it) {
    // Extruded meshes are not yet fully thread-safe (not sure why!)
    if((*it)->meshAttributes.extrude &&
       (*it)->meshAttributes.extrude->mesh.ExtrudeMesh)
      Msg::SetNumThreads(1);
  }

  std::vector<GEdge *> temp;
  for(auto it = m->firstEdge(); it != m->lastEdge(); ++it) {
    (*it)->meshStatistics.status = GEdge::PENDING;
    temp.push_back(*it);
  }

  int nIter = 0, nTot = m->getNumEdges();
  Msg::StartProgressMeter(nTot);

  while(1) {
    if(CTX::instance()->abortOnError && Msg::GetErrorCount()) {
      Msg::Warning("Aborted 1D meshing");
      break;
    }

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
      if(!nIter) Msg::ProgressMeter(nPending, false, "Meshing 1D...");
    }

    if(!nPending) break;
    if(nIter++ > CTX::instance()->mesh.maxRetries) break;
  }

  Msg::StopProgressMeter();

  Msg::SetNumThreads(prevNumThreads);

  double t2 = Cpu(), w2 = TimeOfDay();
  CTX::instance()->meshTimer[0] = w2 - w1;
  Msg::StatusBar(true, "Done meshing 1D (Wall %gs, CPU %gs)",
                 CTX::instance()->meshTimer[0], t2 - t1);
}

static void PrintMesh2dStatistics(GModel *m)
{
  FILE *statreport = nullptr;
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

  for(auto it = m->firstFace(); it != m->lastFace(); ++it) {
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
  if(CTX::instance()->abortOnError && Msg::GetErrorCount()) return;

  m->getFields()->initialize();

  if(TooManyElements(m, 2)) return;
  Msg::StatusBar(true, "Meshing 2D...");
  double t1 = Cpu(), w1 = TimeOfDay();

  int prevNumThreads = Msg::GetMaxThreads();
  if(CTX::instance()->mesh.maxNumThreads2D > 0 &&
     CTX::instance()->mesh.maxNumThreads2D <= Msg::GetMaxThreads())
    Msg::SetNumThreads(CTX::instance()->mesh.maxNumThreads2D);

  // boundary layers are not yet thread-safe
  if(m->getFields()->getNumBoundaryLayerFields()) Msg::SetNumThreads(1);

  for(auto it = m->firstFace(); it != m->lastFace(); ++it) {
    // Frontal-Delaunay for quads and co are not yet thread-safe
    if((*it)->getMeshingAlgo() == ALGO_2D_FRONTAL_QUAD ||
       (*it)->getMeshingAlgo() == ALGO_2D_PACK_PRLGRMS ||
       (*it)->getMeshingAlgo() == ALGO_2D_PACK_PRLGRMS_CSTR)
      Msg::SetNumThreads(1);
    // Periodic meshing is not yet thread-safe
    if((*it)->getMeshMaster() != *it) Msg::SetNumThreads(1);
    // Extruded meshes are not yet fully thread-safe (not sure why!)
    if((*it)->meshAttributes.extrude &&
       (*it)->meshAttributes.extrude->mesh.ExtrudeMesh)
      Msg::SetNumThreads(1);
  }

  for(auto it = m->firstFace(); it != m->lastFace(); ++it)
    (*it)->meshStatistics.status = GFace::PENDING;

  // boundary layers are special: their generation (including vertices and curve
  // meshes) is global as it depends on a smooth normal field generated from the
  // surface mesh of the source surfaces
  if(!Mesh2DWithBoundaryLayers(m)) {
    std::set<GFace *, GEntityPtrLessThan> f;
    for(auto it = m->firstFace(); it != m->lastFace(); ++it) f.insert(*it);

    int nIter = 0, nTot = m->getNumFaces();

    Msg::StartProgressMeter(nTot);

    while(1) {
      if(CTX::instance()->abortOnError && Msg::GetErrorCount()) {
        Msg::Warning("Aborted 2D meshing");
        break;
      }

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
        if(!nIter) Msg::ProgressMeter(nPending, false, "Meshing 2D...");
      }
      if(!nPending) break;
      // iter == 2 is for meshing re-parametrized surfaces; after that, we
      // serialize (self-intersections of 1D meshes are not thread safe)!
      if(nIter > 2) Msg::SetNumThreads(1);
      if(nIter++ > CTX::instance()->mesh.maxRetries) break;
    }

    Msg::StopProgressMeter();
  }

  Msg::SetNumThreads(prevNumThreads);

  double t2 = Cpu(), w2 = TimeOfDay();
  CTX::instance()->meshTimer[1] = w2 - w1;
  Msg::StatusBar(true, "Done meshing 2D (Wall %gs, CPU %gs)",
                 CTX::instance()->meshTimer[1], t2 - t1);

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
      for(auto it = faces.begin(); it != faces.end(); ++it) {
        GFace *gf = *it;
        GRegion *other =
          (gf->getRegion(0) == r) ? gf->getRegion(1) : gf->getRegion(0);
        if(other != nullptr && oneDomain.find(other) == oneDomain.end())
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
  Msg::Info("3D Meshing %d volume%s with %d connected component%s", nbVolumes,
            nbVolumes > 1 ? "s" : "", connected.size(),
            connected.size() > 1 ? "s" : "");
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

void buildUniqueFaces(GRegion *gr, std::set<MFace, MFaceLessThan> &bnd)
{
  for(std::size_t i = 0; i < gr->getNumMeshElements(); i++) {
    MElement *e = gr->getMeshElement(i);
    for(int j = 0; j < e->getNumFaces(); j++) {
      MFace f = e->getFace(j);
      auto it = bnd.find(f);
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
  std::set<MFace, MFaceLessThan> bnd;
  for(auto rit = gm->firstRegion(); rit != gm->lastRegion(); ++rit) {
    GRegion *gr = *rit;
    buildUniqueFaces(gr, bnd);
  }
  // bnd2 contains non conforming faces

  std::set<MFace, MFaceLessThan> bnd2;
  for(auto itf = bnd.begin(); itf != bnd.end(); ++itf) {
    GFace *gfound = findInFaceSearchStructure(*itf, search);
    if(!gfound) { bnd2.insert(*itf); }
  }
  bnd.clear();

  Msg::Info("%d hanging faces", bnd2.size());

  std::set<MFace, MFaceLessThan> ncf;
  for(auto itf = bnd2.begin(); itf != bnd2.end(); ++itf) {
    const MFace &f = *itf;
    if(f.getNumVertices() == 4) { // quad face
      auto it1 =
        bnd2.find(MFace(f.getVertex(0), f.getVertex(1), f.getVertex(2)));
      auto it2 =
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

  for(auto rit = gm->firstRegion(); rit != gm->lastRegion(); ++rit) {
    GRegion *gr = *rit;
    std::vector<MHexahedron *> remainingHexes;
    for(std::size_t i = 0; i < gr->hexahedra.size(); i++) {
      MHexahedron *e = gr->hexahedra[i];
      std::vector<MFace> faces;
      for(int j = 0; j < e->getNumFaces(); j++) {
        MFace f = e->getFace(j);
        auto it = ncf.find(f);
        if(it == ncf.end()) { faces.push_back(f); }
        else {
          faces.push_back(
            MFace(it->getVertex(0), it->getVertex(1), it->getVertex(3)));
          faces.push_back(
            MFace(it->getVertex(1), it->getVertex(2), it->getVertex(3)));
        }
      }
      // Hex is only surrounded by compatible elements
      if((int)faces.size() == e->getNumFaces()) { remainingHexes.push_back(e); }
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
        auto it = ncf.find(f);
        if(it == ncf.end()) { faces.push_back(f); }
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
  for(auto rit = gm->firstRegion(); rit != gm->lastRegion(); ++rit) {
    GRegion *gr = *rit;
    std::set<MFace, MFaceLessThan> bnd;
    double vol = 0.0;
    for(std::size_t i = 0; i < gr->getNumMeshElements(); i++) {
      MElement *e = gr->getMeshElement(i);
      vol += fabs(e->getVolume());
      for(int j = 0; j < e->getNumFaces(); j++) {
        MFace f = e->getFace(j);
        auto it = bnd.find(f);
        if(it == bnd.end())
          bnd.insert(f);
        else
          bnd.erase(it);
      }
    }
    printf("vol(%d) = %12.5E\n", gr->tag(), vol);

    for(auto itf = bnd.begin(); itf != bnd.end(); ++itf) {
      GFace *gfound = findInFaceSearchStructure(*itf, search);
      if(!gfound) { count++; }
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
  if(CTX::instance()->abortOnError && Msg::GetErrorCount()) return;

  m->getFields()->initialize();

  if(TooManyElements(m, 3)) return;
  Msg::StatusBar(true, "Meshing 3D...");
  double t1 = Cpu(), w1 = TimeOfDay();

  int prevNumThreads = Msg::GetMaxThreads();
  if(CTX::instance()->mesh.maxNumThreads3D > 0 &&
     CTX::instance()->mesh.maxNumThreads3D <= Msg::GetMaxThreads())
    Msg::SetNumThreads(CTX::instance()->mesh.maxNumThreads3D);

  for(auto it = m->firstRegion(); it != m->lastRegion(); ++it) {
    // Extruded meshes are not yet fully thread-safe (not sure why!)
    if((*it)->meshAttributes.extrude &&
       (*it)->meshAttributes.extrude->mesh.ExtrudeMesh)
      Msg::SetNumThreads(1);
  }

  if(m->getNumRegions()) {
    Msg::StartProgressMeter(1);
    Msg::ProgressMeter(0, false, "Meshing 3D...");
  }

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
        for(auto it = f.begin(); it != f.end(); ++it)
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
    if(CTX::instance()->abortOnError && Msg::GetErrorCount()) {
      Msg::Warning("Aborted 3D meshing");
      break;
    }

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
        double a = TimeOfDay();
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
        time_recombination += (TimeOfDay() - a);
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
    std::for_each(m->firstRegion(), m->lastRegion(),
                  EmbeddedCompatibilityTest());

  std::stringstream debugInfo;
  debugInfo << "No elements in volume ";
  bool emptyRegionFound = false;
  for(auto it = m->firstRegion(); it != m->lastRegion(); ++it) {
    GRegion *gr = *it;
    if(CTX::instance()->mesh.meshOnlyVisible && !gr->getVisibility()) continue;
    if(CTX::instance()->mesh.meshOnlyEmpty && gr->getNumMeshElements())
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

  double t2 = Cpu(), w2 = TimeOfDay();
  CTX::instance()->meshTimer[2] = w2 - w1;

  if(m->getNumRegions()) {
    Msg::ProgressMeter(1, false, "Meshing 3D...");
    Msg::StopProgressMeter();
  }

  Msg::StatusBar(true, "Done meshing 3D (Wall %gs, CPU %gs)",
                 CTX::instance()->meshTimer[2], t2 - t1);
}

void OptimizeMesh(GModel *m, const std::string &how, bool force, int niter)
{
  if(CTX::instance()->abortOnError && Msg::GetErrorCount()) return;

  if(how != "" && how != "Gmsh" && how != "Optimize" && how != "Netgen" &&
     how != "HighOrder" && how != "HighOrderElastic" &&
     how != "HighOrderFastCurving" && how != "Laplace2D" &&
     how != "Relocate2D" && how != "Relocate3D") {
    Msg::Error("Unknown mesh optimization method '%s'", how.c_str());
    return;
  }

  if(how == "" || how == "Gmsh" || how == "Optimize")
    Msg::StatusBar(true, "Optimizing mesh...");
  else
    Msg::StatusBar(true, "Optimizing mesh (%s)...", how.c_str());
  double t1 = Cpu(), w1 = TimeOfDay();

  if(how == "" || how == "Gmsh" || how == "Optimize") {
    for(auto it = m->firstRegion(); it != m->lastRegion(); it++) {
      optimizeMeshGRegion opt;
      opt(*it, force);
    }
    m->setAllVolumesPositive();
  }
  else if(how == "Netgen") {
    for(auto it = m->firstRegion(); it != m->lastRegion(); it++) {
      optimizeMeshGRegionNetgen opt;
      opt(*it, force);
    }
    m->setAllVolumesPositive();
  }
  else if(how == "HighOrder") {
#if defined(HAVE_OPTHOM)
    OptHomParameters p;
    p.nbLayers = CTX::instance()->mesh.hoNLayers;
    p.BARRIER_MIN = CTX::instance()->mesh.hoThresholdMin;
    p.BARRIER_MAX = CTX::instance()->mesh.hoThresholdMax;
    p.itMax = CTX::instance()->mesh.hoIterMax;
    p.optPassMax = CTX::instance()->mesh.hoPassMax;
    p.dim = m->getDim();
    p.optPrimSurfMesh = CTX::instance()->mesh.hoPrimSurfMesh;
    p.optCAD = CTX::instance()->mesh.hoDistCAD;
    HighOrderMeshOptimizer(m, p);
#else
    Msg::Error("High-order mesh optimization requires the OPTHOM module");
#endif
  }
  else if(how == "HighOrderElastic") {
#if defined(HAVE_OPTHOM)
    HighOrderMeshElasticAnalogy(m, false);
#else
    Msg::Error("High-order mesh optimization requires the OPTHOM module");
#endif
  }
  else if(how == "HighOrderFastCurving") {
#if defined(HAVE_OPTHOM)
    FastCurvingParameters p;
    p.dim = m->getMeshDim();
    p.thickness = false;
    p.curveOuterBL =
      (FastCurvingParameters::OUTERBLCURVE)CTX::instance()->mesh.hoCurveOuterBL;
    p.maxNumLayers = CTX::instance()->mesh.hoNLayers;
    p.maxRho = CTX::instance()->mesh.hoMaxRho;
    p.maxAngle = CTX::instance()->mesh.hoMaxAngle;
    p.maxAngleInner = CTX::instance()->mesh.hoMaxInnerAngle;
    HighOrderMeshFastCurving(m, p, false);
#else
    Msg::Error("High-order mesh optimization requires the OPTHOM module");
#endif
  }
  else if(how == "Laplace2D") {
    for(auto it = m->firstFace(); it != m->lastFace(); ++it) {
      GFace *gf = *it;
      laplaceSmoothing(gf, niter);
    }
  }
  else if(how == "Relocate2D") {
    for(auto it = m->firstFace(); it != m->lastFace(); ++it) {
      GFace *gf = *it;
      RelocateVertices(gf, niter);
    }
  }
  else if(how == "Relocate3D") {
    for(auto it = m->firstRegion(); it != m->lastRegion(); ++it) {
      GRegion *gr = *it;
      RelocateVertices(gr, niter);
    }
  }

  if(Msg::GetVerbosity() > 98)
    std::for_each(m->firstRegion(), m->lastRegion(),
                  EmbeddedCompatibilityTest());

  double t2 = Cpu(), w2 = TimeOfDay();
  Msg::StatusBar(true, "Done optimizing mesh (Wall %gs, CPU %gs)", w2 - w1,
                 t2 - t1);
}

void AdaptMesh(GModel *m)
{
  if(CTX::instance()->abortOnError && Msg::GetErrorCount()) return;

  Msg::StatusBar(true, "Adapting 3D mesh...");
  double t1 = Cpu(), w1 = TimeOfDay();

  for(int i = 0; i < 10; i++)
    std::for_each(m->firstRegion(), m->lastRegion(), adaptMeshGRegion());

  double t2 = Cpu(), w2 = TimeOfDay();
  Msg::StatusBar(true, "Done adaptating 3D mesh (Wall %gs, CPU %gs)", w2 - w1,
                 t2 - t1);
}

void RecombineMesh(GModel *m)
{
  if(CTX::instance()->abortOnError && Msg::GetErrorCount()) return;

  Msg::StatusBar(true, "Recombining 2D mesh...");
  double t1 = Cpu(), w1 = TimeOfDay();

  for(auto it = m->firstFace(); it != m->lastFace(); ++it) {
    GFace *gf = *it;
    bool blossom = (CTX::instance()->mesh.algoRecombine == 1 ||
                    CTX::instance()->mesh.algoRecombine == 3);
    int topo = CTX::instance()->mesh.recombineOptimizeTopology;
    recombineIntoQuads(gf, blossom, topo, true, .01);
  }

  double t2 = Cpu(), w2 = TimeOfDay();
  Msg::StatusBar(true, "Done recombining 2D mesh (Wall %gs, CPU %gs)", w2 - w1,
                 t2 - t1);
}

static SPoint3 transform(MVertex *vsource, const std::vector<double> &tfo)
{
  double ps[4] = {vsource->x(), vsource->y(), vsource->z(), 1.};
  double res[4] = {0., 0., 0., 0.};
  int idx = 0;
  for(int i = 0; i < 4; i++)
    for(int j = 0; j < 4; j++) res[i] += tfo[idx++] * ps[j];

  return SPoint3(res[0], res[1], res[2]);
}

static void relocateSlaveVertices(GFace *slave,
                                  std::map<MVertex *, MVertex *> &vertS2M,
                                  bool useClosestPoint)
{
  for(auto vit = vertS2M.begin(); vit != vertS2M.end(); ++vit) {
    MFaceVertex *v = dynamic_cast<MFaceVertex *>(vit->first);
    if(v && v->onWhat() == slave) {
      SPoint3 p = transform(vit->second, slave->affineTransform);
      SPoint2 p2;
      if(useClosestPoint) {
        double guess[2];
        v->getParameter(0, guess[0]);
        v->getParameter(1, guess[1]);
        GPoint pp = slave->closestPoint(p, guess);
        p2.setPosition(pp.u(), pp.v());
      }
      else {
        p2 = slave->parFromPoint(p);
      }
      GPoint gp = slave->point(p2);
      v->setXYZ(gp.x(), gp.y(), gp.z());
      v->setParameter(0, gp.u());
      v->setParameter(1, gp.v());
    }
  }
}

static void relocateSlaveVertices(GEdge *slave,
                                  std::map<MVertex *, MVertex *> &vertS2M,
                                  bool useClosestPoint)
{
  for(auto vit = vertS2M.begin(); vit != vertS2M.end(); ++vit) {
    MEdgeVertex *v = dynamic_cast<MEdgeVertex *>(vit->first);
    if(v && v->onWhat() == slave) {
      SPoint3 p = transform(vit->second, slave->affineTransform);
      double u;
      if(useClosestPoint) {
        v->getParameter(0, u);
        GPoint pp = slave->closestPoint(p, u);
        u = pp.u();
      }
      else {
        u = slave->parFromPoint(p);
      }
      GPoint gp = slave->point(u);
      v->setXYZ(gp.x(), gp.y(), gp.z());
      v->setParameter(0, u);
    }
  }
}

static void relocateSlaveVertices(std::vector<GEntity *> &entities,
                                  bool useClosestPoint)
{
  std::multimap<GEntity *, GEntity *> master2slave;
  for(std::size_t i = 0; i < entities.size(); ++i) {
    if(entities[i]->dim() == 0) continue;
    GEntity *master = entities[i]->getMeshMaster();
    if(master != entities[i]) {
      master2slave.insert(std::make_pair(master, entities[i]));
    }
  }

  for(auto it = master2slave.begin(); it != master2slave.end(); ++it) {
    if(it->first->dim() == 2) {
      GFace *master = dynamic_cast<GFace *>(it->first);
      GFace *slave = dynamic_cast<GFace *>(it->second);
      if(slave->affineTransform.size() < 16) continue;
      Msg::Info("Relocating nodes of slave surface %i using master %i%s",
                slave->tag(), master->tag(),
                useClosestPoint ? " (using closest point)" : "");
      relocateSlaveVertices(slave, slave->correspondingVertices,
                            useClosestPoint);
      relocateSlaveVertices(slave, slave->correspondingHighOrderVertices,
                            useClosestPoint);
    }
    else if(it->first->dim() == 1) {
      GEdge *master = dynamic_cast<GEdge *>(it->first);
      GEdge *slave = dynamic_cast<GEdge *>(it->second);
      if(slave->affineTransform.size() < 16) continue;
      Msg::Info("Relocating nodes of slave curve %i using master %i%s",
                slave->tag(), master->tag(),
                useClosestPoint ? " (using closest point)" : "");
      relocateSlaveVertices(slave, slave->correspondingVertices,
                            useClosestPoint);
      relocateSlaveVertices(slave, slave->correspondingHighOrderVertices,
                            useClosestPoint);
    }
  }
}

void FixPeriodicMesh(GModel *m)
{
  if(CTX::instance()->abortOnError && Msg::GetErrorCount()) return;

  for(auto it = m->firstEdge(); it != m->lastEdge(); ++it) {
    GEdge *tgt = *it;

    // non complete periodic info (e.g. through extrusion)
    if(tgt->vertexCounterparts.empty()) continue;

    GEdge *src = dynamic_cast<GEdge *>(tgt->getMeshMaster());

    if(src != nullptr && src != tgt) {
      std::map<MVertex *, MVertex *> &v2v = tgt->correspondingVertices;
      std::map<MVertex *, MVertex *> &p2p = tgt->correspondingHighOrderVertices;
      p2p.clear();

      Msg::Info("Reconstructing periodicity for curve connection %d - %d",
                tgt->tag(), src->tag());

      std::map<MEdge, MLine *, MEdgeLessThan> srcEdges;
      for(std::size_t i = 0; i < src->getNumMeshElements(); i++) {
        MLine *srcLine = dynamic_cast<MLine *>(src->getMeshElement(i));
        if(!srcLine) {
          Msg::Error("Master element %d is not a line",
                     src->getMeshElement(i)->getNum());
          return;
        }
        srcEdges[MEdge(srcLine->getVertex(0), srcLine->getVertex(1))] = srcLine;
      }

      for(std::size_t i = 0; i < tgt->getNumMeshElements(); ++i) {
        MLine *tgtLine = dynamic_cast<MLine *>(tgt->getMeshElement(i));
        MVertex *vtcs[2];
        if(!tgtLine) {
          Msg::Error("Slave element %d is not a line",
                     tgt->getMeshElement(i)->getNum());
          return;
        }
        for(int iVtx = 0; iVtx < 2; iVtx++) {
          MVertex *vtx = tgtLine->getVertex(iVtx);
          auto tIter = v2v.find(vtx);
          if(tIter == v2v.end()) {
            Msg::Error("Cannot find periodic counterpart of node %d"
                       " of curve %d on curve %d",
                       vtx->getNum(), tgt->tag(), src->tag());
            return;
          }
          else
            vtcs[iVtx] = tIter->second;
        }

        auto srcIter = srcEdges.find(MEdge(vtcs[0], vtcs[1]));
        if(srcIter == srcEdges.end()) {
          Msg::Error("Can't find periodic counterpart of mesh edge %d-%d "
                     "on curve %d, connected to mesh edge %d-%d on curve %d",
                     tgtLine->getVertex(0)->getNum(),
                     tgtLine->getVertex(1)->getNum(), tgt->tag(),
                     vtcs[0]->getNum(), vtcs[1]->getNum(), src->tag());
          return;
        }
        else {
          MLine *srcLine = srcIter->second;
          for(std::size_t i = 2; i < tgtLine->getNumVertices(); i++)
            p2p[tgtLine->getVertex(i)] = srcLine->getVertex(i);
        }
      }
    }
  }

  if(CTX::instance()->mesh.hoPeriodic) {
    std::vector<GEntity *> modelEdges(m->firstEdge(), m->lastEdge());
    relocateSlaveVertices(modelEdges, CTX::instance()->mesh.hoPeriodic > 1);
  }

  for(auto it = m->firstFace(); it != m->lastFace(); ++it) {
    GFace *tgt = *it;

    // non complete periodic info (e.g. through extrusion)
    if(tgt->vertexCounterparts.empty()) continue;

    GFace *src = dynamic_cast<GFace *>(tgt->getMeshMaster());
    if(src != nullptr && src != tgt) {
      Msg::Info("Reconstructing periodicity for surface connection %d - %d",
                tgt->tag(), src->tag());

      std::map<MVertex *, MVertex *> &v2v = tgt->correspondingVertices;
      std::map<MVertex *, MVertex *> &p2p = tgt->correspondingHighOrderVertices;
      p2p.clear();

      if(tgt->getNumMeshElements() && v2v.empty()) {
        Msg::Info("No periodic vertices in surface %d (maybe due to a "
                  "structured mesh constraint on the target surface)",
                  tgt->tag());
        continue;
      }

      std::map<MFace, MElement *, MFaceLessThan> srcFaces;

      for(std::size_t i = 0; i < src->getNumMeshElements(); ++i) {
        MElement *srcElmt = src->getMeshElement(i);
        int nbVtcs = 0;
        if(dynamic_cast<MTriangle *>(srcElmt)) nbVtcs = 3;
        if(dynamic_cast<MQuadrangle *>(srcElmt)) nbVtcs = 4;
        std::vector<MVertex *> vtcs;
        vtcs.reserve(nbVtcs);
        for(int iVtx = 0; iVtx < nbVtcs; iVtx++) {
          vtcs.push_back(srcElmt->getVertex(iVtx));
        }
        srcFaces[MFace(vtcs)] = srcElmt;
      }

      for(std::size_t i = 0; i < tgt->getNumMeshElements(); ++i) {
        MElement *tgtElmt = tgt->getMeshElement(i);
        int nbVtcs = 0;
        if(dynamic_cast<MTriangle *>(tgtElmt)) nbVtcs = 3;
        if(dynamic_cast<MQuadrangle *>(tgtElmt)) nbVtcs = 4;
        std::vector<MVertex *> vtcs;
        for(int iVtx = 0; iVtx < nbVtcs; iVtx++) {
          MVertex *vtx = tgtElmt->getVertex(iVtx);

          auto tIter = v2v.find(vtx);
          if(tIter == v2v.end()) {
            Msg::Error("Cannot find periodic counterpart of node %d "
                       "of surface %d on surface %d",
                       vtx->getNum(), tgt->tag(), src->tag());
            return;
          }
          else
            vtcs.push_back(tIter->second);
        }

        MFace tgtFace(vtcs);
        auto srcIter = srcFaces.find(tgtFace);
        if(srcIter == srcFaces.end()) {
          std::ostringstream faceDef;
          for(int iVtx = 0; iVtx < nbVtcs; iVtx++)
            faceDef << vtcs[iVtx]->getNum() << " ";
          Msg::Error("Cannot find periodic counterpart of mesh face %s in "
                     "surface %d on surface %d",
                     faceDef.str().c_str(), tgt->tag(), src->tag());
          return;
        }
        else {
          MElement *srcElmt = srcIter->second;
          // Warning: this check is made in case the source and target surface
          // meshes are oriented differently (e.g. to be consistent with the
          // underlying orientation of the geometrical surfaces)
          bool revert = dot(tgtFace.normal(), srcIter->first.normal()) < 0;
          if(revert) srcElmt->reverse();
          for(std::size_t j = nbVtcs; j < srcElmt->getNumVertices(); j++) {
            p2p[tgtElmt->getVertex(j)] = srcElmt->getVertex(j);
          }
          if(revert) srcElmt->reverse();
        }
      }
    }
  }

  if(CTX::instance()->mesh.hoPeriodic) {
    std::vector<GEntity *> modelFaces(m->firstFace(), m->lastFace());
    relocateSlaveVertices(modelFaces, CTX::instance()->mesh.hoPeriodic > 1);
  }
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

  // Change any high order elements back into first order ones (but skip
  // discrete entities)
  SetOrder1(m, false, true);
  FixPeriodicMesh(m);

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
  if(ask == 3) { Mesh3D(m); }

  // Orient the line and surface meshes so that they match the orientation of
  // the geometrical entities and/or the user orientation constraints
  if(m->getMeshStatus() >= 1)
    std::for_each(m->firstEdge(), m->lastEdge(), orientMeshGEdge());
  if(m->getMeshStatus() >= 2)
    std::for_each(m->firstFace(), m->lastFace(), orientMeshGFace());

  // Optimize quality of 3D tet mesh
  if(m->getMeshStatus() == 3 &&
     CTX::instance()->mesh.algo3d != ALGO_3D_INITIAL_ONLY &&
     CTX::instance()->mesh.algo3d != ALGO_3D_HXT) {
    for(int i = 0; i < std::max(CTX::instance()->mesh.optimize,
                                CTX::instance()->mesh.optimizeNetgen);
        i++) {
      if(CTX::instance()->mesh.optimize > i) OptimizeMesh(m);
      if(CTX::instance()->mesh.optimizeNetgen > i) OptimizeMesh(m, "Netgen");
    }
  }

  // Subdivide into quads or hexas
  if(m->getMeshStatus() == 2 && CTX::instance()->mesh.algoSubdivide == 1)
    RefineMesh(m, CTX::instance()->mesh.secondOrderLinear, true);
  else if(m->getMeshStatus() == 3 && CTX::instance()->mesh.algoSubdivide == 2)
    RefineMesh(m, CTX::instance()->mesh.secondOrderLinear, false, true);
  else if(m->getMeshStatus() >= 2 && CTX::instance()->mesh.algoSubdivide == 3)
    BarycentricRefineMesh(m);

  if(m->getMeshStatus() && CTX::instance()->mesh.order > 1) {
    // Create high order elements
    SetOrderN(m, CTX::instance()->mesh.order,
              CTX::instance()->mesh.secondOrderLinear,
              CTX::instance()->mesh.secondOrderIncomplete);

    // Optimize high order elements
    if(CTX::instance()->mesh.hoOptimize == 2 ||
       CTX::instance()->mesh.hoOptimize == 3)
      OptimizeMesh(m, "HighOrderElastic");

    if(CTX::instance()->mesh.hoOptimize == 1 ||
       CTX::instance()->mesh.hoOptimize == 2)
      OptimizeMesh(m, "HighOrder");

    if(CTX::instance()->mesh.hoOptimize == 4)
      OptimizeMesh(m, "HighOrderFastCurving");
  }

  // make sure periodic meshes are actually periodic and store periodic node
  // correspondances
  FixPeriodicMesh(m);

  Msg::Info("%d nodes %d elements", m->getNumMeshVertices(),
            m->getNumMeshElements());

  Msg::PrintErrorCounter("Mesh generation error summary");

  CTX::instance()->lock = 0;
  // ProfilerStop();
}
