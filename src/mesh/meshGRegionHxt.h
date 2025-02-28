// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESH_GREGION_HXT_H
#define MESH_GREGION_HXT_H

#include <vector>

class GRegion;
class MVertex;
class MTetrahedron;

int meshGRegionHxt(std::vector<GRegion *> &regions);
void delaunayMeshIn3DHxt(std::vector<MVertex *> &points,
                         std::vector<MTetrahedron *> &tets);
#endif
