#include "matBranchClassifier.h"
#include "matBranchDecisionTree.h"

#include <algorithm>

namespace matBranchClassifier {
namespace {
double weightedMedian(std::vector<std::pair<double, double>> values)
{
  if(values.empty()) return 0.0;
  std::sort(values.begin(), values.end());
  double total = 0.0;
  for(const auto &value : values) total += value.second;
  if(total <= 0.0) return values[values.size() / 2].first;
  double accumulated = 0.0;
  for(const auto &value : values) {
    accumulated += value.second;
    if(accumulated >= 0.5 * total) return value.first;
  }
  return values.back().first;
}
}

std::map<int, Decision> classify(const std::vector<Branch> &branches)
{
  std::map<int, Decision> result;
  for(const Branch &branch : branches) {
    Decision decision;
    decision.faceCount = branch.faces.size();
    decision.neighborCount = branch.neighbors.size();
    decision.diameter = branch.diameter;
    std::vector<std::pair<double, double>> angles, distances;
    for(const FaceSample &face : branch.faces) {
      decision.area += face.area;
      const double weight = std::max(face.area, 1.e-30);
      angles.push_back({face.openingAngleDegrees, weight});
      distances.push_back({face.seedDistance, weight});
    }
    decision.medianOpeningAngleDegrees = weightedMedian(std::move(angles));
    decision.medianSeedDistance = weightedMedian(std::move(distances));
    if(decision.diameter > 1.e-30) {
      decision.areaOverDiameterSquared =
          decision.area / (decision.diameter * decision.diameter);
      decision.seedDistanceOverDiameter =
          decision.medianSeedDistance / decision.diameter;
    }
    result[branch.tag] = decision;
  }
  for(const Branch &branch : branches) {
    Decision &decision = result[branch.tag];
    decision.classification =
        decision.faceCount <= 1 ? Class::Spurious : classifyLearned(decision);
  }
  // A small interior connector can contain just one Voronoi polygon or have
  // arbitrarily small area/diameter^2. Removing it can disconnect a useful
  // sheet. Require opposing contacts throughout the connector, no original
  // free edge, and at least two independently accepted neighbors. Evaluate
  // against the unmodified decisions so restoration cannot grow recursively.
  std::set<int> interiorConnectors;
  for(const Branch &branch : branches) {
    if(branch.freeBoundaryEdgeCount != 0 || branch.faces.empty() ||
       result.at(branch.tag).classification == Class::MidSurface)
      continue;
    if(!std::all_of(branch.faces.begin(), branch.faces.end(),
                    [](const FaceSample &face) {
                      return face.openingAngleDegrees >= 150.0;
                    }))
      continue;
    std::size_t acceptedNeighbors = 0;
    for(int neighbor : branch.neighbors) {
      const auto found = result.find(neighbor);
      if(found != result.end() &&
         found->second.classification == Class::MidSurface)
        ++acceptedNeighbors;
    }
    if(acceptedNeighbors >= 2) interiorConnectors.insert(branch.tag);
  }
  for(int tag : interiorConnectors)
    result.at(tag).classification = Class::MidSurface;
  return result;
}

std::set<int> findWingClosureCapBranches(
    const std::vector<Branch> &branches,
    const std::map<int, Decision> &decisions,
    const std::map<int, std::size_t> &freeBoundaryEdgeCounts)
{
  constexpr double maximumCapToWingAreaRatio = 1.e-3;
  std::set<int> result;
  for(const Branch &branch : branches) {
    const auto decision = decisions.find(branch.tag);
    const auto freeBoundary = freeBoundaryEdgeCounts.find(branch.tag);
    if(decision == decisions.end() ||
       decision->second.classification == Class::MidSurface ||
       freeBoundary == freeBoundaryEdgeCounts.end() ||
       freeBoundary->second != 0 || branch.neighbors.size() < 3)
      continue;

    std::size_t acceptedNeighbors = 0;
    std::size_t rejectedNeighbors = 0;
    bool completeNeighborhood = true;
    bool rejectedNeighborsAreTerminalWings = true;
    for(int neighbor : branch.neighbors) {
      const auto neighborDecision = decisions.find(neighbor);
      if(neighborDecision == decisions.end()) {
        completeNeighborhood = false;
        break;
      }
      if(neighborDecision->second.classification == Class::MidSurface) {
        ++acceptedNeighbors;
      }
      else {
        ++rejectedNeighbors;
        const auto rejectedFreeBoundary =
            freeBoundaryEdgeCounts.find(neighbor);
        if(rejectedFreeBoundary == freeBoundaryEdgeCounts.end() ||
           rejectedFreeBoundary->second == 0 ||
           neighborDecision->second.area <= 0.0 ||
           decision->second.area > maximumCapToWingAreaRatio *
                                       neighborDecision->second.area)
          rejectedNeighborsAreTerminalWings = false;
      }
    }
    if(!completeNeighborhood || acceptedNeighbors != 2 ||
       rejectedNeighbors == 0 || !rejectedNeighborsAreTerminalWings)
      continue;
    result.insert(branch.tag);
  }
  return result;
}

} // namespace matBranchClassifier
