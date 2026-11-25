// Extracted from MatGmsh for the native Gmsh MAT pipeline.
// See SOURCE_PROVENANCE.txt for the extraction boundary.
#include "matGmsh.h"

#include <gmsh.h>

#include <algorithm>
#include <array>
#include <cmath>
#include <deque>
#include <filesystem>
#include <fstream>
#include <functional>
#include <iomanip>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stdexcept>
#include <utility>
#include <vector>

namespace {

using Point = std::array<double, 3>;

Point add(const Point &a, const Point &b)
{
  return {a[0] + b[0], a[1] + b[1], a[2] + b[2]};
}

Point subtract(const Point &a, const Point &b)
{
  return {a[0] - b[0], a[1] - b[1], a[2] - b[2]};
}

Point scale(const Point &a, double factor)
{
  return {factor * a[0], factor * a[1], factor * a[2]};
}

double dot(const Point &a, const Point &b)
{
  return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

Point cross(const Point &a, const Point &b)
{
  return {a[1] * b[2] - a[2] * b[1],
          a[2] * b[0] - a[0] * b[2],
          a[0] * b[1] - a[1] * b[0]};
}

double norm(const Point &a)
{
  return std::sqrt(dot(a, a));
}

double separationAngleDegrees(const Point &position, const Point &seedA,
                              const Point &seedB)
{
  const Point first = subtract(seedA, position);
  const Point second = subtract(seedB, position);
  const double firstNorm = norm(first);
  const double secondNorm = norm(second);
  if(firstNorm <= 1.e-30 || secondNorm <= 1.e-30) return 0.0;
  const double cosine = std::clamp(
      dot(first, second) / (firstNorm * secondNorm), -1.0, 1.0);
  return std::acos(cosine) * 180.0 / M_PI;
}

double quantile(std::vector<double> values, double probability)
{
  if(values.empty()) return 0.0;
  std::sort(values.begin(), values.end());
  const double position = std::clamp(probability, 0.0, 1.0) *
                          static_cast<double>(values.size() - 1);
  const std::size_t lower = static_cast<std::size_t>(std::floor(position));
  const std::size_t upper = static_cast<std::size_t>(std::ceil(position));
  const double fraction = position - static_cast<double>(lower);
  return (1.0 - fraction) * values[lower] + fraction * values[upper];
}

} // namespace

std::size_t matGmsh::filterMixedBranchWings(
    const std::string &diagnosticFilename,
    const std::vector<int> &unfilteredFaceColors,
    const std::map<int, std::set<int>> &patchesByCadFaceTag,
    std::ostream *report,
    std::vector<int> *zoneByFace,
    std::set<int> *hybridBranches,
    std::vector<MixedBranchZoneSummary> *zoneSummaries)
{
  return processMixedBranchSegmentation(
      diagnosticFilename, unfilteredFaceColors, patchesByCadFaceTag, true,
      0.0, "", false, report, zoneByFace, hybridBranches, "",
      zoneSummaries);
}

std::size_t matGmsh::processMixedBranchSegmentation(
    const std::string &filename,
    const std::vector<int> &unfilteredFaceColors,
    const std::map<int, std::set<int>> &patchesByCadFaceTag,
    bool removeDetectedWings,
    double thetaHmaAngleDegrees,
    const std::string &thetaHmaTripleLineDiagnosticFilename,
    bool applyTripleLineCorridors,
    std::ostream *report,
    std::vector<int> *zoneByFace,
    std::set<int> *hybridBranchesOut,
    const std::string &hybridTripleLineDiagnosticFilename,
    std::vector<MixedBranchZoneSummary> *zoneSummaries)
{
  if(!filename.empty() || thetaHmaAngleDegrees != 0.0 ||
     !thetaHmaTripleLineDiagnosticFilename.empty() || applyTripleLineCorridors ||
     !hybridTripleLineDiagnosticFilename.empty())
    throw std::invalid_argument("Native MAT exposes only the production mixed filter; legacy diagnostics/theta-HMA are not migrated");
  const bool thetaHmaMode = false;
  ScopedTimer timer(*this, thetaHmaMode ? "filterMixedBranchWingsThetaHma" :
                     (removeDetectedWings ? "filterMixedBranchWings" :
                                           "writeMixedBranchSegmentationPos"));
  if(unfilteredFaceColors.size() != vor.faces.size() ||
     vor.faceColors.size() != vor.faces.size()) {
    throw std::runtime_error(
        "Cannot segment mixed MAT branches with incompatible face colors");
  }

  using CadPair = std::pair<int, int>;

  auto patchesForCadFace = [&](int cadFace) {
    const auto patches = patchesByCadFaceTag.find(cadFace);
    if(patches != patchesByCadFaceTag.end() && !patches->second.empty())
      return patches->second;
    return std::set<int>{cadFace};
  };
  auto patchPairsForCadPair = [&](const CadPair &cadPair) {
    std::set<CadPair> pairs;
    const std::set<int> firstPatches = patchesForCadFace(cadPair.first);
    const std::set<int> secondPatches = patchesForCadFace(cadPair.second);
    for(int first : firstPatches) {
      for(int second : secondPatches) {
        pairs.insert({std::min(first, second), std::max(first, second)});
      }
    }
    return pairs;
  };

  struct Neighbor {
    std::size_t face = 0;
    double sharedLength = 0.0;
  };

  struct FaceInfo {
    bool selected = false;
    int branch = -1;
    CadPair pair{-1, -1};
    CadPair cadPair{-1, -1};
    CadPair patchPair{-1, -1};
    std::vector<CadPair> cadPairCandidates;
    std::vector<int> vertices;
    Point center{0.0, 0.0, 0.0};
    Point normal{0.0, 0.0, 0.0};
    double area = 0.0;
    double radius = 0.0;
    double medialRadius = 0.0;
    Point gradient{0.0, 0.0, 0.0};
    double gradientMagnitude = 0.0;
    Point medialGradient{0.0, 0.0, 0.0};
    double medialGradientMagnitude = 0.0;
    double supportCompatibility = 0.0;
    double supportParallelism = 0.0;
    double supportIncidence = 0.0;
    double contactAngleDegrees = 0.0;
    std::vector<double> separationAnglesDegrees;
    double minimumSeparationAngleDegrees = 0.0;
    double meanSeparationAngleDegrees = 0.0;
    double p95SeparationAngleDegrees = 0.0;
    double maximumSeparationAngleDegrees = 0.0;
    bool supportCompatibilityEvaluated = false;
    bool supportParentEligible = false;
    bool junctionSupportCandidate = false;
    std::vector<Neighbor> neighbors;
    int zone = -1;
  };

  struct ZoneInfo {
    int id = -1;
    int branch = -1;
    CadPair pair{-1, -1};
    CadPair patchPair{-1, -1};
    std::vector<std::size_t> faces;
    std::set<int> neighbors;
    Point center{0.0, 0.0, 0.0};
    double area = 0.0;
    double meanRadius = 0.0;
    double minimumRadius = std::numeric_limits<double>::max();
    double maximumRadius = 0.0;
    double meanMedialRadius = 0.0;
    double minimumMedialRadius = std::numeric_limits<double>::max();
    double maximumMedialRadius = 0.0;
    double meanGradient = 0.0;
    double meanMedialGradient = 0.0;
    double medialGradientCoherence = 0.0;
    double coherence = 0.0;
    double plateauFraction = 0.0;
    double inheritedBoundaryLength = 0.0;
    double normalizedBoundaryContact = 0.0;
    double meanSupportCompatibility = 0.0;
    double meanSupportParallelism = 0.0;
    double meanSupportIncidence = 0.0;
    double supportCompatibleFraction = 0.0;
    double minimumSeparationAngleDegrees = 0.0;
    double meanSeparationAngleDegrees = 0.0;
    double p95SeparationAngleDegrees = 0.0;
    double maximumSeparationAngleDegrees = 0.0;
    double lowSeparationAngleFraction = 0.0;
    bool supportParentEligible = false;
    bool junctionSupportCandidate = false;
    bool gradientCore = false;
    bool supportCore = false;
    bool anchorCore = false;
    bool networkCore = false;
    bool strongCore = false;
    bool opposedSupportCore = false;
    bool c1PatchCore = false;
    bool junctionCore = false;
    bool wingLike = false;
    bool proposedWing = false;
    bool wasActiveArticulation = false;
    double topologyBridgeScore = 0.0;
    std::size_t fixedSheetInterfaceEdges = 0;
    std::size_t rawBoundaryEdges = 0;
    bool fixedSheetInterfaceProtected = false;
    bool thetaHmaFrontier = false;
    bool thetaHmaFixed = false;
    int thetaHmaRemovalIteration = -1;
    int thetaHmaRimComponents = 0;
    int thetaHmaSeamComponents = 0;
    int thetaHmaSheetEulerCharacteristic = 0;
    int thetaHmaSeamEulerCharacteristic = 0;
    int proposedClass = 1;
  };

  auto point = [&](int vertex) -> Point {
    return {vor.vertices[3 * vertex], vor.vertices[3 * vertex + 1],
            vor.vertices[3 * vertex + 2]};
  };

  auto seedPoint = [&](int seed) -> Point {
    return {del.seeds[3 * seed], del.seeds[3 * seed + 1],
            del.seeds[3 * seed + 2]};
  };

  std::map<std::pair<int, int>, Point> normalBySeedAndFace;
  std::set<std::pair<int, int>> invalidSeedFaceNormals;
  auto normalAtSeedOnFace = [&](int seed, int faceTag, Point &normal) {
    const std::pair<int, int> key{seed, faceTag};
    const auto cached = normalBySeedAndFace.find(key);
    if(cached != normalBySeedAndFace.end()) {
      normal = cached->second;
      return true;
    }
    if(invalidSeedFaceNormals.count(key) != 0 || seed < 0 ||
       3 * seed + 2 >= static_cast<int>(del.seeds.size())) return false;
    try {
      const Point xyz = seedPoint(seed);
      std::vector<double> uv, values;
      gmsh::model::getParametrization(
          2, faceTag, {xyz[0], xyz[1], xyz[2]}, uv);
      gmsh::model::getNormal(faceTag, uv, values);
      if(values.size() < 3) throw std::runtime_error("missing CAD normal");
      normal = {values[0], values[1], values[2]};
      const double length = norm(normal);
      if(length <= 1.e-30) throw std::runtime_error("null CAD normal");
      normal = scale(normal, 1.0 / length);
      normalBySeedAndFace[key] = normal;
      return true;
    }
    catch(...) {
      invalidSeedFaceNormals.insert(key);
      return false;
    }
  };

  auto seedHasFace = [&](int seed, int faceTag) {
    if(seed < 0 || seed >= static_cast<int>(del.seedFaces.size()))
      return false;
    const std::vector<int> &faces = del.seedFaces[seed];
    return std::find(faces.begin(), faces.end(), faceTag) != faces.end();
  };

  auto supportCompatibility = [&](int seedA, int seedB,
                                  const CadPair &pair,
                                  double &compatibility,
                                  double &supportParallelism,
                                  double &supportIncidence,
                                  double &contactAngleDegrees) {
    compatibility = 0.0;
    supportParallelism = 0.0;
    supportIncidence = 0.0;
    contactAngleDegrees = 0.0;
    if(pair.first == pair.second) return false;
    const Point connector = subtract(seedPoint(seedB), seedPoint(seedA));
    const double connectorLength = norm(connector);
    if(connectorLength <= 1.e-30) return false;
    const Point direction = scale(connector, 1.0 / connectorLength);

    bool evaluated = false;
    auto evaluateAssignment = [&](int faceA, int faceB) {
      Point normalA, normalB;
      if(!normalAtSeedOnFace(seedA, faceA, normalA) ||
         !normalAtSeedOnFace(seedB, faceB, normalB)) return;
      const double parallelism = std::fabs(dot(normalA, normalB));
      // CAD/surface normal orientation is not assumed to be consistent here.
      // Map the unoriented normal angle to the convention used for medial
      // contacts: parallel/opposite supporting walls are 180 degrees, while
      // adjacent faces have a smaller angle (90 degrees for orthogonal faces).
      const double clampedParallelism =
          std::max(0.0, std::min(1.0, parallelism));
      contactAngleDegrees = std::max(
          contactAngleDegrees,
          std::acos(-clampedParallelism) * 180.0 / M_PI);
      const double incidence = std::min(std::fabs(dot(normalA, direction)),
                                        std::fabs(dot(normalB, direction)));
      const double candidateCompatibility =
          std::min(parallelism, incidence);
      if(candidateCompatibility >= compatibility) {
        compatibility = candidateCompatibility;
        supportParallelism = parallelism;
        supportIncidence = incidence;
      }
      evaluated = true;
    };
    if(seedHasFace(seedA, pair.first) && seedHasFace(seedB, pair.second))
      evaluateAssignment(pair.first, pair.second);
    if(seedHasFace(seedA, pair.second) && seedHasFace(seedB, pair.first))
      evaluateAssignment(pair.second, pair.first);
    return evaluated;
  };

  auto finiteVertices = [&](std::size_t faceIndex) {
    std::vector<int> vertices;
    for(int vertex : vor.faces[faceIndex].verts)
      if(vertex >= 0) vertices.push_back(vertex);
    return vertices;
  };

  std::map<matGmshEdge, int> unfilteredValence;
  std::map<matGmshEdge, std::vector<std::size_t>> unfilteredFacesByEdge;
  std::map<matGmshEdge, std::vector<std::size_t>> retainedFacesByEdge;
  std::map<int, std::size_t> retainedFaceCountByBranch;
  for(std::size_t faceIndex = 0; faceIndex < vor.faces.size(); ++faceIndex) {
    const std::vector<int> vertices = finiteVertices(faceIndex);
    if(vertices.size() < 3) continue;
    std::set<matGmshEdge> uniqueEdges;
    for(std::size_t local = 0; local < vertices.size(); ++local)
      uniqueEdges.insert(
          matGmshEdge(vertices[local], vertices[(local + 1) % vertices.size()]));
    if(unfilteredFaceColors[faceIndex] >= 0)
      for(const matGmshEdge &edge : uniqueEdges) {
        ++unfilteredValence[edge];
        unfilteredFacesByEdge[edge].push_back(faceIndex);
      }
    if(vor.faceColors[faceIndex] >= 0) {
      ++retainedFaceCountByBranch[vor.faceColors[faceIndex]];
      for(const matGmshEdge &edge : uniqueEdges)
        retainedFacesByEdge[edge].push_back(faceIndex);
    }
  }

  std::set<int> suspiciousBranches;
  std::map<int, std::set<matGmshEdge>> inheritedEdgesByBranch;
  for(const auto &entry : retainedFacesByEdge) {
    // Only branches that still contain a boundary edge inherited from the
    // complete MAT are hybrid-wing candidates. The peeling boundary itself is
    // nevertheless recomputed from the current retained MAT below.
    const auto unfiltered = unfilteredValence.find(entry.first);
    if(unfiltered == unfilteredValence.end() || unfiltered->second != 1)
      continue;
    for(std::size_t faceIndex : entry.second) {
      const int branch = vor.faceColors[faceIndex];
      if(branch < 0) continue;
      suspiciousBranches.insert(branch);
      inheritedEdgesByBranch[branch].insert(entry.first);
    }
  }

  // A seed classified on a CAD curve belongs to both incident surfaces. Keep
  // the complete Cartesian product of raw CAD-face possibilities. Exact raw
  // face pairs own the topological zones; the independently mapped C1 pairs
  // are used only by the geometric support and core-protection tests below.
  std::map<std::size_t, std::set<CadPair>> cadCandidatesByFace;
  std::map<std::size_t, std::set<CadPair>> patchCandidatesByFace;
  std::map<int, std::map<CadPair, std::size_t>>
      unambiguousCadCountsByBranch;
  std::map<int, std::map<CadPair, std::size_t>>
      unambiguousPatchCountsByBranch;
  for(std::size_t faceIndex = 0; faceIndex < vor.faces.size(); ++faceIndex) {
    const int branch = unfilteredFaceColors[faceIndex];
    if(branch < 0) continue;
    const VoronoiFace &face = vor.faces[faceIndex];
    const int seedA = face.edge.a;
    const int seedB = face.edge.b;
    if(seedA < 0 || seedB < 0 ||
       seedA >= static_cast<int>(del.seedFaces.size()) ||
       seedB >= static_cast<int>(del.seedFaces.size())) continue;
    std::set<CadPair> &cadCandidates = cadCandidatesByFace[faceIndex];
    std::set<CadPair> &patchCandidates = patchCandidatesByFace[faceIndex];
    for(int cadFaceA : del.seedFaces[seedA]) {
      for(int cadFaceB : del.seedFaces[seedB]) {
        const CadPair cadPair{std::min(cadFaceA, cadFaceB),
                              std::max(cadFaceA, cadFaceB)};
        cadCandidates.insert(cadPair);
        const std::set<CadPair> possiblePairs =
            patchPairsForCadPair(cadPair);
        patchCandidates.insert(possiblePairs.begin(), possiblePairs.end());
      }
    }
    if(cadCandidates.size() == 1)
      ++unambiguousCadCountsByBranch[branch][*cadCandidates.begin()];
    if(patchCandidates.size() == 1)
      ++unambiguousPatchCountsByBranch[branch][*patchCandidates.begin()];
  }

  auto mostFrequentCandidate = [](
      const std::set<CadPair> &candidates,
      const std::map<int, std::map<CadPair, std::size_t>> &countsByBranch,
      int branch) {
    CadPair best = *candidates.begin();
    std::size_t bestCount = 0;
    const auto branchCounts = countsByBranch.find(branch);
    for(const CadPair &candidate : candidates) {
      std::size_t count = 0;
      if(branchCounts != countsByBranch.end()) {
        const auto candidateCount = branchCounts->second.find(candidate);
        if(candidateCount != branchCounts->second.end())
          count = candidateCount->second;
      }
      if(count > bestCount) {
        best = candidate;
        bestCount = count;
      }
    }
    return best;
  };

  // Zone ownership follows the exact pair of raw CAD faces so distinct contact
  // regions remain separate. Mapping to smooth/overlapping C1 support patches
  // is deliberately separate: those patches may propagate a core protection,
  // but must not merge distinct raw-face zones before their geometric
  // statistics and topology have been classified.
  std::map<std::size_t, CadPair> selectedCadPairByFace;
  std::map<std::size_t, CadPair> selectedPairByFace;
  std::set<CadPair> selectedPairs;
  std::size_t unresolvedFaces = 0;
  for(std::size_t faceIndex = 0; faceIndex < vor.faces.size(); ++faceIndex) {
    const int branch = unfilteredFaceColors[faceIndex];
    if(branch < 0) continue;
    const auto cadCandidates = cadCandidatesByFace.find(faceIndex);
    if(cadCandidates == cadCandidatesByFace.end() ||
       cadCandidates->second.empty()) {
      if(suspiciousBranches.count(branch) != 0) ++unresolvedFaces;
      continue;
    }
    const CadPair cadPair = mostFrequentCandidate(
        cadCandidates->second, unambiguousCadCountsByBranch, branch);
    selectedCadPairByFace[faceIndex] = cadPair;
    selectedPairs.insert(cadPair);

    const std::set<CadPair> patchPairs = patchPairsForCadPair(cadPair);
    if(!patchPairs.empty())
      selectedPairByFace[faceIndex] = mostFrequentCandidate(
          patchPairs, unambiguousPatchCountsByBranch, branch);
  }

  std::map<CadPair, int> pairTag;
  int nextPairTag = 1;
  for(const CadPair &pair : selectedPairs) pairTag[pair] = nextPairTag++;

  std::vector<FaceInfo> faceInfo(vor.faces.size());
  for(const auto &entry : selectedCadPairByFace) {
    const std::size_t faceIndex = entry.first;
    FaceInfo &info = faceInfo[faceIndex];
    info.branch = unfilteredFaceColors[faceIndex];
    info.selected = vor.faceColors[faceIndex] >= 0 &&
                    suspiciousBranches.count(info.branch) != 0;
    // Raw CAD pairs own zones. C1 patch pairs are metadata used only by the
    // protection propagation below.
    info.pair = entry.second;
    info.cadPair = entry.second;
    const auto patchPair = selectedPairByFace.find(faceIndex);
    info.patchPair = patchPair == selectedPairByFace.end() ? entry.second :
                                                             patchPair->second;
    const auto cadCandidates = cadCandidatesByFace.find(faceIndex);
    if(cadCandidates != cadCandidatesByFace.end()) {
      info.cadPairCandidates.assign(cadCandidates->second.begin(),
                                    cadCandidates->second.end());
    }
    info.vertices = finiteVertices(faceIndex);
    if(info.vertices.size() < 3) {
      info.selected = false;
      continue;
    }
    // Patch-pair ownership is also resolved for faces outside the mixed-zone
    // analysis. The initial MAT triple-line diagnostic below needs all three
    // incident sheets, including an accepted neighbor of a hybrid branch.
    if(!info.selected) continue;

    Point arithmeticCenter{0.0, 0.0, 0.0};
    for(int vertex : info.vertices)
      arithmeticCenter = add(arithmeticCenter, point(vertex));
    arithmeticCenter = scale(arithmeticCenter, 1.0 / info.vertices.size());

    Point weightedCenter{0.0, 0.0, 0.0};
    Point polygonNormal{0.0, 0.0, 0.0};
    for(std::size_t local = 0; local < info.vertices.size(); ++local) {
      const Point a = point(info.vertices[local]);
      const Point b = point(info.vertices[(local + 1) % info.vertices.size()]);
      const Point areaVector =
          cross(subtract(a, arithmeticCenter),
                subtract(b, arithmeticCenter));
      const double triangleArea = 0.5 * norm(areaVector);
      const Point triangleCenter =
          scale(add(add(arithmeticCenter, a), b), 1.0 / 3.0);
      weightedCenter = add(weightedCenter,
                           scale(triangleCenter, triangleArea));
      polygonNormal = add(polygonNormal, areaVector);
      info.area += triangleArea;
    }
    info.center = info.area > 0.0 ?
        scale(weightedCenter, 1.0 / info.area) : arithmeticCenter;
    const double polygonNormalLength = norm(polygonNormal);
    if(polygonNormalLength > 0.0)
      info.normal = scale(polygonNormal, 1.0 / polygonNormalLength);

    const int seedA = vor.faces[faceIndex].edge.a;
    const int seedB = vor.faces[faceIndex].edge.b;
    if(seedA >= 0 && seedB >= 0 &&
       3 * seedA + 2 < static_cast<int>(del.seeds.size()) &&
       3 * seedB + 2 < static_cast<int>(del.seeds.size())) {
      const Point seedConnector = subtract(seedPoint(seedB), seedPoint(seedA));
      const double seedDistance = norm(seedConnector);
      info.radius = 0.5 * seedDistance;
      info.medialRadius =
          0.5 * (norm(subtract(info.center, seedPoint(seedA))) +
                 norm(subtract(info.center, seedPoint(seedB))));
      const Point firstSeed = seedPoint(seedA);
      const Point secondSeed = seedPoint(seedB);
      info.separationAnglesDegrees.push_back(
          separationAngleDegrees(info.center, firstSeed, secondSeed));
      for(int vertex : info.vertices)
        info.separationAnglesDegrees.push_back(
            separationAngleDegrees(point(vertex), firstSeed, secondSeed));
      if(!info.separationAnglesDegrees.empty()) {
        const auto extrema = std::minmax_element(
            info.separationAnglesDegrees.begin(),
            info.separationAnglesDegrees.end());
        info.minimumSeparationAngleDegrees = *extrema.first;
        info.maximumSeparationAngleDegrees = *extrema.second;
        for(double angle : info.separationAnglesDegrees)
          info.meanSeparationAngleDegrees += angle;
        info.meanSeparationAngleDegrees /=
            static_cast<double>(info.separationAnglesDegrees.size());
        info.p95SeparationAngleDegrees =
            quantile(info.separationAnglesDegrees, 0.95);
      }
      // A finite Voronoi face is orthogonal to its generating Delaunay edge.
      // This normal is considerably more robust than one reconstructed from a
      // very small or needle-shaped polygon.
      if(seedDistance > 0.0)
        info.normal = scale(seedConnector, 1.0 / seedDistance);
      // Logical OR for CAD-line seeds: evaluate every adjacent-face
      // possibility and retain the strongest valid assignment. A single bad
      // side of the line must not reject the other, geometrically valid side.
      for(const CadPair &candidate : info.cadPairCandidates) {
        double compatibility = 0.0;
        double parallelism = 0.0;
        double incidence = 0.0;
        double contactAngleDegrees = 0.0;
        const bool evaluated = supportCompatibility(
            seedA, seedB, candidate, compatibility, parallelism, incidence,
            contactAngleDegrees);
        if(!evaluated) continue;
        if(!info.supportCompatibilityEvaluated ||
           compatibility > info.supportCompatibility) {
          info.supportCompatibility = compatibility;
          info.supportParallelism = parallelism;
          info.supportIncidence = incidence;
          info.contactAngleDegrees = contactAngleDegrees;
          info.cadPair = candidate;
        }
        info.supportCompatibilityEvaluated = true;
      }
    }
  }

  for(const auto &entry : retainedFacesByEdge) {
    if(entry.second.size() != 2) continue;
    const std::size_t faceA = entry.second[0];
    const std::size_t faceB = entry.second[1];
    if(!faceInfo[faceA].selected || !faceInfo[faceB].selected ||
       faceInfo[faceA].branch != faceInfo[faceB].branch) continue;
    const double sharedLength =
        norm(subtract(point(entry.first.a), point(entry.first.b)));
    if(sharedLength <= 0.0) continue;
    faceInfo[faceA].neighbors.push_back({faceB, sharedLength});
    faceInfo[faceB].neighbors.push_back({faceA, sharedLength});
  }

  // Recover grad(r) from an area-weighted local linear polynomial instead of
  // averaging one-edge directional slopes. The latter is not polynomial
  // preserving and becomes extremely noisy on cap or needle-shaped faces.
  // The adaptive BFS remains inside the same topological branch because the
  // neighbor graph above only crosses regular (valence-two) branch edges.
  // Since r and x have the same dimension, the recovered |grad(r)| remains
  // dimensionless and comparable across scales and mesh resolutions.
  struct GradientFit {
    Point gradient{0.0, 0.0, 0.0};
    double angularCondition = 0.0;
    bool valid = false;
  };

  std::vector<int> neighborhoodStamp(faceInfo.size(), 0);
  int nextNeighborhoodStamp = 0;
  constexpr std::size_t minimumGradientSamples = 12;
  constexpr int maximumGradientRings = 5;
  constexpr double targetAngularCondition = 0.05;

  auto fitGradient = [&](std::size_t centerFace,
                         const std::vector<std::size_t> &samples,
                         bool useMedialRadius) {
    GradientFit fit;
    const FaceInfo &center = faceInfo[centerFace];
    Point normal = center.normal;
    const double normalLength = norm(normal);
    if(normalLength <= 1.e-30 || samples.size() < 3) return fit;
    normal = scale(normal, 1.0 / normalLength);

    // Pick the Cartesian direction least parallel to the normal in order to
    // construct a stable orthonormal tangent frame.
    Point axis{1.0, 0.0, 0.0};
    if(std::fabs(normal[1]) < std::fabs(normal[0]) &&
       std::fabs(normal[1]) <= std::fabs(normal[2]))
      axis = {0.0, 1.0, 0.0};
    else if(std::fabs(normal[2]) < std::fabs(normal[0]) &&
            std::fabs(normal[2]) < std::fabs(normal[1]))
      axis = {0.0, 0.0, 1.0};
    Point tangentU = cross(normal, axis);
    const double tangentULength = norm(tangentU);
    if(tangentULength <= 1.e-30) return fit;
    tangentU = scale(tangentU, 1.0 / tangentULength);
    const Point tangentV = cross(normal, tangentU);

    double supportRadius = 0.0;
    double meanArea = 0.0;
    for(std::size_t face : samples) {
      supportRadius = std::max(
          supportRadius,
          norm(subtract(faceInfo[face].center, center.center)));
      meanArea += faceInfo[face].area;
    }
    meanArea /= static_cast<double>(samples.size());
    if(supportRadius <= 1.e-30 || meanArea <= 0.0) return fit;

    double totalWeight = 0.0;
    double meanU = 0.0, meanV = 0.0, meanRadius = 0.0;
    for(std::size_t face : samples) {
      const FaceInfo &sample = faceInfo[face];
      const Point delta = subtract(sample.center, center.center);
      const double distance = norm(delta);
      const double normalizedDistance = distance / supportRadius;
      // Area weights make the recovery insensitive to a local proliferation
      // of tiny faces; the Gaussian factor keeps the fit local.
      const double areaWeight = std::max(sample.area, 1.e-8 * meanArea);
      const double weight =
          areaWeight * std::exp(-2.0 * normalizedDistance * normalizedDistance);
      const double u = dot(delta, tangentU);
      const double v = dot(delta, tangentV);
      totalWeight += weight;
      meanU += weight * u;
      meanV += weight * v;
      meanRadius += weight *
          (useMedialRadius ? sample.medialRadius : sample.radius);
    }
    if(totalWeight <= 0.0) return fit;
    meanU /= totalWeight;
    meanV /= totalWeight;
    meanRadius /= totalWeight;

    double covarianceUU = 0.0, covarianceUV = 0.0;
    double covarianceVV = 0.0, rightU = 0.0, rightV = 0.0;
    for(std::size_t face : samples) {
      const FaceInfo &sample = faceInfo[face];
      const Point delta = subtract(sample.center, center.center);
      const double distance = norm(delta);
      const double normalizedDistance = distance / supportRadius;
      const double areaWeight = std::max(sample.area, 1.e-8 * meanArea);
      const double weight =
          areaWeight * std::exp(-2.0 * normalizedDistance * normalizedDistance);
      const double u = dot(delta, tangentU) - meanU;
      const double v = dot(delta, tangentV) - meanV;
      const double radius =
          (useMedialRadius ? sample.medialRadius : sample.radius) -
          meanRadius;
      covarianceUU += weight * u * u;
      covarianceUV += weight * u * v;
      covarianceVV += weight * v * v;
      rightU += weight * u * radius;
      rightV += weight * v * radius;
    }

    const double trace = covarianceUU + covarianceVV;
    if(trace <= 1.e-30) return fit;
    const double discriminant = std::sqrt(
        std::max(0.0, (covarianceUU - covarianceVV) *
                          (covarianceUU - covarianceVV) +
                          4.0 * covarianceUV * covarianceUV));
    const double largestEigenvalue = 0.5 * (trace + discriminant);
    const double smallestEigenvalue = 0.5 * (trace - discriminant);
    if(largestEigenvalue <= 1.e-30) return fit;
    fit.angularCondition =
        std::max(0.0, smallestEigenvalue) / largestEigenvalue;

    // Only the final, still anisotropic neighborhood is regularized. This
    // bounds the unresolved transverse derivative without perturbing a
    // well-conditioned affine reconstruction.
    const double eigenvalueFloor = 1.e-3 * largestEigenvalue;
    const double regularization =
        std::max(0.0, eigenvalueFloor - smallestEigenvalue);
    covarianceUU += regularization;
    covarianceVV += regularization;
    const double determinant =
        covarianceUU * covarianceVV - covarianceUV * covarianceUV;
    if(determinant <= 1.e-30 * trace * trace) return fit;
    const double gradientU =
        (covarianceVV * rightU - covarianceUV * rightV) / determinant;
    const double gradientV =
        (covarianceUU * rightV - covarianceUV * rightU) / determinant;
    fit.gradient = add(scale(tangentU, gradientU),
                       scale(tangentV, gradientV));
    fit.valid = true;
    return fit;
  };

  for(std::size_t face = 0; face < faceInfo.size(); ++face) {
    FaceInfo &info = faceInfo[face];
    if(!info.selected) continue;
    if(++nextNeighborhoodStamp == std::numeric_limits<int>::max()) {
      std::fill(neighborhoodStamp.begin(), neighborhoodStamp.end(), 0);
      nextNeighborhoodStamp = 1;
    }
    std::vector<std::size_t> samples{face};
    std::vector<std::size_t> frontier{face};
    neighborhoodStamp[face] = nextNeighborhoodStamp;
    GradientFit bestFit;
    for(int ring = 1; ring <= maximumGradientRings && !frontier.empty();
        ++ring) {
      std::vector<std::size_t> nextFrontier;
      for(std::size_t current : frontier) {
        for(const Neighbor &neighbor : faceInfo[current].neighbors) {
          const std::size_t candidate = neighbor.face;
          if(neighborhoodStamp[candidate] == nextNeighborhoodStamp) continue;
          neighborhoodStamp[candidate] = nextNeighborhoodStamp;
          nextFrontier.push_back(candidate);
          samples.push_back(candidate);
        }
      }
      frontier.swap(nextFrontier);
      bestFit = fitGradient(face, samples, false);
      if(bestFit.valid && samples.size() >= minimumGradientSamples &&
         bestFit.angularCondition >= targetAngularCondition)
        break;
    }
    if(bestFit.valid) {
      info.gradient = bestFit.gradient;
      info.gradientMagnitude = norm(bestFit.gradient);
    }
    const GradientFit medialFit = fitGradient(face, samples, true);
    if(medialFit.valid) {
      info.medialGradient = medialFit.gradient;
      info.medialGradientMagnitude = norm(medialFit.gradient);
    }
  }

  // Curved or slightly offset skins need not have perfectly parallel normals
  // at the two discrete Delaunay seeds. A value of 0.45 still rejects
  // perpendicular/edge-bisector supports while accepting the clearly paired
  // curved skins observed in the supervised benchmark set.
  constexpr double compatibleSupportThreshold = 0.45;
  auto supportState = [&](const FaceInfo &info) {
    return info.supportCompatibilityEvaluated &&
           info.supportCompatibility >= compatibleSupportThreshold;
  };

  // First classify each complete connected raw-CAD-face-pair zone. Local
  // compatible islands are allowed to become cores only when their parent zone is
  // compatible as a whole. This prevents mesh-dependent compatible speckles
  // inside a wing from blocking its removal.
  std::vector<int> supportParent(faceInfo.size(), -1);
  int nextSupportParent = 0;
  for(std::size_t seed = 0; seed < faceInfo.size(); ++seed) {
    if(!faceInfo[seed].selected || supportParent[seed] >= 0) continue;
    const int parent = nextSupportParent++;
    std::vector<std::size_t> component;
    std::deque<std::size_t> queue;
    queue.push_back(seed);
    supportParent[seed] = parent;
    double weightedCompatibility = 0.0;
    double evaluatedArea = 0.0;
    double compatibleArea = 0.0;
    while(!queue.empty()) {
      const std::size_t face = queue.front();
      queue.pop_front();
      component.push_back(face);
      const FaceInfo &info = faceInfo[face];
      const double weight = info.area > 0.0 ? info.area : 1.0;
      if(info.supportCompatibilityEvaluated) {
        evaluatedArea += weight;
        weightedCompatibility += weight * info.supportCompatibility;
        if(supportState(info)) compatibleArea += weight;
      }
      for(const Neighbor &neighbor : info.neighbors) {
        const FaceInfo &other = faceInfo[neighbor.face];
        if(supportParent[neighbor.face] >= 0 ||
           other.branch != info.branch || other.pair != info.pair) continue;
        supportParent[neighbor.face] = parent;
        queue.push_back(neighbor.face);
      }
    }
    const double meanCompatibility = evaluatedArea > 0.0 ?
        weightedCompatibility / evaluatedArea : 0.0;
    const double compatibleFraction = evaluatedArea > 0.0 ?
        compatibleArea / evaluatedArea : 0.0;
    const bool eligible =
        meanCompatibility >= compatibleSupportThreshold ||
        compatibleFraction >= 0.65;
    for(std::size_t face : component)
      faceInfo[face].supportParentEligible = eligible;
  }

  // A tapered midsurface and a wing can both have a coherent, non-zero
  // radius gradient. Detect the locally thick end of each connected raw-pair
  // component with the true medial distance, then require plausible angular
  // support. Parallelism and connector incidence are deliberately kept
  // separate: a wing can have parallel supports while its connector is almost
  // tangent to them.
  std::vector<double> maximumMedialRadiusBySupportParent(
      static_cast<std::size_t>(nextSupportParent), 0.0);
  std::vector<bool> supportParentTouchesUnfilteredBoundary(
      static_cast<std::size_t>(nextSupportParent), false);
  for(std::size_t face = 0; face < faceInfo.size(); ++face) {
    if(!faceInfo[face].selected || supportParent[face] < 0) continue;
    const std::size_t parent =
        static_cast<std::size_t>(supportParent[face]);
    double &maximum = maximumMedialRadiusBySupportParent[parent];
    maximum = std::max(maximum, faceInfo[face].medialRadius);
    const FaceInfo &info = faceInfo[face];
    for(std::size_t local = 0; local < info.vertices.size(); ++local) {
      const matGmshEdge edge(
          info.vertices[local],
          info.vertices[(local + 1) % info.vertices.size()]);
      const auto valence = unfilteredValence.find(edge);
      if(valence != unfilteredValence.end() && valence->second == 1) {
        supportParentTouchesUnfilteredBoundary[parent] = true;
        break;
      }
    }
  }
  constexpr double minimumLocalMedialRidgeRatio = 0.80;
  constexpr double minimumJunctionIncidence = 0.50;
  constexpr double minimumJunctionParallelism = 0.20;
  constexpr double strongParallelismAtJunction = 0.75;
  for(std::size_t face = 0; face < faceInfo.size(); ++face) {
    FaceInfo &info = faceInfo[face];
    if(!info.selected || supportParent[face] < 0 ||
       !info.supportCompatibilityEvaluated)
      continue;
    const double localMaximum = maximumMedialRadiusBySupportParent[
        static_cast<std::size_t>(supportParent[face])];
    const bool interiorSupportComponent =
        !supportParentTouchesUnfilteredBoundary[
            static_cast<std::size_t>(supportParent[face])];
    const bool onLocalMedialRidge =
        localMaximum > 0.0 &&
        info.medialRadius >= minimumLocalMedialRidgeRatio * localMaximum;
    const bool plausibleAngularSupport =
        (info.supportIncidence >= minimumJunctionIncidence &&
         info.supportParallelism >= minimumJunctionParallelism) ||
        info.supportParallelism >= strongParallelismAtJunction;
    info.junctionSupportCandidate =
        interiorSupportComponent && onLocalMedialRidge &&
        plausibleAngularSupport;
  }

  std::vector<ZoneInfo> zones;
  for(std::size_t seed = 0; seed < faceInfo.size(); ++seed) {
    if(!faceInfo[seed].selected || faceInfo[seed].zone >= 0) continue;
    ZoneInfo zone;
    zone.id = static_cast<int>(zones.size()) + 1;
    zone.branch = faceInfo[seed].branch;
    zone.pair = faceInfo[seed].pair;
    zone.patchPair = faceInfo[seed].patchPair;
    zone.supportParentEligible = faceInfo[seed].supportParentEligible;
    zone.junctionSupportCandidate =
        faceInfo[seed].junctionSupportCandidate;
    std::deque<std::size_t> queue;
    queue.push_back(seed);
    faceInfo[seed].zone = zone.id;
    while(!queue.empty()) {
      const std::size_t face = queue.front();
      queue.pop_front();
      zone.faces.push_back(face);
      for(const Neighbor &neighbor : faceInfo[face].neighbors) {
        FaceInfo &other = faceInfo[neighbor.face];
        if(other.zone >= 0 || other.branch != zone.branch ||
           other.pair != zone.pair) continue;
        if(!thetaHmaMode && zone.supportParentEligible &&
           supportState(other) != supportState(faceInfo[face])) continue;
        if(!thetaHmaMode && other.junctionSupportCandidate !=
           zone.junctionSupportCandidate)
          continue;
        other.zone = zone.id;
        queue.push_back(neighbor.face);
      }
    }
    zones.push_back(std::move(zone));
  }

  // The zone graph contains only within-branch edges. A neighboring retained
  // sheet can be fixed OR belong to another branch that is also being peeled;
  // both contacts are absent from the zone graph. Record either interface so
  // the existing raw-boundary and radius-gradient guard protects the local
  // junction. Do not propagate protection to the rest of either branch.
  if(!thetaHmaMode) {
    for(const auto &entry : retainedFacesByEdge) {
      std::set<int> incidentZones;
      for(std::size_t face : entry.second) {
        if(face < faceInfo.size() && vor.faceColors[face] >= 0 &&
           faceInfo[face].selected && faceInfo[face].zone > 0)
          incidentZones.insert(faceInfo[face].zone);
      }
      if(incidentZones.empty()) continue;
      const double length =
          norm(subtract(point(entry.first.a), point(entry.first.b)));
      if(!std::isfinite(length) || length <= 0.0) continue;
      for(int zoneId : incidentZones) {
        auto &zone = zones[static_cast<std::size_t>(zoneId - 1)];
        const bool hasOtherSheet = std::any_of(
            entry.second.begin(), entry.second.end(), [&](std::size_t face) {
              return face < faceInfo.size() && vor.faceColors[face] >= 0 &&
                  (!faceInfo[face].selected || faceInfo[face].branch != zone.branch);
            });
        if(hasOtherSheet) ++zone.fixedSheetInterfaceEdges;
      }
    }
  }

  constexpr double plateauGradient = 0.15;
  // Diagnostic only: no classification decision below depends on this value.
  constexpr double lowSeparationAngleThresholdDegrees = 150.0;
  for(ZoneInfo &zone : zones) {
    Point gradientSum{0.0, 0.0, 0.0};
    Point medialGradientSum{0.0, 0.0, 0.0};
    double gradientNormSum = 0.0;
    double medialGradientNormSum = 0.0;
    double plateauArea = 0.0;
    double evaluatedSupportArea = 0.0;
    double compatibleSupportArea = 0.0;
    double separationAngleWeight = 0.0;
    double lowSeparationAngleWeight = 0.0;
    std::vector<std::pair<double, double>> separationAngleSamples;
    for(std::size_t face : zone.faces) {
      const FaceInfo &info = faceInfo[face];
      const double weight = info.area > 0.0 ? info.area : 1.0;
      zone.area += weight;
      zone.center = add(zone.center, scale(info.center, weight));
      zone.meanRadius += weight * info.radius;
      zone.meanMedialRadius += weight * info.medialRadius;
      zone.meanGradient += weight * info.gradientMagnitude;
      zone.meanMedialGradient += weight * info.medialGradientMagnitude;
      gradientSum = add(gradientSum, scale(info.gradient, weight));
      medialGradientSum =
          add(medialGradientSum, scale(info.medialGradient, weight));
      gradientNormSum += weight * info.gradientMagnitude;
      medialGradientNormSum += weight * info.medialGradientMagnitude;
      zone.minimumRadius = std::min(zone.minimumRadius, info.radius);
      zone.maximumRadius = std::max(zone.maximumRadius, info.radius);
      zone.minimumMedialRadius =
          std::min(zone.minimumMedialRadius, info.medialRadius);
      zone.maximumMedialRadius =
          std::max(zone.maximumMedialRadius, info.medialRadius);
      if(info.gradientMagnitude <= plateauGradient) plateauArea += weight;
      if(info.supportCompatibilityEvaluated) {
        evaluatedSupportArea += weight;
        zone.meanSupportCompatibility +=
            weight * info.supportCompatibility;
        zone.meanSupportParallelism += weight * info.supportParallelism;
        zone.meanSupportIncidence += weight * info.supportIncidence;
        if(info.supportCompatibility >= compatibleSupportThreshold)
          compatibleSupportArea += weight;
      }
      if(!info.separationAnglesDegrees.empty()) {
        const double sampleWeight =
            weight / static_cast<double>(info.separationAnglesDegrees.size());
        if(separationAngleWeight == 0.0) {
          zone.minimumSeparationAngleDegrees =
              info.minimumSeparationAngleDegrees;
          zone.maximumSeparationAngleDegrees =
              info.maximumSeparationAngleDegrees;
        }
        else {
          zone.minimumSeparationAngleDegrees = std::min(
              zone.minimumSeparationAngleDegrees,
              info.minimumSeparationAngleDegrees);
          zone.maximumSeparationAngleDegrees = std::max(
              zone.maximumSeparationAngleDegrees,
              info.maximumSeparationAngleDegrees);
        }
        for(double angle : info.separationAnglesDegrees) {
          separationAngleSamples.push_back({angle, sampleWeight});
          separationAngleWeight += sampleWeight;
          zone.meanSeparationAngleDegrees += sampleWeight * angle;
          if(angle < lowSeparationAngleThresholdDegrees)
            lowSeparationAngleWeight += sampleWeight;
        }
      }

      for(std::size_t local = 0; local < info.vertices.size(); ++local) {
        const matGmshEdge edge(
            info.vertices[local],
            info.vertices[(local + 1) % info.vertices.size()]);
        const auto raw = unfilteredValence.find(edge);
        if(raw != unfilteredValence.end() && raw->second == 1)
          ++zone.rawBoundaryEdges;
        const auto retained = retainedFacesByEdge.find(edge);
        if(retained != retainedFacesByEdge.end() &&
           retained->second.size() == 1)
          zone.inheritedBoundaryLength +=
              norm(subtract(point(edge.a), point(edge.b)));
      }
    }
    if(zone.area > 0.0) {
      zone.center = scale(zone.center, 1.0 / zone.area);
      zone.meanRadius /= zone.area;
      zone.meanMedialRadius /= zone.area;
      zone.meanGradient /= zone.area;
      zone.meanMedialGradient /= zone.area;
      zone.plateauFraction = plateauArea / zone.area;
      zone.normalizedBoundaryContact =
          zone.inheritedBoundaryLength / std::sqrt(zone.area);
    }
    if(separationAngleWeight > 0.0) {
      zone.meanSeparationAngleDegrees /= separationAngleWeight;
      zone.lowSeparationAngleFraction =
          lowSeparationAngleWeight / separationAngleWeight;
      std::sort(separationAngleSamples.begin(), separationAngleSamples.end(),
                [](const auto &first, const auto &second) {
                  return first.first < second.first;
                });
      const double targetWeight = 0.95 * separationAngleWeight;
      double cumulativeWeight = 0.0;
      zone.p95SeparationAngleDegrees =
          separationAngleSamples.back().first;
      for(const auto &sample : separationAngleSamples) {
        cumulativeWeight += sample.second;
        if(cumulativeWeight >= targetWeight) {
          zone.p95SeparationAngleDegrees = sample.first;
          break;
        }
      }
    }
    if(gradientNormSum > 0.0)
      zone.coherence = norm(gradientSum) / gradientNormSum;
    if(medialGradientNormSum > 0.0)
      zone.medialGradientCoherence =
          norm(medialGradientSum) / medialGradientNormSum;
    if(evaluatedSupportArea > 0.0) {
      zone.meanSupportCompatibility /= evaluatedSupportArea;
      zone.meanSupportParallelism /= evaluatedSupportArea;
      zone.meanSupportIncidence /= evaluatedSupportArea;
      zone.supportCompatibleFraction =
          compatibleSupportArea / evaluatedSupportArea;
    }
  }

  for(const FaceInfo &info : faceInfo) {
    if(!info.selected || info.zone <= 0) continue;
    ZoneInfo &zone = zones[info.zone - 1];
    for(const Neighbor &neighbor : info.neighbors) {
      const int otherZone = faceInfo[neighbor.face].zone;
      if(otherZone > 0 && otherZone != info.zone)
        zone.neighbors.insert(otherZone);
    }
  }

  std::map<int, double> areaByBranch;
  for(const ZoneInfo &zone : zones) areaByBranch[zone.branch] += zone.area;

  // A support zone that contains an inherited boundary of the complete MAT is
  // a hard wing seed. Local CAD support compatibility alone cannot stop the
  // propagation: the terminal part of a wing is often perfectly supported by
  // two CAD faces. Instead, build a scale-free topological core from
  // significant radius plateaus and the support-compatible paths joining two
  // such plateaus. Small terminal plateaus are deliberately not anchors; they
  // are a common discretization artefact at the end of a wing.
  constexpr double minimumAnchorAreaFraction = 0.035;
  for(ZoneInfo &zone : zones) {
    zone.gradientCore =
        zone.plateauFraction >= 0.45 || zone.meanGradient <= 0.08 ||
        (zone.meanGradient <= 0.16 && zone.coherence <= 0.55);
    zone.supportCore =
        zone.supportParentEligible &&
        (zone.meanSupportCompatibility >= compatibleSupportThreshold ||
         zone.supportCompatibleFraction >= 0.65);
    const double branchArea = areaByBranch[zone.branch];
    zone.anchorCore =
        zone.inheritedBoundaryLength <= 0.0 && zone.gradientCore &&
        branchArea > 0.0 &&
        zone.area / branchArea >= minimumAnchorAreaFraction;
    constexpr double minimumOpposedSupportParallelism =
        0.6427876096865394; // cos(50 deg), i.e. theta >= 130 deg
    // A small tapered connector can be a genuine midsurface even when its
    // area is negligible relative to the complete part and none of its
    // samples belongs to the nearly constant-radius plateau. Require both
    // supporting normals and their seed connector to agree locally, and a
    // modest thickness gradient. The inherited-boundary gate still excludes
    // terminal pieces of the original MAT.
    const bool locallyPairedSupports =
        zone.meanSupportCompatibility >= minimumOpposedSupportParallelism &&
        zone.meanGradient <= 0.25;
    zone.opposedSupportCore =
        zone.inheritedBoundaryLength <= 0.0 && zone.supportCore &&
        (locallyPairedSupports ||
         (branchArea > 0.0 && zone.area / branchArea >= 0.05 &&
          zone.plateauFraction >= 0.30 &&
          zone.meanSupportParallelism >= minimumOpposedSupportParallelism));
    zone.wingLike =
        zone.meanGradient >= 0.10 && zone.coherence >= 0.60 &&
        zone.plateauFraction <= 0.45;
  }

  auto eligibleForCoreNetwork = [](const ZoneInfo &zone) {
    return zone.inheritedBoundaryLength <= 0.0 &&
           (zone.gradientCore || zone.supportCore);
  };
  for(ZoneInfo &zone : zones)
    if(zone.anchorCore) zone.networkCore = true;

  // Remove the anchors before finding support components. A terminal cycle
  // attached to one anchor otherwise survives ordinary leaf pruning, even
  // though it cannot connect two established midsurface regions.
  std::set<int> visitedNonAnchors;
  for(const ZoneInfo &seed : zones) {
    if(seed.anchorCore || !eligibleForCoreNetwork(seed) ||
       visitedNonAnchors.count(seed.id) != 0) continue;
    std::set<int> component;
    std::set<int> adjacentAnchors;
    std::deque<int> queue;
    queue.push_back(seed.id);
    visitedNonAnchors.insert(seed.id);
    while(!queue.empty()) {
      const int zoneId = queue.front();
      queue.pop_front();
      component.insert(zoneId);
      for(int neighborId : zones[zoneId - 1].neighbors) {
        const ZoneInfo &neighbor = zones[neighborId - 1];
        if(neighbor.branch != seed.branch ||
           !eligibleForCoreNetwork(neighbor)) continue;
        if(neighbor.anchorCore) {
          adjacentAnchors.insert(neighborId);
          continue;
        }
        if(!visitedNonAnchors.insert(neighborId).second) continue;
        queue.push_back(neighborId);
      }
    }

    if(adjacentAnchors.size() < 2) continue;

    // Retain only the union of paths between anchors. Iteratively pruning
    // non-anchor leaves removes terminal compatible tails without opening a
    // hole between two established parts of the midsurface.
    std::map<int, int> degree;
    std::deque<int> leaves;
    for(int zoneId : component) {
      int value = 0;
      for(int neighborId : zones[zoneId - 1].neighbors)
        if(component.count(neighborId) != 0) ++value;
        else if(zones[neighborId - 1].anchorCore) ++value;
      degree[zoneId] = value;
      if(value <= 1) leaves.push_back(zoneId);
    }
    std::set<int> active = component;
    while(!leaves.empty()) {
      const int zoneId = leaves.front();
      leaves.pop_front();
      if(active.erase(zoneId) == 0) continue;
      for(int neighborId : zones[zoneId - 1].neighbors) {
        if(active.count(neighborId) == 0) continue;
        --degree[neighborId];
        if(degree[neighborId] <= 1)
          leaves.push_back(neighborId);
      }
    }
    for(int zoneId : active) zones[zoneId - 1].networkCore = true;
  }

  // A coherent gradient alone cannot distinguish a terminal wing from a
  // valid, smoothly tapered midsurface. Keep the complete core-network
  // protection here; gradient-flow termination at a low-radius MAT boundary
  // will be handled as a separate discriminant.
  for(ZoneInfo &zone : zones)
    zone.strongCore = zone.inheritedBoundaryLength <= 0.0 &&
                      zone.networkCore;

  // Raw CAD faces may be split by artificial C1 seams. If one raw-face zone
  // establishes a core for a pair of smooth CAD patches, extend that evidence
  // to the other raw-face zones of the same branch and patch pair. Keep the
  // zones separate: merging them before classification mixes their gradient
  // statistics and was observed to over-peel complete sheets.
  std::set<int> visitedC1Zones;
  std::set<std::pair<int, CadPair>> establishedC1PatchPairs;
  for(const ZoneInfo &zone : zones)
    if(zone.strongCore)
      establishedC1PatchPairs.insert({zone.branch, zone.patchPair});
  for(const ZoneInfo &seed : zones) {
    if(visitedC1Zones.count(seed.id) != 0) continue;
    std::vector<int> component;
    std::deque<int> queue;
    bool containsStrongCore = false;
    queue.push_back(seed.id);
    visitedC1Zones.insert(seed.id);
    while(!queue.empty()) {
      const int zoneId = queue.front();
      queue.pop_front();
      const ZoneInfo &zone = zones[zoneId - 1];
      component.push_back(zoneId);
      containsStrongCore = containsStrongCore || zone.strongCore;
      for(int neighborId : zone.neighbors) {
        const ZoneInfo &neighbor = zones[neighborId - 1];
        if(neighbor.branch != seed.branch ||
           neighbor.patchPair != seed.patchPair ||
           !visitedC1Zones.insert(neighborId).second)
          continue;
        queue.push_back(neighborId);
      }
    }
    if(containsStrongCore)
      for(int zoneId : component) zones[zoneId - 1].c1PatchCore = true;
  }
  // A CAD seam can leave a few isolated Voronoi faces with no zone-graph
  // adjacency to the main C1 component. Restore only such micro-fragments;
  // extending this global consensus to larger disconnected zones retained
  // complete wings at coarser mesh resolutions.
  constexpr std::size_t maximumC1SeamFragmentFaces = 3;
  for(ZoneInfo &zone : zones)
    if(!zone.c1PatchCore &&
       zone.faces.size() <= maximumC1SeamFragmentFaces &&
       establishedC1PatchPairs.count({zone.branch, zone.patchPair}) != 0)
      zone.c1PatchCore = true;

  // Promote only ridge pieces attached to an already established midsurface
  // core. Iteration lets the protection cross several tiny Voronoi zones,
  // whereas an isolated high-radius tip of a wing cannot seed a core by
  // itself.
  bool addedJunctionCore = true;
  while(addedJunctionCore) {
    addedJunctionCore = false;
    for(ZoneInfo &zone : zones) {
      if(zone.junctionCore || !zone.junctionSupportCandidate ||
         zone.inheritedBoundaryLength > 0.0 || zone.faces.size() <= 1)
        continue;
      if(zone.meanSupportParallelism < 0.6427876096865394)
        continue;
      const bool attachedToCore = std::any_of(
          zone.neighbors.begin(), zone.neighbors.end(), [&](int neighborId) {
            const ZoneInfo &neighbor = zones[neighborId - 1];
            return neighbor.branch == zone.branch &&
                   (neighbor.strongCore || neighbor.c1PatchCore ||
                    neighbor.junctionCore);
          });
      if(!attachedToCore) continue;
      zone.junctionCore = true;
      addedJunctionCore = true;
    }
  }

  // Peel weak hybrid zones one at a time from the boundary of the current
  // MAT. After removing a complete zone, update every affected edge valence
  // before considering the next zone. This is deliberately not a graph flood:
  // an interior zone can only become removable after it is physically exposed
  // on the newly computed MAT boundary.
  std::map<matGmshEdge, int> currentValence;
  for(const auto &entry : retainedFacesByEdge)
    currentValence[entry.first] = static_cast<int>(entry.second.size());

  auto zoneTouchesCurrentBoundary = [&](const ZoneInfo &zone) {
    for(std::size_t face : zone.faces) {
      const FaceInfo &info = faceInfo[face];
      for(std::size_t local = 0; local < info.vertices.size(); ++local) {
        const matGmshEdge edge(
            info.vertices[local],
            info.vertices[(local + 1) % info.vertices.size()]);
        const auto valence = currentValence.find(edge);
        if(valence != currentValence.end() && valence->second == 1)
          return true;
      }
    }
    return false;
  };

  auto removeZoneFromCurrentMat = [&](ZoneInfo &zone) {
    zone.proposedWing = true;
    for(std::size_t face : zone.faces) {
      const FaceInfo &info = faceInfo[face];
      for(std::size_t local = 0; local < info.vertices.size(); ++local) {
        const matGmshEdge edge(
            info.vertices[local],
            info.vertices[(local + 1) % info.vertices.size()]);
        auto valence = currentValence.find(edge);
        if(valence != currentValence.end() && valence->second > 0)
          --valence->second;
      }
    }
  };

  auto disconnectsActiveBranch = [&](const ZoneInfo &candidate) {
    std::set<int> activeNeighbors;
    for(int neighborId : candidate.neighbors) {
      const ZoneInfo &neighbor = zones[neighborId - 1];
      if(neighbor.branch == candidate.branch && !neighbor.proposedWing)
        activeNeighbors.insert(neighborId);
    }
    if(activeNeighbors.size() <= 1) return false;
    std::set<int> visited;
    std::deque<int> queue;
    queue.push_back(*activeNeighbors.begin());
    visited.insert(*activeNeighbors.begin());
    std::size_t remainingNeighbors = activeNeighbors.size() - 1;
    while(!queue.empty()) {
      const int zoneId = queue.front();
      queue.pop_front();
      for(int neighborId : zones[zoneId - 1].neighbors) {
        const ZoneInfo &neighbor = zones[neighborId - 1];
        if(neighborId == candidate.id ||
           neighbor.branch != candidate.branch || neighbor.proposedWing ||
           !visited.insert(neighborId).second)
          continue;
        // Connectivity of the candidate's neighbors is the only question.
        // Once all have been reached, exploring the rest of this branch
        // cannot change the answer.
        if(activeNeighbors.count(neighborId) && --remainingNeighbors == 0)
          return false;
        queue.push_back(neighborId);
      }
    }
    return std::any_of(activeNeighbors.begin(), activeNeighbors.end(),
                       [&](int neighborId) {
                         return visited.count(neighborId) == 0;
                       });
  };

  std::size_t peelingIterations = 0;
  std::size_t topologyProtectedZones = 0;
  constexpr double minimumStructuralBridgeAreaFraction = 0.20;
  constexpr double maximumStructuralBridgeMeanGradient = 0.25;
  constexpr double minimumStructuralBridgePlateauFraction = 0.30;
  // These protection flags and wingLike do not change during peeling. Keep
  // candidates in the original zone order, dropping each removed zone from
  // the scan instead of repeatedly traversing an ever-growing dead prefix.
  // Dynamic boundary and articulation checks are still repeated as before.
  std::list<ZoneInfo *> peelCandidates;
  for(ZoneInfo &zone : zones)
    if(!zone.proposedWing && !zone.strongCore && !zone.opposedSupportCore &&
       !zone.c1PatchCore && !zone.junctionCore && zone.wingLike)
      peelCandidates.push_back(&zone);
  while(true) {
    auto nextZone = peelCandidates.end();
    for(auto candidate = peelCandidates.begin();
        candidate != peelCandidates.end(); ++candidate) {
      ZoneInfo &zone = **candidate;
      if(!zoneTouchesCurrentBoundary(zone)) continue;
      // An interior subdivision of a terminal wing can have no raw free
      // edge of its own. Contact with a fixed sheet must not override a
      // steep radius gradient: only moderately tapered junctions qualify.
      if(zone.fixedSheetInterfaceEdges > 0 && zone.rawBoundaryEdges == 0 &&
         zone.meanGradient <= 2.0 * plateauGradient) {
        zone.fixedSheetInterfaceProtected = true;
        continue;
      }
      const bool activeArticulation = disconnectsActiveBranch(zone);
      zone.wasActiveArticulation =
          zone.wasActiveArticulation || activeArticulation;
      const double branchArea = areaByBranch[zone.branch];
      const double areaFraction =
          branchArea > 0.0 ? zone.area / branchArea : 0.0;
      const bool broadPlateauBridge =
          areaFraction >= minimumStructuralBridgeAreaFraction &&
          zone.meanGradient <= maximumStructuralBridgeMeanGradient &&
          zone.plateauFraction >= minimumStructuralBridgePlateauFraction;
      if(activeArticulation && broadPlateauBridge) continue;
      nextZone = candidate;
      break;
    }
    if(nextZone == peelCandidates.end()) break;
    removeZoneFromCurrentMat(**nextZone);
    peelCandidates.erase(nextZone);
    ++peelingIterations;
  }

  for(ZoneInfo &zone : zones)
    if(!zone.proposedWing && zone.wingLike &&
       disconnectsActiveBranch(zone)) {
      const double branchArea = areaByBranch[zone.branch];
      zone.topologyBridgeScore =
          branchArea > 0.0 ? zone.area / branchArea : 0.0;
      ++topologyProtectedZones;
    }
  const std::size_t restoredInteriorZones = 0;



  std::map<std::size_t, int> safeTripleLineCutComponentByFace;
  std::map<std::size_t, int> postCutPeeledComponentByFace;
  std::size_t safeTripleLineCorridors = 0;
  std::size_t postCutSheetCount = 0;
  std::size_t postCutPeeledSheets = 0;
  std::size_t postCutProtectedSheets = 0;


  for(ZoneInfo &zone : zones)
    zone.proposedClass = zone.proposedWing ? 2 : 1;

  // Mixed-zone decisions are evidence about an original topological branch,
  // not permission to cut that branch. A branch is hybrid exactly when the
  // zone classifier finds both accepted and wing-like regions in it. The
  // accepted+hybrid flow keeps every original face of such a branch.
  std::map<int, int> zoneClassMaskByBranch;
  for(const ZoneInfo &zone : zones)
    zoneClassMaskByBranch[zone.branch] |=
        zone.proposedClass == 1 ? 1 : 2;
  std::set<int> hybridBranches;
  for(const auto &entry : zoneClassMaskByBranch)
    if(entry.second == 3) hybridBranches.insert(entry.first);
  if(hybridBranchesOut) *hybridBranchesOut = hybridBranches;





  std::map<int, std::size_t> classCounts;
  for(const ZoneInfo &zone : zones) ++classCounts[zone.proposedClass];
  if(zoneSummaries) {
    zoneSummaries->clear();
    zoneSummaries->reserve(zones.size());
    for(const ZoneInfo &zone : zones) {
      MixedBranchZoneSummary summary;
      summary.id = zone.id;
      summary.rawBranch = zone.branch;
      summary.firstPatch = zone.patchPair.first;
      summary.secondPatch = zone.patchPair.second;
      summary.classification = zone.proposedClass;
      summary.faceCount = zone.faces.size();
      summary.area = zone.area;
      zoneSummaries->push_back(summary);
    }
  }
  if(zoneByFace) {
    zoneByFace->assign(vor.faces.size(), -1);
    for(const ZoneInfo &zone : zones)
      for(std::size_t face : zone.faces)
        (*zoneByFace)[face] = zone.id;
  }
  std::size_t removedFaces = 0;
  std::size_t appliedTripleLineCutFaces = 0;
  std::size_t appliedPostCutPeeledFaces = 0;
  if(removeDetectedWings) {
    for(const ZoneInfo &zone : zones) {
      if(zone.proposedClass != 2) continue;
      for(std::size_t face : zone.faces) {
        if(vor.faceColors[face] < 0) continue;
        vor.faceColors[face] = -1;
        ++removedFaces;
      }
    }
    if(applyTripleLineCorridors) {
      for(const auto &entry : safeTripleLineCutComponentByFace) {
        const std::size_t face = entry.first;
        if(face >= vor.faceColors.size() || vor.faceColors[face] < 0)
          continue;
        vor.faceColors[face] = -1;
        ++removedFaces;
        ++appliedTripleLineCutFaces;
      }
      for(const auto &entry : postCutPeeledComponentByFace) {
        const std::size_t face = entry.first;
        if(face >= vor.faceColors.size() || vor.faceColors[face] < 0)
          continue;
        vor.faceColors[face] = -1;
        ++removedFaces;
        ++appliedPostCutPeeledFaces;
      }
    }
  }
  if(report) {
    const std::size_t fixedSheetInterfaceProtectedZones = std::count_if(
        zones.begin(), zones.end(), [](const ZoneInfo &zone) {
          return zone.fixedSheetInterfaceProtected;
        });
    *report << (thetaHmaMode ? "theta-HMA mixed-sheet post-filter: " :
               (removeDetectedWings ? "Mixed-branch wing post-filter: " :
                                      "Mixed-branch segmentation diagnostic: "))
            << "suspiciousBranches="
            << suspiciousBranches.size() << " zones=" << zones.size()
            << " acceptedZones=" << classCounts[1]
            << " wingZones=" << classCounts[2]
            << " restoredInteriorZones=" << restoredInteriorZones
            << " peelingIterations=" << peelingIterations
            << " topologyProtectedZones=" << topologyProtectedZones
            << " fixedSheetInterfaceProtectedZones="
            << fixedSheetInterfaceProtectedZones
            << " removedFaces=" << removedFaces
            << " appliedTripleLineCutFaces="
            << appliedTripleLineCutFaces
            << " appliedPostCutPeeledFaces="
            << appliedPostCutPeeledFaces
            << " unresolvedFaces=" << unresolvedFaces
            << " theta="
            << (thetaHmaMode ? thetaHmaAngleDegrees : 0.0)
            << " file=" << (filename.empty() ? "<disabled>" : filename)
            << "\n";
    for(int branch : suspiciousBranches)
      *report << "  suspiciousBranch=" << branch
              << " retainedFaces=" << retainedFaceCountByBranch[branch]
              << " inheritedBoundaryEdges="
              << inheritedEdgesByBranch[branch].size() << "\n";
    for(const ZoneInfo &zone : zones) {
      if(!zone.fixedSheetInterfaceProtected) continue;
      *report << "  fixedSheetInterfaceZone=" << zone.id
              << " branch=" << zone.branch
              << " patchPair=(" << zone.pair.first << ',' << zone.pair.second
              << ") fixedSheetInterfaceEdges=" << zone.fixedSheetInterfaceEdges
              << " rawBoundaryEdges=" << zone.rawBoundaryEdges
              << " faces=" << zone.faces.size()
              << " center=(" << zone.center[0] << ',' << zone.center[1] << ','
              << zone.center[2] << ')'
              << " area=" << zone.area << "\n";
    }
    for(const ZoneInfo &zone : zones) {
      if(zone.topologyBridgeScore <= 0.0) continue;
      *report << "  topologyProtectedZone=" << zone.id
              << " branch=" << zone.branch
              << " patchPair=(" << zone.pair.first << ',' << zone.pair.second
              << ')'
              << " bridgeScore=" << zone.topologyBridgeScore
              << " center=(" << zone.center[0] << ',' << zone.center[1] << ','
              << zone.center[2] << ')'
              << " areaFraction="
              << (areaByBranch[zone.branch] > 0.0 ?
                    zone.area / areaByBranch[zone.branch] : 0.0)
              << " meanGradient=" << zone.meanGradient
              << " coherence=" << zone.coherence
              << " plateauFraction=" << zone.plateauFraction << "\n";
    }
    for(const ZoneInfo &zone : zones) {
      const double branchArea = areaByBranch[zone.branch];
      const double areaFraction =
          branchArea > 0.0 ? zone.area / branchArea : 0.0;
      if(!zone.wasActiveArticulation) continue;
      *report << "  structuralArticulationCandidate=" << zone.id
              << " branch=" << zone.branch
              << " patchPair=(" << zone.pair.first << ',' << zone.pair.second
              << ')'
              << " faces=" << zone.faces.size()
              << " center=(" << zone.center[0] << ',' << zone.center[1] << ','
              << zone.center[2] << ')'
              << " areaFraction=" << areaFraction
              << " meanGradient=" << zone.meanGradient
              << " coherence=" << zone.coherence
              << " plateauFraction=" << zone.plateauFraction
              << " radiusRatios=("
              << (zone.meanRadius > 0.0 ?
                    zone.minimumRadius / zone.meanRadius : 0.0)
              << ','
              << (zone.meanRadius > 0.0 ?
                    zone.maximumRadius / zone.meanRadius : 0.0)
              << ") boundaryContact=" << zone.normalizedBoundaryContact
              << " supportCompatibility="
              << zone.meanSupportCompatibility
              << " supportFraction=" << zone.supportCompatibleFraction
              << " protected=" << (zone.topologyBridgeScore > 0.0 ? 1 : 0)
              << "\n";
    }
    for(const ZoneInfo &zone : zones) {
      const double branchArea = areaByBranch[zone.branch];
      const double areaFraction =
          branchArea > 0.0 ? zone.area / branchArea : 0.0;
      if(!zone.proposedWing ||
         (areaFraction < 0.02 && zone.plateauFraction < 0.20))
        continue;
      *report << "  significantRemovedZone=" << zone.id
              << " branch=" << zone.branch
              << " patchPair=(" << zone.pair.first << ',' << zone.pair.second
              << ')'
              << " faces=" << zone.faces.size()
              << " center=(" << zone.center[0] << ',' << zone.center[1] << ','
              << zone.center[2] << ')'
              << " areaFraction=" << areaFraction
              << " meanGradient=" << zone.meanGradient
              << " coherence=" << zone.coherence
              << " plateauFraction=" << zone.plateauFraction
              << " radiusRatios=("
              << (zone.meanRadius > 0.0 ?
                    zone.minimumRadius / zone.meanRadius : 0.0)
              << ','
              << (zone.meanRadius > 0.0 ?
                    zone.maximumRadius / zone.meanRadius : 0.0)
              << ") boundaryContact=" << zone.normalizedBoundaryContact
              << " supportCompatibility="
              << zone.meanSupportCompatibility
              << " supportFraction=" << zone.supportCompatibleFraction
              << " spokeAngles=(" << zone.minimumSeparationAngleDegrees
              << ',' << zone.meanSeparationAngleDegrees << ','
              << zone.p95SeparationAngleDegrees << ','
              << zone.maximumSeparationAngleDegrees << ')'
              << " lowSpokeFraction="
              << zone.lowSeparationAngleFraction
              << " articulation=" << (zone.wasActiveArticulation ? 1 : 0)
              << "\n";
    }
  }
  return removeDetectedWings ? removedFaces : suspiciousBranches.size();
}
