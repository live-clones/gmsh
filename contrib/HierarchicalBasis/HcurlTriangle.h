// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Ismail Badia (2019) and Nawfel BENATIA (2025).

// Reference : Solin, P., Segeth, K., & Dolezel, I. (2003).
//             Higher-Order Finite Element Methods (1st ed.).
//             Chapman and Hall/CRC. https://doi.org/10.1201/9780203488041

#ifndef HCURL_TRIANGLE_H
#define HCURL_TRIANGLE_H

#include "HierarchicalBasis.h"

// H(curl) basis on the triangle (0, 0), (1, 0), (0, 1), with the affine
// coordinates L0 = 1 - u - v, L1 = u and L2 = v of its vertices: the functions
// of the edges e0 = {v0, v1}, e1 = {v1, v2}, e2 = {v2, v0} (see hcurlEdge) and
// of the face (v0, v1, v2), with the roles of its vertices permuted to orient
// it (see hcurlTriangle).
class HcurlTriangle : public HierarchicalBasis {
public:
  HcurlTriangle(int order);

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
