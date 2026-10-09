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

#ifndef HCURL_TETRAHEDRON_H
#define HCURL_TETRAHEDRON_H

#include "HierarchicalBasis.h"
#include "H1Tetrahedron.h"
// H(curl) basis on the tetrahedron (0, 0, 0), (1, 0, 0), (0, 1, 0), (0, 0, 1),
// with the affine coordinates L0 = 1 - u - v - w, L1 = u, L2 = v and L3 = w of
// its vertices, and the gradients of the H1 functions of H1Tetrahedron of
// order p + 1:
// - the functions of the edges e0 = {0, 1}, e1 = {1, 2}, e2 = {2, 0},
//   e3 = {0, 3}, e4 = {2, 3}, e5 = {1, 3} (see hcurlEdge);
// - the functions of the faces s0 = (0, 1, 2), s1 = (0, 1, 3), s2 = (0, 2, 3)
//   and s3 = (1, 2, 3), with the roles of their vertices permuted to orient
//   them (see hcurlTriangle);
// - the bubble functions, by increasing order l = 3, ..., p: the gradients of
//   the H1 bubbles of order l + 1, then the rotational functions of order l
//   (see bubbles()).
class HcurlTetrahedron : public HierarchicalBasis {
public:
  HcurlTetrahedron(int order);
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
  H1Tetrahedron _h1;
};

#endif
