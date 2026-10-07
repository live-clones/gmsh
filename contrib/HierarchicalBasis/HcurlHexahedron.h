// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Ismail Badia (2019) and Nawfel BENATIA (2025).

// Reference : Solin, P., Segeth, K., & Dolezel, I. (2003).
//             Higher-Order Finite Element Methods (1st ed.).
//             Chapman and Hall/CRC. https://doi.org/10.1201/9780203488041

#ifndef HCURL_HEXAHEDRON_H
#define HCURL_HEXAHEDRON_H

#include "HierarchicalBasis.h"

// H(curl) basis on the hexahedron [-1, 1]^3, with the affine coordinates a0,
// ..., a5 of hexahedronCoordinates:
// - the functions of the edges (see hexahedronEdges): the product of the two
//   affine coordinates across the edge times the tensor product edge functions
//   (see hcurlTensorEdge);
// - the functions of the faces (see hexahedronFaces): the affine coordinate
//   across the face times the face functions of its two coordinates (see
//   hcurlQuadrangle);
// - the bubble functions L_n1(u) l_n2(v) l_n3(w) e_u, n1 = 0, ..., p, n2, n3 =
//   2, ..., p + 1, and the same with the roles of u, v, w exchanged for e_v and
//   e_w;
// where L_k are the Legendre polynomials and l_k the Lobatto polynomials.
class HcurlHexahedron : public HierarchicalBasis {
public:
  HcurlHexahedron(int order);
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
