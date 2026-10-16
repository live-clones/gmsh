// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Ismail Badia (2019) and Nawfel BENATIA (2025).

// Reference : Solin, P., Segeth, K., & Dolezel, I. (2003).
//             Higher-Order Finite Element Methods (1st ed.).
//             Chapman and Hall/CRC. https://doi.org/10.1201/9780203488041

#ifndef H1_PRISM_H
#define H1_PRISM_H

#include "HierarchicalBasis.h"

// H1 basis on the prism of base (0, 0), (1, 0), (0, 1) and height w in
// [-1, 1], with the affine coordinates L0 = 1 - u - v, L1 = u, L2 = v of the
// triangle, B = (1 - w) / 2 and T = (1 + w) / 2:
// - the vertex functions L0 B, L1 B, L2 B, L0 T, L1 T, L2 T;
// - the functions of the edges e0 = {0, 1}, e1 = {0, 2}, e2 = {0, 3},
//   e3 = {1, 2}, e4 = {1, 4}, e5 = {2, 5}, e6 = {3, 4}, e7 = {3, 5},
//   e8 = {4, 5}: B or T times the triangle edge functions of the horizontal
//   edges, Li times the edge functions of B and T of the vertical ones (see
//   h1Edge);
// - the functions of the quadrilateral faces s0 = {0, 1, 3, 4},
//   s1 = {0, 2, 3, 5}, s2 = {1, 2, 4, 5} over the edge {a, b} of the triangle:
//   La Lb B T K_n1(Lb - La) K_n2(T - B) (see h1QuadrangleKernel), and of the
//   triangular faces s3 = {0, 1, 2}, s4 = {3, 4, 5}: B or T times the triangle
//   face functions (see h1Triangle);
// - the bubble functions: the triangle face functions times l_n3(w), n3 = 2,
//   ..., p;
// where K_k are the kernel functions and l_k the Lobatto polynomials.
class H1Prism : public HierarchicalBasis {
public:
  H1Prism(int order);

protected:
  void functionInfo(std::vector<FunctionInfo> &info) override;
  void functions(const Dual *x, std::vector<Dual> &vertex,
                 std::vector<Dual> &edge, std::vector<Dual> &face,
                 std::vector<Dual> &bubble) override;
  void faceFunctions(const Dual *x, int flag1, int flag2, int flag3,
                     int faceNumber, std::vector<Dual> &face) override;

private:
  int _order;
};

#endif
