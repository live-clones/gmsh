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

#ifndef DISCRETE_CAD_ARRANGEMENT_H
#define DISCRETE_CAD_ARRANGEMENT_H

#include <array>
#include <string>
#include <vector>

// Whether the mesh arrangements are available (always: they need nothing)
bool haveMeshArrangement();

// Cut all triangles where they meet, without classifying volumes. Open and
// nonmanifold surfaces and self-intersections are allowed. The output vertices
// are shared at exact intersections; their exact coordinates are rounded once
// to nearest binary64 (ties to even). birth[i]
// is the input triangle of output triangle i. All nonzero-area descendants are
// kept, including one copy per source in coplanar overlaps, so callers can
// select sheets without losing their provenance. Degenerate inputs are omitted.
// If requested, inputVertex maps every input vertex to its output index (equal
// input coordinates have the same index). Unused input vertices are retained.
// With cutTarget, -1 denotes a regular triangle; a nonnegative entry denotes an
// auxiliary cutter acting only on the regular input triangle with that index.
// Regular triangles still intersect each other normally; cutters do not
// intersect each other and their descendants are omitted. Points on shared
// input edges also split the adjacent regular triangles to keep conformity.
// Selective cutters must be applied after regular intersections have been
// co-refined, so contacts crossed by cutters are already shared input edges.
// Outputs are unchanged on failure; error contains the reason.
bool meshCoRefine(const std::vector<double> &xyz, const std::vector<int> &tri,
                  std::vector<double> &oxyz, std::vector<int> &otri,
                  std::vector<int> &birth, std::string &error,
                  std::vector<int> *inputVertex = nullptr,
                  const std::vector<int> *cutTarget = nullptr);

// The arrangement of closed triangulations, each one oriented outwards,
// possibly with self-intersections, crossing or touching the others: all the
// triangles cut where they meet, exactly, the points where three of them meet
// included, and the winding number of each triangulation in the cells of
// space between them. The input of each triangle in label (0 to labels - 1).
// The triangles of the arrangement, each one once (those of several inputs on
// top of each other one), with the triangle of the inputs it lies in (birth),
// and the inputs inside the space behind it and in front of it (their winding
// number not 0): sets[sides[i][0]] behind triangle i, sets[sides[i][1]] in
// front of it (sets[0] the empty set); the triangles with the same inputs on
// both sides are left out, as the input triangles without area. If thickness
// is positive, the cells thinner than it (twice their volume over their area)
// are part of the cell they share most of their area with (their number in
// merged). The coordinates of the points where triangles meet are rounded.
// False, with the reason in error, if the winding numbers are not whole
// numbers (inputs not closed).
bool meshArrangement(const std::vector<double> &xyz,
                     const std::vector<int> &tri,
                     const std::vector<int> &label, int labels,
                     double thickness, std::vector<double> &oxyz,
                     std::vector<int> &otri, std::vector<int> &birth,
                     std::vector<std::vector<int> > &sets,
                     std::vector<std::array<int, 2> > &sides,
                     std::size_t &merged, std::string &error);

#endif
