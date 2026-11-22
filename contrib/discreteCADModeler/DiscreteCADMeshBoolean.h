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
//
// An operand can be open (edges of one triangle, the others with as many
// triangles in both directions): it has no inside (its volume is zero), the
// triangles of the other operand are all outside it; its own triangles are
// classified against the other operand if it is closed (those on its
// triangles left out: the closed operand carries them), only those on the
// other one's triangles (coplanar, as for closed operands) if it is open, the
// others outside. So the union of a closed V and an open S is V and the part
// of S outside V, the intersection the part of S inside V, V - S is V and,
// turned over, the part of S inside V (the boundary of V split by S), S - V
// the part of S outside V. With op 3, the co-refinement of A and B (any
// triangulations, open, non-manifold, each without self-intersections): all
// their triangles cut by the other operand, as oriented, but those of B on
// triangles of A.
bool meshBoolean(int op, const std::vector<double> &xyzA,
                 const std::vector<int> &triA,
                 const std::vector<double> &xyzB,
                 const std::vector<int> &triB, std::vector<double> &xyz,
                 std::vector<int> &tri, std::vector<int> &birth,
                 std::string &error);

#endif
