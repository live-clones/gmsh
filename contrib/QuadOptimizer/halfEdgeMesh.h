// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.

#ifndef QUAD_OPTIMIZER_HALF_EDGE_MESH_H
#define QUAD_OPTIMIZER_HALF_EDGE_MESH_H

#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <limits>
#include <map>
#include <set>
#include <type_traits>
#include <utility>
#include <vector>

namespace QuadOptimizer {
  namespace HalfEdgeMesh {

    // This is the persistent topology owned by one face optimizer. It is
    // deliberately independent of Gmsh objects: every stored field is an
    // integer identifier or a double coordinate. The Gmsh adapter in
    // smallCavityOptimizer.cpp is the only place that translates identifiers
    // to MVertex/MElement handles.
    using Index = std::int64_t;
    constexpr Index invalid = -1;

    template <class T>
    void reserveGeometrically(std::vector<T> &values, std::size_t required)
    {
      if(required <= values.capacity()) return;
      const std::size_t capacity = values.capacity();
      const std::size_t grown = capacity <= values.max_size() / 2 ?
        std::max<std::size_t>(8, 2 * capacity) : values.max_size();
      values.reserve(std::max(required, grown));
    }

    struct Vertex {
      std::array<double, 3> xyz = {{0., 0., 0.}};
      Index active = 1;
    };

    struct Face {
      std::array<Index, 4> vertices = {{invalid, invalid, invalid, invalid}};
      Index firstHalfEdge = invalid;
      Index cornerCount = 0;
      Index active = 0;
    };

    struct HalfEdge {
      Index origin = invalid;
      Index face = invalid;
      Index next = invalid;
      Index previous = invalid;
      Index twin = invalid;
      Index active = 0;
    };

    static_assert(std::is_trivially_copyable<Vertex>::value,
                  "numeric half-edge vertices must remain POD-like");
    static_assert(std::is_trivially_copyable<Face>::value,
                  "numeric half-edge faces must remain POD-like");
    static_assert(std::is_trivially_copyable<HalfEdge>::value,
                  "numeric half-edges must remain POD-like");

    struct Edge {
      Index first = invalid;
      Index second = invalid;

      bool operator<(const Edge &other) const
      {
        return first < other.first ||
               (first == other.first && second < other.second);
      }

      bool operator==(const Edge &other) const
      {
        return first == other.first && second == other.second;
      }
    };

    struct EdgeFaces {
      Edge edge;
      std::vector<Index> faces;
    };

    enum class CavityAnchor : std::int64_t {
      ExplicitFaces = 0,
      Vertex = 1,
      VertexSet = 2,
      Edge = 3,
      SingleQuadrangle = 4
    };

    // One representation for every local rewrite domain. `coreFaces` is C;
    // `faces` is the current support and becomes C+C' after an extension by
    // vertex stars. All identities are stable numeric mesh identifiers.
    struct Cavity {
      CavityAnchor anchor = CavityAnchor::ExplicitFaces;
      Index anchorFirst = invalid;
      Index anchorSecond = invalid;
      Index anchorOnBoundary = 0;
      // Complete numeric identity of a vertex or vertex-set anchor.  The
      // scalar fields above remain convenient for the common one-vertex and
      // one-edge cases; this vector is what makes three- and four-vertex
      // cavity anchors lossless.
      std::vector<Index> anchorVertices;
      // Ordered incidences of the anchor in the persistent mesh. For a
      // vertex this is its cyclic interior ring or its open boundary chain;
      // for an edge or a single quadrangle it is the complete incident set.
      // Pattern matchers therefore read TTQ, T-Q-Q-T-Q-Q, ... directly from
      // integer face identifiers without rebuilding adjacency from handles.
      std::vector<Index> anchorFaces;
      std::vector<Index> coreFaces;
      std::vector<Index> faces;
      std::vector<Index> boundaryVertices;
      std::vector<Index> interiorVertices;

      void clear()
      {
        anchor = CavityAnchor::ExplicitFaces;
        anchorFirst = invalid;
        anchorSecond = invalid;
        anchorOnBoundary = 0;
        anchorVertices.clear();
        anchorFaces.clear();
        coreFaces.clear();
        faces.clear();
        boundaryVertices.clear();
        interiorVertices.clear();
      }
    };

    inline Edge canonicalEdge(Index first, Index second)
    {
      if(second < first) std::swap(first, second);
      return {first, second};
    }

    class Mesh {
    public:
      class PreparedReplacement {
        friend class Mesh;
        const Mesh *_owner = nullptr;
        std::uint64_t _revision = 0;
        std::vector<Index> _removed;
        std::vector<std::vector<Index> > _inserted;

      public:
        PreparedReplacement() = default;
        PreparedReplacement(const PreparedReplacement &) = delete;
        PreparedReplacement &operator=(const PreparedReplacement &) = delete;
        PreparedReplacement(PreparedReplacement &&other) noexcept
        { *this = std::move(other); }
        PreparedReplacement &operator=(PreparedReplacement &&other) noexcept
        {
          if(this != &other) {
            _owner = std::exchange(other._owner, nullptr);
            _revision = other._revision;
            _removed = std::move(other._removed);
            _inserted = std::move(other._inserted);
          }
          return *this;
        }
      };

    private:
      std::vector<Vertex> _vertices;
      std::vector<Face> _faces;
      std::vector<HalfEdge> _halfEdges;
      std::vector<std::vector<Index> > _outgoing;
      std::map<Edge, std::vector<Index> > _edgeHalfEdges;
      std::set<Index> _activeFaces;
      std::set<Index> _activeVertices;
      std::uint64_t _topologyRevision = 0;
      std::array<std::size_t, 5> _faceCounts = {{0, 0, 0, 0, 0}};
      Index _manifold = 1;
      mutable Index _vertexLinksDirty = 1;
      mutable Index _vertexLinksManifold = 1;

      bool validVertex(Index vertex) const
      {
        return vertex >= 0 &&
               static_cast<std::size_t>(vertex) < _vertices.size() &&
               _vertices[static_cast<std::size_t>(vertex)].active;
      }

      bool validFace(Index face) const
      {
        return face >= 0 &&
               static_cast<std::size_t>(face) < _faces.size() &&
               _faces[static_cast<std::size_t>(face)].active;
      }

      bool validHalfEdge(Index halfEdge) const
      {
        return halfEdge >= 0 &&
               static_cast<std::size_t>(halfEdge) < _halfEdges.size() &&
               _halfEdges[static_cast<std::size_t>(halfEdge)].active;
      }

      Index destination(Index halfEdge) const
      {
        if(!validHalfEdge(halfEdge)) return invalid;
        const Index next = _halfEdges[static_cast<std::size_t>(halfEdge)].next;
        return validHalfEdge(next) ?
          _halfEdges[static_cast<std::size_t>(next)].origin : invalid;
      }

      bool buildDiskCavity(const std::vector<Index> &input,
                           Cavity &result) const
      {
        result.clear();
        if(input.empty() || !manifold()) return false;
        const std::set<Index> selected(input.begin(), input.end());
        if(selected.size() != input.size()) return false;
        for(const Index face : selected)
          if(!validFace(face)) return false;

        std::set<Index> localVertices;
        std::set<Edge> localEdges;
        std::map<Index, Index> boundaryNext;
        std::map<Index, Index> boundaryPrevious;
        std::map<Index, std::set<Index> > dual;
        std::size_t boundaryEdgeCount = 0;
        for(const Index faceIndex : selected) {
          dual[faceIndex];
          const Face &face = _faces[static_cast<std::size_t>(faceIndex)];
          for(Index i = 0; i < face.cornerCount; ++i) {
            const Index halfEdgeIndex = face.firstHalfEdge + i;
            if(!validHalfEdge(halfEdgeIndex)) return false;
            const Index first =
              _halfEdges[static_cast<std::size_t>(halfEdgeIndex)].origin;
            const Index second = destination(halfEdgeIndex);
            if(first == invalid || second == invalid) return false;
            localVertices.insert(first);
            localVertices.insert(second);
            localEdges.insert(canonicalEdge(first, second));
            const Index twin =
              _halfEdges[static_cast<std::size_t>(halfEdgeIndex)].twin;
            const Index neighbor = validHalfEdge(twin) ?
              _halfEdges[static_cast<std::size_t>(twin)].face : invalid;
            if(neighbor != invalid && selected.find(neighbor) != selected.end()) {
              dual[faceIndex].insert(neighbor);
              dual[neighbor].insert(faceIndex);
              continue;
            }
            ++boundaryEdgeCount;
            if(!boundaryNext.emplace(first, second).second ||
               !boundaryPrevious.emplace(second, first).second)
              return false;
          }
        }

        // C must be one edge-connected component.
        std::set<Index> reachedFaces;
        std::vector<Index> stack(1, *selected.begin());
        while(!stack.empty()) {
          const Index face = stack.back();
          stack.pop_back();
          if(!reachedFaces.insert(face).second) continue;
          for(const Index neighbor : dual[face])
            if(reachedFaces.find(neighbor) == reachedFaces.end())
              stack.push_back(neighbor);
        }
        if(reachedFaces.size() != selected.size() || boundaryEdgeCount < 3 ||
           boundaryNext.size() != boundaryEdgeCount ||
           boundaryPrevious.size() != boundaryEdgeCount)
          return false;

        // Follow the orientation inherited from the selected faces. Starting
        // at the smallest identifier makes rotations deterministic while a
        // reflected ordering is never manufactured.
        const Index start = boundaryNext.begin()->first;
        Index current = start;
        std::set<Index> reachedBoundaryVertices;
        for(std::size_t step = 0; step < boundaryEdgeCount; ++step) {
          if(!reachedBoundaryVertices.insert(current).second) return false;
          result.boundaryVertices.push_back(current);
          const auto found = boundaryNext.find(current);
          if(found == boundaryNext.end()) return false;
          current = found->second;
        }
        if(current != start ||
           reachedBoundaryVertices.size() != boundaryEdgeCount)
          return false;

        const std::int64_t euler =
          static_cast<std::int64_t>(localVertices.size()) -
          static_cast<std::int64_t>(localEdges.size()) +
          static_cast<std::int64_t>(selected.size());
        if(euler != 1) return false;

        result.faces.assign(selected.begin(), selected.end());
        result.coreFaces = result.faces;
        for(const Index vertex : localVertices)
          if(reachedBoundaryVertices.find(vertex) ==
             reachedBoundaryVertices.end())
            result.interiorVertices.push_back(vertex);
        return true;
      }

      void compactEdge(const Edge &edge)
      {
        const auto found = _edgeHalfEdges.find(edge);
        if(found == _edgeHalfEdges.end()) return;
        std::vector<Index> &halfEdges = found->second;
        halfEdges.erase(
          std::remove_if(halfEdges.begin(), halfEdges.end(),
                         [&](Index halfEdge) {
                           return !validHalfEdge(halfEdge);
                         }),
          halfEdges.end());
        if(halfEdges.empty()) _edgeHalfEdges.erase(found);
      }

      void compactOutgoing(Index vertex)
      {
        if(vertex < 0 || static_cast<std::size_t>(vertex) >= _outgoing.size())
          return;
        std::vector<Index> &halfEdges =
          _outgoing[static_cast<std::size_t>(vertex)];
        halfEdges.erase(
          std::remove_if(halfEdges.begin(), halfEdges.end(),
                         [&](Index halfEdge) {
                           return !validHalfEdge(halfEdge);
                         }),
          halfEdges.end());
      }

      bool vertexLinksAreManifold() const
      {
        for(std::size_t vertex = 0; vertex < _outgoing.size(); ++vertex) {
          std::set<Index> incident;
          std::map<Index, std::set<Index> > link;
          std::size_t boundarySides = 0;
          for(const Index outgoingIndex : _outgoing[vertex]) {
            if(!validHalfEdge(outgoingIndex)) continue;
            const HalfEdge &outgoing =
              _halfEdges[static_cast<std::size_t>(outgoingIndex)];
            incident.insert(outgoing.face);
            link[outgoing.face];
            const std::array<Index, 2> sides = {
              {outgoingIndex, outgoing.previous}};
            for(const Index side : sides) {
              if(!validHalfEdge(side)) return false;
              const Index twin =
                _halfEdges[static_cast<std::size_t>(side)].twin;
              if(twin == invalid) {
                ++boundarySides;
                continue;
              }
              if(!validHalfEdge(twin)) return false;
              const Index other =
                _halfEdges[static_cast<std::size_t>(twin)].face;
              if(!validFace(other) || other == outgoing.face) return false;
              link[outgoing.face].insert(other);
            }
          }
          if(incident.empty()) continue;

          std::set<Index> reached;
          std::vector<Index> stack(1, *incident.begin());
          while(!stack.empty()) {
            const Index face = stack.back();
            stack.pop_back();
            if(!reached.insert(face).second) continue;
            const auto found = link.find(face);
            if(found == link.end()) return false;
            for(const Index neighbor : found->second) {
              if(incident.find(neighbor) == incident.end()) return false;
              if(reached.find(neighbor) == reached.end())
                stack.push_back(neighbor);
            }
          }
          if(reached.size() != incident.size()) return false;

          if(boundarySides == 0) {
            for(const Index face : incident)
              if(link[face].size() != 2) return false;
          }
          else {
            if(boundarySides != 2) return false;
            std::size_t endpoints = 0;
            for(const Index face : incident) {
              const std::size_t degree = link[face].size();
              if(incident.size() == 1) {
                if(degree != 0) return false;
              }
              else if(degree == 1)
                ++endpoints;
              else if(degree != 2)
                return false;
            }
            if(incident.size() > 1 && endpoints != 2) return false;
          }
        }
        return true;
      }

      // Check every storage bound used by addFace() without modifying the
      // mesh. In particular, keep one value below the Index limit for the
      // half-edge table, as addFace() does.
      bool replacementStorageFits(
        const std::vector<std::vector<Index> > &inserted) const
      {
        const std::size_t indexLimit = static_cast<std::size_t>(
          std::numeric_limits<Index>::max());
        if(_faces.size() > indexLimit ||
           inserted.size() > indexLimit - _faces.size())
          return false;

        if(inserted.empty()) return true;
        if(_halfEdges.size() >= indexLimit) return false;
        const std::size_t available = indexLimit - _halfEdges.size();
        std::size_t required = 0;
        for(const std::vector<Index> &vertices : inserted) {
          if(vertices.size() != 3 && vertices.size() != 4) return false;
          // The strict comparison mirrors addFace(): the resulting table
          // size must stay strictly below indexLimit.
          if(vertices.size() >= available - required) return false;
          required += vertices.size();
        }
        return true;
      }

      bool replacementVerticesAreMaterialized(
        const std::vector<std::vector<Index> > &inserted) const
      {
        for(const std::vector<Index> &vertices : inserted)
          for(const Index vertex : vertices)
            if(!validVertex(vertex)) return false;
        return true;
      }

    public:
      Index addVertex(const std::array<double, 3> &xyz)
      {
        if(_vertices.size() >=
           static_cast<std::size_t>(std::numeric_limits<Index>::max()))
          return invalid;
        const Index result = static_cast<Index>(_vertices.size());
        Vertex vertex;
        vertex.xyz = xyz;
        reserveGeometrically(_vertices, _vertices.size() + 1);
        reserveGeometrically(_outgoing, _outgoing.size() + 1);
        _vertices.push_back(vertex);
        _outgoing.emplace_back();
        return result;
      }

      bool setVertexPosition(Index vertex,
                             const std::array<double, 3> &xyz)
      {
        if(!validVertex(vertex)) return false;
        _vertices[static_cast<std::size_t>(vertex)].xyz = xyz;
        return true;
      }

      const std::array<double, 3> *vertexPosition(Index vertex) const
      {
        return validVertex(vertex) ?
          &_vertices[static_cast<std::size_t>(vertex)].xyz : nullptr;
      }

      Index addFace(const std::vector<Index> &vertices)
      {
        const std::size_t indexLimit = static_cast<std::size_t>(
          std::numeric_limits<Index>::max());
        if((vertices.size() != 3 && vertices.size() != 4) ||
           _faces.size() >= indexLimit ||
           _halfEdges.size() >= indexLimit ||
           vertices.size() >= indexLimit - _halfEdges.size()) {
          _manifold = 0;
          return invalid;
        }
        std::set<Index> unique;
        for(const Index vertex : vertices)
          if(!validVertex(vertex) || !unique.insert(vertex).second) {
            _manifold = 0;
            return invalid;
          }

        const Index faceIndex = static_cast<Index>(_faces.size());
        const Index firstHalfEdge = static_cast<Index>(_halfEdges.size());
        Face face;
        face.firstHalfEdge = firstHalfEdge;
        face.cornerCount = static_cast<Index>(vertices.size());
        face.active = 1;
        for(std::size_t i = 0; i < vertices.size(); ++i)
          face.vertices[i] = vertices[i];
        _faces.push_back(face);
        _activeFaces.insert(faceIndex);

        for(std::size_t i = 0; i < vertices.size(); ++i) {
          HalfEdge halfEdge;
          halfEdge.origin = vertices[i];
          halfEdge.face = faceIndex;
          halfEdge.next = firstHalfEdge +
            static_cast<Index>((i + 1) % vertices.size());
          halfEdge.previous = firstHalfEdge +
            static_cast<Index>((i + vertices.size() - 1) % vertices.size());
          halfEdge.active = 1;
          _halfEdges.push_back(halfEdge);
        }

        std::set<Index> adjacentFaces;
        for(std::size_t i = 0; i < vertices.size(); ++i) {
          const Index halfEdgeIndex = firstHalfEdge + static_cast<Index>(i);
          HalfEdge &halfEdge =
            _halfEdges[static_cast<std::size_t>(halfEdgeIndex)];
          _outgoing[static_cast<std::size_t>(halfEdge.origin)]
            .push_back(halfEdgeIndex);
          _activeVertices.insert(halfEdge.origin);
          const Edge edge = canonicalEdge(
            halfEdge.origin, destination(halfEdgeIndex));
          compactEdge(edge);
          std::vector<Index> &incidences = _edgeHalfEdges[edge];
          if(incidences.size() == 1) {
            const Index twin = incidences.front();
            const HalfEdge &other =
              _halfEdges[static_cast<std::size_t>(twin)];
            if(other.origin != destination(halfEdgeIndex) ||
               destination(twin) != halfEdge.origin)
              _manifold = 0;
            if(!adjacentFaces.insert(other.face).second) _manifold = 0;
            halfEdge.twin = twin;
            _halfEdges[static_cast<std::size_t>(twin)].twin = halfEdgeIndex;
          }
          else if(!incidences.empty()) {
            _manifold = 0;
          }
          incidences.push_back(halfEdgeIndex);
        }
        ++_faceCounts[vertices.size()];
        _vertexLinksDirty = 1;
        ++_topologyRevision;
        return faceIndex;
      }

      bool removeFace(Index faceIndex)
      {
        if(!validFace(faceIndex)) return false;
        Face &face = _faces[static_cast<std::size_t>(faceIndex)];
        std::vector<Edge> touchedEdges;
        std::vector<Index> touchedVertices;
        for(Index i = 0; i < face.cornerCount; ++i) {
          const Index origin = face.vertices[static_cast<std::size_t>(i)];
          const Index next = face.vertices[static_cast<std::size_t>(
            (i + 1) % face.cornerCount)];
          touchedEdges.push_back(canonicalEdge(origin, next));
          touchedVertices.push_back(origin);
        }
        for(Index i = 0; i < face.cornerCount; ++i) {
          const Index halfEdgeIndex = face.firstHalfEdge + i;
          if(!validHalfEdge(halfEdgeIndex)) continue;
          HalfEdge &halfEdge =
            _halfEdges[static_cast<std::size_t>(halfEdgeIndex)];
          if(validHalfEdge(halfEdge.twin))
            _halfEdges[static_cast<std::size_t>(halfEdge.twin)].twin =
              invalid;
          halfEdge.twin = invalid;
          halfEdge.active = 0;
        }
        --_faceCounts[static_cast<std::size_t>(face.cornerCount)];
        face.active = 0;
        _activeFaces.erase(faceIndex);
        for(const Edge &edge : touchedEdges) compactEdge(edge);
        for(const Index vertex : touchedVertices) {
          compactOutgoing(vertex);
          if(_outgoing[static_cast<std::size_t>(vertex)].empty())
            _activeVertices.erase(vertex);
        }
        _vertexLinksDirty = 1;
        ++_topologyRevision;
        return true;
      }

      bool prepareReplacement(
        const std::vector<Index> &removed,
        const std::vector<std::vector<Index> > &inserted,
        PreparedReplacement &result) const
      {
        result = PreparedReplacement();
        if(!validReplacement(removed, inserted)) return false;
        PreparedReplacement prepared;
        prepared._owner = this;
        prepared._revision = _topologyRevision;
        prepared._removed = removed;
        prepared._inserted = inserted;
        result = std::move(prepared);
        return true;
      }

      bool replace(const std::vector<Index> &removed,
                   const std::vector<std::vector<Index> > &inserted,
                   std::vector<Index> *insertedFaces = nullptr)
      {
        if(insertedFaces) insertedFaces->clear();
        PreparedReplacement prepared;
        return prepareReplacement(removed, inserted, prepared) &&
          replace(prepared, insertedFaces);
      }

      bool replace(PreparedReplacement &prepared,
                   std::vector<Index> *insertedFaces = nullptr)
      {
        if(insertedFaces) insertedFaces->clear();
        // A proof is tied to the topology, but accepts vertices materialized
        // since preparation. Coordinate changes cannot invalidate its purely
        // combinatorial predicates.
        if(!_manifold || prepared._owner != this ||
           prepared._revision != _topologyRevision ||
           !replacementVerticesAreMaterialized(prepared._inserted))
          return false;
        const auto &removed = prepared._removed;
        const auto &inserted = prepared._inserted;
        const std::set<Index> removedSet(removed.begin(), removed.end());
        std::map<Edge, std::vector<Index> > edgePatches;
        std::map<Index, std::vector<Index> > outgoingPatches;
        std::vector<Face> newFaces;
        std::vector<HalfEdge> newHalfEdges;
        std::vector<Index> committedFaces;
        std::set<Index> activeFacesToInsert, activeVerticesToInsert;
        for(const Index faceIndex : removed) {
          const Face &face = _faces[static_cast<std::size_t>(faceIndex)];
          for(Index i = 0; i < face.cornerCount; ++i) {
            const Index origin = face.vertices[static_cast<std::size_t>(i)];
            const Index next = face.vertices[static_cast<std::size_t>(
              (i + 1) % face.cornerCount)];
            edgePatches[canonicalEdge(origin, next)];
            outgoingPatches[origin];
          }
        }
        for(const auto &vertices : inserted) {
          const Index faceIndex = static_cast<Index>(_faces.size() +
                                                     newFaces.size());
          const Index firstHalfEdge = static_cast<Index>(
            _halfEdges.size() + newHalfEdges.size());
          Face face;
          face.firstHalfEdge = firstHalfEdge;
          face.cornerCount = static_cast<Index>(vertices.size());
          face.active = 1;
          for(std::size_t i = 0; i < vertices.size(); ++i) {
            face.vertices[i] = vertices[i];
            HalfEdge halfEdge;
            halfEdge.origin = vertices[i];
            halfEdge.face = faceIndex;
            halfEdge.next = firstHalfEdge +
              static_cast<Index>((i + 1) % vertices.size());
            halfEdge.previous = firstHalfEdge +
              static_cast<Index>((i + vertices.size() - 1) % vertices.size());
            halfEdge.active = 1;
            newHalfEdges.push_back(halfEdge);
            const Index halfEdgeIndex = firstHalfEdge + static_cast<Index>(i);
            edgePatches[canonicalEdge(vertices[i],
                                     vertices[(i + 1) % vertices.size()])]
              .push_back(halfEdgeIndex);
            outgoingPatches[vertices[i]].push_back(halfEdgeIndex);
          }
          newFaces.push_back(face);
          committedFaces.push_back(faceIndex);
          activeFacesToInsert.insert(faceIndex);
        }
        for(auto &entry : edgePatches) {
          const auto found = _edgeHalfEdges.find(entry.first);
          if(found == _edgeHalfEdges.end()) continue;
          for(const Index halfEdge : found->second)
            if(validHalfEdge(halfEdge) &&
               !removedSet.count(_halfEdges[static_cast<std::size_t>(halfEdge)]
                                   .face))
              entry.second.push_back(halfEdge);
        }
        for(auto &entry : outgoingPatches) {
          for(const Index halfEdge : _outgoing[static_cast<std::size_t>(
                                     entry.first)])
            if(validHalfEdge(halfEdge) &&
               !removedSet.count(_halfEdges[static_cast<std::size_t>(halfEdge)]
                                   .face))
              entry.second.push_back(halfEdge);
          if(!entry.second.empty() && !_activeVertices.count(entry.first))
            activeVerticesToInsert.insert(entry.first);
        }

        // Allocate every changed adjacency and new map node before changing
        // a face. Geometric capacity growth keeps the append-only storage
        // amortized linear across many local edits.
        reserveGeometrically(_faces, _faces.size() + newFaces.size());
        reserveGeometrically(_halfEdges, _halfEdges.size() + newHalfEdges.size());
        std::vector<Edge> createdEdges;
        createdEdges.reserve(edgePatches.size());
        try {
          for(const auto &entry : edgePatches) {
            if(_edgeHalfEdges.emplace(entry.first, std::vector<Index>()).second)
              createdEdges.push_back(entry.first);
          }
        }
        catch(...) {
          for(const Edge &edge : createdEdges) _edgeHalfEdges.erase(edge);
          throw;
        }

        // Everything below uses reserved POD tables, node transfers and
        // swaps. No allocation or input-dependent rejection remains.
        for(const Index faceIndex : removed) {
          Face &face = _faces[static_cast<std::size_t>(faceIndex)];
          face.active = 0;
          --_faceCounts[static_cast<std::size_t>(face.cornerCount)];
          _activeFaces.erase(faceIndex);
          for(Index i = 0; i < face.cornerCount; ++i) {
            HalfEdge &halfEdge = _halfEdges[static_cast<std::size_t>(
              face.firstHalfEdge + i)];
            halfEdge.active = 0;
            halfEdge.twin = invalid;
          }
        }
        for(const Face &face : newFaces) {
          _faces.push_back(face);
          ++_faceCounts[static_cast<std::size_t>(face.cornerCount)];
        }
        for(const HalfEdge &halfEdge : newHalfEdges)
          _halfEdges.push_back(halfEdge);
        for(auto &entry : edgePatches) {
          auto found = _edgeHalfEdges.find(entry.first);
          found->second.swap(entry.second);
          const auto &incidences = found->second;
          for(const Index halfEdge : incidences)
            _halfEdges[static_cast<std::size_t>(halfEdge)].twin =
              incidences.size() == 2 ?
                (incidences[0] == halfEdge ? incidences[1] : incidences[0]) :
                invalid;
          if(incidences.empty()) _edgeHalfEdges.erase(found);
        }
        for(auto &entry : outgoingPatches) {
          _outgoing[static_cast<std::size_t>(entry.first)].swap(entry.second);
          if(_outgoing[static_cast<std::size_t>(entry.first)].empty())
            _activeVertices.erase(entry.first);
        }
        _activeFaces.merge(activeFacesToInsert);
        _activeVertices.merge(activeVerticesToInsert);
        _vertexLinksManifold = 1;
        _vertexLinksDirty = 0;
        ++_topologyRevision;
        prepared._owner = nullptr;
        if(insertedFaces) *insertedFaces = std::move(committedFaces);
        return true;
      }

      // Roll back only uncommitted, newly materialized isolated vertices.
      // Committed identifiers are never reused.
      bool discardIsolatedVertexTail(std::size_t first)
      {
        if(first > _vertices.size()) return false;
        for(std::size_t i = first; i < _vertices.size(); ++i)
          if(!_outgoing[i].empty()) return false;
        _vertices.resize(first);
        _outgoing.resize(first);
        return true;
      }

      // Vertices use stable tombstone identifiers just like cells and
      // half-edges. The adapter retires a vertex only after an accepted edit
      // has removed its last incident face; its slot is never reused during
      // the optimization.
      bool retireIsolatedVertex(Index vertex)
      {
        if(!validVertex(vertex) || !incidentFaces(vertex).empty())
          return false;
        _vertices[static_cast<std::size_t>(vertex)].active = 0;
        _outgoing[static_cast<std::size_t>(vertex)].clear();
        _activeVertices.erase(vertex);
        ++_topologyRevision;
        return true;
      }

      // Local preflight for a transaction. Candidate vertex identifiers may
      // be virtual (at or beyond the current vertex table); only their integer
      // identity matters until the transaction is committed by the adapter.
      bool validReplacement(
        const std::vector<Index> &removed,
        const std::vector<std::vector<Index> > &inserted) const
      {
        if(!replacementStorageFits(inserted) || !manifold()) return false;
        std::set<Index> removedFaces;
        std::set<Index> touchedVertices;
        for(const Index face : removed)
          if(!validFace(face) || !removedFaces.insert(face).second)
            return false;
          else {
            const std::vector<Index> vertices = faceVertices(face);
            touchedVertices.insert(vertices.begin(), vertices.end());
          }

        struct Incidence {
          Index origin = invalid;
          Index destination = invalid;
          std::int64_t face = -1;
        };
        std::set<Edge> insertedEdges;
        for(const std::vector<Index> &vertices : inserted) {
          if(vertices.size() != 3 && vertices.size() != 4) return false;
          std::set<Index> unique;
          for(std::size_t i = 0; i < vertices.size(); ++i) {
            const Index vertex = vertices[i];
            // Existing identifiers must designate active vertices. Values at
            // or beyond the current table are virtual and remain legal for
            // adapter-side preflight.
            if(vertex < 0 ||
               (static_cast<std::size_t>(vertex) < _vertices.size() &&
                !validVertex(vertex)) ||
               !unique.insert(vertex).second)
              return false;
            touchedVertices.insert(vertex);
            insertedEdges.insert(canonicalEdge(
              vertex, vertices[(i + 1) % vertices.size()]));
          }
        }

        std::map<Edge, std::vector<Incidence> > incidences;
        for(const Edge &edge : insertedEdges) {
          const auto found = _edgeHalfEdges.find(edge);
          if(found == _edgeHalfEdges.end()) continue;
          for(const Index halfEdgeIndex : found->second) {
            if(!validHalfEdge(halfEdgeIndex)) continue;
            const HalfEdge &halfEdge =
              _halfEdges[static_cast<std::size_t>(halfEdgeIndex)];
            if(removedFaces.find(halfEdge.face) != removedFaces.end())
              continue;
            incidences[edge].push_back(
              {halfEdge.origin, destination(halfEdgeIndex), halfEdge.face});
          }
        }

        for(std::size_t candidate = 0; candidate < inserted.size();
            ++candidate) {
          const std::vector<Index> &vertices = inserted[candidate];
          const std::int64_t candidateFace =
            static_cast<std::int64_t>(_faces.size()) +
            static_cast<std::int64_t>(candidate);
          std::set<std::int64_t> adjacentFaces;
          for(std::size_t i = 0; i < vertices.size(); ++i) {
            const Index origin = vertices[i];
            const Index destination = vertices[(i + 1) % vertices.size()];
            std::vector<Incidence> &edge =
              incidences[canonicalEdge(origin, destination)];
            if(edge.size() == 1) {
              const Incidence &other = edge.front();
              if(other.origin != destination ||
                 other.destination != origin ||
                 !adjacentFaces.insert(other.face).second)
                return false;
            }
            else if(!edge.empty()) {
              return false;
            }
            edge.push_back({origin, destination, candidateFace});
          }
        }

        // The incidence test above is necessary but not sufficient: a local
        // rewrite can create a bow-tie vertex while every edge still has at
        // most two incident cells. Rebuild only the links of vertices touched
        // by the transaction and require each resulting link to be one cycle
        // (interior) or one path (boundary).
        for(const Index vertex : touchedVertices) {
          std::map<Index, std::vector<Index> > star;
          for(const Index face : incidentFaces(vertex))
            if(removedFaces.find(face) == removedFaces.end())
              star.emplace(face, faceVertices(face));
          for(std::size_t candidate = 0; candidate < inserted.size();
              ++candidate) {
            const std::vector<Index> &vertices = inserted[candidate];
            if(std::find(vertices.begin(), vertices.end(), vertex) ==
               vertices.end())
              continue;
            const Index face = static_cast<Index>(_faces.size()) +
              static_cast<Index>(candidate);
            star.emplace(face, vertices);
          }
          if(star.empty()) continue;

          std::map<Edge, std::vector<Index> > sides;
          std::map<Index, std::set<Index> > link;
          for(const auto &entry : star) {
            const Index face = entry.first;
            const std::vector<Index> &vertices = entry.second;
            const auto found =
              std::find(vertices.begin(), vertices.end(), vertex);
            if(found == vertices.end()) return false;
            const std::size_t position = static_cast<std::size_t>(
              found - vertices.begin());
            const Index previous = vertices[
              (position + vertices.size() - 1) % vertices.size()];
            const Index next = vertices[(position + 1) % vertices.size()];
            sides[canonicalEdge(previous, vertex)].push_back(face);
            sides[canonicalEdge(vertex, next)].push_back(face);
            link[face];
          }

          std::size_t boundarySides = 0;
          for(const auto &entry : sides) {
            if(entry.second.size() == 1) {
              ++boundarySides;
            }
            else if(entry.second.size() == 2) {
              const Index first = entry.second[0];
              const Index second = entry.second[1];
              if(first == second) return false;
              link[first].insert(second);
              link[second].insert(first);
            }
            else {
              return false;
            }
          }

          std::set<Index> reached;
          std::vector<Index> stack(1, star.begin()->first);
          while(!stack.empty()) {
            const Index face = stack.back();
            stack.pop_back();
            if(!reached.insert(face).second) continue;
            for(const Index neighbor : link[face])
              if(reached.find(neighbor) == reached.end())
                stack.push_back(neighbor);
          }
          if(reached.size() != star.size()) return false;

          if(boundarySides == 0) {
            for(const auto &entry : link)
              if(entry.second.size() != 2) return false;
          }
          else {
            if(boundarySides != 2) return false;
            std::size_t endpoints = 0;
            for(const auto &entry : link) {
              if(star.size() == 1) {
                if(!entry.second.empty()) return false;
              }
              else if(entry.second.size() == 1)
                ++endpoints;
              else if(entry.second.size() != 2)
                return false;
            }
            if(star.size() > 1 && endpoints != 2) return false;
          }
        }
        return true;
      }

      bool manifold() const
      {
        if(!_manifold) return false;
        if(_vertexLinksDirty) {
          _vertexLinksManifold = vertexLinksAreManifold();
          _vertexLinksDirty = 0;
        }
        return _vertexLinksManifold;
      }

      std::vector<Index> faces() const
      {
        return std::vector<Index>(_activeFaces.begin(), _activeFaces.end());
      }

      std::vector<Index> vertices() const
      {
        return std::vector<Index>(_activeVertices.begin(), _activeVertices.end());
      }

      std::vector<Index> incidentFaces(Index vertex) const
      {
        std::vector<Index> result;
        if(!validVertex(vertex)) return result;
        std::set<Index> unique;
        for(const Index halfEdge : _outgoing[static_cast<std::size_t>(vertex)])
          if(validHalfEdge(halfEdge))
            unique.insert(
              _halfEdges[static_cast<std::size_t>(halfEdge)].face);
        result.assign(unique.begin(), unique.end());
        return result;
      }

      // Return the incident faces in their topological order around a
      // vertex. Interior stars form a cycle; boundary stars form an open
      // chain. The initial face and orientation are deterministic but carry
      // no geometric meaning: rewrite matchers apply their declared cyclic
      // or dihedral symmetry to this purely integer ring.
      std::vector<Index> incidentFaceRing(Index vertex) const
      {
        const std::vector<Index> incident = incidentFaces(vertex);
        if(incident.empty()) return {};

        std::map<Edge, std::vector<Index> > sides;
        std::map<Index, std::set<Index> > link;
        for(const Index faceIndex : incident) {
          const std::vector<Index> corners = faceVertices(faceIndex);
          const auto found = std::find(corners.begin(), corners.end(),
                                       vertex);
          if(found == corners.end()) return {};
          const std::size_t local = static_cast<std::size_t>(
            found - corners.begin());
          const Index previous = corners[
            (local + corners.size() - 1) % corners.size()];
          const Index next = corners[(local + 1) % corners.size()];
          sides[canonicalEdge(previous, vertex)].push_back(faceIndex);
          sides[canonicalEdge(vertex, next)].push_back(faceIndex);
          link[faceIndex];
        }

        std::size_t boundarySides = 0;
        for(const auto &entry : sides) {
          if(entry.second.size() == 1) {
            ++boundarySides;
          }
          else if(entry.second.size() == 2) {
            const Index first = entry.second[0];
            const Index second = entry.second[1];
            if(first == second) return {};
            link[first].insert(second);
            link[second].insert(first);
          }
          else {
            return {};
          }
        }
        if(boundarySides != 0 && boundarySides != 2) return {};

        Index start = invalid;
        if(boundarySides == 0) {
          start = *std::min_element(incident.begin(), incident.end());
          for(const auto &entry : link)
            if(entry.second.size() != 2) return {};
        }
        else {
          for(const auto &entry : link) {
            const bool endpoint = incident.size() == 1 ?
              entry.second.empty() : entry.second.size() == 1;
            if(endpoint && (start == invalid || entry.first < start))
              start = entry.first;
            else if(!endpoint && entry.second.size() != 2)
              return {};
          }
        }
        if(start == invalid) return {};

        std::vector<Index> ring;
        ring.reserve(incident.size());
        Index previous = invalid;
        Index current = start;
        while(current != invalid && ring.size() < incident.size()) {
          ring.push_back(current);
          Index next = invalid;
          const auto found = link.find(current);
          if(found == link.end()) return {};
          for(const Index neighbor : found->second) {
            if(neighbor == previous) continue;
            if(next == invalid || neighbor < next) next = neighbor;
          }
          previous = current;
          current = next;
          if(boundarySides == 0 && current == start) break;
        }
        if(ring.size() != incident.size()) return {};
        if(boundarySides == 0) {
          if(current != start) return {};
        }
        else if(current != invalid) {
          return {};
        }
        return ring;
      }

      std::vector<Index> faceVertices(Index faceIndex) const
      {
        std::vector<Index> result;
        if(!validFace(faceIndex)) return result;
        const Face &face = _faces[static_cast<std::size_t>(faceIndex)];
        result.reserve(static_cast<std::size_t>(face.cornerCount));
        for(Index i = 0; i < face.cornerCount; ++i)
          result.push_back(face.vertices[static_cast<std::size_t>(i)]);
        return result;
      }

      Index faceCornerCount(Index faceIndex) const
      {
        return validFace(faceIndex) ?
          _faces[static_cast<std::size_t>(faceIndex)].cornerCount : 0;
      }

      // Extract the two boundary rails of an ordered T-Q^k-T strip.  The
      // first and last entries are triangle apexes; every intermediate pair
      // is an edge shared by two consecutive strip faces.  The first rail is
      // rooted at the smaller vertex of the first shared edge, making the
      // side choice independent of face roots and orientations.
      bool triangleQuadStripRails(
        const std::vector<Index> &orderedFaces,
        std::vector<Index> &firstRail,
        std::vector<Index> &secondRail) const
      {
        firstRail.clear();
        secondRail.clear();
        if(orderedFaces.size() < 2 || !manifold()) return false;

        const std::set<Index> uniqueFaces(
          orderedFaces.begin(), orderedFaces.end());
        if(uniqueFaces.size() != orderedFaces.size()) return false;

        std::vector<std::vector<Index> > corners(orderedFaces.size());
        std::vector<std::vector<Edge> > faceEdges(orderedFaces.size());
        for(std::size_t i = 0; i < orderedFaces.size(); ++i) {
          const Index expectedCorners =
            (i == 0 || i + 1 == orderedFaces.size()) ? 3 : 4;
          if(faceCornerCount(orderedFaces[i]) != expectedCorners)
            return false;
          corners[i] = faceVertices(orderedFaces[i]);
          faceEdges[i].reserve(corners[i].size());
          for(std::size_t j = 0; j < corners[i].size(); ++j)
            faceEdges[i].push_back(canonicalEdge(
              corners[i][j], corners[i][(j + 1) % corners[i].size()]));
        }

        // The selected cells must themselves form an unpinched disk with no
        // interior vertex.  More specific chain checks below reject a disk
        // whose dual graph is not exactly the requested path.
        Cavity disk;
        if(!buildDiskCavity(orderedFaces, disk) ||
           !disk.interiorVertices.empty())
          return false;

        std::vector<Edge> passageEdges;
        passageEdges.reserve(orderedFaces.size() - 1);
        for(std::size_t i = 0; i + 1 < orderedFaces.size(); ++i) {
          std::vector<Edge> sharedEdges;
          for(const Edge &edge : faceEdges[i])
            if(std::find(faceEdges[i + 1].begin(), faceEdges[i + 1].end(),
                         edge) != faceEdges[i + 1].end())
              sharedEdges.push_back(edge);

          std::vector<Index> sharedVertices;
          for(const Index vertex : corners[i])
            if(std::find(corners[i + 1].begin(), corners[i + 1].end(),
                         vertex) != corners[i + 1].end())
              sharedVertices.push_back(vertex);
          if(sharedEdges.size() != 1 || sharedVertices.size() != 2 ||
             !(canonicalEdge(sharedVertices[0], sharedVertices[1]) ==
               sharedEdges.front()))
            return false;

          std::vector<Index> incidences = incidentFaces(sharedEdges.front());
          std::vector<Index> expected =
            {orderedFaces[i], orderedFaces[i + 1]};
          std::sort(expected.begin(), expected.end());
          if(incidences != expected) return false;
          passageEdges.push_back(sharedEdges.front());
        }

        // Non-neighboring cells of a strip are disjoint, even at vertices.
        // This rejects wrapped fans and paths with a hidden shortcut.
        for(std::size_t i = 0; i < corners.size(); ++i)
          for(std::size_t j = i + 2; j < corners.size(); ++j)
            for(const Index vertex : corners[i])
              if(std::find(corners[j].begin(), corners[j].end(), vertex) !=
                 corners[j].end())
                return false;

        // In every intermediate quadrangle the entering and leaving edges
        // must be opposite. Adjacent passage edges describe a fan, not a
        // two-rail strip.
        for(std::size_t i = 1; i + 1 < orderedFaces.size(); ++i) {
          Index previousPosition = invalid;
          Index nextPosition = invalid;
          for(std::size_t j = 0; j < faceEdges[i].size(); ++j) {
            if(faceEdges[i][j] == passageEdges[i - 1])
              previousPosition = static_cast<Index>(j);
            if(faceEdges[i][j] == passageEdges[i])
              nextPosition = static_cast<Index>(j);
          }
          if(previousPosition == invalid || nextPosition == invalid ||
             (previousPosition + 2) % 4 != nextPosition)
            return false;
        }

        const auto apexOutsideEdge = [](const std::vector<Index> &triangle,
                                        const Edge &edge) {
          Index apex = invalid;
          for(const Index vertex : triangle)
            if(vertex != edge.first && vertex != edge.second) {
              if(apex != invalid) return invalid;
              apex = vertex;
            }
          return apex;
        };
        const Index firstApex =
          apexOutsideEdge(corners.front(), passageEdges.front());
        const Index lastApex =
          apexOutsideEdge(corners.back(), passageEdges.back());
        if(firstApex == invalid || lastApex == invalid) return false;

        std::vector<Index> first =
          {firstApex, passageEdges.front().first};
        std::vector<Index> second =
          {firstApex, passageEdges.front().second};
        for(std::size_t i = 1; i + 1 < orderedFaces.size(); ++i) {
          const Edge &entering = passageEdges[i - 1];
          const Edge &leaving = passageEdges[i];
          const auto continuation = [&](Index vertex) {
            const auto found = std::find(
              corners[i].begin(), corners[i].end(), vertex);
            if(found == corners[i].end()) return invalid;
            const std::size_t position = static_cast<std::size_t>(
              found - corners[i].begin());
            const Index previous = corners[i][
              (position + corners[i].size() - 1) % corners[i].size()];
            const Index next =
              corners[i][(position + 1) % corners[i].size()];
            const Index otherEntering = vertex == entering.first ?
              entering.second : vertex == entering.second ?
              entering.first : invalid;
            if(otherEntering == invalid) return invalid;
            const Index candidate = previous == otherEntering ? next :
              next == otherEntering ? previous : invalid;
            return candidate == leaving.first || candidate == leaving.second ?
              candidate : invalid;
          };
          const Index nextFirst = continuation(first.back());
          const Index nextSecond = continuation(second.back());
          if(nextFirst == invalid || nextSecond == invalid ||
             nextFirst == nextSecond)
            return false;
          first.push_back(nextFirst);
          second.push_back(nextSecond);
        }
        first.push_back(lastApex);
        second.push_back(lastApex);

        // The two rails may only meet at their apexes and must reproduce the
        // complete disk boundary.
        std::vector<Index> railBoundary = first;
        railBoundary.insert(railBoundary.end(), second.begin() + 1,
                            second.end() - 1);
        std::sort(railBoundary.begin(), railBoundary.end());
        if(std::adjacent_find(railBoundary.begin(), railBoundary.end()) !=
           railBoundary.end())
          return false;
        std::vector<Index> diskBoundary = disk.boundaryVertices;
        std::sort(diskBoundary.begin(), diskBoundary.end());
        if(railBoundary != diskBoundary) return false;

        firstRail = std::move(first);
        secondRail = std::move(second);
        return true;
      }

      // Recognize the other useful T-Q^k-T path: an open fan whose cells
      // all meet at one boundary vertex.  This is intentionally distinct
      // from triangleQuadStripRails(); accepting every bent dual path here
      // would turn the local rewrite into a generic polygon remesher again.
      Index triangleQuadBoundaryFanCenter(
        const std::vector<Index> &orderedFaces) const
      {
        if(orderedFaces.size() < 3 || !manifold()) return invalid;

        const std::set<Index> uniqueFaces(
          orderedFaces.begin(), orderedFaces.end());
        if(uniqueFaces.size() != orderedFaces.size()) return invalid;

        std::vector<std::vector<Index> > corners(orderedFaces.size());
        std::vector<std::vector<Edge> > faceEdges(orderedFaces.size());
        for(std::size_t i = 0; i < orderedFaces.size(); ++i) {
          const Index expectedCorners =
            (i == 0 || i + 1 == orderedFaces.size()) ? 3 : 4;
          if(faceCornerCount(orderedFaces[i]) != expectedCorners)
            return invalid;
          corners[i] = faceVertices(orderedFaces[i]);
          for(std::size_t j = 0; j < corners[i].size(); ++j)
            faceEdges[i].push_back(canonicalEdge(
              corners[i][j], corners[i][(j + 1) % corners[i].size()]));
        }

        Cavity disk;
        if(!buildDiskCavity(orderedFaces, disk) ||
           !disk.interiorVertices.empty())
          return invalid;

        std::set<Index> common(corners.front().begin(),
                               corners.front().end());
        for(std::size_t i = 1; i < corners.size(); ++i) {
          std::set<Index> next;
          for(const Index vertex : corners[i])
            if(common.find(vertex) != common.end()) next.insert(vertex);
          common.swap(next);
        }
        if(common.size() != 1) return invalid;
        const Index center = *common.begin();
        if(!isBoundaryVertex(center)) return invalid;

        for(std::size_t i = 0; i + 1 < orderedFaces.size(); ++i) {
          std::vector<Edge> sharedEdges;
          for(const Edge &edge : faceEdges[i])
            if(std::find(faceEdges[i + 1].begin(),
                         faceEdges[i + 1].end(), edge) !=
               faceEdges[i + 1].end())
              sharedEdges.push_back(edge);
          if(sharedEdges.size() != 1 ||
             (sharedEdges.front().first != center &&
              sharedEdges.front().second != center))
            return invalid;
          std::vector<Index> incidences = incidentFaces(sharedEdges.front());
          std::vector<Index> expected =
            {orderedFaces[i], orderedFaces[i + 1]};
          std::sort(expected.begin(), expected.end());
          if(incidences != expected) return invalid;
        }

        // Non-neighbors may meet at the fan center, and nowhere else.
        for(std::size_t i = 0; i < corners.size(); ++i)
          for(std::size_t j = i + 2; j < corners.size(); ++j)
            for(const Index vertex : corners[i])
              if(vertex != center &&
                 std::find(corners[j].begin(), corners[j].end(), vertex) !=
                   corners[j].end())
                return invalid;
        return center;
      }

      std::vector<Index> incidentFaces(const Edge &edge) const
      {
        std::vector<Index> result;
        const auto found = _edgeHalfEdges.find(edge);
        if(found == _edgeHalfEdges.end()) return result;
        for(const Index halfEdge : found->second)
          if(validHalfEdge(halfEdge))
            result.push_back(
              _halfEdges[static_cast<std::size_t>(halfEdge)].face);
        std::sort(result.begin(), result.end());
        result.erase(std::unique(result.begin(), result.end()), result.end());
        return result;
      }

      std::vector<Index> neighbors(Index faceIndex) const
      {
        std::vector<Index> result;
        if(!validFace(faceIndex)) return result;
        const Face &face = _faces[static_cast<std::size_t>(faceIndex)];
        for(Index i = 0; i < face.cornerCount; ++i) {
          const Index halfEdgeIndex = face.firstHalfEdge + i;
          if(!validHalfEdge(halfEdgeIndex)) continue;
          const Index twin =
            _halfEdges[static_cast<std::size_t>(halfEdgeIndex)].twin;
          if(validHalfEdge(twin))
            result.push_back(
              _halfEdges[static_cast<std::size_t>(twin)].face);
        }
        std::sort(result.begin(), result.end());
        result.erase(std::unique(result.begin(), result.end()), result.end());
        return result;
      }

      std::vector<EdgeFaces> edges() const
      {
        std::vector<EdgeFaces> result;
        result.reserve(_edgeHalfEdges.size());
        for(const auto &entry : _edgeHalfEdges) {
          EdgeFaces edge;
          edge.edge = entry.first;
          for(const Index halfEdge : entry.second)
            if(validHalfEdge(halfEdge))
              edge.faces.push_back(
                _halfEdges[static_cast<std::size_t>(halfEdge)].face);
          std::sort(edge.faces.begin(), edge.faces.end());
          edge.faces.erase(
            std::unique(edge.faces.begin(), edge.faces.end()),
            edge.faces.end());
          if(!edge.faces.empty()) result.push_back(std::move(edge));
        }
        return result;
      }

      std::size_t faceCount(std::size_t cornerCount) const
      {
        return cornerCount < _faceCounts.size() ?
          _faceCounts[cornerCount] : 0;
      }

      std::size_t quadDegree(Index vertex) const
      {
        std::size_t result = 0;
        for(const Index face : incidentFaces(vertex))
          if(_faces[static_cast<std::size_t>(face)].cornerCount == 4)
            ++result;
        return result;
      }

      bool isBoundaryVertex(Index vertex) const
      {
        if(!validVertex(vertex)) return false;
        for(const Index outgoingIndex :
            _outgoing[static_cast<std::size_t>(vertex)]) {
          if(!validHalfEdge(outgoingIndex)) continue;
          const HalfEdge &outgoing =
            _halfEdges[static_cast<std::size_t>(outgoingIndex)];
          if(outgoing.twin == invalid || !validHalfEdge(outgoing.previous) ||
             _halfEdges[static_cast<std::size_t>(outgoing.previous)].twin ==
               invalid)
            return true;
        }
        return false;
      }

      bool isInternalEdge(const Edge &input) const
      {
        const Edge edge = canonicalEdge(input.first, input.second);
        if(!validVertex(edge.first) || !validVertex(edge.second))
          return false;
        return incidentFaces(edge).size() == 2;
      }

      bool diskCavity(const std::vector<Index> &faces,
                      Cavity &result) const
      {
        return buildDiskCavity(faces, result);
      }

      bool vertexCavity(Index center, Cavity &result) const
      {
        result.clear();
        if(!validVertex(center)) return false;
        const std::vector<Index> star = incidentFaces(center);
        if(!buildDiskCavity(star, result)) return false;
        result.anchorFaces = incidentFaceRing(center);
        if(result.anchorFaces.size() != star.size()) {
          result.clear();
          return false;
        }
        result.anchor = CavityAnchor::Vertex;
        result.anchorFirst = center;
        result.anchorOnBoundary = isBoundaryVertex(center) ? 1 : 0;
        result.anchorVertices = {center};
        return true;
      }

      bool vertexStarsCavity(const std::vector<Index> &centers,
                             Cavity &result) const
      {
        result.clear();
        if(centers.empty()) return false;
        std::set<Index> uniqueCenters;
        std::set<Index> faces;
        bool boundary = false;
        for(const Index center : centers) {
          if(!validVertex(center) || !uniqueCenters.insert(center).second)
            return false;
          const std::vector<Index> star = incidentFaces(center);
          if(star.empty()) return false;
          faces.insert(star.begin(), star.end());
          boundary = boundary || isBoundaryVertex(center);
        }
        const std::vector<Index> support(faces.begin(), faces.end());
        if(!buildDiskCavity(support, result)) return false;
        result.anchor = centers.size() == 1 ?
          CavityAnchor::Vertex : CavityAnchor::VertexSet;
        result.anchorVertices.assign(uniqueCenters.begin(),
                                     uniqueCenters.end());
        result.anchorFirst = result.anchorVertices.front();
        result.anchorSecond = result.anchorVertices.size() == 2 ?
          result.anchorVertices.back() : invalid;
        result.anchorOnBoundary = boundary ? 1 : 0;
        if(result.anchorVertices.size() == 1)
          result.anchorFaces = incidentFaceRing(result.anchorFirst);
        return true;
      }

      bool edgeCavity(const Edge &input, Cavity &result) const
      {
        result.clear();
        const Edge edge = canonicalEdge(input.first, input.second);
        // Edge-anchored rewrite patterns are defined only on an internal
        // edge. The predicate is public as this is part of the pattern
        // contract, not an incidental consequence of disk construction.
        const std::vector<Index> incident = incidentFaces(edge);
        if(incident.size() != 2 || !buildDiskCavity(incident, result))
          return false;
        result.anchor = CavityAnchor::Edge;
        result.anchorFirst = edge.first;
        result.anchorSecond = edge.second;
        result.anchorOnBoundary = 0;
        result.anchorVertices = {edge.first, edge.second};
        result.anchorFaces = incident;
        return true;
      }

      bool singleQuadCavity(Index quadrangle, Cavity &result) const
      {
        result.clear();
        if(faceVertices(quadrangle).size() != 4 ||
           !buildDiskCavity({quadrangle}, result))
          return false;
        result.anchor = CavityAnchor::SingleQuadrangle;
        result.anchorFirst = quadrangle;
        result.anchorFaces = {quadrangle};
        return true;
      }

      bool extendByVertexStars(const Cavity &core,
                               const std::vector<Index> &vertices,
                               Cavity &result) const
      {
        result.clear();
        if(core.faces.empty() || core.coreFaces.empty() || vertices.empty())
          return false;
        std::set<Index> support(core.faces.begin(), core.faces.end());
        for(const Index vertex : vertices) {
          if(!validVertex(vertex)) return false;
          const std::vector<Index> star = incidentFaces(vertex);
          if(star.empty()) return false;
          support.insert(star.begin(), star.end());
        }
        const std::vector<Index> faces(support.begin(), support.end());
        Cavity extended;
        if(!buildDiskCavity(faces, extended)) return false;
        extended.anchor = core.anchor;
        extended.anchorFirst = core.anchorFirst;
        extended.anchorSecond = core.anchorSecond;
        extended.anchorOnBoundary = core.anchorOnBoundary;
        extended.anchorVertices = core.anchorVertices;
        extended.anchorFaces = core.anchorFaces;
        extended.coreFaces = core.coreFaces;
        result = std::move(extended);
        return true;
      }

      // Turn an already constructed support disk into a rewrite core while
      // retaining the numeric anchor that selected it.  Collectors use this
      // after adding rings (or C' temporarily) around a vertex, edge or
      // quadrangle; a CavitySeed must always describe the exact cells that a
      // transaction will replace, i.e. coreFaces == faces.
      bool promoteSupportToCore(const Cavity &support, Cavity &result) const
      {
        Cavity promoted;
        if(!buildDiskCavity(support.faces, promoted)) return false;
        promoted.anchor = support.anchor;
        promoted.anchorFirst = support.anchorFirst;
        promoted.anchorSecond = support.anchorSecond;
        promoted.anchorOnBoundary = support.anchorOnBoundary;
        promoted.anchorVertices = support.anchorVertices;
        promoted.anchorFaces = support.anchorFaces;
        result = std::move(promoted);
        return true;
      }

      // Cell-corner sequence attached to the cavity anchor. Values are 3 or
      // 4 for the mixed surface meshes supported by this optimizer.
      std::vector<Index> anchorFacePattern(const Cavity &cavity) const
      {
        std::vector<Index> result;
        result.reserve(cavity.anchorFaces.size());
        for(const Index face : cavity.anchorFaces) {
          const Index corners = faceCornerCount(face);
          if(corners != 3 && corners != 4) return {};
          result.push_back(corners);
        }
        return result;
      }

      std::size_t vertexStorageSize() const { return _vertices.size(); }
      std::size_t faceStorageSize() const { return _faces.size(); }
      std::size_t halfEdgeStorageSize() const { return _halfEdges.size(); }
    };

  } // namespace HalfEdgeMesh
} // namespace QuadOptimizer

#endif
