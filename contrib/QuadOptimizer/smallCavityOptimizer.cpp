// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.

#include "smallCavityOptimizer.h"

#include "BackgroundMeshTools.h"
#include "Field.h"
#include "GEdge.h"
#include "GFace.h"
#include "GPoint.h"
#include "GModel.h"
#include "GVertex.h"
#include "GmshMessage.h"
#include "MElement.h"
#include "MLine.h"
#include "MQuadrangle.h"
#include "MTriangle.h"
#include "MVertex.h"
#include "meshGFaceOptimize.h"
#include "qmtDiskQuadrangulationRemeshing.h"
#include "qmtMeshUtils.h"

#include <algorithm>
#include <array>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <limits>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <unordered_map>
#include <utility>
#include <vector>

#if defined(_OPENMP)
#include <omp.h>
#endif

namespace QuadOptimizer {
  namespace {

    using UV = std::array<double, 2>;
    using Point = std::array<double, 3>;
    using Pattern = std::vector<std::array<std::size_t, 4> >;
    using ConnectivitySignature =
      std::vector<std::array<std::size_t, 4> >;
    using Adjacency = std::unordered_map<MVertex *, std::vector<MElement *> >;
    using Edge = std::pair<MVertex *, MVertex *>;

    Edge canonicalEdge(MVertex *a, MVertex *b)
    {
      if(std::less<MVertex *>()(b, a)) std::swap(a, b);
      return {a, b};
    }

    bool persistentFaceParameter(GFace *face, MVertex *vertex,
                                 SPoint2 &parameter)
    {
      if(!face || !vertex) return false;
      // UV values cached on a discrete-face MVertex are optional MSH data.
      // Always invert the persistent XYZ coordinates so every cleanup branch
      // sees exactly the same parameter after save/reload.
      if(face->geomType() == GEntity::DiscreteSurface)
        parameter = face->parFromPoint(vertex->point(), true, true);
      else if(!reparamMeshVertexOnFace(vertex, face, parameter, true))
        return false;
      return std::isfinite(parameter.x()) &&
             std::isfinite(parameter.y());
    }

    std::vector<SPoint2> persistentElementParameters(
      GFace *face, MElement *element)
    {
      if(!face || !element) return {};
      if(face->geomType() != GEntity::DiscreteSurface)
        return paramOnElement(face, element);
      const std::size_t count = element->getNumPrimaryVertices();
      std::vector<SPoint2> parameters(count);
      for(std::size_t i = 0; i < count; ++i)
        if(!persistentFaceParameter(
             face, element->getVertex(static_cast<int>(i)), parameters[i]))
          return {};
      return parameters;
    }

    // Quiet parameter recovery for the reporting path. paramOnElement() is
    // useful to the mesher, but it can emit Msg::Error when its center
    // projection fails; a read-only quality query must report that element as
    // unauditable without changing the process-wide error count.
    std::vector<SPoint2> auditElementParameters(
      GFace *face, MElement *element)
    {
      if(!face || !element) return {};
      const std::size_t count = element->getNumPrimaryVertices();
      if(count != 3 && count != 4) return {};
      std::vector<SPoint2> parameters(count);
      if(face->geomType() == GEntity::DiscreteSurface) {
        for(std::size_t i = 0; i < count; ++i)
          if(!persistentFaceParameter(
               face, element->getVertex(static_cast<int>(i)), parameters[i]))
            return {};
        return parameters;
      }

      std::size_t anchor = count;
      for(std::size_t i = 0; i < count; ++i) {
        MVertex *vertex = element->getVertex(static_cast<int>(i));
        if(vertex && vertex->onWhat() == face) {
          double u = 0., v = 0.;
          vertex->getParameter(0, u);
          vertex->getParameter(1, v);
          if(std::isfinite(u) && std::isfinite(v)) {
            anchor = i;
            parameters[i] = SPoint2(u, v);
            break;
          }
        }
      }

      SPoint2 reference;
      if(anchor < count)
        reference = parameters[anchor];
      else {
        const double initialGuess[2] = {0., 0.};
        const GPoint projection = face->closestPoint(
          element->barycenter(), initialGuess);
        if(!projection.succeeded() || !std::isfinite(projection.u()) ||
           !std::isfinite(projection.v()))
          return {};
        reference = SPoint2(projection.u(), projection.v());
        anchor = 0;
        if(!reparamMeshVertexOnFaceWithRef(
             face, element->getVertex(0), reference, parameters[0]))
          return {};
        reference = parameters[0];
      }

      for(std::size_t offset = 1; offset < count; ++offset) {
        const std::size_t i = (anchor + offset) % count;
        if(!reparamMeshVertexOnFaceWithRef(
             face, element->getVertex(static_cast<int>(i)), reference,
             parameters[i]) || !std::isfinite(parameters[i].x()) ||
           !std::isfinite(parameters[i].y()))
          return {};
        reference = parameters[i];
      }
      return parameters;
    }

    std::array<double, 8> canonicalVertexGeometryKey(MVertex *vertex)
    {
      std::array<double, 8> value = {
        0., 0., 0., -1., -1., 0., 0., 0.};
      if(!vertex) return value;
      // The parametric coordinates of discrete-surface vertices are not
      // necessarily serialized in a .msh file.  A canonical order based on
      // them would consequently change after a save/reload cycle.  Physical
      // coordinates and classification are persistent and are all that is
      // needed to make geometrically distinct vertices deterministic.
      value[0] = std::isfinite(vertex->x()) ? vertex->x() : 0.;
      value[1] = std::isfinite(vertex->y()) ? vertex->y() : 0.;
      value[2] = std::isfinite(vertex->z()) ? vertex->z() : 0.;
      value[3] = vertex->onWhat() ? vertex->onWhat()->dim() : -1.;
      value[4] = vertex->onWhat() ? vertex->onWhat()->tag() : -1.;
      return value;
    }

    bool canonicalVertexGeometryLess(MVertex *a, MVertex *b)
    {
      const std::array<double, 8> ka = canonicalVertexGeometryKey(a);
      const std::array<double, 8> kb = canonicalVertexGeometryKey(b);
      if(ka != kb) return ka < kb;
      // Geometrically coincident vertices are already ambiguous to the
      // physical optimizer. Keep a strict final tie-breaker for the in-memory
      // state; ordinary distinct vertices never reach it.
      return a && b ? a->getNum() < b->getNum() :
                      std::less<MVertex *>()(a, b);
    }

    void canonicalizePatchVertexOrder(GFaceMeshPatch &patch)
    {
      std::stable_sort(
        patch.intVertices.begin(), patch.intVertices.end(),
        canonicalVertexGeometryLess);

      auto sequenceLess = [](const std::vector<MVertex *> &a,
                             const std::vector<MVertex *> &b) {
        return std::lexicographical_compare(
          a.begin(), a.end(), b.begin(), b.end(),
          canonicalVertexGeometryLess);
      };
      for(std::vector<MVertex *> &loop : patch.bdrVertices) {
        if(loop.size() < 2) continue;
        std::vector<MVertex *> best;
        best.reserve(loop.size());
        for(bool reflected : {false, true})
          for(std::size_t rotation = 0; rotation < loop.size(); ++rotation) {
            std::vector<MVertex *> candidate(loop.size());
            for(std::size_t i = 0; i < loop.size(); ++i) {
              const std::size_t index = reflected ?
                (rotation + loop.size() - i) % loop.size() :
                (rotation + i) % loop.size();
              candidate[i] = loop[index];
            }
            if(best.empty() || sequenceLess(candidate, best))
              best = std::move(candidate);
          }
        loop = std::move(best);
      }
    }

    bool canonicalPatchFromElements(
      GFace *face, const std::vector<MElement *> &elements,
      GFaceMeshPatch &patch)
    {
      if(!patchFromElements(face, elements, patch)) return false;
      canonicalizePatchVertexOrder(patch);
      return true;
    }

    enum class CavityKind {
      Node,
      Edge,
      Triangle,
      Quadrangle,
      CleanUpConnectivity,
      CleanUpBoundary,
      CleanUpShape,
      CleanUpSize
    };

    struct ValenceObjective {
      std::size_t severeCount = 0;
      std::size_t irregularCount = 0;
      double penalty = 0.;
    };

    struct CavitySeed {
      GFaceMeshPatch patch;
      std::size_t interiorVertexCount = 0;
      bool alwaysTryTopology = false;
      CavityKind kind = CavityKind::Node;
      SpecificationObjective objective;
      ValenceObjective valence;
      bool flexibleInteriorCount = false;
      // Cached from the face half-edge topology when the cavity is built.
      // Candidate ranking is deliberately independent of a subsequent scan
      // over every element of the GFace.
      std::vector<std::size_t> boundaryOutsideQuadDegree;
      std::vector<std::size_t> boundaryIdealQuadDegree;
    };

    struct DiamondSeed {
      CavitySeed cavity;
      MQuadrangle *diamond = nullptr;
      std::size_t retainedInterior = 0;
      std::size_t removedInterior = 0;
    };

    struct PatternConfiguration {
      double score = 0.;
      std::size_t pattern = 0;
      std::size_t rotation = 0;
      bool reflected = false;
    };

    struct SizeScore {
      bool admissible = false;
      double meanSquaredLogRatio = std::numeric_limits<double>::infinity();
      double minimumRatio = std::numeric_limits<double>::infinity();
      double maximumRatio = 0.;
      double minimumLength = std::numeric_limits<double>::infinity();
      double maximumLength = 0.;
      std::size_t edgeCount = 0;
      std::size_t validEdgeCount = 0;
      std::size_t belowMinimum = 0;
      std::size_t aboveMaximum = 0;
      std::size_t invalid = 0;
    };

    // Chordal departure of the linear/bilinear mesh interpolation from the
    // underlying GFace. Vertices alone cannot measure this: every movable
    // vertex is projected onto the GFace, while two different quad diagonals
    // can approximate the interior of the same curved patch very differently.
    struct GeometryDeviation {
      bool valid = false;
      std::size_t elementCount = 0;
      std::size_t invalidSampleCount = 0;
      double maximumDistance = std::numeric_limits<double>::infinity();
      double squaredDistanceIntegral =
        std::numeric_limits<double>::infinity();
      double sampledArea = 0.;
      double meanSquaredDistance = std::numeric_limits<double>::infinity();
    };

    struct SupportingPlane {
      Point origin = {0., 0., 0.};
      Point unitNormal = {0., 0., 0.};
    };

    bool auditedSupportingPlane(GFace *face, SupportingPlane &plane)
    {
      if(!face || face->geomType() != GEntity::Plane) return false;
      const std::vector<GVertex *> vertices = face->vertices();
      for(std::size_t i = 0; i < vertices.size(); ++i) {
        if(!vertices[i]) continue;
        const SPoint3 origin(vertices[i]->x(), vertices[i]->y(),
                             vertices[i]->z());
        for(std::size_t j = i + 1; j < vertices.size(); ++j) {
          if(!vertices[j]) continue;
          const SPoint3 firstPoint(vertices[j]->x(), vertices[j]->y(),
                                   vertices[j]->z());
          const SVector3 first(origin, firstPoint);
          for(std::size_t k = j + 1; k < vertices.size(); ++k) {
            if(!vertices[k]) continue;
            const SPoint3 secondPoint(vertices[k]->x(), vertices[k]->y(),
                                      vertices[k]->z());
            const SVector3 normal = crossprod(
              first, SVector3(origin, secondPoint));
            const double normalNorm = normal.norm();
            if(!(normalNorm > 1.e-14)) continue;
            plane.origin = {origin.x(), origin.y(), origin.z()};
            plane.unitNormal = {normal.x() / normalNorm,
                                normal.y() / normalNorm,
                                normal.z() / normalNorm};
            return true;
          }
        }
      }
      return false;
    }

    enum class CleanUpDecisionReason {
      Rejected,
      FewerUnacceptableElements,
      BetterGeometry,
      OtherImprovement
    };

    enum class CleanUpDecisionPhase {
      Any,
      FewerUnacceptableElements,
      BetterGeometry,
      OtherImprovement
    };

    bool decisionAllowed(CleanUpDecisionReason reason,
                         CleanUpDecisionPhase phase)
    {
      if(reason == CleanUpDecisionReason::Rejected) return false;
      if(phase == CleanUpDecisionPhase::Any) return true;
      if(phase == CleanUpDecisionPhase::FewerUnacceptableElements)
        return reason == CleanUpDecisionReason::FewerUnacceptableElements;
      if(phase == CleanUpDecisionPhase::BetterGeometry)
        return reason == CleanUpDecisionReason::BetterGeometry;
      return reason == CleanUpDecisionReason::OtherImprovement;
    }

    void recordAcceptedCleanUpDecision(
      SmallCavityOptimizerResult &result, CleanUpDecisionReason reason)
    {
      switch(reason) {
      case CleanUpDecisionReason::FewerUnacceptableElements:
        ++result.acceptedFewerUnacceptableElements;
        break;
      case CleanUpDecisionReason::BetterGeometry:
        ++result.acceptedBetterGeometry;
        break;
      case CleanUpDecisionReason::OtherImprovement:
        ++result.acceptedOtherImprovements;
        break;
      case CleanUpDecisionReason::Rejected: break;
      }
    }

    struct Candidate {
      struct VertexGeometry {
        MVertex *vertex = nullptr;
        UV uv = {0., 0.};
        Point xyz = {0., 0., 0.};
      };

      bool valid = false;
      std::vector<UV> uv;
      std::vector<Point> xyz;
      Pattern quadrangles;
      std::vector<std::size_t> interiorAssignment;
      SpecificationObjective objective;
      GeometryDeviation geometry;
      // Geometry of the exact same (possibly smoothed one-ring) patch before
      // this transaction. Keeping the pair on the candidate makes the
      // additive change in squared GFace deviation comparable even when two
      // candidates modify patches with different supports.
      GeometryDeviation referenceGeometry;
      // Fast cleanup uses a single additive face objective. These cached
      // local terms are sufficient because every element, vertex and edge
      // outside the transaction support is unchanged and cancels exactly.
      std::size_t invalidElementCount =
        std::numeric_limits<std::size_t>::max();
      double sizeError = std::numeric_limits<double>::infinity();
      std::size_t sizeEdgeCount = 0;
      std::size_t sizeViolationCount =
        std::numeric_limits<std::size_t>::max();
      ValenceObjective valence;
      bool hasEdgeSwapCad = false;
      double edgeSwapCadDistance = 0.;
      double referenceEdgeSwapCadDistance = 0.;
      double edgeSwapCadScale = 1.;
      // For zero-interior replacements, the actual trial includes a movable
      // one-ring. These values are produced by the in-memory Winslow solve and
      // applied only after the complete smoothed trial has passed all gates.
      bool hasSmoothedReference = false;
      SpecificationObjective smoothedReferenceObjective;
      GeometryDeviation smoothedReferenceGeometry;
      // Quality outside the trial patch is identical before and after the
      // transaction. Adding it back makes the acceptance order a strict
      // objective for the complete GFace, even when a worst local violation
      // is hidden by a worse element elsewhere on the face.
      SpecificationObjective unchangedObjective;
      double smoothedReferenceSizeError =
        std::numeric_limits<double>::infinity();
      std::size_t smoothedReferenceSizeViolationCount =
        std::numeric_limits<std::size_t>::max();
      std::vector<VertexGeometry> smoothedExistingVertices;
      CleanUpDecisionReason decisionReason =
        CleanUpDecisionReason::Rejected;
    };

    std::set<MVertex *> protectedFaceVertices(GFace *face)
    {
      std::set<MVertex *> protectedVertices;
      if(!face) return protectedVertices;
      BoundaryLayerColumns *columns = face->getColumns();
      if(columns)
        for(const auto &entry : columns->_data) {
          protectedVertices.insert(entry.first);
          protectedVertices.insert(entry.second._column.begin(),
                                   entry.second._column.end());
        }
      for(MVertex *vertex : face->mesh_vertices) {
        MFaceVertex *faceVertex = dynamic_cast<MFaceVertex *>(vertex);
        if(faceVertex && faceVertex->bl_data)
          protectedVertices.insert(vertex);
      }
      return protectedVertices;
    }

    bool touchesBoundaryLayerElementData(
      GFace *face, const std::vector<MElement *> &elements)
    {
      BoundaryLayerColumns *columns = face ? face->getColumns() : nullptr;
      if(!columns ||
         (columns->_toFirst.empty() && columns->_elemColumns.empty()))
        return false;
      for(MElement *element : elements) {
        if(!element) continue;
        if(columns->_toFirst.find(element) != columns->_toFirst.end() ||
           columns->_elemColumns.find(element) !=
             columns->_elemColumns.end())
          return true;
        for(const auto &column : columns->_elemColumns)
          if(std::find(column.second.begin(), column.second.end(), element) !=
             column.second.end())
            return true;
      }
      return false;
    }

    struct BoundaryLoop {
      std::vector<MVertex *> vertices;
      double perimeter = 0.;
    };

    std::vector<MElement *> surfaceElements(GFace *face)
    {
      std::vector<MElement *> elements;
      elements.reserve(face->triangles.size() + face->quadrangles.size());
      for(MTriangle *triangle : face->triangles) elements.push_back(triangle);
      for(MQuadrangle *quadrangle : face->quadrangles)
        elements.push_back(quadrangle);
      return elements;
    }

    // Mutable side-car half-edge topology for a single manifold GFace. Gmsh
    // keeps its public surface mesh in triangle/quadrangle vectors; this index
    // gives CleanUp constant-time element twins and vertex stars without
    // changing that storage. Accepted cavity diffs update only the removed and
    // inserted elements.
    class FaceHalfEdgeTopology {
      static constexpr std::size_t invalid =
        std::numeric_limits<std::size_t>::max();

      struct HalfEdge {
        MVertex *origin = nullptr;
        MVertex *destination = nullptr;
        MElement *element = nullptr;
        std::size_t next = invalid;
        std::size_t previous = invalid;
        std::size_t twin = invalid;
        bool active = false;
      };

      std::vector<HalfEdge> _halfEdges;
      std::unordered_map<MElement *, std::vector<std::size_t> >
        _elementHalfEdges;
      std::unordered_map<MVertex *, std::vector<std::size_t> > _outgoing;
      std::map<Edge, std::vector<std::size_t> > _edgeHalfEdges;
      std::set<MElement *> _elements;
      // This flag denotes a regular oriented surface cell complex, not only
      // the weaker "at most two elements per edge" condition. In
      // particular, two distinct cells may share at most one edge and the
      // two incidences of an interior edge must have opposite directions.
      bool _manifold = true;

      void compactEdge(const Edge &edge)
      {
        auto found = _edgeHalfEdges.find(edge);
        if(found == _edgeHalfEdges.end()) return;
        auto &indices = found->second;
        indices.erase(std::remove_if(indices.begin(), indices.end(),
                                     [&](std::size_t index) {
                                       return index >= _halfEdges.size() ||
                                              !_halfEdges[index].active;
                                     }),
                      indices.end());
        if(indices.empty()) _edgeHalfEdges.erase(found);
      }

      void compactOutgoing(MVertex *vertex)
      {
        auto found = _outgoing.find(vertex);
        if(found == _outgoing.end()) return;
        auto &indices = found->second;
        indices.erase(std::remove_if(indices.begin(), indices.end(),
                                     [&](std::size_t index) {
                                       return index >= _halfEdges.size() ||
                                              !_halfEdges[index].active;
                                     }),
                      indices.end());
        if(indices.empty()) _outgoing.erase(found);
      }

    public:
      FaceHalfEdgeTopology() = default;

      explicit FaceHalfEdgeTopology(const std::vector<MElement *> &elements)
      {
        for(MElement *element : elements) addElement(element);
      }

      bool manifold() const { return _manifold; }

      bool addElement(MElement *element)
      {
        if(!element || _elementHalfEdges.find(element) !=
                         _elementHalfEdges.end())
          return false;
        const std::size_t count = element->getNumPrimaryVertices();
        if(count != 3 && count != 4) return false;
        std::set<MVertex *> elementVertices;
        for(std::size_t i = 0; i < count; ++i) {
          MVertex *vertex = element->getVertex(static_cast<int>(i));
          if(!vertex || !elementVertices.insert(vertex).second) {
            _manifold = false;
            return false;
          }
        }
        const std::size_t first = _halfEdges.size();
        std::vector<std::size_t> indices(count);
        for(std::size_t i = 0; i < count; ++i) {
          const std::size_t index = first + i;
          indices[i] = index;
          HalfEdge halfEdge;
          halfEdge.origin = element->getVertex(static_cast<int>(i));
          halfEdge.destination =
            element->getVertex(static_cast<int>((i + 1) % count));
          halfEdge.element = element;
          halfEdge.next = first + (i + 1) % count;
          halfEdge.previous = first + (i + count - 1) % count;
          halfEdge.active = true;
          _halfEdges.push_back(halfEdge);
        }
        _elementHalfEdges[element] = indices;
        _elements.insert(element);
        std::set<MElement *> adjacentElements;
        for(const std::size_t index : indices) {
          HalfEdge &halfEdge = _halfEdges[index];
          _outgoing[halfEdge.origin].push_back(index);
          const Edge edge =
            canonicalEdge(halfEdge.origin, halfEdge.destination);
          compactEdge(edge);
          auto &incidences = _edgeHalfEdges[edge];
          if(incidences.size() == 1) {
            const std::size_t twin = incidences.front();
            const HalfEdge &other = _halfEdges[twin];
            // Cells on the two sides of an oriented surface edge traverse it
            // in opposite directions. Same-direction incidences are an
            // overlap, even though the edge still has only two incidences.
            if(other.origin != halfEdge.destination ||
               other.destination != halfEdge.origin)
              _manifold = false;
            // A pair of distinct polygonal cells cannot share two different
            // edges. Such a triangle wrapped inside a quadrangle was the
            // Doghouse failure that the old incidence-only test accepted.
            if(!adjacentElements.insert(other.element).second)
              _manifold = false;
            halfEdge.twin = twin;
            _halfEdges[twin].twin = index;
          }
          else if(!incidences.empty()) {
            // More than two incident surface elements: CleanUp assumes and
            // exploits a manifold GFace, so keep the index diagnosable.
            _manifold = false;
          }
          incidences.push_back(index);
        }
        return true;
      }

      bool removeElement(MElement *element)
      {
        const auto found = _elementHalfEdges.find(element);
        if(found == _elementHalfEdges.end()) return false;
        std::vector<Edge> touchedEdges;
        std::vector<MVertex *> touchedVertices;
        for(const std::size_t index : found->second) {
          HalfEdge &halfEdge = _halfEdges[index];
          if(!halfEdge.active) continue;
          touchedEdges.push_back(
            canonicalEdge(halfEdge.origin, halfEdge.destination));
          touchedVertices.push_back(halfEdge.origin);
          if(halfEdge.twin != invalid &&
             halfEdge.twin < _halfEdges.size() &&
             _halfEdges[halfEdge.twin].active)
            _halfEdges[halfEdge.twin].twin = invalid;
          halfEdge.twin = invalid;
          halfEdge.active = false;
        }
        _elementHalfEdges.erase(found);
        _elements.erase(element);
        for(const Edge &edge : touchedEdges) compactEdge(edge);
        for(MVertex *vertex : touchedVertices) compactOutgoing(vertex);
        return true;
      }

      bool replace(const std::vector<MElement *> &removed,
                   const std::vector<MElement *> &inserted)
      {
        bool ok = true;
        for(MElement *element : removed) ok = removeElement(element) && ok;
        for(MElement *element : inserted) ok = addElement(element) && ok;
        return ok && _manifold;
      }

      std::vector<MElement *> elements() const
      {
        return {_elements.begin(), _elements.end()};
      }

      std::vector<MVertex *> vertices() const
      {
        std::vector<MVertex *> result;
        result.reserve(_outgoing.size());
        for(const auto &entry : _outgoing)
          if(!entry.second.empty()) result.push_back(entry.first);
        return result;
      }

      std::vector<MElement *> incidentElements(MVertex *vertex) const
      {
        std::vector<MElement *> result;
        const auto found = _outgoing.find(vertex);
        if(found == _outgoing.end()) return result;
        result.reserve(found->second.size());
        for(const std::size_t index : found->second)
          if(index < _halfEdges.size() && _halfEdges[index].active)
            result.push_back(_halfEdges[index].element);
        return result;
      }

      std::size_t quadDegree(MVertex *vertex) const
      {
        std::size_t degree = 0;
        const auto found = _outgoing.find(vertex);
        if(found == _outgoing.end()) return degree;
        for(const std::size_t index : found->second)
          if(index < _halfEdges.size() && _halfEdges[index].active &&
             _halfEdges[index].element->getNumPrimaryVertices() == 4)
            ++degree;
        return degree;
      }

      std::vector<MElement *> neighbors(MElement *element) const
      {
        std::vector<MElement *> result;
        const auto found = _elementHalfEdges.find(element);
        if(found == _elementHalfEdges.end()) return result;
        for(const std::size_t index : found->second) {
          if(index >= _halfEdges.size() || !_halfEdges[index].active)
            continue;
          const std::size_t twin = _halfEdges[index].twin;
          if(twin != invalid && twin < _halfEdges.size() &&
             _halfEdges[twin].active)
            result.push_back(_halfEdges[twin].element);
        }
        return result;
      }

      std::vector<std::pair<Edge, std::vector<MElement *> > > edges() const
      {
        std::vector<std::pair<Edge, std::vector<MElement *> > > result;
        result.reserve(_edgeHalfEdges.size());
        for(const auto &entry : _edgeHalfEdges) {
          std::vector<MElement *> elements;
          elements.reserve(entry.second.size());
          for(const std::size_t index : entry.second)
            if(index < _halfEdges.size() && _halfEdges[index].active)
              elements.push_back(_halfEdges[index].element);
          if(!elements.empty()) result.push_back({entry.first, elements});
        }
        return result;
      }
    };

    Adjacency buildAdjacency(const std::vector<MElement *> &elements)
    {
      Adjacency adjacency;
      for(MElement *element : elements) {
        const std::size_t count = element->getNumPrimaryVertices();
        if(count != 3 && count != 4) continue;
        for(std::size_t i = 0; i < count; ++i)
          adjacency[element->getVertex(static_cast<int>(i))].push_back(element);
      }
      return adjacency;
    }

    std::vector<MElement *> unionStars(
      const std::vector<MVertex *> &vertices, const Adjacency &adjacency)
    {
      std::set<MElement *> unique;
      for(MVertex *vertex : vertices) {
        const auto found = adjacency.find(vertex);
        if(found == adjacency.end()) return {};
        unique.insert(found->second.begin(), found->second.end());
      }
      return {unique.begin(), unique.end()};
    }

    bool sameVertices(const std::vector<MVertex *> &first,
                      const std::vector<MVertex *> &second)
    {
      return std::set<MVertex *>(first.begin(), first.end()) ==
             std::set<MVertex *>(second.begin(), second.end());
    }

    std::size_t currentQuadDegree(MVertex *vertex,
                                  const Adjacency &adjacency)
    {
      const auto found = adjacency.find(vertex);
      if(found == adjacency.end()) return 0;
      return static_cast<std::size_t>(std::count_if(
        found->second.begin(), found->second.end(), [](const MElement *element) {
          return element && element->getNumPrimaryVertices() == 4;
        }));
    }

    double boundaryDomainAngleDegrees(
      GFace *face, MVertex *vertex,
      const std::vector<MElement *> &incidentElements);

    double boundaryDomainAngleDegrees(GFace *face, MVertex *vertex,
                                      const Adjacency &adjacency)
    {
      const auto found = adjacency.find(vertex);
      if(!face || found == adjacency.end()) return 180.;
      return boundaryDomainAngleDegrees(face, vertex, found->second);
    }

    double boundaryDomainAngleDegrees(
      GFace *face, MVertex *vertex,
      const std::vector<MElement *> &incidentElements)
    {
      if(!face || incidentElements.empty()) return 180.;
      SPoint2 center;
      if(!persistentFaceParameter(face, vertex, center))
        return 180.;
      double total = 0.;
      for(MElement *element : incidentElements) {
        if(!element) continue;
        const std::size_t count = element->getNumPrimaryVertices();
        if(count != 3 && count != 4) continue;
        std::size_t local = count;
        for(std::size_t i = 0; i < count; ++i)
          if(element->getVertex(static_cast<int>(i)) == vertex) {
            local = i;
            break;
          }
        if(local == count) continue;
        SPoint2 previous, next;
        if(!reparamMeshVertexOnFaceWithRef(
             face,
             element->getVertex(static_cast<int>((local + count - 1) % count)),
             center, previous) ||
           !reparamMeshVertexOnFaceWithRef(
             face, element->getVertex(static_cast<int>((local + 1) % count)),
             center, next))
          continue;
        const double ax = previous.x() - center.x();
        const double ay = previous.y() - center.y();
        const double bx = next.x() - center.x();
        const double by = next.y() - center.y();
        const double denominator =
          std::sqrt((ax * ax + ay * ay) * (bx * bx + by * by));
        if(!(denominator > 0.)) continue;
        total += std::acos(std::clamp((ax * bx + ay * by) / denominator,
                                     -1., 1.)) *
                 180. / 3.141592653589793238462643383279502884;
      }
      return total > 0. ? total : 180.;
    }

    std::size_t idealQuadDegree(GFace *face, MVertex *vertex,
                                const Adjacency &adjacency)
    {
      if(vertex && vertex->onWhat() == face) return 4;
      const double angle = boundaryDomainAngleDegrees(face, vertex, adjacency);
      if(angle < 25.) return 0;
      if(angle < 115.) return 1;
      if(angle < 205.) return 2;
      if(angle < 295.) return 3;
      return 4;
    }

    std::size_t idealQuadDegree(GFace *face, MVertex *vertex,
                                const FaceHalfEdgeTopology &topology)
    {
      if(vertex && vertex->onWhat() == face) return 4;
      const double angle = boundaryDomainAngleDegrees(
        face, vertex, topology.incidentElements(vertex));
      if(angle < 25.) return 0;
      if(angle < 115.) return 1;
      if(angle < 205.) return 2;
      if(angle < 295.) return 3;
      return 4;
    }

    void addValence(ValenceObjective &objective, std::size_t actual,
                    std::size_t ideal, bool interior)
    {
      const long difference = static_cast<long>(actual) -
                              static_cast<long>(ideal);
      if(difference != 0) ++objective.irregularCount;
      if((interior && (actual <= 2 || actual >= 6)) ||
         (!interior && std::abs(difference) > 1))
        ++objective.severeCount;
      objective.penalty += static_cast<double>(difference * difference);
    }

    bool improvesValence(const ValenceObjective &candidate,
                         const ValenceObjective &reference)
    {
      if(candidate.severeCount != reference.severeCount)
        return candidate.severeCount < reference.severeCount;
      if(candidate.irregularCount != reference.irregularCount)
        return candidate.irregularCount < reference.irregularCount;
      return candidate.penalty < reference.penalty - 1.e-12;
    }

    bool noWorseValencePareto(const ValenceObjective &candidate,
                              const ValenceObjective &reference)
    {
      return candidate.severeCount <= reference.severeCount &&
             candidate.irregularCount <= reference.irregularCount &&
             candidate.penalty <= reference.penalty + 1.e-12;
    }

    bool improvesValencePareto(const ValenceObjective &candidate,
                               const ValenceObjective &reference)
    {
      return noWorseValencePareto(candidate, reference) &&
        (candidate.severeCount < reference.severeCount ||
         candidate.irregularCount < reference.irregularCount ||
         candidate.penalty < reference.penalty - 1.e-12);
    }

    struct FastGlobalQuality {
      std::size_t invalidElementCount = 0;
      std::size_t forbiddenConfigurationCount = 0;
      std::size_t hardSpecificationViolationCount = 0;
      double hardSpecificationPenalty =
        std::numeric_limits<double>::infinity();
      double compromise = std::numeric_limits<double>::infinity();
    };

    FastGlobalQuality fastGlobalQuality(
      const SpecificationObjective &shape, const ValenceObjective &valence,
      std::size_t invalidElementCount, std::size_t sizeViolationCount,
      double meanSquaredLogSizeError, std::size_t sizeEdgeCount,
      double normalizedCadPenalty)
    {
      FastGlobalQuality quality;
      quality.invalidElementCount = invalidElementCount;
      // This is the currently detectable forbidden set: unacceptable
      // elements plus severe interior/boundary valence configurations.
      quality.forbiddenConfigurationCount =
        shape.absoluteBadElementCount + valence.severeCount;
      quality.hardSpecificationViolationCount =
        shape.absoluteViolationCount + sizeViolationCount;

      double sizePenalty = 0.;
      if(sizeEdgeCount) {
        if(!std::isfinite(meanSquaredLogSizeError))
          sizePenalty = std::numeric_limits<double>::infinity();
        else
          sizePenalty = static_cast<double>(sizeEdgeCount) *
            std::max(0., meanSquaredLogSizeError);
      }
      // Absolute shape specifications remain ahead of target-size and soft
      // shape preferences. Hard size violations are already counted above;
      // the continuous target-size error participates in the compromise.
      quality.hardSpecificationPenalty = shape.absolutePenalty;
      quality.compromise =
        static_cast<double>(shape.preferredViolationCount) +
        shape.preferredPenalty + shape.shapePenalty +
        static_cast<double>(valence.irregularCount) + valence.penalty +
        sizePenalty + normalizedCadPenalty;
      return quality;
    }

    bool improvesFastGlobalQuality(const FastGlobalQuality &candidate,
                                   const FastGlobalQuality &reference)
    {
      if(candidate.invalidElementCount != reference.invalidElementCount)
        return candidate.invalidElementCount <
               reference.invalidElementCount;
      if(candidate.forbiddenConfigurationCount !=
         reference.forbiddenConfigurationCount)
        return candidate.forbiddenConfigurationCount <
               reference.forbiddenConfigurationCount;
      if(candidate.hardSpecificationViolationCount !=
         reference.hardSpecificationViolationCount)
        return candidate.hardSpecificationViolationCount <
               reference.hardSpecificationViolationCount;
      if(!std::isfinite(candidate.hardSpecificationPenalty))
        return false;
      if(!std::isfinite(reference.hardSpecificationPenalty))
        return true;
      constexpr double minimumDecrease = 1.e-10;
      if(candidate.hardSpecificationPenalty + minimumDecrease <
         reference.hardSpecificationPenalty)
        return true;
      if(reference.hardSpecificationPenalty + minimumDecrease <
         candidate.hardSpecificationPenalty)
        return false;
      if(!std::isfinite(candidate.compromise))
        return false;
      if(!std::isfinite(reference.compromise))
        return true;
      // A fixed minimum decrease and the finite pass bound exclude
      // tolerance-driven cycles.
      return candidate.compromise + minimumDecrease <
             reference.compromise;
    }

    void cacheCavityValence(CavitySeed &seed,
                            const FaceHalfEdgeTopology &topology)
    {
      const std::vector<MVertex *> &boundary =
        seed.patch.bdrVertices.front();
      seed.boundaryOutsideQuadDegree.assign(boundary.size(), 0);
      seed.boundaryIdealQuadDegree.assign(boundary.size(), 0);
      std::unordered_map<MVertex *, std::size_t> boundaryIndex;
      boundaryIndex.reserve(boundary.size());
      for(std::size_t i = 0; i < boundary.size(); ++i)
        boundaryIndex[boundary[i]] = i;
      std::vector<std::size_t> local(boundary.size(), 0);
      for(MElement *element : seed.patch.elements)
        for(std::size_t i = 0; i < element->getNumPrimaryVertices(); ++i) {
          const auto found = boundaryIndex.find(
            element->getVertex(static_cast<int>(i)));
          if(found != boundaryIndex.end()) ++local[found->second];
        }

      seed.valence = {};
      for(std::size_t i = 0; i < boundary.size(); ++i) {
        MVertex *vertex = boundary[i];
        const std::size_t global = topology.quadDegree(vertex);
        const std::size_t outside =
          global >= local[i] ? global - local[i] : 0;
        const std::size_t ideal = idealQuadDegree(seed.patch.gf, vertex,
                                                  topology);
        seed.boundaryOutsideQuadDegree[i] = outside;
        seed.boundaryIdealQuadDegree[i] = ideal;
        addValence(seed.valence, global, ideal,
                   vertex->onWhat() == seed.patch.gf);
      }
      for(MVertex *vertex : seed.patch.intVertices)
        addValence(seed.valence, topology.quadDegree(vertex), 4, true);
    }

    bool noWorseAbsoluteSpecifications(
      const SpecificationObjective &candidate,
      const SpecificationObjective &reference, double tolerance)
    {
      if(candidate.invalidElementCount > reference.invalidElementCount)
        return false;
      if(candidate.absoluteBadElementCount > reference.absoluteBadElementCount)
        return false;
      if(candidate.worstAbsoluteViolation >
         reference.worstAbsoluteViolation + tolerance *
           std::max({1., candidate.worstAbsoluteViolation,
                     reference.worstAbsoluteViolation}))
        return false;
      if(candidate.absoluteViolationCount > reference.absoluteViolationCount)
        return false;
      return candidate.absolutePenalty <= reference.absolutePenalty +
        tolerance * std::max({1., candidate.absolutePenalty,
                              reference.absolutePenalty});
    }

    bool improvesCleanUpAction(
      const SpecificationObjective &candidateQuality,
      const SpecificationObjective &referenceQuality,
      const ValenceObjective &candidateValence,
      const ValenceObjective &referenceValence,
      std::size_t candidateSizeViolations,
      std::size_t referenceSizeViolations, double candidateSizeError,
      double referenceSizeError, double tolerance)
    {
      if(!noWorseAbsoluteSpecifications(
           candidateQuality, referenceQuality, tolerance))
        return false;

      // Absolute quality requirements are the first priority. As the
      // component-wise no-worse gate above is already satisfied, any strict
      // decrease in one of them is globally monotone.
      if(candidateQuality.invalidElementCount <
           referenceQuality.invalidElementCount ||
         candidateQuality.absoluteBadElementCount <
           referenceQuality.absoluteBadElementCount ||
         candidateQuality.worstAbsoluteViolation + tolerance * std::max(
           {1., candidateQuality.worstAbsoluteViolation,
            referenceQuality.worstAbsoluteViolation}) <
           referenceQuality.worstAbsoluteViolation ||
         candidateQuality.absoluteViolationCount <
           referenceQuality.absoluteViolationCount ||
         candidateQuality.absolutePenalty + tolerance * std::max(
           {1., candidateQuality.absolutePenalty,
            referenceQuality.absolutePenalty}) <
           referenceQuality.absolutePenalty)
        return true;

      const bool comparableSizeCounts =
        candidateSizeViolations != std::numeric_limits<std::size_t>::max() &&
        referenceSizeViolations != std::numeric_limits<std::size_t>::max();
      if(comparableSizeCounts &&
         candidateSizeViolations != referenceSizeViolations)
        return candidateSizeViolations < referenceSizeViolations;
      if(candidateValence.severeCount != referenceValence.severeCount)
        return candidateValence.severeCount < referenceValence.severeCount;
      if(candidateValence.irregularCount != referenceValence.irregularCount)
        return candidateValence.irregularCount <
               referenceValence.irregularCount;

      if(improvesSpecificationObjective(
           candidateQuality, referenceQuality, tolerance))
        return true;
      if(improvesSpecificationObjective(
           referenceQuality, candidateQuality, tolerance))
        return false;

      if(std::isfinite(candidateSizeError) &&
         std::isfinite(referenceSizeError)) {
        const double sizeTolerance = tolerance *
          std::max({1., candidateSizeError, referenceSizeError});
        if(candidateSizeError + sizeTolerance < referenceSizeError)
          return true;
        if(referenceSizeError + sizeTolerance < candidateSizeError)
          return false;
      }
      return candidateValence.penalty + tolerance * std::max(
        {1., candidateValence.penalty, referenceValence.penalty}) <
        referenceValence.penalty;
    }

    bool improvesCleanUpSmoothing(
      const SpecificationObjective &candidateQuality,
      const SpecificationObjective &referenceQuality,
      std::size_t candidateSizeViolations,
      std::size_t referenceSizeViolations, double candidateSizeError,
      double referenceSizeError, double tolerance)
    {
      // Geometry-only relaxation uses a Pareto gate. In particular, it must
      // not trade a tiny preferred-quality loss for a tiny size-error gain:
      // that fuzzy lexicographic trade can form a numerical cycle between
      // neighboring one-rings. Hard size-violation counts remain the first
      // geometric priority after the absolute specification gate.
      constexpr double noWorseTolerance = 1.e-12;
      auto noWorse = [noWorseTolerance](double candidate, double reference) {
        return candidate <= reference + noWorseTolerance *
          std::max({1., std::abs(candidate), std::abs(reference)});
      };
      auto improves = [tolerance](double candidate, double reference) {
        return candidate < reference - tolerance *
          std::max({1., std::abs(candidate), std::abs(reference)});
      };

      if(!noWorseAbsoluteSpecifications(
           candidateQuality, referenceQuality, noWorseTolerance))
        return false;
      if(candidateSizeViolations != referenceSizeViolations)
        return candidateSizeViolations < referenceSizeViolations;
      if(candidateQuality.preferredViolationCount >
         referenceQuality.preferredViolationCount)
        return false;
      if(!noWorse(candidateQuality.worstPreferredViolation,
                  referenceQuality.worstPreferredViolation) ||
         !noWorse(candidateQuality.preferredPenalty,
                  referenceQuality.preferredPenalty) ||
         !noWorse(candidateQuality.shapePenalty,
                  referenceQuality.shapePenalty))
        return false;

      if(candidateQuality.invalidElementCount <
           referenceQuality.invalidElementCount ||
         candidateQuality.absoluteBadElementCount <
           referenceQuality.absoluteBadElementCount ||
         candidateQuality.absoluteViolationCount <
           referenceQuality.absoluteViolationCount ||
         candidateQuality.preferredViolationCount <
           referenceQuality.preferredViolationCount ||
         improves(candidateQuality.worstAbsoluteViolation,
                  referenceQuality.worstAbsoluteViolation) ||
         improves(candidateQuality.absolutePenalty,
                  referenceQuality.absolutePenalty) ||
         improves(candidateQuality.worstPreferredViolation,
                  referenceQuality.worstPreferredViolation) ||
         improves(candidateQuality.preferredPenalty,
                  referenceQuality.preferredPenalty) ||
         improves(candidateQuality.shapePenalty,
                  referenceQuality.shapePenalty))
        return true;

      return std::isfinite(candidateSizeError) &&
             std::isfinite(referenceSizeError) &&
             improves(candidateSizeError, referenceSizeError);
    }

    SpecificationObjective objectiveOutside(
      GFace *face, const std::vector<MElement *> &affected)
    {
      const std::set<MElement *> affectedSet(affected.begin(),
                                             affected.end());
      std::vector<MElement *> unchanged;
      for(MElement *element : surfaceElements(face))
        if(affectedSet.find(element) == affectedSet.end())
          unchanged.push_back(element);
      return specificationObjective(unchanged);
    }

    SpecificationObjective comparisonObjective(const Candidate &candidate)
    {
      SpecificationObjective objective = candidate.objective;
      objective += candidate.unchangedObjective;
      return objective;
    }

    SpecificationObjective comparisonReferenceObjective(
      const CavitySeed &seed, const Candidate &candidate)
    {
      SpecificationObjective objective = candidate.hasSmoothedReference ?
        candidate.smoothedReferenceObjective : seed.objective;
      objective += candidate.unchangedObjective;
      return objective;
    }

    // Return -1 when candidate is closer to the GFace, +1 when reference is
    // closer and 0 when the sampled errors are indistinguishable. Only the
    // area integral participates in acceptance: it is additive over elements,
    // hence every accepted local decrease is a decrease for the complete
    // GFace. Maximum and RMS remain diagnostic quantities, not non-additive
    // tie breakers that could create overlapping-patch cycles.
    int compareGeometryDeviation(const GeometryDeviation &candidate,
                                 const GeometryDeviation &reference,
                                 double tolerance)
    {
      if(candidate.valid != reference.valid)
        return candidate.valid ? -1 : 1;
      if(!candidate.valid) return 0;
      const double relativeTolerance = std::max(tolerance, 1.e-8);
      auto compare = [relativeTolerance](double a, double b,
                                         double absoluteTolerance) {
        const double scale = std::max(std::abs(a), std::abs(b));
        const double epsilon = std::max(
          absoluteTolerance, relativeTolerance * scale);
        if(a + epsilon < b) return -1;
        if(b + epsilon < a) return 1;
        return 0;
      };
      const double areaScale = std::max(
        {candidate.sampledArea, reference.sampledArea,
         std::numeric_limits<double>::min()});
      const int integral = compare(candidate.squaredDistanceIntegral,
                                   reference.squaredDistanceIntegral,
                                   1.e-20 * areaScale * areaScale);
      return integral;
    }

    bool geometryDoesNotRegressBeyondRoundoff(
      const GeometryDeviation &candidate,
      const GeometryDeviation &reference)
    {
      if(!candidate.valid || !reference.valid) return false;
      const double integralScale = std::max(
        {std::abs(candidate.squaredDistanceIntegral),
         std::abs(reference.squaredDistanceIntegral),
         std::numeric_limits<double>::min()});
      const double areaScale = std::max(
        {candidate.sampledArea, reference.sampledArea,
         std::numeric_limits<double>::min()});
      // The symmetric comparison above deliberately has a practical noise
      // band for deciding whether geometry alone is an action. A structural
      // tie-breaker must obey a much tighter one-sided gate, otherwise a
      // sequence of nominal geometry ties can undo a preceding geometric
      // swap on overlapping cavities. Keep only floating-point accumulation
      // noise and the absolute closest-point integration floor.
      const double roundoff = std::max(
        64. * std::numeric_limits<double>::epsilon() * integralScale,
        1.e-20 * areaScale * areaScale);
      return candidate.squaredDistanceIntegral <=
        reference.squaredDistanceIntegral + roundoff;
    }

    CleanUpDecisionReason cleanUpDecision(
      const SpecificationObjective &candidateQuality,
      const SpecificationObjective &referenceQuality,
      const GeometryDeviation &candidateGeometry,
      const GeometryDeviation &referenceGeometry,
      bool candidatePatchAllAcceptable,
      const ValenceObjective &candidateValence,
      const ValenceObjective &referenceValence,
      std::size_t candidateSizeViolations,
      std::size_t referenceSizeViolations, double candidateSizeError,
      double referenceSizeError, double tolerance,
      bool geometryImprovementRequiresValence = false)
    {
      // A negative or degenerate Jacobian is never exchangeable for shape,
      // size, valence or CAD-distance gains.
      if(candidateQuality.invalidElementCount !=
         referenceQuality.invalidElementCount)
        return candidateQuality.invalidElementCount <
                 referenceQuality.invalidElementCount ?
          CleanUpDecisionReason::FewerUnacceptableElements :
          CleanUpDecisionReason::Rejected;

      // Size bounds are hard requirements: reducing bad-element count never
      // authorizes introducing an additional size violation.
      if(candidateSizeViolations > referenceSizeViolations)
        return CleanUpDecisionReason::Rejected;

      // This is the production decision path. Subject to the hard size veto,
      // the count of unacceptable elements is strictly primary:
      // component-wise penalty trades must not veto a topology change that
      // removes one of them.
      if(candidateQuality.absoluteBadElementCount !=
         referenceQuality.absoluteBadElementCount)
        return candidateQuality.absoluteBadElementCount <
                 referenceQuality.absoluteBadElementCount ?
          CleanUpDecisionReason::FewerUnacceptableElements :
          CleanUpDecisionReason::Rejected;

      // Hard edge-length bounds are specifications too. Every candidate has
      // already passed the non-negotiable per-edge admissibility guard; among
      // otherwise equally acceptable element patches, removing a remaining
      // (typically immutable boundary) size violation is the same primary
      // decision as removing a bad element.
      if(candidateSizeViolations < referenceSizeViolations)
        return CleanUpDecisionReason::FewerUnacceptableElements;

      // Once the complete affected patch is inside the absolute envelope,
      // prefer the one that approximates the CAD surface more closely. Bad
      // elements elsewhere on the GFace must not disable this local choice.
      // Shape, valence and target-size error remain deterministic tie breakers.
      if(candidatePatchAllAcceptable) {
        // Every all-acceptable compromise must have a measurable CAD
        // distance. A failed closest-point evaluation cannot silently fall
        // through to a valence or quality edit.
        if(!candidateGeometry.valid || !referenceGeometry.valid)
          return CleanUpDecisionReason::Rejected;
        const int geometry = compareGeometryDeviation(
          candidateGeometry, referenceGeometry, tolerance);
        if(geometry < 0) {
          if(geometryImprovementRequiresValence &&
             !improvesValencePareto(candidateValence, referenceValence))
            return CleanUpDecisionReason::Rejected;
          return CleanUpDecisionReason::BetterGeometry;
        }
        if(geometry > 0) return CleanUpDecisionReason::Rejected;
        if(!geometryDoesNotRegressBeyondRoundoff(
             candidateGeometry, referenceGeometry))
          return CleanUpDecisionReason::Rejected;
        // On an exact geometry tie, retain the published connectivity cleanup
        // only through strict lexicographic improvements. Avoid the former
        // component-wise OR gate: size, valence and shape could otherwise
        // trade places on overlapping cavities and recreate an earlier mesh.
        if(improvesValencePareto(candidateValence, referenceValence))
          return CleanUpDecisionReason::OtherImprovement;
        if(improvesValencePareto(referenceValence, candidateValence))
          return CleanUpDecisionReason::Rejected;
        if(!noWorseValencePareto(candidateValence, referenceValence) ||
           !noWorseValencePareto(referenceValence, candidateValence))
          return CleanUpDecisionReason::Rejected;
        // Once quality is acceptable, tiny preferred-shape changes are not a
        // structural Cleanup action. In particular, swapping two interior
        // vertex identities can leave the physical connectivity isomorphic
        // while changing a Winslow penalty in the last few digits; accepting
        // that relabeling makes save/reload order part of the result. The
        // only geometry-tie action is therefore a strict valence cleanup.
        // The local mean target-size error is likewise not additive across
        // overlapping cavities; only the hard violation count participates.
        (void)candidateSizeError;
        (void)referenceSizeError;
        return CleanUpDecisionReason::Rejected;
      }

      // With unacceptable elements still present and their count unchanged,
      // the requested decision path stops here. Improving only the severity
      // is not enough: the transaction must actually remove an unacceptable
      // element (or a hard size violation) before it is committed.
      return CleanUpDecisionReason::Rejected;
    }

    CleanUpDecisionReason cleanUpSmoothingDecision(
      const SpecificationObjective &candidateQuality,
      const SpecificationObjective &referenceQuality,
      const GeometryDeviation &candidateGeometry,
      const GeometryDeviation &referenceGeometry,
      bool candidatePatchAllAcceptable,
      std::size_t candidateSizeViolations,
      std::size_t referenceSizeViolations, double candidateSizeError,
      double referenceSizeError, double tolerance)
    {
      if(candidateQuality.invalidElementCount !=
         referenceQuality.invalidElementCount)
        return candidateQuality.invalidElementCount <
                 referenceQuality.invalidElementCount ?
          CleanUpDecisionReason::FewerUnacceptableElements :
          CleanUpDecisionReason::Rejected;
      if(candidateSizeViolations > referenceSizeViolations)
        return CleanUpDecisionReason::Rejected;
      if(candidateQuality.absoluteBadElementCount !=
         referenceQuality.absoluteBadElementCount)
        return candidateQuality.absoluteBadElementCount <
                 referenceQuality.absoluteBadElementCount ?
          CleanUpDecisionReason::FewerUnacceptableElements :
          CleanUpDecisionReason::Rejected;
      if(candidateSizeViolations < referenceSizeViolations)
        return CleanUpDecisionReason::FewerUnacceptableElements;
      if(candidatePatchAllAcceptable) {
        if(candidateGeometry.valid && referenceGeometry.valid) {
          const int geometry = compareGeometryDeviation(
            candidateGeometry, referenceGeometry, tolerance);
          if(geometry < 0) return CleanUpDecisionReason::BetterGeometry;
        }
        // A compliant smoothing move must have a proven strict additive
        // geometry gain. A tie or a failed distance evaluation cannot fall
        // through to alternating neighboring one-ring moves.
        return CleanUpDecisionReason::Rejected;
      }
      // As for topology, decreasing only the severity while the number of
      // unacceptable elements is unchanged is not one of the requested
      // actions. The next accepted move must remove one, or reach the fully
      // acceptable geometry branch above.
      (void)candidateSizeError;
      (void)referenceSizeError;
      return CleanUpDecisionReason::Rejected;
    }

    bool betterCleanUpCandidate(
      const Candidate &candidate, const Candidate &reference,
      const SmallCavityOptimizerOptions &options)
    {
      if(!reference.valid) return true;
      const SpecificationObjective candidateQuality =
        comparisonObjective(candidate);
      const SpecificationObjective referenceQuality =
        comparisonObjective(reference);
      if(candidateQuality.invalidElementCount !=
         referenceQuality.invalidElementCount)
        return candidateQuality.invalidElementCount <
               referenceQuality.invalidElementCount;
      if(candidateQuality.absoluteBadElementCount !=
         referenceQuality.absoluteBadElementCount)
        return candidateQuality.absoluteBadElementCount <
               referenceQuality.absoluteBadElementCount;
      if(candidate.objective.absoluteBadElementCount == 0 &&
         candidate.geometry.valid && candidate.referenceGeometry.valid &&
         reference.geometry.valid && reference.referenceGeometry.valid) {
        // The integral is additive. Comparing (after - before) therefore
        // ranks the change to the complete face correctly even when one trial
        // includes a larger smoothing ring than another.
        const double candidateChange =
          candidate.geometry.squaredDistanceIntegral -
          candidate.referenceGeometry.squaredDistanceIntegral;
        const double referenceChange =
          reference.geometry.squaredDistanceIntegral -
          reference.referenceGeometry.squaredDistanceIntegral;
        const double scale = std::max(
          {std::abs(candidate.geometry.squaredDistanceIntegral),
           std::abs(candidate.referenceGeometry.squaredDistanceIntegral),
           std::abs(reference.geometry.squaredDistanceIntegral),
           std::abs(reference.referenceGeometry.squaredDistanceIntegral),
           std::numeric_limits<double>::min()});
        const double epsilon = std::max(
          1.e-20, std::max(options.objectiveRelativeTolerance, 1.e-8) * scale);
        if(candidateChange + epsilon < referenceChange) return true;
        if(referenceChange + epsilon < candidateChange) return false;
      }
      if(improvesSpecificationObjective(
           candidateQuality, referenceQuality,
           options.objectiveRelativeTolerance))
        return true;
      if(improvesSpecificationObjective(
           referenceQuality, candidateQuality,
           options.objectiveRelativeTolerance))
        return false;
      if(improvesValence(candidate.valence, reference.valence)) return true;
      if(improvesValence(reference.valence, candidate.valence)) return false;
      if(candidate.sizeViolationCount != reference.sizeViolationCount)
        return candidate.sizeViolationCount < reference.sizeViolationCount;
      return candidate.sizeError < reference.sizeError;
    }

    bool useFastInteractiveCleanUp(
      const SmallCavityOptimizerOptions &options)
    {
      // QuadCleanUp is a validated fixed-point operation. It must always run
      // the fully converged candidate path even if a caller accidentally also
      // enables the interactive shortcut.
      return options.fastInteractiveCleanUp && !options.quadCleanUp;
    }

    double objectivePriority(const SpecificationObjective &objective)
    {
      return 1.e21 * static_cast<double>(objective.invalidElementCount) +
             1.e18 * static_cast<double>(objective.absoluteBadElementCount) +
             1.e15 * objective.worstAbsoluteViolation +
             1.e12 * static_cast<double>(objective.absoluteViolationCount) +
             1.e9 * objective.absolutePenalty +
             1.e7 * static_cast<double>(objective.preferredViolationCount) +
             1.e3 * objective.preferredPenalty + objective.shapePenalty;
    }

    bool hasQuadFailingAbsoluteSpecifications(const CavitySeed &seed)
    {
      for(const MElement *element : seed.patch.elements)
        if(element && element->getNumPrimaryVertices() == 4 &&
           !evaluateElementQuality(element).passesAbsoluteSpecifications)
          return true;
      return false;
    }

    bool hasQualitySpecificationFailure(
      const SpecificationObjective &objective)
    {
      return objective.absoluteBadElementCount != 0 ||
             objective.absoluteViolationCount != 0 ||
             objective.preferredViolationCount != 0;
    }

    bool flexibleCavityNeedsRepair(
      const CavitySeed &seed,
      const SmallCavityOptimizerOptions &options)
    {
      if(useFastInteractiveCleanUp(options)) {
        if(seed.kind == CavityKind::CleanUpSize) return true;
        if(seed.objective.absoluteBadElementCount != 0 ||
           seed.objective.absoluteViolationCount != 0)
          return true;
        if(seed.kind == CavityKind::CleanUpConnectivity ||
           seed.kind == CavityKind::CleanUpBoundary)
          return seed.valence.severeCount != 0;
        return false;
      }
      if(hasQualitySpecificationFailure(seed.objective)) return true;
      if(seed.kind == CavityKind::CleanUpConnectivity ||
         seed.kind == CavityKind::CleanUpBoundary)
        return seed.valence.irregularCount != 0;
      return seed.kind == CavityKind::CleanUpSize;
    }

    std::vector<CavitySeed> collectCavities(
      GFace *face, const SmallCavityOptimizerOptions &options,
      CavityKind requestedKind)
    {
      const std::vector<MElement *> elements = surfaceElements(face);
      const Adjacency adjacency = buildAdjacency(elements);
      const FaceHalfEdgeTopology topology(elements);
      const std::set<MVertex *> protectedVertices =
        options.quadCleanUp ? protectedFaceVertices(face) :
                              std::set<MVertex *>();
      std::vector<CavitySeed> cavities;
      std::set<std::vector<std::uintptr_t> > signatures;

      auto add = [&](const std::vector<MVertex *> &interior,
                     bool alwaysTryTopology, CavityKind kind,
                     const std::vector<MElement *> &patchElements) {
        if(patchElements.empty()) return;
        if(options.quadCleanUp) {
          if(std::any_of(patchElements.begin(), patchElements.end(),
                         [](MElement *element) {
                           return !element ||
                                  element->getNumPrimaryVertices() != 4;
                         }))
            return;
          if(std::any_of(interior.begin(), interior.end(),
                         [&](MVertex *vertex) {
                           return protectedVertices.find(vertex) !=
                                  protectedVertices.end();
                         }))
            return;
        }
        std::vector<std::uintptr_t> signature;
        signature.reserve(patchElements.size());
        for(MElement *element : patchElements)
          signature.push_back(reinterpret_cast<std::uintptr_t>(element));
        std::sort(signature.begin(), signature.end());
        signature.push_back(0);
        std::vector<std::uintptr_t> interiorSignature;
        interiorSignature.reserve(interior.size());
        for(MVertex *vertex : interior)
          interiorSignature.push_back(
            reinterpret_cast<std::uintptr_t>(vertex));
        std::sort(interiorSignature.begin(), interiorSignature.end());
        signature.insert(signature.end(), interiorSignature.begin(),
                         interiorSignature.end());
        if(!signatures.insert(signature).second) return;

        CavitySeed seed;
        if(!canonicalPatchFromElements(face, patchElements, seed.patch))
          return;
        if(seed.patch.bdrVertices.size() != 1 ||
           seed.patch.bdrVertices.front().size() < 4 ||
           seed.patch.bdrVertices.front().size() > 20 ||
           seed.patch.bdrVertices.front().size() % 2 != 0 ||
           !seed.patch.embVertices.empty() ||
           !sameVertices(seed.patch.intVertices, interior))
          return;
        seed.interiorVertexCount = interior.size();
        seed.alwaysTryTopology = alwaysTryTopology;
        seed.kind = kind;
        seed.objective = specificationObjective(seed.patch.elements);
        if(options.quadCleanUp) cacheCavityValence(seed, topology);
        cavities.push_back(std::move(seed));
      };

      if(requestedKind == CavityKind::Node &&
         options.optimizeOneInteriorVertexCavities) {
        for(MVertex *vertex : face->mesh_vertices)
          if(vertex && vertex->onWhat() == face)
            add({vertex}, false, CavityKind::Node,
                unionStars({vertex}, adjacency));
      }
      if(requestedKind == CavityKind::Edge) {
        using Edge = std::pair<MVertex *, MVertex *>;
        std::map<Edge, std::vector<MElement *> > elementsByEdge;
        for(MElement *element : elements) {
          const std::size_t count = element->getNumPrimaryVertices();
          for(std::size_t i = 0; i < count; ++i) {
            MVertex *a = element->getVertex(static_cast<int>(i));
            MVertex *b = element->getVertex(
              static_cast<int>((i + 1) % count));
            if(b < a) std::swap(a, b);
            elementsByEdge[{a, b}].push_back(element);
          }
        }
        for(const auto &entry : elementsByEdge) {
          if(entry.second.size() != 2 ||
             entry.second[0]->getNumPrimaryVertices() != 4 ||
             entry.second[1]->getNumPrimaryVertices() != 4)
            continue;
          add({}, true, CavityKind::Edge, entry.second);
        }
      }
      if(requestedKind == CavityKind::Triangle &&
         options.optimizeThreeInteriorVertexCavities) {
        for(MTriangle *triangle : face->triangles) {
          std::vector<MVertex *> vertices(3);
          bool interior = true;
          for(int i = 0; i < 3; ++i) {
            vertices[static_cast<std::size_t>(i)] = triangle->getVertex(i);
            interior = interior && vertices[static_cast<std::size_t>(i)] &&
                       vertices[static_cast<std::size_t>(i)]->onWhat() == face;
          }
          if(interior)
            add(vertices, true, CavityKind::Triangle,
                unionStars(vertices, adjacency));
        }
      }
      if(requestedKind == CavityKind::Quadrangle &&
         options.optimizeFourInteriorVertexCavities) {
        for(MQuadrangle *quadrangle : face->quadrangles) {
          if(evaluateElementQuality(quadrangle).passesAbsoluteSpecifications)
            continue;
          std::vector<MVertex *> vertices(4);
          bool interior = true;
          for(int i = 0; i < 4; ++i) {
            vertices[static_cast<std::size_t>(i)] = quadrangle->getVertex(i);
            interior = interior && vertices[static_cast<std::size_t>(i)] &&
                       vertices[static_cast<std::size_t>(i)]->onWhat() == face;
          }
          if(interior)
            add(vertices, true, CavityKind::Quadrangle,
                unionStars(vertices, adjacency));
        }

        if(!options.quadCleanUp) {
          using Edge = std::pair<MVertex *, MVertex *>;
          std::map<Edge, std::vector<MTriangle *> > trianglesByEdge;
          for(MTriangle *triangle : face->triangles) {
            for(int i = 0; i < 3; ++i) {
              MVertex *a = triangle->getVertex(i);
              MVertex *b = triangle->getVertex((i + 1) % 3);
              if(b < a) std::swap(a, b);
              trianglesByEdge[{a, b}].push_back(triangle);
            }
          }
          for(const auto &entry : trianglesByEdge) {
            if(entry.second.size() != 2) continue;
            std::vector<MVertex *> vertices;
            vertices.reserve(4);
            for(MTriangle *triangle : entry.second)
              for(int i = 0; i < 3; ++i) {
                MVertex *vertex = triangle->getVertex(i);
                if(std::find(vertices.begin(), vertices.end(), vertex) ==
                     vertices.end())
                  vertices.push_back(vertex);
              }
            if(vertices.size() != 4) continue;
            bool interior = true;
            for(MVertex *vertex : vertices)
              interior = interior && vertex && vertex->onWhat() == face;
            if(interior)
              add(vertices, true, CavityKind::Quadrangle,
                  unionStars(vertices, adjacency));
          }
        }
      }
      std::sort(cavities.begin(), cavities.end(),
                [](const CavitySeed &a, const CavitySeed &b) {
                  return objectivePriority(a.objective) >
                         objectivePriority(b.objective);
                });
      return cavities;
    }

    std::vector<DiamondSeed> collectDiamonds(GFace *face)
    {
      const std::vector<MElement *> elements = surfaceElements(face);
      const Adjacency adjacency = buildAdjacency(elements);
      const FaceHalfEdgeTopology topology(elements);
      std::vector<DiamondSeed> diamonds;

      auto add = [&](MQuadrangle *quadrangle, MVertex *first,
                     MVertex *opposite) {
        if(!first || !opposite || first->onWhat() != face ||
           opposite->onWhat() != face)
          return;
        const auto firstStar = adjacency.find(first);
        const auto oppositeStar = adjacency.find(opposite);
        if(firstStar == adjacency.end() || oppositeStar == adjacency.end() ||
           firstStar->second.size() != 3 ||
           oppositeStar->second.size() != 3)
          return;
        for(MElement *element : firstStar->second)
          if(element->getNumPrimaryVertices() != 4) return;
        for(MElement *element : oppositeStar->second)
          if(element->getNumPrimaryVertices() != 4) return;

        DiamondSeed diamond;
        std::vector<MVertex *> interior = {first, opposite};
        const std::vector<MElement *> patchElements =
          unionStars(interior, adjacency);
        if(!canonicalPatchFromElements(
             face, patchElements, diamond.cavity.patch) ||
           diamond.cavity.patch.bdrVertices.size() != 1 ||
           diamond.cavity.patch.bdrVertices.front().size() < 4 ||
           diamond.cavity.patch.bdrVertices.front().size() > 20 ||
           diamond.cavity.patch.bdrVertices.front().size() % 2 != 0 ||
           !diamond.cavity.patch.embVertices.empty() ||
           !sameVertices(diamond.cavity.patch.intVertices, interior))
          return;
        const auto central = std::find(patchElements.begin(),
                                       patchElements.end(), quadrangle);
        if(central == patchElements.end()) return;
        diamond.cavity.interiorVertexCount = 2;
        diamond.cavity.alwaysTryTopology = true;
        diamond.cavity.objective =
          specificationObjective(diamond.cavity.patch.elements);
        cacheCavityValence(diamond.cavity, topology);
        diamond.diamond = quadrangle;
        const auto retained = std::min_element(
          diamond.cavity.patch.intVertices.begin(),
          diamond.cavity.patch.intVertices.end(),
          [](const MVertex *a, const MVertex *b) {
            return a->getNum() < b->getNum();
          });
        diamond.retainedInterior = static_cast<std::size_t>(
          retained - diamond.cavity.patch.intVertices.begin());
        diamond.removedInterior = 1 - diamond.retainedInterior;
        diamonds.push_back(std::move(diamond));
      };

      for(MQuadrangle *quadrangle : face->quadrangles) {
        // Only the opposite valence-three pair that is collapsed must be
        // interior to the face. The other two quad vertices may lie on model
        // curves; they remain fixed as vertices of the cavity boundary.
        add(quadrangle, quadrangle->getVertex(0), quadrangle->getVertex(2));
        add(quadrangle, quadrangle->getVertex(1), quadrangle->getVertex(3));
      }
      std::sort(diamonds.begin(), diamonds.end(),
                [](const DiamondSeed &a, const DiamondSeed &b) {
                  return objectivePriority(a.cavity.objective) >
                         objectivePriority(b.cavity.objective);
                });
      return diamonds;
    }

    std::vector<CavitySeed> collectValenceSixCavities(GFace *face)
    {
      const std::vector<MElement *> elements = surfaceElements(face);
      const Adjacency adjacency = buildAdjacency(elements);
      const FaceHalfEdgeTopology topology(elements);
      std::vector<CavitySeed> cavities;
      for(MVertex *vertex : face->mesh_vertices) {
        if(!vertex || vertex->onWhat() != face) continue;
        const auto star = adjacency.find(vertex);
        if(star == adjacency.end() || star->second.size() != 6) continue;
        bool allQuadrangles = true;
        for(MElement *element : star->second)
          allQuadrangles = allQuadrangles &&
                           element->getNumPrimaryVertices() == 4;
        if(!allQuadrangles) continue;
        CavitySeed seed;
        if(!canonicalPatchFromElements(face, star->second, seed.patch) ||
           seed.patch.bdrVertices.size() != 1 ||
           seed.patch.bdrVertices.front().size() != 12 ||
           !seed.patch.embVertices.empty() ||
           seed.patch.intVertices.size() != 1 ||
           seed.patch.intVertices.front() != vertex)
          continue;
        seed.interiorVertexCount = 1;
        seed.alwaysTryTopology = true;
        seed.objective = specificationObjective(seed.patch.elements);
        cacheCavityValence(seed, topology);
        cavities.push_back(std::move(seed));
      }
      std::sort(cavities.begin(), cavities.end(),
                [](const CavitySeed &a, const CavitySeed &b) {
                  return objectivePriority(a.objective) >
                         objectivePriority(b.objective);
                });
      return cavities;
    }

    std::set<MVertex *> neighborsAtVertex(MElement *element, MVertex *vertex)
    {
      std::set<MVertex *> neighbors;
      const std::size_t count = element->getNumPrimaryVertices();
      for(std::size_t i = 0; i < count; ++i) {
        if(element->getVertex(static_cast<int>(i)) != vertex) continue;
        neighbors.insert(element->getVertex(
          static_cast<int>((i + count - 1) % count)));
        neighbors.insert(
          element->getVertex(static_cast<int>((i + 1) % count)));
      }
      return neighbors;
    }

    bool shareEdgeAtVertex(MElement *first, MElement *second,
                           MVertex *vertex)
    {
      const std::set<MVertex *> a = neighborsAtVertex(first, vertex);
      const std::set<MVertex *> b = neighborsAtVertex(second, vertex);
      for(MVertex *neighbor : a)
        if(b.find(neighbor) != b.end()) return true;
      return false;
    }

    std::vector<CavitySeed> collectBoundaryTriangleQuadTriangleFans(
      GFace *face)
    {
      const std::vector<MElement *> elements = surfaceElements(face);
      const Adjacency adjacency = buildAdjacency(elements);
      const FaceHalfEdgeTopology topology(elements);
      if(!topology.manifold()) return {};
      std::vector<CavitySeed> cavities;
      for(const auto &entry : adjacency) {
        MVertex *vertex = entry.first;
        if(!vertex || vertex->onWhat() == face ||
           !vertex->onWhat() || vertex->onWhat()->dim() >= 2 ||
           entry.second.size() < 3)
          continue;
        std::vector<MTriangle *> triangles;
        std::vector<MQuadrangle *> quadrangles;
        bool validTypes = true;
        for(MElement *element : entry.second) {
          if(MTriangle *triangle = dynamic_cast<MTriangle *>(element))
            triangles.push_back(triangle);
          else if(MQuadrangle *quad = dynamic_cast<MQuadrangle *>(element))
            quadrangles.push_back(quad);
          else
            validTypes = false;
        }
        if(!validTypes || triangles.size() != 2 || quadrangles.empty())
          continue;

        // Around a boundary vertex, recognize the complete open chain
        //
        //   triangle - quad [- quad ...] - triangle.
        //
        // The previous test only recognized the three-element T-Q-T case.
        // In particular, a T-Q-Q-T boundary fan survived unchanged.  Testing
        // the degrees in the element adjacency graph makes this independent
        // of the (unordered) vertex-to-element adjacency storage.
        std::size_t chainEdges = 0;
        bool validChain = true;
        for(MElement *element : entry.second) {
          std::size_t degree = 0;
          for(MElement *other : entry.second) {
            if(other != element &&
               shareEdgeAtVertex(element, other, vertex))
              ++degree;
          }
          if(dynamic_cast<MTriangle *>(element)) {
            if(degree != 1) validChain = false;
          }
          else if(degree != 2)
            validChain = false;
          chainEdges += degree;
        }
        chainEdges /= 2;
        if(!validChain || chainEdges + 1 != entry.second.size()) continue;

        CavitySeed seed;
        if(!canonicalPatchFromElements(face, entry.second, seed.patch) ||
           seed.patch.bdrVertices.size() != 1 ||
           seed.patch.bdrVertices.front().size() !=
             2 * quadrangles.size() + 4 ||
           std::find(seed.patch.bdrVertices.front().begin(),
                     seed.patch.bdrVertices.front().end(), vertex) ==
             seed.patch.bdrVertices.front().end() ||
           !seed.patch.intVertices.empty() ||
           !seed.patch.embVertices.empty())
          continue;
        seed.interiorVertexCount = 0;
        seed.alwaysTryTopology = true;
        seed.kind = CavityKind::CleanUpBoundary;
        seed.objective = specificationObjective(seed.patch.elements);
        cacheCavityValence(seed, topology);
        cavities.push_back(std::move(seed));
      }
      std::sort(cavities.begin(), cavities.end(),
                [](const CavitySeed &a, const CavitySeed &b) {
                  return objectivePriority(a.objective) >
                         objectivePriority(b.objective);
                });
      return cavities;
    }

    bool boundaryParametrization(const GFaceMeshPatch &patch,
                                 std::vector<UV> &points)
    {
      const std::vector<MVertex *> &boundary = patch.bdrVertices.front();
      points.assign(boundary.size() + patch.intVertices.size(), {0., 0.});
      SPoint2 previous = patch.gf->parFromPoint(boundary.front()->point(),
                                                true, true);
      if(!std::isfinite(previous.x()) || !std::isfinite(previous.y()))
        return false;
      points[0] = {previous.x(), previous.y()};
      for(std::size_t i = 1; i < boundary.size(); ++i) {
        SPoint2 current;
        if(!reparamMeshVertexOnFaceWithRef(
             patch.gf, boundary[i], previous, current) ||
           !std::isfinite(current.x()) || !std::isfinite(current.y()))
          return false;
        points[i] = {current.x(), current.y()};
        previous = current;
      }
      UV centroid = {0., 0.};
      for(const UV &point : points) {
        centroid[0] += point[0];
        centroid[1] += point[1];
      }
      centroid[0] /= static_cast<double>(boundary.size());
      centroid[1] /= static_cast<double>(boundary.size());
      for(std::size_t i = boundary.size(); i < points.size(); ++i)
        points[i] = centroid;
      return true;
    }

    Pattern transformPattern(const Pattern &pattern, std::size_t boundaryCount,
                             std::size_t rotation, bool reflected)
    {
      Pattern transformed = pattern;
      for(auto &quad : transformed) {
        for(std::size_t &vertex : quad) {
          if(vertex >= boundaryCount) continue;
          vertex = reflected ?
            (rotation + boundaryCount - vertex) % boundaryCount :
            (vertex + rotation) % boundaryCount;
        }
        if(reflected) std::reverse(quad.begin(), quad.end());
      }
      return transformed;
    }

    using IndexedEdge = std::pair<std::size_t, std::size_t>;

    bool existingInteriorEdge(const CavitySeed &seed, IndexedEdge &edge)
    {
      if(seed.patch.elements.size() != 2 ||
         seed.patch.bdrVertices.size() != 1)
        return false;
      const std::vector<MVertex *> &boundary =
        seed.patch.bdrVertices.front();
      std::unordered_map<MVertex *, std::size_t> boundaryIndex;
      for(std::size_t i = 0; i < boundary.size(); ++i)
        boundaryIndex[boundary[i]] = i;
      using PhysicalEdge = std::pair<MVertex *, MVertex *>;
      std::map<PhysicalEdge, std::size_t> occurrences;
      for(MElement *element : seed.patch.elements) {
        if(!element || element->getNumPrimaryVertices() != 4) return false;
        for(std::size_t i = 0; i < 4; ++i) {
          MVertex *a = element->getVertex(static_cast<int>(i));
          MVertex *b = element->getVertex(static_cast<int>((i + 1) % 4));
          if(b < a) std::swap(a, b);
          ++occurrences[{a, b}];
        }
      }
      bool foundInterior = false;
      for(const auto &entry : occurrences) {
        if(entry.second != 2) continue;
        const auto a = boundaryIndex.find(entry.first.first);
        const auto b = boundaryIndex.find(entry.first.second);
        if(a == boundaryIndex.end() || b == boundaryIndex.end() ||
           foundInterior)
          return false;
        edge = {a->second, b->second};
        foundInterior = true;
      }
      return foundInterior;
    }

    bool candidateInteriorEdge(const Pattern &quadrangles,
                               std::size_t boundaryCount,
                               IndexedEdge &edge)
    {
      if(quadrangles.size() != 2) return false;
      std::map<IndexedEdge, std::size_t> occurrences;
      for(const auto &quad : quadrangles) {
        for(std::size_t i = 0; i < 4; ++i) {
          std::size_t a = quad[i], b = quad[(i + 1) % 4];
          if(a >= boundaryCount || b >= boundaryCount) return false;
          if(b < a) std::swap(a, b);
          ++occurrences[{a, b}];
        }
      }
      bool foundInterior = false;
      for(const auto &entry : occurrences) {
        if(entry.second != 2) continue;
        if(foundInterior) return false;
        edge = entry.first;
        foundInterior = true;
      }
      return foundInterior;
    }

    double orientation(const UV &a, const UV &b, const UV &point)
    {
      return (b[0] - a[0]) * (point[1] - a[1]) -
             (b[1] - a[1]) * (point[0] - a[0]);
    }

    bool properSegmentIntersection(const UV &a, const UV &b, const UV &c,
                                   const UV &d)
    {
      const double ab2 = std::pow(b[0] - a[0], 2) +
                         std::pow(b[1] - a[1], 2);
      const double cd2 = std::pow(d[0] - c[0], 2) +
                         std::pow(d[1] - c[1], 2);
      const double tolerance =
        1.e-12 * std::max({ab2, cd2, std::numeric_limits<double>::min()});
      const double abc = orientation(a, b, c);
      const double abd = orientation(a, b, d);
      const double cda = orientation(c, d, a);
      const double cdb = orientation(c, d, b);
      const bool cdOpposite =
        (abc > tolerance && abd < -tolerance) ||
        (abc < -tolerance && abd > tolerance);
      const bool abOpposite =
        (cda > tolerance && cdb < -tolerance) ||
        (cda < -tolerance && cdb > tolerance);
      return cdOpposite && abOpposite;
    }

    bool edgeSwapEdgesIntersect(const CavitySeed &seed,
                                const Pattern &candidate,
                                const std::vector<UV> &uv)
    {
      const std::size_t boundaryCount =
        seed.patch.bdrVertices.front().size();
      if(uv.size() < boundaryCount) return false;
      IndexedEdge oldEdge, newEdge;
      if(!existingInteriorEdge(seed, oldEdge) ||
         !candidateInteriorEdge(candidate, boundaryCount, newEdge))
        return false;
      return properSegmentIntersection(
        uv[oldEdge.first], uv[oldEdge.second],
        uv[newEdge.first], uv[newEdge.second]);
    }

    bool candidateQuadsAreStrictlyConvex(const Pattern &quadrangles,
                                         const std::vector<UV> &uv)
    {
      if(quadrangles.empty() || uv.empty()) return false;
      double umin = uv.front()[0], umax = uv.front()[0];
      double vmin = uv.front()[1], vmax = uv.front()[1];
      for(const UV &point : uv) {
        umin = std::min(umin, point[0]);
        umax = std::max(umax, point[0]);
        vmin = std::min(vmin, point[1]);
        vmax = std::max(vmax, point[1]);
      }
      const double scale2 = std::max(
        std::pow(umax - umin, 2) + std::pow(vmax - vmin, 2),
        std::numeric_limits<double>::min());
      const double tolerance = 1.e-12 * scale2;
      double commonSign = 0.;
      for(const auto &quad : quadrangles) {
        double sign = 0.;
        for(std::size_t i = 0; i < 4; ++i) {
          if(quad[i] >= uv.size() || quad[(i + 1) % 4] >= uv.size() ||
             quad[(i + 2) % 4] >= uv.size())
            return false;
          const double turn = orientation(
            uv[quad[i]], uv[quad[(i + 1) % 4]],
            uv[quad[(i + 2) % 4]]);
          if(std::abs(turn) <= tolerance) return false;
          if(sign == 0.)
            sign = turn;
          else if(sign * turn < 0.)
            return false;
        }
        if(commonSign == 0.)
          commonSign = sign;
        else if(commonSign * sign < 0.)
          return false;
      }
      return true;
    }

    ConnectivitySignature candidateConnectivitySignature(
      const Pattern &quadrangles, std::size_t boundaryCount,
      const std::vector<std::size_t> &interiorAssignment)
    {
      ConnectivitySignature signature = quadrangles;
      for(auto &quad : signature) {
        for(std::size_t &vertex : quad)
          if(vertex >= boundaryCount)
            vertex = boundaryCount +
              interiorAssignment[vertex - boundaryCount];
        std::sort(quad.begin(), quad.end());
      }
      std::sort(signature.begin(), signature.end());
      return signature;
    }

    bool existingConnectivitySignature(const GFaceMeshPatch &patch,
                                       ConnectivitySignature &signature)
    {
      const std::size_t boundaryCount = patch.bdrVertices.front().size();
      std::unordered_map<MVertex *, std::size_t> index;
      for(std::size_t i = 0; i < boundaryCount; ++i)
        index[patch.bdrVertices.front()[i]] = i;
      for(std::size_t i = 0; i < patch.intVertices.size(); ++i)
        index[patch.intVertices[i]] = boundaryCount + i;
      signature.clear();
      signature.reserve(patch.elements.size());
      for(MElement *element : patch.elements) {
        if(element->getNumPrimaryVertices() != 4) return false;
        std::array<std::size_t, 4> quad;
        for(std::size_t i = 0; i < 4; ++i) {
          const auto found = index.find(element->getVertex(static_cast<int>(i)));
          if(found == index.end()) return false;
          quad[i] = found->second;
        }
        std::sort(quad.begin(), quad.end());
        signature.push_back(quad);
      }
      std::sort(signature.begin(), signature.end());
      return true;
    }

    std::vector<PatternConfiguration> rankPatterns(
      const GFaceMeshPatch &patch, const std::vector<Pattern> &patterns,
      int maximum, std::size_t targetInteriorVertexCount,
      const CavitySeed *cachedSeed = nullptr)
    {
      if(maximum <= 0) return {};
      const std::size_t boundaryCount = patch.bdrVertices.front().size();
      std::vector<double> desiredLocalDegree(boundaryCount, 0.);
      if(cachedSeed &&
         cachedSeed->boundaryOutsideQuadDegree.size() == boundaryCount &&
         cachedSeed->boundaryIdealQuadDegree.size() == boundaryCount) {
        for(std::size_t i = 0; i < boundaryCount; ++i)
          desiredLocalDegree[i] = std::max(
            0., static_cast<double>(cachedSeed->boundaryIdealQuadDegree[i]) -
                  static_cast<double>(
                    cachedSeed->boundaryOutsideQuadDegree[i]));
      }
      else {
        const Adjacency globalAdjacency =
          buildAdjacency(surfaceElements(patch.gf));
        std::vector<double> currentLocalDegree(boundaryCount, 0.);
        for(MElement *element : patch.elements) {
          for(std::size_t i = 0; i < element->getNumPrimaryVertices(); ++i) {
            MVertex *vertex = element->getVertex(static_cast<int>(i));
            const auto found = std::find(
              patch.bdrVertices.front().begin(),
              patch.bdrVertices.front().end(), vertex);
            if(found != patch.bdrVertices.front().end())
              currentLocalDegree[static_cast<std::size_t>(
                found - patch.bdrVertices.front().begin())] += 1.;
          }
        }
        for(std::size_t i = 0; i < boundaryCount; ++i) {
          MVertex *vertex = patch.bdrVertices.front()[i];
          const double global =
            static_cast<double>(currentQuadDegree(vertex, globalAdjacency));
          const double outside = global - currentLocalDegree[i];
          desiredLocalDegree[i] = std::max(
            0., static_cast<double>(idealQuadDegree(
                  patch.gf, vertex, globalAdjacency)) - outside);
        }
      }

      const auto better = [](const PatternConfiguration &a,
                             const PatternConfiguration &b) {
        if(a.score != b.score) return a.score < b.score;
        if(a.pattern != b.pattern) return a.pattern < b.pattern;
        if(a.reflected != b.reflected)
          return static_cast<int>(a.reflected) <
                 static_cast<int>(b.reflected);
        return a.rotation < b.rotation;
      };
      const std::size_t limit = static_cast<std::size_t>(maximum);
      // `better` makes the worst retained configuration the heap top. This
      // keeps exactly the same deterministic top-K as the previous global
      // sort, but uses O(K) memory and O(N log K) work.
      std::priority_queue<PatternConfiguration,
                          std::vector<PatternConfiguration>,
                          decltype(better)> best(better);
      for(std::size_t p = 0; p < patterns.size(); ++p) {
        std::vector<double> degree(
          boundaryCount + targetInteriorVertexCount, 0.);
        for(const auto &quad : patterns[p])
          for(const std::size_t vertex : quad)
            if(vertex < degree.size()) degree[vertex] += 1.;
        for(bool reflected : {false, true}) {
          for(std::size_t rotation = 0; rotation < boundaryCount; ++rotation) {
            double score = 0.;
            for(std::size_t vertex = 0; vertex < boundaryCount; ++vertex) {
              const std::size_t mapped = reflected ?
                (rotation + boundaryCount - vertex) % boundaryCount :
                (vertex + rotation) % boundaryCount;
              const double difference =
                degree[vertex] - desiredLocalDegree[mapped];
              score += difference * difference;
            }
            for(std::size_t vertex = boundaryCount; vertex < degree.size();
                ++vertex) {
              const double difference = degree[vertex] - 4.;
              score += difference * difference;
            }
            const PatternConfiguration configuration = {
              score, p, rotation, reflected};
            if(best.size() < limit)
              best.push(configuration);
            else if(better(configuration, best.top())) {
              best.pop();
              best.push(configuration);
            }
          }
        }
      }
      std::vector<PatternConfiguration> ranked;
      ranked.reserve(best.size());
      while(!best.empty()) {
        ranked.push_back(best.top());
        best.pop();
      }
      std::sort(ranked.begin(), ranked.end(), better);
      return ranked;
    }

    ValenceObjective currentPatchValence(const GFaceMeshPatch &patch)
    {
      const Adjacency adjacency = buildAdjacency(surfaceElements(patch.gf));
      ValenceObjective objective;
      for(MVertex *vertex : patch.bdrVertices.front())
        addValence(objective, currentQuadDegree(vertex, adjacency),
                   idealQuadDegree(patch.gf, vertex, adjacency),
                   vertex->onWhat() == patch.gf);
      for(MVertex *vertex : patch.intVertices)
        addValence(objective, currentQuadDegree(vertex, adjacency), 4, true);
      return objective;
    }

    ValenceObjective candidatePatchValence(const CavitySeed &seed,
                                            const Pattern &quadrangles,
                                            std::size_t interiorCount)
    {
      const GFaceMeshPatch &patch = seed.patch;
      const std::size_t boundaryCount = patch.bdrVertices.front().size();
      std::vector<std::size_t> candidateDegree(
        boundaryCount + interiorCount, 0);
      for(const auto &quad : quadrangles)
        for(const std::size_t vertex : quad)
          if(vertex < candidateDegree.size()) ++candidateDegree[vertex];

      ValenceObjective objective;
      for(std::size_t i = 0; i < boundaryCount; ++i) {
        MVertex *vertex = patch.bdrVertices.front()[i];
        if(i >= seed.boundaryOutsideQuadDegree.size() ||
           i >= seed.boundaryIdealQuadDegree.size())
          return {};
        addValence(objective,
                   seed.boundaryOutsideQuadDegree[i] + candidateDegree[i],
                   seed.boundaryIdealQuadDegree[i],
                   vertex->onWhat() == patch.gf);
      }
      for(std::size_t i = 0; i < interiorCount; ++i)
        addValence(objective, candidateDegree[boundaryCount + i], 4, true);
      return objective;
    }

    double distance(const Point &a, const Point &b)
    {
      return std::sqrt(std::pow(a[0] - b[0], 2) +
                       std::pow(a[1] - b[1], 2) +
                       std::pow(a[2] - b[2], 2));
    }

    bool meanPlaneChart(const std::vector<Point> &xyz,
                        const Pattern &quadrangles, Point &origin,
                        Point &firstAxis, Point &secondAxis,
                        std::vector<UV> &planePoints)
    {
      if(xyz.size() < 3 || quadrangles.empty()) return false;
      origin = {0., 0., 0.};
      for(const Point &point : xyz)
        for(std::size_t coordinate = 0; coordinate < 3; ++coordinate)
          origin[coordinate] += point[coordinate];
      for(double &coordinate : origin)
        coordinate /= static_cast<double>(xyz.size());

      // Area-weighted Newell normal of all local quadrangles. Computing it
      // from the physical MAT points keeps the Winslow metric independent of
      // the (possibly very distorted) MVC chart.
      Point normal = {0., 0., 0.};
      for(const auto &quadrangle : quadrangles)
        for(std::size_t i = 0; i < quadrangle.size(); ++i) {
          if(quadrangle[i] >= xyz.size() ||
             quadrangle[(i + 1) % quadrangle.size()] >= xyz.size())
            return false;
          const Point &a = xyz[quadrangle[i]];
          const Point &b = xyz[quadrangle[(i + 1) % quadrangle.size()]];
          const Point ac = {a[0] - origin[0], a[1] - origin[1],
                            a[2] - origin[2]};
          const Point bc = {b[0] - origin[0], b[1] - origin[1],
                            b[2] - origin[2]};
          normal[0] += ac[1] * bc[2] - ac[2] * bc[1];
          normal[1] += ac[2] * bc[0] - ac[0] * bc[2];
          normal[2] += ac[0] * bc[1] - ac[1] * bc[0];
        }
      const double normalNorm = std::sqrt(normal[0] * normal[0] +
                                          normal[1] * normal[1] +
                                          normal[2] * normal[2]);
      if(!(normalNorm > 1.e-14)) return false;
      for(double &coordinate : normal) coordinate /= normalNorm;

      firstAxis = {0., 0., 0.};
      double firstAxisNorm = 0.;
      for(const auto &quadrangle : quadrangles)
        for(std::size_t i = 0; i < quadrangle.size(); ++i) {
          const Point &a = xyz[quadrangle[i]];
          const Point &b = xyz[quadrangle[(i + 1) % quadrangle.size()]];
          Point edge = {b[0] - a[0], b[1] - a[1], b[2] - a[2]};
          const double normalPart = edge[0] * normal[0] +
                                    edge[1] * normal[1] +
                                    edge[2] * normal[2];
          for(std::size_t coordinate = 0; coordinate < 3; ++coordinate)
            edge[coordinate] -= normalPart * normal[coordinate];
          const double edgeNorm = std::sqrt(edge[0] * edge[0] +
                                            edge[1] * edge[1] +
                                            edge[2] * edge[2]);
          if(edgeNorm > firstAxisNorm) {
            firstAxis = edge;
            firstAxisNorm = edgeNorm;
          }
        }
      if(!(firstAxisNorm > 1.e-14)) return false;
      for(double &coordinate : firstAxis) coordinate /= firstAxisNorm;
      secondAxis = {
        normal[1] * firstAxis[2] - normal[2] * firstAxis[1],
        normal[2] * firstAxis[0] - normal[0] * firstAxis[2],
        normal[0] * firstAxis[1] - normal[1] * firstAxis[0]};

      planePoints.resize(xyz.size());
      for(std::size_t i = 0; i < xyz.size(); ++i) {
        const Point delta = {xyz[i][0] - origin[0],
                             xyz[i][1] - origin[1],
                             xyz[i][2] - origin[2]};
        planePoints[i] = {
          delta[0] * firstAxis[0] + delta[1] * firstAxis[1] +
            delta[2] * firstAxis[2],
          delta[0] * secondAxis[0] + delta[1] * secondAxis[1] +
            delta[2] * secondAxis[2]};
      }
      return true;
    }

    double prescribedTargetSize(
      GFace *face, const UV &uv, const Point &xyz,
      const SmallCavityOptimizerOptions &options)
    {
      if(options.targetSize > 0.) return options.targetSize;

      // Quadqs/PACK is driven by the norm of a vector-valued background
      // field. Query that field directly when it is still available: the
      // generic BGM_MeshSize path can apply additional clamps and factors and
      // thus need not reproduce the length used during packing exactly.
      if((options.enforceSizeMap || options.auditSizeMap) && face &&
         face->model()) {
        FieldManager *fields = face->model()->getFields();
        if(fields) {
          Field *field = fields->get(fields->getBackgroundField());
          if(field && field->numComponents() == 3) {
            SVector3 value(0., 0., 0.);
            (*field)(xyz[0], xyz[1], xyz[2], value, face);
            const double size = value.norm();
            if(std::isfinite(size) && size > 0.) return size;
          }
        }
      }
      // An audit-only request is deliberately model-local: do not fall back
      // to BGM_MeshSize(), whose legacy callback is taken from
      // GModel::current() and could belong to a different model.
      if(options.auditSizeMap && !options.enforceSizeMap) return -1.;
      return BGM_MeshSize(face, uv[0], uv[1], xyz[0], xyz[1], xyz[2]);
    }

    EdgeLengthCriteria edgeLengthCriteria(
      GFace *face, const UV &uv, const Point &xyz,
      const SmallCavityOptimizerOptions &options)
    {
      if(options.edgeLengthCriteriaAt)
        return options.edgeLengthCriteriaAt(
          face, uv[0], uv[1], xyz[0], xyz[1], xyz[2]);

      EdgeLengthCriteria criteria;
      criteria.target = prescribedTargetSize(face, uv, xyz, options);
      criteria.minimum = options.enforceSizeMap &&
                           options.minimumEdgeLength > 0. ?
        options.minimumEdgeLength : 0.;
      criteria.maximum = options.enforceSizeMap &&
                           options.maximumEdgeLength > 0. ?
        options.maximumEdgeLength : std::numeric_limits<double>::infinity();
      if(options.enforceSizeMap && std::isfinite(criteria.target) &&
         criteria.target > 0.) {
        if(options.minimumEdgeSizeRatio > 0.)
          criteria.minimum = std::max(
            criteria.minimum,
            options.minimumEdgeSizeRatio * criteria.target);
        if(options.maximumEdgeSizeRatio > 0.)
          criteria.maximum = std::min(
            criteria.maximum,
            options.maximumEdgeSizeRatio * criteria.target);
      }
      return criteria;
    }

    bool validEdgeLengthCriteria(const EdgeLengthCriteria &criteria)
    {
      return std::isfinite(criteria.target) && criteria.target > 0. &&
             std::isfinite(criteria.minimum) && criteria.minimum >= 0. &&
             !std::isnan(criteria.maximum) &&
             criteria.maximum > criteria.minimum;
    }

    bool validSizeOptions(const SmallCavityOptimizerOptions &options)
    {
      if(!std::isfinite(options.targetSize) ||
         !std::isfinite(options.minimumEdgeLength) ||
         !std::isfinite(options.maximumEdgeLength) ||
         !std::isfinite(options.minimumEdgeSizeRatio) ||
         options.minimumEdgeSizeRatio < 0. ||
         !std::isfinite(options.maximumEdgeSizeRatio) ||
         options.maximumEdgeSizeRatio < 0. ||
         (options.minimumEdgeSizeRatio > 0. &&
          options.maximumEdgeSizeRatio > 0. &&
          options.maximumEdgeSizeRatio <= options.minimumEdgeSizeRatio) ||
         (options.minimumEdgeLength > 0. &&
          options.maximumEdgeLength > 0. &&
         options.maximumEdgeLength <= options.minimumEdgeLength) ||
       !std::isfinite(options.maximumRelativeSizeErrorIncrease) ||
         options.maximumRelativeSizeErrorIncrease < 0. ||
         !std::isfinite(options.minimumRecombinationQuality) ||
         options.minimumRecombinationQuality < 0.)
        return false;

      if(options.targetSize > 0. && !options.edgeLengthCriteriaAt) {
        double minimum = options.minimumEdgeLength;
        double maximum = options.maximumEdgeLength > 0. ?
          options.maximumEdgeLength : std::numeric_limits<double>::infinity();
        if(options.minimumEdgeSizeRatio > 0.)
          minimum = std::max(
            minimum, options.minimumEdgeSizeRatio * options.targetSize);
        if(options.maximumEdgeSizeRatio > 0.)
          maximum = std::min(
            maximum, options.maximumEdgeSizeRatio * options.targetSize);
        if(!(maximum > minimum)) return false;
      }
      return true;
    }

    void accumulateSizeEdge(
      SizeScore &score, double &squaredLogError,
      const EdgeLengthCriteria &criteria, double length,
      bool enforceBounds)
    {
      ++score.edgeCount;
      if(!validEdgeLengthCriteria(criteria) || !std::isfinite(length) ||
         !(length > 0.)) {
        ++score.invalid;
        if(enforceBounds) score.admissible = false;
        return;
      }
      const double ratio = length / criteria.target;
      if(!std::isfinite(ratio) || !(ratio > 0.)) {
        ++score.invalid;
        if(enforceBounds) score.admissible = false;
        return;
      }
      ++score.validEdgeCount;
      score.minimumRatio = std::min(score.minimumRatio, ratio);
      score.maximumRatio = std::max(score.maximumRatio, ratio);
      score.minimumLength = std::min(score.minimumLength, length);
      score.maximumLength = std::max(score.maximumLength, length);
      double scale = std::max(
        {1., length, criteria.target, criteria.minimum});
      if(std::isfinite(criteria.maximum))
        scale = std::max(scale, criteria.maximum);
      const double tolerance = 1.e-10 * scale;
      if(length < criteria.minimum - tolerance) {
        ++score.belowMinimum;
        if(enforceBounds) score.admissible = false;
      }
      if(length > criteria.maximum + tolerance) {
        ++score.aboveMaximum;
        if(enforceBounds) score.admissible = false;
      }
      squaredLogError += std::pow(std::log(ratio), 2);
    }

    bool isFixedCavityBoundaryEdge(
      const std::pair<std::size_t, std::size_t> &edge,
      std::size_t boundaryCount)
    {
      if(boundaryCount < 2 || edge.first >= boundaryCount ||
         edge.second >= boundaryCount)
        return false;
      return edge.second == edge.first + 1 ||
             (edge.first == 0 && edge.second + 1 == boundaryCount);
    }

    SizeScore candidateSizeScore(
      GFace *face, const std::vector<UV> &uv, const std::vector<Point> &xyz,
      const Pattern &quadrangles, const SmallCavityOptimizerOptions &options,
      std::size_t fixedBoundaryCount)
    {
      std::set<std::pair<std::size_t, std::size_t> > edges;
      for(const auto &quad : quadrangles) {
        for(std::size_t i = 0; i < 4; ++i) {
          std::size_t a = quad[i], b = quad[(i + 1) % 4];
          if(a > b) std::swap(a, b);
          edges.insert({a, b});
        }
      }
      SizeScore score;
      score.admissible = !edges.empty();
      double error = 0.;
      for(const auto &edge : edges) {
        if(edge.second >= uv.size() || edge.second >= xyz.size()) {
          ++score.edgeCount;
          ++score.invalid;
          score.admissible = false;
          continue;
        }
        const UV midpointUv = {
          .5 * (uv[edge.first][0] + uv[edge.second][0]),
          .5 * (uv[edge.first][1] + uv[edge.second][1])};
        const Point midpointXyz = {
          .5 * (xyz[edge.first][0] + xyz[edge.second][0]),
          .5 * (xyz[edge.first][1] + xyz[edge.second][1]),
          .5 * (xyz[edge.first][2] + xyz[edge.second][2])};
        const EdgeLengthCriteria criteria = edgeLengthCriteria(
          face, midpointUv, midpointXyz, options);
        const double length = distance(xyz[edge.first], xyz[edge.second]);
        // Cavity boundary edges are immutable. A pre-existing violation on
        // one of them must remain visible in the final audit, but must not
        // veto every local repair candidate sharing that boundary.
        const bool enforceBounds =
          !isFixedCavityBoundaryEdge(edge, fixedBoundaryCount);
        accumulateSizeEdge(score, error, criteria, length, enforceBounds);
      }
      if(score.edgeCount && score.invalid == 0)
        score.meanSquaredLogRatio =
          error / static_cast<double>(score.edgeCount);
      return score;
    }

    SizeScore surfacePatchSizeScore(
      GFace *face, const std::vector<UV> &uv, const std::vector<Point> &xyz,
      const std::vector<std::array<std::size_t, 3> > &triangles,
      const Pattern &quadrangles, const std::vector<bool> &fixed,
      const SmallCavityOptimizerOptions &options)
    {
      std::set<std::pair<std::size_t, std::size_t> > edges;
      auto collectEdges = [&](const auto &elements) {
        for(const auto &element : elements)
          for(std::size_t i = 0; i < element.size(); ++i) {
            std::size_t a = element[i];
            std::size_t b = element[(i + 1) % element.size()];
            if(a > b) std::swap(a, b);
            edges.insert({a, b});
          }
      };
      collectEdges(triangles);
      collectEdges(quadrangles);

      SizeScore score;
      score.admissible = !edges.empty();
      double error = 0.;
      for(const auto &edge : edges) {
        if(edge.second >= uv.size() || edge.second >= xyz.size()) {
          ++score.edgeCount;
          ++score.invalid;
          score.admissible = false;
          continue;
        }
        const UV midpointUv = {
          .5 * (uv[edge.first][0] + uv[edge.second][0]),
          .5 * (uv[edge.first][1] + uv[edge.second][1])};
        const Point midpointXyz = {
          .5 * (xyz[edge.first][0] + xyz[edge.second][0]),
          .5 * (xyz[edge.first][1] + xyz[edge.second][1]),
          .5 * (xyz[edge.first][2] + xyz[edge.second][2])};
        const EdgeLengthCriteria criteria = edgeLengthCriteria(
          face, midpointUv, midpointXyz, options);
        const bool immutable = edge.second < fixed.size() &&
                               fixed[edge.first] && fixed[edge.second];
        accumulateSizeEdge(
          score, error, criteria,
          distance(xyz[edge.first], xyz[edge.second]), !immutable);
      }
      if(score.edgeCount && score.invalid == 0)
        score.meanSquaredLogRatio =
          error / static_cast<double>(score.edgeCount);
      return score;
    }

    SizeScore existingSizeScore(
      const GFaceMeshPatch &patch,
      const SmallCavityOptimizerOptions &options,
      bool enforcePatchBoundary = true)
    {
      std::map<std::pair<MVertex *, MVertex *>, std::pair<UV, UV> > edges;
      std::map<std::pair<MVertex *, MVertex *>, std::size_t> occurrences;
      for(MElement *element : patch.elements) {
        const std::size_t count = element->getNumPrimaryVertices();
        const std::vector<SPoint2> parameters =
          persistentElementParameters(patch.gf, element);
        if(parameters.size() < count) continue;
        for(std::size_t i = 0; i < count; ++i) {
          MVertex *a = element->getVertex(static_cast<int>(i));
          MVertex *b = element->getVertex(static_cast<int>((i + 1) % count));
          UV auv = {parameters[i].x(), parameters[i].y()};
          UV buv = {parameters[(i + 1) % count].x(),
                    parameters[(i + 1) % count].y()};
          if(a > b) {
            std::swap(a, b);
            std::swap(auv, buv);
          }
          const std::pair<MVertex *, MVertex *> edge = {a, b};
          edges.emplace(edge, std::make_pair(auv, buv));
          ++occurrences[edge];
        }
      }
      SizeScore score;
      score.admissible = !edges.empty();
      double error = 0.;
      for(const auto &entry : edges) {
        MVertex *a = entry.first.first;
        MVertex *b = entry.first.second;
        const UV &auv = entry.second.first;
        const UV &buv = entry.second.second;
        const UV midpointUv = {.5 * (auv[0] + buv[0]),
                               .5 * (auv[1] + buv[1])};
        const Point midpointXyz = {.5 * (a->x() + b->x()),
                                   .5 * (a->y() + b->y()),
                                   .5 * (a->z() + b->z())};
        const Point ax = {a->x(), a->y(), a->z()};
        const Point bx = {b->x(), b->y(), b->z()};
        const EdgeLengthCriteria criteria = edgeLengthCriteria(
          patch.gf, midpointUv, midpointXyz, options);
        const bool enforceBounds = enforcePatchBoundary ||
          occurrences[entry.first] > 1;
        accumulateSizeEdge(score, error, criteria, distance(ax, bx),
                           enforceBounds);
      }
      if(score.edgeCount && score.invalid == 0)
        score.meanSquaredLogRatio =
          error / static_cast<double>(score.edgeCount);
      return score;
    }

    bool admissibleSizeChange(
      const SizeScore &before, const SizeScore &after,
      const SmallCavityOptimizerOptions &options)
    {
      if(!after.admissible) return false;
      if(!options.enforceRelativeSizeErrorIncrease ||
         !std::isfinite(before.meanSquaredLogRatio))
        return true;
      const double allowed = before.meanSquaredLogRatio *
                               (1. + options.maximumRelativeSizeErrorIncrease) +
                             1.e-14;
      return std::isfinite(after.meanSquaredLogRatio) &&
             after.meanSquaredLogRatio <= allowed;
    }

    bool betterByQualityThenSize(
      const SpecificationObjective &objective, double sizeError,
      const Candidate &reference,
      const SmallCavityOptimizerOptions &options)
    {
      if(!reference.valid) return true;
      if(improvesSpecificationObjective(
           objective, reference.objective,
           options.objectiveRelativeTolerance))
        return true;
      if(improvesSpecificationObjective(
           reference.objective, objective,
           options.objectiveRelativeTolerance))
        return false;
      return sizeError < reference.sizeError;
    }

    void setInitialSizeStatistics(
      SmallCavityOptimizerResult &result, const SizeScore &score)
    {
      result.initialEdgesBelowMinimum = score.belowMinimum;
      result.initialEdgesAboveMaximum = score.aboveMaximum;
      result.initialInvalidSizeEdges = score.invalid;
      result.initialMinimumEdgeLength = score.minimumLength;
      result.initialMaximumEdgeLength = score.maximumLength;
    }

    void setFinalSizeStatistics(
      SmallCavityOptimizerResult &result, const SizeScore &score)
    {
      result.finalEdgesBelowMinimum = score.belowMinimum;
      result.finalEdgesAboveMaximum = score.aboveMaximum;
      result.finalInvalidSizeEdges = score.invalid;
      result.finalMinimumEdgeLength = score.minimumLength;
      result.finalMaximumEdgeLength = score.maximumLength;
      result.sizeRequirementsMet =
        score.belowMinimum == 0 && score.aboveMaximum == 0 &&
        score.invalid == 0;
    }

    SizeScore faceSizeScore(
      GFace *face, const SmallCavityOptimizerOptions &options)
    {
      GFaceMeshPatch patch;
      patch.gf = face;
      patch.elements = surfaceElements(face);
      return existingSizeScore(patch, options);
    }

    SizeScore auditedFaceSizeScore(
      GFace *face, const std::vector<MElement *> &elements,
      const std::map<MElement *, std::vector<SPoint2> > &parametersByElement,
      const SmallCavityOptimizerOptions &options)
    {
      std::map<Edge, std::pair<UV, UV> > edges;
      std::set<Edge> edgesWithParameters;
      SizeScore score;
      double error = 0.;
      bool targetNeedsParameters = true;
      if(options.targetSize > 0.)
        targetNeedsParameters = false;
      else if((options.enforceSizeMap || options.auditSizeMap) && face &&
              face->model()) {
        FieldManager *fields = face->model()->getFields();
        Field *field = fields ?
          fields->get(fields->getBackgroundField()) : nullptr;
        if(field && field->numComponents() == 3)
          targetNeedsParameters = false;
      }
      for(MElement *element : elements) {
        if(!element) {
          ++score.invalid;
          continue;
        }
        const std::size_t count = element->getNumPrimaryVertices();
        const auto foundParameters = parametersByElement.find(element);
        if(count != 3 && count != 4) {
          ++score.invalid;
          continue;
        }
        const bool hasParameters =
          foundParameters != parametersByElement.end() &&
          foundParameters->second.size() >= count;
        for(std::size_t i = 0; i < count; ++i) {
          MVertex *a = element->getVertex(static_cast<int>(i));
          MVertex *b = element->getVertex(
            static_cast<int>((i + 1) % count));
          if(!a || !b) {
            ++score.invalid;
            continue;
          }
          UV auv = {0., 0.}, buv = {0., 0.};
          if(hasParameters) {
            const std::vector<SPoint2> &parameters =
              foundParameters->second;
            auv = {parameters[i].x(), parameters[i].y()};
            buv = {parameters[(i + 1) % count].x(),
                   parameters[(i + 1) % count].y()};
          }
          const Edge edge = canonicalEdge(a, b);
          if(edge.first != a) {
            std::swap(a, b);
            std::swap(auv, buv);
          }
          const auto inserted = edges.emplace(
            edge, std::make_pair(auv, buv));
          if(hasParameters) {
            if(!inserted.second) inserted.first->second = {auv, buv};
            edgesWithParameters.insert(edge);
          }
        }
      }

      score.admissible = !edges.empty() && score.invalid == 0;
      for(const auto &entry : edges) {
        MVertex *a = entry.first.first;
        MVertex *b = entry.first.second;
        if(!a || !b) {
          ++score.invalid;
          continue;
        }
        if(targetNeedsParameters &&
           edgesWithParameters.find(entry.first) ==
             edgesWithParameters.end()) {
          ++score.invalid;
          continue;
        }
        const UV &auv = entry.second.first;
        const UV &buv = entry.second.second;
        const UV midpointUv = {.5 * (auv[0] + buv[0]),
                               .5 * (auv[1] + buv[1])};
        const Point midpointXyz = {.5 * (a->x() + b->x()),
                                   .5 * (a->y() + b->y()),
                                   .5 * (a->z() + b->z())};
        const Point ax = {a->x(), a->y(), a->z()};
        const Point bx = {b->x(), b->y(), b->z()};
        const EdgeLengthCriteria criteria = edgeLengthCriteria(
          face, midpointUv, midpointXyz, options);
        accumulateSizeEdge(score, error, criteria, distance(ax, bx), true);
      }
      // Preserve useful statistics for the valid subset even if another
      // element or target-field query was unauditable.
      if(score.validEdgeCount)
        score.meanSquaredLogRatio =
          error / static_cast<double>(score.validEdgeCount);
      return score;
    }

    std::vector<CavitySeed> collectCleanUpCavities(
      GFace *face, const SmallCavityOptimizerOptions &options,
      CavityKind kind, const FaceHalfEdgeTopology &topology,
      bool criticalShapeOnly = false,
      const std::set<MVertex *> *focusVertices = nullptr)
    {
      std::vector<MElement *> elements;
      if(focusVertices) {
        std::set<MElement *> focusedElements;
        for(MVertex *vertex : *focusVertices) {
          const std::vector<MElement *> incident =
            topology.incidentElements(vertex);
          focusedElements.insert(incident.begin(), incident.end());
        }
        elements.assign(focusedElements.begin(), focusedElements.end());
      }
      else {
        elements = topology.elements();
      }
      const auto edges = kind == CavityKind::CleanUpSize ?
        topology.edges() :
        std::vector<std::pair<Edge, std::vector<MElement *> > >();

      std::vector<CavitySeed> cavities;
      std::set<std::vector<std::uintptr_t> > signatures;
      auto add = [&](const std::set<MElement *> &patchElements,
                     bool alwaysTryTopology = false) {
        if(patchElements.empty() ||
           patchElements.size() > static_cast<std::size_t>(
             options.maximumCleanUpCavityElements))
          return;
        for(MElement *element : patchElements)
          if(!element || element->getNumPrimaryVertices() != 4) return;
        std::vector<std::uintptr_t> signature;
        signature.reserve(patchElements.size());
        for(MElement *element : patchElements)
          signature.push_back(reinterpret_cast<std::uintptr_t>(element));
        std::sort(signature.begin(), signature.end());
        if(!signatures.insert(signature).second) return;

        CavitySeed seed;
        std::vector<MElement *> ordered(patchElements.begin(),
                                        patchElements.end());
        const bool patchBuilt = useFastInteractiveCleanUp(options) ?
          patchFromElements(face, ordered, seed.patch) :
          canonicalPatchFromElements(face, ordered, seed.patch);
        if(!patchBuilt ||
           seed.patch.bdrVertices.size() != 1 ||
           seed.patch.bdrVertices.front().size() < 4 ||
           seed.patch.bdrVertices.front().size() > 20 ||
           seed.patch.bdrVertices.front().size() % 2 != 0 ||
           !seed.patch.embVertices.empty())
          return;
        seed.interiorVertexCount = seed.patch.intVertices.size();
        seed.alwaysTryTopology = alwaysTryTopology;
        seed.flexibleInteriorCount = true;
        seed.kind = kind;
        seed.objective = specificationObjective(seed.patch.elements);
        cacheCavityValence(seed, topology);
        cavities.push_back(std::move(seed));
      };

      auto expandAndAdd = [&](const std::vector<MElement *> &initial,
                              bool alwaysTryTopology = false,
                              int additionalRings = -1) {
        std::set<MElement *> patch(initial.begin(), initial.end());
        add(patch, alwaysTryTopology);
        const int ringCount = additionalRings < 0 ?
          options.maximumCleanUpCavityRings :
          std::min(additionalRings, options.maximumCleanUpCavityRings);
        for(int ring = 0; ring < ringCount; ++ring) {
          std::set<MElement *> expanded = patch;
          for(MElement *element : patch) {
            const std::vector<MElement *> adjacent =
              topology.neighbors(element);
            expanded.insert(adjacent.begin(), adjacent.end());
          }
          if(expanded == patch ||
             expanded.size() > static_cast<std::size_t>(
               options.maximumCleanUpCavityElements))
            break;
          patch.swap(expanded);
          add(patch, alwaysTryTopology);
        }
      };

      if(kind == CavityKind::CleanUpConnectivity) {
        const std::vector<MVertex *> vertices = focusVertices ?
          std::vector<MVertex *>(focusVertices->begin(),
                                 focusVertices->end()) :
          topology.vertices();
        for(MVertex *vertex : vertices) {
          if(!vertex || vertex->onWhat() != face) continue;
          const std::size_t degree = topology.quadDegree(vertex);
          if(useFastInteractiveCleanUp(options)) {
            if(degree > 2 && degree < 6) continue;
          }
          else if(degree == 4) {
            // Several of Kinney's central connectivity patterns have a
            // regular valence-four center and irregular neighbors (e.g.
            // 4-43545000 and 4-34434445). Looking only at the center degree
            // misses those simple cavities entirely.
            bool irregularNeighbor = false;
            for(MElement *element : topology.incidentElements(vertex))
              for(std::size_t i = 0;
                  i < element->getNumPrimaryVertices(); ++i) {
                MVertex *neighbor = element->getVertex(
                  static_cast<int>(i));
                if(!neighbor || neighbor == vertex) continue;
                const std::size_t actual = topology.quadDegree(neighbor);
                const std::size_t ideal =
                  idealQuadDegree(face, neighbor, topology);
                if(actual != ideal) {
                  irregularNeighbor = true;
                  break;
                }
              }
            if(!irregularNeighbor) continue;
          }
          expandAndAdd(topology.incidentElements(vertex));
        }
      }
      else if(kind == CavityKind::CleanUpBoundary) {
        const std::vector<MVertex *> vertices = focusVertices ?
          std::vector<MVertex *>(focusVertices->begin(),
                                 focusVertices->end()) :
          topology.vertices();
        for(MVertex *vertex : vertices) {
          if(!vertex || vertex->onWhat() == face ||
             !vertex->onWhat() || vertex->onWhat()->dim() >= 2)
            continue;
          const long degree = static_cast<long>(topology.quadDegree(vertex));
          const long ideal = static_cast<long>(
            idealQuadDegree(face, vertex, topology));
          const double domainAngle = boundaryDomainAngleDegrees(
            face, vertex, topology.incidentElements(vertex));
          // Kinney's first boundary case has only two mesh edges and both
          // lie on the model boundary: in an all-quad mesh this is one
          // incident, triangular-shaped quad, not two incident quads. Try
          // its one- and two-row replacements when the opening exceeds 150
          // degrees.
          const bool wideTwoEdgeBoundary =
            degree == 1 && domainAngle > 150.;
          if((useFastInteractiveCleanUp(options) ?
                std::abs(degree - ideal) > 1 : degree != ideal) ||
             wideTwoEdgeBoundary)
            expandAndAdd(topology.incidentElements(vertex),
                         wideTwoEdgeBoundary,
                         wideTwoEdgeBoundary ? 1 : -1);
        }
        // Figure 15: a boundary diamond has exactly one vertex on the model
        // boundary. Its one- and two-ring patches are tried; the spec and
        // valence objective decide whether collapse is safe.
        if(!useFastInteractiveCleanUp(options)) {
          for(MElement *element : elements) {
            if(!element || element->getNumPrimaryVertices() != 4) continue;
            std::size_t boundaryVertices = 0;
            for(std::size_t i = 0; i < 4; ++i) {
              MVertex *vertex = element->getVertex(static_cast<int>(i));
              if(vertex && vertex->onWhat() != face) ++boundaryVertices;
            }
            if(boundaryVertices == 1) expandAndAdd({element});
          }
        }
      }
      else if(kind == CavityKind::CleanUpShape) {
        for(MElement *element : elements) {
          if(!element || element->getNumPrimaryVertices() != 4)
            continue;
          const ElementQuality quality = evaluateElementQuality(element);
          const SpecificationObjective objective =
            specificationObjective(quality);
          if((criticalShapeOnly || useFastInteractiveCleanUp(options)) ?
               (quality.topologicallyValid &&
                quality.passesAbsoluteSpecifications) :
               (quality.passesAbsoluteSpecifications &&
                objective.preferredViolationCount == 0))
            continue;
          expandAndAdd({element});
          for(MElement *neighbor : topology.neighbors(element))
            expandAndAdd({element, neighbor});
        }
      }
      else if(kind == CavityKind::CleanUpSize) {
        for(const auto &entry : edges) {
          if(focusVertices &&
             focusVertices->find(entry.first.first) == focusVertices->end() &&
             focusVertices->find(entry.first.second) == focusVertices->end())
            continue;
          if(entry.second.size() != 2 ||
             entry.second[0]->getNumPrimaryVertices() != 4 ||
             entry.second[1]->getNumPrimaryVertices() != 4)
            continue;
          MVertex *a = entry.first.first;
          MVertex *b = entry.first.second;
          if(!a || !b) continue;
          SPoint2 auv, buv;
          if(!persistentFaceParameter(face, a, auv) ||
             !reparamMeshVertexOnFaceWithRef(face, b, auv, buv))
            continue;
          const UV midpointUv = {.5 * (auv.x() + buv.x()),
                                 .5 * (auv.y() + buv.y())};
          const Point midpointXyz = {.5 * (a->x() + b->x()),
                                     .5 * (a->y() + b->y()),
                                     .5 * (a->z() + b->z())};
          const Point ax = {a->x(), a->y(), a->z()};
          const Point bx = {b->x(), b->y(), b->z()};
          const double length = distance(ax, bx);
          const EdgeLengthCriteria criteria = edgeLengthCriteria(
            face, midpointUv, midpointXyz, options);
          double scale = std::max(
            {1., length, criteria.target, criteria.minimum});
          if(std::isfinite(criteria.maximum))
            scale = std::max(scale, criteria.maximum);
          const double tolerance = 1.e-10 * scale;
          const bool violatesConfiguredBounds =
            options.enforceSizeMap && validEdgeLengthCriteria(criteria) &&
            (length < criteria.minimum - tolerance ||
             length > criteria.maximum + tolerance);
          const bool isLegacyLongEdge =
            !options.enforceSizeMap && validEdgeLengthCriteria(criteria) &&
            length / criteria.target > options.cleanUpLongEdgeRatio;
          if(violatesConfiguredBounds || isLegacyLongEdge)
            expandAndAdd(entry.second);
        }
      }

      std::sort(cavities.begin(), cavities.end(),
                [kind](const CavitySeed &a, const CavitySeed &b) {
                  if(kind == CavityKind::CleanUpConnectivity ||
                     kind == CavityKind::CleanUpBoundary) {
                    if(a.valence.severeCount != b.valence.severeCount)
                      return a.valence.severeCount > b.valence.severeCount;
                    if(a.valence.irregularCount != b.valence.irregularCount)
                      return a.valence.irregularCount > b.valence.irregularCount;
                    if(a.valence.penalty != b.valence.penalty)
                      return a.valence.penalty > b.valence.penalty;
                  }
                  const double ap = objectivePriority(a.objective);
                  const double bp = objectivePriority(b.objective);
                  if(ap != bp) return ap > bp;
                  return a.patch.elements.size() < b.patch.elements.size();
                });
      return cavities;
    }

    SpecificationObjective candidateObjective(
      const Pattern &quadrangles, const std::vector<Point> &xyz,
      std::size_t *invalidElementCount = nullptr)
    {
      if(invalidElementCount) *invalidElementCount = 0;
      SpecificationObjective objective;
      for(const auto &quad : quadrangles) {
        std::vector<Point> points(4);
        for(std::size_t i = 0; i < 4; ++i) points[i] = xyz[quad[i]];
        const ElementQuality quality = evaluateElementQuality(
          SurfaceElementKind::Quadrangle, points);
        if(invalidElementCount && !quality.topologicallyValid)
          ++*invalidElementCount;
        objective += specificationObjective(quality);
      }
      return objective;
    }

    std::size_t topologicallyInvalidElementCount(
      const std::vector<MElement *> &elements)
    {
      std::size_t invalid = 0;
      for(MElement *element : elements)
        if(!element || !evaluateElementQuality(element).topologicallyValid)
          ++invalid;
      return invalid;
    }

    bool edgeMidpointCadDistance(
      GFace *face, const UV &aUv, const UV &bUv, const Point &aXyz,
      const Point &bXyz, double &deviation)
    {
      deviation = 0.;
      if(!face) return false;
      // Every chord of a planar face lies on the CAD: avoid even a trivial
      // closest-point call in the common fast-cleanup case.
      if(face->geomType() == GEntity::Plane) return true;
      const UV midpointUv = {
        .5 * (aUv[0] + bUv[0]), .5 * (aUv[1] + bUv[1])};
      const Point midpointXyz = {
        .5 * (aXyz[0] + bXyz[0]), .5 * (aXyz[1] + bXyz[1]),
        .5 * (aXyz[2] + bXyz[2])};
      const double initialGuess[2] = {midpointUv[0], midpointUv[1]};
      const GPoint geometry = face->closestPoint(
        SPoint3(midpointXyz[0], midpointXyz[1], midpointXyz[2]),
        initialGuess);
      if(!geometry.succeeded() || !std::isfinite(geometry.x()) ||
         !std::isfinite(geometry.y()) || !std::isfinite(geometry.z()))
        return false;
      const Point geometryPoint = {
        geometry.x(), geometry.y(), geometry.z()};
      deviation = distance(midpointXyz, geometryPoint);
      return std::isfinite(deviation);
    }

    SpecificationObjective candidateMixedObjective(
      const std::vector<std::array<std::size_t, 3> > &triangles,
      const Pattern &quadrangles, const std::vector<Point> &xyz)
    {
      SpecificationObjective objective;
      for(const auto &triangle : triangles) {
        if(std::any_of(triangle.begin(), triangle.end(),
                       [&](std::size_t vertex) {
                         return vertex >= xyz.size();
                       })) {
          ++objective.absoluteBadElementCount;
          ++objective.absoluteViolationCount;
          objective.worstAbsoluteViolation =
            std::numeric_limits<double>::infinity();
          objective.absolutePenalty =
            std::numeric_limits<double>::infinity();
          return objective;
        }
        std::vector<Point> points(3);
        for(std::size_t i = 0; i < 3; ++i)
          points[i] = xyz[triangle[i]];
        objective += specificationObjective(evaluateElementQuality(
          SurfaceElementKind::Triangle, points));
      }
      objective += candidateObjective(quadrangles, xyz);
      return objective;
    }

    bool mapCandidate(GFace *face, std::size_t boundaryCount,
                      const std::vector<MVertex *> &boundary,
                      const std::vector<UV> &uv, std::vector<Point> &xyz)
    {
      xyz.resize(uv.size());
      for(std::size_t i = 0; i < boundaryCount; ++i)
        xyz[i] = {boundary[i]->x(), boundary[i]->y(), boundary[i]->z()};
      for(std::size_t i = boundaryCount; i < uv.size(); ++i) {
        const GPoint mapped = face->point(SPoint2(uv[i][0], uv[i][1]));
        if(!mapped.succeeded() || !std::isfinite(mapped.x()) ||
           !std::isfinite(mapped.y()) || !std::isfinite(mapped.z()))
          return false;
        xyz[i] = {mapped.x(), mapped.y(), mapped.z()};
      }
      return true;
    }

    bool accumulateGeometrySample(GFace *face, const UV &parameter,
                                  const Point &meshPoint, double areaWeight,
                                  GeometryDeviation &deviation,
                                  const SupportingPlane *supportingPlane)
    {
      if(!face || !std::isfinite(parameter[0]) ||
         !std::isfinite(parameter[1]) || !std::isfinite(areaWeight) ||
         !(areaWeight > 0.)) {
        ++deviation.invalidSampleCount;
        return false;
      }
      // Measure the actual distance from the bilinear/linear mesh sample to
      // the GFace. The interpolated parameter is only the deterministic seed
      // of the closest-point solve; using face->point(parameter) instead would
      // measure parametrization distortion and can rank two quad diagonals in
      // the opposite order from their physical CAD distance. The optional
      // supporting plane is used only by the final report and is computed
      // once per face; optimizer candidates retain the historical CAD query.
      double chordDistance = -1.;
      if(supportingPlane) {
        const Point offset = {
          meshPoint[0] - supportingPlane->origin[0],
          meshPoint[1] - supportingPlane->origin[1],
          meshPoint[2] - supportingPlane->origin[2]};
        chordDistance = std::abs(
          offset[0] * supportingPlane->unitNormal[0] +
          offset[1] * supportingPlane->unitNormal[1] +
          offset[2] * supportingPlane->unitNormal[2]);
      }
      else {
        const SPoint3 query(meshPoint[0], meshPoint[1], meshPoint[2]);
        const double initialGuess[2] = {parameter[0], parameter[1]};
        const GPoint geometry = face->closestPoint(query, initialGuess);
        if(!geometry.succeeded() || !std::isfinite(geometry.x()) ||
           !std::isfinite(geometry.y()) || !std::isfinite(geometry.z())) {
          ++deviation.invalidSampleCount;
          return false;
        }
        const Point geometryPoint = {
          geometry.x(), geometry.y(), geometry.z()};
        chordDistance = distance(meshPoint, geometryPoint);
      }
      if(!std::isfinite(chordDistance)) {
        ++deviation.invalidSampleCount;
        return false;
      }
      deviation.maximumDistance =
        std::max(deviation.maximumDistance, chordDistance);
      deviation.squaredDistanceIntegral +=
        areaWeight * chordDistance * chordDistance;
      deviation.sampledArea += areaWeight;
      return true;
    }

    bool accumulateQuadrangleGeometryDeviation(
      GFace *face, const std::array<UV, 4> &parameters,
      const std::array<Point, 4> &vertices,
      GeometryDeviation &deviation,
      const SupportingPlane *supportingPlane = nullptr)
    {
      // Tensor Gauss integration of squared closest-point distance over the
      // physical bilinear quad. This score is additive, so two alternative
      // fillings of the same cavity can be compared without an element-count
      // bias.
      static constexpr std::array<double, 3> abscissae = {
        .11270166537925831148, .5, .88729833462074168852};
      static constexpr std::array<double, 3> weights = {
        5. / 18., 8. / 18., 5. / 18.};
      for(std::size_t ir = 0; ir < abscissae.size(); ++ir) {
        const double r = abscissae[ir];
        for(std::size_t is = 0; is < abscissae.size(); ++is) {
          const double s = abscissae[is];
        const std::array<double, 4> shape = {
          (1. - r) * (1. - s), r * (1. - s), r * s, (1. - r) * s};
        UV parameter = {0., 0.};
        Point meshPoint = {0., 0., 0.};
        for(std::size_t i = 0; i < 4; ++i) {
          for(std::size_t d = 0; d < 2; ++d)
            parameter[d] += shape[i] * parameters[i][d];
          for(std::size_t d = 0; d < 3; ++d)
            meshPoint[d] += shape[i] * vertices[i][d];
        }
          const Point derivativeR = {
            -(1. - s) * vertices[0][0] + (1. - s) * vertices[1][0] +
              s * vertices[2][0] - s * vertices[3][0],
            -(1. - s) * vertices[0][1] + (1. - s) * vertices[1][1] +
              s * vertices[2][1] - s * vertices[3][1],
            -(1. - s) * vertices[0][2] + (1. - s) * vertices[1][2] +
              s * vertices[2][2] - s * vertices[3][2]};
          const Point derivativeS = {
            -(1. - r) * vertices[0][0] - r * vertices[1][0] +
              r * vertices[2][0] + (1. - r) * vertices[3][0],
            -(1. - r) * vertices[0][1] - r * vertices[1][1] +
              r * vertices[2][1] + (1. - r) * vertices[3][1],
            -(1. - r) * vertices[0][2] - r * vertices[1][2] +
              r * vertices[2][2] + (1. - r) * vertices[3][2]};
          const Point jacobian = {
            derivativeR[1] * derivativeS[2] -
              derivativeR[2] * derivativeS[1],
            derivativeR[2] * derivativeS[0] -
              derivativeR[0] * derivativeS[2],
            derivativeR[0] * derivativeS[1] -
              derivativeR[1] * derivativeS[0]};
          const double differentialArea = std::sqrt(
            jacobian[0] * jacobian[0] + jacobian[1] * jacobian[1] +
            jacobian[2] * jacobian[2]);
        if(!accumulateGeometrySample(
               face, parameter, meshPoint,
               weights[ir] * weights[is] * differentialArea, deviation,
               supportingPlane))
          return false;
        }
      }
      ++deviation.elementCount;
      return true;
    }

    bool accumulateTriangleGeometryDeviation(
      GFace *face, const std::array<UV, 3> &parameters,
      const std::array<Point, 3> &vertices,
      GeometryDeviation &deviation,
      const SupportingPlane *supportingPlane = nullptr)
    {
      // Symmetric second-order rule on the reference triangle. The weights
      // sum to one half, i.e. its reference area.
      static constexpr std::array<std::array<double, 3>, 3> samples = {{
        {{2. / 3., 1. / 6., 1. / 6.}},
        {{1. / 6., 2. / 3., 1. / 6.}},
        {{1. / 6., 1. / 6., 2. / 3.}}
      }};
      const Point firstEdge = {
        vertices[1][0] - vertices[0][0],
        vertices[1][1] - vertices[0][1],
        vertices[1][2] - vertices[0][2]};
      const Point secondEdge = {
        vertices[2][0] - vertices[0][0],
        vertices[2][1] - vertices[0][1],
        vertices[2][2] - vertices[0][2]};
      const Point jacobian = {
        firstEdge[1] * secondEdge[2] - firstEdge[2] * secondEdge[1],
        firstEdge[2] * secondEdge[0] - firstEdge[0] * secondEdge[2],
        firstEdge[0] * secondEdge[1] - firstEdge[1] * secondEdge[0]};
      const double differentialArea = std::sqrt(
        jacobian[0] * jacobian[0] + jacobian[1] * jacobian[1] +
        jacobian[2] * jacobian[2]);
      for(const auto &shape : samples) {
        UV parameter = {0., 0.};
        Point meshPoint = {0., 0., 0.};
        for(std::size_t i = 0; i < 3; ++i) {
          for(std::size_t d = 0; d < 2; ++d)
            parameter[d] += shape[i] * parameters[i][d];
          for(std::size_t d = 0; d < 3; ++d)
            meshPoint[d] += shape[i] * vertices[i][d];
        }
        if(!accumulateGeometrySample(
             face, parameter, meshPoint, differentialArea / 6., deviation,
             supportingPlane))
          return false;
      }
      ++deviation.elementCount;
      return true;
    }

    GeometryDeviation candidateGeometryDeviation(
      GFace *face, const std::vector<UV> &uv,
      const std::vector<Point> &xyz, const Pattern &quadrangles)
    {
      GeometryDeviation deviation;
      deviation.maximumDistance = 0.;
      deviation.squaredDistanceIntegral = 0.;
      for(const auto &quad : quadrangles) {
        std::array<UV, 4> parameters;
        std::array<Point, 4> vertices;
        for(std::size_t i = 0; i < 4; ++i) {
          if(quad[i] >= uv.size() || quad[i] >= xyz.size()) return deviation;
          parameters[i] = uv[quad[i]];
          vertices[i] = xyz[quad[i]];
        }
        if(!accumulateQuadrangleGeometryDeviation(
             face, parameters, vertices, deviation))
          return deviation;
      }
      if(!deviation.elementCount || !(deviation.sampledArea > 0.))
        return deviation;
      deviation.meanSquaredDistance = deviation.squaredDistanceIntegral /
        deviation.sampledArea;
      deviation.valid = deviation.invalidSampleCount == 0 &&
        std::isfinite(deviation.maximumDistance) &&
        std::isfinite(deviation.squaredDistanceIntegral) &&
        std::isfinite(deviation.meanSquaredDistance);
      return deviation;
    }

    GeometryDeviation candidateMixedGeometryDeviation(
      GFace *face, const std::vector<UV> &uv,
      const std::vector<Point> &xyz,
      const std::vector<std::array<std::size_t, 3> > &triangles,
      const Pattern &quadrangles)
    {
      GeometryDeviation deviation;
      deviation.maximumDistance = 0.;
      deviation.squaredDistanceIntegral = 0.;
      for(const auto &triangle : triangles) {
        std::array<UV, 3> parameters;
        std::array<Point, 3> vertices;
        for(std::size_t i = 0; i < 3; ++i) {
          if(triangle[i] >= uv.size() || triangle[i] >= xyz.size())
            return deviation;
          parameters[i] = uv[triangle[i]];
          vertices[i] = xyz[triangle[i]];
        }
        if(!accumulateTriangleGeometryDeviation(
             face, parameters, vertices, deviation))
          return deviation;
      }
      for(const auto &quad : quadrangles) {
        std::array<UV, 4> parameters;
        std::array<Point, 4> vertices;
        for(std::size_t i = 0; i < 4; ++i) {
          if(quad[i] >= uv.size() || quad[i] >= xyz.size()) return deviation;
          parameters[i] = uv[quad[i]];
          vertices[i] = xyz[quad[i]];
        }
        if(!accumulateQuadrangleGeometryDeviation(
             face, parameters, vertices, deviation))
          return deviation;
      }
      if(!deviation.elementCount || !(deviation.sampledArea > 0.))
        return deviation;
      deviation.meanSquaredDistance = deviation.squaredDistanceIntegral /
        deviation.sampledArea;
      deviation.valid = deviation.invalidSampleCount == 0 &&
        std::isfinite(deviation.maximumDistance) &&
        std::isfinite(deviation.squaredDistanceIntegral) &&
        std::isfinite(deviation.meanSquaredDistance);
      return deviation;
    }

    GeometryDeviation existingGeometryDeviation(
      GFace *face, const std::vector<MElement *> &elements)
    {
      GeometryDeviation deviation;
      deviation.maximumDistance = 0.;
      deviation.squaredDistanceIntegral = 0.;
      for(MElement *element : elements) {
        if(!element) return deviation;
        const std::size_t count = element->getNumPrimaryVertices();
        if(count != 3 && count != 4) return deviation;
        const std::vector<SPoint2> parameters =
          persistentElementParameters(face, element);
        if(parameters.size() < count) return deviation;
        if(count == 4) {
          std::array<UV, 4> uv;
          std::array<Point, 4> xyz;
          for(std::size_t i = 0; i < 4; ++i) {
            MVertex *vertex = element->getVertex(static_cast<int>(i));
            uv[i] = {parameters[i].x(), parameters[i].y()};
            xyz[i] = {vertex->x(), vertex->y(), vertex->z()};
          }
          if(!accumulateQuadrangleGeometryDeviation(
               face, uv, xyz, deviation))
            return deviation;
        }
        else {
          std::array<UV, 3> uv;
          std::array<Point, 3> xyz;
          for(std::size_t i = 0; i < 3; ++i) {
            MVertex *vertex = element->getVertex(static_cast<int>(i));
            uv[i] = {parameters[i].x(), parameters[i].y()};
            xyz[i] = {vertex->x(), vertex->y(), vertex->z()};
          }
          if(!accumulateTriangleGeometryDeviation(
               face, uv, xyz, deviation))
            return deviation;
        }
      }
      if(!deviation.elementCount || !(deviation.sampledArea > 0.))
        return deviation;
      deviation.meanSquaredDistance = deviation.squaredDistanceIntegral /
        deviation.sampledArea;
      deviation.valid = deviation.invalidSampleCount == 0 &&
        std::isfinite(deviation.maximumDistance) &&
        std::isfinite(deviation.squaredDistanceIntegral) &&
        std::isfinite(deviation.meanSquaredDistance);
      return deviation;
    }

    GeometryDeviation auditedElementGeometryDeviation(
      GFace *face, MElement *element,
      const std::vector<SPoint2> &parameters,
      const SupportingPlane *supportingPlane)
    {
      GeometryDeviation deviation;
      deviation.maximumDistance = 0.;
      deviation.squaredDistanceIntegral = 0.;
      if(!face || !element) return deviation;
      const std::size_t count = element->getNumPrimaryVertices();
      const bool haveParameters = parameters.size() >= count;
      // The UV values seed every closest-point query on curved CAD. Falling
      // back to (0, 0) can converge to another branch and falsely report full
      // CAD coverage. A plane is the only safe exception: its distance is
      // evaluated analytically from the supporting geometric plane.
      if(!haveParameters && !supportingPlane)
        return deviation;
      if(count == 4) {
        std::array<UV, 4> uv;
        std::array<Point, 4> xyz;
        for(std::size_t i = 0; i < 4; ++i) {
          MVertex *vertex = element->getVertex(static_cast<int>(i));
          if(!vertex) return deviation;
          uv[i] = haveParameters ?
            UV{parameters[i].x(), parameters[i].y()} : UV{0., 0.};
          xyz[i] = {vertex->x(), vertex->y(), vertex->z()};
        }
        if(!accumulateQuadrangleGeometryDeviation(
             face, uv, xyz, deviation, supportingPlane))
          return deviation;
      }
      else if(count == 3) {
        std::array<UV, 3> uv;
        std::array<Point, 3> xyz;
        for(std::size_t i = 0; i < 3; ++i) {
          MVertex *vertex = element->getVertex(static_cast<int>(i));
          if(!vertex) return deviation;
          uv[i] = haveParameters ?
            UV{parameters[i].x(), parameters[i].y()} : UV{0., 0.};
          xyz[i] = {vertex->x(), vertex->y(), vertex->z()};
        }
        if(!accumulateTriangleGeometryDeviation(
             face, uv, xyz, deviation, supportingPlane))
          return deviation;
      }
      else {
        return deviation;
      }
      if(!deviation.elementCount || !(deviation.sampledArea > 0.))
        return deviation;
      deviation.meanSquaredDistance = deviation.squaredDistanceIntegral /
        deviation.sampledArea;
      deviation.valid = deviation.invalidSampleCount == 0 &&
        std::isfinite(deviation.maximumDistance) &&
        std::isfinite(deviation.squaredDistanceIntegral) &&
        std::isfinite(deviation.meanSquaredDistance);
      return deviation;
    }

    bool candidateQuadranglesArePhysicallyNonConcave(
      const Pattern &quadrangles, const std::vector<Point> &xyz)
    {
      constexpr double concavityToleranceDegrees = 1.e-8;
      for(const auto &quad : quadrangles) {
        std::vector<Point> points(4);
        for(std::size_t i = 0; i < 4; ++i) {
          if(quad[i] >= xyz.size()) return false;
          points[i] = xyz[quad[i]];
        }
        const ElementQuality quality = evaluateElementQuality(
          SurfaceElementKind::Quadrangle, points);
        if(!quality.topologicallyValid ||
           !std::isfinite(quality.maximumAngleDegrees) ||
           quality.maximumAngleDegrees >=
             180. - concavityToleranceDegrees)
          return false;
      }
      return true;
    }

    bool candidateQuadranglesAreNonConcave(
      const Pattern &quadrangles, const std::vector<UV> &uv,
      const std::vector<Point> &xyz)
    {
      if(!candidateQuadsAreStrictlyConvex(quadrangles, uv)) return false;
      return candidateQuadranglesArePhysicallyNonConcave(quadrangles, xyz);
    }

    bool hasConcaveQuadrangle(const std::vector<MElement *> &elements)
    {
      constexpr double concavityToleranceDegrees = 1.e-8;
      for(MElement *element : elements) {
        if(!element || element->getNumPrimaryVertices() != 4) continue;
        const ElementQuality quality = evaluateElementQuality(element);
        if(!quality.topologicallyValid ||
           !std::isfinite(quality.maximumAngleDegrees) ||
           quality.maximumAngleDegrees >=
             180. - concavityToleranceDegrees)
          return true;
      }
      return false;
    }

    bool executeCandidate(GFace *face, const CavitySeed &seed,
                          const Candidate &candidate,
                          std::vector<MVertex *> *createdInterior = nullptr)
    {
      if(touchesBoundaryLayerElementData(face, seed.patch.elements))
        return false;
      const std::size_t boundaryCount = seed.patch.bdrVertices.front().size();
      std::vector<MVertex *> localVertices = seed.patch.bdrVertices.front();
      if(candidate.interiorAssignment.size() > seed.patch.intVertices.size())
        return false;
      std::set<std::size_t> retainedIndices;
      for(std::size_t i = 0; i < candidate.interiorAssignment.size(); ++i) {
        const std::size_t old = candidate.interiorAssignment[i];
        if(old >= seed.patch.intVertices.size() ||
           !retainedIndices.insert(old).second)
          return false;
        localVertices.push_back(seed.patch.intVertices[old]);
      }

      std::vector<MElement *> newElements;
      newElements.reserve(candidate.quadrangles.size());
      for(const auto &quad : candidate.quadrangles)
        newElements.push_back(new MQuadrangle(localVertices[quad[0]],
                                              localVertices[quad[1]],
                                              localVertices[quad[2]],
                                              localVertices[quad[3]]));
      if(!orientElementsAccordingToBoundarySegment(
           seed.patch.bdrVertices.front()[0],
           seed.patch.bdrVertices.front()[1], newElements)) {
        for(MElement *element : newElements) delete element;
        return false;
      }
      FaceHalfEdgeTopology validatedTopology(surfaceElements(face));
      if(!validatedTopology.manifold() ||
         !validatedTopology.replace(seed.patch.elements, newElements)) {
        for(MElement *element : newElements) delete element;
        return false;
      }

      GFaceMeshDiff diff;
      diff.gf = face;
      diff.before = seed.patch;
      // Preserve every retained MVertex object and number. A collapse lists
      // only the discarded interior vertex here, so GFaceMeshDiff deletes it.
      diff.before.intVertices.clear();
      for(std::size_t i = 0; i < seed.patch.intVertices.size(); ++i)
        if(retainedIndices.find(i) == retainedIndices.end())
          diff.before.intVertices.push_back(seed.patch.intVertices[i]);
      diff.after.gf = face;
      diff.after.bdrVertices = seed.patch.bdrVertices;
      diff.after.elements = std::move(newElements);
      if(!diff.execute(true)) return false;

      std::vector<MVertex *> retainedInterior;
      retainedInterior.reserve(candidate.interiorAssignment.size());
      for(std::size_t i = 0; i < candidate.interiorAssignment.size(); ++i) {
        MVertex *vertex = seed.patch.intVertices[candidate.interiorAssignment[i]];
        const std::size_t local = boundaryCount + i;
        vertex->setXYZ(candidate.xyz[local][0], candidate.xyz[local][1],
                       candidate.xyz[local][2]);
        vertex->setParameter(0, candidate.uv[local][0]);
        vertex->setParameter(1, candidate.uv[local][1]);
        retainedInterior.push_back(vertex);
      }
      if(createdInterior) *createdInterior = std::move(retainedInterior);
      return true;
    }

    bool executeValenceSixCandidate(
      GFace *face, const CavitySeed &seed, const Candidate &candidate,
      std::vector<MVertex *> &resultInterior)
    {
      if(touchesBoundaryLayerElementData(face, seed.patch.elements))
        return false;
      const std::size_t boundaryCount =
        seed.patch.bdrVertices.front().size();
      if(seed.patch.intVertices.size() != 1 ||
         candidate.uv.size() != boundaryCount + 2 ||
         candidate.xyz.size() != boundaryCount + 2)
        return false;
      MVertex *existing = seed.patch.intVertices.front();
      MVertex *created = new MFaceVertex(
        candidate.xyz[boundaryCount + 1][0],
        candidate.xyz[boundaryCount + 1][1],
        candidate.xyz[boundaryCount + 1][2], face,
        candidate.uv[boundaryCount + 1][0],
        candidate.uv[boundaryCount + 1][1]);
      std::vector<MVertex *> localVertices =
        seed.patch.bdrVertices.front();
      localVertices.push_back(existing);
      localVertices.push_back(created);

      std::vector<MElement *> newElements;
      newElements.reserve(candidate.quadrangles.size());
      for(const auto &quad : candidate.quadrangles)
        newElements.push_back(new MQuadrangle(localVertices[quad[0]],
                                              localVertices[quad[1]],
                                              localVertices[quad[2]],
                                              localVertices[quad[3]]));
      if(!orientElementsAccordingToBoundarySegment(
           seed.patch.bdrVertices.front()[0],
           seed.patch.bdrVertices.front()[1], newElements)) {
        for(MElement *element : newElements) delete element;
        delete created;
        return false;
      }
      FaceHalfEdgeTopology validatedTopology(surfaceElements(face));
      if(!validatedTopology.manifold() ||
         !validatedTopology.replace(seed.patch.elements, newElements)) {
        for(MElement *element : newElements) delete element;
        delete created;
        return false;
      }

      GFaceMeshDiff diff;
      diff.gf = face;
      diff.before = seed.patch;
      // Keep the original valence-six MVertex and add exactly one new vertex.
      diff.before.intVertices.clear();
      diff.after.gf = face;
      diff.after.bdrVertices = seed.patch.bdrVertices;
      diff.after.intVertices = {created};
      diff.after.elements = std::move(newElements);
      if(!diff.execute(true)) return false;

      existing->setXYZ(candidate.xyz[boundaryCount][0],
                       candidate.xyz[boundaryCount][1],
                       candidate.xyz[boundaryCount][2]);
      existing->setParameter(0, candidate.uv[boundaryCount][0]);
      existing->setParameter(1, candidate.uv[boundaryCount][1]);
      resultInterior = {existing, created};
      return true;
    }

    bool executeNewInteriorCandidate(
      GFace *face, const CavitySeed &seed, const Candidate &candidate,
      MVertex *&createdInterior)
    {
      if(touchesBoundaryLayerElementData(face, seed.patch.elements))
        return false;
      const std::size_t boundaryCount =
        seed.patch.bdrVertices.front().size();
      if(!seed.patch.intVertices.empty() ||
         candidate.uv.size() != boundaryCount + 1 ||
         candidate.xyz.size() != boundaryCount + 1)
        return false;
      MVertex *created = new MFaceVertex(
        candidate.xyz[boundaryCount][0],
        candidate.xyz[boundaryCount][1],
        candidate.xyz[boundaryCount][2], face,
        candidate.uv[boundaryCount][0], candidate.uv[boundaryCount][1]);
      std::vector<MVertex *> localVertices =
        seed.patch.bdrVertices.front();
      localVertices.push_back(created);
      std::vector<MElement *> newElements;
      newElements.reserve(candidate.quadrangles.size());
      for(const auto &quad : candidate.quadrangles)
        newElements.push_back(new MQuadrangle(localVertices[quad[0]],
                                              localVertices[quad[1]],
                                              localVertices[quad[2]],
                                              localVertices[quad[3]]));
      if(!orientElementsAccordingToBoundarySegment(
           seed.patch.bdrVertices.front()[0],
           seed.patch.bdrVertices.front()[1], newElements)) {
        for(MElement *element : newElements) delete element;
        delete created;
        return false;
      }
      FaceHalfEdgeTopology validatedTopology(surfaceElements(face));
      if(!validatedTopology.manifold() ||
         !validatedTopology.replace(seed.patch.elements, newElements)) {
        for(MElement *element : newElements) delete element;
        delete created;
        return false;
      }
      GFaceMeshDiff diff;
      diff.gf = face;
      diff.before = seed.patch;
      diff.after.gf = face;
      diff.after.bdrVertices = seed.patch.bdrVertices;
      diff.after.intVertices = {created};
      diff.after.elements = std::move(newElements);
      if(!diff.execute(true)) return false;
      createdInterior = created;
      return true;
    }

    bool executeFlexibleCandidate(
      GFace *face, const CavitySeed &seed, const Candidate &candidate,
      std::vector<MVertex *> &resultInterior,
      std::vector<MElement *> *resultElements = nullptr,
      FaceHalfEdgeTopology *topology = nullptr)
    {
      if(touchesBoundaryLayerElementData(face, seed.patch.elements))
        return false;
      const std::size_t boundaryCount =
        seed.patch.bdrVertices.front().size();
      if(candidate.uv.size() < boundaryCount ||
         candidate.xyz.size() != candidate.uv.size() ||
         candidate.interiorAssignment.size() !=
           candidate.uv.size() - boundaryCount)
        return false;

      const std::size_t createdMarker =
        std::numeric_limits<std::size_t>::max();
      std::vector<MVertex *> localVertices =
        seed.patch.bdrVertices.front();
      std::vector<MVertex *> created;
      std::set<std::size_t> retainedIndices;
      for(std::size_t i = 0; i < candidate.interiorAssignment.size(); ++i) {
        const std::size_t assignment = candidate.interiorAssignment[i];
        const std::size_t local = boundaryCount + i;
        if(assignment == createdMarker) {
          MVertex *vertex = new MFaceVertex(
            candidate.xyz[local][0], candidate.xyz[local][1],
            candidate.xyz[local][2], face, candidate.uv[local][0],
            candidate.uv[local][1]);
          created.push_back(vertex);
          localVertices.push_back(vertex);
        }
        else {
          if(assignment >= seed.patch.intVertices.size() ||
             !retainedIndices.insert(assignment).second) {
            for(MVertex *vertex : created) delete vertex;
            return false;
          }
          localVertices.push_back(seed.patch.intVertices[assignment]);
        }
      }

      std::vector<MElement *> newElements;
      newElements.reserve(candidate.quadrangles.size());
      for(const auto &quad : candidate.quadrangles) {
        bool valid = true;
        for(const std::size_t vertex : quad)
          valid = valid && vertex < localVertices.size();
        if(!valid) {
          for(MElement *element : newElements) delete element;
          for(MVertex *vertex : created) delete vertex;
          return false;
        }
        newElements.push_back(new MQuadrangle(
          localVertices[quad[0]], localVertices[quad[1]],
          localVertices[quad[2]], localVertices[quad[3]]));
      }
      if(!orientElementsAccordingToBoundarySegment(
           seed.patch.bdrVertices.front()[0],
           seed.patch.bdrVertices.front()[1], newElements)) {
        for(MElement *element : newElements) delete element;
        for(MVertex *vertex : created) delete vertex;
        return false;
      }

      // Validate the complete topological transaction before GFaceMeshDiff
      // deletes any old element or vertex. In particular, a duplicate quad
      // would otherwise create four third edge incidences and leave both the
      // mesh and the side-car half-edge index partially modified.
      FaceHalfEdgeTopology validatedTopology = topology ?
        *topology : FaceHalfEdgeTopology(surfaceElements(face));
      if(!validatedTopology.manifold() ||
         !validatedTopology.replace(seed.patch.elements, newElements)) {
        for(MElement *element : newElements) delete element;
        for(MVertex *vertex : created) delete vertex;
        return false;
      }

      GFaceMeshDiff diff;
      diff.gf = face;
      diff.before = seed.patch;
      diff.before.intVertices.clear();
      for(std::size_t i = 0; i < seed.patch.intVertices.size(); ++i)
        if(retainedIndices.find(i) == retainedIndices.end())
          diff.before.intVertices.push_back(seed.patch.intVertices[i]);
      diff.after.gf = face;
      diff.after.bdrVertices = seed.patch.bdrVertices;
      diff.after.intVertices = created;
      const std::vector<MElement *> insertedElements = newElements;
      diff.after.elements = std::move(newElements);
      if(!diff.execute(true)) return false;
      if(topology) *topology = std::move(validatedTopology);

      resultInterior.clear();
      resultInterior.reserve(candidate.interiorAssignment.size());
      std::size_t createdIndex = 0;
      for(std::size_t i = 0; i < candidate.interiorAssignment.size(); ++i) {
        const std::size_t assignment = candidate.interiorAssignment[i];
        const std::size_t local = boundaryCount + i;
        MVertex *vertex = assignment == createdMarker ?
          created[createdIndex++] : seed.patch.intVertices[assignment];
        vertex->setXYZ(candidate.xyz[local][0], candidate.xyz[local][1],
                       candidate.xyz[local][2]);
        vertex->setParameter(0, candidate.uv[local][0]);
        vertex->setParameter(1, candidate.uv[local][1]);
        resultInterior.push_back(vertex);
      }
      if(resultElements) *resultElements = insertedElements;
      return true;
    }

    bool interiorVertexCavity(GFace *face,
                              const std::vector<MVertex *> &interior,
                              const Adjacency &adjacency, CavitySeed &seed,
                              bool canonicalize = true)
    {
      if(interior.empty()) return false;
      for(MVertex *vertex : interior)
        if(!vertex || vertex->onWhat() != face) return false;
      const std::vector<MElement *> patchElements =
        unionStars(interior, adjacency);
      const bool patchBuilt = canonicalize ?
        canonicalPatchFromElements(face, patchElements, seed.patch) :
        patchFromElements(face, patchElements, seed.patch);
      if(patchElements.empty() || !patchBuilt ||
         seed.patch.bdrVertices.size() != 1 ||
         seed.patch.bdrVertices.front().size() < 4 ||
         seed.patch.bdrVertices.front().size() % 2 != 0 ||
         !seed.patch.embVertices.empty() ||
         !sameVertices(seed.patch.intVertices, interior))
        return false;
      seed.interiorVertexCount = interior.size();
      seed.objective = specificationObjective(seed.patch.elements);
      return true;
    }

    bool interiorVertexCavity(GFace *face,
                              const std::vector<MVertex *> &interior,
                              const FaceHalfEdgeTopology &topology,
                              CavitySeed &seed,
                              bool canonicalize = true)
    {
      if(interior.empty()) return false;
      std::set<MElement *> unique;
      for(MVertex *vertex : interior) {
        if(!vertex || vertex->onWhat() != face) return false;
        const std::vector<MElement *> incident =
          topology.incidentElements(vertex);
        if(incident.empty()) return false;
        unique.insert(incident.begin(), incident.end());
      }
      const std::vector<MElement *> patchElements(unique.begin(), unique.end());
      const bool patchBuilt = canonicalize ?
        canonicalPatchFromElements(face, patchElements, seed.patch) :
        patchFromElements(face, patchElements, seed.patch);
      if(!patchBuilt ||
         seed.patch.bdrVertices.size() != 1 ||
         seed.patch.bdrVertices.front().size() < 4 ||
         seed.patch.bdrVertices.front().size() % 2 != 0 ||
         !seed.patch.embVertices.empty() ||
         !sameVertices(seed.patch.intVertices, interior))
        return false;
      seed.interiorVertexCount = interior.size();
      seed.objective = specificationObjective(seed.patch.elements);
      return true;
    }

    bool fourInteriorVertexCavity(GFace *face, MQuadrangle *quadrangle,
                                  const Adjacency &adjacency,
                                  CavitySeed &seed)
    {
      std::vector<MVertex *> interior(4);
      for(int i = 0; i < 4; ++i) {
        interior[static_cast<std::size_t>(i)] = quadrangle->getVertex(i);
        if(!interior[static_cast<std::size_t>(i)] ||
           interior[static_cast<std::size_t>(i)]->onWhat() != face)
          return false;
      }
      return interiorVertexCavity(face, interior, adjacency, seed) &&
        seed.patch.bdrVertices.front().size() <= 20;
    }

    bool currentParametrization(const GFaceMeshPatch &patch,
                                std::vector<UV> &points)
    {
      if(!boundaryParametrization(patch, points)) return false;
      const std::size_t boundaryCount =
        patch.bdrVertices.front().size();
      for(std::size_t i = 0; i < patch.intVertices.size(); ++i) {
        MVertex *vertex = patch.intVertices[i];
        double u = 0., v = 0.;
        // Cached UV coordinates on a discrete surface disappear when the
        // mesh is saved without Mesh.SaveParametric. Reconstruct them from
        // the physical point on every pass so that optimization in memory
        // and optimization after reload follow the same decision path.
        if(patch.gf->geomType() == GEntity::DiscreteSurface ||
           !vertex->getParameter(0, u) || !vertex->getParameter(1, v) ||
           !std::isfinite(u) || !std::isfinite(v)) {
          const SPoint2 parameter =
            patch.gf->parFromPoint(vertex->point(), true, true);
          u = parameter.x();
          v = parameter.y();
        }
        if(!std::isfinite(u) || !std::isfinite(v)) return false;
        points[boundaryCount + i] = {u, v};
      }
      return true;
    }

    bool existingPatternAndParametrization(const CavitySeed &seed,
                                           std::vector<UV> &points,
                                           Pattern &quadrangles)
    {
      if(!currentParametrization(seed.patch, points)) return false;
      const std::size_t boundaryCount =
        seed.patch.bdrVertices.front().size();
      std::unordered_map<MVertex *, std::size_t> index;
      for(std::size_t i = 0; i < boundaryCount; ++i)
        index[seed.patch.bdrVertices.front()[i]] = i;
      for(std::size_t i = 0; i < seed.patch.intVertices.size(); ++i)
        index[seed.patch.intVertices[i]] = boundaryCount + i;

      quadrangles.clear();
      quadrangles.reserve(seed.patch.elements.size());
      for(MElement *element : seed.patch.elements) {
        if(element->getNumPrimaryVertices() != 4) return false;
        std::array<std::size_t, 4> quad;
        for(std::size_t i = 0; i < 4; ++i) {
          const auto found = index.find(element->getVertex(static_cast<int>(i)));
          if(found == index.end()) return false;
          quad[i] = found->second;
        }
        quadrangles.push_back(quad);
      }
      return !quadrangles.empty();
    }

    bool smoothZeroInteriorCandidate(
      GFace *face, const CavitySeed &seed, Candidate &candidate,
      const SmallCavityOptimizerOptions &options,
      SmallCavityOptimizerResult &result)
    {
      const std::size_t coreBoundaryCount =
        seed.patch.bdrVertices.front().size();
      if(!face || !candidate.interiorAssignment.empty() ||
         candidate.uv.size() != coreBoundaryCount ||
         candidate.xyz.size() != coreBoundaryCount)
        return false;

      const std::vector<MElement *> faceElements = surfaceElements(face);
      const Adjacency adjacency = buildAdjacency(faceElements);
      const std::set<MVertex *> protectedVertices =
        protectedFaceVertices(face);
      const std::set<MElement *> coreElements(seed.patch.elements.begin(),
                                              seed.patch.elements.end());
      std::set<MElement *> outsideSet;
      bool hasMovableVertex = false;
      for(MVertex *vertex : seed.patch.bdrVertices.front()) {
        if(!vertex || vertex->onWhat() != face ||
           protectedVertices.find(vertex) != protectedVertices.end())
          continue;
        const auto found = adjacency.find(vertex);
        if(found == adjacency.end()) continue;
        // A triangle or an embedded feature acts as a fixed boundary for the
        // all-quad CleanUp smoother. Do not move a vertex unless its complete
        // star can be included in the validation patch.
        if(std::any_of(found->second.begin(), found->second.end(),
                       [](MElement *element) {
                         return !element ||
                           element->getNumPrimaryVertices() != 4;
                       }))
          continue;
        hasMovableVertex = true;
        for(MElement *element : found->second)
          if(coreElements.find(element) == coreElements.end())
            outsideSet.insert(element);
      }

      candidate.hasSmoothedReference = true;
      candidate.smoothedReferenceObjective = seed.objective;
      if(!hasMovableVertex) {
        // Vacuous smoothing: every vertex is permanent, but the final
        // candidate still has to pass the same size transaction as a movable
        // one-ring.
        const SizeScore beforeSize = existingSizeScore(
          seed.patch, options, false);
        const SizeScore afterSize = candidateSizeScore(
          face, candidate.uv, candidate.xyz, candidate.quadrangles, options,
          coreBoundaryCount);
        const bool checkSize = options.quadCleanUp ||
                               options.enforceSizeMap ||
                               seed.kind == CavityKind::CleanUpSize;
        const bool preservesTarget = !options.enforceSizeMap ||
          admissibleSizeChange(beforeSize, afterSize, options);
        if(checkSize && (!afterSize.admissible || !preservesTarget)) {
          ++result.rejectedBySize;
          return false;
        }
        candidate.smoothedReferenceSizeError =
          beforeSize.meanSquaredLogRatio;
        candidate.smoothedReferenceSizeViolationCount =
          beforeSize.belowMinimum + beforeSize.aboveMaximum +
          beforeSize.invalid;
        candidate.sizeError = afterSize.meanSquaredLogRatio;
        candidate.sizeViolationCount =
          afterSize.belowMinimum + afterSize.aboveMaximum + afterSize.invalid;
        candidate.unchangedObjective = objectiveOutside(
          face, seed.patch.elements);
        if(!candidateQuadranglesAreNonConcave(
             candidate.quadrangles, candidate.uv, candidate.xyz))
          return false;
        if(candidate.objective.absoluteBadElementCount == 0 &&
           candidate.objective.absoluteBadElementCount ==
             candidate.smoothedReferenceObjective.absoluteBadElementCount) {
          candidate.smoothedReferenceGeometry = existingGeometryDeviation(
            face, seed.patch.elements);
          candidate.geometry = candidateGeometryDeviation(
            face, candidate.uv, candidate.xyz, candidate.quadrangles);
        }
        return true;
      }

      std::vector<std::unique_ptr<MQuadrangle> > ownedReplacement;
      std::vector<MElement *> replacement;
      ownedReplacement.reserve(candidate.quadrangles.size());
      replacement.reserve(candidate.quadrangles.size());
      const std::vector<MVertex *> &coreBoundary =
        seed.patch.bdrVertices.front();
      for(const auto &quad : candidate.quadrangles) {
        if(std::any_of(quad.begin(), quad.end(),
                       [&](std::size_t local) {
                         return local >= coreBoundary.size();
                       }))
          return false;
        ownedReplacement.emplace_back(new MQuadrangle(
          coreBoundary[quad[0]], coreBoundary[quad[1]],
          coreBoundary[quad[2]], coreBoundary[quad[3]]));
        replacement.push_back(ownedReplacement.back().get());
      }
      if(replacement.empty() ||
         !orientElementsAccordingToBoundarySegment(
           coreBoundary[0], coreBoundary[1], replacement))
        return false;

      std::vector<MElement *> beforeElements(outsideSet.begin(),
                                             outsideSet.end());
      beforeElements.insert(beforeElements.end(), seed.patch.elements.begin(),
                            seed.patch.elements.end());
      std::vector<MElement *> afterElements(outsideSet.begin(),
                                            outsideSet.end());
      afterElements.insert(afterElements.end(), replacement.begin(),
                           replacement.end());

      GFaceMeshPatch afterPatch;
      if(!canonicalPatchFromElements(face, afterElements, afterPatch) ||
         afterPatch.bdrVertices.size() != 1 ||
         afterPatch.bdrVertices.front().size() < 4 ||
         !afterPatch.embVertices.empty())
        return false;
      for(MVertex *vertex : afterPatch.intVertices)
        if(!vertex || vertex->onWhat() != face ||
           protectedVertices.find(vertex) != protectedVertices.end())
          return false;

      CavitySeed afterSeed;
      afterSeed.patch = afterPatch;
      std::vector<UV> points;
      Pattern quadrangles;
      if(!existingPatternAndParametrization(afterSeed, points, quadrangles))
        return false;
      const std::size_t boundaryCount =
        afterPatch.bdrVertices.front().size();
      if(points.size() > boundaryCount) {
        SmallCavityWinslowOptions winslowOptions = options.winslow;
        winslowOptions.harmonicInitialization = true;
        const SmallCavityWinslowResult winslow =
          optimizeSmallQuadCavityWinslow(points, boundaryCount, quadrangles,
                                         winslowOptions);
        if(!winslow.success || !winslow.untangled) {
          ++result.rejectedByWinslow;
          return false;
        }
      }

      std::vector<Point> xyz;
      if(!mapCandidate(face, boundaryCount,
                       afterPatch.bdrVertices.front(), points, xyz)) {
        ++result.rejectedByWinslow;
        return false;
      }

      GFaceMeshPatch beforePatch;
      beforePatch.gf = face;
      beforePatch.elements = beforeElements;
      const SizeScore beforeSize = existingSizeScore(
        beforePatch, options, false);
      const SizeScore afterSize = candidateSizeScore(
        face, points, xyz, quadrangles, options, boundaryCount);
      const bool checkSize = options.quadCleanUp ||
                             options.enforceSizeMap ||
                             seed.kind == CavityKind::CleanUpSize;
      const bool preservesTarget = !options.enforceSizeMap ||
        admissibleSizeChange(beforeSize, afterSize, options);
      if(checkSize && (!afterSize.admissible || !preservesTarget)) {
        ++result.rejectedBySize;
        return false;
      }

      candidate.smoothedReferenceObjective =
        specificationObjective(beforeElements);
      candidate.objective = candidateObjective(quadrangles, xyz);
      if(!candidateQuadranglesAreNonConcave(quadrangles, points, xyz))
        return false;
      if(candidate.objective.absoluteBadElementCount == 0 &&
         candidate.objective.absoluteBadElementCount ==
           candidate.smoothedReferenceObjective.absoluteBadElementCount) {
        candidate.smoothedReferenceGeometry = existingGeometryDeviation(
          face, beforeElements);
        candidate.geometry = candidateGeometryDeviation(
          face, points, xyz, quadrangles);
      }
      candidate.smoothedReferenceSizeError = beforeSize.meanSquaredLogRatio;
      candidate.smoothedReferenceSizeViolationCount =
        beforeSize.belowMinimum + beforeSize.aboveMaximum +
        beforeSize.invalid;
      candidate.sizeError = afterSize.meanSquaredLogRatio;
      candidate.sizeViolationCount =
        afterSize.belowMinimum + afterSize.aboveMaximum + afterSize.invalid;
      candidate.unchangedObjective = objectiveOutside(face, beforeElements);
      candidate.smoothedExistingVertices.clear();
      candidate.smoothedExistingVertices.reserve(
        afterPatch.intVertices.size());
      for(std::size_t i = 0; i < afterPatch.intVertices.size(); ++i) {
        const std::size_t local = boundaryCount + i;
        candidate.smoothedExistingVertices.push_back(
          {afterPatch.intVertices[i], points[local], xyz[local]});
      }

      // Store the final, post-smoothing geometry of the core boundary as
      // well. Zero-interior operations use these coordinates for the final
      // switch-diagonal intersection and convexity gates.
      std::unordered_map<MVertex *, std::size_t> localIndex;
      for(std::size_t i = 0; i < afterPatch.bdrVertices.front().size(); ++i)
        localIndex[afterPatch.bdrVertices.front()[i]] = i;
      for(std::size_t i = 0; i < afterPatch.intVertices.size(); ++i)
        localIndex[afterPatch.intVertices[i]] = boundaryCount + i;
      for(std::size_t i = 0; i < coreBoundary.size(); ++i) {
        const auto found = localIndex.find(coreBoundary[i]);
        if(found == localIndex.end() || found->second >= points.size() ||
           found->second >= xyz.size())
          return false;
        candidate.uv[i] = points[found->second];
        candidate.xyz[i] = xyz[found->second];
      }
      if(!candidateQuadranglesAreNonConcave(
           candidate.quadrangles, candidate.uv, candidate.xyz))
        return false;
      return true;
    }

    // Validate a boundary T-Q[-Q...]-T replacement after smoothing the
    // complete movable one-ring, including its newly created face vertex. The
    // transaction is entirely in memory: existing vertices are updated only
    // after the topology commit succeeds.
    bool smoothNewInteriorCandidate(
      GFace *face, const CavitySeed &seed, Candidate &candidate,
      const SmallCavityOptimizerOptions &options,
      SmallCavityOptimizerResult &result, CleanUpDecisionPhase phase)
    {
      if(!face || seed.patch.bdrVertices.size() != 1 ||
         !seed.patch.intVertices.empty() ||
         !candidate.interiorAssignment.empty())
        return false;
      const std::vector<MVertex *> &coreBoundary =
        seed.patch.bdrVertices.front();
      const std::size_t coreBoundaryCount = coreBoundary.size();
      const std::size_t center = coreBoundaryCount;
      if(coreBoundaryCount < 6 || coreBoundaryCount % 2 ||
         candidate.uv.size() != coreBoundaryCount + 1 ||
         candidate.xyz.size() != coreBoundaryCount + 1 ||
         candidate.quadrangles.empty())
        return false;

      const std::vector<MElement *> faceElements = surfaceElements(face);
      const Adjacency adjacency = buildAdjacency(faceElements);
      const std::set<MElement *> coreElements(seed.patch.elements.begin(),
                                              seed.patch.elements.end());
      const std::set<MVertex *> protectedVertices =
        protectedFaceVertices(face);
      std::set<MElement *> outsideSet;
      for(MVertex *vertex : coreBoundary) {
        if(!vertex || vertex->onWhat() != face ||
           protectedVertices.find(vertex) != protectedVertices.end())
          continue;
        const auto found = adjacency.find(vertex);
        if(found == adjacency.end()) continue;
        const bool completeAllQuadStar = std::all_of(
          found->second.begin(), found->second.end(),
          [&](MElement *element) {
            return coreElements.find(element) != coreElements.end() ||
              (element && element->getNumPrimaryVertices() == 4);
          });
        if(!completeAllQuadStar) continue;
        for(MElement *element : found->second)
          if(coreElements.find(element) == coreElements.end())
            outsideSet.insert(element);
      }

      // Declare the temporary center before the quadrangles: reverse
      // destruction order then guarantees that no temporary element outlives
      // the vertex it references.
      std::unique_ptr<MFaceVertex> temporaryCenter(new MFaceVertex(
        candidate.xyz[center][0], candidate.xyz[center][1],
        candidate.xyz[center][2], face, candidate.uv[center][0],
        candidate.uv[center][1]));
      std::vector<MVertex *> localVertices = coreBoundary;
      localVertices.push_back(temporaryCenter.get());
      std::vector<std::unique_ptr<MQuadrangle> > ownedReplacement;
      std::vector<MElement *> replacement;
      ownedReplacement.reserve(candidate.quadrangles.size());
      replacement.reserve(candidate.quadrangles.size());
      bool usesCenter = false;
      for(const auto &quad : candidate.quadrangles) {
        std::set<std::size_t> unique(quad.begin(), quad.end());
        if(unique.size() != 4 ||
           std::any_of(quad.begin(), quad.end(), [&](std::size_t local) {
             return local >= localVertices.size();
           }))
          return false;
        usesCenter = usesCenter ||
          std::find(quad.begin(), quad.end(), center) != quad.end();
        ownedReplacement.emplace_back(new MQuadrangle(
          localVertices[quad[0]], localVertices[quad[1]],
          localVertices[quad[2]], localVertices[quad[3]]));
        replacement.push_back(ownedReplacement.back().get());
      }
      if(!usesCenter || replacement.empty() ||
         !orientElementsAccordingToBoundarySegment(
           coreBoundary[0], coreBoundary[1], replacement))
        return false;

      std::vector<MElement *> beforeElements(outsideSet.begin(),
                                             outsideSet.end());
      beforeElements.insert(beforeElements.end(), seed.patch.elements.begin(),
                            seed.patch.elements.end());
      std::vector<MElement *> afterElements(outsideSet.begin(),
                                            outsideSet.end());
      afterElements.insert(afterElements.end(), replacement.begin(),
                           replacement.end());
      if(std::any_of(afterElements.begin(), afterElements.end(),
                     [](MElement *element) {
                       return !element ||
                         element->getNumPrimaryVertices() != 4;
                     }))
        return false;

      GFaceMeshPatch afterPatch;
      if(!canonicalPatchFromElements(face, afterElements, afterPatch) ||
         afterPatch.bdrVertices.size() != 1 ||
         afterPatch.bdrVertices.front().size() < 4 ||
         !afterPatch.embVertices.empty() ||
         std::find(afterPatch.intVertices.begin(),
                   afterPatch.intVertices.end(), temporaryCenter.get()) ==
           afterPatch.intVertices.end())
        return false;
      for(MVertex *vertex : afterPatch.intVertices) {
        if(vertex == temporaryCenter.get()) continue;
        if(!vertex || vertex->onWhat() != face ||
           protectedVertices.find(vertex) != protectedVertices.end())
          return false;
        const auto found = adjacency.find(vertex);
        if(found == adjacency.end()) return false;
        for(MElement *element : found->second)
          if(coreElements.find(element) == coreElements.end() &&
             outsideSet.find(element) == outsideSet.end())
            return false;
      }

      CavitySeed afterSeed;
      afterSeed.patch = afterPatch;
      std::vector<UV> points;
      Pattern fullQuadrangles;
      if(!existingPatternAndParametrization(
           afterSeed, points, fullQuadrangles))
        return false;
      const std::size_t boundaryCount =
        afterPatch.bdrVertices.front().size();
      const std::vector<UV> unsmoothedPoints = points;
      SmallCavityWinslowOptions winslowOptions = options.winslow;
      winslowOptions.harmonicInitialization = true;
      const SmallCavityWinslowResult winslow =
        optimizeSmallQuadCavityWinslow(
          points, boundaryCount, fullQuadrangles, winslowOptions);
      if(!winslow.success || !winslow.untangled) {
        ++result.rejectedByWinslow;
        return false;
      }
      const std::vector<UV> fullySmoothedPoints = points;

      GFaceMeshPatch beforePatch;
      beforePatch.gf = face;
      beforePatch.elements = beforeElements;
      const SizeScore beforeSize = existingSizeScore(
        beforePatch, options, false);
      const SpecificationObjective smoothedReferenceObjective =
        specificationObjective(beforeElements);
      const SpecificationObjective unchangedObjective =
        objectiveOutside(face, beforeElements);
      const std::size_t beforeSizeViolations = beforeSize.belowMinimum +
        beforeSize.aboveMaximum + beforeSize.invalid;
      GeometryDeviation smoothedReferenceGeometry;
      bool referenceGeometryEvaluated = false;
      SizeScore afterSize;
      std::vector<Point> xyz;
      bool acceptedSmoothedStep = false;
      bool mappedTrial = false;
      bool sizeAdmissibleTrial = false;
      Candidate bestTrial;
      std::vector<UV> bestPoints;
      std::vector<Point> bestXyz;
      SizeScore bestSize;
      // A fully converged unconstrained Winslow step can overshoot a hard
      // edge-length bound even though the same descent direction contains an
      // admissible post-smoothed state.  Backtrack the complete one-ring
      // transaction (including the new center) and validate every trial.
      // This is a line search on the smoothing displacement, not an
      // unsmoothed fallback.
      constexpr std::size_t smoothingLineSearchSteps = 32;
      for(std::size_t step = 0; step < smoothingLineSearchSteps; ++step) {
        const double scale = 1. - static_cast<double>(step) /
          static_cast<double>(smoothingLineSearchSteps);
        std::vector<UV> trial = unsmoothedPoints;
        for(std::size_t i = boundaryCount; i < trial.size(); ++i) {
          trial[i][0] += scale *
            (fullySmoothedPoints[i][0] - unsmoothedPoints[i][0]);
          trial[i][1] += scale *
            (fullySmoothedPoints[i][1] - unsmoothedPoints[i][1]);
        }
        std::vector<Point> trialXyz;
        if(!mapCandidate(face, boundaryCount,
                         afterPatch.bdrVertices.front(), trial, trialXyz))
          continue;
        mappedTrial = true;
        const SizeScore trialSize = candidateSizeScore(
          face, trial, trialXyz, fullQuadrangles, options, boundaryCount);
        if((options.quadCleanUp && !trialSize.admissible) ||
           (options.enforceSizeMap &&
            !admissibleSizeChange(beforeSize, trialSize, options)))
          continue;
        sizeAdmissibleTrial = true;
        if(!candidateQuadranglesAreNonConcave(
             fullQuadrangles, trial, trialXyz))
          continue;
        Candidate scored;
        scored.valid = true;
        scored.hasSmoothedReference = true;
        scored.smoothedReferenceObjective = smoothedReferenceObjective;
        scored.objective = candidateObjective(fullQuadrangles, trialXyz);
        scored.valence = candidate.valence;
        scored.sizeError = trialSize.meanSquaredLogRatio;
        scored.sizeViolationCount = trialSize.belowMinimum +
          trialSize.aboveMaximum + trialSize.invalid;
        scored.smoothedReferenceSizeError = beforeSize.meanSquaredLogRatio;
        scored.smoothedReferenceSizeViolationCount = beforeSizeViolations;
        scored.unchangedObjective = unchangedObjective;
        const SpecificationObjective candidateComparison =
          comparisonObjective(scored);
        const SpecificationObjective referenceComparison =
          comparisonReferenceObjective(seed, scored);
        if(scored.objective.absoluteBadElementCount == 0 &&
           candidateComparison.absoluteBadElementCount ==
             referenceComparison.absoluteBadElementCount) {
          if(!referenceGeometryEvaluated) {
            smoothedReferenceGeometry = existingGeometryDeviation(
              face, beforeElements);
            referenceGeometryEvaluated = true;
          }
          scored.smoothedReferenceGeometry = smoothedReferenceGeometry;
          scored.referenceGeometry = smoothedReferenceGeometry;
          scored.geometry = candidateGeometryDeviation(
            face, trial, trialXyz, fullQuadrangles);
        }
        scored.decisionReason = cleanUpDecision(
          candidateComparison, referenceComparison, scored.geometry,
          scored.smoothedReferenceGeometry,
          scored.objective.absoluteBadElementCount == 0,
          scored.valence, seed.valence, scored.sizeViolationCount,
          beforeSizeViolations, scored.sizeError,
          beforeSize.meanSquaredLogRatio,
          options.objectiveRelativeTolerance);
        if(!decisionAllowed(scored.decisionReason, phase)) continue;
        if(bestTrial.valid &&
           !betterCleanUpCandidate(scored, bestTrial, options))
          continue;
        bestTrial = std::move(scored);
        bestPoints = std::move(trial);
        bestXyz = std::move(trialXyz);
        bestSize = trialSize;
      }
      if(bestTrial.valid) {
        points = std::move(bestPoints);
        xyz = std::move(bestXyz);
        afterSize = bestSize;
        acceptedSmoothedStep = true;
      }
      if(!acceptedSmoothedStep) {
        if(!mappedTrial)
          ++result.rejectedByWinslow;
        else if(!sizeAdmissibleTrial)
          ++result.rejectedBySize;
        else
          ++result.rejectedByQuality;
        return false;
      }

      candidate.hasSmoothedReference = true;
      candidate.smoothedReferenceObjective = smoothedReferenceObjective;
      candidate.objective = bestTrial.objective;
      candidate.smoothedReferenceGeometry =
        bestTrial.smoothedReferenceGeometry;
      candidate.geometry = bestTrial.geometry;
      candidate.referenceGeometry = bestTrial.referenceGeometry;
      candidate.smoothedReferenceSizeError = beforeSize.meanSquaredLogRatio;
      candidate.smoothedReferenceSizeViolationCount =
        beforeSize.belowMinimum + beforeSize.aboveMaximum + beforeSize.invalid;
      candidate.sizeError = afterSize.meanSquaredLogRatio;
      candidate.sizeViolationCount =
        afterSize.belowMinimum + afterSize.aboveMaximum + afterSize.invalid;
      candidate.unchangedObjective = unchangedObjective;

      std::unordered_map<MVertex *, std::size_t> localIndex;
      for(std::size_t i = 0;
          i < afterPatch.bdrVertices.front().size(); ++i)
        localIndex[afterPatch.bdrVertices.front()[i]] = i;
      for(std::size_t i = 0; i < afterPatch.intVertices.size(); ++i)
        localIndex[afterPatch.intVertices[i]] = boundaryCount + i;
      const auto centerPosition = localIndex.find(temporaryCenter.get());
      if(centerPosition == localIndex.end() ||
         centerPosition->second >= points.size() ||
         centerPosition->second >= xyz.size())
        return false;
      candidate.uv[center] = points[centerPosition->second];
      candidate.xyz[center] = xyz[centerPosition->second];
      for(std::size_t i = 0; i < coreBoundaryCount; ++i) {
        const auto found = localIndex.find(coreBoundary[i]);
        if(found == localIndex.end() || found->second >= points.size() ||
           found->second >= xyz.size())
          return false;
        candidate.uv[i] = points[found->second];
        candidate.xyz[i] = xyz[found->second];
      }

      candidate.smoothedExistingVertices.clear();
      candidate.smoothedExistingVertices.reserve(
        afterPatch.intVertices.size() - 1);
      for(std::size_t i = 0; i < afterPatch.intVertices.size(); ++i) {
        MVertex *vertex = afterPatch.intVertices[i];
        if(vertex == temporaryCenter.get()) continue;
        const std::size_t local = boundaryCount + i;
        candidate.smoothedExistingVertices.push_back(
          {vertex, points[local], xyz[local]});
      }
      return candidateQuadranglesAreNonConcave(
        candidate.quadrangles, candidate.uv, candidate.xyz);
    }

    void applyCandidateSmoothing(const Candidate &candidate)
    {
      for(const Candidate::VertexGeometry &geometry :
          candidate.smoothedExistingVertices) {
        if(!geometry.vertex) continue;
        geometry.vertex->setXYZ(geometry.xyz[0], geometry.xyz[1],
                                geometry.xyz[2]);
        geometry.vertex->setParameter(0, geometry.uv[0]);
        geometry.vertex->setParameter(1, geometry.uv[1]);
      }
    }

    void applySmoothedGeometry(const CavitySeed &seed,
                               const std::vector<UV> &uv,
                               const std::vector<Point> &xyz)
    {
      const std::size_t boundaryCount =
        seed.patch.bdrVertices.front().size();
      for(std::size_t i = 0; i < seed.patch.intVertices.size(); ++i) {
        MVertex *vertex = seed.patch.intVertices[i];
        const std::size_t local = boundaryCount + i;
        vertex->setXYZ(xyz[local][0], xyz[local][1], xyz[local][2]);
        vertex->setParameter(0, uv[local][0]);
        vertex->setParameter(1, uv[local][1]);
      }
    }

    enum class ExistingSmoothingStatus {
      Invalid,
      SkippedSpecificationCompliant,
      RejectedWinslow,
      RejectedSize,
      RejectedQuality,
      Accepted
    };

    ExistingSmoothingStatus smoothMixedVertexSize(
      GFace *face, MVertex *vertex, const Adjacency &adjacency,
      const SmallCavityOptimizerOptions &options)
    {
      if(!face || !vertex || vertex->onWhat() != face ||
         !options.quadCleanUp || !options.enforceSizeMap)
        return ExistingSmoothingStatus::Invalid;
      const auto foundStar = adjacency.find(vertex);
      if(foundStar == adjacency.end() || foundStar->second.empty())
        return ExistingSmoothingStatus::Invalid;
      bool hasTriangle = false;
      for(MElement *element : foundStar->second) {
        if(!element || (element->getNumPrimaryVertices() != 3 &&
                        element->getNumPrimaryVertices() != 4))
          return ExistingSmoothingStatus::Invalid;
        hasTriangle = hasTriangle || element->getNumPrimaryVertices() == 3;
      }
      if(!hasTriangle) return ExistingSmoothingStatus::Invalid;

      std::vector<MVertex *> vertices = {vertex};
      std::unordered_map<MVertex *, std::size_t> index;
      index[vertex] = 0;
      for(MElement *element : foundStar->second)
        for(std::size_t i = 0; i < element->getNumPrimaryVertices(); ++i) {
          MVertex *candidate = element->getVertex(static_cast<int>(i));
          if(!candidate || index.find(candidate) != index.end()) continue;
          index[candidate] = vertices.size();
          vertices.push_back(candidate);
        }

      SPoint2 centerParameter;
      if(!persistentFaceParameter(face, vertex, centerParameter))
        return ExistingSmoothingStatus::Invalid;
      std::vector<UV> uv(vertices.size());
      std::vector<Point> xyz(vertices.size());
      uv[0] = {centerParameter.x(), centerParameter.y()};
      for(std::size_t i = 0; i < vertices.size(); ++i) {
        if(i) {
          SPoint2 parameter;
          if(!reparamMeshVertexOnFaceWithRef(
               face, vertices[i], centerParameter, parameter))
            return ExistingSmoothingStatus::Invalid;
          uv[i] = {parameter.x(), parameter.y()};
        }
        xyz[i] = {vertices[i]->x(), vertices[i]->y(), vertices[i]->z()};
      }

      std::vector<std::array<std::size_t, 3> > triangles;
      Pattern quadrangles;
      for(MElement *element : foundStar->second) {
        if(element->getNumPrimaryVertices() == 3) {
          std::array<std::size_t, 3> triangle;
          for(std::size_t i = 0; i < 3; ++i)
            triangle[i] = index[element->getVertex(static_cast<int>(i))];
          triangles.push_back(triangle);
        }
        else {
          std::array<std::size_t, 4> quadrangle;
          for(std::size_t i = 0; i < 4; ++i)
            quadrangle[i] = index[element->getVertex(static_cast<int>(i))];
          quadrangles.push_back(quadrangle);
        }
      }
      std::vector<bool> fixed(vertices.size(), true);
      fixed[0] = false;
      GFaceMeshPatch patch;
      patch.gf = face;
      patch.elements = foundStar->second;
      const SizeScore beforeSize = existingSizeScore(patch, options, false);
      const std::size_t beforeSizeViolations =
        beforeSize.belowMinimum + beforeSize.aboveMaximum +
        beforeSize.invalid;
      if(beforeSizeViolations == 0)
        return ExistingSmoothingStatus::Invalid;

      const SpecificationObjective referenceObjective =
        specificationObjective(foundStar->second);
      const SpecificationObjective unchangedObjective =
        objectiveOutside(face, foundStar->second);
      const GeometryDeviation referenceGeometry =
        existingGeometryDeviation(face, foundStar->second);
      auto mixedObjective = [&](const std::vector<Point> &points) {
        SpecificationObjective objective;
        for(const auto &triangle : triangles) {
          std::vector<Point> element(3);
          for(std::size_t i = 0; i < 3; ++i)
            element[i] = points[triangle[i]];
          objective += specificationObjective(evaluateElementQuality(
            SurfaceElementKind::Triangle, element));
        }
        for(const auto &quadrangle : quadrangles) {
          std::vector<Point> element(4);
          for(std::size_t i = 0; i < 4; ++i)
            element[i] = points[quadrangle[i]];
          objective += specificationObjective(evaluateElementQuality(
            SurfaceElementKind::Quadrangle, element));
        }
        return objective;
      };

      bool rejectedBySize = false;
      auto acceptProjected = [&](const Point &displacement, double scale) {
        const SPoint3 target(
          xyz[0][0] + scale * displacement[0],
          xyz[0][1] + scale * displacement[1],
          xyz[0][2] + scale * displacement[2]);
        const double initialGuess[2] = {uv[0][0], uv[0][1]};
        const GPoint projected = face->closestPoint(target, initialGuess);
        if(!projected.succeeded() || !std::isfinite(projected.x()) ||
           !std::isfinite(projected.y()) ||
           !std::isfinite(projected.z()) ||
           !std::isfinite(projected.u()) ||
           !std::isfinite(projected.v()))
          return false;
        std::vector<UV> trialUv = uv;
        std::vector<Point> trialXyz = xyz;
        trialUv[0] = {projected.u(), projected.v()};
        trialXyz[0] = {projected.x(), projected.y(), projected.z()};
        const SizeScore afterSize = surfacePatchSizeScore(
          face, trialUv, trialXyz, triangles, quadrangles, fixed, options);
        if(!admissibleSizeChange(beforeSize, afterSize, options)) {
          rejectedBySize = true;
          return false;
        }
        const SpecificationObjective candidateObjective =
          mixedObjective(trialXyz);
        if(!candidateQuadranglesAreNonConcave(
             quadrangles, trialUv, trialXyz))
          return false;
        SpecificationObjective comparison = candidateObjective;
        comparison += unchangedObjective;
        SpecificationObjective reference = referenceObjective;
        reference += unchangedObjective;
        const std::size_t afterSizeViolations =
          afterSize.belowMinimum + afterSize.aboveMaximum +
          afterSize.invalid;
        const GeometryDeviation candidateGeometry =
          candidateMixedGeometryDeviation(
            face, trialUv, trialXyz, triangles, quadrangles);
        if(cleanUpSmoothingDecision(
             comparison, reference, candidateGeometry, referenceGeometry,
             candidateObjective.absoluteBadElementCount == 0,
             afterSizeViolations, beforeSizeViolations,
             afterSize.meanSquaredLogRatio, beforeSize.meanSquaredLogRatio,
             options.objectiveRelativeTolerance) ==
           CleanUpDecisionReason::Rejected)
          return false;
        vertex->setXYZ(projected.x(), projected.y(), projected.z());
        vertex->setParameter(0, projected.u());
        vertex->setParameter(1, projected.v());
        return true;
      };

      std::set<std::size_t> neighbors;
      auto collectNeighbors = [&](const auto &elements) {
        for(const auto &element : elements)
          for(std::size_t i = 0; i < element.size(); ++i)
            if(element[i] == 0) {
              neighbors.insert(element[(i + element.size() - 1) %
                                       element.size()]);
              neighbors.insert(element[(i + 1) % element.size()]);
            }
      };
      collectNeighbors(triangles);
      collectNeighbors(quadrangles);
      Point spring = {0., 0., 0.};
      std::vector<Point> boundCorrections;
      bool hasIncidentSizeViolation = false;
      for(const std::size_t neighbor : neighbors) {
        const double length = distance(xyz[0], xyz[neighbor]);
        if(!(length > 0.) || !std::isfinite(length)) continue;
        const UV midpointUv = {
          .5 * (uv[0][0] + uv[neighbor][0]),
          .5 * (uv[0][1] + uv[neighbor][1])};
        const Point midpointXyz = {
          .5 * (xyz[0][0] + xyz[neighbor][0]),
          .5 * (xyz[0][1] + xyz[neighbor][1]),
          .5 * (xyz[0][2] + xyz[neighbor][2])};
        const EdgeLengthCriteria criteria = edgeLengthCriteria(
          face, midpointUv, midpointXyz, options);
        if(!validEdgeLengthCriteria(criteria)) continue;
        double requiredLength = length;
        if(length < criteria.minimum) {
          requiredLength = criteria.minimum * (1. + 1.e-8);
          hasIncidentSizeViolation = true;
        }
        else if(length > criteria.maximum) {
          requiredLength = criteria.maximum * (1. - 1.e-8);
          hasIncidentSizeViolation = true;
        }
        if(requiredLength != length) {
          Point correction = {0., 0., 0.};
          const double factor = requiredLength / length - 1.;
          for(std::size_t coordinate = 0; coordinate < 3; ++coordinate)
            correction[coordinate] = factor *
              (xyz[0][coordinate] - xyz[neighbor][coordinate]);
          boundCorrections.push_back(correction);
        }
        const double correction = (criteria.target - length) / length;
        for(std::size_t coordinate = 0; coordinate < 3; ++coordinate)
          spring[coordinate] += correction *
            (xyz[0][coordinate] - xyz[neighbor][coordinate]);
      }
      if(!hasIncidentSizeViolation)
        return ExistingSmoothingStatus::Invalid;
      for(const Point &correction : boundCorrections)
        for(const double scale : {1., 1.05, 1.1, 1.25, 1.5, 2.})
          if(acceptProjected(correction, scale))
            return ExistingSmoothingStatus::Accepted;
      for(const double scale : {1., .75, .5, .25, 1.25, 1.5, 2.})
        if(acceptProjected(spring, scale))
          return ExistingSmoothingStatus::Accepted;
      return rejectedBySize ? ExistingSmoothingStatus::RejectedSize :
                              ExistingSmoothingStatus::RejectedQuality;
    }

    ExistingSmoothingStatus smoothExistingCavity(
      GFace *face, CavitySeed &seed,
      const SmallCavityOptimizerOptions &options)
    {
      const bool fastInteractive = useFastInteractiveCleanUp(options);
      seed.objective = specificationObjective(seed.patch.elements);
      if(options.topologyOnlyIfCavityHasSpecificationFailure &&
         !hasQualitySpecificationFailure(seed.objective))
        return ExistingSmoothingStatus::SkippedSpecificationCompliant;
      std::vector<UV> uv;
      Pattern pattern;
      if(!existingPatternAndParametrization(seed, uv, pattern))
        return ExistingSmoothingStatus::Invalid;

      const std::vector<MVertex *> &boundary =
        seed.patch.bdrVertices.front();
      const std::size_t boundaryCount = boundary.size();
      std::vector<Point> initialXyz;
      initialXyz.reserve(boundaryCount + seed.patch.intVertices.size());
      for(MVertex *vertex : boundary)
        initialXyz.push_back({vertex->x(), vertex->y(), vertex->z()});
      for(MVertex *vertex : seed.patch.intVertices)
        initialXyz.push_back({vertex->x(), vertex->y(), vertex->z()});

      const SpecificationObjective unchangedObjective =
        options.quadCleanUp ? objectiveOutside(face, seed.patch.elements) :
                              SpecificationObjective();
      GeometryDeviation referenceGeometry;
      bool referenceGeometryEvaluated = false;
      const SizeScore beforeSize = existingSizeScore(
        seed.patch, options, false);
      const std::size_t beforeSizeViolations =
        beforeSize.belowMinimum + beforeSize.aboveMaximum +
        beforeSize.invalid;
      const std::size_t beforeInvalidElementCount =
        topologicallyInvalidElementCount(seed.patch.elements);
      bool rejectedBySize = false;
      auto acceptTrial = [&](const std::vector<UV> &trialUv,
                             const std::vector<Point> &trialXyz) {
        SizeScore afterSize;
        if(options.enforceSizeMap || options.quadCleanUp || fastInteractive)
          afterSize = candidateSizeScore(
            face, trialUv, trialXyz, pattern, options, boundaryCount);
        if((options.quadCleanUp && !afterSize.admissible) ||
           (options.enforceSizeMap &&
            !admissibleSizeChange(beforeSize, afterSize, options))) {
          rejectedBySize = true;
          return false;
        }
        if((options.quadCleanUp || fastInteractive) &&
           !candidateQuadranglesAreNonConcave(
             pattern, trialUv, trialXyz))
          return false;
        std::size_t candidateInvalidElementCount = 0;
        const SpecificationObjective objective = candidateObjective(
          pattern, trialXyz, &candidateInvalidElementCount);
        SpecificationObjective comparison = objective;
        comparison += unchangedObjective;
        SpecificationObjective reference = seed.objective;
        reference += unchangedObjective;
        GeometryDeviation geometry;
        if(options.quadCleanUp &&
           comparison.absoluteBadElementCount ==
             reference.absoluteBadElementCount &&
           objective.absoluteBadElementCount == 0) {
          if(!referenceGeometryEvaluated) {
            referenceGeometry = existingGeometryDeviation(
              face, seed.patch.elements);
            referenceGeometryEvaluated = true;
          }
          geometry = candidateGeometryDeviation(
            face, trialUv, trialXyz, pattern);
        }
        const std::size_t afterSizeViolations =
          afterSize.belowMinimum + afterSize.aboveMaximum +
          afterSize.invalid;
        bool improves = false;
        if(fastInteractive) {
          const bool historicalImprovement = improvesSpecificationObjective(
            objective, seed.objective,
            options.objectiveRelativeTolerance);
          const ValenceObjective unchangedValence;
          const FastGlobalQuality candidateQuality = fastGlobalQuality(
            objective, unchangedValence, candidateInvalidElementCount,
            afterSizeViolations, afterSize.meanSquaredLogRatio,
            afterSize.edgeCount, 0.);
          const FastGlobalQuality referenceQuality = fastGlobalQuality(
            seed.objective, unchangedValence, beforeInvalidElementCount,
            beforeSizeViolations, beforeSize.meanSquaredLogRatio,
            beforeSize.edgeCount, 0.);
          const bool globalImprovement = improvesFastGlobalQuality(
            candidateQuality, referenceQuality);
          improves = historicalImprovement && globalImprovement;
        }
        else if(options.quadCleanUp) {
          improves = cleanUpSmoothingDecision(
            comparison, reference, geometry, referenceGeometry,
            objective.absoluteBadElementCount == 0,
            afterSizeViolations, beforeSizeViolations,
            afterSize.meanSquaredLogRatio,
            beforeSize.meanSquaredLogRatio,
            options.objectiveRelativeTolerance) !=
            CleanUpDecisionReason::Rejected;
        }
        else {
          improves = improvesSpecificationObjective(
            objective, seed.objective,
            options.objectiveRelativeTolerance);
        }
        if(!improves) return false;
        applySmoothedGeometry(seed, trialUv, trialXyz);
        return true;
      };

      // A Winslow equilibrium is shape-driven and can leave a short edge
      // untouched. When sizes are hard requirements, first try a projected
      // spring step for a single movable vertex. Every trial is still gated
      // by the complete incident patch quality and edge-size transaction.
      if(options.quadCleanUp && options.enforceSizeMap &&
         beforeSizeViolations && seed.patch.intVertices.size() == 1) {
        const std::size_t center = boundaryCount;
        std::set<std::size_t> neighbors;
        for(const auto &quad : pattern)
          for(std::size_t i = 0; i < 4; ++i)
            if(quad[i] == center) {
              neighbors.insert(quad[(i + 3) % 4]);
              neighbors.insert(quad[(i + 1) % 4]);
        }
        Point displacement = {0., 0., 0.};
        std::vector<Point> boundCorrections;
        bool hasSizeForce = false;
        for(const std::size_t neighbor : neighbors) {
          if(neighbor >= uv.size() || neighbor >= initialXyz.size()) continue;
          const double length = distance(initialXyz[center],
                                         initialXyz[neighbor]);
          if(!(length > 0.) || !std::isfinite(length)) continue;
          const UV midpointUv = {
            .5 * (uv[center][0] + uv[neighbor][0]),
            .5 * (uv[center][1] + uv[neighbor][1])};
          const Point midpointXyz = {
            .5 * (initialXyz[center][0] + initialXyz[neighbor][0]),
            .5 * (initialXyz[center][1] + initialXyz[neighbor][1]),
            .5 * (initialXyz[center][2] + initialXyz[neighbor][2])};
          const EdgeLengthCriteria criteria = edgeLengthCriteria(
            face, midpointUv, midpointXyz, options);
          if(!validEdgeLengthCriteria(criteria)) continue;
          double requiredLength = length;
          if(length < criteria.minimum)
            requiredLength = criteria.minimum * (1. + 1.e-8);
          else if(length > criteria.maximum)
            requiredLength = criteria.maximum * (1. - 1.e-8);
          if(requiredLength != length) {
            Point correction = {0., 0., 0.};
            const double factor = requiredLength / length - 1.;
            for(std::size_t coordinate = 0; coordinate < 3; ++coordinate)
              correction[coordinate] = factor *
                (initialXyz[center][coordinate] -
                 initialXyz[neighbor][coordinate]);
            boundCorrections.push_back(correction);
          }
          const double correction = (criteria.target - length) / length;
          for(std::size_t coordinate = 0; coordinate < 3; ++coordinate)
            displacement[coordinate] += correction *
              (initialXyz[center][coordinate] -
               initialXyz[neighbor][coordinate]);
          hasSizeForce = hasSizeForce || std::abs(correction) > 1.e-12;
        }
        for(const Point &correction : boundCorrections)
          for(const double scale : {1., 1.05, 1.1, 1.25, 1.5, 2.}) {
            const SPoint3 target(
              initialXyz[center][0] + scale * correction[0],
              initialXyz[center][1] + scale * correction[1],
              initialXyz[center][2] + scale * correction[2]);
            const double initialGuess[2] = {uv[center][0], uv[center][1]};
            const GPoint projected = face->closestPoint(target, initialGuess);
            if(!projected.succeeded() || !std::isfinite(projected.x()) ||
               !std::isfinite(projected.y()) ||
               !std::isfinite(projected.z()) ||
               !std::isfinite(projected.u()) ||
               !std::isfinite(projected.v()))
              continue;
            std::vector<UV> trialUv = uv;
            std::vector<Point> trialXyz = initialXyz;
            trialUv[center] = {projected.u(), projected.v()};
            trialXyz[center] = {
              projected.x(), projected.y(), projected.z()};
            if(acceptTrial(trialUv, trialXyz))
              return ExistingSmoothingStatus::Accepted;
          }
        if(hasSizeForce) {
          for(const double scale : {1., .75, .5, .25, 1.25, 1.5, 2.}) {
            const SPoint3 target(
              initialXyz[center][0] + scale * displacement[0],
              initialXyz[center][1] + scale * displacement[1],
              initialXyz[center][2] + scale * displacement[2]);
            const double initialGuess[2] = {uv[center][0], uv[center][1]};
            const GPoint projected = face->closestPoint(target, initialGuess);
            if(!projected.succeeded() || !std::isfinite(projected.x()) ||
               !std::isfinite(projected.y()) ||
               !std::isfinite(projected.z()) ||
               !std::isfinite(projected.u()) ||
               !std::isfinite(projected.v()))
              continue;
            std::vector<UV> trialUv = uv;
            std::vector<Point> trialXyz = initialXyz;
            trialUv[center] = {projected.u(), projected.v()};
            trialXyz[center] = {
              projected.x(), projected.y(), projected.z()};
            if(acceptTrial(trialUv, trialXyz))
              return ExistingSmoothingStatus::Accepted;
          }
        }
      }

      Point origin, firstAxis, secondAxis;
      std::vector<UV> planePoints;
      if(!meanPlaneChart(initialXyz, pattern, origin, firstAxis, secondAxis,
                         planePoints))
        return ExistingSmoothingStatus::RejectedWinslow;
      const std::vector<UV> initialPlanePoints = planePoints;
      SmallCavityWinslowOptions winslowOptions = options.winslow;
      winslowOptions.harmonicInitialization = false;
      const SmallCavityWinslowResult winslow =
        optimizeSmallQuadCavityWinslow(planePoints, boundaryCount, pattern,
                                       winslowOptions);
      if(!winslow.success || !winslow.untangled)
        return ExistingSmoothingStatus::RejectedWinslow;

      // The Winslow unknowns live only in the local physical mean plane.
      // Project the optimized targets back onto the MAT surface with a
      // closest-point query, using the stored UV solely as an initial guess
      // and as Gmsh's required surface-coordinate bookkeeping.
      for(const double fraction : {1., .8, .6, .4, .25, .1}) {
        std::vector<UV> trialUv = uv;
        std::vector<Point> trialXyz = initialXyz;
        bool valid = true;
        for(std::size_t i = boundaryCount; i < planePoints.size(); ++i) {
          const UV trialPlane = {
            initialPlanePoints[i][0] + fraction *
              (planePoints[i][0] - initialPlanePoints[i][0]),
            initialPlanePoints[i][1] + fraction *
              (planePoints[i][1] - initialPlanePoints[i][1])};
          const SPoint3 target(
            origin[0] + trialPlane[0] * firstAxis[0] +
              trialPlane[1] * secondAxis[0],
            origin[1] + trialPlane[0] * firstAxis[1] +
              trialPlane[1] * secondAxis[1],
            origin[2] + trialPlane[0] * firstAxis[2] +
              trialPlane[1] * secondAxis[2]);
          const double initialGuess[2] = {uv[i][0], uv[i][1]};
          const GPoint projected = face->closestPoint(target, initialGuess);
          if(!projected.succeeded() || !std::isfinite(projected.x()) ||
             !std::isfinite(projected.y()) ||
             !std::isfinite(projected.z()) ||
             !std::isfinite(projected.u()) ||
             !std::isfinite(projected.v())) {
            valid = false;
            break;
          }
          trialUv[i] = {projected.u(), projected.v()};
          trialXyz[i] = {projected.x(), projected.y(), projected.z()};
        }
        if(!valid) continue;
        if(acceptTrial(trialUv, trialXyz))
          return ExistingSmoothingStatus::Accepted;
      }
      return rejectedBySize ? ExistingSmoothingStatus::RejectedSize :
                              ExistingSmoothingStatus::RejectedQuality;
    }

    void smoothTopologyNeighborhood(
      GFace *face, const std::vector<MVertex *> &coreInterior,
      const SmallCavityOptimizerOptions &options,
      const FaceHalfEdgeTopology *topology = nullptr)
    {
      const std::set<MVertex *> protectedVertices =
        protectedFaceVertices(face);
      if(std::any_of(coreInterior.begin(), coreInterior.end(),
                     [&](MVertex *vertex) {
                       return protectedVertices.find(vertex) !=
                              protectedVertices.end();
                     }))
        return;
      for(int pass = 0; pass < options.postTopologyNeighborSmoothingPasses;
          ++pass) {
        CavitySeed core;
        Adjacency adjacency;
        if(topology) {
          if(!interiorVertexCavity(face, coreInterior, *topology, core))
            return;
        }
        else {
          adjacency = buildAdjacency(surfaceElements(face));
          if(!interiorVertexCavity(face, coreInterior, adjacency, core))
            return;
        }
        const std::vector<MVertex *> boundary =
          core.patch.bdrVertices.front();
        smoothExistingCavity(face, core, options);
        for(MVertex *vertex : boundary) {
          if(protectedVertices.find(vertex) != protectedVertices.end())
            continue;
          CavitySeed neighbor;
          const bool valid = topology ?
            interiorVertexCavity(face, {vertex}, *topology, neighbor) :
            interiorVertexCavity(face, {vertex}, adjacency, neighbor);
          if(valid) smoothExistingCavity(face, neighbor, options);
        }
      }
    }

    std::size_t smoothLocalVertexStars(
      GFace *face, const std::vector<MVertex *> &focusVertices,
      const SmallCavityOptimizerOptions &options,
      const FaceHalfEdgeTopology &topology,
      const std::set<MVertex *> *additionalProtectedVertices = nullptr)
    {
      std::set<MVertex *> unique(focusVertices.begin(), focusVertices.end());
      const std::set<MVertex *> protectedVertices =
        protectedFaceVertices(face);
      SmallCavityOptimizerOptions localOptions = options;
      localOptions.winslow.maxInnerIterations =
        std::min(localOptions.winslow.maxInnerIterations, 50);
      localOptions.winslow.maxOuterIterations =
        std::min(localOptions.winslow.maxOuterIterations, 2);
      localOptions.winslow.maxLineSearchSteps =
        std::min(localOptions.winslow.maxLineSearchSteps, 20);
      localOptions.winslow.gradientTolerance =
        std::max(localOptions.winslow.gradientTolerance, 1.e-7);

      std::size_t accepted = 0;
      for(int pass = 0;
          pass < options.postTopologyNeighborSmoothingPasses; ++pass) {
        for(MVertex *vertex : unique) {
          if(!vertex || vertex->onWhat() != face ||
             protectedVertices.find(vertex) != protectedVertices.end() ||
             (additionalProtectedVertices &&
              additionalProtectedVertices->find(vertex) !=
                additionalProtectedVertices->end()))
            continue;
          CavitySeed seed;
          if(!interiorVertexCavity(
               face, {vertex}, topology, seed,
               !useFastInteractiveCleanUp(options)))
            continue;
          if(smoothExistingCavity(face, seed, localOptions) ==
             ExistingSmoothingStatus::Accepted)
            ++accepted;
        }
      }
      return accepted;
    }

    ExistingTopologyWinslowResult smoothAllInteriorVertexCavities(
      GFace *face, const SmallCavityOptimizerOptions &options,
      const std::set<MVertex *> *additionalProtectedVertices = nullptr)
    {
      ExistingTopologyWinslowResult result;
      if(!face || options.smoothingPasses < 0) {
        result.success = false;
        return result;
      }
      result.initialObjective = specificationObjective(surfaceElements(face));
      const std::set<MVertex *> protectedVertices =
        protectedFaceVertices(face);
      for(int pass = 0; pass < options.smoothingPasses; ++pass) {
        ++result.passes;
        const std::vector<MElement *> elements = surfaceElements(face);
        const Adjacency adjacency = buildAdjacency(elements);
        const std::vector<MVertex *> vertices = face->mesh_vertices;
        for(MVertex *vertex : vertices) {
          if(!vertex || vertex->onWhat() != face ||
             protectedVertices.find(vertex) != protectedVertices.end() ||
             (additionalProtectedVertices &&
              additionalProtectedVertices->find(vertex) !=
                additionalProtectedVertices->end()))
            continue;
          ++result.quadsVisited;
          CavitySeed seed;
          ExistingSmoothingStatus status = ExistingSmoothingStatus::Invalid;
          if(interiorVertexCavity(
               face, {vertex}, adjacency, seed,
               !useFastInteractiveCleanUp(options)))
            status = smoothExistingCavity(face, seed, options);
          if(status == ExistingSmoothingStatus::Invalid) {
            status = smoothMixedVertexSize(
              face, vertex, adjacency, options);
          }
          if(status == ExistingSmoothingStatus::Invalid) continue;
          if(status ==
             ExistingSmoothingStatus::SkippedSpecificationCompliant) {
            ++result.skippedSpecificationCompliant;
            continue;
          }
          ++result.admissibleCavities;
          ++result.cavitiesOptimized;
          switch(status) {
          case ExistingSmoothingStatus::SkippedSpecificationCompliant: break;
          case ExistingSmoothingStatus::RejectedWinslow:
            ++result.rejectedByWinslow;
            break;
          case ExistingSmoothingStatus::RejectedSize:
            ++result.rejectedBySize;
            break;
          case ExistingSmoothingStatus::RejectedQuality:
            ++result.rejectedByQuality;
            break;
          case ExistingSmoothingStatus::Accepted:
            ++result.acceptedCavities;
            break;
          case ExistingSmoothingStatus::Invalid: break;
          }
        }
      }
      result.finalObjective = specificationObjective(surfaceElements(face));
      if(options.invalidateVertexArrays) face->model()->deleteVertexArrays();
      return result;
    }

    bool tryDiamond(GFace *face, const DiamondSeed &diamond,
                    const SmallCavityOptimizerOptions &options,
                    SmallCavityOptimizerResult &result,
                    CleanUpDecisionPhase phase)
    {
      ++result.diamondsVisited;
      const CavitySeed &seed = diamond.cavity;
      const bool fastInteractive = useFastInteractiveCleanUp(options);
      if(options.quadCleanUp) {
        const std::set<MVertex *> protectedVertices =
          protectedFaceVertices(face);
        if(std::any_of(seed.patch.intVertices.begin(),
                       seed.patch.intVertices.end(),
                       [&](MVertex *vertex) {
                         return protectedVertices.find(vertex) !=
                                protectedVertices.end();
                       }))
          return false;
      }
      const std::size_t boundaryCount =
        seed.patch.bdrVertices.front().size();
      MVertex *retained =
        seed.patch.intVertices[diamond.retainedInterior];
      MVertex *removed = seed.patch.intVertices[diamond.removedInterior];

      std::unordered_map<MVertex *, std::size_t> boundaryIndex;
      for(std::size_t i = 0; i < boundaryCount; ++i)
        boundaryIndex[seed.patch.bdrVertices.front()[i]] = i;
      Pattern quadrangles;
      quadrangles.reserve(seed.patch.elements.size() - 1);
      for(MElement *element : seed.patch.elements) {
        if(element == diamond.diamond) continue;
        if(element->getNumPrimaryVertices() != 4) return false;
        std::array<std::size_t, 4> quad;
        std::set<std::size_t> unique;
        for(std::size_t i = 0; i < 4; ++i) {
          MVertex *vertex = element->getVertex(static_cast<int>(i));
          if(vertex == retained || vertex == removed)
            quad[i] = boundaryCount;
          else {
            const auto found = boundaryIndex.find(vertex);
            if(found == boundaryIndex.end()) return false;
            quad[i] = found->second;
          }
          unique.insert(quad[i]);
        }
        if(unique.size() != 4) return false;
        quadrangles.push_back(quad);
      }
      if(quadrangles.empty()) return false;

      std::vector<UV> uv;
      if(!currentParametrization(seed.patch, uv)) return false;
      const UV merged = {
        .5 * (uv[boundaryCount + diamond.retainedInterior][0] +
              uv[boundaryCount + diamond.removedInterior][0]),
        .5 * (uv[boundaryCount + diamond.retainedInterior][1] +
              uv[boundaryCount + diamond.removedInterior][1])};
      uv.resize(boundaryCount + 1);
      uv[boundaryCount] = merged;

      ++result.topologyCandidatesOptimized;
      SmallCavityWinslowOptions winslowOptions = options.winslow;
      winslowOptions.harmonicInitialization = false;
      const SmallCavityWinslowResult winslow =
        optimizeSmallQuadCavityWinslow(uv, boundaryCount, quadrangles,
                                       winslowOptions);
      if(!winslow.success || !winslow.untangled) {
        ++result.rejectedByWinslow;
        return false;
      }
      std::vector<Point> xyz;
      if(!mapCandidate(face, boundaryCount,
                       seed.patch.bdrVertices.front(), uv, xyz)) {
        ++result.rejectedByWinslow;
        return false;
      }
      const bool evaluateSize = options.enforceSizeMap || options.quadCleanUp;
      const SizeScore beforeSize = evaluateSize ?
        existingSizeScore(seed.patch, options, false) : SizeScore();
      const SizeScore afterSize = evaluateSize ?
        candidateSizeScore(face, uv, xyz, quadrangles, options,
                           boundaryCount) : SizeScore();
      if((options.quadCleanUp && !afterSize.admissible) ||
         (options.enforceSizeMap &&
          !admissibleSizeChange(beforeSize, afterSize, options))) {
        ++result.rejectedBySize;
        return false;
      }
      std::size_t candidateInvalidElementCount = 0;
      const SpecificationObjective objective = candidateObjective(
        quadrangles, xyz, &candidateInvalidElementCount);
      GeometryDeviation referenceGeometry;
      GeometryDeviation geometry;
      if((options.quadCleanUp || fastInteractive) &&
         !candidateQuadranglesAreNonConcave(quadrangles, uv, xyz)) {
        ++result.rejectedByQuality;
        return false;
      }
      // The collapse removes a pair of opposite valence-three vertices, which
      // is the connectivity improvement required by the diamond action. The
      // smoothed result must still preserve every absolute quality guard.
      const ValenceObjective candidateValence =
        candidatePatchValence(seed, quadrangles, 1);
      SpecificationObjective candidateComparison = objective;
      const SpecificationObjective unchanged = objectiveOutside(
        face, seed.patch.elements);
      candidateComparison += unchanged;
      SpecificationObjective referenceComparison = seed.objective;
      referenceComparison += unchanged;
      if(fastInteractive ||
         (options.quadCleanUp &&
          candidateComparison.absoluteBadElementCount ==
            referenceComparison.absoluteBadElementCount &&
          objective.absoluteBadElementCount == 0)) {
        referenceGeometry = existingGeometryDeviation(
          face, seed.patch.elements);
        geometry = candidateGeometryDeviation(face, uv, xyz, quadrangles);
      }
      const std::size_t beforeSizeViolations =
        beforeSize.belowMinimum + beforeSize.aboveMaximum + beforeSize.invalid;
      const std::size_t afterSizeViolations =
        afterSize.belowMinimum + afterSize.aboveMaximum + afterSize.invalid;
      CleanUpDecisionReason decision = CleanUpDecisionReason::Rejected;
      if(fastInteractive) {
        if(!referenceGeometry.valid || !geometry.valid) {
          ++result.rejectedByQuality;
          return false;
        }
        const double target = options.targetSize > 0. ?
          options.targetSize :
          std::sqrt(std::max(
            referenceGeometry.sampledArea /
              static_cast<double>(
                std::max<std::size_t>(1, referenceGeometry.elementCount)),
            std::numeric_limits<double>::min()));
        const double normalization = std::max(
          std::max(referenceGeometry.sampledArea, geometry.sampledArea) *
            target * target,
          std::numeric_limits<double>::min());
        const double normalizedCadChange =
          (geometry.squaredDistanceIntegral -
           referenceGeometry.squaredDistanceIntegral) /
          normalization;
        const FastGlobalQuality candidateQuality = fastGlobalQuality(
          objective, candidateValence, candidateInvalidElementCount,
          afterSizeViolations, afterSize.meanSquaredLogRatio,
          afterSize.edgeCount, normalizedCadChange);
        const FastGlobalQuality referenceQuality = fastGlobalQuality(
          seed.objective, seed.valence,
          topologicallyInvalidElementCount(seed.patch.elements),
          beforeSizeViolations, beforeSize.meanSquaredLogRatio,
          beforeSize.edgeCount, 0.);
        if(improvesFastGlobalQuality(candidateQuality, referenceQuality))
          decision = CleanUpDecisionReason::OtherImprovement;
      }
      else if(options.quadCleanUp) {
        decision = cleanUpDecision(
          candidateComparison, referenceComparison, geometry,
          referenceGeometry, objective.absoluteBadElementCount == 0,
          candidateValence, seed.valence,
          afterSizeViolations, beforeSizeViolations,
          afterSize.meanSquaredLogRatio, beforeSize.meanSquaredLogRatio,
          options.objectiveRelativeTolerance);
      }
      else if(noWorseAbsoluteSpecifications(
                objective, seed.objective,
                options.objectiveRelativeTolerance)) {
        decision = CleanUpDecisionReason::OtherImprovement;
      }
      if(!decisionAllowed(decision, phase)) {
        ++result.rejectedByQuality;
        return false;
      }

      Candidate candidate;
      candidate.valid = true;
      candidate.uv = std::move(uv);
      candidate.xyz = std::move(xyz);
      candidate.quadrangles = std::move(quadrangles);
      candidate.interiorAssignment = {diamond.retainedInterior};
      candidate.objective = objective;
      candidate.geometry = geometry;
      candidate.referenceGeometry = referenceGeometry;
      candidate.valence = candidateValence;
      candidate.invalidElementCount = candidateInvalidElementCount;
      candidate.sizeError = afterSize.meanSquaredLogRatio;
      candidate.sizeEdgeCount = afterSize.edgeCount;
      candidate.sizeViolationCount = afterSizeViolations;
      candidate.unchangedObjective = unchanged;
      candidate.decisionReason = decision;
      std::vector<MVertex *> retainedInterior;
      if(!executeCandidate(face, seed, candidate, &retainedInterior))
        return false;
      if(options.quadCleanUp)
        recordAcceptedCleanUpDecision(result, candidate.decisionReason);
      if(options.quadCleanUp)
        applyCandidateSmoothing(candidate);
      else if(!fastInteractive)
        smoothTopologyNeighborhood(face, retainedInterior, options);
      return true;
    }

    bool tryValenceSixCavity(
      GFace *face, const CavitySeed &seed,
      const SmallCavityOptimizerOptions &options,
      SmallCavityOptimizerResult &result, CleanUpDecisionPhase phase)
    {
      ++result.valenceSixVerticesVisited;
      if(options.quadCleanUp) {
        const std::set<MVertex *> protectedVertices =
          protectedFaceVertices(face);
        if(std::any_of(seed.patch.intVertices.begin(),
                       seed.patch.intVertices.end(),
                       [&](MVertex *vertex) {
                         return protectedVertices.find(vertex) !=
                                protectedVertices.end();
                       }))
          return false;
      }
      const std::size_t boundaryCount =
        seed.patch.bdrVertices.front().size();
      if(boundaryCount != 12 || seed.patch.intVertices.size() != 1)
        return false;
      std::vector<Pattern> patterns;
      if(getDiskQuadrangulations(boundaryCount, 2, patterns) != 0 ||
         patterns.empty())
        return false;
      const auto ranked = rankPatterns(
        seed.patch, patterns, options.maximumTopologyCandidatesPerCavity, 2);
      std::vector<UV> initial;
      if(!currentParametrization(seed.patch, initial)) return false;
      initial.resize(boundaryCount + 2, initial[boundaryCount]);
      const bool evaluateSize = options.enforceSizeMap || options.quadCleanUp;
      const SizeScore beforeSize = evaluateSize ?
        existingSizeScore(seed.patch, options, false) : SizeScore();
      const std::size_t beforeSizeViolations =
        beforeSize.belowMinimum + beforeSize.aboveMaximum +
        beforeSize.invalid;
      const SpecificationObjective unchangedObjective =
        options.quadCleanUp ? objectiveOutside(face, seed.patch.elements) :
                              SpecificationObjective();
      GeometryDeviation referenceGeometry;
      bool referenceGeometryEvaluated = false;
      SmallCavityWinslowOptions winslowOptions = options.winslow;
      // The two new interior points initially coincide with the old
      // valence-six vertex. Harmonic initialization separates this symmetric
      // seed before the nonlinear barrier solve.
      winslowOptions.harmonicInitialization = true;
      std::set<ConnectivitySignature> triedConnectivity;
      Candidate best;

      for(const PatternConfiguration &configuration : ranked) {
        Pattern quadrangles = transformPattern(
          patterns[configuration.pattern], boundaryCount,
          configuration.rotation, configuration.reflected);
        std::array<std::size_t, 2> interiorDegree = {0, 0};
        bool validInterior = true;
        for(const auto &quad : quadrangles)
          for(const std::size_t vertex : quad) {
            if(vertex < boundaryCount) continue;
            const std::size_t interior = vertex - boundaryCount;
            if(interior >= interiorDegree.size()) {
              validInterior = false;
              break;
            }
            ++interiorDegree[interior];
          }
        // The operation must actually split the valence-six singularity.
        if(!validInterior || interiorDegree[0] == 0 ||
           interiorDegree[1] == 0 || interiorDegree[0] >= 6 ||
           interiorDegree[1] >= 6)
          continue;
        const ConnectivitySignature connectivity =
          candidateConnectivitySignature(quadrangles, boundaryCount,
                                         {0, 1});
        if(!triedConnectivity.insert(connectivity).second) continue;

        std::vector<UV> uv = initial;
        ++result.topologyCandidatesOptimized;
        const SmallCavityWinslowResult winslow =
          optimizeSmallQuadCavityWinslow(uv, boundaryCount, quadrangles,
                                         winslowOptions);
        if(!winslow.success || !winslow.untangled) {
          ++result.rejectedByWinslow;
          continue;
        }
        std::vector<Point> xyz;
        if(!mapCandidate(face, boundaryCount,
                         seed.patch.bdrVertices.front(), uv, xyz)) {
          ++result.rejectedByWinslow;
          continue;
        }
        SizeScore size;
        if(evaluateSize) {
          size = candidateSizeScore(face, uv, xyz, quadrangles, options,
                                    boundaryCount);
          if((options.quadCleanUp && !size.admissible) ||
             (options.enforceSizeMap &&
              !admissibleSizeChange(beforeSize, size, options))) {
            ++result.rejectedBySize;
            continue;
          }
        }
        const SpecificationObjective objective =
          candidateObjective(quadrangles, xyz);
        if(options.quadCleanUp &&
           !candidateQuadranglesAreNonConcave(quadrangles, uv, xyz)) {
          ++result.rejectedByQuality;
          continue;
        }
        const ValenceObjective candidateValence =
          candidatePatchValence(seed, quadrangles, 2);
        // The B=12, I=1->2 template is a connectivity repair, not a surface
        // refinement operator.  Requiring a strict affected-star valence
        // decrease prevents a newly created valence-six vertex from being
        // split again merely because the extra quad reduces chordal error.
        if(!options.quadCleanUp &&
           !improvesValencePareto(candidateValence, seed.valence)) {
          ++result.rejectedByQuality;
          continue;
        }
        SpecificationObjective candidateComparison = objective;
        candidateComparison += unchangedObjective;
        SpecificationObjective referenceComparison = seed.objective;
        referenceComparison += unchangedObjective;
        GeometryDeviation geometry;
        if(options.quadCleanUp &&
           candidateComparison.absoluteBadElementCount ==
             referenceComparison.absoluteBadElementCount &&
           objective.absoluteBadElementCount == 0) {
          if(!referenceGeometryEvaluated) {
            referenceGeometry = existingGeometryDeviation(
              face, seed.patch.elements);
            referenceGeometryEvaluated = true;
          }
          geometry = candidateGeometryDeviation(face, uv, xyz, quadrangles);
        }
        const std::size_t sizeViolations =
          size.belowMinimum + size.aboveMaximum + size.invalid;
        const CleanUpDecisionReason decision = options.quadCleanUp ?
          cleanUpDecision(
            candidateComparison, referenceComparison, geometry,
            referenceGeometry, objective.absoluteBadElementCount == 0,
            candidateValence, seed.valence,
            sizeViolations, beforeSizeViolations, size.meanSquaredLogRatio,
            beforeSize.meanSquaredLogRatio,
            options.objectiveRelativeTolerance) :
          (noWorseAbsoluteSpecifications(
             objective, seed.objective,
             options.objectiveRelativeTolerance) ?
             CleanUpDecisionReason::OtherImprovement :
             CleanUpDecisionReason::Rejected);
        if(!decisionAllowed(decision, phase)) {
          ++result.rejectedByQuality;
          continue;
        }
        Candidate candidate;
        candidate.valid = true;
        candidate.uv = std::move(uv);
        candidate.xyz = std::move(xyz);
        candidate.quadrangles = std::move(quadrangles);
        candidate.objective = objective;
        candidate.geometry = geometry;
        candidate.referenceGeometry = referenceGeometry;
        candidate.sizeError = size.meanSquaredLogRatio;
        candidate.sizeViolationCount = sizeViolations;
        candidate.valence = candidateValence;
        candidate.unchangedObjective = unchangedObjective;
        candidate.decisionReason = decision;
        if(options.quadCleanUp ?
             !betterCleanUpCandidate(candidate, best, options) :
             !betterByQualityThenSize(
               candidate.objective, candidate.sizeError, best, options))
          continue;
        best = std::move(candidate);
      }
      if(!best.valid) return false;
      std::vector<MVertex *> interior;
      if(!executeValenceSixCandidate(face, seed, best, interior)) return false;
      if(options.quadCleanUp)
        recordAcceptedCleanUpDecision(result, best.decisionReason);
      if(options.quadCleanUp)
        applyCandidateSmoothing(best);
      else
        smoothTopologyNeighborhood(face, interior, options);
      return true;
    }

    bool tryBoundaryTriangleQuadTriangleFan(
      GFace *face, const CavitySeed &seed,
      const SmallCavityOptimizerOptions &options,
      SmallCavityOptimizerResult &result, CleanUpDecisionPhase phase)
    {
      ++result.boundaryTriangleQuadTriangleFansVisited;
      const std::size_t boundaryCount =
        seed.patch.bdrVertices.front().size();
      if(boundaryCount < 6 || boundaryCount % 2 ||
         !seed.patch.intVertices.empty())
        return false;
      std::vector<Pattern> patterns;
      if(getDiskQuadrangulations(boundaryCount, 1, patterns) != 0 ||
         patterns.empty())
        return false;
      const auto ranked = rankPatterns(
        seed.patch, patterns, options.maximumTopologyCandidatesPerCavity, 1);
      std::vector<UV> initial;
      if(!currentParametrization(seed.patch, initial)) return false;
      UV centroid = {0., 0.};
      for(const UV &point : initial) {
        centroid[0] += point[0];
        centroid[1] += point[1];
      }
      centroid[0] /= static_cast<double>(boundaryCount);
      centroid[1] /= static_cast<double>(boundaryCount);
      initial.push_back(centroid);
      const bool evaluateSize = options.enforceSizeMap || options.quadCleanUp;
      const SizeScore beforeSize = evaluateSize ?
        existingSizeScore(seed.patch, options, false) : SizeScore();
      const SpecificationObjective unchangedObjective =
        options.quadCleanUp ? objectiveOutside(face, seed.patch.elements) :
                              SpecificationObjective();
      SmallCavityWinslowOptions winslowOptions = options.winslow;
      winslowOptions.harmonicInitialization = false;
      std::set<ConnectivitySignature> triedConnectivity;
      Candidate best;

      for(const PatternConfiguration &configuration : ranked) {
        Pattern quadrangles = transformPattern(
          patterns[configuration.pattern], boundaryCount,
          configuration.rotation, configuration.reflected);
        if(quadrangles.size() != boundaryCount / 2) continue;
        const ConnectivitySignature connectivity =
          candidateConnectivitySignature(quadrangles, boundaryCount, {0});
        if(!triedConnectivity.insert(connectivity).second) continue;
        std::vector<UV> uv = initial;
        ++result.topologyCandidatesOptimized;
        const SmallCavityWinslowResult winslow =
          optimizeSmallQuadCavityWinslow(uv, boundaryCount, quadrangles,
                                         winslowOptions);
        if(!winslow.success || !winslow.untangled) {
          ++result.rejectedByWinslow;
          continue;
        }
        std::vector<Point> xyz;
        if(!mapCandidate(face, boundaryCount,
                         seed.patch.bdrVertices.front(), uv, xyz)) {
          ++result.rejectedByWinslow;
          continue;
        }
        Candidate candidate;
        candidate.valid = true;
        candidate.uv = std::move(uv);
        candidate.xyz = std::move(xyz);
        candidate.quadrangles = std::move(quadrangles);
        candidate.valence = candidatePatchValence(
          seed, candidate.quadrangles, 1);
        if(options.quadCleanUp) {
          if(!smoothNewInteriorCandidate(
               face, seed, candidate, options, result, phase))
            continue;
          candidate.decisionReason = cleanUpDecision(
            comparisonObjective(candidate),
            comparisonReferenceObjective(seed, candidate),
            candidate.geometry, candidate.smoothedReferenceGeometry,
            candidate.objective.absoluteBadElementCount == 0,
            candidate.valence, seed.valence,
            candidate.sizeViolationCount,
            candidate.smoothedReferenceSizeViolationCount,
            candidate.sizeError, candidate.smoothedReferenceSizeError,
            options.objectiveRelativeTolerance);
          if(!decisionAllowed(candidate.decisionReason, phase)) {
            ++result.rejectedByQuality;
            continue;
          }
        }
        else {
          SizeScore size;
          if(evaluateSize) {
            size = candidateSizeScore(
              face, candidate.uv, candidate.xyz, candidate.quadrangles,
              options, boundaryCount);
            if(!size.admissible ||
               (options.enforceSizeMap &&
                !admissibleSizeChange(beforeSize, size, options))) {
              ++result.rejectedBySize;
              continue;
            }
          }
          candidate.objective = candidateObjective(
            candidate.quadrangles, candidate.xyz);
          candidate.sizeError = size.meanSquaredLogRatio;
          candidate.sizeViolationCount =
            size.belowMinimum + size.aboveMaximum + size.invalid;
          candidate.unchangedObjective = unchangedObjective;
          if(!noWorseAbsoluteSpecifications(
               candidate.objective, seed.objective,
               options.objectiveRelativeTolerance)) {
            ++result.rejectedByQuality;
            continue;
          }
        }
        if(options.quadCleanUp ?
             !betterCleanUpCandidate(candidate, best, options) :
             !betterByQualityThenSize(
               candidate.objective, candidate.sizeError, best, options))
          continue;
        best = std::move(candidate);
      }
      if(!best.valid) return false;
      MVertex *created = nullptr;
      if(!executeNewInteriorCandidate(face, seed, best, created)) return false;
      if(options.quadCleanUp)
        recordAcceptedCleanUpDecision(result, best.decisionReason);
      if(options.quadCleanUp)
        applyCandidateSmoothing(best);
      else
        smoothTopologyNeighborhood(face, {created}, options);
      return true;
    }

    bool tryCavity(GFace *face, const CavitySeed &seed,
                   const SmallCavityOptimizerOptions &options,
                   SmallCavityOptimizerResult &result,
                   CleanUpDecisionPhase phase)
    {
      ++result.cavitiesVisited;
      if(options.quadCleanUp) {
        const std::set<MVertex *> protectedVertices =
          protectedFaceVertices(face);
        if(std::any_of(seed.patch.intVertices.begin(),
                       seed.patch.intVertices.end(),
                       [&](MVertex *vertex) {
                         return protectedVertices.find(vertex) !=
                                protectedVertices.end();
                       }))
          return false;
      }
      if(!seed.alwaysTryTopology &&
         options.topologyOnlyIfCavityHasSpecificationFailure &&
         !hasQuadFailingAbsoluteSpecifications(seed) &&
         !(options.quadCleanUp && seed.kind == CavityKind::Edge &&
           phase == CleanUpDecisionPhase::BetterGeometry)) {
        ++result.skippedSpecificationCompliant;
        return false;
      }
      const std::size_t boundaryCount = seed.patch.bdrVertices.front().size();
      std::vector<Pattern> patterns;
      if(getDiskQuadrangulations(boundaryCount, seed.interiorVertexCount,
                                 patterns) != 0 || patterns.empty())
        return false;
      const auto ranked = rankPatterns(
        seed.patch, patterns, options.maximumTopologyCandidatesPerCavity,
        seed.interiorVertexCount);
      std::vector<UV> initial;
      if(!currentParametrization(seed.patch, initial)) return false;
      const bool evaluateSize = options.enforceSizeMap || options.quadCleanUp;
      const SizeScore beforeSize = evaluateSize ?
        existingSizeScore(seed.patch, options, false) : SizeScore();
      const std::size_t beforeSizeViolations =
        beforeSize.belowMinimum + beforeSize.aboveMaximum +
        beforeSize.invalid;
      const SpecificationObjective unchangedObjective =
        options.quadCleanUp ? objectiveOutside(face, seed.patch.elements) :
                              SpecificationObjective();
      GeometryDeviation referenceGeometry;
      bool referenceGeometryEvaluated = false;
      const bool repairingConcaveEdge =
        seed.kind == CavityKind::Edge &&
        hasConcaveQuadrangle(seed.patch.elements);
      SmallCavityWinslowOptions winslowOptions = options.winslow;
      winslowOptions.harmonicInitialization = false;
      ConnectivitySignature existingConnectivity;
      const bool existingIsAllQuad =
        existingConnectivitySignature(seed.patch, existingConnectivity);
      std::set<ConnectivitySignature> triedConnectivity;
      std::size_t localCandidates = 0, localWinslowRejected = 0;
      std::size_t localSizeRejected = 0, localQualityRejected = 0;
      std::size_t localSizeBoundsRejected = 0, localSizeErrorRejected = 0;
      bool hasBestEvaluatedObjective = false;
      SpecificationObjective bestEvaluatedObjective;

      Candidate best;
      for(const PatternConfiguration &configuration : ranked) {
        Pattern quadrangles = transformPattern(
          patterns[configuration.pattern], boundaryCount,
          configuration.rotation, configuration.reflected);
        std::vector<std::size_t> assignment(seed.interiorVertexCount);
        for(std::size_t i = 0; i < assignment.size(); ++i)
          assignment[i] = i;
        {
          const ConnectivitySignature connectivity =
            candidateConnectivitySignature(quadrangles, boundaryCount,
                                           assignment);
          if((existingIsAllQuad && connectivity == existingConnectivity) ||
             !triedConnectivity.insert(connectivity).second)
            continue;
          if(seed.kind == CavityKind::Edge && !options.quadCleanUp &&
             !edgeSwapEdgesIntersect(seed, quadrangles, initial)) {
            ++result.rejectedEdgeSwapsNoIntersection;
            continue;
          }
          if(seed.kind == CavityKind::Edge && !options.quadCleanUp &&
             !candidateQuadsAreStrictlyConvex(quadrangles, initial)) {
            ++result.rejectedEdgeSwapsNonConvex;
            continue;
          }
          std::vector<UV> uv = initial;
          ++result.topologyCandidatesOptimized;
          ++localCandidates;
          if(seed.interiorVertexCount > 0) {
            const SmallCavityWinslowResult winslow =
              optimizeSmallQuadCavityWinslow(
                uv, boundaryCount, quadrangles, winslowOptions);
            if(!winslow.success || !winslow.untangled) {
              ++result.rejectedByWinslow;
              ++localWinslowRejected;
              continue;
            }
          }
          std::vector<Point> xyz;
          if(!mapCandidate(face, boundaryCount,
                           seed.patch.bdrVertices.front(), uv, xyz)) {
            ++result.rejectedByWinslow;
            ++localWinslowRejected;
            continue;
          }
          SizeScore size;
          const bool needsOneRingSmoothing =
            options.quadCleanUp && assignment.empty();
          if(evaluateSize && !needsOneRingSmoothing) {
            size = candidateSizeScore(
              face, uv, xyz, quadrangles, options, boundaryCount);
            if((options.quadCleanUp && !size.admissible) ||
               (options.enforceSizeMap &&
                !admissibleSizeChange(beforeSize, size, options))) {
              ++result.rejectedBySize;
              ++localSizeRejected;
              if(!size.admissible)
                ++localSizeBoundsRejected;
              else
                ++localSizeErrorRejected;
              continue;
            }
          }

          Candidate candidate;
          candidate.valid = true;
          candidate.uv = std::move(uv);
          candidate.xyz = std::move(xyz);
          candidate.quadrangles = quadrangles;
          candidate.interiorAssignment = assignment;
          candidate.objective =
            candidateObjective(candidate.quadrangles, candidate.xyz);
          candidate.sizeError = size.meanSquaredLogRatio;
          candidate.sizeViolationCount =
            size.belowMinimum + size.aboveMaximum + size.invalid;
          candidate.valence = candidatePatchValence(
            seed, candidate.quadrangles, assignment.size());
          candidate.unchangedObjective = unchangedObjective;
          if(needsOneRingSmoothing &&
             !smoothZeroInteriorCandidate(face, seed, candidate, options,
                                          result)) {
            continue;
          }
          if(options.quadCleanUp &&
             !candidateQuadranglesAreNonConcave(
                candidate.quadrangles, candidate.uv, candidate.xyz)) {
            ++result.rejectedByQuality;
            ++localQualityRejected;
            continue;
          }
          if(seed.kind == CavityKind::Edge && options.quadCleanUp &&
             !repairingConcaveEdge &&
             !edgeSwapEdgesIntersect(seed, candidate.quadrangles,
                                     candidate.uv)) {
            ++result.rejectedEdgeSwapsNoIntersection;
            continue;
          }
          if(seed.kind == CavityKind::Edge && options.quadCleanUp &&
             !candidateQuadsAreStrictlyConvex(candidate.quadrangles,
                                               candidate.uv)) {
            ++result.rejectedEdgeSwapsNonConvex;
            continue;
          }
          const SpecificationObjective &referenceObjective =
            candidate.hasSmoothedReference ?
              candidate.smoothedReferenceObjective : seed.objective;
          if(!hasBestEvaluatedObjective || improvesSpecificationObjective(
               candidate.objective, bestEvaluatedObjective,
               options.objectiveRelativeTolerance)) {
            bestEvaluatedObjective = candidate.objective;
            hasBestEvaluatedObjective = true;
          }
          const std::size_t referenceSizeViolations =
            candidate.hasSmoothedReference ?
              candidate.smoothedReferenceSizeViolationCount :
              beforeSizeViolations;
          const double referenceSizeError = candidate.hasSmoothedReference ?
            candidate.smoothedReferenceSizeError :
            beforeSize.meanSquaredLogRatio;
          const SpecificationObjective candidateComparison =
            comparisonObjective(candidate);
          const SpecificationObjective referenceComparison =
            comparisonReferenceObjective(seed, candidate);
          if(options.quadCleanUp && !needsOneRingSmoothing &&
             candidateComparison.absoluteBadElementCount ==
               referenceComparison.absoluteBadElementCount &&
             candidate.objective.absoluteBadElementCount == 0) {
            if(!referenceGeometryEvaluated) {
              referenceGeometry = existingGeometryDeviation(
                face, seed.patch.elements);
              referenceGeometryEvaluated = true;
            }
            candidate.geometry = candidateGeometryDeviation(
              face, candidate.uv, candidate.xyz, candidate.quadrangles);
          }
          const GeometryDeviation &evaluatedReferenceGeometry =
            candidate.hasSmoothedReference ?
              candidate.smoothedReferenceGeometry : referenceGeometry;
          candidate.referenceGeometry = evaluatedReferenceGeometry;
          const CleanUpDecisionReason decision = options.quadCleanUp ?
            cleanUpDecision(
              candidateComparison, referenceComparison,
              candidate.geometry, evaluatedReferenceGeometry,
              candidate.objective.absoluteBadElementCount == 0,
              candidate.valence, seed.valence,
              candidate.sizeViolationCount, referenceSizeViolations,
              candidate.sizeError, referenceSizeError,
              options.objectiveRelativeTolerance) :
            (improvesSpecificationObjective(
               candidate.objective, referenceObjective,
               options.objectiveRelativeTolerance) ?
               CleanUpDecisionReason::OtherImprovement :
               CleanUpDecisionReason::Rejected);
          candidate.decisionReason = decision;
          const bool acceptedByObjective = decisionAllowed(decision, phase);
          if(!acceptedByObjective) {
            ++result.rejectedByQuality;
            ++localQualityRejected;
            continue;
          }
          if(options.quadCleanUp ?
               !betterCleanUpCandidate(candidate, best, options) :
               !betterByQualityThenSize(
                 candidate.objective, candidate.sizeError, best, options))
            continue;
          best = std::move(candidate);
        }
      }
      if(options.verbose > 1 && seed.interiorVertexCount == 1) {
        const std::size_t vertex = seed.patch.intVertices.front()->getNum();
        Msg::Info("QuadOptimizer: vertex %zu B=%zu candidates=%zu "
                  "rejected(winslow=%zu,size=%zu,quality=%zu) abs=%zu "
                  "sizeBounds=%zu sizeError=%zu bestAbs=%zu pref=%zu "
                  "bestPref=%zu accepted=%d",
                  vertex, boundaryCount, localCandidates,
                  localWinslowRejected, localSizeRejected,
                  localQualityRejected,
                  seed.objective.absoluteViolationCount,
                  localSizeBoundsRejected, localSizeErrorRejected,
                  hasBestEvaluatedObjective ?
                    bestEvaluatedObjective.absoluteViolationCount : 0,
                  seed.objective.preferredViolationCount,
                  hasBestEvaluatedObjective ?
                    bestEvaluatedObjective.preferredViolationCount : 0,
                  best.valid ? 1 : 0);
      }
      if(!best.valid) return false;
      if(options.verbose && seed.kind == CavityKind::Edge) {
        IndexedEdge oldEdge, newEdge;
        const std::vector<MVertex *> &boundary =
          seed.patch.bdrVertices.front();
        if(existingInteriorEdge(seed, oldEdge) &&
           candidateInteriorEdge(best.quadrangles, boundary.size(),
                                 newEdge)) {
          const char *reason =
            best.decisionReason ==
                CleanUpDecisionReason::FewerUnacceptableElements ?
              "fewer-unacceptable" :
            best.decisionReason == CleanUpDecisionReason::BetterGeometry ?
              "better-geometry" : "cleanup";
          const double geometryChange =
            best.geometry.valid && best.referenceGeometry.valid ?
              best.geometry.squaredDistanceIntegral -
                best.referenceGeometry.squaredDistanceIntegral : 0.;
          Msg::Info("QuadCleanUp swap face %d: %zu-%zu -> %zu-%zu "
                    "reason=%s dE2=%.17g",
                    face->tag(), boundary[oldEdge.first]->getNum(),
                    boundary[oldEdge.second]->getNum(),
                    boundary[newEdge.first]->getNum(),
                    boundary[newEdge.second]->getNum(), reason,
                    geometryChange);
        }
      }
      std::vector<MVertex *> createdInterior;
      if(!executeCandidate(face, seed, best, &createdInterior)) return false;
      if(options.quadCleanUp)
        recordAcceptedCleanUpDecision(result, best.decisionReason);
      if(options.quadCleanUp)
        applyCandidateSmoothing(best);
      else
        smoothTopologyNeighborhood(face, createdInterior, options);
      return true;
    }

    bool tryFlexibleCleanUpCavity(
      GFace *face, const CavitySeed &seed,
      const SmallCavityOptimizerOptions &options,
      SmallCavityOptimizerResult &result,
      FaceHalfEdgeTopology *topology,
      CleanUpDecisionPhase phase,
      std::set<MVertex *> &fastCadProtectedVertices)
    {
      ++result.cavitiesVisited;
      ++result.cleanUpCavitiesVisited;
      if(options.quadCleanUp) {
        const std::set<MVertex *> protectedVertices =
          protectedFaceVertices(face);
        if(std::any_of(seed.patch.intVertices.begin(),
                       seed.patch.intVertices.end(),
                       [&](MVertex *vertex) {
                         return protectedVertices.find(vertex) !=
                                protectedVertices.end();
                       }))
          return false;
      }
      if(!seed.alwaysTryTopology &&
         options.topologyOnlyIfCavityHasSpecificationFailure &&
         !flexibleCavityNeedsRepair(seed, options)) {
        ++result.skippedSpecificationCompliant;
        return false;
      }
      const std::size_t boundaryCount =
        seed.patch.bdrVertices.front().size();
      if(boundaryCount < 4 || boundaryCount > 20 || boundaryCount % 2)
        return false;

      std::vector<UV> boundary;
      if(!boundaryParametrization(seed.patch, boundary)) return false;
      boundary.resize(boundaryCount);
      UV centroid = {0., 0.};
      for(const UV &point : boundary) {
        centroid[0] += point[0];
        centroid[1] += point[1];
      }
      centroid[0] /= static_cast<double>(boundaryCount);
      centroid[1] /= static_cast<double>(boundaryCount);

      const SizeScore beforeSize = existingSizeScore(
        seed.patch, options, false);
      const std::size_t beforeSizeViolations =
        beforeSize.belowMinimum + beforeSize.aboveMaximum +
        beforeSize.invalid;
      const bool fastInteractive = useFastInteractiveCleanUp(options);
      const std::size_t beforeInvalidElementCount =
        topologicallyInvalidElementCount(seed.patch.elements);
      const FastGlobalQuality referenceFastQuality = fastGlobalQuality(
        seed.objective, seed.valence, beforeInvalidElementCount,
        beforeSizeViolations, beforeSize.meanSquaredLogRatio,
        beforeSize.edgeCount, 0.);
      const SpecificationObjective unchangedObjective =
        options.quadCleanUp ? objectiveOutside(face, seed.patch.elements) :
                              SpecificationObjective();
      GeometryDeviation referenceGeometry;
      bool referenceGeometryEvaluated = false;
      SmallCavityWinslowOptions winslowOptions = options.winslow;
      winslowOptions.harmonicInitialization = true;
      ConnectivitySignature existingConnectivity;
      const bool existingIsAllQuad =
        existingConnectivitySignature(seed.patch, existingConnectivity);
      std::set<ConnectivitySignature> triedConnectivity;
      const std::size_t createdMarker =
        std::numeric_limits<std::size_t>::max();

      auto candidateFastQuality = [&](const Candidate &candidate) {
        const double cadChange = candidate.hasEdgeSwapCad ?
          (candidate.edgeSwapCadDistance * candidate.edgeSwapCadDistance -
           candidate.referenceEdgeSwapCadDistance *
             candidate.referenceEdgeSwapCadDistance) /
            (candidate.edgeSwapCadScale * candidate.edgeSwapCadScale) :
          0.;
        return fastGlobalQuality(
          candidate.objective, candidate.valence,
          candidate.invalidElementCount, candidate.sizeViolationCount,
          candidate.sizeError, candidate.sizeEdgeCount, cadChange);
      };

      auto decide = [&](const Candidate &candidate) {
        const SpecificationObjective &referenceObjective =
          candidate.hasSmoothedReference ?
            candidate.smoothedReferenceObjective : seed.objective;
        const std::size_t referenceSizeViolations =
          candidate.hasSmoothedReference ?
            candidate.smoothedReferenceSizeViolationCount :
            beforeSizeViolations;
        const double referenceSizeError = candidate.hasSmoothedReference ?
          candidate.smoothedReferenceSizeError :
          beforeSize.meanSquaredLogRatio;
        const double cadTolerance = candidate.hasEdgeSwapCad ?
          1.e-12 * std::max(1., candidate.edgeSwapCadScale) : 0.;
        const bool cadDoesNotRegress = !candidate.hasEdgeSwapCad ||
          candidate.edgeSwapCadDistance <=
            candidate.referenceEdgeSwapCadDistance + cadTolerance;
        const bool fastQualityImprovement = !fastInteractive ||
          (cadDoesNotRegress && improvesFastGlobalQuality(
            candidateFastQuality(candidate), referenceFastQuality));
        if(options.quadCleanUp) {
          const CleanUpDecisionReason reason = cleanUpDecision(
            comparisonObjective(candidate),
            comparisonReferenceObjective(seed, candidate),
            candidate.geometry, candidate.referenceGeometry,
            candidate.objective.absoluteBadElementCount == 0,
            candidate.valence, seed.valence,
            candidate.sizeViolationCount, referenceSizeViolations,
            candidate.sizeError, referenceSizeError,
            options.objectiveRelativeTolerance,
            // Generic disk enumeration can also return a denser topology.
            // Keep QuadCleanUp from becoming a geometry-driven global
            // refiner: those structural candidates additionally need the
            // published valence cleanup, while swaps and named Cleanup
            // templates use geometry directly.
            candidate.quadrangles.size() > seed.patch.elements.size() ||
              candidate.interiorAssignment.size() >
                seed.patch.intVertices.size());
          return decisionAllowed(reason, phase) ? reason :
            CleanUpDecisionReason::Rejected;
        }
        const bool specificationImprovement = improvesSpecificationObjective(
          candidate.objective, referenceObjective,
          options.objectiveRelativeTolerance);
        if(seed.kind == CavityKind::CleanUpShape)
          return specificationImprovement && fastQualityImprovement ?
            CleanUpDecisionReason::OtherImprovement :
            CleanUpDecisionReason::Rejected;
        if(seed.kind == CavityKind::CleanUpConnectivity ||
           seed.kind == CavityKind::CleanUpBoundary)
          return (specificationImprovement ||
            (noWorseAbsoluteSpecifications(
               candidate.objective, referenceObjective,
               options.objectiveRelativeTolerance) &&
             improvesValence(candidate.valence, seed.valence))) &&
              fastQualityImprovement ?
            CleanUpDecisionReason::OtherImprovement :
            CleanUpDecisionReason::Rejected;
        if(seed.kind == CavityKind::CleanUpSize)
          return (noWorseAbsoluteSpecifications(
                   candidate.objective, referenceObjective,
                   options.objectiveRelativeTolerance) &&
                 (candidate.sizeViolationCount < referenceSizeViolations ||
                  (candidate.sizeViolationCount == referenceSizeViolations &&
                   std::isfinite(candidate.sizeError) &&
                   candidate.sizeError + 1.e-12 <
                     referenceSizeError)) && fastQualityImprovement) ?
            CleanUpDecisionReason::OtherImprovement :
            CleanUpDecisionReason::Rejected;
        return specificationImprovement && fastQualityImprovement ?
          CleanUpDecisionReason::OtherImprovement :
          CleanUpDecisionReason::Rejected;
      };

      auto better = [&](const Candidate &candidate,
                        const Candidate &reference) {
        if(options.quadCleanUp)
          return betterCleanUpCandidate(candidate, reference, options);
        const SpecificationObjective candidateQuality =
          candidate.objective;
        const SpecificationObjective referenceQuality =
          reference.objective;
        if(improvesSpecificationObjective(
             candidateQuality, referenceQuality,
             options.objectiveRelativeTolerance))
          return true;
        if(improvesSpecificationObjective(
             referenceQuality, candidateQuality,
             options.objectiveRelativeTolerance))
          return false;
        if(improvesValence(candidate.valence, reference.valence)) return true;
        if(improvesValence(reference.valence, candidate.valence)) return false;
        if(candidate.sizeViolationCount != reference.sizeViolationCount)
          return candidate.sizeViolationCount < reference.sizeViolationCount;
        if(candidate.sizeError != reference.sizeError)
          return candidate.sizeError < reference.sizeError;
        if(fastInteractive) {
          const FastGlobalQuality candidateQuality =
            candidateFastQuality(candidate);
          const FastGlobalQuality referenceQuality =
            candidateFastQuality(reference);
          if(improvesFastGlobalQuality(candidateQuality, referenceQuality))
            return true;
          if(improvesFastGlobalQuality(referenceQuality, candidateQuality))
            return false;
        }
        return false;
      };

      // Screen many connectivities with a deliberately short Winslow solve,
      // then spend the full nonlinear solve only on the geometrically best
      // shortlist. This preserves the large cavity search while avoiding
      // hundreds of fully converged solves for every seed.
      SmallCavityWinslowOptions screeningOptions = winslowOptions;
      screeningOptions.maxInnerIterations =
        std::min(screeningOptions.maxInnerIterations, 20);
      screeningOptions.maxOuterIterations = 1;
      screeningOptions.maxLineSearchSteps =
        std::min(screeningOptions.maxLineSearchSteps, 12);
      std::vector<Candidate> screened;
      const int interiorMaximum =
        std::max(0, options.maximumCleanUpInteriorVertices);
      const int candidateBudget = fastInteractive ?
        std::min(seed.kind == CavityKind::CleanUpShape ? 64 : 10,
                 options.maximumCleanUpCandidatesPerCavity) :
        options.maximumCleanUpCandidatesPerCavity;
      const int perInteriorMaximum = std::max(
        1, candidateBudget /
             std::max(1, interiorMaximum + 1));
      for(int interior = 0; interior <= interiorMaximum; ++interior) {
        std::vector<Pattern> patterns;
        if(getDiskQuadrangulations(
             boundaryCount, static_cast<std::size_t>(interior), patterns) != 0 ||
           patterns.empty())
          continue;
        const std::vector<PatternConfiguration> ranked = rankPatterns(
          seed.patch, patterns, perInteriorMaximum,
          static_cast<std::size_t>(interior), &seed);
        for(const PatternConfiguration &configuration : ranked) {
          Pattern quadrangles = transformPattern(
            patterns[configuration.pattern], boundaryCount,
            configuration.rotation, configuration.reflected);
          ConnectivitySignature connectivity = quadrangles;
          for(auto &quad : connectivity) std::sort(quad.begin(), quad.end());
          std::sort(connectivity.begin(), connectivity.end());
          if((existingIsAllQuad &&
              static_cast<std::size_t>(interior) ==
                seed.patch.intVertices.size() &&
              connectivity == existingConnectivity) ||
             !triedConnectivity.insert(connectivity).second)
            continue;

          std::vector<UV> uv = boundary;
          uv.resize(boundaryCount + static_cast<std::size_t>(interior),
                    centroid);
          ++result.topologyCandidatesOptimized;
          if(interior > 0) {
            const bool untangled = fastInteractive ?
              initializeSmallQuadCavityHarmonic(
                uv, boundaryCount, quadrangles) :
              [&]() {
                const SmallCavityWinslowResult winslow =
                  optimizeSmallQuadCavityWinslow(
                    uv, boundaryCount, quadrangles, screeningOptions);
                return winslow.success && winslow.untangled;
              }();
            if(!untangled) {
              ++result.rejectedByWinslow;
              continue;
            }
          }
          std::vector<Point> xyz;
          if(!mapCandidate(face, boundaryCount,
                           seed.patch.bdrVertices.front(), uv, xyz)) {
            ++result.rejectedByWinslow;
            continue;
          }
          const SizeScore size =
            candidateSizeScore(face, uv, xyz, quadrangles, options,
                               boundaryCount);
          const bool checkSize = options.quadCleanUp ||
                                 options.enforceSizeMap ||
                                 seed.kind == CavityKind::CleanUpSize;
          const bool preservesTarget = !options.enforceSizeMap ||
            admissibleSizeChange(beforeSize, size, options);
          const bool deferSizeToOneRing = options.quadCleanUp && interior == 0;
          if(checkSize && !deferSizeToOneRing &&
             (!size.admissible || !preservesTarget)) {
            ++result.rejectedBySize;
            continue;
          }

          Candidate candidate;
          candidate.valid = true;
          candidate.uv = std::move(uv);
          candidate.xyz = std::move(xyz);
          candidate.quadrangles = std::move(quadrangles);
          candidate.objective = candidateObjective(
            candidate.quadrangles, candidate.xyz,
            &candidate.invalidElementCount);
          if((options.quadCleanUp || fastInteractive) &&
             !candidateQuadranglesAreNonConcave(
               candidate.quadrangles, candidate.uv, candidate.xyz)) {
            ++result.rejectedByQuality;
            continue;
          }
          candidate.valence = candidatePatchValence(
            seed, candidate.quadrangles,
            static_cast<std::size_t>(interior));
          candidate.sizeError = size.meanSquaredLogRatio;
          candidate.sizeEdgeCount = size.edgeCount;
          candidate.sizeViolationCount =
            size.belowMinimum + size.aboveMaximum + size.invalid;
          candidate.unchangedObjective = unchangedObjective;
          candidate.interiorAssignment.resize(
            static_cast<std::size_t>(interior), createdMarker);
          const std::size_t retained = std::min(
            candidate.interiorAssignment.size(),
            seed.patch.intVertices.size());
          for(std::size_t i = 0; i < retained; ++i)
            candidate.interiorAssignment[i] = i;

          if(fastInteractive && seed.patch.intVertices.empty() &&
             seed.patch.elements.size() == 2 && interior == 0 &&
             candidate.quadrangles.size() == 2) {
            IndexedEdge oldEdge, newEdge;
            if(existingInteriorEdge(seed, oldEdge) &&
               candidateInteriorEdge(
                 candidate.quadrangles, boundaryCount, newEdge) &&
               oldEdge != newEdge) {
              if(!edgeMidpointCadDistance(
                   face, candidate.uv[oldEdge.first],
                   candidate.uv[oldEdge.second],
                   candidate.xyz[oldEdge.first],
                   candidate.xyz[oldEdge.second],
                   candidate.referenceEdgeSwapCadDistance) ||
                 !edgeMidpointCadDistance(
                   face, candidate.uv[newEdge.first],
                   candidate.uv[newEdge.second],
                   candidate.xyz[newEdge.first],
                   candidate.xyz[newEdge.second],
                   candidate.edgeSwapCadDistance)) {
                ++result.rejectedByQuality;
                continue;
              }
              candidate.edgeSwapCadScale = std::max(
                distance(candidate.xyz[oldEdge.first],
                         candidate.xyz[oldEdge.second]),
                distance(candidate.xyz[newEdge.first],
                         candidate.xyz[newEdge.second]));
              if(!std::isfinite(candidate.edgeSwapCadScale) ||
                 !(candidate.edgeSwapCadScale > 0.)) {
                ++result.rejectedByQuality;
                continue;
              }
              candidate.hasEdgeSwapCad = true;
            }
          }

          screened.push_back(std::move(candidate));
        }
      }

      std::stable_sort(screened.begin(), screened.end(),
                       [&](const Candidate &a, const Candidate &b) {
                         if(better(a, b)) return true;
                         if(better(b, a)) return false;
                         return a.quadrangles < b.quadrangles;
                       });

      Candidate best;
      if(fastInteractive) {
        for(Candidate &candidate : screened) {
          candidate.decisionReason = decide(candidate);
          if(candidate.decisionReason == CleanUpDecisionReason::Rejected) {
            ++result.rejectedByQuality;
            continue;
          }
          best = std::move(candidate);
          break;
        }
      }
      const std::size_t refinementCount = std::min(
        screened.size(), fastInteractive ? 0 :
          static_cast<std::size_t>(
            options.maximumCleanUpWinslowCandidatesPerCavity));
      for(std::size_t i = 0; i < refinementCount; ++i) {
        Candidate candidate = std::move(screened[i]);
        if(candidate.uv.size() > boundaryCount) {
          SmallCavityWinslowOptions refinementOptions = winslowOptions;
          // The screened coordinates are already harmonic and untangled.
          refinementOptions.harmonicInitialization = false;
          const SmallCavityWinslowResult winslow =
            optimizeSmallQuadCavityWinslow(
              candidate.uv, boundaryCount, candidate.quadrangles,
              refinementOptions);
          if(!winslow.success || !winslow.untangled) {
            ++result.rejectedByWinslow;
            continue;
          }
          if(!mapCandidate(face, boundaryCount,
                           seed.patch.bdrVertices.front(), candidate.uv,
                           candidate.xyz)) {
            ++result.rejectedByWinslow;
            continue;
          }
          const SizeScore size = candidateSizeScore(
            face, candidate.uv, candidate.xyz, candidate.quadrangles,
            options, boundaryCount);
          const bool checkSize = options.quadCleanUp ||
                                 options.enforceSizeMap ||
                                 seed.kind == CavityKind::CleanUpSize;
          const bool preservesTarget = !options.enforceSizeMap ||
            admissibleSizeChange(beforeSize, size, options);
          if(checkSize && (!size.admissible || !preservesTarget)) {
            ++result.rejectedBySize;
            continue;
          }
          candidate.objective = candidateObjective(
            candidate.quadrangles, candidate.xyz,
            &candidate.invalidElementCount);
          candidate.sizeError = size.meanSquaredLogRatio;
          candidate.sizeEdgeCount = size.edgeCount;
          candidate.sizeViolationCount =
            size.belowMinimum + size.aboveMaximum + size.invalid;
        }
        else if(options.quadCleanUp &&
                !smoothZeroInteriorCandidate(face, seed, candidate, options,
                                             result)) {
          continue;
        }
        if((options.quadCleanUp || fastInteractive) &&
           !candidateQuadranglesAreNonConcave(
             candidate.quadrangles, candidate.uv, candidate.xyz)) {
          ++result.rejectedByQuality;
          continue;
        }
        if(options.quadCleanUp) {
          const SpecificationObjective candidateComparison =
            comparisonObjective(candidate);
          const SpecificationObjective referenceComparison =
            comparisonReferenceObjective(seed, candidate);
          if(candidate.hasSmoothedReference) {
            candidate.referenceGeometry =
              candidate.smoothedReferenceGeometry;
          }
          else if(candidateComparison.absoluteBadElementCount ==
                    referenceComparison.absoluteBadElementCount &&
                  candidate.objective.absoluteBadElementCount == 0) {
            if(!referenceGeometryEvaluated) {
              referenceGeometry = existingGeometryDeviation(
                face, seed.patch.elements);
              referenceGeometryEvaluated = true;
            }
            candidate.geometry = candidateGeometryDeviation(
              face, candidate.uv, candidate.xyz, candidate.quadrangles);
            candidate.referenceGeometry = referenceGeometry;
          }
        }
        candidate.decisionReason = decide(candidate);
        if(candidate.decisionReason == CleanUpDecisionReason::Rejected) {
          ++result.rejectedByQuality;
          continue;
        }
        if(!best.valid || better(candidate, best))
          best = std::move(candidate);
      }
      if(!best.valid) return false;
      MVertex *cadProtectedA = nullptr;
      MVertex *cadProtectedB = nullptr;
      if(fastInteractive && best.hasEdgeSwapCad &&
         face->geomType() != GEntity::Plane) {
        IndexedEdge newEdge;
        if(!candidateInteriorEdge(
             best.quadrangles, boundaryCount, newEdge))
          return false;
        const std::vector<MVertex *> &vertices =
          seed.patch.bdrVertices.front();
        cadProtectedA = vertices[newEdge.first];
        cadProtectedB = vertices[newEdge.second];
      }
      const bool isTwoQuadSwitch =
        (options.quadCleanUp && seed.patch.intVertices.empty() &&
         best.interiorAssignment.empty() && seed.patch.elements.size() == 2 &&
         best.quadrangles.size() == 2) ||
        (fastInteractive && best.hasEdgeSwapCad);
      std::vector<MVertex *> interior;
      if(!executeFlexibleCandidate(face, seed, best, interior,
                                   nullptr, topology))
        return false;
      if(cadProtectedA) fastCadProtectedVertices.insert(cadProtectedA);
      if(cadProtectedB) fastCadProtectedVertices.insert(cadProtectedB);
      if(options.quadCleanUp) {
        recordAcceptedCleanUpDecision(result, best.decisionReason);
        applyCandidateSmoothing(best);
      }
      else if(fastInteractive) {
        std::vector<MVertex *> localVertices =
          seed.patch.bdrVertices.front();
        localVertices.insert(localVertices.end(), interior.begin(),
                             interior.end());
        result.acceptedFinalSmoothingCavities += smoothLocalVertexStars(
          face, localVertices, options, *topology,
          &fastCadProtectedVertices);
      }
      else {
        smoothTopologyNeighborhood(face, interior, options, topology);
      }
      if(isTwoQuadSwitch) {
        ++result.acceptedEdgeSwaps;
        ++result.acceptedCleanUpEdgeSwaps;
      }
      return true;
    }

    bool vertexParameter(GFace *face, MVertex *vertex, UV &parameter)
    {
      if(!face || !vertex) return false;
      SPoint2 persistent;
      if(face->geomType() == GEntity::DiscreteSurface) {
        if(!persistentFaceParameter(face, vertex, persistent)) return false;
        parameter = {persistent.x(), persistent.y()};
        return true;
      }
      double u = 0., v = 0.;
      if(vertex->onWhat() == face && vertex->getParameter(0, u) &&
         vertex->getParameter(1, v) && std::isfinite(u) &&
         std::isfinite(v)) {
        parameter = {u, v};
        return true;
      }
      SPoint2 uv;
      if(!reparamMeshVertexOnFace(vertex, face, uv, true) ||
         !std::isfinite(uv.x()) || !std::isfinite(uv.y()))
        return false;
      parameter = {uv.x(), uv.y()};
      return true;
    }

    struct MixedTriangleQuadSwapSeed {
      GFaceMeshPatch core;
      MTriangle *triangle = nullptr;
      MQuadrangle *quadrangle = nullptr;
      SpecificationObjective objective;
    };

    struct MixedTriangleQuadSwapCandidate {
      bool valid = false;
      std::array<MVertex *, 3> triangle = {nullptr, nullptr, nullptr};
      std::array<MVertex *, 4> quadrangle = {
        nullptr, nullptr, nullptr, nullptr};
      SpecificationObjective objective;
      FastGlobalQuality globalQuality;
      GeometryDeviation geometry;
      GeometryDeviation referenceGeometry;
      double sizeError = std::numeric_limits<double>::infinity();
      std::vector<Candidate::VertexGeometry> smoothedVertices;
      CleanUpDecisionReason decisionReason =
        CleanUpDecisionReason::Rejected;
    };

    std::vector<MixedTriangleQuadSwapSeed> collectMixedTriangleQuadSwaps(
      GFace *face)
    {
      const std::vector<MElement *> elements = surfaceElements(face);
      const FaceHalfEdgeTopology topology(elements);
      if(!topology.manifold()) return {};
      std::vector<MixedTriangleQuadSwapSeed> seeds;
      for(const auto &entry : topology.edges()) {
        if(entry.second.size() != 2) continue;
        MTriangle *triangle = nullptr;
        MQuadrangle *quadrangle = nullptr;
        for(MElement *element : entry.second) {
          if(MTriangle *candidate = dynamic_cast<MTriangle *>(element))
            triangle = candidate;
          else if(MQuadrangle *candidate =
                    dynamic_cast<MQuadrangle *>(element))
            quadrangle = candidate;
        }
        if(!triangle || !quadrangle) continue;
        MixedTriangleQuadSwapSeed seed;
        seed.triangle = triangle;
        seed.quadrangle = quadrangle;
        if(!canonicalPatchFromElements(face, entry.second, seed.core) ||
           seed.core.bdrVertices.size() != 1 ||
           seed.core.bdrVertices.front().size() != 5 ||
           !seed.core.intVertices.empty() ||
           !seed.core.embVertices.empty())
          continue;
        seed.objective = specificationObjective(seed.core.elements);
        seeds.push_back(std::move(seed));
      }
      std::sort(seeds.begin(), seeds.end(),
                [](const MixedTriangleQuadSwapSeed &a,
                   const MixedTriangleQuadSwapSeed &b) {
                  const double ap = objectivePriority(a.objective);
                  const double bp = objectivePriority(b.objective);
                  if(ap != bp) return ap > bp;
                  const std::size_t at = a.triangle->getNum();
                  const std::size_t bt = b.triangle->getNum();
                  if(at != bt) return at < bt;
                  return a.quadrangle->getNum() < b.quadrangle->getNum();
                });
      return seeds;
    }

    bool tryMixedTriangleQuadSwap(
      GFace *face, const MixedTriangleQuadSwapSeed &seed,
      const SmallCavityOptimizerOptions &options,
      SmallCavityOptimizerResult &result, CleanUpDecisionPhase phase)
    {
      if(!face || !seed.triangle || !seed.quadrangle ||
         seed.core.bdrVertices.size() != 1 ||
         seed.core.bdrVertices.front().size() != 5 ||
         !seed.core.intVertices.empty())
        return false;
      if(phase != CleanUpDecisionPhase::FewerUnacceptableElements &&
         phase != CleanUpDecisionPhase::BetterGeometry &&
         phase != CleanUpDecisionPhase::OtherImprovement &&
         phase != CleanUpDecisionPhase::Any)
        return false;
      const bool fastInteractive = useFastInteractiveCleanUp(options);

      const std::vector<MElement *> faceElements = surfaceElements(face);
      const FaceHalfEdgeTopology topology(faceElements);
      if(!topology.manifold()) return false;
      const std::set<MVertex *> protectedVertices =
        protectedFaceVertices(face);
      const std::vector<MVertex *> &pentagon =
        seed.core.bdrVertices.front();

      // Full QuadCleanUp couples the swap to a local Winslow solve, so its
      // transaction contains the complete one-ring of every movable core
      // vertex. Fast moves no vertex while screening the four diagonals: its
      // exact affected support is only the T+Q core, and the requested final
      // Winslow sweeps are validated later as separate one-ring actions.
      std::set<MElement *> selected(seed.core.elements.begin(),
                                    seed.core.elements.end());
      if(!fastInteractive)
        for(MVertex *vertex : pentagon) {
          if(!vertex || vertex->onWhat() != face ||
             protectedVertices.find(vertex) != protectedVertices.end())
            continue;
          const std::vector<MElement *> incident =
            topology.incidentElements(vertex);
          if(incident.empty()) return false;
          selected.insert(incident.begin(), incident.end());
        }
      std::set<MElement *> outside = selected;
      outside.erase(seed.triangle);
      outside.erase(seed.quadrangle);
      std::vector<MElement *> beforeElements(selected.begin(),
                                             selected.end());
      GFaceMeshPatch beforePatch;
      beforePatch.gf = face;
      beforePatch.elements = beforeElements;
      const SpecificationObjective referenceObjective =
        specificationObjective(beforeElements);
      const SizeScore beforeSize = existingSizeScore(
        beforePatch, options, false);
      const std::size_t beforeSizeViolations =
        beforeSize.belowMinimum + beforeSize.aboveMaximum +
        beforeSize.invalid;
      GeometryDeviation referenceGeometry;
      if(!fastInteractive)
        referenceGeometry = existingGeometryDeviation(face, beforeElements);

      // A mixed swap changes the quad degree of pentagon vertices even though
      // it preserves the numbers of triangles and quadrangles. Keep those
      // changed vertex contributions in the same additive transaction as the
      // affected element support below.
      auto mixedValence = [&](const FaceHalfEdgeTopology &candidateTopology) {
        ValenceObjective valence;
        for(MVertex *vertex : pentagon)
          addValence(valence, candidateTopology.quadDegree(vertex),
                     idealQuadDegree(face, vertex, candidateTopology),
                     vertex->onWhat() == face);
        return valence;
      };
      const ValenceObjective referenceValence = mixedValence(topology);
      const FastGlobalQuality referenceGlobalQuality = fastGlobalQuality(
        referenceObjective, referenceValence,
        referenceObjective.invalidElementCount, beforeSizeViolations,
        beforeSize.meanSquaredLogRatio, beforeSize.edgeCount, 0.);

      std::set<MVertex *> oldTriangleVertices;
      std::set<MVertex *> oldQuadrangleVertices;
      for(int i = 0; i < 3; ++i)
        oldTriangleVertices.insert(seed.triangle->getVertex(i));
      for(int i = 0; i < 4; ++i)
        oldQuadrangleVertices.insert(seed.quadrangle->getVertex(i));
      std::array<MVertex *, 2> oldDiagonalVertices = {nullptr, nullptr};
      std::size_t oldDiagonalSize = 0;
      for(MVertex *vertex : oldTriangleVertices)
        if(oldQuadrangleVertices.find(vertex) !=
           oldQuadrangleVertices.end()) {
          if(oldDiagonalSize >= oldDiagonalVertices.size()) return false;
          oldDiagonalVertices[oldDiagonalSize++] = vertex;
        }
      if(oldDiagonalSize != oldDiagonalVertices.size()) return false;

      MixedTriangleQuadSwapCandidate best;
      for(std::size_t diagonal = 0; diagonal < pentagon.size();
          ++diagonal) {
        // Every diagonal of a pentagon defines exactly one triangle and one
        // quadrangle. The existing diagonal is skipped, leaving the four
        // genuine mixed swaps.
        const std::array<MVertex *, 3> proposedTriangle = {
          pentagon[diagonal], pentagon[(diagonal + 1) % 5],
          pentagon[(diagonal + 2) % 5]};
        const std::array<MVertex *, 4> proposedQuadrangle = {
          pentagon[diagonal], pentagon[(diagonal + 2) % 5],
          pentagon[(diagonal + 3) % 5], pentagon[(diagonal + 4) % 5]};
        if(std::set<MVertex *>(proposedTriangle.begin(),
                               proposedTriangle.end()) ==
             oldTriangleVertices &&
           std::set<MVertex *>(proposedQuadrangle.begin(),
                               proposedQuadrangle.end()) ==
             oldQuadrangleVertices)
          continue;

        std::unique_ptr<MTriangle> temporaryTriangle(new MTriangle(
          proposedTriangle[0], proposedTriangle[1], proposedTriangle[2]));
        std::unique_ptr<MQuadrangle> temporaryQuadrangle(new MQuadrangle(
          proposedQuadrangle[0], proposedQuadrangle[1],
          proposedQuadrangle[2], proposedQuadrangle[3]));
        std::vector<MElement *> replacement = {
          temporaryTriangle.get(), temporaryQuadrangle.get()};
        if(!orientElementsAccordingToBoundarySegment(
             pentagon[0], pentagon[1], replacement))
          continue;
        FaceHalfEdgeTopology validatedTopology = topology;
        if(!validatedTopology.replace(seed.core.elements, replacement))
          continue;
        const ValenceObjective candidateValence =
          mixedValence(validatedTopology);

        std::vector<MElement *> afterElements(outside.begin(), outside.end());
        afterElements.insert(afterElements.end(), replacement.begin(),
                             replacement.end());
        GFaceMeshPatch afterPatch;
        if(!canonicalPatchFromElements(face, afterElements, afterPatch) ||
           afterPatch.bdrVertices.size() != 1 ||
           afterPatch.bdrVertices.front().size() < 3 ||
           !afterPatch.embVertices.empty())
          continue;
        bool completeMovableStars = true;
        for(MVertex *vertex : afterPatch.intVertices) {
          if(!vertex || vertex->onWhat() != face ||
             protectedVertices.find(vertex) != protectedVertices.end())
            continue;
          const std::vector<MElement *> incident =
            topology.incidentElements(vertex);
          if(incident.empty() ||
             std::any_of(incident.begin(), incident.end(),
                         [&](MElement *element) {
                           return selected.find(element) == selected.end();
                         })) {
            completeMovableStars = false;
            break;
          }
        }
        if(!completeMovableStars) continue;
        std::vector<UV> initial;
        if(!currentParametrization(afterPatch, initial)) continue;
        const std::size_t boundaryCount =
          afterPatch.bdrVertices.front().size();
        std::vector<MVertex *> localVertices =
          afterPatch.bdrVertices.front();
        localVertices.insert(localVertices.end(),
                             afterPatch.intVertices.begin(),
                             afterPatch.intVertices.end());
        if(localVertices.size() != initial.size()) continue;
        std::unordered_map<MVertex *, std::size_t> localIndex;
        for(std::size_t i = 0; i < localVertices.size(); ++i)
          if(!localVertices[i] ||
             !localIndex.emplace(localVertices[i], i).second)
            return false;
        const auto oldDiagonalAFound =
          localIndex.find(oldDiagonalVertices[0]);
        const auto oldDiagonalBFound =
          localIndex.find(oldDiagonalVertices[1]);
        if(oldDiagonalAFound == localIndex.end() ||
           oldDiagonalBFound == localIndex.end())
          continue;
        const std::array<std::size_t, 2> oldDiagonal = {
          oldDiagonalAFound->second, oldDiagonalBFound->second};

        std::vector<std::array<std::size_t, 3> > triangles;
        Pattern quadrangles;
        std::array<std::size_t, 3> coreTriangle;
        std::array<std::size_t, 4> coreQuadrangle;
        bool validConnectivity = true;
        for(MElement *element : afterElements) {
          const std::size_t count = element->getNumPrimaryVertices();
          if(count == 3) {
            std::array<std::size_t, 3> triangle;
            for(std::size_t i = 0; i < 3; ++i) {
              const auto found = localIndex.find(
                element->getVertex(static_cast<int>(i)));
              if(found == localIndex.end()) {
                validConnectivity = false;
                break;
              }
              triangle[i] = found->second;
            }
            if(validConnectivity) triangles.push_back(triangle);
          }
          else if(count == 4) {
            std::array<std::size_t, 4> quadrangle;
            for(std::size_t i = 0; i < 4; ++i) {
              const auto found = localIndex.find(
                element->getVertex(static_cast<int>(i)));
              if(found == localIndex.end()) {
                validConnectivity = false;
                break;
              }
              quadrangle[i] = found->second;
            }
            if(validConnectivity) quadrangles.push_back(quadrangle);
          }
          else
            validConnectivity = false;
          if(!validConnectivity) break;
        }
        if(!validConnectivity || triangles.empty() || quadrangles.empty())
          continue;
        for(std::size_t i = 0; i < 3; ++i)
          coreTriangle[i] = localIndex[temporaryTriangle->getVertex(
            static_cast<int>(i))];
        for(std::size_t i = 0; i < 4; ++i)
          coreQuadrangle[i] = localIndex[temporaryQuadrangle->getVertex(
            static_cast<int>(i))];
        std::array<std::size_t, 2> newDiagonal = {0, 0};
        std::size_t newDiagonalSize = 0;
        for(const std::size_t triangleVertex : coreTriangle)
          if(std::find(coreQuadrangle.begin(), coreQuadrangle.end(),
                       triangleVertex) != coreQuadrangle.end()) {
            if(newDiagonalSize >= newDiagonal.size()) {
              newDiagonalSize = newDiagonal.size() + 1;
              break;
            }
            newDiagonal[newDiagonalSize++] = triangleVertex;
          }
        if(newDiagonalSize != newDiagonal.size()) continue;

        std::vector<bool> fixed(localVertices.size(), false);
        for(std::size_t i = 0; i < boundaryCount; ++i) fixed[i] = true;
        for(std::size_t i = boundaryCount; i < localVertices.size(); ++i) {
          MVertex *vertex = localVertices[i];
          fixed[i] = vertex->onWhat() != face ||
            protectedVertices.find(vertex) != protectedVertices.end();
        }
        double twiceBoundaryArea = 0.;
        for(std::size_t i = 0; i < boundaryCount; ++i) {
          const UV &a = initial[i];
          const UV &b = initial[(i + 1) % boundaryCount];
          twiceBoundaryArea += a[0] * b[1] - a[1] * b[0];
        }
        if(!std::isfinite(twiceBoundaryArea) ||
           std::abs(twiceBoundaryArea) <= 1.e-14)
          continue;
        const double orientation = twiceBoundaryArea > 0. ? 1. : -1.;

        std::vector<UV> target = initial;
        const bool hasMovable =
          std::find(fixed.begin(), fixed.end(), false) != fixed.end();
        bool useSmoothedTrial = false;
        // Fast screens the four connectivities without moving a vertex. Its
        // requested final Winslow sweeps then relax the accepted topology as a
        // separate globally monotone action. Full QuadCleanUp retains the
        // coupled topology-and-Winslow transaction.
        if(hasMovable && !fastInteractive) {
          SmallCavityWinslowOptions winslowOptions = options.winslow;
          winslowOptions.harmonicInitialization = true;
          SmallCavityWinslowResult winslow;
          bool winslowThrew = false;
          try {
            winslow = optimizeLocalSurfacePatchWinslow(
              target, fixed, triangles, quadrangles, orientation,
              winslowOptions);
          }
          catch(const std::exception &) {
            winslowThrew = true;
          }
          if(winslow.success && winslow.untangled)
            useSmoothedTrial = true;
          else if(winslowThrew || !winslow.success || !winslow.untangled)
            ++result.rejectedByWinslow;
        }

        ++result.topologyCandidatesOptimized;
        constexpr std::size_t smoothingLineSearchSteps = 32;
        // Include scale=0: a valid connectivity improvement must not depend on
        // Winslow moving a vertex, and remains available if that solve fails.
        const std::size_t trialCount = useSmoothedTrial ?
          smoothingLineSearchSteps + 1 : 1;
        for(std::size_t step = 0; step < trialCount; ++step) {
          const double scale = useSmoothedTrial ?
            1. - static_cast<double>(step) /
                   static_cast<double>(smoothingLineSearchSteps) : 0.;
          std::vector<UV> trial = initial;
          for(std::size_t i = 0; i < trial.size(); ++i) {
            if(fixed[i]) continue;
            trial[i][0] += scale * (target[i][0] - initial[i][0]);
            trial[i][1] += scale * (target[i][1] - initial[i][1]);
          }
          std::vector<Point> trialXyz(localVertices.size());
          bool mapped = true;
          for(std::size_t i = 0; i < localVertices.size(); ++i) {
            if(fixed[i]) {
              trialXyz[i] = {localVertices[i]->x(), localVertices[i]->y(),
                             localVertices[i]->z()};
              continue;
            }
            const GPoint point = face->point(
              SPoint2(trial[i][0], trial[i][1]));
            if(!point.succeeded() || !std::isfinite(point.x()) ||
               !std::isfinite(point.y()) || !std::isfinite(point.z())) {
              mapped = false;
              break;
            }
            trialXyz[i] = {point.x(), point.y(), point.z()};
          }
          if(!mapped) continue;

          const SizeScore afterSize = surfacePatchSizeScore(
            face, trial, trialXyz, triangles, quadrangles, fixed, options);
          // A newly inserted diagonal is mutable topology even when both of
          // its endpoints are CAD-fixed. surfacePatchSizeScore deliberately
          // exempts fixed/fixed outer edges, so audit this one new edge
          // explicitly. The other four pentagon edges predate the swap and
          // must retain the normal immutable-boundary exemption.
          SizeScore diagonalSize;
          diagonalSize.admissible = true;
          double diagonalSquaredLogError = 0.;
          const std::size_t diagonalA = newDiagonal[0];
          const std::size_t diagonalB = newDiagonal[1];
          const UV diagonalMidpointUv = {
            .5 * (trial[diagonalA][0] + trial[diagonalB][0]),
            .5 * (trial[diagonalA][1] + trial[diagonalB][1])};
          const Point diagonalMidpointXyz = {
            .5 * (trialXyz[diagonalA][0] + trialXyz[diagonalB][0]),
            .5 * (trialXyz[diagonalA][1] + trialXyz[diagonalB][1]),
            .5 * (trialXyz[diagonalA][2] + trialXyz[diagonalB][2])};
          accumulateSizeEdge(
            diagonalSize, diagonalSquaredLogError,
            edgeLengthCriteria(
              face, diagonalMidpointUv, diagonalMidpointXyz, options),
            distance(trialXyz[diagonalA], trialXyz[diagonalB]), true);
          if((options.quadCleanUp &&
              (!afterSize.admissible || !diagonalSize.admissible)) ||
             (options.enforceSizeMap &&
              !admissibleSizeChange(beforeSize, afterSize, options)))
            continue;
          if(!candidateQuadranglesAreNonConcave(
               quadrangles, trial, trialXyz))
            continue;
          bool validTriangles = true;
          for(const auto &triangle : triangles) {
            const UV &a = trial[triangle[0]];
            const UV &b = trial[triangle[1]];
            const UV &c = trial[triangle[2]];
            const double signedArea =
              (b[0] - a[0]) * (c[1] - a[1]) -
              (b[1] - a[1]) * (c[0] - a[0]);
            std::vector<Point> points = {
              trialXyz[triangle[0]], trialXyz[triangle[1]],
              trialXyz[triangle[2]]};
            if(!std::isfinite(signedArea) ||
               orientation * signedArea <= 1.e-14 ||
               !evaluateElementQuality(
                  SurfaceElementKind::Triangle, points).topologicallyValid) {
              validTriangles = false;
              break;
            }
          }
          if(!validTriangles) continue;

          const SpecificationObjective objective =
            candidateMixedObjective(triangles, quadrangles, trialXyz);
          const std::size_t afterSizeViolations =
            afterSize.belowMinimum + afterSize.aboveMaximum +
            afterSize.invalid;
          GeometryDeviation geometry;
          if(!fastInteractive && objective.absoluteBadElementCount == 0 &&
             objective.absoluteBadElementCount ==
               referenceObjective.absoluteBadElementCount)
            geometry = candidateMixedGeometryDeviation(
              face, trial, trialXyz, triangles, quadrangles);
          const bool rawSwap = scale == 0.;
          bool rawCadValid = false;
          double normalizedCadChange = 0.;
          if(rawSwap) {
            double oldCadDistance = 0., newCadDistance = 0.;
            if(edgeMidpointCadDistance(
                 face, trial[oldDiagonal[0]], trial[oldDiagonal[1]],
                 trialXyz[oldDiagonal[0]], trialXyz[oldDiagonal[1]],
                 oldCadDistance) &&
               edgeMidpointCadDistance(
                 face, trial[newDiagonal[0]], trial[newDiagonal[1]],
                 trialXyz[newDiagonal[0]], trialXyz[newDiagonal[1]],
                 newCadDistance)) {
              const UV oldMidpointUv = {
                .5 * (trial[oldDiagonal[0]][0] +
                      trial[oldDiagonal[1]][0]),
                .5 * (trial[oldDiagonal[0]][1] +
                      trial[oldDiagonal[1]][1])};
              const UV newMidpointUv = {
                .5 * (trial[newDiagonal[0]][0] +
                      trial[newDiagonal[1]][0]),
                .5 * (trial[newDiagonal[0]][1] +
                      trial[newDiagonal[1]][1])};
              const Point oldMidpointXyz = {
                .5 * (trialXyz[oldDiagonal[0]][0] +
                      trialXyz[oldDiagonal[1]][0]),
                .5 * (trialXyz[oldDiagonal[0]][1] +
                      trialXyz[oldDiagonal[1]][1]),
                .5 * (trialXyz[oldDiagonal[0]][2] +
                      trialXyz[oldDiagonal[1]][2])};
              const Point newMidpointXyz = {
                .5 * (trialXyz[newDiagonal[0]][0] +
                      trialXyz[newDiagonal[1]][0]),
                .5 * (trialXyz[newDiagonal[0]][1] +
                      trialXyz[newDiagonal[1]][1]),
                .5 * (trialXyz[newDiagonal[0]][2] +
                      trialXyz[newDiagonal[1]][2])};
              const EdgeLengthCriteria oldCriteria = edgeLengthCriteria(
                face, oldMidpointUv, oldMidpointXyz, options);
              const EdgeLengthCriteria newCriteria = edgeLengthCriteria(
                face, newMidpointUv, newMidpointXyz, options);
              if(validEdgeLengthCriteria(oldCriteria) &&
                 validEdgeLengthCriteria(newCriteria)) {
                normalizedCadChange =
                  std::pow(newCadDistance / newCriteria.target, 2) -
                  std::pow(oldCadDistance / oldCriteria.target, 2);
                rawCadValid = std::isfinite(normalizedCadChange);
              }
            }
          }
          else if(geometry.valid && referenceGeometry.valid) {
            const double target = options.targetSize > 0. ?
              options.targetSize :
              std::sqrt(std::max(
                referenceGeometry.sampledArea /
                  static_cast<double>(std::max<std::size_t>(
                    1, referenceGeometry.elementCount)),
                std::numeric_limits<double>::min()));
            const double normalization = std::max(
              std::max(referenceGeometry.sampledArea,
                       geometry.sampledArea) *
                target * target,
              std::numeric_limits<double>::min());
            normalizedCadChange =
              (geometry.squaredDistanceIntegral -
               referenceGeometry.squaredDistanceIntegral) /
              normalization;
          }
          const FastGlobalQuality globalQuality = fastGlobalQuality(
            objective, candidateValence, objective.invalidElementCount,
            afterSizeViolations, afterSize.meanSquaredLogRatio,
            afterSize.edgeCount, normalizedCadChange);
          CleanUpDecisionReason decision = cleanUpDecision(
            objective, referenceObjective, geometry, referenceGeometry,
            objective.absoluteBadElementCount == 0, candidateValence,
            referenceValence, afterSizeViolations, beforeSizeViolations,
            afterSize.meanSquaredLogRatio, beforeSize.meanSquaredLogRatio,
            options.objectiveRelativeTolerance);

          // cleanUpDecision intentionally reserves a CAD tie for published
          // connectivity actions. A pentagon diagonal is also a finite
          // Cleanup action: accept a pure shape/size improvement when the
          // complete affected support strictly lowers the additive global
          // potential. Absolute specifications and hard size bounds remain
          // one-sided vetoes. For a raw swap, the only changed CAD chord is
          // the diagonal, so its midpoint departure enters the same additive
          // compromise; a simultaneous Winslow move uses the full patch CAD
          // integral. Both are state potentials, so overlapping swaps cannot
          // recreate an earlier state.
          const bool fullGeometryTie = !rawSwap && geometry.valid &&
            referenceGeometry.valid &&
            compareGeometryDeviation(
              geometry, referenceGeometry,
              options.objectiveRelativeTolerance) == 0 &&
            geometryDoesNotRegressBeyondRoundoff(
              geometry, referenceGeometry);
          if(decision == CleanUpDecisionReason::Rejected &&
             objective.absoluteBadElementCount == 0 &&
             referenceObjective.absoluteBadElementCount == 0 &&
             noWorseAbsoluteSpecifications(
               objective, referenceObjective,
               options.objectiveRelativeTolerance) &&
             afterSizeViolations <= beforeSizeViolations &&
             ((rawSwap && rawCadValid) || fullGeometryTie) &&
             improvesFastGlobalQuality(
               globalQuality, referenceGlobalQuality))
            decision = CleanUpDecisionReason::OtherImprovement;

          // Every accepted mixed swap, including the primary bad-count and
          // CAD branches, must lower the same affected-support potential.
          if((rawSwap && !rawCadValid) ||
             !improvesFastGlobalQuality(
               globalQuality, referenceGlobalQuality) ||
             !decisionAllowed(decision, phase))
            continue;

          bool better = !best.valid;
          if(best.valid && improvesFastGlobalQuality(
                           globalQuality, best.globalQuality))
            better = true;
          else if(best.valid && improvesFastGlobalQuality(
                                best.globalQuality, globalQuality))
            better = false;
          else if(best.valid && decision ==
                                  CleanUpDecisionReason::BetterGeometry &&
                  best.decisionReason ==
                    CleanUpDecisionReason::BetterGeometry) {
            const double change = geometry.squaredDistanceIntegral -
                                  referenceGeometry.squaredDistanceIntegral;
            const double bestChange =
              best.geometry.squaredDistanceIntegral -
              best.referenceGeometry.squaredDistanceIntegral;
            const double tolerance = std::max(
              1.e-20, std::max(options.objectiveRelativeTolerance, 1.e-8) *
                std::max({std::abs(change), std::abs(bestChange), 1.e-20}));
            better = change + tolerance < bestChange;
          }
          else if(best.valid)
            better = objectivePriority(objective) <
                     objectivePriority(best.objective);
          if(!better) continue;

          best.valid = true;
          for(std::size_t i = 0; i < 3; ++i)
            best.triangle[i] = temporaryTriangle->getVertex(
              static_cast<int>(i));
          for(std::size_t i = 0; i < 4; ++i)
            best.quadrangle[i] = temporaryQuadrangle->getVertex(
              static_cast<int>(i));
          best.objective = objective;
          best.globalQuality = globalQuality;
          best.geometry = geometry;
          best.referenceGeometry = referenceGeometry;
          best.sizeError = afterSize.meanSquaredLogRatio;
          best.decisionReason = decision;
          best.smoothedVertices.clear();
          for(std::size_t i = 0; i < localVertices.size(); ++i)
            if(!fixed[i])
              best.smoothedVertices.push_back(
                {localVertices[i], trial[i], trialXyz[i]});
        }
      }
      if(!best.valid) {
        ++result.rejectedByQuality;
        return false;
      }
      if(touchesBoundaryLayerElementData(face, seed.core.elements))
        return false;

      std::vector<MElement *> replacement = {
        new MTriangle(best.triangle[0], best.triangle[1], best.triangle[2]),
        new MQuadrangle(best.quadrangle[0], best.quadrangle[1],
                        best.quadrangle[2], best.quadrangle[3])};
      replacement[0]->setPartition(seed.triangle->getPartition());
      replacement[1]->setPartition(seed.quadrangle->getPartition());
      if(!orientElementsAccordingToBoundarySegment(
           pentagon[0], pentagon[1], replacement)) {
        for(MElement *element : replacement) delete element;
        return false;
      }
      FaceHalfEdgeTopology committedTopology = topology;
      if(!committedTopology.replace(seed.core.elements, replacement)) {
        for(MElement *element : replacement) delete element;
        return false;
      }
      GFaceMeshDiff diff;
      diff.gf = face;
      diff.before = seed.core;
      diff.after.gf = face;
      diff.after.bdrVertices = seed.core.bdrVertices;
      diff.after.elements = std::move(replacement);
      if(!diff.execute(true)) return false;
      for(const Candidate::VertexGeometry &geometry :
          best.smoothedVertices) {
        geometry.vertex->setXYZ(geometry.xyz[0], geometry.xyz[1],
                                geometry.xyz[2]);
        geometry.vertex->setParameter(0, geometry.uv[0]);
        geometry.vertex->setParameter(1, geometry.uv[1]);
      }
      recordAcceptedCleanUpDecision(result, best.decisionReason);
      return true;
    }

    bool collectBoundaryLoops(GFace *face,
                              const FaceHalfEdgeTopology &topology,
                              std::vector<BoundaryLoop> &loops)
    {
      std::map<MVertex *, std::vector<MVertex *> > adjacency;
      for(const auto &entry : topology.edges()) {
        if(entry.second.size() != 1) continue;
        adjacency[entry.first.first].push_back(entry.first.second);
        adjacency[entry.first.second].push_back(entry.first.first);
      }
      if(adjacency.empty()) return true;
      for(const auto &entry : adjacency)
        if(entry.second.size() != 2) return false;

      std::set<MVertex *> unseen;
      for(const auto &entry : adjacency) unseen.insert(entry.first);
      loops.clear();
      while(!unseen.empty()) {
        MVertex *start = *std::min_element(
          unseen.begin(), unseen.end(), [](MVertex *a, MVertex *b) {
            return a->getNum() < b->getNum();
          });
        BoundaryLoop loop;
        MVertex *previous = nullptr;
        MVertex *current = start;
        do {
          if(!unseen.erase(current) && current != start) return false;
          loop.vertices.push_back(current);
          const std::vector<MVertex *> &neighbors = adjacency[current];
          MVertex *next = neighbors[0] == previous ? neighbors[1] :
                                                    neighbors[0];
          if(previous == nullptr && neighbors[1]->getNum() < next->getNum())
            next = neighbors[1];
          previous = current;
          current = next;
          if(loop.vertices.size() > adjacency.size()) return false;
        } while(current != start);
        if(loop.vertices.size() < 3) return false;
        for(std::size_t i = 0; i < loop.vertices.size(); ++i) {
          MVertex *a = loop.vertices[i];
          MVertex *b = loop.vertices[(i + 1) % loop.vertices.size()];
          loop.perimeter += std::sqrt(
            std::pow(a->x() - b->x(), 2) +
            std::pow(a->y() - b->y(), 2) +
            std::pow(a->z() - b->z(), 2));
        }
        loops.push_back(std::move(loop));
      }
      std::sort(loops.begin(), loops.end(),
                [](const BoundaryLoop &a, const BoundaryLoop &b) {
                  return a.perimeter > b.perimeter;
                });
      return true;
    }

    double parametricElementArea(
      MElement *element,
      const std::unordered_map<MVertex *, UV> &parameters)
    {
      if(!element) return 0.;
      const std::size_t count = element->getNumPrimaryVertices();
      if(count != 3 && count != 4) return 0.;
      double twiceArea = 0.;
      for(std::size_t i = 0; i < count; ++i) {
        const auto a = parameters.find(element->getVertex(static_cast<int>(i)));
        const auto b = parameters.find(
          element->getVertex(static_cast<int>((i + 1) % count)));
        if(a == parameters.end() || b == parameters.end()) return 0.;
        twiceArea += a->second[0] * b->second[1] -
                     a->second[1] * b->second[0];
      }
      return .5 * twiceArea;
    }

    bool orientLoopWithDomainOnLeft(
      GFace *face, std::vector<MVertex *> &loop,
      const std::map<Edge, std::vector<MElement *> > &edgeElements,
      std::unordered_map<MVertex *, UV> &parameters)
    {
      auto parameter = [&](MVertex *vertex, UV &uv) {
        const auto found = parameters.find(vertex);
        if(found != parameters.end()) {
          uv = found->second;
          return true;
        }
        if(!vertexParameter(face, vertex, uv)) return false;
        parameters[vertex] = uv;
        return true;
      };
      double side = 0.;
      for(std::size_t i = 0; i < loop.size(); ++i) {
        MVertex *a = loop[i];
        MVertex *b = loop[(i + 1) % loop.size()];
        const auto found = edgeElements.find(canonicalEdge(a, b));
        if(found == edgeElements.end() || found->second.size() != 1)
          return false;
        UV auv, buv;
        if(!parameter(a, auv) || !parameter(b, buv)) return false;
        UV centroid = {0., 0.};
        const std::size_t count =
          found->second.front()->getNumPrimaryVertices();
        for(std::size_t k = 0; k < count; ++k) {
          UV uv;
          if(!parameter(found->second.front()->getVertex(
                          static_cast<int>(k)), uv))
            return false;
          centroid[0] += uv[0];
          centroid[1] += uv[1];
        }
        centroid[0] /= static_cast<double>(count);
        centroid[1] /= static_cast<double>(count);
        side += (buv[0] - auv[0]) *
                  (centroid[1] - .5 * (auv[1] + buv[1])) -
                (buv[1] - auv[1]) *
                  (centroid[0] - .5 * (auv[0] + buv[0]));
      }
      if(!std::isfinite(side) || std::abs(side) <= 1.e-14) return false;
      if(side < 0.) std::reverse(loop.begin(), loop.end());
      return true;
    }

    // A pillow is a complete quadrilateral ring: every boundary edge owns a
    // distinct quad, every boundary vertex is incident only to the two ring
    // quads and all radial/inner edges close consistently. This purely
    // topological predicate survives MSH serialization and makes pillowing
    // idempotent without relying on transient vertex flags.
    bool hasCompletePillowLayer(
      const std::vector<MVertex *> &loop,
      const FaceHalfEdgeTopology &topology,
      const std::map<Edge, std::vector<MElement *> > &edgeElements)
    {
      if(loop.size() < 3) return false;
      const std::set<MVertex *> boundaryVertices(loop.begin(), loop.end());
      std::set<MElement *> ringElements;
      std::map<MVertex *, MVertex *> inward;
      auto setInward = [&](MVertex *boundary, MVertex *inner) {
        if(!boundary || !inner || boundary == inner ||
           boundaryVertices.find(inner) != boundaryVertices.end())
          return false;
        const auto inserted = inward.emplace(boundary, inner);
        return inserted.second || inserted.first->second == inner;
      };

      for(std::size_t i = 0; i < loop.size(); ++i) {
        MVertex *a = loop[i];
        MVertex *b = loop[(i + 1) % loop.size()];
        const auto found = edgeElements.find(canonicalEdge(a, b));
        if(found == edgeElements.end() || found->second.size() != 1)
          return false;
        MElement *element = found->second.front();
        if(!element || element->getNumPrimaryVertices() != 4 ||
           !ringElements.insert(element).second)
          return false;
        int ia = -1, ib = -1;
        for(int k = 0; k < 4; ++k) {
          if(element->getVertex(k) == a) ia = k;
          if(element->getVertex(k) == b) ib = k;
        }
        if(ia < 0 || ib < 0) return false;
        MVertex *innerA = nullptr;
        MVertex *innerB = nullptr;
        if(ib == (ia + 1) % 4) {
          innerA = element->getVertex((ia + 3) % 4);
          innerB = element->getVertex((ia + 2) % 4);
        }
        else if(ib == (ia + 3) % 4) {
          innerA = element->getVertex((ia + 1) % 4);
          innerB = element->getVertex((ia + 2) % 4);
        }
        else {
          return false;
        }
        if(!setInward(a, innerA) || !setInward(b, innerB)) return false;
        const auto innerEdge = edgeElements.find(
          canonicalEdge(innerA, innerB));
        if(innerEdge == edgeElements.end() || innerEdge->second.size() != 2)
          return false;
      }
      if(inward.size() != loop.size()) return false;
      std::set<MVertex *> innerVertices;
      for(const auto &entry : inward) innerVertices.insert(entry.second);
      if(innerVertices.size() != loop.size()) return false;

      for(MVertex *boundary : loop) {
        const std::vector<MElement *> incident =
          topology.incidentElements(boundary);
        if(incident.size() != 2 ||
           std::any_of(incident.begin(), incident.end(),
                       [&](MElement *element) {
                         return ringElements.find(element) ==
                                ringElements.end();
                       }))
          return false;
        const auto radial = edgeElements.find(
          canonicalEdge(boundary, inward[boundary]));
        if(radial == edgeElements.end() || radial->second.size() != 2 ||
           std::any_of(radial->second.begin(), radial->second.end(),
                       [&](MElement *element) {
                         return ringElements.find(element) ==
                                ringElements.end();
                       }))
          return false;
      }
      return ringElements.size() == loop.size();
    }

    bool tryPillowHole(GFace *face, const BoundaryLoop &boundary,
                       int neighborLayers,
                       const SmallCavityOptimizerOptions &options,
                       SmallCavityOptimizerResult &result,
                       std::size_t &insertedQuadrangles,
                       bool &alreadyPillowed)
    {
      insertedQuadrangles = 0;
      alreadyPillowed = false;
      if(!face || boundary.vertices.size() < 3 || neighborLayers <= 0)
        return false;
      FaceHalfEdgeTopology topology(surfaceElements(face));
      if(!topology.manifold()) return false;
      std::map<Edge, std::vector<MElement *> > edgeElements;
      for(const auto &entry : topology.edges())
        edgeElements[entry.first] = entry.second;

      std::vector<MVertex *> loop = boundary.vertices;
      std::unordered_map<MVertex *, UV> parameters;
      if(!orientLoopWithDomainOnLeft(face, loop, edgeElements, parameters))
        return false;
      if(hasCompletePillowLayer(loop, topology, edgeElements)) {
        alreadyPillowed = true;
        return false;
      }

      const std::set<MVertex *> protectedVertices =
        protectedFaceVertices(face);
      if(std::any_of(loop.begin(), loop.end(), [&](MVertex *vertex) {
           return protectedVertices.find(vertex) != protectedVertices.end();
         }))
        return false;

      std::set<MElement *> selected;
      // Replacing a boundary vertex affects its complete element star, not
      // just the element adjacent to either boundary edge. Include that full
      // star before adding optional neighbor rows so every changed element is
      // smoothed and validated in memory before the diff is committed.
      for(MVertex *vertex : loop) {
        const std::vector<MElement *> incident =
          topology.incidentElements(vertex);
        if(incident.empty()) return false;
        selected.insert(incident.begin(), incident.end());
      }
      std::set<MElement *> frontier = selected;
      for(int layer = 1; layer < neighborLayers; ++layer) {
        std::set<MElement *> next;
        for(MElement *element : frontier)
          for(MElement *neighbor : topology.neighbors(element))
            if(selected.find(neighbor) == selected.end())
              next.insert(neighbor);
        selected.insert(next.begin(), next.end());
        frontier = std::move(next);
        if(frontier.empty()) break;
      }
      if(touchesBoundaryLayerElementData(
           face, std::vector<MElement *>(selected.begin(), selected.end())))
        return false;

      std::vector<MVertex *> localVertices;
      std::unordered_map<MVertex *, std::size_t> localIndex;
      auto addVertex = [&](MVertex *vertex) {
        const auto inserted = localIndex.emplace(vertex, localVertices.size());
        if(inserted.second) localVertices.push_back(vertex);
        return inserted.first->second;
      };
      for(MElement *element : selected) {
        const std::size_t count = element->getNumPrimaryVertices();
        if(count != 3 && count != 4) return false;
        for(std::size_t i = 0; i < count; ++i)
          addVertex(element->getVertex(static_cast<int>(i)));
      }
      for(MVertex *vertex : loop) addVertex(vertex);
      const std::size_t existingVertexCount = localVertices.size();
      std::vector<UV> points(existingVertexCount);
      for(std::size_t i = 0; i < existingVertexCount; ++i) {
        UV uv;
        const auto found = parameters.find(localVertices[i]);
        if(found != parameters.end()) uv = found->second;
        else if(!vertexParameter(face, localVertices[i], uv)) return false;
        parameters[localVertices[i]] = uv;
        points[i] = uv;
      }

      std::unordered_map<MVertex *, std::size_t> duplicateIndex;
      for(std::size_t i = 0; i < loop.size(); ++i) {
        MVertex *vertex = loop[i];
        const UV &base = parameters[vertex];
        const UV &previous = parameters[loop[(i + loop.size() - 1) % loop.size()]];
        const UV &next = parameters[loop[(i + 1) % loop.size()]];
        const UV incoming = {base[0] - previous[0], base[1] - previous[1]};
        const UV outgoing = {next[0] - base[0], next[1] - base[1]};
        const double inLength = std::hypot(incoming[0], incoming[1]);
        const double outLength = std::hypot(outgoing[0], outgoing[1]);
        if(!(inLength > 0.) || !(outLength > 0.)) return false;
        UV direction = {
          -incoming[1] / inLength - outgoing[1] / outLength,
           incoming[0] / inLength + outgoing[0] / outLength};
        double norm = std::hypot(direction[0], direction[1]);
        if(!(norm > 1.e-12)) {
          direction = {-outgoing[1] / outLength,
                        outgoing[0] / outLength};
          norm = 1.;
        }
        direction[0] /= norm;
        direction[1] /= norm;
        double step = 1.e-4 * std::min(inLength, outLength);
        UV duplicate = {base[0] + step * direction[0],
                        base[1] + step * direction[1]};
        bool mapped = false;
        for(int trial = 0; trial < 12; ++trial) {
          const GPoint point = face->point(SPoint2(duplicate[0], duplicate[1]));
          if(point.succeeded() && std::isfinite(point.x()) &&
             std::isfinite(point.y()) && std::isfinite(point.z())) {
            mapped = true;
            break;
          }
          step *= .5;
          duplicate = {base[0] + step * direction[0],
                       base[1] + step * direction[1]};
        }
        if(!mapped) return false;
        duplicateIndex[vertex] = points.size();
        points.push_back(duplicate);
      }

      double orientation = 0.;
      for(MElement *element : selected) {
        orientation = parametricElementArea(element, parameters);
        if(std::abs(orientation) > 1.e-14) break;
      }
      if(std::abs(orientation) <= 1.e-14) return false;
      orientation = orientation > 0. ? 1. : -1.;

      std::vector<std::array<std::size_t, 3> > triangles;
      std::vector<std::array<std::size_t, 4> > quadrangles;
      for(MElement *element : selected) {
        const std::size_t count = element->getNumPrimaryVertices();
        if(count == 3) {
          std::array<std::size_t, 3> triangle;
          for(std::size_t i = 0; i < 3; ++i) {
            MVertex *vertex = element->getVertex(static_cast<int>(i));
            const auto duplicate = duplicateIndex.find(vertex);
            triangle[i] = duplicate == duplicateIndex.end() ?
                            localIndex[vertex] : duplicate->second;
          }
          triangles.push_back(triangle);
        }
        else {
          std::array<std::size_t, 4> quadrangle;
          for(std::size_t i = 0; i < 4; ++i) {
            MVertex *vertex = element->getVertex(static_cast<int>(i));
            const auto duplicate = duplicateIndex.find(vertex);
            quadrangle[i] = duplicate == duplicateIndex.end() ?
                              localIndex[vertex] : duplicate->second;
          }
          quadrangles.push_back(quadrangle);
        }
      }
      const std::size_t existingQuadrangleCount = quadrangles.size();
      for(std::size_t i = 0; i < loop.size(); ++i) {
        const std::size_t oldA = localIndex[loop[i]];
        const std::size_t oldB = localIndex[loop[(i + 1) % loop.size()]];
        const std::size_t newA = duplicateIndex[loop[i]];
        const std::size_t newB = duplicateIndex[loop[(i + 1) % loop.size()]];
        quadrangles.push_back(orientation > 0. ?
          std::array<std::size_t, 4>{oldA, oldB, newB, newA} :
          std::array<std::size_t, 4>{oldA, newA, newB, oldB});
      }

      std::map<std::pair<std::size_t, std::size_t>, std::size_t> edgeCount;
      auto countEdges = [&](const auto &elements) {
        for(const auto &element : elements)
          for(std::size_t i = 0; i < element.size(); ++i) {
            std::size_t a = element[i];
            std::size_t b = element[(i + 1) % element.size()];
            if(b < a) std::swap(a, b);
            ++edgeCount[{a, b}];
          }
      };
      countEdges(triangles);
      countEdges(quadrangles);
      std::vector<bool> fixed(points.size(), false);
      for(const auto &entry : edgeCount)
        if(entry.second == 1) {
          fixed[entry.first.first] = true;
          fixed[entry.first.second] = true;
        }
      for(std::size_t i = 0; i < existingVertexCount; ++i)
        if(localVertices[i]->onWhat() != face) fixed[i] = true;
      for(std::size_t i = 0; i < existingVertexCount; ++i)
        if(protectedVertices.find(localVertices[i]) !=
           protectedVertices.end())
          fixed[i] = true;

      // Winslow must see physical lengths: the progressive UV map of a
      // discrete MAT face can be strongly anisotropic. Build a mean-plane
      // chart for this tiny patch, optimize there, then project the candidate
      // back through the existing surface parametrization.
      std::vector<Point> initialXyz(points.size());
      for(std::size_t i = 0; i < points.size(); ++i) {
        if(i < existingVertexCount) {
          initialXyz[i] = {localVertices[i]->x(), localVertices[i]->y(),
                           localVertices[i]->z()};
          continue;
        }
        const GPoint mapped = face->point(SPoint2(points[i][0], points[i][1]));
        if(!mapped.succeeded() || !std::isfinite(mapped.x()) ||
           !std::isfinite(mapped.y()) || !std::isfinite(mapped.z()))
          return false;
        initialXyz[i] = {mapped.x(), mapped.y(), mapped.z()};
      }
      Point origin = {0., 0., 0.};
      for(const Point &point : initialXyz)
        for(std::size_t coordinate = 0; coordinate < 3; ++coordinate)
          origin[coordinate] += point[coordinate];
      for(double &coordinate : origin)
        coordinate /= static_cast<double>(initialXyz.size());
      Point normal = {0., 0., 0.};
      auto accumulateNormal = [&](const auto &elements) {
        for(const auto &element : elements) {
          const Point &a = initialXyz[element[0]];
          const Point &b = initialXyz[element[1]];
          const Point &c = initialXyz[element[2]];
          const Point ab = {b[0] - a[0], b[1] - a[1], b[2] - a[2]};
          const Point ac = {c[0] - a[0], c[1] - a[1], c[2] - a[2]};
          normal[0] += ab[1] * ac[2] - ab[2] * ac[1];
          normal[1] += ab[2] * ac[0] - ab[0] * ac[2];
          normal[2] += ab[0] * ac[1] - ab[1] * ac[0];
        }
      };
      accumulateNormal(triangles);
      accumulateNormal(quadrangles);
      double normalNorm = std::sqrt(normal[0] * normal[0] +
                                    normal[1] * normal[1] +
                                    normal[2] * normal[2]);
      if(!(normalNorm > 1.e-14)) return false;
      for(double &coordinate : normal) coordinate /= normalNorm;
      Point firstAxis = {0., 0., 0.};
      double firstAxisNorm = 0.;
      for(std::size_t i = 0; i < loop.size(); ++i) {
        const Point &a = initialXyz[localIndex[loop[i]]];
        const Point &b =
          initialXyz[localIndex[loop[(i + 1) % loop.size()]]];
        Point edge = {b[0] - a[0], b[1] - a[1], b[2] - a[2]};
        const double normalPart = edge[0] * normal[0] +
                                  edge[1] * normal[1] +
                                  edge[2] * normal[2];
        for(std::size_t coordinate = 0; coordinate < 3; ++coordinate)
          edge[coordinate] -= normalPart * normal[coordinate];
        const double edgeNorm = std::sqrt(edge[0] * edge[0] +
                                          edge[1] * edge[1] +
                                          edge[2] * edge[2]);
        if(edgeNorm > firstAxisNorm) {
          firstAxis = edge;
          firstAxisNorm = edgeNorm;
        }
      }
      if(!(firstAxisNorm > 1.e-14)) return false;
      for(double &coordinate : firstAxis) coordinate /= firstAxisNorm;
      const Point secondAxis = {
        normal[1] * firstAxis[2] - normal[2] * firstAxis[1],
        normal[2] * firstAxis[0] - normal[0] * firstAxis[2],
        normal[0] * firstAxis[1] - normal[1] * firstAxis[0]};
      std::vector<UV> planePoints(points.size());
      for(std::size_t i = 0; i < initialXyz.size(); ++i) {
        const Point delta = {initialXyz[i][0] - origin[0],
                             initialXyz[i][1] - origin[1],
                             initialXyz[i][2] - origin[2]};
        planePoints[i] = {
          delta[0] * firstAxis[0] + delta[1] * firstAxis[1] +
            delta[2] * firstAxis[2],
          delta[0] * secondAxis[0] + delta[1] * secondAxis[1] +
            delta[2] * secondAxis[2]};
      }
      auto signedPlaneArea = [&](const auto &element) {
        double twiceArea = 0.;
        for(std::size_t i = 0; i < element.size(); ++i) {
          const UV &a = planePoints[element[i]];
          const UV &b = planePoints[element[(i + 1) % element.size()]];
          twiceArea += a[0] * b[1] - a[1] * b[0];
        }
        return .5 * twiceArea;
      };
      double planeOrientation = 0.;
      for(const auto &triangle : triangles) {
        planeOrientation = signedPlaneArea(triangle);
        if(std::abs(planeOrientation) > 1.e-14) break;
      }
      if(std::abs(planeOrientation) <= 1.e-14)
        for(const auto &quadrangle : quadrangles) {
          planeOrientation = signedPlaneArea(quadrangle);
          if(std::abs(planeOrientation) > 1.e-14) break;
        }
      if(std::abs(planeOrientation) <= 1.e-14) return false;

      const std::vector<UV> initialPlanePoints = planePoints;
      SmallCavityWinslowOptions winslowOptions = options.winslow;
      winslowOptions.harmonicInitialization = true;
      SmallCavityWinslowResult winslow;
      try {
        winslow = optimizeLocalSurfacePatchWinslow(
          planePoints, fixed, triangles, quadrangles,
          planeOrientation > 0. ? 1. : -1., winslowOptions);
      }
      catch(const std::exception &) {
        ++result.rejectedByWinslow;
        return false;
      }
      if(!winslow.success || !winslow.untangled) {
        ++result.rejectedByWinslow;
        return false;
      }
      const std::vector<UV> targetPlanePoints = planePoints;
      const std::vector<UV> initialSurfacePoints = points;
      const std::vector<MElement *> selectedElements(
        selected.begin(), selected.end());
      const SpecificationObjective referenceObjective =
        specificationObjective(selectedElements);
      const GeometryDeviation referencePillowGeometry =
        existingGeometryDeviation(face, selectedElements);
      double meanBoundaryEdge = 0.;
      for(std::size_t i = 0; i < loop.size(); ++i) {
        const std::size_t old = localIndex[loop[i]];
        const std::size_t next =
          localIndex[loop[(i + 1) % loop.size()]];
        meanBoundaryEdge += distance(initialXyz[old], initialXyz[next]);
      }
      meanBoundaryEdge /= static_cast<double>(loop.size());

      GFaceMeshPatch originalPatch;
      originalPatch.gf = face;
      originalPatch.elements.assign(selected.begin(), selected.end());
      const SizeScore beforePillowSize =
        existingSizeScore(originalPatch, options, false);

      std::vector<Point> xyz;
      bool acceptedGeometry = false;
      bool rejectedByWinslow = false;
      bool rejectedByQuality = false;
      bool rejectedBySize = false;
      CleanUpDecisionReason acceptedDecisionReason =
        CleanUpDecisionReason::Rejected;
      auto hasExpectedOrientation = [&](const auto &element,
                                        const std::vector<UV> &uv) {
        double twiceArea = 0.;
        for(std::size_t i = 0; i < element.size(); ++i) {
          const UV &a = uv[element[i]];
          const UV &b = uv[element[(i + 1) % element.size()]];
          twiceArea += a[0] * b[1] - a[1] * b[0];
        }
        return orientation * twiceArea > 0.;
      };
      for(const double fraction :
          {4., 3., 2.5, 2., 1.5, 1.25, 1., .85, .7, .55, .4, .3, .2,
           .15, .1, .075, .05}) {
        std::vector<UV> trialPlanePoints = initialPlanePoints;
        std::vector<bool> trialFixed = fixed;
        for(std::size_t i = 0; i < trialPlanePoints.size(); ++i) {
          if(fixed[i]) continue;
          const double vertexFraction =
            i < existingVertexCount ? std::min(1., fraction) : fraction;
          for(std::size_t coordinate = 0; coordinate < 2; ++coordinate)
            trialPlanePoints[i][coordinate] += vertexFraction *
              (targetPlanePoints[i][coordinate] -
               initialPlanePoints[i][coordinate]);
          if(i >= existingVertexCount) trialFixed[i] = true;
        }
        if(std::find(trialFixed.begin(), trialFixed.end(), false) !=
           trialFixed.end()) {
          SmallCavityWinslowResult relaxed;
          try {
            relaxed = optimizeLocalSurfacePatchWinslow(
              trialPlanePoints, trialFixed, triangles, quadrangles,
              planeOrientation > 0. ? 1. : -1., winslowOptions);
          }
          catch(const std::exception &) {
            rejectedByWinslow = true;
            continue;
          }
          if(!relaxed.success || !relaxed.untangled) {
            rejectedByWinslow = true;
            continue;
          }
        }

        std::vector<UV> trialPoints = initialSurfacePoints;
        bool valid = true;
        for(std::size_t i = 0; i < trialPoints.size(); ++i) {
          if(fixed[i]) continue;
          const SPoint3 target(
            origin[0] + trialPlanePoints[i][0] * firstAxis[0] +
              trialPlanePoints[i][1] * secondAxis[0],
            origin[1] + trialPlanePoints[i][0] * firstAxis[1] +
              trialPlanePoints[i][1] * secondAxis[1],
            origin[2] + trialPlanePoints[i][0] * firstAxis[2] +
              trialPlanePoints[i][1] * secondAxis[2]);
          const SPoint2 parameter = face->parFromPoint(target, true, true);
          if(!std::isfinite(parameter.x()) ||
             !std::isfinite(parameter.y())) {
            valid = false;
            break;
          }
          trialPoints[i] = {parameter.x(), parameter.y()};
        }
        if(!valid) {
          rejectedByQuality = true;
          continue;
        }
        std::vector<Point> trialXyz(trialPoints.size());
        for(std::size_t i = 0; i < trialPoints.size(); ++i) {
          if(i < existingVertexCount && fixed[i]) {
            trialXyz[i] = {localVertices[i]->x(), localVertices[i]->y(),
                           localVertices[i]->z()};
            continue;
          }
          const GPoint mapped = face->point(
            SPoint2(trialPoints[i][0], trialPoints[i][1]));
          if(!mapped.succeeded() || !std::isfinite(mapped.x()) ||
             !std::isfinite(mapped.y()) || !std::isfinite(mapped.z())) {
            valid = false;
            break;
          }
          trialXyz[i] = {mapped.x(), mapped.y(), mapped.z()};
        }
        if(!valid) {
          rejectedByQuality = true;
          continue;
        }

        for(const auto &triangle : triangles) {
          if(!hasExpectedOrientation(triangle, trialPoints)) {
            valid = false;
            break;
          }
          std::vector<Point> element(3);
          for(std::size_t i = 0; i < 3; ++i)
            element[i] = trialXyz[triangle[i]];
          const ElementQuality quality = evaluateElementQuality(
            SurfaceElementKind::Triangle, element);
          if(!quality.topologicallyValid) {
            valid = false;
            break;
          }
        }
        std::size_t pillowSpecificationFailures = 0;
        if(valid)
          for(std::size_t q = 0; q < quadrangles.size(); ++q) {
            const auto &quadrangle = quadrangles[q];
            if(!hasExpectedOrientation(quadrangle, trialPoints)) {
              valid = false;
              break;
            }
            std::vector<Point> element(4);
            for(std::size_t i = 0; i < 4; ++i)
              element[i] = trialXyz[quadrangle[i]];
            const ElementQuality quality = evaluateElementQuality(
              SurfaceElementKind::Quadrangle, element);
            if(!quality.topologicallyValid) {
              valid = false;
              break;
            }
            if(q >= existingQuadrangleCount &&
               !quality.passesAbsoluteSpecifications)
              ++pillowSpecificationFailures;
          }
        // A distorted parametric chart can make a physically valid opened
        // pillow ring look non-convex in UV. QuadCleanUp can therefore skip
        // the strict UV-convexity test here, but physical non-concavity is a
        // hard invariant for every accepted transaction.
        if(valid) {
          const bool nonConcave = options.quadCleanUp ?
            candidateQuadranglesArePhysicallyNonConcave(
              quadrangles, trialXyz) :
            candidateQuadranglesAreNonConcave(
              quadrangles, trialPoints, trialXyz);
          if(!nonConcave) valid = false;
        }
        if(!valid || pillowSpecificationFailures != 0) {
          rejectedByQuality = true;
          continue;
        }
        double minimumRadial = std::numeric_limits<double>::infinity();
        for(MVertex *oldVertex : loop) {
          const std::size_t old = localIndex[oldVertex];
          minimumRadial = std::min(
            minimumRadial,
            distance(trialXyz[old], trialXyz[duplicateIndex[oldVertex]]));
        }
        if(!(minimumRadial > .05 * meanBoundaryEdge)) {
          rejectedByQuality = true;
          continue;
        }
        SizeScore size;
        if(options.enforceSizeMap || options.quadCleanUp) {
          size = surfacePatchSizeScore(
            face, trialPoints, trialXyz, triangles, quadrangles, fixed,
            options);
          if((options.quadCleanUp && !size.admissible) ||
             (options.enforceSizeMap &&
              !admissibleSizeChange(beforePillowSize, size, options))) {
            rejectedBySize = true;
            continue;
          }
        }

        // Pillow is a topology transaction as well: it follows exactly the
        // common CleanUp decision path after the complete smoothed patch has
        // passed convexity and hard-size guards.
        if(options.quadCleanUp) {
          const SpecificationObjective candidateFullObjective =
            candidateMixedObjective(triangles, quadrangles, trialXyz);
          const std::size_t beforeSizeViolations =
            beforePillowSize.belowMinimum + beforePillowSize.aboveMaximum +
            beforePillowSize.invalid;
          const std::size_t afterSizeViolations =
            size.belowMinimum + size.aboveMaximum + size.invalid;
          GeometryDeviation candidatePillowGeometry;
          if(candidateFullObjective.absoluteBadElementCount == 0 &&
             candidateFullObjective.absoluteBadElementCount ==
               referenceObjective.absoluteBadElementCount)
            candidatePillowGeometry = candidateMixedGeometryDeviation(
              face, trialPoints, trialXyz, triangles, quadrangles);
          acceptedDecisionReason = cleanUpDecision(
            candidateFullObjective, referenceObjective,
            candidatePillowGeometry, referencePillowGeometry,
            candidateFullObjective.absoluteBadElementCount == 0,
            ValenceObjective(), ValenceObjective(), afterSizeViolations,
            beforeSizeViolations, size.meanSquaredLogRatio,
            beforePillowSize.meanSquaredLogRatio,
            options.objectiveRelativeTolerance);
          if(acceptedDecisionReason == CleanUpDecisionReason::Rejected) {
            // The strict improvement is structural: this transaction removes
            // one hole without a complete pillow layer. It may break a CAD
            // tie only when shape, hard size and the additive CAD integral
            // are all non-regressive.
            const bool pillowTopologyImproves =
              candidateFullObjective.absoluteBadElementCount == 0 &&
              noWorseAbsoluteSpecifications(
                candidateFullObjective, referenceObjective,
                options.objectiveRelativeTolerance) &&
              afterSizeViolations <= beforeSizeViolations &&
              candidatePillowGeometry.valid &&
              referencePillowGeometry.valid &&
              compareGeometryDeviation(
                candidatePillowGeometry, referencePillowGeometry,
                options.objectiveRelativeTolerance) == 0 &&
              geometryDoesNotRegressBeyondRoundoff(
                candidatePillowGeometry, referencePillowGeometry);
            if(pillowTopologyImproves)
              acceptedDecisionReason =
                CleanUpDecisionReason::OtherImprovement;
          }
          if(acceptedDecisionReason == CleanUpDecisionReason::Rejected) {
            rejectedByQuality = true;
            continue;
          }
        }
        else
          acceptedDecisionReason = CleanUpDecisionReason::OtherImprovement;
        points = std::move(trialPoints);
        xyz = std::move(trialXyz);
        acceptedGeometry = true;
        break;
      }
      if(!acceptedGeometry) {
        if(rejectedByWinslow) ++result.rejectedByWinslow;
        if(rejectedByQuality) ++result.rejectedByQuality;
        if(rejectedBySize) ++result.rejectedBySize;
        if(options.verbose)
          Msg::Info("QuadOptimizer pillow face %d rejected by physical "
                    "quality line search", face->tag());
        return false;
      }

      std::unordered_map<MVertex *, MVertex *> duplicates;
      std::vector<MVertex *> created;
      created.reserve(loop.size());
      for(MVertex *old : loop) {
        const std::size_t local = duplicateIndex[old];
        MVertex *vertex = new MFaceVertex(
          xyz[local][0], xyz[local][1], xyz[local][2], face,
          points[local][0], points[local][1]);
        duplicates[old] = vertex;
        created.push_back(vertex);
      }

      std::vector<MElement *> affected;
      std::vector<MElement *> replacement;
      for(MElement *element : surfaceElements(face)) {
        const std::size_t count = element->getNumPrimaryVertices();
        bool touches = false;
        std::array<MVertex *, 4> vertices = {nullptr, nullptr, nullptr, nullptr};
        for(std::size_t i = 0; i < count; ++i) {
          MVertex *vertex = element->getVertex(static_cast<int>(i));
          const auto found = duplicates.find(vertex);
          vertices[i] = found == duplicates.end() ? vertex : found->second;
          touches = touches || found != duplicates.end();
        }
        if(!touches) continue;
        affected.push_back(element);
        MElement *copy = count == 3 ?
          static_cast<MElement *>(new MTriangle(vertices[0], vertices[1],
                                                vertices[2])) :
          static_cast<MElement *>(new MQuadrangle(
            vertices[0], vertices[1], vertices[2], vertices[3]));
        copy->setPartition(element->getPartition());
        replacement.push_back(copy);
      }
      if(affected.empty()) {
        for(MElement *element : replacement) delete element;
        for(MVertex *vertex : created) delete vertex;
        return false;
      }
      for(std::size_t i = 0; i < loop.size(); ++i) {
        MVertex *oldA = loop[i];
        MVertex *oldB = loop[(i + 1) % loop.size()];
        replacement.push_back(orientation > 0. ?
          static_cast<MElement *>(new MQuadrangle(
            oldA, oldB, duplicates[oldB], duplicates[oldA])) :
          static_cast<MElement *>(new MQuadrangle(
            oldA, duplicates[oldA], duplicates[oldB], oldB)));
      }

      FaceHalfEdgeTopology validatedTopology(surfaceElements(face));
      if(!validatedTopology.manifold() ||
         !validatedTopology.replace(affected, replacement)) {
        for(MElement *element : replacement) delete element;
        for(MVertex *vertex : created) delete vertex;
        return false;
      }

      GFaceMeshDiff diff;
      diff.gf = face;
      diff.before.gf = face;
      diff.before.elements = affected;
      diff.after.gf = face;
      diff.after.intVertices = created;
      diff.after.elements = replacement;
      if(!diff.execute(true)) return false;
      for(std::size_t i = 0; i < existingVertexCount; ++i) {
        if(fixed[i] || localVertices[i]->onWhat() != face) continue;
        localVertices[i]->setXYZ(xyz[i][0], xyz[i][1], xyz[i][2]);
        localVertices[i]->setParameter(0, points[i][0]);
        localVertices[i]->setParameter(1, points[i][1]);
      }
      if(options.quadCleanUp)
        recordAcceptedCleanUpDecision(result, acceptedDecisionReason);
      insertedQuadrangles = loop.size();
      return true;
    }

    void pillowFaceHoles(GFace *face,
                         const SmallCavityOptimizerOptions &options,
                         SmallCavityOptimizerResult &result)
    {
      FaceHalfEdgeTopology topology(surfaceElements(face));
      if(!topology.manifold()) return;
      std::vector<BoundaryLoop> loops;
      if(!collectBoundaryLoops(face, topology, loops) || loops.size() < 2)
        return;
      std::map<Edge, std::vector<MElement *> > edgeElements;
      for(const auto &entry : topology.edges())
        edgeElements[entry.first] = entry.second;
      // Classify each component from its domain-left orientation in the GFace
      // parameter plane: outer components have positive signed area, holes
      // negative signed area. Perimeter is not a topological classifier (a
      // hole can be longer than an outer component, and a face can have
      // several disconnected components).
      for(const BoundaryLoop &boundary : loops) {
        BoundaryLoop hole = boundary;
        std::unordered_map<MVertex *, UV> parameters;
        if(!orientLoopWithDomainOnLeft(
             face, hole.vertices, edgeElements, parameters))
          continue;
        double twiceArea = 0.;
        bool validArea = true;
        for(std::size_t i = 0; i < hole.vertices.size(); ++i) {
          const auto a = parameters.find(hole.vertices[i]);
          const auto b = parameters.find(
            hole.vertices[(i + 1) % hole.vertices.size()]);
          if(a == parameters.end() || b == parameters.end()) {
            validArea = false;
            break;
          }
          twiceArea += a->second[0] * b->second[1] -
                       a->second[1] * b->second[0];
        }
        if(!validArea || !std::isfinite(twiceArea) ||
           twiceArea >= -1.e-14)
          continue;
        ++result.pillowHolesVisited;
        std::size_t inserted = 0;
        bool alreadyPillowed = false;
        if(!tryPillowHole(face, hole, options.pillowNeighborLayers,
                          options, result, inserted, alreadyPillowed)) {
          if(alreadyPillowed) {
            ++result.pillowHolesAlreadyPresent;
            if(options.verbose)
              Msg::Info("QuadOptimizer: face %d boundary with %zu vertices "
                        "already has a complete pillow layer",
                        face->tag(), hole.vertices.size());
            continue;
          }
          if(options.verbose)
            Msg::Warning("QuadOptimizer: rejected pillow on face %d "
                         "boundary with %zu vertices",
                         face->tag(), hole.vertices.size());
          continue;
        }
        ++result.pillowHolesAccepted;
        result.pillowQuadranglesInserted += inserted;
        if(options.verbose)
          Msg::Info("QuadOptimizer: inserted pillow on face %d: %zu quads",
                    face->tag(), inserted);
      }
    }

  } // namespace

  TerminalTriangleRecombinationResult recombineRemainingTrianglePairs(
    GFace *face, const SmallCavityOptimizerOptions &options)
  {
    TerminalTriangleRecombinationResult result;
    if(!face || !validSizeOptions(options) ||
       !std::isfinite(options.minimumRecombinationQuality) ||
       options.minimumRecombinationQuality < 0.) {
      result.success = false;
      return result;
    }

    std::set<MEdge, MEdgeLessThan> constrainedEdges;
    auto addCurveEdges = [&](const std::vector<GEdge *> &curves) {
      for(GEdge *curve : curves)
        if(curve)
          for(MLine *line : curve->lines)
            if(line)
              constrainedEdges.insert(MEdge(
                line->getVertex(0), line->getVertex(1)));
    };
    addCurveEdges(face->edges());
    addCurveEdges(face->getEmbeddedEdges());

    struct PairSeed {
      MTriangle *first = nullptr;
      MTriangle *second = nullptr;
      Edge shared = {nullptr, nullptr};
      std::vector<MVertex *> boundary;
    };

    auto boundaryLess = [](const PairSeed &a, const PairSeed &b) {
      const std::size_t count = std::min(a.boundary.size(), b.boundary.size());
      for(std::size_t i = 0; i < count; ++i) {
        const auto ak = canonicalVertexGeometryKey(a.boundary[i]);
        const auto bk = canonicalVertexGeometryKey(b.boundary[i]);
        if(ak != bk) return ak < bk;
      }
      if(a.boundary.size() != b.boundary.size())
        return a.boundary.size() < b.boundary.size();
      const std::size_t af = a.first ? a.first->getNum() : 0;
      const std::size_t bf = b.first ? b.first->getNum() : 0;
      if(af != bf) return af < bf;
      const std::size_t as = a.second ? a.second->getNum() : 0;
      const std::size_t bs = b.second ? b.second->getNum() : 0;
      return as < bs;
    };

    const std::size_t maximumAccepted = face->triangles.size() / 2;
    while(result.accepted < maximumAccepted && face->triangles.size() >= 2) {
      const std::vector<MElement *> elements = surfaceElements(face);
      const FaceHalfEdgeTopology topology(elements);
      if(!topology.manifold()) {
        result.success = false;
        ++result.rejectedTopology;
        break;
      }

      std::vector<PairSeed> pairs;
      std::set<std::pair<MTriangle *, MTriangle *> > seen;
      for(const auto &entry : topology.edges()) {
        if(entry.second.size() != 2) continue;
        MTriangle *first = dynamic_cast<MTriangle *>(entry.second[0]);
        MTriangle *second = dynamic_cast<MTriangle *>(entry.second[1]);
        if(!first || !second) continue;
        if(std::less<MTriangle *>()(second, first)) std::swap(first, second);
        if(!seen.insert({first, second}).second) continue;

        GFaceMeshPatch patch;
        const std::vector<MElement *> pairElements = {first, second};
        if(!canonicalPatchFromElements(face, pairElements, patch) ||
           patch.bdrVertices.size() != 1 ||
           patch.bdrVertices.front().size() != 4 ||
           !patch.intVertices.empty() || !patch.embVertices.empty())
          continue;
        PairSeed pair;
        pair.first = first;
        pair.second = second;
        pair.shared = entry.first;
        pair.boundary = patch.bdrVertices.front();
        pairs.push_back(std::move(pair));
      }
      std::sort(pairs.begin(), pairs.end(), boundaryLess);

      bool changed = false;
      for(const PairSeed &pair : pairs) {
        ++result.pairsVisited;
        const std::vector<MElement *> pairElements = {
          pair.first, pair.second};
        if(!pair.first || !pair.second ||
           pair.first->getNumVertices() != 3 ||
           pair.second->getNumVertices() != 3 ||
           constrainedEdges.find(MEdge(pair.shared.first,
                                       pair.shared.second)) !=
             constrainedEdges.end() ||
           touchesBoundaryLayerElementData(face, pairElements) ||
           pair.first->getPartition() != pair.second->getPartition() ||
           pair.first->getVisibility() != pair.second->getVisibility()) {
          ++result.rejectedTopology;
          continue;
        }

        CavitySeed seed;
        if(!canonicalPatchFromElements(face, pairElements, seed.patch) ||
           seed.patch.bdrVertices.size() != 1 ||
           seed.patch.bdrVertices.front().size() != 4 ||
           !seed.patch.intVertices.empty() ||
           !seed.patch.embVertices.empty()) {
          ++result.rejectedTopology;
          continue;
        }
        const std::vector<MVertex *> &boundary =
          seed.patch.bdrVertices.front();
        std::unique_ptr<MQuadrangle> quadrangle(new MQuadrangle(
          boundary[0], boundary[1], boundary[2], boundary[3]));
        quadrangle->setPartition(pair.first->getPartition());
        quadrangle->setVisibility(pair.first->getVisibility());
        std::vector<MElement *> replacement = {quadrangle.get()};
        MVertex *orientedA = nullptr;
        MVertex *orientedB = nullptr;
        for(MElement *element : seed.patch.elements) {
          const std::size_t count = element->getNumPrimaryVertices();
          for(std::size_t i = 0; i < count; ++i) {
            MVertex *a = element->getVertex(static_cast<int>(i));
            MVertex *b = element->getVertex(
              static_cast<int>((i + 1) % count));
            if((a == boundary[0] && b == boundary[1]) ||
               (a == boundary[1] && b == boundary[0])) {
              orientedA = a;
              orientedB = b;
              break;
            }
          }
          if(orientedA) break;
        }
        if(!orientedA ||
           !orientElementsAccordingToBoundarySegment(
             orientedA, orientedB, replacement)) {
          ++result.rejectedTopology;
          continue;
        }
        FaceHalfEdgeTopology candidateTopology = topology;
        if(!candidateTopology.replace(pairElements, replacement)) {
          ++result.rejectedTopology;
          continue;
        }

        std::vector<UV> uv;
        if(!currentParametrization(seed.patch, uv) || uv.size() != 4) {
          ++result.rejectedInvalid;
          continue;
        }
        std::vector<Point> xyz(4);
        std::unordered_map<MVertex *, std::size_t> localIndex;
        bool distinct = true;
        for(std::size_t i = 0; i < boundary.size(); ++i) {
          xyz[i] = {boundary[i]->x(), boundary[i]->y(), boundary[i]->z()};
          distinct = distinct && localIndex.emplace(boundary[i], i).second;
        }
        if(!distinct) {
          ++result.rejectedInvalid;
          continue;
        }
        Pattern pattern(1);
        bool indexed = true;
        for(std::size_t i = 0; i < 4; ++i) {
          const auto found = localIndex.find(
            quadrangle->getVertex(static_cast<int>(i)));
          if(found == localIndex.end()) {
            indexed = false;
            break;
          }
          pattern.front()[i] = found->second;
        }
        const ElementQuality quadQuality =
          evaluateElementQuality(quadrangle.get());
        const double eta = quadrangle->etaShapeMeasure();
        if(!indexed ||
           !candidateQuadranglesAreNonConcave(pattern, uv, xyz) ||
           !quadQuality.topologicallyValid ||
           !quadQuality.passesAbsoluteSpecifications ||
           !std::isfinite(quadQuality.warpingDegrees) ||
           !(quadQuality.warpingDegrees <
             absoluteMaximumQuadWarpingDegrees) ||
           !std::isfinite(eta) ||
           eta < options.minimumRecombinationQuality + 1.e-12) {
          ++result.rejectedInvalid;
          continue;
        }

        const SpecificationObjective referenceObjective =
          specificationObjective(pairElements);
        const SpecificationObjective candidateObjective =
          specificationObjective(quadQuality);
        const SizeScore beforeSize =
          existingSizeScore(seed.patch, options, false);
        const SizeScore afterSize = candidateSizeScore(
          face, uv, xyz, pattern, options, boundary.size());
        const std::size_t beforeSizeViolations =
          beforeSize.belowMinimum + beforeSize.aboveMaximum +
          beforeSize.invalid;
        const std::size_t afterSizeViolations =
          afterSize.belowMinimum + afterSize.aboveMaximum +
          afterSize.invalid;
        if(!afterSize.admissible ||
           afterSizeViolations > beforeSizeViolations) {
          ++result.rejectedSize;
          continue;
        }

        const GeometryDeviation referenceGeometry =
          existingGeometryDeviation(face, pairElements);
        const GeometryDeviation candidateGeometry =
          candidateGeometryDeviation(face, uv, xyz, pattern);
        if(!referenceGeometry.valid || !candidateGeometry.valid) {
          ++result.rejectedGeometry;
          continue;
        }
        const double target = options.targetSize > 0. ?
          options.targetSize :
          std::sqrt(std::max(
            referenceGeometry.sampledArea /
              static_cast<double>(std::max<std::size_t>(
                1, referenceGeometry.elementCount)),
            std::numeric_limits<double>::min()));
        const double normalization = std::max(
          std::max(referenceGeometry.sampledArea,
                   candidateGeometry.sampledArea) *
            target * target,
          std::numeric_limits<double>::min());
        const double normalizedCadChange =
          (candidateGeometry.squaredDistanceIntegral -
           referenceGeometry.squaredDistanceIntegral) /
          normalization;
        if(!std::isfinite(normalizedCadChange)) {
          ++result.rejectedGeometry;
          continue;
        }

        ValenceObjective referenceValence, candidateValence;
        for(MVertex *vertex : boundary) {
          const std::size_t ideal = idealQuadDegree(face, vertex, topology);
          const bool interior = vertex->onWhat() == face;
          addValence(referenceValence, topology.quadDegree(vertex), ideal,
                     interior);
          addValence(candidateValence,
                     candidateTopology.quadDegree(vertex), ideal, interior);
        }
        const FastGlobalQuality referenceGlobal = fastGlobalQuality(
          referenceObjective, referenceValence,
          topologicallyInvalidElementCount(pairElements),
          beforeSizeViolations, beforeSize.meanSquaredLogRatio,
          beforeSize.edgeCount, 0.);
        const FastGlobalQuality candidateGlobal = fastGlobalQuality(
          candidateObjective, candidateValence, 0,
          afterSizeViolations, afterSize.meanSquaredLogRatio,
          afterSize.edgeCount, normalizedCadChange);
        if(!improvesFastGlobalQuality(candidateGlobal, referenceGlobal)) {
          ++result.rejectedQuality;
          continue;
        }

        GFaceMeshDiff diff;
        diff.gf = face;
        diff.before = seed.patch;
        diff.before.intVertices.clear();
        diff.after.gf = face;
        diff.after.bdrVertices = seed.patch.bdrVertices;
        diff.after.elements = {quadrangle.release()};
        if(!diff.execute(true)) {
          ++result.rejectedTopology;
          continue;
        }
        ++result.accepted;
        changed = true;
        break;
      }
      if(!changed) break;
    }

    if(result.accepted && options.invalidateVertexArrays)
      face->model()->deleteVertexArrays();
    return result;
  }

  SmallCavityOptimizerResult optimizeSmallQuadCavities(
    GFace *face, const SmallCavityOptimizerOptions &options)
  {
    SmallCavityOptimizerResult result;
    if(!face || options.maximumAcceptedCavities < 0 ||
       options.smoothingPasses < 0 ||
       options.finalSmoothingPasses < 0 ||
       options.postTopologyNeighborSmoothingPasses < 0 ||
       options.maximumOptimizationPasses < 0 ||
       options.maximumTopologyCandidatesPerCavity <= 0 ||
       options.maximumCleanUpCandidatesPerCavity <= 0 ||
       options.maximumCleanUpWinslowCandidatesPerCavity <= 0 ||
       options.maximumCleanUpCavityRings < 0 ||
       options.maximumCleanUpCavityElements <= 0 ||
       options.maximumCleanUpInteriorVertices < 0 ||
       options.maximumCleanUpInteriorVertices > 4 ||
       !(options.cleanUpLongEdgeRatio > 1.) ||
       options.pillowNeighborLayers < 0 ||
       !validSizeOptions(options)) {
      result.success = false;
      Msg::Error("QuadOptimizer: invalid small-cavity optimizer options");
      return result;
    }
    const FaceHalfEdgeTopology initialTopology(surfaceElements(face));
    if(!initialTopology.manifold()) {
      result.success = false;
      Msg::Error("QuadOptimizer: face %d is not a regular oriented surface "
                 "cell complex", face->tag());
      return result;
    }
    result.initialObjective = specificationObjective(surfaceElements(face));
    if(options.enforceSizeMap)
      setInitialSizeStatistics(result, faceSizeScore(face, options));
    // On curved faces, a Fast 2Q swap is accepted from the CAD gap at the
    // midpoint of its new diagonal. Keep both endpoints fixed during every
    // later Fast Winslow move so the checked chord is the committed chord.
    std::set<MVertex *> fastCadProtectedVertices;

    auto recombineTerminalTrianglePairs = [&]() -> std::size_t {
      SmallCavityOptimizerOptions terminalOptions = options;
      terminalOptions.invalidateVertexArrays = false;
      const TerminalTriangleRecombinationResult recombination =
        recombineRemainingTrianglePairs(face, terminalOptions);
      result.terminalTrianglePairsVisited += recombination.pairsVisited;
      result.terminalTrianglePairsAccepted += recombination.accepted;
      result.terminalTrianglePairsRejectedInvalid +=
        recombination.rejectedInvalid;
      result.terminalTrianglePairsRejectedTopology +=
        recombination.rejectedTopology;
      result.terminalTrianglePairsRejectedQuality +=
        recombination.rejectedQuality;
      result.terminalTrianglePairsRejectedSize +=
        recombination.rejectedSize;
      result.terminalTrianglePairsRejectedGeometry +=
        recombination.rejectedGeometry;
      if(!recombination.success) result.success = false;
      return recombination.accepted;
    };

    auto convertAllBoundaryTriangleQuadTriangleFans =
      [&](CleanUpDecisionPhase phase) -> std::size_t {
      if(!options.convertBoundaryTriangleQuadTriangleFans) return 0;
      std::size_t accepted = 0;
      const std::size_t maximumConversions = face->triangles.size() / 2 + 1;
      for(std::size_t conversion = 0; conversion < maximumConversions;
          ++conversion) {
        const std::vector<CavitySeed> fans =
          collectBoundaryTriangleQuadTriangleFans(face);
        if(fans.empty()) break;
        bool changed = false;
        for(const CavitySeed &fan : fans) {
          if(tryBoundaryTriangleQuadTriangleFan(
               face, fan, options, result, phase)) {
            changed = true;
            ++accepted;
            ++result.acceptedBoundaryTriangleQuadTriangleFans;
            if(options.verbose) {
              const std::size_t boundaryCount =
                fan.patch.bdrVertices.front().size();
              Msg::Info("QuadOptimizer: converted boundary "
                        "triangle-quad-chain-triangle fan B=%zu I=0->1",
                        boundaryCount);
            }
            break;
          }
        }
        if(!changed) {
          if(options.verbose)
            Msg::Warning("QuadOptimizer: %zu boundary "
                         "triangle-quad-chain-triangle fans remain but none "
                         "satisfies the geometry, quality and edge-length "
                         "guards",
                         fans.size());
          break;
        }
      }
      return accepted;
    };

    auto eliminateAllDiamonds =
      [&](CleanUpDecisionPhase phase) -> std::size_t {
      if(!options.eliminateDiamonds) return 0;
      std::size_t accepted = 0;
      // A successful diamond collapse removes one interior vertex, so this
      // loop is finite independently of the general topology-change limit.
      const std::size_t maximumDiamondCollapses = face->mesh_vertices.size();
      for(std::size_t collapse = 0; collapse < maximumDiamondCollapses;
          ++collapse) {
        const std::vector<DiamondSeed> diamonds = collectDiamonds(face);
        if(diamonds.empty()) break;
        bool changed = false;
        for(const DiamondSeed &diamond : diamonds) {
          const std::size_t retainedNumber =
            diamond.cavity.patch.intVertices[
              diamond.retainedInterior]->getNum();
          const std::size_t boundarySize =
            diamond.cavity.patch.bdrVertices.front().size();
          if(tryDiamond(face, diamond, options, result, phase)) {
            changed = true;
            ++accepted;
            ++result.acceptedDiamonds;
            if(options.verbose)
              Msg::Info("QuadOptimizer: collapsed diamond B=%zu, retained "
                        "vertex=%zu",
                        boundarySize, retainedNumber);
            break;
          }
        }
        if(!changed) {
          if(options.verbose)
            Msg::Info("QuadOptimizer: %zu diamonds remain but none satisfies "
                      "the geometry, quality and edge-length guards",
                      diamonds.size());
          break;
        }
      }
      return accepted;
    };

    auto splitAllValenceSixVertices =
      [&](CleanUpDecisionPhase phase) -> std::size_t {
      if(!options.splitValenceSixVertices) return 0;
      std::size_t accepted = 0;
      while(accepted <
            static_cast<std::size_t>(options.maximumAcceptedCavities)) {
        const std::vector<CavitySeed> valenceSix =
          collectValenceSixCavities(face);
        bool changed = false;
        for(const CavitySeed &cavity : valenceSix) {
          if(tryValenceSixCavity(face, cavity, options, result, phase)) {
            changed = true;
            ++accepted;
            ++result.acceptedValenceSixSplits;
            if(options.verbose)
              Msg::Info("QuadOptimizer: split valence-six vertex=%zu, "
                        "B=12 I=1->2",
                        cavity.patch.intVertices.front()->getNum());
            break;
          }
        }
        if(!changed) break;
      }
      return accepted;
    };

    auto optimizeCavityStage =
      [&](CavityKind kind, CleanUpDecisionPhase phase) -> std::size_t {
      std::size_t accepted = 0;
      while(accepted <
            static_cast<std::size_t>(options.maximumAcceptedCavities)) {
        const std::vector<CavitySeed> cavities =
          collectCavities(face, options, kind);
        bool changed = false;
        for(const CavitySeed &cavity : cavities) {
          if(tryCavity(face, cavity, options, result, phase)) {
            changed = true;
            ++accepted;
            switch(kind) {
            case CavityKind::Node:
              ++result.acceptedOneInteriorVertexCavities;
              break;
            case CavityKind::Edge: ++result.acceptedEdgeSwaps; break;
            case CavityKind::Triangle:
              ++result.acceptedThreeInteriorVertexCavities;
              break;
            case CavityKind::Quadrangle:
              ++result.acceptedFourInteriorVertexCavities;
              break;
            case CavityKind::CleanUpConnectivity:
            case CavityKind::CleanUpBoundary:
            case CavityKind::CleanUpShape:
            case CavityKind::CleanUpSize: break;
            }
            if(options.verbose)
              Msg::Info("QuadOptimizer: accepted cavity B=%zu I=%zu",
                        cavity.patch.bdrVertices.front().size(),
                        cavity.interiorVertexCount);
            break;
          }
        }
        if(!changed) break;
      }
      return accepted;
    };

    auto optimizeMixedTriangleQuadSwapStage =
      [&](CleanUpDecisionPhase phase) -> std::size_t {
      const bool fast = useFastInteractiveCleanUp(options);
      if((!options.quadCleanUp && !fast) ||
         (phase != CleanUpDecisionPhase::FewerUnacceptableElements &&
          phase != CleanUpDecisionPhase::BetterGeometry &&
          phase != CleanUpDecisionPhase::OtherImprovement &&
          !(fast && phase == CleanUpDecisionPhase::Any)))
        return 0;
      std::size_t accepted = 0;
      while(accepted <
            static_cast<std::size_t>(options.maximumAcceptedCavities)) {
        const std::vector<MixedTriangleQuadSwapSeed> swaps =
          collectMixedTriangleQuadSwaps(face);
        bool changed = false;
        for(const MixedTriangleQuadSwapSeed &swap : swaps) {
          if(!tryMixedTriangleQuadSwap(
               face, swap, options, result, phase))
            continue;
          changed = true;
          ++accepted;
          ++result.acceptedEdgeSwaps;
          if(options.verbose)
            Msg::Info("QuadOptimizer CleanUp: accepted mixed T+Q "
                      "pentagon swap B=5");
          // Every accepted swap invalidates both element pointers and the
          // full one-ring references. Rebuild before considering the next
          // adjacent triangle/quad pair.
          break;
        }
        if(!changed) break;
      }
      return accepted;
    };

    auto optimizeCleanUpStage = [&](CavityKind kind, bool enabled,
                                    bool criticalShapeOnly,
                                    CleanUpDecisionPhase phase)
      -> std::size_t {
      if(!enabled) return 0;
      FaceHalfEdgeTopology topology(surfaceElements(face));
      if(!topology.manifold()) {
        Msg::Warning("QuadOptimizer CleanUp: skipping a non-manifold GFace");
        return 0;
      }
      std::size_t accepted = 0;
      while(accepted <
            static_cast<std::size_t>(options.maximumAcceptedCavities)) {
        const std::vector<CavitySeed> cavities =
          collectCleanUpCavities(face, options, kind, topology,
                                 criticalShapeOnly, nullptr);
        std::set<MVertex *> reservedVertices;
        std::size_t acceptedInWave = 0;
        for(const CavitySeed &cavity : cavities) {
          if(accepted >=
             static_cast<std::size_t>(options.maximumAcceptedCavities))
            break;
          std::vector<MVertex *> cavityVertices =
            cavity.patch.bdrVertices.front();
          cavityVertices.insert(cavityVertices.end(),
                                cavity.patch.intVertices.begin(),
                                cavity.patch.intVertices.end());
          if(std::any_of(cavityVertices.begin(), cavityVertices.end(),
                         [&](MVertex *vertex) {
                           return reservedVertices.find(vertex) !=
                                  reservedVertices.end();
                         }))
            continue;
          if(!tryFlexibleCleanUpCavity(face, cavity, options, result,
                                       &topology, phase,
                                       fastCadProtectedVertices))
            continue;
          reservedVertices.insert(cavityVertices.begin(),
                                  cavityVertices.end());
          ++acceptedInWave;
          ++accepted;
          switch(kind) {
          case CavityKind::CleanUpConnectivity:
            ++result.cleanUpConnectivityAccepted;
            break;
          case CavityKind::CleanUpBoundary:
            ++result.cleanUpBoundaryAccepted;
            break;
          case CavityKind::CleanUpShape:
            ++result.cleanUpShapeAccepted;
            break;
          case CavityKind::CleanUpSize:
            ++result.cleanUpSizeAccepted;
            break;
          case CavityKind::Node:
          case CavityKind::Edge:
          case CavityKind::Triangle:
          case CavityKind::Quadrangle: break;
          }
          if(options.verbose)
            Msg::Info("QuadOptimizer CleanUp: accepted %s cavity B=%zu "
                      "I=%zu elements=%zu",
                      kind == CavityKind::CleanUpConnectivity ? "connectivity" :
                      kind == CavityKind::CleanUpBoundary ? "boundary" :
                      kind == CavityKind::CleanUpShape ? "shape" : "size",
                      cavity.patch.bdrVertices.front().size(),
                      cavity.interiorVertexCount,
                      cavity.patch.elements.size());
          // The accepted transaction can smooth vertices outside the core.
          // Rebuild every seed/reference before considering another cavity,
          // so each decision is validated against the mesh that actually
          // exists after the preceding commit.
          if(options.quadCleanUp) break;
        }
        if(acceptedInWave == 0) break;
        if(useFastInteractiveCleanUp(options)) break;
      }
      return accepted;
    };

    auto timedCleanUpStage = [&](CavityKind kind, bool enabled,
                                 bool criticalShapeOnly,
                                 double &seconds,
                                 CleanUpDecisionPhase phase) -> std::size_t {
      const auto start = std::chrono::steady_clock::now();
      const std::size_t accepted = optimizeCleanUpStage(
        kind, enabled, criticalShapeOnly, phase);
      seconds += std::chrono::duration<double>(
        std::chrono::steady_clock::now() - start).count();
      return accepted;
    };

    auto smoothCleanUpToFixedPoint = [&]() -> std::size_t {
      if(!options.quadCleanUp) return 0;
      SmallCavityOptimizerOptions smoothingOptions = options;
      smoothingOptions.smoothingPasses = 1;
      smoothingOptions.topologyOnlyIfCavityHasSpecificationFailure = false;
      smoothingOptions.invalidateVertexArrays = false;
      // Stop at a numerical fixed point well below the mesh-quality and size
      // tolerances. This also prevents insignificant Gauss-Seidel motion from
      // depending on the serialized vertex order.
      smoothingOptions.objectiveRelativeTolerance = std::max(
        smoothingOptions.objectiveRelativeTolerance, 1.e-6);
      std::size_t accepted = 0;
      for(;;) {
        const ExistingTopologyWinslowResult smoothing =
          smoothAllInteriorVertexCavities(face, smoothingOptions);
        if(!smoothing.success) {
          result.success = false;
          return accepted;
        }
        result.acceptedFinalSmoothingCavities +=
          smoothing.acceptedCavities;
        result.rejectedByWinslow += smoothing.rejectedByWinslow;
        result.rejectedBySize += smoothing.rejectedBySize;
        result.rejectedByQuality += smoothing.rejectedByQuality;
        accepted += smoothing.acceptedCavities;
        if(smoothing.acceptedCavities == 0) break;
      }
      return accepted;
    };

    // Every topology trial below is evaluated after its local smoothing. Start
    // from the corresponding fixed point so the first reference is not stale.
    if(options.quadCleanUp) smoothCleanUpToFixedPoint();
    if(!result.success) return result;

    const bool fixedPointCleanUp = options.quadCleanUp;
    auto runCleanUpPasses = [&](CleanUpDecisionPhase phase,
                                std::size_t &acceptedDuringRun) {
      acceptedDuringRun = 0;
      for(int pass = 0;
          fixedPointCleanUp || pass < options.maximumOptimizationPasses;
          ++pass) {
        ++result.passes;
        std::size_t topologyChanges = 0;
        const bool useSpecializedCavities =
          fixedPointCleanUp || !useFastInteractiveCleanUp(options);

        // Every decision phase visits every seeded Cleanup family. The
        // geometry search is exhaustive for genuine 2Q and mixed T+Q swaps,
        // and for the explicitly recognized boundary cavities. Other
        // families retain their published Cleanup triggers: enumerating a
        // disk around every already-acceptable node or quadrangle would turn
        // Cleanup into a global CAD remesher. Once a candidate is generated,
        // however, it always follows the same bad-count/geometry decision
        // hierarchy after its local Winslow relaxation.
        // Connectivity cleanup: valence-six split, generic published-pattern
        // replacement, simple node/edge fill operations and diamonds.
        std::size_t stageChanges = 0;
        if(useSpecializedCavities || useFastInteractiveCleanUp(options))
          stageChanges += optimizeMixedTriangleQuadSwapStage(phase);
        if(useSpecializedCavities)
          stageChanges += optimizeCavityStage(CavityKind::Edge, phase);
        if(useSpecializedCavities)
          stageChanges += splitAllValenceSixVertices(phase);
        stageChanges += timedCleanUpStage(
          CavityKind::CleanUpConnectivity, options.cleanUpConnectivity,
          false, result.cleanUpConnectivitySeconds, phase);
        if(useSpecializedCavities)
          stageChanges += optimizeCavityStage(CavityKind::Node, phase);
        if(useSpecializedCavities || useFastInteractiveCleanUp(options))
          stageChanges += eliminateAllDiamonds(phase);
        topologyChanges += stageChanges;
        if(fixedPointCleanUp && stageChanges)
          smoothCleanUpToFixedPoint();
        if(!result.success) return false;

        // Boundary and flange cleanup. The mixed T-Q[-Q...]-T fan is the
        // finite quad-dominant extension requested for boundary cavities: it
        // removes two triangles per accepted action and is validated by the
        // same post-Winslow decision path as the all-quad cases.
        stageChanges = timedCleanUpStage(
          CavityKind::CleanUpBoundary, options.cleanUpBoundary, false,
          result.cleanUpBoundarySeconds, phase);
        if(useSpecializedCavities)
          stageChanges += convertAllBoundaryTriangleQuadTriangleFans(phase);
        topologyChanges += stageChanges;
        if(fixedPointCleanUp && stageChanges)
          smoothCleanUpToFixedPoint();
        if(!result.success) return false;

        // Shape cleanup includes the larger generic cases and the simple
        // all-quad cavity around a bad quadrangle. Triangle cavities belong
        // to the mixed-mesh extension, not to the all-quad article.
        stageChanges = 0;
        if(useSpecializedCavities) {
          if(!fixedPointCleanUp)
            stageChanges += optimizeCavityStage(CavityKind::Triangle, phase);
          stageChanges += optimizeCavityStage(CavityKind::Quadrangle, phase);
        }
        stageChanges += timedCleanUpStage(
          CavityKind::CleanUpShape, options.cleanUpShape, false,
          result.cleanUpShapeSeconds, phase);
        topologyChanges += stageChanges;
        if(fixedPointCleanUp && stageChanges)
          smoothCleanUpToFixedPoint();
        if(!result.success) return false;

        stageChanges = timedCleanUpStage(
          CavityKind::CleanUpSize, options.cleanUpSize, false,
          result.cleanUpSizeSeconds, phase);
        topologyChanges += stageChanges;
        if(fixedPointCleanUp && stageChanges)
          smoothCleanUpToFixedPoint();
        if(!result.success) return false;

        acceptedDuringRun += topologyChanges;
        if(topologyChanges == 0) break;
      }
      return result.success;
    };

    auto runDecisionHierarchy = [&](std::size_t *acceptedDuringHierarchy) {
      if(acceptedDuringHierarchy) *acceptedDuringHierarchy = 0;
      if(!options.quadCleanUp) {
        std::size_t accepted = 0;
        const bool success =
          runCleanUpPasses(CleanUpDecisionPhase::Any, accepted);
        if(acceptedDuringHierarchy) *acceptedDuringHierarchy = accepted;
        return success;
      }
      for(;;) {
        std::size_t fewer = 0;
        if(!runCleanUpPasses(
             CleanUpDecisionPhase::FewerUnacceptableElements, fewer))
          return false;
        if(acceptedDuringHierarchy) *acceptedDuringHierarchy += fewer;
        std::size_t geometry = 0;
        if(!runCleanUpPasses(
             CleanUpDecisionPhase::BetterGeometry, geometry))
          return false;
        if(acceptedDuringHierarchy) *acceptedDuringHierarchy += geometry;
        // Re-enter the primary phase after every batch of geometric swaps.
        if(geometry != 0) continue;
        std::size_t other = 0;
        if(!runCleanUpPasses(
             CleanUpDecisionPhase::OtherImprovement, other))
          return false;
        if(acceptedDuringHierarchy) *acceptedDuringHierarchy += other;
        // A structural edit can expose a bad-element repair or a new true
        // swap, so restart the complete lexicographic path immediately.
        if(other != 0) continue;
        break;
      }
      return true;
    };

    // Candidate de-duplication is local to one immutable cavity state. A
    // face-wide connectivity tabu is incorrect here: an overlapping Winslow
    // transaction changes the geometry against which the same connectivity
    // must be judged, and element renumbering after MSH reload can change
    // which seed inserts the tabu first. With the additive one-sided decision
    // potential, rebuilding the seeds after each commit and stopping on a
    // complete idle hierarchy is both the convergence test and invariant
    // under save/reload.
    if(!runDecisionHierarchy(nullptr)) return result;

    auto closePillowAndCleanUp = [&]() -> bool {
      if(!options.quadCleanUp || options.pillowNeighborLayers <= 0)
        return result.success;
      // A post-pillow CleanUp can expose the same boundary again. Retry after
      // every complete CleanUp fixed point and stop when no admissible ring
      // is inserted. The guard turns a
      // pathological pillow/CleanUp cycle into an explicit failure instead
      // of silently returning a non-fixed mesh or looping forever.
      constexpr std::size_t maximumPillowRounds = 8;
      std::size_t pillowRounds = 0;
      for(;;) {
        // Test the guard before the next insertion attempt: the last accepted
        // transaction has then already received its smoothing and CleanUp,
        // so even this failure path never leaves a raw pillow committed.
        if(pillowRounds == maximumPillowRounds) {
          result.success = false;
          Msg::Error("QuadCleanUp: pillow/CleanUp did not reach a fixed "
                     "point on face %d", face->tag());
          return false;
        }
        const std::size_t acceptedBefore = result.pillowHolesAccepted;
        pillowFaceHoles(face, options, result);
        if(result.pillowHolesAccepted == acceptedBefore) break;
        ++pillowRounds;
        // tryPillowHole has already smoothed and validated the complete
        // in-memory transaction. Re-enter every CleanUp family afterwards so
        // the topology created by the pillow belongs to the same fixed point.
        smoothCleanUpToFixedPoint();
        if(!result.success || !runDecisionHierarchy(nullptr))
          return false;
      }
      return result.success;
    };

    if(options.quadCleanUp) {
      if(!closePillowAndCleanUp()) return result;
    }
    else if(options.pillowNeighborLayers > 0)
      pillowFaceHoles(face, options, result);
    auto smoothFastOrLegacyOnce = [&]() {
      SmallCavityOptimizerOptions smoothingOptions = options;
      smoothingOptions.smoothingPasses = options.finalSmoothingPasses;
      smoothingOptions.topologyOnlyIfCavityHasSpecificationFailure = false;
      const ExistingTopologyWinslowResult smoothing =
        smoothAllInteriorVertexCavities(
          face, smoothingOptions, &fastCadProtectedVertices);
      if(!smoothing.success) {
        result.success = false;
        return false;
      }
      result.acceptedFinalSmoothingCavities += smoothing.acceptedCavities;
      result.rejectedByWinslow += smoothing.rejectedByWinslow;
      result.rejectedBySize += smoothing.rejectedBySize;
      result.rejectedByQuality += smoothing.rejectedByQuality;
      if(options.verbose)
        Msg::Info("QuadOptimizer: final mean-plane Winslow passes=%zu "
                  "accepted=%zu",
                  smoothing.passes, smoothing.acceptedCavities);
      return true;
    };
    if(!options.quadCleanUp && options.finalSmoothingPasses > 0) {
      if(useFastInteractiveCleanUp(options)) {
        // A terminal Winslow batch can make another connectivity transaction
        // admissible. Close Fast as T;{S;T} until T is idle, while preserving
        // Mesh.Smoothing as the number of passes after each changed topology.
        // The explicit round bound is a final guard in addition to the
        // strictly decreasing additive quality potential.
        constexpr std::size_t maximumFastClosureRounds = 8;
        bool closed = false;
        for(std::size_t round = 0; round < maximumFastClosureRounds;
            ++round) {
          if(!smoothFastOrLegacyOnce()) return result;
          std::size_t topologyChanges = 0;
          if(!runDecisionHierarchy(&topologyChanges)) return result;
          if(topologyChanges == 0) {
            closed = true;
            break;
          }
        }
        if(!closed) {
          // Never leave the last accepted connectivity batch without the
          // requested Winslow relaxation, even on the guarded failure path.
          if(!smoothFastOrLegacyOnce()) return result;
          result.success = false;
          Msg::Error("OptimizeQuadsFast: topology/smoothing did not reach a "
                     "fixed point on face %d after %zu closure rounds",
                     face->tag(), maximumFastClosureRounds);
        }
      }
      else if(!smoothFastOrLegacyOnce())
        return result;
    }
    if(options.quadCleanUp) {
      // Close the decision path after terminal splits as well. A split can
      // expose a legitimate mixed T+Q boundary swap; leaving that operation
      // to the next OptimizeMesh invocation would violate the requested
      // fixed point. Re-run CleanUp, split any newly exposed terminal quad,
      // and stop only when a complete terminal round is idle.
      constexpr std::size_t maximumTerminalClosureRounds = 16;
      bool terminalClosed = false;
      for(std::size_t round = 0; round < maximumTerminalClosureRounds;
          ++round) {
        const WarpedQuadrangleSplitResult split =
          splitExcessivelyWarpedQuadrangles(
            face, absoluteMaximumQuadWarpingDegrees);
        result.excessiveWarpingQuadrangles += split.excessiveWarping;
        result.nonConvexOrInvalidQuadrangles += split.nonConvexOrInvalid;
        result.warpedQuadranglesSplit += split.split;
        const std::size_t rejected = split.rejectedInvalid +
          split.rejectedUnsupportedOrder;
        result.warpedQuadranglesRejected += rejected;
        if(rejected != 0) {
          result.success = false;
          Msg::Error("QuadCleanUp: face %d retains %zu concave, invalid or "
                     "excessively warped quads because no geometrically "
                     "valid diagonal exists (invalid=%zu, order=%zu)",
                     face->tag(), rejected, split.rejectedInvalid,
                     split.rejectedUnsupportedOrder);
          break;
        }
        if(split.split == 0) {
          terminalClosed = true;
          break;
        }
        smoothCleanUpToFixedPoint();
        if(!result.success || !runDecisionHierarchy(nullptr) ||
           !closePillowAndCleanUp())
          break;
      }
      if(result.success && !terminalClosed) {
        result.success = false;
        Msg::Error("QuadCleanUp: terminal split/CleanUp did not reach a "
                   "fixed point on face %d", face->tag());
      }
      if(result.success && terminalClosed) {
        (void)recombineTerminalTrianglePairs();
        if(result.success) {
          // This is deliberately the last topology operation. If a merge
          // ever escapes the guards above, retain its two fallback triangles
          // and never offer them to recombination again in this invocation.
          const WarpedQuadrangleSplitResult audit =
            splitExcessivelyWarpedQuadrangles(
              face, absoluteMaximumQuadWarpingDegrees);
          result.excessiveWarpingQuadrangles += audit.excessiveWarping;
          result.nonConvexOrInvalidQuadrangles += audit.nonConvexOrInvalid;
          result.warpedQuadranglesSplit += audit.split;
          const std::size_t rejected = audit.rejectedInvalid +
            audit.rejectedUnsupportedOrder;
          result.warpedQuadranglesRejected += rejected;
          if(rejected != 0) {
            result.success = false;
            Msg::Error("QuadCleanUp: face %d failed its final quad "
                       "validity audit (%zu rejected)",
                       face->tag(), rejected);
          }
        }
      }
    }
    else if(useFastInteractiveCleanUp(options)) {
      // Fast deliberately performs this after its last topology/smoothing
      // closure. Returning a concave or folded quad is prohibited: validity
      // outranks both quad count and edge-size requirements.
      const WarpedQuadrangleSplitResult split =
        splitExcessivelyWarpedQuadrangles(
          face, absoluteMaximumQuadWarpingDegrees);
      result.excessiveWarpingQuadrangles += split.excessiveWarping;
      result.nonConvexOrInvalidQuadrangles += split.nonConvexOrInvalid;
      result.warpedQuadranglesSplit += split.split;
      const std::size_t rejected = split.rejectedInvalid +
        split.rejectedUnsupportedOrder;
      result.warpedQuadranglesRejected += rejected;
      if(rejected != 0) {
        result.success = false;
        Msg::Error("OptimizeQuadsFast: face %d retains %zu prohibited "
                   "concave, invalid or excessively warped quads because "
                   "no geometrically valid diagonal exists",
                   face->tag(), rejected);
      }
      if(result.success) {
        (void)recombineTerminalTrianglePairs();
        if(result.success) {
          // Absolute final audit: its fallback triangles are never
          // recombined again during this invocation.
          const WarpedQuadrangleSplitResult audit =
            splitExcessivelyWarpedQuadrangles(
              face, absoluteMaximumQuadWarpingDegrees);
          result.excessiveWarpingQuadrangles += audit.excessiveWarping;
          result.nonConvexOrInvalidQuadrangles += audit.nonConvexOrInvalid;
          result.warpedQuadranglesSplit += audit.split;
          const std::size_t auditRejected = audit.rejectedInvalid +
            audit.rejectedUnsupportedOrder;
          result.warpedQuadranglesRejected += auditRejected;
          if(auditRejected != 0) {
            result.success = false;
            Msg::Error("OptimizeQuadsFast: face %d failed its final quad "
                       "validity audit (%zu rejected)",
                       face->tag(), auditRejected);
          }
        }
      }
    }
    const std::vector<MElement *> finalElements = surfaceElements(face);
    const FaceHalfEdgeTopology finalTopology(finalElements);
    if(!finalTopology.manifold()) {
      result.success = false;
      Msg::Error("QuadOptimizer: optimization produced an invalid surface "
                 "cell complex on face %d", face->tag());
    }
    result.finalObjective = specificationObjective(finalElements);
    if(options.enforceSizeMap)
      setFinalSizeStatistics(result, faceSizeScore(face, options));
    if(options.invalidateVertexArrays) face->model()->deleteVertexArrays();
    return result;
  }

  SmallCavityOptimizerResult optimizeSmallQuadCavities(
    int faceTag, const SmallCavityOptimizerOptions &options)
  {
    return optimizeSmallQuadCavities(
      GModel::current()->getFaceByTag(faceTag), options);
  }

  ExistingTopologyWinslowResult smoothExistingQuadCavities(
    GFace *face, const SmallCavityOptimizerOptions &options)
  {
    ExistingTopologyWinslowResult result;
    if(!face || options.smoothingPasses < 0 ||
       !validSizeOptions(options)) {
      result.success = false;
      Msg::Error("QuadOptimizer: invalid existing-topology smoothing options");
      return result;
    }
    result.initialObjective = specificationObjective(surfaceElements(face));
    for(int pass = 0; pass < options.smoothingPasses; ++pass) {
      ++result.passes;
      const std::vector<MElement *> elements = surfaceElements(face);
      const Adjacency adjacency = buildAdjacency(elements);
      const std::vector<MQuadrangle *> quadrangles = face->quadrangles;

      auto smooth = [&](CavitySeed &seed) {
        const ExistingSmoothingStatus status =
          smoothExistingCavity(face, seed, options);
        if(status == ExistingSmoothingStatus::Invalid) return;
        if(status ==
           ExistingSmoothingStatus::SkippedSpecificationCompliant) {
          ++result.skippedSpecificationCompliant;
          return;
        }
        ++result.admissibleCavities;
        ++result.cavitiesOptimized;
        switch(status) {
        case ExistingSmoothingStatus::SkippedSpecificationCompliant: break;
        case ExistingSmoothingStatus::RejectedWinslow:
          ++result.rejectedByWinslow;
          break;
        case ExistingSmoothingStatus::RejectedSize:
          ++result.rejectedBySize;
          break;
        case ExistingSmoothingStatus::RejectedQuality:
          ++result.rejectedByQuality;
          break;
        case ExistingSmoothingStatus::Accepted:
          ++result.acceptedCavities;
          break;
        case ExistingSmoothingStatus::Invalid: break;
        }
      };

      for(MQuadrangle *quadrangle : quadrangles) {
        ++result.quadsVisited;
        CavitySeed core;
        if(!fourInteriorVertexCavity(face, quadrangle, adjacency, core))
          continue;
        const std::vector<MVertex *> boundary =
          core.patch.bdrVertices.front();
        smooth(core);
        for(MVertex *vertex : boundary) {
          CavitySeed neighbor;
          if(interiorVertexCavity(face, {vertex}, adjacency, neighbor))
            smooth(neighbor);
        }
      }
    }
    result.finalObjective = specificationObjective(surfaceElements(face));
    if(options.invalidateVertexArrays) face->model()->deleteVertexArrays();
    return result;
  }

  ExistingTopologyWinslowResult smoothExistingQuadCavities(
    int faceTag, const SmallCavityOptimizerOptions &options)
  {
    return smoothExistingQuadCavities(
      GModel::current()->getFaceByTag(faceTag), options);
  }

  AllFacesOptimizerResult optimizeSmallQuadCavitiesAllFaces(
    const SmallCavityOptimizerOptions &options, int maximumThreads)
  {
    AllFacesOptimizerResult result;
    GModel *model = GModel::current();
    if(!model || maximumThreads < 0) {
      result.success = false;
      return result;
    }
    std::vector<GFace *> faces;
    for(GFace *face : model->getFaces()) {
      ++result.facesVisited;
      if(!face->quadrangles.empty()) faces.push_back(face);
    }
    result.facesWithQuadrangles = faces.size();
    result.faces.resize(faces.size());
    if(faces.empty()) return result;

    // Load the shared immutable topology database before entering the
    // parallel region.
    if(initDiskQuadrangulations() != 0) {
      result.success = false;
      return result;
    }
    // PostView-backed vector fields build their search octree lazily. Trigger
    // that initialization on the calling thread before the dynamic OpenMP
    // face loop; constructing it from inside that worksharing region would
    // enter the barriers used by PViewData with only a subset of the team.
    if(options.enforceSizeMap && options.targetSize <= 0. &&
       !options.edgeLengthCriteriaAt) {
      for(GFace *face : faces) {
        if(face->quadrangles.empty()) continue;
        MVertex *vertex = face->quadrangles.front()->getVertex(0);
        UV uv;
        if(!vertexParameter(face, vertex, uv)) continue;
        const Point xyz = {vertex->x(), vertex->y(), vertex->z()};
        (void)prescribedTargetSize(face, uv, xyz, options);
        break;
      }
    }
    SmallCavityOptimizerOptions parallelOptions = options;
    parallelOptions.invalidateVertexArrays = false;
    // Per-candidate traces are useful in a focused serial diagnosis but make
    // the normal face-parallel cleanup log enormous and interleaved. Keep the
    // public summary deterministic; individual callers can still invoke the
    // single-face routine with verbose diagnostics.
    parallelOptions.verbose = 0;

#if defined(_OPENMP)
    const int threads = maximumThreads > 0 ? maximumThreads : omp_get_max_threads();
#pragma omp parallel for schedule(dynamic) num_threads(threads)
#endif
    for(std::ptrdiff_t i = 0;
        i < static_cast<std::ptrdiff_t>(faces.size()); ++i) {
      FaceOptimizerResult faceResult;
      faceResult.faceTag = faces[static_cast<std::size_t>(i)]->tag();
      faceResult.optimizer = optimizeSmallQuadCavities(
        faces[static_cast<std::size_t>(i)], parallelOptions);
      result.faces[static_cast<std::size_t>(i)] = std::move(faceResult);
    }

    for(const FaceOptimizerResult &face : result.faces) {
      result.acceptedPillows += face.optimizer.pillowHolesAccepted;
      result.pillowHolesVisited += face.optimizer.pillowHolesVisited;
      result.pillowHolesAlreadyPresent +=
        face.optimizer.pillowHolesAlreadyPresent;
      result.insertedPillowQuadrangles +=
        face.optimizer.pillowQuadranglesInserted;
      result.acceptedEdgeSwaps += face.optimizer.acceptedEdgeSwaps;
      result.acceptedDiamonds += face.optimizer.acceptedDiamonds;
      result.acceptedSmoothingCavities +=
        face.optimizer.acceptedFinalSmoothingCavities;
      result.acceptedFewerUnacceptableElements +=
        face.optimizer.acceptedFewerUnacceptableElements;
      result.acceptedBetterGeometry +=
        face.optimizer.acceptedBetterGeometry;
      result.acceptedOtherImprovements +=
        face.optimizer.acceptedOtherImprovements;
      result.rejectedByWinslow += face.optimizer.rejectedByWinslow;
      result.rejectedBySize += face.optimizer.rejectedBySize;
      result.rejectedByQuality += face.optimizer.rejectedByQuality;
      result.excessiveWarpingQuadrangles +=
        face.optimizer.excessiveWarpingQuadrangles;
      result.nonConvexOrInvalidQuadrangles +=
        face.optimizer.nonConvexOrInvalidQuadrangles;
      result.warpedQuadranglesSplit +=
        face.optimizer.warpedQuadranglesSplit;
      result.warpedQuadranglesRejected +=
        face.optimizer.warpedQuadranglesRejected;
      result.terminalTrianglePairsVisited +=
        face.optimizer.terminalTrianglePairsVisited;
      result.terminalTrianglePairsAccepted +=
        face.optimizer.terminalTrianglePairsAccepted;
      result.terminalTrianglePairsRejectedInvalid +=
        face.optimizer.terminalTrianglePairsRejectedInvalid;
      result.terminalTrianglePairsRejectedTopology +=
        face.optimizer.terminalTrianglePairsRejectedTopology;
      result.terminalTrianglePairsRejectedQuality +=
        face.optimizer.terminalTrianglePairsRejectedQuality;
      result.terminalTrianglePairsRejectedSize +=
        face.optimizer.terminalTrianglePairsRejectedSize;
      result.terminalTrianglePairsRejectedGeometry +=
        face.optimizer.terminalTrianglePairsRejectedGeometry;
      result.success = result.success && face.optimizer.success;
      if(options.enforceSizeMap) {
        result.sizeRequirementsMet =
          result.sizeRequirementsMet && face.optimizer.sizeRequirementsMet;
        result.initialEdgesBelowMinimum +=
          face.optimizer.initialEdgesBelowMinimum;
        result.initialEdgesAboveMaximum +=
          face.optimizer.initialEdgesAboveMaximum;
        result.initialInvalidSizeEdges +=
          face.optimizer.initialInvalidSizeEdges;
        result.finalEdgesBelowMinimum +=
          face.optimizer.finalEdgesBelowMinimum;
        result.finalEdgesAboveMaximum +=
          face.optimizer.finalEdgesAboveMaximum;
        result.finalInvalidSizeEdges +=
          face.optimizer.finalInvalidSizeEdges;
        result.initialMinimumEdgeLength = std::min(
          result.initialMinimumEdgeLength,
          face.optimizer.initialMinimumEdgeLength);
        result.initialMaximumEdgeLength = std::max(
          result.initialMaximumEdgeLength,
          face.optimizer.initialMaximumEdgeLength);
        result.finalMinimumEdgeLength = std::min(
          result.finalMinimumEdgeLength,
          face.optimizer.finalMinimumEdgeLength);
        result.finalMaximumEdgeLength = std::max(
          result.finalMaximumEdgeLength,
          face.optimizer.finalMaximumEdgeLength);
      }
      result.acceptedCavities +=
        face.optimizer.acceptedDiamonds +
        face.optimizer.acceptedValenceSixSplits +
        face.optimizer.acceptedBoundaryTriangleQuadTriangleFans +
        (face.optimizer.acceptedEdgeSwaps -
         face.optimizer.acceptedCleanUpEdgeSwaps) +
        face.optimizer.acceptedOneInteriorVertexCavities +
        face.optimizer.acceptedThreeInteriorVertexCavities +
        face.optimizer.acceptedFourInteriorVertexCavities +
        face.optimizer.terminalTrianglePairsAccepted +
        face.optimizer.cleanUpConnectivityAccepted +
        face.optimizer.cleanUpBoundaryAccepted +
        face.optimizer.cleanUpShapeAccepted +
        face.optimizer.cleanUpSizeAccepted;
      result.initialObjective += face.optimizer.initialObjective;
      result.finalObjective += face.optimizer.finalObjective;
    }
    model->deleteVertexArrays();
    return result;
  }

  QuadMeshQualitySummary summarizeQuadMeshQuality(
    GModel *model, const SmallCavityOptimizerOptions &options)
  {
    QuadMeshQualitySummary summary;
    if(!model || !validSizeOptions(options)) {
      summary.success = false;
      return summary;
    }

    auto addUpper = [](QualityCriterionPassSummary &criterion, double value,
                       double preferred, double absolute) {
      ++criterion.applicable;
      if(std::isfinite(value) && value < preferred)
        ++criterion.preferredPass;
      if(std::isfinite(value) && value < absolute)
        ++criterion.absolutePass;
    };
    auto addLower = [](QualityCriterionPassSummary &criterion, double value,
                       double preferred, double absolute) {
      ++criterion.applicable;
      if(std::isfinite(value) && value > preferred)
        ++criterion.preferredPass;
      if(std::isfinite(value) && value > absolute)
        ++criterion.absolutePass;
    };
    auto criterionPasses = [](const QualityCriterionPassSummary &criterion) {
      if(!criterion.applicable) return true;
      const long double fraction =
        static_cast<long double>(criterion.preferredPass) /
        static_cast<long double>(criterion.applicable);
      return fraction >= .99L &&
        criterion.absolutePass == criterion.applicable;
    };

    double sicnSum = 0.;
    std::size_t sicnCount = 0;
    double edgeRatioSum = 0.;
    std::size_t edgeRatioCount = 0;
    double skewingSum = 0.;
    std::size_t skewingCount = 0;
    double warpingSum = 0.;
    std::size_t warpingCount = 0;
    double minimumAngle = std::numeric_limits<double>::infinity();
    double minimumSicn = std::numeric_limits<double>::infinity();
    double minimumLength = std::numeric_limits<double>::infinity();
    double minimumRatio = std::numeric_limits<double>::infinity();
    double squaredLogRatioSum = 0.;
    double cadSquaredDistanceIntegral = 0.;
    double cadSampledArea = 0.;

    for(GFace *face : model->getFaces()) {
      if(!face) continue;
      const std::vector<MElement *> elements = surfaceElements(face);
      if(elements.empty()) continue;
      ++summary.facesWithElements;
      std::map<MElement *, std::vector<SPoint2> > parametersByElement;
      for(MElement *element : elements)
        if(element)
          parametersByElement.emplace(
            element, auditElementParameters(face, element));
      SupportingPlane supportingPlane;
      const SupportingPlane *supportingPlanePointer =
        auditedSupportingPlane(face, supportingPlane) ?
          &supportingPlane : nullptr;

      const FaceHalfEdgeTopology topology(elements);
      if(!topology.manifold()) {
        ++summary.nonManifoldFaces;
      }
      else {
        ValenceObjective valence;
        std::set<MVertex *> vertices;
        // quadDegree has no useful interpretation for a vertex incident only
        // to triangles in a mixed mesh.
        for(MQuadrangle *quadrangle : face->quadrangles)
          if(quadrangle)
            for(std::size_t i = 0; i < 4; ++i)
              vertices.insert(
                quadrangle->getVertex(static_cast<int>(i)));
        for(MVertex *vertex : vertices)
          addValence(valence, topology.quadDegree(vertex),
                     idealQuadDegree(face, vertex, topology),
                     vertex && vertex->onWhat() == face);
        summary.severeValenceVertices += valence.severeCount;
        summary.irregularValenceVertices += valence.irregularCount;
      }

      for(MTriangle *triangle : face->triangles) {
        if(!triangle) continue;
        ++summary.triangles;
        const ElementQuality quality = evaluateElementQuality(triangle);
        const double sicn = triangle->minSICNShapeMeasure();
        const bool validTriangle = quality.topologicallyValid &&
          std::isfinite(sicn) && sicn > 0.;
        if(!validTriangle) ++summary.invalidTriangles;
        if(validTriangle && quality.passesAbsoluteSpecifications)
          ++summary.absolutePassElements;
        else
          ++summary.badTriangles;
        addUpper(summary.edgeRatio, quality.edgeRatio, 5., 10.);
        addLower(summary.triangleMinimumAngle,
                 quality.minimumAngleDegrees, 20., 10.);
        addUpper(summary.triangleMaximumAngle,
                 quality.maximumAngleDegrees, 120., 150.);
        addUpper(summary.skewing, quality.skewingDegrees, 125., 160.);
      }
      for(MQuadrangle *quadrangle : face->quadrangles) {
        if(!quadrangle) continue;
        ++summary.quadrangles;
        const ElementQuality quality = evaluateElementQuality(quadrangle);
        const SpecificationObjective objective =
          specificationObjective(quality);
        const auto foundParameters = parametersByElement.find(quadrangle);
        const std::vector<SPoint2> noParameters;
        const std::vector<SPoint2> &parameters =
          foundParameters == parametersByElement.end() ?
            noParameters : foundParameters->second;
        std::vector<UV> uv;
        std::vector<Point> xyz(4);
        for(std::size_t i = 0; i < 4; ++i) {
          MVertex *vertex = quadrangle->getVertex(static_cast<int>(i));
          xyz[i] = {vertex->x(), vertex->y(), vertex->z()};
        }
        if(parameters.size() >= 4) {
          uv.resize(4);
          for(std::size_t i = 0; i < 4; ++i) {
            uv[i] = {parameters[i].x(), parameters[i].y()};
          }
        }
        const Pattern singleQuadrangle = {{{0, 1, 2, 3}}};
        const double eta = quadrangle->etaShapeMeasure();
        const double sicn = quadrangle->minSICNShapeMeasure();
        const bool validQuadrangle = quality.topologicallyValid &&
          candidateQuadranglesArePhysicallyNonConcave(
            singleQuadrangle, xyz) &&
          (face->geomType() == GEntity::Plane ||
           !face->haveParametrization() ||
           (parameters.size() >= 4 &&
            candidateQuadsAreStrictlyConvex(singleQuadrangle, uv))) &&
          std::isfinite(sicn) && sicn > 0. &&
          std::isfinite(eta) && eta > 0.;
        if(!validQuadrangle)
          ++summary.invalidQuadrangles;
        if(validQuadrangle && quality.passesAbsoluteSpecifications)
          ++summary.absolutePassElements;
        else
          ++summary.badQuadrangles;
        summary.absoluteQuadrangleViolations +=
          objective.absoluteViolationCount;
        summary.preferredQuadrangleViolations +=
          objective.preferredViolationCount;

        if(std::isfinite(sicn)) {
          minimumSicn = std::min(minimumSicn, sicn);
          sicnSum += sicn;
          ++sicnCount;
        }
        if(std::isfinite(quality.minimumAngleDegrees))
          minimumAngle = std::min(
            minimumAngle, quality.minimumAngleDegrees);
        if(std::isfinite(quality.maximumAngleDegrees))
          summary.maximumQuadrangleAngleDegrees = std::max(
            summary.maximumQuadrangleAngleDegrees,
            quality.maximumAngleDegrees);
        if(std::isfinite(quality.edgeRatio)) {
          summary.maximumQuadrangleEdgeRatio = std::max(
            summary.maximumQuadrangleEdgeRatio, quality.edgeRatio);
          edgeRatioSum += quality.edgeRatio;
          ++edgeRatioCount;
        }
        if(std::isfinite(quality.skewingDegrees)) {
          summary.maximumQuadrangleSkewingDegrees = std::max(
            summary.maximumQuadrangleSkewingDegrees,
            quality.skewingDegrees);
          skewingSum += quality.skewingDegrees;
          ++skewingCount;
        }
        if(std::isfinite(quality.warpingDegrees)) {
          summary.maximumQuadrangleWarpingDegrees = std::max(
            summary.maximumQuadrangleWarpingDegrees,
            quality.warpingDegrees);
          warpingSum += quality.warpingDegrees;
          ++warpingCount;
        }

        addUpper(summary.warping, quality.warpingDegrees, 15.,
                 absoluteMaximumQuadWarpingDegrees);
        addUpper(summary.edgeRatio, quality.edgeRatio, 5., 10.);
        addLower(summary.quadrangleMinimumAngle,
                 quality.minimumAngleDegrees, 45., 25.);
        addUpper(summary.quadrangleMaximumAngle,
                 quality.maximumAngleDegrees, 135., 160.);
        addUpper(summary.skewing, quality.skewingDegrees, 125., 160.);
      }

      if(options.enforceSizeMap || options.auditSizeMap) {
        summary.sizeAudited = true;
        summary.sizeSpecificationsActive = options.enforceSizeMap;
        const SizeScore size = auditedFaceSizeScore(
          face, elements, parametersByElement, options);
        summary.sizeEdges += size.validEdgeCount;
        summary.edgesBelowMinimum += size.belowMinimum;
        summary.edgesAboveMaximum += size.aboveMaximum;
        summary.invalidSizeEdges += size.invalid;
        if(std::isfinite(size.minimumLength))
          minimumLength = std::min(minimumLength, size.minimumLength);
        if(std::isfinite(size.maximumLength))
          summary.maximumEdgeLength = std::max(
            summary.maximumEdgeLength, size.maximumLength);
        if(std::isfinite(size.minimumRatio))
          minimumRatio = std::min(minimumRatio, size.minimumRatio);
        if(std::isfinite(size.maximumRatio))
          summary.maximumTargetSizeRatio = std::max(
            summary.maximumTargetSizeRatio, size.maximumRatio);
        if(size.validEdgeCount && std::isfinite(size.meanSquaredLogRatio))
          squaredLogRatioSum += size.meanSquaredLogRatio *
            static_cast<double>(size.validEdgeCount);
      }

      summary.cadAudited = true;
      for(MElement *element : elements) {
        ++summary.cadElementsRequested;
        const auto foundParameters = parametersByElement.find(element);
        const std::vector<SPoint2> noParameters;
        const std::vector<SPoint2> &parameters =
          foundParameters == parametersByElement.end() ?
            noParameters : foundParameters->second;
        const GeometryDeviation geometry =
          auditedElementGeometryDeviation(
            face, element, parameters, supportingPlanePointer);
        summary.invalidCadSamples += geometry.invalidSampleCount;
        if(geometry.valid) {
          summary.cadElements += geometry.elementCount;
          summary.maximumCadDistance = std::max(
            summary.maximumCadDistance, geometry.maximumDistance);
          cadSquaredDistanceIntegral += geometry.squaredDistanceIntegral;
          cadSampledArea += geometry.sampledArea;
        }
        else {
          ++summary.invalidCadElements;
        }
      }
    }

    if(sicnCount) {
      summary.minimumQuadrangleSICN = minimumSicn;
      summary.averageQuadrangleSICN =
        sicnSum / static_cast<double>(sicnCount);
    }
    if(std::isfinite(minimumAngle))
      summary.minimumQuadrangleAngleDegrees = minimumAngle;
    if(edgeRatioCount)
      summary.averageQuadrangleEdgeRatio =
        edgeRatioSum / static_cast<double>(edgeRatioCount);
    if(skewingCount)
      summary.averageQuadrangleSkewingDegrees =
        skewingSum / static_cast<double>(skewingCount);
    if(warpingCount)
      summary.averageQuadrangleWarpingDegrees =
        warpingSum / static_cast<double>(warpingCount);
    if(summary.sizeAudited && summary.sizeEdges) {
      if(std::isfinite(minimumLength))
        summary.minimumEdgeLength = minimumLength;
      if(std::isfinite(minimumRatio))
        summary.minimumTargetSizeRatio = minimumRatio;
      summary.rmsLogTargetSizeRatio = std::sqrt(
        squaredLogRatioSum / static_cast<double>(summary.sizeEdges));
    }
    if(cadSampledArea > 0. &&
       std::isfinite(cadSquaredDistanceIntegral))
      summary.rmsCadDistance = std::sqrt(
        cadSquaredDistanceIntegral / cadSampledArea);

    summary.passesShapeSpecifications =
      criterionPasses(summary.warping) &&
      criterionPasses(summary.edgeRatio) &&
      criterionPasses(summary.quadrangleMinimumAngle) &&
      criterionPasses(summary.quadrangleMaximumAngle) &&
      criterionPasses(summary.triangleMinimumAngle) &&
      criterionPasses(summary.triangleMaximumAngle) &&
      criterionPasses(summary.skewing);
    return summary;
  }

} // namespace QuadOptimizer
