#include "quadSmartLaplacian.h"
#ifdef NDEBUG
#undef NDEBUG
#endif
#include <cassert>
#include <limits>

int main()
{
  using namespace QuadOptimizer::SmartLaplacian;
  std::array<Point, 4> square{{{{0.,0.,0.}}, {{1.,0.,0.}},
                              {{1.,1.,0.}}, {{0.,1.,0.}}}};
  assert(std::abs(minimumCornerSine(square,4)-1.)<1.e-14);
  std::array<Point, 4> triangle{{{{0.,0.,0.}}, {{1.,0.,0.}},
                                {{.5,std::sqrt(3.)/2.,0.}}, {{0.,0.,0.}}}};
  assert(std::abs(minimumCornerSine(triangle,3)-std::sqrt(3.)/2.)<1.e-14);
  auto skew=square;
  skew[2]={{.2,.4,0.}};
  assert(minimumCornerSine(skew,4)<0.); // Reflex corner must not look acute.
  for(double scale : {1.e-100, 1.e-3, 1., 1.e3, 1.e100}) {
    auto transformed=triangle;
    for(auto &p:transformed) {
      const Point old=p;
      // Rigid rotation into a physical 3D plane, then uniform scale.
      p={{scale*old[1], scale*.6*old[0], scale*.8*old[0]}};
    }
    assert(std::abs(minimumCornerSine(transformed,3)-minimumCornerSine(triangle,3))<1.e-13);
  }
  auto collapsed=square; collapsed[1]=collapsed[0];
  assert(minimumCornerSine(collapsed,4)<0.);
  auto invalid=square; invalid[1][0]=std::numeric_limits<double>::quiet_NaN();
  assert(minimumCornerSine(invalid,4)<0.);
  assert(minimumCornerSine(square,2)<0.);
}
