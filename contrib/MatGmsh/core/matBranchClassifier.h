#pragma once

#include <map>
#include <set>
#include <vector>

namespace matBranchClassifier {

enum class Class : int { MidSurface = 1, Rejected = 2, Spurious = 3 };

struct FaceSample {
  double area = 0.0;
  double seedDistance = 0.0;
  double medialRadius = 0.0;
  double openingAngleDegrees = 0.0;
};

struct Branch {
  int tag = -1;
  std::vector<FaceSample> faces;
  std::set<int> neighbors;
  double diameter = 0.0;
  // Negative means that original (unfiltered) boundary information is absent.
  // Do not infer this from the boundary left after rejecting other branches.
  int freeBoundaryEdgeCount = -1;
};

struct Decision {
  Class classification = Class::Rejected;
  double area = 0.0;
  double medianOpeningAngleDegrees = 0.0;
  double medianSeedDistance = 0.0;
  double diameter = 0.0;
  double areaOverDiameterSquared = 0.0;
  double seedDistanceOverDiameter = 0.0;
  std::size_t faceCount = 0;
  std::size_t neighborCount = 0;
};

std::map<int, Decision> classify(const std::vector<Branch> &branches);

// Find rejected sheets that must remain as topological closure caps after a
// terminal wing is removed. Such a sheet has no original free boundary and
// meets exactly two retained sheets plus one or more rejected wings that
// reach the original MAT boundary. It must also be negligible relative to
// every wing it closes. Removing the cap would open an artificial hole
// between the two retained sheets.
std::set<int> findWingClosureCapBranches(
    const std::vector<Branch> &branches,
    const std::map<int, Decision> &decisions,
    const std::map<int, std::size_t> &freeBoundaryEdgeCounts);

} // namespace matBranchClassifier
