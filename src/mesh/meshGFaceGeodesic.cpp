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
#include <limits>
#include <map>
#include <ostream>
#include <random>
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
#define PRINT_COLORED false
#define WARNING false
#define PRINT_STEP ((size_t)1e5)
#define PRINT_STEP_SWAP ((size_t)1e6)
#define ASTAR true
#define EPS 1e-8
#define CIRCUMMULT 5
#define HEURISTIC_SWAP true
#define SPLIT_IF_CANT_SWAP true

#define MINANGLE (CTX::instance()->mesh.minIntrinsicAngle * M_PI / 180)
#define MAXANGLE (CTX::instance()->mesh.maxIntrinsicAngle * M_PI / 180)
#define MINAHEURISTIC MINANGLE
#define MAXAHEURISTIC MAXANGLE

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
    if(v->id() >= values.size()) Msg::Error("Value not defined for vertex");
    return values[v->id()];
  }

  if(sp.type() == geodesic::EDGE) {
    geodesic::Edge *e = (geodesic::Edge *)sp.base_element();
    geodesic::Vertex *v0 = e->v0();
    geodesic::Vertex *v1 = e->v1();
    if(v0->id() >= values.size() || v1->id() >= values.size())
      Msg::Error("Value not defined for edge vertex");
    double u = sp.uv()[0];
    return (1. - u) * values[v0->id()] + u * values[v1->id()];
  }

  if(sp.type() == geodesic::FACE) {
    geodesic::Face *f = (geodesic::Face *)sp.base_element();
    auto &v0 = f->adjacent_vertices()[0];
    auto &v1 = f->adjacent_vertices()[1];
    auto &v2 = f->adjacent_vertices()[2];
    if(v0->id() >= values.size() || v1->id() >= values.size() ||
       v2->id() >= values.size())
      Msg::Error("Value not defined for face vertex");
    double u = sp.uv()[0], v = sp.uv()[1], w = 1. - u - v;
    return w * values[v0->id()] + u * values[v1->id()] + v * values[v2->id()];
  }

  Msg::Error("SurfacePoint type unknown");
  return T();
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
  const double ux = pb[0] - pa[0];
  const double uy = pb[1] - pa[1];
  const double vx = pc[0] - pa[0];
  const double vy = pc[1] - pa[1];
  const double dot = ux * vx + uy * vy;
  const double orient = robustPredicates::orient2d(pa, pb, pc);
  double angle = atan2(orient, dot);
  if(angle < 0.0) angle += 2.0 * M_PI;
  return angle;
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

inline void robustCrossProd(const double p0[3], const double p1[3],
                            const double p2[3], double crossprod[3])
{
  double pa[2], pb[2], pc[2];
  for(int i = 0; i < 3; ++i) {
    int i1 = (i + 1) % 3;
    int i2 = (i + 2) % 3;
    pa[0] = p1[i1];
    pa[1] = p1[i2];
    pb[0] = p2[i1];
    pb[1] = p2[i2];
    pc[0] = p0[i1];
    pc[1] = p0[i2];
    crossprod[i] = robustPredicates::orient2d(pa, pb, pc);
    if(isnan(crossprod[i])) Msg::Error("Error NaN");
  }
}

inline double computeAngleOnFace(const double p0[3], const double p1[3],
                                 const double p2[3], const double v0[3],
                                 const double v1[3], const double v2[3])
{
  const double ux = p1[0] - p0[0];
  const double uy = p1[1] - p0[1];
  const double uz = p1[2] - p0[2];
  const double vx = p2[0] - p0[0];
  const double vy = p2[1] - p0[1];
  const double vz = p2[2] - p0[2];
  const double dot = ux * vx + uy * vy + uz * vz;

  double angle_cp[3], face_cp[3];
  robustCrossProd(p0, p1, p2, angle_cp);
  robustCrossProd(v0, v1, v2, face_cp);

  const double angle_norm =
    sqrt(angle_cp[0] * angle_cp[0] + angle_cp[1] * angle_cp[1] +
         angle_cp[2] * angle_cp[2]);
  const double face_norm =
    sqrt(face_cp[0] * face_cp[0] + face_cp[1] * face_cp[1] +
         face_cp[2] * face_cp[2]);
  if(angle_norm <= 0 || face_norm <= 0) return (dot >= 0.0) ? 0.0 : M_PI;

  const double orient = face_cp[0] * angle_cp[0] + face_cp[1] * angle_cp[1] +
                        face_cp[2] * angle_cp[2];
  return atan2(((orient < 0.0) ? -1.0 : +1.0) * abs(angle_norm), dot);
}

inline void getFaceParamCoord(geodesic::SurfacePoint &p, geodesic::Face *f,
                              double uv[2])
{
  if(p.type() == geodesic::FACE) {
    uv[0] = p.uv()[0];
    uv[1] = p.uv()[1];
  }
  else if(p.type() == geodesic::EDGE) {
    geodesic::Edge *e = static_cast<geodesic::Edge *>(p.base_element());
    if(f->adjacent_vertices()[0] == e->v0() &&
       f->adjacent_vertices()[1] == e->v1()) {
      uv[0] = p.uv()[0];
      uv[1] = 0.;
    }
    else if(f->adjacent_vertices()[1] == e->v0() &&
            f->adjacent_vertices()[0] == e->v1()) {
      uv[0] = 1. - p.uv()[0];
      uv[1] = 0.;
    }
    else if(f->adjacent_vertices()[1] == e->v0() &&
            f->adjacent_vertices()[2] == e->v1()) {
      uv[0] = 1. - p.uv()[0];
      uv[1] = p.uv()[0];
    }
    else if(f->adjacent_vertices()[2] == e->v0() &&
            f->adjacent_vertices()[1] == e->v1()) {
      uv[0] = p.uv()[0];
      uv[1] = 1. - p.uv()[0];
    }
    else if(f->adjacent_vertices()[2] == e->v0() &&
            f->adjacent_vertices()[0] == e->v1()) {
      uv[0] = 0.;
      uv[1] = 1. - p.uv()[0];
    }
    else if(f->adjacent_vertices()[0] == e->v0() &&
            f->adjacent_vertices()[2] == e->v1()) {
      uv[0] = 0.;
      uv[1] = p.uv()[0];
    }
  }
  else if(p.type() == geodesic::VERTEX) {
    if(f->adjacent_vertices()[0] == p.base_element()) {
      uv[0] = 0.;
      uv[1] = 0.;
    }
    else if(f->adjacent_vertices()[1] == p.base_element()) {
      uv[0] = 1.;
      uv[1] = 0.;
    }
    else if(f->adjacent_vertices()[2] == p.base_element()) {
      uv[0] = 0.;
      uv[1] = 1.;
    }
  }
  else {
    Msg::Error("Undefined surface point");
  }
}

inline double computeAngleOnFace(geodesic::SurfacePoint &p0,
                                 geodesic::SurfacePoint &p1,
                                 geodesic::SurfacePoint &p2, geodesic::Face *f)
{
  double p0_uv[2], p1_uv[2], p2_uv[2];
  getFaceParamCoord(p0, f, p0_uv);
  getFaceParamCoord(p1, f, p1_uv);
  getFaceParamCoord(p2, f, p2_uv);

  double v01_u = p1_uv[0] - p0_uv[0];
  double v01_v = p1_uv[1] - p0_uv[1];
  double v02_u = p2_uv[0] - p0_uv[0];
  double v02_v = p2_uv[1] - p0_uv[1];
  double v01_x = f->J()[0] * v01_u + f->J()[3] * v01_v;
  double v01_y = f->J()[1] * v01_u + f->J()[4] * v01_v;
  double v01_z = f->J()[2] * v01_u + f->J()[5] * v01_v;
  double v02_x = f->J()[0] * v02_u + f->J()[3] * v02_v;
  double v02_y = f->J()[1] * v02_u + f->J()[4] * v02_v;
  double v02_z = f->J()[2] * v02_u + f->J()[5] * v02_v;
  double dot = v01_x * v02_x + v01_y * v02_y + v01_z * v02_z;
  double cross =
    f->sqrt_det() * robustPredicates::orient2d(p0_uv, p1_uv, p2_uv);
  double angle = atan2(cross, dot);
  return angle;
}

double highOrderPolyMesh::computeIntrinsicAngle(geodesic::SurfacePoint &p0,
                                                geodesic::SurfacePoint &p1,
                                                geodesic::SurfacePoint &p2)
{
  if(p0.type() == geodesic::FACE) {
    geodesic::Face *f = static_cast<geodesic::Face *>(p0.base_element());
    double angle = computeAngleOnFace(p0, p1, p2, f);
    if(angle < 0.0) angle += 2 * M_PI;
    return angle;
  }

  if(p0.type() == geodesic::EDGE) {
    geodesic::Edge *e = static_cast<geodesic::Edge *>(p0.base_element());
    geodesic::Face *fs[2] = {e->adjacent_faces()[0], e->adjacent_faces()[1]};

    geodesic::Face *f = (onFace(p1, fs[0])) ? fs[0] : fs[1];
    geodesic::SurfacePoint sp(e->v0());
    double angle = computeAngleOnFace(p0, p1, sp, f);
    f = (onFace(p2, fs[0])) ? fs[0] : fs[1];
    angle -= computeAngleOnFace(p0, p2, sp, f);
    if(angle < 0.0) angle += 2 * M_PI;
    return angle;
  }

  if(p0.type() == geodesic::VERTEX) {
    geodesic::Face *f1 = nullptr, *f2 = nullptr;
    geodesic::Vertex *v0 = static_cast<geodesic::Vertex *>(p0.base_element()),
                     *v1 = nullptr, *v2 = nullptr;

    auto fcs = p0.base_element()->adjacent_faces();
    for(auto fc : fcs) {
      if(onFace(p1, fc)) f1 = fc;
      if(onFace(p2, fc)) f2 = fc;
    }
    if(!f1) Msg::Error("p0 and p1 not on a same face");
    if(!f2) Msg::Error("p0 and p2 not on a same face");

    int i = 0;
    for(; i < 3; ++i) {
      if(f1->adjacent_vertices()[i] != v0) continue;
      v1 = f1->adjacent_vertices()[(i + 1) % 3];
      v2 = f1->adjacent_vertices()[(i + 2) % 3];
      break;
    }
    if(i == 3) Msg::Error("Not right i");

    if(f1 == f2) {
      double angle = computeAngleOnFace(p0, p1, p2, f1);
      if(angle < 0.0) angle += 2 * M_PI;
      if(angle < M_PI) { return angle; }
    }

    geodesic::SurfacePoint sp(v2);
    double angle = computeAngleOnFace(p0, p1, sp, f1);
    if(angle < 0.0) angle += 2 * M_PI;
    geodesic::Face *f = f1;
    geodesic::Edge *e;
    do {
      e = f->opposite_edge(v1);
      f = e->opposite_face(f);
      for(int i = 0; i < 3; ++i) {
        if(f->adjacent_vertices()[i] != v0) continue;
        v1 = f->adjacent_vertices()[(i + 1) % 3];
        v2 = f->adjacent_vertices()[(i + 2) % 3];
        if(f != f2) angle += f->corner_angles()[i];
        break;
      }
    } while(f != f2);

    sp = geodesic::SurfacePoint(v1);
    double tmp = computeAngleOnFace(p0, sp, p2, f);
    if(tmp < 0.0) tmp += 2 * M_PI;
    angle += tmp;
    return angle;
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
      pv2sp[pv->id()] = _s;
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
      pv2sp[pm->vertices.size() - 1] = _s;
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
      pv2sp[pm->vertices.size() - 1] = _s;
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
      pv2sp[pv->id()] = _s;
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
      pv2sp[pm->vertices.size() - 1] = _s;
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
      pv2sp[pm->vertices.size() - 1] = _s;
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
void highOrderPolyMesh::printVertex(const char *fn, int i0)
{
  FILE *f = fopen(fn, "w");
  fprintf(f, "View \"\"{\n");
  geodesic::SurfacePoint sp = pointsPool[i0];
  fprintf(f, "SP(%g,%g,%g){%d};\n", sp.x(), sp.y(), sp.z(), i0);
  fprintf(f, "};\n");
  fclose(f);
}

void highOrderPolyMesh::printGeodesic(const char *fn, int i0, int i1)
{
  FILE *f = fopen(fn, "w");
  fprintf(f, "View \"\"{\n");
  PathView path;
  getGeodesicPath(i0, i1, path);
  fprintf(f, "SP(%g,%g,%g){%d};\n", path.front().x(), path.front().y(),
          path.front().z(), i0);
  fprintf(f, "SP(%g,%g,%g){%d};\n", path.back().x(), path.back().y(),
          path.back().z(), i1);
  for(size_t k = 1; k < path.size(); ++k) {
    fprintf(f, "SL(%g,%g,%g,%g,%g,%g){%d,%d};\n", path[k - 1].x(),
            path[k - 1].y(), path[k - 1].z(), path[k].x(), path[k].y(),
            path[k].z(), i0, i1);
  }
  fprintf(f, "};\n");
  fclose(f);
}

void highOrderPolyMesh::printGeodesics(const char *fn)
{
  FILE *f = fopen(fn, "w");
  fprintf(f, "View \"\"{\n");
  for(size_t i = 0; i < pointsPool.size(); ++i) {
    if(pointsPool.type(i) == PointType::Unused) continue;
    int tag = (pointsPool.type(i) == PointType::Vertex) ? i : 1e5 + i;
    fprintf(f, "SP(%g,%g,%g){%d};\n", pointsPool[i].x(), pointsPool[i].y(),
            pointsPool[i].z(), tag);
  }
  for(size_t i = 0; i < ipm->faces.size(); ++i) {
    auto he = ipm->faces[i]->he;
    if(!he) continue;
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

// CONSTRUCTORS
highOrderPolyMesh::highOrderPolyMesh(PolyMesh *polyMesh,
                                     std::vector<size_t> &tris)
  : maxTag(1)
{
  pm = polyMesh;
  ipm = new PolyMesh(*pm);

  for(int i = 0; i < ipm->hedges.size(); ++i) ipm->hedges[i]->data = i;

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
  auto start = std::chrono::high_resolution_clock::now();
  algorithms[Msg::GetThreadNum()].propagateAStar(pts_start, 0, &pts_end);
  auto end = std::chrono::high_resolution_clock::now();
  timer_geodesic_propagation += end - start;
#else
  algorithms[Msg::GetThreadNum()].propagate(pts_start, 0, &pts_end);
#endif

  paths.clear();
  paths.resize(pts_end.size());
  for(size_t j = 0; j < pts_end.size(); j++) {
    std::vector<geodesic::SurfacePoint> path;
    auto start = std::chrono::high_resolution_clock::now();
    algorithms[Msg::GetThreadNum()].trace_back(pts_end[j], path);
    auto end = std::chrono::high_resolution_clock::now();
    timer_geodesic_trace_back += end - start;
    if(path.empty()) {
      Msg::Info("propagation did not go far enough, widening the search");
#if ASTAR
      auto start = std::chrono::high_resolution_clock::now();

      algorithms[Msg::GetThreadNum()].propagateAStar(pts_start, 1.e22,
                                                     &pts_end);
      auto end = std::chrono::high_resolution_clock::now();
      timer_geodesic_propagation += end - start;

#else
      algorithms[Msg::GetThreadNum()].propagate(pts_start, 1.e22, &pts_end);
#endif
      start = std::chrono::high_resolution_clock::now();
      algorithms[Msg::GetThreadNum()].trace_back(pts_end[j], path);
      end = std::chrono::high_resolution_clock::now();
      timer_geodesic_trace_back += end - start;

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
    }
  }

  for(auto g : __geodesics) {
    for(auto it = g.begin(); it != g.end(); ++it) {
      setGeodesic(it->first, it->second);
    }
  }
}

void highOrderPolyMesh::createInitialGeodesics()
{
  std::vector<geodesic::SurfacePoint> path;
  for(auto he : ipm->hedges) {
    std::pair<int, int> e = {he->v->data, he->next->v->data};
    path = {pointsPool[e.first], pointsPool[e.second]};
    setGeodesic(e, path);
  }
}

void highOrderPolyMesh::createGeodesics()
{
  std::vector<std::pair<int, int>> eds;
  for(auto he : ipm->hedges) {
    std::pair<int, int> e = {he->v->data, he->next->v->data};
    if(e.first > e.second) std::swap(e.first, e.second);
    auto it = std::find(eds.begin(), eds.end(), e);
    if(it == eds.end()) eds.push_back(e);
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

void highOrderPolyMesh::getPath(PolyMesh::HalfEdge *he, PathView &path)
{
  if(he->opposite)
    getGeodesicPath(he->v->data, he->next->v->data, path);
  else
    getBoundaryPath(he->v->data, he->next->v->data, path);
}
void highOrderPolyMesh::getPath(std::pair<int, int> edge, PathView &path)
{
  getGeodesicPath(edge.first, edge.second, path);
}
// END GET GEODESIC PATH

// CREATE CIRCUMCENTER
void highOrderPolyMesh::createCircumcenter(
  std::vector<geodesic::SurfacePoint> &pts,
  geodesic::SurfacePoint &circumcenter, double &circumradius)
{
  auto start = std::chrono::high_resolution_clock::now();
  algorithms[Msg::GetThreadNum()].propagateToCircumcenter(
    pts, 0.0, circumcenter, circumradius);
  auto end = std::chrono::high_resolution_clock::now();
  timer_circumcenter += end - start;
  if(circumcenter.type() == geodesic::UNDEFINED_POINT) {
    if(WARNING) Msg::Warning(("Could not find circumcenter"));
    circumradius = geodesic::GEODESIC_INF;
  }
  if(isnan(circumradius)) Msg::Error("The computed circumradius is NaN");
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
      Msg::Error("The circumcenter does not exist");
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
inline void getSegmentFaces(geodesic::SurfacePoint &sp0,
                            geodesic::SurfacePoint &sp1,
                            std::array<geodesic::Face *, 2> &faces)
{
  faces = {nullptr, nullptr};
  auto base0 = sp0.base_element();
  auto base1 = sp1.base_element();
  if(sp0.type() == geodesic::FACE) {
    faces[0] = static_cast<geodesic::Face *>(base0);
    return;
  }
  if(sp1.type() == geodesic::FACE) {
    faces[0] = static_cast<geodesic::Face *>(base1);
    return;
  }

  auto &adj0 = base0->adjacent_faces();
  auto &adj1 = base1->adjacent_faces();
  int found = 0;
  auto it0 = adj0.begin();
  auto it1 = adj1.begin();

  while(it0 != adj0.end() && it1 != adj1.end() && found < 2) {
    if(*it0 == *it1) {
      faces[found++] = *it0;
      ++it0;
      ++it1;
    }
    else if(*it0 < *it1) {
      ++it0;
    }
    else {
      ++it1;
    }
  }
}

// static void getFacesForSegment(geodesic::SurfacePoint &sp0,
//                                geodesic::SurfacePoint &sp1,
//                                std::array<geodesic::Face *, 2> &faces)
// {
//   faces = {nullptr, nullptr};
//   if(sp0.type() == geodesic::FACE) {
//     faces[0] = static_cast<geodesic::Face *>(sp0.base_element());
//     return;
//   }
//   if(sp1.type() == geodesic::FACE) {
//     faces[0] = static_cast<geodesic::Face *>(sp1.base_element());
//     return;
//   }
//   for(auto f : sp0.base_element()->adjacent_faces()) {
//     auto &sp1Faces = sp1.base_element()->adjacent_faces();
//     auto it = std::find(sp1Faces.begin(), sp1Faces.end(), f);
//     if(it != sp1Faces.end()) {
//       if(faces[0] == nullptr)
//         faces[0] = f;
//       else
//         faces[1] = f;
//     }
//   }
// }

inline bool intersect(double P0[2], double P1[2], double S0[2], double S1[2],
                      bool excludeP0, bool excludeP1, bool excludeS0,
                      bool excludeS1)
{
  double o0 = robustPredicates::orient2d(S0, S1, P0);
  double o1 = robustPredicates::orient2d(S0, S1, P1);
  double o2 = robustPredicates::orient2d(P0, P1, S0);
  double o3 = robustPredicates::orient2d(P0, P1, S1);

  // Colinear case
  if(o0 == 0. && o1 == 0 && o2 == 0. && o3 == 0.) {
    int i = (P0[0] == P1[0]) ? 1 : 0;
    if(P1[i] < P0[i]) {
      std::swap(P0, P1);
      std::swap(excludeP0, excludeP1);
    }
    if(S1[i] < S0[i]) {
      std::swap(S0, S1);
      std::swap(excludeS0, excludeS1);
    }
    if(S0[i] < P0[i]) {
      std::swap(S0, P0);
      std::swap(excludeS0, excludeP0);
      std::swap(S1, P1);
      std::swap(excludeS1, excludeP1);
    }

    if(P1[i] < S0[i]) return false;
    if(P1[i] == S0[i] && excludeP1 && excludeS0) return false;
    return true;
  }

  // Exclude Endpoints
  if((o0 == 0. && excludeP0) || (o1 == 0 && excludeP1)) {
    if((o2 == 0. && excludeS0) || (o3 == 0 && excludeS1)) return false;
  }

  // General Case
  if(o0 * o1 > 0. || o2 * o3 > 0.) return false;
  return true;
}

bool highOrderPolyMesh::intersectGeodesicPath(PathView &p0, PathView &p1)
{
  std::array<geodesic::Face *, 2> faces;
  size_t size0 = p0.size(), size1 = p1.size();

  // Memoization of last p0 argument
  if(p0 != cachedIntersectionPath) {
    cachedIntersectionVertices.clear();
    cachedIntersectionFaces.clear();
    for(size_t i = 1; i < size0; ++i) {
      geodesic::SurfacePoint &start = p0[i - 1], &end = p0[i];

      if(start.type() == geodesic::VERTEX && i > 1) {
        cachedIntersectionVertices.push_back(
          static_cast<geodesic::Vertex *>(start.base_element()));
      }

      getSegmentFaces(start, end, faces);
      cachedIntersectionFaces[faces[0]] = i;
      if(faces[1]) cachedIntersectionFaces[faces[1]] = i;
    }
    cachedIntersectionPath = p0;
  }

  for(size_t j = 1; j < size1; ++j) {
    geodesic::SurfacePoint &start = p1[j - 1], &end = p1[j];

    // Check intersection through vertices
    if(start.type() == geodesic::VERTEX && j > 1) {
      geodesic::Vertex *v =
        static_cast<geodesic::Vertex *>(start.base_element());
      for(geodesic::Vertex *w : cachedIntersectionVertices) {
        if(v == w) return true;
      }
    }

    // Check intersection on faces
    getSegmentFaces(start, end, faces);
    for(geodesic::Face *face : faces) {
      if(!face) continue;
      auto it = cachedIntersectionFaces.find(face);
      if(it != cachedIntersectionFaces.end()) {
        size_t i = it->second;
        double P0[2], P1[2], S0[2], S1[2];
        getFaceParamCoord(p0[i - 1], face, P0);
        getFaceParamCoord(p0[i], face, P1);
        getFaceParamCoord(start, face, S0);
        getFaceParamCoord(end, face, S1);
        if(intersect(P0, P1, S0, S1, i == 1, i + 1 == size0, j == 1,
                     j + 1 == size1))
          return true;
      }
    }
  }
  return false;
}

bool highOrderPolyMesh::intersectNewEdges(
  std::vector<std::pair<size_t, size_t>> &newEdges,
  std::vector<std::pair<size_t, size_t>> &borderEdges)
{
  std::vector<PathView> newPaths(newEdges.size()),
    borderPaths(borderEdges.size());
  for(int i = 0; i < newEdges.size(); ++i) getPath(newEdges[i], newPaths[i]);
  for(int i = 0; i < borderEdges.size(); ++i)
    getPath(borderEdges[i], borderPaths[i]);

  for(int i = 0; i < newPaths.size(); ++i) {
    for(int j = 0; j < borderPaths.size(); ++j) {
      if(intersectGeodesicPath(newPaths[i], borderPaths[j])) {
        // if(WARNING) Msg::Warning("Intersection between new path and
        // border!");
        return true;
      }
    }
    for(int j = 0; j < i; ++j) {
      if(intersectGeodesicPath(newPaths[i], newPaths[j])) {
        // if(WARNING) Msg::Warning("Intersection between new paths !");
        return true;
      }
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
    std::swap(e.first, e.second);
    it = geodesics.find(e);
    if(it != geodesics.end()) geodesics.erase(e);
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

double highOrderPolyMesh::length(std::vector<geodesic::SurfacePoint> *path)
{
  PathView view(*path);
  return length(view);
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

double highOrderPolyMesh::length(std::pair<int, int> edge)
{
  PathView path;
  getGeodesicPath(edge.first, edge.second, path);
  double l = length(path);
  return l;
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
  bool heuristic, bool split_if_cant_swap)
{
  if(!he->opposite)
    Msg::Error("In swapEdge: halfedge %d %d has no opposite halfedge",
               he->v->data, he->next->v->data);
  PolyMesh::HalfEdge *ohe = he->opposite;
  std::pair<int, int> edge = {he->v->data, ohe->v->data},
                      oppEdge = {he->next->next->v->data,
                                 ohe->next->next->v->data};

  if(!doWeSwap(edge, oppEdge, heuristic)) return false;

  bool canSwap = canWeSwap(edge, oppEdge);

  double q = getEdgeQuality(oppEdge);
  if(q < 0.) canSwap = false;

  if(!canSwap) {
    if(WARNING)
      Msg::Warning("Should be swapped but could not: %d %d", edge.first,
                   edge.second);

    if(split_if_cant_swap) {
      std::vector<HEdgeItem> removedEdges, adjacentEdgeItems;
      // Try split edge
      if(splitEdge(he, removedEdges, adjacentEdgeItems, false)) {
        adjacentEdges.clear();
        for(auto kv : adjacentEdgeItems) adjacentEdges.push_back(kv.he);
        return true;
      }

      // Try split border edges
      PolyMesh::HalfEdge *hes[4] = {
        he->next, he->next->next, he->opposite->next, he->opposite->next->next};
      adjacentEdges.clear();
      bool s0 = splitEdge(hes[0], removedEdges, adjacentEdgeItems, false);
      if(s0) {
        for(auto kv : adjacentEdgeItems) adjacentEdges.push_back(kv.he);
      }
      bool s1 = splitEdge(hes[1], removedEdges, adjacentEdgeItems, false);
      if(s1) {
        for(auto kv : adjacentEdgeItems) adjacentEdges.push_back(kv.he);
      }
      bool s2 = splitEdge(hes[2], removedEdges, adjacentEdgeItems, false);
      if(s2) {
        for(auto kv : adjacentEdgeItems) adjacentEdges.push_back(kv.he);
      }
      bool s3 = splitEdge(hes[3], removedEdges, adjacentEdgeItems, false);
      if(s3) {
        for(auto kv : adjacentEdgeItems) adjacentEdges.push_back(kv.he);
      }
      if(s0 || s1 || s2 || s3) return true;

      if(WARNING)
        Msg::Warning("Could not split an edge that should be swapped");
    }

    return false;
  }

  doSwapEdge(he);

  adjacentEdges.clear();
  adjacentEdges.push_back(he->next);
  adjacentEdges.push_back(he->next->next);
  adjacentEdges.push_back(ohe->next);
  adjacentEdges.push_back(ohe->next->next);

  return true;
}

void highOrderPolyMesh::doSwapEdge(PolyMesh::HalfEdge *he)
{
  if(ipm->swap_edge(he)) Msg::Error("Could not swap pm");
}

//         / \
//  b[3] /     \ b[2]
//     /         \
//     ---- e ----
//     \         /
//  b[0] \     / b[1]
//         \ /
//
bool highOrderPolyMesh::doWeSwapAngleHeuristic(std::pair<int, int> &edge,
                                               std::pair<int, int> &oppEdge)
{
  PathView borders[4];
  getGeodesicPath(edge.first, oppEdge.second, borders[0]);
  getGeodesicPath(oppEdge.second, edge.second, borders[1]);
  getGeodesicPath(edge.second, oppEdge.first, borders[2]);
  getGeodesicPath(oppEdge.first, edge.first, borders[3]);

  double before = computeIntrinsicAngle(borders[3], borders[2]) +
                  computeIntrinsicAngle(borders[1], borders[0]);
  double after = computeIntrinsicAngle(borders[0], borders[3]) +
                 computeIntrinsicAngle(borders[2], borders[1]);

  if(abs(before - after) < 1e-6) {
    return std::min(edge.first, edge.second) >
           std::min(oppEdge.first, oppEdge.second);
  }
  return before > after;
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

bool highOrderPolyMesh::canWeSwap(std::pair<int, int> &edge,
                                  std::pair<int, int> &oppEdge)
{
  PathView p01, p23;
  getGeodesicPath(edge.first, edge.second, p01);
  getGeodesicPath(oppEdge.first, oppEdge.second, p23);
  if(!intersectGeodesicPath(p23, p01)) return false;

  std::vector<std::pair<size_t, size_t>> newEdges = {oppEdge}, borderEdges(4);
  borderEdges[0] = {edge.first, oppEdge.second};
  borderEdges[1] = {oppEdge.second, edge.second};
  borderEdges[2] = {edge.second, oppEdge.first};
  borderEdges[3] = {oppEdge.first, edge.first};
  if(intersectNewEdges(newEdges, borderEdges)) return false;

  return true;
}

bool highOrderPolyMesh::checkNewTriangles(std::vector<size_t> newTris)
{
  std::vector<std::pair<size_t, size_t>> edgesToCheck;
  for(int i = 0; i < newTris.size() / 3; ++i) {
    for(int j = 0; j < 3; ++j) {
      std::pair<size_t, size_t> e = {newTris[3 * i + j],
                                     newTris[3 * i + (j + 1) % 3]};
      if(e.first > e.second) std::swap(e.first, e.second);
      auto it = std::find(edgesToCheck.begin(), edgesToCheck.end(), e);
      if(it == edgesToCheck.end()) edgesToCheck.push_back(e);
    }
  }

  std::vector<std::pair<size_t, size_t>> borderEdges;
  if(intersectNewEdges(edgesToCheck, borderEdges)) {
    // Msg::Warning("Intersection between new triangles");
    return false;
  }

  return true;
}

double highOrderPolyMesh::getQuality(std::vector<size_t> &triangles)
{
  double quality = 1.;

  // Edge Quality
  if(edgeQualityPtr != nullptr) {
    std::vector<std::pair<size_t, size_t>> borderEdges, innerEdges;
    getBorder(triangles, borderEdges, innerEdges);
    for(int j = 0; j < innerEdges.size(); ++j) {
      double q = getEdgeQuality(innerEdges[j]);
      if(q < quality) quality = q;
    }
  }

  // Triangle Quality
  if(triangleQualityPtr != nullptr) {
    for(int j = 0; j < triangles.size() / 3; ++j) {
      size_t *is = &triangles[3 * j];
      size_t tri[3] = {is[0], is[1], is[2]};
      double q = getTriangleQuality(tri);
      if(q < quality) quality = q;
    }
  }

  return quality;
}

void highOrderPolyMesh::getBorder(
  std::vector<size_t> &triangles,
  std::vector<std::pair<size_t, size_t>> &borderEdges,
  std::vector<std::pair<size_t, size_t>> &innerEdges)
{
  borderEdges.clear();
  innerEdges.clear();
  for(size_t i = 0; i < triangles.size(); i += 3) {
    size_t *is = &triangles[i];
    for(int j = 0; j < 3; ++j) {
      std::pair<size_t, size_t> o = {is[(j + 1) % 3], is[j]};
      auto it = std::find(borderEdges.begin(), borderEdges.end(), o);
      if(it != borderEdges.end()) {
        borderEdges.erase(it);
        innerEdges.push_back(o);
      }
      else
        borderEdges.push_back({is[j], is[(j + 1) % 3]});
    }
  }
}

inline bool highOrderPolyMesh::doWeSwap(std::pair<int, int> &edge,
                                        std::pair<int, int> &opp,
                                        bool heuristic)
{
  if(heuristic) {
    if(!doWeSwapAngleHeuristic(edge, opp)) return false;
  }
  else {
    if(!doWeSwapIntrinsic(edge, opp)) return false;
  }
  return true;
}

bool highOrderPolyMesh::doWeSwapIntrinsic(std::pair<int, int> &edge,
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
  return false;
}

int highOrderPolyMesh::swapEdges(bool heuristic, bool split_if_cant_swap)
{
  std::vector<PolyMesh::HalfEdge *> set;
  std::vector<bool> updated(ipm->hedges.size(), true);
  for(auto he : ipm->hedges) {
    if(!he->opposite) continue;
    set.push_back(he);
  }

  size_t count = 0, iter = 0;
  while(!set.empty()) {
    if(++iter % PRINT_STEP_SWAP == 0) {
      Msg::Info("\tAlready swapped %d edges (%d triangles, queue "
                "size = %d)",
                count, ipm->faces.size(), set.size());
    }

    PolyMesh::HalfEdge *he = set.back();
    set.pop_back();

    if(!updated[he->data]) continue;
    updated[he->data] = false;

    std::vector<PolyMesh::HalfEdge *> adjacentEdges;
    if(!swapEdge(he, adjacentEdges, heuristic, split_if_cant_swap)) continue;
    ++count;

    if(updated.size() < ipm->hedges.size())
      updated.resize(ipm->hedges.capacity(), true);
    for(auto he : adjacentEdges) {
      if(!he->opposite) continue;
      set.push_back(he);
      updated[he->data] = true;
    }
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
bool highOrderPolyMesh::splitEdge(PolyMesh::HalfEdge *he,
                                  std::vector<HEdgeItem> &removedEdges,
                                  std::vector<HEdgeItem> &adjacentEdges,
                                  bool check_quality)
{
  size_t nPointBefore = pointsPool.size();
  std::pair<int, int> edge = {he->v->data, he->next->v->data};

  // Compute new point
  PathView edgePath;
  std::vector<geodesic::SurfacePoint> firstHalf, secondHalf;
  getPath(edge, edgePath);
  double edgeLength = length(edge), halfLength = .5 * edgeLength;
  splitPath(edgePath, halfLength, firstHalf, secondHalf);

  int mid = pointsPool.size();
  pointsPool.push_back(firstHalf.back());

  PolyMesh::HalfEdge *ohe = he->opposite;
  std::vector<size_t> cavity, newTriangles;
  cavity.push_back(he->f->data);
  if(ohe) cavity.push_back(ohe->f->data);
  size_t is[4];
  int N = 4;
  is[0] = he->v->data;
  is[1] = he->next->v->data;
  is[2] = he->next->next->v->data;
  if(ohe)
    is[3] = ohe->next->next->v->data;
  else
    N = 3;
  newTriangles.push_back(mid);
  newTriangles.push_back(is[2]);
  newTriangles.push_back(is[0]);
  newTriangles.push_back(mid);
  newTriangles.push_back(is[1]);
  newTriangles.push_back(is[2]);
  if(ohe) {
    newTriangles.push_back(mid);
    newTriangles.push_back(is[3]);
    newTriangles.push_back(is[1]);
    newTriangles.push_back(mid);
    newTriangles.push_back(is[0]);
    newTriangles.push_back(is[3]);
  }

  geodesic::SurfacePoint &pt_start = pointsPool[mid];
  std::vector<geodesic::SurfacePoint> pts_end;
  for(int j = 0; j < N; ++j) pts_end.push_back(pointsPool[is[j]]);
  std::vector<std::vector<geodesic::SurfacePoint>> paths;
  createGeodesics(pt_start, pts_end, paths);
  for(int j = 0; j < N; ++j) setGeodesic({is[j], mid}, paths[j]);

  std::vector<std::pair<size_t, size_t>> newEdges(N), borderEdges(N);
  for(int j = 0; j < N; ++j) newEdges[j] = {mid, is[j]};
  borderEdges[0] = {is[1], is[2]};
  borderEdges[1] = {is[2], is[0]};
  if(N == 3)
    borderEdges.pop_back();
  else {
    borderEdges[2] = {is[0], is[3]};
    borderEdges[3] = {is[3], is[1]};
  }

  if(intersectNewEdges(newEdges, borderEdges)) {
    if(WARNING)
      Msg::Warning("Could not split edge %d %d: new geodesic intersects "
                   "(themself or with border)",
                   edge.first, edge.second);
    pointsPool.remove(mid);
    return false;
  }

  bool result = symbolicSwapEdges(newTriangles, cavity, true, true);
  if(!result) {
    if(WARNING)
      Msg::Warning("Could not split edge %d %d: symbolic swap was not possible",
                   edge.first, edge.second);
    for(int i = nPointBefore; i < pointsPool.size(); ++i) {
      if(pointsPool.type(i) != PointType::Vertex) continue;
      pointsPool.remove(i);
    }
    return false;
  }

  if(check_quality) {
    // Quality
    std::vector<size_t> oldTriangles(cavity.size() * 3);
    for(size_t i = 0; i < cavity.size(); ++i) {
      PolyMesh::HalfEdge *he = ipm->faces[cavity[i]]->he;
      oldTriangles[3 * i] = he->v->data;
      oldTriangles[3 * i + 1] = he->next->v->data;
      oldTriangles[3 * i + 2] = he->next->next->v->data;
    }
    double qualityBefore = getQuality(oldTriangles);

    double qualityAfter = getQuality(newTriangles);

    if(qualityAfter < 0. && qualityAfter - qualityBefore < EPS) {
      if(WARNING)
        Msg::Warning("Could not split edge, the quality deos not improve");
      for(int i = nPointBefore; i < pointsPool.size(); ++i) {
        if(pointsPool.type(i) != PointType::Vertex) continue;
        pointsPool.remove(i);
      }
      return false;
    }
  }

  // Split edge

  removedEdges.clear();
  for(auto t : cavity) {
    auto he = ipm->faces[t]->he;
    for(int j = 0; j < 3; ++j, he = he->next)
      removedEdges.push_back(HEdgeItem(he, length(he)));
  }

  replaceCavity(cavity, newTriangles);

  adjacentEdges.clear();
  for(auto t : cavity) {
    auto he = ipm->faces[t]->he;
    for(int j = 0; j < 3; ++j) {
      adjacentEdges.push_back({he, length(he)});
      he = he->next;
    }
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

bool highOrderPolyMesh::doWeSplit(PolyMesh::HalfEdge *he)
{
  double l = adimLengthMax(he);
  return l > 1.;
}

int highOrderPolyMesh::splitEdges()
{
  int count = 0;
  std::set<HEdgeItem, std::greater<HEdgeItem>> queue;

  for(auto he : ipm->hedges) {
    if(!doWeSplit(he)) continue;
    queue.insert(HEdgeItem(he, length(he)));
  }

  size_t iter = 0;
  while(!queue.empty()) {
    if(++iter % 10000 == 0) {
      Msg::Info("\tAlready splitted %d edges (%d triangles, queue size = %d)",
                count, ipm->faces.size(), queue.size());
    }

    HEdgeItem edgeItem = *queue.begin();
    queue.erase(queue.begin());
    PolyMesh::HalfEdge *he = edgeItem.he;

    std::vector<HEdgeItem> removedEdges, adjacentEdges;
    if(!splitEdge(he, removedEdges, adjacentEdges)) continue;
    ++count;

    for(auto item : removedEdges) {
      auto it = queue.find(item);
      if(it != queue.end()) queue.erase(it);
    }

    for(auto item : adjacentEdges) {
      if(!doWeSplit(item.he)) continue;
      queue.insert(item);
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
                                     std::vector<HEdgeItem> &removedEdgeItems,
                                     std::vector<HEdgeItem> &adjacentEdges)
{
  std::pair<size_t, size_t> edge = {he->v->data, he->next->v->data};

  // The edge can be collapsed into one of three vertices
  constexpr size_t N = 3;
  size_t midIndices[N] = {edge.first, edge.second, pointsPool.size()};

  // Find cavity
  std::vector<size_t> cavity, stack;
  stack.push_back(he->f->data);
  while(!stack.empty()) {
    size_t t = stack.back();
    stack.pop_back();
    cavity.push_back(t);
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
      if(std::find(stack.begin(), stack.end(), of) != stack.end()) continue;
      stack.push_back(of);
    }
  }

  // Check topology
  std::vector<size_t> oldTriangles(3 * cavity.size());
  for(size_t i = 0; i < cavity.size(); ++i) {
    PolyMesh::HalfEdge *he = ipm->faces[cavity[i]]->he;
    for(int j = 0; j < 3; ++j, he = he->next)
      oldTriangles[3 * i + j] = he->v->data;
  }
  std::vector<std::pair<size_t, size_t>> borderEdges, innerEdges;
  getBorder(oldTriangles, borderEdges, innerEdges);
  if(borderEdges.size() + 2 != cavity.size()) return false;
  for(int i = 0; i < borderEdges.size(); ++i) {
    for(int j = i + 1; j < borderEdges.size(); ++j) {
      if(borderEdges[i].first == borderEdges[j].first) return false;
      if(borderEdges[i].second == borderEdges[j].second) return false;
    }
  }

  // Insert mid point
  PathView path;
  std::vector<geodesic::SurfacePoint> firstHalf, secondHalf;
  getPath(he, path);
  splitPath(path, .5 * length(path), firstHalf, secondHalf);
  pointsPool.push_back(firstHalf.back());

  // Find the best vertex to collapse the edge into
  bool doCollapseArray[N];
  double qualityArray[N];
  std::vector<size_t> newTrianglesArray[N];
  std::vector<size_t> cavityArray[N];
  for(size_t i = 0; i < N; ++i) {
    doCollapseArray[i] = true;
    qualityArray[i] = 1.;
    newTrianglesArray[i] = {};
    cavityArray[i] = cavity;
  }

  for(size_t i = 0; i < N; ++i) {
    auto &midIndex = midIndices[i];
    std::vector<size_t> &newTriangles = newTrianglesArray[i];
    std::vector<size_t> &cavity = cavityArray[i];

    std::vector<std::pair<size_t, size_t>> newEdges(borderEdges.size());
    for(int j = 0; j < borderEdges.size(); ++j)
      newEdges[j] = {midIndex, borderEdges[j].first};
    if(intersectNewEdges(newEdges, borderEdges)) {
      doCollapseArray[i] = false;
      continue;
    }

    newTriangles.resize(3 * borderEdges.size());
    for(int j = 0; j < borderEdges.size(); ++j) {
      newTriangles[3 * j] = borderEdges[j].first;
      newTriangles[3 * j + 1] = borderEdges[j].second;
      newTriangles[3 * j + 2] = midIndex;
    }
    bool result = symbolicSwapEdges(newTriangles, cavity, true, false);
    if(!result) {
      doCollapseArray[i] = false;
      continue;
    }

    // Qualities
    std::vector<size_t> oldTriangles(cavity.size() * 3);
    for(size_t i = 0; i < cavity.size(); ++i) {
      PolyMesh::HalfEdge *he = ipm->faces[cavity[i]]->he;
      oldTriangles[3 * i] = he->v->data;
      oldTriangles[3 * i + 1] = he->next->v->data;
      oldTriangles[3 * i + 2] = he->next->next->v->data;
    }
    double qualityBefore = getQuality(oldTriangles);

    double qualityAfter = getQuality(newTriangles);

    qualityArray[i] = qualityAfter - qualityBefore;

    if(qualityAfter < 0. && qualityArray[i] < EPS) {
      doCollapseArray[i] = false;
      continue;
    }
  }

  int i = -1;
  for(int j = 0; j < N; ++j) {
    if(!doCollapseArray[j]) continue;
    if(i == -1 || qualityArray[j] > qualityArray[i]) i = j;
  }
  if(i == -1) {
    removePoint(pointsPool.size() - 1);
    return false;
  }

  // Collapse Edge

  removedEdgeItems.clear();
  for(auto t : cavityArray[i]) {
    auto he = ipm->faces[t]->he;
    for(int j = 0; j < 3; ++j, he = he->next)
      removedEdgeItems.push_back(HEdgeItem(he, length(he)));
  }

  doCollapseEdge(edge, midIndices[i], cavityArray[i], newTrianglesArray[i]);

  std::vector<PolyMesh::Vertex *> adjacentVertices;
  for(size_t t : cavityArray[i]) {
    PolyMesh::HalfEdge *he = ipm->faces[t]->he;
    for(int j = 0; j < 3; ++j, he = he->next) {
      auto it =
        std::find(adjacentVertices.begin(), adjacentVertices.end(), he->v);
      if(it == adjacentVertices.end()) adjacentVertices.push_back(he->v);
    }
  }

  std::vector<PolyMesh::HalfEdge *> adjacentHEdges;
  for(PolyMesh::Vertex *v : adjacentVertices) {
    PolyMesh::HalfEdge *he = v->he;
    do {
      auto it = std::find(adjacentHEdges.begin(), adjacentHEdges.end(), he);
      if(it == adjacentHEdges.end()) {
        if(he->opposite) {
          it = std::find(adjacentHEdges.begin(), adjacentHEdges.end(),
                         he->opposite);
          if(it == adjacentHEdges.end()) adjacentHEdges.push_back(he);
        }
        else
          adjacentHEdges.push_back(he);
      }

      if(he->opposite)
        he = he->opposite->next;
      else {
        he = he->next->next;
        while(he->opposite) he = he->opposite->next->next;
        he = he->next;
      }
    } while(he != v->he);
  }

  adjacentEdges.clear();
  adjacentEdges.reserve(adjacentHEdges.size());
  for(PolyMesh::HalfEdge *he : adjacentHEdges)
    adjacentEdges.push_back(HEdgeItem(he, length(he)));

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

inline void highOrderPolyMesh::doCollapseEdge(std::pair<size_t, size_t> &edge,
                                              size_t index,
                                              std::vector<size_t> &cavity,
                                              std::vector<size_t> &newTris)
{
  // Remove points
  if(index != edge.first) { removePoint(edge.first); }
  if(index != edge.second) { removePoint(edge.second); }
  if(index != pointsPool.size() - 1) { removePoint(pointsPool.size() - 1); }

  replaceCavity(cavity, newTris);
}

void highOrderPolyMesh::cleanAfterCollapse()
{
  // Circumcircles
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
      Msg::Error("Circumcenter is a removed point");
    if(it.second.first >= pointsPool.size())
      Msg::Error("Circumcenter is outside of the points array");
  }

  // Points
  std::unordered_map<size_t, size_t> old2New;
  size_t front = 0, back = pointsPool.size() - 1;
  for(; front <= back; ++front) {
    if(pointsPool.type(front) != PointType::Unused) continue;

    while(pointsPool.type(back) == PointType::Unused && back != front) --back;
    if(back == front) { break; }

    old2New[back] = front;
    old2New[front] = back;
    pointsPool.swap(front, back);
  }
  pointsPool.resize(front);

  // Triangles
  std::unordered_map<int, int> old2NewTriangle;
  front = 0;
  back = ipm->faces.size() - 1;
  for(; front <= back; ++front) {
    if(ipm->faces[front]->he != nullptr) continue;

    while(ipm->faces[back]->he == nullptr && back != front) { --back; }
    if(back == front) { break; }

    PolyMesh::Face *ffront = ipm->faces[front], *fback = ipm->faces[back];
    std::swap(ffront->he, fback->he);

    ffront->he->f = ffront;
    ffront->he->next->f = ffront;
    ffront->he->next->next->f = ffront;
  }
  for(auto v : ipm->vertices) {
    if(old2New.find(v->data) == old2New.end()) continue;
    v->data = old2New[v->data];
  }
  ipm->clean();
  for(int i = 0; i < ipm->hedges.size(); ++i) ipm->hedges[i]->data = i;

  // Geodesics
  std::vector<std::pair<int, int>> toInsertEdge;
  std::vector<std::vector<geodesic::SurfacePoint>> toInsertGeo;
  for(auto it = geodesics.begin(); it != geodesics.end();) {
    const std::pair<int, int> &edge = it->first;
    auto itfirst = old2New.find(edge.first);
    auto itsecond = old2New.find(edge.second);
    if(itfirst == old2New.end() && itsecond == old2New.end()) {
      if(edge.first < pointsPool.size() && edge.second < pointsPool.size()) {
        ++it;
      }
      else {
        it = geodesics.erase(it);
      }
      continue;
    }
    std::pair<int, int> newEdge = edge;
    if(itfirst != old2New.end()) newEdge.first = itfirst->second;
    if(itsecond != old2New.end()) newEdge.second = itsecond->second;

    if(newEdge.first < pointsPool.size() &&
       newEdge.second < pointsPool.size()) {
      toInsertEdge.push_back(newEdge);
      toInsertGeo.push_back(it->second);
    }
    it = geodesics.erase(it);
  }
  for(size_t i = 0; i < toInsertEdge.size(); ++i) {
    geodesics.emplace(toInsertEdge[i], std::move(toInsertGeo[i]));
  }

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

  // VertexInfos
  std::vector<int> toIEvg;
  std::vector<std::pair<int, int>> toIGvg;
  vertexGeodesics.clear();
  vertexGeodesics.resize(pointsPool.size(),
                         std::vector<std::pair<int, int>>(0));
  for(auto it = geodesics.begin(); it != geodesics.end();) {
    auto &e = it->first;
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

  for(auto it : circumIndexRadius) {
    for(auto t : it.first) {
      if(pointsPool.type(t) == PointType::Unused)
        Msg::Error("Unused point still have circumcenter");
    }
    if(it.second.first >= pointsPool.size())
      Msg::Error("Circumcenter is outside of the points array");
  }
}

bool highOrderPolyMesh::doWeCollapse(PolyMesh::HalfEdge *he)
{
  double l = adimLengthMin(he);
  return l < 1.;
}

int highOrderPolyMesh::collapseEdges()
{
  std::set<HEdgeItem, std::less<HEdgeItem>> queue;
  for(auto he : ipm->hedges) {
    if(!doWeCollapse(he)) continue;
    queue.insert(HEdgeItem(he, length(he)));
  }

  size_t count = 0, iter = 0, removedTriangles = 0;
  while(queue.size()) {
    if(++iter % PRINT_STEP == 0) {
      Msg::Info("\tAlready collapsed %d edges (%d triangles, queue size = %d)",
                count, ipm->faces.size() - removedTriangles, queue.size());
    }

    HEdgeItem item = *queue.begin();
    queue.erase(queue.begin());
    PolyMesh::HalfEdge *he = item.he;

    std::vector<HEdgeItem> adjacentEdges;
    std::vector<HEdgeItem> removedEdges;
    int nbrTriangles = he->opposite ? 2 : 1;
    if(!collapseEdge(he, removedEdges, adjacentEdges)) { continue; }
    ++count;
    removedTriangles += nbrTriangles;

    for(auto item : removedEdges) {
      auto it = queue.find(item);
      if(it != queue.end()) queue.erase(it);
    }

    for(auto item : adjacentEdges) {
      if(!doWeCollapse(item.he)) continue;
      queue.insert(item);
    }
  }

  cleanAfterCollapse();

  return count;
}
// END COLLAPSE EDGE

int highOrderPolyMesh::findTriangleToSplit(int circumindex, int t)
{
  constexpr double eps = 0;
  PathView borderPaths[3], newPaths[3];
  double angles[3];

  size_t counter = 0;
  constexpr size_t MAX_COUNTER = 1e4;
  while(++counter < MAX_COUNTER) {
    auto he = ipm->faces[t]->he;
    for(int j = 0; j < 3; ++j, he = he->next) {
      size_t i0 = he->v->data, i1 = he->next->v->data;
      getGeodesicPath(i0, i1, borderPaths[j]);
      getGeodesicPath(i0, circumindex, newPaths[j]);
    }

    for(int j = 0; j < 3; ++j) {
      angles[j] =
        computeIntrinsicAngle(borderPaths[j], borderPaths[(j + 2) % 3]);
      angles[j] -= computeIntrinsicAngle(newPaths[j], borderPaths[(j + 2) % 3]);
    }

    // Point inside triangle
    if(angles[0] > -eps && angles[1] > -eps && angles[2] > -eps) return t;

    int i = 0;
    for(; i < 3; ++i) { // Find intersection strictly inside opposite edge
      if(intersectGeodesicPath(newPaths[(i + 2) % 3], borderPaths[(i + 1) % 3]))
        continue;
      if(intersectGeodesicPath(newPaths[(i + 2) % 3], borderPaths[(i + 2) % 3]))
        continue;
      if(intersectGeodesicPath(newPaths[(i + 2) % 3], borderPaths[i])) break;
    }

    if(i < 3) { // Follow intersections for C_MAX steps
      constexpr size_t C_MAX = 1e2;
      for(int j = 0; j < i; ++j) he = he->next;
      PathView p;
      size_t c = 0;
      while(++c < C_MAX) {
        if(!he->opposite)
          Msg::Error("Intersection between an edge and the boundary");

        he = he->opposite->next;
        getGeodesicPath(he->v->data, he->next->v->data, p);
        if(intersectGeodesicPath(newPaths[(i + 2) % 3], p)) continue;

        he = he->next;
        getGeodesicPath(he->v->data, he->next->v->data, p);
        if(intersectGeodesicPath(newPaths[(i + 2) % 3], p)) continue;

        break;
      }
      t = he->f->data;
    }
    else { // Randomly choose an adjacent face
      static std::random_device rd;
      static std::mt19937 gen(rd());
      static std::uniform_int_distribution<> distr(0, 2);
      int N = distr(gen);
      for(int j = 0; j < N; ++j) he = he->next;
      if(!he->opposite) Msg::Error("No implementation for boundary triangles");
      t = he->opposite->f->data;
    }
  }

  return -1;
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

bool highOrderPolyMesh::symbolicSwapEdges(std::vector<size_t> &newTriangles,
                                          std::vector<size_t> &cavity,
                                          bool propagate, bool insert)
{
  size_t initNbrPoints = pointsPool.size();
  bool possible = true;

  // Minimal halfedge representation
  TriMesh mesh;
  for(size_t i = 0; i < newTriangles.size(); i += 3)
    mesh.add_face(newTriangles[i], newTriangles[i + 1], newTriangles[i + 2]);

  std::vector<bool> updated(newTriangles.size(), true);
  std::vector<size_t> list;
  for(size_t i = 0; i < mesh.size(); ++i) {
    size_t he = mesh.face_he(i);
    list.push_back(he);
    list.push_back(mesh.next(he));
    list.push_back(mesh.prev(he));
  }

  std::unordered_map<size_t, PolyMesh::Vertex *> id2pv;
  for(auto t : cavity) {
    auto he = ipm->faces[t]->he;
    for(int j = 0; j < 3; ++j) {
      he = he->next;
      id2pv[he->v->data] = he->v;
    }
  }

  constexpr size_t MAX_COUNT = 1e4;
  size_t count = 0;
  while(!list.empty()) {
    size_t he = list.back();
    list.pop_back();

    if(!updated[he]) continue;
    updated[he] = false;

    size_t i0 = mesh.vertex(he), i1 = mesh.vertex(mesh.next(he)),
           i2 = mesh.vertex(mesh.prev(he));

    size_t ohe = mesh.opposite(he);

    if(ohe == TriMesh::NONE && propagate) {
      PolyMesh::HalfEdge *ihe = id2pv[i0]->he;
      do {
        if(ihe->next->v->data == i1) break;
        if(ihe->opposite)
          ihe = ihe->opposite->next;
        else {
          ihe = ihe->next->next;
          while(ihe->opposite) ihe = ihe->opposite->next->next;
          ihe = ihe->next;
        }
      } while(ihe != id2pv[i0]->he);
      if(ihe->next->v->data != i1) {
        Msg::Error("Could not find the edge %d %d", i0, i1);
      }
      if(!ihe->opposite) continue;
      size_t p0 = ihe->v->data;
      size_t p1 = ihe->next->v->data;
      size_t p3 = ihe->opposite->next->next->v->data;
      size_t f103 = ihe->opposite->f->data;
      id2pv[ihe->opposite->next->next->v->data] = ihe->opposite->next->next->v;

      cavity.push_back(f103);

      size_t face = mesh.add_face(p1, p0, p3);
      for(int i = 0; i < 3; ++i) updated.push_back(true);

      ohe = mesh.face_he(face);
    }

    if(ohe == TriMesh::NONE) continue;

    size_t i3 = mesh.vertex(mesh.prev(ohe));

    if(i0 != mesh.vertex(mesh.next(ohe)) || i1 != mesh.vertex(ohe)) {
      Msg::Error("Error in the symbolic representation of the cavity");
    }

    std::pair<int, int> edge = {i0, i1}, oppEdge = {i2, i3};

    if(!doWeSwap(edge, oppEdge, HEURISTIC_SWAP)) { continue; }

    if(!canWeSwap(edge, oppEdge)) {
      if(!insert) {
        possible = false;
        break;
      }

#if SPLIT_IF_CANT_SWAP
      // Try split edge
      double l = length(edge);
      std::vector<geodesic::SurfacePoint> firstHalf, secondHalf;
      PathView p01;
      getGeodesicPath(i0, i1, p01);
      splitPath(p01, .5 * l, firstHalf, secondHalf);
      geodesic::SurfacePoint newSP = firstHalf.back();
      size_t mid = pointsPool.size();
      pointsPool.push_back(newSP);

      std::vector<std::pair<size_t, size_t>> newEdges(4), borderEdges(4);
      newEdges[0] = {mid, edge.first};
      newEdges[1] = {mid, edge.second};
      newEdges[2] = {mid, oppEdge.first};
      newEdges[3] = {mid, oppEdge.second};
      borderEdges[0] = {edge.first, oppEdge.second};
      borderEdges[1] = {oppEdge.second, edge.second};
      borderEdges[2] = {edge.second, oppEdge.first};
      borderEdges[3] = {oppEdge.first, edge.first};
      bool intersect = intersectNewEdges(newEdges, borderEdges);
      if(intersect) {
        possible = false;
        break;
      }

      // Do split edge
      mesh.split(he, mid);
      for(int i = 0; i < 3; ++i) updated.push_back(true);
      if(mesh.opposite(he) != TriMesh::NONE) {
        for(int i = 0; i < 3; ++i) updated.push_back(true);
      }

      size_t add[12] = {he,
                        mesh.next(he),
                        mesh.prev(he),
                        mesh.opposite(he),
                        mesh.next(mesh.opposite(he)),
                        mesh.prev(mesh.opposite(he)),
                        ohe,
                        mesh.next(ohe),
                        mesh.prev(ohe),
                        mesh.opposite(ohe),
                        mesh.next(mesh.opposite(ohe)),
                        mesh.prev(mesh.opposite(ohe))};

      for(size_t i : add) {
        list.push_back(i);
        updated[i] = true;
      }
      continue;
#else
      possible = false;
      break;
#endif
    }

    if(count++ > MAX_COUNT) {
      if(WARNING) Msg::Warning("infinite swaps");
      possible = false;
      break;
    }

    mesh.swap(he);

    size_t add[6] = {he,  mesh.next(he),  mesh.prev(he),
                     ohe, mesh.next(ohe), mesh.prev(ohe)};

    for(size_t i : add) {
      list.push_back(i);
      updated[i] = true;
    }
  }

  if(!possible) {
    for(size_t i = initNbrPoints; i < pointsPool.size(); ++i) {
      pointsPool.remove(i);
    }
    return false;
  }

  // Remove unchanged triangles
  for(auto it = cavity.begin(); it != cavity.end();) {
    bool remove = false;
    auto he = ipm->faces[*it]->he;
    for(size_t i = 0; i < mesh.size(); ++i) {
      size_t fhe = mesh.face_he(i);
      size_t vs[3] = {mesh.vertex(fhe), mesh.vertex(mesh.next(fhe)),
                      mesh.vertex(mesh.prev(fhe))};
      for(int j = 0; j < 3; ++j) {
        if(he->v->data != vs[j]) continue;
        if(he->next->v->data != vs[(j + 1) % 3]) continue;
        if(he->next->next->v->data != vs[(j + 2) % 3]) continue;
        mesh.remove_face(i);
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

  newTriangles.clear();
  for(size_t i = 0; i < mesh.size(); ++i) {
    size_t he = mesh.face_he(i);
    if(mesh.vertex(he) == TriMesh::NONE) continue;
    newTriangles.push_back(mesh.vertex(he));
    newTriangles.push_back(mesh.vertex(mesh.next(he)));
    newTriangles.push_back(mesh.vertex(mesh.prev(he)));
  }

  return true;
}

void highOrderPolyMesh::replaceCavity(std::vector<size_t> &cavity,
                                      std::vector<size_t> &newTris)
{
  std::vector<PolyMesh::HalfEdge *> boundary;
  std::vector<PolyMesh::Face *> fcs;
  std::vector<PolyMesh::HalfEdge *> hdgs;
  std::unordered_map<int, PolyMesh::Vertex *> index2pv;
  for(size_t i = cavity.size() - 1; i + 1 > 0; --i) {
    PolyMesh::Face *f = ipm->faces[cavity[i]];
    fcs.push_back(f);
    PolyMesh::HalfEdge *he = f->he;
    for(int j = 0; j < 3; ++j) {
      he = he->next;
      he->f = nullptr;
      index2pv[he->v->data] = he->v;

      if(!he->opposite) {
        boundary.push_back(he);
        continue;
      }

      auto it = std::find(boundary.begin(), boundary.end(), he->opposite);
      if(it == boundary.end()) {
        boundary.push_back(he);
        continue;
      }

      boundary.erase(it);
      hdgs.push_back(he);
      hdgs.push_back(he->opposite);
    }
  }

  for(auto kv : index2pv) { kv.second->he = nullptr; }
  for(auto he : boundary) { he->v->he = he; }
  for(auto he : boundary) {
    he->next = he->next->v->he;
    if(!he->next) Msg::Error("no next");
  }
  for(auto he : hdgs) he->v = nullptr;
  for(auto f : fcs) f->he = nullptr;

  for(int i = 0; i < newTris.size() / 3; ++i) {
    size_t *is = &(newTris[3 * i]);
    // Vertices
    PolyMesh::Vertex *vs[3] = {nullptr, nullptr, nullptr};
    for(int j = 0; j < 3; ++j) {
      auto it = index2pv.find(is[j]);
      if(it != index2pv.end()) {
        vs[j] = it->second;
        continue;
      }
      // Create vertex if not exist
      vs[j] = new PolyMesh::Vertex(pointsPool[is[j]].x(), pointsPool[is[j]].y(),
                                   pointsPool[is[j]].z(), is[j]);
      ipm->vertices.push_back(vs[j]);
      index2pv[is[j]] = vs[j];
    }

    // HalfEdges
    PolyMesh::HalfEdge *hes[3] = {nullptr, nullptr, nullptr};
    for(int j = 0; j < 3; ++j) {
      // Search in Boundary
      for(auto it = boundary.begin(); it < boundary.end(); ++it) {
        if((*it)->v->data == is[j] &&
           (*it)->opposite->v->data == is[(j + 1) % 3]) {
          hes[j] = (*it);
          boundary.erase(it);
          break;
        }
      }
      if(hes[j]) continue;

      // Create HalfEdge pair
      PolyMesh::HalfEdge *ohe;
      if(hdgs.size() >= 2) {
        hes[j] = hdgs.back();
        hdgs.pop_back();
        ohe = hdgs.back();
        hdgs.pop_back();
      }
      else {
        hes[j] = new PolyMesh::HalfEdge(nullptr);
        ipm->hedges.push_back(hes[j]);
        ohe = new PolyMesh::HalfEdge(nullptr);
        ipm->hedges.push_back(ohe);
        ipm->hedges[ipm->hedges.size() - 2]->data = ipm->hedges.size() - 2;
        ipm->hedges[ipm->hedges.size() - 1]->data = ipm->hedges.size() - 1;
      }
      hes[j]->v = vs[j];
      ohe->v = vs[(j + 1) % 3];
      hes[j]->opposite = ohe;
      ohe->opposite = hes[j];
      boundary.push_back(ohe);
    }

    // Face
    PolyMesh::Face *f;
    if(!fcs.empty()) {
      f = fcs.back();
      fcs.pop_back();
    }
    else {
      f = new PolyMesh::Face(nullptr);
      ipm->faces.push_back(f);
      f->data = ipm->faces.size() - 1;
      cavity.push_back(f->data);
    }
    f->he = hes[0];

    // HalfEdges connectivity
    for(int j = 0; j < 3; ++j) {
      hes[j]->next = hes[(j + 1) % 3];
      hes[j]->f = f;
      hes[j]->v->he = hes[j];
    }
  }
  cavity.resize(newTris.size() / 3);
}

bool highOrderPolyMesh::doSplitTriangle(size_t circumindex,
                                        std::vector<size_t> &cavity,
                                        std::vector<size_t> &newTris)
{
  bool success = pointsPool.convertToVertex(circumindex);

  if(!success) {
    if(WARNING) Msg::Warning("Could not convert circumcenter to vertex");
    return false;
  }

  replaceCavity(cavity, newTris);

  return true;
}

bool highOrderPolyMesh::splitTriangle(
  int iTriangle, std::vector<TriangleItem> removedTriangles,
  std::vector<TriangleItem> &adjacentTriangles)
{
  double radius;
  size_t circumindex;
  getCircumcenter(iTriangle, circumindex, radius);
  geodesic::SurfacePoint sp = pointsPool[circumindex];

  if(radius == geodesic::GEODESIC_INF || radius == -1 ||
     sp.type() == geodesic::UNDEFINED_POINT) {
    if(WARNING)
      Msg::Warning("In splitTriangle: circumcircle could not be found");
    return false;
  }

  if(pointsPool.type(circumindex) != PointType::Circumcenter) {
    if(WARNING) Msg::Warning("The circumcenter is already a vertex or removed");
    return false;
  }

  // Find triangle to split
  int triangleToSplit = findTriangleToSplit(circumindex, iTriangle);
  if(triangleToSplit == -1) {
    if(WARNING) Msg::Warning("Could not find triangle to split");
    return false;
  }

  std::vector<size_t> cavity = {(size_t)triangleToSplit};
  auto he = ipm->faces[triangleToSplit]->he;
  std::vector<size_t> newTriangles = {(size_t)he->v->data,
                                      (size_t)he->next->v->data,
                                      circumindex,
                                      (size_t)he->next->v->data,
                                      (size_t)he->next->next->v->data,
                                      circumindex,
                                      (size_t)he->next->next->v->data,
                                      (size_t)he->v->data,
                                      circumindex};

  std::vector<std::pair<size_t, size_t>> newEdges(3), borderEdges(3);
  for(int i = 0; i < 3; ++i, he = he->next) {
    borderEdges[i] = {he->v->data, he->next->v->data};
    newEdges[i] = {he->v->data, circumindex};
  }

  // Check intersections
  bool intersect = intersectNewEdges(newEdges, borderEdges);
  if(intersect) {
    // Split edge instead of triangle
    int i = 0;
    for(; i < 3; ++i, he = he->next) {
      if(!he->opposite) {
        Msg::Error("No implementation for triangle split on the boundary");
      }
      PolyMesh::HalfEdge *ohe = he->opposite;

      std::pair<int, int> e = {he->v->data, he->next->v->data};
      cavity = {(size_t)he->f->data, (size_t)ohe->f->data};
      size_t is[4] = {(size_t)he->v->data, (size_t)ohe->v->data,
                      (size_t)he->next->next->v->data,
                      (size_t)ohe->next->next->v->data};
      newTriangles = {circumindex, is[2], is[0], circumindex, is[1], is[2],
                      circumindex, is[0], is[3], circumindex, is[3], is[1]};
      newEdges = {{circumindex, is[0]},
                  {circumindex, is[1]},
                  {circumindex, is[2]},
                  {circumindex, is[3]}};
      borderEdges = {
        {is[0], is[3]}, {is[3], is[1]}, {is[1], is[2]}, {is[2], is[0]}};
      intersect = intersectNewEdges(newEdges, borderEdges);
      if(!intersect) break;
    }
    if(i == 3) {
      if(WARNING)
        Msg::Warning("Could not split triangle: intersection between new edges "
                     "and/or border edges");
      return false;
    }
  }

  size_t nPointBefore = pointsPool.size();
  bool result = symbolicSwapEdges(newTriangles, cavity, true, true);
  if(!result) {
    if(WARNING) Msg::Warning("Could not symbolic swap");
    return false;
  }

  auto it = std::find(cavity.begin(), cavity.end(), iTriangle);
  if(it == cavity.end()) {
    if(WARNING) Msg::Warning("Triangle to split is not in the cavity");
    for(int i = nPointBefore; i < pointsPool.size(); ++i) {
      if(pointsPool.type(i) != PointType::Vertex) continue;
      pointsPool.remove(i);
    }
    return false;
  }

  // Compute triangles qualities
  std::vector<size_t> oldTriangles(cavity.size() * 3);
  for(size_t i = 0; i < cavity.size(); ++i) {
    PolyMesh::HalfEdge *he = ipm->faces[cavity[i]]->he;
    oldTriangles[3 * i] = he->v->data;
    oldTriangles[3 * i + 1] = he->next->v->data;
    oldTriangles[3 * i + 2] = he->next->next->v->data;
  }
  double qualityBefore = getQuality(oldTriangles);

  double qualityAfter = getQuality(newTriangles);

  if(qualityAfter < 0. && qualityAfter - qualityBefore < EPS) {
    if(WARNING)
      Msg::Warning("Quality does not improve after splitting the triangle");
    for(int i = nPointBefore; i < pointsPool.size(); ++i) {
      if(pointsPool.type(i) != PointType::Vertex) continue;
      pointsPool.remove(i);
    }
    return false;
  }

  // Split Triangle

  removedTriangles.resize(cavity.size());
  for(size_t i = 0; i < cavity.size(); ++i) {
    PolyMesh::HalfEdge *he = ipm->faces[cavity[i]]->he;
    size_t tri[3] = {(size_t)he->v->data, (size_t)he->next->v->data,
                     (size_t)he->next->next->v->data};
    double q = getTriangleQuality(tri);
    removedTriangles[i] = TriangleItem((int)cavity[i], q);
  }

  bool splitted = doSplitTriangle(circumindex, cavity, newTriangles);
  if(!splitted) { return false; }

  adjacentTriangles.resize(cavity.size());
  for(int i = 0; i < cavity.size(); ++i) {
    PolyMesh::HalfEdge *he = ipm->faces[cavity[i]]->he;
    size_t tri[3] = {(size_t)he->v->data, (size_t)he->next->v->data,
                     (size_t)he->next->next->v->data};
    double q = getTriangleQuality(tri);
    adjacentTriangles[i] = TriangleItem((int)cavity[i], q);
  }

  return true;
}

int highOrderPolyMesh::splitTriangles()
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
  while(!queue.empty()) {
    if(++iter % PRINT_STEP == 0) {
      Msg::Info("\tAlready splitted %d triangles (%d triangles, queue "
                "size = %d)",
                count, ipm->faces.size(), queue.size());
    }

    TriangleItem item = *queue.begin();
    queue.erase(queue.begin());
    std::vector<TriangleItem> removedTriangles, adjacentTriangles;

    if(splitTriangle(item.index, removedTriangles, adjacentTriangles)) {
      ++count;

      for(auto item : removedTriangles) queue.erase(item);

      for(auto item : adjacentTriangles) {
        if(item.quality < 0.) queue.insert(item);
      }
    }
  }

  return count;
}

// END SPLIT TRIANGLE

// CUT MESH

inline void addPP(PolyMesh::Vertex *v, std::vector<PolyMesh::Vertex *> &pp,
                  std::vector<double> &coord, geodesic::Face *f,
                  geodesic::SurfacePoint &sp)
{
  double uv[2];
  getFaceParamCoord(sp, f, uv);
  coord.push_back(uv[0]);
  coord.push_back(uv[1]);
  pp.push_back(v);
}

int triangulate(const std::vector<double> &coord, const size_t offsets[3],
                const std::vector<size_t> *rec, std::vector<std::size_t> &tri)
{
  // Initial Triangulation
  int k = 0;
  for(int j = 0; j < 3; ++j) {
    ++k;
    for(; k < offsets[j]; ++k) {
      tri.push_back(k);
      tri.push_back((k + 1) % offsets[2]);
      tri.push_back((offsets[j] + 1) % offsets[2]);
    }
  }
  tri.push_back(1);
  tri.push_back(offsets[0] + 1);
  tri.push_back((offsets[1] + 1) % offsets[2]);

  PolyMesh *pm = new PolyMesh;

  // Create Vertices
  for(int i = 0; i < offsets[2]; ++i) {
    PolyMesh::Vertex *v =
      new PolyMesh::Vertex(coord[2 * i], coord[2 * i + 1], 0, i + 1);
    pm->vertices.push_back(v);
  }

  // Create Faces
  for(int i = 0; i < tri.size(); i += 3) {
    PolyMesh::Vertex *v0 = pm->vertices[tri[i]];
    PolyMesh::Vertex *v1 = pm->vertices[tri[i + 2]]; // oriented cw
    PolyMesh::Vertex *v2 = pm->vertices[tri[i + 1]];
    PolyMesh::HalfEdge *he0 = new PolyMesh::HalfEdge(v0);
    PolyMesh::HalfEdge *he1 = new PolyMesh::HalfEdge(v1);
    PolyMesh::HalfEdge *he2 = new PolyMesh::HalfEdge(v2);
    PolyMesh::Face *f = new PolyMesh::Face(he0);
    v0->he = he0;
    v1->he = he1;
    v2->he = he2;
    he0->next = he1;
    he1->prev = he0;
    he1->next = he2;
    he2->prev = he1;
    he2->next = he0;
    he0->prev = he2;
    he0->f = he1->f = he2->f = f;
    pm->faces.push_back(f);
    pm->hedges.push_back(he0);
    pm->hedges.push_back(he1);
    pm->hedges.push_back(he2);
    he0->data = pm->hedges.size() - 3;
    he1->data = pm->hedges.size() - 2;
    he2->data = pm->hedges.size() - 1;
  }

  // Create Face Adjacency
  for(int i = 0; i < pm->hedges.size(); ++i) {
    for(int j = i + 1; j < pm->hedges.size(); ++j) {
      PolyMesh::HalfEdge *he0 = pm->hedges[i];
      PolyMesh::HalfEdge *he1 = pm->hedges[j];
      if(he0->v == he1->next->v && he0->next->v == he1->v) {
        he0->opposite = he1;
        he1->opposite = he0;
      }
    }
  }

  // Swap Edges
  std::stack<PolyMesh::HalfEdge *> _stack;
  for(auto he : pm->hedges) { _stack.push(he); }
  std::vector<bool> _updated(pm->hedges.size(), true);
  std::vector<PolyMesh::HalfEdge *> _touched;
  while(!_stack.empty()) {
    PolyMesh::HalfEdge *he = _stack.top();
    _stack.pop();
    if(!_updated[he->data]) continue;
    _touched.push_back(he);
    if(delaunayEdgeCriterionPlaneIsotropic(he, nullptr) == 1) {
      pm->swap_edge(he);

      PolyMesh::HalfEdge *H[4] = {he->next, he->next->next, he->opposite->next,
                                  he->opposite->next->next};

      for(int k = 0; k < 4; k++) {
        he = H[k];
        if(!he->opposite) continue;

        _updated[he->data] = true;
        _updated[he->opposite->data] = true;
        _stack.push(he);
      }
    }
    else {
      _updated[he->data] = false;
      if(he->opposite) _updated[he->opposite->data] = false;
    }
  }

  // Insert Face Points
  PolyMesh::Face *f = pm->faces[0];
  for(size_t i = 2 * offsets[2]; i < coord.size(); i += 2) {
    double x = coord[i];
    double y = coord[i + 1];
    // find face in which lies x,y
    f = Walk(f, x, y);
    if(!f) Msg::Error("face not found");
    // split f and then swap edges to recover delaunayness
    pm->split_triangle(-1, x, y, 0, f, delaunayEdgeCriterionPlaneIsotropic,
                       nullptr);
    pm->vertices[pm->vertices.size() - 1]->data = i / 2 + 1;
  }

  // Recover Edges
  if(rec) {
    for(size_t i = 0; i < rec->size(); i += 2) {
      int result =
        recover_edge(pm, pm->vertices[(*rec)[i]], pm->vertices[(*rec)[i + 1]]);
      if(result) {
        Msg::Error("impossible to recover an edge %d %d (%d %d): %d", (*rec)[i],
                   (*rec)[i + 1], tri.size() / 3 + 2, pm->vertices.size(),
                   result);
      }
    }
  }

  // Recover Triangulation
  tri.clear();
  for(auto t : pm->faces) {
    int i0 = t->he->v->data;
    int i1 = t->he->next->v->data;
    int i2 = t->he->next->next->v->data;
    tri.push_back(i0);
    tri.push_back(i1);
    tri.push_back(i2);
  }

  delete pm;

  return 0;
}

PolyMesh *
highOrderPolyMesh::cutMesh(std::vector<PolyMesh::Vertex *> &pointVertices)
{
  tags.clear();
  evs.clear();
  fvs.clear();
  pvtags.clear();
  pvvtags.clear();
  sp2pv.clear();
  pv2sp.clear();
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

  std::map<PolyMesh::HalfEdge *, size_t> heVerticesStart;
  std::map<PolyMesh::HalfEdge *, size_t> heVerticesEnd;
  std::vector<PolyMesh::Vertex *> heVertices;

  Msg::Info("Spliting original mesh using geodesics\n");
  for(auto it : evs) {
    PolyMesh::HalfEdge *he = it.first;
    geodesic::Edge *e =
      static_cast<geodesic::Edge *>(pv2sp[it.second[0]].base_element());
    bool swap;
    if(he->v->data == e->v0()->id() && he->next->v->data == e->v1()->id())
      swap = false;
    else if(he->v->data == e->v1()->id() && he->next->v->data == e->v0()->id())
      swap = true;
    else
      Msg::Error("edge and hedge not corresponding");
    std::vector<std::pair<double, PolyMesh::Vertex *>> vv;
    for(auto i : it.second) {
      if(!swap)
        vv.push_back({pv2sp[i].uv()[0], pm->vertices[i]});
      else
        vv.push_back({1. - pv2sp[i].uv()[0], pm->vertices[i]});
    }
    std::sort(vv.begin(), vv.end());
    PolyMesh::HalfEdge *hhe = he;
    heVerticesStart[hhe] = heVertices.size();
    for(size_t k = 0; k < vv.size(); k++) {
      heVertices.push_back(vv[k].second);
    }
    heVerticesEnd[hhe] = heVertices.size();
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
    size_t edgeOffset[3] = {0, 0, 0};
    for(int j = 0; j < 3; ++j) {
      geodesic::SurfacePoint sp(&geoMesh.vertices()[he->v->data]);
      addPP(he->v, pp, coord, &geoMesh.faces()[pm->faces[i]->data], sp);
      PolyMesh::Vertex *v0 = he->v, *v1 = he->next->v;
      PolyMesh::HalfEdge *hhe;
      if(v0->data < v1->data) {
        hhe = pm->getEdge(v0, v1);
        for(size_t k = heVerticesStart[hhe]; k < heVerticesEnd[he]; ++k) {
          addPP(heVertices[k], pp, coord, &geoMesh.faces()[pm->faces[i]->data],
                pv2sp[heVertices[k]->data]);
        }
      }
      else {
        hhe = pm->getEdge(v1, v0);
        for(size_t k = heVerticesEnd[hhe] - 1; k + 1 > heVerticesStart[hhe];
            --k) {
          addPP(heVertices[k], pp, coord, &geoMesh.faces()[pm->faces[i]->data],
                pv2sp[heVertices[k]->data]);
        }
      }
      edgeOffset[j] = pp.size();
      he = he->next;
    }

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
        addPP(newv, pp, coord, &geoMesh.faces()[i], pv2sp[newv->data]);
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
      triangulate(coord, edgeOffset, &recover_all, tri);

      if(tri.size() == 0)
        Msg::Error("CutMesh: Zero triangles after remeshing a face");
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
      Msg::Error("CutMesh: Triangle with less than 3 vertices");
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
  std::vector<int> faceTags(ipm->faces.size());
  std::unordered_map<int, int> faceTags2Index;
  std::vector<size_t> offset(ipm->vertices.size() + 1, 0);
  std::vector<int> tags;
  size_t current = 0;
  std::unordered_map<int, size_t> data2index;
  for(size_t i = 0; i < ipm->vertices.size(); ++i) {
    data2index[ipm->vertices[i]->data] = i;
    PolyMesh::Vertex *v = pm_new->vertices[sp2pv[ipm->vertices[i]->data]];
    PolyMesh::HalfEdge *he = v->he;
    do {
      int tag = he->f->data;
      auto it = std::find(tags.begin() + current, tags.end(), tag);
      if(it == tags.end()) tags.push_back(tag);

      if(he->opposite) { he = he->opposite->next; }
      else {
        while(he->next->next->opposite) he = he->next->next->opposite;
      }

    } while(he != v->he);
    current = tags.size();
    offset[i + 1] = current;
  }

  std::vector<int> commonFaces;
  for(size_t i = 0; i < ipm->faces.size(); ++i) {
    PolyMesh::HalfEdge *he = ipm->faces[i]->he;
    size_t is[3] = {data2index[he->v->data], data2index[he->next->v->data],
                    data2index[he->next->next->v->data]};
    commonFaces.clear();
    for(size_t ii = offset[is[0]]; ii < offset[is[0] + 1]; ++ii) {
      for(size_t jj = offset[is[1]]; jj < offset[is[1] + 1]; ++jj) {
        if(tags[ii] != tags[jj]) continue;
        for(size_t kk = offset[is[2]]; kk < offset[is[2] + 1]; ++kk) {
          if(tags[ii] != tags[kk]) continue;
          commonFaces.push_back(tags[ii]);
        }
      }
    }
    if(commonFaces.size() != 1)
      Msg::Error("Triangle %d (%d %d %d) correspond to %d face tags", i,
                 ipm->faces[i]->he->v->data, ipm->faces[i]->he->next->v->data,
                 ipm->faces[i]->he->next->next->v->data, commonFaces.size());
    faceTags[i] = commonFaces[0];
    faceTags2Index[commonFaces[0]] = i;
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

void saveIsoTriangles(int num, TypedPoints &points, PolyMesh *ipm)
{
  char name[256];
  snprintf(name, sizeof(name), "isoTriangle%d.pos", num);
  std::ofstream f(name);
  if(!f) Msg::Error("Failed to open file: %s", name);
  f << "View \"P\"{\n";
  for(size_t i = 0; i < ipm->faces.size(); ++i) {
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
  // Mesh Coherance
  for(int i = 0; i < ipm->faces.size(); ++i) {
    auto he = ipm->faces[i]->he;
    if(!he) Msg::Error("No f->he");
    for(int j = 0; j < 3; ++j) {
      if(!he->next) Msg::Error("No next");
      if(!he->next->next) Msg::Error("No next next next");
      if(he->next->next->next != he) Msg::Error("No next = he");
      if(!he->opposite) Msg::Error("No opposite");
      if(he->next->v != he->opposite->v)
        Msg::Error("opposite not corresponding");
      if(he->v != he->opposite->next->v)
        Msg::Error("opposite next  not corresponding");
      if(!he->f) Msg::Error("No face");
      if(!he->v) Msg::Error("No vertex");
      if(!he->v->he) Msg::Error("No vertex he");
      if(!he->f->he) Msg::Error("No face he");
      he = he->next;
    }
  }
  if(ipm->faces.size() != ipm->hedges.size() / 3)
    Msg::Error("Not right number of hedges compared to faces");

  // Check geodesics
  for(auto kv : geodesics) {
    auto i0 = kv.first.first;
    auto i1 = kv.first.second;
    auto &first = kv.second.front();
    auto &second = kv.second.back();
    if(abs(pointsPool[i0].x() - first.x()) > 1e-3 ||
       abs(pointsPool[i0].y() - first.y()) > 1e-3 ||
       abs(pointsPool[i0].z() - first.z()) > 1e-3) {
      printGeodesic("geodesic_sanity.pos", i0, i1);
      printVertex("vertex_sanity_0.pos", i0);
      printVertex("vertex_sanity_1.pos", i1);
      std::cout << pointsPool[i0].x() - first.x() << " "
                << pointsPool[i0].y() - first.y() << " "
                << pointsPool[i0].z() - first.z() << std::endl;
      Msg::Error("Geodesic %d %d deos not start at %d", i0, i1, i0);
    }
    if(abs(pointsPool[i1].x() - second.x()) > 1e-3 ||
       abs(pointsPool[i1].y() - second.y()) > 1e-3 ||
       abs(pointsPool[i1].z() - second.z()) > 1e-3) {
      printGeodesic("geodesic_sanity.pos", i0, i1);
      printVertex("vertex_sanity_0.pos", i0);
      printVertex("vertex_sanity_1.pos", i1);
      std::cout << abs(pointsPool[i1].x() - second.x()) << " "
                << abs(pointsPool[i1].y() - second.y()) << " "
                << abs(pointsPool[i1].z() - second.z()) << std::endl;

      Msg::Error("Geodesic %d %d deos not end at %d", i0, i1, i1);
    }
  }

  // Intersection
  std::vector<std::pair<size_t, size_t>> newEdges, borderEdges;
  for(size_t i = 0; i < ipm->hedges.size(); ++i) {
    PolyMesh::HalfEdge *he = ipm->hedges[i];
    if(he->v->data > he->next->v->data) continue;
    newEdges.push_back({he->v->data, he->next->v->data});
  }
  if(intersectNewEdges(newEdges, borderEdges)) {
    printGeodesics("geodesics_intersection.pos");
    Msg::Error("Intersection between edges !");
  }

  return true;
}

void highOrderPolyMesh::meshAdapt(int niter)
{
  Msg::Info("Begin adaptation:\t\t\tTriangles: %d", ipm->faces.size());
  int i = 0, nbrSwap = 0, nbrCollapse = 0, nbrEdgeSplit = 0,
      nbrTriangleSplit = 0, printIndex = 1;

  if(DEBUG) { sanityCheck(); }

  if(niter >= 0) {
    nbrSwap = swapEdges(HEURISTIC_SWAP, false);
    nbrSwap += swapEdges(HEURISTIC_SWAP);

    Msg::Info("Number of edge swaps: \t%d\tTriangles: %d", nbrSwap,
              ipm->faces.size());

    if(PRINT) {
      printGeodesics("geodesics_swapped.pos");
      saveIsoTriangles(printIndex++, pointsPool, ipm);
    }
    if(DEBUG) { sanityCheck(); }
  }

  for(; i < niter; ++i, printIndex -= 3) {
    iteration_loop = i;

    // Collapse edges
    nbrCollapse = collapseEdges();
    Msg::Info("Number of edge collapse: \t%d\tTriangles: %d", nbrCollapse,
              ipm->faces.size());

    if(PRINT) {
      printGeodesics("geodesics_collapse.pos");
      saveIsoTriangles(printIndex++, pointsPool, ipm);
    }
    if(DEBUG) { sanityCheck(); }

    // Split edges
    nbrEdgeSplit = splitEdges();
    Msg::Info("Number of edge split: \t%d\tTriangles: %d", nbrEdgeSplit,
              ipm->faces.size());

    if(PRINT) {
      printGeodesics("geodesics_edge_split.pos");
      saveIsoTriangles(printIndex++, pointsPool, ipm);
    }
    if(DEBUG) { sanityCheck(); }

    // Split triangles
    nbrTriangleSplit = splitTriangles();
    Msg::Info("Number of triangle split: \t%d\tTriangles: %d", nbrTriangleSplit,
              ipm->faces.size());

    if(PRINT) {
      printGeodesics("geodesics_triangle_split.pos");
      saveIsoTriangles(printIndex++, pointsPool, ipm);
    }
    if(DEBUG) { sanityCheck(); }

    Msg::Info("");
    if(nbrCollapse + nbrEdgeSplit + nbrTriangleSplit == 0) break;
  }
  printIndex += 3;

  if(i < niter) { Msg::Info("Converged in %d iterations", i); }
  else {
    Msg::Info("Did not converged after %d iterations", i);
  }

  createGeodesics();
  if(PRINT) {
    printGeodesics("geodesics_adapted.pos");
    saveIsoTriangles(printIndex++, pointsPool, ipm);
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

  double clmin = std::max(1e-100, CTX::instance()->mesh.lcMin);
  double clmax = std::min(1e+100, CTX::instance()->mesh.lcMax);
  hop.characLengthMin = std::vector<double>(hop.pm->vertices.size(), clmin);
  hop.characLengthMax = std::vector<double>(hop.pm->vertices.size(), clmax);

  hop.createInitialGeodesics();

  if(PRINT) {
    hop.printGeodesics("geodesics.pos");
    saveIsoTriangles(0, hop.pointsPool, hop.ipm);
  }

  int adapt = CTX::instance()->mesh.maxIterIntrinsic;

  auto endInit = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed = endInit - start;
  Msg::Info("Initialization elapsed time: %.2lf seconds", elapsed.count());
  hop.meshAdapt(adapt);

  auto endAdapt = std::chrono::high_resolution_clock::now();
  elapsed = endAdapt - endInit;
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
  std::unordered_set<PolyMesh::HalfEdge *> checkedHE;
  for(auto he : hop.ipm->hedges) {
    auto it = checkedHE.find(he);
    if(it != checkedHE.end()) continue;
    std::pair<int, int> e = {he->v->data, he->next->v->data};
    PathView path;
    hop.getGeodesicPath(e.first, e.second, path);
    PathView pv(path);
    double almin = hop.adimLengthMin(pv);
    double almax = hop.adimLengthMax(pv);
    if(almin < 1.) nbrEdgeLessThanMin++;
    if(almax > 1.) nbrEdgeGreaterThanMax++;
    double q = hop.getEdgeQuality(e);
    if(q < 0.) edgeQualityLessThanZero++;
    checkedHE.insert(he);
    if(he->opposite) checkedHE.insert(he->opposite);
  }
  for(size_t i = 0; i < hop.ipm->faces.size(); ++i) {
    auto he = hop.ipm->faces[i]->he;
    for(int j = 0; j < 3; ++j) {
      double angle = hop.computeIntrinsicAngle(he->v->data, he->next->v->data,
                                               he->next->next->v->data);
      if(angle < MINANGLE) nbrAngleLessThanMin++;
      if(angle > MAXANGLE) nbrAngleGreaterThanMax++;
      if(angle < minAngle) minAngle = angle;
      if(angle > maxAngle) maxAngle = angle;
      meanAngle += angle;
      unsigned idx = std::min((unsigned)35, (unsigned)((angle / M_PI) * 36));
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

  Msg::Info("Number of vertices: %d", hop.ipm->vertices.size());
  Msg::Info("Number of edges: %d", hop.ipm->hedges.size() / 2);
  Msg::Info("Number of triangles: %d", hop.ipm->faces.size());
  Msg::Info("Number of edges less than %g: %d", 1, nbrEdgeLessThanMin);
  Msg::Info("Number of edges greater than %g: %d", 1, nbrEdgeGreaterThanMax);
  Msg::Info("Number of angles less than %g: %d", MINANGLE, nbrAngleLessThanMin);
  Msg::Info("Number of angles greater than %g: %d", MAXANGLE,
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

  int diffEd = nbrEdgeGreaterThanMax + nbrEdgeLessThanMin;
  if(diffEd == 0)
    Msg::Info("All Edge Constraints are verified");
  else
    Msg::Info("%d Edge Contraints were not verified", diffEd);

  int diffTri = nbrAngleGreaterThanMax + nbrAngleLessThanMin;
  if(diffTri == 0)
    Msg::Info("All Triangle Constraints are verified");
  else
    Msg::Info("%d Triangle Contraints were not verified", diffTri);

  auto endStat = std::chrono::high_resolution_clock::now();
  elapsed = endStat - endCut;
  Msg::Info("Statistics elapsed time: %.2lf seconds", elapsed.count());

  if(PRINT_COLORED) {
    std::map<int, int> face2Colors;
    int c = 4;
    Msg::Info("Trying to color with %d colors.", c);
    while(!colorFaces(pm_new, face2Colors, c)) {
      Msg::Info("Coloring with %d colors failed.", c);
      c++;
      Msg::Info("Trying to color with %d colors.", c);
    }
    printCuttedMesh(pm_new, face2Colors);
  }

  hop.write(pm_new, pointVertices);

  auto end = std::chrono::high_resolution_clock::now();
  elapsed = end - endStat;
  Msg::Info("Write elapsed time: %.2lf seconds", elapsed.count());

  elapsed = end - start;
  Msg::Info("----------------------------------------");
  Msg::Info("Total elapsed time: %.3lf seconds", elapsed.count());
  Msg::Info("Geodesic propagation: %.3lf seconds",
            hop.timer_geodesic_propagation.count());
  Msg::Info("Geodesic trace back: %.3lf seconds",
            hop.timer_geodesic_trace_back.count());
  Msg::Info("Circumcenter search: %.3lf seconds",
            hop.timer_circumcenter.count());

  return 0;
}

#else

int makeMeshGeodesic(GModel *gm)
{
  Msg::Error("Geodesic meshing not available");
  return 0;
}

#endif
