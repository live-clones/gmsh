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
class SPoint3;
class SurfaceProjector;

int quadQualityStats(const std::vector<MElement*>& elements, double& qualityMin, double& qualityAvg);


enum MesquiteSmoother {
  MesquiteShapeImprovement,
  MesquitePaverMinEdgeLengthWrapper
};

int optimizeQuadCavity(
    MesquiteSmoother smoother,
    SurfaceProjector* sp,
    const std::vector<MElement*>& elements,
    std::vector<MVertex*>& freeVertices,
    double& qualityMin,
    double& qualityAvg);


int optimizeQuadGeometry(GFace* gf);

#endif
