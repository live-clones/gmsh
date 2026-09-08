// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.

#pragma once

#include "halfEdgeMesh.h"

#include <cstdint>
#include <unordered_map>
#include <vector>

class GFace;
class MElement;
class MVertex;

namespace QuadOptimizer {

  // Persistent triangle/quad half-edge topology owned by one GFace
  // optimizer. Local algorithms exchange only Cavity objects; there is no
  // smoothing halo and no C' in this interface.
  class FaceHalfEdge {
  public:
    using Id = HalfEdgeMesh::Index;

    struct Cavity {
      std::vector<Id> cells;
      std::vector<Id> boundary;
      std::vector<Id> interior;

      bool empty() const { return cells.empty(); }
    };

    struct Edge {
      Id first = HalfEdgeMesh::invalid;
      Id second = HalfEdgeMesh::invalid;
      std::vector<Id> cells;
    };

    class PreparedReplacement {
      friend class FaceHalfEdge;
      const FaceHalfEdge *_owner = nullptr;
      std::uint64_t _revision = 0;
      Cavity _cavity;
      std::vector<MElement *> _elements;
      std::vector<MVertex *> _newVertices;
      std::vector<std::vector<Id> > _connectivity;
      HalfEdgeMesh::Mesh::PreparedReplacement _numeric;

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
          _cavity = std::move(other._cavity);
          _elements = std::move(other._elements);
          _newVertices = std::move(other._newVertices);
          _connectivity = std::move(other._connectivity);
          _numeric = std::move(other._numeric);
        }
        return *this;
      }
    };

    explicit FaceHalfEdge(GFace *face, bool splitFixedBoundaryFans = false);
    FaceHalfEdge(const FaceHalfEdge &) = delete;
    FaceHalfEdge &operator=(const FaceHalfEdge &) = delete;

    bool valid() const;
    GFace *face() const { return _face; }
    std::uint64_t revision() const { return _revision; }

    std::vector<Id> cells() const;
    std::vector<Id> vertices() const;
    std::vector<Edge> edges() const;
    std::vector<Id> incidentCells(Id vertex) const;
    std::vector<Id> incidentCellRing(Id vertex) const;
    std::vector<Id> neighbors(Id cell) const;
    std::vector<Id> cellVertices(Id cell) const;
    std::size_t cornerCount(Id cell) const;
    std::size_t quadDegree(Id vertex) const;
    bool isBoundaryVertex(Id vertex) const;

    Id id(MVertex *vertex) const;
    Id id(MElement *element) const;
    MVertex *vertex(Id id) const;
    MElement *element(Id id) const;

    bool cavity(const std::vector<Id> &cells, Cavity &result) const;
    bool vertexCavity(Id vertex, Cavity &result) const;
    bool edgeCavity(Id first, Id second, Cavity &result) const;

    // Check and atomically install a replacement of C. `inserted` must own
    // no pointer already present in the GFace. The caller retains ownership
    // on failure and transfers it on success. New vertices are discovered
    // directly in the inserted cells; obsolete interior face vertices are
    // retired automatically.
    bool canReplace(const Cavity &cavity,
                    const std::vector<MElement *> &inserted) const;
    // The caller keeps the candidate alive and unchanged while holding its
    // proof. Commit consumes the proof and transfers those exact elements;
    // any intervening topology/geometry synchronization invalidates it.
    bool prepareReplacement(const Cavity &cavity,
                            const std::vector<MElement *> &inserted,
                            PreparedReplacement &prepared) const;
    bool replace(PreparedReplacement &prepared,
                 std::vector<MVertex *> *created = nullptr,
                 std::vector<MVertex *> *retired = nullptr);
    bool replace(const Cavity &cavity,
                 const std::vector<MElement *> &inserted,
                 std::vector<MVertex *> *created = nullptr,
                 std::vector<MVertex *> *retired = nullptr);

    // Geometry changes do not rebuild connectivity. They only update the
    // numeric point and revision stamps used by the rejected-cavity cache.
    bool synchronizeGeometry(const std::vector<MVertex *> &vertices);
    std::uint64_t state(const Cavity &cavity) const;
    const std::vector<Id> &lastTouchedVertices() const
    { return _lastTouchedVertices; }
    const std::vector<Id> &lastCreatedCells() const
    { return _lastCreatedCells; }

  private:
    GFace *_face = nullptr;
    HalfEdgeMesh::Mesh _mesh;
    std::vector<MVertex *> _vertices;
    std::vector<MElement *> _elements;
    std::unordered_map<MVertex *, Id> _vertexIds;
    std::unordered_map<MElement *, Id> _elementIds;
    std::vector<std::size_t> _elementPositions;
    std::unordered_map<MVertex *, std::size_t> _meshVertexPositions;
    std::vector<std::uint64_t> _vertexRevisions;
    std::vector<Id> _lastTouchedVertices;
    std::vector<Id> _lastCreatedCells;
    std::uint64_t _revision = 0;
    bool _valid = true;

    Id addVertex(MVertex *vertex);
    bool addElement(MElement *element,
                    const std::unordered_map<MVertex *, Id> *corners = nullptr);
    bool orientedBoundaryMatches(
      const Cavity &cavity,
      const std::vector<std::vector<Id> > &inserted) const;
  };

} // namespace QuadOptimizer
