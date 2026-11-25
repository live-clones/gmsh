// Extracted from MatGmsh src/matGmsh.cpp: local projection only.
// The geometry and acceptance rules are unchanged. Whole-stage rollback is
// implemented by the native pipeline that calls this optional stage.
#include "matGmsh.h"
#include "matLocalMidSurfaceProjection.h"

#include <Eigen/Core>
#include <Eigen/Eigenvalues>
#include <Eigen/Geometry>
#include <gmsh.h>

#include <algorithm>
#include <array>
#include <chrono>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stdexcept>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

namespace {

struct SizeTPairHash {
  std::size_t operator()(const std::pair<std::size_t, std::size_t> &pair) const
      noexcept
  {
    std::size_t seed = std::hash<std::size_t>{}(pair.first);
    seed ^= std::hash<std::size_t>{}(pair.second) +
            0x9e3779b97f4a7c15ULL + (seed << 6) + (seed >> 2);
    return seed;
  }
};

struct MatGmshEdgeHash {
  std::size_t operator()(const matGmshEdge &edge) const noexcept
  {
    const std::uint64_t packed =
        (static_cast<std::uint64_t>(static_cast<std::uint32_t>(edge.a))
         << 32) |
        static_cast<std::uint32_t>(edge.b);
    return std::hash<std::uint64_t>{}(packed);
  }
};

struct IntPairHash {
  std::size_t operator()(const std::pair<int, int> &pair) const noexcept
  {
    const std::uint64_t packed =
        (static_cast<std::uint64_t>(static_cast<std::uint32_t>(pair.first))
         << 32) |
        static_cast<std::uint32_t>(pair.second);
    return std::hash<std::uint64_t>{}(packed);
  }
};

struct CadSurfaceObservation {
  int seed = -1;
  int faceTag = -1;
  Eigen::Vector3d point = Eigen::Vector3d::Zero();
};

struct CadSurfacePairObservation {
  CadSurfaceObservation first;
  CadSurfaceObservation second;
};

struct ProjectionMatEdgeUse {
  int branch = -1;
  std::size_t faceIndex = 0;
  std::pair<int, int> supportPair;
};

struct SourceDirectionCacheEntry {
  CadSurfacePairObservation result;
  std::size_t winningVotes = 0;
  std::size_t totalVotes = 0;
  bool success = false;
};

struct ProjectionConnectivityCache {
  bool ready = false;
  std::unordered_map<matGmshEdge, std::vector<ProjectionMatEdgeUse>,
                     MatGmshEdgeHash> edgeUses;
  std::unordered_map<int, std::vector<int>> branchesAtVertex;
  std::unordered_map<int, std::vector<std::pair<int, int>>> pairsAtVertex;
  std::unordered_set<int> retainedVertices;
  std::unordered_map<
      int, std::vector<std::pair<std::size_t, std::size_t>>>
      incidentEdgeTopology;
  std::unordered_set<int> retainedBoundaryVertices;
  std::unordered_set<int> tripleLineVertices;
  std::unordered_map<int, std::vector<std::array<int, 3>>>
      tripleEdgeSupportsAtVertex;
  std::set<matGmshEdge> tripleLineEdges;
  std::unordered_map<int, std::vector<CadSurfacePairObservation>>
      repeatedSourcePairsAtTripleVertex;
  std::vector<int> candidates;
  std::unordered_set<int> simpleBoundaryCandidates;
  std::unordered_set<int> requiredSeeds;
  std::unordered_set<std::pair<int, int>, IntPairHash> requiredPairs;
  std::size_t tripleEdgesTwoCurveOneSurface = 0;
  std::size_t tripleEdgesTwoCurveOneSurfaceSameCurve = 0;
  std::size_t tripleEdgesUnexpectedClassification = 0;
  std::size_t tripleEdgesWithTwoManifoldCadCurves = 0;
  std::size_t tripleEdgesWhoseCadCurvesShareFace = 0;
  std::size_t tripleEdgesWhoseCadCurvesShareSupportPatch = 0;
  std::size_t tripleEdgesWithOneSharedSupportPatch = 0;
  std::size_t tripleEdgesWithSeveralSharedSupportPatches = 0;
  std::size_t tripleEdgesWhoseThirdFaceIsSharedSupport = 0;
  std::size_t tripleEdgesWithExactlyThreeMatDirections = 0;
  std::size_t tripleEdgesWithThreeRecoveredSourcePairs = 0;
  std::size_t tripleEdgesWithRepeatedGeometricSourcePair = 0;
  std::size_t tripleEdgesWithExactlyOneRepeatedGeometricSourcePair = 0;
  std::size_t tripleEdgesWithAllThreeGeometricSourcePairsEqual = 0;
  std::size_t recoveredDirectionWinningVotes = 0;
  std::size_t recoveredDirectionTotalVotes = 0;
  std::size_t tripleLineCandidateCount = 0;
  std::size_t nonSurfaceOppositeCandidates = 0;
  std::size_t regularCandidateCount = 0;
  std::size_t simpleBoundaryCandidateCount = 0;
  std::vector<std::array<int, 3>>
      tripleEdgeCadCurvePairsWithoutSharedSupport;
  std::map<std::array<int, 3>, std::size_t>
      tripleEdgeGeneratorDimensionPatterns;
};

struct ProjectionMidPlaneData {
  matLocalMidSurfaceProjection::Plane plane;
  double scale = 0.0;
};

struct ProjectionPlaneCache {
  bool ready = false;
  std::unordered_map<int, matLocalMidSurfaceProjection::Plane> planeAtSeed;
  std::unordered_map<std::pair<int, int>, ProjectionMidPlaneData,
                     IntPairHash>
      midPlaneByPair;
  std::vector<std::size_t> midPlaneOffsetsAtVertex;
  std::vector<const ProjectionMidPlaneData *> midPlanesAtVertex;
  std::size_t oneRingMissingTriangles = 0;
  std::size_t oneRingZeroArea = 0;
  std::size_t oneRingEigenFailures = 0;
  std::size_t oneRingInvalidPlanes = 0;
  std::size_t pointBisectorMidPlaneFallbacks = 0;
};

struct ProjectionFanTriangleLocation {
  std::size_t face = 0;
  std::size_t local = 0;
};

struct ProjectionFanAdjacencyTopology {
  ProjectionFanTriangleLocation first;
  ProjectionFanTriangleLocation second;
};

struct ProjectionFanNormalAdjacency {
  ProjectionFanTriangleLocation first;
  ProjectionFanTriangleLocation second;
  double originalCosine = 1.0;
};

struct ProjectionTopologyCache {
  bool ready = false;
  std::map<int, std::vector<std::size_t>> facesByBranch;
  std::vector<std::vector<int>> retainedFanVertices;
  std::vector<std::vector<double>> fanOrientationSigns;
  std::map<int, std::vector<ProjectionFanAdjacencyTopology>>
      fanAdjacencyTopologyByBranch;
  std::unordered_map<int, std::vector<std::size_t>> retainedFacesAtVertex;
  std::vector<std::size_t> regularizationNeighborOffsets;
  std::vector<int> regularizationNeighbors;
  std::vector<std::size_t> fanCornerScratchOffset;
  std::vector<std::size_t> fanCenterScratchOffset;
  std::size_t maximumBranchCornerCount = 0;
  std::size_t maximumBranchFaceCount = 0;
};

struct ProjectionSharedContext {
  ProjectionConnectivityCache connectivity;
  ProjectionPlaneCache planes;
  ProjectionTopologyCache topology;
  std::map<int, std::set<int>> adjacentCadFaces;
  std::unordered_map<std::pair<int, int>, bool, IntPairHash>
      cadProjectionMatches;
  std::unordered_map<std::size_t, SourceDirectionCacheEntry>
      sourceDirections;
};

} // namespace

void matGmsh::projectRegularBranchVerticesToLocalMidSurface(
    int iterations, double relativeTolerance,
    const std::map<int, std::set<int>> *patchesByCadFaceTag,
    bool storeDiagnostics)
{
  projectRegularBranchVerticesToLocalMidSurfaceImpl(
      iterations, relativeTolerance, patchesByCadFaceTag,
      storeDiagnostics, nullptr);
}

void matGmsh::projectRegularBranchVerticesToLocalMidSurfacePasses(
    int passes, int iterations, double relativeTolerance,
    const std::map<int, std::set<int>> *patchesByCadFaceTag,
    bool storeDiagnostics)
{
  if(passes <= 0)
    throw std::invalid_argument(
        "local mid-surface projection needs at least one pass");
  ProjectionSharedContext shared;
  for(int pass = 0; pass < passes; ++pass) {
    std::cout << "Local mid-surface projection pass " << (pass + 1)
              << '/' << passes << '\n';
    projectRegularBranchVerticesToLocalMidSurfaceImpl(
        iterations, relativeTolerance, patchesByCadFaceTag,
        storeDiagnostics, &shared);
  }
}

void matGmsh::projectRegularBranchVerticesToLocalMidSurfaceImpl(
    int iterations, double relativeTolerance,
    const std::map<int, std::set<int>> *patchesByCadFaceTag,
    bool storeDiagnostics, void *sharedContext)
{
  ScopedTimer timer(
      *this, "projectRegularBranchVerticesToLocalMidSurface");
  ProjectionSharedContext localSharedContext;
  ProjectionSharedContext &shared = sharedContext ?
      *static_cast<ProjectionSharedContext *>(sharedContext) :
      localSharedContext;
  const auto projectionStart = std::chrono::steady_clock::now();
  localMidSurfaceProjectionDiagnostics.clear();
  if(iterations <= 0 || !(relativeTolerance > 0.0) ||
     vor.faceColors.size() != vor.faces.size() ||
     del.triangles.size() % 3 != 0 ||
     del.seeds.size() % 3 != 0) {
    throw std::runtime_error(
        "Cannot project regular MAT vertices: incompatible input");
  }

  ProjectionConnectivityCache &connectivity = shared.connectivity;
  const bool buildConnectivity = !connectivity.ready;
  auto &edgeUses = connectivity.edgeUses;
  auto &branchesAtVertex = connectivity.branchesAtVertex;
  auto &pairsAtVertex = connectivity.pairsAtVertex;
  auto &retainedVertices = connectivity.retainedVertices;
  auto &incidentEdgeTopology = connectivity.incidentEdgeTopology;
  auto &retainedBoundaryVertices =
      connectivity.retainedBoundaryVertices;
  auto &tripleLineVertices = connectivity.tripleLineVertices;
  auto &tripleEdgeSupportsAtVertex =
      connectivity.tripleEdgeSupportsAtVertex;
  auto &tripleLineEdges = connectivity.tripleLineEdges;
  auto &repeatedSourcePairsAtTripleVertex =
      connectivity.repeatedSourcePairsAtTripleVertex;
  auto &candidates = connectivity.candidates;
  auto &simpleBoundaryCandidates =
      connectivity.simpleBoundaryCandidates;
  auto &requiredSeeds = connectivity.requiredSeeds;
  auto &requiredPairs = connectivity.requiredPairs;
  std::size_t &tripleEdgesTwoCurveOneSurface =
      connectivity.tripleEdgesTwoCurveOneSurface;
  std::size_t &tripleEdgesTwoCurveOneSurfaceSameCurve =
      connectivity.tripleEdgesTwoCurveOneSurfaceSameCurve;
  std::size_t &tripleEdgesUnexpectedClassification =
      connectivity.tripleEdgesUnexpectedClassification;
  std::size_t &tripleEdgesWithTwoManifoldCadCurves =
      connectivity.tripleEdgesWithTwoManifoldCadCurves;
  std::size_t &tripleEdgesWhoseCadCurvesShareFace =
      connectivity.tripleEdgesWhoseCadCurvesShareFace;
  std::size_t &tripleEdgesWhoseCadCurvesShareSupportPatch =
      connectivity.tripleEdgesWhoseCadCurvesShareSupportPatch;
  std::size_t &tripleEdgesWithOneSharedSupportPatch =
      connectivity.tripleEdgesWithOneSharedSupportPatch;
  std::size_t &tripleEdgesWithSeveralSharedSupportPatches =
      connectivity.tripleEdgesWithSeveralSharedSupportPatches;
  std::size_t &tripleEdgesWhoseThirdFaceIsSharedSupport =
      connectivity.tripleEdgesWhoseThirdFaceIsSharedSupport;
  std::size_t &tripleEdgesWithExactlyThreeMatDirections =
      connectivity.tripleEdgesWithExactlyThreeMatDirections;
  std::size_t &tripleEdgesWithThreeRecoveredSourcePairs =
      connectivity.tripleEdgesWithThreeRecoveredSourcePairs;
  std::size_t &tripleEdgesWithRepeatedGeometricSourcePair =
      connectivity.tripleEdgesWithRepeatedGeometricSourcePair;
  std::size_t &tripleEdgesWithExactlyOneRepeatedGeometricSourcePair =
      connectivity.tripleEdgesWithExactlyOneRepeatedGeometricSourcePair;
  std::size_t &tripleEdgesWithAllThreeGeometricSourcePairsEqual =
      connectivity.tripleEdgesWithAllThreeGeometricSourcePairsEqual;
  std::size_t &recoveredDirectionWinningVotes =
      connectivity.recoveredDirectionWinningVotes;
  std::size_t &recoveredDirectionTotalVotes =
      connectivity.recoveredDirectionTotalVotes;
  auto &tripleEdgeCadCurvePairsWithoutSharedSupport =
      connectivity.tripleEdgeCadCurvePairsWithoutSharedSupport;
  auto &tripleEdgeGeneratorDimensionPatterns =
      connectivity.tripleEdgeGeneratorDimensionPatterns;
  std::size_t &tripleLineCandidateCount =
      connectivity.tripleLineCandidateCount;
  std::size_t &nonSurfaceOppositeCandidates =
      connectivity.nonSurfaceOppositeCandidates;
  std::size_t &regularCandidateCount =
      connectivity.regularCandidateCount;
  std::size_t &simpleBoundaryCandidateCount =
      connectivity.simpleBoundaryCandidateCount;

  if(buildConnectivity) {
    edgeUses.reserve(2 * vor.faces.size());
    std::vector<int> vertices;
    for(std::size_t faceIndex = 0; faceIndex < vor.faces.size();
        ++faceIndex) {
      const int branch = vor.faceColors[faceIndex];
      if(branch < 0) continue;
      const VoronoiFace &face = vor.faces[faceIndex];
      vertices.clear();
      vertices.reserve(face.verts.size());
      for(const int vertex : face.verts)
        if(vertex >= 0 &&
           3 * vertex + 2 < static_cast<int>(vor.vertices.size()))
          vertices.push_back(vertex);
      if(vertices.size() < 3 || face.edge.a < 0 || face.edge.b < 0)
        continue;

      const std::pair<int, int> supportPair = {
          std::min(face.edge.a, face.edge.b),
          std::max(face.edge.a, face.edge.b)};
      for(const int vertex : vertices) {
        retainedVertices.insert(vertex);
        branchesAtVertex[vertex].push_back(branch);
        pairsAtVertex[vertex].push_back(supportPair);
      }
      for(std::size_t local = 0; local < vertices.size(); ++local) {
        const int a = vertices[local];
        const int b = vertices[(local + 1) % vertices.size()];
        if(a != b)
          edgeUses[matGmshEdge(a, b)].push_back(
              {branch, faceIndex, supportPair});
      }
    }

    for(auto &entry : branchesAtVertex) {
      std::vector<int> &values = entry.second;
      std::sort(values.begin(), values.end());
      values.erase(std::unique(values.begin(), values.end()), values.end());
    }
    for(auto &entry : pairsAtVertex) {
      std::vector<std::pair<int, int>> &values = entry.second;
      std::sort(values.begin(), values.end());
      values.erase(std::unique(values.begin(), values.end()), values.end());
    }
  }
  const auto projectionBaseConnectivityReady =
      std::chrono::steady_clock::now();
  std::map<int, std::set<int>> &adjacentCadFacesCache =
      shared.adjacentCadFaces;
  const auto adjacentCadFaces = [&](int curveTag) -> const std::set<int> & {
    auto insertion = adjacentCadFacesCache.try_emplace(curveTag);
    if(insertion.second) {
      std::vector<int> upward;
      std::vector<int> downward;
      try {
        gmsh::model::getAdjacencies(1, curveTag, upward, downward);
      }
      catch(...) {
        upward.clear();
      }
      insertion.first->second.insert(upward.begin(), upward.end());
    }
    return insertion.first->second;
  };
  const auto supportPatchesOfFaces = [&](const std::set<int> &faces) {
    std::set<int> patches;
    if(!patchesByCadFaceTag) return patches;
    for(const int face : faces) {
      const auto memberships = patchesByCadFaceTag->find(face);
      if(memberships != patchesByCadFaceTag->end())
        patches.insert(
            memberships->second.begin(), memberships->second.end());
    }
    return patches;
  };

  double cadReferenceLength = 0.0;
  if(!del.seeds.empty()) {
    Eigen::Vector3d minimum = Eigen::Vector3d::Constant(
        std::numeric_limits<double>::infinity());
    Eigen::Vector3d maximum = Eigen::Vector3d::Constant(
        -std::numeric_limits<double>::infinity());
    for(std::size_t seed = 0; 3 * seed + 2 < del.seeds.size(); ++seed) {
      const Eigen::Vector3d point(
          del.seeds[3 * seed], del.seeds[3 * seed + 1],
          del.seeds[3 * seed + 2]);
      minimum = minimum.cwiseMin(point);
      maximum = maximum.cwiseMax(point);
    }
    cadReferenceLength = (maximum - minimum).norm();
  }
  const double sameCadSurfaceTolerance =
      1e-7 * std::max(1.0, cadReferenceLength);
  const auto surfacePointObservation = [&](int seed) {
    CadSurfaceObservation observation;
    if(seed < 0 || seed >= static_cast<int>(del.onWhat.size()) ||
       del.onWhat[seed].first != 2 ||
       3 * seed + 2 >= static_cast<int>(del.seeds.size()))
      return observation;
    observation.seed = seed;
    observation.faceTag = del.onWhat[seed].second;
    observation.point = Eigen::Vector3d(
        del.seeds[3 * seed], del.seeds[3 * seed + 1],
        del.seeds[3 * seed + 2]);
    return observation;
  };
  const auto observedSurfacePair = [&](std::size_t faceIndex,
                                       CadSurfacePairObservation &pair) {
    if(faceIndex >= vor.faces.size()) return false;
    const VoronoiFace &face = vor.faces[faceIndex];
    pair.first = surfacePointObservation(face.edge.a);
    pair.second = surfacePointObservation(face.edge.b);
    return pair.first.faceTag >= 0 && pair.second.faceTag >= 0 &&
        pair.first.faceTag != pair.second.faceTag;
  };
  auto &cadProjectionMatchCache = shared.cadProjectionMatches;
  const auto sameCadSurface = [&](const CadSurfaceObservation &first,
                                  const CadSurfaceObservation &second) {
    if(first.faceTag < 0 || second.faceTag < 0) return false;
    if(first.faceTag == second.faceTag) return true;
    const auto projectionMatches = [&](const CadSurfaceObservation &source,
                                       int targetFace) {
      const std::pair<int, int> key = {source.seed, targetFace};
      const auto cached = cadProjectionMatchCache.find(key);
      if(cached != cadProjectionMatchCache.end()) return cached->second;
      const bool matches = [&]() {
        try {
          std::vector<double> closest;
          std::vector<double> targetUv;
          gmsh::model::getClosestPoint(
              2, targetFace,
              {source.point.x(), source.point.y(), source.point.z()},
              closest, targetUv);
          if(closest.size() < 3 || targetUv.size() < 2) return false;
          const Eigen::Vector3d targetPoint(
              closest[0], closest[1], closest[2]);
          if((targetPoint - source.point).norm() >
             sameCadSurfaceTolerance)
            return false;

          std::vector<double> sourceClosest;
          std::vector<double> sourceUv;
          gmsh::model::getClosestPoint(
              2, source.faceTag,
              {source.point.x(), source.point.y(), source.point.z()},
              sourceClosest, sourceUv);
          if(sourceUv.size() < 2) return false;
          std::vector<double> sourceNormal;
          std::vector<double> targetNormal;
          gmsh::model::getNormal(
              source.faceTag, sourceUv, sourceNormal);
          gmsh::model::getNormal(targetFace, targetUv, targetNormal);
          if(sourceNormal.size() < 3 || targetNormal.size() < 3)
            return false;
          Eigen::Vector3d firstNormal(
              sourceNormal[0], sourceNormal[1], sourceNormal[2]);
          Eigen::Vector3d secondNormal(
              targetNormal[0], targetNormal[1], targetNormal[2]);
          if(!(firstNormal.norm() > 0.0) ||
             !(secondNormal.norm() > 0.0))
            return false;
          firstNormal.normalize();
          secondNormal.normalize();
          return std::abs(firstNormal.dot(secondNormal)) >= 0.999999;
        }
        catch(...) {
          return false;
        }
      }();
      cadProjectionMatchCache.emplace(key, matches);
      return matches;
    };
    return projectionMatches(first, second.faceTag) &&
        projectionMatches(second, first.faceTag);
  };
  const auto sameCadSurfacePair = [&](
      const CadSurfacePairObservation &first,
      const CadSurfacePairObservation &second) {
    return (sameCadSurface(first.first, second.first) &&
            sameCadSurface(first.second, second.second)) ||
        (sameCadSurface(first.first, second.second) &&
         sameCadSurface(first.second, second.first));
  };
  std::vector<std::uint32_t> sourceDirectionVisitedEpoch(
      vor.faces.size(), 0);
  std::uint32_t nextSourceDirectionVisitedEpoch = 0;
  std::vector<std::pair<std::size_t, int>> sourceDirectionPending;
  sourceDirectionPending.reserve(4000);
  std::vector<int> sourceDirectionFaceVertices;
  const auto sourcePairAlongMatDirection = [&](
      const ProjectionMatEdgeUse &start,
      CadSurfacePairObservation &result,
      std::size_t &winningVotes, std::size_t &totalVotes) {
    const std::size_t cacheKey = start.faceIndex;
    const auto cachedDirection = shared.sourceDirections.find(cacheKey);
    if(cachedDirection != shared.sourceDirections.end()) {
      result = cachedDirection->second.result;
      winningVotes = cachedDirection->second.winningVotes;
      totalVotes = cachedDirection->second.totalVotes;
      return cachedDirection->second.success;
    }
    struct Cluster {
      CadSurfacePairObservation representative;
      std::size_t votes = 0;
    };
    std::vector<Cluster> clusters;
    clusters.reserve(4);
    ++nextSourceDirectionVisitedEpoch;
    if(nextSourceDirectionVisitedEpoch == 0) {
      std::fill(sourceDirectionVisitedEpoch.begin(),
                sourceDirectionVisitedEpoch.end(), 0);
      ++nextSourceDirectionVisitedEpoch;
    }
    sourceDirectionPending.clear();
    sourceDirectionPending.push_back({start.faceIndex, 0});
    sourceDirectionVisitedEpoch[start.faceIndex] =
        nextSourceDirectionVisitedEpoch;
    std::size_t pendingHead = 0;
    std::size_t visitedCount = 1;
    constexpr int minimumRing = 3;
    constexpr int maximumRing = 40;
    constexpr std::size_t maximumVotes = 48;
    constexpr std::size_t maximumVisitedFaces = 4000;
    totalVotes = 0;
    while(pendingHead < sourceDirectionPending.size() &&
          totalVotes < maximumVotes &&
          visitedCount <= maximumVisitedFaces) {
      const auto current = sourceDirectionPending[pendingHead++];
      const std::size_t faceIndex = current.first;
      const int ring = current.second;
      if(faceIndex >= vor.faces.size()) continue;
      if(ring >= minimumRing) {
        CadSurfacePairObservation observation;
        if(observedSurfacePair(faceIndex, observation)) {
          auto cluster = std::find_if(
              clusters.begin(), clusters.end(), [&](const Cluster &entry) {
                return sameCadSurfacePair(
                    entry.representative, observation);
              });
          if(cluster == clusters.end())
            clusters.push_back({observation, 1});
          else
            ++cluster->votes;
          ++totalVotes;
        }
      }
      if(ring >= maximumRing) continue;
      const VoronoiFace &face = vor.faces[faceIndex];
      sourceDirectionFaceVertices.clear();
      sourceDirectionFaceVertices.reserve(face.verts.size());
      for(const int vertex : face.verts)
        if(vertex >= 0) sourceDirectionFaceVertices.push_back(vertex);
      for(std::size_t local = 0;
          local < sourceDirectionFaceVertices.size(); ++local) {
        const matGmshEdge edge(
            sourceDirectionFaceVertices[local],
            sourceDirectionFaceVertices[
                (local + 1) % sourceDirectionFaceVertices.size()]);
        const auto uses = edgeUses.find(edge);
        if(uses == edgeUses.end() || uses->second.size() >= 3) continue;
        for(const ProjectionMatEdgeUse &neighbor : uses->second) {
          if(neighbor.branch != start.branch ||
             neighbor.faceIndex == faceIndex ||
             sourceDirectionVisitedEpoch[neighbor.faceIndex] ==
                 nextSourceDirectionVisitedEpoch)
            continue;
          sourceDirectionVisitedEpoch[neighbor.faceIndex] =
              nextSourceDirectionVisitedEpoch;
          ++visitedCount;
          sourceDirectionPending.push_back(
              {neighbor.faceIndex, ring + 1});
        }
      }
    }
    if(clusters.empty()) {
      shared.sourceDirections.emplace(
          cacheKey, SourceDirectionCacheEntry{});
      return false;
    }
    const auto winner = std::max_element(
        clusters.begin(), clusters.end(),
        [](const Cluster &first, const Cluster &second) {
          return first.votes < second.votes;
        });
    result = winner->representative;
    winningVotes = winner->votes;
    const bool success =
        winningVotes >= 4 && winningVotes * 2 >= totalVotes;
    shared.sourceDirections.emplace(
        cacheKey, SourceDirectionCacheEntry{
                      result, winningVotes, totalVotes, success});
    return success;
  };
  if(buildConnectivity) for(const auto &entry : edgeUses) {
    std::size_t branchCount = 0;
    for(std::size_t use = 0; use < entry.second.size(); ++use) {
      bool firstUseOfBranch = true;
      for(std::size_t previous = 0; previous < use; ++previous)
        if(entry.second[previous].branch == entry.second[use].branch) {
          firstUseOfBranch = false;
          break;
        }
      if(firstUseOfBranch) ++branchCount;
    }
    const std::pair<std::size_t, std::size_t> counts = {
        entry.second.size(), branchCount};
    incidentEdgeTopology[entry.first.a].push_back(counts);
    incidentEdgeTopology[entry.first.b].push_back(counts);
    // A retained MAT triple line is an edge used by at least three retained
    // sheets. Its vertices must be projected together with the regular MAT:
    // the edge adjacency and its three supports are therefore production
    // data, not optional diagnostics.
    if(entry.second.size() >= 3) {
      tripleLineVertices.insert(entry.first.a);
      tripleLineVertices.insert(entry.first.b);
      tripleLineEdges.insert(entry.first);
      if(entry.second.size() == 3) {
        ++tripleEdgesWithExactlyThreeMatDirections;
        std::array<CadSurfacePairObservation, 3> recoveredPairs;
        bool allRecovered = true;
        for(std::size_t direction = 0; direction < 3; ++direction) {
          std::size_t winningVotes = 0;
          std::size_t totalVotes = 0;
          if(!sourcePairAlongMatDirection(
                 entry.second[direction], recoveredPairs[direction],
                 winningVotes, totalVotes))
            allRecovered = false;
          recoveredDirectionWinningVotes += winningVotes;
          recoveredDirectionTotalVotes += totalVotes;
        }
        if(allRecovered) {
          ++tripleEdgesWithThreeRecoveredSourcePairs;
          const bool same01 = sameCadSurfacePair(
              recoveredPairs[0], recoveredPairs[1]);
          const bool same12 = sameCadSurfacePair(
              recoveredPairs[1], recoveredPairs[2]);
          const bool same20 = sameCadSurfacePair(
              recoveredPairs[2], recoveredPairs[0]);
          const int repeatedPairs =
              static_cast<int>(same01) + static_cast<int>(same12) +
              static_cast<int>(same20);
          if(repeatedPairs > 0)
            ++tripleEdgesWithRepeatedGeometricSourcePair;
          if(repeatedPairs == 1) {
            ++tripleEdgesWithExactlyOneRepeatedGeometricSourcePair;
            const CadSurfacePairObservation &repeatedPair = same01 ?
                recoveredPairs[0] :
                (same12 ? recoveredPairs[1] : recoveredPairs[2]);
            repeatedSourcePairsAtTripleVertex[entry.first.a].push_back(
                repeatedPair);
            repeatedSourcePairsAtTripleVertex[entry.first.b].push_back(
                repeatedPair);
          }
          if(repeatedPairs == 3)
            ++tripleEdgesWithAllThreeGeometricSourcePairsEqual;
        }
      }
      std::set<int> supportSeeds;
      for(const ProjectionMatEdgeUse &use : entry.second) {
        supportSeeds.insert(use.supportPair.first);
        supportSeeds.insert(use.supportPair.second);
      }
      if(supportSeeds.size() == 3) {
        std::array<int, 3> supports;
        std::copy(supportSeeds.begin(), supportSeeds.end(), supports.begin());
        std::size_t curveSupports = 0;
        std::size_t surfaceSupports = 0;
        std::set<int> curveTags;
        std::set<int> surfaceTags;
        std::array<int, 3> dimensions = {-1, -1, -1};
        std::size_t localSupport = 0;
        for(const int support : supports) {
          if(support < 0 ||
             support >= static_cast<int>(del.onWhat.size())) {
            ++localSupport;
            continue;
          }
          dimensions[localSupport++] = del.onWhat[support].first;
          if(del.onWhat[support].first == 1) {
            ++curveSupports;
            curveTags.insert(del.onWhat[support].second);
          }
          else if(del.onWhat[support].first == 2) {
            ++surfaceSupports;
            surfaceTags.insert(del.onWhat[support].second);
          }
        }
        std::sort(dimensions.begin(), dimensions.end());
        ++tripleEdgeGeneratorDimensionPatterns[dimensions];
        if(curveSupports == 2 && surfaceSupports == 1) {
          ++tripleEdgesTwoCurveOneSurface;
          if(curveTags.size() == 1)
            ++tripleEdgesTwoCurveOneSurfaceSameCurve;
          if(curveTags.size() == 2 && surfaceTags.size() == 1) {
            const int firstCurve = *curveTags.begin();
            const int secondCurve = *std::next(curveTags.begin());
            const int thirdFace = *surfaceTags.begin();
            const std::set<int> &firstFaces =
                adjacentCadFaces(firstCurve);
            const std::set<int> &secondFaces =
                adjacentCadFaces(secondCurve);
            if(firstFaces.size() == 2 && secondFaces.size() == 2)
              ++tripleEdgesWithTwoManifoldCadCurves;
            std::set<int> commonFaces;
            std::set_intersection(
                firstFaces.begin(), firstFaces.end(),
                secondFaces.begin(), secondFaces.end(),
                std::inserter(commonFaces, commonFaces.end()));
            if(!commonFaces.empty())
              ++tripleEdgesWhoseCadCurvesShareFace;

            const std::set<int> firstPatches =
                supportPatchesOfFaces(firstFaces);
            const std::set<int> secondPatches =
                supportPatchesOfFaces(secondFaces);
            std::set<int> sharedPatches;
            std::set_intersection(
                firstPatches.begin(), firstPatches.end(),
                secondPatches.begin(), secondPatches.end(),
                std::inserter(sharedPatches, sharedPatches.end()));
            if(!sharedPatches.empty()) {
              ++tripleEdgesWhoseCadCurvesShareSupportPatch;
              if(sharedPatches.size() == 1)
                ++tripleEdgesWithOneSharedSupportPatch;
              else
                ++tripleEdgesWithSeveralSharedSupportPatches;
            }
            else if(tripleEdgeCadCurvePairsWithoutSharedSupport.size() < 12) {
              tripleEdgeCadCurvePairsWithoutSharedSupport.push_back(
                  {firstCurve, secondCurve, thirdFace});
            }

            const std::set<int> thirdFaceSet = {thirdFace};
            const std::set<int> thirdFacePatches =
                supportPatchesOfFaces(thirdFaceSet);
            bool thirdFaceSharesSupport = false;
            for(const int patch : thirdFacePatches)
              if(sharedPatches.count(patch) != 0) {
                thirdFaceSharesSupport = true;
                break;
              }
            if(thirdFaceSharesSupport)
              ++tripleEdgesWhoseThirdFaceIsSharedSupport;
          }
        }
        else {
          ++tripleEdgesUnexpectedClassification;
        }
        tripleEdgeSupportsAtVertex[entry.first.a].push_back(supports);
        tripleEdgeSupportsAtVertex[entry.first.b].push_back(supports);
      }
    }
    if(entry.second.size() == 1 && branchCount == 1) {
      retainedBoundaryVertices.insert(entry.first.a);
      retainedBoundaryVertices.insert(entry.first.b);
    }
  }
  const auto projectionTripleConnectivityReady =
      std::chrono::steady_clock::now();

  if(buildConnectivity) for(const int vertex : retainedVertices) {
    const auto branches = branchesAtVertex.find(vertex);
    const auto pairs = pairsAtVertex.find(vertex);
    const auto incident = incidentEdgeTopology.find(vertex);
    if(branches == branchesAtVertex.end() || branches->second.empty() ||
       pairs == pairsAtVertex.end() || pairs->second.empty() ||
       incident == incidentEdgeTopology.end())
      continue;
    const bool tripleLine = tripleLineVertices.count(vertex) != 0;
    const matLocalMidSurfaceProjection::RetainedVertexTopology topology =
        matLocalMidSurfaceProjection::classifyRetainedVertexTopology(
            incident->second);
    if(!matLocalMidSurfaceProjection::
           allOppositePairsAreSurfaceClassifiedImpl(del.onWhat,
                                                    pairs->second))
      ++nonSurfaceOppositeCandidates;
    candidates.push_back(vertex);
    if(tripleLine) {
      ++tripleLineCandidateCount;
    }
    else if(topology == matLocalMidSurfaceProjection::
                       RetainedVertexTopology::SimpleBoundary) {
      simpleBoundaryCandidates.insert(vertex);
      ++simpleBoundaryCandidateCount;
    }
    else {
      ++regularCandidateCount;
    }
  }
  const auto projectionConnectivityReady =
      std::chrono::steady_clock::now();

  // Build the triangulated 1-ring mean planes for the complete retained MAT,
  // including the triple-line vertices projected onto their common line.
  if(buildConnectivity) for(const int vertex : retainedVertices) {
    const auto pairs = pairsAtVertex.find(vertex);
    if(pairs == pairsAtVertex.end()) continue;
    for(const auto &pair : pairs->second) {
      requiredPairs.insert(pair);
      requiredSeeds.insert(pair.first);
      requiredSeeds.insert(pair.second);
    }
  }
  connectivity.ready = true;

  ProjectionPlaneCache &planeCache = shared.planes;
  const bool buildPlanes = !planeCache.ready;
  auto &planeAtSeed = planeCache.planeAtSeed;
  auto &midPlaneByPair = planeCache.midPlaneByPair;
  std::size_t &oneRingMissingTriangles =
      planeCache.oneRingMissingTriangles;
  std::size_t &oneRingZeroArea = planeCache.oneRingZeroArea;
  std::size_t &oneRingEigenFailures = planeCache.oneRingEigenFailures;
  std::size_t &oneRingInvalidPlanes = planeCache.oneRingInvalidPlanes;
  std::size_t &pointBisectorMidPlaneFallbacks =
      planeCache.pointBisectorMidPlaneFallbacks;
  const std::size_t surfacePointCount = del.seeds.size() / 3;
  std::unordered_map<int, std::vector<std::size_t>> trianglesAtSeed;
  if(buildPlanes) {
    trianglesAtSeed.reserve(requiredSeeds.size());
    for(std::size_t triangle = 0; triangle < del.triangles.size() / 3;
        ++triangle) {
      for(int local = 0; local < 3; ++local) {
        const std::size_t seed = del.triangles[3 * triangle + local];
        if(seed < surfacePointCount &&
           requiredSeeds.count(static_cast<int>(seed)) != 0)
          trianglesAtSeed[static_cast<int>(seed)].push_back(triangle);
      }
    }
  }

  const auto surfacePoint = [&](std::size_t seed) {
    return Eigen::Vector3d(
        del.seeds[3 * seed], del.seeds[3 * seed + 1],
        del.seeds[3 * seed + 2]);
  };

  const auto closestCadSurfacePlane = [](
      int tag, const Eigen::Vector3d &query,
      matLocalMidSurfaceProjection::Plane &plane) {
    if(tag < 0 || !query.allFinite()) return false;
    try {
      std::vector<double> coordinates;
      std::vector<double> uv;
      gmsh::model::getClosestPoint(
          2, tag, {query.x(), query.y(), query.z()}, coordinates, uv);
      if(coordinates.size() < 3 || uv.size() < 2) return false;
      std::vector<double> normal;
      gmsh::model::getNormal(tag, uv, normal);
      if(normal.size() < 3) return false;
      plane.origin = Eigen::Vector3d(
          coordinates[0], coordinates[1], coordinates[2]);
      plane.normal =
          Eigen::Vector3d(normal[0], normal[1], normal[2]);
      const double norm = plane.normal.norm();
      if(!(norm > std::numeric_limits<double>::min())) return false;
      plane.normal /= norm;
      return plane.origin.allFinite() && plane.normal.allFinite();
    }
    catch(...) {
      return false;
    }
  };

  // The pair repeated in two of the three incident sheets identifies the
  // regular MAT sheet that continues through the junction.  Project onto the
  // local plane midway between the two exact CAD tangent planes.  The second
  // global projection pass rebuilds this local linearization after the move.
  const auto projectToCadMeanSurface = [&closestCadSurfacePlane](
      const CadSurfacePairObservation &pair,
      const Eigen::Vector3d &query, Eigen::Vector3d &meanPoint,
      Eigen::Vector3d &contactA, Eigen::Vector3d &contactB) {
    matLocalMidSurfaceProjection::Plane first;
    matLocalMidSurfaceProjection::Plane second;
    matLocalMidSurfaceProjection::Plane midway;
    if(!closestCadSurfacePlane(pair.first.faceTag, query, first) ||
       !closestCadSurfacePlane(pair.second.faceTag, query, second) ||
       !matLocalMidSurfaceProjection::planeMidwayBetween(
           first, second, midway))
      return false;
    contactA = first.origin;
    contactB = second.origin;
    meanPoint =
        matLocalMidSurfaceProjection::projectOntoPlane(query, midway);
    return meanPoint.allFinite();
  };

  // Fit one area-weighted mean plane to the complete triangle 1-ring of each
  // opposite surface point. In particular, a planar 1-ring is reproduced to
  // roundoff instead of being clipped to the closest individual triangle.
  if(buildPlanes) planeAtSeed.reserve(requiredSeeds.size());
  if(buildPlanes) for(const int seed : requiredSeeds) {
    const auto incident = trianglesAtSeed.find(seed);
    if(incident == trianglesAtSeed.end() || incident->second.empty()) {
      ++oneRingMissingTriangles;
      continue;
    }

    double totalArea = 0.0;
    Eigen::Vector3d firstMoment = Eigen::Vector3d::Zero();
    Eigen::Vector3d orientedNormal = Eigen::Vector3d::Zero();
    for(const std::size_t triangle : incident->second) {
      const Eigen::Vector3d a = surfacePoint(del.triangles[3 * triangle]);
      const Eigen::Vector3d b = surfacePoint(del.triangles[3 * triangle + 1]);
      const Eigen::Vector3d c = surfacePoint(del.triangles[3 * triangle + 2]);
      const Eigen::Vector3d cross = (b - a).cross(c - a);
      const double area = 0.5 * cross.norm();
      if(!(area > std::numeric_limits<double>::min())) continue;
      totalArea += area;
      firstMoment += area * (a + b + c) / 3.0;
      orientedNormal += cross;
    }
    if(!(totalArea > 0.0) || !std::isfinite(totalArea)) {
      ++oneRingZeroArea;
      continue;
    }

    matLocalMidSurfaceProjection::Plane plane;
    plane.origin = firstMoment / totalArea;
    Eigen::Matrix3d covariance = Eigen::Matrix3d::Zero();
    for(const std::size_t triangle : incident->second) {
      const Eigen::Vector3d a = surfacePoint(del.triangles[3 * triangle]);
      const Eigen::Vector3d b = surfacePoint(del.triangles[3 * triangle + 1]);
      const Eigen::Vector3d c = surfacePoint(del.triangles[3 * triangle + 2]);
      const double area = 0.5 * ((b - a).cross(c - a)).norm();
      if(!(area > std::numeric_limits<double>::min())) continue;
      const Eigen::Vector3d q0 = a - plane.origin;
      const Eigen::Vector3d q1 = b - plane.origin;
      const Eigen::Vector3d q2 = c - plane.origin;
      const Eigen::Vector3d sum = q0 + q1 + q2;
      covariance += (area / 12.0) *
          (sum * sum.transpose() + q0 * q0.transpose() +
           q1 * q1.transpose() + q2 * q2.transpose());
    }
    covariance /= totalArea;
    Eigen::SelfAdjointEigenSolver<Eigen::Matrix3d> eigen(covariance);
    if(eigen.info() != Eigen::Success) {
      ++oneRingEigenFailures;
      continue;
    }
    plane.normal = eigen.eigenvectors().col(0).normalized();
    if(plane.normal.dot(orientedNormal) < 0.0) plane.normal = -plane.normal;
    if(!plane.origin.allFinite() || !plane.normal.allFinite()) {
      ++oneRingInvalidPlanes;
      continue;
    }
    planeAtSeed.emplace(seed, plane);
  }

  if(buildPlanes) midPlaneByPair.reserve(requiredPairs.size());
  if(buildPlanes) for(const auto &pair : requiredPairs) {
      const auto first = planeAtSeed.find(pair.first);
      const auto second = planeAtSeed.find(pair.second);
      ProjectionMidPlaneData data;
      bool fitted = first != planeAtSeed.end() &&
                    second != planeAtSeed.end() &&
                    matLocalMidSurfaceProjection::planeMidwayBetween(
                        first->second, second->second, data.plane);
      if(fitted) {
        data.scale =
            (second->second.origin - first->second.origin).norm();
      }
      else {
        // Surface-classified mesh vertices should normally have usable
        // triangle 1-rings.  If a degenerate local ring nevertheless makes
        // the PCA fit unavailable, the Euclidean bisector of the two
        // opposite points is still an exact, finite medial constraint.  It
        // is preferable to leaving an isolated MAT vertex unprojected.
        const Eigen::Vector3d firstPoint = surfacePoint(pair.first);
        const Eigen::Vector3d secondPoint = surfacePoint(pair.second);
        const Eigen::Vector3d separation = secondPoint - firstPoint;
        data.scale = separation.norm();
        if(!(data.scale > std::numeric_limits<double>::min()) ||
           !std::isfinite(data.scale))
          continue;
        data.plane.origin = 0.5 * (firstPoint + secondPoint);
        data.plane.normal = separation / data.scale;
        ++pointBisectorMidPlaneFallbacks;
      }
      midPlaneByPair.emplace(pair, data);
  }
  if(buildPlanes) {
    const std::size_t vertexCount = vor.vertices.size() / 3;
    planeCache.midPlaneOffsetsAtVertex.assign(vertexCount + 1, 0);
    for(const auto &entry : pairsAtVertex) {
      const int vertex = entry.first;
      if(vertex < 0 || vertex >= static_cast<int>(vertexCount)) continue;
      std::size_t count = 0;
      for(const auto &pair : entry.second)
        if(midPlaneByPair.find(pair) != midPlaneByPair.end()) ++count;
      planeCache.midPlaneOffsetsAtVertex[vertex + 1] = count;
    }
    std::partial_sum(planeCache.midPlaneOffsetsAtVertex.begin(),
                     planeCache.midPlaneOffsetsAtVertex.end(),
                     planeCache.midPlaneOffsetsAtVertex.begin());
    planeCache.midPlanesAtVertex.resize(
        planeCache.midPlaneOffsetsAtVertex.back());
    std::vector<std::size_t> cursor =
        planeCache.midPlaneOffsetsAtVertex;
    for(const auto &entry : pairsAtVertex) {
      const int vertex = entry.first;
      if(vertex < 0 || vertex >= static_cast<int>(vertexCount)) continue;
      for(const auto &pair : entry.second) {
        const auto mid = midPlaneByPair.find(pair);
        if(mid != midPlaneByPair.end())
          planeCache.midPlanesAtVertex[cursor[vertex]++] = &mid->second;
      }
    }
  }
  planeCache.ready = true;
  const auto projectionPlanesReady =
      std::chrono::steady_clock::now();

  // The correction below is a gradient step for the least-squares distance
  // to all local mid-planes.  Use the matching RMS residual for acceptance:
  // an L1 check can increase when one plane gets slightly worse even though
  // the global least-squares projection has strictly improved.
  const auto projectionResidual =
      [&](const Eigen::Vector3d &point, int vertex) {
    if(vertex < 0 ||
       vertex + 1 >=
           static_cast<int>(planeCache.midPlaneOffsetsAtVertex.size()))
      return std::numeric_limits<double>::infinity();
    double squaredResidual = 0.0;
    const std::size_t begin =
        planeCache.midPlaneOffsetsAtVertex[vertex];
    const std::size_t end =
        planeCache.midPlaneOffsetsAtVertex[vertex + 1];
    for(std::size_t planeIndex = begin; planeIndex < end; ++planeIndex) {
      const ProjectionMidPlaneData &mid =
          *planeCache.midPlanesAtVertex[planeIndex];
      const double signedDistance = mid.plane.normal.dot(
          point - mid.plane.origin);
      squaredResidual += signedDistance * signedDistance;
    }
    return end > begin ?
        std::sqrt(squaredResidual / static_cast<double>(end - begin)) :
        std::numeric_limits<double>::infinity();
  };
  const auto planeResidual =
      [](const Eigen::Vector3d &point,
         const std::vector<matLocalMidSurfaceProjection::Plane> &planes) {
    double squaredResidual = 0.0;
    std::size_t count = 0;
    for(const auto &plane : planes) {
      const double signedDistance =
          plane.normal.dot(point - plane.origin);
      if(!std::isfinite(signedDistance)) continue;
      squaredResidual += signedDistance * signedDistance;
      ++count;
    }
    return count > 0 ?
        std::sqrt(squaredResidual / static_cast<double>(count)) :
        std::numeric_limits<double>::infinity();
  };

  struct ProjectionTarget {
    Eigen::Vector3d original = Eigen::Vector3d::Zero();
    Eigen::Vector3d rawRequested = Eigen::Vector3d::Zero();
    Eigen::Vector3d preSplineRequested = Eigen::Vector3d::Zero();
    Eigen::Vector3d requested = Eigen::Vector3d::Zero();
    Eigen::Vector3d midSurfaceNormal = Eigen::Vector3d::Zero();
    Eigen::Vector3d repeatedSourceContactA = Eigen::Vector3d::Zero();
    Eigen::Vector3d repeatedSourceContactB = Eigen::Vector3d::Zero();
    double residualBefore = 0.0;
    std::vector<matLocalMidSurfaceProjection::Plane> constraintPlanes;
    const std::vector<int> *branches = nullptr;
    bool simpleBoundary = false;
    bool tripleLine = false;
    bool repeatedCadSourcePair = false;
    bool tripleSplineTarget = false;
    bool explicitPointConstraint = false;
    bool hasFiniteProjectionConstraint = true;
  };
  std::unordered_map<int, ProjectionTarget> targetByVertex;
  targetByVertex.reserve(candidates.size());
  std::map<int, std::vector<int>> targetVerticesByBranch;
  std::size_t rejected = 0;
  std::size_t stationaryUnconstrainedCandidates = 0;
  std::size_t stationaryRequestedResidualFallbacks = 0;
  std::size_t tripleLineRankFailures = 0;
  std::size_t tripleEdgeLineTargets = 0;
  std::size_t tripleEdgeLineFailures = 0;
  std::size_t repeatedCadSourcePairVertexCandidates = 0;
  std::size_t repeatedCadSourcePairVertexTargets = 0;
  std::size_t repeatedCadSourcePairVertexConflicts = 0;
  std::size_t repeatedCadSourcePairProjectionFailures = 0;
  std::size_t targetedRetainedBoundaryVertices = 0;
  double tripleLineRankRatioSum = 0.0;
  double maximumTripleLineRankRatio = 0.0;
  struct RegularProjectionPrecompute {
    Eigen::Vector3d original = Eigen::Vector3d::Zero();
    Eigen::Vector3d requested = Eigen::Vector3d::Zero();
    Eigen::Vector3d midSurfaceNormal = Eigen::Vector3d::Zero();
    double residualBefore = 0.0;
    bool ready = false;
    bool hasFiniteProjectionConstraint = true;
    bool requestedResidualFallback = false;
  };
  const auto projectionRegularTargetsStarted =
      std::chrono::steady_clock::now();
  std::vector<RegularProjectionPrecompute> regularProjectionAtCandidate(
      candidates.size());
#ifdef _OPENMP
#pragma omp parallel for schedule(static)
#endif
  for(std::ptrdiff_t candidateIndex = 0;
      candidateIndex < static_cast<std::ptrdiff_t>(candidates.size());
      ++candidateIndex) {
    const int vertex = candidates[candidateIndex];
    if(vertex < 0 ||
       3 * vertex + 2 >= static_cast<int>(vor.vertices.size()) ||
       tripleLineVertices.count(vertex) != 0)
      continue;
    RegularProjectionPrecompute &precomputed =
        regularProjectionAtCandidate[candidateIndex];
    precomputed.original = Eigen::Vector3d(
        vor.vertices[3 * vertex], vor.vertices[3 * vertex + 1],
        vor.vertices[3 * vertex + 2]);
    precomputed.requested = precomputed.original;
    const std::size_t firstMidPlane =
        planeCache.midPlaneOffsetsAtVertex[vertex];
    const std::size_t endMidPlane =
        planeCache.midPlaneOffsetsAtVertex[vertex + 1];
    Eigen::Vector3d referenceNormal = Eigen::Vector3d::Zero();
    Eigen::Vector3d normalSum = Eigen::Vector3d::Zero();
    for(std::size_t planeIndex = firstMidPlane;
        planeIndex < endMidPlane; ++planeIndex) {
      const ProjectionMidPlaneData &mid =
          *planeCache.midPlanesAtVertex[planeIndex];
      Eigen::Vector3d normal = mid.plane.normal;
      const double norm = normal.norm();
      if(!(norm > 0.0) || !normal.allFinite()) continue;
      normal /= norm;
      if(!(referenceNormal.norm() > 0.0)) referenceNormal = normal;
      if(normal.dot(referenceNormal) < 0.0) normal = -normal;
      normalSum += normal;
    }
    if(normalSum.norm() > 0.0)
      precomputed.midSurfaceNormal = normalSum.normalized();
    for(int iteration = 0; iteration < iterations; ++iteration) {
      Eigen::Vector3d correction = Eigen::Vector3d::Zero();
      double localScale = 0.0;
      double squaredResidual = 0.0;
      std::size_t count = 0;
      for(std::size_t planeIndex = firstMidPlane;
          planeIndex < endMidPlane; ++planeIndex) {
        const ProjectionMidPlaneData &mid =
            *planeCache.midPlanesAtVertex[planeIndex];
        const double signedDistance = mid.plane.normal.dot(
            precomputed.requested - mid.plane.origin);
        correction -= signedDistance * mid.plane.normal;
        squaredResidual += signedDistance * signedDistance;
        localScale += mid.scale;
        ++count;
      }
      if(count == 0) break;
      correction /= static_cast<double>(count);
      localScale /= static_cast<double>(count);
      const double residual =
          std::sqrt(squaredResidual / static_cast<double>(count));
      if(residual <= relativeTolerance * std::max(1.0, localScale)) break;
      const double maximumStep = 0.25 * localScale;
      if(correction.norm() > maximumStep && maximumStep > 0.0)
        correction *= maximumStep / correction.norm();
      precomputed.requested += correction;
      if(!precomputed.requested.allFinite()) {
        precomputed.requested = precomputed.original;
        break;
      }
    }
    precomputed.residualBefore =
        projectionResidual(precomputed.original, vertex);
    if(!std::isfinite(precomputed.residualBefore)) {
      precomputed.residualBefore = 0.0;
      precomputed.requested = precomputed.original;
      precomputed.hasFiniteProjectionConstraint = false;
    }
    else {
      const double requestedResidual =
          projectionResidual(precomputed.requested, vertex);
      if(!std::isfinite(requestedResidual) ||
         requestedResidual > precomputed.residualBefore + 1e-14) {
        precomputed.requested = precomputed.original;
        precomputed.requestedResidualFallback = true;
      }
    }
    precomputed.ready = true;
  }
  const auto projectionRegularTargetsReady =
      std::chrono::steady_clock::now();
  for(std::size_t candidateIndex = 0;
      candidateIndex < candidates.size(); ++candidateIndex) {
    const int vertex = candidates[candidateIndex];
    if(tripleLineVertices.count(vertex) == 0) {
      const RegularProjectionPrecompute &precomputed =
          regularProjectionAtCandidate[candidateIndex];
      if(!precomputed.ready)
        throw std::runtime_error(
            "regular MAT projection precomputation is missing");
      ProjectionTarget target;
      target.original = precomputed.original;
      target.requested = precomputed.requested;
      target.rawRequested = precomputed.requested;
      target.midSurfaceNormal = precomputed.midSurfaceNormal;
      target.residualBefore = precomputed.residualBefore;
      target.branches = &branchesAtVertex.at(vertex);
      target.simpleBoundary = simpleBoundaryCandidates.count(vertex) != 0;
      target.hasFiniteProjectionConstraint =
          precomputed.hasFiniteProjectionConstraint;
      if(!precomputed.hasFiniteProjectionConstraint)
        ++stationaryUnconstrainedCandidates;
      if(precomputed.requestedResidualFallback)
        ++stationaryRequestedResidualFallbacks;
      if(retainedBoundaryVertices.count(vertex) != 0)
        ++targetedRetainedBoundaryVertices;
      targetByVertex.emplace(vertex, target);
      for(const int branch : *target.branches)
        targetVerticesByBranch[branch].push_back(vertex);
      continue;
    }
    ProjectionTarget target;
    target.original = Eigen::Vector3d(
        vor.vertices[3 * vertex], vor.vertices[3 * vertex + 1],
        vor.vertices[3 * vertex + 2]);
    target.requested = target.original;
    target.branches = &branchesAtVertex.at(vertex);
    target.simpleBoundary = simpleBoundaryCandidates.count(vertex) != 0;
    target.tripleLine = tripleLineVertices.count(vertex) != 0;
    const std::size_t firstMidPlane =
        planeCache.midPlaneOffsetsAtVertex[vertex];
    const std::size_t endMidPlane =
        planeCache.midPlaneOffsetsAtVertex[vertex + 1];
    // Keep a tangent-plane normal with the projected vertex.  The extension
    // refinement later uses it to put newly inserted MAT-side boundary
    // points on a smooth reconstruction of this same local mid-surface.
    Eigen::Vector3d referenceNormal = Eigen::Vector3d::Zero();
    Eigen::Vector3d normalSum = Eigen::Vector3d::Zero();
    for(std::size_t planeIndex = firstMidPlane;
        planeIndex < endMidPlane; ++planeIndex) {
      const ProjectionMidPlaneData &mid =
          *planeCache.midPlanesAtVertex[planeIndex];
      Eigen::Vector3d normal = mid.plane.normal;
      const double norm = normal.norm();
      if(!(norm > 0.0) || !normal.allFinite()) continue;
      normal /= norm;
      if(!(referenceNormal.norm() > 0.0)) referenceNormal = normal;
      if(normal.dot(referenceNormal) < 0.0) normal = -normal;
      normalSum += normal;
    }
    if(normalSum.norm() > 0.0)
      target.midSurfaceNormal = normalSum.normalized();
    if(target.tripleLine) {
      bool repeatedPairTargetBuilt = false;
      const auto recovered = repeatedSourcePairsAtTripleVertex.find(vertex);
      if(recovered != repeatedSourcePairsAtTripleVertex.end() &&
         !recovered->second.empty()) {
        ++repeatedCadSourcePairVertexCandidates;
        std::vector<CadSurfacePairObservation> geometricPairs;
        for(const CadSurfacePairObservation &pair : recovered->second) {
          const bool alreadyPresent = std::any_of(
              geometricPairs.begin(), geometricPairs.end(),
              [&](const CadSurfacePairObservation &existing) {
                return sameCadSurfacePair(existing, pair);
              });
          if(!alreadyPresent) geometricPairs.push_back(pair);
        }

        // All incident triple edges must identify the same continuing sheet.
        // A disagreement is kept on the exact Voronoi fallback below.
        if(geometricPairs.size() == 1) {
          Eigen::Vector3d contactA;
          Eigen::Vector3d contactB;
          Eigen::Vector3d meanPoint;
          if(projectToCadMeanSurface(
                 geometricPairs.front(), target.original, meanPoint,
                 contactA, contactB)) {
            target.requested = meanPoint;
            target.repeatedSourceContactA = contactA;
            target.repeatedSourceContactB = contactB;
            target.repeatedCadSourcePair = true;
            target.explicitPointConstraint = true;
            const Eigen::Vector3d transverse = contactB - contactA;
            if(transverse.norm() > std::numeric_limits<double>::min())
              target.midSurfaceNormal = transverse.normalized();
            repeatedPairTargetBuilt = true;
            ++repeatedCadSourcePairVertexTargets;
          }
          else {
            ++repeatedCadSourcePairProjectionFailures;
          }
        }
        else {
          ++repeatedCadSourcePairVertexConflicts;
        }
      }

      if(!repeatedPairTargetBuilt) {
        std::vector<Eigen::Vector3d> localTargets;
        std::vector<Eigen::Vector3d> localDirections;
        const auto incidentTripleEdges =
            tripleEdgeSupportsAtVertex.find(vertex);
        if(incidentTripleEdges != tripleEdgeSupportsAtVertex.end()) {
          for(const std::array<int, 3> &supports :
              incidentTripleEdges->second) {
            const std::array<Eigen::Vector3d, 3> supportPoints = {
                surfacePoint(supports[0]), surfacePoint(supports[1]),
                surfacePoint(supports[2])};
            Eigen::Vector3d localTarget = target.original;
            Eigen::Vector3d localDirection = Eigen::Vector3d::Zero();
            std::vector<matLocalMidSurfaceProjection::Plane> constraints;
            double rankRatio = 0.0;
            if(matLocalMidSurfaceProjection::projectOntoEquidistantPointLine(
                   target.original, supportPoints, localTarget,
                   localDirection, &constraints, &rankRatio)) {
              localTargets.push_back(localTarget);
              if(!localDirections.empty() &&
                 localDirection.dot(localDirections.front()) < 0.0)
                localDirection = -localDirection;
              localDirections.push_back(localDirection);
              target.constraintPlanes.insert(
                  target.constraintPlanes.end(), constraints.begin(),
                  constraints.end());
              tripleLineRankRatioSum += rankRatio;
              maximumTripleLineRankRatio =
                  std::max(maximumTripleLineRankRatio, rankRatio);
              ++tripleEdgeLineTargets;
            }
            else {
              ++tripleEdgeLineFailures;
            }
          }
        }
        if(!localTargets.empty()) {
          Eigen::Vector3d lineOrigin = Eigen::Vector3d::Zero();
          Eigen::Vector3d lineDirection = Eigen::Vector3d::Zero();
          for(const Eigen::Vector3d &localTarget : localTargets)
            lineOrigin += localTarget;
          for(const Eigen::Vector3d &localDirection : localDirections)
            lineDirection += localDirection;
          lineOrigin /= static_cast<double>(localTargets.size());
          if(lineDirection.norm() > std::numeric_limits<double>::min()) {
            lineDirection.normalize();
            target.requested = lineOrigin + lineDirection *
                lineDirection.dot(target.original - lineOrigin);
            target.midSurfaceNormal = lineDirection;
          }
          else {
            target.requested = lineOrigin;
          }
        }
        else {
          target.requested = target.original;
          ++tripleLineRankFailures;
        }
      }
    }
    else {
      for(int iteration = 0; iteration < iterations; ++iteration) {
        Eigen::Vector3d correction = Eigen::Vector3d::Zero();
        double localScale = 0.0;
        double squaredResidual = 0.0;
        std::size_t count = 0;
        for(std::size_t planeIndex = firstMidPlane;
            planeIndex < endMidPlane; ++planeIndex) {
          const ProjectionMidPlaneData &mid =
              *planeCache.midPlanesAtVertex[planeIndex];
          const double signedDistance = mid.plane.normal.dot(
              target.requested - mid.plane.origin);
          correction -= signedDistance * mid.plane.normal;
          squaredResidual += signedDistance * signedDistance;
          localScale += mid.scale;
          ++count;
        }
        if(count == 0) break;
        correction /= static_cast<double>(count);
        localScale /= static_cast<double>(count);
        const double residual =
            std::sqrt(squaredResidual / static_cast<double>(count));
        if(residual <= relativeTolerance * std::max(1.0, localScale)) break;
        const double maximumStep = 0.25 * localScale;
        if(correction.norm() > maximumStep && maximumStep > 0.0)
          correction *= maximumStep / correction.norm();
        target.requested += correction;
        if(!target.requested.allFinite()) {
          target.requested = target.original;
          break;
        }
      }
    }
    target.residualBefore = target.explicitPointConstraint ?
        (target.original - target.requested).norm() :
        (target.tripleLine ?
             planeResidual(target.original, target.constraintPlanes) :
             projectionResidual(target.original, vertex));
    if(!std::isfinite(target.residualBefore)) {
      // A retained vertex remains a projection candidate even when a
      // degenerate local configuration supplies no finite constraint. Keep
      // it at its current position for this pass instead of rejecting it.
      target.residualBefore = 0.0;
      target.requested = target.original;
      target.rawRequested = target.original;
      target.hasFiniteProjectionConstraint = false;
      ++stationaryUnconstrainedCandidates;
      targetByVertex.emplace(vertex, target);
      for(const int branch : *target.branches)
        targetVerticesByBranch[branch].push_back(vertex);
      continue;
    }
    const double requestedResidual = target.explicitPointConstraint ?
        0.0 :
        (target.tripleLine ?
             planeResidual(target.requested, target.constraintPlanes) :
             projectionResidual(target.requested, vertex));
    if(!std::isfinite(requestedResidual) ||
       requestedResidual > target.residualBefore + 1e-14) {
      // The original point is always a finite, non-worsening fallback. This
      // remains a projection candidate and is reported as stationary.
      target.requested = target.original;
      ++stationaryRequestedResidualFallbacks;
    }
    target.rawRequested = target.requested;
    targetByVertex.emplace(vertex, target);
    for(const int branch : *target.branches)
      targetVerticesByBranch[branch].push_back(vertex);
  }
  const auto projectionTargetAssemblyReady =
      std::chrono::steady_clock::now();

  std::size_t tripleSplineClosedChains = 0;
  std::size_t tripleSplineFittedChains = 0;
  std::size_t tripleSplineProjectedVertices = 0;
  double tripleSplineTargetChangeSum = 0.0;
  double maximumTripleSplineTargetChange = 0.0;
  struct TripleSplineChain {
    std::vector<int> vertices;
    bool closed = false;
  };
  std::map<int, std::vector<int>> tripleAdjacency;
  for(const matGmshEdge &edge : tripleLineEdges) {
    tripleAdjacency[edge.a].push_back(edge.b);
    tripleAdjacency[edge.b].push_back(edge.a);
  }
  for(auto &entry : tripleAdjacency) {
    std::sort(entry.second.begin(), entry.second.end());
    entry.second.erase(
        std::unique(entry.second.begin(), entry.second.end()),
        entry.second.end());
  }

  std::set<matGmshEdge> visitedTripleEdges;
  std::vector<TripleSplineChain> tripleSplineChains;
  const auto appendTripleSplineChain = [&](int start, int next) {
    TripleSplineChain chain;
    chain.vertices.push_back(start);
    int previous = start;
    int current = next;
    visitedTripleEdges.insert(matGmshEdge(start, next));
    while(true) {
      if(current == start) {
        chain.closed = true;
        break;
      }
      chain.vertices.push_back(current);
      const auto adjacent = tripleAdjacency.find(current);
      if(adjacent == tripleAdjacency.end() ||
         adjacent->second.size() != 2)
        break;
      int following = -1;
      for(const int candidate : adjacent->second) {
        if(candidate == previous) continue;
        const matGmshEdge edge(current, candidate);
        if(visitedTripleEdges.count(edge) == 0) {
          following = candidate;
          visitedTripleEdges.insert(edge);
          break;
        }
      }
      if(following < 0) break;
      previous = current;
      current = following;
    }
    if(chain.vertices.size() >= 2)
      tripleSplineChains.push_back(std::move(chain));
  };

  // Open chains and chains meeting a higher-order junction are split at
  // vertices whose triple-edge degree is not two.
  for(const auto &entry : tripleAdjacency) {
    if(entry.second.size() == 2) continue;
    for(const int neighbor : entry.second)
      if(visitedTripleEdges.count(matGmshEdge(entry.first, neighbor)) == 0)
        appendTripleSplineChain(entry.first, neighbor);
  }
  // The unvisited components are closed triple-line loops.
  for(const matGmshEdge &edge : tripleLineEdges)
    if(visitedTripleEdges.count(edge) == 0)
      appendTripleSplineChain(edge.a, edge.b);

  std::unordered_map<int, std::vector<Eigen::Vector3d>>
      splineTargetsAtVertex;
  for(const TripleSplineChain &chain : tripleSplineChains) {
    const std::size_t count = chain.vertices.size();
    if(count < 2 || (chain.closed && count < 3)) continue;
    bool complete = true;
    std::vector<Eigen::Vector3d> original(count);
    std::vector<Eigen::Vector3d> rawTargets(count);
    for(std::size_t i = 0; i < count; ++i) {
      const auto target = targetByVertex.find(chain.vertices[i]);
      if(target == targetByVertex.end() || !target->second.tripleLine) {
        complete = false;
        break;
      }
      original[i] = target->second.original;
      rawTargets[i] = target->second.rawRequested;
    }
    if(!complete) continue;

    const std::size_t segmentCount = chain.closed ? count : count - 1;
    std::vector<double> segmentLengths(segmentCount, 1.0);
    for(std::size_t segment = 0; segment < segmentCount; ++segment) {
      const std::size_t next = (segment + 1) % count;
      double length = (original[next] - original[segment]).norm();
      if(!(length > std::numeric_limits<double>::min()))
        length = (rawTargets[next] - rawTargets[segment]).norm();
      segmentLengths[segment] =
          length > std::numeric_limits<double>::min() ? length : 1.0;
    }

    // Smooth only the requested displacement. This removes isolated target
    // noise without shrinking the already valid triple-line geometry.
    std::vector<Eigen::Vector3d> displacement(count);
    for(std::size_t i = 0; i < count; ++i)
      displacement[i] = rawTargets[i] - original[i];
    constexpr int displacementSmoothingPasses = 4;
    constexpr double displacementSmoothingWeight = 0.5;
    for(int pass = 0; pass < displacementSmoothingPasses; ++pass) {
      std::vector<Eigen::Vector3d> filtered = displacement;
      const std::size_t first = chain.closed ? 0 : 1;
      const std::size_t end = chain.closed ? count : count - 1;
      for(std::size_t i = first; i < end; ++i) {
        const std::size_t previous = (i + count - 1) % count;
        const std::size_t next = (i + 1) % count;
        const double previousLength = segmentLengths[previous % segmentCount];
        const double nextLength = segmentLengths[i % segmentCount];
        const double sum = previousLength + nextLength;
        if(!(sum > std::numeric_limits<double>::min())) continue;
        const Eigen::Vector3d interpolated =
            (nextLength * displacement[previous] +
             previousLength * displacement[next]) /
            sum;
        filtered[i] =
            (1.0 - displacementSmoothingWeight) * displacement[i] +
            displacementSmoothingWeight * interpolated;
      }
      displacement.swap(filtered);
    }

    std::vector<Eigen::Vector3d> knots(count);
    for(std::size_t i = 0; i < count; ++i)
      knots[i] = original[i] + displacement[i];

    std::vector<Eigen::Vector3d> tangents(count, Eigen::Vector3d::Zero());
    for(std::size_t i = 0; i < count; ++i) {
      if(!chain.closed && i == 0) {
        tangents[i] = (knots[1] - knots[0]) / segmentLengths[0];
      }
      else if(!chain.closed && i + 1 == count) {
        tangents[i] = (knots[i] - knots[i - 1]) /
            segmentLengths[segmentCount - 1];
      }
      else {
        const std::size_t previous = (i + count - 1) % count;
        const std::size_t next = (i + 1) % count;
        const double scale =
            segmentLengths[previous % segmentCount] +
            segmentLengths[i % segmentCount];
        if(scale > std::numeric_limits<double>::min())
          tangents[i] = (knots[next] - knots[previous]) / scale;
      }
    }

    const auto evaluateSplineSegment = [&](std::size_t segment, double u,
                                           Eigen::Vector3d *firstDerivative,
                                           Eigen::Vector3d *secondDerivative) {
      const std::size_t next = (segment + 1) % count;
      const double h = segmentLengths[segment];
      const double u2 = u * u;
      const double u3 = u2 * u;
      const double h00 = 2.0 * u3 - 3.0 * u2 + 1.0;
      const double h10 = u3 - 2.0 * u2 + u;
      const double h01 = -2.0 * u3 + 3.0 * u2;
      const double h11 = u3 - u2;
      if(firstDerivative) {
        *firstDerivative =
            (6.0 * u2 - 6.0 * u) * knots[segment] +
            (3.0 * u2 - 4.0 * u + 1.0) * h * tangents[segment] +
            (-6.0 * u2 + 6.0 * u) * knots[next] +
            (3.0 * u2 - 2.0 * u) * h * tangents[next];
      }
      if(secondDerivative) {
        *secondDerivative =
            (12.0 * u - 6.0) * knots[segment] +
            (6.0 * u - 4.0) * h * tangents[segment] +
            (-12.0 * u + 6.0) * knots[next] +
            (6.0 * u - 2.0) * h * tangents[next];
      }
      return h00 * knots[segment] + h10 * h * tangents[segment] +
          h01 * knots[next] + h11 * h * tangents[next];
    };

    for(std::size_t i = 0; i < count; ++i) {
      // Shared endpoints delimit distinct chains and remain at their common
      // raw target. Interior nodes are projected only on nearby segments, so
      // a close but unrelated part of a closed curve cannot capture them.
      if(!chain.closed && (i == 0 || i + 1 == count)) {
        splineTargetsAtVertex[chain.vertices[i]].push_back(rawTargets[i]);
        continue;
      }
      Eigen::Vector3d bestPoint = knots[i];
      double bestSquaredDistance =
          (bestPoint - original[i]).squaredNorm();
      for(int offset = -2; offset <= 1; ++offset) {
        int signedSegment = static_cast<int>(i) + offset;
        if(chain.closed) {
          signedSegment %= static_cast<int>(segmentCount);
          if(signedSegment < 0)
            signedSegment += static_cast<int>(segmentCount);
        }
        else if(signedSegment < 0 ||
                signedSegment >= static_cast<int>(segmentCount)) {
          continue;
        }
        const std::size_t segment =
            static_cast<std::size_t>(signedSegment);
        double bestU = 0.0;
        constexpr int coarseIntervals = 8;
        for(int sample = 0; sample <= coarseIntervals; ++sample) {
          const double u =
              static_cast<double>(sample) / coarseIntervals;
          const Eigen::Vector3d candidate =
              evaluateSplineSegment(segment, u, nullptr, nullptr);
          const double squaredDistance =
              (candidate - original[i]).squaredNorm();
          if(squaredDistance < bestSquaredDistance) {
            bestSquaredDistance = squaredDistance;
            bestPoint = candidate;
            bestU = u;
          }
        }
        double u = bestU;
        for(int iteration = 0; iteration < 12; ++iteration) {
          Eigen::Vector3d firstDerivative;
          Eigen::Vector3d secondDerivative;
          const Eigen::Vector3d candidate = evaluateSplineSegment(
              segment, u, &firstDerivative, &secondDerivative);
          const Eigen::Vector3d residual = candidate - original[i];
          const double denominator = firstDerivative.squaredNorm() +
              residual.dot(secondDerivative);
          if(!(std::abs(denominator) >
               1e-14 * std::max(1.0, firstDerivative.squaredNorm())))
            break;
          const double nextU = std::clamp(
              u - residual.dot(firstDerivative) / denominator, 0.0, 1.0);
          if(std::abs(nextU - u) < 1e-10) {
            u = nextU;
            break;
          }
          u = nextU;
        }
        const Eigen::Vector3d candidate =
            evaluateSplineSegment(segment, u, nullptr, nullptr);
        const double squaredDistance =
            (candidate - original[i]).squaredNorm();
        if(squaredDistance < bestSquaredDistance) {
          bestSquaredDistance = squaredDistance;
          bestPoint = candidate;
        }
      }
      splineTargetsAtVertex[chain.vertices[i]].push_back(bestPoint);
    }
    ++tripleSplineFittedChains;
    if(chain.closed) ++tripleSplineClosedChains;
  }

  for(auto &entry : splineTargetsAtVertex) {
    auto target = targetByVertex.find(entry.first);
    if(target == targetByVertex.end() || entry.second.empty()) continue;
    Eigen::Vector3d splineTarget = Eigen::Vector3d::Zero();
    for(const Eigen::Vector3d &candidate : entry.second)
      splineTarget += candidate;
    splineTarget /= static_cast<double>(entry.second.size());
    if(!splineTarget.allFinite()) continue;
    ProjectionTarget &projection = target->second;
    projection.preSplineRequested = projection.rawRequested;
    const double targetChange =
        (splineTarget - projection.rawRequested).norm();
    tripleSplineTargetChangeSum += targetChange;
    maximumTripleSplineTargetChange =
        std::max(maximumTripleSplineTargetChange, targetChange);
    projection.requested = splineTarget;
    projection.rawRequested = splineTarget;
    projection.explicitPointConstraint = true;
    projection.hasFiniteProjectionConstraint = true;
    projection.tripleSplineTarget = true;
    projection.residualBefore =
        (projection.original - projection.requested).norm();
    ++tripleSplineProjectedVertices;
  }
  const auto projectionTripleSplinesReady =
      std::chrono::steady_clock::now();

  // Triple-line vertices use the same topology-guarded displacement as the
  // rest of the MAT. Their target is the continuing CAD mean surface when a
  // repeated source pair is available, and otherwise the local equidistant
  // line; chain-wise spline filtering keeps the projected curve coherent.
  std::size_t fixedTripleLineVertices = 0;
  const auto projectionTargetsReady = std::chrono::steady_clock::now();

  const auto targetUsesBranch = [](const ProjectionTarget &target,
                                   int branch) {
    if(!target.branches) return false;
    return std::binary_search(
        target.branches->begin(), target.branches->end(), branch);
  };
  const auto targetsShareBranch = [](const ProjectionTarget &first,
                                     const ProjectionTarget &second) {
    if(!first.branches || !second.branches) return false;
    for(const int branch : *first.branches)
      if(std::binary_search(second.branches->begin(),
                            second.branches->end(), branch))
        return true;
    return false;
  };

  // Build the retained fan connectivity and reproduce the topological
  // triangle orientations used later by createTriangulatedModel(). The actual
  // acceptance decision below is local to each projected vertex and its
  // incident 1-ring.
  const std::vector<double> originalVoronoiVertices = vor.vertices;
  ProjectionTopologyCache &topology = shared.topology;
  const bool buildTopology = !topology.ready;
  auto &facesByBranch = topology.facesByBranch;
  auto &retainedFanVertices = topology.retainedFanVertices;
  auto &fanOrientationSigns = topology.fanOrientationSigns;
  auto &fanAdjacencyTopologyByBranch =
      topology.fanAdjacencyTopologyByBranch;
  auto &retainedFacesAtVertex = topology.retainedFacesAtVertex;
  auto &regularizationNeighborOffsets =
      topology.regularizationNeighborOffsets;
  auto &regularizationNeighbors = topology.regularizationNeighbors;
  auto &fanCornerScratchOffset = topology.fanCornerScratchOffset;
  auto &fanCenterScratchOffset = topology.fanCenterScratchOffset;
  std::size_t &maximumBranchCornerCount =
      topology.maximumBranchCornerCount;
  std::size_t &maximumBranchFaceCount = topology.maximumBranchFaceCount;
  if(buildTopology) {
    retainedFanVertices.resize(vor.faces.size());
    fanOrientationSigns.resize(vor.faces.size());
    for(std::size_t faceIndex = 0; faceIndex < vor.faces.size();
        ++faceIndex) {
      const int branch = vor.faceColors[faceIndex];
      if(branch < 0) continue;
      facesByBranch[branch].push_back(faceIndex);
      const VoronoiFace &face = vor.faces[faceIndex];
      std::vector<int> &vertices = retainedFanVertices[faceIndex];
      vertices.reserve(face.verts.size());
      for(const int vertex : face.verts) {
        if(vertex >= 0 &&
           3 * vertex + 2 <
               static_cast<int>(originalVoronoiVertices.size()))
          vertices.push_back(vertex);
      }
    }
  }
  std::vector<Eigen::Vector3d> originalFanCenters(
      vor.faces.size(), Eigen::Vector3d::Zero());
  struct ProjectionFanReferenceTriangle {
    Eigen::Vector3d cross = Eigen::Vector3d::Zero();
    std::array<double, 3> edgeLengths = {0.0, 0.0, 0.0};
    double squaredLengthSum = 0.0;
    double doubleArea = 0.0;
    double quality = 0.0;
    bool valid = false;
  };
  std::vector<std::vector<ProjectionFanReferenceTriangle>>
      originalFanTriangles(vor.faces.size());
  for(std::size_t faceIndex = 0; faceIndex < vor.faces.size(); ++faceIndex) {
    if(vor.faceColors[faceIndex] < 0) continue;
    const std::vector<int> &vertices = retainedFanVertices[faceIndex];
    if(vertices.size() < 3) continue;
    Eigen::Vector3d center = Eigen::Vector3d::Zero();
    for(const int vertex : vertices) {
      center += Eigen::Vector3d(
          originalVoronoiVertices[3 * vertex],
          originalVoronoiVertices[3 * vertex + 1],
          originalVoronoiVertices[3 * vertex + 2]);
    }
    center /= static_cast<double>(vertices.size());
    originalFanCenters[faceIndex] = center;
    auto &triangles = originalFanTriangles[faceIndex];
    triangles.reserve(vertices.size());
    for(std::size_t local = 0; local < vertices.size(); ++local) {
      const int first = vertices[local];
      const int second = vertices[(local + 1) % vertices.size()];
      const Eigen::Vector3d a(
          originalVoronoiVertices[3 * first],
          originalVoronoiVertices[3 * first + 1],
          originalVoronoiVertices[3 * first + 2]);
      const Eigen::Vector3d b(
          originalVoronoiVertices[3 * second],
          originalVoronoiVertices[3 * second + 1],
          originalVoronoiVertices[3 * second + 2]);
      ProjectionFanReferenceTriangle reference;
      const std::array<Eigen::Vector3d, 3> edges = {
          a - center, b - a, center - b};
      reference.valid = center.allFinite() && a.allFinite() && b.allFinite();
      for(std::size_t edge = 0; edge < edges.size(); ++edge) {
        reference.edgeLengths[edge] = edges[edge].norm();
        reference.squaredLengthSum +=
            reference.edgeLengths[edge] * reference.edgeLengths[edge];
        reference.valid = reference.valid &&
            reference.edgeLengths[edge] >
                std::numeric_limits<double>::min();
      }
      reference.cross = (a - center).cross(b - center);
      reference.doubleArea = reference.cross.norm();
      reference.valid = reference.valid &&
          reference.doubleArea > std::numeric_limits<double>::min();
      if(reference.valid)
        reference.quality =
            reference.doubleArea / reference.squaredLengthSum;
      triangles.push_back(reference);
    }
  }

  std::map<int, std::vector<ProjectionFanNormalAdjacency>>
      fanNormalAdjacenciesByBranch;
  if(buildTopology) for(const auto &branchFaces : facesByBranch) {
    struct FanReference {
      std::size_t face = 0;
      std::size_t local = 0;
      std::array<std::size_t, 3> originalNodes = {0, 0, 0};
    };
    std::vector<std::array<std::size_t, 3>> triangles;
    std::vector<FanReference> references;
    const std::size_t centerBase = originalVoronoiVertices.size() / 3 + 1;
    for(const std::size_t faceIndex : branchFaces.second) {
      const std::vector<int> &vertices = retainedFanVertices[faceIndex];
      fanOrientationSigns[faceIndex].assign(vertices.size(), 1.0);
      const std::size_t centerNode = centerBase + faceIndex;
      for(std::size_t local = 0; local < vertices.size(); ++local) {
        const std::array<std::size_t, 3> nodes = {
            centerNode, static_cast<std::size_t>(vertices[local]) + 1,
            static_cast<std::size_t>(
                vertices[(local + 1) % vertices.size()]) + 1};
        triangles.push_back(nodes);
        references.push_back({faceIndex, local, nodes});
      }
    }

    struct TriangleEdgeUse {
      std::size_t triangle = 0;
      std::size_t edge = 0;
    };
    const auto edgeKey = [](std::size_t a, std::size_t b) {
      return std::pair<std::size_t, std::size_t>{
          std::min(a, b), std::max(a, b)};
    };
    const auto edgeNodes = [&](std::size_t triangle, std::size_t edge) {
      return std::pair<std::size_t, std::size_t>{
          triangles[triangle][edge], triangles[triangle][(edge + 1) % 3]};
    };
    std::unordered_map<std::pair<std::size_t, std::size_t>,
                       std::vector<TriangleEdgeUse>, SizeTPairHash>
        edgeUsesForOrientation;
    edgeUsesForOrientation.reserve(3 * triangles.size());
    for(std::size_t triangle = 0; triangle < triangles.size(); ++triangle) {
      for(std::size_t edge = 0; edge < 3; ++edge) {
        const auto nodes = edgeNodes(triangle, edge);
        edgeUsesForOrientation[edgeKey(nodes.first, nodes.second)].push_back(
            {triangle, edge});
      }
    }
    std::vector<char> visited(triangles.size(), 0);
    std::queue<std::size_t> queue;
    for(std::size_t seed = 0; seed < triangles.size(); ++seed) {
      if(visited[seed]) continue;
      visited[seed] = 1;
      queue.push(seed);
      while(!queue.empty()) {
        const std::size_t current = queue.front();
        queue.pop();
        for(std::size_t edge = 0; edge < 3; ++edge) {
          const auto currentNodes = edgeNodes(current, edge);
          const auto uses = edgeUsesForOrientation.find(
              edgeKey(currentNodes.first, currentNodes.second));
          if(uses == edgeUsesForOrientation.end()) continue;
          for(const TriangleEdgeUse &neighborUse : uses->second) {
            const std::size_t neighbor = neighborUse.triangle;
            if(neighbor == current || visited[neighbor]) continue;
            const auto neighborNodes =
                edgeNodes(neighbor, neighborUse.edge);
            if(neighborNodes.first == currentNodes.first &&
               neighborNodes.second == currentNodes.second)
              std::swap(triangles[neighbor][1], triangles[neighbor][2]);
            visited[neighbor] = 1;
            queue.push(neighbor);
          }
        }
      }
    }
    for(std::size_t triangle = 0; triangle < triangles.size(); ++triangle) {
      const FanReference &reference = references[triangle];
      if(triangles[triangle][1] != reference.originalNodes[1])
        fanOrientationSigns[reference.face][reference.local] = -1.0;
    }

    auto &adjacencyTopology =
        fanAdjacencyTopologyByBranch[branchFaces.first];
    for(const auto &edgeEntry : edgeUsesForOrientation) {
      if(edgeEntry.second.size() != 2) continue;
      const FanReference &firstReference =
          references[edgeEntry.second[0].triangle];
      const FanReference &secondReference =
          references[edgeEntry.second[1].triangle];
      adjacencyTopology.push_back({
          {firstReference.face, firstReference.local},
          {secondReference.face, secondReference.local}});
    }
  }
  for(const auto &branchAdjacencies : fanAdjacencyTopologyByBranch) {
    auto &normalAdjacencies =
        fanNormalAdjacenciesByBranch[branchAdjacencies.first];
    normalAdjacencies.reserve(branchAdjacencies.second.size());
    for(const ProjectionFanAdjacencyTopology &adjacency :
        branchAdjacencies.second) {
      Eigen::Vector3d firstNormal =
          fanOrientationSigns[adjacency.first.face][adjacency.first.local] *
          originalFanTriangles[adjacency.first.face]
                              [adjacency.first.local]
                                  .cross;
      Eigen::Vector3d secondNormal =
          fanOrientationSigns[adjacency.second.face][adjacency.second.local] *
          originalFanTriangles[adjacency.second.face]
                              [adjacency.second.local]
                                  .cross;
      const double firstNorm = firstNormal.norm();
      const double secondNorm = secondNormal.norm();
      if(!(firstNorm > std::numeric_limits<double>::min()) ||
         !(secondNorm > std::numeric_limits<double>::min()))
        continue;
      normalAdjacencies.push_back({
          adjacency.first, adjacency.second,
          std::clamp(firstNormal.dot(secondNormal) /
                         (firstNorm * secondNorm),
                     -1.0, 1.0)});
    }
  }
  std::vector<std::vector<std::size_t>>
      fanNormalAdjacencyIndicesAtFace(vor.faces.size());
  for(const auto &branchAdjacencies : fanNormalAdjacenciesByBranch) {
    for(std::size_t adjacency = 0;
        adjacency < branchAdjacencies.second.size(); ++adjacency) {
      const ProjectionFanNormalAdjacency &entry =
          branchAdjacencies.second[adjacency];
      fanNormalAdjacencyIndicesAtFace[entry.first.face].push_back(adjacency);
      if(entry.second.face != entry.first.face)
        fanNormalAdjacencyIndicesAtFace[entry.second.face].push_back(
            adjacency);
    }
  }

  const std::size_t retainedVertexCount = vor.vertices.size() / 3;
  std::vector<double> acceptedFractionByVertex(retainedVertexCount, 0.0);
  std::vector<const ProjectionTarget *> targetAtVertex(
      retainedVertexCount, nullptr);
  std::vector<double *> acceptedFractionAtVertex(
      retainedVertexCount, nullptr);
  for(const auto &target : targetByVertex) {
    const int vertex = target.first;
    if(vertex < 0 || vertex >= static_cast<int>(targetAtVertex.size()))
      continue;
    targetAtVertex[vertex] = &target.second;
    acceptedFractionAtVertex[vertex] =
        &acceptedFractionByVertex[vertex];
  }
  // Reuse one compact geometry buffer for both topology predicates. The old
  // hot path rebuilt every face, center and fan cross independently in each
  // predicate and on every dyadic backtrack.
  const std::size_t invalidScratchOffset =
      std::numeric_limits<std::size_t>::max();
  if(buildTopology) {
    fanCornerScratchOffset.assign(vor.faces.size(), invalidScratchOffset);
    fanCenterScratchOffset.assign(vor.faces.size(), invalidScratchOffset);
  }
  if(buildTopology) for(const auto &branchFaces : facesByBranch) {
    std::size_t cornerCount = 0;
    std::size_t faceCount = 0;
    for(const std::size_t faceIndex : branchFaces.second) {
      fanCornerScratchOffset[faceIndex] = cornerCount;
      fanCenterScratchOffset[faceIndex] = faceCount++;
      cornerCount += retainedFanVertices[faceIndex].size();
    }
    maximumBranchCornerCount =
        std::max(maximumBranchCornerCount, cornerCount);
    maximumBranchFaceCount =
        std::max(maximumBranchFaceCount, faceCount);
  }
  std::vector<Eigen::Vector3d> currentFanPositions(
      maximumBranchCornerCount);
  std::vector<Eigen::Vector3d> currentOrientedFanCrosses(
      maximumBranchCornerCount);
  std::vector<Eigen::Vector3d> currentFanCenters(
      maximumBranchFaceCount, Eigen::Vector3d::Zero());
  const auto projectionTopologyPrepared =
      std::chrono::steady_clock::now();

  const auto pointAtFraction =
      [&](int vertex, int branch, double fraction) -> Eigen::Vector3d {
    (void)branch;
    if(vertex >= 0 && vertex < static_cast<int>(targetAtVertex.size()) &&
       targetAtVertex[vertex] && acceptedFractionAtVertex[vertex]) {
      const ProjectionTarget &target = *targetAtVertex[vertex];
      return target.original +
          fraction * *acceptedFractionAtVertex[vertex] *
          (target.requested - target.original);
    }
    return Eigen::Vector3d(
        originalVoronoiVertices[3 * vertex],
        originalVoronoiVertices[3 * vertex + 1],
        originalVoronoiVertices[3 * vertex + 2]);
  };
  const auto updateFanFaceGeometry =
      [&](std::size_t faceIndex, int branch, double fraction) {
      const std::vector<int> &vertices = retainedFanVertices[faceIndex];
      if(vertices.size() < 3 ||
         originalFanTriangles[faceIndex].size() != vertices.size())
        return false;
      const std::size_t cornerOffset = fanCornerScratchOffset[faceIndex];
      const std::size_t centerOffset = fanCenterScratchOffset[faceIndex];
      if(cornerOffset == invalidScratchOffset ||
         centerOffset == invalidScratchOffset ||
         cornerOffset + vertices.size() > currentFanPositions.size() ||
         centerOffset >= currentFanCenters.size())
        return false;
      Eigen::Vector3d center = Eigen::Vector3d::Zero();
      for(std::size_t local = 0; local < vertices.size(); ++local) {
        currentFanPositions[cornerOffset + local] =
            pointAtFraction(vertices[local], branch, fraction);
        center += currentFanPositions[cornerOffset + local];
      }
      center /= static_cast<double>(vertices.size());
      currentFanCenters[centerOffset] = center;
      for(std::size_t local = 0; local < vertices.size(); ++local) {
        currentOrientedFanCrosses[cornerOffset + local] =
            fanOrientationSigns[faceIndex][local] *
            (currentFanPositions[cornerOffset + local] - center)
                .cross(currentFanPositions[
                           cornerOffset + (local + 1) % vertices.size()] -
                       center);
      }
      return true;
  };
  const auto updateBranchFanGeometry = [&](int branch, double fraction) {
    const auto faces = facesByBranch.find(branch);
    if(faces == facesByBranch.end()) return false;
    for(const std::size_t faceIndex : faces->second) {
      if(!updateFanFaceGeometry(faceIndex, branch, fraction)) return false;
    }
    return true;
  };

  const auto fanFaceOrientationIsPreserved = [&](std::size_t faceIndex) {
    const std::vector<int> &vertices = retainedFanVertices[faceIndex];
    const std::size_t cornerOffset = fanCornerScratchOffset[faceIndex];
    const std::size_t centerOffset = fanCenterScratchOffset[faceIndex];
    if(vertices.size() < 3 || cornerOffset == invalidScratchOffset ||
       centerOffset == invalidScratchOffset ||
       cornerOffset + vertices.size() > currentFanPositions.size() ||
       centerOffset >= currentFanCenters.size())
      return false;
    for(std::size_t local = 0; local < vertices.size(); ++local) {
      const ProjectionFanReferenceTriangle &reference =
          originalFanTriangles[faceIndex][local];
      const Eigen::Vector3d &center = currentFanCenters[centerOffset];
      const Eigen::Vector3d &first =
          currentFanPositions[cornerOffset + local];
      const Eigen::Vector3d &second = currentFanPositions[
          cornerOffset + (local + 1) % vertices.size()];
      if(!reference.valid || !center.allFinite() || !first.allFinite() ||
         !second.allFinite())
        return false;
      const std::array<Eigen::Vector3d, 3> projectedEdges = {
          first - center, second - first, center - second};
      double projectedSquaredLengthSum = 0.0;
      for(std::size_t edge = 0; edge < projectedEdges.size(); ++edge) {
        const double length = projectedEdges[edge].norm();
        if(!std::isfinite(length)) return false;
        const double stretch = length / reference.edgeLengths[edge];
        if(stretch < 0.25 || stretch > 4.0) return false;
        projectedSquaredLengthSum += length * length;
      }
      const Eigen::Vector3d projectedCross =
          fanOrientationSigns[faceIndex][local] *
          currentOrientedFanCrosses[cornerOffset + local];
      const double projectedDoubleArea = projectedCross.norm();
      if(!(projectedDoubleArea >= 0.01 * reference.doubleArea) ||
         !(projectedCross.dot(reference.cross) > 0.0) ||
         !(projectedDoubleArea / projectedSquaredLengthSum >=
           0.1 * reference.quality))
        return false;
    }
    return true;
  };

  const auto preservesBranchFanOrientation =
      [&](int branch, std::set<int> *invalidVertices) {
    const auto faces = facesByBranch.find(branch);
    if(faces == facesByBranch.end()) return false;
    bool valid = true;
    for(const std::size_t faceIndex : faces->second) {
      const std::vector<int> &vertices = retainedFanVertices[faceIndex];
      if(fanFaceOrientationIsPreserved(faceIndex)) continue;
      valid = false;
      if(!invalidVertices) return false;
      for(const int vertex : vertices) {
        const auto target = targetByVertex.find(vertex);
        if(target != targetByVertex.end() &&
           targetUsesBranch(target->second, branch))
          invalidVertices->insert(vertex);
        }
    }
    return valid;
  };

  // A triangle can remain in the same hemisphere as its own original normal
  // while crossing the normal of a neighboring triangle.  That creates the
  // isolated reversed normals visible along a projected MAT boundary.  Test
  // the oriented normal on both sides of every fan edge instead of comparing
  // with a single mean plane; the latter is not meaningful on a curved MAT
  // branch.  Only pairs that were coherent before projection are constrained,
  // so the exact original mesh is always a valid backtracking endpoint.
  const auto adjacentFanNormalOrientationIsPreserved =
      [&](const ProjectionFanNormalAdjacency &adjacency) {
    constexpr double coherentOriginalCosine = 1.e-8;
    if(!(adjacency.originalCosine > coherentOriginalCosine)) return true;
    const std::size_t firstOffset =
        fanCornerScratchOffset[adjacency.first.face];
    const std::size_t secondOffset =
        fanCornerScratchOffset[adjacency.second.face];
    if(firstOffset == invalidScratchOffset ||
       secondOffset == invalidScratchOffset ||
       firstOffset + adjacency.first.local >=
           currentOrientedFanCrosses.size() ||
       secondOffset + adjacency.second.local >=
           currentOrientedFanCrosses.size())
      return false;
    const Eigen::Vector3d &first = currentOrientedFanCrosses[
        firstOffset + adjacency.first.local];
    const Eigen::Vector3d &second = currentOrientedFanCrosses[
        secondOffset + adjacency.second.local];
    const double scale = first.norm() * second.norm();
    return scale > std::numeric_limits<double>::min() &&
        first.dot(second) > 0.0;
  };

  const auto preservesAdjacentFanNormalOrientation =
      [&](int branch, std::set<int> *invalidVertices,
          std::size_t *violationCount) {
    const auto adjacencies = fanNormalAdjacenciesByBranch.find(branch);
    if(adjacencies == fanNormalAdjacenciesByBranch.end())
      return false;

    const auto addFaceVertices = [&](std::size_t faceIndex) {
      if(!invalidVertices) return;
      for(const int vertex : vor.faces[faceIndex].verts) {
        const auto target = targetByVertex.find(vertex);
        if(target != targetByVertex.end() &&
           targetUsesBranch(target->second, branch))
          invalidVertices->insert(vertex);
      }
    };

    bool valid = true;
    for(const ProjectionFanNormalAdjacency &adjacency :
        adjacencies->second) {
      constexpr double coherentOriginalCosine = 1.e-8;
      if(!(adjacency.originalCosine > coherentOriginalCosine)) continue;
      if(adjacentFanNormalOrientationIsPreserved(adjacency)) continue;
      valid = false;
      if(violationCount) ++*violationCount;
      addFaceVertices(adjacency.first.face);
      addFaceVertices(adjacency.second.face);
      if(!invalidVertices && !violationCount) return false;
    }
    return valid;
  };

  const auto hasPositiveBranchMeanPlaneProjection =
      [&](int branch, double fraction, std::set<int> *invalidVertices) {
    const auto faces = facesByBranch.find(branch);
    if(faces == facesByBranch.end()) return false;

    double totalArea = 0.0;
    Eigen::Vector3d firstMoment = Eigen::Vector3d::Zero();
    Eigen::Vector3d orientedNormal = Eigen::Vector3d::Zero();
    for(const std::size_t faceIndex : faces->second) {
      std::vector<int> vertices;
      for(const int vertex : vor.faces[faceIndex].verts) {
        if(vertex >= 0 &&
           3 * vertex + 2 < static_cast<int>(originalVoronoiVertices.size()))
          vertices.push_back(vertex);
      }
      if(vertices.size() < 3) continue;
      Eigen::Vector3d center = Eigen::Vector3d::Zero();
      for(const int vertex : vertices)
        center += pointAtFraction(vertex, branch, fraction);
      center /= static_cast<double>(vertices.size());
      for(std::size_t local = 0; local < vertices.size(); ++local) {
        const Eigen::Vector3d a =
            pointAtFraction(vertices[local], branch, fraction);
        const Eigen::Vector3d b = pointAtFraction(
            vertices[(local + 1) % vertices.size()], branch, fraction);
        const Eigen::Vector3d cross = (a - center).cross(b - center);
        const double area = 0.5 * cross.norm();
        if(!(area > std::numeric_limits<double>::min())) continue;
        totalArea += area;
        firstMoment += area * (center + a + b) / 3.0;
        orientedNormal += fanOrientationSigns[faceIndex][local] * cross;
      }
    }
    if(!(totalArea > 0.0) || !std::isfinite(totalArea)) {
      if(invalidVertices) {
        for(const int vertex : targetVerticesByBranch.at(branch))
          invalidVertices->insert(vertex);
      }
      return false;
    }
    const Eigen::Vector3d origin = firstMoment / totalArea;

    Eigen::Matrix3d covariance = Eigen::Matrix3d::Zero();
    for(const std::size_t faceIndex : faces->second) {
      std::vector<int> vertices;
      for(const int vertex : vor.faces[faceIndex].verts) {
        if(vertex >= 0 &&
           3 * vertex + 2 < static_cast<int>(originalVoronoiVertices.size()))
          vertices.push_back(vertex);
      }
      if(vertices.size() < 3) continue;
      Eigen::Vector3d center = Eigen::Vector3d::Zero();
      for(const int vertex : vertices)
        center += pointAtFraction(vertex, branch, fraction);
      center /= static_cast<double>(vertices.size());
      for(std::size_t local = 0; local < vertices.size(); ++local) {
        const Eigen::Vector3d a =
            pointAtFraction(vertices[local], branch, fraction);
        const Eigen::Vector3d b = pointAtFraction(
            vertices[(local + 1) % vertices.size()], branch, fraction);
        const double area = 0.5 * ((a - center).cross(b - center)).norm();
        if(!(area > std::numeric_limits<double>::min())) continue;
        const Eigen::Vector3d q0 = center - origin;
        const Eigen::Vector3d q1 = a - origin;
        const Eigen::Vector3d q2 = b - origin;
        const Eigen::Vector3d sum = q0 + q1 + q2;
        covariance += (area / 12.0) *
            (sum * sum.transpose() + q0 * q0.transpose() +
             q1 * q1.transpose() + q2 * q2.transpose());
      }
    }
    covariance /= totalArea;
    Eigen::SelfAdjointEigenSolver<Eigen::Matrix3d> eigen(covariance);
    if(eigen.info() != Eigen::Success) {
      if(invalidVertices) {
        for(const int vertex : targetVerticesByBranch.at(branch))
          invalidVertices->insert(vertex);
      }
      return false;
    }
    Eigen::Vector3d normal = eigen.eigenvectors().col(0).normalized();
    if(normal.dot(orientedNormal) < 0.0) normal = -normal;

    constexpr double minimumSignedRatio = 1e-10;
    bool valid = true;
    for(const std::size_t faceIndex : faces->second) {
      std::vector<int> vertices;
      for(const int vertex : vor.faces[faceIndex].verts) {
        if(vertex >= 0 &&
           3 * vertex + 2 < static_cast<int>(originalVoronoiVertices.size()))
          vertices.push_back(vertex);
      }
      if(vertices.size() < 3) continue;
      Eigen::Vector3d center = Eigen::Vector3d::Zero();
      for(const int vertex : vertices)
        center += pointAtFraction(vertex, branch, fraction);
      center /= static_cast<double>(vertices.size());
      for(std::size_t local = 0; local < vertices.size(); ++local) {
        const Eigen::Vector3d a =
            pointAtFraction(vertices[local], branch, fraction);
        const Eigen::Vector3d b = pointAtFraction(
            vertices[(local + 1) % vertices.size()], branch, fraction);
        const Eigen::Vector3d cross = (a - center).cross(b - center);
        const double norm = cross.norm();
        if(!(norm > std::numeric_limits<double>::min()) ||
           fanOrientationSigns[faceIndex][local] * cross.dot(normal) <=
               minimumSignedRatio * norm) {
          valid = false;
          if(!invalidVertices) return false;
          for(const int vertex : vertices) {
            const auto target = targetByVertex.find(vertex);
            if(target != targetByVertex.end() &&
               targetUsesBranch(target->second, branch))
              invalidVertices->insert(vertex);
          }
          break;
        }
      }
    }
    return valid;
  };

  if(buildTopology) for(const auto &branchFaces : facesByBranch) {
    for(const std::size_t faceIndex : branchFaces.second) {
      for(const int vertex : vor.faces[faceIndex].verts) {
        if(vertex >= 0)
          retainedFacesAtVertex[vertex].push_back(faceIndex);
      }
    }
  }
  // Preserve the exact old face/edge traversal order, but compile it once.
  // Regularization used to rescan every edge of every incident polygon each
  // time a vertex left the queue.
  const auto regularizationNeighborsAreCompatible =
      [&](int first, int second) {
    return first >= 0 && second >= 0 &&
        first < static_cast<int>(targetAtVertex.size()) &&
        second < static_cast<int>(targetAtVertex.size()) &&
        targetAtVertex[first] && targetAtVertex[second] &&
        targetsShareBranch(*targetAtVertex[first], *targetAtVertex[second]);
  };
  if(buildTopology)
    regularizationNeighborOffsets.assign(retainedVertexCount + 1, 0);
  if(buildTopology) for(const auto &incident : retainedFacesAtVertex) {
    const int vertex = incident.first;
    if(vertex < 0 || vertex >= static_cast<int>(retainedVertexCount))
      continue;
    std::size_t count = 0;
    for(const std::size_t faceIndex : incident.second) {
      if(faceIndex >= vor.faces.size()) continue;
      const std::vector<int> &vertices = vor.faces[faceIndex].verts;
      for(std::size_t local = 0; local < vertices.size(); ++local) {
        const int first = vertices[local];
        const int second = vertices[(local + 1) % vertices.size()];
        if(first == vertex &&
           regularizationNeighborsAreCompatible(first, second))
          ++count;
        if(second == vertex &&
           regularizationNeighborsAreCompatible(second, first))
          ++count;
      }
    }
    regularizationNeighborOffsets[vertex + 1] = count;
  }
  if(buildTopology)
    std::partial_sum(regularizationNeighborOffsets.begin(),
                     regularizationNeighborOffsets.end(),
                     regularizationNeighborOffsets.begin());
  std::vector<std::size_t> regularizationNeighborCursor;
  if(buildTopology) {
    regularizationNeighbors.resize(regularizationNeighborOffsets.back());
    regularizationNeighborCursor = regularizationNeighborOffsets;
  }
  if(buildTopology) for(const auto &incident : retainedFacesAtVertex) {
    const int vertex = incident.first;
    if(vertex < 0 || vertex >= static_cast<int>(retainedVertexCount))
      continue;
    for(const std::size_t faceIndex : incident.second) {
      if(faceIndex >= vor.faces.size()) continue;
      const std::vector<int> &vertices = vor.faces[faceIndex].verts;
      for(std::size_t local = 0; local < vertices.size(); ++local) {
        const int first = vertices[local];
        const int second = vertices[(local + 1) % vertices.size()];
        if(first == vertex &&
           regularizationNeighborsAreCompatible(first, second))
          regularizationNeighbors[
              regularizationNeighborCursor[vertex]++] = second;
        if(second == vertex &&
           regularizationNeighborsAreCompatible(second, first))
          regularizationNeighbors[
              regularizationNeighborCursor[vertex]++] = first;
      }
    }
  }
  topology.ready = true;

  const auto captureIncidentFanCrosses = [&](int vertex) {
    std::map<std::size_t, std::vector<Eigen::Vector3d>> crossesByFace;
    const auto incident = retainedFacesAtVertex.find(vertex);
    if(incident == retainedFacesAtVertex.end()) return crossesByFace;
    for(const std::size_t faceIndex : incident->second) {
      const int branch = vor.faceColors[faceIndex];
      std::vector<int> vertices;
      Eigen::Vector3d center = Eigen::Vector3d::Zero();
      for(const int faceVertex : vor.faces[faceIndex].verts) {
        if(faceVertex < 0 ||
           3 * faceVertex + 2 >=
               static_cast<int>(originalVoronoiVertices.size()))
          continue;
        vertices.push_back(faceVertex);
        center += pointAtFraction(faceVertex, branch, 1.0);
      }
      if(vertices.size() < 3) continue;
      center /= static_cast<double>(vertices.size());
      auto &crosses = crossesByFace[faceIndex];
      crosses.reserve(vertices.size());
      for(std::size_t local = 0; local < vertices.size(); ++local) {
        const Eigen::Vector3d a =
            pointAtFraction(vertices[local], branch, 1.0);
        const Eigen::Vector3d b = pointAtFraction(
            vertices[(local + 1) % vertices.size()], branch, 1.0);
        crosses.push_back((a - center).cross(b - center));
      }
    }
    return crossesByFace;
  };

  const auto incidentFanOrientationIsPreserved =
      [&](int vertex,
          const std::map<std::size_t,
                         std::vector<Eigen::Vector3d>> &before) {
    constexpr double minimumAreaFraction = 0.01;
    const auto after = captureIncidentFanCrosses(vertex);
    if(after.size() != before.size()) return false;
    for(const auto &faceCrosses : before) {
      const auto afterFace = after.find(faceCrosses.first);
      if(afterFace == after.end() ||
         afterFace->second.size() != faceCrosses.second.size())
        return false;
      for(std::size_t local = 0; local < faceCrosses.second.size(); ++local) {
        const Eigen::Vector3d &oldCross = faceCrosses.second[local];
        const Eigen::Vector3d &newCross = afterFace->second[local];
        const double oldNorm = oldCross.norm();
        const double newNorm = newCross.norm();
        if(!(oldNorm > std::numeric_limits<double>::min())) continue;
        if(!(newNorm >= minimumAreaFraction * oldNorm) ||
           newCross.dot(oldCross) <= 0.0)
          return false;
      }
    }
    return true;
  };

  std::size_t projected = 0;
  std::size_t projectedRegular = 0;
  std::size_t projectedSimpleBoundary = 0;
  std::size_t projectedTripleLine = 0;
  std::size_t topologyLimited = 0;
  std::size_t topologyRejected = 0;
  std::size_t stationaryFinalResidualFallbacks = 0;
  std::size_t repeatedCadSourcePairTopologyLimited = 0;
  double repeatedCadSourcePairAcceptedFractionSum = 0.0;
  double residualBeforeSum = 0.0;
  double residualAfterSum = 0.0;
  double maximumDisplacement = 0.0;
  constexpr double minimumAcceptedFraction =
      1.0 / static_cast<double>(std::size_t{1} << 24);
  std::size_t originalAdjacentNormalViolations = 0;
  std::set<int> originalConnectivityInvalidVertices;
  for(const auto &branch : targetVerticesByBranch) {
    updateBranchFanGeometry(branch.first, 0.0);
    preservesBranchFanOrientation(
        branch.first, &originalConnectivityInvalidVertices);
    preservesAdjacentFanNormalOrientation(
        branch.first, nullptr, &originalAdjacentNormalViolations);
  }
  if(!originalConnectivityInvalidVertices.empty() ||
     originalAdjacentNormalViolations != 0)
    throw std::runtime_error(
        "local mid-surface projection requires a valid filtered MAT fan");
  // Apply the complete projection synchronously. Testing one vertex at a
  // time is order-dependent: a vertex can appear to invert its fan only
  // because its neighbors are still at their original positions, even when
  // the fully projected patch is perfectly valid.
  for(const int vertex : candidates) {
    const auto target = targetByVertex.find(vertex);
    if(target == targetByVertex.end()) continue;
    acceptedFractionByVertex.at(vertex) = 1.0;
  }

  // The preceding line searches are deliberately local, but accepting a
  // sequence of individually legal moves can still rotate a fan little by
  // little until its final orientation is opposite to the original one.
  // Audit every branch against the immutable pre-projection fan and reduce
  // all projected vertices of an offending face together.  At zero fraction
  // the original configuration is recovered, so this process always has a
  // legal endpoint and no projected triangle can cross its original normal.
  std::size_t globalTopologyBacktracks = 0;
  std::size_t adjacentNormalBacktracks = 0;
  std::size_t topologyAuditBranchVisits = 0;
  std::vector<unsigned char> globallyLimitedVertex(
      retainedVertexCount, 0);
  std::vector<unsigned char> adjacentNormalLimitedVertex(
      retainedVertexCount, 0);
  std::size_t globallyLimitedVertexCount = 0;
  std::size_t adjacentNormalLimitedVertexCount = 0;
  const auto markCountedVertex = [](int vertex,
                                    std::vector<unsigned char> &marked,
                                    std::size_t &count) {
    if(vertex < 0 || vertex >= static_cast<int>(marked.size()) ||
       marked[vertex])
      return;
    marked[vertex] = 1;
    ++count;
  };
  // A fraction field that already satisfies the displacement edge constraint
  // can only become invalid next to a vertex whose fraction was reduced by
  // the topology audit.  Keep those vertices as the exact propagation
  // frontier instead of re-enqueuing every projection target after each
  // coupled audit.
  std::vector<int> regularizationSeeds;
  std::vector<unsigned char> regularizationSeeded(
      retainedVertexCount, 0);
  const auto markRegularizationSeed = [&](int vertex) {
    if(vertex < 0 ||
       vertex >= static_cast<int>(regularizationSeeded.size()) ||
       regularizationSeeded[vertex])
      return;
    regularizationSeeded[vertex] = 1;
    regularizationSeeds.push_back(vertex);
  };
  std::set<int> dirtyTopologyBranches;
  for(const auto &branchTargets : targetVerticesByBranch)
    dirtyTopologyBranches.insert(branchTargets.first);
  const auto markVertexBranchesDirty = [&](int vertex) {
    if(vertex < 0 || vertex >= static_cast<int>(targetAtVertex.size()) ||
       !targetAtVertex[vertex])
      return;
    if(!targetAtVertex[vertex]->branches) return;
    dirtyTopologyBranches.insert(
        targetAtVertex[vertex]->branches->begin(),
        targetAtVertex[vertex]->branches->end());
  };
  std::vector<std::uint32_t> dirtyFanFaceEpoch(vor.faces.size(), 0);
  std::uint32_t nextDirtyFanFaceEpoch = 0;
  std::vector<std::uint32_t> invalidVertexEpoch(retainedVertexCount, 0);
  std::vector<std::uint32_t> adjacentInvalidVertexEpoch(
      retainedVertexCount, 0);
  std::uint32_t nextInvalidVertexEpoch = 0;
  const std::size_t inactiveTopologyIndex =
      std::numeric_limits<std::size_t>::max();
  std::vector<std::size_t> invalidFanFacePosition(
      vor.faces.size(), inactiveTopologyIndex);
  const auto auditBranchesAndBacktrack = [&]() {
    bool anyFractionChanged = false;
    const std::set<int> branchesToAudit = dirtyTopologyBranches;
    dirtyTopologyBranches.clear();
    for(const auto &branchTargets : targetVerticesByBranch) {
      if(branchesToAudit.count(branchTargets.first) == 0) continue;
      ++topologyAuditBranchVisits;
      const auto branchFaces = facesByBranch.find(branchTargets.first);
      const auto branchAdjacencies =
          fanNormalAdjacenciesByBranch.find(branchTargets.first);
      const bool geometryInitialized =
          branchFaces != facesByBranch.end() &&
          branchAdjacencies != fanNormalAdjacenciesByBranch.end() &&
          updateBranchFanGeometry(branchTargets.first, 1.0);
      std::vector<std::size_t> invalidFanFaces;
      const auto setFanFaceInvalid =
          [&](std::size_t faceIndex, bool invalid) {
        if(faceIndex >= invalidFanFacePosition.size()) return;
        std::size_t &position = invalidFanFacePosition[faceIndex];
        if(invalid) {
          if(position != inactiveTopologyIndex) return;
          position = invalidFanFaces.size();
          invalidFanFaces.push_back(faceIndex);
        }
        else {
          if(position == inactiveTopologyIndex) return;
          const std::size_t lastFace = invalidFanFaces.back();
          invalidFanFaces[position] = lastFace;
          invalidFanFacePosition[lastFace] = position;
          invalidFanFaces.pop_back();
          position = inactiveTopologyIndex;
        }
      };
      if(branchFaces != facesByBranch.end()) {
        invalidFanFaces.reserve(branchFaces->second.size() / 8 + 1);
        if(geometryInitialized) {
          for(const std::size_t faceIndex : branchFaces->second)
            if(!fanFaceOrientationIsPreserved(faceIndex))
              setFanFaceInvalid(faceIndex, true);
        }
      }
      std::vector<std::size_t> invalidAdjacentNormalPosition;
      std::vector<std::size_t> invalidAdjacentNormals;
      const auto setAdjacentNormalInvalid =
          [&](std::size_t adjacency, bool invalid) {
        if(adjacency >= invalidAdjacentNormalPosition.size()) return;
        std::size_t &position = invalidAdjacentNormalPosition[adjacency];
        if(invalid) {
          if(position != inactiveTopologyIndex) return;
          position = invalidAdjacentNormals.size();
          invalidAdjacentNormals.push_back(adjacency);
        }
        else {
          if(position == inactiveTopologyIndex) return;
          const std::size_t lastAdjacency = invalidAdjacentNormals.back();
          invalidAdjacentNormals[position] = lastAdjacency;
          invalidAdjacentNormalPosition[lastAdjacency] = position;
          invalidAdjacentNormals.pop_back();
          position = inactiveTopologyIndex;
        }
      };
      if(branchAdjacencies != fanNormalAdjacenciesByBranch.end()) {
        invalidAdjacentNormalPosition.assign(
            branchAdjacencies->second.size(), inactiveTopologyIndex);
        invalidAdjacentNormals.reserve(
            branchAdjacencies->second.size() / 8 + 1);
        if(geometryInitialized) {
          for(std::size_t adjacency = 0;
              adjacency < branchAdjacencies->second.size(); ++adjacency)
            setAdjacentNormalInvalid(
                adjacency, !adjacentFanNormalOrientationIsPreserved(
                               branchAdjacencies->second[adjacency]));
        }
      }
      std::vector<int> invalidVertices;
      std::vector<int> adjacentNormalInvalidVertices;
      std::vector<int> mergedInvalidVertices;
      std::vector<int> changedVertices;
      std::vector<std::size_t> dirtyFaces;
      invalidVertices.reserve(branchTargets.second.size());
      adjacentNormalInvalidVertices.reserve(branchTargets.second.size());
      mergedInvalidVertices.reserve(branchTargets.second.size());
      changedVertices.reserve(branchTargets.second.size());
      for(std::size_t iteration = 0; iteration < 80; ++iteration) {
        ++nextInvalidVertexEpoch;
        if(nextInvalidVertexEpoch == 0) {
          std::fill(invalidVertexEpoch.begin(), invalidVertexEpoch.end(), 0);
          std::fill(adjacentInvalidVertexEpoch.begin(),
                    adjacentInvalidVertexEpoch.end(), 0);
          ++nextInvalidVertexEpoch;
        }
        invalidVertices.clear();
        adjacentNormalInvalidVertices.clear();
        const auto appendInvalidVertex = [&](int vertex, bool adjacent) {
          if(vertex < 0 ||
             vertex >= static_cast<int>(targetAtVertex.size()) ||
             !targetAtVertex[vertex] ||
             !targetUsesBranch(*targetAtVertex[vertex],
                               branchTargets.first))
            return;
          std::vector<std::uint32_t> &epochs = adjacent ?
              adjacentInvalidVertexEpoch : invalidVertexEpoch;
          if(epochs[vertex] == nextInvalidVertexEpoch) return;
          epochs[vertex] = nextInvalidVertexEpoch;
          (adjacent ? adjacentNormalInvalidVertices : invalidVertices)
              .push_back(vertex);
        };
        const std::size_t adjacentNormalViolations =
            invalidAdjacentNormals.size();
        if(geometryInitialized) {
          for(const std::size_t faceIndex : invalidFanFaces) {
            for(const int vertex : retainedFanVertices[faceIndex])
              appendInvalidVertex(vertex, false);
          }
          for(const std::size_t adjacency : invalidAdjacentNormals) {
            const ProjectionFanNormalAdjacency &invalid =
                branchAdjacencies->second[adjacency];
            for(const std::size_t faceIndex :
                {invalid.first.face, invalid.second.face})
              for(const int vertex : retainedFanVertices[faceIndex])
                appendInvalidVertex(vertex, true);
          }
        }
        std::sort(invalidVertices.begin(), invalidVertices.end());
        std::sort(adjacentNormalInvalidVertices.begin(),
                  adjacentNormalInvalidVertices.end());
        const bool preservesOriginalFan =
            geometryInitialized && invalidFanFaces.empty();
        const bool preservesAdjacentNormals =
            geometryInitialized && adjacentNormalViolations == 0;
        constexpr bool verifyIncrementalTopologyGuard = false;
        if(verifyIncrementalTopologyGuard) {
          std::set<int> scannedInvalidVertices;
          std::set<int> scannedAdjacentInvalidVertices;
          std::size_t scannedAdjacentViolations = 0;
          const bool scannedGeometry =
              updateBranchFanGeometry(branchTargets.first, 1.0);
          const bool scannedFan = scannedGeometry &&
              preservesBranchFanOrientation(
                  branchTargets.first, &scannedInvalidVertices);
          const bool scannedAdjacent = scannedGeometry &&
              preservesAdjacentFanNormalOrientation(
                  branchTargets.first, &scannedAdjacentInvalidVertices,
                  &scannedAdjacentViolations);
          const std::set<int> incrementalInvalidVertices(
              invalidVertices.begin(), invalidVertices.end());
          const std::set<int> incrementalAdjacentInvalidVertices(
              adjacentNormalInvalidVertices.begin(),
              adjacentNormalInvalidVertices.end());
          if(scannedFan != preservesOriginalFan ||
             scannedAdjacent != preservesAdjacentNormals ||
             scannedInvalidVertices != incrementalInvalidVertices ||
             scannedAdjacentInvalidVertices !=
                 incrementalAdjacentInvalidVertices ||
             scannedAdjacentViolations != adjacentNormalViolations) {
            throw std::runtime_error(
                "incremental topology guard differs from full audit");
          }
        }
        if(preservesOriginalFan && preservesAdjacentNormals) {
          dirtyTopologyBranches.erase(branchTargets.first);
          break;
        }
        if(!preservesAdjacentNormals) {
          ++adjacentNormalBacktracks;
          for(const int vertex : adjacentNormalInvalidVertices)
            markCountedVertex(
                vertex, adjacentNormalLimitedVertex,
                adjacentNormalLimitedVertexCount);
          mergedInvalidVertices.clear();
          mergedInvalidVertices.reserve(
              invalidVertices.size() +
              adjacentNormalInvalidVertices.size());
          std::set_union(
              invalidVertices.begin(), invalidVertices.end(),
              adjacentNormalInvalidVertices.begin(),
              adjacentNormalInvalidVertices.end(),
              std::back_inserter(mergedInvalidVertices));
          invalidVertices.swap(mergedInvalidVertices);
        }
        if(invalidVertices.empty()) {
          invalidVertices.assign(branchTargets.second.begin(),
                                 branchTargets.second.end());
          std::sort(invalidVertices.begin(), invalidVertices.end());
          invalidVertices.erase(
              std::unique(invalidVertices.begin(), invalidVertices.end()),
              invalidVertices.end());
        }
        bool changed = false;
        changedVertices.clear();
        changedVertices.reserve(invalidVertices.size());
        for(const int vertex : invalidVertices) {
          if(vertex < 0 ||
             vertex >= static_cast<int>(acceptedFractionAtVertex.size()) ||
             !acceptedFractionAtVertex[vertex] ||
             !(*acceptedFractionAtVertex[vertex] > 0.0))
            continue;
          const double reducedFraction =
              *acceptedFractionAtVertex[vertex] <= minimumAcceptedFraction ?
                  0.0 : 0.5 * *acceptedFractionAtVertex[vertex];
          if(!(reducedFraction < *acceptedFractionAtVertex[vertex]))
            continue;
          *acceptedFractionAtVertex[vertex] = reducedFraction;
          markCountedVertex(
              vertex, globallyLimitedVertex,
              globallyLimitedVertexCount);
          markVertexBranchesDirty(vertex);
          markRegularizationSeed(vertex);
          changedVertices.push_back(vertex);
          changed = true;
        }
        ++globalTopologyBacktracks;
        if(changed) {
          anyFractionChanged = true;
          ++nextDirtyFanFaceEpoch;
          if(nextDirtyFanFaceEpoch == 0) {
            std::fill(dirtyFanFaceEpoch.begin(), dirtyFanFaceEpoch.end(), 0);
            ++nextDirtyFanFaceEpoch;
          }
          dirtyFaces.clear();
          for(const int vertex : changedVertices) {
            const auto incident = retainedFacesAtVertex.find(vertex);
            if(incident == retainedFacesAtVertex.end()) continue;
            for(const std::size_t faceIndex : incident->second) {
              if(faceIndex >= vor.faceColors.size() ||
                 vor.faceColors[faceIndex] != branchTargets.first ||
                 dirtyFanFaceEpoch[faceIndex] == nextDirtyFanFaceEpoch)
                continue;
              dirtyFanFaceEpoch[faceIndex] = nextDirtyFanFaceEpoch;
              dirtyFaces.push_back(faceIndex);
            }
          }
          bool dirtyGeometryValid = geometryInitialized;
          for(const std::size_t faceIndex : dirtyFaces) {
            if(!updateFanFaceGeometry(
                   faceIndex, branchTargets.first, 1.0)) {
              dirtyGeometryValid = false;
              break;
            }
            setFanFaceInvalid(
                faceIndex, !fanFaceOrientationIsPreserved(faceIndex));
          }
          if(!dirtyGeometryValid) {
            if(branchFaces != facesByBranch.end())
              for(const std::size_t faceIndex : branchFaces->second)
                setFanFaceInvalid(faceIndex, true);
            if(branchAdjacencies != fanNormalAdjacenciesByBranch.end())
              for(std::size_t adjacency = 0;
                  adjacency < branchAdjacencies->second.size(); ++adjacency)
                setAdjacentNormalInvalid(adjacency, true);
          }
          else {
            for(const std::size_t faceIndex : dirtyFaces) {
              for(const std::size_t adjacency :
                  fanNormalAdjacencyIndicesAtFace[faceIndex]) {
                const ProjectionFanNormalAdjacency &candidate =
                    branchAdjacencies->second[adjacency];
                setAdjacentNormalInvalid(
                    adjacency,
                    !adjacentFanNormalOrientationIsPreserved(candidate));
              }
            }
          }
          continue;
        }

        // The only guaranteed backtracking endpoint is the original point.
        // Even a tiny positive motion can overturn a near-degenerate fan.
        bool fallbackChanged = false;
        for(const int vertex : branchTargets.second) {
          double &acceptedFraction = acceptedFractionByVertex.at(vertex);
          if(acceptedFraction > 0.0) {
            acceptedFraction = 0.0;
            markVertexBranchesDirty(vertex);
            markRegularizationSeed(vertex);
            fallbackChanged = true;
          }
          markCountedVertex(
              vertex, globallyLimitedVertex,
              globallyLimitedVertexCount);
        }
        anyFractionChanged = anyFractionChanged || fallbackChanged;
        break;
      }
      for(const std::size_t faceIndex : invalidFanFaces)
        invalidFanFacePosition[faceIndex] = inactiveTopologyIndex;
    }
    return anyFractionChanged;
  };

  // The local mean surface supplies the requested position, but this
  // checkpoint must remain a valid triangulated MAT. Reduce only the local
  // projection fraction when the inherited fan would otherwise turn over.
  constexpr bool backtrackProjectedPositionsForOldConnectivity = true;
  if(backtrackProjectedPositionsForOldConnectivity)
    auditBranchesAndBacktrack();

  // Smooth the extra displacement gradient introduced by local backtracking.
  // Fractions alone are not geometric: halving a micron-scale correction
  // must not freeze neighbors whose requested displacement is quite different.
  // On an edge, bound the fraction jump times the larger requested motion
  // by one quarter of the original edge length. This leaves smoothly varying
  // full targets unchanged and confines a blocked point's influence to its
  // physical neighborhood. Only reduce fractions, then re-audit the geometry:
  // returning nonuniformly toward the original mesh is not necessarily safe.
  std::size_t acceptedFractionRegularizationPasses = 0;
  std::size_t acceptedFractionRegularizationRelaxations = 0;
  std::vector<unsigned char> acceptedFractionRegularizedVertex(
      retainedVertexCount, 0);
  std::size_t acceptedFractionRegularizedVertexCount = 0;
  std::vector<unsigned char> regularizationQueued(
      retainedVertexCount, 0);
  std::vector<int> regularizationPending;
  regularizationPending.reserve(targetByVertex.size());
  const auto regularizeAcceptedFractions = [&]() {
    if(regularizationSeeds.empty()) return false;
    bool anyFractionChanged = false;
    regularizationPending.clear();
    for(const int vertex : regularizationSeeds) {
      regularizationSeeded[vertex] = 0;
      if(regularizationQueued[vertex]) continue;
      regularizationPending.push_back(vertex);
      regularizationQueued[vertex] = 1;
    }
    regularizationSeeds.clear();
    std::size_t pendingHead = 0;

    const auto relaxNeighbor = [&](int vertex, int neighbor) {
      if(vertex < 0 || neighbor < 0 ||
         vertex >= static_cast<int>(acceptedFractionAtVertex.size()) ||
         neighbor >= static_cast<int>(acceptedFractionAtVertex.size()) ||
         !acceptedFractionAtVertex[vertex] ||
         !acceptedFractionAtVertex[neighbor])
        return;
      const ProjectionTarget &first = *targetAtVertex[vertex];
      const ProjectionTarget &second = *targetAtVertex[neighbor];
      const double motion = std::max(
          (first.requested - first.original).norm(),
          (second.requested - second.original).norm());
      if(!(motion > std::numeric_limits<double>::min())) return;
      const double edgeLength = (second.original - first.original).norm();
      const double limit = *acceptedFractionAtVertex[vertex] +
          0.25 * edgeLength / motion;
      if(!(*acceptedFractionAtVertex[neighbor] > limit)) return;
      *acceptedFractionAtVertex[neighbor] = limit;
      markVertexBranchesDirty(neighbor);
      markCountedVertex(
          neighbor, acceptedFractionRegularizedVertex,
          acceptedFractionRegularizedVertexCount);
      ++acceptedFractionRegularizationRelaxations;
      anyFractionChanged = true;
      if(neighbor >= 0 &&
         neighbor < static_cast<int>(regularizationQueued.size()) &&
         !regularizationQueued[neighbor]) {
        regularizationPending.push_back(neighbor);
        regularizationQueued[neighbor] = 1;
      }
    };

    while(pendingHead < regularizationPending.size()) {
      const int vertex = regularizationPending[pendingHead++];
      regularizationQueued[vertex] = 0;
      if(vertex < 0 ||
         vertex + 1 >=
             static_cast<int>(regularizationNeighborOffsets.size()))
        continue;
      for(std::size_t neighbor = regularizationNeighborOffsets[vertex];
          neighbor < regularizationNeighborOffsets[vertex + 1]; ++neighbor)
        relaxNeighbor(vertex, regularizationNeighbors[neighbor]);
    }
    if(anyFractionChanged)
      ++acceptedFractionRegularizationPasses;
    return anyFractionChanged;
  };

  std::size_t topologyCouplingIterations = 0;
  if(backtrackProjectedPositionsForOldConnectivity) {
    bool topologyCouplingConverged = false;
    for(std::size_t couplingIteration = 0; couplingIteration < 256;
        ++couplingIteration) {
      ++topologyCouplingIterations;
      const bool regularized = regularizeAcceptedFractions();
      const bool topologyBacktracked = auditBranchesAndBacktrack();
      if(!regularized && !topologyBacktracked) {
        topologyCouplingConverged = true;
        break;
      }
    }
    if(!topologyCouplingConverged)
      throw std::runtime_error(
          "local mid-surface topology guard did not converge");
  }
  const auto projectionTopologyGuarded =
      std::chrono::steady_clock::now();

  double minimumPositiveAcceptedFraction = 1.0;
  double maximumBacktrackDisplacementGradient = 0.0;
  std::size_t acceptedFractionBelowHalf = 0;
  std::size_t acceptedFractionBelowQuarter = 0;
  for(const auto &target : targetByVertex) {
    const double accepted = acceptedFractionByVertex[target.first];
    if(accepted > 0.0)
      minimumPositiveAcceptedFraction = std::min(
          minimumPositiveAcceptedFraction, accepted);
    if(accepted < 0.5) ++acceptedFractionBelowHalf;
    if(accepted < 0.25) ++acceptedFractionBelowQuarter;
  }
  for(const auto &edgeEntry : edgeUses) {
    const int firstVertex = edgeEntry.first.a;
    const int secondVertex = edgeEntry.first.b;
    if(firstVertex < 0 || secondVertex < 0 ||
       firstVertex >= static_cast<int>(acceptedFractionAtVertex.size()) ||
       secondVertex >= static_cast<int>(acceptedFractionAtVertex.size()) ||
       !acceptedFractionAtVertex[firstVertex] ||
       !acceptedFractionAtVertex[secondVertex])
      continue;
    const double first = acceptedFractionByVertex[firstVertex];
    const double second = acceptedFractionByVertex[secondVertex];
    const ProjectionTarget &firstTarget = *targetAtVertex[firstVertex];
    const ProjectionTarget &secondTarget = *targetAtVertex[secondVertex];
    const double edgeLength =
        (secondTarget.original - firstTarget.original).norm();
    if(!(edgeLength > 0.0)) continue;
    const double motion = std::max(
        (firstTarget.requested - firstTarget.original).norm(),
        (secondTarget.requested - secondTarget.original).norm());
    maximumBacktrackDisplacementGradient = std::max(
        maximumBacktrackDisplacementGradient,
        std::abs(first - second) * motion / edgeLength);
  }

  std::size_t remainingAdjacentNormalViolations = 0;
  std::set<int> fullProjectionConnectivityInvalidVertices;
  for(const auto &branchTargets : targetVerticesByBranch) {
    std::set<int> branchInvalidVertices;
    updateBranchFanGeometry(branchTargets.first, 1.0);
    preservesBranchFanOrientation(
        branchTargets.first, &branchInvalidVertices);
    fullProjectionConnectivityInvalidVertices.insert(
        branchInvalidVertices.begin(), branchInvalidVertices.end());
    std::size_t branchViolations = 0;
    preservesAdjacentFanNormalOrientation(
        branchTargets.first, nullptr, &branchViolations);
    remainingAdjacentNormalViolations += branchViolations;
  }
  if(!fullProjectionConnectivityInvalidVertices.empty() ||
     remainingAdjacentNormalViolations != 0)
    throw std::runtime_error(
        "local mid-surface projection failed its final topology audit");


  struct ProjectionErrorSummary {
    std::vector<double> targetGaps;
    double requestedResidualSum = 0.0;
    double acceptedResidualSum = 0.0;
    std::size_t aboveOnePercent = 0;
    std::size_t aboveFivePercent = 0;
  };
  std::array<ProjectionErrorSummary, 3> projectionErrors;
  for(const auto &targetEntry : targetByVertex) {
    const int vertex = targetEntry.first;
    const ProjectionTarget &target = targetEntry.second;
    double acceptedFraction = acceptedFractionByVertex.at(vertex);
    Eigen::Vector3d point = target.original +
        acceptedFraction * (target.requested - target.original);
    double residualAfter = target.residualBefore;
    if(target.hasFiniteProjectionConstraint) {
      residualAfter = target.explicitPointConstraint ?
          (point - target.requested).norm() :
          (target.tripleLine ?
               planeResidual(point, target.constraintPlanes) :
               projectionResidual(point, vertex));
      if(!std::isfinite(residualAfter) ||
         residualAfter > target.residualBefore + 1e-14) {
        // Roundoff at a very small accepted fraction can make the measured
        // residual infinitesimally worse. The original point is valid, but a
        // post-guard reset would invalidate the audited displacement
        // field. Keep the already audited position and clamp the reported
        // residual to the original value instead.
        residualAfter = target.residualBefore;
        ++stationaryFinalResidualFallbacks;
      }
    }
    const auto toArray = [](const Eigen::Vector3d &value) {
      return std::array<double, 3>{value.x(), value.y(), value.z()};
    };
    if(storeDiagnostics) {
      LocalMidSurfaceProjectionDiagnostic diagnostic;
      diagnostic.original = toArray(target.original);
      diagnostic.rawRequested = toArray(target.rawRequested);
      diagnostic.preSplineRequested =
          toArray(target.preSplineRequested);
      diagnostic.filteredRequested = toArray(target.requested);
      diagnostic.accepted = toArray(point);
      diagnostic.midSurfaceNormal = toArray(target.midSurfaceNormal);
      diagnostic.repeatedSourceContactA =
          toArray(target.repeatedSourceContactA);
      diagnostic.repeatedSourceContactB =
          toArray(target.repeatedSourceContactB);
      diagnostic.acceptedFraction = acceptedFraction;
      diagnostic.meanSurfaceDistance = residualAfter;
      diagnostic.projectionCandidate = true;
      diagnostic.surfaceClassifiedOpposites = true;
      diagnostic.simpleBoundary = target.simpleBoundary;
      diagnostic.tripleLine = target.tripleLine;
      diagnostic.repeatedCadSourcePair = target.repeatedCadSourcePair;
      diagnostic.tripleSplineTarget = target.tripleSplineTarget;
      localMidSurfaceProjectionDiagnostics[vertex] = diagnostic;
    }
    if(target.repeatedCadSourcePair) {
      repeatedCadSourcePairAcceptedFractionSum += acceptedFraction;
      if(acceptedFraction < 1.0)
        ++repeatedCadSourcePairTopologyLimited;
    }
    if(acceptedFraction < 1.0) ++topologyLimited;
    if(acceptedFraction == 0.0) ++topologyRejected;
    ProjectionErrorSummary &errors = projectionErrors[
        target.tripleLine ? 2 : (target.simpleBoundary ? 1 : 0)];
    const double gap = (point - target.requested).norm();
    errors.targetGaps.push_back(gap);
    errors.acceptedResidualSum += residualAfter;
    const double requestedResidual = target.explicitPointConstraint ? 0.0 :
        (target.tripleLine ?
             planeResidual(target.requested, target.constraintPlanes) :
             projectionResidual(target.requested, vertex));
    if(std::isfinite(requestedResidual))
      errors.requestedResidualSum += requestedResidual;
    double supportScale = 0.0;
    const std::size_t firstPlane = planeCache.midPlaneOffsetsAtVertex[vertex];
    const std::size_t endPlane = planeCache.midPlaneOffsetsAtVertex[vertex + 1];
    for(std::size_t plane = firstPlane; plane < endPlane; ++plane)
      supportScale += planeCache.midPlanesAtVertex[plane]->scale;
    if(endPlane > firstPlane) supportScale /= endPlane - firstPlane;
    if(supportScale > 0.0) {
      if(gap > 0.01 * supportScale) ++errors.aboveOnePercent;
      if(gap > 0.05 * supportScale) ++errors.aboveFivePercent;
    }
    vor.vertices[3 * vertex] = point.x();
    vor.vertices[3 * vertex + 1] = point.y();
    vor.vertices[3 * vertex + 2] = point.z();
    ++projected;
    if(target.tripleLine)
      ++projectedTripleLine;
    else if(target.simpleBoundary)
      ++projectedSimpleBoundary;
    else
      ++projectedRegular;
    residualBeforeSum += target.residualBefore;
    residualAfterSum += residualAfter;
    maximumDisplacement = std::max(
        maximumDisplacement, (point - target.original).norm());
  }

  std::size_t checkedRetainedBoundaryVertices = 0;
  std::size_t movedRetainedBoundaryVertices = 0;
  for(const int vertex : retainedBoundaryVertices) {
    if(vertex < 0 ||
       3 * vertex + 2 >= static_cast<int>(vor.vertices.size()) ||
       3 * vertex + 2 >=
           static_cast<int>(originalVoronoiVertices.size()))
      continue;
    ++checkedRetainedBoundaryVertices;
    if(vor.vertices[3 * vertex] != originalVoronoiVertices[3 * vertex] ||
       vor.vertices[3 * vertex + 1] !=
           originalVoronoiVertices[3 * vertex + 1] ||
       vor.vertices[3 * vertex + 2] !=
           originalVoronoiVertices[3 * vertex + 2])
      ++movedRetainedBoundaryVertices;
  }

  if(storeDiagnostics) {
    // Store the actual post-pass RMS distance for every retained MAT node for
    // which a triangulated local mean surface exists. Triple-line nodes remain
    // visible in the diagnostic POS instead of receiving zero.
    const auto toArray = [](const Eigen::Vector3d &value) {
      return std::array<double, 3>{value.x(), value.y(), value.z()};
    };
    for(const int vertex : retainedVertices) {
      if(vertex < 0 ||
         3 * vertex + 2 >= static_cast<int>(vor.vertices.size()))
        continue;
      const auto pairs = pairsAtVertex.find(vertex);
      if(pairs == pairsAtVertex.end() || pairs->second.empty()) continue;
      const Eigen::Vector3d point(
          vor.vertices[3 * vertex], vor.vertices[3 * vertex + 1],
          vor.vertices[3 * vertex + 2]);
      auto insertion =
          localMidSurfaceProjectionDiagnostics.try_emplace(vertex);
      LocalMidSurfaceProjectionDiagnostic &diagnostic =
          insertion.first->second;
      if(insertion.second) {
        diagnostic.original = toArray(point);
        diagnostic.rawRequested = toArray(point);
        diagnostic.preSplineRequested = toArray(point);
        diagnostic.filteredRequested = toArray(point);
        diagnostic.midSurfaceNormal = {0.0, 0.0, 0.0};
        diagnostic.acceptedFraction = 0.0;
        diagnostic.simpleBoundary =
            simpleBoundaryCandidates.count(vertex) != 0;
        diagnostic.tripleLine = tripleLineVertices.count(vertex) != 0;
        diagnostic.repeatedCadSourcePair = false;
        diagnostic.tripleSplineTarget = false;
      }
      diagnostic.accepted = toArray(point);
      diagnostic.projectionCandidate =
          targetByVertex.count(vertex) != 0;
      diagnostic.surfaceClassifiedOpposites =
          matLocalMidSurfaceProjection::
              allOppositePairsAreSurfaceClassifiedImpl(
                  del.onWhat, pairs->second);
      if(!diagnostic.tripleLine)
        diagnostic.meanSurfaceDistance =
            projectionResidual(point, vertex);
    }
  }

  const auto projectionCompleted = std::chrono::steady_clock::now();
  const auto elapsedSeconds = [](const auto &first, const auto &second) {
    return std::chrono::duration<double>(second - first).count();
  };

  std::cout
      << "MAT local mid-surface and triple-line projection: candidates="
      << candidates.size() << " projected=" << projected
      << " rejected=" << rejected
      << " regularCandidates=" << regularCandidateCount
      << " simpleBoundaryCandidates=" << simpleBoundaryCandidateCount
      << " tripleLineCandidates=" << tripleLineCandidateCount
      << " targetedRetainedBoundaryVertices="
      << targetedRetainedBoundaryVertices
      << " checkedRetainedBoundaryVertices="
      << checkedRetainedBoundaryVertices
      << " movedRetainedBoundaryVertices="
      << movedRetainedBoundaryVertices
      << " projectedRegular=" << projectedRegular
      << " projectedSimpleBoundary=" << projectedSimpleBoundary
      << " projectedTripleLine=" << projectedTripleLine
      << " tripleLineRankFailures=" << tripleLineRankFailures
      << " tripleEdgeLineTargets=" << tripleEdgeLineTargets
      << " tripleEdgeLineFailures=" << tripleEdgeLineFailures
      << " repeatedCadSourcePairVertexCandidates="
      << repeatedCadSourcePairVertexCandidates
      << " repeatedCadSourcePairVertexTargets="
      << repeatedCadSourcePairVertexTargets
      << " repeatedCadSourcePairVertexConflicts="
      << repeatedCadSourcePairVertexConflicts
      << " repeatedCadSourcePairProjectionFailures="
      << repeatedCadSourcePairProjectionFailures
      << " tripleSplineChains=" << tripleSplineFittedChains
      << " tripleSplineClosedChains=" << tripleSplineClosedChains
      << " tripleSplineProjectedVertices="
      << tripleSplineProjectedVertices
      << " fixedTripleLineVertices=" << fixedTripleLineVertices
      << " meanTripleSplineTargetChange="
      << (tripleSplineProjectedVertices > 0 ?
              tripleSplineTargetChangeSum /
                  static_cast<double>(tripleSplineProjectedVertices) :
              0.0)
      << " maximumTripleSplineTargetChange="
      << maximumTripleSplineTargetChange
      << " repeatedCadSourcePairTopologyLimited="
      << repeatedCadSourcePairTopologyLimited
      << " meanRepeatedCadSourcePairAcceptedFraction="
      << (repeatedCadSourcePairVertexTargets > 0 ?
              repeatedCadSourcePairAcceptedFractionSum /
                  static_cast<double>(repeatedCadSourcePairVertexTargets) :
              0.0)
      << " tripleEdgesTwoCurveOneSurface="
      << tripleEdgesTwoCurveOneSurface
      << " tripleEdgesTwoCurveOneSurfaceSameCurve="
      << tripleEdgesTwoCurveOneSurfaceSameCurve
      << " tripleEdgesUnexpectedClassification="
      << tripleEdgesUnexpectedClassification
      << " tripleEdgesWithTwoManifoldCadCurves="
      << tripleEdgesWithTwoManifoldCadCurves
      << " tripleEdgesWhoseCadCurvesShareFace="
      << tripleEdgesWhoseCadCurvesShareFace
      << " tripleEdgesWhoseCadCurvesShareSupportPatch="
      << tripleEdgesWhoseCadCurvesShareSupportPatch
      << " tripleEdgesWithOneSharedSupportPatch="
      << tripleEdgesWithOneSharedSupportPatch
      << " tripleEdgesWithSeveralSharedSupportPatches="
      << tripleEdgesWithSeveralSharedSupportPatches
      << " tripleEdgesWhoseThirdFaceIsSharedSupport="
      << tripleEdgesWhoseThirdFaceIsSharedSupport
      << " tripleEdgesWithExactlyThreeMatDirections="
      << tripleEdgesWithExactlyThreeMatDirections
      << " tripleEdgesWithThreeRecoveredSourcePairs="
      << tripleEdgesWithThreeRecoveredSourcePairs
      << " tripleEdgesWithRepeatedGeometricSourcePair="
      << tripleEdgesWithRepeatedGeometricSourcePair
      << " tripleEdgesWithExactlyOneRepeatedGeometricSourcePair="
      << tripleEdgesWithExactlyOneRepeatedGeometricSourcePair
      << " tripleEdgesWithAllThreeGeometricSourcePairsEqual="
      << tripleEdgesWithAllThreeGeometricSourcePairsEqual
      << " recoveredDirectionVotePurity="
      << (recoveredDirectionTotalVotes > 0 ?
              static_cast<double>(recoveredDirectionWinningVotes) /
                  static_cast<double>(recoveredDirectionTotalVotes) :
              0.0)
      << " meanTripleLineRankRatio="
      << (tripleEdgeLineTargets > 0 ?
              tripleLineRankRatioSum /
                  static_cast<double>(tripleEdgeLineTargets) :
              0.0)
      << " maximumTripleLineRankRatio=" << maximumTripleLineRankRatio
      << " nonSurfaceOppositeCandidates="
      << nonSurfaceOppositeCandidates
      << " stationaryUnconstrainedCandidates="
      << stationaryUnconstrainedCandidates
      << " stationaryRequestedResidualFallbacks="
      << stationaryRequestedResidualFallbacks
      << " stationaryFinalResidualFallbacks="
      << stationaryFinalResidualFallbacks
      << " requiredOneRingSeeds=" << requiredSeeds.size()
      << " fittedOneRingPlanes=" << planeAtSeed.size()
      << " oneRingMissingTriangles=" << oneRingMissingTriangles
      << " oneRingZeroArea=" << oneRingZeroArea
      << " oneRingEigenFailures=" << oneRingEigenFailures
      << " oneRingInvalidPlanes=" << oneRingInvalidPlanes
      << " pointBisectorMidPlaneFallbacks="
      << pointBisectorMidPlaneFallbacks
      << " topologyLimited=" << topologyLimited
      << " topologyRejected=" << topologyRejected
      << " originalConnectivityInvalidVertices="
      << originalConnectivityInvalidVertices.size()
      << " originalAdjacentNormalViolations=" << originalAdjacentNormalViolations
      << " globalTopologyBacktracks=" << globalTopologyBacktracks
      << " topologyAuditBranchVisits=" << topologyAuditBranchVisits
      << " topologyCouplingIterations=" << topologyCouplingIterations
      << " globallyLimitedVertices=" << globallyLimitedVertexCount
      << " acceptedFractionRegularizationPasses="
      << acceptedFractionRegularizationPasses
      << " acceptedFractionRegularizationRelaxations="
      << acceptedFractionRegularizationRelaxations
      << " acceptedFractionRegularizedVertices="
      << acceptedFractionRegularizedVertexCount
      << " minimumPositiveAcceptedFraction="
      << minimumPositiveAcceptedFraction
      << " acceptedFractionBelowHalf=" << acceptedFractionBelowHalf
      << " acceptedFractionBelowQuarter="
      << acceptedFractionBelowQuarter
      << " maximumBacktrackDisplacementGradient="
      << maximumBacktrackDisplacementGradient
      << " adjacentNormalBacktracks=" << adjacentNormalBacktracks
      << " adjacentNormalLimitedVertices="
      << adjacentNormalLimitedVertexCount
      << " remainingAdjacentNormalViolations="
      << remainingAdjacentNormalViolations
      << " fullProjectionConnectivityInvalidVertices="
      << fullProjectionConnectivityInvalidVertices.size()
      << " rmsResidualBefore="
      << (projected > 0 ?
              residualBeforeSum / static_cast<double>(projected) : 0.0)
      << " rmsResidualAfter="
      << (projected > 0 ?
              residualAfterSum / static_cast<double>(projected) : 0.0)
      << " maximumDisplacement=" << maximumDisplacement << '\n';

  const std::array<const char *, 3> projectionClasses = {
      "regular", "boundary", "triple"};
  for(std::size_t group = 0; group < projectionErrors.size(); ++group) {
    ProjectionErrorSummary &errors = projectionErrors[group];
    if(errors.targetGaps.empty()) continue;
    std::sort(errors.targetGaps.begin(), errors.targetGaps.end());
    const double count = static_cast<double>(errors.targetGaps.size());
    std::cout << "MAT projection error: class=" << projectionClasses[group]
              << " vertices=" << errors.targetGaps.size()
              << " targetGapP95="
              << errors.targetGaps[static_cast<std::size_t>(0.95 * (count - 1))]
              << " targetGapMax=" << errors.targetGaps.back()
              << " targetGapAbove1PercentSupport=" << errors.aboveOnePercent
              << " targetGapAbove5PercentSupport=" << errors.aboveFivePercent
              << " meanRequestedResidual=" << errors.requestedResidualSum / count
              << " meanAcceptedResidual=" << errors.acceptedResidualSum / count
              << '\n';
  }

  std::cout
      << "MAT projection timings: connectivity="
      << elapsedSeconds(projectionStart, projectionConnectivityReady)
      << " connectivityBase="
      << elapsedSeconds(projectionStart,
                        projectionBaseConnectivityReady)
      << " connectivityTriple="
      << elapsedSeconds(projectionBaseConnectivityReady,
                        projectionTripleConnectivityReady)
      << " connectivityCandidates="
      << elapsedSeconds(projectionTripleConnectivityReady,
                        projectionConnectivityReady)
      << " localPlanes="
      << elapsedSeconds(projectionConnectivityReady,
                        projectionPlanesReady)
      << " targets="
      << elapsedSeconds(projectionPlanesReady, projectionTargetsReady)
      << " targetsRegular="
      << elapsedSeconds(projectionRegularTargetsStarted,
                        projectionRegularTargetsReady)
      << " targetsAssembly="
      << elapsedSeconds(projectionRegularTargetsReady,
                        projectionTargetAssemblyReady)
      << " targetsSplines="
      << elapsedSeconds(projectionTargetAssemblyReady,
                        projectionTripleSplinesReady)
      << " targetsFreeze="
      << elapsedSeconds(projectionTripleSplinesReady,
                        projectionTargetsReady)
      << " topologyPreparation="
      << elapsedSeconds(projectionTargetsReady,
                        projectionTopologyPrepared)
      << " topologyGuard="
      << elapsedSeconds(projectionTopologyPrepared,
                        projectionTopologyGuarded)
      << " finalize="
      << elapsedSeconds(projectionTopologyGuarded, projectionCompleted)
      << " total="
      << elapsedSeconds(projectionStart, projectionCompleted)
      << " diagnostics=" << (storeDiagnostics ? 1 : 0) << '\n';

  std::cout << "Triple-edge generator dimension patterns:";
  for(const auto &pattern : tripleEdgeGeneratorDimensionPatterns)
    std::cout << " (" << pattern.first[0] << ',' << pattern.first[1]
              << ',' << pattern.first[2] << ")=" << pattern.second;
  std::cout << '\n';

  if(!tripleEdgeCadCurvePairsWithoutSharedSupport.empty()) {
    std::cout << "Triple CAD curve pairs without shared support patch:";
    for(const auto &example :
        tripleEdgeCadCurvePairsWithoutSharedSupport)
      std::cout << " (curves " << example[0] << ',' << example[1]
                << " face " << example[2] << ')';
    std::cout << '\n';
  }

}

