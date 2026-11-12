// Gmsh Discrete CAD Modeler - Copyright (C) 2026 C. Geuzaine and J.-F. Remacle
//
// This program is free software: you can redistribute it and/or modify it under
// the terms of the GNU Affero General Public License as published by the Free
// Software Foundation, either version 3 of the License, or (at your option) any
// later version.
//
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more
// details.
//
// You should have received a copy of the GNU Affero General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef DISCRETE_CAD_MESH_BOOLEAN_H
#define DISCRETE_CAD_MESH_BOOLEAN_H

#include <string>
#include <vector>

// The boolean operation op (0: union, 1: intersection, 2: difference A - B)
// of two closed triangulations oriented outwards, each without
// self-intersections (3 coordinates per vertex, 3 vertex indices per
// triangle), exact and without dependencies: the intersection points are
// identified by the vertices, edges and triangles of both operands they lie
// in, all the decisions are taken with exact predicates, degenerate
// configurations included (vertices on edges or triangles, edges along
// planes, coplanar overlapping triangles); the triangles cut are triangulated
// by gmsh's constrained Delaunay (PolyMesh). The result, oriented outwards,
// and for each of its triangles the triangle it lies in (those of A first,
// then those of B). Returns false, with the reason in error, if it cannot
// compute it (operands that are not closed manifold triangulations without
// self-intersections).
bool meshBoolean(int op, const std::vector<double> &xyzA,
                 const std::vector<int> &triA,
                 const std::vector<double> &xyzB,
                 const std::vector<int> &triB, std::vector<double> &xyz,
                 std::vector<int> &tri, std::vector<int> &birth,
                 std::string &error);

#endif
