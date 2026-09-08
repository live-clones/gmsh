// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <stdlib.h>
#include <array>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <limits>
#include <mutex>
#include <map>
#include <queue>
#include <unordered_set>
#include "GmshMessage.h"
#include "discreteEdge.h"
#include "discreteFace.h"
#include "GModelIO_GEO.h"
#include "Geo.h"
#include "Context.h"
#include "MPoint.h"
#include "MElementOctree.h"
#include "Octree.h"
#include "Context.h"
#include "GEdgeLoop.h"
#include "MEdge.h"
#include "GModelParametrize.h"

extern "C" {
#include "libol1.h"
}

namespace {

struct ExactTriangleProjection {
  SPoint3 point = SPoint3(0., 0., 0.);
  std::array<double, 3> weights{{0., 0., 0.}};
  double squaredDistance = std::numeric_limits<double>::max();
};

static bool finishTriangleProjection(const SPoint3 &query,
                                     const SPoint3 &point,
                                     const std::array<double, 3> &weights,
                                     ExactTriangleProjection &projection)
{
  const SVector3 difference = query - point;
  const double squaredDistance = dot(difference, difference);
  if(!std::isfinite(point.x()) || !std::isfinite(point.y()) ||
     !std::isfinite(point.z()) || !std::isfinite(squaredDistance) ||
     squaredDistance < 0.)
    return false;
  projection.point = point;
  projection.weights = weights;
  projection.squaredDistance = squaredDistance;
  return true;
}

static bool projectPointOnTriangleEdges(const SPoint3 &query,
                                        const SPoint3 &a, const SPoint3 &b,
                                        const SPoint3 &c,
                                        ExactTriangleProjection &projection)
{
  bool found = false;
  const auto consider = [&](const SPoint3 &first, const SPoint3 &second,
                            int firstIndex, int secondIndex) {
    const SVector3 edge = second - first;
    const double squaredLength = dot(edge, edge);
    double parameter = 0.;
    if(std::isfinite(squaredLength) && squaredLength > 0.) {
      parameter = dot(query - first, edge) / squaredLength;
      parameter = std::max(0., std::min(1., parameter));
    }
    const SPoint3 point = first + parameter * edge;
    std::array<double, 3> weights{{0., 0., 0.}};
    weights[firstIndex] = 1. - parameter;
    weights[secondIndex] = parameter;
    ExactTriangleProjection candidate;
    if(!finishTriangleProjection(query, point, weights, candidate)) return;
    if(!found || candidate.squaredDistance < projection.squaredDistance) {
      projection = candidate;
      found = true;
    }
  };
  consider(a, b, 0, 1);
  consider(b, c, 1, 2);
  consider(c, a, 2, 0);
  return found;
}

// Exact Euclidean point-triangle projection (Ericson's Voronoi-region test).
// The edge fallback also gives a well-defined result on degenerate STL facets.
static bool projectPointOnTriangle(const SPoint3 &query,
                                   const MTriangle &triangle,
                                   ExactTriangleProjection &projection)
{
  const SPoint3 a = triangle.getVertex(0)->point();
  const SPoint3 b = triangle.getVertex(1)->point();
  const SPoint3 c = triangle.getVertex(2)->point();
  const SVector3 ab = b - a;
  const SVector3 ac = c - a;
  const SVector3 normal = crossprod(ab, ac);
  const double squaredArea = dot(normal, normal);
  if(!std::isfinite(squaredArea) || squaredArea == 0.)
    return projectPointOnTriangleEdges(query, a, b, c, projection);

  const SVector3 ap = query - a;
  const double d1 = dot(ab, ap);
  const double d2 = dot(ac, ap);
  if(d1 <= 0. && d2 <= 0.)
    return finishTriangleProjection(query, a, {{1., 0., 0.}}, projection);

  const SVector3 bp = query - b;
  const double d3 = dot(ab, bp);
  const double d4 = dot(ac, bp);
  if(d3 >= 0. && d4 <= d3)
    return finishTriangleProjection(query, b, {{0., 1., 0.}}, projection);

  const double vc = d1 * d4 - d3 * d2;
  if(vc <= 0. && d1 >= 0. && d3 <= 0.) {
    const double denominator = d1 - d3;
    if(denominator > 0.) {
      const double v = d1 / denominator;
      return finishTriangleProjection(query, a + v * ab, {{1. - v, v, 0.}},
                                      projection);
    }
    return projectPointOnTriangleEdges(query, a, b, c, projection);
  }

  const SVector3 cp = query - c;
  const double d5 = dot(ab, cp);
  const double d6 = dot(ac, cp);
  if(d6 >= 0. && d5 <= d6)
    return finishTriangleProjection(query, c, {{0., 0., 1.}}, projection);

  const double vb = d5 * d2 - d1 * d6;
  if(vb <= 0. && d2 >= 0. && d6 <= 0.) {
    const double denominator = d2 - d6;
    if(denominator > 0.) {
      const double w = d2 / denominator;
      return finishTriangleProjection(query, a + w * ac, {{1. - w, 0., w}},
                                      projection);
    }
    return projectPointOnTriangleEdges(query, a, b, c, projection);
  }

  const double va = d3 * d6 - d5 * d4;
  if(va <= 0. && d4 - d3 >= 0. && d5 - d6 >= 0.) {
    const double denominator = d4 - d3 + d5 - d6;
    if(denominator > 0.) {
      const double w = (d4 - d3) / denominator;
      return finishTriangleProjection(query, b + w * (c - b),
                                      {{0., 1. - w, w}}, projection);
    }
    return projectPointOnTriangleEdges(query, a, b, c, projection);
  }

  const double denominator = va + vb + vc;
  if(!(denominator > 0.) || !std::isfinite(denominator))
    return projectPointOnTriangleEdges(query, a, b, c, projection);
  const double v = vb / denominator;
  const double w = vc / denominator;
  return finishTriangleProjection(query, a + v * ab + w * ac,
                                  {{1. - v - w, v, w}}, projection);
}

} // namespace

#if defined(HAVE_EIGEN) && defined(HAVE_GEOMETRYCENTRAL)
#include <Eigen/Core>
#include <Eigen/Dense>
#include "geometrycentral/surface/signpost_intrinsic_triangulation.h"
#include "geometrycentral/surface/vertex_position_geometry.h"
#endif

discreteFace::param::~param()
{
  clear();
}

void discreteFace::param::clear()
{
  if(libolOctree) {
    LolFreeOctree(libolOctree);
    libolOctree = 0;
  }
  libolVertexCoordinates.clear();
  libolTriangles.clear();
  libolTriangleToParam.clear();
  libolDegenerateTrianglePositions.clear();
  triangleBvhPositions.clear();
  triangleBvhNodes.clear();
  libolUvTriangleCache.clear();
  if(oct) delete oct;
  oct = nullptr;
  rtree3d.RemoveAll();
  for(auto p : rtree3dData) delete p;
  rtree3dData.clear();
  v2d.clear();
  v3d.clear();
  bbox = SBoundingBox3d();
  t2d.clear();
  t3d.clear();
  triangleUnitNormals.clear();
  uvTriangleGrid.clear();
  uvTriangleGridResolution = 0;
  uvTriangleGridMin[0] = uvTriangleGridMin[1] = 0.;
  uvTriangleGridMax[0] = uvTriangleGridMax[1] = 0.;
  uvTriangleGridTolerance = 0.;
  CURV.clear();
}

void discreteFace::_buildUvTriangleGrid()
{
  _param.uvTriangleGrid.clear();
  _param.uvTriangleGridResolution = 0;
  if(_param.t2d.empty()) return;

  double minimum[2] = {
    std::numeric_limits<double>::max(),
    std::numeric_limits<double>::max()};
  double maximum[2] = {
    -std::numeric_limits<double>::max(),
    -std::numeric_limits<double>::max()};
  for(const MTriangle &triangle : _param.t2d) {
    for(int i = 0; i < 3; ++i) {
      const MVertex *vertex = triangle.getVertex(i);
      if(!vertex || !std::isfinite(vertex->x()) ||
         !std::isfinite(vertex->y()))
        return;
      minimum[0] = std::min(minimum[0], vertex->x());
      minimum[1] = std::min(minimum[1], vertex->y());
      maximum[0] = std::max(maximum[0], vertex->x());
      maximum[1] = std::max(maximum[1], vertex->y());
    }
  }
  if(!(maximum[0] > minimum[0]) || !(maximum[1] > minimum[1])) return;

  const std::size_t resolution = std::max<std::size_t>(
    16, std::min<std::size_t>(
      512, static_cast<std::size_t>(
        std::ceil(2. * std::sqrt(
          static_cast<double>(_param.t2d.size()))))));
  _param.uvTriangleGrid.assign(
    resolution * resolution, std::vector<std::size_t>());
  _param.uvTriangleGridResolution = resolution;
  _param.uvTriangleGridMin[0] = minimum[0];
  _param.uvTriangleGridMin[1] = minimum[1];
  _param.uvTriangleGridMax[0] = maximum[0];
  _param.uvTriangleGridMax[1] = maximum[1];
  _param.uvTriangleGridTolerance =
    CTX::instance()->mesh.toleranceReferenceElement;

  auto cell = [&](double value, int axis) {
    const double normalized =
      (value - minimum[axis]) / (maximum[axis] - minimum[axis]);
    if(normalized <= 0.) return std::size_t(0);
    if(normalized >= 1.) return resolution - 1;
    return std::min(
      resolution - 1,
      static_cast<std::size_t>(normalized * resolution));
  };
  const double tolerance = std::max(
    0., _param.uvTriangleGridTolerance);
  for(std::size_t position = 0; position < _param.t2d.size();
      ++position) {
    const MTriangle &triangle = _param.t2d[position];
    double lower[2] = {
      std::numeric_limits<double>::max(),
      std::numeric_limits<double>::max()};
    double upper[2] = {
      -std::numeric_limits<double>::max(),
      -std::numeric_limits<double>::max()};
    for(int axis = 0; axis < 2; ++axis) {
      double edgeSum = 0.;
      for(int i = 0; i < 3; ++i) {
        const double current = axis == 0 ?
          triangle.getVertex(i)->x() : triangle.getVertex(i)->y();
        const double next = axis == 0 ?
          triangle.getVertex((i + 1) % 3)->x() :
          triangle.getVertex((i + 1) % 3)->y();
        lower[axis] = std::min(lower[axis], current);
        upper[axis] = std::max(upper[axis], current);
        edgeSum += std::abs(next - current);
      }
      // MElement::isInside accepts barycentric coordinates through +/-tol.
      // Expand by a conservative coordinate-space image of that envelope so
      // every triangle accepted by the historical predicate is in the cell.
      const double padding = 2. * tolerance * edgeSum;
      lower[axis] -= padding;
      upper[axis] += padding;
    }
    const std::size_t firstU = cell(lower[0], 0);
    const std::size_t lastU = cell(upper[0], 0);
    const std::size_t firstV = cell(lower[1], 1);
    const std::size_t lastV = cell(upper[1], 1);
    for(std::size_t j = firstV; j <= lastV; ++j)
      for(std::size_t i = firstU; i <= lastU; ++i)
        _param.uvTriangleGrid[j * resolution + i].push_back(position);
  }
}

void discreteFace::_buildTriangleBvh()
{
  _param.triangleBvhPositions.clear();
  _param.triangleBvhNodes.clear();
  if(_param.t3d.empty()) return;

  _param.triangleBvhPositions.resize(_param.t3d.size());
  for(std::size_t i = 0; i < _param.t3d.size(); ++i)
    _param.triangleBvhPositions[i] = i;
  _param.triangleBvhNodes.reserve(2 * _param.t3d.size());

  const auto coordinate = [&](std::size_t triangle, int vertex, int axis) {
    const MVertex *point = _param.t3d[triangle].getVertex(vertex);
    return axis == 0 ? point->x() : axis == 1 ? point->y() : point->z();
  };
  bool valid = true;
  const std::function<std::size_t(std::size_t, std::size_t)> build =
    [&](std::size_t begin, std::size_t end) -> std::size_t {
      param::TriangleBvhNode node;
      node.begin = begin;
      node.end = end;
      for(int axis = 0; axis < 3; ++axis) {
        node.minimum[axis] = std::numeric_limits<double>::max();
        node.maximum[axis] = -std::numeric_limits<double>::max();
      }
      for(std::size_t offset = begin; offset < end; ++offset) {
        const std::size_t triangle =
          _param.triangleBvhPositions[offset];
        for(int vertex = 0; vertex < 3; ++vertex) {
          for(int axis = 0; axis < 3; ++axis) {
            const double value = coordinate(triangle, vertex, axis);
            if(!std::isfinite(value)) valid = false;
            node.minimum[axis] = std::min(node.minimum[axis], value);
            node.maximum[axis] = std::max(node.maximum[axis], value);
          }
        }
      }

      const std::size_t index = _param.triangleBvhNodes.size();
      _param.triangleBvhNodes.push_back(node);
      constexpr std::size_t leafSize = 2;
      if(end - begin <= leafSize) return index;

      int splitAxis = 0;
      for(int axis = 1; axis < 3; ++axis)
        if(node.maximum[axis] - node.minimum[axis] >
           node.maximum[splitAxis] - node.minimum[splitAxis])
          splitAxis = axis;
      std::stable_sort(
        _param.triangleBvhPositions.begin() +
          static_cast<std::ptrdiff_t>(begin),
        _param.triangleBvhPositions.begin() +
          static_cast<std::ptrdiff_t>(end),
        [&](std::size_t first, std::size_t second) {
          double firstCenter = 0.;
          double secondCenter = 0.;
          for(int vertex = 0; vertex < 3; ++vertex) {
            firstCenter += coordinate(first, vertex, splitAxis);
            secondCenter += coordinate(second, vertex, splitAxis);
          }
          if(firstCenter != secondCenter)
            return firstCenter < secondCenter;
          return first < second;
        });
      const std::size_t middle = begin + (end - begin) / 2;
      const std::size_t left = build(begin, middle);
      const std::size_t right = build(middle, end);
      _param.triangleBvhNodes[index].leaf = false;
      _param.triangleBvhNodes[index].left = left;
      _param.triangleBvhNodes[index].right = right;
      return index;
    };

  build(0, _param.triangleBvhPositions.size());
  if(!valid) {
    _param.triangleBvhPositions.clear();
    _param.triangleBvhNodes.clear();
  }
}

const MTriangle *discreteFace::_findUniqueInteriorUvTriangle(
  double u, double v) const
{
  const std::size_t resolution = _param.uvTriangleGridResolution;
  if(!resolution || _param.uvTriangleGrid.size() != resolution * resolution ||
     !std::isfinite(u) || !std::isfinite(v) ||
     CTX::instance()->mesh.toleranceReferenceElement !=
       _param.uvTriangleGridTolerance ||
     u < _param.uvTriangleGridMin[0] ||
     u > _param.uvTriangleGridMax[0] ||
     v < _param.uvTriangleGridMin[1] ||
     v > _param.uvTriangleGridMax[1])
    return nullptr;

  auto cell = [&](double value, int axis) {
    const double normalized =
      (value - _param.uvTriangleGridMin[axis]) /
      (_param.uvTriangleGridMax[axis] - _param.uvTriangleGridMin[axis]);
    if(normalized <= 0.) return std::size_t(0);
    if(normalized >= 1.) return resolution - 1;
    return std::min(
      resolution - 1,
      static_cast<std::size_t>(normalized * resolution));
  };
  const std::size_t i = cell(u, 0);
  const std::size_t j = cell(v, 1);
  const std::vector<std::size_t> &candidates =
    _param.uvTriangleGrid[j * resolution + i];
  const MTriangle *match = nullptr;
  bool strictlyInterior = false;
  double point[3] = {u, v, 0.};
  const double tolerance = _param.uvTriangleGridTolerance;
  for(const std::size_t position : candidates) {
    if(position >= _param.t2d.size()) return nullptr;
    const MTriangle &triangle = _param.t2d[position];
    double barycentric[3] = {0., 0., 0.};
    triangle.xyz2uvw(point, barycentric);
    if(!std::isfinite(barycentric[0]) ||
       !std::isfinite(barycentric[1]) ||
       !std::isfinite(barycentric[2]) ||
       !triangle.isInside(
         barycentric[0], barycentric[1], barycentric[2]))
      continue;
    if(match) return nullptr;
    match = &triangle;
    strictlyInterior = barycentric[0] > tolerance &&
      barycentric[1] > tolerance &&
      1. - barycentric[0] - barycentric[1] > tolerance &&
      std::abs(barycentric[2]) <= tolerance;
  }
  return match && strictlyInterior ? match : nullptr;
}

bool discreteFace::param::checkPlanar()
{
  SBoundingBox3d bb;
  mean_plane mp;
  std::vector<SPoint3> v, vp;
  for(size_t i = 0; i < t3d.size(); i++) {
    for(int j = 0; j < 3; j++) {
      SPoint3 p(t3d[i].getVertex(j)->x(), t3d[i].getVertex(j)->y(),
                t3d[i].getVertex(j)->z());
      bb += p;
      v.push_back(p);
    }
  }

  computeMeanPlaneSimple(v, mp);
  projectPointsToPlane(v, vp, mp);
  for(size_t i = 0; i < v.size(); i++) {
    double F = mp.a * v[i].x() + mp.b * v[i].y() + mp.c * v[i].z() - mp.d;
    // this is maybe a bit strict, but it's better this way: wrongly identifying
    // a very thin (but curved) surface as plane will lead to complete meshing
    // failure (see e.g. mmbendo.stl in #641)
    if(fabs(F) > CTX::instance()->geom.matchMeshTolerance * bb.diag()) {
      return false;
    }
  }

  SVector3 VX(mp.plan[0][0], mp.plan[0][1], mp.plan[0][2]);
  SVector3 VY(mp.plan[1][0], mp.plan[1][1], mp.plan[1][2]);
  SPoint3 XP(mp.x, mp.y, mp.z);

  umin = 1e200;
  vmin = 1e200;
  umax = -1e200;
  vmax = -1e200;

  int count = 0;
  for(size_t i = 0; i < t2d.size(); i++) {
    for(int j = 0; j < 3; j++) {
      SVector3 DX = vp[count++] - XP;
      MVertex *v = t2d[i].getVertex(j);
      v->x() = dot(DX, VX);
      v->y() = dot(DX, VY);
      umin = std::min(umin, v->x());
      vmin = std::min(vmin, v->y());
      umax = std::max(umax, v->x());
      vmax = std::max(vmax, v->y());
    }
  }
  return true;
}

discreteFace::discreteFace(GModel *model, int num) : GFace(model, num)
{
  Surface *s = CreateSurface(num, MSH_SURF_DISCRETE);
  Tree_Add(model->getGEOInternals()->Surfaces, &s);
  meshStatistics.status = GFace::DONE;
}

discreteFace::discreteFace(GModel *model) : GFace(model, 0)
{
  // used for temporary discrete faces, that should not lead to the creation of
  // the corresponding entity in GEO internals
}

int discreteFace::trianglePosition(double par1, double par2, double &u,
                                   double &v) const
{
  if(_param.empty()) return 0;

  double xy[3] = {par1, par2, 0};
  double uv[3];
  const MElement *e = _param.oct->find(par1, par2, 0.0, -1, true);
  if(!e) return -1;
  e->xyz2uvw(xy, uv);
  int position = (int)((MTriangle *)e - &_param.t2d[0]);
  u = uv[0];
  v = uv[1];
  return position;
}

static void MYxyz2uvw(const MElement *t, double xyz[3], double uvw[3])
{
  double M[2][2], R[2];
  const SPoint2 p0(t->getVertex(0)->x(), t->getVertex(0)->y());
  const SPoint2 p1(t->getVertex(1)->x(), t->getVertex(1)->y());
  const SPoint2 p2(t->getVertex(2)->x(), t->getVertex(2)->y());
  M[0][0] = p1.x() - p0.x();
  M[0][1] = p2.x() - p0.x();
  M[1][0] = p1.y() - p0.y();
  M[1][1] = p2.y() - p0.y();
  R[0] = (xyz[0] - p0.x());
  R[1] = (xyz[1] - p0.y());
  double const det = M[0][0] * M[1][1] - M[1][0] * M[0][1];
  uvw[0] = R[0] * M[1][1] - M[0][1] * R[1];
  uvw[1] = M[0][0] * R[1] - M[1][0] * R[0];
  uvw[0] /= det;
  uvw[1] /= det;
  return;
}

GPoint discreteFace::point(double par1, double par2) const
{
  if(_param.empty()) return GPoint();

  double xy[3] = {par1, par2, 0};
  double uv[3];
  const MElement *e = _param.oct->find(par1, par2, 0.0, -1, true);
  if(!e) {
    GPoint gp = GPoint(1.e21, 1.e21, 1.e21, this, xy);
    gp.setNoSuccess();
    return gp;
  }
  MYxyz2uvw(e, xy, uv);
  int position = (int)((MTriangle *)e - &_param.t2d[0]);
  const MTriangle &t3d = _param.t3d[position];
  double X = 0, Y = 0, Z = 0;
  double eval[3] = {1. - uv[0] - uv[1], uv[0], uv[1]};
  for(int io = 0; io < 3; io++) {
    X += t3d.getVertex(io)->x() * eval[io];
    Y += t3d.getVertex(io)->y() * eval[io];
    Z += t3d.getVertex(io)->z() * eval[io];
  }
  return GPoint(X, Y, Z, this, xy);
}

class dfWrapper {
public:
  SPoint3 _p;
  double _distance;
  SPoint3 _closestPoint;
  MTriangle *_t3d, *_t2d;
  dfWrapper(const SPoint3 &p)
    : _p(p), _distance(1.e22), _t3d(nullptr), _t2d(nullptr)
  {
  }
};

bool discreteFace_rtree_callback(std::pair<MTriangle *, MTriangle *> *t,
                                 void *w)
{
  dfWrapper *wrapper = static_cast<dfWrapper *>(w);

  SPoint3 closePt;
  double d;
  signedDistancePointTriangle(
    SPoint3(t->first->getVertex(0)->x(), t->first->getVertex(0)->y(),
            t->first->getVertex(0)->z()),
    SPoint3(t->first->getVertex(1)->x(), t->first->getVertex(1)->y(),
            t->first->getVertex(1)->z()),
    SPoint3(t->first->getVertex(2)->x(), t->first->getVertex(2)->y(),
            t->first->getVertex(2)->z()),
    wrapper->_p, d, closePt);
  if(fabs(d) < wrapper->_distance) {
    wrapper->_distance = fabs(d);
    wrapper->_closestPoint = closePt;
    wrapper->_t3d = t->first;
    wrapper->_t2d = t->second;
  }

  return true;
}

class dfCircleCandidates {
public:
  std::vector<std::pair<MTriangle *, MTriangle *> *> triangles;
};

static bool discreteFace_circle_rtree_callback(
  std::pair<MTriangle *, MTriangle *> *triangle, void *context)
{
  static_cast<dfCircleCandidates *>(context)->triangles.push_back(triangle);
  return true;
}

GPoint discreteFace::closestPoint(const SPoint3 &queryPoint, double maxDistance,
                                  SVector3 *normal) const
{
  if(_param.empty()) {
    auto pp = GPoint();
    pp.setNoSuccess();
    return pp;
  }

  dfWrapper wrapper(queryPoint);
  do {
    wrapper._distance = 1.e22;
    double MIN[3] = {queryPoint.x() - maxDistance, queryPoint.y() - maxDistance,
                     queryPoint.z() - maxDistance};
    double MAX[3] = {queryPoint.x() + maxDistance, queryPoint.y() + maxDistance,
                     queryPoint.z() + maxDistance};
    _param.rtree3d.Search(MIN, MAX, discreteFace_rtree_callback, &wrapper);
    maxDistance *= 2.0;
  } while(!wrapper._t3d);

  if(normal) {
    SVector3 t1(
      wrapper._t3d->getVertex(1)->x() - wrapper._t3d->getVertex(0)->x(),
      wrapper._t3d->getVertex(1)->y() - wrapper._t3d->getVertex(0)->y(),
      wrapper._t3d->getVertex(1)->z() - wrapper._t3d->getVertex(0)->z());
    SVector3 t2(
      wrapper._t3d->getVertex(2)->x() - wrapper._t3d->getVertex(0)->x(),
      wrapper._t3d->getVertex(2)->y() - wrapper._t3d->getVertex(0)->y(),
      wrapper._t3d->getVertex(2)->z() - wrapper._t3d->getVertex(0)->z());
    *normal = crossprod(t1, t2);
    normal->normalize();
  }

  double xyz[3] = {wrapper._closestPoint.x(), wrapper._closestPoint.y(),
                   wrapper._closestPoint.z()};
  double uvw[3];
  wrapper._t3d->xyz2uvw(xyz, uvw);
  const MVertex *v0 = wrapper._t2d->getVertex(0);
  const MVertex *v1 = wrapper._t2d->getVertex(1);
  const MVertex *v2 = wrapper._t2d->getVertex(2);
  const MVertex *v03 = wrapper._t3d->getVertex(0);
  const MVertex *v13 = wrapper._t3d->getVertex(1);
  const MVertex *v23 = wrapper._t3d->getVertex(2);
  double U = 1 - uvw[0] - uvw[1];
  double V = uvw[0];
  double W = uvw[1];
  SPoint2 pp(U * v0->x() + V * v1->x() + W * v2->x(),
             U * v0->y() + V * v1->y() + W * v2->y());
  SPoint3 pp3(U * v03->x() + V * v13->x() + W * v23->x(),
              U * v03->y() + V * v13->y() + W * v23->y(),
              U * v03->z() + V * v13->z() + W * v23->z());

  return GPoint(pp3.x(), pp3.y(), pp3.z(), this, pp);
}

GPoint discreteFace::closestPoint(const SPoint3 &queryPoint,
                                  const double initialGuess[2]) const
{
  const GPoint result = closestPointLibOL(queryPoint, nullptr, initialGuess);
  if(result.succeeded() || !std::isfinite(queryPoint.x()) ||
     !std::isfinite(queryPoint.y()) || !std::isfinite(queryPoint.z()))
    return result;
  return closestPoint(queryPoint, 1e-1);
}

GPoint discreteFace::closestPointLibOL(const SPoint3 &queryPoint,
                                       SVector3 *normal,
                                       const double initialGuess[2]) const
{
  const auto failedPoint = [this]() {
    GPoint result(0., 0., 0., this);
    result.setNoSuccess();
    return result;
  };
  double query[3] = {queryPoint.x(), queryPoint.y(), queryPoint.z()};
  std::size_t position = std::numeric_limits<std::size_t>::max();
  ExactTriangleProjection best;
  bool haveInitialCandidate = false;
  // LibOL uses face-local mutable scratch arrays indexed by a thread slot.
  // This first, deliberately conservative implementation owns one slot and
  // serializes concurrent queries on the same face. Different faces remain
  // fully independent and can still be queried in parallel. Holding the lock
  // until the GPoint is assembled also protects against a geometry rebuild.
  std::lock_guard<std::mutex> lock(_param.libolMutex);
  if(_param.empty() ||
     (!_param.libolOctree &&
      _param.libolDegenerateTrianglePositions.empty()) ||
     !std::isfinite(queryPoint.x()) || !std::isfinite(queryPoint.y()) ||
     !std::isfinite(queryPoint.z()))
    return failedPoint();

  const auto consider = [&](std::size_t candidatePosition) {
    if(candidatePosition >= _param.t3d.size() ||
       candidatePosition >= _param.t2d.size())
      return;
    ExactTriangleProjection candidate;
    if(!projectPointOnTriangle(queryPoint, _param.t3d[candidatePosition],
                               candidate))
      return;
    if(position == std::numeric_limits<std::size_t>::max() ||
       candidate.squaredDistance < best.squaredDistance) {
      position = candidatePosition;
      best = candidate;
    }
  };

  // Degenerate STL facets are not inserted in LibOL because its octree
  // construction computes a facet aspect ratio. They are generally absent;
  // when present, checking their edges explicitly keeps this query exact.
  for(const std::size_t candidatePosition :
      _param.libolDegenerateTrianglePositions)
    consider(candidatePosition);

  // A valid UV guess immediately supplies a rigorous upper distance bound.
  // Keeping it on ties also preserves the expected chart at discrete seams.
  if(initialGuess && std::isfinite(initialGuess[0]) &&
     std::isfinite(initialGuess[1]) && _param.oct) {
    const param::uvKey key(initialGuess[0], initialGuess[1]);
    const auto cached = _param.libolUvTriangleCache.find(key);
    if(cached != _param.libolUvTriangleCache.end()) {
      haveInitialCandidate = cached->second < _param.t3d.size();
      consider(cached->second);
    }
    else {
      const MTriangle *triangle = _findUniqueInteriorUvTriangle(
        initialGuess[0], initialGuess[1]);
      const MElement *element = triangle;
      if(!element)
        element = _param.oct->find(
          initialGuess[0], initialGuess[1], 0., -1, true);
      if(element) {
        triangle = static_cast<const MTriangle *>(element);
        const std::ptrdiff_t candidatePosition =
          triangle - _param.t2d.data();
        if(candidatePosition >= 0 &&
           static_cast<std::size_t>(candidatePosition) <
             _param.t2d.size()) {
          constexpr std::size_t maxCachedGuesses = 4096;
          if(_param.libolUvTriangleCache.size() >= maxCachedGuesses)
            _param.libolUvTriangleCache.clear();
          _param.libolUvTriangleCache.emplace(
            key, static_cast<std::size_t>(candidatePosition));
          haveInitialCandidate = true;
          consider(static_cast<std::size_t>(candidatePosition));
        }
      }
    }
  }

  // The UV seed provides an upper bound. Traverse the immutable triangle BVH
  // against that bound and evaluate every surviving leaf with the same exact
  // Euclidean predicate. Unlike an octree, each surface triangle occurs in a
  // single leaf; this removes the repeated tagged-link walks from the hot
  // projection path while preserving the seed on equal-distance seams.
  bool usedTriangleBvh = false;
  if(haveInitialCandidate &&
     position != std::numeric_limits<std::size_t>::max() &&
     best.squaredDistance > 0. &&
     !_param.triangleBvhNodes.empty() &&
     _param.triangleBvhPositions.size() == _param.t3d.size()) {
    const double coordinateScale =
      std::max({1., std::fabs(queryPoint.x()), std::fabs(queryPoint.y()),
                std::fabs(queryPoint.z()), std::fabs(best.point.x()),
                std::fabs(best.point.y()), std::fabs(best.point.z())});
    const double roundingMargin =
      256. * std::numeric_limits<double>::epsilon() *
      coordinateScale * coordinateScale;
    const auto boxSquaredDistance = [&](const param::TriangleBvhNode &node) {
      double squaredDistance = 0.;
      for(int axis = 0; axis < 3; ++axis) {
        const double value = query[axis];
        double difference = 0.;
        if(value < node.minimum[axis])
          difference = node.minimum[axis] - value;
        else if(value > node.maximum[axis])
          difference = value - node.maximum[axis];
        squaredDistance += difference * difference;
      }
      return squaredDistance;
    };

    thread_local std::vector<std::size_t> stack;
    stack.clear();
    stack.push_back(0);
    while(!stack.empty()) {
      const std::size_t nodePosition = stack.back();
      stack.pop_back();
      if(nodePosition >= _param.triangleBvhNodes.size()) continue;
      const param::TriangleBvhNode &node =
        _param.triangleBvhNodes[nodePosition];
      if(boxSquaredDistance(node) >
         best.squaredDistance + roundingMargin)
        continue;
      if(node.leaf) {
        const std::size_t end = std::min(
          node.end, _param.triangleBvhPositions.size());
        for(std::size_t offset = node.begin; offset < end; ++offset)
          consider(_param.triangleBvhPositions[offset]);
        continue;
      }

      if(node.left >= _param.triangleBvhNodes.size() ||
         node.right >= _param.triangleBvhNodes.size())
        continue;
      const double leftDistance = boxSquaredDistance(
        _param.triangleBvhNodes[node.left]);
      const double rightDistance = boxSquaredDistance(
        _param.triangleBvhNodes[node.right]);
      // LIFO: push the farther child first so the nearer bound tightens the
      // search before the other branch is reconsidered.
      if(leftDistance < rightDistance) {
        if(rightDistance <= best.squaredDistance + roundingMargin)
          stack.push_back(node.right);
        if(leftDistance <= best.squaredDistance + roundingMargin)
          stack.push_back(node.left);
      }
      else {
        if(leftDistance <= best.squaredDistance + roundingMargin)
          stack.push_back(node.left);
        if(rightDistance <= best.squaredDistance + roundingMargin)
          stack.push_back(node.right);
      }
    }
    usedTriangleBvh = true;
  }

  // Retain LibOL for callers without a usable UV seed and as a defensive
  // fallback when the immutable BVH could not be built.
  if(!usedTriangleBvh && _param.libolOctree &&
     (position == std::numeric_limits<std::size_t>::max() ||
      best.squaredDistance > 0.)) {
    double nearestDistance = std::numeric_limits<double>::max();
    double maxDistance = 0.;
    if(position != std::numeric_limits<std::size_t>::max()) {
      const double coordinateScale =
        std::max({1., std::fabs(queryPoint.x()), std::fabs(queryPoint.y()),
                  std::fabs(queryPoint.z()), std::fabs(best.point.x()),
                  std::fabs(best.point.y()), std::fabs(best.point.z())});
      maxDistance = std::sqrt(best.squaredDistance) +
        128. * std::numeric_limits<double>::epsilon() * coordinateScale;
    }
    const int32_t nearest =
      LolGetNearest(_param.libolOctree, LolTypTri, query,
                    &nearestDistance, maxDistance, nullptr, nullptr, 0);
    if(nearest > 0) {
      const std::size_t libolPosition =
        static_cast<std::size_t>(nearest - 1);
      if(libolPosition < _param.libolTriangleToParam.size())
        consider(_param.libolTriangleToParam[libolPosition]);
    }
  }
  if(position == std::numeric_limits<std::size_t>::max())
    return failedPoint();

  if(position >= _param.t3d.size() || position >= _param.t2d.size())
    return failedPoint();
  const MTriangle &triangle3d = _param.t3d[position];
  const MTriangle &triangle2d = _param.t2d[position];

  if(normal) {
    if(position < _param.triangleUnitNormals.size())
      *normal = _param.triangleUnitNormals[position];
    else {
      const SVector3 first(
        triangle3d.getVertex(1)->x() - triangle3d.getVertex(0)->x(),
        triangle3d.getVertex(1)->y() - triangle3d.getVertex(0)->y(),
        triangle3d.getVertex(1)->z() - triangle3d.getVertex(0)->z());
      const SVector3 second(
        triangle3d.getVertex(2)->x() - triangle3d.getVertex(0)->x(),
        triangle3d.getVertex(2)->y() - triangle3d.getVertex(0)->y(),
        triangle3d.getVertex(2)->z() - triangle3d.getVertex(0)->z());
      *normal = crossprod(first, second);
      normal->normalize();
    }
  }

  SPoint2 parameter;
  for(int i = 0; i < 3; ++i) {
    parameter[0] += best.weights[i] * triangle2d.getVertex(i)->x();
    parameter[1] += best.weights[i] * triangle2d.getVertex(i)->y();
  }
  return GPoint(best.point.x(), best.point.y(), best.point.z(), this,
                parameter);
}

GPoint discreteFace::closestPointFromTrustedGuess(
  const SPoint3 &queryPoint, const double initialGuess[2]) const
{
  const GPoint result = closestPointLibOL(queryPoint, nullptr, initialGuess);
  if(result.succeeded() || !std::isfinite(queryPoint.x()) ||
     !std::isfinite(queryPoint.y()) || !std::isfinite(queryPoint.z()))
    return result;
  return closestPoint(queryPoint, 1e-1);
}

SPoint2 discreteFace::parFromPoint(const SPoint3 &p, bool onSurface,
                                   bool convTestXYZ) const
{
  GPoint gp = closestPoint(p, 1e-6);
  return SPoint2(gp.u(), gp.v());
}

Range<double> discreteFace::parBounds(int i) const
{
  if(i == 0)
    return Range<double>(_param.umin, _param.umax);
  else
    return Range<double>(_param.vmin, _param.vmax);
}

bool discreteFace::containsParam(const SPoint2 &pt)
{
  if(_param.empty()) return false;
  if(_findUniqueInteriorUvTriangle(pt.x(), pt.y())) return true;
  if(_param.oct->find(pt.x(), pt.y(), 0.0, -1, true)) return true;
  return false;
}

SBoundingBox3d discreteFace::bounds(bool fast)
{
  if(_param.empty()) return GFace::bounds(fast);
  return _param.bbox;
}

SVector3 discreteFace::normal(const SPoint2 &param) const
{
  if(_param.empty()) return SVector3();

  const MTriangle *triangle2d =
    _findUniqueInteriorUvTriangle(param.x(), param.y());
  MElement *e = const_cast<MTriangle *>(triangle2d);
  if(!e)
    e = _param.oct->find(param.x(), param.y(), 0.0, -1, true);
  if(!e) {
    Msg::Debug("Triangle not found at uv=(%g,%g) on discrete surface %d",
              param.x(), param.y(), tag());
    return SVector3(0, 0, 1);
  }
  int position = (int)((MTriangle *)e - &_param.t2d[0]);
  if(position >= 0 &&
     static_cast<std::size_t>(position) <
       _param.triangleUnitNormals.size())
    return _param.triangleUnitNormals[static_cast<std::size_t>(position)];
  const MTriangle &t3d = _param.t3d[position];
  SVector3 v31(t3d.getVertex(2)->x() - t3d.getVertex(0)->x(),
               t3d.getVertex(2)->y() - t3d.getVertex(0)->y(),
               t3d.getVertex(2)->z() - t3d.getVertex(0)->z());
  SVector3 v21(t3d.getVertex(1)->x() - t3d.getVertex(0)->x(),
               t3d.getVertex(1)->y() - t3d.getVertex(0)->y(),
               t3d.getVertex(1)->z() - t3d.getVertex(0)->z());
  SVector3 n = crossprod(v21, v31);
  n.normalize();
  return n;
}

bool discreteFace::normalIfContainsParam(const SPoint2 &param,
                                         SVector3 &result) const
{
  if(_param.empty()) return false;
  const MTriangle *triangle2d =
    _findUniqueInteriorUvTriangle(param.x(), param.y());
  std::ptrdiff_t position = -1;
  if(triangle2d) {
    position = triangle2d - _param.t2d.data();
  }
  else {
    MElement *element =
      _param.oct->find(param.x(), param.y(), 0.0, -1, true);
    if(!element) return false;
    position = static_cast<MTriangle *>(element) - _param.t2d.data();
  }
  if(position < 0 ||
     static_cast<std::size_t>(position) >= _param.t3d.size())
    return false;
  if(static_cast<std::size_t>(position) <
     _param.triangleUnitNormals.size()) {
    result = _param.triangleUnitNormals[static_cast<std::size_t>(position)];
    return true;
  }
  const MTriangle &triangle = _param.t3d[position];
  const SVector3 first(
    triangle.getVertex(1)->x() - triangle.getVertex(0)->x(),
    triangle.getVertex(1)->y() - triangle.getVertex(0)->y(),
    triangle.getVertex(1)->z() - triangle.getVertex(0)->z());
  const SVector3 second(
    triangle.getVertex(2)->x() - triangle.getVertex(0)->x(),
    triangle.getVertex(2)->y() - triangle.getVertex(0)->y(),
    triangle.getVertex(2)->z() - triangle.getVertex(0)->z());
  result = crossprod(first, second);
  result.normalize();
  return true;
}

bool discreteFace::normalBoundsForParametricTriangle(
  const SPoint2 &first, const SPoint2 &second, const SPoint2 &third,
  SVector3 &minimumNormal, SVector3 &maximumNormal) const
{
  if(_param.empty() ||
     _param.triangleUnitNormals.size() != _param.t2d.size() ||
     !std::isfinite(first.x()) || !std::isfinite(first.y()) ||
     !std::isfinite(second.x()) || !std::isfinite(second.y()) ||
     !std::isfinite(third.x()) || !std::isfinite(third.y()))
    return false;

  const double minimum[2] = {
    std::min({first.x(), second.x(), third.x()}),
    std::min({first.y(), second.y(), third.y()})};
  const double maximum[2] = {
    std::max({first.x(), second.x(), third.x()}),
    std::max({first.y(), second.y(), third.y()})};

  double lower[3] = {
    std::numeric_limits<double>::max(),
    std::numeric_limits<double>::max(),
    std::numeric_limits<double>::max()};
  double upper[3] = {
    -std::numeric_limits<double>::max(),
    -std::numeric_limits<double>::max(),
    -std::numeric_limits<double>::max()};
  bool found = false;
  for(std::size_t position = 0; position < _param.t2d.size(); ++position) {
    const MTriangle &triangle = _param.t2d[position];
    double triangleMinimum[2] = {
      std::numeric_limits<double>::max(),
      std::numeric_limits<double>::max()};
    double triangleMaximum[2] = {
      -std::numeric_limits<double>::max(),
      -std::numeric_limits<double>::max()};
    for(int vertex = 0; vertex < 3; ++vertex) {
      triangleMinimum[0] = std::min(
        triangleMinimum[0], triangle.getVertex(vertex)->x());
      triangleMinimum[1] = std::min(
        triangleMinimum[1], triangle.getVertex(vertex)->y());
      triangleMaximum[0] = std::max(
        triangleMaximum[0], triangle.getVertex(vertex)->x());
      triangleMaximum[1] = std::max(
        triangleMaximum[1], triangle.getVertex(vertex)->y());
    }
    if(triangleMaximum[0] < minimum[0] ||
       triangleMinimum[0] > maximum[0] ||
       triangleMaximum[1] < minimum[1] ||
       triangleMinimum[1] > maximum[1])
      continue;

    const SVector3 &normal = _param.triangleUnitNormals[position];
    const double norm = normal.norm();
    if(!std::isfinite(normal.x()) || !std::isfinite(normal.y()) ||
       !std::isfinite(normal.z()) || !std::isfinite(norm) || !(norm > 0.))
      continue;
    for(int component = 0; component < 3; ++component) {
      lower[component] = std::min(lower[component], normal[component]);
      upper[component] = std::max(upper[component], normal[component]);
    }
    found = true;
  }
  if(!found) return false;
  minimumNormal = SVector3(lower);
  maximumNormal = SVector3(upper);
  return true;
}

double discreteFace::curvatureMax(const SPoint2 &param) const
{
  if(_param.empty()) return 0.;

  SVector3 dirMax, dirMin;
  double c, C;
  if(_param.CURV.empty()) return 0.0;
  curvatures(param, dirMax, dirMin, C, c);
  return std::max(c, C);
}

double discreteFace::curvatures(const SPoint2 &param, SVector3 &dirMax,
                                SVector3 &dirMin, double &curvMax,
                                double &curvMin) const
{
  if(_param.empty()) return 0.;
  if(_param.CURV.empty()) return 0.0;

  MElement *e = _param.oct->find(param.x(), param.y(), 0.0, -1, true);
  if(!e) {
    Msg::Info("Triangle not found for curvatures at uv=(%g,%g) on "
              "discrete surface %d",
              param.x(), param.y(), tag());
    return 0.0;
  }

  int position = (int)((MTriangle *)e - &_param.t2d[0]);

  SVector3 c0max = _param.CURV[6 * position + 0];
  SVector3 c1max = _param.CURV[6 * position + 1];
  SVector3 c2max = _param.CURV[6 * position + 2];
  SVector3 c0min = _param.CURV[6 * position + 3];
  SVector3 c1min = _param.CURV[6 * position + 4];
  SVector3 c2min = _param.CURV[6 * position + 5];

  curvMax = c0max.norm();
  curvMin = c0min.norm();

  dirMax = c0max.normalize();
  dirMin = c0min.normalize();

  return false;
}

std::pair<SVector3, SVector3> discreteFace::firstDer(const SPoint2 &param) const
{
  if(_param.empty()) return std::make_pair(SVector3(), SVector3());

  MElement *e = _param.oct->find(param.x(), param.y(), 0.0, -1, true);
  if(!e) {
    Msg::Info("Triangle not found for first derivative at uv=(%g,%g) on "
              "discrete surface %d",
              param.x(), param.y(), tag());
    return std::make_pair(SVector3(1, 0, 0), SVector3(0, 1, 0));
  }

  int position = (int)((MTriangle *)e - &_param.t2d[0]);

  const MTriangle &t3d = _param.t3d[position];
  const MVertex *v1 = t3d.getVertex(0);
  const MVertex *v2 = t3d.getVertex(1);
  const MVertex *v3 = t3d.getVertex(2);

  double M3D[3][2] = {{v2->x() - v1->x(), v3->x() - v1->x()},
                      {v2->y() - v1->y(), v3->y() - v1->y()},
                      {v2->z() - v1->z(), v3->z() - v1->z()}};
  v1 = e->getVertex(0);
  v2 = e->getVertex(1);
  v3 = e->getVertex(2);

  double M2D[2][2] = {{(v3->y() - v1->y()), -(v3->x() - v1->x())},
                      {-(v2->y() - v1->y()), (v2->x() - v1->x())}};

  double det = 1. / (M2D[0][0] * M2D[1][1] - M2D[1][0] * M2D[0][1]);

  double dxdu[3][2];

  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 2; j++) {
      dxdu[i][j] = 0.;
      for(int k = 0; k < 2; k++) { dxdu[i][j] += det * M3D[i][k] * M2D[k][j]; }
    }
  }

  return std::make_pair(SVector3(dxdu[0][0], dxdu[1][0], dxdu[2][0]),
                        SVector3(dxdu[0][1], dxdu[1][1], dxdu[2][1]));
}

void discreteFace::secondDer(const SPoint2 &param, SVector3 &dudu,
                             SVector3 &dvdv, SVector3 &dudv) const
{
  return;
}

void discreteFace::_debugParametrization(bool uv)
{
  char tmp[256];
  sprintf(tmp, "discrete_param_%d.pos", tag());
  FILE *fp = fopen(tmp, "w");
  if(fp) {
    fprintf(fp, "View \"uv\" {\n");
    for(std::size_t i = 0; i < stl_triangles.size(); i += 3) {
      int i0 = stl_triangles[i + 0];
      int i1 = stl_triangles[i + 1];
      int i2 = stl_triangles[i + 2];
      SPoint3 xyz0 = stl_vertices_xyz[i0];
      SPoint3 xyz1 = stl_vertices_xyz[i1];
      SPoint3 xyz2 = stl_vertices_xyz[i2];
      SPoint2 uv0 = stl_vertices_uv[i0];
      SPoint2 uv1 = stl_vertices_uv[i1];
      SPoint2 uv2 = stl_vertices_uv[i2];
      if(uv) {
        for(int j = 0; j < 2; j++) {
          xyz0[j] = uv0[j];
          xyz1[j] = uv1[j];
          xyz2[j] = uv2[j];
        }
        xyz0[2] = xyz1[2] = xyz2[2] = 0;
      }
      fprintf(fp, "ST(%g,%g,%g, %g,%g,%g, %g,%g,%g){%g,%g,%g, %g,%g,%g};\n",
              xyz0.x(), xyz0.y(), xyz0.z(), xyz1.x(), xyz1.y(), xyz1.z(),
              xyz2.x(), xyz2.y(), xyz2.z(), uv0.x(), uv1.x(), uv2.x(), uv0.y(),
              uv1.y(), uv2.y());
    }
    fprintf(fp, "};\n");
    fclose(fp);
  }
}

void intrinsicDelaunayize(discreteFace *df)
{
#if defined(HAVE_EIGEN) && defined(HAVE_GEOMETRYCENTRAL)

  char name[245];
  sprintf(name, "intrinsic%d.pos", df->tag());
  FILE *ff = fopen(name, "w");
  fprintf(ff, "View \"\"{\n");

  Eigen::MatrixXi triangles(df->triangles.size(), 3);
  std::vector<geometrycentral::Vector3> vertexCoordinates;
  for(auto t : df->triangles) {
    t->getVertex(0)->setIndex(-1);
    t->getVertex(1)->setIndex(-1);
    t->getVertex(2)->setIndex(-1);
  }
  int index = 0;
  for(auto t : df->triangles) {
    for(int i = 0; i < 3; i++) {
      if(t->getVertex(i)->getIndex() == -1) {
        geometrycentral::Vector3 p = {
          t->getVertex(i)->x(), t->getVertex(i)->y(), t->getVertex(i)->z()};
        vertexCoordinates.push_back(p);
        t->getVertex(i)->setIndex(index++);
      }
    }
  }
  Eigen::MatrixXd positions(vertexCoordinates.size(), 3);
  for(size_t i = 0; i < vertexCoordinates.size(); i++) {
    positions(i, 0) = vertexCoordinates[i].x;
    positions(i, 1) = vertexCoordinates[i].y;
    positions(i, 2) = vertexCoordinates[i].z;
  }

  int T = 0;
  for(auto t : df->triangles) {
    for(int i = 0; i < 3; i++) triangles(T, i) = t->getVertex(i)->getIndex();
    T++;
  }
  geometrycentral::surface::ManifoldSurfaceMesh msm(triangles);

  printf("isManifold %d\n", msm.isManifold());
  printf("isOriented %d\n", msm.isOriented());
  printf("nVertices %zu\n", msm.nVertices());
  printf("nCorners %zu\n", msm.nCorners());
  printf("nInteriorVertices %zu\n", msm.nInteriorVertices());

  geometrycentral::surface::VertexPositionGeometry vpg(msm, positions);

  geometrycentral::surface::SignpostIntrinsicTriangulation signpostTri(msm,
                                                                       vpg);

  signpostTri.flipToDelaunay();

  signpostTri.delaunayRefine();
  printf("-->nVertices %zu %zu\n", signpostTri.intrinsicMesh->nVertices(),
         signpostTri.mesh.nVertices());

  signpostTri.requireVertexIndices();

  size_t nV = signpostTri.mesh.nVertices();
  size_t nF = signpostTri.mesh.nFaces();

  Eigen::MatrixXd vertexPositions(nV, 3);
  Eigen::MatrixXi faceInds(nF, 3);

  size_t iF = 0;
  for(geometrycentral::surface::Face f : signpostTri.mesh.faces()) {
    geometrycentral::surface::Halfedge he = f.halfedge();
    for(int v = 0; v < 3; v++) {
      geometrycentral::surface::Vertex vA = he.vertex();
      size_t indA = signpostTri.vertexIndices[vA];
      faceInds(iF, v) = indA;
      he = he.next();
    }
    iF++;
  }

  size_t iV = 0;
  for(geometrycentral::surface::Vertex v : signpostTri.mesh.vertices()) {
    geometrycentral::Vector3 pos =
      signpostTri.vertexLocations[v].interpolate(vpg.inputVertexPositions);
    vertexPositions(iV, 0) = pos.x;
    vertexPositions(iV, 1) = pos.y;
    vertexPositions(iV, 2) = pos.z;
    iV++;
  }

  for(int i = 0; i < nF; i++) {
    int id0 = faceInds(i, 0);
    int id1 = faceInds(i, 1);
    int id2 = faceInds(i, 2);
    fprintf(ff, "ST(%lg,%lg,%lg,%lg,%lg,%lg,%lg,%lg,%lg){%d,%d,%d};\n",
            vertexPositions(id0, 0), vertexPositions(id0, 1),
            vertexPositions(id0, 2), vertexPositions(id1, 0),
            vertexPositions(id1, 1), vertexPositions(id1, 2),
            vertexPositions(id2, 0), vertexPositions(id2, 1),
            vertexPositions(id2, 2), df->tag(), df->tag(), df->tag());
  }

  fprintf(ff, "};\n");
  fclose(ff);

#endif
}

int discreteFace::createGeometry()
{
  stl_vertices_uv.clear();
  stl_vertices_xyz.clear();
  stl_curvatures.clear();
  stl_triangles.clear();
  if(triangles.empty()) return 0;

  //  intrinsicDelaunayize(this);

  double minq = 1.;
  for(auto t : triangles) minq = std::min(minq, t->gammaShapeMeasure());
  if(minq < 1e-3)
    Msg::Warning("Poor input mesh quality (min gamma = %g) for computing "
                 "parametrization",
                 minq);

  std::vector<MVertex *> nodes;
  computeParametrization(triangles, nodes, stl_vertices_uv, stl_vertices_xyz,
                         stl_triangles);

  if(model()->getCurvatures().size()) {
    stl_curvatures.resize(2 * nodes.size());
    for(std::size_t i = 0; i < nodes.size(); i++) {
      auto it = model()->getCurvatures().find(nodes[i]);
      if(it == model()->getCurvatures().end()) {
        Msg::Error("Curvature not found for node %d", nodes[i]->getNum());
      }
      else {
        stl_curvatures[2 * i] = it->second.first;
        stl_curvatures[2 * i + 1] = it->second.second;
      }
    }
  }

  _computeSTLNormals();
  _createGeometryFromSTL();

  //_debugParametrization(false);

  return 0;
}

void discreteFace::_computeSTLNormals()
{
  stl_normals.clear();
  std::size_t T = stl_triangles.size() / 3;
  std::size_t N = stl_vertices_xyz.size();
  if(!N || !T) return;
  stl_normals.resize(N);
  for(std::size_t i = 0; i < T; i++) {
    int a = stl_triangles[3 * i + 0];
    int b = stl_triangles[3 * i + 1];
    int c = stl_triangles[3 * i + 2];
    SPoint3 pa(stl_vertices_xyz[a]);
    SPoint3 pb(stl_vertices_xyz[b]);
    SPoint3 pc(stl_vertices_xyz[c]);
    SVector3 vba = pb - pa;
    SVector3 vca = pc - pa;
    SVector3 n = crossprod(vba, vca);
    stl_normals[a] += n;
    stl_normals[b] += n;
    stl_normals[c] += n;
  }
  for(std::size_t i = 0; i < N; i++) stl_normals[i].normalize();
}

void discreteFace::_createGeometryFromSTL()
{
  if(stl_triangles.empty() || stl_vertices_uv.empty() ||
     stl_vertices_xyz.empty())
    return;

  std::lock_guard<std::mutex> lock(_param.libolMutex);
  _param.clear();

  for(size_t i = 0; i < stl_vertices_uv.size(); i++) {
    _param.v2d.push_back(
      MVertex(stl_vertices_uv[i].x(), stl_vertices_uv[i].y(), 0.0));
    _param.v3d.push_back(MVertex(stl_vertices_xyz[i].x(),
                                 stl_vertices_xyz[i].y(),
                                 stl_vertices_xyz[i].z()));
    _param.bbox += _param.v3d.back().point();
  }

  for(size_t i = 0; i < stl_triangles.size() / 3; i++) {
    int a = stl_triangles[3 * i];
    int b = stl_triangles[3 * i + 1];
    int c = stl_triangles[3 * i + 2];
    _param.t2d.push_back(
      MTriangle(&_param.v2d[a], &_param.v2d[b], &_param.v2d[c]));
    _param.t3d.push_back(
      MTriangle(&_param.v3d[a], &_param.v3d[b], &_param.v3d[c]));
    if(!stl_curvatures.empty()) {
      _param.CURV.push_back(stl_curvatures[2 * a]);
      _param.CURV.push_back(stl_curvatures[2 * a + 1]);
      _param.CURV.push_back(stl_curvatures[2 * b]);
      _param.CURV.push_back(stl_curvatures[2 * b + 1]);
      _param.CURV.push_back(stl_curvatures[2 * c]);
      _param.CURV.push_back(stl_curvatures[2 * c + 1]);
    }
  }
  _param.triangleUnitNormals.reserve(_param.t3d.size());
  for(const MTriangle &triangle : _param.t3d) {
    const SVector3 first(
      triangle.getVertex(1)->x() - triangle.getVertex(0)->x(),
      triangle.getVertex(1)->y() - triangle.getVertex(0)->y(),
      triangle.getVertex(1)->z() - triangle.getVertex(0)->z());
    const SVector3 second(
      triangle.getVertex(2)->x() - triangle.getVertex(0)->x(),
      triangle.getVertex(2)->y() - triangle.getVertex(0)->y(),
      triangle.getVertex(2)->z() - triangle.getVertex(0)->z());
    SVector3 normal = crossprod(first, second);
    normal.normalize();
    _param.triangleUnitNormals.push_back(normal);
  }
  if(_param.checkPlanar())
    Msg::Info("Discrete surface %d is planar, simplifying parametrization",
              tag());

  _buildTriangleBvh();

  std::vector<MElement *> temp;
  for(size_t j = 0; j < _param.t2d.size(); j++) {
    temp.push_back(&_param.t2d[j]);
    double MIN[3] = {_param.t3d[j].getVertex(0)->x(),
                     _param.t3d[j].getVertex(0)->y(),
                     _param.t3d[j].getVertex(0)->z()};
    double MAX[3] = {_param.t3d[j].getVertex(0)->x(),
                     _param.t3d[j].getVertex(0)->y(),
                     _param.t3d[j].getVertex(0)->z()};
    for(int k = 1; k < 3; k++) {
      MAX[0] = std::max(MAX[0], _param.t3d[j].getVertex(k)->x());
      MIN[0] = std::min(MIN[0], _param.t3d[j].getVertex(k)->x());
      MAX[1] = std::max(MAX[1], _param.t3d[j].getVertex(k)->y());
      MIN[1] = std::min(MIN[1], _param.t3d[j].getVertex(k)->y());
      MAX[2] = std::max(MAX[2], _param.t3d[j].getVertex(k)->z());
      MIN[2] = std::min(MIN[2], _param.t3d[j].getVertex(k)->z());
    }
    _param.rtree3dData.push_back
      (new std::pair<MTriangle *, MTriangle *>(&_param.t3d[j], &_param.t2d[j]));
    _param.rtree3d.Insert(MIN, MAX, _param.rtree3dData.back());
  }
  _param.oct = new MElementOctree(temp);
  _buildUvTriangleGrid();

  // Keep the legacy R-tree above and build a second, true nearest-neighbour
  // index for exact and inexpensive projections. LibOL stores pointers to the
  // supplied arrays, hence these flat buffers live in _param for the complete
  // lifetime of the octree. Exactly degenerate triangles are left out because
  // LibOL computes a facet aspect ratio while constructing its index.
  if(_param.v3d.size() <=
       static_cast<std::size_t>(std::numeric_limits<int32_t>::max()) &&
     _param.t3d.size() <=
       static_cast<std::size_t>(std::numeric_limits<int32_t>::max())) {
    _param.libolVertexCoordinates.reserve(3 * _param.v3d.size());
    bool finiteVertices = true;
    for(const MVertex &vertex : _param.v3d) {
      finiteVertices = finiteVertices && std::isfinite(vertex.x()) &&
        std::isfinite(vertex.y()) && std::isfinite(vertex.z());
      _param.libolVertexCoordinates.push_back(vertex.x());
      _param.libolVertexCoordinates.push_back(vertex.y());
      _param.libolVertexCoordinates.push_back(vertex.z());
    }
    _param.libolTriangles.reserve(3 * _param.t3d.size());
    _param.libolTriangleToParam.reserve(_param.t3d.size());
    _param.libolDegenerateTrianglePositions.reserve(
      std::min<std::size_t>(_param.t3d.size(), 16));
    if(finiteVertices) {
      for(std::size_t i = 0; i < stl_triangles.size() / 3; ++i) {
        const MTriangle &triangle = _param.t3d[i];
        const SVector3 first = triangle.getVertex(1)->point() -
          triangle.getVertex(0)->point();
        const SVector3 second = triangle.getVertex(2)->point() -
          triangle.getVertex(0)->point();
        const SVector3 triangleNormal = crossprod(first, second);
        const double squaredNorm = dot(triangleNormal, triangleNormal);
        if(!std::isfinite(squaredNorm) ||
           squaredNorm < std::numeric_limits<double>::min()) {
          _param.libolDegenerateTrianglePositions.push_back(i);
          continue;
        }
        _param.libolTriangles.push_back(stl_triangles[3 * i] + 1);
        _param.libolTriangles.push_back(stl_triangles[3 * i + 1] + 1);
        _param.libolTriangles.push_back(stl_triangles[3 * i + 2] + 1);
        _param.libolTriangleToParam.push_back(i);
      }
    }
    if(finiteVertices && !_param.libolVertexCoordinates.empty() &&
       !_param.libolTriangles.empty()) {
      _param.libolOctree = LolNewOctree(
        static_cast<int32_t>(_param.libolVertexCoordinates.size() / 3),
        _param.libolVertexCoordinates.data(),
        _param.libolVertexCoordinates.data() + 3, 0, nullptr, nullptr,
        static_cast<int32_t>(_param.libolTriangles.size() / 3),
        _param.libolTriangles.data(), _param.libolTriangles.data() + 3, 0,
        nullptr, nullptr, 0, nullptr, nullptr, 0, nullptr, nullptr, 0,
        nullptr, nullptr, 0, nullptr, nullptr, 1, 1);
    }
  }
}

void discreteFace::mesh(bool verbose)
{
  if(_param.empty()) return;
  GFace::mesh(verbose);
}

GPoint discreteFace::intersectionWithCircle(const SVector3 &n1,
                                            const SVector3 &n2,
                                            const SVector3 &p, const double &R,
                                            double uv[2])
{
  if(_param.empty()) return 0.;

  MTriangle *t2d = (MTriangle *)_param.oct->find(uv[0], uv[1], 0.0, -1, true);
  MTriangle *t3d = nullptr;
  if(t2d) {
    int position = (int)(t2d - &_param.t2d[0]);
    t3d = &_param.t3d[position];
  }

  SVector3 n = crossprod(n1, n2);
  n.normalize();

  int N = _param.t3d.size();
  int start = 0;
  if(t2d) start = -1;
  for(int i = start; i < N; i++) {
    if(i >= 0) {
      t2d = &_param.t2d[i];
      t3d = &_param.t3d[i];
    }
    SVector3 v0(t3d->getVertex(0)->x(), t3d->getVertex(0)->y(),
                t3d->getVertex(0)->z());
    SVector3 v1(t3d->getVertex(1)->x(), t3d->getVertex(1)->y(),
                t3d->getVertex(1)->z());
    SVector3 v2(t3d->getVertex(2)->x(), t3d->getVertex(2)->y(),
                t3d->getVertex(2)->z());
    SVector3 v0_2d(t2d->getVertex(0)->x(), t2d->getVertex(0)->y(),
                   t2d->getVertex(0)->z());
    SVector3 v1_2d(t2d->getVertex(1)->x(), t2d->getVertex(1)->y(),
                   t2d->getVertex(1)->z());
    SVector3 v2_2d(t2d->getVertex(2)->x(), t2d->getVertex(2)->y(),
                   t2d->getVertex(2)->z());
    SVector3 t1 = v1 - v0;
    SVector3 t2 = v2 - v0;
    SVector3 t = crossprod(t1, t2);
    t.normalize();
    SVector3 d = crossprod(n, t);
    if(d.norm() < 1.e-12) continue;
    d.normalize();
    double rhs[2] = {dot(n, p), dot(v0, t)};
    double r[2];
    double m[2][2];
    SVector3 x0(0, 0, 0);
    m[0][0] = n.y();
    m[0][1] = n.z();
    m[1][0] = t.y();
    m[1][1] = t.z();
    if(fabs(det2x2(m)) > 1.e-12) {
      sys2x2(m, rhs, r);
      x0 = SVector3(0, r[0], r[1]);
    }
    else {
      m[0][0] = n.x();
      m[0][1] = n.z();
      m[1][0] = t.x();
      m[1][1] = t.z();
      if(fabs(det2x2(m)) > 1.e-12) {
        sys2x2(m, rhs, r);
        x0 = SVector3(r[0], 0, r[1]);
      }
      else {
        m[0][0] = n.x();
        m[0][1] = n.y();
        m[1][0] = t.x();
        m[1][1] = t.y();
        if(sys2x2(m, rhs, r)) { x0 = SVector3(r[0], r[1], 0); }
        else {
          // printf("mauvaise pioche\n");
          continue;
        }
      }
    }

    const double a = 1.0;
    const double b = -2 * dot(d, p - x0);
    const double c = dot(p - x0, p - x0) - R * R;
    const double delta = b * b - 4 * a * c;
    if(delta >= 0) {
      double sign = (dot(n2, d) > 0) ? 1.0 : -1.0;
      const double ta = (-b + sign * sqrt(delta)) / (2. * a);
      const double tb = (-b - sign * sqrt(delta)) / (2. * a);
      SVector3 s[2] = {x0 + d * ta, x0 + d * tb};
      for(int IT = 0; IT < 2; IT++) {
        double mat[2][2], b[2], uv[2];
        mat[0][0] = dot(t1, t1);
        mat[1][1] = dot(t2, t2);
        mat[0][1] = mat[1][0] = dot(t1, t2);
        b[0] = dot(s[IT] - v0, t1);
        b[1] = dot(s[IT] - v0, t2);
        sys2x2(mat, b, uv);
        // check now if the point is inside the triangle
        if(uv[0] >= -1.e-6 && uv[1] >= -1.e-6 && 1. - uv[0] - uv[1] >= -1.e-6) {
          SVector3 pp =
            v0_2d * (1. - uv[0] - uv[1]) + v1_2d * uv[0] + v2_2d * uv[1];
          uv[0] = pp.x();
          uv[1] = pp.y();
          return GPoint(s[IT].x(), s[IT].y(), s[IT].z(), this, uv);
        }
      }
    }
  }

  GPoint pp(0);
  pp.setNoSuccess();
  // Msg::Warning("Could not intersect with circle");
  return pp;
}

GPoint discreteFace::intersectionWithCircleSpatial(const SVector3 &n1,
                                                   const SVector3 &n2,
                                                   const SVector3 &p,
                                                   const double &R,
                                                   double uv[2])
{
  auto failure = []() {
    GPoint result(0.0);
    result.setNoSuccess();
    return result;
  };
  if(_param.empty() || R <= 0.0) return failure();

  // Keep the fast frontal estimate: when it lies just outside the
  // parametrized domain there is no seed triangle, and selecting the first
  // circle intersection in source-triangle order can jump to another fold of
  // the discrete surface. Use this estimate to rank all spatial candidates.
  const double estimatedUV[2] = {uv[0], uv[1]};

  SVector3 circleNormal = crossprod(n1, n2);
  if(circleNormal.normalize() <= 1.e-14) return failure();

  MTriangle *seed2d =
    (MTriangle *)_param.oct->find(uv[0], uv[1], 0.0, -1, true);
  MTriangle *seed3d = nullptr;
  if(seed2d) {
    const std::ptrdiff_t position = seed2d - &_param.t2d[0];
    if(position >= 0 && (std::size_t)position < _param.t3d.size())
      seed3d = &_param.t3d[(std::size_t)position];
  }

  // Every possible solution belongs to the 3D AABB of the complete circle.
  // Query the R-tree already built for closestPoint() instead of scanning all
  // parametrization triangles. The L1 extent is slightly conservative even
  // if the supplied circle basis is not perfectly orthonormal.
  const double scale = std::max(1.0, _param.bbox.diag());
  const double padding = std::max(1.e-12 * scale, 1.e-10 * std::abs(R));
  double minimum[3], maximum[3];
  for(int component = 0; component < 3; component++) {
    const double extent =
      std::abs(R) *
        (std::abs(n1[component]) + std::abs(n2[component])) +
      padding;
    minimum[component] = p[component] - extent;
    maximum[component] = p[component] + extent;
  }
  dfCircleCandidates candidates;
  _param.rtree3d.Search(minimum, maximum,
                        discreteFace_circle_rtree_callback, &candidates);

  const MTriangle *const triangleBase = &_param.t3d[0];
  std::sort(candidates.triangles.begin(), candidates.triangles.end(),
            [triangleBase](const auto *first, const auto *second) {
              return first->first - triangleBase <
                     second->first - triangleBase;
            });
  candidates.triangles.erase(
    std::unique(candidates.triangles.begin(), candidates.triangles.end()),
    candidates.triangles.end());

  auto intersectTriangle = [&](MTriangle *t3d, MTriangle *t2d,
                               GPoint &result, double resultUV[2],
                               double &distance2) {
    const SVector3 v0(t3d->getVertex(0)->x(), t3d->getVertex(0)->y(),
                      t3d->getVertex(0)->z());
    const SVector3 v1(t3d->getVertex(1)->x(), t3d->getVertex(1)->y(),
                      t3d->getVertex(1)->z());
    const SVector3 v2(t3d->getVertex(2)->x(), t3d->getVertex(2)->y(),
                      t3d->getVertex(2)->z());
    const SVector3 edge1 = v1 - v0;
    const SVector3 edge2 = v2 - v0;
    SVector3 triangleNormal = crossprod(edge1, edge2);
    if(triangleNormal.normalize() <= 1.e-14) return false;

    const SVector3 lineDirection =
      crossprod(circleNormal, triangleNormal);
    const double lineNorm2 = lineDirection.normSq();
    if(lineNorm2 <= 1.e-24) return false;

    // A point on the intersection of n.x=n.p and t.x=t.v0. This vector form
    // replaces the three coordinate-dependent 2x2 solves in the legacy code.
    const double circlePlane = dot(circleNormal, p);
    const double trianglePlane = dot(triangleNormal, v0);
    const SVector3 lineOrigin =
      (circlePlane * crossprod(triangleNormal, lineDirection) +
       trianglePlane * crossprod(lineDirection, circleNormal)) *
      (1.0 / lineNorm2);
    const SVector3 closest =
      lineOrigin + lineDirection *
                     (dot(p - lineOrigin, lineDirection) / lineNorm2);
    double height2 = R * R - (closest - p).normSq();
    const double discriminantTolerance =
      1.e-12 * std::max(R * R, scale * scale);
    if(height2 < -discriminantTolerance) return false;
    height2 = std::max(0.0, height2);

    const double gram00 = dot(edge1, edge1);
    const double gram01 = dot(edge1, edge2);
    const double gram11 = dot(edge2, edge2);
    const double gramDet = gram00 * gram11 - gram01 * gram01;
    if(gramDet <= 1.e-28 * std::max(1.0, gram00 * gram11)) return false;

    const double rootScale = std::sqrt(height2 / lineNorm2);
    const double preferredSign = dot(n2, lineDirection) >= 0.0 ? 1.0 : -1.0;
    const SVector3 points[2] = {
      closest + lineDirection * (preferredSign * rootScale),
      closest - lineDirection * (preferredSign * rootScale)};
    bool found = false;
    for(const SVector3 &point : points) {
      const double rhs0 = dot(point - v0, edge1);
      const double rhs1 = dot(point - v0, edge2);
      const double bary1 = (rhs0 * gram11 - gram01 * rhs1) / gramDet;
      const double bary2 = (gram00 * rhs1 - gram01 * rhs0) / gramDet;
      if(bary1 < -1.e-6 || bary2 < -1.e-6 ||
         1.0 - bary1 - bary2 < -1.e-6)
        continue;

      const MVertex *uv0 = t2d->getVertex(0);
      const MVertex *uv1 = t2d->getVertex(1);
      const MVertex *uv2 = t2d->getVertex(2);
      const double candidateUV[2] = {
        uv0->x() * (1.0 - bary1 - bary2) + uv1->x() * bary1 +
          uv2->x() * bary2,
        uv0->y() * (1.0 - bary1 - bary2) + uv1->y() * bary1 +
          uv2->y() * bary2};
      const double du = candidateUV[0] - estimatedUV[0];
      const double dv = candidateUV[1] - estimatedUV[1];
      const double candidateDistance2 = du * du + dv * dv;
      if(!found || candidateDistance2 < distance2) {
        distance2 = candidateDistance2;
        resultUV[0] = candidateUV[0];
        resultUV[1] = candidateUV[1];
        result = GPoint(point.x(), point.y(), point.z(), this, resultUV);
        found = true;
      }
    }
    return found;
  };

  GPoint result;
  double resultUV[2], distance2 = std::numeric_limits<double>::max();
  if(seed3d &&
     intersectTriangle(seed3d, seed2d, result, resultUV, distance2)) {
    uv[0] = resultUV[0];
    uv[1] = resultUV[1];
    return result;
  }

  GPoint best;
  double bestUV[2] = {0.0, 0.0};
  double bestDistance2 = std::numeric_limits<double>::max();
  for(const auto *candidate : candidates.triangles) {
    if(candidate->first == seed3d) continue;
    double candidateUV[2];
    double candidateDistance2 = std::numeric_limits<double>::max();
    if(intersectTriangle(candidate->first, candidate->second, result,
                         candidateUV, candidateDistance2) &&
       candidateDistance2 < bestDistance2) {
      best = result;
      bestUV[0] = candidateUV[0];
      bestUV[1] = candidateUV[1];
      bestDistance2 = candidateDistance2;
    }
  }
  if(bestDistance2 < std::numeric_limits<double>::max()) {
    uv[0] = bestUV[0];
    uv[1] = bestUV[1];
    return best;
  }
  return failure();
}

bool discreteFace::writeParametrization(FILE *fp, bool binary)
{
  std::size_t N = stl_vertices_uv.size();
  std::size_t T = stl_triangles.size() / 3;
  std::vector<double> d(11 * N, 0.);
  for(std::size_t i = 0; i < N; i++) {
    d[11 * i + 0] = stl_vertices_xyz[i].x();
    d[11 * i + 1] = stl_vertices_xyz[i].y();
    d[11 * i + 2] = stl_vertices_xyz[i].z();
    d[11 * i + 3] = stl_vertices_uv[i].x();
    d[11 * i + 4] = stl_vertices_uv[i].y();
    if(stl_curvatures.size() == 2 * stl_vertices_uv.size()) {
      d[11 * i + 5] = stl_curvatures[2 * i].x();
      d[11 * i + 6] = stl_curvatures[2 * i].y();
      d[11 * i + 7] = stl_curvatures[2 * i].z();
      d[11 * i + 8] = stl_curvatures[2 * i + 1].x();
      d[11 * i + 9] = stl_curvatures[2 * i + 1].y();
      d[11 * i + 10] = stl_curvatures[2 * i + 1].z();
    }
  }
  if(binary) {
    fwrite(&N, sizeof(std::size_t), 1, fp);
    fwrite(&T, sizeof(std::size_t), 1, fp);
    fwrite(&d[0], sizeof(double), d.size(), fp);
    fwrite(&stl_triangles[0], sizeof(int), stl_triangles.size(), fp);
  }
  else {
    fprintf(fp, "%zu %zu\n", N, T);
    for(std::size_t i = 0; i < N; i++)
      fprintf(fp,
              "%.16g %.16g %.16g %.16g %.16g %.16g %.16g "
              "%.16g %.16g %.16g %.16g\n",
              d[11 * i + 0], d[11 * i + 1], d[11 * i + 2], d[11 * i + 3],
              d[11 * i + 4], d[11 * i + 5], d[11 * i + 6], d[11 * i + 7],
              d[11 * i + 8], d[11 * i + 9], d[11 * i + 10]);
    for(std::size_t i = 0; i < T; i++) {
      fprintf(fp, "%d %d %d\n", stl_triangles[3 * i + 0],
              stl_triangles[3 * i + 1], stl_triangles[3 * i + 2]);
    }
  }
  return true;
}

bool discreteFace::readParametrization(FILE *fp, bool binary)
{
  _coincidentVertexParameters.clear();
  stl_vertices_xyz.clear();
  stl_vertices_uv.clear();
  stl_curvatures.clear();
  stl_triangles.clear();

  std::size_t N, T;
  if(binary) {
    if(fread(&N, sizeof(std::size_t), 1, fp) != 1) { return false; }
    if(fread(&T, sizeof(std::size_t), 1, fp) != 1) { return false; }
  }
  else {
    if(fscanf(fp, "%zu %zu", &N, &T) != 2) { return false; }
  }
  std::vector<double> d(11 * N);
  stl_vertices_xyz.resize(N);
  stl_vertices_uv.resize(N);
  stl_curvatures.resize(2 * N);
  stl_triangles.resize(3 * T);

  if(binary) {
    if(fread(&d[0], sizeof(double), 11 * N, fp) != 11 * N) { return false; }
    if(fread(&stl_triangles[0], sizeof(int), 3 * T, fp) != 3 * T) {
      return false;
    }
  }
  else {
    for(std::size_t i = 0; i < N; i++) {
      if(fscanf(fp, "%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf",
                &d[11 * i + 0], &d[11 * i + 1], &d[11 * i + 2], &d[11 * i + 3],
                &d[11 * i + 4], &d[11 * i + 5], &d[11 * i + 6], &d[11 * i + 7],
                &d[11 * i + 8], &d[11 * i + 9], &d[11 * i + 10]) != 11) {
        return false;
      }
    }
    for(std::size_t i = 0; i < T; i++) {
      if(fscanf(fp, "%d %d %d", &stl_triangles[3 * i + 0],
                &stl_triangles[3 * i + 1], &stl_triangles[3 * i + 2]) != 3) {
        return false;
      }
    }
  }

  for(std::size_t i = 0; i < N; i++) {
    stl_vertices_xyz[i] = SPoint3(d[11 * i + 0], d[11 * i + 1], d[11 * i + 2]);
    stl_vertices_uv[i] = SPoint2(d[11 * i + 3], d[11 * i + 4]);
    stl_curvatures[2 * i + 0] =
      SVector3(d[11 * i + 5], d[11 * i + 6], d[11 * i + 7]);
    stl_curvatures[2 * i + 1] =
      SVector3(d[11 * i + 8], d[11 * i + 9], d[11 * i + 10]);
  }

  _computeSTLNormals();
  _createGeometryFromSTL();
  _buildCoincidentVertexParameters();
  return true;
}

void discreteFace::_buildCoincidentVertexParameters()
{
  _coincidentVertexParameters.clear();
  const std::size_t n = std::min(triangles.size(), stl_triangles.size() / 3);
  if(!n || stl_vertices_xyz.size() != stl_vertices_uv.size()) return;

  std::unordered_map<std::size_t, SPoint2> candidate;
  std::unordered_map<std::size_t, std::array<double, 3>> coordinates;
  std::unordered_set<std::size_t> inconsistent;
  for(std::size_t triangle = 0; triangle < n; ++triangle) {
    for(int corner = 0; corner < 3; ++corner) {
      MVertex *vertex = triangles[triangle]->getVertex(corner);
      if(!vertex->onWhat() || vertex->onWhat()->dim() >= 2) continue;
      const int local = stl_triangles[3 * triangle + corner];
      if(local < 0 || static_cast<std::size_t>(local) >= stl_vertices_xyz.size())
        continue;
      const SPoint3 &point = stl_vertices_xyz[local];
      const double dx = vertex->x() - point.x();
      const double dy = vertex->y() - point.y();
      const double dz = vertex->z() - point.z();
      const double scale = 1.0 + vertex->x() * vertex->x() +
                           vertex->y() * vertex->y() +
                           vertex->z() * vertex->z();
      // The element and parametrization triangle orders normally coincide.
      // If they do not, leave the generic closest-point path untouched.
      if(dx * dx + dy * dy + dz * dz > 1.e-24 * scale) continue;

      const std::size_t tag = vertex->getNum();
      if(inconsistent.count(tag)) continue;
      const SPoint2 uv = stl_vertices_uv[local];
      const auto inserted = candidate.emplace(tag, uv);
      if(!inserted.second) {
        const double du = inserted.first->second.x() - uv.x();
        const double dv = inserted.first->second.y() - uv.y();
        if(du * du + dv * dv > 1.e-18) {
          candidate.erase(inserted.first);
          inconsistent.insert(tag);
        }
      }
      coordinates[tag] = {{vertex->x(), vertex->y(), vertex->z()}};
    }
  }

  std::map<std::array<double, 3>, std::vector<std::size_t>> tagsByPoint;
  for(const auto &entry : coordinates)
    if(candidate.count(entry.first))
      tagsByPoint[entry.second].push_back(entry.first);
  for(const auto &entry : tagsByPoint) {
    if(entry.second.size() < 2) continue;
    bool distinctUv = false;
    for(std::size_t i = 0; i < entry.second.size() && !distinctUv; ++i) {
      const SPoint2 &first = candidate.at(entry.second[i]);
      for(std::size_t j = i + 1; j < entry.second.size(); ++j) {
        const SPoint2 &second = candidate.at(entry.second[j]);
        const double du = first.x() - second.x();
        const double dv = first.y() - second.y();
        if(du * du + dv * dv > 1.e-18) {
          distinctUv = true;
          break;
        }
      }
    }
    if(distinctUv)
      for(const std::size_t tag : entry.second)
        _coincidentVertexParameters.emplace(tag, candidate.at(tag));
  }
}

bool discreteFace::parFromCoincidentMeshVertex(const MVertex *vertex,
                                               SPoint2 &param) const
{
  if(!vertex) return false;
  const auto found = _coincidentVertexParameters.find(vertex->getNum());
  if(found == _coincidentVertexParameters.end()) return false;
  param = found->second;
  return true;
}

void discreteFace::resetMeshAttributes()
{
  Surface *_s = FindSurface(tag());
  if(!_s) {
    GFace ::resetMeshAttributes();
    return;
  }
  meshAttributes.recombine = _s->Recombine;
  meshAttributes.recombineAngle = _s->RecombineAngle;
  meshAttributes.method = _s->Method;
  meshAttributes.extrude = _s->Extrude;
  if(meshAttributes.method == MESH_TRANSFINITE) {
    meshAttributes.transfiniteArrangement = _s->Recombine_Dir;
    meshAttributes.transfiniteSmoothing = _s->TransfiniteSmoothing;
    meshAttributes.corners.clear();
    for(int i = 0; i < List_Nbr(_s->TrsfPoints); i++) {
      Vertex *corn;
      List_Read(_s->TrsfPoints, i, &corn);
      GVertex *gv = model()->getVertexByTag(corn->Num);
      if(gv)
        meshAttributes.corners.push_back(gv);
      else
        Msg::Error("Unknown point %d in transfinite attributes", corn->Num);
    }
  }
  meshAttributes.reverseMesh = _s->ReverseMesh;
  meshAttributes.algorithm = _s->MeshAlgorithm;
  meshAttributes.meshSizeFromBoundary = _s->MeshSizeFromBoundary;
  meshAttributes.transfinite3 = false;
}
