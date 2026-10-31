// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <algorithm>
#include <cctype>
#include <cmath>
#include "DiscreteCADModeler.h"
#include "DiscreteCADMeshBoolean.h"
#include "DiscreteCADRecognition.h"
#include "GmshMessage.h"
#include "Context.h"
#include "GModel.h"
#include "GModelIO_GEO.h"
#include "GModelIO_OCC.h"
#include "OpenFile.h"
#include "StringUtils.h"
#include "discreteVertex.h"
#include "discreteEdge.h"
#include "discreteFace.h"
#include "discreteRegion.h"
#include "MVertex.h"
#include "MLine.h"
#include "MTriangle.h"
#include "SPoint2.h"
#include "SPoint3.h"
#include "GEdgeLoop.h"
#include "GModelParametrize.h"

namespace {
  const char *entityName(int dim)
  {
    static const char *names[4] = {"point", "curve", "surface", "volume"};
    return names[dim];
  }

  // the maximum distance between the unit sphere and the triangles of an
  // octant of the octahedron, n times subdivided, projected on it: 1 - the
  // distance of the plane of each triangle to the center (the distance to
  // the circumcenter of the triangle, an upper bound when it lies outside)
  double octantDeviation(int n)
  {
    auto point = [n](int i, int j) {
      std::array<double, 3> p = {(double)i, (double)j, (double)(n - i - j)};
      const double r = std::sqrt(p[0] * p[0] + p[1] * p[1] + p[2] * p[2]);
      for(int k = 0; k < 3; k++) p[k] /= r;
      return p;
    };
    auto deviation = [](const std::array<double, 3> &a,
                        const std::array<double, 3> &b,
                        const std::array<double, 3> &c) {
      const double u[3] = {b[0] - a[0], b[1] - a[1], b[2] - a[2]};
      const double v[3] = {c[0] - a[0], c[1] - a[1], c[2] - a[2]};
      const double w[3] = {u[1] * v[2] - u[2] * v[1], u[2] * v[0] - u[0] * v[2],
                           u[0] * v[1] - u[1] * v[0]};
      const double l = std::sqrt(w[0] * w[0] + w[1] * w[1] + w[2] * w[2]);
      return 1. - std::abs(w[0] * a[0] + w[1] * a[1] + w[2] * a[2]) / l;
    };
    double d = 0.;
    for(int i = 0; i < n; i++)
      for(int j = 0; i + j < n; j++) {
        d = std::max(d, deviation(point(i, j), point(i + 1, j), point(i, j + 1)));
        if(i + j + 2 <= n)
          d = std::max(d, deviation(point(i + 1, j), point(i + 1, j + 1),
                                    point(i, j + 1)));
      }
    return d;
  }

  const double pi = 3.14159265358979323846;

  void normalize(double v[3])
  {
    const double l = std::sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
    if(l > 0.)
      for(int k = 0; k < 3; k++) v[k] /= l;
  }

  // the frame of origin (x, y, z), of third axis zAxis and first axis xAxis
  // made orthogonal to it (the z axis, and the x or y axis, if empty)
  DiscreteCAD_Internals::Frame frame(double x, double y, double z,
                                     const std::vector<double> &zAxis,
                                     const std::vector<double> &xAxis)
  {
    DiscreteCAD_Internals::Frame f;
    f.o[0] = x;
    f.o[1] = y;
    f.o[2] = z;
    double *e0 = f.e[0], *e1 = f.e[1], *e2 = f.e[2];
    for(int k = 0; k < 3; k++) e2[k] = zAxis.size() == 3 ? zAxis[k] : k == 2;
    normalize(e2);
    double t[3] = {1., 0., 0.};
    if(xAxis.size() == 3)
      for(int k = 0; k < 3; k++) t[k] = xAxis[k];
    for(int pass = 0; pass < 2; pass++) {
      const double d = t[0] * e2[0] + t[1] * e2[1] + t[2] * e2[2];
      for(int k = 0; k < 3; k++) e0[k] = t[k] - d * e2[k];
      if(e0[0] * e0[0] + e0[1] * e0[1] + e0[2] * e0[2] > 1.e-12) break;
      // xAxis (or x) along zAxis: y instead
      t[0] = 0.;
      t[1] = 1.;
      t[2] = 0.;
    }
    normalize(e0);
    e1[0] = e2[1] * e0[2] - e2[2] * e0[1];
    e1[1] = e2[2] * e0[0] - e2[0] * e0[2];
    e1[2] = e2[0] * e0[1] - e2[1] * e0[0];
    return f;
  }

  // the divisions (even, at least 4) of a circle of radius r whose chords are
  // at most tolerance away from it
  int circleDivisions(double r, double tolerance)
  {
    const int maxDivisions = 4096;
    if(tolerance >= r) return 4;
    int n = (int)std::ceil(pi / std::acos(1. - tolerance / r) - 1.e-9);
    n = std::max(4, n + n % 2);
    return std::min(n, maxDivisions);
  }

  // the triangles between the halves [h pi, (h + 1) pi] of rings a and b
  // (closed, of an even number of nodes, or a single node), by increasing
  // angle: oriented outwards for b above a on a surface of revolution, and
  // along the axis for b inside a in a plane
  void zipHalf(const std::vector<int> &a, const std::vector<int> &b, int h,
               std::vector<std::array<int, 3> > &triangles)
  {
    auto half = [h](const std::vector<int> &r) {
      const int n = (int)r.size();
      std::vector<int> p;
      if(n == 1) p.push_back(r[0]);
      else
        for(int i = h * n / 2; i <= (h + 1) * n / 2; i++) p.push_back(r[i % n]);
      return p;
    };
    const std::vector<int> pa = half(a), pb = half(b);
    const int na = (int)pa.size() - 1, nb = (int)pb.size() - 1;
    int i = 0, j = 0;
    while(i < na || j < nb) {
      // on the ring whose next node comes first
      if(j == nb || (i < na && (double)(i + 1) / na <= (double)(j + 1) / nb)) {
        triangles.push_back({{pa[i], pa[i + 1], pb[j]}});
        i++;
      }
      else {
        triangles.push_back({{pa[i], pb[j + 1], pb[j]}});
        j++;
      }
    }
  }

  void reverse(std::vector<std::array<int, 3> > &triangles)
  {
    for(auto &t : triangles) std::swap(t[1], t[2]);
  }

  // a temporary model, current while it exists (the numbering of the nodes
  // and elements of the current one is left alone); creating it hides the
  // others
  class TemporaryModel {
    int _current;
    std::vector<int> _visible;

  public:
    GModel *model;
    TemporaryModel() : _current(GModel::getCurrentIndex())
    {
      for(GModel *m : GModel::list) _visible.push_back(m->getVisibility());
      model = new GModel();
      GModel::setCurrent(model);
    }
    ~TemporaryModel()
    {
      delete model;
      GModel::setCurrentIndex(_current);
      for(std::size_t i = 0; i < GModel::list.size() && i < _visible.size();
          i++)
        GModel::list[i]->setVisibility(_visible[i]);
    }
  };
} // namespace

DiscreteCAD_Internals::DiscreteCAD_Internals() { reset(); }

void DiscreteCAD_Internals::reset()
{
  _nodes.clear();
  _vertices.clear();
  _curves.clear();
  _surfaces.clear();
  _volumes.clear();
  for(int dim = 0; dim < 4; dim++) _maxTag[dim] = 0;
  _synchronized.clear();
  _changed = false;
}

bool DiscreteCAD_Internals::_exists(int dim, int tag) const
{
  switch(dim) {
  case 0: return _vertices.count(tag) > 0;
  case 1: return _curves.count(tag) > 0;
  case 2: return _surfaces.count(tag) > 0;
  default: return _volumes.count(tag) > 0;
  }
}

bool DiscreteCAD_Internals::_assignTag(int dim, int &tag)
{
  if(tag > 0 && _exists(dim, tag)) {
    Msg::Error("Discrete CAD %s %d already exists", entityName(dim), tag);
    return false;
  }
  GModel *model = GModel::current();
  GEO_Internals *geo = model ? model->getGEOInternals() : nullptr;
  OCC_Internals *occ = model ? model->getOCCInternals() : nullptr;
  if(tag <= 0) {
    // after the entities of the model and of the other kernels
    tag = _maxTag[dim];
    if(model) tag = std::max(tag, model->getMaxElementaryNumber(dim));
    if(geo) tag = std::max(tag, geo->getMaxTag(dim));
    if(occ) tag = std::max(tag, occ->getMaxTag(dim));
    tag++;
  }
  _maxTag[dim] = std::max(_maxTag[dim], tag);
  _changed = true;
  // the other kernels number their new entities after it
  if(geo) geo->setMaxTag(dim, std::max(geo->getMaxTag(dim), tag));
  if(occ) occ->setMaxTag(dim, tag);
  return true;
}

int DiscreteCAD_Internals::_addNode(double x, double y, double z)
{
  _nodes.push_back({{x, y, z}});
  return (int)_nodes.size() - 1;
}

int DiscreteCAD_Internals::_addVertex(int node)
{
  int tag = -1;
  _assignTag(0, tag);
  _vertices[tag] = {node};
  return tag;
}

int DiscreteCAD_Internals::_addCurve(int v0, int v1,
                                     const std::vector<int> &nodes)
{
  int tag = -1;
  _assignTag(1, tag);
  _curves[tag] = {v0, v1, nodes};
  return tag;
}

int DiscreteCAD_Internals::_addSurface(
  const std::vector<int> &curves,
  const std::vector<std::array<int, 3> > &triangles)
{
  int tag = -1;
  _assignTag(2, tag);
  _surfaces[tag] = {curves, triangles};
  return tag;
}

bool DiscreteCAD_Internals::addBox(int &tag, double x, double y, double z,
                                   double dx, double dy, double dz)
{
  if(!dx || !dy || !dz) {
    Msg::Error("Discrete CAD box with a zero extent");
    return false;
  }
  if(!_assignTag(3, tag)) return false;
  // a positive extent along each axis
  if(dx < 0.) {
    x += dx;
    dx = -dx;
  }
  if(dy < 0.) {
    y += dy;
    dy = -dy;
  }
  if(dz < 0.) {
    z += dz;
    dz = -dz;
  }
  // corner i + 2 j + 4 k at (x + i dx, y + j dy, z + k dz)
  int corner[8];
  for(int c = 0; c < 8; c++)
    corner[c] = _addVertex(
      _addNode(x + (c & 1) * dx, y + ((c >> 1) & 1) * dy, z + (c >> 2) * dz));
  // the 12 edges, from their corner of smaller index
  static const int edges[12][2] = {{0, 1}, {2, 3}, {4, 5}, {6, 7},
                                   {0, 2}, {1, 3}, {4, 6}, {5, 7},
                                   {0, 4}, {1, 5}, {2, 6}, {3, 7}};
  std::map<std::pair<int, int>, int> curveOf;
  for(auto &e : edges) {
    const int a = corner[e[0]], b = corner[e[1]];
    curveOf[{e[0], e[1]}] =
      _addCurve(a, b, {_vertices[a].node, _vertices[b].node});
  }
  // the 6 faces, their corners counterclockwise seen from outside
  static const int faces[6][4] = {{0, 4, 6, 2}, {1, 3, 7, 5}, {0, 1, 5, 4},
                                  {2, 6, 7, 3}, {0, 2, 3, 1}, {4, 5, 7, 6}};
  Volume volume;
  for(auto &f : faces) {
    std::vector<int> loop;
    for(int k = 0; k < 4; k++) {
      const int a = f[k], b = f[(k + 1) % 4];
      loop.push_back(a < b ? curveOf[{a, b}] : -curveOf[{b, a}]);
    }
    int n[4];
    for(int k = 0; k < 4; k++) n[k] = _vertices[corner[f[k]]].node;
    const int face =
      _addSurface(loop, {{{n[0], n[1], n[2]}}, {{n[0], n[2], n[3]}}});
    // along the edges from the first corner
    double eu[3], ev[3];
    for(int k = 0; k < 3; k++) {
      eu[k] = _nodes[n[1]][k] - _nodes[n[0]][k];
      ev[k] = _nodes[n[3]][k] - _nodes[n[0]][k];
    }
    normalize(eu);
    normalize(ev);
    _planarUV(face, _nodes[n[0]].data(), eu, ev);
    volume.surfaces.push_back(face);
  }
  _volumes[tag] = volume;
  return true;
}

bool DiscreteCAD_Internals::addSphere(int &tag, double xc, double yc,
                                      double zc, double radius,
                                      double tolerance)
{
  if(radius <= 0.) {
    Msg::Error("Discrete CAD sphere with a non-positive radius");
    return false;
  }
  if(!_assignTag(3, tag)) return false;
  if(tolerance <= 0.)
    tolerance = CTX::instance()->geom.discreteTolerance * radius;
  // the octants of the octahedron, n times subdivided along their edges, the
  // fewest subdivisions within the tolerance (the deviation decreases as
  // 1 / n^2)
  const int maxDivisions = 1024;
  int n = (int)std::ceil(
    std::sqrt(octantDeviation(1) * radius / tolerance) - 1.e-12);
  n = std::min(std::max(n, 1), maxDivisions);
  while(n > 1 && octantDeviation(n - 1) * radius <= tolerance) n--;
  while(n < maxDivisions && octantDeviation(n) * radius > tolerance) n++;
  if(octantDeviation(n) * radius > tolerance)
    Msg::Warning("Discrete CAD sphere: tolerance %g not reached with %d "
                 "subdivisions (%g)",
                 tolerance, n, octantDeviation(n) * radius);
  // the nodes, shared by the octants through their integer coordinates
  // (signed, zero on the planes of the octants)
  std::map<std::array<int, 3>, int> nodeOf;
  auto node = [&](int i, int j, int k) {
    const std::array<int, 3> key = {{i, j, k}};
    auto it = nodeOf.find(key);
    if(it != nodeOf.end()) return it->second;
    const double r = std::sqrt((double)(i * i + j * j + k * k));
    const int id = _addNode(xc + radius * i / r, yc + radius * j / r,
                            zc + radius * k / r);
    nodeOf[key] = id;
    return id;
  };
  // the two hemispheres, their triangles oriented outwards
  std::vector<std::array<int, 3> > north, south;
  for(int s = 0; s < 8; s++) {
    const int sx = (s & 1) ? -1 : 1, sy = (s & 2) ? -1 : 1,
              sz = (s & 4) ? -1 : 1;
    auto add = [&](int i0, int j0, int i1, int j1, int i2, int j2) {
      std::array<int, 3> t = {
        {node(sx * i0, sy * j0, sz * (n - i0 - j0)),
         node(sx * i1, sy * j1, sz * (n - i1 - j1)),
         node(sx * i2, sy * j2, sz * (n - i2 - j2))}};
      // outwards for the octant (+, +, +); a reflection of an odd number of
      // axes reverses it
      if(sx * sy * sz < 0) std::swap(t[1], t[2]);
      (sz > 0 ? north : south).push_back(t);
    };
    for(int i = 0; i < n; i++)
      for(int j = 0; i + j < n; j++) {
        add(i, j, i + 1, j, i, j + 1);
        if(i + j + 2 <= n) add(i + 1, j, i + 1, j + 1, i, j + 1);
      }
  }
  // the equator, two arcs between the vertices at -x and +x: A through +y,
  // B through -y
  const int east = _addVertex(node(n, 0, 0)), west = _addVertex(node(-n, 0, 0));
  std::vector<int> arcA, arcB;
  for(int m = 0; m <= n; m++) arcA.push_back(node(n - m, m, 0));
  for(int m = 1; m <= n; m++) arcA.push_back(node(-m, n - m, 0));
  for(int m = 0; m <= n; m++) arcB.push_back(node(-(n - m), -m, 0));
  for(int m = 1; m <= n; m++) arcB.push_back(node(m, -(n - m), 0));
  const int a = _addCurve(east, west, arcA), b = _addCurve(west, east, arcB);
  // the loops counterclockwise seen from outside
  Volume volume;
  volume.surfaces.push_back(_addSurface({a, b}, north));
  volume.surfaces.push_back(_addSurface({-b, -a}, south));
  // the stereographic projections from the opposite poles, on the unit disk
  for(int h = 0; h < 2; h++)
    _setUV(volume.surfaces[h], [&](int n) {
      const std::array<double, 3> &x = _nodes[n];
      const double q[3] = {(x[0] - xc) / radius, (x[1] - yc) / radius,
                           (x[2] - zc) / radius};
      const double d = 1. + (h ? -q[2] : q[2]);
      return std::array<double, 2>{{q[0] / d, q[1] / d}};
    });
  _volumes[tag] = volume;
  return true;
}

std::vector<int> DiscreteCAD_Internals::_addRing(const Frame &f, double rx,
                                                double ry, double w, int n)
{
  std::vector<int> ring;
  for(int i = 0; i < n; i++) {
    const double t = 2. * pi * i / n;
    const double u = n == 1 ? 0. : rx * std::cos(t);
    const double v = n == 1 ? 0. : ry * std::sin(t);
    double p[3];
    for(int k = 0; k < 3; k++)
      p[k] = f.o[k] + u * f.e[0][k] + v * f.e[1][k] + w * f.e[2][k];
    ring.push_back(_addNode(p[0], p[1], p[2]));
  }
  return ring;
}

void DiscreteCAD_Internals::_addArcs(const std::vector<int> &ring, int &a,
                                     int &b)
{
  const std::size_t n = ring.size();
  const int v0 = _addVertex(ring[0]), v1 = _addVertex(ring[n / 2]);
  std::vector<int> first(ring.begin(), ring.begin() + n / 2 + 1);
  std::vector<int> second(ring.begin() + n / 2, ring.end());
  second.push_back(ring[0]);
  a = _addCurve(v0, v1, first);
  b = _addCurve(v1, v0, second);
}

std::vector<std::array<int, 3> >
DiscreteCAD_Internals::_fillEllipse(const Frame &f, double rx, double ry,
                                    double w, const std::vector<int> &ring)
{
  // rings about as far apart as their nodes
  std::vector<std::array<int, 3> > triangles;
  const int n = (int)ring.size();
  const int m = std::max(1, (int)std::lround(n / (2. * pi)));
  std::vector<int> outer = ring;
  for(int k = m - 1; k >= 0; k--) {
    int nk = 1;
    if(k > 0) {
      nk = (int)std::lround((double)n * k / m);
      nk = std::max(4, nk + nk % 2);
    }
    const std::vector<int> inner =
      _addRing(f, rx * k / m, ry * k / m, w, nk);
    zipHalf(outer, inner, 0, triangles);
    zipHalf(outer, inner, 1, triangles);
    outer = inner;
  }
  return triangles;
}

void DiscreteCAD_Internals::_setUV(
  int surface, const std::function<std::array<double, 2>(int)> &uvOfNode)
{
  Surface &sf = _surfaces[surface];
  sf.uv.clear();
  for(auto &t : sf.triangles)
    sf.uv.push_back({{uvOfNode(t[0]), uvOfNode(t[1]), uvOfNode(t[2])}});
}

void DiscreteCAD_Internals::_planarUV(int surface, const double o[3],
                                      const double eu[3], const double ev[3])
{
  _setUV(surface, [&](int n) {
    const std::array<double, 3> &x = _nodes[n];
    const double d[3] = {x[0] - o[0], x[1] - o[1], x[2] - o[2]};
    return std::array<double, 2>{{d[0] * eu[0] + d[1] * eu[1] + d[2] * eu[2],
                                  d[0] * ev[0] + d[1] * ev[1] + d[2] * ev[2]}};
  });
}

bool DiscreteCAD_Internals::addRectangle(int &tag, double x, double y,
                                         double z, double dx, double dy)
{
  if(!dx || !dy) {
    Msg::Error("Discrete CAD rectangle with a zero extent");
    return false;
  }
  if(!_assignTag(2, tag)) return false;
  if(dx < 0.) {
    x += dx;
    dx = -dx;
  }
  if(dy < 0.) {
    y += dy;
    dy = -dy;
  }
  // counterclockwise seen from +z
  int v[4], n[4], c[4];
  for(int k = 0; k < 4; k++) {
    n[k] = _addNode(x + (k == 1 || k == 2) * dx, y + (k >= 2) * dy, z);
    v[k] = _addVertex(n[k]);
  }
  for(int k = 0; k < 4; k++)
    c[k] = _addCurve(v[k], v[(k + 1) % 4], {n[k], n[(k + 1) % 4]});
  _surfaces[tag] = {{c[0], c[1], c[2], c[3]},
                    {{{n[0], n[1], n[2]}}, {{n[0], n[2], n[3]}}}};
  const double eu[3] = {1., 0., 0.}, ev[3] = {0., 1., 0.};
  _planarUV(tag, _nodes[n[0]].data(), eu, ev);
  return true;
}

bool DiscreteCAD_Internals::addDisk(int &tag, double xc, double yc, double zc,
                                    double rx, double ry,
                                    const std::vector<double> &zAxis,
                                    const std::vector<double> &xAxis,
                                    double tolerance)
{
  if(rx <= 0. || ry <= 0.) {
    Msg::Error("Discrete CAD disk with a non-positive radius");
    return false;
  }
  if(!_assignTag(2, tag)) return false;
  const double rmin = std::min(rx, ry), rmax = std::max(rx, ry);
  if(tolerance <= 0.)
    tolerance = CTX::instance()->geom.discreteTolerance * rmax;
  const Frame f = frame(xc, yc, zc, zAxis, xAxis);
  // the chords of the ellipse are at most (2 pi rmax / n)^2 / (8 rmin^2 /
  // rmax) away from it: as those of a circle of radius rmax^3 / rmin^2
  const std::vector<int> ring = _addRing(
    f, rx, ry, 0., circleDivisions(rmax * rmax * rmax / (rmin * rmin), tolerance));
  int a, b;
  _addArcs(ring, a, b);
  _surfaces[tag] = {{a, b}, _fillEllipse(f, rx, ry, 0., ring)};
  _planarUV(tag, f.o, f.e[0], f.e[1]);
  return true;
}

bool DiscreteCAD_Internals::addCylinder(int &tag, double x, double y,
                                        double z, double dx, double dy,
                                        double dz, double r, double tolerance)
{
  if(r <= 0.) {
    Msg::Error("Discrete CAD cylinder with a non-positive radius");
    return false;
  }
  return addCone(tag, x, y, z, dx, dy, dz, r, r, tolerance);
}

bool DiscreteCAD_Internals::addCone(int &tag, double x, double y, double z,
                                    double dx, double dy, double dz, double r1,
                                    double r2, double tolerance)
{
  const double h = std::sqrt(dx * dx + dy * dy + dz * dz);
  if(!h || r1 < 0. || r2 < 0. || (!r1 && !r2)) {
    Msg::Error("Discrete CAD cone with a zero axis or invalid radii");
    return false;
  }
  if(!_assignTag(3, tag)) return false;
  const double rmax = std::max(r1, r2);
  if(tolerance <= 0.) tolerance = CTX::instance()->geom.discreteTolerance * rmax;
  const Frame f = frame(x, y, z, {dx, dy, dz}, {});
  // the rings at the ends of the lateral surface, ruled: a single band of
  // triangles between them is within the tolerance; a zero radius gives an
  // apex
  const double slant = std::sqrt(h * h + (r2 - r1) * (r2 - r1));
  const int m = 1;
  std::vector<std::vector<int> > rings(m + 1);
  for(int k = 0; k <= m; k++) {
    const double r = r1 + (r2 - r1) * k / m;
    rings[k] = _addRing(f, r, r, h * k / m, r > 0. ? circleDivisions(r, tolerance) : 1);
  }
  // the lateral surface, bounded by the circles at its ends (two arcs each)
  // and, without apex, by its seam at the angle 0, used twice; and the disks
  // at the ends. Their loops counterclockwise seen from outside
  const bool apex = !r1 || !r2;
  int a1 = 0, b1 = 0, a2 = 0, b2 = 0;
  if(r1 > 0.) _addArcs(rings[0], a1, b1);
  if(r2 > 0.) _addArcs(rings[m], a2, b2);
  std::vector<int> column;
  int seam = 0;
  if(!apex) {
    for(int k = 0; k <= m; k++) column.push_back(rings[k][0]);
    seam = _addCurve(_curves[a1].v0, _curves[a2].v0, column);
  }
  std::vector<std::array<int, 3> > triangles;
  for(int k = 0; k < m; k++)
    for(int half = 0; half < 2; half++)
      zipHalf(rings[k], rings[k + 1], half, triangles);
  std::vector<int> loop;
  if(r1 > 0.) loop.insert(loop.end(), {a1, b1});
  if(seam) loop.push_back(seam);
  if(r2 > 0.) loop.insert(loop.end(), {-b2, -a2});
  if(seam) loop.push_back(-seam);
  Volume volume;
  const int lateral = _addSurface(loop, triangles);
  volume.surfaces.push_back(lateral);
  // with an apex, a disk: the parameters (r / rmax) (cos(theta), sin(theta)),
  // the apex at the center as an embedded vertex
  if(apex) {
    _surfaces[lateral].embeddedVertices.push_back(
      _addVertex(r1 > 0. ? rings[m][0] : rings[0][0]));
    _setUV(lateral, [&](int n) {
      const std::array<double, 3> &x = _nodes[n];
      double c[3];
      for(int k = 0; k < 3; k++)
        c[k] = (x[0] - f.o[0]) * f.e[k][0] + (x[1] - f.o[1]) * f.e[k][1] +
               (x[2] - f.o[2]) * f.e[k][2];
      return std::array<double, 2>{{c[0] / rmax, c[1] / rmax}};
    });
  }
  // without apex, its developed parameters, an isometry: (r theta, z) for a
  // cylinder, s (cos(theta sin(beta)), sin(theta sin(beta))) for a cone, s
  // the distance to its apex and beta its half angle; the angles of the nodes
  // of a triangle across the seam from 0 to 2 pi
  else {
    std::map<int, double> angle;
    for(auto &ring : rings)
      for(std::size_t i = 0; i < ring.size(); i++)
        angle[ring[i]] = 2. * pi * i / ring.size();
    const double sinBeta = std::abs(r2 - r1) / slant;
    auto developed = [&](int n, double theta) {
      const std::array<double, 3> &x = _nodes[n];
      const double w = (x[0] - f.o[0]) * f.e[2][0] +
                       (x[1] - f.o[1]) * f.e[2][1] + (x[2] - f.o[2]) * f.e[2][2];
      if(r1 == r2) return std::array<double, 2>{{r1 * theta, w}};
      const double s = (r1 + (r2 - r1) * w / h) / sinBeta;
      return std::array<double, 2>{
        {s * std::cos(theta * sinBeta), s * std::sin(theta * sinBeta)}};
    };
    Surface &sf = _surfaces[lateral];
    for(auto &t : sf.triangles) {
      double theta[3];
      for(int k = 0; k < 3; k++) theta[k] = angle[t[k]];
      if(std::max({theta[0], theta[1], theta[2]}) -
           std::min({theta[0], theta[1], theta[2]}) > pi)
        for(int k = 0; k < 3; k++)
          if(theta[k] < pi) theta[k] += 2. * pi;
      sf.uv.push_back({{developed(t[0], theta[0]), developed(t[1], theta[1]),
                        developed(t[2], theta[2])}});
    }
    // (the seam used forwards at the angle 2 pi)
    auto &sides = sf.seams[seam];
    for(int n : column) {
      sides[0].push_back(developed(n, 2. * pi));
      sides[1].push_back(developed(n, 0.));
    }
  }
  if(r1 > 0.) {
    std::vector<std::array<int, 3> > bottom =
      _fillEllipse(f, r1, r1, 0., rings[0]);
    reverse(bottom);
    const int disk = _addSurface({-b1, -a1}, bottom);
    _planarUV(disk, f.o, f.e[0], f.e[1]);
    volume.surfaces.push_back(disk);
  }
  if(r2 > 0.) {
    const int disk =
      _addSurface({a2, b2}, _fillEllipse(f, r2, r2, h, rings[m]));
    _planarUV(disk, f.o, f.e[0], f.e[1]);
    volume.surfaces.push_back(disk);
  }
  _volumes[tag] = volume;
  return true;
}

bool DiscreteCAD_Internals::addTorus(int &tag, double x, double y, double z,
                                     double r1, double r2,
                                     const std::vector<double> &zAxis,
                                     double tolerance)
{
  if(r2 <= 0. || r1 <= r2) {
    Msg::Error("Discrete CAD torus with invalid radii (0 < r2 < r1)");
    return false;
  }
  if(!_assignTag(3, tag)) return false;
  if(tolerance <= 0.) tolerance = CTX::instance()->geom.discreteTolerance * r2;
  const Frame f = frame(x, y, z, zAxis, {});
  // the point at the angles theta (around the axis) and phi (around the
  // center circle)
  auto point = [&](double theta, double phi, double p[3]) {
    const double rho = r1 + r2 * std::cos(phi);
    const double u = rho * std::cos(theta), v = rho * std::sin(theta),
                 w = r2 * std::sin(phi);
    for(int k = 0; k < 3; k++)
      p[k] = f.o[k] + u * f.e[0][k] + v * f.e[1][k] + w * f.e[2][k];
  };
  // the distance of the centroids of the triangles of a band of quads (the
  // same at every theta) to the torus
  auto deviation = [&](int nt, int np) {
    double d = 0.;
    for(int j = 0; j < np; j++) {
      double p[4][3];
      point(0., 2. * pi * j / np, p[0]);
      point(2. * pi / nt, 2. * pi * j / np, p[1]);
      point(2. * pi / nt, 2. * pi * (j + 1) / np, p[2]);
      point(0., 2. * pi * (j + 1) / np, p[3]);
      static const int tri[2][3] = {{0, 1, 2}, {0, 2, 3}};
      for(auto &t : tri) {
        double c[3], q[3];
        for(int k = 0; k < 3; k++)
          c[k] = (p[t[0]][k] + p[t[1]][k] + p[t[2]][k]) / 3. - f.o[k];
        for(int k = 0; k < 3; k++)
          q[k] = c[0] * f.e[k][0] + c[1] * f.e[k][1] + c[2] * f.e[k][2];
        const double rho = std::sqrt(q[0] * q[0] + q[1] * q[1]);
        d = std::max(d, std::abs(std::sqrt((rho - r1) * (rho - r1) +
                                           q[2] * q[2]) - r2));
      }
    }
    return d;
  };
  int nt = circleDivisions(r1 + r2, tolerance / 2.);
  int np = circleDivisions(r2, tolerance / 2.);
  for(int pass = 0; pass < 10; pass++) {
    const double d = deviation(nt, np);
    if(d <= tolerance) break;
    const double factor = std::sqrt(d / tolerance) * 1.05;
    nt = (int)std::ceil(nt * factor);
    np = (int)std::ceil(np * factor);
    nt += nt % 2;
    np += np % 2;
  }
  std::vector<int> grid(nt * np);
  for(int i = 0; i < nt; i++)
    for(int j = 0; j < np; j++) {
      double p[3];
      point(2. * pi * i / nt, 2. * pi * j / np, p);
      grid[i * np + j] = _addNode(p[0], p[1], p[2]);
    }
  auto node = [&](int i, int j) { return grid[(i % nt) * np + j % np]; };
  // the vertices at theta in {0, pi} on the outer (phi = 0) and inner (phi =
  // pi) equators, the arcs of the equators between them
  int vertex[2][2], equator[2][2];
  for(int a = 0; a < 2; a++)
    for(int b = 0; b < 2; b++)
      vertex[a][b] = _addVertex(node(a * nt / 2, b * np / 2));
  for(int b = 0; b < 2; b++)
    for(int h = 0; h < 2; h++) {
      std::vector<int> nodes;
      for(int i = h * nt / 2; i <= (h + 1) * nt / 2; i++)
        nodes.push_back(node(i, b * np / 2));
      equator[b][h] = _addCurve(vertex[h][b], vertex[(h + 1) % 2][b], nodes);
    }
  // the two halves phi in [hp pi, (hp + 1) pi], their triangles oriented
  // outwards (d/dtheta x d/dphi), their loops counterclockwise in (theta, phi),
  // and their parameters: the angle theta and a radius exp(s), with s the
  // conformal coordinate of phi, ds = r2 dphi / (r1 + r2 cos phi) (a
  // conformal map of the half onto an annulus), its range limited to a factor
  // 4
  const double c = std::sqrt(r1 * r1 - r2 * r2);
  const double range = pi * r2 / c, maxRange = std::log(4.);
  const double lambda = range > maxRange ? maxRange / range : 1.;
  auto conformal = [&](double phi) {
    // phi in [-pi, pi]
    return std::abs(2. * r2 / c *
                    std::atan(std::sqrt((r1 - r2) / (r1 + r2)) *
                              std::tan(phi / 2.)));
  };
  Volume volume;
  for(int hp = 0; hp < 2; hp++) {
    std::vector<std::array<int, 3> > triangles;
    for(int i = 0; i < nt; i++)
      for(int j = hp * np / 2; j < (hp + 1) * np / 2; j++) {
        triangles.push_back({{node(i, j), node(i + 1, j), node(i + 1, j + 1)}});
        triangles.push_back({{node(i, j), node(i + 1, j + 1), node(i, j + 1)}});
      }
    const std::vector<int> loops = {
      equator[hp][0], equator[hp][1], -equator[(hp + 1) % 2][1],
      -equator[(hp + 1) % 2][0]};
    const int half = _addSurface(loops, triangles);
    std::map<int, std::array<double, 2> > uv;
    for(int i = 0; i < nt; i++)
      for(int j = hp * np / 2; j <= (hp + 1) * np / 2; j++) {
        const double theta = 2. * pi * i / nt;
        const double phi = 2. * pi * j / np - (hp ? 2. * pi : 0.);
        const double rho = std::exp(lambda * conformal(phi));
        uv[node(i, j)] = {{rho * std::cos(theta), rho * std::sin(theta)}};
      }
    _setUV(half, [&](int n) { return uv.at(n); });
    volume.surfaces.push_back(half);
  }
  _volumes[tag] = volume;
  return true;
}

void DiscreteCAD_Internals::_removeVolume(int tag)
{
  auto vit = _volumes.find(tag);
  if(vit == _volumes.end()) return;
  const std::vector<int> surfaces = vit->second.surfaces;
  _volumes.erase(vit);
  // the entities still used
  std::set<int> usedSurfaces, usedCurves, usedVertices;
  for(auto &v : _volumes)
    for(int s : v.second.surfaces) usedSurfaces.insert(std::abs(s));
  for(int s : surfaces)
    if(!usedSurfaces.count(std::abs(s))) _surfaces.erase(std::abs(s));
  for(auto &s : _surfaces) {
    for(int c : s.second.curves) usedCurves.insert(std::abs(c));
    for(int v : s.second.embeddedVertices) usedVertices.insert(v);
  }
  for(auto it = _curves.begin(); it != _curves.end();) {
    if(!usedCurves.count(it->first)) it = _curves.erase(it);
    else {
      usedVertices.insert(it->second.v0);
      usedVertices.insert(it->second.v1);
      ++it;
    }
  }
  for(auto it = _vertices.begin(); it != _vertices.end();) {
    if(!usedVertices.count(it->first)) it = _vertices.erase(it);
    else ++it;
  }
  _changed = true;
}

bool DiscreteCAD_Internals::booleanOperation(
  int op, const std::vector<std::pair<int, int> > &objectDimTags,
  const std::vector<std::pair<int, int> > &toolDimTags,
  std::vector<std::pair<int, int> > &outDimTags,
  std::vector<std::vector<std::pair<int, int> > > &outDimTagsMap, int tag,
  bool removeObject, bool removeTool)
{
  outDimTags.clear();
  outDimTagsMap.clear();

  // the triangulations of the volumes of each operand, oriented outwards,
  // with the input entity, surface and triangle each triangle comes from
  struct Origin {
    int input, surface;
    std::size_t triangle;
  };
  std::vector<Origin> origins;
  struct Triangulation {
    std::vector<double> xyz;
    std::vector<int> tri, origin;
  };
  std::vector<Triangulation> volumes[2];
  std::map<std::array<double, 3>, int> nodeOf;
  const std::vector<std::pair<int, int> > *operands[2] = {&objectDimTags,
                                                          &toolDimTags};
  int input = 0;
  std::vector<int> inputTag, inputOperand;
  for(int o = 0; o < 2; o++) {
    for(auto &dt : *operands[o]) {
      inputTag.push_back(dt.second);
      inputOperand.push_back(o);
      if(dt.first != 3 || !_volumes.count(dt.second)) {
        Msg::Error("Discrete CAD boolean operations apply to volumes: no "
                   "discrete CAD volume (%d, %d)",
                   dt.first, dt.second);
        return false;
      }
      Triangulation v;
      std::map<int, int> local;
      for(int s : _volumes[dt.second].surfaces) {
        const Surface &sf = _surfaces[std::abs(s)];
        for(std::size_t i = 0; i < sf.triangles.size(); i++) {
          std::array<int, 3> t = sf.triangles[i];
          if(s < 0) std::swap(t[1], t[2]);
          for(int n : t) {
            auto it = local.find(n);
            if(it == local.end()) {
              it = local.insert({n, (int)local.size()}).first;
              v.xyz.insert(v.xyz.end(), _nodes[n].begin(), _nodes[n].end());
              nodeOf[_nodes[n]] = n;
            }
            v.tri.push_back(it->second);
          }
          v.origin.push_back((int)origins.size());
          origins.push_back({input, std::abs(s), i});
        }
      }
      volumes[o].push_back(v);
      input++;
    }
  }
  if(volumes[0].empty() || volumes[1].empty()) return false;

  // the boolean operation of two triangulations: the volumes of each operand
  // fused first (each operation then has operands without
  // self-intersections), then the operation
  std::string error;
  auto boolean = [&](int o, const Triangulation &a, const Triangulation &b,
                     Triangulation &r) {
    std::vector<int> birth;
    if(!meshBoolean(o, a.xyz, a.tri, b.xyz, b.tri, r.xyz, r.tri, birth,
                    error))
      return false;
    const std::size_t na = a.tri.size() / 3;
    r.origin.resize(birth.size());
    for(std::size_t i = 0; i < birth.size(); i++)
      r.origin[i] = (std::size_t)birth[i] < na ? a.origin[birth[i]] :
                                                 b.origin[birth[i] - na];
    return true;
  };
  Triangulation operand[2], result;
  bool ok = true;
  for(int o = 0; o < 2 && ok; o++) {
    operand[o] = volumes[o][0];
    for(std::size_t k = 1; k < volumes[o].size() && ok; k++) {
      Triangulation r;
      ok = boolean(0, operand[o], volumes[o][k], r);
      operand[o] = r;
    }
  }
  if(ok) ok = boolean(op, operand[0], operand[1], result);
  if(!ok) {
    Msg::Error("Discrete CAD boolean operation: %s", error.c_str());
    return false;
  }
  std::vector<double> rxyz = result.xyz;
  std::vector<int> rtri = result.tri, birth = result.origin;

  // the nodes of the result: those of the operands kept, new ones elsewhere
  std::vector<int> rnode(rxyz.size() / 3);
  for(std::size_t v = 0; v < rnode.size(); v++) {
    const std::array<double, 3> p = {
      {rxyz[3 * v], rxyz[3 * v + 1], rxyz[3 * v + 2]}};
    auto it = nodeOf.find(p);
    rnode[v] = it != nodeOf.end() ? it->second : _addNode(p[0], p[1], p[2]);
  }
  // the nodes closer than the rounding of the exact result merged (the oldest
  // kept): its clusters of nodes where the operands touch each other, which
  // would make the triangles of the next operations degenerate; the
  // triangles degenerate or folded onto each other then removed
  double lo[3] = {1e300, 1e300, 1e300}, hi[3] = {-1e300, -1e300, -1e300};
  for(std::size_t v = 0; v < rnode.size(); v++)
    for(int k = 0; k < 3; k++) {
      lo[k] = std::min(lo[k], rxyz[3 * v + k]);
      hi[k] = std::max(hi[k], rxyz[3 * v + k]);
    }
  const double merge =
    1.e-12 * std::sqrt((hi[0] - lo[0]) * (hi[0] - lo[0]) +
                       (hi[1] - lo[1]) * (hi[1] - lo[1]) +
                       (hi[2] - lo[2]) * (hi[2] - lo[2]));
  std::map<int, int> merged;
  std::function<int(int)> representative = [&](int n) {
    auto it = merged.find(n);
    if(it == merged.end() || it->second == n) return n;
    return it->second = representative(it->second);
  };
  for(std::size_t i = 0; i < rtri.size() / 3; i++)
    for(int k = 0; k < 3; k++) {
      int a = representative(rnode[rtri[3 * i + k]]);
      int b = representative(rnode[rtri[3 * i + (k + 1) % 3]]);
      if(a == b) continue;
      const std::array<double, 3> &x = _nodes[a], &y = _nodes[b];
      if(std::abs(x[0] - y[0]) + std::abs(x[1] - y[1]) +
           std::abs(x[2] - y[2]) > merge)
        continue;
      if(a > b) std::swap(a, b);
      merged[b] = a;
    }
  std::vector<std::array<int, 3> > triangles;
  std::vector<int> kept;
  std::map<std::array<int, 3>, std::size_t> sorted;
  for(std::size_t i = 0; i < birth.size(); i++) {
    std::array<int, 3> t;
    for(int k = 0; k < 3; k++) t[k] = representative(rnode[rtri[3 * i + k]]);
    if(t[0] == t[1] || t[1] == t[2] || t[2] == t[0]) continue;
    std::array<int, 3> key = t;
    std::sort(key.begin(), key.end());
    auto it = sorted.find(key);
    if(it != sorted.end()) {
      // a triangle folded onto another one: both removed if they are
      // opposite
      const std::array<int, 3> &u = triangles[it->second];
      int k = 0;
      while(u[k] != t[0]) k++;
      if(u[(k + 1) % 3] != t[1]) kept[it->second] = -1;
      continue;
    }
    sorted[key] = triangles.size();
    triangles.push_back(t);
    kept.push_back(birth[i]);
  }
  {
    std::size_t j = 0;
    for(std::size_t i = 0; i < triangles.size(); i++) {
      if(kept[i] < 0) continue;
      triangles[j] = triangles[i];
      kept[j++] = kept[i];
    }
    triangles.resize(j);
    kept.resize(j);
    birth = kept;
  }
  const std::size_t nt = birth.size();

  // the parameters of the corners: those of the nodes of the triangle each
  // one comes from, if its surface has parameters, or interpolated along its
  // edge the corner is on (the same on both sides of the edge, whatever the
  // shape of the triangles), or else inside it
  std::vector<std::array<std::array<double, 2>, 3> > uv(nt);
  std::vector<char> hasUV(nt, 0);
  for(std::size_t i = 0; i < nt; i++) {
    const Origin &og = origins[birth[i]];
    const Surface &sf = _surfaces[og.surface];
    if(sf.uv.empty()) continue;
    hasUV[i] = 1;
    const std::array<int, 3> &t = sf.triangles[og.triangle];
    const std::array<std::array<double, 2>, 3> &tuv = sf.uv[og.triangle];
    double longest = 0.;
    for(int k = 0; k < 3; k++) {
      const std::array<double, 3> &x = _nodes[t[k]], &y = _nodes[t[(k + 1) % 3]];
      longest = std::max(longest, std::sqrt((y[0] - x[0]) * (y[0] - x[0]) +
                                            (y[1] - x[1]) * (y[1] - x[1]) +
                                            (y[2] - x[2]) * (y[2] - x[2])));
    }
    for(int k = 0; k < 3; k++) {
      const int n = triangles[i][k];
      const std::array<double, 3> &p = _nodes[n];
      int j = 0;
      while(j < 3 && t[j] != n) j++;
      if(j < 3) {
        uv[i][k] = tuv[j];
        continue;
      }
      // the nearest edge, its nodes in increasing order
      double nearest = 1e300, along = 0.;
      int a = 0, b = 1;
      for(int e = 0; e < 3; e++) {
        int ea = e, eb = (e + 1) % 3;
        if(t[ea] > t[eb]) std::swap(ea, eb);
        const std::array<double, 3> &x = _nodes[t[ea]], &y = _nodes[t[eb]];
        double l = 0., d2 = 0.;
        for(int m = 0; m < 3; m++) {
          l += (p[m] - x[m]) * (y[m] - x[m]);
          d2 += (y[m] - x[m]) * (y[m] - x[m]);
        }
        l = d2 ? std::min(1., std::max(0., l / d2)) : 0.;
        double d = 0.;
        for(int m = 0; m < 3; m++) {
          const double q = x[m] + l * (y[m] - x[m]) - p[m];
          d += q * q;
        }
        if(d < nearest) {
          nearest = d;
          along = l;
          a = ea;
          b = eb;
        }
      }
      if(std::sqrt(nearest) <= 1.e-9 * longest) {
        for(int m = 0; m < 2; m++)
          uv[i][k][m] = (1. - along) * tuv[a][m] + along * tuv[b][m];
        continue;
      }
      double e1[3], e2[3], d[3];
      for(int m = 0; m < 3; m++) {
        e1[m] = _nodes[t[1]][m] - _nodes[t[0]][m];
        e2[m] = _nodes[t[2]][m] - _nodes[t[0]][m];
        d[m] = p[m] - _nodes[t[0]][m];
      }
      const double a11 = e1[0] * e1[0] + e1[1] * e1[1] + e1[2] * e1[2];
      const double a12 = e1[0] * e2[0] + e1[1] * e2[1] + e1[2] * e2[2];
      const double a22 = e2[0] * e2[0] + e2[1] * e2[1] + e2[2] * e2[2];
      const double b1 = d[0] * e1[0] + d[1] * e1[1] + d[2] * e1[2];
      const double b2 = d[0] * e2[0] + d[1] * e2[1] + d[2] * e2[2];
      const double det = a11 * a22 - a12 * a12;
      const double l1 = det ? (a22 * b1 - a12 * b2) / det : 0.;
      const double l2 = det ? (a11 * b2 - a12 * b1) / det : 0.;
      for(int m = 0; m < 2; m++)
        uv[i][k][m] =
          (1. - l1 - l2) * tuv[0][m] + l1 * tuv[1][m] + l2 * tuv[2][m];
    }
  }

  // the surfaces, curves and vertices of the result: the triangles coming
  // from the same surface, connected
  std::vector<int> label(nt), surfaceOf;
  for(std::size_t i = 0; i < nt; i++) label[i] = origins[birth[i]].surface;
  _addTopology(triangles, label, uv, hasUV, pi, surfaceOf);

  // the operands removed before the volumes are created (one of them can
  // take the tag of an operand)
  if(removeObject)
    for(auto &dt : objectDimTags) _removeVolume(dt.second);
  if(removeTool)
    for(auto &dt : toolDimTags) _removeVolume(dt.second);

  // the volumes, their tags: the one given for the first, or that of the
  // only removed object they come from, or else of the only removed tool
  std::map<int, std::set<int> > inputsOfSurface;
  for(std::size_t i = 0; i < nt; i++)
    inputsOfSurface[surfaceOf[i]].insert(origins[birth[i]].input);
  for(auto &cell : _cells(triangles, surfaceOf)) {
    int t = (tag > 0 && outDimTags.empty()) ? tag : -1;
    std::set<int> from;
    for(int s : cell[0]) {
      const std::set<int> &in = inputsOfSurface[std::abs(s)];
      from.insert(in.begin(), in.end());
    }
    for(int o = 0; o < 2 && t < 0; o++) {
      if(!(o ? removeTool : removeObject)) continue;
      std::set<int> tags;
      for(int i : from)
        if(inputOperand[i] == o) tags.insert(inputTag[i]);
      if(tags.size() == 1 && !_exists(3, *tags.begin())) t = *tags.begin();
    }
    if(!_assignTag(3, t)) {
      t = -1;
      _assignTag(3, t);
    }
    _volumes[t] = Volume();
    for(auto &shell : cell)
      for(int s : shell) _volumes[t].surfaces.push_back(s);
    outDimTags.push_back({3, t});
  }

  // the resulting volumes coming from each input entity
  outDimTagsMap.resize(input);
  std::map<int, int> volumeOfSurface;
  for(auto &v : outDimTags)
    for(int s : _volumes[v.second].surfaces)
      volumeOfSurface[std::abs(s)] = v.second;
  std::vector<std::set<int> > from(input);
  for(std::size_t i = 0; i < nt; i++) {
    auto it = volumeOfSurface.find(surfaceOf[i]);
    if(it != volumeOfSurface.end()) from[origins[birth[i]].input].insert(it->second);
  }
  for(int i = 0; i < input; i++)
    for(int v : from[i]) outDimTagsMap[i].push_back({3, v});

  _changed = true;
  return true;
}

void DiscreteCAD_Internals::_addTopology(
  const std::vector<std::array<int, 3> > &triangles,
  const std::vector<int> &label,
  std::vector<std::array<std::array<double, 2>, 3> > &uv,
  const std::vector<char> &hasUV, double curveAngle,
  std::vector<int> &surfaceOf)
{
  const std::size_t nt = triangles.size();

  // the surfaces: the triangles of the same label, connected
  std::map<std::pair<int, int>, std::vector<std::size_t> > edgeTriangles;
  for(std::size_t i = 0; i < nt; i++)
    for(int k = 0; k < 3; k++)
      edgeTriangles[std::minmax(triangles[i][k], triangles[i][(k + 1) % 3])]
        .push_back(i);
  std::vector<std::size_t> parent(nt);
  for(std::size_t i = 0; i < nt; i++) parent[i] = i;
  std::function<std::size_t(std::size_t)> find = [&](std::size_t i) {
    while(parent[i] != i) i = parent[i] = parent[parent[i]];
    return i;
  };
  for(auto &e : edgeTriangles)
    if(e.second.size() == 2 && label[e.second[0]] == label[e.second[1]])
      parent[find(e.second[0])] = find(e.second[1]);
  std::map<std::size_t, int> surfaceOfRoot;
  surfaceOf.assign(nt, 0);
  for(std::size_t i = 0; i < nt; i++) {
    const std::size_t r = find(i);
    auto it = surfaceOfRoot.find(r);
    if(it == surfaceOfRoot.end()) {
      int t = -1;
      _assignTag(2, t);
      _surfaces[t] = Surface();
      it = surfaceOfRoot.insert({r, t}).first;
    }
    surfaceOf[i] = it->second;
    _surfaces[it->second].triangles.push_back(triangles[i]);
  }

  // the edges of the curves: between different surfaces, or where the
  // parameters of a surface jump (its seam)
  auto cornerUV = [&](std::size_t i, int n) {
    int k = 0;
    while(k < 2 && triangles[i][k] != n) k++;
    return uv[i][k];
  };
  auto jumps = [&](std::size_t i, std::size_t j, int a, int b) {
    if(!hasUV[i] || !hasUV[j]) return false;
    for(int n : {a, b}) {
      const std::array<double, 2> p = cornerUV(i, n), q = cornerUV(j, n);
      const double d = std::abs(p[0] - q[0]) + std::abs(p[1] - q[1]);
      if(d > 1.e-9 * (1. + std::abs(p[0]) + std::abs(p[1]))) return true;
    }
    return false;
  };
  // the parameters made continuous across the seam of a surface that does not
  // go around it: the pieces of the surface on both sides of the seam (the
  // connected triangles with continuous parameters) moved onto each other by
  // the isometry of the plane given by the seam
  std::vector<std::size_t> piece(nt);
  for(std::size_t i = 0; i < nt; i++) piece[i] = i;
  std::function<std::size_t(std::size_t)> findPiece = [&](std::size_t i) {
    while(piece[i] != i) i = piece[i] = piece[piece[i]];
    return i;
  };
  struct Link {
    std::size_t a, b;
    int na, nb;
    double length;
  };
  std::vector<Link> links;
  for(auto &e : edgeTriangles) {
    const std::vector<std::size_t> &t = e.second;
    if(t.size() != 2 || surfaceOf[t[0]] != surfaceOf[t[1]] || !hasUV[t[0]])
      continue;
    if(!jumps(t[0], t[1], e.first.first, e.first.second))
      piece[findPiece(t[0])] = findPiece(t[1]);
    else {
      const std::array<double, 2> p = cornerUV(t[0], e.first.first),
                                  q = cornerUV(t[0], e.first.second);
      links.push_back({t[0], t[1], e.first.first, e.first.second,
                       std::hypot(q[0] - p[0], q[1] - p[1])});
    }
  }
  std::sort(links.begin(), links.end(), [](const Link &l, const Link &m) {
    return l.length > m.length;
  });
  std::map<std::size_t, std::vector<std::size_t> > trianglesOfPiece;
  for(std::size_t i = 0; i < nt; i++)
    if(hasUV[i]) trianglesOfPiece[findPiece(i)].push_back(i);
  std::map<std::size_t, std::vector<const Link *> > linksOfPiece;
  for(auto &l : links) {
    linksOfPiece[findPiece(l.a)].push_back(&l);
    linksOfPiece[findPiece(l.b)].push_back(&l);
  }
  std::set<std::size_t> placed;
  std::vector<std::pair<std::size_t, std::size_t> > pieces; // size, root
  for(auto &p : trianglesOfPiece) pieces.push_back({p.second.size(), p.first});
  std::sort(pieces.rbegin(), pieces.rend());
  for(auto &p : pieces) {
    if(placed.count(p.second)) continue;
    placed.insert(p.second);
    std::vector<std::size_t> queue = {p.second};
    while(!queue.empty()) {
      const std::size_t c = queue.back();
      queue.pop_back();
      for(const Link *l : linksOfPiece[c]) {
        // the triangle along the link on the placed side, and on the other
        const bool aPlaced = findPiece(l->a) == c;
        const std::size_t ti = aPlaced ? l->a : l->b, tj = aPlaced ? l->b : l->a;
        const std::size_t d = findPiece(tj);
        if(placed.count(d)) continue;
        const std::array<double, 2> pa = cornerUV(ti, l->na),
                                    pb = cornerUV(ti, l->nb),
                                    qa = cornerUV(tj, l->na),
                                    qb = cornerUV(tj, l->nb);
        const double angle =
          std::atan2(pb[1] - pa[1], pb[0] - pa[0]) -
          std::atan2(qb[1] - qa[1], qb[0] - qa[0]);
        const double c0 = std::cos(angle), s0 = std::sin(angle);
        const double tx = pa[0] - (c0 * qa[0] - s0 * qa[1]);
        const double ty = pa[1] - (s0 * qa[0] + c0 * qa[1]);
        for(std::size_t i : trianglesOfPiece[d])
          for(auto &q : uv[i])
            q = {{c0 * q[0] - s0 * q[1] + tx, s0 * q[0] + c0 * q[1] + ty}};
        placed.insert(d);
        queue.push_back(d);
      }
    }
  }
  for(auto &s : surfaceOfRoot) _surfaces[s.second].uv.clear();
  for(std::size_t i = 0; i < nt; i++)
    if(hasUV[i]) _surfaces[surfaceOf[i]].uv.push_back(uv[i]);
  for(auto &s : surfaceOfRoot) {
    Surface &sf = _surfaces[s.second];
    if(sf.uv.size() != sf.triangles.size()) sf.uv.clear();
  }

  std::map<std::pair<int, int>, bool> special; // edge -> is a seam
  std::map<int, std::vector<int> > neighbors;
  for(auto &e : edgeTriangles) {
    const std::vector<std::size_t> &t = e.second;
    bool feature = t.size() != 2 || surfaceOf[t[0]] != surfaceOf[t[1]];
    bool seam = !feature && jumps(t[0], t[1], e.first.first, e.first.second);
    if(!feature && !seam) continue;
    special[e.first] = seam;
    neighbors[e.first.first].push_back(e.first.second);
    neighbors[e.first.second].push_back(e.first.first);
  }

  // the curves: chains of these edges between the nodes where more or less
  // than two of them meet or where they turn by more than curveAngle, closed
  // chains split in two arcs at the nodes where they turn the most
  auto turn = [&](int p, int n, int q) {
    const std::array<double, 3> &a = _nodes[p], &x = _nodes[n],
                                &b = _nodes[q];
    double uv = 0., uu = 0., vv = 0.;
    for(int k = 0; k < 3; k++) {
      uv += (x[k] - a[k]) * (b[k] - x[k]);
      uu += (x[k] - a[k]) * (x[k] - a[k]);
      vv += (b[k] - x[k]) * (b[k] - x[k]);
    }
    if(uu == 0. || vv == 0.) return 0.;
    return std::acos(std::max(-1., std::min(1., uv / std::sqrt(uu * vv))));
  };
  auto corner = [&](int n) {
    const std::vector<int> &nb = neighbors[n];
    return nb.size() != 2 || turn(nb[0], n, nb[1]) > curveAngle;
  };
  std::map<int, int> vertexOf;
  auto vertex = [&](int n) {
    auto it = vertexOf.find(n);
    if(it == vertexOf.end()) it = vertexOf.insert({n, _addVertex(n)}).first;
    return it->second;
  };
  std::set<std::pair<int, int> > visited;
  std::map<std::pair<int, int>, int> curveOfEdge; // directed edge -> +-curve
  auto addChain = [&](const std::vector<int> &nodes) {
    const int c =
      _addCurve(vertex(nodes.front()), vertex(nodes.back()), nodes);
    for(std::size_t j = 0; j + 1 < nodes.size(); j++) {
      curveOfEdge[{nodes[j], nodes[j + 1]}] = c;
      curveOfEdge[{nodes[j + 1], nodes[j]}] = -c;
    }
  };
  auto walk = [&](int a, int b) {
    std::vector<int> nodes = {a, b};
    visited.insert(std::minmax(a, b));
    while(!corner(nodes.back()) && nodes.back() != nodes.front()) {
      const int last = nodes.back(), previous = nodes[nodes.size() - 2];
      const int next = neighbors[last][0] == previous ? neighbors[last][1] :
                                                       neighbors[last][0];
      if(visited.count(std::minmax(last, next))) break;
      visited.insert(std::minmax(last, next));
      nodes.push_back(next);
    }
    return nodes;
  };
  for(auto &nb : neighbors) {
    if(!corner(nb.first)) continue;
    for(int b : nb.second)
      if(!visited.count(std::minmax(nb.first, b)))
        addChain(walk(nb.first, b));
  }
  for(auto &nb : neighbors)
    for(int b : nb.second)
      if(!visited.count(std::minmax(nb.first, b))) {
        std::vector<int> loop = walk(nb.first, b);
        // the node where it turns the most, and the one where it turns the
        // most at least a quarter of the loop away
        const std::size_t n = loop.size() - 1;
        std::vector<double> angle(n);
        for(std::size_t i = 0; i < n; i++)
          angle[i] = turn(loop[(i + n - 1) % n], loop[i], loop[i + 1]);
        std::size_t first = 0;
        for(std::size_t i = 1; i < n; i++)
          if(angle[i] > angle[first]) first = i;
        std::size_t second = (first + n / 2) % n;
        for(std::size_t i = 0; i < n; i++) {
          const std::size_t d = (i + n - first) % n;
          if(std::min(d, n - d) >= std::max<std::size_t>(1, n / 4) &&
             angle[i] > angle[second])
            second = i;
        }
        std::vector<int> arc[2];
        for(std::size_t i = first;; i = (i + 1) % n) {
          arc[0].push_back(loop[i]);
          if(i == second) break;
        }
        for(std::size_t i = second;; i = (i + 1) % n) {
          arc[1].push_back(loop[i]);
          if(i == first) break;
        }
        addChain(arc[0]);
        addChain(arc[1]);
      }

  // the curves of the surfaces, oriented as their triangles, their seams
  // twice, with their parameters on their two sides: from the triangles along
  // them in their direction (side 0) and in the other one
  for(auto &s : surfaceOfRoot) {
    Surface &sf = _surfaces[s.second];
    std::set<int> curves;
    for(std::size_t i = 0; i < nt; i++) {
      if(surfaceOf[i] != s.second) continue;
      for(int k = 0; k < 3; k++) {
        const int a = triangles[i][k], b = triangles[i][(k + 1) % 3];
        auto it = curveOfEdge.find({a, b});
        if(it == curveOfEdge.end()) continue;
        const int c = std::abs(it->second);
        if(!curves.insert(c).second) continue;
        if(special[std::minmax(a, b)]) {
          sf.curves.push_back(c);
          sf.curves.push_back(-c);
          sf.seams[c];
        }
        else
          sf.curves.push_back(it->second);
      }
    }
    for(auto &sm : sf.seams) {
      const std::vector<int> &n = _curves[sm.first].nodes;
      for(int side = 0; side < 2; side++) sm.second[side].resize(n.size());
      for(std::size_t j = 0; j + 1 < n.size(); j++)
        for(std::size_t i : edgeTriangles[std::minmax(n[j], n[j + 1])]) {
          int k = 0;
          while(k < 3 && triangles[i][k] != n[j]) k++;
          const int side = triangles[i][(k + 1) % 3] == n[j + 1] ? 0 : 1;
          sm.second[side][j] = cornerUV(i, n[j]);
          sm.second[side][j + 1] = cornerUV(i, n[j + 1]);
        }
    }
  }
}

std::vector<std::vector<std::vector<int> > >
DiscreteCAD_Internals::_cells(const std::vector<std::array<int, 3> > &triangles,
                              const std::vector<int> &surfaceOf) const
{
  const std::size_t nt = triangles.size();
  std::map<std::pair<int, int>, std::vector<std::size_t> > edgeTriangles;
  for(std::size_t i = 0; i < nt; i++)
    for(int k = 0; k < 3; k++)
      edgeTriangles[std::minmax(triangles[i][k], triangles[i][(k + 1) % 3])]
        .push_back(i);
  // the connected pieces of the triangulation, and its shells: the sides of
  // the triangles (2 i behind triangle i, its normal pointing out of the cell
  // on that side, 2 i + 1 in front of it) facing the same cell, joined around
  // their edges
  std::vector<std::size_t> piece(nt), side(2 * nt);
  for(std::size_t i = 0; i < nt; i++) piece[i] = i;
  for(std::size_t i = 0; i < 2 * nt; i++) side[i] = i;
  auto find = [](std::vector<std::size_t> &parent, std::size_t i) {
    while(parent[i] != i) i = parent[i] = parent[parent[i]];
    return i;
  };
  auto along = [&](std::size_t i, int a, int b) {
    for(int k = 0; k < 3; k++)
      if(triangles[i][k] == a) return triangles[i][(k + 1) % 3] == b;
    return false;
  };
  for(auto &e : edgeTriangles) {
    const int a = e.first.first, b = e.first.second;
    std::vector<std::size_t> t = e.second;
    if(t.size() > 2) {
      // around the edge, by increasing angle of their third node
      const std::array<double, 3> &pa = _nodes[a], &pb = _nodes[b];
      double z[3] = {pb[0] - pa[0], pb[1] - pa[1], pb[2] - pa[2]};
      normalize(z);
      int m = 0;
      for(int k = 1; k < 3; k++)
        if(std::abs(z[k]) < std::abs(z[m])) m = k;
      double x[3] = {0., 0., 0.};
      x[m] = 1.;
      const double d = z[m];
      for(int k = 0; k < 3; k++) x[k] -= d * z[k];
      normalize(x);
      const double y[3] = {z[1] * x[2] - z[2] * x[1], z[2] * x[0] - z[0] * x[2],
                           z[0] * x[1] - z[1] * x[0]};
      std::vector<std::pair<double, std::size_t> > angles;
      for(std::size_t i : t) {
        int c = triangles[i][0];
        for(int k = 1; k < 3 && (c == a || c == b); k++) c = triangles[i][k];
        double u = 0., v = 0.;
        for(int k = 0; k < 3; k++) {
          u += (_nodes[c][k] - pa[k]) * x[k];
          v += (_nodes[c][k] - pa[k]) * y[k];
        }
        angles.push_back({std::atan2(v, u), i});
      }
      std::sort(angles.begin(), angles.end());
      for(std::size_t k = 0; k < t.size(); k++) t[k] = angles[k].second;
    }
    // the sides facing the cell between two consecutive triangles i and j: in
    // front of i if it goes from a to b, in front of j if it goes from b to a
    for(std::size_t k = 0; k < t.size(); k++) {
      const std::size_t i = t[k], j = t[(k + 1) % t.size()];
      side[find(side, 2 * i + (along(i, a, b) ? 1 : 0))] =
        find(side, 2 * j + (along(j, b, a) ? 1 : 0));
      piece[find(piece, i)] = find(piece, j);
    }
  }

  // the shells, their pieces, bounding boxes and volumes, and the volumes
  // enclosed by their triangles as oriented (the triangles with both sides in
  // a shell do not bound it)
  struct Shell {
    std::vector<std::size_t> sides;
    std::size_t piece;
    double volume, oriented, lo[3], hi[3];
  };
  std::vector<Shell> shells;
  std::map<std::size_t, std::size_t> shellOf;
  for(std::size_t s = 0; s < 2 * nt; s++) {
    auto it = shellOf.insert({find(side, s), shells.size()}).first;
    if(it->second == shells.size()) {
      shells.push_back(Shell());
      shells.back().piece = find(piece, s / 2);
    }
    shells[it->second].sides.push_back(s);
  }
  auto bounds = [&](std::size_t i) {
    return find(side, 2 * i) != find(side, 2 * i + 1);
  };
  for(Shell &sh : shells) {
    const std::array<double, 3> &o = _nodes[triangles[sh.sides[0] / 2][0]];
    sh.volume = sh.oriented = 0.;
    for(int k = 0; k < 3; k++) {
      sh.lo[k] = 1e300;
      sh.hi[k] = -1e300;
    }
    for(std::size_t s : sh.sides) {
      const std::array<int, 3> &t = triangles[s / 2];
      for(int n : t)
        for(int k = 0; k < 3; k++) {
          sh.lo[k] = std::min(sh.lo[k], _nodes[n][k]);
          sh.hi[k] = std::max(sh.hi[k], _nodes[n][k]);
        }
      if(!bounds(s / 2)) continue;
      double p[3][3];
      for(int j = 0; j < 3; j++)
        for(int k = 0; k < 3; k++) p[j][k] = _nodes[t[j]][k] - o[k];
      const double v = (p[0][0] * (p[1][1] * p[2][2] - p[1][2] * p[2][1]) -
                        p[0][1] * (p[1][0] * p[2][2] - p[1][2] * p[2][0]) +
                        p[0][2] * (p[1][0] * p[2][1] - p[1][1] * p[2][0])) /
                       6.;
      sh.volume += s % 2 ? -v : v;
      sh.oriented += v;
    }
  }
  // the winding number of a shell around a point
  auto winding = [&](const Shell &sh, const double p[3]) {
    double w = 0.;
    for(std::size_t s : sh.sides) {
      if(!bounds(s / 2)) continue;
      const std::array<int, 3> &t = triangles[s / 2];
      double a[3], b[3], c[3];
      for(int k = 0; k < 3; k++) {
        a[k] = _nodes[t[0]][k] - p[k];
        b[k] = _nodes[t[1]][k] - p[k];
        c[k] = _nodes[t[2]][k] - p[k];
      }
      const double la = std::sqrt(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);
      const double lb = std::sqrt(b[0] * b[0] + b[1] * b[1] + b[2] * b[2]);
      const double lc = std::sqrt(c[0] * c[0] + c[1] * c[1] + c[2] * c[2]);
      const double det = a[0] * (b[1] * c[2] - b[2] * c[1]) -
                         a[1] * (b[0] * c[2] - b[2] * c[0]) +
                         a[2] * (b[0] * c[1] - b[1] * c[0]);
      const double den = la * lb * lc +
                         (a[0] * b[0] + a[1] * b[1] + a[2] * b[2]) * lc +
                         (a[0] * c[0] + a[1] * c[1] + a[2] * c[2]) * lb +
                         (b[0] * c[0] + b[1] * c[1] + b[2] * c[2]) * la;
      const double angle = 2. * std::atan2(det, den);
      w += s % 2 ? -angle : angle;
    }
    return w / (4. * pi);
  };

  // the cells: the shells of positive volume; the others, of negative volume,
  // bound the space around a piece, inside the smallest cell of another piece
  // around them, if any
  std::map<std::size_t, std::size_t> around; // shell of negative volume -> cell
  std::map<std::size_t, std::size_t> outside; // piece -> its largest such shell
  for(std::size_t n = 0; n < shells.size(); n++) {
    const Shell &sh = shells[n];
    if(sh.volume >= 0.) continue;
    auto o = outside.find(sh.piece);
    if(o == outside.end() || shells[o->second].volume > sh.volume)
      outside[sh.piece] = n;
    std::size_t i = 0;
    while(!bounds(sh.sides[i] / 2)) i++;
    const std::array<int, 3> &t = triangles[sh.sides[i] / 2];
    double p[3];
    for(int k = 0; k < 3; k++)
      p[k] = (_nodes[t[0]][k] + _nodes[t[1]][k] + _nodes[t[2]][k]) / 3.;
    double smallest = 1e300;
    for(std::size_t c = 0; c < shells.size(); c++) {
      const Shell &cl = shells[c];
      if(cl.volume <= 0. || cl.piece == sh.piece || cl.volume >= smallest)
        continue;
      bool in = true;
      for(int k = 0; k < 3; k++)
        if(p[k] < cl.lo[k] || p[k] > cl.hi[k]) in = false;
      if(!in || winding(cl, p) < 0.5) continue;
      smallest = cl.volume;
      around[n] = c;
    }
  }
  // the cells of a piece are volumes if the space around it is in no cell,
  // or if its triangles point out of it (around it, as oriented, they enclose
  // a positive volume), holes otherwise
  auto isSolid = [&](std::size_t pc) {
    auto o = outside.find(pc);
    if(o == outside.end() || !around.count(o->second)) return true;
    return shells[o->second].oriented > 0.;
  };

  // the signed surfaces of a shell (those on both sides of it left out)
  auto surfaces = [&](const Shell &sh) {
    std::map<int, int> signOf;
    for(std::size_t s : sh.sides) {
      const int sf = surfaceOf[s / 2], sign = s % 2 ? -1 : 1;
      auto it = signOf.insert({sf, sign}).first;
      if(it->second != sign) it->second = 0;
    }
    std::vector<int> r;
    for(auto &sg : signOf) {
      if(sg.second)
        r.push_back(sg.second * sg.first);
      else
        Msg::Warning("Discrete CAD surface %d inside a volume, not on its "
                     "boundary: ignored",
                     sg.first);
    }
    return r;
  };
  std::map<std::size_t, std::size_t> volumeOf; // cell -> volume
  std::vector<std::vector<std::vector<int> > > volumes;
  for(std::size_t c = 0; c < shells.size(); c++) {
    if(shells[c].volume <= 0. || !isSolid(shells[c].piece)) continue;
    std::vector<int> outer = surfaces(shells[c]);
    if(outer.empty()) continue;
    volumeOf[c] = volumes.size();
    volumes.push_back({outer});
  }
  // the shells around the pieces inside a volume, the holes and the volumes
  // in it
  for(auto &a : around) {
    auto v = volumeOf.find(a.second);
    if(v != volumeOf.end())
      volumes[v->second].push_back(surfaces(shells[a.first]));
  }
  // in the order of their surfaces
  std::sort(volumes.begin(), volumes.end(),
            [](const std::vector<std::vector<int> > &v,
               const std::vector<std::vector<int> > &w) {
              return std::abs(v[0][0]) < std::abs(w[0][0]);
            });
  return volumes;
}

bool DiscreteCAD_Internals::addTriangulation(
  const std::vector<double> &coord, const std::vector<std::size_t> &triangles,
  const std::vector<int> &pieces, double angle, double curveAngle,
  double tolerance, std::vector<std::pair<int, int> > &outDimTags)
{
  outDimTags.clear();
  const std::size_t nn = coord.size() / 3;
  if(coord.size() % 3 || triangles.size() % 3 ||
     (!pieces.empty() && pieces.size() != triangles.size() / 3)) {
    Msg::Error("Discrete CAD triangulation: %lu coordinates, %lu node "
               "indices and %lu pieces",
               coord.size(), triangles.size(), pieces.size());
    return false;
  }
  for(std::size_t n : triangles) {
    if(n < nn) continue;
    Msg::Error("Discrete CAD triangulation: unknown node %lu", n);
    return false;
  }

  // the nodes, those at the same coordinates merged; the triangles, without
  // the degenerate ones and the copies
  std::map<std::array<double, 3>, int> nodeOf;
  std::vector<int> node(nn, -1);
  std::vector<std::array<int, 3> > tri;
  std::vector<int> piece;
  std::set<std::array<int, 3> > sorted;
  std::size_t degenerate = 0, copies = 0;
  for(std::size_t i = 0; i < triangles.size() / 3; i++) {
    std::array<int, 3> t;
    for(int k = 0; k < 3; k++) {
      const std::size_t n = triangles[3 * i + k];
      if(node[n] < 0) {
        const std::array<double, 3> p = {
          {coord[3 * n], coord[3 * n + 1], coord[3 * n + 2]}};
        auto it = nodeOf.find(p);
        if(it == nodeOf.end())
          it = nodeOf.insert({p, _addNode(p[0], p[1], p[2])}).first;
        node[n] = it->second;
      }
      t[k] = node[n];
    }
    if(t[0] == t[1] || t[1] == t[2] || t[2] == t[0]) {
      degenerate++;
      continue;
    }
    std::array<int, 3> key = t;
    std::sort(key.begin(), key.end());
    if(!sorted.insert(key).second) {
      copies++;
      continue;
    }
    tri.push_back(t);
    piece.push_back(pieces.empty() ? 0 : pieces[i]);
  }
  if(degenerate || copies)
    Msg::Warning("Discrete CAD triangulation: %lu degenerate and %lu "
                 "duplicate triangles ignored",
                 degenerate, copies);
  const std::size_t nt = tri.size();
  if(!nt) {
    Msg::Error("Discrete CAD triangulation without triangles");
    return false;
  }

  // the triangles oriented as their neighbors across the edges of two
  // triangles
  std::map<std::pair<int, int>, std::vector<std::size_t> > edgeTriangles;
  for(std::size_t i = 0; i < nt; i++)
    for(int k = 0; k < 3; k++)
      edgeTriangles[std::minmax(tri[i][k], tri[i][(k + 1) % 3])].push_back(i);
  auto along = [&](std::size_t i, int a, int b) {
    for(int k = 0; k < 3; k++)
      if(tri[i][k] == a) return tri[i][(k + 1) % 3] == b;
    return false;
  };
  std::vector<char> oriented(nt, 0);
  bool orientable = true;
  for(std::size_t first = 0; first < nt; first++) {
    if(oriented[first]) continue;
    oriented[first] = 1;
    std::vector<std::size_t> stack = {first};
    while(!stack.empty()) {
      const std::size_t i = stack.back();
      stack.pop_back();
      for(int k = 0; k < 3; k++) {
        const int a = tri[i][k], b = tri[i][(k + 1) % 3];
        const std::vector<std::size_t> &et = edgeTriangles[std::minmax(a, b)];
        if(et.size() != 2) continue;
        const std::size_t j = et[0] == i ? et[1] : et[0];
        const bool consistent = along(j, b, a);
        if(!oriented[j]) {
          if(!consistent) std::swap(tri[j][1], tri[j][2]);
          oriented[j] = 1;
          stack.push_back(j);
        }
        else if(!consistent)
          orientable = false;
      }
    }
  }
  if(!orientable)
    Msg::Warning("Discrete CAD triangulation not orientable");

  // the surfaces: the triangles of the same piece connected across edges of
  // two triangles whose normals make an angle smaller than angle (or one of
  // them without normal)
  std::vector<std::array<double, 3> > normal(nt);
  for(std::size_t i = 0; i < nt; i++) {
    const std::array<double, 3> &a = _nodes[tri[i][0]], &b = _nodes[tri[i][1]],
                                &c = _nodes[tri[i][2]];
    double n[3] = {(b[1] - a[1]) * (c[2] - a[2]) - (b[2] - a[2]) * (c[1] - a[1]),
                   (b[2] - a[2]) * (c[0] - a[0]) - (b[0] - a[0]) * (c[2] - a[2]),
                   (b[0] - a[0]) * (c[1] - a[1]) - (b[1] - a[1]) * (c[0] - a[0])};
    normalize(n);
    normal[i] = {{n[0], n[1], n[2]}};
  }
  std::vector<std::size_t> parent(nt);
  for(std::size_t i = 0; i < nt; i++) parent[i] = i;
  std::function<std::size_t(std::size_t)> find = [&](std::size_t i) {
    while(parent[i] != i) i = parent[i] = parent[parent[i]];
    return i;
  };
  for(auto &e : edgeTriangles) {
    if(e.second.size() != 2) continue;
    const std::size_t i = e.second[0], j = e.second[1];
    if(piece[i] != piece[j]) continue;
    const std::array<double, 3> &m = normal[i], &n = normal[j];
    const double c = m[0] * n[0] + m[1] * n[1] + m[2] * n[2];
    const bool none = (m[0] == 0. && m[1] == 0. && m[2] == 0.) ||
                      (n[0] == 0. && n[1] == 0. && n[2] == 0.);
    if(none || std::acos(std::max(-1., std::min(1., c))) < angle)
      parent[find(i)] = find(j);
  }
  std::vector<int> label(nt);
  for(std::size_t i = 0; i < nt; i++) label[i] = (int)find(i);

  // the analytic surfaces: the planes, spheres, cylinders, cones and tori
  // within the tolerance of the nodes of the surfaces, with the parameters of
  // the primitives (a sphere or a torus split in two halves if needed, the
  // apex of a cone inside its surface an embedded vertex)
  if(tolerance <= 0.) {
    double lo[3] = {1e300, 1e300, 1e300}, hi[3] = {-1e300, -1e300, -1e300};
    for(auto &t : tri)
      for(int n : t)
        for(int k = 0; k < 3; k++) {
          lo[k] = std::min(lo[k], _nodes[n][k]);
          hi[k] = std::max(hi[k], _nodes[n][k]);
        }
    tolerance = CTX::instance()->geom.discreteTolerance *
                std::sqrt((hi[0] - lo[0]) * (hi[0] - lo[0]) +
                          (hi[1] - lo[1]) * (hi[1] - lo[1]) +
                          (hi[2] - lo[2]) * (hi[2] - lo[2]));
  }
  std::vector<std::array<std::array<double, 2>, 3> > uv(nt);
  std::vector<char> hasUV(nt, 0);
  std::vector<int> apexes;
  int recognized[6] = {0, 0, 0, 0, 0, 0};
  {
    std::map<int, std::vector<std::size_t> > trianglesOf;
    for(std::size_t i = 0; i < nt; i++) trianglesOf[label[i]].push_back(i);
    int next = (int)nt;
    for(auto &tl : trianglesOf) {
      std::map<int, int> local;
      std::vector<std::array<double, 3> > x;
      std::vector<std::array<int, 3> > lt;
      std::vector<int> global;
      for(std::size_t i : tl.second) {
        std::array<int, 3> t;
        for(int k = 0; k < 3; k++) {
          auto it = local.insert({tri[i][k], (int)x.size()});
          if(it.second) {
            x.push_back(_nodes[tri[i][k]]);
            global.push_back(tri[i][k]);
          }
          t[k] = it.first->second;
        }
        lt.push_back(t);
      }
      const DiscreteCADAnalyticSurface as =
        recognizeSurface(x, lt, tolerance, angle);
      if(as.type == DiscreteCADAnalyticSurface::NONE) continue;
      recognized[as.type]++;
      double deviation = 0.;
      for(auto &p : x) deviation = std::max(deviation, std::abs(as.distance(p.data())));
      static const char *names[6] = {"", "plane", "sphere", "cylinder", "cone",
                                     "torus"};
      Msg::Debug("Discrete CAD triangulation: %lu triangles on a %s (%g, %g, "
                 "%g), axis (%g, %g, %g), %g, %g, at most %g away",
                 tl.second.size(), names[as.type], as.o[0], as.o[1], as.o[2],
                 as.axis[0], as.axis[1], as.axis[2], as.r1, as.r2, deviation);
      std::vector<std::array<std::array<double, 2>, 3> > luv;
      std::vector<int> half;
      int apex;
      analyticParameters(as, x, lt, tolerance, luv, half, apex);
      const int second = next++;
      for(std::size_t j = 0; j < tl.second.size(); j++) {
        const std::size_t i = tl.second[j];
        uv[i] = luv[j];
        hasUV[i] = 1;
        if(half[j]) label[i] = second;
      }
      if(apex >= 0) apexes.push_back(global[apex]);
    }
  }

  // the other surfaces split into pieces that a single map can parametrize,
  // as classifySurfaces does (in a temporary model, a discrete surface for
  // each surface)
  std::set<std::pair<int, int> > cuts;
  {
    TemporaryModel tmp;
    std::map<int, discreteFace *> faceOf;
    std::map<std::pair<int, int>, MVertex *> vertexOf; // (label, node)
    std::map<MVertex *, int> nodeOf;
    for(std::size_t i = 0; i < nt; i++) {
      if(hasUV[i]) continue;
      discreteFace *&gf = faceOf[label[i]];
      if(!gf) {
        gf = new discreteFace(tmp.model, (int)faceOf.size(), false);
        tmp.model->add(gf);
      }
      MVertex *v[3];
      for(int k = 0; k < 3; k++) {
        MVertex *&mv = vertexOf[{label[i], tri[i][k]}];
        if(!mv) {
          const std::array<double, 3> &x = _nodes[tri[i][k]];
          mv = new MVertex(x[0], x[1], x[2], gf);
          gf->mesh_vertices.push_back(mv);
          nodeOf[mv] = tri[i][k];
        }
        v[k] = mv;
      }
      gf->triangles.push_back(new MTriangle(v[0], v[1], v[2]));
    }
    std::vector<MLine *> cut;
    computeEdgeCut(tmp.model, cut, CTX::instance()->mesh.reparamMaxTriangles);
    for(MLine *l : cut) {
      cuts.insert(std::minmax(nodeOf[l->getVertex(0)], nodeOf[l->getVertex(1)]));
      delete l;
    }
  }
  if(!cuts.empty()) {
    for(std::size_t i = 0; i < nt; i++) parent[i] = i;
    for(auto &e : edgeTriangles) {
      if(e.second.size() != 2 || cuts.count(e.first)) continue;
      const std::size_t i = e.second[0], j = e.second[1];
      if(label[i] == label[j]) parent[find(i)] = find(j);
    }
    for(std::size_t i = 0; i < nt; i++) label[i] = (int)find(i);
  }

  // their parameters, computed on their triangulations as createGeometry
  // would (the boolean operations then interpolate them)
  {
    TemporaryModel tmp;
    std::map<int, std::vector<std::size_t> > trianglesOf;
    for(std::size_t i = 0; i < nt; i++)
      if(!hasUV[i]) trianglesOf[label[i]].push_back(i);
    for(auto &tl : trianglesOf) {
      std::map<int, MVertex *> vertexOf;
      std::vector<MTriangle *> ts;
      for(std::size_t i : tl.second) {
        MVertex *v[3];
        for(int k = 0; k < 3; k++) {
          MVertex *&mv = vertexOf[tri[i][k]];
          if(!mv) {
            const std::array<double, 3> &x = _nodes[tri[i][k]];
            mv = new MVertex(x[0], x[1], x[2]);
          }
          v[k] = mv;
        }
        ts.push_back(new MTriangle(v[0], v[1], v[2]));
      }
      std::vector<MVertex *> nodes;
      std::vector<SPoint2> nodesUV;
      std::vector<SPoint3> nodesXYZ;
      std::vector<int> corners;
      if(computeParametrization(ts, nodes, nodesUV, nodesXYZ, corners)) {
        for(std::size_t j = 0; j < tl.second.size(); j++) {
          const std::size_t i = tl.second[j];
          for(int k = 0; k < 3; k++) {
            const SPoint2 &p = nodesUV[corners[3 * j + k]];
            uv[i][k] = {{p.x(), p.y()}};
          }
          hasUV[i] = 1;
        }
      }
      for(MTriangle *t : ts) delete t;
      for(auto &v : vertexOf) delete v.second;
    }
  }

  // the surfaces, curves and vertices, and the volumes
  std::vector<int> surfaceOf;
  _addTopology(tri, label, uv, hasUV, curveAngle, surfaceOf);
  std::vector<std::vector<std::vector<int> > > cells = _cells(tri, surfaceOf);
  // (the apexes of the cones inside their surfaces)
  for(int a : apexes) {
    std::size_t i = 0;
    while(i < nt && tri[i][0] != a && tri[i][1] != a && tri[i][2] != a) i++;
    if(i == nt) continue;
    Surface &sf = _surfaces[surfaceOf[i]];
    bool inside = true;
    for(int c : sf.curves)
      for(int n : _curves[std::abs(c)].nodes)
        if(n == a) inside = false;
    if(inside) sf.embeddedVertices.push_back(_addVertex(a));
  }

  // the surfaces oriented outwards of the first volume whose outer shell they
  // are on, or else of the first volume they bound
  std::map<int, int> signOf;
  for(auto &cell : cells)
    for(int s : cell[0]) signOf.insert({std::abs(s), s > 0 ? 1 : -1});
  for(auto &cell : cells)
    for(auto &shell : cell)
      for(int s : shell) signOf.insert({std::abs(s), s > 0 ? 1 : -1});
  for(auto &sg : signOf) {
    if(sg.second > 0) continue;
    Surface &sf = _surfaces[sg.first];
    for(auto &t : sf.triangles) std::swap(t[1], t[2]);
    for(auto &q : sf.uv) std::swap(q[1], q[2]);
    for(auto &sm : sf.seams) std::swap(sm.second[0], sm.second[1]);
    for(int &c : sf.curves) c = -c;
  }
  for(auto &cell : cells) {
    int t = -1;
    _assignTag(3, t);
    _volumes[t] = Volume();
    for(auto &shell : cell)
      for(int s : shell)
        _volumes[t].surfaces.push_back(signOf[std::abs(s)] > 0 ? s : -s);
    outDimTags.push_back({3, t});
  }
  std::set<int> surfaces(surfaceOf.begin(), surfaceOf.end());
  for(int s : surfaces)
    if(!signOf.count(s)) outDimTags.push_back({2, s});
  std::set<int> curves;
  for(int s : surfaces)
    for(int c : _surfaces[s].curves) curves.insert(std::abs(c));
  Msg::Info("Discrete CAD triangulation: %lu volume%s, %lu surface%s, %lu "
            "curve%s",
            cells.size(), cells.size() == 1 ? "" : "s", surfaces.size(),
            surfaces.size() == 1 ? "" : "s", curves.size(),
            curves.size() == 1 ? "" : "s");
  Msg::Info("Discrete CAD triangulation: %d plane%s, %d sphere%s, %d "
            "cylinder%s, %d cone%s and %d tor%s recognized (tolerance %g)",
            recognized[1], recognized[1] == 1 ? "" : "s", recognized[2],
            recognized[2] == 1 ? "" : "s", recognized[3],
            recognized[3] == 1 ? "" : "s", recognized[4],
            recognized[4] == 1 ? "" : "s", recognized[5],
            recognized[5] == 1 ? "us" : "i", tolerance);
  _changed = true;
  return true;
}

bool DiscreteCAD_Internals::importShapes(
  const std::string &fileName, double angle, double curveAngle,
  double tolerance, std::vector<std::pair<int, int> > &outDimTags)
{
  outDimTags.clear();
  std::string ext = SplitFileName(fileName)[2];
  std::transform(ext.begin(), ext.end(), ext.begin(), ::tolower);

  std::vector<double> coord;
  std::vector<std::size_t> triangles;
  std::vector<int> pieces;
  std::size_t others = 0;
  int status = 0;
  {
    // the file read in a temporary model (destroyed before the topology is
    // built)
    TemporaryModel tmp;
    GModel *model = tmp.model;
    if(ext == ".stl")
      status = model->readSTL(fileName, CTX::instance()->geom.tolerance);
    else if(ext == ".msh")
      status = model->readMSH(fileName);
    else if(ext == ".obj")
      status = model->readOBJ(fileName);
    else if(ext == ".ply")
      status = model->readPLY(fileName);
    else if(ext == ".off")
      status = model->readOFF(fileName);
    else if(ext == ".vtk")
      status = model->readVTK(fileName, CTX::instance()->bigEndian);
    else if(ext == ".mesh")
      status = model->readMESH(fileName);
    else
      Msg::Error("Discrete CAD import: unknown format of '%s'",
                 fileName.c_str());

    // the triangles of its surfaces, each surface a piece
    std::map<MVertex *, std::size_t> index;
    int count = 0;
    for(auto it = model->firstFace(); it != model->lastFace(); ++it, ++count) {
      GFace *gf = *it;
      for(MTriangle *t : gf->triangles) {
        for(int k = 0; k < 3; k++) {
          MVertex *v = t->getVertex(k);
          auto r = index.insert({v, index.size()});
          if(r.second) {
            coord.push_back(v->x());
            coord.push_back(v->y());
            coord.push_back(v->z());
          }
          triangles.push_back(r.first->second);
        }
        pieces.push_back(count);
      }
      others += gf->quadrangles.size() + gf->polygons.size();
    }
  }
  if(!status) return false;
  if(others)
    Msg::Warning("Discrete CAD import: %lu surface elements other than "
                 "triangles ignored in '%s'",
                 others, fileName.c_str());
  if(triangles.empty()) {
    Msg::Error("Discrete CAD import: no triangles in '%s'", fileName.c_str());
    return false;
  }
  return addTriangulation(coord, triangles, pieces, angle, curveAngle,
                          tolerance, outDimTags);
}

void DiscreteCAD_Internals::synchronize(GModel *model)
{
  // the entities of the previous call, those of highest dimension first (an
  // entity is only removed after those it bounds)
  std::sort(_synchronized.begin(), _synchronized.end(),
            [](const std::pair<int, int> &p, const std::pair<int, int> &q) {
              return p.first > q.first ||
                     (p.first == q.first && p.second < q.second);
            });
  std::vector<GEntity *> removed;
  model->remove(_synchronized, removed);
  for(GEntity *e : removed) delete e;
  _synchronized.clear();

  // the geometry of the entities is computed from a temporary mesh, the
  // polylines and triangulations, deleted afterwards without changing the
  // numbering of the mesh of the model
  const std::size_t maxVertex = model->getMaxVertexNumber();
  const std::size_t maxElement = model->getMaxElementNumber();
  std::vector<MVertex *> mesh(_nodes.size(), nullptr);
  auto node = [&](int n, GEntity *e) {
    if(!mesh[n]) {
      const std::array<double, 3> &x = _nodes[n];
      mesh[n] = new MVertex(x[0], x[1], x[2], e);
      e->mesh_vertices.push_back(mesh[n]);
    }
    return mesh[n];
  };
  auto taken = [&](int dim, int tag) {
    if(!model->getEntityByTag(dim, tag)) return false;
    Msg::Error("The model already has a %s %d: discrete CAD %s %d ignored",
               entityName(dim), tag, entityName(dim), tag);
    return true;
  };
  std::vector<GEntity *> created;
  for(auto &it : _vertices) {
    if(taken(0, it.first)) continue;
    const std::array<double, 3> &x = _nodes[it.second.node];
    discreteVertex *gv =
      new discreteVertex(model, it.first, x[0], x[1], x[2], false);
    gv->setNativeType(GEntity::DiscreteCADModel);
    model->add(gv);
    node(it.second.node, gv);
    created.push_back(gv);
  }
  for(auto &it : _curves) {
    if(taken(1, it.first)) continue;
    discreteEdge *ge = new discreteEdge(
      model, it.first, model->getVertexByTag(it.second.v0),
      model->getVertexByTag(it.second.v1), false);
    ge->setNativeType(GEntity::DiscreteCADModel);
    model->add(ge);
    const std::vector<int> &n = it.second.nodes;
    for(std::size_t i = 0; i + 1 < n.size(); i++)
      ge->lines.push_back(new MLine(node(n[i], ge), node(n[i + 1], ge)));
    created.push_back(ge);
  }
  for(auto &it : _surfaces) {
    if(taken(2, it.first)) continue;
    discreteFace *gf = new discreteFace(model, it.first, false);
    std::vector<int> tags, signs;
    for(int c : it.second.curves) {
      tags.push_back(std::abs(c));
      signs.push_back(c > 0 ? 1 : -1);
    }
    gf->setBoundEdges(tags, signs);
    for(int v : it.second.embeddedVertices) {
      GVertex *gv = model->getVertexByTag(v);
      if(gv) gf->addEmbeddedVertex(gv);
    }
    gf->setNativeType(GEntity::DiscreteCADModel);
    model->add(gf);
    // without parameters, the parametrization is computed from the mesh
    if(it.second.uv.empty())
      for(auto &t : it.second.triangles)
        gf->triangles.push_back(
          new MTriangle(node(t[0], gf), node(t[1], gf), node(t[2], gf)));
    created.push_back(gf);
  }
  for(auto &it : _volumes) {
    if(taken(3, it.first)) continue;
    discreteRegion *gr = new discreteRegion(model, it.first, false);
    std::vector<int> tags, signs;
    for(int s : it.second.surfaces) {
      tags.push_back(std::abs(s));
      signs.push_back(s > 0 ? 1 : -1);
    }
    gr->setBoundFaces(tags, signs);
    gr->setNativeType(GEntity::DiscreteCADModel);
    model->add(gr);
    created.push_back(gr);
  }
  for(GEntity *e : created) _synchronized.push_back({e->dim(), e->tag()});
  model->createGeometryOfDiscreteEntities(_synchronized);
  // the parametrizations given with the surfaces, positively oriented (the
  // nodes of a seam twice, with their parameters on each side)
  for(GEntity *e : created) {
    if(e->dim() != 2) continue;
    discreteFace *gf = static_cast<discreteFace *>(e);
    const Surface &sf = _surfaces[e->tag()];
    if(sf.uv.empty()) continue;
    std::map<std::pair<int, std::array<double, 2> >, int> local;
    std::vector<SPoint2> uv;
    std::vector<SPoint3> xyz;
    std::vector<int> triangles;
    double area = 0.;
    for(std::size_t i = 0; i < sf.triangles.size(); i++) {
      for(int k = 0; k < 3; k++) {
        const int n = sf.triangles[i][k];
        const std::array<double, 2> &p = sf.uv[i][k];
        auto it = local.find({n, p});
        if(it == local.end()) {
          it = local.insert({{n, p}, (int)uv.size()}).first;
          uv.push_back(SPoint2(p[0], p[1]));
          xyz.push_back(SPoint3(_nodes[n][0], _nodes[n][1], _nodes[n][2]));
        }
        triangles.push_back(it->second);
      }
      const std::array<double, 2> &a = sf.uv[i][0], &b = sf.uv[i][1],
                                  &c = sf.uv[i][2];
      area += (b[0] - a[0]) * (c[1] - a[1]) - (b[1] - a[1]) * (c[0] - a[0]);
    }
    const double flip = area < 0. ? -1. : 1.;
    for(SPoint2 &p : uv) p = SPoint2(p.x(), flip * p.y());
    gf->setParametrization(uv, xyz, triangles);
    // the parameters of its curves on it, from the triangles along them (the
    // two sides of the seam given)
    std::map<std::pair<int, int>, std::size_t> triangleOf;
    for(std::size_t i = 0; i < sf.triangles.size(); i++)
      for(int k = 0; k < 3; k++)
        triangleOf[std::minmax(sf.triangles[i][k],
                               sf.triangles[i][(k + 1) % 3])] = i;
    auto corner = [&](std::size_t i, int n) {
      int k = 0;
      while(k < 2 && sf.triangles[i][k] != n) k++;
      return SPoint2(sf.uv[i][k][0], flip * sf.uv[i][k][1]);
    };
    // (the parameters along each use of a curve, in its direction)
    std::vector<std::vector<SPoint2> > along;
    for(int c : sf.curves) {
      const int tag = std::abs(c);
      along.push_back(std::vector<SPoint2>());
      discreteEdge *de = dynamic_cast<discreteEdge *>(model->getEdgeByTag(tag));
      if(!de) continue;
      auto sm = sf.seams.find(tag);
      if(sm != sf.seams.end()) {
        std::vector<SPoint2> side[2];
        for(int k = 0; k < 2; k++)
          for(const std::array<double, 2> &p : sm->second[k])
            side[k].push_back(SPoint2(p[0], flip * p[1]));
        de->setReparamOnFace(gf, side[0], side[1]);
        along.back() = side[c > 0 ? 0 : 1];
      }
      else {
        const std::vector<int> &n = _curves[tag].nodes;
        std::vector<SPoint2> p(n.size());
        bool found = true;
        for(std::size_t j = 0; j + 1 < n.size() && found; j++) {
          auto it = triangleOf.find(std::minmax(n[j], n[j + 1]));
          if(it == triangleOf.end()) found = false;
          else {
            p[j] = corner(it->second, n[j]);
            p[j + 1] = corner(it->second, n[j + 1]);
          }
        }
        if(!found) continue;
        de->setReparamOnFace(gf, p);
        along.back() = p;
      }
      if(c < 0) std::reverse(along.back().begin(), along.back().end());
    }
    if(sf.seams.empty()) continue;
    // the loops of a surface with seams, the curves in their order (the
    // mesher of periodic surfaces follows them), chained by their parameters
    gf->edgeLoops.clear();
    std::vector<bool> used(sf.curves.size(), false);
    for(std::size_t first = 0; first < sf.curves.size(); first++) {
      if(used[first]) continue;
      GEdgeLoop loop;
      std::size_t current = first;
      while(current < sf.curves.size()) {
        used[current] = true;
        const int c = sf.curves[current];
        loop.add(c > 0 ? 1 : -1, model->getEdgeByTag(std::abs(c)));
        if(along[current].empty() || along[first].empty()) break;
        const SPoint2 &end = along[current].back();
        double best = end.distance(along[first].front());
        current = sf.curves.size();
        for(std::size_t j = 0; j < sf.curves.size(); j++) {
          if(used[j] || along[j].empty()) continue;
          const double d = end.distance(along[j].front());
          if(d < best) {
            best = d;
            current = j;
          }
        }
      }
      gf->edgeLoops.push_back(loop);
    }
  }
  for(GEntity *e : created) e->deleteMesh();
  model->resetMaxVertexNumber(maxVertex);
  model->resetMaxElementNumber(maxElement);
  _changed = false;
  // the bounding box of the model (and its characteristic length), as the
  // other kernels
  SetBoundingBox();
}
