// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.

#include "intrinsicTriangulation.h"
#include "GFace.h"
#include "GEdge.h"
#include "GModel.h"
#include "MTriangle.h"
#include "MLine.h"
#include "meshGFaceTri3.h"
#include "Context.h"
#include "GmshMessage.h"
#include "OS.h"
#include "robustPredicates.h"
#include "BackgroundMesh.h"
#include "Numeric.h"
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <limits>
#include <map>
#include <memory>
#include <new>
#include <queue>
#include <set>

namespace QuadOptimizer {
  static bool existingMeshDataIndex(MVertex *vertex, const bidimMeshData &data,
                                    std::size_t &index)
  {
    if(!vertex || !vertex->onWhat()) return false;
    if(vertex->onWhat()->dim() == 2) {
      const long int rawIndex = vertex->getIndex();
      if(rawIndex < 0) return false;
      index = static_cast<std::size_t>(rawIndex);
    }
    else {
      const auto found = data.indices.find(vertex);
      if(found == data.indices.end() || found->second < 0) return false;
      index = static_cast<std::size_t>(found->second);
    }
    return true;
  }

  static double orientationUV(MVertex *a, MVertex *b, MVertex *c,
                              const bidimMeshData &data)
  {
    std::size_t ia = 0, ib = 0, ic = 0;
    if(!existingMeshDataIndex(a, data, ia) ||
       !existingMeshDataIndex(b, data, ib) ||
       !existingMeshDataIndex(c, data, ic) || ia >= data.Us.size() ||
       ib >= data.Us.size() || ic >= data.Us.size() || ia >= data.Vs.size() ||
       ib >= data.Vs.size() || ic >= data.Vs.size())
      return std::numeric_limits<double>::quiet_NaN();
    double pa[2] = {data.Us[ia], data.Vs[ia]};
    double pb[2] = {data.Us[ib], data.Vs[ib]};
    double pc[2] = {data.Us[ic], data.Vs[ic]};
    return robustPredicates::orient2d(pa, pb, pc);
  }

  static bool validTriangleUV(MTriangle *triangle, bidimMeshData &data,
                              double &orientation)
  {
    if(!triangle) return false;
    MVertex *vertices[3] = {triangle->getVertex(0), triangle->getVertex(1),
                            triangle->getVertex(2)};
    if(!vertices[0] || !vertices[1] || !vertices[2] ||
       vertices[0] == vertices[1] || vertices[1] == vertices[2] ||
       vertices[2] == vertices[0])
      return false;
    for(int i = 0; i < 3; ++i) {
      std::size_t index = 0;
      if(!existingMeshDataIndex(vertices[i], data, index) ||
         index >= data.Us.size() || index >= data.Vs.size())
        return false;
    }
    orientation = orientationUV(vertices[0], vertices[1], vertices[2], data);
    return std::isfinite(orientation) && orientation != 0.;
  }

  static double intrinsicAngle(double adjacent0, double adjacent1,
                               double opposite)
  {
    const double denominator = 2. * adjacent0 * adjacent1;
    if(denominator <= std::numeric_limits<double>::min()) return 0.;
    double cosine =
      (adjacent0 * adjacent0 + adjacent1 * adjacent1 - opposite * opposite) /
      denominator;
    cosine = std::max(-1., std::min(1., cosine));
    return std::acos(cosine);
  }

  static double unfoldedDiagonal(double ab, double ac, double bc, double ad,
                                 double bd)
  {
    if(ab <= std::numeric_limits<double>::min()) return -1.;
    const double xc = (ac * ac + ab * ab - bc * bc) / (2. * ab);
    const double xd = (ad * ad + ab * ab - bd * bd) / (2. * ab);
    const double yc2 = ac * ac - xc * xc;
    const double yd2 = ad * ad - xd * xd;
    const double scale = std::max({ab, ac, bc, ad, bd, 1.});
    const double tolerance = 1.e-12 * scale * scale;
    if(yc2 < -tolerance || yd2 < -tolerance) return -1.;
    const double yc = std::sqrt(std::max(0., yc2));
    const double yd = std::sqrt(std::max(0., yd2));
    return std::hypot(xc - xd, yc + yd);
  }

  static void orientTriangleUV(MTriangle *triangle, MVertex *a, MVertex *b,
                               MVertex *c, double referenceOrientation,
                               bidimMeshData &data)
  {
    triangle->setVertex(0, a);
    triangle->setVertex(1, b);
    triangle->setVertex(2, c);
    const double orientation = orientationUV(a, b, c, data);
    if(std::isfinite(orientation) && orientation != 0. &&
       ((referenceOrientation < 0.) != (orientation < 0.))) {
      triangle->setVertex(1, c);
      triangle->setVertex(2, b);
    }
  }

  // Persistent half-edge topology used by the intrinsic triangulation. The
  // former implementation rebuilt an edge-to-triangle map, rescanned every edge
  // and copied the complete triangle vector after each local split. On a large
  // packed face this made a local operation effectively O(number of triangles).
  // Here twins, faces and intrinsic edge lengths remain valid across O(1) flips
  // and splits; only a deterministic Lawson front and a lazy long-edge heap are
  // updated.
  class IntrinsicTriHalfEdgeMesh {
  public:
    using Id = std::uint32_t;

  private:
    static Id invalidId() { return std::numeric_limits<Id>::max(); }

    struct HalfEdge {
      MVertex *origin = nullptr;
      Id next = invalidId();
      Id previous = invalidId();
      Id twin = invalidId();
      Id face = invalidId();
      Id edge = invalidId();
    };

    struct Face {
      MTriangle *triangle = nullptr;
      Id halfEdge = invalidId();
    };

    struct Edge {
      Id halfEdge = invalidId();
      double intrinsicLength = 0.;
      std::uint64_t revision = 0;
    };

    struct SplitGeometry {
      double u = 0.;
      double v = 0.;
      double localSize = 0.;
      GPoint point;
    };

    struct LongEdgeCandidate {
      double ratio = 0.;
      std::size_t lowVertex = 0;
      std::size_t highVertex = 0;
      Id edge = invalidId();
      std::uint64_t revision = 0;
    };

    struct LongEdgeCandidateLess {
      bool operator()(const LongEdgeCandidate &a,
                      const LongEdgeCandidate &b) const
      {
        if(a.ratio != b.ratio) return a.ratio < b.ratio;
        if(a.lowVertex != b.lowVertex) return a.lowVertex > b.lowVertex;
        if(a.highVertex != b.highVertex) return a.highVertex > b.highVertex;
        return a.edge > b.edge;
      }
    };

    GFace *_gf;
    bidimMeshData &_data;
    std::vector<HalfEdge> _halfEdges;
    std::vector<Face> _faces;
    std::vector<Edge> _edges;
    std::map<MEdge, Id, MEdgeLessThan> _edgeIndex;
    std::priority_queue<LongEdgeCandidate, std::vector<LongEdgeCandidate>,
                        LongEdgeCandidateLess>
      _longEdges;
    bool _valid = true;
    bool _longEdgesReady = false;

    MVertex *destination(Id halfEdge) const
    {
      return _halfEdges[_halfEdges[halfEdge].next].origin;
    }

    MEdge halfEdgeKey(Id halfEdge) const
    {
      return MEdge(_halfEdges[halfEdge].origin, destination(halfEdge));
    }

    MEdge edgeKey(Id edge) const { return halfEdgeKey(_edges[edge].halfEdge); }

    void topologyFailure(const char *reason)
    {
      if(_valid)
        Msg::Warning("- Face %d: intrinsic half-edge topology is not an "
                     "oriented manifold (%s)",
                     _gf->tag(), reason);
      _valid = false;
    }

    Id appendFace(MTriangle *triangle)
    {
      if(_faces.size() >= static_cast<std::size_t>(invalidId())) {
        topologyFailure("too many faces");
        return invalidId();
      }
      Face face;
      face.triangle = triangle;
      _faces.push_back(face);
      return static_cast<Id>(_faces.size() - 1);
    }

    Id appendHalfEdge(MVertex *origin)
    {
      if(_halfEdges.size() >= static_cast<std::size_t>(invalidId())) {
        topologyFailure("too many half-edges");
        return invalidId();
      }
      HalfEdge halfEdge;
      halfEdge.origin = origin;
      _halfEdges.push_back(halfEdge);
      return static_cast<Id>(_halfEdges.size() - 1);
    }

    Id appendEdge(Id halfEdge, double intrinsicLength)
    {
      if(_edges.size() >= static_cast<std::size_t>(invalidId())) {
        topologyFailure("too many edges");
        return invalidId();
      }
      Edge edge;
      edge.halfEdge = halfEdge;
      edge.intrinsicLength = intrinsicLength;
      _edges.push_back(edge);
      return static_cast<Id>(_edges.size() - 1);
    }

    void linkFace(Id face, Id h0, Id h1, Id h2)
    {
      _halfEdges[h0].next = h1;
      _halfEdges[h1].next = h2;
      _halfEdges[h2].next = h0;
      _halfEdges[h0].previous = h2;
      _halfEdges[h1].previous = h0;
      _halfEdges[h2].previous = h1;
      _halfEdges[h0].face = face;
      _halfEdges[h1].face = face;
      _halfEdges[h2].face = face;
      _faces[face].halfEdge = h0;
      MTriangle *triangle = _faces[face].triangle;
      triangle->setVertex(0, _halfEdges[h0].origin);
      triangle->setVertex(1, _halfEdges[h1].origin);
      triangle->setVertex(2, _halfEdges[h2].origin);
    }

    void attachInitialEdge(Id halfEdge,
                           std::set<std::pair<Id, Id>> &adjacentFacePairs)
    {
      const MEdge key = halfEdgeKey(halfEdge);
      auto found = _edgeIndex.find(key);
      if(found == _edgeIndex.end()) {
        const Id edge = appendEdge(halfEdge, key.length());
        if(edge == invalidId()) return;
        _halfEdges[halfEdge].edge = edge;
        _edgeIndex.emplace(key, edge);
        return;
      }

      const Id edge = found->second;
      const Id other = _edges[edge].halfEdge;
      if(_halfEdges[other].twin != invalidId()) {
        topologyFailure("edge with more than two incident triangles");
        return;
      }
      if(_halfEdges[other].origin != destination(halfEdge) ||
         destination(other) != _halfEdges[halfEdge].origin) {
        topologyFailure("two incident triangles have the same orientation");
        return;
      }
      const Id face = _halfEdges[halfEdge].face;
      const Id otherFace = _halfEdges[other].face;
      if(face == otherFace) {
        topologyFailure("a triangle is adjacent to itself");
        return;
      }
      const std::pair<Id, Id> facePair = std::minmax(face, otherFace);
      if(!adjacentFacePairs.insert(facePair).second) {
        topologyFailure("two triangles share more than one edge");
        return;
      }
      _halfEdges[other].twin = halfEdge;
      _halfEdges[halfEdge].twin = other;
      _halfEdges[halfEdge].edge = edge;
    }

    void build()
    {
      // This set is only a construction-time guard. Face adjacencies change
      // during flips and splits, so retaining it as persistent state would make
      // it stale after the first edit and would waste one tree node per
      // interior edge for the remainder of the run.
      std::set<std::pair<Id, Id>> adjacentFacePairs;
      _faces.reserve(_gf->triangles.size());
      _halfEdges.reserve(3 * _gf->triangles.size());
      _edges.reserve(3 * _gf->triangles.size() / 2 + 1);
      for(MTriangle *triangle : _gf->triangles) {
        MVertex *v0 = triangle->getVertex(0);
        MVertex *v1 = triangle->getVertex(1);
        MVertex *v2 = triangle->getVertex(2);
        if(!v0 || !v1 || !v2 || v0 == v1 || v1 == v2 || v2 == v0) {
          topologyFailure("triangle with repeated vertices");
          return;
        }
        const Id face = appendFace(triangle);
        const Id h0 = appendHalfEdge(v0);
        const Id h1 = appendHalfEdge(v1);
        const Id h2 = appendHalfEdge(v2);
        if(!_valid) return;
        linkFace(face, h0, h1, h2);
        attachInitialEdge(h0, adjacentFacePairs);
        attachInitialEdge(h1, adjacentFacePairs);
        attachInitialEdge(h2, adjacentFacePairs);
        if(!_valid) return;
      }
    }

    bool isInteriorUnconstrained(Id edge) const
    {
      if(!_valid || edge >= _edges.size()) return false;
      const Id halfEdge = _edges[edge].halfEdge;
      if(halfEdge >= _halfEdges.size()) return false;
      const Id twin = _halfEdges[halfEdge].twin;
      if(twin == invalidId() || twin >= _halfEdges.size() ||
         _halfEdges[twin].twin != halfEdge)
        return false;
      return _data.internalEdges.find(edgeKey(edge)) ==
             _data.internalEdges.end();
    }

    bool splitRatio(Id edge, double &ratio, SplitGeometry *geometry)
    {
      ratio = 0.;
      if(!isInteriorUnconstrained(edge)) return false;
      const Edge &intrinsicEdge = _edges[edge];
      if(!(intrinsicEdge.intrinsicLength > 0.) ||
         !std::isfinite(intrinsicEdge.intrinsicLength))
        return false;

      const MEdge key = edgeKey(edge);
      MVertex *a = key.getVertex(0);
      MVertex *b = key.getVertex(1);
      if(!a || !b || a == _data.equivalent(b) || b == _data.equivalent(a))
        return false;
      std::size_t ia = 0, ib = 0;
      if(!existingMeshDataIndex(a, _data, ia) ||
         !existingMeshDataIndex(b, _data, ib) || ia >= _data.Us.size() ||
         ib >= _data.Us.size() || ia >= _data.Vs.size() ||
         ib >= _data.Vs.size() || ia >= _data.vSizes.size() ||
         ib >= _data.vSizes.size())
        return false;

      const double u = .5 * _data.Us[ia] + .5 * _data.Us[ib];
      const double v = .5 * _data.Vs[ia] + .5 * _data.Vs[ib];
      if(!std::isfinite(u) || !std::isfinite(v)) return false;
      double localSize = CTX::instance()->mesh.packTargetSize;
      GPoint point;
      const bool needPoint = geometry || !(localSize > 0.);
      if(needPoint) {
        point = _gf->point(u, v);
        if(!point.succeeded() || !std::isfinite(point.x()) ||
           !std::isfinite(point.y()) || !std::isfinite(point.z()))
          return false;
      }
      if(!(localSize > 0.))
        localSize = BGM_MeshSize(_gf, u, v, point.x(), point.y(), point.z());
      if(!(localSize > 0.) || !std::isfinite(localSize)) return false;

      const double intrinsicFactor =
        CTX::instance()->mesh.packIntrinsicEdgeLengthFactor;
      if(!(intrinsicFactor > 0.) || !std::isfinite(intrinsicFactor))
        return false;
      double maximumLength = intrinsicFactor * localSize;
      const double hardMaximum =
        CTX::instance()->mesh.optimizeQuadsMaximumEdgeLength;
      if(hardMaximum > 0.) maximumLength = std::min(maximumLength, hardMaximum);
      if(!(maximumLength > 0.) || !std::isfinite(maximumLength)) return false;
      ratio = intrinsicEdge.intrinsicLength / maximumLength;
      if(!std::isfinite(ratio)) return false;
      if(geometry) {
        geometry->u = u;
        geometry->v = v;
        geometry->localSize = localSize;
        geometry->point = point;
      }
      return true;
    }

    void refreshLongEdge(Id edge)
    {
      if(edge >= _edges.size()) return;
      Edge &intrinsicEdge = _edges[edge];
      ++intrinsicEdge.revision;
      if(!_longEdgesReady) return;
      double ratio = 0.;
      if(!splitRatio(edge, ratio, nullptr) || !(ratio > 1.)) return;
      const MEdge key = edgeKey(edge);
      LongEdgeCandidate candidate;
      candidate.ratio = ratio;
      candidate.lowVertex = key.getMinVertex()->getNum();
      candidate.highVertex = key.getMaxVertex()->getNum();
      candidate.edge = edge;
      candidate.revision = intrinsicEdge.revision;
      _longEdges.push(candidate);
    }

    void enqueueEdge(Id edge, std::set<MEdge, MEdgeLessThan> &front) const
    {
      if(isInteriorUnconstrained(edge)) front.insert(edgeKey(edge));
    }

    void enqueueFaceEdges(Id face, std::set<MEdge, MEdgeLessThan> &front) const
    {
      Id halfEdge = _faces[face].halfEdge;
      for(int i = 0; i < 3; ++i) {
        enqueueEdge(_halfEdges[halfEdge].edge, front);
        halfEdge = _halfEdges[halfEdge].next;
      }
    }

    void enqueueOppositeEdge(Id face, MVertex *vertex,
                             std::set<MEdge, MEdgeLessThan> &front) const
    {
      Id halfEdge = _faces[face].halfEdge;
      for(int i = 0; i < 3; ++i) {
        if(_halfEdges[halfEdge].origin != vertex &&
           destination(halfEdge) != vertex) {
          enqueueEdge(_halfEdges[halfEdge].edge, front);
          return;
        }
        halfEdge = _halfEdges[halfEdge].next;
      }
    }

    bool flipIfNeeded(Id edge, MVertex *localVertex, Id &face0, Id &face1)
    {
      if(!isInteriorUnconstrained(edge)) return false;
      const Id h = _edges[edge].halfEdge;
      const Id twin = _halfEdges[h].twin;
      if(twin == invalidId()) return false;
      const Id hn = _halfEdges[h].next;
      const Id hp = _halfEdges[h].previous;
      const Id tn = _halfEdges[twin].next;
      const Id tp = _halfEdges[twin].previous;

      MVertex *a = _halfEdges[h].origin;
      MVertex *b = destination(h);
      MVertex *c = _halfEdges[hp].origin;
      MVertex *d = _halfEdges[tp].origin;
      if(!a || !b || !c || !d || c == d) return false;
      if(localVertex && (a == localVertex || b == localVertex ||
                         (c != localVertex && d != localVertex)))
        return false;

      const MEdge oldKey(a, b);
      const MEdge newKey(c, d);
      auto duplicate = _edgeIndex.find(newKey);
      if(duplicate != _edgeIndex.end() && duplicate->second != edge)
        return false;

      const double ab_c = orientationUV(a, b, c, _data);
      const double ab_d = orientationUV(a, b, d, _data);
      const double cd_a = orientationUV(c, d, a, _data);
      const double cd_b = orientationUV(c, d, b, _data);
      if(!((ab_c > 0. && ab_d < 0.) || (ab_c < 0. && ab_d > 0.)) ||
         !((cd_a > 0. && cd_b < 0.) || (cd_a < 0. && cd_b > 0.)))
        return false;

      const double ab = _edges[edge].intrinsicLength;
      const double ac = _edges[_halfEdges[hp].edge].intrinsicLength;
      const double bc = _edges[_halfEdges[hn].edge].intrinsicLength;
      const double ad = _edges[_halfEdges[tn].edge].intrinsicLength;
      const double bd = _edges[_halfEdges[tp].edge].intrinsicLength;
      const double oppositeAngles =
        intrinsicAngle(ac, bc, ab) + intrinsicAngle(ad, bd, ab);
      if(oppositeAngles <= std::acos(-1.) + 1.e-10) return false;
      const double cd = unfoldedDiagonal(ab, ac, bc, ad, bd);
      if(!(cd > 0.) || !std::isfinite(cd)) return false;

      face0 = _halfEdges[h].face;
      face1 = _halfEdges[twin].face;
      _edgeIndex.erase(oldKey);

      // h: c->d and twin: d->c. The four outer half-edges retain their
      // endpoints and edge records; only their incident faces change.
      _halfEdges[h].origin = c;
      _halfEdges[twin].origin = d;
      linkFace(face0, h, tp, hn);
      linkFace(face1, twin, hp, tn);
      _edges[edge].halfEdge = h;
      _edges[edge].intrinsicLength = cd;
      _edgeIndex.emplace(newKey, edge);
      refreshLongEdge(edge);
      return true;
    }

    std::size_t legalize(std::set<MEdge, MEdgeLessThan> &front,
                         MVertex *localVertex, std::size_t &remainingFlips,
                         bool &budgetReached)
    {
      std::size_t flips = 0;
      while(!front.empty() && remainingFlips) {
        const MEdge key = *front.begin();
        front.erase(front.begin());
        auto found = _edgeIndex.find(key);
        if(found == _edgeIndex.end()) continue;
        Id face0 = invalidId(), face1 = invalidId();
        if(!flipIfNeeded(found->second, localVertex, face0, face1)) continue;
        ++flips;
        --remainingFlips;
        if(localVertex) {
          enqueueOppositeEdge(face0, localVertex, front);
          enqueueOppositeEdge(face1, localVertex, front);
        }
        else {
          enqueueFaceEdges(face0, front);
          enqueueFaceEdges(face1, front);
        }
      }
      if(!front.empty() && !remainingFlips) budgetReached = true;
      return flips;
    }

    static bool validTriangleXYZ(MVertex *v0, MVertex *v1, MVertex *v2)
    {
      const double e0[3] = {v1->x() - v0->x(), v1->y() - v0->y(),
                            v1->z() - v0->z()};
      const double e1[3] = {v2->x() - v0->x(), v2->y() - v0->y(),
                            v2->z() - v0->z()};
      double scale = 0.;
      for(int i = 0; i < 3; ++i) {
        if(!std::isfinite(e0[i]) || !std::isfinite(e1[i])) return false;
        scale = std::max(scale, std::abs(e0[i]));
        scale = std::max(scale, std::abs(e1[i]));
      }
      if(!(scale > 0.) || !std::isfinite(scale)) return false;
      const double a0 = e0[0] / scale, a1 = e0[1] / scale;
      const double a2 = e0[2] / scale, b0 = e1[0] / scale;
      const double b1 = e1[1] / scale, b2 = e1[2] / scale;
      const double n0 = a1 * b2 - a2 * b1;
      const double n1 = a2 * b0 - a0 * b2;
      const double n2 = a0 * b1 - a1 * b0;
      const double area2 = n0 * n0 + n1 * n1 + n2 * n2;
      return std::isfinite(area2) && area2 > 0.;
    }

    bool validSplitTriangles(MVertex *a, MVertex *b, MVertex *c, MVertex *d,
                             MVertex *midpoint,
                             const SplitGeometry &geometry) const
    {
      std::size_t ia = 0, ib = 0, ic = 0, id = 0;
      if(!existingMeshDataIndex(a, _data, ia) ||
         !existingMeshDataIndex(b, _data, ib) ||
         !existingMeshDataIndex(c, _data, ic) ||
         !existingMeshDataIndex(d, _data, id) || ia >= _data.Us.size() ||
         ib >= _data.Us.size() || ic >= _data.Us.size() ||
         id >= _data.Us.size() || ia >= _data.Vs.size() ||
         ib >= _data.Vs.size() || ic >= _data.Vs.size() ||
         id >= _data.Vs.size())
        return false;

      double pa[2] = {_data.Us[ia], _data.Vs[ia]};
      double pb[2] = {_data.Us[ib], _data.Vs[ib]};
      double pc[2] = {_data.Us[ic], _data.Vs[ic]};
      double pd[2] = {_data.Us[id], _data.Vs[id]};
      double pm[2] = {geometry.u, geometry.v};
      const double old0 = robustPredicates::orient2d(pa, pb, pc);
      const double old1 = robustPredicates::orient2d(pb, pa, pd);
      const double orientations[4] = {robustPredicates::orient2d(pa, pm, pc),
                                      robustPredicates::orient2d(pm, pb, pc),
                                      robustPredicates::orient2d(pb, pm, pd),
                                      robustPredicates::orient2d(pm, pa, pd)};
      if(!std::isfinite(old0) || !std::isfinite(old1) || old0 == 0. ||
         old1 == 0. || ((old0 < 0.) != (old1 < 0.)))
        return false;
      for(int i = 0; i < 4; ++i) {
        const double reference = i < 2 ? old0 : old1;
        if(!std::isfinite(orientations[i]) || orientations[i] == 0. ||
           ((orientations[i] < 0.) != (reference < 0.)))
          return false;
      }

      return validTriangleXYZ(a, midpoint, c) &&
             validTriangleXYZ(midpoint, b, c) &&
             validTriangleXYZ(b, midpoint, d) &&
             validTriangleXYZ(midpoint, a, d);
    }

    bool prepareSplitStorage(std::vector<Id> &cavityFaces)
    {
      const std::size_t idLimit = static_cast<std::size_t>(invalidId());
      const bool idCapacity =
        _halfEdges.size() <= idLimit && 6 <= idLimit - _halfEdges.size() &&
        _faces.size() <= idLimit && 2 <= idLimit - _faces.size() &&
        _edges.size() <= idLimit && 3 <= idLimit - _edges.size();
      const bool alignedData = _data.Us.size() == _data.Vs.size() &&
                               _data.Us.size() == _data.vSizes.size() &&
                               _data.Us.size() == _data.vSizesBGM.size();
      const bool dataIndexCapacity =
        _data.Us.size() <=
        static_cast<std::size_t>(std::numeric_limits<int>::max());
      const bool vectorCapacity =
        6 <= _halfEdges.max_size() - _halfEdges.size() &&
        2 <= _faces.max_size() - _faces.size() &&
        3 <= _edges.max_size() - _edges.size() &&
        1 <= _data.Us.max_size() - _data.Us.size() &&
        1 <= _data.Vs.max_size() - _data.Vs.size() &&
        1 <= _data.vSizes.max_size() - _data.vSizes.size() &&
        1 <= _data.vSizesBGM.max_size() - _data.vSizesBGM.size() &&
        1 <= _gf->mesh_vertices.max_size() - _gf->mesh_vertices.size() &&
        2 <= _gf->triangles.max_size() - _gf->triangles.size() &&
        4 <= cavityFaces.max_size() - cavityFaces.size() &&
        4 <= _edgeIndex.max_size() - _edgeIndex.size();
      if(!idCapacity || !alignedData || !dataIndexCapacity || !vectorCapacity) {
        Msg::Warning("- Face %d: intrinsic half-edge split capacity or mesh "
                     "data consistency check failed",
                     _gf->tag());
        _valid = false;
        return false;
      }

      try {
        _halfEdges.reserve(_halfEdges.size() + 6);
        _faces.reserve(_faces.size() + 2);
        _edges.reserve(_edges.size() + 3);
        _data.Us.reserve(_data.Us.size() + 1);
        _data.Vs.reserve(_data.Vs.size() + 1);
        _data.vSizes.reserve(_data.vSizes.size() + 1);
        _data.vSizesBGM.reserve(_data.vSizesBGM.size() + 1);
        _gf->mesh_vertices.reserve(_gf->mesh_vertices.size() + 1);
        _gf->triangles.reserve(_gf->triangles.size() + 2);
        cavityFaces.reserve(4);
      } catch(const std::bad_alloc &) {
        Msg::Warning("- Face %d: insufficient memory for an intrinsic "
                     "half-edge split",
                     _gf->tag());
        _valid = false;
        return false;
      }
      return true;
    }

    bool splitEdge(Id edge, const SplitGeometry &geometry,
                   double thresholdRatio, MVertex *&midpoint,
                   std::vector<Id> &cavityFaces)
    {
      midpoint = nullptr;
      cavityFaces.clear();
      if(!_valid || !isInteriorUnconstrained(edge) || !(thresholdRatio > 1.))
        return false;
      const Id h = _edges[edge].halfEdge;
      const Id twin = _halfEdges[h].twin;
      const Id hn = _halfEdges[h].next;
      const Id hp = _halfEdges[h].previous;
      const Id tn = _halfEdges[twin].next;
      const Id tp = _halfEdges[twin].previous;
      MVertex *a = _halfEdges[h].origin;
      MVertex *b = destination(h);
      MVertex *c = _halfEdges[hp].origin;
      MVertex *d = _halfEdges[tp].origin;
      if(!a || !b || !c || !d || c == d) return false;
      std::size_t ia = 0, ib = 0;
      if(!existingMeshDataIndex(a, _data, ia) ||
         !existingMeshDataIndex(b, _data, ib) || ia >= _data.vSizes.size() ||
         ib >= _data.vSizes.size())
        return false;

      const double interpolatedSize =
        .5 * _data.vSizes[ia] + .5 * _data.vSizes[ib];
      if(!(interpolatedSize > 0.) || !std::isfinite(interpolatedSize) ||
         !(geometry.localSize > 0.) || !std::isfinite(geometry.localSize) ||
         !std::isfinite(geometry.u) || !std::isfinite(geometry.v) ||
         !prepareSplitStorage(cavityFaces))
        return false;

      std::unique_ptr<MFaceVertex> midpointOwner(
        new MFaceVertex(geometry.point.x(), geometry.point.y(),
                        geometry.point.z(), _gf, geometry.u, geometry.v));
      MVertex *newMidpoint = midpointOwner.get();
      if(!validSplitTriangles(a, b, c, d, newMidpoint, geometry)) return false;

      const double lengthAM = MEdge(a, newMidpoint).length();
      const double lengthBM = MEdge(b, newMidpoint).length();
      const double lengthMC = MEdge(newMidpoint, c).length();
      const double lengthMD = MEdge(newMidpoint, d).length();
      if(!(lengthAM > 0.) || !std::isfinite(lengthAM) || !(lengthBM > 0.) ||
         !std::isfinite(lengthBM) || !(lengthMC > 0.) ||
         !std::isfinite(lengthMC) || !(lengthMD > 0.) ||
         !std::isfinite(lengthMD))
        return false;

      std::unique_ptr<MTriangle> triangle2Owner(
        new MTriangle(newMidpoint, b, c));
      std::unique_ptr<MTriangle> triangle3Owner(
        new MTriangle(newMidpoint, a, d));

      // Stage all allocating map insertions before changing either the GFace or
      // the half-edge connectivity. The edge Ids below are the three records
      // that will be appended after the insertions have succeeded.
      const Id expectedEdgeBM = static_cast<Id>(_edges.size());
      const Id expectedEdgeMC = expectedEdgeBM + 1;
      const Id expectedEdgeMD = expectedEdgeBM + 2;
      const MEdge keyAM(a, newMidpoint);
      const MEdge keyBM(b, newMidpoint);
      const MEdge keyMC(newMidpoint, c);
      const MEdge keyMD(newMidpoint, d);
      bool insertedAM = false, insertedBM = false;
      bool insertedMC = false, insertedMD = false;
      try {
        insertedAM = _edgeIndex.emplace(keyAM, edge).second;
        insertedBM = _edgeIndex.emplace(keyBM, expectedEdgeBM).second;
        insertedMC = _edgeIndex.emplace(keyMC, expectedEdgeMC).second;
        insertedMD = _edgeIndex.emplace(keyMD, expectedEdgeMD).second;
      } catch(const std::bad_alloc &) {
        if(insertedAM) _edgeIndex.erase(keyAM);
        if(insertedBM) _edgeIndex.erase(keyBM);
        if(insertedMC) _edgeIndex.erase(keyMC);
        if(insertedMD) _edgeIndex.erase(keyMD);
        Msg::Warning("- Face %d: insufficient memory for intrinsic split edge "
                     "index",
                     _gf->tag());
        _valid = false;
        return false;
      }
      if(!insertedAM || !insertedBM || !insertedMC || !insertedMD) {
        if(insertedAM) _edgeIndex.erase(keyAM);
        if(insertedBM) _edgeIndex.erase(keyBM);
        if(insertedMC) _edgeIndex.erase(keyMC);
        if(insertedMD) _edgeIndex.erase(keyMD);
        topologyFailure("duplicate edge created by a split");
        return false;
      }

      const MEdge oldKey(a, b);

      // Six new half-edges supplement the two halves h and twin that are
      // reused. This creates four triangles without copying gf->triangles.
      const Id ma = appendHalfEdge(newMidpoint);
      const Id mb = appendHalfEdge(newMidpoint);
      const Id mc = appendHalfEdge(newMidpoint);
      const Id cm = appendHalfEdge(c);
      const Id md = appendHalfEdge(newMidpoint);
      const Id dm = appendHalfEdge(d);
      const Id face0 = _halfEdges[h].face;
      const Id face1 = _halfEdges[twin].face;
      const Id face2 = appendFace(triangle2Owner.get());
      const Id face3 = appendFace(triangle3Owner.get());

      const Id edgeBM = appendEdge(twin, lengthBM);
      const Id edgeMC = appendEdge(mc, lengthMC);
      const Id edgeMD = appendEdge(md, lengthMD);

      // All allocations and validations have succeeded: commit ownership to
      // bidimMeshData/GFace, then rewire the fixed-size local cavity.
      _data.addVertex(newMidpoint, geometry.u, geometry.v, interpolatedSize,
                      geometry.localSize);
      _gf->mesh_vertices.push_back(newMidpoint);
      midpoint = midpointOwner.release();
      _gf->triangles.push_back(triangle2Owner.release());
      _gf->triangles.push_back(triangle3Owner.release());
      _edgeIndex.erase(oldKey);

      _halfEdges[h].twin = ma;
      _halfEdges[ma].twin = h;
      _halfEdges[twin].twin = mb;
      _halfEdges[mb].twin = twin;
      _halfEdges[mc].twin = cm;
      _halfEdges[cm].twin = mc;
      _halfEdges[md].twin = dm;
      _halfEdges[dm].twin = md;

      _halfEdges[h].edge = edge;
      _halfEdges[ma].edge = edge;
      _halfEdges[twin].edge = edgeBM;
      _halfEdges[mb].edge = edgeBM;
      _halfEdges[mc].edge = edgeMC;
      _halfEdges[cm].edge = edgeMC;
      _halfEdges[md].edge = edgeMD;
      _halfEdges[dm].edge = edgeMD;

      linkFace(face0, h, mc, hp); // a, m, c
      linkFace(face2, mb, hn, cm); // m, b, c
      linkFace(face1, twin, md, tp); // b, m, d
      linkFace(face3, ma, tn, dm); // m, a, d

      _edges[edge].halfEdge = h;
      _edges[edge].intrinsicLength = lengthAM;

      refreshLongEdge(edge);
      refreshLongEdge(edgeBM);
      refreshLongEdge(edgeMC);
      refreshLongEdge(edgeMD);
      cavityFaces.push_back(face0);
      cavityFaces.push_back(face2);
      cavityFaces.push_back(face1);
      cavityFaces.push_back(face3);
      return true;
    }

  public:
    IntrinsicTriHalfEdgeMesh(GFace *gf, bidimMeshData &data)
      : _gf(gf), _data(data)
    {
      build();
    }

    bool valid() const { return _valid; }

    std::size_t legalizeGlobally(std::size_t &remainingFlips,
                                 bool &budgetReached)
    {
      std::set<MEdge, MEdgeLessThan> front;
      for(const auto &entry : _edgeIndex)
        if(isInteriorUnconstrained(entry.second)) front.insert(entry.first);
      return legalize(front, nullptr, remainingFlips, budgetReached);
    }

    void initializeLongEdgeQueue()
    {
      _longEdgesReady = true;
      for(Id edge = 0; edge < static_cast<Id>(_edges.size()); ++edge)
        refreshLongEdge(edge);
    }

    bool splitLongestEdge(double &thresholdRatio, MVertex *&midpoint,
                          std::vector<Id> &cavityFaces)
    {
      thresholdRatio = 1.;
      midpoint = nullptr;
      cavityFaces.clear();
      if(!_valid) return false;
      while(!_longEdges.empty()) {
        const LongEdgeCandidate candidate = _longEdges.top();
        _longEdges.pop();
        if(candidate.edge >= _edges.size()) continue;
        const Edge &edge = _edges[candidate.edge];
        if(candidate.revision != edge.revision ||
           !isInteriorUnconstrained(candidate.edge))
          continue;
        const MEdge key = edgeKey(candidate.edge);
        if(candidate.lowVertex != key.getMinVertex()->getNum() ||
           candidate.highVertex != key.getMaxVertex()->getNum())
          continue;
        auto indexed = _edgeIndex.find(key);
        if(indexed == _edgeIndex.end() || indexed->second != candidate.edge)
          continue;

        SplitGeometry geometry;
        double ratio = 0.;
        if(!splitRatio(candidate.edge, ratio, &geometry) || !(ratio > 1.))
          continue;
        if(!splitEdge(candidate.edge, geometry, ratio, midpoint, cavityFaces)) {
          if(!_valid) return false;
          continue;
        }
        thresholdRatio = ratio;
        return true;
      }
      return false;
    }

    std::size_t legalizeLocally(MVertex *midpoint,
                                const std::vector<Id> &cavityFaces,
                                std::size_t &remainingFlips,
                                bool &budgetReached)
    {
      std::set<MEdge, MEdgeLessThan> front;
      for(Id face : cavityFaces) enqueueOppositeEdge(face, midpoint, front);
      return legalize(front, midpoint, remainingFlips, budgetReached);
    }
  };

  // Convert the UV Delaunay connectivity into an intrinsic Delaunay
  // triangulation of the piecewise-flat surface. Intrinsic lengths live on the
  // persistent half-edge records: a flipped diagonal is measured by unfolding
  // its two incident triangles, while newly split edges start with their CAD
  // chord lengths.
  std::size_t intrinsicDelaunayizePackedSurface(GFace *gf, bidimMeshData &data)
  {
    double referenceOrientation = 0.;
    for(MTriangle *triangle : gf->triangles) {
      double orientation = 0.;
      if(!validTriangleUV(triangle, data, orientation)) {
        Msg::Warning("- Face %d: cannot build intrinsic triangulation from "
                     "invalid or collapsed UV triangles",
                     gf->tag());
        return 0;
      }
      if(referenceOrientation == 0.) referenceOrientation = orientation;
    }
    if(referenceOrientation == 0.) {
      Msg::Warning("- Face %d: cannot build an empty intrinsic "
                   "triangulation",
                   gf->tag());
      return 0;
    }

    // A half-edge mesh requires consistently oriented faces. The verified
    // injective chart supplies the reference sign; invalid and collapsed UV
    // triangles have already been rejected above.
    for(MTriangle *triangle : gf->triangles)
      orientTriangleUV(triangle, triangle->getVertex(0), triangle->getVertex(1),
                       triangle->getVertex(2), referenceOrientation, data);

    const std::size_t initialTriangles = gf->triangles.size();
    IntrinsicTriHalfEdgeMesh topology(gf, data);
    if(!topology.valid()) return 0;
    const std::size_t maxFlips =
      std::max<std::size_t>(1000, 100 * initialTriangles);
    std::size_t remainingFlips = maxFlips;
    bool flipBudgetReached = false;
    std::size_t totalFlips =
      topology.legalizeGlobally(remainingFlips, flipBudgetReached);
    if(!flipBudgetReached) topology.initializeLongEdgeQueue();

    const std::size_t splitBudget =
      std::max<std::size_t>(16, initialTriangles / 2);
    std::size_t totalSplits = 0;
    double worstThresholdRatio = 1.;
    while(totalSplits < splitBudget && !flipBudgetReached) {
      double thresholdRatio = 1.;
      MVertex *midpoint = nullptr;
      std::vector<IntrinsicTriHalfEdgeMesh::Id> cavityFaces;
      if(!topology.splitLongestEdge(thresholdRatio, midpoint, cavityFaces))
        break;
      ++totalSplits;
      worstThresholdRatio = std::max(worstThresholdRatio, thresholdRatio);
      totalFlips += topology.legalizeLocally(midpoint, cavityFaces,
                                             remainingFlips, flipBudgetReached);
    }
    if(flipBudgetReached)
      Msg::Warning("- Face %d: intrinsic Delaunay global flip budget reached "
                   "(%zu)",
                   gf->tag(), maxFlips);
    if(totalSplits == splitBudget)
      Msg::Warning("- Face %d: intrinsic long-edge split budget reached (%zu)",
                   gf->tag(), totalSplits);
    Msg::Info("- Face %d: intrinsic Delaunay triangulation, %zu edge flips, "
              "%zu long-edge splits (worst threshold ratio %.6g)",
              gf->tag(), totalFlips, totalSplits, worstThresholdRatio);
    return totalFlips;
  }

  void printTrianglesXYZ(const char *name,
                         const std::vector<MTriangle *> &triangles)
  {
    FILE *file = Fopen(name, "w");
    if(!file) {
      Msg::Error("Could not open file '%s'", name);
      return;
    }
    fprintf(file, "View\"test\"{\n");
    for(MTriangle *triangle : triangles) {
      fprintf(file, "ST(%g,%g,%g,%g,%g,%g,%g,%g,%g) {%zu,%zu,%zu};\n",
              triangle->getVertex(0)->x(), triangle->getVertex(0)->y(),
              triangle->getVertex(0)->z(), triangle->getVertex(1)->x(),
              triangle->getVertex(1)->y(), triangle->getVertex(1)->z(),
              triangle->getVertex(2)->x(), triangle->getVertex(2)->y(),
              triangle->getVertex(2)->z(), triangle->getVertex(0)->getNum(),
              triangle->getVertex(1)->getNum(),
              triangle->getVertex(2)->getNum());
    }
    fprintf(file, "};\n");
    fclose(file);
  }

} // namespace QuadOptimizer
