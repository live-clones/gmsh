// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

#include "meshQuadQuasiStructured.h"

#include <array>

#include "GmshConfig.h"
#include "GmshMessage.h"
#include "Numeric.h"
#include "Context.h"
#include "OS.h"
#include "GModel.h"
#include "meshGEdge.h"
#include "meshGFace.h"
#include "meshGFaceOptimize.h"
#include "meshGRegion.h"
#include "BackgroundMesh.h"
#include "Generator.h"
#include "Field.h"
#include "MElement.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MLine.h"

#if defined(HAVE_POST)
#include "PView.h"
#include "PViewData.h"
#include "PViewDataList.h"
#include "PViewDataGModel.h"
#include "PViewOptions.h"
#endif
#include "GuiListener.h"

#if defined(HAVE_QUADMESHINGTOOLS)
#include "cppUtils.h"
#include "qmtMeshUtils.h"
#include "qmtCrossField.h"
#include "qmtSizeMap.h"
#include "qmtQuadCavityRemeshing.h"
#include "qmtMeshGeometryOptimization.h"
#include "arrayGeometry.h"
#include "geolog.h"

using namespace CppUtils;
using namespace ArrayGeometry;

constexpr int SizeMapDefault = 0;
constexpr int SizeMapCrossFieldAndSmallCad = 2;
constexpr int SizeMapBackgroundMesh = 3;
constexpr int SizeMapCrossFieldAndBMeshOnCurves = 4;

const std::string BMESH_NAME = "bmesh_quadqs";


/* scaling applied on integer values stored in view (background field),
 * so the visualization is not broken by the integers */
constexpr double VIEW_INT_SCALING = 1.e-8;

static int getNumThreads()
{
  int nthreads = CTX::instance()->numThreads;
  if(CTX::instance()->mesh.maxNumThreads2D > 0)
    nthreads = CTX::instance()->mesh.maxNumThreads2D;
  if(!nthreads) nthreads = Msg::GetMaxThreads();
  return nthreads;
}

int buildBackgroundField(
  GModel *gm, const std::vector<MTriangle *> &global_triangles,
  const std::vector<std::array<double, 9>> &global_triangle_directions,
  const std::unordered_map<MVertex *, double> &global_size_map,
  const std::vector<std::array<double, 5>> &global_singularity_list,
  const std::string &viewName = "guiding_field")
{
  Msg::Info("Build background field (view 'guiding_field') ...");
  if(global_triangles.size() != global_triangle_directions.size()) {
    Msg::Error("build background field: incoherent sizes in input");
    return -1;
  }

  std::vector<double> datalist;
  datalist.reserve(global_triangles.size() * 18);
  for(size_t i = 0; i < global_triangles.size(); ++i) {
    MTriangle *t = global_triangles[i];
    /* Triangle coordinates */
    for(size_t d = 0; d < 3; ++d) {
      for(size_t lv = 0; lv < 3; ++lv) {
        datalist.push_back(t->getVertex(lv)->point().data()[d]);
      }
    }
    /* Vector field */
    for(size_t lv = 0; lv < 3; ++lv) {
      MVertex *v = t->getVertex(lv);
      auto it = global_size_map.find(v);
      if(it == global_size_map.end()) {
        Msg::Error("Building background field, triangle vertex not found in "
                   "global size map");
        return -1;
      }
      double siz = it->second;
      for(size_t d = 0; d < 3; ++d) {
        double val = siz * global_triangle_directions[i][3 * lv + d];
        datalist.push_back(val);
      }
    }
  }

#if defined(HAVE_POST)
  PView *view = PView::getViewByName(viewName);
  if(view == NULL) {
    view = new PView();
    view->getData()->setName(viewName);
  }
  PViewDataList *d = dynamic_cast<PViewDataList *>(view->getData());
  if(!d) { // change the view type
    std::string name = view->getData()->getName();
    delete view->getData();
    d = new PViewDataList();
    d->setName(name);
    d->setFileName(name + ".pos");
    view->setData(d);
  }

  size_t numElements = datalist.size() / (9 + 9);
  int idxtypeVT = 7; /* Post type: VT */
  d->importList(idxtypeVT, numElements, datalist, false);

  view->getOptions()->visible = 0;
  Gui()->viewsChanged(true);

  /* singularities */
  if(global_singularity_list.size() > 0) {
    int idxtypeVP = 1; /* Post type: VP */
    std::vector<double> datalistSING;
    datalistSING.reserve(global_singularity_list.size() * 6);
    for(size_t i = 0; i < global_singularity_list.size(); ++i) {
      datalistSING.push_back(global_singularity_list[i][2]); /* x */
      datalistSING.push_back(global_singularity_list[i][3]); /* y */
      datalistSING.push_back(global_singularity_list[i][4]); /* z */
      datalistSING.push_back(
        VIEW_INT_SCALING *
        double(global_singularity_list[i][0])); /* gf->tag() */
      datalistSING.push_back(VIEW_INT_SCALING *
                             double(global_singularity_list[i][1])); /* index */
      datalistSING.push_back(0.); /* empty */
    }
    d->importList(idxtypeVP, datalistSING.size() / 6, datalistSING, false);
  }

  d->finalize();

  gm->getFields()->setGuidingField(view->getIndex());

  const bool exportBGM = false;
  if(exportBGM || Msg::GetVerbosity() >= 99) {
    std::string name = gm->getName() + "_bgm.pos";
    Msg::Warning("Exporting background field to '%s'", name.c_str());
    view->write(name, PView::POS_ASCII);
  }

  return 0;
#else
  Msg::Error("Post-processing module required to create background field view");
  return -1;
#endif
}

void showCrossFieldInView(
  const std::vector<MTriangle *> &global_triangles,
  const std::vector<std::array<double, 9>> &global_triangle_directions,
  const std::string &viewName = "cross_field")
{
  for(size_t i = 0; i < global_triangles.size(); ++i) {
    for(size_t lv = 0; lv < 3; ++lv) {
      MVertex *v = global_triangles[i]->getVertex(lv);
      vec3 dir = {{global_triangle_directions[i][3 * lv + 0],
                   global_triangle_directions[i][3 * lv + 1],
                   global_triangle_directions[i][3 * lv + 2]}};
      std::array<double, 3> pt = v->point();
      GeoLog::add(pt, dir, viewName);
    }
  }
  GeoLog::flush();
}

void showUVParametrization(GFace *gf, const std::vector<MElement *> &elts,
                           const std::string &viewName = "uv")
{
  std::vector<std::vector<double>> values_u;
  std::vector<std::vector<double>> values_v;
  for(MElement *t : elts) {
    std::vector<SPoint2> tris_uvs = paramOnElement(gf, t);
    std::vector<double> us(tris_uvs.size());
    std::vector<double> vs(tris_uvs.size());
    for(size_t k = 0; k < us.size(); ++k) {
      us[k] = tris_uvs[k][0];
      vs[k] = tris_uvs[k][1];
    }
    values_u.push_back(us);
    values_v.push_back(vs);
  }
  GeoLog::add(elts, values_u, viewName + "_u");
  GeoLog::add(elts, values_v, viewName + "_v");
}

void showUVParametrization(GlobalBackgroundMesh &bgm,
                           const std::string &viewName = "uv")
{
  for(auto &kv : bgm.faceBackgroundMeshes) {
    GFace *gf = kv.first;
    if(!gf->haveParametrization()) continue;
    std::vector<MElement *> tris;
    for(MTriangle &t : kv.second.triangles) { tris.push_back(&t); }
    showUVParametrization(gf, tris, viewName);
  }
  GeoLog::flush();
}

void printSizeMapStats(const std::vector<MTriangle *> &triangles,
                       std::unordered_map<MVertex *, double> &sizemap)
{
  double vmin = DBL_MAX;
  double vmax = -DBL_MAX;
  for(auto &kv : sizemap) {
    vmin = std::min(vmin, kv.second);
    vmax = std::max(vmax, kv.second);
  }
  double integral = 0.;
  for(MTriangle *t : triangles) {
    double values[3] = {0, 0, 0};
    for(size_t lv = 0; lv < 3; ++lv) {
      MVertex *v = t->getVertex(lv);
      auto it = sizemap.find(v);
      values[lv] = it->second;
      ;
    }
    double a = std::abs(t->getVolume());
    integral +=
      a * 1. / std::pow(1. / 3. * (values[0] + values[1] + values[2]), 2);
  }
  Msg::Info("Size map statistics: min=%.3f, max=%.3f, target #elements: %.3f",
            vmin, vmax, integral);
}

int fillSizemapFromTriangleSizes(const std::vector<MTriangle *> &triangles,
                                 std::unordered_map<MVertex *, double> &sizeMap)
{
  const double tol = CTX::instance()->geom.tolerance;
  VertexToVertexMap v2v;
  buildVertexToVertexMap(triangles, v2v);
  for(auto &kv : v2v) {
    MVertex *v = kv.first;
    double sum = 0.;
    double avg = 0.;
    for(MVertex *v2 : kv.second) {
      double dist = v->distance(v2);
      if(dist > tol) {
        avg += dist;
        sum += 1.;
      }
    }
    if(sum == 0.) continue;
    sizeMap[v] = avg / sum;
  }

  /* Laplacian smoothing of the size map */
  size_t iterMax = 3;
  for(size_t iter = 0; iter < iterMax; ++iter) {
    for(auto &kv : v2v) {
      MVertex *v = kv.first;
      // if (v->onWhat()->dim() < 2) continue;
      double sum = 0.;
      double avg = 0.;
      for(MVertex *v2 : kv.second) {
        avg += sizeMap[v2];
        sum += 1.;
      }
      if(sum == 0.) continue;
      auto it = sizeMap.find(v);
      if(it == sizeMap.end()) continue;
      it->second = 0.5 * it->second + 0.5 * avg / sum;
    }
  }

  return 0;
}

int fillSizemapFromScalarBackgroundField(
  GModel *gm, const std::vector<MTriangle *> &triangles,
  std::unordered_map<MVertex *, double> &sizeMap)
{
  Field *field = nullptr;
  FieldManager *fields = gm->getFields();
  if(fields->getBackgroundField() > 0) {
    field = fields->get(fields->getBackgroundField());
    if(field && field->numComponents() != 1) { field = nullptr; }
  }
  if(field == nullptr) {
    Msg::Error("Scalar background field not found");
    return -1;
  }
  for(MTriangle *t : triangles)
    for(size_t lv = 0; lv < 3; ++lv) {
      MVertex *v = t->getVertex(lv);
      auto it = sizeMap.find(v);
      if(it == sizeMap.end()) {
        double value = (*field)(v->x(), v->y(), v->z());
        if(std::isnan(value) || value == -DBL_MAX || value == DBL_MAX) continue;
        sizeMap[v] = value;
      }
    }
  return 0;
}

std::string nameOfSizeMapMethod(int method)
{
  if(method == 0) { return "default (" + nameOfSizeMapMethod(4) + ")"; }
  else if(method == 1) {
    return "cross-field conformal scaling";
  }
  else if(method == 2) {
    return "cross-field conformal scaling and CAD adaptation";
  }
  else if(method == 3) {
    return "background mesh sizes";
  }
  else if(method == 4) {
    return "cross-field conformal scaling and CAD adaptation (clamped by "
           "background mesh)";
  }
  return "unknown";
}

static bool generateBackgroundTriangulation(GModel *gm)
{
  Msg::Debug("build background triangulation ...");

  /* Change meshing parameters to build a good triangulation
   * for cross field, restored however the meshing ends */
  struct savedParameters {
    int minCurveNodes = CTX::instance()->mesh.minCurveNodes;
    int minCircleNodes = CTX::instance()->mesh.minCircleNodes;
    int recombineAll = CTX::instance()->mesh.recombineAll;
    int algoRecombine = CTX::instance()->mesh.algoRecombine;
    int algoSubdivide = CTX::instance()->mesh.algoSubdivide;
    int algo = CTX::instance()->mesh.algo2d;
    int algo3d = CTX::instance()->mesh.algo3d;
    ~savedParameters()
    {
      CTX::instance()->mesh.minCurveNodes = minCurveNodes;
      CTX::instance()->mesh.minCircleNodes = minCircleNodes;
      CTX::instance()->mesh.recombineAll = recombineAll;
      CTX::instance()->mesh.algoRecombine = algoRecombine;
      CTX::instance()->mesh.algoSubdivide = algoSubdivide;
      CTX::instance()->mesh.algo2d = algo;
      CTX::instance()->mesh.algo3d = algo3d;
    }
  } saved;
  CTX::instance()->mesh.minCurveNodes = std::min(saved.minCurveNodes, 5);
  CTX::instance()->mesh.minCircleNodes = std::min(saved.minCircleNodes, 30);
  CTX::instance()->mesh.recombineAll = 0;
  CTX::instance()->mesh.algoRecombine = 0;
  // the size map is read from this triangulation's edges: it must not be
  // subdivided
  CTX::instance()->mesh.algoSubdivide = 0;
  CTX::instance()->mesh.algo2d = ALGO_2D_FRONTAL;
  //    ALGO_2D_MESHADAPT; /* slow but frontal does not always work */
  // the surface directions of the hex-dominant 3D algorithm are those of
  // the final surface mesh: not computed on this one
  if(saved.algo3d == ALGO_3D_RTREE)
    CTX::instance()->mesh.algo3d = ALGO_3D_DELAUNAY;

  /* Generate the triangulation with standard gmsh pipeline, as part of the
   * meshing that called this, which holds the lock on the model */
  GenerateMesh(gm, 2, true);

  return true;
}

bool getGFaceBackgroundMeshLinesAndTriangles(
  GlobalBackgroundMesh &bmesh, GFace *gf, std::vector<MLine *> &lines,
  std::vector<MTriangle *> &triangles)
{
  lines.clear();
  triangles.clear();

  /* Collect pointers to background mesh elements */
  std::vector<GEdge *> edges = face_edges(gf);
  for(GEdge *ge : edges) {
    auto it = bmesh.edgeBackgroundMeshes.find(ge);
    if(it == bmesh.edgeBackgroundMeshes.end()) {
      Msg::Warning(
        "getGFaceBackgroundMeshLinesAndTriangles: GEdge %i not found "
        "in background mesh",
        ge->tag());
      continue;
    }
    lines.reserve(lines.size() + it->second.lines.size());
    for(size_t i = 0; i < it->second.lines.size(); ++i) {
      lines.push_back(&(it->second.lines[i]));
    }
  }
  auto it = bmesh.faceBackgroundMeshes.find(gf);
  if(it == bmesh.faceBackgroundMeshes.end()) {
    Msg::Warning("getGFaceBackgroundMeshLinesAndTriangles: GFace %i not found "
                 "in background mesh",
                 gf->tag());
    return false;
  }
  triangles.reserve(triangles.size() + it->second.triangles.size());
  for(size_t i = 0; i < it->second.triangles.size(); ++i) {
    triangles.push_back(&(it->second.triangles[i]));
  }

  sort_unique(lines,
              [](MLine *a, MLine *b) { return a->getNum() < b->getNum(); });
  sort_unique(triangles, [](MTriangle *a, MTriangle *b) {
    return a->getNum() < b->getNum();
  });

  return true;
}

int BuildBackgroundMeshAndGuidingField(GModel *gm, bool overwriteGModelMesh,
                                       bool deleteGModelMeshAfter,
                                       bool overwriteField, int N)
{
  if(CTX::instance()->abortOnError && Msg::GetErrorCount()) return 0;
  if(CTX::instance()->mesh.algo2d != ALGO_2D_PACK_PRLGRMS) return 0;
  if(N != 4 && N != 6) {
    Msg::Error("guiding field: %i-symmetry field not supported", N);
    return -1;
  }

  const int sizemapMethod = CTX::instance()->mesh.packSizemapMethod;
  if(sizemapMethod == 5) {
    Msg::Warning("PACK: no background mesh");
    return 0;
  }

  bool midpointSubdivisionAfter = true;
  if(CTX::instance()->mesh.algoRecombine == 1 ||
     CTX::instance()->mesh.algoRecombine == 2 ||
     CTX::instance()->mesh.algoRecombine == 4) {
    midpointSubdivisionAfter = false;
  }

  const bool SHOW_INTERMEDIATE_VIEWS = (Msg::GetVerbosity() >= 99);

  Msg::Info("Build background mesh and guiding field ...");
  bool externalSizemap = false;
  {
    FieldManager *fields = gm->getFields();
    if(fields->getDirectionField()) {
      if(!overwriteField) {
        Msg::Info("guiding field exists, using it");
        return 0;
      }
      Msg::Info("building a new guiding field");
      // the previous one must not size the new triangulation (it clamps
      // curve and surface sizes); a vector field set by the user as
      // background field is replaced
      if(fields->getGuidingField() > 0)
        fields->clearGuidingField();
      else
        fields->setBackgroundFieldId(0);
    }
    Field *field = fields->getBackgroundField() > 0 ?
                     fields->get(fields->getBackgroundField()) :
                     nullptr;
    if(field && field->numComponents() == 1) {
      // Some scalar fields (e.g. AutomaticMeshSizeField) lazily build
      // themselves from the GModel's current surface mesh on first query.
      // That mesh gets deleted below (overwriteGModelMesh or
      // deleteGModelMeshAfter) while the field stays the background field
      // queried by all later meshing steps, so build it now.
      field->update();
      if(sizemapMethod == SizeMapDefault) {
        Msg::Info("scalar background field exists, using it as size map");
        externalSizemap = true;
      }
      else {
        Msg::Info("scalar background field exists, used through the "
                  "background triangulation (Mesh.PackSizemapMethod is %i)",
                  sizemapMethod);
      }
    }
  }

  if(overwriteGModelMesh) {
    Msg::Debug("delete current GModel mesh");
    gm->deleteMesh();
  }

  /* Check if triangulation available */
  bool surfaceMeshed = true;
  {
    bool onlyVisible = CTX::instance()->mesh.meshOnlyVisible;
    for(GFace *gf : gm->getFaces())
      if(gf->getNumMeshElements() == 0) {
        if(onlyVisible && !gf->getVisibility()) continue;
        surfaceMeshed = false;
      }
  }

  if(!surfaceMeshed) {
    const double w = TimeOfDay(), c = Cpu();
    generateBackgroundTriangulation(gm);
    AddMeshStageTime("background mesh", TimeOfDay() - w, Cpu() - c);
  }

  GlobalBackgroundMesh &bmesh = getBackgroundMesh(BMESH_NAME);
  bool overwrite = true;
  int status = bmesh.importGModelMeshes(gm, overwrite);
  if(status != 0) {
    Msg::Error("failed to import model mesh in background mesh");
    return -1;
  }

  if(deleteGModelMeshAfter) {
    Msg::Debug("delete GModel mesh");
    gm->deleteMesh();
  }

  /* Build guiding field on background mesh:
   * - per GFace:
   *   - cross field (unit vectors, one value per edge)
   *   - conformal scaling (scalar, one value per vertex)
   *   - offset conformal scaling by target number of quads
   *   -> one vector (scaled direction) per triangle corner
   * - global:
   *   - compute/extract size map
   *   - apply size map to triangle vectors (take minimum)
   *   - one-way smoothing with Dijkstra + gradient max
   */
  std::vector<MTriangle *> global_triangles;
  std::vector<std::array<double, 9>> global_triangle_directions;
  std::vector<std::pair<MVertex *, double>> global_size_map;
  std::vector<std::array<double, 5>>
    global_singularity_list; /* format: gf->tag(), index, x, y, z */
  int failedCrossFields = 0;
  /* Per GFace computations, in parallel */
  {
    Msg::Debug("- PACK sizemap method: %s (%i), expect midpoint subdivision: %i",
               nameOfSizeMapMethod(sizemapMethod).c_str(), sizemapMethod,
               midpointSubdivisionAfter);

    std::vector<GFace *> faces = model_faces(gm);
    size_t ntris = 0;
    std::set<GFace *> compnds;
    for(size_t f = 0; f < faces.size(); ++f) {
      GFace *gf = faces[f];
      if(gf->compoundSurface) compnds.insert(gf->compoundSurface);
      auto it = bmesh.faceBackgroundMeshes.find(gf);
      if(it != bmesh.faceBackgroundMeshes.end()) {
        ntris += it->second.triangles.size();
      }
    }
    global_triangles.reserve(ntris);
    global_size_map.reserve(3 * ntris);

    int nthreads = crossFieldHeatSolverUsesMumps() ? 1 : getNumThreads();
    const double tCrossFields = TimeOfDay(), cCrossFields = Cpu();
    int nbCrossFields = 0;
    std::size_t nbCrossFieldTriangles = 0;
#pragma omp parallel for schedule(dynamic) num_threads(nthreads) reduction(+ : failedCrossFields, nbCrossFields, nbCrossFieldTriangles)
    for(size_t f = 0; f < faces.size(); ++f) {
      GFace *gf = faces[f];

      if(CTX::instance()->mesh.meshOnlyVisible && !gf->getVisibility())
        continue;
      if(CTX::instance()->debugSurface > 0 &&
         gf->tag() != CTX::instance()->debugSurface)
        continue;
      if(compnds.find(gf) != compnds.end()) continue;
      /* Compute a cross field on each face */

      /* Get mesh elements for solver */
      std::vector<MLine *> lines;
      std::vector<MTriangle *> triangles;
      bool oklt =
        getGFaceBackgroundMeshLinesAndTriangles(bmesh, gf, lines, triangles);
      if(!oklt && triangles.size() == 0) {
        Msg::Error("- Face %i: failed to get triangles from background mesh",
                   gf->tag());
        continue;
      }

      /* Cross field */
      std::vector<std::array<double, 3>> triEdgeTheta;
      int nbDiffusionLevels = 4;
      double thresholdNormConvergence = 1.e-2;
      int nbBoundaryExtensionLayer = 1;
      int verbosity = 0;
      Msg::Debug("- Face %i/%li: compute cross field (%li triangles, %li B.C. "
                 "edges, %i diffusion levels) ...",
                 gf->tag(), faces.size(), triangles.size(), lines.size(),
                 nbDiffusionLevels);
      nbCrossFields++;
      nbCrossFieldTriangles += triangles.size();
      int scf = computeCrossFieldWithHeatEquation(
        N, triangles, lines, triEdgeTheta, nbDiffusionLevels,
        thresholdNormConvergence, nbBoundaryExtensionLayer, verbosity);
      if(scf != 0) {
        Msg::Warning("- Face %i: failed to compute cross field", gf->tag());
        ++failedCrossFields;
        continue;
      }

      /* Cross field singularities */
      bool addSingularitiesAtAcuteCorners = true;
      double thresholdInDeg = 30.;
      std::vector<std::pair<SPoint3, int>> singularities;
      int scsi = detectCrossFieldSingularities(N, triangles, triEdgeTheta,
                                               addSingularitiesAtAcuteCorners,
                                               thresholdInDeg, singularities);
      if(scsi != 0) {
        Msg::Warning("- Face %i: failed to compute cross field singularities",
                     gf->tag());
      }
      std::vector<std::array<double, 5>> singularity_list(singularities.size());
      for(size_t k = 0; k < singularities.size(); ++k) {
        singularity_list[k] = {
          double(gf->tag()), double(singularities[k].second),
          singularities[k].first.x(), singularities[k].first.y(),
          singularities[k].first.z()};
      }

      if(SHOW_INTERMEDIATE_VIEWS) {
        for(auto &kv : singularities) {
          GeoLog::add(kv.first, double(kv.second), "singularities");
        }
      }

      std::vector<std::array<double, 9>> triangleDirections;
      int sc = convertToPerTriangleCrossFieldDirections(
        N, triangles, triEdgeTheta, triangleDirections);
      if(sc != 0) {
        Msg::Warning(
          "- Face %i: failed to resample cross field at triangle corners",
          gf->tag());
      }

      /* Build the size map of the guiding field */
      std::unordered_map<MVertex *, double> localSizemap;
      if(externalSizemap) { /* Size map from background field */
        int sts =
          fillSizemapFromScalarBackgroundField(gm, triangles, localSizemap);
        if(sts != 0) {
          Msg::Warning(
            "- Face %i: failed to fill size map from scalar background field",
            gf->tag());
        }
      }
      else if(sizemapMethod ==
              SizeMapBackgroundMesh) { /* Size map from background triangulation
                                        */
        int sts = fillSizemapFromTriangleSizes(triangles, localSizemap);
        if(sts != 0) {
          Msg::Warning("- Face %i: failed to fill size map from triangle sizes",
                       gf->tag());
        }
        else if(midpointSubdivisionAfter) {
          for(auto &kv : localSizemap) kv.second *= 2;
        }
      }
      else {
        /* Conformal scaling associated to cross field */
        Msg::Info("- Face %i/%li: compute cross field conformal scaling ...",
                  gf->tag(), faces.size());
        int scs = computeCrossFieldConformalScaling(N, triangles, triEdgeTheta,
                                                    localSizemap);
        if(scs != 0) {
          Msg::Warning(
            "- Face %i: failed to compute conformal scaling, use uniform size",
            gf->tag());
          for(MTriangle *t : triangles)
            for(size_t lv = 0; lv < 3; ++lv) {
              localSizemap[t->getVertex(lv)] = 1.;
            }
        }

        /* Quantile filtering on the conformal scaling histogram */
        Msg::Debug("- Face %i/%li: conformal scaling quantile filtering ...",
                   gf->tag(), faces.size());
        double filteringRange = 0.05;
        quantileFiltering(localSizemap, filteringRange);

        size_t targetNumberOfQuads = gf->triangles.size() / 2.;
        if(targetNumberOfQuads == 0) { /* Check in background mesh */
          auto it = bmesh.faceBackgroundMeshes.find(gf);
          if(it == bmesh.faceBackgroundMeshes.end()) {
            Msg::Error("- Face %i: background mesh not found", gf->tag());
            targetNumberOfQuads = 1000;
          }
          else {
            targetNumberOfQuads = 0.5 * it->second.triangles.size();
          }
        }

        /* Midpoint subdivision => 4 times more quads */
        if(midpointSubdivisionAfter) { targetNumberOfQuads /= 4; }

        if(targetNumberOfQuads == 0) targetNumberOfQuads = 1;

        int scso = computeQuadSizeMapFromCrossFieldConformalFactor(
          triangles, targetNumberOfQuads, localSizemap);
        if(scso != 0) {
          Msg::Warning(
            "- Face %i: failed to compute size map from conformal scaling",
            gf->tag());
        }
      }

#pragma omp critical(BuildBackgroundMeshAndGuidingField)
      {
        append(global_triangles, triangles);
        append(global_triangle_directions, triangleDirections);
        append(global_singularity_list, singularity_list);
        for(auto &kv : localSizemap) {
          global_size_map.push_back({kv.first, kv.second});
        }
        // GeoLog::add(dynamic_cast_vector<MTriangle*,MElement*>(triangles),
        //    localSizemap, "sizemap_f"+std::to_string(gf->tag()));
      }
    }
    Msg::Info("Cross field on %d surface%s (%zu triangles, %zu singularities, "
              "Wall %gs)",
              nbCrossFields, nbCrossFields == 1 ? "" : "s",
              nbCrossFieldTriangles, global_singularity_list.size(),
              TimeOfDay() - tCrossFields);
    AddMeshStageTime("cross field", TimeOfDay() - tCrossFields,
                     Cpu() - cCrossFields);
  }

  if(failedCrossFields) {
    Msg::Error("Could not compute cross field on %i surface(s); "
               "guiding field not built", failedCrossFields);
    return -1;
  }

  sort_unique(global_size_map);

  /* Warning: from now on, code is not optimized in terms of data structures
   *          (slow unordered_map instead of contiguous vectors, etc)
   *          should be improved if this step is time-consuming in the
   *          global pipeline. */

  if(SHOW_INTERMEDIATE_VIEWS) {
    showCrossFieldInView(global_triangles, global_triangle_directions,
                         "cross_field");
  }

  /* Global operations */

  /* Compute minimum / maximum of "natural" size map.
   * Use this to avoid cases when minimal size on curves
   * tends to 0 */
  double smMin = DBL_MAX;
  for(auto &kv : global_size_map) { smMin = std::min(smMin, kv.second); }
  double factor = 0.1; /* size map can be reduced up to factor */
  double minSizeClampMin = factor * smMin;

  /* Minimal size on curves */
  std::unordered_map<MVertex *, double> cadMinimalSizeOnCurves;
  if(!externalSizemap) {
    if(sizemapMethod == SizeMapDefault ||
       sizemapMethod == SizeMapCrossFieldAndBMeshOnCurves ||
       sizemapMethod == SizeMapCrossFieldAndSmallCad) {
      bool clampMinWithTriEdges = false;
      if(sizemapMethod == SizeMapDefault ||
         sizemapMethod == SizeMapCrossFieldAndBMeshOnCurves) {
        clampMinWithTriEdges = true;
      }

      int scad = computeMinimalSizeOnCurves(bmesh, clampMinWithTriEdges,
                                            cadMinimalSizeOnCurves);
      if(scad != 0) {
        Msg::Warning("failed to compute minimal size on CAD curves");
      }
    }
  }

  /* Initialize global size map defined on the background mesh */
  std::unordered_map<MVertex *, double> sizeMap = cadMinimalSizeOnCurves;
  for(auto &kv : global_size_map) {
    MVertex *v = kv.first;
    auto it = sizeMap.find(v);
    if(it == sizeMap.end()) {
      sizeMap[kv.first] = kv.second; /* "natural" size */
    }
    else {
      double sizeFromAdaptation = std::max(it->second, minSizeClampMin);
      it->second = std::min(sizeFromAdaptation, kv.second);
    }
  }

  /* One-way propagation of values */
  if(sizemapMethod != SizeMapBackgroundMesh) {
    const double gradientMax =
      1.2; /* this param should be a global gmsh option */
    Msg::Info("Sizemap smoothing (progression ratio: %.2f)", gradientMax);
    int sop = sizeMapOneWaySmoothing(global_triangles, sizeMap, gradientMax);
    if(sop != 0) {
      Msg::Warning("failed to compute one-way size map smoothing");
    }
  }

  /* Clamp with global minimum/maximum mesh size */
  {
    // TODO: should be multiplied by lcFactor or not ?
    double fs = midpointSubdivisionAfter ? 2. : 1.;
    double sizeMin =
      CTX::instance()->mesh.lcMin * CTX::instance()->mesh.lcFactor;
    double sizeMax =
      fs * CTX::instance()->mesh.lcMax * CTX::instance()->mesh.lcFactor;
    for(auto &kv : sizeMap) {
      if(kv.second < sizeMin) { kv.second = sizeMin; }
      else if(kv.second > sizeMax) {
        kv.second = sizeMax;
      }
    }
  }

  if(SHOW_INTERMEDIATE_VIEWS) {
    std::vector<MElement *> elements =
      dynamic_cast_vector<MTriangle *, MElement *>(global_triangles);
    GeoLog::add(elements, sizeMap, "size_map");
    GeoLog::flush();
    // showUVParametrization(bmesh);
    std::unordered_map<MVertex *, double> sizemap_init;
    for(auto &kv : global_size_map) {
      MVertex *v = kv.first;
      auto it = sizemap_init.find(v);
      if(it == sizemap_init.end()) {
        sizemap_init[kv.first] = kv.second; /* "natural" size */
      }
      else {
        it->second = std::min(it->second, kv.second);
      }
    }
    GeoLog::add(elements, sizemap_init, "size_map_init");
    GeoLog::flush();
  }

  printSizeMapStats(global_triangles, sizeMap);

  /* Build the background field */
  int sbf =
    buildBackgroundField(gm, global_triangles, global_triangle_directions,
                         sizeMap, global_singularity_list, "guiding_field");
  if(sbf != 0) {
    Msg::Warning("failed to build background guiding field");
    return -1;
  }

  return 0;
}

bool backgroundMeshAndGuidingFieldExists(GModel *gm)
{
  bool bgmOk = backgroudMeshExists(BMESH_NAME);
  bool bfOk = false;
  FieldManager *fields = gm->getFields();
  if(fields->getDirectionField()) bfOk = true;
  return bgmOk && bfOk;
}

bool meshOrientationIsOppositeOfCadOrientation(GFace *gf)
{
  size_t nOk = 0;
  size_t nInv = 0;
  for(std::size_t iEl = 0; iEl < gf->getNumMeshElements(); iEl++) {
    MElement *e = gf->getMeshElement(iEl);
    SVector3 ne = e->getFace(0).normal();
    MVertex *v = e->getVertex(0);
    SPoint2 param;
    if(v->onWhat() == gf && v->getParameter(0, param[0]) &&
       v->getParameter(1, param[1])) {
      SVector3 nf = gf->normal(param);
      if(dot(nf, ne) < 0.) { nInv += 1; }
      else {
        nOk += 1;
      }
    }
  }
  return (nInv > nOk);
}

int quadMeshingOfSimpleFacesWithPatterns(GModel *gm,
                                         double minimumQualityRequired)
{

  std::vector<GFace *> faces = model_faces(gm);
  Msg::Info("Pattern-based quad meshing of simple CAD faces ...", faces.size());

  initQuadPatterns();

  //  int nthreads = getNumThreads();
  //#pragma omp parallel for schedule(dynamic) num_threads(nthreads)
  for(auto gf : faces) {
    //    if(gf->meshStatistics.status != GFace::PENDING) continue;
    if(CTX::instance()->mesh.meshOnlyVisible && !gf->getVisibility()) continue;
    if(CTX::instance()->debugSurface > 0 &&
       gf->tag() != CTX::instance()->debugSurface)
      continue;
    if(gf->embeddedEdges().size() > 0 || gf->embeddedVertices().size() > 0)
      continue;
    bool invertNormals = meshOrientationIsOppositeOfCadOrientation(gf);
    meshFaceWithGlobalPattern(gf, invertNormals, minimumQualityRequired);
  }
  return 0;
}

#else
/* else: without QUADMESHINGTOOLS module*/

int BuildBackgroundMeshAndGuidingField(GModel *gm, bool overwriteGModelMesh,
                                       bool deleteGModelMeshAfter,
                                       bool overwriteField, int N)
{
  Msg::Error("Module QUADMESHINGTOOLS required for function "
             "BuildBackgroundMeshAndGuidingField");
  return -10;
}
bool backgroundMeshAndGuidingFieldExists(GModel *gm)
{
  return false;
}
int quadMeshingOfSimpleFacesWithPatterns(GModel *gm,
                                         double minimumQualityRequired)
{
  Msg::Error("Module QUADMESHINGTOOLS required for function "
             "quadMeshingOfSimpleFacesWithPatterns");
  return -10;
}
#endif
/* endif: QUADMESHINGTOOLS*/

int transferSeamGEdgesVerticesToGFace(GModel *gm)
{
  for(GFace *gf : gm->getFaces()) {
    /* Transfer the vertices from seam GEdge to associated GFace */
    std::unordered_map<MVertex *, MVertex *> old2new;
    for(GEdge *ge : gf->edges()) {
      if(ge->isSeam(gf) && ge->faces().size() == 1 && ge->faces()[0] == gf) {
        /* GEdge interior vertices */
        for(MVertex *ov : ge->mesh_vertices) {
          auto it = old2new.find(ov);
          if(it != old2new.end()) continue; /* already changed */
          SPoint3 p = ov->point();
          double t;
          ov->getParameter(0, t);
          SPoint2 uv = ge->reparamOnFace(gf, t, -1);
          MVertex *nv = new MFaceVertex(p.x(), p.y(), p.z(), gf, uv[0], uv[1]);
          nv->setParameter(0, uv[0]);
          nv->setParameter(1, uv[1]);
          gf->mesh_vertices.push_back(nv);
          old2new[ov] = nv;
          delete ov;
        }
        ge->mesh_vertices.clear();
        for(size_t i = 0; i < ge->lines.size(); ++i) { delete ge->lines[i]; }
        ge->lines.clear();

        /* GEdge boundary vertices */
        for(GVertex *gv : ge->vertices())
          if(gv->mesh_vertices.size() == 1) {
            std::vector<GEdge *> otherCurves;
            for(GEdge *ge2 : gv->edges())
              if(ge2 != ge) {
                if(ge2->vertices().front() == ge2->vertices().back() &&
                   ge2->length() <
                     CTX::instance()->geom.tolerance) { /* Empty curve */
                  continue;
                }
                otherCurves.push_back(ge2);
              }
            std::sort(otherCurves.begin(), otherCurves.end());
            otherCurves.erase(
              std::unique(otherCurves.begin(), otherCurves.end()),
              otherCurves.end());

            if(otherCurves.size() > 0) continue;
            MVertex *ov = gv->mesh_vertices[0];
            auto it = old2new.find(ov);
            if(it != old2new.end()) continue; /* already changed */
            Msg::Debug(
              "transfer: mesh vertex at CAD corner %i moved to face %i",
              gv->tag(), gf->tag());
            SPoint3 p = ov->point();
            SPoint2 uv = gv->reparamOnFace(gf, 0);
            MVertex *nv =
              new MFaceVertex(p.x(), p.y(), p.z(), gf, uv[0], uv[1]);
            nv->setParameter(0, uv[0]);
            nv->setParameter(1, uv[1]);
            gf->mesh_vertices.push_back(nv);
            old2new[ov] = nv;

            /* Note/warning: let the MVertex on the GVertex live. If the MVertex
             * is deleted, I/O is broken.
             * FIXME: support for GVertex without MVertex in mesh I/O */
            // delete ov;
            // gv->mesh_vertices.clear();
          }
      }
    }
    if(old2new.size() > 0) {
      for(MElement *f : gf->triangles)
        for(size_t lv = 0; lv < 3; ++lv) {
          MVertex *v = f->getVertex(lv);
          auto it = old2new.find(v);
          if(it != old2new.end()) { f->setVertex(lv, it->second); }
        }
      for(MElement *f : gf->quadrangles)
        for(size_t lv = 0; lv < 4; ++lv) {
          MVertex *v = f->getVertex(lv);
          auto it = old2new.find(v);
          if(it != old2new.end()) { f->setVertex(lv, it->second); }
        }
    }
  }
  return 0;
}
