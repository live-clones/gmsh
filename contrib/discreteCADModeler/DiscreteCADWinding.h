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

#ifndef DISCRETE_CAD_WINDING_H
#define DISCRETE_CAD_WINDING_H

#include <array>
#include <vector>

// The generalized winding number of a soup of triangles at a point: the sum
// of the signed solid angles of the triangles seen from it, over 4 pi (1
// inside a closed surface oriented outwards, 0 outside, in between near its
// holes and gaps: inside where it is above 1/2), as Jacobson, Kavan and
// Sorkine-Hornung (2013). Computed fast, as Barill, Dickson, Schmidt, Levin
// and Jacobson (2018): a tree of boxes of the triangles, each with the
// moments of the area-weighted normals of its triangles about its center (the
// dipoles, and their first and second moments, those of the triangles
// integrated exactly); the triangles of a box seen from beyond beta times
// its radius taken through the Taylor expansion of the kernel there, the
// others exactly.
class DiscreteCADWinding {
public:
  // the triangles (by the indices of their nodes x), oriented outwards
  DiscreteCADWinding(const std::vector<std::array<double, 3> > &x,
                     const std::vector<std::array<int, 3> > &triangles,
                     double beta = 2.);
  // the winding number at q
  double operator()(const double q[3]) const;
  // the winding numbers at the points q
  void evaluate(const std::vector<std::array<double, 3> > &q,
                std::vector<double> &w) const;
  // the winding number at q summed over all the triangles (to check)
  double exact(const double q[3]) const;

private:
  struct Node {
    // the center (the area-weighted centroid) and the radius of the box (the
    // largest distance of the nodes of its triangles to the center)
    double c[3], r;
    // the moments: the sum of the area-weighted normals, of their products
    // with the positions about the center (a 3x3 matrix, normal index
    // first), and with the second moments of the triangles about the center
    // (a 3x3x3 tensor, normal index first)
    double m0[3], m1[9], m2[27];
    // the children (leaf: -1), the first triangle and their number
    int left, right, first, count;
  };
  std::vector<std::array<double, 3> > _x;
  std::vector<std::array<int, 3> > _t;
  std::vector<Node> _nodes;
  double _beta;
  int _build(std::vector<int> &order, int first, int count);
  double _leaf(const Node &n, const double q[3]) const;
};

#endif
