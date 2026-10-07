// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Ismail Badia (2019) and Nawfel BENATIA (2025).

// Reference : Solin, P., Segeth, K., & Dolezel, I. (2003).
//             Higher-Order Finite Element Methods (1st ed.).
//             Chapman and Hall/CRC. https://doi.org/10.1201/9780203488041

#ifndef H1_QUADRANGLE_H
#define H1_QUADRANGLE_H

#include "HierarchicalBasis.h"

// H1 basis on the quadrangle [-1, 1]^2, with vertices v0 = (-1, -1),
// v1 = (1, -1), v2 = (1, 1), v3 = (-1, 1) and the affine coordinates
// a1 = (1 + u) / 2, a2 = (1 - u) / 2, a3 = (1 + v) / 2, a4 = (1 - v) / 2:
// - the vertex functions a2 a4, a1 a4, a1 a3, a2 a3;
// - the functions a4 l_k(u), a1 l_k(v), a3 l_k(u), a2 l_k(v), k = 2, ..., p,
//   of the edges e0 = {v0, v1}, e1 = {v1, v2}, e2 = {v3, v2} and e3 = {v0, v3};
// - the face functions of the face of coordinates (u, v) (see h1Quadrangle);
// where l_k are the Lobatto polynomials.
class H1Quadrangle : public HierarchicalBasis {
public:
  H1Quadrangle(int order);
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
