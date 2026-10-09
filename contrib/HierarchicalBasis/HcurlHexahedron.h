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

#ifndef HCURL_HEXAHEDRON_H
#define HCURL_HEXAHEDRON_H

#include "HierarchicalBasis.h"
#include "H1Hexahedron.h"
// H(curl) basis on the hexahedron [-1, 1]^3, with the affine coordinates a0,
// ..., a5 of hexahedronCoordinates and the gradients of the H1 functions of
// H1Hexahedron of order p + 1:
// - the functions of the edges (see hexahedronEdges), whose lowest order
//   function is the product of the two affine coordinates across the edge
//   times the gradient of the coordinate along it (see hcurlEdge);
// - the functions of the faces (see hexahedronFaces): those of its two
//   coordinates, multiplied by the affine coordinate across the face (see
//   hcurlQuadrangle);
// - the bubble functions, by increasing order l = 1, ..., p: the gradients of
//   the H1 bubbles of order l + 1, then the rotational functions of order l
//   (see rotationalBubbles()).
class HcurlHexahedron : public HierarchicalBasis {
public:
  HcurlHexahedron(int order);
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
  H1Hexahedron _h1;
};

#endif
