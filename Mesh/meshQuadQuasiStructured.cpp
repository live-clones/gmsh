// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

#include <array>

#include "GmshConfig.h"
#include "GmshMessage.h"
#include "Numeric.h"
#include "Context.h"
#include "OS.h"
#include "GModel.h"
#include "meshGEdge.h"
#include "meshGFace.h"
#include "meshGRegion.h"
#include "BackgroundMesh.h"
#include "Generator.h"
#include "Field.h"
#include "gmsh.h"

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

/* QuadMeshingTools includes */
#include "cppUtils.h"
#include "qmtMeshUtils.h"
#include "qmtCrossField.h"
#include "qmtSizeMap.h"
#include "arrayGeometry.h"
#include "geolog.h"

using namespace CppUtils;
using namespace ArrayGeometry;

const std::string BMESH_NAME = "bmesh_quadqs";

int buildBackgroundField(
    GModel* gm,
    const std::vector<MTriangle*>& global_triangles,
    const std::vector<std::array<double,9> >& global_triangle_directions,
    const std::unordered_map<MVertex*,double>& global_size_map,
    const std::string& viewName = "guiding_field")  {
  Msg::Debug("build background guiding field ...");
  if (global_triangles.size() != global_triangle_directions.size()) {
    Msg::Error("build background field: incoherent sizes in input");
    return -1;
  }

  std::vector<double> datalist;
  datalist.reserve(global_triangles.size()*18);
  for (size_t i = 0; i < global_triangles.size(); ++i) {
    MTriangle* t = global_triangles[i];
    /* Triangle coordinates */
    for (size_t d = 0; d < 3; ++d) {
      for (size_t lv = 0; lv < 3; ++lv) {
        datalist.push_back(t->getVertex(lv)->point().data()[d]);
      }
    }
    /* Vector field */
    for (size_t lv = 0; lv < 3; ++lv) {
      MVertex* v = t->getVertex(lv);
      auto it = global_size_map.find(v);
      if (it == global_size_map.end()) {
        Msg::Error("Building background field, triangle vertex not found in global size map");
        return -1;
      }
      double siz = it->second;
      for (size_t d = 0; d < 3; ++d) {
        double val = siz * global_triangle_directions[i][3*lv+d];
        datalist.push_back(val);
      }
    }
  }

#if defined(HAVE_POST)
  PView* view = PView::getViewByName(viewName);
  if (view == NULL) {
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

  size_t numElements = datalist.size()/(9+9);
  int idxtype = 7; /* Post type: VT */
  d->importList(idxtype, numElements, datalist, true);
#if defined(HAVE_FLTK)
  view->getOptions()->visible = 0;
  if(FlGui::available()) FlGui::instance()->updateViews(true, true);
#endif

  gm->getFields()->setBackgroundMesh(view->getTag());

  return 0;
#else
  Msg::Error("Module POST (post-processing) required to create background field view");
  return -1;
#endif
}

void showCrossFieldInView(
    const std::vector<MTriangle*>& global_triangles,
    const std::vector<std::array<double,9> >& global_triangle_directions,
    const std::string& viewName = "cross_field") {
  for (size_t i = 0; i < global_triangles.size(); ++i) {
    for (size_t lv = 0; lv < 3; ++lv) {
      MVertex* v = global_triangles[i]->getVertex(lv);
      vec3 dir = {
        global_triangle_directions[i][3*lv+0],
        global_triangle_directions[i][3*lv+1],
        global_triangle_directions[i][3*lv+2]};
      std::array<double,3> pt = v->point();
      GeoLog::add(pt, dir, viewName);
    }
  }
  GeoLog::flush();
}

void showUVParametrization(
    GlobalBackgroundMesh& bgm,
    const std::string& viewName = "uv") {
  for (auto& kv: bgm.faceBackgroundMeshes) {
    GFace* gf = kv.first;
    std::unordered_map<MVertex*,double> param_u;
    std::unordered_map<MVertex*,double> param_v;
    std::vector<MElement*> tris;
    for (MTriangle& t: kv.second.triangles) {
      tris.push_back(&t);
      for (size_t lv = 0; lv < 3; ++lv) {
        MVertex* v = t.getVertex(lv);
        auto it = param_u.find(v);
        if (it == param_u.end()) {
          GFace* dgf = dynamic_cast<GFace*>(v->onWhat());
          if (dgf) {
            double uv[2];
            v->getParameter(0,uv[0]);
            v->getParameter(1,uv[1]);
            param_u[v] = uv[0];
            param_v[v] = uv[1];
          } else {
            SPoint2 uv;
            reparamMeshVertexOnFace(v, gf, uv);
            param_u[v] = uv.x();
            param_v[v] = uv.y();
          }
        }
      }
    }
    GeoLog::add(tris,param_u,viewName+"_u");
    GeoLog::add(tris,param_v,viewName+"_v");
  }
  GeoLog::flush();
}

int BuildBackgroundMeshAndGuidingField(GModel* gm, bool overwriteGModelMesh, bool deleteGModelMesh) {
  if(CTX::instance()->abortOnError && Msg::GetErrorCount()) return 0;
  if (CTX::instance()->mesh.algo2d != ALGO_2D_PACK_PRLGRMS
      && CTX::instance()->mesh.algo2d != ALGO_2D_QUAD_QUASI_STRUCT) return 0;

  const bool SHOW_INTERMEDIATE_VIEWS = (Msg::GetVerbosity() >= 99);

  Msg::Info("Build background mesh and guiding field ...");

  /* Todo:
   * - check if background mesh exists
   * - check if background guiding field exists */

  if (overwriteGModelMesh) {
    Msg::Debug("delete GModel mesh");
    std::for_each(gm->firstRegion(), gm->lastRegion(), deMeshGRegion());
    std::for_each(gm->firstFace(), gm->lastFace(), deMeshGFace());
    std::for_each(gm->firstRegion(), gm->lastRegion(), deMeshGRegion());
  }

  /* Check if triangulation available */
  bool surfaceMeshed = true;
  {
    bool onlyVisible = CTX::instance()->mesh.meshOnlyVisible;
    for(GFace* gf: gm->getFaces()) if (gf->getNumMeshElements() == 0){
      if (onlyVisible && !gf->getVisibility()) continue;
      surfaceMeshed = false;
    }
  }

  /* Generate triangulation */
  if (!surfaceMeshed) {
    Msg::Debug("build background triangulation ...");

    /* Unlock if called from GenerateMesh() */
    bool shouldLock = false;
    if (CTX::instance()->lock) {
      CTX::instance()->lock = 0;
      shouldLock = true;
    }

    /* Change meshing parameters to build a good triangulation
     * for cross field */
    double scalingOnTriangulation = 0.8;
    int minCurvPoints = CTX::instance()->mesh.minCurvPoints;
    int minCircPoints = CTX::instance()->mesh.minCircPoints;
    double lcFactor = CTX::instance()->mesh.lcFactor;
    int algo = CTX::instance()->mesh.algo2d;
    CTX::instance()->mesh.minCurvPoints = std::min(minCurvPoints,5);
    CTX::instance()->mesh.minCircPoints = std::min(minCircPoints,30);
    CTX::instance()->mesh.lcFactor = lcFactor * scalingOnTriangulation;
    CTX::instance()->mesh.algo2d = ALGO_2D_FRONTAL;

    /* Generate the triangulation with standard gmsh pipeline */
    GenerateMesh(gm,2);

    /* Restore parameters */
    CTX::instance()->mesh.minCurvPoints = minCurvPoints;
    CTX::instance()->mesh.minCircPoints = minCircPoints;
    CTX::instance()->mesh.lcFactor = lcFactor;
    CTX::instance()->mesh.algo2d = algo;

    /* Lock again before going back to GenerateMesh() */
    if (shouldLock) CTX::instance()->lock = 1;
  }

  GlobalBackgroundMesh& bmesh = getBackgroundMesh(BMESH_NAME);
  bool overwrite = true;
  int status = bmesh.importGModelMeshes(gm, overwrite);
  if (status != 0) {
    Msg::Error("failed to import model mesh in background mesh");
    return -1;
  }

  if (deleteGModelMesh) {
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
  std::vector<MTriangle*> global_triangles;
  std::vector<std::array<double,9> > global_triangle_directions;
  std::vector<std::pair<MVertex*,double> > global_size_map;
  {
    /* Per GFace computations, in parallel */

    std::vector<GFace*> faces = model_faces(gm);
    size_t ntris = 0;
    for (size_t f = 0; f < faces.size(); ++f) {
      GFace* gf = faces[f];
      auto it = bmesh.faceBackgroundMeshes.find(gf);
      if (it != bmesh.faceBackgroundMeshes.end()) {
        ntris += it->second.triangles.size();
      }
    }
    global_triangles.reserve(ntris);
    global_size_map.reserve(3*ntris);

    #if defined(_OPENMP)
    #pragma omp parallel for schedule(dynamic)
    #endif
    for (size_t f = 0; f < faces.size(); ++f) {

      GFace* gf = faces[f];
      /* Compute a cross field on each face */
      std::vector<MLine*> lines;
      std::vector<MTriangle*> triangles;

      /* Collect pointers to background mesh elements */
      std::vector<GEdge*> edges = face_edges(gf);
      for (GEdge* ge: edges) {
        auto it = bmesh.edgeBackgroundMeshes.find(ge);
        if (it == bmesh.edgeBackgroundMeshes.end()) {
          Msg::Warning("BuildBackgroundMeshAndGuidingField: GEdge %i not found in background mesh", 
              ge->tag());
          continue;
        }
        lines.reserve(lines.size()+it->second.lines.size());
        for (size_t i = 0; i < it->second.lines.size(); ++i) {
          lines.push_back(&(it->second.lines[i]));
        }
      }
      auto it = bmesh.faceBackgroundMeshes.find(gf);
      if (it == bmesh.faceBackgroundMeshes.end()) {
        Msg::Warning("BuildBackgroundMeshAndGuidingField: GFace %i not found in background mesh", 
            gf->tag());
        continue;
      }
      triangles.reserve(triangles.size()+it->second.triangles.size());
      for (size_t i = 0; i < it->second.triangles.size(); ++i) {
        triangles.push_back(&(it->second.triangles[i]));
      }

      if (triangles.size() == 0) {
        Msg::Error("- Face %i: no triangles in background mesh", gf->tag());
        continue;
      }

      std::vector<std::array<double,3> > triEdgeTheta;
      int nbDiffusionLevels = 4;
      double thresholdNormConvergence = 1.e-2;
      int nbBoundaryExtensionLayer = 1;
      int verbosity = 0;
      Msg::Info("- Face %i/%li: compute cross field (%li triangles, %li B.C. edges, %i diffusion levels) ...",
          gf->tag(), faces.size(), triangles.size(), lines.size(), nbDiffusionLevels);
      int scf = computeCrossFieldWithHeatEquation(triangles, lines, triEdgeTheta, 
          nbDiffusionLevels, thresholdNormConvergence, nbBoundaryExtensionLayer, verbosity);
      if (scf != 0) {
        Msg::Warning("- Face %i: failed to compute cross field", gf->tag());
      }

      std::unordered_map<MVertex*,double> conformalScaling;
      Msg::Info("- Face %i/%li: compute cross field conformal scaling ...", gf->tag(), faces.size());
      int scs = computeCrossFieldConformalScaling(triangles, triEdgeTheta, conformalScaling);
      if (scs != 0) {
        Msg::Warning("- Face %i: failed to compute conformal scaling, use uniform size", gf->tag());
      }

      std::vector<std::array<double,9> > triangleDirections;
      int sc = convertToPerTriangleCrossFieldDirections(triangles, triEdgeTheta, triangleDirections);
      if (sc != 0) {
        Msg::Warning("- Face %i: failed to resample cross field at triangle corners", gf->tag());
      }

      size_t targetNumberOfQuads = gf->triangles.size()/2.;
      if (targetNumberOfQuads == 0) { /* Check in background mesh */
        auto it = bmesh.faceBackgroundMeshes.find(gf);
        if (it == bmesh.faceBackgroundMeshes.end()) {
          Msg::Error("- Face %i: background mesh not found", gf->tag());
          targetNumberOfQuads = 1000;
        } else {
          targetNumberOfQuads = it->second.triangles.size()/2.;
        }
      }

      int scso = computeQuadSizeMapFromCrossFieldConformalFactor(triangles, targetNumberOfQuads, conformalScaling);
      if (scso != 0) {
        Msg::Warning("- Face %i: failed to compute size map from conformal scaling", gf->tag());
      }

      #if defined(_OPENMP)
      #pragma omp critical
      #endif
      {
        append(global_triangles, triangles);
        append(global_triangle_directions, triangleDirections);
        for (auto& kv: conformalScaling) {
          global_size_map.push_back({kv.first,kv.second});
        }
      }
    }
  }
  sort_unique(global_size_map);

  /* Warning: from now on, code is not optimized in terms of data structures
   *          (slow unordered_map instead of contiguous vectors, etc) 
   *          should be improved if this step is time-consuming in the 
   *          global pipeline. */

  if (SHOW_INTERMEDIATE_VIEWS) {
    showCrossFieldInView(global_triangles, global_triangle_directions, "cross_field");
  }


  /* Global operations */
  std::unordered_map<MVertex*,double> cadMinimalSizeOnCurves;
  int scad = computeMinimalSizeOnCurves(bmesh, cadMinimalSizeOnCurves);
  if (scad != 0) {
    Msg::Warning("failed to compute minimal size on CAD curves");
  }

  /* Initialize global size map defined on the background mesh */
  std::unordered_map<MVertex*,double> sizeMap = cadMinimalSizeOnCurves;
  for (auto& kv: global_size_map) {
    MVertex* v = kv.first;
    auto it = sizeMap.find(v);
    if (it == sizeMap.end()) {
      sizeMap[kv.first] = kv.second;
    } else {
      it->second = std::min(it->second, kv.second);
    }
  }

  /* One-way propagation of values */
  const double gradientMax = 1.2; /* this param should be a global gmsh option */
  int sop = sizeMapOneWaySmoothing(global_triangles, sizeMap, gradientMax);
  if (sop != 0) {
    Msg::Warning("failed to compute one-way size map smoothing");
  }

  if (SHOW_INTERMEDIATE_VIEWS) {
    std::vector<MElement*> elements = dynamic_cast_vector<MTriangle*,MElement*>(global_triangles);
    GeoLog::add(elements, sizeMap, "size_map");
    GeoLog::flush();
    showUVParametrization(bmesh);
  }

  /* Clamp with global minimum/maximum mesh size */
  {
    // TODO: should be multiplied by lcFactor or not ?
    for (auto& kv: global_size_map) {
      if (kv.second < CTX::instance()->mesh.lcMin) {
        kv.second = CTX::instance()->mesh.lcMin;
      } else if (kv.second > CTX::instance()->mesh.lcMax) {
        kv.second = CTX::instance()->mesh.lcMax;
      }
    }
  }

  /* Build the background field */
  int sbf = buildBackgroundField(gm, global_triangles, global_triangle_directions, sizeMap,
      "guiding_field");
  if (sbf != 0) {
    Msg::Warning("failed to build background guiding field");
    return -1;
  }

  CTX::instance()->mesh.lcFactor = 1.; // TODO TEMP TEST

  return 0;
}

bool backgroundMeshAndGuidingFieldExists(GModel* gm) {
  bool bgmOk = backgroudMeshExists(BMESH_NAME);
  bool bfOk = false;
  FieldManager *fields = gm->getFields();
  if(fields->getBackgroundField() > 0) {        
    Field* guiding_field = fields->get(fields->getBackgroundField());
    if(guiding_field && guiding_field->numComponents() == 3) {
      bfOk = true;
    }
  }
  return bgmOk && bfOk;
}

#else

/* QuadMeshingTools module not available */
int BuildBackgroundMeshAndGuidingField(
    GModel* gm, 
    bool overwriteGModelMesh,
    bool deleteGModelMeshAfter) {
  Msg::Error("BuildBackgroundMeshAndGuidingField: Module QUADMESHINGTOOLS required");
  return -1;
}

#endif


