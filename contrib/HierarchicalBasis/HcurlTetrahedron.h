// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Ismail Badia (2019) and Nawfel BENATIA (2025).

// Reference : Solin, P., Segeth, K., & Dolezel, I. (2003).
//             Higher-Order Finite Element Methods (1st ed.).
//             Chapman and Hall/CRC. https://doi.org/10.1201/9780203488041

#ifndef HCURL_TETRAHEDRON_H
#define HCURL_TETRAHEDRON_H

#include "HierarchicalBasis.h"

// H(curl) basis on the tetrahedron (0, 0, 0), (1, 0, 0), (0, 1, 0), (0, 0, 1),
// with the affine coordinates L0 = 1 - u - v - w, L1 = u, L2 = v and L3 = w of
// its vertices:
// - the functions of the edges e0 = {0, 1}, e1 = {1, 2}, e2 = {2, 0},
//   e3 = {0, 3}, e4 = {2, 3}, e5 = {1, 3} (see hcurlEdge);
// - the functions of the faces s0 = (0, 1, 2), s1 = (0, 1, 3), s2 = (0, 2, 3)
//   and s3 = (1, 2, 3), with the roles of their vertices permuted to orient
//   them (see hcurlTriangle);
// - the bubble functions: for each face (a, b, c), opposite to the vertex d,
//   a b c L_n1(b - a) L_n2(a - c) grad(d), n1 + n2 <= p - 3; then
//   2 L0 L1 L2 L3 K_n1(L2 - L0) K_n2(L1 - L0) K_n3(L3 - L0) times e_u, then
//   e_v, then e_w, n1 + n2 + n3 <= p - 4;
// where L_k are the Legendre polynomials and K_k the kernel functions.
class HcurlTetrahedron : public HierarchicalBasis {
public:
  HcurlTetrahedron(int order);

protected:
  void keysInfo(std::vector<int> &functionTypeInfo,
                std::vector<int> &orderInfo) override;
  void functions(const Dual *x, std::vector<Vec> &vertex,
                 std::vector<Vec> &edge, std::vector<Vec> &face,
                 std::vector<Vec> &bubble) override;
  void faceFunctions(const Dual *x, int flag1, int flag2, int flag3,
                     int faceNumber, std::vector<Vec> &face) override;

private:
  int _order;
};

#endif
