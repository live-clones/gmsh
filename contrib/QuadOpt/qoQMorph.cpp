// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.

// Q-Morph: advancing fronts on an existing triangulation (Owen et al., 1999),
// with the nine front types and background optimization between layers of
// Wang et al. (2025), DOI: 10.1007/s00366-025-02196-y. Side/top recovery still
// uses the classical triangle transformations, not all the paper's templates.
// Sides are selected, swapped or split; the top edge is recovered by flips; the
// enclosed triangle cavity is replaced by a quadrangle. Only the fronts live
// here: import, geometry and export are FaceMesh (qoFace.h), and the remaining
// triangles are paired and optimized by the optimizer (qoOptimizer.cpp).

#include "qoQMorph.h"
#include "qoFace.h"
#include "qoOptimizer.h"
#include "GEdge.h"
#include "GFace.h"
#include "GModel.h"
#include "GRegion.h"
#include "GmshMessage.h"
#include "SVector3.h"
#include <limits>
#include <map>
#include <set>

namespace QuadOpt {

  // The one class allowed to edit a FaceMesh, besides the optimizer.
  class FrontAdvance {
    using Key = std::uint64_t;
    using Vert = FaceMesh::Vert;
    static constexpr double pi = 3.14159265358979323846;
    static constexpr double kMinQuadQuality = 0.15;
    static constexpr double kMaxQuadWarping = 45.; // degrees
    static constexpr double kMaxQuadDeviation = 0.1; // centroid to CAD / edge

    struct Fan {
      std::vector<int> neighbor;
      double angle = 0.;
    };
    struct Front {
      int a, b, priority;
      double length;
      bool operator<(const Front &other) const
      {
        if(priority != other.priority) return priority < other.priority;
        if(length != other.length) return length < other.length;
        if(a != other.a) return a < other.a;
        return b < other.b;
      }
    };
    // Only active triangles are changed during front construction. Restoring a
    // transaction appends the saved cells; front entries use directed edge
    // keys, never cell ids, so HalfEdgeMesh's append-only ids remain valid.
    struct Edit {
      std::size_t firstCell, firstVertex;
      std::map<int, Cell> saved;
      std::set<int> touched;
      std::size_t splits = 0;
    };

    FaceMesh &_m;
    HalfEdgeMesh &_he;
    std::vector<Vert> &_v;
    Relaxer &_relax; // the optimizer: smoothing and re-meshing of cells
    std::vector<char> _terminal; // triangles left as they are
    // Only edges present at the start of this layer enter the queue. New fronts
    // wait until every surviving edge of this layer is consumed.
    std::set<Front> _queue;
    std::map<Key, Front> _pending;
    std::set<int> _dirty; // vertices changed since the last background pass
    std::size_t _initial = 0, _active = 0, _morphed = 0, _splits = 0;

    static int frontType(double angle)
    {
      return angle < .75 * pi ? 1 : (angle <= 1.25 * pi ? 0 : 2);
    }
    static Cell triangle(int a, int b, int c)
    {
      Cell t;
      t.n = 3;
      t.v = {{a, b, c, -1}};
      return t;
    }
    static Cell quadrangle(int a, int b, int c, int d)
    {
      Cell q;
      q.n = 4;
      q.v = {{a, b, c, d}};
      return q;
    }
    bool active(int c) const
    {
      return c >= 0 && _he.cells[c].alive && _he.cells[c].n == 3 &&
             !_terminal[c];
    }
    void grow() { _terminal.resize(_he.cells.size(), false); }
    bool protectedEdge(int a, int b) const
    {
      return _m._protected.count(FaceMesh::edgeKey(a, b));
    }
    bool front(int a, int b) const
    {
      return active(_he.cellAt(a, b)) &&
             (protectedEdge(a, b) || !active(_he.cellAt(b, a)));
    }
    SVector3 normalOf(const Cell &c) const
    {
      const Corners p = _m.pointsOf(c);
      return areaNormal(p.data(), c.n);
    }
    int opposite(int c, int a, int b) const
    {
      if(c < 0 || _he.cells[c].n != 3) return -1;
      for(int i = 0; i < 3; ++i)
        if(_he.cells[c].v[i] != a && _he.cells[c].v[i] != b)
          return _he.cells[c].v[i];
      return -1;
    }

    Fan fan(int origin, int first, bool ccw) const;
    void enqueue(int a, int b, bool newLayer = false);
    void update(const std::set<int> &vertices);
    bool replace(Edit &edit, const std::vector<int> &old,
                 const std::vector<Cell> &fresh, std::vector<int> &ids);
    void rollback(Edit &edit);
    bool flip(Edit &edit, int a, int b, const std::set<Key> &locked);
    int side(Edit &edit, int origin, int first, bool ccw, const SVector3 &normal,
             double h, const std::set<Key> &locked);
    bool crossing(int a, int b, int c, int d, const SVector3 &normal) const;
    bool corridor(int a, int b, const SVector3 &normal,
                  const std::set<Key> &locked,
                  std::vector<std::pair<int, int> > &edges) const;
    bool recover(Edit &edit, int a, int b, const SVector3 &normal,
                 const std::set<Key> &locked);
    bool cavity(int base, const Cell &quad, std::vector<int> &cells) const;
    bool morph(const Front &f);
    bool pair(int c);
    void finishTriangle(int c);
    void optimizeBackground();

  public:
    FrontAdvance(FaceMesh &mesh, Relaxer &relaxer)
      : _m(mesh), _he(mesh._he), _v(mesh._v), _relax(relaxer)
    {
      grow();
      for(const Cell &c : _he.cells) _active += c.alive && c.n == 3;
      _initial = _active;
    }
    void run();
  };

  FrontAdvance::Fan FrontAdvance::fan(int origin, int first, bool ccw) const
  {
    Fan result;
    result.neighbor.push_back(first);
    int c = ccw ? _he.cellAt(origin, first) : _he.cellAt(first, origin);
    for(std::size_t k = 0; active(c) && k <= _he.star[origin].size(); ++k) {
      const Cell &cell = _he.cells[c];
      int i = 0;
      while(i < 3 && cell.v[i] != origin) ++i;
      if(i == 3) break;
      const int next = cell.v[(i + (ccw ? 2 : 1)) % 3];
      result.angle += angle(_v[result.neighbor.back()].p - _v[origin].p,
                            _v[next].p - _v[origin].p);
      result.neighbor.push_back(next);
      if(next == first || protectedEdge(origin, next)) break;
      c = ccw ? _he.cellAt(origin, next) : _he.cellAt(next, origin);
    }
    return result;
  }

  void FrontAdvance::enqueue(int a, int b, bool newLayer)
  {
    const Key key = HalfEdgeMesh::key(a, b);
    auto old = _pending.find(key);
    if(old == _pending.end() && !newLayer) return;
    if(old != _pending.end()) {
      _queue.erase(old->second);
      _pending.erase(old);
    }
    if(!front(a, b)) return;
    // Rows/columns are endpoint types 0, 1, 2. Priority order (paper §2.2):
    // 1-1, 1-0, 0-1, 1-2, 2-1, 0-0, 2-0, 0-2, 2-2.
    static const int priority[3][3] = {{5, 2, 7}, {1, 0, 3}, {6, 4, 8}};
    const int aType = frontType(fan(a, b, true).angle);
    const int bType = frontType(fan(b, a, false).angle);
    const Front f = {a, b, priority[aType][bType], (_v[b].p - _v[a].p).norm()};
    _queue.insert(f);
    _pending.emplace(key, f);
  }

  void FrontAdvance::update(const std::set<int> &vertices)
  {
    std::set<std::pair<int, int> > edges;
    for(int v : vertices) {
      if(v >= int(_v.size())) continue;
      for(int c : _he.star[v])
        for(int i = 0; i < _he.cells[c].n; ++i) {
          const int a = _he.cells[c].v[i], b = _he.next(_he.cells[c], i);
          edges.emplace(a, b);
          edges.emplace(b, a);
        }
    }
    for(const auto &e : edges) enqueue(e.first, e.second);
  }

  bool FrontAdvance::replace(Edit &edit, const std::vector<int> &old,
                             const std::vector<Cell> &fresh,
                             std::vector<int> &ids)
  {
    // Preflight: HalfEdgeMesh::replace's failure rollback changes cell ids.
    // Reject conflicts before editing so our transaction sees every change.
    std::set<Key> owners;
    for(const Cell &c : fresh)
      for(int i = 0; i < c.n; ++i) {
        const int a = c.v[i], b = _he.next(c, i);
        const int owner = _he.cellAt(a, b);
        if(!owners.insert(HalfEdgeMesh::key(a, b)).second ||
           (owner >= 0 && std::find(old.begin(), old.end(), owner) == old.end()))
          return false;
      }
    for(int c : old) {
      if(!active(c)) return false;
      if(std::size_t(c) < edit.firstCell) edit.saved.emplace(c, _he.cells[c]);
      for(int i = 0; i < _he.cells[c].n; ++i)
        edit.touched.insert(_he.cells[c].v[i]);
    }
    if(!_he.replace(old, fresh, ids)) return false;
    _active -= old.size();
    grow();
    for(int c : ids) {
      _active += _he.cells[c].n == 3;
      for(int i = 0; i < _he.cells[c].n; ++i)
        edit.touched.insert(_he.cells[c].v[i]);
    }
    return true;
  }

  void FrontAdvance::rollback(Edit &edit)
  {
    for(std::size_t c = edit.firstCell; c < _he.cells.size(); ++c)
      if(_he.cells[c].alive) {
        _active -= active(int(c));
        _he.remove(int(c));
      }
    for(const auto &saved : edit.saved) {
      _he.add(saved.second);
      ++_active;
    }
    _v.resize(edit.firstVertex);
    _he.star.resize(edit.firstVertex);
    grow();
  }

  bool FrontAdvance::flip(Edit &edit, int a, int b, const std::set<Key> &locked)
  {
    const int left = _he.cellAt(a, b), right = _he.cellAt(b, a);
    if(!active(left) || !active(right) || protectedEdge(a, b) ||
       locked.count(FaceMesh::edgeKey(a, b)))
      return false;
    const int c = opposite(left, a, b), d = opposite(right, a, b);
    if(c == d || c < 0 || d < 0 || _he.cellAt(c, d) >= 0 || _he.cellAt(d, c) >= 0)
      return false;
    const Cell t0 = triangle(c, d, b), t1 = triangle(d, c, a);
    const SVector3 normal = normalOf(_he.cells[left]) + normalOf(_he.cells[right]);
    if(_m.fit(t0) <= 1.e-5 || _m.fit(t1) <= 1.e-5 ||
       dot(normalOf(t0), normal) <= 0. || dot(normalOf(t1), normal) <= 0.)
      return false;
    std::vector<int> ids;
    return replace(edit, {left, right}, {t0, t1}, ids);
  }

  int FrontAdvance::side(Edit &edit, int origin, int first, bool ccw,
                         const SVector3 &normal, double h,
                         const std::set<Key> &locked)
  {
    const Fan f = fan(origin, first, ccw);
    if(f.neighbor.size() < 2) return -1;
    if(frontType(f.angle) == 1) return f.neighbor.back();
    SVector3 x = _v[first].p - _v[origin].p;
    x -= normal * dot(x, normal);
    if(!(x.norm() > 0.)) return -1;
    x.normalize();
    const SVector3 y = crossprod(normal, x) * (ccw ? 1. : -1.);
    const double theta = frontType(f.angle) == 2 ? .5 * pi : .5 * f.angle;
    const SVector3 direction = x * std::cos(theta) + y * std::sin(theta);
    int best = -1;
    double deviation = pi;
    for(std::size_t i = 1; i < f.neighbor.size(); ++i) {
      const int v = f.neighbor[i];
      const SVector3 d = _v[v].p - _v[origin].p;
      const double a = angle(direction, d);
      if(a < deviation && d.norm() >= .35 * h && d.norm() <= 2. * h)
        best = v, deviation = a;
    }
    if(deviation < pi / 6.) return best;

    // The ray intersects the opposite edge of one triangle in this sector.
    for(std::size_t i = 1; i < f.neighbor.size(); ++i) {
      const int a = f.neighbor[i - 1], b = f.neighbor[i];
      const SVector3 p = _v[a].p - _v[origin].p, edge = _v[b].p - _v[a].p;
      const double denominator = dot(crossprod(direction, edge), normal);
      if(std::abs(denominator) < 1.e-12 * h) continue;
      const double s = dot(crossprod(p, direction), normal) / denominator;
      const double t = dot(crossprod(p, edge), normal) / denominator;
      if(s <= .05 || s >= .95 || t <= .2 * h || t > 2. * h) continue;
      const int left = _he.cellAt(a, b), right = _he.cellAt(b, a);
      if(!active(left) || !active(right) || protectedEdge(a, b) ||
         locked.count(FaceMesh::edgeKey(a, b)))
        continue;
      int v = opposite(left, a, b);
      if(v == origin) v = opposite(right, a, b);
      const SVector3 d = _v[v].p - _v[origin].p;
      if(angle(direction, d) < pi / 6. && d.norm() < 2. * h &&
         flip(edit, a, b, locked))
        return v;
      if(_splits + edit.splits >= _initial) return -1;
      // Split the edge at the ray, on the CAD.
      const SVector3 target = _v[a].p + edge * s;
      SVector3 point;
      double uv[2];
      if(!_m.project(target, _v[origin].hasUV ? _v[origin].uv : nullptr, point,
                     uv) ||
         (point - target).norm() > .15 * h)
        return -1;
      const int w = _m.addVertex(point, uv);
      const int c = opposite(left, a, b), d0 = opposite(right, a, b);
      const std::vector<Cell> fresh = {triangle(a, w, c), triangle(w, b, c),
                                       triangle(b, w, d0), triangle(w, a, d0)};
      bool good = true;
      for(const Cell &cell : fresh) good = good && _m.fit(cell) > 1.e-5;
      std::vector<int> ids;
      if(!good || !replace(edit, {left, right}, fresh, ids)) return -1;
      ++edit.splits;
      return w;
    }
    return -1;
  }

  bool FrontAdvance::crossing(int a, int b, int c, int d,
                              const SVector3 &normal) const
  {
    if(a == c || a == d || b == c || b == d) return false;
    auto orient = [&](int x, int y, int z) {
      return dot(crossprod(_v[y].p - _v[x].p, _v[z].p - _v[x].p), normal);
    };
    const double scale = (_v[b].p - _v[a].p).norm() * (_v[d].p - _v[c].p).norm();
    const double tolerance = 1.e-12 * scale;
    const double ac = orient(a, b, c), ad = orient(a, b, d);
    const double ca = orient(c, d, a), cb = orient(c, d, b);
    return std::min(ac, ad) < -tolerance && std::max(ac, ad) > tolerance &&
           std::min(ca, cb) < -tolerance && std::max(ca, cb) > tolerance;
  }

  bool FrontAdvance::corridor(int a, int b, const SVector3 &normal,
                              const std::set<Key> &locked,
                              std::vector<std::pair<int, int> > &edges) const
  {
    edges.clear();
    int current = -1;
    for(int c : _he.star[a]) {
      if(!active(c)) continue;
      const Cell &cell = _he.cells[c];
      for(int i = 0; i < 3; ++i)
        if(crossing(a, b, cell.v[i], _he.next(cell, i), normal)) current = c;
      if(current >= 0) break;
    }
    if(current < 0) return false;
    std::set<int> visited;
    Key entered = std::numeric_limits<Key>::max();
    while(active(current) && visited.insert(current).second &&
          visited.size() < 256) {
      const Cell &cell = _he.cells[current];
      for(int i = 0; i < 3; ++i)
        if(cell.v[i] == b) return true;
      int next = -1;
      for(int i = 0; i < 3; ++i) {
        const int c = cell.v[i], d = _he.next(cell, i);
        const Key key = FaceMesh::edgeKey(c, d);
        if(key == entered || !crossing(a, b, c, d, normal)) continue;
        if(protectedEdge(c, d) || locked.count(key)) return false;
        next = _he.cellAt(d, c);
        if(!active(next)) return false;
        edges.emplace_back(c, d);
        entered = key;
        break;
      }
      if(next < 0) return false;
      current = next;
    }
    return false;
  }

  bool FrontAdvance::recover(Edit &edit, int a, int b, const SVector3 &normal,
                             const std::set<Key> &locked)
  {
    std::vector<std::pair<int, int> > edges;
    std::set<Key> postponed;
    for(int iteration = 0; iteration < 256; ++iteration) {
      if(_he.cellAt(a, b) >= 0) return true;
      if(!corridor(a, b, normal, locked, edges)) return false;
      bool changed = false;
      // Prefer flips that remove an intersection. A necessary temporary
      // intersecting diagonal is postponed before being considered again.
      for(int pass = 0; pass < 2 && !changed; ++pass)
        for(const auto &edge : edges) {
          const int c = opposite(_he.cellAt(edge.first, edge.second), edge.first,
                                 edge.second);
          const int d = opposite(_he.cellAt(edge.second, edge.first), edge.first,
                                 edge.second);
          if(c < 0 || d < 0) continue;
          const bool intersects = crossing(a, b, c, d, normal);
          if(pass == 0 && intersects) continue;
          if(pass == 1 && postponed.count(FaceMesh::edgeKey(edge.first, edge.second)))
            continue;
          if(flip(edit, edge.first, edge.second, locked)) {
            if(intersects) postponed.insert(FaceMesh::edgeKey(c, d));
            changed = true;
            break;
          }
        }
      if(!changed) return false;
    }
    return false;
  }

  // The triangles enclosed by the quadrangle, if they form one closed cavity.
  bool FrontAdvance::cavity(int base, const Cell &quad,
                            std::vector<int> &cells) const
  {
    std::set<Key> boundary;
    for(int i = 0; i < 4; ++i)
      boundary.insert(FaceMesh::edgeKey(quad.v[i], _he.next(quad, i)));
    std::set<int> visited;
    cells.assign(1, base);
    visited.insert(base);
    for(std::size_t k = 0; k < cells.size(); ++k) {
      if(cells.size() > 256 || !active(cells[k])) return false;
      const Cell &cell = _he.cells[cells[k]];
      for(int i = 0; i < 3; ++i) {
        const int a = cell.v[i], b = _he.next(cell, i);
        if(boundary.count(FaceMesh::edgeKey(a, b))) continue;
        if(protectedEdge(a, b)) return false;
        const int next = _he.cellAt(b, a);
        if(!active(next)) return false;
        if(visited.insert(next).second) cells.push_back(next);
      }
    }
    std::vector<int> loop;
    if(!_he.loop(cells, loop) || loop.size() != 4) return false;
    auto start = std::find(loop.begin(), loop.end(), quad.v[0]);
    if(start == loop.end()) return false;
    const int offset = int(start - loop.begin());
    for(int i = 0; i < 4; ++i)
      if(loop[(offset + i) % 4] != quad.v[i]) return false;
    for(int c : cells)
      for(int i = 0; i < 3; ++i) {
        const int v = _he.cells[c].v[i];
        if(std::find(loop.begin(), loop.end(), v) != loop.end()) continue;
        if(_v[v].fixed) return false;
        for(int incident : _he.star[v])
          if(!visited.count(incident)) return false;
      }
    return true;
  }

  bool FrontAdvance::morph(const Front &f)
  {
    Edit edit;
    edit.firstCell = _he.cells.size(), edit.firstVertex = _v.size();
    const bool done = [&]() {
      const int base = _he.cellAt(f.a, f.b);
      if(!active(base)) return false;
      SVector3 normal = normalOf(_he.cells[base]);
      if(!(normal.norm() > 0.)) return false;
      normal.normalize();
      std::set<Key> locked = {FaceMesh::edgeKey(f.a, f.b)};
      const int left = side(edit, f.a, f.b, true, normal, f.length, locked);
      if(left < 0 || left == f.b) return false;
      locked.insert(FaceMesh::edgeKey(f.a, left));
      const int right = side(edit, f.b, f.a, false, normal, f.length, locked);
      if(right < 0 || right == f.a || right == left) return false;
      locked.insert(FaceMesh::edgeKey(f.b, right));
      const Cell quad = quadrangle(f.a, f.b, right, left);
      const Corners p = _m.pointsOf(quad);
      if(_m.fit(quad) < kMinQuadQuality || warping(p.data()) > kMaxQuadWarping ||
         _m.deviation(quad) > kMaxQuadDeviation)
        return false;
      if(!recover(edit, right, left, normal, locked)) return false;
      std::vector<int> cells, ids;
      return cavity(_he.cellAt(f.a, f.b), quad, cells) &&
             replace(edit, cells, {quad}, ids);
    }();
    if(!done)
      rollback(edit);
    else {
      _splits += edit.splits;
      ++_morphed;
      _dirty.insert(edit.touched.begin(), edit.touched.end());
    }
    update(edit.touched);
    return done;
  }

  // A front triangle that cannot advance is merged with a neighbor, if the
  // optimizer finds a better arrangement for the pair.
  bool FrontAdvance::pair(int c)
  {
    for(int i = 0; i < 3; ++i) {
      const int a = _he.cells[c].v[i], b = _he.next(_he.cells[c], i);
      const int d = _he.cellAt(b, a);
      const std::size_t first = _he.cells.size();
      if(!active(d) || protectedEdge(a, b) || !_relax.rewrite({c, d})) continue;
      _active -= 2;
      grow();
      std::set<int> touched;
      for(std::size_t k = first; k < _he.cells.size(); ++k)
        if(_he.cells[k].alive) {
          _active += active(int(k));
          touched.insert(_he.cells[k].v.begin(),
                         _he.cells[k].v.begin() + _he.cells[k].n);
        }
      update(touched);
      _dirty.insert(touched.begin(), touched.end());
      return true;
    }
    return false;
  }

  void FrontAdvance::finishTriangle(int c)
  {
    if(!active(c)) return;
    _terminal[c] = true;
    --_active;
    const Cell cell = _he.cells[c];
    update(std::set<int>(cell.v.begin(), cell.v.begin() + 3));
  }

  // Between two layers no front is processed: flip the triangles that changed
  // for quality and relax their vertices, so that a thin triangle at the new
  // front cannot stay trapped forever. Only the changed region is visited.
  void FrontAdvance::optimizeBackground()
  {
    for(int pass = 0; pass < 2 && !_dirty.empty(); ++pass) {
      const std::set<int> work = _dirty;
      _dirty.clear();
      for(int w : work) {
        if(w >= int(_v.size())) continue;
        const std::vector<int> star = _he.star[w];
        for(int id : star)
          for(int i = 0; i < 3 && active(id); ++i) {
            const Cell cell = _he.cells[id];
            const int a = cell.v[i], b = _he.next(cell, i);
            const int other = _he.cellAt(b, a);
            if(!active(other) || protectedEdge(a, b)) continue;
            const int c = opposite(id, a, b), d = opposite(other, a, b);
            if(!(std::min(_m.fit(triangle(c, d, b)), _m.fit(triangle(d, c, a))) >
                 std::min(_m.fit(cell), _m.fit(_he.cells[other])) + 1.e-6))
              continue;
            Edit edit;
            edit.firstCell = _he.cells.size(), edit.firstVertex = _v.size();
            if(flip(edit, a, b, {}))
              _dirty.insert(edit.touched.begin(), edit.touched.end());
            else
              rollback(edit);
          }
      }
      for(int w : work) {
        if(w >= int(_v.size())) continue;
        bool background = false;
        for(int c : _he.star[w]) background = background || active(c);
        if(background && _relax.smooth(w)) _dirty.insert(w);
      }
    }
  }

  void FrontAdvance::run()
  {
    std::size_t steps = 0;
    const std::size_t limit = 4 * _initial + 16;
    while(_active && steps < limit) {
      // Snapshot all remaining contours, including both sides of embedded
      // curves. update() may reprioritize these edges, but cannot add the next
      // layer. Directed keys survive rollback's changes to cell ids.
      _queue.clear();
      _pending.clear();
      for(int c = 0; c < int(_he.cells.size()); ++c)
        if(active(c))
          for(int i = 0; i < 3; ++i)
            enqueue(_he.cells[c].v[i], _he.next(_he.cells[c], i), true);
      if(_queue.empty()) {
        // Closed surfaces (or disconnected closed components) need a seed.
        int seed = -1;
        for(int c = 0; c < int(_he.cells.size()) && seed < 0; ++c)
          if(active(c)) seed = c;
        if(seed < 0) break;
        ++steps;
        if(!pair(seed)) finishTriangle(seed);
        continue;
      }
      while(!_queue.empty() && steps < limit) {
        const Front f = *_queue.begin();
        _queue.erase(_queue.begin());
        _pending.erase(HalfEdgeMesh::key(f.a, f.b));
        if(!front(f.a, f.b)) continue;
        ++steps;
        if(!morph(f)) {
          const int c = _he.cellAt(f.a, f.b);
          if(!pair(c)) finishTriangle(c);
        }
      }
      _queue.clear();
      _pending.clear();
      optimizeBackground();
    }
    for(int c = 0; c < int(_he.cells.size()); ++c) finishTriangle(c);
    Msg::Debug("Q-Morph: %zu quadrangles from fronts, %zu edge splits", _morphed,
               _splits);
  }

  void advanceFronts(FaceMesh &mesh, Relaxer &relaxer)
  {
    FrontAdvance(mesh, relaxer).run();
  }

  namespace {
    bool supported(GFace *face)
    {
      auto refuse = [&](const char *reason) {
        Msg::Warning("Q-Morph: face %d left unchanged (%s)", face->tag(), reason);
        return false;
      };
      if(!face->polygons.empty()) return refuse("polygonal elements");
      if(!face->quadrangles.empty()) return refuse("expected a pure triangulation");
      if(face->model()->getNumPartitions() ||
         !face->model()->getGhostCells().empty())
        return refuse("partitioned mesh");
      for(GRegion *region : face->regions())
        if(region->getNumMeshElements())
          return refuse("adjacent volume is already meshed");
      for(GRegion *region : face->model()->getRegions()) {
        if(!region->getNumMeshElements()) continue;
        const auto &embedded = region->embeddedFaces();
        if(std::find(embedded.begin(), embedded.end(), face) != embedded.end())
          return refuse("embedded in an already meshed volume");
      }
      if(face->getMeshMaster() != face) return refuse("periodic mesh slave");
      for(GFace *other : face->model()->getFaces())
        if(other != face && other->getMeshMaster() == face)
          return refuse("periodic mesh master");
      return true;
    }
  } // namespace

  bool qMorph(GFace *face)
  {
    if(!face) return false;
    if(face->triangles.empty() && face->quadrangles.empty() &&
       face->polygons.empty())
      return true;
    if(!supported(face)) return false;
    struct CurrentModelScope {
      GModel *saved;
      explicit CurrentModelScope(GModel *model) : saved(GModel::current())
      {
        GModel::setCurrent(model);
      }
      ~CurrentModelScope() { GModel::setCurrent(saved); }
    } current(face->model());
    return optimizeFace(face, true);
  }

  bool qMorph(GModel *model)
  {
    if(!model) return false;
    bool success = true;
    for(GFace *face : model->getFaces()) {
      if(face->triangles.empty() && face->polygons.empty()) continue;
      if(!qMorph(face)) success = false;
    }
    model->deleteVertexArrays();
    return success;
  }

} // namespace QuadOpt
