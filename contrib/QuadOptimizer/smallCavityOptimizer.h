// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.

#pragma once

#include "GmshGlobal.h"
#include "quadQuality.h"
#include "smallCavityWinslow.h"

#include <cstddef>
#include <vector>

class GFace;

namespace QuadOptimizer {

  struct SmallCavityOptimizerOptions {
    bool optimizeOneInteriorVertexCavities = true;
    bool optimizeThreeInteriorVertexCavities = true;
    bool optimizeFourInteriorVertexCavities = true;
    bool eliminateDiamonds = true;
    bool splitValenceSixVertices = true;
    bool convertBoundaryTriangleQuadTriangleFans = true;
    // Kinney CleanUp stages. The implementation detects generic cavities
    // around the configurations described in the paper and enumerates all
    // stored disk quadrangulations instead of relying on the unpublished
    // table of 64 proprietary valence patterns.
    bool cleanUpConnectivity = true;
    bool cleanUpBoundary = true;
    bool cleanUpShape = true;
    bool cleanUpSize = true;
    // Experimental paper-style path used by OptimizeQuadsFast. It keeps the
    // exhaustive API unchanged while using constant-size local decisions,
    // harmonic candidate placement and local Winslow relaxation after every
    // accepted edit.
    bool fastInteractiveCleanUp = false;
    bool topologyOnlyIfCavityHasSpecificationFailure = true;
    // Optional post-processing: insert one infinitesimal quad ring around
    // every hole, then open it with the local Winslow solver. Zero disables
    // the operator; a positive value selects the number of optimized rows.
    int pillowNeighborLayers = 0;
    int smoothingPasses = 2;
    int finalSmoothingPasses = 2;
    int postTopologyNeighborSmoothingPasses = 2;
    int maximumOptimizationPasses = 3;
    int maximumAcceptedCavities = 100;
    int maximumTopologyCandidatesPerCavity = 24;
    // Connectivity candidates are screened with a short Winslow solve; only
    // the best shortlist receives the fully converged solve.
    int maximumCleanUpCandidatesPerCavity = 128;
    int maximumCleanUpWinslowCandidatesPerCavity = 12;
    int maximumCleanUpCavityRings = 2;
    int maximumCleanUpCavityElements = 12;
    int maximumCleanUpInteriorVertices = 4;
    double cleanUpLongEdgeRatio = 2.5;

    // Optional size-map filter. It is disabled by default: cavity boundaries
    // are fixed, so size variations remain local.
    bool enforceSizeMap = false;
    // Positive: constant target size. Non-positive: query BGM_MeshSize.
    double targetSize = -1.;
    double minimumEdgeSizeRatio = .35;
    double maximumEdgeSizeRatio = 2.5;
    bool enforceRelativeSizeErrorIncrease = false;
    double maximumRelativeSizeErrorIncrease = .02;
    double objectiveRelativeTolerance = 1.e-12;

    SmallCavityWinslowOptions winslow;
    bool invalidateVertexArrays = true;
    int verbose = 0;
  };

  struct SmallCavityOptimizerResult {
    bool success = true;
    std::size_t passes = 0;
    std::size_t cavitiesVisited = 0;
    std::size_t topologyCandidatesOptimized = 0;
    std::size_t rejectedByWinslow = 0;
    std::size_t rejectedBySize = 0;
    std::size_t rejectedByQuality = 0;
    std::size_t skippedSpecificationCompliant = 0;
    std::size_t diamondsVisited = 0;
    std::size_t acceptedDiamonds = 0;
    std::size_t valenceSixVerticesVisited = 0;
    std::size_t acceptedValenceSixSplits = 0;
    std::size_t boundaryTriangleQuadTriangleFansVisited = 0;
    std::size_t acceptedBoundaryTriangleQuadTriangleFans = 0;
    std::size_t acceptedFinalSmoothingCavities = 0;
    std::size_t acceptedEdgeSwaps = 0;
    std::size_t rejectedEdgeSwapsNoIntersection = 0;
    std::size_t rejectedEdgeSwapsNonConvex = 0;
    std::size_t acceptedOneInteriorVertexCavities = 0;
    std::size_t acceptedThreeInteriorVertexCavities = 0;
    std::size_t acceptedFourInteriorVertexCavities = 0;
    std::size_t cleanUpCavitiesVisited = 0;
    std::size_t cleanUpConnectivityAccepted = 0;
    std::size_t cleanUpBoundaryAccepted = 0;
    std::size_t cleanUpShapeAccepted = 0;
    std::size_t cleanUpSizeAccepted = 0;
    std::size_t pillowHolesVisited = 0;
    std::size_t pillowHolesAccepted = 0;
    std::size_t pillowQuadranglesInserted = 0;
    double cleanUpCriticalSeconds = 0.;
    double cleanUpConnectivitySeconds = 0.;
    double cleanUpBoundarySeconds = 0.;
    double cleanUpShapeSeconds = 0.;
    double cleanUpSizeSeconds = 0.;
    SpecificationObjective initialObjective;
    SpecificationObjective finalObjective;
  };

  struct ExistingTopologyWinslowResult {
    bool success = true;
    std::size_t passes = 0;
    std::size_t quadsVisited = 0;
    std::size_t admissibleCavities = 0;
    std::size_t cavitiesOptimized = 0;
    std::size_t acceptedCavities = 0;
    std::size_t rejectedByWinslow = 0;
    std::size_t rejectedBySize = 0;
    std::size_t rejectedByQuality = 0;
    std::size_t skippedSpecificationCompliant = 0;
    SpecificationObjective initialObjective;
    SpecificationObjective finalObjective;
  };

  struct FaceOptimizerResult {
    int faceTag = -1;
    SmallCavityOptimizerResult optimizer;
  };

  struct AllFacesOptimizerResult {
    bool success = true;
    std::size_t facesVisited = 0;
    std::size_t facesWithQuadrangles = 0;
    std::size_t acceptedCavities = 0;
    std::size_t acceptedPillows = 0;
    std::size_t insertedPillowQuadrangles = 0;
    SpecificationObjective initialObjective;
    SpecificationObjective finalObjective;
    std::vector<FaceOptimizerResult> faces;
  };

  // Maintain a half-edge index of the manifold face, rank local cavities, try
  // the best disk-quadrangulation patterns and execute improving mesh diffs in
  // vertex-disjoint waves. Boundary vertices are never moved.
  GMSH_API SmallCavityOptimizerResult optimizeSmallQuadCavities(
    GFace *face,
    const SmallCavityOptimizerOptions &options = SmallCavityOptimizerOptions());

  GMSH_API SmallCavityOptimizerResult optimizeSmallQuadCavities(
    int faceTag,
    const SmallCavityOptimizerOptions &options = SmallCavityOptimizerOptions());

  // Visit every quadrangle whose four vertices are interior to the face. The
  // union of the four vertex stars defines the cavity. Its existing
  // connectivity and boundary are kept unchanged; only the four interior
  // vertices are optimized with the Winslow functional in parameter space.
  GMSH_API ExistingTopologyWinslowResult smoothExistingQuadCavities(
    GFace *face,
    const SmallCavityOptimizerOptions &options = SmallCavityOptimizerOptions());

  GMSH_API ExistingTopologyWinslowResult smoothExistingQuadCavities(
    int faceTag,
    const SmallCavityOptimizerOptions &options = SmallCavityOptimizerOptions());

  // Optimize every face containing quadrangles. Faces are independent and
  // processed in parallel; model-wide vertex caches are invalidated once.
  GMSH_API AllFacesOptimizerResult optimizeSmallQuadCavitiesAllFaces(
    const SmallCavityOptimizerOptions &options = SmallCavityOptimizerOptions(),
    int maximumThreads = 0);

} // namespace QuadOptimizer
