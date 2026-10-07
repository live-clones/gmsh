// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Ismail Badia (2019) and Nawfel BENATIA (2025).

// Reference : Solin, P., Segeth, K., & Dolezel, I. (2003).
//             Higher-Order Finite Element Methods (1st ed.).
//             Chapman and Hall/CRC. https://doi.org/10.1201/9780203488041

#include "HcurlLine.h"
#include "Blocks.h"

HcurlLine::HcurlLine(int order) : _order(order)
{
  _dual = true;
  _numVertex = 2;
  _numEdge = 1;
  _numQuadFace = _numTriFace = 0;
  _numVertexFunction = 0;
  _numEdgeFunction = order + 1;
  _numQuadFaceFunction = _numTriFaceFunction = _numBubbleFunction = 0;
}

void HcurlLine::functions(const Dual *x, std::vector<Vec> &vertex,
                          std::vector<Vec> &edge, std::vector<Vec> &face,
                          std::vector<Vec> &bubble)
{ hcurlTensorEdge(x[0], Dual(1.), _order, edge.data()); }

void HcurlLine::getKeysInfo(std::vector<int> &functionTypeInfo,
                            std::vector<int> &orderInfo)
{
  for(int k = 0; k <= _order; k++) {
    functionTypeInfo[k] = 1;
    orderInfo[k] = k;
  }
}
