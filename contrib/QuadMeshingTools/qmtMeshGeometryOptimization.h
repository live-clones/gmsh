// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

#pragma once

#include <float.h>
#include "qmtMeshUtils.h"

class SurfaceProjector;

/**
 * @brief Mesh optimization statistics
 */
struct GeomOptimStats {
  size_t nFree = 0;
  size_t nLock = 0;
  double timeCpu = 0.;
  size_t outerLoopIter = 0;
  double sicnMinBefore = 0.;
  double sicnMinAfter = 0.;
  double sicnAvgBefore = 0.;
  double sicnAvgAfter = 0.;
  void print();
};

/**
 * @brief Optimize the vertex position inside a patch by
 *        smoothing the CAD parametric coordinates with
 *        a Laplacian solver: Du=0, Dv=0
 *        The patch boundary is fixed.
 *        Use direct solver and arithmetric average to ensure
 *        maximum principle.
 *        Not always applicable: if no param, if the patch contains a CAD uv singularity
 *
 * @param[in,out] patch The mesh patch to smooth. The new positions and uv are directly updated 
 *                      in the MVertex instances.
 * @param[out] stats Some statistics on the smoothing
 *
 * @return 0 if success
 */
int patchOptimizeGeometryGlobal(
    GFaceMeshPatch& patch, 
    GeomOptimStats& stats);

/**
 * @brief Options for the kernel-based explicit untangling/smoothing.
 * Kernels:
 * - DMO (brute-force uv sampling) if low quality
 * - Winslow if regular vertex
 * - Angle-based smoothing is irregular vertex
 */
struct GeomOptimOptions {
  double useDmoIfSICNbelow = 0.1; /* use the DMO kernel if SICN quality below threshold */
  size_t outerLoopIterMax = 100; /* maximum number of loops over all vertices */
  double timeMax = DBL_MAX; /* stop smoothing is timeMax elapsed */
  bool invertCADNormals = false; /* invert the CAD normals for the quality computation */
  SurfaceProjector* sp = nullptr; /* if present, surface projection is used instead of CAD */
  double smartMinThreshold = -DBL_MAX; /* do not displace if inducing min(SICN) < smartMinThreshold */
  bool qualityRangeTechnique = false;
  bool localLocking = true; /* Lock if small displacement, unlocked neighbors else */
  double dxLocalMax = 1.e-5; /* If not smart and localLocking, lock a vertex if moved less than dxLocalMax*local_size */
  double qualityRangeMin = 0.5;
  double qualityRangeMax = 0.8;
  bool withBackup = true; /* save the geometry before, restore if quality decreased */
};

/**
 * @brief Optimize the mesh by iteratively moving the vertices (explicit approach).
 *        The patch boundary is fixed.
 *        Require a parametrization on the face.
 *
 * @param[in,out] patch The mesh patch to smooth. The new positions and uv are directly updated 
 *                      in the MVertex instances.
 * @param[in] opt The optimization parameters
 * @param[out] stats Some statistics on the smoothing
 *
 * @return true if success
 */
bool patchOptimizeGeometryWithKernel(
    GFaceMeshPatch& patch, 
    const GeomOptimOptions& opt,
    GeomOptimStats& stats);

/**
 * @brief Compute minimum and average SICN quality of elements
 *
 * @param[in] elements The elements on which to measure the quality
 * @param[out] sicnMin Minimum element SICN quality
 * @param[out] sicnAvg Average element SICN quality
 */
void computeSICN(const std::vector<MElement*>& elements, double& sicnMin, double& sicnAvg);


/**
 * @brief Project the patch interior vertices on the surface.
 *        If no parametrization, only the SurfaceProjector is used.
 *        If param, the SurfaceProjector is used as a initial guess.
 *
 * @param patch The patch containing the vertices
 * @param sp If not nullptr, use it to project
 *
 * @return true if success
 */
bool patchProjectOnSurface(GFaceMeshPatch& patch, SurfaceProjector* sp = nullptr);

