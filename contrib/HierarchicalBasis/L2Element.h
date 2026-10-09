// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef L2_ELEMENT_H
#define L2_ELEMENT_H

#include "HierarchicalBasis.h"

// L2 basis on the elements of any family, which closes the sequences of the H1,
// H(curl) and H(div) bases: the polynomials of degree p on simplices (P_p),
// of degree p in each coordinate on quadrangles and hexahedra (Q_p), and
// P_p(u, v) x P_p(w) on prisms, as products of Legendre polynomials of the
// coordinates (scaled to [-1, 1] on simplices), by increasing order. They are
// all associated with the element (with its edge in 1D, its face in 2D) and do
// not depend on its orientation.
class L2Element : public HierarchicalBasis {
public:
  L2Element(int familyType, int order);
  void functionInfo(std::vector<FunctionInfo> &info) override;
  void functions(const Dual *x, std::vector<Dual> &vertex,
                 std::vector<Dual> &edge, std::vector<Dual> &face,
                 std::vector<Dual> &bubble) override;

private:
  int _dim;
  // the exponents of the Legendre polynomials of each function, and its order
  std::vector<std::array<int, 4>> _indices;
};

#endif
