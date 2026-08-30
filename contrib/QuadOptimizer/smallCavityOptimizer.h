// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.

#pragma once

#include "GmshGlobal.h"
#include "quadQuality.h"
#include "smallCavityWinslow.h"

#include <cstddef>
#include <functional>
#include <limits>
#include <vector>

class GFace;
class GModel;

namespace QuadOptimizer {

  // Physical edge-length requirements at one point of a face. Keeping the
  // target separate from the hard bounds lets callers express e.g. the
  // constant {target, minimum, maximum} triplets {10, 2, 20}, {6, 2, 12}
  // and {4, 2, 8}, as well as spatially varying requirements later on.
  struct EdgeLengthCriteria {
    double target = -1.;
    double minimum = 0.;
    double maximum = std::numeric_limits<double>::infinity();
  };

  using EdgeLengthCriteriaAt = std::function<EdgeLengthCriteria(
    GFace *, double, double, double, double, double)>;

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
    // Full Kinney CleanUp path: connectivity, boundary, shape and size
    // cleanup (including the specialized simple cavities), with guarded local
    // smoothing after every accepted action, until a complete sweep is idle.
    // If pillowNeighborLayers is positive, admissible hole pillowing is
    // included in the same smoothed, validated fixed-point transaction.
    bool quadCleanUp = false;
    // Experimental paper-style path used by OptimizeQuadsFast. It keeps the
    // exhaustive API unchanged while using constant-size local decisions,
    // harmonic candidate placement and local Winslow relaxation after every
    // accepted edit.
    bool fastInteractiveCleanUp = false;
    bool topologyOnlyIfCavityHasSpecificationFailure = true;
    // Optional post-processing: attempt to establish one complete quad ring
    // around every hole, opening a newly inserted infinitesimal ring with
    // local Winslow when all quality and size gates accept it. Zero disables
    // the operator. One optimizes the complete affected vertex stars; larger
    // values add neighboring element layers to that patch.
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
    // Read the active target field for the final report without turning its
    // values into hard optimization bounds. This is used by PACK when a
    // spatially varying guiding field is active.
    bool auditSizeMap = false;
    // If set, this callback supplies the complete physical specification and
    // takes precedence over the scalar settings below. It must be thread-safe
    // when optimizeSmallQuadCavitiesAllFaces() is used.
    EdgeLengthCriteriaAt edgeLengthCriteriaAt;
    // Positive: constant target size. Non-positive: use the active Quadqs
    // vector field when enforcing constraints, then fall back to BGM_MeshSize.
    double targetSize = -1.;
    // Absolute physical bounds; non-positive values disable the corresponding
    // bound. Active absolute and relative bounds are intersected.
    double minimumEdgeLength = 0.;
    double maximumEdgeLength = 0.;
    double minimumEdgeSizeRatio = .35;
    double maximumEdgeSizeRatio = 2.5;
    bool enforceRelativeSizeErrorIncrease = false;
    double maximumRelativeSizeErrorIncrease = .02;
    double objectiveRelativeTolerance = 1.e-12;
    // A terminal T+T -> Q merge must not recreate a quadrangle that the
    // caller's optional eta-quality filter would immediately split again.
    double minimumRecombinationQuality = 0.;

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
    // Accepted topology transactions, classified by the first branch of the
    // QuadCleanUp decision path that justified them.
    std::size_t acceptedFewerUnacceptableElements = 0;
    std::size_t acceptedBetterGeometry = 0;
    std::size_t acceptedOtherImprovements = 0;
    // Subset of acceptedEdgeSwaps found by the generic CleanUp cavity stage;
    // these are already included in one of the four CleanUp family counters.
    std::size_t acceptedCleanUpEdgeSwaps = 0;
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
    // Per-round attempts; a successful hole is visited again to confirm the
    // composed pillow/CleanUp fixed point.
    std::size_t pillowHolesVisited = 0;
    std::size_t pillowHolesAlreadyPresent = 0;
    std::size_t pillowHolesAccepted = 0;
    std::size_t pillowQuadranglesInserted = 0;
    std::size_t excessiveWarpingQuadrangles = 0;
    std::size_t nonConvexOrInvalidQuadrangles = 0;
    std::size_t warpedQuadranglesSplit = 0;
    std::size_t warpedQuadranglesRejected = 0;
    std::size_t terminalTrianglePairsVisited = 0;
    std::size_t terminalTrianglePairsAccepted = 0;
    std::size_t terminalTrianglePairsRejectedInvalid = 0;
    std::size_t terminalTrianglePairsRejectedTopology = 0;
    std::size_t terminalTrianglePairsRejectedQuality = 0;
    std::size_t terminalTrianglePairsRejectedSize = 0;
    std::size_t terminalTrianglePairsRejectedGeometry = 0;
    double cleanUpCriticalSeconds = 0.;
    double cleanUpConnectivitySeconds = 0.;
    double cleanUpBoundarySeconds = 0.;
    double cleanUpShapeSeconds = 0.;
    double cleanUpSizeSeconds = 0.;
    bool sizeRequirementsMet = true;
    std::size_t initialEdgesBelowMinimum = 0;
    std::size_t initialEdgesAboveMaximum = 0;
    std::size_t initialInvalidSizeEdges = 0;
    std::size_t finalEdgesBelowMinimum = 0;
    std::size_t finalEdgesAboveMaximum = 0;
    std::size_t finalInvalidSizeEdges = 0;
    double initialMinimumEdgeLength =
      std::numeric_limits<double>::infinity();
    double initialMaximumEdgeLength = 0.;
    double finalMinimumEdgeLength =
      std::numeric_limits<double>::infinity();
    double finalMaximumEdgeLength = 0.;
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

  struct TerminalTriangleRecombinationResult {
    bool success = true;
    std::size_t pairsVisited = 0;
    std::size_t accepted = 0;
    std::size_t rejectedInvalid = 0;
    std::size_t rejectedTopology = 0;
    std::size_t rejectedQuality = 0;
    std::size_t rejectedSize = 0;
    std::size_t rejectedGeometry = 0;
  };

  struct AllFacesOptimizerResult {
    bool success = true;
    std::size_t facesVisited = 0;
    std::size_t facesWithQuadrangles = 0;
    std::size_t acceptedCavities = 0;
    std::size_t acceptedEdgeSwaps = 0;
    std::size_t acceptedDiamonds = 0;
    std::size_t acceptedSmoothingCavities = 0;
    std::size_t acceptedFewerUnacceptableElements = 0;
    std::size_t acceptedBetterGeometry = 0;
    std::size_t acceptedOtherImprovements = 0;
    std::size_t rejectedByWinslow = 0;
    std::size_t rejectedBySize = 0;
    std::size_t rejectedByQuality = 0;
    std::size_t pillowHolesVisited = 0;
    std::size_t pillowHolesAlreadyPresent = 0;
    std::size_t acceptedPillows = 0;
    std::size_t insertedPillowQuadrangles = 0;
    std::size_t excessiveWarpingQuadrangles = 0;
    std::size_t nonConvexOrInvalidQuadrangles = 0;
    std::size_t warpedQuadranglesSplit = 0;
    std::size_t warpedQuadranglesRejected = 0;
    std::size_t terminalTrianglePairsVisited = 0;
    std::size_t terminalTrianglePairsAccepted = 0;
    std::size_t terminalTrianglePairsRejectedInvalid = 0;
    std::size_t terminalTrianglePairsRejectedTopology = 0;
    std::size_t terminalTrianglePairsRejectedQuality = 0;
    std::size_t terminalTrianglePairsRejectedSize = 0;
    std::size_t terminalTrianglePairsRejectedGeometry = 0;
    bool sizeRequirementsMet = true;
    std::size_t initialEdgesBelowMinimum = 0;
    std::size_t initialEdgesAboveMaximum = 0;
    std::size_t initialInvalidSizeEdges = 0;
    std::size_t finalEdgesBelowMinimum = 0;
    std::size_t finalEdgesAboveMaximum = 0;
    std::size_t finalInvalidSizeEdges = 0;
    double initialMinimumEdgeLength =
      std::numeric_limits<double>::infinity();
    double initialMaximumEdgeLength = 0.;
    double finalMinimumEdgeLength =
      std::numeric_limits<double>::infinity();
    double finalMaximumEdgeLength = 0.;
    SpecificationObjective initialObjective;
    SpecificationObjective finalObjective;
    std::vector<FaceOptimizerResult> faces;
  };

  // Read-only, model-wide audit of the final linear triangle/quad surface
  // mesh. Averages are weighted by elements (shape) or sampled physical area
  // (CAD distance), never averaged face by face. Size ratios are measured
  // against the active target field when enforceSizeMap or auditSizeMap is
  // enabled; only enforceSizeMap activates normative size bounds.
  struct QualityCriterionPassSummary {
    std::size_t applicable = 0;
    std::size_t preferredPass = 0;
    std::size_t absolutePass = 0;
  };

  struct QuadMeshQualitySummary {
    bool success = true;
    std::size_t facesWithElements = 0;
    std::size_t nonManifoldFaces = 0;
    std::size_t triangles = 0;
    std::size_t quadrangles = 0;
    std::size_t invalidTriangles = 0;
    std::size_t invalidQuadrangles = 0;
    std::size_t absolutePassElements = 0;
    std::size_t badTriangles = 0;
    std::size_t badQuadrangles = 0;
    std::size_t absoluteQuadrangleViolations = 0;
    std::size_t preferredQuadrangleViolations = 0;
    std::size_t severeValenceVertices = 0;
    std::size_t irregularValenceVertices = 0;
    QualityCriterionPassSummary warping;
    QualityCriterionPassSummary edgeRatio;
    QualityCriterionPassSummary quadrangleMinimumAngle;
    QualityCriterionPassSummary quadrangleMaximumAngle;
    QualityCriterionPassSummary triangleMinimumAngle;
    QualityCriterionPassSummary triangleMaximumAngle;
    QualityCriterionPassSummary skewing;
    bool passesShapeSpecifications = false;
    double minimumQuadrangleSICN = 0.;
    double averageQuadrangleSICN = 0.;
    double minimumQuadrangleAngleDegrees = 0.;
    double maximumQuadrangleAngleDegrees = 0.;
    double maximumQuadrangleEdgeRatio = 0.;
    double averageQuadrangleEdgeRatio = 0.;
    double maximumQuadrangleSkewingDegrees = 0.;
    double averageQuadrangleSkewingDegrees = 0.;
    double maximumQuadrangleWarpingDegrees = 0.;
    double averageQuadrangleWarpingDegrees = 0.;
    bool sizeAudited = false;
    bool sizeSpecificationsActive = false;
    std::size_t sizeEdges = 0;
    std::size_t edgesBelowMinimum = 0;
    std::size_t edgesAboveMaximum = 0;
    std::size_t invalidSizeEdges = 0;
    double minimumEdgeLength = 0.;
    double maximumEdgeLength = 0.;
    double minimumTargetSizeRatio = 0.;
    double maximumTargetSizeRatio = 0.;
    double rmsLogTargetSizeRatio = 0.;
    bool cadAudited = false;
    std::size_t cadElementsRequested = 0;
    std::size_t cadElements = 0;
    std::size_t invalidCadElements = 0;
    std::size_t invalidCadSamples = 0;
    double maximumCadDistance = 0.;
    double rmsCadDistance = 0.;
  };

  GMSH_API QuadMeshQualitySummary summarizeQuadMeshQuality(
    GModel *model,
    const SmallCavityOptimizerOptions &options =
      SmallCavityOptimizerOptions());

  // Replace adjacent triangle pairs by quadrangles only when the complete
  // local transaction strictly improves the same additive global quality as
  // Fast cleanup. Candidates must satisfy every absolute shape
  // specification, remain strictly convex in UV and physical space, preserve
  // the surface cell complex and not increase hard edge-size violations. The
  // integrated distance to the CAD participates in the compromise.
  GMSH_API TerminalTriangleRecombinationResult
  recombineRemainingTrianglePairs(
    GFace *face,
    const SmallCavityOptimizerOptions &options =
      SmallCavityOptimizerOptions());

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
