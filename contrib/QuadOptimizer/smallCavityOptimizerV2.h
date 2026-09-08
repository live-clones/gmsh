// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.

#pragma once

#include "smallCavityOptimizer.h"

class GFace;

namespace QuadOptimizer {

  // Compact optimizer used by OptimizeQuadsFast. It owns one persistent
  // FaceHalfEdge per GFace, evaluates only the modified cavity C, applies the
  // monotone CleanUp rules first, then quality-improving QQ/QT/TT swaps, and
  // optionally smooths between rounds. In the staged schedule, nodal
  // smoothing follows the last topology/context revisit on all regular faces.
  // Smart Laplacian can be followed by pure mean-plane 3D Winslow sweeps;
  // both phases are independent of topology budgets and preserve connectivity.
  GMSH_API SmallCavityOptimizerResult optimizeSmallQuadCavitiesV2(
    GFace *face,
    const SmallCavityOptimizerOptions &options = SmallCavityOptimizerOptions());

  GMSH_API SmallCavityOptimizerResult optimizeSmallQuadCavitiesV2(
    int faceTag,
    const SmallCavityOptimizerOptions &options = SmallCavityOptimizerOptions());

  GMSH_API AllFacesOptimizerResult optimizeSmallQuadCavitiesAllFacesV2(
    const SmallCavityOptimizerOptions &options = SmallCavityOptimizerOptions());

} // namespace QuadOptimizer
