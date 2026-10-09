// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Ismail Badia (2019) and Nawfel BENATIA (2025).

// References: Solin, P., Segeth, K., & Dolezel, I. (2003). Higher-Order Finite
// Element Methods. Chapman and Hall/CRC. https://doi.org/10.1201/9780203488041
// Zaglmayr, S. (2006). High Order Finite Element Methods for Electromagnetic
// Field Computation. PhD thesis, Johannes Kepler University Linz.

#ifndef HCURL_PRISM_H
#define HCURL_PRISM_H

#include "HierarchicalBasis.h"
#include "H1Prism.h"

// H(curl) basis on the prism of base (0, 0), (1, 0), (0, 1) and height w in
// [-1, 1], with the affine coordinates L0 = 1 - u - v, L1 = u, L2 = v of the
// triangle, B = (1 - w) / 2 and T = (1 + w) / 2, as the product of the
// sequences of the triangle and of the line: by increasing order on each
// entity, the gradients of the H1 functions of H1Prism of order p + 1, then
// the rotational functions:
// - on the edges e0 = {0, 1}, e1 = {0, 2}, e3 = {1, 2} of the bottom triangle
//   and e6 = {3, 4}, e7 = {3, 5}, e8 = {4, 5} of the top triangle, B or T
//   times the Whitney function of the edge, and on the vertical edges
//   e2 = {0, 3}, e4 = {1, 4}, e5 = {2, 5}, Li grad(w);
// - on the quadrilateral faces s0, s1, s2 over the edges {0, 1}, {0, 2} and
//   {1, 2} of the triangle, of coordinates (s, t) oriented as the face, with
//   the H1 functions P_n of each coordinate (a b K_n(b - a) along the edge (a,
//   b) of the triangle, B T K_n(w) along w) and their Whitney functions W
//   (that of the edge (a, b), grad(w)): W_s P_t,l-1, P_s,l-1 W_t and P_t,n2
//   grad(P_s,n1) - P_s,n1 grad(P_t,n2), max(n1, n2) = l - 1, for the order l:
//   on the face, the functions of the faces of the hexahedron;
// - on the triangular faces s3 = {0, 1, 2} and s4 = {3, 4, 5}, B or T times
//   the functions of the triangle (see hcurlTriangle);
// - in the interior, with the H1 functions F of the triangle (see h1Triangle),
//   its rotational H(curl) functions R (see hcurlTriangleRotational) and the
//   Lobatto polynomials l_k(w): R l_k, F grad(w) and F grad(l_k) - l_k grad(F).
class HcurlPrism : public HierarchicalBasis {
public:
  HcurlPrism(int order);
  void functionInfo(std::vector<FunctionInfo> &info) override;
  void functions(const Dual *x, std::vector<Vec> &vertex,
                 std::vector<Vec> &edge, std::vector<Vec> &face,
                 std::vector<Vec> &bubble) override;
  void faceFunctions(const Dual *x, int flag1, int flag2, int flag3,
                     int faceNumber, std::vector<Vec> &face) override;

protected:
  bool hasParts() const override { return true; }

private:
  int _order;
  H1Prism _h1;
  // the functions of quadrilateral face f, of order l, from the H1 functions
  // h of the face, in the orientation given by the flags
  int _quadrangle(const Dual *x, int f, int flag1, int flag2, int flag3,
                  const Dual *h, Vec *out);
};

#endif
