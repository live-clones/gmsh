// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESH_QUAD_GEOMETRY
#define MESH_QUAD_GEOMETRY

#include <vector>

class GFace;
class MVertex;
class MElement;
class MQuadrangle;
class SPoint3;
class SurfaceProjector;

int quadQualityStats(const std::vector<MElement*>& elements, double& qualityMin, double& qualityAvg);
int quadQualityStats(const std::vector<MQuadrangle*>& elements, double& qualityMin, double& qualityAvg);


enum MesquiteSmoother {
  MesquiteUntangler,
  MesquiteShapeImprovement,
  MesquitePaverMinEdgeLengthWrapper,
};

struct MesquiteOptions {
  MesquiteSmoother smoother;
  double cpu_time_limit_sec = 0.;
  int outer_iteration_limit = 0;
  int use_real_CAD = 0;
};

int optimizeQuadCavity(
    const MesquiteOptions& opt,
    SurfaceProjector* sp,
    const std::vector<MElement*>& elements,
    const std::vector<MVertex*>& freeVertices,
    double& qualityMin,
    double& qualityAvg);

int optimizeQuadMeshWithSubPatches(
    GFace* gf,
    SurfaceProjector* sp,
    double& qualityMin,
    double& qualityAvg);


int optimizeQuadGeometry(GFace* gf);


enum LocalSmoothingKernel {
  Laplacian,
  WinslowAtRegular,
  AngleBased
};

bool smoothElementsWithLocalKernel(
    LocalSmoothingKernel kernel,
    GFace* gf,
    SurfaceProjector* sp,
    const std::vector<MElement*>& elements,
    const std::vector<MVertex*>& freeVertices,
    bool smartVariant = false, /* check quality of elements after each move, slow */
    size_t iterMaxOuterLoop = 0,
    double global_dx_reduction = 1.e-3, /* stop smoothing it the while deplacement is less than global_dx_reduction * dx0 */
    double local_dx_reduction = 1.e-5 /* lock a node if it moved less than local_dx_reduction * local_size */
    );

#endif
