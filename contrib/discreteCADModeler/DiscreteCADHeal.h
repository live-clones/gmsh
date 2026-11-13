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

#ifndef DISCRETE_CAD_HEAL_H
#define DISCRETE_CAD_HEAL_H

#include <array>
#include <vector>

// The healing of a soup of triangles (a STL file of separate parts, with
// holes, gaps, overlaps, duplicated triangles and triangles oriented either
// way), before the discrete CAD modeler builds its volumes:

// what the healing did
struct DiscreteCADHealReport {
  int degenerate = 0, duplicated = 0;
  // the components (the triangles connected across edges of two triangles,
  // oriented as their neighbors), and those turned over: closed ones by the
  // sign of their volume, open ones by the winding number around them
  int components = 0, closed = 0, reversedClosed = 0, reversedOpen = 0;
  // the triangles turned over in all
  int reversedTriangles = 0;
};

// The degenerate triangles (two nodes the same) and the duplicated ones (the
// same nodes) removed; the index of each one kept in the input in kept
void removeBadTriangles(std::vector<std::array<int, 3> > &triangles,
                        DiscreteCADHealReport &report,
                        std::vector<std::size_t> *kept = nullptr);

// The triangles oriented: as their neighbors across the edges of two
// triangles, each component so made then outwards: a closed one so that its
// volume is positive, an open one (a part of a surface with holes, or a sheet
// closing another component) so that the winding number of all the
// triangles is the nearest to whole numbers, and not negative, at points on
// both sides of it, about a tenth of its size away (where a component turned
// over makes the winding number fractional: see Takayama, Jacobson, Kavan
// and Sorkine-Hornung, 2014). The component of each triangle in component.
void orientTriangles(const std::vector<std::array<double, 3> > &x,
                     std::vector<std::array<int, 3> > &triangles,
                     DiscreteCADHealReport &report,
                     std::vector<int> *component = nullptr);

#endif
