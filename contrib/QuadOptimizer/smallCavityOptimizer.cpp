// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.

#include "smallCavityOptimizer.h"
#include "quadGeometryGuard.h"

#include "BackgroundMeshTools.h"
#include "Field.h"
#include "GEdge.h"
#include "GFace.h"
#include "GPoint.h"
#include "GModel.h"
#include "GVertex.h"
#include "GmshMessage.h"
#include "halfEdgeMesh.h"
#include "halfEdgeRewriteCatalog.h"
#include "MElement.h"
#include "MLine.h"
#include "MQuadrangle.h"
#include "MTriangle.h"
#include "MVertex.h"
#include "meshGFaceOptimize.h"
#include "qmtDiskQuadrangulationRemeshing.h"
#include "qmtMeshUtils.h"
#include "discreteFace.h"

#include <algorithm>
#include <array>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <exception>
#include <limits>
#include <map>
#include <memory>
#include <mutex>
#include <numeric>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#if defined(_OPENMP)
#include <omp.h>
#endif

namespace QuadOptimizer {
  namespace {

    // Local-rewrite architecture
    // --------------------------
    //  1. HalfEdgeMesh::Mesh is the only persistent topology. Its records
    //     contain numeric ids and coordinates only.
    //  2. A catalog matcher builds one numeric core cavity C around a vertex,
    //     an internal edge, a vertex set or a single quadrangle.
    //  3. Before a candidate is judged, C is enlarged with the complete
    //     stars of its movable vertices to form the support C+C'. Mixed
    //     Winslow smoothing moves every unconstrained support vertex while
    //     the outer boundary of C+C' remains fixed.
    //  4. Quality, size, CAD distance and orientation are evaluated on that
    //     same smoothed support. Only an improving, non-inverted candidate is
    //     committed through one synchronized GFace/half-edge transaction.
    //
    // Gmsh pointers below are transient adapter handles. They never enter the
    // persistent half-edge connectivity defined in halfEdgeMesh.h.

    using UV = std::array<double, 2>;
    using Point = std::array<double, 3>;
    using Pattern = std::vector<std::array<std::size_t, 4> >;
    using ConnectivitySignature =
      std::vector<std::array<std::size_t, 4> >;
    using CavityStateSignature = std::vector<std::uint64_t>;
    using Edge = std::pair<MVertex *, MVertex *>;
    using QuadSwapTransition = std::pair<Edge, Edge>;

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

    // Orientation guards revisit identical interpolation samples throughout
    // the fixed-point catalog. The supporting GFace geometry is immutable
    // during one face transaction, so cache its exact (face, bitwise UV)
    // query without quantizing parameters or changing abstention semantics.
    // Each worker owns its cache and clears it before optimizing a new face.
    thread_local std::unordered_map<FaceNormalSampleCacheKey,
                                    FaceNormalSampleCacheEntry,
                                    FaceNormalSampleCacheKeyHash>
      faceNormalSampleCache;

    struct FaceProjectionDistanceCacheKey {
      GFace *face = nullptr;
      std::uint64_t u = 0;
      std::uint64_t v = 0;
      std::uint64_t x = 0;
      std::uint64_t y = 0;
      std::uint64_t z = 0;

      bool operator==(const FaceProjectionDistanceCacheKey &other) const
      {
        return face == other.face && u == other.u && v == other.v &&
          x == other.x && y == other.y && z == other.z;
      }
    };

    struct FaceProjectionDistanceCacheKeyHash {
      std::size_t operator()(
        const FaceProjectionDistanceCacheKey &key) const
      {
        std::size_t value = std::hash<GFace *>()(key.face);
        const auto combine = [&](std::uint64_t word) {
          value ^= std::hash<std::uint64_t>()(word) +
            0x9e3779b97f4a7c15ULL + (value << 6) + (value >> 2);
        };
        combine(key.u);
        combine(key.v);
        combine(key.x);
        combine(key.y);
        combine(key.z);
        return value;
      }
    };

    struct FaceProjectionDistanceCacheEntry {
      bool available = false;
      double distance = 0.;
    };

    // Exact repeated closest-point queries arise when several connectivities
    // are evaluated on the same C+C' support. The key contains every input
    // bit consumed by the query; no spatial tolerance or quantization can
    // merge geometrically distinct candidates.
    thread_local std::unordered_map<FaceProjectionDistanceCacheKey,
                                    FaceProjectionDistanceCacheEntry,
                                    FaceProjectionDistanceCacheKeyHash>
      faceProjectionDistanceCache;

    std::uint64_t exactDoubleBits(double value)
    {
      std::uint64_t bits = 0;
      static_assert(sizeof(bits) == sizeof(value),
                    "unexpected floating-point representation");
      std::memcpy(&bits, &value, sizeof(bits));
      return bits;
    }

    struct CavityStateSignatureHash {
      std::size_t operator()(const CavityStateSignature &signature) const
      {
        std::size_t hash = 0xcbf29ce484222325ULL;
        for(const std::uint64_t word : signature) {
          hash ^= static_cast<std::size_t>(word);
          hash *= 0x100000001b3ULL;
          hash ^= static_cast<std::size_t>(word >> 32);
        }
        return hash;
      }
    };

    using RejectedCavityStateSet = std::unordered_set<
      CavityStateSignature, CavityStateSignatureHash>;

    void clearInitialPackNormalAtlas();

    void clearFaceGeometryCaches()
    {
      persistentFaceParameterCache.clear();
      faceNormalSampleCache.clear();
      faceProjectionDistanceCache.clear();
      clearInitialPackNormalAtlas();
    }

    bool closestPointDistanceCached(GFace *face, const UV &parameter,
                                    const Point &meshPoint,
                                    double &sampleDistance)
    {
      sampleDistance = -1.;
      if(!face) return false;
      const FaceProjectionDistanceCacheKey key = {
        face, exactDoubleBits(parameter[0]), exactDoubleBits(parameter[1]),
        exactDoubleBits(meshPoint[0]), exactDoubleBits(meshPoint[1]),
        exactDoubleBits(meshPoint[2])};
      const auto cached = faceProjectionDistanceCache.find(key);
      if(cached != faceProjectionDistanceCache.end()) {
        sampleDistance = cached->second.distance;
        return cached->second.available;
      }

      const double initialGuess[2] = {parameter[0], parameter[1]};
      const GPoint geometry = face->closestPoint(
        SPoint3(meshPoint[0], meshPoint[1], meshPoint[2]), initialGuess);
      FaceProjectionDistanceCacheEntry entry;
      entry.available = geometry.succeeded() &&
        std::isfinite(geometry.x()) && std::isfinite(geometry.y()) &&
        std::isfinite(geometry.z());
      if(entry.available) {
        const double dx = meshPoint[0] - geometry.x();
        const double dy = meshPoint[1] - geometry.y();
        const double dz = meshPoint[2] - geometry.z();
        entry.distance = std::sqrt(dx * dx + dy * dy + dz * dz);
        entry.available = std::isfinite(entry.distance);
      }
      sampleDistance = entry.distance;
      faceProjectionDistanceCache.emplace(key, entry);
      return entry.available;
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

    struct InitialPackNormalCell {
      std::array<UV, 3> uv;
      UV minimumUv = {0., 0.};
      UV maximumUv = {0., 0.};
      Point minimumNormal = {0., 0., 0.};
      Point maximumNormal = {0., 0., 0.};
      double twiceUvArea = 0.;
      double uvScale2 = 0.;
    };

    // Immutable normal atlas captured immediately after PACK and before the
    // first optional rewrite. Each PACK triangle is one cell; each quad is a
    // four-lobe fan. A cell stores conservative component bounds over every
    // fine MAT normal whose UV box can meet that lobe. The compact atlas can
    // therefore prove clear normal signs without locating a MAT triangle.
    struct InitialPackNormalAtlas {
      GFace *face = nullptr;
      std::vector<InitialPackNormalCell> cells;
      std::vector<std::vector<std::size_t> > grid;
      std::size_t gridResolution = 0;
      UV minimumUv = {0., 0.};
      UV maximumUv = {0., 0.};
      mutable std::size_t queries = 0;
      mutable std::size_t certifiedPositive = 0;
      mutable std::size_t certifiedNegative = 0;
      mutable std::size_t fallbacks = 0;

      void clear()
      {
        face = nullptr;
        cells.clear();
        grid.clear();
        gridResolution = 0;
        minimumUv = {0., 0.};
        maximumUv = {0., 0.};
        queries = 0;
        certifiedPositive = 0;
        certifiedNegative = 0;
        fallbacks = 0;
      }
    };

    thread_local InitialPackNormalAtlas initialPackNormalAtlas;

    void clearInitialPackNormalAtlas()
    {
      initialPackNormalAtlas.clear();
    }

    bool buildInitialPackNormalAtlas(
      GFace *face, const std::vector<MElement *> &elements)
    {
      initialPackNormalAtlas.clear();
      discreteFace *discrete = dynamic_cast<discreteFace *>(face);
      if(!discrete || elements.empty()) return false;

      auto appendCell = [&](const std::array<UV, 3> &uv) {
        InitialPackNormalCell cell;
        cell.uv = uv;
        cell.twiceUvArea = localOrientationCross2(uv[0], uv[1], uv[2]);
        cell.uvScale2 = std::max(
          {localOrientationDistance2(uv[0], uv[1]),
           localOrientationDistance2(uv[1], uv[2]),
           localOrientationDistance2(uv[2], uv[0])});
        if(!std::isfinite(cell.twiceUvArea) ||
           !std::isfinite(cell.uvScale2) || !(cell.uvScale2 > 0.) ||
           std::abs(cell.twiceUvArea) <= 1.e-12 * cell.uvScale2)
          return;
        for(std::size_t coordinate = 0; coordinate < 2; ++coordinate) {
          cell.minimumUv[coordinate] = std::min(
            {uv[0][coordinate], uv[1][coordinate], uv[2][coordinate]});
          cell.maximumUv[coordinate] = std::max(
            {uv[0][coordinate], uv[1][coordinate], uv[2][coordinate]});
        }
        SVector3 minimumNormal, maximumNormal;
        if(!discrete->normalBoundsForParametricTriangle(
             SPoint2(uv[0][0], uv[0][1]),
             SPoint2(uv[1][0], uv[1][1]),
             SPoint2(uv[2][0], uv[2][1]),
             minimumNormal, maximumNormal))
          return;
        cell.minimumNormal = {
          minimumNormal.x(), minimumNormal.y(), minimumNormal.z()};
        cell.maximumNormal = {
          maximumNormal.x(), maximumNormal.y(), maximumNormal.z()};
        initialPackNormalAtlas.cells.push_back(cell);
      };

      for(MElement *element : elements) {
        if(!element) continue;
        const std::size_t count = element->getNumPrimaryVertices();
        if(count != 3 && count != 4) continue;
        std::array<UV, 4> uv = {};
        bool valid = true;
        for(std::size_t i = 0; i < count; ++i) {
          MVertex *vertex = element->getVertex(static_cast<int>(i));
          SPoint2 parameter;
          if(!vertex || !persistentFaceParameter(face, vertex, parameter)) {
            valid = false;
            break;
          }
          uv[i] = {parameter.x(), parameter.y()};
        }
        if(!valid) continue;
        if(count == 3) {
          appendCell({uv[0], uv[1], uv[2]});
        }
        else {
          UV center = {0., 0.};
          for(std::size_t i = 0; i < 4; ++i) {
            center[0] += .25 * uv[i][0];
            center[1] += .25 * uv[i][1];
          }
          for(std::size_t i = 0; i < 4; ++i)
            appendCell({uv[i], uv[(i + 1) % 4], center});
        }
      }
      if(initialPackNormalAtlas.cells.empty()) return false;

      InitialPackNormalAtlas &atlas = initialPackNormalAtlas;
      atlas.face = face;
      atlas.minimumUv = {
        std::numeric_limits<double>::max(),
        std::numeric_limits<double>::max()};
      atlas.maximumUv = {
        -std::numeric_limits<double>::max(),
        -std::numeric_limits<double>::max()};
      for(const InitialPackNormalCell &cell : atlas.cells)
        for(std::size_t coordinate = 0; coordinate < 2; ++coordinate) {
          atlas.minimumUv[coordinate] = std::min(
            atlas.minimumUv[coordinate], cell.minimumUv[coordinate]);
          atlas.maximumUv[coordinate] = std::max(
            atlas.maximumUv[coordinate], cell.maximumUv[coordinate]);
        }
      if(!(atlas.maximumUv[0] > atlas.minimumUv[0]) ||
         !(atlas.maximumUv[1] > atlas.minimumUv[1])) {
        atlas.clear();
        return false;
      }
      atlas.gridResolution = std::max<std::size_t>(
        8, std::min<std::size_t>(
          128, static_cast<std::size_t>(std::ceil(
            2. * std::sqrt(static_cast<double>(atlas.cells.size()))))));
      atlas.grid.assign(
        atlas.gridResolution * atlas.gridResolution,
        std::vector<std::size_t>());
      const auto gridCoordinate = [&](double value, std::size_t coordinate) {
        const double normalized =
          (value - atlas.minimumUv[coordinate]) /
          (atlas.maximumUv[coordinate] - atlas.minimumUv[coordinate]);
        if(normalized <= 0.) return std::size_t(0);
        if(normalized >= 1.) return atlas.gridResolution - 1;
        return std::min(
          atlas.gridResolution - 1,
          static_cast<std::size_t>(normalized * atlas.gridResolution));
      };
      for(std::size_t position = 0; position < atlas.cells.size();
          ++position) {
        const InitialPackNormalCell &cell = atlas.cells[position];
        const std::size_t firstU = gridCoordinate(cell.minimumUv[0], 0);
        const std::size_t lastU = gridCoordinate(cell.maximumUv[0], 0);
        const std::size_t firstV = gridCoordinate(cell.minimumUv[1], 1);
        const std::size_t lastV = gridCoordinate(cell.maximumUv[1], 1);
        for(std::size_t v = firstV; v <= lastV; ++v)
          for(std::size_t u = firstU; u <= lastU; ++u)
            atlas.grid[v * atlas.gridResolution + u].push_back(position);
      }
      return true;
    }

    bool initialPackNormalBounds(
      GFace *face, const UV &parameter,
      Point &minimumNormal, Point &maximumNormal)
    {
      InitialPackNormalAtlas &atlas = initialPackNormalAtlas;
      if(atlas.face != face || !atlas.gridResolution || atlas.grid.empty() ||
         !std::isfinite(parameter[0]) || !std::isfinite(parameter[1]) ||
         parameter[0] < atlas.minimumUv[0] ||
         parameter[0] > atlas.maximumUv[0] ||
         parameter[1] < atlas.minimumUv[1] ||
         parameter[1] > atlas.maximumUv[1])
        return false;
      ++atlas.queries;

      const auto gridCoordinate = [&](double value, std::size_t coordinate) {
        const double normalized =
          (value - atlas.minimumUv[coordinate]) /
          (atlas.maximumUv[coordinate] - atlas.minimumUv[coordinate]);
        if(normalized <= 0.) return std::size_t(0);
        if(normalized >= 1.) return atlas.gridResolution - 1;
        return std::min(
          atlas.gridResolution - 1,
          static_cast<std::size_t>(normalized * atlas.gridResolution));
      };
      const std::size_t u = gridCoordinate(parameter[0], 0);
      const std::size_t v = gridCoordinate(parameter[1], 1);
      const std::vector<std::size_t> &candidates =
        atlas.grid[v * atlas.gridResolution + u];

      minimumNormal = {
        std::numeric_limits<double>::max(),
        std::numeric_limits<double>::max(),
        std::numeric_limits<double>::max()};
      maximumNormal = {
        -std::numeric_limits<double>::max(),
        -std::numeric_limits<double>::max(),
        -std::numeric_limits<double>::max()};
      bool covered = false;
      for(const std::size_t position : candidates) {
        if(position >= atlas.cells.size()) continue;
        const InitialPackNormalCell &cell = atlas.cells[position];
        const double orientation = cell.twiceUvArea > 0. ? 1. : -1.;
        // Only certify points strictly inside an original PACK lobe. Its
        // edges and any uncovered/overlapping regions retain the exact MAT
        // query, preserving seam and abstention behaviour.
        const double margin = 1.e-10 * cell.uvScale2;
        bool inside = true;
        for(std::size_t edge = 0; edge < 3; ++edge)
          if(orientation * localOrientationCross2(
               cell.uv[edge], cell.uv[(edge + 1) % 3], parameter) <=
             margin) {
            inside = false;
            break;
          }
        if(!inside) continue;
        covered = true;
        for(std::size_t component = 0; component < 3; ++component) {
          minimumNormal[component] = std::min(
            minimumNormal[component], cell.minimumNormal[component]);
          maximumNormal[component] = std::max(
            maximumNormal[component], cell.maximumNormal[component]);
        }
      }
      if(!covered) {
        ++atlas.fallbacks;
        return false;
      }

      return true;
    }

    bool initialPackNormalBoundsSign(
      const Point &minimumNormal, const Point &maximumNormal,
      const Point &jacobian, double jacobianNorm, int &sign)
    {
      sign = 0;
      if(!std::isfinite(jacobianNorm) || !(jacobianNorm > 0.))
        return false;
      double lower = 0.;
      double upper = 0.;
      for(std::size_t component = 0; component < 3; ++component) {
        if(jacobian[component] >= 0.) {
          lower += jacobian[component] * minimumNormal[component];
          upper += jacobian[component] * maximumNormal[component];
        }
        else {
          lower += jacobian[component] * maximumNormal[component];
          upper += jacobian[component] * minimumNormal[component];
        }
      }
      // A deliberately wider interval than the exact 1e-10 predicate absorbs
      // floating-point interval rounding and never guesses near a fold.
      const double certainty = 1.e-8 * jacobianNorm;
      if(std::isfinite(lower) && lower > certainty) {
        sign = 1;
        ++initialPackNormalAtlas.certifiedPositive;
        return true;
      }
      if(std::isfinite(upper) && upper < -certainty) {
        sign = -1;
        ++initialPackNormalAtlas.certifiedNegative;
        return true;
      }
      ++initialPackNormalAtlas.fallbacks;
      return false;
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
      Point minimumNormal, maximumNormal;
      int packSign = 0;
      if(initialPackNormalBounds(
           face, parameter, minimumNormal, maximumNormal) &&
         initialPackNormalBoundsSign(
           minimumNormal, maximumNormal, jacobian,
           jacobianNorm, packSign))
        return packSign;
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
        // patchFromElements gives the boundary the orientation of the
        // existing surface component. Canonicalize its starting vertex, but
        // never reflect it: a reflection used to erase precisely the CAD-side
        // invariant that every replacement must preserve.
        for(std::size_t rotation = 0; rotation < loop.size(); ++rotation) {
          std::vector<MVertex *> candidate(loop.size());
          for(std::size_t i = 0; i < loop.size(); ++i)
            candidate[i] = loop[(rotation + i) % loop.size()];
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

    enum class CavityPurpose {
      Node,
      Edge,
      Triangle,
      Quadrangle,
      CleanUpConnectivity,
      CleanUpBoundary,
      CleanUpShape,
      CleanUpSize
    };

    using HalfEdgeRewriteDescriptor = HalfEdgeRewrite::Descriptor;
    using HalfEdgeRewriteFamily = HalfEdgeRewrite::Family;
    using HalfEdgeRewriteKind = HalfEdgeRewrite::Kind;
    using HalfEdgeRewriteSchedule = HalfEdgeRewrite::Schedule;
    using HalfEdgeRewriteSymmetry = HalfEdgeRewrite::Symmetry;

    // One ordered registry is the source of truth for every local topology
    // rewrite. Every matcher and transaction consumes this exact table.
    const std::array<HalfEdgeRewriteDescriptor, 25> &
    halfEdgeRewriteCatalog()
    {
      return HalfEdgeRewrite::catalog();
    }

    struct ValenceObjective {
      std::size_t severeCount = 0;
      std::size_t irregularCount = 0;
      double penalty = 0.;
    };

    struct CavitySeed {
      // Stable numeric identity of the rewrite core C in the persistent
      // half-edge mesh. The Gmsh patch below is only its short-lived adapter
      // view for parametrization, quality evaluation and ownership changes.
      // For every collected seed, coreFaces == faces.
      HalfEdgeMesh::Cavity halfEdgeCavity;
      GFaceMeshPatch patch;
      std::size_t interiorVertexCount = 0;
      bool alwaysTryTopology = false;
      CavityPurpose kind = CavityPurpose::Node;
      SpecificationObjective objective;
      ValenceObjective valence;
      bool flexibleInteriorCount = false;
      // The unchanged patch contains a reliable physical Jacobian opposed to
      // the GFace. Such a seed may use the GFace normal as a corrective
      // oracle instead of preserving the input patch's wrong local side.
      bool correctiveCadOrientation = false;
      // Cached from the face half-edge topology when the cavity is built.
      // Candidate ranking is deliberately independent of a subsequent scan
      // over every element of the GFace.
      std::vector<std::size_t> boundaryOutsideQuadDegree;
      std::vector<std::size_t> boundaryIdealQuadDegree;
      bool attemptStateCacheable = false;
      CavityStateSignature attemptState;
    };

    using CavityAttemptStateBuilder = std::function<bool(
      const CavitySeed &, CavityStateSignature &)>;
    using CavityCoreAttemptStateBuilder = std::function<bool(
      const HalfEdgeMesh::Cavity &, CavityPurpose,
      CavityStateSignature &)>;

    struct DiamondSeed {
      CavitySeed cavity;
      MQuadrangle *diamond = nullptr;
      std::size_t retainedInterior = 0;
      std::size_t removedInterior = 0;
      bool boundaryDiamond = false;
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
      // Every accepted topology rewrite is judged on the exact support that
      // was smoothed: C together with its vertex-star extension C'. Keep the
      // matching reference terms next to the candidate so no later decision
      // accidentally compares C+C' with the smaller seed C.
      SpecificationObjective referenceObjective;
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
      SizeScore referenceSize;
      std::size_t referenceInvalidElementCount =
        std::numeric_limits<std::size_t>::max();
      ValenceObjective valence;
      // For retained-vertex rewrites (QQ, QT, TT, strips, diamonds), these
      // coordinates are the result of the transactional C+C' Winslow solve.
      // They are applied only after the topology transaction succeeds.
      std::vector<VertexGeometry> smoothedVertices;
      bool hasEdgeSwapCad = false;
      double edgeSwapCadDistance = 0.;
      double referenceEdgeSwapCadDistance = 0.;
      double edgeSwapCadScale = 1.;
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

    struct SurfaceOrientationRepairResult {
      bool structurallyRegular = true;
      bool orientable = true;
      std::size_t reorientedElements = 0;
    };

    // Validate the orientation-independent part of the surface cell complex,
    // then solve the element-orientation constraints on the dual graph. No
    // element is touched until all components have been proved orientable.
    // Among the two solutions of each component, retain the one whose physical
    // normals follow a reliable CAD normal. When no normal can be evaluated,
    // retain the solution requiring the fewest reversals and let local cavity
    // references preserve that chosen side.
    SurfaceOrientationRepairResult repairSurfaceElementOrientation(
      GFace *face, const std::vector<MElement *> &elements,
      bool allowConsistentTwoQuadChains = false,
      bool applyRepair = true)
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

      SurfaceOrientationRepairResult result;
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
      struct SharedEdge {
        Edge edge = {nullptr, nullptr};
        Incidence first;
        Incidence second;
      };
      std::map<std::pair<std::size_t, std::size_t>,
               std::vector<SharedEdge> > sharedEdges;
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
        sharedEdges[{a, b}].push_back(
          {entry.first, first, second});
        const bool sameDirection =
          first.origin == second.origin &&
          first.destination == second.destination;
        constraints[first.element].push_back(
          {second.element, sameDirection});
        constraints[second.element].push_back(
          {first.element, sameDirection});
      }

      for(const auto &entry : sharedEdges) {
        if(entry.second.size() <= 1) continue;
        if(!allowConsistentTwoQuadChains || entry.second.size() != 2) {
          result.structurallyRegular = false;
          return result;
        }
        MElement *firstElement = elements[entry.first.first];
        MElement *secondElement = elements[entry.first.second];
        if(firstElement->getNumPrimaryVertices() != 4 ||
           secondElement->getNumPrimaryVertices() != 4) {
          // In particular, never turn a triangle wrapped in a quadrangle
          // into an apparently regular triangulation by splitting the quad.
          result.structurallyRegular = false;
          return result;
        }
        const Edge &firstEdge = entry.second[0].edge;
        const Edge &secondEdge = entry.second[1].edge;
        const std::size_t commonVertices =
          static_cast<std::size_t>(firstEdge.first == secondEdge.first) +
          static_cast<std::size_t>(firstEdge.first == secondEdge.second) +
          static_cast<std::size_t>(firstEdge.second == secondEdge.first) +
          static_cast<std::size_t>(firstEdge.second == secondEdge.second);
        if(commonVertices != 1) {
          result.structurallyRegular = false;
          return result;
        }

        const bool firstSameDirection =
          entry.second[0].first.origin == entry.second[0].second.origin &&
          entry.second[0].first.destination ==
            entry.second[0].second.destination;
        const bool secondSameDirection =
          entry.second[1].first.origin == entry.second[1].second.origin &&
          entry.second[1].first.destination ==
            entry.second[1].second.destination;
        if(firstSameDirection != secondSameDirection) {
          result.structurallyRegular = false;
          return result;
        }

        // Incidence alone cannot distinguish Blossom's legitimate
        // opposite-side chain from two overlapping quads. Prove in the face
        // chart that the two private corners lie strictly on opposite sides
        // of both shared segments. This test is independent of either quad's
        // current ordering, so a consistently reversed quad remains
        // repairable by the XOR pass below.
        MVertex *middle = nullptr;
        for(MVertex *candidate : {firstEdge.first, firstEdge.second})
          if(candidate == secondEdge.first ||
             candidate == secondEdge.second) {
            middle = candidate;
            break;
          }
        if(!face || !middle) {
          result.structurallyRegular = false;
          return result;
        }
        MVertex *firstEnd = firstEdge.first == middle ?
          firstEdge.second : firstEdge.first;
        MVertex *secondEnd = secondEdge.first == middle ?
          secondEdge.second : secondEdge.first;
        const std::set<MVertex *> chain = {firstEnd, middle, secondEnd};
        auto privateCorner = [&](MElement *element) -> MVertex * {
          MVertex *corner = nullptr;
          for(int i = 0; i < 4; ++i) {
            MVertex *vertex = element->getVertex(i);
            if(chain.find(vertex) != chain.end()) continue;
            if(corner) return nullptr;
            corner = vertex;
          }
          return corner;
        };
        MVertex *firstPrivate = privateCorner(firstElement);
        MVertex *secondPrivate = privateCorner(secondElement);
        if(!firstPrivate || !secondPrivate) {
          result.structurallyRegular = false;
          return result;
        }
        std::array<MVertex *, 5> vertices = {
          firstEnd, middle, secondEnd, firstPrivate, secondPrivate};
        std::array<SPoint2, 5> parameters;
        auto chainParameter = [&](MVertex *vertex, SPoint2 &parameter) {
          if(face->geomType() == GEntity::DiscreteSurface)
            return persistentFaceParameter(face, vertex, parameter);
          return reparamMeshVertexOnFace(
                   vertex, face, parameter, true, false) &&
            std::isfinite(parameter.x()) &&
            std::isfinite(parameter.y());
        };
        bool parametrized = true;
        for(std::size_t i = 0; i < vertices.size(); ++i)
          if(!chainParameter(vertices[i], parameters[i])) {
            parametrized = false;
            break;
          }
        if(!parametrized) {
          result.structurallyRegular = false;
          return result;
        }
        for(int direction = 0; direction < 2; ++direction) {
          if(!face->periodic(direction)) continue;
          const double period = std::abs(face->period(direction));
          if(!std::isfinite(period) || !(period > 0.)) {
            result.structurallyRegular = false;
            return result;
          }
          const double reference = parameters[1][direction];
          for(SPoint2 &parameter : parameters)
            parameter[direction] +=
              std::round((reference - parameter[direction]) / period) *
              period;
        }
        auto orientation2d = [](const SPoint2 &a, const SPoint2 &b,
                                const SPoint2 &c) {
          return (b.x() - a.x()) * (c.y() - a.y()) -
                 (b.y() - a.y()) * (c.x() - a.x());
        };
        double scale2 = 0.;
        for(std::size_t i = 0; i < parameters.size(); ++i)
          for(std::size_t j = i + 1; j < parameters.size(); ++j)
            scale2 = std::max(
              scale2,
              std::pow(parameters[i].x() - parameters[j].x(), 2) +
                std::pow(parameters[i].y() - parameters[j].y(), 2));
        const double tolerance = 1.e-12 *
          std::max(scale2, std::numeric_limits<double>::min());
        const double firstSideA = orientation2d(
          parameters[0], parameters[1], parameters[3]);
        const double firstSideB = orientation2d(
          parameters[0], parameters[1], parameters[4]);
        const double secondSideA = orientation2d(
          parameters[1], parameters[2], parameters[3]);
        const double secondSideB = orientation2d(
          parameters[1], parameters[2], parameters[4]);
        if(!std::isfinite(firstSideA) || !std::isfinite(firstSideB) ||
           !std::isfinite(secondSideA) || !std::isfinite(secondSideB) ||
           std::abs(firstSideA) <= tolerance ||
           std::abs(firstSideB) <= tolerance ||
           std::abs(secondSideA) <= tolerance ||
           std::abs(secondSideB) <= tolerance ||
           (firstSideA > 0.) == (firstSideB > 0.) ||
           (secondSideA > 0.) == (secondSideB > 0.)) {
          result.structurallyRegular = false;
          return result;
        }
      }

      std::map<MElement *, bool> flip;
      std::vector<MElement *> elementsToReverse;
      for(MElement *root : elements) {
        if(flip.find(root) != flip.end()) continue;
        std::queue<MElement *> pending;
        std::vector<MElement *> component;
        flip[root] = false;
        pending.push(root);
        std::size_t flipped = 0;
        while(!pending.empty()) {
          MElement *element = pending.front();
          pending.pop();
          component.push_back(element);
          if(flip[element]) ++flipped;
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
        std::ptrdiff_t cadOrientationVote = 0;
        std::size_t cadOrientationSamples = 0;
        // Resolve the two coherent half-edge orientations with a robust
        // element/CAD vote. Discrete faces use the multi-point physical
        // Jacobian guard; mixed or unevaluable elements abstain.
        if(face)
          for(MElement *element : component) {
            const int currentSign = surfaceElementCadNormalSign(face, element);
            if(!currentSign) continue;
            ++cadOrientationSamples;
            cadOrientationVote += flip[element] ? -currentSign : currentSign;
          }
        const bool complement = cadOrientationSamples ?
          cadOrientationVote < 0 :
          flipped > component.size() - flipped;
        for(MElement *element : component)
          if(flip[element] != complement)
            elementsToReverse.push_back(element);
      }

      if(applyRepair)
        for(MElement *element : elementsToReverse) element->reverse();
      result.reorientedElements = elementsToReverse.size();
      return result;
    }

    // Gmsh adapter for the persistent numeric half-edge mesh of one GFace.
    // HalfEdgeMesh::Mesh is the sole topological state during optimization:
    // it contains only integer identifiers and doubles, uses stable append-only
    // identifiers, and is updated locally after every accepted rewrite. Gmsh
    // pointers are kept exclusively in these translation tables and views.
    class FaceHalfEdgeTopology {
      using Index = HalfEdgeMesh::Index;

      // The persistent mesh is a pointer-free integer/double structure.
      // Gmsh handles live only in this adapter and never participate in the
      // half-edge connectivity.
      mutable HalfEdgeMesh::Mesh _mesh;
      std::vector<MVertex *> _verticesByIndex;
      std::unordered_map<MVertex *, Index> _vertexIndices;
      // Monotone local generations make an unchanged C+C' state cheap to
      // recognize. A topology transaction touches only vertices incident to
      // removed/inserted faces; a geometry transaction touches only vertices
      // whose XYZ bits actually changed. Distant edits consequently leave a
      // rejected cavity's certificate valid.
      mutable std::vector<std::uint64_t> _vertexStateRevisions;
      mutable std::uint64_t _stateRevision = 0;
      std::vector<MElement *> _elementsByIndex;
      std::unordered_map<MElement *, Index> _elementIndices;
      Index _revision = 0;
      mutable bool _elementsViewDirty = true;
      mutable bool _verticesViewDirty = true;
      mutable bool _edgesViewDirty = true;
      mutable std::vector<MElement *> _elementsView;
      mutable std::vector<MVertex *> _verticesView;
      mutable std::vector<std::pair<Edge, std::vector<MElement *> > >
        _edgesView;
      // Local adjacency and degree queries dominate the overlapping disk
      // collectors. Their answers remain exact until an accepted topology
      // transaction; only their canonical order also depends on geometry.
      mutable std::unordered_map<MVertex *, std::vector<MElement *> >
        _incidentElementsViews;
      mutable std::map<Edge, std::vector<MElement *> >
        _edgeIncidentElementsViews;
      mutable std::unordered_map<MElement *, std::vector<MElement *> >
        _neighborViews;
      mutable std::unordered_map<MVertex *, std::size_t> _quadDegreeViews;
      mutable std::unordered_map<MVertex *, bool> _boundaryVertexViews;
      // Boundary-layer protection is immutable during one face optimizer
      // transaction. Computing it once avoids a full mesh-vertex and column
      // scan for every C+C' connectivity candidate.
      mutable GFace *_protectedVertexFace = nullptr;
      mutable std::set<MVertex *> _protectedVertexView;
      // Set only while one catalog callback is running. Candidate discovery
      // remains free to build intermediate disks; the callback explicitly
      // submits its final core C to this contract before attempting a rewrite.
      mutable HalfEdgeRewrite::AnchorContract _catalogAnchorContract;
      bool _synchronized = true;

      using DirectedIndexEdge = std::pair<Index, Index>;

      static bool directedBoundary(
        const std::vector<std::vector<Index> > &faces,
        std::vector<DirectedIndexEdge> &boundary)
      {
        std::map<HalfEdgeMesh::Edge, std::vector<DirectedIndexEdge> > edges;
        for(const std::vector<Index> &vertices : faces) {
          if(vertices.size() != 3 && vertices.size() != 4) return false;
          for(std::size_t i = 0; i < vertices.size(); ++i) {
            const Index first = vertices[i];
            const Index second = vertices[(i + 1) % vertices.size()];
            edges[HalfEdgeMesh::canonicalEdge(first, second)].push_back(
              {first, second});
          }
        }
        boundary.clear();
        for(const auto &entry : edges) {
          if(entry.second.size() == 1) {
            boundary.push_back(entry.second.front());
          }
          else if(entry.second.size() == 2) {
            if(entry.second[0].first != entry.second[1].second ||
               entry.second[0].second != entry.second[1].first)
              return false;
          }
          else {
            return false;
          }
        }
        std::sort(boundary.begin(), boundary.end());
        return true;
      }

      static bool sameDirectedBoundary(
        const std::vector<std::vector<Index> > &before,
        const std::vector<std::vector<Index> > &after)
      {
        std::vector<DirectedIndexEdge> beforeBoundary, afterBoundary;
        return directedBoundary(before, beforeBoundary) &&
               directedBoundary(after, afterBoundary) &&
               beforeBoundary == afterBoundary;
      }

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
        _verticesViewDirty = true;
        _edgesViewDirty = true;
        _incidentElementsViews.clear();
        _edgeIncidentElementsViews.clear();
        _neighborViews.clear();
        _quadDegreeViews.clear();
        _boundaryVertexViews.clear();
      }

      Index findVertex(MVertex *vertex) const
      {
        const auto found = _vertexIndices.find(vertex);
        return found == _vertexIndices.end() ?
          HalfEdgeMesh::invalid : found->second;
      }

      void touchVertexState(Index index) const
      {
        if(index < 0 ||
           static_cast<std::size_t>(index) >=
             _vertexStateRevisions.size())
          return;
        _vertexStateRevisions[static_cast<std::size_t>(index)] =
          ++_stateRevision;
      }

      Index addVertex(MVertex *vertex)
      {
        if(!vertex) return HalfEdgeMesh::invalid;
        const Index existing = findVertex(vertex);
        if(existing != HalfEdgeMesh::invalid) return existing;
        const Index index = _mesh.addVertex(
          {{vertex->x(), vertex->y(), vertex->z()}});
        if(index == HalfEdgeMesh::invalid) return index;
        if(static_cast<std::size_t>(index) != _verticesByIndex.size())
          return HalfEdgeMesh::invalid;
        _verticesByIndex.push_back(vertex);
        _vertexStateRevisions.push_back(0);
        _vertexIndices.emplace(vertex, index);
        return index;
      }

      Index findElement(MElement *element) const
      {
        const auto found = _elementIndices.find(element);
        return found == _elementIndices.end() ?
          HalfEdgeMesh::invalid : found->second;
      }

      MVertex *vertex(Index index) const
      {
        return index >= 0 &&
            static_cast<std::size_t>(index) < _verticesByIndex.size() ?
          _verticesByIndex[static_cast<std::size_t>(index)] : nullptr;
      }

      MElement *element(Index index) const
      {
        return index >= 0 &&
            static_cast<std::size_t>(index) < _elementsByIndex.size() ?
          _elementsByIndex[static_cast<std::size_t>(index)] : nullptr;
      }

    public:
      // A prepared edit is the compact bridge between Gmsh ownership and the
      // numeric half-edge mesh. It snapshots only stable integer face/vertex
      // identifiers, candidate connectivities and adapter iterators. In
      // particular, committing it never dereferences an element deleted by
      // GFaceMeshDiff.
      class PreparedReplacement {
        friend class FaceHalfEdgeTopology;
        using ElementIterator =
          std::unordered_map<MElement *, Index>::const_iterator;
        using VertexIterator =
          std::unordered_map<MVertex *, Index>::const_iterator;

        const FaceHalfEdgeTopology *_owner = nullptr;
        Index _revision = HalfEdgeMesh::invalid;
        std::size_t _vertexStorageSize = 0;
        std::size_t _faceStorageSize = 0;
        std::vector<Index> _removedFaces;
        std::vector<MElement *> _removedElements;
        std::vector<ElementIterator> _removedElementMappings;
        std::vector<std::vector<Index> > _insertedFaces;
        std::vector<MElement *> _insertedElements;
        std::vector<MVertex *> _newVertices;
        std::vector<std::array<double, 3> > _newVertexPositions;
        std::vector<std::pair<Index, VertexIterator> >
          _touchedExistingVertices;
        std::vector<MVertex *> _retiredVertices;
        bool _valid = false;

      public:
        explicit operator bool() const { return _valid; }
      };

      FaceHalfEdgeTopology() = default;

      FaceHalfEdgeTopology(const FaceHalfEdgeTopology &) = delete;
      FaceHalfEdgeTopology &operator=(const FaceHalfEdgeTopology &) = delete;
      FaceHalfEdgeTopology(FaceHalfEdgeTopology &&) = delete;
      FaceHalfEdgeTopology &operator=(FaceHalfEdgeTopology &&) = delete;

      explicit FaceHalfEdgeTopology(const std::vector<MElement *> &elements)
      {
        for(MElement *element : elements)
          if(!addElement(element)) {
            _synchronized = false;
            break;
          }
      }

      bool manifold() const
      {
        return _synchronized && _mesh.manifold();
      }

      const std::set<MVertex *> &protectedVertices(GFace *face) const
      {
        if(_protectedVertexFace != face) {
          _protectedVertexView = protectedFaceVertices(face);
          _protectedVertexFace = face;
        }
        return _protectedVertexView;
      }

      bool beginCatalogRewrite(
        const HalfEdgeRewrite::Descriptor &descriptor)
      {
        return _catalogAnchorContract.begin(descriptor);
      }

      bool catalogAccepts(const HalfEdgeMesh::Cavity &cavity) const
      {
        return _catalogAnchorContract.accepts(cavity);
      }

      bool catalogAcceptsBoundaryLoop(std::size_t vertexCount) const
      {
        return _catalogAnchorContract.acceptsBoundaryLoop(vertexCount);
      }

      bool finishCatalogRewrite(bool requireAcceptedAnchor)
      {
        return _catalogAnchorContract.finish(requireAcceptedAnchor);
      }

      bool addElement(MElement *element)
      {
        if(!element || findElement(element) != HalfEdgeMesh::invalid)
          return false;
        const std::size_t count = element->getNumPrimaryVertices();
        if(count != 3 && count != 4) return false;
        std::set<MVertex *> elementVertices;
        std::vector<Index> vertices;
        vertices.reserve(count);
        for(std::size_t i = 0; i < count; ++i) {
          MVertex *vertex = element->getVertex(static_cast<int>(i));
          if(!vertex || !elementVertices.insert(vertex).second)
            return false;
          const Index index = addVertex(vertex);
          if(index == HalfEdgeMesh::invalid) return false;
          vertices.push_back(index);
        }
        const Index index = _mesh.addFace(vertices);
        if(index == HalfEdgeMesh::invalid) return false;
        if(static_cast<std::size_t>(index) != _elementsByIndex.size())
          return false;
        _elementsByIndex.push_back(element);
        _elementIndices.emplace(element, index);
        ++_revision;
        invalidateSortedViews();
        return true;
      }

      bool removeElement(MElement *element)
      {
        const Index index = findElement(element);
        if(index == HalfEdgeMesh::invalid) return false;
        const std::vector<Index> touched = _mesh.faceVertices(index);
        if(!_mesh.removeFace(index))
          return false;
        for(const Index vertex : touched) touchVertexState(vertex);
        _elementIndices.erase(element);
        _elementsByIndex[static_cast<std::size_t>(index)] = nullptr;
        ++_revision;
        invalidateSortedViews();
        return true;
      }

      // Check a prospective local transaction without copying the complete
      // face index. Only edges of inserted cells can acquire a new incidence;
      // start those edge stars from the active, non-removed incidences and
      // replay addElement's oriented-cell-complex guards locally. No copy of
      // the face topology is made: an accepted transaction mutates the same
      // persistent mesh once, after GFaceMeshDiff has transferred ownership.
      PreparedReplacement prepareReplacement(
        const std::vector<MElement *> &removed,
        const std::vector<MElement *> &inserted) const
      {
        PreparedReplacement prepared;
        prepared._owner = this;
        prepared._revision = _revision;
        prepared._vertexStorageSize = _mesh.vertexStorageSize();
        prepared._faceStorageSize = _mesh.faceStorageSize();
        if(!manifold()) return prepared;
        std::set<MElement *> removedElements;
        std::set<Index> touchedExistingVertices;
        prepared._removedFaces.reserve(removed.size());
        prepared._removedElements.reserve(removed.size());
        prepared._removedElementMappings.reserve(removed.size());
        for(MElement *element : removed) {
          const auto found = _elementIndices.find(element);
          if(!element || found == _elementIndices.end() ||
             !removedElements.insert(element).second)
            return prepared;
          prepared._removedFaces.push_back(found->second);
          prepared._removedElements.push_back(element);
          prepared._removedElementMappings.push_back(found);
          const std::vector<Index> vertices =
            _mesh.faceVertices(found->second);
          touchedExistingVertices.insert(vertices.begin(), vertices.end());
        }

        std::set<MElement *> insertedElements;
        std::unordered_map<MVertex *, Index> virtualVertices;
        prepared._insertedFaces.reserve(inserted.size());
        prepared._insertedElements.reserve(inserted.size());
        Index nextVirtual = static_cast<Index>(_mesh.vertexStorageSize());
        for(MElement *insertedElement : inserted) {
          if(!insertedElement ||
             !insertedElements.insert(insertedElement).second ||
             // GFaceMeshDiff deletes every object in `before`. Reusing the
             // same pointer in `after` would leave both the GFace and the
             // numeric adapter holding a dangling MElement.
             findElement(insertedElement) != HalfEdgeMesh::invalid)
            return prepared;
          const std::size_t count =
            insertedElement->getNumPrimaryVertices();
          if(count != 3 && count != 4) return prepared;
          std::vector<Index> vertices;
          vertices.reserve(count);
          for(std::size_t i = 0; i < count; ++i) {
            MVertex *candidate =
              insertedElement->getVertex(static_cast<int>(i));
            if(!candidate) return prepared;
            Index index = findVertex(candidate);
            if(index == HalfEdgeMesh::invalid) {
              const auto found = virtualVertices.find(candidate);
              if(found == virtualVertices.end()) {
                if(nextVirtual == std::numeric_limits<Index>::max())
                  return prepared;
                index = nextVirtual++;
                virtualVertices.emplace(candidate, index);
                prepared._newVertices.push_back(candidate);
                prepared._newVertexPositions.push_back(
                  {{candidate->x(), candidate->y(), candidate->z()}});
              }
              else {
                index = found->second;
              }
            }
            else {
              touchedExistingVertices.insert(index);
            }
            vertices.push_back(index);
          }
          prepared._insertedFaces.push_back(std::move(vertices));
          prepared._insertedElements.push_back(insertedElement);
        }
        if(!_mesh.validReplacement(
             prepared._removedFaces, prepared._insertedFaces))
          return prepared;
        std::vector<std::vector<Index> > removedFaces;
        removedFaces.reserve(prepared._removedFaces.size());
        for(const Index face : prepared._removedFaces)
          removedFaces.push_back(_mesh.faceVertices(face));
        // A cavity rewrite may change its interior connectivity, but not the
        // oriented interface through which it is attached to the unchanged
        // mesh. This also catches a disconnected island or an accidental new
        // hole that the global edge-incidence test alone would accept.
        if(!sameDirectedBoundary(removedFaces, prepared._insertedFaces)) {
          if(Msg::GetVerbosity() > 5)
            Msg::Info("QuadOptimizer transaction: rejected a rewrite that "
                      "changes the oriented cavity interface");
          return prepared;
        }
        prepared._touchedExistingVertices.reserve(
          touchedExistingVertices.size());
        for(const Index index : touchedExistingVertices) {
          MVertex *handle = vertex(index);
          if(!handle) return prepared;
          const auto found = _vertexIndices.find(handle);
          if(found == _vertexIndices.end() || found->second != index)
            return prepared;
          prepared._touchedExistingVertices.push_back({index, found});

          bool retained = false;
          for(const Index face : _mesh.incidentFaces(index))
            if(std::find(prepared._removedFaces.begin(),
                         prepared._removedFaces.end(), face) ==
               prepared._removedFaces.end()) {
              retained = true;
              break;
            }
          if(!retained)
            for(const std::vector<Index> &face : prepared._insertedFaces)
              if(std::find(face.begin(), face.end(), index) != face.end()) {
                retained = true;
                break;
              }
          if(!retained) prepared._retiredVertices.push_back(handle);
        }
        prepared._valid = true;
        return prepared;
      }

      bool validReplacement(const std::vector<MElement *> &removed,
                            const std::vector<MElement *> &inserted) const
      {
        return static_cast<bool>(prepareReplacement(removed, inserted));
      }

      // Bind a numeric edit to the exact GFace ownership diff that will be
      // executed. All checks performed by GFaceMeshDiff::execute(), plus its
      // currently implicit ownership assumptions, are discharged here while
      // every old object is still alive. The subsequent execute() therefore
      // cannot discover an input-dependent error after deleting an object.
      bool preflightPreparedDiff(const PreparedReplacement &prepared,
                                 GFaceMeshDiff &diff) const
      {
        if(!prepared._valid || prepared._owner != this ||
           prepared._revision != _revision ||
           prepared._vertexStorageSize != _mesh.vertexStorageSize() ||
           prepared._faceStorageSize != _mesh.faceStorageSize() ||
           !_synchronized || !diff.gf || diff.done ||
           diff.gf != diff.before.gf || diff.gf != diff.after.gf ||
           diff.after.elements.empty() ||
           diff.before.bdrVertices != diff.after.bdrVertices ||
           !sameUniquePointers(diff.before.elements,
                               prepared._removedElements) ||
           !sameUniquePointers(diff.after.elements,
                               prepared._insertedElements) ||
           !sameUniquePointers(diff.before.intVertices,
                               prepared._retiredVertices) ||
           !sameUniquePointers(diff.after.intVertices,
                               prepared._newVertices) ||
           !patchIsTopologicallyValid(diff.after))
          return false;

        std::unordered_map<MVertex *, Index> preparedVertices;
        preparedVertices.reserve(prepared._newVertices.size());
        for(std::size_t i = 0; i < prepared._newVertices.size(); ++i) {
          MVertex *candidate = prepared._newVertices[i];
          if(!candidate ||
             !preparedVertices.emplace(
                candidate,
                static_cast<Index>(prepared._vertexStorageSize + i)).second ||
             candidate->x() != prepared._newVertexPositions[i][0] ||
             candidate->y() != prepared._newVertexPositions[i][1] ||
             candidate->z() != prepared._newVertexPositions[i][2])
            return false;
        }
        const auto currentVertexIndex = [&](MVertex *candidate) {
          const Index current = findVertex(candidate);
          if(current != HalfEdgeMesh::invalid) return current;
          const auto found = preparedVertices.find(candidate);
          return found == preparedVertices.end() ?
            HalfEdgeMesh::invalid : found->second;
        };
        const auto connectivityMatches = [&](
          MElement *candidate, const std::vector<Index> &connectivity) {
          if(!candidate ||
             candidate->getNumPrimaryVertices() != connectivity.size())
            return false;
          for(std::size_t i = 0; i < connectivity.size(); ++i)
            if(currentVertexIndex(
                 candidate->getVertex(static_cast<int>(i))) !=
               connectivity[i])
              return false;
          return true;
        };
        for(std::size_t i = 0; i < prepared._removedElements.size(); ++i) {
          const Index face = prepared._removedFaces[i];
          if(!connectivityMatches(prepared._removedElements[i],
                                  _mesh.faceVertices(face)))
            return false;
        }
        for(std::size_t i = 0; i < prepared._insertedElements.size(); ++i)
          if(!connectivityMatches(prepared._insertedElements[i],
                                  prepared._insertedFaces[i]))
            return false;

        const auto triangleOccurrences = [&](MElement *element) {
          MTriangle *triangle = dynamic_cast<MTriangle *>(element);
          return triangle ? static_cast<std::size_t>(std::count(
            diff.gf->triangles.begin(), diff.gf->triangles.end(), triangle)) :
            0;
        };
        const auto quadrangleOccurrences = [&](MElement *element) {
          MQuadrangle *quadrangle = dynamic_cast<MQuadrangle *>(element);
          return quadrangle ? static_cast<std::size_t>(std::count(
            diff.gf->quadrangles.begin(), diff.gf->quadrangles.end(),
            quadrangle)) : 0;
        };
        std::set<MElement *, std::less<MElement *> > removedSet(
          prepared._removedElements.begin(), prepared._removedElements.end());
        for(MElement *element : prepared._removedElements) {
          const bool triangle = dynamic_cast<MTriangle *>(element) != nullptr;
          const bool quadrangle =
            dynamic_cast<MQuadrangle *>(element) != nullptr;
          if(triangle == quadrangle ||
             triangleOccurrences(element) + quadrangleOccurrences(element) !=
               1)
            return false;
        }
        for(MElement *element : prepared._insertedElements) {
          if(removedSet.find(element) != removedSet.end() ||
             (dynamic_cast<MTriangle *>(element) == nullptr &&
              dynamic_cast<MQuadrangle *>(element) == nullptr) ||
             triangleOccurrences(element) || quadrangleOccurrences(element))
            return false;
        }

        for(MVertex *vertex : prepared._retiredVertices)
          if(!vertex || std::count(diff.gf->mesh_vertices.begin(),
                                   diff.gf->mesh_vertices.end(), vertex) != 1)
            return false;
        for(MVertex *vertex : prepared._newVertices)
          if(!vertex || std::find(diff.gf->mesh_vertices.begin(),
                                  diff.gf->mesh_vertices.end(), vertex) !=
                           diff.gf->mesh_vertices.end())
            return false;

        // GFaceMeshDiff appends at most every new object after consuming its
        // replacement slots. Reserve that conservative upper bound now, while
        // a failed allocation can still reject the transaction harmlessly.
        std::size_t newTriangles = 0, newQuadrangles = 0;
        for(MElement *element : prepared._insertedElements) {
          if(dynamic_cast<MTriangle *>(element)) ++newTriangles;
          else ++newQuadrangles;
        }
        try {
          diff.gf->mesh_vertices.reserve(
            diff.gf->mesh_vertices.size() + prepared._newVertices.size());
          diff.gf->triangles.reserve(
            diff.gf->triangles.size() + newTriangles);
          diff.gf->quadrangles.reserve(
            diff.gf->quadrangles.size() + newQuadrangles);
        }
        catch(...) {
          return false;
        }
        return true;
      }

      // Exceptional recovery only. Normal candidates update the one
      // persistent mesh locally; if an invariant that was already preflighted
      // nevertheless fails after the GFace commit, reconstruct a fresh state
      // from the authoritative live GFace and swap it in atomically.
      bool rebuildFromFace(GFace *face)
      {
        if(!face) {
          _synchronized = false;
          return false;
        }
        FaceHalfEdgeTopology rebuilt;
        const std::vector<MElement *> live = surfaceElements(face);
        for(MElement *element : live)
          if(!rebuilt.addElement(element)) {
            _synchronized = false;
            return false;
          }
        if(!rebuilt.manifold() ||
           rebuilt._elementIndices.size() != live.size()) {
          _synchronized = false;
          return false;
        }
        using std::swap;
        swap(_mesh, rebuilt._mesh);
        swap(_verticesByIndex, rebuilt._verticesByIndex);
        swap(_vertexIndices, rebuilt._vertexIndices);
        swap(_vertexStateRevisions, rebuilt._vertexStateRevisions);
        swap(_elementsByIndex, rebuilt._elementsByIndex);
        swap(_elementIndices, rebuilt._elementIndices);
        for(const Index index : _mesh.vertices()) touchVertexState(index);
        _synchronized = true;
        ++_revision;
        invalidateSortedViews();
        return true;
      }

      bool commitPrepared(PreparedReplacement &prepared)
      {
        if(!prepared._valid || prepared._owner != this ||
           prepared._revision != _revision ||
           prepared._vertexStorageSize != _mesh.vertexStorageSize() ||
           prepared._faceStorageSize != _mesh.faceStorageSize() ||
           _verticesByIndex.size() != _mesh.vertexStorageSize() ||
           _vertexStateRevisions.size() != _mesh.vertexStorageSize() ||
           _elementsByIndex.size() != _mesh.faceStorageSize())
          return false;
        prepared._valid = false;

        std::set<Index> affectedVertices;
        for(const Index face : prepared._removedFaces) {
          const std::vector<Index> vertices = _mesh.faceVertices(face);
          affectedVertices.insert(vertices.begin(), vertices.end());
        }
        for(const std::vector<Index> &vertices : prepared._insertedFaces)
          affectedVertices.insert(vertices.begin(), vertices.end());

        std::vector<Index> addedVertices;
        addedVertices.reserve(prepared._newVertices.size());
        for(std::size_t i = 0; i < prepared._newVertices.size(); ++i) {
          const Index expected = static_cast<Index>(
            prepared._vertexStorageSize + i);
          const Index index = _mesh.addVertex(
            prepared._newVertexPositions[i]);
          if(index != expected) return false;
          addedVertices.push_back(index);
          _verticesByIndex.push_back(prepared._newVertices[i]);
          _vertexStateRevisions.push_back(0);
        }

        std::vector<Index> insertedFaces;
        if(!_mesh.replace(prepared._removedFaces,
                          prepared._insertedFaces, &insertedFaces) ||
           insertedFaces.size() != prepared._insertedElements.size()) {
          for(const Index index : addedVertices)
            _mesh.retireIsolatedVertex(index);
          return false;
        }

        // Erase through iterators captured while all handles were alive. No
        // deleted Gmsh element or vertex is inspected by this commit.
        for(std::size_t i = 0; i < prepared._removedFaces.size(); ++i) {
          const Index index = prepared._removedFaces[i];
          _elementIndices.erase(prepared._removedElementMappings[i]);
          _elementsByIndex[static_cast<std::size_t>(index)] = nullptr;
        }
        for(const auto &entry : prepared._touchedExistingVertices) {
          const Index index = entry.first;
          if(!_mesh.incidentFaces(index).empty()) continue;
          _vertexIndices.erase(entry.second);
          _verticesByIndex[static_cast<std::size_t>(index)] = nullptr;
          if(!_mesh.retireIsolatedVertex(index)) return false;
        }
        for(std::size_t i = 0; i < prepared._newVertices.size(); ++i) {
          const Index index = addedVertices[i];
          if(!_vertexIndices.emplace(prepared._newVertices[i], index).second)
            return false;
        }
        for(std::size_t i = 0; i < insertedFaces.size(); ++i) {
          const Index index = insertedFaces[i];
          if(index != static_cast<Index>(_elementsByIndex.size()) ||
             !_elementIndices.emplace(
               prepared._insertedElements[i], index).second)
            return false;
          _elementsByIndex.push_back(prepared._insertedElements[i]);
        }
        for(const Index index : affectedVertices)
          touchVertexState(index);
        ++_revision;
        invalidateSortedViews();
        return manifold();
      }

      bool replace(const std::vector<MElement *> &removed,
                   const std::vector<MElement *> &inserted)
      {
        PreparedReplacement prepared =
          prepareReplacement(removed, inserted);
        return commitPrepared(prepared);
      }

      std::vector<MElement *> elements() const
      {
        if(_elementsViewDirty) {
          _elementsView.clear();
          for(const Index index : _mesh.faces())
            if(MElement *current = element(index))
              _elementsView.push_back(current);
          std::sort(_elementsView.begin(), _elementsView.end(),
                    canonicalElementGeometryLess);
          _elementsViewDirty = false;
        }
        return _elementsView;
      }

      std::vector<MElement *> elements(
        const HalfEdgeMesh::Cavity &cavity) const
      {
        std::vector<MElement *> result;
        result.reserve(cavity.faces.size());
        for(const Index index : cavity.faces) {
          MElement *current = element(index);
          if(!current) return {};
          result.push_back(current);
        }
        std::sort(result.begin(), result.end(),
                  canonicalElementGeometryLess);
        return result;
      }

      bool cavityAroundVertex(MVertex *center,
                              HalfEdgeMesh::Cavity &cavity) const
      {
        const Index index = findVertex(center);
        if(index == HalfEdgeMesh::invalid) {
          cavity.clear();
          return false;
        }
        return _mesh.vertexCavity(index, cavity);
      }

      std::vector<Index> anchorFacePattern(
        const HalfEdgeMesh::Cavity &cavity) const
      {
        return _mesh.anchorFacePattern(cavity);
      }

      bool cavityFromElements(const std::vector<MElement *> &elements,
                              HalfEdgeMesh::Cavity &cavity) const
      {
        std::vector<Index> indices;
        indices.reserve(elements.size());
        for(MElement *current : elements) {
          const Index index = findElement(current);
          if(index == HalfEdgeMesh::invalid) {
            cavity.clear();
            return false;
          }
          indices.push_back(index);
        }
        return _mesh.diskCavity(indices, cavity);
      }

      bool cavityFromElements(
        const std::vector<MElement *> &elements,
        const HalfEdgeMesh::Cavity &anchor,
        HalfEdgeMesh::Cavity &cavity) const
      {
        HalfEdgeMesh::Cavity disk;
        if(!cavityFromElements(elements, disk)) return false;
        disk.anchor = anchor.anchor;
        disk.anchorFirst = anchor.anchorFirst;
        disk.anchorSecond = anchor.anchorSecond;
        disk.anchorOnBoundary = anchor.anchorOnBoundary;
        disk.anchorVertices = anchor.anchorVertices;
        disk.anchorFaces = anchor.anchorFaces;
        // diskCavity() already produced coreFaces == faces.  Preserve that
        // exact numeric disk and merely attach its anchor; rebuilding the
        // same disk here doubled the topology work of every collector.
        cavity = std::move(disk);
        return true;
      }

      // Translate an ordered T-Q^k-T face chain once, let the persistent
      // numeric topology prove that it is a true opposite-edge strip, then
      // expose its rails in the local boundary numbering used by patterns.
      bool triangleQuadStripRails(
        const std::vector<MElement *> &orderedElements,
        const std::vector<MVertex *> &boundary,
        std::vector<std::size_t> &firstRail,
        std::vector<std::size_t> &secondRail) const
      {
        firstRail.clear();
        secondRail.clear();
        std::vector<Index> orderedFaces;
        orderedFaces.reserve(orderedElements.size());
        for(MElement *current : orderedElements) {
          const Index face = findElement(current);
          if(face == HalfEdgeMesh::invalid) return false;
          orderedFaces.push_back(face);
        }
        std::vector<Index> numericFirst, numericSecond;
        if(!_mesh.triangleQuadStripRails(
             orderedFaces, numericFirst, numericSecond))
          return false;

        std::map<Index, std::size_t> localBoundary;
        for(std::size_t i = 0; i < boundary.size(); ++i) {
          const Index vertexIndex = findVertex(boundary[i]);
          if(vertexIndex == HalfEdgeMesh::invalid ||
             !localBoundary.emplace(vertexIndex, i).second)
            return false;
        }
        auto translate = [&](const std::vector<Index> &numeric,
                             std::vector<std::size_t> &local) {
          local.reserve(numeric.size());
          for(const Index vertexIndex : numeric) {
            const auto found = localBoundary.find(vertexIndex);
            if(found == localBoundary.end()) return false;
            local.push_back(found->second);
          }
          return true;
        };
        if(!translate(numericFirst, firstRail) ||
           !translate(numericSecond, secondRail)) {
          firstRail.clear();
          secondRail.clear();
          return false;
        }
        return true;
      }

      bool triangleQuadBoundaryFan(
        const std::vector<MElement *> &orderedElements) const
      {
        std::vector<Index> orderedFaces;
        orderedFaces.reserve(orderedElements.size());
        for(MElement *current : orderedElements) {
          const Index face = findElement(current);
          if(face == HalfEdgeMesh::invalid) return false;
          orderedFaces.push_back(face);
        }
        return _mesh.triangleQuadBoundaryFanCenter(orderedFaces) !=
               HalfEdgeMesh::invalid;
      }

      bool containsVertex(MVertex *vertex) const
      {
        return findVertex(vertex) != HalfEdgeMesh::invalid;
      }

      // Exact identity of the complete state that can influence a C+C'
      // rewrite. The support faces encode connectivity; per-vertex monotone
      // generations encode every incident topology or XYZ change without
      // repeatedly hashing coordinates. Consequently a rejected attempt can
      // be reused after a distant rewrite, but never after a topology,
      // geometry or constraint change that could alter its result.
      bool cavityEvaluationStateSignature(
        GFace *face, const HalfEdgeMesh::Cavity &core,
        const std::set<MVertex *> *permanentlyProtectedVertices,
        const std::set<MVertex *> *additionalProtectedVertices,
        CavityStateSignature &signature) const
      {
        signature.clear();
        if(!face || !manifold() || core.faces.empty() ||
           core.faces != core.coreFaces)
          return false;

        std::set<Index> coreVertices;
        for(const Index faceIndex : core.coreFaces) {
          const std::vector<Index> vertices =
            _mesh.faceVertices(faceIndex);
          if(vertices.empty()) return false;
          coreVertices.insert(vertices.begin(), vertices.end());
        }
        std::vector<Index> supportCenters;
        supportCenters.reserve(coreVertices.size());
        for(const Index index : coreVertices) {
          MVertex *handle = vertex(index);
          if(!handle || handle->onWhat() != face ||
             (permanentlyProtectedVertices &&
              permanentlyProtectedVertices->find(handle) !=
                permanentlyProtectedVertices->end()) ||
             (additionalProtectedVertices &&
              additionalProtectedVertices->find(handle) !=
                additionalProtectedVertices->end()))
            continue;
          supportCenters.push_back(index);
        }

        HalfEdgeMesh::Cavity support = core;
        if(!supportCenters.empty() &&
           !_mesh.extendByVertexStars(core, supportCenters, support))
          return false;

        auto appendIndex = [&](Index index) {
          signature.push_back(static_cast<std::uint64_t>(index));
        };
        auto appendIndices = [&](const std::vector<Index> &indices) {
          signature.push_back(static_cast<std::uint64_t>(indices.size()));
          for(const Index index : indices) appendIndex(index);
        };
        appendIndex(static_cast<Index>(core.anchor));
        appendIndex(core.anchorFirst);
        appendIndex(core.anchorSecond);
        appendIndex(core.anchorOnBoundary);
        appendIndices(core.anchorVertices);
        appendIndices(core.anchorFaces);
        appendIndices(core.coreFaces);
        appendIndices(support.faces);

        std::set<Index> supportVertices;
        for(const Index faceIndex : support.faces) {
          const std::vector<Index> vertices =
            _mesh.faceVertices(faceIndex);
          if(vertices.empty()) return false;
          supportVertices.insert(vertices.begin(), vertices.end());
        }
        signature.push_back(
          static_cast<std::uint64_t>(supportVertices.size()));
        for(const Index index : supportVertices) {
          MVertex *handle = vertex(index);
          if(!handle || index < 0 ||
             static_cast<std::size_t>(index) >=
               _vertexStateRevisions.size())
            return false;
          appendIndex(index);
          signature.push_back(
            _vertexStateRevisions[static_cast<std::size_t>(index)]);
          signature.push_back(
            permanentlyProtectedVertices &&
                permanentlyProtectedVertices->find(handle) !=
                  permanentlyProtectedVertices->end() ?
              std::uint64_t(1) : std::uint64_t(0));
          signature.push_back(
            additionalProtectedVertices &&
                additionalProtectedVertices->find(handle) !=
                  additionalProtectedVertices->end() ?
              std::uint64_t(1) : std::uint64_t(0));
        }
        return true;
      }

      bool cavityAroundVertices(
        const std::vector<MVertex *> &centers,
        HalfEdgeMesh::Cavity &cavity) const
      {
        std::vector<Index> indices;
        indices.reserve(centers.size());
        for(MVertex *center : centers) {
          const Index index = findVertex(center);
          if(index == HalfEdgeMesh::invalid) {
            cavity.clear();
            return false;
          }
          indices.push_back(index);
        }
        return _mesh.vertexStarsCavity(indices, cavity);
      }

      bool cavityAroundEdge(const Edge &center,
                            HalfEdgeMesh::Cavity &cavity) const
      {
        const Index first = findVertex(center.first);
        const Index second = findVertex(center.second);
        if(first == HalfEdgeMesh::invalid ||
           second == HalfEdgeMesh::invalid) {
          cavity.clear();
          return false;
        }
        return _mesh.edgeCavity(
          HalfEdgeMesh::canonicalEdge(first, second), cavity);
      }

      bool singleQuadrangleCavity(MElement *center,
                                  HalfEdgeMesh::Cavity &cavity) const
      {
        const Index index = findElement(center);
        if(index == HalfEdgeMesh::invalid) {
          cavity.clear();
          return false;
        }
        return _mesh.singleQuadCavity(index, cavity);
      }

      bool extendCavityByVertexStars(
        const HalfEdgeMesh::Cavity &core,
        const std::vector<MVertex *> &vertices,
        HalfEdgeMesh::Cavity &support) const
      {
        std::vector<Index> indices;
        indices.reserve(vertices.size());
        for(MVertex *vertex : vertices) {
          const Index index = findVertex(vertex);
          if(index == HalfEdgeMesh::invalid) {
            support.clear();
            return false;
          }
          indices.push_back(index);
        }
        return _mesh.extendByVertexStars(core, indices, support);
      }

      bool promoteCavitySupportToCore(
        const HalfEdgeMesh::Cavity &support,
        HalfEdgeMesh::Cavity &core) const
      {
        return _mesh.promoteSupportToCore(support, core);
      }

      std::vector<MVertex *> vertices() const
      {
        if(!_verticesViewDirty) return _verticesView;
        _verticesView.clear();
        for(const Index index : _mesh.vertices())
          if(MVertex *current = vertex(index))
            _verticesView.push_back(current);
        std::sort(_verticesView.begin(), _verticesView.end(),
                  canonicalVertexGeometryLess);
        _verticesViewDirty = false;
        return _verticesView;
      }

      // Canonical ordering depends on XYZ in addition to connectivity. The
      // optimizer calls this after an accepted geometry-only Winslow batch;
      // topology edits already invalidate the same views through add/remove.
      bool synchronizeGeometry(const std::vector<MVertex *> &vertices) const
      {
        std::set<Index> synchronized;
        bool changed = false;
        for(MVertex *current : vertices) {
          const Index index = findVertex(current);
          if(index == HalfEdgeMesh::invalid ||
             !synchronized.insert(index).second)
            continue;
          const std::array<double, 3> *before =
            _mesh.vertexPosition(index);
          if(before &&
             exactDoubleBits((*before)[0]) == exactDoubleBits(current->x()) &&
             exactDoubleBits((*before)[1]) == exactDoubleBits(current->y()) &&
             exactDoubleBits((*before)[2]) == exactDoubleBits(current->z()))
            continue;
          _mesh.setVertexPosition(
            index, {{current->x(), current->y(), current->z()}});
          touchVertexState(index);
          changed = true;
        }
        if(changed) invalidateSortedViews();
        return changed;
      }

      void invalidateGeometryOrdering() const
      {
        std::vector<MVertex *> all;
        all.reserve(_vertexIndices.size());
        for(const auto &entry : _vertexIndices) all.push_back(entry.first);
        synchronizeGeometry(all);
      }

      std::vector<MElement *> incidentElements(MVertex *vertex) const
      {
        const auto cached = _incidentElementsViews.find(vertex);
        if(cached != _incidentElementsViews.end()) return cached->second;
        std::vector<MElement *> result;
        const Index vertexIndex = findVertex(vertex);
        if(vertexIndex == HalfEdgeMesh::invalid) return result;
        for(const Index index : _mesh.incidentFaces(vertexIndex))
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
        const Index first = findVertex(edge.first);
        const Index second = findVertex(edge.second);
        if(first == HalfEdgeMesh::invalid ||
           second == HalfEdgeMesh::invalid)
          return result;
        for(const Index index : _mesh.incidentFaces(
              HalfEdgeMesh::canonicalEdge(first, second)))
          if(MElement *current = element(index)) result.push_back(current);
        std::sort(result.begin(), result.end(),
                  canonicalElementGeometryLess);
        return _edgeIncidentElementsViews.emplace(edge, std::move(result))
          .first->second;
      }

      std::size_t elementCount(std::size_t primaryVertexCount) const
      {
        return _mesh.faceCount(primaryVertexCount);
      }

      std::size_t quadDegree(MVertex *vertex) const
      {
        const auto cached = _quadDegreeViews.find(vertex);
        if(cached != _quadDegreeViews.end()) return cached->second;
        const Index index = findVertex(vertex);
        const std::size_t degree = index == HalfEdgeMesh::invalid ?
          0 : _mesh.quadDegree(index);
        _quadDegreeViews[vertex] = degree;
        return degree;
      }

      std::size_t quadDegreeAfterReplacement(
        MVertex *vertex, const std::vector<MElement *> &removed,
        const std::vector<MElement *> &inserted) const
      {
        std::size_t degree = quadDegree(vertex);
        for(MElement *element : removed) {
          if(!element || element->getNumPrimaryVertices() != 4) continue;
          bool contains = false;
          for(std::size_t i = 0; i < 4; ++i)
            contains = contains ||
              element->getVertex(static_cast<int>(i)) == vertex;
          if(contains) {
            if(degree == 0) return 0;
            --degree;
          }
        }
        for(MElement *element : inserted) {
          if(!element || element->getNumPrimaryVertices() != 4) continue;
          for(std::size_t i = 0; i < 4; ++i)
            if(element->getVertex(static_cast<int>(i)) == vertex) {
              ++degree;
              break;
            }
        }
        return degree;
      }

      bool isBoundaryVertex(MVertex *vertex) const
      {
        const auto cached = _boundaryVertexViews.find(vertex);
        if(cached != _boundaryVertexViews.end()) return cached->second;
        const Index index = findVertex(vertex);
        const bool boundary = index != HalfEdgeMesh::invalid &&
          _mesh.isBoundaryVertex(index);
        _boundaryVertexViews[vertex] = boundary;
        return boundary;
      }

      std::vector<MElement *> neighbors(MElement *element) const
      {
        const auto cached = _neighborViews.find(element);
        if(cached != _neighborViews.end()) return cached->second;
        std::vector<MElement *> result;
        const Index face = findElement(element);
        if(face == HalfEdgeMesh::invalid) return result;
        for(const Index index : _mesh.neighbors(face))
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
          _mesh.edges();
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

    // Temporary Gmsh ownership transaction paired with one already validated
    // integer half-edge edit. The GFace diff is the unique transaction
    // description: both the numeric replacement and the ownership preflight
    // are derived from its exact before/after object sets. This replaces the
    // former full FaceHalfEdgeTopology copy made for every candidate.
    class FaceRewriteTransaction {
      FaceHalfEdgeTopology *_topology = nullptr;
      GFaceMeshDiff *_diff = nullptr;
      FaceHalfEdgeTopology::PreparedReplacement _prepared;
      bool _valid = false;

    public:
      FaceRewriteTransaction(
        FaceHalfEdgeTopology &topology, GFaceMeshDiff &diff)
        : _topology(&topology),
          _diff(&diff),
          _prepared(topology.prepareReplacement(
            diff.before.elements, diff.after.elements))
      {
        const bool topologyPrepared = static_cast<bool>(_prepared);
        _valid = topologyPrepared &&
          topology.preflightPreparedDiff(_prepared, diff);
        if(!_valid && Msg::GetVerbosity() > 5)
          Msg::Info("QuadOptimizer transaction: %s preflight rejected the "
                    "candidate",
                    topologyPrepared ? "GFace/half-edge concordance" :
                                       "numeric topology");
      }

      explicit operator bool() const
      {
        return _valid;
      }

      bool execute()
      {
        if(!_valid || !static_cast<bool>(_prepared) || !_topology || !_diff) {
          if(Msg::GetVerbosity() > 5)
            Msg::Info("QuadOptimizer transaction: invalid execution lease");
          return false;
        }
        _valid = false;
        // Recheck the exact lease immediately before transferring ownership;
        // callers cannot substitute or mutate a diff after construction.
        if(!_topology->preflightPreparedDiff(_prepared, *_diff)) {
          if(Msg::GetVerbosity() > 5)
            Msg::Info("QuadOptimizer transaction: execution preflight "
                      "rejected the candidate");
          return false;
        }
        if(!_diff->execute(true)) {
          if(Msg::GetVerbosity() > 5)
            Msg::Info("QuadOptimizer transaction: GFace commit rejected "
                      "the candidate");
          return false;
        }
        if(_topology->commitPrepared(_prepared)) return true;

        // The GFace commit has happened and owns the new objects. Returning a
        // plain rejection here would leave the persistent topology stale and
        // would also make the caller skip the committed geometry. Rebuild only
        // on this supposedly impossible invariant failure and report the
        // operation as committed when synchronization is restored.
        if(_topology->rebuildFromFace(_diff->gf)) {
          Msg::Warning("QuadOptimizer: recovered the persistent half-edge "
                       "topology after a local commit invariant failed on "
                       "face %d",
                       _diff->gf->tag());
          return true;
        }
        Msg::Warning("QuadOptimizer: could not recover the persistent "
                     "half-edge topology after a committed rewrite on face "
                     "%d; stopping further local rewrites on this face",
                     _diff->gf->tag());
        return false;
      }
    };

    bool materializeCavitySeed(
      GFace *face, const HalfEdgeMesh::Cavity &cavity,
      const FaceHalfEdgeTopology &topology, CavitySeed &seed,
      bool canonicalize = true)
    {
      if(cavity.faces.empty() || cavity.faces != cavity.coreFaces)
        return false;
      const std::vector<MElement *> elements = topology.elements(cavity);
      if(elements.size() != cavity.faces.size()) return false;
      GFaceMeshPatch patch;
      const bool built = canonicalize ?
        canonicalPatchFromElements(face, elements, patch) :
        patchFromElements(face, elements, patch);
      if(!built) return false;
      seed.halfEdgeCavity = cavity;
      seed.patch = std::move(patch);
      return true;
    }

    bool sameVertices(const std::vector<MVertex *> &first,
                      const std::vector<MVertex *> &second)
    {
      return std::set<MVertex *>(first.begin(), first.end()) ==
             std::set<MVertex *>(second.begin(), second.end());
    }

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
                                const FaceHalfEdgeTopology &topology)
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

    // The Q+T+T -> Q+Q operator has an explicit topological objective that
    // the all-quad Cleanup potential cannot encode: after validity, fewer
    // triangles is strictly better. The ordinary Fast quality remains the
    // tie-breaker between candidates with the same element counts.
    struct FastTriangleReductionQuality {
      std::size_t invalidElementCount = 0;
      std::size_t triangleCount = 0;
      FastGlobalQuality remaining;
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
      // Connectivity changes must buy a measurable improvement.  The
      // Winslow solve and the CAD projection both accumulate floating-point
      // noise, so a fixed 1.e-10 decrement is far too small for objectives
      // whose magnitude is O(10--100): it used to accept visually identical
      // rewrites and prevented the catalog from reaching a reproducible fixed
      // point.  Keep a relative dead band, with an absolute floor near zero.
      const auto significantlyLess = [](double left, double right) {
        constexpr double relativeDecrease = 1.e-8;
        const double scale = std::max({1., std::abs(left), std::abs(right)});
        return left + relativeDecrease * scale < right;
      };
      if(significantlyLess(candidate.hardSpecificationPenalty,
                           reference.hardSpecificationPenalty))
        return true;
      if(significantlyLess(reference.hardSpecificationPenalty,
                           candidate.hardSpecificationPenalty))
        return false;
      if(!std::isfinite(candidate.compromise))
        return false;
      if(!std::isfinite(reference.compromise))
        return true;
      return significantlyLess(candidate.compromise,
                               reference.compromise);
    }

    bool improvesFastTriangleReductionQuality(
      const FastTriangleReductionQuality &candidate,
      const FastTriangleReductionQuality &reference)
    {
      if(candidate.invalidElementCount != reference.invalidElementCount)
        return candidate.invalidElementCount < reference.invalidElementCount;
      if(candidate.triangleCount != reference.triangleCount)
        return candidate.triangleCount < reference.triangleCount;
      return improvesFastGlobalQuality(candidate.remaining,
                                       reference.remaining);
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
      for(MElement *element : seed.patch.elements) {
        // topology.quadDegree() deliberately excludes triangles; keep the
        // local contribution in the same unit for mixed T/Q cavities.
        if(element->getNumPrimaryVertices() != 4) continue;
        for(std::size_t i = 0; i < element->getNumPrimaryVertices(); ++i) {
          const auto found = boundaryIndex.find(
            element->getVertex(static_cast<int>(i)));
          if(found != boundaryIndex.end()) ++local[found->second];
        }
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

      // The two `worst*` maxima above are only no-regression guards. They are
      // not additive over overlapping one-rings and consequently cannot be a
      // strict progress witness. Counts and summed penalties below are local
      // deltas of face-wide additive quantities.
      if(candidateQuality.invalidElementCount <
           referenceQuality.invalidElementCount ||
         candidateQuality.absoluteBadElementCount <
           referenceQuality.absoluteBadElementCount ||
         candidateQuality.absoluteViolationCount <
           referenceQuality.absoluteViolationCount ||
         candidateQuality.preferredViolationCount <
           referenceQuality.preferredViolationCount ||
         improves(candidateQuality.absolutePenalty,
                  referenceQuality.absolutePenalty) ||
         improves(candidateQuality.preferredPenalty,
                  referenceQuality.preferredPenalty) ||
         improves(candidateQuality.shapePenalty,
                  referenceQuality.shapePenalty))
        return true;

      // Connectivity is unchanged by smoothing, so both scores contain the
      // same edge count; decreasing their mean is therefore exactly decreasing
      // the corresponding sum of squared logarithmic size errors.
      return std::isfinite(candidateSizeError) &&
             std::isfinite(referenceSizeError) &&
             improves(candidateSizeError, referenceSizeError);
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

    bool geometryRegressionFitsMeshScale(
      const GeometryDeviation &candidate,
      const GeometryDeviation &reference, double targetSize,
      const SmallCavityOptimizerOptions &options,
      double &normalizedIntegralChange,
      double &normalizedMaximumDistanceChange)
    {
      normalizedIntegralChange = std::numeric_limits<double>::infinity();
      normalizedMaximumDistanceChange =
        std::numeric_limits<double>::infinity();
      if(!candidate.valid || !reference.valid ||
         !std::isfinite(targetSize) || !(targetSize > 0.))
        return false;
      const double normalization = std::max(
        std::max(reference.sampledArea, candidate.sampledArea) *
          targetSize * targetSize,
        std::numeric_limits<double>::min());
      normalizedIntegralChange =
        (candidate.squaredDistanceIntegral -
         reference.squaredDistanceIntegral) /
        normalization;
      normalizedMaximumDistanceChange =
        (candidate.maximumDistance - reference.maximumDistance) /
        targetSize;
      return std::isfinite(normalizedIntegralChange) &&
             std::isfinite(normalizedMaximumDistanceChange) &&
             normalizedIntegralChange <=
               options.maximumNormalizedCadRegression &&
             normalizedMaximumDistanceChange <=
               options.maximumCadDistanceIncreaseRatio;
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

    bool useFastInteractiveCleanUp(
      const SmallCavityOptimizerOptions &options)
    {
      return options.fastInteractiveCleanUp;
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
        if(seed.kind == CavityPurpose::CleanUpSize) return true;
        if(seed.objective.absoluteBadElementCount != 0 ||
           seed.objective.absoluteViolationCount != 0)
          return true;
        if(seed.kind == CavityPurpose::CleanUpConnectivity ||
           seed.kind == CavityPurpose::CleanUpBoundary)
          return seed.valence.irregularCount != 0;
        return false;
      }
      if(hasQualitySpecificationFailure(seed.objective)) return true;
      if(seed.kind == CavityPurpose::CleanUpConnectivity ||
         seed.kind == CavityPurpose::CleanUpBoundary)
        return seed.valence.irregularCount != 0;
      return seed.kind == CavityPurpose::CleanUpSize;
    }

    std::vector<CavitySeed> collectCavities(
      GFace *face, const SmallCavityOptimizerOptions &options,
      CavityPurpose requestedKind, const FaceHalfEdgeTopology &topology,
      const CavityCoreAttemptStateBuilder *attemptStateBuilder = nullptr,
      const RejectedCavityStateSet *rejectedCavityAttempts = nullptr)
    {
      const std::vector<MElement *> elements = topology.elements();
      std::vector<CavitySeed> cavities;
      std::set<std::vector<HalfEdgeMesh::Index> > signatures;

      auto add = [&](const std::vector<MVertex *> &interior,
                     bool alwaysTryTopology, CavityPurpose kind,
                     const HalfEdgeMesh::Cavity &cavity) {
        if(cavity.faces.empty() || cavity.faces != cavity.coreFaces) return;
        std::vector<HalfEdgeMesh::Index> signature = cavity.faces;
        signature.push_back(HalfEdgeMesh::invalid);
        signature.push_back(static_cast<HalfEdgeMesh::Index>(cavity.anchor));
        signature.push_back(cavity.anchorFirst);
        signature.push_back(cavity.anchorSecond);
        signature.insert(signature.end(), cavity.anchorVertices.begin(),
                         cavity.anchorVertices.end());
        if(!signatures.insert(signature).second) return;

        CavityStateSignature attemptState;
        const bool cacheable = attemptStateBuilder &&
          (*attemptStateBuilder)(cavity, kind, attemptState);
        // Keep cached rejections in the vector until after sorting. Removing
        // them here changes the permutation of otherwise equivalent entries
        // because std::sort is not stable; the executor then commits a
        // different first admissible cavity. The caller skips their costly
        // evaluation after the complete, historically identical ordering is
        // established.

        CavitySeed seed;
        if(!materializeCavitySeed(face, cavity, topology, seed))
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
        seed.attemptStateCacheable = cacheable;
        seed.attemptState = std::move(attemptState);
        seed.objective = specificationObjective(seed.patch.elements);
        cacheCavityValence(seed, topology);
        cavities.push_back(std::move(seed));
      };

      if(requestedKind == CavityPurpose::Node &&
         options.optimizeOneInteriorVertexCavities) {
        for(MVertex *vertex : topology.vertices()) {
          HalfEdgeMesh::Cavity cavity;
          if(vertex && vertex->onWhat() == face &&
             topology.cavityAroundVertex(vertex, cavity) &&
             !cavity.anchorOnBoundary)
            add({vertex}, false, CavityPurpose::Node, cavity);
        }
      }
      if(requestedKind == CavityPurpose::Edge) {
        for(const auto &entry : topology.edges()) {
          if(entry.second.size() != 2 ||
             entry.second[0]->getNumPrimaryVertices() != 4 ||
             entry.second[1]->getNumPrimaryVertices() != 4)
            continue;
          HalfEdgeMesh::Cavity edgeCavity;
          if(!topology.cavityAroundEdge(entry.first, edgeCavity) ||
             edgeCavity.anchorOnBoundary)
            continue;
          add({}, true, CavityPurpose::Edge, edgeCavity);
        }
      }
      if(requestedKind == CavityPurpose::Triangle &&
         options.optimizeThreeInteriorVertexCavities) {
        for(MElement *element : elements) {
          MTriangle *triangle = dynamic_cast<MTriangle *>(element);
          if(!triangle) continue;
          std::vector<MVertex *> vertices(3);
          bool interior = true;
          for(int i = 0; i < 3; ++i) {
            vertices[static_cast<std::size_t>(i)] = triangle->getVertex(i);
            interior = interior && vertices[static_cast<std::size_t>(i)] &&
                       vertices[static_cast<std::size_t>(i)]->onWhat() == face;
          }
          HalfEdgeMesh::Cavity cavity;
          if(interior && topology.cavityAroundVertices(vertices, cavity) &&
             !cavity.anchorOnBoundary)
            add(vertices, true, CavityPurpose::Triangle, cavity);
        }
      }
      if(requestedKind == CavityPurpose::Quadrangle &&
         options.optimizeFourInteriorVertexCavities) {
        for(MElement *element : elements) {
          MQuadrangle *quadrangle = dynamic_cast<MQuadrangle *>(element);
          if(!quadrangle) continue;
          if(evaluateElementQuality(quadrangle).passesAbsoluteSpecifications)
            continue;
          std::vector<MVertex *> vertices(4);
          bool interior = true;
          for(int i = 0; i < 4; ++i) {
            vertices[static_cast<std::size_t>(i)] = quadrangle->getVertex(i);
            interior = interior && vertices[static_cast<std::size_t>(i)] &&
                       vertices[static_cast<std::size_t>(i)]->onWhat() == face;
          }
          HalfEdgeMesh::Cavity cavity;
          if(interior && topology.cavityAroundVertices(vertices, cavity) &&
             !cavity.anchorOnBoundary)
            add(vertices, true, CavityPurpose::Quadrangle, cavity);
        }

        {
          for(const auto &entry : topology.edges()) {
            if(entry.second.size() != 2 ||
               !dynamic_cast<MTriangle *>(entry.second[0]) ||
               !dynamic_cast<MTriangle *>(entry.second[1]))
              continue;
            std::vector<MVertex *> vertices;
            vertices.reserve(4);
            for(MElement *triangle : entry.second)
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
            HalfEdgeMesh::Cavity cavity;
            if(interior && topology.cavityAroundVertices(vertices, cavity) &&
               !cavity.anchorOnBoundary)
              add(vertices, true, CavityPurpose::Quadrangle, cavity);
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

    std::vector<DiamondSeed> collectDiamonds(
      GFace *face, const FaceHalfEdgeTopology &topology)
    {
      std::vector<DiamondSeed> diamonds;

      auto add = [&](MQuadrangle *quadrangle, MVertex *first,
                     MVertex *opposite) {
        if(!first || !opposite || first->onWhat() != face ||
           opposite->onWhat() != face)
          return;
        const std::vector<MElement *> firstStar =
          topology.incidentElements(first);
        const std::vector<MElement *> oppositeStar =
          topology.incidentElements(opposite);
        for(MElement *element : firstStar)
          if(element->getNumPrimaryVertices() != 4) return;
        for(MElement *element : oppositeStar)
          if(element->getNumPrimaryVertices() != 4) return;

        std::size_t centralBoundaryVertices = 0;
        for(std::size_t i = 0; i < 4; ++i) {
          MVertex *vertex = quadrangle->getVertex(static_cast<int>(i));
          if(vertex && vertex->onWhat() != face)
            ++centralBoundaryVertices;
        }
        const bool boundaryDiamond = centralBoundaryVertices == 1;
        if(boundaryDiamond) {
          // Kinney Figure 15: if na and nb are the two diamond vertices
          // adjacent to its sole boundary vertex, closing the diamond merges
          // them and gives valence va + vb - 2. Collapse exactly the cases
          // whose distance from the ideal interior valence four is no worse
          // than the larger of the two original defects. Unlike an interior
          // diamond, this valid pattern is commonly 4/3, not only 3/3.
          const auto defect = [](std::size_t valence) {
            return valence > 4 ? valence - 4 : 4 - valence;
          };
          const std::size_t mergedValence =
            firstStar.size() + oppositeStar.size() - 2;
          if(defect(mergedValence) >
             std::max(defect(firstStar.size()),
                      defect(oppositeStar.size())))
            return;
        }
        else if(firstStar.size() != 3 || oppositeStar.size() != 3) {
          return;
        }

        DiamondSeed diamond;
        std::vector<MVertex *> interior = {first, opposite};
        HalfEdgeMesh::Cavity central, support, cavity;
        if(!topology.singleQuadrangleCavity(quadrangle, central) ||
           !topology.extendCavityByVertexStars(
             central, interior, support) ||
           !topology.promoteCavitySupportToCore(support, cavity) ||
           !materializeCavitySeed(
             face, cavity, topology, diamond.cavity) ||
           diamond.cavity.patch.bdrVertices.size() != 1 ||
           diamond.cavity.patch.bdrVertices.front().size() < 4 ||
           diamond.cavity.patch.bdrVertices.front().size() > 20 ||
           diamond.cavity.patch.bdrVertices.front().size() % 2 != 0 ||
           !diamond.cavity.patch.embVertices.empty() ||
           !sameVertices(diamond.cavity.patch.intVertices, interior))
          return;
        const auto centralElement = std::find(
          diamond.cavity.patch.elements.begin(),
          diamond.cavity.patch.elements.end(), quadrangle);
        if(centralElement == diamond.cavity.patch.elements.end()) return;
        diamond.cavity.interiorVertexCount = 2;
        diamond.cavity.alwaysTryTopology = true;
        diamond.cavity.objective =
          specificationObjective(diamond.cavity.patch.elements);
        cacheCavityValence(diamond.cavity, topology);
        diamond.diamond = quadrangle;
        diamond.boundaryDiamond = boundaryDiamond;
        // Collapsing either diagonal endpoint is a distinct configuration:
        // on a curved face, or next to a size transition, only one of the two
        // can satisfy the geometry guards. Test both instead of selecting an
        // endpoint from its transient mesh number.
        for(std::size_t retained = 0; retained < 2; ++retained) {
          DiamondSeed configuration = diamond;
          configuration.retainedInterior = retained;
          configuration.removedInterior = 1 - retained;
          diamonds.push_back(std::move(configuration));
        }
      };

      for(MElement *element : topology.elements()) {
        MQuadrangle *quadrangle = dynamic_cast<MQuadrangle *>(element);
        if(!quadrangle) continue;
        // Only the opposite valence-three pair that is collapsed must be
        // interior to the face. The other two quad vertices may lie on model
        // curves; they remain fixed as vertices of the cavity boundary.
        add(quadrangle, quadrangle->getVertex(0), quadrangle->getVertex(2));
        add(quadrangle, quadrangle->getVertex(1), quadrangle->getVertex(3));
      }
      std::sort(diamonds.begin(), diamonds.end(),
                [](const DiamondSeed &a, const DiamondSeed &b) {
                  const double ap = objectivePriority(a.cavity.objective);
                  const double bp = objectivePriority(b.cavity.objective);
                  if(ap != bp) return ap > bp;
                  MVertex *ar = a.cavity.patch.intVertices[
                    a.retainedInterior];
                  MVertex *br = b.cavity.patch.intVertices[
                    b.retainedInterior];
                  if(canonicalVertexGeometryLess(ar, br)) return true;
                  if(canonicalVertexGeometryLess(br, ar)) return false;
                  return canonicalElementGeometryLess(a.diamond,
                                                      b.diamond);
                });
      return diamonds;
    }

    std::vector<CavitySeed> collectValenceSixCavities(
      GFace *face, const FaceHalfEdgeTopology &topology)
    {
      std::vector<CavitySeed> cavities;
      for(MVertex *vertex : topology.vertices()) {
        if(!vertex || vertex->onWhat() != face) continue;
        HalfEdgeMesh::Cavity cavity;
        if(!topology.cavityAroundVertex(vertex, cavity) ||
           cavity.anchorOnBoundary)
          continue;
        if(topology.anchorFacePattern(cavity) !=
           std::vector<HalfEdgeMesh::Index>(6, 4))
          continue;
        CavitySeed seed;
        if(!materializeCavitySeed(face, cavity, topology, seed) ||
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

    std::vector<CavitySeed> collectInteriorQQTQQTCavities(
      GFace *face, const FaceHalfEdgeTopology &topology)
    {
      if(!topology.manifold()) return {};
      std::vector<CavitySeed> cavities;
      for(MVertex *vertex : topology.vertices()) {
        if(!vertex || vertex->onWhat() != face) continue;
        HalfEdgeMesh::Cavity cavity;
        if(!topology.cavityAroundVertex(vertex, cavity) ||
           cavity.anchorOnBoundary)
          continue;
        if(!HalfEdgeRewrite::matchesCyclicFacePattern(
             topology.anchorFacePattern(cavity), {3, 4, 4, 3, 4, 4}))
          continue;

        CavitySeed seed;
        if(!materializeCavitySeed(face, cavity, topology, seed) ||
           seed.patch.bdrVertices.size() != 1 ||
           seed.patch.bdrVertices.front().size() != 10 ||
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
                  const double ap = objectivePriority(a.objective);
                  const double bp = objectivePriority(b.objective);
                  if(ap != bp) return ap > bp;
                  return canonicalVertexGeometryLess(
                    a.patch.intVertices.front(),
                    b.patch.intVertices.front());
                });
      return cavities;
    }

    std::vector<CavitySeed> collectInteriorFanCavities(
      GFace *face, const FaceHalfEdgeTopology &topology,
      const std::vector<HalfEdgeMesh::Index> &expectedPattern,
      std::size_t expectedBoundaryVertices)
    {
      if(!topology.manifold()) return {};
      std::vector<CavitySeed> cavities;
      for(MVertex *vertex : topology.vertices()) {
        if(!vertex || vertex->onWhat() != face) continue;
        HalfEdgeMesh::Cavity cavity;
        if(!topology.cavityAroundVertex(vertex, cavity) ||
           cavity.anchorOnBoundary ||
           !HalfEdgeRewrite::matchesCyclicFacePattern(
             topology.anchorFacePattern(cavity), expectedPattern))
          continue;

        CavitySeed seed;
        if(!materializeCavitySeed(face, cavity, topology, seed) ||
           seed.patch.bdrVertices.size() != 1 ||
           seed.patch.bdrVertices.front().size() !=
             expectedBoundaryVertices ||
           seed.patch.elements.size() != expectedPattern.size() ||
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
                  const double ap = objectivePriority(a.objective);
                  const double bp = objectivePriority(b.objective);
                  if(ap != bp) return ap > bp;
                  return canonicalVertexGeometryLess(
                    a.patch.intVertices.front(),
                    b.patch.intVertices.front());
                });
      return cavities;
    }

    std::vector<CavitySeed> collectInteriorTriangleTriangleQuadCavities(
      GFace *face, const FaceHalfEdgeTopology &topology)
    {
      return collectInteriorFanCavities(
        face, topology, {3, 3, 4}, 4);
    }

    std::vector<CavitySeed> collectInteriorFourTriangleFanCavities(
      GFace *face, const FaceHalfEdgeTopology &topology)
    {
      return collectInteriorFanCavities(
        face, topology, {3, 3, 3, 3}, 4);
    }

    std::vector<CavitySeed>
    collectInteriorAlternatingQuadTriangleCavities(
      GFace *face, const FaceHalfEdgeTopology &topology)
    {
      return collectInteriorFanCavities(
        face, topology, {4, 3, 4, 3}, 6);
    }

    std::vector<CavitySeed> collectBoundaryTriangleQuadTriangleFans(
      GFace *face, const FaceHalfEdgeTopology &topology)
    {
      if(!topology.manifold()) return {};
      std::vector<CavitySeed> cavities;
      for(MVertex *vertex : topology.vertices()) {
        HalfEdgeMesh::Cavity cavity;
        const bool classifiedOnFace = vertex && vertex->onWhat() == face;
        const bool classifiedOnBoundary =
          vertex && vertex->onWhat() && vertex->onWhat()->dim() < 2;
        // PACK can leave a topological boundary point classified directly
        // on its discrete face. The half-edge anchor is authoritative here;
        // accept both classifications and reject vertices owned elsewhere.
        if(!vertex || (!classifiedOnFace && !classifiedOnBoundary) ||
           !topology.cavityAroundVertex(vertex, cavity) ||
           !cavity.anchorOnBoundary)
          continue;
        // Around a boundary vertex, recognize the complete open chain
        //
        //   triangle - quad [- quad ...] - triangle.
        //
        // The half-edge cavity already stores that open chain in order, so
        // matching the source pattern is a direct integer operation.
        const std::vector<HalfEdgeMesh::Index> observed =
          topology.anchorFacePattern(cavity);
        if(observed.size() < 3) continue;
        std::vector<HalfEdgeMesh::Index> expected(observed.size(), 4);
        expected.front() = expected.back() = 3;
        if(!HalfEdgeRewrite::matchesBoundaryFacePattern(observed, expected))
          continue;
        const std::size_t quadrangleCount = observed.size() - 2;

        CavitySeed seed;
        if(!materializeCavitySeed(face, cavity, topology, seed) ||
           seed.patch.bdrVertices.size() != 1 ||
           seed.patch.bdrVertices.front().size() !=
             2 * quadrangleCount + 4 ||
           std::find(seed.patch.bdrVertices.front().begin(),
                     seed.patch.bdrVertices.front().end(), vertex) ==
             seed.patch.bdrVertices.front().end() ||
           !seed.patch.intVertices.empty() ||
           !seed.patch.embVertices.empty())
          continue;
        seed.interiorVertexCount = 0;
        seed.alwaysTryTopology = true;
        seed.kind = CavityPurpose::CleanUpBoundary;
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
      if(patch.gf->geomType() == GEntity::DiscreteSurface) {
        // A discrete face is not periodic: recovering every boundary vertex
        // independently from its persistent XYZ is identical to the
        // reference-based path, while allowing persistentFaceParameter's
        // exact per-vertex cache to avoid repeating the closest-point solve.
        for(std::size_t i = 0; i < boundary.size(); ++i) {
          SPoint2 parameter;
          if(!persistentFaceParameter(patch.gf, boundary[i], parameter))
            return false;
          points[i] = {parameter.x(), parameter.y()};
        }
        UV centroid = {0., 0.};
        for(std::size_t i = 0; i < boundary.size(); ++i) {
          centroid[0] += points[i][0];
          centroid[1] += points[i][1];
        }
        centroid[0] /= static_cast<double>(boundary.size());
        centroid[1] /= static_cast<double>(boundary.size());
        for(std::size_t i = boundary.size(); i < points.size(); ++i)
          points[i] = centroid;
        return true;
      }
      std::size_t anchor = boundary.size();
      SPoint2 previous;
      // Parameters on discrete faces are optional cache data and are not
      // guaranteed to survive save/reload. Keep using the persistent XYZ
      // inversion there; native CAD faces can safely reuse their stored UV.
      for(std::size_t i = 0; i < boundary.size(); ++i) {
        double u = 0., v = 0.;
        if(boundary[i] && boundary[i]->onWhat() == patch.gf &&
           boundary[i]->getParameter(0, u) &&
           boundary[i]->getParameter(1, v) &&
           std::isfinite(u) && std::isfinite(v)) {
          anchor = i;
          previous = SPoint2(u, v);
          break;
        }
      }
      if(anchor == boundary.size()) {
        anchor = 0;
        if(!persistentFaceParameter(patch.gf, boundary.front(), previous))
          previous = patch.gf->parFromPoint(boundary.front()->point(),
                                            true, true);
      }
      if(!std::isfinite(previous.x()) || !std::isfinite(previous.y()))
        return false;
      points[anchor] = {previous.x(), previous.y()};
      for(std::size_t offset = 1; offset < boundary.size(); ++offset) {
        const std::size_t i = (anchor + offset) % boundary.size();
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
                             std::size_t rotation, bool reflected,
                             HalfEdgeRewriteSymmetry symmetry)
    {
      Pattern transformed = pattern;
      const std::size_t action = rotation +
        (reflected ? boundaryCount : 0);
      for(auto &quad : transformed)
        quad = HalfEdgeRewrite::transformFace(
          symmetry, boundaryCount, action, quad);
      return transformed;
    }

    struct CachedPatternConfiguration {
      std::size_t pattern = 0;
      std::size_t action = 0;
    };

    struct CachedPatternOrbit {
      std::size_t boundaryCount = 0;
      std::size_t interiorCount = 0;
      HalfEdgeRewriteSymmetry symmetry =
        HalfEdgeRewriteSymmetry::Dihedral;
      bool valid = false;
      std::vector<Pattern> patterns;
      std::size_t degreeStride = 0;
      std::vector<std::uint8_t> degrees;
      std::vector<CachedPatternConfiguration> configurations;
    };

    std::shared_ptr<const CachedPatternOrbit> cachedPatternOrbit(
      std::size_t boundaryCount, std::size_t interiorCount,
      HalfEdgeRewriteSymmetry symmetry)
    {
      // getDiskQuadrangulations is a pure function of (B,I). Keep both its
      // pattern set and the quotient by the requested boundary action in one
      // immutable process-wide entry. Optimizing several cavities with the
      // same combinatorics then recomputes only their valence score.
      static std::mutex cacheMutex;
      static std::vector<std::shared_ptr<const CachedPatternOrbit> > cache;
      const std::lock_guard<std::mutex> lock(cacheMutex);
      for(const auto &entry : cache)
        if(entry->boundaryCount == boundaryCount &&
           entry->interiorCount == interiorCount &&
           entry->symmetry == symmetry)
          return entry;

      std::shared_ptr<CachedPatternOrbit> entry(new CachedPatternOrbit);
      entry->boundaryCount = boundaryCount;
      entry->interiorCount = interiorCount;
      entry->symmetry = symmetry;
      entry->valid = getDiskQuadrangulations(
        boundaryCount, interiorCount, entry->patterns) == 0 &&
        !entry->patterns.empty();
      if(entry->valid) {
        entry->degreeStride = boundaryCount + interiorCount;
        entry->degrees.assign(
          entry->patterns.size() * entry->degreeStride, 0);
        std::set<ConnectivitySignature> uniqueConnectivity;
        for(std::size_t p = 0; p < entry->patterns.size(); ++p) {
          for(const auto &quad : entry->patterns[p])
            for(const std::size_t vertex : quad)
              if(vertex < entry->degreeStride)
                ++entry->degrees[p * entry->degreeStride + vertex];
          const std::size_t count =
            HalfEdgeRewrite::actionCount(symmetry, boundaryCount);
          for(std::size_t action = 0; action < count; ++action) {
            const bool reflected = HalfEdgeRewrite::actionReflected(
              symmetry, boundaryCount, action);
            const std::size_t rotation = HalfEdgeRewrite::actionRotation(
              symmetry, boundaryCount, action);
            const Pattern transformed = transformPattern(
              entry->patterns[p], boundaryCount, rotation, reflected,
              symmetry);
            const ConnectivitySignature connectivity =
              HalfEdgeRewrite::canonicalConnectivityIgnoringInteriorLabels(
                transformed, boundaryCount);
            if(!uniqueConnectivity.insert(connectivity).second) continue;
            entry->configurations.push_back({p, action});
          }
        }
      }
      cache.push_back(entry);
      return entry;
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
      }
      return HalfEdgeRewrite::canonicalConnectivityIgnoringInteriorLabels(
        signature, boundaryCount);
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
        signature.push_back(quad);
      }
      signature =
        HalfEdgeRewrite::canonicalConnectivityIgnoringInteriorLabels(
          signature, boundaryCount);
      return true;
    }

    std::vector<PatternConfiguration> rankPatterns(
      const GFaceMeshPatch &patch, const CachedPatternOrbit &orbit,
      int maximum, const FaceHalfEdgeTopology &topology,
      const CavitySeed *cachedSeed = nullptr)
    {
      if(maximum == 0) return {};
      const std::size_t boundaryCount = patch.bdrVertices.front().size();
      if(!orbit.valid || orbit.boundaryCount != boundaryCount) return {};
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
            static_cast<double>(topology.quadDegree(vertex));
          const double outside = global - currentLocalDegree[i];
          desiredLocalDegree[i] = std::max(
            0., static_cast<double>(idealQuadDegree(
                  patch.gf, vertex, topology)) - outside);
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
      const bool unlimited = maximum < 0;
      const std::size_t limit = unlimited ?
        std::numeric_limits<std::size_t>::max() :
        static_cast<std::size_t>(maximum);
      // `better` makes the worst retained configuration the heap top. This
      // keeps the deterministic top-K of unique, unlabelled connectivities
      // while using O(K) heap memory and O(N log K) heap work.
      std::priority_queue<PatternConfiguration,
                          std::vector<PatternConfiguration>,
                          decltype(better)> best(better);
      std::vector<PatternConfiguration> ranked;
      if(unlimited) ranked.reserve(orbit.configurations.size());
      for(const CachedPatternConfiguration &cached : orbit.configurations) {
        const std::uint8_t *degree = orbit.degrees.data() +
          cached.pattern * orbit.degreeStride;
        double score = 0.;
        for(std::size_t vertex = 0; vertex < boundaryCount; ++vertex) {
          const std::size_t mapped =
            HalfEdgeRewrite::transformBoundaryVertex(
              orbit.symmetry, boundaryCount, cached.action, vertex);
          const double difference =
            static_cast<double>(degree[vertex]) - desiredLocalDegree[mapped];
          score += difference * difference;
        }
        for(std::size_t vertex = boundaryCount;
            vertex < orbit.degreeStride; ++vertex) {
          const double difference = static_cast<double>(degree[vertex]) - 4.;
          score += difference * difference;
        }
        const PatternConfiguration configuration = {
          score, cached.pattern,
          HalfEdgeRewrite::actionRotation(
            orbit.symmetry, boundaryCount, cached.action),
          HalfEdgeRewrite::actionReflected(
            orbit.symmetry, boundaryCount, cached.action)};
        if(unlimited)
          ranked.push_back(configuration);
        else if(best.size() < limit)
          best.push(configuration);
        else if(better(configuration, best.top())) {
          best.pop();
          best.push(configuration);
        }
      }
      if(!unlimited) {
        ranked.reserve(best.size());
        while(!best.empty()) {
          ranked.push_back(best.top());
          best.pop();
        }
      }
      std::sort(ranked.begin(), ranked.end(), better);
      return ranked;
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

    bool meanPlaneChart(
      const std::vector<Point> &xyz,
      const std::vector<std::array<std::size_t, 3> > &triangles,
      const Pattern &quadrangles, Point &origin,
      Point &firstAxis, Point &secondAxis,
      std::vector<UV> &planePoints)
    {
      if(xyz.size() < 3 || (triangles.empty() && quadrangles.empty()))
        return false;
      origin = {0., 0., 0.};
      for(const Point &point : xyz)
        for(std::size_t coordinate = 0; coordinate < 3; ++coordinate)
          origin[coordinate] += point[coordinate];
      for(double &coordinate : origin)
        coordinate /= static_cast<double>(xyz.size());

      // Area-weighted Newell normal of the complete local mixed patch.
      // Computing it from the physical MAT points keeps the Winslow metric
      // independent of the (possibly very distorted) MVC chart.
      Point normal = {0., 0., 0.};
      auto accumulateNormal = [&](const auto &elements) {
        for(const auto &element : elements)
          for(std::size_t i = 0; i < element.size(); ++i) {
            if(element[i] >= xyz.size() ||
               element[(i + 1) % element.size()] >= xyz.size())
              return false;
            const Point &a = xyz[element[i]];
            const Point &b = xyz[element[(i + 1) % element.size()]];
            const Point ac = {a[0] - origin[0], a[1] - origin[1],
                              a[2] - origin[2]};
            const Point bc = {b[0] - origin[0], b[1] - origin[1],
                              b[2] - origin[2]};
            normal[0] += ac[1] * bc[2] - ac[2] * bc[1];
            normal[1] += ac[2] * bc[0] - ac[0] * bc[2];
            normal[2] += ac[0] * bc[1] - ac[1] * bc[0];
          }
        return true;
      };
      if(!accumulateNormal(triangles) ||
         !accumulateNormal(quadrangles))
        return false;
      const double normalNorm = std::sqrt(normal[0] * normal[0] +
                                          normal[1] * normal[1] +
                                          normal[2] * normal[2]);
      if(!(normalNorm > 1.e-14)) return false;
      for(double &coordinate : normal) coordinate /= normalNorm;

      firstAxis = {0., 0., 0.};
      double firstAxisNorm = 0.;
      auto accumulateLongestEdge = [&](const auto &elements) {
        for(const auto &element : elements)
          for(std::size_t i = 0; i < element.size(); ++i) {
            const Point &a = xyz[element[i]];
            const Point &b = xyz[element[(i + 1) % element.size()]];
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
      };
      accumulateLongestEdge(triangles);
      accumulateLongestEdge(quadrangles);
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

    bool immutableCandidateChordsRespectSize(
      GFace *face, const std::vector<UV> &boundaryUv,
      const std::vector<Point> &boundaryXyz, const Pattern &quadrangles,
      const SmallCavityOptimizerOptions &options)
    {
      if(!options.enforceSizeMap) return true;
      const std::size_t boundaryCount = boundaryUv.size();
      if(boundaryXyz.size() != boundaryCount) return false;
      std::set<std::pair<std::size_t, std::size_t> > chords;
      for(const auto &quad : quadrangles)
        for(std::size_t i = 0; i < 4; ++i) {
          std::size_t a = quad[i], b = quad[(i + 1) % 4];
          if(a > b) std::swap(a, b);
          const std::pair<std::size_t, std::size_t> edge = {a, b};
          if(b < boundaryCount &&
             !isFixedCavityBoundaryEdge(edge, boundaryCount))
            chords.insert(edge);
        }
      SizeScore score;
      score.admissible = true;
      double error = 0.;
      for(const auto &edge : chords) {
        const UV midpointUv = {
          .5 * (boundaryUv[edge.first][0] + boundaryUv[edge.second][0]),
          .5 * (boundaryUv[edge.first][1] + boundaryUv[edge.second][1])};
        const Point midpointXyz = {
          .5 * (boundaryXyz[edge.first][0] +
                boundaryXyz[edge.second][0]),
          .5 * (boundaryXyz[edge.first][1] +
                boundaryXyz[edge.second][1]),
          .5 * (boundaryXyz[edge.first][2] +
                boundaryXyz[edge.second][2])};
        accumulateSizeEdge(
          score, error,
          edgeLengthCriteria(face, midpointUv, midpointXyz, options),
          distance(boundaryXyz[edge.first], boundaryXyz[edge.second]),
          true);
      }
      return score.admissible;
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
      CavityPurpose kind, const FaceHalfEdgeTopology &topology,
      bool criticalShapeOnly = false,
      const std::set<MVertex *> *focusVertices = nullptr,
      const CavityCoreAttemptStateBuilder *attemptStateBuilder = nullptr,
      const RejectedCavityStateSet *rejectedCavityAttempts = nullptr)
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
      const auto edges = kind == CavityPurpose::CleanUpSize ?
        topology.edges() :
        std::vector<std::pair<Edge, std::vector<MElement *> > >();

      std::vector<CavitySeed> cavities;
      std::set<std::vector<HalfEdgeMesh::Index> > signatures;
      auto add = [&](const HalfEdgeMesh::Cavity &cavity,
                     bool alwaysTryTopology = false) {
        if(cavity.faces.empty() || cavity.faces != cavity.coreFaces ||
           cavity.faces.size() > static_cast<std::size_t>(
             options.maximumCleanUpCavityElements))
          return;
        std::vector<HalfEdgeMesh::Index> signature = cavity.faces;
        signature.push_back(HalfEdgeMesh::invalid);
        signature.push_back(static_cast<HalfEdgeMesh::Index>(cavity.anchor));
        signature.push_back(cavity.anchorFirst);
        signature.push_back(cavity.anchorSecond);
        signature.insert(signature.end(), cavity.anchorVertices.begin(),
                         cavity.anchorVertices.end());
        if(!signatures.insert(signature).second) return;

        CavityStateSignature attemptState;
        const bool cacheable = attemptStateBuilder &&
          (*attemptStateBuilder)(cavity, kind, attemptState);
        // Preserve every entry through the non-stable sort. Cache hits are
        // skipped by optimizeCleanUpStage() only after this full ordering has
        // been reproduced, so equal-priority live candidates do not move.

        const std::vector<MElement *> patchElements =
          topology.elements(cavity);
        if(patchElements.size() != cavity.faces.size()) return;
        for(MElement *element : patchElements)
          if(!element || element->getNumPrimaryVertices() != 4) return;

        CavitySeed seed;
        if(!materializeCavitySeed(
             face, cavity, topology, seed,
             !useFastInteractiveCleanUp(options)) ||
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
        seed.attemptStateCacheable = cacheable;
        seed.attemptState = std::move(attemptState);
        seed.objective = specificationObjective(seed.patch.elements);
        cacheCavityValence(seed, topology);
        cavities.push_back(std::move(seed));
      };

      auto expandAndAdd = [&](const HalfEdgeMesh::Cavity &initial,
                              bool alwaysTryTopology = false,
                              int additionalRings = -1) {
        HalfEdgeMesh::Cavity current = initial;
        add(current, alwaysTryTopology);
        const std::vector<MElement *> initialElements =
          topology.elements(current);
        std::set<MElement *> patch(
          initialElements.begin(), initialElements.end());
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
          const std::vector<MElement *> ordered(patch.begin(), patch.end());
          HalfEdgeMesh::Cavity expandedCavity;
          if(!topology.cavityFromElements(
               ordered, initial, expandedCavity))
            break;
          current = std::move(expandedCavity);
          add(current, alwaysTryTopology);
        }
      };

      if(kind == CavityPurpose::CleanUpConnectivity) {
        const std::vector<MVertex *> vertices = focusVertices ?
          std::vector<MVertex *>(focusVertices->begin(),
                                 focusVertices->end()) :
          topology.vertices();
        for(MVertex *vertex : vertices) {
          // Connectivity patterns are centered on interior half-edge stars.
          // A mesh-boundary vertex can still be classified on the GFace
          // (notably after importing an OCC test mesh); treating it as an
          // interior valence defect can create an arbitrary interior disk.
          // Boundary-specific rewrites own such open stars.
          HalfEdgeMesh::Cavity vertexCavity;
          if(!vertex || vertex->onWhat() != face ||
             !topology.cavityAroundVertex(vertex, vertexCavity) ||
             vertexCavity.anchorOnBoundary)
            continue;
          const std::size_t degree = topology.quadDegree(vertex);
          if(degree == 4) {
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
          expandAndAdd(vertexCavity);
        }
      }
      else if(kind == CavityPurpose::CleanUpBoundary) {
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
          HalfEdgeMesh::Cavity vertexCavity;
          if((degree != ideal || wideTwoEdgeBoundary) &&
             topology.cavityAroundVertex(vertex, vertexCavity) &&
             vertexCavity.anchorOnBoundary)
            expandAndAdd(vertexCavity, wideTwoEdgeBoundary,
                         wideTwoEdgeBoundary ? 1 : -1);
        }
        // Figure 15: a boundary diamond has exactly one vertex on the model
        // boundary. Its one- and two-ring patches are tried; the spec and
        // valence objective decide whether collapse is safe.
        for(MElement *element : elements) {
          if(!element || element->getNumPrimaryVertices() != 4) continue;
          std::size_t boundaryVertices = 0;
          MVertex *boundaryAnchor = nullptr;
          for(std::size_t i = 0; i < 4; ++i) {
            MVertex *vertex = element->getVertex(static_cast<int>(i));
            if(vertex && vertex->onWhat() != face) {
              ++boundaryVertices;
              boundaryAnchor = vertex;
            }
          }
          if(boundaryVertices == 1) {
            // This is a boundary-node pattern.  Anchor its one- and two-ring
            // disks at that node instead of borrowing a single-quad anchor;
            // the declared catalog contract then remains true as the disk is
            // expanded.
            HalfEdgeMesh::Cavity boundaryStar;
            if(topology.cavityAroundVertex(
                 boundaryAnchor, boundaryStar) &&
               boundaryStar.anchorOnBoundary)
              expandAndAdd(boundaryStar);
          }
        }
      }
      else if(kind == CavityPurpose::CleanUpShape) {
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
          HalfEdgeMesh::Cavity single;
          if(!topology.singleQuadrangleCavity(element, single)) continue;
          expandAndAdd(single);
          for(MElement *neighbor : topology.neighbors(element)) {
            HalfEdgeMesh::Cavity pair;
            if(topology.cavityFromElements(
                 {element, neighbor}, single, pair))
              expandAndAdd(pair);
          }
        }
      }
      else if(kind == CavityPurpose::CleanUpSize) {
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
          if(violatesConfiguredBounds || isLegacyLongEdge) {
            HalfEdgeMesh::Cavity edgeCavity;
            if(topology.cavityAroundEdge(entry.first, edgeCavity))
              expandAndAdd(edgeCavity);
          }
        }
      }

      std::sort(cavities.begin(), cavities.end(),
                [kind](const CavitySeed &a, const CavitySeed &b) {
                  if(kind == CavityPurpose::CleanUpConnectivity ||
                     kind == CavityPurpose::CleanUpBoundary) {
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

    // A QQ swap changes only the diagonal of a six-vertex polygon. For this
    // operation the relevant angular quality is the minimax equiangular
    // metric: minimize the worst corner's distance from 90 degrees. The
    // aggregate skewing criterion alone can reject a large improvement of an
    // almost-flat corner because the error is redistributed over several
    // otherwise admissible corners. Keep warping and edge ratio as hard
    // non-angular guards; orientation and CAD/size guards are enforced by the
    // common transactional evaluation.
    struct QuadEquiangularObjective {
      bool admissible = true;
      double worstDeviation = 0.;
    };

    void addQuadEquiangularQuality(
      const ElementQuality &quality, QuadEquiangularObjective &objective)
    {
      if(quality.kind != SurfaceElementKind::Quadrangle ||
         !quality.topologicallyValid ||
         !std::isfinite(quality.minimumAngleDegrees) ||
         !std::isfinite(quality.maximumAngleDegrees) ||
         !(quality.warpingDegrees < absoluteMaximumQuadWarpingDegrees) ||
         !(quality.edgeRatio < 10.)) {
        objective.admissible = false;
        objective.worstDeviation =
          std::numeric_limits<double>::infinity();
        return;
      }
      objective.worstDeviation = std::max(
        objective.worstDeviation,
        std::max(std::abs(quality.minimumAngleDegrees - 90.),
                 std::abs(quality.maximumAngleDegrees - 90.)));
    }

    QuadEquiangularObjective quadEquiangularObjective(
      const std::vector<MElement *> &elements)
    {
      QuadEquiangularObjective objective;
      for(MElement *element : elements) {
        if(!element || element->getNumPrimaryVertices() != 4) {
          objective.admissible = false;
          objective.worstDeviation =
            std::numeric_limits<double>::infinity();
          break;
        }
        addQuadEquiangularQuality(
          evaluateElementQuality(element), objective);
        if(!objective.admissible) break;
      }
      return objective;
    }

    QuadEquiangularObjective quadEquiangularObjective(
      const Pattern &quadrangles, const std::vector<Point> &xyz)
    {
      QuadEquiangularObjective objective;
      for(const auto &quadrangle : quadrangles) {
        std::vector<Point> points(4);
        for(std::size_t i = 0; i < 4; ++i) {
          if(quadrangle[i] >= xyz.size()) {
            objective.admissible = false;
            objective.worstDeviation =
              std::numeric_limits<double>::infinity();
            return objective;
          }
          points[i] = xyz[quadrangle[i]];
        }
        addQuadEquiangularQuality(
          evaluateElementQuality(SurfaceElementKind::Quadrangle, points),
          objective);
        if(!objective.admissible) break;
      }
      return objective;
    }

    bool improvesQuadEquiangularObjective(
      const QuadEquiangularObjective &candidate,
      const QuadEquiangularObjective &reference, double tolerance)
    {
      if(!candidate.admissible || !reference.admissible) return false;
      return candidate.worstDeviation + tolerance * std::max(
        {1., candidate.worstDeviation, reference.worstDeviation}) <
        reference.worstDeviation;
    }

    double maximumCandidateWarpingDegrees(
      const Pattern &quadrangles, const std::vector<Point> &xyz)
    {
      double maximum = 0.;
      for(const auto &quad : quadrangles) {
        std::vector<Point> points(4);
        for(std::size_t i = 0; i < quad.size(); ++i) {
          if(quad[i] >= xyz.size())
            return std::numeric_limits<double>::infinity();
          points[i] = xyz[quad[i]];
        }
        const ElementQuality quality = evaluateElementQuality(
          SurfaceElementKind::Quadrangle, points);
        if(!std::isfinite(quality.warpingDegrees))
          return std::numeric_limits<double>::infinity();
        maximum = std::max(maximum, quality.warpingDegrees);
      }
      return maximum;
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
      return closestPointDistanceCached(
        face, midpointUv, midpointXyz, deviation);
    }

    struct EdgeMidpointCadSwapAssessment {
      bool valid = false;
      bool referenceCritical = false;
      bool strongImprovement = false;
      double referenceRatio = std::numeric_limits<double>::infinity();
      double candidateRatio = std::numeric_limits<double>::infinity();
    };

    EdgeMidpointCadSwapAssessment assessEdgeMidpointCadSwap(
      double referenceDistance,
      const EdgeLengthCriteria &referenceCriteria,
      double candidateDistance,
      const EdgeLengthCriteria &candidateCriteria,
      const SmallCavityOptimizerOptions &options)
    {
      EdgeMidpointCadSwapAssessment assessment;
      if(!std::isfinite(referenceDistance) || referenceDistance < 0. ||
         !std::isfinite(candidateDistance) || candidateDistance < 0. ||
         !validEdgeLengthCriteria(referenceCriteria) ||
         !validEdgeLengthCriteria(candidateCriteria) ||
         !std::isfinite(options.edgeMidpointCadSwapTriggerRatio) ||
         options.edgeMidpointCadSwapTriggerRatio < 0. ||
         !std::isfinite(
           options.edgeMidpointCadSwapMaximumRemainingFraction) ||
         options.edgeMidpointCadSwapMaximumRemainingFraction < 0. ||
         options.edgeMidpointCadSwapMaximumRemainingFraction >= 1.)
        return assessment;
      assessment.referenceRatio =
        referenceDistance / referenceCriteria.target;
      // Compare both chords with the same local scale. Using the target at
      // the candidate midpoint as a second denominator could make a larger
      // absolute CAD error appear to be an improvement in a varying field.
      assessment.candidateRatio =
        candidateDistance / referenceCriteria.target;
      if(!std::isfinite(assessment.referenceRatio) ||
         !std::isfinite(assessment.candidateRatio))
        return assessment;
      assessment.valid = true;
      const double scale = std::max(
        {1., std::abs(assessment.referenceRatio),
         std::abs(assessment.candidateRatio),
         std::abs(options.edgeMidpointCadSwapTriggerRatio)});
      const double tolerance =
        64. * std::numeric_limits<double>::epsilon() * scale;
      assessment.referenceCritical =
        assessment.referenceRatio >
        options.edgeMidpointCadSwapTriggerRatio + tolerance;
      assessment.strongImprovement = assessment.referenceCritical &&
        assessment.candidateRatio + tolerance <=
          options.edgeMidpointCadSwapMaximumRemainingFraction *
            assessment.referenceRatio;
      return assessment;
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
                                  const SupportingPlane *supportingPlane,
                                  bool useParametricChord)
    {
      if(!face || !std::isfinite(parameter[0]) ||
         !std::isfinite(parameter[1]) || !std::isfinite(areaWeight) ||
         !(areaWeight > 0.)) {
        ++deviation.invalidSampleCount;
        return false;
      }
      // Optimizer candidates use the closest-point distance: the interpolated
      // parameter is only the deterministic seed of that solve. The final
      // model-wide report uses the chord to the CAD point at the same
      // parameter instead. This conservative, deterministic metric keeps the
      // full quadrature while avoiding hundreds of thousands of nonlinear
      // projections. The optional supporting plane makes the planar report
      // exact and is computed only once per face.
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
        if(useParametricChord) {
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
        else if(!closestPointDistanceCached(
                  face, parameter, meshPoint, sampleDistance)) {
          ++deviation.invalidSampleCount;
          return false;
        }
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
      const SupportingPlane *supportingPlane = nullptr,
      bool useParametricChord = false)
    {
      // Tensor Gauss integration of squared CAD deviation over the physical
      // bilinear quad. Optimizer candidates use closest-point distance; the
      // final report uses the parametric chord. This score is additive, so two
      // alternative fillings of the same cavity can be compared without an
      // element-count bias.
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
               supportingPlane, useParametricChord))
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
      const SupportingPlane *supportingPlane = nullptr,
      bool useParametricChord = false)
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
             supportingPlane, useParametricChord))
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
             face, uv, xyz, deviation, supportingPlane, true))
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
             face, uv, xyz, deviation, supportingPlane, true))
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

    bool executeCandidate(GFace *face, const CavitySeed &seed,
                          const Candidate &candidate,
                          FaceHalfEdgeTopology &topology,
                          std::vector<MVertex *> *createdInterior = nullptr)
    {
      auto reject = [](const char *reason) {
        if(Msg::GetVerbosity() > 5)
          Msg::Info("QuadOptimizer executeCandidate reject reason=%s",
                    reason);
        return false;
      };
      if(!candidate.valid) return reject("unevaluated-candidate");
      if(touchesBoundaryLayerElementData(face, seed.patch.elements))
        return reject("boundary-layer");
      const std::size_t boundaryCount = seed.patch.bdrVertices.front().size();
      std::vector<MVertex *> localVertices = seed.patch.bdrVertices.front();
      if(candidate.interiorAssignment.size() > seed.patch.intVertices.size())
        return reject("interior-count");
      std::set<std::size_t> retainedIndices;
      for(std::size_t i = 0; i < candidate.interiorAssignment.size(); ++i) {
        const std::size_t old = candidate.interiorAssignment[i];
        if(old >= seed.patch.intVertices.size() ||
           !retainedIndices.insert(old).second)
          return reject("interior-assignment");
        localVertices.push_back(seed.patch.intVertices[old]);
      }

      const int partition = seed.patch.elements.front()->getPartition();
      const bool visibility =
        seed.patch.elements.front()->getVisibility();
      std::vector<MElement *> newElements;
      newElements.reserve(candidate.quadrangles.size());
      for(const auto &quad : candidate.quadrangles) {
        MQuadrangle *element = new MQuadrangle(
          localVertices[quad[0]], localVertices[quad[1]],
          localVertices[quad[2]], localVertices[quad[3]]);
        element->setPartition(partition);
        element->setVisibility(visibility);
        newElements.push_back(element);
      }
      if(!orientElementsAccordingToBoundarySegment(
           seed.patch.bdrVertices.front()[0],
           seed.patch.bdrVertices.front()[1], newElements)) {
        for(MElement *element : newElements) delete element;
        return reject("boundary-orientation");
      }
      // `candidate` is the exact state accepted by
      // prepareQuadCavityEvaluation(): orientation was checked on C+C' after
      // every retained core and support vertex had reached its final
      // transactional position. Rebuilding a second reference on C alone
      // here is both redundant and incorrect: vertices on the boundary of C
      // can be interior to C+C' and therefore legitimately move. Comparing
      // that moved boundary with the old C coordinates rejected valid
      // diamond collapses and edge swaps immediately before their commit.
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
      FaceRewriteTransaction transaction(topology, diff);
      if(!transaction) return reject("transaction-construction");
      if(!transaction.execute()) return reject("transaction-execution");

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
      topology.synchronizeGeometry(retainedInterior);
      if(createdInterior) *createdInterior = std::move(retainedInterior);
      return true;
    }

    bool executeValenceSixCandidate(
      GFace *face, const CavitySeed &seed, const Candidate &candidate,
      FaceHalfEdgeTopology &topology,
      std::vector<MVertex *> &resultInterior)
    {
      if(touchesBoundaryLayerElementData(face, seed.patch.elements))
        return false;
      if(seed.patch.elements.empty()) return false;
      const int partition = seed.patch.elements.front()->getPartition();
      const bool visibility =
        seed.patch.elements.front()->getVisibility();
      for(MElement *element : seed.patch.elements)
        if(!element || element->getPartition() != partition ||
           element->getVisibility() != visibility)
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
      for(const auto &quad : candidate.quadrangles) {
        MQuadrangle *element = new MQuadrangle(localVertices[quad[0]],
                                               localVertices[quad[1]],
                                               localVertices[quad[2]],
                                               localVertices[quad[3]]);
        element->setPartition(partition);
        element->setVisibility(visibility);
        newElements.push_back(element);
      }
      if(!orientElementsAccordingToBoundarySegment(
           seed.patch.bdrVertices.front()[0],
           seed.patch.bdrVertices.front()[1], newElements)) {
        for(MElement *element : newElements) delete element;
        delete created;
        return false;
      }
      if(!replacementElementsPreserveSurfaceOrientation(
           face, seed.patch.elements, newElements, localVertices, candidate.uv,
           candidate.xyz)) {
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
      FaceRewriteTransaction transaction(topology, diff);
      if(!transaction || !transaction.execute()) return false;

      existing->setXYZ(candidate.xyz[boundaryCount][0],
                       candidate.xyz[boundaryCount][1],
                       candidate.xyz[boundaryCount][2]);
      existing->setParameter(0, candidate.uv[boundaryCount][0]);
      existing->setParameter(1, candidate.uv[boundaryCount][1]);
      resultInterior = {existing, created};
      topology.synchronizeGeometry(resultInterior);
      return true;
    }

    bool executeNewInteriorCandidate(
      GFace *face, const CavitySeed &seed, const Candidate &candidate,
      FaceHalfEdgeTopology &topology, MVertex *&createdInterior)
    {
      if(touchesBoundaryLayerElementData(face, seed.patch.elements))
        return false;
      const std::size_t boundaryCount =
        seed.patch.bdrVertices.front().size();
      if(!seed.patch.intVertices.empty() ||
         seed.patch.elements.empty() ||
         candidate.uv.size() != boundaryCount + 1 ||
         candidate.xyz.size() != boundaryCount + 1)
        return false;
      const int partition = seed.patch.elements.front()->getPartition();
      const bool visibility = seed.patch.elements.front()->getVisibility();
      for(MElement *element : seed.patch.elements)
        if(!element || element->getPartition() != partition ||
           element->getVisibility() != visibility)
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
      for(const auto &quad : candidate.quadrangles) {
        MQuadrangle *element = new MQuadrangle(
          localVertices[quad[0]], localVertices[quad[1]],
          localVertices[quad[2]], localVertices[quad[3]]);
        element->setPartition(partition);
        element->setVisibility(visibility);
        newElements.push_back(element);
      }
      if(!orientElementsAccordingToBoundarySegment(
           seed.patch.bdrVertices.front()[0],
           seed.patch.bdrVertices.front()[1], newElements)) {
        for(MElement *element : newElements) delete element;
        delete created;
        return false;
      }
      if(!replacementElementsPreserveSurfaceOrientation(
           face, seed.patch.elements, newElements, localVertices, candidate.uv,
           candidate.xyz)) {
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
      FaceRewriteTransaction transaction(topology, diff);
      if(!transaction || !transaction.execute()) return false;
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

      const int partition = seed.patch.elements.front()->getPartition();
      const bool visibility =
        seed.patch.elements.front()->getVisibility();
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
        MQuadrangle *element = new MQuadrangle(
          localVertices[quad[0]], localVertices[quad[1]],
          localVertices[quad[2]], localVertices[quad[3]]);
        element->setPartition(partition);
        element->setVisibility(visibility);
        newElements.push_back(element);
      }
      if(!orientElementsAccordingToBoundarySegment(
           seed.patch.bdrVertices.front()[0],
           seed.patch.bdrVertices.front()[1], newElements)) {
        for(MElement *element : newElements) delete element;
        for(MVertex *vertex : created) delete vertex;
        return false;
      }
      if(!replacementElementsPreserveSurfaceOrientation(
           face, seed.patch.elements, newElements, localVertices, candidate.uv,
           candidate.xyz)) {
        for(MElement *element : newElements) delete element;
        for(MVertex *vertex : created) delete vertex;
        return false;
      }

      // Validate the complete topological transaction before GFaceMeshDiff
      // deletes any old element or vertex. In particular, a duplicate quad
      // would otherwise create four third edge incidences and leave both the
      // mesh and the side-car half-edge index partially modified.
      if(!topology) {
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
      FaceRewriteTransaction transaction(*topology, diff);
      if(!transaction || !transaction.execute()) return false;

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
      topology->synchronizeGeometry(resultInterior);
      return true;
    }

    bool interiorVertexCavity(GFace *face,
                              const std::vector<MVertex *> &interior,
                              const FaceHalfEdgeTopology &topology,
                              CavitySeed &seed,
                              bool canonicalize = true,
                              bool requireEvenBoundary = true)
    {
      if(interior.empty()) return false;
      for(MVertex *vertex : interior)
        if(!vertex || vertex->onWhat() != face) return false;
      HalfEdgeMesh::Cavity cavity;
      if(!topology.cavityAroundVertices(interior, cavity) ||
         cavity.anchorOnBoundary ||
         !materializeCavitySeed(
           face, cavity, topology, seed, canonicalize) ||
         seed.patch.bdrVertices.size() != 1 ||
         seed.patch.bdrVertices.front().size() < 3 ||
         (requireEvenBoundary &&
          seed.patch.bdrVertices.front().size() % 2 != 0) ||
         !seed.patch.embVertices.empty() ||
         !sameVertices(seed.patch.intVertices, interior))
        return false;
      seed.interiorVertexCount = interior.size();
      seed.objective = specificationObjective(seed.patch.elements);
      return true;
    }

    std::vector<CavitySeed> collectOpposedQuadStarSmoothingCavities(
      GFace *face, const SmallCavityOptimizerOptions &options,
      const FaceHalfEdgeTopology &topology)
    {
      std::vector<CavitySeed> cavities;
      if(!face || face->geomType() != GEntity::DiscreteSurface ||
         !topology.manifold())
        return cavities;

      std::set<std::vector<std::uintptr_t> > signatures;
      for(MElement *element : topology.elements()) {
        MQuadrangle *quadrangle = dynamic_cast<MQuadrangle *>(element);
        if(!quadrangle) continue;
        const ElementQuality quality = evaluateElementQuality(quadrangle);
        // GFace sampling is deliberately behind a cheap shape predicate. All
        // residual opposed Doghouse cells are already absolute failures, and
        // a compliant quad must not make the terminal fast path scan every
        // GFace normal merely to confirm that there is no work.
        if(quality.topologicallyValid &&
           quality.passesAbsoluteSpecifications)
          continue;
        if(surfaceElementCadNormalSign(face, quadrangle) >= 0) continue;

        std::vector<MVertex *> movable;
        for(std::size_t i = 0; i < 4; ++i) {
          MVertex *vertex = quadrangle->getVertex(static_cast<int>(i));
          if(vertex && vertex->onWhat() == face &&
             !topology.isBoundaryVertex(vertex))
            movable.push_back(vertex);
        }
        std::sort(movable.begin(), movable.end(),
                  canonicalVertexGeometryLess);
        movable.erase(std::unique(movable.begin(), movable.end()),
                      movable.end());
        if(movable.empty()) continue;

        // Four quad vertices give at most fifteen subsets. Opening complete
        // half-edge stars makes exactly those vertices genuine Winslow
        // unknowns while keeping the outer ring immutable. Subsets matter:
        // the complete four-vertex star can exceed the bounded Fast catalog,
        // whereas a one-, two- or three-vertex corrective star is local.
        const std::size_t subsetCount = std::size_t(1) << movable.size();
        for(std::size_t mask = 1; mask < subsetCount; ++mask) {
          std::vector<MVertex *> interior;
          for(std::size_t i = 0; i < movable.size(); ++i)
            if(mask & (std::size_t(1) << i)) interior.push_back(movable[i]);

          CavitySeed seed;
          HalfEdgeMesh::Cavity single, quadrangleAnchored;
          if(!topology.singleQuadrangleCavity(quadrangle, single) ||
             !interiorVertexCavity(
               face, interior, topology, seed, true, false) ||
             !topology.cavityFromElements(
               seed.patch.elements, single, quadrangleAnchored) ||
             std::find(seed.patch.elements.begin(),
                       seed.patch.elements.end(), quadrangle) ==
               seed.patch.elements.end() ||
             seed.patch.elements.size() > static_cast<std::size_t>(
               options.maximumCleanUpCavityElements) ||
             seed.patch.intVertices.size() > static_cast<std::size_t>(
               std::max(0, options.maximumCleanUpInteriorVertices)) ||
             touchesBoundaryLayerElementData(face, seed.patch.elements))
            continue;

          seed.halfEdgeCavity = std::move(quadrangleAnchored);

          const int partition = seed.patch.elements.front()->getPartition();
          const bool visibility =
            seed.patch.elements.front()->getVisibility();
          bool homogeneous = true;
          std::vector<std::uintptr_t> signature;
          signature.reserve(seed.patch.elements.size());
          for(MElement *patchElement : seed.patch.elements) {
            homogeneous = homogeneous && patchElement &&
              (patchElement->getNumPrimaryVertices() == 3 ||
               patchElement->getNumPrimaryVertices() == 4) &&
              patchElement->getPartition() == partition &&
              patchElement->getVisibility() == visibility;
            signature.push_back(
              reinterpret_cast<std::uintptr_t>(patchElement));
          }
          if(!homogeneous) continue;
          std::sort(signature.begin(), signature.end());
          if(!signatures.insert(signature).second) continue;

          seed.alwaysTryTopology = true;
          seed.kind = CavityPurpose::CleanUpShape;
          seed.correctiveCadOrientation = true;
          seed.objective = specificationObjective(seed.patch.elements);
          cacheCavityValence(seed, topology);
          cavities.push_back(std::move(seed));
        }
      }
      std::stable_sort(
        cavities.begin(), cavities.end(),
        [](const CavitySeed &a, const CavitySeed &b) {
          if(a.patch.elements.size() != b.patch.elements.size())
            return a.patch.elements.size() < b.patch.elements.size();
          if(a.patch.intVertices.size() != b.patch.intVertices.size())
            return a.patch.intVertices.size() < b.patch.intVertices.size();
          return objectivePriority(a.objective) >
                 objectivePriority(b.objective);
        });
      return cavities;
    }

    bool fourInteriorVertexCavity(
      GFace *face, MQuadrangle *quadrangle,
      const FaceHalfEdgeTopology &topology, CavitySeed &seed)
    {
      std::vector<MVertex *> interior(4);
      for(int i = 0; i < 4; ++i) {
        interior[static_cast<std::size_t>(i)] = quadrangle->getVertex(i);
        if(!interior[static_cast<std::size_t>(i)] ||
           interior[static_cast<std::size_t>(i)]->onWhat() != face)
          return false;
      }
      return interiorVertexCavity(face, interior, topology, seed) &&
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
        // mesh is saved without Mesh.SaveParametric. Recover them from XYZ,
        // through the exact position-aware cache shared by all cavity
        // evaluations on this face.
        if(patch.gf->geomType() == GEntity::DiscreteSurface) {
          SPoint2 parameter;
          if(!persistentFaceParameter(patch.gf, vertex, parameter))
            return false;
          u = parameter.x();
          v = parameter.y();
        }
        else if(!vertex->getParameter(0, u) ||
                !vertex->getParameter(1, v) || !std::isfinite(u) ||
                !std::isfinite(v)) {
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

    bool existingSurfacePatternAndParametrization(
      const CavitySeed &seed, std::vector<UV> &points,
      std::vector<std::array<std::size_t, 3> > &triangles,
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

      triangles.clear();
      quadrangles.clear();
      triangles.reserve(seed.patch.elements.size());
      quadrangles.reserve(seed.patch.elements.size());
      for(MElement *element : seed.patch.elements) {
        const std::size_t count = element->getNumPrimaryVertices();
        if(count == 3) {
          std::array<std::size_t, 3> triangle;
          for(std::size_t i = 0; i < triangle.size(); ++i) {
            const auto found = index.find(
              element->getVertex(static_cast<int>(i)));
            if(found == index.end()) return false;
            triangle[i] = found->second;
          }
          triangles.push_back(triangle);
        }
        else if(count == 4) {
          std::array<std::size_t, 4> quadrangle;
          for(std::size_t i = 0; i < quadrangle.size(); ++i) {
            const auto found = index.find(
              element->getVertex(static_cast<int>(i)));
            if(found == index.end()) return false;
            quadrangle[i] = found->second;
          }
          quadrangles.push_back(quadrangle);
        }
        else {
          return false;
        }
      }
      return !triangles.empty() || !quadrangles.empty();
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
      const SmallCavityOptimizerOptions &options,
      bool requireCadNonRegression = false,
      std::vector<Candidate::VertexGeometry> *acceptedGeometry = nullptr,
      bool requireObjectiveImprovement = true,
      const std::set<MVertex *> *additionalFixedVertices = nullptr,
      const std::vector<Candidate::VertexGeometry> *initialGeometry = nullptr,
      const std::set<MVertex *> *cachedProtectedVertices = nullptr)
    {
      if(acceptedGeometry) acceptedGeometry->clear();
      const bool fastInteractive = useFastInteractiveCleanUp(options);
      seed.objective = specificationObjective(seed.patch.elements);
      if(options.topologyOnlyIfCavityHasSpecificationFailure &&
         !hasQualitySpecificationFailure(seed.objective))
        return ExistingSmoothingStatus::SkippedSpecificationCompliant;
      std::vector<UV> uv;
      std::vector<std::array<std::size_t, 3> > triangles;
      Pattern quadrangles;
      if(!existingSurfacePatternAndParametrization(
           seed, uv, triangles, quadrangles))
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

      std::set<MVertex *> localProtectedVertices;
      if(!cachedProtectedVertices)
        localProtectedVertices = protectedFaceVertices(face);
      const std::set<MVertex *> &protectedVertices = cachedProtectedVertices ?
        *cachedProtectedVertices : localProtectedVertices;
      if(initialGeometry) {
        std::set<MVertex *> overridden;
        for(const Candidate::VertexGeometry &geometry : *initialGeometry) {
          if(!geometry.vertex ||
             !std::isfinite(geometry.uv[0]) ||
             !std::isfinite(geometry.uv[1]) ||
             !std::isfinite(geometry.xyz[0]) ||
             !std::isfinite(geometry.xyz[1]) ||
             !std::isfinite(geometry.xyz[2]) ||
             !overridden.insert(geometry.vertex).second)
            return ExistingSmoothingStatus::Invalid;
          const auto found = std::find(
            seed.patch.intVertices.begin(), seed.patch.intVertices.end(),
            geometry.vertex);
          if(found == seed.patch.intVertices.end() ||
             geometry.vertex->onWhat() != face ||
             protectedVertices.find(geometry.vertex) !=
               protectedVertices.end() ||
             (additionalFixedVertices &&
              additionalFixedVertices->find(geometry.vertex) !=
                additionalFixedVertices->end()))
            return ExistingSmoothingStatus::Invalid;
          const std::size_t local = boundaryCount +
            static_cast<std::size_t>(
              found - seed.patch.intVertices.begin());
          uv[local] = geometry.uv;
          initialXyz[local] = geometry.xyz;
        }
        seed.objective = candidateMixedObjective(
          triangles, quadrangles, initialXyz);
      }

      LocalPatchOrientationReference beforeOrientation;
      const LocalPatchOrientationReference *beforeOrientationPointer =
        nullptr;
      if(face->geomType() == GEntity::DiscreteSurface) {
        const bool hasReliableOpposedSample =
          indexedPatchFollowsSampledFaceNormal(
            face, uv, initialXyz, triangles, quadrangles, -1);
        const bool haveLocalReference = buildLocalPatchOrientationReference(
          uv, initialXyz, triangles, quadrangles, beforeOrientation);
        if(!haveLocalReference) {
          // A physical fold in the input star is precisely one of the defects
          // this smoothing pass must be able to repair.  In that exceptional
          // case there is no coherent mesh-only normal field to preserve: use
          // the sampled GFace normal as the corrective oracle instead.  Do not
          // relax other failures of the local-reference construction; the
          // fallback is enabled only after observing a reliable opposed sample
          // in the unchanged input patch.
          if(!hasReliableOpposedSample)
            return ExistingSmoothingStatus::Invalid;
        }
        if(haveLocalReference && !hasReliableOpposedSample)
          beforeOrientationPointer = &beforeOrientation;
      }

      std::vector<bool> fixed(initialXyz.size(), false);
      for(std::size_t i = 0; i < boundaryCount; ++i) fixed[i] = true;
      for(std::size_t i = 0; i < seed.patch.intVertices.size(); ++i) {
        MVertex *vertex = seed.patch.intVertices[i];
        fixed[boundaryCount + i] = !vertex || vertex->onWhat() != face ||
          protectedVertices.find(vertex) != protectedVertices.end() ||
          (additionalFixedVertices &&
           additionalFixedVertices->find(vertex) !=
             additionalFixedVertices->end());
      }

      double twiceSurfaceBoundaryArea = 0.;
      double surfaceBoundaryScale2 = 0.;
      for(std::size_t i = 0; i < boundaryCount; ++i) {
        const UV &a = uv[i];
        const UV &b = uv[(i + 1) % boundaryCount];
        twiceSurfaceBoundaryArea += a[0] * b[1] - a[1] * b[0];
        surfaceBoundaryScale2 = std::max(
          surfaceBoundaryScale2,
          std::pow(b[0] - a[0], 2) + std::pow(b[1] - a[1], 2));
      }
      if(!std::isfinite(twiceSurfaceBoundaryArea) ||
         std::abs(twiceSurfaceBoundaryArea) <=
           1.e-12 * std::max(
             surfaceBoundaryScale2,
             std::numeric_limits<double>::min()))
        return ExistingSmoothingStatus::Invalid;
      const double surfaceOrientation =
        twiceSurfaceBoundaryArea > 0. ? 1. : -1.;

      auto elementsHaveExpectedOrientation =
        [&](const auto &elements, const std::vector<UV> &points) {
          for(const auto &element : elements) {
            double twiceArea = 0.;
            double scale2 = 0.;
            for(std::size_t i = 0; i < element.size(); ++i) {
              if(element[i] >= points.size() ||
                 element[(i + 1) % element.size()] >= points.size())
                return false;
              const UV &a = points[element[i]];
              const UV &b = points[element[(i + 1) % element.size()]];
              if(!std::isfinite(a[0]) || !std::isfinite(a[1]) ||
                 !std::isfinite(b[0]) || !std::isfinite(b[1]))
                return false;
              twiceArea += a[0] * b[1] - a[1] * b[0];
              scale2 = std::max(
                scale2, std::pow(b[0] - a[0], 2) +
                          std::pow(b[1] - a[1], 2));
            }
            const double tolerance = 1.e-12 * std::max(
              scale2, std::numeric_limits<double>::min());
            if(!std::isfinite(twiceArea) ||
               surfaceOrientation * twiceArea <= tolerance)
              return false;
          }
          return true;
        };

      // Compare size on exactly the same mixed connectivity and immutable
      // edge support as the candidate. In particular, fixed/fixed boundary
      // edges must not manufacture a smoothing improvement.
      const SizeScore beforeSize = surfacePatchSizeScore(
        face, uv, initialXyz, triangles, quadrangles, fixed, options);
      const std::size_t beforeSizeViolations =
        beforeSize.belowMinimum + beforeSize.aboveMaximum +
        beforeSize.invalid;
      GeometryDeviation referenceGeometry;
      if(requireCadNonRegression) {
        referenceGeometry = existingGeometryDeviation(
          face, seed.patch.elements);
        if(!referenceGeometry.valid)
          return ExistingSmoothingStatus::RejectedQuality;
      }
      bool rejectedBySize = false;
      auto acceptTrial = [&](const std::vector<UV> &trialUv,
                             const std::vector<Point> &trialXyz) {
        SizeScore afterSize;
        if(options.enforceSizeMap || fastInteractive)
          afterSize = surfacePatchSizeScore(
            face, trialUv, trialXyz, triangles, quadrangles, fixed,
            options);
        const std::size_t trialSizeViolations =
          afterSize.belowMinimum + afterSize.aboveMaximum +
          afterSize.invalid;
        if(options.enforceSizeMap &&
           (trialSizeViolations > beforeSizeViolations ||
            !admissibleSizeChange(beforeSize, afterSize, options))) {
          rejectedBySize = true;
          return false;
        }
        if(!elementsHaveExpectedOrientation(triangles, trialUv) ||
           !elementsHaveExpectedOrientation(quadrangles, trialUv))
          return false;
        if(!quadrangles.empty() &&
           !candidateQuadranglesAreNonConcave(
             quadrangles, trialUv, trialXyz))
          return false;
        const SpecificationObjective objective = candidateMixedObjective(
          triangles, quadrangles, trialXyz);
        if(objective.invalidElementCount != 0)
          return false;
        if(seed.correctiveCadOrientation &&
           !noWorseAbsoluteSpecifications(
             objective, seed.objective,
             options.objectiveRelativeTolerance))
          return false;
        const std::size_t afterSizeViolations =
          afterSize.belowMinimum + afterSize.aboveMaximum +
          afterSize.invalid;
        if(requireObjectiveImprovement) {
          bool improves = false;
          if(fastInteractive) {
            improves = improvesCleanUpSmoothing(
              objective, seed.objective, afterSizeViolations,
              beforeSizeViolations, afterSize.meanSquaredLogRatio,
              beforeSize.meanSquaredLogRatio,
              options.objectiveRelativeTolerance);
          }
          else {
            improves = improvesSpecificationObjective(
              objective, seed.objective,
              options.objectiveRelativeTolerance);
          }
          if(!improves)
            return false;
        }
        // The sampled GFace guard is exact but substantially more expensive
        // on a discrete support than the intrinsic, size and objective
        // predicates above. It has no side effects, so defer it until the
        // candidate has passed every cheaper rejection gate.
        const bool preservesSurfaceOrientation =
          face->geomType() == GEntity::DiscreteSurface &&
              !beforeOrientationPointer ?
            indexedPatchFollowsSampledFaceNormal(
              face, trialUv, trialXyz, triangles, quadrangles) :
            indexedPatchPreservesSurfaceOrientation(
              face, beforeOrientationPointer, trialUv, trialXyz,
              triangles, quadrangles);
        if(!preservesSurfaceOrientation)
          return false;
        if(requireCadNonRegression) {
          const GeometryDeviation geometry =
            candidateMixedGeometryDeviation(
              face, trialUv, trialXyz, triangles, quadrangles);
          if(!geometryDoesNotRegressBeyondRoundoff(
               geometry, referenceGeometry))
            return false;
        }
        if(acceptedGeometry) {
          acceptedGeometry->clear();
          for(std::size_t i = 0; i < seed.patch.intVertices.size(); ++i) {
            const std::size_t local = boundaryCount + i;
            if(fixed[local]) continue;
            acceptedGeometry->push_back(
              {seed.patch.intVertices[i], trialUv[local],
               trialXyz[local]});
          }
        }
        else {
          applySmoothedGeometry(seed, trialUv, trialXyz);
        }
        return true;
      };

      Point origin, firstAxis, secondAxis;
      std::vector<UV> planePoints;
      if(!meanPlaneChart(initialXyz, triangles, quadrangles, origin,
                         firstAxis, secondAxis, planePoints))
        return ExistingSmoothingStatus::RejectedWinslow;
      const std::vector<UV> initialPlanePoints = planePoints;
      SmallCavityWinslowOptions winslowOptions = options.winslow;
      winslowOptions.harmonicInitialization = false;
      SmallCavityWinslowResult winslow;
      const bool hasFixedInterior = std::any_of(
        fixed.begin() + static_cast<std::ptrdiff_t>(boundaryCount),
        fixed.end(), [](bool isFixed) { return isFixed; });
      if(triangles.empty() && !hasFixedInterior) {
        winslow = optimizeSmallQuadCavityWinslow(
          planePoints, boundaryCount, quadrangles, winslowOptions);
      }
      else {
        double twicePlaneBoundaryArea = 0.;
        double planeBoundaryScale2 = 0.;
        for(std::size_t i = 0; i < boundaryCount; ++i) {
          const UV &a = planePoints[i];
          const UV &b = planePoints[(i + 1) % boundaryCount];
          twicePlaneBoundaryArea += a[0] * b[1] - a[1] * b[0];
          planeBoundaryScale2 = std::max(
            planeBoundaryScale2,
            std::pow(b[0] - a[0], 2) +
              std::pow(b[1] - a[1], 2));
        }
        if(!std::isfinite(twicePlaneBoundaryArea) ||
           std::abs(twicePlaneBoundaryArea) <=
             1.e-12 * std::max(
               planeBoundaryScale2,
               std::numeric_limits<double>::min()))
          return ExistingSmoothingStatus::RejectedWinslow;
        try {
          winslow = optimizeLocalSurfacePatchWinslow(
            planePoints, fixed, triangles, quadrangles,
            twicePlaneBoundaryArea > 0. ? 1. : -1., winslowOptions);
        }
        catch(const std::exception &) {
          return ExistingSmoothingStatus::RejectedWinslow;
        }
      }
      if(!winslow.success || !winslow.untangled)
        return ExistingSmoothingStatus::RejectedWinslow;

      // The Winslow unknowns live only in the local physical mean plane.
      // Project the optimized targets back onto the MAT surface with a
      // closest-point query, using the stored UV solely as an initial guess
      // and as Gmsh's required surface-coordinate bookkeeping.
      // A topology rewrite can already be admissible at the current support
      // coordinates even when every nonzero Winslow displacement regresses
      // size or CAD fit. Include the zero step as the final line-search
      // fallback: acceptTrial still enforces orientation, convexity, absolute
      // quality, size and CAD, and the outer rewrite still has to improve its
      // own objective before a commit is possible.
      for(const double fraction : {1., .8, .6, .4, .25, .1, 0.}) {
        std::vector<UV> trialUv = uv;
        std::vector<Point> trialXyz = initialXyz;
        bool valid = true;
        for(std::size_t i = boundaryCount; i < planePoints.size(); ++i) {
          if(fixed[i]) continue;
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
          const GPoint projected =
            face->closestPointFromTrustedGuess(target, initialGuess);
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

    // Complete transactional support used by topology rewrites that keep
    // their vertices (T-Q swaps, T-Q^n-T reductions, triangle swaps, ...).
    // The core alone has no interior unknown: all of its vertices appear on
    // the core boundary, so running Winslow on that disk is a no-op.  Extend
    // the patch with the complete stars of the movable core vertices.  They
    // then become true interior unknowns, while the outer one-ring boundary
    // stays fixed.  No MVertex is moved until the topology transaction has
    // been accepted and committed.
    struct CavityEvaluationMetrics {
      SpecificationObjective referenceObjective;
      SpecificationObjective candidateObjective;
      SizeScore referenceSize;
      SizeScore candidateSize;
      GeometryDeviation referenceGeometry;
      GeometryDeviation candidateGeometry;
    };

    // Ephemeral transaction token for one rewrite.  The persistent topology
    // remains the pointer-free HalfEdgeMesh; this object merely binds the
    // exact C/C' identities, the Winslow state and the metrics which were
    // validated together before a Gmsh transaction is allowed to commit.
    struct SmoothedCavityEvaluation {
      HalfEdgeMesh::Cavity core;    // C
      HalfEdgeMesh::Cavity support; // C + C'
      GFaceMeshPatch beforePatch;
      GFaceMeshPatch afterPatch;
      std::vector<MVertex *> vertices;
      std::unordered_map<MVertex *, std::size_t> index;
      std::vector<UV> uv;
      std::vector<Point> xyz;
      std::vector<bool> fixed;
      std::vector<std::array<std::size_t, 3> > triangles;
      Pattern quadrangles;
      std::vector<Candidate::VertexGeometry> movedVertices;
      CavityEvaluationMetrics metrics;
      bool admissible = false;
    };

    // Immutable half of a C+C' transaction. All candidate connectivities of
    // one core share this numeric support, source patch and orientation
    // reference. Preparing them once avoids rebuilding the same stars and
    // resampling the same source normals for every candidate pattern.
    struct CavityEvaluationReference {
      HalfEdgeMesh::Cavity core;
      HalfEdgeMesh::Cavity support;
      GFaceMeshPatch beforePatch;
      std::vector<MElement *> beforeElements;
      LocalPatchOrientationReference beforeOrientation;
      SpecificationObjective objective;
      SizeScore size;
      mutable GeometryDeviation geometry;
      mutable bool geometryEvaluated = false;
      bool sizeReusable = false;
      bool useBeforeOrientation = false;
      bool valid = false;
    };

    using CavityPreCadGate =
      std::function<bool(const SmoothedCavityEvaluation &)>;

    bool prepareCavityEvaluationReference(
      GFace *face, const std::vector<MElement *> &removed,
      const FaceHalfEdgeTopology &topology,
      const SmallCavityOptimizerOptions &options,
      const HalfEdgeMesh::Cavity &numericCore,
      const std::set<MVertex *> *additionalProtectedVertices,
      CavityEvaluationReference &reference)
    {
      reference = CavityEvaluationReference();
      if(!face || removed.empty() || !topology.manifold()) return false;

      const std::set<MElement *> removedSet(removed.begin(), removed.end());
      const std::vector<MElement *> numericElements =
        topology.elements(numericCore);
      const std::set<MElement *> numericSet(
        numericElements.begin(), numericElements.end());
      if(numericCore.faces.empty() ||
         numericCore.faces != numericCore.coreFaces ||
         numericElements.size() != numericCore.faces.size() ||
         numericSet != removedSet) {
        if(options.verbose > 1)
          Msg::Info("QuadOptimizer C+C': stale or mismatched numeric core");
        return false;
      }
      reference.core = numericCore;

      const std::set<MVertex *> &protectedVertices =
        topology.protectedVertices(face);
      auto isProtected = [&](MVertex *vertex) {
        return protectedVertices.find(vertex) != protectedVertices.end() ||
          (additionalProtectedVertices &&
           additionalProtectedVertices->find(vertex) !=
             additionalProtectedVertices->end());
      };
      std::set<MVertex *> coreVertices;
      for(MElement *element : removed) {
        if(!element) continue;
        const std::size_t count = element->getNumPrimaryVertices();
        for(std::size_t i = 0; i < count; ++i)
          coreVertices.insert(element->getVertex(static_cast<int>(i)));
      }
      std::vector<MVertex *> supportCenters;
      for(MVertex *vertex : coreVertices) {
        if(!vertex || vertex->onWhat() != face || isProtected(vertex) ||
           !topology.containsVertex(vertex))
          continue;
        supportCenters.push_back(vertex);
      }

      reference.support = numericCore;
      // In the staged algorithm no candidate is locally smoothed: vertices
      // outside C are byte-for-byte unchanged and cancel from every quality,
      // size and geometry delta. Extending C to all of their stars is not
      // only wasted work; for a boundary diamond C is already the union of
      // the two pole stars and a second extension can produce a non-disk
      // support which rejects the valid collapse as "invalid before patch".
      const bool needsSmoothingHalo =
        !options.stagedTopologyThenQuality &&
        !options.evaluateCandidatesWithoutLocalSmoothing;
      if(needsSmoothingHalo && !supportCenters.empty() &&
         !topology.extendCavityByVertexStars(
           numericCore, supportCenters, reference.support)) {
        if(options.verbose > 1)
          Msg::Info("QuadOptimizer C+C': rejected numeric support cavity");
        return false;
      }
      reference.beforeElements = topology.elements(reference.support);
      if(reference.beforeElements.empty()) {
        if(options.verbose > 1)
          Msg::Info("QuadOptimizer C+C': empty numeric support cavity");
        return false;
      }
      if(!canonicalPatchFromElements(
           face, reference.beforeElements, reference.beforePatch) ||
         reference.beforePatch.bdrVertices.size() != 1 ||
         reference.beforePatch.bdrVertices.front().size() < 3 ||
         !reference.beforePatch.embVertices.empty()) {
        if(options.verbose > 1)
          Msg::Info("QuadOptimizer C+C': invalid before patch");
        return false;
      }

      if(face->geomType() == GEntity::DiscreteSurface) {
        if(options.stagedTopologyThenQuality) {
          // A staged rewrite is meant to repair bad elements without moving
          // their vertices. Do not require the replacement to reproduce the
          // normal field of the old C+C' patch: a flat or strongly warped
          // source quad makes that field unreliable and would veto precisely
          // the QQ swaps and diamond collapses which repair it. The final
          // candidate guard below still checks every triangle/quad sample
          // against the immutable PACK normal atlas (and falls back to the
          // discrete surface normal when the atlas cannot certify a sign).
          reference.useBeforeOrientation = false;
        }
        else {
          const bool haveLocalReference = buildLocalPatchOrientationReference(
            face, reference.beforeElements, reference.beforeOrientation);
          const bool hasReliableOpposedSample = std::any_of(
            reference.beforeElements.begin(), reference.beforeElements.end(),
            [&](MElement *element) {
              return surfaceElementCadNormalSign(face, element) < 0;
            });
          if(!haveLocalReference && !hasReliableOpposedSample) return false;
          reference.useBeforeOrientation =
            haveLocalReference && !hasReliableOpposedSample;
        }
      }
      reference.objective =
        specificationObjective(reference.beforePatch.elements);
      if(!options.edgeLengthCriteriaAt) {
        reference.size =
          existingSizeScore(reference.beforePatch, options, false);
        reference.sizeReusable = true;
      }
      reference.valid = true;
      return true;
    }

    bool prepareSmoothedCavityEvaluation(
      GFace *face, const std::vector<MElement *> &removed,
      const std::vector<MElement *> &inserted,
      const FaceHalfEdgeTopology &topology,
      const SmallCavityOptimizerOptions &options,
      SmoothedCavityEvaluation &evaluation,
      const HalfEdgeMesh::Cavity &numericCore,
      const std::set<MVertex *> *additionalProtectedVertices = nullptr,
      const std::vector<Candidate::VertexGeometry> *initialGeometry = nullptr,
      bool acceptAdmissibleInitialGeometry = false,
      bool deferCadRegressionToOuterObjective = false,
      const CavityEvaluationReference *preparedReference = nullptr,
      const CavityPreCadGate *preCadGate = nullptr,
      bool allowAbsoluteSpecificationTradeoff = false)
    {
      evaluation = SmoothedCavityEvaluation();
      if(!face || removed.empty() || inserted.empty() ||
         !topology.manifold())
        return false;

      CavityEvaluationReference localReference;
      const CavityEvaluationReference *reference = preparedReference;
      if(!reference) {
        if(!prepareCavityEvaluationReference(
             face, removed, topology, options, numericCore,
             additionalProtectedVertices, localReference))
          return false;
        reference = &localReference;
      }
      if(!reference->valid || reference->core.faces != numericCore.faces ||
         reference->core.coreFaces != numericCore.coreFaces)
        return false;
      evaluation.core = reference->core;
      evaluation.support = reference->support;
      evaluation.beforePatch = reference->beforePatch;
      const std::vector<MElement *> &beforeElements =
        reference->beforeElements;
      const LocalPatchOrientationReference *beforeOrientationPointer =
        reference->useBeforeOrientation ?
          &reference->beforeOrientation : nullptr;

      const std::set<MElement *> removedSet(removed.begin(), removed.end());
      const std::set<MVertex *> &protectedVertices =
        topology.protectedVertices(face);
      auto isProtected = [&](MVertex *vertex) {
        return protectedVertices.find(vertex) != protectedVertices.end() ||
          (additionalProtectedVertices &&
           additionalProtectedVertices->find(vertex) !=
             additionalProtectedVertices->end());
      };

      std::set<MElement *> afterElements(
        beforeElements.begin(), beforeElements.end());
      for(MElement *element : removedSet)
        if(afterElements.erase(element) != 1) {
          if(options.verbose > 1)
            Msg::Info("QuadOptimizer C+C': removed face outside support");
          return false;
        }
      afterElements.insert(inserted.begin(), inserted.end());
      const std::vector<MElement *> afterVector(
        afterElements.begin(), afterElements.end());
      if(!canonicalPatchFromElements(
           face, afterVector, evaluation.afterPatch) ||
         evaluation.afterPatch.bdrVertices.size() != 1 ||
         evaluation.afterPatch.bdrVertices.front().size() < 3 ||
         !evaluation.afterPatch.embVertices.empty()) {
        if(options.verbose > 1)
          Msg::Info("QuadOptimizer C+C': invalid replacement patch");
        return false;
      }

      CavitySeed candidate;
      candidate.patch = evaluation.afterPatch;
      if(!existingSurfacePatternAndParametrization(
           candidate, evaluation.uv, evaluation.triangles,
           evaluation.quadrangles)) {
        if(options.verbose > 1)
          Msg::Info("QuadOptimizer C+C': parametrization failed");
        return false;
      }

      const std::size_t boundaryCount =
        evaluation.afterPatch.bdrVertices.front().size();
      evaluation.vertices = evaluation.afterPatch.bdrVertices.front();
      evaluation.vertices.insert(
        evaluation.vertices.end(), evaluation.afterPatch.intVertices.begin(),
        evaluation.afterPatch.intVertices.end());
      if(evaluation.vertices.size() != evaluation.uv.size()) {
        if(options.verbose > 1)
          Msg::Info("QuadOptimizer C+C': vertex/parameter count mismatch");
        return false;
      }
      evaluation.xyz.resize(evaluation.vertices.size());
      evaluation.fixed.assign(evaluation.vertices.size(), false);
      for(std::size_t i = 0; i < evaluation.vertices.size(); ++i) {
        MVertex *vertex = evaluation.vertices[i];
        if(!vertex || !evaluation.index.emplace(vertex, i).second) {
          if(options.verbose > 1)
            Msg::Info("QuadOptimizer C+C': invalid or duplicate vertex");
          return false;
        }
        evaluation.xyz[i] = {vertex->x(), vertex->y(), vertex->z()};
        // C' is part of the optimization domain, not a frozen halo. Only
        // the outer boundary of C+C' and genuinely constrained vertices are
        // fixed; every other support vertex participates in mixed Winslow.
        evaluation.fixed[i] = i < boundaryCount ||
          vertex->onWhat() != face || isProtected(vertex);
      }
      if(initialGeometry)
        for(const Candidate::VertexGeometry &geometry : *initialGeometry) {
          const auto found = evaluation.index.find(geometry.vertex);
          if(found == evaluation.index.end() ||
             evaluation.fixed[found->second])
            return false;
          evaluation.uv[found->second] = geometry.uv;
          evaluation.xyz[found->second] = geometry.xyz;
        }

      const bool hasMovableVertex = std::any_of(
        evaluation.fixed.begin(), evaluation.fixed.end(),
        [](bool fixed) { return !fixed; });

      auto finalizeEvaluation = [&]() {
        CavityEvaluationMetrics &metrics = evaluation.metrics;
        metrics.referenceObjective = reference->objective;
        metrics.candidateObjective = candidateMixedObjective(
          evaluation.triangles, evaluation.quadrangles, evaluation.xyz);
        metrics.referenceSize = reference->sizeReusable ? reference->size :
          existingSizeScore(evaluation.beforePatch, options, false);
        metrics.candidateSize = surfacePatchSizeScore(
          face, evaluation.uv, evaluation.xyz, evaluation.triangles,
          evaluation.quadrangles, evaluation.fixed, options);

        if(!options.acceptValidTopologyReduction &&
           !allowAbsoluteSpecificationTradeoff &&
           !noWorseAbsoluteSpecifications(
             metrics.candidateObjective, metrics.referenceObjective,
             options.objectiveRelativeTolerance)) {
          if(options.verbose > 2)
            Msg::Info("QuadOptimizer C+C': face=%d absolute specification "
                      "regression bad=%zu->%zu violations=%zu->%zu "
                      "worst=%g->%g penalty=%g->%g",
                      face->tag(),
                      metrics.referenceObjective.absoluteBadElementCount,
                      metrics.candidateObjective.absoluteBadElementCount,
                      metrics.referenceObjective.absoluteViolationCount,
                      metrics.candidateObjective.absoluteViolationCount,
                      metrics.referenceObjective.worstAbsoluteViolation,
                      metrics.candidateObjective.worstAbsoluteViolation,
                      metrics.referenceObjective.absolutePenalty,
                      metrics.candidateObjective.absolutePenalty);
          return false;
        }
        if(options.requireStrictElementQualityImprovement &&
           !allowAbsoluteSpecificationTradeoff &&
           !improvesSpecificationObjective(
             metrics.candidateObjective, metrics.referenceObjective,
             options.objectiveRelativeTolerance)) {
          if(options.verbose > 2)
            Msg::Info("QuadOptimizer C+C': face=%d unchanged-geometry "
                      "candidate does not strictly improve element quality",
                      face->tag());
          return false;
        }
        if(options.enforceSizeMap &&
           !options.acceptValidTopologyReduction) {
          const std::size_t referenceViolations =
            metrics.referenceSize.belowMinimum +
            metrics.referenceSize.aboveMaximum +
            metrics.referenceSize.invalid;
          const std::size_t candidateViolations =
            metrics.candidateSize.belowMinimum +
            metrics.candidateSize.aboveMaximum +
            metrics.candidateSize.invalid;
          if(!metrics.candidateSize.admissible ||
             candidateViolations > referenceViolations ||
             !admissibleSizeChange(
               metrics.referenceSize, metrics.candidateSize, options)) {
            if(options.verbose > 2)
              Msg::Info("QuadOptimizer C+C': face=%d size regression "
                        "admissible=%d violations=%zu->%zu rmsLog2=%g->%g",
                        face->tag(),
                        metrics.candidateSize.admissible ? 1 : 0,
                        referenceViolations, candidateViolations,
                        metrics.referenceSize.meanSquaredLogRatio,
                        metrics.candidateSize.meanSquaredLogRatio);
            return false;
          }
        }
        // Rule-specific predicates such as QQ chord intersection, strict
        // convexity and objective ranking do not consume the CAD deviation.
        // Run those pure vetoes after the same Winslow state and all common
        // hard guards have been selected, but before the expensive exact
        // closest-point integration. A veto here cannot alter an accepted
        // transaction: the old path rejected the same candidate immediately
        // after this function returned.
        if(preCadGate && !(*preCadGate)(evaluation)) return false;
        // Surface-normal evaluation is the expensive remaining geometric
        // guard. Postpone it until all purely algebraic and rule-specific
        // vetoes have passed; the accepted set is unchanged because all
        // these predicates are conjunctive.
        const bool preservesOrientation =
          face->geomType() == GEntity::DiscreteSurface &&
            !beforeOrientationPointer ?
          indexedPatchFollowsSampledFaceNormal(
            face, evaluation.uv, evaluation.xyz, evaluation.triangles,
            evaluation.quadrangles, 1,
            options.stagedTopologyThenQuality ||
              options.evaluateCandidatesWithoutLocalSmoothing) :
          indexedPatchPreservesSurfaceOrientation(
            face, beforeOrientationPointer, evaluation.uv, evaluation.xyz,
            evaluation.triangles, evaluation.quadrangles);
        if(!preservesOrientation) {
          if(options.verbose > 1)
            Msg::Info("QuadOptimizer C+C': face=%d cavity rejected by "
                      "final orientation (%zuT %zuQ)",
                      face->tag(), evaluation.triangles.size(),
                      evaluation.quadrangles.size());
          return false;
        }
        // Closest-point integration dominates candidate evaluation. It has
        // no bearing on candidates already rejected by shape or edge-size
        // specifications, so preserve the exact calculation and summation
        // order but perform it only after those cheaper hard gates pass.
        if(!reference->geometryEvaluated) {
          reference->geometry = existingGeometryDeviation(
            face, reference->beforePatch.elements);
          reference->geometryEvaluated = true;
        }
        metrics.referenceGeometry = reference->geometry;
        metrics.candidateGeometry = candidateMixedGeometryDeviation(
          face, evaluation.uv, evaluation.xyz, evaluation.triangles,
          evaluation.quadrangles);
        const bool cadGeometryValid =
          metrics.referenceGeometry.valid && metrics.candidateGeometry.valid;
        if(!cadGeometryValid) return false;
        const bool cadDoesNotRegress = geometryDoesNotRegressBeyondRoundoff(
          metrics.candidateGeometry, metrics.referenceGeometry);
        if(!cadDoesNotRegress && !deferCadRegressionToOuterObjective &&
           !options.acceptValidTopologyReduction)
          return false;
        if(!cadDoesNotRegress && options.verbose > 1) {
          const double target = options.targetSize > 0. ?
            options.targetSize : 1.;
          const double normalization = std::max(
            std::max(metrics.referenceGeometry.sampledArea,
                     metrics.candidateGeometry.sampledArea) *
              target * target,
            std::numeric_limits<double>::min());
          Msg::Info("QuadOptimizer C+C': deferring CAD regression "
                    "dE2/(A*h^2)=%g max=%g->%g to outer objective",
                    (metrics.candidateGeometry.squaredDistanceIntegral -
                     metrics.referenceGeometry.squaredDistanceIntegral) /
                      normalization,
                    metrics.referenceGeometry.maximumDistance,
                    metrics.candidateGeometry.maximumDistance);
        }
        evaluation.admissible = true;
        return true;
      };

      // Some topology reductions (notably a diamond collapse) already have
      // an admissible C+C' geometry before relaxation. Requiring a nonlinear
      // Winslow iteration in that state is incorrect: the solver can reject
      // a perfectly valid starting patch simply because it cannot find a
      // strictly better step. This opt-in path runs the exact same final
      // orientation, absolute-quality, size and CAD gates; it skips only the
      // unnecessary motion.
      const bool skipLocalSmoothing =
        options.stagedTopologyThenQuality ||
        options.evaluateCandidatesWithoutLocalSmoothing;
      if(acceptAdmissibleInitialGeometry || skipLocalSmoothing) {
        const bool accepted = finalizeEvaluation();
        if(accepted || skipLocalSmoothing) return accepted;
      }

      if(!hasMovableVertex) {
        return finalizeEvaluation();
      }

      std::set<MVertex *> smoothingFixedVertices;
      for(std::size_t i = boundaryCount; i < evaluation.vertices.size();
          ++i)
        if(evaluation.fixed[i])
          smoothingFixedVertices.insert(evaluation.vertices[i]);

      SmallCavityOptimizerOptions smoothingOptions = options;
      smoothingOptions.topologyOnlyIfCavityHasSpecificationFailure = false;
      // Every feasible connectivity receives a real mixed Winslow solve,
      // but keep the per-candidate work bounded for the interactive path.
      if(useFastInteractiveCleanUp(options)) {
        smoothingOptions.winslow.maxInnerIterations = std::min(
          smoothingOptions.winslow.maxInnerIterations, 40);
        smoothingOptions.winslow.maxOuterIterations = std::min(
          smoothingOptions.winslow.maxOuterIterations, 2);
        smoothingOptions.winslow.maxLineSearchSteps = std::min(
          smoothingOptions.winslow.maxLineSearchSteps, 20);
        smoothingOptions.winslow.gradientTolerance = std::max(
          smoothingOptions.winslow.gradientTolerance, 1.e-7);
      }
      const ExistingSmoothingStatus status = smoothExistingCavity(
        face, candidate, smoothingOptions, false,
        &evaluation.movedVertices, false, &smoothingFixedVertices,
        initialGeometry, &protectedVertices);
      if(status != ExistingSmoothingStatus::Accepted) {
        if(options.verbose > 1)
          Msg::Info("QuadOptimizer C+C': face=%d smoothing rejected "
                    "status=%d B=%zu I=%zu movable=%zu",
                    face->tag(), static_cast<int>(status), boundaryCount,
                    evaluation.afterPatch.intVertices.size(),
                    static_cast<std::size_t>(std::count(
                      evaluation.fixed.begin(), evaluation.fixed.end(),
                      false)));
        return false;
      }

      for(const Candidate::VertexGeometry &geometry :
          evaluation.movedVertices) {
        const auto found = evaluation.index.find(geometry.vertex);
        if(found == evaluation.index.end()) return false;
        evaluation.uv[found->second] = geometry.uv;
        evaluation.xyz[found->second] = geometry.xyz;
      }
      return finalizeEvaluation();
    }

    bool indexedElement(
      MElement *element,
      const std::unordered_map<MVertex *, std::size_t> &index,
      std::vector<std::size_t> &vertices)
    {
      if(!element) return false;
      const std::size_t count = element->getNumPrimaryVertices();
      vertices.resize(count);
      for(std::size_t i = 0; i < count; ++i) {
        const auto found = index.find(
          element->getVertex(static_cast<int>(i)));
        if(found == index.end()) return false;
        vertices[i] = found->second;
      }
      return true;
    }

    bool quadranglesPassAbsoluteSpecifications(
      const std::vector<MElement *> &quadrangles,
      const SmoothedCavityEvaluation &evaluation)
    {
      for(MElement *element : quadrangles) {
        if(!element || element->getNumPrimaryVertices() != 4) return false;
        std::vector<std::size_t> indexed;
        if(!indexedElement(element, evaluation.index, indexed) ||
           indexed.size() != 4)
          return false;
        std::vector<Point> points(4);
        for(std::size_t i = 0; i < 4; ++i)
          points[i] = evaluation.xyz[indexed[i]];
        if(!evaluateElementQuality(
             SurfaceElementKind::Quadrangle, points)
              .passesAbsoluteSpecifications)
          return false;
      }
      return true;
    }

    void applySmoothedReplacementGeometry(
      const std::vector<Candidate::VertexGeometry> &movedVertices)
    {
      for(const Candidate::VertexGeometry &geometry : movedVertices) {
        geometry.vertex->setXYZ(
          geometry.xyz[0], geometry.xyz[1], geometry.xyz[2]);
        geometry.vertex->setParameter(0, geometry.uv[0]);
        geometry.vertex->setParameter(1, geometry.uv[1]);
      }
    }

    void applySmoothedReplacementGeometry(
      const SmoothedCavityEvaluation &evaluation)
    {
      applySmoothedReplacementGeometry(evaluation.movedVertices);
    }

    void applySmoothedReplacementGeometry(
      const std::vector<Candidate::VertexGeometry> &movedVertices,
      FaceHalfEdgeTopology &topology)
    {
      applySmoothedReplacementGeometry(movedVertices);
      std::vector<MVertex *> changed;
      changed.reserve(movedVertices.size());
      for(const Candidate::VertexGeometry &geometry : movedVertices)
        changed.push_back(geometry.vertex);
      topology.synchronizeGeometry(changed);
    }

    void applySmoothedReplacementGeometry(
      const SmoothedCavityEvaluation &evaluation,
      FaceHalfEdgeTopology &topology)
    {
      applySmoothedReplacementGeometry(evaluation.movedVertices, topology);
    }

    bool prepareQuadCavityEvaluation(
      GFace *face, const CavitySeed &seed, const Pattern &quadrangles,
      const std::vector<std::size_t> &interiorAssignment,
      const FaceHalfEdgeTopology &topology,
      const SmallCavityOptimizerOptions &options,
      std::vector<UV> &localUv, std::vector<Point> &localXyz,
      std::vector<Candidate::VertexGeometry> &movedVertices,
      CavityEvaluationMetrics &metrics,
      const std::set<MVertex *> *additionalProtectedVertices = nullptr,
      const std::vector<Candidate::VertexGeometry> *initialGeometry = nullptr,
      bool acceptAdmissibleInitialGeometry = false,
      bool deferCadRegressionToOuterObjective = false,
      const CavityEvaluationReference *preparedReference = nullptr,
      const CavityPreCadGate *preCadGate = nullptr,
      bool allowAbsoluteSpecificationTradeoff = false)
    {
      if(!face || seed.patch.bdrVertices.size() != 1 ||
         seed.patch.elements.empty())
        return false;
      const std::size_t boundaryCount =
        seed.patch.bdrVertices.front().size();
      std::vector<MVertex *> localVertices =
        seed.patch.bdrVertices.front();
      std::vector<std::unique_ptr<MVertex> > temporaryVertices;
      std::set<MVertex *> temporaryVertexHandles;
      std::set<std::size_t> retained;
      for(std::size_t i = 0; i < interiorAssignment.size(); ++i) {
        const std::size_t assignment = interiorAssignment[i];
        if(assignment == std::numeric_limits<std::size_t>::max()) {
          const std::size_t local = boundaryCount + i;
          if(local >= localUv.size() || local >= localXyz.size())
            return false;
          std::unique_ptr<MVertex> created(new MFaceVertex(
            localXyz[local][0], localXyz[local][1], localXyz[local][2],
            face, localUv[local][0], localUv[local][1]));
          temporaryVertexHandles.insert(created.get());
          localVertices.push_back(created.get());
          temporaryVertices.push_back(std::move(created));
          continue;
        }
        if(assignment >= seed.patch.intVertices.size() ||
           !retained.insert(assignment).second)
          return false;
        localVertices.push_back(seed.patch.intVertices[assignment]);
      }

      const int partition = seed.patch.elements.front()->getPartition();
      const bool visibility =
        seed.patch.elements.front()->getVisibility();
      std::vector<std::unique_ptr<MElement> > storage;
      std::vector<MElement *> replacement;
      storage.reserve(quadrangles.size());
      replacement.reserve(quadrangles.size());
      for(const auto &quad : quadrangles) {
        bool valid = true;
        for(const std::size_t vertex : quad)
          valid = valid && vertex < localVertices.size();
        if(!valid) return false;
        std::unique_ptr<MElement> element(new MQuadrangle(
          localVertices[quad[0]], localVertices[quad[1]],
          localVertices[quad[2]], localVertices[quad[3]]));
        element->setPartition(partition);
        element->setVisibility(visibility);
        replacement.push_back(element.get());
        storage.push_back(std::move(element));
      }
      if(replacement.empty() ||
         !orientElementsAccordingToBoundarySegment(
           seed.patch.bdrVertices.front()[0],
           seed.patch.bdrVertices.front()[1], replacement) ||
         !topology.validReplacement(seed.patch.elements, replacement))
        return false;

      std::vector<Candidate::VertexGeometry> combinedInitialGeometry;
      if(initialGeometry)
        combinedInitialGeometry = *initialGeometry;
      for(std::size_t i = 0; i < interiorAssignment.size(); ++i) {
        if(interiorAssignment[i] !=
           std::numeric_limits<std::size_t>::max())
          continue;
        const std::size_t local = boundaryCount + i;
        combinedInitialGeometry.push_back(
          {localVertices[local], localUv[local], localXyz[local]});
      }

      SmoothedCavityEvaluation evaluation;
      if(!prepareSmoothedCavityEvaluation(
           face, seed.patch.elements, replacement, topology, options,
           evaluation, seed.halfEdgeCavity, additionalProtectedVertices,
           combinedInitialGeometry.empty() ? nullptr :
                                             &combinedInitialGeometry,
           acceptAdmissibleInitialGeometry,
           deferCadRegressionToOuterObjective, preparedReference,
           preCadGate, allowAbsoluteSpecificationTradeoff))
        return false;
      if(!evaluation.admissible) return false;
      metrics = evaluation.metrics;

      localUv.resize(localVertices.size());
      localXyz.resize(localVertices.size());
      for(std::size_t i = 0; i < localVertices.size(); ++i) {
        const auto found = evaluation.index.find(localVertices[i]);
        if(found == evaluation.index.end()) return false;
        localUv[i] = evaluation.uv[found->second];
        localXyz[i] = evaluation.xyz[found->second];
      }
      movedVertices.clear();
      movedVertices.reserve(evaluation.movedVertices.size());
      for(const Candidate::VertexGeometry &geometry :
          evaluation.movedVertices)
        if(temporaryVertexHandles.find(geometry.vertex) ==
           temporaryVertexHandles.end())
          movedVertices.push_back(geometry);
      return true;
    }

    ExistingTopologyWinslowResult smoothAllInteriorVertexCavities(
      GFace *face, const SmallCavityOptimizerOptions &options,
      const FaceHalfEdgeTopology &topology,
      const std::set<MVertex *> *additionalProtectedVertices = nullptr,
      bool smoothAdditionalProtectedWithCadGuard = false)
    {
      ExistingTopologyWinslowResult result;
      if(!face || options.smoothingPasses < 0 || !topology.manifold()) {
        result.success = false;
        return result;
      }
      result.initialObjective = specificationObjective(topology.elements());
      const std::set<MVertex *> &protectedVertices =
        topology.protectedVertices(face);
      for(int pass = 0; pass < options.smoothingPasses; ++pass) {
        ++result.passes;
        std::size_t acceptedThisPass = 0;
        const std::vector<MVertex *> vertices = topology.vertices();
        for(MVertex *vertex : vertices) {
          const bool additionallyProtected =
            additionalProtectedVertices &&
            additionalProtectedVertices->find(vertex) !=
              additionalProtectedVertices->end();
          if(!vertex || vertex->onWhat() != face ||
             protectedVertices.find(vertex) != protectedVertices.end() ||
             (additionallyProtected &&
              !smoothAdditionalProtectedWithCadGuard))
            continue;
          ++result.quadsVisited;
          CavitySeed seed;
          ExistingSmoothingStatus status = ExistingSmoothingStatus::Invalid;
          if(interiorVertexCavity(
               face, {vertex}, topology, seed,
               !useFastInteractiveCleanUp(options), false))
            status = smoothExistingCavity(
              face, seed, options, additionallyProtected);
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
            if(topology.synchronizeGeometry(seed.patch.intVertices)) {
              ++result.acceptedCavities;
              ++acceptedThisPass;
            }
            break;
          case ExistingSmoothingStatus::Invalid: break;
          }
        }
        // With no accepted movement the mesh, its exact XYZ/UV cache keys
        // and every cavity decision are unchanged. A subsequent pass would
        // deterministically repeat the same rejections.
        if(acceptedThisPass == 0) {
          result.reachedFixedPoint = true;
          break;
        }
      }
      result.finalObjective = specificationObjective(topology.elements());
      if(options.invalidateVertexArrays) face->model()->deleteVertexArrays();
      return result;
    }

    bool tryDiamond(GFace *face, const DiamondSeed &diamond,
                    FaceHalfEdgeTopology &topology,
                    const SmallCavityOptimizerOptions &options,
                    SmallCavityOptimizerResult &result,
                    CleanUpDecisionPhase phase,
                    const std::set<MVertex *> *additionalProtectedVertices)
    {
      ++result.diamondsVisited;
      const CavitySeed &seed = diamond.cavity;
      const bool fastInteractive = useFastInteractiveCleanUp(options);
      const std::size_t boundaryCount =
        seed.patch.bdrVertices.front().size();
      MVertex *retained =
        seed.patch.intVertices[diamond.retainedInterior];
      MVertex *removed = seed.patch.intVertices[diamond.removedInterior];
      auto rejectDiamond = [&](const char *reason) {
        if(options.verbose > 1)
          Msg::Info("QuadOptimizer diamond reject face=%d central=%zu "
                    "retained=%zu removed=%zu reason=%s",
                    face->tag(), diamond.diamond->getNum(),
                    retained->getNum(), removed->getNum(), reason);
        return false;
      };

      std::unordered_map<MVertex *, std::size_t> boundaryIndex;
      for(std::size_t i = 0; i < boundaryCount; ++i)
        boundaryIndex[seed.patch.bdrVertices.front()[i]] = i;
      Pattern quadrangles;
      quadrangles.reserve(seed.patch.elements.size() - 1);
      for(MElement *element : seed.patch.elements) {
        if(element == diamond.diamond) continue;
        if(element->getNumPrimaryVertices() != 4)
          return rejectDiamond("non-quad-support");
        std::array<std::size_t, 4> quad;
        std::set<std::size_t> unique;
        for(std::size_t i = 0; i < 4; ++i) {
          MVertex *vertex = element->getVertex(static_cast<int>(i));
          if(vertex == retained || vertex == removed)
            quad[i] = boundaryCount;
          else {
            const auto found = boundaryIndex.find(vertex);
            if(found == boundaryIndex.end())
              return rejectDiamond("support-index");
            quad[i] = found->second;
          }
          unique.insert(quad[i]);
        }
        if(unique.size() != 4) return rejectDiamond("collapsed-quad");
        quadrangles.push_back(quad);
      }
      if(quadrangles.empty()) return rejectDiamond("empty-candidate");

      std::vector<UV> uv;
      if(!currentParametrization(seed.patch, uv))
        return rejectDiamond("parametrization");
      const UV retainedUv = uv[boundaryCount + diamond.retainedInterior];
      const UV removedUv = uv[boundaryCount + diamond.removedInterior];
      const UV merged = {
        .5 * (retainedUv[0] + removedUv[0]),
        .5 * (retainedUv[1] + removedUv[1])};
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
        return rejectDiamond("core-winslow");
      }
      std::vector<Point> xyz;
      if(!mapCandidate(face, boundaryCount,
                       seed.patch.bdrVertices.front(), uv, xyz)) {
        ++result.rejectedByWinslow;
        return rejectDiamond("core-map");
      }
      // The diamond's small core solve supplies the first collapse position.
      // On a curved discrete surface that point and both original endpoints
      // can straddle a support-normal transition even though an intermediate
      // point along the same short edge is valid. Test a deterministic
      // bounded line search along the surface-parameter segment. Every trial
      // still goes through the complete orientation, size and geometry
      // transaction; this only broadens the initial positions, not the
      // acceptance contract.
      std::vector<Candidate::VertexGeometry> collapsePositions = {{
        retained, uv[boundaryCount], xyz[boundaryCount]}};
      for(const double fraction : {0., .25, .5, .75, 1.}) {
        const UV trialUv = {
          retainedUv[0] + fraction * (removedUv[0] - retainedUv[0]),
          retainedUv[1] + fraction * (removedUv[1] - retainedUv[1])};
        const GPoint mapped = face->point(SPoint2(trialUv[0], trialUv[1]));
        if(!mapped.succeeded() || !std::isfinite(mapped.x()) ||
           !std::isfinite(mapped.y()) || !std::isfinite(mapped.z()))
          continue;
        const Point trialXyz = {mapped.x(), mapped.y(), mapped.z()};
        const bool duplicate = std::any_of(
          collapsePositions.begin(), collapsePositions.end(),
          [&](const Candidate::VertexGeometry &position) {
            return std::abs(position.uv[0] - trialUv[0]) <= 1.e-14 &&
                   std::abs(position.uv[1] - trialUv[1]) <= 1.e-14;
          });
        if(!duplicate)
          collapsePositions.push_back({retained, trialUv, trialXyz});
      }
      std::vector<Candidate::VertexGeometry> smoothedVertices;
      CavityEvaluationMetrics metrics;
      bool prepared = false;
      for(const Candidate::VertexGeometry &position : collapsePositions) {
        std::vector<UV> trialUv;
        std::vector<Point> trialXyz;
        std::vector<Candidate::VertexGeometry> trialSmoothedVertices;
        CavityEvaluationMetrics trialMetrics;
        const std::vector<Candidate::VertexGeometry> initialGeometry = {
          position};
        if(!prepareQuadCavityEvaluation(
          face, seed, quadrangles, {diamond.retainedInterior}, topology,
          options, trialUv, trialXyz, trialSmoothedVertices, trialMetrics,
          additionalProtectedVertices, &initialGeometry, true, true))
          continue;
        if(fastInteractive && !candidateQuadranglesAreNonConcave(
             quadrangles, trialUv, trialXyz))
          continue;
        uv = std::move(trialUv);
        xyz = std::move(trialXyz);
        smoothedVertices = std::move(trialSmoothedVertices);
        metrics = std::move(trialMetrics);
        prepared = true;
        break;
      }
      if(!prepared) {
        ++result.rejectedByWinslow;
        return rejectDiamond("support-winslow");
      }
      const SizeScore &beforeSize = metrics.referenceSize;
      const SizeScore &afterSize = metrics.candidateSize;
      const SpecificationObjective &referenceObjective =
        metrics.referenceObjective;
      const SpecificationObjective &objective = metrics.candidateObjective;
      const std::size_t candidateInvalidElementCount =
        objective.invalidElementCount;
      const GeometryDeviation &referenceGeometry =
        metrics.referenceGeometry;
      const GeometryDeviation &geometry = metrics.candidateGeometry;
      const SpecificationObjective coreObjective =
        candidateObjective(quadrangles, xyz);
      if(coreObjective.invalidElementCount != 0 ||
         (!options.acceptValidTopologyReduction &&
          coreObjective.absoluteBadElementCount != 0)) {
        ++result.rejectedByQuality;
        return rejectDiamond("core-quality");
      }
      if(fastInteractive &&
         !candidateQuadranglesAreNonConcave(quadrangles, uv, xyz)) {
        ++result.rejectedByQuality;
        return rejectDiamond("non-convex");
      }
      // The collapse removes a pair of opposite valence-three vertices, which
      // is the connectivity improvement required by the diamond action. The
      // smoothed result must still preserve every absolute quality guard.
      const ValenceObjective candidateValence =
        candidatePatchValence(seed, quadrangles, 1);
      const std::size_t beforeSizeViolations =
        beforeSize.belowMinimum + beforeSize.aboveMaximum + beforeSize.invalid;
      const std::size_t afterSizeViolations =
        afterSize.belowMinimum + afterSize.aboveMaximum + afterSize.invalid;
      CleanUpDecisionReason decision = CleanUpDecisionReason::Rejected;
      if(options.acceptValidTopologyReduction) {
        // Removing the two-pole diamond is itself the monotone objective in
        // the staged topology pass. Geometry and topology were validated by
        // the C+C' transaction above; quality is repaired globally later.
        decision = CleanUpDecisionReason::OtherImprovement;
      }
      else if(fastInteractive) {
        if(!referenceGeometry.valid || !geometry.valid) {
          ++result.rejectedByQuality;
          return rejectDiamond("geometry-evaluation");
        }
        const double target = options.targetSize > 0. ?
          options.targetSize :
          std::sqrt(std::max(
            referenceGeometry.sampledArea /
              static_cast<double>(
                std::max<std::size_t>(1, referenceGeometry.elementCount)),
            std::numeric_limits<double>::min()));
        double normalizedCadChange = 0.;
        double normalizedMaximumCadDistanceChange = 0.;
        const bool boundedCadRegression = geometryRegressionFitsMeshScale(
          geometry, referenceGeometry, target, options,
          normalizedCadChange, normalizedMaximumCadDistanceChange);
        const FastGlobalQuality candidateQuality = fastGlobalQuality(
          objective, candidateValence, candidateInvalidElementCount,
          afterSizeViolations, afterSize.meanSquaredLogRatio,
          afterSize.edgeCount, normalizedCadChange);
        const FastGlobalQuality referenceQuality = fastGlobalQuality(
          referenceObjective, seed.valence,
          referenceObjective.invalidElementCount,
          beforeSizeViolations, beforeSize.meanSquaredLogRatio,
          beforeSize.edgeCount, 0.);
        // A diamond collapse strictly removes one vertex and one quad, so it
        // is an acyclic structural improvement. Do not let the soft
        // compromise score veto it after all hard C+C' guards have passed.
        // The opt-in CAD deferral above remains bounded here both by its
        // A*h^2-normalized integral and by its h-normalized worst distance.
        // Collapsing the two valence-three poles can either preserve the
        // valence objective exactly or move one unit of defect to an adjacent
        // pole. Permit the neutral case. Permit at most one new severe pole
        // only when the total irregular count strictly decreases, and keep
        // the squared-valence penalty increase bounded by two in both cases.
        const bool introducesSeverePole =
          candidateValence.severeCount > seed.valence.severeCount;
        const bool boundedValenceTrade =
          candidateValence.severeCount <= seed.valence.severeCount + 1 &&
          candidateValence.irregularCount <= seed.valence.irregularCount &&
          (!introducesSeverePole ||
           candidateValence.irregularCount < seed.valence.irregularCount) &&
          candidateValence.penalty <= seed.valence.penalty + 2. +
            options.objectiveRelativeTolerance * std::max(
              {1., candidateValence.penalty, seed.valence.penalty});
        const bool structuralDiamondReduction =
          boundedValenceTrade && boundedCadRegression;
        if(improvesFastGlobalQuality(candidateQuality, referenceQuality) ||
           structuralDiamondReduction)
          decision = CleanUpDecisionReason::OtherImprovement;
        if(structuralDiamondReduction && options.verbose > 1)
          Msg::Info("QuadOptimizer diamond accepted structural reduction "
                    "face=%d central=%zu retained=%zu dCAD=%g "
                    "dCADmax/h=%g max=%g->%g",
                    face->tag(), diamond.diamond->getNum(),
                    retained->getNum(), normalizedCadChange,
                    normalizedMaximumCadDistanceChange,
                    referenceGeometry.maximumDistance,
                    geometry.maximumDistance);
        else if(decision == CleanUpDecisionReason::Rejected &&
                options.verbose > 1) {
          Msg::Info("QuadOptimizer diamond objective face=%d central=%zu "
                    "retained=%zu invalid=%zu->%zu forbidden=%zu->%zu "
                    "hard=%zu->%zu hardPenalty=%g->%g "
                    "compromise=%g->%g sizeBad=%zu->%zu "
                    "valence[severe=%zu->%zu irregular=%zu->%zu "
                    "penalty=%g->%g] dCAD=%g dCADmax/h=%g CADmax=%g->%g",
                    face->tag(), diamond.diamond->getNum(),
                    retained->getNum(),
                    referenceQuality.invalidElementCount,
                    candidateQuality.invalidElementCount,
                    referenceQuality.forbiddenConfigurationCount,
                    candidateQuality.forbiddenConfigurationCount,
                    referenceQuality.hardSpecificationViolationCount,
                    candidateQuality.hardSpecificationViolationCount,
                    referenceQuality.hardSpecificationPenalty,
                    candidateQuality.hardSpecificationPenalty,
                    referenceQuality.compromise,
                    candidateQuality.compromise,
                    beforeSizeViolations, afterSizeViolations,
                    seed.valence.severeCount,
                    candidateValence.severeCount,
                    seed.valence.irregularCount,
                    candidateValence.irregularCount,
                    seed.valence.penalty,
                    candidateValence.penalty,
                    normalizedCadChange,
                    normalizedMaximumCadDistanceChange,
                    referenceGeometry.maximumDistance,
                    geometry.maximumDistance);
        }
      }
      else if(noWorseAbsoluteSpecifications(
                objective, referenceObjective,
                options.objectiveRelativeTolerance)) {
        decision = CleanUpDecisionReason::OtherImprovement;
      }
      if(!decisionAllowed(decision, phase)) {
        ++result.rejectedByQuality;
        return rejectDiamond("objective");
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
      candidate.decisionReason = decision;
      candidate.smoothedVertices = std::move(smoothedVertices);
      std::vector<MVertex *> retainedInterior;
      if(!executeCandidate(face, seed, candidate, topology,
                           &retainedInterior))
        return rejectDiamond("commit");
      applySmoothedReplacementGeometry(candidate.smoothedVertices, topology);
      return true;
    }

    bool tryInteriorFourBoundaryFanReduction(
      GFace *face, const CavitySeed &seed,
      FaceHalfEdgeTopology &topology,
      const SmallCavityOptimizerOptions &options,
      SmallCavityOptimizerResult &result, CleanUpDecisionPhase phase,
      const std::set<MVertex *> *additionalProtectedVertices,
      std::size_t expectedTriangles,
      std::size_t expectedQuadrangles)
    {
      if(!face || phase != CleanUpDecisionPhase::Any ||
         !useFastInteractiveCleanUp(options) || !topology.manifold() ||
         seed.patch.bdrVertices.size() != 1 ||
         seed.patch.bdrVertices.front().size() != 4 ||
         expectedTriangles == 0 ||
         seed.patch.elements.size() !=
           expectedTriangles + expectedQuadrangles ||
         seed.patch.intVertices.size() != 1 ||
         !seed.patch.embVertices.empty() ||
         seed.patch.intVertices.front()->onWhat() != face ||
         touchesBoundaryLayerElementData(face, seed.patch.elements))
        return false;

      std::size_t triangles = 0, quadrangles = 0;
      const int partition = seed.patch.elements.front()->getPartition();
      const bool visibility = seed.patch.elements.front()->getVisibility();
      for(MElement *element : seed.patch.elements) {
        if(!element || element->getPartition() != partition ||
           element->getVisibility() != visibility)
          return false;
        triangles += element->getNumPrimaryVertices() == 3;
        quadrangles += element->getNumPrimaryVertices() == 4;
      }
      if(triangles != expectedTriangles ||
         quadrangles != expectedQuadrangles)
        return false;

      // The four radial edges disappear with the interior star. None may be
      // a model or embedded-curve constraint.
      const MVertex *center = seed.patch.intVertices.front();
      auto constrainedRadialEdge = [&](const std::vector<GEdge *> &curves) {
        for(GEdge *curve : curves)
          if(curve)
            for(MLine *line : curve->lines)
              if(line &&
                 (line->getVertex(0) == center ||
                  line->getVertex(1) == center))
                return true;
        return false;
      };
      if(constrainedRadialEdge(face->edges()) ||
         constrainedRadialEdge(face->getEmbeddedEdges()))
        return false;

      const Pattern replacement = {{{0, 1, 2, 3}}};
      std::vector<UV> uv;
      std::vector<Point> xyz;
      std::vector<Candidate::VertexGeometry> smoothedVertices;
      CavityEvaluationMetrics metrics;
      ++result.topologyCandidatesOptimized;
      if(!prepareQuadCavityEvaluation(
           face, seed, replacement, {}, topology, options, uv, xyz,
           smoothedVertices, metrics, additionalProtectedVertices)) {
        ++result.rejectedByWinslow;
        return false;
      }

      const SpecificationObjective coreObjective =
        candidateObjective(replacement, xyz);
      if(coreObjective.invalidElementCount != 0 ||
         (!options.acceptValidTopologyReduction &&
          coreObjective.absoluteBadElementCount != 0) ||
         !candidateQuadranglesAreNonConcave(replacement, uv, xyz)) {
        ++result.rejectedByQuality;
        return false;
      }

      // The persistent-topology preflight proved that the exact B=4/I=1
      // source fan is replaced by this single quad while C' is unchanged.
      // Fewer triangles is the strict monotone objective; soft shape and
      // valence terms must not veto an otherwise admissible reduction.

      Candidate candidate;
      candidate.valid = true;
      candidate.uv = std::move(uv);
      candidate.xyz = std::move(xyz);
      candidate.quadrangles = replacement;
      candidate.interiorAssignment.clear();
      candidate.objective = metrics.candidateObjective;
      candidate.geometry = metrics.candidateGeometry;
      candidate.referenceGeometry = metrics.referenceGeometry;
      candidate.invalidElementCount =
        metrics.candidateObjective.invalidElementCount;
      candidate.sizeError = metrics.candidateSize.meanSquaredLogRatio;
      candidate.sizeEdgeCount = metrics.candidateSize.edgeCount;
      candidate.sizeViolationCount =
        metrics.candidateSize.belowMinimum +
        metrics.candidateSize.aboveMaximum + metrics.candidateSize.invalid;
      candidate.valence = candidatePatchValence(seed, replacement, 0);
      candidate.decisionReason = CleanUpDecisionReason::OtherImprovement;
      candidate.smoothedVertices = std::move(smoothedVertices);
      if(!executeCandidate(face, seed, candidate, topology)) return false;
      applySmoothedReplacementGeometry(candidate.smoothedVertices, topology);
      return true;
    }

    bool tryInteriorAlternatingQuadTriangleReduction(
      GFace *face, const CavitySeed &seed,
      FaceHalfEdgeTopology &topology,
      const SmallCavityOptimizerOptions &options,
      SmallCavityOptimizerResult &result, CleanUpDecisionPhase phase,
      const std::set<MVertex *> *additionalProtectedVertices)
    {
      if(!face || phase != CleanUpDecisionPhase::Any ||
         !useFastInteractiveCleanUp(options) || !topology.manifold() ||
         seed.patch.bdrVertices.size() != 1 ||
         seed.patch.bdrVertices.front().size() != 6 ||
         seed.patch.elements.size() != 4 ||
         seed.patch.intVertices.size() != 1 ||
         !seed.patch.embVertices.empty() ||
         seed.patch.intVertices.front()->onWhat() != face ||
         touchesBoundaryLayerElementData(face, seed.patch.elements))
        return false;

      std::size_t triangles = 0, quadrangles = 0;
      const int partition = seed.patch.elements.front()->getPartition();
      const bool visibility =
        seed.patch.elements.front()->getVisibility();
      for(MElement *element : seed.patch.elements) {
        if(!element || element->getPartition() != partition ||
           element->getVisibility() != visibility)
          return false;
        triangles += element->getNumPrimaryVertices() == 3;
        quadrangles += element->getNumPrimaryVertices() == 4;
      }
      if(triangles != 2 || quadrangles != 2) return false;

      // All four source radial edges disappear with the center. A CAD or
      // embedded-curve edge is never removable by a surface rewrite.
      const MVertex *center = seed.patch.intVertices.front();
      auto constrainedRadialEdge = [&](const std::vector<GEdge *> &curves) {
        for(GEdge *curve : curves)
          if(curve)
            for(MLine *line : curve->lines)
              if(line &&
                 (line->getVertex(0) == center ||
                  line->getVertex(1) == center))
                return true;
        return false;
      };
      if(constrainedRadialEdge(face->edges()) ||
         constrainedRadialEdge(face->getEmbeddedEdges()))
        return false;

      Candidate best;
      FastTriangleReductionQuality bestReduction;
      ConnectivitySignature bestConnectivity;
      bool haveBestReduction = false;
      constexpr std::size_t boundaryCount = 6;
      for(std::size_t diagonal = 0; diagonal < 3; ++diagonal) {
        // The only dissections of a hexagon into two quadrangles use one of
        // its three opposite-vertex diagonals. Enumerating all three makes
        // the rule independent of the numeric half-edge root and of the
        // geometry seen in any particular mesh.
        const Pattern replacement = {{
          {{diagonal, (diagonal + 1) % boundaryCount,
            (diagonal + 2) % boundaryCount,
            (diagonal + 3) % boundaryCount}},
          {{diagonal, (diagonal + 3) % boundaryCount,
            (diagonal + 4) % boundaryCount,
            (diagonal + 5) % boundaryCount}}
        }};
        std::vector<UV> uv;
        std::vector<Point> xyz;
        std::vector<Candidate::VertexGeometry> smoothedVertices;
        CavityEvaluationMetrics metrics;
        ++result.topologyCandidatesOptimized;
        if(!prepareQuadCavityEvaluation(
             face, seed, replacement, {}, topology, options, uv, xyz,
             smoothedVertices, metrics, additionalProtectedVertices,
             nullptr, false, true)) {
          ++result.rejectedByWinslow;
          continue;
        }

        const SpecificationObjective coreObjective =
          candidateObjective(replacement, xyz);
        if(coreObjective.invalidElementCount != 0 ||
           coreObjective.absoluteBadElementCount != 0 ||
           !candidateQuadranglesAreNonConcave(replacement, uv, xyz)) {
          ++result.rejectedByQuality;
          continue;
        }

        const GeometryDeviation &referenceGeometry =
          metrics.referenceGeometry;
        const GeometryDeviation &geometry = metrics.candidateGeometry;
        const double target = options.targetSize > 0. ?
          options.targetSize :
          std::sqrt(std::max(
            referenceGeometry.sampledArea /
              static_cast<double>(std::max<std::size_t>(
                1, referenceGeometry.elementCount)),
            std::numeric_limits<double>::min()));
        double normalizedCadChange = 0.;
        double normalizedMaximumCadDistanceChange = 0.;
        if(!geometryRegressionFitsMeshScale(
             geometry, referenceGeometry, target, options,
             normalizedCadChange,
             normalizedMaximumCadDistanceChange)) {
          ++result.rejectedByQuality;
          continue;
        }

        const SizeScore &size = metrics.candidateSize;
        const std::size_t sizeViolations = size.belowMinimum +
          size.aboveMaximum + size.invalid;
        const ValenceObjective valence =
          candidatePatchValence(seed, replacement, 0);
        FastTriangleReductionQuality reduction;
        reduction.invalidElementCount =
          metrics.candidateObjective.invalidElementCount;
        reduction.triangleCount = 0;
        reduction.remaining = fastGlobalQuality(
          metrics.candidateObjective, valence,
          metrics.candidateObjective.invalidElementCount,
          sizeViolations, size.meanSquaredLogRatio, size.edgeCount,
          normalizedCadChange);

        const SizeScore &referenceSize = metrics.referenceSize;
        const std::size_t referenceSizeViolations =
          referenceSize.belowMinimum + referenceSize.aboveMaximum +
          referenceSize.invalid;
        FastTriangleReductionQuality referenceReduction;
        referenceReduction.invalidElementCount =
          metrics.referenceObjective.invalidElementCount;
        referenceReduction.triangleCount = 2;
        referenceReduction.remaining = fastGlobalQuality(
          metrics.referenceObjective, seed.valence,
          metrics.referenceObjective.invalidElementCount,
          referenceSizeViolations,
          referenceSize.meanSquaredLogRatio, referenceSize.edgeCount, 0.);
        if(!improvesFastTriangleReductionQuality(
             reduction, referenceReduction)) {
          ++result.rejectedByQuality;
          continue;
        }

        const ConnectivitySignature connectivity =
          candidateConnectivitySignature(replacement, boundaryCount, {});
        bool better = !haveBestReduction ||
          improvesFastTriangleReductionQuality(reduction, bestReduction);
        if(haveBestReduction && !better &&
           !improvesFastTriangleReductionQuality(
             bestReduction, reduction))
          better = connectivity < bestConnectivity;
        if(!better) continue;

        haveBestReduction = true;
        bestReduction = reduction;
        bestConnectivity = connectivity;
        best.valid = true;
        best.uv = std::move(uv);
        best.xyz = std::move(xyz);
        best.quadrangles = replacement;
        best.interiorAssignment.clear();
        best.objective = metrics.candidateObjective;
        best.geometry = geometry;
        best.referenceGeometry = referenceGeometry;
        best.valence = valence;
        best.invalidElementCount =
          metrics.candidateObjective.invalidElementCount;
        best.sizeError = size.meanSquaredLogRatio;
        best.sizeEdgeCount = size.edgeCount;
        best.sizeViolationCount = sizeViolations;
        best.decisionReason = CleanUpDecisionReason::OtherImprovement;
        best.smoothedVertices = std::move(smoothedVertices);
      }
      if(!best.valid) return false;
      if(!executeCandidate(face, seed, best, topology)) return false;
      applySmoothedReplacementGeometry(best.smoothedVertices, topology);
      return true;
    }

    bool tryValenceSixCavity(
      GFace *face, const CavitySeed &seed,
      FaceHalfEdgeTopology &topology,
      const SmallCavityOptimizerOptions &options,
      SmallCavityOptimizerResult &result, CleanUpDecisionPhase phase,
      HalfEdgeRewriteSymmetry symmetry)
    {
      ++result.valenceSixVerticesVisited;
      const std::size_t boundaryCount =
        seed.patch.bdrVertices.front().size();
      if(boundaryCount != 12 || seed.patch.intVertices.size() != 1)
        return false;
      const std::shared_ptr<const CachedPatternOrbit> orbit =
        cachedPatternOrbit(boundaryCount, 2, symmetry);
      if(!orbit->valid) return false;
      const std::vector<Pattern> &patterns = orbit->patterns;
      const auto ranked = rankPatterns(
        seed.patch, *orbit, options.maximumTopologyCandidatesPerCavity,
        topology, &seed);
      std::vector<UV> initial;
      if(!currentParametrization(seed.patch, initial)) return false;
      initial.resize(boundaryCount + 2, initial[boundaryCount]);
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
          configuration.rotation, configuration.reflected, symmetry);
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

        // Valence depends only on connectivity. Reject an inadmissible
        // split before the two nonlinear solves and all discrete-CAD
        // queries required by the C+C' transaction.
        const ValenceObjective candidateValence =
          candidatePatchValence(seed, quadrangles, 2);
        if(!improvesValencePareto(candidateValence, seed.valence)) {
          ++result.rejectedByQuality;
          continue;
        }

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
        // Preserve the retained half of the core Winslow split as the
        // initial state of the mandatory C+C' solve. The live center is not
        // moved while candidate configurations are being evaluated.
        const std::vector<Candidate::VertexGeometry> coreInitialGeometry = {{
          seed.patch.intVertices.front(), uv[boundaryCount],
          xyz[boundaryCount]}};
        std::vector<Candidate::VertexGeometry> smoothedVertices;
        CavityEvaluationMetrics metrics;
        if(!prepareQuadCavityEvaluation(
             face, seed, quadrangles,
             {0, std::numeric_limits<std::size_t>::max()}, topology,
             options, uv, xyz, smoothedVertices, metrics, nullptr,
             &coreInitialGeometry)) {
          ++result.rejectedByWinslow;
          continue;
        }
        const SizeScore &size = metrics.candidateSize;
        const SpecificationObjective &objective =
          metrics.candidateObjective;
        // The B=12, I=1->2 template is a connectivity repair, not a surface
        // refinement operator.  Requiring a strict affected-star valence
        // decrease prevents a newly created valence-six vertex from being
        // split again merely because the extra quad reduces chordal error.
        const std::size_t sizeViolations =
          size.belowMinimum + size.aboveMaximum + size.invalid;
        const CleanUpDecisionReason decision = noWorseAbsoluteSpecifications(
          objective, metrics.referenceObjective,
          options.objectiveRelativeTolerance) ?
          CleanUpDecisionReason::OtherImprovement :
          CleanUpDecisionReason::Rejected;
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
        candidate.sizeError = size.meanSquaredLogRatio;
        candidate.sizeViolationCount = sizeViolations;
        candidate.valence = candidateValence;
        candidate.decisionReason = decision;
        candidate.smoothedVertices = std::move(smoothedVertices);
        if(!betterByQualityThenSize(
             candidate.objective, candidate.sizeError, best, options))
          continue;
        best = std::move(candidate);
      }
      if(!best.valid) return false;
      std::vector<MVertex *> interior;
      if(!executeValenceSixCandidate(face, seed, best, topology, interior))
        return false;
      applySmoothedReplacementGeometry(best.smoothedVertices, topology);
      return true;
    }

    bool tryInteriorQQTQQTCavity(
      GFace *face, const CavitySeed &seed,
      FaceHalfEdgeTopology &topology,
      const SmallCavityOptimizerOptions &options,
      SmallCavityOptimizerResult &result, CleanUpDecisionPhase phase,
      HalfEdgeRewriteSymmetry symmetry)
    {
      ++result.interiorQQTQQTStarsVisited;
      if(touchesBoundaryLayerElementData(face, seed.patch.elements))
        return false;
      const std::size_t boundaryCount =
        seed.patch.bdrVertices.front().size();
      if(boundaryCount != 10 || seed.patch.intVertices.size() != 1 ||
         seed.patch.elements.size() != 6)
        return false;
      std::size_t referenceTriangles = 0;
      std::size_t referenceQuadrangles = 0;
      for(MElement *element : seed.patch.elements) {
        if(element->getNumPrimaryVertices() == 3)
          ++referenceTriangles;
        else if(element->getNumPrimaryVertices() == 4)
          ++referenceQuadrangles;
      }
      // Triangle reduction is the strict structural objective of this rule;
      // the cyclic matcher has already established T-Q-Q-T-Q-Q.
      if(referenceTriangles != 2 || referenceQuadrangles != 4)
        return false;
      const int sourcePartition =
        seed.patch.elements.front()->getPartition();
      const bool sourceVisibility =
        seed.patch.elements.front()->getVisibility();
      for(MElement *element : seed.patch.elements)
        if(!element || element->getPartition() != sourcePartition ||
           element->getVisibility() != sourceVisibility)
          return false;

      const std::shared_ptr<const CachedPatternOrbit> orbit =
        cachedPatternOrbit(10, 2, symmetry);
      if(!orbit->valid) return false;
      const std::vector<Pattern> &patterns = orbit->patterns;
      const auto ranked = rankPatterns(
        seed.patch, *orbit, options.maximumTopologyCandidatesPerCavity,
        topology, &seed);
      std::vector<UV> initial;
      if(!currentParametrization(seed.patch, initial) ||
         initial.size() != boundaryCount + 1)
        return false;
      // Both candidate interior vertices start at the old star center. The
      // harmonic pass separates them before the Winslow barrier iterations.
      initial.resize(boundaryCount + 2, initial[boundaryCount]);
      SmallCavityWinslowOptions winslowOptions = options.winslow;
      winslowOptions.harmonicInitialization = true;
      std::set<ConnectivitySignature> triedConnectivity;
      Candidate best;

      for(const PatternConfiguration &configuration : ranked) {
        Pattern quadrangles = transformPattern(
          patterns[configuration.pattern], boundaryCount,
          configuration.rotation, configuration.reflected, symmetry);
        // Euler's relation fixes this B=10, I=2 disk at six quads, hence the
        // candidate contains no triangle and strictly improves 2 -> 0.
        if(quadrangles.size() != 6) continue;
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
        if(!validInterior || interiorDegree[0] != 4 ||
           interiorDegree[1] != 4)
          continue;
        const ConnectivitySignature connectivity =
          candidateConnectivitySignature(quadrangles, boundaryCount,
                                         {0, 1});
        if(!triedConnectivity.insert(connectivity).second) continue;

        // This dedicated rewrite is accepted only if its all-quad topology
        // is valence-Pareto admissible. Test that integer-only invariant
        // before Winslow, projection and C+C' geometry validation.
        const ValenceObjective candidateValence =
          candidatePatchValence(seed, quadrangles, 2);
        if(!noWorseValencePareto(candidateValence, seed.valence)) {
          ++result.rejectedByQuality;
          continue;
        }

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
        // Preserve the retained half of the core Winslow split as the
        // initial state of the mandatory C+C' solve. The live center is not
        // moved while candidate configurations are being evaluated.
        const std::vector<Candidate::VertexGeometry> coreInitialGeometry = {{
          seed.patch.intVertices.front(), uv[boundaryCount],
          xyz[boundaryCount]}};
        std::vector<Candidate::VertexGeometry> smoothedVertices;
        CavityEvaluationMetrics metrics;
        if(!prepareQuadCavityEvaluation(
             face, seed, quadrangles,
             {0, std::numeric_limits<std::size_t>::max()}, topology,
             options, uv, xyz, smoothedVertices, metrics, nullptr,
             &coreInitialGeometry)) {
          ++result.rejectedByWinslow;
          continue;
        }
        std::size_t coreInvalidElementCount = 0;
        const SpecificationObjective coreObjective = candidateObjective(
          quadrangles, xyz, &coreInvalidElementCount);
        const double maximumWarping =
          maximumCandidateWarpingDegrees(quadrangles, xyz);
        // This rule removes both triangles. Every quad it creates must satisfy
        // every absolute criterion; aggregate improvement is not sufficient
        // for a triangle-to-all-quad rewrite.
        if(coreInvalidElementCount != 0 ||
           coreObjective.absoluteBadElementCount != 0 ||
           !(maximumWarping < absoluteMaximumQuadWarpingDegrees) ||
           !candidateQuadranglesAreNonConcave(quadrangles, uv, xyz)) {
          ++result.rejectedByQuality;
          continue;
        }
        const SpecificationObjective &objective = metrics.candidateObjective;
        const SizeScore &size = metrics.candidateSize;
        const CleanUpDecisionReason decision =
          objective.absoluteBadElementCount <
              metrics.referenceObjective.absoluteBadElementCount ?
            CleanUpDecisionReason::FewerUnacceptableElements :
            CleanUpDecisionReason::OtherImprovement;
        if(!decisionAllowed(decision, phase)) {
          continue;
        }

        Candidate candidate;
        candidate.valid = true;
        candidate.uv = std::move(uv);
        candidate.xyz = std::move(xyz);
        candidate.quadrangles = std::move(quadrangles);
        candidate.objective = objective;
        candidate.invalidElementCount = objective.invalidElementCount;
        candidate.geometry = metrics.candidateGeometry;
        candidate.referenceGeometry = metrics.referenceGeometry;
        candidate.sizeError = size.meanSquaredLogRatio;
        candidate.sizeViolationCount =
          size.belowMinimum + size.aboveMaximum + size.invalid;
        candidate.valence = candidateValence;
        candidate.decisionReason = decision;
        candidate.smoothedVertices = std::move(smoothedVertices);
        if(!betterByQualityThenSize(
             candidate.objective, candidate.sizeError, best, options))
          continue;
        best = std::move(candidate);
      }
      if(!best.valid) return false;
      std::vector<MVertex *> interior;
      // The transaction reuses the old center, creates one face vertex,
      // orients all six quads, and validates the replacement in a copied
      // persistent half-edge topology before mutating the GFace mesh.
      if(!executeValenceSixCandidate(
           face, seed, best, topology, interior))
        return false;
      applySmoothedReplacementGeometry(best.smoothedVertices, topology);
      return true;
    }

    bool tryTriangleQuadTriangleFanWithNewCenter(
      GFace *face, const CavitySeed &seed,
      FaceHalfEdgeTopology &topology,
      const SmallCavityOptimizerOptions &options,
      SmallCavityOptimizerResult &result, CleanUpDecisionPhase phase,
      HalfEdgeRewriteSymmetry symmetry)
    {
      const std::size_t boundaryCount =
        seed.patch.bdrVertices.front().size();
      if(boundaryCount < 6 || boundaryCount % 2 ||
         !seed.patch.intVertices.empty())
        return false;
      const std::shared_ptr<const CachedPatternOrbit> orbit =
        cachedPatternOrbit(boundaryCount, 1, symmetry);
      if(!orbit->valid) return false;
      const std::vector<Pattern> &patterns = orbit->patterns;
      const auto ranked = rankPatterns(
        seed.patch, *orbit, options.maximumCleanUpCandidatesPerCavity,
        topology, &seed);
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
      SmallCavityWinslowOptions winslowOptions = options.winslow;
      // The new point must not inherit a potentially poor polygon-centroid
      // seed on a curved or strongly anisotropic boundary fan. Let the same
      // harmonic initializer used by the generic disk machinery place it
      // before the nonlinear barrier solve.
      winslowOptions.harmonicInitialization = true;
      std::set<ConnectivitySignature> triedConnectivity;
      Candidate best;

      for(const PatternConfiguration &configuration : ranked) {
        Pattern quadrangles = transformPattern(
          patterns[configuration.pattern], boundaryCount,
          configuration.rotation, configuration.reflected, symmetry);
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
        std::vector<Candidate::VertexGeometry> smoothedVertices;
        CavityEvaluationMetrics metrics;
        if(!prepareQuadCavityEvaluation(
             face, seed, quadrangles,
             {std::numeric_limits<std::size_t>::max()}, topology,
             options, uv, xyz, smoothedVertices, metrics, nullptr,
             nullptr, true, true)) {
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
        const SpecificationObjective coreObjective = candidateObjective(
          candidate.quadrangles, candidate.xyz);
        if(coreObjective.invalidElementCount != 0 ||
           (!options.acceptValidTopologyReduction &&
            coreObjective.absoluteBadElementCount != 0) ||
           !candidateQuadranglesAreNonConcave(
             candidate.quadrangles, candidate.uv, candidate.xyz)) {
          ++result.rejectedByQuality;
          continue;
        }
        candidate.objective = metrics.candidateObjective;
        candidate.geometry = metrics.candidateGeometry;
        candidate.referenceGeometry = metrics.referenceGeometry;
        const double target = options.targetSize > 0. ?
          options.targetSize :
          std::sqrt(std::max(
            metrics.referenceGeometry.sampledArea /
              static_cast<double>(std::max<std::size_t>(
                1, metrics.referenceGeometry.elementCount)),
            std::numeric_limits<double>::min()));
        double normalizedCadChange = 0.;
        double normalizedMaximumCadDistanceChange = 0.;
        const bool boundedCadRegression = geometryRegressionFitsMeshScale(
          candidate.geometry, candidate.referenceGeometry, target,
          options, normalizedCadChange,
          normalizedMaximumCadDistanceChange);
        if(!options.acceptValidTopologyReduction &&
           !boundedCadRegression) {
          ++result.rejectedByQuality;
          if(options.verbose > 2)
            Msg::Info("QuadOptimizer boundary T-Q^k-T rejected "
                      "mesh-scaled CAD regression dCAD=%g dCADmax/h=%g",
                      normalizedCadChange,
                      normalizedMaximumCadDistanceChange);
          continue;
        }
        const SizeScore &size = metrics.candidateSize;
        candidate.sizeError = size.meanSquaredLogRatio;
        candidate.sizeViolationCount =
          size.belowMinimum + size.aboveMaximum + size.invalid;
        candidate.smoothedVertices = std::move(smoothedVertices);
        if(!options.acceptValidTopologyReduction &&
           !noWorseAbsoluteSpecifications(
             candidate.objective, metrics.referenceObjective,
             options.objectiveRelativeTolerance)) {
          ++result.rejectedByQuality;
          continue;
        }
        if(!betterByQualityThenSize(
             candidate.objective, candidate.sizeError, best, options))
          continue;
        best = std::move(candidate);
      }
      if(!best.valid) return false;
      MVertex *created = nullptr;
      if(!executeNewInteriorCandidate(face, seed, best, topology, created))
        return false;
      applySmoothedReplacementGeometry(best.smoothedVertices, topology);
      return true;
    }

    bool tryCavity(GFace *face, const CavitySeed &seed,
                   FaceHalfEdgeTopology &topology,
                   const SmallCavityOptimizerOptions &options,
                   SmallCavityOptimizerResult &result,
                   CleanUpDecisionPhase phase,
                   HalfEdgeRewriteSymmetry symmetry,
                   std::set<Edge> *removedQuadSwapEdges = nullptr,
                   std::set<QuadSwapTransition> *quadSwapTransitions = nullptr,
                   const std::set<MVertex *> *additionalProtectedVertices =
                     nullptr)
    {
      ++result.cavitiesVisited;
      if(!seed.alwaysTryTopology &&
         options.topologyOnlyIfCavityHasSpecificationFailure &&
         !hasQuadFailingAbsoluteSpecifications(seed)) {
        ++result.skippedSpecificationCompliant;
        return false;
      }
      const std::size_t boundaryCount = seed.patch.bdrVertices.front().size();
      const std::shared_ptr<const CachedPatternOrbit> orbit =
        cachedPatternOrbit(
          boundaryCount, seed.interiorVertexCount, symmetry);
      if(!orbit->valid) return false;
      const std::vector<Pattern> &patterns = orbit->patterns;
      const auto ranked = rankPatterns(
        seed.patch, *orbit, options.maximumTopologyCandidatesPerCavity,
        topology, &seed);
      ConnectivitySignature existingConnectivity;
      const bool existingIsAllQuad =
        existingConnectivitySignature(seed.patch, existingConnectivity);
      CavityEvaluationReference evaluationReference;
      if(!prepareCavityEvaluationReference(
           face, seed.patch.elements, topology, options,
           seed.halfEdgeCavity, additionalProtectedVertices,
           evaluationReference))
        return false;
      std::set<ConnectivitySignature> triedConnectivity;
      std::size_t localCandidates = 0, localWinslowRejected = 0;
      std::size_t localSizeRejected = 0, localQualityRejected = 0;
      std::size_t localSizeBoundsRejected = 0, localSizeErrorRejected = 0;
      bool hasBestEvaluatedObjective = false;
      SpecificationObjective bestEvaluatedObjective;
      const QuadEquiangularObjective referenceEquiangular =
        seed.kind == CavityPurpose::Edge ?
          quadEquiangularObjective(seed.patch.elements) :
          QuadEquiangularObjective();
      const bool allowEquiangularTradeoff =
        seed.kind == CavityPurpose::Edge &&
        options.stagedTopologyThenQuality &&
        options.evaluateCandidatesWithoutLocalSmoothing;

      enum class PreCadRejection {
        None,
        NoIntersection,
        NonConvex,
        Objective,
        NotBetter
      };
      Candidate best;
      for(const PatternConfiguration &configuration : ranked) {
        Pattern quadrangles = transformPattern(
          patterns[configuration.pattern], boundaryCount,
          configuration.rotation, configuration.reflected, symmetry);
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
          if(seed.kind == CavityPurpose::Edge) {
            IndexedEdge oldIndexed, newIndexed;
            if(!existingInteriorEdge(seed, oldIndexed) ||
               !candidateInteriorEdge(
                 quadrangles, boundaryCount, newIndexed))
              continue;
            const std::vector<MVertex *> &boundary =
              seed.patch.bdrVertices.front();
            const Edge oldEdge = canonicalEdge(
              boundary[oldIndexed.first], boundary[oldIndexed.second]);
            const Edge newEdge = canonicalEdge(
              boundary[newIndexed.first], boundary[newIndexed.second]);
            if(removedQuadSwapEdges &&
               removedQuadSwapEdges->find(newEdge) !=
                 removedQuadSwapEdges->end())
              continue;
            if(quadSwapTransitions) {
              QuadSwapTransition transition = {oldEdge, newEdge};
              if(transition.second < transition.first)
                std::swap(transition.first, transition.second);
              if(quadSwapTransitions->find(transition) !=
                 quadSwapTransitions->end())
                continue;
            }
          }
          std::vector<UV> uv;
          std::vector<Point> xyz;
          std::vector<Candidate::VertexGeometry> smoothedVertices;
          CavityEvaluationMetrics metrics;
          PreCadRejection preCadRejection = PreCadRejection::None;
          bool candidateUsesEquiangularTradeoff = false;
          const CavityPreCadGate preCadGate =
            [&](const SmoothedCavityEvaluation &cheapEvaluation) {
              if(seed.kind == CavityPurpose::Edge) {
                std::vector<MVertex *> localVertices =
                  seed.patch.bdrVertices.front();
                localVertices.insert(
                  localVertices.end(), seed.patch.intVertices.begin(),
                  seed.patch.intVertices.end());
                std::vector<UV> coreUv(localVertices.size());
                std::vector<Point> coreXyz(localVertices.size());
                for(std::size_t i = 0; i < localVertices.size(); ++i) {
                  const auto found =
                    cheapEvaluation.index.find(localVertices[i]);
                  if(found == cheapEvaluation.index.end()) {
                    preCadRejection = PreCadRejection::NoIntersection;
                    return false;
                  }
                  coreUv[i] = cheapEvaluation.uv[found->second];
                  coreXyz[i] = cheapEvaluation.xyz[found->second];
                }
                if(!edgeSwapEdgesIntersect(seed, quadrangles, coreUv)) {
                  preCadRejection = PreCadRejection::NoIntersection;
                  return false;
                }
                if(!candidateQuadsAreStrictlyConvex(
                     quadrangles, coreUv)) {
                  preCadRejection = PreCadRejection::NonConvex;
                  return false;
                }
                candidateUsesEquiangularTradeoff =
                  allowEquiangularTradeoff &&
                  improvesQuadEquiangularObjective(
                    quadEquiangularObjective(quadrangles, coreXyz),
                    referenceEquiangular,
                    options.objectiveRelativeTolerance);
              }

              const CavityEvaluationMetrics &cheap =
                cheapEvaluation.metrics;
              const bool improvesShape =
                (noWorseAbsoluteSpecifications(
                   cheap.candidateObjective, cheap.referenceObjective,
                   options.objectiveRelativeTolerance) &&
                 improvesSpecificationObjective(
                   cheap.candidateObjective, cheap.referenceObjective,
                   options.objectiveRelativeTolerance)) ||
                candidateUsesEquiangularTradeoff;
              const bool improvesConnectivity =
                seed.kind == CavityPurpose::Edge &&
                noWorseAbsoluteSpecifications(
                  cheap.candidateObjective, cheap.referenceObjective,
                  options.objectiveRelativeTolerance) &&
                improvesValence(
                  candidatePatchValence(
                    seed, quadrangles, assignment.size()),
                  seed.valence);
              const CleanUpDecisionReason decision =
                improvesShape || improvesConnectivity ?
                  CleanUpDecisionReason::OtherImprovement :
                  CleanUpDecisionReason::Rejected;
              if(!decisionAllowed(decision, phase)) {
                preCadRejection = PreCadRejection::Objective;
                return false;
              }
              if(!betterByQualityThenSize(
                   cheap.candidateObjective,
                   cheap.candidateSize.meanSquaredLogRatio, best,
                   options)) {
                preCadRejection = PreCadRejection::NotBetter;
                return false;
              }
              return true;
            };
          ++result.topologyCandidatesOptimized;
          ++localCandidates;
          // These patterns retain every interior vertex. Construct the new
          // connectivity directly in C, then perform the sole nonlinear
          // solve on the actual evaluation domain C+C'. A separate solve of
          // C would only project the same vertices twice and its result is
          // not the state accepted by the transaction.
          if(!prepareQuadCavityEvaluation(
               face, seed, quadrangles, assignment, topology, options,
               uv, xyz, smoothedVertices, metrics,
               additionalProtectedVertices, nullptr, false, false,
               &evaluationReference, &preCadGate,
               allowEquiangularTradeoff)) {
            if(preCadRejection == PreCadRejection::NoIntersection) {
              ++result.rejectedEdgeSwapsNoIntersection;
              continue;
            }
            if(preCadRejection == PreCadRejection::NonConvex) {
              ++result.rejectedEdgeSwapsNonConvex;
              continue;
            }
            if(preCadRejection == PreCadRejection::Objective) {
              ++result.rejectedByQuality;
              ++localQualityRejected;
              continue;
            }
            if(preCadRejection == PreCadRejection::NotBetter) continue;
            ++result.rejectedByWinslow;
            ++localWinslowRejected;
            continue;
          }
          Candidate candidate;
          candidate.valid = true;
          candidate.uv = std::move(uv);
          candidate.xyz = std::move(xyz);
          candidate.quadrangles = quadrangles;
          candidate.interiorAssignment = assignment;
          candidate.smoothedVertices = std::move(smoothedVertices);
          candidate.objective = metrics.candidateObjective;
          candidate.referenceGeometry = metrics.referenceGeometry;
          candidate.geometry = metrics.candidateGeometry;
          candidate.sizeError = metrics.candidateSize.meanSquaredLogRatio;
          candidate.sizeViolationCount =
            metrics.candidateSize.belowMinimum +
            metrics.candidateSize.aboveMaximum +
            metrics.candidateSize.invalid;
          candidate.valence = candidatePatchValence(
            seed, candidate.quadrangles, assignment.size());
          const SpecificationObjective &referenceObjective =
            metrics.referenceObjective;
          if(!hasBestEvaluatedObjective || improvesSpecificationObjective(
               candidate.objective, bestEvaluatedObjective,
               options.objectiveRelativeTolerance)) {
            bestEvaluatedObjective = candidate.objective;
            hasBestEvaluatedObjective = true;
          }
          const bool improvesShape =
            (noWorseAbsoluteSpecifications(
               candidate.objective, referenceObjective,
               options.objectiveRelativeTolerance) &&
             improvesSpecificationObjective(
               candidate.objective, referenceObjective,
               options.objectiveRelativeTolerance)) ||
            candidateUsesEquiangularTradeoff;
          const bool improvesConnectivity =
            seed.kind == CavityPurpose::Edge &&
            noWorseAbsoluteSpecifications(
              candidate.objective, referenceObjective,
              options.objectiveRelativeTolerance) &&
            improvesValence(candidate.valence, seed.valence);
          const CleanUpDecisionReason decision =
            improvesShape || improvesConnectivity ?
              CleanUpDecisionReason::OtherImprovement :
              CleanUpDecisionReason::Rejected;
          candidate.decisionReason = decision;
          const bool acceptedByObjective = decisionAllowed(decision, phase);
          if(!acceptedByObjective) {
            ++result.rejectedByQuality;
            ++localQualityRejected;
            continue;
          }
          if(!betterByQualityThenSize(
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
      if(options.verbose && seed.kind == CavityPurpose::Edge) {
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
          Msg::Info("QuadOptimizer swap face %d: %zu-%zu -> %zu-%zu "
                    "reason=%s dE2=%.17g",
                    face->tag(), boundary[oldEdge.first]->getNum(),
                    boundary[oldEdge.second]->getNum(),
                    boundary[newEdge.first]->getNum(),
                    boundary[newEdge.second]->getNum(), reason,
                    geometryChange);
        }
      }
      std::vector<MVertex *> createdInterior;
      Edge removedQuadSwapEdge = {nullptr, nullptr};
      QuadSwapTransition acceptedQuadSwapTransition;
      bool recordQuadSwap = false;
      if(seed.kind == CavityPurpose::Edge) {
        IndexedEdge oldIndexed, newIndexed;
        const std::vector<MVertex *> &boundary =
          seed.patch.bdrVertices.front();
        if(existingInteriorEdge(seed, oldIndexed) &&
           candidateInteriorEdge(
             best.quadrangles, boundary.size(), newIndexed)) {
          removedQuadSwapEdge = canonicalEdge(
            boundary[oldIndexed.first], boundary[oldIndexed.second]);
          const Edge newEdge = canonicalEdge(
            boundary[newIndexed.first], boundary[newIndexed.second]);
          acceptedQuadSwapTransition = {removedQuadSwapEdge, newEdge};
          if(acceptedQuadSwapTransition.second <
             acceptedQuadSwapTransition.first)
            std::swap(acceptedQuadSwapTransition.first,
                      acceptedQuadSwapTransition.second);
          recordQuadSwap = true;
        }
      }
      if(!executeCandidate(face, seed, best, topology, &createdInterior))
        return false;
      applySmoothedReplacementGeometry(best.smoothedVertices, topology);
      if(recordQuadSwap) {
        if(removedQuadSwapEdges)
          removedQuadSwapEdges->insert(removedQuadSwapEdge);
        if(quadSwapTransitions)
          quadSwapTransitions->insert(acceptedQuadSwapTransition);
      }
      return true;
    }

    bool tryFlexibleCleanUpCavity(
      GFace *face, const CavitySeed &seed,
      const SmallCavityOptimizerOptions &options,
      SmallCavityOptimizerResult &result,
      FaceHalfEdgeTopology *topology,
      CleanUpDecisionPhase phase,
      HalfEdgeRewriteSymmetry symmetry,
      std::set<MVertex *> &fastCadProtectedVertices,
      int requiredInteriorVertexCount = -1,
      std::size_t retainedInteriorVertex = 0)
    {
      ++result.cavitiesVisited;
      ++result.cleanUpCavitiesVisited;
      if(!topology) return false;
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
      // The interactive catalog contains explicit operators through the
      // twelve-boundary-vertex valence-six/strip configurations requested by
      // the cleanup rules. Larger disks belong to the exhaustive legacy
      // remesher: searching their thousands of arbitrary quadrangulations is
      // neither a published local pattern nor compatible with an interactive
      // cleanup budget.
      const bool fastInteractive = useFastInteractiveCleanUp(options);
      if(fastInteractive && boundaryCount > 12) return false;

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
      std::vector<Point> boundaryXyz(boundaryCount);
      for(std::size_t i = 0; i < boundaryCount; ++i) {
        MVertex *vertex = seed.patch.bdrVertices.front()[i];
        boundaryXyz[i] = {vertex->x(), vertex->y(), vertex->z()};
      }

      SmallCavityWinslowOptions winslowOptions = options.winslow;
      winslowOptions.harmonicInitialization = true;
      ConnectivitySignature existingConnectivity;
      const bool existingIsAllQuad =
        existingConnectivitySignature(seed.patch, existingConnectivity);
      CavityEvaluationReference evaluationReference;
      if(!prepareCavityEvaluationReference(
           face, seed.patch.elements, *topology, options,
           seed.halfEdgeCavity, &fastCadProtectedVertices,
           evaluationReference))
        return false;
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
          candidate.referenceObjective;
        const std::size_t referenceSizeViolations =
          candidate.referenceSize.belowMinimum +
          candidate.referenceSize.aboveMaximum +
          candidate.referenceSize.invalid;
        const double referenceSizeError =
          candidate.referenceSize.meanSquaredLogRatio;
        const double cadTolerance = candidate.hasEdgeSwapCad ?
          1.e-12 * std::max(1., candidate.edgeSwapCadScale) : 0.;
        const bool cadDoesNotRegress = !candidate.hasEdgeSwapCad ||
          candidate.edgeSwapCadDistance <=
            candidate.referenceEdgeSwapCadDistance + cadTolerance;
        const FastGlobalQuality referenceFastQuality = fastGlobalQuality(
          referenceObjective, seed.valence,
          candidate.referenceInvalidElementCount,
          referenceSizeViolations, referenceSizeError,
          candidate.referenceSize.edgeCount, 0.);
        const bool fastQualityImprovement = !fastInteractive ||
          (cadDoesNotRegress && improvesFastGlobalQuality(
            candidateFastQuality(candidate),
            referenceFastQuality));
        const bool specificationImprovement = improvesSpecificationObjective(
          candidate.objective, referenceObjective,
          options.objectiveRelativeTolerance);
        // Dedicated acyclic reductions (for example the general fallback of
        // a diamond I=2 -> I=1) have already passed the complete C+C'
        // validity, orientation, convexity, size and CAD transaction above.
        // In the staged topology pass, removing an interior vertex is the
        // monotone objective; a soft shape aggregate must not veto it.
        if(options.acceptValidTopologyReduction &&
           candidate.interiorAssignment.size() <
             seed.patch.intVertices.size()) {
          if(!candidate.referenceGeometry.valid ||
             !candidate.geometry.valid)
            return CleanUpDecisionReason::Rejected;
          const bool introducesSeverePole =
            candidate.valence.severeCount > seed.valence.severeCount;
          const bool boundedValenceTrade =
            candidate.valence.severeCount <= seed.valence.severeCount + 1 &&
            candidate.valence.irregularCount <= seed.valence.irregularCount &&
            (!introducesSeverePole ||
             candidate.valence.irregularCount < seed.valence.irregularCount) &&
            candidate.valence.penalty <= seed.valence.penalty + 2. +
              options.objectiveRelativeTolerance * std::max(
                {1., candidate.valence.penalty, seed.valence.penalty});
          const double target = options.targetSize > 0. ?
            options.targetSize :
            std::sqrt(std::max(
              candidate.referenceGeometry.sampledArea /
                static_cast<double>(std::max<std::size_t>(
                  1, candidate.referenceGeometry.elementCount)),
              std::numeric_limits<double>::min()));
          double normalizedCadChange = 0.;
          double normalizedMaximumCadDistanceChange = 0.;
          const bool boundedCadRegression = geometryRegressionFitsMeshScale(
            candidate.geometry, candidate.referenceGeometry, target, options,
            normalizedCadChange,
            normalizedMaximumCadDistanceChange);
          return boundedValenceTrade && boundedCadRegression ?
            CleanUpDecisionReason::OtherImprovement :
            CleanUpDecisionReason::Rejected;
        }
        if(seed.kind == CavityPurpose::CleanUpShape)
          return specificationImprovement && fastQualityImprovement ?
            CleanUpDecisionReason::OtherImprovement :
            CleanUpDecisionReason::Rejected;
        if(seed.kind == CavityPurpose::CleanUpConnectivity ||
           seed.kind == CavityPurpose::CleanUpBoundary)
          return (specificationImprovement ||
            (noWorseAbsoluteSpecifications(
               candidate.objective, referenceObjective,
               options.objectiveRelativeTolerance) &&
             improvesValence(candidate.valence, seed.valence))) &&
              fastQualityImprovement ?
            CleanUpDecisionReason::OtherImprovement :
            CleanUpDecisionReason::Rejected;
        if(seed.kind == CavityPurpose::CleanUpSize)
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

      // Rank the complete orbit, then give only a small deterministic
      // shortlist a bounded Winslow solve. Non-Fast mode may subsequently
      // refine its best candidates with the fully configured solve.
      SmallCavityWinslowOptions screeningOptions = winslowOptions;
      screeningOptions.maxInnerIterations =
        std::min(screeningOptions.maxInnerIterations, 20);
      screeningOptions.maxOuterIterations = 1;
      screeningOptions.maxLineSearchSteps =
        std::min(screeningOptions.maxLineSearchSteps, 12);
      std::vector<Candidate> screened;
      const int interiorMaximum =
        std::max(0, options.maximumCleanUpInteriorVertices);
      // Vertex creation/collapse is represented by the dedicated valence-six,
      // diamond, fan and T/Q rules. The generic Fast disk rule only changes
      // connectivity/shape, so preserve its interior vertex count instead of
      // searching five unrelated topology families for every cavity.
      if(requiredInteriorVertexCount > interiorMaximum) return false;
      const int interiorMinimum = requiredInteriorVertexCount >= 0 ?
        requiredInteriorVertexCount :
        (fastInteractive ?
           std::min(interiorMaximum,
                    static_cast<int>(seed.patch.intVertices.size())) : 0);
      const int interiorEnd = requiredInteriorVertexCount >= 0 ?
        requiredInteriorVertexCount :
        (fastInteractive ? interiorMinimum : interiorMaximum);
      // Every dihedral configuration participates in rankPatterns' valence
      // score. The nonlinear map/Winslow stage is deliberately bounded: it
      // is a geometric optimizer, not part of half-edge pattern matching.
      // Fast divides its explicit Winslow budget between all interior counts
      // so I=0...I=max each keep at least one representative instead of the
      // first count consuming every nonlinear solve.
      const int geometricCandidateBudget = fastInteractive ?
        options.maximumCleanUpWinslowCandidatesPerCavity :
        options.maximumCleanUpCandidatesPerCavity;
      const int perInteriorMaximum = requiredInteriorVertexCount >= 0 ?
        geometricCandidateBudget :
        std::max(1, geometricCandidateBudget /
                      std::max(1, interiorMaximum + 1));
      for(int interior = interiorMinimum; interior <= interiorEnd;
          ++interior) {
        const std::shared_ptr<const CachedPatternOrbit> orbit =
          cachedPatternOrbit(
            boundaryCount, static_cast<std::size_t>(interior), symmetry);
        if(!orbit->valid) continue;
        const std::vector<Pattern> &patterns = orbit->patterns;
        const std::vector<PatternConfiguration> ranked = rankPatterns(
          seed.patch, *orbit, perInteriorMaximum, *topology, &seed);
        for(const PatternConfiguration &configuration : ranked) {
          Pattern quadrangles = transformPattern(
            patterns[configuration.pattern], boundaryCount,
            configuration.rotation, configuration.reflected, symmetry);
          const ConnectivitySignature connectivity =
            HalfEdgeRewrite::canonicalConnectivityIgnoringInteriorLabels(
              quadrangles, boundaryCount);
          if((existingIsAllQuad &&
              static_cast<std::size_t>(interior) ==
                seed.patch.intVertices.size() &&
              connectivity == existingConnectivity) ||
             !triedConnectivity.insert(connectivity).second)
            continue;
          const bool isRetainedTwoQuadCandidate =
            seed.patch.intVertices.empty() &&
            seed.patch.elements.size() == 2 && interior == 0 &&
            quadrangles.size() == 2;
          // This is an exact pre-Winslow invariant: both endpoints of such
          // a new chord are on the immutable cavity boundary.  Never use
          // harmonic positions of movable interior vertices as a rejection
          // criterion; their complete size audit remains after Winslow.
          if(!isRetainedTwoQuadCandidate &&
             !immutableCandidateChordsRespectSize(
               face, boundary, boundaryXyz, quadrangles, options)) {
            ++result.rejectedBySize;
            continue;
          }

          std::vector<UV> uv = boundary;
          uv.resize(boundaryCount + static_cast<std::size_t>(interior),
                    centroid);
          std::vector<Point> xyz;
          std::vector<Candidate::VertexGeometry> smoothedVertices;
          std::vector<Candidate::VertexGeometry> coreInitialGeometry;
          CavityEvaluationMetrics metrics;
          const std::size_t createdMarker =
            std::numeric_limits<std::size_t>::max();
          std::vector<std::size_t> candidateAssignment(
            static_cast<std::size_t>(interior), createdMarker);
          const std::size_t retainedCount = std::min(
            candidateAssignment.size(), seed.patch.intVertices.size());
          for(std::size_t i = 0; i < retainedCount; ++i) {
            if(requiredInteriorVertexCount >= 0 && i == 0) {
              if(retainedInteriorVertex >= seed.patch.intVertices.size())
                return false;
              candidateAssignment[i] = retainedInteriorVertex;
            }
            else
              candidateAssignment[i] = i;
          }
          ++result.topologyCandidatesOptimized;
          const bool hasCreatedInteriorVertex =
            retainedCount < candidateAssignment.size();
          if(interior > 0 &&
             (!fastInteractive || hasCreatedInteriorVertex)) {
            SmallCavityWinslowOptions candidateScreeningOptions =
              screeningOptions;
            if(fastInteractive) {
              // The linear harmonic map is only the initializer. Any
              // candidate that reaches a quality or mobile-edge size
              // decision below has first received a genuine Winslow solve.
              if(!initializeSmallQuadCavityHarmonic(
                   uv, boundaryCount, quadrangles)) {
                ++result.rejectedByWinslow;
                continue;
              }
              candidateScreeningOptions.harmonicInitialization = false;
            }
            const SmallCavityWinslowResult winslow =
              optimizeSmallQuadCavityWinslow(
                uv, boundaryCount, quadrangles,
                candidateScreeningOptions);
            if(!winslow.success || !winslow.untangled) {
              ++result.rejectedByWinslow;
              continue;
            }
            if(!mapCandidate(face, boundaryCount,
                             seed.patch.bdrVertices.front(), uv, xyz)) {
              ++result.rejectedByWinslow;
              continue;
            }
            if(retainedCount) {
              coreInitialGeometry.reserve(retainedCount);
              for(std::size_t i = 0; i < retainedCount; ++i) {
                const std::size_t local = boundaryCount + i;
                coreInitialGeometry.push_back(
                  {seed.patch.intVertices[candidateAssignment[i]],
                   uv[local], xyz[local]});
              }
            }
          }
          // Fast generic disks retain their interior vertices. Their only
          // meaningful geometry is the C+C' Winslow state below, so avoid a
          // redundant core-only solve and a first round of CAD projections.
          if(!prepareQuadCavityEvaluation(
               face, seed, quadrangles, candidateAssignment, *topology,
               options, uv, xyz, smoothedVertices, metrics,
               &fastCadProtectedVertices,
               coreInitialGeometry.empty() ? nullptr :
                                             &coreInitialGeometry,
               false, false, &evaluationReference)) {
            ++result.rejectedByWinslow;
            continue;
          }
          const SizeScore &size = metrics.candidateSize;
          const bool checkSize = options.enforceSizeMap ||
                                 seed.kind == CavityPurpose::CleanUpSize;
          const bool preservesTarget = !options.enforceSizeMap ||
            admissibleSizeChange(metrics.referenceSize, size, options);
          if(checkSize && !options.acceptValidTopologyReduction &&
             (!size.admissible || !preservesTarget)) {
            ++result.rejectedBySize;
            continue;
          }

          Candidate candidate;
          candidate.valid = true;
          candidate.uv = std::move(uv);
          candidate.xyz = std::move(xyz);
          candidate.quadrangles = std::move(quadrangles);
          candidate.smoothedVertices = std::move(smoothedVertices);
          candidate.objective = metrics.candidateObjective;
          candidate.referenceObjective = metrics.referenceObjective;
          candidate.invalidElementCount =
            metrics.candidateObjective.invalidElementCount;
          candidate.referenceSize = metrics.referenceSize;
          candidate.referenceInvalidElementCount =
            metrics.referenceObjective.invalidElementCount;
          candidate.geometry = metrics.candidateGeometry;
          candidate.referenceGeometry = metrics.referenceGeometry;
          if(fastInteractive &&
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
          candidate.interiorAssignment = std::move(candidateAssignment);

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
        if(fastInteractive &&
           !candidateQuadranglesAreNonConcave(
             candidate.quadrangles, candidate.uv, candidate.xyz)) {
          ++result.rejectedByQuality;
          continue;
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
      const bool isTwoQuadSwitch = fastInteractive && best.hasEdgeSwapCad;
      std::vector<MVertex *> interior;
      if(!executeFlexibleCandidate(face, seed, best, interior,
                                   nullptr, topology))
        return false;
      applySmoothedReplacementGeometry(best.smoothedVertices, *topology);
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

    // A single mixed-disk representation covers every strip
    //
    //   T - Q - ... - Q - T
    //
    // and all its rotations/reflections.  The persistent adjacency remains
    // FaceHalfEdgeTopology; this seed is only the immutable payload of one
    // prospective transaction.
    struct TriangleQuadStripReductionSeed {
      CavitySeed cavity;
      std::array<MTriangle *, 2> triangles = {nullptr, nullptr};
      std::size_t quadrangleCount = 0;
      std::array<std::vector<std::size_t>, 2> rails;
      bool boundaryFan = false;
    };

    // Verbose-only diagnostics for the bounded T-Q^k-T matcher.  The key is
    // the complete mixed input disk, quotiented by all rotations,
    // reflections and interior labels; it consequently groups geometric
    // occurrences of the same half-edge rewrite without relying on element
    // or vertex tags.  Candidate outcomes are exclusive: each configuration
    // is charged to the first gate that rejects it, or to exactly one of the
    // terminal feasible/commit outcomes.
    using MixedConnectivitySignature =
      std::vector<std::vector<std::size_t> >;

    struct TriangleQuadStripDiagnosticKey {
      std::size_t quadrangleCount = 0;
      std::size_t boundaryCount = 0;
      std::size_t interiorCount = 0;
      MixedConnectivitySignature connectivity;

      bool operator<(const TriangleQuadStripDiagnosticKey &other) const
      {
        if(quadrangleCount != other.quadrangleCount)
          return quadrangleCount < other.quadrangleCount;
        if(boundaryCount != other.boundaryCount)
          return boundaryCount < other.boundaryCount;
        if(interiorCount != other.interiorCount)
          return interiorCount < other.interiorCount;
        return connectivity < other.connectivity;
      }
    };

    struct TriangleQuadStripDiagnosticEntry {
      std::size_t matched = 0;
      std::size_t configurations = 0;
      std::size_t setupRejected = 0;
      std::size_t patternRejected = 0;
      std::size_t orientationRejected = 0;
      std::size_t topologyRejected = 0;
      std::size_t constrainedRejected = 0;
      std::size_t invalidRejected = 0;
      std::size_t nonConvexRejected = 0;
      std::size_t qualityRejected = 0;
      std::size_t sizeRejected = 0;
      std::size_t cadRejected = 0;
      std::size_t noImprovement = 0;
      std::size_t dominated = 0;
      std::size_t commitRejected = 0;
      std::size_t accepted = 0;
    };

    struct TriangleQuadStripDiagnostics {
      std::map<TriangleQuadStripDiagnosticKey,
               TriangleQuadStripDiagnosticEntry> entries;

      void clear() { entries.clear(); }
    };

    bool triangleQuadStripDiagnosticKey(
      const TriangleQuadStripReductionSeed &seed,
      TriangleQuadStripDiagnosticKey &key)
    {
      const GFaceMeshPatch &patch = seed.cavity.patch;
      if(patch.bdrVertices.size() != 1) return false;
      const std::vector<MVertex *> &boundary = patch.bdrVertices.front();
      const std::size_t boundaryCount = boundary.size();
      const std::size_t interiorCount = patch.intVertices.size();
      if(boundaryCount == 0) return false;

      std::unordered_map<MVertex *, std::size_t> index;
      index.reserve(boundaryCount + interiorCount);
      for(std::size_t i = 0; i < boundaryCount; ++i)
        if(!boundary[i] || !index.emplace(boundary[i], i).second)
          return false;
      for(std::size_t i = 0; i < interiorCount; ++i)
        if(!patch.intVertices[i] ||
           !index.emplace(patch.intVertices[i], boundaryCount + i).second)
          return false;

      MixedConnectivitySignature input;
      input.reserve(patch.elements.size());
      for(MElement *element : patch.elements) {
        if(!element) return false;
        std::vector<std::size_t> face;
        const std::size_t count = element->getNumPrimaryVertices();
        if(count != 3 && count != 4) return false;
        face.reserve(count);
        for(std::size_t i = 0; i < count; ++i) {
          const auto found = index.find(
            element->getVertex(static_cast<int>(i)));
          if(found == index.end()) return false;
          face.push_back(found->second);
        }
        input.push_back(std::move(face));
      }

      MixedConnectivitySignature canonical;
      bool hasCanonical = false;
      const std::size_t actions = HalfEdgeRewrite::actionCount(
        HalfEdgeRewriteSymmetry::Dihedral, boundaryCount);
      for(std::size_t action = 0; action < actions; ++action) {
        MixedConnectivitySignature transformed;
        transformed.reserve(input.size());
        for(const std::vector<std::size_t> &face : input)
          transformed.push_back(HalfEdgeRewrite::transformFace(
            HalfEdgeRewriteSymmetry::Dihedral, boundaryCount, action,
            face));
        transformed =
          HalfEdgeRewrite::canonicalConnectivityIgnoringInteriorLabels(
            transformed, boundaryCount);
        if(!hasCanonical || transformed < canonical) {
          canonical = std::move(transformed);
          hasCanonical = true;
        }
      }
      if(!hasCanonical) return false;
      key.quadrangleCount = seed.quadrangleCount;
      key.boundaryCount = boundaryCount;
      key.interiorCount = interiorCount;
      key.connectivity = std::move(canonical);
      return true;
    }

    std::uint64_t triangleQuadStripDiagnosticHash(
      const TriangleQuadStripDiagnosticKey &key)
    {
      // Stable FNV-1a shorthand for the log; the map above still compares the
      // complete signature, so a hash collision never merges diagnostics.
      std::uint64_t hash = 1469598103934665603ull;
      auto add = [&](std::size_t value) {
        hash ^= static_cast<std::uint64_t>(value);
        hash *= 1099511628211ull;
      };
      add(key.quadrangleCount);
      add(key.boundaryCount);
      add(key.interiorCount);
      for(const std::vector<std::size_t> &face : key.connectivity) {
        add(face.size());
        for(const std::size_t vertex : face) add(vertex + 1);
        add(0);
      }
      return hash;
    }

    void printTriangleQuadStripDiagnostics(
      GFace *face, const TriangleQuadStripDiagnostics &diagnostics)
    {
      if(diagnostics.entries.empty()) return;
      std::size_t matched = 0, configurations = 0;
      for(const auto &item : diagnostics.entries) {
        matched += item.second.matched;
        configurations += item.second.configurations;
      }
      Msg::Info("QuadOptimizer strip diagnostics face=%d signatures=%zu "
                "matched=%zu configurations=%zu",
                face ? face->tag() : -1, diagnostics.entries.size(),
                matched, configurations);
      for(const auto &item : diagnostics.entries) {
        const TriangleQuadStripDiagnosticKey &key = item.first;
        const TriangleQuadStripDiagnosticEntry &entry = item.second;
        Msg::Info(
          "QuadOptimizer strip signature=%016llx k=%zu B=%zu I=%zu "
          "matched=%zu cfg=%zu setup=%zu pattern=%zu orientation=%zu "
          "topology=%zu constrained=%zu invalid=%zu nonConvex=%zu "
          "quality=%zu size=%zu cad=%zu noImprove=%zu dominated=%zu "
          "commit=%zu accepted=%zu",
          static_cast<unsigned long long>(
            triangleQuadStripDiagnosticHash(key)),
          key.quadrangleCount, key.boundaryCount, key.interiorCount,
          entry.matched, entry.configurations, entry.setupRejected,
          entry.patternRejected, entry.orientationRejected,
          entry.topologyRejected, entry.constrainedRejected,
          entry.invalidRejected, entry.nonConvexRejected,
          entry.qualityRejected, entry.sizeRejected, entry.cadRejected,
          entry.noImprovement, entry.dominated, entry.commitRejected,
          entry.accepted);
      }
    }

    struct TriangleQuadStripReductionCandidate {
      bool valid = false;
      Pattern quadrangles;
      SpecificationObjective objective;
      FastTriangleReductionQuality quality;
      ConnectivitySignature connectivity;
      std::vector<Candidate::VertexGeometry> smoothedVertices;
    };

    std::vector<TriangleQuadStripReductionSeed>
    collectTriangleQuadStripReductions(
      GFace *face, const FaceHalfEdgeTopology &topology,
      std::size_t maximumQuadrangles = 4)
    {
      if(!face || !topology.manifold()) return {};

      std::vector<MTriangle *> triangles;
      for(MElement *element : topology.elements())
        if(MTriangle *triangle = dynamic_cast<MTriangle *>(element))
          triangles.push_back(triangle);
      std::sort(triangles.begin(), triangles.end(),
                [](MTriangle *a, MTriangle *b) {
                  return canonicalElementGeometryLess(a, b);
                });

      std::vector<TriangleQuadStripReductionSeed> seeds;
      std::set<std::vector<std::uintptr_t> > signatures;
      auto addPath = [&](MTriangle *first, MTriangle *second,
                         const std::vector<MElement *> &path,
                         std::size_t quadrangleCount) {
        if(!first || !second || first == second ||
           path.size() != quadrangleCount + 2)
          return;

        std::vector<std::uintptr_t> signature;
        signature.reserve(path.size());
        for(MElement *element : path)
          signature.push_back(reinterpret_cast<std::uintptr_t>(element));
        std::sort(signature.begin(), signature.end());
        if(!signatures.insert(signature).second) return;

        std::size_t foundTriangles = 0, foundQuadrangles = 0;
        for(MElement *element : path) {
          if(dynamic_cast<MTriangle *>(element))
            ++foundTriangles;
          else if(dynamic_cast<MQuadrangle *>(element))
            ++foundQuadrangles;
          else
            return;
        }
        if(foundTriangles != 2 || foundQuadrangles != quadrangleCount)
          return;

        TriangleQuadStripReductionSeed seed;
        Edge anchorEdge = {nullptr, nullptr};
        std::size_t sharedEdgeCount = 0;
        MElement *next = path[1];
        for(std::size_t side = 0;
            side < first->getNumPrimaryVertices(); ++side) {
          const Edge edge = canonicalEdge(
            first->getVertex(static_cast<int>(side)),
            first->getVertex(static_cast<int>(
              (side + 1) % first->getNumPrimaryVertices())));
          bool inNext = false;
          for(std::size_t nextSide = 0;
              nextSide < next->getNumPrimaryVertices(); ++nextSide) {
            const Edge candidate = canonicalEdge(
              next->getVertex(static_cast<int>(nextSide)),
              next->getVertex(static_cast<int>(
                (nextSide + 1) % next->getNumPrimaryVertices())));
            inNext = inNext || candidate == edge;
          }
          if(inNext) {
            anchorEdge = edge;
            ++sharedEdgeCount;
          }
        }
        HalfEdgeMesh::Cavity edgeAnchor, cavity;
        if(sharedEdgeCount != 1 ||
           !topology.cavityAroundEdge(anchorEdge, edgeAnchor) ||
           !topology.cavityFromElements(path, edgeAnchor, cavity) ||
           !materializeCavitySeed(
             face, cavity, topology, seed.cavity) ||
           seed.cavity.patch.elements.size() != path.size() ||
           seed.cavity.patch.bdrVertices.size() != 1 ||
           seed.cavity.patch.bdrVertices.front().size() !=
             2 * quadrangleCount + 4 ||
           !seed.cavity.patch.intVertices.empty() ||
           !seed.cavity.patch.embVertices.empty())
          return;
        seed.cavity.interiorVertexCount = 0;
        seed.cavity.alwaysTryTopology = true;
        seed.cavity.kind = CavityPurpose::CleanUpConnectivity;
        seed.cavity.objective = specificationObjective(
          seed.cavity.patch.elements);
        cacheCavityValence(seed.cavity, topology);
        // A true strip has two opposite-edge rails. Boundary T-Q^k-T fans
        // are also valid direct reductions, but deliberately leave these
        // vectors empty and use the bounded generic fallback below.
        const bool oppositeEdgeStrip = topology.triangleQuadStripRails(
          path, seed.cavity.patch.bdrVertices.front(),
          seed.rails[0], seed.rails[1]);
        seed.boundaryFan = !oppositeEdgeStrip &&
                           topology.triangleQuadBoundaryFan(path);
        if(!oppositeEdgeStrip && !seed.boundaryFan) return;
        seed.triangles = {first, second};
        seed.quadrangleCount = quadrangleCount;
        seeds.push_back(std::move(seed));
      };

      for(MTriangle *start : triangles) {
        std::vector<MElement *> path = {start};
        std::set<MElement *> selected = {start};
        std::function<void(MElement *, std::size_t)> extend;
        extend = [&](MElement *current, std::size_t quadrangleCount) {
          for(MElement *neighbor : topology.neighbors(current)) {
            if(!neighbor || selected.find(neighbor) != selected.end())
              continue;
            if(MTriangle *end = dynamic_cast<MTriangle *>(neighbor)) {
              std::vector<MElement *> complete = path;
              complete.push_back(end);
              addPath(start, end, complete, quadrangleCount);
              continue;
            }
            if(!dynamic_cast<MQuadrangle *>(neighbor) ||
               quadrangleCount >= maximumQuadrangles)
              continue;
            selected.insert(neighbor);
            path.push_back(neighbor);
            extend(neighbor, quadrangleCount + 1);
            path.pop_back();
            selected.erase(neighbor);
          }
        };
        extend(start, 0);
      }

      std::sort(
        seeds.begin(), seeds.end(),
        [](const TriangleQuadStripReductionSeed &a,
           const TriangleQuadStripReductionSeed &b) {
          if(a.quadrangleCount != b.quadrangleCount)
            return a.quadrangleCount < b.quadrangleCount;
          const double ap = objectivePriority(a.cavity.objective);
          const double bp = objectivePriority(b.cavity.objective);
          if(ap != bp) return ap > bp;
          const std::vector<MVertex *> &av =
            a.cavity.patch.bdrVertices.front();
          const std::vector<MVertex *> &bv =
            b.cavity.patch.bdrVertices.front();
          return std::lexicographical_compare(
            av.begin(), av.end(), bv.begin(), bv.end(),
            canonicalVertexGeometryLess);
        });
      return seeds;
    }

    bool tryTriangleQuadStripReduction(
      GFace *face, const TriangleQuadStripReductionSeed &seed,
      FaceHalfEdgeTopology &topology,
      const SmallCavityOptimizerOptions &options,
      SmallCavityOptimizerResult &result, CleanUpDecisionPhase phase,
      std::set<MVertex *> &fastCadProtectedVertices,
      TriangleQuadStripDiagnostics *diagnostics)
    {
      ++result.quadTwoTriangleCavitiesVisited;
      const GFaceMeshPatch &patch = seed.cavity.patch;
      if(!face || !seed.triangles[0] || !seed.triangles[1] ||
         seed.triangles[0] == seed.triangles[1] ||
         phase != CleanUpDecisionPhase::Any ||
         !useFastInteractiveCleanUp(options) || !topology.manifold() ||
         patch.bdrVertices.size() != 1 ||
         patch.bdrVertices.front().size() !=
           2 * seed.quadrangleCount + 4 ||
         patch.elements.size() != seed.quadrangleCount + 2 ||
         !patch.intVertices.empty() || !patch.embVertices.empty())
        return false;

      TriangleQuadStripDiagnosticEntry *diagnostic = nullptr;
      if(diagnostics) {
        TriangleQuadStripDiagnosticKey key;
        if(triangleQuadStripDiagnosticKey(seed, key)) {
          diagnostic = &diagnostics->entries[std::move(key)];
          ++diagnostic->matched;
        }
      }
      auto rejectSetup = [&]() {
        if(diagnostic) ++diagnostic->setupRejected;
        return false;
      };

      if(touchesBoundaryLayerElementData(face, patch.elements))
        return rejectSetup();

      const int partition = patch.elements.front()->getPartition();
      const bool visibility = patch.elements.front()->getVisibility();
      for(MElement *element : patch.elements)
        if(!element || element->getPartition() != partition ||
           element->getVisibility() != visibility)
          return rejectSetup();

      std::set<MEdge, MEdgeLessThan> constrainedEdges;
      auto addConstrainedEdges = [&](const std::vector<GEdge *> &curves) {
        for(GEdge *curve : curves)
          if(curve)
            for(MLine *line : curve->lines)
              if(line)
                constrainedEdges.insert(MEdge(
                  line->getVertex(0), line->getVertex(1)));
      };
      addConstrainedEdges(face->edges());
      addConstrainedEdges(face->getEmbeddedEdges());

      auto preservesConstrainedEdges =
        [&](const std::vector<MElement *> &replacement) {
          std::set<MEdge, MEdgeLessThan> replacementEdges;
          for(MElement *element : replacement) {
            const std::size_t count = element->getNumPrimaryVertices();
            for(std::size_t i = 0; i < count; ++i)
              replacementEdges.insert(MEdge(
                element->getVertex(static_cast<int>(i)),
                element->getVertex(static_cast<int>((i + 1) % count))));
          }
          for(MElement *element : patch.elements) {
            const std::size_t count = element->getNumPrimaryVertices();
            for(std::size_t i = 0; i < count; ++i) {
              const MEdge edge(
                element->getVertex(static_cast<int>(i)),
                element->getVertex(static_cast<int>((i + 1) % count)));
              if(constrainedEdges.find(edge) != constrainedEdges.end() &&
                 replacementEdges.find(edge) == replacementEdges.end())
                return false;
            }
          }
          return true;
      };

      const std::vector<MVertex *> &boundary = patch.bdrVertices.front();
      const std::size_t boundaryCount = boundary.size();
      ValenceObjective referenceValence;
      for(MVertex *vertex : boundary)
        addValence(referenceValence, topology.quadDegree(vertex),
                   idealQuadDegree(face, vertex, topology),
                   vertex->onWhat() == face);

      // This catalog entry is a composition of local TQ swaps followed by
      // TT -> Q, not an arbitrary remeshing of the surrounding polygon.
      // Consequently a true opposite-edge strip has exactly two zipper
      // directions (one for TT), independent of k.  The exhaustive polygon
      // generator remains available to tests and non-interactive tools, but
      // must not turn one Fast pattern into 273 nonlinear solves.
      std::vector<Pattern> patterns;
      if(!seed.rails[0].empty() && !seed.rails[1].empty()) {
        // TT and T-Q-T have only one and three exact fillings respectively;
        // retaining all of them avoids hiding the useful direct TQT -> QQ
        // alternative behind a preceding topology-preserving swap.
        patterns = seed.quadrangleCount <= 1 ?
          HalfEdgeRewrite::triangleQuadStripReconnections(
            seed.rails[0], seed.rails[1]) :
          HalfEdgeRewrite::triangleQuadStripZipperReconnections(
            seed.rails[0], seed.rails[1]);
      }
      else if(seed.boundaryFan) {
        // A boundary fan has no opposite rails. It is still one of the
        // requested T-Q^k-T patterns, so rank its polygon fillings by the
        // integer valence objective and send only a bounded shortlist to
        // C+C' Winslow.
        const std::shared_ptr<const CachedPatternOrbit> orbit =
          cachedPatternOrbit(boundaryCount, 0,
                             HalfEdgeRewriteSymmetry::Dihedral);
        if(!orbit->valid) return rejectSetup();
        const std::vector<PatternConfiguration> ranked = rankPatterns(
          patch, *orbit, options.maximumTopologyCandidatesPerCavity,
          topology, &seed.cavity);
        std::set<ConnectivitySignature> seen;
        for(const PatternConfiguration &configuration : ranked) {
          Pattern pattern = transformPattern(
            orbit->patterns[configuration.pattern], boundaryCount,
            configuration.rotation, configuration.reflected,
            HalfEdgeRewriteSymmetry::Dihedral);
          const ConnectivitySignature connectivity =
            HalfEdgeRewrite::canonicalConnectivityIgnoringInteriorLabels(
              pattern, boundaryCount);
          if(seen.insert(connectivity).second)
            patterns.push_back(std::move(pattern));
        }
      }
      if(patterns.empty()) return rejectSetup();

      CavityEvaluationReference evaluationReference;
      if(!prepareCavityEvaluationReference(
           face, patch.elements, topology, options,
           seed.cavity.halfEdgeCavity, &fastCadProtectedVertices,
           evaluationReference))
        return rejectSetup();

      TriangleQuadStripReductionCandidate best;
      for(const Pattern &pattern : patterns) {
        if(diagnostic) ++diagnostic->configurations;
        if(pattern.size() != seed.quadrangleCount + 1) {
          if(diagnostic) ++diagnostic->patternRejected;
          continue;
        }

        std::vector<MElement *> replacement;
        replacement.reserve(pattern.size());
        for(const auto &quad : pattern) {
          bool indexed = true;
          for(const std::size_t vertex : quad)
            indexed = indexed && vertex < boundaryCount;
          if(!indexed) {
            replacement.clear();
            break;
          }
          MQuadrangle *element = new MQuadrangle(
            boundary[quad[0]], boundary[quad[1]],
            boundary[quad[2]], boundary[quad[3]]);
          element->setPartition(partition);
          element->setVisibility(visibility);
          replacement.push_back(element);
        }
        if(replacement.size() != pattern.size()) {
          for(MElement *element : replacement) delete element;
          if(diagnostic) ++diagnostic->patternRejected;
          continue;
        }
        const bool oriented = orientElementsAccordingToBoundarySegment(
          boundary[0], boundary[1], replacement);
        if(!oriented) {
          for(MElement *element : replacement) delete element;
          if(diagnostic) ++diagnostic->orientationRejected;
          continue;
        }
        if(!topology.validReplacement(patch.elements, replacement)) {
          for(MElement *element : replacement) delete element;
          if(diagnostic) ++diagnostic->topologyRejected;
          continue;
        }
        if(!preservesConstrainedEdges(replacement)) {
          for(MElement *element : replacement) delete element;
          if(diagnostic) ++diagnostic->constrainedRejected;
          continue;
        }

        ++result.topologyCandidatesOptimized;
        SmoothedCavityEvaluation evaluation;
        if(!prepareSmoothedCavityEvaluation(
             face, patch.elements, replacement, topology, options,
             evaluation, seed.cavity.halfEdgeCavity,
             &fastCadProtectedVertices, nullptr, true, true,
             &evaluationReference)) {
          for(MElement *element : replacement) delete element;
          ++result.rejectedByWinslow;
          if(diagnostic) ++diagnostic->qualityRejected;
          continue;
        }

        const CavityEvaluationMetrics &metrics = evaluation.metrics;
        const SpecificationObjective &objective = metrics.candidateObjective;
        const bool nonConcave = objective.invalidElementCount == 0 &&
          candidateQuadranglesAreNonConcave(
            evaluation.quadrangles, evaluation.uv, evaluation.xyz);
        // Reducing two triangles is a sufficient structural improvement only
        // when every quad created by this rewrite satisfies the complete
        // configured all-elements criteria after Winslow (warping, ratio,
        // angles and skewing), not a hand-picked subset of those tests.
        const bool createdQuadsAcceptable =
          options.acceptValidTopologyReduction ||
          quadranglesPassAbsoluteSpecifications(replacement, evaluation);
        if(objective.invalidElementCount != 0 || !nonConcave ||
           !createdQuadsAcceptable) {
          if(options.verbose > 2 &&
             objective.invalidElementCount == 0 && nonConcave &&
             !createdQuadsAcceptable) {
            for(MElement *element : replacement) {
              std::vector<std::size_t> local;
              if(!indexedElement(element, evaluation.index, local)) continue;
              std::vector<Point> points(local.size());
              for(std::size_t i = 0; i < local.size(); ++i)
                points[i] = evaluation.xyz[local[i]];
              const ElementQuality quality = evaluateElementQuality(
                SurfaceElementKind::Quadrangle, points);
              Msg::Info("QuadOptimizer strip rejected quad: angle=%g..%g "
                        "ratio=%g skew=%g warp=%g absolute=%d",
                        quality.minimumAngleDegrees,
                        quality.maximumAngleDegrees, quality.edgeRatio,
                        quality.skewingDegrees, quality.warpingDegrees,
                        quality.passesAbsoluteSpecifications ? 1 : 0);
            }
          }
          for(MElement *element : replacement) delete element;
          if(diagnostic) {
            if(objective.invalidElementCount != 0)
              ++diagnostic->invalidRejected;
            else if(!nonConcave)
              ++diagnostic->nonConvexRejected;
            else
              ++diagnostic->qualityRejected;
          }
          continue;
        }

        // Triangle removal is now judged on the already smoothed candidate.
        // Once the new quads meet every absolute criterion, 2 -> 0 triangles
        // is the strict structural decrease; soft quality and valence terms
        // only rank multiple admissible connectivities.

        ValenceObjective candidateValence;
        for(MVertex *vertex : boundary)
          addValence(candidateValence,
                     topology.quadDegreeAfterReplacement(
                       vertex, patch.elements, replacement),
                     idealQuadDegree(face, vertex, topology),
                     vertex->onWhat() == face);

        const SizeScore &beforeSupportSize = metrics.referenceSize;
        const SizeScore &afterSize = metrics.candidateSize;
        const std::size_t beforeSupportSizeViolations =
          beforeSupportSize.belowMinimum + beforeSupportSize.aboveMaximum +
          beforeSupportSize.invalid;
        const std::size_t afterSizeViolations =
          afterSize.belowMinimum + afterSize.aboveMaximum +
          afterSize.invalid;
        const SpecificationObjective &referenceSupportObjective =
          metrics.referenceObjective;
        const GeometryDeviation &referenceSupportGeometry =
          metrics.referenceGeometry;
        const GeometryDeviation &geometry = metrics.candidateGeometry;
        const double target = options.targetSize > 0. ?
          options.targetSize :
          std::sqrt(std::max(
            referenceSupportGeometry.sampledArea /
              static_cast<double>(std::max<std::size_t>(
                1, referenceSupportGeometry.elementCount)),
            std::numeric_limits<double>::min()));
        double normalizedCadChange = 0.;
        double normalizedMaximumCadDistanceChange = 0.;
        const bool boundedCadRegression = geometryRegressionFitsMeshScale(
          geometry, referenceSupportGeometry, target, options,
          normalizedCadChange, normalizedMaximumCadDistanceChange);
        if((!geometry.valid || !referenceSupportGeometry.valid) ||
           (!options.acceptValidTopologyReduction &&
            !boundedCadRegression)) {
          for(MElement *element : replacement) delete element;
          if(diagnostic) ++diagnostic->cadRejected;
          if(options.verbose > 2)
            Msg::Info("QuadOptimizer strip rejected mesh-scaled CAD "
                      "regression dCAD=%g dCADmax/h=%g",
                      normalizedCadChange,
                      normalizedMaximumCadDistanceChange);
          continue;
        }
        const std::size_t referenceInvalid =
          referenceSupportObjective.invalidElementCount;
        const std::size_t referenceTriangles =
          static_cast<std::size_t>(std::count_if(
            evaluation.beforePatch.elements.begin(),
            evaluation.beforePatch.elements.end(), [](MElement *element) {
              return element && element->getNumPrimaryVertices() == 3;
            }));
        const std::size_t candidateTriangles = evaluation.triangles.size();
        if(candidateTriangles + 2 != referenceTriangles) {
          for(MElement *element : replacement) delete element;
          if(diagnostic) ++diagnostic->patternRejected;
          continue;
        }
        const FastGlobalQuality referenceFast = fastGlobalQuality(
          referenceSupportObjective, referenceValence, referenceInvalid,
          beforeSupportSizeViolations,
          beforeSupportSize.meanSquaredLogRatio,
          beforeSupportSize.edgeCount, 0.);
        const FastGlobalQuality candidateFast = fastGlobalQuality(
          objective, candidateValence, objective.invalidElementCount,
          afterSizeViolations, afterSize.meanSquaredLogRatio,
          afterSize.edgeCount, normalizedCadChange);
        const FastTriangleReductionQuality referenceQuality = {
          referenceInvalid, referenceTriangles, referenceFast};
        const FastTriangleReductionQuality candidateQuality = {
          objective.invalidElementCount, candidateTriangles, candidateFast};
        const ConnectivitySignature connectivity =
          HalfEdgeRewrite::canonicalConnectivityIgnoringInteriorLabels(
            pattern, boundaryCount);
        for(MElement *element : replacement) delete element;

        if(!improvesFastTriangleReductionQuality(
             candidateQuality, referenceQuality)) {
          if(diagnostic) ++diagnostic->noImprovement;
          continue;
        }
        bool better = !best.valid ||
          improvesFastTriangleReductionQuality(candidateQuality,
                                                best.quality);
        if(best.valid &&
           !improvesFastTriangleReductionQuality(candidateQuality,
                                                 best.quality) &&
           !improvesFastTriangleReductionQuality(best.quality,
                                                 candidateQuality))
          better = connectivity < best.connectivity;
        if(!better) {
          if(diagnostic) ++diagnostic->dominated;
          continue;
        }
        if(best.valid && diagnostic) ++diagnostic->dominated;
        best.valid = true;
        best.quadrangles = std::move(pattern);
        best.objective = objective;
        best.quality = candidateQuality;
        best.connectivity = connectivity;
        best.smoothedVertices = std::move(evaluation.movedVertices);
      }
      if(!best.valid) {
        ++result.rejectedByQuality;
        return false;
      }

      std::vector<MElement *> replacement;
      replacement.reserve(best.quadrangles.size());
      for(const auto &quad : best.quadrangles) {
        MQuadrangle *element = new MQuadrangle(
          boundary[quad[0]], boundary[quad[1]],
          boundary[quad[2]], boundary[quad[3]]);
        element->setPartition(partition);
        element->setVisibility(visibility);
        replacement.push_back(element);
      }
      if(!orientElementsAccordingToBoundarySegment(
           boundary[0], boundary[1], replacement) ||
         !preservesConstrainedEdges(replacement)) {
        for(MElement *element : replacement) delete element;
        if(diagnostic) ++diagnostic->commitRejected;
        return false;
      }
      GFaceMeshDiff diff;
      diff.gf = face;
      diff.before = patch;
      diff.before.intVertices.clear();
      diff.after.gf = face;
      diff.after.bdrVertices = patch.bdrVertices;
      diff.after.elements = std::move(replacement);
      FaceRewriteTransaction transaction(topology, diff);
      if(!transaction || !transaction.execute()) {
        if(diagnostic) ++diagnostic->commitRejected;
        return false;
      }
      if(diagnostic) ++diagnostic->accepted;

      applySmoothedReplacementGeometry(best.smoothedVertices, topology);
      if(!best.smoothedVertices.empty())
        ++result.acceptedFinalSmoothingCavities;

      return true;
    }

    struct TriangleTriangleSwapSeed {
      HalfEdgeMesh::Cavity halfEdgeCavity;
      GFaceMeshPatch core;
      std::array<MTriangle *, 2> triangles = {nullptr, nullptr};
      Edge shared = {nullptr, nullptr};
      SpecificationObjective objective;
      double dihedralDegrees = std::numeric_limits<double>::infinity();
    };

    double trianglePairDihedralDegrees(
      MElement *first, MElement *second,
      const std::unordered_map<MVertex *, std::size_t> *index = nullptr,
      const std::vector<Point> *xyz = nullptr)
    {
      if(!first || !second || first->getNumPrimaryVertices() != 3 ||
         second->getNumPrimaryVertices() != 3)
        return std::numeric_limits<double>::infinity();
      auto point = [&](MVertex *vertex) {
        if(index && xyz) {
          const auto found = index->find(vertex);
          if(found != index->end() && found->second < xyz->size())
            return (*xyz)[found->second];
        }
        return Point{vertex->x(), vertex->y(), vertex->z()};
      };
      auto normal = [&](MElement *triangle) {
        const Point a = point(triangle->getVertex(0));
        const Point b = point(triangle->getVertex(1));
        const Point c = point(triangle->getVertex(2));
        const Point ab = {b[0] - a[0], b[1] - a[1], b[2] - a[2]};
        const Point ac = {c[0] - a[0], c[1] - a[1], c[2] - a[2]};
        return Point{ab[1] * ac[2] - ab[2] * ac[1],
                     ab[2] * ac[0] - ab[0] * ac[2],
                     ab[0] * ac[1] - ab[1] * ac[0]};
      };
      const Point a = normal(first);
      const Point b = normal(second);
      const double an = std::sqrt(a[0] * a[0] + a[1] * a[1] +
                                  a[2] * a[2]);
      const double bn = std::sqrt(b[0] * b[0] + b[1] * b[1] +
                                  b[2] * b[2]);
      if(!(an > 0.) || !(bn > 0.))
        return std::numeric_limits<double>::infinity();
      const double cosine = std::clamp(
        (a[0] * b[0] + a[1] * b[1] + a[2] * b[2]) / (an * bn),
        -1., 1.);
      return std::acos(cosine) *
        180. / 3.141592653589793238462643383279502884;
    }

    bool elementContainsPrimaryEdge(MElement *element, const Edge &edge)
    {
      if(!element) return false;
      const std::size_t count = element->getNumPrimaryVertices();
      for(std::size_t i = 0; i < count; ++i)
        if(canonicalEdge(
             element->getVertex(static_cast<int>(i)),
             element->getVertex(static_cast<int>((i + 1) % count))) == edge)
          return true;
      return false;
    }

    bool trianglesAttachToOppositeQuadrangleEdges(
      const TriangleQuadStripReductionSeed &seed)
    {
      if(seed.quadrangleCount != 1) return false;
      MQuadrangle *quadrangle = nullptr;
      for(MElement *element : seed.cavity.patch.elements) {
        MQuadrangle *candidate = dynamic_cast<MQuadrangle *>(element);
        if(!candidate) continue;
        if(quadrangle) return false;
        quadrangle = candidate;
      }
      if(!quadrangle) return false;

      std::array<int, 2> attachedSides = {-1, -1};
      for(std::size_t triangleIndex = 0; triangleIndex < 2;
          ++triangleIndex) {
        MTriangle *triangle = seed.triangles[triangleIndex];
        if(!triangle) return false;
        for(int side = 0; side < 4; ++side) {
          const Edge edge = canonicalEdge(
            quadrangle->getVertex(side), quadrangle->getVertex((side + 1) % 4));
          if(!elementContainsPrimaryEdge(triangle, edge)) continue;
          if(attachedSides[triangleIndex] >= 0) return false;
          attachedSides[triangleIndex] = side;
        }
        if(attachedSides[triangleIndex] < 0) return false;
      }
      return (attachedSides[0] + 2) % 4 == attachedSides[1];
    }

    std::vector<TriangleQuadStripReductionSeed>
    collectOppositeEdgeTriangleQuadStrips(
      GFace *face, const FaceHalfEdgeTopology &topology)
    {
      std::vector<TriangleQuadStripReductionSeed> strips =
        collectTriangleQuadStripReductions(face, topology, 1);
      strips.erase(
        std::remove_if(
          strips.begin(), strips.end(),
          [](const TriangleQuadStripReductionSeed &strip) {
            return !trianglesAttachToOppositeQuadrangleEdges(strip);
          }),
        strips.end());
      return strips;
    }

    std::vector<CavitySeed> collectOppositeEdgeTriangleQuadFans(
      GFace *face, const FaceHalfEdgeTopology &topology)
    {
      std::vector<TriangleQuadStripReductionSeed> strips =
        collectOppositeEdgeTriangleQuadStrips(face, topology);
      std::vector<CavitySeed> fans;
      fans.reserve(strips.size());
      for(TriangleQuadStripReductionSeed &strip : strips) {
        fans.push_back(std::move(strip.cavity));
      }
      return fans;
    }

    struct OppositeEdgeTriangleQuadSwapCandidate {
      bool valid = false;
      MixedConnectivitySignature faces;
      MixedConnectivitySignature connectivity;
      SpecificationObjective objective;
      ValenceObjective valence;
      SizeScore size;
      GeometryDeviation geometry;
      GeometryDeviation referenceGeometry;
      CleanUpDecisionReason decision = CleanUpDecisionReason::Rejected;
      std::vector<Candidate::VertexGeometry> smoothedVertices;
    };

    std::vector<MixedConnectivitySignature>
    oppositeEdgeTriangleQuadSwapPatterns(
      HalfEdgeRewriteSymmetry symmetry)
    {
      // These are the three D6 orbits of planar dissections of an hexagon
      // into exactly one quadrangle and two triangles. Their orbit sizes are
      // respectively 6, 3 and 12, for all 21 labelled configurations.
      const auto &representatives =
        HalfEdgeRewrite::oppositeEdgeTriangleQuadSwapRepresentatives();
      constexpr std::size_t boundaryCount = 6;
      std::map<MixedConnectivitySignature, MixedConnectivitySignature>
        unique;
      for(const MixedConnectivitySignature &representative :
          representatives) {
        for(std::size_t action = 0;
            action < HalfEdgeRewrite::actionCount(
              symmetry, boundaryCount);
            ++action) {
          MixedConnectivitySignature transformed;
          transformed.reserve(representative.size());
          for(const std::vector<std::size_t> &face : representative)
            transformed.push_back(HalfEdgeRewrite::transformFace(
              symmetry, boundaryCount, action, face));
          const MixedConnectivitySignature connectivity =
            HalfEdgeRewrite::canonicalConnectivity(transformed);
          unique.emplace(connectivity, std::move(transformed));
        }
      }
      std::vector<MixedConnectivitySignature> patterns;
      patterns.reserve(unique.size());
      for(auto &entry : unique)
        patterns.push_back(std::move(entry.second));
      return patterns;
    }

    bool tryOppositeEdgeTriangleQuadSwap(
      GFace *face, const TriangleQuadStripReductionSeed &seed,
      FaceHalfEdgeTopology &topology,
      const SmallCavityOptimizerOptions &options,
      SmallCavityOptimizerResult &result, CleanUpDecisionPhase phase,
      HalfEdgeRewriteSymmetry symmetry,
      std::set<MVertex *> &fastCadProtectedVertices)
    {
      const GFaceMeshPatch &patch = seed.cavity.patch;
      if(!face || seed.quadrangleCount != 1 ||
         !trianglesAttachToOppositeQuadrangleEdges(seed) ||
         phase != CleanUpDecisionPhase::Any ||
         !useFastInteractiveCleanUp(options) || !topology.manifold() ||
         patch.bdrVertices.size() != 1 ||
         patch.bdrVertices.front().size() != 6 ||
         patch.elements.size() != 3 || !patch.intVertices.empty() ||
         !patch.embVertices.empty() ||
         touchesBoundaryLayerElementData(face, patch.elements))
        return false;

      const int partition = patch.elements.front()->getPartition();
      const bool visibility = patch.elements.front()->getVisibility();
      for(MElement *element : patch.elements)
        if(!element || element->getPartition() != partition ||
           element->getVisibility() != visibility)
          return false;

      const std::vector<MVertex *> &boundary =
        patch.bdrVertices.front();
      std::unordered_map<MVertex *, std::size_t> boundaryIndex;
      for(std::size_t i = 0; i < boundary.size(); ++i)
        if(!boundary[i] || !boundaryIndex.emplace(boundary[i], i).second)
          return false;

      MixedConnectivitySignature input;
      input.reserve(patch.elements.size());
      for(MElement *element : patch.elements) {
        const std::size_t count = element->getNumPrimaryVertices();
        if(count != 3 && count != 4) return false;
        std::vector<std::size_t> faceVertices;
        faceVertices.reserve(count);
        for(std::size_t i = 0; i < count; ++i) {
          const auto found = boundaryIndex.find(
            element->getVertex(static_cast<int>(i)));
          if(found == boundaryIndex.end()) return false;
          faceVertices.push_back(found->second);
        }
        input.push_back(std::move(faceVertices));
      }
      input = HalfEdgeRewrite::canonicalConnectivity(std::move(input));

      std::set<MEdge, MEdgeLessThan> constrainedEdges;
      auto addConstrainedEdges = [&](const std::vector<GEdge *> &curves) {
        for(GEdge *curve : curves)
          if(curve)
            for(MLine *line : curve->lines)
              if(line)
                constrainedEdges.insert(MEdge(
                  line->getVertex(0), line->getVertex(1)));
      };
      addConstrainedEdges(face->edges());
      addConstrainedEdges(face->getEmbeddedEdges());
      auto preservesConstrainedEdges =
        [&](const std::vector<MElement *> &replacement) {
          std::set<MEdge, MEdgeLessThan> replacementEdges;
          for(MElement *element : replacement) {
            const std::size_t count = element->getNumPrimaryVertices();
            for(std::size_t i = 0; i < count; ++i)
              replacementEdges.insert(MEdge(
                element->getVertex(static_cast<int>(i)),
                element->getVertex(static_cast<int>((i + 1) % count))));
          }
          for(MElement *element : patch.elements) {
            const std::size_t count = element->getNumPrimaryVertices();
            for(std::size_t i = 0; i < count; ++i) {
              const MEdge edge(
                element->getVertex(static_cast<int>(i)),
                element->getVertex(static_cast<int>((i + 1) % count)));
              if(constrainedEdges.find(edge) != constrainedEdges.end() &&
                 replacementEdges.find(edge) == replacementEdges.end())
                return false;
            }
          }
          return true;
        };

      const std::vector<MixedConnectivitySignature> patterns =
        oppositeEdgeTriangleQuadSwapPatterns(symmetry);
      if(patterns.size() != 21) return false;
      CavityEvaluationReference evaluationReference;
      if(!prepareCavityEvaluationReference(
           face, patch.elements, topology, options,
           seed.cavity.halfEdgeCavity, &fastCadProtectedVertices,
           evaluationReference))
        return false;
      OppositeEdgeTriangleQuadSwapCandidate best;
      for(const MixedConnectivitySignature &faces : patterns) {
        const MixedConnectivitySignature connectivity =
          HalfEdgeRewrite::canonicalConnectivity(faces);
        if(connectivity == input) continue;

        std::vector<MElement *> replacement;
        replacement.reserve(faces.size());
        bool patternValid = true;
        for(const std::vector<std::size_t> &candidateFace : faces) {
          for(const std::size_t vertex : candidateFace)
            patternValid = patternValid && vertex < boundary.size();
          if(!patternValid) break;
          if(candidateFace.size() == 3)
            replacement.push_back(new MTriangle(
              boundary[candidateFace[0]], boundary[candidateFace[1]],
              boundary[candidateFace[2]]));
          else if(candidateFace.size() == 4)
            replacement.push_back(new MQuadrangle(
              boundary[candidateFace[0]], boundary[candidateFace[1]],
              boundary[candidateFace[2]], boundary[candidateFace[3]]));
          else {
            patternValid = false;
            break;
          }
          replacement.back()->setPartition(partition);
          replacement.back()->setVisibility(visibility);
        }
        if(!patternValid || replacement.size() != 3 ||
           !orientElementsAccordingToBoundarySegment(
             boundary[0], boundary[1], replacement) ||
           !topology.validReplacement(patch.elements, replacement) ||
           !preservesConstrainedEdges(replacement)) {
          for(MElement *element : replacement) delete element;
          continue;
        }

        ++result.topologyCandidatesOptimized;
        SmoothedCavityEvaluation evaluation;
        if(!prepareSmoothedCavityEvaluation(
             face, patch.elements, replacement, topology, options,
             evaluation, seed.cavity.halfEdgeCavity,
             &fastCadProtectedVertices, nullptr, false, false,
             &evaluationReference)) {
          for(MElement *element : replacement) delete element;
          ++result.rejectedByWinslow;
          continue;
        }

        bool corePassesAbsoluteSpecifications = true;
        Pattern coreQuadrangles;
        for(const std::vector<std::size_t> &candidateFace : faces)
          if(candidateFace.size() == 4)
            coreQuadrangles.push_back(
              {candidateFace[0], candidateFace[1], candidateFace[2],
               candidateFace[3]});
        for(MElement *element : replacement) {
          std::vector<std::size_t> indexed;
          if(!indexedElement(element, evaluation.index, indexed) ||
             (indexed.size() != 3 && indexed.size() != 4)) {
            corePassesAbsoluteSpecifications = false;
            break;
          }
          std::vector<Point> points(indexed.size());
          for(std::size_t i = 0; i < indexed.size(); ++i)
            points[i] = evaluation.xyz[indexed[i]];
          const SurfaceElementKind kind = indexed.size() == 3 ?
            SurfaceElementKind::Triangle :
            SurfaceElementKind::Quadrangle;
          if(!evaluateElementQuality(
               kind, points).passesAbsoluteSpecifications) {
            corePassesAbsoluteSpecifications = false;
            break;
          }
        }
        const SpecificationObjective &referenceObjective =
          evaluation.metrics.referenceObjective;
        const SpecificationObjective &objective =
          evaluation.metrics.candidateObjective;
        if(!corePassesAbsoluteSpecifications ||
           objective.invalidElementCount != 0 ||
           !candidateQuadranglesAreNonConcave(
             evaluation.quadrangles, evaluation.uv, evaluation.xyz) ||
           !noWorseAbsoluteSpecifications(
             objective, referenceObjective,
             options.objectiveRelativeTolerance)) {
          for(MElement *element : replacement) delete element;
          ++result.rejectedByQuality;
          continue;
        }

        const SizeScore &beforeSize = evaluation.metrics.referenceSize;
        const SizeScore &afterSize = evaluation.metrics.candidateSize;
        const std::size_t beforeSizeViolations =
          beforeSize.belowMinimum + beforeSize.aboveMaximum +
          beforeSize.invalid;
        const std::size_t afterSizeViolations =
          afterSize.belowMinimum + afterSize.aboveMaximum +
          afterSize.invalid;

        SizeScore chordSize;
        chordSize.admissible = true;
        double chordError = 0.;
        std::set<std::pair<std::size_t, std::size_t> > chords;
        for(const std::vector<std::size_t> &candidateFace : faces)
          for(std::size_t i = 0; i < candidateFace.size(); ++i) {
            std::size_t a = candidateFace[i];
            std::size_t b = candidateFace[(i + 1) % candidateFace.size()];
            if(a > b) std::swap(a, b);
            const std::pair<std::size_t, std::size_t> edge = {a, b};
            if(!isFixedCavityBoundaryEdge(edge, boundary.size()))
              chords.insert(edge);
          }
        for(const auto &edge : chords) {
          const auto first = evaluation.index.find(boundary[edge.first]);
          const auto second = evaluation.index.find(boundary[edge.second]);
          if(first == evaluation.index.end() ||
             second == evaluation.index.end()) {
            chordSize.admissible = false;
            break;
          }
          const std::size_t a = first->second;
          const std::size_t b = second->second;
          const UV midpointUv = {
            .5 * (evaluation.uv[a][0] + evaluation.uv[b][0]),
            .5 * (evaluation.uv[a][1] + evaluation.uv[b][1])};
          const Point midpointXyz = {
            .5 * (evaluation.xyz[a][0] + evaluation.xyz[b][0]),
            .5 * (evaluation.xyz[a][1] + evaluation.xyz[b][1]),
            .5 * (evaluation.xyz[a][2] + evaluation.xyz[b][2])};
          accumulateSizeEdge(
            chordSize, chordError,
            edgeLengthCriteria(face, midpointUv, midpointXyz, options),
            distance(evaluation.xyz[a], evaluation.xyz[b]), true);
        }
        if(options.enforceSizeMap &&
           (!afterSize.admissible || !chordSize.admissible ||
            afterSizeViolations > beforeSizeViolations ||
            !admissibleSizeChange(beforeSize, afterSize, options))) {
          for(MElement *element : replacement) delete element;
          ++result.rejectedBySize;
          continue;
        }

        const GeometryDeviation &referenceGeometry =
          evaluation.metrics.referenceGeometry;
        const GeometryDeviation &geometry =
          evaluation.metrics.candidateGeometry;
        if(!referenceGeometry.valid || !geometry.valid ||
           !geometryDoesNotRegressBeyondRoundoff(
             geometry, referenceGeometry)) {
          for(MElement *element : replacement) delete element;
          ++result.rejectedByQuality;
          continue;
        }

        const ValenceObjective candidateValence =
          candidatePatchValence(seed.cavity, coreQuadrangles, 0);
        const CleanUpDecisionReason decision = cleanUpDecision(
          objective, referenceObjective, geometry, referenceGeometry,
          objective.absoluteBadElementCount == 0, candidateValence,
          seed.cavity.valence, afterSizeViolations,
          beforeSizeViolations, afterSize.meanSquaredLogRatio,
          beforeSize.meanSquaredLogRatio,
          options.objectiveRelativeTolerance);
        if(!decisionAllowed(decision, phase)) {
          for(MElement *element : replacement) delete element;
          continue;
        }
        // BetterGeometry is an additive, strict progress witness and may
        // deliberately cross a transient valence barrier; the following
        // connectivity cleanup sees and repairs that valence on the same
        // half-edge topology.  On a CAD tie, cleanUpDecision still requires
        // a strict valence improvement, so no quality-only regression is
        // admitted here.

        bool better = !best.valid;
        if(best.valid && decision != best.decision)
          better = static_cast<int>(decision) <
                   static_cast<int>(best.decision);
        else if(best.valid &&
                decision == CleanUpDecisionReason::BetterGeometry)
          better = compareGeometryDeviation(
                     geometry, best.geometry,
                     options.objectiveRelativeTolerance) < 0;
        else if(best.valid)
          better = objectivePriority(objective) <
                   objectivePriority(best.objective);
        if(best.valid && decision == best.decision && !better &&
           compareGeometryDeviation(
             geometry, best.geometry,
             options.objectiveRelativeTolerance) == 0 &&
           objectivePriority(objective) ==
             objectivePriority(best.objective))
          better = connectivity < best.connectivity;
        for(MElement *element : replacement) delete element;
        if(!better) continue;

        best.valid = true;
        best.faces = faces;
        best.connectivity = connectivity;
        best.objective = objective;
        best.valence = candidateValence;
        best.size = afterSize;
        best.geometry = geometry;
        best.referenceGeometry = referenceGeometry;
        best.decision = decision;
        best.smoothedVertices = std::move(evaluation.movedVertices);
      }
      if(!best.valid) return false;

      std::vector<MElement *> replacement;
      replacement.reserve(best.faces.size());
      for(const std::vector<std::size_t> &candidateFace : best.faces) {
        MElement *element = candidateFace.size() == 3 ?
          static_cast<MElement *>(new MTriangle(
            boundary[candidateFace[0]], boundary[candidateFace[1]],
            boundary[candidateFace[2]])) :
          static_cast<MElement *>(new MQuadrangle(
            boundary[candidateFace[0]], boundary[candidateFace[1]],
            boundary[candidateFace[2]], boundary[candidateFace[3]]));
        element->setPartition(partition);
        element->setVisibility(visibility);
        replacement.push_back(element);
      }
      if(!orientElementsAccordingToBoundarySegment(
           boundary[0], boundary[1], replacement) ||
         !preservesConstrainedEdges(replacement)) {
        for(MElement *element : replacement) delete element;
        return false;
      }
      GFaceMeshDiff diff;
      diff.gf = face;
      diff.before = patch;
      diff.before.intVertices.clear();
      diff.after.gf = face;
      diff.after.bdrVertices = patch.bdrVertices;
      diff.after.elements = std::move(replacement);
      FaceRewriteTransaction transaction(topology, diff);
      if(!transaction || !transaction.execute()) return false;
      applySmoothedReplacementGeometry(best.smoothedVertices, topology);
      if(!best.smoothedVertices.empty())
        ++result.acceptedFinalSmoothingCavities;
      if(options.verbose)
        Msg::Info("QuadOptimizer CleanUp: accepted opposite-edge T-Q-T "
                  "mixed swap B=6 CAD integral=%g->%g",
                  best.referenceGeometry.squaredDistanceIntegral,
                  best.geometry.squaredDistanceIntegral);
      return true;
    }

    // Additive part of the face-wide T/T fold potential whose value can change
    // during one local transaction. Besides the removed/inserted diagonal, the
    // support contains the four cavity-boundary edges: replacing either inner
    // triangle changes its normal and therefore its dihedral with an external
    // triangle across any of those edges.
    double affectedTriangleTriangleDihedralPenalty(
      const FaceHalfEdgeTopology &topology, const std::set<Edge> &support,
      const std::set<MElement *> &removed,
      const std::vector<MElement *> &inserted,
      const std::unordered_map<MVertex *, std::size_t> *index = nullptr,
      const std::vector<Point> *xyz = nullptr)
    {
      double penalty = 0.;
      for(const Edge &edge : support) {
        std::vector<MElement *> incident = topology.incidentElements(edge);
        incident.erase(
          std::remove_if(incident.begin(), incident.end(),
                         [&](MElement *element) {
                           return removed.find(element) != removed.end();
                         }),
          incident.end());
        for(MElement *element : inserted)
          if(elementContainsPrimaryEdge(element, edge))
            incident.push_back(element);
        if(incident.size() != 2) continue;
        if(incident[0]->getNumPrimaryVertices() != 3 ||
           incident[1]->getNumPrimaryVertices() != 3)
          continue;
        const double dihedral = trianglePairDihedralDegrees(
          incident[0], incident[1], index, xyz);
        if(!std::isfinite(dihedral))
          return std::numeric_limits<double>::infinity();
        penalty += std::pow(dihedral / 15., 2);
      }
      return penalty;
    }

    std::vector<TriangleTriangleSwapSeed> collectTriangleTriangleSwaps(
      GFace *face, const FaceHalfEdgeTopology &topology)
    {
      if(!face || !topology.manifold()) return {};
      std::vector<TriangleTriangleSwapSeed> seeds;
      for(const auto &entry : topology.edges()) {
        if(entry.second.size() != 2) continue;
        MTriangle *first = dynamic_cast<MTriangle *>(entry.second[0]);
        MTriangle *second = dynamic_cast<MTriangle *>(entry.second[1]);
        if(!first || !second) continue;
        if(canonicalElementGeometryLess(second, first))
          std::swap(first, second);
        TriangleTriangleSwapSeed seed;
        seed.triangles = {first, second};
        seed.shared = entry.first;
        if(!topology.cavityAroundEdge(entry.first, seed.halfEdgeCavity))
          continue;
        const std::vector<MElement *> elements =
          topology.elements(seed.halfEdgeCavity);
        if(elements.size() != 2 ||
           !canonicalPatchFromElements(face, elements, seed.core) ||
           seed.core.bdrVertices.size() != 1 ||
           seed.core.bdrVertices.front().size() != 4 ||
           !seed.core.intVertices.empty() || !seed.core.embVertices.empty())
          continue;
        seed.objective = specificationObjective(elements);
        seed.dihedralDegrees = trianglePairDihedralDegrees(first, second);
        seeds.push_back(std::move(seed));
      }
      std::sort(seeds.begin(), seeds.end(),
                [](const TriangleTriangleSwapSeed &a,
                   const TriangleTriangleSwapSeed &b) {
                  if(a.dihedralDegrees != b.dihedralDegrees)
                    return a.dihedralDegrees > b.dihedralDegrees;
                  const double ap = objectivePriority(a.objective);
                  const double bp = objectivePriority(b.objective);
                  if(ap != bp) return ap > bp;
                  return canonicalEdgeGeometryLess(a.shared, b.shared);
                });
      return seeds;
    }

    bool tryTriangleTriangleSwap(
      GFace *face, const TriangleTriangleSwapSeed &seed,
      FaceHalfEdgeTopology &topology,
      const SmallCavityOptimizerOptions &options,
      SmallCavityOptimizerResult &result,
      std::set<MVertex *> &fastCadProtectedVertices)
    {
      if(!face || !seed.triangles[0] || !seed.triangles[1] ||
         seed.core.bdrVertices.size() != 1 ||
         seed.core.bdrVertices.front().size() != 4 ||
         !seed.core.intVertices.empty() || !topology.manifold())
        return false;
      if(seed.triangles[0]->getPartition() !=
           seed.triangles[1]->getPartition() ||
         seed.triangles[0]->getVisibility() !=
           seed.triangles[1]->getVisibility() ||
         touchesBoundaryLayerElementData(face, seed.core.elements))
        return false;

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
      if(constrainedEdges.find(MEdge(seed.shared.first,
                                     seed.shared.second)) !=
         constrainedEdges.end())
        return false;

      const std::vector<MVertex *> &boundary =
        seed.core.bdrVertices.front();
      const Edge diagonal02 = canonicalEdge(boundary[0], boundary[2]);
      const Edge diagonal13 = canonicalEdge(boundary[1], boundary[3]);
      std::array<std::array<std::size_t, 3>, 2> triangles;
      Edge newDiagonal = {nullptr, nullptr};
      if(seed.shared == diagonal02) {
        triangles = {{{1, 2, 3}, {1, 3, 0}}};
        newDiagonal = diagonal13;
      }
      else if(seed.shared == diagonal13) {
        triangles = {{{0, 1, 2}, {0, 2, 3}}};
        newDiagonal = diagonal02;
      }
      else {
        ++result.rejectedByQuality;
        return false;
      }

      std::vector<std::unique_ptr<MTriangle> > temporary;
      temporary.emplace_back(new MTriangle(
        boundary[triangles[0][0]], boundary[triangles[0][1]],
        boundary[triangles[0][2]]));
      temporary.emplace_back(new MTriangle(
        boundary[triangles[1][0]], boundary[triangles[1][1]],
        boundary[triangles[1][2]]));
      std::vector<MElement *> replacement = {
        temporary[0].get(), temporary[1].get()};
      for(MElement *element : replacement) {
        element->setPartition(seed.triangles[0]->getPartition());
        element->setVisibility(seed.triangles[0]->getVisibility());
      }
      if(!orientElementsAccordingToBoundarySegment(
           boundary[0], boundary[1], replacement) ||
         !topology.validReplacement(seed.core.elements, replacement)) {
        ++result.rejectedByQuality;
        return false;
      }

      std::vector<UV> uv;
      if(!currentParametrization(seed.core, uv) || uv.size() != 4) {
        ++result.rejectedByQuality;
        return false;
      }
      std::vector<Point> xyz(4);
      std::unordered_map<MVertex *, std::size_t> localIndex;
      for(std::size_t i = 0; i < boundary.size(); ++i) {
        xyz[i] = {boundary[i]->x(), boundary[i]->y(), boundary[i]->z()};
        if(!localIndex.emplace(boundary[i], i).second) {
          ++result.rejectedByQuality;
          return false;
        }
      }
      std::vector<std::array<std::size_t, 3> > candidateTriangles(2);
      for(std::size_t element = 0; element < replacement.size(); ++element)
        for(std::size_t vertex = 0; vertex < 3; ++vertex) {
          const auto found = localIndex.find(
            replacement[element]->getVertex(static_cast<int>(vertex)));
          if(found == localIndex.end()) {
            ++result.rejectedByQuality;
            return false;
          }
          candidateTriangles[element][vertex] = found->second;
        }

      double twiceBoundaryArea = 0.;
      for(std::size_t i = 0; i < 4; ++i) {
        const UV &a = uv[i];
        const UV &b = uv[(i + 1) % 4];
        twiceBoundaryArea += a[0] * b[1] - a[1] * b[0];
      }
      if(!std::isfinite(twiceBoundaryArea) ||
         std::abs(twiceBoundaryArea) <= 1.e-14) {
        ++result.rejectedByQuality;
        return false;
      }
      const double orientation = twiceBoundaryArea > 0. ? 1. : -1.;
      for(const auto &triangle : candidateTriangles) {
        const UV &a = uv[triangle[0]];
        const UV &b = uv[triangle[1]];
        const UV &c = uv[triangle[2]];
        const double twiceArea =
          (b[0] - a[0]) * (c[1] - a[1]) -
          (b[1] - a[1]) * (c[0] - a[0]);
        if(!std::isfinite(twiceArea) ||
           orientation * twiceArea <= 1.e-14) {
          ++result.rejectedByQuality;
          return false;
        }
      }

      // The four-vertex core has no interior unknown. Evaluate the new
      // diagonal only after a transactional mixed Winslow solve on the
      // complete stars of its movable vertices; the live mesh is left
      // untouched until the half-edge replacement has committed.
      SmoothedCavityEvaluation evaluation;
      if(!prepareSmoothedCavityEvaluation(
           face, seed.core.elements, replacement, topology, options,
           evaluation, seed.halfEdgeCavity,
           &fastCadProtectedVertices)) {
        if(options.verbose > 1)
          Msg::Info("TT reject edge=(%lu,%lu) new=(%lu,%lu): Winslow",
                    seed.shared.first->getNum(), seed.shared.second->getNum(),
                    newDiagonal.first->getNum(), newDiagonal.second->getNum());
        ++result.rejectedByWinslow;
        return false;
      }
      for(std::size_t element = 0; element < replacement.size(); ++element)
        for(std::size_t vertex = 0; vertex < 3; ++vertex) {
          const auto found = evaluation.index.find(
            replacement[element]->getVertex(static_cast<int>(vertex)));
          if(found == evaluation.index.end()) {
            ++result.rejectedByQuality;
            return false;
          }
          candidateTriangles[element][vertex] = found->second;
        }

      const SpecificationObjective &referenceObjective =
        evaluation.metrics.referenceObjective;
      const SpecificationObjective &candidateObjective =
        evaluation.metrics.candidateObjective;
      const SpecificationObjective candidateCoreObjective =
        candidateMixedObjective(
          candidateTriangles, Pattern(), evaluation.xyz);
      const std::size_t referenceInvalid =
        referenceObjective.invalidElementCount;
      const std::size_t candidateInvalid =
        candidateObjective.invalidElementCount;
      if(candidateInvalid > referenceInvalid ||
         !noWorseAbsoluteSpecifications(
           candidateObjective, referenceObjective,
           options.objectiveRelativeTolerance)) {
        if(options.verbose > 1)
          Msg::Info("TT reject edge=(%lu,%lu) new=(%lu,%lu): hard quality",
                    seed.shared.first->getNum(), seed.shared.second->getNum(),
                    newDiagonal.first->getNum(), newDiagonal.second->getNum());
        ++result.rejectedByQuality;
        return false;
      }
      const double candidateDihedral = trianglePairDihedralDegrees(
        replacement[0], replacement[1], &evaluation.index,
        &evaluation.xyz);
      if(!std::isfinite(candidateDihedral)) {
        ++result.rejectedByQuality;
        return false;
      }

      std::set<Edge> affectedDihedralEdges;
      auto addAffectedEdges = [&](const std::vector<MElement *> &elements) {
        for(MElement *element : elements) {
          if(!element) continue;
          const std::size_t count = element->getNumPrimaryVertices();
          for(std::size_t i = 0; i < count; ++i)
            affectedDihedralEdges.insert(canonicalEdge(
              element->getVertex(static_cast<int>(i)),
              element->getVertex(static_cast<int>((i + 1) % count))));
        }
      };
      addAffectedEdges(evaluation.beforePatch.elements);
      addAffectedEdges(evaluation.afterPatch.elements);
      const std::set<MElement *> noRemovedElements;
      const std::vector<MElement *> noInsertedElements;
      const double referenceDihedralPenalty =
        affectedTriangleTriangleDihedralPenalty(
          topology, affectedDihedralEdges, noRemovedElements,
          noInsertedElements);
      const std::set<MElement *> removedElements(
        seed.core.elements.begin(), seed.core.elements.end());
      const double candidateDihedralPenalty =
        affectedTriangleTriangleDihedralPenalty(
          topology, affectedDihedralEdges, removedElements, replacement,
          &evaluation.index, &evaluation.xyz);

      const SizeScore &beforeSize = evaluation.metrics.referenceSize;
      const SizeScore &afterSize = evaluation.metrics.candidateSize;
      const std::size_t beforeSizeViolations =
        beforeSize.belowMinimum + beforeSize.aboveMaximum +
        beforeSize.invalid;
      const std::size_t afterSizeViolations =
        afterSize.belowMinimum + afterSize.aboveMaximum + afterSize.invalid;
      const auto newAFound = evaluation.index.find(newDiagonal.first);
      const auto newBFound = evaluation.index.find(newDiagonal.second);
      if(newAFound == evaluation.index.end() ||
         newBFound == evaluation.index.end()) {
        ++result.rejectedByQuality;
        return false;
      }
      const std::size_t newA = newAFound->second;
      const std::size_t newB = newBFound->second;
      const UV newMidpointUv = {
        .5 * (evaluation.uv[newA][0] + evaluation.uv[newB][0]),
        .5 * (evaluation.uv[newA][1] + evaluation.uv[newB][1])};
      const Point newMidpointXyz = {
        .5 * (evaluation.xyz[newA][0] + evaluation.xyz[newB][0]),
        .5 * (evaluation.xyz[newA][1] + evaluation.xyz[newB][1]),
        .5 * (evaluation.xyz[newA][2] + evaluation.xyz[newB][2])};
      SizeScore newDiagonalSize;
      newDiagonalSize.admissible = true;
      double newDiagonalSizeError = 0.;
      accumulateSizeEdge(
        newDiagonalSize, newDiagonalSizeError,
        edgeLengthCriteria(face, newMidpointUv, newMidpointXyz, options),
        distance(evaluation.xyz[newA], evaluation.xyz[newB]), true);
      if(options.enforceSizeMap &&
         (!newDiagonalSize.admissible || !afterSize.admissible ||
          afterSizeViolations > beforeSizeViolations ||
          !admissibleSizeChange(beforeSize, afterSize, options))) {
        if(options.verbose > 1)
          Msg::Info("TT reject edge=(%lu,%lu) new=(%lu,%lu): size",
                    seed.shared.first->getNum(), seed.shared.second->getNum(),
                    newDiagonal.first->getNum(), newDiagonal.second->getNum());
        ++result.rejectedBySize;
        return false;
      }

      const std::size_t oldA = localIndex[seed.shared.first];
      const std::size_t oldB = localIndex[seed.shared.second];
      double oldCadDistance = 0., newCadDistance = 0.;
      if(!edgeMidpointCadDistance(
         face, uv[oldA], uv[oldB], xyz[oldA], xyz[oldB],
           oldCadDistance) ||
         !edgeMidpointCadDistance(
           face, evaluation.uv[newA], evaluation.uv[newB],
           evaluation.xyz[newA], evaluation.xyz[newB],
           newCadDistance)) {
        ++result.rejectedByQuality;
        return false;
      }
      const UV oldMidpointUv = {
        .5 * (uv[oldA][0] + uv[oldB][0]),
        .5 * (uv[oldA][1] + uv[oldB][1])};
      const Point oldMidpointXyz = {
        .5 * (xyz[oldA][0] + xyz[oldB][0]),
        .5 * (xyz[oldA][1] + xyz[oldB][1]),
        .5 * (xyz[oldA][2] + xyz[oldB][2])};
      const EdgeLengthCriteria oldCriteria = edgeLengthCriteria(
        face, oldMidpointUv, oldMidpointXyz, options);
      const EdgeLengthCriteria newCriteria = edgeLengthCriteria(
        face, newMidpointUv, newMidpointXyz, options);
      if(!validEdgeLengthCriteria(oldCriteria) ||
         !validEdgeLengthCriteria(newCriteria)) {
        ++result.rejectedByQuality;
        return false;
      }
      const double oldCadPenalty =
        std::pow(oldCadDistance / oldCriteria.target, 2);
      const double newCadPenalty =
        std::pow(newCadDistance / oldCriteria.target, 2);
      const double cadTolerance = 1.e-12 * std::max(
        {1., std::abs(oldCadPenalty), std::abs(newCadPenalty)});
      if(!std::isfinite(oldCadPenalty) || !std::isfinite(newCadPenalty) ||
         newCadPenalty > oldCadPenalty + cadTolerance) {
        ++result.rejectedByQuality;
        return false;
      }

      const GeometryDeviation &referenceGeometry =
        evaluation.metrics.referenceGeometry;
      const GeometryDeviation &candidateGeometry =
        evaluation.metrics.candidateGeometry;
      if(!referenceGeometry.valid || !candidateGeometry.valid ||
         !geometryDoesNotRegressBeyondRoundoff(
           candidateGeometry, referenceGeometry)) {
        if(options.verbose > 1)
          Msg::Info("TT reject edge=(%lu,%lu) new=(%lu,%lu): geometry %g -> %g",
                    seed.shared.first->getNum(), seed.shared.second->getNum(),
                    newDiagonal.first->getNum(), newDiagonal.second->getNum(),
                    referenceGeometry.squaredDistanceIntegral,
                    candidateGeometry.squaredDistanceIntegral);
        ++result.rejectedByQuality;
        return false;
      }

      // A smoothed TT transaction can move every edge incident on a core
      // vertex. Score the unique primary edges of the complete support, not
      // only the exchanged diagonal. The squared sum is an additive
      // face-wide progress guard; the maximum is a no-regression guard for
      // the worst chord.
      struct MidpointSupportScore {
        bool valid = false;
        std::size_t edgeCount = 0;
        double maximumDistance = std::numeric_limits<double>::infinity();
        double squaredDistanceSum =
          std::numeric_limits<double>::infinity();
      };
      auto midpointSupportScore = [&]
        (const std::vector<MElement *> &elements,
         const std::unordered_map<MVertex *, std::size_t> *index,
         const std::vector<UV> *parameters,
         const std::vector<Point> *points) {
        MidpointSupportScore score;
        std::set<Edge> edges;
        for(MElement *element : elements) {
          if(!element) return score;
          const std::size_t count = element->getNumPrimaryVertices();
          for(std::size_t i = 0; i < count; ++i)
            edges.insert(canonicalEdge(
              element->getVertex(static_cast<int>(i)),
              element->getVertex(static_cast<int>((i + 1) % count))));
        }
        if(edges.empty()) return score;
        score.maximumDistance = 0.;
        score.squaredDistanceSum = 0.;
        for(const Edge &edge : edges) {
          UV aUv, bUv;
          Point aXyz, bXyz;
          if(index && parameters && points) {
            const auto a = index->find(edge.first);
            const auto b = index->find(edge.second);
            if(a == index->end() || b == index->end() ||
               a->second >= parameters->size() ||
               b->second >= parameters->size() ||
               a->second >= points->size() || b->second >= points->size())
              return score;
            aUv = (*parameters)[a->second];
            bUv = (*parameters)[b->second];
            aXyz = (*points)[a->second];
            bXyz = (*points)[b->second];
          }
          else {
            SPoint2 aParameter, bParameter;
            if(!persistentFaceParameter(face, edge.first, aParameter) ||
               !reparamMeshVertexOnFaceWithRef(
                 face, edge.second, aParameter, bParameter))
              return score;
            aUv = {aParameter.x(), aParameter.y()};
            bUv = {bParameter.x(), bParameter.y()};
            aXyz = {edge.first->x(), edge.first->y(), edge.first->z()};
            bXyz = {edge.second->x(), edge.second->y(), edge.second->z()};
          }
          double deviation = 0.;
          if(!edgeMidpointCadDistance(
               face, aUv, bUv, aXyz, bXyz, deviation))
            return score;
          score.maximumDistance =
            std::max(score.maximumDistance, deviation);
          score.squaredDistanceSum += deviation * deviation;
        }
        score.edgeCount = edges.size();
        score.valid = std::isfinite(score.maximumDistance) &&
          std::isfinite(score.squaredDistanceSum);
        return score;
      };
      const MidpointSupportScore referenceMidpoints = midpointSupportScore(
        evaluation.beforePatch.elements, nullptr, nullptr, nullptr);
      const MidpointSupportScore candidateMidpoints = midpointSupportScore(
        evaluation.afterPatch.elements, &evaluation.index, &evaluation.uv,
        &evaluation.xyz);
      if(!referenceMidpoints.valid || !candidateMidpoints.valid ||
         referenceMidpoints.edgeCount != candidateMidpoints.edgeCount) {
        ++result.rejectedByQuality;
        return false;
      }
      const double target = options.targetSize > 0. ?
        options.targetSize :
        std::sqrt(std::max(
          referenceGeometry.sampledArea /
            static_cast<double>(std::max<std::size_t>(
              1, referenceGeometry.elementCount)),
          std::numeric_limits<double>::min()));
      const double midpointSumScale = std::max(
        {std::abs(referenceMidpoints.squaredDistanceSum),
         std::abs(candidateMidpoints.squaredDistanceSum),
         std::numeric_limits<double>::min()});
      const double midpointSumTolerance = std::max(
        64. * std::numeric_limits<double>::epsilon() * midpointSumScale,
        1.e-20 * target * target *
          static_cast<double>(referenceMidpoints.edgeCount));
      const double midpointMaximumTolerance = std::max(
        64. * std::numeric_limits<double>::epsilon() * std::max(
          {std::abs(referenceMidpoints.maximumDistance),
           std::abs(candidateMidpoints.maximumDistance),
           std::numeric_limits<double>::min()}),
        1.e-10 * target);
      if(candidateMidpoints.squaredDistanceSum >
           referenceMidpoints.squaredDistanceSum + midpointSumTolerance ||
         candidateMidpoints.maximumDistance >
           referenceMidpoints.maximumDistance +
             midpointMaximumTolerance) {
        if(options.verbose > 1)
          Msg::Info("TT reject edge=(%lu,%lu) new=(%lu,%lu): support midpoint sum=%g->%g max=%g->%g",
                    seed.shared.first->getNum(), seed.shared.second->getNum(),
                    newDiagonal.first->getNum(), newDiagonal.second->getNum(),
                    referenceMidpoints.squaredDistanceSum,
                    candidateMidpoints.squaredDistanceSum,
                    referenceMidpoints.maximumDistance,
                    candidateMidpoints.maximumDistance);
        ++result.rejectedByQuality;
        return false;
      }
      const bool strictMidpointSupportImprovement =
        candidateMidpoints.squaredDistanceSum + midpointSumTolerance <
          referenceMidpoints.squaredDistanceSum;

      const EdgeMidpointCadSwapAssessment cadSwap =
        assessEdgeMidpointCadSwap(
          oldCadDistance, oldCriteria, newCadDistance, newCriteria,
          options);
      // A large geometric chord repair is an explicit cleanup objective. It
      // may override soft shape/dihedral tradeoffs, but never topology,
      // orientation, size or the absolute element specifications.
      const bool geometryDriven = cadSwap.strongImprovement &&
        candidateCoreObjective.invalidElementCount == 0 &&
        candidateCoreObjective.absoluteBadElementCount == 0 &&
        strictMidpointSupportImprovement;
      // Outside the explicit geometric branch, retain the monotone
      // specification gate: do not exchange one kind of shape defect for
      // another.
      if(!geometryDriven && improvesSpecificationObjective(
           referenceObjective, candidateObjective,
           options.objectiveRelativeTolerance)) {
        ++result.rejectedByQuality;
        return false;
      }

      const double geometryNormalization = std::max(
        std::max(referenceGeometry.sampledArea,
                 candidateGeometry.sampledArea) * target * target,
        std::numeric_limits<double>::min());
      const double normalizedCadChange =
        (candidateGeometry.squaredDistanceIntegral -
         referenceGeometry.squaredDistanceIntegral) /
        geometryNormalization;
      if(!std::isfinite(normalizedCadChange)) {
        ++result.rejectedByQuality;
        return false;
      }

      ValenceObjective unchangedValence;
      FastGlobalQuality referenceQuality = fastGlobalQuality(
        referenceObjective, unchangedValence, referenceInvalid,
        beforeSizeViolations, beforeSize.meanSquaredLogRatio,
        beforeSize.edgeCount, 0.);
      FastGlobalQuality candidateQuality = fastGlobalQuality(
        candidateObjective, unchangedValence, candidateInvalid,
        afterSizeViolations, afterSize.meanSquaredLogRatio,
        afterSize.edgeCount, normalizedCadChange);
      // Use the complete additive part of the face-wide T/T fold potential
      // changed by this transaction. This includes external triangle neighbors
      // across the four cavity edges, whose dihedrals change with the normals
      // of the two replaced triangles. A reverse or overlapping flip therefore
      // sees the opposite delta of the same state function.
      referenceQuality.compromise += referenceDihedralPenalty;
      candidateQuality.compromise += candidateDihedralPenalty;
      if(!geometryDriven &&
         !improvesFastGlobalQuality(candidateQuality, referenceQuality)) {
        ++result.rejectedByQuality;
        return false;
      }

      std::vector<MElement *> committed;
      committed.reserve(2);
      for(std::unique_ptr<MTriangle> &triangle : temporary)
        committed.push_back(triangle.release());
      GFaceMeshDiff diff;
      diff.gf = face;
      diff.before = seed.core;
      diff.before.intVertices.clear();
      diff.after.gf = face;
      diff.after.bdrVertices = seed.core.bdrVertices;
      diff.after.elements = std::move(committed);
      FaceRewriteTransaction transaction(topology, diff);
      if(!transaction || !transaction.execute()) return false;
      applySmoothedReplacementGeometry(evaluation, topology);
      if(!evaluation.movedVertices.empty())
        ++result.acceptedFinalSmoothingCavities;
      if(geometryDriven)
        ++result.acceptedGeometryDrivenTriangleTriangleSwaps;
      if(options.verbose)
        Msg::Info("QuadOptimizer CleanUp: accepted T+T diagonal swap "
                  "B=4 reason=%s midpoint/h=%g->%g dihedral=%g->%g "
                  "affectedPenalty=%g->%g",
                  geometryDriven ? "geometry" : "cleanup",
                  cadSwap.referenceRatio, cadSwap.candidateRatio,
                  seed.dihedralDegrees, candidateDihedral,
                  referenceDihedralPenalty, candidateDihedralPenalty);
      return true;
    }

    struct MixedTriangleQuadSwapSeed {
      HalfEdgeMesh::Cavity halfEdgeCavity;
      GFaceMeshPatch core;
      MTriangle *triangle = nullptr;
      MQuadrangle *quadrangle = nullptr;
      SpecificationObjective objective;
      double edgeMidpointCadRatio =
        std::numeric_limits<double>::infinity();
      bool edgeMidpointCadCritical = false;
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
      EdgeMidpointCadSwapAssessment cadSwap;
      bool geometryDriven = false;
      CleanUpDecisionReason decisionReason =
        CleanUpDecisionReason::Rejected;
    };

    std::vector<MixedTriangleQuadSwapSeed> collectMixedTriangleQuadSwaps(
      GFace *face, const FaceHalfEdgeTopology &topology,
      const SmallCavityOptimizerOptions &options)
    {
      if(!face || !topology.manifold()) return {};
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
        if(!topology.cavityAroundEdge(entry.first, seed.halfEdgeCavity))
          continue;
        const std::vector<MElement *> coreElements =
          topology.elements(seed.halfEdgeCavity);
        if(coreElements.size() != 2 ||
           !canonicalPatchFromElements(face, coreElements, seed.core) ||
           seed.core.bdrVertices.size() != 1 ||
           seed.core.bdrVertices.front().size() != 5 ||
           !seed.core.intVertices.empty() ||
           !seed.core.embVertices.empty())
          continue;
        seed.objective = specificationObjective(seed.core.elements);
        SPoint2 firstUv, secondUv;
        if(persistentFaceParameter(face, entry.first.first, firstUv) &&
           reparamMeshVertexOnFaceWithRef(
             face, entry.first.second, firstUv, secondUv)) {
          const UV firstParameter = {firstUv.x(), firstUv.y()};
          const UV secondParameter = {secondUv.x(), secondUv.y()};
          const Point firstPoint = {
            entry.first.first->x(), entry.first.first->y(),
            entry.first.first->z()};
          const Point secondPoint = {
            entry.first.second->x(), entry.first.second->y(),
            entry.first.second->z()};
          double distanceToCad = 0.;
          if(edgeMidpointCadDistance(
               face, firstParameter, secondParameter,
               firstPoint, secondPoint, distanceToCad)) {
            const UV midpointUv = {
              .5 * (firstParameter[0] + secondParameter[0]),
              .5 * (firstParameter[1] + secondParameter[1])};
            const Point midpointXyz = {
              .5 * (firstPoint[0] + secondPoint[0]),
              .5 * (firstPoint[1] + secondPoint[1]),
              .5 * (firstPoint[2] + secondPoint[2])};
            const EdgeLengthCriteria criteria = edgeLengthCriteria(
              face, midpointUv, midpointXyz, options);
            if(validEdgeLengthCriteria(criteria)) {
              seed.edgeMidpointCadRatio =
                distanceToCad / criteria.target;
              const double scale = std::max(
                {1., std::abs(seed.edgeMidpointCadRatio),
                 std::abs(options.edgeMidpointCadSwapTriggerRatio)});
              const double tolerance =
                64. * std::numeric_limits<double>::epsilon() * scale;
              seed.edgeMidpointCadCritical =
                seed.edgeMidpointCadRatio >
                  options.edgeMidpointCadSwapTriggerRatio + tolerance;
            }
          }
        }
        seeds.push_back(std::move(seed));
      }
      std::sort(seeds.begin(), seeds.end(),
                [](const MixedTriangleQuadSwapSeed &a,
                   const MixedTriangleQuadSwapSeed &b) {
                  if(a.edgeMidpointCadCritical !=
                     b.edgeMidpointCadCritical)
                    return a.edgeMidpointCadCritical;
                  if(a.edgeMidpointCadCritical &&
                     a.edgeMidpointCadRatio != b.edgeMidpointCadRatio)
                    return a.edgeMidpointCadRatio >
                           b.edgeMidpointCadRatio;
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

    // Transactional pentagon T-Q swap. Evaluate each diagonal only after mixed
    // Winslow on the complete affected one-ring, and compare that final state
    // against exactly the same support with the original connectivity.
    bool trySmoothedMixedTriangleQuadSwap(
      GFace *face, const MixedTriangleQuadSwapSeed &seed,
      FaceHalfEdgeTopology &topology,
      const SmallCavityOptimizerOptions &options,
      SmallCavityOptimizerResult &result, CleanUpDecisionPhase phase,
      std::set<MVertex *> &fastCadProtectedVertices)
    {
      if(!face || !seed.triangle || !seed.quadrangle ||
         seed.core.bdrVertices.size() != 1 ||
         seed.core.bdrVertices.front().size() != 5 ||
         !seed.core.intVertices.empty() ||
         phase != CleanUpDecisionPhase::Any ||
         !useFastInteractiveCleanUp(options) || !topology.manifold())
        return false;
      if(touchesBoundaryLayerElementData(face, seed.core.elements) ||
         seed.triangle->getPartition() !=
           seed.quadrangle->getPartition() ||
         seed.triangle->getVisibility() !=
           seed.quadrangle->getVisibility())
        return false;

      const std::vector<MVertex *> &pentagon =
        seed.core.bdrVertices.front();
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

      // Never remove a CAD boundary or embedded-curve edge, irrespective of
      // the geometric score of an alternative pentagon diagonal.
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
      if(constrainedEdges.find(MEdge(oldDiagonalVertices[0],
                                     oldDiagonalVertices[1])) !=
         constrainedEdges.end())
        return false;

      SPoint2 oldFirstUv, oldSecondUv;
      if(!persistentFaceParameter(
           face, oldDiagonalVertices[0], oldFirstUv) ||
         !reparamMeshVertexOnFaceWithRef(
           face, oldDiagonalVertices[1], oldFirstUv, oldSecondUv))
        return false;
      const UV oldFirstParameter = {oldFirstUv.x(), oldFirstUv.y()};
      const UV oldSecondParameter = {oldSecondUv.x(), oldSecondUv.y()};
      const Point oldFirstPoint = {
        oldDiagonalVertices[0]->x(), oldDiagonalVertices[0]->y(),
        oldDiagonalVertices[0]->z()};
      const Point oldSecondPoint = {
        oldDiagonalVertices[1]->x(), oldDiagonalVertices[1]->y(),
        oldDiagonalVertices[1]->z()};
      double oldCadDistance = 0.;
      if(!edgeMidpointCadDistance(
           face, oldFirstParameter, oldSecondParameter,
           oldFirstPoint, oldSecondPoint, oldCadDistance))
        return false;
      const UV oldMidpointUv = {
        .5 * (oldFirstParameter[0] + oldSecondParameter[0]),
        .5 * (oldFirstParameter[1] + oldSecondParameter[1])};
      const Point oldMidpointXyz = {
        .5 * (oldFirstPoint[0] + oldSecondPoint[0]),
        .5 * (oldFirstPoint[1] + oldSecondPoint[1]),
        .5 * (oldFirstPoint[2] + oldSecondPoint[2])};
      const EdgeLengthCriteria oldCadCriteria = edgeLengthCriteria(
        face, oldMidpointUv, oldMidpointXyz, options);

      const std::set<MElement *> removedElements(
        seed.core.elements.begin(), seed.core.elements.end());
      auto hasVertex = [](MElement *element, MVertex *vertex) {
        if(!element || !vertex) return false;
        const std::size_t count = element->getNumPrimaryVertices();
        for(std::size_t i = 0; i < count; ++i)
          if(element->getVertex(static_cast<int>(i)) == vertex) return true;
        return false;
      };
      auto mixedValence =
        [&](const std::vector<MElement *> *replacement) {
        ValenceObjective valence;
        for(MVertex *vertex : pentagon) {
          if(!replacement) {
            addValence(valence, topology.quadDegree(vertex),
                       idealQuadDegree(face, vertex, topology),
                       vertex->onWhat() == face);
            continue;
          }
          std::vector<MElement *> incident =
            topology.incidentElements(vertex);
          incident.erase(
            std::remove_if(incident.begin(), incident.end(),
                           [&](MElement *element) {
                             return removedElements.find(element) !=
                                    removedElements.end();
                           }),
            incident.end());
          for(MElement *element : *replacement)
            if(hasVertex(element, vertex)) incident.push_back(element);
          const std::size_t degree = static_cast<std::size_t>(std::count_if(
            incident.begin(), incident.end(), [](MElement *element) {
              return element && element->getNumPrimaryVertices() == 4;
            }));
          addValence(valence, degree,
                     idealQuadDegree(face, vertex, incident),
                     vertex->onWhat() == face);
        }
        return valence;
      };
      const ValenceObjective referenceValence = mixedValence(nullptr);

      CavityEvaluationReference evaluationReference;
      if(!prepareCavityEvaluationReference(
           face, seed.core.elements, topology, options,
           seed.halfEdgeCavity, &fastCadProtectedVertices,
           evaluationReference))
        return false;

      MixedTriangleQuadSwapCandidate best;
      for(std::size_t diagonal = 0; diagonal < pentagon.size();
          ++diagonal) {
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

        std::unique_ptr<MTriangle> triangle(new MTriangle(
          proposedTriangle[0], proposedTriangle[1], proposedTriangle[2]));
        std::unique_ptr<MQuadrangle> quadrangle(new MQuadrangle(
          proposedQuadrangle[0], proposedQuadrangle[1],
          proposedQuadrangle[2], proposedQuadrangle[3]));
        triangle->setPartition(seed.triangle->getPartition());
        quadrangle->setPartition(seed.triangle->getPartition());
        triangle->setVisibility(seed.triangle->getVisibility());
        quadrangle->setVisibility(seed.triangle->getVisibility());
        std::vector<MElement *> replacement = {
          triangle.get(), quadrangle.get()};
        if(!orientElementsAccordingToBoundarySegment(
             pentagon[0], pentagon[1], replacement) ||
           !topology.validReplacement(seed.core.elements, replacement))
          continue;

        ++result.topologyCandidatesOptimized;
        SmoothedCavityEvaluation evaluation;
        if(!prepareSmoothedCavityEvaluation(
             face, seed.core.elements, replacement, topology, options,
             evaluation, seed.halfEdgeCavity,
             &fastCadProtectedVertices, nullptr, false, true,
             &evaluationReference)) {
          if(options.verbose > 2)
            Msg::Info("QuadOptimizer T+Q reject edge=(%lu,%lu)->"
                      "(%lu,%lu): C+C' support evaluation",
                      oldDiagonalVertices[0]->getNum(),
                      oldDiagonalVertices[1]->getNum(),
                      pentagon[diagonal]->getNum(),
                      pentagon[(diagonal + 2) % 5]->getNum());
          ++result.rejectedByWinslow;
          continue;
        }

        std::vector<std::size_t> triangleIndex, quadrangleIndex;
        if(!indexedElement(triangle.get(), evaluation.index,
                           triangleIndex) ||
           !indexedElement(quadrangle.get(), evaluation.index,
                           quadrangleIndex) ||
           triangleIndex.size() != 3 || quadrangleIndex.size() != 4)
          continue;
        std::array<std::size_t, 2> newDiagonal = {0, 0};
        std::size_t shared = 0;
        for(const std::size_t vertex : triangleIndex)
          if(std::find(quadrangleIndex.begin(), quadrangleIndex.end(),
                       vertex) != quadrangleIndex.end()) {
            if(shared >= newDiagonal.size()) {
              shared = newDiagonal.size() + 1;
              break;
            }
            newDiagonal[shared++] = vertex;
          }
        if(shared != 2) continue;

        const SpecificationObjective &referenceObjective =
          evaluation.metrics.referenceObjective;
        const SpecificationObjective &objective =
          evaluation.metrics.candidateObjective;
        if(objective.invalidElementCount != 0) continue;
        std::vector<Point> coreTrianglePoints(3);
        std::vector<Point> coreQuadranglePoints(4);
        for(std::size_t i = 0; i < coreTrianglePoints.size(); ++i)
          coreTrianglePoints[i] = evaluation.xyz[triangleIndex[i]];
        for(std::size_t i = 0; i < coreQuadranglePoints.size(); ++i)
          coreQuadranglePoints[i] = evaluation.xyz[quadrangleIndex[i]];
        const bool corePassesAbsoluteSpecifications =
          evaluateElementQuality(
            SurfaceElementKind::Triangle, coreTrianglePoints)
              .passesAbsoluteSpecifications &&
          evaluateElementQuality(
            SurfaceElementKind::Quadrangle, coreQuadranglePoints)
              .passesAbsoluteSpecifications;
        const SizeScore &beforeSize = evaluation.metrics.referenceSize;
        const SizeScore &afterSize = evaluation.metrics.candidateSize;
        const std::size_t beforeSizeViolations =
          beforeSize.belowMinimum + beforeSize.aboveMaximum +
          beforeSize.invalid;
        const std::size_t afterSizeViolations =
          afterSize.belowMinimum + afterSize.aboveMaximum +
          afterSize.invalid;

        // The new diagonal is mutable even when both endpoints are fixed CAD
        // vertices and the support scorer consequently exempts it.
        SizeScore diagonalSize;
        diagonalSize.admissible = true;
        double diagonalError = 0.;
        const std::size_t a = newDiagonal[0], b = newDiagonal[1];
        const UV midpointUv = {
          .5 * (evaluation.uv[a][0] + evaluation.uv[b][0]),
          .5 * (evaluation.uv[a][1] + evaluation.uv[b][1])};
        const Point midpointXyz = {
          .5 * (evaluation.xyz[a][0] + evaluation.xyz[b][0]),
          .5 * (evaluation.xyz[a][1] + evaluation.xyz[b][1]),
          .5 * (evaluation.xyz[a][2] + evaluation.xyz[b][2])};
        const EdgeLengthCriteria newCadCriteria = edgeLengthCriteria(
          face, midpointUv, midpointXyz, options);
        double newCadDistance = 0.;
        if(!edgeMidpointCadDistance(
             face, evaluation.uv[a], evaluation.uv[b],
             evaluation.xyz[a], evaluation.xyz[b], newCadDistance))
          continue;
        const EdgeMidpointCadSwapAssessment cadSwap =
          assessEdgeMidpointCadSwap(
            oldCadDistance, oldCadCriteria, newCadDistance,
            newCadCriteria, options);
        const double cadRatioScale = std::max(
          {1., std::abs(cadSwap.referenceRatio),
           std::abs(cadSwap.candidateRatio),
           std::abs(options.edgeMidpointCadSwapTriggerRatio)});
        const double cadRatioTolerance =
          64. * std::numeric_limits<double>::epsilon() * cadRatioScale;
        // Below the repair threshold, ordinary quality swaps may move the
        // chord inside the same harmless envelope. Once the old chord is a
        // geometric defect, even the ordinary path is forbidden to worsen
        // it; the geometry-driven path below additionally requires the
        // configured large reduction.
        const bool midpointCadAdmissible = cadSwap.valid &&
          (cadSwap.referenceCritical ?
             cadSwap.candidateRatio <=
               cadSwap.referenceRatio + cadRatioTolerance :
             cadSwap.candidateRatio <=
               options.edgeMidpointCadSwapTriggerRatio +
                 cadRatioTolerance);
        if(!midpointCadAdmissible) {
          if(options.verbose > 2)
            Msg::Info("QuadOptimizer T+Q reject edge=(%lu,%lu)->"
                      "(%lu,%lu): midpoint CAD/h=%g->%g",
                      oldDiagonalVertices[0]->getNum(),
                      oldDiagonalVertices[1]->getNum(),
                      pentagon[diagonal]->getNum(),
                      pentagon[(diagonal + 2) % 5]->getNum(),
                      cadSwap.referenceRatio, cadSwap.candidateRatio);
          continue;
        }
        accumulateSizeEdge(
          diagonalSize, diagonalError,
          newCadCriteria,
          distance(evaluation.xyz[a], evaluation.xyz[b]), true);
        if(options.enforceSizeMap &&
           (!afterSize.admissible || !diagonalSize.admissible ||
            afterSizeViolations > beforeSizeViolations ||
            !admissibleSizeChange(beforeSize, afterSize, options))) {
          ++result.rejectedBySize;
          continue;
        }

        const GeometryDeviation &referenceGeometry =
          evaluation.metrics.referenceGeometry;
        const GeometryDeviation &geometry =
          evaluation.metrics.candidateGeometry;
        if(!referenceGeometry.valid || !geometry.valid) continue;
        const double target = options.targetSize > 0. ?
          options.targetSize :
          std::sqrt(std::max(
            referenceGeometry.sampledArea /
              static_cast<double>(std::max<std::size_t>(
                1, referenceGeometry.elementCount)),
            std::numeric_limits<double>::min()));
        // Judge ordinary mixed swaps with the same dimensionless CAD budget
        // as the structural reductions: integral change is scaled by A*h^2
        // and maximum-distance change by h. A swap that strictly removes an
        // absolute defect may additionally use the repair envelope below,
        // provided its shared diagonal midpoint remains admissible.
        const double cadRepairEnvelope = std::max(
          referenceGeometry.maximumDistance,
          options.edgeMidpointCadSwapTriggerRatio * target);
        const double cadRepairTolerance =
          64. * std::numeric_limits<double>::epsilon() * std::max(
            {1., cadRepairEnvelope, geometry.maximumDistance});
        const bool repairsAbsoluteDefect =
          corePassesAbsoluteSpecifications &&
          objective.absoluteBadElementCount <
            referenceObjective.absoluteBadElementCount &&
          geometry.invalidSampleCount <=
            referenceGeometry.invalidSampleCount &&
          midpointCadAdmissible &&
          geometry.maximumDistance <=
            cadRepairEnvelope + cadRepairTolerance;
        double normalizedCadChange = 0.;
        double normalizedMaximumCadDistanceChange = 0.;
        const bool boundedCadRegression = geometryRegressionFitsMeshScale(
          geometry, referenceGeometry, target, options,
          normalizedCadChange, normalizedMaximumCadDistanceChange);
        if(!boundedCadRegression && !repairsAbsoluteDefect) {
          if(options.verbose > 2)
            Msg::Info("QuadOptimizer T+Q rejected mesh-scaled CAD "
                      "regression dCAD=%g dCADmax/h=%g",
                      normalizedCadChange,
                      normalizedMaximumCadDistanceChange);
          continue;
        }
        const ValenceObjective candidateValence = mixedValence(&replacement);
        const FastGlobalQuality referenceQuality = fastGlobalQuality(
          referenceObjective, referenceValence,
          referenceObjective.invalidElementCount, beforeSizeViolations,
          beforeSize.meanSquaredLogRatio, beforeSize.edgeCount, 0.);
        const FastGlobalQuality candidateQuality = fastGlobalQuality(
          objective, candidateValence, objective.invalidElementCount,
          afterSizeViolations, afterSize.meanSquaredLogRatio,
          afterSize.edgeCount, normalizedCadChange);
        const bool geometryDriven = cadSwap.strongImprovement &&
          corePassesAbsoluteSpecifications &&
          noWorseAbsoluteSpecifications(
            objective, referenceObjective,
            options.objectiveRelativeTolerance) &&
          afterSizeViolations <= beforeSizeViolations &&
          candidateValence.severeCount <= referenceValence.severeCount &&
          geometryDoesNotRegressBeyondRoundoff(
            geometry, referenceGeometry);
        if(!geometryDriven &&
           !improvesFastGlobalQuality(candidateQuality, referenceQuality)) {
          if(options.verbose > 2)
            Msg::Info("QuadOptimizer T+Q reject edge=(%lu,%lu)->"
                      "(%lu,%lu): global objective forbidden=%zu->%zu "
                      "hard=%zu->%zu hardPenalty=%g->%g "
                      "compromise=%g->%g valence[severe/irregular]="
                      "%zu/%zu->%zu/%zu preferred=%zu->%zu dCAD=%g",
                      oldDiagonalVertices[0]->getNum(),
                      oldDiagonalVertices[1]->getNum(),
                      pentagon[diagonal]->getNum(),
                      pentagon[(diagonal + 2) % 5]->getNum(),
                      referenceQuality.forbiddenConfigurationCount,
                      candidateQuality.forbiddenConfigurationCount,
                      referenceQuality.hardSpecificationViolationCount,
                      candidateQuality.hardSpecificationViolationCount,
                      referenceQuality.hardSpecificationPenalty,
                      candidateQuality.hardSpecificationPenalty,
                      referenceQuality.compromise,
                      candidateQuality.compromise,
                      referenceValence.severeCount,
                      referenceValence.irregularCount,
                      candidateValence.severeCount,
                      candidateValence.irregularCount,
                      referenceObjective.preferredViolationCount,
                      objective.preferredViolationCount,
                      normalizedCadChange);
          continue;
        }

        bool better = !best.valid;
        if(best.valid && geometryDriven != best.geometryDriven)
          better = geometryDriven;
        else if(best.valid && geometryDriven && best.geometryDriven) {
          const double rankingScale = std::max(
            {1., std::abs(cadSwap.candidateRatio),
             std::abs(best.cadSwap.candidateRatio)});
          const double rankingTolerance =
            64. * std::numeric_limits<double>::epsilon() * rankingScale;
          if(cadSwap.candidateRatio + rankingTolerance <
             best.cadSwap.candidateRatio)
            better = true;
          else if(best.cadSwap.candidateRatio + rankingTolerance <
                  cadSwap.candidateRatio)
            better = false;
          else if(improvesFastGlobalQuality(
                    candidateQuality, best.globalQuality))
            better = true;
          else if(!improvesFastGlobalQuality(
                    best.globalQuality, candidateQuality))
            better = objectivePriority(objective) <
                     objectivePriority(best.objective);
        }
        else if(best.valid &&
                improvesFastGlobalQuality(
                  candidateQuality, best.globalQuality))
          better = true;
        else if(best.valid &&
           !improvesFastGlobalQuality(candidateQuality,
                                      best.globalQuality) &&
           !improvesFastGlobalQuality(best.globalQuality,
                                      candidateQuality))
          better = objectivePriority(objective) <
                   objectivePriority(best.objective);
        if(!better) continue;

        best.valid = true;
        best.triangle = {triangle->getVertex(0), triangle->getVertex(1),
                         triangle->getVertex(2)};
        best.quadrangle = {
          quadrangle->getVertex(0), quadrangle->getVertex(1),
          quadrangle->getVertex(2), quadrangle->getVertex(3)};
        best.objective = objective;
        best.globalQuality = candidateQuality;
        best.geometry = geometry;
        best.referenceGeometry = referenceGeometry;
        best.sizeError = afterSize.meanSquaredLogRatio;
        best.cadSwap = cadSwap;
        best.geometryDriven = geometryDriven;
        best.decisionReason =
          geometryDriven ? CleanUpDecisionReason::BetterGeometry :
          objective.absoluteBadElementCount <
              referenceObjective.absoluteBadElementCount ?
            CleanUpDecisionReason::FewerUnacceptableElements :
            CleanUpDecisionReason::OtherImprovement;
        best.smoothedVertices = std::move(evaluation.movedVertices);
      }

      if(!best.valid) {
        ++result.rejectedByQuality;
        return false;
      }
      std::vector<MElement *> replacement = {
        new MTriangle(best.triangle[0], best.triangle[1], best.triangle[2]),
        new MQuadrangle(best.quadrangle[0], best.quadrangle[1],
                        best.quadrangle[2], best.quadrangle[3])};
      for(MElement *element : replacement) {
        element->setPartition(seed.triangle->getPartition());
        element->setVisibility(seed.triangle->getVisibility());
      }
      if(!orientElementsAccordingToBoundarySegment(
           pentagon[0], pentagon[1], replacement)) {
        for(MElement *element : replacement) delete element;
        return false;
      }
      GFaceMeshDiff diff;
      diff.gf = face;
      diff.before = seed.core;
      diff.after.gf = face;
      diff.after.bdrVertices = seed.core.bdrVertices;
      diff.after.elements = std::move(replacement);
      FaceRewriteTransaction transaction(topology, diff);
      if(!transaction || !transaction.execute()) return false;
      applySmoothedReplacementGeometry(best.smoothedVertices, topology);
      if(!best.smoothedVertices.empty())
        ++result.acceptedFinalSmoothingCavities;
      // Do not retain a history-dependent fixed-vertex mask for the new
      // diagonal. Every following overlapping transaction evaluates its
      // complete C+C' support against the same mesh-scaled CAD guards, so the
      // triangle can propagate through an admissible quad strip in this run
      // exactly as it can after saving and reloading the mesh.
      if(best.geometryDriven)
        ++result.acceptedGeometryDrivenMixedTriangleQuadSwaps;
      if(options.verbose)
        Msg::Info("QuadOptimizer CleanUp: accepted T+Q diagonal swap "
                  "B=5 reason=%s midpoint/h=%g->%g",
                  best.geometryDriven ? "geometry" : "cleanup",
                  best.cadSwap.referenceRatio,
                  best.cadSwap.candidateRatio);
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
                       FaceHalfEdgeTopology &topology,
                       const SmallCavityOptimizerOptions &options,
                       SmallCavityOptimizerResult &result,
                       std::size_t &insertedQuadrangles,
                       bool &alreadyPillowed)
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
      LocalPatchOrientationReference beforeOrientation;
      const LocalPatchOrientationReference *beforeOrientationPointer =
        nullptr;
      if(face->geomType() == GEntity::DiscreteSurface) {
        if(!buildLocalPatchOrientationReference(
             face, originalPatch.elements, beforeOrientation))
          return false;
        beforeOrientationPointer = &beforeOrientation;
      }
      const SizeScore beforePillowSize =
        existingSizeScore(originalPatch, options, false);

      std::vector<Point> xyz;
      bool acceptedGeometry = false;
      bool rejectedByWinslow = false;
      bool rejectedByQuality = false;
      bool rejectedBySize = false;
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
        if(valid && !candidateQuadranglesAreNonConcave(
             quadrangles, trialPoints, trialXyz))
          valid = false;
        if(valid && !indexedPatchPreservesSurfaceOrientation(
             face, beforeOrientationPointer, trialPoints, trialXyz,
             triangles, quadrangles))
          valid = false;
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
        if(options.enforceSizeMap) {
          size = surfacePatchSizeScore(
            face, trialPoints, trialXyz, triangles, quadrangles, fixed,
            options);
          if(!size.admissible ||
             !admissibleSizeChange(beforePillowSize, size, options)) {
            rejectedBySize = true;
            continue;
          }
        }
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
      insertedQuadrangles = loop.size();
      return true;
    }

    void pillowFaceHoles(GFace *face,
                         const SmallCavityOptimizerOptions &options,
                         SmallCavityOptimizerResult &result,
                         FaceHalfEdgeTopology &topology)
    {
      if(!topology.manifold()) return;
      std::vector<BoundaryLoop> loops;
      if(!collectBoundaryLoops(face, topology, loops) || loops.size() < 2)
        return;
      // Classify each component from its domain-left orientation in the GFace
      // parameter plane: outer components have positive signed area, holes
      // negative signed area. Perimeter is not a topological classifier (a
      // hole can be longer than an outer component, and a face can have
      // several disconnected components).
      for(const BoundaryLoop &boundary : loops) {
        if(!topology.catalogAcceptsBoundaryLoop(boundary.vertices.size()))
          continue;
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
        ++result.pillowHolesVisited;
        std::size_t inserted = 0;
        bool alreadyPillowed = false;
        if(!tryPillowHole(face, hole, options.pillowNeighborLayers,
                          topology, options, result, inserted,
                          alreadyPillowed)) {
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

  static TerminalTriangleRecombinationResult
  recombineRemainingTrianglePairsWithTopology(
    GFace *face, const SmallCavityOptimizerOptions &options,
    FaceHalfEdgeTopology &topology,
    const std::set<MVertex *> *additionalProtectedVertices = nullptr,
    const CavityAttemptStateBuilder *attemptStateBuilder = nullptr,
    RejectedCavityStateSet *rejectedCavityAttempts = nullptr)
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
    if(!topology.manifold()) {
      result.success = false;
      ++result.rejectedTopology;
      return result;
    }

    struct PairSeed {
      CavitySeed cavity;
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

    const std::size_t maximumAccepted = topology.elementCount(3) / 2;
    while(result.accepted < maximumAccepted &&
          topology.elementCount(3) >= 2) {
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

        const std::vector<MElement *> pairElements = {first, second};
        HalfEdgeMesh::Cavity edgeCavity;
        PairSeed pair;
        if(!topology.cavityAroundEdge(entry.first, edgeCavity) ||
           !materializeCavitySeed(
             face, edgeCavity, topology, pair.cavity) ||
           !topology.catalogAccepts(pair.cavity.halfEdgeCavity) ||
           pair.cavity.patch.bdrVertices.size() != 1 ||
           pair.cavity.patch.bdrVertices.front().size() != 4 ||
           !pair.cavity.patch.intVertices.empty() ||
           !pair.cavity.patch.embVertices.empty())
          continue;
        pair.first = first;
        pair.second = second;
        pair.shared = entry.first;
        pair.boundary = pair.cavity.patch.bdrVertices.front();
        pairs.push_back(std::move(pair));
      }
      std::sort(pairs.begin(), pairs.end(), boundaryLess);

      bool changed = false;
      for(const PairSeed &pair : pairs) {
        CavityStateSignature state;
        const bool cacheable = attemptStateBuilder &&
          rejectedCavityAttempts &&
          (*attemptStateBuilder)(pair.cavity, state);
        if(cacheable &&
           rejectedCavityAttempts->find(state) !=
             rejectedCavityAttempts->end())
          continue;
        const auto rememberRejected = [&]() {
          if(cacheable) rejectedCavityAttempts->insert(state);
        };
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
          rememberRejected();
          continue;
        }

        const CavitySeed &seed = pair.cavity;
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
          rememberRejected();
          continue;
        }
        // T+T -> Q is an acyclic triangle-reduction rewrite. In the staged
        // topology pass a valid, oriented, non-concave quad is sufficient;
        // the later global smoothing owns its final element quality.
        SmoothedCavityEvaluation evaluation;
        if(!prepareSmoothedCavityEvaluation(
             face, pairElements, replacement, topology, options,
             evaluation, seed.halfEdgeCavity,
             additionalProtectedVertices)) {
          ++result.rejectedInvalid;
          rememberRejected();
          continue;
        }

        std::vector<std::size_t> quadVertices;
        if(!indexedElement(quadrangle.get(), evaluation.index,
                           quadVertices) ||
                           quadVertices.size() != 4) {
          ++result.rejectedInvalid;
          rememberRejected();
          continue;
        }
        Pattern createdQuadrangle(1);
        std::vector<Point> quadPoints(4);
        for(std::size_t i = 0; i < 4; ++i) {
          createdQuadrangle.front()[i] = quadVertices[i];
          quadPoints[i] = evaluation.xyz[quadVertices[i]];
        }
        const ElementQuality quadQuality = evaluateElementQuality(
          SurfaceElementKind::Quadrangle, quadPoints);
        const double worstAngleDeviation = std::max(
          std::abs(90. - quadQuality.minimumAngleDegrees),
          std::abs(quadQuality.maximumAngleDegrees - 90.));
        const double eta = quadQuality.topologicallyValid ?
          1. - worstAngleDeviation / 90. : -1.;
        if(!candidateQuadranglesAreNonConcave(
             evaluation.quadrangles, evaluation.uv, evaluation.xyz) ||
           (!options.acceptValidTopologyReduction &&
            !quadranglesPassAbsoluteSpecifications(
              replacement, evaluation)) ||
           !std::isfinite(eta) ||
           eta < options.minimumRecombinationQuality + 1.e-12) {
          ++result.rejectedInvalid;
          rememberRejected();
          continue;
        }

        const SpecificationObjective &referenceObjective =
          evaluation.metrics.referenceObjective;
        const SpecificationObjective &candidateObjective =
          evaluation.metrics.candidateObjective;
        if(!options.acceptValidTopologyReduction &&
           !noWorseAbsoluteSpecifications(
             candidateObjective, referenceObjective,
             options.objectiveRelativeTolerance)) {
          ++result.rejectedQuality;
          rememberRejected();
          continue;
        }

        const SizeScore &beforeSize = evaluation.metrics.referenceSize;
        const SizeScore &afterSize = evaluation.metrics.candidateSize;
        // All four edges of the newly created quad are mutable topology,
        // even when they happen to lie on the support boundary.
        const SizeScore createdQuadSize = candidateSizeScore(
          face, evaluation.uv, evaluation.xyz, createdQuadrangle,
          options, 0);
        const std::size_t beforeSizeViolations =
          beforeSize.belowMinimum + beforeSize.aboveMaximum +
          beforeSize.invalid;
        const std::size_t afterSizeViolations =
          afterSize.belowMinimum + afterSize.aboveMaximum +
          afterSize.invalid;
        if(options.enforceSizeMap &&
           !options.acceptValidTopologyReduction &&
           (!createdQuadSize.admissible || !afterSize.admissible ||
            afterSizeViolations > beforeSizeViolations ||
            !admissibleSizeChange(beforeSize, afterSize, options))) {
          ++result.rejectedSize;
          rememberRejected();
          continue;
        }

        const GeometryDeviation &referenceGeometry =
          evaluation.metrics.referenceGeometry;
        const GeometryDeviation &candidateGeometry =
          evaluation.metrics.candidateGeometry;
        if(!referenceGeometry.valid || !candidateGeometry.valid ||
           (!options.acceptValidTopologyReduction &&
            !geometryDoesNotRegressBeyondRoundoff(
              candidateGeometry, referenceGeometry))) {
          ++result.rejectedGeometry;
          rememberRejected();
          continue;
        }

        GFaceMeshDiff diff;
        diff.gf = face;
        diff.before = seed.patch;
        diff.before.intVertices.clear();
        diff.after.gf = face;
        diff.after.bdrVertices = seed.patch.bdrVertices;
        diff.after.elements = {quadrangle.release()};
        FaceRewriteTransaction transaction(topology, diff);
        if(!transaction || !transaction.execute()) {
          ++result.rejectedTopology;
          rememberRejected();
          continue;
        }
        applySmoothedReplacementGeometry(evaluation, topology);
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

  TerminalTriangleRecombinationResult recombineRemainingTrianglePairs(
    GFace *face, const SmallCavityOptimizerOptions &options)
  {
    FaceHalfEdgeTopology topology(surfaceElements(face));
    return recombineRemainingTrianglePairsWithTopology(
      face, options, topology);
  }

  SmallCavityOptimizerResult optimizeSmallQuadCavities(
    GFace *face, const SmallCavityOptimizerOptions &options)
  {
    clearFaceGeometryCaches();
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
    std::vector<MElement *> initialElements = surfaceElements(face);
    // Validate the half-edge complex and choose its physical side in one
    // transactional pass. No element is reversed unless the complete input
    // complex is regular and orientable.
    const SurfaceOrientationRepairResult initialOrientation =
      repairSurfaceElementOrientation(face, initialElements, true, true);
    if(!initialOrientation.structurallyRegular) {
      result.skippedInvalidInputCellComplex = true;
      Msg::Warning("QuadOptimizer: face %d is not a regular oriented "
                   "surface cell complex; skipping optimization",
                   face->tag());
      return result;
    }

    if(!initialOrientation.orientable) {
      Msg::Warning("QuadOptimizer: face %d has a non-orientable surface "
                   "cell complex; skipping optimization", face->tag());
      result.skippedInvalidInputCellComplex = true;
      result.initialObjective = specificationObjective(initialElements);
      result.finalObjective = result.initialObjective;
      if(options.enforceSizeMap) {
        setInitialSizeStatistics(result, faceSizeScore(face, options));
        setFinalSizeStatistics(result, faceSizeScore(face, options));
      }
      if(options.invalidateVertexArrays)
        face->model()->deleteVertexArrays();
      return result;
    }
    result.reorientedElements += initialOrientation.reorientedElements;
    if(initialOrientation.reorientedElements &&
       options.invalidateVertexArrays)
      face->model()->deleteVertexArrays();

    result.initialObjective = specificationObjective(initialElements);
    if(options.enforceSizeMap)
      setInitialSizeStatistics(result, faceSizeScore(face, options));
    auto finishSkippedInputFace = [&]() {
      result.skippedInvalidInputCellComplex = true;
      result.finalObjective =
        specificationObjective(surfaceElements(face));
      if(options.enforceSizeMap)
        setFinalSizeStatistics(result, faceSizeScore(face, options));
      if(options.invalidateVertexArrays)
        face->model()->deleteVertexArrays();
    };

    // Blossom can match four regular triangles into two quads whose
    // intersection is a two-edge chain. On an oriented surface, one of these
    // two quads is necessarily concave (or degenerate). Identify exactly
    // those exceptional pairs: ordinary concave quads must remain available
    // to the cavity catalog, which can repair their surrounding connectivity
    // without manufacturing a pair of terminal triangles first.
    std::map<Edge, std::vector<MQuadrangle *> > initialQuadEdges;
    for(MQuadrangle *quad : face->quadrangles)
      if(quad)
        for(std::size_t i = 0; i < 4; ++i)
          initialQuadEdges[canonicalEdge(
            quad->getVertex(static_cast<int>(i)),
            quad->getVertex(static_cast<int>((i + 1) % 4)))].push_back(quad);
    std::map<std::pair<MQuadrangle *, MQuadrangle *>, std::size_t>
      sharedQuadEdgeCount;
    for(const auto &entry : initialQuadEdges) {
      if(entry.second.size() != 2 || entry.second[0] == entry.second[1])
        continue;
      MQuadrangle *first = entry.second[0];
      MQuadrangle *second = entry.second[1];
      if(std::less<MQuadrangle *>()(second, first))
        std::swap(first, second);
      ++sharedQuadEdgeCount[{first, second}];
    }
    std::set<MQuadrangle *> overlappingQuadChainElements;
    for(const auto &entry : sharedQuadEdgeCount)
      if(entry.second == 2) {
        overlappingQuadChainElements.insert(entry.first.first);
        overlappingQuadChainElements.insert(entry.first.second);
      }

    // Restore the safe diagonal only in that structural repair set before
    // asking the strict half-edge cell-complex index to accept the face.
    const WarpedQuadrangleSplitResult preflightSplit =
      splitExcessivelyWarpedQuadrangles(
        face, std::numeric_limits<double>::max(), {}, {},
        [&](GFace *, MQuadrangle *quad) {
          return overlappingQuadChainElements.find(quad) !=
                 overlappingQuadChainElements.end();
        });
    result.excessiveWarpingQuadrangles += preflightSplit.excessiveWarping;
    result.nonConvexOrInvalidQuadrangles +=
      preflightSplit.nonConvexOrInvalid;
    result.warpedQuadranglesSplit += preflightSplit.split;
    const std::size_t preflightRejected = preflightSplit.rejectedInvalid +
      preflightSplit.rejectedUnsupportedOrder;
    result.warpedQuadranglesRejected += preflightRejected;
    if(preflightSplit.split && options.invalidateVertexArrays)
      face->model()->deleteVertexArrays();
    if(preflightRejected != 0) {
      Msg::Warning("QuadOptimizer: face %d retains %zu prohibited concave "
                   "or invalid input quads because no geometrically valid "
                   "diagonal exists; leaving them to the cavity catalog",
                   face->tag(),
                   preflightRejected);
    }

    initialElements = surfaceElements(face);
    const SurfaceOrientationRepairResult orientation =
      repairSurfaceElementOrientation(face, initialElements);
    if(!orientation.structurallyRegular) {
      Msg::Warning("QuadOptimizer: face %d is not a regular oriented "
                   "surface cell complex; skipping optimization",
                   face->tag());
      finishSkippedInputFace();
      return result;
    }
    if(!orientation.orientable) {
      Msg::Warning("QuadOptimizer: face %d has a non-orientable surface "
                   "cell complex; skipping optimization", face->tag());
      finishSkippedInputFace();
      return result;
    }
    result.reorientedElements += orientation.reorientedElements;
    if(orientation.reorientedElements && options.invalidateVertexArrays)
      face->model()->deleteVertexArrays();

    FaceHalfEdgeTopology topology(initialElements);
    if(!topology.manifold()) {
      Msg::Warning("QuadOptimizer: face %d is not a regular oriented "
                   "surface cell complex after repairing element "
                   "orientations and concave input quads; skipping "
                   "optimization", face->tag());
      finishSkippedInputFace();
      return result;
    }
    (void)buildInitialPackNormalAtlas(face, initialElements);
    // This set is deliberately call-local and currently remains empty. It is
    // threaded through the common C+C' interfaces so a future rule can add a
    // transaction-local protection without reintroducing the old accepted-
    // edge history, which made an identical saved/reloaded mesh take a
    // different propagation path.
    std::set<MVertex *> fastCadProtectedVertices;
    const std::set<MVertex *> &permanentlyProtectedVertices =
      topology.protectedVertices(face);
    RejectedCavityStateSet rejectedCavityAttempts;
    // Reversible QQ guards grow monotonically inside one catalog scan, then
    // are deliberately cleared before a fresh complete-closure round. A
    // rejection that depended on those guards is reusable only within that
    // epoch, even when the geometric cavity itself did not change.
    std::uint64_t quadSwapGuardEpoch = 0;
    auto halfEdgeCavityAttemptState = [&]
      (HalfEdgeRewriteKind rule, CleanUpDecisionPhase phase,
       HalfEdgeRewriteSymmetry symmetry,
       const HalfEdgeMesh::Cavity &halfEdgeCavity,
       CavityPurpose purpose,
       const std::set<MVertex *> *additionalProtectedVertices,
       CavityStateSignature &signature) -> bool {
      // On discrete faces UV is recovered deterministically from XYZ.  This
      // makes the numeric half-edge state a complete cache key; retain the
      // conservative uncached path for general CAD parameterizations.
      const bool cacheableRule =
        rule == HalfEdgeRewriteKind::QuadQuadSwap ||
        options.stagedTopologyThenQuality;
      if(!cacheableRule ||
         !useFastInteractiveCleanUp(options) ||
         options.edgeLengthCriteriaAt ||
         face->geomType() != GEntity::DiscreteSurface ||
         !topology.cavityEvaluationStateSignature(
           face, halfEdgeCavity, &permanentlyProtectedVertices,
           additionalProtectedVertices, signature))
        return false;
      signature.insert(signature.begin(), {
        static_cast<std::uint64_t>(rule),
        static_cast<std::uint64_t>(phase),
        static_cast<std::uint64_t>(symmetry),
        static_cast<std::uint64_t>(purpose)});
      if(purpose == CavityPurpose::Edge)
        signature.push_back(quadSwapGuardEpoch);
      return true;
    };
    auto cavityAttemptState = [&]
      (HalfEdgeRewriteKind rule, CleanUpDecisionPhase phase,
       HalfEdgeRewriteSymmetry symmetry, const CavitySeed &seed,
       const std::set<MVertex *> *additionalProtectedVertices,
       CavityStateSignature &signature) -> bool {
      return halfEdgeCavityAttemptState(
        rule, phase, symmetry, seed.halfEdgeCavity, seed.kind,
        additionalProtectedVertices, signature);
    };
    // A quad-quad swap is reversible. Local shape/valence objectives can
    // change after neighboring rewrites and otherwise make the same pair of
    // diagonals oscillate until maximumAcceptedCavities is reached. Keep the
    // Fast face transaction acyclic: a removed diagonal cannot be recreated,
    // and the same unordered transition is attempted at most once.
    std::set<Edge> removedQuadSwapEdges;
    std::set<QuadSwapTransition> quadSwapTransitions;
    // Populated only for the last CleanUp pass when diagnostic verbosity is
    // requested. Normal runs do not construct a signature or increment an
    // instrumentation counter.
    TriangleQuadStripDiagnostics stripDiagnostics;
    TriangleQuadStripDiagnostics *activeStripDiagnostics =
      options.verbose > 1 ? &stripDiagnostics : nullptr;
    enum class StagedFastPhase { None, Topology, Quality };
    StagedFastPhase stagedFastPhase = StagedFastPhase::None;
    SmallCavityOptimizerOptions strictUnsmoothedQualityOptions = options;
    strictUnsmoothedQualityOptions.stagedTopologyThenQuality = true;
    strictUnsmoothedQualityOptions.evaluateCandidatesWithoutLocalSmoothing =
      true;
    strictUnsmoothedQualityOptions.requireStrictElementQualityImprovement =
      true;
    SmallCavityOptimizerOptions mandatoryTopologyOptions = options;
    mandatoryTopologyOptions.stagedTopologyThenQuality = true;
    mandatoryTopologyOptions.evaluateCandidatesWithoutLocalSmoothing = true;
    mandatoryTopologyOptions.acceptValidTopologyReduction = true;
    const auto stagedCandidateOptions = [&]()
      -> const SmallCavityOptimizerOptions & {
      return stagedFastPhase == StagedFastPhase::Quality ?
        strictUnsmoothedQualityOptions : options;
    };
    const auto mandatoryReductionOptions = [&]()
      -> const SmallCavityOptimizerOptions & {
      return stagedFastPhase == StagedFastPhase::Topology ?
        mandatoryTopologyOptions : stagedCandidateOptions();
    };

    bool terminalTransactionLostSynchronization = false;
    const QuadrangleSplitTransactionCommit commitTerminalQuadSplits =
      [&](GFace *candidateFace, const std::vector<MElement *> &removed,
          const std::vector<MElement *> &inserted) {
        GFaceMeshDiff diff;
        diff.gf = candidateFace;
        diff.before.gf = candidateFace;
        diff.before.elements = removed;
        diff.after.gf = candidateFace;
        diff.after.elements = inserted;
        FaceRewriteTransaction transaction(topology, diff);
        const bool synchronized =
          transaction && transaction.execute();
        if(!diff.done) {
          // The split planner still owns the proposed triangles on rejection.
          // Prevent GFaceMeshDiff's destructor from deleting them before the
          // planner performs its normal cleanup.
          diff.after.elements.clear();
        }
        else if(!synchronized) {
          // Ownership was transferred, but even the exceptional rebuild
          // failed. Never let the planner delete elements now owned by GFace.
          terminalTransactionLostSynchronization = true;
          return true;
        }
        return synchronized;
      };

    auto recombineTerminalTrianglePairs = [&]
      (CleanUpDecisionPhase phase,
       HalfEdgeRewriteSymmetry symmetry) -> std::size_t {
      if(topology.elementCount(3) < 2) return 0;
      SmallCavityOptimizerOptions terminalOptions =
        mandatoryReductionOptions();
      terminalOptions.invalidateVertexArrays = false;
      const CavityAttemptStateBuilder attemptStateBuilder =
        [&](const CavitySeed &seed, CavityStateSignature &state) {
          return cavityAttemptState(
            HalfEdgeRewriteKind::TerminalTrianglePairRecombination,
            phase, symmetry, seed, &fastCadProtectedVertices, state);
        };
      const TerminalTriangleRecombinationResult recombination =
        recombineRemainingTrianglePairsWithTopology(
          face, terminalOptions, topology, &fastCadProtectedVertices,
          &attemptStateBuilder, &rejectedCavityAttempts);
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

    auto splitInvalidQuadrangles = [&]
      (CleanUpDecisionPhase phase,
       HalfEdgeRewriteSymmetry symmetry) -> std::size_t {
      std::vector<CavityStateSignature> attemptedStates;
      const QuadrangleSplitSelection catalogSingleQuadrangle =
        [&](GFace *candidateFace, MQuadrangle *quadrangle) {
          HalfEdgeMesh::Cavity cavity;
          if(candidateFace != face || !quadrangle ||
             !topology.singleQuadrangleCavity(quadrangle, cavity) ||
             !topology.catalogAccepts(cavity))
            return false;
          CavityStateSignature state;
          const bool cacheable = halfEdgeCavityAttemptState(
            HalfEdgeRewriteKind::InvalidQuadSplit, phase, symmetry,
            cavity, CavityPurpose::Quadrangle,
            &fastCadProtectedVertices, state);
          if(cacheable &&
             rejectedCavityAttempts.find(state) !=
               rejectedCavityAttempts.end())
            return false;
          if(cacheable) attemptedStates.push_back(std::move(state));
          return true;
        };
      const WarpedQuadrangleSplitResult split =
        splitExcessivelyWarpedQuadrangles(
          face, absoluteMaximumQuadWarpingDegrees, {}, {},
          catalogSingleQuadrangle, {}, {}, true, commitTerminalQuadSplits);
      result.excessiveWarpingQuadrangles += split.excessiveWarping;
      result.nonConvexOrInvalidQuadrangles += split.nonConvexOrInvalid;
      result.warpedQuadranglesSplit += split.split;
      // With no commit the selector has visited every eligible quadrangle;
      // each recorded state is therefore a proven rejection.  A successful
      // split can stop or alter the scan, so defer all certificates until the
      // next pass, where changed one-rings receive different exact keys.
      if(split.split == 0)
        for(CavityStateSignature &state : attemptedStates)
          rejectedCavityAttempts.insert(std::move(state));
      const std::size_t rejected = split.rejectedInvalid +
        split.rejectedBySize + split.rejectedUnsupportedOrder;
      result.warpedQuadranglesRejected += rejected;
      if(terminalTransactionLostSynchronization) {
        result.success = false;
        return 0;
      }
      if(rejected != 0) {
        // A protected or geometrically unsplittable residual defect is a
        // quality warning, not a corrupt mesh. In particular, never turn the
        // final best valid state into a process-stopping Msg::Error.
        Msg::Warning("QuadOptimizer: face %d retains %zu concave, invalid "
                     "or excessively warped quadrangles because no valid "
                     "split is admissible; keeping the last valid state",
                     face->tag(), rejected);
      }
      return split.split;
    };

    auto splitCatastrophicAngleQuadrangles = [&]() -> std::size_t {
      // Snapshot the residual catastrophic-angle defects and attempt each
      // quad exactly once.
      // Per-quad transactions ensure that one CAD- or size-protected defect
      // does not prevent independent admissible repairs elsewhere.
      auto hasCatastrophicAngles = [](MQuadrangle *quadrangle) {
        if(!quadrangle) return false;
        const ElementQuality quality = evaluateElementQuality(quadrangle);
        return quality.topologicallyValid &&
          std::isfinite(quality.minimumAngleDegrees) &&
          std::isfinite(quality.maximumAngleDegrees) &&
          (quality.minimumAngleDegrees <= 25. ||
           quality.maximumAngleDegrees >= 160.);
      };
      std::vector<MQuadrangle *> candidates;
      candidates.reserve(face->quadrangles.size());
      for(MQuadrangle *quadrangle : face->quadrangles)
        if(hasCatastrophicAngles(quadrangle))
          candidates.push_back(quadrangle);

      const QuadrangleDiagonalAdmissibility diagonalAdmissible =
        [&](GFace *candidateFace, MVertex *a, MVertex *b) {
          if(candidateFace != face || !a || !b) return false;
          SPoint2 auv, buv;
          if(!persistentFaceParameter(face, a, auv) ||
             !reparamMeshVertexOnFaceWithRef(face, b, auv, buv))
            return false;
          const UV midpointUv = {.5 * (auv.x() + buv.x()),
                                 .5 * (auv.y() + buv.y())};
          const Point midpointXyz = {.5 * (a->x() + b->x()),
                                     .5 * (a->y() + b->y()),
                                     .5 * (a->z() + b->z())};
          const EdgeLengthCriteria criteria = edgeLengthCriteria(
            face, midpointUv, midpointXyz, options);
          if(!validEdgeLengthCriteria(criteria)) return false;
          const double minimum = std::max(
            criteria.minimum, .5 * criteria.target);
          const double maximum = std::min(
            criteria.maximum, 2. * criteria.target);
          if(!(maximum >= minimum)) return false;
          const Point ax = {a->x(), a->y(), a->z()};
          const Point bx = {b->x(), b->y(), b->z()};
          const double length = distance(ax, bx);
          if(!std::isfinite(length)) return false;
          const double tolerance = 1.e-10 * std::max(
            {1., length, minimum, maximum});
          return length >= minimum - tolerance &&
                 length <= maximum + tolerance;
        };
      const QuadrangleSplitGeometryAdmissibility geometryAdmissible =
        [&](GFace *candidateFace, MQuadrangle *quadrangle,
            MElement *first, MElement *second) {
          if(candidateFace != face || !quadrangle || !first || !second)
            return false;
          const GeometryDeviation reference =
            existingGeometryDeviation(face, {quadrangle});
          const GeometryDeviation candidate =
            existingGeometryDeviation(face, {first, second});
          // This is the last-resort rule requested for a quad whose angles
          // violate the all-elements criteria after every topology and
          // smoothing pass.  A valid pair of surface triangles is preferable
          // to retaining that prohibited quad; the strict roundoff-only CAD
          // comparison used for optional swaps must not veto the fallback.
          return reference.valid && candidate.valid;
        };

      std::size_t accepted = 0;
      for(MQuadrangle *quadrangle : candidates) {
        // No preceding split removes another candidate, but retain this
        // membership guard as a local lifetime invariant.
        if(std::find(face->quadrangles.begin(), face->quadrangles.end(),
                     quadrangle) == face->quadrangles.end())
          continue;
        const QuadrangleSplitSelection selected =
          [&, quadrangle](GFace *candidateFace, MQuadrangle *candidate) {
            HalfEdgeMesh::Cavity cavity;
            return candidateFace == face && candidate == quadrangle &&
              topology.singleQuadrangleCavity(candidate, cavity) &&
              topology.catalogAccepts(cavity);
          };
        const QuadrangleSplitRequirement required =
          [quadrangle, &hasCatastrophicAngles](
            GFace *, MQuadrangle *candidate) {
            return candidate == quadrangle &&
              hasCatastrophicAngles(candidate);
          };
        const WarpedQuadrangleSplitResult split =
          splitExcessivelyWarpedQuadrangles(
            face, absoluteMaximumQuadWarpingDegrees,
            diagonalAdmissible, {}, selected, required,
            geometryAdmissible, true, commitTerminalQuadSplits);
        result.catastrophicAngleQuadranglesSelectedForSplit +=
          split.selectedByRequirement;
        result.catastrophicAngleQuadranglesSplit += split.split;
        result.catastrophicAngleQuadranglesRejectedBySize +=
          split.rejectedBySize;
        result.catastrophicAngleQuadranglesRejectedByGeometry +=
          split.rejectedByGeometry;
        result.catastrophicAngleQuadranglesRejectedOther +=
          split.rejectedInvalid + split.rejectedUnsupportedOrder;
        if(terminalTransactionLostSynchronization) {
          result.success = false;
          return accepted;
        }
        accepted += split.split;
      }
      return accepted;
    };

    auto convertAllBoundaryTriangleQuadTriangleFans =
      [&](CleanUpDecisionPhase phase,
          HalfEdgeRewriteSymmetry symmetry) -> std::size_t {
      if(!options.convertBoundaryTriangleQuadTriangleFans ||
         topology.elementCount(3) < 2 || topology.elementCount(4) < 1)
        return 0;
      std::size_t accepted = 0;
      const std::size_t maximumConversions =
        topology.elementCount(3) / 2 + 1;
      for(std::size_t conversion = 0; conversion < maximumConversions;
          ++conversion) {
        const std::vector<CavitySeed> fans =
          collectBoundaryTriangleQuadTriangleFans(face, topology);
        if(fans.empty()) break;
        bool changed = false;
        for(const CavitySeed &fan : fans) {
          if(!topology.catalogAccepts(fan.halfEdgeCavity)) continue;
          CavityStateSignature state;
          const bool cacheable = cavityAttemptState(
            HalfEdgeRewriteKind::BoundaryTriangleQuadFan, phase,
            symmetry, fan, &fastCadProtectedVertices, state);
          if(cacheable &&
             rejectedCavityAttempts.find(state) !=
               rejectedCavityAttempts.end())
            continue;
          ++result.boundaryTriangleQuadTriangleFansVisited;
          std::size_t fanTriangles = 0, fanQuadrangles = 0;
          for(MElement *element : fan.patch.elements) {
            if(!element) continue;
            fanTriangles += element->getNumPrimaryVertices() == 3;
            fanQuadrangles += element->getNumPrimaryVertices() == 4;
          }
          const bool mandatoryBoundaryTQQT =
            stagedFastPhase == StagedFastPhase::Topology &&
            fanTriangles == 2 && fanQuadrangles == 2;
          const SmallCavityOptimizerOptions &fanOptions =
            mandatoryBoundaryTQQT ? mandatoryTopologyOptions :
                                    stagedCandidateOptions();
          if(!tryTriangleQuadTriangleFanWithNewCenter(
               face, fan, topology, fanOptions, result, phase, symmetry)) {
            if(cacheable)
              rejectedCavityAttempts.insert(std::move(state));
            continue;
          }
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

    auto convertAllOppositeEdgeTriangleQuadFans =
      [&](CleanUpDecisionPhase phase,
          HalfEdgeRewriteSymmetry symmetry) -> std::size_t {
      if(topology.elementCount(3) < 2 || topology.elementCount(4) < 1)
        return 0;
      std::size_t accepted = 0;
      const std::size_t maximumConversions = topology.elementCount(3) / 2;
      while(accepted < maximumConversions &&
            accepted <
              static_cast<std::size_t>(options.maximumAcceptedCavities)) {
        const std::vector<CavitySeed> fans =
          collectOppositeEdgeTriangleQuadFans(face, topology);
        bool changed = false;
        for(const CavitySeed &fan : fans) {
          if(!topology.catalogAccepts(fan.halfEdgeCavity)) continue;
          CavityStateSignature state;
          const bool cacheable = cavityAttemptState(
            HalfEdgeRewriteKind::OppositeEdgeTriangleQuadFan, phase,
            symmetry, fan, &fastCadProtectedVertices, state);
          if(cacheable &&
             rejectedCavityAttempts.find(state) !=
               rejectedCavityAttempts.end())
            continue;
          ++result.oppositeEdgeTriangleQuadFansVisited;
          if(!tryTriangleQuadTriangleFanWithNewCenter(
               face, fan, topology, stagedCandidateOptions(), result,
               phase, symmetry)) {
            if(cacheable)
              rejectedCavityAttempts.insert(std::move(state));
            continue;
          }
          changed = true;
          ++accepted;
          ++result.acceptedOppositeEdgeTriangleQuadFans;
          if(options.verbose)
            Msg::Info("QuadOptimizer CleanUp: accepted opposite-edge "
                      "T-Q-T -> 3Q fan B=6 I=0->1");
          break;
        }
        if(!changed) break;
      }
      return accepted;
    };

    auto optimizeOppositeEdgeTriangleQuadSwapStage =
      [&](CleanUpDecisionPhase phase,
          HalfEdgeRewriteSymmetry symmetry) -> std::size_t {
      if(!useFastInteractiveCleanUp(options) ||
         phase != CleanUpDecisionPhase::Any ||
         topology.elementCount(3) < 2 || topology.elementCount(4) < 1)
        return 0;
      std::size_t accepted = 0;
      while(accepted <
            static_cast<std::size_t>(options.maximumAcceptedCavities)) {
        if(!topology.manifold()) break;
        const std::vector<TriangleQuadStripReductionSeed> swaps =
          collectOppositeEdgeTriangleQuadStrips(face, topology);
        bool changed = false;
        for(const TriangleQuadStripReductionSeed &swap : swaps) {
          if(!topology.catalogAccepts(
               swap.cavity.halfEdgeCavity))
            continue;
          CavityStateSignature state;
          const bool cacheable = cavityAttemptState(
            HalfEdgeRewriteKind::OppositeEdgeTriangleQuadSwap, phase,
            symmetry, swap.cavity, &fastCadProtectedVertices, state);
          if(cacheable &&
             rejectedCavityAttempts.find(state) !=
               rejectedCavityAttempts.end())
            continue;
          ++result.oppositeEdgeTriangleQuadSwapsVisited;
          if(!tryOppositeEdgeTriangleQuadSwap(
               face, swap, topology, stagedCandidateOptions(), result,
               phase, symmetry, fastCadProtectedVertices)) {
            if(cacheable)
              rejectedCavityAttempts.insert(std::move(state));
            continue;
          }
          changed = true;
          ++accepted;
          ++result.acceptedOppositeEdgeTriangleQuadSwaps;
          ++result.acceptedEdgeSwaps;
          break;
        }
        if(!changed) break;
      }
      return accepted;
    };

    auto eliminateAllDiamonds =
      [&](CleanUpDecisionPhase phase,
          HalfEdgeRewriteSymmetry symmetry) -> std::size_t {
      if(!options.eliminateDiamonds) return 0;
      std::size_t accepted = 0;
      // A successful diamond collapse removes one interior vertex, so this
      // loop is finite independently of the general topology-change limit.
      const std::size_t maximumDiamondCollapses = face->mesh_vertices.size();
      for(std::size_t collapse = 0; collapse < maximumDiamondCollapses;
          ++collapse) {
        const std::vector<DiamondSeed> diamonds =
          collectDiamonds(face, topology);
        if(diamonds.empty()) break;
        bool changed = false;
        for(const DiamondSeed &diamond : diamonds) {
          if(!topology.catalogAccepts(
               diamond.cavity.halfEdgeCavity))
            continue;
          CavityStateSignature state;
          const bool cacheable = cavityAttemptState(
            HalfEdgeRewriteKind::DiamondCollapse, phase,
            symmetry, diamond.cavity,
            &fastCadProtectedVertices, state);
          // The same diamond has two distinct collapse transactions. A
          // rejection for one retained pole must not suppress the other.
          if(cacheable) {
            state.push_back(0x4449414d4f4e4400ULL); // "DIAMOND"
            state.push_back(
              static_cast<std::uint64_t>(diamond.retainedInterior));
          }
          if(cacheable &&
             rejectedCavityAttempts.find(state) !=
               rejectedCavityAttempts.end())
            continue;
          const std::size_t retainedNumber =
            diamond.cavity.patch.intVertices[
              diamond.retainedInterior]->getNum();
          const std::size_t boundarySize =
            diamond.cavity.patch.bdrVertices.front().size();
          if(tryDiamond(face, diamond, topology, mandatoryReductionOptions(),
                        result, phase, &fastCadProtectedVertices)) {
            changed = true;
            ++accepted;
            ++result.acceptedDiamonds;
            if(options.verbose)
              Msg::Info("QuadOptimizer: collapsed %sdiamond B=%zu, "
                        "retained vertex=%zu",
                        diamond.boundaryDiamond ? "boundary " : "",
                        boundarySize, retainedNumber);
            break;
          }
          // A direct pole identification fixes the post-collapse
          // connectivity. On a folded or strongly graded patch that single
          // fan can be invalid even though the same disk has a valid I=1
          // quadrangulation. Enumerate the bounded B/I=1 catalog before
          // declaring the diamond irreducible; this is the general diamond
          // operator, not a geometry-specific special case.
          CavitySeed remeshedDiamond = diamond.cavity;
          remeshedDiamond.kind = CavityPurpose::CleanUpConnectivity;
          remeshedDiamond.alwaysTryTopology = true;
          if(tryFlexibleCleanUpCavity(
               face, remeshedDiamond, mandatoryReductionOptions(), result,
               &topology, phase, symmetry, fastCadProtectedVertices, 1,
               diamond.retainedInterior)) {
            changed = true;
            ++accepted;
            ++result.acceptedDiamonds;
            if(options.verbose)
              Msg::Info("QuadOptimizer: remeshed %sdiamond B=%zu I=2->1, "
                        "retained vertex=%zu",
                        diamond.boundaryDiamond ? "boundary " : "",
                        boundarySize, retainedNumber);
            break;
          }
          if(cacheable)
            rejectedCavityAttempts.insert(std::move(state));
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
      [&](CleanUpDecisionPhase phase,
          HalfEdgeRewriteSymmetry symmetry) -> std::size_t {
      if(!options.splitValenceSixVertices) return 0;
      std::size_t accepted = 0;
      while(accepted <
            static_cast<std::size_t>(options.maximumAcceptedCavities)) {
        const std::vector<CavitySeed> valenceSix =
          collectValenceSixCavities(face, topology);
        bool changed = false;
        for(const CavitySeed &cavity : valenceSix) {
          if(!topology.catalogAccepts(cavity.halfEdgeCavity)) continue;
          CavityStateSignature state;
          const bool cacheable = cavityAttemptState(
            HalfEdgeRewriteKind::ValenceSixSplit, phase, symmetry,
            cavity, &fastCadProtectedVertices, state);
          if(cacheable &&
             rejectedCavityAttempts.find(state) !=
               rejectedCavityAttempts.end())
            continue;
          if(tryValenceSixCavity(
               face, cavity, topology, stagedCandidateOptions(), result, phase,
               symmetry)) {
            changed = true;
            ++accepted;
            ++result.acceptedValenceSixSplits;
            if(options.verbose)
              Msg::Info("QuadOptimizer: split valence-six vertex=%zu, "
                        "B=12 I=1->2",
                        cavity.patch.intVertices.front()->getNum());
            break;
          }
          if(cacheable)
            rejectedCavityAttempts.insert(std::move(state));
        }
        if(!changed) break;
      }
      return accepted;
    };

    auto reduceAllInteriorTriangleTriangleQuadStars =
      [&](CleanUpDecisionPhase phase,
          HalfEdgeRewriteSymmetry symmetry) -> std::size_t {
      if(!useFastInteractiveCleanUp(options) ||
         phase != CleanUpDecisionPhase::Any ||
         topology.elementCount(3) < 2 || topology.elementCount(4) < 1)
        return 0;
      std::size_t accepted = 0;
      const std::size_t maximumReductions = topology.elementCount(3) / 2;
      while(accepted < maximumReductions &&
            accepted <
              static_cast<std::size_t>(options.maximumAcceptedCavities)) {
        const std::vector<CavitySeed> cavities =
          collectInteriorTriangleTriangleQuadCavities(face, topology);
        bool changed = false;
        for(const CavitySeed &cavity : cavities) {
          if(!topology.catalogAccepts(cavity.halfEdgeCavity)) continue;
          CavityStateSignature state;
          const bool cacheable = cavityAttemptState(
            HalfEdgeRewriteKind::InteriorTriangleTriangleQuadReduction,
            phase, symmetry, cavity, &fastCadProtectedVertices, state);
          if(cacheable &&
             rejectedCavityAttempts.find(state) !=
               rejectedCavityAttempts.end())
            continue;
          const std::size_t center =
            cavity.patch.intVertices.front()->getNum();
          ++result.interiorTriangleTriangleQuadStarsVisited;
          if(!tryInteriorFourBoundaryFanReduction(
               face, cavity, topology, mandatoryReductionOptions(), result,
               phase,
               &fastCadProtectedVertices, 2, 1)) {
            if(cacheable)
              rejectedCavityAttempts.insert(std::move(state));
            continue;
          }
          changed = true;
          ++accepted;
          ++result.acceptedInteriorTriangleTriangleQuadReductions;
          if(options.verbose)
            Msg::Info("QuadOptimizer CleanUp: accepted interior "
                      "TTQ -> Q star center=%zu B=4 I=1->0", center);
          break;
        }
        if(!changed) break;
      }
      return accepted;
    };

    auto reduceAllInteriorFourTriangleFans =
      [&](CleanUpDecisionPhase phase,
          HalfEdgeRewriteSymmetry symmetry) -> std::size_t {
      if(!useFastInteractiveCleanUp(options) ||
         phase != CleanUpDecisionPhase::Any ||
         topology.elementCount(3) < 4)
        return 0;
      std::size_t accepted = 0;
      const std::size_t maximumReductions = topology.elementCount(3) / 4;
      while(accepted < maximumReductions &&
            accepted <
              static_cast<std::size_t>(options.maximumAcceptedCavities)) {
        const std::vector<CavitySeed> cavities =
          collectInteriorFourTriangleFanCavities(face, topology);
        bool changed = false;
        for(const CavitySeed &cavity : cavities) {
          if(!topology.catalogAccepts(cavity.halfEdgeCavity)) continue;
          CavityStateSignature state;
          const bool cacheable = cavityAttemptState(
            HalfEdgeRewriteKind::InteriorFourTriangleFanReduction,
            phase, symmetry, cavity, &fastCadProtectedVertices, state);
          if(cacheable &&
             rejectedCavityAttempts.find(state) !=
               rejectedCavityAttempts.end())
            continue;
          const std::size_t center =
            cavity.patch.intVertices.front()->getNum();
          ++result.interiorFourTriangleFansVisited;
          if(!tryInteriorFourBoundaryFanReduction(
               face, cavity, topology, stagedCandidateOptions(), result, phase,
               &fastCadProtectedVertices, 4, 0)) {
            if(cacheable)
              rejectedCavityAttempts.insert(std::move(state));
            continue;
          }
          changed = true;
          ++accepted;
          ++result.acceptedInteriorFourTriangleFanReductions;
          if(options.verbose)
            Msg::Info("QuadOptimizer CleanUp: accepted interior "
                      "TTTT -> Q fan center=%zu B=4 I=1->0", center);
          break;
        }
        if(!changed) break;
      }
      return accepted;
    };

    auto reduceAllInteriorAlternatingQuadTriangleStars =
      [&](CleanUpDecisionPhase phase,
          HalfEdgeRewriteSymmetry symmetry) -> std::size_t {
      (void)symmetry;
      if(!useFastInteractiveCleanUp(options) ||
         phase != CleanUpDecisionPhase::Any ||
         topology.elementCount(3) < 2 || topology.elementCount(4) < 2)
        return 0;
      std::size_t accepted = 0;
      const std::size_t maximumReductions = topology.elementCount(3) / 2;
      while(accepted < maximumReductions &&
            accepted <
              static_cast<std::size_t>(options.maximumAcceptedCavities)) {
        const std::vector<CavitySeed> cavities =
          collectInteriorAlternatingQuadTriangleCavities(face, topology);
        bool changed = false;
        for(const CavitySeed &cavity : cavities) {
          if(!topology.catalogAccepts(cavity.halfEdgeCavity)) continue;
          CavityStateSignature state;
          const bool cacheable = cavityAttemptState(
            HalfEdgeRewriteKind::InteriorAlternatingQuadTriangleReduction,
            phase, symmetry, cavity, &fastCadProtectedVertices, state);
          if(cacheable &&
             rejectedCavityAttempts.find(state) !=
               rejectedCavityAttempts.end())
            continue;
          const std::size_t center =
            cavity.patch.intVertices.front()->getNum();
          ++result.interiorAlternatingQuadTriangleStarsVisited;
          if(!tryInteriorAlternatingQuadTriangleReduction(
               face, cavity, topology, stagedCandidateOptions(), result, phase,
               &fastCadProtectedVertices)) {
            if(cacheable)
              rejectedCavityAttempts.insert(std::move(state));
            continue;
          }
          changed = true;
          ++accepted;
          ++result.acceptedInteriorAlternatingQuadTriangleReductions;
          if(options.verbose)
            Msg::Info("QuadOptimizer CleanUp: accepted interior "
                      "Q-T-Q-T -> 2Q star center=%zu B=6 I=1->0",
                      center);
          break;
        }
        if(!changed) break;
      }
      return accepted;
    };

    auto reduceAllInteriorQQTQQTStars =
      [&](CleanUpDecisionPhase phase,
          HalfEdgeRewriteSymmetry symmetry) -> std::size_t {
      if(topology.elementCount(3) < 2 || topology.elementCount(4) < 4)
        return 0;
      std::size_t accepted = 0;
      const std::size_t maximumReductions = topology.elementCount(3) / 2;
      while(accepted < maximumReductions &&
            accepted <
              static_cast<std::size_t>(options.maximumAcceptedCavities)) {
        const std::vector<CavitySeed> cavities =
          collectInteriorQQTQQTCavities(face, topology);
        bool changed = false;
        for(const CavitySeed &cavity : cavities) {
          if(!topology.catalogAccepts(cavity.halfEdgeCavity)) continue;
          CavityStateSignature state;
          const bool cacheable = cavityAttemptState(
            HalfEdgeRewriteKind::InteriorQQTQQTReduction, phase,
            symmetry, cavity, nullptr, state);
          if(cacheable &&
             rejectedCavityAttempts.find(state) !=
               rejectedCavityAttempts.end()) {
            continue;
          }
          const std::size_t center =
            cavity.patch.intVertices.front()->getNum();
          if(!tryInteriorQQTQQTCavity(
               face, cavity, topology, stagedCandidateOptions(), result, phase,
               symmetry)) {
            if(cacheable)
              rejectedCavityAttempts.insert(std::move(state));
            continue;
          }
          changed = true;
          ++accepted;
          ++result.acceptedInteriorQQTQQTReductions;
          if(options.verbose)
            Msg::Info("QuadOptimizer CleanUp: accepted interior "
                      "T-Q-Q-T-Q-Q -> 6Q star center=%zu B=10 I=1->2",
                      center);
          break;
        }
        if(!changed) break;
      }
      return accepted;
    };

    auto optimizeCavityStage =
      [&](CavityPurpose kind, CleanUpDecisionPhase phase,
          HalfEdgeRewriteSymmetry symmetry) -> std::size_t {
      HalfEdgeRewriteKind rewriteKind = HalfEdgeRewriteKind::QuadQuadSwap;
      if(kind == CavityPurpose::Node)
        rewriteKind = HalfEdgeRewriteKind::OneVertexDisk;
      else if(kind == CavityPurpose::Triangle)
        rewriteKind = HalfEdgeRewriteKind::ThreeVertexDisk;
      else if(kind == CavityPurpose::Quadrangle)
        rewriteKind = HalfEdgeRewriteKind::FourVertexDisk;
      const CavityCoreAttemptStateBuilder attemptStateBuilder =
        [&](const HalfEdgeMesh::Cavity &cavity,
            CavityPurpose purpose, CavityStateSignature &state) {
          return halfEdgeCavityAttemptState(
            rewriteKind, phase, symmetry, cavity, purpose,
            &fastCadProtectedVertices, state);
        };
      std::size_t accepted = 0;
      while(accepted <
            static_cast<std::size_t>(options.maximumAcceptedCavities)) {
        const std::vector<CavitySeed> cavities =
          collectCavities(face, options, kind, topology,
                          &attemptStateBuilder,
                          &rejectedCavityAttempts);
        bool changed = false;
        for(const CavitySeed &cavity : cavities) {
          if(!topology.catalogAccepts(cavity.halfEdgeCavity)) continue;
          CavityStateSignature state = cavity.attemptState;
          const bool cacheable = cavity.attemptStateCacheable;
          if(cacheable &&
             rejectedCavityAttempts.find(state) !=
               rejectedCavityAttempts.end()) {
            continue;
          }
          if(tryCavity(face, cavity, topology, stagedCandidateOptions(),
                       result, phase, symmetry,
                       kind == CavityPurpose::Edge ?
                         &removedQuadSwapEdges : nullptr,
                       kind == CavityPurpose::Edge ?
                         &quadSwapTransitions : nullptr,
                       &fastCadProtectedVertices)) {
            changed = true;
            ++accepted;
            switch(kind) {
            case CavityPurpose::Node:
              ++result.acceptedOneInteriorVertexCavities;
              break;
            case CavityPurpose::Edge: ++result.acceptedEdgeSwaps; break;
            case CavityPurpose::Triangle:
              ++result.acceptedThreeInteriorVertexCavities;
              break;
            case CavityPurpose::Quadrangle:
              ++result.acceptedFourInteriorVertexCavities;
              break;
            case CavityPurpose::CleanUpConnectivity:
            case CavityPurpose::CleanUpBoundary:
            case CavityPurpose::CleanUpShape:
            case CavityPurpose::CleanUpSize: break;
            }
            if(options.verbose)
              Msg::Info("QuadOptimizer: accepted cavity B=%zu I=%zu",
                        cavity.patch.bdrVertices.front().size(),
                        cavity.interiorVertexCount);
            break;
          }
          if(cacheable)
            rejectedCavityAttempts.insert(std::move(state));
        }
        if(!changed) break;
      }
      return accepted;
    };

    auto optimizeMixedTriangleQuadSwapStage =
      [&](CleanUpDecisionPhase phase,
          HalfEdgeRewriteSymmetry symmetry) -> std::size_t {
      const bool fast = useFastInteractiveCleanUp(options);
      if(!fast || phase != CleanUpDecisionPhase::Any ||
         topology.elementCount(3) < 1 || topology.elementCount(4) < 1)
        return 0;
      std::size_t accepted = 0;
      while(accepted <
            static_cast<std::size_t>(options.maximumAcceptedCavities)) {
        if(!topology.manifold()) break;
        const std::vector<MixedTriangleQuadSwapSeed> swaps =
          collectMixedTriangleQuadSwaps(face, topology, options);
        bool changed = false;
        for(const MixedTriangleQuadSwapSeed &swap : swaps) {
          if(!topology.catalogAccepts(swap.halfEdgeCavity)) continue;
          CavityStateSignature state;
          const bool cacheable = halfEdgeCavityAttemptState(
            HalfEdgeRewriteKind::MixedTriangleQuadSwap, phase,
            symmetry, swap.halfEdgeCavity,
            CavityPurpose::Edge, &fastCadProtectedVertices, state);
          if(cacheable &&
             rejectedCavityAttempts.find(state) !=
               rejectedCavityAttempts.end())
            continue;
          if(!trySmoothedMixedTriangleQuadSwap(
               face, swap, topology, stagedCandidateOptions(), result, phase,
               fastCadProtectedVertices)) {
            if(cacheable)
              rejectedCavityAttempts.insert(std::move(state));
            continue;
          }
          changed = true;
          ++accepted;
          ++result.acceptedEdgeSwaps;
          if(options.verbose)
            Msg::Info("QuadOptimizer CleanUp: accepted mixed T+Q "
                      "pentagon swap B=5");
          // The committed half-edge transaction has already updated the
          // persistent topology before the next adjacent pair is visited.
          break;
        }
        if(!changed) break;
      }
      return accepted;
    };

    auto optimizeTriangleTriangleSwapStage =
      [&](CleanUpDecisionPhase phase,
          HalfEdgeRewriteSymmetry symmetry) -> std::size_t {
      if(!useFastInteractiveCleanUp(options) ||
         phase != CleanUpDecisionPhase::Any ||
         topology.elementCount(3) < 2)
        return 0;
      // A four-vertex disk has a single alternative diagonal; rotations and
      // reflections name the same transaction. Keep the symmetry in the
      // descriptor, while evaluating that one canonical half-edge action.
      (void)symmetry;
      std::size_t accepted = 0;
      while(accepted <
            static_cast<std::size_t>(options.maximumAcceptedCavities)) {
        if(!topology.manifold()) break;
        const std::vector<TriangleTriangleSwapSeed> swaps =
          collectTriangleTriangleSwaps(face, topology);
        bool changed = false;
        for(const TriangleTriangleSwapSeed &swap : swaps) {
          if(!topology.catalogAccepts(swap.halfEdgeCavity)) continue;
          CavityStateSignature state;
          const bool cacheable = halfEdgeCavityAttemptState(
            HalfEdgeRewriteKind::TriangleTriangleSwap, phase, symmetry,
            swap.halfEdgeCavity, CavityPurpose::Edge,
            &fastCadProtectedVertices, state);
          if(cacheable &&
             rejectedCavityAttempts.find(state) !=
               rejectedCavityAttempts.end())
            continue;
          ++result.triangleTriangleSwapsVisited;
          if(!tryTriangleTriangleSwap(
               face, swap, topology, stagedCandidateOptions(), result,
               fastCadProtectedVertices)) {
            if(cacheable)
              rejectedCavityAttempts.insert(std::move(state));
            continue;
          }
          changed = true;
          ++accepted;
          ++result.acceptedTriangleTriangleSwaps;
          break;
        }
        if(!changed) break;
      }
      return accepted;
    };

    auto optimizeTriangleQuadStripReductionStage =
      [&](CleanUpDecisionPhase phase,
          HalfEdgeRewriteSymmetry symmetry) -> std::size_t {
      if(!useFastInteractiveCleanUp(options) ||
         phase != CleanUpDecisionPhase::Any ||
         topology.elementCount(3) < 2)
        return 0;
      std::size_t accepted = 0;
      const std::size_t maximumReductions = topology.elementCount(3) / 2;
      while(accepted < maximumReductions &&
            accepted <
              static_cast<std::size_t>(options.maximumAcceptedCavities)) {
        if(!topology.manifold()) break;
        const std::vector<TriangleQuadStripReductionSeed> reductions =
          collectTriangleQuadStripReductions(face, topology, 4);
        bool changed = false;
        for(const TriangleQuadStripReductionSeed &reduction : reductions) {
          // A boundary T-Q-Q-T has its dedicated QQQQ rewrite with one new
          // boundary-star center. Do not let the earlier generic strip rule
          // consume it as a three-quad zipper before that rule is reached.
          if(options.stagedTopologyThenQuality &&
             stagedFastPhase == StagedFastPhase::Topology &&
             reduction.boundaryFan && reduction.quadrangleCount == 2)
            continue;
          if(options.stagedTopologyThenQuality &&
             stagedFastPhase == StagedFastPhase::Quality)
            continue;
          if(!topology.catalogAccepts(
               reduction.cavity.halfEdgeCavity))
            continue;
          CavityStateSignature state;
          const bool cacheable = cavityAttemptState(
            HalfEdgeRewriteKind::TriangleQuadStripReduction, phase,
            symmetry, reduction.cavity, &fastCadProtectedVertices, state);
          if(cacheable &&
             rejectedCavityAttempts.find(state) !=
               rejectedCavityAttempts.end()) {
            continue;
          }
          if(!tryTriangleQuadStripReduction(
               face, reduction, topology, mandatoryReductionOptions(), result,
               phase,
               fastCadProtectedVertices,
               activeStripDiagnostics)) {
            if(cacheable)
              rejectedCavityAttempts.insert(std::move(state));
            continue;
          }
          changed = true;
          ++accepted;
          ++result.acceptedQuadTwoTriangleReductions;
          if(options.verbose)
            Msg::Info("QuadOptimizer CleanUp: accepted T-Q^%zu-T -> "
                      "%zuQ strip reduction B=%zu",
                      reduction.quadrangleCount,
                      reduction.quadrangleCount + 1,
                      reduction.cavity.patch.bdrVertices.front().size());
          break;
        }
        if(!changed) break;
      }
      return accepted;
    };

    auto optimizeCleanUpStage = [&](CavityPurpose kind, bool enabled,
                                    bool criticalShapeOnly,
                                    CleanUpDecisionPhase phase,
                                    HalfEdgeRewriteSymmetry symmetry)
      -> std::size_t {
      if(!enabled) return 0;
      if(!topology.manifold()) {
        Msg::Warning("QuadOptimizer CleanUp: skipping a non-manifold GFace");
        return 0;
      }
      HalfEdgeRewriteKind rewriteKind =
        HalfEdgeRewriteKind::ConnectivityDisk;
      if(kind == CavityPurpose::CleanUpBoundary)
        rewriteKind = HalfEdgeRewriteKind::BoundaryDisk;
      else if(kind == CavityPurpose::CleanUpShape)
        rewriteKind = HalfEdgeRewriteKind::ShapeDisk;
      else if(kind == CavityPurpose::CleanUpSize)
        rewriteKind = HalfEdgeRewriteKind::SizeDisk;
      const CavityCoreAttemptStateBuilder attemptStateBuilder =
        [&](const HalfEdgeMesh::Cavity &cavity,
            CavityPurpose purpose, CavityStateSignature &state) {
          return halfEdgeCavityAttemptState(
            rewriteKind, phase, symmetry, cavity, purpose,
            &fastCadProtectedVertices, state);
        };
      std::size_t accepted = 0;
      while(accepted <
            static_cast<std::size_t>(options.maximumAcceptedCavities)) {
        const std::vector<CavitySeed> cavities =
          collectCleanUpCavities(face, options, kind, topology,
                                 criticalShapeOnly, nullptr,
                                 &attemptStateBuilder,
                                 &rejectedCavityAttempts);
        std::set<MVertex *> reservedVertices;
        std::size_t acceptedInWave = 0;
        for(const CavitySeed &cavity : cavities) {
          if(!topology.catalogAccepts(cavity.halfEdgeCavity)) continue;
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
          CavityStateSignature state = cavity.attemptState;
          const bool cacheable = cavity.attemptStateCacheable;
          if(cacheable &&
             rejectedCavityAttempts.find(state) !=
               rejectedCavityAttempts.end()) {
            continue;
          }
          if(!tryFlexibleCleanUpCavity(
                                       face, cavity,
                                       stagedCandidateOptions(), result,
                                       &topology, phase,
                                       symmetry,
                                       fastCadProtectedVertices)) {
            if(cacheable)
              rejectedCavityAttempts.insert(std::move(state));
            continue;
          }
          reservedVertices.insert(cavityVertices.begin(),
                                  cavityVertices.end());
          ++acceptedInWave;
          ++accepted;
          switch(kind) {
          case CavityPurpose::CleanUpConnectivity:
            ++result.cleanUpConnectivityAccepted;
            break;
          case CavityPurpose::CleanUpBoundary:
            ++result.cleanUpBoundaryAccepted;
            break;
          case CavityPurpose::CleanUpShape:
            ++result.cleanUpShapeAccepted;
            break;
          case CavityPurpose::CleanUpSize:
            ++result.cleanUpSizeAccepted;
            break;
          case CavityPurpose::Node:
          case CavityPurpose::Edge:
          case CavityPurpose::Triangle:
          case CavityPurpose::Quadrangle: break;
          }
          if(options.verbose)
            Msg::Info("QuadOptimizer CleanUp: accepted %s cavity B=%zu "
                      "I=%zu elements=%zu",
                      kind == CavityPurpose::CleanUpConnectivity ? "connectivity" :
                      kind == CavityPurpose::CleanUpBoundary ? "boundary" :
                      kind == CavityPurpose::CleanUpShape ? "shape" : "size",
                      cavity.patch.bdrVertices.front().size(),
                      cavity.interiorVertexCount,
                      cavity.patch.elements.size());
        }
        if(acceptedInWave == 0) break;
        if(useFastInteractiveCleanUp(options)) break;
      }
      return accepted;
    };

    auto timedCleanUpStage = [&](CavityPurpose kind, bool enabled,
                                 bool criticalShapeOnly,
                                 double &seconds,
                                 CleanUpDecisionPhase phase,
                                 HalfEdgeRewriteSymmetry symmetry)
      -> std::size_t {
      const auto start = std::chrono::steady_clock::now();
      const std::size_t accepted = optimizeCleanUpStage(
        kind, enabled, criticalShapeOnly, phase, symmetry);
      seconds += std::chrono::duration<double>(
        std::chrono::steady_clock::now() - start).count();
      return accepted;
    };

    auto smoothOpposedQuadStars = [&]
      (CleanUpDecisionPhase phase,
       HalfEdgeRewriteSymmetry symmetry) -> std::size_t {
      if(!useFastInteractiveCleanUp(options) ||
         face->geomType() != GEntity::DiscreteSurface ||
         !topology.manifold())
        return 0;
      std::size_t accepted = 0;
      while(accepted <
            static_cast<std::size_t>(options.maximumAcceptedCavities)) {
        const std::vector<CavitySeed> cavities =
          collectOpposedQuadStarSmoothingCavities(
            face, options, topology);
        bool changed = false;
        for(CavitySeed cavity : cavities) {
          if(!topology.catalogAccepts(cavity.halfEdgeCavity)) continue;
          CavityStateSignature state;
          const bool cacheable = cavityAttemptState(
            HalfEdgeRewriteKind::OpposedQuadStarSmoothing, phase,
            symmetry, cavity, &fastCadProtectedVertices, state);
          if(cacheable &&
             rejectedCavityAttempts.find(state) !=
               rejectedCavityAttempts.end())
            continue;
          ++result.cavitiesVisited;
          const ExistingSmoothingStatus status = smoothExistingCavity(
            face, cavity, options, true, nullptr, false);
          if(status == ExistingSmoothingStatus::RejectedWinslow)
            ++result.rejectedByWinslow;
          else if(status == ExistingSmoothingStatus::RejectedSize)
            ++result.rejectedBySize;
          else if(status == ExistingSmoothingStatus::RejectedQuality)
            ++result.rejectedByQuality;
          if(status != ExistingSmoothingStatus::Accepted) {
            if(cacheable)
              rejectedCavityAttempts.insert(std::move(state));
            continue;
          }
          if(!topology.synchronizeGeometry(cavity.patch.intVertices)) {
            // An algorithmically admissible state that changes no XYZ bit is
            // not a rewrite. Remember it like any other unchanged attempt so
            // it cannot manufacture progress or force a fresh catalog scan.
            if(cacheable)
              rejectedCavityAttempts.insert(std::move(state));
            continue;
          }
          ++result.acceptedFinalSmoothingCavities;
          ++accepted;
          changed = true;
          if(options.verbose)
            Msg::Info("QuadOptimizer: corrected an opposed quad with mixed "
                      "star Winslow B=%zu I=%zu elements=%zu",
                      cavity.patch.bdrVertices.front().size(),
                      cavity.patch.intVertices.size(),
                      cavity.patch.elements.size());
          // Geometry changed, so rebuild both the normal samples and the
          // deterministic cavity order before selecting another residual.
          break;
        }
        if(!changed) break;
      }
      return accepted;
    };

    using HalfEdgeRewriteExecutor = std::function<std::size_t(
      CleanUpDecisionPhase, const HalfEdgeRewriteDescriptor &)>;
    struct ExecutableHalfEdgeRewrite {
      const HalfEdgeRewriteDescriptor *descriptor = nullptr;
      HalfEdgeRewriteExecutor execute;
    };
    std::vector<ExecutableHalfEdgeRewrite> executableCatalog;
    executableCatalog.reserve(halfEdgeRewriteCatalog().size());
    std::vector<double> rewriteSeconds(
      halfEdgeRewriteCatalog().size(), 0.);
    double globalSmoothingSeconds = 0.;
    auto appendRewrite = [&](HalfEdgeRewriteKind expected,
                             HalfEdgeRewriteExecutor execute) {
      const std::size_t index = executableCatalog.size();
      const auto &descriptors = halfEdgeRewriteCatalog();
      if(index >= descriptors.size() || descriptors[index].kind != expected) {
        result.success = false;
        Msg::Warning("QuadOptimizer: executable half-edge catalog does not "
                     "match its descriptor table on face %d",
                     face->tag());
        return;
      }
      executableCatalog.push_back({&descriptors[index],
                                   std::move(execute)});
    };

    appendRewrite(
      HalfEdgeRewriteKind::InteriorTriangleTriangleQuadReduction,
      [&](CleanUpDecisionPhase phase,
          const HalfEdgeRewriteDescriptor &rule) {
        return reduceAllInteriorTriangleTriangleQuadStars(
          phase, rule.symmetry);
      });
    appendRewrite(HalfEdgeRewriteKind::InteriorFourTriangleFanReduction,
      [&](CleanUpDecisionPhase phase,
          const HalfEdgeRewriteDescriptor &rule) {
        return reduceAllInteriorFourTriangleFans(phase, rule.symmetry);
      });
    appendRewrite(
      HalfEdgeRewriteKind::InteriorAlternatingQuadTriangleReduction,
      [&](CleanUpDecisionPhase phase,
          const HalfEdgeRewriteDescriptor &rule) {
        return reduceAllInteriorAlternatingQuadTriangleStars(
          phase, rule.symmetry);
      });
    appendRewrite(HalfEdgeRewriteKind::InteriorQQTQQTReduction,
      [&](CleanUpDecisionPhase phase,
          const HalfEdgeRewriteDescriptor &rule) {
        return reduceAllInteriorQQTQQTStars(phase, rule.symmetry);
      });
    appendRewrite(HalfEdgeRewriteKind::TriangleTriangleSwap,
      [&](CleanUpDecisionPhase phase,
          const HalfEdgeRewriteDescriptor &rule) {
        return optimizeTriangleTriangleSwapStage(phase, rule.symmetry);
      });
    appendRewrite(HalfEdgeRewriteKind::TriangleQuadStripReduction,
      [&](CleanUpDecisionPhase phase,
          const HalfEdgeRewriteDescriptor &rule) {
        return optimizeTriangleQuadStripReductionStage(
          phase, rule.symmetry);
      });
    appendRewrite(HalfEdgeRewriteKind::OppositeEdgeTriangleQuadSwap,
      [&](CleanUpDecisionPhase phase,
          const HalfEdgeRewriteDescriptor &rule) {
        return optimizeOppositeEdgeTriangleQuadSwapStage(
          phase, rule.symmetry);
      });
    appendRewrite(HalfEdgeRewriteKind::OppositeEdgeTriangleQuadFan,
      [&](CleanUpDecisionPhase phase,
          const HalfEdgeRewriteDescriptor &rule) {
        return convertAllOppositeEdgeTriangleQuadFans(
          phase, rule.symmetry);
      });
    appendRewrite(HalfEdgeRewriteKind::MixedTriangleQuadSwap,
      [&](CleanUpDecisionPhase phase,
          const HalfEdgeRewriteDescriptor &rule) {
        return optimizeMixedTriangleQuadSwapStage(phase, rule.symmetry);
      });
    appendRewrite(HalfEdgeRewriteKind::QuadQuadSwap,
      [&](CleanUpDecisionPhase phase,
          const HalfEdgeRewriteDescriptor &rule) {
        return optimizeCavityStage(
          CavityPurpose::Edge, phase, rule.symmetry);
      });
    appendRewrite(HalfEdgeRewriteKind::ValenceSixSplit,
      [&](CleanUpDecisionPhase phase,
          const HalfEdgeRewriteDescriptor &rule) {
        return options.splitValenceSixVertices ?
          splitAllValenceSixVertices(phase, rule.symmetry) : 0;
      });
    appendRewrite(HalfEdgeRewriteKind::ConnectivityDisk,
      [&](CleanUpDecisionPhase phase,
          const HalfEdgeRewriteDescriptor &rule) {
        return timedCleanUpStage(
          CavityPurpose::CleanUpConnectivity, options.cleanUpConnectivity,
          false, result.cleanUpConnectivitySeconds, phase, rule.symmetry);
      });
    appendRewrite(HalfEdgeRewriteKind::OneVertexDisk,
      [&](CleanUpDecisionPhase phase,
          const HalfEdgeRewriteDescriptor &rule) {
        return options.optimizeOneInteriorVertexCavities ?
          optimizeCavityStage(CavityPurpose::Node, phase, rule.symmetry) : 0;
      });
    appendRewrite(HalfEdgeRewriteKind::DiamondCollapse,
      [&](CleanUpDecisionPhase phase,
          const HalfEdgeRewriteDescriptor &rule) {
        return options.eliminateDiamonds ?
          eliminateAllDiamonds(phase, rule.symmetry) : 0;
      });
    appendRewrite(HalfEdgeRewriteKind::BoundaryDisk,
      [&](CleanUpDecisionPhase phase,
          const HalfEdgeRewriteDescriptor &rule) {
        return timedCleanUpStage(
          CavityPurpose::CleanUpBoundary, options.cleanUpBoundary, false,
          result.cleanUpBoundarySeconds, phase, rule.symmetry);
      });
    appendRewrite(HalfEdgeRewriteKind::BoundaryTriangleQuadFan,
      [&](CleanUpDecisionPhase phase,
          const HalfEdgeRewriteDescriptor &rule) {
        return options.convertBoundaryTriangleQuadTriangleFans ?
          convertAllBoundaryTriangleQuadTriangleFans(
            phase, rule.symmetry) : 0;
      });
    appendRewrite(HalfEdgeRewriteKind::ThreeVertexDisk,
      [&](CleanUpDecisionPhase phase,
          const HalfEdgeRewriteDescriptor &rule) {
        return options.optimizeThreeInteriorVertexCavities ?
          optimizeCavityStage(CavityPurpose::Triangle, phase, rule.symmetry) : 0;
      });
    appendRewrite(HalfEdgeRewriteKind::FourVertexDisk,
      [&](CleanUpDecisionPhase phase,
          const HalfEdgeRewriteDescriptor &rule) {
        return options.optimizeFourInteriorVertexCavities ?
          optimizeCavityStage(
            CavityPurpose::Quadrangle, phase, rule.symmetry) : 0;
      });
    appendRewrite(HalfEdgeRewriteKind::ShapeDisk,
      [&](CleanUpDecisionPhase phase,
          const HalfEdgeRewriteDescriptor &rule) {
        return timedCleanUpStage(
          CavityPurpose::CleanUpShape, options.cleanUpShape, false,
          result.cleanUpShapeSeconds, phase, rule.symmetry);
      });
    appendRewrite(HalfEdgeRewriteKind::SizeDisk,
      [&](CleanUpDecisionPhase phase,
          const HalfEdgeRewriteDescriptor &rule) {
        return timedCleanUpStage(
          CavityPurpose::CleanUpSize, options.cleanUpSize, false,
          result.cleanUpSizeSeconds, phase, rule.symmetry);
      });
    appendRewrite(HalfEdgeRewriteKind::PillowHole,
      [&](CleanUpDecisionPhase, const HalfEdgeRewriteDescriptor &) {
        if(options.pillowNeighborLayers <= 0) return std::size_t(0);
        const std::size_t acceptedBefore = result.pillowHolesAccepted;
        pillowFaceHoles(face, options, result, topology);
        return result.pillowHolesAccepted - acceptedBefore;
      });
    appendRewrite(HalfEdgeRewriteKind::OpposedQuadStarSmoothing,
      [&](CleanUpDecisionPhase phase,
          const HalfEdgeRewriteDescriptor &rule) {
        return smoothOpposedQuadStars(phase, rule.symmetry);
      });
    appendRewrite(HalfEdgeRewriteKind::InvalidQuadSplit,
      [&](CleanUpDecisionPhase phase,
          const HalfEdgeRewriteDescriptor &rule) {
        return splitInvalidQuadrangles(phase, rule.symmetry);
      });
    appendRewrite(HalfEdgeRewriteKind::TerminalTrianglePairRecombination,
      [&](CleanUpDecisionPhase phase,
          const HalfEdgeRewriteDescriptor &rule) {
        return recombineTerminalTrianglePairs(phase, rule.symmetry);
      });
    appendRewrite(HalfEdgeRewriteKind::CatastrophicAngleQuadSplit,
      [&](CleanUpDecisionPhase, const HalfEdgeRewriteDescriptor &) {
        return splitCatastrophicAngleQuadrangles();
      });

    auto applyCatalogRewrite = [&]
      (const ExecutableHalfEdgeRewrite &rewrite,
       CleanUpDecisionPhase phase) -> std::size_t {
      if(!rewrite.descriptor || !rewrite.execute) return 0;
      if(!topology.beginCatalogRewrite(*rewrite.descriptor)) {
        result.success = false;
        Msg::Warning("QuadOptimizer: could not begin the cavity-anchor "
                     "contract for rule %s on face %d",
                     rewrite.descriptor->id, face->tag());
        return 0;
      }
      const auto start = std::chrono::steady_clock::now();
      const std::size_t accepted =
        rewrite.execute(phase, *rewrite.descriptor);
      const auto &descriptors = halfEdgeRewriteCatalog();
      const std::ptrdiff_t position =
        rewrite.descriptor - descriptors.data();
      if(position >= 0 &&
         static_cast<std::size_t>(position) < rewriteSeconds.size())
        rewriteSeconds[static_cast<std::size_t>(position)] +=
          std::chrono::duration<double>(
            std::chrono::steady_clock::now() - start).count();
      if(!topology.finishCatalogRewrite(accepted != 0)) {
        result.success = false;
        Msg::Warning("QuadOptimizer: rule %s submitted a cavity that does "
                     "not match its declared anchor on face %d",
                     rewrite.descriptor->id, face->tag());
      }
      return accepted;
    };

    auto runCatalogSchedule = [&]
      (HalfEdgeRewriteSchedule schedule, CleanUpDecisionPhase phase,
       std::size_t &acceptedDuringSchedule) -> bool {
      acceptedDuringSchedule = 0;
      for(const ExecutableHalfEdgeRewrite &executable :
          executableCatalog) {
        const HalfEdgeRewriteDescriptor &rewrite = *executable.descriptor;
        if(rewrite.schedule != schedule) continue;
        const std::size_t accepted = applyCatalogRewrite(executable, phase);
        acceptedDuringSchedule += accepted;
        if(options.verbose > 1 && accepted)
          Msg::Info("QuadOptimizer half-edge rule %s accepted=%zu",
                    rewrite.id, accepted);
        if(!result.success || !topology.manifold()) {
          result.success = false;
          return false;
        }
      }
      return true;
    };

    bool catalogReachedFixedPoint = false;
    auto runCleanUpPasses = [&](CleanUpDecisionPhase phase,
                                std::size_t &acceptedDuringRun) {
      catalogReachedFixedPoint = false;
      acceptedDuringRun = 0;
      for(int pass = 0; pass < options.maximumOptimizationPasses; ++pass) {
        // A later pass supersedes the evolving topology seen by the previous
        // one. Keeping only this pass makes the eventual report describe the
        // actual residual fixed point instead of historical candidates.
        if(activeStripDiagnostics) activeStripDiagnostics->clear();
        ++result.passes;
        std::size_t topologyChanges = 0;
        if(!runCatalogSchedule(HalfEdgeRewriteSchedule::CleanUp, phase,
                               topologyChanges))
          return false;

        acceptedDuringRun += topologyChanges;
        if(topologyChanges == 0) {
          catalogReachedFixedPoint = true;
          break;
        }
      }
      return result.success;
    };

    auto runDecisionHierarchy = [&](std::size_t *acceptedDuringHierarchy) {
      if(acceptedDuringHierarchy) *acceptedDuringHierarchy = 0;
      std::size_t accepted = 0;
      const bool success =
        runCleanUpPasses(CleanUpDecisionPhase::Any, accepted);
      if(acceptedDuringHierarchy) *acceptedDuringHierarchy = accepted;
      return success;
    };

    bool lastSmoothingReachedFixedPoint = false;
    auto smoothFastOrLegacyOnce = [&](int forcedPasses = -1) {
      const auto start = std::chrono::steady_clock::now();
      SmallCavityOptimizerOptions smoothingOptions = options;
      // Mixed Winslow is part of the Fast optimizer's acceptance contract,
      // including when the caller set the legacy Mesh.Smoothing knob to
      // zero.  Keep one bounded pass in that case; non-Fast callers retain
      // the historical opt-out semantics.
      smoothingOptions.smoothingPasses = forcedPasses >= 0 ?
        forcedPasses :
        (useFastInteractiveCleanUp(options) ?
           std::max(1, options.finalSmoothingPasses) :
           options.finalSmoothingPasses);
      smoothingOptions.topologyOnlyIfCavityHasSpecificationFailure = false;
      // A face-wide sweep contains one overlapping star solve per movable
      // vertex.  Give each star the same converged-but-bounded Fast budget
      // as a transactional C+C' candidate; the legacy optimizer retains its
      // caller-provided nonlinear limits.
      if(useFastInteractiveCleanUp(options)) {
        smoothingOptions.winslow.maxInnerIterations = std::min(
          smoothingOptions.winslow.maxInnerIterations, 40);
        smoothingOptions.winslow.maxOuterIterations = std::min(
          smoothingOptions.winslow.maxOuterIterations, 2);
        smoothingOptions.winslow.maxLineSearchSteps = std::min(
          smoothingOptions.winslow.maxLineSearchSteps, 20);
        smoothingOptions.winslow.gradientTolerance = std::max(
          smoothingOptions.winslow.gradientTolerance, 1.e-7);
      }
      const ExistingTopologyWinslowResult smoothing =
        smoothAllInteriorVertexCavities(
          face, smoothingOptions, topology, &fastCadProtectedVertices,
          true);
      lastSmoothingReachedFixedPoint = smoothing.reachedFixedPoint;
      globalSmoothingSeconds += std::chrono::duration<double>(
        std::chrono::steady_clock::now() - start).count();
      if(!smoothing.success) {
        result.success = false;
        return false;
      }
      result.acceptedFinalSmoothingCavities += smoothing.acceptedCavities;
      result.rejectedByWinslow += smoothing.rejectedByWinslow;
      result.rejectedBySize += smoothing.rejectedBySize;
      result.rejectedByQuality += smoothing.rejectedByQuality;
      if(options.verbose)
        Msg::Info("QuadOptimizer: mixed mean-plane Winslow passes=%zu "
                  "accepted=%zu",
                  smoothing.passes, smoothing.acceptedCavities);
      return true;
    };

    // A T+Q or simultaneous opposite-edge T-Q-T swap can expose a
    // T-Q^k-T strip after the strip descriptor has already run in the main
    // catalog order. Run exactly two bounded swap passes before the final
    // all-quad retry; every individual transaction still performs its own
    // one-ring Winslow solve before acceptance.
    auto runTwoTriangleSwapPasses = [&]() {
      std::size_t accepted = 0;
      for(std::size_t pass = 0; pass < 2; ++pass) {
        for(const ExecutableHalfEdgeRewrite &executable :
            executableCatalog) {
          const HalfEdgeRewriteDescriptor &rewrite = *executable.descriptor;
          if(rewrite.kind != HalfEdgeRewriteKind::TriangleTriangleSwap &&
             rewrite.kind != HalfEdgeRewriteKind::MixedTriangleQuadSwap &&
             rewrite.kind !=
               HalfEdgeRewriteKind::OppositeEdgeTriangleQuadSwap)
            continue;
          const std::size_t changes = applyCatalogRewrite(
            executable, CleanUpDecisionPhase::Any);
          accepted += changes;
          if(options.verbose > 1 && changes)
            Msg::Info("QuadOptimizer final swap pass %zu rule %s "
                      "accepted=%zu",
                      pass + 1, rewrite.id, changes);
          if(!result.success || !topology.manifold()) {
            result.success = false;
            return false;
          }
        }
      }
      if(options.verbose)
        Msg::Info("QuadOptimizer: final two triangle-swap passes "
                  "accepted=%zu",
                  accepted);
      return true;
    };

    // Final acyclic retry: use the same single half-edge catalog as the main
    // cleanup, but retain every rule that strictly removes triangles and
    // never creates one. TriangleQuadStripReduction includes k=0 (T+T -> Q)
    // as well as T-Q^k-T. Iterate because a later boundary/terminal reduction
    // can expose an earlier catalog rule. Termination follows directly from
    // the strict decrease in the number of triangles.
    auto retryQuadReductions = [&]() {
      const std::size_t initialTriangles = topology.elementCount(3);
      const std::size_t maximumCycles = initialTriangles / 2 + 1;
      std::size_t accepted = 0;
      for(std::size_t cycle = 0; cycle < maximumCycles; ++cycle) {
        const std::size_t trianglesBefore = topology.elementCount(3);
        std::size_t acceptedThisCycle = 0;
        for(const ExecutableHalfEdgeRewrite &executable :
            executableCatalog) {
          const HalfEdgeRewriteDescriptor &rewrite = *executable.descriptor;
          if(rewrite.kind !=
               HalfEdgeRewriteKind::InteriorTriangleTriangleQuadReduction &&
             rewrite.kind !=
               HalfEdgeRewriteKind::InteriorFourTriangleFanReduction &&
             rewrite.kind !=
               HalfEdgeRewriteKind::InteriorAlternatingQuadTriangleReduction &&
             rewrite.kind !=
               HalfEdgeRewriteKind::InteriorQQTQQTReduction &&
             rewrite.kind !=
               HalfEdgeRewriteKind::TriangleQuadStripReduction &&
             rewrite.kind !=
               HalfEdgeRewriteKind::OppositeEdgeTriangleQuadFan &&
             rewrite.kind !=
               HalfEdgeRewriteKind::BoundaryTriangleQuadFan &&
             rewrite.kind !=
               HalfEdgeRewriteKind::TerminalTrianglePairRecombination)
            continue;
          const std::size_t changes = applyCatalogRewrite(
            executable, CleanUpDecisionPhase::Any);
          acceptedThisCycle += changes;
          if(options.verbose > 1 && changes)
            Msg::Info("QuadOptimizer final quad retry cycle %zu rule %s "
                      "accepted=%zu",
                      cycle + 1, rewrite.id, changes);
          if(!result.success || !topology.manifold()) {
            result.success = false;
            return false;
          }
        }
        accepted += acceptedThisCycle;
        if(acceptedThisCycle == 0) break;
        const std::size_t trianglesAfter = topology.elementCount(3);
        if(trianglesAfter >= trianglesBefore) {
          Msg::Warning("QuadOptimizer: stopping the final all-quad retry on "
                       "face %d because its triangle count did not decrease",
                       face->tag());
          break;
        }
      }
      if(options.verbose)
        Msg::Info("QuadOptimizer: final all-quad retry accepted=%zu",
                  accepted);
      return true;
    };

    // A terminal topology is closed only if a fresh, history-independent
    // scan of the complete cleanup and terminal catalogs accepts nothing
    // after the most recent Winslow batch. Winslow can keep accepting
    // vanishingly small coordinate changes after topology has stabilized;
    // those do not invalidate the topological closure certificate.
    // Reset the reversible-quad transition guards before each fresh scan:
    // they prevent oscillation within one scan, but must not make the answer
    // depend on whether the same mesh was saved and reloaded. Every accepted
    // transaction remains individually monotone and the outer iteration is
    // bounded defensively.
    auto closeCompleteCatalog = [&](const char *stage) {
      constexpr std::size_t maximumCompleteClosureRounds = 12;
      bool topologyClosed = false;
      for(std::size_t round = 0; round < maximumCompleteClosureRounds;
          ++round) {
        ++quadSwapGuardEpoch;
        fastCadProtectedVertices.clear();
        removedQuadSwapEdges.clear();
        quadSwapTransitions.clear();

        const std::size_t smoothingBefore =
          result.acceptedFinalSmoothingCavities;
        if(!smoothFastOrLegacyOnce(2)) return false;
        const bool geometryChanged =
          result.acceptedFinalSmoothingCavities != smoothingBefore;
        std::size_t cleanupChanges = 0;
        if(!runDecisionHierarchy(&cleanupChanges)) return false;
        std::size_t terminalChanges = 0;
        if(useFastInteractiveCleanUp(options) &&
           !runCatalogSchedule(HalfEdgeRewriteSchedule::Terminal,
                               CleanUpDecisionPhase::Any,
                               terminalChanges))
          return false;
        if(options.verbose > 1 &&
           (geometryChanged || cleanupChanges || terminalChanges))
          Msg::Info("QuadOptimizer %s complete closure round %zu: "
                    "geometry=%d cleanup=%zu terminal=%zu",
                    stage, round + 1, geometryChanged ? 1 : 0,
                    cleanupChanges, terminalChanges);
        topologyClosed = cleanupChanges == 0 && terminalChanges == 0;
        // A literally idle geometry/catalog round is an exact joint fixed
        // point. Otherwise retain the bounded Winslow continuation: a later
        // batch can expose a propagation swap even though the present scan
        // was idle. The final scan still certifies the returned topology.
        if((!geometryChanged || lastSmoothingReachedFixedPoint) &&
           topologyClosed) {
          break;
        }
      }
      if(!topologyClosed)
        Msg::Warning("QuadOptimizer: %s complete catalog closure reached "
                     "its budget on face %d immediately after a topology "
                     "change; the result is valid but not certified as a "
                     "topological fixed point",
                     stage, face->tag());
      return true;
    };

    const auto stagedTopologyRule = [](HalfEdgeRewriteKind kind) {
      switch(kind) {
      case HalfEdgeRewriteKind::InteriorTriangleTriangleQuadReduction:
      case HalfEdgeRewriteKind::InteriorFourTriangleFanReduction:
      case HalfEdgeRewriteKind::InteriorAlternatingQuadTriangleReduction:
      case HalfEdgeRewriteKind::InteriorQQTQQTReduction:
      case HalfEdgeRewriteKind::TriangleQuadStripReduction:
      case HalfEdgeRewriteKind::OppositeEdgeTriangleQuadFan:
      case HalfEdgeRewriteKind::ValenceSixSplit:
      case HalfEdgeRewriteKind::ConnectivityDisk:
      case HalfEdgeRewriteKind::OneVertexDisk:
      case HalfEdgeRewriteKind::DiamondCollapse:
      case HalfEdgeRewriteKind::BoundaryDisk:
      case HalfEdgeRewriteKind::BoundaryTriangleQuadFan:
      case HalfEdgeRewriteKind::InvalidQuadSplit:
      case HalfEdgeRewriteKind::TerminalTrianglePairRecombination:
        return true;
      default: return false;
      }
    };
    const auto stagedQualityRule = [](HalfEdgeRewriteKind kind) {
      switch(kind) {
      case HalfEdgeRewriteKind::TriangleTriangleSwap:
      case HalfEdgeRewriteKind::OppositeEdgeTriangleQuadSwap:
      case HalfEdgeRewriteKind::MixedTriangleQuadSwap:
      case HalfEdgeRewriteKind::QuadQuadSwap:
        return true;
      default: return false;
      }
    };
    auto runStagedFastPhase = [&]
      (StagedFastPhase stage,
       const std::function<bool(HalfEdgeRewriteKind)> &selected,
       const char *label) {
      stagedFastPhase = stage;
      constexpr std::size_t maximumRounds = 12;
      std::size_t acceptedTotal = 0;
      for(std::size_t round = 0; round < maximumRounds; ++round) {
        ++result.passes;
        std::size_t acceptedThisRound = 0;
        for(const ExecutableHalfEdgeRewrite &executable : executableCatalog) {
          if(!executable.descriptor ||
             !selected(executable.descriptor->kind))
            continue;
          const std::size_t accepted = applyCatalogRewrite(
            executable, CleanUpDecisionPhase::Any);
          acceptedThisRound += accepted;
          if(!result.success || !topology.manifold()) {
            result.success = false;
            return false;
          }
        }
        acceptedTotal += acceptedThisRound;
        if(acceptedThisRound == 0) break;
      }
      if(options.verbose)
        Msg::Info("OptimizeQuadsFast staged %s: accepted=%zu",
                  label, acceptedTotal);
      return true;
    };

    if(options.stagedTopologyThenQuality) {
      // Phase 1 contains the direct structural reductions, including every
      // T-Q^k-T -> Q^(k+1) merge (k=0 is T+T -> Q), diamond collapse,
      // valence repair and mandatory validity splitting. These acyclic
      // reductions are accepted before the final global smoothing whenever
      // their replacement is topologically valid, oriented and non-concave.
      if(!runStagedFastPhase(
           StagedFastPhase::Topology, stagedTopologyRule, "topology"))
        return result;
      ++quadSwapGuardEpoch;
      removedQuadSwapEdges.clear();
      quadSwapTransitions.clear();
      if(!runStagedFastPhase(
           StagedFastPhase::Quality, stagedQualityRule,
           "unsmoothed-quality"))
        return result;
      stagedFastPhase = StagedFastPhase::None;
      // No topology rule is run after this point. Smooth the topology that
      // the two preceding fixed-point scans selected. Smoothing changes the
      // geometry against which QQ/QT/TT swaps are judged and can expose a
      // strongly flattened quad even though the same connectivity was at a
      // quality fixed point before the move. Re-scan only the geometry-
      // preserving quality rules afterwards; their transactions do not move
      // vertices, so no second smoothing batch is needed.
      if(!smoothFastOrLegacyOnce(8)) return result;
      ++quadSwapGuardEpoch;
      removedQuadSwapEdges.clear();
      quadSwapTransitions.clear();
      if(!runStagedFastPhase(
           StagedFastPhase::Quality, stagedQualityRule,
           "post-smoothing-quality"))
        return result;
      stagedFastPhase = StagedFastPhase::None;
    }
    else if(options.finalPatternClosureOnly) {
      if(!closeCompleteCatalog("PACK final")) return result;
    }
    else {
      // Candidate de-duplication is local to one immutable cavity state. A
      // face-wide connectivity tabu is incorrect here: an overlapping
      // Winslow transaction changes the geometry against which the same
      // connectivity must be judged, and element renumbering after MSH
      // reload can change which seed inserts the tabu first. With the
      // additive one-sided decision potential, rebuilding the seeds after
      // each commit and stopping on a complete idle hierarchy is both the
      // Put the input topology in its locally optimized mixed T/Q geometry
      // before comparing it with any replacement topology. This also makes
      // triangles participate in the first, rather than only the final,
      // Winslow batch.
      if((useFastInteractiveCleanUp(options) ||
          options.finalSmoothingPasses > 0) &&
         !smoothFastOrLegacyOnce())
        return result;
      if(!runDecisionHierarchy(nullptr)) return result;

      std::size_t postProcessChanges = 0;
      if(!runCatalogSchedule(HalfEdgeRewriteSchedule::PostProcess,
                             CleanUpDecisionPhase::Any,
                             postProcessChanges))
        return result;
    // A pillow inserts a complete quad ring and can expose any of the same
    // local rewrite configurations as the original mesh. Close the common
    // catalog on the updated graph instead of maintaining a pillow-specific
    // follow-up path.
      if(postProcessChanges && !runDecisionHierarchy(nullptr)) {
        return result;
      }
      if(options.finalSmoothingPasses > 0) {
      // Topology and geometry are coupled. Iterate the same complete
      // half-edge catalog after each Winslow batch until both are idle;
      // otherwise a smoothing move can expose a published configuration that
      // would silently survive the final mesh.
      constexpr std::size_t maximumClosureRounds = 8;
      bool closed = false;
      for(std::size_t round = 0; round < maximumClosureRounds; ++round) {
        const bool catalogWasAtFixedPoint = catalogReachedFixedPoint;
        const std::size_t acceptedSmoothingBefore =
          result.acceptedFinalSmoothingCavities;
        if(!smoothFastOrLegacyOnce()) return result;
        const bool smoothingChangedGeometry =
          result.acceptedFinalSmoothingCavities !=
          acceptedSmoothingBefore;
        // If the preceding hierarchy ended on an actual zero-change pass
        // and Winslow did not move a vertex, both topology and geometry are
        // byte-for-byte the state that was already scanned. Re-running all
        // catalog collectors here cannot expose a new cavity.
        if(catalogWasAtFixedPoint && !smoothingChangedGeometry) {
          closed = true;
          break;
        }
        std::size_t topologyChanges = 0;
        if(!runDecisionHierarchy(&topologyChanges)) return result;
        if(topologyChanges == 0) {
          closed = true;
          break;
        }
      }
      if(!closed) {
        if(!smoothFastOrLegacyOnce()) return result;
        // The current half-edge state is still manifold and every committed
        // transaction was individually admissible. Reaching the bounded
        // interactive budget is therefore a convergence warning, not a mesh
        // generation failure: keep the last valid state and continue with
        // the remaining faces.
        Msg::Warning("QuadOptimizer: half-edge rewrite/smoothing catalog "
                     "reached its closure budget on face %d; keeping the "
                     "last valid state",
                     face->tag());
      }
      }
      if(useFastInteractiveCleanUp(options)) {
      // Terminal validity splitting and residual T+T recombination are rules
      // in the same catalog. Alternate that terminal schedule with the
      // complete cleanup schedule: a split can expose Q+T+T, while a merge
      // can expose a neighboring swap. The next terminal sweep is also the
      // absolute validity audit of every quad created in the preceding one.
      constexpr std::size_t maximumTerminalClosureRounds = 8;
      bool terminalClosed = false;
      for(std::size_t round = 0; round < maximumTerminalClosureRounds;
          ++round) {
        std::size_t terminalChanges = 0;
        if(!runCatalogSchedule(HalfEdgeRewriteSchedule::Terminal,
                               CleanUpDecisionPhase::Any,
                               terminalChanges))
          return result;
        std::size_t cleanupChanges = 0;
        if(terminalChanges && !runDecisionHierarchy(&cleanupChanges))
          return result;
        if(terminalChanges == 0 && cleanupChanges == 0) {
          terminalClosed = true;
          break;
        }
      }
      if(!terminalClosed) {
        Msg::Warning("OptimizeQuadsFast: terminal half-edge catalog reached "
                     "its closure budget on face %d; keeping the last "
                     "valid state",
                     face->tag());
      }

      // This is deliberately a one-shot topology fallback. It can introduce
      // triangles to remove residual catastrophic-angle quad defects; the
      // bounded mixed Winslow/swap and all-quad retry below ensure that those
      // triangles are neither returned with raw split geometry nor left
      // untested for an admissible recombination.
      std::size_t finalFallbackChanges = 0;
      if(!runCatalogSchedule(HalfEdgeRewriteSchedule::FinalFallback,
                             CleanUpDecisionPhase::Any,
                             finalFallbackChanges))
        return result;
      // Whether triangles came from the original mesh, the terminal validity
      // split or the catastrophic fallback, give the final mixed topology
      // exactly two Winslow sweeps and two targeted TT/TQ swap passes, then
      // retry every acyclic all-quad reduction in catalog order. Each
      // candidate is still evaluated after its own transactional one-ring
      // smoothing and must pass absolute quality, size and CAD non-regression
      // guards.
      if(topology.elementCount(3) > 0) {
        if(!smoothFastOrLegacyOnce(2)) return result;
        if(!runTwoTriangleSwapPasses()) return result;
        if(!retryQuadReductions()) return result;
      }
      // The fallback and its all-quad reductions can expose any earlier
      // swap, boundary fan or connectivity disk. Finish with the complete
      // catalog, not with the acyclic subset that happened to run last.
      if(!closeCompleteCatalog("final")) return result;
      }
    }
    if(activeStripDiagnostics)
      printTriangleQuadStripDiagnostics(face, stripDiagnostics);
    const std::vector<MElement *> finalElements = surfaceElements(face);
    const std::vector<MElement *> finalTopologyElements = topology.elements();
    const std::set<MElement *, std::less<MElement *> > topologyElements(
      finalTopologyElements.begin(), finalTopologyElements.end());
    const std::set<MElement *, std::less<MElement *> > faceElements(
      finalElements.begin(), finalElements.end());
    if(!topology.manifold() ||
       topologyElements != faceElements) {
      result.success = false;
      Msg::Error("QuadOptimizer: optimization produced an invalid surface "
                 "cell complex on face %d", face->tag());
    }
    result.finalObjective = specificationObjective(finalElements);
    if(options.enforceSizeMap)
      setFinalSizeStatistics(result, faceSizeScore(face, options));
    if(options.verbose && useFastInteractiveCleanUp(options))
      Msg::Info("QuadOptimizer CleanUp timings face=%d: "
                "connectivity=%.6gs boundary=%.6gs shape=%.6gs size=%.6gs "
                "globalWinslow=%.6gs",
                face->tag(), result.cleanUpConnectivitySeconds,
                result.cleanUpBoundarySeconds, result.cleanUpShapeSeconds,
                result.cleanUpSizeSeconds, globalSmoothingSeconds);
    if(options.verbose > 1 && useFastInteractiveCleanUp(options)) {
      Msg::Info("QuadOptimizer candidate profile face=%d: optimized=%zu "
                "rejectedWinslow=%zu edgeIntersection=%zu edgeConvex=%zu",
                face->tag(), result.topologyCandidatesOptimized,
                result.rejectedByWinslow,
                result.rejectedEdgeSwapsNoIntersection,
                result.rejectedEdgeSwapsNonConvex);
      const auto &descriptors = halfEdgeRewriteCatalog();
      for(std::size_t i = 0; i < rewriteSeconds.size(); ++i)
        if(rewriteSeconds[i] > 1.e-6)
          Msg::Info("QuadOptimizer rule timing face=%d rule=%s time=%.6gs",
                    face->tag(), descriptors[i].id, rewriteSeconds[i]);
    }
    if(options.verbose > 1 && initialPackNormalAtlas.face == face)
      Msg::Info("QuadOptimizer initial PACK normal atlas face=%d: "
                "cells=%zu queries=%zu certifiedPositive=%zu "
                "certifiedNegative=%zu fallback=%zu",
                face->tag(), initialPackNormalAtlas.cells.size(),
                initialPackNormalAtlas.queries,
                initialPackNormalAtlas.certifiedPositive,
                initialPackNormalAtlas.certifiedNegative,
                initialPackNormalAtlas.fallbacks);
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
    const FaceHalfEdgeTopology topology(surfaceElements(face));
    if(!topology.manifold()) {
      result.success = false;
      Msg::Warning("QuadOptimizer: refusing to smooth a non-manifold "
                   "surface cell complex on face %d", face->tag());
      return result;
    }
    result.initialObjective = specificationObjective(topology.elements());
    for(int pass = 0; pass < options.smoothingPasses; ++pass) {
      ++result.passes;

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
          if(topology.synchronizeGeometry(seed.patch.intVertices))
            ++result.acceptedCavities;
          break;
        case ExistingSmoothingStatus::Invalid: break;
        }
      };

      for(MElement *element : topology.elements()) {
        MQuadrangle *quadrangle = dynamic_cast<MQuadrangle *>(element);
        if(!quadrangle) continue;
        ++result.quadsVisited;
        CavitySeed core;
        if(!fourInteriorVertexCavity(face, quadrangle, topology, core))
          continue;
        const std::vector<MVertex *> boundary =
          core.patch.bdrVertices.front();
        smooth(core);
        for(MVertex *vertex : boundary) {
          CavitySeed neighbor;
          if(interiorVertexCavity(
               face, {vertex}, topology, neighbor, true, false))
            smooth(neighbor);
        }
      }
    }
    result.finalObjective = specificationObjective(topology.elements());
    if(options.invalidateVertexArrays) face->model()->deleteVertexArrays();
    return result;
  }

  ExistingTopologyWinslowResult smoothExistingQuadCavities(
    int faceTag, const SmallCavityOptimizerOptions &options)
  {
    return smoothExistingQuadCavities(
      GModel::current()->getFaceByTag(faceTag), options);
  }

  bool isRegularOrientedSurfaceCellComplex(GFace *face)
  {
    if(!face) return false;
    const std::vector<MElement *> elements = surfaceElements(face);
    if(elements.empty()) return true;
    const SurfaceOrientationRepairResult structure =
      repairSurfaceElementOrientation(face, elements, false, false);
    return structure.structurallyRegular && structure.orientable &&
      FaceHalfEdgeTopology(elements).manifold();
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
    std::vector<std::exception_ptr> faceExceptions(faces.size());
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
      GFace *sampleFace = nullptr;
      MVertex *sampleVertex = nullptr;
      for(GFace *face : faces) {
        for(MQuadrangle *quadrangle : face->quadrangles) {
          if(!quadrangle) continue;
          for(std::size_t i = 0; i < 4; ++i) {
            MVertex *vertex = quadrangle->getVertex(static_cast<int>(i));
            if(!vertex) continue;
            sampleFace = face;
            sampleVertex = vertex;
            break;
          }
          if(sampleVertex) break;
        }
        if(sampleVertex) break;
      }
      UV uv;
      if(sampleFace && sampleVertex &&
         vertexParameter(sampleFace, sampleVertex, uv)) {
        const Point xyz = {sampleVertex->x(), sampleVertex->y(),
                           sampleVertex->z()};
        (void)prescribedTargetSize(sampleFace, uv, xyz, options);
      }
    }
    SmallCavityOptimizerOptions parallelOptions = options;
    parallelOptions.invalidateVertexArrays = false;
    // Keep normal face-parallel cleanup (-v5, internal level 1) quiet. An
    // explicit diagnostic request (-v6 and above) deliberately propagates to
    // the single-face workers so their compact per-signature summaries are
    // reachable from the command line.
    parallelOptions.verbose = options.verbose > 1 ? options.verbose : 0;

#if defined(_OPENMP)
    const int threads = maximumThreads > 0 ? maximumThreads : omp_get_max_threads();
#pragma omp parallel for schedule(dynamic) num_threads(threads)
#endif
    for(std::ptrdiff_t i = 0;
        i < static_cast<std::ptrdiff_t>(faces.size()); ++i) {
      FaceOptimizerResult faceResult;
      faceResult.faceTag = faces[static_cast<std::size_t>(i)]->tag();
      try {
        faceResult.optimizer = optimizeSmallQuadCavities(
          faces[static_cast<std::size_t>(i)], parallelOptions);
      }
      catch(...) {
        faceResult.optimizer.success = false;
        faceExceptions[static_cast<std::size_t>(i)] =
          std::current_exception();
      }
      result.faces[static_cast<std::size_t>(i)] = std::move(faceResult);
    }

    for(const FaceOptimizerResult &face : result.faces) {
      if(face.optimizer.skippedInvalidInputCellComplex)
        ++result.facesSkippedInvalidInputCellComplex;
      result.acceptedPillows += face.optimizer.pillowHolesAccepted;
      result.pillowHolesVisited += face.optimizer.pillowHolesVisited;
      result.pillowHolesAlreadyPresent +=
        face.optimizer.pillowHolesAlreadyPresent;
      result.insertedPillowQuadrangles +=
        face.optimizer.pillowQuadranglesInserted;
      result.acceptedEdgeSwaps += face.optimizer.acceptedEdgeSwaps;
      result.acceptedDiamonds += face.optimizer.acceptedDiamonds;
      result.acceptedQuadTwoTriangleReductions +=
        face.optimizer.acceptedQuadTwoTriangleReductions;
      result.acceptedOppositeEdgeTriangleQuadSwaps +=
        face.optimizer.acceptedOppositeEdgeTriangleQuadSwaps;
      result.acceptedOppositeEdgeTriangleQuadFans +=
        face.optimizer.acceptedOppositeEdgeTriangleQuadFans;
      result.acceptedInteriorTriangleTriangleQuadReductions +=
        face.optimizer.acceptedInteriorTriangleTriangleQuadReductions;
      result.acceptedInteriorFourTriangleFanReductions +=
        face.optimizer.acceptedInteriorFourTriangleFanReductions;
      result.acceptedInteriorAlternatingQuadTriangleReductions +=
        face.optimizer.acceptedInteriorAlternatingQuadTriangleReductions;
      result.acceptedInteriorQQTQQTReductions +=
        face.optimizer.acceptedInteriorQQTQQTReductions;
      result.acceptedBoundaryTriangleQuadTriangleFans +=
        face.optimizer.acceptedBoundaryTriangleQuadTriangleFans;
      result.triangleTriangleSwapsVisited +=
        face.optimizer.triangleTriangleSwapsVisited;
      result.acceptedTriangleTriangleSwaps +=
        face.optimizer.acceptedTriangleTriangleSwaps;
      result.acceptedGeometryDrivenTriangleTriangleSwaps +=
        face.optimizer.acceptedGeometryDrivenTriangleTriangleSwaps;
      result.acceptedGeometryDrivenMixedTriangleQuadSwaps +=
        face.optimizer.acceptedGeometryDrivenMixedTriangleQuadSwaps;
      result.acceptedSmoothingCavities +=
        face.optimizer.acceptedFinalSmoothingCavities;
      result.rejectedByWinslow += face.optimizer.rejectedByWinslow;
      result.rejectedBySize += face.optimizer.rejectedBySize;
      result.rejectedByQuality += face.optimizer.rejectedByQuality;
      result.reorientedElements += face.optimizer.reorientedElements;
      result.excessiveWarpingQuadrangles +=
        face.optimizer.excessiveWarpingQuadrangles;
      result.nonConvexOrInvalidQuadrangles +=
        face.optimizer.nonConvexOrInvalidQuadrangles;
      result.warpedQuadranglesSplit +=
        face.optimizer.warpedQuadranglesSplit;
      result.warpedQuadranglesRejected +=
        face.optimizer.warpedQuadranglesRejected;
      result.catastrophicAngleQuadranglesSelectedForSplit +=
        face.optimizer.catastrophicAngleQuadranglesSelectedForSplit;
      result.catastrophicAngleQuadranglesSplit +=
        face.optimizer.catastrophicAngleQuadranglesSplit;
      result.catastrophicAngleQuadranglesRejectedBySize +=
        face.optimizer.catastrophicAngleQuadranglesRejectedBySize;
      result.catastrophicAngleQuadranglesRejectedByGeometry +=
        face.optimizer.catastrophicAngleQuadranglesRejectedByGeometry;
      result.catastrophicAngleQuadranglesRejectedOther +=
        face.optimizer.catastrophicAngleQuadranglesRejectedOther;
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
        face.optimizer.acceptedTriangleTriangleSwaps +
        face.optimizer.acceptedQuadTwoTriangleReductions +
        face.optimizer.acceptedOppositeEdgeTriangleQuadFans +
        face.optimizer.acceptedInteriorTriangleTriangleQuadReductions +
        face.optimizer.acceptedInteriorFourTriangleFanReductions +
        face.optimizer.acceptedInteriorAlternatingQuadTriangleReductions +
        face.optimizer.acceptedInteriorQQTQQTReductions +
        face.optimizer.acceptedValenceSixSplits +
        face.optimizer.acceptedBoundaryTriangleQuadTriangleFans +
        (face.optimizer.acceptedEdgeSwaps -
         face.optimizer.acceptedCleanUpEdgeSwaps) +
        face.optimizer.acceptedOneInteriorVertexCavities +
        face.optimizer.acceptedThreeInteriorVertexCavities +
        face.optimizer.acceptedFourInteriorVertexCavities +
        face.optimizer.terminalTrianglePairsAccepted +
        face.optimizer.catastrophicAngleQuadranglesSplit +
        face.optimizer.cleanUpConnectivityAccepted +
        face.optimizer.cleanUpBoundaryAccepted +
        face.optimizer.cleanUpShapeAccepted +
        face.optimizer.cleanUpSizeAccepted;
      result.initialObjective += face.optimizer.initialObjective;
      result.finalObjective += face.optimizer.finalObjective;
    }
    model->deleteVertexArrays();
    // Msg::Error can throw when the API keeps General.AbortOnError at its
    // default value. Never let that exception escape an OpenMP worker (which
    // would call std::terminate); rethrow it on the caller thread only after
    // every face has left the parallel region and model caches are clean.
    for(const std::exception_ptr &exception : faceExceptions)
      if(exception) std::rethrow_exception(exception);
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

      // The quality report is also run after a malformed input face has been
      // deliberately skipped by the optimizer. Do not feed null/repeated
      // vertices or invalid incidences to geometric evaluators: record the
      // complete face as invalid and continue auditing the other faces.
      const SurfaceOrientationRepairResult readable =
        repairSurfaceElementOrientation(face, elements, false, false);
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
        std::vector<Point> xyz(4);
        for(std::size_t i = 0; i < 4; ++i) {
          MVertex *vertex = quadrangle->getVertex(static_cast<int>(i));
          xyz[i] = {vertex->x(), vertex->y(), vertex->z()};
        }
        const Pattern singleQuadrangle = {{{0, 1, 2, 3}}};
        const double eta = quadrangle->etaShapeMeasure();
        const double sicn = quadrangle->minSICNShapeMeasure();
        const bool validQuadrangle = quality.topologicallyValid &&
          candidateQuadranglesArePhysicallyNonConcave(
            singleQuadrangle, xyz) &&
          std::isfinite(sicn) && sicn > 0. &&
          std::isfinite(eta) && eta > 0. &&
          surfaceElementCadNormalSign(
            face, quadrangle, &parameters) != -1;
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
