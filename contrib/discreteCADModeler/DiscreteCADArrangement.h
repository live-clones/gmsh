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
