// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.

#include "smallCavityOptimizer.h"

#include "BackgroundMeshTools.h"
#include "GFace.h"
#include "GPoint.h"
#include "GModel.h"
#include "GmshMessage.h"
#include "MElement.h"
#include "MQuadrangle.h"
#include "MTriangle.h"
#include "MVertex.h"
#include "qmtDiskQuadrangulationRemeshing.h"
#include "qmtMeshUtils.h"

#include <algorithm>
#include <array>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <limits>
#include <map>
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
    };

    struct Candidate {
      bool valid = false;
      std::vector<UV> uv;
      std::vector<Point> xyz;
      Pattern quadrangles;
      std::vector<std::size_t> interiorAssignment;
      SpecificationObjective objective;
      double sizeError = std::numeric_limits<double>::infinity();
      ValenceObjective valence;
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
        for(const std::size_t index : indices) {
          HalfEdge &halfEdge = _halfEdges[index];
          _outgoing[halfEdge.origin].push_back(index);
          const Edge edge =
            canonicalEdge(halfEdge.origin, halfEdge.destination);
          compactEdge(edge);
          auto &incidences = _edgeHalfEdges[edge];
          if(incidences.size() == 1) {
            halfEdge.twin = incidences.front();
            _halfEdges[incidences.front()].twin = index;
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
      if(!reparamMeshVertexOnFace(vertex, face, center, true) ||
         !std::isfinite(center.x()) || !std::isfinite(center.y()))
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

    double objectivePriority(const SpecificationObjective &objective)
    {
      return 1.e18 * static_cast<double>(objective.absoluteBadElementCount) +
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
      if(options.fastInteractiveCleanUp) {
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
      std::vector<CavitySeed> cavities;
      std::set<std::vector<std::uintptr_t> > signatures;

      auto add = [&](const std::vector<MVertex *> &interior,
                     bool alwaysTryTopology, CavityKind kind,
                     const std::vector<MElement *> &patchElements) {
        if(patchElements.empty()) return;
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
        if(!patchFromElements(face, patchElements, seed.patch)) return;
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
        if(!patchFromElements(face, patchElements, diamond.cavity.patch) ||
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
        if(!patchFromElements(face, star->second, seed.patch) ||
           seed.patch.bdrVertices.size() != 1 ||
           seed.patch.bdrVertices.front().size() != 12 ||
           !seed.patch.embVertices.empty() ||
           seed.patch.intVertices.size() != 1 ||
           seed.patch.intVertices.front() != vertex)
          continue;
        seed.interiorVertexCount = 1;
        seed.alwaysTryTopology = true;
        seed.objective = specificationObjective(seed.patch.elements);
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
        if(!patchFromElements(face, entry.second, seed.patch) ||
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
        seed.objective = specificationObjective(seed.patch.elements);
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
      if(seed.kind != CavityKind::Edge || seed.patch.elements.size() != 2 ||
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

    bool physicalElementsConnectivitySignature(
      const std::vector<MElement *> &elements,
      ConnectivitySignature &signature)
    {
      signature.clear();
      signature.reserve(elements.size());
      for(MElement *element : elements) {
        if(element->getNumPrimaryVertices() != 4) return false;
        std::array<std::size_t, 4> quad;
        for(std::size_t i = 0; i < 4; ++i)
          quad[i] = element->getVertex(static_cast<int>(i))->getNum();
        std::sort(quad.begin(), quad.end());
        signature.push_back(quad);
      }
      std::sort(signature.begin(), signature.end());
      return true;
    }

    bool physicalExistingConnectivitySignature(
      const GFaceMeshPatch &patch, ConnectivitySignature &signature)
    {
      return physicalElementsConnectivitySignature(patch.elements,
                                                    signature);
    }

    ConnectivitySignature physicalCandidateConnectivitySignature(
      const CavitySeed &seed, const Pattern &quadrangles,
      const std::vector<std::size_t> &interiorAssignment)
    {
      std::vector<MVertex *> vertices = seed.patch.bdrVertices.front();
      for(const std::size_t old : interiorAssignment)
        vertices.push_back(seed.patch.intVertices[old]);
      ConnectivitySignature signature = quadrangles;
      for(auto &quad : signature) {
        for(std::size_t &vertex : quad) vertex = vertices[vertex]->getNum();
        std::sort(quad.begin(), quad.end());
      }
      std::sort(signature.begin(), signature.end());
      return signature;
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

    double targetSize(GFace *face, const UV &uv, const Point &xyz,
                      const SmallCavityOptimizerOptions &options)
    {
      if(options.targetSize > 0.) return options.targetSize;
      return BGM_MeshSize(face, uv[0], uv[1], xyz[0], xyz[1], xyz[2]);
    }

    SizeScore candidateSizeScore(
      GFace *face, const std::vector<UV> &uv, const std::vector<Point> &xyz,
      const Pattern &quadrangles, const SmallCavityOptimizerOptions &options)
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
        const UV midpointUv = {
          .5 * (uv[edge.first][0] + uv[edge.second][0]),
          .5 * (uv[edge.first][1] + uv[edge.second][1])};
        const Point midpointXyz = {
          .5 * (xyz[edge.first][0] + xyz[edge.second][0]),
          .5 * (xyz[edge.first][1] + xyz[edge.second][1]),
          .5 * (xyz[edge.first][2] + xyz[edge.second][2])};
        const double size = targetSize(face, midpointUv, midpointXyz, options);
        const double ratio = distance(xyz[edge.first], xyz[edge.second]) / size;
        if(!std::isfinite(ratio) || !(ratio > 0.)) {
          score.admissible = false;
          continue;
        }
        score.minimumRatio = std::min(score.minimumRatio, ratio);
        score.maximumRatio = std::max(score.maximumRatio, ratio);
        if(ratio < options.minimumEdgeSizeRatio ||
           ratio > options.maximumEdgeSizeRatio)
          score.admissible = false;
        error += std::pow(std::log(ratio), 2);
      }
      score.meanSquaredLogRatio = error / static_cast<double>(edges.size());
      return score;
    }

    SizeScore existingSizeScore(
      const GFaceMeshPatch &patch,
      const SmallCavityOptimizerOptions &options)
    {
      std::map<std::pair<MVertex *, MVertex *>, std::pair<UV, UV> > edges;
      for(MElement *element : patch.elements) {
        const std::size_t count = element->getNumPrimaryVertices();
        const std::vector<SPoint2> parameters =
          paramOnElement(patch.gf, element);
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
          edges.emplace(std::make_pair(a, b), std::make_pair(auv, buv));
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
        const double size = targetSize(patch.gf, midpointUv, midpointXyz,
                                       options);
        const Point ax = {a->x(), a->y(), a->z()};
        const Point bx = {b->x(), b->y(), b->z()};
        const double ratio = distance(ax, bx) / size;
        if(!std::isfinite(ratio) || !(ratio > 0.)) {
          score.admissible = false;
          continue;
        }
        score.minimumRatio = std::min(score.minimumRatio, ratio);
        score.maximumRatio = std::max(score.maximumRatio, ratio);
        if(ratio < options.minimumEdgeSizeRatio ||
           ratio > options.maximumEdgeSizeRatio)
          score.admissible = false;
        error += std::pow(std::log(ratio), 2);
      }
      score.meanSquaredLogRatio = error / static_cast<double>(edges.size());
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
      auto add = [&](const std::set<MElement *> &patchElements) {
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
        if(!patchFromElements(face, ordered, seed.patch) ||
           seed.patch.bdrVertices.size() != 1 ||
           seed.patch.bdrVertices.front().size() < 4 ||
           seed.patch.bdrVertices.front().size() > 20 ||
           seed.patch.bdrVertices.front().size() % 2 != 0 ||
           !seed.patch.embVertices.empty())
          return;
        seed.interiorVertexCount = seed.patch.intVertices.size();
        seed.alwaysTryTopology = true;
        seed.flexibleInteriorCount = true;
        seed.kind = kind;
        seed.objective = specificationObjective(seed.patch.elements);
        cacheCavityValence(seed, topology);
        cavities.push_back(std::move(seed));
      };

      auto expandAndAdd = [&](const std::vector<MElement *> &initial) {
        std::set<MElement *> patch(initial.begin(), initial.end());
        add(patch);
        for(int ring = 0; ring < options.maximumCleanUpCavityRings; ++ring) {
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
          add(patch);
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
          if(options.fastInteractiveCleanUp) {
            if(degree > 2 && degree < 6) continue;
          }
          else if(degree == 4)
            continue;
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
          if(options.fastInteractiveCleanUp ?
               std::abs(degree - ideal) > 1 : degree != ideal)
            expandAndAdd(topology.incidentElements(vertex));
        }
        // Figure 15: a boundary diamond has exactly one vertex on the model
        // boundary. Its one- and two-ring patches are tried; the spec and
        // valence objective decide whether collapse is safe.
        if(!options.fastInteractiveCleanUp) {
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
          if((criticalShapeOnly || options.fastInteractiveCleanUp) ?
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
          if(!a || !b || a->onWhat() != face || b->onWhat() != face)
            continue;
          SPoint2 auv, buv;
          if(!reparamMeshVertexOnFace(a, face, auv, true) ||
             !reparamMeshVertexOnFaceWithRef(face, b, auv, buv))
            continue;
          const UV midpointUv = {.5 * (auv.x() + buv.x()),
                                 .5 * (auv.y() + buv.y())};
          const Point midpointXyz = {.5 * (a->x() + b->x()),
                                     .5 * (a->y() + b->y()),
                                     .5 * (a->z() + b->z())};
          const double size = targetSize(face, midpointUv, midpointXyz,
                                         options);
          const Point ax = {a->x(), a->y(), a->z()};
          const Point bx = {b->x(), b->y(), b->z()};
          if(std::isfinite(size) && size > 0. &&
             distance(ax, bx) / size > options.cleanUpLongEdgeRatio)
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
      const Pattern &quadrangles, const std::vector<Point> &xyz)
    {
      SpecificationObjective objective;
      for(const auto &quad : quadrangles) {
        std::vector<Point> points(4);
        for(std::size_t i = 0; i < 4; ++i) points[i] = xyz[quad[i]];
        objective += specificationObjective(evaluateElementQuality(
          SurfaceElementKind::Quadrangle, points));
      }
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

    bool executeCandidate(GFace *face, const CavitySeed &seed,
                          const Candidate &candidate,
                          std::vector<MVertex *> *createdInterior = nullptr)
    {
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
      FaceHalfEdgeTopology validatedTopology;
      if(topology) {
        validatedTopology = *topology;
        if(!validatedTopology.replace(seed.patch.elements, newElements)) {
          for(MElement *element : newElements) delete element;
          for(MVertex *vertex : created) delete vertex;
          return false;
        }
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
                              const Adjacency &adjacency, CavitySeed &seed)
    {
      if(interior.empty()) return false;
      for(MVertex *vertex : interior)
        if(!vertex || vertex->onWhat() != face) return false;
      const std::vector<MElement *> patchElements =
        unionStars(interior, adjacency);
      if(patchElements.empty() ||
         !patchFromElements(face, patchElements, seed.patch) ||
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
                              CavitySeed &seed)
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
      if(!patchFromElements(face, patchElements, seed.patch) ||
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
        if(!vertex->getParameter(0, u) || !vertex->getParameter(1, v) ||
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

    ExistingSmoothingStatus smoothExistingCavity(
      GFace *face, CavitySeed &seed,
      const SmallCavityOptimizerOptions &options)
    {
      seed.objective = specificationObjective(seed.patch.elements);
      if(options.topologyOnlyIfCavityHasSpecificationFailure &&
         !hasQualitySpecificationFailure(seed.objective))
        return ExistingSmoothingStatus::SkippedSpecificationCompliant;
      std::vector<UV> uv;
      Pattern pattern;
      if(!existingPatternAndParametrization(seed, uv, pattern))
        return ExistingSmoothingStatus::Invalid;
      SmallCavityWinslowOptions winslowOptions = options.winslow;
      winslowOptions.harmonicInitialization = false;
      const std::size_t boundaryCount =
        seed.patch.bdrVertices.front().size();
      const SmallCavityWinslowResult winslow =
        optimizeSmallQuadCavityWinslow(uv, boundaryCount, pattern,
                                       winslowOptions);
      if(!winslow.success || !winslow.untangled)
        return ExistingSmoothingStatus::RejectedWinslow;
      std::vector<Point> xyz;
      if(!mapCandidate(face, boundaryCount,
                       seed.patch.bdrVertices.front(), uv, xyz))
        return ExistingSmoothingStatus::RejectedWinslow;
      if(options.enforceSizeMap) {
        const SizeScore beforeSize = existingSizeScore(seed.patch, options);
        const SizeScore afterSize =
          candidateSizeScore(face, uv, xyz, pattern, options);
        const double allowedSizeError = beforeSize.meanSquaredLogRatio *
          (1. + options.maximumRelativeSizeErrorIncrease) + 1.e-14;
        if(!afterSize.admissible ||
           (options.enforceRelativeSizeErrorIncrease &&
            std::isfinite(beforeSize.meanSquaredLogRatio) &&
            afterSize.meanSquaredLogRatio > allowedSizeError))
          return ExistingSmoothingStatus::RejectedSize;
      }
      const SpecificationObjective objective =
        candidateObjective(pattern, xyz);
      if(!improvesSpecificationObjective(
           objective, seed.objective, options.objectiveRelativeTolerance))
        return ExistingSmoothingStatus::RejectedQuality;
      applySmoothedGeometry(seed, uv, xyz);
      return ExistingSmoothingStatus::Accepted;
    }

    void smoothTopologyNeighborhood(
      GFace *face, const std::vector<MVertex *> &coreInterior,
      const SmallCavityOptimizerOptions &options,
      const FaceHalfEdgeTopology *topology = nullptr)
    {
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
        const std::vector<MVertex *> boundary = core.patch.bdrVertices.front();
        smoothExistingCavity(face, core, options);
        for(MVertex *vertex : boundary) {
          CavitySeed neighbor;
          const bool valid = topology ?
            interiorVertexCavity(face, {vertex}, *topology, neighbor) :
            interiorVertexCavity(face, {vertex}, adjacency, neighbor);
          if(valid)
            smoothExistingCavity(face, neighbor, options);
        }
      }
    }

    std::size_t smoothLocalVertexStars(
      GFace *face, const std::vector<MVertex *> &focusVertices,
      const SmallCavityOptimizerOptions &options,
      const FaceHalfEdgeTopology &topology)
    {
      std::set<MVertex *> unique(focusVertices.begin(), focusVertices.end());
      SmallCavityOptimizerOptions localOptions = options;
      // The current mesh is already untangled. A short solve on each modified
      // one-ring is enough to recover the Winslow equilibrium without turning
      // the interactive cleanup into a global nonlinear optimization.
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
          if(!vertex || vertex->onWhat() != face) continue;
          CavitySeed seed;
          if(!interiorVertexCavity(face, {vertex}, topology, seed)) continue;
          if(smoothExistingCavity(face, seed, localOptions) ==
             ExistingSmoothingStatus::Accepted)
            ++accepted;
        }
      }
      return accepted;
    }

    ExistingTopologyWinslowResult smoothAllInteriorVertexCavities(
      GFace *face, const SmallCavityOptimizerOptions &options)
    {
      ExistingTopologyWinslowResult result;
      if(!face || options.smoothingPasses < 0) {
        result.success = false;
        return result;
      }
      result.initialObjective = specificationObjective(surfaceElements(face));
      for(int pass = 0; pass < options.smoothingPasses; ++pass) {
        ++result.passes;
        const std::vector<MElement *> elements = surfaceElements(face);
        const Adjacency adjacency = buildAdjacency(elements);
        const std::vector<MVertex *> vertices = face->mesh_vertices;
        for(MVertex *vertex : vertices) {
          if(!vertex || vertex->onWhat() != face) continue;
          ++result.quadsVisited;
          CavitySeed seed;
          if(!interiorVertexCavity(face, {vertex}, adjacency, seed)) continue;
          const ExistingSmoothingStatus status =
            smoothExistingCavity(face, seed, options);
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
                    SmallCavityOptimizerResult &result)
    {
      ++result.diamondsVisited;
      const CavitySeed &seed = diamond.cavity;
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
      if(options.enforceSizeMap) {
        const SizeScore beforeSize = existingSizeScore(seed.patch, options);
        const SizeScore afterSize =
          candidateSizeScore(face, uv, xyz, quadrangles, options);
        const double allowedSizeError = beforeSize.meanSquaredLogRatio *
          (1. + options.maximumRelativeSizeErrorIncrease) + 1.e-14;
        if(!afterSize.admissible ||
           (options.enforceRelativeSizeErrorIncrease &&
            std::isfinite(beforeSize.meanSquaredLogRatio) &&
            afterSize.meanSquaredLogRatio > allowedSizeError)) {
          ++result.rejectedBySize;
          return false;
        }
      }
      const SpecificationObjective objective =
        candidateObjective(quadrangles, xyz);

      Candidate candidate;
      candidate.valid = true;
      candidate.uv = std::move(uv);
      candidate.xyz = std::move(xyz);
      candidate.quadrangles = std::move(quadrangles);
      candidate.interiorAssignment = {diamond.retainedInterior};
      candidate.objective = objective;
      std::vector<MVertex *> retainedInterior;
      if(!executeCandidate(face, seed, candidate, &retainedInterior))
        return false;
      smoothTopologyNeighborhood(face, retainedInterior, options);
      return true;
    }

    bool tryValenceSixCavity(
      GFace *face, const CavitySeed &seed,
      const SmallCavityOptimizerOptions &options,
      SmallCavityOptimizerResult &result)
    {
      ++result.valenceSixVerticesVisited;
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
      const SizeScore beforeSize = options.enforceSizeMap ?
        existingSizeScore(seed.patch, options) : SizeScore();
      SmallCavityWinslowOptions winslowOptions = options.winslow;
      winslowOptions.harmonicInitialization = false;
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
        if(options.enforceSizeMap) {
          size = candidateSizeScore(face, uv, xyz, quadrangles, options);
          const double allowedSizeError = beforeSize.meanSquaredLogRatio *
            (1. + options.maximumRelativeSizeErrorIncrease) + 1.e-14;
          if(!size.admissible ||
             (options.enforceRelativeSizeErrorIncrease &&
              std::isfinite(beforeSize.meanSquaredLogRatio) &&
              size.meanSquaredLogRatio > allowedSizeError)) {
            ++result.rejectedBySize;
            continue;
          }
        }
        const SpecificationObjective objective =
          candidateObjective(quadrangles, xyz);
        if(best.valid && !improvesSpecificationObjective(
             objective, best.objective,
             options.objectiveRelativeTolerance))
          continue;
        best.valid = true;
        best.uv = std::move(uv);
        best.xyz = std::move(xyz);
        best.quadrangles = std::move(quadrangles);
        best.objective = objective;
        best.sizeError = size.meanSquaredLogRatio;
      }
      if(!best.valid) return false;
      std::vector<MVertex *> interior;
      if(!executeValenceSixCandidate(face, seed, best, interior)) return false;
      smoothTopologyNeighborhood(face, interior, options);
      return true;
    }

    bool tryBoundaryTriangleQuadTriangleFan(
      GFace *face, const CavitySeed &seed,
      const SmallCavityOptimizerOptions &options,
      SmallCavityOptimizerResult &result)
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
      const SizeScore beforeSize = options.enforceSizeMap ?
        existingSizeScore(seed.patch, options) : SizeScore();
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
        SizeScore size;
        if(options.enforceSizeMap) {
          size = candidateSizeScore(face, uv, xyz, quadrangles, options);
          const double allowedSizeError = beforeSize.meanSquaredLogRatio *
            (1. + options.maximumRelativeSizeErrorIncrease) + 1.e-14;
          if(!size.admissible ||
             (options.enforceRelativeSizeErrorIncrease &&
              std::isfinite(beforeSize.meanSquaredLogRatio) &&
              size.meanSquaredLogRatio > allowedSizeError)) {
            ++result.rejectedBySize;
            continue;
          }
        }
        const SpecificationObjective objective =
          candidateObjective(quadrangles, xyz);
        if(best.valid && !improvesSpecificationObjective(
             objective, best.objective,
             options.objectiveRelativeTolerance))
          continue;
        best.valid = true;
        best.uv = std::move(uv);
        best.xyz = std::move(xyz);
        best.quadrangles = std::move(quadrangles);
        best.objective = objective;
        best.sizeError = size.meanSquaredLogRatio;
      }
      if(!best.valid) return false;
      MVertex *created = nullptr;
      if(!executeNewInteriorCandidate(face, seed, best, created)) return false;
      smoothTopologyNeighborhood(face, {created}, options);
      return true;
    }

    bool tryCavity(GFace *face, const CavitySeed &seed,
                   const SmallCavityOptimizerOptions &options,
                   SmallCavityOptimizerResult &result,
                   std::set<ConnectivitySignature> &topologyHistory)
    {
      ++result.cavitiesVisited;
      if(!seed.alwaysTryTopology &&
         options.topologyOnlyIfCavityHasSpecificationFailure &&
         !hasQuadFailingAbsoluteSpecifications(seed)) {
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
      const SizeScore beforeSize = options.enforceSizeMap ?
        existingSizeScore(seed.patch, options) : SizeScore();
      SmallCavityWinslowOptions winslowOptions = options.winslow;
      winslowOptions.harmonicInitialization = false;
      ConnectivitySignature existingConnectivity;
      const bool existingIsAllQuad =
        existingConnectivitySignature(seed.patch, existingConnectivity);
      ConnectivitySignature physicalExistingConnectivity;
      if(physicalExistingConnectivitySignature(
           seed.patch, physicalExistingConnectivity))
        topologyHistory.insert(physicalExistingConnectivity);
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
          const ConnectivitySignature physicalConnectivity =
            physicalCandidateConnectivitySignature(seed, quadrangles,
                                                    assignment);
          if((existingIsAllQuad && connectivity == existingConnectivity) ||
             topologyHistory.find(physicalConnectivity) !=
               topologyHistory.end() ||
             !triedConnectivity.insert(connectivity).second)
            continue;
          if(seed.kind == CavityKind::Edge &&
             !edgeSwapEdgesIntersect(seed, quadrangles, initial)) {
            ++result.rejectedEdgeSwapsNoIntersection;
            continue;
          }
          if(seed.kind == CavityKind::Edge &&
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
          if(options.enforceSizeMap) {
            size = candidateSizeScore(
              face, uv, xyz, quadrangles, options);
            const double allowedSizeError = beforeSize.meanSquaredLogRatio *
              (1. + options.maximumRelativeSizeErrorIncrease) + 1.e-14;
            if(!size.admissible ||
               (options.enforceRelativeSizeErrorIncrease &&
                std::isfinite(beforeSize.meanSquaredLogRatio) &&
                size.meanSquaredLogRatio > allowedSizeError)) {
              ++result.rejectedBySize;
              ++localSizeRejected;
              if(!size.admissible)
                ++localSizeBoundsRejected;
              else
                ++localSizeErrorRejected;
              continue;
            }
          }

          const SpecificationObjective objective =
            candidateObjective(quadrangles, xyz);
          if(!hasBestEvaluatedObjective || improvesSpecificationObjective(
               objective, bestEvaluatedObjective,
               options.objectiveRelativeTolerance)) {
            bestEvaluatedObjective = objective;
            hasBestEvaluatedObjective = true;
          }
          if(!improvesSpecificationObjective(
               objective, seed.objective,
               options.objectiveRelativeTolerance)) {
            ++result.rejectedByQuality;
            ++localQualityRejected;
            continue;
          }
          if(best.valid && !improvesSpecificationObjective(
               objective, best.objective,
               options.objectiveRelativeTolerance))
            continue;
          best.valid = true;
          best.uv = std::move(uv);
          best.xyz = std::move(xyz);
          best.quadrangles = quadrangles;
          best.interiorAssignment = assignment;
          best.objective = objective;
          best.sizeError = size.meanSquaredLogRatio;
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
      std::vector<MVertex *> createdInterior;
      if(!executeCandidate(face, seed, best, &createdInterior)) return false;
      topologyHistory.insert(physicalCandidateConnectivitySignature(
        seed, best.quadrangles, best.interiorAssignment));
      smoothTopologyNeighborhood(face, createdInterior, options);
      return true;
    }

    bool tryFlexibleCleanUpCavity(
      GFace *face, const CavitySeed &seed,
      const SmallCavityOptimizerOptions &options,
      SmallCavityOptimizerResult &result,
      FaceHalfEdgeTopology *topology,
      std::set<ConnectivitySignature> &topologyHistory)
    {
      ++result.cavitiesVisited;
      ++result.cleanUpCavitiesVisited;
      if(options.topologyOnlyIfCavityHasSpecificationFailure &&
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

      const SizeScore beforeSize = existingSizeScore(seed.patch, options);
      SmallCavityWinslowOptions winslowOptions = options.winslow;
      winslowOptions.harmonicInitialization = true;
      ConnectivitySignature existingConnectivity;
      const bool existingIsAllQuad =
        existingConnectivitySignature(seed.patch, existingConnectivity);
      ConnectivitySignature physicalExistingConnectivity;
      if(physicalExistingConnectivitySignature(
           seed.patch, physicalExistingConnectivity))
        topologyHistory.insert(physicalExistingConnectivity);
      std::set<ConnectivitySignature> triedConnectivity;
      const std::size_t createdMarker =
        std::numeric_limits<std::size_t>::max();

      auto admissible = [&](const Candidate &candidate) {
        const bool specificationImprovement = improvesSpecificationObjective(
          candidate.objective, seed.objective,
          options.objectiveRelativeTolerance);
        if(seed.kind == CavityKind::CleanUpShape)
          return specificationImprovement;
        if(seed.kind == CavityKind::CleanUpConnectivity ||
           seed.kind == CavityKind::CleanUpBoundary)
          return specificationImprovement ||
            (noWorseAbsoluteSpecifications(
               candidate.objective, seed.objective,
               options.objectiveRelativeTolerance) &&
             improvesValence(candidate.valence, seed.valence));
        if(seed.kind == CavityKind::CleanUpSize)
          return noWorseAbsoluteSpecifications(
                   candidate.objective, seed.objective,
                   options.objectiveRelativeTolerance) &&
                 std::isfinite(candidate.sizeError) &&
                 candidate.sizeError + 1.e-12 <
                   beforeSize.meanSquaredLogRatio;
        return specificationImprovement;
      };

      auto better = [&](const Candidate &candidate,
                        const Candidate &reference) {
        if(improvesSpecificationObjective(
             candidate.objective, reference.objective,
             options.objectiveRelativeTolerance))
          return true;
        if(improvesSpecificationObjective(
             reference.objective, candidate.objective,
             options.objectiveRelativeTolerance))
          return false;
        if(improvesValence(candidate.valence, reference.valence)) return true;
        if(improvesValence(reference.valence, candidate.valence)) return false;
        return candidate.sizeError < reference.sizeError;
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
      const int candidateBudget = options.fastInteractiveCleanUp ?
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
            const bool untangled = options.fastInteractiveCleanUp ?
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
            candidateSizeScore(face, uv, xyz, quadrangles, options);
          if((options.enforceSizeMap ||
              seed.kind == CavityKind::CleanUpSize) && !size.admissible) {
            ++result.rejectedBySize;
            continue;
          }

          Candidate candidate;
          candidate.valid = true;
          candidate.uv = std::move(uv);
          candidate.xyz = std::move(xyz);
          candidate.quadrangles = std::move(quadrangles);
          candidate.objective =
            candidateObjective(candidate.quadrangles, candidate.xyz);
          candidate.valence = candidatePatchValence(
            seed, candidate.quadrangles,
            static_cast<std::size_t>(interior));
          candidate.sizeError = size.meanSquaredLogRatio;
          candidate.interiorAssignment.resize(
            static_cast<std::size_t>(interior), createdMarker);
          const std::size_t retained = std::min(
            candidate.interiorAssignment.size(),
            seed.patch.intVertices.size());
          for(std::size_t i = 0; i < retained; ++i)
            candidate.interiorAssignment[i] = i;

          if(std::find(candidate.interiorAssignment.begin(),
                       candidate.interiorAssignment.end(), createdMarker) ==
             candidate.interiorAssignment.end()) {
            const ConnectivitySignature physicalConnectivity =
              physicalCandidateConnectivitySignature(
                seed, candidate.quadrangles,
                candidate.interiorAssignment);
            if(topologyHistory.find(physicalConnectivity) !=
               topologyHistory.end())
              continue;
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
      if(options.fastInteractiveCleanUp) {
        for(Candidate &candidate : screened) {
          if(!admissible(candidate)) {
            ++result.rejectedByQuality;
            continue;
          }
          best = std::move(candidate);
          break;
        }
      }
      const std::size_t refinementCount = std::min(
        screened.size(), options.fastInteractiveCleanUp ? 0 :
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
            options);
          if((options.enforceSizeMap ||
              seed.kind == CavityKind::CleanUpSize) && !size.admissible) {
            ++result.rejectedBySize;
            continue;
          }
          candidate.objective =
            candidateObjective(candidate.quadrangles, candidate.xyz);
          candidate.sizeError = size.meanSquaredLogRatio;
        }
        if(!admissible(candidate)) {
          ++result.rejectedByQuality;
          continue;
        }
        if(!best.valid || better(candidate, best))
          best = std::move(candidate);
      }
      if(!best.valid) return false;
      std::vector<MVertex *> interior;
      std::vector<MElement *> insertedElements;
      if(!executeFlexibleCandidate(face, seed, best, interior,
                                   &insertedElements, topology))
        return false;
      ConnectivitySignature insertedConnectivity;
      if(physicalElementsConnectivitySignature(insertedElements,
                                                insertedConnectivity))
        topologyHistory.insert(std::move(insertedConnectivity));
      if(options.fastInteractiveCleanUp) {
        std::vector<MVertex *> localVertices =
          seed.patch.bdrVertices.front();
        localVertices.insert(localVertices.end(), interior.begin(),
                             interior.end());
        result.acceptedFinalSmoothingCavities += smoothLocalVertexStars(
          face, localVertices, options, *topology);
      }
      else
        smoothTopologyNeighborhood(face, interior, options, topology);
      return true;
    }

  } // namespace

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
       !(options.minimumEdgeSizeRatio > 0.) ||
       !(options.maximumEdgeSizeRatio > options.minimumEdgeSizeRatio) ||
       options.maximumRelativeSizeErrorIncrease < 0.) {
      result.success = false;
      Msg::Error("QuadOptimizer: invalid small-cavity optimizer options");
      return result;
    }
    result.initialObjective = specificationObjective(surfaceElements(face));

    auto convertAllBoundaryTriangleQuadTriangleFans = [&]() -> std::size_t {
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
               face, fan, options, result)) {
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
                         "triangle-quad-triangle fans remain but none can be "
                         "untangled in parameter space",
                         fans.size());
          break;
        }
      }
      return accepted;
    };

    auto eliminateAllDiamonds = [&]() -> std::size_t {
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
          if(tryDiamond(face, diamond, options, result)) {
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
            Msg::Warning("QuadOptimizer: %zu diamonds remain but none can be "
                         "untangled in parameter space",
                         diamonds.size());
          break;
        }
      }
      return accepted;
    };

    std::set<ConnectivitySignature> topologyHistory;
    auto splitAllValenceSixVertices = [&]() -> std::size_t {
      if(!options.splitValenceSixVertices) return 0;
      std::size_t accepted = 0;
      while(accepted <
            static_cast<std::size_t>(options.maximumAcceptedCavities)) {
        const std::vector<CavitySeed> valenceSix =
          collectValenceSixCavities(face);
        bool changed = false;
        for(const CavitySeed &cavity : valenceSix) {
          if(tryValenceSixCavity(face, cavity, options, result)) {
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

    auto optimizeCavityStage = [&](CavityKind kind) -> std::size_t {
      std::size_t accepted = 0;
      while(accepted <
            static_cast<std::size_t>(options.maximumAcceptedCavities)) {
        const std::vector<CavitySeed> cavities =
          collectCavities(face, options, kind);
        bool changed = false;
        for(const CavitySeed &cavity : cavities) {
          if(tryCavity(face, cavity, options, result, topologyHistory)) {
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

    auto optimizeCleanUpStage = [&](CavityKind kind, bool enabled,
                                    bool criticalShapeOnly = false)
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
                                       &topology, topologyHistory))
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
        }
        if(acceptedInWave == 0) break;
        if(options.fastInteractiveCleanUp) break;
      }
      return accepted;
    };

    auto timedCleanUpStage = [&](CavityKind kind, bool enabled,
                                 bool criticalShapeOnly,
                                 double &seconds) -> std::size_t {
      const auto start = std::chrono::steady_clock::now();
      const std::size_t accepted = optimizeCleanUpStage(
        kind, enabled, criticalShapeOnly);
      seconds += std::chrono::duration<double>(
        std::chrono::steady_clock::now() - start).count();
      return accepted;
    };

    // Kinney processes chevrons and bowties before connectivity cleanup: a
    // connectivity edit around a twisted quad tends to make it worse. The
    // generalized shape collector also catches ordinary >160 degree cases.
    timedCleanUpStage(CavityKind::CleanUpShape, options.cleanUpShape,
                      true, result.cleanUpCriticalSeconds);

    const int cleanupPasses = options.maximumOptimizationPasses;
    for(int pass = 0; pass < cleanupPasses; ++pass) {
      ++result.passes;
      std::size_t topologyChanges = 0;
      // CleanUp order: connectivity, boundary, shape and size. Existing
      // specialized operations are retained as fast paths within the same
      // pass; flexible disk remeshing supplies fill_2/fill_3/fill_4 and the
      // larger examples from the paper.
      if(!options.fastInteractiveCleanUp)
        topologyChanges += splitAllValenceSixVertices();
      topologyChanges += timedCleanUpStage(
        CavityKind::CleanUpConnectivity, options.cleanUpConnectivity,
        false, result.cleanUpConnectivitySeconds);
      if(!options.fastInteractiveCleanUp) {
        topologyChanges += optimizeCavityStage(CavityKind::Node);
        topologyChanges += optimizeCavityStage(CavityKind::Edge);
        topologyChanges += eliminateAllDiamonds();
        topologyChanges += convertAllBoundaryTriangleQuadTriangleFans();
      }
      topologyChanges += timedCleanUpStage(
        CavityKind::CleanUpBoundary, options.cleanUpBoundary, false,
        result.cleanUpBoundarySeconds);
      if(!options.fastInteractiveCleanUp) {
        topologyChanges += optimizeCavityStage(CavityKind::Triangle);
        topologyChanges += optimizeCavityStage(CavityKind::Quadrangle);
      }
      topologyChanges += timedCleanUpStage(
        CavityKind::CleanUpShape, options.cleanUpShape, false,
        result.cleanUpShapeSeconds);
      topologyChanges += timedCleanUpStage(
        CavityKind::CleanUpSize, options.cleanUpSize, false,
        result.cleanUpSizeSeconds);

      if(!options.fastInteractiveCleanUp &&
         options.finalSmoothingPasses > 0) {
        SmallCavityOptimizerOptions smoothingOptions = options;
        smoothingOptions.smoothingPasses = options.finalSmoothingPasses;
        const ExistingTopologyWinslowResult smoothing =
          smoothAllInteriorVertexCavities(face, smoothingOptions);
        if(!smoothing.success) {
          result.success = false;
          return result;
        }
        result.acceptedFinalSmoothingCavities +=
          smoothing.acceptedCavities;
        if(options.verbose)
          Msg::Info("QuadOptimizer: pass=%d topology changes=%zu smoothing "
                    "passes=%zu accepted=%zu",
                    pass + 1, topologyChanges, smoothing.passes,
                    smoothing.acceptedCavities);
      }
      if(topologyChanges == 0) break;
    }
    result.finalObjective = specificationObjective(surfaceElements(face));
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
       !(options.minimumEdgeSizeRatio > 0.) ||
       !(options.maximumEdgeSizeRatio > options.minimumEdgeSizeRatio) ||
       options.maximumRelativeSizeErrorIncrease < 0.) {
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
    SmallCavityOptimizerOptions parallelOptions = options;
    parallelOptions.invalidateVertexArrays = false;
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
      if(options.verbose)
        Msg::Info("QuadOptimizer face %d timing(s): critical=%.6g "
                  "connectivity=%.6g boundary=%.6g shape=%.6g size=%.6g; "
                  "accepted=%zu/%zu/%zu/%zu",
                  face.faceTag,
                  face.optimizer.cleanUpCriticalSeconds,
                  face.optimizer.cleanUpConnectivitySeconds,
                  face.optimizer.cleanUpBoundarySeconds,
                  face.optimizer.cleanUpShapeSeconds,
                  face.optimizer.cleanUpSizeSeconds,
                  face.optimizer.cleanUpConnectivityAccepted,
                  face.optimizer.cleanUpBoundaryAccepted,
                  face.optimizer.cleanUpShapeAccepted,
                  face.optimizer.cleanUpSizeAccepted);
      result.success = result.success && face.optimizer.success;
      result.acceptedCavities +=
        face.optimizer.acceptedDiamonds +
        face.optimizer.acceptedValenceSixSplits +
        face.optimizer.acceptedBoundaryTriangleQuadTriangleFans +
        face.optimizer.acceptedEdgeSwaps +
        face.optimizer.acceptedOneInteriorVertexCavities +
        face.optimizer.acceptedThreeInteriorVertexCavities +
        face.optimizer.acceptedFourInteriorVertexCavities +
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

} // namespace QuadOptimizer
