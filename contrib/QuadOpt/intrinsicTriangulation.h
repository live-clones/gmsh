// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.

#ifndef QUAD_OPT_INTRINSIC_TRIANGULATION_H
#define QUAD_OPT_INTRINSIC_TRIANGULATION_H
#include <cstddef>
#include <vector>
class GFace;
class MTriangle;
struct bidimMeshData;
namespace QuadOpt {
  // Called on the packed triangles, before Blossom constructs quadrangles.
  std::size_t intrinsicDelaunayizePackedSurface(GFace *, bidimMeshData &);
  void printTrianglesXYZ(const char *, const std::vector<MTriangle *> &);
} // namespace QuadOpt
#endif
