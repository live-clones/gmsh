// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef DISCRETE_CAD_BOOLEAN_H
#define DISCRETE_CAD_BOOLEAN_H

#include <vector>

// The boolean operation op (0: union, 1: intersection, 2: difference A - B)
// of two closed triangulations oriented outwards (3 coordinates per vertex, 3
// vertex indices per triangle), with the exact mesh booleans of libigl (and
// CGAL): the result, oriented outwards, and for each of its triangles the
// triangle it lies in (those of A first, then those of B). Returns false if
// libigl is not available or fails.
bool meshBooleanLibigl(int op, const std::vector<double> &xyzA,
                       const std::vector<int> &triA,
                       const std::vector<double> &xyzB,
                       const std::vector<int> &triB, std::vector<double> &xyz,
                       std::vector<int> &tri, std::vector<int> &birth);

#endif
