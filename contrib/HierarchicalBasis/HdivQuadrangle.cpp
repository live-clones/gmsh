// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Ismail Badia (2019) and Nawfel BENATIA (2025).

// Reference : Solin, P., Segeth, K., & Dolezel, I. (2003).
//             Higher-Order Finite Element Methods (1st ed.).
//             Chapman and Hall/CRC. https://doi.org/10.1201/9780203488041

#include "HdivQuadrangle.h"
#include "Blocks.h"

HdivQuadrangle::HdivQuadrangle(int order) : _order(order)
{
  _numVertex = 4;
  _numEdge = 4;
  _numQuadFace = 1;
  _numTriFace = 0;
  _numVertexFunction = 0;
  _numEdgeFunction = 4 * order + 4;
  _numQuadFaceFunction = 2 * order * (order + 1);
  _numTriFaceFunction = 0;
  _numBubbleFunction = 0;
}

void HdivQuadrangle::functions(const Dual *x, std::vector<Vec> &vertex,
                               std::vector<Vec> &edge, std::vector<Vec> &face,
                               std::vector<Vec> &bubble)
{
  const Dual &u = x[0], &v = x[1];
  Dual a1 = 0.5 * (1. + u), a2 = 0.5 * (1. - u), a3 = 0.5 * (1. + v),
       a4 = 0.5 * (1. - v);
  int n = 0;
  n += hcurlTensorEdge(u, a4, _order, &edge[n]);
  n += hcurlTensorEdge(v, a1, _order, &edge[n]);
  n += hcurlTensorEdge(u, a3, _order, &edge[n]);
  n += hcurlTensorEdge(v, a2, _order, &edge[n]);
  for(int i = 0; i < n; i++) edge[i] = -1. * rotate(edge[i]);
  hdivQuadrangle(u, v, _order, face.data());
}

void HdivQuadrangle::faceFunctions(const Dual *x, int flag1, int flag2,
                                   int flag3, int faceNumber,
                                   std::vector<Vec> &face)
{
  Dual s, t;
  quadrangleCoordinates(x[0], x[1], flag1, flag2, flag3, s, t);
  hdivQuadrangle(s, t, _order, face.data());
}

void HdivQuadrangle::keysInfo(std::vector<int> &functionTypeInfo,
                              std::vector<int> &orderInfo)
{
  int it = 0;
  for(int e = 0; e < 4; e++)
    for(int k = 0; k <= _order; k++, it++) {
      functionTypeInfo[it] = 1;
      orderInfo[it] = k;
    }
  for(int n1 = 0; n1 <= _order; n1++)
    for(int n2 = 2; n2 <= _order + 1; n2++, it++) {
      functionTypeInfo[it] = 2;
      orderInfo[it] = std::max(n1, n2);
    }
  for(int n1 = 2; n1 <= _order + 1; n1++)
    for(int n2 = 0; n2 <= _order; n2++, it++) {
      functionTypeInfo[it] = 2;
      orderInfo[it] = std::max(n1, n2);
    }
}
