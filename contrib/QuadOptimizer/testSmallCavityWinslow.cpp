#include "smallCavityWinslow.h"

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

int getDiskQuadrangulations(
  std::size_t boundaryVertexCount, std::size_t interiorVertexCount,
  std::vector<std::vector<std::array<std::size_t, 4> > > &quadrangulations);

namespace {
  bool near(double a, double b, double tolerance = 1.e-9)
  {
    return std::abs(a - b) <= tolerance;
  }

  int testOneInterior(bool clockwise)
  {
    std::vector<std::array<double, 2> > points = {
      {1., 0.}, {.5, .8660254037844386}, {-.5, .8660254037844386},
      {-1., 0.}, {-.5, -.8660254037844386}, {.5, -.8660254037844386},
      {-3., 4.}};
    std::vector<std::array<std::size_t, 4> > quads = {
      {0, 1, 2, 6}, {2, 3, 4, 6}, {4, 5, 0, 6}};
    if(clockwise) {
      std::reverse(points.begin(), points.begin() + 6);
    }
    const auto boundary = points;
    QuadOptimizer::SmallCavityWinslowOptions options;
    options.maxOuterIterations = 12;
    const auto result = QuadOptimizer::optimizeSmallQuadCavityWinslow(
      points, 6, quads, options);
    if(!result.success || !result.untangled ||
       !(result.minimumJacobian > 0.))
      return 1;
    for(std::size_t i = 0; i < 6; ++i) {
      if(!near(points[i][0], boundary[i][0]) ||
         !near(points[i][1], boundary[i][1]))
        return 2;
    }
    if(!std::isfinite(points[6][0]) || !std::isfinite(points[6][1])) return 3;
    return 0;
  }

  int testFourInteriors()
  {
    constexpr std::size_t boundaryCount = 8;
    std::vector<std::vector<std::array<std::size_t, 4> > > patterns;
    if(getDiskQuadrangulations(boundaryCount, 4, patterns) ||
       patterns.empty())
      return 1;
    std::vector<std::array<double, 2> > points(boundaryCount + 4);
    for(std::size_t i = 0; i < boundaryCount; ++i) {
      const double angle = 2. * 3.14159265358979323846 *
                           static_cast<double>(i) /
                           static_cast<double>(boundaryCount);
      points[i] = {std::cos(angle), std::sin(angle)};
    }
    points[8] = {3., 3.};
    points[9] = {-3., 3.};
    points[10] = {-3., -3.};
    points[11] = {3., -3.};
    const auto boundary = points;
    QuadOptimizer::SmallCavityWinslowOptions options;
    options.maxOuterIterations = 12;
    const auto result = QuadOptimizer::optimizeSmallQuadCavityWinslow(
      points, boundaryCount, patterns.front(), options);
    if(!result.success || !result.untangled ||
       !(result.minimumJacobian > 0.))
      return 2;
    for(std::size_t i = 0; i < boundaryCount; ++i) {
      if(!near(points[i][0], boundary[i][0]) ||
         !near(points[i][1], boundary[i][1]))
        return 3;
    }
    return 0;
  }
}

int main()
{
  const int ccw = testOneInterior(false);
  const int cw = testOneInterior(true);
  const int four = testFourInteriors();
  if(ccw || cw || four) {
    std::cerr << "small-cavity Winslow failed: ccw=" << ccw
              << " cw=" << cw << " four=" << four << '\n';
    return 1;
  }
  return 0;
}
