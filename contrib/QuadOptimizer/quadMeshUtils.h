// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.

#pragma once

#include "GmshGlobal.h"
#include "quadQuality.h"
#include "smallCavityWinslow.h"

#include <cstddef>
#include <limits>
#include <vector>

class GFace;
class GModel;
class MQuadrangle;
class SPoint2;

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

  struct SmallCavityOptimizerOptions {
    bool optimizeOneInteriorVertexCavities = true;
    bool eliminateDiamonds = true;
    bool splitValenceSixVertices = true;
    bool convertBoundaryTriangleQuadTriangleFans = true;
    // Optional post-processing: attempt to establish one complete quad ring
    // around every hole, opening a newly inserted infinitesimal ring with
    // local Winslow when physical and CAD guards accept it. Zero disables
    // the operator. One optimizes the complete affected vertex stars; larger
    // values add neighboring element layers to that patch.
    int pillowNeighborLayers = 0;
    // Freitag (1997) Smart Laplacian, adapted to projected surface quads.
    // Strict local minimum-sine improvement; no optimization fallback.
    bool smartLaplacian = false;
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
    int maximumOptimizationPasses = 3; // V2: -1 runs until a topology-idle pass.
    int maximumAcceptedCavities = 100;

    // Optional size-map filter. It is disabled by default: cavity boundaries
    // are fixed, so size variations remain local.
    bool enforceSizeMap = false;
    // Read the active target field for the final report without turning its
    // values into hard optimization bounds. This is used by PACK when a
    // spatially varying guiding field is active.
    bool auditSizeMap = false;
    // Positive: constant target size. Non-positive: use the active scaled
    // vector field when enforcing constraints, then fall back to BGM_MeshSize.
    double targetSize = -1.;
    // Absolute physical bounds; non-positive values disable the corresponding
    // bound. Active absolute and relative bounds are intersected.
    double minimumEdgeLength = 0.;
    double maximumEdgeLength = 0.;
    double minimumEdgeSizeRatio = .35;
    double maximumEdgeSizeRatio = 2.5;
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
  };

  struct SmallCavityOptimizerResult {
    bool success = true;
    bool skippedInvalidInputCellComplex = false;
    std::size_t passes = 0;
    // Number of committed local topology transactions on this face.
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
    std::size_t acceptedFinalSmoothingCavities = 0;
    std::size_t acceptedEdgeSwaps = 0;
    std::size_t acceptedOneInteriorVertexCavities = 0;
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

  struct FaceOptimizerResult {
    int faceTag = -1;
    SmallCavityOptimizerResult optimizer;
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
    bool sizeRequirementsMet = true;
    std::size_t finalEdgesBelowMinimum = 0;
    std::size_t finalEdgesAboveMaximum = 0;
    std::size_t finalInvalidSizeEdges = 0;
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

  // Validity of a final surface quad, as counted by summarizeQuadMeshQuality:
  // topologically valid, physically non-concave, positive SICN and eta, and
  // not opposed to the CAD normal (parameters: its known UV, if any)
  GMSH_API bool isValidFinalQuadrangle(
    GFace *face, MQuadrangle *quadrangle,
    const std::vector<SPoint2> *parameters = nullptr);

  GMSH_API QuadMeshQualitySummary summarizeQuadMeshQuality(
    GModel *model,
    const SmallCavityOptimizerOptions &options =
      SmallCavityOptimizerOptions());

  // Read-only guard for callers that perform additional model-wide topology
  // operations after cleanup. False means the face must be left untouched:
  // its triangle/quad cells cannot form a regular, currently oriented
  // half-edge complex.
  GMSH_API bool isRegularOrientedSurfaceCellComplex(GFace *face);

  struct QuadHoleRingResult {
    bool success = true;
    bool skippedInvalidInputCellComplex = false;
    std::size_t visited = 0, alreadyPresent = 0, accepted = 0, rejected = 0;
    std::size_t insertedQuadrangles = 0;
    std::size_t collapseCandidates = 0, acceptedCollapses = 0;
    std::size_t trianglesRemoved = 0;
    // Across candidate trials: unavailable UV normals resolved by a bounded
    // closest-point query on the immutable discrete support.
    std::size_t physicalNormalQueries = 0, physicalNormalCovered = 0;
  };

  // Insert at most one complete ring per hole. Boundary/embedded vertices
  // stay fixed. Every changed
  // patch passes complete physical-normal sampling, non-folding and bounded
  // local/cumulative CAD-distance checks before its transaction. Shape and
  // edge-size specifications are reported but do not veto structural rings.
  // Nearby TT contractions then remove triangles at fixed surviving XYZ,
  // preserving every ring cell and every quad. Strict triangle reduction
  // makes this cleanup terminate at a deterministic local fixed point.
  // pillowNeighborLayers enlarges the smoothing support, not the ring count.
  GMSH_API QuadHoleRingResult insertQuadHoleRings(
    GFace *face,
    const SmallCavityOptimizerOptions &options = SmallCavityOptimizerOptions());

} // namespace QuadOptimizer
