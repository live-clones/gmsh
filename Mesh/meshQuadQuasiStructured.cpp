// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
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
/* QuadMeshingTools includes */
#include "cppUtils.h"
#include "qmtMeshUtils.h"
#include "qmtCrossField.h"
#include "qmtSizeMap.h"
#include "qmtDiskQuadrangulationRemeshing.h"
#include "qmtQuadCavityRemeshing.h"
#include "qmtMeshGeometryOptimization.h"
#include "arrayGeometry.h"
#include "geolog.h"

using namespace CppUtils;
using namespace ArrayGeometry;

template <typename Key, typename T, typename Hash = robin_hood::hash<Key>,
         typename KeyEqual = std::equal_to<Key>, size_t MaxLoadFactor100 = 80>
           using unordered_map = robin_hood::detail::Table<true, MaxLoadFactor100, Key, T, Hash, KeyEqual>;

template <typename Key, typename Hash = robin_hood::hash<Key>, typename KeyEqual = std::equal_to<Key>,
         size_t MaxLoadFactor100 = 80>
           using unordered_set = robin_hood::detail::Table<true, MaxLoadFactor100, Key, void, Hash, KeyEqual>;


const std::string BMESH_NAME = "bmesh_quadqs";

constexpr bool PARANO_QUALITY = false;


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

  if (Msg::GetVerbosity() >= 99) {
    std::string name = gm->getName() + "_bgm.pos";
    Msg::Warning("export background field to '%s' ", name.c_str());
    view->write(name,0);
  }

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
    GFace* gf,
    const std::vector<MElement*>& elts,
    const std::string& viewName = "uv") {
  std::vector<std::vector<double> > values_u;
  std::vector<std::vector<double> > values_v;
  for (MElement* t: elts) {
    std::vector<SPoint2> tris_uvs = paramOnElement(gf,t);
    std::vector<double> us(tris_uvs.size());
    std::vector<double> vs(tris_uvs.size());
    for (size_t k = 0; k < us.size(); ++k) {
      us[k] = tris_uvs[k][0];
      vs[k] = tris_uvs[k][1];
    }
    values_u.push_back(us);
    values_v.push_back(vs);
  }
  GeoLog::add(elts,values_u,viewName+"_u");
  GeoLog::add(elts,values_v,viewName+"_v");
}

void showUVParametrization(
    GlobalBackgroundMesh& bgm,
    const std::string& viewName = "uv") {
  for (auto& kv: bgm.faceBackgroundMeshes) {
    GFace* gf = kv.first;
    if (!gf->haveParametrization()) continue;
    std::vector<MElement*> tris;
    for (MTriangle& t: kv.second.triangles) {
      tris.push_back(&t);
    }
    showUVParametrization(gf, tris, viewName);
  }
  GeoLog::flush();
}

void printSizeMapStats(
    const std::vector<MTriangle*>& triangles, 
    std::unordered_map<MVertex*,double>& sizemap) {
  double vmin = DBL_MAX;
  double vmax = -DBL_MAX;
  for (auto& kv: sizemap) {
    vmin = std::min(vmin,kv.second);
    vmax = std::max(vmax,kv.second);
  }
  double integral = 0.;
  for (MTriangle* t: triangles) {
    double values[3] = {0,0,0};
    for (size_t lv = 0; lv < 3; ++lv) {
      MVertex* v = t->getVertex(lv);
      auto it = sizemap.find(v);
      values[lv] = it->second;;
    }
    double a = std::abs(t->getVolume());
    integral += a * 1. / std::pow(1./3. * (values[0] + values[1] + values[2]),2);
  }
  Msg::Info("Size map statistics: min=%.3f, max=%.3f, target #elements: %.3f", vmin, vmax, integral);
}


int BuildBackgroundMeshAndGuidingField(GModel* gm, bool overwriteGModelMesh, bool deleteGModelMesh, int N) {
  if(CTX::instance()->abortOnError && Msg::GetErrorCount()) return 0;
  if (CTX::instance()->mesh.algo2d != ALGO_2D_PACK_PRLGRMS
      && CTX::instance()->mesh.algo2d != ALGO_2D_QUAD_QUASI_STRUCT) return 0;
  if (N != 4 && N != 6) {
    Msg::Error("guiding field: %i-symmetry field not supported", N);
    return -1;
  }

  const bool SHOW_INTERMEDIATE_VIEWS = (Msg::GetVerbosity() >= 99);

  Msg::Info("Build background mesh and guiding field ...");

  {
    FieldManager *fields = gm->getFields();
    if(fields->getBackgroundField() > 0) {        
      Field* guiding_field = fields->get(fields->getBackgroundField());
      if(guiding_field && guiding_field->numComponents() == 3) {
        Msg::Info("background field exists, using it");
        return 0;
      }
    }
  }

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
  double scalingOnTriangulation = 1;
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
    /* - the triangulation must be a bit more refined than the quad mesh */
    scalingOnTriangulation = 0.75; 
    int minCurveNodes = CTX::instance()->mesh.minCurveNodes;
    int minCircleNodes = CTX::instance()->mesh.minCircleNodes;
    double lcFactor = CTX::instance()->mesh.lcFactor;
    int algo = CTX::instance()->mesh.algo2d;
    CTX::instance()->mesh.minCurveNodes = std::min(minCurveNodes,5);
    CTX::instance()->mesh.minCircleNodes = std::min(minCircleNodes,30);
    CTX::instance()->mesh.lcFactor = lcFactor * scalingOnTriangulation;
    CTX::instance()->mesh.algo2d = ALGO_2D_MESHADAPT; /* slow but frontal does not always work */

    /* Generate the triangulation with standard gmsh pipeline */
    GenerateMesh(gm,2);

    /* Restore parameters */
    CTX::instance()->mesh.minCurveNodes = minCurveNodes;
    CTX::instance()->mesh.minCircleNodes = minCircleNodes;
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
      /* warning: initialize global storage of singularities
       *          before parallel loop to avoid race conditions */
      global_singularities[gf] = {}; 
    }
    global_triangles.reserve(ntris);
    global_size_map.reserve(3*ntris);

    #if defined(_OPENMP)
    #pragma omp parallel for schedule(dynamic)
    #endif
    for (size_t f = 0; f < faces.size(); ++f) {

      GFace* gf = faces[f];

      if (CTX::instance()->mesh.meshOnlyVisible && !gf->getVisibility()) continue;
      if (CTX::instance()->debugSurface > 0 && gf->tag() != CTX::instance()->debugSurface) continue;

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

      /* Cross field */
      std::vector<std::array<double,3> > triEdgeTheta;
      int nbDiffusionLevels = 4;
      double thresholdNormConvergence = 1.e-2;
      int nbBoundaryExtensionLayer = 1;
      int verbosity = 0;
      Msg::Info("- Face %i/%li: compute cross field (%li triangles, %li B.C. edges, %i diffusion levels) ...",
          gf->tag(), faces.size(), triangles.size(), lines.size(), nbDiffusionLevels);
      int scf = computeCrossFieldWithHeatEquation(N, triangles, lines, triEdgeTheta, 
          nbDiffusionLevels, thresholdNormConvergence, nbBoundaryExtensionLayer, verbosity);
      if (scf != 0) {
        Msg::Warning("- Face %i: failed to compute cross field", gf->tag());
      }

      /* Cross field singularities */
      bool addSingularitiesAtAcuteCorners = true;
      double thresholdInDeg = 30.;
      std::vector<std::pair<SPoint3,int> > singularities;
      int scsi = detectCrossFieldSingularities(N, triangles, triEdgeTheta, 
          addSingularitiesAtAcuteCorners, thresholdInDeg,
          singularities);
      if (scsi != 0) {
        Msg::Warning("- Face %i: failed to compute cross field singularities", gf->tag());
      }
      global_singularities[gf] = singularities; /* warning: global storage of singularities ! */
      if (SHOW_INTERMEDIATE_VIEWS) {
        for (auto& kv: singularities) {
          GeoLog::add(kv.first,double(kv.second),"singularities");
        }
      }

      /* Conformal scaling associated to cross field */
      std::unordered_map<MVertex*,double> conformalScaling;
      Msg::Info("- Face %i/%li: compute cross field conformal scaling ...", gf->tag(), faces.size());
      int scs = computeCrossFieldConformalScaling(N, triangles, triEdgeTheta, conformalScaling);
      if (scs != 0) {
        Msg::Warning("- Face %i: failed to compute conformal scaling, use uniform size", gf->tag());
      }

      /* Quantile filtering on the conformal scaling histogram */
      double filteringRange = 0.05;
      quantileFiltering(conformalScaling, filteringRange);

      std::vector<std::array<double,9> > triangleDirections;
      int sc = convertToPerTriangleCrossFieldDirections(N, triangles, triEdgeTheta, triangleDirections);
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
          targetNumberOfQuads = 0.5 * it->second.triangles.size();
          targetNumberOfQuads *= std::pow(scalingOnTriangulation,2);
        }
      }

      /* Midpoint subdivision => 4 times more quads */
      targetNumberOfQuads /= 4;

      if (targetNumberOfQuads == 0) targetNumberOfQuads = 1;

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

  /* Compute minimum / maximum of "natural" size map.
   * Use this to avoid cases when minimal size on curves
   * tends to 0 */
  double smMin =  DBL_MAX;
  for (auto& kv: global_size_map) {
    smMin = std::min(smMin, kv.second);
  }
  double factor = 0.1; /* size map can be reduced up to factor */
  double minSizeClampMin = factor * smMin;

  /* Minimal size on curves */
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
      sizeMap[kv.first] = kv.second; /* "natural" size */
    } else {
      double sizeFromAdaptation = std::max(it->second,minSizeClampMin);
      it->second = std::min(sizeFromAdaptation, kv.second);
    }
  }

  /* One-way propagation of values */
  // Msg::Warning("TODO: enable one way prop");
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
  // {
  // // TODO: apply on sizeMap instead
  //   // TODO: should be multiplied by lcFactor or not ?
  //   for (auto& kv: global_size_map) {
  //     if (kv.second < CTX::instance()->mesh.lcMin) {
  //       kv.second = CTX::instance()->mesh.lcMin;
  //     } else if (kv.second > CTX::instance()->mesh.lcMax) {
  //       kv.second = CTX::instance()->mesh.lcMax;
  //     }
  //   }
  // }

  printSizeMapStats(global_triangles, sizeMap);

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


// /* QuadMeshingTools module not available */
// int BuildBackgroundMeshAndGuidingField(
//     GModel* gm, 
//     bool overwriteGModelMesh,
//     bool deleteGModelMeshAfter) {
//   Msg::Error("BuildBackgroundMeshAndGuidingField: Module QUADMESHINGTOOLS required");
//   return -1;
// }



void computeBdrVertexIdealValence(const std::vector<MQuadrangle*>& quads,
    unordered_map<MVertex *, double>& qValIdeal) {
  qValIdeal.clear();
  for (MQuadrangle* f: quads) {
    for (size_t lv = 0; lv < 4; ++lv) {
      MVertex* v = f->getVertex(lv);
      GFace* gf = dynamic_cast<GFace*>(v->onWhat());
      if (gf == nullptr) { /* On boundary */
        MVertex* vPrev = f->getVertex((4+lv-1)%4);
        MVertex* vNext = f->getVertex((lv+1)%4);
        SVector3 pNext = vNext->point();
        SVector3 pPrev = vPrev->point();
        SVector3 pCurr = v->point();
        double agl = angleVectors(pNext-pCurr,pPrev-pCurr);
        qValIdeal[v] += agl * 2. / M_PI;
      }
    }
  }
}

inline int clamp(int val, int lower, int upper) {
  return std::min(upper, std::max(val, lower));
}

bool getBoundaryIdealAndAllowedValences(
    int fixingDim, /* 0 when fixing corners, 1 when fixing curves, 2 when fixing surfaces */
    GFaceMeshPatch& patch,
    const unordered_map<MVertex *, std::vector<MElement *> >& adj,
    const unordered_map<MVertex *, double>& qValIdeal,
    std::vector<int>& bndIdealValence,
    std::vector<std::pair<int,int> >& bndAllowedValenceRange) {
  if (fixingDim < 0 || fixingDim > 2) return false;
  size_t N = patch.bdrVertices.front().size();
  bndIdealValence.resize(N);
  bndAllowedValenceRange.resize(N);
  for (size_t i = 0; i < N; ++i) {
    MVertex* bv = patch.bdrVertices.front()[i];
    GVertex* gv = dynamic_cast<GVertex*>(bv->onWhat());
    GEdge* ge = dynamic_cast<GEdge*>(bv->onWhat());
    GFace* gf = dynamic_cast<GFace*>(bv->onWhat());
    int idealTot = 4;
    if (gf == nullptr) {
      auto it = qValIdeal.find(bv);
      if (it == qValIdeal.end()) {
        Msg::Error("getBoundaryIdealAndAllowedValences: bdr vertex %i not found in qValIdeal", bv->getNum());
        return false;
      }
      idealTot = (int) clamp(std::round(it->second),1.,4.);
    } 
    auto it = adj.find(bv);
    if (it == adj.end()) {
      Msg::Error("getBoundaryIdealAndAllowedValences: bdr vertex not found in adj");
      return false;
    }
    std::vector<MElement*> exterior = difference(it->second, patch.elements);
    int valExterior = (int) exterior.size();
    int valInterior = (int) it->second.size() - exterior.size();
    int idealIn = idealTot - valExterior;
    if (idealIn <= 0) {
      idealIn = 1;
      // DBG(bv->getNum(), idealIn, idealTot, valExterior);
      // Msg::Error("getBoundaryIdealAndAllowedValences: ideal valence inside is <= 0, weird");
      // return false;
    }
    bndIdealValence[i] = idealIn;
    if (exterior.size() == 0) { /* boundary vertex "inside" the cavity, probably the one to remesh */
      bndAllowedValenceRange[i] = {idealIn,idealIn};
    } else if (gv != nullptr) { /* Current bdr vertex is corner */
      bndAllowedValenceRange[i] = {idealIn,idealIn};
    } else if (ge != nullptr) { /* Current bdr vertex is on curve */
      if (fixingDim == 0) { /* When fixing corners, can degrade curves */
        bndAllowedValenceRange[i] = {1,2};
      } else {
        bndAllowedValenceRange[i] = {idealIn,idealIn};
      }
    } else if (gf != nullptr) {
      if (valExterior <= 0) {
        Msg::Error("getBoundaryIdealAndAllowedValences: surface bdr vertex but exterior valence is: %i", valExterior);
        return false;
      }
      if (fixingDim == 0 && idealTot >= 3 && it->second.size() == 4) { 
        /* When fixing concave corner, do not degrade close regular interior vertices */
        bndAllowedValenceRange[i] = {valInterior,valInterior}; 
      } else if (fixingDim == 0 || fixingDim == 1) { /* When fixing corner/curve, can degrade surface */
        /* Allowed total range: [3,6], minimize if valExterior higher to this */
        int lower = 3 - valExterior;
        int upper = 6 - valExterior;
        lower = clamp(lower, 1, 5);
        upper = clamp(upper, 1, 5);
        bndAllowedValenceRange[i] = {lower,upper}; 
      } else {
        /* Allowed total range: [3,5], minimize if valExterior higher to this */
        int lower = 3 - valExterior;
        int upper = 5 - valExterior;
        lower = clamp(lower, 1, 4);
        upper = clamp(upper, 1, 4);
        bndAllowedValenceRange[i] = {lower,upper}; 
      }
    } else {
      Msg::Error("getBoundaryIdealAndAllowedValences: vertex on no CAD entity, should not happen");
      return false;
    }

    // if (fixingDim == 2) {
    //   std::string name = "[" + std::to_string(bndAllowedValenceRange[i].first) 
    //     + "," + std::to_string(int(bndAllowedValenceRange[i].second)) + "]";
    //   GeoLog::add({bv->point()},double(bndIdealValence[i]), name);
    // }
  }

  return true;
}

bool meshOrientationIsOppositeOfCadOrientation(GFace* gf) {
  size_t nOk = 0;
  size_t nInv = 0;
  for(std::size_t iEl = 0; iEl < gf->getNumMeshElements(); iEl++) {
    MElement *e = gf->getMeshElement(iEl);
    SVector3 ne = e->getFace(0).normal();
    MVertex* v = e->getVertex(0);
    SPoint2 param;
    if(v->onWhat() == gf && v->getParameter(0, param[0]) &&
        v->getParameter(1, param[1])) {
      SVector3 nf = gf->normal(param);
      if (dot(nf,ne) < 0.) {
        nInv += 1;
      } else {
        nOk += 1;
      }
    }
  }
  return (nInv > nOk);
}

void updateAdjacencies(
    const GFaceMeshPatch& before,
    const GFaceMeshPatch& after,
    unordered_map<MVertex *, std::vector<MElement *> >& adj) {
  /* Remove old vertices from adjacency keys */
  for (MVertex* v: before.intVertices) {
    auto it = adj.find(v);
    if (it != adj.end()) {
      adj.erase(it);
    }
  }
  /* Remove old elements from adjacency values */
  for (MVertex* bv: before.bdrVertices.front()) {
    auto it = adj.find(bv);
    if (it != adj.end()) {
      it->second = difference(it->second, before.elements);
    }
  }
  /* Add new keys and values */
  for (MElement* e: after.elements) {
    for (size_t lv = 0; lv < e->getNumVertices(); ++lv) {
      MVertex* v = e->getVertex(lv);
      adj[v].push_back(e);
    }
  }
}

std::vector<MElement*> getNeighbors(
    const std::vector<MElement*>& elements,
    const unordered_map<MVertex *, std::vector<MElement *> >& adj) {
  std::vector<MElement*> neighbors;
  for (MElement* e: elements) {
    for (size_t lv = 0; lv < e->getNumVertices(); ++lv) {
      MVertex* v = e->getVertex(lv);
      auto it = adj.find(v);
      if (it != adj.end()) {
        for (MElement* e: it->second) {
          neighbors.push_back(e);
        }
      }
    }
  }
  neighbors = difference(neighbors, elements);
  return neighbors;
}

bool smoothThePool(
    GFace* gf,
    const std::vector<MVertex*>& smoothingPool,
    const unordered_map<MVertex *, std::vector<MElement *> >& adj,
    bool invertNormalsForQuality,
    SurfaceProjector* sp = nullptr) {
  /* Get all quads used for smoothing */
  std::vector<MElement*> elements;
  {
    std::vector<MVertex*> unq = smoothingPool;
    sort_unique(unq);
    elements.reserve(unq.size());
    for (MVertex* v: unq) {
      auto it = adj.find(v);
      if (it != adj.end()) {
        append(elements, it->second);
      }
    }
  }

  /* Build the disconnected patches and smooth them independently */
  std::vector<std::vector<MElement*> > components;
  bool okc = getConnectedComponents(elements, components);
  if (!okc) return false;
  Msg::Debug("smooth %li connected components from %li initial elements ...", 
      components.size(), elements.size());
  for (size_t i = 0; i < components.size(); ++i) {
    GFaceMeshPatch patch;
    bool okp = patchFromElements(gf, components[i], patch);
    if (!okp) continue;

    PatchGeometryBackup backup(patch);

    GeomOptimStats stats;
    double sicnBefore = 0.;
    if (haveNiceParametrization(gf)) {
      if (patch.bdrVertices.size() == 1) { /* disk topology */
        /* Global UV smoothing */
        patchOptimizeGeometryGlobal(patch, stats);
        sicnBefore = stats.sicnMinBefore;

        if (stats.sicnMinAfter < 0.5) {
          /* Kernel smoothing */
          GeomOptimOptions opt;
          opt.invertCADNormals = invertNormalsForQuality;
          patchOptimizeGeometryWithKernel(patch, opt, stats);
        }
      } else {
        double sicnAvg;
        computeSICN(patch.elements, sicnBefore, sicnAvg);
        if (sicnBefore < 0.5) {
          /* Kernel smoothing */
          GeomOptimOptions opt;
          opt.invertCADNormals = invertNormalsForQuality;
          patchOptimizeGeometryWithKernel(patch, opt, stats);
        }
      }
    } else {
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
    if (stats.sicnMinAfter < sicnBefore) {
      Msg::Debug("quality (SICN) decreased (%.3f -> %.3f), restore previous geometry",
          sicnBefore, stats.sicnMinAfter);
      backup.restore();
    }
  }

  return true;
}

struct DQOptions {
  bool invertNormalsForQuality = false;
  SurfaceProjector* sp = nullptr;
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
    GFace* gf,
    const unordered_map<MVertex *, double>& qValIdeal, /* valence on bdr vertices */
    unordered_map<MVertex *, std::vector<MElement *> >& adj,
    DQOptions& opt,
    DQStats& stats
    ) {
  Msg::Debug("- Face %i: improve corner valences", gf->tag());
  std::vector<MVertex*> smoothingPool; /* for smoothing after topological changes */
  smoothingPool.reserve(gf->mesh_vertices.size());

  /* qValIdeal is unordered_map and its ordering is random, we replace 
   * it with a deterministic ordering, containing only the corners */
  std::vector<std::pair<MVertex*,double> > cornerAndIdeal;
  for (auto& kv: qValIdeal) {
    GVertex* gv = dynamic_cast<GVertex*>(kv.first->onWhat());
    if (gv != nullptr) {
      cornerAndIdeal.push_back({kv.first,kv.second});
    }
  }
  std::sort(cornerAndIdeal.begin(),cornerAndIdeal.end(),
      [](const std::pair<MVertex*, double>& lhs, const std::pair<MVertex*, double>& rhs) {
      return lhs.second < rhs.second 
      || (lhs.second == rhs.second && lhs.first->getNum() < rhs.first->getNum()); } );


  int SMALL_PATCH = 0; /* just the quads adjacent to corner */
  int LARGER_PATCH = 1; /* add the neighbors */
  /* We try larger cavities first because the result is usually better
   * when it works (less new defects on adjacent curves). But it does
   * not work when the larger cavity is too constrained by CAD curves,
   * so we try the small cavity after */
  for (int pass: {LARGER_PATCH,SMALL_PATCH}) {
    for (const auto& kv: cornerAndIdeal) {
      MVertex* v = kv.first;
      GVertex* gv = dynamic_cast<GVertex*>(v->onWhat());
      if (gv == nullptr) continue;
      auto it = adj.find(v);
      if (it == adj.end()) continue;
      const std::vector<MElement*>& quads = it->second;
      double ideal = kv.second;
      size_t ival = (size_t) clamp(std::round(ideal),1.,4.);
      if (ival == quads.size()) continue;
      size_t num = v->getNum();

      /* From here, we try to change the local configuration */
      Msg::Debug("- Face %i: try to fix corner %i (vertex %li), val %li instead of %li", 
          gf->tag(), gv->tag(), num, it->second.size(), ival);

      /* Init patch with quads adjacent to corner */
      GFaceMeshPatch patch;
      if (pass == LARGER_PATCH) {
        /* and the neighbors */
        std::vector<MElement*> quadsPlus = quads;
        append(quadsPlus, getNeighbors(quads,adj));
        bool okp = patchFromElements(gf, quadsPlus, patch); 
        if (!okp) continue;
      } else {
        bool okp = patchFromElements(gf, quads, patch); 
        if (!okp) continue;
      }
      if (patch.bdrVertices.size() != 1) {
        Msg::Debug("patch has %li bdr loops, weird", patch.bdrVertices.size());
        continue;
      }

      std::vector<int> bndIdealValence;
      std::vector<std::pair<int,int> > bndAllowedValenceRange;
      const int dimCorner = 0;
      bool okb = getBoundaryIdealAndAllowedValences(dimCorner, patch, adj, qValIdeal, bndIdealValence, bndAllowedValenceRange);
      if (!okb) continue;

      GFaceMeshDiff diff;
      std::vector<MElement*> neighborsForGeometry = getNeighbors(patch.elements, adj);
      double minSICNafer = 0.1;
      int sdq = remeshLocalWithDiskQuadrangulation(gf,
          patch.elements, patch.intVertices, patch.bdrVertices.front(), bndIdealValence, bndAllowedValenceRange,
          neighborsForGeometry, minSICNafer, opt.invertNormalsForQuality, opt.sp, diff);
      if (sdq == 0) {
        /* Copy the pointers to update the adjacencies in case success */
        GFaceMeshPatch patchBefore = diff.before;
        GFaceMeshPatch patchAfter = diff.after;

        /* Execute the diff on the mesh */
        bool ok = diff.execute(true); /* warning: GFace mesh changes here */
        if (ok) {
          updateAdjacencies(patchBefore, patchAfter, adj);
          append(smoothingPool, patchBefore.intVertices);
          append(smoothingPool, patchBefore.bdrVertices.front());
          stats.nCornerValFixed += 1;
        } else {
          Msg::Error("failed to apply diff, abort");
          abort();
        }
        Msg::Debug("-- corner %li fixed", num);
      } else {
        Msg::Debug("-- failed to fix corner %li", num);
      }
    }
  }

  if (smoothingPool.size() > 0) smoothThePool(gf, smoothingPool, adj, opt.invertNormalsForQuality, opt.sp);

  /* Remaining cases, just for stats */
  for (const auto& kv: cornerAndIdeal) {
    MVertex* v = kv.first;
    GVertex* gv = dynamic_cast<GVertex*>(v->onWhat());
    if (gv == nullptr) continue;
    auto it = adj.find(v);
    if (it == adj.end()) continue;
    const std::vector<MElement*>& quads = it->second;
    double ideal = kv.second;
    size_t ival = (size_t) clamp(std::round(ideal),1.,4.);
    if (ival == quads.size()) continue;
    stats.nCornerValRemaining += 1;
  }

  return 0;
}

int improveCurveValences(
    GFace* gf,
    const unordered_map<MVertex *, double>& qValIdeal, /* valence on bdr vertices */
    unordered_map<MVertex *, std::vector<MElement *> >& adj,
    DQOptions& opt,
    DQStats& stats
    ) {
  Msg::Debug("- Face %i: improve curve valences", gf->tag());
  std::vector<MVertex*> smoothingPool; /* for smoothing after topological changes */
  smoothingPool.reserve(gf->mesh_vertices.size());

  /* qValIdeal is unordered_map and its ordering is random, we replace 
   * it with a deterministic ordering, containing only the corners */
  std::vector<std::pair<MVertex*,double> > curveVertexAndIdeal;
  curveVertexAndIdeal.reserve(qValIdeal.size());
  for (auto& kv: qValIdeal) {
    MVertex* v = kv.first;
    GEdge* ge = dynamic_cast<GEdge*>(v->onWhat());
    if (ge != nullptr) {
      curveVertexAndIdeal.push_back({kv.first,kv.second});
    }
  }
  std::sort(curveVertexAndIdeal.begin(),curveVertexAndIdeal.end(),
      [](const std::pair<MVertex*, double>& lhs, const std::pair<MVertex*, double>& rhs) {
      return lhs.second < rhs.second 
      || (lhs.second == rhs.second && lhs.first->getNum() < rhs.first->getNum()); } );

  for (const auto& kv: curveVertexAndIdeal) {
    MVertex* v = kv.first;
    GEdge* ge = dynamic_cast<GEdge*>(v->onWhat());
    if (ge == nullptr) continue;
    auto it = adj.find(v);
    if (it == adj.end()) continue;
    const std::vector<MElement*>& quads = it->second;
    double ideal = kv.second;
    size_t ival = (size_t) clamp(std::round(ideal),1.,4.);
    if (ival == quads.size()) continue;
    size_t num = v->getNum();

    /* From here, we try to change the local configuration */
    Msg::Debug("- Face %i: try to fix curve vertex %li, val %li instead of %li", 
        gf->tag(), v->getNum(), it->second.size(), ival);

    /* Init patch with quads adjacent to corner */
    GFaceMeshPatch patch;
    bool okp = patchFromElements(gf, quads, patch); 
    if (!okp) continue;
    if (patch.bdrVertices.size() != 1) {
      Msg::Debug("patch has %li bdr loops, weird", patch.bdrVertices.size());
      continue;
    }

    std::vector<int> bndIdealValence;
    std::vector<std::pair<int,int> > bndAllowedValenceRange;
    const int dimCurve = 1;
    bool okb = getBoundaryIdealAndAllowedValences(dimCurve, patch, adj, qValIdeal, bndIdealValence, bndAllowedValenceRange);
    if (!okb) continue;

    GFaceMeshDiff diff;
    std::vector<MElement*> neighborsForGeometry = getNeighbors(patch.elements, adj);
    double minSICNafer = 0.1;
    int sdq = remeshLocalWithDiskQuadrangulation(gf,
        patch.elements, patch.intVertices, patch.bdrVertices.front(), bndIdealValence, bndAllowedValenceRange,
        neighborsForGeometry, minSICNafer, opt.invertNormalsForQuality, opt.sp, diff);
    if (sdq == 0) {
      /* Copy the pointers to update the adjacencies in case success */
      GFaceMeshPatch patchBefore = diff.before;
      GFaceMeshPatch patchAfter = diff.after;

      /* Execute the diff on the mesh */
      bool ok = diff.execute(true); /* warning: GFace mesh changes here */
      if (ok) {
        updateAdjacencies(patchBefore, patchAfter, adj);
        append(smoothingPool, patchBefore.intVertices);
        append(smoothingPool, patchBefore.bdrVertices.front());
        stats.nCurveValFixed += 1;

        if (PARANO_QUALITY) {
          errorAndAbortIfNegativeElement(gf, dynamic_cast_vector<MQuadrangle*,MElement*>(gf->quadrangles), "after execute");
        }
      } else {
        Msg::Error("failed to apply diff, abort");
        abort();
      }
      Msg::Debug("-- curve vertex %li fixed", num);
    } else {
      Msg::Debug("-- failed to fix curve vertex %li", num);

      if (PARANO_QUALITY) {
        errorAndAbortIfNegativeElement(gf, dynamic_cast_vector<MQuadrangle*,MElement*>(gf->quadrangles), "after failed to fix, baaad");
      }
    }
  }

  if (PARANO_QUALITY) {
    errorAndAbortIfNegativeElement(gf, dynamic_cast_vector<MQuadrangle*,MElement*>(gf->quadrangles), "before pool");
  }

  if (smoothingPool.size() > 0) smoothThePool(gf, smoothingPool, adj, opt.invertNormalsForQuality, opt.sp);

  if (PARANO_QUALITY) {
    errorAndAbortIfNegativeElement(gf, dynamic_cast_vector<MQuadrangle*,MElement*>(gf->quadrangles), "after pool");
  }

  /* Remaining cases, just for stats */
  for (const auto& kv: curveVertexAndIdeal) {
    MVertex* v = kv.first;
    GEdge* ge = dynamic_cast<GEdge*>(v->onWhat());
    if (ge == nullptr) continue;
    auto it = adj.find(v);
    if (it == adj.end()) continue;
    const std::vector<MElement*>& quads = it->second;
    double ideal = kv.second;
    size_t ival = (size_t) clamp(std::round(ideal),1.,4.);
    if (ival == quads.size()) continue;
    stats.nCurveValRemaining += 1;
  }

  return 0;
}

double irregularityEnergy(
    const GFaceMeshPatch& patch,
    const unordered_map<MVertex *, double>& qValIdeal,
    const unordered_map<MVertex *, std::vector<MElement *> >& adj)
{
  double Ir = 0.;
  /* Boundary vertices */
  for (MVertex* v: patch.bdrVertices.front()) {
    double valIdeal = 4.;
    auto it = qValIdeal.find(v);
    if (it != qValIdeal.end()) {
      valIdeal = it->second;
    }
    auto it2 = adj.find(v);
    if (it2 == adj.end()) {
      continue; 
    }
    valIdeal = clamp(std::round(valIdeal),1.,4.);

    double val = (double) it2->second.size();
    Ir += std::pow(valIdeal - val,2);
  }
  /* Interior vertices */
  for (MVertex* v: patch.intVertices) {
    double valIdeal = 4.;
    auto it2 = adj.find(v);
    if (it2 == adj.end()) {
      continue;
    }
    valIdeal = clamp(std::round(valIdeal),1.,4.);
    double val = (double) it2->second.size();
    Ir += std::pow(valIdeal - val,2);
  }
  return Ir;
}

double irregularityEnergy(
    GFace* gf,
    const std::vector<MElement*>& quads,
    const unordered_map<MVertex *, double>& qValIdeal,
    const unordered_map<MVertex *, std::vector<MElement *> >& adj)
{
  GFaceMeshPatch patch;
  bool okp = patchFromElements(gf, quads, patch); 
  if (!okp) return 0.;
  return irregularityEnergy(patch, qValIdeal, adj);
}

int improveInteriorValences(
    GFace* gf,
    const unordered_map<MVertex *, double>& qValIdeal, /* valence on bdr vertices */
    unordered_map<MVertex *, std::vector<MElement *> >& adj,
    DQOptions& opt,
    DQStats& stats
    ) {
  Msg::Debug("- Face %i: improve interior valences", gf->tag());

  std::vector<MVertex*> smoothingPool; /* for smoothing after topological changes */
  smoothingPool.reserve(gf->mesh_vertices.size());

  // TODO IMPORTANT: add strict decrease of irregularity to avoid infinite loops

  /* Priority queue */
  std::priority_queue<std::pair<double,MVertex*>, std::vector<std::pair<double,MVertex*> > > Q; 

  /* Initialize with all very irregular vertices of the face */
  for (const auto& kv: adj) {
    MVertex* v = kv.first;
    GFace* gf = dynamic_cast<GFace*>(v->onWhat());
    if (gf == nullptr) continue;
    auto it = adj.find(v);
    if (it == adj.end()) continue;
    const std::vector<MElement*>& quads = it->second;
    const size_t val = quads.size();
    if (3 <= val && val <= 5) continue;

    /* Build patch with quads adjacent to very irregular vertex */
    GFaceMeshPatch patch;
    bool okp = patchFromElements(gf, quads, patch); 
    if (!okp || patch.bdrVertices.size() != 1) continue;

    double Ir = irregularityEnergy(gf, quads, qValIdeal, adj);
    if (Ir > 0.) Q.push({Ir,v});
  }

  /* Topological replacement loop */
  while (Q.size() > 0) {
    MVertex* v = Q.top().second;
    Q.pop();

    auto it = adj.find(v);
    /* Check if vertex still exists, may have been removed */
    if (it == adj.end()) continue; 
    const std::vector<MElement*>& quads = it->second;
    size_t num = v->getNum();

    /* Build patch with quads adjacent to very irregular vertex */
    GFaceMeshPatch patch;
    bool okp = patchFromElements(gf, quads, patch); 
    if (!okp || patch.bdrVertices.size() != 1) continue;


    /* Get ideal and allowed ranges on the patch boundary */
    std::vector<int> bndIdealValence;
    std::vector<std::pair<int,int> > bndAllowedValenceRange;
    const int dimCurve = 2;
    bool okb = getBoundaryIdealAndAllowedValences(dimCurve, patch, adj, qValIdeal, bndIdealValence, bndAllowedValenceRange);
    if (!okb) continue;

    /* Check if there is a valid disk remeshing */
    GFaceMeshDiff diff;
    std::vector<MElement*> neighborsForGeometry = getNeighbors(patch.elements, adj);
    double minSICNafer = 0.1;
    int sdq = remeshLocalWithDiskQuadrangulation(gf,
        patch.elements, patch.intVertices, patch.bdrVertices.front(), bndIdealValence, bndAllowedValenceRange,
        neighborsForGeometry, minSICNafer, opt.invertNormalsForQuality, opt.sp, diff);
    if (sdq == 0) {
      /* Copy the pointers to update the adjacencies in case success */
      GFaceMeshPatch patchBefore = diff.before;
      GFaceMeshPatch patchAfter = diff.after;

      // GeoLog::add(patchBefore.elements, "-I_v"+std::to_string(v->getNum()));
      // GeoLog::add(patchAfter.elements, "+I_v"+std::to_string(v->getNum()));

      /* Execute the diff on the mesh */
      bool ok = diff.execute(true); /* warning: GFace mesh changes here */
      if (ok) {
        updateAdjacencies(patchBefore, patchAfter, adj);
        append(smoothingPool, patchBefore.intVertices);
        append(smoothingPool, patchBefore.bdrVertices.front());
        stats.nSurfaceValFixed += 1;

        /* If new very irregular vertices have been created,
         * add them to the queue */
        for (MVertex* bv: patchAfter.bdrVertices.front()) {
          auto it2 = adj.find(bv);
          if (it2 == adj.end()) continue; 
          const std::vector<MElement*>& quads2 = it2->second;
          if (quads2.size() > 5) {
            double Ir2 = irregularityEnergy(gf, quads2, qValIdeal, adj);
            if (Ir2 > 0) Q.push({Ir2,bv});
          }
        }
      } else {
        Msg::Error("failed to apply diff, abort");
        abort();
      }
      Msg::Debug("-- interior vertex %li fixed", num);
    } else {
      Msg::Debug("-- failed to fix interior vertex %li", num);
      // GeoLog::add(quads, "!I_v"+std::to_string(v->getNum()));
    }
  }
  // GeoLog::flush();

  if (smoothingPool.size() > 0) smoothThePool(gf, smoothingPool, adj, opt.invertNormalsForQuality, opt.sp);

  /* Remaining cases, just for stats */
  for (const auto& kv: adj) {
    MVertex* v = kv.first;
    GFace* gf = dynamic_cast<GFace*>(v->onWhat());
    if (gf == nullptr) continue;
    auto it = adj.find(v);
    if (it == adj.end()) continue;
    const std::vector<MElement*>& quads = it->second;
    const size_t val = quads.size();
    if (3 <= val && val <= 5) continue;
    stats.nSurfaceValRemaining += 1;
  }

  return 0;
}

int RefineMeshWithBackgroundMeshProjection(GModel* gm) {
  const bool SHOW_INTERMEDIATE_VIEWS = (Msg::GetVerbosity() >= 99);

  const bool SHOW_QUADTRI = SHOW_INTERMEDIATE_VIEWS;
  if (SHOW_QUADTRI) {
    std::vector<MElement*> elements;
    for (GFace* gf: model_faces(gm)) {
      append(elements,dynamic_cast_vector<MTriangle*,MElement*>(gf->triangles));
      append(elements,dynamic_cast_vector<MQuadrangle*,MElement*>(gf->quadrangles));
      // showUVParametrization(gf,dynamic_cast_vector<MTriangle*,MElement*>(gf->triangles),"quadtri_uvs");
      // showUVParametrization(gf,dynamic_cast_vector<MQuadrangle*,MElement*>(gf->quadrangles),"quadtri_uvs");
    }
    GeoLog::add(elements, "qqs_quadtri");
    GeoLog::flush();
  }


  Msg::Info("Refine mesh (midpoint subdivision, with background projection) ...");


  bool linear = true; 
  RefineMesh(gm, linear, true, false);

  if (Msg::GetVerbosity() >= 99) {
    std::unordered_map<std::string,double> stats;
    appendQuadMeshStatistics(gm, stats, "MPS_");
    printStatistics(stats,"Quad mesh after subdivision, before projection:");
  }

  GlobalBackgroundMesh* bmesh = nullptr;
  if (backgroudMeshExists(BMESH_NAME)) {
    bmesh = &(getBackgroundMesh(BMESH_NAME));
  } else {
    Msg::Warning("refine mesh with background projection: no background mesh, using CAD projection (slow)");
  }

  std::vector<GEdge*> edges = model_edges(gm);

#if defined(_OPENMP)
#pragma omp parallel for schedule(dynamic)
#endif
  for (size_t e = 0; e < edges.size(); ++e) {
    GEdge* ge = edges[e];
    if (CTX::instance()->mesh.meshOnlyVisible && !ge->getVisibility()) continue;
    if (ge->lines.size() == 0 || ge->mesh_vertices.size() == 0) continue;

    Msg::Debug("- Curve %i: project midpoints on curve", ge->tag());
    unordered_map<MVertex*,MVertex*> old2new_ge;
    unordered_map<MVertex*,SPoint3> backupPositionLinear;
    double tPrev = 0;
    for (size_t i = 0; i < ge->mesh_vertices.size(); ++i) {
      MVertex* v = ge->mesh_vertices[i];
      MEdgeVertex* mev = dynamic_cast<MEdgeVertex*>(v);
      if (mev == nullptr) {
        double t = tPrev;
        GPoint proj = ge->closestPoint(v->point(), t);
        if (proj.succeeded()) {
          /* Need to change the type of the MVertex */
          MVertex *v2 = new MEdgeVertex(proj.x(),proj.y(),proj.z(),ge,proj.u());
          tPrev = proj.u();
          ge->mesh_vertices[i] = v2;
          old2new_ge[v] = v2;
          backupPositionLinear[v2] = v->point();
          delete v;
        } else {
          Msg::Warning("- Edge %i, vertex %li: curve projection failed", ge->tag(), v->getNum());
          MVertex *v2 = new MEdgeVertex(v->point().x(),v->point().y(),v->point().z(), ge, tPrev);
          ge->mesh_vertices[i] = v2;
          old2new_ge[v] = v2;
          backupPositionLinear[v2] = v->point();
          delete v;
        }
        tPrev = t;
      }
    }

    bool qualityOk = true;

    /* Update Lines */
    for (MLine* l: ge->lines) for (size_t lv = 0; lv < 2; ++lv) {
      MVertex* v = l->getVertex(lv);
      auto it = old2new_ge.find(v);
      if (it != old2new_ge.end()) {
        l->setVertex(lv,it->second);
      }
    }

    /* Update adjacent faces */
    for (GFace* gf: ge->faces()) {
      for (size_t i = 0; i < gf->getNumMeshElements(); ++i) {
        MElement* e = gf->getMeshElement(i);
        for (size_t lv = 0; lv < e->getNumVertices(); ++lv) {
          MVertex* v = e->getVertex(lv);
          auto it = old2new_ge.find(v);
          if (it != old2new_ge.end()) {
            e->setVertex(lv,it->second);
          }
        }
      }

      /* Check quality of quads */
      if (gf->quadrangles.size() > 0) {
        double sicnMin, sicnAvg;
        computeSICN(dynamic_cast_vector<MQuadrangle*,MElement*>(gf->quadrangles), sicnMin, sicnAvg);
        if (sicnMin < 0.) {
          Msg::Warning("- refine with projection: quality negative (%.3f) on face %i after curve %i projection, rollback", 
              sicnMin, gf->tag(), ge->tag());
          qualityOk = false;
        }
      }
    }

    if (!qualityOk) { /* restore positions on the curve */
      for (auto& kv: backupPositionLinear) {
        kv.first->setXYZ(kv.second);
      }
    }
  }

  std::vector<GFace*> faces = model_faces(gm);
#if defined(_OPENMP)
#pragma omp parallel for schedule(dynamic)
#endif
  for (size_t f = 0; f < faces.size(); ++f) {
    GFace* gf = faces[f];
    if (CTX::instance()->mesh.meshOnlyVisible && !gf->getVisibility()) continue;
    if (CTX::instance()->debugSurface > 0 &&
        gf->tag() != CTX::instance()->debugSurface) continue;
    if (gf->triangles.size() == 0 && gf->quadrangles.size() == 0) continue;

    SurfaceProjector* sp = nullptr;
    if (bmesh) {
      auto it = bmesh->faceBackgroundMeshes.find(gf);
      if (it == bmesh->faceBackgroundMeshes.end()) {
        Msg::Error("background mesh not found for face %i", gf->tag());
        continue;
      }

      /* Get pointers to triangles in the background mesh */
      std::vector<MTriangle*> triangles(it->second.triangles.size());
      for (size_t i = 0; i < it->second.triangles.size(); ++i) {
        triangles[i] = &(it->second.triangles[i]);
      }

      sp = new SurfaceProjector();
      bool oki = sp->initialize(gf,triangles);
      if (!oki) {
        Msg::Warning("failed to initialize surface projector");
        delete sp;
        sp = nullptr;
      }
    }

    /* Project the vertices which have been introduced by the RefineMesh */
    Msg::Debug("- Face %i: project midpoints on surface", gf->tag());
    bool evalOnCAD = gf->haveParametrization();
    bool projOnCad = false;
    if (evalOnCAD && !haveNiceParametrization(gf)) {
      /* Strong disortion in parametrization, use projection */
      evalOnCAD = false;
      projOnCad = true;
    }

    unordered_map<MVertex*,MVertex*> old2new_gf;
    unordered_map<MVertex*,SPoint3> backupPositionLinear;

    for (size_t i = 0; i < gf->mesh_vertices.size(); ++i) {
      MVertex* v = gf->mesh_vertices[i];
      MFaceVertex* mfv = dynamic_cast<MFaceVertex*>(v);
      if (mfv == nullptr) {
        GPoint proj;
        if (sp != nullptr) {
          proj = sp->closestPoint(v->point().data(), evalOnCAD, projOnCad);

          if (!proj.succeeded() && gf->haveParametrization()) {
            double uvg[2] = {0.,0.};
            proj = gf->closestPoint(v->point(), uvg);
          }
        } else {
          double uvg[2] = {0.,0.};
          proj = gf->closestPoint(v->point(), uvg);
        }
        if (proj.succeeded()) {
          /* Need to change the type of the MVertex */
          MVertex* v2 = new MFaceVertex(proj.x(),proj.y(),proj.z(),gf,proj.u(),proj.v());
          gf->mesh_vertices[i] = v2;
          backupPositionLinear[v2] = v->point();
          old2new_gf[v] = v2;
          delete v;
        } else {
          MVertex* v2 = new MFaceVertex(v->point().x(),v->point().y(),v->point().z(),gf,0.,0.);
          gf->mesh_vertices[i] = v2;
          backupPositionLinear[v2] = v->point();
          old2new_gf[v] = v2;
          delete v;
          Msg::Warning("- Face %i, vertex %li: surface projection failed", gf->tag(), v->getNum());
        }
      }
    }

    /* Update elements */
    for (size_t i = 0; i < gf->getNumMeshElements(); ++i) {
      MElement* e = gf->getMeshElement(i);
      for (size_t lv = 0; lv < e->getNumVertices(); ++lv) {
        MVertex* v = e->getVertex(lv);
        auto it2 = old2new_gf.find(v);
        if (it2 != old2new_gf.end()) {
          e->setVertex(lv,it2->second);
        }
      }
    }

    /* Check quality of quads */
    if (gf->quadrangles.size() > 0) {
      bool qualityOk = true;
      double sicnMin, sicnAvg;
      computeSICN(dynamic_cast_vector<MQuadrangle*,MElement*>(gf->quadrangles), sicnMin, sicnAvg);
      if (sicnMin < 0.) {
        Msg::Warning("- refine with projection: quality negative (%.3f) on face %i after projection, rollback", 
            sicnMin, gf->tag());
        qualityOk = false;
      }
      if (!qualityOk) {
        for (auto& kv: backupPositionLinear) {
          kv.first->setXYZ(kv.second);
        }
      }
    }

    /* Smooth geometry (quick) */
    if (sp != nullptr) {
      double timeMax = 0.3;
      optimizeGeometryQuadMesh(gf, sp, timeMax);
    }

    if (sp != nullptr) delete sp;
  }

  const bool SHOW_QUADINIT = SHOW_INTERMEDIATE_VIEWS;
  if (SHOW_QUADINIT) {
    std::vector<MElement*> elements;
    for (GFace* gf: model_faces(gm)) {
      append(elements,dynamic_cast_vector<MQuadrangle*,MElement*>(gf->quadrangles));
      // showUVParametrization(gf,dynamic_cast_vector<MQuadrangle*,MElement*>(gf->quadrangles),"quad_uvs");
    }
    GeoLog::add(elements, "qqs_quadinit");
    GeoLog::flush();
  }

  if (Msg::GetVerbosity() >= 99) {
    std::unordered_map<std::string,double> stats;
    appendQuadMeshStatistics(gm, stats, "Mesh_");
    printStatistics(stats,"Quad mesh after subdivision, projection and small smoothing:");
  }

  return 0;
}


int optimizeQuadMeshWithDiskQuadrangulationRemeshing(GFace* gf) {
  if (gf->triangles.size() > 0 || gf->quadrangles.size() == 0) return -1;

  // Disk quadrangulation remeshing use the CAD normals to compute the signed quality,
  // so the orientation is important.
  bool invertNormals = meshOrientationIsOppositeOfCadOrientation(gf);

  /* For each bdr vertex, compute the ideal valence (based on angle viewed from the face) */
  unordered_map<MVertex *, double> qValIdeal;
  computeBdrVertexIdealValence(gf->quadrangles, qValIdeal);

  /* Vertex to quads */
  unordered_map<MVertex *, std::vector<MElement *> > adj;
  for (MQuadrangle* f: gf->quadrangles) for (size_t lv = 0; lv < 4; ++lv) {
    MVertex* v = f->getVertex(lv);
    adj[v].push_back(f);
  }

  DQStats stats;
  DQOptions opt;
  opt.invertNormalsForQuality = invertNormals;
  bool alwaysBuildSurfaceProjector = true;
  if (alwaysBuildSurfaceProjector || !haveNiceParametrization(gf) || (gf->periodic(0) || gf->periodic(1))) {
    opt.sp = new SurfaceProjector();
    bool okf = fillSurfaceProjector(gf, opt.sp);
    if (!okf) {
      Msg::Error("- Face %i: failed to get a surface projector", gf->tag());
      return false;
    }
  }

  double t1 = Cpu();

  int sc = improveCornerValences(gf, qValIdeal, adj, opt, stats);
  if (sc != 0) {
    Msg::Warning("optimize quad topology: failed to improve corner valences");
  }
  if (PARANO_QUALITY) {
    errorAndAbortIfNegativeElement(gf, dynamic_cast_vector<MQuadrangle*,MElement*>(gf->quadrangles), "after corner");
  }

  int scu = improveCurveValences(gf, qValIdeal, adj, opt, stats);
  if (scu != 0) {
    Msg::Warning("optimize quad topology: failed to improve curve valences");
  }
  if (PARANO_QUALITY) {
    errorAndAbortIfNegativeElement(gf, dynamic_cast_vector<MQuadrangle*,MElement*>(gf->quadrangles), "after curve");
  }

  int sci = improveInteriorValences(gf, qValIdeal, adj, opt, stats);
  if (sci != 0) {
    Msg::Warning("optimize quad topology: failed to improve interior valences");
  }
  if (PARANO_QUALITY) {
    errorAndAbortIfNegativeElement(gf, dynamic_cast_vector<MQuadrangle*,MElement*>(gf->quadrangles), "after interior");
  }

  /* Smooth geometry (quick) */
  double timeMax = 0.3;
  optimizeGeometryQuadMesh(gf, opt.sp, timeMax);

  if (opt.sp) {
    delete opt.sp;
    opt.sp = nullptr;
  }

  double t2 = Cpu();

  Msg::Info("- Face %i: disk quadrangulation remeshing, improved valence on %li/%li/%li corner/curve/surface vertices (in %.3f sec), remaining non-ideal: %li/%li/%li",
      gf->tag(),
      stats.nCornerValFixed, stats.nCurveValFixed, stats.nSurfaceValFixed,
      t2-t1,
      stats.nCornerValRemaining, stats.nCurveValRemaining, stats.nSurfaceValRemaining);

  if (PARANO_QUALITY) {
    errorAndAbortIfNegativeElement(gf, dynamic_cast_vector<MQuadrangle*,MElement*>(gf->quadrangles), "after geom optim");
  }

  return 0;
}

int quadMeshingOfSimpleFacesWithPatterns(GModel* gm, double minimumQualityRequired) {
  std::vector<GFace*> faces = model_faces(gm);
  Msg::Info("Pattern-based quad meshing of simple CAD faces ...", faces.size());

  initQuadPatterns();

#if defined(_OPENMP)
#pragma omp parallel for schedule(dynamic)
#endif
  for (size_t f = 0; f < faces.size(); ++f) {
    GFace* gf = faces[f];
    if (gf->meshStatistics.status != GFace::PENDING) continue;
    if (CTX::instance()->mesh.meshOnlyVisible && !gf->getVisibility()) continue;
    if (CTX::instance()->debugSurface > 0 &&
        gf->tag() != CTX::instance()->debugSurface) continue;
    if (gf->triangles.size() > 0 || gf->quadrangles.size() == 0) continue;

    bool invertNormals = meshOrientationIsOppositeOfCadOrientation(gf);
    meshFaceWithGlobalPattern(gf, invertNormals, minimumQualityRequired);
  }

  std::unordered_map<std::string,double> stats;
  appendQuadMeshStatistics(gm, stats, "Mesh_");
  printStatistics(stats,"Quad mesh after simple face pattern-based remeshing:");

  return 0;
}



int optimizeTopologyWithDiskQuadrangulationRemeshing(GModel* gm) {

  Msg::Info("Optimize topology of quad meshes with disk quadrangulation remeshing ...");

  initDiskQuadrangulations();

#if defined(_OPENMP)
#pragma omp parallel for schedule(dynamic)
#endif
  std::vector<GFace*> faces = model_faces(gm);
  for (size_t f = 0; f < faces.size(); ++f) {
    GFace* gf = faces[f];
    if (gf->meshStatistics.status != GFace::PENDING) continue;
    if (CTX::instance()->mesh.meshOnlyVisible && !gf->getVisibility()) continue;
    if (CTX::instance()->debugSurface > 0 &&
        gf->tag() != CTX::instance()->debugSurface) continue;
    if (gf->triangles.size() > 0 || gf->quadrangles.size() == 0) continue;

    optimizeQuadMeshWithDiskQuadrangulationRemeshing(gf);
  }

  std::unordered_map<std::string,double> stats;
  appendQuadMeshStatistics(gm, stats, "Mesh_");
  printStatistics(stats,"Quad mesh after disk quadrangulation remeshing:");

  if (stats["Mesh_SICN_min"] < 0.) {
    Msg::Warning("negative quality on some quads");
  }

  return 0;
}

int optimizeTopologyWithCavityRemeshing(GModel* gm) {
  std::vector<GFace*> faces = model_faces(gm);
  Msg::Info("Optimize topology of quad meshes with cavity remeshing (%li faces) ...", faces.size());

  initQuadPatterns();

#if defined(_OPENMP)
#pragma omp parallel for schedule(dynamic)
#endif
  for (size_t f = 0; f < faces.size(); ++f) {
    GFace* gf = faces[f];
    if (gf->meshStatistics.status != GFace::PENDING) continue;
    if (CTX::instance()->mesh.meshOnlyVisible && !gf->getVisibility()) continue;
    if (CTX::instance()->debugSurface > 0 &&
        gf->tag() != CTX::instance()->debugSurface) continue;
    if (gf->triangles.size() > 0 || gf->quadrangles.size() == 0) continue;
      gf->meshStatistics.status = GFace::DONE;

    /* Get singularities from global storage */
    std::vector<std::pair<SPoint3,int> > singularities;
    auto it = global_singularities.find(gf);
    if (it == global_singularities.end()) {
      Msg::Warning("optimize topology with cavity remeshing: cross field singularities not found for face %i", gf->tag());
      Msg::Warning("TODO: compute cross field on quad mesh !");
    } else {
      singularities = it->second;
    }

    bool invertNormals = meshOrientationIsOppositeOfCadOrientation(gf);
    improveQuadMeshTopologyWithCavityRemeshing(gf, singularities, invertNormals);
  }

  std::unordered_map<std::string,double> stats;
  appendQuadMeshStatistics(gm, stats, "Mesh_");
  printStatistics(stats,"Quad mesh after cavity remeshing:");

  writeStatistics(stats, "quadqs_statistics.json");

  GeoLog::flush();

  return 0;
}

#else
/* else: without QUADMESHINGTOOLS module*/

int BuildBackgroundMeshAndGuidingField( GModel* gm, bool overwriteGModelMesh, bool deleteGModelMeshAfter, int N) {
  Msg::Error("Module QUADMESHINGTOOLS required for function BuildBackgroundMeshAndGuidingField");
  return -10;
}
bool backgroundMeshAndGuidingFieldExists(GModel* gm) {
  Msg::Error("Module QUADMESHINGTOOLS required for function backgroundMeshAndGuidingFieldExists");
  return -10;
}
int optimizeTopologyWithDiskQuadrangulationRemeshing(GModel* gm) {
  Msg::Error("Module QUADMESHINGTOOLS required for function optimizeTopologyWithCavityRemeshing");
  return -10;
}
int optimizeTopologyWithCavityRemeshing(GModel* gm) {
  Msg::Error("Module QUADMESHINGTOOLS required for function optimizeTopologyWithCavityRemeshing");
  return -10;
}
int quadMeshingOfSimpleFacesWithPatterns(GModel* gm, double minimumQualityRequired) {
  Msg::Error("Module QUADMESHINGTOOLS required for function quadMeshingOfSimpleFacesWithPatterns");
  return -10;
}
int RefineMeshWithBackgroundMeshProjection(GModel* gm) {
  Msg::Error("Module QUADMESHINGTOOLS required for function RefineMeshWithBackgroundMeshProjection");
  return -10;
}

#endif
/* endif: QUADMESHINGTOOLS*/


int transferSeamGEdgesVerticesToGFace(GModel* gm) {
  for (GFace* gf: gm->getFaces()) {
    /* Transfer the vertices from seam GEdge to associated GFace */
    std::unordered_map<MVertex*,MVertex*> old2new;
    for (GEdge* ge: gf->edges()) {
      if (ge->isSeam(gf) && ge->faces().size() == 1 && ge->faces()[0] == gf) {
        /* GEdge interior vertices */
        for (MVertex* ov: ge->mesh_vertices) {
          auto it = old2new.find(ov);
          if (it != old2new.end()) continue; /* already changed */
          SPoint3 p = ov->point();
          double t;
          ov->getParameter(0,t);
          SPoint2 uv = ge->reparamOnFace(gf, t, -1);
          MVertex *nv = new MFaceVertex(p.x(),p.y(),p.z(),gf,uv[0],uv[1]);
          nv->setParameter(0,uv[0]);
          nv->setParameter(1,uv[1]);
          gf->mesh_vertices.push_back(nv);
          old2new[ov] = nv;
          delete ov;
        }
        ge->mesh_vertices.clear();
        for (size_t i = 0; i < ge->lines.size(); ++i) {
          delete ge->lines[i];
        }
        ge->lines.clear();

        /* GEdge boundary vertices */
        for (GVertex* gv: ge->vertices()) if (gv->mesh_vertices.size() == 1) {
          size_t nbOtherCurves = 0;
          for (GEdge* ge2: gv->edges()) if (ge2 != ge) {
            if (ge2->vertices().front() == ge2->vertices().back() 
                && ge2->length() == 0.) { /* Empty curve */
              continue;
            }
            nbOtherCurves += 1;
          }
          if (nbOtherCurves > 0) continue;
          MVertex* ov = gv->mesh_vertices[0];
          auto it = old2new.find(ov);
          if (it != old2new.end()) continue; /* already changed */
          SPoint3 p = ov->point();
          SPoint2 uv = gv->reparamOnFace(gf,0);
          MVertex *nv = new MFaceVertex(p.x(),p.y(),p.z(),gf,uv[0],uv[1]);
          nv->setParameter(0,uv[0]);
          nv->setParameter(1,uv[1]);
          gf->mesh_vertices.push_back(nv);
          old2new[ov] = nv;
          delete ov;
          gv->mesh_vertices.clear();
        }
      }
    }
    if (old2new.size() > 0) {
      for (MElement* f: gf->triangles) for (size_t lv = 0; lv < 3; ++lv){ 
        MVertex* v = f->getVertex(lv);
        auto it = old2new.find(v);
        if (it != old2new.end()) {
          f->setVertex(lv, it->second);
        }
      }
      for (MElement* f: gf->quadrangles) for (size_t lv = 0; lv < 4; ++lv){ 
        MVertex* v = f->getVertex(lv);
        auto it = old2new.find(v);
        if (it != old2new.end()) {
          f->setVertex(lv, it->second);
        }
      }
    }
  }
  return 0;
}

QuadqsContextUpdater::QuadqsContextUpdater() {
  algo2d = CTX::instance()->mesh.algo2d;
  recombineAll = CTX::instance()->mesh.recombineAll;
  algoRecombine = CTX::instance()->mesh.algoRecombine;
  recombineOptimizeTopology = CTX::instance()->mesh.recombineOptimizeTopology;
  lcFactor = CTX::instance()->mesh.lcFactor;
  lcMin = CTX::instance()->mesh.lcMin;
  lcMax = CTX::instance()->mesh.lcMax;
  lcFromPoints = CTX::instance()->mesh.lcFromPoints;
  minCurveNodes = CTX::instance()->mesh.minCurveNodes;
  minCircleNodes = CTX::instance()->mesh.minCircleNodes;

  setQuadqsOptions();
}

QuadqsContextUpdater::~QuadqsContextUpdater() {
  restoreInitialOption();
}

void QuadqsContextUpdater::setQuadqsOptions() {
  Msg::Debug("set special quadqs options in the global context");
  CTX::instance()->mesh.algo2d = ALGO_2D_QUAD_QUASI_STRUCT;
  CTX::instance()->mesh.recombineAll = 1;
  CTX::instance()->mesh.algoRecombine = 0;
  CTX::instance()->mesh.recombineOptimizeTopology = 0;
  CTX::instance()->mesh.lcFactor = 1.;
  CTX::instance()->mesh.lcMin = 0.;
  CTX::instance()->mesh.lcMax = 1.e22;
  CTX::instance()->mesh.lcFromPoints = 0;
  CTX::instance()->mesh.minCurveNodes = 0;
  CTX::instance()->mesh.minCircleNodes = 0;
}

void QuadqsContextUpdater::restoreInitialOption() {
  Msg::Debug("restore options in the global context");
  CTX::instance()->mesh.algo2d = algo2d;
  CTX::instance()->mesh.recombineAll = recombineAll;
  CTX::instance()->mesh.algoRecombine = algoRecombine;
  CTX::instance()->mesh.recombineOptimizeTopology = recombineOptimizeTopology;
  CTX::instance()->mesh.lcFactor = lcFactor;
  CTX::instance()->mesh.lcMin = lcMin;
  CTX::instance()->mesh.lcMax = lcMax;
  CTX::instance()->mesh.lcFromPoints = lcFromPoints;
  CTX::instance()->mesh.minCurveNodes = minCurveNodes;
  CTX::instance()->mesh.minCircleNodes = minCircleNodes;
}

