#pragma once

#include <Eigen/Core>
#include <Eigen/Eigenvalues>
#include <Eigen/Geometry>
#include <algorithm>
#include <array>
#include <cmath>
#include <cstddef>
#include <limits>
#include <set>
#include <utility>
#include <vector>

namespace matLocalMidSurfaceProjection {

struct Plane {
  Eigen::Vector3d origin = Eigen::Vector3d::Zero();
  Eigen::Vector3d normal = Eigen::Vector3d::UnitZ();
};

enum class RetainedVertexTopology {
  Unsupported,
  RegularInterior,
  SimpleBoundary
};

inline RetainedVertexTopology classifyRetainedVertexTopology(
    const std::vector<std::pair<std::size_t, std::size_t>>
        &incidentEdgeUseAndBranchCounts)
{
  if(incidentEdgeUseAndBranchCounts.empty())
    return RetainedVertexTopology::Unsupported;

  bool touchesBoundary = false;
  for(const auto &counts : incidentEdgeUseAndBranchCounts) {
    const bool regularInteriorEdge =
        counts.first == 2 && counts.second == 1;
    const bool simpleBoundaryEdge =
        counts.first == 1 && counts.second == 1;
    if(!regularInteriorEdge && !simpleBoundaryEdge)
      return RetainedVertexTopology::Unsupported;
    touchesBoundary = touchesBoundary || simpleBoundaryEdge;
  }
  return touchesBoundary ? RetainedVertexTopology::SimpleBoundary :
                           RetainedVertexTopology::RegularInterior;
}

template <class PairContainer>
inline bool allOppositePairsAreSurfaceClassifiedImpl(
    const std::vector<std::pair<int, int>> &classification,
    const PairContainer &oppositePairs)
{
  if(oppositePairs.empty()) return false;
  for(const auto &pair : oppositePairs) {
    if(pair.first < 0 || pair.second < 0 ||
       pair.first >= static_cast<int>(classification.size()) ||
       pair.second >= static_cast<int>(classification.size()) ||
       classification[pair.first].first != 2 ||
       classification[pair.second].first != 2) {
      return false;
    }
  }
  return true;
}

inline bool allOppositePairsAreSurfaceClassified(
    const std::vector<std::pair<int, int>> &classification,
    const std::set<std::pair<int, int>> &oppositePairs)
{
  return allOppositePairsAreSurfaceClassifiedImpl(
      classification, oppositePairs);
}

inline bool planeMidwayBetween(const Plane &first, const Plane &second,
                               Plane &midway)
{
  if(!first.origin.allFinite() || !second.origin.allFinite() ||
     !first.normal.allFinite() || !second.normal.allFinite())
    return false;

  Eigen::Vector3d firstNormal = first.normal;
  Eigen::Vector3d secondNormal = second.normal;
  const double firstNorm = firstNormal.norm();
  const double secondNorm = secondNormal.norm();
  if(!(firstNorm > 0.0) || !(secondNorm > 0.0)) return false;
  firstNormal /= firstNorm;
  secondNormal /= secondNorm;

  // Opposite CAD sides normally have opposite oriented normals. Align the
  // two local planes geometrically before averaging them.
  if(firstNormal.dot(secondNormal) < 0.0) secondNormal = -secondNormal;
  const Eigen::Vector3d summedNormal = firstNormal + secondNormal;
  const double midwayNorm = summedNormal.norm();
  if(!(midwayNorm > 0.0)) return false;
  midway.normal = summedNormal / midwayNorm;

  // Average the two signed plane equations, not their centroids. The latter
  // contains arbitrary tangential offsets and would make the midway plane
  // vary from one surface mesh vertex to the next for non-parallel planes.
  const double firstOffset = firstNormal.dot(first.origin);
  const double secondOffset = secondNormal.dot(second.origin);
  const double midwayOffset =
      (firstOffset + secondOffset) / midwayNorm;
  midway.origin = midwayOffset * midway.normal;
  return midway.origin.allFinite() && midway.normal.allFinite();
}

inline Eigen::Vector3d projectOntoPlane(const Eigen::Vector3d &point,
                                        const Plane &plane)
{
  return point - plane.normal.dot(point - plane.origin) * plane.normal;
}

inline bool projectOntoCommonLine(
    const Eigen::Vector3d &point, const std::vector<Plane> &planes,
    Eigen::Vector3d &projected, Eigen::Vector3d &lineDirection,
    double *smallestToLargestEigenvalueRatio = nullptr)
{
  if(!point.allFinite() || planes.size() < 2) return false;

  Eigen::Matrix3d normalMatrix = Eigen::Matrix3d::Zero();
  Eigen::Vector3d rightHandSide = Eigen::Vector3d::Zero();
  std::size_t usablePlanes = 0;
  for(const Plane &plane : planes) {
    if(!plane.origin.allFinite() || !plane.normal.allFinite()) continue;
    Eigen::Vector3d normal = plane.normal;
    const double norm = normal.norm();
    if(!(norm > std::numeric_limits<double>::min())) continue;
    normal /= norm;
    normalMatrix += normal * normal.transpose();
    rightHandSide += normal * normal.dot(plane.origin);
    ++usablePlanes;
  }
  if(usablePlanes < 2) return false;

  Eigen::SelfAdjointEigenSolver<Eigen::Matrix3d> eigen(normalMatrix);
  if(eigen.info() != Eigen::Success) return false;
  const Eigen::Vector3d eigenvalues = eigen.eigenvalues();
  const double largest = eigenvalues[2];
  const double middle = eigenvalues[1];
  const double rankTolerance =
      64.0 * std::numeric_limits<double>::epsilon() *
      std::max(1.0, largest);
  if(!(largest > rankTolerance) || !(middle > rankTolerance)) return false;

  lineDirection = eigen.eigenvectors().col(0).normalized();
  const Eigen::Vector3d residual = rightHandSide - normalMatrix * point;
  projected = point;
  for(int direction = 1; direction < 3; ++direction) {
    const Eigen::Vector3d basis = eigen.eigenvectors().col(direction);
    projected += basis * basis.dot(residual) / eigenvalues[direction];
  }
  if(smallestToLargestEigenvalueRatio)
    *smallestToLargestEigenvalueRatio =
        largest > 0.0 ? eigenvalues[0] / largest : 1.0;
  return projected.allFinite() && lineDirection.allFinite();
}

inline bool projectOntoEquidistantPointLine(
    const Eigen::Vector3d &point,
    const std::array<Eigen::Vector3d, 3> &supportPoints,
    Eigen::Vector3d &projected, Eigen::Vector3d &lineDirection,
    std::vector<Plane> *equidistanceConstraints = nullptr,
    double *smallestToLargestEigenvalueRatio = nullptr)
{
  if(!point.allFinite()) return false;
  for(const Eigen::Vector3d &supportPoint : supportPoints)
    if(!supportPoint.allFinite()) return false;

  std::vector<Plane> constraints;
  constraints.reserve(2);
  for(std::size_t support = 1; support < 3; ++support) {
    Eigen::Vector3d normal = supportPoints[support] - supportPoints[0];
    const double norm = normal.norm();
    if(!(norm > 64.0 * std::numeric_limits<double>::epsilon())) continue;
    const double offset =
        (supportPoints[support].squaredNorm() -
         supportPoints[0].squaredNorm()) /
        (2.0 * norm);
    normal /= norm;
    Plane constraint;
    constraint.normal = normal;
    constraint.origin = offset * normal;
    constraints.push_back(constraint);
  }
  if(equidistanceConstraints) *equidistanceConstraints = constraints;
  return projectOntoCommonLine(
      point, constraints, projected, lineDirection,
      smallestToLargestEigenvalueRatio);
}

inline Eigen::Vector3d limitBoundaryProjectionDisplacementJump(
    const Eigen::Vector3d &center, const Eigen::Vector3d &firstNeighbor,
    const Eigen::Vector3d &secondNeighbor,
    const Eigen::Vector3d &firstNeighborDisplacement,
    const Eigen::Vector3d &secondNeighborDisplacement,
    const Eigen::Vector3d &requestedDisplacement,
    double maximumJumpToEdgeRatio, bool *limited = nullptr)
{
  if(limited) *limited = false;
  const double firstLength = (center - firstNeighbor).norm();
  const double secondLength = (secondNeighbor - center).norm();
  if(!(firstLength > 0.0) || !(secondLength > 0.0) ||
     !(maximumJumpToEdgeRatio >= 0.0) ||
     !std::isfinite(maximumJumpToEdgeRatio))
    return requestedDisplacement;
  const Eigen::Vector3d predictedDisplacement =
      (secondLength * firstNeighborDisplacement +
       firstLength * secondNeighborDisplacement) /
      (firstLength + secondLength);
  Eigen::Vector3d jump = requestedDisplacement - predictedDisplacement;
  const double jumpNorm = jump.norm();
  const double maximumJump = maximumJumpToEdgeRatio *
      std::min(firstLength, secondLength);
  if(jumpNorm > maximumJump && maximumJump > 0.0) {
    jump *= maximumJump / jumpNorm;
    if(limited) *limited = true;
  }
  return predictedDisplacement + jump;
}

inline bool projectedFanTriangleIsValid(
    const Eigen::Vector3d &originalCenter,
    const Eigen::Vector3d &originalFirst,
    const Eigen::Vector3d &originalSecond,
    const Eigen::Vector3d &projectedCenter,
    const Eigen::Vector3d &projectedFirst,
    const Eigen::Vector3d &projectedSecond,
    double minimumAreaFraction = 0.01,
    double minimumEdgeStretch = 0.25,
    double maximumEdgeStretch = 4.0,
    double minimumQualityFraction = 0.1)
{
  if(!originalCenter.allFinite() || !originalFirst.allFinite() ||
     !originalSecond.allFinite() || !projectedCenter.allFinite() ||
     !projectedFirst.allFinite() || !projectedSecond.allFinite() ||
     !(minimumAreaFraction > 0.0) || !(minimumEdgeStretch > 0.0) ||
     !(maximumEdgeStretch >= minimumEdgeStretch) ||
     !(minimumQualityFraction > 0.0))
    return false;

  const std::array<Eigen::Vector3d, 3> originalEdges = {
      originalFirst - originalCenter,
      originalSecond - originalFirst,
      originalCenter - originalSecond};
  const std::array<Eigen::Vector3d, 3> projectedEdges = {
      projectedFirst - projectedCenter,
      projectedSecond - projectedFirst,
      projectedCenter - projectedSecond};
  double originalSquaredLengthSum = 0.0;
  double projectedSquaredLengthSum = 0.0;
  for(std::size_t edge = 0; edge < originalEdges.size(); ++edge) {
    const double originalLength = originalEdges[edge].norm();
    const double projectedLength = projectedEdges[edge].norm();
    if(!(originalLength > std::numeric_limits<double>::min()) ||
       !std::isfinite(projectedLength))
      return false;
    const double stretch = projectedLength / originalLength;
    if(stretch < minimumEdgeStretch || stretch > maximumEdgeStretch)
      return false;
    originalSquaredLengthSum += originalLength * originalLength;
    projectedSquaredLengthSum += projectedLength * projectedLength;
  }

  const Eigen::Vector3d originalCross =
      (originalFirst - originalCenter)
          .cross(originalSecond - originalCenter);
  const Eigen::Vector3d projectedCross =
      (projectedFirst - projectedCenter)
          .cross(projectedSecond - projectedCenter);
  const double originalDoubleArea = originalCross.norm();
  const double projectedDoubleArea = projectedCross.norm();
  if(!(originalDoubleArea > std::numeric_limits<double>::min()) ||
     !(projectedDoubleArea >= minimumAreaFraction * originalDoubleArea) ||
     !(projectedCross.dot(originalCross) > 0.0))
    return false;

  const double originalQuality =
      originalDoubleArea / originalSquaredLengthSum;
  const double projectedQuality =
      projectedDoubleArea / projectedSquaredLengthSum;
  return projectedQuality >= minimumQualityFraction * originalQuality;
}

} // namespace matLocalMidSurfaceProjection
