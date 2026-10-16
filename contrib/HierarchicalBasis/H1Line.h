// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Ismail Badia (2019) and Nawfel BENATIA (2025).

// Reference : Solin, P., Segeth, K., & Dolezel, I. (2003).
//             Higher-Order Finite Element Methods (1st ed.).
//             Chapman and Hall/CRC. https://doi.org/10.1201/9780203488041

#ifndef H1_LINE_H
#define H1_LINE_H

#include "HierarchicalBasis.h"

// H1 basis on the line u in [-1, 1], with vertices 0 (u = -1) and 1 (u = 1):
// the 2 vertex functions, and the edge functions of degrees 2 to the order
class H1Line : public HierarchicalBasis {
public:
  H1Line(int order);

protected:
  void functionInfo(std::vector<FunctionInfo> &info) override;
  void functions(const Dual *x, std::vector<Dual> &vertex,
                 std::vector<Dual> &edge, std::vector<Dual> &face,
                 std::vector<Dual> &bubble) override;

private:
  int _order;
};

#endif
