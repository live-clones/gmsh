// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.

#pragma once

#include "GmshGlobal.h"

#include <array>
#include <cstddef>
#include <vector>

namespace QuadOptimizer {

  struct SmallCavityWinslowOptions {
    double lambda = 1. / 127.;
    int maxInnerIterations = 200;
    int maxOuterIterations = 8;
    int maxLineSearchSteps = 80;
    double gradientTolerance = 1.e-8;
    double functionTolerance = 1.e-12;
    double stepTolerance = 1.e-12;
    bool harmonicInitialization = true;
    int verbose = 0;
  };

  struct SmallCavityWinslowResult {
    bool success = false;
    bool untangled = false;
    int outerIterations = 0;
    int lbfgsIterations = 0;
    int functionEvaluations = 0;
    double initialEnergy = 0.;
    double finalEnergy = 0.;
    double minimumJacobian = 0.;
  };

  // Optimize a quadrangulated topological disk in a two-dimensional surface
  // parameterization. Vertices [0, boundaryVertexCount) are fixed. Only the
  // 2 coordinates of the remaining (small number of) interior vertices are
  // passed to GmshLBFGS. Quads must be coherently oriented and reference the
  // boundary first, followed by the interior vertices.
  GMSH_API SmallCavityWinslowResult optimizeSmallQuadCavityWinslow(
    std::vector<std::array<double, 2> > &parametricPoints,
    std::size_t boundaryVertexCount,
    const std::vector<std::array<std::size_t, 4> > &quadrangles,
    const SmallCavityWinslowOptions &options = SmallCavityWinslowOptions());

} // namespace QuadOptimizer
