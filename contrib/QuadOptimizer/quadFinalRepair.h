// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.

#ifndef QUAD_OPTIMIZER_FINAL_REPAIR_H
#define QUAD_OPTIMIZER_FINAL_REPAIR_H
#include <cstddef>
#include <functional>
#include <vector>
class GFace;
class MVertex;
class MElement;
class MQuadrangle;
namespace QuadOptimizer {
  void splitLowQualityQuads(GFace *gf, double minqual,
                            double minimumDiagonalLength = 0.,
                            double maximumDiagonalLength = 0.);

  struct WarpedQuadrangleSplitResult {
    std::size_t excessiveWarping = 0;
    std::size_t nonConvexOrInvalid = 0;
    std::size_t selectedByRequirement = 0;
    std::size_t split = 0;
    std::size_t rejectedInvalid = 0;
    std::size_t rejectedBySize = 0;
    std::size_t rejectedByGeometry = 0;
    std::size_t rejectedUnsupportedOrder = 0;
  };

  // Optional hard admissibility test for the only new edge introduced by a
  // terminal split. An empty predicate accepts every geometrically valid
  // diagonal. A false result is reported as rejectedBySize.
  using QuadrangleDiagonalAdmissibility =
    std::function<bool(GFace *, MVertex *, MVertex *)>;

  // Optional atomic cell-complex validation for the complete split batch.
  // The callback is invoked after every replacement triangle has been planned
  // but before the GFace is mutated or any input quadrangle is destroyed.
  using QuadrangleSplitTransactionAdmissibility = std::function<bool(
    GFace *, const std::vector<MElement *> &, const std::vector<MElement *> &)>;

  // Optional owner-side commit for the complete planned split batch. The
  // callback is invoked after admissibility, before this routine mutates GFace.
  // It must leave ownership of the proposed elements with the caller when it
  // returns false; on true they must have been transferred to the GFace.
  using QuadrangleSplitTransactionCommit = std::function<bool(
    GFace *, const std::vector<MElement *> &, const std::vector<MElement *> &)>;

  // Optional selector used by repair preflights that own only a precisely
  // identified subset of quadrangles. An empty predicate audits every quad.
  using QuadrangleSplitSelection = std::function<bool(GFace *, MQuadrangle *)>;

  // Optional additional trigger for a geometrically valid quadrangle. This is
  // used by callers that own quality requirements beyond warping and
  // parametric convexity (for example absolute angle, edge-ratio or skewing
  // specifications).
  using QuadrangleSplitRequirement =
    std::function<bool(GFace *, MQuadrangle *)>;

  // Optional CAD admissibility test for one candidate diagonal, represented by
  // its two oriented replacement triangles. It is evaluated independently for
  // both diagonals before the planarity/gamma tie-break; a rejected candidate
  // is never selected merely because the other diagonal is worse.
  using QuadrangleSplitGeometryAdmissibility =
    std::function<bool(GFace *, MQuadrangle *, MElement *, MElement *)>;

  // Transactional terminal quad-dominant fallback: split every linear quad
  // whose warping is not strictly below maximumWarpingDegrees, whose corner
  // topology is not a strictly convex quadrangle in the face parametrization,
  // or which is selected by additionalRequirement. Among the size- and
  // geometry- admissible diagonals, choose the one minimizing the angle between
  // the two triangle normals, then maximize the minimum triangle gamma quality.
  // The optional face-normal gate samples each proposed triangle at several
  // interior parameter locations: unavailable samples abstain, one reliable
  // non-positive sample rejects, and every triangle needs at least one reliable
  // positive sample. It should remain enabled whenever an oriented surface
  // normal field is available. Rejected quadrangles remain unchanged; all
  // admissible splits are submitted together to the optional transaction gate
  // before the valid subset is committed.
  WarpedQuadrangleSplitResult splitExcessivelyWarpedQuadrangles(
    GFace *gf, double maximumWarpingDegrees,
    const QuadrangleDiagonalAdmissibility &diagonalAdmissible = {},
    const QuadrangleSplitTransactionAdmissibility &transactionAdmissible = {},
    const QuadrangleSplitSelection &selection = {},
    const QuadrangleSplitRequirement &additionalRequirement = {},
    const QuadrangleSplitGeometryAdmissibility &geometryAdmissible = {},
    bool requireFaceNormal = true,
    const QuadrangleSplitTransactionCommit &transactionCommit = {});

} // namespace QuadOptimizer
#endif
