// Gmsh Discrete CAD Modeler - Copyright (C) 2026 C. Geuzaine and J.-F. Remacle
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

// The Frontal-Delaunay algorithm on a discrete surface, without its
// parametrization (Mesh.Algorithm = 12).
//
// The triangulation F of the surface is the geometry: the points are placed
// on it - the circle of the frontal algorithm, in the plane bisecting the
// active edge, intersected with its triangles - and it is never modified
// (only its long edges cut in two at the start, which does not change it).
//
// The mesh M starts as a copy of F. Its nodes are of two kinds: the nodes of
// F, the scaffold, which all have to go, and the nodes of the mesh, those of
// the 1D mesh of the boundary curves then the points of the front. Each node
// knows where it is on F (a triangle and the barycentric coordinates). The
// decisions of the Delaunay kernel are taken in a local chart, the plane
// tangent to F at the point the decision is about, onto which the nodes are
// projected, and the scaffold disappears in the Bowyer-Watson cavities: it is
// weighted -W in the power diagram (see scaffoldWeight), the mesh nodes 0, so
// that a scaffold node is hidden as soon as it lies in a triangle of mesh
// nodes small enough to be accepted, and the cavity of a point swallows the
// scaffold within about sqrt(W) of it. Between nodes of the same kind it is
// the plain Delaunay kernel.
//
// The steps:
//  1. F: the triangulation of the surface, its edges longer than the mesh
//     size cut in two (so that every triangle of M fits in a chart);
//  2. M, a copy of F, the nodes of the 1D mesh inserted on its boundary, the
//     scaffold nodes of the boundary then removed one by one (the polyline of
//     F between two consecutive nodes of a curve becomes their segment), and
//     Lawson's flips;
//  3. the front: the triangles with a scaffold node are never accepted, the
//     active ones are refined largest first, the optimal point found on F;
//  4. the scaffold nodes the front leaves (the charts of their neighbors
//     disagreeing on a needle) removed explicitly, the Delaunay property
//     restored by flips, and the front run again where needed.

#include <algorithm>
#include <array>
#include <cmath>
#include <functional>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "DiscreteCADScaffold.h"
#include "GmshMessage.h"
#include "GFace.h"
#include "GEdge.h"
#include "discreteEdge.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MVertex.h"
#include "BackgroundMeshTools.h"
#include "robustPredicates.h"
#include "WinslowUntangler.h"
#include "Context.h"

namespace {

typedef std::array<double, 3> P3;
typedef std::array<double, 2> P2;
typedef std::array<int, 3> T3;

// radius (over the mesh size) below which a triangle is accepted, as in the
// Frontal-Delaunay algorithm
const double LIMIT_ = 0.5 * std::sqrt(2.0);

inline P3 add(const P3 &a, const P3 &b)
{
  return {a[0] + b[0], a[1] + b[1], a[2] + b[2]};
}
inline P3 sub(const P3 &a, const P3 &b)
{
  return {a[0] - b[0], a[1] - b[1], a[2] - b[2]};
}
inline P3 scale(const P3 &a, double s)
{
  return {a[0] * s, a[1] * s, a[2] * s};
}
inline P3 cross(const P3 &a, const P3 &b)
{
  return {a[1] * b[2] - a[2] * b[1], a[2] * b[0] - a[0] * b[2],
          a[0] * b[1] - a[1] * b[0]};
}
inline double dot(const P3 &a, const P3 &b)
{
  return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}
inline double norm(const P3 &a) { return std::sqrt(dot(a, a)); }
inline P3 unit(const P3 &a)
{
  const double l = norm(a);
  return l > 0. ? scale(a, 1. / l) : a;
}
inline double o2(const P2 &a, const P2 &b, const P2 &c)
{
  return robustPredicates::orient2d(a.data(), b.data(), c.data());
}

// the weight -W of the scaffold in the insertions, for the mesh size h. Above
// h^2 / 3, the optimal point of an active edge (a, b) is in conflict with the
// triangle (a, b, s) whatever the scaffold node s; above (LIMIT_ h)^2, no
// accepted triangle can contain a scaffold node. Without it the front stalls
// next to the scaffold, and the scaffold removed ahead of it leaves chords
// across the surface that no chart holds; too large, the cavities reach far
// ahead. Measured on a disk, a rectangle and a curved face of t13 (0 to 4
// (LIMIT_ h)^2): h^2 has the fewest failed insertions and the best worst
// triangles. (The flips and the removals keep (LIMIT_ h)^2: with h^2 there
// too, the boolean and t13 models end with twice as many bad triangles.)
inline double scaffoldWeight(double h) { return h * h; }

// the circumradius of a triangle (huge if it has no area)
double circumRadius(const P3 &a, const P3 &b, const P3 &c)
{
  const double A2 = norm(cross(sub(b, a), sub(c, a)));
  if(!(A2 > 0.)) return 1e300;
  return norm(sub(b, c)) * norm(sub(c, a)) * norm(sub(a, b)) / (2. * A2);
}

// the circumcenter of a triangle (its first node if it has no area)
P3 circumCenter(const P3 &a, const P3 &b, const P3 &c)
{
  const P3 u = sub(b, a), v = sub(c, a), w = cross(u, v);
  const double w2 = dot(w, w);
  if(!(w2 > 0.)) return a;
  return add(a, scale(add(scale(cross(v, w), dot(u, u)),
                          scale(cross(w, u), dot(v, v))),
                      0.5 / w2));
}

// the agreement of a triangle with the surface: the cosine of the angle
// between its normal and m (the sum of the normals of F at its nodes), -1 if
// it has no area
double agreement(const P3 &a, const P3 &b, const P3 &c, const P3 &m)
{
  const P3 n = cross(sub(b, a), sub(c, a));
  const double ln = norm(n), lm = norm(m);
  if(!(ln > 0.) || !(lm > 0.)) return -1.;
  return dot(n, m) / (ln * lm);
}

// the plane through o of normal n, with an orthonormal frame (e1, e2, n)
struct Chart {
  P3 o, e1, e2;
  Chart(const P3 &o_, const P3 &n) : o(o_)
  {
    const P3 a = std::fabs(n[0]) < 0.6 ? P3{1, 0, 0} : P3{0, 1, 0};
    e1 = unit(cross(n, a));
    e2 = cross(n, e1);
  }
  P2 uv(const P3 &x) const
  {
    const P3 d = sub(x, o);
    return {dot(d, e1), dot(d, e2)};
  }
};

// a point of F: a triangle and the barycentric coordinates in it
struct Location {
  int f = -1;
  double l[3] = {0., 0., 0.};
};

// a node of M
struct Node {
  P3 x, n; // position, normal of F there
  double s1 = 0., sB = 0.; // mesh sizes: extended from the boundary, background
  Location at; // where it is on F
  MVertex *mv = nullptr; // the mesh node (null for the new ones until the end)
  bool scaffold = true; // a node of F
  bool boundary = false; // on the boundary of M
  bool alive = true;
  int inc = -1; // a triangle of the node
  // its generation: 0 on the boundary, for a point of the front one more than
  // the nodes of the edge it was placed for
  int layer = 0;
};

// a triangle of M
struct Tri {
  T3 v, nb; // nodes, neighbors across (v[k], v[k + 1]) (-1 on the boundary)
  double r = 0.; // circumradius over the mesh size; -1: no point could be
                 // inserted for it
  unsigned ver = 0; // changed when the triangle is (stale queue entries)
  bool alive = true;
};

// the front advances layer by layer (the active edges of the oldest nodes
// first), the largest triangles first in a layer: with the scaffold, the
// radius alone (that of small triangles of F) would start the front
// everywhere at once, its parts colliding everywhere
struct QueueEntry {
  int layer;
  double r;
  int t;
  unsigned ver;
  bool operator<(const QueueEntry &o) const
  {
    if(layer != o.layer) return layer > o.layer;
    return r < o.r || (r == o.r && t > o.t);
  }
};

class Scaffold {
public:
  explicit Scaffold(GFace *gf) : _gf(gf) {}
  bool mesh();

private:
  GFace *_gf;
  // F
  std::vector<P3> _x, _n; // nodes, normals
  std::vector<double> _s1, _sB; // sizes at the nodes
  std::vector<T3> _ft, _fnb; // triangles, neighbors
  std::vector<std::array<SPoint2, 3> > _fuv; // parameters of the corners
  bool _param = false;
  std::vector<int> _fMark;
  int _fStamp = 0;
  // the nodes of F as given (before the cuts and the refinement), by position;
  // for each node of F the one of them it is (its copies along the cuts too),
  // -1 for those cut in the edges, and for those cut in boundary edges the
  // boundary edge as given they are on ({-1, -1} for the others)
  std::map<P3, int> _fNode;
  std::vector<int> _fOrigin;
  std::vector<std::pair<int, int> > _fOnEdge;
  // the 1D mesh of the boundary, and where each node is on its curve: the
  // curve and the parameter (no curve for those of the vertices)
  std::vector<MVertex *> _bv;
  std::vector<std::pair<GEdge *, double> > _bAt;
  std::vector<double> _bSize;
  std::vector<std::pair<int, int> > _segments;
  // (their nodes, to know an edge of M that is one)
  std::set<std::pair<MVertex *, MVertex *> > _segmentNodes;
  // the seams and the embedded curves (curves with the surface on their two
  // sides, inside F), and their number of segments
  std::set<GEdge *> _seams;
  std::size_t _seamSegments = 0;
  // M
  std::vector<Node> _v;
  std::vector<Tri> _t;
  std::vector<int> _freeT, _mark, _tested;
  int _stamp = 0;
  bool _extend1d = false;
  const char *_why = ""; // why the last removal failed (debugging)
  bool _trace = false;
  std::map<std::string, long> _rejects; // why the insertions failed
  std::priority_queue<QueueEntry> _queue;
  // what was done
  long _inserted = 0, _hidden = 0, _removed = 0, _flips = 0, _failed = 0,
       _shrunk = 0, _refined = 0, _forced = 0;

  // F
  bool buildBackground();
  bool collectBoundary();
  const std::vector<int> *polyline(GEdge *ge);
  std::map<GEdge *, std::vector<int> > _polylines;
  bool cutSeams();
  long checkF() const;
  std::string checkM() const;
  void dump(const std::string &what) const;
  void backgroundSizes();
  void refineBackground();
  void splitBackgroundEdge(int t1, int k);
  void backgroundNormals();
  double sizeAt(double s1, double sB) const
  {
    return _extend1d ? std::min(s1, sB) : sB;
  }
  P3 normalAt(const Location &at) const;
  SPoint2 uvAt(const Location &at) const;
  double backgroundSize(const P3 &x, const SPoint2 &uv) const
  {
    return BGM_MeshSize(_gf, uv.x(), uv.y(), x[0], x[1], x[2]);
  }
  bool circleOnF(const P3 &m, const P3 &e, const P3 &dir, double L, int seed0,
                 int seed1, P3 &p, Location &at);

  // M
  bool initialMesh();
  int newTri(const T3 &v);
  void killTri(int t);
  void relink(int o, int from, int to);
  int indexOf(int t, int v) const
  {
    for(int k = 0; k < 3; k++)
      if(_t[t].v[k] == v) return k;
    return -1;
  }
  bool hasScaffold(int t) const
  {
    return _v[_t[t].v[0]].scaffold || _v[_t[t].v[1]].scaffold ||
           _v[_t[t].v[2]].scaffold;
  }
  double nodeSize(int i) const { return sizeAt(_v[i].s1, _v[i].sB); }
  double weight(int i, double W) const { return _v[i].scaffold ? -W : 0.; }
  void setRadius(int t);
  bool accepted(int t) const
  {
    return _t[t].r > 0. && _t[t].r < LIMIT_ && !hasScaffold(t);
  }
  int activeEdge(int t) const;
  void push(int t);
  bool star(int s, std::vector<int> &q, std::vector<int> &out,
            std::vector<int> &tris, bool &boundary) const;
  bool edgeExists(int a, int b) const;
  bool edgeTaken(int a, int b) const;
  bool segmentEdge(int a, int b) const
  {
    return _v[a].mv && _v[b].mv &&
           _segmentNodes.count(std::minmax(_v[a].mv, _v[b].mv));
  }
  double agreement(int t) const
  {
    const Node &a = _v[_t[t].v[0]], &b = _v[_t[t].v[1]], &c = _v[_t[t].v[2]];
    return ::agreement(a.x, b.x, c.x, add(add(a.n, b.n), c.n));
  }
  int flipEdge(int i, int k);
  bool removeNode(int s, bool force = false);
  bool removeBoundaryScaffold();
  long flip();
  bool optimalPoint(int t, int k, P3 &p, Location &at);
  bool insertPoint(const P3 &p, const Location &at, int t, int layer);
  void front();
  bool nearestOnF(const P3 &x, double reach, Location &at, P3 &p);
  void smooth(int passes);
  void untangle();
  void transfer();
};

// F: the triangulation of the surface, the nodes of a seam (twice in the
// triangulation of a parametrization) merged
bool Scaffold::buildBackground()
{
  const std::vector<SPoint3> &xyz = _gf->stl_vertices_xyz;
  const std::vector<int> &tri = _gf->stl_triangles;
  const std::vector<SPoint2> &uv = _gf->stl_vertices_uv;
  if(tri.empty() || xyz.empty()) {
    Msg::Error("Surface %d has no triangulation", _gf->tag());
    return false;
  }
  _param = uv.size() == xyz.size();
  std::vector<int> id(xyz.size());
  for(std::size_t i = 0; i < xyz.size(); i++) {
    const P3 p = {xyz[i].x(), xyz[i].y(), xyz[i].z()};
    auto it = _fNode.insert({p, (int)_x.size()});
    if(it.second) {
      _fOrigin.push_back((int)_x.size());
      _x.push_back(p);
    }
    id[i] = it.first->second;
  }
  _fOnEdge.assign(_x.size(), {-1, -1});
  for(std::size_t i = 0; i + 2 < tri.size(); i += 3) {
    const T3 t = {id[tri[i]], id[tri[i + 1]], id[tri[i + 2]]};
    if(t[0] == t[1] || t[1] == t[2] || t[2] == t[0]) continue;
    _ft.push_back(t);
    std::array<SPoint2, 3> c;
    for(int k = 0; k < 3; k++)
      c[k] = _param ? uv[tri[i + k]] : SPoint2(0., 0.);
    _fuv.push_back(c);
  }
  const long long N = (long long)_x.size();
  std::unordered_map<long long, int> edges;
  for(std::size_t t = 0; t < _ft.size(); t++)
    for(int k = 0; k < 3; k++)
      if(!edges.insert({_ft[t][k] * N + _ft[t][(k + 1) % 3], (int)t}).second) {
        Msg::Error("Triangulation of surface %d not manifold or not "
                   "consistently oriented",
                   _gf->tag());
        return false;
      }
  _fnb.assign(_ft.size(), {-1, -1, -1});
  for(std::size_t t = 0; t < _ft.size(); t++)
    for(int k = 0; k < 3; k++) {
      auto it = edges.find(_ft[t][(k + 1) % 3] * N + _ft[t][k]);
      if(it != edges.end()) _fnb[t][k] = it->second;
    }
  backgroundNormals();
  if(Msg::GetVerbosity() > 98) {
    SBoundingBox3d bb;
    for(auto &x : _x) bb += SPoint3(x[0], x[1], x[2]);
    long nb = 0;
    for(auto &n : _fnb)
      for(int k = 0; k < 3; k++) nb += n[k] < 0;
    Msg::Debug("Surface %d: F %lu nodes (%lu given), %lu triangles, %ld "
               "boundary edges, box (%g %g %g) (%g %g %g)",
               _gf->tag(), _x.size(), xyz.size(), _ft.size(), nb, bb.min().x(),
               bb.min().y(), bb.min().z(), bb.max().x(), bb.max().y(),
               bb.max().z());
  }
  return true;
}

void Scaffold::backgroundNormals()
{
  _n.assign(_x.size(), P3{0., 0., 0.});
  for(auto &t : _ft) {
    const P3 c = cross(sub(_x[t[1]], _x[t[0]]), sub(_x[t[2]], _x[t[0]]));
    for(int v : t) _n[v] = add(_n[v], c);
  }
  for(auto &n : _n) n = unit(n);
}

P3 Scaffold::normalAt(const Location &at) const
{
  P3 n = {0., 0., 0.};
  for(int k = 0; k < 3; k++) n = add(n, scale(_n[_ft[at.f][k]], at.l[k]));
  return unit(n);
}

SPoint2 Scaffold::uvAt(const Location &at) const
{
  if(!_param) return SPoint2(0., 0.);
  double u = 0., v = 0.;
  for(int k = 0; k < 3; k++) {
    u += at.l[k] * _fuv[at.f][k].x();
    v += at.l[k] * _fuv[at.f][k].y();
  }
  return SPoint2(u, v);
}

// the nodes and the segments of the 1D mesh of the boundary curves, and of the
// embedded curves (inside F, the surface on their two sides: cut as the seams)
bool Scaffold::collectBoundary()
{
  std::set<GVertex *> ends;
  for(GEdge *ge : _gf->getEmbeddedEdges())
    for(GVertex *gv : ge->vertices()) ends.insert(gv);
  for(GVertex *gv : _gf->getEmbeddedVertices()) {
    if(ends.count(gv)) continue;
    Msg::Error("Surface %d: embedded points not handled yet by the "
               "Frontal-Delaunay algorithm on the triangulation",
               _gf->tag());
    return false;
  }
  std::set<GEdge *> seen;
  std::map<MVertex *, int> id;
  auto node = [&](MVertex *v) {
    auto it = id.insert({v, (int)_bv.size()});
    if(it.second) {
      _bv.push_back(v);
      double u = 0.;
      GEntity *on = v->onWhat();
      if(on && on->dim() == 1 && v->getParameter(0, u))
        _bAt.push_back({static_cast<GEdge *>(on), u});
      else
        _bAt.push_back({nullptr, 0.});
    }
    return it.first->second;
  };
  for(GEdge *ge : _gf->edges()) {
    if(!seen.insert(ge).second) { // twice on the boundary
      _seams.insert(ge);
      continue;
    }
    if(ge->isSeam(_gf)) _seams.insert(ge);
    if(ge->isMeshDegenerated()) continue;
    for(MLine *l : ge->lines) {
      const int a = node(l->getVertex(0)), b = node(l->getVertex(1));
      if(a == b) continue;
      _segments.push_back({a, b});
      if(_seams.count(ge)) _seamSegments++;
    }
  }
  for(GEdge *ge : _gf->getEmbeddedEdges()) {
    if(!seen.insert(ge).second || ge->isMeshDegenerated()) continue;
    _seams.insert(ge);
    for(MLine *l : ge->lines) {
      const int a = node(l->getVertex(0)), b = node(l->getVertex(1));
      if(a == b) continue;
      _segments.push_back({a, b});
      _seamSegments++;
    }
  }
  if(_bv.size() < 3) {
    Msg::Error("Surface %d: only %d nodes on its boundary", _gf->tag(),
               (int)_bv.size());
    return false;
  }
  for(auto &s : _segments)
    _segmentNodes.insert(std::minmax(_bv[s.first], _bv[s.second]));
  _bSize.assign(_bv.size(), 1e300);
  for(auto &s : _segments) {
    const double l = _bv[s.first]->distance(_bv[s.second]);
    _bSize[s.first] = std::min(_bSize[s.first], l);
    _bSize[s.second] = std::min(_bSize[s.second], l);
  }
  return true;
}

// the polyline of a discrete curve (the points of its discretization), as
// nodes of F as given: null if the curve has no discretization, -1 for its
// points that are no node of F
const std::vector<int> *Scaffold::polyline(GEdge *ge)
{
  auto it = _polylines.find(ge);
  if(it != _polylines.end()) return it->second.empty() ? nullptr : &it->second;
  std::vector<int> &p = _polylines[ge];
  discreteEdge *de = dynamic_cast<discreteEdge *>(ge);
  if(!de || de->discretization().size() < 2) return nullptr;
  for(const SPoint3 &q : de->discretization()) {
    auto f = _fNode.find(P3{q.x(), q.y(), q.z()});
    p.push_back(f == _fNode.end() ? -1 : f->second);
  }
  return &p;
}

// cut F along the seams and the embedded curves, their polylines (the points
// of the discretization of the curves, nodes of F): they become two boundary
// curves, as in a parametrization, the nodes along them duplicated (not the
// free end of an embedded curve, around which the boundary turns)
bool Scaffold::cutSeams()
{
  if(_seams.empty()) return true;
  std::set<std::pair<int, int> > cut;
  for(GEdge *ge : _seams) {
    // (the nodes of F of its polyline; for the other curves, or the points
    // of the polyline that are no node of F, the nearest nodes of F of its
    // points)
    std::vector<int> nodes;
    if(const std::vector<int> *p = polyline(ge)) nodes = *p;
    const int N = nodes.empty() ? (int)std::lround(ge->parBounds(0).high()) + 1 :
                                  (int)nodes.size();
    int prev = -1;
    for(int i = 0; i < N; i++) {
      int n = nodes.empty() ? -1 : nodes[i];
      if(n < 0) {
        const GPoint g = ge->point((double)i);
        const P3 p = {g.x(), g.y(), g.z()};
        auto it = _fNode.find(p);
        if(it != _fNode.end())
          n = it->second;
        else { // the nearest node of F
          double best = 1e300;
          for(std::size_t j = 0; j < _x.size(); j++) {
            const double d = norm(sub(_x[j], p));
            if(d < best) {
              best = d;
              n = (int)j;
            }
          }
        }
      }
      if(prev >= 0 && n != prev) cut.insert(std::minmax(prev, n));
      prev = n;
    }
  }
  std::size_t marked = 0;
  for(std::size_t t = 0; t < _ft.size(); t++)
    for(int k = 0; k < 3; k++)
      if(_fnb[t][k] >= 0 &&
         cut.count(std::minmax(_ft[t][k], _ft[t][(k + 1) % 3]))) {
        _fnb[t][k] = -1;
        marked++;
      }
  if(marked != 2 * cut.size()) {
    Msg::Error("Surface %d: %lu edges of its seams, %lu inside its "
               "triangulation",
               _gf->tag(), cut.size(), marked / 2);
    return false;
  }
  // each node, one per fan of its triangles between boundary edges
  std::vector<std::vector<std::pair<int, int> > > corners(_x.size());
  for(std::size_t t = 0; t < _ft.size(); t++)
    for(int k = 0; k < 3; k++) corners[_ft[t][k]].push_back({(int)t, k});
  std::vector<int> fan(_ft.size() * 3, -1);
  const std::size_t n0 = _x.size();
  for(std::size_t v = 0; v < n0; v++) {
    int fans = 0;
    for(auto &c : corners[v]) {
      if(fan[3 * c.first + c.second] >= 0) continue;
      const int copy = fans++ ? (int)_x.size() : (int)v;
      if(copy != (int)v) {
        _x.push_back(_x[v]);
        _n.push_back(_n[v]);
        _fOrigin.push_back(_fOrigin[v]);
        _fOnEdge.push_back(_fOnEdge[v]);
      }
      // the triangles of the fan, turning both ways from c
      std::vector<int> todo = {c.first};
      fan[3 * c.first + c.second] = copy;
      for(std::size_t i = 0; i < todo.size(); i++) {
        const int t = todo[i];
        int k = 0;
        while(_ft[t][k] != (int)v && _ft[t][k] != copy) k++;
        _ft[t][k] = copy;
        for(int n : {_fnb[t][k], _fnb[t][(k + 2) % 3]}) {
          if(n < 0) continue;
          int l = 0;
          while(l < 3 && _ft[n][l] != (int)v && _ft[n][l] != copy) l++;
          if(l < 3 && fan[3 * n + l] < 0) {
            fan[3 * n + l] = copy;
            todo.push_back(n);
          }
        }
      }
    }
  }
  backgroundNormals();
  return true;
}

// the number of inconsistent adjacencies of F (debugging)
long Scaffold::checkF() const
{
  long bad = 0;
  for(std::size_t t = 0; t < _ft.size(); t++)
    for(int k = 0; k < 3; k++) {
      const int n = _fnb[t][k];
      if(n < 0) continue;
      const int a = _ft[t][k], b = _ft[t][(k + 1) % 3];
      bool ok = false;
      for(int l = 0; l < 3; l++)
        if(_ft[n][l] == b && _ft[n][(l + 1) % 3] == a && _fnb[n][l] == (int)t)
          ok = true;
      bad += !ok;
    }
  return bad;
}

// the inconsistencies of M (debugging): adjacencies, incidences, stars
std::string Scaffold::checkM() const
{
  long adj = 0, inc = 0, stars = 0, twice = 0;
  for(std::size_t t = 0; t < _t.size(); t++) {
    if(!_t[t].alive) continue;
    for(int k = 0; k < 3; k++) {
      const int n = _t[t].nb[k];
      if(n < 0) continue;
      const int a = _t[t].v[k], b = _t[t].v[(k + 1) % 3];
      bool ok = _t[n].alive;
      if(ok) {
        ok = false;
        for(int l = 0; l < 3; l++)
          if(_t[n].v[l] == b && _t[n].v[(l + 1) % 3] == a &&
             _t[n].nb[l] == (int)t)
            ok = true;
      }
      adj += !ok;
    }
  }
  std::vector<int> count(_v.size(), 0);
  for(std::size_t t = 0; t < _t.size(); t++)
    if(_t[t].alive)
      for(int v : _t[t].v) count[v]++;
  for(std::size_t i = 0; i < _v.size(); i++) {
    if(!_v[i].alive) continue;
    const int t = _v[i].inc;
    if(t < 0 || !_t[t].alive || indexOf(t, (int)i) < 0) {
      inc++;
      continue;
    }
    std::vector<int> q, out, tris;
    bool boundary;
    if(!star((int)i, q, out, tris, boundary) || (int)tris.size() != count[i])
      stars++;
    std::unordered_set<int> seen(q.begin(), q.end());
    if(seen.size() != q.size()) twice++;
  }
  char buf[256];
  sprintf(buf, "%ld bad adjacencies, %ld bad incidences, %ld stars not all "
               "the triangles, %ld links with a node twice",
          adj, inc, stars, twice);
  return buf;
}

// F or M in a text file, one triangle per line, each node its coordinates and
// its kind (0: a node of F, 1: of the 1D mesh, 2: a point of the front), for
// the pictures (debugging)
void Scaffold::dump(const std::string &what) const
{
  const std::string name =
    "scaffold_" + std::to_string(_gf->tag()) + "_" + what + ".txt";
  FILE *fp = fopen(name.c_str(), "w");
  if(!fp) return;
  if(what == "F")
    for(const T3 &t : _ft) {
      for(int v : t)
        fprintf(fp, "%.16g %.16g %.16g 0 ", _x[v][0], _x[v][1], _x[v][2]);
      fprintf(fp, "\n");
    }
  else
    for(const Tri &t : _t) {
      if(!t.alive) continue;
      for(int v : t.v) {
        const Node &n = _v[v];
        fprintf(fp, "%.16g %.16g %.16g %d ", n.x[0], n.x[1], n.x[2],
                n.scaffold ? 0 : n.mv ? 1 : 2);
      }
      fprintf(fp, "\n");
    }
  fclose(fp);
}

// the mesh sizes at the nodes of F: the background one, and the one extended
// from the boundary (that of the nearest node of the 1D mesh on the boundary,
// then to the nearest boundary node of F, smoothed)
void Scaffold::backgroundSizes()
{
  const int n = (int)_x.size();
  std::vector<SPoint2> uv(n, SPoint2(0., 0.));
  for(std::size_t t = 0; t < _ft.size(); t++)
    for(int k = 0; k < 3; k++) uv[_ft[t][k]] = _fuv[t][k];
  _sB.resize(n);
  for(int i = 0; i < n; i++) _sB[i] = backgroundSize(_x[i], uv[i]);
  _s1 = _sB;
  if(!_extend1d) return;

  std::vector<std::vector<int> > adj(n);
  std::vector<char> onBoundary(n, 0);
  for(std::size_t t = 0; t < _ft.size(); t++)
    for(int k = 0; k < 3; k++) {
      const int a = _ft[t][k], b = _ft[t][(k + 1) % 3];
      if(_fnb[t][k] < 0) onBoundary[a] = onBoundary[b] = 1;
      if(_fnb[t][k] < 0 || a < b) {
        adj[a].push_back(b);
        adj[b].push_back(a);
      }
    }
  std::vector<double> d(n, 1e300);
  typedef std::pair<double, int> DI;
  std::priority_queue<DI, std::vector<DI>, std::greater<DI> > q;
  for(int i = 0; i < n; i++) {
    if(!onBoundary[i]) continue;
    double best = 1e300;
    for(std::size_t j = 0; j < _bv.size(); j++) {
      const P3 b = {_bv[j]->x(), _bv[j]->y(), _bv[j]->z()};
      const double dd = dot(sub(b, _x[i]), sub(b, _x[i]));
      if(dd < best) {
        best = dd;
        _s1[i] = _bSize[j];
      }
    }
    d[i] = 0.;
    q.push({0., i});
  }
  while(!q.empty()) {
    const std::pair<double, int> e = q.top();
    q.pop();
    if(e.first > d[e.second]) continue;
    for(int j : adj[e.second]) {
      const double dj = e.first + norm(sub(_x[j], _x[e.second]));
      if(dj < d[j]) {
        d[j] = dj;
        _s1[j] = _s1[e.second];
        q.push({dj, j});
      }
    }
  }
  for(int it = 0; it < 20; it++) {
    std::vector<double> s = _s1;
    for(int i = 0; i < n; i++) {
      if(onBoundary[i] || adj[i].empty()) continue;
      double m = 0.;
      for(int j : adj[i]) m += _s1[j];
      s[i] = m / adj[i].size();
    }
    _s1 = s;
  }
}

// cut the edge k of the triangle t1 of F in two
void Scaffold::splitBackgroundEdge(int t1, int k)
{
  const int t2 = _fnb[t1][k];
  const int a = _ft[t1][k], b = _ft[t1][(k + 1) % 3], c = _ft[t1][(k + 2) % 3];
  auto relinkF = [&](int o, int from, int to) {
    if(o < 0) return;
    for(int j = 0; j < 3; j++)
      if(_fnb[o][j] == from) _fnb[o][j] = to;
  };
  if(t2 < 0) { // on the boundary
    const int nbc = _fnb[t1][(k + 1) % 3], nca = _fnb[t1][(k + 2) % 3];
    const SPoint2 ua = _fuv[t1][k], ub = _fuv[t1][(k + 1) % 3],
                  uc = _fuv[t1][(k + 2) % 3];
    const SPoint2 um = (ua + ub) * 0.5;
    const int m = (int)_x.size();
    // (on the boundary edge as given that ab is part of)
    _fOrigin.push_back(-1);
    if(_fOnEdge[a].first >= 0)
      _fOnEdge.push_back(_fOnEdge[a]);
    else if(_fOnEdge[b].first >= 0)
      _fOnEdge.push_back(_fOnEdge[b]);
    else if(_fOrigin[a] >= 0 && _fOrigin[b] >= 0)
      _fOnEdge.push_back(std::minmax(_fOrigin[a], _fOrigin[b]));
    else
      _fOnEdge.push_back({-1, -1});
    _x.push_back(scale(add(_x[a], _x[b]), 0.5));
    _n.push_back(unit(add(_n[a], _n[b])));
    _s1.push_back(0.5 * (_s1[a] + _s1[b]));
    _sB.push_back(backgroundSize(_x[m], um));
    const int t3 = (int)_ft.size();
    _ft[t1] = {a, m, c};
    _fnb[t1] = {-1, t3, nca};
    _fuv[t1] = {ua, um, uc};
    _ft.push_back({m, b, c});
    _fnb.push_back({-1, nbc, t1});
    _fuv.push_back({um, ub, uc});
    relinkF(nbc, t1, t3);
    return;
  }
  int l = 0;
  while(_ft[t2][l] != b) l++;
  const int d = _ft[t2][(l + 2) % 3];
  const int nbc = _fnb[t1][(k + 1) % 3], nca = _fnb[t1][(k + 2) % 3];
  const int nad = _fnb[t2][(l + 1) % 3], ndb = _fnb[t2][(l + 2) % 3];
  const SPoint2 ua1 = _fuv[t1][k], ub1 = _fuv[t1][(k + 1) % 3],
                uc = _fuv[t1][(k + 2) % 3];
  const SPoint2 ub2 = _fuv[t2][l], ua2 = _fuv[t2][(l + 1) % 3],
                ud = _fuv[t2][(l + 2) % 3];
  const SPoint2 um1 = (ua1 + ub1) * 0.5, um2 = (ua2 + ub2) * 0.5;
  const int m = (int)_x.size();
  _fOrigin.push_back(-1);
  _fOnEdge.push_back({-1, -1});
  _x.push_back(scale(add(_x[a], _x[b]), 0.5));
  _n.push_back(unit(add(_n[a], _n[b])));
  _s1.push_back(0.5 * (_s1[a] + _s1[b]));
  _sB.push_back(backgroundSize(_x[m], um1));
  const int t3 = (int)_ft.size(), t4 = t3 + 1;
  _ft[t1] = {a, m, c};
  _fnb[t1] = {t4, t3, nca};
  _fuv[t1] = {ua1, um1, uc};
  _ft.push_back({m, b, c});
  _fnb.push_back({t2, nbc, t1});
  _fuv.push_back({um1, ub1, uc});
  _ft[t2] = {b, m, d};
  _fnb[t2] = {t3, t4, ndb};
  _fuv[t2] = {ub2, um2, ud};
  _ft.push_back({m, a, d});
  _fnb.push_back({t1, nad, t2});
  _fuv.push_back({um2, ua2, ud});
  relinkF(nbc, t1, t3);
  relinkF(nad, t2, t4);
}

// cut the edges of F longer than the mesh size, longest first: the triangles
// of M then all fit in a chart (F stays the same surface; the edges on the
// boundary too, or a triangle on a long one could never be small). An edge is
// cut once it is the longest edge of the triangle beyond it, the longest
// edges beyond it cut before (the longest edge propagation path of Rivara,
// 1997): the triangles of F keep their angles, and F is only as fine as the
// mesh sizes (cutting an edge of a triangle with a much longer one made fans
// of ever thinner triangles towards its far vertex, refined without end)
void Scaffold::refineBackground()
{
  struct E {
    double ratio;
    int t, a, b;
    bool operator<(const E &o) const { return ratio < o.ratio; }
  };
  std::priority_queue<E> q;
  auto consider = [&](int t) {
    for(int k = 0; k < 3; k++) {
      const int a = _ft[t][k], b = _ft[t][(k + 1) % 3];
      const double h = sizeAt(0.5 * (_s1[a] + _s1[b]), 0.5 * (_sB[a] + _sB[b]));
      const double r = norm(sub(_x[a], _x[b])) / h;
      if(r > 1.) q.push({r, t, a, b});
    }
  };
  auto length2 = [&](int t, int k) {
    const P3 d = sub(_x[_ft[t][k]], _x[_ft[t][(k + 1) % 3]]);
    return dot(d, d);
  };
  // the edge ab in t (-1 if it is not one of its edges)
  auto edgeOf = [&](int t, int a, int b) {
    for(int k = 0; k < 3; k++) {
      const int u = _ft[t][k], v = _ft[t][(k + 1) % 3];
      if((u == a && v == b) || (u == b && v == a)) return k;
    }
    return -1;
  };
  auto split = [&](int t, int k) {
    const int t2 = _fnb[t][k], n = (int)_ft.size();
    splitBackgroundEdge(t, k);
    _refined++;
    consider(t);
    consider(n);
    if(t2 >= 0) {
      consider(t2);
      consider(n + 1);
    }
  };
  std::function<void(int, int)> lepp = [&](int t, int k) {
    const int a = _ft[t][k], b = _ft[t][(k + 1) % 3];
    while(true) {
      const int t2 = _fnb[t][k];
      const int s = t2 >= 0 ? edgeOf(t2, a, b) : -1;
      if(s >= 0) {
        int l = s;
        for(int j = 0; j < 3; j++)
          if(length2(t2, j) > length2(t2, l)) l = j;
        if(l != s) {
          lepp(t2, l);
          // (the edge ab is still that of t, unless the path beyond went
          // through t: it is then cut later, from the triangles made)
          k = edgeOf(t, a, b);
          if(k < 0) return;
          continue;
        }
      }
      break;
    }
    split(t, k);
  };
  for(int t = 0; t < (int)_ft.size(); t++) consider(t);
  while(!q.empty()) {
    const E e = q.top();
    q.pop();
    int k = 0;
    while(k < 3 && !(_ft[e.t][k] == e.a && _ft[e.t][(k + 1) % 3] == e.b)) k++;
    if(k == 3) continue;
    if(_x.size() > 20000000) break;
    lepp(e.t, k);
  }
  backgroundNormals();
}

int Scaffold::newTri(const T3 &v)
{
  int id;
  if(!_freeT.empty()) {
    id = _freeT.back();
    _freeT.pop_back();
  }
  else {
    id = (int)_t.size();
    _t.push_back(Tri());
    _mark.push_back(0);
    _tested.push_back(0);
  }
  Tri &t = _t[id];
  t.v = v;
  t.nb = {-1, -1, -1};
  t.r = 0.;
  t.ver++;
  t.alive = true;
  for(int i : v) _v[i].inc = id;
  return id;
}

void Scaffold::killTri(int t)
{
  _t[t].alive = false;
  _t[t].ver++;
  _freeT.push_back(t);
}

void Scaffold::relink(int o, int from, int to)
{
  if(o < 0) return;
  for(int j = 0; j < 3; j++)
    if(_t[o].nb[j] == from) _t[o].nb[j] = to;
}

void Scaffold::setRadius(int t)
{
  const T3 &v = _t[t].v;
  const double s1 = (_v[v[0]].s1 + _v[v[1]].s1 + _v[v[2]].s1) / 3.;
  const double sB = (_v[v[0]].sB + _v[v[1]].sB + _v[v[2]].sB) / 3.;
  _t[t].r = circumRadius(_v[v[0]].x, _v[v[1]].x, _v[v[2]].x) / sizeAt(s1, sB);
}

// the first edge of t on the front (on the boundary, or shared with an
// accepted triangle), -1 if none
int Scaffold::activeEdge(int t) const
{
  for(int k = 0; k < 3; k++) {
    const int n = _t[t].nb[k];
    if(n < 0 || accepted(n)) return k;
  }
  return -1;
}

void Scaffold::push(int t)
{
  if(t < 0 || !_t[t].alive || _t[t].r <= 0. || accepted(t)) return;
  const int k = activeEdge(t);
  if(k < 0) return;
  const int layer =
    std::max(_v[_t[t].v[k]].layer, _v[_t[t].v[(k + 1) % 3]].layer);
  _queue.push({layer, _t[t].r, t, _t[t].ver});
}

// the star of s, counterclockwise: the nodes q of its link and the triangles
// out across its edges, from the boundary if s is on it (q then one node
// longer than the triangles of the star)
bool Scaffold::star(int s, std::vector<int> &q, std::vector<int> &out,
                    std::vector<int> &tris, bool &boundary) const
{
  q.clear();
  out.clear();
  tris.clear();
  boundary = false;
  int t = _v[s].inc;
  if(t < 0 || !_t[t].alive || indexOf(t, s) < 0) return false;
  const int start = t;
  for(int it = 0;; it++) { // turn clockwise to the boundary, if any
    if(it > 10000) return false;
    const int p = _t[t].nb[indexOf(t, s)];
    if(p < 0) {
      boundary = true;
      break;
    }
    t = p;
    if(t == start) break;
  }
  const int first = t;
  for(int it = 0;; it++) {
    if(it > 10000) return false;
    const int k = indexOf(t, s);
    q.push_back(_t[t].v[(k + 1) % 3]);
    out.push_back(_t[t].nb[(k + 1) % 3]);
    tris.push_back(t);
    const int n = _t[t].nb[(k + 2) % 3];
    if(n < 0) {
      q.push_back(_t[t].v[(k + 2) % 3]);
      // the new boundary edge, from the last node to the first
      out.push_back(-1);
      break;
    }
    t = n;
    if(t == first) break;
  }
  return true;
}

// whether the edge (a, b) is in M: the triangles around a, turning both ways
// from that of a (true if they cannot be turned around, as for a node whose
// star cannot be made)
bool Scaffold::edgeExists(int a, int b) const
{
  const int start = _v[a].inc;
  if(start < 0 || !_t[start].alive || indexOf(start, a) < 0) return true;
  for(int dir = 0; dir < 2; dir++) {
    int t = start;
    for(int it = 0;; it++) {
      if(it > 10000) return true;
      const int k = indexOf(t, a);
      if(_t[t].v[(k + 1) % 3] == b || _t[t].v[(k + 2) % 3] == b) return true;
      t = _t[t].nb[dir ? k : (k + 2) % 3];
      if(t == start) return false;
      if(t < 0) break;
    }
  }
  return false;
}

// whether a new edge (a, b) inside M would be one already: an edge of M, or a
// segment of the 1D mesh (always one of M, on its boundary, or inside it for
// the seams and the embedded curves; turning around a node from one of its
// triangles does not see it where the node is between two holes of the face
// a hair apart, as in the small holes left by faces of one triangle)
bool Scaffold::edgeTaken(int a, int b) const
{
  if(_v[a].mv && _v[b].mv &&
     _segmentNodes.count(std::minmax(_v[a].mv, _v[b].mv)))
    return true;
  return edgeExists(a, b);
}

// remove the node s, its star retriangulated in the chart at s: inside, the
// ears of its link, the one whose lifted plane is the lowest above s first
// (Devillers); on the boundary (its two boundary edges becoming one), the
// most regular ear first. False if it cannot be done in the chart. Forced, a
// node of the boundary is removed whatever the chart, as long as the topology
// allows it: the triangulation of its link whose worst triangle is the least
// folded (where the 1D mesh crosses the boundary of F, the triangles it makes
// fold are those of any mesh with that 1D mesh)
bool Scaffold::removeNode(int s, bool force)
{
  std::vector<int> q, out, tris;
  bool boundary;
  _why = "no star";
  if(!star(s, q, out, tris, boundary)) return false;
  const int m = (int)q.size();
  if(boundary && m == 2 && out[0] >= 0) {
    // a single triangle: its third edge becomes a boundary edge
    killTri(tris[0]);
    relink(out[0], tris[0], -1);
    _v[q[0]].inc = _v[q[1]].inc = out[0];
    _v[s].alive = false;
    return true;
  }
  if(!boundary && m == 2) {
    // two triangles back to back: their neighbors become neighbors
    _why = "two triangles back to back on the boundary";
    if(out[0] < 0 && out[1] < 0) return false;
    killTri(tris[0]);
    killTri(tris[1]);
    relink(out[0], tris[0], out[1]);
    relink(out[1], tris[1], out[0]);
    const int o = out[0] >= 0 ? out[0] : out[1];
    _v[q[0]].inc = _v[q[1]].inc = o;
    _v[s].alive = false;
    return true;
  }
  _why = "link too short";
  if(m < 3) return false;
  {
    _why = "node twice in the link";
    std::unordered_set<int> seen(q.begin(), q.end());
    if((int)seen.size() != m) return false;
  }
  const bool topo = force && boundary;
  _why = "new boundary edge already in M";
  if(topo && edgeExists(q[m - 1], q[0])) return false;
  // the chart: the polar map of the star, the distances to s kept and the
  // angles at s scaled to sum to 2 pi (kept on the boundary, unless they sum
  // to more than 2 pi there, the star folded on itself by needles of F:
  // scaled to 1.9 pi), never folded (the tangent plane is, where the star
  // turns much more than the surface is resolved by the mesh size)
  const P2 O = {0., 0.};
  const double W = std::pow(LIMIT_ * nodeSize(s), 2);
  const int fan = boundary ? m - 1 : m;
  std::vector<double> angle(fan);
  double total = 0.;
  for(int i = 0; i < fan; i++) {
    const P3 a = sub(_v[q[i]].x, _v[s].x);
    const P3 b = sub(_v[q[(i + 1) % m]].x, _v[s].x);
    angle[i] = std::atan2(norm(cross(a, b)), dot(a, b));
    total += angle[i];
  }
  _why = "star of no angle";
  if(!(total > 0.) && !topo) return false;
  const double f = !boundary              ? 2. * M_PI / total :
                   total < 1.9 * M_PI ? 1. :
                                          1.9 * M_PI / total;
  std::vector<P2> u(m);
  std::vector<double> z(m);
  double phi = 0.;
  for(int i = 0; i < m; i++) {
    const double r = norm(sub(_v[q[i]].x, _v[s].x));
    u[i] = {r * std::cos(phi), r * std::sin(phi)};
    z[i] = r * r - weight(q[i], W);
    if(i < fan) phi += f * angle[i];
  }
  // (the needles of F along its boundary, three nodes on a curve that is
  // straight in the surface, are flat in the chart, or folded by the tilt of
  // its normal: folded by less than 0.6 degrees, they are not a fold)
  _why = "star folded in the chart";
  for(int i = 0; i < fan && !topo; i++) {
    const P2 &a = u[i], &b = u[(i + 1) % m];
    if(o2(a, b, O) <= -1e-2 * std::hypot(a[0], a[1]) * std::hypot(b[0], b[1])) {
      if(_trace) {
        const P3 &x = _v[s].x;
        Msg::Debug("  node %d (%g %g %g, n %g %g %g) of %d triangles: fan %d "
                   "(%d %d) at %.1f deg, nodes at %g and %g (h %g)",
                   s, x[0], x[1], x[2], _v[s].n[0], _v[s].n[1], _v[s].n[2],
                   (int)tris.size(), i, q[i], q[(i + 1) % m],
                   std::asin(std::max(-1., o2(a, b, O) /
                                             (std::hypot(a[0], a[1]) *
                                              std::hypot(b[0], b[1])))) *
                    180. / M_PI,
                   std::hypot(a[0], a[1]), std::hypot(b[0], b[1]), nodeSize(s));
      }
      return false;
    }
  }
  _why = "new boundary edge crossing the link";
  if(boundary && !topo) {
    // a simple polygon: the new boundary edge crosses no edge of the link
    const P2 &a = u[m - 1], &b = u[0];
    for(int i = 1; i + 2 < m; i++) {
      const double s1 = o2(a, b, u[i]), s2 = o2(a, b, u[i + 1]);
      const double s3 = o2(u[i], u[i + 1], a), s4 = o2(u[i], u[i + 1], b);
      if(s1 * s2 < 0. && s3 * s4 < 0.) return false;
    }
    // (nor a node of the link on it)
    for(int i = 1; i + 1 < m; i++)
      if(o2(a, b, u[i]) == 0. && (u[i][0] - a[0]) * (b[0] - u[i][0]) +
                                       (u[i][1] - a[1]) * (b[1] - u[i][1]) >=
                                     0.)
        return false;
    double area = 0.;
    for(int i = 0; i < m; i++)
      area += u[i][0] * u[(i + 1) % m][1] - u[(i + 1) % m][0] * u[i][1];
    _why = "polygon not counterclockwise";
    if(area <= 0.) return false;
  }
  _why = "no ear";

  std::vector<T3> ears;
  if(topo) {
    // the triangulations of the polygon q[0] ... q[m - 1], their diagonals not
    // edges of M already: the one whose worst triangle (the sine of its
    // smallest angle in the chart, negative if folded) is the best
    auto quality = [&](int a, int b, int c) {
      const double la = std::hypot(u[b][0] - u[c][0], u[b][1] - u[c][1]),
                   lb = std::hypot(u[c][0] - u[a][0], u[c][1] - u[a][1]),
                   lc = std::hypot(u[a][0] - u[b][0], u[a][1] - u[b][1]);
      const double d = std::max(la * lb, std::max(lb * lc, lc * la));
      return d > 0. ? o2(u[a], u[b], u[c]) / d : 0.;
    };
    // (worst[i m + k], split[i m + k]: the best triangulation of q[i] ...
    // q[k], its triangle on (q[i], q[k]); none if split < 0)
    std::vector<double> worst(m * m, 1e300);
    std::vector<int> split(m * m, -1);
    auto valid = [&](int i, int k) { return k == i + 1 || split[i * m + k] >= 0; };
    for(int len = 2; len < m; len++)
      for(int i = 0; i + len < m; i++) {
        const int k = i + len;
        if(k != m - 1 || i) // (the new boundary edge, not in M: tested)
          if(edgeTaken(q[i], q[k])) continue;
        for(int j = i + 1; j < k; j++) {
          if(!valid(i, j) || !valid(j, k)) continue;
          const double w = std::min(std::min(worst[i * m + j], worst[j * m + k]),
                                    quality(i, j, k));
          if(split[i * m + k] < 0 || w > worst[i * m + k]) {
            worst[i * m + k] = w;
            split[i * m + k] = j;
          }
        }
      }
    _why = "no triangulation of the link";
    if(!valid(0, m - 1)) return false;
    std::vector<std::pair<int, int> > todo = {{0, m - 1}};
    while(!todo.empty()) {
      const int i = todo.back().first, k = todo.back().second;
      todo.pop_back();
      const int j = split[i * m + k];
      ears.push_back({i, j, k});
      if(j > i + 1) todo.push_back({i, j});
      if(k > j + 1) todo.push_back({j, k});
    }
  }
  std::vector<int> poly(m);
  for(int i = 0; i < m; i++) poly[i] = i;
  while(!topo && poly.size() > 3) {
    const int n = (int)poly.size();
    int best = -1;
    double bestScore = 0.;
    for(int j = 0; j < n; j++) {
      const int a = poly[(j + n - 1) % n], b = poly[j], c = poly[(j + 1) % n];
      const double A = o2(u[a], u[b], u[c]);
      if(A <= 0.) continue;
      bool empty = true;
      for(int i : poly)
        if(i != a && i != b && i != c && o2(u[a], u[b], u[i]) >= 0. &&
           o2(u[b], u[c], u[i]) >= 0. && o2(u[c], u[a], u[i]) >= 0.)
          empty = false;
      if(!empty) continue;
      // (no edge twice: the charts of a curved surface may not see one
      // outside the star)
      if(n > 3 && edgeTaken(q[a], q[c])) continue;
      double score;
      if(!boundary) // minus the height of the lifted plane above s
        score = -(o2(O, u[b], u[c]) * z[a] + o2(u[a], O, u[c]) * z[b] +
                  o2(u[a], u[b], O) * z[c]) /
                A;
      else { // the smallest angle (its sine, all below 90 degrees but one)
        const double la = std::hypot(u[b][0] - u[c][0], u[b][1] - u[c][1]),
                     lb = std::hypot(u[c][0] - u[a][0], u[c][1] - u[a][1]),
                     lc = std::hypot(u[a][0] - u[b][0], u[a][1] - u[b][1]);
        score = A / std::max(la * lb, std::max(lb * lc, lc * la));
      }
      if(best < 0 || score > bestScore) {
        best = j;
        bestScore = score;
      }
    }
    if(best < 0) return false;
    ears.push_back(
      {poly[(best + n - 1) % n], poly[best], poly[(best + 1) % n]});
    poly.erase(poly.begin() + best);
  }
  if(!topo) {
    if(o2(u[poly[0]], u[poly[1]], u[poly[2]]) <= 0.) return false;
    ears.push_back({poly[0], poly[1], poly[2]});
  }

  for(int t : tris) killTri(t);
  std::map<std::pair<int, int>, std::pair<int, int> > e;
  for(auto &a : ears) {
    const int t = newTri({q[a[0]], q[a[1]], q[a[2]]});
    setRadius(t);
    for(int k = 0; k < 3; k++) e[{a[k], a[(k + 1) % 3]}] = {t, k};
  }
  for(auto &x : e) {
    const int i = x.first.first, j = x.first.second;
    const int t = x.second.first, k = x.second.second;
    auto r = e.find({j, i});
    if(r != e.end()) { _t[t].nb[k] = r->second.first; }
    else { // an edge of the polygon, (i, i + 1)
      const int o = out[i];
      _t[t].nb[k] = o;
      if(o >= 0)
        for(int l = 0; l < 3; l++)
          if(_t[o].v[l] == q[j] && _t[o].v[(l + 1) % 3] == q[i])
            _t[o].nb[l] = t;
    }
  }
  _v[s].alive = false;
  return true;
}

// M: a copy of F, the nodes of the 1D mesh inserted on its boundary
bool Scaffold::initialMesh()
{
  _v.resize(_x.size());
  for(std::size_t i = 0; i < _x.size(); i++) {
    _v[i].x = _x[i];
    _v[i].n = _n[i];
    _v[i].s1 = _s1[i];
    _v[i].sB = _sB[i];
  }
  for(std::size_t t = 0; t < _ft.size(); t++) {
    const int id = newTri(_ft[t]);
    _t[id].nb = _fnb[t];
    for(int k = 0; k < 3; k++) {
      Node &v = _v[_ft[t][k]];
      v.at.f = (int)t;
      v.at.l[0] = v.at.l[1] = v.at.l[2] = 0.;
      v.at.l[k] = 1.;
      if(_fnb[t][k] < 0) v.boundary = _v[_ft[t][(k + 1) % 3]].boundary = true;
    }
  }

  // where the nodes of the 1D mesh are on the boundary of F
  std::vector<std::pair<int, int> > be;
  SBoundingBox3d bbox;
  for(std::size_t t = 0; t < _ft.size(); t++) {
    for(int k = 0; k < 3; k++)
      if(_fnb[t][k] < 0) be.push_back({(int)t, k});
    bbox += SPoint3(_x[_ft[t][0]][0], _x[_ft[t][0]][1], _x[_ft[t][0]][2]);
  }
  // (the nodes of a discrete curve are placed by their topology: on the
  // segment of the polyline of the curve their parameter is in, a boundary
  // edge of F as given - the boundary edges of F it was cut into, on the two
  // sides of a seam -, at their parameter along it; those of its vertices and
  // at the points of its polyline at the boundary nodes of F that are these
  // points. So curves touching each other, or a hair apart, around faces
  // without area, are never mixed up. The others, as those of curves with an
  // exact geometry and no polyline, are on the curve near the polyline of F:
  // they are taken at the point of the polyline nearest to them. In both
  // cases at a node of F if near enough, so that all the decisions are taken
  // on F, their mesh node keeping its position; those of a seam are on the
  // two sides of the cut)
  const double diag = bbox.diag();
  auto given = [&](int a, int b) -> std::pair<int, int> {
    if(_fOnEdge[a].first >= 0) return _fOnEdge[a];
    if(_fOnEdge[b].first >= 0) return _fOnEdge[b];
    if(_fOrigin[a] < 0 || _fOrigin[b] < 0) return {-1, -1};
    return std::minmax(_fOrigin[a], _fOrigin[b]);
  };
  std::map<std::pair<int, int>, std::vector<int> > onGiven;
  std::map<int, std::set<int> > copies;
  for(std::size_t j = 0; j < be.size(); j++) {
    const T3 &t = _ft[be[j].first];
    const int a = t[be[j].second], b = t[(be[j].second + 1) % 3];
    onGiven[given(a, b)].push_back((int)j);
    for(int n : {a, b})
      if(_fOrigin[n] >= 0) copies[_fOrigin[n]].insert(n);
  }
  std::vector<int> all(be.size());
  const std::vector<int> none;
  for(std::size_t j = 0; j < be.size(); j++) all[j] = (int)j;
  long byTopology = 0, byDistance = 0;
  struct OnEdge {
    double s;
    int node;
  };
  std::map<std::pair<int, int>, std::vector<OnEdge> > onEdge;
  std::vector<double> d(be.size()), s(be.size());
  for(std::size_t i = 0; i < _bv.size(); i++) {
    P3 p = {_bv[i]->x(), _bv[i]->y(), _bv[i]->z()};
    // (by its topology: the boundary nodes of F it is, or the boundary edges
    // of F it is on and its point on the polyline)
    const std::set<int> *at = nullptr;
    const std::vector<int> *on = nullptr;
    if(GEdge *ge = _bAt[i].first) {
      const std::vector<int> *pl = polyline(ge);
      int k;
      double tl;
      if(pl && static_cast<discreteEdge *>(ge)->segmentAt(_bAt[i].second, k, tl) &&
         k >= 0 && k + 1 < (int)pl->size() && (*pl)[k] >= 0 && (*pl)[k + 1] >= 0) {
        const int A = (*pl)[k], B = (*pl)[k + 1];
        if(tl <= 0. || tl >= 1.) {
          auto c = copies.find(tl <= 0. ? A : B);
          if(c != copies.end()) at = &c->second;
        }
        else {
          auto o = onGiven.find(std::minmax(A, B));
          if(o != onGiven.end()) {
            on = &o->second;
            p = add(_x[A], scale(sub(_x[B], _x[A]), tl));
          }
        }
      }
    }
    else {
      auto f = _fNode.find(p);
      if(f != _fNode.end()) {
        auto c = copies.find(f->second);
        if(c != copies.end()) at = &c->second;
      }
    }
    if(at || on)
      byTopology++;
    else
      byDistance++;
    std::set<int> nodes;
    std::vector<int> edges;
    if(at) nodes = *at;
    const std::vector<int> &js = at ? none : on ? *on : all;
    double best = 1e300;
    for(int j : js) {
      const T3 &t = _ft[be[j].first];
      const int k = be[j].second;
      const P3 &a = _x[t[k]], &b = _x[t[(k + 1) % 3]];
      const P3 ab = sub(b, a);
      const double l2 = dot(ab, ab);
      s[j] = l2 > 0. ? dot(sub(p, a), ab) / l2 : 0.;
      s[j] = std::max(0., std::min(1., s[j]));
      d[j] = norm(sub(add(a, scale(ab, s[j])), p));
      best = std::min(best, d[j]);
    }
    if(!at && !on && best > 0.1 * _bSize[i] + 1e-6 * diag) {
      Msg::Error("Surface %d: node %lu (%g %g %g, on %d) of its boundary "
                 "curves not on the boundary of its triangulation (at %g)",
                 _gf->tag(), _bv[i]->getNum(), p[0], p[1], p[2],
                 _bv[i]->onWhat()->tag(), best);
      return false;
    }
    // (snapped to the nearest nodes of F only: the copies of a node cut along
    // a seam are at the same place, but two nodes of F a hair apart are not,
    // and the farther one is then removed as the other nodes of F)
    const double snap = 0.01 * _bSize[i] + 1e-9 * diag;
    double nearest = 1e300;
    for(int j : js) {
      if(d[j] > best + 1e-9 * diag) continue;
      const int t = be[j].first, k = be[j].second;
      for(int a : {_ft[t][k], _ft[t][(k + 1) % 3]})
        nearest = std::min(nearest, norm(sub(_x[a], p)));
    }
    for(int j : js) {
      if(d[j] > best + 1e-9 * diag) continue;
      const int t = be[j].first, k = be[j].second;
      const int a = _ft[t][k], b = _ft[t][(k + 1) % 3];
      const double da = norm(sub(_x[a], p)), db = norm(sub(_x[b], p));
      if(da > snap && db > snap) {
        edges.push_back((int)j);
        continue;
      }
      if(da <= snap && da <= nearest + 1e-9 * diag) nodes.insert(a);
      if(db <= snap && db <= nearest + 1e-9 * diag) nodes.insert(b);
    }
    for(int node : nodes) { // a node of F
      if(!_v[node].scaffold) {
        Msg::Error("Surface %d: two nodes of its boundary curves at node %d of "
                   "its triangulation",
                   _gf->tag(), node);
        return false;
      }
      _v[node].scaffold = false;
      _v[node].mv = _bv[i];
      _v[node].s1 = _v[node].sB = _bSize[i];
    }
    for(int j : edges) onEdge[be[j]].push_back({s[j], (int)i});
  }
  Msg::Debug("Surface %d: %ld nodes of its curves placed by their topology, "
             "%ld by their distance to the boundary of its triangulation",
             _gf->tag(), byTopology, byDistance);
  // the triangle of M with each boundary edge, and the index of the edge in it
  // (cutting an edge moves the next one of its triangle to the new triangle)
  std::map<std::pair<int, int>, std::pair<int, int> > boundaryEdge;
  for(std::size_t t = 0; t < _t.size(); t++)
    for(int k = 0; k < 3; k++)
      if(_t[t].nb[k] < 0)
        boundaryEdge[{_t[t].v[k], _t[t].v[(k + 1) % 3]}] = {(int)t, k};
  for(auto &e : onEdge) {
    std::vector<OnEdge> &l = e.second;
    std::sort(l.begin(), l.end(),
              [](const OnEdge &a, const OnEdge &b) { return a.s < b.s; });
    const T3 &f = _ft[e.first.first];
    const std::pair<int, int> &where = boundaryEdge.at(
      {f[e.first.second], f[(e.first.second + 1) % 3]});
    // each node cuts the rest of the edge
    int T = where.first, k = where.second;
    for(const OnEdge &o : l) {
      Node nd;
      const P3 &a = _x[f[e.first.second]], &b = _x[f[(e.first.second + 1) % 3]];
      nd.x = add(a, scale(sub(b, a), o.s));
      nd.at.f = e.first.first;
      nd.at.l[e.first.second] = 1. - o.s;
      nd.at.l[(e.first.second + 1) % 3] = o.s;
      nd.n = normalAt(nd.at);
      nd.s1 = nd.sB = _bSize[o.node];
      nd.mv = _bv[o.node];
      nd.scaffold = false;
      nd.boundary = true;
      const int qn = (int)_v.size();
      _v.push_back(nd);
      const int w = _t[T].v[(k + 1) % 3], c = _t[T].v[(k + 2) % 3];
      const int nwc = _t[T].nb[(k + 1) % 3];
      const int N = newTri({qn, w, c});
      _t[N].nb = {-1, nwc, T};
      _t[T].v[(k + 1) % 3] = qn;
      _t[T].nb[(k + 1) % 3] = N;
      relink(nwc, T, N);
      if(nwc < 0) boundaryEdge[{w, c}] = {N, 1};
      _v[_t[T].v[k]].inc = T;
      T = N;
      k = 0;
    }
  }
  return removeBoundaryScaffold();
}

// the scaffold nodes of the boundary removed one by one, then the boundary of
// M is the 1D mesh
bool Scaffold::removeBoundaryScaffold()
{
  for(int pass = 0;; pass++) {
    long left = 0, done = 0;
    for(std::size_t i = 0; i < _v.size(); i++) {
      if(!_v[i].alive || !_v[i].scaffold || !_v[i].boundary) continue;
      if(removeNode((int)i)) {
        done++;
        continue;
      }
      left++;
      if(Msg::GetVerbosity() > 98) {
        std::vector<int> q, out, tris;
        bool b;
        star((int)i, q, out, tris, b);
        Msg::Debug("Surface %d: boundary node %lu (%g %g %g) not removed: %s "
                   "(%lu triangles, link of %lu, boundary %d)",
                   _gf->tag(), i, _v[i].x[0], _v[i].x[1], _v[i].x[2], _why,
                   tris.size(), q.size(), (int)b);
        for(int j : q)
          Msg::Debug("  link node %d (%g %g %g) scaffold %d boundary %d", j,
                     _v[j].x[0], _v[j].x[1], _v[j].x[2], (int)_v[j].scaffold,
                     (int)_v[j].boundary);
      }
      // the scaffold inside that its link crosses removed first
      std::vector<int> q, out, tris;
      bool boundary;
      if(star((int)i, q, out, tris, boundary))
        for(int j : q)
          if(_v[j].alive && _v[j].scaffold && !_v[j].boundary && removeNode(j))
            done++;
    }
    _removed += done;
    if(!left) break;
    if(!done) {
      // none removed in its chart: one removed whatever the geometry (the 1D
      // mesh crossing the boundary of F, which it is not for M to change),
      // then the others tried again in their charts
      for(std::size_t i = 0; i < _v.size() && !done; i++)
        if(_v[i].alive && _v[i].scaffold && _v[i].boundary &&
           removeNode((int)i, true))
          done++;
      _removed += done;
      _forced += done;
    }
    if(!done || pass > (int)_v.size()) {
      Msg::Error("Surface %d: %ld nodes of its triangulation left on its "
                 "boundary",
                 _gf->tag(), left);
      return false;
    }
  }
  // the boundary of M must now be the 1D mesh, the seams and embedded curves
  // twice
  std::set<std::pair<int, int> > segments;
  for(auto &s : _segments) segments.insert(std::minmax(s.first, s.second));
  std::map<MVertex *, int> id;
  for(std::size_t i = 0; i < _bv.size(); i++) id[_bv[i]] = (int)i;
  std::size_t expected = _segments.size() + _seamSegments, found = 0;
  for(std::size_t t = 0; t < _t.size(); t++) {
    if(!_t[t].alive) continue;
    for(int k = 0; k < 3; k++) {
      if(_t[t].nb[k] >= 0) continue;
      const Node &a = _v[_t[t].v[k]], &b = _v[_t[t].v[(k + 1) % 3]];
      if(!a.mv || !b.mv ||
         !segments.count(std::minmax(id[a.mv], id[b.mv]))) {
        Msg::Error("Surface %d: boundary of its triangulation not that of its "
                   "curves",
                   _gf->tag());
        for(const Node *n : {&a, &b})
          Msg::Debug("  edge node (%g %g %g): scaffold %d, mesh node %lu (on "
                     "%d)",
                     n->x[0], n->x[1], n->x[2], (int)n->scaffold,
                     n->mv ? n->mv->getNum() : 0,
                     n->mv ? n->mv->onWhat()->tag() : 0);
        return false;
      }
      found++;
    }
  }
  if(found != expected) {
    Msg::Error("Surface %d: %lu segments of its curves (seams and embedded "
               "twice), %lu on the boundary of its triangulation",
               _gf->tag(), expected, found);
    return false;
  }
  return true;
}

// the edge k of the triangle i flipped: (a, b, c) and its neighbor (b, a, d)
// become (c, a, d) and (d, b, c); the neighbor
int Scaffold::flipEdge(int i, int k)
{
  const int n = _t[i].nb[k];
  const int a = _t[i].v[k], b = _t[i].v[(k + 1) % 3], c = _t[i].v[(k + 2) % 3];
  const int l = indexOf(n, b);
  const int d = _t[n].v[(l + 2) % 3];
  const int tbc = _t[i].nb[(k + 1) % 3], tca = _t[i].nb[(k + 2) % 3];
  const int tad = _t[n].nb[(l + 1) % 3], tdb = _t[n].nb[(l + 2) % 3];
  _t[i].v = {c, a, d};
  _t[i].nb = {tca, tad, n};
  _t[n].v = {d, b, c};
  _t[n].nb = {tdb, tbc, i};
  _t[i].ver++;
  _t[n].ver++;
  relink(tad, n, i);
  relink(tbc, i, n);
  _v[a].inc = _v[c].inc = _v[d].inc = i;
  _v[b].inc = n;
  setRadius(i);
  setRadius(n);
  return n;
}

// Lawson's flips, each decided in the chart at the middle of the edge, the
// scaffold weighted: the number of flips. The edges are all tested once (from
// the triangle of lower index), then those of the two triangles of each flip;
// at most 100 flips per triangle (the weights of the scaffold depend on the
// edge, so that a flip and its reverse could alternate)
long Scaffold::flip()
{
  // 0: not to test, 1: to test (the edges towards higher indices), 2: to test
  // (all its edges)
  std::vector<char> state(_t.size(), 0);
  std::vector<int> todo;
  for(int i = (int)_t.size() - 1; i >= 0; i--)
    if(_t[i].alive) {
      state[i] = 1;
      todo.push_back(i);
    }
  const long cap = 100 * (long)todo.size();
  auto again = [&](int t) {
    if(!state[t]) todo.push_back(t);
    state[t] = 2;
  };
  long flips = 0;
  while(!todo.empty() && flips < cap) {
    const int i = todo.back();
    todo.pop_back();
    const bool all = state[i] == 2;
    state[i] = 0;
    for(int k = 0; k < 3 && _t[i].alive; k++) {
      const int n = _t[i].nb[k];
      if(n < 0 || (!all && n < i)) continue;
      const int a = _t[i].v[k], b = _t[i].v[(k + 1) % 3],
                c = _t[i].v[(k + 2) % 3];
      const int l = indexOf(n, b); // n = (b, a, d)
      const int d = _t[n].v[(l + 2) % 3];
      if(c == d) continue;
      // (the chart of the quadrilateral and the weight, the same for both
      // diagonals to the last bit: the nodes summed in the order of their
      // indices; otherwise the rounding decides the cocircular ones, those of
      // the triangulations of the primitives, differently for the two
      // diagonals, and they are flipped back and forth)
      int o[4] = {a, b, c, d};
      std::sort(o, o + 4);
      const Chart C(
        scale(add(add(_v[o[0]].x, _v[o[1]].x), add(_v[o[2]].x, _v[o[3]].x)),
              0.25),
        unit(add(add(_v[o[0]].n, _v[o[1]].n), add(_v[o[2]].n, _v[o[3]].n))));
      const double W =
        std::pow(LIMIT_ * 0.25 *
                   ((nodeSize(o[0]) + nodeSize(o[1])) +
                    (nodeSize(o[2]) + nodeSize(o[3]))),
                 2);
      const int v4[4] = {a, b, c, d};
      P2 q[4];
      double L[4][3];
      for(int j = 0; j < 4; j++) {
        q[j] = C.uv(_v[v4[j]].x);
        L[j][0] = q[j][0];
        L[j][1] = q[j][1];
        L[j][2] = q[j][0] * q[j][0] + q[j][1] * q[j][1] - weight(v4[j], W);
      }
      if(robustPredicates::orient3dDynamic(L[0], L[1], L[2], L[3]) <= 0.)
        continue;
      if(o2(q[3], q[1], q[2]) <= 0. || o2(q[2], q[0], q[3]) <= 0.) continue;
      if(edgeTaken(c, d)) continue;
      flipEdge(i, k);
      flips++;
      again(i);
      again(n);
      break;
    }
  }
  return flips;
}

// the intersection of F with the circle of center m and radius L in the plane
// of normal e, nearest to the direction dir (in that plane): the triangles of
// F within reach of the circle visited from the seeds, the segment of each
// that the plane cuts intersected with the sphere of the circle
bool Scaffold::circleOnF(const P3 &m, const P3 &e, const P3 &dir, double L,
                         int seed0, int seed1, P3 &p, Location &at)
{
  if(_fMark.size() != _ft.size()) _fMark.assign(_ft.size(), 0);
  const int stamp = ++_fStamp;
  std::vector<int> todo;
  for(int s : {seed0, seed1})
    if(s >= 0 && _fMark[s] != stamp) {
      _fMark[s] = stamp;
      todo.push_back(s);
    }
  double best = 0.3; // at most 72 degrees away
  bool found = false;
  for(std::size_t i = 0; i < todo.size(); i++) {
    const int t = todo[i];
    const P3 &x0 = _x[_ft[t][0]], &x1 = _x[_ft[t][1]], &x2 = _x[_ft[t][2]];
    const P3 c = scale(add(add(x0, x1), x2), 1. / 3.);
    const double rad = std::max(norm(sub(x0, c)),
                                std::max(norm(sub(x1, c)), norm(sub(x2, c))));
    if(norm(sub(c, m)) - rad > 1.5 * L) continue;
    for(int k = 0; k < 3; k++) {
      const int n = _fnb[t][k];
      if(n >= 0 && _fMark[n] != stamp) {
        _fMark[n] = stamp;
        todo.push_back(n);
      }
    }
    const P3 *X[3] = {&x0, &x1, &x2};
    double s[3];
    for(int k = 0; k < 3; k++) s[k] = dot(sub(*X[k], m), e);
    P3 seg[2];
    int ns = 0;
    for(int k = 0; k < 3 && ns < 2; k++) {
      const int j = (k + 1) % 3;
      if((s[k] >= 0.) == (s[j] >= 0.)) continue;
      seg[ns++] = add(*X[k], scale(sub(*X[j], *X[k]), s[k] / (s[k] - s[j])));
    }
    if(ns < 2) continue;
    const P3 d = sub(seg[1], seg[0]), w = sub(seg[0], m);
    const double A = dot(d, d), B = 2. * dot(w, d), Cc = dot(w, w) - L * L;
    const double disc = B * B - 4. * A * Cc;
    if(!(A > 0.) || disc < 0.) continue;
    for(double sg : {-1., 1.}) {
      const double u = (-B + sg * std::sqrt(disc)) / (2. * A);
      if(u < -1e-12 || u > 1. + 1e-12) continue;
      const P3 y = add(seg[0], scale(d, u));
      const double cs = dot(sub(y, m), dir) / L;
      if(cs > best) {
        best = cs;
        p = y;
        at.f = t;
        found = true;
      }
    }
  }
  if(!found) return false;
  // the barycentric coordinates of p in its triangle
  const T3 &t = _ft[at.f];
  const P3 N = cross(sub(_x[t[1]], _x[t[0]]), sub(_x[t[2]], _x[t[0]]));
  const double N2 = dot(N, N);
  double sum = 0.;
  for(int k = 0; k < 3; k++) {
    const P3 &b = _x[t[(k + 1) % 3]], &c = _x[t[(k + 2) % 3]];
    at.l[k] = N2 > 0. ? std::max(0., dot(N, cross(sub(b, p), sub(c, p))) / N2) :
                        1. / 3.;
    sum += at.l[k];
  }
  for(int k = 0; k < 3; k++) at.l[k] /= sum;
  return true;
}

// the optimal point of the Frontal-Delaunay algorithm for the active edge k of
// t, found on F: at sqrt(3)/2 the mesh size from the middle of the edge, in
// its bisecting plane, towards the inside of t (and not beyond the
// circumcenter of a triangle of mesh nodes, as in the Frontal-Delaunay
// algorithm; with a scaffold node the point is always in conflict with t)
bool Scaffold::optimalPoint(int t, int k, P3 &p, Location &at)
{
  const int a = _t[t].v[k], b = _t[t].v[(k + 1) % 3], c = _t[t].v[(k + 2) % 3];
  const P3 &xa = _v[a].x, &xb = _v[b].x;
  const P3 m = scale(add(xa, xb), 0.5);
  const P3 e = sub(xb, xa);
  const P3 n = unit(add(_v[a].n, _v[b].n));
  const P3 dir = unit(cross(n, e));
  const double rho =
    sizeAt(0.5 * (_v[a].s1 + _v[b].s1), 0.5 * (_v[a].sB + _v[b].sB));
  double L = rho * std::sqrt(3.) * 0.5;
  if(!hasScaffold(t)) {
    const P3 cc = circumCenter(xa, xb, _v[c].x);
    if(dot(sub(cc, m), dir) > 0.) L = std::min(L, norm(sub(cc, m)));
  }
  if(!(L > 0.)) return false;
  return circleOnF(m, unit(e), dir, L, _v[a].at.f, _v[b].at.f, p, at);
}

// insert a node at p (at on F) found for the triangle t: Bowyer-Watson in the
// chart at p, the scaffold weighted, the cavity grown from the triangle p is
// in (reached from t), shrunk until star-shaped; the scaffold inside it
// removed
bool Scaffold::insertPoint(const P3 &p, const Location &at, int t, int layer)
{
  Node nd;
  nd.x = p;
  nd.at = at;
  nd.n = normalAt(at);
  nd.s1 = 0.;
  for(int k = 0; k < 3; k++) nd.s1 += at.l[k] * _s1[_ft[at.f][k]];
  nd.sB = backgroundSize(p, uvAt(at));
  nd.scaffold = false;
  nd.layer = layer;
  const int pi = (int)_v.size();
  _v.push_back(nd);
  const char *why = "";
  auto reject = [&]() {
    _v.pop_back();
    _rejects[why]++;
    return false;
  };
  const double h = nodeSize(pi), R = 10. * h;
  const double W = scaffoldWeight(h);
  const Chart C(p, nd.n);
  const P2 O = {0., 0.};
  auto uv = [&](int v) { return C.uv(_v[v].x); };
  auto conflict = [&](int t) {
    const T3 &v = _t[t].v;
    P2 q[3];
    double L[3][3];
    for(int k = 0; k < 3; k++) {
      if(norm(sub(_v[v[k]].x, p)) > R) return false;
      q[k] = uv(v[k]);
      L[k][0] = q[k][0];
      L[k][1] = q[k][1];
      L[k][2] = q[k][0] * q[k][0] + q[k][1] * q[k][1] - weight(v[k], W);
    }
    if(o2(q[0], q[1], q[2]) <= 0.) return false; // folded in the chart
    const double P[3] = {0., 0., 0.};
    return robustPredicates::orient3dDynamic(L[0], L[1], L[2], P) > 0.;
  };

  // the triangle p is in
  why = "walk";
  for(int step = 0;; step++) {
    if(step > 10000) return reject();
    bool moved = false;
    for(int j = 0; j < 3 && !moved; j++) {
      const int k = (j + step) % 3;
      if(o2(uv(_t[t].v[k]), uv(_t[t].v[(k + 1) % 3]), O) < 0.) {
        t = _t[t].nb[k];
        if(t < 0) { // outside
          why = "outside";
          return reject();
        }
        moved = true;
      }
    }
    if(!moved) break;
  }
  why = "not in conflict";
  if(!conflict(t)) return reject();

  // the cavity
  const int t0 = t;
  int s = ++_stamp;
  std::vector<int> cavity = {t0};
  _mark[t0] = s;
  for(std::size_t i = 0; i < cavity.size(); i++)
    for(int n : _t[cavity[i]].nb) {
      if(n < 0 || _mark[n] == s || _tested[n] == s) continue;
      _tested[n] = s;
      if(conflict(n)) {
        _mark[n] = s;
        cavity.push_back(n);
      }
    }
  // star-shaped from p: drop the triangles behind an edge not seen from it
  for(;;) {
    int bad = -1;
    for(int c : cavity) {
      for(int k = 0; k < 3 && bad < 0; k++) {
        const int n = _t[c].nb[k];
        if((n < 0 || _mark[n] != s) &&
           o2(uv(_t[c].v[k]), uv(_t[c].v[(k + 1) % 3]), O) <= 0.)
          bad = c;
      }
      if(bad >= 0) break;
    }
    if(bad < 0) break;
    why = "not star-shaped";
    if(bad == t0) return reject();
    _shrunk++;
    _mark[bad] = 0;
    const int s2 = ++_stamp;
    std::vector<int> part = {t0};
    _mark[t0] = s2;
    for(std::size_t i = 0; i < part.size(); i++)
      for(int n : _t[part[i]].nb)
        if(n >= 0 && _mark[n] == s) {
          _mark[n] = s2;
          part.push_back(n);
        }
    cavity = part;
    s = s2;
  }

  // a disk (one boundary cycle, as many triangles as boundary edges plus
  // twice the inner nodes minus 2), its inner nodes all scaffold, and p not
  // too close to the mesh nodes on its boundary (the tests of the
  // Frontal-Delaunay algorithm)
  struct Shell {
    int a, b, out;
  };
  std::vector<Shell> shell;
  why = "not a disk";
  std::unordered_map<int, int> from;
  std::unordered_set<int> nodes;
  for(int c : cavity)
    for(int k = 0; k < 3; k++) {
      nodes.insert(_t[c].v[k]);
      const int n = _t[c].nb[k];
      if(n < 0 || _mark[n] != s) {
        if(!from.insert({_t[c].v[k], (int)shell.size()}).second)
          return reject();
        shell.push_back({_t[c].v[k], _t[c].v[(k + 1) % 3], n});
      }
    }
  std::vector<int> inner;
  for(int v : nodes)
    if(!from.count(v)) inner.push_back(v);
  {
    std::size_t count = 0;
    int i = 0;
    do {
      auto it = from.find(shell[i].b);
      if(it == from.end()) break;
      i = it->second;
      count++;
    } while(i != 0 && count <= shell.size());
    if(count != shell.size() ||
       cavity.size() != shell.size() + 2 * inner.size() - 2)
      return reject();
  }
  why = "mesh node inside";
  for(int v : inner)
    if(!_v[v].scaffold) return reject();
  why = "too close";
  const double cosSq = (2. * .9999) * (2. * .9999);
  for(const Shell &e : shell) {
    const Node &a = _v[e.a], &b = _v[e.b];
    const double lc = (a.s1 + b.s1 + nd.s1) / 3.,
                 lcB = (a.sB + b.sB + nd.sB) / 3.;
    const double LL = std::min(lc, lcB), hh = 0.5 * LL;
    const double d1 = dot(sub(a.x, p), sub(a.x, p)),
                 d2 = dot(sub(b.x, p), sub(b.x, p)),
                 d3 = dot(sub(a.x, b.x), sub(a.x, b.x));
    if((!a.scaffold && d1 < hh * hh) || (!b.scaffold && d2 < hh * hh))
      return reject();
    if(a.boundary && b.boundary && !a.scaffold && !b.scaffold) {
      const P3 cr = cross(sub(b.x, a.x), sub(p, a.x));
      if(dot(cr, cr) < 0.16 * LL * LL * d3) return reject();
    }
    if(!a.scaffold && !b.scaffold) {
      const double num = d1 + d2 - d3;
      if(num < 0. && num * num > cosSq * d1 * d2) return reject();
    }
  }

  // (one insertion in pictures: M before, the cavity, M after, the cavity
  // file starting with the point, its mesh size and the weight; debugging)
  const bool picture = Msg::GetVerbosity() > 98 &&
                       (_inserted + 1 == 30 || _inserted + 1 == 60);
  if(picture) {
    const std::string n = std::to_string(_inserted + 1);
    dump("before_" + n);
    FILE *fp = fopen(("scaffold_" + std::to_string(_gf->tag()) + "_cavity_" +
                      n + ".txt").c_str(), "w");
    fprintf(fp, "%.16g %.16g %.16g %.16g %.16g\n", p[0], p[1], p[2], h, W);
    for(int c : cavity) {
      for(int v : _t[c].v)
        fprintf(fp, "%.16g %.16g %.16g %d ", _v[v].x[0], _v[v].x[1],
                _v[v].x[2], (int)_v[v].alive);
      fprintf(fp, "\n");
    }
    fclose(fp);
  }

  // the fan from p
  for(int c : cavity) killTri(c);
  for(int v : inner) _v[v].alive = false;
  _hidden += inner.size();
  std::vector<int> nt(shell.size());
  std::unordered_map<int, int> startAt;
  for(std::size_t i = 0; i < shell.size(); i++) {
    const int id = newTri({shell[i].a, shell[i].b, pi});
    nt[i] = id;
    startAt[shell[i].a] = id;
    _t[id].nb[0] = shell[i].out;
    const int o = shell[i].out;
    if(o >= 0)
      for(int k = 0; k < 3; k++)
        if(_t[o].v[k] == shell[i].b && _t[o].v[(k + 1) % 3] == shell[i].a)
          _t[o].nb[k] = id;
  }
  for(std::size_t i = 0; i < shell.size(); i++) {
    const int n = startAt[shell[i].b];
    _t[nt[i]].nb[1] = n;
    _t[n].nb[2] = nt[i];
    _v[shell[i].a].inc = nt[i];
    setRadius(nt[i]);
  }
  for(std::size_t i = 0; i < shell.size(); i++) {
    push(nt[i]);
    push(shell[i].out);
  }
  _inserted++;
  if(picture) dump("after_" + std::to_string(_inserted));
  if(Msg::GetVerbosity() > 98 && _inserted >= 25 &&
     (_inserted / 25 & (_inserted / 25 - 1)) == 0 && _inserted % 25 == 0)
    dump("M_" + std::to_string(_inserted));
  return true;
}

void Scaffold::front()
{
  _queue = std::priority_queue<QueueEntry>();
  for(int t = 0; t < (int)_t.size(); t++)
    if(_t[t].alive && _t[t].r >= 0.) setRadius(t);
  for(int t = 0; t < (int)_t.size(); t++)
    if(_t[t].alive) push(t);
  while(!_queue.empty()) {
    const QueueEntry e = _queue.top();
    _queue.pop();
    if(Msg::GetVerbosity() > 98 && (_inserted + _failed) % 20000 == 19999)
      Msg::Debug("Surface %d: front, %ld inserted, %ld failed, queue %lu",
                 _gf->tag(), _inserted, _failed, _queue.size());
    const int t = e.t;
    if(!_t[t].alive || _t[t].ver != e.ver || _t[t].r <= 0. || accepted(t))
      continue;
    const int k = activeEdge(t);
    if(k < 0) continue;
    P3 p;
    Location at;
    if(!optimalPoint(t, k, p, at)) {
      _rejects["no point on F"]++;
      _t[t].r = -1.;
      _failed++;
    }
    else if(!insertPoint(p, at, t,
                         1 + std::max(_v[_t[t].v[k]].layer,
                                      _v[_t[t].v[(k + 1) % 3]].layer))) {
      _t[t].r = -1.;
      _failed++;
    }
  }
}

// the mesh: the nodes of M that are not the boundary ones, and its triangles
// the point of F nearest to x, among the triangles of F within reach of x
// visited from the triangle of at across the edges of F that are not cut
// (the seams, the embedded curves): at is updated
bool Scaffold::nearestOnF(const P3 &x, double reach, Location &at, P3 &p)
{
  if(at.f < 0) return false;
  if(_fMark.size() != _ft.size()) _fMark.assign(_ft.size(), 0);
  const int stamp = ++_fStamp;
  std::vector<int> todo = {at.f};
  _fMark[at.f] = stamp;
  double best = 1e300;
  int bestF = -1;
  P3 bestP = x;
  for(std::size_t i = 0; i < todo.size(); i++) {
    const int t = todo[i];
    const P3 &a = _x[_ft[t][0]], &b = _x[_ft[t][1]], &c = _x[_ft[t][2]];
    const P3 g = scale(add(add(a, b), c), 1. / 3.);
    const double rad = std::max(norm(sub(a, g)),
                                std::max(norm(sub(b, g)), norm(sub(c, g))));
    if(norm(sub(g, x)) - rad > reach) continue;
    for(int k = 0; k < 3; k++) {
      const int n = _fnb[t][k];
      if(n >= 0 && _fMark[n] != stamp) {
        _fMark[n] = stamp;
        todo.push_back(n);
      }
    }
    // the point of the triangle nearest to x (Ericson)
    const P3 ab = sub(b, a), ac = sub(c, a), ap = sub(x, a);
    const double d1 = dot(ab, ap), d2 = dot(ac, ap);
    const P3 bp = sub(x, b);
    const double d3 = dot(ab, bp), d4 = dot(ac, bp);
    const P3 cp = sub(x, c);
    const double d5 = dot(ab, cp), d6 = dot(ac, cp);
    P3 y;
    if(d1 <= 0. && d2 <= 0.) y = a;
    else if(d3 >= 0. && d4 <= d3) y = b;
    else if(d6 >= 0. && d5 <= d6) y = c;
    else {
      const double vc = d1 * d4 - d3 * d2, vb = d5 * d2 - d1 * d6,
                   va = d3 * d6 - d5 * d4;
      if(vc <= 0. && d1 >= 0. && d3 <= 0.)
        y = add(a, scale(ab, d1 / (d1 - d3)));
      else if(vb <= 0. && d2 >= 0. && d6 <= 0.)
        y = add(a, scale(ac, d2 / (d2 - d6)));
      else if(va <= 0. && (d4 - d3) >= 0. && (d5 - d6) >= 0.)
        y = add(b, scale(sub(c, b), (d4 - d3) / ((d4 - d3) + (d5 - d6))));
      else {
        const double den = va + vb + vc;
        y = add(a, add(scale(ab, vb / den), scale(ac, vc / den)));
      }
    }
    const double d = norm(sub(y, x));
    if(d < best) {
      best = d;
      bestF = t;
      bestP = y;
    }
  }
  if(bestF < 0) return false;
  p = bestP;
  at.f = bestF;
  const T3 &t = _ft[bestF];
  const P3 N = cross(sub(_x[t[1]], _x[t[0]]), sub(_x[t[2]], _x[t[0]]));
  const double N2 = dot(N, N);
  double sum = 0.;
  for(int k = 0; k < 3; k++) {
    const P3 &b = _x[t[(k + 1) % 3]], &c = _x[t[(k + 2) % 3]];
    at.l[k] = N2 > 0. ? std::max(0., dot(N, cross(sub(b, p), sub(c, p))) / N2) :
                        1. / 3.;
    sum += at.l[k];
  }
  for(int k = 0; k < 3; k++) at.l[k] = sum > 0. ? at.l[k] / sum : 1. / 3.;
  return true;
}

// the quality of a triangle, 4 sqrt(3) area / sum of the squared lengths
static double gamma3(const P3 &a, const P3 &b, const P3 &c)
{
  const double l2 = dot(sub(b, a), sub(b, a)) + dot(sub(c, b), sub(c, b)) +
                    dot(sub(a, c), sub(a, c));
  return l2 > 0. ? 2. * std::sqrt(3.) * norm(cross(sub(b, a), sub(c, a))) / l2 :
                   0.;
}

// the mesh smoothed, passes times: each node of the front moved by a local
// Winslow in the mean plane of its star (WinslowUntangler::untangle2D, its
// link fixed, equilateral targets of the mesh size there), then put back on
// F at the point of F nearest to it; the move is refused if it turns a
// triangle of the star over (with respect to the normals of F) or lowers the
// smallest quality of the star. Lawson's flips after each pass
void Scaffold::smooth(int passes)
{
  std::vector<int> q, out, tris;
  bool boundary;
  for(int pass = 0; pass < passes; pass++) {
    long moved = 0, tried = 0;
    for(std::size_t si = 0; si < _v.size(); si++) {
      const int s = (int)si;
      if(!_v[s].alive || _v[s].scaffold || _v[s].boundary || _v[s].mv)
        continue;
      if(!star(s, q, out, tris, boundary) || boundary || q.size() < 3 ||
         q.size() != tris.size())
        continue;
      tried++;
      // the mean plane of the star: through the centroid of its nodes, normal
      // to the sum of the area vectors of its triangles
      P3 c = _v[s].x, nrm = {0., 0., 0.};
      for(int j : q) c = add(c, _v[j].x);
      c = scale(c, 1. / (double)(q.size() + 1));
      for(int t : tris) {
        const P3 &x0 = _v[_t[t].v[0]].x, &x1 = _v[_t[t].v[1]].x,
                 &x2 = _v[_t[t].v[2]].x;
        nrm = add(nrm, cross(sub(x1, x0), sub(x2, x0)));
      }
      if(!(norm(nrm) > 0.)) continue;
      const Chart C(c, unit(nrm));
      const std::size_t n = q.size();
      std::vector<std::array<double, 2> > pts(n + 1);
      pts[0] = C.uv(_v[s].x);
      for(std::size_t j = 0; j < n; j++) pts[j + 1] = C.uv(_v[q[j]].x);
      std::vector<bool> locked(n + 1, true);
      locked[0] = false;
      std::vector<std::array<uint32_t, 3> > T(n);
      const double h = nodeSize(s);
      const std::array<std::array<double, 2>, 3> equilateral = {
        {{{0., 0.}}, {{h, 0.}}, {{0.5 * h, 0.5 * std::sqrt(3.) * h}}}};
      std::vector<std::array<std::array<double, 2>, 3> > ideal(n,
                                                               equilateral);
      int negative = 0;
      for(std::size_t j = 0; j < n; j++) {
        T[j] = {0u, (uint32_t)(j + 1), (uint32_t)((j + 1) % n + 1)};
        if(o2(pts[0], pts[j + 1], pts[(j + 1) % n + 1]) <= 0.) negative++;
      }
      if(negative) continue; // (a star folded in its mean plane: left)
      WinslowUntangler::Options options;
      options.maxOuterIterations = 5;
      options.maxInnerIterations = 50;
      options.timeMax = 1.;
      WinslowUntangler::untangle2D(pts, locked, T, ideal, options);
      const P3 x = add(C.o, add(scale(C.e1, pts[0][0]), scale(C.e2, pts[0][1])));
      Location at = _v[s].at;
      P3 p;
      // (the node is on F: the nearest point is not farther than it)
      const double d0 = norm(sub(x, _v[s].x));
      if(!nearestOnF(x, std::min(2. * h, d0 + 1e-9 * h), at, p)) continue;
      // the star before and after
      const P3 np = normalAt(at);
      double before = 1e300, after = 1e300;
      bool flipped = false;
      for(std::size_t j = 0; j < n; j++) {
        const Node &a = _v[q[j]], &b = _v[q[(j + 1) % n]];
        before = std::min(before, gamma3(_v[s].x, a.x, b.x));
        after = std::min(after, gamma3(p, a.x, b.x));
        const P3 m = add(add(np, a.n), b.n);
        if(dot(cross(sub(a.x, p), sub(b.x, p)), m) <= 0.) flipped = true;
      }
      if(flipped || after < before) continue;
      _v[s].x = p;
      _v[s].at = at;
      _v[s].n = np;
      moved++;
    }
    const long f = flip();
    _flips += f;
    Msg::Debug("Surface %d: smoothing pass %d, %ld of %ld nodes moved, %ld "
               "flips",
               _gf->tag(), pass + 1, moved, tried, f);
  }
}

// the triangles against F (their normal more than 60 degrees from the normals
// of F at their nodes: folded, or standing across the surface where the
// front left a node on the other side of a turn of F) untangled: an edge of
// such a triangle flipped if that improves the worst of its two triangles
// (never a segment of the 1D mesh, never into an edge already there), a node
// of such a triangle moved if that improves the worst triangle of its star:
// to the point of F nearest to the one a local Winslow untangling gives in
// the plane of the normals of F at its neighbors (its star is folded, the
// mean plane of the smoothing is not that of the surface)
void Scaffold::untangle()
{
  const double bad = 0.5;
  std::vector<int> q, out, tris;
  bool boundary;
  long flipped = 0, moved = 0;
  for(int round = 0; round < 10; round++) {
    long f = 0, m = 0;
    for(int i = 0; i < (int)_t.size(); i++) {
      if(!_t[i].alive) continue;
      const double ai = agreement(i);
      if(ai >= bad) continue;
      int best = -1;
      double bestAgreement = -2.;
      for(int k = 0; k < 3; k++) {
        const int n = _t[i].nb[k];
        if(n < 0) continue;
        const int a = _t[i].v[k], b = _t[i].v[(k + 1) % 3],
                  c = _t[i].v[(k + 2) % 3];
        const int l = indexOf(n, b);
        const int d = _t[n].v[(l + 2) % 3];
        if(c == d || segmentEdge(a, b) || edgeTaken(c, d)) continue;
        const double before = std::min(ai, agreement(n));
        const double after =
          std::min(::agreement(_v[c].x, _v[a].x, _v[d].x,
                               add(add(_v[c].n, _v[a].n), _v[d].n)),
                   ::agreement(_v[d].x, _v[b].x, _v[c].x,
                               add(add(_v[d].n, _v[b].n), _v[c].n)));
        if(after > before + 1e-12 && after > bestAgreement) {
          best = k;
          bestAgreement = after;
        }
      }
      if(best >= 0) {
        flipEdge(i, best);
        f++;
      }
    }
    for(std::size_t si = 0; si < _v.size(); si++) {
      const int s = (int)si;
      if(!_v[s].alive || _v[s].scaffold || _v[s].boundary || _v[s].mv)
        continue;
      if(!star(s, q, out, tris, boundary) || boundary || q.size() < 3 ||
         q.size() != tris.size())
        continue;
      const std::size_t n = q.size();
      double worst = 1.;
      for(int t : tris) worst = std::min(worst, agreement(t));
      if(worst >= bad) continue;
      // the plane of the normals of F at its neighbors, through their
      // centroid
      P3 c = {0., 0., 0.}, nrm = {0., 0., 0.};
      for(int j : q) {
        c = add(c, _v[j].x);
        nrm = add(nrm, _v[j].n);
      }
      c = scale(c, 1. / (double)n);
      if(!(norm(nrm) > 0.)) continue;
      const Chart C(c, unit(nrm));
      std::vector<std::array<double, 2> > pts(n + 1);
      pts[0] = {0., 0.};
      for(std::size_t j = 0; j < n; j++) pts[j + 1] = C.uv(_v[q[j]].x);
      std::vector<bool> locked(n + 1, true);
      locked[0] = false;
      std::vector<std::array<uint32_t, 3> > T(n);
      const double h = nodeSize(s);
      const std::array<std::array<double, 2>, 3> equilateral = {
        {{{0., 0.}}, {{h, 0.}}, {{0.5 * h, 0.5 * std::sqrt(3.) * h}}}};
      std::vector<std::array<std::array<double, 2>, 3> > ideal(n,
                                                               equilateral);
      for(std::size_t j = 0; j < n; j++)
        T[j] = {0u, (uint32_t)(j + 1), (uint32_t)((j + 1) % n + 1)};
      WinslowUntangler::Options options;
      options.maxOuterIterations = 10;
      options.maxInnerIterations = 100;
      options.timeMax = 1.;
      WinslowUntangler::untangle2D(pts, locked, T, ideal, options);
      const P3 x = add(C.o, add(scale(C.e1, pts[0][0]), scale(C.e2, pts[0][1])));
      Location at = _v[s].at;
      P3 p;
      if(!nearestOnF(x, norm(sub(x, _v[s].x)) + 2. * h, at, p)) continue;
      const P3 np = normalAt(at);
      double after = 1.;
      for(std::size_t j = 0; j < n; j++) {
        const Node &a = _v[q[j]], &b = _v[q[(j + 1) % n]];
        after =
          std::min(after, ::agreement(p, a.x, b.x, add(add(np, a.n), b.n)));
      }
      if(!(after > worst + 1e-12)) continue;
      _v[s].x = p;
      _v[s].at = at;
      _v[s].n = np;
      for(int t : tris) setRadius(t);
      m++;
    }
    flipped += f;
    moved += m;
    if(!f && !m) break;
  }
  long left = 0;
  for(std::size_t i = 0; i < _t.size(); i++)
    if(_t[i].alive && agreement((int)i) < bad) left++;
  Msg::Debug("Surface %d: untangled, %ld flips, %ld nodes moved, %ld "
             "triangles left more than 60 degrees from F",
             _gf->tag(), flipped, moved, left);
}

void Scaffold::transfer()
{
  long scaffold = 0;
  for(Node &v : _v) {
    if(!v.alive || v.mv) continue;
    scaffold += v.scaffold;
    const SPoint2 uv = uvAt(v.at);
    v.mv = new MFaceVertex(v.x[0], v.x[1], v.x[2], _gf, uv.x(), uv.y());
    _gf->mesh_vertices.push_back(v.mv);
  }
  for(const Tri &t : _t)
    if(t.alive)
      _gf->triangles.push_back(
        new MTriangle(_v[t.v[0]].mv, _v[t.v[1]].mv, _v[t.v[2]].mv));
  if(scaffold)
    Msg::Warning("Surface %d: %ld nodes of its triangulation left in its mesh",
                 _gf->tag(), scaffold);
  // the triangles flat (no area, to the rounding) or folded (against the
  // normals of F at their nodes)
  long folded = 0, flat = 0;
  for(const Tri &t : _t) {
    if(!t.alive) continue;
    const Node &a = _v[t.v[0]], &b = _v[t.v[1]], &c = _v[t.v[2]];
    const P3 n = cross(sub(b.x, a.x), sub(c.x, a.x));
    const double l2 = std::max(dot(sub(b.x, a.x), sub(b.x, a.x)),
                               std::max(dot(sub(c.x, b.x), sub(c.x, b.x)),
                                        dot(sub(a.x, c.x), sub(a.x, c.x))));
    if(norm(n) <= 1e-12 * l2)
      flat++;
    else if(dot(n, add(add(a.n, b.n), c.n)) <= 0.) {
      folded++;
      if(Msg::GetVerbosity() > 98)
        Msg::Debug("Surface %d: folded triangle (%g %g %g) (%g %g %g) (%g %g "
                   "%g), nodes on the boundary %d %d %d, scaffold %d %d %d",
                   _gf->tag(), a.x[0], a.x[1], a.x[2], b.x[0], b.x[1], b.x[2],
                   c.x[0], c.x[1], c.x[2], (int)a.boundary, (int)b.boundary,
                   (int)c.boundary, (int)a.scaffold, (int)b.scaffold,
                   (int)c.scaffold);
    }
  }
  if(_forced)
    Msg::Warning("Surface %d: %ld nodes of its triangulation removed from its "
                 "boundary whatever the geometry (its 1D mesh crossing it), "
                 "%ld triangles folded, %ld flat",
                 _gf->tag(), _forced, folded, flat);
  else if(folded || flat)
    Msg::Warning("Surface %d: %ld triangles folded, %ld flat", _gf->tag(),
                 folded, flat);
  if(Msg::GetVerbosity() > 98) { // the layers of the front (debugging)
    char name[256];
    sprintf(name, "scaffold_layers_%d.txt", _gf->tag());
    FILE *fp = fopen(name, "w");
    for(const Tri &t : _t) {
      if(!t.alive) continue;
      for(int k = 0; k < 3; k++)
        fprintf(fp, "%g %g %g %d ", _v[t.v[k]].x[0], _v[t.v[k]].x[1],
                _v[t.v[k]].x[2], _v[t.v[k]].layer);
      fprintf(fp, "\n");
    }
    fclose(fp);
  }
}

bool Scaffold::mesh()
{
  const bool debug = Msg::GetVerbosity() > 98;
  auto trace = [&](const char *what) {
    if(debug)
      Msg::Debug("Surface %d: %s (%lu nodes, %lu triangles, %ld inserted, %ld "
                 "hidden, %ld removed, %ld flips, %ld failed)",
                 _gf->tag(), what, _v.size(), _t.size(), _inserted, _hidden,
                 _removed, _flips, _failed);
  };
  _extend1d = Extend1dMeshIn2dSurfaces(_gf);
  if(!buildBackground() || !collectBoundary() || !cutSeams()) return false;
  trace("F built and cut");
  if(debug)
    Msg::Debug("Surface %d: %lu seams, %ld bad adjacencies in F", _gf->tag(),
               _seams.size(), checkF());
  backgroundSizes();
  if(debug) {
    double a = 1e300, b = 0., c = 1e300, d = 0., e = 1e300, f = 0.;
    for(std::size_t i = 0; i < _x.size(); i++) {
      a = std::min(a, _s1[i]);
      b = std::max(b, _s1[i]);
      c = std::min(c, _sB[i]);
      d = std::max(d, _sB[i]);
    }
    for(double x : _bSize) {
      e = std::min(e, x);
      f = std::max(f, x);
    }
    Msg::Debug("Surface %d: sizes s1 %g %g, sB %g %g, 1D %g %g, extend %d",
               _gf->tag(), a, b, c, d, e, f, (int)_extend1d);
  }
  refineBackground();
  trace("F refined");
  if(debug)
    Msg::Debug("Surface %d: F refined to %lu nodes", _gf->tag(), _x.size());
  const long nF = (long)_x.size();
  if(!initialMesh()) return false;
  trace("initial mesh");
  if(debug) Msg::Debug("Surface %d: M %s", _gf->tag(), checkM().c_str());
  _flips += flip();
  trace("flipped");
  if(debug) {
    dump("F");
    dump("M_0");
  }
  if(debug) Msg::Debug("Surface %d: M %s", _gf->tag(), checkM().c_str());
  // the front, then the scaffold it left removed and the flips, again as long
  // as points are inserted: where the front failed next to the scaffold (no
  // circumcenter of a triangle of mesh nodes to stop the point at, too close
  // to the other side of a narrow face), the triangles of mesh nodes left by
  // the removal are those of the Frontal-Delaunay algorithm
  for(int round = 0; round < 10; round++) {
    const long inserted = _inserted;
    front();
    trace("front");
    if(debug) Msg::Debug("Surface %d: M %s", _gf->tag(), checkM().c_str());
    long left = 0;
    for(int pass = 0; pass < 5; pass++) {
      left = 0;
      for(std::size_t i = 0; i < _v.size(); i++) {
        if(!_v[i].alive || !_v[i].scaffold) continue;
        _trace = debug && pass == 4;
        const bool removed = removeNode((int)i);
        _trace = false;
        if(removed)
          _removed++;
        else {
          left++;
          if(debug && pass == 4) _rejects[std::string("removal: ") + _why]++;
        }
      }
      if(!left) break;
    }
    _flips += flip();
    if(_inserted == inserted) break;
    for(Tri &t : _t) // the points that failed tried again
      if(t.alive && t.r < 0.) setRadius((int)(&t - &_t[0]));
  }
  smooth(CTX::instance()->mesh.nbSmoothing);
  untangle();
  if(debug) dump("M_final");
  transfer();

  if(debug)
    for(auto &r : _rejects)
      Msg::Debug("Surface %d: %ld insertions failed: %s", _gf->tag(), r.second,
                 r.first.c_str());
  Msg::Debug("Surface %d: %ld nodes inserted, %ld nodes of its triangulation "
             "(%ld edges cut), %ld hidden by the insertions, %ld removed, "
             "%ld flips, %ld insertions failed, %ld cavities shrunk",
             _gf->tag(), _inserted, nF, _refined, _hidden, _removed, _flips,
             _failed, _shrunk);
  return true;
}

} // namespace

bool meshGFaceScaffold(GFace *gf)
{
  Scaffold s(gf);
  return s.mesh();
}
