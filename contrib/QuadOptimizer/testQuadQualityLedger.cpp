#include "quadQualityLedger.h"
#include <cstdlib>
#include <iostream>
#include <limits>

using namespace QuadOptimizer;
static void require(bool value, const char *message)
{
  if(!value) { std::cerr << message << '\n'; std::exit(1); }
}
int main()
{
  ElementQuality quad;
  quad.kind = SurfaceElementKind::Quadrangle;
  quad.edgeRatio = 1.; quad.minimumAngleDegrees = 90.;
  quad.maximumAngleDegrees = 90.; quad.skewingDegrees = 0.;
  QualityLedger good; good.add(quad);
  quad.warpingDegrees = 15.;
  QualityLedger borderline; borderline.add(quad);
  QualityLedger total;
  for(int i = 0; i < 99; ++i) total.add(good);
  total.add(borderline);
  require(total.preferredDeficit()[0] == 0, "99/100 must pass");
  const auto smaller = total.replaced(good, QualityLedger{});
  require(smaller.criteria[QualityLedger::Warping].deficit() == 1,
          "98/99 must fail after removal of a passing element");
  require(smaller.replaced(borderline, good).preferredDeficit()[0] == 0,
          "repair must restore the exact quota");
  require(total.state() != smaller.state(), "quota cache context must change");
  require(QualityLedger{}.preferredDeficit()[0] == 0, "empty population is N/A");
  quad.warpingDegrees = 25.;
  QualityLedger absolute; absolute.add(quad);
  require(!absolute.absoluteNoWorseThan(good), "25 degrees must fail strictly");
  require(good.absoluteNoWorseThan(absolute), "repair absolute warping");
  quad.kind = SurfaceElementKind::Triangle;
  quad.minimumAngleDegrees = 20.; quad.maximumAngleDegrees = 120.;
  QualityLedger tri; tri.add(quad);
  require(tri.criteria[QualityLedger::Warping].elements == 0,
          "triangle warping must not dilute the quad quota");
  require(tri.preferredDeficit()[0] == 2, "triangle angle bounds are strict");
  quad.edgeRatio = std::numeric_limits<double>::quiet_NaN();
  QualityLedger nan; nan.add(quad);
  require(nan.criteria[QualityLedger::EdgeRatio].absoluteBad == 1,
          "missing metric must not pass");
  QualityLedger::Population huge{std::numeric_limits<std::size_t>::max(),
    std::numeric_limits<std::size_t>::max() / 100, 0};
  require(huge.deficit() == 0, "quota arithmetic must not multiply N by 100");
  bool threw = false;
  try { QualityLedger{}.replaced(good, tri); }
  catch(const std::logic_error &) { threw = true; }
  require(threw, "reject ledger underflow instead of wrapping a counter");
  std::cout << "Exact V2 quota ledger contracts passed\n";
}
