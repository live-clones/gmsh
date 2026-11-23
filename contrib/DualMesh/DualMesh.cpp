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
#include <cmath>
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
#include "MVertex.h"
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
         "The cells are cut along the curves of the surfaces and the surfaces "
         "of the volumes, embedded ones and seams included: a node on a curve "
         "embedded in a surface, or on a surface embedded in a volume, gets a "
         "cell on each side, so that the lines are edges of the polygons and "
         "the polygons faces of the polyhedra. Where an embedded curve or "
         "surface ends, the cell goes around its end and has it as a slit. "
         "Curves and points embedded in volumes do not cut the cells.\n\n"
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

  // the keys of the hash tables compare the node pointers: the tables are
  // looked up, or iterated by node number (see byNumber()), so that their
  // order does not matter
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
  // keys it shares with them, into fans: the sequences of (item, key in, key
  // out), one fan after the other (fan i from starts[i] to starts[i + 1]). A
  // fan ends at a key that is used once or for which cut() is true (an edge on
  // a curve, a face on a surface), and is then open; the items left make
  // closed fans.
  template <class K, class C>
  void fans(const std::vector<std::array<K, 2>> &links, C cut,
            std::vector<std::pair<int, std::array<K, 2>>> &seq,
            std::vector<int> &starts, std::vector<char> &open)
  {
    int n = (int)links.size();
    seq.clear();
    starts.assign(1, 0);
    open.clear();
    std::vector<char> done(n, 0);
    auto isEnd = [&](const K &key) {
      if(cut(key)) return true;
      int c = 0;
      for(int k = 0; k < n; k++)
        c += (links[k][0] == key) + (links[k][1] == key);
      return c == 1;
    };
    auto walk = [&](int cur, K in) {
      while(true) {
        done[cur] = 1;
        K out = (links[cur][0] == in) ? links[cur][1] : links[cur][0];
        seq.push_back({cur, {in, out}});
        if(cut(out)) break;
        int next = -1;
        for(int i = 0; i < n && next < 0; i++)
          if(!done[i] && (links[i][0] == out || links[i][1] == out)) next = i;
        if(next < 0) break;
        in = out;
        cur = next;
      }
      starts.push_back((int)seq.size());
    };
    // the open fans from their ends, then the closed ones
    for(int pass = 0; pass < 2; pass++)
      for(int i = 0; i < n; i++) {
        if(done[i]) continue;
        if(pass) {
          walk(i, links[i][0]);
          open.push_back(0);
          continue;
        }
        for(int j = 0; j < 2; j++)
          if(isEnd(links[i][j])) {
            walk(i, links[i][j]);
            open.push_back(1);
            break;
          }
      }
  }

  SVector3 pos(V v) { return SVector3(v->x(), v->y(), v->z()); }

  // the circumcentre of a triangle (n = 3) or of a tetrahedron (n = 4), and
  // whether it lies inside, its barycentric coordinates all above a small
  // tolerance; false if the simplex is flat
  bool circumcentre(const V *v, int n, SVector3 &c, bool &inside,
                    double *bary = nullptr)
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
    if(bary)
      for(int i = 0; i < n; i++) bary[i] = l[i];
    return true;
  }

  // the centre of an element or a face: its circumcentre if circumcentres are
  // asked for and it is a simplex holding it, its centroid otherwise
  // (with its weights on the nodes, if asked for)
  SVector3 centrePoint(const V *v, int n, bool circumcentres, bool &circ,
                       double *w = nullptr)
  {
    SVector3 c(0., 0., 0.);
    circ = false;
    if(circumcentres && (n == 3 || n == 4) && circumcentre(v, n, c, circ, w) &&
       circ)
      return c;
    c = SVector3(0., 0., 0.);
    for(int i = 0; i < n; i++) {
      c += pos(v[i]);
      if(w) w[i] = 1. / n;
    }
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
      double w[4];
      SVector3 c = centrePoint(v, n, voronoi && simplex, circ, w);
      if(voronoi && simplex) {
        numCircum[n - 3] += circ;
        numCentroid[n - 3] += !circ;
      }
      return newNode(c, ge, v, w, n);
    }
    V newNode(const SVector3 &c, GEntity *ge)
    {
      V nv = new MVertex(c.x(), c.y(), c.z(), ge);
      newNodes.push_back(nv);
      return nv;
    }
    // a new node in the edge or the face of nodes v, with weights w on them:
    // on a curve or a surface that has a parametrization, with the same mean
    // of the parameters of these nodes as its parameters (those of a node on
    // the end of a closed curve or on a seam taken next to the others)
    V newNode(const SVector3 &c, GEntity *ge, const V *v, const double *w, int n)
    {
      if(ge->dim() == 1 && n == 2 && ge->haveParametrization()) {
        GEdge *e = static_cast<GEdge *>(ge);
        double t[2];
        bool ok = true;
        for(int i = 0; i < 2; i++) {
          ok &= reparamMeshVertexOnEdge(v[i], e, t[i]);
          if(ok && e->periodic(0) && v[i]->onWhat()->dim() == 0) {
            double other;
            ok &= reparamMeshVertexOnEdge(v[1 - i], e, other);
            Range<double> r = e->parBounds(0);
            if(std::abs(r.high() - other) < std::abs(r.low() - other))
              t[i] = r.high();
          }
        }
        if(ok) {
          V nv = new MEdgeVertex(c.x(), c.y(), c.z(), e,
                                 w[0] * t[0] + w[1] * t[1]);
          newNodes.push_back(nv);
          return nv;
        }
      }
      else if(ge->dim() == 2 && ge->haveParametrization()) {
        GFace *f = static_cast<GFace *>(ge);
        SPoint2 p0, p;
        double uv[2] = {0., 0.};
        bool ok = true;
        for(int i = 1; i < n && ok; i++) {
          SPoint2 q0;
          ok = reparamMeshEdgeOnFace(v[0], v[i], f, q0, p);
          if(i == 1) p0 = q0;
          for(int k = 0; k < 2; k++) {
            if(i == 1) uv[k] += w[0] * p0[k];
            uv[k] += w[i] * (p[k] + p0[k] - q0[k]);
          }
        }
        if(ok) {
          V nv = new MFaceVertex(c.x(), c.y(), c.z(), f, uv[0], uv[1]);
          newNodes.push_back(nv);
          return nv;
        }
      }
      return newNode(c, ge);
    }
    // the middle of an edge, on the curve or surface holding it if any
    V mid(V a, V b, GEntity *ge)
    {
      EdgeKey k(a, b);
      auto it = _mid.find(k);
      if(it != _mid.end()) return it->second;
      auto ot = edgeOwner.find(k);
      V v[2] = {a, b};
      double w[2] = {0.5, 0.5};
      return _mid[k] = newNode((pos(a) + pos(b)) * 0.5,
                               ot == edgeOwner.end() ? ge : ot->second, v, w, 2);
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

  // the entries of a table keyed on nodes, by node number: the polygons, the
  // polyhedra and the nodes are created in this order, not in the order of the
  // table, which changes from one run to the next
  template <class M> std::vector<typename M::value_type *> byNumber(M &table)
  {
    std::vector<typename M::value_type *> v;
    for(auto &a : table) v.push_back(&a);
    std::sort(v.begin(), v.end(),
              [](typename M::value_type *x, typename M::value_type *y) {
                return x->first->getNum() < y->first->getNum();
              });
    return v;
  }

  // the dual of the 2D elements of a surface: a polygon around each node,
  // whose vertices are the centres of the elements around it and the middles
  // of the edges between them. The elements around a node whose edges are on
  // curves (the boundary of the surface, its seam, curves embedded in it) are
  // cut there into fans, each giving a polygon that also has the node itself
  // and the middles of the two edges it ends at: the lines of the curves are
  // then edges of the polygons. The polygons are subdivided into the triangles
  // joining their node to their edges: the triangles of the barycentric
  // subdivision of the elements. With circumcentres, the triangles are
  // represented by their circumcentres wherever these lie, and the middles of
  // the edges between two such triangles are dropped: the polygon of a node
  // whose triangles all are is then its Voronoi cell. A triangle whose
  // circumcentre inverts one of the triangles of the subdivision falls back to
  // its centre, until all are valid.
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

    // the fans of elements around each node, in order: (element, node in,
    // node out); one polygon by fan
    std::vector<V> nodes;
    std::vector<int> seqStart(1, 0);
    std::vector<std::pair<int, std::array<V, 2>>> seqs;
    std::vector<char> open;
    {
      std::vector<std::array<V, 2>> links;
      std::vector<std::pair<int, std::array<V, 2>>> seq;
      std::vector<int> starts;
      std::vector<char> opens;
      for(auto *pa : byNumber(around)) {
        auto &a = *pa;
        V v = a.first;
        links.clear();
        for(auto &ei : a.second) {
          int e = ei.first, i = ei.second;
          int n = shape(elements[e]->getType())->numCorners;
          links.push_back(
            {ev[4 * e + (i + n - 1) % n], ev[4 * e + (i + 1) % n]});
        }
        auto onCurve = [&](V w) {
          auto it = d.edgeOwner.find(EdgeKey(v, w));
          return it != d.edgeOwner.end() && it->second->dim() == 1;
        };
        fans(links, onCurve, seq, starts, opens);
        for(std::size_t f = 0; f < opens.size(); f++) {
          nodes.push_back(v);
          open.push_back(opens[f]);
          for(int j = starts[f]; j < starts[f + 1]; j++)
            seqs.push_back({a.second[seq[j].first].first, seq[j].second});
          seqStart.push_back((int)seqs.size());
        }
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
        if((open[k] && j == n - 1) || state[e] ||
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
              double w[3];
              SVector3 cc;
              bool in;
              circumcentre(&ev[4 * e], 3, cc, in, w);
              elementNode[e] = d.newNode(circ[e], gf, &ev[4 * e], w, 3);
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
  // between them. The elements around an edge whose faces are on surfaces (the
  // boundary of the volume, surfaces embedded in it) are cut there into fans,
  // each giving a dual face that also has the middle of the edge; and the
  // elements around a node are on one side or another of the surfaces through
  // it, each side giving a polyhedron, closed by the duals of the faces of the
  // surfaces (cut at the curves as in 2D): the polygons of the surfaces are
  // then faces of the polyhedra. The polyhedra are subdivided into the tetrahedra joining their
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

    // the fans of elements around each edge, in order: (element, face in,
    // face out); one dual face (ring) by fan
    std::vector<int> ringEdge, seqStart(1, 0);
    std::vector<std::array<int, 3>> seqs;
    std::vector<char> open;
    {
      std::vector<std::array<int, 2>> links;
      std::vector<std::pair<int, std::array<int, 2>>> seq;
      std::vector<int> starts;
      std::vector<char> opens;
      auto cut = [&](int f) { return onSurface[f] != 0; };
      for(int ed = 0; ed < nd; ed++) {
        links.clear();
        for(auto &ek : edgeElements[ed]) {
          const Topology &t = topology(elements[ek.first]->getType());
          links.push_back(
            {elementFace[6 * ek.first + t.edgeFaces[ek.second][0]],
             elementFace[6 * ek.first + t.edgeFaces[ek.second][1]]});
        }
        fans(links, cut, seq, starts, opens);
        for(std::size_t f = 0; f < opens.size(); f++) {
          ringEdge.push_back(ed);
          open.push_back(opens[f]);
          for(int j = starts[f]; j < starts[f + 1]; j++)
            seqs.push_back({edgeElements[ed][seq[j].first].first,
                            seq[j].second[0], seq[j].second[1]});
          seqStart.push_back((int)seqs.size());
        }
      }
    }
    int nr = (int)ringEdge.size();
    edgeElements.clear();
    edgeElements.shrink_to_fit();

    // a dual face of an edge, as references to the centre of an element (<
    // ne), of a face (< ne + nf) or to the middle of the edge, and the centre
    // of its fan
    auto ring = [&](int rg, std::vector<int> &r, int &centre) {
      r.clear();
      int ed = ringEdge[rg], s0 = seqStart[rg], n = seqStart[rg + 1] - s0;
      bool exact = !open[rg];
      if(open[rg]) {
        r.push_back(ne + nf + ed);
        r.push_back(ne + seqs[s0][1]);
      }
      for(int j = 0; j < n; j++) {
        int e = seqs[s0 + j][0], fo = seqs[s0 + j][2];
        r.push_back(e);
        exact &= state[e] == 0;
        if((open[rg] && j == n - 1) || state[e] ||
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
      for(int rg = 0; rg < nr; rg++) {
        int c, ed = ringEdge[rg];
        ring(rg, r, c);
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

    // the dual faces at each node, and the faces on surfaces
    std::unordered_map<V, std::vector<int>> nodeRings, nodeBoundary;
    for(int rg = 0; rg < nr; rg++)
      for(int j = 0; j < 2; j++)
        nodeRings[edgeVerts[ringEdge[rg]][j]].push_back(rg);
    for(int f = 0; f < nf; f++)
      if(faceElements[f][1] < 0 || onSurface[f])
        for(int j = 0; j < faceSize[f]; j++)
          nodeBoundary[faceVerts[f][j]].push_back(f);

    // the polyhedra
    std::vector<V> nodes, tets, rn, bcentres;
    std::vector<int> offsets, side, starts;
    std::vector<char> opens;
    std::vector<std::pair<int, int>> elementRing;
    std::vector<std::array<V, 2>> blinks;
    std::vector<std::pair<int, std::array<V, 2>>> bseq;
    std::vector<std::pair<std::array<int, 2>, int>> bnd; // (surface, copy), face
    for(auto *pa : byNumber(nodeRings)) {
      V v = pa->first;
      const std::vector<int> &rings = pa->second;
      int numRings = (int)rings.size();
      // the sides of the surfaces through the node: the dual faces whose fans
      // share an element are on the same side
      side.resize(numRings);
      for(int i = 0; i < numRings; i++) side[i] = i;
      auto root = [&](int i) {
        while(side[i] != i) i = side[i];
        return i;
      };
      elementRing.clear();
      for(int i = 0; i < numRings; i++)
        for(int j = seqStart[rings[i]]; j < seqStart[rings[i] + 1]; j++)
          elementRing.push_back({seqs[j][0], i});
      std::sort(elementRing.begin(), elementRing.end());
      for(std::size_t k = 1; k < elementRing.size(); k++)
        if(elementRing[k].first == elementRing[k - 1].first)
          side[root(elementRing[k].second)] = root(elementRing[k - 1].second);
      auto sideOf = [&](int e) {
        auto it = std::lower_bound(elementRing.begin(), elementRing.end(),
                                   std::pair<int, int>(e, 0));
        return root(it->second);
      };
      auto bt = nodeBoundary.find(v);

      // a polyhedron by side
      for(int s = 0; s < numRings; s++) {
        if(root(s) != s) continue;
        nodes.clear();
        tets.clear();
        offsets.assign(1, 0);
        for(int i = 0; i < numRings; i++) {
          if(root(i) != s) continue;
          int c, rg = rings[i], ed = ringEdge[rg];
          ring(rg, r, c);
          rn.clear();
          for(auto k : r) rn.push_back(node(k, ed));
          V vc = node(c, ed);
          nodes.insert(nodes.end(), rn.begin(), rn.end());
          offsets.push_back((int)nodes.size());
          int n = (int)rn.size();
          for(int k = 0; k < n; k++) {
            V p = rn[k], q = rn[(k + 1) % n];
            if(p != vc && q != vc) tets.insert(tets.end(), {v, vc, p, q});
          }
        }
        // its faces on the surfaces, as the polygons of the node on these
        // surfaces: by surface, the centres of the faces around the node and
        // the middles of their edges, in fans cut at the edges on curves,
        // which also have the node itself. Around the border of an embedded
        // surface, this side is on both sides of the faces: they are then
        // taken twice, the second time apart
        bnd.clear();
        if(bt != nodeBoundary.end())
          for(int f : bt->second) {
            int copy = 0;
            for(int j = 0; j < 2; j++) {
              int e = faceElements[f][j];
              if(e < 0 || sideOf(e) != s) continue;
              auto ot =
                d.faceOwner.find(FaceKey(faceVerts[f].data(), faceSize[f]));
              int tag = (ot == d.faceOwner.end()) ? 0 : ot->second->tag();
              bnd.push_back({{tag, copy++}, f});
            }
          }
        std::stable_sort(bnd.begin(), bnd.end(),
                         [](const std::pair<std::array<int, 2>, int> &x,
                            const std::pair<std::array<int, 2>, int> &y) {
                           return x.first < y.first;
                         });
        auto onCurve = [&](V w) {
          auto it = d.edgeOwner.find(EdgeKey(v, w));
          return it != d.edgeOwner.end() && it->second->dim() == 1;
        };
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
          fans(blinks, onCurve, bseq, starts, opens);
          for(std::size_t k = 0; k < opens.size(); k++) {
            if(opens[k]) nodes.push_back(v);
            for(int j = starts[k]; j < starts[k + 1]; j++) {
              if(j == starts[k]) nodes.push_back(d.mid(v, bseq[j].second[0], gr));
              nodes.push_back(bcentres[bseq[j].first]);
              if(opens[k] || j + 1 < starts[k + 1])
                nodes.push_back(d.mid(v, bseq[j].second[1], gr));
            }
            offsets.push_back((int)nodes.size());
          }
          b0 = b1;
        }
        auto p = new MPolyhedron(nodes);
        p->setPolygonsAndTetrahedra(nodes, offsets, tets);
        polyhedra.push_back(p);
      }
    }
  }

} // namespace

int GMSH_DualMeshPlugin::run()
{
  GModel *m = GModel::current();
  double t0 = TimeOfDay();

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
      if(e->getType() == TYPE_TRIH) {
        Msg::Error("Plugin(DualMesh) does not handle trihedra");
        return 0;
      }
    }
  }
  if(!m->getGhostCells().empty()) {
    Msg::Error("Plugin(DualMesh) does not handle ghost cells");
    return 0;
  }

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

  // the curves and surfaces holding the edges and faces of the mesh
  Dual d;
  d.voronoi = (option(0) != 0.);
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

  // (the new nodes are not added to the periodic node correspondences)
  for(auto ge : entities)
    if(ge->correspondingVertices.size()) {
      Msg::Warning("Plugin(DualMesh) does not extend the periodic node "
                   "correspondences to the new nodes");
      break;
    }

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
