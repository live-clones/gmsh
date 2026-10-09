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

#include "HcurlTetrahedron.h"
#include "Blocks.h"

HcurlTetrahedron::HcurlTetrahedron(int order) : _order(order), _h1(order + 1)
{
  _numVertex = 4;
  _numEdge = 6;
  _numTriFace = 4;
  _numQuadFace = 0;
  _numVertexFunction = 0;
  _numEdgeFunction = 6 * order + 6;
  _numQuadFaceFunction = 0;
  _numTriFaceFunction = order ? 4 * (order - 1) * (order + 1) : 0;
  _numBubbleFunction = order ? (order + 1) * (order - 1) * (order - 2) / 2 : 0;
}

// the affine coordinates of the vertices
static void coordinates(const Dual *x, Dual *L)
{
  L[0] = 1. - x[0] - x[1] - x[2];
  L[1] = x[0];
  L[2] = x[1];
  L[3] = x[2];
}

// The rotational bubble functions of order l, with u_i and v_j as in
// hcurlTriangleRotational for (a, b, c) = (L0, L1, L2) and w_k = L3 P_k-1(L3 -
// L0 - L1 - L2, 1), P being the scaled Legendre polynomials: v_j w_k times the
// Whitney function of (L0, L1), j + k = l - 1, then (j v_j grad(u_i) - i u_i
// grad(v_j)) w_k, then (k w_k grad(v_j) - j v_j grad(w_k)) u_i, i + j + k = l
// + 1, i >= 2, j, k >= 1, by increasing i, then j. Like the face functions,
// they belong to the Nedelec space of the first kind of order l.
static int rotationalBubbles(const Dual *L, int l, Vec *f)
{
  const Dual &a = L[0], &b = L[1], &c = L[2], &d = L[3];
  Dual s = a + b + c, all = s + d;
  auto u = [&](int i) { return a * b * scaledLegendre(i - 2, b - a, a + b); };
  auto v = [&](int j) { return c * scaledLegendre(j - 1, c - a - b, s); };
  auto w = [&](int k) { return d * scaledLegendre(k - 1, d - s, all); };
  int n = 0;
  for(int j = 1; j <= l - 2; j++) f[n++] = v(j) * w(l - 1 - j) * whitney(a, b);
  for(int type = 0; type < 2; type++)
    for(int i = 2; i <= l - 1; i++)
      for(int j = 1; j <= l - i; j++) {
        int k = l + 1 - i - j;
        Dual ui = u(i), vj = v(j), wk = w(k);
        if(type == 0)
          f[n++] = wk * (double(j) * vj * grad(ui) - double(i) * ui * grad(vj));
        else
          f[n++] = ui * (double(k) * wk * grad(vj) - double(j) * vj * grad(wk));
      }
  return n;
}

void HcurlTetrahedron::functions(const Dual *x, std::vector<Vec> &vertex,
                                 std::vector<Vec> &edge, std::vector<Vec> &face,
                                 std::vector<Vec> &bubble)
{
  Dual L[4];
  coordinates(x, L);
  std::vector<Dual> hv, he, hf, hb;
  h1Functions(_h1, x, hv, he, hf, hb);
  int n = 0;
  for(int e = 0; e < 6; e++) {
    const int *v = tetrahedronEdges[e];
    n +=
      hcurlEdge(whitney(L[v[0]], L[v[1]]), &he[e * _order], _order, &edge[n]);
  }
  const int perH1Face = _order * (_order - 1) / 2;
  n = 0;
  for(int f = 0; f < 4; f++) {
    const int *v = tetrahedronFaces[f];
    n += hcurlTriangle(L[v[0]], L[v[1]], L[v[2]], Dual(1.), &hf[f * perH1Face],
                       _order, &face[n]);
  }
  // by increasing order l, the gradients of the H1 bubbles of order l + 1,
  // then the rotational functions of order l
  std::vector<Vec> r(_numBubbleFunction + 1);
  n = 0;
  for(int l = 3; l <= _order; l++) {
    int d = l - 3;
    for(int k = d * (d + 1) * (d + 2) / 6; k < (d + 1) * (d + 2) * (d + 3) / 6;
        k++)
      bubble[n++] = grad(hb[k]);
    int nr = rotationalBubbles(L, l, r.data());
    for(int k = 0; k < nr; k++) bubble[n++] = r[k];
  }
}

void HcurlTetrahedron::faceFunctions(const Dual *x, int flag1, int flag2,
                                     int flag3, int faceNumber,
                                     std::vector<Vec> &face)
{
  Dual L[4];
  coordinates(x, L);
  std::vector<Dual> hf;
  h1FaceFunctions(_h1, x, flag1, flag2, flag3, faceNumber, hf);
  const int *v = tetrahedronFaces[faceNumber], *r = triangleRoles(flag1, flag2);
  const int perH1Face = _order * (_order - 1) / 2,
            perFace = _numTriFaceFunction / 4;
  hcurlTriangle(L[v[r[0]]], L[v[r[1]]], L[v[r[2]]], Dual(1.),
                &hf[faceNumber * perH1Face], _order,
                &face[faceNumber * perFace]);
}

void HcurlTetrahedron::functionInfo(std::vector<FunctionInfo> &info)
{
  for(int e = 0; e < 6; e++) hcurlEdgeInfo(_order, info);
  for(int f = 0; f < 4; f++) hcurlTriangleInfo(_order, info);
  for(int l = 3; l <= _order; l++) {
    for(int k = 0; k < (l - 2) * (l - 1) / 2; k++) info.push_back({3, l, true});
    for(int k = 0; k < (l - 2) * l; k++) info.push_back({3, l, false});
  }
}
