// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.

#ifndef HALF_EDGE_REWRITES_H
#define HALF_EDGE_REWRITES_H

#include "halfEdgeMesh.h"

#include <algorithm>
#include <array>
#include <cstddef>
#include <utility>
#include <vector>

namespace QuadOptimizer {
  namespace HalfEdgeRewrite {

    inline bool matchesCyclicFacePattern(
      const std::vector<HalfEdgeMesh::Index> &observed,
      const std::vector<HalfEdgeMesh::Index> &pattern)
    {
      if(observed.empty() || observed.size() != pattern.size()) return false;
      const std::size_t count = observed.size();
      for(std::size_t rotation = 0; rotation < count; ++rotation) {
        bool direct = true;
        bool reflected = true;
        for(std::size_t i = 0; i < count; ++i) {
          direct = direct &&
            observed[i] == pattern[(rotation + i) % count];
          reflected = reflected &&
            observed[i] == pattern[(rotation + count - i) % count];
        }
        if(direct || reflected) return true;
      }
      return false;
    }

    // A strip filling is identified by its unordered cell-corner sets.
    template <class Connectivity>
    inline Connectivity canonicalConnectivity(Connectivity connectivity)
    {
      for(auto &face : connectivity)
        std::sort(face.begin(), face.end());
      std::sort(connectivity.begin(), connectivity.end());
      return connectivity;
    }

    using QuadConnectivity =
      std::vector<std::array<std::size_t, 4> >;

    // All quadrangulations of an even polygon, rooted at its last-to-first
    // boundary edge.  The root quadrangle splits the polygon into three even
    // sub-polygons (an edge is the empty base case), so every non-crossing
    // quadrangulation is produced exactly once.  This is the quadrangular
    // analogue of the standard Catalan recurrence.
    inline std::vector<QuadConnectivity> evenPolygonQuadrangulations(
      const std::vector<std::size_t> &polygon)
    {
      if(polygon.size() == 2) return {QuadConnectivity()};
      if(polygon.size() < 4 || polygon.size() % 2) return {};

      std::vector<QuadConnectivity> result;
      const std::size_t last = polygon.size() - 1;
      // Every interval cut off by {0, first, second, last} must contain an
      // even number of polygon vertices.  Hence the index gaps are odd.
      for(std::size_t first = 1; first + 2 <= last; first += 2) {
        for(std::size_t second = first + 1;
            second + 1 <= last; second += 2) {
          const std::vector<std::size_t> left(
            polygon.begin(), polygon.begin() + first + 1);
          const std::vector<std::size_t> middle(
            polygon.begin() + first, polygon.begin() + second + 1);
          const std::vector<std::size_t> right(
            polygon.begin() + second, polygon.end());
          const std::vector<QuadConnectivity> leftFillings =
            evenPolygonQuadrangulations(left);
          const std::vector<QuadConnectivity> middleFillings =
            evenPolygonQuadrangulations(middle);
          const std::vector<QuadConnectivity> rightFillings =
            evenPolygonQuadrangulations(right);
          for(const QuadConnectivity &leftFilling : leftFillings)
            for(const QuadConnectivity &middleFilling : middleFillings)
              for(const QuadConnectivity &rightFilling : rightFillings) {
                QuadConnectivity filling;
                filling.reserve(leftFilling.size() + middleFilling.size() +
                                rightFilling.size() + 1);
                filling.insert(filling.end(), leftFilling.begin(),
                               leftFilling.end());
                filling.insert(filling.end(), middleFilling.begin(),
                               middleFilling.end());
                filling.insert(filling.end(), rightFilling.begin(),
                               rightFilling.end());
                filling.push_back({polygon.front(), polygon[first],
                                   polygon[second], polygon.back()});
                result.push_back(std::move(filling));
              }
        }
      }
      return result;
    }

    // The two bounded "zipper" rewrites of a T-Q^k-T strip.  They propagate
    // either end triangle through the strip and finish with TT -> Q, instead
    // of enumerating every quadrangulation of the surrounding polygon.  If
    // the rails are a[0..n] and b[0..n], with common endpoints, the two
    // candidates are
    //
    //   (a[j], a[j+1], b[j+2], b[j+1])  and
    //   (b[j], b[j+1], a[j+2], a[j+1]),
    //
    // for j=0..n-2.  For k=0 these have identical connectivity and are
    // returned only once.  Sorting by the canonical connectivity makes the
    // candidate order deterministic without discarding the oriented faces.
    inline std::vector<QuadConnectivity>
    triangleQuadStripZipperReconnections(
      const std::vector<std::size_t> &firstRail,
      const std::vector<std::size_t> &secondRail)
    {
      if(firstRail.size() != secondRail.size() || firstRail.size() < 3 ||
         firstRail.front() != secondRail.front() ||
         firstRail.back() != secondRail.back())
        return {};

      // Apart from the two intentionally shared endpoints, every rail
      // vertex must be distinct.  This also rejects a collapsed rail edge
      // and coincident endpoints before a degenerate quadrangle is built.
      std::vector<std::size_t> boundary = firstRail;
      boundary.reserve(2 * firstRail.size() - 2);
      for(std::size_t i = secondRail.size() - 1; i-- > 1;)
        boundary.push_back(secondRail[i]);
      std::sort(boundary.begin(), boundary.end());
      if(std::adjacent_find(boundary.begin(), boundary.end()) !=
         boundary.end())
        return {};

      const auto zipper = [](const std::vector<std::size_t> &first,
                             const std::vector<std::size_t> &second) {
        QuadConnectivity candidate;
        candidate.reserve(first.size() - 2);
        for(std::size_t j = 0; j + 2 < first.size(); ++j)
          candidate.push_back(
            {{first[j], first[j + 1], second[j + 2], second[j + 1]}});
        return candidate;
      };

      std::vector<QuadConnectivity> result;
      result.reserve(2);
      result.push_back(zipper(firstRail, secondRail));
      QuadConnectivity opposite = zipper(secondRail, firstRail);
      if(canonicalConnectivity(opposite) !=
         canonicalConnectivity(result.front()))
        result.push_back(std::move(opposite));
      std::sort(result.begin(), result.end(),
                [](const QuadConnectivity &left,
                   const QuadConnectivity &right) {
                  return canonicalConnectivity(left) <
                    canonicalConnectivity(right);
                });
      return result;
    }

  } // namespace HalfEdgeRewrite
} // namespace QuadOptimizer

#endif
