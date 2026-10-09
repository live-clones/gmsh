// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef HDIV_HEXAHEDRON_H
#define HDIV_HEXAHEDRON_H

#include "HierarchicalBasis.h"

// H(div) basis of Raviart-Thomas type on the hexahedron [-1, 1]^3, spanning
// Q_(p+1,p,p) e_u + Q_(p,p+1,p) e_v + Q_(p,p,p+1) e_w, with the affine
// coordinates a0, ..., a5 of hexahedronCoordinates:
// - the functions of the faces (see hexahedronFaces): the affine coordinate
//   across the face times the face functions of its two coordinates (see
//   hdivQuadrangleFace);
// - the bubble functions l_n1(u) L_n2(v) L_n3(w) e_u, n1 = 2, ..., p + 1, n2,
//   n3 = 0, ..., p, and the same with the roles of u, v, w exchanged for e_v
//   and e_w;
// where L_k are the Legendre polynomials and l_k the Lobatto polynomials.
class HdivHexahedron : public HierarchicalBasis {
public:
  HdivHexahedron(int order);
  void getKeysInfo(std::vector<int> &functionTypeInfo,
                   std::vector<int> &orderInfo) override;

protected:
  void functions(const Dual *x, std::vector<Vec> &vertex,
                 std::vector<Vec> &edge, std::vector<Vec> &face,
                 std::vector<Vec> &bubble) override;
  void faceFunctions(const Dual *x, int flag1, int flag2, int flag3,
                     int faceNumber, std::vector<Vec> &face) override;

private:
  int _order;
};

#endif
