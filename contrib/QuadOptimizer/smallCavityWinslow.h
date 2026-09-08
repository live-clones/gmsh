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
    // Dimensionless area regularization. Before solving, the whole UV patch
    // is translated and uniformly scaled so its oriented area is
    // #quadrangles + 0.5 * #triangles. True triangle references are equilateral
    // with area 0.5; the four corner references of each quad remain those of
    // a unit square. A zero-area starting patch uses its isotropic extent.
    double lambda = 1. / 127.;
    int maxInnerIterations = 200;
    int maxOuterIterations = 8;
    int maxLineSearchSteps = 80;
    // Tolerances apply to the normalized coordinates and dimensionless energy,
    // not the original CAD parameter units. No independent U/V scaling occurs.
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
    // Energy and Jacobian are measured in the normalized solve coordinates.
    // Uniform scaling or translation of a patch does not change their units.
    double initialEnergy = 0.;
    double finalEnergy = 0.;
    double minimumJacobian = 0.;
  };

  // Linear-time initializer for interactive CleanUp. The boundary stays fixed
  // exactly and the function rejects folded parametric quadrangles. Failed
  // initialization leaves every input point unchanged.
  GMSH_API bool initializeSmallQuadCavityHarmonic(
    std::vector<std::array<double, 2> > &parametricPoints,
    std::size_t boundaryVertexCount,
    const std::vector<std::array<std::size_t, 4> > &quadrangles);

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

  // Dimensionless physical-chart energy, including area regularization.
  // Used to check the actual reprojected nodal displacement, not just the
  // unprojected numerical proposal.
  GMSH_API double evaluateLocalSurfacePatchWinslowEnergy(
    const std::vector<std::array<double, 2> > &points,
    const std::vector<std::array<std::size_t, 3> > &triangles,
    const std::vector<std::array<std::size_t, 4> > &quadrangles,
    double orientationSign, double lambda);

  // Optimize an arbitrary local mixed triangle/quad patch. ``fixed`` marks
  // vertices that must remain unchanged; every other point is a Winslow
  // unknown. The explicit orientation is the sign (+1 or -1) of coherently
  // oriented surface elements in parameter space. This is used by annular
  // patches, for which the fixed vertices do not form one disk boundary.
  // Fixed coordinates are preserved bitwise. All movable coordinates are
  // mapped back with the same scalar normalization used for the entire patch.
  GMSH_API SmallCavityWinslowResult optimizeLocalSurfacePatchWinslow(
    std::vector<std::array<double, 2> > &parametricPoints,
    const std::vector<bool> &fixed,
    const std::vector<std::array<std::size_t, 3> > &triangles,
    const std::vector<std::array<std::size_t, 4> > &quadrangles,
    double orientationSign,
    const SmallCavityWinslowOptions &options = SmallCavityWinslowOptions());

} // namespace QuadOptimizer
