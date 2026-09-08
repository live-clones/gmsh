// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.

#include "halfEdge.h"

#include "GFace.h"
#include "MElement.h"
#include "MQuadrangle.h"
#include "MTriangle.h"
#include "MVertex.h"

#include <algorithm>
#include <array>
#include <map>
#include <set>
#include <utility>

namespace QuadOptimizer {
  namespace {
    using Id = FaceHalfEdge::Id;
    using DirectedEdge = std::pair<Id, Id>;

    std::vector<MElement *> faceElements(GFace *face)
    {
      std::vector<MElement *> result;
      if(!face) return result;
      result.reserve(face->triangles.size() + face->quadrangles.size());
      result.insert(result.end(), face->triangles.begin(),
                    face->triangles.end());
      result.insert(result.end(), face->quadrangles.begin(),
                    face->quadrangles.end());
      return result;
    }

    bool uniquePointers(const std::vector<MElement *> &elements)
    {
      std::set<MElement *> unique;
      for(MElement *element : elements)
        if(!element || !unique.insert(element).second) return false;
      return true;
    }

    std::vector<DirectedEdge> boundaryOf(
      const std::vector<std::vector<Id> > &cells)
    {
      std::map<HalfEdgeMesh::Edge, std::vector<DirectedEdge> > incidences;
      for(const std::vector<Id> &cell : cells) {
        if(cell.size() != 3 && cell.size() != 4) return {};
        for(std::size_t i = 0; i < cell.size(); ++i) {
          const Id a = cell[i];
          const Id b = cell[(i + 1) % cell.size()];
          incidences[HalfEdgeMesh::canonicalEdge(a, b)].push_back({a, b});
        }
      }
      std::vector<DirectedEdge> result;
      for(const auto &entry : incidences) {
        if(entry.second.size() == 1)
          result.push_back(entry.second.front());
        else if(entry.second.size() != 2 ||
                entry.second[0].first != entry.second[1].second ||
                entry.second[0].second != entry.second[1].first)
          return {};
      }
      std::sort(result.begin(), result.end());
      return result;
    }

  } // namespace

  FaceHalfEdge::FaceHalfEdge(GFace *face, bool splitFixedBoundaryFans) : _face(face)
  {
    if(face)
      for(std::size_t i = 0; i < face->mesh_vertices.size(); ++i)
        _meshVertexPositions.emplace(face->mesh_vertices[i], i);
    const auto elements = faceElements(face);
    std::unordered_map<MElement *, std::unordered_map<MVertex *, Id> > corners;
    if(splitFixedBoundaryFans) {
      // A trimmed face can touch itself at a fixed CAD point. Its incident
      // fans have distinct numerical boundary vertices but retain the exact
      // same fixed Gmsh vertex. No mesh node is duplicated or moved here.
      std::map<MVertex *, std::vector<MElement *> > stars;
      for(MElement *element : elements)
        for(std::size_t i = 0; i < element->getNumPrimaryVertices(); ++i) {
          MVertex *v = element->getVertex(i);
          if(v && v->onWhat() && v->onWhat()->dim() < 2) stars[v].push_back(element);
        }
      for(const auto &star : stars) {
        MVertex *center = star.first;
        std::map<MVertex *, std::vector<MElement *> > spokes;
        for(MElement *element : star.second) {
          const std::size_t count = element->getNumPrimaryVertices();
          for(std::size_t i = 0; i < count; ++i)
            if(element->getVertex(i) == center) {
              spokes[element->getVertex((i + 1) % count)].push_back(element);
              spokes[element->getVertex((i + count - 1) % count)].push_back(element);
            }
        }
        std::map<MElement *, std::vector<MElement *> > neighbors;
        for(const auto &spoke : spokes)
          if(spoke.second.size() == 2) {
            neighbors[spoke.second[0]].push_back(spoke.second[1]);
            neighbors[spoke.second[1]].push_back(spoke.second[0]);
          }
        std::set<MElement *> seen;
        std::vector<std::vector<MElement *> > fans;
        for(MElement *seed : star.second) {
          if(seen.count(seed)) continue;
          fans.emplace_back();
          std::vector<MElement *> todo{seed};
          while(!todo.empty()) {
            MElement *element = todo.back(); todo.pop_back();
            if(!seen.insert(element).second) continue;
            fans.back().push_back(element);
            for(MElement *other : neighbors[element]) todo.push_back(other);
          }
        }
        if(fans.size() < 2) continue;
        for(std::size_t i = 0; i < fans.size(); ++i) {
          Id vertexId;
          if(i == 0) vertexId = addVertex(center);
          else {
            vertexId = _mesh.addVertex({{center->x(), center->y(), center->z()}});
            _vertices.push_back(center);
            _vertexRevisions.push_back(++_revision);
          }
          for(MElement *element : fans[i]) corners[element][center] = vertexId;
        }
      }
    }
    for(MElement *element : elements)
      if(!addElement(element, corners.count(element) ? &corners.at(element) : nullptr)) {
        _valid = false;
        break;
      }
    _valid = _valid && _mesh.manifold();
    if(_valid && face) {
      for(std::size_t i = 0; i < face->triangles.size(); ++i)
        _elementPositions[static_cast<std::size_t>(id(face->triangles[i]))] = i;
      for(std::size_t i = 0; i < face->quadrangles.size(); ++i)
        _elementPositions[static_cast<std::size_t>(id(face->quadrangles[i]))] = i;
    }
  }

  bool FaceHalfEdge::valid() const
  {
    return _face && _valid && _mesh.manifold();
  }

  FaceHalfEdge::Id FaceHalfEdge::addVertex(MVertex *vertex)
  {
    if(!vertex) return HalfEdgeMesh::invalid;
    const auto known = _vertexIds.find(vertex);
    if(known != _vertexIds.end()) return known->second;
    const Id result = _mesh.addVertex(
      {{vertex->x(), vertex->y(), vertex->z()}});
    if(result == HalfEdgeMesh::invalid ||
       static_cast<std::size_t>(result) != _vertices.size())
      return HalfEdgeMesh::invalid;
    _vertices.push_back(vertex);
    _vertexIds.emplace(vertex, result);
    _vertexRevisions.push_back(++_revision);
    return result;
  }

  bool FaceHalfEdge::addElement(
    MElement *element, const std::unordered_map<MVertex *, Id> *corners)
  {
    if(!element || _elementIds.find(element) != _elementIds.end())
      return false;
    const std::size_t count = element->getNumPrimaryVertices();
    if(count != 3 && count != 4) return false;
    std::vector<Id> vertices;
    std::set<Id> unique;
    vertices.reserve(count);
    for(std::size_t i = 0; i < count; ++i) {
      MVertex *handle = element->getVertex(static_cast<int>(i));
      const Id vertexId = corners && corners->count(handle) ?
        corners->at(handle) : addVertex(handle);
      if(vertexId == HalfEdgeMesh::invalid ||
         !unique.insert(vertexId).second)
        return false;
      vertices.push_back(vertexId);
    }
    const Id result = _mesh.addFace(vertices);
    if(result == HalfEdgeMesh::invalid ||
       static_cast<std::size_t>(result) != _elements.size())
      return false;
    _elements.push_back(element);
    _elementPositions.push_back(0);
    _elementIds.emplace(element, result);
    ++_revision;
    return true;
  }

  std::vector<FaceHalfEdge::Id> FaceHalfEdge::cells() const
  {
    return _mesh.faces();
  }

  std::vector<FaceHalfEdge::Id> FaceHalfEdge::vertices() const
  {
    return _mesh.vertices();
  }

  std::vector<FaceHalfEdge::Edge> FaceHalfEdge::edges() const
  {
    std::vector<Edge> result;
    for(const HalfEdgeMesh::EdgeFaces &edge : _mesh.edges())
      result.push_back({edge.edge.first, edge.edge.second, edge.faces});
    return result;
  }

  std::vector<FaceHalfEdge::Id>
  FaceHalfEdge::incidentCells(Id vertex) const
  {
    return _mesh.incidentFaces(vertex);
  }

  std::vector<FaceHalfEdge::Id>
  FaceHalfEdge::incidentCellRing(Id vertex) const
  {
    return _mesh.incidentFaceRing(vertex);
  }

  std::vector<FaceHalfEdge::Id> FaceHalfEdge::neighbors(Id cell) const
  {
    return _mesh.neighbors(cell);
  }

  std::vector<FaceHalfEdge::Id> FaceHalfEdge::cellVertices(Id cell) const
  {
    return _mesh.faceVertices(cell);
  }

  std::size_t FaceHalfEdge::cornerCount(Id cell) const
  {
    return static_cast<std::size_t>(_mesh.faceCornerCount(cell));
  }

  std::size_t FaceHalfEdge::quadDegree(Id vertex) const
  {
    return _mesh.quadDegree(vertex);
  }

  bool FaceHalfEdge::isBoundaryVertex(Id vertex) const
  {
    return _mesh.isBoundaryVertex(vertex);
  }

  FaceHalfEdge::Id FaceHalfEdge::id(MVertex *vertex) const
  {
    const auto found = _vertexIds.find(vertex);
    return found == _vertexIds.end() ? HalfEdgeMesh::invalid : found->second;
  }

  FaceHalfEdge::Id FaceHalfEdge::id(MElement *element) const
  {
    const auto found = _elementIds.find(element);
    return found == _elementIds.end() ? HalfEdgeMesh::invalid : found->second;
  }

  MVertex *FaceHalfEdge::vertex(Id vertexId) const
  {
    return vertexId >= 0 &&
        static_cast<std::size_t>(vertexId) < _vertices.size() ?
      _vertices[static_cast<std::size_t>(vertexId)] : nullptr;
  }

  MElement *FaceHalfEdge::element(Id cellId) const
  {
    return cellId >= 0 &&
        static_cast<std::size_t>(cellId) < _elements.size() ?
      _elements[static_cast<std::size_t>(cellId)] : nullptr;
  }

  bool FaceHalfEdge::cavity(const std::vector<Id> &cellIds,
                            Cavity &result) const
  {
    HalfEdgeMesh::Cavity numeric;
    if(!_mesh.diskCavity(cellIds, numeric)) return false;
    result.cells = numeric.faces;
    result.boundary = numeric.boundaryVertices;
    result.interior = numeric.interiorVertices;
    return true;
  }

  bool FaceHalfEdge::vertexCavity(Id vertexId, Cavity &result) const
  {
    HalfEdgeMesh::Cavity numeric;
    if(!_mesh.vertexCavity(vertexId, numeric)) return false;
    result.cells = numeric.faces;
    result.boundary = numeric.boundaryVertices;
    result.interior = numeric.interiorVertices;
    return true;
  }

  bool FaceHalfEdge::edgeCavity(Id first, Id second, Cavity &result) const
  {
    HalfEdgeMesh::Cavity numeric;
    if(!_mesh.edgeCavity(HalfEdgeMesh::canonicalEdge(first, second), numeric))
      return false;
    result.cells = numeric.faces;
    result.boundary = numeric.boundaryVertices;
    result.interior = numeric.interiorVertices;
    return true;
  }

  bool FaceHalfEdge::orientedBoundaryMatches(
    const Cavity &cavity,
    const std::vector<std::vector<Id> > &inserted) const
  {
    std::vector<std::vector<Id> > removed;
    removed.reserve(cavity.cells.size());
    for(const Id cell : cavity.cells) {
      const std::vector<Id> vertices = _mesh.faceVertices(cell);
      if(vertices.empty()) return false;
      removed.push_back(vertices);
    }
    const std::vector<DirectedEdge> before = boundaryOf(removed);
    const std::vector<DirectedEdge> after = boundaryOf(inserted);
    return !before.empty() && before == after;
  }

  bool FaceHalfEdge::canReplace(
    const Cavity &cavity,
    const std::vector<MElement *> &insertedElements) const
  {
    PreparedReplacement prepared;
    return prepareReplacement(cavity, insertedElements, prepared);
  }

  bool FaceHalfEdge::prepareReplacement(
    const Cavity &cavity,
    const std::vector<MElement *> &insertedElements,
    PreparedReplacement &result) const
  {
    result = PreparedReplacement();
    if(!valid() || cavity.empty() || insertedElements.empty() ||
       !uniquePointers(insertedElements))
      return false;
    std::set<Id> removed(cavity.cells.begin(), cavity.cells.end());
    if(removed.size() != cavity.cells.size()) return false;

    PreparedReplacement prepared;
    // Resolve a shared fixed CAD handle within this cavity's own fan.
    std::unordered_map<MVertex *, Id> cavityIds;
    for(Id cell : cavity.cells)
      for(Id corner : cellVertices(cell)) {
        const auto inserted = cavityIds.emplace(vertex(corner), corner);
        if(!inserted.second && inserted.first->second != corner) return false;
      }
    std::unordered_map<MVertex *, Id> virtualIds;
    Id next = static_cast<Id>(_mesh.vertexStorageSize());
    auto &inserted = prepared._connectivity;
    inserted.reserve(insertedElements.size());
    for(MElement *element : insertedElements) {
      if(!element || _elementIds.find(element) != _elementIds.end())
        return false;
      const std::size_t count = element->getNumPrimaryVertices();
      if(count != 3 && count != 4) return false;
      std::vector<Id> cell;
      std::set<Id> unique;
      for(std::size_t i = 0; i < count; ++i) {
        MVertex *handle = element->getVertex(static_cast<int>(i));
        if(!handle) return false;
        const auto cavityCorner = cavityIds.find(handle);
        Id vertexId = cavityCorner != cavityIds.end() ? cavityCorner->second : id(handle);
        if(vertexId == HalfEdgeMesh::invalid) {
          const auto known = virtualIds.find(handle);
          if(known == virtualIds.end()) {
            if(next == std::numeric_limits<Id>::max()) return false;
            vertexId = next++;
            virtualIds.emplace(handle, vertexId);
            prepared._newVertices.push_back(handle);
          }
          else
            vertexId = known->second;
        }
        if(!unique.insert(vertexId).second) return false;
        cell.push_back(vertexId);
      }
      inserted.push_back(std::move(cell));
    }
    if(!orientedBoundaryMatches(cavity, inserted) ||
       !_mesh.prepareReplacement(cavity.cells, inserted, prepared._numeric))
      return false;
    prepared._owner = this;
    prepared._revision = _revision;
    prepared._cavity = cavity;
    prepared._elements = insertedElements;
    result = std::move(prepared);
    return true;
  }

  bool FaceHalfEdge::replace(const Cavity &cavity,
                             const std::vector<MElement *> &insertedElements,
                             std::vector<MVertex *> *createdResult,
                             std::vector<MVertex *> *retiredResult)
  {
    if(createdResult) createdResult->clear();
    if(retiredResult) retiredResult->clear();
    PreparedReplacement prepared;
    return prepareReplacement(cavity, insertedElements, prepared) &&
      replace(prepared, createdResult, retiredResult);
  }

  bool FaceHalfEdge::replace(PreparedReplacement &prepared,
                             std::vector<MVertex *> *createdResult,
                             std::vector<MVertex *> *retiredResult)
  {
    if(createdResult) createdResult->clear();
    if(retiredResult) retiredResult->clear();
    if(prepared._owner != this || prepared._revision != _revision)
      return false;
    const Cavity &cavity = prepared._cavity;
    const auto &insertedElements = prepared._elements;
    const auto &created = prepared._newVertices;
    const std::size_t vertexBase = _vertices.size();
    const std::size_t cellBase = _elements.size();

    std::vector<MElement *> removedElements;
    removedElements.reserve(cavity.cells.size());
    std::vector<Id> touched;
    for(const Id cell : cavity.cells) {
      MElement *handle = element(cell);
      if(!handle) return false;
      const std::size_t position = _elementPositions[static_cast<std::size_t>(cell)];
      // GFace arrays are unordered containers (meshGRegion sorts them on
      // demand). Detect an external reorder while this adapter is alive.
      if(handle->getNumPrimaryVertices() == 3) {
        if(position >= _face->triangles.size() ||
           _face->triangles[position] != handle) return false;
      }
      else if(position >= _face->quadrangles.size() ||
              _face->quadrangles[position] != handle) return false;
      removedElements.push_back(handle);
      const auto vertices = _mesh.faceVertices(cell);
      touched.insert(touched.end(), vertices.begin(), vertices.end());
    }
    std::set<Id> retainedVertices;
    for(const auto &cell : prepared._connectivity) {
      touched.insert(touched.end(), cell.begin(), cell.end());
      retainedVertices.insert(cell.begin(), cell.end());
    }
    std::sort(touched.begin(), touched.end());
    touched.erase(std::unique(touched.begin(), touched.end()), touched.end());
    std::vector<Id> retiredIds;
    std::vector<MVertex *> retired;
    const std::set<Id> removedIds(cavity.cells.begin(), cavity.cells.end());
    for(const Id vertexId : cavity.interior) {
      if(retainedVertices.count(vertexId)) continue;
      MVertex *handle = vertex(vertexId);
      if(!handle) return false;
      bool isolated = true;
      for(const Id cell : _mesh.incidentFaces(vertexId))
        if(!removedIds.count(cell)) isolated = false;
      if(!isolated) continue;
      retiredIds.push_back(vertexId);
      if(handle->onWhat() == _face && _meshVertexPositions.count(handle))
        retired.push_back(handle);
    }

    std::unordered_map<MVertex *, Id> newVertexIds;
    std::unordered_map<MElement *, Id> newElementIds;
    std::unordered_map<MVertex *, std::size_t> newVertexPositions;
    std::vector<MVertex *> attached;
    for(std::size_t i = 0; i < created.size(); ++i) {
      newVertexIds.emplace(created[i], static_cast<Id>(vertexBase + i));
      if(!_meshVertexPositions.count(created[i])) {
        newVertexPositions.emplace(created[i],
                                   _face->mesh_vertices.size() + attached.size());
        attached.push_back(created[i]);
      }
    }
    std::size_t triangles = 0, quadrangles = 0;
    for(std::size_t i = 0; i < insertedElements.size(); ++i) {
      newElementIds.emplace(insertedElements[i], static_cast<Id>(cellBase + i));
      if(insertedElements[i]->getNumPrimaryVertices() == 3) ++triangles;
      else ++quadrangles;
    }
    using HalfEdgeMesh::reserveGeometrically;
    reserveGeometrically(_vertices, vertexBase + created.size());
    reserveGeometrically(_vertexRevisions, vertexBase + created.size());
    reserveGeometrically(_elements, cellBase + insertedElements.size());
    reserveGeometrically(_elementPositions, cellBase + insertedElements.size());
    reserveGeometrically(_face->mesh_vertices,
                         _face->mesh_vertices.size() + attached.size());
    reserveGeometrically(_face->triangles, _face->triangles.size() + triangles);
    reserveGeometrically(_face->quadrangles,
                         _face->quadrangles.size() + quadrangles);
    _vertexIds.reserve(_vertexIds.size() + newVertexIds.size());
    _elementIds.reserve(_elementIds.size() + newElementIds.size());
    _meshVertexPositions.reserve(_meshVertexPositions.size() +
                                newVertexPositions.size());
    if(createdResult) createdResult->reserve(created.size());
    if(retiredResult) retiredResult->reserve(retired.size());

    // Transfer already allocated hash nodes before the numeric commit.
    // Any failure while staging the numeric patch rolls back these entries
    // and the uncommitted vertex tail; the caller still owns the candidate.
    const auto rollback = [&]() {
      for(MVertex *handle : created) _vertexIds.erase(handle);
      for(MElement *handle : insertedElements) _elementIds.erase(handle);
      for(MVertex *handle : attached) _meshVertexPositions.erase(handle);
      _vertices.resize(vertexBase);
      _vertexRevisions.resize(vertexBase);
      _mesh.discardIsolatedVertexTail(vertexBase);
    };
    std::vector<Id> insertedIds;
    try {
      _vertexIds.merge(newVertexIds);
      _elementIds.merge(newElementIds);
      _meshVertexPositions.merge(newVertexPositions);
      for(MVertex *handle : created) {
        const Id vertexId = _mesh.addVertex({{handle->x(), handle->y(), handle->z()}});
        if(vertexId != static_cast<Id>(_vertices.size())) {
          rollback();
          return false;
        }
        _vertices.push_back(handle);
        _vertexRevisions.push_back(_revision);
      }
      if(!_mesh.replace(prepared._numeric, &insertedIds)) {
        rollback();
        return false;
      }
    }
    catch(...) {
      rollback();
      throw;
    }

    // All ownership updates are allocation-free. Element positions permit
    // constant-time erasure without shifting a whole GFace vector.
    const auto eraseElement = [&](auto &values, std::size_t position) {
      MElement *last = values.back();
      values[position] = values.back();
      _elementPositions[static_cast<std::size_t>(_elementIds.find(last)->second)] =
        position;
      values.pop_back();
    };
    for(std::size_t i = 0; i < cavity.cells.size(); ++i) {
      const Id cell = cavity.cells[i];
      const std::size_t position = _elementPositions[static_cast<std::size_t>(cell)];
      if(removedElements[i]->getNumPrimaryVertices() == 3)
        eraseElement(_face->triangles, position);
      else
        eraseElement(_face->quadrangles, position);
      _elementIds.erase(removedElements[i]);
      _elements[static_cast<std::size_t>(cell)] = nullptr;
    }
    for(MElement *handle : insertedElements) {
      _elements.push_back(handle);
      if(handle->getNumPrimaryVertices() == 3) {
        _elementPositions.push_back(_face->triangles.size());
        _face->triangles.push_back(static_cast<MTriangle *>(handle));
      }
      else {
        _elementPositions.push_back(_face->quadrangles.size());
        _face->quadrangles.push_back(static_cast<MQuadrangle *>(handle));
      }
    }
    for(MVertex *handle : attached) _face->mesh_vertices.push_back(handle);
    for(const Id vertexId : retiredIds) {
      MVertex *handle = vertex(vertexId);
      _mesh.retireIsolatedVertex(vertexId);
      _vertexIds.erase(handle);
      _vertices[static_cast<std::size_t>(vertexId)] = nullptr;
    }
    for(MVertex *handle : retired) {
      const auto found = _meshVertexPositions.find(handle);
      const std::size_t position = found->second;
      MVertex *last = _face->mesh_vertices.back();
      _face->mesh_vertices[position] = last;
      _meshVertexPositions.find(last)->second = position;
      _face->mesh_vertices.pop_back();
      _meshVertexPositions.erase(found);
    }
    for(const Id vertexId : touched)
      _vertexRevisions[static_cast<std::size_t>(vertexId)] = ++_revision;
    ++_revision;
    _lastTouchedVertices = std::move(touched);
    _lastCreatedCells = std::move(insertedIds);
    prepared._owner = nullptr;
    for(MElement *handle : removedElements) delete handle;
    for(MVertex *handle : retired) delete handle;
    if(createdResult) createdResult->assign(created.begin(), created.end());
    if(retiredResult) retiredResult->assign(retired.begin(), retired.end());
    return true;
  }

  bool FaceHalfEdge::synchronizeGeometry(
    const std::vector<MVertex *> &changedVertices)
  {
    if(!valid()) return false;
    std::set<Id> unique;
    for(MVertex *handle : changedVertices) {
      const Id vertexId = id(handle);
      if(vertexId == HalfEdgeMesh::invalid ||
         !_mesh.vertexPosition(vertexId)) return false;
      unique.insert(vertexId);
    }
    std::vector<Id> touched(unique.begin(), unique.end());
    for(const Id vertexId : touched) {
      MVertex *handle = vertex(vertexId);
      _mesh.setVertexPosition(vertexId,
                              {{handle->x(), handle->y(), handle->z()}});
      _vertexRevisions[static_cast<std::size_t>(vertexId)] = ++_revision;
    }
    _lastTouchedVertices = std::move(touched);
    _lastCreatedCells.clear();
    return true;
  }

  std::uint64_t FaceHalfEdge::state(const Cavity &cavity) const
  {
    // FNV-1a over stable cell connectivity and local geometry revisions.
    std::uint64_t hash = 1469598103934665603ull;
    const auto add = [&](std::uint64_t value, std::uint64_t &target) {
      target ^= value;
      target *= 1099511628211ull;
    };
    for(const Id cell : cavity.cells) {
      add(static_cast<std::uint64_t>(cell), hash);
      for(const Id vertexId : _mesh.faceVertices(cell)) {
        add(static_cast<std::uint64_t>(vertexId), hash);
        if(vertexId >= 0 && static_cast<std::size_t>(vertexId) <
                              _vertexRevisions.size())
          add(_vertexRevisions[static_cast<std::size_t>(vertexId)], hash);
      }
    }
    return hash;
  }

} // namespace QuadOptimizer
