// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESH_GREGION_HXT_H
#define MESH_GREGION_HXT_H

#include <vector>

class GVolume;
class MNode;
class MTetrahedron;

int meshGRegionHxt(std::vector<GVolume *> &regions);
void delaunayMeshIn3DHxt(std::vector<MNode *> &points,
                         std::vector<MTetrahedron *> &tets);
#endif
