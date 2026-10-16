// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Ismail Badia (2019) and Nawfel BENATIA (2025).

// Reference : Solin, P., Segeth, K., & Dolezel, I. (2003).
//             Higher-Order Finite Element Methods (1st ed.).
//             Chapman and Hall/CRC. https://doi.org/10.1201/9780203488041

#ifndef H1_TRIANGLE_H
#define H1_TRIANGLE_H

#include "HierarchicalBasis.h"

// H1 basis on the triangle (0, 0), (1, 0), (0, 1), with the affine
// coordinates L0 = 1 - u - v, L1 = u and L2 = v of its vertices:
// - the vertex functions L0, L1, L2;
// - the functions of the edges e0 = {v0, v1}, e1 = {v1, v2}, e2 = {v2, v0};
// - the functions of the face (v0, v1, v2), with the roles of its vertices
//   permuted to orient it;
// see h1Edge and h1Triangle.
class H1Triangle : public HierarchicalBasis {
public:
  H1Triangle(int order);

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
