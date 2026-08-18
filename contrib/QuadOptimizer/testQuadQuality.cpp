#include "quadQuality.h"

#include <cmath>
#include <iostream>

namespace {
  bool near(double a, double b, double tolerance = 1.e-10)
  {
    return std::abs(a - b) <= tolerance;
  }
}

int main()
{
  using namespace QuadOptimizer;
  const std::vector<std::array<double, 3> > square = {
    {0., 0., 0.}, {1., 0., 0.}, {1., 1., 0.}, {0., 1., 0.}};
  const ElementQuality quad =
    evaluateElementQuality(SurfaceElementKind::Quadrangle, square);
  if(!near(quad.warpingDegrees, 0.) || !near(quad.edgeRatio, 1.) ||
     !near(quad.minimumAngleDegrees, 90.) ||
     !near(quad.maximumAngleDegrees, 90.) ||
     !near(quad.skewingDegrees, 0.) ||
     !quad.passesAbsoluteSpecifications) {
    std::cerr << "perfect quad quality is incorrect\n";
    return 1;
  }

  const double root3 = std::sqrt(3.);
  const std::vector<std::array<double, 3> > equilateral = {
    {0., 0., 0.}, {1., 0., 0.}, {.5, .5 * root3, 0.}};
  const ElementQuality triangle =
    evaluateElementQuality(SurfaceElementKind::Triangle, equilateral);
  if(!near(triangle.edgeRatio, 1.) ||
     !near(triangle.minimumAngleDegrees, 60.) ||
     !near(triangle.maximumAngleDegrees, 60.) ||
     !near(triangle.skewingDegrees, 0.) ||
     !triangle.passesAbsoluteSpecifications) {
    std::cerr << "perfect triangle quality is incorrect\n";
    return 2;
  }

  const std::vector<std::array<double, 3> > bad = {
    {0., 0., 0.}, {10., 0., 0.}, {10., .01, 0.}, {0., 1., 0.}};
  const ElementQuality badQuad =
    evaluateElementQuality(SurfaceElementKind::Quadrangle, bad);
  if(badQuad.passesAbsoluteSpecifications ||
     !improvesSpecificationObjective(specificationObjective(quad),
                                     specificationObjective(badQuad))) {
    std::cerr << "quality objective ordering is incorrect\n";
    return 3;
  }
  return 0;
}
