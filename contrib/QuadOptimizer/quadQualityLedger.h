// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
// See the LICENSE.txt file in the Gmsh root directory for license information.
#pragma once

#include "quadQuality.h"
#include <array>
#include <algorithm>
#include <cstdint>
#include <stdexcept>

namespace QuadOptimizer {
  // Exact model-wide populations, updated by subtracting C and adding its
  // replacement. No neighboring cells or whole-model rescore is necessary.
  struct QualityLedger {
    enum Criterion { Warping, EdgeRatio, QuadMinimumAngle, QuadMaximumAngle,
                     TriangleMinimumAngle, TriangleMaximumAngle, Skewing,
                     Count };
    struct Population {
      std::size_t elements = 0, preferredBad = 0, absoluteBad = 0;
      std::size_t deficit() const
      {
        // ceil(.99*N) passes <=> at most floor(N/100) failures. Integer
        // division avoids floating-point rounding and 100*N overflow.
        return preferredBad - std::min(preferredBad, elements / 100);
      }
    };
    std::array<Population, Count> criteria{};

    void add(const ElementQuality &q)
    {
      const auto record = [&](Criterion c, bool preferred, bool absolute) {
        auto &p = criteria[c];
        ++p.elements;
        p.preferredBad += !preferred;
        p.absoluteBad += !absolute;
      };
      record(EdgeRatio, q.edgeRatio < 5., q.edgeRatio < 10.);
      record(Skewing, q.skewingDegrees < 125., q.skewingDegrees < 160.);
      if(q.kind == SurfaceElementKind::Quadrangle) {
        record(Warping, q.warpingDegrees < 15., q.warpingDegrees < 25.);
        record(QuadMinimumAngle, q.minimumAngleDegrees > 45.,
               q.minimumAngleDegrees > 25.);
        record(QuadMaximumAngle, q.maximumAngleDegrees < 135.,
               q.maximumAngleDegrees < 160.);
      }
      else {
        record(TriangleMinimumAngle, q.minimumAngleDegrees > 20.,
               q.minimumAngleDegrees > 10.);
        record(TriangleMaximumAngle, q.maximumAngleDegrees < 120.,
               q.maximumAngleDegrees < 150.);
      }
    }

    QualityLedger replaced(const QualityLedger &removed,
                           const QualityLedger &added) const
    {
      QualityLedger result;
      for(std::size_t j = 0; j < Count; ++j) {
        const auto &p = criteria[j], &r = removed.criteria[j],
                   &a = added.criteria[j];
        if(p.elements < r.elements || p.preferredBad < r.preferredBad ||
           p.absoluteBad < r.absoluteBad)
          throw std::logic_error("V2 quality ledger does not contain cavity");
        result.criteria[j] = {p.elements - r.elements + a.elements,
          p.preferredBad - r.preferredBad + a.preferredBad,
          p.absoluteBad - r.absoluteBad + a.absoluteBad};
      }
      return result;
    }

    void add(const QualityLedger &other)
    {
      *this = replaced(QualityLedger{}, other);
    }

    bool absoluteNoWorseThan(const QualityLedger &other) const
    {
      for(std::size_t j = 0; j < Count; ++j)
        if(criteria[j].absoluteBad > other.criteria[j].absoluteBad)
          return false;
      return true;
    }

    std::array<std::size_t, 3> preferredDeficit() const
    {
      // First reach all seven quotas; then minimize the total and worst
      // number of elements still needed to reach those exact quotas.
      std::array<std::size_t, 3> result{};
      for(const auto &p : criteria) {
        const std::size_t d = p.deficit();
        result[0] += d != 0;
        result[1] += d;
        result[2] = std::max(result[2], d);
      }
      return result;
    }

    std::uint64_t state() const
    {
      std::uint64_t hash = 1469598103934665603ull;
      for(const auto &p : criteria)
        for(const std::size_t v : {p.elements, p.preferredBad, p.absoluteBad}) {
          hash ^= static_cast<std::uint64_t>(v);
          hash *= 1099511628211ull;
        }
      return hash;
    }
  };
}
