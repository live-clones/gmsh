// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Ismail Badia (2019) and Nawfel BENATIA (2025).

// Reference : Solin, P., Segeth, K., & Dolezel, I. (2003).
//             Higher-Order Finite Element Methods (1st ed.).
//             Chapman and Hall/CRC. https://doi.org/10.1201/9780203488041

#ifndef HCURL_QUADRANGLE_H
#define HCURL_QUADRANGLE_H

#include "HierarchicalBasis.h"

// H(curl) basis on the quadrangle [-1, 1]^2, with vertices v0 = (-1, -1),
// v1 = (1, -1), v2 = (1, 1), v3 = (-1, 1) and the affine coordinates
// a1 = (1 + u) / 2, a2 = (1 - u) / 2, a3 = (1 + v) / 2, a4 = (1 - v) / 2: the
// functions of the edges e0 = {v0, v1}, e1 = {v1, v2}, e2 = {v3, v2},
// e3 = {v0, v3}, with blends a4, a1, a3, a2 (see hcurlTensorEdge), and of the
// face of coordinates (u, v) (see hcurlQuadrangle).
class HcurlQuadrangle : public HierarchicalBasis {
public:
  HcurlQuadrangle(int order);

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
