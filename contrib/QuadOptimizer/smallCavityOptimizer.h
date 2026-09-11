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
    // stored disk quadrangulations instead of relying on the paper's
    // non-enumerated set of 64 implementation cases.
    bool cleanUpConnectivity = true;
    bool cleanUpBoundary = true;
    bool cleanUpShape = true;
    bool cleanUpSize = true;
    // Paper-style path used by OptimizeQuadsFast: constant-size local
    // decisions, harmonic candidate placement and bounded local Winslow
    // relaxation.
    bool fastInteractiveCleanUp = false;
    // Simpler Fast schedule: first apply monotone structural reductions
    // (including valid TT -> Q and diamond collapses), then accept QQ/QT/TT
    // swaps only when the unchanged vertex geometry strictly improves the
    // element-quality objective, and finally smooth the resulting topology
    // once.
    bool stagedTopologyThenQuality = false;
    // Internal candidate-evaluation contracts used by the staged schedule.
    // They remain public to keep copied option sets explicit and testable,
    // but normal callers should select stagedTopologyThenQuality instead.
    bool evaluateCandidatesWithoutLocalSmoothing = false;
    bool requireStrictElementQualityImprovement = false;
    // Internal contract for mandatory acyclic reductions selected by the
    // staged topology pass (QTT -> Q, T-Q^k-T, TT -> Q and diamonds).
    // The replacement must remain topologically valid, oriented and
    // non-degenerate, but quality/size/CAD improvement is deferred to the
    // single global smoothing pass.
    bool acceptValidTopologyReduction = false;
    // Run only the final fixed-point closure of the complete local rewrite
    // catalog. PACK uses this after its terminal operations, which can expose
    // swaps, triangle strips, boundary fans or diamonds after the ordinary
    // Fast optimization.
    bool finalPatternClosureOnly = false;
    bool topologyOnlyIfCavityHasSpecificationFailure = true;
    // Optional post-processing: attempt to establish one complete quad ring
    // around every hole, opening a newly inserted infinitesimal ring with
    // local Winslow when all quality and size gates accept it. Zero disables
    // the operator. One optimizes the complete affected vertex stars; larger
    // values add neighboring element layers to that patch.
    int pillowNeighborLayers = 0;
    int smoothingPasses = 2;
    // Freitag (1997) Smart Laplacian, adapted to projected surface quads.
    // Strict local minimum-sine improvement; no optimization fallback.
    bool smartLaplacian = false;
    // V2: only revisit stars touched by connectivity or coordinate changes.
    bool activeNodalSmoothing = true;
    int finalSmoothingPasses = 2;
    // In V2, each initial/round batch uses these two nodal sweep budgets.
    // Winslow proposes mean-plane 3D moves with the same quality gate as Smart.
    int finalWinslowPasses = 0;
    // V2: full-mesh pure Winslow sweeps after topology becomes idle, followed
    // by final quad splitting, admissible TT recombination and CAD-edge swaps.
    int terminalWinslowPasses = 4;
    // Enable the V2 valence phase, with local Winslow on replacement points.
    bool terminalMandatoryCleanup = true;
    // V2 quality-gated QQ/QT swaps, separate from valence and TT merges.
    bool qualitySwaps = true;
    // Final Q -> 2T fallback, after all smoothing and mandatory rewrites.
    // A negative ratio disables only the CAD-distance trigger. Invalid and
    // absolute-quality-failing quads are always tried; every inserted triangle
    // must pass the complete physical orientation check.
    double finalSplitCadDistanceRatio = .2;
    bool finalPairCleanup = true; // V2: enable the TT merge phase.
    int postTopologyNeighborSmoothingPasses = 2;
    int maximumOptimizationPasses = 3; // V2: -1 runs until a topology-idle pass.
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
    // Positive: constant target size. Non-positive: use the active scaled
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
    // Geometry-driven T+T and T+Q edge swaps. A separating chord becomes a
    // repair target when its midpoint is farther than this fraction of the
    // local target size from the supporting face. The replacement chord must
    // leave at most this fraction of the old normalized distance. The
    // defaults therefore require d_old > 0.1 h and d_new <= 0.5 d_old.
    double edgeMidpointCadSwapTriggerRatio = .1;
    double edgeMidpointCadSwapMaximumRemainingFraction = .5;
    // Structural reductions may trade a bounded amount of chordal CAD fit
    // for fewer triangles or a removed diamond. Both limits are dimensionless:
    // the integral is divided by A*h^2 and the maximum-distance increase by h.
    double maximumNormalizedCadRegression = .005;
    double maximumCadDistanceIncreaseRatio = .1;
    // A terminal T+T -> Q merge must not recreate a quadrangle that the
    // caller's optional eta-quality filter would immediately split again.
    double minimumRecombinationQuality = 0.;

    SmallCavityWinslowOptions winslow;
    bool invalidateVertexArrays = true;
    int verbose = 0;
    // Deterministic V2 structural schedules, followed by swaps and Winslow.
    // 0: stars/diamonds/strips/boundary; 1: strips/stars/boundary/diamonds;
    // 2: diamonds/boundary/stars/strips. All use identical acceptance guards.
    int v2Schedule = 0;
    // Bounded V2 searches after ordinary local operators reach a fixed point.
    // Bit 1: repair a defective patch; bit 2: compose triangle reductions.
    int v2SearchMode = 0;
    int v2SearchCandidateLimit = 32;
  };

  struct SmallCavityOptimizerResult {
    bool success = true;
    bool skippedInvalidInputCellComplex = false;
    std::size_t passes = 0;
    // Number of committed local topology transactions on this face. The V2
    // engine records this directly; legacy callers can continue using the
    // individual rule counters below.
    std::size_t acceptedCavities = 0;
    std::size_t acceptedTerminalMandatoryCavities = 0;
    std::size_t finalInvalidQuadsSplit = 0;
    std::size_t finalQualityQuadsSplit = 0;
    std::size_t finalQtSwaps = 0;
    std::size_t finalTtMerges = 0;
    std::size_t finalTtCadSwaps = 0;
    std::size_t initialValenceTwoQuadsSplit = 0;
    std::size_t finalCadQuadsSplit = 0;
    std::size_t finalQuadsSplitRejected = 0;
    std::size_t finalQuadDiagonalQueriesFailed = 0;
    std::size_t cavitiesVisited = 0;
    std::size_t topologyCandidatesOptimized = 0;
    std::size_t rejectedByWinslow = 0;
    std::size_t rejectedBySize = 0;
    std::size_t rejectedByQuality = 0;
    std::size_t reorientedElements = 0;
    std::size_t skippedSpecificationCompliant = 0;
    std::size_t diamondsVisited = 0;
    std::size_t acceptedDiamonds = 0;
    std::size_t valenceSixVerticesVisited = 0;
    std::size_t acceptedValenceSixSplits = 0;
    // Complete interior B=4, I=1 star with 2T+1Q collapsed to one quad.
    std::size_t interiorTriangleTriangleQuadStarsVisited = 0;
    std::size_t acceptedInteriorTriangleTriangleQuadReductions = 0;
    std::size_t interiorFourTriangleFansVisited = 0;
    std::size_t acceptedInteriorFourTriangleFanReductions = 0;
    // Complete interior B=6, I=1 alternating Q-T-Q-T star collapsed to the
    // best admissible pair of quadrangles.
    std::size_t interiorAlternatingQuadTriangleStarsVisited = 0;
    std::size_t acceptedInteriorAlternatingQuadTriangleReductions = 0;
    // Complete interior star T-Q-Q-T-Q-Q (up to D10 symmetry) rewritten as
    // six quads with one additional interior vertex.
    std::size_t interiorQQTQQTStarsVisited = 0;
    std::size_t acceptedInteriorQQTQQTReductions = 0;
    std::size_t boundaryTriangleQuadTriangleFansVisited = 0;
    std::size_t acceptedBoundaryTriangleQuadTriangleFans = 0;
    std::size_t triangleTriangleSwapsVisited = 0;
    std::size_t acceptedTriangleTriangleSwaps = 0;
    std::size_t acceptedGeometryDrivenTriangleTriangleSwaps = 0;
    std::size_t acceptedGeometryDrivenMixedTriangleQuadSwaps = 0;
    // Fast Q+T+T -> Q+Q reduction: a six-vertex disk containing one quad
    // and two adjacent triangles is replaced by the best valid pair of
    // quads. Triangle count is the strict improvement for this operator.
    std::size_t quadTwoTriangleCavitiesVisited = 0;
    std::size_t acceptedQuadTwoTriangleReductions = 0;
    // Simultaneous B=6 mixed rewrite for T-Q-T on opposite quad edges. It
    // preserves 1Q+2T while choosing among all 21 labelled planar fillings.
    std::size_t oppositeEdgeTriangleQuadSwapsVisited = 0;
    std::size_t acceptedOppositeEdgeTriangleQuadSwaps = 0;
    // Fallback for an opposite-edge T-Q-T disk when none of its direct 2Q
    // fillings is admissible: insert one face vertex and build three quads.
    std::size_t oppositeEdgeTriangleQuadFansVisited = 0;
    std::size_t acceptedOppositeEdgeTriangleQuadFans = 0;
    std::size_t acceptedFinalSmoothingCavities = 0;
    std::size_t acceptedEdgeSwaps = 0;
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
    std::size_t catastrophicAngleQuadranglesSelectedForSplit = 0;
    std::size_t catastrophicAngleQuadranglesSplit = 0;
    std::size_t catastrophicAngleQuadranglesRejectedBySize = 0;
    std::size_t catastrophicAngleQuadranglesRejectedByGeometry = 0;
    std::size_t catastrophicAngleQuadranglesRejectedOther = 0;
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
    bool reachedFixedPoint = false;
    bool exhaustedIterationBudget = false;
    bool exhaustedCavityBudget = false;
    std::size_t rejectedByCad = 0;
    std::size_t rejectedByOrientation = 0;
    std::size_t rejectedByTopology = 0;
    std::size_t rejectedCacheHits = 0;
  };

  struct ExistingTopologyWinslowResult {
    bool success = true;
    // True only when the last requested sweep accepted no bitwise geometry
    // change, which certifies that repeating the same deterministic sweep on
    // the same topology is idle.
    bool reachedFixedPoint = false;
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
    std::size_t facesSkippedInvalidInputCellComplex = 0;
    std::size_t acceptedCavities = 0;
    std::size_t acceptedTerminalMandatoryCavities = 0;
    std::size_t finalInvalidQuadsSplit = 0;
    std::size_t finalQualityQuadsSplit = 0;
    std::size_t finalQtSwaps = 0;
    std::size_t finalTtMerges = 0;
    std::size_t finalTtCadSwaps = 0;
    std::size_t initialValenceTwoQuadsSplit = 0;
    std::size_t finalCadQuadsSplit = 0;
    std::size_t finalQuadsSplitRejected = 0;
    std::size_t finalQuadDiagonalQueriesFailed = 0;
    std::size_t acceptedEdgeSwaps = 0;
    std::size_t acceptedDiamonds = 0;
    std::size_t acceptedValenceSixSplits = 0;
    std::size_t acceptedQuadTwoTriangleReductions = 0;
    std::size_t acceptedOppositeEdgeTriangleQuadSwaps = 0;
    std::size_t acceptedOppositeEdgeTriangleQuadFans = 0;
    std::size_t acceptedInteriorTriangleTriangleQuadReductions = 0;
    std::size_t acceptedInteriorFourTriangleFanReductions = 0;
    std::size_t acceptedInteriorAlternatingQuadTriangleReductions = 0;
    std::size_t acceptedInteriorQQTQQTReductions = 0;
    std::size_t acceptedBoundaryTriangleQuadTriangleFans = 0;
    std::size_t triangleTriangleSwapsVisited = 0;
    std::size_t acceptedTriangleTriangleSwaps = 0;
    std::size_t acceptedGeometryDrivenTriangleTriangleSwaps = 0;
    std::size_t acceptedGeometryDrivenMixedTriangleQuadSwaps = 0;
    std::size_t acceptedSmoothingCavities = 0;
    std::size_t rejectedByWinslow = 0;
    std::size_t rejectedBySize = 0;
    std::size_t rejectedByQuality = 0;
    std::size_t reorientedElements = 0;
    std::size_t pillowHolesVisited = 0;
    std::size_t pillowHolesAlreadyPresent = 0;
    std::size_t acceptedPillows = 0;
    std::size_t insertedPillowQuadrangles = 0;
    std::size_t excessiveWarpingQuadrangles = 0;
    std::size_t nonConvexOrInvalidQuadrangles = 0;
    std::size_t warpedQuadranglesSplit = 0;
    std::size_t warpedQuadranglesRejected = 0;
    std::size_t catastrophicAngleQuadranglesSelectedForSplit = 0;
    std::size_t catastrophicAngleQuadranglesSplit = 0;
    std::size_t catastrophicAngleQuadranglesRejectedBySize = 0;
    std::size_t catastrophicAngleQuadranglesRejectedByGeometry = 0;
    std::size_t catastrophicAngleQuadranglesRejectedOther = 0;
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
  // (parametric chord from the linear mesh to the CAD), never averaged face
  // by face. Size ratios are measured against the active target field when
  // enforceSizeMap or auditSizeMap is enabled; only enforceSizeMap activates
  // normative size bounds.
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
    double maximumSampledCadChordDistance = 0.;
    double rmsCadChordDistance = 0.;
  };

  GMSH_API QuadMeshQualitySummary summarizeQuadMeshQuality(
    GModel *model,
    const SmallCavityOptimizerOptions &options =
      SmallCavityOptimizerOptions());

  // Read-only guard for callers that perform additional model-wide topology
  // operations after cleanup. False means the face must be left untouched:
  // its triangle/quad cells cannot form a regular, currently oriented
  // half-edge complex.
  GMSH_API bool isRegularOrientedSurfaceCellComplex(GFace *face);

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
