#ifndef QUAD_CAD_DISTANCE_H
#define QUAD_CAD_DISTANCE_H

#include "GFace.h"
#include "MElement.h"
#include "MVertex.h"

#include <algorithm>
#include <array>
#include <cmath>
#include <cstddef>
#include <limits>
#include <map>
#include <vector>

namespace QuadOptimizer {
  namespace CadDistance {
    using Point = std::array<double, 3>;
    using UV = std::array<double, 2>;
    // One cache per geometric face, valid only while its support is unchanged.
    // Store successful squared physical distances, independently of local h.
    using DistanceCache = std::map<Point, double>;

    inline const char *metricId()
    {
      return "closest-point-center-edge-midpoints-area-local-h-v1";
    }

    struct Contribution {
      double squaredDistanceIntegral = 0.;
      double normalizedSquaredDistanceIntegral = 0.;
      double sampledArea = 0.;
      double maximumDistance = 0.;
      double maximumNormalizedDistance = 0.;
      std::size_t requestedSamples = 0, coveredSamples = 0;

      bool complete() const
      {
        return requestedSamples > 0 && requestedSamples == coveredSamples &&
          sampledArea > 0. && std::isfinite(sampledArea) &&
          std::isfinite(squaredDistanceIntegral) &&
          std::isfinite(normalizedSquaredDistanceIntegral) &&
          std::isfinite(maximumDistance) &&
          std::isfinite(maximumNormalizedDistance);
      }

      Contribution &operator+=(const Contribution &other)
      {
        squaredDistanceIntegral += other.squaredDistanceIntegral;
        normalizedSquaredDistanceIntegral +=
          other.normalizedSquaredDistanceIntegral;
        sampledArea += other.sampledArea;
        maximumDistance = std::max(maximumDistance, other.maximumDistance);
        maximumNormalizedDistance =
          std::max(maximumNormalizedDistance, other.maximumNormalizedDistance);
        requestedSamples += other.requestedSamples;
        coveredSamples += other.coveredSamples;
        return *this;
      }
    };

    inline bool vertexParameter(GFace *face, const MVertex *vertex, UV &result)
    {
      if(!face || !vertex) return false;
      double u = 0., v = 0.;
      if(vertex->onWhat() == face && vertex->getParameter(0, u) &&
         vertex->getParameter(1, v) && std::isfinite(u) && std::isfinite(v)) {
        result = {{u, v}};
        return true;
      }
      try {
        SPoint2 uv;
        if(face->geomType() == GEntity::DiscreteSurface)
          uv = face->parFromPoint(vertex->point(), true, true);
        else if(!reparamMeshVertexOnFace(vertex, face, uv, true, false))
          return false;
        result = {{uv.x(), uv.y()}};
        return std::isfinite(result[0]) && std::isfinite(result[1]);
      }
      catch(...) { return false; }
    }

    inline void unwrapParameters(GFace *face, std::vector<UV> &parameters)
    {
      if(!face || parameters.empty()) return;
      for(int direction = 0; direction < 2; ++direction) {
        if(!face->periodic(direction)) continue;
        const double period = std::abs(face->period(direction));
        if(!(period > 0.) || !std::isfinite(period)) continue;
        const double reference = parameters.front()[direction];
        for(UV &uv : parameters)
          uv[direction] +=
            std::round((reference - uv[direction]) / period) * period;
      }
    }

    inline bool elementParameters(GFace *face, MElement *element,
                                  std::vector<UV> &parameters)
    {
      parameters.clear();
      if(!face || !element) return false;
      parameters.resize(element->getNumPrimaryVertices());
      for(std::size_t i = 0; i < parameters.size(); ++i) {
        if(!vertexParameter(face, element->getVertex(static_cast<int>(i)),
                            parameters[i])) {
          parameters.clear();
          return false;
        }
      }
      unwrapParameters(face, parameters);
      return true;
    }

    // Sample the physical linear element, then project to its geometric face.
    // The centre and every edge midpoint have equal area weights. These are
    // finite samples, not a Hausdorff bound. UV supplies only a projection guess.
    // Failed requests remain visible; partial support is never called complete.
    template <class TargetAt>
    Contribution sampleElement(GFace *face, MElement *element,
                               const std::vector<UV> &parameters,
                               TargetAt targetAt,
                               DistanceCache *cache = nullptr)
    {
      Contribution result;
      const std::size_t count = element ? element->getNumPrimaryVertices() : 0;
      result.requestedSamples = count + 1;
      if(!face || !element || (count != 3 && count != 4) ||
         parameters.size() != count)
        return result;
      std::vector<Point> vertices(count);
      for(std::size_t i = 0; i < count; ++i) {
        const MVertex *vertex = element->getVertex(static_cast<int>(i));
        if(!vertex) return result;
        vertices[i] = {{vertex->x(), vertex->y(), vertex->z()}};
        for(double coordinate : vertices[i])
          if(!std::isfinite(coordinate)) return result;
        for(double coordinate : parameters[i])
          if(!std::isfinite(coordinate)) return result;
      }
      double area = 0.;
      for(std::size_t i = 1; i + 1 < count; ++i) {
        Point a, b;
        for(int d = 0; d < 3; ++d) {
          a[d] = vertices[i][d] - vertices[0][d];
          b[d] = vertices[i + 1][d] - vertices[0][d];
        }
        const Point cross = {{a[1] * b[2] - a[2] * b[1],
                              a[2] * b[0] - a[0] * b[2],
                              a[0] * b[1] - a[1] * b[0]}};
        area += .5 * std::hypot(cross[0], cross[1], cross[2]);
      }
      if(!(area > 0.) || !std::isfinite(area)) return result;
      const double sampleWeight = area / result.requestedSamples;
      for(std::size_t sample = 0; sample < result.requestedSamples; ++sample) {
        Point linear = {{0., 0., 0.}};
        UV uv = {{0., 0.}};
        for(std::size_t i = 0; i < count; ++i) {
          const double weight = sample == 0 ? 1. / count :
            (i == sample - 1 || i == sample % count ? .5 : 0.);
          for(int d = 0; d < 3; ++d) linear[d] += weight * vertices[i][d];
          for(int d = 0; d < 2; ++d) uv[d] += weight * parameters[i][d];
        }
        double h = 0.;
        try { h = targetAt(linear, uv); }
        catch(...) { continue; }
        if(!(h > 0.) || !std::isfinite(h)) continue;
        double distance2 = std::numeric_limits<double>::infinity();
        const auto found = cache ? cache->find(linear) :
          DistanceCache::const_iterator();
        if(cache && found != cache->end()) distance2 = found->second;
        else {
          try {
            const GPoint projected = face->closestPointFromTrustedGuess(
              SPoint3(linear[0], linear[1], linear[2]), uv.data());
            if(projected.succeeded()) {
              const double dx = projected.x() - linear[0];
              const double dy = projected.y() - linear[1];
              const double dz = projected.z() - linear[2];
              distance2 = dx * dx + dy * dy + dz * dz;
            }
          }
          catch(...) {}
          if(cache && distance2 >= 0. && std::isfinite(distance2))
            cache->emplace(linear, distance2);
        }
        if(!(distance2 >= 0.) || !std::isfinite(distance2)) continue;
        const double distance = std::sqrt(distance2);
        const double normalized = distance / h;
        const double weightedSquared = sampleWeight * distance2;
        const double weightedNormalized = sampleWeight * normalized * normalized;
        if(!std::isfinite(weightedSquared) ||
           !std::isfinite(weightedNormalized)) continue;
        result.squaredDistanceIntegral += weightedSquared;
        result.normalizedSquaredDistanceIntegral += weightedNormalized;
        result.sampledArea += sampleWeight;
        result.maximumDistance = std::max(result.maximumDistance, distance);
        result.maximumNormalizedDistance =
          std::max(result.maximumNormalizedDistance, normalized);
        ++result.coveredSamples;
      }
      return result;
    }
  } // namespace CadDistance
} // namespace QuadOptimizer

#endif
