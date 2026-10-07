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

H1Triangle::H1Triangle(int order) : _order(order)
{
  _dual = true;
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
  for(int e = 0; e < 3; e++) {
    const Dual &a = L[e], &b = L[(e + 1) % 3];
    for(int k = 0; k <= _order - 2; k++) edge[n++] = a * b * kernel(k, b - a);
  }
  _faceFunctions(L[0], L[1], L[2], face);
}

void H1Triangle::_faceFunctions(const Dual &a, const Dual &b, const Dual &c,
                                std::vector<Dual> &face)
{
  Dual abc = a * b * c;
  int n = 0;
  for(int n1 = 0; n1 <= _order - 3; n1++) {
    Dual k1 = kernel(n1, b - a);
    for(int n2 = 0; n2 <= _order - 3 - n1; n2++)
      face[n++] = abc * k1 * kernel(n2, a - c);
  }
}

void H1Triangle::faceFunctions(const Dual *x, int flag1, int flag2, int flag3,
                               int faceNumber, std::vector<Dual> &face)
{
  // the roles (a, b, c) taken by L0, L1, L2 in each orientation of the face
  static const int roles[3][2][3] = {
    {{0, 2, 1}, {0, 1, 2}}, {{1, 0, 2}, {1, 2, 0}}, {{2, 1, 0}, {2, 0, 1}}};
  const int *r = roles[flag1][flag2 == 1 ? 1 : 0];
  Dual L[3];
  coordinates(x, L);
  _faceFunctions(L[r[0]], L[r[1]], L[r[2]], face);
}

void H1Triangle::getKeysInfo(std::vector<int> &functionTypeInfo,
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
  for(int n1 = 0; n1 <= _order - 3; n1++)
    for(int n2 = 0; n2 <= _order - 3 - n1; n2++, it++) {
      functionTypeInfo[it] = 2;
      orderInfo[it] = n1 + n2 + 3;
    }
}
