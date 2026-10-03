// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.

#include "quadOptimizerIntegration.h"
#include "quadMeshUtils.h"
#include "smallCavityOptimizerV2.h"
#include "quadFinalRepair.h"
#include "Context.h"
#include "GmshMessage.h"
#include "GModel.h"
#include "GFace.h"
#include "GEdge.h"
#include "GVertex.h"
#include "MQuadrangle.h"
#include "meshQuadQuasiStructured.h"
#include <algorithm>
#include <cmath>
#include <limits>
#include <map>
#include <set>

namespace QuadOptimizer {
  static void PrintQuadMeshQualitySummary(
    const char *label, const QuadOptimizer::QuadMeshQualitySummary &quality)
  {
    if(!quality.success) {
      Msg::Warning("%s quality summary could not be computed", label);
      return;
    }
    const std::size_t elements = quality.triangles + quality.quadrangles;
    const bool validityPass = quality.nonManifoldFaces == 0 &&
                              quality.invalidTriangles == 0 &&
                              quality.invalidQuadrangles == 0;
    const bool sizePass =
      quality.sizeSpecificationsActive && quality.sizeAudited &&
      quality.sizeEdges > 0 && quality.edgesBelowMinimum == 0 &&
      quality.edgesAboveMaximum == 0 && quality.invalidSizeEdges == 0;
    Msg::Info("%s quality: faces=%zu triangles=%zu quads=%zu "
              "absolutePass=%zu/%zu validity=%s invalid[T/Q]=%zu/%zu "
              "nonManifoldFaces=%zu shapeSpecs=%s sizeSpecs=%s",
              label, quality.facesWithElements, quality.triangles,
              quality.quadrangles, quality.absolutePassElements, elements,
              validityPass ? "PASS" : "FAIL", quality.invalidTriangles,
              quality.invalidQuadrangles, quality.nonManifoldFaces,
              quality.passesShapeSpecifications ? "PASS" : "FAIL",
              quality.sizeSpecificationsActive ? (sizePass ? "PASS" : "FAIL") :
                                                 "off");
    Msg::Info("%s specifications pass(preferred/total|absolute/total): "
              "warp=%zu/%zu|%zu/%zu edgeRatio=%zu/%zu|%zu/%zu "
              "quadAngleMin=%zu/%zu|%zu/%zu "
              "quadAngleMax=%zu/%zu|%zu/%zu "
              "triAngleMin=%zu/%zu|%zu/%zu "
              "triAngleMax=%zu/%zu|%zu/%zu skew=%zu/%zu|%zu/%zu",
              label, quality.warping.preferredPass, quality.warping.applicable,
              quality.warping.absolutePass, quality.warping.applicable,
              quality.edgeRatio.preferredPass, quality.edgeRatio.applicable,
              quality.edgeRatio.absolutePass, quality.edgeRatio.applicable,
              quality.quadrangleMinimumAngle.preferredPass,
              quality.quadrangleMinimumAngle.applicable,
              quality.quadrangleMinimumAngle.absolutePass,
              quality.quadrangleMinimumAngle.applicable,
              quality.quadrangleMaximumAngle.preferredPass,
              quality.quadrangleMaximumAngle.applicable,
              quality.quadrangleMaximumAngle.absolutePass,
              quality.quadrangleMaximumAngle.applicable,
              quality.triangleMinimumAngle.preferredPass,
              quality.triangleMinimumAngle.applicable,
              quality.triangleMinimumAngle.absolutePass,
              quality.triangleMinimumAngle.applicable,
              quality.triangleMaximumAngle.preferredPass,
              quality.triangleMaximumAngle.applicable,
              quality.triangleMaximumAngle.absolutePass,
              quality.triangleMaximumAngle.applicable,
              quality.skewing.preferredPass, quality.skewing.applicable,
              quality.skewing.absolutePass, quality.skewing.applicable);
    Msg::Info(
      "%s quad metrics: SICN[min/avg]=%.6g/%.6g "
      "angle[min/max]=%.6g/%.6gdeg "
      "edgeRatio[max/avg]=%.6g/%.6g "
      "skew[max/avg]=%.6g/%.6gdeg "
      "warp[max/avg]=%.6g/%.6gdeg bad=%zu invalid=%zu "
      "valence[severe/irregular]=%zu/%zu",
      label, quality.minimumQuadrangleSICN, quality.averageQuadrangleSICN,
      quality.minimumQuadrangleAngleDegrees,
      quality.maximumQuadrangleAngleDegrees, quality.maximumQuadrangleEdgeRatio,
      quality.averageQuadrangleEdgeRatio,
      quality.maximumQuadrangleSkewingDegrees,
      quality.averageQuadrangleSkewingDegrees,
      quality.maximumQuadrangleWarpingDegrees,
      quality.averageQuadrangleWarpingDegrees, quality.badQuadrangles,
      quality.invalidQuadrangles, quality.severeValenceVertices,
      quality.irregularValenceVertices);
    if(quality.sizeAudited)
      Msg::Info("%s fit: sizeEdges=%zu length[min/max]=%.6g/%.6g "
                "targetRatio[min/max/rmsLog]=%.6g/%.6g/%.6g "
                "sizeBad[below/above/invalid]=%zu/%zu/%zu "
                "CADchord[max/rms]=%.6g/%.6g "
                "CADcoverage=%zu/%zu invalidElements=%zu invalidSamples=%zu",
                label, quality.sizeEdges, quality.minimumEdgeLength,
                quality.maximumEdgeLength, quality.minimumTargetSizeRatio,
                quality.maximumTargetSizeRatio, quality.rmsLogTargetSizeRatio,
                quality.edgesBelowMinimum, quality.edgesAboveMaximum,
                quality.invalidSizeEdges,
                quality.maximumSampledCadChordDistance,
                quality.rmsCadChordDistance, quality.cadElements,
                quality.cadElementsRequested, quality.invalidCadElements,
                quality.invalidCadSamples);
    else
      Msg::Info("%s fit: size=off CADchord[max/rms]=%.6g/%.6g "
                "CADcoverage=%zu/%zu invalidElements=%zu invalidSamples=%zu",
                label, quality.maximumSampledCadChordDistance,
                quality.rmsCadChordDistance, quality.cadElements,
                quality.cadElementsRequested, quality.invalidCadElements,
                quality.invalidCadSamples);
  }

  static SmallCavityOptimizerOptions optimizerOptions()
  {
    SmallCavityOptimizerOptions options;
    options.minimumRecombinationQuality =
      std::max(0., CTX::instance()->mesh.recombineMinimumQuality);
    options.pillowNeighborLayers =
      CTX::instance()->mesh.optimizeQuadsPillowLayers;
    const double targetSize = CTX::instance()->mesh.optimizeQuadsTargetSize;
    if(targetSize > 0. ||
       CTX::instance()->mesh.optimizeQuadsMinimumEdgeLength > 0. ||
       CTX::instance()->mesh.optimizeQuadsMaximumEdgeLength > 0.) {
      options.enforceSizeMap = true;
      options.targetSize = targetSize;
      options.minimumEdgeLength =
        CTX::instance()->mesh.optimizeQuadsMinimumEdgeLength;
      options.maximumEdgeLength =
        CTX::instance()->mesh.optimizeQuadsMaximumEdgeLength;
      options.minimumEdgeSizeRatio = 0.;
      options.maximumEdgeSizeRatio = 0.;
    }
    options.finalSplitCadDistanceRatio =
      CTX::instance()->mesh.optimizeQuadsFinalSplitCadDistanceRatio;
    options.smartLaplacian =
      CTX::instance()->mesh.optimizeQuadsSmartLaplacian != 0;
    options.finalWinslowPasses =
      CTX::instance()->mesh.optimizeQuadsSmartLaplacian == 2 ? 1 : 0;
    options.finalSmoothingPasses =
      std::max(0, CTX::instance()->mesh.nbSmoothing);
    options.maximumOptimizationPasses = -1; // Stop after a topology-idle round.
    options.maximumAcceptedCavities = 10000;
    options.verbose = std::max(0, Msg::GetVerbosity() - 5);
    return options;
  }

  void optimizeQuads(GModel *m, const std::string &how, bool reportQuadQuality)
  {
    if(CTX::instance()->abortOnError && Msg::GetErrorCount()) return;
    SmallCavityOptimizerOptions options = optimizerOptions();
    if(how == "OptimizeQuadHoleRings") {
      options.verbose = std::max(0, Msg::GetVerbosity() - 4);
      QuadHoleRingResult total;
      std::size_t faces = 0, skipped = 0;
      options.invalidateVertexArrays = false;
      for(GFace *face : m->getFaces()) {
        if(face->triangles.empty() && face->quadrangles.empty()) continue;
        ++faces;
        const QuadHoleRingResult result = insertQuadHoleRings(face, options);
        total.success = total.success && result.success;
        total.visited += result.visited;
        total.alreadyPresent += result.alreadyPresent;
        total.accepted += result.accepted;
        total.rejected += result.rejected;
        total.insertedQuadrangles += result.insertedQuadrangles;
        total.collapseCandidates += result.collapseCandidates;
        total.acceptedCollapses += result.acceptedCollapses;
        total.trianglesRemoved += result.trianglesRemoved;
        total.physicalNormalQueries += result.physicalNormalQueries;
        total.physicalNormalCovered += result.physicalNormalCovered;
        skipped += result.skippedInvalidInputCellComplex;
      }
      if(total.accepted || total.acceptedCollapses) m->deleteVertexArrays();
      Msg::Info("OptimizeQuadHoleRings: faces=%zu visited=%zu already=%zu "
                "accepted=%zu rejected=%zu insertedQuads=%zu skippedFaces=%zu "
                "physicalNormalCoverage=%zu/%zu "
                "collapses=%zu/%zu trianglesRemoved=%zu",
                faces, total.visited, total.alreadyPresent, total.accepted,
                total.rejected, total.insertedQuadrangles, skipped,
                total.physicalNormalCovered, total.physicalNormalQueries,
                total.acceptedCollapses, total.collapseCandidates,
                total.trianglesRemoved);
      if(!total.success) Msg::Error("OptimizeQuadHoleRings failed");
      if(reportQuadQuality && Msg::GetVerbosity() >= 4)
        PrintQuadMeshQualitySummary(how.c_str(),
          summarizeQuadMeshQuality(m, options));
      return;
    }
    const QuadOptimizer::AllFacesOptimizerResult result =
      QuadOptimizer::optimizeSmallQuadCavitiesAllFacesV2(options);
    if(!result.success) { Msg::Error("%s failed", how.c_str()); }
    else {
      Msg::Info(
        "%s: %zu faces, %zu topology changes, bad "
        "elements %zu -> %zu, absolute violations %zu -> %zu, "
        "preferred violations %zu -> %zu, reoriented=%zu, "
        "skipped(inputCellComplex=%zu), "
        "rejected(size=%zu)",
        how.c_str(), result.facesWithQuadrangles, result.acceptedCavities,
        result.initialObjective.absoluteBadElementCount,
        result.finalObjective.absoluteBadElementCount,
        result.initialObjective.absoluteViolationCount,
        result.finalObjective.absoluteViolationCount,
        result.initialObjective.preferredViolationCount,
        result.finalObjective.preferredViolationCount,
        result.reorientedElements, result.facesSkippedInvalidInputCellComplex,
        result.rejectedBySize);
      Msg::Info("%s half-edge rule triangle_triangle_swap: "
                "visited=%zu accepted=%zu geometry=%zu",
                how.c_str(), result.triangleTriangleSwapsVisited,
                result.acceptedTriangleTriangleSwaps,
                result.acceptedGeometryDrivenTriangleTriangleSwaps);
      Msg::Info("%s geometry-driven midpoint swaps: TT=%zu TQ=%zu",
                how.c_str(),
                result.acceptedGeometryDrivenTriangleTriangleSwaps,
                result.acceptedGeometryDrivenMixedTriangleQuadSwaps);
      Msg::Info("%s interior TTQ -> Q reduction: accepted=%zu", how.c_str(),
                result.acceptedInteriorTriangleTriangleQuadReductions);
      Msg::Info("%s interior TTTT -> Q reduction: accepted=%zu", how.c_str(),
                result.acceptedInteriorFourTriangleFanReductions);
      Msg::Info("%s interior QTQT -> 2Q reduction: accepted=%zu", how.c_str(),
                result.acceptedInteriorAlternatingQuadTriangleReductions);
      Msg::Info("%s Q+T+T triangle reduction: accepted=%zu", how.c_str(),
                result.acceptedQuadTwoTriangleReductions);
      Msg::Info("%s half-edge rule boundary_t_qn_t: accepted=%zu",
                how.c_str(), result.acceptedBoundaryTriangleQuadTriangleFans);
      Msg::Info("%s final cleanup: split[invalid/quality/CAD]=%zu/%zu/%zu "
                "TTmerges=%zu TTcadSwaps=%zu QTswaps=%zu rejectedSplits=%zu",
                how.c_str(), result.finalInvalidQuadsSplit,
                result.finalQualityQuadsSplit, result.finalCadQuadsSplit,
                result.finalTtMerges, result.finalTtCadSwaps,
                result.finalQtSwaps, result.finalQuadsSplitRejected);
      if(options.enforceSizeMap && result.facesWithQuadrangles == 0) {
        Msg::Warning("QuadOptimizer: no quadrilateral face was found; "
                     "edge-length requirements were not audited");
      }
      else if(options.enforceSizeMap && !result.sizeRequirementsMet)
        Msg::Warning("QuadOptimizer: edge-length requirements are not met "
                     "after optimization (%zu below, %zu above, %zu "
                     "invalid)",
                     result.finalEdgesBelowMinimum,
                     result.finalEdgesAboveMaximum,
                     result.finalInvalidSizeEdges);
      if(reportQuadQuality && Msg::GetVerbosity() >= 4) {
        const QuadOptimizer::QuadMeshQualitySummary finalQuality =
          QuadOptimizer::summarizeQuadMeshQuality(m, options);
        PrintQuadMeshQualitySummary(how.c_str(), finalQuality);
      }
    }
  }

  void finishPackMesh(GModel *m)
  {
    for(GFace *gf : m->getFaces()) {
      if(gf->meshStatistics.status == GFace::DONE) {
        gf->meshStatistics.status = GFace::PENDING;
      }
    }
    bool debug = CTX::instance()->mesh.saveDebugFiles;

    transferSeamGEdgesVerticesToGFace(m);
    if(CTX::instance()->mesh.packPatterns)
      quadMeshingOfSimpleFacesWithPatterns(m, .02);

    // Preserve the generated mesh when cleanup is disabled.
    if(CTX::instance()->mesh.packCleanupMethod != 2) {
      // Cleanup can deliberately leave a malformed input face unchanged after
      // warning about it. No later PACK operation may then split/recombine that
      // face and accidentally hide an overlap in an apparently regular mesh.
      std::set<GFace *> terminalSkippedFaces;
      for(GFace *gf : m->getFaces()) {
        if(!isRegularOrientedSurfaceCellComplex(gf))
          terminalSkippedFaces.insert(gf);
      }
      if(!terminalSkippedFaces.empty())
        Msg::Warning("PACK: skipping terminal operations on %zu face%s with "
                     "an invalid surface cell complex",
                     terminalSkippedFaces.size(),
                     terminalSkippedFaces.size() == 1 ? "" : "s");

      // This is a validity invariant, not an optional quality filter. Shape
      // measures alone can miss a concave or folded bilinear quad on a curved
      // CAD face, and RecombineMinimumQuality=0 must not disable the terminal
      // fallback. Split every such quad with a parametrically and physically
      // consistent diagonal, even when this increases the triangle count or
      // violates the requested edge-size interval.
      // Opt-in raw Blossom experiment: give V2 the complete matched quads
      // before any validity split; keep all optimizer acceptance guards.
      const bool keepRawMatchedQuads =
        CTX::instance()->mesh.recombineMinimumQuality < 0.;
      if(keepRawMatchedQuads)
        Msg::Info("PACK: preserving raw matched quads for V2 repair "
                  "(RecombineMinimumQuality < 0)");
      std::size_t terminalNonConvexOrInvalid = 0;
      std::size_t terminalExcessiveWarping = 0;
      std::size_t terminalSplitCount = 0;
      std::size_t terminalRejected = 0;
      for(GFace *gf : m->getFaces()) {
        if(keepRawMatchedQuads ||
           terminalSkippedFaces.find(gf) != terminalSkippedFaces.end())
          continue;
        // Repair concave, inverted or degenerate quads before V2. Leave
        // finite warping and other quality defects to the optimizer.
        const double maximumWarpingDegrees =
          std::numeric_limits<double>::max();
        const WarpedQuadrangleSplitResult split =
          splitExcessivelyWarpedQuadrangles(gf, maximumWarpingDegrees, {}, {},
                                            {}, {}, {}, true);
        terminalNonConvexOrInvalid += split.nonConvexOrInvalid;
        terminalExcessiveWarping += split.excessiveWarping;
        terminalSplitCount += split.split;
        const std::size_t rejected =
          split.rejectedInvalid + split.rejectedUnsupportedOrder;
        terminalRejected += rejected;
        if(rejected) {
          terminalSkippedFaces.insert(gf);
          Msg::Warning("PACK face %d retains %zu prohibited concave, invalid "
                       "or unsupported terminal quadrangles with no valid "
                       "diagonal; skipping subsequent terminal operations",
                       gf->tag(), rejected);
        }
      }
      Msg::Info("PACK terminal quad validity: concaveOrInvalid=%zu "
                "excessiveWarping=%zu split=%zu rejected=%zu skippedFaces=%zu",
                terminalNonConvexOrInvalid, terminalExcessiveWarping,
                terminalSplitCount, terminalRejected,
                terminalSkippedFaces.size());

      // Recombination deliberately keeps low-quality valid quads in the PACK
      // path so that Winslow and cavity optimization can repair them. Once the
      // validity fallback above has selected safe diagonals, apply the optional
      // eta filter to the remaining convex quads.
      const double minQuality = CTX::instance()->mesh.recombineMinimumQuality;
      if(minQuality > 0.) {
        std::size_t quadsBefore = 0, trianglesBefore = 0;
        for(GFace *gf : m->getFaces()) {
          quadsBefore += gf->quadrangles.size();
          trianglesBefore += gf->triangles.size();
          if(terminalSkippedFaces.find(gf) != terminalSkippedFaces.end())
            continue;
          splitLowQualityQuads(
            gf, minQuality,
            CTX::instance()->mesh.optimizeQuadsMinimumEdgeLength,
            CTX::instance()->mesh.optimizeQuadsMaximumEdgeLength);
        }
        std::size_t quadsAfter = 0, trianglesAfter = 0;
        for(GFace *gf : m->getFaces()) {
          quadsAfter += gf->quadrangles.size();
          trianglesAfter += gf->triangles.size();
        }
        Msg::Info("PACK pre-optimization quality filter (%g): split %zu "
                  "quads into %zu triangles",
                  minQuality, quadsBefore - quadsAfter,
                  trianglesAfter - trianglesBefore);
      }

      // V2 owns topology cleanup and nodal Winslow sweeps. Run it after PACK's
      // validity fallbacks; only the final validity repair below may
      // change connectivity afterward, without moving the optimized nodes.
      Msg::Info("PACK final cleanup: V2 with final nodal Winslow");
      optimizeQuads(m, "OptimizeQuadsFast", false);

      // The final nodal sweeps above can still leave a concave or
      // degenerate quad; splitting it along a valid diagonal cannot undo
      // the smoothing, so the validity split has the last word.
      std::size_t postNonConvexOrInvalid = 0, postSplit = 0,
                  postRejected = 0;
      for(GFace *gf : m->getFaces()) {
        if(keepRawMatchedQuads ||
           terminalSkippedFaces.find(gf) != terminalSkippedFaces.end())
          continue;
        const WarpedQuadrangleSplitResult split =
          splitExcessivelyWarpedQuadrangles(
            gf, std::numeric_limits<double>::max(), {}, {}, {},
            [](GFace *face, MQuadrangle *quad) {
              return !QuadOptimizer::isValidFinalQuadrangle(face, quad);
            },
            {}, true);
        postNonConvexOrInvalid +=
          split.nonConvexOrInvalid + split.selectedByRequirement;
        postSplit += split.split;
        postRejected += split.rejectedInvalid + split.rejectedUnsupportedOrder;
      }
      if(postSplit) m->deleteVertexArrays();
      Msg::Info("PACK post-V2 quad validity: concaveOrInvalid=%zu split=%zu "
                "rejected=%zu",
                postNonConvexOrInvalid, postSplit, postRejected);

      if(Msg::GetVerbosity() >= 4) {
        SmallCavityOptimizerOptions auditOptions = optimizerOptions();
        if(!auditOptions.enforceSizeMap) auditOptions.auditSizeMap = true;
        const QuadOptimizer::QuadMeshQualitySummary finalQuality =
          QuadOptimizer::summarizeQuadMeshQuality(m, auditOptions);
        PrintQuadMeshQualitySummary("PACK final", finalQuality);
      }
    }
    else {
      Msg::Info("PACK cleanup disabled: preserving generated mesh");
    }
    if(debug) m->writeMSH("opti4.msh");

    for(GFace *gf : m->getFaces()) {
      if(gf->meshStatistics.status == GFace::PENDING) {
        gf->meshStatistics.status = GFace::DONE;
      }
    }
  }

  // PACK uses the standard mesh size settings. For uniform sizes, derive
  // cleanup bounds and preserve boundary loops; variable size fields keep
  // their local sizing. Restore temporary meshing settings after generation.
  struct PackMeshScope::State {
    bool active = false;
    bool packing = false;
    int recombineAll = 0;
    int minCurveNodes = 0;
    int smoothingPasses = 0;
    int forceAllPackedPoints = 0;
    double minimumEdgeLength = 0.;
    double maximumEdgeLength = 0.;
    std::map<GEdge *, int> minimumSegmentsByEdge;

    void preserveDiscreteBoundaryLoops()
    {
      GModel *model = GModel::current();
      if(!model) return;
      const auto requireSegments = [&](GEdge *edge, int minimum) {
        if(edge->meshAttributes.minimumMeshSegments >= minimum) return;
        minimumSegmentsByEdge.emplace(
          edge, edge->meshAttributes.minimumMeshSegments);
        edge->meshAttributes.minimumMeshSegments = minimum;
      };
      for(GFace *face : model->getFaces()) {
        if(face->geomType() != GEntity::DiscreteSurface) continue;
        // Imported discrete faces need not populate GFace::edgeLoops. Recover
        // the one- and two-curve loops from their actual boundary edges and
        // endpoints; embedded curves are deliberately not included. OCCFace
        // already imposes these same topological minima on its wires.
        std::map<std::pair<int, int>, std::set<GEdge *>> edgesByEndpoints;
        for(GEdge *edge : face->edges()) {
          GVertex *first = edge->getBeginVertex();
          GVertex *second = edge->getEndVertex();
          if(!first || !second) continue;
          if(first == second)
            requireSegments(edge, 3);
          else
            edgesByEndpoints[std::minmax(first->tag(), second->tag())].insert(edge);
        }
        for(const auto &entry : edgesByEndpoints)
          if(entry.second.size() == 2)
            for(GEdge *edge : entry.second) requireSegments(edge, 2);
      }
    }

    State()
    {
      contextMeshOptions &mesh = CTX::instance()->mesh;
      const bool uniformSize =
        mesh.lcMin > 0. && mesh.lcMax > 0. && mesh.lcFactor > 0. &&
        std::isfinite(mesh.lcFactor) &&
        std::isfinite(mesh.lcMin) && std::isfinite(mesh.lcMax) &&
        std::abs(mesh.lcMax - mesh.lcMin) <=
          1.e-12 * std::max({1., mesh.lcMin, mesh.lcMax});
      const double h = (.5 * mesh.lcMin + .5 * mesh.lcMax) * mesh.lcFactor;
      packing = mesh.algo2d == ALGO_2D_PACK_PRLGRMS;
      active = packing && uniformSize && h > 0. && std::isfinite(h) &&
               !(mesh.optimizeQuadsMinimumEdgeLength > 0.) &&
               !(mesh.optimizeQuadsMaximumEdgeLength > 0.);
      // PACK is a quad mesher: recombine its triangulation of the packed
      // points whatever the size specification (uniform or a size field)
      if(packing) {
        recombineAll = mesh.recombineAll;
        mesh.recombineAll = 1;
      }
      if(!active) return;

      minCurveNodes = mesh.minCurveNodes;
      smoothingPasses = mesh.nbSmoothing;
      forceAllPackedPoints = mesh.packForceAllPoints;
      minimumEdgeLength = mesh.optimizeQuadsMinimumEdgeLength;
      maximumEdgeLength = mesh.optimizeQuadsMaximumEdgeLength;

      preserveDiscreteBoundaryLoops();
      mesh.minCurveNodes = 1;
      mesh.nbSmoothing =
        std::max(mesh.nbSmoothing, mesh.optimizeQuadsSmartLaplacian ? 3 : 5);
      mesh.packForceAllPoints = 1;
      mesh.optimizeQuadsMinimumEdgeLength = .5 * h;
      mesh.optimizeQuadsMaximumEdgeLength = 2. * h;

      Msg::Info("PACK uniform size: h=%g, admissible edges=[%g,%g], "
                "3D packing forced",
                h, mesh.optimizeQuadsMinimumEdgeLength,
                mesh.optimizeQuadsMaximumEdgeLength);
    }

    ~State()
    {
      contextMeshOptions &mesh = CTX::instance()->mesh;
      if(packing) mesh.recombineAll = recombineAll;
      if(!active) return;
      mesh.minCurveNodes = minCurveNodes;
      mesh.nbSmoothing = smoothingPasses;
      mesh.packForceAllPoints = forceAllPackedPoints;
      mesh.optimizeQuadsMinimumEdgeLength = minimumEdgeLength;
      mesh.optimizeQuadsMaximumEdgeLength = maximumEdgeLength;
      for(const auto &entry : minimumSegmentsByEdge)
        entry.first->meshAttributes.minimumMeshSegments = entry.second;
    }
  };

  PackMeshScope::PackMeshScope() : _state(new State) {}
  PackMeshScope::~PackMeshScope() = default;

} // namespace QuadOptimizer
