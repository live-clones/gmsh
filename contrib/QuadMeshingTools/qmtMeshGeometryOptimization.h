// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

#pragma once

#include <float.h>
#include <cstdint>
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
enum SmoothingKernel {
  Laplacian,
  WinslowFDM,
  AngleBased
};

struct GeomOptimOptions {
  double useDmoIfSICNbelow = 0.1; /* use the DMO kernel if SICN quality below threshold */
  size_t outerLoopIterMax = 100; /* maximum number of loops over all vertices */
  double timeMax = DBL_MAX; /* stop smoothing is timeMax elapsed */
  bool invertCADNormals = false; /* invert the CAD normals for the quality computation */
  SurfaceProjector* sp = nullptr; /* if present, surface projection is used instead of CAD */
  double smartMinThreshold = -DBL_MAX; /* do not displace if inducing min(SICN) < smartMinThreshold */
  bool qualityRangeTechnique = false;
  bool localLocking = false; /* Lock if small displacement, unlocked neighbors else */
  double dxLocalMax = 1.e-5; /* lock a vertex if dx < dxLocalMax * local_size */
  double dxGlobalMax = 1.e-5; /* stop if sum(dx) < dxGlobalMax * sum(dx_0) */
  double qualityRangeMin = 0.5;
  double qualityRangeMax = 0.8;
  bool withBackup = true; /* save the geometry before, restore if quality decreased */
  bool project = true; /* project with SurfaceProjector/CAD */
  bool force3DwithProjection = false;
  SmoothingKernel kernelRegular = SmoothingKernel::WinslowFDM;
  SmoothingKernel kernelIrregular = SmoothingKernel::Laplacian;
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

/**
 * @brief High-level function which try to make good parameter choices
 *        automatically.
 *
 * @param gf The face containing the quad mesh to smooth
 * @param sp Surface projector (faster than CAD projection)
 * @param timeMax Time budget for the smoothing
 * @param withBackup Rollback if quality decreased
 *
 * @return true if success
 */
bool optimizeGeometryQuadMesh(GFace* gf, SurfaceProjector* sp = nullptr, double timeMax = DBL_MAX, bool withBackup = true);

/**
 * @brief High-level function which try to make good parameter choices
 *        automatically.
 *
 * @param gf The face containing the quad-tri mesh to smooth
 * @param sp Surface projector (faster than CAD projection)
 * @param timeMax Time budget for the smoothing
 *
 * @return true if success
 */
bool optimizeGeometryQuadTriMesh(GFace* gf, SurfaceProjector* sp = nullptr, double timeMax = DBL_MAX);


class GeometryOptimizer {
  public:
    enum PlanarMethod {
      MeanPlane,
      ParamCAD
    };

    GeometryOptimizer() {};
    bool initialize(GFaceMeshPatch& patch, SurfaceProjector* sp = nullptr);

    bool smoothWithKernel(
        SmoothingKernel kernelRegular,
        SmoothingKernel kernelIrregular,
        double timeMax = DBL_MAX,
        int iterMax = 1000,
        double withBackup = false,
        bool localLocking = false, /* Lock if small displacement, unlocked neighbors else */
        double dxLocalMax = 1.e-5, /* lock a vertex if dx < dxLocalMax * local_size */
        double dxGlobalMax = 1.e-5, /* stop if sum(dx) < dxGlobalMax * sum(dx_0) */
        bool project = true, /* project with SurfaceProjector */
        bool finalCADprojection = true, /* project with real CAD at the end */
        bool smartVariant = false  /* compute SICN before/after each point displacement, reject quality decrease */
        );

    bool smoothWithWinslowUntangler(
        PlanarMethod planar,
        int iterMax = 1000,
        double withBackup = false,
        bool finalCADprojection = true,
        double nonPlanarRatioMax = 0.1 /* if using mean plane, check the orthogonal deviation is less than the ratio */
        );

  public:
    GFaceMeshPatch* patchPtr = nullptr;
    SurfaceProjector* sp = nullptr;
  protected:
    std::vector<std::array<double,3> > points;
    std::vector<std::array<double,2> > uvs;
    std::vector<std::array<uint32_t,4> > quads;
    std::vector<size_t> one_ring_first;
    std::vector<uint32_t> one_ring_values;
    std::vector<MVertex*> new2old;
    std::unordered_map<MVertex*,uint32_t> old2new;
    size_t nFree =0;
};

bool optimizeGeometryQuadqs(GModel* gm);
