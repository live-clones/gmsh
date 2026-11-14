// Gmsh Dual Mesh Plugin - Copyright (C) 2026 C. Geuzaine and J.-F. Remacle
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
#include <cstdint>
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
#include "Context.h"
#include "Hash.h"
#include "OS.h"
#include "DualMesh.h"

GMSH_DualMeshPlugin::GMSH_DualMeshPlugin()
  : GMSH_MeshPlugin({{GMSH_FULLRC, "Voronoi", nullptr, 0.}})
{
}

std::string GMSH_DualMeshPlugin::getHelp() const
{
  return "Plugin(DualMesh) replaces the first order mesh of the current model "
         "by its barycentric dual: each node becomes a polygon (in 2D) or a "
         "polyhedron (in 3D) around it, one for each surface or volume it "
         "belongs to, whose vertices are the centres of the elements, the "
         "centres of their faces and the middles of their edges around the "
         "node, and the node itself if it lies on a curve. The polygons are "
         "subdivided into the triangles and the polyhedra into the "
         "tetrahedra of the barycentric subdivision of the elements, which "
         "are valid whenever the elements are. The lines on curves are split "
         "at their middle.\n\n"
         "If `Voronoi' is set, the triangles of a 2D mesh and the "
         "tetrahedra of a 3D mesh are represented by their circumcentres, and "
         "the middles of the edges and the centres of the faces between two "
         "of them are dropped: the cells are then the Voronoi cells of the "
         "nodes where the mesh is Delaunay. Each cell is subdivided into the "
         "triangles or the tetrahedra joining its node to fans of triangles "
         "on its edges or faces, and an element whose circumcentre would "
         "invert one of these is represented by its centre instead: its "
         "circumcentre if it lies inside, its centroid otherwise (as are the "
         "triangles of the surfaces of a 3D mesh, and the triangular faces).";
}

namespace {

  typedef MVertex *V;
  typedef std::uintptr_t P;

  // the keys of the hash tables compare the node pointers (the tables are
  // never iterated, so their order does not matter)
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

  struct FaceKey {
    std::array<V, 4> v;
    FaceKey() : v{nullptr, nullptr, nullptr, nullptr} {}
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

  // the edges and the faces of the element types, in the Gmsh node ordering
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

  const Shape *shape(int type)
  {
    switch(type) {
    case TYPE_TRI: return &triShape;
    case TYPE_QUA: return &quaShape;
    case TYPE_TET: return &tetShape;
    case TYPE_HEX: return &hexShape;
    case TYPE_PRI: return &priShape;
    case TYPE_PYR: return &pyrShape;
    default: return nullptr;
    }
  }

  // order items around a centre, each item being linked to two others by the
  // keys it shares with them: the sequence of (item, key in, key out), from an
  // end if the chain is open (a key used once); false if not all the items
  // could be chained (several fans)
  template <class K>
  bool chain(const std::vector<std::array<K, 2>> &links,
             std::vector<std::pair<int, std::array<K, 2>>> &seq, bool &open)
  {
    int n = (int)links.size();
    seq.clear();
    open = false;
    if(!n) return true;
    // an end: a key used once
    int start = 0, side = 0;
    for(int i = 0; i < n && !open; i++)
      for(int j = 0; j < 2 && !open; j++) {
        int c = 0;
        for(int k = 0; k < n && c < 2; k++)
          c += (links[k][0] == links[i][j]) + (links[k][1] == links[i][j]);
        if(c == 1) {
          start = i;
          side = j;
          open = true;
        }
      }
    std::vector<char> done(n, 0);
    int cur = start;
    K in = links[start][side];
    while(true) {
      done[cur] = 1;
      K out = (links[cur][0] == in) ? links[cur][1] : links[cur][0];
      seq.push_back({cur, {in, out}});
      int next = -1;
      for(int i = 0; i < n && next < 0; i++)
        if(!done[i] && (links[i][0] == out || links[i][1] == out)) next = i;
      if(next < 0) break;
      in = out;
      cur = next;
    }
    return (int)seq.size() == n;
  }

  SVector3 pos(V v) { return SVector3(v->x(), v->y(), v->z()); }

  // the circumcentre of a triangle (n = 3) or of a tetrahedron (n = 4), and
  // whether it lies inside, its barycentric coordinates all above a small
  // tolerance; false if the simplex is flat
  bool circumcentre(const V *v, int n, SVector3 &c, bool &inside)
  {
    const double eps = 1e-6;
    SVector3 a = pos(v[0]), u = pos(v[1]) - a, w = pos(v[2]) - a, p;
    double l[4];
    if(n == 3) {
      SVector3 uw = crossprod(u, w);
      double n2 = dot(uw, uw);
      if(n2 <= 0.) return false;
      p = (dot(w, w) * crossprod(uw, u) + dot(u, u) * crossprod(w, uw)) *
          (0.5 / n2);
      l[1] = dot(crossprod(p, w), uw) / n2;
      l[2] = dot(crossprod(u, p), uw) / n2;
      l[0] = 1. - l[1] - l[2];
    }
    else {
      SVector3 t = pos(v[3]) - a;
      SVector3 wt = crossprod(w, t), tu = crossprod(t, u), uw = crossprod(u, w);
      double det = dot(u, wt);
      if(det == 0.) return false;
      p = (dot(u, u) * wt + dot(w, w) * tu + dot(t, t) * uw) * (0.5 / det);
      l[1] = dot(p, wt) / det;
      l[2] = dot(p, tu) / det;
      l[3] = dot(p, uw) / det;
      l[0] = 1. - l[1] - l[2] - l[3];
    }
    c = a + p;
    inside = true;
    for(int i = 0; i < n; i++) inside &= l[i] >= eps;
    return true;
  }

  // the centre of an element or a face: its circumcentre if circumcentres are
  // asked for and it is a simplex holding it, its centroid otherwise
  SVector3 centrePoint(const V *v, int n, bool circumcentres, bool &circ)
  {
    SVector3 c(0., 0., 0.);
    circ = false;
    if(circumcentres && (n == 3 || n == 4) && circumcentre(v, n, c, circ) &&
       circ)
      return c;
    c = SVector3(0., 0., 0.);
    for(int i = 0; i < n; i++) c += pos(v[i]);
    return c * (1. / n);
  }

  class Dual {
  private:
    std::unordered_map<EdgeKey, V, EdgeHash> _mid;
    std::unordered_map<FaceKey, V, FaceHash> _centre;

  public:
    // the curve or surface holding an edge, the surface holding a face
    std::unordered_map<EdgeKey, GEntity *, EdgeHash> edgeOwner;
    std::unordered_map<FaceKey, GFace *, FaceHash> faceOwner;
    std::vector<V> newNodes;

    // the centres of the triangles and the tetrahedra at their circumcentres
    // when these lie inside, and how many elements use their circumcentre (or
    // not)
    bool voronoi = false;
    std::size_t numCircum[2] = {0, 0}, numCentroid[2] = {0, 0};

    // the centre of an element or a face (simplex is false for quadrangles)
    V centreNode(const V *v, int n, bool simplex, GEntity *ge)
    {
      bool circ;
      SVector3 c = centrePoint(v, n, voronoi && simplex, circ);
      if(voronoi && simplex) {
        numCircum[n - 3] += circ;
        numCentroid[n - 3] += !circ;
      }
      return newNode(c, ge);
    }
    V newNode(const SVector3 &c, GEntity *ge)
    {
      V nv = new MVertex(c.x(), c.y(), c.z(), ge);
      newNodes.push_back(nv);
      return nv;
    }
    // the middle of an edge, on the curve or surface holding it if any
    V mid(V a, V b, GEntity *ge)
    {
      EdgeKey k(a, b);
      auto it = _mid.find(k);
      if(it != _mid.end()) return it->second;
      auto ot = edgeOwner.find(k);
      return _mid[k] = newNode((pos(a) + pos(b)) * 0.5,
                               ot == edgeOwner.end() ? ge : ot->second);
    }
    // the centre of a face, on the surface holding it if any
    V centre(const V *f, int n, GEntity *ge)
    {
      FaceKey k(f, n);
      auto it = _centre.find(k);
      if(it != _centre.end()) return it->second;
      auto ot = faceOwner.find(k);
      return _centre[k] =
               centreNode(f, n, n == 3,
                          ot == faceOwner.end() ? ge : (GEntity *)ot->second);
    }
  };

  void corners(MElement *e, V *v)
  {
    for(int i = 0; i < shape(e->getType())->numCorners; i++)
      v[i] = e->getVertex(i);
  }

  // the dual of the 2D elements of a surface: a polygon around each node,
  // whose vertices are the centres of the elements around it and the middles
  // of the edges between them, plus the node itself and the middles of its
  // edges on the boundary of the surface. The polygons are subdivided into
  // the triangles joining their node to their edges: the triangles of the
  // barycentric subdivision of the elements. With circumcentres, the triangles
  // are represented by their circumcentres wherever these lie, and the middles
  // of the edges between two such triangles are dropped (unless the edges are
  // on a curve): the polygon of a node whose triangles all are is then its
  // Voronoi cell. A triangle whose circumcentre inverts one of the triangles
  // of the subdivision falls back to its centre, until all are valid.
  void dual2D(GFace *gf, std::vector<MElement *> &elements, bool circumcentres,
              Dual &d, std::vector<MPolygon *> &polygons, int &passes)
  {
    // the centre of each element, and its circumcentre (state 0) if asked for
    int ne = (int)elements.size();
    std::vector<V> ev(4 * ne);
    std::vector<SVector3> circ(ne), cent(ne), normal(ne);
    std::vector<char> state(ne, 1);
    std::unordered_map<V, std::vector<std::pair<int, int>>> around;
    for(int e = 0; e < ne; e++) {
      int n = shape(elements[e]->getType())->numCorners;
      corners(elements[e], &ev[4 * e]);
      for(int i = 0; i < n; i++) around[ev[4 * e + i]].push_back({e, i});
      bool in;
      cent[e] = centrePoint(&ev[4 * e], n, d.voronoi && n == 3, in);
      normal[e] = elements[e]->getFace(0).normal();
      if(n == 3 && circumcentres && circumcentre(&ev[4 * e], 3, circ[e], in))
        state[e] = 0;
    }

    // the elements around each node, in order: (element, node in, node out),
    // and whether the edge to the node out is on a curve
    std::vector<V> nodes;
    std::vector<int> seqStart(1, 0);
    std::vector<std::pair<int, std::array<V, 2>>> seqs;
    std::vector<char> open, onCurve;
    {
      std::vector<std::array<V, 2>> links;
      std::vector<std::pair<int, std::array<V, 2>>> seq;
      for(auto &a : around) {
        V v = a.first;
        links.clear();
        for(auto &ei : a.second) {
          int e = ei.first, i = ei.second;
          int n = shape(elements[e]->getType())->numCorners;
          links.push_back(
            {ev[4 * e + (i + n - 1) % n], ev[4 * e + (i + 1) % n]});
        }
        bool o;
        if(!chain(links, seq, o))
          Msg::Warning("Node %zu has several fans of elements on surface %d",
                       v->getNum(), gf->tag());
        nodes.push_back(v);
        open.push_back(o);
        for(auto &s : seq) {
          seqs.push_back({a.second[s.first].first, s.second});
          auto it = d.edgeOwner.find(EdgeKey(v, s.second[1]));
          onCurve.push_back(it != d.edgeOwner.end() && it->second->dim() == 1);
        }
        seqStart.push_back((int)seqs.size());
      }
    }
    around.clear();
    int nn = (int)nodes.size();

    // the polygon of a node, as references to the centre of an element (>=
    // 0), to the middle of the edge to a node (-1) or to the node itself (-2)
    typedef std::pair<int, V> Ref;
    auto ring = [&](int k, std::vector<Ref> &r) {
      r.clear();
      int s0 = seqStart[k], n = seqStart[k + 1] - s0;
      if(open[k]) {
        r.push_back({-2, nodes[k]});
        r.push_back({-1, seqs[s0].second[0]});
      }
      for(int j = 0; j < n; j++) {
        int e = seqs[s0 + j].first;
        r.push_back({e, nullptr});
        if((open[k] && j == n - 1) || onCurve[s0 + j] || state[e] ||
           state[seqs[s0 + (j + 1) % n].first])
          r.push_back({-1, seqs[s0 + j].second[1]});
      }
    };
    auto position = [&](const Ref &x, V v) {
      if(x.first >= 0) return state[x.first] ? cent[x.first] : circ[x.first];
      if(x.first == -1) return (pos(v) + pos(x.second)) * 0.5;
      return pos(v);
    };

    // fall back to the centres until the triangles (node, edge) are positive
    std::vector<Ref> r;
    passes = 0;
    for(bool changed = circumcentres; changed; passes++) {
      changed = false;
      for(int k = 0; k < nn; k++) {
        ring(k, r);
        bool circumcentres = false;
        for(auto &x : r) circumcentres |= (x.first >= 0 && !state[x.first]);
        if(!circumcentres) continue;
        // the orientation of the polygon, from its triangle (node, middle of
        // the edge in, centre of the first element) in the barycentric
        // subdivision
        V v = nodes[k];
        int s0 = seqStart[k], e0 = seqs[s0].first, n = (int)r.size();
        SVector3 pv = pos(v), m0 = (pv + pos(seqs[s0].second[0])) * 0.5;
        double sign =
          dot(crossprod(m0 - pv, cent[e0] - pv), normal[e0]) > 0. ? 1. : -1.;
        double tol = 1e-12 * (m0 - pv).normSq();
        for(int i = 0; i < n; i++) {
          const Ref &p = r[i], &q = r[(i + 1) % n];
          if(p.first == -2 || q.first == -2) continue;
          SVector3 t =
            sign * crossprod(position(p, v) - pv, position(q, v) - pv);
          if((p.first < 0 || dot(t, normal[p.first]) > tol) &&
             (q.first < 0 || dot(t, normal[q.first]) > tol))
            continue;
          // the circumcentres of the triangle, or else of the whole polygon
          bool fixed = false;
          for(auto &x : {p, q})
            if(x.first >= 0 && !state[x.first]) {
              state[x.first] = 1;
              fixed = true;
            }
          if(!fixed)
            for(auto &x : r)
              if(x.first >= 0) state[x.first] = 1;
          changed = true;
          break;
        }
      }
    }

    // the polygons
    std::vector<V> elementNode(ne, nullptr), poly, tris;
    for(int k = 0; k < nn; k++) {
      V v = nodes[k];
      ring(k, r);
      poly.clear();
      for(auto &x : r) {
        if(x.first == -2)
          poly.push_back(v);
        else if(x.first == -1)
          poly.push_back(d.mid(v, x.second, gf));
        else {
          int e = x.first;
          if(!elementNode[e]) {
            if(state[e]) {
              int n = shape(elements[e]->getType())->numCorners;
              elementNode[e] = d.centre(&ev[4 * e], n, gf);
            }
            else {
              elementNode[e] = d.newNode(circ[e], gf);
              d.numCircum[0]++;
            }
          }
          poly.push_back(elementNode[e]);
        }
      }
      tris.clear();
      int n = (int)poly.size();
      for(int i = 0; i < n; i++) {
        V p = poly[i], q = poly[(i + 1) % n];
        if(p != v && q != v) tris.insert(tris.end(), {v, p, q});
      }
      // orient the polygon like the elements
      SVector3 n0 = normal[seqs[seqStart[k]].first], nr(0., 0., 0.);
      for(int i = 0; i < n; i++)
        nr += crossprod(pos(poly[i]), pos(poly[(i + 1) % n]));
      if(dot(nr, n0) < 0.) std::reverse(poly.begin(), poly.end());
      auto p = new MPolygon(poly);
      p->setTriangles(tris);
      polygons.push_back(p);
    }
  }

  // the faces holding each edge of a shape
  struct Topology {
    int edgeFaces[12][2];
    explicit Topology(const Shape &s)
    {
      for(int k = 0; k < s.numEdges; k++) {
        int a = s.edges[k][0], b = s.edges[k][1], n = 0;
        for(int f = 0; f < s.numFaces; f++) {
          bool ha = false, hb = false;
          for(int j = 0; j < s.faceSize[f]; j++) {
            ha |= s.faces[f][j] == a;
            hb |= s.faces[f][j] == b;
          }
          if(ha && hb && n < 2) edgeFaces[k][n++] = f;
        }
      }
    }
  };

  const Topology &topology(int type)
  {
    static const Topology tet(tetShape), hex(hexShape), pri(priShape),
      pyr(pyrShape);
    switch(type) {
    case TYPE_TET: return tet;
    case TYPE_HEX: return hex;
    case TYPE_PRI: return pri;
    default: return pyr;
    }
  }

  // the dual of the 3D elements of a volume: a polyhedron around each node,
  // whose faces are dual to the edges at the node. The vertices of the dual
  // face of an edge are the centres of the elements around it and of the faces
  // between them, plus the middle of the edge if it is on the boundary of the
  // volume. The polyhedra are subdivided into the tetrahedra joining their
  // node to a fan of triangles on each of their faces, centred at the middle
  // of the edge: these are the tetrahedra of the barycentric subdivision of
  // the elements. With circumcentres, the tetrahedra are represented by their
  // circumcentres wherever these lie, and the faces between two such
  // tetrahedra are dropped: the dual face of an edge whose tetrahedra all are
  // is then its Voronoi face, fanned from one of its vertices. A tetrahedron
  // whose circumcentre inverts one of the tetrahedra of the subdivision falls
  // back to its centre, until all are valid.
  void dual3D(GRegion *gr, std::vector<MElement *> &elements,
              bool circumcentres, Dual &d,
              std::vector<MPolyhedron *> &polyhedra, int &passes)
  {
    // the centre of each element, and its circumcentre (state 0) if asked for
    int ne = (int)elements.size();
    std::vector<V> ev(8 * ne);
    std::vector<SVector3> circ(ne), cent(ne);
    std::vector<char> state(ne, 1), inside(ne, 0);
    for(int e = 0; e < ne; e++) {
      int type = elements[e]->getType(), n = shape(type)->numCorners;
      corners(elements[e], &ev[8 * e]);
      bool in;
      cent[e] = centrePoint(&ev[8 * e], n, d.voronoi && type == TYPE_TET, in);
      inside[e] = in;
      if(type == TYPE_TET && circumcentres &&
         circumcentre(&ev[8 * e], 4, circ[e], in))
        state[e] = 0;
    }

    // the faces and the edges
    std::unordered_map<FaceKey, int, FaceHash> faceIds;
    std::vector<std::array<int, 2>> faceElements;
    std::vector<std::array<V, 4>> faceVerts;
    std::vector<char> faceSize;
    std::vector<int> elementFace(6 * ne);
    std::unordered_map<EdgeKey, int, EdgeHash> edgeIds;
    std::vector<std::array<V, 2>> edgeVerts;
    std::vector<std::vector<std::pair<int, int>>> edgeElements;
    for(int e = 0; e < ne; e++) {
      const Shape &s = *shape(elements[e]->getType());
      for(int f = 0; f < s.numFaces; f++) {
        std::array<V, 4> fv = {nullptr, nullptr, nullptr, nullptr};
        for(int j = 0; j < s.faceSize[f]; j++)
          fv[j] = ev[8 * e + s.faces[f][j]];
        auto it = faceIds.insert(
          {FaceKey(fv.data(), s.faceSize[f]), (int)faceElements.size()});
        if(it.second) {
          faceElements.push_back({e, -1});
          faceVerts.push_back(fv);
          faceSize.push_back(s.faceSize[f]);
        }
        else
          faceElements[it.first->second][1] = e;
        elementFace[6 * e + f] = it.first->second;
      }
      for(int k = 0; k < s.numEdges; k++) {
        V a = ev[8 * e + s.edges[k][0]], b = ev[8 * e + s.edges[k][1]];
        auto it = edgeIds.insert({EdgeKey(a, b), (int)edgeVerts.size()});
        if(it.second) {
          edgeVerts.push_back({a, b});
          edgeElements.emplace_back();
        }
        edgeElements[it.first->second].push_back({e, k});
      }
    }
    faceIds.clear();
    edgeIds.clear();
    int nf = (int)faceElements.size(), nd = (int)edgeVerts.size();

    // the faces on a surface, which are never dropped
    std::vector<char> onSurface(nf);
    for(int f = 0; f < nf; f++)
      onSurface[f] =
        d.faceOwner.count(FaceKey(faceVerts[f].data(), faceSize[f])) > 0;

    // the centre of each face, as in Dual::centre
    std::vector<SVector3> faceCentre(nf);
    for(int f = 0; f < nf; f++) {
      bool in;
      faceCentre[f] = centrePoint(faceVerts[f].data(), faceSize[f],
                                  d.voronoi && faceSize[f] == 3, in);
    }

    // the elements around each edge, in order: (element, face in, face out)
    std::vector<int> seqStart(nd + 1, 0);
    std::vector<std::array<int, 3>> seqs;
    std::vector<char> open(nd);
    {
      std::vector<std::array<int, 2>> links;
      std::vector<std::pair<int, std::array<int, 2>>> seq;
      for(int ed = 0; ed < nd; ed++) {
        links.clear();
        for(auto &ek : edgeElements[ed]) {
          const Topology &t = topology(elements[ek.first]->getType());
          links.push_back(
            {elementFace[6 * ek.first + t.edgeFaces[ek.second][0]],
             elementFace[6 * ek.first + t.edgeFaces[ek.second][1]]});
        }
        bool o;
        if(!chain(links, seq, o))
          Msg::Warning("Edge with several fans of elements in volume %d",
                       gr->tag());
        open[ed] = o;
        for(auto &s : seq)
          seqs.push_back(
            {edgeElements[ed][s.first].first, s.second[0], s.second[1]});
        seqStart[ed + 1] = (int)seqs.size();
      }
    }
    edgeElements.clear();
    edgeElements.shrink_to_fit();

    // the dual face of an edge, as references to the centre of an element (<
    // ne), of a face (< ne + nf) or to the middle of the edge, and the centre
    // of its fan
    auto ring = [&](int ed, std::vector<int> &r, int &centre) {
      r.clear();
      int s0 = seqStart[ed], n = seqStart[ed + 1] - s0;
      bool exact = !open[ed];
      if(open[ed]) {
        r.push_back(ne + nf + ed);
        r.push_back(ne + seqs[s0][1]);
      }
      for(int j = 0; j < n; j++) {
        int e = seqs[s0 + j][0], fo = seqs[s0 + j][2];
        r.push_back(e);
        exact &= state[e] == 0;
        if((open[ed] && j == n - 1) || onSurface[fo] || state[e] ||
           state[seqs[s0 + (j + 1) % n][0]])
          r.push_back(ne + fo);
      }
      centre = exact ? r[0] : ne + nf + ed;
    };
    auto position = [&](int ref, int ed) {
      if(ref < ne) return state[ref] ? cent[ref] : circ[ref];
      if(ref < ne + nf) return faceCentre[ref - ne];
      return (pos(edgeVerts[ed][0]) + pos(edgeVerts[ed][1])) * 0.5;
    };

    // fall back to the centres until the tetrahedra (node, fan triangle) are
    // positive on both sides of each dual face
    std::vector<int> r;
    std::vector<SVector3> x;
    passes = 0;
    for(bool changed = circumcentres; changed; passes++) {
      changed = false;
      for(int ed = 0; ed < nd; ed++) {
        int c;
        ring(ed, r, c);
        bool circumcentres = false;
        for(auto k : r) circumcentres |= (k < ne && !state[k]);
        if(!circumcentres) continue;
        int n = (int)r.size();
        x.resize(n);
        for(int i = 0; i < n; i++) x[i] = position(r[i], ed);
        SVector3 xc = position(c, ed);
        SVector3 a = pos(edgeVerts[ed][0]), b = pos(edgeVerts[ed][1]);
        SVector3 normal(0., 0., 0.);
        for(int i = 0; i < n; i++) normal += crossprod(x[i], x[(i + 1) % n]);
        double sign = dot(normal, b - a) > 0. ? 1. : -1.;
        double l = (b - a).norm(), tol = 1e-12 * l * l * l;
        for(int i = 0; i < n; i++) {
          int p = r[i], q = r[(i + 1) % n];
          if(p == c || q == c) continue;
          SVector3 t = sign * crossprod(x[i] - xc, x[(i + 1) % n] - xc);
          if(dot(t, xc - a) > tol && dot(t, b - xc) > tol) continue;
          // the circumcentres of the triangle, or else of the whole face
          bool fixed = false;
          for(int k : {c, p, q})
            if(k < ne && !state[k]) {
              state[k] = 1;
              fixed = true;
            }
          if(!fixed)
            for(auto k : r)
              if(k < ne) state[k] = 1;
          changed = true;
          break;
        }
      }
    }

    // the nodes
    std::vector<V> elementNode(ne), faceNode(nf, nullptr);
    for(int e = 0; e < ne; e++) {
      elementNode[e] = d.newNode(state[e] ? cent[e] : circ[e], gr);
      if(elements[e]->getType() == TYPE_TET && d.voronoi) {
        bool c = !state[e] || inside[e];
        d.numCircum[1] += c;
        d.numCentroid[1] += !c;
      }
    }
    auto node = [&](int ref, int ed) {
      if(ref < ne) return elementNode[ref];
      if(ref < ne + nf) {
        int f = ref - ne;
        if(!faceNode[f]) {
          if(faceElements[f][1] < 0 || onSurface[f])
            faceNode[f] = d.centre(faceVerts[f].data(), faceSize[f], gr);
          else
            faceNode[f] = d.newNode(faceCentre[f], gr);
        }
        return faceNode[f];
      }
      return d.mid(edgeVerts[ed][0], edgeVerts[ed][1], gr);
    };

    // the dual faces at each node, and the boundary faces
    std::unordered_map<V, std::vector<int>> nodeEdges, nodeBoundary;
    for(int ed = 0; ed < nd; ed++)
      for(int j = 0; j < 2; j++) nodeEdges[edgeVerts[ed][j]].push_back(ed);
    for(int f = 0; f < nf; f++)
      if(faceElements[f][1] < 0)
        for(int j = 0; j < faceSize[f]; j++)
          nodeBoundary[faceVerts[f][j]].push_back(f);

    // the polyhedra
    std::vector<V> nodes, tets, rn, bcentres;
    std::vector<int> offsets;
    std::vector<std::array<V, 2>> blinks;
    std::vector<std::pair<int, std::array<V, 2>>> bseq;
    std::vector<std::pair<GFace *, int>> bnd;
    for(auto &a : nodeEdges) {
      V v = a.first;
      nodes.clear();
      tets.clear();
      offsets.assign(1, 0);
      for(int ed : a.second) {
        int c;
        ring(ed, r, c);
        rn.clear();
        for(auto k : r) rn.push_back(node(k, ed));
        V vc = node(c, ed);
        nodes.insert(nodes.end(), rn.begin(), rn.end());
        offsets.push_back((int)nodes.size());
        int n = (int)rn.size();
        for(int i = 0; i < n; i++) {
          V p = rn[i], q = rn[(i + 1) % n];
          if(p != vc && q != vc) tets.insert(tets.end(), {v, vc, p, q});
        }
      }
      // the boundary faces of the polyhedron, one by surface: the middles of
      // the edges and the centres of the faces around the node, and the node
      // itself if it is on a curve
      bnd.clear();
      auto bt = nodeBoundary.find(v);
      if(bt != nodeBoundary.end())
        for(int f : bt->second) {
          auto ot = d.faceOwner.find(FaceKey(faceVerts[f].data(), faceSize[f]));
          bnd.push_back({ot == d.faceOwner.end() ? nullptr : ot->second, f});
        }
      std::sort(
        bnd.begin(), bnd.end(),
        [](const std::pair<GFace *, int> &x, const std::pair<GFace *, int> &y) {
          return x.first < y.first;
        });
      for(std::size_t b0 = 0; b0 < bnd.size();) {
        std::size_t b1 = b0;
        blinks.clear();
        bcentres.clear();
        while(b1 < bnd.size() && bnd[b1].first == bnd[b0].first) {
          int f = bnd[b1].second, n = faceSize[f], j = 0;
          while(faceVerts[f][j] != v) j++;
          blinks.push_back(
            {faceVerts[f][(j + n - 1) % n], faceVerts[f][(j + 1) % n]});
          bcentres.push_back(node(ne + f, -1));
          b1++;
        }
        bool o;
        chain(blinks, bseq, o);
        if(o) nodes.push_back(v);
        for(std::size_t j = 0; j < bseq.size(); j++) {
          if(j == 0) nodes.push_back(d.mid(v, bseq[j].second[0], gr));
          nodes.push_back(bcentres[bseq[j].first]);
          if(o || j + 1 < bseq.size())
            nodes.push_back(d.mid(v, bseq[j].second[1], gr));
        }
        offsets.push_back((int)nodes.size());
        b0 = b1;
      }
      auto p = new MPolyhedron(nodes);
      p->setPolygonsAndTetrahedra(nodes, offsets, tets);
      polyhedra.push_back(p);
    }
  }

} // namespace

int GMSH_DualMeshPlugin::run()
{
  GModel *m = GModel::current();
  double t0 = TimeOfDay();

  int dim = 0;
  for(auto gr : m->getRegions())
    if(gr->tetrahedra.size() + gr->hexahedra.size() + gr->prisms.size() +
       gr->pyramids.size())
      dim = 3;
  if(!dim)
    for(auto gf : m->getFaces())
      if(gf->triangles.size() + gf->quadrangles.size()) dim = 2;
  if(!dim) {
    Msg::Warning("Plugin(DualMesh): no 2D or 3D elements");
    return 0;
  }
  std::vector<GEntity *> entities;
  m->getEntities(entities);
  for(auto ge : entities) {
    for(std::size_t i = 0; i < ge->getNumMeshElements(); i++) {
      MElement *e = ge->getMeshElement(i);
      if(e->getPolynomialOrder() > 1) {
        Msg::Error("Plugin(DualMesh) requires a first order mesh");
        return 0;
      }
      if(e->getType() == TYPE_POLYG || e->getType() == TYPE_POLYH) {
        Msg::Error("Plugin(DualMesh) does not handle polygons and polyhedra");
        return 0;
      }
    }
  }

  // the curves and surfaces holding the edges and faces of the mesh
  Dual d;
  d.voronoi = (int)option(0);
  for(auto ge : m->getEdges())
    for(auto l : ge->lines)
      d.edgeOwner[EdgeKey(l->getVertex(0), l->getVertex(1))] = ge;
  std::vector<std::pair<GFace *, std::vector<MElement *>>> surfaces;
  for(auto gf : m->getFaces()) {
    std::vector<MElement *> els(gf->triangles.begin(), gf->triangles.end());
    els.insert(els.end(), gf->quadrangles.begin(), gf->quadrangles.end());
    if(els.empty()) continue;
    for(auto e : els) {
      const Shape &s = *shape(e->getType());
      V v[4];
      corners(e, v);
      d.faceOwner[FaceKey(v, s.numCorners)] = gf;
      for(int i = 0; i < s.numEdges; i++)
        d.edgeOwner.insert(
          {EdgeKey(v[s.edges[i][0]], v[s.edges[i][1]]), (GEntity *)gf});
    }
    surfaces.push_back({gf, els});
  }

  std::size_t numPolyhedra = 0, numPolygons = 0;
  if(dim == 3) {
    for(auto gr : m->getRegions()) {
      std::vector<MElement *> els(gr->tetrahedra.begin(), gr->tetrahedra.end());
      els.insert(els.end(), gr->hexahedra.begin(), gr->hexahedra.end());
      els.insert(els.end(), gr->prisms.begin(), gr->prisms.end());
      els.insert(els.end(), gr->pyramids.begin(), gr->pyramids.end());
      if(els.empty()) continue;
      std::vector<MPolyhedron *> polyhedra;
      int passes;
      dual3D(gr, els, d.voronoi, d, polyhedra, passes);
      if(d.voronoi)
        Msg::Info("Volume %d: subdivision valid after %d passes", gr->tag(),
                  passes);
      for(auto e : els) delete e;
      gr->tetrahedra.clear();
      gr->hexahedra.clear();
      gr->prisms.clear();
      gr->pyramids.clear();
      for(auto p : polyhedra) gr->addPolyhedron(p);
      numPolyhedra += polyhedra.size();
    }
  }
  for(auto &s : surfaces) {
    std::vector<MPolygon *> polygons;
    // on the surfaces of a 3D mesh, the centres shared with the polyhedra
    int passes;
    dual2D(s.first, s.second, d.voronoi && dim == 2, d, polygons, passes);
    if(d.voronoi && dim == 2)
      Msg::Info("Surface %d: subdivision valid after %d passes", s.first->tag(),
                passes);
    for(auto e : s.second) delete e;
    s.first->triangles.clear();
    s.first->quadrangles.clear();
    for(auto p : polygons) s.first->addPolygon(p);
    numPolygons += polygons.size();
  }
  for(auto ge : m->getEdges()) {
    std::vector<MLine *> lines;
    for(auto l : ge->lines) {
      V a = l->getVertex(0), b = l->getVertex(1), c = d.mid(a, b, ge);
      lines.push_back(new MLine(a, c));
      lines.push_back(new MLine(c, b));
      delete l;
    }
    ge->lines = lines;
  }
  for(auto v : d.newNodes) v->onWhat()->addMeshVertex(v);

  m->destroyMeshCaches();
  CTX::instance()->meshChanged();

  // the triangles counted in 2D, the tetrahedra in 3D
  int k = dim - 2;
  if(d.voronoi)
    Msg::Info("Circumcentres used: %zu of %zu %s", d.numCircum[k],
              d.numCircum[k] + d.numCentroid[k],
              k ? "tetrahedra" : "triangles");
  Msg::Info("Dual mesh: %zu polyhedra, %zu polygons, %zu new nodes (%g s)",
            numPolyhedra, numPolygons, d.newNodes.size(), TimeOfDay() - t0);
  return 1;
}
