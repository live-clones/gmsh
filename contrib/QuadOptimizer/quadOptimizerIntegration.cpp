// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.

#include "quadOptimizerIntegration.h"
#include "smallCavityOptimizer.h"
#include "smallCavityOptimizerV2.h"
#include "quadFinalRepair.h"
#include "Context.h"
#include "GmshMessage.h"
#include "GModel.h"
#include "GFace.h"
#include "MQuadrangle.h"
#include "Generator.h"
#include "meshQuadQuasiStructured.h"
#include "meshGFaceOptimize.h"
#include "GmshConfig.h"
#include <algorithm>
#include <cmath>
#include <limits>
#include <set>
#if defined(HAVE_QUADMESHINGTOOLS)
#include "qmtQuadCavityRemeshing.h"
#endif

namespace QuadOptimizer {
  static double optimizationTargetSize()
  {
    const contextMeshOptions &mesh = CTX::instance()->mesh;
    return mesh.optimizeQuadsTargetSize > 0. ? mesh.optimizeQuadsTargetSize :
                                               mesh.packTargetSize;
  }

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

  void optimizeQuads(GModel *m, const std::string &how, bool reportQuadQuality)
  {
    if(CTX::instance()->abortOnError && Msg::GetErrorCount()) return;
    QuadOptimizer::SmallCavityOptimizerOptions options;
    options.fastInteractiveCleanUp = how == "OptimizeQuadsFast";
    options.stagedTopologyThenQuality = options.fastInteractiveCleanUp;
    options.minimumRecombinationQuality =
      std::max(0., CTX::instance()->mesh.recombineMinimumQuality);
    options.pillowNeighborLayers =
      CTX::instance()->mesh.optimizeQuadsPillowLayers;
    if(optimizationTargetSize() > 0. ||
       CTX::instance()->mesh.optimizeQuadsMinimumEdgeLength > 0. ||
       CTX::instance()->mesh.optimizeQuadsMaximumEdgeLength > 0.) {
      options.enforceSizeMap = true;
      options.targetSize = optimizationTargetSize();
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
      options.fastInteractiveCleanUp &&
      CTX::instance()->mesh.optimizeQuadsSmartLaplacian != 0;
    options.finalWinslowPasses =
      options.fastInteractiveCleanUp &&
          CTX::instance()->mesh.optimizeQuadsSmartLaplacian == 2 ?
        1 :
        0;
    options.finalSmoothingPasses =
      std::max(0, CTX::instance()->mesh.nbSmoothing);
    if(options.fastInteractiveCleanUp) {
      // Complete topology before the final physical mean-plane smoothing.
      // Mesh.Smoothing controls the terminal sweep budget, once per model.
      // Use the validated V2 budgets. The historical adapter capped the
      // old cleanup at two passes and inherited only 100 accepted cavities,
      // prematurely stopping V2 compared with the standalone benchmark.
      options.maximumOptimizationPasses =
        -1; // V2 stops after a topology-idle round.
      options.maximumAcceptedCavities = 10000;
      options.postTopologyNeighborSmoothingPasses = 1;
      // Pillow is a separate structural operator and does not yet use the
      // same strict Fast global-quality transaction.
      options.pillowNeighborLayers = 0;
    }
    // Keep -v5 output unchanged while reserving -v6 and above for compact
    // per-pattern diagnostics inside the half-edge optimizer.
    options.verbose = std::max(0, Msg::GetVerbosity() -
                                    (options.fastInteractiveCleanUp ? 5 : 4));
    const QuadOptimizer::AllFacesOptimizerResult result =
      options.fastInteractiveCleanUp ?
        QuadOptimizer::optimizeSmallQuadCavitiesAllFacesV2(options) :
        QuadOptimizer::optimizeSmallQuadCavitiesAllFaces(options);
    if(!result.success) { Msg::Error("%s failed", how.c_str()); }
    else {
      Msg::Info(
        "%s: %zu faces, %zu topology changes, %zu pillows "
        "(%zu quads), bad "
        "elements %zu -> %zu, absolute violations %zu -> %zu, "
        "preferred violations %zu -> %zu, reoriented=%zu, "
        "skipped(inputCellComplex=%zu), "
        "rejected(size=%zu)",
        how.c_str(), result.facesWithQuadrangles, result.acceptedCavities,
        result.acceptedPillows, result.insertedPillowQuadrangles,
        result.initialObjective.absoluteBadElementCount,
        result.finalObjective.absoluteBadElementCount,
        result.initialObjective.absoluteViolationCount,
        result.finalObjective.absoluteViolationCount,
        result.initialObjective.preferredViolationCount,
        result.finalObjective.preferredViolationCount,
        result.reorientedElements, result.facesSkippedInvalidInputCellComplex,
        result.rejectedBySize);
      if(options.fastInteractiveCleanUp)
        Msg::Info("%s half-edge rule triangle_triangle_swap: "
                  "visited=%zu accepted=%zu geometry=%zu",
                  how.c_str(), result.triangleTriangleSwapsVisited,
                  result.acceptedTriangleTriangleSwaps,
                  result.acceptedGeometryDrivenTriangleTriangleSwaps);
      if(options.fastInteractiveCleanUp)
        Msg::Info("%s geometry-driven midpoint swaps: TT=%zu TQ=%zu",
                  how.c_str(),
                  result.acceptedGeometryDrivenTriangleTriangleSwaps,
                  result.acceptedGeometryDrivenMixedTriangleQuadSwaps);
      if(options.fastInteractiveCleanUp)
        Msg::Info("%s interior TTQ -> Q reduction: accepted=%zu", how.c_str(),
                  result.acceptedInteriorTriangleTriangleQuadReductions);
      if(options.fastInteractiveCleanUp)
        Msg::Info("%s interior TTTT -> Q reduction: accepted=%zu", how.c_str(),
                  result.acceptedInteriorFourTriangleFanReductions);
      if(options.fastInteractiveCleanUp)
        Msg::Info("%s interior QTQT -> 2Q reduction: accepted=%zu", how.c_str(),
                  result.acceptedInteriorAlternatingQuadTriangleReductions);
      if(options.fastInteractiveCleanUp)
        Msg::Info("%s Q+T+T triangle reduction: accepted=%zu", how.c_str(),
                  result.acceptedQuadTwoTriangleReductions);
      if(options.fastInteractiveCleanUp)
        Msg::Info("%s opposite-edge T-Q-T mixed swap: accepted=%zu",
                  how.c_str(), result.acceptedOppositeEdgeTriangleQuadSwaps);
      if(options.fastInteractiveCleanUp)
        Msg::Info("%s opposite-edge T-Q-T -> 3Q fan: accepted=%zu", how.c_str(),
                  result.acceptedOppositeEdgeTriangleQuadFans);
      if(options.fastInteractiveCleanUp)
        Msg::Info("%s half-edge rule boundary_t_qn_t: accepted=%zu",
                  how.c_str(), result.acceptedBoundaryTriangleQuadTriangleFans);
      if(options.fastInteractiveCleanUp)
        Msg::Info("%s terminal split: excessiveWarping=%zu "
                  "nonConvexOrInvalid=%zu split=%zu rejected=%zu",
                  how.c_str(), result.excessiveWarpingQuadrangles,
                  result.nonConvexOrInvalidQuadrangles,
                  result.warpedQuadranglesSplit,
                  result.warpedQuadranglesRejected);
      if(options.fastInteractiveCleanUp)
        Msg::Info("%s final catastrophic-angle quad fallback: selected=%zu "
                  "split=%zu "
                  "rejectedSize=%zu rejectedGeometry=%zu "
                  "rejectedOther=%zu",
                  how.c_str(),
                  result.catastrophicAngleQuadranglesSelectedForSplit,
                  result.catastrophicAngleQuadranglesSplit,
                  result.catastrophicAngleQuadranglesRejectedBySize,
                  result.catastrophicAngleQuadranglesRejectedByGeometry,
                  result.catastrophicAngleQuadranglesRejectedOther);
      if(options.fastInteractiveCleanUp)
        Msg::Info("%s terminal triangle recombination: visited=%zu "
                  "accepted=%zu rejectedInvalid=%zu rejectedTopology=%zu "
                  "rejectedQuality=%zu rejectedSize=%zu "
                  "rejectedGeometry=%zu",
                  how.c_str(), result.terminalTrianglePairsVisited,
                  result.terminalTrianglePairsAccepted,
                  result.terminalTrianglePairsRejectedInvalid,
                  result.terminalTrianglePairsRejectedTopology,
                  result.terminalTrianglePairsRejectedQuality,
                  result.terminalTrianglePairsRejectedSize,
                  result.terminalTrianglePairsRejectedGeometry);
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
    quadMeshingOfSimpleFacesWithPatterns(m, .02);

    if(Msg::GetVerbosity() == 99) {
      std::vector<std::pair<SPoint3, int>> singularities;
      for(GFace *gf : m->getFaces()) {
#if defined(HAVE_QUADMESHINGTOOLS)
        improveQuadMeshTopologyWithCavityRemeshing(gf, singularities, false);
#endif
      }
    }

    // A disabled cleanup must also bypass the terminal legacy closure and
    // splitting passes. This preserves the PACK output for isolated optimizer
    // comparisons and matches the public option's documented meaning.
    if(CTX::instance()->mesh.packCleanupMethod != 2) {
      if(CTX::instance()->mesh.packCleanupMethod == 0)
        optimizeQuads(m, "OptimizeQuads", false);

      // Cleanup can deliberately leave a malformed input face unchanged after
      // warning about it. No later PACK operation may then split/recombine that
      // face and accidentally hide an overlap in an apparently regular mesh.
      std::set<GFace *> terminalSkippedFaces;
      if(CTX::instance()->mesh.packCleanupMethod == 0 ||
         CTX::instance()->mesh.packCleanupMethod == 1) {
        for(GFace *gf : m->getFaces()) {
          if(!QuadOptimizer::isRegularOrientedSurfaceCellComplex(gf))
            terminalSkippedFaces.insert(gf);
        }
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
      // before any legacy validity split; keep all optimizer acceptance guards.
      const bool keepRawMatchedQuads =
        CTX::instance()->mesh.packCleanupMethod == 1 &&
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
        // In the staged Fast strategy every valid TT pair is deliberately
        // merged before the single global smoothing pass. Splitting a convex,
        // oriented result only because it exceeds the quality warping target
        // would recreate the exact TT/QTT/TQQT patterns that phase removed.
        // Keep the terminal fallback for genuinely concave, inverted or
        // degenerate quads; leave finite warping to the reported quality.
        const double maximumWarpingDegrees =
          CTX::instance()->mesh.packCleanupMethod == 1 ?
            std::numeric_limits<double>::max() :
            QuadOptimizer::absoluteMaximumQuadWarpingDegrees;
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
        Msg::Info("PACK post-optimization quality filter (%g): split %zu "
                  "quads into %zu triangles",
                  minQuality, quadsBefore - quadsAfter,
                  trianglesAfter - trianglesBefore);
      }

      // Recover quadrangles from the residual triangles, but do not use the
      // historical Blossom/greedy recombiner here: it can recreate the exact
      // concave quad split above. This local transaction is accepted only when
      // the UV/physical validity, absolute specifications and size guards all
      // pass after a transactional mixed Winslow solve. Once those hard guards
      // pass, reducing two triangles to one valid quad is sufficient.
      QuadOptimizer::SmallCavityOptimizerOptions terminalOptions;
      terminalOptions.invalidateVertexArrays = false;
      terminalOptions.minimumRecombinationQuality = std::max(0., minQuality);
      if(optimizationTargetSize() > 0. ||
         CTX::instance()->mesh.optimizeQuadsMinimumEdgeLength > 0. ||
         CTX::instance()->mesh.optimizeQuadsMaximumEdgeLength > 0.) {
        terminalOptions.enforceSizeMap = true;
        terminalOptions.targetSize = optimizationTargetSize();
        terminalOptions.minimumEdgeLength =
          CTX::instance()->mesh.optimizeQuadsMinimumEdgeLength;
        terminalOptions.maximumEdgeLength =
          CTX::instance()->mesh.optimizeQuadsMaximumEdgeLength;
        terminalOptions.minimumEdgeSizeRatio = 0.;
        terminalOptions.maximumEdgeSizeRatio = 0.;
      }
      auto closeFinalPatterns = [&](const std::set<GFace *> &faces,
                                    const char *stage) {
        QuadOptimizer::SmallCavityOptimizerOptions closureOptions =
          terminalOptions;
        closureOptions.fastInteractiveCleanUp = true;
        closureOptions.finalPatternClosureOnly = true;
        closureOptions.smoothingPasses = 0;
        closureOptions.finalSmoothingPasses = 0;
        closureOptions.postTopologyNeighborSmoothingPasses = 0;
        closureOptions.invalidateVertexArrays = false;
        closureOptions.verbose = std::max(0, Msg::GetVerbosity() - 4);
        std::size_t processed = 0;
        std::size_t topologyChanges = 0;
        std::size_t edgeSwaps = 0;
        std::size_t triangleReductions = 0;
        std::size_t boundaryFans = 0;
        std::size_t diamonds = 0;
        bool success = true;
        for(GFace *gf : faces) {
          if(!gf || terminalSkippedFaces.find(gf) != terminalSkippedFaces.end())
            continue;
          const QuadOptimizer::SmallCavityOptimizerResult closure =
            QuadOptimizer::optimizeSmallQuadCavities(gf, closureOptions);
          ++processed;
          success = success && closure.success;
          diamonds += closure.acceptedDiamonds;
          edgeSwaps +=
            closure.acceptedEdgeSwaps + closure.acceptedTriangleTriangleSwaps;
          boundaryFans += closure.acceptedBoundaryTriangleQuadTriangleFans;
          triangleReductions +=
            closure.acceptedInteriorTriangleTriangleQuadReductions +
            closure.acceptedInteriorFourTriangleFanReductions +
            closure.acceptedInteriorAlternatingQuadTriangleReductions +
            closure.acceptedInteriorQQTQQTReductions +
            closure.acceptedQuadTwoTriangleReductions +
            closure.acceptedOppositeEdgeTriangleQuadFans +
            closure.acceptedBoundaryTriangleQuadTriangleFans +
            closure.terminalTrianglePairsAccepted;
          const std::size_t cleanUpChanges =
            closure.cleanUpConnectivityAccepted +
            closure.cleanUpBoundaryAccepted + closure.cleanUpShapeAccepted +
            closure.cleanUpSizeAccepted;
          const std::size_t nonCleanUpEdgeSwaps =
            closure.acceptedEdgeSwaps >= closure.acceptedCleanUpEdgeSwaps ?
              closure.acceptedEdgeSwaps - closure.acceptedCleanUpEdgeSwaps :
              0;
          topologyChanges +=
            closure.acceptedDiamonds + closure.acceptedTriangleTriangleSwaps +
            closure.acceptedQuadTwoTriangleReductions +
            closure.acceptedOppositeEdgeTriangleQuadFans +
            closure.acceptedInteriorTriangleTriangleQuadReductions +
            closure.acceptedInteriorFourTriangleFanReductions +
            closure.acceptedInteriorAlternatingQuadTriangleReductions +
            closure.acceptedInteriorQQTQQTReductions +
            closure.acceptedValenceSixSplits +
            closure.acceptedBoundaryTriangleQuadTriangleFans +
            nonCleanUpEdgeSwaps + closure.acceptedOneInteriorVertexCavities +
            closure.acceptedThreeInteriorVertexCavities +
            closure.acceptedFourInteriorVertexCavities +
            closure.terminalTrianglePairsAccepted +
            closure.warpedQuadranglesSplit +
            closure.catastrophicAngleQuadranglesSplit + cleanUpChanges;
        }
        if(topologyChanges) m->deleteVertexArrays();
        Msg::Info("PACK %s complete pattern closure: faces=%zu "
                  "topologyChanges=%zu edgeSwaps=%zu "
                  "triangleReductions=%zu boundaryFans=%zu diamonds=%zu "
                  "status=%s",
                  stage, processed, topologyChanges, edgeSwaps,
                  triangleReductions, boundaryFans, diamonds,
                  success ? "PASS" : "FAIL");
        return success;
      };
      std::size_t terminalPairsVisited = 0;
      std::size_t terminalPairsAccepted = 0;
      std::size_t terminalPairsRejectedInvalid = 0;
      std::size_t terminalPairsRejectedTopology = 0;
      std::size_t terminalPairsRejectedQuality = 0;
      std::size_t terminalPairsRejectedSize = 0;
      std::size_t terminalPairsRejectedGeometry = 0;
      if(CTX::instance()->mesh.packCleanupMethod != 1) {
        for(GFace *gf : m->getFaces()) {
          if(terminalSkippedFaces.find(gf) != terminalSkippedFaces.end())
            continue;
          const QuadOptimizer::TerminalTriangleRecombinationResult
            recombination = QuadOptimizer::recombineRemainingTrianglePairs(
              gf, terminalOptions);
          terminalPairsVisited += recombination.pairsVisited;
          terminalPairsAccepted += recombination.accepted;
          terminalPairsRejectedInvalid += recombination.rejectedInvalid;
          terminalPairsRejectedTopology += recombination.rejectedTopology;
          terminalPairsRejectedQuality += recombination.rejectedQuality;
          terminalPairsRejectedSize += recombination.rejectedSize;
          terminalPairsRejectedGeometry += recombination.rejectedGeometry;
          if(!recombination.success) {
            Msg::Warning("PACK skipped terminal triangle recombination on "
                         "face %d",
                         gf->tag());
          }
        }
      }
      if(terminalPairsAccepted) m->deleteVertexArrays();
      Msg::Info("PACK terminal triangle recombination: visited=%zu "
                "accepted=%zu rejectedInvalid=%zu rejectedTopology=%zu "
                "rejectedQuality=%zu rejectedSize=%zu rejectedGeometry=%zu",
                terminalPairsVisited, terminalPairsAccepted,
                terminalPairsRejectedInvalid, terminalPairsRejectedTopology,
                terminalPairsRejectedQuality, terminalPairsRejectedSize,
                terminalPairsRejectedGeometry);
      std::set<GFace *> terminalClosureFaces;
      for(GFace *gf : m->getFaces()) terminalClosureFaces.insert(gf);
      if(CTX::instance()->mesh.packCleanupMethod != 1)
        closeFinalPatterns(terminalClosureFaces, "terminal");
      else
        Msg::Info("PACK Fast staged cleanup: terminal recombination and "
                  "full-catalog restart disabled after final smoothing");

      // Audit every quad created above. Any fallback triangles introduced here
      // receive one final transactional T+T -> Q attempt below; the reducer can
      // only recreate a quad that passes every configured criterion after
      // mixed Winslow.
      std::size_t finalNonConvexOrInvalid = 0;
      std::size_t finalExcessiveWarping = 0;
      std::size_t finalSplitCount = 0;
      std::size_t finalRejected = 0;
      std::set<GFace *> finalSplitFaces;
      for(GFace *gf : m->getFaces()) {
        if(keepRawMatchedQuads ||
           terminalSkippedFaces.find(gf) != terminalSkippedFaces.end())
          continue;
        const double maximumWarpingDegrees =
          CTX::instance()->mesh.packCleanupMethod == 1 ?
            std::numeric_limits<double>::max() :
            QuadOptimizer::absoluteMaximumQuadWarpingDegrees;
        const WarpedQuadrangleSplitResult audit =
          splitExcessivelyWarpedQuadrangles(gf, maximumWarpingDegrees, {}, {},
                                            {}, {}, {}, true);
        finalNonConvexOrInvalid += audit.nonConvexOrInvalid;
        finalExcessiveWarping += audit.excessiveWarping;
        finalSplitCount += audit.split;
        const std::size_t rejected =
          audit.rejectedInvalid + audit.rejectedUnsupportedOrder;
        finalRejected += rejected;
        if(audit.split) finalSplitFaces.insert(gf);
        if(rejected) {
          Msg::Warning("PACK face %d retained %zu quadrangle%s rejected by "
                       "the final validity audit",
                       gf->tag(), rejected, rejected == 1 ? "" : "s");
        }
      }
      Msg::Info("PACK final quad audit: concaveOrInvalid=%zu "
                "excessiveWarping=%zu split=%zu rejected=%zu skippedFaces=%zu",
                finalNonConvexOrInvalid, finalExcessiveWarping, finalSplitCount,
                finalRejected, terminalSkippedFaces.size());
      std::size_t postFallbackVisited = 0;
      std::size_t postFallbackAccepted = 0;
      std::size_t postFallbackRejectedInvalid = 0;
      std::size_t postFallbackRejectedTopology = 0;
      std::size_t postFallbackRejectedQuality = 0;
      std::size_t postFallbackRejectedSize = 0;
      std::size_t postFallbackRejectedGeometry = 0;
      if(CTX::instance()->mesh.packCleanupMethod != 1) {
        for(GFace *gf : finalSplitFaces) {
          const QuadOptimizer::TerminalTriangleRecombinationResult
            recombination = QuadOptimizer::recombineRemainingTrianglePairs(
              gf, terminalOptions);
          postFallbackVisited += recombination.pairsVisited;
          postFallbackAccepted += recombination.accepted;
          postFallbackRejectedInvalid += recombination.rejectedInvalid;
          postFallbackRejectedTopology += recombination.rejectedTopology;
          postFallbackRejectedQuality += recombination.rejectedQuality;
          postFallbackRejectedSize += recombination.rejectedSize;
          postFallbackRejectedGeometry += recombination.rejectedGeometry;
          if(!recombination.success) {
            Msg::Warning("PACK skipped post-fallback triangle recombination on "
                         "face %d",
                         gf->tag());
          }
        }
      }
      if(postFallbackAccepted) m->deleteVertexArrays();
      if(!finalSplitFaces.empty() &&
         CTX::instance()->mesh.packCleanupMethod != 1)
        Msg::Info("PACK post-fallback triangle recombination: visited=%zu "
                  "accepted=%zu rejectedInvalid=%zu rejectedTopology=%zu "
                  "rejectedQuality=%zu rejectedSize=%zu "
                  "rejectedGeometry=%zu",
                  postFallbackVisited, postFallbackAccepted,
                  postFallbackRejectedInvalid, postFallbackRejectedTopology,
                  postFallbackRejectedQuality, postFallbackRejectedSize,
                  postFallbackRejectedGeometry);
      if(!finalSplitFaces.empty() &&
         CTX::instance()->mesh.packCleanupMethod != 1)
        closeFinalPatterns(finalSplitFaces, "post-fallback");

      // V2 owns the final topology cleanup and nodal Winslow sweeps. Run it
      // after PACK's validity fallbacks so no later split can invalidate the
      // final smoothing, and the file written by Gmsh is the optimized mesh.
      if(CTX::instance()->mesh.packCleanupMethod == 1) {
        Msg::Info("PACK final cleanup: V2 with final nodal Winslow");
        optimizeQuads(m, "OptimizeQuadsFast", false);
      }

      if(Msg::GetVerbosity() >= 4) {
        QuadOptimizer::SmallCavityOptimizerOptions auditOptions =
          terminalOptions;
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

  // Mesh.PackTargetSize is the single physical-size control for PACK. Also
  // recognize the historical uniform `-clmin h -clmax h` spelling: it must
  // drive the same bounded 3D pipeline on native CAD faces. Keep legacy
  // variable-size behavior otherwise. The scope restores the public context
  // after generation so a subsequent operation can use other settings.
  struct PackTargetSizeScope::State {
    bool active = false;
    int recombineAll = 0;
    int minCurveNodes = 0;
    int smoothingPasses = 0;
    int packing3D = 0;
    int forceAllPackedPoints = 0;
    double sizeFactor = 1.;
    double minimumSize = 0.;
    double maximumSize = 0.;
    double targetSize = 0.;
    double minimumEdgeLength = 0.;
    double maximumEdgeLength = 0.;

    State()
    {
      contextMeshOptions &mesh = CTX::instance()->mesh;
      const bool uniformLegacySize =
        !(mesh.packTargetSize > 0.) && mesh.lcMin > 0. && mesh.lcMax > 0. &&
        std::isfinite(mesh.lcMin) && std::isfinite(mesh.lcMax) &&
        std::abs(mesh.lcMax - mesh.lcMin) <=
          1.e-12 * std::max({1., mesh.lcMin, mesh.lcMax});
      active = mesh.algo2d == ALGO_2D_PACK_PRLGRMS &&
               (mesh.packTargetSize > 0. || uniformLegacySize) &&
               !(mesh.optimizeQuadsMinimumEdgeLength > 0.) &&
               !(mesh.optimizeQuadsMaximumEdgeLength > 0.);
      if(!active) return;

      recombineAll = mesh.recombineAll;
      minCurveNodes = mesh.minCurveNodes;
      smoothingPasses = mesh.nbSmoothing;
      packing3D = mesh.pack3D;
      forceAllPackedPoints = mesh.packForceAllPoints;
      sizeFactor = mesh.lcFactor;
      minimumSize = mesh.lcMin;
      maximumSize = mesh.lcMax;
      targetSize = mesh.packTargetSize;
      minimumEdgeLength = mesh.optimizeQuadsMinimumEdgeLength;
      maximumEdgeLength = mesh.optimizeQuadsMaximumEdgeLength;

      const double h = mesh.packTargetSize > 0. ?
                         mesh.packTargetSize :
                         .5 * (mesh.lcMin + mesh.lcMax);
      mesh.recombineAll = 1;
      mesh.minCurveNodes = 1;
      mesh.nbSmoothing =
        std::max(mesh.nbSmoothing, mesh.optimizeQuadsSmartLaplacian ? 3 : 5);
      mesh.pack3D = 1;
      mesh.packForceAllPoints = 1;
      mesh.lcFactor = 1.;
      mesh.lcMin = h;
      mesh.lcMax = h;
      mesh.packTargetSize = h;
      mesh.optimizeQuadsMinimumEdgeLength = .5 * h;
      mesh.optimizeQuadsMaximumEdgeLength = 2. * h;

      Msg::Info("PACK master target size: h=%g, admissible edges=[%g,%g], "
                "3D packing forced",
                h, mesh.optimizeQuadsMinimumEdgeLength,
                mesh.optimizeQuadsMaximumEdgeLength);
    }

    ~State()
    {
      if(!active) return;
      contextMeshOptions &mesh = CTX::instance()->mesh;
      mesh.recombineAll = recombineAll;
      mesh.minCurveNodes = minCurveNodes;
      mesh.nbSmoothing = smoothingPasses;
      mesh.pack3D = packing3D;
      mesh.packForceAllPoints = forceAllPackedPoints;
      mesh.lcFactor = sizeFactor;
      mesh.lcMin = minimumSize;
      mesh.lcMax = maximumSize;
      mesh.packTargetSize = targetSize;
      mesh.optimizeQuadsMinimumEdgeLength = minimumEdgeLength;
      mesh.optimizeQuadsMaximumEdgeLength = maximumEdgeLength;
    }
  };

  PackTargetSizeScope::PackTargetSizeScope() : _state(new State) {}
  PackTargetSizeScope::~PackTargetSizeScope() = default;

} // namespace QuadOptimizer
