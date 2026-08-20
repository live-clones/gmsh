// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef DELAUNAY3D_H
#define DELAUNAY3D_H

#include <cstdint>
#include <vector>

class MVertex;
class MTetrahedron;

// tetrahedralize the vertices given in S; adds 8 new vertices at the end of S
// (the corners of an enclosing box); if neighbors is given, it is filled with
// 4 entries per tet: the index in T of the tet sharing face k (in the
// internal face numbering), or -1 if there is none
void delaunayTriangulation(std::vector<MVertex *> &S,
                           std::vector<MTetrahedron *> &T, bool removeBox,
                           std::vector<std::int64_t> *neighbors = nullptr);

#endif
