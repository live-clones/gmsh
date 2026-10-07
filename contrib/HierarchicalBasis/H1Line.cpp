// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Ismail Badia (2019) and Nawfel BENATIA (2025).

// Reference : Solin, P., Segeth, K., & Dolezel, I. (2003).
//             Higher-Order Finite Element Methods (1st ed.).
//             Chapman and Hall/CRC. https://doi.org/10.1201/9780203488041

#include "H1Line.h"

H1Line::H1Line(int order) : _order(order)
{
  _numVertex = 2;
  _numEdge = 1;
  _numQuadFace = _numTriFace = 0;
  _numVertexFunction = 2;
  _numEdgeFunction = order - 1;
  _numQuadFaceFunction = _numTriFaceFunction = _numBubbleFunction = 0;
}

void H1Line::functions(const Dual *x, std::vector<Dual> &vertex,
                       std::vector<Dual> &edge, std::vector<Dual> &face,
                       std::vector<Dual> &bubble)
{
  // the affine coordinates of the vertices
  Dual l0 = 0.5 * (1. - x[0]), l1 = 0.5 * (1. + x[0]);
  vertex[0] = l0;
  vertex[1] = l1;
  for(int k = 2; k <= _order; k++)
    edge[k - 2] = l1 * l0 * kernel(k - 2, l1 - l0);
}

void H1Line::getKeysInfo(std::vector<int> &functionTypeInfo,
                         std::vector<int> &orderInfo)
{
  for(int i = 0; i < 2; i++) {
    functionTypeInfo[i] = 0;
    orderInfo[i] = 1;
  }
  for(int k = 2; k <= _order; k++) {
    functionTypeInfo[k] = 1;
    orderInfo[k] = k;
  }
}
