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

#include "HcurlPrism.h"
#include "Blocks.h"

// the edges of the triangle under the quadrilateral faces s0, s1, s2
static const int quadEdges[3][2] = {{0, 1}, {0, 2}, {1, 2}};

HcurlPrism::HcurlPrism(int order) : _order(order), _h1(order + 1)
{
  _numVertex = 6;
  _numEdge = 9;
  _numTriFace = (order < 2) ? 0 : 2;
  _numQuadFace = 3;
  _numVertexFunction = 0;
  _numEdgeFunction = 9 * order + 9;
  _numQuadFaceFunction = 6 * order * (order + 1);
  _numTriFaceFunction = _numTriFace * (order - 1) * (order + 1);
  _numBubbleFunction = 3 * order * (order - 1) * (order + 1) / 2;
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

// the order of the i-th rotational function of hcurlTriangleRotational: l for
// the (l - 1) l / 2 - 1-th to the l (l + 1) / 2 - 2-th functions
static int rotationalOrder(int i)
{
  int l = 2;
  while(l * (l + 1) / 2 - 1 <= i) l++;
  return l;
}

// the number of H1 bubbles of H1Prism of order m (see H1Prism::functions)
static int numH1Bubbles(int m)
{
  int n = 0;
  for(int i = 0; i < (m - 2) * (m - 1) / 2; i++)
    for(int k = 2; k <= m; k++)
      if(std::max(triangleOrder(i), k) == m) n++;
  return n;
}

int HcurlPrism::_quadrangle(const Dual *x, int f, int flag1, int flag2,
                            int flag3, const Dual *h, Vec *out)
{
  Dual L[3], B, T;
  coordinates(x, L, B, T);
  // the coordinate along the edge (a, b) of the triangle, reversed by flag1,
  // and the vertical one, reversed by flag2; flag3 = -1 exchanges them
  int ia = quadEdges[f][0], ib = quadEdges[f][1];
  if(flag1 == -1) std::swap(ia, ib);
  const Dual &a = L[ia], &b = L[ib], w = double(flag2) * x[2];
  auto Ph = [&](int n) { return a * b * kernel(n, b - a); };
  auto Pv = [&](int n) { return B * T * kernel(n, w); };
  Vec Wh = whitney(a, b), Wv = grad(w);
  bool swap = (flag3 == -1);
  int n = 0;
  for(int l = 1; l <= _order; l++) {
    for(int k = (l - 1) * (l - 1); k < l * l; k++) out[n++] = grad(h[k]);
    Dual Ps = swap ? Pv(l - 1) : Ph(l - 1), Pt = swap ? Ph(l - 1) : Pv(l - 1);
    out[n++] = Pt * (swap ? Wv : Wh);
    out[n++] = Ps * (swap ? Wh : Wv);
    for(int n1 = 0; n1 <= l - 1; n1++)
      for(int n2 = 0; n2 <= l - 1; n2++)
        if(std::max(n1, n2) == l - 1) {
          Dual s = swap ? Pv(n1) : Ph(n1), t = swap ? Ph(n2) : Pv(n2);
          out[n++] = t * grad(s) - s * grad(t);
        }
  }
  return n;
}

void HcurlPrism::functions(const Dual *x, std::vector<Vec> &vertex,
                           std::vector<Vec> &edge, std::vector<Vec> &face,
                           std::vector<Vec> &bubble)
{
  Dual L[3], B, T;
  coordinates(x, L, B, T);
  std::vector<Dual> hv, he, hf, hb;
  h1Functions(_h1, x, hv, he, hf, hb);
  const int p = _order, per = p + 1;
  // the horizontal edges of the bottom (e0, e1, e3) and top (e6, e7, e8)
  // triangles, and the vertical edges (e2, e4, e5)
  int bottom[3] = {0, 1, 3}, top[3] = {6, 7, 8}, vertical[3] = {2, 4, 5};
  for(int i = 0; i < 3; i++) {
    Vec w = whitney(L[quadEdges[i][0]], L[quadEdges[i][1]]);
    hcurlEdge(B * w, &he[bottom[i] * p], p, &edge[bottom[i] * per]);
    hcurlEdge(T * w, &he[top[i] * p], p, &edge[top[i] * per]);
    hcurlEdge(L[i] * whitney(B, T), &he[vertical[i] * p], p,
              &edge[vertical[i] * per]);
  }
  const int perH1Quad = p * p, perH1Tri = p * (p - 1) / 2;
  int n = 0;
  for(int f = 0; f < 3; f++)
    n += _quadrangle(x, f, 1, 1, 1, &hf[f * perH1Quad], &face[n]);
  for(int f = 0; f < _numTriFace; f++)
    n += hcurlTriangle(L[0], L[1], L[2], f == 0 ? B : T,
                       &hf[3 * perH1Quad + f * perH1Tri], p, &face[n]);
  // the interior, by increasing order l: the gradients of the H1 bubbles of
  // order l + 1, then R l_k, F grad(w) and F grad(l_k) - l_k grad(F)
  std::vector<Vec> R(p * p);
  int nR = hcurlTriangleRotational(L[0], L[1], L[2], Dual(1.), p, R.data());
  std::vector<Dual> F(p * p);
  int nF = h1Triangle(L[0], L[1], L[2], Dual(1.), p + 1, F.data());
  n = 0;
  int nb = 0;
  for(int l = 2; l <= p; l++) {
    for(int k = 0; k < numH1Bubbles(l + 1); k++) bubble[n++] = grad(hb[nb++]);
    for(int r = 0; r < nR; r++)
      for(int k = 2; k <= p + 1; k++)
        if(std::max(rotationalOrder(r), k - 1) == l)
          bubble[n++] = lobatto(k, x[2]) * R[r];
    for(int i = 0; i < nF; i++)
      if(triangleOrder(i) - 1 == l) bubble[n++] = F[i] * whitney(B, T);
    for(int i = 0; i < nF; i++)
      for(int k = 2; k <= p + 1; k++)
        if(std::max(triangleOrder(i), k) - 1 == l) {
          Dual lk = lobatto(k, x[2]);
          bubble[n++] = F[i] * grad(lk) - lk * grad(F[i]);
        }
  }
}

void HcurlPrism::faceFunctions(const Dual *x, int flag1, int flag2, int flag3,
                               int faceNumber, std::vector<Vec> &face)
{
  Dual L[3], B, T;
  coordinates(x, L, B, T);
  std::vector<Dual> hf;
  h1FaceFunctions(_h1, x, flag1, flag2, flag3, faceNumber, hf);
  const int p = _order, perQuad = 2 * p * (p + 1), perH1Quad = p * p,
            perTri = (p - 1) * (p + 1), perH1Tri = p * (p - 1) / 2;
  if(faceNumber < 3)
    _quadrangle(x, faceNumber, flag1, flag2, flag3, &hf[faceNumber * perH1Quad],
                &face[faceNumber * perQuad]);
  else {
    const int *r = triangleRoles(flag1, flag2);
    int f = faceNumber - 3;
    hcurlTriangle(L[r[0]], L[r[1]], L[r[2]], f == 0 ? B : T,
                  &hf[3 * perH1Quad + f * perH1Tri], p,
                  &face[3 * perQuad + f * perTri]);
  }
}

void HcurlPrism::functionInfo(std::vector<FunctionInfo> &info)
{
  const int p = _order;
  for(int e = 0; e < 9; e++) hcurlEdgeInfo(p, info);
  for(int f = 0; f < 3; f++)
    for(int l = 1; l <= p; l++) {
      for(int k = 0; k < 2 * l - 1; k++) info.push_back({2, l, true});
      for(int k = 0; k < 2 * l + 1; k++) info.push_back({2, l, false});
    }
  for(int f = 0; f < _numTriFace; f++) hcurlTriangleInfo(p, info);
  int nR = (p + 2) * (p - 1) / 2, nF = p * (p - 1) / 2;
  for(int l = 2; l <= p; l++) {
    for(int k = 0; k < numH1Bubbles(l + 1); k++) info.push_back({3, l, true});
    for(int r = 0; r < nR; r++)
      for(int k = 2; k <= p + 1; k++)
        if(std::max(rotationalOrder(r), k - 1) == l)
          info.push_back({3, l, false});
    for(int i = 0; i < nF; i++)
      if(triangleOrder(i) - 1 == l) info.push_back({3, l, false});
    for(int i = 0; i < nF; i++)
      for(int k = 2; k <= p + 1; k++)
        if(std::max(triangleOrder(i), k) - 1 == l)
          info.push_back({3, l, false});
  }
}
