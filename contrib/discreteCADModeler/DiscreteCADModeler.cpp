// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <algorithm>
#include <cmath>
#include "DiscreteCADModeler.h"
#include "GmshMessage.h"
#include "Context.h"
#include "GModel.h"
#include "GModelIO_GEO.h"
#include "GModelIO_OCC.h"
#include "discreteVertex.h"
#include "discreteEdge.h"
#include "discreteFace.h"
#include "discreteRegion.h"
#include "MVertex.h"
#include "MLine.h"
#include "MTriangle.h"

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
    volume.surfaces.push_back(
      _addSurface(loop, {{{n[0], n[1], n[2]}}, {{n[0], n[2], n[3]}}}));
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
  // the rings of the lateral surface, its cells about as long as wide; a zero
  // radius gives an apex
  const int n = circleDivisions(rmax, tolerance);
  const double slant = std::sqrt(h * h + (r2 - r1) * (r2 - r1));
  const int m = std::max(1, (int)std::lround(slant * n / (2. * pi * rmax)));
  std::vector<std::vector<int> > rings(m + 1);
  for(int k = 0; k <= m; k++) {
    const double r = r1 + (r2 - r1) * k / m;
    rings[k] = _addRing(f, r, r, h * k / m, r > 0. ? circleDivisions(r, tolerance) : 1);
  }
  // the circles (two arcs each) or apexes at the ends, and the two seams of
  // the lateral surface at the angles 0 and pi
  int a1 = 0, b1 = 0, a2 = 0, b2 = 0, v1[2], v2[2];
  if(r1 > 0.) {
    _addArcs(rings[0], a1, b1);
    v1[0] = _curves[a1].v0;
    v1[1] = _curves[a1].v1;
  }
  else
    v1[0] = v1[1] = _addVertex(rings[0][0]);
  if(r2 > 0.) {
    _addArcs(rings[m], a2, b2);
    v2[0] = _curves[a2].v0;
    v2[1] = _curves[a2].v1;
  }
  else
    v2[0] = v2[1] = _addVertex(rings[m][0]);
  std::vector<int> column[2];
  for(int k = 0; k <= m; k++) {
    column[0].push_back(rings[k][0]);
    column[1].push_back(rings[k][rings[k].size() / 2]);
  }
  const int seam0 = _addCurve(v1[0], v2[0], column[0]);
  const int seamPi = _addCurve(v1[1], v2[1], column[1]);
  // the two halves of the lateral surface, and the disks at the ends, their
  // loops counterclockwise seen from outside
  Volume volume;
  for(int half = 0; half < 2; half++) {
    std::vector<std::array<int, 3> > triangles;
    for(int k = 0; k < m; k++) zipHalf(rings[k], rings[k + 1], half, triangles);
    std::vector<int> loop;
    if(r1 > 0.) loop.push_back(half ? b1 : a1);
    loop.push_back(half ? seam0 : seamPi);
    if(r2 > 0.) loop.push_back(half ? -b2 : -a2);
    loop.push_back(half ? -seamPi : -seam0);
    volume.surfaces.push_back(_addSurface(loop, triangles));
  }
  if(r1 > 0.) {
    std::vector<std::array<int, 3> > triangles =
      _fillEllipse(f, r1, r1, 0., rings[0]);
    reverse(triangles);
    volume.surfaces.push_back(_addSurface({-b1, -a1}, triangles));
  }
  if(r2 > 0.)
    volume.surfaces.push_back(
      _addSurface({a2, b2}, _fillEllipse(f, r2, r2, h, rings[m])));
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
  // the vertices at theta, phi in {0, pi}, the arcs of the parallels (phi =
  // 0, pi) and of the meridians (theta = 0, pi) between them
  int vertex[2][2];
  for(int a = 0; a < 2; a++)
    for(int b = 0; b < 2; b++)
      vertex[a][b] = _addVertex(node(a * nt / 2, b * np / 2));
  int parallel[2][2], meridian[2][2];
  for(int b = 0; b < 2; b++)
    for(int h = 0; h < 2; h++) {
      std::vector<int> nodes;
      for(int i = h * nt / 2; i <= (h + 1) * nt / 2; i++)
        nodes.push_back(node(i, b * np / 2));
      parallel[b][h] =
        _addCurve(vertex[h][b], vertex[(h + 1) % 2][b], nodes);
    }
  for(int a = 0; a < 2; a++)
    for(int h = 0; h < 2; h++) {
      std::vector<int> nodes;
      for(int j = h * np / 2; j <= (h + 1) * np / 2; j++)
        nodes.push_back(node(a * nt / 2, j));
      meridian[a][h] =
        _addCurve(vertex[a][h], vertex[a][(h + 1) % 2], nodes);
    }
  // the 4 patches theta in [ht pi, (ht + 1) pi], phi in [hp pi, (hp + 1) pi],
  // their triangles oriented outwards (d/dtheta x d/dphi) and their loops
  // counterclockwise in (theta, phi)
  Volume volume;
  for(int ht = 0; ht < 2; ht++)
    for(int hp = 0; hp < 2; hp++) {
      std::vector<std::array<int, 3> > triangles;
      for(int i = ht * nt / 2; i < (ht + 1) * nt / 2; i++)
        for(int j = hp * np / 2; j < (hp + 1) * np / 2; j++) {
          triangles.push_back(
            {{node(i, j), node(i + 1, j), node(i + 1, j + 1)}});
          triangles.push_back(
            {{node(i, j), node(i + 1, j + 1), node(i, j + 1)}});
        }
      const std::vector<int> loop = {
        parallel[hp][ht], meridian[(ht + 1) % 2][hp],
        -parallel[(hp + 1) % 2][ht], -meridian[ht][hp]};
      volume.surfaces.push_back(_addSurface(loop, triangles));
    }
  _volumes[tag] = volume;
  return true;
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
    gf->setNativeType(GEntity::DiscreteCADModel);
    model->add(gf);
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
  for(GEntity *e : created) e->deleteMesh();
  model->resetMaxVertexNumber(maxVertex);
  model->resetMaxElementNumber(maxElement);
}
