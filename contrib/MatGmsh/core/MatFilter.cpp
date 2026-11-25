// Extracted from MatGmsh for the native Gmsh MAT pipeline.
// See SOURCE_PROVENANCE.txt for the extraction boundary.
#include "matGmsh.h"
#include <gmsh.h>
#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stdexcept>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <Eigen/Core>
#include <Eigen/Eigenvalues>
#include <Eigen/Geometry>
#include "matBranchClassifier.h"
#include "matClosureCapTopology.h"
namespace {
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
}
void matGmsh::filterVoronoiBranchesByClassification(
    const std::string &classificationPosFile,
    const std::string &classificationCsvFile,
    std::ostream *report,
    std::map<int, int> *effectiveClasses,
    BranchClassificationPolicy policy,
    std::map<int, int> *wingClosureCapMergeTargets)
{
  ScopedTimer timer(*this, "filterVoronoiBranchesByClassification");
  if(!classificationCsvFile.empty() || !classificationPosFile.empty() || policy.applyManualOverrides)
    throw std::invalid_argument("Native MAT classification uses automatic decisions; CSV/POS legacy exports are not migrated");
  if(wingClosureCapMergeTargets) wingClosureCapMergeTargets->clear();
  struct Accumulator {
    matBranchClassifier::Branch branch;
    std::array<double, 3> minimum{
        std::numeric_limits<double>::infinity(),
        std::numeric_limits<double>::infinity(),
        std::numeric_limits<double>::infinity()};
    std::array<double, 3> maximum{
        -std::numeric_limits<double>::infinity(),
        -std::numeric_limits<double>::infinity(),
        -std::numeric_limits<double>::infinity()};
    std::set<int> vertices;
    std::set<matGmshEdge> edges;
    std::map<std::pair<int, int>, double> cadPairArea;
    double unresolvedCadPairArea = 0.0;
    std::size_t freeBoundaryEdgeCount = 0;
    std::size_t interfaceEdgeCount = 0;
    std::size_t nonManifoldEdgeCount = 0;
    double freeBoundaryLength = 0.0;
    double interfaceLength = 0.0;
    double radiusGradientWeight = 0.0;
    double radiusGradientSum = 0.0;
    double radiusGradientSquaredSum = 0.0;
    double radiusGradientMaximum = 0.0;
  };
  std::map<int, Accumulator> byBranch;
  std::map<matGmshEdge, std::vector<int>> edgeFaces;
  std::vector<double> faceAreas(vor.faces.size(), 0.0);
  std::vector<double> faceRadii(vor.faces.size(), 0.0);
  std::vector<Eigen::Vector3d> faceCenters(
      vor.faces.size(), Eigen::Vector3d::Zero());
  std::vector<Eigen::Vector3d> faceNormals(
      vor.faces.size(), Eigen::Vector3d::Zero());

  for(std::size_t faceIndex = 0; faceIndex < vor.faces.size(); ++faceIndex) {
    if(faceIndex >= vor.faceColors.size() || vor.faceColors[faceIndex] < 0)
      continue;
    const int branchTag = vor.faceColors[faceIndex];
    const auto &face = vor.faces[faceIndex];
    if(face.verts.empty() || face.verts.front() < 0) continue;
    std::vector<int> vertices;
    Eigen::Vector3d center = Eigen::Vector3d::Zero();
    for(int vertex : face.verts) {
      if(vertex < 0) continue;
      vertices.push_back(vertex);
      center += Eigen::Vector3d(vor.vertices[3*vertex],
                                vor.vertices[3*vertex+1],
                                vor.vertices[3*vertex+2]);
    }
    if(vertices.size() < 3) continue;
    center /= static_cast<double>(vertices.size());
    faceCenters[faceIndex] = center;
    double area = 0.0;
    Eigen::Vector3d normal = Eigen::Vector3d::Zero();
    for(std::size_t i = 0; i < vertices.size(); ++i) {
      const int a = vertices[i], b = vertices[(i + 1) % vertices.size()];
      const Eigen::Vector3d pa(vor.vertices[3*a], vor.vertices[3*a+1],
                               vor.vertices[3*a+2]);
      const Eigen::Vector3d pb(vor.vertices[3*b], vor.vertices[3*b+1],
                               vor.vertices[3*b+2]);
      const Eigen::Vector3d cross = (pa - center).cross(pb - center);
      area += 0.5 * cross.norm();
      normal += cross;
      edgeFaces[matGmshEdge(a, b)].push_back(static_cast<int>(faceIndex));
    }
    faceAreas[faceIndex] = area;
    if(normal.norm() > 1.e-30) faceNormals[faceIndex] = normal.normalized();
    const int seedA = face.edge.a, seedB = face.edge.b;
    if(seedA < 0 || seedB < 0 ||
       3*seedA+2 >= static_cast<int>(del.seeds.size()) ||
       3*seedB+2 >= static_cast<int>(del.seeds.size())) continue;
    const Eigen::Vector3d a(del.seeds[3*seedA], del.seeds[3*seedA+1],
                            del.seeds[3*seedA+2]);
    const Eigen::Vector3d b(del.seeds[3*seedB], del.seeds[3*seedB+1],
                            del.seeds[3*seedB+2]);
    const double seedDistance = (a - b).norm();
    const double radius = 0.5 * ((center - a).norm() + (center - b).norm());
    faceRadii[faceIndex] = radius;
    const double ratio = radius > 1.e-30 ?
        std::clamp(seedDistance / (2.0 * radius), 0.0, 1.0) : 0.0;
    const double angle = 2.0 * std::asin(ratio) * 180.0 / M_PI;
    Accumulator &accumulator = byBranch[branchTag];
    accumulator.branch.tag = branchTag;
    accumulator.branch.faces.push_back(
        {area, seedDistance, radius, angle});
    for(int vertex : vertices) {
      accumulator.vertices.insert(vertex);
      for(int coordinate = 0; coordinate < 3; ++coordinate) {
        accumulator.minimum[coordinate] = std::min(
            accumulator.minimum[coordinate], vor.vertices[3*vertex+coordinate]);
        accumulator.maximum[coordinate] = std::max(
            accumulator.maximum[coordinate], vor.vertices[3*vertex+coordinate]);
      }
    }
    for(std::size_t local = 0; local < vertices.size(); ++local)
      accumulator.edges.insert(matGmshEdge(
          vertices[local], vertices[(local + 1) % vertices.size()]));
    if(seedA < static_cast<int>(del.seedFaces.size()) &&
       seedB < static_cast<int>(del.seedFaces.size()) &&
       del.seedFaces[seedA].size() == 1 &&
       del.seedFaces[seedB].size() == 1) {
      const int cadA = del.seedFaces[seedA].front();
      const int cadB = del.seedFaces[seedB].front();
      accumulator.cadPairArea[
          {std::min(cadA, cadB), std::max(cadA, cadB)}] += area;
    }
    else {
      accumulator.unresolvedCadPairArea += area;
    }
  }
  for(const auto &entry : edgeFaces) {
    // Distinct MAT branches meet precisely on non-regular edges, which often
    // have three or more incident faces. Connect every pair of branch tags on
    // the edge instead of considering valence-two edges only.
    std::set<int> edgeBranches;
    for(int face : entry.second) {
      const int branch = vor.faceColors[face];
      if(branch >= 0) edgeBranches.insert(branch);
    }
    double edgeLength = 0.0;
    if(entry.first.a >= 0 && entry.first.b >= 0 &&
       3 * entry.first.a + 2 < static_cast<int>(vor.vertices.size()) &&
       3 * entry.first.b + 2 < static_cast<int>(vor.vertices.size())) {
      const Eigen::Vector3d a(
          vor.vertices[3 * entry.first.a],
          vor.vertices[3 * entry.first.a + 1],
          vor.vertices[3 * entry.first.a + 2]);
      const Eigen::Vector3d b(
          vor.vertices[3 * entry.first.b],
          vor.vertices[3 * entry.first.b + 1],
          vor.vertices[3 * entry.first.b + 2]);
      edgeLength = (a - b).norm();
    }
    for(int branch : edgeBranches) {
      Accumulator &accumulator = byBranch[branch];
      if(entry.second.size() == 1) {
        ++accumulator.freeBoundaryEdgeCount;
        accumulator.freeBoundaryLength += edgeLength;
      }
      else if(edgeBranches.size() > 1) {
        ++accumulator.interfaceEdgeCount;
        accumulator.interfaceLength += edgeLength;
      }
      if(entry.second.size() > 2)
        ++accumulator.nonManifoldEdgeCount;
    }
    if(entry.second.size() == 2) {
      const int firstFace = entry.second[0];
      const int secondFace = entry.second[1];
      const int firstBranch = vor.faceColors[firstFace];
      const int secondBranch = vor.faceColors[secondFace];
      if(firstBranch >= 0 && firstBranch == secondBranch) {
        const double centerDistance =
            (faceCenters[firstFace] - faceCenters[secondFace]).norm();
        if(centerDistance > 1.e-30) {
          const double gradient =
              std::abs(faceRadii[firstFace] - faceRadii[secondFace]) /
              centerDistance;
          const double weight = std::max(edgeLength, 1.e-30);
          Accumulator &accumulator = byBranch[firstBranch];
          accumulator.radiusGradientWeight += weight;
          accumulator.radiusGradientSum += weight * gradient;
          accumulator.radiusGradientSquaredSum +=
              weight * gradient * gradient;
          accumulator.radiusGradientMaximum =
              std::max(accumulator.radiusGradientMaximum, gradient);
        }
      }
    }
    for(auto first = edgeBranches.begin(); first != edgeBranches.end();
        ++first) {
      for(auto second = std::next(first); second != edgeBranches.end();
          ++second) {
        byBranch[*first].branch.neighbors.insert(*second);
        byBranch[*second].branch.neighbors.insert(*first);
      }
    }
  }
  std::vector<matBranchClassifier::Branch> branches;
  for(auto &entry : byBranch) {
    double squaredDiameter = 0.0;
    for(int coordinate = 0; coordinate < 3; ++coordinate) {
      const double extent = entry.second.maximum[coordinate] -
                            entry.second.minimum[coordinate];
      squaredDiameter += extent * extent;
    }
    entry.second.branch.diameter = std::sqrt(squaredDiameter);
    entry.second.branch.freeBoundaryEdgeCount =
        static_cast<int>(entry.second.freeBoundaryEdgeCount);
    branches.push_back(entry.second.branch);
  }
  auto decisions = matBranchClassifier::classify(branches);

  // Preserve optional expert labels from a previously generated CSV. The
  // automatic class remains reported separately, while desired_class drives
  // the actual filtering decision. This makes visual validation reproducible
  // without baking case-specific branch tags into the learned tree.
  std::map<int, matBranchClassifier::Class> desiredClasses;

  std::map<int, matBranchClassifier::Class> automaticClasses;
  for(auto &entry : decisions) {
    automaticClasses[entry.first] = entry.second.classification;
    const auto desired = desiredClasses.find(entry.first);
    if(desired != desiredClasses.end())
      entry.second.classification = desired->second;
  }

  std::size_t restoredInteriorBranches = 0;
  std::size_t restoredInteriorFaces = 0;
  std::set<int> restoredInteriorBranchTags;
  std::set<int> strongMedialSheetBranchTags;
  std::set<int> wingClosureCapBranchTags;

  // Protect locally unambiguous medial sheets before reasoning about the
  // connectivity of rejected components.  A long narrow sheet can have a
  // very small area/diameter^2 ratio (and is rejected by the historical
  // tree), while a large opposed-contact angle, a nearly constant radius and
  // the absence of a free edge are direct evidence that it is not a terminal
  // wing. These deliberately conservative thresholds require nearly opposed
  // supports and low normalized radius variation before restoring an interior
  // sheet.
  constexpr double minimumStrongSheetOpeningAngleDegrees = 145.0;
  constexpr double maximumStrongSheetRadiusGradient = 0.15;
  if(policy.restoreStrongMedialSheets)
  for(auto &decisionEntry : decisions) {
    const int branch = decisionEntry.first;
    if(decisionEntry.second.classification ==
           matBranchClassifier::Class::MidSurface ||
       desiredClasses.count(branch) != 0 ||
       decisionEntry.second.faceCount <= 1)
      continue;
    const auto accumulator = byBranch.find(branch);
    if(accumulator == byBranch.end() ||
       accumulator->second.freeBoundaryEdgeCount != 0)
      continue;
    double area = 0.0;
    double weightedOpeningAngle = 0.0;
    for(const auto &face : accumulator->second.branch.faces) {
      const double weight = std::max(face.area, 1.e-30);
      area += weight;
      weightedOpeningAngle += weight * face.openingAngleDegrees;
    }
    const double meanOpeningAngle =
        area > 0.0 ? weightedOpeningAngle / area : 0.0;
    const double meanRadiusGradient =
        accumulator->second.radiusGradientWeight > 0.0 ?
            accumulator->second.radiusGradientSum /
                accumulator->second.radiusGradientWeight :
            std::numeric_limits<double>::infinity();
    if(meanOpeningAngle < minimumStrongSheetOpeningAngleDegrees ||
       meanRadiusGradient > maximumStrongSheetRadiusGradient)
      continue;
    decisionEntry.second.classification =
        matBranchClassifier::Class::MidSurface;
    ++restoredInteriorBranches;
    restoredInteriorFaces += decisionEntry.second.faceCount;
    restoredInteriorBranchTags.insert(branch);
    strongMedialSheetBranchTags.insert(branch);
  }

  // When a terminal wing is removed, keep the sheets that close it between
  // two retained sheets. These caps have no original free boundary and meet
  // exactly two accepted branches plus one or more rejected wings, which
  // themselves reach the MAT boundary. The cap must be negligible relative
  // to every adjacent wing. The criterion has no case-specific face count or
  // absolute length scale.
  if(policy.restoreWingClosureCaps) {
    std::map<int, std::size_t> freeBoundaryEdgeCounts;
    for(const auto &entry : byBranch)
      freeBoundaryEdgeCounts[entry.first] = entry.second.freeBoundaryEdgeCount;
    const std::set<int> candidates =
        matBranchClassifier::findWingClosureCapBranches(
            branches, decisions, freeBoundaryEdgeCounts);
    for(int branch : candidates) {
      if(desiredClasses.count(branch) != 0) continue;
      auto decision = decisions.find(branch);
      if(decision == decisions.end() ||
         decision->second.classification ==
             matBranchClassifier::Class::MidSurface)
        continue;
      decision->second.classification =
          matBranchClassifier::Class::MidSurface;
      ++restoredInteriorBranches;
      restoredInteriorFaces += decision->second.faceCount;
      restoredInteriorBranchTags.insert(branch);
      wingClosureCapBranchTags.insert(branch);
    }

    // Two one-polygon caps can close each other's boundary. Neither passes
    // the isolated-cap rule above because its rejected neighbour is itself
    // an interior cap, not a terminal wing. Test pairs only, and require the
    // original polygons to form exactly a disk sewn into the retained mesh.
    // In particular, do not restore their whole rejected connected component.
    std::map<int, std::size_t> singlePolygonByBranch;
    for(std::size_t face = 0; face < vor.faces.size(); ++face) {
      if(face >= vor.faceColors.size()) continue;
      const int branch = vor.faceColors[face];
      const auto decision = decisions.find(branch);
      const auto accumulator = byBranch.find(branch);
      if(decision == decisions.end() || accumulator == byBranch.end() ||
         decision->second.classification != matBranchClassifier::Class::Spurious ||
         decision->second.faceCount != 1 || desiredClasses.count(branch) ||
         accumulator->second.freeBoundaryEdgeCount != 0)
        continue;
      singlePolygonByBranch.emplace(branch, face);
    }
    const auto point = [&](int vertex) -> Eigen::Vector3d {
      return {vor.vertices[3*vertex], vor.vertices[3*vertex+1],
              vor.vertices[3*vertex+2]};
    };
    const auto oppositeSides = [&](const matGmshEdge &edge,
                                    std::size_t first, std::size_t second) {
      const Eigen::Vector3d origin = point(edge.a);
      const Eigen::Vector3d direction = point(edge.b) - origin;
      const Eigen::Vector3d a = direction.cross(faceCenters[first] - origin);
      const Eigen::Vector3d b = direction.cross(faceCenters[second] - origin);
      const double scale = a.norm() * b.norm();
      // The same 60-degree continuity limit is used by cap absorption below.
      return a.allFinite() && b.allFinite() && std::isfinite(scale) &&
             scale > 0.0 && a.dot(b) <= -0.5 * scale;
    };
    gmsh::vectorpair cadVolumes;
    bool queriedCadVolumes = false;
    std::size_t restoredCapPairs = 0;
    for(const auto &candidate : singlePolygonByBranch) {
      const int firstBranch = candidate.first;
      for(int secondBranch : byBranch.at(firstBranch).branch.neighbors) {
        const auto secondCandidate = singlePolygonByBranch.find(secondBranch);
        if(secondBranch <= firstBranch || secondCandidate == singlePolygonByBranch.end() ||
           decisions.at(firstBranch).classification == matBranchClassifier::Class::MidSurface ||
           decisions.at(secondBranch).classification == matBranchClassifier::Class::MidSurface)
          continue;
        const std::array<std::size_t, 2> faces{candidate.second,
                                               secondCandidate->second};
        std::map<matGmshEdge, std::vector<std::pair<int, int>>> patchEdges;
        std::map<int, unsigned int> vertexMembership;
        bool valid = true;
        for(int local = 0; local < 2 && valid; ++local) {
          const auto &vertices = vor.faces[faces[local]].verts;
          std::set<int> unique;
          if(vertices.size() < 3 || !(faceAreas[faces[local]] > 0.0) ||
             !faceNormals[faces[local]].allFinite() ||
             faceNormals[faces[local]].squaredNorm() == 0.0) {
            valid = false;
            break;
          }
          for(std::size_t i = 0; i < vertices.size(); ++i) {
            const int a = vertices[i], b = vertices[(i+1) % vertices.size()];
            if(a < 0 || static_cast<std::size_t>(a) >= vor.vertices.size()/3 ||
               !point(a).allFinite() || !unique.insert(a).second) {
              valid = false;
              break;
            }
            vertexMembership[a] |= 1u << local;
            patchEdges[matGmshEdge(a, b)].push_back({local, a < b ? 1 : -1});
          }
        }
        if(!valid || vertexMembership.size() + 2 != patchEdges.size() + 1)
          continue; // Euler characteristic must be one.
        std::map<int, std::vector<int>> boundary;
        std::set<int> sharedEdgeVertices;
        int secondOrientation = 0;
        for(const auto &entry : patchEdges) {
          const auto original = edgeFaces.find(entry.first);
          if(original == edgeFaces.end() || entry.second.size() > 2) {
            valid = false;
            break;
          }
          std::size_t retainedCount = 0, retainedFace = 0;
          for(int face : original->second) {
            const auto decision = decisions.find(vor.faceColors[face]);
            if(decision != decisions.end() &&
               decision->second.classification == matBranchClassifier::Class::MidSurface) {
              ++retainedCount;
              retainedFace = static_cast<std::size_t>(face);
            }
          }
          if(entry.second.size() == 1) {
            if(retainedCount != 1 ||
               !oppositeSides(entry.first, faces[entry.second.front().first],
                              retainedFace)) {
              valid = false;
              break;
            }
            boundary[entry.first.a].push_back(entry.first.b);
            boundary[entry.first.b].push_back(entry.first.a);
          }
          else {
            const int orientation = -entry.second[0].second * entry.second[1].second;
            if(retainedCount != 0 || entry.second[0].first == entry.second[1].first ||
               (secondOrientation && secondOrientation != orientation) ||
               !oppositeSides(entry.first, faces[0], faces[1])) {
              valid = false;
              break;
            }
            secondOrientation = orientation;
            sharedEdgeVertices.insert(entry.first.a);
            sharedEdgeVertices.insert(entry.first.b);
          }
        }
        if(!valid || secondOrientation == 0 || boundary.size() < 3) continue;
        // Exclude disconnected vertex links (two polygons meeting additionally
        // at an isolated vertex) and require one simple boundary cycle.
        for(const auto &vertex : vertexMembership)
          if(vertex.second == 3 && !sharedEdgeVertices.count(vertex.first)) valid = false;
        for(const auto &vertex : boundary)
          if(vertex.second.size() != 2) valid = false;
        if(!valid) continue;
        std::set<int> visited;
        std::vector<int> pending{boundary.begin()->first};
        while(!pending.empty()) {
          const int vertex = pending.back();
          pending.pop_back();
          if(!visited.insert(vertex).second) continue;
          for(int neighbor : boundary.at(vertex)) pending.push_back(neighbor);
        }
        if(visited.size() != boundary.size()) continue;

        // The polygons already belong to the interior raw complex. Also
        // require a native CAD witness at the contour centre and throughout
        // their original triangle fans, so a real CAD opening is not closed
        // merely because its boundary vertices lie inside the solid.
        if(!queriedCadVolumes) {
          gmsh::model::getEntities(cadVolumes, 3);
          queriedCadVolumes = true;
        }
        if(cadVolumes.empty()) continue;
        const auto insideCad = [&](const Eigen::Vector3d &p) {
          if(!p.allFinite()) return false;
          for(const auto &volume : cadVolumes)
            if(gmsh::model::isInside(3, volume.second, {p.x(), p.y(), p.z()}) == 1)
              return true;
          return false;
        };
        Eigen::Vector3d boundaryCenter = Eigen::Vector3d::Zero();
        const Eigen::Vector3d origin = point(boundary.begin()->first);
        for(const auto &vertex : boundary) boundaryCenter += point(vertex.first) - origin;
        boundaryCenter = origin + boundaryCenter / static_cast<double>(boundary.size());
        valid = insideCad(boundaryCenter);
        constexpr std::array<std::array<double, 3>, 7> samples{{
            {{1./3., 1./3., 1./3.}}, {{.5, .5, 0.}}, {{0., .5, .5}},
            {{.5, 0., .5}}, {{.6, .2, .2}}, {{.2, .6, .2}}, {{.2, .2, .6}}}};
        std::vector<double> cadWitnessPoints;
        for(std::size_t face : faces) {
          const auto &vertices = vor.faces[face].verts;
          for(std::size_t i = 0; i < vertices.size() && valid; ++i) {
            const Eigen::Vector3d a = point(vertices[i]);
            const Eigen::Vector3d b = point(vertices[(i+1) % vertices.size()]);
            for(const auto &weight : samples) {
              const Eigen::Vector3d p = faceCenters[face] +
                  weight[1]*(a-faceCenters[face]) + weight[2]*(b-faceCenters[face]);
              if(!p.allFinite()) {
                valid = false;
                break;
              }
              cadWitnessPoints.insert(cadWitnessPoints.end(), {p.x(), p.y(), p.z()});
            }
          }
        }
        // Same witnesses and all-inside predicate as the scalar path. A
        // single call lets OCC reuse its expensive solid-classifier setup.
        if(valid && cadVolumes.size() == 1)
          valid = gmsh::model::isInside(3, cadVolumes.front().second,
                                        cadWitnessPoints) ==
                  static_cast<int>(cadWitnessPoints.size() / 3);
        else if(valid) {
          // With several solids, different points can belong to different
          // solids. Preserve the original pointwise union semantics.
          for(std::size_t i = 0; i < cadWitnessPoints.size() && valid; i += 3)
            valid = insideCad(Eigen::Vector3d(cadWitnessPoints[i],
                                             cadWitnessPoints[i+1],
                                             cadWitnessPoints[i+2]));
        }
        if(!valid) continue;
        for(int branch : {firstBranch, secondBranch}) {
          decisions.at(branch).classification = matBranchClassifier::Class::MidSurface;
          restoredInteriorBranchTags.insert(branch);
          wingClosureCapBranchTags.insert(branch);
          ++restoredInteriorBranches;
          restoredInteriorFaces += decisions.at(branch).faceCount;
        }
        ++restoredCapPairs;
        if(report) {
          *report << "Restored paired wing closure caps: branches=" << firstBranch
                  << ',' << secondBranch << " boundaryEdges=" << boundary.size()
                  << " area=" << faceAreas[faces[0]] + faceAreas[faces[1]]
                  << " openingAngles="
                  << byBranch.at(firstBranch).branch.faces.front().openingAngleDegrees
                  << ',' << byBranch.at(secondBranch).branch.faces.front().openingAngleDegrees
                  << " sourceSeedOwners=";
          for(std::size_t face : faces)
            for(int seed : {vor.faces[face].edge.a, vor.faces[face].edge.b}) {
              if(seed >= 0 && static_cast<std::size_t>(seed) < del.onWhat.size())
                *report << '(' << del.onWhat[seed].first << ',' << del.onWhat[seed].second << ')';
              else *report << "(unknown)";
            }
          *report << '\n';
        }
      }
    }
    if(report) *report << "Paired wing closure cap restoration: pairs="
                       << restoredCapPairs << '\n';

    // A restored cap is not a new geometric surface. Absorb it into the one
    // of its two retained neighbors whose normals are the most continuous
    // across their common edges. Keep a true crease when neither mean normal
    // alignment is better than 60 degrees.
    struct Alignment {
      double weightedCosine = 0.0;
      double weight = 0.0;
    };
    std::map<int, std::map<int, Alignment>> alignments;
    for(const auto &edgeEntry : edgeFaces) {
      double edgeLength = 0.0;
      if(edgeEntry.first.a >= 0 && edgeEntry.first.b >= 0 &&
         3 * edgeEntry.first.a + 2 < static_cast<int>(vor.vertices.size()) &&
         3 * edgeEntry.first.b + 2 < static_cast<int>(vor.vertices.size())) {
        const Eigen::Vector3d a(
            vor.vertices[3 * edgeEntry.first.a],
            vor.vertices[3 * edgeEntry.first.a + 1],
            vor.vertices[3 * edgeEntry.first.a + 2]);
        const Eigen::Vector3d b(
            vor.vertices[3 * edgeEntry.first.b],
            vor.vertices[3 * edgeEntry.first.b + 1],
            vor.vertices[3 * edgeEntry.first.b + 2]);
        edgeLength = (a - b).norm();
      }
      const double weight = std::max(edgeLength, 1.e-30);
      for(int capFace : edgeEntry.second) {
        const int capBranch = vor.faceColors[capFace];
        if(wingClosureCapBranchTags.count(capBranch) == 0 ||
           faceNormals[capFace].squaredNorm() <= 0.0)
          continue;
        for(int neighborFace : edgeEntry.second) {
          const int neighborBranch = vor.faceColors[neighborFace];
          if(neighborBranch == capBranch ||
             wingClosureCapBranchTags.count(neighborBranch) != 0 ||
             faceNormals[neighborFace].squaredNorm() <= 0.0)
            continue;
          const auto neighborDecision = decisions.find(neighborBranch);
          if(neighborDecision == decisions.end() ||
             neighborDecision->second.classification !=
                 matBranchClassifier::Class::MidSurface)
            continue;
          Alignment &alignment = alignments[capBranch][neighborBranch];
          alignment.weightedCosine += weight * std::abs(
              faceNormals[capFace].dot(faceNormals[neighborFace]));
          alignment.weight += weight;
        }
      }
    }
    constexpr double minimumMergeNormalCosine = 0.5; // 60 degrees
    if(wingClosureCapMergeTargets) {
      for(int capBranch : wingClosureCapBranchTags) {
        int bestNeighbor = -1;
        double bestCosine = -1.0;
        double bestArea = -1.0;
        const auto candidatesForCap = alignments.find(capBranch);
        if(candidatesForCap == alignments.end()) continue;
        for(const auto &candidate : candidatesForCap->second) {
          if(candidate.second.weight <= 0.0) continue;
          const double cosine = candidate.second.weightedCosine /
                                candidate.second.weight;
          const auto neighborDecision = decisions.find(candidate.first);
          const double area = neighborDecision == decisions.end() ? 0.0 :
                                                       neighborDecision->second.area;
          if(cosine > bestCosine + 1.e-12 ||
             (std::abs(cosine - bestCosine) <= 1.e-12 &&
              (area > bestArea ||
               (area == bestArea && candidate.first < bestNeighbor)))) {
            bestNeighbor = candidate.first;
            bestCosine = cosine;
            bestArea = area;
          }
        }
        if(bestNeighbor >= 0 && bestCosine >= minimumMergeNormalCosine)
          (*wingClosureCapMergeTargets)[capBranch] = bestNeighbor;
      }
    }
  }

  // A rejected component completely enclosed by one accepted sheet is not a
  // peripheral wing: removing it would punch an artificial hole in the MAT.
  // Only restore components whose every boundary edge is sewn to the same
  // accepted branch. In particular, an original free edge or contact with
  // another rejected component prevents restoration.
  struct Enclosure {
    bool hasBoundary = false;
    bool enclosed = true;
    int enclosingBranch = -1;
  };
  std::map<int, Enclosure> enclosures;
  for(const auto &faceEntry : edgeFaces) {
    std::map<int, int> incidentCounts;
    for(int face : faceEntry.second) {
      const int branch = vor.faceColors[face];
      if(branch >= 0) ++incidentCounts[branch];
    }
    for(const auto &incident : incidentCounts) {
      const int branch = incident.first;
      if(incidentCounts.size() == 1 && incident.second > 1) continue;
      Enclosure &enclosure = enclosures[branch];
      enclosure.hasBoundary = true;
      if(incidentCounts.size() == 1) {
        enclosure.enclosed = false; // original free boundary
        continue;
      }
      for(const auto &otherIncident : incidentCounts) {
        const int other = otherIncident.first;
        if(other == branch) continue;
        const auto otherDecision = decisions.find(other);
        if(otherDecision == decisions.end() ||
           otherDecision->second.classification !=
             matBranchClassifier::Class::MidSurface ||
           (enclosure.enclosingBranch >= 0 &&
            enclosure.enclosingBranch != other)) {
          enclosure.enclosed = false;
          break;
        }
        enclosure.enclosingBranch = other;
      }
    }
  }
  if(policy.restoreEnclosedBranches)
  for(auto &decisionEntry : decisions) {
    const int branch = decisionEntry.first;
    if(decisionEntry.second.classification ==
         matBranchClassifier::Class::MidSurface ||
       desiredClasses.count(branch) != 0)
      continue;
    const auto enclosure = enclosures.find(branch);
    if(enclosure != enclosures.end() &&
       enclosure->second.hasBoundary && enclosure->second.enclosed &&
       enclosure->second.enclosingBranch >= 0) {
      decisionEntry.second.classification =
        matBranchClassifier::Class::MidSurface;
      ++restoredInteriorBranches;
      restoredInteriorFaces += decisionEntry.second.faceCount;
      restoredInteriorBranchTags.insert(branch);
    }
  }

  // CAD-pair segmentation deliberately gives adjacent pieces distinct branch
  // ids.  The strict single-enclosing-branch test above consequently misses
  // an interior rejected island as soon as two accepted CAD-pair zones meet
  // around it.  Work on connected rejected components instead: a component
  // that has no free MAT boundary and whose complete external neighborhood is
  // accepted is an interior hole, irrespective of how many accepted zone ids
  // surround it.  Expert-rejected branches remain authoritative and are not
  // candidates for automatic restoration.
  if(policy.restoreEnclosedBranches) {
  std::set<int> visitedRejectedComponents;
  for(const auto &entry : decisions) {
    const int seedBranch = entry.first;
    if(entry.second.classification ==
           matBranchClassifier::Class::MidSurface ||
       desiredClasses.count(seedBranch) != 0 ||
       visitedRejectedComponents.count(seedBranch) != 0)
      continue;

    std::vector<int> component;
    std::deque<int> queue;
    queue.push_back(seedBranch);
    visitedRejectedComponents.insert(seedBranch);
    bool touchesFreeBoundary = false;
    bool hasAcceptedNeighbor = false;
    bool hasRejectedExternalNeighbor = false;
    while(!queue.empty()) {
      const int branch = queue.front();
      queue.pop_front();
      component.push_back(branch);
      const auto branchIt = byBranch.find(branch);
      if(branchIt == byBranch.end()) {
        touchesFreeBoundary = true;
        continue;
      }
      touchesFreeBoundary = touchesFreeBoundary ||
          branchIt->second.freeBoundaryEdgeCount > 0;
      for(int neighbor : branchIt->second.branch.neighbors) {
        const auto neighborDecision = decisions.find(neighbor);
        if(neighborDecision == decisions.end()) {
          hasRejectedExternalNeighbor = true;
          continue;
        }
        if(neighborDecision->second.classification ==
           matBranchClassifier::Class::MidSurface) {
          hasAcceptedNeighbor = true;
          continue;
        }
        if(desiredClasses.count(neighbor) != 0) {
          hasRejectedExternalNeighbor = true;
          continue;
        }
        if(visitedRejectedComponents.insert(neighbor).second)
          queue.push_back(neighbor);
      }
    }
    if(touchesFreeBoundary || !hasAcceptedNeighbor ||
       hasRejectedExternalNeighbor)
      continue;
    for(int branch : component) {
      auto decision = decisions.find(branch);
      if(decision == decisions.end() ||
         decision->second.classification ==
             matBranchClassifier::Class::MidSurface)
        continue;
      decision->second.classification =
          matBranchClassifier::Class::MidSurface;
      ++restoredInteriorBranches;
      restoredInteriorFaces += decision->second.faceCount;
      restoredInteriorBranchTags.insert(branch);
    }
  }
  }



  std::ofstream pos;


  std::size_t counts[4] = {0, 0, 0, 0};
  for(const auto &entry : decisions) {
    ++counts[static_cast<int>(entry.second.classification)];
    if(effectiveClasses)
      (*effectiveClasses)[entry.first] =
          static_cast<int>(entry.second.classification);
  }
  for(std::size_t i = 0; i < vor.faceColors.size(); ++i) {
    const auto decision = decisions.find(vor.faceColors[i]);
    if(decision == decisions.end()) continue;
    const auto classification = decision->second.classification;
    if(classification != matBranchClassifier::Class::MidSurface)
      vor.faceColors[i] = -1;
  }
  if(report) {
    *report << "Branch classification: midsurface=" << counts[1]
            << " decisionTreeRejected=" << counts[2]
            << " spurious=" << counts[3]
            << " restoredInteriorBranches=" << restoredInteriorBranches
            << " restoredInteriorFaces=" << restoredInteriorFaces
            << " restoredWingClosureCaps="
            << wingClosureCapBranchTags.size()
            << " mergeableWingClosureCaps="
            << (wingClosureCapMergeTargets ?
                    wingClosureCapMergeTargets->size() : 0) << "\n";
  }
}

std::map<int, int> matGmsh::restoreSewnClosureDisks(
    const std::vector<int> &unfilteredFaceColors, std::ostream *report)
{
  ScopedTimer timer(*this, "restoreSewnClosureDisks");
  if(unfilteredFaceColors.size() != vor.faces.size() ||
     vor.faceColors.size() != vor.faces.size())
    throw std::invalid_argument("Closure disk restoration requires complete raw and selected colors");

  // Evaluate every candidate against the same effective selection, after the
  // mixed filter. A branch with even one retained polygon is not a missing
  // closure disk; neither is a branch reaching the original raw boundary.
  std::set<int> partlyRetained;
  for(std::size_t face = 0; face < vor.faces.size(); ++face)
    if(vor.faceColors[face] >= 0 && unfilteredFaceColors[face] >= 0)
      partlyRetained.insert(unfilteredFaceColors[face]);
  std::map<int, std::vector<std::size_t>> candidates;
  for(std::size_t face = 0; face < vor.faces.size(); ++face) {
    const int branch = unfilteredFaceColors[face];
    if(branch >= 0 && !partlyRetained.count(branch))
      candidates[branch].push_back(face);
  }

  struct EdgeUse {
    std::size_t raw = 0, retained = 0, retainedFace = 0;
  };
  std::unordered_map<matGmshEdge, EdgeUse, MatGmshEdgeHash> edgeUses;
  std::set<int> invalidBranches;
  const std::size_t vertexCount = vor.vertices.size() / 3;
  const auto validVertex = [&](int vertex) {
    return vertex >= 0 && static_cast<std::size_t>(vertex) < vertexCount;
  };
  for(const auto &candidate : candidates)
    for(std::size_t face : candidate.second) {
      const auto &vertices = vor.faces[face].verts;
      if(vertices.size() < 3) invalidBranches.insert(candidate.first);
      for(std::size_t i = 0; i < vertices.size(); ++i) {
        const int a = vertices[i], b = vertices[(i + 1) % vertices.size()];
        if(!validVertex(a) || !validVertex(b) || a == b) {
          invalidBranches.insert(candidate.first);
          continue;
        }
        edgeUses.emplace(matGmshEdge(a, b), EdgeUse{});
      }
    }
  std::vector<unsigned char> retainedVertices(vertexCount, 0);
  for(std::size_t face = 0; face < vor.faces.size(); ++face) {
    if(unfilteredFaceColors[face] < 0) continue;
    const bool retained = vor.faceColors[face] >= 0;
    const auto &vertices = vor.faces[face].verts;
    for(std::size_t i = 0; i < vertices.size(); ++i) {
      const int a = vertices[i], b = vertices[(i + 1) % vertices.size()];
      if(retained && validVertex(a)) retainedVertices[a] = 1;
      if(!validVertex(a) || !validVertex(b)) continue;
      const auto found = edgeUses.find(matGmshEdge(a, b));
      if(found == edgeUses.end()) continue;
      ++found->second.raw;
      if(retained) {
        ++found->second.retained;
        found->second.retainedFace = face;
      }
    }
  }
  const auto point = [&](int vertex) -> Eigen::Vector3d {
    return {vor.vertices[3 * vertex], vor.vertices[3 * vertex + 1],
            vor.vertices[3 * vertex + 2]};
  };
  struct Geometry {
    Eigen::Vector3d center = Eigen::Vector3d::Zero();
    Eigen::Vector3d normal = Eigen::Vector3d::Zero();
    double area = 0.0;
  };
  const auto geometry = [&](std::size_t face, Geometry &result) {
    const auto &vertices = vor.faces[face].verts;
    if(vertices.size() < 3 || !validVertex(vertices.front())) return false;
    const Eigen::Vector3d origin = point(vertices.front());
    result = Geometry{};
    for(int vertex : vertices) {
      if(!validVertex(vertex) || !point(vertex).allFinite()) return false;
      result.center += point(vertex) - origin;
    }
    result.center = origin + result.center / static_cast<double>(vertices.size());
    for(std::size_t i = 0; i < vertices.size(); ++i)
      result.normal += (point(vertices[i]) - result.center).cross(
          point(vertices[(i + 1) % vertices.size()]) - result.center);
    const double norm = result.normal.norm();
    if(!result.center.allFinite() || !std::isfinite(norm) || !(norm > 0.0))
      return false;
    result.area = 0.5 * norm;
    result.normal /= norm;
    return true;
  };

  gmsh::vectorpair cadVolumes;
  bool queriedCadVolumes = false;
  const auto insideCad = [&](const Eigen::Vector3d &p) {
    if(!p.allFinite()) return false;
    for(const auto &volume : cadVolumes)
      if(gmsh::model::isInside(3, volume.second, {p.x(), p.y(), p.z()}) == 1)
        return true;
    return false;
  };
  std::map<int, int> mergeTargets;
  std::map<int, matClosureCapTopology::DiskContacts> diskContacts;
  struct DiskAudit { std::size_t boundaryEdges; double area, meanNormalCosine; };
  std::map<int, DiskAudit> diskAudits;
  std::size_t interiorCandidates = 0, restoredFaces = 0;
  for(const auto &candidate : candidates) {
    const int branch = candidate.first;
    if(invalidBranches.count(branch)) continue;
    bool valid = true;
    std::set<matGmshEdge> patchEdges;
    for(std::size_t face : candidate.second) {
      const auto &vertices = vor.faces[face].verts;
      for(std::size_t i = 0; i < vertices.size(); ++i) {
        const matGmshEdge edge(vertices[i], vertices[(i + 1) % vertices.size()]);
        if(edgeUses.at(edge).raw == 1) valid = false;
        patchEdges.insert(edge);
      }
    }
    if(!valid) continue;
    ++interiorCandidates;
    std::vector<matClosureCapTopology::Polygon> polygons;
    std::map<int, matClosureCapTopology::Point> points;
    std::map<matClosureCapTopology::Edge,
             std::vector<matClosureCapTopology::Point>> retainedCenters;
    std::map<std::size_t, Geometry> geometryByFace;
    double area = 0.0;
    for(std::size_t face : candidate.second) {
      Geometry shape;
      if(!geometry(face, shape)) { valid = false; break; }
      geometryByFace.emplace(face, shape);
      area += shape.area;
      const auto &vertices = vor.faces[face].verts;
      polygons.push_back({vertices, {shape.center.x(), shape.center.y(), shape.center.z()}});
      for(int vertex : vertices) {
        const Eigen::Vector3d p = point(vertex);
        points.emplace(vertex, matClosureCapTopology::Point{p.x(), p.y(), p.z()});
      }
    }
    if(!valid) continue;
    for(const matGmshEdge &edge : patchEdges) {
      const EdgeUse &use = edgeUses.at(edge);
      if(use.retained > 1) { valid = false; break; }
      if(use.retained == 0) continue;
      Geometry shape;
      if(!geometry(use.retainedFace, shape)) { valid = false; break; }
      geometryByFace.emplace(use.retainedFace, shape);
      retainedCenters[{edge.a, edge.b}].push_back(
          {shape.center.x(), shape.center.y(), shape.center.z()});
    }
    if(!valid) continue;
    std::set<int> retainedPatchVertices;
    for(const auto &vertex : points)
      if(retainedVertices[vertex.first]) retainedPatchVertices.insert(vertex.first);
    std::vector<int> boundary;
    if(!matClosureCapTopology::isSewnDisk(
           polygons, points, retainedCenters, retainedPatchVertices, &boundary))
      continue;

    // The original Voronoi polygons are kept intact. Supplement their local
    // topological/normal certificate with native CAD witnesses; these sampled
    // checks must not be described as a continuous containment proof.
    if(!queriedCadVolumes) {
      gmsh::model::getEntities(cadVolumes, 3);
      queriedCadVolumes = true;
    }
    const Eigen::Vector3d origin = point(boundary.front());
    Eigen::Vector3d center = Eigen::Vector3d::Zero();
    for(int vertex : boundary) center += point(vertex) - origin;
    center = origin + center / static_cast<double>(boundary.size());
    if(report)
      *report << "Closure disk CAD check: branch=" << branch
              << " points=" << candidate.second.size() + 1 << " started" << std::endl;
    if(cadVolumes.size() == 1) {
      // The batch API reuses the OCC classifier for these same witnesses.
      // Preserve their coordinates and order: boundary mean, then every
      // original polygon centre. All samples must belong to this volume.
      std::vector<double> samples;
      samples.reserve(3 * (candidate.second.size() + 1));
      const auto appendFinite = [&](const Eigen::Vector3d &p) {
        if(!p.allFinite()) return false;
        samples.insert(samples.end(), {p.x(), p.y(), p.z()});
        return true;
      };
      valid = appendFinite(center);
      for(std::size_t face : candidate.second) {
        if(!valid) break;
        valid = appendFinite(geometryByFace.at(face).center);
      }
      if(valid) {
        const int inside = gmsh::model::isInside(3, cadVolumes.front().second, samples);
        valid = inside >= 0 && static_cast<std::size_t>(inside) == samples.size() / 3;
      }
    }
    else {
      // For multiple solids each point may belong to a different volume.
      valid = insideCad(center);
      for(std::size_t face : candidate.second) {
        if(!valid) break;
        valid = insideCad(geometryByFace.at(face).center);
      }
    }
    if(report)
      *report << "Closure disk CAD check: branch=" << branch
              << " result=" << (valid ? "accepted" : "rejected") << std::endl;
    if(!valid) continue;

    struct Alignment { double weightedCosine = 0.0, weight = 0.0; };
    std::map<int, Alignment> alignments;
    for(std::size_t face : candidate.second) {
      const auto &vertices = vor.faces[face].verts;
      for(std::size_t i = 0; i < vertices.size(); ++i) {
        const matGmshEdge edge(vertices[i], vertices[(i + 1) % vertices.size()]);
        const EdgeUse &use = edgeUses.at(edge);
        if(use.retained != 1) continue;
        const double weight = (point(edge.b) - point(edge.a)).norm();
        Alignment &alignment = alignments[vor.faceColors[use.retainedFace]];
        alignment.weight += weight;
        alignment.weightedCosine += weight * std::abs(
            geometryByFace.at(face).normal.dot(geometryByFace.at(use.retainedFace).normal));
      }
    }
    int target = -1;
    double bestCosine = -1.0, bestWeight = -1.0;
    for(const auto &entry : alignments) {
      if(!(entry.second.weight > 0.0)) continue;
      const double cosine = entry.second.weightedCosine / entry.second.weight;
      if(cosine > bestCosine + 1.e-12 ||
         (std::abs(cosine - bestCosine) <= 1.e-12 && entry.second.weight > bestWeight)) {
        target = entry.first;
        bestCosine = cosine;
        bestWeight = entry.second.weight;
      }
    }
    if(target < 0 || bestCosine < 0.5) continue;
    mergeTargets.emplace(branch, target);
    auto &contacts = diskContacts[branch];
    for(const auto &edge : patchEdges) contacts.edges.emplace(edge.a, edge.b);
    for(const auto &vertex : points) contacts.vertices.insert(vertex.first);
    contacts.boundaryVertices.insert(boundary.begin(), boundary.end());
    diskAudits.emplace(branch, DiskAudit{boundary.size(), area, bestCosine});
  }
  // Commit only after all certificates used the original effective selection.
  // Newly restored disks cannot serve as evidence for another restoration.
  const auto conflicts = matClosureCapTopology::conflictingDisks(diskContacts);
  for(int branch : conflicts) mergeTargets.erase(branch);
  for(const auto &target : mergeTargets) {
    for(std::size_t face : candidates.at(target.first)) vor.faceColors[face] = target.first;
    restoredFaces += candidates.at(target.first).size();
    const auto &audit = diskAudits.at(target.first);
    if(report)
      *report << "Restored sewn closure disk after mixed filtering: branch=" << target.first
              << " faces=" << candidates.at(target.first).size()
              << " boundaryEdges=" << audit.boundaryEdges << " area=" << audit.area
              << " mergeTarget=" << target.second
              << " meanNormalCosine=" << audit.meanNormalCosine << '\n';
  }
  if(report)
    *report << "Sewn closure disk restoration after mixed filtering: interiorCandidates="
            << interiorCandidates << " branches=" << mergeTargets.size()
            << " faces=" << restoredFaces << " conflictingBranches=" << conflicts.size() << '\n';
  return mergeTargets;
}
