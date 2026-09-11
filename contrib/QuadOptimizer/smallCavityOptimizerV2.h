// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.

#pragma once

#include "smallCavityOptimizer.h"

class GFace;

namespace QuadOptimizer {

  // Persistent local rewrite queues and active nodal smoothing. A round
  // without topology changes ends the alternating loop; bounded global
  // mean-plane Winslow sweeps and the final physical/quality/CAD quad split
  // follow. Admissible TT merges and CAD-edge swaps close the result, with
  // quads preferred and no further smoothing.
  GMSH_API SmallCavityOptimizerResult optimizeSmallQuadCavitiesV2(
    GFace *face,
    const SmallCavityOptimizerOptions &options = SmallCavityOptimizerOptions());

  GMSH_API SmallCavityOptimizerResult optimizeSmallQuadCavitiesV2(
    int faceTag,
    const SmallCavityOptimizerOptions &options = SmallCavityOptimizerOptions());

  GMSH_API AllFacesOptimizerResult optimizeSmallQuadCavitiesAllFacesV2(
    const SmallCavityOptimizerOptions &options = SmallCavityOptimizerOptions());

} // namespace QuadOptimizer
