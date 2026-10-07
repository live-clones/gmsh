// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Ismail Badia (2019) and Nawfel BENATIA (2025).

// Reference : Solin, P., Segeth, K., & Dolezel, I. (2003).
//             Higher-Order Finite Element Methods (1st ed.).
//             Chapman and Hall/CRC. https://doi.org/10.1201/9780203488041

#ifndef HCURL_LINE_H
#define HCURL_LINE_H

#include "HierarchicalBasis.h"

// H(curl) basis on the line u in [-1, 1]: the edge functions L_k(u) e_u, for
// the Legendre polynomials L_k of degrees k = 0 to the order (the Whitney
// function and its hierarchical extensions)
class HcurlLine : public HierarchicalBasis {
public:
  HcurlLine(int order);
  void getKeysInfo(std::vector<int> &functionTypeInfo,
                   std::vector<int> &orderInfo) override;

protected:
  void functions(const Dual *x, std::vector<Vec> &vertex,
                 std::vector<Vec> &edge, std::vector<Vec> &face,
                 std::vector<Vec> &bubble) override;

private:
  int _order;
};

#endif
