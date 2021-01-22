// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.


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

#if defined(HAVE_QUADMESHINGTOOLS)

/* QuadMeshingTools includes */
#include "cppUtils.h"
#include "qmtCrossField.h"


using namespace CppUtils;

std::vector<GFace*> model_faces(GModel* gm) {
  std::vector<GFace*> faces;
  for(GModel::fiter it = gm->firstFace(); it != gm->lastFace(); ++it) {
    faces.push_back(*it);
  }
  return faces;
}

std::vector<GEdge*> face_edges(GFace* gf) {
  std::vector<GEdge*> edges;
  for (GEdge* ge: gf->edges()) {
    edges.push_back(ge);
  }
  for (GEdge* ge: gf->embeddedEdges()) {
    edges.push_back(ge);
  }
  sort_unique(edges);
  return edges;
}

std::vector<GEdge*> model_edges(GModel* gm) {
  std::vector<GEdge*> edges;
  std::vector<GFace*> faces = model_faces(gm);
  for (GFace* gf: faces) append(edges,face_edges(gf));
  sort_unique(edges);
  return edges;
}

int BuildBackgroundMeshAndGuidingField(GModel* gm, bool overwriteGModelMesh, bool deleteGModelMesh) {
  if(CTX::instance()->abortOnError && Msg::GetErrorCount()) return 0;
  if (CTX::instance()->mesh.algo2d != ALGO_2D_PACK_PRLGRMS
      && CTX::instance()->mesh.algo2d != ALGO_2D_QUAD_QUASI_STRUCT) return 0;

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

  GlobalBackgroundMesh& bmesh = getBackgroundMesh("bmesh_quadqs");
  bool overwrite = true;
  int status = bmesh.importGModelMeshes(gm, overwrite);
  if (status != 0) {
    Msg::Error("failed to import model mesh in background mesh");
    return -1;
  }

  if (deleteGModelMesh) {
    Msg::Debug("delete GModel mesh");
    std::for_each(gm->firstRegion(), gm->lastRegion(), deMeshGRegion());
    std::for_each(gm->firstFace(), gm->lastFace(), deMeshGFace());
    std::for_each(gm->firstRegion(), gm->lastRegion(), deMeshGRegion());
  }

  /* Build cross field on background mesh */
  {
    std::vector<GFace*> faces = model_faces(gm);

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
        continue;
      }
    }

  }


  return 0;
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


