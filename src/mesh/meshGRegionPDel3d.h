// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESH_GREGION_PDEL3D_H
#define MESH_GREGION_PDEL3D_H

#include <vector>

class MVertex;
class GRegion;
class MTetrahedron;

// Delaunay tetrahedralization of a point set with the pdel3d kernel; the
// vertices are not reordered, the tets reference them directly
void delaunayMeshIn3DPDel3d(std::vector<MVertex *> &v,
                            std::vector<MTetrahedron *> &tets);

// mesh the volumes of a group of connected regions with the pdel3d kernel;
// returns 0 on success, 2 if the input is not supported (the caller may fall
// back to another algorithm), 1 on error
int meshGRegionPDel3d(std::vector<GRegion *> &regions);

#endif
