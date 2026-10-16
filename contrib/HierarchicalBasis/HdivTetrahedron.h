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

#ifndef HDIV_TETRAHEDRON_H
#define HDIV_TETRAHEDRON_H

#include "HierarchicalBasis.h"
#include "HcurlTetrahedron.h"
// H(div) basis on the tetrahedron (0, 0, 0), (1, 0, 0), (0, 1, 0), (0, 0, 1),
// with the affine coordinates L0 = 1 - u - v - w, L1 = u, L2 = v and L3 = w of
// its vertices: the Raviart-Thomas space RT0 for p = 0, the full space of
// vector polynomials of degree p (Brezzi-Douglas-Marini) for p >= 1, from the
// H(curl) basis of HcurlTetrahedron of order p + 1:
// - the functions of the faces s0 = (0, 1, 2), s1 = (0, 1, 3), s2 = (0, 2, 3)
//   and s3 = (1, 2, 3), with the roles (a, b, c) of their vertices permuted to
//   orient them: the Whitney 2-form of (a, b, c) (see whitney2), then, by
//   increasing order l = 1, ..., p, the curls of the l + 1 rotational H(curl)
//   functions of the face of order l + 1;
// - the bubble functions, by increasing order l = 2, ..., p: the curls of the
//   rotational H(curl) bubbles of order l + 1, then L0^i L1^j L2^k times the
//   Whitney 2-form of the face opposite to L0 for i + j + k = l - 1, i >= 1,
//   opposite to L1 for i = 0 and j >= 1, and opposite to L2 for i = j = 0, by
//   decreasing i, then j: their divergences span the polynomials of degree l -
//   1 without the constants.
// The curls are the divergence-free functions. The other functions belong to
// the Raviart-Thomas space of order l - 1 (degree l), so that the curls of
// order p with the other functions of order p + 1 span RT_p.
class HdivTetrahedron : public HierarchicalBasis {
public:
  HdivTetrahedron(int order);
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
  HcurlTetrahedron _hcurl;
};

#endif
