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
  // Edges longer than edgeLengthFactor times the local size are split (zero:
  // never).
  std::size_t intrinsicDelaunayizePackedSurface(GFace *, bidimMeshData &,
                                                double edgeLengthFactor);
} // namespace QuadOpt
#endif
