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
  if(tag > 0) {
    if(_exists(dim, tag)) {
      Msg::Error("Discrete CAD %s %d already exists", entityName(dim), tag);
      return false;
    }
  }
  else {
    tag = _maxTag[dim];
    if(GModel::current())
      tag = std::max(tag, GModel::current()->getMaxElementaryNumber(dim));
    tag++;
  }
  _maxTag[dim] = std::max(_maxTag[dim], tag);
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
    model->add(gv);
    node(it.second.node, gv);
    created.push_back(gv);
  }
  for(auto &it : _curves) {
    if(taken(1, it.first)) continue;
    discreteEdge *ge = new discreteEdge(
      model, it.first, model->getVertexByTag(it.second.v0),
      model->getVertexByTag(it.second.v1), false);
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
    model->add(gr);
    created.push_back(gr);
  }
  for(GEntity *e : created) _synchronized.push_back({e->dim(), e->tag()});
  model->createGeometryOfDiscreteEntities(_synchronized);
  for(GEntity *e : created) e->deleteMesh();
  model->resetMaxVertexNumber(maxVertex);
  model->resetMaxElementNumber(maxElement);
}
