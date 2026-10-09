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

#ifndef HDIV_HEXAHEDRON_H
#define HDIV_HEXAHEDRON_H

#include "HierarchicalBasis.h"
#include "HcurlHexahedron.h"
// H(div) basis of Raviart-Thomas type on the hexahedron [-1, 1]^3, spanning
// Q_(p+1,p,p) e_u + Q_(p,p+1,p) e_v + Q_(p,p,p+1) e_w, with the affine
// coordinates a0, ..., a5 of hexahedronCoordinates:
// - the functions of each face (see hexahedronFaces), of coordinates (s, t):
//   the affine coordinate across the face times grad(s) x grad(t), then, by
//   increasing order l = 1, ..., p, the curls of the rotational H(curl)
//   functions of the face of order l (see HcurlHexahedron);
// - the bubble functions, by increasing order l = 1, ..., p: the curls of the
//   rotational H(curl) bubbles of order l, then l_n1+1(u) L_n2(v) L_n3(w) e_u
//   for max(n1, n2, n3) = l and n1 >= 1, the same along e_v for n1 = 0 and n2
//   >= 1 and along e_w for n1 = n2 = 0, whose divergences are the products of
//   Legendre polynomials L_n1(u) L_n2(v) L_n3(w);
// where L_k are the Legendre polynomials and l_k the Lobatto polynomials. The
// curls are the divergence-free functions.
class HdivHexahedron : public HierarchicalBasis {
public:
  HdivHexahedron(int order);
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
  HcurlHexahedron _hcurl;
};

#endif
