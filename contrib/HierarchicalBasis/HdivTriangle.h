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

#ifndef HDIV_TRIANGLE_H
#define HDIV_TRIANGLE_H

#include "HierarchicalBasis.h"
#include "HcurlTriangle.h"
// H(div) basis on the triangle: the H(curl) basis of HcurlTriangle rotated in
// the plane, by 90 degrees for the edge functions and by -90 degrees for the
// face functions. The rotated gradients are the divergence-free functions.
class HdivTriangle : public HierarchicalBasis {
public:
  HdivTriangle(int order);
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
  HcurlTriangle _hcurl;
};

#endif
