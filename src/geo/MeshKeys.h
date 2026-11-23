// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESH_KEYS_H
#define MESH_KEYS_H

#include <algorithm>
#include <array>
#include <cstdint>
#include "GmshDefines.h"
#include "Hash.h"

class MVertex;

// Keys of hash tables of mesh edges and faces by their node pointers, which
// are not dereferenced (unlike MEdge and MFace, which compare the node
// numbers), and the edges and faces of the first-order element types in the
// Gmsh node ordering (see Plugin(NonConformalRefinement), Plugin(DualMesh) and
// meshCombine3D.cpp)
namespace meshKeys {

  struct EdgeKey {
    MVertex *a, *b;
    EdgeKey(MVertex *x, MVertex *y) : a(x), b(y)
    {
      if(a > b) std::swap(a, b);
    }
    bool operator==(const EdgeKey &o) const { return a == o.a && b == o.b; }
  };

  struct EdgeHash {
    std::size_t operator()(const EdgeKey &k) const
    {
      return HashCombine(HashMix((std::uintptr_t)k.a), (std::uintptr_t)k.b);
    }
  };

  // a triangle or a quadrangle, by its sorted corners (the 4th null for a
  // triangle)
  struct FaceKey {
    std::array<MVertex *, 4> v;
    FaceKey() : v{nullptr, nullptr, nullptr, nullptr} {}
    FaceKey(MVertex *const *f, int n)
    {
      v = {f[0], f[1], f[2], n == 4 ? f[3] : nullptr};
      std::sort(v.begin(), v.begin() + n);
    }
    bool operator==(const FaceKey &o) const { return v == o.v; }
  };

  struct FaceHash {
    std::size_t operator()(const FaceKey &k) const
    {
      std::uint64_t h = HashMix((std::uintptr_t)k.v[0]);
      for(int i = 1; i < 4; i++) h = HashCombine(h, (std::uintptr_t)k.v[i]);
      return h;
    }
  };

  // the edges and the faces of an element type (in 2D, the face is the
  // element itself)
  struct Shape {
    int numCorners, numEdges, edges[12][2], numFaces, faceSize[6], faces[6][4];
  };

  // that of the type (TYPE_TRI...), null for another one
  inline const Shape *shape(int type)
  {
    static const Shape tri = {3, 3, {{0, 1}, {1, 2}, {2, 0}}, 1, {3},
                              {{0, 1, 2}}};
    static const Shape qua = {4, 4, {{0, 1}, {1, 2}, {2, 3}, {3, 0}}, 1, {4},
                              {{0, 1, 2, 3}}};
    static const Shape tet = {4,
                              6,
                              {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}, {2, 3}},
                              4,
                              {3, 3, 3, 3},
                              {{0, 2, 1}, {0, 1, 3}, {0, 3, 2}, {3, 1, 2}}};
    static const Shape hex = {8,
                              12,
                              {{0, 1},
                               {0, 3},
                               {0, 4},
                               {1, 2},
                               {1, 5},
                               {2, 3},
                               {2, 6},
                               {3, 7},
                               {4, 5},
                               {4, 7},
                               {5, 6},
                               {6, 7}},
                              6,
                              {4, 4, 4, 4, 4, 4},
                              {{0, 3, 2, 1},
                               {0, 1, 5, 4},
                               {0, 4, 7, 3},
                               {1, 2, 6, 5},
                               {2, 3, 7, 6},
                               {4, 5, 6, 7}}};
    static const Shape pri = {
      6,
      9,
      {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 4}, {2, 5}, {3, 4}, {3, 5}, {4, 5}},
      5,
      {3, 3, 4, 4, 4},
      {{0, 2, 1}, {3, 4, 5}, {0, 1, 4, 3}, {0, 3, 5, 2}, {1, 2, 5, 4}}};
    static const Shape pyr = {
      5,
      8,
      {{0, 1}, {0, 3}, {0, 4}, {1, 2}, {1, 4}, {2, 3}, {2, 4}, {3, 4}},
      5,
      {4, 3, 3, 3, 3},
      {{0, 3, 2, 1}, {0, 1, 4}, {3, 0, 4}, {1, 2, 4}, {2, 3, 4}}};
    switch(type) {
    case TYPE_TRI: return &tri;
    case TYPE_QUA: return &qua;
    case TYPE_TET: return &tet;
    case TYPE_HEX: return &hex;
    case TYPE_PRI: return &pri;
    case TYPE_PYR: return &pyr;
    default: return nullptr;
    }
  }

} // namespace meshKeys

#endif
