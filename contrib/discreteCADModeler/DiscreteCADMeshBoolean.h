// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef DISCRETE_CAD_MESH_BOOLEAN_H
#define DISCRETE_CAD_MESH_BOOLEAN_H

#include <string>
#include <vector>

// The boolean operation op (0: union, 1: intersection, 2: difference A - B)
// of two closed triangulations oriented outwards, each without
// self-intersections (3 coordinates per vertex, 3 vertex indices per
// triangle), exact and without dependencies: the intersection points are
// identified by the vertices, edges and triangles of both operands they lie
// in, all the decisions are taken with exact predicates. The result, oriented
// outwards, and for each of its triangles the triangle it lies in (those of A
// first, then those of B). Returns false, with the reason in error, if it
// cannot compute it (overlapping coplanar triangles, intersecting
// constraints of operands that are not valid).
bool meshBoolean(int op, const std::vector<double> &xyzA,
                 const std::vector<int> &triA,
                 const std::vector<double> &xyzB,
                 const std::vector<int> &triB, std::vector<double> &xyz,
                 std::vector<int> &tri, std::vector<int> &birth,
                 std::string &error);

#endif
