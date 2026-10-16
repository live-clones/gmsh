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

#ifndef HCURL_LINE_H
#define HCURL_LINE_H

#include "HierarchicalBasis.h"
#include "H1Line.h"
// H(curl) basis on the line [-1, 1]: the Whitney function of the edge, then
// the gradients of the H1 functions of the edge of order p + 1.
class HcurlLine : public HierarchicalBasis {
public:
  HcurlLine(int order);
  void functionInfo(std::vector<FunctionInfo> &info) override;
  void functions(const Dual *x, std::vector<Vec> &vertex,
                 std::vector<Vec> &edge, std::vector<Vec> &face,
                 std::vector<Vec> &bubble) override;

protected:
  bool hasParts() const override { return true; }

private:
  int _order;
  H1Line _h1;
};

#endif
