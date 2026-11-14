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
#include <string>
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
// and Sorkine-Hornung, 2014). The component of each triangle in component,
// and whether each one ends turned over in turned: 0 if not, 1 against its
// neighbors, 2 with a closed component of negative volume, 3 with an open
// one against the winding number.
void orientTriangles(const std::vector<std::array<double, 3> > &x,
                     std::vector<std::array<int, 3> > &triangles,
                     DiscreteCADHealReport &report,
                     std::vector<int> *component = nullptr,
                     std::vector<char> *turned = nullptr);

// The cracks of a soup of triangles zipped: the nodes of its free edges
// (edges of one triangle) within tolerance of a node of another free edge
// merged into it (closest pairs first, never into more than two distinct
// triangles along an edge; a triangle with the two nodes collapses), and
// those within tolerance of the inside of a free edge inserted into it, its
// triangle split (a T-junction), until nothing changes; the degenerate and
// duplicated triangles then made removed. For each triangle left, the
// triangle of the input it comes from in origin; the nodes merged away, the
// nodes inserted and the free edges before and after in the report.
struct DiscreteCADZipReport {
  std::vector<int> merged, inserted;
  std::size_t freeBefore = 0, freeAfter = 0;
};
void zipFreeEdges(const std::vector<std::array<double, 3> > &x,
                  std::vector<std::array<int, 3> > &triangles, double tolerance,
                  DiscreteCADZipReport &report,
                  std::vector<std::size_t> *origin = nullptr);

// A tolerance for zipFreeEdges: in the distribution of the distances from the
// nodes of free edges to the nearest free edge not touching them, the
// emptiest half decade between the cracks (the first peak) and the gaps
// between parts (the main peak), its upper end; 0 if there is no free edge.
// What it is made of in why.
double zipTolerance(const std::vector<std::array<double, 3> > &x,
                    const std::vector<std::array<int, 3> > &triangles,
                    std::string *why = nullptr);

// The defects of a soup of triangles, as it is: the triangles degenerate (two
// nodes the same, or no area), duplicated (the nodes of one before) and
// needles (an angle smaller than a degree); the edges free (of one triangle:
// holes and gaps), non-manifold (of more than two triangles) and misoriented
// (two triangles along them the same way); the nodes of T-junctions (inside a
// free edge of other triangles); the pieces (the triangles connected across
// edges of two triangles), the piece of each triangle and whether each piece
// is closed. The edges and the pieces are those of the triangles neither
// degenerate nor duplicated (their piece is -1).
struct DiscreteCADDefects {
  std::vector<std::size_t> degenerate, duplicated, needles;
  std::vector<std::pair<int, int> > free, nonManifold, misoriented;
  std::vector<int> tJunctions;
  std::vector<int> piece;
  std::vector<char> closed;
};
void findDefects(const std::vector<std::array<double, 3> > &x,
                 const std::vector<std::array<int, 3> > &triangles,
                 DiscreteCADDefects &defects);

#endif
