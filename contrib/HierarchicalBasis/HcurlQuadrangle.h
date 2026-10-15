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

#ifndef HCURL_QUADRANGLE_H
#define HCURL_QUADRANGLE_H

#include "HierarchicalBasis.h"
#include "H1Quadrangle.h"
// H(curl) basis on the quadrangle [-1, 1]^2, with vertices v0 = (-1, -1),
// v1 = (1, -1), v2 = (1, 1), v3 = (-1, 1) and the affine coordinates
// a1 = (1 + u) / 2, a2 = (1 - u) / 2, a3 = (1 + v) / 2, a4 = (1 - v) / 2: the
// functions of the edges e0 = {v0, v1}, e1 = {v1, v2}, e2 = {v3, v2},
// e3 = {v0, v3}, whose lowest order functions are a4 grad(u), a1 grad(v), a3
// grad(u) and a2 grad(v) (see hcurlEdge), and of the face of coordinates (u,
// v) (see hcurlQuadrangle). The gradients are those of the H1 functions of
// H1Quadrangle of order p + 1.
class HcurlQuadrangle : public HierarchicalBasis {
public:
  HcurlQuadrangle(int order);
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
  H1Quadrangle _h1;
};

#endif
