// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.

#include "quadMeshUtils.h"
#include "quadGeometryGuard.h"
#include "quadCadDistance.h"

#include "BackgroundMeshTools.h"
#include "Field.h"
#include "GEdge.h"
#include "GFace.h"
#include "GPoint.h"
#include "GModel.h"
#include "GVertex.h"
#include "GmshMessage.h"
#include "halfEdge.h"
#include "MElement.h"
#include "MLine.h"
#include "MQuadrangle.h"
#include "MTriangle.h"
#include "MVertex.h"
#include "qmtMeshUtils.h"
#include "discreteFace.h"

#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <exception>
#include <limits>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

namespace QuadOptimizer {
  namespace {

    using UV = std::array<double, 2>;
    using Point = std::array<double, 3>;
    using Pattern = std::vector<std::array<std::size_t, 4> >;
    using Edge = std::pair<MVertex *, MVertex *>;
    Edge canonicalEdge(MVertex *a, MVertex *b)
    {
      if(std::less<MVertex *>()(b, a)) std::swap(a, b);
      return {a, b};
    }

    struct PersistentFaceParameterCacheEntry {
      GFace *face = nullptr;
      std::size_t vertexNumber = 0;
      double x = 0.;
      double y = 0.;
      double z = 0.;
      SPoint2 parameter;
    };

    // A face is optimized by a single worker. Parameter recovery can however
    // be requested thousands of times for the same immutable mesh vertex
    // while screening overlapping cavities. Cache only exact XYZ matches:
    // moving a vertex invalidates its entry without an explicit notification.
    thread_local std::unordered_map<MVertex *,
                                    PersistentFaceParameterCacheEntry>
      persistentFaceParameterCache;

    struct FaceNormalSampleCacheKey {
      GFace *face = nullptr;
      std::uint64_t u = 0;
      std::uint64_t v = 0;

      bool operator==(const FaceNormalSampleCacheKey &other) const
      {
        return face == other.face && u == other.u && v == other.v;
      }
    };

    struct FaceNormalSampleCacheKeyHash {
      std::size_t operator()(const FaceNormalSampleCacheKey &key) const
      {
        std::size_t value = std::hash<GFace *>()(key.face);
        value ^= std::hash<std::uint64_t>()(key.u) +
          0x9e3779b97f4a7c15ULL + (value << 6) + (value >> 2);
        value ^= std::hash<std::uint64_t>()(key.v) +
          0x9e3779b97f4a7c15ULL + (value << 6) + (value >> 2);
        return value;
      }
    };

    struct FaceNormalSampleCacheEntry {
      bool available = false;
      SVector3 normal;
      double normalNorm = 0.;
    };

    // Orientation guards revisit identical interpolation samples during ring
    // construction. The supporting GFace geometry is immutable
    // during one face transaction, so cache its exact (face, bitwise UV)
    // query without quantizing parameters or changing abstention semantics.
    // Each worker owns its cache and clears it before optimizing a new face.
    thread_local std::unordered_map<FaceNormalSampleCacheKey,
                                    FaceNormalSampleCacheEntry,
                                    FaceNormalSampleCacheKeyHash>
      faceNormalSampleCache;

    std::uint64_t exactDoubleBits(double value)
    {
      std::uint64_t bits = 0;
      static_assert(sizeof(bits) == sizeof(value),
                    "unexpected floating-point representation");
      std::memcpy(&bits, &value, sizeof(bits));
      return bits;
    }

    void clearFaceGeometryCaches()
    {
      persistentFaceParameterCache.clear();
      faceNormalSampleCache.clear();
    }

    bool persistentFaceParameter(GFace *face, MVertex *vertex,
                                 SPoint2 &parameter)
    {
      if(!face || !vertex) return false;
      // UV values cached on a discrete-face MVertex are optional MSH data.
      // Always invert the persistent XYZ coordinates so every cleanup branch
      // sees exactly the same parameter after save/reload.
      if(face->geomType() == GEntity::DiscreteSurface) {
        const auto cached = persistentFaceParameterCache.find(vertex);
        if(cached != persistentFaceParameterCache.end() &&
           cached->second.face == face &&
           cached->second.vertexNumber == vertex->getNum() &&
           cached->second.x == vertex->x() &&
           cached->second.y == vertex->y() && cached->second.z == vertex->z()) {
          parameter = cached->second.parameter;
          return true;
        }
        parameter = face->parFromPoint(vertex->point(), true, true);
        if(std::isfinite(parameter.x()) && std::isfinite(parameter.y()))
          persistentFaceParameterCache[vertex] = {
            face, vertex->getNum(), vertex->x(), vertex->y(), vertex->z(),
            parameter};
      }
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
      GFace *face, MElement *element,
      std::unordered_map<MVertex *, SPoint2> &discreteParameterCache)
    {
      if(!face || !element) return {};
      const std::size_t count = element->getNumPrimaryVertices();
      if(count != 3 && count != 4) return {};
      std::vector<SPoint2> parameters(count);
      if(face->geomType() == GEntity::DiscreteSurface) {
        for(std::size_t i = 0; i < count; ++i) {
          MVertex *vertex = element->getVertex(static_cast<int>(i));
          const auto cached = discreteParameterCache.find(vertex);
          if(cached != discreteParameterCache.end()) {
            parameters[i] = cached->second;
            continue;
          }
          if(!persistentFaceParameter(face, vertex, parameters[i]))
            return {};
          discreteParameterCache.emplace(vertex, parameters[i]);
        }
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

    // A topologically oriented patch can still turn through the CAD surface
    // on a strongly curved face: all of its half-edges then remain coherent,
    // while the physical normal of an individual linear element points to the
    // wrong side of the GFace. Keep this signed geometric invariant separate
    // from the intrinsic shape tests, which deliberately have no CAD context.
    //
    // Return +1 for a normal following the CAD, -1 for an opposed normal and
    // 0 when either normal cannot be evaluated robustly.
    template <class IndexedElement>
    int indexedElementCadNormalSign(
      GFace *face, const IndexedElement &element,
      const std::vector<UV> &uv, const std::vector<Point> &xyz)
    {
      if(!face || (element.size() != 3 && element.size() != 4)) return 0;
      const auto polygonSign = [&](const auto &polygon) {
        UV parameter = {0., 0.};
        Point normal = {0., 0., 0.};
        for(std::size_t i = 0; i < polygon.size(); ++i) {
          const std::size_t current = polygon[i];
          const std::size_t next = polygon[(i + 1) % polygon.size()];
          if(current >= uv.size() || current >= xyz.size() ||
             next >= xyz.size())
            return 0;
          for(int direction = 0; direction < 2; ++direction) {
            if(!std::isfinite(uv[current][direction])) return 0;
            parameter[direction] += uv[current][direction];
          }
          const Point &a = xyz[current];
          const Point &b = xyz[next];
          for(int component = 0; component < 3; ++component)
            if(!std::isfinite(a[component]) ||
               !std::isfinite(b[component]))
              return 0;
          // Newell's polygon normal. For triangles this is parallel to the
          // usual cross product; for a warped quad it is its center normal.
          normal[0] += (a[1] - b[1]) * (a[2] + b[2]);
          normal[1] += (a[2] - b[2]) * (a[0] + b[0]);
          normal[2] += (a[0] - b[0]) * (a[1] + b[1]);
        }
        const double reciprocalCount =
          1. / static_cast<double>(polygon.size());
        parameter[0] *= reciprocalCount;
        parameter[1] *= reciprocalCount;
        const double elementNorm = std::sqrt(
          normal[0] * normal[0] + normal[1] * normal[1] +
          normal[2] * normal[2]);
        if(!std::isfinite(elementNorm) || !(elementNorm > 0.)) return 0;

        const SVector3 cadNormal = face->normal(
          SPoint2(parameter[0], parameter[1]));
        const double cadNorm = cadNormal.norm();
        if(!std::isfinite(cadNorm) || !(cadNorm > 0.)) return 0;
        const double scalarProduct = normal[0] * cadNormal.x() +
          normal[1] * cadNormal.y() + normal[2] * cadNormal.z();
        const double tolerance = 1.e-12 * elementNorm * cadNorm;
        if(!std::isfinite(scalarProduct) ||
           std::abs(scalarProduct) <= tolerance)
          return 0;
        return scalarProduct > 0. ? 1 : -1;
      };

      return polygonSign(element);
    }

    template <class TriangleRange, class QuadrangleRange>
    bool indexedPatchFollowsCadNormal(
      GFace *face, const std::vector<UV> &uv,
      const std::vector<Point> &xyz, const TriangleRange &triangles,
      const QuadrangleRange &quadrangles)
    {
      for(const auto &triangle : triangles)
        if(indexedElementCadNormalSign(face, triangle, uv, xyz) != 1)
          return false;
      for(const auto &quadrangle : quadrangles)
        if(indexedElementCadNormalSign(face, quadrangle, uv, xyz) != 1)
          return false;
      return true;
    }

    struct LocalOrientationTriangle {
      std::array<UV, 3> uv;
      std::array<Point, 3> xyz;
      Point normal = {0., 0., 0.};
      UV minimumUv = {0., 0.};
      UV maximumUv = {0., 0.};
      double twiceUvArea = 0.;
      double containmentPadding = 0.;
      double normalNorm = 0.;
      bool reliable = true;
    };

    struct LocalBoundarySegment {
      UV firstUv = {0., 0.};
      UV secondUv = {0., 0.};
      Point firstXyz = {0., 0., 0.};
      Point secondXyz = {0., 0., 0.};
      Point normal = {0., 0., 0.};
      double normalNorm = 0.;
      bool reliable = false;
    };

    // Immutable, mesh-only orientation field of the cavity before a local
    // transaction. It deliberately remains independent of GFace::normal():
    // the separate multipoint physical guard checks the candidate against the
    // GFace, while this reference preserves the unchanged cavity winding and
    // directed boundary even when no geometric normal can be evaluated.
    struct LocalPatchOrientationReference {
      bool valid = false;
      bool strict = true;
      double uvScale2 = 0.;
      double xyzScale2 = 0.;
      std::vector<LocalOrientationTriangle> triangles;
      std::vector<LocalBoundarySegment> boundary;
    };

    double localOrientationCross2(const UV &a, const UV &b, const UV &c)
    {
      return (b[0] - a[0]) * (c[1] - a[1]) -
             (b[1] - a[1]) * (c[0] - a[0]);
    }

    Point localOrientationNormal(const Point &a, const Point &b,
                                 const Point &c)
    {
      const Point ab = {b[0] - a[0], b[1] - a[1], b[2] - a[2]};
      const Point ac = {c[0] - a[0], c[1] - a[1], c[2] - a[2]};
      return {ab[1] * ac[2] - ab[2] * ac[1],
              ab[2] * ac[0] - ab[0] * ac[2],
              ab[0] * ac[1] - ab[1] * ac[0]};
    }

    double localOrientationNorm(const Point &value)
    {
      return std::sqrt(value[0] * value[0] + value[1] * value[1] +
                       value[2] * value[2]);
    }

    double localOrientationDistance2(const UV &a, const UV &b)
    {
      return std::pow(b[0] - a[0], 2) +
             std::pow(b[1] - a[1], 2);
    }

    double localOrientationDistance2(const Point &a, const Point &b)
    {
      return std::pow(b[0] - a[0], 2) +
             std::pow(b[1] - a[1], 2) +
             std::pow(b[2] - a[2], 2);
    }

    template <class TriangleRange, class QuadrangleRange>
    bool buildLocalPatchOrientationReference(
      const std::vector<UV> &uv, const std::vector<Point> &xyz,
      const TriangleRange &triangles, const QuadrangleRange &quadrangles,
      LocalPatchOrientationReference &reference)
    {
      reference = LocalPatchOrientationReference();
      if(uv.size() != xyz.size()) return false;

      std::map<std::pair<std::size_t, std::size_t>,
               std::pair<std::size_t, int> > edgeUse;
      auto appendEdges = [&](const auto &element) {
        if(element.size() != 3 && element.size() != 4) return false;
        for(std::size_t i = 0; i < element.size(); ++i) {
          const std::size_t a = element[i];
          const std::size_t b = element[(i + 1) % element.size()];
          if(a >= uv.size() || b >= uv.size() || a == b) return false;
          const auto key = std::minmax(a, b);
          auto &use = edgeUse[{key.first, key.second}];
          ++use.first;
          use.second += a < b ? 1 : -1;
          if(use.first > 2) return false;
          reference.uvScale2 = std::max(
            reference.uvScale2, localOrientationDistance2(uv[a], uv[b]));
          reference.xyzScale2 = std::max(
            reference.xyzScale2,
            localOrientationDistance2(xyz[a], xyz[b]));
        }
        return true;
      };
      for(const auto &triangle : triangles)
        if(!appendEdges(triangle)) return false;
      for(const auto &quadrangle : quadrangles)
        if(!appendEdges(quadrangle)) return false;
      if(edgeUse.empty() || !(reference.uvScale2 > 0.) ||
         !(reference.xyzScale2 > 0.))
        return false;

      // The before state must already be a coherently oriented half-edge
      // complex. A local reference made from inconsistent cells would merely
      // replace one ambiguous normal source by another.
      for(const auto &entry : edgeUse) {
        if(entry.second.first == 2 && entry.second.second != 0) return false;
        if(entry.second.first == 1) {
          const bool forward = entry.second.second > 0;
          const std::size_t first = forward ? entry.first.first :
                                              entry.first.second;
          const std::size_t second = forward ? entry.first.second :
                                               entry.first.first;
          reference.boundary.push_back(
            {uv[first], uv[second], xyz[first], xyz[second]});
        }
      }

      auto appendTriangle = [&](const UV &aUv, const UV &bUv,
                                const UV &cUv, const Point &aXyz,
                                const Point &bXyz, const Point &cXyz,
                                std::size_t *index = nullptr) {
        LocalOrientationTriangle triangle;
        triangle.uv = {aUv, bUv, cUv};
        triangle.xyz = {aXyz, bXyz, cXyz};
        for(std::size_t coordinate = 0; coordinate < 2; ++coordinate) {
          triangle.minimumUv[coordinate] = std::min(
            {aUv[coordinate], bUv[coordinate], cUv[coordinate]});
          triangle.maximumUv[coordinate] = std::max(
            {aUv[coordinate], bUv[coordinate], cUv[coordinate]});
        }
        triangle.twiceUvArea = localOrientationCross2(aUv, bUv, cUv);
        const double uvScale = std::sqrt(std::max(
          reference.uvScale2, std::numeric_limits<double>::min()));
        triangle.containmentPadding = std::min(
          uvScale,
          4.e-10 * reference.uvScale2 * uvScale /
            std::max(std::abs(triangle.twiceUvArea),
                     std::numeric_limits<double>::min()));
        triangle.normal = localOrientationNormal(aXyz, bXyz, cXyz);
        triangle.normalNorm = localOrientationNorm(triangle.normal);
        const double uvTolerance = 1.e-12 * std::max(
          reference.uvScale2, std::numeric_limits<double>::min());
        const double xyzTolerance = 1.e-12 * std::max(
          reference.xyzScale2, std::numeric_limits<double>::min());
        if(!std::isfinite(triangle.twiceUvArea) ||
           !std::isfinite(triangle.normalNorm) ||
           std::abs(triangle.twiceUvArea) <= uvTolerance ||
           triangle.normalNorm <= xyzTolerance) {
          reference.strict = false;
          return false;
        }
        if(index) *index = reference.triangles.size();
        reference.triangles.push_back(triangle);
        return true;
      };

      for(const auto &triangle : triangles) {
        appendTriangle(uv[triangle[0]], uv[triangle[1]], uv[triangle[2]],
                       xyz[triangle[0]], xyz[triangle[1]], xyz[triangle[2]]);
      }
      for(const auto &quadrangle : quadrangles) {
        UV centerUv = {0., 0.};
        Point centerXyz = {0., 0., 0.};
        for(const std::size_t vertex : quadrangle) {
          if(vertex >= uv.size()) return false;
          for(std::size_t coordinate = 0; coordinate < 2; ++coordinate)
            centerUv[coordinate] += .25 * uv[vertex][coordinate];
          for(std::size_t coordinate = 0; coordinate < 3; ++coordinate)
            centerXyz[coordinate] += .25 * xyz[vertex][coordinate];
        }
        // A four-triangle fan exposes every lobe of a warped quadrangle; a
        // single Newell normal can hide two mutually opposed lobes.
        const std::size_t missing = std::numeric_limits<std::size_t>::max();
        std::array<std::size_t, 4> lobe = {missing, missing, missing, missing};
        bool reliableQuadrangle = true;
        for(std::size_t i = 0; i < 4; ++i) {
          const std::size_t a = quadrangle[i];
          const std::size_t b = quadrangle[(i + 1) % 4];
          if(!appendTriangle(uv[a], uv[b], centerUv,
                             xyz[a], xyz[b], centerXyz, &lobe[i]))
            reliableQuadrangle = false;
        }
        // A center fan alone is insufficient for a bilinear quadrangle:
        // explicitly validate all four corner Jacobians against both lobes
        // incident on the corner.
        for(std::size_t i = 0; i < 4; ++i) {
          const std::size_t current = quadrangle[i];
          const std::size_t next = quadrangle[(i + 1) % 4];
          const std::size_t previous = quadrangle[(i + 3) % 4];
          const double cornerUv = localOrientationCross2(
            uv[current], uv[next], uv[previous]);
          const Point cornerNormal = localOrientationNormal(
            xyz[current], xyz[next], xyz[previous]);
          const double cornerNorm = localOrientationNorm(cornerNormal);
          const double uvTolerance = 1.e-12 * std::max(
            reference.uvScale2, std::numeric_limits<double>::min());
          const double xyzTolerance = 1.e-12 * std::max(
            reference.xyzScale2, std::numeric_limits<double>::min());
          if(!std::isfinite(cornerUv) || !std::isfinite(cornerNorm) ||
             std::abs(cornerUv) <= uvTolerance ||
             cornerNorm <= xyzTolerance || lobe[i] == missing ||
             lobe[(i + 3) % 4] == missing) {
            reliableQuadrangle = false;
            continue;
          }
          for(const std::size_t adjacent :
              {lobe[i], lobe[(i + 3) % 4]}) {
            const LocalOrientationTriangle &triangle =
              reference.triangles[adjacent];
            const double dot = cornerNormal[0] * triangle.normal[0] +
              cornerNormal[1] * triangle.normal[1] +
              cornerNormal[2] * triangle.normal[2];
            if(!std::isfinite(dot) ||
               dot <= 1.e-10 * cornerNorm * triangle.normalNorm)
              reliableQuadrangle = false;
          }
        }
        if(!reliableQuadrangle) {
          reference.strict = false;
          for(const std::size_t index : lobe)
            if(index != missing) reference.triangles[index].reliable = false;
        }
      }

      const double uvMatchTolerance2 = 1.e-20 * std::max(
        reference.uvScale2, std::numeric_limits<double>::min());
      const double xyzMatchTolerance2 = 1.e-20 * std::max(
        reference.xyzScale2, std::numeric_limits<double>::min());
      auto samePoint = [&](const UV &aUv, const Point &aXyz,
                           const UV &bUv, const Point &bXyz) {
        return localOrientationDistance2(aUv, bUv) <= uvMatchTolerance2 &&
               localOrientationDistance2(aXyz, bXyz) <=
                 xyzMatchTolerance2;
      };

      // A positive Jacobian on each subcell is not sufficient if two
      // neighboring subcells fold through one another. Mark both sides of
      // such an interface unreliable. This identifies a bad before state
      // without preventing a self-consistent candidate from repairing it.
      for(std::size_t i = 0; i < reference.triangles.size(); ++i)
        for(std::size_t j = i + 1; j < reference.triangles.size(); ++j) {
          std::size_t common = 0;
          for(std::size_t a = 0; a < 3; ++a)
            for(std::size_t b = 0; b < 3; ++b)
              if(samePoint(reference.triangles[i].uv[a],
                           reference.triangles[i].xyz[a],
                           reference.triangles[j].uv[b],
                           reference.triangles[j].xyz[b])) {
                ++common;
                break;
              }
          if(common < 2) continue;
          const double dot =
            reference.triangles[i].normal[0] *
              reference.triangles[j].normal[0] +
            reference.triangles[i].normal[1] *
              reference.triangles[j].normal[1] +
            reference.triangles[i].normal[2] *
              reference.triangles[j].normal[2];
          if(!std::isfinite(dot) ||
             dot <= 1.e-10 * reference.triangles[i].normalNorm *
               reference.triangles[j].normalNorm) {
            reference.triangles[i].reliable = false;
            reference.triangles[j].reliable = false;
            reference.strict = false;
          }
        }

      // Store only boundary anchors inherited from individually valid and
      // locally coherent cells. In corrective mode no interior normal of the
      // bad before state is imposed on the candidate.
      for(LocalBoundarySegment &segment : reference.boundary) {
        for(const LocalOrientationTriangle &triangle : reference.triangles) {
          if(!triangle.reliable) continue;
          bool hasFirst = false, hasSecond = false;
          for(std::size_t i = 0; i < 3; ++i) {
            hasFirst = hasFirst || samePoint(
              segment.firstUv, segment.firstXyz,
              triangle.uv[i], triangle.xyz[i]);
            hasSecond = hasSecond || samePoint(
              segment.secondUv, segment.secondXyz,
              triangle.uv[i], triangle.xyz[i]);
          }
          if(!hasFirst || !hasSecond) continue;
          segment.normal = triangle.normal;
          segment.normalNorm = triangle.normalNorm;
          segment.reliable = true;
          break;
        }
      }

      reference.valid = !reference.boundary.empty();
      return reference.valid;
    }

    bool buildLocalPatchOrientationReference(
      GFace *face, const std::vector<MElement *> &elements,
      LocalPatchOrientationReference &reference)
    {
      reference = LocalPatchOrientationReference();
      if(!face || elements.empty()) return false;
      std::vector<MVertex *> vertices;
      std::unordered_map<MVertex *, std::size_t> index;
      std::vector<std::array<std::size_t, 3> > triangles;
      Pattern quadrangles;
      for(MElement *element : elements) {
        if(!element) return false;
        const std::size_t count = element->getNumPrimaryVertices();
        if(count != 3 && count != 4) return false;
        std::array<std::size_t, 4> indexed = {0, 0, 0, 0};
        for(std::size_t i = 0; i < count; ++i) {
          MVertex *vertex = element->getVertex(static_cast<int>(i));
          if(!vertex) return false;
          const auto inserted = index.emplace(vertex, vertices.size());
          if(inserted.second) vertices.push_back(vertex);
          indexed[i] = inserted.first->second;
        }
        if(count == 3)
          triangles.push_back({indexed[0], indexed[1], indexed[2]});
        else
          quadrangles.push_back(indexed);
      }
      std::vector<UV> uv(vertices.size());
      std::vector<Point> xyz(vertices.size());
      for(std::size_t i = 0; i < vertices.size(); ++i) {
        SPoint2 parameter;
        if(!persistentFaceParameter(face, vertices[i], parameter))
          return false;
        uv[i] = {parameter.x(), parameter.y()};
        xyz[i] = {vertices[i]->x(), vertices[i]->y(), vertices[i]->z()};
      }
      return buildLocalPatchOrientationReference(
        uv, xyz, triangles, quadrangles, reference);
    }

    bool localOrientationCoordinatesMatch(
      const UV &aUv, const Point &aXyz, const UV &bUv,
      const Point &bXyz, const LocalPatchOrientationReference &reference)
    {
      const double uvTolerance2 = 1.e-20 * std::max(
        reference.uvScale2, std::numeric_limits<double>::min());
      const double xyzTolerance2 = 1.e-20 * std::max(
        reference.xyzScale2, std::numeric_limits<double>::min());
      return localOrientationDistance2(aUv, bUv) <= uvTolerance2 &&
             localOrientationDistance2(aXyz, bXyz) <= xyzTolerance2;
    }

    double localOrientationPointSide(const UV &a, const UV &b,
                                     const UV &point, double orientation)
    {
      return orientation * localOrientationCross2(a, b, point);
    }

    bool localOrientationPointInTriangle(
      const UV &point, const LocalOrientationTriangle &triangle,
      const LocalPatchOrientationReference &reference)
    {
      const double orientation = triangle.twiceUvArea > 0. ? 1. : -1.;
      const double scale2 = std::max(
        reference.uvScale2, std::numeric_limits<double>::min());
      const double tolerance = -1.e-10 * scale2;
      // Most multipoint guards cover only one or two cells of C+C'. Reject
      // the other reference triangles with their UV boxes before evaluating
      // three oriented cross products. The padding contains the exact
      // half-plane tolerance above even for a very thin but still reliable
      // reference triangle; ambiguous cases merely lose this fast path.
      for(std::size_t coordinate = 0; coordinate < 2; ++coordinate)
        if(point[coordinate] <
             triangle.minimumUv[coordinate] -
               triangle.containmentPadding ||
           point[coordinate] >
             triangle.maximumUv[coordinate] +
               triangle.containmentPadding)
          return false;
      for(std::size_t i = 0; i < 3; ++i)
        if(localOrientationPointSide(
             triangle.uv[i], triangle.uv[(i + 1) % 3], point,
             orientation) < tolerance)
          return false;
      return true;
    }

    bool localOrientationNormalFollowsReference(
      const UV &sample, const Point &normal, double normalNorm,
      const LocalPatchOrientationReference &reference)
    {
      if(!reference.valid || !std::isfinite(normalNorm) ||
         normalNorm <= 1.e-12 * std::max(
           reference.xyzScale2, std::numeric_limits<double>::min()))
        return false;
      bool covered = false;
      for(const LocalOrientationTriangle &triangle : reference.triangles) {
        if(!triangle.reliable) continue;
        if(!localOrientationPointInTriangle(sample, triangle, reference))
          continue;
        covered = true;
        const double scalarProduct =
          normal[0] * triangle.normal[0] +
          normal[1] * triangle.normal[1] +
          normal[2] * triangle.normal[2];
        const double tolerance =
          1.e-10 * normalNorm * triangle.normalNorm;
        if(!std::isfinite(scalarProduct) || scalarProduct <= tolerance)
          return false;
      }
      return covered;
    }

    template <class TriangleRange, class QuadrangleRange>
    bool indexedPatchPreservesLocalOrientation(
      const LocalPatchOrientationReference &reference,
      const std::vector<UV> &uv, const std::vector<Point> &xyz,
      const TriangleRange &triangles, const QuadrangleRange &quadrangles)
    {
      if(!reference.valid || uv.size() != xyz.size()) return false;

      LocalPatchOrientationReference candidateTopology;
      if(!buildLocalPatchOrientationReference(
           uv, xyz, triangles, quadrangles, candidateTopology))
        return false;
      if(!candidateTopology.strict || candidateTopology.triangles.empty())
        return false;
      if(candidateTopology.boundary.size() != reference.boundary.size())
        return false;
      std::vector<bool> matched(candidateTopology.boundary.size(), false);
      std::size_t inheritedBoundaryNormals = 0;
      for(const LocalBoundarySegment &before : reference.boundary) {
        bool found = false;
        for(std::size_t i = 0; i < candidateTopology.boundary.size(); ++i) {
          if(matched[i]) continue;
          const LocalBoundarySegment &after = candidateTopology.boundary[i];
          if(localOrientationCoordinatesMatch(
               before.firstUv, before.firstXyz,
               after.firstUv, after.firstXyz, reference) &&
             localOrientationCoordinatesMatch(
               before.secondUv, before.secondXyz,
               after.secondUv, after.secondXyz, reference)) {
            if(before.reliable) {
              if(!after.reliable) return false;
              const double dot = before.normal[0] * after.normal[0] +
                before.normal[1] * after.normal[1] +
                before.normal[2] * after.normal[2];
              if(!std::isfinite(dot) ||
                 dot <= 1.e-10 * before.normalNorm * after.normalNorm)
                return false;
              ++inheritedBoundaryNormals;
            }
            matched[i] = true;
            found = true;
            break;
          }
        }
        if(!found) return false;
      }

      // Corrective fallback: the before cavity itself contains a folded or
      // degenerate cell. Do not inherit its bad interior lobes. The candidate
      // has already proved coherent winding, preserved the complete directed
      // boundary, and passed every fan and corner Jacobian. Any reliable
      // before boundary cell additionally anchors its physical side.
      if(!reference.strict) return true;
      if(inheritedBoundaryNormals != reference.boundary.size()) return false;

      // Test the oriented normal of every triangle and every quad fan lobe at
      // four interior samples. This both verifies coverage by the immutable
      // before patch and prevents a narrow flipped lobe from escaping through
      // a centroid-only test.
      for(const LocalOrientationTriangle &triangle :
          candidateTopology.triangles) {
        static const double weights[4][3] = {
          {1. / 3., 1. / 3., 1. / 3.},
          {.8, .1, .1}, {.1, .8, .1}, {.1, .1, .8}};
        for(const auto &weight : weights) {
          UV sample = {0., 0.};
          for(std::size_t vertex = 0; vertex < 3; ++vertex)
            for(std::size_t coordinate = 0; coordinate < 2; ++coordinate)
              sample[coordinate] +=
                weight[vertex] * triangle.uv[vertex][coordinate];
          if(!localOrientationNormalFollowsReference(
               sample, triangle.normal, triangle.normalNorm, reference))
            return false;
        }
      }

      // The fan tests finite subcells. Check the bilinear corner Jacobians as
      // well: a quad can retain a plausible center normal while one corner
      // has already folded through the old surface.
      for(const auto &quadrangle : quadrangles) {
        if(quadrangle.size() != 4) return false;
        for(std::size_t i = 0; i < 4; ++i) {
          const std::size_t current = quadrangle[i];
          const std::size_t next = quadrangle[(i + 1) % 4];
          const std::size_t previous = quadrangle[(i + 3) % 4];
          if(current >= uv.size() || next >= uv.size() ||
             previous >= uv.size())
            return false;
          const Point normal = localOrientationNormal(
            xyz[current], xyz[next], xyz[previous]);
          const double normalNorm = localOrientationNorm(normal);
          const UV sample = {
            .8 * uv[current][0] + .1 * uv[next][0] +
              .1 * uv[previous][0],
            .8 * uv[current][1] + .1 * uv[next][1] +
              .1 * uv[previous][1]};
          if(!localOrientationNormalFollowsReference(
               sample, normal, normalNorm, reference))
            return false;
        }
      }
      return true;
    }

    int sampledPhysicalJacobianFaceNormalSign(
      GFace *face, const UV &parameter, const Point &jacobian,
      double jacobianNorm, double physicalScale2)
    {
      if(!face || !std::isfinite(parameter[0]) ||
         !std::isfinite(parameter[1]) ||
         !std::isfinite(jacobianNorm) ||
         jacobianNorm <= 1.e-12 * std::max(
           physicalScale2, std::numeric_limits<double>::min()))
        return 0;
      const SPoint2 surfaceParameter(parameter[0], parameter[1]);
      const FaceNormalSampleCacheKey cacheKey = {
        face, exactDoubleBits(parameter[0]), exactDoubleBits(parameter[1])};
      auto cached = faceNormalSampleCache.find(cacheKey);
      if(cached == faceNormalSampleCache.end()) {
        FaceNormalSampleCacheEntry entry;
        discreteFace *discrete = dynamic_cast<discreteFace *>(face);
        bool haveNormal = false;
        if(discrete) {
          try {
            haveNormal = discrete->normalIfContainsParam(
              surfaceParameter, entry.normal);
          }
          catch(...) {
          }
        }
        else if(face->containsParam(surfaceParameter)) {
          try {
            entry.normal = face->normal(surfaceParameter);
            haveNormal = true;
          }
          catch(...) {
            // A candidate guard is a transactional predicate: inability to
            // evaluate the geometry rejects this candidate, but must never
            // turn a local cleanup attempt into a fatal meshing error.
          }
        }
        if(haveNormal) {
          entry.normalNorm = entry.normal.norm();
          entry.available = std::isfinite(entry.normal.x()) &&
            std::isfinite(entry.normal.y()) &&
            std::isfinite(entry.normal.z()) &&
            std::isfinite(entry.normalNorm) && entry.normalNorm > 0.;
        }
        cached = faceNormalSampleCache.emplace(cacheKey, entry).first;
      }
      if(!cached->second.available) return 0;
      const SVector3 &faceNormal = cached->second.normal;
      const double faceNormalNorm = cached->second.normalNorm;

      const double dot = jacobian[0] * faceNormal.x() +
                         jacobian[1] * faceNormal.y() +
                         jacobian[2] * faceNormal.z();
      const double tolerance =
        1.e-10 * jacobianNorm * faceNormalNorm;
      if(!std::isfinite(dot)) return 0;
      return dot > tolerance ? 1 : -1;
    }

    template <class TriangleRange, class QuadrangleRange>
    bool indexedPatchFollowsSampledFaceNormal(
      GFace *face, const std::vector<UV> &uv,
      const std::vector<Point> &xyz, const TriangleRange &triangles,
      const QuadrangleRange &quadrangles, int requiredSign = 1,
      bool allowUnevaluableSamples = false)
    {
      if(!face) return false;
      return GeometryGuard::indexedPatchFollowsNormals(
        [&](const UV &parameter, const Point &jacobian,
            double jacobianNorm, double physicalScale2) {
          return sampledPhysicalJacobianFaceNormalSign(
            face, parameter, jacobian, jacobianNorm, physicalScale2);
        }, uv, xyz, triangles, quadrangles, requiredSign,
        allowUnevaluableSamples);
    }

    template <class TriangleRange, class QuadrangleRange>
    bool indexedPatchPreservesSurfaceOrientation(
      GFace *face, const LocalPatchOrientationReference *reference,
      const std::vector<UV> &uv, const std::vector<Point> &xyz,
      const TriangleRange &triangles, const QuadrangleRange &quadrangles)
    {
      if(!face) return false;
      if(face->geomType() != GEntity::DiscreteSurface)
        return indexedPatchFollowsCadNormal(
          face, uv, xyz, triangles, quadrangles);
      return reference && indexedPatchPreservesLocalOrientation(
        *reference, uv, xyz, triangles, quadrangles) &&
        indexedPatchFollowsSampledFaceNormal(
          face, uv, xyz, triangles, quadrangles);
    }

    int surfaceElementCadNormalSign(
      GFace *face, MElement *element,
      const std::vector<SPoint2> *knownParameters = nullptr)
    {
      if(!face || !element) return 0;
      const std::size_t count = element->getNumPrimaryVertices();
      if(count != 3 && count != 4) return 0;
      const std::vector<SPoint2> recovered = knownParameters ?
        std::vector<SPoint2>() : persistentElementParameters(face, element);
      const std::vector<SPoint2> &parameters = knownParameters ?
        *knownParameters : recovered;
      if(parameters.size() < count) return 0;
      std::vector<UV> uv(count);
      std::vector<Point> xyz(count);
      std::vector<std::size_t> indices(count);
      for(std::size_t i = 0; i < count; ++i) {
        MVertex *vertex = element->getVertex(static_cast<int>(i));
        if(!vertex) return 0;
        uv[i] = {parameters[i].x(), parameters[i].y()};
        xyz[i] = {vertex->x(), vertex->y(), vertex->z()};
        indices[i] = i;
      }
      if(face->geomType() == GEntity::DiscreteSurface) {
        std::vector<std::vector<std::size_t> > triangles;
        std::vector<std::vector<std::size_t> > quadrangles;
        if(count == 3)
          triangles.push_back(indices);
        else
          quadrangles.push_back(indices);
        if(indexedPatchFollowsSampledFaceNormal(
             face, uv, xyz, triangles, quadrangles, 1))
          return 1;
        if(indexedPatchFollowsSampledFaceNormal(
             face, uv, xyz, triangles, quadrangles, -1))
          return -1;
        return 0;
      }
      return indexedElementCadNormalSign(face, indices, uv, xyz);
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

    bool canonicalElementGeometryLess(MElement *a, MElement *b)
    {
      if(a == b) return false;
      if(!a || !b) return std::less<MElement *>()(a, b);
      const std::size_t ac = a->getNumPrimaryVertices();
      const std::size_t bc = b->getNumPrimaryVertices();
      if(ac != bc) return ac < bc;
      std::array<MVertex *, 4> av = {nullptr, nullptr, nullptr, nullptr};
      std::array<MVertex *, 4> bv = {nullptr, nullptr, nullptr, nullptr};
      for(std::size_t i = 0; i < ac; ++i) {
        av[i] = a->getVertex(static_cast<int>(i));
        bv[i] = b->getVertex(static_cast<int>(i));
      }
      std::sort(av.begin(), av.begin() + ac, canonicalVertexGeometryLess);
      std::sort(bv.begin(), bv.begin() + bc, canonicalVertexGeometryLess);
      if(std::lexicographical_compare(
           av.begin(), av.begin() + ac, bv.begin(), bv.begin() + bc,
           canonicalVertexGeometryLess))
        return true;
      if(std::lexicographical_compare(
           bv.begin(), bv.begin() + bc, av.begin(), av.begin() + ac,
           canonicalVertexGeometryLess))
        return false;
      if(a->getPartition() != b->getPartition())
        return a->getPartition() < b->getPartition();
      if(a->getVisibility() != b->getVisibility())
        return a->getVisibility() < b->getVisibility();
      return a->getNum() < b->getNum();
    }

    bool canonicalEdgeGeometryLess(const Edge &a, const Edge &b)
    {
      Edge first = a, second = b;
      if(canonicalVertexGeometryLess(first.second, first.first))
        std::swap(first.first, first.second);
      if(canonicalVertexGeometryLess(second.second, second.first))
        std::swap(second.first, second.second);
      if(canonicalVertexGeometryLess(first.first, second.first)) return true;
      if(canonicalVertexGeometryLess(second.first, first.first)) return false;
      return canonicalVertexGeometryLess(first.second, second.second);
    }

    struct ValenceObjective {
      std::size_t severeCount = 0;
      std::size_t irregularCount = 0;
      double penalty = 0.;
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

    struct SurfaceCellComplexValidity {
      bool structurallyRegular = true;
      bool orientable = true;
    };

    // Read-only incidence and orientability checks for the final surface mesh.
    SurfaceCellComplexValidity validateSurfaceCellComplex(
      const std::vector<MElement *> &elements)
    {
      struct Incidence {
        MElement *element = nullptr;
        MVertex *origin = nullptr;
        MVertex *destination = nullptr;
      };
      struct Constraint {
        MElement *neighbor = nullptr;
        bool oppositeFlip = false;
      };

      SurfaceCellComplexValidity result;
      std::map<Edge, std::vector<Incidence> > incidences;
      std::set<MElement *> uniqueElements;
      std::map<MElement *, std::size_t, std::less<MElement *> > elementIndex;
      for(std::size_t elementNumber = 0;
          elementNumber < elements.size(); ++elementNumber) {
        MElement *element = elements[elementNumber];
        if(!element || !uniqueElements.insert(element).second) {
          result.structurallyRegular = false;
          return result;
        }
        const std::size_t count = element->getNumPrimaryVertices();
        if(count != 3 && count != 4) {
          result.structurallyRegular = false;
          return result;
        }
        std::set<MVertex *> uniqueVertices;
        for(std::size_t i = 0; i < count; ++i) {
          MVertex *origin = element->getVertex(static_cast<int>(i));
          MVertex *destination = element->getVertex(
            static_cast<int>((i + 1) % count));
          if(!origin || !destination ||
             !uniqueVertices.insert(origin).second) {
            result.structurallyRegular = false;
            return result;
          }
          incidences[canonicalEdge(origin, destination)].push_back(
            {element, origin, destination});
        }
        elementIndex[element] = elementNumber;
      }

      std::map<MElement *, std::vector<Constraint> > constraints;
      std::map<std::pair<std::size_t, std::size_t>, std::size_t> sharedEdges;
      for(const auto &entry : incidences) {
        if(entry.second.size() > 2) {
          result.structurallyRegular = false;
          return result;
        }
        if(entry.second.size() != 2) continue;
        const Incidence &first = entry.second[0];
        const Incidence &second = entry.second[1];
        if(first.element == second.element) {
          result.structurallyRegular = false;
          return result;
        }
        std::size_t a = elementIndex[first.element];
        std::size_t b = elementIndex[second.element];
        if(b < a) std::swap(a, b);
        ++sharedEdges[{a, b}];
        const bool sameDirection =
          first.origin == second.origin &&
          first.destination == second.destination;
        constraints[first.element].push_back(
          {second.element, sameDirection});
        constraints[second.element].push_back(
          {first.element, sameDirection});
      }

      for(const auto &entry : sharedEdges)
        if(entry.second > 1) {
          result.structurallyRegular = false;
          return result;
        }

      std::map<MElement *, bool> flip;
      for(MElement *root : elements) {
        if(flip.find(root) != flip.end()) continue;
        std::queue<MElement *> pending;
        flip[root] = false;
        pending.push(root);
        while(!pending.empty()) {
          MElement *element = pending.front();
          pending.pop();
          const auto found = constraints.find(element);
          if(found == constraints.end()) continue;
          for(const Constraint &constraint : found->second) {
            const bool expected =
              flip[element] != constraint.oppositeFlip;
            const auto known = flip.find(constraint.neighbor);
            if(known == flip.end()) {
              flip[constraint.neighbor] = expected;
              pending.push(constraint.neighbor);
            }
            else if(known->second != expected) {
              result.orientable = false;
              return result;
            }
          }
        }
      }
      return result;
    }

    // Canonically ordered views for hole-ring edits. FaceHalfEdge owns the
    // connectivity, Gmsh handle maps and replacement transactions.
    class CavityContext {
      using Index = HalfEdgeMesh::Index;
      GFace *_face;
      mutable FaceHalfEdge _topology;
      mutable bool _elementsViewDirty = true;
      mutable bool _edgesViewDirty = true;
      mutable std::vector<MElement *> _elementsView;
      mutable std::vector<std::pair<Edge, std::vector<MElement *> > >
        _edgesView;
      // Adjacency and degree remain exact until an accepted topology edit;
      // canonical order also depends on geometry.
      mutable std::unordered_map<MVertex *, std::vector<MElement *> >
        _incidentElementsViews;
      mutable std::map<Edge, std::vector<MElement *> >
        _edgeIncidentElementsViews;
      mutable std::unordered_map<MElement *, std::vector<MElement *> >
        _neighborViews;
      mutable std::unordered_map<MVertex *, std::size_t> _quadDegreeViews;
      // Boundary-layer protection is immutable throughout the ring pass.
      mutable GFace *_protectedVertexFace = nullptr;
      mutable std::set<MVertex *> _protectedVertexView;

      template <class T>
      static bool sameUniquePointers(const std::vector<T *> &first,
                                     const std::vector<T *> &second)
      {
        if(first.size() != second.size()) return false;
        const std::set<T *, std::less<T *> > firstSet(
          first.begin(), first.end());
        const std::set<T *, std::less<T *> > secondSet(
          second.begin(), second.end());
        return firstSet.size() == first.size() &&
               secondSet.size() == second.size() && firstSet == secondSet;
      }

      void invalidateSortedViews() const
      {
        _elementsViewDirty = true;
        _edgesViewDirty = true;
        _incidentElementsViews.clear();
        _edgeIncidentElementsViews.clear();
        _neighborViews.clear();
        _quadDegreeViews.clear();
      }

      const HalfEdgeMesh::Mesh &mesh() const
      { return _topology.numericMesh(); }

      MVertex *vertex(Index index) const { return _topology.vertex(index); }
      MElement *element(Index index) const { return _topology.element(index); }

    public:
      using PreparedReplacement = FaceHalfEdge::PreparedReplacement;

      explicit CavityContext(GFace *face) : _face(face), _topology(face) {}

      bool manifold() const { return _topology.valid(); }

      const std::set<MVertex *> &protectedVertices(GFace *face) const
      {
        if(_protectedVertexFace != face) {
          _protectedVertexView = protectedFaceVertices(face);
          _protectedVertexFace = face;
        }
        return _protectedVertexView;
      }

      PreparedReplacement prepareReplacement(
        const std::vector<MElement *> &removed,
        const std::vector<MElement *> &inserted) const
      {
        PreparedReplacement prepared;
        _topology.prepareReplacement(removed, inserted, prepared);
        return prepared;
      }

      // The shared transaction owns the actual GFace edit. The cavity policy
      // additionally requires an exact match with the candidate's ownership
      // diff, including its boundary, new vertices and retired vertices.
      bool preflightPreparedDiff(const PreparedReplacement &prepared,
                                 const GFaceMeshDiff &diff) const
      {
        return _topology.replacementValid(prepared) && !diff.done &&
          diff.gf == _face && diff.gf == diff.before.gf &&
          diff.gf == diff.after.gf && !diff.after.elements.empty() &&
          diff.before.bdrVertices == diff.after.bdrVertices &&
          sameUniquePointers(diff.before.elements,
                             prepared.removedElements()) &&
          sameUniquePointers(diff.after.elements,
                             prepared.insertedElements()) &&
          sameUniquePointers(diff.before.intVertices,
                             prepared.retiredVertices()) &&
          sameUniquePointers(diff.after.intVertices,
                             prepared.newVertices()) &&
          patchIsTopologicallyValid(diff.after);
      }

      bool commitPrepared(PreparedReplacement &prepared, GFaceMeshDiff &diff)
      {
        if(!preflightPreparedDiff(prepared, diff) ||
           !_topology.replace(prepared))
          return false;
        // FaceHalfEdge consumed the candidate and deleted the old objects.
        // Leave neither set for the GFaceMeshDiff destructor to delete again.
        diff.before.elements.clear();
        diff.before.intVertices.clear();
        diff.after.elements.clear();
        diff.after.intVertices.clear();
        diff.done = true;
        invalidateSortedViews();
        return true;
      }

      std::vector<MElement *> elements() const
      {
        if(_elementsViewDirty) {
          _elementsView.clear();
          for(const Index index : mesh().faces())
            if(MElement *current = element(index))
              _elementsView.push_back(current);
          std::sort(_elementsView.begin(), _elementsView.end(),
                    canonicalElementGeometryLess);
          _elementsViewDirty = false;
        }
        return _elementsView;
      }

      // Canonical ordering changes only when the shared numeric coordinates do.
      bool synchronizeGeometry(const std::vector<MVertex *> &vertices) const
      {
        const bool changed = _topology.refreshGeometry(vertices);
        if(changed) invalidateSortedViews();
        return changed;
      }

      std::vector<MElement *> incidentElements(MVertex *vertex) const
      {
        const auto cached = _incidentElementsViews.find(vertex);
        if(cached != _incidentElementsViews.end()) return cached->second;
        std::vector<MElement *> result;
        const Index vertexIndex = _topology.id(vertex);
        if(vertexIndex == HalfEdgeMesh::invalid) return result;
        for(const Index index : mesh().incidentFaces(vertexIndex))
          if(MElement *current = element(index)) result.push_back(current);
        std::sort(result.begin(), result.end(),
                  canonicalElementGeometryLess);
        return _incidentElementsViews.emplace(vertex, std::move(result))
          .first->second;
      }

      std::vector<MElement *> incidentElements(const Edge &edge) const
      {
        const auto cached = _edgeIncidentElementsViews.find(edge);
        if(cached != _edgeIncidentElementsViews.end())
          return cached->second;
        std::vector<MElement *> result;
        const Index first = _topology.id(edge.first);
        const Index second = _topology.id(edge.second);
        if(first == HalfEdgeMesh::invalid ||
           second == HalfEdgeMesh::invalid)
          return result;
        for(const Index index : mesh().incidentFaces(
              HalfEdgeMesh::canonicalEdge(first, second)))
          if(MElement *current = element(index)) result.push_back(current);
        std::sort(result.begin(), result.end(),
                  canonicalElementGeometryLess);
        return _edgeIncidentElementsViews.emplace(edge, std::move(result))
          .first->second;
      }

      std::size_t elementCount(std::size_t primaryVertexCount) const
      {
        return mesh().faceCount(primaryVertexCount);
      }

      std::size_t quadDegree(MVertex *vertex) const
      {
        const auto cached = _quadDegreeViews.find(vertex);
        if(cached != _quadDegreeViews.end()) return cached->second;
        const Index index = _topology.id(vertex);
        const std::size_t degree = index == HalfEdgeMesh::invalid ?
          0 : mesh().quadDegree(index);
        _quadDegreeViews[vertex] = degree;
        return degree;
      }

      std::vector<MElement *> neighbors(MElement *element) const
      {
        const auto cached = _neighborViews.find(element);
        if(cached != _neighborViews.end()) return cached->second;
        std::vector<MElement *> result;
        const Index face = _topology.id(element);
        if(face == HalfEdgeMesh::invalid) return result;
        for(const Index index : mesh().neighbors(face))
          if(MElement *current = this->element(index))
            result.push_back(current);
        std::sort(result.begin(), result.end(),
                  canonicalElementGeometryLess);
        return _neighborViews.emplace(element, std::move(result))
          .first->second;
      }

      std::vector<std::pair<Edge, std::vector<MElement *> > > edges() const
      {
        if(!_edgesViewDirty) return _edgesView;
        _edgesView.clear();
        const std::vector<HalfEdgeMesh::EdgeFaces> indexedEdges =
          mesh().edges();
        _edgesView.reserve(indexedEdges.size());
        for(const HalfEdgeMesh::EdgeFaces &entry : indexedEdges) {
          std::vector<MElement *> elements;
          elements.reserve(entry.faces.size());
          for(const Index index : entry.faces)
            if(MElement *current = element(index))
              elements.push_back(current);
          std::sort(elements.begin(), elements.end(),
                    canonicalElementGeometryLess);
          MVertex *first = vertex(entry.edge.first);
          MVertex *second = vertex(entry.edge.second);
          if(first && second && !elements.empty())
            _edgesView.push_back(
              {canonicalEdge(first, second), std::move(elements)});
        }
        std::sort(_edgesView.begin(), _edgesView.end(),
                  [](const auto &a, const auto &b) {
                    return canonicalEdgeGeometryLess(a.first, b.first);
                  });
        _edgesViewDirty = false;
        return _edgesView;
      }
    };

    // Candidate ownership remains with the diff until the shared half-edge
    // transaction succeeds. Recheck the prepared edit immediately at commit.
    class FaceRewriteTransaction {
      CavityContext &_topology;
      GFaceMeshDiff &_diff;
      CavityContext::PreparedReplacement _prepared;
      bool _valid;

    public:
      FaceRewriteTransaction(CavityContext &topology, GFaceMeshDiff &diff)
        : _topology(topology), _diff(diff),
          _prepared(topology.prepareReplacement(
            diff.before.elements, diff.after.elements)),
          _valid(topology.preflightPreparedDiff(_prepared, diff))
      {
        if(!_valid && Msg::GetVerbosity() > 5)
          Msg::Info("QuadOptimizer transaction: %s preflight rejected the "
                    "candidate",
                    _prepared ? "GFace/half-edge concordance" :
                                "numeric topology");
      }

      explicit operator bool() const { return _valid; }

      bool execute()
      {
        if(!_valid) return false;
        _valid = false;
        if(_topology.commitPrepared(_prepared, _diff)) return true;
        if(Msg::GetVerbosity() > 5)
          Msg::Info("QuadOptimizer transaction: execution preflight "
                    "rejected the candidate");
        return false;
      }
    };

    double boundaryDomainAngleDegrees(
      GFace *face, MVertex *vertex,
      const std::vector<MElement *> &incidentElements);

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

    std::size_t idealQuadDegree(
      GFace *face, MVertex *vertex,
      const std::vector<MElement *> &incidentElements)
    {
      if(vertex && vertex->onWhat() == face) return 4;
      const double angle = boundaryDomainAngleDegrees(
        face, vertex, incidentElements);
      if(angle < 25.) return 0;
      if(angle < 115.) return 1;
      if(angle < 205.) return 2;
      if(angle < 295.) return 3;
      return 4;
    }

    std::size_t idealQuadDegree(GFace *face, MVertex *vertex,
                                const CavityContext &topology)
    {
      return idealQuadDegree(face, vertex,
                             topology.incidentElements(vertex));
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

    double orientation(const UV &a, const UV &b, const UV &point)
    {
      return (b[0] - a[0]) * (point[1] - a[1]) -
             (b[1] - a[1]) * (point[0] - a[0]);
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

    double distance(const Point &a, const Point &b)
    {
      return std::sqrt(std::pow(a[0] - b[0], 2) +
                       std::pow(a[1] - b[1], 2) +
                       std::pow(a[2] - b[2], 2));
    }

    double prescribedTargetSize(
      GFace *face, const UV &uv, const Point &xyz,
      const SmallCavityOptimizerOptions &options)
    {
      if(options.targetSize > 0.) return options.targetSize;

      // PACK is driven by the norm of a vector-valued background
      // field. Query that field directly when it is still available: the
      // generic BGM_MeshSize path can apply additional clamps and factors and
      // thus need not reproduce the length used during packing exactly.
      if((options.enforceSizeMap || options.auditSizeMap) && face &&
         face->model()) {
        FieldManager *fields = face->model()->getFields();
        if(fields) {
          Field *field = fields->getDirectionField();
          if(field) {
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
         !std::isfinite(options.edgeMidpointCadSwapTriggerRatio) ||
         options.edgeMidpointCadSwapTriggerRatio < 0. ||
         !std::isfinite(
           options.edgeMidpointCadSwapMaximumRemainingFraction) ||
         options.edgeMidpointCadSwapMaximumRemainingFraction < 0. ||
         options.edgeMidpointCadSwapMaximumRemainingFraction >= 1. ||
         !std::isfinite(options.maximumNormalizedCadRegression) ||
         options.maximumNormalizedCadRegression < 0. ||
         !std::isfinite(options.maximumCadDistanceIncreaseRatio) ||
         options.maximumCadDistanceIncreaseRatio < 0. ||
         !std::isfinite(options.minimumRecombinationQuality) ||
         options.minimumRecombinationQuality < 0.)
        return false;

      if(options.targetSize > 0.) {
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
        Field *field = fields ? fields->getDirectionField() : nullptr;
        if(field)
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
      // Measure the chord to the CAD point at the interpolated parameter.
      // A supporting plane gives an exact planar distance without projection.
      double sampleDistance = -1.;
      if(supportingPlane) {
        const Point offset = {
          meshPoint[0] - supportingPlane->origin[0],
          meshPoint[1] - supportingPlane->origin[1],
          meshPoint[2] - supportingPlane->origin[2]};
        sampleDistance = std::abs(
          offset[0] * supportingPlane->unitNormal[0] +
          offset[1] * supportingPlane->unitNormal[1] +
          offset[2] * supportingPlane->unitNormal[2]);
      }
      else {
        const GPoint geometry =
          face->point(SPoint2(parameter[0], parameter[1]));
        if(!geometry.succeeded() || !std::isfinite(geometry.x()) ||
           !std::isfinite(geometry.y()) || !std::isfinite(geometry.z())) {
          ++deviation.invalidSampleCount;
          return false;
        }
        const Point geometryPoint = {
          geometry.x(), geometry.y(), geometry.z()};
        sampleDistance = distance(meshPoint, geometryPoint);
      }
      if(!std::isfinite(sampleDistance)) {
        ++deviation.invalidSampleCount;
        return false;
      }
      deviation.maximumDistance =
        std::max(deviation.maximumDistance, sampleDistance);
      deviation.squaredDistanceIntegral +=
        areaWeight * sampleDistance * sampleDistance;
      deviation.sampledArea += areaWeight;
      return true;
    }

    bool accumulateQuadrangleGeometryDeviation(
      GFace *face, const std::array<UV, 4> &parameters,
      const std::array<Point, 4> &vertices,
      GeometryDeviation &deviation,
      const SupportingPlane *supportingPlane)
    {
      // Tensor Gauss integration of squared CAD deviation over the physical
      // bilinear quad, weighted by physical area.
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
      const SupportingPlane *supportingPlane)
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
      // The report evaluates a chord to the CAD at every quadrature point, so
      // curved faces require valid, element-local UV values. A plane is the
      // only safe exception: its distance is evaluated analytically from the
      // supporting geometric plane.
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

    bool replacementElementsPreserveSurfaceOrientation(
      GFace *face, const std::vector<MElement *> &beforeElements,
      const std::vector<MElement *> &elements,
      const std::vector<MVertex *> &localVertices,
      const std::vector<UV> &uv, const std::vector<Point> &xyz)
    {
      if(localVertices.size() != uv.size() || uv.size() != xyz.size())
        return false;
      std::unordered_map<MVertex *, std::size_t> index;
      index.reserve(localVertices.size());
      for(std::size_t i = 0; i < localVertices.size(); ++i)
        if(!localVertices[i] || !index.emplace(localVertices[i], i).second)
          return false;

      std::vector<std::array<std::size_t, 3> > triangles;
      Pattern quadrangles;
      for(MElement *element : elements) {
        if(!element) return false;
        const std::size_t count = element->getNumPrimaryVertices();
        if(count != 3 && count != 4) return false;
        std::array<std::size_t, 4> indexed = {0, 0, 0, 0};
        for(std::size_t i = 0; i < count; ++i) {
          const auto found = index.find(
            element->getVertex(static_cast<int>(i)));
          if(found == index.end()) return false;
          indexed[i] = found->second;
        }
        if(count == 3)
          triangles.push_back({indexed[0], indexed[1], indexed[2]});
        else
          quadrangles.push_back(indexed);
      }

      LocalPatchOrientationReference reference;
      const LocalPatchOrientationReference *referencePointer = nullptr;
      if(face && face->geomType() == GEntity::DiscreteSurface) {
        const bool hasReliableOpposedSample = std::any_of(
          beforeElements.begin(), beforeElements.end(),
          [&](MElement *element) {
            return surfaceElementCadNormalSign(face, element) < 0;
          });
        const bool haveLocalReference = buildLocalPatchOrientationReference(
          face, beforeElements, reference);
        // A corrective rewrite must not preserve the coherent but physically
        // wrong side of an input patch.  Once an opposed GFace sample has
        // been observed, the sampled physical Jacobian is the only valid
        // orientation oracle.  For ordinary patches retain the stricter
        // local-reference-plus-GFace contract.
        if(!haveLocalReference && !hasReliableOpposedSample) return false;
        if(haveLocalReference && !hasReliableOpposedSample)
          referencePointer = &reference;
      }
      return face && face->geomType() == GEntity::DiscreteSurface &&
          !referencePointer ?
        indexedPatchFollowsSampledFaceNormal(
          face, uv, xyz, triangles, quadrangles) :
        indexedPatchPreservesSurfaceOrientation(
          face, referencePointer, uv, xyz, triangles, quadrangles);
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

    bool collectBoundaryLoops(const CavityContext &topology,
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
      const CavityContext &topology,
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

    // This ledger belongs only to the explicit ring pass. Unknown elements
    // elsewhere on the face do not veto a local ring, but every replaced and
    // inserted element must have complete CAD coverage. The immutable initial
    // limits prevent successive rings from accumulating the local allowance.
    struct HoleRingCadGuard {
      GFace *face;
      const SmallCavityOptimizerOptions &options;
      CadDistance::Contribution current;
      double initialMean = 0., initialMaximum = 0.;
      std::size_t physicalNormalQueries = 0, physicalNormalCovered = 0;

      double target(const Point &xyz, const UV &uv) const
      {
        return edgeLengthCriteria(face, uv, xyz, options).target;
      }

      CadDistance::Contribution sample(MElement *element,
                                      const std::vector<UV> &uv) const
      {
        return CadDistance::sampleElement(face, element, uv,
          [&](const Point &xyz, const UV &parameter) {
            return target(xyz, parameter);
          });
      }

      HoleRingCadGuard(GFace *face_, const SmallCavityOptimizerOptions &options_,
                       const std::vector<MElement *> &elements)
        : face(face_), options(options_)
      {
        for(MElement *element : elements) {
          std::vector<UV> uv;
          if(!CadDistance::elementParameters(face, element, uv)) continue;
          const auto value = sample(element, uv);
          if(value.complete()) current += value;
        }
        if(current.sampledArea > 0.)
          initialMean = current.normalizedSquaredDistanceIntegral /
                        current.sampledArea;
        initialMaximum = current.maximumNormalizedDistance;
      }

      CadDistance::Contribution replaced(const CadDistance::Contribution &before,
                                         const CadDistance::Contribution &after) const
      {
        auto next = current;
        next.sampledArea += after.sampledArea - before.sampledArea;
        next.squaredDistanceIntegral +=
          after.squaredDistanceIntegral - before.squaredDistanceIntegral;
        next.normalizedSquaredDistanceIntegral +=
          after.normalizedSquaredDistanceIntegral -
          before.normalizedSquaredDistanceIntegral;
        return next;
      }

      bool admissible(const CadDistance::Contribution &before,
                       const CadDistance::Contribution &after) const
      {
        if(!before.complete() || !after.complete()) return false;
        const auto next = replaced(before, after);
        return next.sampledArea > 0. &&
          std::isfinite(next.normalizedSquaredDistanceIntegral) &&
          after.normalizedSquaredDistanceIntegral / after.sampledArea <=
            before.normalizedSquaredDistanceIntegral / before.sampledArea +
            options.maximumNormalizedCadRegression + 1.e-15 &&
          after.maximumNormalizedDistance <= before.maximumNormalizedDistance +
            options.maximumCadDistanceIncreaseRatio + 1.e-14 &&
          next.normalizedSquaredDistanceIntegral / next.sampledArea <=
            initialMean + options.maximumNormalizedCadRegression + 1.e-14 &&
          after.maximumNormalizedDistance <= initialMaximum +
            options.maximumCadDistanceIncreaseRatio + 1.e-14;
      }

      // Match the final Fast split/merge predicate: do not introduce a quad
      // with a clearly excessive diagonal when the other one fits the CAD.
      bool admissibleQuad(MQuadrangle &quad, const std::vector<UV> &uv) const
      {
        const double eta = quad.etaShapeMeasure();
        const double sicn = quad.minSICNShapeMeasure();
        if(!std::isfinite(eta) || !(eta > 0.) ||
           !std::isfinite(sicn) || !(sicn > 0.)) return false;
        if(options.finalSplitCadDistanceRatio < 0.) return true;
        double distance[2] = {0., 0.};
        for(int diagonal = 0; diagonal < 2; ++diagonal) {
          const MVertex *a = quad.getVertex(diagonal);
          const MVertex *b = quad.getVertex(diagonal + 2);
          for(const double t : {.25, .5, .75}) {
            const Point xyz = {{(1. - t) * a->x() + t * b->x(),
                                (1. - t) * a->y() + t * b->y(),
                                (1. - t) * a->z() + t * b->z()}};
            const UV guess = {{(1. - t) * uv[diagonal][0] + t * uv[diagonal + 2][0],
                               (1. - t) * uv[diagonal][1] + t * uv[diagonal + 2][1]}};
            try {
              const double h = target(xyz, guess);
              const GPoint projected = face->closestPoint(
                SPoint3(xyz[0], xyz[1], xyz[2]), guess.data());
              if(!(h > 0.) || !std::isfinite(h) || !projected.succeeded())
                return false;
              const double d = std::hypot(projected.x() - xyz[0],
                projected.y() - xyz[1], projected.z() - xyz[2]) / h;
              if(!std::isfinite(d)) return false;
              distance[diagonal] = std::max(distance[diagonal], d);
            }
            catch(...) { return false; }
          }
        }
        const double low = std::min(distance[0], distance[1]);
        const double high = std::max(distance[0], distance[1]);
        return !(high > options.finalSplitCadDistanceRatio &&
                 low <= options.finalSplitCadDistanceRatio && low <= .5 * high);
      }
    };

    bool holeRingPatchFollowsNormals(
      HoleRingCadGuard &guard, const std::vector<UV> &uv,
      const std::vector<Point> &positions,
      const std::vector<std::array<std::size_t, 3>> &triangles,
      const std::vector<std::array<std::size_t, 4>> &quadrangles,
      const std::vector<MVertex *> &localVertices,
      std::size_t existingQuadrangleCount = std::numeric_limits<std::size_t>::max(),
      double fraction = 0.)
    {
      GFace *face = guard.face;
      const auto &options = guard.options;
      const std::size_t existingVertexCount = localVertices.size();
      auto followsElement = [&](const auto &indices, std::size_t cell) {
        std::size_t queries = 0, zero = 0, negative = 0;
        UV firstUnavailable = {{0., 0.}}, firstOpposed = {{0., 0.}};
        std::vector<std::vector<std::size_t>> tri, quad;
        (indices.size() == 3 ? tri : quad).emplace_back(
          indices.begin(), indices.end());
        const bool follows = GeometryGuard::indexedPatchFollowsNormals(
          [&](const UV &parameter, const Point &jacobian,
              double norm, double scale2) {
            const std::size_t sample = queries;
            ++queries;
            int sign = sampledPhysicalJacobianFaceNormalSign(
              face, parameter, jacobian, norm, scale2);
            // A coarse hole edge is a physical chord: its interpolated UV
            // can lie outside the fine trimmed chart. Resolve an unknown
            // normal on the same physical sample, never an opposed normal.
            // Keep the physical Jacobian's original non-degeneracy guard.
            if(sign == 0 && face->geomType() == GEntity::DiscreteSurface &&
               std::isfinite(norm) && norm > 1.e-12 * std::max(
                 scale2, std::numeric_limits<double>::min())) {
              ++guard.physicalNormalQueries;
              Point sampleXyz = {{0., 0., 0.}};
              double weight[4] = {0., 0., 0., 0.};
              if(indices.size() == 3 && sample < 4) {
                static const double triangleWeight[4][3] = {
                  {1. / 3., 1. / 3., 1. / 3.},
                  {.98, .01, .01}, {.01, .98, .01}, {.01, .01, .98}};
                std::copy(triangleWeight[sample], triangleWeight[sample] + 3,
                          weight);
              }
              else if(indices.size() == 4 && sample < 8) {
                constexpr double g = 0.57735026918962576451;
                constexpr double c = 1. - 1.e-6;
                static const UV samples[8] = {
                  {-g, -g}, {g, -g}, {g, g}, {-g, g},
                  {-c, -c}, {c, -c}, {c, c}, {-c, c}};
                const double xi = samples[sample][0], eta = samples[sample][1];
                weight[0] = .25 * (1. - xi) * (1. - eta);
                weight[1] = .25 * (1. + xi) * (1. - eta);
                weight[2] = .25 * (1. + xi) * (1. + eta);
                weight[3] = .25 * (1. - xi) * (1. + eta);
              }
              for(std::size_t i = 0; i < indices.size(); ++i)
                for(int d = 0; d < 3; ++d)
                  sampleXyz[d] += weight[i] * positions[indices[i]][d];
              try {
                SVector3 normal;
                const GPoint projected = static_cast<discreteFace *>(face)->
                  closestPoint(SPoint3(sampleXyz[0], sampleXyz[1], sampleXyz[2]),
                               parameter.data(), &normal);
                const double h = guard.target(sampleXyz, parameter);
                const double normalNorm = normal.norm();
                const double distance = std::hypot(
                  projected.x() - sampleXyz[0], projected.y() - sampleXyz[1],
                  projected.z() - sampleXyz[2]);
                const double product = jacobian[0] * normal.x() +
                  jacobian[1] * normal.y() + jacobian[2] * normal.z();
                if(projected.succeeded() && h > 0. && std::isfinite(h) &&
                   std::isfinite(normalNorm) && normalNorm > 0. &&
                   std::isfinite(distance) &&
                   distance <= options.maximumCadDistanceIncreaseRatio * h &&
                   std::isfinite(product)) {
                  ++guard.physicalNormalCovered;
                  sign = product > 1.e-10 * norm * normalNorm ? 1 : -1;
                }
              }
              catch(...) {}
            }
            if(sign == 0 && zero++ == 0) firstUnavailable = parameter;
            if(sign < 0 && negative++ == 0) firstOpposed = parameter;
            return sign;
          }, uv, positions, tri, quad);
        const std::size_t expected = indices.size() == 3 ? 4 : 8;
        if(follows && !zero && !negative && queries == expected) return true;
        if(options.verbose > 1) {
          std::size_t nodes[4] = {0, 0, 0, 0};
          for(std::size_t i = 0; i < indices.size(); ++i)
            if(indices[i] < existingVertexCount)
              nodes[i] = localVertices[indices[i]]->getNum();
          Msg::Info("OptimizeQuadHoleRings face=%d fraction=%g %s[%zu] "
                    "ring=%d normalQueries=%zu/%zu zero=%zu negative=%zu "
                    "guard=%d nodes=[%zu,%zu,%zu,%zu] "
                    "firstUnavailableUV=[%.17g,%.17g] "
                    "firstOpposedUV=[%.17g,%.17g]",
                    face->tag(), fraction, indices.size() == 3 ? "T" : "Q",
                    cell, int(indices.size() == 4 && cell >= existingQuadrangleCount),
                    queries, expected, zero, negative, int(follows),
                    nodes[0], nodes[1], nodes[2], nodes[3],
                    firstUnavailable[0], firstUnavailable[1],
                    firstOpposed[0], firstOpposed[1]);
        }
        return false;
      };
      for(std::size_t i = 0; i < triangles.size(); ++i)
        if(!followsElement(triangles[i], i)) return false;
      for(std::size_t i = 0; i < quadrangles.size(); ++i)
        if(!followsElement(quadrangles[i], i)) return false;

      return true;
    }

    bool tryPillowHole(GFace *face, const BoundaryLoop &boundary,
                       int neighborLayers,
                       CavityContext &topology,
                       const SmallCavityOptimizerOptions &options,
                       std::size_t &insertedQuadrangles,
                       bool &alreadyPillowed,
                       HoleRingCadGuard &ringGuard)
    {
      insertedQuadrangles = 0;
      alreadyPillowed = false;
      if(!face || boundary.vertices.size() < 3 || neighborLayers <= 0)
        return false;
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

      const std::set<MVertex *> &protectedVertices =
        topology.protectedVertices(face);
      if(std::any_of(loop.begin(), loop.end(), [&](MVertex *vertex) {
           return protectedVertices.find(vertex) != protectedVertices.end();
         }))
        return false;
      {
        const std::set<MVertex *> boundaryVertices(loop.begin(), loop.end());
        for(GEdge *curve : face->getEmbeddedEdges())
          for(MLine *line : curve->lines)
            if(boundaryVertices.count(line->getVertex(0)) ||
               boundaryVertices.count(line->getVertex(1))) {
              // The annular rewrite duplicates every hole vertex in the old
              // cells. A curve ending here would require a cut ring to keep
              // its 1D/2D incidence; do not silently detach that constraint.
              if(options.verbose)
                Msg::Info("OptimizeQuadHoleRings face=%d rejected: embedded "
                          "curve %d meets hole boundary", face->tag(), curve->tag());
              return false;
            }
      }

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
        return false;
      }
      if(!winslow.success || !winslow.untangled) {
        return false;
      }
      const std::vector<UV> targetPlanePoints = planePoints;
      const std::vector<UV> initialSurfacePoints = points;
      GFaceMeshPatch originalPatch;
      originalPatch.gf = face;
      originalPatch.elements.assign(selected.begin(), selected.end());
      LocalPatchOrientationReference beforeOrientation;
      const LocalPatchOrientationReference *beforeOrientationPointer =
        nullptr;
      if(face->geomType() == GEntity::DiscreteSurface) {
        if(!buildLocalPatchOrientationReference(
             face, originalPatch.elements, beforeOrientation))
          return false;
        beforeOrientationPointer = &beforeOrientation;
      }
      CadDistance::Contribution beforeCad, acceptedCad;
      {
        for(MElement *element : originalPatch.elements) {
          std::vector<UV> parameter;
          if(!CadDistance::elementParameters(face, element, parameter))
            return false;
          const auto value = ringGuard.sample(element, parameter);
          if(!value.complete()) return false;
          beforeCad += value;
        }
      }

      auto admissibleRingPatch = [&](const std::vector<UV> &uv,
                                      const std::vector<Point> &positions,
                                      CadDistance::Contribution &cad,
                                      double fraction) {
        auto reject = [&](const char *reason) {
          if(options.verbose > 1)
            Msg::Info("OptimizeQuadHoleRings face=%d rejected trial: %s",
                      face->tag(), reason);
          return false;
        };
        if(!holeRingPatchFollowsNormals(ringGuard, uv, positions,
             triangles, quadrangles, localVertices,
             existingQuadrangleCount, fraction)) return false;

        auto auditElement = [&](const auto &indices) {
          std::vector<MVertex> vertices;
          std::vector<MVertex *> pointers;
          std::vector<UV> parameter;
          vertices.reserve(indices.size());
          for(const std::size_t index : indices) {
            const Point &p = positions[index];
            // Explicit existing tag: temporary audit objects must not consume
            // global mesh tags or become classified mesh vertices.
            vertices.emplace_back(p[0], p[1], p[2], face, 1);
            pointers.push_back(&vertices.back());
            parameter.push_back(uv[index]);
          }
          std::unique_ptr<MElement> element;
          if(indices.size() == 3)
            element.reset(new MTriangle(pointers, 1));
          else
            element.reset(new MQuadrangle(pointers, 1));
          if(!evaluateElementQuality(element.get()).topologicallyValid)
            return reject("degenerate or invalid physical element");
          if(indices.size() == 4 && !ringGuard.admissibleQuad(
               *static_cast<MQuadrangle *>(element.get()), parameter))
            return reject("quad Jacobian or diagonal CAD guard");
          const auto value = ringGuard.sample(element.get(), parameter);
          if(!value.complete()) return reject("incomplete chord CAD coverage");
          cad += value;
          return true;
        };
        for(const auto &triangle : triangles)
          if(!auditElement(triangle)) return false;
        for(const auto &quadrangle : quadrangles)
          if(!auditElement(quadrangle)) return false;
        // A structural ring may contain thin or skewed elements. Report those
        // shape/size failures, while retaining physical validity and CAD fit.
        if(!ringGuard.admissible(beforeCad, cad)) {
          if(options.verbose > 1)
            Msg::Info("OptimizeQuadHoleRings face=%d CAD mean=%.6g->%.6g "
                      "max=%.6g->%.6g initialMean=%.6g initialMax=%.6g",
                      face->tag(), beforeCad.normalizedSquaredDistanceIntegral /
                        beforeCad.sampledArea,
                      cad.normalizedSquaredDistanceIntegral / cad.sampledArea,
                      beforeCad.maximumNormalizedDistance,
                      cad.maximumNormalizedDistance,
                      ringGuard.initialMean, ringGuard.initialMaximum);
          return reject("local or cumulative CAD-distance limit");
        }
        return true;
      };

      std::vector<Point> xyz;
      bool acceptedGeometry = false;
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
            continue;
          }
          if(!relaxed.success || !relaxed.untangled) {
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
          }
        if(valid && !candidateQuadranglesAreNonConcave(
             quadrangles, trialPoints, trialXyz))
          valid = false;
        if(valid && !indexedPatchPreservesSurfaceOrientation(
             face, beforeOrientationPointer, trialPoints, trialXyz,
             triangles, quadrangles))
          valid = false;
        if(!valid) {
          if(options.verbose > 1)
            Msg::Info("OptimizeQuadHoleRings face=%d fraction=%g rejected: "
                      "UV/physical orientation, convexity or mapping",
                      face->tag(), fraction);
          continue;
        }
        double minimumRadial = std::numeric_limits<double>::infinity();
        for(MVertex *oldVertex : loop) {
          const std::size_t old = localIndex[oldVertex];
          minimumRadial = std::min(
            minimumRadial,
            distance(trialXyz[old], trialXyz[duplicateIndex[oldVertex]]));
        }
        // The explicit structural pass permits thin rings. Its complete
        // physical-Jacobian guard supplies the numerical non-degeneracy test.
        if(!(minimumRadial > 0.) || !std::isfinite(minimumRadial)) {
          continue;
        }
        CadDistance::Contribution candidateCad;
        if(!admissibleRingPatch(trialPoints, trialXyz, candidateCad, fraction)) {
          continue;
        }
        acceptedCad = candidateCad;
        points = std::move(trialPoints);
        xyz = std::move(trialXyz);
        acceptedGeometry = true;
        break;
      }
      if(!acceptedGeometry) {
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
      for(MElement *element : topology.elements()) {
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

      GFaceMeshDiff diff;
      diff.gf = face;
      diff.before.gf = face;
      diff.before.elements = affected;
      diff.after.gf = face;
      diff.after.intVertices = created;
      diff.after.elements = replacement;
      FaceRewriteTransaction transaction(topology, diff);
      if(!transaction || !transaction.execute()) return false;
      std::vector<MVertex *> movedVertices;
      for(std::size_t i = 0; i < existingVertexCount; ++i) {
        if(fixed[i] || localVertices[i]->onWhat() != face) continue;
        localVertices[i]->setXYZ(xyz[i][0], xyz[i][1], xyz[i][2]);
        localVertices[i]->setParameter(0, points[i][0]);
        localVertices[i]->setParameter(1, points[i][1]);
        movedVertices.push_back(localVertices[i]);
      }
      topology.synchronizeGeometry(movedVertices);
      ringGuard.current = ringGuard.replaced(beforeCad, acceptedCad);
      insertedQuadrangles = loop.size();
      return true;
    }

    void pillowFaceHoles(GFace *face,
                         const SmallCavityOptimizerOptions &options,
                         QuadHoleRingResult &result,
                         CavityContext &topology,
                         HoleRingCadGuard &ringGuard)
    {
      if(!topology.manifold()) return;
      std::vector<BoundaryLoop> loops;
      if(!collectBoundaryLoops(topology, loops) || loops.size() < 2)
        return;
      // Classify each component from its domain-left orientation in the GFace
      // parameter plane: outer components have positive signed area, holes
      // negative signed area. Perimeter is not a topological classifier (a
      // hole can be longer than an outer component, and a face can have
      // several disconnected components).
      for(const BoundaryLoop &boundary : loops) {
        // A preceding accepted pillow changes the element adjacent to every
        // edge of that hole. Always derive orientation from the live
        // half-edge graph; retaining the initial edge map would leave stale
        // element pointers when a face contains several holes.
        std::map<Edge, std::vector<MElement *> > edgeElements;
        for(const auto &entry : topology.edges())
          edgeElements[entry.first] = entry.second;
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
        ++result.visited;
        std::size_t inserted = 0;
        bool alreadyPillowed = false;
        if(!tryPillowHole(face, hole, options.pillowNeighborLayers,
                          topology, options, inserted,
                          alreadyPillowed, ringGuard)) {
          if(alreadyPillowed) {
            ++result.alreadyPresent;
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
        ++result.accepted;
        result.insertedQuadrangles += inserted;
        if(options.verbose)
          Msg::Info("QuadOptimizer: inserted pillow on face %d: %zu quads",
                    face->tag(), inserted);
      }
    }


    // Delete only a free vertex outside the certified ring. All surviving
    // coordinates and all ring cells stay exact; the full retired-vertex star
    // is the transaction, including any neighbors outside the search rows.
    bool tryHoleRingTriangleCollapse(
      GFace *face, MVertex *removed, MVertex *retained,
      const std::set<MVertex *> &protectedVertices,
      CavityContext &topology, HoleRingCadGuard &cad,
      QuadHoleRingResult &result)
    {
      const auto &options = cad.options;
      auto reject = [&](const char *reason) {
        if(options.verbose > 1)
          Msg::Info("OptimizeQuadHoleRings face=%d collapse %zu->%zu "
                    "rejected: %s", face->tag(), removed->getNum(),
                    retained->getNum(), reason);
        return false;
      };
      if(removed->onWhat() != face || protectedVertices.count(removed))
        return reject("retired vertex belongs to a ring or fixed constraint");
      const auto edgeElements = topology.incidentElements(
        canonicalEdge(removed, retained));
      if(edgeElements.size() != 2 ||
         std::any_of(edgeElements.begin(), edgeElements.end(),
                     [](MElement *e) { return e->getNumPrimaryVertices() != 3; }))
        return false;
      const auto before = topology.incidentElements(removed);
      if(before.empty() || before.size() > 128 ||
         touchesBoundaryLayerElementData(face, before))
        return reject("unsupported or protected vertex star");

      GFaceMeshDiff diff;
      diff.gf = diff.before.gf = diff.after.gf = face;
      diff.before.elements = before;
      diff.before.intVertices = {removed};
      std::size_t removedTriangles = 0;
      CadDistance::Contribution beforeCad, afterCad;
      std::vector<MVertex *> vertices;
      std::unordered_map<MVertex *, std::size_t> index;
      std::vector<UV> uv;
      std::vector<Point> xyz;
      std::vector<std::array<std::size_t, 3>> triangles;
      Pattern quadrangles;
      auto signedArea = [](const std::vector<UV> &points) {
        double area = 0.;
        for(std::size_t i = 1; i + 1 < points.size(); ++i)
          area += (points[i][0] - points[0][0]) *
                    (points[i + 1][1] - points[0][1]) -
                  (points[i][1] - points[0][1]) *
                    (points[i + 1][0] - points[0][0]);
        return area;
      };
      for(MElement *element : before) {
        const std::size_t n = element->getNumPrimaryVertices();
        if(n != 3 && n != 4) return reject("unsupported element type");
        std::vector<UV> oldUv;
        if(!CadDistance::elementParameters(face, element, oldUv))
          return reject("unavailable original parameters");
        const auto originalCad = cad.sample(element, oldUv);
        if(!originalCad.complete())
          return reject("incomplete original CAD coverage");
        beforeCad += originalCad;
        std::vector<MVertex *> nodes;
        for(std::size_t i = 0; i < n; ++i) {
          MVertex *vertex = element->getVertex(static_cast<int>(i));
          nodes.push_back(vertex == removed ? retained : vertex);
        }
        const std::set<MVertex *> unique(nodes.begin(), nodes.end());
        if(unique.size() != n) {
          if(n != 3 || unique.size() != 2 ||
             std::find(edgeElements.begin(), edgeElements.end(), element) ==
               edgeElements.end())
            return reject("contraction would delete a quad or another cell");
          ++removedTriangles;
          continue;
        }
        std::array<std::size_t, 4> indices = {{0, 0, 0, 0}};
        std::vector<UV> parameters;
        for(std::size_t i = 0; i < n; ++i) {
          const auto added = index.emplace(nodes[i], vertices.size());
          indices[i] = added.first->second;
          if(added.second) {
            UV parameter;
            if(!vertexParameter(face, nodes[i], parameter))
              return reject("unavailable surviving parameters");
            vertices.push_back(nodes[i]);
            uv.push_back(parameter);
            xyz.push_back({nodes[i]->x(), nodes[i]->y(), nodes[i]->z()});
          }
          parameters.push_back(uv[indices[i]]);
        }
        const double oldArea = signedArea(oldUv), area = signedArea(parameters);
        if(!std::isfinite(oldArea) || !std::isfinite(area) || oldArea == 0. ||
           area == 0. || std::signbit(oldArea) != std::signbit(area))
          return reject("reversed or degenerate UV cell");
        MElement *replacement = n == 3 ?
          static_cast<MElement *>(new MTriangle(nodes)) :
          static_cast<MElement *>(new MQuadrangle(nodes));
        diff.after.elements.push_back(replacement);
        replacement->setPartition(element->getPartition());
        replacement->setVisibility(element->getVisibility());
        if(n == 3) triangles.push_back({indices[0], indices[1], indices[2]});
        else quadrangles.push_back(indices);
        if(!evaluateElementQuality(replacement).topologicallyValid)
          return reject("degenerate physical cell");
        if(n == 4 && !cad.admissibleQuad(
             *static_cast<MQuadrangle *>(replacement), parameters))
          return reject("quad Jacobian or diagonal CAD guard");
        const auto value = cad.sample(replacement, parameters);
        if(!value.complete()) return reject("incomplete candidate CAD coverage");
        afterCad += value;
      }
      if(removedTriangles != 2 || diff.after.elements.empty()) return false;
      if(!quadrangles.empty() &&
         !candidateQuadranglesAreNonConcave(quadrangles, uv, xyz))
        return reject("non-convex or folded candidate quad");
      if(!replacementElementsPreserveSurfaceOrientation(
           face, before, diff.after.elements, vertices, uv, xyz) ||
         !holeRingPatchFollowsNormals(cad, uv, xyz, triangles, quadrangles,
                                      vertices))
        return reject("incomplete or opposed physical-normal samples");
      if(!cad.admissible(beforeCad, afterCad))
        return reject("local or cumulative CAD-distance limit");
      FaceRewriteTransaction transaction(topology, diff);
      if(!transaction) return reject("cell-complex or ownership guard");
      const std::size_t removedTag = removed->getNum();
      const std::size_t retainedTag = retained->getNum();
      if(!transaction.execute()) return false;
      cad.current = cad.replaced(beforeCad, afterCad);
      // The parameter cache is keyed by MVertex pointers; do not keep a
      // retired pointer available for reuse by a later mesh operation.
      clearFaceGeometryCaches();
      ++result.acceptedCollapses;
      result.trianglesRemoved += removedTriangles;
      if(options.verbose)
        Msg::Info("OptimizeQuadHoleRings face=%d accepted collapse %zu->%zu: "
                  "%zu triangles removed, quad count and ring cells preserved",
                  face->tag(), removedTag, retainedTag, removedTriangles);
      return true;
    }

    void collapseTrianglesOutsideHoleRings(
      GFace *face, CavityContext &topology, HoleRingCadGuard &cad,
      QuadHoleRingResult &result)
    {
      std::vector<BoundaryLoop> loops;
      if(!collectBoundaryLoops(topology, loops)) return;
      std::map<Edge, std::vector<MElement *>> edgeElements;
      for(const auto &entry : topology.edges()) edgeElements[entry.first] = entry.second;
      std::set<MElement *> ringElements;
      std::set<MVertex *> protectedVertices = topology.protectedVertices(face);
      for(const BoundaryLoop &boundary : loops) {
        protectedVertices.insert(boundary.vertices.begin(), boundary.vertices.end());
        auto loop = boundary.vertices;
        std::unordered_map<MVertex *, UV> parameters;
        if(!orientLoopWithDomainOnLeft(face, loop, edgeElements, parameters)) continue;
        double area = 0.;
        for(std::size_t i = 0; i < loop.size(); ++i) {
          const auto &a = parameters.at(loop[i]);
          const auto &b = parameters.at(loop[(i + 1) % loop.size()]);
          area += a[0] * b[1] - a[1] * b[0];
        }
        if(!std::isfinite(area) || area >= -1.e-14 ||
           !hasCompletePillowLayer(loop, topology, edgeElements)) continue;
        for(std::size_t i = 0; i < loop.size(); ++i)
          ringElements.insert(edgeElements.at(
            canonicalEdge(loop[i], loop[(i + 1) % loop.size()])).front());
      }
      if(ringElements.empty()) return;
      for(MElement *element : ringElements)
        for(int i = 0; i < 4; ++i) protectedVertices.insert(element->getVertex(i));
      auto protectCurves = [&](const std::vector<GEdge *> &curves) {
        for(GEdge *curve : curves) if(curve)
          for(MLine *line : curve->lines) if(line)
            for(int i = 0; i < 2; ++i) protectedVertices.insert(line->getVertex(i));
      };
      protectCurves(face->edges());
      protectCurves(face->getEmbeddedEdges());
      for(GVertex *vertex : face->getEmbeddedVertices()) if(vertex)
        protectedVertices.insert(vertex->mesh_vertices.begin(), vertex->mesh_vertices.end());

      // Every accepted TT contraction removes exactly two triangles. Rebuild
      // the small search neighborhood after each commit; there is no pass cap
      // that could leave an admissible move for the next identical invocation.
      while(topology.manifold() && topology.elementCount(3) >= 2) {
        std::set<MElement *> selected = ringElements, frontier = ringElements;
        for(int layer = 0; layer < cad.options.pillowNeighborLayers; ++layer) {
          std::set<MElement *> next;
          for(MElement *element : frontier)
            for(MElement *neighbor : topology.neighbors(element))
              if(!selected.count(neighbor)) next.insert(neighbor);
          selected.insert(next.begin(), next.end());
          frontier = std::move(next);
          if(frontier.empty()) break;
        }
        std::set<Edge> candidateSet;
        for(MElement *element : selected) {
          if(element->getNumPrimaryVertices() != 3) continue;
          for(int i = 0; i < 3; ++i) {
            const Edge edge = canonicalEdge(element->getVertex(i),
                                            element->getVertex((i + 1) % 3));
            const auto adjacent = topology.incidentElements(edge);
            if(adjacent.size() == 2 &&
               adjacent[0]->getNumPrimaryVertices() == 3 &&
               adjacent[1]->getNumPrimaryVertices() == 3)
              candidateSet.insert(edge);
          }
        }
        std::vector<Edge> candidates(candidateSet.begin(), candidateSet.end());
        for(Edge &edge : candidates)
          if(canonicalVertexGeometryKey(edge.second) < canonicalVertexGeometryKey(edge.first))
            std::swap(edge.first, edge.second);
        std::sort(candidates.begin(), candidates.end(), [](const Edge &a, const Edge &b) {
          const auto a0 = canonicalVertexGeometryKey(a.first), b0 = canonicalVertexGeometryKey(b.first);
          if(a0 != b0) return a0 < b0;
          return canonicalVertexGeometryKey(a.second) < canonicalVertexGeometryKey(b.second);
        });
        bool accepted = false;
        for(const Edge &edge : candidates) {
          for(int direction = 0; direction < 2; ++direction) {
            ++result.collapseCandidates;
            if(tryHoleRingTriangleCollapse(face,
                 direction ? edge.second : edge.first,
                 direction ? edge.first : edge.second,
                 protectedVertices, topology, cad, result)) {
              accepted = true;
              break;
            }
          }
          if(accepted) break;
        }
        if(!accepted) break;
      }
    }

  } // namespace

  QuadHoleRingResult insertQuadHoleRings(
    GFace *face, const SmallCavityOptimizerOptions &options)
  {
    QuadHoleRingResult result;
    if(!face || options.pillowNeighborLayers < 0 || !validSizeOptions(options) ||
       !std::isfinite(options.maximumNormalizedCadRegression) ||
       options.maximumNormalizedCadRegression < 0. ||
       !std::isfinite(options.maximumCadDistanceIncreaseRatio) ||
       options.maximumCadDistanceIncreaseRatio < 0.) {
      result.success = false;
      return result;
    }
    if(options.pillowNeighborLayers == 0) return result;
    clearFaceGeometryCaches();
    const auto elements = surfaceElements(face);
    if(elements.empty()) return result;
    if(std::any_of(elements.begin(), elements.end(), [](MElement *element) {
         return !element || element->getNumVertices() !=
                              element->getNumPrimaryVertices();
       })) {
      result.skippedInvalidInputCellComplex = true;
      Msg::Warning("OptimizeQuadHoleRings: skipping face %d with non-linear "
                   "mesh elements", face->tag());
      return result;
    }
    if(!face->haveParametrization() ||
       !isRegularOrientedSurfaceCellComplex(face)) {
      result.skippedInvalidInputCellComplex = true;
      Msg::Warning("OptimizeQuadHoleRings: skipping face %d without a "
                   "regular parameterized surface cell complex", face->tag());
      return result;
    }
    CavityContext topology(face);
    std::vector<BoundaryLoop> loops;
    if(!collectBoundaryLoops(topology, loops) || loops.size() < 2)
      return result;
    HoleRingCadGuard cad(face, options, elements);
    pillowFaceHoles(face, options, result, topology, cad);
    collapseTrianglesOutsideHoleRings(face, topology, cad, result);
    result.physicalNormalQueries = cad.physicalNormalQueries;
    result.physicalNormalCovered = cad.physicalNormalCovered;
    result.rejected = result.visited - result.alreadyPresent - result.accepted;
    if((result.accepted || result.acceptedCollapses) &&
       options.invalidateVertexArrays)
      face->model()->deleteVertexArrays();
    return result;
  }

  bool isRegularOrientedSurfaceCellComplex(GFace *face)
  {
    if(!face) return false;
    const std::vector<MElement *> elements = surfaceElements(face);
    if(elements.empty()) return true;
    const SurfaceCellComplexValidity structure =
      validateSurfaceCellComplex(elements);
    return structure.structurallyRegular && structure.orientable &&
      FaceHalfEdge(face).valid();
  }

  bool isValidFinalQuadrangle(GFace *face, MQuadrangle *quadrangle,
                              const std::vector<SPoint2> *parameters)
  {
    if(!face || !quadrangle) return false;
    if(!evaluateElementQuality(quadrangle).topologicallyValid) return false;
    std::vector<Point> xyz(4);
    for(std::size_t i = 0; i < 4; ++i) {
      MVertex *vertex = quadrangle->getVertex(static_cast<int>(i));
      xyz[i] = {vertex->x(), vertex->y(), vertex->z()};
    }
    const Pattern singleQuadrangle = {{{0, 1, 2, 3}}};
    const double eta = quadrangle->etaShapeMeasure();
    const double sicn = quadrangle->minSICNShapeMeasure();
    return candidateQuadranglesArePhysicallyNonConcave(singleQuadrangle,
                                                       xyz) &&
           std::isfinite(sicn) && sicn > 0. && std::isfinite(eta) &&
           eta > 0. &&
           surfaceElementCadNormalSign(face, quadrangle, parameters) != -1;
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

      // The quality report is also run after a malformed input face has been
      // deliberately skipped by the optimizer. Do not feed null/repeated
      // vertices or invalid incidences to geometric evaluators: record the
      // complete face as invalid and continue auditing the other faces.
      const SurfaceCellComplexValidity readable =
        validateSurfaceCellComplex(elements);
      if(!readable.structurallyRegular) {
        const std::size_t triangles = face->triangles.size();
        const std::size_t quadrangles = face->quadrangles.size();
        ++summary.nonManifoldFaces;
        summary.triangles += triangles;
        summary.quadrangles += quadrangles;
        summary.invalidTriangles += triangles;
        summary.invalidQuadrangles += quadrangles;
        summary.badTriangles += triangles;
        summary.badQuadrangles += quadrangles;
        if(options.enforceSizeMap || options.auditSizeMap) {
          summary.sizeAudited = true;
          summary.sizeSpecificationsActive = options.enforceSizeMap;
          // The individual edges cannot be inspected safely. A sentinel per
          // unreadable face keeps the model-wide size verdict conservative.
          ++summary.invalidSizeEdges;
        }
        summary.cadAudited = true;
        summary.cadElementsRequested += triangles + quadrangles;
        summary.invalidCadElements += triangles + quadrangles;
        continue;
      }

      std::map<MElement *, std::vector<SPoint2> > parametersByElement;
      std::unordered_map<MVertex *, SPoint2> discreteParameterCache;
      if(face->geomType() == GEntity::DiscreteSurface)
        discreteParameterCache.reserve(2 * elements.size());
      for(MElement *element : elements)
        if(element)
          parametersByElement.emplace(
            element, auditElementParameters(
              face, element, discreteParameterCache));
      SupportingPlane supportingPlane;
      const SupportingPlane *supportingPlanePointer =
        auditedSupportingPlane(face, supportingPlane) ?
          &supportingPlane : nullptr;
      // Intrinsic validity catches folded cells independently of the CAD.
      // Also count a reliably sampled physical Jacobian opposed to the GFace
      // normal as invalid; an unevaluable normal remains an audit abstention.

      const CavityContext topology(face);
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
        const auto foundParameters = parametersByElement.find(triangle);
        const std::vector<SPoint2> noParameters;
        const std::vector<SPoint2> &parameters =
          foundParameters == parametersByElement.end() ?
            noParameters : foundParameters->second;
        const bool validTriangle = quality.topologicallyValid &&
          std::isfinite(sicn) && sicn > 0. &&
          surfaceElementCadNormalSign(
            face, triangle, &parameters) != -1;
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
        const double sicn = quadrangle->minSICNShapeMeasure();
        const bool validQuadrangle =
          isValidFinalQuadrangle(face, quadrangle, &parameters);
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
          summary.maximumSampledCadChordDistance = std::max(
            summary.maximumSampledCadChordDistance,
            geometry.maximumDistance);
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
      summary.rmsCadChordDistance = std::sqrt(
        cadSquaredDistanceIntegral / cadSampledArea);

    summary.passesShapeSpecifications =
      summary.nonManifoldFaces == 0 &&
      summary.invalidTriangles == 0 &&
      summary.invalidQuadrangles == 0 &&
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
