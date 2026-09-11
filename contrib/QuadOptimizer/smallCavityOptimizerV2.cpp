// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.

#include "smallCavityOptimizerV2.h"

#include "GFace.h"
#include "GEdge.h"
#include "GVertex.h"
#include "BackgroundMeshTools.h"
#include "discreteFace.h"
#include "quadGeometryGuard.h"
#include "quadQualityLedger.h"
#include "quadCadDistance.h"
#include "quadSmartLaplacian.h"
#include "SPoint3.h"
#include "GModel.h"
#include "GPoint.h"
#include "GmshMessage.h"
#include "MElement.h"
#include "MQuadrangle.h"
#include "MTriangle.h"
#include "MVertex.h"
#include "SPoint2.h"
#include "SVector3.h"
#include "halfEdge.h"
#include "halfEdgeRewriteCatalog.h"
#include "quadPatchSearch.h"

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
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <tuple>
#include <vector>

namespace QuadOptimizer {
  namespace {
    using Id = FaceHalfEdge::Id;
    using UV = std::array<double, 2>;
    using Point = std::array<double, 3>;
    using Cell = std::vector<std::size_t>;

    enum class Rule : std::uint64_t {
      InteriorStar = 1,
      InteriorQQTQQT,
      ValenceSix,
      BoundaryFan,
      TriangleStrip,
      Diamond,
      QuadQuad,
      QuadTriangle,
      TriangleTriangle,
      RepairPatch,
      ComposedTriangleReduction,
      InteriorTQTQQ,
      InvalidPatch
    };

    struct VertexSpec {
      MVertex *vertex = nullptr;
      UV uv = {{0., 0.}};
      Point xyz = {{0., 0., 0.}};
    };

    struct Candidate {
      std::vector<VertexSpec> vertices;
      std::vector<Cell> cells;
      const char *name = "";
    };

    struct Score {
      SpecificationObjective shape;
      QualityLedger criteria;
      CadDistance::Contribution cad;
      std::size_t invalid = 0;
      // Reliable physical defects, excluding unavailable CAD/UV samples and
      // specification-only failures such as the absolute warping threshold.
      std::size_t physicalInvalid = 0;
      std::size_t incompleteOrientation = 0;
      std::size_t sizeViolations = 0;
      std::size_t triangles = 0;
      double maximumAngularDeviation = 0.;
      double worstSizeViolation = 0.;
      double sizePenalty = 0.;
      std::size_t belowMinimum = 0, aboveMaximum = 0, invalidSize = 0;
      double minimumLength = std::numeric_limits<double>::infinity();
      double maximumLength = 0.;
      double cadNormalizedMeanSquared = 0.;
      double cadNormalizedMaximum = 0.;
      double cadWeight = 0.;
    };

    struct BuiltCandidate {
      std::vector<std::unique_ptr<MVertex> > newVertices;
      std::vector<std::unique_ptr<MElement> > elements;
      std::vector<MElement *> elementPointers;
      std::unordered_map<MVertex *, UV> parameters;
      FaceHalfEdge::PreparedReplacement replacement;
    };

    std::uint64_t hashIds(std::vector<Id> ids)
    {
      std::sort(ids.begin(), ids.end());
      std::uint64_t hash = 1469598103934665603ull;
      for(const Id id : ids) {
        hash ^= static_cast<std::uint64_t>(id);
        hash *= 1099511628211ull;
      }
      return hash;
    }

    std::uint64_t attemptKey(Rule rule,
                             const FaceHalfEdge::Cavity &cavity)
    {
      std::uint64_t hash = hashIds(cavity.cells);
      hash ^= static_cast<std::uint64_t>(rule) +
        0x9e3779b97f4a7c15ull + (hash << 6) + (hash >> 2);
      return hash;
    }

    Point point(MVertex *vertex)
    {
      return {{vertex->x(), vertex->y(), vertex->z()}};
    }

    Point subtract(const Point &a, const Point &b)
    {
      return {{a[0] - b[0], a[1] - b[1], a[2] - b[2]}};
    }

    Point cross(const Point &a, const Point &b)
    {
      return {{a[1] * b[2] - a[2] * b[1],
               a[2] * b[0] - a[0] * b[2],
               a[0] * b[1] - a[1] * b[0]}};
    }

    double dot(const Point &a, const Point &b)
    {
      return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
    }

    double squaredDistance(const Point &a, const Point &b)
    {
      const Point difference = subtract(a, b);
      return dot(difference, difference);
    }

    double edgeLength(MVertex *a, MVertex *b)
    {
      return std::sqrt(squaredDistance(point(a), point(b)));
    }

    struct OrientationRepair {
      bool regular = true;
      std::size_t reversed = 0;
      std::size_t valenceTwoQuadsSplit = 0;
    };

    // Establish coherent half-edge directions before constructing the
    // persistent topology. The dual-graph propagation is purely
    // combinatorial. Reliable physical Jacobian/normal samples vote on the
    // component sign: a single center normal can disagree with a curved face.
    OrientationRepair orientFaceComponents(GFace *face)
    {
      struct Incidence {
        MElement *element = nullptr;
        MVertex *from = nullptr;
        MVertex *to = nullptr;
      };
      struct Constraint {
        MElement *element = nullptr;
        bool different = false;
      };
      using VertexEdge = std::pair<MVertex *, MVertex *>;
      const auto edge = [](MVertex *a, MVertex *b) {
        if(std::less<MVertex *>()(b, a)) std::swap(a, b);
        return VertexEdge(a, b);
      };

      OrientationRepair result;
      if(!face) {
        result.regular = false;
        return result;
      }
      std::vector<MElement *> elements;
      elements.insert(elements.end(), face->triangles.begin(),
                      face->triangles.end());
      elements.insert(elements.end(), face->quadrangles.begin(),
                      face->quadrangles.end());
      std::map<VertexEdge, std::vector<Incidence> > incidences;
      std::map<MVertex *, std::set<MElement *> > vertexStars;
      std::set<MElement *> uniqueElements;
      for(MElement *element : elements) {
        if(!element || !uniqueElements.insert(element).second) {
          result.regular = false;
          return result;
        }
        const std::size_t count = element->getNumPrimaryVertices();
        if(count != 3 && count != 4) {
          result.regular = false;
          return result;
        }
        std::set<MVertex *> uniqueVertices;
        for(std::size_t i = 0; i < count; ++i) {
          MVertex *from = element->getVertex(static_cast<int>(i));
          MVertex *to =
            element->getVertex(static_cast<int>((i + 1) % count));
          if(!from || !to || !uniqueVertices.insert(from).second) {
            result.regular = false;
            return result;
          }
          vertexStars[from].insert(element);
          incidences[edge(from, to)].push_back({element, from, to});
        }
      }

      // Edge manifoldness alone does not reject a bow-tie vertex. Validate
      // each orientation-independent vertex link before changing a single
      // Gmsh element, so malformed input is left bit-for-bit untouched.
      std::map<MVertex *, std::vector<VertexEdge> > vertexEdges;
      for(const auto &entry : incidences) {
        vertexEdges[entry.first.first].push_back(entry.first);
        vertexEdges[entry.first.second].push_back(entry.first);
      }
      for(const auto &starEntry : vertexStars) {
        MVertex *vertex = starEntry.first;
        const std::set<MElement *> &star = starEntry.second;
        std::map<MElement *, std::set<MElement *> > link;
        std::size_t boundarySides = 0;
        for(MElement *element : star) link[element];
        for(const VertexEdge &key : vertexEdges[vertex]) {
          const auto edgeEntry = incidences.find(key);
          const auto &edgeIncidences = edgeEntry->second;
          if(edgeIncidences.size() == 1) {
            ++boundarySides;
          }
          else if(edgeIncidences.size() == 2) {
            MElement *a = edgeIncidences[0].element;
            MElement *b = edgeIncidences[1].element;
            link[a].insert(b);
            link[b].insert(a);
          }
          else {
            result.regular = false;
            return result;
          }
        }
        std::set<MElement *> reached;
        std::vector<MElement *> pending(1, *star.begin());
        while(!pending.empty()) {
          MElement *element = pending.back();
          pending.pop_back();
          if(!reached.insert(element).second) continue;
          for(MElement *neighbor : link[element]) pending.push_back(neighbor);
        }
        const bool fixedCad = vertex->onWhat() && vertex->onWhat()->dim() < 2;
        if(reached.size() != star.size() && !fixedCad) {
          result.regular = false;
          return result;
        }
        if(boundarySides == 0) {
          for(const auto &entry : link)
            if(entry.second.size() != 2) {
              result.regular = false;
              return result;
            }
        }
        else {
          if(boundarySides != 2 && !fixedCad) {
            result.regular = false;
            return result;
          }
          std::size_t endpoints = 0;
          for(const auto &entry : link) {
            if(star.size() == 1 || (fixedCad && entry.second.empty())) {
              if(!entry.second.empty()) {
                result.regular = false;
                return result;
              }
            }
            else if(entry.second.size() == 1)
              ++endpoints;
            else if(entry.second.size() != 2) {
              result.regular = false;
              return result;
            }
          }
          std::size_t isolated = 0;
          for(const auto &entry : link) if(entry.second.empty()) ++isolated;
          if(star.size() > 1 && (fixedCad ? endpoints + 2 * isolated != boundarySides : endpoints != 2)) {
            result.regular = false;
            return result;
          }
        }
      }

      std::map<MElement *, std::vector<Constraint> > graph;
      for(const auto &entry : incidences) {
        if(entry.second.size() > 2) {
          result.regular = false;
          return result;
        }
        if(entry.second.size() != 2) continue;
        const Incidence &a = entry.second[0];
        const Incidence &b = entry.second[1];
        if(a.element == b.element) {
          result.regular = false;
          return result;
        }
        const bool sameDirection = a.from == b.from && a.to == b.to;
        graph[a.element].push_back({b.element, sameDirection});
        graph[b.element].push_back({a.element, sameDirection});
      }

      auto cadSign = [&](MElement *element) {
        std::vector<UV> uv(element->getNumPrimaryVertices());
        for(std::size_t i = 0; i < uv.size(); ++i) {
          MVertex *vertex = element->getVertex(static_cast<int>(i));
          double u = 0., v = 0.;
          bool known = vertex->onWhat() == face &&
            vertex->getParameter(0, u) && vertex->getParameter(1, v);
          if(!known) {
            SPoint2 parameter;
            if(face->geomType() == GEntity::DiscreteSurface)
              parameter = face->parFromPoint(vertex->point(), true, true);
            else if(!reparamMeshVertexOnFace(
                      vertex, face, parameter, true, false))
              return 0;
            u = parameter.x();
            v = parameter.y();
          }
          if(!std::isfinite(u) || !std::isfinite(v)) return 0;
          uv[i] = {{u, v}};
        }
        for(int direction = 0; direction < 2; ++direction) {
          if(!face->periodic(direction)) continue;
          const double period = std::abs(face->period(direction));
          if(!(period > 0.) || !std::isfinite(period)) return 0;
          for(std::size_t i = 1; i < uv.size(); ++i)
            uv[i][direction] +=
              std::round((uv[0][direction] - uv[i][direction]) / period) *
              period;
        }
        std::vector<Point> xyz;
        for(std::size_t i = 0; i < uv.size(); ++i)
          xyz.push_back(point(element->getVertex(i)));
        std::vector<std::array<std::size_t, 3> > triangles;
        std::vector<std::array<std::size_t, 4> > quads;
        if(uv.size() == 3) triangles.push_back({{0, 1, 2}});
        else quads.push_back({{0, 1, 2, 3}});
        int vote = 0;
        GeometryGuard::indexedPatchFollowsNormals(
          [&](const UV &parameter, const Point &jacobian,
              double jacobianNorm, double physicalScale2) {
            if(!std::isfinite(jacobianNorm) ||
               jacobianNorm <= 1.e-12 * physicalScale2) return 0;
            try {
              const SPoint2 sample(parameter[0], parameter[1]);
              SVector3 normal;
              if(auto *discrete = dynamic_cast<discreteFace *>(face)) {
                if(!discrete->normalIfContainsParam(sample, normal)) return 0;
              }
              else {
                if(!face->containsParam(sample)) return 0;
                normal = face->normal(sample);
              }
              const Point n = {{normal.x(), normal.y(), normal.z()}};
              const double scale = jacobianNorm * std::sqrt(dot(n, n));
              const double product = dot(jacobian, n);
              if(!(scale > 0.) || !std::isfinite(scale) || !std::isfinite(product)) return 0;
              if(product > 1.e-10 * scale) ++vote;
              else if(product < -1.e-10 * scale) --vote;
              // Accumulate every reliable sample; do not short-circuit on
              // a negative sample during component orientation selection.
              return 1;
            }
            catch(...) { return 0; }
          }, uv, xyz, triangles, quads);
        return vote;
      };

      std::map<MElement *, bool> relativeFlip;
      std::vector<MElement *> reverse;
      for(MElement *root : elements) {
        if(relativeFlip.find(root) != relativeFlip.end()) continue;
        std::queue<MElement *> pending;
        std::vector<MElement *> component;
        relativeFlip[root] = false;
        pending.push(root);
        std::size_t preliminaryFlips = 0;
        while(!pending.empty()) {
          MElement *current = pending.front();
          pending.pop();
          component.push_back(current);
          if(relativeFlip[current]) ++preliminaryFlips;
          for(const Constraint &constraint : graph[current]) {
            const bool expected =
              relativeFlip[current] != constraint.different;
            const auto known = relativeFlip.find(constraint.element);
            if(known == relativeFlip.end()) {
              relativeFlip[constraint.element] = expected;
              pending.push(constraint.element);
            }
            else if(known->second != expected) {
              result.regular = false;
              return result;
            }
          }
        }
        bool complement = preliminaryFlips >
          component.size() - preliminaryFlips;
        int componentVote = 0;
        for(MElement *element : component) {
          const int vote = cadSign(element);
          componentVote += relativeFlip[element] ? -vote : vote;
        }
        if(componentVote) complement = componentVote < 0;
        for(MElement *element : component)
          if(relativeFlip[element] != complement) reverse.push_back(element);
      }
      for(MElement *element : reverse) element->reverse();
      result.reversed = reverse.size();
      return result;
    }

    OrientationRepair prepareFaceComponents(GFace *face)
    {
      auto result = orientFaceComponents(face);
      if(result.regular || !face) return result;
      // Raw recombination can leave a fixed CAD pole with just two incident
      // cells sharing its two sides. Our rewrite complex requires at least
      // three cells around an interior pole. Split one quad through the pole
      // rather than dropping the CAD vertex or skipping the entire face.
      std::map<MVertex *, std::vector<MElement *> > stars;
      std::set<std::pair<MVertex *, MVertex *> > edges;
      const auto key = [](MVertex *a, MVertex *b) {
        if(std::less<MVertex *>()(b, a)) std::swap(a, b);
        return std::make_pair(a, b);
      };
      std::vector<MElement *> elements(face->triangles.begin(), face->triangles.end());
      elements.insert(elements.end(), face->quadrangles.begin(), face->quadrangles.end());
      for(MElement *element : elements) {
        const int n = element->getNumPrimaryVertices();
        for(int i = 0; i < n; ++i) {
          MVertex *v = element->getVertex(i);
          stars[v].push_back(element);
          edges.insert(key(v, element->getVertex((i + 1) % n)));
        }
      }
      std::map<MQuadrangle *, int> cuts;
      // A curved discrete chart can fold the physical chords of two disjoint
      // cells onto the same side of their shared segments. Keep the physical
      // proof below, with a stricter native-chart proof for that case only.
      using VertexCell = std::vector<MVertex *>;
      struct DiscreteStarProof {
        std::array<MElement *, 2> elements;
        std::array<int, 2> winding;
        int uvSign = 0;
      };
      std::vector<DiscreteStarProof> discreteProofs;
      std::map<MVertex *, UV> parameters;
      auto *discrete = dynamic_cast<discreteFace *>(face);
      const auto parameter = [&](MVertex *vertex) {
        if(parameters.count(vertex)) return true;
        UV uv;
        try {
          if(!(vertex->onWhat() == face && vertex->getParameter(0, uv[0]) &&
               vertex->getParameter(1, uv[1]))) {
            const SPoint2 p = face->parFromPoint(vertex->point(), true, true);
            uv = {{p.x(), p.y()}};
          }
        }
        catch(...) { return false; }
        if(!std::isfinite(uv[0]) || !std::isfinite(uv[1])) return false;
        parameters.emplace(vertex, uv);
        return true;
      };
      const auto area = [&](MVertex *a, MVertex *b, MVertex *c) {
        return GeometryGuard::localOrientationCross2(
          parameters.at(a), parameters.at(b), parameters.at(c));
      };
      const auto uvTolerance = [&](const VertexCell &vertices) {
        double scale2 = 0.;
        for(MVertex *a : vertices)
          for(MVertex *b : vertices) {
            const UV &u = parameters.at(a), &v = parameters.at(b);
            scale2 = std::max(scale2,
              (u[0] - v[0]) * (u[0] - v[0]) +
              (u[1] - v[1]) * (u[1] - v[1]));
          }
        return 1.e-12 * scale2;
      };
      const auto physicalSign = [&](const VertexCell &vertices) {
        std::vector<UV> uv;
        std::vector<Point> xyz;
        for(MVertex *vertex : vertices) {
          uv.push_back(parameters.at(vertex));
          xyz.push_back(point(vertex));
        }
        std::vector<std::array<std::size_t, 3> > triangles;
        std::vector<std::array<std::size_t, 4> > quadrangles;
        if(vertices.size() == 3) triangles.push_back({{0, 1, 2}});
        else if(vertices.size() == 4) quadrangles.push_back({{0, 1, 2, 3}});
        else return 0;
        int sign = 0;
        bool complete = true;
        std::size_t samples = 0;
        const bool regular = GeometryGuard::indexedPatchFollowsNormals(
          [&](const UV &uv, const Point &jacobian, double norm, double scale2) {
            ++samples;
            int sampleSign = 0;
            try {
              SVector3 normal;
              if(std::isfinite(norm) && norm > 1.e-12 * scale2 &&
                 discrete->normalIfContainsParam(SPoint2(uv[0], uv[1]), normal)) {
                const Point n = {{normal.x(), normal.y(), normal.z()}};
                const double normalNorm = std::sqrt(dot(n, n));
                const double product = dot(jacobian, n);
                const double tolerance = 1.e-10 * norm * normalNorm;
                if(std::isfinite(normalNorm) && normalNorm > 0. &&
                   std::isfinite(product)) {
                  if(product > tolerance) sampleSign = 1;
                  else if(product < -tolerance) sampleSign = -1;
                }
              }
            }
            catch(...) {}
            if(!sampleSign || (sign && sign != sampleSign)) complete = false;
            if(sampleSign) sign = sampleSign;
            // Visit every sample, including after an opposed or unavailable
            // one. Source winding may be reversed, but may not be mixed.
            return 1;
          }, uv, xyz, triangles, quadrangles);
        return regular && complete &&
          samples == (vertices.size() == 3 ? 4 : 8) ? sign : 0;
      };
      const auto validCell = [&](const VertexCell &vertices, int winding,
                                 int uvSign) {
        const double tolerance = uvTolerance(vertices);
        if(!(tolerance > 0.)) return false;
        for(std::size_t i = 0; i < vertices.size(); ++i)
          if(!(winding * uvSign * area(vertices[i],
                vertices[(i + 1) % vertices.size()],
                vertices[(i + 2) % vertices.size()]) > tolerance)) return false;
        return physicalSign(vertices) == winding;
      };
      const auto validStagedCell = [&](MElement *element, int cut,
                                       int winding, int uvSign) {
        const int n = element->getNumPrimaryVertices();
        if(cut < 0) {
          VertexCell vertices;
          for(int i = 0; i < n; ++i) vertices.push_back(element->getVertex(i));
          return validCell(vertices, winding, uvSign);
        }
        if(n != 4) return false;
        for(int j = 1; j <= 2; ++j)
          if(!validCell({element->getVertex(cut),
                         element->getVertex((cut + j) % 4),
                         element->getVertex((cut + j + 1) % 4)},
                        winding, uvSign)) return false;
        return true;
      };
      for(const auto &entry : stars) {
        MVertex *pole = entry.first;
        if(entry.second.size() != 2 || !pole->onWhat() ||
           pole->onWhat()->dim() >= 2) continue;
        std::array<std::set<MVertex *>, 2> sides;
        for(int k = 0; k < 2; ++k) {
          MElement *element = entry.second[k];
          const int n = element->getNumPrimaryVertices();
          for(int i = 0; i < n; ++i)
            if(element->getVertex(i) == pole) {
              sides[k].insert(element->getVertex((i + 1) % n));
              sides[k].insert(element->getVertex((i + n - 1) % n));
            }
        }
        if(sides[0].size() != 2 || sides[0] != sides[1]) continue;
        // Splitting a shared two-edge chain can hide overlapping input.
        // Before staging any cut, prove that both cells occupy opposite
        // physical sides of each shared segment.
        std::array<Point, 2> interior;
        for(int k = 0; k < 2; ++k) {
          MElement *element = entry.second[k];
          if(element->getNumPrimaryVertices() == 3) {
            interior[k] = {{0., 0., 0.}};
            for(int i = 0; i < 3; ++i) {
              const Point p = point(element->getVertex(i));
              for(int d = 0; d < 3; ++d) interior[k][d] += p[d] / 3.;
            }
          }
          else {
            for(int i = 0; i < 4; ++i)
              if(element->getVertex(i) == pole)
                interior[k] = point(element->getVertex((i + 2) % 4));
          }
        }
        bool physicalSides = true;
        for(MVertex *end : sides[0]) {
          const Point segment = subtract(point(end), point(pole));
          const Point a = cross(segment, subtract(interior[0], point(pole)));
          const Point b = cross(segment, subtract(interior[1], point(pole)));
          const double scale = std::sqrt(dot(a, a) * dot(b, b));
          if(!(scale > 0.) || !std::isfinite(scale) ||
             !(dot(a, b) < -1.e-12 * scale)) physicalSides = false;
        }
        DiscreteStarProof proof;
        if(!physicalSides) {
          if(!discrete || !discrete->haveParametrization() ||
             face->periodic(0) || face->periodic(1)) return result;
          std::array<std::vector<VertexCell>, 2> fans;
          std::set<MVertex *> vertices;
          for(int k = 0; k < 2; ++k) {
            MElement *element = proof.elements[k] = entry.second[k];
            const int n = element->getNumPrimaryVertices();
            if((n != 3 && n != 4) || element->getNumVertices() != n) return result;
            int corner = -1;
            for(int i = 0; i < n; ++i) {
              MVertex *vertex = element->getVertex(i);
              if(!parameter(vertex)) return result;
              vertices.insert(vertex);
              if(vertex == pole) corner = i;
            }
            if(corner < 0) return result;
            proof.winding[k] = 0;
            for(int j = 1; j + 1 < n; ++j) {
              VertexCell triangle = {pole, element->getVertex((corner + j) % n),
                                    element->getVertex((corner + j + 1) % n)};
              const int sign = physicalSign(triangle);
              if(!sign || (proof.winding[k] && proof.winding[k] != sign)) return result;
              proof.winding[k] = sign;
              if(sign < 0) std::swap(triangle[1], triangle[2]);
              const double signedArea = area(triangle[0], triangle[1], triangle[2]);
              if(!(std::abs(signedArea) > uvTolerance(triangle))) return result;
              const int uvSign = signedArea > 0. ? 1 : -1;
              if(proof.uvSign && proof.uvSign != uvSign) return result;
              proof.uvSign = uvSign;
              fans[k].push_back(triangle);
            }
          }
          // The cells may share only the pole and its two neighbors.
          if(vertices.size() != static_cast<std::size_t>(
               entry.second[0]->getNumPrimaryVertices() +
               entry.second[1]->getNumPrimaryVertices() - 3)) return result;
          for(MVertex *end : sides[0]) {
            std::array<double, 2> side = {{0., 0.}};
            for(int k = 0; k < 2; ++k)
              for(const VertexCell &triangle : fans[k])
                for(int i = 1; i <= 2; ++i)
                  if(triangle[i] == end)
                    side[k] = area(pole, end, triangle[3 - i]);
            if(!((side[0] > 0. && side[1] < 0.) ||
                 (side[0] < 0. && side[1] > 0.))) return result;
          }
          // The complete, coherently oriented fan must have one simple outer
          // rim with the pole strictly inside. This excludes folded or
          // overlapping UV stars even when individual samples look valid.
          std::map<MVertex *, MVertex *> next;
          std::map<std::pair<MVertex *, MVertex *>, int> radial;
          for(const auto &fan : fans)
            for(const VertexCell &triangle : fan) {
              if(!next.emplace(triangle[1], triangle[2]).second) return result;
              ++radial[{pole, triangle[1]}];
              ++radial[{triangle[2], pole}];
            }
          for(MVertex *vertex : vertices)
            if(vertex != pole &&
               (radial[{pole, vertex}] != 1 || radial[{vertex, pole}] != 1)) return result;
          if(next.size() + 1 != vertices.size()) return result;
          VertexCell rim;
          MVertex *vertex = next.begin()->first;
          do {
            if(rim.size() >= next.size() || !next.count(vertex)) return result;
            rim.push_back(vertex);
            vertex = next.at(vertex);
          } while(vertex != rim.front());
          if(rim.size() != next.size()) return result;
          const double tolerance = uvTolerance(rim);
          const double lengthTolerance = std::sqrt(tolerance);
          const auto direction = [&](double a) {
            return a > tolerance ? 1 : a < -tolerance ? -1 : 0;
          };
          for(std::size_t i = 0; i < rim.size(); ++i)
            for(std::size_t j = i + 1; j < rim.size(); ++j) {
              if(j == i + 1 || (i == 0 && j + 1 == rim.size())) continue;
              MVertex *a = rim[i], *b = rim[(i + 1) % rim.size()];
              MVertex *c = rim[j], *d = rim[(j + 1) % rim.size()];
              bool boxesOverlap = true;
              for(int axis = 0; axis < 2; ++axis)
                if(std::max(parameters.at(a)[axis], parameters.at(b)[axis]) <
                     std::min(parameters.at(c)[axis], parameters.at(d)[axis]) - lengthTolerance ||
                   std::max(parameters.at(c)[axis], parameters.at(d)[axis]) <
                     std::min(parameters.at(a)[axis], parameters.at(b)[axis]) - lengthTolerance)
                  boxesOverlap = false;
              if(boxesOverlap && direction(area(a, b, c)) * direction(area(a, b, d)) <= 0 &&
                 direction(area(c, d, a)) * direction(area(c, d, b)) <= 0) return result;
            }
          bool inside = false;
          const UV &p = parameters.at(pole);
          for(std::size_t i = 0; i < rim.size(); ++i) {
            const UV &a = parameters.at(rim[i]);
            const UV &b = parameters.at(rim[(i + 1) % rim.size()]);
            if((a[1] > p[1]) != (b[1] > p[1]) &&
               p[0] < (b[0] - a[0]) * (p[1] - a[1]) / (b[1] - a[1]) + a[0])
              inside = !inside;
          }
          if(!inside) return result;
        }
        MQuadrangle *best = nullptr;
        int corner = -1;
        double bestAngle = -1.;
        for(MElement *element : entry.second) {
          auto *quad = dynamic_cast<MQuadrangle *>(element);
          if(!quad || quad->getNumVertices() != 4) continue;
          for(int i = 0; i < 4; ++i) {
            if(quad->getVertex(i) != pole ||
               edges.count(key(pole, quad->getVertex((i + 2) % 4)))) continue;
            if(!physicalSides) {
              const auto existing = cuts.find(quad);
              if(existing != cuts.end() && (existing->second % 2) != (i % 2)) continue;
              bool valid = true;
              for(int k = 0; k < 2; ++k) {
                auto *other = dynamic_cast<MQuadrangle *>(proof.elements[k]);
                const auto cut = cuts.find(other);
                const int stagedCut = other == quad ? i :
                  cut == cuts.end() ? -1 : cut->second;
                if(!validStagedCell(proof.elements[k], stagedCut,
                                    proof.winding[k], proof.uvSign)) valid = false;
              }
              if(!valid) continue;
            }
            MTriangle a(pole, quad->getVertex((i + 1) % 4), quad->getVertex((i + 2) % 4));
            MTriangle b(pole, quad->getVertex((i + 2) % 4), quad->getVertex((i + 3) % 4));
            const auto qa = evaluateElementQuality(&a), qb = evaluateElementQuality(&b);
            const double angle = std::min(qa.minimumAngleDegrees, qb.minimumAngleDegrees);
            if(qa.topologicallyValid && qb.topologicallyValid && angle > bestAngle) {
              best = quad; corner = i; bestAngle = angle;
            }
          }
        }
        if(best) cuts.emplace(best, corner);
        if(!physicalSides) {
          if(!best) return result;
          discreteProofs.push_back(proof);
        }
      }
      if(cuts.empty()) return result;
      // A later pole can propose a cut in the retained cell of an earlier
      // star. Validate the actual complete plan before changing ownership.
      for(const DiscreteStarProof &proof : discreteProofs)
        for(int k = 0; k < 2; ++k) {
          const auto cut = cuts.find(dynamic_cast<MQuadrangle *>(proof.elements[k]));
          if(!validStagedCell(proof.elements[k], cut == cuts.end() ? -1 : cut->second,
                              proof.winding[k], proof.uvSign)) return result;
        }
      std::vector<std::unique_ptr<MTriangle> > added;
      auto triangles = face->triangles;
      std::vector<MQuadrangle *> quadrangles;
      for(MQuadrangle *quad : face->quadrangles) {
        const auto cut = cuts.find(quad);
        if(cut == cuts.end()) { quadrangles.push_back(quad); continue; }
        const int i = cut->second;
        for(int j = 1; j <= 2; ++j) {
          added.emplace_back(new MTriangle(quad->getVertex(i),
            quad->getVertex((i + j) % 4), quad->getVertex((i + j + 1) % 4)));
          added.back()->setPartition(quad->getPartition());
          added.back()->setVisibility(quad->getVisibility());
          triangles.push_back(added.back().get());
        }
      }
      // Validate the entire staged face. On failure the original elements,
      // winding, coordinates and classifications remain untouched.
      face->triangles.swap(triangles);
      face->quadrangles.swap(quadrangles);
      try { result = orientFaceComponents(face); }
      catch(...) {
        face->triangles.swap(triangles);
        face->quadrangles.swap(quadrangles);
        throw;
      }
      if(!result.regular) {
        face->triangles.swap(triangles);
        face->quadrangles.swap(quadrangles);
        return result;
      }
      for(auto &triangle : added) triangle.release();
      for(const auto &cut : cuts) delete cut.first;
      result.valenceTwoQuadsSplit = cuts.size();
      Msg::Info("QuadOptimizerV2 face=%d prepared fixed CAD valence-two stars: "
                "splitQuads=%zu addedPoints=0", face->tag(), cuts.size());
      return result;
    }

    std::vector<std::vector<Id> > canonicalConnectivity(
      std::vector<std::vector<Id> > connectivity)
    {
      for(std::vector<Id> &cell : connectivity) {
        if(cell.empty()) continue;
        std::rotate(cell.begin(), std::min_element(cell.begin(), cell.end()), cell.end());
        std::vector<Id> reversed = cell;
        std::reverse(reversed.begin() + 1, reversed.end());
        cell = std::min(cell, reversed);
      }
      std::sort(connectivity.begin(), connectivity.end());
      return connectivity;
    }

    struct OptimizationContext {
      QualityLedger quality;
      CadDistance::Contribution cad;
      double initialCadMean = 0., initialCadMaximum = 0.;
      std::uint64_t revision = 0;

      void initialize(const std::vector<GFace *> &faces,
                      const SmallCavityOptimizerOptions &options)
      {
        for(GFace *face : faces) {
          CadDistance::DistanceCache distances;
          std::vector<MElement *> elements;
          elements.insert(elements.end(), face->triangles.begin(), face->triangles.end());
          elements.insert(elements.end(), face->quadrangles.begin(), face->quadrangles.end());
          for(std::size_t index = 0; index < elements.size(); ++index) {
            MElement *element = elements[index];
            const bool triangle = index < face->triangles.size();
            const std::size_t corners = triangle ? 3 : 4;
            bool measurable = element && element->getNumPrimaryVertices() == corners;
            for(std::size_t i = 0; measurable && i < corners; ++i) {
              MVertex *vertex = element->getVertex(static_cast<int>(i));
              measurable = vertex && std::isfinite(vertex->x()) &&
                std::isfinite(vertex->y()) && std::isfinite(vertex->z());
            }
            if(!measurable) {
              // Irregular input faces are skipped by the optimizer, but
              // their unknown cells must not crash or dilute global quotas.
              ElementQuality invalid;
              invalid.kind = triangle ? SurfaceElementKind::Triangle : SurfaceElementKind::Quadrangle;
              invalid.topologicallyValid = false;
              invalid.warpingDegrees = invalid.edgeRatio = invalid.minimumAngleDegrees =
                invalid.maximumAngleDegrees = invalid.skewingDegrees = std::numeric_limits<double>::quiet_NaN();
              quality.add(invalid);
              cad.requestedSamples += corners + 1;
              continue;
            }
            quality.add(evaluateElementQuality(element));
            std::vector<UV> uv;
            if(!CadDistance::elementParameters(face, element, uv)) {
              cad.requestedSamples += element->getNumPrimaryVertices() + 1;
              continue;
            }
            cad += CadDistance::sampleElement(face, element, uv,
              [&](const Point &xyz, const UV &parameter) {
                if(options.edgeLengthCriteriaAt)
                  return options.edgeLengthCriteriaAt(face, xyz[0], xyz[1], xyz[2],
                                                      parameter[0], parameter[1]).target;
                if(options.targetSize > 0.) return options.targetSize;
                return BGM_MeshSize(face, parameter[0], parameter[1], xyz[0], xyz[1], xyz[2]);
              }, &distances);
          }
        }
        initialCadMean = cad.sampledArea > 0. ?
          cad.normalizedSquaredDistanceIntegral / cad.sampledArea : 0.;
        initialCadMaximum = cad.maximumNormalizedDistance;
      }

      CadDistance::Contribution replacedCad(const Score &removed,
                                           const Score &added) const
      {
        CadDistance::Contribution next = cad;
        next.squaredDistanceIntegral += added.cad.squaredDistanceIntegral -
                                        removed.cad.squaredDistanceIntegral;
        next.normalizedSquaredDistanceIntegral +=
          added.cad.normalizedSquaredDistanceIntegral - removed.cad.normalizedSquaredDistanceIntegral;
        next.sampledArea += added.cad.sampledArea - removed.cad.sampledArea;
        next.requestedSamples = next.requestedSamples - removed.cad.requestedSamples + added.cad.requestedSamples;
        next.coveredSamples = next.coveredSamples - removed.cad.coveredSamples + added.cad.coveredSamples;
        // Current maxima need not be rescanned: the acceptance bound uses
        // the immutable initial maximum, and every added cell is checked.
        next.maximumDistance = std::max(next.maximumDistance, added.cad.maximumDistance);
        next.maximumNormalizedDistance = std::max(next.maximumNormalizedDistance,
                                                 added.cad.maximumNormalizedDistance);
        return next;
      }

      void replace(const Score &removed, const Score &added)
      {
        quality = quality.replaced(removed.criteria, added.criteria);
        cad = replacedCad(removed, added);
        ++revision;
      }
    };

    class Optimizer {
      GFace *_face;
      OptimizationContext &_context;
      const SmallCavityOptimizerOptions &_options;
      FaceHalfEdge _topology;
      bool _smartSmoothing = false;
      bool _terminalMandatory = false;
      bool _terminalPairs = false;
      std::set<Id> _fixedCadVertices;
      std::set<std::pair<Id, Id> > _embeddedMeshEdges;

      void collectCadConstraints()
      {
        for(const Id vertexId : _topology.vertices()) {
          MVertex *vertex = _topology.vertex(vertexId);
          if(vertex && vertex->onWhat() && vertex->onWhat()->dim() < 2)
            _fixedCadVertices.insert(vertexId);
        }
        if(!_face || _face->embeddedEdges().empty()) return;
        const auto meshEdges = _topology.edges();
        for(GEdge *curve : _face->embeddedEdges()) {
          std::set<MVertex *> nodes(curve->mesh_vertices.begin(),
                                    curve->mesh_vertices.end());
          for(GVertex *endpoint : curve->vertices())
            nodes.insert(endpoint->mesh_vertices.begin(),
                         endpoint->mesh_vertices.end());
          // Physical-group MSH exports can omit all 1D elements while
          // retaining curve classification and embedded-entity relations.
          // Recover the existing trace from those classified vertices;
          // do not rely exclusively on curve->lines being present.
          for(const auto &edge : meshEdges)
            if(nodes.count(_topology.vertex(edge.first)) &&
               nodes.count(_topology.vertex(edge.second)))
              _embeddedMeshEdges.insert(
                std::minmax(edge.first, edge.second));
        }
      }

      bool preservesCadConstraints(
        const std::vector<std::vector<Id> > &before,
        const std::vector<std::vector<Id> > &after) const
      {
        if(_fixedCadVertices.empty() && _embeddedMeshEdges.empty()) return true;
        std::set<Id> retained;
        std::map<std::pair<Id, Id>, std::size_t> incidences;
        for(const auto &cell : after) {
          retained.insert(cell.begin(), cell.end());
          for(std::size_t i = 0; i < cell.size(); ++i)
            ++incidences[std::minmax(cell[i], cell[(i + 1) % cell.size()])];
        }
        std::map<std::pair<Id, Id>, std::size_t> required;
        for(const auto &cell : before) {
          for(std::size_t i = 0; i < cell.size(); ++i) {
            if(_fixedCadVertices.count(cell[i]) && !retained.count(cell[i]))
              return false;
            const auto edge = std::minmax(cell[i], cell[(i + 1) % cell.size()]);
            if(_embeddedMeshEdges.count(edge)) ++required[edge];
          }
        }
        for(const auto &entry : required)
          if(incidences[entry.first] != entry.second) return false;
        return true;
      }
      SmallCavityOptimizerResult _result;
      std::unordered_map<MVertex *, UV> _parameters;
      struct Rejection {
        std::uint64_t localState = 0, contextRevision = 0;
        bool contextDependent = false;
      };
      std::unordered_map<std::uint64_t, Rejection> _rejected;
      std::size_t _accepted = 0;
      bool _started = false, _hasContextRejections = false;
      std::vector<Id> _smoothingTouched;
      // Each proposal method must see a changed star independently: a rejected
      // Smart proposal does not make Winslow unnecessary (or conversely).
      std::set<Id> _activeSmart, _activeWinslow;
      std::vector<std::vector<Id> > _smoothingColors;
      bool _smoothingColorsValid = false;

      void activateSmoothing(const std::vector<Id> &vertices)
      {
        for(Id id : vertices) {
          MVertex *vertex = _topology.vertex(id);
          if(!vertex || vertex->onWhat() != _face ||
             _topology.isBoundaryVertex(id)) continue;
          _activeSmart.insert(id);
          _activeWinslow.insert(id);
        }
      }
      struct UvHash {
        std::size_t operator()(const UV &uv) const {
          const std::size_t a = std::hash<double>{}(uv[0]);
          const std::size_t b = std::hash<double>{}(uv[1]);
          return a ^ (b + 0x9e3779b9 + (a << 6) + (a >> 2));
        }
      };
      std::unordered_map<UV, Point, UvHash> _normalCache;
      std::map<Point, double> _distanceCache;
      struct ElementCache {
        std::uint64_t state = 0;
        std::vector<UV> uv;
        ElementQuality quality;
        bool parametrized = false, oriented = false, opposed = false;
        bool orientationComplete = false, cadKnown = false;
        CadDistance::Contribution cad;
      };
      std::unordered_map<Id, ElementCache> _elementCache;
      std::set<Id> _stars, _diamonds, _strips, _fans;
      std::set<Id> _repairCells, _composedTriangles;
      std::set<std::pair<Id, Id> > _swaps, _merges;
      struct RuleStats {
        std::size_t applicable = 0, cache = 0, candidates = 0;
        std::size_t topology = 0, orientation = 0, size = 0, cad = 0;
        std::size_t quality = 0, accepted = 0;
      };
      std::map<Rule, RuleStats> _stats;
      struct OnePointStats {
        std::size_t solves = 0, iterations = 0, evaluations = 0;
        std::size_t fixedCornerRejections = 0;
        double seconds = 0.;
      } _onePointStats;

      bool parameter(MVertex *vertex, UV &result)
      {
        const auto known = _parameters.find(vertex);
        if(known != _parameters.end()) {
          result = known->second;
          return true;
        }
        double u = 0., v = 0.;
        bool found = vertex && vertex->onWhat() == _face &&
          vertex->getParameter(0, u) && vertex->getParameter(1, v) &&
          std::isfinite(u) && std::isfinite(v);
        if(!found && vertex) {
          SPoint2 uv;
          if(_face->geomType() == GEntity::DiscreteSurface)
            uv = _face->parFromPoint(vertex->point(), true, true);
          else if(!reparamMeshVertexOnFace(vertex, _face, uv, true, false))
            return false;
          u = uv.x();
          v = uv.y();
          found = std::isfinite(u) && std::isfinite(v);
        }
        if(!found) return false;
        result = {{u, v}};
        _parameters.emplace(vertex, result);
        return true;
      }

      void unwrap(std::vector<UV> &parameters) const
      {
        if(parameters.empty()) return;
        for(int direction = 0; direction < 2; ++direction) {
          if(!_face->periodic(direction)) continue;
          const double period = std::abs(_face->period(direction));
          if(!(period > 0.) || !std::isfinite(period)) continue;
          const double reference = parameters.front()[direction];
          for(UV &uv : parameters)
            uv[direction] +=
              std::round((reference - uv[direction]) / period) * period;
        }
      }

      bool mappedPoint(const UV &uv, Point &xyz) const
      {
        const GPoint mapped = _face->point(SPoint2(uv[0], uv[1]));
        if(!mapped.succeeded() || !std::isfinite(mapped.x()) ||
           !std::isfinite(mapped.y()) || !std::isfinite(mapped.z()))
          return false;
        xyz = {{mapped.x(), mapped.y(), mapped.z()}};
        return true;
      }

      double localTarget(const Point &xyz, const UV &uv) const
      {
        double h = _options.targetSize;
        if(_options.edgeLengthCriteriaAt)
          h = _options.edgeLengthCriteriaAt(
            _face, xyz[0], xyz[1], xyz[2], uv[0], uv[1]).target;
        else if(!(h > 0.))
          h = BGM_MeshSize(_face, uv[0], uv[1], xyz[0], xyz[1], xyz[2]);
        return h > 0. && std::isfinite(h) ? h : 0.;
      }

      EdgeLengthCriteria edgeCriteria(MVertex *a, MVertex *b,
                                       const UV &middle) const
      {
        if(_options.edgeLengthCriteriaAt) {
          const Point pa = point(a), pb = point(b);
          return _options.edgeLengthCriteriaAt(
            _face, .5 * (pa[0] + pb[0]), .5 * (pa[1] + pb[1]),
            .5 * (pa[2] + pb[2]), middle[0], middle[1]);
        }
        EdgeLengthCriteria result;
        const Point pa = point(a), pb = point(b);
        result.target = localTarget(
          {{.5 * (pa[0] + pb[0]), .5 * (pa[1] + pb[1]),
            .5 * (pa[2] + pb[2])}}, middle);
        const double relativeMinimum = _options.minimumEdgeSizeRatio > 0. ?
          _options.minimumEdgeSizeRatio * result.target : 0.;
        const double relativeMaximum = _options.maximumEdgeSizeRatio > 0. ?
          _options.maximumEdgeSizeRatio * result.target :
          std::numeric_limits<double>::infinity();
        result.minimum = _options.minimumEdgeLength > 0. ?
          std::max(_options.minimumEdgeLength, relativeMinimum) :
          relativeMinimum;
        result.maximum = _options.maximumEdgeLength > 0. ?
          std::min(_options.maximumEdgeLength, relativeMaximum) :
          relativeMaximum;
        return result;
      }

      bool elementParameters(
        MElement *element,
        const std::unordered_map<MVertex *, UV> *overrides,
        std::vector<UV> &uv)
      {
        const std::size_t count = element->getNumPrimaryVertices();
        uv.resize(count);
        for(std::size_t i = 0; i < count; ++i) {
          MVertex *vertex = element->getVertex(static_cast<int>(i));
          const auto overridden = overrides ? overrides->find(vertex) :
            std::unordered_map<MVertex *, UV>::const_iterator();
          if(overrides && overridden != overrides->end())
            uv[i] = overridden->second;
          else if(!parameter(vertex, uv[i]))
            return false;
        }
        unwrap(uv);
        return true;
      }

      bool addCadContribution(const CadDistance::Contribution &contribution, Score &score)
      {
        score.cad += contribution;
        score.cadNormalizedMeanSquared += contribution.normalizedSquaredDistanceIntegral;
        score.cadNormalizedMaximum = std::max(score.cadNormalizedMaximum,
                                             contribution.maximumNormalizedDistance);
        score.cadWeight += contribution.sampledArea;
        return contribution.complete();
      }

      bool followsFace(MElement *element, const std::vector<UV> &uv,
                       bool *reliableOpposition = nullptr,
                       bool *complete = nullptr)
      {
        if(complete) *complete = true;
        std::vector<Point> xyz;
        for(std::size_t i = 0; i < uv.size(); ++i)
          xyz.push_back(point(element->getVertex(i)));
        std::vector<std::array<std::size_t, 3> > triangles;
        std::vector<std::array<std::size_t, 4> > quads;
        if(uv.size() == 3) triangles.push_back({{0, 1, 2}});
        else if(uv.size() == 4) quads.push_back({{0, 1, 2, 3}});
        else return false;
        if(reliableOpposition) *reliableOpposition = false;
        std::size_t samples = 0;
        const bool oriented = GeometryGuard::indexedPatchFollowsNormals(
          [&](const UV &parameter, const Point &jacobian,
              double norm, double scale2) {
            ++samples;
            if(!std::isfinite(norm) || norm <= 1.e-12 * scale2) {
              if(complete) *complete = false;
              return 0;
            }
            auto cached = _normalCache.find(parameter);
            if(cached == _normalCache.end()) {
              Point normal = {{0., 0., 0.}};
              try {
                SVector3 n;
                bool available = false;
                const SPoint2 uvPoint(parameter[0], parameter[1]);
                if(auto *discrete = dynamic_cast<discreteFace *>(_face))
                  available = discrete->normalIfContainsParam(uvPoint, n);
                else if(_face->containsParam(uvPoint)) {
                  n = _face->normal(uvPoint);
                  available = true;
                }
                if(available && std::isfinite(n.x()) &&
                   std::isfinite(n.y()) && std::isfinite(n.z()))
                  normal = {{n.x(), n.y(), n.z()}};
              }
              catch(...) {}
              cached = _normalCache.emplace(parameter, normal).first;
            }
            const double normalNorm = std::sqrt(dot(cached->second, cached->second));
            if(!(normalNorm > 0.)) {
              if(complete) *complete = false;
              return 0;
            }
            const int sign = dot(jacobian, cached->second) >
              1.e-10 * norm * normalNorm ? 1 : -1;
            if(sign < 0 && reliableOpposition) *reliableOpposition = true;
            return sign;
          }, uv, xyz, triangles, quads);
        if(complete) *complete = *complete && samples == (uv.size() == 3 ? 4 : 8);
        return oriented;
      }

      Score score(const std::vector<MElement *> &elements,
                  const std::unordered_map<MVertex *, UV> *overrides = nullptr,
                  bool withCad = true, bool requireAbsoluteWarping = true,
                  bool withOrientation = true,
                  std::vector<ElementCache> *evaluated = nullptr)
      {
        Score result;
        // Trial evaluations stay separate from the committed geometry cache.
        // They can be published only after acceptance and synchronization.
        if(evaluated) {
          evaluated->clear();
          evaluated->reserve(elements.size());
        }
        std::vector<std::pair<MVertex *, MVertex *> > localEdges;
        struct EdgeHash {
          std::size_t operator()(const std::pair<MVertex *, MVertex *> &edge) const {
            const auto a = reinterpret_cast<std::uintptr_t>(edge.first) >> 3;
            const auto b = reinterpret_cast<std::uintptr_t>(edge.second) >> 3;
            return a ^ (b + 0x9e3779b9 + (a << 6) + (a >> 2));
          }
        };
        std::unordered_set<std::pair<MVertex *, MVertex *>, EdgeHash> largeEdges;
        const bool small = elements.size() <= 16;
        if(small) localEdges.reserve(4 * elements.size());
        else largeEdges.reserve(3 * elements.size());
        for(MElement *element : elements) {
          if(evaluated) evaluated->emplace_back();
          if(!element) {
            ++result.invalid;
            continue;
          }
          // Reference elements must still be owned by the GFace. This cheap
          // pointer-only guard also turns any adapter synchronization bug
          // into a rejected candidate instead of dereferencing freed Gmsh
          // storage. Candidate elements are intentionally not owned yet.
          if(!overrides && _topology.id(element) == HalfEdgeMesh::invalid) {
            Msg::Error("QuadOptimizerV2 face=%d found a stale half-edge "
                       "element handle", _face->tag());
            ++result.invalid;
            continue;
          }
          std::vector<UV> uv;
          ElementCache *cached = nullptr;
          // Only cache committed mesh geometry. Nodal trials use the cheap
          // score without orientation; proposed topology supplies overrides.
          if(!overrides && withOrientation) {
            const Id id = _topology.id(element);
            const auto state = _topology.state(FaceHalfEdge::Cavity{{id}, {}, {}});
            auto &entry = _elementCache[id];
            if(entry.state != state) {
              entry.state = state;
              entry.parametrized = elementParameters(element, nullptr, entry.uv);
              entry.opposed = false;
              entry.orientationComplete = false;
              entry.oriented = entry.parametrized &&
                followsFace(element, entry.uv, &entry.opposed, &entry.orientationComplete);
              entry.quality = evaluateElementQuality(element);
              entry.cadKnown = false;
            }
            cached = &entry;
          }
          const bool parametrized = cached ? cached->parametrized :
            elementParameters(element, overrides, uv);
          if(cached) uv = cached->uv;
          bool opposed = cached && cached->opposed;
          bool orientationComplete = cached && cached->orientationComplete;
          const bool oriented = parametrized && withOrientation &&
            (cached ? cached->oriented : followsFace(element, uv, &opposed, &orientationComplete));
          if(!parametrized || (withOrientation && !oriented))
            ++result.invalid;
          if(withOrientation && !orientationComplete) ++result.incompleteOrientation;
          const ElementQuality quality = cached ? cached->quality : evaluateElementQuality(element);
          if(opposed || !quality.topologicallyValid) ++result.physicalInvalid;
          if(quality.kind == SurfaceElementKind::Triangle) ++result.triangles;
          if(requireAbsoluteWarping && quality.kind == SurfaceElementKind::Quadrangle &&
             quality.warpingDegrees >= absoluteMaximumQuadWarpingDegrees)
            ++result.invalid;
          result.shape += specificationObjective(quality);
          result.criteria.add(quality);
          result.maximumAngularDeviation = std::max(
            result.maximumAngularDeviation,
            std::max(std::abs(quality.minimumAngleDegrees -
                       (quality.kind == SurfaceElementKind::Triangle ? 60. : 90.)),
                     std::abs(quality.maximumAngleDegrees -
                       (quality.kind == SurfaceElementKind::Triangle ? 60. : 90.))));
          if(!quality.topologicallyValid) ++result.invalid;
          CadDistance::Contribution cad;
          bool cadKnown = false;
          if(parametrized && withCad) {
            if(cached) {
              if(!cached->cadKnown) {
                cached->cad = CadDistance::sampleElement(_face, element, uv,
                  [&](const Point &xyz, const UV &parameter) { return localTarget(xyz, parameter); },
                  &_distanceCache);
                cached->cadKnown = true;
              }
              cad = cached->cad;
            }
            else cad = CadDistance::sampleElement(_face, element, uv,
              [&](const Point &xyz, const UV &parameter) { return localTarget(xyz, parameter); },
              &_distanceCache);
            cadKnown = true;
            if(!addCadContribution(cad, result)) ++result.invalid;
          }
          if(evaluated) {
            ElementCache &entry = evaluated->back();
            entry.uv = uv;
            entry.quality = quality;
            entry.parametrized = parametrized;
            entry.oriented = oriented;
            entry.opposed = opposed;
            entry.orientationComplete = orientationComplete;
            entry.cadKnown = cadKnown;
            entry.cad = cad;
          }
          if(!parametrized || !_options.enforceSizeMap) continue;
          const std::size_t count = element->getNumPrimaryVertices();
          for(std::size_t i = 0; i < count; ++i) {
            MVertex *a = element->getVertex(static_cast<int>(i));
            MVertex *b =
              element->getVertex(static_cast<int>((i + 1) % count));
            if(std::less<MVertex *>()(b, a)) std::swap(a, b);
            if(small) {
              const std::pair<MVertex *, MVertex *> edge{a, b};
              if(std::find(localEdges.begin(), localEdges.end(), edge) != localEdges.end()) continue;
              localEdges.push_back(edge);
            }
            else if(!largeEdges.insert({a, b}).second) continue;
            UV middle = {{.5 * (uv[i][0] + uv[(i + 1) % count][0]),
                          .5 * (uv[i][1] + uv[(i + 1) % count][1])}};
            const EdgeLengthCriteria criteria = edgeCriteria(a, b, middle);
            const double length = edgeLength(a, b);
            result.minimumLength = std::min(result.minimumLength, length);
            result.maximumLength = std::max(result.maximumLength, length);
            double violation = 0.;
            if(!std::isfinite(length) || !(criteria.target > 0.) ||
               !std::isfinite(criteria.target) ||
               !std::isfinite(criteria.minimum) || criteria.minimum < 0. ||
               std::isnan(criteria.maximum) || criteria.maximum < criteria.minimum) {
              ++result.invalidSize;
              violation = std::numeric_limits<double>::infinity();
            }
            else if(length < criteria.minimum) {
              ++result.belowMinimum;
              violation = (criteria.minimum - length) / criteria.target;
            }
            else if(length > criteria.maximum) {
              ++result.aboveMaximum;
              violation = (length - criteria.maximum) / criteria.target;
            }
            if(violation > 0.) ++result.sizeViolations;
            result.worstSizeViolation = std::max(result.worstSizeViolation, violation);
            result.sizePenalty += violation * violation;
          }
        }
        if(result.cadWeight > 0.) {
          result.cadNormalizedMeanSquared /= result.cadWeight;
        }
        return result;
      }

      bool boundedLocalCad(const Score &candidate, const Score &reference) const
      {
        return !candidate.invalid && candidate.cad.complete() && reference.cad.complete() &&
          candidate.cadNormalizedMeanSquared <= reference.cadNormalizedMeanSquared +
            _options.maximumNormalizedCadRegression + 1.e-15 &&
          candidate.cadNormalizedMaximum <= reference.cadNormalizedMaximum +
            _options.maximumCadDistanceIncreaseRatio + 1.e-14;
      }

      bool boundedGlobalCad(const Score &candidate, const Score &reference) const
      {
        const auto global = _context.replacedCad(reference, candidate);
        return global.sampledArea > 0. &&
          std::isfinite(global.normalizedSquaredDistanceIntegral) &&
          global.normalizedSquaredDistanceIntegral / global.sampledArea <=
            _context.initialCadMean + _options.maximumNormalizedCadRegression + 1.e-14 &&
          candidate.cadNormalizedMaximum <= _context.initialCadMaximum +
            _options.maximumCadDistanceIncreaseRatio + 1.e-14;
      }

      bool boundedCad(const Score &candidate, const Score &reference) const
      {
        return boundedLocalCad(candidate, reference) && boundedGlobalCad(candidate, reference);
      }

      bool boundedSize(const Score &candidate, const Score &reference) const
      {
        const double tolerance = std::max(1.e-12, _options.objectiveRelativeTolerance);
        return candidate.invalidSize == 0 &&
          candidate.sizeViolations <= reference.sizeViolations &&
          candidate.worstSizeViolation <= reference.worstSizeViolation + tolerance &&
          candidate.sizePenalty <= reference.sizePenalty + tolerance *
            std::max(1., reference.sizePenalty);
      }

      bool boundedQuality(const Score &candidate, const Score &reference) const
      {
        return candidate.shape.absoluteBadElementCount <= reference.shape.absoluteBadElementCount &&
          candidate.shape.absoluteViolationCount <= reference.shape.absoluteViolationCount &&
          candidate.criteria.absoluteNoWorseThan(reference.criteria);
      }

      bool better(const Score &candidate, const Score &reference,
                  const Score *removed = nullptr) const
      {
        if(candidate.invalid != reference.invalid)
          return candidate.invalid < reference.invalid;
        if(candidate.sizeViolations != reference.sizeViolations)
          return candidate.sizeViolations < reference.sizeViolations;
        if(candidate.shape.absoluteBadElementCount !=
           reference.shape.absoluteBadElementCount)
          return candidate.shape.absoluteBadElementCount <
            reference.shape.absoluteBadElementCount;
        if(candidate.shape.absoluteViolationCount !=
           reference.shape.absoluteViolationCount)
          return candidate.shape.absoluteViolationCount <
            reference.shape.absoluteViolationCount;
        // After the hard admissibility criteria, prefer quadrangles to
        // triangles even when the triangles meet more preferred targets.
        // The preferred ledger still ranks candidates with equal triangle counts.
        if(candidate.triangles != reference.triangles)
          return candidate.triangles < reference.triangles;
        const QualityLedger &cavity = removed ? removed->criteria : reference.criteria;
        const auto candidateDeficit = _context.quality.replaced(cavity, candidate.criteria).preferredDeficit();
        const auto referenceDeficit = _context.quality.replaced(cavity, reference.criteria).preferredDeficit();
        if(candidateDeficit != referenceDeficit) return candidateDeficit < referenceDeficit;
        const double tolerance = _options.objectiveRelativeTolerance;
        if(candidate.maximumAngularDeviation + tolerance <
           reference.maximumAngularDeviation)
          return true;
        if(reference.maximumAngularDeviation + tolerance <
           candidate.maximumAngularDeviation)
          return false;
        const double candidateCompromise = candidate.shape.shapePenalty +
          candidate.sizePenalty + candidate.cadNormalizedMeanSquared;
        const double referenceCompromise = reference.shape.shapePenalty +
          reference.sizePenalty + reference.cadNormalizedMeanSquared;
        return candidateCompromise + tolerance *
          std::max({1., std::abs(candidateCompromise),
                    std::abs(referenceCompromise)}) < referenceCompromise;
      }

      std::vector<MElement *> cavityElements(
        const FaceHalfEdge::Cavity &cavity) const
      {
        std::vector<MElement *> result;
        result.reserve(cavity.cells.size());
        for(const Id cell : cavity.cells)
          if(MElement *element = _topology.element(cell))
            result.push_back(element);
        return result;
      }

      bool baseCandidate(const FaceHalfEdge::Cavity &cavity,
                         Candidate &candidate)
      {
        candidate.vertices.clear();
        candidate.vertices.reserve(cavity.boundary.size());
        for(const Id vertexId : cavity.boundary) {
          MVertex *vertex = _topology.vertex(vertexId);
          UV uv;
          if(!vertex || !parameter(vertex, uv)) return false;
          candidate.vertices.push_back({vertex, uv, point(vertex)});
        }
        std::vector<UV> boundaryUv;
        for(const VertexSpec &vertex : candidate.vertices)
          boundaryUv.push_back(vertex.uv);
        unwrap(boundaryUv);
        for(std::size_t i = 0; i < boundaryUv.size(); ++i)
          candidate.vertices[i].uv = boundaryUv[i];
        return true;
      }

      Candidate polygonCandidate(
        const FaceHalfEdge::Cavity &cavity,
        const HalfEdgeRewrite::QuadConnectivity &quadrangles,
        const char *name)
      {
        Candidate candidate;
        candidate.name = name;
        if(!baseCandidate(cavity, candidate)) return {};
        for(const auto &quad : quadrangles)
          candidate.cells.push_back(
            {quad[0], quad[1], quad[2], quad[3]});
        return candidate;
      }

      std::vector<Candidate> polygonCandidates(
        const FaceHalfEdge::Cavity &cavity, const char *name)
      {
        std::vector<Candidate> result;
        std::vector<std::size_t> polygon(cavity.boundary.size());
        for(std::size_t i = 0; i < polygon.size(); ++i) polygon[i] = i;
        for(const auto &quadrangles :
            HalfEdgeRewrite::evenPolygonQuadrangulations(polygon))
          result.push_back(polygonCandidate(cavity, quadrangles, name));
        return result;
      }

      Candidate fanCandidate(const FaceHalfEdge::Cavity &cavity,
                             MVertex *retained, bool createCenter,
                             std::size_t rotation, const char *name)
      {
        Candidate candidate;
        candidate.name = name;
        if(!baseCandidate(cavity, candidate) ||
           cavity.boundary.size() < 4 || cavity.boundary.size() % 2)
          return {};
        VertexSpec center;
        center.vertex = retained;
        if(retained) {
          if(!parameter(retained, center.uv)) return {};
          center.xyz = point(retained);
        }
        else if(createCenter) {
          for(const VertexSpec &boundary : candidate.vertices) {
            center.uv[0] += boundary.uv[0] / candidate.vertices.size();
            center.uv[1] += boundary.uv[1] / candidate.vertices.size();
          }
          if(!mappedPoint(center.uv, center.xyz)) return {};
        }
        else {
          return {};
        }
        const std::size_t centerIndex = candidate.vertices.size();
        candidate.vertices.push_back(center);
        const std::size_t count = cavity.boundary.size();
        for(std::size_t offset = 0; offset < count; offset += 2) {
          const std::size_t i = (rotation + offset) % count;
          candidate.cells.push_back({centerIndex, i, (i + 1) % count,
                                     (i + 2) % count});
        }
        return candidate;
      }

      // Physical, area-weighted mean plane; independent of CAD parameters.
      bool meanPlaneChart(const std::vector<Point> &xyz, std::size_t first,
                          std::size_t count, std::size_t center, Point &origin,
                          Point &tangent1, Point &tangent2, std::vector<UV> &plane)
      {
        origin = {{0., 0., 0.}};
        for(const Point &p : xyz)
          for(int k = 0; k < 3; ++k) origin[k] += p[k];
        for(double &v : origin) v /= xyz.size();
        SVector3 normal(0., 0., 0.);
        for(std::size_t i = 0; i < count; ++i) {
          const Point a = subtract(xyz[first + i], origin);
          const Point b = subtract(xyz[first + (i + 1) % count], origin);
          normal += crossprod(SVector3(a[0], a[1], a[2]), SVector3(b[0], b[1], b[2]));
        }
        if(!(normal.norm() > 0.) || !std::isfinite(normal.norm())) return false;
        normal.normalize();
        SVector3 t1(0., 0., 0.);
        for(std::size_t i = 0; i < count; ++i) {
          const Point delta = subtract(xyz[first + i], xyz[center]);
          SVector3 axis(delta[0], delta[1], delta[2]);
          axis -= normal * dot(axis, normal);
          if(axis.norm() > t1.norm()) t1 = axis;
        }
        if(!(t1.norm() > 0.)) return false;
        t1.normalize();
        SVector3 t2 = crossprod(normal, t1); t2.normalize();
        tangent1 = {{t1.x(), t1.y(), t1.z()}};
        tangent2 = {{t2.x(), t2.y(), t2.z()}};
        plane.resize(xyz.size());
        for(std::size_t i = 0; i < xyz.size(); ++i) {
          const Point delta = subtract(xyz[i], origin);
          plane[i] = {{dot(delta, tangent1), dot(delta, tangent2)}};
        }
        return true;
      }

      std::vector<Candidate> onePointStarCandidates(
        const FaceHalfEdge::Cavity &cavity, Id center)
      {
        std::vector<Candidate> result;
        if(cavity.cells.size() != 5 || cavity.boundary.size() != 8 ||
           cavity.interior != std::vector<Id>{center}) return result;
        SmallCavityWinslowOptions winslow = _options.winslow;
        winslow.harmonicInitialization = false;
        winslow.maxInnerIterations = std::min(winslow.maxInnerIterations, 20);
        winslow.maxOuterIterations = std::min(winslow.maxOuterIterations, 2);
        winslow.maxLineSearchSteps = std::min(winslow.maxLineSearchSteps, 12);
        for(std::size_t rotation = 0; rotation < 2; ++rotation) {
          Candidate candidate = fanCandidate(cavity, _topology.vertex(center),
            false, rotation, "TQTQQ->4Q one-point Winslow");
          if(candidate.cells.size() != 4 || candidate.vertices.size() != 9) continue;
          std::vector<UV> uv;
          for(const VertexSpec &vertex : candidate.vertices) uv.push_back(vertex.uv);
          unwrap(uv);
          const UV initialUv = uv.back();
          const Point initialXyz = candidate.vertices.back().xyz;
          std::vector<Point> xyz;
          for(const VertexSpec &vertex : candidate.vertices) xyz.push_back(vertex.xyz);
          Point origin, tangent1, tangent2;
          std::vector<UV> plane;
          if(!meanPlaneChart(xyz, 0, cavity.boundary.size(), xyz.size() - 1,
                             origin, tangent1, tangent2, plane)) continue;
          const UV initialPlane = plane.back();
          std::vector<std::array<std::size_t, 4> > quadrangles;
          for(const Cell &cell : candidate.cells)
            quadrangles.push_back({{cell[0], cell[1], cell[2], cell[3]}});
          const auto twiceArea = [&](std::size_t a, std::size_t b, std::size_t c) {
            return (static_cast<long double>(plane[b][0]) - plane[a][0]) *
                     (static_cast<long double>(plane[c][1]) - plane[a][1]) -
                   (static_cast<long double>(plane[b][1]) - plane[a][1]) *
                     (static_cast<long double>(plane[c][0]) - plane[a][0]);
          };
          long double boundaryArea = 0.;
          for(std::size_t i = 1; i + 1 < cavity.boundary.size(); ++i)
            boundaryArea += twiceArea(0, i, i + 1);
          const long double sign = boundaryArea > 0. ? 1. : -1.;
          bool fixedCornersValid = std::isfinite(boundaryArea) && boundaryArea != 0.;
          for(const auto &quad : quadrangles)
            fixedCornersValid = fixedCornersValid &&
              sign * twiceArea(quad[1], quad[2], quad[3]) > 0.;
          if(!fixedCornersValid) {
            // This corner uses three fixed boundary vertices: moving the
            // center cannot change its Jacobian, so no solve can untangle it.
            ++_onePointStats.fixedCornerRejections;
            if(_options.verbose)
              Msg::Info("QuadOptimizerV2 face=%d one-point Winslow parity=%zu "
                        "C=5 B=8 unknowns=2 skipped=fixed-corner",
                        _face->tag(), rotation);
            continue;
          }
          // Exactly two unknowns, on the original five-cell cavity. The
          // solver keeps its eight boundary vertices bitwise fixed. No live
          // mesh vertex is moved while generating or scoring the candidate.
          const auto started = std::chrono::steady_clock::now();
          SmallCavityWinslowResult optimized;
          try {
            optimized = optimizeSmallQuadCavityWinslow(
              plane, cavity.boundary.size(), quadrangles, winslow);
          }
          catch(const std::invalid_argument &) {
            // A degenerate chart is a rejected candidate, not a failed model.
          }
          _onePointStats.seconds += std::chrono::duration<double>(
            std::chrono::steady_clock::now() - started).count();
          ++_onePointStats.solves;
          _onePointStats.iterations += optimized.lbfgsIterations;
          _onePointStats.evaluations += optimized.functionEvaluations;
          if(_options.verbose)
            Msg::Info("QuadOptimizerV2 face=%d one-point Winslow parity=%zu "
                      "C=5 B=8 unknowns=2 success=%d iterations=%d evaluations=%d energy=%.17g->%.17g",
                      _face->tag(), rotation, optimized.success && optimized.untangled,
                      optimized.lbfgsIterations, optimized.functionEvaluations,
                      optimized.initialEnergy, optimized.finalEnergy);
          if(!optimized.success || !optimized.untangled) {
            ++_result.rejectedByWinslow;
            continue;
          }
          // The staged center replaces the old interior vertex atomically;
          // no additional mesh point remains after the transaction.
          VertexSpec &placed = candidate.vertices.back();
          placed.vertex = nullptr;
          const double dx = plane.back()[0] - initialPlane[0];
          const double dy = plane.back()[1] - initialPlane[1];
          const SPoint3 target(initialXyz[0] + dx * tangent1[0] + dy * tangent2[0],
                               initialXyz[1] + dx * tangent1[1] + dy * tangent2[1],
                               initialXyz[2] + dx * tangent1[2] + dy * tangent2[2]);
          UV guess = initialUv;
          const GPoint projected = _face->closestPointFromTrustedGuess(target, guess.data());
          if(!projected.succeeded()) continue;
          placed.uv = {{projected.u(), projected.v()}};
          if(!mappedPoint(placed.uv, placed.xyz)) continue;
          // If the center stayed put, the short-strip operators already
          // cover this fan on C3/C4. Do not include its unchanged quads in C5.
          // Allow for roundoff from the solver's normalization round trip.
          double uvScale = 0., xyzScale = 0.;
          for(const VertexSpec &vertex : candidate.vertices) {
            for(double value : vertex.uv) uvScale = std::max(uvScale, std::abs(value));
            for(double value : vertex.xyz) xyzScale = std::max(xyzScale, std::abs(value));
          }
          for(double value : initialUv) uvScale = std::max(uvScale, std::abs(value));
          for(double value : initialXyz) xyzScale = std::max(xyzScale, std::abs(value));
          const double roundoff = 64. * std::numeric_limits<double>::epsilon();
          bool stationary = true;
          for(std::size_t i = 0; i < 2; ++i)
            stationary = stationary && std::abs(placed.uv[i] - initialUv[i]) <= roundoff * uvScale;
          for(std::size_t i = 0; i < 3; ++i)
            stationary = stationary && std::abs(placed.xyz[i] - initialXyz[i]) <= roundoff * xyzScale;
          if(stationary) continue;
          for(std::size_t i = 0; i < cavity.boundary.size(); ++i)
            candidate.vertices[i].uv = uv[i];
          result.push_back(std::move(candidate));
        }
        return result;
      }

      bool smoothReplacementInterior(const FaceHalfEdge::Cavity &cavity,
                                     Candidate &candidate)
      {
        const std::size_t boundary = cavity.boundary.size();
        if(candidate.vertices.size() < boundary || boundary < 3) return false;
        std::vector<Point> xyz;
        std::vector<bool> fixed(candidate.vertices.size(), true);
        std::size_t free = 0, firstFree = 0;
        for(std::size_t i = 0; i < candidate.vertices.size(); ++i) {
          const auto &vertex = candidate.vertices[i];
          xyz.push_back(vertex.xyz);
          if(i < boundary) {
            if(vertex.vertex != _topology.vertex(cavity.boundary[i])) return false;
          }
          else if(!vertex.vertex ||
                  (std::find(cavity.interior.begin(), cavity.interior.end(),
                             _topology.id(vertex.vertex)) != cavity.interior.end() &&
                   !_fixedCadVertices.count(_topology.id(vertex.vertex)))) {
            fixed[i] = false;
            firstFree = i;
            ++free;
          }
        }
        // Reductions with no surviving interior point need no smoothing.
        if(!free) return true;
        Point origin, tangent1, tangent2;
        std::vector<UV> plane;
        if(!meanPlaneChart(xyz, 0, boundary, firstFree, origin,
                           tangent1, tangent2, plane)) return false;
        const auto initialPlane = plane;
        double area = 0.;
        for(std::size_t i = 0; i < boundary; ++i) {
          const UV &a = plane[i], &b = plane[(i + 1) % boundary];
          area += a[0] * b[1] - a[1] * b[0];
        }
        if(!std::isfinite(area) || area == 0.) return false;
        const double orientation = area > 0. ? 1. : -1.;
        std::vector<std::array<std::size_t, 3> > triangles;
        std::vector<std::array<std::size_t, 4> > quadrangles;
        for(const Cell &cell : candidate.cells) {
          if(cell.size() == 3)
            triangles.push_back({{cell[0], cell[1], cell[2]}});
          else if(cell.size() == 4)
            quadrangles.push_back({{cell[0], cell[1], cell[2], cell[3]}});
          else return false;
        }
        SmallCavityWinslowOptions options = _options.winslow;
        options.harmonicInitialization = false;
        options.maxInnerIterations = std::min(options.maxInnerIterations, 20);
        options.maxOuterIterations = std::min(options.maxOuterIterations, 2);
        options.maxLineSearchSteps = std::min(options.maxLineSearchSteps, 12);
        options.verbose = 0;
        SmallCavityWinslowResult optimized;
        try {
          // QQTQQT has exactly two free points (four coupled unknowns).
          // This solve owns only candidate arrays, never live mesh vertices.
          optimized = optimizeLocalSurfacePatchWinslow(
            plane, fixed, triangles, quadrangles, orientation, options);
        }
        catch(const std::invalid_argument &) {}
        if(_options.verbose)
          Msg::Info("QuadOptimizerV2 face=%d valence local Winslow rule=%s "
                    "C=%zu B=%zu points=%zu unknowns=%zu success=%d",
                    _face->tag(), candidate.name, cavity.cells.size(), boundary,
                    free, 2 * free, optimized.success && optimized.untangled);
        if(!optimized.success || !optimized.untangled) return false;
        for(std::size_t i = 0; i < candidate.vertices.size(); ++i) {
          if(fixed[i]) continue;
          auto &vertex = candidate.vertices[i];
          const double dx = plane[i][0] - initialPlane[i][0];
          const double dy = plane[i][1] - initialPlane[i][1];
          const SPoint3 target(xyz[i][0] + dx * tangent1[0] + dy * tangent2[0],
                               xyz[i][1] + dx * tangent1[1] + dy * tangent2[1],
                               xyz[i][2] + dx * tangent1[2] + dy * tangent2[2]);
          UV guess = vertex.uv;
          const GPoint projected =
            _face->closestPointFromTrustedGuess(target, guess.data());
          if(!projected.succeeded()) return false;
          vertex.uv = {{projected.u(), projected.v()}};
          if(!mappedPoint(vertex.uv, vertex.xyz)) return false;
          // Stage even a retained interior point as a replacement. The
          // original cavity is left intact if any transaction guard rejects.
          vertex.vertex = nullptr;
        }
        return true;
      }

      std::vector<Candidate> splitInteriorStarCandidates(
        const FaceHalfEdge::Cavity &cavity, Id,
        bool qqtqqt)
      {
        std::vector<Candidate> result;
        const std::size_t count = cavity.boundary.size();
        if((qqtqqt && count != 10) || (!qqtqqt && count != 12))
          return result;
        for(std::size_t rotation = 0; rotation < count; ++rotation) {
          Candidate candidate;
          candidate.name = qqtqqt ? "QQTQQT->6Q" : "valence6 split";
          if(!baseCandidate(cavity, candidate)) continue;
          // Replace the old pole by two interior points, one initialized in
          // each half-disk. Keeping the old pole at the full-disk centroid
          // would make the bridge quadrangle degenerate before the global
          // Winslow sweep has a chance to move it.
          UV firstUv = {{0., 0.}};
          UV secondUv = {{0., 0.}};
          const std::size_t half = count / 2;
          for(std::size_t offset = 0; offset <= half; ++offset) {
            const UV &uv = candidate.vertices[(rotation + offset) % count].uv;
            firstUv[0] += uv[0] / (half + 1);
            firstUv[1] += uv[1] / (half + 1);
          }
          for(std::size_t offset = half; offset <= count; ++offset) {
            const UV &uv = candidate.vertices[(rotation + offset) % count].uv;
            secondUv[0] += uv[0] / (half + 1);
            secondUv[1] += uv[1] / (half + 1);
          }
          Point firstXyz;
          Point secondXyz;
          if(!mappedPoint(firstUv, firstXyz) ||
             !mappedPoint(secondUv, secondXyz))
            continue;
          const std::size_t firstCenter = candidate.vertices.size();
          candidate.vertices.push_back({nullptr, firstUv, firstXyz});
          const std::size_t secondCenter = candidate.vertices.size();
          candidate.vertices.push_back({nullptr, secondUv, secondXyz});
          const auto b = [&](std::size_t offset) {
            return (rotation + offset) % count;
          };
          if(qqtqqt) {
            candidate.cells = {
              {firstCenter, b(0), b(1), b(2)},
              {firstCenter, b(2), b(3), b(4)},
              {firstCenter, b(4), b(5), secondCenter},
              {secondCenter, b(5), b(6), b(7)},
              {secondCenter, b(7), b(8), b(9)},
              {secondCenter, b(9), b(0), firstCenter}};
          }
          else {
            candidate.cells = {
              {firstCenter, b(0), b(1), b(2)},
              {firstCenter, b(2), b(3), b(4)},
              {firstCenter, b(4), b(5), b(6)},
              {firstCenter, b(6), secondCenter, b(0)},
              {secondCenter, b(6), b(7), b(8)},
              {secondCenter, b(8), b(9), b(10)},
              {secondCenter, b(10), b(11), b(0)}};
          }
          // Two closed-form placements, not a local smoothing solve. The
          // half-disk means alone produce excessive bridge skew even on a
          // regular ring; a small inward shift gives an admissible split.
          UV centroid = {{0., 0.}};
          for(std::size_t i = 0; i < count; ++i)
            for(int d = 0; d < 2; ++d) centroid[d] += candidate.vertices[i].uv[d] / count;
          Candidate inset = candidate;
          bool mapped = true;
          for(const std::size_t i : {firstCenter, secondCenter}) {
            for(int d = 0; d < 2; ++d)
              inset.vertices[i].uv[d] = centroid[d] + .9 * (candidate.vertices[i].uv[d] - centroid[d]);
            mapped = mapped && mappedPoint(inset.vertices[i].uv, inset.vertices[i].xyz);
          }
          result.push_back(std::move(candidate));
          if(mapped) result.push_back(std::move(inset));
        }
        return result;
      }

      bool build(const Candidate &candidate, BuiltCandidate &built)
      {
        built = BuiltCandidate();
        std::vector<MVertex *> vertices;
        vertices.reserve(candidate.vertices.size());
        for(const VertexSpec &specification : candidate.vertices) {
          MVertex *vertex = specification.vertex;
          if(!vertex) {
            std::unique_ptr<MVertex> created(new MFaceVertex(
              specification.xyz[0], specification.xyz[1],
              specification.xyz[2], _face, specification.uv[0],
              specification.uv[1]));
            vertex = created.get();
            built.newVertices.push_back(std::move(created));
          }
          vertices.push_back(vertex);
          built.parameters[vertex] = specification.uv;
        }
        const std::vector<MElement *> before = cavityElementsForPartition(candidate);
        const int partition = before.empty() ? 0 : before.front()->getPartition();
        const bool visibility = before.empty() ? true :
          before.front()->getVisibility();
        for(const Cell &cell : candidate.cells) {
          if(cell.size() != 3 && cell.size() != 4) return false;
          for(const std::size_t index : cell)
            if(index >= vertices.size()) return false;
          std::unique_ptr<MElement> element;
          if(cell.size() == 3)
            element.reset(new MTriangle(vertices[cell[0]], vertices[cell[1]],
                                        vertices[cell[2]]));
          else
            element.reset(new MQuadrangle(
              vertices[cell[0]], vertices[cell[1]], vertices[cell[2]],
              vertices[cell[3]]));
          element->setPartition(partition);
          element->setVisibility(visibility);
          built.elementPointers.push_back(element.get());
          built.elements.push_back(std::move(element));
        }
        return !built.elements.empty();
      }

      // Set immediately around build() by attempt(); this keeps Candidate a
      // purely generic topology/geometry value and avoids rule-specific
      // partition plumbing.
      mutable const FaceHalfEdge::Cavity *_buildingCavity = nullptr;

      std::vector<MElement *> cavityElementsForPartition(
        const Candidate &) const
      {
        return _buildingCavity ? cavityElements(*_buildingCavity) :
                                 std::vector<MElement *>();
      }

      std::vector<std::vector<Id> > connectivity(
        const FaceHalfEdge::Cavity &cavity) const
      {
        std::vector<std::vector<Id> > result;
        for(const Id cell : cavity.cells)
          result.push_back(_topology.cellVertices(cell));
        return canonicalConnectivity(std::move(result));
      }

      std::vector<std::vector<Id> > connectivity(
        const Candidate &candidate) const
      {
        std::vector<Id> local;
        local.reserve(candidate.vertices.size());
        Id next = std::numeric_limits<Id>::max() / 2;
        for(const VertexSpec &vertex : candidate.vertices)
          local.push_back(vertex.vertex ? _topology.id(vertex.vertex) : next++);
        std::vector<std::vector<Id> > result;
        for(const Cell &cell : candidate.cells) {
          std::vector<Id> vertices;
          for(const std::size_t index : cell)
            if(index < local.size()) vertices.push_back(local[index]);
          result.push_back(std::move(vertices));
        }
        return canonicalConnectivity(std::move(result));
      }

      void enqueueAffected(const std::vector<Id> &vertices)
      {
        std::set<Id> incident;
        for(const Id vertex : vertices) {
          if(!_topology.vertex(vertex)) continue;
          _stars.insert(vertex);
          _fans.insert(vertex);
          for(const Id cell : _topology.incidentCells(vertex)) incident.insert(cell);
        }
        for(const Id cell : incident) {
          _diamonds.insert(cell);
          const auto corners = _topology.cellVertices(cell);
          for(std::size_t i = 0; i < corners.size(); ++i) {
            _stars.insert(corners[i]);
            _fans.insert(corners[i]);
            for(const Id central : _topology.incidentCells(corners[i]))
              _diamonds.insert(central);
            const auto edge = std::minmax(corners[i], corners[(i + 1) % corners.size()]);
            _swaps.insert(edge);
            _merges.insert(edge);
          }
        }
        // A strip can start up to six dual edges from a changed cell.
        // This is scheduling only: candidate guards still evaluate C alone.
        std::set<Id> reached = incident, frontier = incident;
        for(int depth = 0; depth <= 6 && !frontier.empty(); ++depth) {
          std::set<Id> next;
          for(const Id cell : frontier) {
            if((_options.v2SearchMode & 1) && depth <= 3) _repairCells.insert(cell);
            if(_topology.cornerCount(cell) == 3) {
              _strips.insert(cell);
              if(_options.v2SearchMode & 2) _composedTriangles.insert(cell);
            }
            for(const Id neighbor : _topology.neighbors(cell))
              if(reached.insert(neighbor).second) next.insert(neighbor);
          }
          frontier.swap(next);
        }
      }

      std::uint64_t rejectionKey(Rule rule, const FaceHalfEdge::Cavity &cavity) const
      {
        // Terminal candidates include a coupled local solve. A rejection of
        // the earlier closed-form placement must not suppress that retry.
        return attemptKey(rule, cavity) ^
          (_terminalMandatory ? 0xd6e8feb86659fd93ull : 0ull) ^
          (_terminalPairs ? 0xa0761d6478bd642full : 0ull);
      }

      bool cached(Rule rule, const FaceHalfEdge::Cavity &cavity)
      {
        const auto found = _rejected.find(rejectionKey(rule, cavity));
        if(found == _rejected.end() ||
           found->second.localState != _topology.state(cavity) ||
           (found->second.contextDependent &&
            found->second.contextRevision != _context.revision)) return false;
        if(found->second.contextDependent) _hasContextRejections = true;
        ++_stats[rule].cache;
        ++_result.rejectedCacheHits;
        return true;
      }

      void traceGuard(const char *kind, const Score &before, const Score &after) const
      {
        if(_options.verbose < 2) return;
        Msg::Info("QuadOptimizerV2 acceptedGuard kind=%s sizeWorst=%.17g->%.17g "
                  "sizePenalty=%.17g->%.17g cadMeanNormalized=%.17g->%.17g "
                  "cadMaxNormalized=%.17g->%.17g",
                  kind, before.worstSizeViolation, after.worstSizeViolation,
                  before.sizePenalty, after.sizePenalty,
                  before.cadNormalizedMeanSquared, after.cadNormalizedMeanSquared,
                  before.cadNormalizedMaximum, after.cadNormalizedMaximum);
        Msg::Info("QuadOptimizerV2 acceptedQuality absoluteBad=%zu->%zu "
                  "absoluteViolations=%zu->%zu cadInitialMean=%.17g "
                  "cadGlobalMean=%.17g cadInitialMaximum=%.17g cadAcceptedMaximum=%.17g",
                  before.shape.absoluteBadElementCount, after.shape.absoluteBadElementCount,
                  before.shape.absoluteViolationCount, after.shape.absoluteViolationCount,
                  _context.initialCadMean,
                  _context.cad.normalizedSquaredDistanceIntegral / _context.cad.sampledArea,
                  _context.initialCadMaximum, after.cadNormalizedMaximum);
      }

      bool commit(BuiltCandidate &built)
      {
        _parameters.reserve(_parameters.size() + built.newVertices.size());
        std::vector<MVertex *> retired;
        if(!_topology.replace(built.replacement, nullptr, &retired)) return false;
        // GFace owns all installed objects now, before any queue allocation.
        for(auto &element : built.elements) element.release();
        for(auto &vertex : built.newVertices) {
          MVertex *installed = vertex.release();
          _parameters.insert(built.parameters.extract(installed));
        }
        for(MVertex *vertex : retired) _parameters.erase(vertex);
        enqueueAffected(_topology.lastTouchedVertices());
        activateSmoothing(_topology.lastTouchedVertices());
        _smoothingColorsValid = false;
        ++_accepted;
        ++_result.acceptedCavities;
        return true;
      }

      CadDistance::Contribution trianglePairCad(
        const std::vector<MElement *> &elements,
        const std::unordered_map<MVertex *, UV> *overrides = nullptr)
      {
        CadDistance::Contribution result;
        for(MElement *element : elements) {
          std::vector<UV> uv;
          if(element->getNumPrimaryVertices() != 3 ||
             !elementParameters(element, overrides, uv)) return {};
          result += CadDistance::sampleElement(_face, element, uv,
            [&](const Point &xyz, const UV &parameter) {
              return localTarget(xyz, parameter);
            }, &_distanceCache, true);
        }
        return result;
      }

      bool followsCavityChart(const FaceHalfEdge::Cavity &cavity,
                             const BuiltCandidate &candidate)
      {
        Candidate boundary;
        if(!baseCandidate(cavity, boundary) || boundary.vertices.size() < 3) return false;
        double area = 0.;
        for(std::size_t i = 1; i + 1 < boundary.vertices.size(); ++i)
          area += GeometryGuard::localOrientationCross2(boundary.vertices[0].uv,
            boundary.vertices[i].uv, boundary.vertices[i + 1].uv);
        if(!std::isfinite(area) || area == 0.) return false;
        const double sign = area > 0. ? 1. : -1.;
        for(MElement *element : candidate.elementPointers) {
          std::vector<UV> uv;
          if(!elementParameters(element, &candidate.parameters, uv) ||
             (uv.size() != 3 && uv.size() != 4)) return false;
          double scale2 = 0.;
          for(std::size_t i = 0; i < uv.size(); ++i)
            for(std::size_t j = i + 1; j < uv.size(); ++j)
              scale2 = std::max(scale2, GeometryGuard::localOrientationDistance2(uv[i], uv[j]));
          if(!std::isfinite(scale2) || !(scale2 > 0.)) return false;
          // For a bilinear quad the signed chart Jacobian is affine: its
          // four corner signs also bound all interior/Gauss-point signs.
          for(std::size_t i = 0; i < uv.size(); ++i) {
            const double jacobian = sign * GeometryGuard::localOrientationCross2(
              uv[i], uv[(i + 1) % uv.size()], uv[(i + 2) % uv.size()]);
            if(!std::isfinite(jacobian) || jacobian <= 1.e-12 * scale2) return false;
          }
        }
        return true;
      }

      bool attempt(Rule rule, const FaceHalfEdge::Cavity &cavity,
                   std::vector<Candidate> candidates, bool mandatory)
      {
        if(cavity.empty()) return false;
        // Callers check before generation; keep this guard for direct users.
        if(cached(rule, cavity)) return false;
        const std::uint64_t key = rejectionKey(rule, cavity);
        const std::uint64_t state = _topology.state(cavity);
        bool contextDependent = false;
        RuleStats &stats = _stats[rule];
        ++stats.applicable;
        ++_result.cavitiesVisited;
        const std::vector<MElement *> beforeElements = cavityElements(cavity);
        const bool merge = rule == Rule::TriangleStrip && cavity.cells.size() == 2;
        Score reference = score(beforeElements, nullptr, false);
        // A physically inverted input can have excellent unsigned angles and
        // edge lengths. Repairing it must take precedence over those quotas.
        // Every replacement still passes the full physical/topological and
        // CAD guards below; an unavailable geometry query is not a repair.
        const bool physicalRepair = reference.physicalInvalid != 0;
        bool referenceCad = false;
        const auto beforeConnectivity = connectivity(cavity);
        using Signature = std::pair<std::vector<std::vector<Id> >, std::vector<UV> >;
        std::set<Signature> unique;
        std::unique_ptr<BuiltCandidate> best;
        const char *bestName = "";
        Score bestScore;
        for(Candidate &candidate : candidates) {
          if(candidate.cells.empty() || connectivity(candidate) == beforeConnectivity)
            continue;
          if(_terminalMandatory && mandatory &&
             !smoothReplacementInterior(cavity, candidate)) {
            ++_result.rejectedByWinslow;
            continue;
          }
          const auto candidateConnectivity = connectivity(candidate);
          std::vector<UV> newPositions;
          for(const VertexSpec &vertex : candidate.vertices)
            if(!vertex.vertex) newPositions.push_back(vertex.uv);
          if(candidate.cells.empty() || candidateConnectivity == beforeConnectivity ||
             !unique.insert({candidateConnectivity, newPositions}).second) continue;
          ++stats.candidates;
          ++_result.topologyCandidatesOptimized;
          if(!preservesCadConstraints(beforeConnectivity, candidateConnectivity)) {
            ++stats.topology; ++_result.rejectedByTopology; continue;
          }
          std::unique_ptr<BuiltCandidate> built(new BuiltCandidate);
          _buildingCavity = &cavity;
          bool prepared = build(candidate, *built);
          if(prepared) {
            // An optimistic numerical score can reject a doomed rewrite
            // before allocating its topological proof or locating CAD normals.
            const Score cheap = score(built->elementPointers, &built->parameters,
                                      false, true, false);
            const auto preferred = _context.quality.replaced(
              reference.criteria, cheap.criteria).preferredDeficit();
            const auto oldPreferred = _context.quality.preferredDeficit();
            const auto prefix = std::make_tuple(
              cheap.invalid, cheap.sizeViolations, cheap.shape.absoluteBadElementCount,
              cheap.shape.absoluteViolationCount, cheap.triangles, preferred);
            const auto oldPrefix = std::make_tuple(
              reference.invalid, reference.sizeViolations, reference.shape.absoluteBadElementCount,
              reference.shape.absoluteViolationCount, reference.triangles, oldPreferred);
            const bool sizeRejected = cheap.invalidSize ||
              (!physicalRepair && !boundedSize(cheap, reference));
            if(cheap.invalid || sizeRejected ||
               (!physicalRepair && !mandatory && !boundedQuality(cheap, reference)) ||
               (!physicalRepair && !mandatory && !merge && (prefix > oldPrefix ||
                (prefix == oldPrefix && cheap.maximumAngularDeviation >
                  reference.maximumAngularDeviation + _options.objectiveRelativeTolerance)))) {
              _buildingCavity = nullptr;
              // Geometric/absolute failures depend only on this cavity.
              // Only a rejection decided by model-wide preferred quotas
              // needs another attempt when a distant cavity changes them.
              const auto localPrefix = std::make_tuple(cheap.invalid, cheap.sizeViolations,
                cheap.shape.absoluteBadElementCount, cheap.shape.absoluteViolationCount,
                cheap.triangles);
              const auto oldLocalPrefix = std::make_tuple(reference.invalid, reference.sizeViolations,
                reference.shape.absoluteBadElementCount, reference.shape.absoluteViolationCount,
                reference.triangles);
              if(!cheap.invalid && !sizeRejected && boundedQuality(cheap, reference) &&
                 ((_terminalMandatory && preferred > oldPreferred) ||
                  localPrefix == oldLocalPrefix)) {
                contextDependent = true;
                _hasContextRejections = true;
              }
              if(cheap.invalid) {
                ++stats.orientation; ++_result.rejectedByOrientation;
              }
              else if(sizeRejected) {
                ++stats.size; ++_result.rejectedBySize;
              }
              else {
                ++stats.quality; ++_result.rejectedByQuality;
              }
              continue;
            }
            prepared = _topology.prepareReplacement(
              cavity, built->elementPointers, built->replacement);
          }
          if(!prepared) {
            for(Cell &cell : candidate.cells) std::reverse(cell.begin(), cell.end());
            prepared = build(candidate, *built) &&
              _topology.prepareReplacement(cavity, built->elementPointers, built->replacement);
          }
          _buildingCavity = nullptr;
          if(!prepared) {
            ++stats.topology; ++_result.rejectedByTopology; continue;
          }
          if(physicalRepair && !followsCavityChart(cavity, *built)) {
            ++stats.orientation; ++_result.rejectedByOrientation; continue;
          }
          if(!physicalRepair && rule == Rule::TriangleStrip && cavity.cells.size() == 2 &&
             _options.minimumRecombinationQuality > 0. &&
             built->elementPointers.size() == 1 &&
             built->elementPointers.front()->etaShapeMeasure() <
               _options.minimumRecombinationQuality) {
            ++stats.quality; ++_result.rejectedByQuality; continue;
          }
          if(merge) {
            bool allowed = true;
            for(MElement *element : built->elementPointers) {
              if(element->getNumPrimaryVertices() != 4) continue;
              const auto assessment = assessFinalQuad(element, &built->parameters);
              if(!assessment.parametrized || assessment.queryFailures ||
                 assessment.invalid || assessment.unacceptable ||
                 assessment.cadRepair) allowed = false;
            }
            if(!allowed) {
              ++stats.cad; ++_result.rejectedByCad; continue;
            }
          }
          Score candidateScore = score(built->elementPointers, &built->parameters, false);
          if(candidateScore.invalid ||
             ((physicalRepair || merge) && candidateScore.incompleteOrientation)) {
            ++stats.orientation; ++_result.rejectedByOrientation; continue;
          }
          if(candidateScore.invalidSize ||
             (!physicalRepair && !boundedSize(candidateScore, reference))) {
            ++stats.size; ++_result.rejectedBySize; continue;
          }
          if(!physicalRepair && ((!mandatory && !boundedQuality(candidateScore, reference)) ||
             (rule == Rule::TriangleStrip && cavity.cells.size() == 2 &&
              candidateScore.shape.absoluteBadElementCount != 0))) {
            ++stats.quality; ++_result.rejectedByQuality; continue;
          }
          if(!referenceCad) {
            reference = score(beforeElements);
            referenceCad = true;
          }
          candidateScore = score(built->elementPointers, &built->parameters);
          if(!boundedLocalCad(candidateScore, reference)) {
            ++stats.cad; ++_result.rejectedByCad; continue;
          }
          if(!boundedGlobalCad(candidateScore, reference)) {
            contextDependent = true;
            _hasContextRejections = true;
            ++stats.cad; ++_result.rejectedByCad; continue;
          }
          if(!mandatory && !merge && !better(candidateScore, reference)) {
            contextDependent = true;
            _hasContextRejections = true;
            ++stats.quality; ++_result.rejectedByQuality; continue;
          }
          if(!best || better(candidateScore, bestScore, &reference)) {
            best = std::move(built);
            bestScore = candidateScore;
            bestName = candidate.name;
          }
        }
        if(!best || !commit(*best)) {
          _rejected[key] = {state, _context.revision, contextDependent};
          return false;
        }
        _context.replace(reference, bestScore);
        if(_terminalMandatory) ++_result.acceptedTerminalMandatoryCavities;
        ++stats.accepted;
        traceGuard("topology", reference, bestScore);
        if(_options.verbose)
          Msg::Info("QuadOptimizerV2 face=%d accepted %s C=%zu B=%zu stage=%s",
                    _face->tag(), bestName, cavity.cells.size(), cavity.boundary.size(),
                    _terminalMandatory ? "valence" :
                    _terminalPairs ? "merge" : "swap");
        return true;
      }

      bool interiorStar()
      {
        while(!_stars.empty()) {
          const Id center = *_stars.begin(); _stars.erase(_stars.begin());
          if(!_topology.vertex(center) || _topology.isBoundaryVertex(center)) continue;
          const std::vector<Id> ring = _topology.incidentCellRing(center);
          std::vector<std::size_t> pattern;
          for(const Id cell : ring) pattern.push_back(_topology.cornerCount(cell));
          const bool ttq = ring.size() == 3 &&
            std::count(pattern.begin(), pattern.end(), 3) == 2 &&
            std::count(pattern.begin(), pattern.end(), 4) == 1;
          const bool tttt = ring.size() == 4 &&
            std::count(pattern.begin(), pattern.end(), 3) == 4;
          bool qtqt = ring.size() == 4;
          if(qtqt)
            for(std::size_t i = 0; i < 4; ++i)
              qtqt = qtqt && pattern[i] != pattern[(i + 1) % 4] &&
                (pattern[i] == 3 || pattern[i] == 4);
          const bool qqtqqt = ring.size() == 6 &&
            HalfEdgeRewrite::matchesCyclicFacePattern(
              ring.empty() ? std::vector<Id>() :
                std::vector<Id>(pattern.begin(), pattern.end()),
              std::vector<Id>{3, 4, 4, 3, 4, 4});
          const bool tqtqq = ring.size() == 5 &&
            HalfEdgeRewrite::matchesCyclicFacePattern(
              std::vector<Id>(pattern.begin(), pattern.end()),
              std::vector<Id>{3, 4, 3, 4, 4});
          const bool valenceSix = ring.size() == 6 &&
            std::count(pattern.begin(), pattern.end(), 4) == 6;
          if(!ttq && !tttt && !qtqt && !qqtqqt && !tqtqq && !valenceSix)
            continue;
          if(ttq) ++_result.interiorTriangleTriangleQuadStarsVisited;
          else if(tttt) ++_result.interiorFourTriangleFansVisited;
          else if(qtqt)
            ++_result.interiorAlternatingQuadTriangleStarsVisited;
          else if(qqtqqt) ++_result.interiorQQTQQTStarsVisited;
          else if(valenceSix) ++_result.valenceSixVerticesVisited;
          FaceHalfEdge::Cavity cavity;
          if(!_topology.vertexCavity(center, cavity) ||
             cavity.interior != std::vector<Id>{center})
            continue;
          const Rule rule = tqtqq ? Rule::InteriorTQTQQ :
            qqtqqt ? Rule::InteriorQQTQQT :
            valenceSix ? Rule::ValenceSix : Rule::InteriorStar;
          if((valenceSix && !_options.splitValenceSixVertices) ||
             ((!valenceSix && !qqtqqt) && !_options.optimizeOneInteriorVertexCavities) ||
             cached(rule, cavity)) continue;
          std::vector<Candidate> candidates =
            tqtqq ? onePointStarCandidates(cavity, center) :
            qqtqqt || valenceSix ?
              splitInteriorStarCandidates(cavity, center, qqtqqt) :
              polygonCandidates(cavity, ttq ? "QTT->Q" :
                tttt ? "TTTT->Q" : "QTQT->QQ");
          if(attempt(rule, cavity, std::move(candidates), true)) {
            if(ttq) ++_result.acceptedInteriorTriangleTriangleQuadReductions;
            else if(tttt) ++_result.acceptedInteriorFourTriangleFanReductions;
            else if(qtqt)
              ++_result.acceptedInteriorAlternatingQuadTriangleReductions;
            else if(qqtqqt) ++_result.acceptedInteriorQQTQQTReductions;
            else if(tqtqq) ++_result.acceptedOneInteriorVertexCavities;
            else ++_result.acceptedValenceSixSplits;
            if(_options.verbose && qqtqqt)
              Msg::Info("QuadOptimizerV2 half-edge rule "
                        "interior_qqtqqt_to_6q accepted=1");
            if(_options.verbose && valenceSix)
              Msg::Info("QuadOptimizerV2 half-edge rule "
                        "valence6_split accepted=1");
            return true;
          }
        }
        return false;
      }

      bool boundaryFan()
      {
        while(!_fans.empty()) {
          const Id center = *_fans.begin(); _fans.erase(_fans.begin());
          if(!_options.convertBoundaryTriangleQuadTriangleFans ||
             !_topology.vertex(center) || !_topology.isBoundaryVertex(center)) continue;
          const std::vector<Id> ring = _topology.incidentCellRing(center);
          if(ring.size() < 3 || _topology.cornerCount(ring.front()) != 3 ||
             _topology.cornerCount(ring.back()) != 3)
            continue;
          bool middleQuads = true;
          for(std::size_t i = 1; i + 1 < ring.size(); ++i)
            middleQuads = middleQuads && _topology.cornerCount(ring[i]) == 4;
          if(!middleQuads) continue;
          FaceHalfEdge::Cavity cavity;
          if(!_topology.vertexCavity(center, cavity) ||
             cavity.boundary.size() % 2)
            continue;
          if(cached(Rule::BoundaryFan, cavity)) continue;
          std::vector<Candidate> candidates;
          candidates.push_back(fanCandidate(
            cavity, nullptr, true, 0, "boundary T-Q^n-T"));
          candidates.push_back(fanCandidate(
            cavity, nullptr, true, 1, "boundary T-Q^n-T"));
          ++_result.boundaryTriangleQuadTriangleFansVisited;
          if(attempt(Rule::BoundaryFan, cavity, std::move(candidates), true)) {
            ++_result.acceptedBoundaryTriangleQuadTriangleFans;
            return true;
          }
        }
        return false;
      }

      Candidate collapsedDiamond(const FaceHalfEdge::Cavity &cavity,
                                 Id firstPole, Id secondPole,
                                 Id retained, Id central)
      {
        Candidate candidate;
        candidate.name = "diamond";
        if(!baseCandidate(cavity, candidate)) return {};
        std::unordered_map<Id, std::size_t> local;
        for(std::size_t i = 0; i < cavity.boundary.size(); ++i)
          local[cavity.boundary[i]] = i;
        MVertex *retainedVertex = _topology.vertex(retained);
        UV retainedUv;
        if(!retainedVertex || !parameter(retainedVertex, retainedUv)) return {};
        const std::size_t pole = candidate.vertices.size();
        candidate.vertices.push_back(
          {retainedVertex, retainedUv, point(retainedVertex)});
        local[firstPole] = pole;
        local[secondPole] = pole;
        for(const Id cell : cavity.cells) {
          if(cell == central) continue;
          Cell replacement;
          std::set<std::size_t> unique;
          for(const Id vertex : _topology.cellVertices(cell)) {
            const auto found = local.find(vertex);
            if(found == local.end() || !unique.insert(found->second).second)
              return {};
            replacement.push_back(found->second);
          }
          candidate.cells.push_back(std::move(replacement));
        }
        return candidate;
      }

      bool diamond()
      {
        while(!_diamonds.empty()) {
          const Id central = *_diamonds.begin(); _diamonds.erase(_diamonds.begin());
          if(!_options.eliminateDiamonds || _topology.cornerCount(central) != 4) continue;
          const std::vector<Id> corners = _topology.cellVertices(central);
          for(int diagonal = 0; diagonal < 2; ++diagonal) {
            const Id first = corners[diagonal];
            const Id second = corners[diagonal + 2];
            if(_topology.isBoundaryVertex(first) ||
               _topology.isBoundaryVertex(second))
              continue;
            const auto firstStar = _topology.incidentCells(first);
            const auto secondStar = _topology.incidentCells(second);
            const auto allQuads = [&](const std::vector<Id> &star) {
              return std::all_of(star.begin(), star.end(), [&](Id cell) {
                return _topology.cornerCount(cell) == 4;
              });
            };
            // The valence phase removes true 3-3 diamonds only. A 3-4
            // collapse creates a valence-5 pole and is a discretionary
            // coarsening operation, not a mandatory final repair.
            if(_terminalMandatory &&
               (firstStar.size() != 3 || secondStar.size() != 3)) continue;
            if(!allQuads(firstStar) || !allQuads(secondStar) ||
               firstStar.size() > 4 || secondStar.size() > 4 ||
               (firstStar.size() != 3 && secondStar.size() != 3))
              continue;
            std::vector<Id> support = firstStar;
            support.insert(support.end(), secondStar.begin(), secondStar.end());
            std::sort(support.begin(), support.end());
            support.erase(std::unique(support.begin(), support.end()),
                          support.end());
            FaceHalfEdge::Cavity cavity;
            if(!_topology.cavity(support, cavity) ||
               cavity.interior.size() != 2 ||
               std::find(cavity.interior.begin(), cavity.interior.end(), first) ==
                 cavity.interior.end() ||
               std::find(cavity.interior.begin(), cavity.interior.end(), second) ==
                 cavity.interior.end())
              continue;
            if(cached(Rule::Diamond, cavity)) continue;
            std::vector<Candidate> candidates;
            candidates.push_back(collapsedDiamond(
              cavity, first, second, first, central));
            candidates.push_back(collapsedDiamond(
              cavity, first, second, second, central));
            for(const Id retained : {first, second})
              for(std::size_t parity = 0; parity < 2; ++parity)
                candidates.push_back(fanCandidate(
                  cavity, _topology.vertex(retained), false, parity, "diamond fan"));
            ++_result.diamondsVisited;
            if(attempt(Rule::Diamond, cavity, std::move(candidates), true)) {
              ++_result.acceptedDiamonds;
              return true;
            }
          }
        }
        return false;
      }

      bool stripPath(const std::vector<Id> &path)
      {
        if(path.size() < 2 || _topology.cornerCount(path.front()) != 3 ||
           _topology.cornerCount(path.back()) != 3)
          return false;
        for(std::size_t i = 1; i + 1 < path.size(); ++i)
          if(_topology.cornerCount(path[i]) != 4) return false;
        FaceHalfEdge::Cavity cavity;
        const std::size_t quads = path.size() - 2;
        if(_terminalMandatory && quads == 0) return false;
        if(!_topology.cavity(path, cavity) || !cavity.interior.empty() ||
           cavity.boundary.size() != 2 * quads + 4)
          return false;
        if(cached(Rule::TriangleStrip, cavity)) return false;
        std::vector<Candidate> candidates;
        if(quads <= 2) candidates = polygonCandidates(cavity, "T-Q^n-T");
        else {
          const auto shared = [&](Id a, Id b) {
            std::vector<Id> result;
            const auto other = _topology.cellVertices(b);
            for(const Id vertex : _topology.cellVertices(a))
              if(std::find(other.begin(), other.end(), vertex) != other.end())
                result.push_back(vertex);
            return result;
          };
          const auto entry = shared(path[0], path[1]);
          if(entry.size() != 2) return false;
          Id firstApex = HalfEdgeMesh::invalid;
          for(const Id vertex : _topology.cellVertices(path[0]))
            if(vertex != entry[0] && vertex != entry[1]) firstApex = vertex;
          std::vector<Id> left = {firstApex, entry[0]}, right = {firstApex, entry[1]};
          for(std::size_t i = 1; i + 1 < path.size(); ++i) {
            const auto corners = _topology.cellVertices(path[i]);
            const auto exit = shared(path[i], path[i + 1]);
            if(exit.size() != 2) return false;
            Id nextLeft = HalfEdgeMesh::invalid, nextRight = HalfEdgeMesh::invalid;
            for(std::size_t j = 0; j < 4; ++j) {
              if(corners[j] == left.back())
                nextLeft = corners[(j + 1) % 4] == right.back() ?
                  corners[(j + 3) % 4] : corners[(j + 1) % 4];
              if(corners[j] == right.back())
                nextRight = corners[(j + 1) % 4] == left.back() ?
                  corners[(j + 3) % 4] : corners[(j + 1) % 4];
            }
            if(std::minmax(nextLeft, nextRight) != std::minmax(exit[0], exit[1]))
              return false; // Curved fans have their own bounded operator.
            left.push_back(nextLeft); right.push_back(nextRight);
          }
          Id lastApex = HalfEdgeMesh::invalid;
          for(const Id vertex : _topology.cellVertices(path.back()))
            if(vertex != left.back() && vertex != right.back()) lastApex = vertex;
          left.push_back(lastApex); right.push_back(lastApex);
          std::vector<std::size_t> leftLocal, rightLocal;
          for(const auto &rail : {left, right}) {
            std::vector<std::size_t> local;
            for(const Id vertex : rail) {
              const auto found = std::find(cavity.boundary.begin(), cavity.boundary.end(), vertex);
              if(found == cavity.boundary.end()) return false;
              local.push_back(found - cavity.boundary.begin());
            }
            if(leftLocal.empty()) leftLocal = std::move(local);
            else rightLocal = std::move(local);
          }
          for(const auto &filling : HalfEdgeRewrite::triangleQuadStripZipperReconnections(leftLocal, rightLocal))
            candidates.push_back(polygonCandidate(cavity, filling, "T-Q^n-T zipper"));
        }
        // TT uses the acceptable-quad gate; longer strips are valence rewrites.
        if(attempt(Rule::TriangleStrip, cavity, std::move(candidates), quads != 0)) {
          ++_result.acceptedQuadTwoTriangleReductions;
          return true;
        }
        return false;
      }

      bool triangleStrip()
      {
        while(!_strips.empty()) {
          const Id start = *_strips.begin(); _strips.erase(_strips.begin());
          if(_topology.cornerCount(start) != 3) continue;
          std::vector<std::vector<Id> > pending(1, {start});
          while(!pending.empty()) {
            std::vector<Id> path = std::move(pending.back());
            pending.pop_back();
            const Id current = path.back();
            for(const Id next : _topology.neighbors(current)) {
              if(std::find(path.begin(), path.end(), next) != path.end())
                continue;
              const std::size_t corners = _topology.cornerCount(next);
              if(corners == 3) {
                {
                  std::vector<Id> complete = path;
                  complete.push_back(next);
                  ++_result.quadTwoTriangleCavitiesVisited;
                  if(stripPath(complete)) return true;
                }
              }
              else if(corners == 4 && path.size() < 6) {
                std::vector<Id> longer = path;
                longer.push_back(next);
                pending.push_back(std::move(longer));
              }
            }
          }
        }
        return false;
      }

      std::vector<Candidate> qqCandidates(
        const FaceHalfEdge::Cavity &cavity)
      {
        return polygonCandidates(cavity, "QQ swap");
      }

      std::vector<Candidate> qtCandidates(
        const FaceHalfEdge::Cavity &cavity)
      {
        std::vector<Candidate> result;
        if(cavity.boundary.size() != 5) return result;
        for(std::size_t i = 0; i < 5; ++i) {
          Candidate candidate;
          candidate.name = "QT swap";
          if(!baseCandidate(cavity, candidate)) continue;
          candidate.cells = {
            {i, (i + 1) % 5, (i + 2) % 5},
            {(i + 2) % 5, (i + 3) % 5, (i + 4) % 5, i}};
          result.push_back(std::move(candidate));
        }
        return result;
      }

      std::vector<Candidate> ttCandidates(
        const FaceHalfEdge::Cavity &cavity)
      {
        std::vector<Candidate> result;
        if(cavity.boundary.size() != 4) return result;
        for(std::size_t i = 0; i < 2; ++i) {
          Candidate candidate;
          candidate.name = "TT swap";
          if(!baseCandidate(cavity, candidate)) continue;
          candidate.cells = {{i, (i + 1) % 4, (i + 2) % 4},
            {(i + 2) % 4, (i + 3) % 4, i}};
          result.push_back(std::move(candidate));
        }
        return result;
      }

      bool chordMidpointCadRatio(const VertexSpec &a, const VertexSpec &b,
                                 double &ratio)
      {
        Point middle;
        UV guess;
        for(int d = 0; d < 3; ++d) middle[d] = .5 * (a.xyz[d] + b.xyz[d]);
        for(int d = 0; d < 2; ++d) guess[d] = .5 * (a.uv[d] + b.uv[d]);
        try {
          const double h = localTarget(middle, guess);
          const GPoint projected = _face->closestPointFromTrustedGuess(
            SPoint3(middle[0], middle[1], middle[2]), guess.data());
          if(!(h > 0.) || !std::isfinite(h) || !projected.succeeded()) return false;
          ratio = std::hypot(projected.x() - middle[0],
            projected.y() - middle[1], projected.z() - middle[2]) / h;
          return std::isfinite(ratio);
        }
        catch(...) { return false; }
      }

      bool geometryDrivenEdgeSwap(const FaceHalfEdge::Cavity &cavity,
                                  std::vector<Candidate> candidates,
                                  bool terminal = false)
      {
        if(cavity.cells.size() != 2 || !cavity.interior.empty()) return false;
        const auto beforeConnectivity = connectivity(cavity);
        const auto sharedEdge = [](const std::vector<std::vector<Id> > &cells,
                                   std::pair<Id, Id> &shared) {
          std::map<std::pair<Id, Id>, std::size_t> incidences;
          for(const auto &cell : cells)
            for(std::size_t i = 0; i < cell.size(); ++i)
              ++incidences[std::minmax(cell[i], cell[(i + 1) % cell.size()])];
          std::size_t count = 0;
          for(const auto &entry : incidences) {
            if(entry.second > 2) return false;
            if(entry.second == 2) { shared = entry.first; ++count; }
          }
          return count == 1;
        };
        std::pair<Id, Id> oldEdge;
        Candidate boundary;
        if(!sharedEdge(beforeConnectivity, oldEdge) ||
           !baseCandidate(cavity, boundary)) return false;
        const auto vertexSpec = [&](Id id) -> const VertexSpec * {
          MVertex *vertex = _topology.vertex(id);
          for(const auto &spec : boundary.vertices)
            if(spec.vertex == vertex) return &spec;
          return nullptr;
        };
        const VertexSpec *oldA = vertexSpec(oldEdge.first);
        const VertexSpec *oldB = vertexSpec(oldEdge.second);
        double oldRatio = 0.;
        const double trigger = _options.edgeMidpointCadSwapTriggerRatio;
        const double fraction = _options.edgeMidpointCadSwapMaximumRemainingFraction;
        if(!oldA || !oldB || !std::isfinite(trigger) || trigger < 0. ||
           !std::isfinite(fraction) || fraction < 0. || fraction >= 1. ||
           !chordMidpointCadRatio(*oldA, *oldB, oldRatio) || oldRatio <= trigger)
          return false;

        const auto reference = score(cavityElements(cavity));
        if(reference.invalid || reference.incompleteOrientation ||
           !reference.cad.complete()) return false;
        const bool trianglesOnly = reference.triangles == 2;
        if(!trianglesOnly && reference.triangles != 1) return false;
        if(trianglesOnly) ++_result.triangleTriangleSwapsVisited;
        const auto noWorse = [](double next, double old) {
          const double tolerance = 64. * std::numeric_limits<double>::epsilon() *
            std::max({std::abs(next), std::abs(old), std::numeric_limits<double>::min()});
          return std::isfinite(next) && std::isfinite(old) && next <= old + tolerance;
        };
        const auto decreases = [](double next, double old) {
          const double tolerance = 64. * std::numeric_limits<double>::epsilon() *
            std::max({std::abs(next), std::abs(old), std::numeric_limits<double>::min()});
          return std::isfinite(next) && std::isfinite(old) && next < old - tolerance;
        };
        std::unique_ptr<BuiltCandidate> best;
        Score bestScore;
        double bestRatio = oldRatio;
        for(Candidate &candidate : candidates) {
          const auto nextConnectivity = connectivity(candidate);
          std::pair<Id, Id> nextEdge;
          if(nextConnectivity == beforeConnectivity ||
             !sharedEdge(nextConnectivity, nextEdge) || nextEdge == oldEdge ||
             !preservesCadConstraints(beforeConnectivity, nextConnectivity)) continue;
          const VertexSpec *nextA = vertexSpec(nextEdge.first);
          const VertexSpec *nextB = vertexSpec(nextEdge.second);
          double nextRatio = 0.;
          if(!nextA || !nextB || !chordMidpointCadRatio(*nextA, *nextB, nextRatio) ||
             nextRatio > fraction * oldRatio) continue;

          std::unique_ptr<BuiltCandidate> built(new BuiltCandidate);
          _buildingCavity = &cavity;
          bool ready = build(candidate, *built) && _topology.prepareReplacement(
            cavity, built->elementPointers, built->replacement);
          if(!ready) {
            for(Cell &cell : candidate.cells) std::reverse(cell.begin(), cell.end());
            ready = build(candidate, *built) && _topology.prepareReplacement(
              cavity, built->elementPointers, built->replacement);
          }
          _buildingCavity = nullptr;
          if(!ready || !built->newVertices.empty() ||
             !followsCavityChart(cavity, *built)) continue;
          const auto next = score(built->elementPointers, &built->parameters);
          // Geometry may outrank preferred angles, but never absolute
          // element limits, complete physical orientation or size safety.
          if(next.invalid || next.incompleteOrientation ||
             next.shape.absoluteBadElementCount || !boundedQuality(next, reference) ||
             !boundedSize(next, reference) || !boundedCad(next, reference)) continue;
          bool quadsAdmissible = true;
          for(MElement *element : built->elementPointers) {
            if(element->getNumPrimaryVertices() != 4) continue;
            const auto assessment = assessFinalQuad(element, &built->parameters);
            if(!assessment.parametrized || assessment.queryFailures ||
               assessment.invalid || assessment.cadRepair ||
               !evaluateElementQuality(element).passesAbsoluteSpecifications)
              quadsAdmissible = false;
          }
          if(!quadsAdmissible ||
             !decreases(next.cad.squaredDistanceIntegral,
                        reference.cad.squaredDistanceIntegral) ||
             !noWorse(next.cad.normalizedSquaredDistanceIntegral,
                      reference.cad.normalizedSquaredDistanceIntegral) ||
             !noWorse(next.cad.maximumDistance, reference.cad.maximumDistance) ||
             !noWorse(next.cad.maximumNormalizedDistance,
                      reference.cad.maximumNormalizedDistance)) continue;
          const auto rank = std::make_tuple(next.cad.squaredDistanceIntegral,
            next.cad.maximumDistance, nextRatio);
          const auto bestRank = std::make_tuple(bestScore.cad.squaredDistanceIntegral,
            bestScore.cad.maximumDistance, bestRatio);
          if(!best || rank < bestRank) {
            best = std::move(built);
            bestScore = next;
            bestRatio = nextRatio;
          }
        }
        if(!best || !commit(*best)) return false;
        _context.replace(reference, bestScore);
        ++_result.acceptedEdgeSwaps;
        if(trianglesOnly) {
          ++_result.acceptedTriangleTriangleSwaps;
          ++_result.acceptedGeometryDrivenTriangleTriangleSwaps;
          if(terminal) ++_result.finalTtCadSwaps;
        }
        else {
          ++_result.acceptedGeometryDrivenMixedTriangleQuadSwaps;
          ++_result.finalQtSwaps;
        }
        traceGuard("CAD edge swap", reference, bestScore);
        if(_options.verbose)
          Msg::Info("QuadOptimizerV2 %s CAD swap face=%d midpoint/h=%.9g->%.9g "
                    "integral=%.9g->%.9g maximum=%.9g->%.9g terminal=%d",
                    trianglesOnly ? "TT" : "TQ", _face->tag(), oldRatio, bestRatio,
                    reference.cad.squaredDistanceIntegral, bestScore.cad.squaredDistanceIntegral,
                    reference.cad.maximumDistance, bestScore.cad.maximumDistance, terminal);
        return true;
      }

      bool swaps(bool pairsOnly = false)
      {
        auto &pending = pairsOnly ? _merges : _swaps;
        while(!pending.empty()) {
          const auto endpoints = *pending.begin(); pending.erase(pending.begin());
          FaceHalfEdge::Edge edge;
          edge.first = endpoints.first; edge.second = endpoints.second;
          for(const Id cell : _topology.incidentCells(edge.first)) {
            const auto corners = _topology.cellVertices(cell);
            for(std::size_t i = 0; i < corners.size(); ++i)
              if(std::minmax(corners[i], corners[(i + 1) % corners.size()]) ==
                 std::minmax(edge.first, edge.second)) edge.cells.push_back(cell);
          }
          if(edge.cells.size() != 2) continue;
          FaceHalfEdge::Cavity cavity;
          if(!_topology.edgeCavity(edge.first, edge.second, cavity) ||
             !cavity.interior.empty())
            continue;
          const std::size_t first = _topology.cornerCount(edge.cells[0]);
          const std::size_t second = _topology.cornerCount(edge.cells[1]);
          if(!pairsOnly && first == 4 && second == 4 && cavity.boundary.size() == 6) {
            if(!cached(Rule::QuadQuad, cavity) &&
               attempt(Rule::QuadQuad, cavity, qqCandidates(cavity), false)) {
              ++_result.acceptedEdgeSwaps;
              return true;
            }
          }
          else if(!pairsOnly && ((first == 3 && second == 4) ||
                   (first == 4 && second == 3)) &&
                  cavity.boundary.size() == 5) {
            if(!cached(Rule::QuadTriangle, cavity) &&
               attempt(Rule::QuadTriangle, cavity, qtCandidates(cavity), false)) {
              ++_result.acceptedEdgeSwaps;
              ++_result.finalQtSwaps;
              return true;
            }
          }
          else if(first == 3 && second == 3 &&
                  cavity.boundary.size() == 4) {
            if(pairsOnly) {
              if(stripPath(edge.cells)) {
                ++_result.finalTtMerges;
                return true;
              }
              continue;
            }
            // The ordinary TT phase remains restricted to physical repair.
            // CAD swaps run only after quality swaps have finished, so an
            // angle-driven inverse cannot undo their geometric progress.
            if(!score(cavityElements(cavity), nullptr, false).physicalInvalid) continue;
            ++_result.triangleTriangleSwapsVisited;
            if(!cached(Rule::TriangleTriangle, cavity) &&
               attempt(Rule::TriangleTriangle, cavity, ttCandidates(cavity), false)) {
              ++_result.acceptedEdgeSwaps;
              ++_result.acceptedTriangleTriangleSwaps;
              return true;
            }
          }
        }
        return false;
      }

      struct NodeSmoothingJob {
        Id center;
        FaceHalfEdge::Cavity cavity;
        std::vector<UV> uv;
        std::vector<UV> plane;
        Point origin, tangent1, tangent2;
        std::vector<bool> fixed;
        std::vector<std::array<std::size_t, 3> > triangles;
        std::vector<std::array<std::size_t, 4> > quadrangles;
        SmallCavityWinslowResult optimized;
        double orientation = 0., initialEnergy = 0.;
        const char *status = "invalid-star";
      };

      struct NodeSweepStats {
        std::size_t visited = 0, accepted = 0, solves = 0, cells = 0;
        std::size_t centroidTried = 0, centroidAccepted = 0;
        double minimumStep = 1., solveSeconds = 0., guardSeconds = 0.;
        double prepareSeconds = 0.;
        double maximumMove = 0., sumSquaredMove = 0.;
      } _nodeSweep;

      const std::vector<std::vector<Id> > &smoothingColors()
      {
        if(_smoothingColorsValid) return _smoothingColors;
        auto &colors = _smoothingColors;
        colors.clear();
        std::map<Id, std::size_t> assigned;
        for(Id center : _topology.vertices()) {
          MVertex *vertex = _topology.vertex(center);
          if(!vertex || vertex->onWhat() != _face ||
             _topology.isBoundaryVertex(center)) continue;
          std::set<std::size_t> forbidden;
          // Opposite corners of a quad also conflict: two same-color
          // centers must never change the same element.
          for(Id cell : _topology.incidentCells(center))
            for(Id neighbor : _topology.cellVertices(cell)) {
              const auto color = assigned.find(neighbor);
              if(color != assigned.end()) forbidden.insert(color->second);
            }
          std::size_t color = 0;
          while(forbidden.count(color)) ++color;
          if(color == colors.size()) colors.emplace_back();
          colors[color].push_back(center);
          assigned.emplace(center, color);
        }
        _smoothingColorsValid = true;
        return colors;
      }

      bool prepareNodeSmoothing(NodeSmoothingJob &job)
      {
        if(_smartSmoothing) {
          // No Winslow chart/energy or topological cavity proof is needed
          // for a single projected barycenter proposal on fixed connectivity.
          job.cavity.cells = _topology.incidentCells(job.center);
          if(job.cavity.cells.empty()) return false;
          for(Id cell : job.cavity.cells)
            for(Id id : _topology.cellVertices(cell)) {
              UV uv;
              if(!parameter(_topology.vertex(id), uv)) return false;
              job.uv.push_back(uv);
            }
          unwrap(job.uv);
          job.status = "ready";
          return true;
        }
        if(!_topology.vertexCavity(job.center, job.cavity) ||
           job.cavity.interior != std::vector<Id>{job.center} ||
           job.cavity.boundary.size() < 3) return false;
        // Center first: unwrap the small chart around the actual unknown.
        std::vector<Id> vertices(1, job.center);
        vertices.insert(vertices.end(), job.cavity.boundary.begin(),
                        job.cavity.boundary.end());
        job.uv.resize(vertices.size());
        for(std::size_t i = 0; i < vertices.size(); ++i)
          if(!parameter(_topology.vertex(vertices[i]), job.uv[i])) {
            job.status = "missing-parameters";
            return false;
          }
        unwrap(job.uv);
        std::vector<Point> xyz;
        for(Id id : vertices) xyz.push_back(point(_topology.vertex(id)));
        if(!meanPlaneChart(xyz, 1, xyz.size() - 1, 0, job.origin,
                           job.tangent1, job.tangent2, job.plane)) return false;
        job.fixed.assign(vertices.size(), true);
        job.fixed[0] = false;
        const auto twiceArea = [&](std::size_t a, std::size_t b, std::size_t c) {
          return (static_cast<long double>(job.plane[b][0]) - job.plane[a][0]) *
                   (static_cast<long double>(job.plane[c][1]) - job.plane[a][1]) -
                 (static_cast<long double>(job.plane[b][1]) - job.plane[a][1]) *
                   (static_cast<long double>(job.plane[c][0]) - job.plane[a][0]);
        };
        long double area = 0.;
        for(std::size_t i = 2; i + 1 < vertices.size(); ++i)
          area += twiceArea(1, i, i + 1);
        if(!std::isfinite(area) || area == 0.) {
          job.status = "degenerate-chart";
          return false;
        }
        job.orientation = area > 0. ? 1. : -1.;
        for(Id cell : job.cavity.cells) {
          std::vector<std::size_t> indices;
          for(Id vertex : _topology.cellVertices(cell)) {
            const auto found = std::find(vertices.begin(), vertices.end(), vertex);
            if(found == vertices.end()) return false;
            indices.push_back(found - vertices.begin());
          }
          if(indices.size() == 3)
            job.triangles.push_back({{indices[0], indices[1], indices[2]}});
          else if(indices.size() == 4) {
            for(std::size_t i = 0; i < 4; ++i) {
              const std::size_t a = indices[i], b = indices[(i + 1) % 4],
                                c = indices[(i + 2) % 4];
              if(a && b && c && !(job.orientation * twiceArea(a, b, c) > 0.)) {
                job.status = "fixed-corner";
                return false;
              }
            }
            job.quadrangles.push_back({{indices[0], indices[1], indices[2], indices[3]}});
          }
          else return false;
        }
        job.initialEnergy = evaluateLocalSurfacePatchWinslowEnergy(
          job.plane, job.triangles, job.quadrangles, job.orientation, _options.winslow.lambda);
        job.status = "ready";
        return true;
      }

      double minimumSine(const std::vector<MElement *> &elements,
                         MVertex *moved = nullptr, const Point *trial = nullptr) const
      {
        double result = 1.;
        for(MElement *element : elements) {
          const std::size_t count = element->getNumPrimaryVertices();
          if(count != 3 && count != 4) return -1.;
          std::array<Point, 4> xyz;
          for(std::size_t i = 0; i < count; ++i) {
            MVertex *v = element->getVertex(i);
            xyz[i] = v == moved && trial ? *trial : point(v);
          }
          result = std::min(result, SmartLaplacian::minimumCornerSine(xyz, count));
        }
        return result;
      }

      bool acceptNodeSmoothing(NodeSmoothingJob &job, const char *stage,
                               std::size_t sweep, std::size_t color,
                               const Point *centroid = nullptr)
      {
        MVertex *vertex = _topology.vertex(job.center);
        int trials = 0;
        double acceptedStep = 0.;
        const auto finish = [&](const char *status) {
          if(_options.verbose > 1 && (!centroid || acceptedStep > 0. || _smartSmoothing))
            Msg::Info("QuadOptimizerV2 face=%d %s stage=%s sweep=%zu "
                      "node=%zu color=%zu C=%zu status=%s step=%.17g trials=%d",
                      _face->tag(), _smartSmoothing ? "nodeSmartLaplacian" : "nodeWinslow",
                      stage, sweep, vertex->getNum(), color,
                      job.cavity.cells.size(), status, acceptedStep, trials);
          return acceptedStep > 0.;
        };
        if(!job.optimized.success || !job.optimized.untangled)
          return finish(job.status);
        UV oldUv;
        if(!parameter(vertex, oldUv)) return finish("missing-parameters");
        const Point oldXyz = point(vertex);
        const Point oldPlaneOffset = centroid ? Point{{0., 0., 0.}} : subtract(oldXyz, job.origin);
        const double dx = centroid ? 0. : job.plane[0][0] - dot(oldPlaneOffset, job.tangent1);
        const double dy = centroid ? 0. : job.plane[0][1] - dot(oldPlaneOffset, job.tangent2);
        const SPoint3 target(
          centroid ? (*centroid)[0] : oldXyz[0] + dx * job.tangent1[0] + dy * job.tangent2[0],
          centroid ? (*centroid)[1] : oldXyz[1] + dx * job.tangent1[1] + dy * job.tangent2[1],
          centroid ? (*centroid)[2] : oldXyz[2] + dx * job.tangent1[2] + dy * job.tangent2[2]);
        const GPoint projected = _face->closestPointFromTrustedGuess(target, oldUv.data());
        if(!projected.succeeded()) return finish("projection-rejected");
        const UV direction = {{projected.u() - oldUv[0],
                               projected.v() - oldUv[1]}};
        const double roundoff = 64. * std::numeric_limits<double>::epsilon();
        bool stationary = true;
        for(std::size_t axis = 0; axis < 2; ++axis) {
          double scale = std::abs(oldUv[axis]);
          for(const UV &uv : job.uv) scale = std::max(scale, std::abs(uv[axis]));
          stationary = stationary && std::abs(direction[axis]) <= roundoff * scale;
        }
        if(stationary) return finish("stationary");
        const auto elements = cavityElements(job.cavity);
        const double initialSine = minimumSine(elements);
        double proposedSine = 0.;
        if(_smartSmoothing) {
          Point proposed;
          if(!mappedPoint({{projected.u(), projected.v()}}, proposed))
            return finish("mapping-rejected");
          proposedSine = minimumSine(elements, vertex, &proposed);
          // Freitag's strict max-min acceptance. Evaluate the physical,
          // projected candidate, before paying for specification/CAD guards.
          if(!(proposedSine > initialSine + 64. * std::numeric_limits<double>::epsilon()))
            return finish("minimum-sine-rejected");
        }
        const Score reference = score(elements, nullptr, true, false);
        std::vector<double> oldWarping;
        for(MElement *element : elements)
          if(element->getNumPrimaryVertices() == 4)
            oldWarping.push_back(
              _elementCache.at(_topology.id(element)).quality.warpingDegrees);
        std::vector<ElementCache> evaluated;
        const double tolerance = std::max(1.e-12, _options.objectiveRelativeTolerance);
        const auto restore = [&]() {
          vertex->setXYZ(oldXyz[0], oldXyz[1], oldXyz[2]);
          vertex->setParameter(0, oldUv[0]);
          vertex->setParameter(1, oldUv[1]);
          _parameters[vertex] = oldUv;
        };
        struct RestoreOnExit {
          const decltype(restore) &action;
          bool active = true;
          ~RestoreOnExit() { if(active) action(); }
        } rollback{restore};
        const char *rejection = "stationary";
        const auto traceRejection = [&](double step) {
          if(_options.verbose > 1 && !centroid)
            Msg::Info("QuadOptimizerV2 face=%d nodeWinslow stage=%s sweep=%zu "
                      "node=%zu trial=%d step=%.17g rejected=%s",
                      _face->tag(), stage, sweep, vertex->getNum(), trials, step, rejection);
        };
        for(int trial = 0; trial < (centroid ? 1 : 12); ++trial) {
          trials = trial + 1;
          const double step = std::ldexp(1., -trial);
          const UV uv = {{oldUv[0] + step * direction[0],
                          oldUv[1] + step * direction[1]}};
          Point xyz;
          if(!mappedPoint(uv, xyz)) {
            rejection = "mapping-rejected";
            traceRejection(step);
            continue;
          }
          bool unchanged = true;
          for(std::size_t axis = 0; axis < 3; ++axis)
            unchanged = unchanged && std::abs(xyz[axis] - oldXyz[axis]) <=
              roundoff * std::max(std::abs(xyz[axis]), std::abs(oldXyz[axis]));
          if(unchanged) {
            rejection = "stationary";
            traceRejection(step);
            break;
          }
          vertex->setXYZ(xyz[0], xyz[1], xyz[2]);
          vertex->setParameter(0, uv[0]);
          vertex->setParameter(1, uv[1]);
          _parameters[vertex] = uv;
          // Screen the trial before paying for CAD projections. With a
          // zero candidate CAD penalty, better() is an optimistic bound:
          // adding a nonnegative CAD penalty cannot rescue a rejected trial.
          Score candidate = score(elements, nullptr, false, false, false, &evaluated);
          bool warpingSafe = true;
          std::size_t quad = 0;
          for(std::size_t i = 0; i < elements.size(); ++i) {
            MElement *element = elements[i];
            if(element->getNumPrimaryVertices() != 4) continue;
            const double previous = oldWarping[quad++];
            const double next = evaluated[i].quality.warpingDegrees;
            warpingSafe = warpingSafe && std::isfinite(next) &&
              (std::isfinite(previous) && previous >= absoluteMaximumQuadWarpingDegrees ?
                 next <= previous + tolerance : next < absoluteMaximumQuadWarpingDegrees);
          }
          const bool sizeSafe = boundedSize(candidate, reference);
          const bool qualitySafe = boundedQuality(candidate, reference);
          // Both nodal proposals must improve the minimum physical corner
          // sine, while preserving absolute criteria and preferred quotas.
          const bool quotaSafe =
            _context.quality.replaced(reference.criteria, candidate.criteria).preferredDeficit() <=
            _context.quality.preferredDeficit();
          const bool improved = minimumSine(elements) > initialSine +
            std::max(64. * std::numeric_limits<double>::epsilon(), tolerance);
          const bool cheapSafe = !candidate.invalid && warpingSafe &&
            sizeSafe && qualitySafe && quotaSafe && improved;
          if(cheapSafe) {
            for(std::size_t i = 0; i < elements.size(); ++i) {
              ElementCache &entry = evaluated[i];
              entry.oriented = entry.parametrized &&
                followsFace(elements[i], entry.uv, &entry.opposed, &entry.orientationComplete);
              if(!entry.oriented) {
                ++candidate.invalid;
                continue;
              }
              entry.cad = CadDistance::sampleElement(_face, elements[i], entry.uv,
                [&](const Point &xyz, const UV &parameter) { return localTarget(xyz, parameter); },
                &_distanceCache);
              entry.cadKnown = true;
              if(!addCadContribution(entry.cad, candidate)) ++candidate.invalid;
            }
            if(candidate.cadWeight > 0.) {
              candidate.cadNormalizedMeanSquared /= candidate.cadWeight;
            }
          }
          const bool cadSafe = cheapSafe && boundedCad(candidate, reference);
          if(candidate.invalid || !warpingSafe || !sizeSafe || !cadSafe ||
             !qualitySafe || !improved) {
            restore();
            if(!candidate.invalid && warpingSafe && sizeSafe && qualitySafe &&
               (!cheapSafe || boundedLocalCad(candidate, reference))) _hasContextRejections = true;
            rejection = candidate.invalid ? "orientation-rejected" :
              !warpingSafe ? "warping-rejected" : !sizeSafe ? "size-rejected" :
              !qualitySafe || !cheapSafe ? "quality-rejected" :
              !cadSafe ? "cad-rejected" : "quality-rejected";
            traceRejection(step);
            continue;
          }
          if(!_topology.synchronizeGeometry({vertex})) {
            restore();
            _result.success = false;
            return finish("synchronization-failed");
          }
          // All guards passed for these exact XYZ/UV coordinates. Preserve
          // their results under the new revisions instead of recomputing
          // them when an adjacent node next scores its reference star.
          for(std::size_t i = 0; i < elements.size(); ++i) {
            const Id id = _topology.id(elements[i]);
            evaluated[i].state = _topology.state(FaceHalfEdge::Cavity{{id}, {}, {}});
            _elementCache[id] = std::move(evaluated[i]);
          }
          _context.replace(reference, candidate);
          rollback.active = false;
          _smoothingTouched.push_back(job.center);
          for(Id cell : job.cavity.cells)
            activateSmoothing(_topology.cellVertices(cell));
          traceGuard("smoothing", reference, candidate);
          ++_result.acceptedFinalSmoothingCavities;
          ++_nodeSweep.accepted;
          const double movement = std::sqrt(squaredDistance(xyz, oldXyz)) /
            std::max(1.e-30, localTarget(oldXyz, oldUv));
          _nodeSweep.maximumMove = std::max(_nodeSweep.maximumMove, movement);
          _nodeSweep.sumSquaredMove += movement * movement;
          _nodeSweep.cells += elements.size();
          _nodeSweep.minimumStep = std::min(_nodeSweep.minimumStep, step);
          acceptedStep = step;
          if(_options.verbose > 1) {
            Msg::Info("QuadOptimizerV2 face=%d nodal %s moved=1", _face->tag(),
                      _smartSmoothing ? "SmartLaplacian" : "Winslow");
            if(_smartSmoothing)
              Msg::Info("QuadOptimizerV2 face=%d smartAccepted node=%zu minimumSineBefore=%.17g minimumSineAfter=%.17g",
                        _face->tag(), vertex->getNum(), initialSine, minimumSine(elements));
          }
          return finish("accepted");
        }
        if(centroid)
          return _smartSmoothing ? finish(rejection) : false;
        if(std::string(rejection) == "size-rejected") ++_result.rejectedBySize;
        else if(std::string(rejection) == "cad-rejected") ++_result.rejectedByCad;
        else if(std::string(rejection) == "orientation-rejected") ++_result.rejectedByOrientation;
        else ++_result.rejectedByQuality;
        return finish(rejection);
      }

      bool tryProjectedCentroid(NodeSmoothingJob &job, const char *stage,
                                std::size_t sweep, std::size_t color)
      {
        if(std::string(job.status) != "ready") {
          // Smart smoothing has no fallback job that would otherwise emit
          // the visit's terminal status. Record skipped stars as well.
          if(_smartSmoothing && _options.verbose > 1)
            acceptNodeSmoothing(job, stage, sweep, color);
          return false;
        }
        // Standard nodal barycenter: direct edge neighbors, each counted once.
        // Opposite corners of incident quads are not edge neighbors.
        std::set<Id> neighbors;
        for(Id cell : job.cavity.cells) {
          const auto vertices = _topology.cellVertices(cell);
          for(std::size_t i = 0; i < vertices.size(); ++i)
            if(vertices[i] == job.center) {
              neighbors.insert(vertices[(i + 1) % vertices.size()]);
              neighbors.insert(vertices[(i + vertices.size() - 1) % vertices.size()]);
            }
        }
        if(neighbors.empty()) return false;
        // Sum offsets to preserve precision on translated CAD models.
        const Point origin = point(_topology.vertex(job.center));
        Point centroid{{0., 0., 0.}};
        for(Id neighbor : neighbors) {
          const Point delta = subtract(point(_topology.vertex(neighbor)), origin);
          for(int k = 0; k < 3; ++k) centroid[k] += delta[k];
        }
        for(int k = 0; k < 3; ++k) centroid[k] = origin[k] + centroid[k] / neighbors.size();
        ++_nodeSweep.centroidTried;
        job.optimized.success = job.optimized.untangled = true;
        // One full projected trial. A refusal restores the exact original
        // geometry and ledger, then the original job goes to Winslow.
        const bool accepted = acceptNodeSmoothing(job, stage, sweep, color, &centroid);
        if(accepted) ++_nodeSweep.centroidAccepted;
        job.optimized = SmallCavityWinslowResult();
        return accepted;
      }

      bool smoothSweep(const char *stage, std::size_t sweep,
                       bool winslowOnly = false)
      {
        const auto sweepStarted = std::chrono::steady_clock::now();
        const bool terminalPolish = std::string(stage) == "polish";
        _smartSmoothing = _options.smartLaplacian && !winslowOnly;
        _nodeSweep = NodeSweepStats();
        _smoothingTouched.clear();
        const auto &colors = smoothingColors();
        auto &active = _smartSmoothing ? _activeSmart : _activeWinslow;
        std::size_t free = 0;
        for(const auto &color : colors) free += color.size();
        if(_options.verbose)
          Msg::Info("QuadOptimizerV2 face=%d %s stage=%s sweep=%zu "
                    "begin free=%zu colors=%zu active=%zu", _face->tag(), _smartSmoothing ? "nodeSmartLaplacian" : "nodeWinslow",
                    stage, sweep, free, colors.size(), active.size());
        SmallCavityWinslowOptions winslow = _options.winslow;
        winslow.harmonicInitialization = false;
        winslow.maxInnerIterations = std::min(winslow.maxInnerIterations, 20);
        winslow.maxOuterIterations = std::min(winslow.maxOuterIterations, 2);
        winslow.maxLineSearchSteps = std::min(winslow.maxLineSearchSteps, 12);
        winslow.verbose = 0;
        for(std::size_t color = 0; color < colors.size(); ++color) {
          std::vector<NodeSmoothingJob> jobs;
          jobs.reserve(colors[color].size());
          for(Id center : colors[color]) {
            if(!terminalPolish && _options.activeNodalSmoothing && !active.erase(center)) continue;
            NodeSmoothingJob job;
            job.center = center;
            const auto prepareStarted = std::chrono::steady_clock::now();
            prepareNodeSmoothing(job);
            _nodeSweep.prepareSeconds += std::chrono::duration<double>(
              std::chrono::steady_clock::now() - prepareStarted).count();
            ++_nodeSweep.visited;
            const auto centroidStarted = std::chrono::steady_clock::now();
            const bool accepted = !winslowOnly &&
              tryProjectedCentroid(job, stage, sweep, color);
            _nodeSweep.guardSeconds += std::chrono::duration<double>(
              std::chrono::steady_clock::now() - centroidStarted).count();
            if(!accepted && !_smartSmoothing) jobs.push_back(std::move(job));
          }
          // This section uses only owned numeric arrays. It is separated
          // from CAD calls and mesh/ledger updates for parallel execution.
          const auto started = std::chrono::steady_clock::now();
          for(NodeSmoothingJob &job : jobs) {
            if(std::string(job.status) != "ready") continue;
            ++_nodeSweep.solves;
            try {
              job.optimized = optimizeLocalSurfacePatchWinslow(
                job.plane, job.fixed, job.triangles, job.quadrangles,
                job.orientation, winslow);
            }
            catch(const std::invalid_argument &) {}
            job.status = "solver-failed";
            if(!job.optimized.success || !job.optimized.untangled)
              ++_result.rejectedByWinslow;
          }
          _nodeSweep.solveSeconds += std::chrono::duration<double>(
            std::chrono::steady_clock::now() - started).count();
          // Stable serial commits preserve the shared global quality/CAD
          // budget even when same-color numeric proposals run concurrently.
          const auto guardsStarted = std::chrono::steady_clock::now();
          for(NodeSmoothingJob &job : jobs)
            acceptNodeSmoothing(job, stage, sweep, color);
          _nodeSweep.guardSeconds += std::chrono::duration<double>(
            std::chrono::steady_clock::now() - guardsStarted).count();
        }
        // No topological operation runs inside a nodal sweep. Schedule the
        // union once: repeated six-ring traversals per moved node are redundant.
        const auto queueStarted = std::chrono::steady_clock::now();
        if(!terminalPolish && !_smoothingTouched.empty())
          enqueueAffected(_smoothingTouched);
        const double queueSeconds = std::chrono::duration<double>(
          std::chrono::steady_clock::now() - queueStarted).count();
        const double totalSeconds = std::chrono::duration<double>(
          std::chrono::steady_clock::now() - sweepStarted).count();
        if(_options.verbose)
          Msg::Info("QuadOptimizerV2 face=%d %s stage=%s sweep=%zu "
                    "end visited=%zu acceptedNodes=%zu solves=%zu solveSeconds=%.9g guardSeconds=%.9g maxMoveOverH=%.9g rmsMoveOverH=%.9g centroidTried=%zu centroidAccepted=%zu winslowFallbacks=%zu prepareSeconds=%.9g queueSeconds=%.9g totalSeconds=%.9g",
                    _face->tag(), _smartSmoothing ? "nodeSmartLaplacian" : "nodeWinslow",
                    stage, sweep, _nodeSweep.visited, _nodeSweep.accepted,
                    _nodeSweep.solves, _nodeSweep.solveSeconds, _nodeSweep.guardSeconds,
                    _nodeSweep.maximumMove, std::sqrt(_nodeSweep.sumSquaredMove / std::max<std::size_t>(1, _nodeSweep.visited)),
                    _nodeSweep.centroidTried, _nodeSweep.centroidAccepted, _nodeSweep.solves,
                    _nodeSweep.prepareSeconds, queueSeconds, totalSeconds);
        return _nodeSweep.accepted != 0;
      }

      std::size_t searchLimit() const
      {
        return static_cast<std::size_t>(std::max(0,
          std::min(64, _options.v2SearchCandidateLimit)));
      }

      PatchSearch::Cells localPatch(const FaceHalfEdge::Cavity &cavity,
                                     std::vector<Id> &vertices) const
      {
        vertices = cavity.boundary;
        vertices.insert(vertices.end(), cavity.interior.begin(), cavity.interior.end());
        PatchSearch::Cells cells;
        for(const Id cell : cavity.cells) {
          PatchSearch::Cell local;
          for(const Id vertex : _topology.cellVertices(cell)) {
            const auto found = std::find(vertices.begin(), vertices.end(), vertex);
            if(found == vertices.end()) return {};
            local.push_back(static_cast<Id>(found - vertices.begin()));
          }
          cells.push_back(std::move(local));
        }
        return cells;
      }

      Candidate searchCandidate(const std::vector<Id> &vertices,
                                 const PatchSearch::Cells &cells,
                                 const char *name)
      {
        Candidate candidate;
        candidate.name = name;
        std::vector<UV> parameters;
        for(const Id vertexId : vertices) {
          MVertex *vertex = _topology.vertex(vertexId);
          UV uv;
          if(!vertex || !parameter(vertex, uv)) return {};
          candidate.vertices.push_back({vertex, uv, point(vertex)});
          parameters.push_back(uv);
        }
        unwrap(parameters);
        for(std::size_t i = 0; i < parameters.size(); ++i)
          candidate.vertices[i].uv = parameters[i];
        for(const auto &cell : cells) {
          Cell mapped;
          for(const Id vertex : cell) {
            if(vertex < 0 || static_cast<std::size_t>(vertex) >= vertices.size()) return {};
            mapped.push_back(static_cast<std::size_t>(vertex));
          }
          candidate.cells.push_back(std::move(mapped));
        }
        return candidate;
      }

      bool reliableDefect(Id cell)
      {
        MElement *element = _topology.element(cell);
        if(!element) return false;
        const auto quality = evaluateElementQuality(element);
        if(!quality.topologicallyValid ||
           (quality.kind == SurfaceElementKind::Quadrangle &&
            std::isfinite(quality.warpingDegrees) &&
            quality.warpingDegrees >= absoluteMaximumQuadWarpingDegrees)) return true;
        std::vector<UV> uv;
        if(!elementParameters(element, nullptr, uv)) return false;
        bool opposed = false;
        followsFace(element, uv, &opposed);
        return opposed; // An unavailable CAD/UV sample alone is not a seed.
      }

      std::vector<Candidate> invalidPatchCandidates(
        const FaceHalfEdge::Cavity &cavity)
      {
        std::vector<Candidate> result;
        const std::size_t count = cavity.boundary.size();
        // Reconnect existing nodes only. An interior vertex requires a
        // different operator; never silently discard it to triangulate a rim.
        if(!cavity.interior.empty() || count < 4 || count > 10) return result;
        Candidate base;
        if(!baseCandidate(cavity, base)) return result;
        const auto crossUv = [&](std::size_t a, std::size_t b, std::size_t c) {
          return GeometryGuard::localOrientationCross2(base.vertices[a].uv,
            base.vertices[b].uv, base.vertices[c].uv);
        };
        double area = 0., scale2 = 0.;
        for(std::size_t i = 1; i + 1 < count; ++i) area += crossUv(0, i, i + 1);
        for(std::size_t i = 0; i < count; ++i)
          for(std::size_t j = i + 1; j < count; ++j)
            scale2 = std::max(scale2, GeometryGuard::localOrientationDistance2(
              base.vertices[i].uv, base.vertices[j].uv));
        if(!std::isfinite(area) || !std::isfinite(scale2) || !(scale2 > 0.) ||
           std::abs(area) <= 1.e-12 * scale2) return result;
        const double sign = area > 0. ? 1. : -1.;
        using Fillings = std::vector<PatchSearch::Cells>;
        std::vector<std::vector<Fillings> > fillings(count,
          std::vector<Fillings>(count));
        for(std::size_t i = 0; i + 1 < count; ++i)
          fillings[i][i + 1].push_back({});
        constexpr std::size_t limit = 64;
        // Apply the physical guard before the candidate limit: a folded
        // support can invalidate most purely combinatorial triangulations.
        for(std::size_t span = 2; span < count; ++span) {
          for(std::size_t first = 0; first + span < count; ++first) {
            const std::size_t last = first + span;
            Fillings &out = fillings[first][last];
            for(std::size_t middle = first + 1;
                middle < last && out.size() < limit; ++middle) {
              const auto &left = fillings[first][middle];
              const auto &right = fillings[middle][last];
              if(left.empty() || right.empty() ||
                 sign * crossUv(first, middle, last) <= 1.e-12 * scale2) continue;
              MTriangle triangle(base.vertices[first].vertex,
                base.vertices[middle].vertex, base.vertices[last].vertex);
              const std::vector<UV> uv = {base.vertices[first].uv,
                base.vertices[middle].uv, base.vertices[last].uv};
              bool complete = false;
              if(!followsFace(&triangle, uv, nullptr, &complete) || !complete) continue;
              for(const auto &a : left) {
                for(const auto &b : right) {
                  auto filling = a;
                  filling.insert(filling.end(), b.begin(), b.end());
                  filling.push_back({static_cast<Id>(first),
                    static_cast<Id>(middle), static_cast<Id>(last)});
                  out.push_back(std::move(filling));
                  if(out.size() == limit) break;
                }
                if(out.size() == limit) break;
              }
            }
          }
        }
        for(const auto &filling : fillings[0][count - 1]) {
          Candidate candidate = base;
          candidate.name = "invalid patch triangulation";
          for(const auto &cell : filling)
            candidate.cells.emplace_back(cell.begin(), cell.end());
          result.push_back(std::move(candidate));
        }
        return result;
      }

      bool repairInvalidPatch()
      {
        for(const Id seed : _topology.cells()) {
          MElement *element = _topology.element(seed);
          if(!element || !score({element}, nullptr, false).physicalInvalid) continue;
          std::queue<std::vector<Id> > pending;
          std::set<std::vector<Id> > discovered;
          pending.push({seed});
          discovered.insert({seed});
          std::size_t expanded = 0;
          while(!pending.empty() && expanded++ < 256) {
            const auto cells = pending.front();
            pending.pop();
            if(cells.size() >= 2) {
              FaceHalfEdge::Cavity cavity;
              if(_topology.cavity(cells, cavity) && cavity.boundary.size() <= 10 &&
                 !cached(Rule::InvalidPatch, cavity) &&
                 attempt(Rule::InvalidPatch, cavity, invalidPatchCandidates(cavity), false))
                return true;
            }
            if(cells.size() == 4) continue;
            for(const Id cell : cells)
              for(const Id neighbor : _topology.neighbors(cell)) {
                if(std::find(cells.begin(), cells.end(), neighbor) != cells.end()) continue;
                auto extended = cells;
                extended.push_back(neighbor);
                std::sort(extended.begin(), extended.end());
                if(discovered.insert(extended).second) pending.push(std::move(extended));
              }
          }
        }
        return false;
      }

      bool repairPatch()
      {
        while(!_repairCells.empty()) {
          const Id seed = *_repairCells.begin(); _repairCells.erase(_repairCells.begin());
          if(!reliableDefect(seed)) continue;
          std::size_t expanded = 0;
          std::queue<std::vector<Id> > pending;
          std::set<std::vector<Id> > discovered;
          pending.push({seed}); discovered.insert({seed});
          while(!pending.empty() && expanded++ < 64) {
            const auto cells = pending.front(); pending.pop();
            if(cells.size() >= 3) {
              FaceHalfEdge::Cavity cavity;
              if(_topology.cavity(cells, cavity) && cavity.boundary.size() <= 10 &&
                 !cached(Rule::RepairPatch, cavity)) {
                std::vector<Id> vertices;
                const auto before = localPatch(cavity, vertices);
                PatchSearch::Cell boundary;
                for(std::size_t i = 0; i < cavity.boundary.size(); ++i)
                  boundary.push_back(static_cast<Id>(i));
                std::vector<Candidate> candidates;
                for(const auto &filling : PatchSearch::minimalTriangleFillings(boundary, searchLimit())) {
                  if(PatchSearch::changesEveryCell(before, filling))
                    candidates.push_back(searchCandidate(vertices, filling, "targeted patch repair"));
                }
                if(attempt(Rule::RepairPatch, cavity, std::move(candidates), false)) return true;
              }
            }
            if(cells.size() == 4) continue;
            for(const Id cell : cells)
              for(const Id neighbor : _topology.neighbors(cell)) {
                if(std::find(cells.begin(), cells.end(), neighbor) != cells.end()) continue;
                auto extended = cells;
                extended.push_back(neighbor);
                std::sort(extended.begin(), extended.end());
                if(discovered.insert(extended).second) pending.push(std::move(extended));
              }
          }
        }
        return false;
      }

      bool hardValidIntermediate(const FaceHalfEdge::Cavity &support,
                                  const std::vector<Id> &vertices,
                                  const std::vector<Id> &removed,
                                  const PatchSearch::Cells &inserted)
      {
        std::vector<Id> cells;
        for(const Id local : removed) cells.push_back(support.cells[static_cast<std::size_t>(local)]);
        FaceHalfEdge::Cavity pair;
        if(!_topology.cavity(cells, pair)) return false;
        Candidate candidate = searchCandidate(vertices, inserted, "speculative QT");
        BuiltCandidate built;
        _buildingCavity = &pair;
        const bool ready = build(candidate, built) &&
          _topology.prepareReplacement(pair, built.elementPointers, built.replacement);
        _buildingCavity = nullptr;
        if(!ready) return false;
        const Score before = score(cavityElements(pair));
        const Score after = score(built.elementPointers, &built.parameters);
        return !after.invalid && boundedSize(after, before) && boundedLocalCad(after, before);
      }

      bool composedTriangleReduction()
      {
        while(!_composedTriangles.empty()) {
          const Id start = *_composedTriangles.begin(); _composedTriangles.erase(_composedTriangles.begin());
          if(_topology.cornerCount(start) != 3) continue;
          std::size_t expanded = 0;
          std::vector<std::vector<Id> > pending(1, {start});
          while(!pending.empty() && expanded++ < 64) {
            auto path = std::move(pending.back()); pending.pop_back();
            for(const Id next : _topology.neighbors(path.back())) {
              if(std::find(path.begin(), path.end(), next) != path.end()) continue;
              if(_topology.cornerCount(next) == 4 && path.size() < 4) {
                auto longer = path; longer.push_back(next); pending.push_back(std::move(longer));
                continue;
              }
              // Three/four-cell unions are already exhaustively covered by
              // the ordinary TQT/TQQT reductions. Spend this budget only on
              // the five-cell cases absent from the two long-strip zippers.
              if(_topology.cornerCount(next) != 3 || path.size() != 4) continue;
              auto complete = path; complete.push_back(next);
              FaceHalfEdge::Cavity cavity;
              if(!_topology.cavity(complete, cavity) ||
                 cached(Rule::ComposedTriangleReduction, cavity)) continue;
              std::vector<Id> vertices;
              const auto before = localPatch(cavity, vertices);
              const auto search = PatchSearch::composeTriangleReduction(before, searchLimit(),
                [&](const std::vector<Id> &removed, const PatchSearch::Cells &inserted) {
                  return hardValidIntermediate(cavity, vertices, removed, inserted);
                });
              std::vector<Candidate> candidates;
              for(const auto &filling : search.candidates)
                candidates.push_back(searchCandidate(vertices, filling, "composed QT strip reduction"));
              if(attempt(Rule::ComposedTriangleReduction, cavity, std::move(candidates), false)) return true;
            }
          }
        }
        return false;
      }

      bool experimentalSearch()
      {
        if(!searchLimit()) return false;
        if((_options.v2SearchMode & 1) && repairPatch()) return true;
        return (_options.v2SearchMode & 2) && composedTriangleReduction();
      }

      bool mandatoryPass()
      {
        switch(_options.v2Schedule) {
        case 1:
          if(triangleStrip()) return true;
          if(interiorStar()) return true;
          if(boundaryFan()) return true;
          return diamond();
        case 2:
          if(diamond()) return true;
          if(boundaryFan()) return true;
          if(interiorStar()) return true;
          return triangleStrip();
        default:
          if(interiorStar()) return true;
          if(diamond()) return true;
          if(triangleStrip()) return true;
          return boundaryFan();
        }
      }

      void auditSize(const Score &score, bool initial)
      {
        if(initial) {
          _result.initialEdgesBelowMinimum = score.belowMinimum;
          _result.initialEdgesAboveMaximum = score.aboveMaximum;
          _result.initialInvalidSizeEdges = score.invalidSize;
          _result.initialMinimumEdgeLength = score.minimumLength;
          _result.initialMaximumEdgeLength = score.maximumLength;
        }
        else {
          _result.finalEdgesBelowMinimum = score.belowMinimum;
          _result.finalEdgesAboveMaximum = score.aboveMaximum;
          _result.finalInvalidSizeEdges = score.invalidSize;
          _result.finalMinimumEdgeLength = score.minimumLength;
          _result.finalMaximumEdgeLength = score.maximumLength;
          _result.sizeRequirementsMet = score.sizeViolations == 0;
        }
      }

    public:
      Optimizer(GFace *face, const SmallCavityOptimizerOptions &options,
                OptimizationContext &context)
        : _face(face), _context(context), _options(options), _topology(face, true)
      {
        collectCadConstraints();
      }

      bool initialize()
      {
        if(!_face || !_topology.valid()) {
          _result.skippedInvalidInputCellComplex = true;
          return false;
        }
        if(!_started) {
          const auto elements = cavityElements(FaceHalfEdge::Cavity{_topology.cells(), {}, {}});
          _result.initialObjective = specificationObjective(elements);
          auditSize(score(elements, nullptr, false), true);
          const auto vertices = _topology.vertices();
          activateSmoothing(vertices);
          enqueueAffected(vertices); // Seed once; later updates stay local.
          _started = true;
        }
        return true;
      }

      std::size_t nodalSweep(const char *stage, std::size_t sweep, bool winslowOnly)
      {
        if(!_started) return 0;
        const auto before = _result.acceptedFinalSmoothingCavities;
        smoothSweep(stage, sweep, winslowOnly);
        return _result.acceptedFinalSmoothingCavities - before;
      }

      std::size_t topologySweep(int phase)
      {
        const auto limit = static_cast<std::size_t>(std::max(0, _options.maximumAcceptedCavities));
        if(!_started || !_topology.valid() || _accepted >= limit) return 0;
        _terminalMandatory = phase == 0;
        _terminalPairs = phase == 2;
        const auto searchStarted = std::chrono::steady_clock::now();
        const auto before = _accepted;
        while(_accepted < limit && (phase == 0 ? mandatoryPass() :
          phase == 1 ? (swaps(false) || experimentalSearch()) : swaps(true))) {}
        _terminalMandatory = _terminalPairs = false;
        if(_options.verbose)
          Msg::Info("QuadOptimizerV2 face=%d topologyTiming phase=%d accepted=%zu queueSeconds=%.9g searchSeconds=%.9g",
                    _face->tag(), phase, _accepted - before,
                    0.,
                    std::chrono::duration<double>(std::chrono::steady_clock::now() - searchStarted).count());
        return _accepted - before;
      }

      std::size_t finalCadSwapSweep()
      {
        if(!_started || !_topology.valid() || !_options.qualitySwaps ||
           _accepted >= static_cast<std::size_t>(
             std::max(0, _options.maximumAcceptedCavities))) return 0;
        // The terminal driver seeds this queue after splitting and retries
        // all admissible TT merges after each single successful CAD swap.
        while(!_swaps.empty()) {
          const auto edge = *_swaps.begin();
          _swaps.erase(_swaps.begin());
          FaceHalfEdge::Cavity cavity;
          if(!_topology.edgeCavity(edge.first, edge.second, cavity) ||
             cavity.cells.size() != 2 || !cavity.interior.empty()) continue;
          const auto first = _topology.cornerCount(cavity.cells[0]);
          const auto second = _topology.cornerCount(cavity.cells[1]);
          if(first == 3 && second == 3 && cavity.boundary.size() == 4) {
            if(geometryDrivenEdgeSwap(cavity, ttCandidates(cavity), true)) return 1;
          }
          else if(((first == 3 && second == 4) || (first == 4 && second == 3)) &&
                  cavity.boundary.size() == 5) {
            if(geometryDrivenEdgeSwap(cavity, qtCandidates(cavity), true)) return 1;
          }
        }
        return 0;
      }

      bool cavityBudgetExhausted() const
      {
        return _started && _accepted >= static_cast<std::size_t>(
          std::max(0, _options.maximumAcceptedCavities));
      }

      void loopResult(std::size_t rounds, bool fixed, bool iterationLimit)
      {
        _result.passes = rounds;
        _result.exhaustedCavityBudget = cavityBudgetExhausted();
        _result.reachedFixedPoint = fixed && !_result.exhaustedCavityBudget;
        _result.exhaustedIterationBudget = iterationLimit;
      }

      SmallCavityOptimizerResult finalResult()
      {
        const auto elements = cavityElements(FaceHalfEdge::Cavity{_topology.cells(), {}, {}});
        _result.finalObjective = specificationObjective(elements);
        auditSize(score(elements, nullptr, false), false);
        _result.success = _result.success && _topology.valid();
        _result.exhaustedCavityBudget = cavityBudgetExhausted();
        if(_result.exhaustedCavityBudget) _result.reachedFixedPoint = false;
        return _result;
      }

      void repairInvalidCells()
      {
        if(!_started || !_topology.valid()) return;
        const auto before = _result.acceptedCavities;
        // Each transaction removes a reliable physical defect and inserts
        // only fully valid cells, so the number of repairs is finite. Keep
        // this validity pass independent of the quality optimization budget.
        while(repairInvalidPatch()) {}
        if(_result.acceptedCavities != before)
          Msg::Info("QuadOptimizerV2 final invalid repair face=%d cavities=%zu",
                    _face->tag(), _result.acceptedCavities - before);
      }

      void seedFinalCleanup()
      {
        if(_started && _topology.valid()) enqueueAffected(_topology.vertices());
      }

      struct FinalQuadAssessment {
        bool parametrized = false, invalid = false, unacceptable = false;
        bool cadRepair = false;
        int first = 0;
        double distance[2] = {0., 0.};
        std::size_t queryFailures = 0;
        std::vector<UV> uv;
      };

      FinalQuadAssessment assessFinalQuad(MElement *quad,
        const std::unordered_map<MVertex *, UV> *overrides = nullptr)
      {
        FinalQuadAssessment assessment;
        std::vector<UV> uv;
        if(!elementParameters(quad, overrides, uv)) return assessment;
        const auto quality = evaluateElementQuality(quad);
        bool opposed = false;
        followsFace(quad, uv, &opposed);
        const double eta = quad->etaShapeMeasure();
        const double sicn = quad->minSICNShapeMeasure();
        // Use the same absolute admissibility limits for final splitting and
        // TT recombination. Preferred quality only ranks admissible quads;
        // it must neither force their split nor veto their recombination.
        const bool invalid = !quality.topologicallyValid || opposed ||
          !std::isfinite(quality.maximumAngleDegrees) ||
          !std::isfinite(quality.minimumAngleDegrees) ||
          !std::isfinite(eta) || !(eta > 0.) ||
          !std::isfinite(sicn) || !(sicn > 0.);
        double distance[2] = {0., 0.};
        bool covered[2] = {true, true};
        if(_options.finalSplitCadDistanceRatio >= 0.) {
          for(int diagonal = 0; diagonal < 2; ++diagonal) {
            const Point a = point(quad->getVertex(diagonal));
            const Point b = point(quad->getVertex(diagonal + 2));
            // Sample the chord, not the interpolated CAD curve. These
            // three distances are estimates, not a certified supremum.
            for(const double t : {.25, .5, .75}) {
              Point p;
              UV guess;
              for(int d = 0; d < 3; ++d) p[d] = (1. - t) * a[d] + t * b[d];
              for(int d = 0; d < 2; ++d)
                guess[d] = (1. - t) * uv[diagonal][d] + t * uv[diagonal + 2][d];
              bool found = false;
              try {
                const double h = localTarget(p, guess);
                const GPoint projected = _face->closestPointFromTrustedGuess(
                  SPoint3(p[0], p[1], p[2]), guess.data());
                if(h > 0. && projected.succeeded()) {
                  const double d = std::hypot(projected.x() - p[0],
                    projected.y() - p[1], projected.z() - p[2]) / h;
                  if(std::isfinite(d)) {
                    distance[diagonal] = std::max(distance[diagonal], d);
                    found = true;
                  }
                }
              }
              catch(...) {}
              covered[diagonal] = covered[diagonal] && found;
            }
            if(!covered[diagonal]) ++assessment.queryFailures;
          }
        }
        // Ordinary curvature can put both diagonals away from the CAD.
        // Split only if one is excessive and the other is clearly better,
        // within tolerance. The inserted chord must be the closer one.
        const int first = covered[0] && covered[1] &&
          distance[1] < distance[0] ? 1 : 0;
        const bool cadRepair = _options.finalSplitCadDistanceRatio >= 0. &&
          covered[0] && covered[1] &&
          distance[1 - first] > _options.finalSplitCadDistanceRatio &&
          distance[first] <= _options.finalSplitCadDistanceRatio &&
          distance[first] <= .5 * distance[1 - first];
        assessment.parametrized = true;
        assessment.invalid = invalid;
        assessment.unacceptable = !quality.passesAbsoluteSpecifications;
        assessment.cadRepair = cadRepair;
        assessment.first = first;
        assessment.distance[0] = distance[0];
        assessment.distance[1] = distance[1];
        assessment.uv = std::move(uv);
        return assessment;
      }

      std::size_t splitFinalQuads()
      {
        if(!_started || !_topology.valid()) return 0;
        const std::size_t before = _result.acceptedCavities;
        const auto start = std::chrono::steady_clock::now();
        // Snapshot IDs: newly created triangles are handled by the subsequent
        // pair/CAD-edge closure, with no further nodal smoothing.
        for(const Id id : _topology.cells()) {
          if(_topology.cornerCount(id) != 4) continue;
          MElement *quad = _topology.element(id);
          if(quad->getNumVertices() != 4) continue;
          const auto assessment = assessFinalQuad(quad);
          _result.finalQuadDiagonalQueriesFailed += assessment.queryFailures;
          if(!assessment.parametrized) {
            ++_result.finalQuadDiagonalQueriesFailed;
            ++_result.finalQuadsSplitRejected;
            continue;
          }
          const auto &uv = assessment.uv;
          const auto &distance = assessment.distance;
          const int first = assessment.first;
          const bool invalid = assessment.invalid, cadRepair = assessment.cadRepair;
          const bool unacceptable = assessment.unacceptable;
          if(!invalid && !unacceptable && !cadRepair) continue;
          const char *reason = invalid ? "invalid" :
            unacceptable ? "absolute-quality" : "cad-distance";
          FaceHalfEdge::Cavity cavity;
          if(!_topology.cavity({id}, cavity)) {
            ++_result.finalQuadsSplitRejected;
            continue;
          }
          std::unique_ptr<BuiltCandidate> chosen;
          int selected = -1;
          std::tuple<std::size_t, bool, double, double, double> bestSplit;
          for(int trial = 0; trial < 2; ++trial) {
            const int d = trial == 0 ? first : 1 - first;
            // Never fall back to the distant chord for a CAD-only repair.
            // Invalid quads may use either admissible diagonal.
            if(!invalid && !unacceptable && trial != 0) continue;
            Candidate candidate;
            for(int i = 0; i < 4; ++i)
              candidate.vertices.push_back({quad->getVertex(i), uv[i], point(quad->getVertex(i))});
            candidate.cells = d == 0 ? std::vector<Cell>{{0, 1, 2}, {2, 3, 0}} :
                                      std::vector<Cell>{{1, 2, 3}, {3, 0, 1}};
            auto built = std::unique_ptr<BuiltCandidate>(new BuiltCandidate);
            _buildingCavity = &cavity;
            const bool ready = build(candidate, *built);
            _buildingCavity = nullptr;
            if(!ready) continue;
            bool valid = true;
            std::size_t absoluteViolations = 0;
            double minimumAngle = 180.;
            // No shape quota can veto repair of an invalid quad; validity
            // still requires nondegenerate, consistently oriented triangles.
            for(MElement *triangle : built->elementPointers) {
              std::vector<UV> parameters;
              bool orientationComplete = false;
              const auto triangleQuality = evaluateElementQuality(triangle);
              absoluteViolations += specificationObjective(triangleQuality).absoluteViolationCount;
              minimumAngle = std::min(minimumAngle, triangleQuality.minimumAngleDegrees);
              valid = valid && triangleQuality.topologicallyValid &&
                elementParameters(triangle, &built->parameters, parameters) &&
                followsFace(triangle, parameters, nullptr, &orientationComplete) &&
                orientationComplete;
            }
            if(!valid || !_topology.prepareReplacement(
                 cavity, built->elementPointers, built->replacement)) continue;
            // Absolute triangle safety comes first. Among equally safe cuts,
            // compare the physical triangles to the CAD before angle comfort.
            // Chord distance alone misses errors in triangle interiors.
            const auto cad = trianglePairCad(built->elementPointers, &built->parameters);
            // A physically valid quad remains preferable to two triangles
            // that also fail the absolute limits. Quality/CAD-only cuts must
            // therefore produce two admissible triangles with known CAD fit.
            // Physical validity repair keeps priority over shape comfort.
            if(!invalid && (absoluteViolations || !cad.complete())) continue;
            const double maximum = cad.complete() ? cad.maximumNormalizedDistance :
              std::numeric_limits<double>::infinity();
            const double mean = cad.complete() ?
              cad.normalizedSquaredDistanceIntegral / cad.sampledArea : maximum;
            const auto rank = std::make_tuple(absoluteViolations, !cad.complete(),
              maximum < 1.e-10 ? 0. : maximum, mean < 1.e-20 ? 0. : mean, -minimumAngle);
            if(!chosen || rank < bestSplit) {
              chosen = std::move(built);
              selected = d;
              bestSplit = rank;
            }
          }
          if(!chosen) {
            ++_result.finalQuadsSplitRejected;
            if(_options.verbose)
              Msg::Info("QuadOptimizerV2 final split rejected face=%d quad=%zu "
                        "reason=%s distance02/h=%.9g distance13/h=%.9g",
                        _face->tag(), quad->getNum(),
                        reason, distance[0], distance[1]);
            continue;
          }
          const std::size_t tag = quad->getNum();
          const Score removed = score({quad});
          const Score inserted = score(chosen->elementPointers, &chosen->parameters);
          // Commit directly: final splits have separate counters and are
          // independent of the optimization cavity budget. Keep the shared
          // ledger current for the final QT/TT cleanup, without resetting its
          // immutable initial CAD reference.
          if(!_topology.replace(chosen->replacement)) {
            ++_result.finalQuadsSplitRejected;
            continue;
          }
          for(auto &element : chosen->elements) element.release();
          enqueueAffected(_topology.lastTouchedVertices());
          _context.replace(removed, inserted);
          ++_result.acceptedCavities;
          if(invalid) ++_result.finalInvalidQuadsSplit;
          else if(unacceptable) ++_result.finalQualityQuadsSplit;
          else ++_result.finalCadQuadsSplit;
          if(_options.verbose)
            Msg::Info("QuadOptimizerV2 final split face=%d quad=%zu reason=%s "
                      "diagonal=%d distance02/h=%.9g distance13/h=%.9g",
                      _face->tag(), tag, reason,
                      selected, distance[0], distance[1]);
        }
        const double seconds = std::chrono::duration<double>(
          std::chrono::steady_clock::now() - start).count();
        Msg::Info("QuadOptimizerV2 final split face=%d invalid=%zu quality=%zu cad=%zu "
                  "rejected=%zu queryFailures=%zu wall=%.6g s",
                  _face->tag(), _result.finalInvalidQuadsSplit,
                  _result.finalQualityQuadsSplit, _result.finalCadQuadsSplit,
                  _result.finalQuadsSplitRejected,
                  _result.finalQuadDiagonalQueriesFailed, seconds);
        return _result.acceptedCavities - before;
      }

    };

    std::size_t smoothModel(const std::vector<Optimizer *> &engines,
                            const SmallCavityOptimizerOptions &options,
                            const char *stage)
    {
      std::size_t moved = 0;
      for(int pass = 0; pass < options.finalSmoothingPasses; ++pass) {
        std::size_t changed = 0;
        for(Optimizer *engine : engines) changed += engine->nodalSweep(stage, pass + 1, false);
        moved += changed;
        if(!changed) break;
      }
      for(int pass = 0; pass < options.finalWinslowPasses; ++pass) {
        std::size_t changed = 0;
        for(Optimizer *engine : engines) changed += engine->nodalSweep(stage, pass + 1, true);
        moved += changed;
        if(!changed) break;
      }
      return moved;
    }

    void improveModel(const std::vector<Optimizer *> &engines,
                      const SmallCavityOptimizerOptions &options)
    {
      for(Optimizer *engine : engines) engine->initialize();
      Msg::Info("QuadOptimizerV2 initial smoothing begin");
      const auto initial = smoothModel(engines, options, "initial");
      Msg::Info("QuadOptimizerV2 initial smoothing end moved=%zu", initial);
      std::size_t round = 0;
      bool fixed = false;
      while(options.maximumOptimizationPasses < 0 ||
            round < static_cast<std::size_t>(options.maximumOptimizationPasses)) {
        ++round;
        std::size_t counts[3] = {0, 0, 0};
        for(int phase = 0; phase < 3; ++phase) {
          if(phase == 0 && !options.terminalMandatoryCleanup) continue;
          if(phase == 1 && !options.qualitySwaps) continue;
          if(phase == 2 && !options.finalPairCleanup) continue;
          Msg::Info("QuadOptimizerV2 loop round=%zu phase=%s begin", round,
                    phase == 0 ? "valence" : phase == 1 ? "swap" : "merge");
          const auto phaseStarted = std::chrono::steady_clock::now();
          std::size_t changed;
          do {
            changed = 0;
            for(Optimizer *engine : engines) changed += engine->topologySweep(phase);
            counts[phase] += changed;
          } while(changed);
          Msg::Info("QuadOptimizerV2 loop round=%zu phase=%s end accepted=%zu wall=%.9g",
                    round, phase == 0 ? "valence" : phase == 1 ? "swap" : "merge",
                    counts[phase], std::chrono::duration<double>(
                      std::chrono::steady_clock::now() - phaseStarted).count());
        }
        const bool topologyIdle = !counts[0] && !counts[1] && !counts[2];
        // An idle topology round terminates the alternating loop. Do not
        // restart it because the bounded terminal Winslow pass moves nodes.
        const auto moved = topologyIdle ? 0 : smoothModel(engines, options, "round");
        Msg::Info("QuadOptimizerV2 loop round=%zu end valence=%zu swaps=%zu merges=%zu moved=%zu",
                  round, counts[0], counts[1], counts[2], moved);
        if(topologyIdle) { fixed = true; break; }
      }
      const bool cavityLimit = std::any_of(engines.begin(), engines.end(),
        [](Optimizer *engine) { return engine->cavityBudgetExhausted(); });
      for(Optimizer *engine : engines)
        engine->loopResult(round, fixed, !fixed && !cavityLimit);
      Msg::Info("QuadOptimizerV2 loop end rounds=%zu reason=%s", round,
                cavityLimit ? "cavity-budget" : fixed ? "topology-idle" : "iteration-budget");
      Msg::Info("QuadOptimizerV2 terminal Winslow begin passes=%d", options.terminalWinslowPasses);
      std::size_t polished = 0;
      for(int pass = 0; pass < options.terminalWinslowPasses; ++pass) {
        std::size_t moved = 0;
        for(Optimizer *engine : engines)
          moved += engine->nodalSweep("polish", pass + 1, true);
        polished += moved;
        Msg::Info("QuadOptimizerV2 terminal Winslow sweep=%d moved=%zu", pass + 1, moved);
      }
      Msg::Info("QuadOptimizerV2 terminal Winslow end passes=%d moved=%zu",
                options.terminalWinslowPasses, polished);
      // A boundary ear can be inverted despite positive chart Jacobians and
      // good angles. Repair its small connected patch after all smoothing;
      // two-cell flips alone cannot recover a reflex physical corner.
      for(Optimizer *engine : engines) engine->repairInvalidCells();
      // Split first, then close admissible pairs and repair distant chords.
      // Recombination uses the same assessment as this split, so it cannot
      // recreate a prohibited quad. No smoothing follows this final closure.
      Msg::Info("QuadOptimizerV2 final split begin");
      for(Optimizer *engine : engines) engine->splitFinalQuads();
      Msg::Info("QuadOptimizerV2 final split end");
      for(Optimizer *engine : engines) engine->seedFinalCleanup();
      std::size_t finalMerges = 0, finalCadSwaps = 0;
      while(true) {
        std::size_t merged = 0, swapped = 0;
        if(options.finalPairCleanup)
          for(Optimizer *engine : engines) merged += engine->topologySweep(2);
        // One CAD swap per face, then give newly adjacent triangles first
        // refusal as a quad before considering another diagonal exchange.
        if(options.qualitySwaps)
          for(Optimizer *engine : engines) swapped += engine->finalCadSwapSweep();
        finalMerges += merged;
        finalCadSwaps += swapped;
        if(!merged && !swapped) break;
      }
      Msg::Info("QuadOptimizerV2 final closure merges=%zu CADswaps=%zu",
                finalMerges, finalCadSwaps);
      if(std::any_of(engines.begin(), engines.end(),
          [](Optimizer *engine) { return engine->cavityBudgetExhausted(); }))
        Msg::Warning("QuadOptimizerV2 final closure reached a cavity budget; "
                     "remaining candidates were not exhausted");
    }

    void accumulate(AllFacesOptimizerResult &all,
                    const SmallCavityOptimizerResult &face)
    {
      all.success = all.success && face.success;
      all.acceptedCavities += face.acceptedCavities;
      all.initialValenceTwoQuadsSplit += face.initialValenceTwoQuadsSplit;
      all.acceptedTerminalMandatoryCavities += face.acceptedTerminalMandatoryCavities;
      all.finalInvalidQuadsSplit += face.finalInvalidQuadsSplit;
      all.finalQualityQuadsSplit += face.finalQualityQuadsSplit;
      all.finalQtSwaps += face.finalQtSwaps;
      all.finalTtMerges += face.finalTtMerges;
      all.finalTtCadSwaps += face.finalTtCadSwaps;
      all.finalCadQuadsSplit += face.finalCadQuadsSplit;
      all.finalQuadsSplitRejected += face.finalQuadsSplitRejected;
      all.finalQuadDiagonalQueriesFailed += face.finalQuadDiagonalQueriesFailed;
      all.acceptedEdgeSwaps += face.acceptedEdgeSwaps;
      all.acceptedDiamonds += face.acceptedDiamonds;
      all.acceptedQuadTwoTriangleReductions +=
        face.acceptedQuadTwoTriangleReductions;
      all.acceptedInteriorTriangleTriangleQuadReductions +=
        face.acceptedInteriorTriangleTriangleQuadReductions;
      all.acceptedInteriorFourTriangleFanReductions +=
        face.acceptedInteriorFourTriangleFanReductions;
      all.acceptedInteriorAlternatingQuadTriangleReductions +=
        face.acceptedInteriorAlternatingQuadTriangleReductions;
      all.acceptedInteriorQQTQQTReductions +=
        face.acceptedInteriorQQTQQTReductions;
      all.acceptedValenceSixSplits += face.acceptedValenceSixSplits;
      all.acceptedBoundaryTriangleQuadTriangleFans +=
        face.acceptedBoundaryTriangleQuadTriangleFans;
      all.triangleTriangleSwapsVisited += face.triangleTriangleSwapsVisited;
      all.acceptedTriangleTriangleSwaps +=
        face.acceptedTriangleTriangleSwaps;
      all.acceptedGeometryDrivenTriangleTriangleSwaps +=
        face.acceptedGeometryDrivenTriangleTriangleSwaps;
      all.acceptedGeometryDrivenMixedTriangleQuadSwaps +=
        face.acceptedGeometryDrivenMixedTriangleQuadSwaps;
      all.terminalTrianglePairsVisited += face.terminalTrianglePairsVisited;
      all.terminalTrianglePairsAccepted += face.terminalTrianglePairsAccepted;
      all.acceptedSmoothingCavities +=
        face.acceptedFinalSmoothingCavities;
      all.reorientedElements += face.reorientedElements;
      all.excessiveWarpingQuadrangles += face.excessiveWarpingQuadrangles;
      all.nonConvexOrInvalidQuadrangles += face.nonConvexOrInvalidQuadrangles;
      all.warpedQuadranglesSplit += face.warpedQuadranglesSplit;
      all.warpedQuadranglesRejected += face.warpedQuadranglesRejected;
      all.catastrophicAngleQuadranglesSelectedForSplit += face.catastrophicAngleQuadranglesSelectedForSplit;
      all.catastrophicAngleQuadranglesSplit += face.catastrophicAngleQuadranglesSplit;
      all.catastrophicAngleQuadranglesRejectedOther += face.catastrophicAngleQuadranglesRejectedOther;
      all.sizeRequirementsMet = all.sizeRequirementsMet && face.sizeRequirementsMet;
      all.finalEdgesBelowMinimum += face.finalEdgesBelowMinimum;
      all.finalEdgesAboveMaximum += face.finalEdgesAboveMaximum;
      all.finalInvalidSizeEdges += face.finalInvalidSizeEdges;
      all.rejectedByWinslow += face.rejectedByWinslow;
      all.rejectedBySize += face.rejectedBySize;
      all.rejectedByQuality += face.rejectedByQuality;
      all.initialObjective += face.initialObjective;
      all.finalObjective += face.finalObjective;
    }
  } // namespace

  SmallCavityOptimizerResult optimizeSmallQuadCavitiesV2(
    GFace *face, const SmallCavityOptimizerOptions &options)
  {
    const OrientationRepair orientation = prepareFaceComponents(face);
    if(!orientation.regular) {
      SmallCavityOptimizerResult result;
      result.skippedInvalidInputCellComplex = true;
      Msg::Warning("QuadOptimizer: face %d is not a regular oriented "
                   "surface cell complex", face ? face->tag() : -1);
      return result;
    }
    OptimizationContext context;
    if(face) context.initialize({face}, options);
    Optimizer engine(face, options, context);
    improveModel({&engine}, options);
    SmallCavityOptimizerResult result = engine.finalResult();
    result.reorientedElements += orientation.reversed;
    result.initialValenceTwoQuadsSplit += orientation.valenceTwoQuadsSplit;
    return result;
  }

  SmallCavityOptimizerResult optimizeSmallQuadCavitiesV2(
    int faceTag, const SmallCavityOptimizerOptions &options)
  {
    GModel *model = GModel::current();
    GFace *face = model ? model->getFaceByTag(faceTag) : nullptr;
    return optimizeSmallQuadCavitiesV2(face, options);
  }

  AllFacesOptimizerResult optimizeSmallQuadCavitiesAllFacesV2(
    const SmallCavityOptimizerOptions &options)
  {
    AllFacesOptimizerResult result;
    GModel *model = GModel::current();
    if(!model) {
      result.success = false;
      return result;
    }
    SmallCavityOptimizerOptions localOptions = options;
    localOptions.invalidateVertexArrays = false;
    std::vector<GFace *> faces;
    for(GFace *face : model->getFaces()) if(face) faces.push_back(face);
    std::map<GFace *, OrientationRepair> orientations;
    for(GFace *face : faces) orientations.emplace(face, prepareFaceComponents(face));
    OptimizationContext context;
    context.initialize(faces, localOptions);
    std::map<GFace *, std::unique_ptr<Optimizer> > engines;
    for(GFace *face : faces) {
      ++result.facesVisited;
      if(face->triangles.empty() && face->quadrangles.empty()) continue;
      if(!face->quadrangles.empty()) ++result.facesWithQuadrangles;
      if(orientations.at(face).regular) {
        engines.emplace(face, std::unique_ptr<Optimizer>(
          new Optimizer(face, localOptions, context)));
      }
    }
    std::vector<Optimizer *> finalEngines;
    for(GFace *face : faces) {
      const auto engine = engines.find(face);
      if(engine != engines.end()) finalEngines.push_back(engine->second.get());
    }
    improveModel(finalEngines, localOptions);
    for(GFace *face : faces) {
      if(face->triangles.empty() && face->quadrangles.empty()) continue;
      FaceOptimizerResult faceResult;
      faceResult.faceTag = face->tag();
      const auto engine = engines.find(face);
      if(engine != engines.end()) {
        faceResult.optimizer = engine->second->finalResult();
        faceResult.optimizer.reorientedElements += orientations.at(face).reversed;
        faceResult.optimizer.initialValenceTwoQuadsSplit += orientations.at(face).valenceTwoQuadsSplit;
      }
      else {
        faceResult.optimizer.skippedInvalidInputCellComplex = true;
        Msg::Warning("QuadOptimizer: face %d is not a regular oriented surface cell complex", face->tag());
      }
      if(faceResult.optimizer.skippedInvalidInputCellComplex)
        ++result.facesSkippedInvalidInputCellComplex;
      accumulate(result, faceResult.optimizer);
      result.faces.push_back(std::move(faceResult));
    }
    if(options.invalidateVertexArrays) model->deleteVertexArrays();
    return result;
  }

} // namespace QuadOptimizer
