// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
// Shared physical orientation predicate used by V2 and the final mesh audit.
#pragma once
#include <algorithm>
#include <array>
#include <cmath>
#include <limits>
#include <vector>
namespace QuadOptimizer { namespace GeometryGuard {
using UV = std::array<double, 2>;
using Point = std::array<double, 3>;
template<std::size_t N>
inline double localOrientationDistance2(const std::array<double,N>&a,
                                        const std::array<double,N>&b) {
  double d=0.; for(std::size_t i=0;i<N;++i) d+=(a[i]-b[i])*(a[i]-b[i]); return d;
}
inline Point localOrientationNormal(const Point&a,const Point&b,const Point&c) {
  const Point u={{b[0]-a[0],b[1]-a[1],b[2]-a[2]}},v={{c[0]-a[0],c[1]-a[1],c[2]-a[2]}};
  return {{u[1]*v[2]-u[2]*v[1],u[2]*v[0]-u[0]*v[2],u[0]*v[1]-u[1]*v[0]}};
}
inline double localOrientationNorm(const Point&a) { return std::sqrt(a[0]*a[0]+a[1]*a[1]+a[2]*a[2]); }
inline double localOrientationCross2(const UV&a,const UV&b,const UV&c) {
 return (b[0]-a[0])*(c[1]-a[1])-(b[1]-a[1])*(c[0]-a[0]);
}
    template <class TriangleRange, class QuadrangleRange, class NormalAt>
    bool indexedPatchFollowsNormals(
      NormalAt &&normalAt, const std::vector<UV> &uv,
      const std::vector<Point> &xyz, const TriangleRange &triangles,
      const QuadrangleRange &quadrangles, int requiredSign = 1,
      bool allowUnevaluableSamples = false)
    {
      if(uv.size() != xyz.size()) return false;
      if(requiredSign != 1 && requiredSign != -1) return false;
      bool foundOpposedSample = false;
      auto acceptSample = [&](int sign, bool &foundPositiveSample) {
        // A discrete-face support triangle can end before an interpolated UV
        // sample even though the candidate remains meaningful at its other
        // samples. Such an unevaluable query abstains. One reliable sample
        // that is opposed or non-positive within tolerance is nevertheless
        // sufficient to reject the element.
        if(sign < 0) {
          foundOpposedSample = true;
          return requiredSign < 0;
        }
        if(sign > 0) foundPositiveSample = true;
        return true;
      };

      // The physical Jacobian of a linear triangle is constant, but the
      // discrete-face normal is piecewise constant on its support mesh.
      // Sample the centroid and three near-corner interior points so a single
      // favorable support triangle cannot hide an opposed region.
      static const double triangleWeights[4][3] = {
        {1. / 3., 1. / 3., 1. / 3.},
        {.98, .01, .01}, {.01, .98, .01}, {.01, .01, .98}};
      for(const auto &triangle : triangles) {
        if(triangle.size() != 3) return false;
        bool foundPositiveSample = false;
        for(const std::size_t vertex : triangle)
          if(vertex >= uv.size()) return false;
        const Point &a = xyz[triangle[0]];
        const Point &b = xyz[triangle[1]];
        const Point &c = xyz[triangle[2]];
        Point jacobian = localOrientationNormal(a, b, c);
        const double jacobianNorm = localOrientationNorm(jacobian);
        const double physicalScale2 = std::max(
          {localOrientationDistance2(a, b),
           localOrientationDistance2(b, c),
           localOrientationDistance2(c, a)});
        const double uvScale2 = std::max(
          {localOrientationDistance2(uv[triangle[0]], uv[triangle[1]]),
           localOrientationDistance2(uv[triangle[1]], uv[triangle[2]]),
           localOrientationDistance2(uv[triangle[2]], uv[triangle[0]])});
        const double uvJacobian = localOrientationCross2(
          uv[triangle[0]], uv[triangle[1]], uv[triangle[2]]);
        if(!std::isfinite(uvScale2) || !(uvScale2 > 0.) ||
           !std::isfinite(uvJacobian) ||
           std::abs(uvJacobian) <= 1.e-12 * uvScale2)
          return false;
        for(const auto &weight : triangleWeights) {
          UV parameter = {0., 0.};
          for(std::size_t i = 0; i < 3; ++i)
            for(std::size_t coordinate = 0; coordinate < 2; ++coordinate)
              parameter[coordinate] +=
                weight[i] * uv[triangle[i]][coordinate];
          if(!acceptSample(normalAt( parameter, jacobian, jacobianNorm, physicalScale2),
               foundPositiveSample))
            return false;
        }
        if(requiredSign > 0 && !foundPositiveSample &&
           !allowUnevaluableSamples)
          return false;
      }

      // Bilinear quadrangles can fold at a corner while retaining a plausible
      // Newell or center normal. Evaluate dX/dxi x dX/deta at the 2x2 Gauss
      // points and at four near-corner limits. The same shape functions
      // interpolate a coherent candidate UV for the GFace query.
      constexpr double gauss = 0.57735026918962576451;
      constexpr double corner = 1. - 1.e-6;
      static const UV quadrangleSamples[8] = {
        {-gauss, -gauss}, {gauss, -gauss},
        {gauss, gauss}, {-gauss, gauss},
        {-corner, -corner}, {corner, -corner},
        {corner, corner}, {-corner, corner}};
      for(const auto &quadrangle : quadrangles) {
        if(quadrangle.size() != 4) return false;
        bool foundPositiveSample = false;
        for(const std::size_t vertex : quadrangle)
          if(vertex >= uv.size()) return false;
        double physicalScale2 = 0.;
        double uvScale2 = 0.;
        for(std::size_t i = 0; i < 4; ++i)
          for(std::size_t j = i + 1; j < 4; ++j) {
            physicalScale2 = std::max(
              physicalScale2,
              localOrientationDistance2(
                xyz[quadrangle[i]], xyz[quadrangle[j]]));
            uvScale2 = std::max(
              uvScale2,
              localOrientationDistance2(
                uv[quadrangle[i]], uv[quadrangle[j]]));
          }
        if(!(physicalScale2 > 0.) || !std::isfinite(physicalScale2))
          return false;
        if(!(uvScale2 > 0.) || !std::isfinite(uvScale2)) return false;

        for(const UV &sample : quadrangleSamples) {
          const double xi = sample[0];
          const double eta = sample[1];
          const double shape[4] = {
            .25 * (1. - xi) * (1. - eta),
            .25 * (1. + xi) * (1. - eta),
            .25 * (1. + xi) * (1. + eta),
            .25 * (1. - xi) * (1. + eta)};
          const double dShapeDxi[4] = {
            -.25 * (1. - eta), .25 * (1. - eta),
             .25 * (1. + eta), -.25 * (1. + eta)};
          const double dShapeDeta[4] = {
            -.25 * (1. - xi), -.25 * (1. + xi),
             .25 * (1. + xi), .25 * (1. - xi)};
          UV parameter = {0., 0.};
          UV dUdxi = {0., 0.};
          UV dUdeta = {0., 0.};
          Point dXdxi = {0., 0., 0.};
          Point dXdeta = {0., 0., 0.};
          for(std::size_t i = 0; i < 4; ++i) {
            const std::size_t vertex = quadrangle[i];
            for(std::size_t coordinate = 0; coordinate < 2; ++coordinate)
            {
              parameter[coordinate] += shape[i] * uv[vertex][coordinate];
              dUdxi[coordinate] +=
                dShapeDxi[i] * uv[vertex][coordinate];
              dUdeta[coordinate] +=
                dShapeDeta[i] * uv[vertex][coordinate];
            }
            for(std::size_t coordinate = 0; coordinate < 3; ++coordinate) {
              dXdxi[coordinate] +=
                dShapeDxi[i] * xyz[vertex][coordinate];
              dXdeta[coordinate] +=
                dShapeDeta[i] * xyz[vertex][coordinate];
            }
          }
          Point jacobian = {
            dXdxi[1] * dXdeta[2] - dXdxi[2] * dXdeta[1],
            dXdxi[2] * dXdeta[0] - dXdxi[0] * dXdeta[2],
            dXdxi[0] * dXdeta[1] - dXdxi[1] * dXdeta[0]};
          const double jacobianNorm = localOrientationNorm(jacobian);
          const double uvJacobian =
            dUdxi[0] * dUdeta[1] - dUdxi[1] * dUdeta[0];
          const int sign = std::isfinite(uvJacobian) &&
              std::abs(uvJacobian) > 1.e-12 * uvScale2 ?
            normalAt( parameter, jacobian, jacobianNorm, physicalScale2) : 0;
          if(!acceptSample(sign, foundPositiveSample))
            return false;
        }
        if(requiredSign > 0 && !foundPositiveSample &&
           !allowUnevaluableSamples)
          return false;
      }
      return requiredSign > 0 || foundOpposedSample;
    }

}} // namespace QuadOptimizer::GeometryGuard
