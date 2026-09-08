// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
#pragma once
#include <algorithm>
#include <array>
#include <cmath>
#include <cstddef>

namespace QuadOptimizer { namespace SmartLaplacian {
  using Point = std::array<double, 3>;

  // Freitag (1997), minimum sine over every angle of the incident elements.
  // Surface adaptation: physical edge vectors; reflex quad corners are signed
  // against the element's Newell normal. CAD orientation is checked separately.
  inline double minimumCornerSine(const std::array<Point, 4> &p,
                                  std::size_t count)
  {
    if(count != 3 && count != 4) return -1.;
    const auto sub = [](const Point &a, const Point &b) {
      return Point{{a[0]-b[0], a[1]-b[1], a[2]-b[2]}};
    };
    const auto cross = [](const Point &a, const Point &b) {
      return Point{{a[1]*b[2]-a[2]*b[1], a[2]*b[0]-a[0]*b[2],
                    a[0]*b[1]-a[1]*b[0]}};
    };
    const auto dot = [](const Point &a, const Point &b) {
      return a[0]*b[0]+a[1]*b[1]+a[2]*b[2];
    };
    // Normalize offsets to avoid overflow/underflow at model length scales.
    std::array<Point, 4> v;
    double scale = 0.;
    for(std::size_t i=0;i<count;++i) {
      v[i]=sub(p[i],p[0]);
      for(double x:v[i]) {
        if(!std::isfinite(x)) return -1.;
        scale=std::max(scale,std::abs(x));
      }
    }
    if(!(scale>0.)) return -1.;
    for(std::size_t i=0;i<count;++i)
      for(double &x:v[i]) x/=scale;
    Point normal{{0.,0.,0.}};
    for(std::size_t i=0;i<count;++i) {
      const Point n=cross(v[i],v[(i+1)%count]);
      for(int k=0;k<3;++k) normal[k]+=n[k];
    }
    if(!(dot(normal,normal)>0.)) return -1.;
    double result=1.;
    for(std::size_t i=0;i<count;++i) {
      const Point a=sub(v[(i+1)%count],v[i]);
      const Point b=sub(v[(i+count-1)%count],v[i]);
      const double denominator=dot(a,a)*dot(b,b);
      if(!(denominator>0.)) return -1.;
      const Point n=cross(a,b);
      double sine=std::sqrt(std::min(1.,dot(n,n)/denominator));
      if(dot(n,normal)<0.) sine=-sine;
      result=std::min(result,sine);
    }
    return result;
  }
} }
