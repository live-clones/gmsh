// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Ismail Badia (2019) and Nawfel BENATIA (2025).

// Reference : Solin, P., Segeth, K., & Dolezel, I. (2003).
//             Higher-Order Finite Element Methods (1st ed.).
//             Chapman and Hall/CRC. https://doi.org/10.1201/9780203488041

#ifndef H1_HEXAHEDRON_H
#define H1_HEXAHEDRON_H

#include "HierarchicalBasis.h"

// H1 basis on the hexahedron [-1, 1]^3, with the affine coordinates
// a0 = (1 + u) / 2, a1 = (1 - u) / 2, a2 = (1 + v) / 2, a3 = (1 - v) / 2,
// a4 = (1 + w) / 2, a5 = (1 - w) / 2:
// - the vertex functions, products of three affine coordinates;
// - the functions of the edges e0 = {0, 1}, e1 = {0, 3}, e2 = {0, 4},
//   e3 = {1, 2}, e4 = {1, 5}, e5 = {3, 2}, e6 = {2, 6}, e7 = {3, 7},
//   e8 = {4, 5}, e9 = {4, 7}, e10 = {5, 6}, e11 = {7, 6}: the product of two
//   affine coordinates across the edge times l_k of the coordinate along it,
//   k = 2, ..., p;
// - the functions of the faces s0 = {0, 1, 3, 2}, s1 = {0, 1, 4, 5},
//   s2 = {0, 3, 4, 7}, s3 = {1, 2, 5, 6}, s4 = {3, 2, 7, 6}, s5 = {4, 5, 7, 6}:
//   the affine coordinate across the face times the face functions of its two
//   coordinates (see h1Quadrangle);
// - the bubble functions l_n1(u) l_n2(v) l_n3(w), n1, n2, n3 = 2, ..., p;
// where l_k are the Lobatto polynomials.
class H1Hexahedron : public HierarchicalBasis {
public:
  H1Hexahedron(int order);
  void getKeysInfo(std::vector<int> &functionTypeInfo,
                   std::vector<int> &orderInfo) override;

protected:
  void functions(const Dual *x, std::vector<Dual> &vertex,
                 std::vector<Dual> &edge, std::vector<Dual> &face,
                 std::vector<Dual> &bubble) override;
  void faceFunctions(const Dual *x, int flag1, int flag2, int flag3,
                     int faceNumber, std::vector<Dual> &face) override;

private:
  int _order;
};

#endif
