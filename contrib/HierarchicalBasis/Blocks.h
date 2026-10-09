// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef BLOCKS_H
#define BLOCKS_H

#include <algorithm>
#include <vector>
#include "Dual.h"
#include "HierarchicalBasis.h"

// Building blocks shared by the hierarchical bases of several elements.

// The edges and the faces of the tetrahedron, by their vertices
static const int tetrahedronEdges[6][2] = {{0, 1}, {1, 2}, {2, 0},
                                           {0, 3}, {2, 3}, {1, 3}};
static const int tetrahedronFaces[4][3] = {
  {0, 1, 2}, {0, 1, 3}, {0, 2, 3}, {1, 2, 3}};

// The edges of the hexahedron e0 = {0, 1}, e1 = {0, 3}, e2 = {0, 4},
// e3 = {1, 2}, e4 = {1, 5}, e5 = {3, 2}, e6 = {2, 6}, e7 = {3, 7}, e8 = {4, 5},
// e9 = {4, 7}, e10 = {5, 6}, e11 = {7, 6}, by the coordinate (u, v or w) along
// each edge and its two affine coordinates a0 = (1 + u) / 2, a1 = (1 - u) / 2,
// a2 = (1 + v) / 2, a3 = (1 - v) / 2, a4 = (1 + w) / 2, a5 = (1 - w) / 2 across
static const int hexahedronEdges[12][3] = {
  {0, 3, 5}, {1, 1, 5}, {2, 1, 3}, {1, 0, 5}, {2, 3, 0}, {0, 2, 5},
  {2, 2, 0}, {2, 2, 1}, {0, 3, 4}, {1, 4, 1}, {1, 4, 0}, {0, 4, 2}};
// The faces of the hexahedron s0 = {0, 1, 3, 2}, s1 = {0, 1, 4, 5},
// s2 = {0, 3, 4, 7}, s3 = {1, 2, 5, 6}, s4 = {3, 2, 7, 6}, s5 = {4, 5, 7, 6},
// by their two coordinates and the affine coordinate across
static const int hexahedronFaces[6][3] = {{0, 1, 5}, {0, 2, 3}, {1, 2, 1},
                                          {1, 2, 0}, {0, 2, 2}, {0, 1, 4}};

// The affine coordinates a0, ..., a5 of the hexahedron
inline void hexahedronCoordinates(const Dual *x, Dual *a)
{
  for(int i = 0; i < 3; i++) {
    a[2 * i] = 0.5 * (1. + x[i]);
    a[2 * i + 1] = 0.5 * (1. - x[i]);
  }
}

// The roles (a, b, c) taken by the vertices (0, 1, 2) of a triangular face in
// the orientation of the face given by flag1 (0, 1 or 2) and flag2 (1 or -1)
inline const int *triangleRoles(int flag1, int flag2)
{
  static const int roles[3][2][3] = {
    {{0, 2, 1}, {0, 1, 2}}, {{1, 0, 2}, {1, 2, 0}}, {{2, 1, 0}, {2, 0, 1}}};
  return roles[flag1][flag2 == 1 ? 1 : 0];
}

// The H1 functions of the element h1 at the point x
inline void h1Functions(HierarchicalBasis &h1, const Dual *x,
                        std::vector<Dual> &vertex, std::vector<Dual> &edge,
                        std::vector<Dual> &face, std::vector<Dual> &bubble)
{
  vertex.resize(h1.getNumVertexFunction());
  edge.resize(h1.getNumEdgeFunction());
  face.resize(h1.getNumQuadFaceFunction() + h1.getNumTriFaceFunction());
  bubble.resize(h1.getNumBubbleFunction());
  h1.functions(x, vertex, edge, face, bubble);
}

// The H1 functions of face faceNumber of the element h1 at the point x, for
// the orientation of the face given by the flags, at their place among the
// face functions of the element (the others are not computed)
inline void h1FaceFunctions(HierarchicalBasis &h1, const Dual *x, int flag1,
                            int flag2, int flag3, int faceNumber,
                            std::vector<Dual> &face)
{
  face.resize(h1.getNumQuadFaceFunction() + h1.getNumTriFaceFunction());
  h1.faceFunctions(x, flag1, flag2, flag3, faceNumber, face);
}

// The same for the H(curl) functions of the element hcurl
inline void hcurlFunctions(HierarchicalBasis &hcurl, const Dual *x,
                           std::vector<Vec> &vertex, std::vector<Vec> &edge,
                           std::vector<Vec> &face, std::vector<Vec> &bubble)
{
  vertex.resize(hcurl.getNumVertexFunction());
  edge.resize(hcurl.getNumEdgeFunction());
  face.resize(hcurl.getNumQuadFaceFunction() + hcurl.getNumTriFaceFunction());
  bubble.resize(hcurl.getNumBubbleFunction());
  hcurl.functions(x, vertex, edge, face, bubble);
}
inline void hcurlFaceFunctions(HierarchicalBasis &hcurl, const Dual *x,
                               int flag1, int flag2, int flag3, int faceNumber,
                               std::vector<Vec> &face)
{
  face.resize(hcurl.getNumQuadFaceFunction() + hcurl.getNumTriFaceFunction());
  hcurl.faceFunctions(x, flag1, flag2, flag3, faceNumber, face);
}

// The information of the functions of the blocks below, with the given type,
// in the order of the blocks
inline void h1EdgeInfo(int type, int order, std::vector<FunctionInfo> &info)
{
  for(int k = 2; k <= order; k++) info.push_back({type, k, false});
}
inline void h1TriangleInfo(int type, int order, std::vector<FunctionInfo> &info)
{
  for(int d = 0; d <= order - 3; d++)
    for(int n2 = 0; n2 <= d; n2++) info.push_back({type, d + 3, false});
}
inline void h1QuadrangleInfo(int type, int order,
                             std::vector<FunctionInfo> &info)
{
  for(int m = 2; m <= order; m++)
    for(int k = 0; k < 2 * m - 3; k++) info.push_back({type, m, false});
}

// The H1 functions of an edge from vertex a to vertex b, of affine
// coordinates a and b: a b K_k(b - a), k = 0, ..., order - 2; return the
// number of functions
inline int h1Edge(const Dual &a, const Dual &b, int order, Dual *f)
{
  int n = 0;
  for(int k = 0; k <= order - 2; k++) f[n++] = a * b * kernel(k, b - a);
  return n;
}

// The H1 functions of a triangular face of affine coordinates (a, b, c),
// multiplied by blend: blend a b c K_n1(b - a) K_n2(a - c), n1 + n2 <= order -
// 3, by increasing n1 + n2 (the functions of a lower order come first, in the
// same positions), then increasing n2; return the number of functions
inline int h1Triangle(const Dual &a, const Dual &b, const Dual &c,
                      const Dual &blend, int order, Dual *f)
{
  Dual abc = blend * a * b * c;
  int n = 0;
  for(int d = 0; d <= order - 3; d++)
    for(int n2 = 0; n2 <= d; n2++)
      f[n++] = abc * kernel(d - n2, b - a) * kernel(n2, a - c);
  return n;
}

// The order of the i-th function of h1Triangle: d + 3 for the d (d + 1) / 2-th
// to the (d + 1) (d + 2) / 2 - 1-th functions
inline int triangleOrder(int i)
{
  int d = 0;
  while((d + 1) * (d + 2) / 2 <= i) d++;
  return d + 3;
}

// The coordinates (s, t) of a quadrilateral face of coordinates (s0, t0), in
// the orientation of the face given by the flags: flag1 and flag2 reverse s0
// and t0, flag3 = -1 exchanges them
inline void quadrangleCoordinates(const Dual &s0, const Dual &t0, int flag1,
                                  int flag2, int flag3, Dual &s, Dual &t)
{
  s = (flag3 == 1) ? flag1 * s0 : flag2 * t0;
  t = (flag3 == 1) ? flag2 * t0 : flag1 * s0;
}

// The H1 functions of a quadrilateral face of coordinates (s, t) in [-1, 1]^2,
// multiplied by blend: blend l_n1(s) l_n2(t), n1, n2 = 2, ..., order, where
// l_k are the Lobatto polynomials, by increasing max(n1, n2) (the functions of
// a lower order come first, in the same positions), then increasing n1 and
// n2; return the number of functions
inline int h1Quadrangle(const Dual &s, const Dual &t, const Dual &blend,
                        int order, Dual *f)
{
  int n = 0;
  for(int m = 2; m <= order; m++)
    for(int n1 = 2; n1 <= m; n1++)
      for(int n2 = 2; n2 <= m; n2++)
        if(std::max(n1, n2) == m)
          f[n++] = blend * lobatto(n1, s) * lobatto(n2, t);
  return n;
}

// The same with the kernel functions: blend K_n1(s) K_n2(t), n1, n2 = 0, ...,
// order - 2
inline int h1QuadrangleKernel(const Dual &s, const Dual &t, const Dual &blend,
                              int order, Dual *f)
{
  int n = 0;
  for(int m = 0; m <= order - 2; m++)
    for(int n1 = 0; n1 <= m; n1++)
      for(int n2 = 0; n2 <= m; n2++)
        if(std::max(n1, n2) == m)
          f[n++] = blend * kernel(n1, s) * kernel(n2, t);
  return n;
}

// The scaled Legendre polynomial t^n L_n(x / t), homogeneous of degree n in
// (x, t), by the recurrence k P_k = (2k - 1) x P_k-1 - (k - 1) t^2 P_k-2
inline Dual scaledLegendre(int n, const Dual &x, const Dual &t)
{
  Dual p0(1.), p1 = x, t2 = t * t;
  if(n == 0) return p0;
  for(int k = 2; k <= n; k++) {
    Dual p2 = ((2. * k - 1.) / k) * x * p1 - ((k - 1.) / k) * t2 * p0;
    p0 = p1;
    p1 = p2;
  }
  return p1;
}

// The Whitney function of the edge from vertex a to vertex b, of affine
// coordinates a and b: 2 (a grad(b) - b grad(a))
inline Vec whitney(const Dual &a, const Dual &b)
{ return 2. * (a * grad(b) - b * grad(a)); }

// The H(curl) functions of an edge: its lowest order function w, then the
// gradients of the H1 functions h of the edge of order + 1 (of orders 2 to
// order + 1); return the number of functions
inline int hcurlEdge(const Vec &w, const Dual *h, int order, Vec *f)
{
  f[0] = w;
  for(int k = 0; k < order; k++) f[k + 1] = grad(h[k]);
  return order + 1;
}
inline void hcurlEdgeInfo(int order, std::vector<FunctionInfo> &info)
{
  info.push_back({1, 0, false});
  for(int k = 1; k <= order; k++) info.push_back({1, k, true});
}

// The rotational H(curl) functions of a triangular face of affine coordinates
// (a, b, c), multiplied by blend, of orders l = 2, ..., order, with the
// polynomials u_i = a b P_i-2(b - a, a + b) and v_j = c P_j-1(c - a - b, a + b
// + c), P being the scaled Legendre polynomials, homogeneous of degrees i and
// j: for each l, v_l-1 times the Whitney function of (a, b), then j v_j
// grad(u_i) - i u_i grad(v_j), i = 2, ..., l, j = l + 1 - i. Their curls are
// linearly independent, and they belong to the Nedelec space of the first kind
// of order l, so that leaving out the gradients of order l gives that space.
// Return the number of functions.
inline int hcurlTriangleRotational(const Dual &a, const Dual &b, const Dual &c,
                                   const Dual &blend, int order, Vec *f)
{
  Dual s = a + b + c;
  int n = 0;
  for(int l = 2; l <= order; l++) {
    Dual v = c * scaledLegendre(l - 2, c - a - b, s);
    f[n++] = blend * v * whitney(a, b);
    for(int i = 2; i <= l; i++) {
      int j = l + 1 - i;
      Dual u = a * b * scaledLegendre(i - 2, b - a, a + b);
      Dual vj = c * scaledLegendre(j - 1, c - a - b, s);
      f[n++] = blend * (double(j) * vj * grad(u) - double(i) * u * grad(vj));
    }
  }
  return n;
}

// The H(curl) functions of a triangular face: by increasing order l = 2, ...,
// order, the gradients of the H1 functions h of the face of order l + 1 (see
// h1Triangle), then its rotational functions of order l (see
// hcurlTriangleRotational); return the number of functions
inline int hcurlTriangle(const Dual &a, const Dual &b, const Dual &c,
                         const Dual &blend, const Dual *h, int order, Vec *f)
{
  std::vector<Vec> r(order * order);
  hcurlTriangleRotational(a, b, c, blend, order, r.data());
  int n = 0, nr = 0;
  for(int l = 2; l <= order; l++) {
    for(int k = (l - 2) * (l - 1) / 2; k < (l - 1) * l / 2; k++)
      f[n++] = grad(h[k]);
    for(int k = 0; k < l; k++) f[n++] = r[nr++];
  }
  return n;
}
inline void hcurlTriangleInfo(int order, std::vector<FunctionInfo> &info)
{
  for(int l = 2; l <= order; l++) {
    for(int k = 0; k < l - 1; k++) info.push_back({2, l, true});
    for(int k = 0; k < l; k++) info.push_back({2, l, false});
  }
}

// The rotational H(curl) functions of a quadrilateral face of coordinates (s,
// t) in [-1, 1]^2, multiplied by blend, of orders l = 1, ..., order, with m =
// l + 1 and the Lobatto polynomials l_k: l_m(t) grad(s), l_m(s) grad(t), then
// grad(l_i(s)) l_j(t) - l_i(s) grad(l_j(t)) for (i, j) in [2, m]^2 with
// max(i, j) = m, by increasing i, then j; return the number of functions
inline int hcurlQuadrangleRotational(const Dual &s, const Dual &t,
                                     const Dual &blend, int order, Vec *f)
{
  int n = 0;
  for(int m = 2; m <= order + 1; m++) {
    f[n++] = blend * lobatto(m, t) * grad(s);
    f[n++] = blend * lobatto(m, s) * grad(t);
    for(int i = 2; i <= m; i++)
      for(int j = 2; j <= m; j++)
        if(std::max(i, j) == m) {
          Dual li = lobatto(i, s), lj = lobatto(j, t);
          f[n++] = blend * (lj * grad(li) - li * grad(lj));
        }
  }
  return n;
}

// The H(curl) functions of a quadrilateral face: by increasing order l = 1,
// ..., order, the gradients of the H1 functions h of the face of order l + 1
// (see h1Quadrangle), then its rotational functions of order l (see
// hcurlQuadrangleRotational); return the number of functions
inline int hcurlQuadrangle(const Dual &s, const Dual &t, const Dual &blend,
                           const Dual *h, int order, Vec *f)
{
  std::vector<Vec> r((order + 1) * (order + 1));
  hcurlQuadrangleRotational(s, t, blend, order, r.data());
  int n = 0, nr = 0;
  for(int l = 1; l <= order; l++) {
    for(int k = (l - 1) * (l - 1); k < l * l; k++) f[n++] = grad(h[k]);
    for(int k = 0; k < 2 * l + 1; k++) f[n++] = r[nr++];
  }
  return n;
}
inline void hcurlQuadrangleInfo(int order, std::vector<FunctionInfo> &info)
{
  for(int l = 1; l <= order; l++) {
    for(int k = 0; k < 2 * l - 1; k++) info.push_back({2, l, true});
    for(int k = 0; k < 2 * l + 1; k++) info.push_back({2, l, false});
  }
}

// The curl of an H(curl) function, as a vector field without derivatives: its
// divergence is then zero, which is exact
inline Vec curlVec(const Vec &v)
{ return Vec(Dual(v.curl(0)), Dual(v.curl(1)), Dual(v.curl(2))); }

// The Whitney 2-form of the triangular face (a, b, c): 2 (a grad(b) x grad(c) +
// b grad(c) x grad(a) + c grad(a) x grad(b)), whose normal component is
// constant on the face and zero on the other faces
inline Vec whitney2(const Dual &a, const Dual &b, const Dual &c)
{
  return 2. * (a * cross(grad(b), grad(c)) + b * cross(grad(c), grad(a)) +
               c * cross(grad(a), grad(b)));
}

#endif
