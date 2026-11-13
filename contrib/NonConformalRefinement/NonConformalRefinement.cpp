// Gmsh Non-Conformal Refinement Plugin - Copyright (C) 2026 C. Geuzaine and
// J.-F. Remacle
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
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>
#include <limits>
#include <unordered_map>
#include <vector>
#include "GModel.h"
#include "GEdge.h"
#include "GFace.h"
#include "GRegion.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "MPyramid.h"
#include "MPolygon.h"
#include "MPolyhedron.h"
#include "Field.h"
#include "Context.h"
#include "Hash.h"
#include "OS.h"
#include "MVertex.h"
#include "NonConformalRefinement.h"

GMSH_NonConformalRefinementPlugin::GMSH_NonConformalRefinementPlugin()
  : GMSH_MeshPlugin({{GMSH_FULLRC, "SizeField", nullptr, -1.},
                     {GMSH_FULLRC, "MaxLevel", nullptr, 4.},
                     {GMSH_FULLRC, "Balance", nullptr, 1.},
                     {GMSH_FULLRC, "OnGeometry", nullptr, 1.},
                     {GMSH_FULLRC, "SampleSpacing", nullptr, 0.}})
{
}

std::string GMSH_NonConformalRefinementPlugin::getHelp() const
{
  return "Plugin(NonConformalRefinement) splits the first order elements of "
         "highest dimension of the current mesh through the middle of their "
         "edges, up to `MaxLevel' times, until their longest edge is smaller "
         "than the mesh size field `SizeField' (the background field if "
         "negative). The elements with hanging nodes become polygons and "
         "polyhedra. The field is evaluated at the centre and edge midpoints "
         "of the elements, which allows large jumps of sizes between "
         "neighboring elements; if `SampleSpacing' is positive, it is instead "
         "evaluated on a grid of points of the elements including their "
         "corners, at most `SampleSpacing' apart (e.g. the smallest size of "
         "the field), so that no region of smaller sizes is missed. If "
         "`Balance' is positive, the refinement levels of elements sharing an "
         "edge differ by at most `Balance'. If `OnGeometry' is set, the new "
         "nodes on curves and surfaces are placed on the geometry.";
}

namespace {

  typedef MVertex *V;

  // the keys of the hash tables compare the node pointers, which are not
  // dereferenced (the tables are never iterated, so their order does not
  // matter)
  typedef std::uintptr_t P;

  struct EdgeKey {
    V a, b;
    EdgeKey(V x, V y) : a(x), b(y)
    {
      if(a > b) std::swap(a, b);
    }
    bool operator==(const EdgeKey &o) const { return a == o.a && b == o.b; }
  };

  struct EdgeHash {
    std::size_t operator()(const EdgeKey &k) const
    { return HashCombine(HashMix((P)k.a), (P)k.b); }
  };

  // a triangle or a quadrangle, by its sorted corners
  struct FaceKey {
    std::array<V, 4> v;
    FaceKey(const V *f, int n)
    {
      v = {f[0], f[1], f[2], n == 4 ? f[3] : nullptr};
      std::sort(v.begin(), v.begin() + n);
    }
    bool operator==(const FaceKey &o) const { return v == o.v; }
  };

  struct FaceHash {
    std::size_t operator()(const FaceKey &k) const
    {
      std::uint64_t h = HashMix((P)k.v[0]);
      for(int i = 1; i < 4; i++) h = HashCombine(h, (P)k.v[i]);
      return h;
    }
  };

  // the edges and the faces of the element types, in the Gmsh node ordering (in
  // 2D, the face is the element itself)
  struct Shape {
    int numCorners, numEdges, edges[12][2], numFaces, faceSize[6], faces[6][4];
  };

  const Shape triShape = {3, 3, {{0, 1}, {1, 2}, {2, 0}}, 1, {3}, {{0, 1, 2}}};
  const Shape quaShape = {4, 4,   {{0, 1}, {1, 2}, {2, 3}, {3, 0}},
                          1, {4}, {{0, 1, 2, 3}}};
  const Shape tetShape = {4,
                          6,
                          {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}, {2, 3}},
                          4,
                          {3, 3, 3, 3},
                          {{0, 2, 1}, {0, 1, 3}, {0, 3, 2}, {3, 1, 2}}};
  const Shape hexShape = {8,
                          12,
                          {{0, 1},
                           {0, 3},
                           {0, 4},
                           {1, 2},
                           {1, 5},
                           {2, 3},
                           {2, 6},
                           {3, 7},
                           {4, 5},
                           {4, 7},
                           {5, 6},
                           {6, 7}},
                          6,
                          {4, 4, 4, 4, 4, 4},
                          {{0, 3, 2, 1},
                           {0, 1, 5, 4},
                           {0, 4, 7, 3},
                           {1, 2, 6, 5},
                           {2, 3, 7, 6},
                           {4, 5, 6, 7}}};
  const Shape priShape = {
    6,
    9,
    {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 4}, {2, 5}, {3, 4}, {3, 5}, {4, 5}},
    5,
    {3, 3, 4, 4, 4},
    {{0, 2, 1}, {3, 4, 5}, {0, 1, 4, 3}, {0, 3, 5, 2}, {1, 2, 5, 4}}};
  const Shape pyrShape = {
    5,
    8,
    {{0, 1}, {0, 3}, {0, 4}, {1, 2}, {1, 4}, {2, 3}, {2, 4}, {3, 4}},
    5,
    {4, 3, 3, 3, 3},
    {{0, 3, 2, 1}, {0, 1, 4}, {3, 0, 4}, {1, 2, 4}, {2, 3, 4}}};

  const Shape &shape(int type)
  {
    switch(type) {
    case TYPE_TRI: return triShape;
    case TYPE_QUA: return quaShape;
    case TYPE_TET: return tetShape;
    case TYPE_HEX: return hexShape;
    case TYPE_PRI: return priShape;
    default: return pyrShape;
    }
  }

  // an element of the refinement: its type, its refinement level, whether it
  // was found small enough for the size field, and its corners
  struct Leaf {
    char type, level;
    bool sized;
    V v[8];
  };

  double edgeLength(V a, V b)
  {
    return std::sqrt((a->x() - b->x()) * (a->x() - b->x()) +
                     (a->y() - b->y()) * (a->y() - b->y()) +
                     (a->z() - b->z()) * (a->z() - b->z()));
  }

  // triangulate a planar convex polygon whose nodes may be aligned (hanging
  // nodes), without dropping any node, by clipping the convex corners whose
  // triangle holds no other node; the triangulation only depends on the set of
  // nodes, so that the two polyhedra sharing a face triangulate it the same way
  void triangulate(const V *nodes, int numNodes, std::vector<V> &tris)
  {
    std::vector<V> ring(nodes, nodes + numNodes);
    auto first = std::min_element(ring.begin(), ring.end(), [](V x, V y) {
      return x->getNum() < y->getNum();
    });
    std::rotate(ring.begin(), first, ring.end());
    if(ring[1]->getNum() > ring.back()->getNum())
      std::reverse(ring.begin() + 1, ring.end());

    // the normal (Newell), whose norm is twice the area
    double n[3] = {0., 0., 0.};
    for(std::size_t i = 0; i < ring.size(); i++) {
      V a = ring[i], b = ring[(i + 1) % ring.size()];
      n[0] += (a->y() - b->y()) * (a->z() + b->z());
      n[1] += (a->z() - b->z()) * (a->x() + b->x());
      n[2] += (a->x() - b->x()) * (a->y() + b->y());
    }
    double eps = 1e-10 * std::sqrt(n[0] * n[0] + n[1] * n[1] + n[2] * n[2]);
    auto cross = [&](V a, V b, V c) {
      double u[3] = {b->x() - a->x(), b->y() - a->y(), b->z() - a->z()};
      double v[3] = {c->x() - a->x(), c->y() - a->y(), c->z() - a->z()};
      return (u[1] * v[2] - u[2] * v[1]) * n[0] +
             (u[2] * v[0] - u[0] * v[2]) * n[1] +
             (u[0] * v[1] - u[1] * v[0]) * n[2];
    };

    while(ring.size() > 3) {
      int N = (int)ring.size(), ear = -1;
      for(int i = 0; i < N && ear < 0; i++) {
        V a = ring[(i + N - 1) % N], b = ring[i], c = ring[(i + 1) % N];
        if(cross(a, b, c) <= eps) continue; // aligned (or reflex)
        bool ok = true;
        for(int j = 0; j < N && ok; j++) {
          V p = ring[j];
          if(p != a && p != b && p != c && cross(a, b, p) >= -eps &&
             cross(b, c, p) >= -eps && cross(c, a, p) >= -eps)
            ok = false;
        }
        if(ok) ear = i;
      }
      if(ear < 0) {
        Msg::Warning("Could not triangulate a polygon with %d nodes", N);
        for(int i = 1; i < N - 1; i++)
          tris.insert(tris.end(), {ring[0], ring[i], ring[i + 1]});
        return;
      }
      tris.insert(tris.end(),
                  {ring[(ear + N - 1) % N], ring[ear], ring[(ear + 1) % N]});
      ring.erase(ring.begin() + ear);
    }
    tris.insert(tris.end(), ring.begin(), ring.end());
  }

  // faces, as the nodes around each one (offsets[i] to offsets[i + 1]), with
  // the number of corners of each
  struct Rings {
    std::vector<V> nodes;
    std::vector<int> offsets, corners;
    void clear()
    {
      nodes.clear();
      offsets.assign(1, 0);
      corners.clear();
    }
    int size() const { return (int)corners.size(); }
    const V *ring(int i) const { return &nodes[offsets[i]]; }
    int ringSize(int i) const { return offsets[i + 1] - offsets[i]; }
  };

  class Refiner {
  private:
    // the middle of the split edges, and the split faces (with their centre for
    // quadrangles)
    std::unordered_map<EdgeKey, V, EdgeHash> _mid;
    std::unordered_map<FaceKey, V, FaceHash> _split;
    // the curves and surfaces holding the edges and faces of the boundary, if
    // the new nodes are placed on the geometry
    std::unordered_map<EdgeKey, GEntity *, EdgeHash> _edgeOwner;
    std::unordered_map<FaceKey, GFace *, FaceHash> _faceOwner;

    GEntity *edgeOwner(V a, V b) const
    {
      auto it = _edgeOwner.find(EdgeKey(a, b));
      return it == _edgeOwner.end() ? nullptr : it->second;
    }
    // the parameter of a on a curve, next to that of b on a closed curve
    double curveParameter(V a, V b, GEdge *ge) const
    {
      double t;
      reparamMeshVertexOnEdge(a, ge, t);
      if(ge->periodic(0) && a->onWhat()->dim() == 0) {
        double tb;
        reparamMeshVertexOnEdge(b, ge, tb);
        Range<double> r = ge->parBounds(0);
        if(std::abs(r.high() - tb) < std::abs(r.low() - tb)) t = r.high();
      }
      return t;
    }
    // the parameters of nodes on a surface, all taken next to the first one
    // on a seam
    void surfaceParameters(const V *v, int n, GFace *gf, SPoint2 *p) const
    {
      for(int i = 1; i < n; i++) {
        SPoint2 p0;
        reparamMeshEdgeOnFace(v[0], v[i], gf, p0, p[i]);
        if(i == 1)
          p[0] = p0;
        else
          p[i] += p[0] - p0;
      }
    }

    SPoint3 centre(const V *v, int n) const
    {
      SPoint3 s(0., 0., 0.);
      for(int i = 0; i < n; i++) s += v[i]->point();
      return s * (1. / n);
    }
    // a new node on a curve or a surface, in the middle of the nodes v in the
    // parametric space; if that point is far from their straight centre
    // (compared to the size h of the edge or face), as at a pole or where the
    // parametrization is distorted, the straight centre is projected instead
    V onCurve(GEdge *c, double t, const V *v, int n, double h)
    {
      SPoint3 s = centre(v, n);
      GPoint p = c->point(t);
      if(s.distance(SPoint3(p.x(), p.y(), p.z())) > 0.1 * h)
        p = c->closestPoint(s, t);
      V m = new MEdgeVertex(p.x(), p.y(), p.z(), c, t);
      newNodes.push_back(m);
      straight[m] = s;
      return m;
    }
    V onSurface(GFace *f, SPoint2 uv, const V *v, int n, double h)
    {
      SPoint3 s = centre(v, n);
      GPoint p = f->point(uv);
      if(s.distance(SPoint3(p.x(), p.y(), p.z())) > 0.1 * h) {
        double guess[2] = {uv.x(), uv.y()};
        p = f->closestPoint(s, guess);
        uv = SPoint2(p.u(), p.v());
      }
      V m = new MFaceVertex(p.x(), p.y(), p.z(), f, uv.x(), uv.y());
      newNodes.push_back(m);
      straight[m] = s;
      return m;
    }

  public:
    std::vector<V> newNodes;
    // the straight position of the nodes placed on the geometry
    std::unordered_map<V, SPoint3> straight;

    // place the new nodes on the geometry: register the edges of the curves
    // and of the surfaces, and the faces of the surfaces
    void addCurve(GEdge *ge, V a, V b) { _edgeOwner[EdgeKey(a, b)] = ge; }
    void addSurface(GFace *gf, const V *f, int n)
    {
      for(int i = 0; i < n; i++)
        _edgeOwner.insert({EdgeKey(f[i], f[(i + 1) % n]), gf});
      _faceOwner[FaceKey(f, n)] = gf;
    }

    // a new node at the centre of the nodes v, classified on ge
    V newNode(const V *v, int n, GEntity *ge)
    {
      double x = 0., y = 0., z = 0.;
      for(int i = 0; i < n; i++) {
        x += v[i]->x();
        y += v[i]->y();
        z += v[i]->z();
      }
      V nv = new MVertex(x / n, y / n, z / n, ge);
      newNodes.push_back(nv);
      return nv;
    }
    V findMid(V a, V b) const
    {
      auto it = _mid.find(EdgeKey(a, b));
      return it == _mid.end() ? nullptr : it->second;
    }
    // the middle of an edge, created if needed: on the curve or surface that
    // holds the edge if any, on ge otherwise
    V mid(V a, V b, GEntity *ge)
    {
      EdgeKey k(a, b);
      auto it = _mid.find(k);
      if(it != _mid.end()) return it->second;
      V v[2] = {a, b};
      GEntity *owner = edgeOwner(a, b);
      if(!owner) return _mid[k] = newNode(v, 2, ge);
      V m;
      if(owner->dim() == 1) {
        GEdge *c = static_cast<GEdge *>(owner);
        m =
          onCurve(c, 0.5 * (curveParameter(a, b, c) + curveParameter(b, a, c)),
                  v, 2, edgeLength(a, b));
      }
      else {
        GFace *f = static_cast<GFace *>(owner);
        SPoint2 uv[2];
        surfaceParameters(v, 2, f, uv);
        m = onSurface(f, (uv[0] + uv[1]) * 0.5, v, 2, edgeLength(a, b));
      }
      _edgeOwner[EdgeKey(a, m)] = owner;
      _edgeOwner[EdgeKey(m, b)] = owner;
      return _mid[k] = m;
    }
    // mark a face as split; return the centre of a quadrangle
    V split(const V *f, int n, GEntity *ge)
    {
      FaceKey k(f, n);
      auto it = _split.find(k);
      if(it != _split.end()) return it->second;
      auto ot = _faceOwner.find(k);
      if(ot == _faceOwner.end())
        return _split[k] = (n == 4) ? newNode(f, 4, ge) : nullptr;

      // a face of a surface: its children, their edges and its centre are on
      // the surface
      GFace *gf = ot->second;
      V m[4], o = nullptr;
      for(int i = 0; i < n; i++) m[i] = mid(f[i], f[(i + 1) % n], ge);
      if(n == 3) {
        V c[4][3] = {{f[0], m[0], m[2]},
                     {m[0], f[1], m[1]},
                     {m[2], m[1], f[2]},
                     {m[0], m[1], m[2]}};
        for(int i = 0; i < 4; i++) addSurface(gf, c[i], 3);
      }
      else {
        SPoint2 uv[4];
        surfaceParameters(f, 4, gf, uv);
        o = onSurface(gf, (uv[0] + uv[1] + uv[2] + uv[3]) * 0.25, f, 4,
                      std::max(edgeLength(f[0], f[2]), edgeLength(f[1], f[3])));
        V c4[4][4] = {{f[0], m[0], o, m[3]},
                      {m[0], f[1], m[1], o},
                      {o, m[1], f[2], m[2]},
                      {m[3], o, m[2], f[3]}};
        for(int i = 0; i < 4; i++) addSurface(gf, c4[i], 4);
      }
      return _split[k] = o;
    }
    V split(std::initializer_list<V> f, GEntity *ge)
    { return split(f.begin(), (int)f.size(), ge); }

    // how many times the edge was split
    int depth(V a, V b) const
    {
      V m = findMid(a, b);
      return m ? 1 + std::max(depth(a, m), depth(m, b)) : 0;
    }
    // the nodes inside the edge, from a to b
    void edgeNodes(V a, V b, std::vector<V> &out) const
    {
      V m = findMid(a, b);
      if(!m) return;
      edgeNodes(a, m, out);
      out.push_back(m);
      edgeNodes(m, b, out);
    }
    // the nodes around a face, hanging nodes included
    void ring(const V *f, int n, std::vector<V> &out) const
    {
      for(int i = 0; i < n; i++) {
        out.push_back(f[i]);
        edgeNodes(f[i], f[(i + 1) % n], out);
      }
    }
    // the faces a face is made of, down to the faces that are not split: the
    // nodes around each one, and its number of corners
    void faces(const V *f, int n, Rings &out) const
    {
      auto it = _split.find(FaceKey(f, n));
      if(it == _split.end()) {
        ring(f, n, out.nodes);
        out.offsets.push_back((int)out.nodes.size());
        out.corners.push_back(n);
        return;
      }
      V m[4];
      for(int i = 0; i < n; i++) m[i] = findMid(f[i], f[(i + 1) % n]);
      if(n == 3) {
        V c[4][3] = {{f[0], m[0], m[2]},
                     {m[0], f[1], m[1]},
                     {m[2], m[1], f[2]},
                     {m[0], m[1], m[2]}};
        for(int i = 0; i < 4; i++) faces(c[i], 3, out);
      }
      else {
        V o = it->second;
        V c[4][4] = {{f[0], m[0], o, m[3]},
                     {m[0], f[1], m[1], o},
                     {o, m[1], f[2], m[2]},
                     {m[3], o, m[2], f[3]}};
        for(int i = 0; i < 4; i++) faces(c[i], 4, out);
      }
    }

    // the longest edge
    double size(const Leaf &l) const
    {
      const Shape &s = shape(l.type);
      double h = 0.;
      for(int i = 0; i < s.numEdges; i++)
        h = std::max(h, edgeLength(l.v[s.edges[i][0]], l.v[s.edges[i][1]]));
      return h;
    }
    // does an edge of the element hold hanging nodes (more than maxDepth
    // levels of them if maxDepth > 0)?
    bool hanging(const Leaf &l, int maxDepth = 0) const
    {
      const Shape &s = shape(l.type);
      for(int i = 0; i < s.numEdges; i++) {
        V a = l.v[s.edges[i][0]], b = l.v[s.edges[i][1]];
        if(maxDepth ? depth(a, b) > maxDepth : findMid(a, b) != nullptr)
          return true;
      }
      return false;
    }

    void refine(const Leaf &l, GEntity *ge, std::vector<Leaf> &out)
    {
      const Shape &s = shape(l.type);
      const V *v = l.v;
      for(int i = 0; i < s.numFaces; i++) {
        V f[4];
        for(int j = 0; j < s.faceSize[i]; j++) f[j] = v[s.faces[i][j]];
        split(f, s.faceSize[i], ge);
      }
      auto add = [&](int type, std::initializer_list<V> nodes) {
        Leaf c;
        c.type = type;
        c.level = l.level + 1;
        c.sized = false;
        std::copy(nodes.begin(), nodes.end(), c.v);
        out.push_back(c);
      };
      auto m = [&](int i, int j) { return mid(v[i], v[j], ge); };

      switch(l.type) {
      case TYPE_TRI: {
        V m01 = m(0, 1), m12 = m(1, 2), m20 = m(2, 0);
        add(TYPE_TRI, {v[0], m01, m20});
        add(TYPE_TRI, {m01, v[1], m12});
        add(TYPE_TRI, {m20, m12, v[2]});
        add(TYPE_TRI, {m01, m12, m20});
      } break;
      case TYPE_QUA: {
        V m01 = m(0, 1), m12 = m(1, 2), m23 = m(2, 3), m30 = m(3, 0);
        V o = split(v, 4, ge);
        add(TYPE_QUA, {v[0], m01, o, m30});
        add(TYPE_QUA, {m01, v[1], m12, o});
        add(TYPE_QUA, {o, m12, v[2], m23});
        add(TYPE_QUA, {m30, o, m23, v[3]});
      } break;
      case TYPE_TET: {
        V m01 = m(0, 1), m02 = m(0, 2), m03 = m(0, 3), m12 = m(1, 2),
          m13 = m(1, 3), m23 = m(2, 3);
        add(TYPE_TET, {v[0], m01, m02, m03});
        add(TYPE_TET, {m01, v[1], m12, m13});
        add(TYPE_TET, {m02, m12, v[2], m23});
        add(TYPE_TET, {m03, m13, m23, v[3]});
        // the inner octahedron, cut along its shortest diagonal
        V d[3][2] = {{m01, m23}, {m02, m13}, {m03, m12}};
        int k = 0;
        for(int i = 1; i < 3; i++)
          if(edgeLength(d[i][0], d[i][1]) < edgeLength(d[k][0], d[k][1])) k = i;
        int i = (k + 1) % 3, j = (k + 2) % 3;
        V r[4] = {d[i][0], d[j][0], d[i][1], d[j][1]};
        for(int q = 0; q < 4; q++)
          add(TYPE_TET, {d[k][0], d[k][1], r[q], r[(q + 1) % 4]});
      } break;
      case TYPE_HEX: {
        // the 3x3x3 nodes of the refined hexahedron
        static const int corner[2][2][2] = {{{0, 4}, {3, 7}}, {{1, 5}, {2, 6}}};
        auto c = [&](int i, int j, int k) {
          return v[corner[i / 2][j / 2][k / 2]];
        };
        V g[3][3][3];
        for(int i = 0; i < 3; i++)
          for(int j = 0; j < 3; j++)
            for(int k = 0; k < 3; k++) {
              int ones = (i == 1) + (j == 1) + (k == 1);
              if(ones == 0)
                g[i][j][k] = c(i, j, k);
              else if(ones == 1) {
                if(i == 1)
                  g[i][j][k] = mid(c(0, j, k), c(2, j, k), ge);
                else if(j == 1)
                  g[i][j][k] = mid(c(i, 0, k), c(i, 2, k), ge);
                else
                  g[i][j][k] = mid(c(i, j, 0), c(i, j, 2), ge);
              }
              else if(ones == 2) {
                if(i != 1)
                  g[i][j][k] =
                    split({c(i, 0, 0), c(i, 2, 0), c(i, 2, 2), c(i, 0, 2)}, ge);
                else if(j != 1)
                  g[i][j][k] =
                    split({c(0, j, 0), c(2, j, 0), c(2, j, 2), c(0, j, 2)}, ge);
                else
                  g[i][j][k] =
                    split({c(0, 0, k), c(2, 0, k), c(2, 2, k), c(0, 2, k)}, ge);
              }
              else
                g[i][j][k] = newNode(v, 8, ge);
            }
        for(int i = 0; i < 2; i++)
          for(int j = 0; j < 2; j++)
            for(int k = 0; k < 2; k++)
              add(TYPE_HEX, {g[i][j][k], g[i + 1][j][k], g[i + 1][j + 1][k],
                             g[i][j + 1][k], g[i][j][k + 1], g[i + 1][j][k + 1],
                             g[i + 1][j + 1][k + 1], g[i][j + 1][k + 1]});
      } break;
      case TYPE_PRI: {
        V L[3][6] = {{v[0], v[1], v[2], m(0, 1), m(1, 2), m(2, 0)},
                     {m(0, 3), m(1, 4), m(2, 5),
                      split({v[0], v[1], v[4], v[3]}, ge),
                      split({v[1], v[2], v[5], v[4]}, ge),
                      split({v[2], v[0], v[3], v[5]}, ge)},
                     {v[3], v[4], v[5], m(3, 4), m(4, 5), m(5, 3)}};
        static const int t[4][3] = {{0, 3, 5}, {3, 1, 4}, {5, 4, 2}, {3, 4, 5}};
        for(int k = 0; k < 2; k++)
          for(int i = 0; i < 4; i++)
            add(TYPE_PRI,
                {L[k][t[i][0]], L[k][t[i][1]], L[k][t[i][2]], L[k + 1][t[i][0]],
                 L[k + 1][t[i][1]], L[k + 1][t[i][2]]});
      } break;
      case TYPE_PYR: {
        V b[4] = {m(0, 1), m(1, 2), m(2, 3), m(3, 0)};
        V a[4] = {m(0, 4), m(1, 4), m(2, 4), m(3, 4)};
        V o = split(v, 4, ge);
        add(TYPE_PYR, {v[0], b[0], o, b[3], a[0]});
        add(TYPE_PYR, {b[0], v[1], b[1], o, a[1]});
        add(TYPE_PYR, {o, b[1], v[2], b[2], a[2]});
        add(TYPE_PYR, {b[3], o, b[2], v[3], a[3]});
        add(TYPE_PYR, {a[0], a[1], a[2], a[3], v[4]});
        add(TYPE_PYR, {a[0], a[3], a[2], a[1], o});
        for(int i = 0; i < 4; i++)
          add(TYPE_TET, {b[i], o, a[i], a[(i + 1) % 4]});
      } break;
      }
    }
  };

  // is the size field smaller than h at a point of a grid of the element, with
  // n intervals along its edges?
  bool smallerOnGrid(const Leaf &l, int n, double h, Field *field, GEntity *ge)
  {
    double c[8][3];
    for(int i = 0; i < shape(l.type).numCorners; i++) {
      c[i][0] = l.v[i]->x();
      c[i][1] = l.v[i]->y();
      c[i][2] = l.v[i]->z();
    }
    // the point of weights w on the corners
    auto smaller = [&](const double *w, int nw) {
      double p[3] = {0., 0., 0.};
      for(int i = 0; i < nw; i++)
        for(int d = 0; d < 3; d++) p[d] += w[i] * c[i][d];
      return (*field)(p[0], p[1], p[2], ge) < h;
    };
    double w[8];
    switch(l.type) {
    case TYPE_TRI:
      for(int i = 0; i <= n; i++)
        for(int j = 0; i + j <= n; j++) {
          double a = (double)i / n, b = (double)j / n;
          w[0] = 1 - a - b, w[1] = a, w[2] = b;
          if(smaller(w, 3)) return true;
        }
      return false;
    case TYPE_TET:
      for(int i = 0; i <= n; i++)
        for(int j = 0; i + j <= n; j++)
          for(int k = 0; i + j + k <= n; k++) {
            double a = (double)i / n, b = (double)j / n, d = (double)k / n;
            w[0] = 1 - a - b - d, w[1] = a, w[2] = b, w[3] = d;
            if(smaller(w, 4)) return true;
          }
      return false;
    case TYPE_QUA:
      for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++) {
          double u = (double)i / n, v = (double)j / n;
          w[0] = (1 - u) * (1 - v), w[1] = u * (1 - v), w[2] = u * v,
          w[3] = (1 - u) * v;
          if(smaller(w, 4)) return true;
        }
      return false;
    case TYPE_HEX:
      for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++)
          for(int k = 0; k <= n; k++) {
            double u = (double)i / n, v = (double)j / n, t = (double)k / n;
            double q[4] = {(1 - u) * (1 - v), u * (1 - v), u * v, (1 - u) * v};
            for(int m = 0; m < 4; m++) {
              w[m] = (1 - t) * q[m];
              w[m + 4] = t * q[m];
            }
            if(smaller(w, 8)) return true;
          }
      return false;
    case TYPE_PRI:
      for(int i = 0; i <= n; i++)
        for(int j = 0; i + j <= n; j++)
          for(int k = 0; k <= n; k++) {
            double a = (double)i / n, b = (double)j / n, t = (double)k / n;
            double q[3] = {1 - a - b, a, b};
            for(int m = 0; m < 3; m++) {
              w[m] = (1 - t) * q[m];
              w[m + 3] = t * q[m];
            }
            if(smaller(w, 6)) return true;
          }
      return false;
    default: // pyramid: square sections shrinking to the apex
      for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++)
          for(int k = 0; k <= n; k++) {
            double u = (double)i / n, v = (double)j / n, t = (double)k / n;
            w[0] = (1 - t) * (1 - u) * (1 - v), w[1] = (1 - t) * u * (1 - v),
            w[2] = (1 - t) * u * v, w[3] = (1 - t) * (1 - u) * v, w[4] = t;
            if(smaller(w, 5)) return true;
          }
      return false;
    }
  }

  // the corners of an element, for a leaf
  bool leaf(MElement *e, Leaf &l)
  {
    if(e->getPolynomialOrder() > 1) {
      Msg::Error("Plugin(NonConformalRefinement) only refines first order "
                 "elements");
      return false;
    }
    l.type = e->getType();
    l.level = 0;
    l.sized = false;
    for(std::size_t i = 0; i < e->getNumVertices(); i++)
      l.v[i] = e->getVertex(i);
    return true;
  }

  // is the Jacobian of a volume element with a node on the boundary negative at
  // one of its corners (except at the apex of a pyramid)?
  bool isInverted(MElement *e)
  {
    bool boundary = false;
    for(std::size_t i = 0; i < e->getNumVertices() && !boundary; i++)
      if(e->getVertex(i)->onWhat()->dim() < 3) boundary = true;
    if(!boundary) return false;
    int n = (e->getType() == TYPE_PYR) ? 4 : (int)e->getNumVertices();
    for(int i = 0; i < n; i++) {
      double u, v, w;
      e->getNode(i, u, v, w);
      if(e->getJacobianDeterminant(u, v, w) <= 0.) return true;
    }
    return false;
  }

  // a standard element, positively oriented
  MElement *standardElement(const Leaf &l)
  {
    const V *v = l.v;
    switch(l.type) {
    case TYPE_TRI: return new MTriangle(v[0], v[1], v[2]);
    case TYPE_QUA: return new MQuadrangle(v[0], v[1], v[2], v[3]);
    case TYPE_TET: {
      auto e = new MTetrahedron(v[0], v[1], v[2], v[3]);
      if(e->getVolume() < 0.) e->reverse();
      return e;
    }
    case TYPE_HEX:
      return new MHexahedron(v[0], v[1], v[2], v[3], v[4], v[5], v[6], v[7]);
    case TYPE_PRI: return new MPrism(v[0], v[1], v[2], v[3], v[4], v[5]);
    default: {
      auto e = new MPyramid(v[0], v[1], v[2], v[3], v[4]);
      if(e->getVolumeSign() < 0) e->reverse();
      return e;
    }
    }
  }

} // namespace

int GMSH_NonConformalRefinementPlugin::run()
{
  GModel *m = GModel::current();
  FieldManager *fields = m->getFields();
  int tag = (int)option(0);
  if(tag < 0) tag = fields->getBackgroundField();
  Field *field = fields->get(tag);
  if(!field) {
    Msg::Error("Plugin(NonConformalRefinement) requires a mesh size field");
    return 0;
  }
  field->ensureUpdated();
  int maxLevel = (int)option(1);
  int balance = std::max(0, (int)option(2));
  bool onGeometry = (int)option(3);
  double sampleSpacing = option(4);

  double t0 = TimeOfDay();

  int dim = 2;
  for(auto gr : m->getRegions())
    if(gr->getNumMeshElements()) dim = 3;

  // the elements to refine, of the highest dimension
  std::vector<GEntity *> entities;
  std::vector<std::vector<Leaf>> leaves;
  if(dim == 3) {
    for(auto gr : m->getRegions()) {
      std::vector<MElement *> elements;
      elements.insert(elements.end(), gr->tetrahedra.begin(),
                      gr->tetrahedra.end());
      elements.insert(elements.end(), gr->hexahedra.begin(),
                      gr->hexahedra.end());
      elements.insert(elements.end(), gr->prisms.begin(), gr->prisms.end());
      elements.insert(elements.end(), gr->pyramids.begin(), gr->pyramids.end());
      if(elements.empty()) continue;
      entities.push_back(gr);
      leaves.emplace_back(elements.size());
      for(std::size_t i = 0; i < elements.size(); i++)
        if(!leaf(elements[i], leaves.back()[i])) return 0;
    }
  }
  else {
    for(auto gf : m->getFaces()) {
      std::vector<MElement *> elements;
      elements.insert(elements.end(), gf->triangles.begin(),
                      gf->triangles.end());
      elements.insert(elements.end(), gf->quadrangles.begin(),
                      gf->quadrangles.end());
      if(elements.empty()) continue;
      entities.push_back(gf);
      leaves.emplace_back(elements.size());
      for(std::size_t i = 0; i < elements.size(); i++)
        if(!leaf(elements[i], leaves.back()[i])) return 0;
    }
  }
  if(entities.empty()) {
    Msg::Warning("Plugin(NonConformalRefinement): no elements to refine");
    return 0;
  }

  // the elements of lower dimension, which follow
  std::vector<std::pair<GFace *, std::vector<Leaf>>> faces;
  if(dim == 3) {
    for(auto gf : m->getFaces()) {
      std::vector<Leaf> l(gf->triangles.size() + gf->quadrangles.size());
      for(std::size_t i = 0; i < gf->triangles.size(); i++)
        if(!leaf(gf->triangles[i], l[i])) return 0;
      for(std::size_t i = 0; i < gf->quadrangles.size(); i++)
        if(!leaf(gf->quadrangles[i], l[gf->triangles.size() + i])) return 0;
      if(l.size()) faces.push_back({gf, l});
    }
  }
  std::vector<std::pair<GEdge *, std::vector<std::array<V, 2>>>> lines;
  for(auto ge : m->getEdges()) {
    std::vector<std::array<V, 2>> l;
    for(auto e : ge->lines) {
      if(e->getPolynomialOrder() > 1) {
        Msg::Error("Plugin(NonConformalRefinement) only refines first order "
                   "elements");
        return 0;
      }
      l.push_back({e->getVertex(0), e->getVertex(1)});
    }
    if(l.size()) lines.push_back({ge, l});
  }

  // place the new nodes of the curves and surfaces on the geometry
  Refiner r;
  if(onGeometry) {
    for(auto &l : lines)
      if(l.first->haveParametrization())
        for(auto &e : l.second) r.addCurve(l.first, e[0], e[1]);
    for(auto &f : faces)
      if(f.first->haveParametrization())
        for(auto &l : f.second)
          r.addSurface(f.first, l.v, shape(l.type).numCorners);
    if(dim == 2)
      for(std::size_t e = 0; e < entities.size(); e++)
        if(entities[e]->haveParametrization())
          for(auto &l : leaves[e])
            r.addSurface(static_cast<GFace *>(entities[e]), l.v,
                         shape(l.type).numCorners);
  }

  // refine until all the elements are small enough
  for(int pass = 1;; pass++) {
    std::size_t refined = 0, total = 0;
    for(std::size_t e = 0; e < entities.size(); e++) {
      // the elements larger than the size field, in parallel (the fields are
      // only read during a pass)
      std::vector<Leaf> &ls = leaves[e];
      std::vector<char> large(ls.size(), 0);
      int nthreads = CTX::instance()->numThreadsFor(ls.size(), 1000);
#pragma omp parallel for schedule(dynamic, 256) num_threads(nthreads)
      for(std::size_t k = 0; k < ls.size(); k++) {
        Leaf &l = ls[k];
        if(l.level >= maxLevel || l.sized) continue;
        // on a grid with points at most sampleSpacing apart, corners and edge
        // midpoints included, which sees a region of small sizes touching the
        // element: no element then touches a region of smaller sizes, but the
        // levels can only grow one by one away from it
        if(sampleSpacing > 0.) {
          double h = r.size(l);
          int n = std::max(2, (int)std::ceil(h / sampleSpacing));
          if(smallerOnGrid(l, n, h, field, entities[e]))
            large[k] = 1;
          else
            l.sized = true;
          continue;
        }
        // otherwise at the middle of the edges and at the centre, which only
        // sees a region of small sizes reaching half way across the element
        const Shape &s = shape(l.type);
        int n = s.numCorners;
        double x = 0., y = 0., z = 0.;
        double size = std::numeric_limits<double>::max();
        for(int i = 0; i < n; i++) {
          V v = l.v[i];
          x += v->x();
          y += v->y();
          z += v->z();
        }
        size = std::min(size, (*field)(x / n, y / n, z / n, entities[e]));
        for(int i = 0; i < s.numEdges; i++) {
          V a = l.v[s.edges[i][0]], b = l.v[s.edges[i][1]];
          size = std::min(size, (*field)(0.5 * (a->x() + b->x()),
                                         0.5 * (a->y() + b->y()),
                                         0.5 * (a->z() + b->z()), entities[e]));
        }
        if(r.size(l) > size)
          large[k] = 1;
        else
          l.sized = true;
      }

      // refine them, and the ones that are not balanced
      std::vector<Leaf> next;
      next.reserve(ls.size());
      for(std::size_t k = 0; k < ls.size(); k++) {
        Leaf &l = ls[k];
        bool split = large[k];
        if(!split && balance && l.level < maxLevel && r.hanging(l, balance))
          split = true;
        if(split) {
          r.refine(l, entities[e], next);
          refined++;
        }
        else
          next.push_back(l);
      }
      leaves[e].swap(next);
      total += leaves[e].size();
    }
    Msg::Info("Pass %d: %zu elements refined, %zu elements (%g s)", pass,
              refined, total, TimeOfDay() - t0);
    if(!refined) break;
  }

  double t1 = TimeOfDay();

  // replace the mesh: the elements of highest dimension...
  std::size_t numPolytopes = 0, numElements = 0;
  Rings rings;
  for(std::size_t e = 0; e < entities.size(); e++) {
    if(dim == 3) {
      GRegion *gr = static_cast<GRegion *>(entities[e]);
      for(auto el : gr->tetrahedra) delete el;
      for(auto el : gr->hexahedra) delete el;
      for(auto el : gr->prisms) delete el;
      for(auto el : gr->pyramids) delete el;
      gr->tetrahedra.clear();
      gr->hexahedra.clear();
      gr->prisms.clear();
      gr->pyramids.clear();
      for(auto &l : leaves[e]) {
        if(!r.hanging(l)) {
          gr->addElement(standardElement(l));
          continue;
        }
        const Shape &s = shape(l.type);
        rings.clear();
        for(int i = 0; i < s.numFaces; i++) {
          V f[4];
          for(int j = 0; j < s.faceSize[i]; j++) f[j] = l.v[s.faces[i][j]];
          r.faces(f, s.faceSize[i], rings);
        }
        // a polyhedron, cut into tetrahedra from its centre
        std::vector<V> tets, tris;
        V o = r.newNode(l.v, s.numCorners, gr);
        for(int i = 0; i < rings.size(); i++) {
          tris.clear();
          triangulate(rings.ring(i), rings.ringSize(i), tris);
          for(std::size_t j = 0; j < tris.size(); j += 3)
            tets.insert(tets.end(), {o, tris[j], tris[j + 1], tris[j + 2]});
        }
        auto p = new MPolyhedron(rings.nodes);
        p->setPolygonsAndTetrahedra(rings.nodes, rings.offsets, tets);
        gr->addPolyhedron(p);
        numPolytopes++;
      }
      numElements += gr->getNumMeshElements();
    }
    else {
      GFace *gf = static_cast<GFace *>(entities[e]);
      for(auto el : gf->triangles) delete el;
      for(auto el : gf->quadrangles) delete el;
      gf->triangles.clear();
      gf->quadrangles.clear();
      for(auto &l : leaves[e]) {
        const Shape &s = shape(l.type);
        std::vector<V> ring, tris;
        r.ring(l.v, s.numCorners, ring);
        if((int)ring.size() == s.numCorners) {
          gf->addElement(standardElement(l));
          continue;
        }
        // a polygon, triangulated without new nodes
        auto p = new MPolygon(ring);
        triangulate(ring.data(), (int)ring.size(), tris);
        p->setTriangles(tris);
        gf->addPolygon(p);
        numPolytopes++;
      }
      numElements += gf->getNumMeshElements();
    }
  }

  // ... the faces of the volumes, with their new nodes...
  for(auto &f : faces) {
    GFace *gf = f.first;
    for(auto el : gf->triangles) delete el;
    for(auto el : gf->quadrangles) delete el;
    gf->triangles.clear();
    gf->quadrangles.clear();
    for(auto &l : f.second) {
      rings.clear();
      r.faces(l.v, shape(l.type).numCorners, rings);
      for(int i = 0; i < rings.size(); i++) {
        const V *ring = rings.ring(i);
        int n = rings.ringSize(i);
        for(int j = 0; j < n; j++)
          if(ring[j]->onWhat()->dim() > 2) ring[j]->setEntity(gf);
        if(n == rings.corners[i]) {
          Leaf c;
          c.type = (n == 3) ? TYPE_TRI : TYPE_QUA;
          std::copy(ring, ring + n, c.v);
          gf->addElement(standardElement(c));
        }
        else {
          std::vector<V> tris;
          auto p = new MPolygon(std::vector<V>(ring, ring + n));
          triangulate(ring, n, tris);
          p->setTriangles(tris);
          gf->addPolygon(p);
        }
      }
    }
  }

  // ... and the lines
  for(auto &l : lines) {
    GEdge *ge = l.first;
    for(auto el : ge->lines) delete el;
    ge->lines.clear();
    for(auto &e : l.second) {
      std::vector<V> nodes(1, e[0]);
      r.edgeNodes(e[0], e[1], nodes);
      nodes.push_back(e[1]);
      for(std::size_t i = 0; i + 1 < nodes.size(); i++) {
        if(nodes[i]->onWhat()->dim() > 1) nodes[i]->setEntity(ge);
        ge->addLine(new MLine(nodes[i], nodes[i + 1]));
      }
    }
  }

  for(auto v : r.newNodes) v->onWhat()->addMeshVertex(v);

  // put back on the straight edges the nodes of the volume elements that the
  // geometry inverts
  if(dim == 3 && r.straight.size()) {
    std::size_t moved = 0, inverted = 0;
    for(int pass = 0; pass < 2; pass++) {
      for(auto ge : entities) {
        for(std::size_t i = 0; i < ge->getNumMeshElements(); i++) {
          MElement *e = ge->getMeshElement(i);
          if(e->getType() == TYPE_POLYH || !isInverted(e)) continue;
          if(pass) {
            inverted++;
            continue;
          }
          for(std::size_t j = 0; j < e->getNumVertices(); j++) {
            auto it = r.straight.find(e->getVertex(j));
            if(it == r.straight.end()) continue;
            e->getVertex(j)->setXYZ(it->second.x(), it->second.y(),
                                    it->second.z());
            r.straight.erase(it);
            moved++;
          }
        }
      }
    }
    if(moved)
      Msg::Warning("%zu nodes left on the straight edges, to avoid inverting "
                   "elements",
                   moved);
    if(inverted) Msg::Warning("%zu inverted elements", inverted);
  }

  m->destroyMeshCaches();
  CTX::instance()->meshChanged();

  Msg::Info("Refined mesh: %zu elements of dimension %d, of which %zu "
            "polytopes, %zu new nodes (refinement %g s, mesh %g s)",
            numElements, dim, numPolytopes, r.newNodes.size(), t1 - t0,
            TimeOfDay() - t1);
  return 1;
}
