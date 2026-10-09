// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Ismail Badia (2019) and Nawfel BENATIA (2025).

// Reference : Solin, P., Segeth, K., & Dolezel, I. (2003).
//             Higher-Order Finite Element Methods (1st ed.).
//             Chapman and Hall/CRC. https://doi.org/10.1201/9780203488041

#ifndef HCURL_PRISM_H
#define HCURL_PRISM_H

#include "HierarchicalBasis.h"

// H(curl) basis on the prism of base (0, 0), (1, 0), (0, 1) and height w in
// [-1, 1], with the affine coordinates L0 = 1 - u - v, L1 = u, L2 = v of the
// triangle, B = (1 - w) / 2 and T = (1 + w) / 2:
// - the functions of the edges e0 = {0, 1}, e1 = {0, 2}, e3 = {1, 2} (times B)
//   and e6 = {3, 4}, e7 = {3, 5}, e8 = {4, 5} (times T) of the triangles (see
//   hcurlEdge), and of the vertical edges e2 = {0, 3}, e4 = {1, 4},
//   e5 = {2, 5}, Li L_k(w) grad(w), k = 0, ..., p;
// - the functions of the quadrilateral faces s0 = {0, 1, 3, 4},
//   s1 = {0, 2, 3, 5}, s2 = {1, 2, 4, 5} over the edges {0, 1}, {0, 2} and
//   {1, 2} of the triangle (see hcurlPrismQuadrangle), and of the triangular
//   faces s3 = {0, 1, 2} (times B) and s4 = {3, 4, 5} (times T) (see
//   hcurlTriangle);
// - the bubble functions: for the edges (x, y) = (0, 1), (2, 0), (1, 2) of the
//   triangle, opposite to the vertex z, x y L_k(y - x) grad(z) l_n(w), k = 0,
//   ..., p - 2, n = 2, ..., p + 1; with abc = L0 L1 L2 L_n1(L1 - L0)
//   L_n2(L0 - L2), 2 abc l_n3(w) e_u, then -2 abc l_n3(w) e_v, n1 + n2 <= p -
//   3, n3 = 2, ..., p + 1, and abc L_n3(w) grad(w), n1 + n2 <= p - 2, n3 = 0,
//   ..., p;
// where L_k are the Legendre polynomials and l_k the Lobatto polynomials.
class HcurlPrism : public HierarchicalBasis {
public:
  HcurlPrism(int order);

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
