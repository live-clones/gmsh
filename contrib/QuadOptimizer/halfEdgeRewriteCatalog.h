// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.

#ifndef HALF_EDGE_REWRITE_CATALOG_H
#define HALF_EDGE_REWRITE_CATALOG_H

#include "halfEdgeMesh.h"

#include <algorithm>
#include <array>
#include <cstddef>
#include <utility>
#include <vector>

namespace QuadOptimizer {
  namespace HalfEdgeRewrite {

    enum class Family {
      Connectivity,
      Boundary,
      Shape,
      Size,
      Mixed,
      Validity
    };

    enum class Schedule { CleanUp, PostProcess, Terminal, FinalFallback };

    enum class Symmetry {
      // Try every rotation and every reflected rotation of a disk boundary.
      Dihedral,
      // The oriented half-edge boundary supplies the side of the domain;
      // only cyclic changes of root preserve that orientation.
      BoundaryOriented
    };

    // Every rule declares how its core C is discovered in the persistent
    // half-edge mesh. Policies may enlarge C afterwards, but they all use the
    // same numeric Cavity representation.
    enum class Anchor {
      Vertex,
      Edge,
      SingleQuadrangle,
      VertexSet,
      BoundaryLoop
    };

    enum class Kind {
      // Replace the complete interior B=4, I=1 star made of two triangles
      // and one quadrangle by its boundary quadrangle. The center vertex is
      // retired and the triangle count decreases by two.
      InteriorTriangleTriangleQuadReduction,
      // Replace the complete interior B=4, I=1 four-triangle fan by its
      // boundary quadrangle. The center is retired and four triangles are
      // removed in one atomic rewrite.
      InteriorFourTriangleFanReduction,
      // Replace the complete interior B=6, I=1 alternating Q-T-Q-T star by
      // the best of the three two-quadrangle fillings of its boundary
      // hexagon. The center and both triangles are removed atomically.
      InteriorAlternatingQuadTriangleReduction,
      // Replace a disk formed by two triangles joined by a simple path of
      // zero or more quadrangles by an all-quad disk.  One descriptor covers
      // T+T, T-Q-T, T-Q-Q-T, ... and all their dihedral images.
      TriangleQuadStripReduction,
      // Reconfigure the complete B=6, I=0 mixed disk formed by a quadrangle
      // and two triangles on opposite quadrangle edges. All 21 labelled
      // 1Q+2T dissections are represented by three D6 orbits.
      OppositeEdgeTriangleQuadSwap,
      // Fallback for T-Q-T with the triangles attached to opposite edges of
      // the quadrangle. Insert one Winslow-positioned face vertex and replace
      // the six-vertex disk by three quadrangles.
      OppositeEdgeTriangleQuadFan,
      // Flip the diagonal of a two-triangle disk. This deliberately precedes
      // TriangleQuadStripReduction in the CleanUp schedule: the same pass can
      // therefore consume a newly improved k=0 strip as a quadrangle.
      TriangleTriangleSwap,
      // Replace the complete six-face interior star T-Q-Q-T-Q-Q by the
      // B=10, I=2 all-quad disk. The two triangles are opposite in the
      // cyclic star; every rotation and reflection is handled by D10.
      InteriorQQTQQTReduction,
      MixedTriangleQuadSwap,
      QuadQuadSwap,
      ValenceSixSplit,
      ConnectivityDisk,
      OneVertexDisk,
      DiamondCollapse,
      BoundaryDisk,
      BoundaryTriangleQuadFan,
      ThreeVertexDisk,
      FourVertexDisk,
      ShapeDisk,
      SizeDisk,
      PillowHole,
      // Repair a reliably GFace-opposed residual quadrangle by opening the
      // complete half-edge stars of its movable vertices and applying mixed
      // Winslow smoothing before any quality decision.
      OpposedQuadStarSmoothing,
      InvalidQuadSplit,
      TerminalTrianglePairRecombination,
      CatastrophicAngleQuadSplit
    };

    struct Descriptor {
      const char *id;
      Kind kind;
      Family family;
      Schedule schedule;
      Symmetry symmetry;
      Anchor anchor;
    };

    // The catalog anchor is an executable contract, not documentation.  A
    // matcher may construct temporary/support cavities while searching, but
    // the core C that it submits to a rewrite must carry the anchor declared
    // by its descriptor.  Boundary loops are not face disks and consequently
    // have their own explicit check below.
    inline bool cavityMatchesAnchor(
      Anchor declared, const HalfEdgeMesh::Cavity &cavity)
    {
      using HalfEdgeMesh::CavityAnchor;
      using HalfEdgeMesh::invalid;
      // Matchers submit C here, never its enlarged smoothing support C+C'.
      if(cavity.coreFaces.empty() || cavity.faces != cavity.coreFaces)
        return false;
      switch(declared) {
      case Anchor::Vertex:
        return cavity.anchor == CavityAnchor::Vertex &&
               cavity.anchorVertices.size() == 1 &&
               !cavity.anchorFaces.empty() &&
               cavity.anchorFirst == cavity.anchorVertices.front() &&
               cavity.anchorFirst != invalid;
      case Anchor::Edge:
        return cavity.anchor == CavityAnchor::Edge &&
               cavity.anchorVertices.size() == 2 &&
               cavity.anchorFaces.size() == 2 &&
               cavity.anchorFirst == cavity.anchorVertices[0] &&
               cavity.anchorSecond == cavity.anchorVertices[1] &&
               cavity.anchorFirst != invalid &&
               cavity.anchorSecond != invalid &&
               cavity.anchorOnBoundary == 0;
      case Anchor::SingleQuadrangle:
        return cavity.anchor == CavityAnchor::SingleQuadrangle &&
               cavity.anchorFirst != invalid &&
               cavity.anchorFaces ==
                 std::vector<HalfEdgeMesh::Index>{cavity.anchorFirst};
      case Anchor::VertexSet:
        return cavity.anchor == CavityAnchor::VertexSet &&
               cavity.anchorVertices.size() > 1 &&
               cavity.anchorFirst == cavity.anchorVertices.front() &&
               cavity.anchorFirst != invalid;
      case Anchor::BoundaryLoop: return false;
      }
      return false;
    }

    class AnchorContract {
      const Descriptor *_descriptor = nullptr;
      bool _checked = false;
      bool _accepted = false;
      bool _violated = false;

    public:
      bool begin(const Descriptor &descriptor)
      {
        if(_descriptor) return false;
        _descriptor = &descriptor;
        _checked = false;
        _accepted = false;
        _violated = false;
        return true;
      }

      bool accepts(const HalfEdgeMesh::Cavity &cavity)
      {
        if(!_descriptor) return true;
        _checked = true;
        const bool accepted = cavityMatchesAnchor(
          _descriptor->anchor, cavity);
        _accepted = _accepted || accepted;
        _violated = _violated || !accepted;
        return accepted;
      }

      bool acceptsBoundaryLoop(std::size_t vertexCount)
      {
        if(!_descriptor) return true;
        _checked = true;
        const bool accepted =
          _descriptor->anchor == Anchor::BoundaryLoop && vertexCount >= 3;
        _accepted = _accepted || accepted;
        _violated = _violated || !accepted;
        return accepted;
      }

      bool checked() const { return _checked; }
      bool violated() const { return _violated; }

      bool finish(bool requireAcceptedAnchor = false)
      {
        const bool accepted = _descriptor && !_violated &&
          (!requireAcceptedAnchor || _accepted);
        _descriptor = nullptr;
        _checked = false;
        _accepted = false;
        _violated = false;
        return accepted;
      }
    };

    using MixedConnectivity =
      std::vector<std::vector<std::size_t> >;

    // Complete source data for the opposite-edge T-Q-T mixed rewrite. These
    // three representatives generate all 21 labelled planar 1Q+2T fillings
    // of a six-vertex disk under D6 (orbit sizes 6, 3 and 12).
    inline const std::array<MixedConnectivity, 3> &
    oppositeEdgeTriangleQuadSwapRepresentatives()
    {
      static const std::array<MixedConnectivity, 3> representatives = {{
        MixedConnectivity{{0, 1, 2}, {2, 3, 4}, {0, 2, 4, 5}},
        MixedConnectivity{{0, 1, 2}, {0, 2, 3, 5}, {3, 4, 5}},
        MixedConnectivity{{0, 1, 2}, {0, 2, 3}, {0, 3, 4, 5}}
      }};
      return representatives;
    }

    inline const std::array<Descriptor, 25> &catalog()
    {
      static const std::array<Descriptor, 25> rules = {{
        {"interior_ttq_to_q", Kind::InteriorTriangleTriangleQuadReduction,
         Family::Mixed, Schedule::CleanUp, Symmetry::Dihedral,
         Anchor::Vertex},
        {"interior_tttt_to_q", Kind::InteriorFourTriangleFanReduction,
         Family::Mixed, Schedule::CleanUp, Symmetry::Dihedral,
         Anchor::Vertex},
        {"interior_qtqt_to_2q",
         Kind::InteriorAlternatingQuadTriangleReduction,
         Family::Mixed, Schedule::CleanUp, Symmetry::Dihedral,
         Anchor::Vertex},
        {"interior_qqtqqt_to_6q", Kind::InteriorQQTQQTReduction,
         Family::Mixed, Schedule::CleanUp, Symmetry::Dihedral,
         Anchor::Vertex},
        {"triangle_triangle_swap", Kind::TriangleTriangleSwap,
         Family::Mixed, Schedule::CleanUp, Symmetry::Dihedral,
         Anchor::Edge},
        {"triangle_quad_strip_reduce", Kind::TriangleQuadStripReduction,
         Family::Mixed, Schedule::CleanUp, Symmetry::Dihedral,
         Anchor::Edge},
        {"opposite_edge_tqt_mixed_swap",
         Kind::OppositeEdgeTriangleQuadSwap, Family::Mixed,
         Schedule::CleanUp, Symmetry::Dihedral, Anchor::Edge},
        {"opposite_edge_tqt_to_3q", Kind::OppositeEdgeTriangleQuadFan,
         Family::Mixed, Schedule::CleanUp, Symmetry::Dihedral,
         Anchor::Edge},
        {"mixed_tq_swap", Kind::MixedTriangleQuadSwap, Family::Mixed,
         Schedule::CleanUp, Symmetry::Dihedral, Anchor::Edge},
        {"quad_quad_swap", Kind::QuadQuadSwap, Family::Connectivity,
         Schedule::CleanUp, Symmetry::Dihedral, Anchor::Edge},
        {"valence6_split", Kind::ValenceSixSplit, Family::Connectivity,
         Schedule::CleanUp, Symmetry::Dihedral, Anchor::Vertex},
        {"disk_connectivity", Kind::ConnectivityDisk, Family::Connectivity,
         Schedule::CleanUp, Symmetry::Dihedral, Anchor::Vertex},
        {"one_vertex_disk", Kind::OneVertexDisk, Family::Connectivity,
         Schedule::CleanUp, Symmetry::Dihedral, Anchor::Vertex},
        {"diamond_collapse", Kind::DiamondCollapse, Family::Connectivity,
         Schedule::CleanUp, Symmetry::Dihedral,
         Anchor::SingleQuadrangle},
        {"disk_boundary", Kind::BoundaryDisk, Family::Boundary,
         Schedule::CleanUp, Symmetry::Dihedral, Anchor::Vertex},
        {"boundary_t_qn_t", Kind::BoundaryTriangleQuadFan,
         Family::Boundary, Schedule::CleanUp,
         Symmetry::Dihedral, Anchor::Vertex},
        {"three_vertex_disk", Kind::ThreeVertexDisk, Family::Shape,
         Schedule::CleanUp, Symmetry::Dihedral, Anchor::VertexSet},
        {"four_vertex_disk", Kind::FourVertexDisk, Family::Shape,
         Schedule::CleanUp, Symmetry::Dihedral, Anchor::VertexSet},
        {"disk_shape", Kind::ShapeDisk, Family::Shape,
         Schedule::CleanUp, Symmetry::Dihedral,
         Anchor::SingleQuadrangle},
        {"disk_size", Kind::SizeDisk, Family::Size,
         Schedule::CleanUp, Symmetry::Dihedral, Anchor::Edge},
        {"pillow_hole", Kind::PillowHole, Family::Boundary,
         Schedule::PostProcess, Symmetry::BoundaryOriented,
         Anchor::BoundaryLoop},
        {"opposed_quad_star_smoothing", Kind::OpposedQuadStarSmoothing,
         Family::Validity, Schedule::Terminal, Symmetry::Dihedral,
         Anchor::SingleQuadrangle},
        {"invalid_quad_split", Kind::InvalidQuadSplit, Family::Validity,
         Schedule::Terminal, Symmetry::Dihedral,
         Anchor::SingleQuadrangle},
        {"terminal_triangle_pair_recombination",
         Kind::TerminalTrianglePairRecombination, Family::Mixed,
         Schedule::Terminal, Symmetry::Dihedral, Anchor::Edge},
        // This catastrophic-angle fallback remains a one-shot last-resort
        // split. Two mixed Winslow/swap passes and the acyclic all-quad
        // reducers run afterwards, but no unrestricted cleanup search is
        // restarted.
        {"catastrophic_angle_quad_split", Kind::CatastrophicAngleQuadSplit,
         Family::Validity, Schedule::FinalFallback, Symmetry::Dihedral,
         Anchor::SingleQuadrangle}
      }};
      return rules;
    }

    inline std::size_t actionCount(Symmetry symmetry,
                                   std::size_t boundaryCount)
    {
      return symmetry == Symmetry::Dihedral ? 2 * boundaryCount :
                                               boundaryCount;
    }

    inline std::size_t actionRotation(Symmetry,
                                      std::size_t boundaryCount,
                                      std::size_t action)
    {
      return boundaryCount ? action % boundaryCount : 0;
    }

    inline bool actionReflected(Symmetry symmetry,
                                std::size_t boundaryCount,
                                std::size_t action)
    {
      return symmetry == Symmetry::Dihedral && boundaryCount &&
             action >= boundaryCount;
    }

    // Match a vertex-star cell pattern (3=T, 4=Q) independently of the root
    // and orientation chosen for the numeric half-edge ring.
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

    // Boundary stars are open chains: reflection is allowed, cyclic shifts
    // are not because the two endpoints lie on the geometric boundary.
    inline bool matchesBoundaryFacePattern(
      const std::vector<HalfEdgeMesh::Index> &observed,
      const std::vector<HalfEdgeMesh::Index> &pattern)
    {
      if(observed.size() != pattern.size()) return false;
      return observed == pattern ||
        std::equal(observed.begin(), observed.end(), pattern.rbegin());
    }

    inline std::size_t transformBoundaryVertex(
      Symmetry symmetry, std::size_t boundaryCount,
      std::size_t action, std::size_t vertex)
    {
      if(vertex >= boundaryCount || boundaryCount == 0) return vertex;
      const std::size_t rotation =
        actionRotation(symmetry, boundaryCount, action);
      return actionReflected(symmetry, boundaryCount, action) ?
        (rotation + boundaryCount - vertex) % boundaryCount :
        (rotation + vertex) % boundaryCount;
    }

    template <class Face>
    inline Face transformFace(Symmetry symmetry,
                              std::size_t boundaryCount,
                              std::size_t action, const Face &face)
    {
      Face transformed = face;
      for(std::size_t &vertex : transformed)
        vertex = transformBoundaryVertex(
          symmetry, boundaryCount, action, vertex);
      if(actionReflected(symmetry, boundaryCount, action))
        std::reverse(transformed.begin(), transformed.end());
      return transformed;
    }

    // Connectivity is independent of the root and orientation chosen for
    // each face.  This canonical key is shared by production ranking and the
    // catalog tests so stabilizer images cannot consume several candidate
    // slots before the configured top-K budget is applied.
    template <class Connectivity>
    inline Connectivity canonicalConnectivity(Connectivity connectivity)
    {
      for(auto &face : connectivity)
        std::sort(face.begin(), face.end());
      std::sort(connectivity.begin(), connectivity.end());
      return connectivity;
    }

    // Interior vertices of an abstract rewrite have no persistent identity.
    // Quotient their labels as well as face roots/orientations. The production
    // optimizer bounds these vertices to four, hence at most 4! relabelings.
    template <class Connectivity>
    inline Connectivity canonicalConnectivityIgnoringInteriorLabels(
      const Connectivity &connectivity, std::size_t boundaryCount)
    {
      std::vector<std::size_t> interiorLabels;
      for(const auto &face : connectivity)
        for(const std::size_t vertex : face)
          if(vertex >= boundaryCount)
            interiorLabels.push_back(vertex);
      std::sort(interiorLabels.begin(), interiorLabels.end());
      interiorLabels.erase(
        std::unique(interiorLabels.begin(), interiorLabels.end()),
        interiorLabels.end());
      if(interiorLabels.empty()) return canonicalConnectivity(connectivity);

      std::vector<std::size_t> relabeling(interiorLabels.size());
      for(std::size_t i = 0; i < relabeling.size(); ++i)
        relabeling[i] = i;
      Connectivity best;
      bool hasBest = false;
      do {
        Connectivity candidate = connectivity;
        for(auto &face : candidate)
          for(std::size_t &vertex : face) {
            if(vertex < boundaryCount) continue;
            const auto found = std::lower_bound(
              interiorLabels.begin(), interiorLabels.end(), vertex);
            const std::size_t label = static_cast<std::size_t>(
              found - interiorLabels.begin());
            vertex = boundaryCount + relabeling[label];
          }
        candidate = canonicalConnectivity(candidate);
        if(!hasBest || candidate < best) {
          best = std::move(candidate);
          hasBest = true;
        }
      } while(std::next_permutation(relabeling.begin(), relabeling.end()));
      return best;
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

    // Exact and complete all-quad reconnections of a T-Q^k-T strip. The two
    // rails include the two triangle apexes and contain k+3 vertices each.
    // Together they define the oriented (2k+4)-gon surrounding the strip.
    // Enumerating that polygon directly avoids loading, transforming and
    // canonicalizing the generic B-gone catalog while retaining every valid
    // non-crossing reconnection (1, 3, 12, 55 and 273 for k=0..4).
    inline std::vector<QuadConnectivity> triangleQuadStripReconnections(
      const std::vector<std::size_t> &firstRail,
      const std::vector<std::size_t> &secondRail)
    {
      if(firstRail.size() != secondRail.size() || firstRail.size() < 3 ||
         firstRail.front() != secondRail.front() ||
         firstRail.back() != secondRail.back())
        return {};

      std::vector<std::size_t> polygon = firstRail;
      polygon.reserve(2 * firstRail.size() - 2);
      for(std::size_t i = secondRail.size() - 1; i-- > 1;)
        polygon.push_back(secondRail[i]);
      std::vector<std::size_t> unique = polygon;
      std::sort(unique.begin(), unique.end());
      if(std::adjacent_find(unique.begin(), unique.end()) != unique.end())
        return {};
      return evenPolygonQuadrangulations(polygon);
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
