#include "matBranchClassifier.h"

#ifdef NDEBUG
#undef NDEBUG
#endif
#include <cassert>

namespace {

matBranchClassifier::Decision decision(matBranchClassifier::Class value,
                                       double area)
{
  matBranchClassifier::Decision result;
  result.classification = value;
  result.area = area;
  return result;
}

} // namespace

int main()
{
  using matBranchClassifier::Branch;
  using matBranchClassifier::Class;

  // Aggregated measured features of two missing OFF-supported sheets in
  // A9608856807. Their medians are represented by equal-area samples here;
  // full-mesh coverage is checked separately against the OFF reference.
  Branch longSheet{101, {}, {}, 39.9162};
  longSheet.faces.assign(410, {97.0088 / 410., 3.42348, 1.91, 118.369});
  Branch shortSheet{102, {}, {}, 19.64};
  shortSheet.faces.assign(209, {18.1594 / 209., 3.6555, 1.95, 163.235});
  // A normal sheet, a terminal wing and one-polygon debris retain their
  // classifications; neither world position nor a branch id is a feature.
  Branch plate{103, {{50., 3.5, 1.75, 180.},
                     {50., 3.5, 1.75, 180.}}, {}, 14.1421356237};
  Branch wing{104, {{10., 1., 0.7, 90.},
                    {10., 1., 0.7, 90.}}, {}, 10.};
  Branch debris{105, {{100., 3.5, 1.75, 180.}}, {}, 10.};
  const auto sheetDecisions = matBranchClassifier::classify(
      {longSheet, shortSheet, plate, wing, debris});
  assert(sheetDecisions.at(101).classification == Class::MidSurface);
  assert(sheetDecisions.at(102).classification == Class::MidSurface);
  assert(sheetDecisions.at(103).classification == Class::MidSurface);
  assert(sheetDecisions.at(104).classification == Class::Rejected);
  assert(sheetDecisions.at(105).classification == Class::Spurious);

  // Interior connector rule: an opposed-contact polygon bridges two retained
  // sheets even if a one-face/shape-ratio prefilter would reject it. Unknown
  // boundaries, free edges, one-sided contacts and terminal appendages do not
  // qualify. A pair of rejected pieces cannot bootstrap each other.
  Branch sheetA = plate, sheetB = plate;
  sheetA.tag = 201; sheetB.tag = 202;
  Branch connector{203, {{0.002, 4., 2., 165.}}, {201, 202}, 0.23, 0};
  Branch openConnector = connector; openConnector.tag = 204;
  openConnector.freeBoundaryEdgeCount = 1;
  Branch uncertainConnector = connector; uncertainConnector.tag = 205;
  uncertainConnector.freeBoundaryEdgeCount = -1;
  Branch end = connector; end.tag = 206; end.neighbors = {201};
  Branch oblique = connector; oblique.tag = 207;
  oblique.faces.front().openingAngleDegrees = 90.;
  Branch chainA = connector, chainB = connector;
  chainA.tag = 208; chainA.neighbors = {201, 209};
  chainB.tag = 209; chainB.neighbors = {202, 208};
  Branch narrow{210, {{1.5, 4.8, 2.5, 160.}, {1.5, 4.8, 2.5, 170.}},
                {201, 202}, 9.74, 0};
  const auto connectors = matBranchClassifier::classify(
      {sheetA, sheetB, connector, openConnector, uncertainConnector, end,
       oblique, chainA, chainB, narrow});
  assert(connectors.at(203).classification == Class::MidSurface);
  assert(connectors.at(210).classification == Class::MidSurface);
  for(int tag : {204, 205, 206, 207, 208, 209})
    assert(connectors.at(tag).classification == Class::Spurious);

  std::vector<Branch> branches = {
      {1, {}, {2, 3, 4, 12}, 0.0}, // closure cap between two wings
      {5, {}, {2, 3, 4}, 0.0}, // has its own free edge
      {6, {}, {2, 4, 7}, 0.0}, // only one retained neighbor
      {8, {}, {2, 3, 9}, 0.0}, // rejected neighbor is interior
      {10, {}, {2, 3, 11}, 0.0}, // incomplete neighborhood
      {13, {}, {2, 3, 4}, 0.0}, // too large relative to its wing
  };
  std::map<int, matBranchClassifier::Decision> decisions = {
      {1, decision(Class::Spurious, 0.05)},
      {2, decision(Class::MidSurface, 1000.0)},
      {3, decision(Class::MidSurface, 2000.0)},
      {4, decision(Class::Rejected, 100.0)},
      {5, decision(Class::Rejected, 0.05)},
      {6, decision(Class::Rejected, 0.05)},
      {7, decision(Class::Spurious, 100.0)},
      {8, decision(Class::Rejected, 0.05)},
      {9, decision(Class::Rejected, 100.0)},
      {10, decision(Class::Rejected, 0.05)},
      {12, decision(Class::Rejected, 200.0)},
      {13, decision(Class::Rejected, 0.2)},
  };
  std::map<int, std::size_t> freeBoundaryEdges = {
      {1, 0}, {2, 0}, {3, 0}, {4, 12}, {5, 1},
      {6, 0}, {7, 4}, {8, 0}, {9, 0}, {10, 0}, {12, 7}, {13, 0},
  };

  const std::set<int> caps =
      matBranchClassifier::findWingClosureCapBranches(
          branches, decisions, freeBoundaryEdges);
  assert(caps == std::set<int>{1});
  return 0;
}
