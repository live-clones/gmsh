// Gmsh Boundary Layer Plugin - Copyright (C) 2026 C. Geuzaine and J.-F. Remacle
//
// This program is free software: you can redistribute it and/or modify it under
// the terms of the GNU Affero General Public License as published by the Free
// Software Foundation, either version 3 of the License, or (at your option) any
// later version.
//
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more
// details.
//
// You should have received a copy of the GNU Affero General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include "meanPlaneSurfaceUntangler.h"

#include "GFace.h"
#include "GPoint.h"
#include "GmshDefines.h"
#include "GmshMessage.h"
#include "MEdge.h"
#include "MElement.h"
#include "MQuadrangle.h"
#include "MTriangle.h"
#include "MVertex.h"
#include "Numeric.h"
#include "SPoint3.h"
#include "bezierBasis.h"
#include "winslowUntanglerGMSH.h"

#include <algorithm>
#include <array>
#include <cmath>
#include <cstdio>
#include <cstdint>
#include <limits>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <vector>

namespace {
  struct Vec3 {
    double x = 0., y = 0., z = 0.;
  };

  struct Plane {
    Vec3 origin, e0, e1, normal;
  };

  struct SurfaceElementInfo {
    MElement *element = nullptr;
    Vec3 centroid;
    Vec3 normal;
    double size = 0.;
  };

  struct BezierPatchElement {
    MElement *element = nullptr;
    bool isTriangle = false;
    std::array<uint32_t, 9> bezierPoints = {};
  };

  struct ReferenceTriangle {
    std::array<int, 3> vertices;
    std::array<std::array<double, 2>, 3> ideal;
  };

  struct OriginalElementGeometry {
    std::vector<Vec3> points;
    std::vector<ReferenceTriangle> referenceTriangles;
  };

  typedef std::map<MElement *, OriginalElementGeometry, MElementPtrLessThan>
    OriginalElementGeometryMap;

  static const int triBezierTriangles[4][3] = {
    {0, 3, 5}, {3, 1, 4}, {5, 4, 2}, {3, 4, 5}};
  static const int quadBezierTriangles[8][3] = {
    {0, 4, 8}, {0, 8, 7}, {4, 1, 5}, {4, 5, 8},
    {8, 5, 2}, {8, 2, 6}, {7, 8, 6}, {7, 6, 3}};
  static const int triBezierCoeffFromVertex[6] = {0, 2, 5, 1, 4, 3};
  static const int quadBezierCoeffFromVertex[9] = {0, 2, 8, 6, 1,
                                                   5, 7, 3, 4};

  static Vec3 vertexPoint(MVertex *v)
  {
    return {v->x(), v->y(), v->z()};
  }

  static Vec3 bezierPoint(const bezierCoeff &bez, int i)
  {
    return {bez(i, 0), bez(i, 1), bez(i, 2)};
  }

  static Vec3 operator+(const Vec3 &a, const Vec3 &b)
  {
    return {a.x + b.x, a.y + b.y, a.z + b.z};
  }

  static Vec3 operator-(const Vec3 &a, const Vec3 &b)
  {
    return {a.x - b.x, a.y - b.y, a.z - b.z};
  }

  static Vec3 operator*(double a, const Vec3 &b)
  {
    return {a * b.x, a * b.y, a * b.z};
  }

  static Vec3 operator/(const Vec3 &a, double b)
  {
    return {a.x / b, a.y / b, a.z / b};
  }

  static double dot(const Vec3 &a, const Vec3 &b)
  {
    return a.x * b.x + a.y * b.y + a.z * b.z;
  }

  static Vec3 cross(const Vec3 &a, const Vec3 &b)
  {
    return {a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z,
            a.x * b.y - a.y * b.x};
  }

  static double norm(const Vec3 &a)
  {
    return std::sqrt(dot(a, a));
  }

  static Vec3 normalized(const Vec3 &a)
  {
    const double n = norm(a);
    if(n <= 0.) return {0., 0., 1.};
    return a / n;
  }

  static bool isSupportedElement(MElement *e)
  {
    const int type = e->getTypeForMSH();
    return type == MSH_TRI_3 || type == MSH_QUA_4 || type == MSH_TRI_6 ||
           type == MSH_QUA_9;
  }

  static SurfaceElementInfo elementInfo(MElement *e)
  {
    SurfaceElementInfo info;
    info.element = e;
    const std::size_t n = e->getNumPrimaryVertices();
    std::vector<Vec3> p(n);
    for(std::size_t i = 0; i < n; ++i) {
      p[i] = vertexPoint(e->getVertex(i));
      info.centroid = info.centroid + p[i];
    }
    info.centroid = info.centroid / (double)n;

    if(n == 3) {
      info.normal = cross(p[1] - p[0], p[2] - p[0]);
    }
    else if(n == 4) {
      info.normal =
        cross(p[1] - p[0], p[2] - p[0]) + cross(p[2] - p[0], p[3] - p[0]);
    }
    info.normal = normalized(info.normal);

    double l = 0.;
    int count = 0;
    for(int i = 0; i < e->getNumEdges(); ++i) {
      MEdge edge = e->getEdge(i);
      l += norm(vertexPoint(edge.getVertex(1)) - vertexPoint(edge.getVertex(0)));
      count++;
    }
    info.size = count ? l / count : 1.;
    return info;
  }

  static Plane makePlaneFromVertices(const std::vector<MVertex *> &vertices)
  {
    Plane plane;
    if(vertices.empty()) {
      plane.normal = {0., 0., 1.};
      plane.e0 = {1., 0., 0.};
      plane.e1 = {0., 1., 0.};
      return plane;
    }

    std::vector<SPoint3> points;
    points.reserve(vertices.size());
    for(MVertex *v : vertices) points.push_back(v->point());

    mean_plane mp;
    computeMeanPlaneSimple(points, mp);
    plane.origin = {mp.x, mp.y, mp.z};
    plane.normal = normalized({mp.a, mp.b, mp.c});
    plane.e0 = normalized({mp.plan[0][0], mp.plan[0][1], mp.plan[0][2]});
    if(norm(plane.e0) < 1.e-14) {
      Vec3 a = std::abs(plane.normal.x) < 0.9 ? Vec3{1., 0., 0.} :
                                                 Vec3{0., 1., 0.};
      plane.e0 = normalized(a - dot(a, plane.normal) * plane.normal);
    }
    plane.e1 = normalized(cross(plane.normal, plane.e0));
    return plane;
  }

  static std::array<double, 2> project(const Plane &plane, const Vec3 &p)
  {
    Vec3 d = p - plane.origin;
    return {dot(d, plane.e0), dot(d, plane.e1)};
  }

  static Vec3 unproject(const Plane &plane, const std::array<double, 2> &p)
  {
    return plane.origin + p[0] * plane.e0 + p[1] * plane.e1;
  }

  static double triangleArea2DSigned(const std::array<double, 2> &a,
                                     const std::array<double, 2> &b,
                                     const std::array<double, 2> &c)
  {
    return 0.5 * ((b[0] - a[0]) * (c[1] - a[1]) -
                  (b[1] - a[1]) * (c[0] - a[0]));
  }

  static void appendReferenceTriangle(
    OriginalElementGeometry &geom, int i0, int i1, int i2,
    std::array<std::array<double, 2>, 3> ideal)
  {
    double area = triangleArea2DSigned(ideal[0], ideal[1], ideal[2]);
    if(std::abs(area) < 1.e-16) return;
    ReferenceTriangle t;
    if(area < 0.) {
      t.vertices = {{i0, i2, i1}};
      t.ideal = {{ideal[0], ideal[2], ideal[1]}};
    }
    else {
      t.vertices = {{i0, i1, i2}};
      t.ideal = ideal;
    }
    geom.referenceTriangles.push_back(t);
  }

  static Plane makePlaneFromPoints(const std::vector<Vec3> &points)
  {
    Plane plane;
    if(points.empty()) {
      plane.origin = {0., 0., 0.};
      plane.e0 = {1., 0., 0.};
      plane.e1 = {0., 1., 0.};
      plane.normal = {0., 0., 1.};
      return plane;
    }

    plane.origin = points[0];
    Vec3 n = {0., 0., 0.};
    if(points.size() >= 3)
      n = cross(points[1] - points[0], points[2] - points[0]);
    if(points.size() >= 4)
      n = n + cross(points[2] - points[0], points[3] - points[0]);
    plane.normal = normalized(n);

    Vec3 e0 = {0., 0., 0.};
    for(std::size_t i = 1; i < points.size(); ++i) {
      e0 = points[i] - points[0];
      if(norm(e0) > 1.e-14) break;
    }
    e0 = e0 - dot(e0, plane.normal) * plane.normal;
    if(norm(e0) < 1.e-14) {
      Vec3 a = std::abs(plane.normal.x) < 0.9 ? Vec3{1., 0., 0.} :
                                                 Vec3{0., 1., 0.};
      e0 = a - dot(a, plane.normal) * plane.normal;
    }
    plane.e0 = normalized(e0);
    plane.e1 = normalized(cross(plane.normal, plane.e0));
    return plane;
  }

  static double signedProjectedArea(MElement *e, const Plane &plane)
  {
    const auto area2D = [](const std::array<double, 2> &a,
                           const std::array<double, 2> &b,
                           const std::array<double, 2> &c) {
      return 0.5 * ((b[0] - a[0]) * (c[1] - a[1]) -
                    (b[1] - a[1]) * (c[0] - a[0]));
    };
    const int n = e->getNumPrimaryVertices();
    if(n < 3) return 0.;
    std::array<double, 2> p0 = project(plane, vertexPoint(e->getVertex(0)));
    std::array<double, 2> p1 = project(plane, vertexPoint(e->getVertex(1)));
    std::array<double, 2> p2 = project(plane, vertexPoint(e->getVertex(2)));
    double a = area2D(p0, p1, p2);
    if(n == 4) {
      std::array<double, 2> p3 = project(plane, vertexPoint(e->getVertex(3)));
      a += area2D(p0, p2, p3);
    }
    return a;
  }

  static void orientPlaneWithPatch(
    Plane &plane, const std::vector<int> &patch,
    const std::vector<SurfaceElementInfo> &infos)
  {
    double area = 0.;
    for(int id : patch) area += signedProjectedArea(infos[id].element, plane);
    if(area < 0.) {
      plane.e1 = -1. * plane.e1;
      plane.normal = -1. * plane.normal;
    }
  }

  static void setVertex(MVertex *v, const Vec3 &p)
  {
    v->x() = p.x;
    v->y() = p.y;
    v->z() = p.z;
  }

  static void setVertexOnFace(GFace *gf, MVertex *v, const Vec3 &p)
  {
    if(!gf) {
      setVertex(v, p);
      return;
    }

    if(gf->geomType() == GEntity::Plane) {
      setVertex(v, p);
      SPoint2 param = gf->parFromPoint(SPoint3(p.x, p.y, p.z), false);
      v->setParameter(0, param.x());
      v->setParameter(1, param.y());
      return;
    }

    double initialGuess[2] = {0., 0.};
    double u = 0., vv = 0.;
    if(v->getParameter(0, u) && v->getParameter(1, vv)) {
      initialGuess[0] = u;
      initialGuess[1] = vv;
    }
    GPoint gp =
      gf->closestPoint(SPoint3(p.x, p.y, p.z), initialGuess);
    v->x() = gp.x();
    v->y() = gp.y();
    v->z() = gp.z();
    v->setParameter(0, gp.u());
    v->setParameter(1, gp.v());
  }

  static std::array<std::array<double, 2>, 3>
  triangleIdealWith3DShape(const Vec3 &p0, const Vec3 &p1, const Vec3 &p2)
  {
    double l01 = norm(p1 - p0);
    const double l02 = norm(p2 - p0);
    const double l12 = norm(p2 - p1);
    if(l01 <= 1.e-14) l01 = 1.e-14;
    const double x =
      (l02 * l02 + l01 * l01 - l12 * l12) / (2. * l01);
    const double y2 = std::max(l02 * l02 - x * x, 0.);
    return {{{0., 0.}, {l01, 0.}, {x, std::sqrt(y2)}}};
  }

  static std::array<std::array<double, 2>, 3>
  triangleIdealWith3DShape(MElement *e)
  {
    return triangleIdealWith3DShape(vertexPoint(e->getVertex(0)),
                                    vertexPoint(e->getVertex(1)),
                                    vertexPoint(e->getVertex(2)));
  }

  static bool originalProjectedShape(
    MElement *e, const OriginalElementGeometryMap *original, const Plane &plane,
    std::array<std::array<double, 2>, 4> &sh)
  {
    if(!original) return false;
    auto it = original->find(e);
    if(it == original->end()) return false;
    const int n = (int)e->getNumPrimaryVertices();
    if((int)it->second.points.size() < n) return false;
    for(int i = 0; i < n; ++i) sh[i] = project(plane, it->second.points[i]);
    return true;
  }

  static double originalEdgeLength(
    MElement *e, const OriginalElementGeometryMap *original, int i0, int i1)
  {
    if(original) {
      auto it = original->find(e);
      if(it != original->end() &&
         (int)it->second.points.size() > std::max(i0, i1))
        return norm(it->second.points[i1] - it->second.points[i0]);
    }
    return norm(vertexPoint(e->getVertex(i1)) - vertexPoint(e->getVertex(i0)));
  }

  static void buildP1ReferenceTriangles(
    MElement *e, OriginalElementGeometry &geom,
    const std::map<MElement *, double> &layers)
  {
    geom.referenceTriangles.clear();
    const int type = e->getTypeForMSH();
    const auto itLayer = layers.find(e);
    const bool isLayer = itLayer != layers.end();

    if(type == MSH_TRI_3) {
      if(isLayer) {
        const double T = M_PI / 3.;
        const double thickness = itLayer->second;
        const std::array<std::array<double, 2>, 3> sh = {
          {{0., 0.}, {thickness, 0.},
           {thickness * std::cos(T), thickness * std::sin(T)}}};
        appendReferenceTriangle(geom, 0, 1, 2, sh);
      }
      else if(geom.points.size() >= 3) {
        appendReferenceTriangle(
          geom, 0, 1, 2,
          triangleIdealWith3DShape(geom.points[0], geom.points[1],
                                   geom.points[2]));
      }
    }
    else if(type == MSH_QUA_4) {
      if(isLayer && geom.points.size() >= 2) {
        const double thickness = itLayer->second;
        double dx = norm(geom.points[1] - geom.points[0]);
        if(dx <= 1.e-14) dx = 1.e-14;
        const std::array<std::array<double, 2>, 4> sh = {
          {{0., 0.}, {dx, 0.}, {dx, thickness}, {0., thickness}}};
        appendReferenceTriangle(geom, 0, 1, 2, {sh[0], sh[1], sh[2]});
        appendReferenceTriangle(geom, 2, 3, 0, {sh[2], sh[3], sh[0]});
        appendReferenceTriangle(geom, 0, 1, 3, {sh[0], sh[1], sh[3]});
        appendReferenceTriangle(geom, 1, 2, 3, {sh[1], sh[2], sh[3]});
      }
      else if(geom.points.size() >= 4) {
        Plane plane = makePlaneFromPoints(geom.points);
        std::array<std::array<double, 2>, 4> sh;
        for(int i = 0; i < 4; ++i) sh[i] = project(plane, geom.points[i]);
        appendReferenceTriangle(geom, 0, 1, 2, {sh[0], sh[1], sh[2]});
        appendReferenceTriangle(geom, 2, 3, 0, {sh[2], sh[3], sh[0]});
        appendReferenceTriangle(geom, 0, 1, 3, {sh[0], sh[1], sh[3]});
        appendReferenceTriangle(geom, 1, 2, 3, {sh[1], sh[2], sh[3]});
      }
    }
  }

  static void writePatchDebugPos(
    GFace *gf, const std::vector<int> &patch,
    const std::vector<SurfaceElementInfo> &infos, const Plane &plane)
  {
    if(patch.empty()) return;
    char name[256];
    std::snprintf(name, sizeof(name), "meanPlaneBL_face_%d_seed_%d.pos",
                  gf ? gf->tag() : 0, patch.front());
    FILE *fp = std::fopen(name, "w");
    if(!fp) return;

    std::fprintf(fp, "View \"Mean-plane patch face %d seed %d\" {\n",
                 gf ? gf->tag() : 0, patch.front());
    for(int id : patch) {
      MElement *e = infos[id].element;
      if(e->getNumPrimaryVertices() == 3) {
        Vec3 p[3] = {vertexPoint(e->getVertex(0)),
                     vertexPoint(e->getVertex(1)),
                     vertexPoint(e->getVertex(2))};
        std::fprintf(fp,
                     "ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){1,1,1};\n",
                     p[0].x, p[0].y, p[0].z, p[1].x, p[1].y, p[1].z,
                     p[2].x, p[2].y, p[2].z);
      }
      else if(e->getNumPrimaryVertices() == 4) {
        Vec3 p[4] = {vertexPoint(e->getVertex(0)),
                     vertexPoint(e->getVertex(1)),
                     vertexPoint(e->getVertex(2)),
                     vertexPoint(e->getVertex(3))};
        std::fprintf(fp,
                     "ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){1,1,1};\n",
                     p[0].x, p[0].y, p[0].z, p[1].x, p[1].y, p[1].z,
                     p[2].x, p[2].y, p[2].z);
        std::fprintf(fp,
                     "ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){1,1,1};\n",
                     p[2].x, p[2].y, p[2].z, p[3].x, p[3].y, p[3].z,
                     p[0].x, p[0].y, p[0].z);
      }
    }

    const Vec3 seed = infos[patch.front()].centroid;
    std::fprintf(fp, "SP(%g,%g,%g){2};\n", seed.x, seed.y, seed.z);
    for(int id : patch) {
      const Vec3 c = infos[id].centroid;
      std::fprintf(fp, "SP(%g,%g,%g){1};\n", c.x, c.y, c.z);
    }
    const double scale = std::max(infos[patch.front()].size, 1.e-12);
    const Vec3 o = plane.origin;
    const Vec3 a = plane.origin + scale * plane.e0;
    const Vec3 b = plane.origin + scale * plane.e1;
    const Vec3 n = plane.origin + scale * plane.normal;
    std::fprintf(fp, "SL(%g,%g,%g,%g,%g,%g){3,3};\n", o.x, o.y, o.z, a.x,
                 a.y, a.z);
    std::fprintf(fp, "SL(%g,%g,%g,%g,%g,%g){4,4};\n", o.x, o.y, o.z, b.x,
                 b.y, b.z);
    std::fprintf(fp, "SL(%g,%g,%g,%g,%g,%g){5,5};\n", o.x, o.y, o.z, n.x,
                 n.y, n.z);
    std::fprintf(fp, "};\n");
    std::fclose(fp);
  }

  static uint32_t addVertexPoint(
    MVertex *v, bool lock, const Plane &plane,
    std::map<MVertex *, uint32_t, MVertexPtrLessThan> &indices,
    std::vector<std::array<double, 2>> &points, std::vector<bool> &locked)
  {
    auto it = indices.find(v);
    if(it != indices.end()) {
      if(lock) locked[it->second] = true;
      return it->second;
    }

    const uint32_t id = (uint32_t)points.size();
    indices[v] = id;
    points.push_back(project(plane, vertexPoint(v)));
    locked.push_back(lock);
    return id;
  }

  static uint32_t addBezierPoint(
    MVertex *owner, const Vec3 &p, bool lock, const Plane &plane,
    std::map<MVertex *, uint32_t, MVertexPtrLessThan> &indices,
    std::vector<std::array<double, 2>> &points, std::vector<bool> &locked)
  {
    if(owner) {
      auto it = indices.find(owner);
      if(it != indices.end()) {
        if(lock) locked[it->second] = true;
        return it->second;
      }
    }

    const uint32_t id = (uint32_t)points.size();
    points.push_back(project(plane, p));
    locked.push_back(lock);
    if(owner) indices[owner] = id;
    return id;
  }

  static void addPositiveTriangle(
    uint32_t a, uint32_t b, uint32_t c,
    const std::vector<std::array<double, 2>> &points,
    std::vector<std::array<uint32_t, 3>> &triangles,
    std::vector<std::array<std::array<double, 2>, 3>> &ideal)
  {
    std::array<std::array<double, 2>, 3> sh = {points[a], points[b], points[c]};
    const double area =
      (sh[1][0] - sh[0][0]) * (sh[2][1] - sh[0][1]) -
      (sh[1][1] - sh[0][1]) * (sh[2][0] - sh[0][0]);
    if(std::abs(area) < 1.e-16) return;
    if(area < 0.) {
      triangles.push_back({a, c, b});
      ideal.push_back({sh[0], sh[2], sh[1]});
    }
    else {
      triangles.push_back({a, b, c});
      ideal.push_back(sh);
    }
  }

  static void addTriangleWithIdeal(
    uint32_t a, uint32_t b, uint32_t c,
    std::array<std::array<double, 2>, 3> sh,
    std::vector<std::array<uint32_t, 3>> &triangles,
    std::vector<std::array<std::array<double, 2>, 3>> &ideal)
  {
    const double area =
      (sh[1][0] - sh[0][0]) * (sh[2][1] - sh[0][1]) -
      (sh[1][1] - sh[0][1]) * (sh[2][0] - sh[0][0]);
    if(std::abs(area) < 1.e-16) return;
    if(area < 0.) {
      triangles.push_back({a, c, b});
      ideal.push_back({sh[0], sh[2], sh[1]});
    }
    else {
      triangles.push_back({a, b, c});
      ideal.push_back(sh);
    }
  }

  static void removeLockedTriangles(
    const std::vector<bool> &locked,
    std::vector<std::array<uint32_t, 3>> &triangles,
    std::vector<std::array<std::array<double, 2>, 3>> &ideal)
  {
    std::vector<std::array<uint32_t, 3>> filteredTriangles;
    std::vector<std::array<std::array<double, 2>, 3>> filteredIdeal;
    filteredTriangles.reserve(triangles.size());
    filteredIdeal.reserve(ideal.size());
    for(std::size_t i = 0; i < triangles.size(); ++i) {
      const auto &t = triangles[i];
      if(locked[t[0]] && locked[t[1]] && locked[t[2]]) continue;
      filteredTriangles.push_back(t);
      filteredIdeal.push_back(ideal[i]);
    }
    triangles.swap(filteredTriangles);
    ideal.swap(filteredIdeal);
  }

  static void lockPatchBoundary(
    const std::vector<int> &patch, const std::vector<SurfaceElementInfo> &infos,
    std::set<MVertex *, MVertexPtrLessThan> &lockedVertices)
  {
    std::map<MEdge, int, MEdgeLessThan> edgeCount;
    for(int id : patch) {
      MElement *e = infos[id].element;
      for(int i = 0; i < e->getNumEdges(); ++i) edgeCount[e->getEdge(i)]++;
    }

    for(int id : patch) {
      MElement *e = infos[id].element;
      for(int i = 0; i < e->getNumEdges(); ++i) {
        MEdge edge = e->getEdge(i);
        if(edgeCount[edge] != 1) continue;
        lockedVertices.insert(edge.getVertex(0));
        lockedVertices.insert(edge.getVertex(1));
        std::vector<MVertex *> edgeVertices;
        e->getEdgeVertices(i, edgeVertices);
        for(MVertex *v : edgeVertices) lockedVertices.insert(v);
      }
    }
  }

  static void collectPatchVerticesAndBoundary(
    const std::vector<int> &patch, const std::vector<SurfaceElementInfo> &infos,
    std::vector<MVertex *> &all, std::vector<MVertex *> &boundary)
  {
    all.clear();
    boundary.clear();
    std::set<MVertex *, MVertexPtrLessThan> allSet, boundarySet;
    std::map<MEdge, int, MEdgeLessThan> edgeCount;

    for(int id : patch) {
      MElement *e = infos[id].element;
      for(std::size_t i = 0; i < e->getNumVertices(); ++i)
        if(allSet.insert(e->getVertex(i)).second) all.push_back(e->getVertex(i));
      for(int i = 0; i < e->getNumEdges(); ++i) edgeCount[e->getEdge(i)]++;
    }

    for(int id : patch) {
      MElement *e = infos[id].element;
      for(int i = 0; i < e->getNumEdges(); ++i) {
        MEdge edge = e->getEdge(i);
        if(edgeCount[edge] != 1) continue;
        if(boundarySet.insert(edge.getVertex(0)).second)
          boundary.push_back(edge.getVertex(0));
        if(boundarySet.insert(edge.getVertex(1)).second)
          boundary.push_back(edge.getVertex(1));
        std::vector<MVertex *> edgeVertices;
        e->getEdgeVertices(i, edgeVertices);
        for(MVertex *v : edgeVertices)
          if(boundarySet.insert(v).second) boundary.push_back(v);
      }
    }
  }

  static void collectPatchVertices(
    const std::vector<int> &patch, const std::vector<SurfaceElementInfo> &infos,
    std::vector<MVertex *> &vertices)
  {
    vertices.clear();
    std::set<MVertex *, MVertexPtrLessThan> vertexSet;
    for(int id : patch) {
      MElement *e = infos[id].element;
      for(std::size_t i = 0; i < e->getNumVertices(); ++i)
        if(vertexSet.insert(e->getVertex(i)).second)
          vertices.push_back(e->getVertex(i));
    }
  }

  static std::vector<int> patchVector(const std::set<int> &patchSet)
  {
    return std::vector<int>(patchSet.begin(), patchSet.end());
  }

  static bool elementProjectedPositive(MElement *e, const Plane &plane)
  {
    const int type = e->getTypeForMSH();
    if(type == MSH_TRI_6 || type == MSH_QUA_9) {
      bezierCoeff *bez = e->getBezierVerticesCoord();
      const bool isTri = type == MSH_TRI_6;
      const int n = isTri ? 6 : 9;
      if(bez->getNumCoeff() < n) {
        delete bez;
        return false;
      }
      std::array<double, 2> p[9];
      for(int i = 0; i < n; ++i) {
        const int iBez =
          isTri ? triBezierCoeffFromVertex[i] : quadBezierCoeffFromVertex[i];
        p[i] = project(plane, bezierPoint(*bez, iBez));
      }
      delete bez;
      if(isTri) {
        for(const auto &t : triBezierTriangles) {
          if(triangleArea2DSigned(p[t[0]], p[t[1]], p[t[2]]) <= 1.e-14)
            return false;
        }
      }
      else {
        for(const auto &t : quadBezierTriangles) {
          if(triangleArea2DSigned(p[t[0]], p[t[1]], p[t[2]]) <= 1.e-14)
            return false;
        }
      }
      return true;
    }

    const int n = (int)e->getNumPrimaryVertices();
    if(n == 3) {
      const auto p0 = project(plane, vertexPoint(e->getVertex(0)));
      const auto p1 = project(plane, vertexPoint(e->getVertex(1)));
      const auto p2 = project(plane, vertexPoint(e->getVertex(2)));
      return triangleArea2DSigned(p0, p1, p2) > -1.e-14;
    }
    if(n == 4) {
      const auto p0 = project(plane, vertexPoint(e->getVertex(0)));
      const auto p1 = project(plane, vertexPoint(e->getVertex(1)));
      const auto p2 = project(plane, vertexPoint(e->getVertex(2)));
      const auto p3 = project(plane, vertexPoint(e->getVertex(3)));
      return triangleArea2DSigned(p0, p1, p2) > -1.e-14 &&
             triangleArea2DSigned(p2, p3, p0) > -1.e-14 &&
             triangleArea2DSigned(p0, p1, p3) > -1.e-14 &&
             triangleArea2DSigned(p1, p2, p3) > -1.e-14;
    }
    return true;
  }

  static bool patchAccepted(
    const std::set<int> &patchSet,
    const std::vector<SurfaceElementInfo> &infos, double normalTolerance,
    Plane &plane, bool &orientationFailed)
  {
    orientationFailed = false;
    std::vector<int> patch = patchVector(patchSet);
    std::vector<MVertex *> vertices;
    collectPatchVertices(patch, infos, vertices);
    if(vertices.size() < 3) return false;

    plane = makePlaneFromVertices(vertices);
    for(MVertex *v : vertices) {
      const Vec3 p = vertexPoint(v);
      if(std::abs(dot(p - plane.origin, plane.normal)) > normalTolerance)
        return false;
    }

    orientPlaneWithPatch(plane, patch, infos);
    for(int id : patch) {
      if(!elementProjectedPositive(infos[id].element, plane)) {
        orientationFailed = true;
        return false;
      }
    }
    return true;
  }

  static bool elementAcceptedInPlane(MElement *e, const Plane &plane,
                                     double normalTolerance,
                                     bool &orientationFailed)
  {
    orientationFailed = false;
    for(std::size_t i = 0; i < e->getNumVertices(); ++i) {
      const Vec3 p = vertexPoint(e->getVertex(i));
      if(std::abs(dot(p - plane.origin, plane.normal)) > normalTolerance)
        return false;
    }
    if(!elementProjectedPositive(e, plane)) {
      orientationFailed = true;
      return false;
    }
    return true;
  }

  static void addElementNeighbours(
    MElement *e, std::map<MVertex *, std::vector<MVertex *>, MVertexPtrLessThan>
                   &v2v)
  {
    const std::size_t n = e->getNumVertices();
    for(std::size_t i = 0; i < n; ++i) {
      MVertex *vi = e->getVertex(i);
      for(std::size_t j = 0; j < n; ++j) {
        if(i == j) continue;
        MVertex *vj = e->getVertex(j);
        if(std::find(v2v[vi].begin(), v2v[vi].end(), vj) == v2v[vi].end())
          v2v[vi].push_back(vj);
      }
    }
  }

  static bool buildPlanarBFSPatch(
    MVertex *seed,
    const std::map<MVertex *, std::vector<int>, MVertexPtrLessThan> &v2e,
    const std::map<MVertex *, std::vector<MVertex *>, MVertexPtrLessThan> &v2v,
    const std::vector<SurfaceElementInfo> &infos, double normalTolerance,
    int maxDepth, std::vector<int> &patch, Plane &plane,
    bool &orientationFailed)
  {
    orientationFailed = false;
    patch.clear();

    const auto itSeed = v2e.find(seed);
    if(itSeed == v2e.end()) return false;

    std::set<int> seedPatchSet;
    for(int id : itSeed->second) seedPatchSet.insert(id);
    std::set<int> planePatchSet = seedPatchSet;

    bool failedOrientation = false;
    if(!patchAccepted(planePatchSet, infos, normalTolerance, plane,
                      failedOrientation)) {
      orientationFailed = failedOrientation;
      return false;
    }

    std::queue<std::pair<MVertex *, int>> candidates;
    std::map<MVertex *, int, MVertexPtrLessThan> visited;

    auto enqueueNeighbours = [&](MVertex *v, int depth) {
      const auto it = v2v.find(v);
      if(it == v2v.end()) return;
      for(MVertex *w : it->second) {
        if(visited.find(w) != visited.end()) continue;
        visited[w] = depth;
        candidates.push(std::make_pair(w, depth));
      }
    };

    std::vector<MVertex *> vertices;
    collectPatchVertices(patchVector(planePatchSet), infos, vertices);
    for(MVertex *v : vertices) visited[v] = 0;
    for(MVertex *v : vertices) enqueueNeighbours(v, 1);

    while(!candidates.empty()) {
      const auto candidate = candidates.front();
      candidates.pop();
      MVertex *v = candidate.first;
      const int depth = candidate.second;
      if(depth > maxDepth) continue;

      const auto it = v2e.find(v);
      if(it == v2e.end()) continue;

      bool acceptedAny = false;
      for(int id : it->second) {
        if(planePatchSet.find(id) != planePatchSet.end()) continue;

        bool candidateOrientationFailed = false;
        if(!elementAcceptedInPlane(infos[id].element, plane, normalTolerance,
                                  candidateOrientationFailed)) {
          if(candidateOrientationFailed) {
            orientationFailed = true;
            return false;
          }
          continue;
        }
        planePatchSet.insert(id);
        acceptedAny = true;
      }

      if(acceptedAny) {
        for(int id : it->second) {
          if(planePatchSet.find(id) == planePatchSet.end()) continue;
          MElement *e = infos[id].element;
          for(std::size_t i = 0; i < e->getNumVertices(); ++i) {
            MVertex *w = e->getVertex(i);
            if(visited.find(w) == visited.end()) visited[w] = depth;
            if(depth < maxDepth) enqueueNeighbours(w, depth + 1);
          }
        }
      }
    }

    patch = patchVector(planePatchSet);
    return true;
  }

  struct SurfacePatchGraph {
    std::map<MVertex *, std::vector<int>, MVertexPtrLessThan> v2e;
    std::map<MVertex *, std::vector<MVertex *>, MVertexPtrLessThan> v2v;
  };

  static SurfacePatchGraph
  buildSurfacePatchGraph(const std::vector<SurfaceElementInfo> &infos)
  {
    SurfacePatchGraph graph;
    for(std::size_t i = 0; i < infos.size(); ++i) {
      MElement *e = infos[i].element;
      for(std::size_t j = 0; j < e->getNumVertices(); ++j)
        graph.v2e[e->getVertex(j)].push_back((int)i);
      addElementNeighbours(e, graph.v2v);
    }
    return graph;
  }

  static std::vector<MVertex *> shuffledSurfaceSeeds(
    GFace *gf,
    const std::map<MVertex *, std::vector<int>, MVertexPtrLessThan> &v2e,
    int sweep)
  {
    std::vector<MVertex *> seeds;
    std::set<MVertex *, MVertexPtrLessThan> seedSet;

    if(gf) {
      for(MVertex *v : gf->mesh_vertices) {
        if(v2e.find(v) == v2e.end()) continue;
        if(seedSet.insert(v).second) seeds.push_back(v);
      }
    }
    for(const auto &entry : v2e)
      if(seedSet.insert(entry.first).second) seeds.push_back(entry.first);

    std::mt19937 rng(0x9e3779b9u ^
                     (uint32_t)(gf ? gf->tag() * 2654435761u : 0u) ^
                     (uint32_t)seeds.size() ^
                     (uint32_t)((sweep + 1) * 2246822519u));
    std::shuffle(seeds.begin(), seeds.end(), rng);
    return seeds;
  }

  static bool buildPatchWithRetries(
    MVertex *seed, const SurfacePatchGraph &graph,
    const std::vector<SurfaceElementInfo> &infos, double baseTolerance,
    double minTolerance, int maxDepth, std::vector<int> &patch, Plane &plane)
  {
    double tolerance = baseTolerance;
    while(tolerance >= minTolerance) {
      bool orientationFailed = false;
      if(buildPlanarBFSPatch(seed, graph.v2e, graph.v2v, infos, tolerance,
                             maxDepth, patch, plane, orientationFailed))
        return !patch.empty();
      if(!orientationFailed) return false;
      tolerance *= 0.5;
    }
    return false;
  }

  static void augmentSurfaceFixedVertices(
    GFace *gf, const std::set<MElement *, MElementPtrLessThan> &toProcess,
    const std::set<MVertex *, MVertexPtrLessThan> &fixed,
    std::set<MVertex *, MVertexPtrLessThan> &effectiveFixed)
  {
    effectiveFixed = fixed;
    if(!gf) return;

    auto visitElement = [&](MElement *e) {
      const bool processed = toProcess.find(e) != toProcess.end();
      for(std::size_t i = 0; i < e->getNumVertices(); ++i) {
        MVertex *v = e->getVertex(i);
        if(!processed || v->onWhat()->dim() != 2) effectiveFixed.insert(v);
      }
    };

    for(auto e : gf->triangles) visitElement(e);
    for(auto e : gf->quadrangles) visitElement(e);
  }

  static void updateP2LagrangeNodes(
    GFace *gf, const Plane &plane,
    const std::vector<BezierPatchElement> &patchElements,
    const std::vector<std::array<double, 2>> &points,
    const std::vector<bool> &locked, double *maxMove = nullptr)
  {
    std::set<MVertex *, MVertexPtrLessThan> updated;
    auto updateMove = [&](MVertex *v, const Vec3 &before) {
      if(!maxMove) return;
      const Vec3 after = vertexPoint(v);
      *maxMove = std::max(*maxMove, norm(after - before));
    };

    auto point3 = [&](uint32_t i) { return unproject(plane, points[i]); };
    auto blend = [](const Vec3 &a, double wa, const Vec3 &b, double wb,
                    const Vec3 &c, double wc) {
      return wa * a + wb * b + wc * c;
    };

    for(const auto &pe : patchElements) {
      MElement *e = pe.element;
      if(!e) continue;
      if(pe.isTriangle) {
        Vec3 b[6];
        for(int i = 0; i < 6; ++i) b[i] = point3(pe.bezierPoints[i]);
        const Vec3 lag[6] = {
          b[0], b[1], b[2], blend(b[0], 0.25, b[3], 0.5, b[1], 0.25),
          blend(b[1], 0.25, b[4], 0.5, b[2], 0.25),
          blend(b[2], 0.25, b[5], 0.5, b[0], 0.25)};
        for(int i = 0; i < 6; ++i)
          if(!locked[pe.bezierPoints[i]] &&
             updated.insert(e->getVertex(i)).second) {
            Vec3 before = vertexPoint(e->getVertex(i));
            setVertexOnFace(gf, e->getVertex(i), lag[i]);
            updateMove(e->getVertex(i), before);
          }
      }
      else {
        Vec3 b[9];
        for(int i = 0; i < 9; ++i) b[i] = point3(pe.bezierPoints[i]);
        const Vec3 lag[9] = {
          b[0],
          b[1],
          b[2],
          b[3],
          blend(b[0], 0.25, b[4], 0.5, b[1], 0.25),
          blend(b[1], 0.25, b[5], 0.5, b[2], 0.25),
          blend(b[2], 0.25, b[6], 0.5, b[3], 0.25),
          blend(b[3], 0.25, b[7], 0.5, b[0], 0.25),
          0.0625 * (b[0] + b[1] + b[2] + b[3]) +
            0.125 * (b[4] + b[5] + b[6] + b[7]) + 0.25 * b[8]};
        for(int i = 0; i < 9; ++i)
          if(!locked[pe.bezierPoints[i]] &&
             updated.insert(e->getVertex(i)).second) {
            Vec3 before = vertexPoint(e->getVertex(i));
            setVertexOnFace(gf, e->getVertex(i), lag[i]);
            updateMove(e->getVertex(i), before);
          }
      }
    }
  }

  static bool untanglePatchP1LikeOption1(
    GFace *gf, const std::vector<int> &patch,
    const std::vector<SurfaceElementInfo> &infos,
    const std::set<MVertex *, MVertexPtrLessThan> &fixed,
    const MeanPlaneSurfaceUntanglerOptions &options,
    const std::map<MElement *, double> &layers,
    const OriginalElementGeometryMap *original, const Plane &plane,
    double *maxMove = nullptr)
  {
    std::set<MVertex *, MVertexPtrLessThan> lockedVertices = fixed;
    if(options.lockPatchBoundary)
      lockPatchBoundary(patch, infos, lockedVertices);

    std::vector<MElement *> elements;
    elements.reserve(patch.size());
    for(int id : patch) {
      MElement *e = infos[id].element;
      const int type = e->getTypeForMSH();
      if(type == MSH_TRI_3 || type == MSH_QUA_4) elements.push_back(e);
    }
    if(elements.empty()) return true;

    std::vector<std::array<double, 2>> points;
    std::vector<std::array<uint32_t, 3>> triangles;
    std::vector<std::array<std::array<double, 2>, 3>> sh;
    std::vector<bool> locked;
    std::set<MVertex *, MVertexPtrLessThan> verts;

    for(MElement *e : elements) {
      for(std::size_t j = 0; j < e->getNumVertices(); ++j)
        verts.insert(e->getVertex(j));
    }

    std::map<MVertex *, uint32_t, MVertexPtrLessThan> indices;
    uint32_t index = 0;
    for(MVertex *v : verts) {
      indices[v] = index++;
      locked.push_back(lockedVertices.find(v) != lockedVertices.end());
      points.push_back(project(plane, vertexPoint(v)));
    }

    for(MElement *e : elements) {
      const OriginalElementGeometry *geom = nullptr;
      if(original) {
        auto it = original->find(e);
        if(it != original->end()) geom = &it->second;
      }

      if(geom && !geom->referenceTriangles.empty()) {
        for(const ReferenceTriangle &rt : geom->referenceTriangles) {
          if(rt.vertices[0] >= (int)e->getNumVertices() ||
             rt.vertices[1] >= (int)e->getNumVertices() ||
             rt.vertices[2] >= (int)e->getNumVertices())
            continue;
          triangles.push_back(
            {indices[e->getVertex(rt.vertices[0])],
             indices[e->getVertex(rt.vertices[1])],
             indices[e->getVertex(rt.vertices[2])]});
          sh.push_back(rt.ideal);
        }
      }
      else {
        const uint32_t a = indices[e->getVertex(0)];
        const uint32_t b = indices[e->getVertex(1)];
        const uint32_t c = indices[e->getVertex(2)];
        if(e->getNumVertices() == 3) {
          addPositiveTriangle(a, b, c, points, triangles, sh);
        }
        else {
          const uint32_t d = indices[e->getVertex(3)];
          addPositiveTriangle(a, b, c, points, triangles, sh);
          addPositiveTriangle(c, d, a, points, triangles, sh);
          addPositiveTriangle(a, b, d, points, triangles, sh);
          addPositiveTriangle(b, c, d, points, triangles, sh);
        }
      }
    }

    if(triangles.empty()) return true;
    if(triangles.size() != sh.size()) {
      Msg::Warning("Mean-plane P1 surface untangler face %d: %zu triangles "
                   "but %zu ideal shapes",
                   gf ? gf->tag() : 0, triangles.size(), sh.size());
      return false;
    }

    bool ok = untangle_triangles_2D_GMSH(
      points, locked, triangles, sh, options.lambda, options.iterMaxInner,
      options.iterMaxOuter, options.iterFailMax, options.timeMax, false);

    for(const auto &it : indices) {
      if(locked[it.second]) continue;
      Vec3 before = vertexPoint(it.first);
      setVertexOnFace(gf, it.first, unproject(plane, points[it.second]));
      if(maxMove)
        *maxMove = std::max(*maxMove, norm(vertexPoint(it.first) - before));
    }
    return ok;
  }

  static bool untanglePatch(
    GFace *gf, const std::vector<int> &patch,
    const std::vector<SurfaceElementInfo> &infos,
    const std::set<MVertex *, MVertexPtrLessThan> &fixed,
    const MeanPlaneSurfaceUntanglerOptions &options,
    const std::map<MElement *, double> *layers = nullptr,
    const OriginalElementGeometryMap *original = nullptr,
    const Plane *inputPlane = nullptr, double *maxMove = nullptr)
  {
    std::vector<MVertex *> all, boundary;
    collectPatchVerticesAndBoundary(patch, infos, all, boundary);
    Plane plane = inputPlane ? *inputPlane : makePlaneFromVertices(all);
    if(!inputPlane) orientPlaneWithPatch(plane, patch, infos);
    if(options.writePatchDebugPos) writePatchDebugPos(gf, patch, infos, plane);
    if(layers)
      return untanglePatchP1LikeOption1(gf, patch, infos, fixed, options,
                                        *layers, original, plane, maxMove);

    std::set<MVertex *, MVertexPtrLessThan> lockedVertices = fixed;
    if(options.lockPatchBoundary)
      lockPatchBoundary(patch, infos, lockedVertices);

    std::map<MVertex *, uint32_t, MVertexPtrLessThan> indices;
    std::vector<std::array<double, 2>> points;
    std::vector<bool> locked;
    std::vector<std::array<uint32_t, 3>> triangles;
    std::vector<std::array<std::array<double, 2>, 3>> ideal;
    std::vector<BezierPatchElement> patchElements;

    for(int id : patch) {
      MElement *e = infos[id].element;
      const int type = e->getTypeForMSH();
      if(type == MSH_TRI_3) {
        uint32_t v[3];
        for(int i = 0; i < 3; ++i) {
          MVertex *mv = e->getVertex(i);
          v[i] = addVertexPoint(mv, lockedVertices.count(mv), plane, indices,
                                points, locked);
        }
        const auto itLayer = layers ? layers->find(e) :
                                      std::map<MElement *, double>::const_iterator();
        std::array<std::array<double, 2>, 4> sh;
        if(layers && itLayer != layers->end()) {
          addTriangleWithIdeal(v[0], v[1], v[2], triangleIdealWith3DShape(e),
                               triangles, ideal);
        }
        else if(originalProjectedShape(e, original, plane, sh))
          addTriangleWithIdeal(v[0], v[1], v[2], {sh[0], sh[1], sh[2]},
                               triangles, ideal);
        else
          addPositiveTriangle(v[0], v[1], v[2], points, triangles, ideal);
      }
      else if(type == MSH_QUA_4) {
        uint32_t v[4];
        for(int i = 0; i < 4; ++i) {
          MVertex *mv = e->getVertex(i);
          v[i] = addVertexPoint(mv, lockedVertices.count(mv), plane, indices,
                                points, locked);
        }
        const auto itLayer = layers ? layers->find(e) :
                                      std::map<MElement *, double>::const_iterator();
        if(layers && itLayer != layers->end()) {
          const double thickness = itLayer->second;
          const double dx = originalEdgeLength(e, original, 0, 1);
          std::array<std::array<double, 2>, 4> sh = {
            {{0., 0.}, {dx, 0.}, {dx, thickness}, {0., thickness}}};
          addTriangleWithIdeal(v[0], v[1], v[2], {sh[0], sh[1], sh[2]},
                               triangles, ideal);
          addTriangleWithIdeal(v[2], v[3], v[0], {sh[2], sh[3], sh[0]},
                               triangles, ideal);
          addTriangleWithIdeal(v[0], v[1], v[3], {sh[0], sh[1], sh[3]},
                               triangles, ideal);
          addTriangleWithIdeal(v[1], v[2], v[3], {sh[1], sh[2], sh[3]},
                               triangles, ideal);
        }
        else {
          std::array<std::array<double, 2>, 4> sh;
          if(originalProjectedShape(e, original, plane, sh)) {
            addTriangleWithIdeal(v[0], v[1], v[2], {sh[0], sh[1], sh[2]},
                                 triangles, ideal);
            addTriangleWithIdeal(v[0], v[2], v[3], {sh[0], sh[2], sh[3]},
                                 triangles, ideal);
            addTriangleWithIdeal(v[0], v[1], v[3], {sh[0], sh[1], sh[3]},
                                 triangles, ideal);
            addTriangleWithIdeal(v[1], v[2], v[3], {sh[1], sh[2], sh[3]},
                                 triangles, ideal);
          }
          else {
            addPositiveTriangle(v[0], v[1], v[2], points, triangles, ideal);
            addPositiveTriangle(v[0], v[2], v[3], points, triangles, ideal);
            addPositiveTriangle(v[0], v[1], v[3], points, triangles, ideal);
            addPositiveTriangle(v[1], v[2], v[3], points, triangles, ideal);
          }
        }
      }
      else if(type == MSH_TRI_6 || type == MSH_QUA_9) {
        bezierCoeff *bez = e->getBezierVerticesCoord();
        const bool isTri = type == MSH_TRI_6;
        const int n = isTri ? 6 : 9;
        if(bez->getNumCoeff() < n) {
          delete bez;
          continue;
        }
        BezierPatchElement pe;
        pe.element = e;
        pe.isTriangle = isTri;
        uint32_t v[9];
        for(int i = 0; i < n; ++i) {
          const int iBez =
            isTri ? triBezierCoeffFromVertex[i] : quadBezierCoeffFromVertex[i];
          MVertex *owner = e->getVertex(i);
          v[i] = addBezierPoint(owner, bezierPoint(*bez, iBez),
                                lockedVertices.count(owner), plane, indices,
                                points, locked);
          pe.bezierPoints[i] = v[i];
        }
        if(isTri) {
          for(const auto &t : triBezierTriangles)
            addPositiveTriangle(v[t[0]], v[t[1]], v[t[2]], points, triangles,
                                ideal);
        }
        else {
          for(const auto &t : quadBezierTriangles)
            addPositiveTriangle(v[t[0]], v[t[1]], v[t[2]], points, triangles,
                                ideal);
        }
        patchElements.push_back(pe);
        delete bez;
      }
    }

    removeLockedTriangles(locked, triangles, ideal);
    if(triangles.empty()) return true;

    bool ok = untangle_triangles_2D_GMSH(
      points, locked, triangles, ideal, options.lambda, options.iterMaxInner,
      options.iterMaxOuter, options.iterFailMax, options.timeMax, false);

    if(!patchElements.empty()) {
      updateP2LagrangeNodes(gf, plane, patchElements, points, locked, maxMove);
    }
    else {
      for(const auto &it : indices) {
        if(locked[it.second]) continue;
        Vec3 before = vertexPoint(it.first);
        setVertexOnFace(gf, it.first, unproject(plane, points[it.second]));
        if(maxMove)
          *maxMove = std::max(*maxMove, norm(vertexPoint(it.first) - before));
      }
    }

    if(options.writePatchDebugPos)
      Msg::Info("Mean-plane surface untangler face %d: patch with %zu "
                "elements, %zu points, %zu triangles%s",
                gf ? gf->tag() : 0, patch.size(), points.size(),
                triangles.size(), ok ? "" : " (failed)");
    return true;
  }

  static std::size_t untangleMeanPlaneSweep(
    GFace *gf, const std::vector<SurfaceElementInfo> &infos,
    const std::set<MVertex *, MVertexPtrLessThan> &effectiveFixed,
    const MeanPlaneSurfaceUntanglerOptions &options, int sweep, bool &ok,
    double &maxMove, const std::map<MElement *, double> *layers = nullptr,
    const OriginalElementGeometryMap *original = nullptr)
  {
    const SurfacePatchGraph graph = buildSurfacePatchGraph(infos);
    std::vector<MVertex *> seeds = shuffledSurfaceSeeds(gf, graph.v2e, sweep);

    const double diag = gf ? gf->bounds().diag() : 1.;
    const double scale = std::max(diag, 1.e-30);
    const double baseTolerance =
      std::max(options.distanceTolerance * scale, 1.e-14 * scale);
    double minTolerance =
      options.extensionDistanceTolerance > 0. ?
        options.extensionDistanceTolerance * scale :
        1.e-14 * scale;
    minTolerance = std::min(minTolerance, baseTolerance);
    const int maxDepth = std::numeric_limits<int>::max();

    std::size_t numPatches = 0;
    std::set<MVertex *, MVertexPtrLessThan> touched;
    for(MVertex *seed : seeds) {
      if(effectiveFixed.find(seed) != effectiveFixed.end()) continue;
      if(touched.find(seed) != touched.end()) continue;

      std::vector<int> patch;
      Plane plane;
      if(!buildPatchWithRetries(seed, graph, infos, baseTolerance,
                                minTolerance, maxDepth, patch, plane))
        continue;

      ok = untanglePatch(gf, patch, infos, effectiveFixed, options, layers,
                         original, &plane, &maxMove) &&
           ok;
      numPatches++;

      std::vector<MVertex *> all, boundary;
      collectPatchVerticesAndBoundary(patch, infos, all, boundary);
      for(MVertex *v : all) touched.insert(v);
    }
    return numPatches;
  }

}

bool untangleSurfaceMeanPlanePatches(
  GFace *gf, const std::set<MElement *, MElementPtrLessThan> &toProcess,
  const std::set<MVertex *, MVertexPtrLessThan> &fixed,
  const MeanPlaneSurfaceUntanglerOptions &options)
{
  if(!gf) return false;

  std::set<MVertex *, MVertexPtrLessThan> effectiveFixed;
  augmentSurfaceFixedVertices(gf, toProcess, fixed, effectiveFixed);
  bool ok = true;
  const int numSweeps = std::max(1, options.numSweeps);
  const double scale = std::max(gf->bounds().diag(), 1.e-30);
  const double moveTolerance =
    std::max(options.moveTolerance, 0.) * scale;
  for(int sweep = 0; sweep < numSweeps; ++sweep) {
    std::vector<SurfaceElementInfo> infos;
    for(auto e : gf->triangles)
      if(toProcess.find(e) != toProcess.end() && isSupportedElement(e))
        infos.push_back(elementInfo(e));
    for(auto e : gf->quadrangles)
      if(toProcess.find(e) != toProcess.end() && isSupportedElement(e))
        infos.push_back(elementInfo(e));
    if(infos.empty()) return true;

    double maxMove = 0.;
    std::size_t numPatches =
      untangleMeanPlaneSweep(gf, infos, effectiveFixed, options, sweep, ok,
                             maxMove);
    if(options.verbose)
      Msg::Info("Mean-plane surface untangler face %d sweep %d/%d: %zu "
                "elements, %zu BFS patches processed, max move %.6g",
                gf->tag(), sweep + 1, numSweeps, infos.size(),
                numPatches, maxMove);
    if(numPatches == 0 || maxMove <= moveTolerance) break;
  }
  return ok;
}

bool untangleSurfaceMeanPlanePatchesP1(
  GFace *gf, const std::set<MElement *, MElementPtrLessThan> &toProcess,
  const std::set<MVertex *, MVertexPtrLessThan> &fixed,
  const std::map<MElement *, double> &layers,
  const MeanPlaneSurfaceUntanglerOptions &options)
{
  if(!gf) return false;

  std::set<MVertex *, MVertexPtrLessThan> effectiveFixed;
  augmentSurfaceFixedVertices(gf, toProcess, fixed, effectiveFixed);
  OriginalElementGeometryMap original;
  for(MElement *e : toProcess) {
    const int type = e->getTypeForMSH();
    if(type != MSH_TRI_3 && type != MSH_QUA_4) continue;
    OriginalElementGeometry geom;
    const int n = (int)e->getNumPrimaryVertices();
    geom.points.reserve(n);
    for(int i = 0; i < n; ++i)
      geom.points.push_back(vertexPoint(e->getVertex(i)));
    buildP1ReferenceTriangles(e, geom, layers);
    original[e] = geom;
  }

  bool ok = true;
  const int numSweeps = std::max(1, options.numSweeps);
  const double scale = std::max(gf->bounds().diag(), 1.e-30);
  const double moveTolerance =
    std::max(options.moveTolerance, 0.) * scale;
  for(int sweep = 0; sweep < numSweeps; ++sweep) {
    std::vector<SurfaceElementInfo> infos;
    for(auto e : gf->triangles)
      if(toProcess.find(e) != toProcess.end() &&
         e->getTypeForMSH() == MSH_TRI_3)
        infos.push_back(elementInfo(e));
    for(auto e : gf->quadrangles)
      if(toProcess.find(e) != toProcess.end() &&
         e->getTypeForMSH() == MSH_QUA_4)
        infos.push_back(elementInfo(e));
    if(infos.empty()) return true;

    double maxMove = 0.;
    std::size_t numPatches =
      untangleMeanPlaneSweep(gf, infos, effectiveFixed, options, sweep, ok,
                             maxMove, &layers, &original);
    if(options.verbose)
      Msg::Info("Mean-plane P1 surface untangler face %d sweep %d/%d: %zu "
                "elements, %zu BFS patches processed, max move %.6g",
                gf->tag(), sweep + 1, numSweeps, infos.size(),
                numPatches, maxMove);
    if(numPatches == 0 || maxMove <= moveTolerance) break;
  }
  return ok;
}
