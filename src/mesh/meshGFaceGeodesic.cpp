#include "GEntity.h"
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "Context.h"
#include "GFace.h"
#include "MTriangle.h"
#include "SPoint3.h"
#include "SVector3.h"
#include "geodesic_constants_and_simple_functions.h"
#include "meshPolyMesh.h"
#include "meshTriangulation.h"

#include <algorithm>
#include <array>
#include <cstddef>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <ostream>
#include <random>
#include <stdexcept>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include "meshGFaceGeodesic.h"
#include <chrono>

#if defined(HAVE_MESH) && defined(HAVE_GEODESIC)

#include "qualityMeasures.h"
#include "GModelParametrize.h"
#include "geodesic_algorithm_exact.h"
#include "geodesic_mesh_elements.h"

#define DEBUG false
#define PRINT false
#define WARNING false
#define ASTAR true
#define EPS 1e-12
#define CIRCUMMULT 5
#define PRECOMPUTE_CIRCUMCENTERS false

#define MINANGLE (CTX::instance()->mesh.minIntrinsicAngle)
#define MAXANGLE CTX::instance()->mesh.maxIntrinsicAngle
#define MINAHEURISTIC MINANGLE
#define MAXAHEURISTIC MAXANGLE

#define SWAP_AFTER_COLLAPSE true

#define LENGTH_CRITERION CTX::instance()->mesh.maxIntrinsicEdgeStretch
#define LENGTH_QUALITY 1 / (LENGTH_CRITERION)

#define RATIO_CRITERION 1e100
#define AREA_RATIO 1e100
#define FLAT_AREA_RATIO CTX::instance()->mesh.maxFlatAreaChange

static int getNumThreads();

template <typename T>
T interpolate(std::vector<T> &values, geodesic::SurfacePoint &sp)
{
  if(values.empty()) Msg::Error("values not defined");
  if(sp.type() == geodesic::VERTEX) {
    geodesic::Vertex *v = (geodesic::Vertex *)sp.base_element();

    if(values.size() - 1 < v->id()) Msg::Error("Value not defined for vertex");
    return values[v->id()];
  }

  if(sp.type() == geodesic::EDGE) {
    geodesic::Edge *e = (geodesic::Edge *)sp.base_element();
    geodesic::Vertex *v0 = e->v0();
    geodesic::Vertex *v1 = e->v1();

    SVector3 d = SVector3(sp.x() - v0->x(), sp.y() - v0->y(), sp.z() - v0->z());
    SVector3 d1 =
      SVector3(v1->x() - v0->x(), v1->y() - v0->y(), v1->z() - v0->z());
    double t = dot(d1, d) / dot(d1, d1);

    if(values.size() - 1 < v0->id() || values.size() - 1 < v1->id())
      Msg::Error("Value not defined for vertex");
    T p0 = values[v0->id()];
    T p1 = values[v1->id()];
    T p = ((1 - t) * p0 + t * p1);
    return p;
  }

  if(sp.type() == geodesic::FACE) {
    geodesic::Face *f = (geodesic::Face *)sp.base_element();
    auto &v0 = f->adjacent_vertices()[0];
    auto &v1 = f->adjacent_vertices()[1];
    auto &v2 = f->adjacent_vertices()[2];

    SVector3 d = SVector3(sp.x() - v0->x(), sp.y() - v0->y(), sp.z() - v0->z());
    SVector3 d1 =
      SVector3(v1->x() - v0->x(), v1->y() - v0->y(), v1->z() - v0->z());
    SVector3 d2 =
      SVector3(v2->x() - v0->x(), v2->y() - v0->y(), v2->z() - v0->z());
    double a = crossprod(d1, d2).norm();
    double v = crossprod(d1, d).norm() / a;
    double u = crossprod(d, d2).norm() / a;

    if(values.size() - 1 < v0->id() || values.size() - 1 < v1->id() ||
       values.size() - 1 < v2->id())
      Msg::Error("Value not defined for vertex");
    T p0 = values[v0->id()];
    T p1 = values[v1->id()];
    T p2 = values[v2->id()];
    T p = ((1 - u - v) * p0 + u * p1 + v * p2);
    return p;
  }

  Msg::Error("SurfacePoint type unknown");
  return T();
}

// SPoint3 highOrderPolyMesh::getTrueCoords(geodesic::SurfacePoint &sp)
// {
//   SVector3 p = interpolate<SVector3>(trueCoord, sp);
//   return SPoint3(p);
// }

double highOrderPolyMesh::cl(geodesic::SurfacePoint &sp)
{
  double p = interpolate<double>(characLength, sp);
  return p;
}
double highOrderPolyMesh::clMin(geodesic::SurfacePoint &sp)
{
  double p = interpolate<double>(characLengthMin, sp);
  return p;
}
double highOrderPolyMesh::clMax(geodesic::SurfacePoint &sp)
{
  double p = interpolate<double>(characLengthMax, sp);
  return p;
}

PolyMesh *createPolyMesh(const std::vector<double> &p,
                         const std::vector<size_t> &t,
                         const std::vector<size_t> &e,
                         const std::vector<size_t> &vertexNum)
{
  PolyMesh *pm_new = new PolyMesh;

  // int cc = 0;
  for(size_t i = 0; i < p.size(); i += 3) {
    int tag = vertexNum.empty() ? i / 3 : vertexNum[i / 3];
    pm_new->vertices.push_back(
      new PolyMesh::Vertex(p[i], p[i + 1], p[i + 2], tag));
  }

  for(size_t i = 0; i < t.size(); i += 3) {
    PolyMesh::HalfEdge *he[3];
    for(std::size_t j = 0; j < 3; j++) {
      PolyMesh::Vertex *vv = pm_new->vertices[t[i + j]];
      he[j] = new PolyMesh::HalfEdge(vv);
      pm_new->hedges.push_back(he[j]);
      vv->he = he[j];
    }
    PolyMesh::Face *ff = new PolyMesh::Face(he[0]);
    ff->data = pm_new->faces.size();
    pm_new->faces.push_back(ff);
    for(int j = 0; j < 3; j++) {
      he[j]->next = he[(j + 1) % 3];
      he[j]->prev = he[(j - 1 + 3) % 3];
      he[j]->f = ff;
      // if(he[j]->v->data == 302 && he[j]->next->v->data == 2)
      //   std::cout << i << " " << j << " " << he[j]->v->data << " "
      //             << he[j]->next->v->data << std::endl;
    }
  }

  HalfEdgePtrLessThan compare;
  std::sort(pm_new->hedges.begin(), pm_new->hedges.end(), compare);

  HalfEdgePtrEqual equal;
  for(size_t i = 0; i + 1 < pm_new->hedges.size(); i++) {
    PolyMesh::HalfEdge *h0 = pm_new->hedges[i];
    PolyMesh::HalfEdge *h1 = pm_new->hedges[i + 1];
    // if(h0->opposite || h1->opposite) throw std::runtime_error("not ok");
    if(equal(h0, h1)) {
      if(h0->v->data == h1->v->data && h0->next->v->data == h1->next->v->data)
        Msg::Error(
          "Two times the same half edge when remeshing after cutting mesh");
      h0->opposite = h1;
      h1->opposite = h0;
      i++;
    }
  }

  if(e.size() == 0) return pm_new;

  // for(size_t i = 0; i + 1 < pm_new->hedges.size(); i++) {
  //   PolyMesh::HalfEdge *h0 = pm_new->hedges[i];
  //   PolyMesh::HalfEdge *h1 = pm_new->hedges[i + 1];
  //   if(h0->v->data == h1->v->data && h0->next->v->data == h1->next->v->data)
  //     throw std::runtime_error("same he");
  // }

  for(size_t i = 0; i < e.size(); i += 3) {
    PolyMesh::Vertex *v0 = pm_new->vertices[e[i]];
    PolyMesh::Vertex *v1 = pm_new->vertices[e[i + 1]];
    PolyMesh::HalfEdge *he01 = pm_new->getEdge(v0, v1);
    PolyMesh::HalfEdge *he10 = pm_new->getEdge(v1, v0);
    // if(e[i + 2] == 68)
    //   std::cout << e[i + 2] << ": " << v0->data << " " << v1->data <<
    //   std::endl;
    if(he01) {
      // if(e[i + 2] == 68)
      //   std::cout << "\t" << e[i + 2] << ": " << he01->v->data << " "
      //             << he01->next->v->data << std::endl;
      he01->data = e[i + 2];
    }
    else
      Msg::Debug("Non existing edge -- %d %d", e[i], e[i + 1]);
    if(he10) {
      // if(e[i + 2] == 68)
      //   std::cout << "\t" << e[i + 2] << ": " << he10->v->data << " "
      //             << he10->next->v->data << std::endl;
      he10->data = e[i + 2];
    }
    else
      Msg::Debug("Non existing edge -- %d %d", e[i], e[i + 1]);
    // if(e[i + 2] == 68) std::cout << std::endl;
  }

  for(auto f : pm_new->faces) f->data = -1;
  int faceTag = 1;
  for(auto f : pm_new->faces) {
    if(f->data == -1) {
      std::stack<PolyMesh::Face *> _s;
      _s.push(f);
      int count = 1;
      f->data = faceTag;
      while(!_s.empty()) {
        PolyMesh::Face *_f = _s.top();
        _s.pop();
        PolyMesh::HalfEdge *he = _f->he;
        do {
          if(he->data == -1 && he->opposite && he->opposite->f->data == -1) {
            he->opposite->f->data = faceTag;
            count++;
            _s.push(he->opposite->f);
          }
          he = he->next;
        } while(he != _f->he);
      }
      faceTag++;
    }
  }

  // Msg::Info("%d isogeometric triangles were generated", faceTag - 1);

  return pm_new;
}

static PolyMesh *createPolyMesh(PolyMesh *pm, const std::vector<size_t> &t,
                                const std::vector<size_t> &e)
{
  int cc = 0;
  std::vector<double> pos;
  for(auto vv : pm->vertices) {
    if(cc++ != vv->data) Msg::Warning("Wrong numbering %d %d", cc, vv->data);
    pos.push_back(vv->position.x());
    pos.push_back(vv->position.y());
    pos.push_back(vv->position.z());
  }

  PolyMesh *pm_new = createPolyMesh(pos, t, e);

  return pm_new;
}

static void filterPath(std::vector<geodesic::SurfacePoint> &path, double eps)
{
  // Snap to close vertices
  for(size_t i = 1; i < path.size() - 1; i++) {
    if(path[i].type() == geodesic::VERTEX) continue;
    double minD = 1e100;
    geodesic::Vertex *minV = nullptr;
    for(auto v : path[i].base_element()->adjacent_vertices()) {
      SVector3 dx(v->x() - path[i].x(), v->y() - path[i].y(),
                  v->z() - path[i].z());
      double d = norm(dx);
      if(d < minD) {
        minD = d;
        minV = v;
      }
    }
    double local_eps = 0.;
    if(path[i].type() == geodesic::EDGE)
      local_eps += ((geodesic::Edge *)path[i].base_element())->length();
    else {
      for(int j = 0; j < 3; ++j)
        local_eps += path[i].base_element()->adjacent_edges()[j]->length();
    }
    local_eps *= eps;
    if(minD < local_eps) { path[i] = geodesic::SurfacePoint(minV); }
  }

  // Remove redundant points
  for(int ii = 0; ii < 2; ++ii) {
    std::vector<geodesic::SurfacePoint> filtered_path;
    filtered_path.push_back(*path.begin());
    for(size_t i = 1; i < path.size() - 1; i++) {
      if(path[i].base_element() == filtered_path.back().base_element())
        continue;
      // if(filtered_path.back().type() == geodesic::VERTEX &&
      //    path[i].type() == geodesic::EDGE) {
      //   auto &adjEdges =
      //   filtered_path.back().base_element()->adjacent_edges(); geodesic::Edge
      //   *e = (geodesic::Edge *)path[i].base_element();
      //   if(std::find(adjEdges.begin(), adjEdges.end(), e) != adjEdges.end())
      //     continue;
      // }
      filtered_path.push_back(path[i]);
    }
    filtered_path.push_back(*path.rbegin());
    std::reverse(filtered_path.begin(), filtered_path.end());
    path = filtered_path;
  }
}

static void polyMeshToGeodesicMesh(PolyMesh *pm, geodesic::Mesh &mesh,
                                   std::map<PolyMesh::Face *, int> &f2n)
{
  std::vector<double> _points;
  std::vector<unsigned> _faces;
  int num = 0;
  for(auto v : pm->vertices) {
    _points.push_back(v->position.x());
    _points.push_back(v->position.y());
    _points.push_back(v->position.z());
    v->data = num++;
  }
  int nnn = 0;
  for(auto f : pm->faces) {
    _faces.push_back(f->he->v->data);
    _faces.push_back(f->he->next->v->data);
    _faces.push_back(f->he->next->next->v->data);
    f2n[f] = nnn++;
  }
  mesh.initialize_mesh_data(_points, _faces);
}

bool compareVertexOnHalfEdge(const PolyMesh::Vertex *v0,
                             const PolyMesh::Vertex *v1)
{
  SVector3 d0 = v0->position;
  SVector3 d1 = v1->position;
  return d0.norm() < d1.norm();
};

// -- M A I N    C L A S S

int highOrderPolyMesh::getTag(const std::pair<int, int> &e2)
{
  std::pair<int, int> e = std::make_pair(std::min(e2.first, e2.second),
                                         std::max(e2.first, e2.second));
  auto it = tags.find(e);
  if(it == tags.end()) { tags[e] = maxTag++; }
  return tags[e];
}

SVector3 highOrderPolyMesh::normal(geodesic::base_pointer b)
{
  SVector3 n(0, 0, 0);
  if(b->type() == geodesic::VERTEX || b->type() == geodesic::EDGE) {
    for(int i = 0; i < b->adjacent_faces().size(); ++i)
      n += normal(b->adjacent_faces()[i]);
  }
  else if(b->type() == geodesic::FACE) {
    SVector3 p0 = b->adjacent_vertices()[0]->xyz();
    SVector3 p1 = b->adjacent_vertices()[1]->xyz();
    SVector3 p2 = b->adjacent_vertices()[2]->xyz();
    SVector3 t0(p2 - p0);
    SVector3 t1(p1 - p0);
    n = crossprod(t1, t0);
  }
  else
    Msg::Error("Unknown type");
  if(norm(n) < 1e-12) {
    // std::cout << b->adjacent_vertices()[0]->id() << " "
    //           << b->adjacent_vertices()[1]->id() << std::endl;
    // Msg::Error("norm(n) is null: %g", norm(n));
    Msg::Warning("norm(n) is null: %g", norm(n));
    return SVector3(0., 0., 0.);
  }
  // std::cout << "n=" << n.x() << " " << n.y() << " " << n.z() << std::endl;
  n.normalize();
  return n;
}

SVector3 highOrderPolyMesh::normal(int p)
{
  return normal(pointsPool[p].base_element());
}

double highOrderPolyMesh::computeAngle(SVector3 v01, SVector3 v02)
{
  double cos = dot(v01, v02);
  double sin = norm(crossprod(v01, v02));
  double angle = atan2(sin, cos);
  if(angle < -1e-12) angle = M_PI - angle;
  if(angle < +1e-12) angle = 0.;
  return angle;
}

inline double computeAngle2d(double pa[2], double pb[2], double pc[2])
{
  SVector3 p01(pb[0] - pa[0], pb[1] - pa[1], 0);
  SVector3 p02(pc[0] - pa[0], pc[1] - pa[1], 0);
  // double d =
  //   (pb[0] - pa[0]) * (pc[0] - pa[0]) + (pb[1] - pa[1]) * (pc[1] - pa[1]);
  double d = dot(p01, p02);
  SVector3 c = crossprod(p01, p02);
  double nc = norm(c);
  // double nc =
  //   abs((pb[0] - pa[0]) * (pc[1] - pa[1]) - (pb[1] - pa[1]) * (pc[0] -
  //   pa[0]));
  double o = robustPredicates::orient2d(pa, pb, pc);
  if(o == 0. && d >= 0.) return 0.;
  if(o == 0. && d < 0.) return M_PI;
  double s = (o < 0.) ? -1 : +1;
  // double s = (c.z() < 0.) ? -1 : +1;
  double angle = atan2(s * nc, d);
  if(angle < 0.) angle += 2 * M_PI;
  return angle;
  //
  // double o = robustPredicates::orient2d(pa, pb, pc);
  // double cross =
  //   (pb[0] - pa[0]) * (pc[1] - pa[1]) - (pb[1] - pa[1]) * (pc[0] - pa[0]);
  // double dot =
  //   (pb[0] - pa[0]) * (pc[0] - pa[0]) + (pb[1] - pa[1]) * (pc[1] - pa[1]);
  // if(o < 0.) cross *= -1 * abs(cross);
  // double angle = atan2(cross, dot);
  // // std::cout << "o: " << o << std::endl;
  // // std::cout << "oangle: " << angle << std::endl;
  // // if(o > 0. && angle > 0.) angle  = M_PI -angle;
  // // if(o < 0. && angle < 0.) angle  = M_PI -angle;
  // // if(o < 0. && angle < 0.) angle *= -1;
  // // std::cout << "oangle: " << angle << std::endl;
  // // if(o == 0.) angle = 0.;
  // // std::cout << "oangle: " << angle << std::endl;
  // // // angle *= (o > 0) - (o < 0);
  //
  // if(angle < 0.) angle += 2 * M_PI;
  // std::cout << "oangle: " << angle << std::endl;
  // return angle;
}

inline bool onFace(geodesic::SurfacePoint &sp, geodesic::Face *f)
{
  if(sp.type() == geodesic::FACE) {
    if(f == sp.base_element()) return true;
  }
  else {
    for(auto spf : sp.base_element()->adjacent_faces()) {
      if(f == spf) return true;
    }
  }
  return false;
}

inline bool swappedEdge(geodesic::Edge *e, geodesic::Face *f)
{
  for(int i = 0; i < 3; ++i) {
    if(f->adjacent_vertices()[i] == e->v0() &&
       f->adjacent_vertices()[(i + 1) % 3] == e->v1())
      return false;
    if(f->adjacent_vertices()[i] == e->v1() &&
       f->adjacent_vertices()[(i + 1) % 3] == e->v0())
      return true;
  }
  Msg::Error("could not find orientation");
  return false;
}

inline void local_coordinates(double p0[3], double p1[3], double p[3],
                              double lc[2])
{
  SVector3 v0(p0, p);
  double d0 = norm(v0);
  if(d0 < 1e-14) {
    lc[0] = 0.0;
    lc[1] = 0.0;
    return;
  }

  SVector3 v1(p1, p);
  double d1 = norm(v1);
  if(d1 < 1e-14) {
    lc[0] = 1.;
    lc[1] = 0.0;
    return;
  }

  SVector3 v01(p0, p1);
  double d01 = norm(v01);
  lc[0] = d01 / 2.0 + (d0 * d0 - d1 * d1) / (2.0 * d01);
  lc[1] = sqrt(std::max(0.0, d0 * d0 - lc[0] * lc[0]));
  lc[0] *= 1. / d01;
  lc[1] *= 1. / d01;
}

double highOrderPolyMesh::computeIntrinsicAngle(geodesic::SurfacePoint &p0,
                                                geodesic::SurfacePoint &p1,
                                                geodesic::SurfacePoint &p2)
{
  if(p0.type() == geodesic::FACE) {
    double oangle;
    {
      geodesic::Face *f = static_cast<geodesic::Face *>(p0.base_element());
      geodesic::Vertex *v0 = f->adjacent_vertices()[0],
                       *v1 = f->adjacent_vertices()[1];
      double pa[2], pb[2], pc[2];
      local_coordinates(v0->xyz(), v1->xyz(), p0.xyz(), pa);
      local_coordinates(v0->xyz(), v1->xyz(), p1.xyz(), pb);
      local_coordinates(v0->xyz(), v1->xyz(), p2.xyz(), pc);
      oangle = computeAngle2d(pa, pb, pc);
      return oangle;
    }

    // for(int i = 0; i < 2; ++i) {
    //   auto p = (i == 0) ? p1 : p2;
    //   if(p.type() == geodesic::FACE) {
    //     if(p.base_element() != p0.base_element())
    //       Msg::Error("(FACE) p0 and p%d are not on the same face", i + 1);
    //   }
    //   else {
    //     auto faces = p.base_element()->adjacent_faces();
    //     int j = 0;
    //     for(; j < faces.size(); ++j) {
    //       if(faces[j] == p0.base_element()) break;
    //     }
    //     if(j == faces.size())
    //       Msg::Error("(FACE) p0 and p%d do not share a face", i + 1);
    //   }
    // }
    //
    // SVector3 v01((p0).xyz(), (p1).xyz());
    // SVector3 v02((p0).xyz(), (p2).xyz());
    //
    // SVector3 n = normal(p0.base_element());
    // double angle = computeAngle(v01, v02, n);
    // // if(abs(angle - oangle) > 1e-2) {
    // //   std::cout << angle << " " << oangle << " " << angle - oangle <<
    // //   std::endl; Msg::Error("false V");
    // // }
    // return angle;
  }

  if(p0.type() == geodesic::EDGE) {
    // double oangle;
    {
      geodesic::Edge *e = static_cast<geodesic::Edge *>(p0.base_element());
      geodesic::Face *f = e->adjacent_faces()[0];
      geodesic::Vertex *v0 = e->v0(), *v1 = e->v1();
      if(swappedEdge(e, f)) { v0 = e->v1(), v1 = e->v0(); }
      double pa[2], pb[2], pc[2];
      local_coordinates(v0->xyz(), v1->xyz(), p0.xyz(), pa);
      local_coordinates(v0->xyz(), v1->xyz(), p1.xyz(), pb);
      local_coordinates(v0->xyz(), v1->xyz(), p2.xyz(), pc);
      if(!onFace(p1, f)) pb[1] *= -1;
      if(!onFace(p2, f)) pc[1] *= -1;
      return computeAngle2d(pa, pb, pc);
      // oangle = computeAngle2d(pa, pb, pc);
    }

    // geodesic::Face *fs[2] = {nullptr, nullptr};
    // for(int i = 0; i < 2; ++i) {
    //   auto p = (i == 0) ? p1 : p2;
    //   if(p.type() == geodesic::FACE) {
    //     if(p.base_element() == p0.base_element()->adjacent_faces()[0] ||
    //        p.base_element() == p0.base_element()->adjacent_faces()[1]) {
    //       fs[i] = (geodesic::Face *)p.base_element();
    //     }
    //   }
    //   else {
    //     auto faces = p.base_element()->adjacent_faces();
    //     for(int j = 0; j < faces.size(); ++j) {
    //       if(faces[j] == p0.base_element()->adjacent_faces()[0] ||
    //          faces[j] == p0.base_element()->adjacent_faces()[1]) {
    //         fs[i] = faces[j];
    //         break;
    //       }
    //     }
    //   }
    //   if(fs[i] == nullptr) {
    //     std::cout << "p0 " << p0.type() << " " << p0.base_element()->id()
    //               << std::endl;
    //     std::cout << "p2 " << p2.type() << " " << p2.base_element()->id()
    //               << std::endl;
    //     Msg::Error("(EDGE) p0 and p%d do not share a face", i + 1);
    //   }
    // }
    //
    // geodesic::Vertex *v = nullptr;
    // for(int i = 0; i < 3; ++i) {
    //   auto vv = fs[0]->adjacent_vertices()[i];
    //   if(vv != p0.base_element()->adjacent_vertices()[0] &&
    //      vv != p0.base_element()->adjacent_vertices()[1]) {
    //     v = fs[0]->adjacent_vertices()[(i + 1) % 3];
    //     break;
    //   }
    // }
    // SVector3 v01((p0).xyz(), (p1).xyz());
    // geodesic::SurfacePoint sp(v);
    // SVector3 v02((p0).xyz(), (sp).xyz());
    // double a1, a2;
    // SVector3 n = normal(fs[0]);
    // a1 = computeAngle(v01, v02, n);
    //
    // if(fs[0] == fs[1]) {
    //   v01 = SVector3((p0).xyz(), (p2).xyz());
    //   a2 = computeAngle(v01, v02, n);
    //
    //   double angle = a1 - a2;
    //   if(angle < 0.) angle += 2 * M_PI;
    //   // if(abs(angle - oangle) > 1e-3) { Msg::Error("false 2"); }
    //   return angle;
    // }
    // else {
    //   v01 = v02;
    //   v02 = SVector3((p0).xyz(), (p2).xyz());
    //   n = normal(fs[1]);
    //   double a2;
    //   a2 = computeAngle(v01, v02, n);
    //   // if(abs(a1 + a2 - oangle) > 1e-3) { Msg::Error("false 2"); }
    //   return a1 + a2;
    // }
  }

  if(p0.type() == geodesic::VERTEX) {
    double oangle;
    {
      geodesic::Face *f1 = nullptr, *f2 = nullptr;
      geodesic::Vertex *v0 = static_cast<geodesic::Vertex *>(p0.base_element()),
                       *v1 = nullptr, *v2 = nullptr;

      auto fcs = p0.base_element()->adjacent_faces();
      for(auto fc : fcs) {
        if(onFace(p1, fc)) f1 = fc;
        if(onFace(p2, fc)) f2 = fc;
      }

      int i = 0;
      for(; i < 3; ++i) {
        if(f1->adjacent_vertices()[i] != v0) continue;
        v1 = f1->adjacent_vertices()[(i + 1) % 3];
        v2 = f1->adjacent_vertices()[(i + 2) % 3];
        break;
      }
      if(i == 3) Msg::Error("Not right i");
      double pa[2], pb[2], pc[2];
      local_coordinates(v0->xyz(), v1->xyz(), p0.xyz(), pa);
      local_coordinates(v0->xyz(), v1->xyz(), p1.xyz(), pb);
      bool skip = false;
      if(f1 == f2) {
        local_coordinates(v0->xyz(), v1->xyz(), p2.xyz(), pc);
        double angle = computeAngle2d(pa, pb, pc);
        // std::cout << "same face: " << angle << std::endl;
        // std::cout << "okt " << angle << std::endl;
        if(angle < M_PI) {
          oangle = angle;
          skip = true;
          return angle;
        }
      }

      if(!skip) {
        local_coordinates(v0->xyz(), v1->xyz(), v2->xyz(), pc);
        double angle = computeAngle2d(pa, pb, pc);
        // std::cout << "first face: " << angle << std::endl;
        geodesic::Face *f = f1;
        do {
          geodesic::Edge *e = f->opposite_edge(v1);
          f = (e->adjacent_faces()[0] == f) ? e->adjacent_faces()[1] :
                                              e->adjacent_faces()[0];
          for(int i = 0; i < 3; ++i) {
            if(f->adjacent_vertices()[i] != v0) continue;
            v1 = f->adjacent_vertices()[(i + 1) % 3];
            v2 = f->adjacent_vertices()[(i + 2) % 3];
            if(f != f2) angle += f->corner_angles()[i];
            // std::cout << "current face: " << angle << std::endl;

            break;
          }
          if(f == f2) break;
        } while(f != f1);

        local_coordinates(v0->xyz(), v1->xyz(), p0.xyz(), pa);
        local_coordinates(v0->xyz(), v1->xyz(), v1->xyz(), pb);
        local_coordinates(v0->xyz(), v1->xyz(), p2.xyz(), pc);
        // return angle + computeAngle2d(pa, pb, pc);
        angle += computeAngle2d(pa, pb, pc);
        // std::cout << "last face: " << angle << std::endl;
        return angle;
        // oangle = angle;
      }
    }

    ////
    ////
    ////
    ////
    ////
    ////
    ////
    ////
    ////
    ////
    ////
    ////
    ////
    ////
    //////
    //////
    //////
    //////
    //////
    // auto fcs = p0.base_element()->adjacent_faces();
    // geodesic::Face *fs[2] = {nullptr, nullptr};
    // for(int i = 0; i < 2; ++i) {
    //   auto p = (i == 0) ? p1 : p2;
    //
    //   for(int j = 0; j < fcs.size(); ++j) {
    //     if(onFace(p, fcs[j])) fs[i] = fcs[j];
    //   }
    //
    //   // if(p.type() == geodesic::FACE) {
    //   //   for(int j = 0; j < fcs.size(); ++j) {
    //   //     if(fcs[j] == p.base_element()) {
    //   //       fs[i] = fcs[j];
    //   //       break;
    //   //     }
    //   //   }
    //   // }
    //   // else {
    //   //   auto faces = p.base_element()->adjacent_faces();
    //   //   for(int j = 0; j < faces.size(); ++j) {
    //   //     auto it = std::find(fcs.begin(), fcs.end(), faces[j]);
    //   //     if(it != fcs.end()) {
    //   //       fs[i] = faces[j];
    //   //       break;
    //   //     }
    //   //   }
    //   // }
    //   if(fs[i] == nullptr) {
    //     std::cout << p0.x() << " " << p0.y() << " " << p0.z() << " "
    //               << std::endl;
    //     std::cout << p2.x() << " " << p2.y() << " " << p2.z() << " "
    //               << std::endl;
    //     Msg::Error("(VERTEX) p0 and p%d are not on the same face", i + 1);
    //   }
    // }
    //
    // if(fs[0] == fs[1]) {
    //   SVector3 v01((p0).xyz(), (p1).xyz());
    //   SVector3 v02((p0).xyz(), (p2).xyz());
    //   SVector3 n = normal(fs[0]);
    //   double angle = computeAngle(v01, v02, n);
    //   // std::cout << "- same face " << angle << std::endl;
    //   if(angle < M_PI) {
    //     // if(abs(oangle - angle) > 1e-3) {
    //     //   std::cout << angle << " " << oangle << " diff=" << oangle -
    //     angle
    //     //             << std::endl;
    //     //   Msg::Error("Not same angles");
    //     // }
    //     return angle;
    //   }
    // }
    //
    // double angle = 0.;
    // geodesic::Face *f = fs[0];
    // geodesic::Vertex *v = nullptr;
    // for(int i = 0; i < 3; ++i) {
    //   if(fs[0]->adjacent_vertices()[i] == p0.base_element()) {
    //     v = fs[0]->adjacent_vertices()[(i + 2) % 3];
    //     break;
    //   }
    // }
    // SVector3 v01((p0).xyz(), (p1).xyz());
    // geodesic::SurfacePoint sp(v);
    // SVector3 v02((p0).xyz(), (sp).xyz());
    // SVector3 n = normal(fs[0]);
    // angle = computeAngle(v01, v02, n);
    //// std::cout << "- first face " << angle << std::endl;
    //// std::cout << angle << std::endl;
    //
    // for(int i = 0; i < 3; ++i) {
    //  auto e = f->adjacent_edges()[i];
    //  if((e->v0() == v && e->v1() == p0.base_element()) ||
    //     (e->v0() == p0.base_element() && e->v1() == v)) {
    //    f = (e->adjacent_faces()[0] == f) ? e->adjacent_faces()[1] :
    //                                        e->adjacent_faces()[0];
    //    break;
    //  }
    //}
    //
    // while(f != fs[1]) {
    //  if(f == fs[0]) {
    //    Msg::Error("Could not find (%g %g %g) around (%g %g %g) and (%g %g
    //    %g)",
    //               p2.x(), p2.y(), p2.z(), p0.x(), p0.y(), p0.z(), p1.x(),
    //               p1.y(), p1.z());
    //  }
    //
    //  for(int i = 0; i < 3; ++i) {
    //    if(f->adjacent_vertices()[i] == p0.base_element()) {
    //      v = f->adjacent_vertices()[(i + 2) % 3];
    //      break;
    //    }
    //  }
    //  v01 = v02;
    //  geodesic::SurfacePoint sp(v);
    //  v02 = SVector3((p0).xyz(), (sp).xyz());
    //  n = normal(f);
    //  angle += computeAngle(v01, v02, n);
    //  // std::cout << "- current face " << angle << std::endl;
    //
    //  for(int i = 0; i < 3; ++i) {
    //    auto e = f->adjacent_edges()[i];
    //    if((e->v0() == v && e->v1() == p0.base_element()) ||
    //       (e->v0() == p0.base_element() && e->v1() == v)) {
    //      if(e->adjacent_faces().size() != 2)
    //        return -computeIntrinsicAngle(p0, p2, p1);
    //      f = (e->adjacent_faces()[0] == f) ? e->adjacent_faces()[1] :
    //                                          e->adjacent_faces()[0];
    //      break;
    //    }
    //  }
    //}
    //
    // v01 = v02;
    // v02 = SVector3((p0).xyz(), (p2).xyz());
    // n = normal(fs[1]);
    // angle += computeAngle(v01, v02, n);
    //// std::cout << "- last face " << angle << std::endl;
    //// std::cout << angle << std::endl;
    //// if(abs(oangle - angle) > 1e-3) {
    ////   std::cout << angle << " " << oangle << " diff=" << oangle - angle
    ////             << std::endl;
    ////   Msg::Error("Not same angles");
    //// }
    // return angle;
  }

  Msg::Error("Computing intrinsic angle on undifined surface point");
  return 0.;
}

double highOrderPolyMesh::computeIntrinsicAngle(int p0, int p1, int p2)
{
  PathView p01, p20;
  getGeodesicPath(p0, p1, p01);
  getGeodesicPath(p2, p0, p20);
  return computeIntrinsicAngle(p01, p20);
}

double highOrderPolyMesh::computeIntrinsicAngle(PathView &p01, PathView &p20)
{
  return computeIntrinsicAngle(p01[0], p01[1], p20[p20.size() - 2]);
}

double highOrderPolyMesh::computeAngle(SVector3 v01, SVector3 v02, SVector3 n)
{
  double cos = dot(v01, v02);
  SVector3 cp = crossprod(v01, v02);
  double sin = norm(cp);

  double angle = atan2(sin, cos);
  if(dot(cp, n) < -1e-12) angle = 2 * M_PI - angle;
  if(angle < 0) angle += 2 * M_PI;
  return angle;
}

double highOrderPolyMesh::computeAngle(PathView &p01, PathView &p20, SVector3 n)
{
  return computeIntrinsicAngle(p01[0], p01[1], p20[p20.size() - 2]);
}

/*
  p2            p1
   \           /
     \ <---- /
       \   /
         p0
*/
double highOrderPolyMesh::computeAngle(int p0, int p1, int p2, SVector3 n,
                                       int boundary10, int boundary12)
{
  PathView p01, p20;
  getGeodesicPath(p0, p1, p01);
  getGeodesicPath(p2, p0, p20);
  PathView pv01(p01), pv20(p20);
  return computeIntrinsicAngle(pv01, pv20);
}

void highOrderPolyMesh::addVertexOnSurface(PolyMesh::Face *f, int v)
{
  auto it = fvs.find(f);
  if(it != fvs.end())
    it->second.push_back(v);
  else {
    std::vector<int> cut = {v};
    fvs[f] = cut;
  }
}

void highOrderPolyMesh::addVertexOnEdge(PolyMesh::HalfEdge *e, int v)
{
  auto it = evs.find(e);
  if(it != evs.end()) {
    // for(auto w : it->second) {
    //   if(norm(pm->vertices[v]->position - pm->vertices[w]->position) <
    //      1e-14 * e->l()) {
    //     Msg::Error("Vertex already exists in evs (%lf %lf %lf) (%lf %lf
    //     %lf)",
    //                pm->vertices[v]->position.x(),
    //                pm->vertices[v]->position.y(),
    //                pm->vertices[v]->position.z(),
    //                pm->vertices[w]->position.x(),
    //                pm->vertices[w]->position.y(),
    //                pm->vertices[w]->position.z());
    //   }
    // }
    it->second.push_back(v);
  }
  else {
    std::vector<int> cut = {v};
    evs[e] = cut;
  }
}

void highOrderPolyMesh::addPolyMeshVertexTag(PolyMesh::Vertex *v, int tag)
{
  auto it = pvtags.find(v);
  if(it != pvtags.end())
    it->second.push_back(tag);
  else {
    std::vector<int> tmp = {tag};
    pvtags[v] = tmp;
  }
}

void highOrderPolyMesh::addPolyMeshVertexVertexTag(PolyMesh::Vertex *v,
                                                   PolyMesh::Vertex *w, int tag)
{
  // if((v->data == 297 && w->data == 136) || (v->data == 136 && w->data ==
  // 297))
  //   Msg::Error("error");
  auto it = pvvtags.find(v);
  if(it != pvvtags.end())
    it->second.push_back({w, tag});
  else {
    std::vector<std::pair<PolyMesh::Vertex *, int>> tmp = {
      std::make_pair(w, tag)};
    pvvtags[v] = tmp;
  }

  it = pvvtags.find(w);
  if(it != pvvtags.end())
    it->second.push_back({v, tag});
  else {
    std::vector<std::pair<PolyMesh::Vertex *, int>> tmp = {
      std::make_pair(v, tag)};
    pvvtags[w] = tmp;
  }
}

void highOrderPolyMesh::classifyGeodesic(std::pair<int, int> pair,
                                         const PathView &p, int i0, int i1)
{
  if(pair.first >= pair.second)
    Msg::Error("Not ordered pair %d %d", pair.first, pair.second);
  int tag = getTag(pair);
  //    printf("----> classifying a geodesic %d %d %d\n",pair.first,
  //    pair.second, tag);
  // PolyMesh::Vertex *last = pm->vertices[i0];
  size_t last = i0;
  for(size_t i = 1; i < p.size() - 1; i++) {
    geodesic::SurfacePoint _s = p[i];
    if(_s.type() == geodesic::VERTEX) { // saddle vertex
      // no new point needed
      geodesic::Vertex *pv = static_cast<geodesic::Vertex *>(_s.base_element());
      //	printf("point %lu geodesic vertex %d - %g %g
      //%g\n",i,pv->id(),_s.x(),_s.y(),_s.z());
      addPolyMeshVertexTag(pm->vertices[pv->id()], tag);
      addPolyMeshVertexVertexTag(pm->vertices[pv->id()], pm->vertices[last],
                                 tag);
      last = pv->id();
      auto it = _saddle.find(pv->id());
      if(it != _saddle.end()) {
        printf("geodesics %d and %d intersect at saddle point %d (%g %g %g)\n",
               tag, it->second, pv->id(), pv->x(), pv->y(), pv->z());
      }
      _saddle[pv->id()] = tag;
    }
    else if(_s.type() == geodesic::EDGE) { // usual vertex on an edge
      // point will be created later by splitting
      geodesic::Edge *pe = static_cast<geodesic::Edge *>(_s.base_element());
      geodesic::vertex_pointer v0 = pe->v0();
      geodesic::vertex_pointer v1 = pe->v1();
      PolyMesh::HalfEdge *he =
        pm->getEdge(pm->vertices[std::min(v0->id(), v1->id())],
                    pm->vertices[std::max(v0->id(), v1->id())]);
      if(!he)
        he = pm->getEdge(pm->vertices[std::max(v0->id(), v1->id())],
                         pm->vertices[std::min(v0->id(), v1->id())]);
      if(!he) Msg::Error("%s %d -- FAILURE", __FILE__, __LINE__);
      /*	if (pm->vertices.size() == 664 || pm->vertices.size() == 655 ||
        pm->vertices.size() == 644 || pm->vertices.size() == 634){
        geodesic::SurfacePoint _ss = p[0];
        printf("we are on geodesic %d %d and point %lu is on position %lu (%g
        %g %g) vs (%g %g %g) -- %d vs %d size = %lu\n",
            pair.first,pair.second,pm->vertices.size(),i,_s.x(),_s.y(),_s.z(),_ss.x(),_ss.y(),_ss.z(),_s.type(),_ss.type(),p.size());
            }*/
      PolyMesh::Vertex *newv =
        new PolyMesh::Vertex(_s.x(), _s.y(), _s.z(), pm->vertices.size());
      pm->vertices.push_back(newv);
      addVertexOnEdge(he, pm->vertices.size() - 1);
      addPolyMeshVertexTag(newv, tag);
      addPolyMeshVertexVertexTag(newv, pm->vertices[last], tag);
      last = pm->vertices.size() - 1;
    }
    else if(_s.type() ==
            geodesic::FACE) { // point on a face (start of geodesic)
      geodesic::Face *pf = static_cast<geodesic::Face *>(_s.base_element());
      PolyMesh::Vertex *newv =
        new PolyMesh::Vertex(_s.x(), _s.y(), _s.z(), pm->vertices.size());
      //	printf("point %lu geodesic face %d \n",i,pf->id());
      pm->vertices.push_back(newv);
      addVertexOnSurface(pm->faces[pf->id()], pm->vertices.size() - 1);
      addPolyMeshVertexTag(newv, tag);
      addPolyMeshVertexVertexTag(newv, pm->vertices[last], tag);
      last = pm->vertices.size() - 1;
    }
  }
  addPolyMeshVertexVertexTag(pm->vertices[last], pm->vertices[i1], tag);
}

void highOrderPolyMesh::classifyGeodesicVertices(
  std::vector<PolyMesh::Vertex *> &pointVertices)
{
  pointVertices.clear();
  for(size_t i = 0; i < pointsPool.size(); ++i) {
    if(pointsPool.type(i) != PointType::Vertex) continue;
    geodesic::SurfacePoint _s = pointsPool[i];
    //      printf("end point %lu geodesic vertex - %g %g %g - type
    //      %d\n",i,_s.x(),_s.y(),_s.z(),_s.type());
    if(_s.type() == geodesic::VERTEX) { // saddle vertex
      geodesic::Vertex *pv = static_cast<geodesic::Vertex *>(_s.base_element());
      sp2pv[i] = pv->id();
      // std::cout << i << " vertex " << pv->id() << std::endl;
      // pointVertices[i] = pm->vertices[pv->id()];
      pointVertices.push_back(pm->vertices[pv->id()]);
      // pm->vertices[pv->id()]->data = pv->id();
    }
    else if(_s.type() == geodesic::FACE) {
      geodesic::Face *pf = static_cast<geodesic::Face *>(_s.base_element());
      PolyMesh::Vertex *newv =
        new PolyMesh::Vertex(_s.x(), _s.y(), _s.z(), pm->vertices.size());
      pm->vertices.push_back(newv);
      addVertexOnSurface(pm->faces[pf->id()], pm->vertices.size() - 1);
      sp2pv[i] = pm->vertices.size() - 1;
      // std::cout << i << " face " << pm->vertices.size() - 1 << std::endl;
      // pointVertices[i] = newv;
      pointVertices.push_back(newv);
    }
    else if(_s.type() == geodesic::EDGE) {
      geodesic::Edge *pe = static_cast<geodesic::Edge *>(_s.base_element());
      geodesic::vertex_pointer v0 = pe->v0();
      geodesic::vertex_pointer v1 = pe->v1();
      PolyMesh::HalfEdge *he =
        pm->getEdge(pm->vertices[std::min(v0->id(), v1->id())],
                    pm->vertices[std::max(v0->id(), v1->id())]);
      if(!he)
        he = pm->getEdge(pm->vertices[std::max(v0->id(), v1->id())],
                         pm->vertices[std::min(v0->id(), v1->id())]);
      if(!he) Msg::Error("%s %d -- FAILURE", __FILE__, __LINE__);
      // if(pm->vertices.size() == 664 || pm->vertices.size() == 655 ||
      //    pm->vertices.size() == 644 || pm->vertices.size() == 634) {
      //   printf("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAA  argh : %lu --- %g %g %g --> "
      //          "%g %g %g\n",
      //          i, he->v->position.x(), he->v->position.y(),
      //          he->v->position.z(), he->next->v->position.x(),
      //          he->next->v->position.y(), he->next->v->position.z());
      // }
      PolyMesh::Vertex *newv =
        new PolyMesh::Vertex(_s.x(), _s.y(), _s.z(), pm->vertices.size());
      pm->vertices.push_back(newv);
      addVertexOnEdge(he, pm->vertices.size() - 1);
      sp2pv[i] = pm->vertices.size() - 1;
      // std::cout << i << " edge " << pm->vertices.size() - 1 << std::endl;
      // pointVertices[i] = newv;
      pointVertices.push_back(newv);
    }
  }

  for(size_t i = 0; i < ipm->faces.size(); ++i) {
    auto he = ipm->faces[i]->he;
    int is[3] = {he->v->data, he->next->v->data, he->next->next->v->data};
    PolyMesh::Vertex *vs[3];
    auto it = sp2pv.find(is[0]);
    if(it == sp2pv.end()) Msg::Error("point not found");
    vs[0] = pm->vertices[it->second];
    it = sp2pv.find(is[1]);
    if(it == sp2pv.end()) Msg::Error("point not found");
    vs[1] = pm->vertices[it->second];
    it = sp2pv.find(is[2]);
    if(it == sp2pv.end()) Msg::Error("point not found");
    vs[2] = pm->vertices[it->second];
    for(int j = 0; j < 3; ++j) {
      // auto i0 = triangles[3 * i + j];
      // auto i1 = triangles[3 * i + (j + 1) % 3];
      // auto i0 = he->v->data;
      // auto i1 = he->next->v->data;
      int tag = getTag({is[j], is[(j + 1) % 3]});
      addPolyMeshVertexTag(vs[j], tag);
      addPolyMeshVertexTag(vs[(j + 1) % 3], tag);
      he = he->next;
    }
  }

  std::set<std::pair<int, int>> done;
  for(size_t i = 0; i < ipm->faces.size(); ++i) {
    auto he = ipm->faces[i]->he;
    for(int j = 0; j < 3; ++j) {
      he = he->next;
      int i0 = he->v->data;
      int i1 = he->next->v->data;
      // std::cout << i0 << " to " << i1 << std::endl;
      auto it = sp2pv.find(i0);
      if(it == sp2pv.end()) Msg::Error("point not found");
      PolyMesh::Vertex *v0 = pm->vertices[it->second];
      it = sp2pv.find(i1);
      if(it == sp2pv.end()) Msg::Error("point not found");
      PolyMesh::Vertex *v1 = pm->vertices[it->second];
      std::pair<int, int> e = {i0, i1};
      if(e.first > e.second) {
        std::swap(e.first, e.second);
        std::swap(v0, v1);
      }
      if(done.find(e) != done.end()) continue;
      PathView path;
      getGeodesicPath(e.first, e.second, path);
      classifyGeodesic(e, path, sp2pv[e.first], sp2pv[e.second]);
      done.insert(e);
    }
  }
}

// public
void highOrderPolyMesh::printGeodesics(const char *fn)
{
  FILE *f = fopen(fn, "w");
  fprintf(f, "View \"\"{\n");
  for(size_t i = 0; i < pointsPool.size(); i += 1) {
    int tag = (pointsPool.type(i) == PointType::Vertex) ? 1000 : 2000;
    fprintf(f, "SP(%g,%g,%g){%d};\n", pointsPool[i].x(), pointsPool[i].y(),
            pointsPool[i].z(), tag);
  }
  for(size_t i = 0; i < ipm->faces.size(); ++i) {
    auto he = ipm->faces[i]->he;
    for(int j = 0; j < 3; ++j) {
      he = he->next;
      int i0 = he->v->data;
      int i1 = he->next->v->data;
      PathView path;
      getGeodesicPath(i0, i1, path);
      fprintf(f, "SP(%g,%g,%g){%d};\n", path.front().x(), path.front().y(),
              path.front().z(), i0);
      fprintf(f, "SP(%g,%g,%g){%d};\n", path.back().x(), path.back().y(),
              path.back().z(), i1);
      for(size_t k = 1; k < path.size(); ++k) {
        fprintf(f, "SL(%g,%g,%g,%g,%g,%g){%ld,%ld};\n", path[k - 1].x(),
                path[k - 1].y(), path[k - 1].z(), path[k].x(), path[k].y(),
                path[k].z(), i, i);
      }
    }
  }
  fprintf(f, "};\n");
  fclose(f);
}

void highOrderPolyMesh::enforceBoundary()
{
  for(size_t i = 0; i < ipm->faces.size(); ++i) {
    auto he = ipm->faces[i]->he;
    for(int j = 0; j < 3; ++j) {
      auto i0 = he->v->data;
      auto i1 = he->next->v->data;
      std::pair<int, int> edge = {std::min(i0, i1), std::max(i0, i1)};
      if(edges[edge].size() != 1) continue;

      PathView path;
      getBoundaryPath(i0, i1, path);
    }
  }
}

// CONSTRUCTORS
highOrderPolyMesh::highOrderPolyMesh(PolyMesh *polyMesh,
                                     std::vector<size_t> &tris)
  : maxTag(1)
{
  pm = polyMesh;
  ipm = new PolyMesh(*pm);

  polyMeshToGeodesicMesh(pm, geoMesh, f2n);
  algorithms = std::vector<geodesic::GeodesicAlgorithmExact>(
    getNumThreads(), geodesic::GeodesicAlgorithmExact(&geoMesh));

  auto vertices = pm->vertices;
  std::map<int, int> v2n;
  for(auto i : tris) {
    auto v = vertices[i];
    if(!v2n.count(i)) {
      geodesic::SurfacePoint gv =
        geodesic::SurfacePoint(&geoMesh.vertices()[v->data]);
      v2n[i] = pointsPool.size();
      pointsPool.push_back(gv);
    }
  }
  for(size_t i = 0; i < tris.size() / 3; ++i) {
    PolyMesh::Vertex *vs[3];
    for(int j = 0; j < 3; ++j) vs[j] = vertices[tris[3 * i + j]];
    for(size_t i = 0; i < 3; i++) {
      int i0 = v2n[vs[i]->data];
      int i1 = v2n[vs[(i + 1) % 3]->data];
      if(i0 < 0 || i1 < 0) Msg::Error("The problem is here");
      std::pair<int, int> p =
        std::make_pair(std::min(i0, i1), std::max(i0, i1));
      auto it = edges.find(p);
      if(it == edges.end()) {
        std::vector<size_t> tmp = {triangles.size() / 3};
        edges[p] = tmp;
      }
      else
        it->second.push_back(triangles.size() / 3);
    }
    triangles.push_back(v2n[vs[0]->data]);
    triangles.push_back(v2n[vs[1]->data]);
    triangles.push_back(v2n[vs[2]->data]);
  }
}

highOrderPolyMesh::highOrderPolyMesh(PolyMesh *polyMesh) : maxTag(1)
{
  pm = polyMesh;
  polyMeshToGeodesicMesh(pm, geoMesh, f2n);
  algorithms = std::vector<geodesic::GeodesicAlgorithmExact>(
    getNumThreads(), geodesic::GeodesicAlgorithmExact(&geoMesh));
}

// END CONSTRUCTORS

static int getNumThreads()
{
  int nthreads = CTX::instance()->numThreads;
  if(CTX::instance()->mesh.maxNumThreads3D > 0)
    nthreads = CTX::instance()->mesh.maxNumThreads3D;
  if(!nthreads) nthreads = Msg::GetMaxThreads();
  return nthreads;
}

void highOrderPolyMesh::setGeodesic(std::pair<int, int> edge,
                                    std::vector<geodesic::SurfacePoint> &path)
{
  if(path.size() < 2)
    Msg::Error("Unable to set geodesic path (size == %d)", path.size());
  if(path.front().x() != pointsPool[edge.first].x() ||
     path.front().y() != pointsPool[edge.first].y() ||
     path.front().z() != pointsPool[edge.first].z())
    Msg::Error("Error: geodesic path does not start at the right point");
  if(path.back().x() != pointsPool[edge.second].x() ||
     path.back().y() != pointsPool[edge.second].y() ||
     path.back().z() != pointsPool[edge.second].z())
    Msg::Error("Error: geodesic path does not end at the right point");

  auto it = geodesics.find(edge);
  if(it != geodesics.end())
    it->second = path;
  else
    geodesics[edge] = path;
  if(vertexGeodesics.size() != pointsPool.size())
    vertexGeodesics.resize(pointsPool.size(),
                           std::vector<std::pair<int, int>>(0));
  auto &vec0 = vertexGeodesics[edge.first];
  if(std::find(vec0.begin(), vec0.end(), edge) == vec0.end())
    vec0.push_back(edge);
  auto &vec1 = vertexGeodesics[edge.second];
  if(std::find(vec1.begin(), vec1.end(), edge) == vec1.end())
    vec1.push_back(edge);
}

void highOrderPolyMesh::createGeodesics(
  geodesic::SurfacePoint &pt_start,
  std::vector<geodesic::SurfacePoint> &pts_end,
  std::vector<std::vector<geodesic::SurfacePoint>> &paths)
{
  if(pts_end.size() == 0) return;

  std::vector<geodesic::SurfacePoint> pts_start = {pt_start};
#if ASTAR
  algorithms[Msg::GetThreadNum()].propagateAStar(pts_start, 0, &pts_end);
#else
  algorithms[Msg::GetThreadNum()].propagate(pts_start, 0, &pts_end);
#endif

  paths.clear();
  paths.resize(pts_end.size());
  for(size_t j = 0; j < pts_end.size(); j++) {
    std::vector<geodesic::SurfacePoint> path;
    algorithms[Msg::GetThreadNum()].trace_back(pts_end[j], path);
    if(path.empty()) {
      Msg::Info("propagation did not go far enough, widening the search");
#if ASTAR
      algorithms[Msg::GetThreadNum()].propagateAStar(pts_start, 1.e22,
                                                     &pts_end);
#else
      algorithms[Msg::GetThreadNum()].propagate(pts_start, 1.e22, &pts_end);
#endif
      algorithms[Msg::GetThreadNum()].trace_back(pts_end[j], path);
      std::reverse(path.begin(), path.end());
    }
    if(path.empty()) Msg::Error("Error: geodesic path is empty");
    filterPath(path, 1.e-8);
    paths[j] = path;
  }
}

void highOrderPolyMesh::createGeodesics(
  std::vector<geodesic::SurfacePoint> &pts_start,
  std::vector<std::vector<geodesic::SurfacePoint>> &vector_pts_end,
  std::vector<std::vector<geodesic::SurfacePoint>> &paths)
{
  if(pts_start.size() != vector_pts_end.size()) Msg::Error("Wring vector size");
  int nthreads = getNumThreads();

  std::map<std::pair<size_t, size_t>, size_t> index;
  size_t count = 0;
  for(size_t i = 0; i < pts_start.size(); ++i) {
    for(size_t j = 0; j < vector_pts_end[i].size(); ++j) {
      index[{i, j}] = count++;
    }
  }
  paths.resize(count);

  std::vector<std::vector<std::vector<geodesic::SurfacePoint>>> pths(nthreads);

#if defined(_OPENMP)
#pragma omp parallel for num_threads(nthreads) schedule(dynamic)
#endif
  for(size_t i = 0; i < pts_start.size(); i++) {
    geodesic::SurfacePoint &pt_start = pts_start[i];
    std::vector<geodesic::SurfacePoint> &pts_end = vector_pts_end[i];
    std::vector<std::vector<geodesic::SurfacePoint>> &ps =
      pths[Msg::GetThreadNum()];

    Msg::Debug("Computing geodesics for vertex %d on thread %d ",
               pts_start[i].base_element()->id(), Msg::GetThreadNum());

    createGeodesics(pt_start, pts_end, ps);
    for(int j = 0; j < ps.size(); ++j) paths[index[{i, j}]] = ps[j];
  }
}

void highOrderPolyMesh::createGeodesicsInParallel(
  std::vector<std::pair<int, int>> edges, bool reorder)
{
  int nthreads = getNumThreads();
  // Msg::Info("Computing geodesics using %d threads", nthreads);

  std::vector<std::pair<int, int>> eds;
  if(reorder) {
    for(auto it = edges.begin(); it != edges.end(); ++it) {
      std::pair<int, int> e = *it;
      if(e.first > e.second) std::swap(e.first, e.second);
      eds.push_back(e);
    }
  }
  else
    eds = edges;

  std::vector<int> __rows, __columns, __starts;
  for(auto it = eds.begin(); it != eds.end(); ++it) {
    // std::pair<int, int> e = *it;
    // if(e.first > e.second) std::swap(e.first, e.second);
    if(geodesics.find(*it) != geodesics.end()) continue;
    if(geodesics.find({it->second, it->first}) != geodesics.end()) continue;
    int row = it->first;
    int column = it->second;
    if(row < 0 || column < 0) Msg::Error("negative index");
    if(__rows.empty() || __rows[__rows.size() - 1] != row) {
      __starts.push_back(__columns.size());
      __rows.push_back(row);
    }
    __columns.push_back(column);
  }
  __starts.push_back(__columns.size());

  std::vector<std::unordered_map<
    std::pair<int, int>, std::vector<geodesic::SurfacePoint>, pair_hash>>
    __geodesics(nthreads);
  std::vector<std::unordered_map<std::pair<int, int>, double, pair_hash>>
    __lengths(nthreads);

#if defined(_OPENMP)
#pragma omp parallel for num_threads(nthreads) schedule(dynamic)
#endif

  for(size_t i = 0; i < __rows.size(); i++) {
    int start = __starts[i];
    int end = __starts[i + 1];

    Msg::Debug("Computing geodesics for vertex %d on thread %d ", __rows[i],
               Msg::GetThreadNum());

    geodesic::SurfacePoint &pt_start = pointsPool[__rows[i]];
    std::vector<geodesic::SurfacePoint> pts_end;
    std::vector<std::pair<int, int>> pairs;
    for(int j = start; j < end; j++) {
      pts_end.push_back(pointsPool[__columns[j]]);
      pairs.push_back(std::make_pair(__rows[i], __columns[j]));
    }
    std::vector<std::vector<geodesic::SurfacePoint>> paths;
    createGeodesics(pt_start, pts_end, paths);
    for(int j = 0; j < pts_end.size(); j++) {
      auto path = paths[j];
      std::pair<int, int> inv = pairs[j];
      __geodesics[Msg::GetThreadNum()][std::make_pair(inv.second, inv.first)] =
        path;
      std::reverse(path.begin(), path.end());
      __geodesics[Msg::GetThreadNum()][pairs[j]] = path;
      __lengths[Msg::GetThreadNum()][pairs[j]] = adimLength(path);
    }
  }

  for(auto g : __geodesics) {
    for(auto it = g.begin(); it != g.end(); ++it) {
      setGeodesic(it->first, it->second);
    }
  }
  for(auto l : __lengths) adimLengths.insert(l.begin(), l.end());
}

void highOrderPolyMesh::createInitialGeodesics()
{
  std::vector<geodesic::SurfacePoint> path;
  for(auto kv : edges) {
    if(kv.second.size() == 0)
      throw std::runtime_error("Should not be in edges");
    path = {pointsPool[kv.first.first], pointsPool[kv.first.second]};
    setGeodesic(kv.first, path);
  }
}

void highOrderPolyMesh::createGeodesics()
{
  std::vector<std::pair<int, int>> eds;
  for(auto kv : edges) {
    if(kv.second.size() == 0)
      throw std::runtime_error("Should not be in edges");
    eds.push_back(kv.first);
  }
  createGeodesicsInParallel(eds);
}

// CREATE GEODESIC PATH
void highOrderPolyMesh::getGeodesicPath(int p0, int p1, PathView &path)
{
  auto it = geodesics.find({p0, p1});
  if(it != geodesics.end()) {
    path = PathView(it->second);
    return;
  }

  auto itinv = geodesics.find({p1, p0});
  if(itinv != geodesics.end()) {
    path = PathView(itinv->second, true);
    return;
  }

  geodesic::SurfacePoint &start_pt = pointsPool[p1];
  std::vector<geodesic::SurfacePoint> stop_pts = {pointsPool[p0]};
  std::vector<std::vector<geodesic::SurfacePoint>> ps;
  createGeodesics(start_pt, stop_pts, ps);
  setGeodesic({p0, p1}, ps[0]);
  getGeodesicPath(p0, p1, path);
}
// END CREATE GEODESIC PATH

// GET BOUNDARY PATH
void highOrderPolyMesh::getBoundaryPath(int p0, int p1, PathView &path)
{
  std::vector<geodesic::SurfacePoint> p;
  geodesic::SurfacePoint sp[2] = {pointsPool[p0], pointsPool[p1]};
  PolyMesh::HalfEdge *he[2];
  for(int i = 0; i < 2; ++i) {
    if(sp[i].base_element()->type() == geodesic::VERTEX) {
      he[i] = pm->vertices[sp[i].base_element()->id()]->he;
      while(he[i]->opposite != nullptr) he[i] = he[i]->opposite->next;
    }
    else if(sp[i].base_element()->type() == geodesic::EDGE) {
      PolyMesh::Vertex *v0 =
        pm->vertices[sp[i].base_element()->adjacent_vertices()[0]->id()];
      PolyMesh::Vertex *v1 =
        pm->vertices[sp[i].base_element()->adjacent_vertices()[1]->id()];
      he[i] = pm->getEdge(v0, v1);
      if(he[i] == nullptr) he[i] = pm->getEdge(v1, v0);
    }
    else
      Msg::Error("Error in getBoundaryPath: sp is not a vertex or an edge");
    if(he[i] == nullptr) Msg::Error("Error in getBoundaryPath: he is nullptr");
  }

  p.push_back(sp[0]);
  while(he[0] != he[1]) {
    he[0] = he[0]->next;
    while(he[0]->opposite != nullptr) he[0] = he[0]->opposite->next;
    auto sp = geodesic::SurfacePoint(&geoMesh.vertices()[he[0]->v->data]);
    p.push_back(sp);
  }
  if(sp[1].base_element()->type() == geodesic::EDGE)
    p.push_back(pointsPool[p1]);

  setGeodesic({p0, p1}, p);
  getGeodesicPath(p0, p1, path);
}
// END GET BOUNDARY PATH

// GET PATH
void highOrderPolyMesh::getPath(std::pair<int, int> edge,
                                int boundaryOrientation, PathView &path)
{
  if(boundaryOrientation == 0) {
    getGeodesicPath(edge.first, edge.second, path);
    return;
  }
  if(boundaryOrientation == 1) {
    getBoundaryPath(edge.first, edge.second, path);
    return;
  }
  if(boundaryOrientation == -1) {
    getBoundaryPath(edge.second, edge.first, path);
    path = PathView(path, true);
    return;
  }
  Msg::Error("Error: boundaryOrientation = %d", boundaryOrientation);
}

int highOrderPolyMesh::getBoundaryOrientation(std::pair<int, int> edge)
{
  int i0 = edge.first, i1 = edge.second;
  std::pair<int, int> e = {i0, i1};
  if(e.first > e.second) std::swap(e.first, e.second);

  auto it = edges.find(e);
  if(it == edges.end()) { return 0; }

  if(it->second.size() == 2 || it->second.size() == 0) return 0;

  if(it->second.size() == 1) {
    for(int j = 0; j < 3; ++j) {
      if(triangles[3 * edges[e][0] + j] == i0 &&
         triangles[3 * edges[e][0] + (j + 1) % 3] == i1)
        return 1;
      if(triangles[3 * edges[e][0] + j] == i1 &&
         triangles[3 * edges[e][0] + (j + 1) % 3] == i0)
        return -1;
    }
    Msg::Error("Error: edge not found in triangle");
  }

  Msg::Error("Error: edge %d %d has %d triangles", it->first.first,
             it->first.second, it->second.size());
  return -2;
}

void highOrderPolyMesh::getPath(PolyMesh::HalfEdge *he, PathView &path)
{
  if(he->opposite)
    getGeodesicPath(he->v->data, he->next->v->data, path);
  else
    getBoundaryPath(he->v->data, he->next->v->data, path);
}
void highOrderPolyMesh::getPath(std::pair<int, int> edge, PathView &path)
{
  int boundaryOrientation = getBoundaryOrientation(edge);
  getPath(edge, boundaryOrientation, path);
}
// END GET GEODESIC PATH

// CREATE CIRCUMCENTER
void highOrderPolyMesh::createCircumcenter(
  std::vector<geodesic::SurfacePoint> &pts,
  geodesic::SurfacePoint &circumcenter, double &circumradius)
{
  algorithms[Msg::GetThreadNum()].propagateToCircumcenter(
    pts, 0.0, circumcenter, circumradius);
  if(circumcenter.type() == geodesic::UNDEFINED_POINT) {
    if(WARNING) Msg::Warning(("Could not find circumcenter"));
    circumradius = geodesic::GEODESIC_INF;
  }
  if(isnan(circumradius)) throw std::runtime_error("error circumradius is nan");
}

void highOrderPolyMesh::createCircumcenters(
  std::vector<std::vector<geodesic::SurfacePoint>> &pts,
  std::vector<geodesic::SurfacePoint> &circumcenters,
  std::vector<double> &circumradii)
{
  int nthreads = getNumThreads();
  std::vector<std::vector<geodesic::SurfacePoint>> ___circumcenters(nthreads);
  std::vector<std::vector<double>> ___circumradii(nthreads);
  std::vector<std::vector<int>> ___index(nthreads);

  circumradii.resize(pts.size(), geodesic::GEODESIC_INF);

#if defined(_OPENMP)
#pragma omp parallel for num_threads(nthreads) schedule(dynamic)
#endif
  for(size_t i = 0; i < pts.size(); ++i) {
    geodesic::SurfacePoint circumcenter;
    double circumradius = circumradii[i];
    createCircumcenter(pts[i], circumcenter, circumradius);
    ___circumcenters[Msg::GetThreadNum()].push_back(circumcenter);
    ___circumradii[Msg::GetThreadNum()].push_back(circumradius);
    ___index[Msg::GetThreadNum()].push_back(i);
  }

  circumcenters.resize(pts.size());
  for(int i = 0; i < nthreads; ++i) {
    for(size_t j = 0; j < ___index[i].size(); ++j) {
      circumcenters[___index[i][j]] = ___circumcenters[i][j];
      circumradii[___index[i][j]] = ___circumradii[i][j];
    }
  }
}

void highOrderPolyMesh::getCircumcenter(int t, size_t &circumindex,
                                        double &circumradius)
{
  auto he = ipm->faces[t]->he;
  std::array<int, 3> tri = {he->v->data, he->next->v->data,
                            he->next->next->v->data};
  getCircumcenter(tri, circumindex, circumradius);
}

void highOrderPolyMesh::getCircumcenter(std::array<int, 3> &tri,
                                        size_t &circumindex,
                                        double &circumradius)
{
  auto sorted = tri;
  std::sort(sorted.begin(), sorted.end());
  auto it = circumIndexRadius.find(sorted);
  if(it != circumIndexRadius.end()) {
    circumindex = it->second.first;
    circumradius = it->second.second;
    if(circumindex >= pointsPool.size())
      throw std::runtime_error("not existing center");
    return;
  }
  std::vector<geodesic::SurfacePoint> pts = {
    pointsPool[tri[0]], pointsPool[tri[1]], pointsPool[tri[2]]};
  double d = 0.;
  for(int i = 0; i < 3; ++i) {
    std::pair<int, int> e = {tri[i], tri[(i + 1) % 3]};
    double l = length(e);
    if(l > d) d = l;
  }
  d *= CIRCUMMULT;
  circumradius = d;
  geodesic::SurfacePoint circumcenter;
  createCircumcenter(pts, circumcenter, circumradius);
  circumindex = setCircumcenter(sorted, circumcenter, circumradius);
}

size_t highOrderPolyMesh::setCircumcenter(std::array<int, 3> &tri,
                                          geodesic::SurfacePoint &circumcenter,
                                          double circumradius)
{
  size_t index = pointsPool.size();
  pointsPool.insertCircumcenter(circumcenter);
  circumIndexRadius[tri] = {index, circumradius};
  vertexTriangles[tri[0]].push_back(tri);
  vertexTriangles[tri[1]].push_back(tri);
  vertexTriangles[tri[2]].push_back(tri);
  return index;
}

// INTERSECT GEODESIC PATH
static void getFacesForSegment(geodesic::SurfacePoint &sp0,
                               geodesic::SurfacePoint &sp1,
                               std::array<geodesic::Face *, 2> &faces)
{
  faces = {nullptr, nullptr};
  if(sp0.type() == geodesic::FACE) {
    faces[0] = static_cast<geodesic::Face *>(sp0.base_element());
    return;
  }
  if(sp1.type() == geodesic::FACE) {
    faces[0] = static_cast<geodesic::Face *>(sp1.base_element());
    return;
  }
  for(auto f : sp0.base_element()->adjacent_faces()) {
    auto &sp1Faces = sp1.base_element()->adjacent_faces();
    auto it = std::find(sp1Faces.begin(), sp1Faces.end(), f);
    if(it != sp1Faces.end()) {
      if(faces[0] == nullptr)
        faces[0] = f;
      else
        faces[1] = f;
    }
  }
}

bool highOrderPolyMesh::intersectGeodesicPath(
  PathView &p0, PathView &p1, SVector3 &intersection,
  std::unordered_map<geodesic::Face *, size_t> *faceSegmentsPtr,
  std::unordered_map<geodesic::Vertex *, std::array<size_t, 2>>
    *vertexSegmentsPtr)
{
  double eps = 1e-12;
  double epsBis = 1e-12;
  std::unordered_map<geodesic::Face *, size_t> faceSegments;
  std::unordered_map<geodesic::Vertex *, std::array<size_t, 2>> vertexSegments;
  std::unordered_map<geodesic::Face *, size_t> *_faceSegmentsPtr =
    &faceSegments;
  std::unordered_map<geodesic::Vertex *, std::array<size_t, 2>>
    *_vertexSegmentsPtr = &vertexSegments;

  if(faceSegmentsPtr != nullptr && vertexSegmentsPtr != nullptr) {
    _faceSegmentsPtr = faceSegmentsPtr;
    _vertexSegmentsPtr = vertexSegmentsPtr;
  }

  if(_faceSegmentsPtr->size() == 0) {
    std::array<geodesic::Face *, 2> faces;
    for(size_t i = 1; i < p0.size(); i++) {
      getFacesForSegment(p0[i - 1], p0[i], faces);
      (*_faceSegmentsPtr)[faces[0]] = i;
      if(faces[1] != nullptr) (*_faceSegmentsPtr)[faces[1]] = i;

      if(p0[i - 1].type() == geodesic::VERTEX) {
        (*_vertexSegmentsPtr)[static_cast<geodesic::Vertex *>(
          p0[i - 1].base_element())][0] = i + 1;
      }
      if(p0[i].type() == geodesic::VERTEX)
        (*_vertexSegmentsPtr)[static_cast<geodesic::Vertex *>(
          p0[i].base_element())][1] = i + 1;
    }
  }

  std::array<size_t, 6> segments;
  unsigned segCount;
  for(size_t j = 1; j < p1.size(); j++) {
    segCount = 0;
    std::array<geodesic::Face *, 2> faces;
    getFacesForSegment(p1[j - 1], p1[j], faces);
    auto it = _faceSegmentsPtr->find(faces[0]);
    if(it != _faceSegmentsPtr->end()) segments[segCount++] = it->second;
    if(faces[1] != nullptr) {
      it = _faceSegmentsPtr->find(faces[1]);
      if(it != _faceSegmentsPtr->end()) segments[segCount++] = it->second;
    }

    if(p1[j - 1].type() == geodesic::VERTEX) {
      auto it = _vertexSegmentsPtr->find(
        static_cast<geodesic::Vertex *>(p1[j - 1].base_element()));
      if(it != _vertexSegmentsPtr->end()) {
        if(it->second[0] != 0) segments[segCount++] = it->second[0] - 1;
        if(it->second[1] != 0) segments[segCount++] = it->second[1] - 1;
      }
    }
    if(p1[j].type() == geodesic::VERTEX) {
      auto it = _vertexSegmentsPtr->find(
        static_cast<geodesic::Vertex *>(p1[j].base_element()));
      if(it != _vertexSegmentsPtr->end()) {
        if(it->second[0] != 0) segments[segCount++] = it->second[0] - 1;
        if(it->second[1] != 0) segments[segCount++] = it->second[1] - 1;
      }
    }

    if(segCount == 0) continue;

    SVector3 w0(p1[j - 1].x(), p1[j - 1].y(), p1[j - 1].z());
    SVector3 w1(p1[j].x(), p1[j].y(), p1[j].z());
    double local_scale = norm(w1 - w0);
    double inv_local_scale = 1. / local_scale;
    w0 *= inv_local_scale;
    w1 *= inv_local_scale;

    for(unsigned ii = 0; ii < segCount; ++ii) {
      size_t i = segments[ii];
      SVector3 v0(p0[i - 1].x(), p0[i - 1].y(), p0[i - 1].z());
      SVector3 v1(p0[i].x(), p0[i].y(), p0[i].z());
      v0 *= inv_local_scale;
      v1 *= inv_local_scale;
      SVector3 d1 = v1 - v0;
      SVector3 d2 = w1 - w0;
      double l1 = d1.norm(), l2 = d2.norm();
      d1 *= 1. / l1;
      d2 *= 1. / l2;
      SVector3 A = w0 - v0;
      double lA = A.norm();
      if(lA > eps) A *= 1. / lA;
      SVector3 n = crossprod(d1, d2);

      if(n.norm() < eps) { // parallel lines
        if(norm(crossprod(A, d2)) > eps) continue; // not coincident lines
        double pv0 = 0;
        double pv1 = l1;
        double pw0 = dot(A, d1) * lA;
        double pw1 = dot(w1 - v0, d1);
        SVector3 s0 = v0, s1 = v1, s2 = w0, s3 = w1;
        if(pw0 > pw1) {
          std::swap(pw0, pw1);
          std::swap(s2, s3);
        }
        if(pv0 > pw0) {
          std::swap(pv0, pw0);
          std::swap(pv1, pw1);
          std::swap(s0, s2);
          std::swap(s1, s3);
        }
        if(pv1 - pw0 < -eps) continue;
        intersection = .5 * (s1 + s2);

        if(((norm(intersection - inv_local_scale * SVector3(p0[0].xyz())) <
             epsBis) != (norm(intersection -
                              inv_local_scale *
                                SVector3(p0[p0.size() - 1].xyz())) < epsBis)) ||
           ((norm(intersection - inv_local_scale * SVector3(p1[0].xyz())) <
             epsBis) != (norm(intersection -
                              inv_local_scale *
                                SVector3(p1[p1.size() - 1].xyz())) < epsBis)))
          continue;

        intersection *= local_scale;
        return true;
      }

      n.normalize();
      SVector3 n1 = crossprod(n, d2);
      if(abs(dot(d1, n1)) < eps) continue;
      double lambda = dot(A, n1) * lA / (dot(d1, n1) * l1);
      if(lambda < -eps || 1 + eps < lambda) continue;
      intersection = v0 + lambda * d1 * l1;
      double mu = dot(intersection - w0, d2) / l2;
      if(mu < -eps || 1 + eps < mu) continue;

      // // Closed loops
      // if((norm(intersection - inv_local_scale * SVector3(p0[0].xyz())) <
      //     epsBis) &&
      //    (norm(intersection -
      //          inv_local_scale * SVector3(p0[p0.size() - 1].xyz())) <
      //          epsBis))
      //   continue;
      // if((norm(intersection - inv_local_scale * SVector3(p1[0].xyz())) <
      //     epsBis) &&
      //    (norm(intersection -
      //          inv_local_scale * SVector3(p1[p1.size() - 1].xyz())) <
      //          epsBis))
      //   continue;

      // Closed to start points
      if(((norm(intersection - inv_local_scale * SVector3(p0[0].xyz())) <
           epsBis) ||
          (norm(intersection -
                inv_local_scale * SVector3(p0[p0.size() - 1].xyz())) <
           epsBis)) &&
         ((norm(intersection - inv_local_scale * SVector3(p1[0].xyz())) <
           epsBis) ||
          (norm(intersection -
                inv_local_scale * SVector3(p1[p1.size() - 1].xyz())) < epsBis)))
        continue;

      intersection *= local_scale;
      return true;
    }
  }

  return false;
}

// END INTERSECT GEODESIC PATH

void highOrderPolyMesh::removePoint(size_t i)
{
  for(auto e : vertexGeodesics[i]) {
    auto it = geodesics.find(e);
    if(it != geodesics.end()) geodesics.erase(e);
    auto itt = adimLengths.find(e);
    if(itt != adimLengths.end()) adimLengths.erase(e);
    std::swap(e.first, e.second);
    it = geodesics.find(e);
    if(it != geodesics.end()) geodesics.erase(e);
    itt = adimLengths.find(e);
    if(itt != adimLengths.end()) adimLengths.erase(e);
  }
  vertexGeodesics[i].clear();

  for(auto tri : vertexTriangles[i]) {
    auto it = circumIndexRadius.find(tri);
    if(it == circumIndexRadius.end()) continue;
    int idx = it->second.first;
    if(pointsPool.type(idx) == PointType::Circumcenter) removePoint(idx);
    circumIndexRadius.erase(it);
  }

  pointsPool.remove(i);
}

double highOrderPolyMesh::adimLength(std::vector<geodesic::SurfacePoint> &path)
{
  PathView pv(path);
  return adimLength(pv);
}
double highOrderPolyMesh::adimLength(PathView &path)
{
  if(path.size() < 2) Msg::Error("Path smaller than 2 (size=%d)", path.size());
  double adimentionalLength = 0;
  double cl0, cl1 = cl(path[0]);
  for(size_t i = 0; i < path.size() - 1; ++i) {
    SVector3 dl((path[i]).xyz(), (path[i + 1]).xyz());
    cl0 = cl1;
    cl1 = cl(path[i + 1]);
    adimentionalLength += dl.norm() * 2 / (cl0 + cl1);
  }
  if(adimentionalLength < 0)
    Msg::Error("Negative adimentional length in computation: %g",
               adimentionalLength);
  return adimentionalLength;
}

double highOrderPolyMesh::adimLengthMin(PathView &path)
{
  if(path.size() < 2) Msg::Error("Path smaller than 2 (size=%d)", path.size());
  double adimentionalLength = 0;
  double cl0, cl1 = clMin(path[0]);
  for(size_t i = 0; i < path.size() - 1; ++i) {
    SVector3 dl((path[i]).xyz(), (path[i + 1]).xyz());
    cl0 = cl1;
    cl1 = clMin(path[i + 1]);
    adimentionalLength += dl.norm() * 2 / (cl0 + cl1);
  }
  if(adimentionalLength < 0)
    Msg::Error("Negative adimentional length in computation: %g",
               adimentionalLength);
  return adimentionalLength;
}

double highOrderPolyMesh::adimLengthMax(PathView &path)
{
  if(path.size() < 2) Msg::Error("Path smaller than 2 (size=%d)", path.size());
  double adimentionalLength = 0;
  double cl0, cl1 = clMax(path[0]);
  for(size_t i = 0; i < path.size() - 1; ++i) {
    SVector3 dl((path[i]).xyz(), (path[i + 1]).xyz());
    cl0 = cl1;
    cl1 = clMax(path[i + 1]);
    adimentionalLength += dl.norm() * 2 / (cl0 + cl1);
  }
  if(adimentionalLength < 0)
    Msg::Error("Negative adimentional length in computation: %g",
               adimentionalLength);
  return adimentionalLength;
}

double highOrderPolyMesh::length(PathView &path)
{
  if(path.size() < 2) Msg::Error("Path smaller than 2 (size=%d)", path.size());
  double l = 0;
  for(size_t i = 0; i < path.size() - 1; ++i) {
    SVector3 dl(path[i].xyz(), path[i + 1].xyz());
    l += dl.norm();
  }
  return l;
}

void highOrderPolyMesh::setLength(std::pair<int, int> edge, double length)
{
  if(length <= 0.)
    Msg::Error("Negative or null adimentional length: %g", length);
  if(edge.first > edge.second) std::swap(edge.first, edge.second);
  adimLengths[edge] = length;
}

void highOrderPolyMesh::setAdimLength(std::pair<int, int> edge, double length)
{
  if(length <= 0.)
    Msg::Error("Negative or null adimentional length: %g", length);
  if(edge.first > edge.second) std::swap(edge.first, edge.second);
  adimLengths[edge] = length;
}

double highOrderPolyMesh::length(std::pair<int, int> edge)
{
  PathView path;
  getGeodesicPath(edge.first, edge.second, path);
  lengths[edge] = length(path);
  return lengths[edge];
}

double highOrderPolyMesh::adimLength(std::pair<int, int> edge)
{
  auto it = adimLengths.find(edge);
  if(it != adimLengths.end()) { return it->second; }

  PathView path;
  getGeodesicPath(edge.first, edge.second, path);
  adimLengths[edge] = adimLength(path);
  return adimLengths[edge];
}
double highOrderPolyMesh::adimLengthMin(PolyMesh::HalfEdge *he)
{
  PathView path;
  getPath(he, path);
  return adimLengthMin(path);
}
double highOrderPolyMesh::adimLengthMax(PolyMesh::HalfEdge *he)
{
  PathView path;
  getPath(he, path);
  return adimLengthMax(path);
}
double highOrderPolyMesh::length(PolyMesh::HalfEdge *he)
{
  std::pair<int, int> e = {he->v->data, he->next->v->data};
  return length(e);
}
double highOrderPolyMesh::adimLength(PolyMesh::HalfEdge *he)
{
  std::pair<int, int> e = {he->v->data, he->next->v->data};
  return adimLength(e);
}

std::vector<size_t> &
highOrderPolyMesh::adjacentTriangles(std::pair<int, int> edge)
{
  if(edge.first > edge.second) std::swap(edge.first, edge.second);
  auto it = edges.find(edge);
  static std::vector<size_t> empty;
  return it == edges.end() ? empty : it->second;
}

inline double areaHeuristic(double a, double b, double c)
{
  double s = (a + b + c) / 2;
  return sqrt(s * (s - a) * (s - b) * (s - c));
}

inline double angleHeuristic(double a, double b, double c)
{
  return acos((b * b + c * c - a * a) / (2 * b * c));
}

// SWAP EDGE
/*
             p2                                 p2
           /   \                              / | \
        /         \                        /    |    \
     /       t0      \                  /       |       \
  p0 ----------------- p1     =>     p0    t0   |   t1    p1
     \       t1      /                  \       |       /
        \         /                        \    |    /
           \   /                              \ | /
             p3                                 p3
*/
bool highOrderPolyMesh::swapEdge(
  PolyMesh::HalfEdge *he, std::vector<PolyMesh::HalfEdge *> &adjacentEdges,
  int OPTION)
{
  if(!he->opposite)
    Msg::Error("In swapEdge: halfedge %d %d has no opposite halfedge",
               he->v->data, he->next->v->data);
  std::pair<int, int> edge, oppEdge, ts;
  edge.first = he->v->data;
  edge.second = he->next->v->data;
  oppEdge.first = he->next->next->v->data;
  oppEdge.second = he->opposite->next->next->v->data;
  ts.first = he->f->data;
  ts.second = he->opposite->f->data;
  std::vector<size_t> ats = adjacentTriangles(edge);
  if(ats.size() != 2)
    Msg::Error("In swapEdge: edge %d %d has %d triangles", edge.first,
               edge.second, ats.size());

  PathView p01, p23;
  getGeodesicPath(edge.first, edge.second, p01);
  getGeodesicPath(oppEdge.first, oppEdge.second, p23);
  std::array<PathView, 4> borderPaths;
  getGeodesicPath(edge.first, oppEdge.second, borderPaths[0]);
  getGeodesicPath(oppEdge.second, edge.second, borderPaths[1]);
  getGeodesicPath(edge.second, oppEdge.first, borderPaths[2]);
  getGeodesicPath(oppEdge.first, edge.first, borderPaths[3]);

  if(!doWeSwap(edge, oppEdge, p01, p23, borderPaths, OPTION)) return false;

  // Check topology
  if(adjacentTriangles(oppEdge).size() != 0) {
    // Msg::Warning("Swap edge: Opposite edge already exists");
    return false;
  }

  bool canSwap = true;
  if(!canWeSwap(edge, oppEdge, p01, p23, borderPaths)) { canSwap = false; }

  double q = getEdgeQuality(oppEdge);
  if(q < 0.) { canSwap = false; }

  if(!canSwap) {
    if(WARNING)
      Msg::Warning("Should be swapped but could not: %d %d", edge.first,
                   edge.second);
    if(!splitEdge(he, MINANGLE, MAXANGLE, adjacentEdges)) {
      if(WARNING)
        Msg::Warning("Could not split an edge that should be swapped");
      return false;
    }
    return true;
    // return false;
  }

  doSwapEdge(he);

  adjacentEdges.clear();
  adjacentEdges.push_back(he->next);
  adjacentEdges.push_back(he->next->next);
  adjacentEdges.push_back(he->opposite->next);
  adjacentEdges.push_back(he->opposite->next->next);

  return true;
}

void highOrderPolyMesh::removeAdjacency(std::vector<size_t> &trgls)
{
  for(auto t : trgls) {
    for(int j = 0; j < 3; ++j) {
      std::pair<int, int> e = {triangles[3 * t + j],
                               triangles[3 * t + (j + 1) % 3]};
      if(e.first > e.second) std::swap(e.first, e.second);
      auto it = edges.find(e);
      if(it == edges.end()) throw std::runtime_error("edge not found");
      auto &ats = it->second;
      if(ats[0] == t) std::swap(ats[0], ats.back());
      ats.pop_back();
      if(ats.size() == 0) edges.erase(it);
    }
  }
}

void highOrderPolyMesh::addAdjacency(std::vector<size_t> &trgls)
{
  for(auto t : trgls) {
    for(int j = 0; j < 3; ++j) {
      std::pair<int, int> e = {triangles[3 * t + j],
                               triangles[3 * t + (j + 1) % 3]};
      if(e.first > e.second) std::swap(e.first, e.second);
      edges[e].push_back(t);
    }
  }
}

void highOrderPolyMesh::doSwapEdge(PolyMesh::HalfEdge *he)
{
  std::pair<int, int> edge = {he->v->data, he->next->v->data},
                      oppEdge = {he->next->next->v->data,
                                 he->opposite->next->next->v->data},
                      ts = {he->f->data, he->opposite->f->data};
  std::vector<size_t> ats = {(size_t)ts.first, (size_t)ts.second};
  removeAdjacency(ats);

  triangles[3 * ats[0]] = edge.first;
  triangles[3 * ats[0] + 1] = oppEdge.second;
  triangles[3 * ats[0] + 2] = oppEdge.first;
  triangles[3 * ats[1]] = edge.second;
  triangles[3 * ats[1] + 1] = oppEdge.first;
  triangles[3 * ats[1] + 2] = oppEdge.second;

  addAdjacency(ats);

  if(ipm->swap_edge(he)) Msg::Error("Could not swap pm");
}

void highOrderPolyMesh::getOppEdge(const std::pair<int, int> &p01,
                                   std::pair<int, int> &p23,
                                   std::pair<int, int> &ts)
{
  p23 = {-1, -1};
  ts = {-1, -1};
  for(auto t : adjacentTriangles(p01)) {
    auto is = triangles.begin() + 3 * t;
    for(int j = 0; j < 3; ++j) {
      if(is[j] == p01.first && is[(j + 1) % 3] == p01.second) {
        p23.first = is[(j + 2) % 3];
        ts.first = t;
        break;
      }
      if(is[j] == p01.second && is[(j + 1) % 3] == p01.first) {
        p23.second = is[(j + 2) % 3];
        ts.second = t;
        break;
      }
    }
  }
}

//         / \
//  b[3] /     \ b[2]
//     /         \
//     ---- e ----
//     \         /
//  b[0] \     / b[1]
//         \ /
//
bool highOrderPolyMesh::doWeSwapAngleHeuristic(int p0, int p1, int p2, int p3)
// bool highOrderPolyMesh::doWeSwapAngleHeuristic(PathView &edge, PathView &opp,
//                                                std::array<PathView, 4>
//                                                &borders)
{
  PathView edge, redge, borders[4];
  getGeodesicPath(p0, p1, edge);
  redge = PathView(edge, true);
  getGeodesicPath(p0, p3, borders[0]);
  getGeodesicPath(p3, p1, borders[1]);
  getGeodesicPath(p1, p2, borders[2]);
  getGeodesicPath(p2, p0, borders[3]);
  // PathView redge = PathView(edge, true);

  // double b0 = computeIntrinsicAngle(edge, borders[3]);
  // double b1 = computeIntrinsicAngle(borders[0], redge);
  // double b2 = computeIntrinsicAngle(borders[2], edge);
  // double b3 = computeIntrinsicAngle(redge, borders[1]);
  // double b4 = computeIntrinsicAngle(borders[3], borders[2]);
  // double b5 = computeIntrinsicAngle(borders[1], borders[0]);

  double angles[4] = {computeIntrinsicAngle(borders[3], borders[2]),
                      computeIntrinsicAngle(borders[1], borders[0]),
                      computeIntrinsicAngle(borders[0], borders[3]),
                      computeIntrinsicAngle(borders[2], borders[1])};

  return angles[0] + angles[1] > angles[2] + angles[3] + EPS;
}

bool highOrderPolyMesh::doWeSwapLengthHeuristic(int p0, int p1, int p2, int p3)
{
  PathView edge, opp, borders[4];
  getGeodesicPath(p0, p1, edge);
  getGeodesicPath(p2, p3, opp);
  getGeodesicPath(p0, p3, borders[0]);
  getGeodesicPath(p3, p1, borders[1]);
  getGeodesicPath(p1, p2, borders[2]);
  getGeodesicPath(p2, p0, borders[3]);
  double ledge = length(edge), lopp = length(opp),
         lborders[4] = {length(borders[0]), length(borders[1]),
                        length(borders[2]), length(borders[3])};

  double angles[4] = {angleHeuristic(ledge, lborders[1], lborders[0]),
                      angleHeuristic(ledge, lborders[3], lborders[2]),
                      angleHeuristic(lopp, lborders[0], lborders[3]),
                      angleHeuristic(lopp, lborders[2], lborders[1])};

  return angles[0] + angles[1] > angles[2] + angles[3] + EPS;
}

bool highOrderPolyMesh::doWeSwapMaxMin(int p0, int p1, int p2, int p3)
{
  PathView edge, opp, borders[4], redge, ropp;
  getGeodesicPath(p0, p1, edge);
  getGeodesicPath(p2, p3, opp);
  getGeodesicPath(p0, p3, borders[0]);
  getGeodesicPath(p3, p1, borders[1]);
  getGeodesicPath(p1, p2, borders[2]);
  getGeodesicPath(p2, p0, borders[3]);
  redge = PathView(edge, true);
  ropp = PathView(opp, true);

  std::array<double, 6> before = {computeIntrinsicAngle(edge, borders[3]),
                                  computeIntrinsicAngle(borders[2], edge),
                                  computeIntrinsicAngle(borders[3], borders[2]),
                                  computeIntrinsicAngle(borders[0], redge),
                                  computeIntrinsicAngle(borders[1], borders[0]),
                                  computeIntrinsicAngle(redge, borders[1])};
  std::array<double, 6> after = {computeIntrinsicAngle(opp, borders[2]),
                                 computeIntrinsicAngle(borders[1], opp),
                                 computeIntrinsicAngle(borders[2], borders[1]),
                                 computeIntrinsicAngle(borders[3], ropp),
                                 computeIntrinsicAngle(borders[0], borders[3]),
                                 computeIntrinsicAngle(ropp, borders[0])};

  for(int i = 0; i < 6; ++i) {
    before[i] = before[i] / (M_PI / 3);
    before[i] = (before[i] <= 1) ? before[i] : 2 - before[i];
    after[i] = after[i] / (M_PI / 3);
    after[i] = (after[i] <= 1) ? after[i] : 2 - after[i];
  }

  std::sort(before.begin(), before.end());
  std::sort(after.begin(), after.end());
  return before[0] < after[0] - EPS;
}

bool highOrderPolyMesh::locallyDelaunay(size_t circumindex, double circumradius,
                                        size_t oppVertex)
{
  if(circumradius == geodesic::GEODESIC_INF) return false;
  PathView path;
  getGeodesicPath(circumindex, oppVertex, path);
  double l = length(path);
  return (l / circumradius - 1.) > -EPS;
}

bool highOrderPolyMesh::canWeSwap(const std::pair<int, int> &edge,
                                  const std::pair<int, int> &oppEdge,
                                  PathView &p01, PathView &p23,
                                  std::array<PathView, 4> &borders)
{
  SVector3 intersection;
  std::unordered_map<geodesic::Face *, size_t> faceSegments;
  std::unordered_map<geodesic::Vertex *, std::array<size_t, 2>> vertexSegments;

  if(!intersectGeodesicPath(p23, p01, intersection, &faceSegments,
                            &vertexSegments)) {
    // Msg::Warning("Could not swap edge %d %d: geodesics do not intersect",
    // edge.first, edge.second);
    return false;
  }

  for(int i = 0; i < 4; i++) {
    if(intersectGeodesicPath(p23, borders[i], intersection, &faceSegments,
                             &vertexSegments))
      return false;
  }

  return true;
}

bool highOrderPolyMesh::checkNewTriangles(std::vector<size_t> newTris)
{
  std::vector<std::pair<int, int>> edgesToCheck;
  for(int i = 0; i < newTris.size() / 3; ++i) {
    for(int j = 0; j < 3; ++j) {
      std::pair<int, int> e = {newTris[3 * i + j],
                               newTris[3 * i + (j + 1) % 3]};
      if(e.first > e.second) std::swap(e.first, e.second);
      auto it = std::find(edgesToCheck.begin(), edgesToCheck.end(), e);
      if(it == edgesToCheck.end()) edgesToCheck.push_back(e);
    }
  }

  SVector3 intersection;
  PathView p0, p1;
  std::unordered_map<geodesic::Face *, size_t> faceSegments;
  std::unordered_map<geodesic::Vertex *, std::array<size_t, 2>> vertexSegments;
  for(auto it = edgesToCheck.begin(); it != edgesToCheck.end(); ++it) {
    faceSegments.clear();
    vertexSegments.clear();
    getPath(*it, p0);
    for(auto itt = it + 1; itt != edgesToCheck.end(); ++itt) {
      getPath(*itt, p1);
      if(intersectGeodesicPath(p0, p1, intersection, &faceSegments,
                               &vertexSegments)) {
        // Msg::Warning("Intersection between new triangles");
        return false;
      }
    }
  }

  return true;
}

inline bool highOrderPolyMesh::doWeSwap(const std::pair<int, int> &edge,
                                        std::pair<int, int> &opp, PathView &p01,
                                        PathView &p23,
                                        std::array<PathView, 4> &borders,
                                        int OPTION)
{
  if(OPTION == 0) {
    // bool swapI = doWeSwapIntrinsic(edge, opp);
    // bool swapL =
    //   doWeSwapAngleHeuristic(edge.first, edge.second, opp.first, opp.second);
    // static int count = 0;
    // if(swapI != swapL) std::cout << "noswap: " << ++count << std::endl;
    if(!doWeSwapIntrinsic(edge, opp)) return false;
  }
  else if(OPTION == 1) {
    if(!doWeSwapAngleHeuristic(edge.first, edge.second, opp.first, opp.second))
      return false;
  }
  else if(OPTION == 2) {
    if(!doWeSwapLengthHeuristic(edge.first, edge.second, opp.first, opp.second))
      return false;
  }
  else if(OPTION == 3) {
    if(!doWeSwapLengthHeuristic(edge.first, edge.second, opp.first, opp.second))
      return false;
  }
  return true;
}

bool highOrderPolyMesh::doWeSwapIntrinsic(const std::pair<int, int> &edge,
                                          std::pair<int, int> &oppEdge)
{
  // Check if current config is locally Delaunay
  bool isLocallyDelaunay = true;
  std::array<int, 3> tri = {edge.first, edge.second, oppEdge.first};
  int oppVertex = oppEdge.second;
  geodesic::SurfacePoint circumcenter;
  size_t circumindex;
  double circumradius;
  getCircumcenter(tri, circumindex, circumradius);
  if(!locallyDelaunay(circumindex, circumradius, oppVertex))
    isLocallyDelaunay = false;

  if(isLocallyDelaunay) {
    tri = {edge.first, oppEdge.second, edge.second};
    oppVertex = oppEdge.first;
    getCircumcenter(tri, circumindex, circumradius);
    if(!locallyDelaunay(circumindex, circumradius, oppVertex))
      isLocallyDelaunay = false;
  }

  if(isLocallyDelaunay) return false;

  // Check if swapped config is locally Delaunay
  isLocallyDelaunay = true;
  tri = {edge.first, oppEdge.second, oppEdge.first};
  oppVertex = edge.second;
  getCircumcenter(tri, circumindex, circumradius);
  if(!locallyDelaunay(circumindex, circumradius, oppVertex))
    isLocallyDelaunay = false;

  if(isLocallyDelaunay) {
    tri = {edge.second, oppEdge.first, oppEdge.second};
    oppVertex = edge.first;
    getCircumcenter(tri, circumindex, circumradius);
    if(!locallyDelaunay(circumindex, circumradius, oppVertex))
      isLocallyDelaunay = false;
  }

  if(isLocallyDelaunay) return true;

  Msg::Warning("Neither config is locally Delaunay testing edge swap");
  // static int count = 0;
  // std::cout << "neither: " << ++count << std::endl;
  // {
  //   std::array<int, 3> tri = {edge.first, edge.second, oppEdge.first};
  //   size_t circumindex;
  //   double circumradius;
  //   getCircumcenter(tri, circumindex, circumradius);
  //   std::cout << circumradius << std::endl;
  //   tri = {edge.first, oppEdge.second, edge.second};
  //   getCircumcenter(tri, circumindex, circumradius);
  //   std::cout << circumradius << std::endl;
  //   tri = {edge.first, oppEdge.second, oppEdge.first};
  //   getCircumcenter(tri, circumindex, circumradius);
  //   std::cout << circumradius << std::endl;
  //   tri = {edge.second, oppEdge.first, oppEdge.second};
  //   getCircumcenter(tri, circumindex, circumradius);
  //   std::cout << circumradius << std::endl;
  // }
  return false;
}

void highOrderPolyMesh::precomputeCircumcenters()
{
  std::vector<size_t> ts;
  std::vector<std::vector<geodesic::SurfacePoint>> pts;
  std::vector<geodesic::SurfacePoint> circumcenters;
  std::vector<double> circumradii(ipm->faces.size());
  for(size_t i = 0; i < ipm->faces.size(); ++i) {
    auto he = ipm->faces[i]->he;
    std::array<int, 3> tri = {he->v->data, he->next->v->data,
                              he->next->next->v->data};
    std::sort(tri.begin(), tri.end());
    auto it = circumIndexRadius.find(tri);
    if(it != circumIndexRadius.end()) continue;
    ts.push_back(i);
    pts.push_back({pointsPool[he->v->data], pointsPool[he->next->v->data],
                   pointsPool[he->next->next->v->data]});
  }
  createCircumcenters(pts, circumcenters, circumradii);

  for(size_t i = 0; i < ts.size(); ++i) {
    size_t t = ts[i];
    auto he = ipm->faces[t]->he;
    std::array<int, 3> tri = {he->v->data, he->next->v->data,
                              he->next->next->v->data};
    std::sort(tri.begin(), tri.end());
    setCircumcenter(tri, circumcenters[i], circumradii[i]);
  }
}

int highOrderPolyMesh::swapEdges(int OPTION)
{
  int count = 0;

  // std::unordered_set<PolyMesh::HalfEdge *> set;
  std::set<PolyMesh::HalfEdge *> set, nextSet;
  for(auto he : ipm->hedges) {
    if(!he->opposite) continue;
    if(set.find(he->opposite) != set.end()) continue;
    set.insert(he);
  }

  size_t iter = 1;
  while(!set.empty()) {
    nextSet.clear();

    // Pre-compute circumcenters
    if(PRECOMPUTE_CIRCUMCENTERS) precomputeCircumcenters();

    while(!set.empty()) {
      if(count >= iter * 10000) {
        iter++;
        Msg::Info("Already swapped %d edges (%d triangles, queue "
                  "size = %d)",
                  count, triangles.size() / 3, set.size() + nextSet.size());
      }

      PolyMesh::HalfEdge *he = *(set.begin());
      set.erase(set.begin());

      std::vector<PolyMesh::HalfEdge *> adjacentEdges;
      if(!swapEdge(he, adjacentEdges, OPTION)) continue;
      ++count;

      for(auto he : adjacentEdges) {
        if(!he->opposite) continue;
        auto it = set.find(he);
        if(it != set.end()) { set.erase(it); }
        it = set.find(he->opposite);
        if(it != set.end()) { set.erase(it); }
        nextSet.insert(he);
      }
    }

    set = nextSet;
  }

  return count;
}
// END SWAP EDGE

// SPLIT EDGE
/*
            p2                             p2
          /   \                          / | \
        /       \        =>            /   |   \
      /     t     \                  /     |     \
    /               \              /   t   | tNew  \
  p0 --------------- p1          p0 ----- mid ------ p1
*/
bool highOrderPolyMesh::splitEdge(
  PolyMesh::HalfEdge *he, double MINA, double MAXA,
  std::vector<PolyMesh::HalfEdge *> &adjacentEdges)
{
  std::vector<size_t> adjTriangles = {(size_t)he->f->data};
  if(he->opposite) adjTriangles.push_back(he->opposite->f->data);
  std::pair<int, int> edge = {he->v->data, he->next->v->data};

  // Compute new point
  PathView edgePath;
  std::vector<geodesic::SurfacePoint> firstHalf, secondHalf;
  getPath(edge, edgePath);
  double edgeLength = length(edge), halfLength = .5 * edgeLength;
  splitPath(edgePath, halfLength, firstHalf, secondHalf);
  geodesic::SurfacePoint midPoint = firstHalf.back();

  std::pair<int, int> oppEdge, ts;
  getOppEdge(edge, oppEdge, ts);

  oppEdge.first = he->next->next->v->data;
  ts.first = he->f->data;
  if(he->opposite) {
    oppEdge.second = he->opposite->next->next->v->data;
    ts.second = he->opposite->f->data;
  }
  else {
    oppEdge.second = -1;
    ts.second = -1;
  }

  int oppVertices[2] = {oppEdge.first, oppEdge.second};

  std::vector<std::pair<int, int>> borderEdges;
  if(oppVertices[0] != -1) {
    borderEdges.push_back({edge.second, oppVertices[0]});
    borderEdges.push_back({oppVertices[0], edge.first});
  }
  else {
    borderEdges.push_back({edge.second, edge.first});
  }
  if(oppVertices[1] != -1) {
    borderEdges.push_back({edge.first, oppVertices[1]});
    borderEdges.push_back({oppVertices[1], edge.second});
  }
  else {
    borderEdges.push_back({edge.first, edge.second});
  }

  geodesic::SurfacePoint &pt_start = midPoint;
  std::vector<geodesic::SurfacePoint> pts_end;
  for(int i = 0; i < 2; ++i) {
    if(oppVertices[i] == -1) continue;
    pts_end.push_back(pointsPool[oppVertices[i]]);
  }
  std::vector<std::vector<geodesic::SurfacePoint>> newPaths;
  createGeodesics(pt_start, pts_end, newPaths);
  std::vector<double> newLengths(newPaths.size());
  std::vector<PathView> newPathsV(pts_end.size());
  for(int i = 0; i < newPaths.size(); ++i) {
    PathView pv(newPaths[i]);
    newLengths[i] = adimLength(pv);
    newPathsV[i] = PathView(newPaths[i]);
  }

  // For degenerate cases, check intersection with the border
  std::vector<PathView> borderPaths(borderEdges.size());
  for(int i = 0; i < borderEdges.size(); ++i) {
    getPath(borderEdges[i], borderPaths[i]);
  }
  SVector3 intersection;
  std::unordered_map<geodesic::Face *, size_t> faceSegments;
  std::unordered_map<geodesic::Vertex *, std::array<size_t, 2>> vertexSegments;
  for(auto bpv : borderPaths) {
    faceSegments.clear();
    vertexSegments.clear();
    for(auto npv : newPathsV) {
      if(intersectGeodesicPath(bpv, npv, intersection, &faceSegments,
                               &vertexSegments)) {
        if(WARNING)
          Msg::Warning(
            "Could not split edge %d %d: new geodesic intersects border",
            edge.first, edge.second);
        return false;
      }
    }
  }

  // Check intersection with the original edge
  faceSegments.clear();
  vertexSegments.clear();
  PathView fpv(firstHalf), spv(secondHalf);
  for(auto npv : newPathsV) {
    if(intersectGeodesicPath(fpv, npv, intersection, &faceSegments,
                             &vertexSegments)) {
      if(WARNING)
        Msg::Warning(
          "Could not split edge %d %d: new geodesic intersects original edge",
          edge.first, edge.second);
      return false;
    }
  }
  faceSegments.clear();
  vertexSegments.clear();
  for(auto npv : newPathsV) {
    if(intersectGeodesicPath(spv, npv, intersection, &faceSegments,
                             &vertexSegments)) {
      if(WARNING)
        Msg::Warning(
          "Could not split edge %d %d: new geodesic intersects original edge",
          edge.first, edge.second);
      return false;
    }
  }

  //
  // Split edge
  //
  std::pair<int, int> o, tts;
  getOppEdge(edge, o, tts);
  adjTriangles = {(size_t)tts.first, (size_t)tts.second};
  removeAdjacency(adjTriangles);

  edges.erase(edge);
  int mid = pointsPool.size();
  pointsPool.push_back(midPoint);

  int nbTriangles = adjTriangles.size();
  for(int i = 0; i < nbTriangles; ++i) {
    int t = adjTriangles[i], j = 0;
    for(; j < 3; ++j) {
      if((triangles[3 * t + j] == edge.first &&
          triangles[3 * t + (j + 1) % 3] == edge.second) ||
         (triangles[3 * t + j] == edge.second &&
          triangles[3 * t + (j + 1) % 3] == edge.first))
        break;
    }
    adjTriangles.push_back(triangles.size() / 3);
    triangles.push_back(mid);
    triangles.push_back(triangles[3 * t + (j + 1) % 3]);
    triangles.push_back(triangles[3 * t + (j + 2) % 3]);
    triangles[3 * t + (j + 1) % 3] = mid;
  }

  std::vector<PolyMesh::Face *> faces;
  PolyMesh::Vertex *newV = new PolyMesh::Vertex(
    pointsPool[mid].x(), pointsPool[mid].y(), pointsPool[mid].z(), mid);
  ipm->vertices.push_back(newV);
  ipm->faces.push_back(new PolyMesh::Face(nullptr));
  ipm->faces.back()->data = ipm->faces.size() - 1;
  ipm->hedges.push_back(new PolyMesh::HalfEdge(nullptr));
  ipm->hedges.push_back(new PolyMesh::HalfEdge(nullptr));
  ipm->hedges.push_back(new PolyMesh::HalfEdge(nullptr));
  PolyMesh::Face *fs[2] = {he->f, ipm->faces.back()};
  faces.push_back(fs[0]);
  faces.push_back(fs[1]);
  PolyMesh::HalfEdge *hes[6] = {he,
                                he->next,
                                he->next->next,
                                *(ipm->hedges.rbegin()),
                                *(ipm->hedges.rbegin() + 1),
                                *(ipm->hedges.rbegin() + 2)};
  PolyMesh::Vertex *vs[3] = {hes[0]->v, hes[1]->v, hes[2]->v};
  ipm->createFace(fs[0], vs[0], newV, vs[2], hes[0], hes[3], hes[2]);
  ipm->createFace(fs[1], newV, vs[1], vs[2], hes[4], hes[1], hes[5]);
  hes[3]->opposite = hes[5];
  hes[5]->opposite = hes[3];
  if(he->opposite) {
    he->opposite->opposite = hes[4];
    hes[4]->opposite = he->opposite;
    ipm->faces.push_back(new PolyMesh::Face(nullptr));
    ipm->faces.back()->data = ipm->faces.size() - 1;
    ipm->hedges.push_back(new PolyMesh::HalfEdge(nullptr));
    ipm->hedges.push_back(new PolyMesh::HalfEdge(nullptr));
    ipm->hedges.push_back(new PolyMesh::HalfEdge(nullptr));
    fs[0] = he->opposite->f;
    fs[1] = ipm->faces.back();
    faces.push_back(fs[0]);
    faces.push_back(fs[1]);
    hes[0] = he->opposite;
    hes[1] = he->opposite->next;
    hes[2] = he->opposite->next->next;
    hes[3] = *(ipm->hedges.rbegin());
    hes[4] = *(ipm->hedges.rbegin() + 1);
    hes[5] = *(ipm->hedges.rbegin() + 2);
    vs[0] = hes[0]->v;
    vs[1] = hes[1]->v;
    vs[2] = hes[2]->v;
    ipm->createFace(fs[0], vs[0], newV, vs[2], hes[0], hes[3], hes[2]);
    ipm->createFace(fs[1], newV, vs[1], vs[2], hes[4], hes[1], hes[5]);
    hes[3]->opposite = hes[5];
    hes[5]->opposite = hes[3];
    he->opposite = hes[4];
    hes[4]->opposite = he;
  }

  adjacentEdges.clear();
  for(auto f : faces) {
    auto he = f->he;
    for(int j = 0; j < 3; ++j) {
      adjacentEdges.push_back(he);
      he = he->next;
    }
  }
  addAdjacency(adjTriangles);

  setGeodesic({edge.first, mid}, firstHalf);
  setAdimLength({std::min(edge.first, mid), std::max(edge.first, mid)},
                halfLength);
  setGeodesic({mid, edge.second}, secondHalf);
  setAdimLength({std::min(edge.second, mid), std::max(edge.second, mid)},
                halfLength);
  for(int i = 0; i < 2; ++i) {
    if(oppVertices[i] == -1) continue;
    setGeodesic({oppVertices[i], mid}, newPaths[i]);
    setAdimLength(
      {std::min(oppVertices[i], mid), std::max(oppVertices[i], mid)},
      newLengths[i]);
  }

  return true;
}

static std::array<double, 2> barycentricCoords(const SVector3 &P,
                                               const SVector3 &A,
                                               const SVector3 &B,
                                               const SVector3 &C)
{
  SVector3 v0 = B - A;
  SVector3 v1 = C - A;
  SVector3 v2 = P - A;

  double d00 = v0.x() * v0.x() + v0.y() * v0.y() + v0.z() * v0.z();
  double d01 = v0.x() * v1.x() + v0.y() * v1.y() + v0.z() * v1.z();
  double d11 = v1.x() * v1.x() + v1.y() * v1.y() + v1.z() * v1.z();
  double d20 = v2.x() * v0.x() + v2.y() * v0.y() + v2.z() * v0.z();
  double d21 = v2.x() * v1.x() + v2.y() * v1.y() + v2.z() * v1.z();

  double denom = d00 * d11 - d01 * d01;
  double l1 = (d11 * d20 - d01 * d21) / denom;
  double l2 = (d00 * d21 - d01 * d20) / denom;

  return {l1, l2};
}

void highOrderPolyMesh::splitPath(
  PathView &path, const double length,
  std::vector<geodesic::SurfacePoint> &firstHalf,
  std::vector<geodesic::SurfacePoint> &secondHalf)
{
  if(length < 0) Msg::Error("In splitPath: length is negative");
  if(path.size() < 2)
    Msg::Error("In splitPath: path only made of %d points", path.size());
  firstHalf.clear();
  secondHalf.clear();

  double L = length, dL;
  SVector3 v0 = (path[0]).xyz(), v1;
  int i = 0;
  for(; i + 1 < path.size(); ++i) {
    firstHalf.push_back(path[i]);
    v1 = (path[i + 1]).xyz();
    dL = norm(v1 - v0);
    if(dL >= L) break;
    L -= dL;
    v0 = v1;
  }
  if(i + 1 >= path.size())
    Msg::Error("In splitPath: trying to split a path of length %lf at %lf",
               length - L, length);

  double tLocal = L / dL;
  if(tLocal < 1e-2) { secondHalf.push_back(path[i]); }
  else if(1 - tLocal < 1e-2) {
    firstHalf.push_back(path[i + 1]);
  }
  else {
    geodesic::SurfacePoint sp(
      nullptr, (1 - tLocal) * path[i].x() + tLocal * path[i + 1].x(),
      (1 - tLocal) * path[i].y() + tLocal * path[i + 1].y(),
      (1 - tLocal) * path[i].z() + tLocal * path[i + 1].z(),
      geodesic::UNDEFINED_POINT);

    std::set<geodesic::Vertex *> adjacent_vertices;
    for(int j = 0; j < 2; ++j) {
      geodesic::base_pointer be = path[i + j].base_element();
      if(be->type() == geodesic::VERTEX)
        adjacent_vertices.insert((geodesic::Vertex *)be);
      else {
        for(auto v : be->adjacent_vertices()) adjacent_vertices.insert(v);
      }
    }

    if(adjacent_vertices.size() == 2) { // New point on an edge
      geodesic::Vertex *v0 = *adjacent_vertices.begin();
      geodesic::Vertex *v1 = *adjacent_vertices.rbegin();
      geodesic::Edge *e = nullptr;
      for(auto ae : v0->adjacent_edges()) {
        if(ae->v0() != v1 && ae->v1() != v1) continue;
        e = ae;
        break;
      }
      if(e == nullptr)
        Msg::Error("In splitPath: vertices %d and %a are not connected",
                   v0->id(), v1->id());
      SVector3 v(e->v0()->xyz(), e->v1()->xyz());
      SVector3 w(e->v0()->xyz(), sp.xyz());
      double norm2 = v.x() * v.x() + v.y() * v.y() + v.z() * v.z();
      double d = dot(v, w) / norm2;
      sp = geodesic::SurfacePoint(e, d);
    }
    else if(adjacent_vertices.size() == 3) { // New point on a face
      auto it = adjacent_vertices.begin();
      geodesic::Vertex *v0 = *it++, *v1 = *it++, *v2 = *it++;
      geodesic::Face *f = nullptr;
      for(auto af : v0->adjacent_faces()) {
        auto vs = af->adjacent_vertices();
        if(vs[0] != v1 && vs[1] != v1 && vs[2] != v1) continue;
        if(vs[0] != v2 && vs[1] != v2 && vs[2] != v2) continue;
        f = af;
        break;
      }
      if(f == nullptr)
        Msg::Error("Error in splitPath: vertices are not on the same face");

      std::array<double, 2> uv;
      auto vs = f->adjacent_vertices();
      uv =
        barycentricCoords(sp.xyz(), vs[0]->xyz(), vs[1]->xyz(), vs[2]->xyz());

      sp = geodesic::SurfacePoint(f, uv[0], uv[1]);
    }
    else
      Msg::Error("In splitPath: can not find a SurfacePoint configuration with "
                 "%d adjacent vertices",
                 adjacent_vertices.size());

    firstHalf.push_back(sp);
    secondHalf.push_back(sp);
  }

  i++;
  for(; i < path.size(); ++i) secondHalf.push_back(path[i]);

  if(firstHalf.size() < 2 || secondHalf.size() < 2)
    Msg::Error("In splitPath: could not split path in two paths (%d points and "
               "%d points)",
               firstHalf.size(), secondHalf.size());
}

bool highOrderPolyMesh::doWeSplit(PolyMesh::HalfEdge *he, double MAXE)
{
  double l = adimLengthMax(he);
  return l > MAXE;
}

int highOrderPolyMesh::splitEdges(const double MAXE, double MINA, double MAXA)
{
  int count = 0;
  std::set<HEdgeItem, std::greater<HEdgeItem>> queue;

  for(auto he : ipm->hedges) {
    if(!doWeSplit(he, MAXE)) continue;
    queue.insert(HEdgeItem(he, length(he)));
  }

  size_t iter = 0;
  while(!queue.empty()) {
    if(++iter % 10000 == 0) {
      Msg::Info("Already splitted %d edges (%d triangles, queue size = %d)",
                count, triangles.size() / 3, queue.size());
    }

    HEdgeItem edgeItem = *queue.begin();
    queue.erase(queue.begin());
    PolyMesh::HalfEdge *he = edgeItem.he;

    std::vector<PolyMesh::HalfEdge *> adjacentEdges;
    if(!splitEdge(he, MINA, MAXA, adjacentEdges)) continue;
    ++count;

    for(auto he : adjacentEdges) {
      if(!doWeSplit(he, MAXE)) continue;
      queue.insert(HEdgeItem(he, length(he)));
    }
  }

  return count;
}
// END SPLIT EDGE

// COLLAPSE EDGE
/*
       pB ------ pC ------ pD                 pB ------ pC ------ pD
      / \       / \       / \                / \        |        / \
     /   \     /   \     /   \      =>      /    \      |      /    \
    /     \   /  eT \   /     \            /       \    |    /       \
   /       \ /       \ /       \          /          \  |  /          \
  pA ------ p0 ------ p1 ------ pE       pA ---------- pNew ---------- pE
*/
bool highOrderPolyMesh::collapseEdge(PolyMesh::HalfEdge *he,
                                     std::set<size_t> keep,
                                     std::vector<HEdgeItem> &adjacentEdges,
                                     std::vector<HEdgeItem> &removedEdgeItems,
                                     double MINA, double MAXA)
{
  std::pair<int, int> edge = {he->v->data, he->next->v->data};
  edge.first = he->v->data;
  edge.second = he->next->v->data;

  // Two possible vertex in which collapse
  std::vector<size_t> midIndices = {(size_t)edge.first, (size_t)edge.second};

  std::vector<size_t> borderVertices, cavity;
  cavity = {(size_t)he->f->data};
  if(he->opposite) cavity.push_back(he->opposite->f->data);
  std::vector<size_t> toCheck = cavity;
  while(!toCheck.empty()) {
    size_t t = toCheck.back();
    toCheck.pop_back();
    auto he = ipm->faces[t]->he;
    for(int j = 0; j < 3; ++j) {
      he = he->next;
      int i0 = he->v->data;
      int i1 = he->next->v->data;
      if(i0 != edge.first && i0 != edge.second && i1 != edge.first &&
         i1 != edge.second)
        continue;
      if(!he->opposite) continue;
      size_t of = he->opposite->f->data;
      if(std::find(cavity.begin(), cavity.end(), of) != cavity.end()) continue;
      if(std::find(toCheck.begin(), toCheck.end(), of) != toCheck.end())
        continue;
      cavity.push_back(of);
      toCheck.push_back(of);
    }
  }

  std::vector<std::pair<int, int>> borderEdges;
  for(auto t : cavity) {
    auto he = ipm->faces[t]->he;
    for(int j = 0; j < 3; ++j) {
      he = he->next;
      std::pair<int, int> e = {he->v->data, he->next->v->data}, o = e;
      std::swap(o.first, o.second);
      auto it = std::find(borderEdges.begin(), borderEdges.end(), o);
      if(it != borderEdges.end())
        borderEdges.erase(it);
      else
        borderEdges.push_back(e);
    }
  }

  // Check topology
  if(borderEdges.size() + 2 != cavity.size()) return false;
  for(int i = 0; i < borderEdges.size(); ++i) {
    for(int j = i + 1; j < borderEdges.size(); ++j) {
      if(borderEdges[i].first == borderEdges[j].first) return false;
      if(borderEdges[i].second == borderEdges[j].second) return false;
    }
  }

  std::vector<bool> collapse(midIndices.size(), true);
  std::vector<double> maxlgths(midIndices.size(), 0.);
  std::vector<double> minlgths(midIndices.size(), 1e100);
  std::vector<double> areas(midIndices.size(), 0.);
  std::vector<double> arearatios(midIndices.size(), 0.);
  std::vector<double> qualities(midIndices.size(), 1.);
  std::vector<std::vector<size_t>> newTriss(midIndices.size());
  std::vector<std::vector<size_t>> cavities(midIndices.size());
  for(size_t i = 0; i < midIndices.size(); ++i) {
    auto &midIndex = midIndices[i];
    std::vector<size_t> &newTris = newTriss[i];
    std::vector<size_t> &cavityi = cavities[i];
    cavityi = cavity;

    if(keep.count(midIndex)) {
      collapse[i] = false;
      continue;
    }

    std::vector<geodesic::SurfacePoint> pts_end(borderEdges.size());
    std::vector<PathView> borderPaths(borderEdges.size());
    newTris.resize(3 * borderEdges.size());
    for(int j = 0; j < borderEdges.size(); ++j) {
      newTris[3 * j] = borderEdges[j].first;
      newTris[3 * j + 1] = borderEdges[j].second;
      newTris[3 * j + 2] = midIndex;
      pts_end[j] = pointsPool[borderEdges[j].first];
      getPath(borderEdges[j], borderPaths[j]);
    }

    // Check for intersections
    std::vector<PathView> paths(borderEdges.size());
    std::vector<PathView> pathsV(borderEdges.size());
    SVector3 intersection;
    std::unordered_map<geodesic::Face *, size_t> faceSegments;
    std::unordered_map<geodesic::Vertex *, std::array<size_t, 2>>
      vertexSegments;
    for(int j = 0; j < borderEdges.size(); ++j) {
      faceSegments.clear();
      vertexSegments.clear();
      getGeodesicPath(midIndex, borderEdges[j].first, paths[j]);

      for(int k = 0; k < borderEdges.size(); ++k) {
        if(intersectGeodesicPath(paths[j], borderPaths[k], intersection,
                                 &faceSegments, &vertexSegments)) {
          collapse[i] = false;
          break;
        }
      }
      if(!collapse[i]) break;

      for(int k = 0; k < j; ++k) {
        if(intersectGeodesicPath(paths[j], paths[k], intersection,
                                 &faceSegments, &vertexSegments)) {
          collapse[i] = false;
          break;
        }
      }
      if(!collapse[i]) break;
    }
    if(!collapse[i]) continue;

    if(SWAP_AFTER_COLLAPSE) {
      if(!symbolicSwapEdges(newTris, cavityi, false)) {
        collapse[i] = false;
        continue;
      }
      // if(!checkNewTriangles(newTris)) {
      //   collapse[i] = false;
      //   continue;
      // }
    }

    // Before
    double qualityBefore = 1.;
    double areaBefore = 0;
    for(auto t : cavityi) {
      double angles[3], lengths[3], dlengths[3];
      for(int j = 0; j < 3; ++j) {
        angles[j] = computeIntrinsicAngle(triangles[3 * t + j],
                                          triangles[3 * t + (j + 1) % 3],
                                          triangles[3 * t + (j + 2) % 3]);
        PathView path;
        getGeodesicPath(triangles[3 * t + j], triangles[3 * t + (j + 1) % 3],
                        path);
        lengths[j] = length(path);
        dlengths[j] = norm(SVector3(path.front().xyz(), path.back().xyz()));
      }

      size_t tri[3] = {(size_t)triangles[3 * t], (size_t)triangles[3 * t + 1],
                       (size_t)triangles[3 * t + 2]};
      double q = getTriangleQuality(tri);

      if(q < qualityBefore) qualityBefore = q;

      areaBefore += areaHeuristic(dlengths[0], dlengths[1], dlengths[2]);
    }

    // After
    double area = 0., qualityAfter = 1., maxAdimLength = 0.;
    for(int j = 0; j < newTris.size() / 3; ++j) {
      double angles[3], lengths[3];
      double ls[3];
      for(int k = 0; k < 3; ++k) {
        angles[k] = computeIntrinsicAngle(newTris[3 * j + k],
                                          newTris[3 * j + (k + 1) % 3],
                                          newTris[3 * j + (k + 2) % 3]);
        PathView path;
        getGeodesicPath(newTris[3 * j + k], newTris[3 * j + (k + 1) % 3], path);
        lengths[k] = length(path);
        SVector3 v(path.front().xyz(), path.back().xyz());
        ls[k] = norm(v);
        if(lengths[k] > maxlgths[i]) maxlgths[i] = lengths[k];
        if(lengths[k] < minlgths[i]) minlgths[i] = lengths[k];

        std::vector<double *> edgePointsCoords(path.size());
        for(int i = 0; i < path.size(); ++i) {
          edgePointsCoords[i] = path[i].xyz();
        }
        double q =
          getEdgeQuality({newTris[3 * j + k], newTris[3 * j + (k + 1) % 3]});

        if(q < 0.) {
          collapse[i] = false;
          break;
        }
        double al = adimLength(path);
        if(al > maxAdimLength) maxAdimLength = al;
      }
      if(!collapse[i]) break;

      size_t tri[3] = {newTris[3 * j], newTris[3 * j + 1], newTris[3 * j + 2]};
      double q = getTriangleQuality(tri);
      if(q < qualityAfter) qualityAfter = q;
      qualities[i] = qualityAfter;

      areas[i] += areaHeuristic(ls[0], ls[1], ls[2]);
      area += areaHeuristic(ls[0], ls[1], ls[2]);
    }
    if(!collapse[i]) continue;

    double areaRatio = areaBefore / area;
    if(areaRatio > 1. + FLAT_AREA_RATIO || areaRatio < 1. - FLAT_AREA_RATIO) {
      collapse[i] = false;
      continue;
    }

    if(qualityAfter < 0. || (iter > 1 && qualityAfter - qualityBefore < EPS)) {
      collapse[i] = false;
      continue;
    }
  }

  int i = -1;
  for(int j = 0; j < midIndices.size(); ++j) {
    if(!collapse[j]) continue;
    if(i == -1 || qualities[j] > qualities[i]) i = j;
  }
  if(i == -1) return false;

  doCollapseEdge(edge, midIndices[i], cavities[i], newTriss[i],
                 removedEdgeItems, adjacentEdges);

  return true;
}

bool highOrderPolyMesh::canWeCollapse(
  std::vector<PathView> &newPaths, std::vector<PathView> &borderPaths,
  std::vector<geodesic::SurfacePoint> &borderPath, double &minAngleAfter,
  double &maxAngleAfter)
{
  // Check intersection with border
  SVector3 intersection;
  std::unordered_map<geodesic::Face *, size_t> faceSegments;
  std::unordered_map<geodesic::Vertex *, std::array<size_t, 2>> vertexSegments;
  for(int j = 0; j < newPaths.size(); ++j) {
    PathView bpv(borderPath), npv(newPaths[j]);
    if(intersectGeodesicPath(bpv, npv, intersection, &faceSegments,
                             &vertexSegments)) {
      // Msg::Warning("Collaspe edge : border intersect !");
      return false;
    }
  }

  // Check angles
  for(size_t i = 0; i < borderPaths.size(); ++i) {
    PathView paths[3];
    paths[0] = newPaths[i];
    paths[0] = PathView(paths[0], true);
    paths[1] = borderPaths[i];
    paths[2] = newPaths[(i + 1) % newPaths.size()];
    for(int j = 0; j < 3; ++j) {
      SVector3 n;
      double angle = computeIntrinsicAngle(paths[j], paths[(j + 2) % 3]);
      if(angle < 1e-6 || angle > M_PI - 1e-6) { return false; }
      if(i == 0 && j == 0) { minAngleAfter = maxAngleAfter = angle; }
      if(angle < minAngleAfter) minAngleAfter = angle;
      if(angle > maxAngleAfter) maxAngleAfter = angle;
    }
  }
  return true;
}

double highOrderPolyMesh::getEdgeQuality(std::pair<int, int> e)
{
  double intrinsicLength = length(e);
  PathView path;
  getGeodesicPath(e.first, e.second, path);
  std::vector<double> edgeCoord(3 * path.size());
  for(size_t i = 0; i < path.size(); ++i) {
    edgeCoord[3 * i] = path[i].x();
    edgeCoord[3 * i + 1] = path[i].y();
    edgeCoord[3 * i + 2] = path[i].z();
  }
  return edgeQualityPtr(intrinsicLength, edgeCoord.data(), edgeCoord.size());
}

double edgeQualityDefault(const double intrinsicLength, const double *edgeCoord,
                          const size_t edgeCoord_n)
{
  double dx = edgeCoord[0] - edgeCoord[edgeCoord_n - 3];
  double dy = edgeCoord[1] - edgeCoord[edgeCoord_n - 2];
  double dz = edgeCoord[2] - edgeCoord[edgeCoord_n - 1];
  double l = sqrt(dx * dx + dy * dy + dz * dz);
  return (l / intrinsicLength - 1. / LENGTH_CRITERION);
}

double highOrderPolyMesh::getTriangleQuality(size_t tri[3])
{
  std::vector<double> intrinsicAngles(3), intrinsicLengths(3), coord;
  std::vector<size_t> numPoints(3);
  PathView paths[3];
  for(int j = 0; j < 3; ++j) {
    intrinsicAngles[j] =
      computeIntrinsicAngle(tri[j], tri[(j + 1) % 3], tri[(j + 2) % 3]);
    intrinsicLengths[j] = length({tri[j], tri[(j + 1) % 3]});
    getGeodesicPath(tri[j], tri[(j + 1) % 3], paths[j]);
    numPoints[j] = paths[j].size();
  }
  for(int j = 0; j < 3; ++j) {
    for(int k = 0; k < paths[j].size(); ++k) {
      coord.push_back(paths[j][k].x());
      coord.push_back(paths[j][k].y());
      coord.push_back(paths[j][k].z());
    }
  }
  double quality = triangleQualityPtr(
    intrinsicAngles.data(), intrinsicAngles.size(), intrinsicLengths.data(),
    intrinsicLengths.size(), numPoints.data(), numPoints.size(), coord.data(),
    coord.size());

  return quality;
}

double triangleQualityDefault(const double *intrinsicAngles,
                              const size_t intrinsicAngles_n,
                              const double *intrinsicLengths,
                              const size_t intrinsicLengths_n,
                              const size_t *numPoints, const size_t numPoints_n,
                              const double *edgesCoord,
                              const size_t edgesCoord_n)
{
  double intrinsicQuality = 1.;
  for(int i = 0; i < 3; ++i) {
    double q = intrinsicAngles[i];
    if(q > M_PI / 3) q = (M_PI - q) / 2;
    q = (q - MINANGLE) / (M_PI / 3 - MINANGLE);
    if(q < intrinsicQuality) intrinsicQuality = q;
  }

  return intrinsicQuality;
}

std::function<double(const double, const double *, const size_t)>
  highOrderPolyMesh::edgeQualityPtr = edgeQualityDefault;
std::function<double(const double *, const size_t, const double *, const size_t,
                     const size_t *, const size_t, const double *,
                     const size_t)>
  highOrderPolyMesh::triangleQualityPtr = triangleQualityDefault;

void highOrderPolyMesh::doCollapseEdge(
  std::pair<int, int> &edge, size_t index, std::vector<size_t> &cavity,
  std::vector<size_t> &newTris, std::vector<HEdgeItem> &removedEdgeItems,
  // std::vector<std::pair<int, int>> &borderEdges,
  std::vector<HEdgeItem> &adjacentEdges)
{
  // Remove edges
  removedEdgeItems.clear();
  for(auto t : cavity) {
    auto he = ipm->faces[t]->he;
    for(int j = 0; j < 3; ++j) {
      removedEdgeItems.push_back(HEdgeItem(he, length(he)));
      he = he->next;
    }
  }

  removeAdjacency(cavity);
  std::unordered_map<int, PolyMesh::Vertex *> index2pv;
  std::vector<PolyMesh::HalfEdge *> boundary;
  for(auto t : cavity) {
    auto he = ipm->faces[t]->he;
    for(int j = 0; j < 3; ++j) {
      index2pv[he->v->data] = he->v;
      he->v->he = nullptr;
      he->v = nullptr;
      auto it = std::find(boundary.begin(), boundary.end(), he);
      if(it != boundary.end()) boundary.erase(it);
      if(he->opposite) {
        he->opposite->opposite = nullptr;
        boundary.push_back(he->opposite);
      }
      he->opposite = nullptr;
      he = he->next;
    }
  }
  for(auto he : boundary) { he->v->he = he; }

  // Remove points
  if(index != edge.first) {
    for(auto kv : index2pv) {
      if(kv.first == edge.first) {
        kv.second->he = nullptr;
        kv.second->data = -1;
      }
    }
    removePoint(edge.first);
  }
  if(index != edge.second) {
    for(auto kv : index2pv) {
      if(kv.first == edge.second) {
        kv.second->he = nullptr;
        kv.second->data = -1;
      }
    }
    removePoint(edge.second);
  }
  if(index == pointsPool.size()) {
    pointsPool.push_back(pointsPool[index]);
    ipm->vertices.push_back(new PolyMesh::Vertex(pointsPool[index].x(),
                                                 pointsPool[index].y(),
                                                 pointsPool[index].z(), index));
  }

  for(int i = 0; i < cavity.size(); ++i) {
    int t = cavity[i];
    PolyMesh::HalfEdge *he = ipm->faces[t]->he;

    if(i >= cavity.size() - 2) {
      for(int j = 0; j < 3; ++j) triangles[3 * t + j] = -1;

      he->f->he = nullptr;
      for(int i = 0; i < 3; ++i) {
        he->f = nullptr;
        he = he->next;
      }
      continue;
    }

    triangles[3 * t] = newTris[3 * i];
    triangles[3 * t + 1] = newTris[3 * i + 1];
    triangles[3 * t + 2] = newTris[3 * i + 2];

    for(int j = 0; j < 3; ++j) {
      if(!index2pv[newTris[3 * i + j]]) Msg::Error("index2pv not found");
      PolyMesh::Vertex *v = index2pv[newTris[3 * i + j]];
      he->v = v;
      v->he = he;
      he = he->next;
    }
  }
  for(int i = 0; i < cavity.size() - 2; ++i) {
    size_t t = cavity[i];
    auto he = ipm->faces[t]->he;
    if(!he) continue;
    for(int j = 0; j < 3; ++j) {
      he = he->next;
      for(auto bhe : boundary) {
        if(bhe->next->v->data == he->v->data &&
           bhe->v->data == he->next->v->data) {
          he->opposite = bhe;
          bhe->opposite = he;
          break;
        }
      }
      for(int ii = i + 1; ii < cavity.size() - 2; ++ii) {
        size_t tt = cavity[ii];
        auto hhe = ipm->faces[tt]->he;
        if(!hhe) continue;
        for(int jj = 0; jj < 3; ++jj) {
          hhe = hhe->next;
          if(he->v->data == hhe->next->v->data &&
             he->next->v->data == hhe->v->data) {
            he->opposite = hhe;
            hhe->opposite = he;
            break;
          }
        }
      }
      if(!he->opposite)
        Msg::Error("Culd not find opp of %d %d", he->v->data,
                   he->next->v->data);
    }
  }
  std::vector<PolyMesh::Vertex *> verticesInCavity;
  for(int i = 0; i < cavity.size() - 2; ++i) {
    size_t t = cavity[i];
    auto he = ipm->faces[t]->he;
    if(!he) continue;
    for(int j = 0; j < 3; ++j) {
      he->v->he = he;
      auto it =
        std::find(verticesInCavity.begin(), verticesInCavity.end(), he->v);
      if(it == verticesInCavity.end()) verticesInCavity.push_back(he->v);
      he = he->next;
    }
  }
  int rfcount = 0;
  for(auto t : cavity) {
    if(ipm->faces[t]->he == nullptr) rfcount++;
  }
  if(rfcount != 2) Msg::Error("Did not removed 2 faces");

  cavity.resize(cavity.size() - 2);

  addAdjacency(cavity);

  adjacentEdges.clear();
  std::vector<PolyMesh::HalfEdge *> added;
  for(auto v : verticesInCavity) {
    PolyMesh::HalfEdge *he = v->he;
    do {
      auto it = std::find(added.begin(), added.end(), he->opposite);
      if(it == added.end()) adjacentEdges.push_back(HEdgeItem(he, length(he)));
      if(!he->opposite || !he->opposite->next) Msg::Error("Boundary vertex !");
      he = he->opposite->next;
    } while(he != v->he);
  }
}

void highOrderPolyMesh::cleanAfterCollapse(std::set<size_t> &keep)
{
  for(auto it = circumIndexRadius.begin(); it != circumIndexRadius.end();) {
    if(pointsPool.type(it->second.first) == PointType::Unused)
      it = circumIndexRadius.erase(it);
    else
      ++it;
  }

  for(auto it : circumIndexRadius) {
    for(auto t : it.first) {
      if(pointsPool.type(t) == PointType::Unused) {
        Msg::Warning("unused point still have circumcenter");
      }
    }
    if(pointsPool.type(it.second.first) == PointType::Unused)
      throw std::runtime_error("circumcenter does not exist 0");
    if(it.second.first >= pointsPool.size())
      throw std::runtime_error("circumcenter does not exist 1");
  }

  // Points
  std::unordered_map<size_t, size_t> old2New;
  size_t front = 0, back = pointsPool.size() - 1;
  for(; front <= back; ++front) {
    if(pointsPool.type(front) != PointType::Unused) continue;
    // if(pointsPool.type(front) == PointType::Vertex) continue;

    while(pointsPool.type(back) == PointType::Unused && back != front) --back;
    // while(pointsPool.type(back) != PointType::Vertex && back != front)
    // --back;
    if(back == front) {
      // --front;
      break;
    }

    old2New[back] = front;
    pointsPool.swap(front, back);
  }
  pointsPool.resize(front);

  // Triangles
  std::unordered_map<int, int> old2NewTriangle;
  front = 0;
  back = triangles.size() / 3 - 1;
  for(; front <= back; ++front) {
    // std::cout << front << std::endl;
    // if(triangles[3 * front] != -1) continue;
    if(triangles[3 * front] != -1 && triangles[3 * front + 1] != -1 &&
       triangles[3 * front + 2] != -1)
      continue;

    // while(triangles[3 * back] == -1 && back != front) --back;
    while((triangles[3 * back] == -1 || triangles[3 * back + 1] == -1 ||
           triangles[3 * back + 2] == -1) &&
          back != front) {
      // std::cout << "back: " << back << std::endl;
      --back;
    }
    if(back == front) {
      // std::cout << "break: " << front << " " << back << std::endl;
      // --front;
      break;
    }

    // std::cout << "back swap: " << triangles[3 * back] << " "
    //           << triangles[3 * back + 1] << " " << triangles[3 * back +
    //           2]
    //           << std::endl;

    std::swap(triangles[3 * front], triangles[3 * back]);
    std::swap(triangles[3 * front + 1], triangles[3 * back + 1]);
    std::swap(triangles[3 * front + 2], triangles[3 * back + 2]);
    PolyMesh::Face *ffront = ipm->faces[front], *fback = ipm->faces[back];
    std::swap(ffront->he, fback->he);

    ffront->he->f = ffront;
    ffront->he->next->f = ffront;
    ffront->he->next->next->f = ffront;
  }
  triangles.resize(3 * front);
  // std::cout << triangles.size() << std::endl;
  for(size_t i = 0; i < triangles.size(); ++i) {
    auto it = old2New.find(triangles[i]);
    if(it != old2New.end()) triangles[i] = it->second;
  }
  for(auto v : ipm->vertices) {
    if(old2New.find(v->data) == old2New.end()) continue;
    v->data = old2New[v->data];
  }
  ipm->clean();

  // // Edges
  edges.clear();
  for(size_t i = 0; i < triangles.size(); i += 3) {
    for(unsigned j = 0; j < 3; ++j) {
      std::pair<int, int> e = {triangles[i + j], triangles[i + (j + 1) % 3]};
      if(e.first > e.second) std::swap(e.first, e.second);
      edges[e].push_back(i / 3);
    }
  }

  // Geodesics
  std::vector<std::pair<int, int>> toInsertEdge;
  std::vector<std::vector<geodesic::SurfacePoint>> toInsertGeo;
  for(auto it = geodesics.begin(); it != geodesics.end();) {
    const std::pair<int, int> &edge = it->first;
    auto itfirst = old2New.find(edge.first);
    auto itsecond = old2New.find(edge.second);
    if(itfirst == old2New.end() && itsecond == old2New.end()) {
      ++it;
      continue;
    }
    std::pair<int, int> newEdge = edge;
    if(itfirst != old2New.end()) newEdge.first = itfirst->second;
    if(itsecond != old2New.end()) newEdge.second = itsecond->second;

    toInsertEdge.push_back(newEdge);
    toInsertGeo.push_back(std::move(it->second));
    it = geodesics.erase(it);
  }
  for(size_t i = 0; i < toInsertEdge.size(); ++i) {
    geodesics.emplace(toInsertEdge[i], std::move(toInsertGeo[i]));
  }

  // Lengths
  std::vector<std::pair<int, int>> toInsertEdgeOrdered;
  std::vector<double> toInsertLen;
  for(auto it = adimLengths.begin(); it != adimLengths.end();) {
    const std::pair<int, int> &edge = it->first;
    auto itfirst = old2New.find(edge.first);
    auto itsecond = old2New.find(edge.second);
    if(itfirst == old2New.end() && itsecond == old2New.end()) {
      ++it;
      continue;
    }
    std::pair<int, int> newEdge = edge;
    if(itfirst != old2New.end()) newEdge.first = itfirst->second;
    if(itsecond != old2New.end()) newEdge.second = itsecond->second;

    toInsertLen.push_back(it->second);
    if(newEdge.first > newEdge.second) std::swap(newEdge.first, newEdge.second);
    toInsertEdgeOrdered.push_back(newEdge);
    it = adimLengths.erase(it);
  }
  for(size_t i = 0; i < toInsertEdgeOrdered.size(); ++i) {
    adimLengths.emplace(toInsertEdgeOrdered[i], toInsertLen[i]);
  }
  // geodesics.clear();
  // lengths.clear();

  // CircumInfos
  std::vector<std::pair<std::array<int, 3>, std::pair<size_t, double>>>
    toInsert2;
  for(auto it = circumIndexRadius.begin(); it != circumIndexRadius.end();) {
    auto itt = old2New.find(it->second.first);
    if(itt != old2New.end()) it->second.first = itt->second;

    std::array<int, 3> tri = it->first;
    auto it0 = old2New.find(tri[0]);
    auto it1 = old2New.find(tri[1]);
    auto it2 = old2New.find(tri[2]);
    if(it0 == old2New.end() && it1 == old2New.end() && it2 == old2New.end()) {
      ++it;
      continue;
    }

    if(it0 != old2New.end()) tri[0] = it0->second;
    if(it1 != old2New.end()) tri[1] = it1->second;
    if(it2 != old2New.end()) tri[2] = it2->second;
    std::sort(tri.begin(), tri.end());
    toInsert2.push_back({tri, it->second});
    it = circumIndexRadius.erase(it);
  }
  for(auto kv : toInsert2) circumIndexRadius.emplace(kv.first, kv.second);
  // circumIndexRadius.clear();

  // VertexInfos
  std::vector<int> toIEvg;
  std::vector<std::pair<int, int>> toIGvg;
  vertexGeodesics.clear();
  vertexGeodesics.resize(pointsPool.size(),
                         std::vector<std::pair<int, int>>(0));
  for(auto it = geodesics.begin(); it != geodesics.end();) {
    auto &e = it->first;
    if(e.first >= pointsPool.size() || e.second >= pointsPool.size()) {
      it = geodesics.erase(it);
      continue;
    }
    toIEvg.push_back(e.first);
    toIGvg.push_back(e);
    toIEvg.push_back(e.second);
    toIGvg.push_back(e);
    ++it;
  }
  for(size_t i = 0; i < toIEvg.size(); ++i) {
    vertexGeodesics[toIEvg[i]].push_back(toIGvg[i]);
  }

  std::vector<int> toITriE;
  std::vector<std::array<int, 3>> toITri;
  vertexTriangles.clear();
  for(auto it = circumIndexRadius.begin(); it != circumIndexRadius.end();) {
    auto &tri = it->first;
    if(tri[0] >= pointsPool.size() || tri[1] >= pointsPool.size() ||
       tri[2] >= pointsPool.size()) {
      it = circumIndexRadius.erase(it);
      continue;
    }
    for(auto t : tri) {
      toITriE.push_back(t);
      toITri.push_back(tri);
    }
    ++it;
  }
  for(size_t i = 0; i < toITri.size(); ++i)
    vertexTriangles[toITriE[i]].push_back(toITri[i]);

  // Keep
  std::vector<size_t> toInsertKeep;
  for(auto it = keep.begin(); it != keep.end();) {
    auto itt = old2New.find(*it);
    if(itt == old2New.end()) continue;
    toInsertKeep.push_back(itt->second);
    keep.erase(it);
  }
  for(auto i : toInsertKeep) keep.insert(i);

  for(auto it : circumIndexRadius) {
    for(auto t : it.first) {
      if(pointsPool.type(t) == PointType::Unused)
        throw std::runtime_error("unused point still have circumcenter");
    }
    if(it.second.first >= pointsPool.size())
      throw std::runtime_error("circumcenter does not exist");
  }
}

bool highOrderPolyMesh::doWeCollapse(PolyMesh::HalfEdge *he, double MINE)
{
  double l = adimLengthMin(he);
  return l < MINE;
}

int highOrderPolyMesh::collapseEdges(const double MINE, double MINA,
                                     double MAXA, std::set<size_t> &keep)
{
  std::set<HEdgeItem, std::less<HEdgeItem>> queue;
  for(auto he : ipm->hedges) {
    if(!doWeCollapse(he, MINE)) continue;
    queue.insert(HEdgeItem(he, length(he)));
  }

  size_t iter = 0;
  int count = 0;
  int removedTriangles = 0;
  while(queue.size()) {
    if(++iter % 10000 == 0) {
      Msg::Info("Already collapsed %d edges (%d triangles, queue size = %d)",
                count, triangles.size() / 3 - removedTriangles, queue.size());
    }

    HEdgeItem item = *queue.begin();
    queue.erase(queue.begin());
    PolyMesh::HalfEdge *he = item.he;

    std::vector<HEdgeItem> adjacentEdges;
    std::vector<HEdgeItem> removedEdgeItems;
    int nbrRemovedTri = he->opposite ? 2 : 1;
    if(!collapseEdge(he, keep, adjacentEdges, removedEdgeItems, MINA, MAXA)) {
      continue;
    }
    ++count;
    removedTriangles += nbrRemovedTri;

    for(auto item : removedEdgeItems) {
      auto it = queue.find(item);
      if(it != queue.end()) queue.erase(it);
    }

    for(auto item : adjacentEdges) {
      if(!doWeCollapse(item.he, MINE)) continue;
      queue.insert(item);
    }
  }

  cleanAfterCollapse(keep);

  return count;
}
// END COLLAPSE EDGE

char highOrderPolyMesh::outTriangleFast(int circumindex, int t)
{
  PathView borderPaths[3], inPaths[3];
  PathView bpv[3], ipv[3];
  auto he = ipm->faces[t]->he;
  for(int j = 0; j < 3; ++j) {
    std::pair<int, int> e = {he->v->data, he->next->v->data};
    getGeodesicPath(e.first, e.second, borderPaths[j]);
    getGeodesicPath(e.first, circumindex, inPaths[j]);
    bpv[j] = PathView(borderPaths[j]);
    ipv[j] = PathView(inPaths[j]);
    he = he->next;
  }

  bool neg = false;
  char maxValue = 0b000;
  double maxAngle = -1e100;
  for(int j = 0; j < 3; ++j) {
    double angle = computeIntrinsicAngle(bpv[j], bpv[(j + 2) % 3]);
    angle -= computeIntrinsicAngle(ipv[j], bpv[(j + 2) % 3]);
    if(angle < -1e-10) neg = true;
    if(angle > maxAngle) {
      maxAngle = angle;
      maxValue = (1u << j);
    }
  }
  if(neg)
    return maxValue;
  else
    return 0b000;
}

inline double triangle_area(double a, double b, double c)
{
  // Heron formula stable variant
  double s1 = a + (b + c);
  double s2 = c - (a - b);
  double s3 = c + (a - b);
  double s4 = a + (b - c);
  return 0.25 * sqrt(s1 * s2 * s3 * s4);
}

inline void barycentric_from_lengths(
  double a, double b, double c, // triangle sides: BC, AC, AB
  double dA, double dB, double dC, // distances from P to vertices A,B,C
  double *u, double *v, double *w // output barycentric coordinates
)
{
  double areaABC = triangle_area(a, b, c);

  double areaPBC = triangle_area(a, dB, dC);
  double areaPCA = triangle_area(b, dC, dA);
  double areaPAB = triangle_area(c, dA, dB);

  *u = areaPBC / areaABC;
  *v = areaPCA / areaABC;
  *w = areaPAB / areaABC;
}

bool highOrderPolyMesh::symbolicSwapEdges(std::vector<size_t> &newTris,
                                          std::vector<size_t> &cavity,
                                          bool propagate)
{
  bool swapped = true;

  // Minimal halfedge representation
  std::vector<int> id(newTris.size());
  std::vector<int> next(newTris.size());
  std::vector<int> opposite(newTris.size(), -1);
  for(int i = 0; i < newTris.size() / 3; ++i) {
    for(int j = 0; j < 3; ++j) {
      id[3 * i + j] = newTris[3 * i + j];
      next[3 * i + j] = 3 * i + (j + 1) % 3;
    }
  }

  std::vector<int> list(id.size());
  for(int i = 0; i < id.size(); ++i) {
    list.push_back(i);
    for(int j = i + 1; j < id.size(); ++j) {
      if(id[i] != id[next[j]]) continue;
      if(id[j] != id[next[i]]) continue;
      opposite[i] = j;
      opposite[j] = i;
    }
  }

  std::unordered_map<int, PolyMesh::Vertex *> id2pv;
  for(auto t : cavity) {
    auto he = ipm->faces[t]->he;
    for(int j = 0; j < 3; ++j) {
      he = he->next;
      id2pv[he->v->data] = he->v;
    }
  }

  while(!list.empty()) {
    int he = list.back();
    list.pop_back();

    int i0 = id[he], i1 = id[next[he]], i2 = id[next[next[he]]];

    int ohe = opposite[he];
    if(ohe == -1 && propagate) {
      PolyMesh::HalfEdge *ihe = id2pv[i0]->he;
      do {
        if(ihe->next->v->data == i1) break;
        ihe = ihe->opposite->next;
      } while(ihe != id2pv[i0]->he);
      if(ihe->next->v->data != i1) {
        Msg::Error("Could not find the edge %d %d", i0, i1);
      }
      if(!ihe->opposite) continue;
      int p0 = ihe->v->data;
      int p1 = ihe->next->v->data;
      int p3 = ihe->opposite->next->next->v->data;
      int f103 = ihe->opposite->f->data;
      id2pv[ihe->opposite->next->next->v->data] = ihe->opposite->next->next->v;

      cavity.push_back(f103);
      int idx = id.size();
      id.push_back(p1);
      id.push_back(p0);
      id.push_back(p3);
      next.push_back(idx + 1);
      next.push_back(idx + 2);
      next.push_back(idx);
      opposite.push_back(he);
      opposite[he] = idx;
      opposite.push_back(-1);
      opposite.push_back(-1);
      for(int i = 0; i < id.size(); ++i) {
        if(opposite[i] != -1) continue;
        if(id[i] == p3 && id[next[i]] == p0) {
          opposite[i] = idx + 1;
          opposite[idx + 1] = i;
        }
        if(id[i] == p1 && id[next[i]] == p3) {
          opposite[i] = idx + 2;
          opposite[idx + 2] = i;
        }
      }

      ohe = idx;
    }

    if(ohe == -1) continue;

    int i3 = id[next[next[ohe]]];

    if(i0 != id[next[ohe]] || i1 != id[ohe]) {
      std::cout << id[he] << " " << id[next[he]] << " " << id[next[next[he]]]
                << std::endl;
      std::cout << id[ohe] << " " << id[next[ohe]] << " " << id[next[next[ohe]]]
                << std::endl;
      throw std::runtime_error("wrong values");
    }

    PathView p01, p23;
    getGeodesicPath(i0, i1, p01);
    getGeodesicPath(i2, i3, p23);
    std::array<PathView, 4> borderPaths;
    getGeodesicPath(i0, i3, borderPaths[0]);
    getGeodesicPath(i3, i1, borderPaths[1]);
    getGeodesicPath(i1, i2, borderPaths[2]);
    getGeodesicPath(i2, i0, borderPaths[3]);

    std::pair<int, int> edge = {i0, i1}, oppEdge = {i2, i3};

    if(!doWeSwap(edge, oppEdge, p01, p23, borderPaths, ANGLECRIT)) { continue; }

    if(!canWeSwap(edge, oppEdge, p01, p23, borderPaths)) {
      // Msg::Warning("Edge should be swapped");
      // return false;
      swapped = false;
      continue;
    }

    opposite[he] = opposite[next[ohe]];
    if(opposite[he] != -1) opposite[opposite[he]] = he;
    opposite[ohe] = opposite[next[he]];
    if(opposite[ohe] != -1) opposite[opposite[ohe]] = ohe;
    id[next[he]] = i3;
    id[next[ohe]] = i2;
    opposite[next[he]] = next[ohe];
    opposite[next[ohe]] = next[he];

    int toAdd[4] = {he, next[next[he]], ohe, next[next[ohe]]};
    for(int j = 0; j < 4; ++j) {
      for(int i = 0; i < list.size(); ++i) {
        if(list[i] == toAdd[j] && next[list[i]] == next[toAdd[j]]) {
          toAdd[j] = -1;
          break;
        }
        if(list[i] == next[toAdd[j]] && next[list[i]] == toAdd[j]) {
          toAdd[j] = -1;
          break;
        }
      }
    }
    for(int j = 0; j < 4; ++j) {
      if(toAdd[j] != -1) list.push_back(toAdd[j]);
    }
  }

  newTris.clear();
  for(int i = 0; i < id.size(); ++i) {
    if(id[i] == -1) continue;
    newTris.push_back(id[i]);
    newTris.push_back(id[next[i]]);
    newTris.push_back(id[next[next[i]]]);
    id[next[next[i]]] = -1;
    id[next[i]] = -1;
    id[i] = -1;
  }

  // Remove unchanged triangles
  for(auto it = cavity.begin(); it != cavity.end();) {
    bool remove = false;
    for(int i = 0; i < newTris.size() / 3; ++i) {
      auto he = ipm->faces[*it]->he;
      for(int j = 0; j < 3; ++j) {
        if(he->v->data != newTris[3 * i + j]) continue;
        if(he->next->v->data != newTris[3 * i + (j + 1) % 3]) continue;
        if(he->next->next->v->data != newTris[3 * i + (j + 2) % 3]) continue;
        newTris.erase(newTris.begin() + 3 * i);
        newTris.erase(newTris.begin() + 3 * i);
        newTris.erase(newTris.begin() + 3 * i);
        remove = true;
        break;
      }
      if(remove) break;
    }
    if(remove)
      it = cavity.erase(it);
    else
      ++it;
  }

  return swapped;
}

bool highOrderPolyMesh::splitTriangle(
  int iTriangle, double MINA, double MAXA, std::set<int> &skipTriangles,
  std::vector<TriangleItem> removedTriangles,
  std::vector<TriangleItem> &adjTriangles)
{
  if(skipTriangles.find(iTriangle) != skipTriangles.end()) {
    if(WARNING) Msg::Warning("In splitTriangle: skip triangle");
    return false;
  }

  double radius;
  size_t circumindex;
  getCircumcenter(iTriangle, circumindex, radius);
  geodesic::SurfacePoint sp = pointsPool[circumindex];

  if(radius == geodesic::GEODESIC_INF) {
    if(WARNING) Msg::Warning("In splitTriangle: circumradius is infinite");
    return false;
  }
  if(sp.type() == geodesic::UNDEFINED_POINT) {
    if(WARNING) Msg::Warning("In splitTriangle: circumcenter is undefined");
    return false;
  }
  if(radius == -1) {
    if(WARNING) Msg::Warning("In splitTriangle: circumradius is not computed");
    return false;
  }

  if(pointsPool.type(circumindex) != PointType::Circumcenter) {
    if(WARNING) Msg::Warning("Point not circumcenter anymore");
    return false;
  }

  // Find triangle to split
  int triangleToSplit = iTriangle;
  {
    int newTriangle = triangleToSplit, counter = 0;
    do {
      ++counter;
      if(counter > 1e6) break;
      triangleToSplit = newTriangle;

      char mask = outTriangleFast(circumindex, triangleToSplit);
      if(mask == 0b000) break;

      int i = __builtin_ctz(mask);
      auto he = ipm->faces[triangleToSplit]->he;
      for(char ii = 0; ii < i; ++ii) he = he->next;
      std::pair<int, int> e = {he->next->v->data, he->next->next->v->data};
      auto ats = adjacentTriangles(e);
      if(ats[0] != triangleToSplit) newTriangle = ats[0];
      if(ats[1] != triangleToSplit) newTriangle = ats[1];
      continue;

    } while(newTriangle != triangleToSplit && counter < 1e6);

    if(counter >= 1e6) {
      if(WARNING)
        Msg::Warning(("Could not found the triangle to split (endless loop)"));
      return false;
    }

    if(outTriangleFast(circumindex, triangleToSplit) != 0b000) {
      if(WARNING) Msg::Warning(("Circumcenter not in this triangle !"));
      return false;
    }

    if(skipTriangles.find(triangleToSplit) != skipTriangles.end()) return false;
  }

  std::vector<size_t> cavity = {(size_t)triangleToSplit};
  auto he = ipm->faces[triangleToSplit]->he;
  std::vector<size_t> newTris = {(size_t)he->v->data,
                                 (size_t)he->next->v->data,
                                 circumindex,
                                 (size_t)he->next->v->data,
                                 (size_t)he->next->next->v->data,
                                 circumindex,
                                 (size_t)he->next->next->v->data,
                                 (size_t)he->v->data,
                                 circumindex};

  std::vector<PathView> paths(3), borderPaths(3);
  for(int i = 0; i < 3; ++i) {
    getGeodesicPath(he->v->data, he->next->v->data, borderPaths[i]);
    getGeodesicPath(he->v->data, circumindex, paths[i]);
    he = he->next;
  }

  // Split edge instead of triangle if needed
  for(int i = 0; i < 3; ++i) {
    he = he->next;
    std::pair<int, int> e = {he->v->data, he->next->v->data};
    if(abs(length({e.first, e.second}) - length({e.first, circumindex}) -
           length({circumindex, e.second})) > 1e-12)
      continue;
    auto ats = adjacentTriangles(e);
    ats = {(size_t)he->f->data};
    if(he->opposite) ats.push_back(he->opposite->f->data);
    cavity = ats;
    newTris.clear();
    paths.clear();
    borderPaths.clear();
    newTris.reserve(12);
    paths.reserve(4);
    borderPaths.reserve(4);
    for(auto t : ats) {
      auto he = ipm->faces[t]->he;
      for(int i = 0; i < 3; ++i) {
        he = he->next;
        if((he->v->data == e.first || he->v->data == e.second) &&
           (he->next->v->data == e.first || he->next->v->data == e.second))
          continue;
        newTris.push_back(he->v->data);
        newTris.push_back(he->next->v->data);
        newTris.push_back(circumindex);
        PathView tmp;
        getGeodesicPath(he->v->data, he->next->v->data, tmp);
        borderPaths.push_back(tmp);
        getGeodesicPath(he->v->data, circumindex, tmp);
        paths.push_back(tmp);
      }
    }
  }

  // Check intersections
  SVector3 intersection;
  std::unordered_map<geodesic::Face *, size_t> faceSegments;
  std::unordered_map<geodesic::Vertex *, std::array<size_t, 2>> vertexSegments;
  for(int i = 0; i < paths.size(); ++i) {
    faceSegments.clear();
    vertexSegments.clear();
    for(int j = 0; j < borderPaths.size(); ++j) {
      if(intersectGeodesicPath(paths[i], borderPaths[j], intersection,
                               &faceSegments, &vertexSegments)) {
        // if(WARNING)
        //   Msg::Warning("Could not split triangle: intersection between "
        //                "new path and border");
        return false;
      }
    }
    for(int j = 0; j < i; ++j) {
      if(intersectGeodesicPath(paths[i], paths[j], intersection, &faceSegments,
                               &vertexSegments)) {
        // if(WARNING)
        //   Msg::Warning(
        //     "Could not split triangle: intersection between new paths");
        return false;
      }
    }
  }

  if(true) { symbolicSwapEdges(newTris, cavity); }

  // if(!checkNewTriangles(newTris)) { return false; }

  // Compute triangles qualities
  std::vector<double> qualitiesBefore(cavity.size()),
    qualitiesAfter(newTris.size() / 3);
  double qualityBefore = 1., qualityAfter = 1.;
  for(int i = 0; i < cavity.size(); ++i) {
    size_t t = cavity[i];
    auto he = ipm->faces[t]->he;
    size_t tri[3] = {(size_t)he->v->data, (size_t)he->next->v->data,
                     (size_t)he->next->next->v->data};
    double q = getTriangleQuality(tri);
    qualitiesBefore[i] = q;
    if(q < qualityBefore) qualityBefore = q;
  }

  for(int i = 0; i < newTris.size() / 3; ++i) {
    size_t tri[3] = {newTris[3 * i], newTris[3 * i + 1], newTris[3 * i + 2]};
    double q = getTriangleQuality(tri);
    qualitiesAfter[i] = q;
    if(q < qualityAfter) qualityAfter = q;
  }

  if(iter > 1 && qualityAfter - qualityBefore < EPS) { return false; }

  auto it = std::find(cavity.begin(), cavity.end(), iTriangle);
  if(it == cavity.end()) return false;

  // Split Triangle
  bool success = pointsPool.convertToVertex(circumindex);

  if(!success) { return false; }

  PolyMesh::Vertex *newV = new PolyMesh::Vertex(
    pointsPool[circumindex].x(), pointsPool[circumindex].y(),
    pointsPool[circumindex].z(), circumindex);
  ipm->vertices.push_back(newV);

  removedTriangles.resize(cavity.size());
  std::unordered_map<int, PolyMesh::Vertex *> index2pv;
  index2pv[circumindex] = newV;
  std::vector<PolyMesh::HalfEdge *> boundary;
  for(size_t i = 0; i < cavity.size(); ++i) {
    removedTriangles[i] = TriangleItem((int)cavity[i], qualitiesBefore[i]);
    auto he = ipm->faces[cavity[i]]->he;
    for(int j = 0; j < 3; ++j) {
      index2pv[he->v->data] = he->v;
      he->v->he = nullptr;
      he->v = nullptr;
      auto it = std::find(boundary.begin(), boundary.end(), he);
      if(it != boundary.end()) boundary.erase(it);
      if(he->opposite) {
        he->opposite->opposite = nullptr;
        boundary.push_back(he->opposite);
      }
      he->opposite = nullptr;
      he = he->next;
    }
  }
  for(auto he : boundary) { he->v->he = he; }
  removeAdjacency(cavity);

  cavity.push_back(triangles.size() / 3);
  cavity.push_back(triangles.size() / 3 + 1);
  triangles.insert(triangles.end(), {-1, -1, -1, -1, -1, -1});
  for(int i = 0; i < 2; ++i) {
    PolyMesh::HalfEdge *hs[3] = {new PolyMesh::HalfEdge(nullptr),
                                 new PolyMesh::HalfEdge(nullptr),
                                 new PolyMesh::HalfEdge(nullptr)};
    hs[0]->next = hs[1];
    hs[1]->next = hs[2];
    hs[2]->next = hs[0];
    ipm->hedges.push_back(hs[0]);
    ipm->hedges.push_back(hs[1]);
    ipm->hedges.push_back(hs[2]);
    ipm->faces.push_back(new PolyMesh::Face(hs[0]));
    ipm->faces.back()->data = ipm->faces.size() - 1;

    hs[0]->f = ipm->faces.back();
    hs[1]->f = ipm->faces.back();
    hs[2]->f = ipm->faces.back();
  }
  if(cavity.size() != newTris.size() / 3) {
    std::cout << cavity.size() << " vs " << newTris.size() / 3 << std::endl;
    throw std::runtime_error("erooor not good size");
  }
  for(int i = 0; i < cavity.size(); ++i) {
    auto t = cavity[i];
    auto he = ipm->faces[t]->he;
    for(int j = 0; j < 3; ++j) {
      triangles[3 * t + j] = newTris[3 * i + j];
      auto it = index2pv.find(newTris[3 * i + j]);
      if(it == index2pv.end()) Msg::Error("Vertex not foud");
      he->v = index2pv[newTris[3 * i + j]];
      he->v->he = he;
      he = he->next;
    }
  }

  for(int i = 0; i < cavity.size(); ++i) {
    size_t t = cavity[i];
    auto he = ipm->faces[t]->he;
    if(!he) continue;
    for(int j = 0; j < 3; ++j) {
      he = he->next;
      for(auto bhe : boundary) {
        if(bhe->v->data == he->next->v->data &&
           bhe->next->v->data == he->v->data) {
          he->opposite = bhe;
          bhe->opposite = he;
          break;
        }
      }
      for(int ii = i + 1; ii < cavity.size(); ++ii) {
        size_t tt = cavity[ii];
        auto hhe = ipm->faces[tt]->he;
        if(!hhe) continue;
        for(int jj = 0; jj < 3; ++jj) {
          hhe = hhe->next;
          if(he->v->data == hhe->next->v->data &&
             he->next->v->data == hhe->v->data) {
            he->opposite = hhe;
            hhe->opposite = he;
            break;
          }
        }
      }
      if(!he->opposite)
        Msg::Error("Culd not find opp of %d %d", he->v->data,
                   he->next->v->data);
    }
  }
  for(int i = 0; i < cavity.size(); ++i) {
    size_t t = cavity[i];
    auto he = ipm->faces[t]->he;
    if(!he) continue;
    for(int j = 0; j < 3; ++j) {
      he->v->he = he;
      he = he->next;
    }
  }

  addAdjacency(cavity);

  adjTriangles.resize(cavity.size());
  for(int i = 0; i < cavity.size(); ++i) {
    adjTriangles[i] = TriangleItem((int)cavity[i], qualitiesAfter[i]);
  }

  return true;
}

int highOrderPolyMesh::splitTriangles(double MAXE)
{
  std::set<TriangleItem, std::less<TriangleItem>> queue;
  for(size_t i = 0; i < ipm->faces.size(); ++i) {
    auto he = ipm->faces[i]->he;
    size_t tri[3] = {(size_t)he->v->data, (size_t)he->next->v->data,
                     (size_t)he->next->next->v->data};
    double q = getTriangleQuality(tri);

    if(q < 0.) queue.insert(TriangleItem(i, q));
  }

  int count = 0, iter = 0;
  std::set<int> skipTriangles;
  while(!queue.empty()) {
    if(++iter % 10000 == 0) {
      Msg::Info("Already splitted %d triangles (%d triangles, queue "
                "size = %d)",
                count, ipm->faces.size(), queue.size());
    }

    TriangleItem item = *queue.begin();
    queue.erase(queue.begin());
    std::vector<TriangleItem> removedTriangles, adjTriangles;

    if(splitTriangle(item.index, MINANGLE, MAXANGLE, skipTriangles,
                     removedTriangles, adjTriangles)) {
      ++count;

      for(auto item : removedTriangles) {
        auto it = queue.find(item);
        if(it != queue.end()) queue.erase(it);
      }

      for(auto item : adjTriangles) {
        if(item.quality < 0.) queue.insert(item);
      }
    }
  }

  return count;
}

// END SPLIT TRIANGLE

// CUT MESH
PolyMesh *
highOrderPolyMesh::cutMesh(std::vector<PolyMesh::Vertex *> &pointVertices)
{
  tags.clear();
  evs.clear();
  fvs.clear();
  pvtags.clear();
  pvvtags.clear();
  sp2pv.clear();
  _saddle.clear();
  size_t nbFaces = pm->faces.size();
  std::vector<SVector3> p0;
  std::vector<SVector3> t1;
  std::vector<SVector3> t2;
  std::vector<SVector3> ns;

  for(size_t i = 0; i < nbFaces; i++) {
    PolyMesh::HalfEdge *he = pm->faces[i]->he;
    SVector3 _t1 = he->d();
    SVector3 _t2 = he->next->d();
    _t1.normalize();
    SVector3 _n = crossprod(_t1, _t2);
    _t2 = crossprod(_n, _t1);
    _t2.normalize();
    p0.push_back(he->v->position);
    t1.push_back(_t1);
    t2.push_back(_t2);
    _n.normalize();
    ns.push_back(_n);
  }

  if(false) {
    std::map<PolyMesh::Vertex *, double> nothing;
    print__("spliut.pos", pm, nothing);
  }

  FILE *f = nullptr, *f2 = nullptr;
  if(PRINT) f = fopen("triangulate.pos", "w");
  if(f) fprintf(f, "View \"\"{\n");

  if(PRINT) f2 = fopen("tags.pos", "w");
  if(f2) fprintf(f2, "View \"\"{\n");

  // ---  Cut every mesh edge with eventual additional points

  Msg::Info("Classifying Geodesic Vertices\n");
  classifyGeodesicVertices(pointVertices);
  Msg::Info("Classifying Geodesic Vertices Done\n");

  Msg::Info("Spliting original mesh using geodesics\n");
  for(auto it : evs) {
    PolyMesh::HalfEdge *he = it.first;
    std::vector<PolyMesh::Vertex *> vv;
    for(auto i : it.second) {
      vv.push_back(pm->vertices[i]);
      pm->vertices[i]->position = pm->vertices[i]->position - he->v->position;
    }
    std::sort(vv.begin(), vv.end(), compareVertexOnHalfEdge);
    for(auto i : it.second) {
      pm->vertices[i]->position = pm->vertices[i]->position + he->v->position;
    }
    for(size_t k = 0; k < vv.size(); k++) {
      pm->split_edge_general(he, vv[k]);
      he = he->next;
    }
  }
  Msg::Info("Spliting original mesh using geodesics Done\n");

  // ---  Split every face taking into account constrained edges
  // ---  that belong to geodesic lines
  if(PRINT) {
    // Write the cutted mesh to a .pos file
    std::ofstream posFile1("splitted_mesh.pos");
    if(!posFile1) {
      Msg::Error("Failed to open file: splitted_mesh.pos");
      return nullptr;
    }
    posFile1 << "View \"Cutted Mesh\" {\n";
    for(size_t i = 0; i < pm->vertices.size(); ++i) {
      SVector3 pos = pm->vertices[i]->position;
      posFile1 << "SP(" << pos.x() << "," << pos.y() << "," << pos.z() << "){"
               << pm->vertices[i]->data << "};\n";
    }
    for(size_t i = 0; i < pm->hedges.size(); ++i) {
      PolyMesh::HalfEdge *he = pm->hedges[i];
      // if(he->data == -1) continue;
      posFile1 << "SL(" << he->v->position.x() << "," << he->v->position.y()
               << "," << he->v->position.z() << "," << he->next->v->position.x()
               << "," << he->next->v->position.y() << ","
               << he->next->v->position.z() << "){" << he->data << ","
               << he->data << "};\n";
    }
    for(size_t i = 0; i < pm->faces.size(); ++i) {
      PolyMesh::HalfEdge *he = pm->faces[i]->he;
      posFile1 << "ST(";
      for(int j = 0; j < 3; ++j) {
        posFile1 << he->v->position.x() << "," << he->v->position.y() << ","
                 << he->v->position.z();
        if(j < 2) posFile1 << ",";
        he = he->next;
      }
      posFile1 << "){" << pm->faces[i]->data << "," << pm->faces[i]->data << ","
               << pm->faces[i]->data << "};\n";
    }
    posFile1 << "};\n";
    posFile1.close();
  }

  std::vector<size_t> tris;
  std::vector<size_t> bnds;

  for(size_t i = 0; i < nbFaces; i++) {
    std::vector<double> coord;
    std::vector<PolyMesh::Vertex *> pp;
    PolyMesh::HalfEdge *he = pm->faces[i]->he;
    double maxX = 0., maxY = 0.;
    do {
      SVector3 pos = he->v->position;
      double x = dot(pos - p0[i], t1[i]);
      double y = dot(pos - p0[i], t2[i]);
      if(x > maxX) maxX = x;
      if(y > maxY) maxY = y;
      coord.push_back(x);
      coord.push_back(y);
      pp.push_back(he->v);
      he = he->next;
      // if(he->v->data == 2) std::cout << "2 with " << i << std::endl;
    } while(he != pm->faces[i]->he);

    // // add salt
    // double local_eps = 1e-14 * sqrt(maxX * maxX + maxY * maxY);
    // // std::cout << std::endl;
    // for(int i = 0; i < pp.size(); ++i) {
    //   // std::cout << local_eps * cos((i * 2 * M_PI) / pp.size()) <<
    //   std::endl; coord[2 * i] -= local_eps * cos((i * 2 * M_PI) / pp.size());
    //   coord[2 * i + 1] -= local_eps * sin((i * 2 * M_PI) / pp.size());
    // }

    // Want to recover the boundary of the triangle
    std::vector<size_t> recover_all;
    for(size_t j = 0; j < pp.size(); j++) {
      recover_all.push_back(j);
      recover_all.push_back((j + 1) % pp.size());
    }

    // There exist internal points on the triangle

    auto it = fvs.find(pm->faces[i]);
    FILE *deb = nullptr;
    // FILE *deb = fopen("deb.pos", "w");
    if(deb) fprintf(deb, "View \"\"{\n");
    if(it != fvs.end()) {
      for(size_t j = 0; j < it->second.size(); j++) {
        PolyMesh::Vertex *newv = pm->vertices[it->second[j]];
        SVector3 pos = newv->position;
        double x = dot(pos - p0[i], t1[i]);
        double y = dot(pos - p0[i], t2[i]);
        coord.push_back(x);
        coord.push_back(y);
        pp.push_back(newv);
      }
    }
    for(size_t j = 0; j < coord.size(); j += 2) {
      if(deb)
        fprintf(deb, "SP(%g,%g,%g){1,1,1};\n", coord[2 * j], coord[2 * j + 1],
                0.0);
    }

    // Some other edges should be recovered because they belong to geodesics

    std::vector<size_t> recover;

    for(size_t j = 0; j < pp.size(); j++) {
      PolyMesh::Vertex *vj = pp[j];
      auto itj = pvvtags.find(vj);
      if(itj != pvvtags.end()) {
        for(size_t k = j + 1; k < pp.size(); k++) {
          PolyMesh::Vertex *vk = pp[k];
          for(auto vtagj : itj->second) {
            if(vtagj.second == -1) continue;
            if(vk != vtagj.first) continue;
            recover.push_back(j);
            recover.push_back(k);
            recover_all.push_back(j);
            recover_all.push_back(k);
            // std::cout << "also added " << j << " " << k << std::endl;
            bnds.push_back(vj->data);
            bnds.push_back(vk->data);
            bnds.push_back(vtagj.second);
            // if(vtagj.second == 68) {
            //   std::cout << vj->data << " " << vk->data << std::endl;
            //   for(auto vt : itj->second) {
            //     std::cout << "\t" << vt.first->data << " " << vt.second
            //               << std::endl;
            //   }
            // }
          }
        }
      }
    }

    // // Add salt
    // std::random_device rd;
    // std::mt19937 gen(rd());
    // double local_eps =
    //   1e-12 * std::max(norm(pp[1]->position - pp[0]->position),
    //                    norm(pp[2]->position - pp[0]->position));
    // std::uniform_real_distribution<double> dist(-local_eps, local_eps);
    // for(auto &c : coord) {
    //   std::cout << "dist+ " << dist(gen) << std::endl;
    //   c += dist(gen);
    // }

    if(pp.size() >= 3) {
      std::vector<size_t> tri;
      meshTriangulate2d(coord, tri,
                        recover_all.empty() ? nullptr : &recover_all);

      if(tri.size() == 0) throw std::runtime_error("zero triangles");
      // if(i == 13)
      // std::cout << "13: " << tri.size() << " vs " << pp.size() << std::endl;
      // if(i == 13) throw std::runtime_error("stop");
      // verify if orientation is ok (it should be thet case ...)
      if(0) {
        // if(1) {
        for(size_t j = 0; j < tri.size(); j += 3) {
          int n0 = tri[j] - 1;
          int n1 = tri[j + 2] - 1; // Clockwise orientation
          int n2 = tri[j + 1] - 1;
          PolyMesh::Vertex *j0 = pp[n0];
          PolyMesh::Vertex *j1 = pp[n1];
          PolyMesh::Vertex *j2 = pp[n2];
          SVector3 _t1 = j1->position - j0->position;
          SVector3 _t2 = j2->position - j0->position;
          SVector3 _n = crossprod(_t1, _t2);
          // double area = _n.norm();
          _n.normalize();
          // double ps = dot(_n, ns[i]);
          double pa[2] = {coord[2 * n0], coord[2 * n0 + 1]};
          double pb[2] = {coord[2 * n1], coord[2 * n1 + 1]};
          double pc[2] = {coord[2 * n2], coord[2 * n2 + 1]};
          // double pb[2] = {dot(t1[i], _t1), dot(t2[i], _t1)};
          // double pc[2] = {dot(t1[i], _t2), dot(t2[i], _t2)};
          double ps = robustPredicates::orient2d(pa, pb, pc);
          if(ps < 0) {
            size_t tmp = tri[j];
            tri[j] = tri[j + 2];
            tri[j + 2] = tmp;
          }
        }
      }

      for(size_t j = 0; j < tri.size(); j += 3) {
        int n0 = tri[j] - 1;
        int n1 = tri[j + 2] - 1; // Clockwise orientation
        int n2 = tri[j + 1] - 1;
        PolyMesh::Vertex *j0 = pp[n0];
        PolyMesh::Vertex *j1 = pp[n1];
        PolyMesh::Vertex *j2 = pp[n2];
        tris.push_back(j0->data);
        tris.push_back(j1->data);
        tris.push_back(j2->data);

        if(deb)
          fprintf(deb, "ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%d,%d,%d};\n",
                  coord[2 * n0], coord[2 * n0 + 1], 0.0, coord[2 * n1],
                  coord[2 * n1 + 1], 0.0, coord[2 * n2], coord[2 * n2 + 1], 0.0,
                  j0->data, j1->data, j2->data);

        if(f)
          fprintf(f, "ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%lu,%lu,%lu};\n",
                  j0->position.x(), j0->position.y(), j0->position.z(),
                  j1->position.x(), j1->position.y(), j1->position.z(),
                  j2->position.x(), j2->position.y(), j2->position.z(), i, i,
                  i);
        // j0->data, j1->data, j2->data);
      }
    }
    else
      Msg::Error("Triangle with less than 3 vertices");
    if(deb) {
      fprintf(deb, "};\n");
      fclose(deb);
    }
  }
  if(f) fprintf(f, "};\n");
  if(f) fclose(f);
  if(f2) fprintf(f2, "};\n");
  if(f2) fclose(f2);

  PolyMesh *pm_new = createPolyMesh(pm, tris, bnds);

  if(PRINT) {
    // Write the cutted mesh to a .pos file
    std::ofstream posFile("cutted_mesh.pos");
    if(!posFile) {
      Msg::Error("Failed to open file: cutted_mesh.pos");
      return nullptr;
    }
    posFile << "View \"Cutted Mesh\" {\n";
    for(size_t i = 0; i < pm_new->vertices.size(); ++i) {
      SVector3 pos = pm_new->vertices[i]->position;
      posFile << "SP(" << pos.x() << "," << pos.y() << "," << pos.z() << "){"
              << pm_new->vertices[i]->data << "};\n";
    }
    for(size_t i = 0; i < pm_new->hedges.size(); ++i) {
      PolyMesh::HalfEdge *he = pm_new->hedges[i];
      if(he->data == -1) continue;
      // if(he->data == 68)
      //   std::cout << "\t" << he->data << " :" << he->v->data << " "
      //             << he->next->v->data << std::endl;
      posFile << "SL(" << he->v->position.x() << "," << he->v->position.y()
              << "," << he->v->position.z() << "," << he->next->v->position.x()
              << "," << he->next->v->position.y() << ","
              << he->next->v->position.z() << "){" << he->data << ","
              << he->data << "};\n";
    }
    for(size_t i = 0; i < pm_new->faces.size(); ++i) {
      PolyMesh::HalfEdge *he = pm_new->faces[i]->he;
      posFile << "ST(";
      for(int j = 0; j < 3; ++j) {
        posFile << he->v->position.x() << "," << he->v->position.y() << ","
                << he->v->position.z();
        if(j < 2) posFile << ",";
        he = he->next;
      }
      posFile << "){" << pm_new->faces[i]->data << "," << pm_new->faces[i]->data
              << "," << pm_new->faces[i]->data << "};\n";
    }
    posFile << "};\n";
    posFile.close();
  }

  return pm_new;
}
// END CUT MESH

// WRITE
void highOrderPolyMesh::write(const PolyMesh *pm_new,
                              std::vector<PolyMesh::Vertex *> &pointVertices)
{
  std::ofstream posFile("elements.pos");
  if(posFile.is_open()) {
    posFile << "View \"intrinsicElements\" {\n";
    for(const auto &f : pm_new->faces) {
      posFile << "ST(";
      PolyMesh::HalfEdge *he = f->he;
      for(int i = 0; i < 3; ++i) {
        posFile << he->v->position.x() << "," << he->v->position.y() << ","
                << he->v->position.z();
        if(i < 2) posFile << ",";
        he = he->next;
      }
      posFile << "){" << f->data << "," << f->data << "," << f->data << "};\n";
    }
    posFile << "};\n";
    posFile.close();
  }
  else {
    Msg::Error("Unable to open file for writing");
  }

  //
  // All points
  //

  // Msg::Info("%lu points", pm_new->vertices.size());
  std::map<int, MVertex *> index2MVertex;
  std::map<int, char> pointAssigned;
  Msg::Info("Writing 'points.csv'...");
  std::ofstream outputPoints("points.csv");
  outputPoints << "pointTag,x,y,z\n";
  for(size_t i = 0; i < pm_new->vertices.size(); ++i) {
    auto v = pm_new->vertices[i];
    SVector3 pos = v->position;
    int index = v->data;
    outputPoints << index << "," << pos.x() << "," << pos.y() << "," << pos.z()
                 << "\n";
    auto mv = new MVertex(pos.x(), pos.y(), pos.z());
    mv->setIndex(index);
    index2MVertex[index] = mv;
    pointAssigned[index] = 0;
  }
  outputPoints.close();

  //
  // Vertices
  //
  std::set<int> vertexTags;
  std::vector<int> faceTags(ipm->faces.size());
  std::map<int, int> faceTags2Index;
  for(size_t i = 0; i < ipm->faces.size(); ++i) {
    std::set<int> faces;
    auto fhe = ipm->faces[i]->he;
    for(int j = 0; j < 3; ++j) {
      int index = pm->vertices[sp2pv[fhe->v->data]]->data;
      vertexTags.insert(index); // TODO: manage non-vertex sp
      PolyMesh::HalfEdge *he = pm_new->vertices[index]->he;
      std::set<int> otherFaces;
      do {
        otherFaces.insert(he->f->data);
        if(he->opposite != nullptr)
          he = he->opposite->next;
        else {
          while(he->prev->opposite != nullptr) {
            he = he->prev->opposite;
            otherFaces.insert(he->f->data);
          }
          pm_new->vertices[index]->he = he;
        }
      } while(he != pm_new->vertices[index]->he);
      if(j == 0)
        faces = otherFaces;
      else {
        std::set<int> intersection;
        std::set_intersection(
          faces.begin(), faces.end(), otherFaces.begin(), otherFaces.end(),
          std::inserter(intersection, intersection.begin()));
        faces = intersection;
      }
      fhe = fhe->next;
    }
    if(faces.size() != 1) {
      auto he = ipm->faces[i]->he;
      Msg::Error("Triangle %lu (%lu %lu %lu) correspond to %lu faces", i,
                 he->v->data, he->next->v->data, he->next->next->v->data,
                 faces.size());
      return;
    }
    faceTags[i] = *faces.begin();
    faceTags2Index[faceTags[i]] = i;
  }
  std::ofstream outputVertices;

  //
  // Edges
  //
  Msg::Info("Writing 'edgesT.csv'...");
  std::ofstream outputEdgesT("edgesT.csv");
  outputEdgesT << "vertexTag0,vertexTag1,pointTag,T\n";
  std::unordered_set<std::pair<int, int>, pair_hash> savedEdges;
  std::vector<std::vector<PolyMesh::HalfEdge *>> triangleHEdges(
    3 * ipm->faces.size());
  for(size_t i = 0; i < ipm->faces.size(); ++i) {
    int faceTag = faceTags[i];
    auto fhe = ipm->faces[i]->he;
    for(int j = 0; j < 3; ++j) {
      int index0 = pm->vertices[sp2pv[fhe->v->data]]->data;
      int index1 = pm->vertices[sp2pv[fhe->next->v->data]]->data;
      PolyMesh::HalfEdge *he = pm_new->vertices[index0]->he;
      std::vector<PolyMesh::Vertex *> vs;
      while(he->v->data != index1) {
        while(he->data == -1 || he->f->data != faceTag) {
          if(he->opposite == nullptr) {
            Msg::Error("HalfEdge not found");
            return;
          }
          he = he->opposite->next;
        }
        triangleHEdges[3 * i + j].push_back(he);
        if(triangleHEdges[3 * i + j].size() > 1e5)
          Msg::Error("Could not find next half edge");
        vs.push_back(he->v);
        he = he->next;
      }
      vs.push_back(he->v);

      std::pair<int, int> e = {index0, index1};
      if(e.first > e.second) {
        std::swap(e.first, e.second);
        std::swap(index0, index1);
        std::reverse(vs.begin(), vs.end());
      }
      if(savedEdges.find(e) != savedEdges.end()) continue;
      std::vector<double> ls(vs.size());
      ls[0] = 0.;
      for(int k = 1; k < vs.size(); ++k) {
        ls[k] = ls[k - 1] + norm(vs[k]->position - vs[k - 1]->position);
      }
      for(int k = 0; k < vs.size(); ++k)
        outputEdgesT << index0 << "," << index1 << "," << vs[k]->data << ","
                     << ls[k] / ls[ls.size() - 1] << "\n";
      fhe = fhe->next;
    }
  }
  outputEdgesT.close();
  Msg::Info("Done writing 'edgesT.csv'");

  //
  // Faces
  //
  Msg::Info("Writing 'trianglesUV.csv'...");
  std::ofstream outputTrianglesUV("trianglesUV.csv");
  outputTrianglesUV << "vertexTag0,vertexTag1,vertexTag2,"
                    << "pointTag0,pointU0,pointV0,"
                    << "pointTag1,pointU1,pointV1,"
                    << "pointTag2,pointU2,pointV2\n";

  std::vector<std::vector<size_t>> verticesList(ipm->faces.size());
  std::vector<std::vector<MVertex *>> mVerticesList(ipm->faces.size());
  for(size_t index = 0; index < ipm->faces.size(); ++index) {
    auto he = ipm->faces[index]->he;
    verticesList[index].resize(3);
    mVerticesList[index].resize(3);
    for(int i = 0; i < 3; i++) {
      verticesList[index][i] = pm->vertices[sp2pv[he->v->data]]->data;
      mVerticesList[index][i] = index2MVertex[verticesList[index][i]];
      he = he->next;
    }
  }

  std::set<int> pts;
  std::set<int> boundaryPts;
  std::vector<std::vector<MTriangle *>> mTrianglesList(ipm->faces.size());
  for(size_t i = 0; i < pm_new->faces.size(); ++i) {
    PolyMesh::Face *f = pm_new->faces[i];
    if(f->data < 1) Msg::Error("Face without a tag");
    if(f->data > ipm->faces.size()) Msg::Error("Face with a tag too large");
    PolyMesh::HalfEdge *hes[3] = {f->he, f->he->next, f->he->next->next};

    for(size_t j = 0; j < 3; ++j) {
      if(hes[j]->data == -1)
        pts.insert(hes[j]->v->data);
      else
        boundaryPts.insert(hes[j]->v->data);
    }

    auto mTriangle = new MTriangle(index2MVertex[f->he->v->data],
                                   index2MVertex[f->he->next->v->data],
                                   index2MVertex[f->he->next->next->v->data]);
    mTrianglesList[faceTags2Index[f->data]].push_back(mTriangle);
  }

  for(size_t index = 0; index < ipm->faces.size(); ++index) {
    std::vector<MVertex *> nodes;
    std::vector<SPoint2> stl_vertices_uv;
    std::vector<SPoint3> stl_vertices_xyz;
    std::vector<int> stl_triangles;
    computeParametrization(mTrianglesList[index], nodes, stl_vertices_uv,
                           stl_vertices_xyz, stl_triangles,
                           mVerticesList[index]);

    for(size_t i = 0; i < stl_triangles.size() / 3; i++) {
      outputTrianglesUV << verticesList[index][0] << ","
                        << verticesList[index][1] << ","
                        << verticesList[index][2];
      for(int j = 0; j < 3; ++j) {
        int node = stl_triangles[3 * i + j];
        double u = stl_vertices_uv[node].x();
        double v = stl_vertices_uv[node].y();
        outputTrianglesUV << "," << nodes[node]->getIndex() << ","
                          << (1. - u) / 3 + v / sqrt(3) << ","
                          << (1. - u) / 3 - v / sqrt(3);
      }
      outputTrianglesUV << "\n";
    }
  }
  for(size_t index = 0; index < ipm->faces.size(); ++index) {
    for(auto &mTriangle : mTrianglesList[index]) delete mTriangle;
  }

  outputTrianglesUV.close();
  Msg::Info("Done writing 'trianglesUV.csv'");

  for(size_t i = 0; i < pm_new->vertices.size(); ++i) {
    delete index2MVertex[i];
  }
}
// END WRITE

void saveIsoTriangles(int num, std::vector<int> &triangles, TypedPoints &points,
                      PolyMesh *ipm)
{
  char name[256];
  snprintf(name, sizeof(name), "isoTriangle%d.pos", num);
  std::ofstream f(name);
  if(!f) Msg::Error("Failed to open file: %s", name);
  f << "View \"P\"{\n";
  for(size_t i = 0; i < ipm->faces.size() / 3; ++i) {
    auto he = ipm->faces[i]->he;
    auto sp0 = points[he->v->data];
    auto sp1 = points[he->next->v->data];
    auto sp2 = points[he->next->next->v->data];

    f << "ST(" << sp0.x() << "," << sp0.y() << "," << sp0.z() << "," << sp1.x()
      << "," << sp1.y() << "," << sp1.z() << "," << sp2.x() << "," << sp2.y()
      << "," << sp2.z() << "){" << he->v->data << "," << he->next->v->data
      << "," << he->next->next->v->data << "};\n";
  }
  f << "};\n";
  f.close();
}

bool colorFace(int index, int color, std::vector<int> &faceColors, int maxColor,
               std::vector<std::set<int>> &star)
{
  if(index == star.size()) return true;

  for(auto i : star[index]) {
    if(faceColors[i] == color) return false;
  }
  faceColors[index] = color;

  for(int c = 0; c < maxColor; c++) {
    if(colorFace(index + 1, c, faceColors, maxColor, star)) return true;
  }
  faceColors[index] = -1;
  return false;
}

bool greedyColorFace(int index, std::vector<int> &faceColors, int maxColor,
                     std::vector<std::set<int>> &star, int shift = 0)
{
  if(index == star.size()) return true;

  for(int c = 0; c < maxColor; c++) {
    int color = (c + shift) % maxColor;
    bool sameColor = false;
    for(auto i : star[index]) {
      if(faceColors[i] == color) {
        sameColor = true;
        break;
      }
    }
    if(sameColor) continue;
    faceColors[index] = color;
    break;
  }
  if(faceColors[index] == -1) return false;

  return greedyColorFace(index + 1, faceColors, maxColor, star, shift + 1);
}

bool colorFaces(PolyMesh *pm, std::map<int, int> &face2Colors, int maxColor)
{
  face2Colors.clear();
  for(size_t i = 0; i < pm->faces.size(); ++i) {
    auto it = face2Colors.find(pm->faces[i]->data);
    if(it == face2Colors.end())
      face2Colors[pm->faces[i]->data] = face2Colors.size();
  }
  std::vector<std::set<int>> star(face2Colors.size());
  for(size_t i = 0; i < pm->hedges.size(); ++i) {
    PolyMesh::HalfEdge *he = pm->hedges[i];
    if(he->opposite == nullptr) continue;
    if(he->f == nullptr || he->opposite->f == nullptr)
      Msg::Error("face not found");
    if(he->f->data == he->opposite->f->data) continue;
    star[face2Colors[he->f->data]].insert(face2Colors[he->opposite->f->data]);
    star[face2Colors[he->opposite->f->data]].insert(face2Colors[he->f->data]);
  }

  if(star.size() == 0) Msg::Error("face not found in polymesh");
  std::vector<int> faceColors(star.size(), -1);
  if(!greedyColorFace(0, faceColors, maxColor, star)) return false;

  for(auto kv : face2Colors) face2Colors[kv.first] = faceColors[kv.second];
  return true;
}

void printCuttedMesh(PolyMesh *pm, std::map<int, int> colors)
{
  char name[256];
  snprintf(name, sizeof(name), "colored.pos");
  std::ofstream f(name);
  if(!f) Msg::Error("Failed to open file: %s", name);
  f << "View \"P\"{\n";
  for(size_t i = 0; i < pm->faces.size(); ++i) {
    PolyMesh::HalfEdge *he = pm->faces[i]->he;
    f << "ST(";
    for(int j = 0; j < 3; ++j) {
      f << he->v->position.x() << "," << he->v->position.y() << ","
        << he->v->position.z();
      if(j < 2) f << ",";
      he = he->next;
    }
    if(colors.size() == 0)
      f << "){" << pm->faces[i]->data << "," << pm->faces[i]->data << ","
        << pm->faces[i]->data << "};\n";
    else
      f << "){" << colors[pm->faces[i]->data] << ","
        << colors[pm->faces[i]->data] << "," << colors[pm->faces[i]->data]
        << "};\n";
  }
  f << "};\n";
  f.close();
}

bool highOrderPolyMesh::sanityCheck()
{
  if(ipm->faces.size() != triangles.size() / 3)
    Msg::Error("Triangles sizes does not correspond: %d vs %d",
               ipm->faces.size(), triangles.size() / 3);

  for(int i = 0; i < ipm->faces.size(); ++i) {
    PolyMesh::Face *f = ipm->faces[i];
    PolyMesh::HalfEdge *he = f->he;
    for(int j = 0; j < 3; ++j) {
      PolyMesh::Vertex *v = he->v;
      if(v->data != triangles[3 * i + j] &&
         v->data != triangles[3 * i + (j + 1) % 3] &&
         v->data != triangles[3 * i + (j + 2) % 3]) {
        std::cout << v->data << " " << triangles[3 * i + j] << " "
                  << triangles[3 * i + (j + 1) % 3] << " "
                  << triangles[3 * i + (j + 2) % 3] << std::endl;
        Msg::Error("Triangles %d vertex %d does not correspond", i, j);
      }
      he = he->next;
    }
  }
  if(ipm->faces.size() != ipm->hedges.size() / 3)
    Msg::Error("wrong size between faces and hedge (%d %d)", ipm->faces.size(),
               ipm->hedges.size());
  for(auto he : ipm->hedges) {
    if(!he->f) Msg::Error("he has not f");
    if(he->f->he != he && he->f->he != he->next && he->f->he != he->next->next)
      Msg::Error("he->f->he is not he (%g %g)", he->f->he, he);
    if(he->v->data != he->opposite->next->v->data)
      Msg::Error("not fight opp 1: %d %d vs %d %d", he->v->data,
                 he->next->v->data, he->opposite->v->data,
                 he->opposite->next->v->data);
    if(he->next->v->data != he->opposite->v->data)
      Msg::Error("not fight opp 2");
  }
  return true;

  std::vector<bool> isIn(pointsPool.size());
  for(int i = 0; i < pointsPool.size(); ++i) {
    if(pointsPool.type(i) != PointType::Vertex) isIn[i] = true;
  }
  for(int i = 0; i < triangles.size() / 3; ++i) {
    for(int j = 0; j < 3; ++j) { isIn[triangles[3 * i + j]] = true; }
  }
  bool isSane = true;
  for(int i = 0; i < pointsPool.size(); ++i) {
    if(!isIn[i]) {
      isSane = false;
      break;
    }
  }
  if(!isSane) Msg::Error("not sane");
  return isSane;

  SVector3 intersection;
  std::vector<std::pair<int, int>> edgs;
  for(size_t i = 0; i < triangles.size() / 3; ++i) {
    for(int j = 0; j < 3; ++j) {
      int i0 = triangles[3 * i + j];
      int i1 = triangles[3 * i + (j + 1) % 3];
      if(i0 == -1 || i1 == -1) continue;
      std::pair<int, int> edge = {i0, i1};
      if(edge.first > edge.second) std::swap(edge.first, edge.second);
      if(std::find(edgs.begin(), edgs.end(), edge) == edgs.end())
        edgs.push_back(edge);
    }
  }
  for(size_t i = 0; i < edgs.size(); ++i) {
    std::pair<int, int> e = edgs[i];
    PathView path0;
    getPath(e, path0);

    std::vector<size_t> adjTriangles = adjacentTriangles(e);
    for(size_t j = 0; j < adjTriangles.size(); ++j) {
      size_t t = adjTriangles[j];
      for(int j = 0; j < 3; ++j) {
        auto ts = adjacentTriangles(
          {triangles[3 * t + j], triangles[3 * t + (j + 1) % 3]});
        for(auto tt : ts) {
          if(tt == t) continue;
          auto it = std::find(adjTriangles.begin(), adjTriangles.end(), tt);
          if(it != adjTriangles.end()) continue;
          if(triangles[3 * tt] != e.first && triangles[3 * tt] != e.second &&
             triangles[3 * tt + 1] != e.first &&
             triangles[3 * tt + 1] != e.second &&
             triangles[3 * tt + 2] != e.first &&
             triangles[3 * tt + 2] != e.second)
            continue;
          adjTriangles.push_back(tt);
        }
      }
    }

    for(size_t j = 0; j < adjTriangles.size(); ++j) {
      for(int k = 0; k < 3; ++k) {
        std::pair<int, int> ee = {triangles[3 * adjTriangles[j] + k],
                                  triangles[3 * adjTriangles[j] + (k + 1) % 3]};
        if(ee.first == e.first && ee.second == e.second) continue;
        if(ee.first == e.second && ee.second == e.first) continue;
        PathView p;
        getPath(ee, p);
        if(intersectGeodesicPath(path0, p, intersection)) {
          printGeodesics("geodesic_test.pos");
          // saveIsoTriangles(100, triangles, points, hop.ipm);
          Msg::Info("Intersection between %d %d and %d %d", e.first, e.second,
                    ee.first, ee.second);
          Msg::Info("Intersection at %g %g %g", intersection.x(),
                    intersection.y(), intersection.z());
          Msg::Error("The geodesic mesh is incorrect, likely due to excessive "
                     "decimation. Try reducing the decimation threshold by "
                     "adjusting 'clmin' (currently %g).",
                     1);
        }
      }
    }
  }

  bool sane = true;
  for(size_t i = 0; i < pointsPool.size(); ++i) {
    for(size_t j = i + 1; j < pointsPool.size(); ++j) {
      if(abs(pointsPool[i].x() - pointsPool[j].x()) < 1.e-8 &&
         abs(pointsPool[i].y() - pointsPool[j].y()) < 1.e-8 &&
         abs(pointsPool[i].z() - pointsPool[j].z()) < 1.e-8) {
        Msg::Warning("Two points are too close: %d and %d", i, j);
        Msg::Warning("%d: %g %g %g", i, pointsPool[i].x(), pointsPool[i].y(),
                     pointsPool[i].z());
        Msg::Warning("%d: %g %g %g", i, pointsPool[j].x(), pointsPool[j].y(),
                     pointsPool[j].z());
        sane = false;
      }
    }
  }

  std::set<int> vertices;
  for(size_t i = 0; i < triangles.size(); ++i) {
    if(triangles[i] >= pointsPool.size()) {
      Msg::Warning("Triangle %lu has a vertex %d that does not exist", i,
                   triangles[i]);
      sane = false;
    }
    vertices.insert(triangles[i]);
  }
  if(vertices.size() != pointsPool.size()) {
    Msg::Warning("Some vertices are not used in triangles");
    sane = false;
  }

  std::unordered_map<std::pair<int, int>, std::vector<int>, pair_hash>
    verifEdges;
  // std::map<std::pair<int,int>, std::vector<int>> verifEdges;
  for(size_t i = 0; i < triangles.size(); i += 3) {
    for(int j = 0; j < 3; ++j) {
      std::pair<int, int> edge = {triangles[i + j], triangles[i + (j + 1) % 3]};
      if(edge.first > edge.second) std::swap(edge.first, edge.second);
      verifEdges[edge].push_back(i / 3);
      if(edge.first == -1 || edge.second == -1) continue;
      PathView pTmp;
      getPath(edge, pTmp);
      std::swap(edge.first, edge.second);
      getPath(edge, pTmp);
    }
  }

  if(edges.size() != verifEdges.size()) {
    Msg::Warning("Number of edges is %lu instead of %lu", edges.size(),
                 verifEdges.size());
    sane = false;
  }
  for(auto kv : edges) {
    if(kv.second.size() != verifEdges[kv.first].size()) {
      Msg::Warning("Edge %d %d has %lu triangles instead of %lu",
                   kv.first.first, kv.first.second, kv.second.size(),
                   verifEdges[kv.first].size());
      sane = false;
    }
    for(auto i : kv.second) {
      auto it =
        std::find(verifEdges[kv.first].begin(), verifEdges[kv.first].end(), i);
      if(it == verifEdges[kv.first].end()) {
        Msg::Warning("Edge %d %d is not in triangle %d", kv.first.first,
                     kv.first.second, i);
        sane = false;
      }
    }
  }

  return sane;
}

void highOrderPolyMesh::meshAdapt(int niter, double MINE, double MAXE,
                                  double MINA, double MAXA,
                                  std::set<size_t> &keepSet)
{
  Msg::Info("Begin adaptation:\t\t\tTriangles: %d", ipm->faces.size());
  int i = 0, nbrSwap = 0, nbrCollapse = 0, nbrEdgeSplit = 0,
      nbrTriangleSplit = 0, printIndex = 1;

  if(DEBUG) { sanityCheck(); }

  for(; i < niter; ++i) {
    iter = i;
    nbrSwap = swapEdges();
    Msg::Info("Number of edge swaps: \t%d\tTriangles: %d", nbrSwap,
              ipm->faces.size());

    if(PRINT) {
      printGeodesics("geodesics_swapped.pos");
      saveIsoTriangles(printIndex++, triangles, pointsPool, ipm);
    }
    if(DEBUG) { sanityCheck(); }

    // Collapse edges
    nbrCollapse = collapseEdges(MINE, MINA, MAXA, keepSet);
    Msg::Info("Number of edge collapse: \t%d\tTriangles: %d", nbrCollapse,
              ipm->faces.size());

    if(PRINT) {
      printGeodesics("geodesics_collapse.pos");
      saveIsoTriangles(printIndex++, triangles, pointsPool, ipm);
    }
    if(DEBUG) { sanityCheck(); }

    nbrSwap = swapEdges();
    Msg::Info("Number of edge swaps: \t%d\tTriangles: %d", nbrSwap,
              ipm->faces.size());

    if(PRINT) {
      printGeodesics("geodesics_swapped.pos");
      saveIsoTriangles(printIndex++, triangles, pointsPool, ipm);
    }
    if(DEBUG) { sanityCheck(); }

    // Split triangles
    nbrTriangleSplit = splitTriangles(MAXE);
    Msg::Info("Number of triangle split: \t%d\tTriangles: %d", nbrTriangleSplit,
              ipm->faces.size());

    if(PRINT) {
      printGeodesics("geodesics_triangle_split.pos");
      saveIsoTriangles(printIndex++, triangles, pointsPool, ipm);
    }
    if(DEBUG) { sanityCheck(); }

    nbrSwap = swapEdges();
    Msg::Info("Number of edge swaps: \t%d\tTriangles: %d", nbrSwap,
              ipm->faces.size());

    if(PRINT) {
      printGeodesics("geodesics_swapped_after_triangle_split.pos");
      saveIsoTriangles(printIndex++, triangles, pointsPool, ipm);
    }
    if(DEBUG) { sanityCheck(); }

    // Split edges
    nbrEdgeSplit = splitEdges(MAXE, 0, 1e100);
    Msg::Info("Number of edge split: \t%d\tTriangles: %d", nbrEdgeSplit,
              ipm->faces.size());

    if(PRINT) {
      printGeodesics("geodesics_edge_split.pos");
      saveIsoTriangles(printIndex++, triangles, pointsPool, ipm);
    }
    if(DEBUG) { sanityCheck(); }

    Msg::Info("");
    if(nbrCollapse + nbrEdgeSplit + nbrTriangleSplit == 0) break;
    printIndex -= 6;
  }

  if(niter > 0) {
    nbrSwap = swapEdges();
    Msg::Info("Number of edge swaps: \t%d\tTriangles: %d", nbrSwap,
              ipm->faces.size());

    if(PRINT) {
      printGeodesics("geodesics_swapped.pos");
      saveIsoTriangles(printIndex++, triangles, pointsPool, ipm);
    }
    if(DEBUG) { sanityCheck(); }
  }

  createGeodesics();
  if(PRINT) {
    printGeodesics("geodesics_adapted.pos");
    saveIsoTriangles(printIndex++, triangles, pointsPool, ipm);
  }

  Msg::Info("Adaptation ended.");
}

int makeMeshGeodesic(GModel *gm)
{
  auto start = std::chrono::high_resolution_clock::now();
  if(gm->getNumFaces() == 0) {
    Msg::Error("No faces in the model");
    return 1;
  }

  Msg::Info("Creating a Polymesh");
  PolyMesh *pm;
  GFace2PolyMesh((*gm->firstFace())->tag(), &pm);
  Msg::Info("Creating a Polymesh done -- %lu faces ", pm->faces.size());

  // Check Manifoldness
  std::vector<int> data(pm->vertices.size());
  for(int i = 0; i < pm->vertices.size(); ++i) {
    data[i] = pm->vertices[i]->data;
    pm->vertices[i]->data = i;
  }
  for(int i = 0; i < pm->hedges.size(); ++i) { pm->hedges[i]->data = i; }
  std::vector<bool> checked(pm->hedges.size(), false);
  std::vector<int> nopp(pm->hedges.size(), 0);
  std::vector<int> nfan(pm->vertices.size(), 0);
  for(int i = 0; i < pm->hedges.size(); ++i) {
    PolyMesh::HalfEdge *he = pm->hedges[i];
    if(he->opposite) nopp[he->opposite->data]++;
  }
  for(int i = 0; i < pm->hedges.size(); ++i) {
    PolyMesh::HalfEdge *he = pm->hedges[i];
    if(checked[i]) continue;
    nfan[he->v->data]++;
    do {
      checked[he->data] = true;
      if(nopp[he->data] != 1) {
        he = he->next->next;
        while(nopp[he->data] == 1) { he = he->opposite->next->next; }
      }
      else
        he = he->opposite->next;
    } while(he != pm->hedges[i]);
  }
  int boundary_edge = 0, non_manifold_edge = 0, non_manifold_vertex = 0;
  for(int i = 0; i < pm->vertices.size(); ++i) {
    pm->vertices[i]->data = data[i];
    if(nfan[i] != 1) non_manifold_vertex++;
  }
  for(int i = 0; i < pm->hedges.size(); ++i) {
    if(nopp[i] == 0) boundary_edge++;
    if(nopp[i] > 1) non_manifold_edge++;
  }

  if(boundary_edge != 0 || non_manifold_edge != 0 || non_manifold_vertex != 0)
    Msg::Error("The surface is not a closed manifold (%d boundary edges, %d "
               "non manifold edges, %d non manifold vertices)",
               boundary_edge, non_manifold_edge, non_manifold_vertex);

  std::vector<size_t> tris;
  for(size_t i = 0; i < pm->vertices.size(); ++i) { pm->vertices[i]->data = i; }
  tris.resize(3 * pm->faces.size());
  for(size_t i = 0; i < pm->faces.size(); ++i) {
    PolyMesh::HalfEdge *he = pm->faces[i]->he;
    for(int j = 0; j < 3; ++j) {
      tris[3 * i + j] = he->v->data;
      he = he->next;
    }
  }

  Msg::Info("Creating a Geodesic Mesh");
  highOrderPolyMesh hop(pm, tris);

  // hop.sanityCheck();

  for(auto &kv : hop.edges) {
    if(kv.second.size() != 2) {
      Msg::Warning("Edge %d %d is adjacent to %d faces !", kv.first.first,
                   kv.first.second, kv.second.size());
    }
  }

  // hop.trueCoord = std::vector<SVector3>(hop.pm->vertices.size());
  // for(size_t i = 0; i < hop.pm->vertices.size(); ++i) {
  //   hop.trueCoord[i] = SVector3(hop.pm->vertices[i]->position);
  // }
  hop.characLength = std::vector<double>(hop.pm->vertices.size(), 1);
  double clmin = std::max(1e-100, CTX::instance()->mesh.lcMin);
  double clmax = std::min(1e+100, CTX::instance()->mesh.lcMax);
  hop.characLengthMin = std::vector<double>(hop.pm->vertices.size(), clmin);
  hop.characLengthMax = std::vector<double>(hop.pm->vertices.size(), clmax);

  hop.createInitialGeodesics();

  if(PRINT) {
    hop.printGeodesics("geodesics.pos");
    saveIsoTriangles(0, hop.triangles, hop.pointsPool, hop.ipm);
  }

  std::set<size_t> keep;
  int adapt = CTX::instance()->mesh.maxIterIntrinsic;
  double MINE = 1.;
  double MAXE = 1.;
  double MINA = MINANGLE;
  double MAXA = MAXANGLE;
  hop.meshAdapt(adapt, MINE, MAXE, MINA, MAXA, keep);

  auto endAdapt = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed = endAdapt - start;
  Msg::Info("Computation elapsed time: %.2lf seconds", elapsed.count());

  std::vector<PolyMesh::Vertex *> pointVertices;
  PolyMesh *pm_new = hop.cutMesh(pointVertices);

  auto endCut = std::chrono::high_resolution_clock::now();
  elapsed = endCut - endAdapt;
  Msg::Info("Mesh splitting elapsed time: %.2lf seconds", elapsed.count());

  // STATS
  Msg::Info("STATISTICS:");
  int nbrAngleLessThanMin = 0, nbrAngleGreaterThanMax = 0,
      nbrEdgeLessThanMin = 0, nbrEdgeGreaterThanMax = 0,
      edgeQualityLessThanZero = 0, triangleQualityLessThanZero = 0;
  unsigned angleBins[72] = {0}, zeroAngle = 0;
  double minAngle = 1e100, maxAngle = 0., meanAngle = 0., zeroAngleMax = 1e-5,
         zeroAreaMax = 1e-5;
  for(auto kv : hop.edges) {
    if(kv.second.size() == 0)
      Msg::Warning("Edge without triangle adjacence in edges");
    std::pair<int, int> e = kv.first;
    PathView path;
    hop.getGeodesicPath(e.first, e.second, path);
    PathView pv(path);
    double almin = hop.adimLengthMin(pv);
    double almax = hop.adimLengthMax(pv);
    if(almin < MINE) nbrEdgeLessThanMin++;
    if(almax > MAXE) nbrEdgeGreaterThanMax++;
    double q = hop.getEdgeQuality(e);
    if(q < 0.) edgeQualityLessThanZero++;
  }
  for(size_t i = 0; i < hop.ipm->faces.size(); ++i) {
    auto he = hop.ipm->faces[i]->he;
    for(int j = 0; j < 3; ++j) {
      double angle = hop.computeIntrinsicAngle(he->v->data, he->next->v->data,
                                               he->next->next->v->data);
      if(angle < MINA) nbrAngleLessThanMin++;
      if(angle > MAXA) nbrAngleGreaterThanMax++;
      if(angle < minAngle) minAngle = angle;
      if(angle > maxAngle) maxAngle = angle;
      meanAngle += angle;
      unsigned idx = (unsigned)((angle / M_PI) * 36);
      angleBins[idx]++;
      if(angle < 1e-3) ++zeroAngle;
      he = he->next;
    }
    size_t tri[3] = {(size_t)he->v->data, (size_t)he->next->v->data,
                     (size_t)he->next->next->v->data};
    double q = hop.getTriangleQuality(tri);
    if(q < 0.) triangleQualityLessThanZero++;
  }
  meanAngle /= hop.ipm->faces.size() * 3;
  std::vector<double> areas(hop.ipm->faces.size(), 0);
  for(auto f : pm_new->faces) {
    SVector3 p0(f->he->next->v->position - f->he->v->position);
    SVector3 p1(f->he->next->next->v->position - f->he->v->position);
    if(f->data - 1 >= hop.ipm->faces.size()) {
      std::vector<std::vector<int>> faceTagVertex;
      for(auto ff : pm_new->faces) {
        auto he = ff->he;
        for(int i = 0; i < 3; ++i) {
          for(int j = 0; j < hop.pointsPool.size(); ++j) {
            if(hop.pointsPool.type(j) != PointType::Vertex) continue;
            auto v = hop.pointsPool[j];
            double dx = he->v->position.x() - v.x();
            double dy = he->v->position.y() - v.y();
            double dz = he->v->position.z() - v.z();
            if(sqrt(dx * dx + dy * dy + dz * dz) > 1e-12) continue;
            if(faceTagVertex.size() < ff->data) faceTagVertex.resize(ff->data);
            auto it = std::find(faceTagVertex[ff->data - 1].begin(),
                                faceTagVertex[ff->data - 1].end(), j);
            if(it == faceTagVertex[ff->data - 1].end())
              faceTagVertex[ff->data - 1].push_back(j);
          }
          he = he->next;
        }
      }

      for(int i = 0; i < faceTagVertex.size(); ++i) {
        if(faceTagVertex[i].size() != 3) {
          std::cout << "Face (" << i << ") has " << faceTagVertex[i].size()
                    << " vertices:" << std::endl;
          for(auto ii : faceTagVertex[i]) {
            std::cout << "\t" << hop.pointsPool[ii].x() << " "
                      << hop.pointsPool[ii].y() << " " << hop.pointsPool[ii].z()
                      << std::endl;
          }
        }
      }

      std::cout << f->data << std::endl;
      std::cout << f->he->next->next->v->position.x() << " "
                << f->he->next->next->v->position.y() << " "
                << f->he->next->next->v->position.z() << std::endl;
      std::cout << f->he->next->v->position.x() << " "
                << f->he->next->v->position.y() << " "
                << f->he->next->v->position.z() << std::endl;
      std::cout << f->he->v->position.x() << " " << f->he->v->position.y()
                << " " << f->he->v->position.z() << std::endl;
      Msg::Error("Triangle does not exist");
    }
    areas[f->data - 1] += norm(crossprod(p0, p1)) / 2;
  }
  unsigned nbrZeroArea = 0;
  double minA = 1e100, maxA = 0, meanA = 0;
  for(int i = 0; i < hop.ipm->faces.size(); ++i) {
    if(areas[i] < minA) minA = areas[i];
    if(areas[i] > maxA) maxA = areas[i];
    meanA += areas[i];
    if(areas[i] < 1e-3) { nbrZeroArea++; }
  }
  meanA /= hop.ipm->faces.size();

  Msg::Info("Number of vertices: %d", hop.pointsPool.size());
  Msg::Info("Number of edges: %d", hop.edges.size());
  Msg::Info("Number of triangles: %d", hop.ipm->faces.size());
  Msg::Info("Number of edges less than %g: %d", MINE, nbrEdgeLessThanMin);
  Msg::Info("Number of edges greater than %g: %d", MAXE, nbrEdgeGreaterThanMax);
  Msg::Info("Number of angles less than %g: %d", MINA, nbrAngleLessThanMin);
  Msg::Info("Number of angles greater than %g: %d", MAXA,
            nbrAngleGreaterThanMax);
  Msg::Info("Minimum angle: %g (%g deg)", minAngle,
            minAngle / (2 * M_PI) * 360);
  Msg::Info("Mean angle: %g (%g deg)", meanAngle, meanAngle / (2 * M_PI) * 360);
  Msg::Info("Maximum angle: %g (%g deg)", maxAngle,
            maxAngle / (2 * M_PI) * 360);
  Msg::Info("Angle repatition: ");
  std::cout << "\t";
  for(int i = 0; i < 72; ++i) { std::cout << angleBins[i] << " "; }
  std::cout << "\n";
  Msg::Info("Nbr of angles less than %g: %d", zeroAngleMax, zeroAngle);
  Msg::Info("Nbr of edge with quality less than 0: %d",
            edgeQualityLessThanZero);
  Msg::Info("Nbr of triangles with quality less than 0: %d",
            triangleQualityLessThanZero);
  Msg::Info("Min area triangle: %g", minA);
  Msg::Info("Mean area triangle: %g", meanA);
  Msg::Info("Max area triangle: %g", maxA);
  Msg::Info("Nbr areas less than %g: %d", zeroAreaMax, nbrZeroArea);

  auto endStat = std::chrono::high_resolution_clock::now();
  elapsed = endStat - endCut;
  Msg::Info("Statistics elapsed time: %.2lf seconds", elapsed.count());

  std::map<int, int> face2Colors;
  int c = 4;
  Msg::Info("Trying to color with %d colors.", c);
  while(!colorFaces(pm_new, face2Colors, c)) {
    Msg::Info("Coloring with %d colors failed.", c);
    c++;
    Msg::Info("Trying to color with %d colors.", c);
  }
  printCuttedMesh(pm_new, face2Colors);

  hop.write(pm_new, pointVertices);

  auto end = std::chrono::high_resolution_clock::now();
  elapsed = end - endStat;
  Msg::Info("Write elapsed time: %.2lf seconds", elapsed.count());

  elapsed = end - start;
  Msg::Info("----------------------------------------");
  Msg::Info("Total elapsed time: %.2lf seconds", elapsed.count());

  return 0;
}

#else

int makeMeshGeodesic(GModel *gm)
{
  Msg::Error("Geodesic meshing not available");
  return 0;
}

#endif
