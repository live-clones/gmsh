// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Ismail Badia (2019) and Nawfel BENATIA (2025).

// Reference : Solin, P., Segeth, K., & Dolezel, I. (2003).
//             Higher-Order Finite Element Methods (1st ed.).
//             Chapman and Hall/CRC. https://doi.org/10.1201/9780203488041

#include "HcurlPrism.h"
#include "Blocks.h"

// the edges of the triangle under the quadrilateral faces s0, s1, s2
static const int quadEdges[3][2] = {{0, 1}, {0, 2}, {1, 2}};

HcurlPrism::HcurlPrism(int order) : _order(order)
{
  _dual = true;
  _numVertex = 6;
  _numEdge = 9;
  _numTriFace = (order < 2) ? 0 : 2;
  _numQuadFace = 3;
  _numVertexFunction = 0;
  _numEdgeFunction = 9 * order + 9;
  _numQuadFaceFunction = 6 * order * (order + 1);
  _numTriFaceFunction =
    order ? 6 * (order - 1) + 2 * (order - 1) * (order - 2) : 0;
  _numBubbleFunction = 3 * (order - 1) * order +
                       (order - 1) * (order - 2) * order +
                       (order - 1) * order * (order + 1) / 2;
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

void HcurlPrism::functions(const Dual *x, std::vector<Vec> &vertex,
                           std::vector<Vec> &edge, std::vector<Vec> &face,
                           std::vector<Vec> &bubble)
{
  Dual L[3], B, T;
  coordinates(x, L, B, T);
  const Dual &w = x[2];
  const int p = _order, per = p + 1;
  // the horizontal edges of the bottom (e0, e1, e3) and top (e6, e7, e8)
  // triangles, and the vertical edges (e2, e4, e5)
  int bottom[3] = {0, 1, 3}, top[3] = {6, 7, 8}, vertical[3] = {2, 4, 5};
  std::vector<Vec> e(per);
  for(int i = 0; i < 3; i++) {
    hcurlEdge(L[quadEdges[i][0]], L[quadEdges[i][1]], p, e.data());
    for(int k = 0; k <= p; k++) {
      edge[bottom[i] * per + k] = B * e[k];
      edge[top[i] * per + k] = T * e[k];
    }
    hcurlTensorEdge(w, L[i], p, &edge[vertical[i] * per]);
  }
  int n = 0;
  for(int i = 0; i < 3; i++)
    n += hcurlPrismQuadrangle(L[quadEdges[i][0]], L[quadEdges[i][1]], w, false,
                              p, &face[n]);
  if(_numTriFace) {
    std::vector<Vec> t(_numTriFaceFunction / 2);
    hcurlTriangle(L[0], L[1], L[2], p, t.data());
    for(std::size_t i = 0; i < t.size(); i++) {
      face[n + i] = B * t[i];
      face[n + t.size() + i] = T * t[i];
    }
  }
  // the bubble functions based on the quadrilateral faces, on the edges
  // (x, y) of the triangle, opposite to the vertex z
  static const int xyz[3][3] = {{0, 1, 2}, {2, 0, 1}, {1, 2, 0}};
  n = 0;
  for(int f = 0; f < 3; f++) {
    const Dual &a = L[xyz[f][0]], &b = L[xyz[f][1]];
    Vec dir = grad(L[xyz[f][2]]);
    for(int k = 0; k <= p - 2; k++)
      for(int j = 2; j <= p + 1; j++)
        bubble[n++] = a * b * legendre(k, b - a) * lobatto(j, w) * dir;
  }
  // the genuine bubble functions, and those based on the triangular faces
  Dual all = L[0] * L[1] * L[2];
  for(int g = 0; g < 2; g++) {
    Vec dir = (g == 0 ? 2. : -2.) * grad(x[g]);
    for(int n1 = 0; n1 <= p - 3; n1++)
      for(int n2 = 0; n2 <= p - 3 - n1; n2++) {
        Dual t = all * legendre(n1, L[1] - L[0]) * legendre(n2, L[0] - L[2]);
        for(int j = 2; j <= p + 1; j++) bubble[n++] = t * lobatto(j, w) * dir;
      }
  }
  for(int n1 = 0; n1 <= p - 2; n1++)
    for(int n2 = 0; n2 <= p - 2 - n1; n2++) {
      Dual t = all * legendre(n1, L[1] - L[0]) * legendre(n2, L[0] - L[2]);
      for(int j = 0; j <= p; j++) bubble[n++] = t * legendre(j, w) * grad(w);
    }
}

void HcurlPrism::faceFunctions(const Dual *x, int flag1, int flag2, int flag3,
                               int faceNumber, std::vector<Vec> &face)
{
  Dual L[3], B, T;
  coordinates(x, L, B, T);
  const int perQuad = 2 * _order * (_order + 1);
  if(faceNumber < 3) {
    // flag1 reverses the edge of the triangle, flag2 the vertical direction,
    // flag3 = -1 exchanges them
    int a = quadEdges[faceNumber][0], b = quadEdges[faceNumber][1];
    if(flag1 == -1) std::swap(a, b);
    hcurlPrismQuadrangle(L[a], L[b], flag2 * x[2], flag3 == -1, _order,
                         &face[faceNumber * perQuad]);
  }
  else {
    const int *r = triangleRoles(flag1, flag2);
    int perTri = _numTriFaceFunction / 2;
    std::vector<Vec> t(perTri);
    hcurlTriangle(L[r[0]], L[r[1]], L[r[2]], _order, t.data());
    const Dual &blend = (faceNumber == 3) ? B : T;
    for(int i = 0; i < perTri; i++)
      face[3 * perQuad + (faceNumber - 3) * perTri + i] = blend * t[i];
  }
}

void HcurlPrism::getKeysInfo(std::vector<int> &functionTypeInfo,
                             std::vector<int> &orderInfo)
{
  const int p = _order;
  int it = 0;
  auto set = [&](int type, int order) {
    functionTypeInfo[it] = type;
    orderInfo[it++] = order;
  };
  for(int e = 0; e < 9; e++)
    for(int k = 0; k <= p; k++) set(1, k);
  for(int f = 0; f < 3; f++) {
    for(int n1 = 0; n1 <= p; n1++)
      for(int n2 = 2; n2 <= p + 1; n2++) set(2, std::max(n1, n2));
    for(int n1 = 2; n1 <= p + 1; n1++)
      for(int n2 = 0; n2 <= p; n2++) set(2, std::max(n1, n2));
  }
  for(int f = 0; f < 2; f++) {
    for(int e = 0; e < 3; e++)
      for(int k = 2; k <= p; k++) set(2, k);
    for(int g = 0; g < 2; g++)
      for(int n1 = 0; n1 <= p - 3; n1++)
        for(int n2 = 0; n2 <= p - 3 - n1; n2++) set(2, n1 + n2 + 3);
  }
  for(int f = 0; f < 3; f++)
    for(int n1 = 2; n1 <= p; n1++)
      for(int n2 = 2; n2 <= p + 1; n2++) set(3, std::max(n1, n2));
  for(int g = 0; g < 2; g++)
    for(int n1 = 0; n1 <= p - 3; n1++)
      for(int n2 = 0; n2 <= p - 3 - n1; n2++)
        for(int n3 = 2; n3 <= p + 1; n3++) set(3, std::max(n1 + n2 + 3, n3));
  for(int n1 = 0; n1 <= p - 2; n1++)
    for(int n2 = 0; n2 <= p - 2 - n1; n2++)
      for(int n3 = 0; n3 <= p; n3++) set(3, std::max(n1 + n2 + 3, n3));
}
