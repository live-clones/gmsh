// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Ismail Badia (2019) and Nawfel BENATIA (2025).

// Reference : Solin, P., Segeth, K., & Dolezel, I. (2003).
//             Higher-Order Finite Element Methods (1st ed.).
//             Chapman and Hall/CRC. https://doi.org/10.1201/9780203488041

#include "H1Triangle.h"
#include "Blocks.h"

H1Triangle::H1Triangle(int order) : _order(order)
{
  _numVertex = 3;
  _numEdge = 3;
  _numTriFace = 1;
  _numQuadFace = 0;
  _numVertexFunction = 3;
  _numEdgeFunction = 3 * order - 3;
  _numQuadFaceFunction = 0;
  _numTriFaceFunction = (order >= 3) ? (order - 1) * (order - 2) / 2 : 0;
  _numBubbleFunction = 0;
}

// the affine coordinates of the vertices
static void coordinates(const Dual *x, Dual *L)
{
  L[0] = 1. - x[0] - x[1];
  L[1] = x[0];
  L[2] = x[1];
}

void H1Triangle::functions(const Dual *x, std::vector<Dual> &vertex,
                           std::vector<Dual> &edge, std::vector<Dual> &face,
                           std::vector<Dual> &bubble)
{
  Dual L[3];
  coordinates(x, L);
  for(int i = 0; i < 3; i++) vertex[i] = L[i];
  int n = 0;
  for(int e = 0; e < 3; e++)
    n += h1Edge(L[e], L[(e + 1) % 3], _order, &edge[n]);
  h1Triangle(L[0], L[1], L[2], Dual(1.), _order, face.data());
}

void H1Triangle::faceFunctions(const Dual *x, int flag1, int flag2, int flag3,
                               int faceNumber, std::vector<Dual> &face)
{
  Dual L[3];
  coordinates(x, L);
  const int *r = triangleRoles(flag1, flag2);
  h1Triangle(L[r[0]], L[r[1]], L[r[2]], Dual(1.), _order, face.data());
}

void H1Triangle::keysInfo(std::vector<int> &functionTypeInfo,
                          std::vector<int> &orderInfo)
{
  int it = 0;
  for(int i = 0; i < 3; i++, it++) {
    functionTypeInfo[it] = 0;
    orderInfo[it] = 1;
  }
  for(int e = 0; e < 3; e++)
    for(int k = 2; k <= _order; k++, it++) {
      functionTypeInfo[it] = 1;
      orderInfo[it] = k;
    }
  for(int d = 0; d <= _order - 3; d++)
    for(int n2 = 0; n2 <= d; n2++, it++) {
      functionTypeInfo[it] = 2;
      orderInfo[it] = d + 3;
    }
}
