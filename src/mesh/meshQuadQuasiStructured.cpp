// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

#include "meshQuadQuasiStructured.h"

#include <array>
#include <queue>

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
#include "gmsh.h"
#include "meshRefine.h"
#include "meshOctreeLibOL.h"
#include "robin_hood.h"

#if defined(HAVE_POST)
#include "PView.h"
#include "PViewData.h"
#include "PViewDataList.h"
#include "PViewDataGModel.h"
#include "PViewOptions.h"
#endif
#if defined(HAVE_FLTK)
#include "FlGui.h"
#endif

#if defined(HAVE_QUADMESHINGTOOLS)
#include "cppUtils.h"
#include "qmtMeshUtils.h"
#include "qmtCrossField.h"
#include "qmtSizeMap.h"
#include "qmtCurveQuantization.h"
#include "qmtDiskQuadrangulationRemeshing.h"
#include "qmtQuadCavityRemeshing.h"
#include "qmtMeshGeometryOptimization.h"
#include "arrayGeometry.h"
#include "geolog.h"

using namespace CppUtils;
using namespace ArrayGeometry;

template <typename Key, typename T, typename Hash = robin_hood::hash<Key>,
          typename KeyEqual = std::equal_to<Key>, size_t MaxLoadFactor100 = 80>
using unordered_map =
  robin_hood::detail::Table<true, MaxLoadFactor100, Key, T, Hash, KeyEqual>;

template <typename Key, typename Hash = robin_hood::hash<Key>,
          typename KeyEqual = std::equal_to<Key>, size_t MaxLoadFactor100 = 80>
using unordered_set =
  robin_hood::detail::Table<true, MaxLoadFactor100, Key, void, Hash, KeyEqual>;

constexpr int SizeMapDefault = 0;
constexpr int SizeMapCrossFieldAndSmallCad = 2;
constexpr int SizeMapBackgroundMesh = 3;
constexpr int SizeMapCrossFieldAndBMeshOnCurves = 4;

const std::string BMESH_NAME = "bmesh_quadqs";

constexpr bool PARANO_QUALITY = false;
constexpr bool PARANO_VALIDITY = false;
constexpr bool DBG_EXPORT = false;
constexpr bool SHOW_DQR = false;

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
  const std::vector<std::array<double, 9> > &global_triangle_directions,
  const std::unordered_map<MVertex *, double> &global_size_map,
  const std::vector<std::array<double, 5> > &global_singularity_list,
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

#if defined(HAVE_FLTK)
  view->getOptions()->visible = 0;
  if(FlGui::available()) FlGui::instance()->updateViews(true, true);
#endif

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

  gm->getFields()->setBackgroundMesh(view->getIndex());

  const bool exportBGM = false;
  if(exportBGM || Msg::GetVerbosity() >= 99) {
    std::string name = gm->getName() + "_bgm.pos";
    Msg::Warning("Exporting background field to '%s'", name.c_str());
    view->write(name, 0);
  }

  return 0;
#else
  Msg::Error("Post-processing module required to create background field view");
  return -1;
#endif
}

void showCrossFieldInView(
  const std::vector<MTriangle *> &global_triangles,
  const std::vector<std::array<double, 9> > &global_triangle_directions,
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
  std::vector<std::vector<double> > values_u;
  std::vector<std::vector<double> > values_v;
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
  std::unordered_map<MVertex *, std::vector<MVertex *> > v2v;
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
        double value = (*field)(v->point().x(), v->point().y(), v->point().z());
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

bool generateMeshWithSpecialParameters(GModel *gm,
                                       double scalingOnTriangulation)
{
  Msg::Debug("build background triangulation ...");

  /* Unlock if called from GenerateMesh() */
  bool shouldLock = false;
  if(CTX::instance()->lock) {
    CTX::instance()->lock = 0;
    shouldLock = true;
  }

  /* Change meshing parameters to build a good triangulation
   * for cross field */
  /* - the triangulation must be a bit more refined than the quad mesh */
  int minCurveNodes = CTX::instance()->mesh.minCurveNodes;
  int minCircleNodes = CTX::instance()->mesh.minCircleNodes;
  double lcFactor = CTX::instance()->mesh.lcFactor;
  int recombineAll = CTX::instance()->mesh.recombineAll;
  int algoRecombine = CTX::instance()->mesh.algoRecombine;
  int algo = CTX::instance()->mesh.algo2d;
  CTX::instance()->mesh.minCurveNodes = std::min(minCurveNodes, 5);
  CTX::instance()->mesh.minCircleNodes = std::min(minCircleNodes, 30);
  CTX::instance()->mesh.lcFactor = lcFactor * scalingOnTriangulation;
  CTX::instance()->mesh.recombineAll = 0;
  CTX::instance()->mesh.algoRecombine = 0;
  CTX::instance()->mesh.algo2d = ALGO_2D_FRONTAL;
  //    ALGO_2D_MESHADAPT; /* slow but frontal does not always work */

  /* Generate the triangulation with standard gmsh pipeline */
  GenerateMesh(gm, 2);

  /* Restore parameters */
  CTX::instance()->mesh.minCurveNodes = minCurveNodes;
  CTX::instance()->mesh.minCircleNodes = minCircleNodes;
  CTX::instance()->mesh.lcFactor = lcFactor;
  CTX::instance()->mesh.recombineAll = recombineAll;
  CTX::instance()->mesh.algoRecombine = algoRecombine;
  CTX::instance()->mesh.algo2d = algo;

  /* Lock again before going back to GenerateMesh() */
  if(shouldLock) CTX::instance()->lock = 1;

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

  return true;
}

int BuildBackgroundMeshAndGuidingField(GModel *gm, bool overwriteGModelMesh,
                                       bool deleteGModelMeshAfter,
                                       bool overwriteField, int N)
{
  if(CTX::instance()->abortOnError && Msg::GetErrorCount()) return 0;
  if(CTX::instance()->mesh.algo2d != ALGO_2D_PACK_PRLGRMS &&
     CTX::instance()->mesh.algo2d != ALGO_2D_QUAD_QUASI_STRUCT)
    return 0;
  if(N != 4 && N != 6) {
    Msg::Error("guiding field: %i-symmetry field not supported", N);
    return -1;
  }

  const int qqsSizemapMethod = CTX::instance()->mesh.quadqsSizemapMethod;
  if(qqsSizemapMethod == 5) {
    Msg::Warning("Quadqs method: no background mesh");
    return 0;
  }

  bool midpointSubdivisionAfter = true;
  if(!CTX::instance()->mesh.recombineAll ||
     CTX::instance()->mesh.algoRecombine == 4) {
    midpointSubdivisionAfter = false;
  }

  const bool SHOW_INTERMEDIATE_VIEWS = (Msg::GetVerbosity() >= 99);

  Msg::Info("Build background mesh and guiding field ...");
  bool externalSizemap = false;
  {
    FieldManager *fields = gm->getFields();
    if(fields->getBackgroundField() > 0) {
      Field *field = fields->get(fields->getBackgroundField());
      if(field && field->numComponents() == 3) {
        if(!overwriteField) {
          Msg::Info(
            "vector background field exists, using it as a guiding field");
          return 0;
        }
        else {
          Msg::Info(
            "disabled current vector background field, building a new one");
          fields->setBackgroundFieldId(0);
        }
      }
      else if(field && field->numComponents() == 1) {
        if(qqsSizemapMethod == SizeMapDefault) {
          Msg::Info("scalar background field exists, using it as size map");
          externalSizemap = true;
        }
        else {
          Msg::Warning("scalar background field exists, but ignored because "
                       "QuadqsSizemapMethod is %i",
                       CTX::instance()->mesh.quadqsSizemapMethod);
        }
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

  /* Generate triangulation */
  /* - scalingOnTriangulation: this factor is used to get a triangulation a bit
   * more finer than the target quadrangulation, to get a more accurate cross
   * field */
  double edgeScaling = CTX::instance()->mesh.quadqsScalingOnTriangulation;
  if(!surfaceMeshed) { generateMeshWithSpecialParameters(gm, edgeScaling); }

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
  std::vector<std::array<double, 9> > global_triangle_directions;
  std::vector<std::pair<MVertex *, double> > global_size_map;
  std::vector<std::array<double, 5> >
    global_singularity_list; /* format: gf->tag(), index, x, y, z */
  /* Per GFace computations, in parallel */
  {
    Msg::Info(
      "- quadqs sizemap method: %s (%i), expect midpoint subdivision: %i, "
      "scaling on edge length: %f",
      nameOfSizeMapMethod(CTX::instance()->mesh.quadqsSizemapMethod).c_str(),
      CTX::instance()->mesh.quadqsSizemapMethod, midpointSubdivisionAfter,
      edgeScaling);

    std::vector<GFace *> faces = model_faces(gm);
    size_t ntris = 0;
    for(size_t f = 0; f < faces.size(); ++f) {
      GFace *gf = faces[f];
      auto it = bmesh.faceBackgroundMeshes.find(gf);
      if(it != bmesh.faceBackgroundMeshes.end()) {
        ntris += it->second.triangles.size();
      }
    }
    global_triangles.reserve(ntris);
    global_size_map.reserve(3 * ntris);

    int nthreads = getNumThreads();
#pragma omp parallel for schedule(dynamic) num_threads(nthreads)
    for(size_t f = 0; f < faces.size(); ++f) {
      GFace *gf = faces[f];

      if(CTX::instance()->mesh.meshOnlyVisible && !gf->getVisibility())
        continue;
      if(CTX::instance()->debugSurface > 0 &&
         gf->tag() != CTX::instance()->debugSurface)
        continue;

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
      std::vector<std::array<double, 3> > triEdgeTheta;
      int nbDiffusionLevels = 4;
      double thresholdNormConvergence = 1.e-2;
      int nbBoundaryExtensionLayer = 1;
      int verbosity = 0;
      Msg::Info("- Face %i/%li: compute cross field (%li triangles, %li B.C. "
                "edges, %i diffusion levels) ...",
                gf->tag(), faces.size(), triangles.size(), lines.size(),
                nbDiffusionLevels);
      int scf = computeCrossFieldWithHeatEquation(
        N, triangles, lines, triEdgeTheta, nbDiffusionLevels,
        thresholdNormConvergence, nbBoundaryExtensionLayer, verbosity);
      if(scf != 0) {
        Msg::Warning("- Face %i: failed to compute cross field", gf->tag());
      }

      /* Cross field singularities */
      bool addSingularitiesAtAcuteCorners = true;
      double thresholdInDeg = 30.;
      std::vector<std::pair<SPoint3, int> > singularities;
      int scsi = detectCrossFieldSingularities(N, triangles, triEdgeTheta,
                                               addSingularitiesAtAcuteCorners,
                                               thresholdInDeg, singularities);
      if(scsi != 0) {
        Msg::Warning("- Face %i: failed to compute cross field singularities",
                     gf->tag());
      }
      std::vector<std::array<double, 5> > singularity_list(
        singularities.size());
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

      std::vector<std::array<double, 9> > triangleDirections;
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
      else if(qqsSizemapMethod ==
              SizeMapBackgroundMesh) { /* Size map from background triangulation
                                        */
        int sts = fillSizemapFromTriangleSizes(triangles, localSizemap);
        if(sts != 0) {
          Msg::Warning("- Face %i: failed to fill size map from triangle sizes",
                       gf->tag());
        }
        else if(sts == 0 && edgeScaling > 0.) {
          /* re-adjust the target edge size as if the triangulation was
           * not finer for more accurate cross field */
          for(auto &kv : localSizemap) {
            kv.second /= edgeScaling;
            if(midpointSubdivisionAfter) { kv.second *= 2; }
          }
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
            targetNumberOfQuads *= std::pow(edgeScaling, 2);
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

#pragma omp critical
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
    if(qqsSizemapMethod == SizeMapDefault ||
       qqsSizemapMethod == SizeMapCrossFieldAndBMeshOnCurves ||
       qqsSizemapMethod == SizeMapCrossFieldAndSmallCad) {
      bool clampMinWithTriEdges = false;
      if(qqsSizemapMethod == SizeMapDefault ||
         qqsSizemapMethod == SizeMapCrossFieldAndBMeshOnCurves) {
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
  if(qqsSizemapMethod != SizeMapBackgroundMesh) {
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
  if(fields->getBackgroundField() > 0) {
    Field *guiding_field = fields->get(fields->getBackgroundField());
    if(guiding_field && guiding_field->numComponents() == 3) { bfOk = true; }
  }
  return bgmOk && bfOk;
}

bool getSingularitiesFromBackgroundField(
  GFace *gf, std::vector<std::pair<SPoint3, int> > &singularities)
{
  singularities.clear();

  Field *field = nullptr;
  FieldManager *fields = gf->model()->getFields();
  if(fields->getBackgroundField() > 0) {
    Field *guiding_field = fields->get(fields->getBackgroundField());
    if(guiding_field && guiding_field->numComponents() == 3) {
      field = guiding_field;
    }
  }
  if(field == nullptr) {
    Msg::Debug("get singularities: face %i, failed to get background field",
               gf->tag());
    return false;
  }

  int viewIndex = int(field->options["IView"]->numericalValue());
  PView *view = nullptr;
  if(viewIndex >= 0 && viewIndex < (int)PView::list.size()) {
    view = PView::list[viewIndex];
  }
  else {
    Msg::Error("failed to get view for index = %i", viewIndex);
    return false;
  }
  PViewDataList *d = dynamic_cast<PViewDataList *>(view->getData());
  if(d == nullptr) {
    Msg::Error("view type is wrong");
    return false;
  }

  size_t nVP = d->VP.size() / 6;
  for(size_t i = 0; i < nVP; ++i) {
    int gfTag = int(std::round(d->VP[6 * i + 3] / VIEW_INT_SCALING));
    if(gfTag != gf->tag()) continue;
    int index = int(std::round(d->VP[6 * i + 4] / VIEW_INT_SCALING));
    double x = d->VP[6 * i + 0];
    double y = d->VP[6 * i + 1];
    double z = d->VP[6 * i + 2];
    singularities.push_back(std::make_pair(SPoint3(x, y, z), index));
  }

  return true;
}

bool getSingularitiesFromNewCrossFieldComputation(
  GlobalBackgroundMesh &bmesh, GFace *gf,
  std::vector<std::pair<SPoint3, int> > &singularities)
{
  const int N = 4;

  std::vector<MLine *> lines;
  std::vector<MTriangle *> triangles;
  bool oklt =
    getGFaceBackgroundMeshLinesAndTriangles(bmesh, gf, lines, triangles);
  if(!oklt && triangles.size() == 0) {
    Msg::Error("- Face %i: failed to get triangles from background mesh",
               gf->tag());
    return false;
  }

  /* Cross field */
  std::vector<std::array<double, 3> > triEdgeTheta;
  int nbDiffusionLevels = 4;
  double thresholdNormConvergence = 1.e-2;
  int nbBoundaryExtensionLayer = 1;
  int verbosity = 0;
  Msg::Info("- Face %i: compute cross field (%li triangles, %li B.C. "
            "edges, %i diffusion levels) ...",
            gf->tag(), triangles.size(), lines.size(), nbDiffusionLevels);
  int scf = computeCrossFieldWithHeatEquation(
    N, triangles, lines, triEdgeTheta, nbDiffusionLevels,
    thresholdNormConvergence, nbBoundaryExtensionLayer, verbosity);
  if(scf != 0) {
    Msg::Warning("- Face %i: failed to compute cross field", gf->tag());
  }

  /* Cross field singularities */
  bool addSingularitiesAtAcuteCorners = true;
  double thresholdInDeg = 30.;
  int scsi = detectCrossFieldSingularities(N, triangles, triEdgeTheta,
                                           addSingularitiesAtAcuteCorners,
                                           thresholdInDeg, singularities);
  if(scsi != 0) {
    Msg::Warning("- Face %i: failed to compute cross field singularities",
                 gf->tag());
  }

  return true;
}

void computeBdrVertexIdealValence(const std::vector<MQuadrangle *> &quads,
                                  unordered_map<MVertex *, double> &qValIdeal)
{
  qValIdeal.clear();
  for(MQuadrangle *f : quads) {
    for(size_t lv = 0; lv < 4; ++lv) {
      MVertex *v = f->getVertex(lv);
      GFace *gf = dynamic_cast<GFace *>(v->onWhat());
      if(gf == nullptr) { /* On boundary */
        MVertex *vPrev = f->getVertex((4 + lv - 1) % 4);
        MVertex *vNext = f->getVertex((lv + 1) % 4);
        SVector3 pNext = vNext->point();
        SVector3 pPrev = vPrev->point();
        SVector3 pCurr = v->point();
        double agl = angleVectors(pNext - pCurr, pPrev - pCurr);
        qValIdeal[v] += agl * 2. / M_PI;
      }
    }
  }
}

inline int clamp(int val, int lower, int upper)
{
  return std::min(upper, std::max(val, lower));
}

size_t idealBoundaryValence(const MVertex *v, double ideal)
{
  if(v->onWhat() && v->onWhat()->dim() == 1) {
    /* Regular on curves */
    return 2;
  }
  if(ideal <= 1.25) { return 1; }
  else if(ideal <= 2.75) {
    return 2;
  }
  else if(ideal <= 3.5) {
    return 3;
  }
  return 4;
}

bool getBoundaryIdealAndAllowedValences(
  int fixingDim, /* 0 when fixing corners, 1 when fixing curves, 2 when fixing
                    surfaces */
  GFaceMeshPatch &patch,
  const unordered_map<MVertex *, std::vector<MElement *> > &adj,
  const unordered_map<MVertex *, double> &qValIdeal,
  std::vector<int> &bndIdealValence,
  std::vector<std::pair<int, int> > &bndAllowedValenceRange)
{
  if(fixingDim < 0 || fixingDim > 2) return false;
  size_t N = patch.bdrVertices.front().size();
  bndIdealValence.resize(N);
  bndAllowedValenceRange.resize(N);
  for(size_t i = 0; i < N; ++i) {
    MVertex *bv = patch.bdrVertices.front()[i];
    GVertex *gv = dynamic_cast<GVertex *>(bv->onWhat());
    GEdge *ge = dynamic_cast<GEdge *>(bv->onWhat());
    GFace *gf = dynamic_cast<GFace *>(bv->onWhat());
    int idealTot = 4;
    if(gf == nullptr) {
      auto it = qValIdeal.find(bv);
      if(it == qValIdeal.end()) {
        Msg::Error("getBoundaryIdealAndAllowedValences: bdr vertex %i not "
                   "found in qValIdeal",
                   bv->getNum());
        return false;
      }
      idealTot = idealBoundaryValence(it->first, it->second);
    }
    auto it = adj.find(bv);
    if(it == adj.end()) {
      Msg::Error(
        "getBoundaryIdealAndAllowedValences: bdr vertex not found in adj");
      return false;
    }
    std::vector<MElement *> exterior = difference(it->second, patch.elements);
    int valExterior = (int)exterior.size();
    int valInterior = (int)it->second.size() - exterior.size();
    int idealIn = idealTot - valExterior;
    if(idealIn <= 0) {
      idealIn = 1;
      // DBG(bv->getNum(), idealIn, idealTot, valExterior);
      // Msg::Error("getBoundaryIdealAndAllowedValences: ideal valence inside is
      // <= 0, weird"); return false;
    }
    bndIdealValence[i] = idealIn;
    if(exterior.size() == 0) { /* boundary vertex "inside" the cavity, probably
                                  the one to remesh */
      bndAllowedValenceRange[i] = {idealIn, idealIn};
    }
    else if(gv != nullptr) { /* Current bdr vertex is corner */
      bndAllowedValenceRange[i] = {idealIn, idealIn};
    }
    else if(ge != nullptr) { /* Current bdr vertex is on curve */
      if(fixingDim == 0) {
        /* When fixing corners, can degrade curves */
        // bndAllowedValenceRange[i] = {1, 2};

        // No: do not degrade curves
        bndAllowedValenceRange[i] = {idealIn, idealIn};
      }
      else {
        bndAllowedValenceRange[i] = {idealIn, idealIn};
      }
    }
    else if(gf != nullptr) {
      if(valExterior <= 0) {
        Msg::Error("getBoundaryIdealAndAllowedValences: surface bdr vertex but "
                   "exterior valence is: %i",
                   valExterior);
        return false;
      }
      if(fixingDim == 0 && idealTot >= 3 && it->second.size() == 4) {
        /* When fixing concave corner, do not degrade close regular interior
         * vertices */
        bndAllowedValenceRange[i] = {valInterior, valInterior};
      }
      else if(fixingDim == 0 ||
              fixingDim ==
                1) { /* When fixing corner/curve, can degrade surface */
        /* Allowed total range: [3,6], minimize if valExterior higher to this */
        int lower = 3 - valExterior;
        int upper = 6 - valExterior;
        lower = clamp(lower, 1, 5);
        upper = clamp(upper, 1, 5);
        bndAllowedValenceRange[i] = {lower, upper};
      }
      else {
        /* Allowed total range: [3,5], minimize if valExterior higher to this */
        int lower = 3 - valExterior;
        int upper = 5 - valExterior;
        lower = clamp(lower, 1, 4);
        upper = clamp(upper, 1, 4);
        bndAllowedValenceRange[i] = {lower, upper};
      }
    }
    else {
      Msg::Error("getBoundaryIdealAndAllowedValences: vertex on no CAD entity, "
                 "should not happen");
      return false;
    }

    // if (fixingDim == 2) {
    //   std::string name = "[" +
    //   std::to_string(bndAllowedValenceRange[i].first)
    //     + "," + std::to_string(int(bndAllowedValenceRange[i].second)) + "]";
    //   GeoLog::add({bv->point()},double(bndIdealValence[i]), name);
    // }
  }

  return true;
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

void updateAdjacencies(const GFaceMeshPatch &before,
                       const GFaceMeshPatch &after,
                       unordered_map<MVertex *, std::vector<MElement *> > &adj)
{
  /* Remove old vertices from adjacency keys */
  for(MVertex *v : before.intVertices) {
    auto it = adj.find(v);
    if(it != adj.end()) { adj.erase(it); }
  }
  /* Remove old elements from adjacency values */
  for(auto &loop : before.bdrVertices) {
    for(MVertex *bv : loop) {
      auto it = adj.find(bv);
      if(it != adj.end()) {
        it->second = difference(it->second, before.elements);
      }
    }
  }
  /* Add new keys and values */
  for(MElement *e : after.elements) {
    for(size_t lv = 0; lv < e->getNumVertices(); ++lv) {
      MVertex *v = e->getVertex(lv);
      adj[v].push_back(e);
    }
  }
}

std::vector<MElement *>
getNeighbors(const std::vector<MElement *> &elements,
             const unordered_map<MVertex *, std::vector<MElement *> > &adj)
{
  std::vector<MElement *> neighbors;
  for(MElement *e : elements) {
    for(size_t lv = 0; lv < e->getNumVertices(); ++lv) {
      MVertex *v = e->getVertex(lv);
      auto it = adj.find(v);
      if(it != adj.end()) {
        for(MElement *e2 : it->second) { neighbors.push_back(e2); }
      }
    }
  }
  neighbors = difference(neighbors, elements);
  return neighbors;
}

bool smoothThePool(
  GFace *gf, const std::vector<MVertex *> &smoothingPool,
  const unordered_map<MVertex *, std::vector<MElement *> > &adj,
  bool invertNormalsForQuality, SurfaceProjector *sp = nullptr)
{
  /* Get all quads used for smoothing */
  std::vector<MElement *> elements;
  {
    std::vector<MVertex *> unq = smoothingPool;
    sort_unique(unq);
    elements.reserve(unq.size());
    for(MVertex *v : unq) {
      auto it = adj.find(v);
      if(it != adj.end()) {
        auto it2 =
          std::find(gf->mesh_vertices.begin(), gf->mesh_vertices.end(), v);
        if(it2 != gf->mesh_vertices.end()) { append(elements, it->second); }
      }
    }
  }
  sort_unique(elements);

  // ensures all the elements are in the GFace. Should not be different,
  // but there are some bugs in the smoothing pool
  std::vector<MElement *> faceElements =
    dynamic_cast_vector<MQuadrangle *, MElement *>(gf->quadrangles);
  elements = intersection(elements, faceElements);

  /* Build the disconnected patches and smooth them independently */
  std::vector<std::vector<MElement *> > components;
  bool okc = getConnectedComponents(elements, components);
  if(!okc) return false;
  Msg::Debug("smooth %li connected components from %li initial elements ...",
             components.size(), elements.size());
  for(size_t i = 0; i < components.size(); ++i) {
    GFaceMeshPatch patch;
    bool okp = patchFromElements(gf, components[i], patch);
    if(!okp) continue;

    PatchGeometryBackup backup(patch);

    GeomOptimStats stats;
    double sicnBefore = 0.;
    if(haveNiceParametrization(gf)) {
      if(patch.bdrVertices.size() == 1) { /* disk topology */
        /* Global UV smoothing */
        patchOptimizeGeometryGlobal(patch, stats);
        sicnBefore = stats.sicnMinBefore;

        if(stats.sicnMinAfter < 0.5) {
          /* Kernel smoothing */
          GeomOptimOptions opt;
          opt.invertCADNormals = invertNormalsForQuality;
          patchOptimizeGeometryWithKernel(patch, opt, stats);
        }
      }
      else {
        double sicnAvg;
        computeSICN(patch.elements, sicnBefore, sicnAvg);
        if(sicnBefore < 0.5) {
          /* Kernel smoothing */
          GeomOptimOptions opt;
          opt.invertCADNormals = invertNormalsForQuality;
          patchOptimizeGeometryWithKernel(patch, opt, stats);
        }
      }
    }
    else {
      GeomOptimOptions opt;
      opt.sp = sp;
      opt.outerLoopIterMax = 20.;
      opt.timeMax = 10.;
      opt.withBackup = true;
      opt.invertCADNormals = invertNormalsForQuality;
      // opt.smartMinThreshold = 0.1;
      // opt.localLocking = true;
      opt.dxLocalMax = 1.e-4;
      patchOptimizeGeometryWithKernel(patch, opt, stats);
    }

    /* Check after smoothing */
    if(stats.sicnMinAfter < sicnBefore) {
      Msg::Debug(
        "quality (SICN) decreased (%.3f -> %.3f), restore previous geometry",
        sicnBefore, stats.sicnMinAfter);
      backup.restore();
    }
  }

  return true;
}

struct DQOptions {
  bool invertNormalsForQuality = false;
  SurfaceProjector *sp = nullptr;
};

struct DQStats {
  size_t nCornerValFixed = 0;
  size_t nCurveValFixed = 0;
  size_t nSurfaceValFixed = 0;
  size_t nCornerValRemaining = 0;
  size_t nCurveValRemaining = 0;
  size_t nSurfaceValRemaining = 0;
};

int improveCornerValences(
  GFace *gf,
  const unordered_map<MVertex *, double>
    &qValIdeal, /* valence on bdr vertices */
  unordered_map<MVertex *, std::vector<MElement *> > &adj, DQOptions &opt,
  DQStats &stats)
{
  Msg::Debug("- Face %i: improve corner valences", gf->tag());
  std::vector<MVertex *>
    smoothingPool; /* for smoothing after topological changes */
  smoothingPool.reserve(gf->mesh_vertices.size());

  /* qValIdeal is unordered_map and its ordering is random, we replace
   * it with a deterministic ordering, containing only the corners */
  std::vector<std::pair<MVertex *, double> > cornerAndIdeal;
  for(auto &kv : qValIdeal) {
    GVertex *gv = dynamic_cast<GVertex *>(kv.first->onWhat());
    if(gv != nullptr) { cornerAndIdeal.push_back({kv.first, kv.second}); }
  }
  std::sort(cornerAndIdeal.begin(), cornerAndIdeal.end(),
            [](const std::pair<MVertex *, double> &lhs,
               const std::pair<MVertex *, double> &rhs) {
              return lhs.second < rhs.second ||
                     (lhs.second == rhs.second &&
                      lhs.first->getNum() < rhs.first->getNum());
            });

  int SMALL_PATCH = 0; /* just the quads adjacent to corner */
  int LARGER_PATCH = 1; /* add the neighbors */
  int CORNER_PATCH =
    2; /* add the neighbors of neighbors of the extruded vertex if valence 2 */
  int CORNER_PATCH_2 = 3; /* CORNER_PATCH + one layer */
  /* We try larger cavities first because the result is usually better
   * when it works (less new defects on adjacent curves). But it does
   * not work when the larger cavity is too constrained by CAD curves,
   * so we try the small cavity after */
  for(int pass : {CORNER_PATCH, CORNER_PATCH_2, LARGER_PATCH, SMALL_PATCH}) {
    for(const auto &kv : cornerAndIdeal) {
      MVertex *v = kv.first;
      GVertex *gv = dynamic_cast<GVertex *>(v->onWhat());
      if(gv == nullptr) continue;

      auto it = adj.find(v);
      if(it == adj.end()) continue;
      const std::vector<MElement *> &quads = it->second;
      double ival_float = kv.second;
      size_t ival = idealBoundaryValence(kv.first, ival_float);
      if(ival == quads.size()) continue;
      size_t num = v->getNum();

      /* From here, we try to change the local configuration */
      Msg::Debug(
        "- Face %i: try to fix corner %i (vertex %li), val %li instead of %li",
        gf->tag(), gv->tag(), num, it->second.size(), ival);

      /* Init patch with quads adjacent to corner */
      GFaceMeshPatch patch;
      if((pass == CORNER_PATCH || pass == CORNER_PATCH_2) &&
         quads.size() == 2) {
        /* The corner is valence and has been extruded
         * take all the quads around the extruded vertex */
        std::vector<MVertex *> vert1 = {
          quads[0]->getVertex(0), quads[0]->getVertex(1),
          quads[0]->getVertex(2), quads[0]->getVertex(3)};
        std::vector<MVertex *> vert2 = {
          quads[1]->getVertex(0), quads[1]->getVertex(1),
          quads[1]->getVertex(2), quads[1]->getVertex(3)};
        std::vector<MVertex *> shared = intersection(vert1, vert2);
        if(shared.size() != 2) continue;
        MVertex *ext = nullptr;
        if(shared[0] == v) { ext = shared[1]; }
        else if(shared[1] == v) {
          ext = shared[0];
        }
        else {
          continue;
        }
        auto it2 = adj.find(ext);
        if(it2 == adj.end()) continue;
        std::vector<MElement *> quadsPlus = it2->second;
        append(quadsPlus, getNeighbors(quadsPlus, adj));
        if(pass == CORNER_PATCH_2) {
          append(quadsPlus, getNeighbors(quadsPlus, adj));
        }
        bool okp = patchFromElements(gf, quadsPlus, patch);
        if(!okp) continue;
      }
      else if(pass == LARGER_PATCH) {
        /* and the neighbors */
        std::vector<MElement *> quadsPlus = quads;
        append(quadsPlus, getNeighbors(quads, adj));
        bool okp = patchFromElements(gf, quadsPlus, patch);
        if(!okp) continue;
      }
      else if(pass == SMALL_PATCH) {
        bool okp = patchFromElements(gf, quads, patch);
        if(!okp) continue;
      }
      if(patch.bdrVertices.size() != 1) {
        Msg::Debug("patch has %li bdr loops, weird", patch.bdrVertices.size());
        continue;
      }
      if(patch.embVertices.size() > 0) {
        Msg::Debug("patch has %li embedded vertices loops, avoid",
                   patch.embVertices.size());
        continue;
      }

      std::vector<int> bndIdealValence;
      std::vector<std::pair<int, int> > bndAllowedValenceRange;
      const int dimCorner = 0;
      bool okb = getBoundaryIdealAndAllowedValences(dimCorner, patch, adj,
                                                    qValIdeal, bndIdealValence,
                                                    bndAllowedValenceRange);
      if(!okb) continue;

      GFaceMeshDiff diff;
      std::vector<MElement *> neighborsForGeometry =
        getNeighbors(patch.elements, adj);
      double minSICNafer = 0.1;
      if(ival_float <= 0.5) minSICNafer = 0.001; /* acute corner */
      int sdq = remeshLocalWithDiskQuadrangulation(
        gf, patch.elements, patch.intVertices, patch.bdrVertices.front(),
        bndIdealValence, bndAllowedValenceRange, neighborsForGeometry,
        minSICNafer, opt.invertNormalsForQuality, opt.sp, diff);
      if(sdq == 0) {
        /* Copy the pointers to update the adjacencies in case success */
        GFaceMeshPatch patchBefore = diff.before;
        GFaceMeshPatch patchAfter = diff.after;

        if(SHOW_DQR) {
          // FIXME using the public API inside Gmsh is not a good idea
          if(!gmsh::isInitialized()) gmsh::initialize();
          GeoLog::add(patchBefore.elements, "fixCornerB");
          GeoLog::add(patchAfter.elements, "fixCornerA");
          gmsh::view::add("---");
          GeoLog::flush();
        }

        /* Execute the diff on the mesh */
        bool ok = diff.execute(true); /* warning: GFace mesh changes here */
        if(PARANO_VALIDITY) {
          errorAndAbortIfInvalidSurfaceMesh(
            gf, "improveCornerValences | after execute");
        }
        if(ok) {
          updateAdjacencies(patchBefore, patchAfter, adj);
          append(smoothingPool, patchAfter.intVertices);
          append(smoothingPool, patchAfter.bdrVertices.front());
          stats.nCornerValFixed += 1;
        }
        else {
          Msg::Error("failed to apply diff, abort");
          abort();
        }
        Msg::Debug("-- corner %li fixed", num);
      }
      else {
        Msg::Debug("-- failed to fix corner %li", num);
        if(SHOW_DQR) {
          // FIXME using the public API inside Gmsh is not a good idea
          if(!gmsh::isInitialized()) gmsh::initialize();
          GeoLog::add(patch.elements, "fixCornerFAILED");
          gmsh::view::add("---");
          GeoLog::flush();
        }
      }
    }
  }

  if(smoothingPool.size() > 0)
    smoothThePool(gf, smoothingPool, adj, opt.invertNormalsForQuality, opt.sp);

  /* Remaining cases, just for stats */
  for(const auto &kv : cornerAndIdeal) {
    MVertex *v = kv.first;
    GVertex *gv = dynamic_cast<GVertex *>(v->onWhat());
    if(gv == nullptr) continue;
    auto it = adj.find(v);
    if(it == adj.end()) continue;
    const std::vector<MElement *> &quads = it->second;
    size_t ival = idealBoundaryValence(kv.first, kv.second);
    if(ival == quads.size()) continue;
    stats.nCornerValRemaining += 1;
  }

  return 0;
}

int improveCurveValences(
  GFace *gf,
  const unordered_map<MVertex *, double>
    &qValIdeal, /* valence on bdr vertices */
  unordered_map<MVertex *, std::vector<MElement *> > &adj, DQOptions &opt,
  DQStats &stats)
{
  Msg::Debug("- Face %i: improve curve valences", gf->tag());
  std::vector<MVertex *>
    smoothingPool; /* for smoothing after topological changes */
  smoothingPool.reserve(gf->mesh_vertices.size());

  /* qValIdeal is unordered_map and its ordering is random, we replace
   * it with a deterministic ordering, containing only the corners */
  std::vector<std::pair<MVertex *, double> > curveVertexAndIdeal;
  curveVertexAndIdeal.reserve(qValIdeal.size());
  for(auto &kv : qValIdeal) {
    MVertex *v = kv.first;
    GEdge *ge = dynamic_cast<GEdge *>(v->onWhat());
    if(ge != nullptr) { curveVertexAndIdeal.push_back({kv.first, kv.second}); }
  }
  std::sort(curveVertexAndIdeal.begin(), curveVertexAndIdeal.end(),
            [](const std::pair<MVertex *, double> &lhs,
               const std::pair<MVertex *, double> &rhs) {
              return lhs.second < rhs.second ||
                     (lhs.second == rhs.second &&
                      lhs.first->getNum() < rhs.first->getNum());
            });

  for(const auto &kv : curveVertexAndIdeal) {
    MVertex *v = kv.first;
    GEdge *ge = dynamic_cast<GEdge *>(v->onWhat());
    if(ge == nullptr) continue;
    auto it = adj.find(v);
    if(it == adj.end()) continue;
    const std::vector<MElement *> &quads = it->second;
    size_t ival = idealBoundaryValence(kv.first, kv.second);
    if(ival == quads.size()) continue;
    size_t num = v->getNum();

    /* From here, we try to change the local configuration */
    Msg::Debug("- Face %i: try to fix curve vertex %li, val %li instead of %li",
               gf->tag(), v->getNum(), it->second.size(), ival);

    /* Init patch with quads adjacent to corner */
    GFaceMeshPatch patch;
    bool okp = patchFromElements(gf, quads, patch);
    if(!okp) continue;
    if(patch.bdrVertices.size() != 1) {
      Msg::Debug("patch has %li bdr loops, weird", patch.bdrVertices.size());
      continue;
    }
    if(patch.embVertices.size() > 0) {
      Msg::Debug("patch has %li embedded vertices loops, avoid",
                 patch.embVertices.size());
      continue;
    }

    std::vector<int> bndIdealValence;
    std::vector<std::pair<int, int> > bndAllowedValenceRange;
    const int dimCurve = 1;
    bool okb = getBoundaryIdealAndAllowedValences(
      dimCurve, patch, adj, qValIdeal, bndIdealValence, bndAllowedValenceRange);
    if(!okb) continue;

    GFaceMeshDiff diff;
    std::vector<MElement *> neighborsForGeometry =
      getNeighbors(patch.elements, adj);
    double minSICNafer = 0.1;
    int sdq = remeshLocalWithDiskQuadrangulation(
      gf, patch.elements, patch.intVertices, patch.bdrVertices.front(),
      bndIdealValence, bndAllowedValenceRange, neighborsForGeometry,
      minSICNafer, opt.invertNormalsForQuality, opt.sp, diff);
    if(sdq == 0) {
      /* Copy the pointers to update the adjacencies in case success */
      GFaceMeshPatch patchBefore = diff.before;
      GFaceMeshPatch patchAfter = diff.after;

      if(SHOW_DQR) {
        // FIXME using the public API inside Gmsh is not a good idea
        if(!gmsh::isInitialized()) gmsh::initialize();
        GeoLog::add(patchBefore.elements, "fixCurveB");
        GeoLog::add(patchAfter.elements, "fixCurveA");
        gmsh::view::add("---");
        GeoLog::flush();
      }

      /* Execute the diff on the mesh */
      bool ok = diff.execute(true); /* warning: GFace mesh changes here */
      if(PARANO_VALIDITY) {
        errorAndAbortIfInvalidSurfaceMesh(
          gf, "improveCurveValences | after execute");
      }
      if(ok) {
        updateAdjacencies(patchBefore, patchAfter, adj);
        append(smoothingPool, patchAfter.intVertices);
        append(smoothingPool, patchAfter.bdrVertices.front());
        stats.nCurveValFixed += 1;

        if(PARANO_QUALITY) {
          errorAndAbortIfNegativeElement(
            gf, dynamic_cast_vector<MQuadrangle *, MElement *>(gf->quadrangles),
            "after execute");
        }
      }
      else {
        Msg::Error("failed to apply diff, abort");
        abort();
      }
      Msg::Debug("-- curve vertex %li fixed", num);
    }
    else {
      Msg::Debug("-- failed to fix curve vertex %li", num);

      if(PARANO_QUALITY) {
        errorAndAbortIfNegativeElement(
          gf, dynamic_cast_vector<MQuadrangle *, MElement *>(gf->quadrangles),
          "after failed to fix, baaad");
      }
    }
  }

  if(PARANO_QUALITY) {
    errorAndAbortIfNegativeElement(
      gf, dynamic_cast_vector<MQuadrangle *, MElement *>(gf->quadrangles),
      "before pool");
  }

  if(smoothingPool.size() > 0)
    smoothThePool(gf, smoothingPool, adj, opt.invertNormalsForQuality, opt.sp);

  if(PARANO_QUALITY) {
    errorAndAbortIfNegativeElement(
      gf, dynamic_cast_vector<MQuadrangle *, MElement *>(gf->quadrangles),
      "after pool");
  }

  /* Remaining cases, just for stats */
  for(const auto &kv : curveVertexAndIdeal) {
    MVertex *v = kv.first;
    GEdge *ge = dynamic_cast<GEdge *>(v->onWhat());
    if(ge == nullptr) continue;
    auto it = adj.find(v);
    if(it == adj.end()) continue;
    const std::vector<MElement *> &quads = it->second;
    size_t ival = idealBoundaryValence(kv.first, kv.second);
    if(ival == quads.size()) continue;
    stats.nCurveValRemaining += 1;
  }

  return 0;
}

double irregularityEnergy(
  const GFaceMeshPatch &patch,
  const unordered_map<MVertex *, double> &qValIdeal,
  const unordered_map<MVertex *, std::vector<MElement *> > &adj)
{
  double Ir = 0.;
  /* Boundary vertices */
  for(MVertex *v : patch.bdrVertices.front()) {
    double valIdeal = 4.;
    auto it = qValIdeal.find(v);
    if(it != qValIdeal.end()) { valIdeal = it->second; }
    auto it2 = adj.find(v);
    if(it2 == adj.end()) { continue; }
    valIdeal = clamp(std::round(valIdeal), 1., 4.);

    double val = (double)it2->second.size();
    Ir += std::pow(valIdeal - val, 2);
  }
  /* Interior vertices */
  for(MVertex *v : patch.intVertices) {
    double valIdeal = 4.;
    auto it2 = adj.find(v);
    if(it2 == adj.end()) { continue; }
    valIdeal = clamp(std::round(valIdeal), 1., 4.);
    double val = (double)it2->second.size();
    Ir += std::pow(valIdeal - val, 2);
  }
  return Ir;
}

double irregularityEnergy(
  GFace *gf, const std::vector<MElement *> &quads,
  const unordered_map<MVertex *, double> &qValIdeal,
  const unordered_map<MVertex *, std::vector<MElement *> > &adj)
{
  GFaceMeshPatch patch;
  bool okp = patchFromElements(gf, quads, patch);
  if(!okp) return 0.;
  return irregularityEnergy(patch, qValIdeal, adj);
}

int improveInteriorValences(
  GFace *gf,
  const unordered_map<MVertex *, double>
    &qValIdeal, /* valence on bdr vertices */
  unordered_map<MVertex *, std::vector<MElement *> > &adj, DQOptions &opt,
  DQStats &stats)
{
  Msg::Debug("- Face %i: improve interior valences", gf->tag());

  std::vector<MVertex *>
    smoothingPool; /* for smoothing after topological changes */
  smoothingPool.reserve(gf->mesh_vertices.size());

  /* Priority queue */
  std::priority_queue<std::pair<double, MVertex *>,
                      std::vector<std::pair<double, MVertex *> > >
    Q;

  /* Initialize with all very irregular vertices of the face */
  for(const auto &kv : adj) {
    MVertex *v = kv.first;
    GFace *gf = dynamic_cast<GFace *>(v->onWhat());
    if(gf == nullptr) continue;
    auto it = adj.find(v);
    if(it == adj.end()) continue;
    const std::vector<MElement *> &quads = it->second;
    const size_t val = quads.size();
    if(3 <= val && val <= 5) continue;

    /* Build patch with quads adjacent to very irregular vertex */
    GFaceMeshPatch patch;
    bool okp = patchFromElements(gf, quads, patch);
    if(!okp || patch.bdrVertices.size() != 1) continue;

    if(patch.embVertices.size() > 0) {
      Msg::Debug("patch has %li embedded vertices loops, avoid",
                 patch.embVertices.size());
      continue;
    }

    double Ir = irregularityEnergy(gf, quads, qValIdeal, adj);
    if(Ir > 0.) Q.push({Ir, v});
  }

  /* Topological replacement loop */
  while(Q.size() > 0) {
    MVertex *v = Q.top().second;
    Q.pop();

    auto it = adj.find(v);
    /* Check if vertex still exists, may have been removed */
    if(it == adj.end()) continue;
    const std::vector<MElement *> &quads = it->second;
    size_t num = v->getNum();

    /* Build patch with quads adjacent to very irregular vertex */
    GFaceMeshPatch patch;
    bool okp = patchFromElements(gf, quads, patch);
    if(!okp || patch.bdrVertices.size() != 1) continue;

    /* Get ideal and allowed ranges on the patch boundary */
    std::vector<int> bndIdealValence;
    std::vector<std::pair<int, int> > bndAllowedValenceRange;
    const int dimCurve = 2;
    bool okb = getBoundaryIdealAndAllowedValences(
      dimCurve, patch, adj, qValIdeal, bndIdealValence, bndAllowedValenceRange);
    if(!okb) continue;

    /* Check if there is a valid disk remeshing */
    GFaceMeshDiff diff;
    std::vector<MElement *> neighborsForGeometry =
      getNeighbors(patch.elements, adj);
    double minSICNafer = 0.1;
    int sdq = remeshLocalWithDiskQuadrangulation(
      gf, patch.elements, patch.intVertices, patch.bdrVertices.front(),
      bndIdealValence, bndAllowedValenceRange, neighborsForGeometry,
      minSICNafer, opt.invertNormalsForQuality, opt.sp, diff);
    if(sdq == 0) {
      /* Copy the pointers to update the adjacencies in case success */
      GFaceMeshPatch patchBefore = diff.before;
      GFaceMeshPatch patchAfter = diff.after;

      if(SHOW_DQR) {
        // FIXME using the public API inside Gmsh is not a good idea
        if(!gmsh::isInitialized()) gmsh::initialize();
        GeoLog::add(patchBefore.elements, "fixIntB");
        GeoLog::add(patchAfter.elements, "fixIntA");
        gmsh::view::add("---");
        GeoLog::flush();
      }

      /* Execute the diff on the mesh */
      bool ok = diff.execute(true); /* warning: GFace mesh changes here */
      if(PARANO_VALIDITY) {
        errorAndAbortIfInvalidSurfaceMesh(
          gf, "improveInteriorValences | after execute");
      }
      if(ok) {
        updateAdjacencies(patchBefore, patchAfter, adj);
        append(smoothingPool, patchAfter.intVertices);
        append(smoothingPool, patchAfter.bdrVertices.front());
        stats.nSurfaceValFixed += 1;

        /* If new very irregular vertices have been created,
         * add them to the queue */
        for(MVertex *bv : patchAfter.bdrVertices.front()) {
          auto it2 = adj.find(bv);
          if(it2 == adj.end()) continue;
          const std::vector<MElement *> &quads2 = it2->second;
          if(quads2.size() > 5) {
            double Ir2 = irregularityEnergy(gf, quads2, qValIdeal, adj);
            if(Ir2 > 0) Q.push({Ir2, bv});
          }
        }
      }
      else {
        Msg::Error("failed to apply diff, abort");
        abort();
      }
      Msg::Debug("-- interior vertex %li fixed", num);
    }
    else {
      Msg::Debug("-- failed to fix interior vertex %li", num);
      // GeoLog::add(quads, "!I_v"+std::to_string(v->getNum()));
    }
  }
  // GeoLog::flush();

  if(smoothingPool.size() > 0)
    smoothThePool(gf, smoothingPool, adj, opt.invertNormalsForQuality, opt.sp);

  /* Remaining cases, just for stats */
  for(const auto &kv : adj) {
    MVertex *v = kv.first;
    GFace *gf = dynamic_cast<GFace *>(v->onWhat());
    if(gf == nullptr) continue;
    auto it = adj.find(v);
    if(it == adj.end()) continue;
    const std::vector<MElement *> &quads = it->second;
    const size_t val = quads.size();
    if(3 <= val && val <= 5) continue;
    stats.nSurfaceValRemaining += 1;
  }

  return 0;
}

bool patchIsValidForDiskRequadrangulation(
  const GFaceMeshPatch &patch,
  const unordered_map<MVertex *, std::vector<MElement *> > &adj)
{
  if(patch.bdrVertices.size() != 1) return false;
  for(MVertex *v : patch.intVertices) {
    auto it = adj.find(v);
    if(it == adj.end()) return false;
  }
  for(MVertex *v : patch.bdrVertices[0]) {
    auto it = adj.find(v);
    if(it == adj.end()) return false;
  }
  for(MElement *e : patch.elements) {
    auto it =
      std::find(patch.gf->quadrangles.begin(), patch.gf->quadrangles.end(), e);
    if(it == patch.gf->quadrangles.end()) return false;
  }
  std::vector<MVertex *> bndt;
  bool okbb = buildBoundary(patch.elements, bndt);
  if(!okbb) return false;

  return true;
}

bool getIrregularPatchesAroundVertices(
  const std::vector<MVertex *> &vert,
  const unordered_map<MVertex *, std::vector<MElement *> > &adj,
  const unordered_map<MVertex *, double> &qValIdeal,
  std::vector<std::pair<double, GFaceMeshPatch> > &patches)
{
  for(MVertex *v : vert) {
    GFace *gf = dynamic_cast<GFace *>(v->onWhat());
    if(gf == nullptr) continue;
    auto it = adj.find(v);
    if(it == adj.end()) continue;
    const std::vector<MElement *> &quads = it->second;
    const size_t val = quads.size();
    if(val == 4) continue;
    if(val > 5) {
      /* Take adjacent quads around very irregular vertex */
      GFaceMeshPatch patch;
      bool okp = patchFromElements(gf, quads, patch);
      if(!okp || patch.bdrVertices.size() != 1) continue;
      if(patch.embVertices.size() > 0) { continue; }
      double Ir = irregularityEnergy(gf, quads, qValIdeal, adj);
      if(Ir > 0.) patches.push_back({Ir, patch});
    }
    else {
      /* Loop on edges around v */
      for(MElement *q : quads)
        for(size_t le = 0; le < 4; ++le) {
          MVertex *v1 = q->getVertex(le);
          MVertex *v2 = q->getVertex((le + 1) % 4);
          if(v1 != v && v2 != v) continue;
          if(v1->getNum() > v2->getNum()) continue;
          auto it2 = (v1 == v) ? adj.find(v2) : adj.find(v1);
          if(it2 == adj.end()) continue;
          if(it2->second.size() != 4) {
            /* v1 and v2 are irregular, build cavity around them */
            std::vector<MElement *> elts = quads;
            append(elts, it2->second);
            GFaceMeshPatch patch;
            bool okp = patchFromElements(gf, elts, patch);
            if(!okp || patch.bdrVertices.size() != 1) continue;
            if(patch.embVertices.size() > 0) continue;
            double Ir = irregularityEnergy(gf, elts, qValIdeal, adj);
            if(Ir > 0.) patches.push_back({Ir, patch});
          }
        }
      /* Check for irreg quads */
      for(MElement *q : quads) {
        auto it0 = adj.find(q->getVertex(0));
        auto it1 = adj.find(q->getVertex(1));
        auto it2 = adj.find(q->getVertex(2));
        auto it3 = adj.find(q->getVertex(3));
        if(it0 == adj.end() || it1 == adj.end() || it2 == adj.end() ||
           it3 == adj.end())
          continue;
        std::array<size_t, 4> vals = {it0->second.size(), it1->second.size(),
                                      it2->second.size(), it3->second.size()};
        for(size_t k = 0; k < 2; ++k) {
          if(vals[k] != 4 && vals[k + 2] != 4) {
            /* Opposite vertices are irregular */
            std::vector<MElement *> elts = {q};
            append(elts, getNeighbors(elts, adj));
            GFaceMeshPatch patch;
            bool okp = patchFromElements(gf, elts, patch);
            if(!okp || patch.bdrVertices.size() != 1) continue;
            if(patch.embVertices.size() > 0) continue;
            double Ir = irregularityEnergy(gf, elts, qValIdeal, adj);
            if(Ir > 0.) patches.push_back({Ir, patch});
            break;
          }
        }
      }
    }
  }
  return true;
}

int improveInteriorValencesV2(
  GFace *gf,
  const unordered_map<MVertex *, double>
    &qValIdeal, /* valence on bdr vertices */
  unordered_map<MVertex *, std::vector<MElement *> > &adj, DQOptions &opt,
  DQStats &stats)
{
  Msg::Debug("- Face %i: improve interior valences", gf->tag());

  std::vector<MVertex *>
    smoothingPool; /* for smoothing after topological changes */
  smoothingPool.reserve(gf->mesh_vertices.size());

  /* Priority queue */
  typedef std::pair<double, GFaceMeshPatch> Ir_and_Patch;
  auto comp = [](const Ir_and_Patch &a, const Ir_and_Patch &b) {
    return a.first > b.first ||
           (a.first == b.first &&
            a.second.elements.size() < b.second.elements.size());
  };
  std::priority_queue<Ir_and_Patch, std::vector<Ir_and_Patch>, decltype(comp)>
    Q(comp);

  /* Initialize with patches around irregular vertices of the face */
  for(const auto &kv : adj) {
    MVertex *v = kv.first;
    GFace *gf = dynamic_cast<GFace *>(v->onWhat());
    if(gf == nullptr) continue;
    auto it = adj.find(v);
    if(it == adj.end()) continue;
    const std::vector<MElement *> &quads = it->second;
    const size_t val = quads.size();
    if(val == 4) continue;

    std::vector<std::pair<double, GFaceMeshPatch> > patches;
    getIrregularPatchesAroundVertices({v}, adj, qValIdeal, patches);
    for(size_t k = 0; k < patches.size(); ++k) { Q.push(patches[k]); }
  }

  /* Topological replacement loop */
  while(Q.size() > 0) {
    GFaceMeshPatch patch = Q.top().second;
    Q.pop();

    if(!patchIsValidForDiskRequadrangulation(patch, adj)) continue;

    /* Get ideal and allowed ranges on the patch boundary */
    std::vector<int> bndIdealValence;
    std::vector<std::pair<int, int> > bndAllowedValenceRange;
    const int dimCurve = 2;
    bool okb = getBoundaryIdealAndAllowedValences(
      dimCurve, patch, adj, qValIdeal, bndIdealValence, bndAllowedValenceRange);
    if(!okb) continue;

    /* Check if there is a valid disk remeshing */
    GFaceMeshDiff diff;
    std::vector<MElement *> neighborsForGeometry =
      getNeighbors(patch.elements, adj);
    double minSICNafer = 0.1;
    int sdq = remeshLocalWithDiskQuadrangulation(
      gf, patch.elements, patch.intVertices, patch.bdrVertices.front(),
      bndIdealValence, bndAllowedValenceRange, neighborsForGeometry,
      minSICNafer, opt.invertNormalsForQuality, opt.sp, diff);
    if(sdq == 0) {
      /* Copy the pointers to update the adjacencies in case success */
      GFaceMeshPatch patchBefore = diff.before;
      GFaceMeshPatch patchAfter = diff.after;

      if(SHOW_DQR) {
        // FIXME using the public API inside Gmsh is not a good idea
        if(!gmsh::isInitialized()) gmsh::initialize();
        GeoLog::add(patchBefore.elements, "fixIntB");
        GeoLog::add(patchAfter.elements, "fixIntA");
        gmsh::view::add("---");
        GeoLog::flush();
      }

      /* Execute the diff on the mesh */
      bool ok = diff.execute(true); /* warning: GFace mesh changes here */
      if(PARANO_VALIDITY) {
        errorAndAbortIfInvalidSurfaceMesh(
          gf, "improveInteriorValencesV2 | after execute");
      }
      if(ok) {
        updateAdjacencies(patchBefore, patchAfter, adj);
        append(smoothingPool, patchAfter.intVertices);
        append(smoothingPool, patchAfter.bdrVertices.front());
        stats.nSurfaceValFixed += 1;

        /* If new irregular patches have been created,
         * add them to the queue */
        std::vector<std::pair<double, GFaceMeshPatch> > patches;
        getIrregularPatchesAroundVertices(patchAfter.bdrVertices.front(), adj,
                                          qValIdeal, patches);
        for(size_t k = 0; k < patches.size(); ++k) { Q.push(patches[k]); }
      }
      else {
        Msg::Error("failed to apply diff, abort");
        abort();
      }
      Msg::Debug("-- interior patch fixed");
    }
    else {
      Msg::Debug("-- failed to fix interior patch");
      // GeoLog::add(quads, "!I_v"+std::to_string(v->getNum()));
    }
  }
  // GeoLog::flush();

  if(smoothingPool.size() > 0)
    smoothThePool(gf, smoothingPool, adj, opt.invertNormalsForQuality, opt.sp);

  /* Remaining cases, just for stats */
  for(const auto &kv : adj) {
    MVertex *v = kv.first;
    GFace *gf = dynamic_cast<GFace *>(v->onWhat());
    if(gf == nullptr) continue;
    auto it = adj.find(v);
    if(it == adj.end()) continue;
    const std::vector<MElement *> &quads = it->second;
    const size_t val = quads.size();
    if(3 <= val && val <= 5) continue;
    stats.nSurfaceValRemaining += 1;
  }

  return 0;
}

int RefineMeshWithBackgroundMeshProjectionSimple(GModel *gm)
{
  Msg::Info(
    "Refine mesh (midpoint subdivision, with background projection) ...");

  bool linear = true;
  RefineMesh(gm, linear, true, false);

  /* Convert vertex types:
   * - MVertex on curve -> MEdgeVertex
   * - MVertex on face  -> MFaceVertex */
  std::vector<GEdge *> edges = model_edges(gm);
  std::vector<GFace *> faces = model_faces(gm);

  /* old2new use to update mesh elements after */
  unordered_map<MVertex *, MVertex *> old2new;

  // FIXME: crash #1799
  int nthreads = 1; //getNumThreads();

#pragma omp parallel for schedule(dynamic) num_threads(nthreads)
  for(size_t e = 0; e < edges.size(); ++e) {
    GEdge *ge = edges[e];
    if(CTX::instance()->mesh.meshOnlyVisible && !ge->getVisibility()) continue;
    if(ge->mesh_vertices.size() == 0) continue;
    std::vector<MVertex *> toProj;
    toProj.reserve(ge->mesh_vertices.size() / 2);

    /* Replace MVertex by MEdgeVertex */
    for(size_t i = 0; i < ge->mesh_vertices.size(); ++i) {
      MVertex *v = ge->mesh_vertices[i];
      if(v->onWhat() != ge) {
        Msg::Error("- Edge %i: vertex %li is associated to entity (%i,%i)",
                   ge->tag(), v->getNum(), v->onWhat()->dim(),
                   v->onWhat()->tag());
        continue;
      }
      MEdgeVertex *mev = dynamic_cast<MEdgeVertex *>(v);
      if(mev == nullptr) {
        MVertex *v2 = new MEdgeVertex(v->point().x(), v->point().y(),
                                      v->point().z(), ge, 0.);
        ge->mesh_vertices[i] = v2;
        old2new[v] = v2;
        toProj.push_back(v2);
        delete v;
      }
    }
    /* Projections */
    double tMin = ge->parBounds(0).low();
    double tMax = ge->parBounds(0).high();
    for(size_t i = 0; i < toProj.size(); ++i) {
      MVertex *v = toProj[i];
      double tGuess =
        tMin + (tMax - tMin) * double(i + 1) / double(toProj.size());
      GPoint proj = ge->closestPoint(v->point(), tGuess);
      if(proj.succeeded()) {
        v->setXYZ(proj.x(), proj.y(), proj.z());
        v->setParameter(0, proj.u());
      }
      else {
        Msg::Warning("- Edge %i, vertex %li: curve projection failed",
                     ge->tag(), v->getNum());
      }
    }
  }

  GlobalBackgroundMesh *bmesh = nullptr;
  if(backgroudMeshExists(BMESH_NAME)) {
    bmesh = &(getBackgroundMesh(BMESH_NAME));
  }
  else {
    Msg::Warning("refine mesh with background projection: no background mesh, "
                 "using CAD projection (slow)");
  }

#pragma omp parallel for schedule(dynamic) num_threads(nthreads)
  for(size_t f = 0; f < faces.size(); ++f) {
    GFace *gf = faces[f];
    if(CTX::instance()->mesh.meshOnlyVisible && !gf->getVisibility()) continue;
    if(CTX::instance()->debugSurface > 0 &&
       gf->tag() != CTX::instance()->debugSurface)
      continue;
    if(gf->triangles.size() == 0 && gf->quadrangles.size() == 0) continue;
    std::vector<MVertex *> toProj;
    toProj.reserve(gf->mesh_vertices.size() / 2);
    for(size_t i = 0; i < gf->mesh_vertices.size(); ++i) {
      MVertex *v = gf->mesh_vertices[i];
      if(v->onWhat() != gf) {
        Msg::Error("- Face %i: vertex %li is associated to entity (%i,%i)",
                   gf->tag(), v->getNum(), v->onWhat()->dim(),
                   v->onWhat()->tag());
        continue;
      }

      /* Replace MVertex by MFaceVertex */
      MFaceVertex *mfv = dynamic_cast<MFaceVertex *>(v);
      if(mfv == nullptr) {
        MVertex *v2 = new MFaceVertex(v->point().x(), v->point().y(),
                                      v->point().z(), gf, 0., 0.);
        gf->mesh_vertices[i] = v2;
        old2new[v] = v2;
        toProj.push_back(v2);
        delete v;
      }
    }

    /* Projections */
    SurfaceProjector *sp = nullptr;
    sp = new SurfaceProjector();
    bool oki = sp->initialize(gf, {}, true);
    if(!oki && bmesh) {
      auto it2 = bmesh->faceBackgroundMeshes.find(gf);
      if(it2 == bmesh->faceBackgroundMeshes.end()) {
        Msg::Error("background mesh not found for face %i", gf->tag());
      }
      else {
        /* Get pointers to triangles in the background mesh */
        std::vector<MTriangle *> triangles(it2->second.triangles.size());
        for(size_t i = 0; i < it2->second.triangles.size(); ++i) {
          triangles[i] = &(it2->second.triangles[i]);
        }
        oki = sp->initialize(gf, triangles);
        if(!oki) {
          Msg::Warning("failed to initialize surface projector");
          delete sp;
          sp = nullptr;
        }
      }
    }
    if(!oki && sp) {
      delete sp;
      sp = nullptr;
    }

    bool evalOnCAD = false;
    bool projOnCad = false;
    // if (gf->haveParametrization() && !gf->periodic(0)  && !gf->periodic(1))
    // evalOnCAD = true;

    for(size_t i = 0; i < toProj.size(); ++i) {
      MVertex *v = toProj[i];
      GPoint proj;
      if(sp != nullptr) {
        proj = sp->closestPoint(v->point().data(), evalOnCAD, projOnCad);
        if(!proj.succeeded() && gf->haveParametrization()) {
          double uvg[2] = {0., 0.};
          proj = gf->closestPoint(v->point(), uvg);
        }
      }
      else {
        double uvg[2] = {0., 0.};
        proj = gf->closestPoint(v->point(), uvg);
      }
      if(proj.succeeded()) {
        v->setXYZ(proj.x(), proj.y(), proj.z());
        v->setParameter(0, proj.u());
        v->setParameter(1, proj.v());
      }
      else {
        Msg::Warning("- Face %i, vertex %li: surface projection failed",
                     gf->tag(), v->getNum());
      }
    }

    /* Delete the surface */
    if(sp) delete sp;
  }

/* Update elements */
#pragma omp parallel for schedule(dynamic) num_threads(nthreads)
  for(size_t e = 0; e < edges.size(); ++e) {
    GEdge *ge = edges[e];
    for(MLine *l : ge->lines) {
      for(size_t lv = 0; lv < 2; ++lv) {
        MVertex *v = l->getVertex(lv);
        auto it = old2new.find(v);
        if(it != old2new.end()) { l->setVertex(lv, it->second); }
      }
    }
  }

#pragma omp parallel for schedule(dynamic) num_threads(nthreads)
  for(size_t f = 0; f < faces.size(); ++f) {
    GFace *gf = faces[f];
    for(size_t i = 0; i < gf->getNumMeshElements(); ++i) {
      MElement *e = gf->getMeshElement(i);
      for(size_t lv = 0; lv < e->getNumVertices(); ++lv) {
        MVertex *v = e->getVertex(lv);
        auto it2 = old2new.find(v);
        if(it2 != old2new.end()) { e->setVertex(lv, it2->second); }
      }
    }
  }

  if(PARANO_VALIDITY) {
    errorAndAbortIfInvalidVertexInModel(gm, "after refine + proj");
  }

  if(DBG_EXPORT) { gm->writeMSH("qqs_subdiv.msh", 4.1); }

  optimizeGeometryQuadqs(gm);

  if(true || Msg::GetVerbosity() >= 99) {
    std::unordered_map<std::string, double> stats;
    appendQuadMeshStatistics(gm, stats, "Mesh_");
    printStatistics(
      stats, "Quad mesh after subdivision, projection and small smoothing:");
  }

  return 0;
}

int RefineMeshWithBackgroundMeshProjection(GModel *gm)
{
  return RefineMeshWithBackgroundMeshProjectionSimple(gm);

  const bool USE_CAD_PROJECTION = false;
  if(USE_CAD_PROJECTION) {
    // Problem: it is slow and buggy on periodic CAD
    Msg::Info("Refine mesh (midpoint subdivision, with CAD projection) ...");
    bool linear = false;
    RefineMesh(gm, linear, true, false);

    std::unordered_map<std::string, double> stats;
    appendQuadMeshStatistics(gm, stats, "Mesh_");
    printStatistics(stats, "Quad mesh after subdivision with CAD projection:");

    return 0;
  }

  const bool SHOW_INTERMEDIATE_VIEWS = (Msg::GetVerbosity() >= 99);
  if(SHOW_INTERMEDIATE_VIEWS) {
    std::vector<MElement *> elements;
    for(GFace *gf : model_faces(gm)) {
      append(elements,
             dynamic_cast_vector<MTriangle *, MElement *>(gf->triangles));
      append(elements,
             dynamic_cast_vector<MQuadrangle *, MElement *>(gf->quadrangles));
    }
    GeoLog::add(elements, "qqs_quadtri");
    GeoLog::flush();
  }
  if(DBG_EXPORT) { gm->writeMSH("qqs_init.msh", 4.1); }

  Msg::Info(
    "Refine mesh (midpoint subdivision, with background projection) ...");

  bool linear = true;
  RefineMesh(gm, linear, true, false);

  if(Msg::GetVerbosity() >= 99) {
    std::unordered_map<std::string, double> stats;
    appendQuadMeshStatistics(gm, stats, "MPS_");
    printStatistics(stats, "Quad mesh after subdivision, before projection:");
    if(DBG_EXPORT) { gm->writeMSH("qqs_subdiv_noproj.msh", 4.1); }
  }

  /* Convert vertex types:
   * - MVertex on curve -> MEdgeVertex
   * - MVertex on face  -> MFaceVertex */
  std::vector<GEdge *> edges = model_edges(gm);
  std::vector<GFace *> faces = model_faces(gm);
  /* Build custom edgeToFaces because ge->faces() does not work
   * for embedded edges */
  std::unordered_map<GEdge *, std::vector<MVertex *> > toProjectOnCurve;
  std::unordered_map<GFace *, std::vector<MVertex *> > toProjectOnFace;
  std::unordered_map<GEdge *, std::unordered_set<GFace *> > edgeToFaces;
  for(GFace *gf : model_faces(gm)) {
    std::vector<GEdge *> fedges = face_edges(gf);
    for(GEdge *ge : fedges) edgeToFaces[ge].insert(gf);
  }

  int nthreads = getNumThreads();
#pragma omp parallel for schedule(dynamic) num_threads(nthreads)
  for(size_t e = 0; e < edges.size(); ++e) {
    GEdge *ge = edges[e];
    if(CTX::instance()->mesh.meshOnlyVisible && !ge->getVisibility()) continue;
    if(ge->lines.size() == 0 || ge->mesh_vertices.size() == 0) continue;
    unordered_map<MVertex *, MVertex *> old2new_ge;
    std::vector<MVertex *> &projList = toProjectOnCurve[ge];
    projList.reserve(ge->mesh_vertices.size());
    for(size_t i = 0; i < ge->mesh_vertices.size(); ++i) {
      MVertex *v = ge->mesh_vertices[i];
      MEdgeVertex *mev = dynamic_cast<MEdgeVertex *>(v);
      if(mev == nullptr) {
        MVertex *v2 = new MEdgeVertex(v->point().x(), v->point().y(),
                                      v->point().z(), ge, 0.);
        ge->mesh_vertices[i] = v2;
        old2new_ge[v] = v2;
        projList.push_back(v2);
        delete v;
      }
    }
    /* Update lines */
    for(MLine *l : ge->lines) {
      for(size_t lv = 0; lv < 2; ++lv) {
        MVertex *v = l->getVertex(lv);
        auto it = old2new_ge.find(v);
        if(it != old2new_ge.end()) { l->setVertex(lv, it->second); }
      }
    }
    /* Update elements in adjacent faces */
    for(GFace *gf : edgeToFaces[ge]) {
      for(size_t i = 0; i < gf->getNumMeshElements(); ++i) {
        MElement *e = gf->getMeshElement(i);
        for(size_t lv = 0; lv < e->getNumVertices(); ++lv) {
          MVertex *v = e->getVertex(lv);
          auto it = old2new_ge.find(v);
          if(it != old2new_ge.end()) { e->setVertex(lv, it->second); }
        }
      }
    }
  }

#pragma omp parallel for schedule(dynamic) num_threads(nthreads)
  for(size_t f = 0; f < faces.size(); ++f) {
    GFace *gf = faces[f];
    if(CTX::instance()->mesh.meshOnlyVisible && !gf->getVisibility()) continue;
    if(CTX::instance()->debugSurface > 0 &&
       gf->tag() != CTX::instance()->debugSurface)
      continue;
    if(gf->triangles.size() == 0 && gf->quadrangles.size() == 0) continue;
    unordered_map<MVertex *, MVertex *> old2new_gf;
    std::vector<MVertex *> &projList = toProjectOnFace[gf];
    projList.reserve(gf->mesh_vertices.size());
    for(size_t i = 0; i < gf->mesh_vertices.size(); ++i) {
      MVertex *v = gf->mesh_vertices[i];
      if(v->onWhat() != gf) {
        Msg::Error("- Face %i: vertex %li is associated to entity (%i,%i)",
                   gf->tag(), v->getNum(), v->onWhat()->dim(),
                   v->onWhat()->tag());
        continue;
      }
      MFaceVertex *mfv = dynamic_cast<MFaceVertex *>(v);
      if(mfv == nullptr) {
        MVertex *v2 = new MFaceVertex(v->point().x(), v->point().y(),
                                      v->point().z(), gf, 0., 0.);
        gf->mesh_vertices[i] = v2;
        old2new_gf[v] = v2;
        projList.push_back(v2);
        delete v;
      }
    }
    /* Update elements */
    for(size_t i = 0; i < gf->getNumMeshElements(); ++i) {
      MElement *e = gf->getMeshElement(i);
      for(size_t lv = 0; lv < e->getNumVertices(); ++lv) {
        MVertex *v = e->getVertex(lv);
        auto it2 = old2new_gf.find(v);
        if(it2 != old2new_gf.end()) { e->setVertex(lv, it2->second); }
      }
    }
  }

/* Geometric projection on model */

/* - projections on curves */
#pragma omp parallel for schedule(dynamic) num_threads(nthreads)
  for(size_t e = 0; e < edges.size(); ++e) {
    GEdge *ge = edges[e];
    auto it = toProjectOnCurve.find(ge);
    if(it == toProjectOnCurve.end()) continue;

    double tMin = ge->parBounds(0).low();
    double tMax = ge->parBounds(0).high();

    for(size_t j = 0; j < it->second.size(); ++j) {
      MVertex *v = it->second[j];
      double tGuess =
        tMin + (tMax - tMin) * double(j + 1) / double(it->second.size() + 1);
      GPoint proj = ge->closestPoint(v->point(), tGuess);
      if(proj.succeeded()) {
        v->setXYZ(proj.x(), proj.y(), proj.z());
        v->setParameter(0, proj.u());
      }
      else {
        Msg::Warning("- Edge %i, vertex %li: curve projection failed",
                     ge->tag(), v->getNum());
      }
    }
  }

  GlobalBackgroundMesh *bmesh = nullptr;
  if(backgroudMeshExists(BMESH_NAME)) {
    bmesh = &(getBackgroundMesh(BMESH_NAME));
  }
  else {
    Msg::Warning("refine mesh with background projection: no background mesh, "
                 "using CAD projection (slow)");
  }

/* - projections on faces */
#pragma omp parallel for schedule(dynamic) num_threads(nthreads)
  for(size_t f = 0; f < faces.size(); ++f) {
    GFace *gf = faces[f];

    auto it = toProjectOnFace.find(gf);
    if(it == toProjectOnFace.end()) continue;

    Msg::Info("- Face %i: project %li vertices and smooth the quad mesh ...",
              gf->tag(), it->second.size());

    SurfaceProjector *sp = nullptr;
    if(bmesh) {
      auto it2 = bmesh->faceBackgroundMeshes.find(gf);
      if(it2 == bmesh->faceBackgroundMeshes.end()) {
        Msg::Error("background mesh not found for face %i", gf->tag());
      }
      else {
        /* Get pointers to triangles in the background mesh */
        std::vector<MTriangle *> triangles(it2->second.triangles.size());
        for(size_t i = 0; i < it2->second.triangles.size(); ++i) {
          triangles[i] = &(it2->second.triangles[i]);
        }

        sp = new SurfaceProjector();
        bool oki = sp->initialize(gf, triangles);
        if(!oki) {
          Msg::Warning("failed to initialize surface projector");
          delete sp;
          sp = nullptr;
        }
      }
    }

    /* Project the vertices */
    bool evalOnCAD = false;
    bool projOnCad = false;
    if(gf->haveParametrization() && haveNiceParametrization(gf))
      evalOnCAD = true;
    for(size_t j = 0; j < it->second.size(); ++j) {
      MVertex *v = it->second[j];
      GPoint proj;
      if(sp != nullptr) {
        proj = sp->closestPoint(v->point().data(), evalOnCAD, projOnCad);
        if(!proj.succeeded() && gf->haveParametrization()) {
          double uvg[2] = {0., 0.};
          proj = gf->closestPoint(v->point(), uvg);
        }
      }
      else {
        double uvg[2] = {0., 0.};
        proj = gf->closestPoint(v->point(), uvg);
      }
      if(proj.succeeded()) {
        v->setXYZ(proj.x(), proj.y(), proj.z());
        v->setParameter(0, proj.u());
        v->setParameter(1, proj.v());
      }
      else {
        Msg::Warning("- Face %i, vertex %li: surface projection failed",
                     gf->tag(), v->getNum());
      }
    }

    /* Quad mesh smoothing */
    double timeMax = 0.3;
    optimizeGeometryQuadMesh(gf, sp, timeMax);
    double sicnMin, sicnAvg;
    computeSICN(dynamic_cast_vector<MQuadrangle *, MElement *>(gf->quadrangles),
                sicnMin, sicnAvg);
    if(sicnMin < 0.) {
      double timeMax = 2.;
      optimizeGeometryQuadMesh(gf, sp, timeMax);
    }

    if(sp) delete sp;
  }

  if(SHOW_INTERMEDIATE_VIEWS) {
    std::vector<MElement *> elements;
    for(GFace *gf : model_faces(gm)) {
      append(elements,
             dynamic_cast_vector<MQuadrangle *, MElement *>(gf->quadrangles));
      // showUVParametrization(gf,dynamic_cast_vector<MQuadrangle*,MElement*>(gf->quadrangles),"quad_uvs");
    }
    GeoLog::add(elements, "qqs_quadinit");
    GeoLog::flush();
  }

  if(true || Msg::GetVerbosity() >= 99) {
    std::unordered_map<std::string, double> stats;
    appendQuadMeshStatistics(gm, stats, "Mesh_");
    printStatistics(
      stats, "Quad mesh after subdivision, projection and small smoothing:");
  }

  if(PARANO_VALIDITY) {
    errorAndAbortIfInvalidVertexInModel(gm, "after refine + proj");
  }

  if(DBG_EXPORT) { gm->writeMSH("qqs_subdiv.msh", 4.1); }

  return 0;
}

int checkAndReplaceQuadDominantMesh(GFace *gf, int valenceMaxBdr = 6,
                                    int valenceMaxIn = 8)
{
  /* Check valence */
  unordered_map<MVertex *, int> valence;
  for(MQuadrangle *q : gf->quadrangles)
    for(size_t lv = 0; lv < 4; ++lv) { valence[q->getVertex(lv)] += 1; }
  for(MTriangle *t : gf->triangles)
    for(size_t lv = 0; lv < 3; ++lv) { valence[t->getVertex(lv)] += 1; }
  int vMaxInt = 0;
  int vMaxBdr = 0;
  for(auto &kv : valence) {
    if(kv.first->onWhat() == gf) { vMaxInt = std::max(vMaxInt, kv.second); }
    else if(kv.first->onWhat()->cast2Edge() != nullptr) {
      vMaxBdr = std::max(vMaxBdr, kv.second);
    }
  }
  if(vMaxInt <= valenceMaxIn && vMaxBdr <= valenceMaxBdr) return 0;

  Msg::Warning("- Face %i: quad-tri mesh have valence %i (interior) and %i "
               "(bdr), replace it with meshadapt ...",
               gf->tag(), vMaxInt, vMaxBdr);

  int algo2d = gf->getMeshingAlgo();
  gf->setMeshingAlgo(ALGO_2D_MESHADAPT);
  gf->mesh(false);
  gf->setMeshingAlgo(algo2d);

  if(gf->meshStatistics.status != GFace::DONE) {
    Msg::Warning("- Face %i: failed to build triangulation", gf->tag());
    return -1;
  }

  /* Recombine triangles in quads */
  recombineIntoQuads(gf, false, 0, false, .1);

  return 0;
}

int replaceBadQuadDominantMeshes(GModel *gm)
{
  std::vector<GFace *> faces = model_faces(gm);

  int nthreads = getNumThreads();
#pragma omp parallel for schedule(dynamic) num_threads(nthreads)
  for(size_t f = 0; f < faces.size(); ++f) {
    GFace *gf = faces[f];
    if(CTX::instance()->mesh.meshOnlyVisible && !gf->getVisibility()) continue;
    if(CTX::instance()->debugSurface > 0 &&
       gf->tag() != CTX::instance()->debugSurface)
      continue;
    if(gf->getNumMeshElements() == 0) continue;

    int st = checkAndReplaceQuadDominantMesh(gf);
    if(st != 0) {
      Msg::Warning("- Face %i: failed to replace bad quad-tri mesh", gf->tag());
    }
  }

  return 0;
}

int optimizeQuadMeshWithDiskQuadrangulationRemeshing(GFace *gf)
{
  if(gf->triangles.size() > 0 || gf->quadrangles.size() == 0) return -1;

  // Disk quadrangulation remeshing use the CAD normals to compute the signed
  // quality, so the orientation is important.
  bool invertNormals = meshOrientationIsOppositeOfCadOrientation(gf);

  /* For each bdr vertex, compute the ideal valence (based on angle viewed from
   * the face) */
  unordered_map<MVertex *, double> qValIdeal;
  computeBdrVertexIdealValence(gf->quadrangles, qValIdeal);

  /* Vertex to quads */
  unordered_map<MVertex *, std::vector<MElement *> > adj;
  for(MQuadrangle *f : gf->quadrangles)
    for(size_t lv = 0; lv < 4; ++lv) {
      MVertex *v = f->getVertex(lv);
      adj[v].push_back(f);
    }

  DQStats stats;
  DQOptions opt;
  opt.invertNormalsForQuality = invertNormals;
  bool alwaysBuildSurfaceProjector = true;
  if(alwaysBuildSurfaceProjector || !haveNiceParametrization(gf) ||
     (gf->periodic(0) || gf->periodic(1))) {
    opt.sp = new SurfaceProjector();
    bool okf = fillSurfaceProjector(gf, opt.sp);
    if(!okf) {
      Msg::Error("- Face %i: failed to get a surface projector", gf->tag());
      return false;
    }
  }

  if(SHOW_DQR) {
    for(auto &kv : qValIdeal) {
      GeoLog::add(kv.first->point(), std::round(kv.second),
                  "f_" + std::to_string(gf->tag()) + "_val_ideal");
    }
    GeoLog::flush();
  }

  double t1 = Cpu();

  const bool ENABLE_CORNER = true;
  const bool ENABLE_CURVE = true;

  if(ENABLE_CORNER) {
    int sc = improveCornerValences(gf, qValIdeal, adj, opt, stats);
    if(sc != 0) {
      Msg::Warning("optimize quad topology: failed to improve corner valences");
    }
    if(PARANO_QUALITY) {
      errorAndAbortIfNegativeElement(
        gf, dynamic_cast_vector<MQuadrangle *, MElement *>(gf->quadrangles),
        "after corner");
    }
  }

  if(ENABLE_CURVE) {
    int scu = improveCurveValences(gf, qValIdeal, adj, opt, stats);
    if(scu != 0) {
      Msg::Warning("optimize quad topology: failed to improve curve valences");
    }
    if(PARANO_QUALITY) {
      errorAndAbortIfNegativeElement(
        gf, dynamic_cast_vector<MQuadrangle *, MElement *>(gf->quadrangles),
        "after curve");
    }
  }

  int sci = improveInteriorValencesV2(gf, qValIdeal, adj, opt, stats);
  if(sci != 0) {
    Msg::Warning("optimize quad topology: failed to improve interior valences");
  }
  if(PARANO_QUALITY) {
    errorAndAbortIfNegativeElement(
      gf, dynamic_cast_vector<MQuadrangle *, MElement *>(gf->quadrangles),
      "after interior");
  }

  /* Smooth geometry (quick) */
  double timeMax = 0.3;
  optimizeGeometryQuadMesh(gf, opt.sp, timeMax);

  if(opt.sp) {
    delete opt.sp;
    opt.sp = nullptr;
  }

  double t2 = Cpu();

  Msg::Info("- Face %i: disk quadrangulation remeshing, improved valence on "
            "%li/%li/%li corner/curve/surface vertices (in %.3f sec), "
            "remaining non-ideal: %li/%li/%li",
            gf->tag(), stats.nCornerValFixed, stats.nCurveValFixed,
            stats.nSurfaceValFixed, t2 - t1, stats.nCornerValRemaining,
            stats.nCurveValRemaining, stats.nSurfaceValRemaining);

  if(PARANO_QUALITY) {
    errorAndAbortIfNegativeElement(
      gf, dynamic_cast_vector<MQuadrangle *, MElement *>(gf->quadrangles),
      "after geom optim");
  }

  return 0;
}

int insertExtrudedBoundaryLayer(
  GFace *gf, const std::vector<MVertex *> &loop,
  const unordered_map<MVertex *, std::vector<MElement *> > &adj)
{
  if(loop.size() < 2) return -1;
  unordered_map<MVertex *, MVertex *> extrusion;
  for(size_t i = 0; i < loop.size(); ++i) {
    if(i > 0 && i == loop.size() - 1 && loop[i] == loop[0]) continue;
    MVertex *v = loop[i];
    auto it = adj.find(v);
    if(it == adj.end()) {
      Msg::Error("insert extruded layer: vertex not found in adj");
      return -1;
    }

    /* Create extruded vertex */
    SPoint3 pos = v->point();
    double sum = 1.;
    SPoint2 uv(0., 0.);
    double sumuv = 0.;
    for(auto &q : it->second) {
      for(size_t lv = 0; lv < 4; ++lv) {
        MVertex *qv = q->getVertex(lv);
        MFaceVertex *mfv = dynamic_cast<MFaceVertex *>(qv);
        if(mfv) {
          double u, v;
          mfv->getParameter(0, u);
          mfv->getParameter(1, v);
          uv = uv + SPoint2(u, v);
          sumuv += 1.;
        }
      }
      pos = pos + q->barycenter();
      sum += 1.;
    }
    if(sum > 0.) pos = pos * double(1. / sum);
    if(sumuv > 0.) uv = uv * double(1. / sumuv);

    MVertex *v2 =
      new MFaceVertex(pos.x(), pos.y(), pos.z(), gf, uv.x(), uv.y());
    gf->mesh_vertices.push_back(v2);
    gf->model()->addMVertexToVertexCache(v2);
    extrusion[v] = v2;

    /* Update adjacent quads */
    for(auto &q : it->second) {
      for(size_t lv = 0; lv < 4; ++lv) {
        MVertex *qv = q->getVertex(lv);
        if(qv == v) { q->setVertex(lv, v2); }
      }
    }
  }

  /* Create new quads */
  for(size_t i = 0; i < loop.size(); ++i) {
    MVertex *v0 = loop[i];
    MVertex *v1 = loop[(i + 1) % loop.size()];
    if(v0 == v1) continue;
    MVertex *v2 = extrusion[v1];
    MVertex *v3 = extrusion[v0];
    MQuadrangle *nq = new MQuadrangle(v0, v1, v2, v3);
    gf->quadrangles.push_back(nq);
  }

  return 0;
}

int optimizeFaceQuadMeshBoundaries(GFace *gf, bool ignoreAcuteCorners = false)
{
  if(gf->triangles.size() > 0 || gf->quadrangles.size() == 0) return -1;

  size_t nv = gf->mesh_vertices.size();
  size_t nq = gf->quadrangles.size();

  double minSICNb = DBL_MAX;
  double avgSICNb = 0.;
  std::vector<MElement *> elts =
    dynamic_cast_vector<MQuadrangle *, MElement *>(gf->quadrangles);
  computeSICN(elts, minSICNb, avgSICNb);
  std::vector<std::array<MVertex *, 4> > quadsInit(gf->quadrangles.size());
  for(size_t i = 0; i < gf->quadrangles.size(); ++i)
    for(size_t lv = 0; lv < 4; ++lv) {
      quadsInit[i][lv] = gf->quadrangles[i]->getVertex(lv);
    }
  std::vector<SPoint3> positionsInit(gf->mesh_vertices.size());
  for(size_t i = 0; i < gf->mesh_vertices.size(); ++i)
    positionsInit[i] = gf->mesh_vertices[i]->point();

  /* For each bdr vertex, compute the ideal valence (based on angle viewed from
   * the face) */
  unordered_map<MVertex *, double> qValIdeal;
  computeBdrVertexIdealValence(gf->quadrangles, qValIdeal);

  /* Face boundary loops */
  std::vector<std::vector<MVertex *> > loops;
  bool okb = buildBoundaries(elts, loops);
  if(!okb) {
    Msg::Warning("failed to build boundary loops on face %i", gf->tag());
    return -1;
  }

  /* Vertex to quads */
  unordered_map<MVertex *, std::vector<MElement *> > adj;
  for(MQuadrangle *f : gf->quadrangles)
    for(size_t lv = 0; lv < 4; ++lv) {
      MVertex *v = f->getVertex(lv);
      adj[v].push_back(f);
    }

  /* Check if valences are not right on a loop */
  size_t nlayer = 0;
  for(size_t i = 0; i < loops.size(); ++i) {
    bool goodAcute = false;
    bool loopIsGood = true;
    for(MVertex *v : loops[i]) {
      auto it = adj.find(v);
      if(it == adj.end()) continue;
      size_t val = it->second.size();

      auto iti = qValIdeal.find(v);
      if(iti == qValIdeal.end()) continue;
      size_t ival = idealBoundaryValence(iti->first, iti->second);

      if(val != ival) { loopIsGood = false; }

      if(val == ival && iti->second < 0.5) { goodAcute = true; }
    }

    if(ignoreAcuteCorners && goodAcute) continue;

    /* Add a layer */
    if(!loopIsGood) {
      insertExtrudedBoundaryLayer(gf, loops[i], adj);
      nlayer += 1;
    }
  }

  if(nlayer > 0) {
    double timeMax = 1;
    SurfaceProjector sp;
    fillSurfaceProjector(gf, &sp);
    optimizeGeometryQuadMesh(gf, &sp, timeMax);

    double minSICNa = DBL_MAX;
    double avgSICNa = 0.;
    std::vector<MElement *> eltsa =
      dynamic_cast_vector<MQuadrangle *, MElement *>(gf->quadrangles);
    computeSICN(eltsa, minSICNa, avgSICNa);

    if(minSICNa <= 0. && minSICNa <= minSICNb) {
      Msg::Warning("- Face %i: worst quality (%.3f -> %.3f) after adding %li "
                   "extruded boundary layers, restore",
                   gf->tag(), minSICNb, minSICNa, nlayer);
      /* Delete added vertices */
      for(size_t v = nv; v < gf->mesh_vertices.size(); ++v) {
        delete gf->mesh_vertices[v];
      }
      gf->mesh_vertices.resize(nv);
      /* Restore positions */
      for(size_t i = 0; i < gf->mesh_vertices.size(); ++i) {
        gf->mesh_vertices[i]->setXYZ(positionsInit[i]);
      }
      /* Delete added quads */
      for(size_t f = nq; f < gf->quadrangles.size(); ++f) {
        delete gf->quadrangles[f];
      }
      gf->quadrangles.resize(nq);
      /* Restore quad vertices */
      for(size_t i = 0; i < gf->quadrangles.size(); ++i)
        for(size_t lv = 0; lv < 4; ++lv) {
          gf->quadrangles[i]->setVertex(lv, quadsInit[i][lv]);
        }
      return 1;
    }
    Msg::Info("- Face %i: added %li extruded boundary layers", gf->tag(),
              nlayer);
  }

  return 0;
}

int ensureEvenNumberOfEdgesOnCurvesAfterInitialSurfaceMesh(GModel *gm)
{
  Msg::Info("Generating empty surface meshes ...");

  int algo2d = CTX::instance()->mesh.algo2d;
  CTX::instance()->mesh.algo2d = ALGO_2D_INITIAL_ONLY;

  std::vector<GFace *> faces = model_faces(gm);
  int nIter = 0;
  while(1) {
    int nPending = 0;
    for(size_t f = 0; f < faces.size(); ++f) {
      GFace *gf = faces[f];
      if(gf->meshStatistics.status != GFace::PENDING) continue;
      if(CTX::instance()->mesh.meshOnlyVisible && !gf->getVisibility())
        continue;
      if(CTX::instance()->debugSurface > 0 &&
         gf->tag() != CTX::instance()->debugSurface)
        continue;
      nPending += 1;
      backgroundMesh::current()->unset();

      /* Initial mesh only */
      char method = gf->meshAttributes.method;
      int algo = gf->meshAttributes.algorithm;
      if(method == 1) { /* remove transfinite property */
        gf->meshAttributes.method = MESH_UNSTRUCTURED;
      }
      gf->meshAttributes.algorithm = ALGO_2D_INITIAL_ONLY;
      gf->mesh(true);
      gf->meshAttributes.algorithm = algo;
      gf->meshAttributes.method = method;
    }
    if(!nPending) break;
    if(nIter++ > CTX::instance()->mesh.maxRetries) break;
  }
  CTX::instance()->mesh.algo2d = algo2d;

  /* Remove the meshes */
  std::vector<GEdge *> edges;

  Msg::Info("Deleting empty surface meshes ...");
  for(size_t f = 0; f < faces.size(); ++f) {
    GFace *gf = faces[f];
    if(CTX::instance()->mesh.meshOnlyVisible && !gf->getVisibility()) continue;
    if(CTX::instance()->debugSurface > 0 &&
       gf->tag() != CTX::instance()->debugSurface)
      continue;
    if(gf->meshStatistics.status == GFace::PENDING) {
      Msg::Warning("- Face %i not meshed !", gf->tag());
    }
    deMeshGFace killer;
    killer(gf);

    append(edges, gf->edges()); /* face edges saved to verify nb of edges */
  }
  Msg::Info("done.");

  /* Verify the curves */
  sort_unique(edges);
  for(size_t e = 0; e < edges.size(); ++e) {
    GEdge *ge = edges[e];
    if(ge->lines.size() % 2 != 0) {
      Msg::Warning(
        "- Curve %i has %li lines (due to boundary recovery), splitting one",
        ge->tag(), ge->lines.size());
      size_t i = ge->lines.size() / 2;
      MLine *l = ge->lines[i];
      MVertex *v1 = l->getVertex(0);
      MVertex *v2 = l->getVertex(1);
      double t1, t2;
      v1->getParameter(0, t1);
      v2->getParameter(0, t2);
      double t = 0.5 * (t1 + t2);
      SPoint3 mid = (v1->point() + v2->point()) * 0.5;
      GPoint proj = ge->closestPoint(mid, t);
      if(!proj.succeeded()) { /* force values */
        proj.x() = mid.x();
        proj.y() = mid.y();
        proj.z() = mid.z();
        t = 0.5 * (t1 + t2);
      }
      MEdgeVertex *mev1 = dynamic_cast<MEdgeVertex *>(v1);
      MEdgeVertex *mev2 = dynamic_cast<MEdgeVertex *>(v2);
      double lc = -1.;
      if(mev1 && mev2) { lc = 0.5 * (mev1->getLc() + mev2->getLc()); }
      else if(mev1) {
        lc = mev1->getLc();
      }
      else if(mev2) {
        lc = mev2->getLc();
      }
      MEdgeVertex *newv =
        new MEdgeVertex(proj.x(), proj.y(), proj.z(), ge, t, 0, lc);
      ge->mesh_vertices.push_back(newv);
      ge->lines[i] = new MLine(v1, newv);
      ge->lines.push_back(new MLine(newv, v2));
      delete l;
    }
  }

  /* Undo transfinite which are no longer possibles */
  for(size_t f = 0; f < faces.size(); ++f) {
    GFace *gf = faces[f];
    if(CTX::instance()->mesh.meshOnlyVisible && !gf->getVisibility()) continue;
    if(CTX::instance()->debugSurface > 0 &&
       gf->tag() != CTX::instance()->debugSurface)
      continue;
    if(gf->meshAttributes.method == MESH_TRANSFINITE &&
       gf->edges().size() == 4) {
      std::vector<size_t> sizes;
      for(GEdge *ge : gf->edges()) { sizes.push_back(ge->lines.size()); }
      std::sort(sizes.begin(), sizes.end());
      if(sizes.size() != 4 || sizes[0] != sizes[1] || sizes[2] != sizes[3]) {
        Msg::Warning(
          "- Face %i: transfinite no longer possible, remove the attribute",
          gf->tag());
        gf->meshAttributes.method = MESH_UNSTRUCTURED;
      }
    }
  }

  return 0;
}

int quadMeshingOfSimpleFacesWithPatterns(GModel *gm,
                                         double minimumQualityRequired)
{
  if(CTX::instance()->mesh.quadqsTopoOptimMethods != 0 &&
     CTX::instance()->mesh.quadqsTopoOptimMethods != 100 &&
     CTX::instance()->mesh.quadqsTopoOptimMethods != 101 &&
     CTX::instance()->mesh.quadqsTopoOptimMethods != 110 &&
     CTX::instance()->mesh.quadqsTopoOptimMethods != 111) {
    Msg::Debug("optimize topology of simple CAD faces with patterns: avoided "
               "because quadqsTopoOptimMethods = %i",
               CTX::instance()->mesh.quadqsTopoOptimMethods);
    return 0;
  }

  std::vector<GFace *> faces = model_faces(gm);
  Msg::Info("Pattern-based quad meshing of simple CAD faces ...", faces.size());

  initQuadPatterns();

  int nthreads = getNumThreads();
#pragma omp parallel for schedule(dynamic) num_threads(nthreads)
  for(size_t f = 0; f < faces.size(); ++f) {
    GFace *gf = faces[f];
    if(gf->meshStatistics.status != GFace::PENDING) continue;
    if(CTX::instance()->mesh.meshOnlyVisible && !gf->getVisibility()) continue;
    if(CTX::instance()->debugSurface > 0 &&
       gf->tag() != CTX::instance()->debugSurface)
      continue;
    if(gf->triangles.size() > 0 || gf->quadrangles.size() == 0) continue;
    if(gf->embeddedEdges().size() > 0 || gf->embeddedVertices().size() > 0)
      continue;

    bool invertNormals = meshOrientationIsOppositeOfCadOrientation(gf);
    meshFaceWithGlobalPattern(gf, invertNormals, minimumQualityRequired);

    if(PARANO_VALIDITY) {
      errorAndAbortIfInvalidSurfaceMesh(gf, "after mesh with global pattern");
    }
  }

  std::unordered_map<std::string, double> stats;
  appendQuadMeshStatistics(gm, stats, "Mesh_");
  printStatistics(stats,
                  "Quad mesh after simple face pattern-based remeshing:");

  if(PARANO_VALIDITY) {
    errorAndAbortIfInvalidVertexInModel(
      gm, "global check after face pattern meshing");
  }

  if(DBG_EXPORT) { gm->writeMSH("qqs_simplefaces.msh", 4.1); }

  return 0;
}

int optimizeTopologyWithDiskQuadrangulationRemeshing(GModel *gm)
{
  if(CTX::instance()->mesh.quadqsTopoOptimMethods != 0 &&
     CTX::instance()->mesh.quadqsTopoOptimMethods != 10 &&
     CTX::instance()->mesh.quadqsTopoOptimMethods != 11 &&
     CTX::instance()->mesh.quadqsTopoOptimMethods != 110 &&
     CTX::instance()->mesh.quadqsTopoOptimMethods != 111) {
    Msg::Debug("optimize topology with disk quadrangulation remeshing: avoided "
               "because quadqsTopoOptimMethods = %i",
               CTX::instance()->mesh.quadqsTopoOptimMethods);
    return 0;
  }

  Msg::Info(
    "Optimize topology of quad meshes with disk quadrangulation remeshing ...");

  initDiskQuadrangulations();

  std::vector<GFace *> faces = model_faces(gm);

  int nthreads = getNumThreads();
#pragma omp parallel for schedule(dynamic) num_threads(nthreads)
  for(size_t f = 0; f < faces.size(); ++f) {
    GFace *gf = faces[f];
    if(gf->meshStatistics.status != GFace::PENDING) continue;
    if(CTX::instance()->mesh.meshOnlyVisible && !gf->getVisibility()) continue;
    if(CTX::instance()->debugSurface > 0 &&
       gf->tag() != CTX::instance()->debugSurface)
      continue;
    if(gf->triangles.size() > 0 || gf->quadrangles.size() == 0) continue;

    optimizeQuadMeshWithDiskQuadrangulationRemeshing(gf);

    if(PARANO_VALIDITY) {
      errorAndAbortIfInvalidSurfaceMesh(gf,
                                        "after disk quadrangulation remeshing");
    }
  }

  std::unordered_map<std::string, double> stats;
  appendQuadMeshStatistics(gm, stats, "Mesh_");
  printStatistics(stats, "Quad mesh after disk quadrangulation remeshing:");

  if(stats["Mesh_SICN_min"] < 0.) {
    Msg::Warning("negative quality on some quads");
  }

  if(PARANO_VALIDITY) {
    errorAndAbortIfInvalidVertexInModel(
      gm, "global check after disk quadrangulation remeshing");
  }

  if(DBG_EXPORT) { gm->writeMSH("qqs_diskrmsh.msh", 4.1); }

  return 0;
}

int optimizeTopologyWithCavityRemeshing(GModel *gm)
{
  if(CTX::instance()->mesh.quadqsTopoOptimMethods != 0 &&
     CTX::instance()->mesh.quadqsTopoOptimMethods != 1 &&
     CTX::instance()->mesh.quadqsTopoOptimMethods != 11 &&
     CTX::instance()->mesh.quadqsTopoOptimMethods != 101 &&
     CTX::instance()->mesh.quadqsTopoOptimMethods != 111) {
    Msg::Debug("optimize topology with cavity remeshing: avoided because "
               "quadqsTopoOptimMethods = %i",
               CTX::instance()->mesh.quadqsTopoOptimMethods);
    return 0;
  }

  std::vector<GFace *> faces = model_faces(gm);
  Msg::Info(
    "Optimize topology of quad meshes with cavity remeshing (%li faces) ...",
    faces.size());

  initQuadPatterns();

  if(!backgroudMeshExists(BMESH_NAME)) {
    Msg::Info("no background mesh, creating one with the current quad mesh");
    GlobalBackgroundMesh &bmesh = getBackgroundMesh(BMESH_NAME);
    int status = bmesh.importGModelMeshes(gm, true);
    if(status != 0) {
      Msg::Error("failed to import model mesh in background mesh");
      return -1;
    }
  }

  GlobalBackgroundMesh &bmesh = getBackgroundMesh(BMESH_NAME);

  int nthreads = getNumThreads();
#pragma omp parallel for schedule(dynamic) num_threads(nthreads)
  for(size_t f = 0; f < faces.size(); ++f) {
    GFace *gf = faces[f];
    if(gf->meshStatistics.status != GFace::PENDING) continue;
    if(CTX::instance()->mesh.meshOnlyVisible && !gf->getVisibility()) continue;
    if(CTX::instance()->debugSurface > 0 &&
       gf->tag() != CTX::instance()->debugSurface)
      continue;
    if(gf->triangles.size() > 0 || gf->quadrangles.size() == 0) continue;
    gf->meshStatistics.status = GFace::DONE;

    /* Get singularities from global storage */
    std::vector<std::pair<SPoint3, int> > singularities;
    bool okg = getSingularitiesFromBackgroundField(gf, singularities);
    if(!okg) {
      okg = getSingularitiesFromNewCrossFieldComputation(bmesh, gf,
              singularities);
      if(!okg) {
          Msg::Warning("- Face %i: failed to get singularities", gf->tag());
      }
    }

    bool invertNormals = meshOrientationIsOppositeOfCadOrientation(gf);
    improveQuadMeshTopologyWithCavityRemeshing(gf, singularities,
                                               invertNormals);

    if(PARANO_VALIDITY) {
      errorAndAbortIfInvalidSurfaceMesh(gf, "after cavity remeshing");
    }
  }

  std::unordered_map<std::string, double> stats;
  appendQuadMeshStatistics(gm, stats, "Mesh_");
  printStatistics(stats, "Quad mesh after cavity remeshing:");

  if(Msg::GetVerbosity() > 5)
    writeStatistics(stats, "quadqs_statistics.json");

  if(PARANO_VALIDITY) {
    errorAndAbortIfInvalidVertexInModel(gm,
                                        "global check after cavity remeshing");
  }

  GeoLog::flush();

  if(DBG_EXPORT) { gm->writeMSH("qqs_cavrmsh.msh", 4.1); }

  return 0;
}

int optimizeQuadMeshBoundaries(GModel *gm)
{
  Msg::Info("Optimize topology of quad mesh boundaries with extrusion and "
            "remeshing ...");

  std::vector<GFace *> faces = model_faces(gm);

  int nthreads = getNumThreads();
#pragma omp parallel for schedule(dynamic) num_threads(nthreads)
  for(size_t f = 0; f < faces.size(); ++f) {
    GFace *gf = faces[f];
    if(gf->meshStatistics.status != GFace::PENDING) continue;
    if(CTX::instance()->mesh.meshOnlyVisible && !gf->getVisibility()) continue;
    if(CTX::instance()->debugSurface > 0 &&
       gf->tag() != CTX::instance()->debugSurface)
      continue;
    if(gf->triangles.size() > 0 || gf->quadrangles.size() == 0) continue;

    optimizeFaceQuadMeshBoundaries(gf, true);
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
  Msg::Error("Module QUADMESHINGTOOLS required for function "
             "backgroundMeshAndGuidingFieldExists");
  return -10;
}
int optimizeTopologyWithDiskQuadrangulationRemeshing(GModel *gm)
{
  Msg::Error("Module QUADMESHINGTOOLS required for function "
             "optimizeTopologyWithCavityRemeshing");
  return -10;
}
int optimizeTopologyWithCavityRemeshing(GModel *gm)
{
  Msg::Error("Module QUADMESHINGTOOLS required for function "
             "optimizeTopologyWithCavityRemeshing");
  return -10;
}
int quadMeshingOfSimpleFacesWithPatterns(GModel *gm,
                                         double minimumQualityRequired)
{
  Msg::Error("Module QUADMESHINGTOOLS required for function "
             "quadMeshingOfSimpleFacesWithPatterns");
  return -10;
}
int RefineMeshWithBackgroundMeshProjection(GModel *gm)
{
  Msg::Error("Module QUADMESHINGTOOLS required for function "
             "RefineMeshWithBackgroundMeshProjection");
  return -10;
}
int replaceBadQuadDominantMeshes(GModel *gm)
{
  Msg::Error("Module QUADMESHINGTOOLS required for function "
             "replaceBadQuadDominantMeshes");
  return -10;
}
int optimizeQuadMeshBoundaries(GModel *gm)
{
  Msg::Error("Module QUADMESHINGTOOLS required for function "
             "optimizeQuadMeshBoundaries");
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

QuadqsContextUpdater::QuadqsContextUpdater()
{
#if defined(HAVE_QUADMESHINGTOOLS)
  backups_int.push_back(
    new RestoreValueAtEndOfLife<int>(&CTX::instance()->mesh.algo2d));
  backups_int.push_back(
    new RestoreValueAtEndOfLife<int>(&CTX::instance()->mesh.recombineAll));
  backups_int.push_back(
    new RestoreValueAtEndOfLife<int>(&CTX::instance()->mesh.algoRecombine));
  backups_int.push_back(new RestoreValueAtEndOfLife<int>(
    &CTX::instance()->mesh.recombineOptimizeTopology));
  backups_double.push_back(
    new RestoreValueAtEndOfLife<double>(&CTX::instance()->mesh.lcFactor));
  backups_double.push_back(
    new RestoreValueAtEndOfLife<double>(&CTX::instance()->mesh.lcMin));
  backups_double.push_back(
    new RestoreValueAtEndOfLife<double>(&CTX::instance()->mesh.lcMax));
  backups_int.push_back(
    new RestoreValueAtEndOfLife<int>(&CTX::instance()->mesh.lcFromPoints));
  backups_int.push_back(
    new RestoreValueAtEndOfLife<int>(&CTX::instance()->mesh.minCurveNodes));
  backups_int.push_back(
    new RestoreValueAtEndOfLife<int>(&CTX::instance()->mesh.minCircleNodes));

  // TODOMX: should restore abortOnError, but testing stuff
  backups_int.push_back(
    new RestoreValueAtEndOfLife<int>(&CTX::instance()->abortOnError));

  // Backup GEdge meshing attributes
  for(GEdge *ge : model_edges(GModel::current())) {
    backups_char.push_back(
      new RestoreValueAtEndOfLife<char>(&ge->meshAttributes.method));
    backups_double.push_back(new RestoreValueAtEndOfLife<double>(
      &ge->meshAttributes.coeffTransfinite));
    backups_double.push_back(
      new RestoreValueAtEndOfLife<double>(&ge->meshAttributes.meshSize));
    backups_double.push_back(
      new RestoreValueAtEndOfLife<double>(&ge->meshAttributes.meshSizeFactor));
    backups_int.push_back(new RestoreValueAtEndOfLife<int>(
      &ge->meshAttributes.nbPointsTransfinite));
    backups_int.push_back(
      new RestoreValueAtEndOfLife<int>(&ge->meshAttributes.typeTransfinite));
    backups_int.push_back(new RestoreValueAtEndOfLife<int>(
      &ge->meshAttributes.minimumMeshSegments));
    backups_bool.push_back(
      new RestoreValueAtEndOfLife<bool>(&ge->meshAttributes.reverseMesh));
  }

  // Backup GFace meshing attributes
  for(GFace *gf : model_faces(GModel::current())) {
    backups_int.push_back(
      new RestoreValueAtEndOfLife<int>(&gf->meshAttributes.recombine));
    backups_double.push_back(
      new RestoreValueAtEndOfLife<double>(&gf->meshAttributes.recombineAngle));
    backups_char.push_back(
      new RestoreValueAtEndOfLife<char>(&gf->meshAttributes.method));
    backups_int.push_back(new RestoreValueAtEndOfLife<int>(
      &gf->meshAttributes.transfiniteArrangement));
    backups_int.push_back(new RestoreValueAtEndOfLife<int>(
      &gf->meshAttributes.transfiniteSmoothing));
    backups_bool.push_back(
      new RestoreValueAtEndOfLife<bool>(&gf->meshAttributes.reverseMesh));
    backups_double.push_back(
      new RestoreValueAtEndOfLife<double>(&gf->meshAttributes.meshSize));
    backups_double.push_back(
      new RestoreValueAtEndOfLife<double>(&gf->meshAttributes.meshSizeFactor));
    backups_int.push_back(
      new RestoreValueAtEndOfLife<int>(&gf->meshAttributes.algorithm));
    backups_int.push_back(new RestoreValueAtEndOfLife<int>(
      &gf->meshAttributes.meshSizeFromBoundary));
  }
#else
  Msg::Error("Module QUADMESHINGTOOLS required to use QuadqsContextUpdater");
#endif

  setQuadqsOptions();
}

QuadqsContextUpdater::~QuadqsContextUpdater() { restoreInitialOption(); }

void QuadqsContextUpdater::setQuadqsOptions()
{
  Msg::Debug("set special quadqs options in the global context");

  // CTX::instance()->mesh.algo2d = ALGO_2D_QUAD_QUASI_STRUCT;
  CTX::instance()->mesh.recombineAll = 1;
  // CTX::instance()->mesh.algoRecombine = 4; /* bipartite labelling */
  if(CTX::instance()->mesh.algoRecombine != 4) {
    CTX::instance()->mesh.algoRecombine = 0; /* midpoint subdivision */
  }
  CTX::instance()->mesh.recombineOptimizeTopology = 0;
  CTX::instance()->mesh.lcFactor = 1.;
  CTX::instance()->mesh.lcMin = 0.;
  CTX::instance()->mesh.lcMax = 1.e22;
  CTX::instance()->mesh.lcFromPoints = 0;
  CTX::instance()->abortOnError = 0;
  CTX::instance()->mesh.minCurveNodes = 2;
  CTX::instance()->mesh.minCircleNodes = 0;
}

void QuadqsContextUpdater::restoreInitialOption()
{
#if defined(HAVE_QUADMESHINGTOOLS)
  Msg::Debug("restore options in the global context");
  for(size_t i = 0; i < backups_char.size(); ++i) { delete backups_char[i]; }
  for(size_t i = 0; i < backups_bool.size(); ++i) { delete backups_bool[i]; }
  for(size_t i = 0; i < backups_int.size(); ++i) { delete backups_int[i]; }
  for(size_t i = 0; i < backups_double.size(); ++i) {
    delete backups_double[i];
  }
#else
  Msg::Error("Module QUADMESHINGTOOLS required to use QuadqsContextUpdater");
#endif
}

int quadqsCleanup(GModel *gm)
{
  Msg::Info("Cleaning quadqs background mesh and field");
  global_bmeshes.clear(); /* background meshes used in quadqs */
  if(gm->getFields()->getBackgroundField() > 0) { /* background field */
    gm->getFields()->reset();
    // Field *field =
    // gm->getFields()->get(gm->getFields()->getBackgroundField()); if(field &&
    // field->numComponents() == 3) {
    //   gm->getFields()->deleteField(field->id);
    //   gm->getFields()->setBackgroundMesh(0);
    // }
  }
#if defined(HAVE_POST)
  PView *view = PView::getViewByName("guiding_field");
  delete view;
#if defined(HAVE_FLTK)
  if(FlGui::available()) FlGui::instance()->updateViews(true, true);
#endif
#endif
  return 0;
}

void getAcuteCorners(
  GFace *gf,
  std::unordered_map<MVertex *, std::vector<MVertex *> > &acuteCorners,
  double angle_threshold_rad)
{
  std::unordered_map<MVertex *, std::vector<MVertex *> > corner2vertices;
  for(GEdge *ge : gf->edges()) {
    for(MLine *line : ge->lines) {
      MVertex *v1 = line->getVertex(0);
      MVertex *v2 = line->getVertex(1);
      if(v1->onWhat() && v1->onWhat()->dim() == 0) {
        corner2vertices[v1].push_back(v2);
      }
      if(v2->onWhat() && v2->onWhat()->dim() == 0) {
        corner2vertices[v2].push_back(v1);
      }
    }
  }
  for(auto &kv : corner2vertices) {
    if(kv.second.size() == 2) {
      MVertex *v = kv.first;
      MVertex *v2 = kv.second[0];
      MVertex *v3 = kv.second[1];
      double agl = angle3Vertices(v2, v, v3);
      if(agl < angle_threshold_rad) {
        acuteCorners[v].push_back(v2);
        acuteCorners[v].push_back(v3);
      }
    }
  }
}

int optimize1DMeshAtAcuteCorners(GModel *gm)
{
  /* Collect acute corners */
  std::unordered_map<MVertex *, std::vector<MVertex *> > acuteCorners;
  double threshold = 30. * M_PI / 180.;
  for(GFace *gf : gm->getFaces()) {
    for(GEdge *ge : gf->edges())
      if(ge->lines.size() == 0) {
        Msg::Warning("Optimize 1D mesh at acute corners: no lines in curve %i",
                     ge->tag());
      }
    if(gf->triangles.size() > 0 || gf->quadrangles.size() > 0) {
      Msg::Warning("Optimize 1D mesh at acute corners: elements in face %i",
                   gf->tag());
    }
    getAcuteCorners(gf, acuteCorners, threshold);
  }

  /* Move vertices */
  size_t n = 0;
  for(auto &kv : acuteCorners) {
    MVertex *v = kv.first;
    /* Compute averaged distance */
    double avgLen = 0.;
    double avgN = 0.;
    double forcedLen = 0.;
    double forcedLenN = 0.;
    for(MVertex *v2 : kv.second) {
      double len = v->distance(v2);
      avgLen += len;
      avgN += 1.;
      if(v2->onWhat() && v2->onWhat()->dim() == 0) {
        forcedLen += len;
        forcedLenN += 1.;
      }
    }
    if(avgN > 0.) avgLen /= avgN;
    if(forcedLenN > 0.) forcedLen /= forcedLenN;

    /* Move vertices */
    for(MVertex *v2 : kv.second)
      if(v2->onWhat() && v2->onWhat()->dim() == 1) {
        SVector3 dir = v2->point() - v->point();
        if(dir.normSq() > 0.) { dir.normalize(); }
        double len = (forcedLen > 0.) ? forcedLen : avgLen;
        SPoint3 newPos = v->point() + len * dir;
        GEdge *ge = dynamic_cast<GEdge *>(v2->onWhat());
        double t = 0.;
        v2->getParameter(0, t);
        GPoint proj = ge->closestPoint(newPos, t);
        if(proj.succeeded()) {
          v2->setXYZ(proj.x(), proj.y(), proj.z());
          v2->setParameter(0, proj.u());
          n += 1;
        }
      }
  }
  if(n > 0) {
    Msg::Debug("optimize mesh 1D at acute corners: moved %li curve vertices",
               n);
  }
  return 0;
}
