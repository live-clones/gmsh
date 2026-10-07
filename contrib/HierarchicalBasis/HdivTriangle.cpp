// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Ismail Badia (2019) and Nawfel BENATIA (2025).

// Reference : Solin, P., Segeth, K., & Dolezel, I. (2003).
//             Higher-Order Finite Element Methods (1st ed.).
//             Chapman and Hall/CRC. https://doi.org/10.1201/9780203488041

#include "HdivTriangle.h"
#include "Blocks.h"

HdivTriangle::HdivTriangle(int order) : _order(order)
{
  _dual = true;
  _numVertex = 3;
  _numEdge = 3;
  _numTriFace = 1;
  _numQuadFace = 0;
  _numVertexFunction = 0;
  _numEdgeFunction = 3 * order + 3;
  _numQuadFaceFunction = 0;
  _numTriFaceFunction =
    (order == 0) ? 0 : 3 * (order - 1) + (order - 1) * (order - 2);
  _numBubbleFunction = 0;
}

// the affine coordinates of the vertices
static void coordinates(const Dual *x, Dual *L)
{
  L[0] = 1. - x[0] - x[1];
  L[1] = x[0];
  L[2] = x[1];
}

void HdivTriangle::functions(const Dual *x, std::vector<Vec> &vertex,
                             std::vector<Vec> &edge, std::vector<Vec> &face,
                             std::vector<Vec> &bubble)
{
  Dual L[3];
  coordinates(x, L);
  int n = 0;
  for(int e = 0; e < 3; e++)
    n += hdivEdge(L[e], L[(e + 1) % 3], _order, &edge[n]);
  hdivTriangle(L[0], L[1], L[2], _order, face.data());
}

void HdivTriangle::faceFunctions(const Dual *x, int flag1, int flag2, int flag3,
                                 int faceNumber, std::vector<Vec> &face)
{
  Dual L[3];
  coordinates(x, L);
  const int *r = triangleRoles(flag1, flag2);
  hdivTriangle(L[r[0]], L[r[1]], L[r[2]], _order, face.data());
}

void HdivTriangle::getKeysInfo(std::vector<int> &functionTypeInfo,
                               std::vector<int> &orderInfo)
{
  int it = 0;
  for(int e = 0; e < 3; e++)
    for(int k = 0; k <= _order; k++, it++) {
      functionTypeInfo[it] = 1;
      orderInfo[it] = k;
    }
  for(int e = 0; e < 3; e++)
    for(int k = 2; k <= _order; k++, it++) {
      functionTypeInfo[it] = 2;
      orderInfo[it] = k;
    }
  for(int g = 0; g < 2; g++)
    for(int n1 = 0; n1 <= _order - 3; n1++)
      for(int n2 = 0; n2 <= _order - 3 - n1; n2++, it++) {
        functionTypeInfo[it] = 2;
        orderInfo[it] = n1 + n2 + 3;
      }
}
