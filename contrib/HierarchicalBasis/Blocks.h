// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef BLOCKS_H
#define BLOCKS_H

#include <vector>
#include "Dual.h"

// Building blocks shared by the hierarchical bases of several elements.

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

// The H1 functions of a triangular face of affine coordinates (a, b, c): a b c
// K_n1(b - a) K_n2(a - c), n1 + n2 <= order - 3; return the number of
// functions
inline int h1Triangle(const Dual &a, const Dual &b, const Dual &c, int order,
                      Dual *f)
{
  Dual abc = a * b * c;
  int n = 0;
  for(int n1 = 0; n1 <= order - 3; n1++) {
    Dual k1 = kernel(n1, b - a);
    for(int n2 = 0; n2 <= order - 3 - n1; n2++)
      f[n++] = abc * k1 * kernel(n2, a - c);
  }
  return n;
}

#endif
