// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef BLOCKS_H
#define BLOCKS_H

#include <vector>
#include "Dual.h"

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
// 3; return the number of functions
inline int h1Triangle(const Dual &a, const Dual &b, const Dual &c,
                      const Dual &blend, int order, Dual *f)
{
  Dual abc = blend * a * b * c;
  int n = 0;
  for(int n1 = 0; n1 <= order - 3; n1++) {
    Dual k1 = kernel(n1, b - a);
    for(int n2 = 0; n2 <= order - 3 - n1; n2++)
      f[n++] = abc * k1 * kernel(n2, a - c);
  }
  return n;
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
// l_k are the Lobatto polynomials; return the number of functions
inline int h1Quadrangle(const Dual &s, const Dual &t, const Dual &blend,
                        int order, Dual *f)
{
  int n = 0;
  for(int n1 = 2; n1 <= order; n1++) {
    Dual b1 = blend * lobatto(n1, s);
    for(int n2 = 2; n2 <= order; n2++) f[n++] = b1 * lobatto(n2, t);
  }
  return n;
}

// The same with the kernel functions: blend K_n1(s) K_n2(t), n1, n2 = 0, ...,
// order - 2
inline int h1QuadrangleKernel(const Dual &s, const Dual &t, const Dual &blend,
                              int order, Dual *f)
{
  int n = 0;
  for(int n1 = 0; n1 <= order - 2; n1++) {
    Dual b1 = blend * kernel(n1, s);
    for(int n2 = 0; n2 <= order - 2; n2++) f[n++] = b1 * kernel(n2, t);
  }
  return n;
}

// The H(curl) functions of an edge from vertex a to vertex b, of affine
// coordinates a and b: the Whitney function 2 (a grad(b) - b grad(a)), the
// function -2 grad(a b), and their Legendre extensions to the degrees k = 2,
// ..., order, ((2k - 1) / k) L_k-1(b - a) f1 - ((k - 1) / k) L_k-2(b - a) f0;
// return the number of functions
inline int hcurlEdge(const Dual &a, const Dual &b, int order, Vec *f)
{
  Vec f0 = 2. * (a * grad(b) - b * grad(a));
  Vec f1 = -2. * (b * grad(a) + a * grad(b));
  f[0] = f0;
  if(order >= 1) f[1] = f1;
  for(int k = 2; k <= order; k++)
    f[k] = ((2. * k - 1.) / k) * legendre(k - 1, b - a) * f1 -
           ((k - 1.) / k) * legendre(k - 2, b - a) * f0;
  return order + 1;
}

// The H(curl) functions of a triangular face of affine coordinates (a, b, c):
// - for each edge (x, y) = (a, b), (b, c), (c, a) of the face, opposite to the
//   vertex z: x y L_n(y - x) grad(z), n = 0, ..., order - 2;
// - a b c L_n1(b - a) L_n2(a - c) grad(b), then the same with grad(c),
//   n1 + n2 <= order - 3;
// where L_k are the Legendre polynomials; return the number of functions
inline int hcurlTriangle(const Dual &a, const Dual &b, const Dual &c, int order,
                         Vec *f)
{
  const Dual *x[3] = {&a, &b, &c};
  int n = 0;
  for(int e = 0; e < 3; e++) {
    const Dual &p = *x[e], &q = *x[(e + 1) % 3], &r = *x[(e + 2) % 3];
    for(int k = 0; k <= order - 2; k++)
      f[n++] = p * q * legendre(k, q - p) * grad(r);
  }
  Dual abc = a * b * c;
  for(int g = 0; g < 2; g++) {
    Vec dir = grad(g == 0 ? b : c);
    for(int n1 = 0; n1 <= order - 3; n1++)
      for(int n2 = 0; n2 <= order - 3 - n1; n2++)
        f[n++] = abc * legendre(n1, b - a) * legendre(n2, a - c) * dir;
  }
  return n;
}

// The H(curl) functions of an edge of a tensor product element, along the
// coordinate s in [-1, 1], multiplied by blend: blend L_k(s) grad(s), k = 0,
// ..., order; return the number of functions
inline int hcurlTensorEdge(const Dual &s, const Dual &blend, int order, Vec *f)
{
  for(int k = 0; k <= order; k++) f[k] = blend * legendre(k, s) * grad(s);
  return order + 1;
}

// The H(curl) functions of a quadrilateral face of coordinates (s, t) in
// [-1, 1]^2, multiplied by blend: blend L_n1(s) l_n2(t) grad(s), n1 = 0, ...,
// order, n2 = 2, ..., order + 1, then blend l_n1(s) L_n2(t) grad(t), n1 = 2,
// ..., order + 1, n2 = 0, ..., order; return the number of functions
inline int hcurlQuadrangle(const Dual &s, const Dual &t, const Dual &blend,
                           int order, Vec *f)
{
  int n = 0;
  for(int n1 = 0; n1 <= order; n1++)
    for(int n2 = 2; n2 <= order + 1; n2++)
      f[n++] = blend * legendre(n1, s) * lobatto(n2, t) * grad(s);
  for(int n1 = 2; n1 <= order + 1; n1++)
    for(int n2 = 0; n2 <= order; n2++)
      f[n++] = blend * lobatto(n1, s) * legendre(n2, t) * grad(t);
  return n;
}

#endif
