// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Ismail Badia (2019) and Nawfel BENATIA (2025).

// Reference : Solin, P., Segeth, K., & Dolezel, I. (2003).
//             Higher-Order Finite Element Methods (1st ed.).
//             Chapman and Hall/CRC. https://doi.org/10.1201/9780203488041

#include "H1Prism.h"
#include "Blocks.h"

// the edges of the triangle under the quadrilateral faces s0, s1, s2
static const int quadEdges[3][2] = {{0, 1}, {0, 2}, {1, 2}};

H1Prism::H1Prism(int order) : _order(order)
{
  _numVertex = 6;
  _numEdge = 9;
  _numTriFace = (order < 3) ? 0 : 2;
  _numQuadFace = 3;
  _numVertexFunction = 6;
  _numEdgeFunction = 9 * order - 9;
  _numQuadFaceFunction = 3 * (order - 1) * (order - 1);
  _numTriFaceFunction = (order - 2) * (order - 1);
  _numBubbleFunction = (order - 1) * (order - 2) * (order - 1) / 2;
}

// the affine coordinates L0, L1, L2 of the triangle, and B and T
static void coordinates(const Dual *x, Dual *L, Dual &B, Dual &T)
{
  L[0] = 1. - x[0] - x[1];
  L[1] = x[0];
  L[2] = x[1];
  B = 0.5 * (1. - x[2]);
  T = 0.5 * (1. + x[2]);
}

void H1Prism::functions(const Dual *x, std::vector<Dual> &vertex,
                        std::vector<Dual> &edge, std::vector<Dual> &face,
                        std::vector<Dual> &bubble)
{
  Dual L[3], B, T;
  coordinates(x, L, B, T);
  for(int i = 0; i < 3; i++) {
    vertex[i] = L[i] * B;
    vertex[i + 3] = L[i] * T;
  }
  // the horizontal edges of the bottom (e0, e1, e3) and top (e6, e7, e8)
  // triangles, and the vertical edges (e2, e4, e5)
  const int per = _order - 1;
  Dual *e = edge.data();
  int bottom[3] = {0, 1, 3}, top[3] = {6, 7, 8}, vertical[3] = {2, 4, 5};
  for(int i = 0; i < 3; i++) {
    const Dual &a = L[quadEdges[i][0]], &b = L[quadEdges[i][1]];
    h1Edge(a, b, _order, e + bottom[i] * per);
    h1Edge(a, b, _order, e + top[i] * per);
    h1Edge(B, T, _order, e + vertical[i] * per);
    for(int k = 0; k < per; k++) {
      e[bottom[i] * per + k] = B * e[bottom[i] * per + k];
      e[top[i] * per + k] = T * e[top[i] * per + k];
      e[vertical[i] * per + k] = L[i] * e[vertical[i] * per + k];
    }
  }
  int n = 0;
  for(int i = 0; i < 3; i++) {
    const Dual &a = L[quadEdges[i][0]], &b = L[quadEdges[i][1]];
    n += h1QuadrangleKernel(b - a, T - B, a * b * B * T, _order, &face[n]);
  }
  if(_numTriFace) {
    n += h1Triangle(L[0], L[1], L[2], B, _order, &face[n]);
    h1Triangle(L[0], L[1], L[2], T, _order, &face[n]);
  }
  std::vector<Dual> tri(_numTriFaceFunction / 2 + 1);
  int nt = h1Triangle(L[0], L[1], L[2], Dual(1.), _order, tri.data());
  n = 0;
  for(int i = 0; i < nt; i++)
    for(int k = 2; k <= _order; k++) bubble[n++] = tri[i] * lobatto(k, x[2]);
}

void H1Prism::faceFunctions(const Dual *x, int flag1, int flag2, int flag3,
                            int faceNumber, std::vector<Dual> &face)
{
  Dual L[3], B, T;
  coordinates(x, L, B, T);
  const int perQuad = (_order - 1) * (_order - 1);
  if(faceNumber < 3) {
    const Dual &a = L[quadEdges[faceNumber][0]],
               &b = L[quadEdges[faceNumber][1]];
    Dual s, t;
    quadrangleCoordinates(b - a, T - B, flag1, flag2, flag3, s, t);
    h1QuadrangleKernel(s, t, a * b * B * T, _order,
                       &face[faceNumber * perQuad]);
  }
  else {
    const int *r = triangleRoles(flag1, flag2);
    int perTri = (_order - 2) * (_order - 1) / 2;
    h1Triangle(L[r[0]], L[r[1]], L[r[2]], faceNumber == 3 ? B : T, _order,
               &face[3 * perQuad + (faceNumber - 3) * perTri]);
  }
}

void H1Prism::getKeysInfo(std::vector<int> &functionTypeInfo,
                          std::vector<int> &orderInfo)
{
  int it = 0;
  for(int i = 0; i < 6; i++, it++) {
    functionTypeInfo[it] = 0;
    orderInfo[it] = 1;
  }
  for(int e = 0; e < 9; e++)
    for(int k = 2; k <= _order; k++, it++) {
      functionTypeInfo[it] = 1;
      orderInfo[it] = k;
    }
  for(int f = 0; f < 3; f++)
    for(int n1 = 2; n1 <= _order; n1++)
      for(int n2 = 2; n2 <= _order; n2++, it++) {
        functionTypeInfo[it] = 2;
        orderInfo[it] = std::max(n1, n2);
      }
  for(int f = 0; f < _numTriFace; f++)
    for(int n1 = 0; n1 <= _order - 3; n1++)
      for(int n2 = 0; n2 <= _order - 3 - n1; n2++, it++) {
        functionTypeInfo[it] = 2;
        orderInfo[it] = n1 + n2 + 3;
      }
  for(int n1 = 0; n1 <= _order - 3; n1++)
    for(int n2 = 0; n2 <= _order - 3 - n1; n2++)
      for(int n3 = 2; n3 <= _order; n3++, it++) {
        functionTypeInfo[it] = 3;
        orderInfo[it] = std::max(n1 + n2 + 3, n3);
      }
}
