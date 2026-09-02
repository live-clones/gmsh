// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.

#ifndef HALF_EDGE_REWRITE_CATALOG_H
#define HALF_EDGE_REWRITE_CATALOG_H

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

    enum class Kind {
      // Replace a disk formed by two triangles joined by a simple path of
      // zero or more quadrangles by an all-quad disk.  One descriptor covers
      // T+T, T-Q-T, T-Q-Q-T, ... and all their dihedral images.
      TriangleQuadStripReduction,
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
      InvalidQuadSplit,
      CatastrophicAngleQuadSplit
    };

    struct Descriptor {
      const char *id;
      Kind kind;
      Family family;
      Schedule schedule;
      Symmetry symmetry;
    };

    inline const std::array<Descriptor, 18> &catalog()
    {
      static const std::array<Descriptor, 18> rules = {{
        {"interior_qqtqqt_to_6q", Kind::InteriorQQTQQTReduction,
         Family::Mixed, Schedule::CleanUp, Symmetry::Dihedral},
        {"triangle_triangle_swap", Kind::TriangleTriangleSwap,
         Family::Mixed, Schedule::CleanUp, Symmetry::Dihedral},
        {"triangle_quad_strip_reduce", Kind::TriangleQuadStripReduction,
         Family::Mixed, Schedule::CleanUp, Symmetry::Dihedral},
        {"mixed_tq_swap", Kind::MixedTriangleQuadSwap, Family::Mixed,
         Schedule::CleanUp, Symmetry::Dihedral},
        {"quad_quad_swap", Kind::QuadQuadSwap, Family::Connectivity,
         Schedule::CleanUp, Symmetry::Dihedral},
        {"valence6_split", Kind::ValenceSixSplit, Family::Connectivity,
         Schedule::CleanUp, Symmetry::Dihedral},
        {"disk_connectivity", Kind::ConnectivityDisk, Family::Connectivity,
         Schedule::CleanUp, Symmetry::Dihedral},
        {"one_vertex_disk", Kind::OneVertexDisk, Family::Connectivity,
         Schedule::CleanUp, Symmetry::Dihedral},
        {"diamond_collapse", Kind::DiamondCollapse, Family::Connectivity,
         Schedule::CleanUp, Symmetry::Dihedral},
        {"disk_boundary", Kind::BoundaryDisk, Family::Boundary,
         Schedule::CleanUp, Symmetry::Dihedral},
        {"boundary_t_qn_t", Kind::BoundaryTriangleQuadFan,
         Family::Boundary, Schedule::CleanUp,
         Symmetry::Dihedral},
        {"three_vertex_disk", Kind::ThreeVertexDisk, Family::Shape,
         Schedule::CleanUp, Symmetry::Dihedral},
        {"four_vertex_disk", Kind::FourVertexDisk, Family::Shape,
         Schedule::CleanUp, Symmetry::Dihedral},
        {"disk_shape", Kind::ShapeDisk, Family::Shape,
         Schedule::CleanUp, Symmetry::Dihedral},
        {"disk_size", Kind::SizeDisk, Family::Size,
         Schedule::CleanUp, Symmetry::Dihedral},
        {"pillow_hole", Kind::PillowHole, Family::Boundary,
         Schedule::PostProcess, Symmetry::BoundaryOriented},
        {"invalid_quad_split", Kind::InvalidQuadSplit, Family::Validity,
         Schedule::Terminal, Symmetry::Dihedral},
        // This catastrophic-angle fallback is intentionally alone in the
        // last schedule. It may introduce triangles, and no recombination or
        // cleanup follows it.
        {"catastrophic_angle_quad_split", Kind::CatastrophicAngleQuadSplit,
         Family::Validity, Schedule::FinalFallback, Symmetry::Dihedral}
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

  } // namespace HalfEdgeRewrite
} // namespace QuadOptimizer

#endif
