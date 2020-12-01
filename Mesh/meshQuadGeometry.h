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

#endif
