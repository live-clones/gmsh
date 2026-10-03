// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESH_GREGION_PDEL3D_H
#define MESH_GREGION_PDEL3D_H

#include <vector>

class MVertex;
class MTetrahedron;

// Delaunay tetrahedralization of a point set with the pdel3d kernel; the
// vertices are not reordered, the tets reference them directly
void delaunayMeshIn3DPDel3d(std::vector<MVertex *> &v,
                            std::vector<MTetrahedron *> &tets);

#endif
