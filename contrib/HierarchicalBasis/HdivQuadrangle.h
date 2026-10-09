// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Ismail Badia (2019) and Nawfel BENATIA (2025).

// Reference : Solin, P., Segeth, K., & Dolezel, I. (2003).
//             Higher-Order Finite Element Methods (1st ed.).
//             Chapman and Hall/CRC. https://doi.org/10.1201/9780203488041

#ifndef HDIV_QUADRANGLE_H
#define HDIV_QUADRANGLE_H

#include "HierarchicalBasis.h"

// H(div) basis on the quadrangle [-1, 1]^2: the H(curl) basis of
// HcurlQuadrangle rotated in the plane, by -90 degrees for the edge functions
// (as for the edges of HdivTriangle) and by 90 degrees for the face functions
// (see hdivQuadrangle).
class HdivQuadrangle : public HierarchicalBasis {
public:
  HdivQuadrangle(int order);

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
