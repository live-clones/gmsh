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

#include <algorithm>
#include <array>
#include <cfloat>
#include <cmath>
#include <cstdint>
#include <deque>
#include <map>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include "DiscreteCADArrangement.h"
#include "robustPredicates.h"

namespace {

  // exact arithmetic: expansions (Shewchuk), sums of nonoverlapping
  // components by increasing magnitude, of the sign of the last one, with
  // the routines of gmsh's robust predicates

  typedef std::vector<double> Expansion;

  inline int sign(double a) { return a > 0. ? 1 : a < 0. ? -1 : 0; }

  inline int sign(const Expansion &e) { return sign(e.back()); }

  // the same value with as few components as possible (Shewchuk's compress)
  Expansion compress(const Expansion &e)
  {
    const int n = (int)e.size();
    if(n < 2) return e;
    Expansion h(n);
    int bottom = n - 1;
    double Q = e[bottom];
    for(int i = n - 2; i >= 0; i--) {
      const double enow = e[i], Qnew = Q + enow, bvirt = Qnew - Q,
                   q = enow - bvirt;
      if(q != 0.) {
        h[bottom--] = Qnew;
        Q = q;
      }
      else
        Q = Qnew;
    }
    int top = 0;
    for(int i = bottom + 1; i < n; i++) {
      const double hnow = h[i], Qnew = hnow + Q, bvirt = Qnew - hnow,
                   q = Q - bvirt;
      if(q != 0.) h[top++] = q;
      Q = Qnew;
    }
    h[top] = Q;
    h.resize(top + 1);
    return h;
  }

  Expansion sum(const Expansion &e, const Expansion &f)
  {
    Expansion h(e.size() + f.size());
    h.resize(robustPredicates::fast_expansion_sum_zeroelim(
      (int)e.size(), e.data(), (int)f.size(), f.data(), h.data()));
    return h;
  }

  Expansion sub(const Expansion &e, const Expansion &f)
  {
    Expansion m = f;
    for(double &c : m) c = -c;
    return sum(e, m);
  }

  // e b
  Expansion scale(const Expansion &e, double b)
  {
    Expansion h(2 * e.size());
    h.resize(robustPredicates::scale_expansion_zeroelim((int)e.size(),
                                                        e.data(), b, h.data()));
    return h;
  }

  Expansion product(const Expansion &e, const Expansion &f)
  {
    Expansion h(1, 0.);
    for(double c : f) h = sum(h, scale(e, c));
    return compress(h);
  }

  // an approximation (within an ulp of a compressed expansion)
  double estimate(const Expansion &e)
  {
    double s = 0.;
    for(double c : e) s += c;
    return s;
  }

  // a value with a bound of its error

  struct Approx {
    double v, e;
  };

  const double unit = 1.1102230246251565e-16 * 1.01;

  inline Approx exact(double a) { return {a, 0.}; }

  inline Approx operator+(Approx a, Approx b)
  {
    const double v = a.v + b.v;
    return {v, a.e + b.e + unit * std::abs(v)};
  }

  inline Approx operator-(Approx a, Approx b)
  {
    const double v = a.v - b.v;
    return {v, a.e + b.e + unit * std::abs(v)};
  }

  inline Approx operator*(Approx a, Approx b)
  {
    const double v = a.v * b.v;
    return {v, std::abs(a.v) * b.e + std::abs(b.v) * a.e + a.e * b.e +
                 unit * std::abs(v)};
  }

  inline bool certain(Approx a) { return std::abs(a.v) > a.e * (1. + 1.e-8); }

  // the orientations of input points: orient3d positive if d is below the
  // plane of a, b, c (seen counterclockwise from above), orient2d positive if
  // a, b, c are counterclockwise in the projection along the axis k, i.e. on
  // the axes k + 1, k + 2 (that of positive normals along k): the exact signs
  // and values of gmsh's robust predicates (orient3d without the static filter
  // that depends on the coordinate ranges given to exactinit)

  inline int orient3d(const double *a, const double *b, const double *c,
                      const double *d)
  {
    return sign(robustPredicates::orient3dDynamic(a, b, c, d));
  }

  Expansion orient3dExact(const double *a, const double *b, const double *c,
                          const double *d)
  {
    Expansion h(96);
    h.resize(robustPredicates::orient3dExact(a, b, c, d, h.data()));
    return h;
  }

  inline int orient2d(const double *a, const double *b, const double *c, int k)
  {
    const int i = (k + 1) % 3, j = (k + 2) % 3;
    const double A[2] = {a[i], a[j]}, B[2] = {b[i], b[j]}, C[2] = {c[i], c[j]};
    return sign(robustPredicates::orient2d(A, B, C));
  }

  Expansion orient2dExact(const double *a, const double *b, const double *c,
                          int k)
  {
    const int i = (k + 1) % 3, j = (k + 2) % 3;
    const double A[2] = {a[i], a[j]}, B[2] = {b[i], b[j]}, C[2] = {c[i], c[j]};
    Expansion h(12);
    h.resize(robustPredicates::orient2dExact(A, B, C, h.data()));
    return h;
  }

  // a bounding volume hierarchy of boxes
  class BoxTree {
    struct Node {
      double lo[3], hi[3];
      int left, right, first, count;
    };
    std::vector<Node> _nodes;
    std::vector<int> _items;
    const std::vector<std::array<double, 6> > *_boxes = nullptr;
    int _build(int first, int count)
    {
      Node n;
      for(int k = 0; k < 3; k++) {
        n.lo[k] = 1e300;
        n.hi[k] = -1e300;
      }
      double clo[3] = {1e300, 1e300, 1e300}, chi[3] = {-1e300, -1e300, -1e300};
      for(int i = first; i < first + count; i++) {
        const std::array<double, 6> &b = (*_boxes)[_items[i]];
        for(int k = 0; k < 3; k++) {
          n.lo[k] = std::min(n.lo[k], b[k]);
          n.hi[k] = std::max(n.hi[k], b[3 + k]);
          const double c = b[k] + b[3 + k];
          clo[k] = std::min(clo[k], c);
          chi[k] = std::max(chi[k], c);
        }
      }
      n.first = first;
      n.count = count;
      n.left = n.right = -1;
      const int id = (int)_nodes.size();
      _nodes.push_back(n);
      if(count <= 4) return id;
      int axis = 0;
      for(int k = 1; k < 3; k++)
        if(chi[k] - clo[k] > chi[axis] - clo[axis]) axis = k;
      const int half = count / 2;
      std::nth_element(_items.begin() + first, _items.begin() + first + half,
                       _items.begin() + first + count, [&](int a, int b) {
                         const std::array<double, 6> &u = (*_boxes)[a],
                                                     &v = (*_boxes)[b];
                         return u[axis] + u[3 + axis] < v[axis] + v[3 + axis];
                       });
      const int left = _build(first, half);
      const int right = _build(first + half, count - half);
      _nodes[id].left = left;
      _nodes[id].right = right;
      return id;
    }

  public:
    void build(const std::vector<std::array<double, 6> > &boxes,
               const std::vector<int> &items)
    {
      _boxes = &boxes;
      _items = items;
      _nodes.clear();
      if(!_items.empty()) _build(0, (int)_items.size());
    }
    template <class F> void query(const std::array<double, 6> &b, F f) const
    {
      if(_nodes.empty()) return;
      int stack[128], n = 0;
      stack[n++] = 0;
      while(n) {
        const Node &node = _nodes[stack[--n]];
        bool overlap = true;
        for(int k = 0; k < 3 && overlap; k++)
          if(node.lo[k] > b[3 + k] || node.hi[k] < b[k]) overlap = false;
        if(!overlap) continue;
        if(node.left < 0) {
          for(int i = node.first; i < node.first + node.count; i++) {
            const std::array<double, 6> &c = (*_boxes)[_items[i]];
            bool o = true;
            for(int k = 0; k < 3 && o; k++)
              if(c[k] > b[3 + k] || c[3 + k] < b[k]) o = false;
            if(o) f(_items[i]);
          }
        }
        else {
          stack[n++] = node.left;
          stack[n++] = node.right;
        }
      }
    }
  };

  // the winding numbers of the inputs in a cell: (input, winding number not
  // 0), by increasing input
  typedef std::vector<std::pair<int, int> > Winding;

  // w + s m
  Winding combined(const Winding &w, const Winding &m, int s)
  {
    Winding r;
    std::size_t i = 0, j = 0;
    while(i < w.size() || j < m.size()) {
      if(j == m.size() || (i < w.size() && w[i].first < m[j].first))
        r.push_back(w[i++]);
      else if(i == w.size() || m[j].first < w[i].first) {
        r.push_back({m[j].first, s * m[j].second});
        j++;
      }
      else {
        const int v = w[i].second + s * m[j].second;
        if(v) r.push_back({w[i].first, v});
        i++;
        j++;
      }
    }
    return r;
  }

  // The arrangement of triangles: all of them cut where they meet, exactly.
  // The points where they meet (on lines through two input vertices and
  // planes through three, on two lines in a plane, on three planes) are kept
  // implicit, by the input points defining them: their coordinates rounded
  // with a bound of their error decide the predicates when they can,
  // expansions decide them exactly otherwise; points at the same place are
  // one. Each triangle is cut by a constrained Delaunay triangulation of its
  // points (its vertices, those on its edges, inside it) and of its segments
  // (where it crosses other triangles), the constraints crossing each other
  // at new points; the triangles in the same plane overlapping each other are
  // triangulated together, so that their parts are the same triangles.
  class Arrangement {
  public:
    std::string error;

    bool compute(const std::vector<double> &xyz, const std::vector<int> &tri,
                 const std::vector<int> &label)
    {
      _setup(xyz, tri, label);
      if(error.empty()) _intersectAll();
      if(error.empty()) _sortEdges();
      if(error.empty()) _triangulateAll();
      return error.empty();
    }

    // the inputs inside the cells on both sides of the triangles of the
    // arrangement (each one once), by the winding numbers of the inputs; the
    // cells thinner than thickness (twice their volume over their area) in
    // the cell they share most of their area with (their number in merged)
    bool winding(double thickness, std::vector<double> &oxyz,
                 std::vector<int> &otri, std::vector<int> &birth,
                 std::vector<std::vector<int> > &sets,
                 std::vector<std::array<int, 2> > &sides,
                 std::size_t &merged);

  private:
    enum { VERTEX, LPI3, LPI2, TPI, BARY };
    // a point: an input vertex d[0], the point of the line through the input
    // vertices d[0], d[1] in the plane of the triangle d[2] (LPI3), on the
    // line through d[2], d[3] in the projection along the axis d[4] (LPI2),
    // the point of the planes of the triangles d[0], d[1], d[2] (TPI), the
    // point d[1] v0 + d[2] v1 + d[3] v2 / (d[1] + d[2] + d[3]) of the
    // triangle d[0] (BARY); its coordinates rounded, the bounds of their
    // errors
    struct Point {
      int type;
      int d[5];
      double x[3], e[3];
    };
    struct Segment {
      int a, b, source;
    };
    struct Face {
      int v[3], t;
    };
    // a point on the segment pq of input vertices (p < q), p + a / (a - b) (q -
    // p), a and b the orientations of p and q relative to the plane of the
    // input vertices r, s, t, or, if t < 0, relative to the line rs in the
    // projection along the axis -t - 1
    struct Ratio {
      int p, q, r, s, t;
    };

    // the input: its vertices (those at the same place one), its triangles
    // (but those with two vertices the same and those without area), the
    // input triangles they are and their labels, the axis of their projection
    // and their orientation in it
    std::vector<double> _x;
    int _nv = 0, _nt = 0;
    std::vector<int> _tri, _birth, _label, _axis, _orientation;
    // the edges: their vertices, the smallest first; those of the triangles
    // (edge k from vertex k to vertex k + 1)
    std::vector<std::array<int, 2> > _edges;
    std::vector<int> _triEdges;
    // the points (the input vertices first), the exact homogeneous
    // coordinates of some of them, their grid
    std::vector<Point> _points;
    mutable std::unordered_map<int, std::array<Expansion, 4> > _exact;
    double _lo[3] = {0., 0., 0.}, _cell = 1., _maxError = 0.;
    std::unordered_map<uint64_t, std::vector<int> > _grid;
    // the points inside the edges, inside the triangles, the segments in the
    // triangles (their source: the plane of a triangle t >= 0, or the line of
    // the edge -t - 1)
    std::vector<std::vector<int> > _onEdge, _inside;
    std::vector<std::vector<Segment> > _segments;
    // the triangles in the same plane overlapping each other (union-find)
    std::vector<int> _parent;
    std::vector<std::array<double, 6> > _boxes;
    BoxTree _tree;
    // the triangles of the arrangement
    std::vector<Face> _faces;

    const double *X(int v) const { return &_x[3 * v]; }

    // ---- the points ----

    void _homogeneous(const Point &P, std::array<Expansion, 4> &h) const
    {
      switch(P.type) {
      case VERTEX:
        for(int k = 0; k < 3; k++) h[k] = Expansion(1, P.x[k]);
        h[3] = Expansion(1, 1.);
        return;
      case LPI3:
      case LPI2: {
        const double *p = X(P.d[0]), *q = X(P.d[1]);
        Expansion a, b;
        if(P.type == LPI3) {
          const int *v = &_tri[3 * P.d[2]];
          a = orient3dExact(X(v[0]), X(v[1]), X(v[2]), p);
          b = orient3dExact(X(v[0]), X(v[1]), X(v[2]), q);
        }
        else {
          a = orient2dExact(X(P.d[2]), X(P.d[3]), p, P.d[4]);
          b = orient2dExact(X(P.d[2]), X(P.d[3]), q, P.d[4]);
        }
        for(int k = 0; k < 3; k++)
          h[k] = compress(sub(scale(a, q[k]), scale(b, p[k])));
        h[3] = compress(sub(a, b));
        return;
      }
      case TPI: {
        // the planes n_i x = d_i: x = (d_1 n_2 x n_3 + d_2 n_3 x n_1 + d_3
        // n_1 x n_2) / n_1 . n_2 x n_3
        Expansion n[3][3], d[3];
        for(int i = 0; i < 3; i++) {
          const int *v = &_tri[3 * P.d[i]];
          for(int k = 0; k < 3; k++)
            n[i][k] = compress(orient2dExact(X(v[0]), X(v[1]), X(v[2]), k));
          d[i] = compress(sum(sum(scale(n[i][0], X(v[0])[0]),
                                  scale(n[i][1], X(v[0])[1])),
                              scale(n[i][2], X(v[0])[2])));
        }
        auto cross = [](const Expansion *a, const Expansion *b, Expansion *c) {
          c[0] = sub(product(a[1], b[2]), product(a[2], b[1]));
          c[1] = sub(product(a[2], b[0]), product(a[0], b[2]));
          c[2] = sub(product(a[0], b[1]), product(a[1], b[0]));
        };
        Expansion c23[3], c31[3], c12[3];
        cross(n[1], n[2], c23);
        cross(n[2], n[0], c31);
        cross(n[0], n[1], c12);
        h[3] = compress(sum(sum(product(n[0][0], c23[0]),
                                product(n[0][1], c23[1])),
                            product(n[0][2], c23[2])));
        for(int k = 0; k < 3; k++)
          h[k] = compress(sum(sum(product(d[0], c23[k]),
                                  product(d[1], c31[k])),
                              product(d[2], c12[k])));
        return;
      }
      case BARY: {
        const int *v = &_tri[3 * P.d[0]];
        for(int k = 0; k < 3; k++)
          h[k] = compress(sum(sum(scale(Expansion(1, X(v[0])[k]), P.d[1]),
                                  scale(Expansion(1, X(v[1])[k]), P.d[2])),
                              scale(Expansion(1, X(v[2])[k]), P.d[3])));
        h[3] = Expansion(1, (double)(P.d[1] + P.d[2] + P.d[3]));
        return;
      }
      }
    }

    const std::array<Expansion, 4> &_hom(int p) const
    {
      auto it = _exact.find(p);
      if(it != _exact.end()) return it->second;
      std::array<Expansion, 4> &h = _exact[p];
      _homogeneous(_points[p], h);
      return h;
    }

    Approx _approx(int p, int k) const
    {
      return {_points[p].x[k], _points[p].e[k]};
    }

    // the coordinates of a point rounded, within 8 ulps
    bool _round(Point &P, std::array<Expansion, 4> &h) const
    {
      _homogeneous(P, h);
      const double w = estimate(h[3]);
      if(w == 0. || !std::isfinite(w)) return false;
      for(int k = 0; k < 3; k++) {
        P.x[k] = estimate(h[k]) / w;
        if(!std::isfinite(P.x[k])) return false;
        P.e[k] = 8. * DBL_EPSILON * std::abs(P.x[k]);
      }
      return true;
    }

    int64_t _cellOf(double x, int k) const
    {
      return (int64_t)std::floor((x - _lo[k]) / _cell);
    }

    static uint64_t _key(int64_t i, int64_t j, int64_t l)
    {
      return ((uint64_t)i * 73856093u) ^ ((uint64_t)j * 19349663u) ^
             ((uint64_t)l * 83492791u);
    }

    void _insertGrid(int p)
    {
      const Point &P = _points[p];
      _grid[_key(_cellOf(P.x[0], 0), _cellOf(P.x[1], 1), _cellOf(P.x[2], 2))]
        .push_back(p);
    }

    // the same definition (up to the order of the planes of TPI)
    static bool _same(const Point &P, const Point &Q)
    {
      if(P.type != Q.type) return false;
      switch(P.type) {
      case VERTEX: return P.d[0] == Q.d[0];
      case LPI3:
        return P.d[0] == Q.d[0] && P.d[1] == Q.d[1] && P.d[2] == Q.d[2];
      case LPI2:
        return P.d[0] == Q.d[0] && P.d[1] == Q.d[1] && P.d[2] == Q.d[2] &&
               P.d[3] == Q.d[3] && P.d[4] == Q.d[4];
      case TPI: {
        int a[3] = {P.d[0], P.d[1], P.d[2]}, b[3] = {Q.d[0], Q.d[1], Q.d[2]};
        std::sort(a, a + 3);
        std::sort(b, b + 3);
        return a[0] == b[0] && a[1] == b[1] && a[2] == b[2];
      }
      }
      return false;
    }

    // a point already there at the same place, -1 if none
    int _find(const Point &P, const std::array<Expansion, 4> &h) const
    {
      int64_t lo[3], hi[3];
      for(int k = 0; k < 3; k++) {
        const double r = P.e[k] + _maxError;
        lo[k] = _cellOf(P.x[k] - r, k);
        hi[k] = _cellOf(P.x[k] + r, k);
      }
      for(int64_t i = lo[0]; i <= hi[0]; i++)
        for(int64_t j = lo[1]; j <= hi[1]; j++)
          for(int64_t l = lo[2]; l <= hi[2]; l++) {
            auto it = _grid.find(_key(i, j, l));
            if(it == _grid.end()) continue;
            for(int c : it->second) {
              const Point &Q = _points[c];
              bool near = true;
              for(int k = 0; k < 3 && near; k++)
                if(std::abs(P.x[k] - Q.x[k]) > P.e[k] + Q.e[k]) near = false;
              if(!near) continue;
              if(_same(P, Q)) return c;
              const std::array<Expansion, 4> &q = _hom(c);
              bool equal = true;
              for(int k = 0; k < 3 && equal; k++)
                if(sign(sub(product(h[k], q[3]), product(q[k], h[3]))))
                  equal = false;
              if(equal) return c;
            }
          }
      return -1;
    }

    // a new point, or the one already at the same place
    int _add(int type, int d0, int d1, int d2, int d3 = 0, int d4 = 0)
    {
      Point P;
      P.type = type;
      // (a canonical order of the lines)
      if((type == LPI3 || type == LPI2) && d0 > d1) std::swap(d0, d1);
      if(type == LPI2 && d2 > d3) std::swap(d2, d3);
      P.d[0] = d0;
      P.d[1] = d1;
      P.d[2] = d2;
      P.d[3] = d3;
      P.d[4] = d4;
      std::array<Expansion, 4> h;
      if(!_round(P, h)) {
        error = "a point of the arrangement at infinity";
        return -1;
      }
      const int f = _find(P, h);
      if(f >= 0) return f;
      const int id = (int)_points.size();
      _points.push_back(P);
      _insertGrid(id);
      for(int k = 0; k < 3; k++) _maxError = std::max(_maxError, P.e[k]);
      return id;
    }

    // ---- the predicates on points ----

    // the orientation of 3 points in the projection along the axis k
    int _orient2d(int a, int b, int c, int k) const
    {
      const Point &A = _points[a], &B = _points[b], &C = _points[c];
      if(A.type == VERTEX && B.type == VERTEX && C.type == VERTEX)
        return orient2d(A.x, B.x, C.x, k);
      const int i = (k + 1) % 3, j = (k + 2) % 3;
      const Approx d = (_approx(a, i) - _approx(c, i)) *
                         (_approx(b, j) - _approx(c, j)) -
                       (_approx(a, j) - _approx(c, j)) *
                         (_approx(b, i) - _approx(c, i));
      if(certain(d)) return sign(d.v);
      const std::array<Expansion, 4> &ha = _hom(a), &hb = _hom(b),
                                     &hc = _hom(c);
      const Expansion det =
        sum(sub(product(ha[i], sub(product(hb[j], hc[3]),
                                   product(hb[3], hc[j]))),
                product(ha[j], sub(product(hb[i], hc[3]),
                                   product(hb[3], hc[i])))),
            product(ha[3],
                    sub(product(hb[i], hc[j]), product(hb[j], hc[i]))));
      return sign(det) * sign(ha[3]) * sign(hb[3]) * sign(hc[3]);
    }

    // the sign of a_m - b_m
    int _compareAxis(int a, int b, int m) const
    {
      const Point &A = _points[a], &B = _points[b];
      if(A.type == VERTEX && B.type == VERTEX) return sign(A.x[m] - B.x[m]);
      const Approx d = _approx(a, m) - _approx(b, m);
      if(certain(d)) return sign(d.v);
      const std::array<Expansion, 4> &ha = _hom(a), &hb = _hom(b);
      return sign(sub(product(ha[m], hb[3]), product(hb[m], ha[3]))) *
             sign(ha[3]) * sign(hb[3]);
    }

    // orient3d of the vertices of the triangle t and of the point p
    int _side(int t, int p) const
    {
      const int *v = &_tri[3 * t];
      const Point &P = _points[p];
      if(P.type == VERTEX) return orient3d(X(v[0]), X(v[1]), X(v[2]), P.x);
      Approx ad[3], bd[3], cd[3];
      for(int k = 0; k < 3; k++) {
        ad[k] = exact(X(v[0])[k]) - _approx(p, k);
        bd[k] = exact(X(v[1])[k]) - _approx(p, k);
        cd[k] = exact(X(v[2])[k]) - _approx(p, k);
      }
      const Approx d = ad[0] * (bd[1] * cd[2] - bd[2] * cd[1]) -
                       ad[1] * (bd[0] * cd[2] - bd[2] * cd[0]) +
                       ad[2] * (bd[0] * cd[1] - bd[1] * cd[0]);
      if(certain(d)) return sign(d.v);
      // - (n . x - n . v0) with n = (v1 - v0) x (v2 - v0), x = h / h_w
      const std::array<Expansion, 4> &h = _hom(p);
      Expansion n[3];
      for(int k = 0; k < 3; k++)
        n[k] = compress(orient2dExact(X(v[0]), X(v[1]), X(v[2]), k));
      const Expansion nx =
        sum(sum(product(n[0], h[0]), product(n[1], h[1])), product(n[2], h[2]));
      const Expansion nv =
        compress(sum(sum(scale(n[0], X(v[0])[0]), scale(n[1], X(v[0])[1])),
                     scale(n[2], X(v[0])[2])));
      return -sign(sub(nx, product(nv, h[3]))) * sign(h[3]);
    }

    // ---- the input ----

    void _setup(const std::vector<double> &xyz, const std::vector<int> &tri,
                const std::vector<int> &label)
    {
      // the vertices, those at the same place one
      const int n = (int)xyz.size() / 3;
      std::vector<int> order(n);
      std::iota(order.begin(), order.end(), 0);
      auto less = [&](int a, int b) {
        for(int k = 0; k < 3; k++) {
          if(xyz[3 * a + k] < xyz[3 * b + k]) return true;
          if(xyz[3 * a + k] > xyz[3 * b + k]) return false;
        }
        return false;
      };
      std::sort(order.begin(), order.end(), less);
      std::vector<int> id(n, -1);
      for(int i = 0; i < n; i++) {
        const int v = order[i];
        if(i && !less(order[i - 1], v))
          id[v] = id[order[i - 1]];
        else {
          id[v] = _nv++;
          for(int k = 0; k < 3; k++) _x.push_back(xyz[3 * v + k]);
        }
      }
      // the triangles, the axes of their projections
      const int nt = (int)tri.size() / 3;
      for(int t = 0; t < nt; t++) {
        const int a = id[tri[3 * t]], b = id[tri[3 * t + 1]],
                  c = id[tri[3 * t + 2]];
        if(a == b || b == c || c == a) continue;
        const double *A = X(a), *B = X(b), *C = X(c);
        const double nn[3] = {
          (B[1] - A[1]) * (C[2] - A[2]) - (B[2] - A[2]) * (C[1] - A[1]),
          (B[2] - A[2]) * (C[0] - A[0]) - (B[0] - A[0]) * (C[2] - A[2]),
          (B[0] - A[0]) * (C[1] - A[1]) - (B[1] - A[1]) * (C[0] - A[0])};
        int axes[3] = {0, 1, 2};
        std::sort(axes, axes + 3, [&](int i, int j) {
          return std::abs(nn[i]) > std::abs(nn[j]);
        });
        int o = 0, k = 0;
        for(int i = 0; i < 3 && !o; i++) {
          k = axes[i];
          o = orient2d(A, B, C, k);
        }
        if(!o) continue;
        _tri.push_back(a);
        _tri.push_back(b);
        _tri.push_back(c);
        _birth.push_back(t);
        _label.push_back(label[t]);
        _axis.push_back(k);
        _orientation.push_back(o);
      }
      _nt = (int)_birth.size();
      // the points, their grid
      _points.resize(_nv);
      double hi[3] = {-1e300, -1e300, -1e300};
      for(int k = 0; k < 3; k++) _lo[k] = 1e300;
      for(int v = 0; v < _nv; v++) {
        Point &P = _points[v];
        P.type = VERTEX;
        P.d[0] = v;
        P.d[1] = P.d[2] = P.d[3] = P.d[4] = 0;
        for(int k = 0; k < 3; k++) {
          P.x[k] = X(v)[k];
          P.e[k] = 0.;
          _lo[k] = std::min(_lo[k], P.x[k]);
          hi[k] = std::max(hi[k], P.x[k]);
        }
      }
      double size = 0.;
      for(int k = 0; k < 3; k++) size = std::max(size, hi[k] - _lo[k]);
      if(!(size > 0.)) size = 1.;
      _cell = std::ldexp(size, -20);
      for(int v = 0; v < _nv; v++) _insertGrid(v);
      // the edges
      std::vector<std::array<int, 4> > half(3 * _nt);
      for(int t = 0; t < _nt; t++)
        for(int k = 0; k < 3; k++) {
          const int a = _tri[3 * t + k], b = _tri[3 * t + (k + 1) % 3];
          half[3 * t + k] = {std::min(a, b), std::max(a, b), t, k};
        }
      std::sort(half.begin(), half.end());
      _triEdges.assign(3 * _nt, -1);
      for(std::size_t i = 0; i < half.size();) {
        std::size_t j = i;
        while(j < half.size() && half[j][0] == half[i][0] &&
              half[j][1] == half[i][1])
          j++;
        const int e = (int)_edges.size();
        _edges.push_back({half[i][0], half[i][1]});
        for(std::size_t h = i; h < j; h++)
          _triEdges[3 * half[h][2] + half[h][3]] = e;
        i = j;
      }
      _onEdge.resize(_edges.size());
      _inside.resize(_nt);
      _segments.resize(_nt);
      _parent.resize(_nt);
      std::iota(_parent.begin(), _parent.end(), 0);
      // the boxes of the triangles
      _boxes.resize(_nt);
      for(int t = 0; t < _nt; t++) {
        std::array<double, 6> &b = _boxes[t];
        for(int k = 0; k < 3; k++) {
          b[k] = 1e300;
          b[3 + k] = -1e300;
        }
        for(int i = 0; i < 3; i++)
          for(int k = 0; k < 3; k++) {
            b[k] = std::min(b[k], X(_tri[3 * t + i])[k]);
            b[3 + k] = std::max(b[3 + k], X(_tri[3 * t + i])[k]);
          }
      }
      std::vector<int> items(_nt);
      std::iota(items.begin(), items.end(), 0);
      _tree.build(_boxes, items);
    }

    int _root(int t)
    {
      while(_parent[t] != t) t = _parent[t] = _parent[_parent[t]];
      return t;
    }

    void _unite(int t, int u)
    {
      t = _root(t);
      u = _root(u);
      if(t != u) _parent[std::max(t, u)] = std::min(t, u);
    }

    // ---- the intersections of the triangles ----

    // the orientations defining a ratio
    void _orientations(const Ratio &r, Expansion &a, Expansion &b) const
    {
      if(r.t >= 0) {
        a = orient3dExact(X(r.r), X(r.s), X(r.t), X(r.p));
        b = orient3dExact(X(r.r), X(r.s), X(r.t), X(r.q));
      }
      else {
        a = orient2dExact(X(r.r), X(r.s), X(r.p), -r.t - 1);
        b = orient2dExact(X(r.r), X(r.s), X(r.q), -r.t - 1);
      }
    }

    // the sign of a1 / (a1 - b1) - a2 / (a2 - b2) for two ratios along the
    // same segment
    int _compare(const Ratio &r1, const Ratio &r2) const
    {
      Expansion a1, b1, a2, b2;
      _orientations(r1, a1, b1);
      _orientations(r2, a2, b2);
      return sign(sub(product(a2, b1), product(a1, b2))) * sign(sub(a1, b1)) *
             sign(sub(a2, b2));
    }

    // a point (a point id) in the relative interior of the vertex, the edge
    // or the triangle (dimension 0, 1, 2) index
    void _register(int point, int dimension, int index)
    {
      if(dimension == 1)
        _onEdge[index].push_back(point);
      else if(dimension == 2)
        _inside[index].push_back(point);
    }

    // the location of an input vertex w in the plane of the triangle t: false
    // outside, its dimension and index otherwise
    bool _locate(int w, int t, int &dimension, int &index) const
    {
      const int *v = &_tri[3 * t];
      const int k = _axis[t], o = _orientation[t];
      int s[3];
      for(int i = 0; i < 3; i++) {
        s[i] = o * orient2d(X(v[i]), X(v[(i + 1) % 3]), X(w), k);
        if(s[i] < 0) return false;
      }
      const int zeros = (s[0] == 0) + (s[1] == 0) + (s[2] == 0);
      if(zeros == 0) {
        dimension = 2;
        index = t;
      }
      else if(zeros == 1) {
        int i = 0;
        while(s[i]) i++;
        dimension = 1;
        index = _triEdges[3 * t + i];
      }
      else {
        int i = 0;
        while(s[i] || s[(i + 1) % 3]) i++;
        dimension = 0;
        index = v[(i + 1) % 3];
      }
      return true;
    }

    // the intersection of the edge e with the triangle t, the edge in the
    // plane of t: the points (at most 2) registered where they lie
    int _intersectCoplanar(int e, int t, int out[2])
    {
      const int p = _edges[e][0], q = _edges[e][1];
      const int *v = &_tri[3 * t];
      const int k = _axis[t], o = _orientation[t];
      int sp[3], sq[3];
      for(int i = 0; i < 3; i++) {
        sp[i] = o * orient2d(X(v[i]), X(v[(i + 1) % 3]), X(p), k);
        sq[i] = o * orient2d(X(v[i]), X(v[(i + 1) % 3]), X(q), k);
        if(sp[i] < 0 && sq[i] < 0) return 0;
      }
      // the lines of the edges of t through which pq enters and exits
      auto crossing = [&](int i) {
        return Ratio{p, q, v[i], v[(i + 1) % 3], -k - 1};
      };
      int enter = -1, exit = -1;
      for(int i = 0; i < 3; i++) {
        if(sp[i] < 0) {
          if(enter < 0 || _compare(crossing(i), crossing(enter)) > 0)
            enter = i;
        }
        else if(sq[i] < 0) {
          if(exit < 0 || _compare(crossing(i), crossing(exit)) < 0) exit = i;
        }
      }
      if(enter >= 0 && exit >= 0 &&
         _compare(crossing(enter), crossing(exit)) > 0)
        return 0;
      auto endpoint = [&](int i, bool entering) {
        if(i < 0 || (entering && sq[i] == 0) || (!entering && sp[i] == 0)) {
          // an endpoint of pq
          const int w = (i < 0) == entering ? p : q;
          int dimension, index;
          if(_locate(w, t, dimension, index)) _register(w, dimension, index);
          return w;
        }
        const int a = v[i], b = v[(i + 1) % 3];
        int w = -1;
        if(orient2d(X(p), X(q), X(a), k) == 0)
          w = a;
        else if(orient2d(X(p), X(q), X(b), k) == 0)
          w = b;
        if(w >= 0) {
          if(w != p && w != q) _register(w, 1, e);
          return w;
        }
        w = _add(LPI2, p, q, a, b, k);
        if(w < 0) return 0;
        _register(w, 1, e);
        _register(w, 1, _triEdges[3 * t + i]);
        return w;
      };
      out[0] = endpoint(enter, true);
      out[1] = endpoint(exit, false);
      return out[0] == out[1] ? 1 : 2;
    }

    // the intersection of the edge e with the triangle t: the points (at
    // most 2) registered where they lie
    int _intersect(int e, int t, int out[2])
    {
      const int p = _edges[e][0], q = _edges[e][1];
      const int *v = &_tri[3 * t];
      const int dp = orient3d(X(v[0]), X(v[1]), X(v[2]), X(p));
      const int dq = orient3d(X(v[0]), X(v[1]), X(v[2]), X(q));
      if(dp * dq > 0) return 0;
      if(!dp && !dq) return _intersectCoplanar(e, t, out);
      int dimension, index;
      if(!dp || !dq) {
        const int w = dp ? q : p;
        if(!_locate(w, t, dimension, index)) return 0;
        _register(w, dimension, index);
        out[0] = w;
        return 1;
      }
      int s[3];
      for(int i = 0; i < 3; i++)
        s[i] = orient3d(X(p), X(q), X(v[i]), X(v[(i + 1) % 3]));
      if((s[0] > 0 || s[1] > 0 || s[2] > 0) &&
         (s[0] < 0 || s[1] < 0 || s[2] < 0))
        return 0;
      const int zeros = (s[0] == 0) + (s[1] == 0) + (s[2] == 0);
      if(zeros == 2) {
        // through a vertex of t
        int i = 0;
        while(s[i] || s[(i + 1) % 3]) i++;
        const int w = v[(i + 1) % 3];
        _register(w, 1, e);
        out[0] = w;
        return 1;
      }
      const int w = _add(LPI3, p, q, t);
      if(w < 0) return 0;
      _register(w, 1, e);
      if(zeros == 1) {
        int i = 0;
        while(s[i]) i++;
        _register(w, 1, _triEdges[3 * t + i]);
      }
      else
        _register(w, 2, t);
      out[0] = w;
      return 1;
    }

    // whether the insides of two triangles in the same plane overlap: no
    // line of an edge separating them
    bool _overlap(int t, int u) const
    {
      const int k = _axis[t];
      auto separated = [&](int a, int b) {
        const int *v = &_tri[3 * a], *w = &_tri[3 * b];
        const int o = orient2d(X(v[0]), X(v[1]), X(v[2]), k);
        for(int i = 0; i < 3; i++) {
          bool all = true;
          for(int j = 0; j < 3 && all; j++)
            if(o * orient2d(X(v[i]), X(v[(i + 1) % 3]), X(w[j]), k) > 0)
              all = false;
          if(all) return true;
        }
        return false;
      };
      return !separated(t, u) && !separated(u, t);
    }

    void _pair(int t, int u)
    {
      const int *a = &_tri[3 * t], *b = &_tri[3 * u];
      int shared = 0;
      for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
          if(a[i] == b[j]) shared++;
      if(shared == 3) {
        // the same triangle (or turned over)
        _unite(t, u);
        return;
      }
      if(shared == 2) {
        // along an edge: only if in the same plane, on the same side of it
        int c = -1, d = -1;
        for(int i = 0; i < 3; i++) {
          if(a[i] != b[0] && a[i] != b[1] && a[i] != b[2]) c = a[i];
          if(b[i] != a[0] && b[i] != a[1] && b[i] != a[2]) d = b[i];
        }
        if(orient3d(X(b[0]), X(b[1]), X(b[2]), X(c))) return;
        int e0 = -1, e1 = -1;
        for(int i = 0; i < 3; i++)
          if(a[i] != c) (e0 < 0 ? e0 : e1) = a[i];
        const int k = _axis[t];
        if(orient2d(X(e0), X(e1), X(c), k) * orient2d(X(e0), X(e1), X(d), k) <
           0)
          return;
        _unite(t, u);
        int out[2];
        for(int i = 0; i < 3; i++) {
          _intersectCoplanar(_triEdges[3 * t + i], u, out);
          _intersectCoplanar(_triEdges[3 * u + i], t, out);
        }
        return;
      }
      int da[3], db[3];
      for(int i = 0; i < 3; i++)
        da[i] = orient3d(X(b[0]), X(b[1]), X(b[2]), X(a[i]));
      if((da[0] > 0 && da[1] > 0 && da[2] > 0) ||
         (da[0] < 0 && da[1] < 0 && da[2] < 0))
        return;
      for(int i = 0; i < 3; i++)
        db[i] = orient3d(X(a[0]), X(a[1]), X(a[2]), X(b[i]));
      if((db[0] > 0 && db[1] > 0 && db[2] > 0) ||
         (db[0] < 0 && db[1] < 0 && db[2] < 0))
        return;
      if(!da[0] && !da[1] && !da[2]) {
        // in the same plane: the points on the edges of each one
        int out[2];
        for(int i = 0; i < 3; i++) {
          _intersectCoplanar(_triEdges[3 * t + i], u, out);
          _intersectCoplanar(_triEdges[3 * u + i], t, out);
        }
        if(_overlap(t, u)) _unite(t, u);
        return;
      }
      int points[12], n = 0;
      for(int i = 0; i < 3; i++)
        n += _intersect(_triEdges[3 * t + i], u, points + n);
      for(int i = 0; i < 3; i++)
        n += _intersect(_triEdges[3 * u + i], t, points + n);
      std::sort(points, points + n);
      n = (int)(std::unique(points, points + n) - points);
      if(n > 2) {
        error = "inconsistent intersection of two triangles";
        return;
      }
      if(n == 2) {
        _segments[t].push_back({points[0], points[1], u});
        _segments[u].push_back({points[0], points[1], t});
      }
    }

    void _intersectAll()
    {
      for(int t = 0; t < _nt && error.empty(); t++)
        _tree.query(_boxes[t], [&](int u) {
          if(u > t && error.empty()) _pair(t, u);
        });
    }

    // the points inside the edges in their order
    void _sortEdges()
    {
      for(std::size_t e = 0; e < _edges.size(); e++) {
        std::vector<int> &on = _onEdge[e];
        if(on.empty()) continue;
        const int p = _edges[e][0], q = _edges[e][1];
        std::sort(on.begin(), on.end());
        on.erase(std::unique(on.begin(), on.end()), on.end());
        on.erase(std::remove_if(on.begin(), on.end(),
                                [&](int w) { return w == p || w == q; }),
                 on.end());
        if(on.size() < 2) continue;
        int m = 0;
        for(int k = 1; k < 3; k++)
          if(std::abs(X(q)[k] - X(p)[k]) > std::abs(X(q)[m] - X(p)[m])) m = k;
        const int s = sign(X(q)[m] - X(p)[m]);
        std::sort(on.begin(), on.end(), [&](int a, int b) {
          return s * _compareAxis(a, b, m) < 0;
        });
        for(std::size_t i = 0; i + 1 < on.size(); i++)
          if(!_compareAxis(on[i], on[i + 1], m)) {
            error = "two points of an edge at the same place";
            return;
          }
      }
    }

    // ---- the triangulations ----

    // the constrained Delaunay triangulation of the points of a triangle, or
    // of triangles in the same plane overlapping each other, in the
    // projection along the axis of the first one: the Delaunay criterion on
    // approximate coordinates in an orthonormal frame of the plane, the
    // validity of the triangulation (locations, convexity of the flips,
    // crossings of the constraints) decided exactly
    class Triangulation {
    public:
      struct Tri {
        int v[3], n[3], c[3];
      };
      std::vector<Tri> t;

    private:
      Arrangement &_a;
      int _k = 0, _o = 1, _plane = 0;
      std::vector<int> _gid, _vt;
      std::unordered_map<int, int> _local;
      std::vector<std::array<double, 2> > _q;
      double _origin[3], _e1[3], _e2[3];
      std::vector<int> _sources;
      int _last = 0;
      unsigned _random = 12345;

      static int _at(const Tri &T, int v)
      {
        return T.v[0] == v ? 0 : T.v[1] == v ? 1 : T.v[2] == v ? 2 : -1;
      }

      int _orient(int a, int b, int c) const
      {
        return _o * _a._orient2d(_gid[a], _gid[b], _gid[c], _k);
      }

      int _orientPoint(int a, int b, int g) const
      {
        return _o * _a._orient2d(_gid[a], _gid[b], g, _k);
      }

      void _setNeighbor(int i, int from, int to)
      {
        if(i < 0) return;
        for(int j = 0; j < 3; j++)
          if(t[i].n[j] == from) {
            t[i].n[j] = to;
            return;
          }
      }

      // the triangles around the vertex a: f(triangle, index of a in it),
      // true to stop
      template <class F> void _around(int a, F f) const
      {
        const int i0 = _vt[a];
        int i = i0;
        do {
          const int j = _at(t[i], a);
          if(f(i, j)) return;
          i = t[i].n[(j + 2) % 3];
        } while(i >= 0 && i != i0);
        if(i == i0) return;
        i = t[i0].n[_at(t[i0], a)];
        while(i >= 0) {
          const int j = _at(t[i], a);
          if(f(i, j)) return;
          i = t[i].n[j];
        }
      }

      // the triangle with the edge from a to b
      bool _directed(int a, int b, int &i, int &j) const
      {
        bool found = false;
        _around(a, [&](int ti, int tj) {
          if(t[ti].v[(tj + 1) % 3] != b) return false;
          i = ti;
          j = tj;
          found = true;
          return true;
        });
        return found;
      }

      bool _edge(int a, int b, int &i, int &j) const
      {
        return _directed(a, b, i, j) || _directed(b, a, i, j);
      }

      void _mark(int i, int j, int source)
      {
        t[i].c[j] = source;
        const int u = t[i].n[j];
        if(u < 0) return;
        const int jj = _at(t[u], t[i].v[(j + 1) % 3]);
        t[u].c[jj] = source;
      }

      void _flip(int i, int j)
      {
        const Tri T = t[i];
        const int u = T.n[j];
        const Tri U = t[u];
        const int a = T.v[j], b = T.v[(j + 1) % 3], c = T.v[(j + 2) % 3];
        const int jj = _at(U, b), d = U.v[(jj + 2) % 3];
        const int nbc = T.n[(j + 1) % 3], nca = T.n[(j + 2) % 3];
        const int cbc = T.c[(j + 1) % 3], cca = T.c[(j + 2) % 3];
        const int nad = U.n[(jj + 1) % 3], ndb = U.n[(jj + 2) % 3];
        const int cad = U.c[(jj + 1) % 3], cdb = U.c[(jj + 2) % 3];
        t[i] = {{a, d, c}, {nad, u, nca}, {cad, -1, cca}};
        t[u] = {{d, b, c}, {ndb, nbc, i}, {cdb, cbc, -1}};
        _setNeighbor(nad, u, i);
        _setNeighbor(nbc, i, u);
        _vt[a] = i;
        _vt[c] = i;
        _vt[d] = u;
        _vt[b] = u;
      }

      // the flips restoring the Delaunay criterion from some edges
      void _legalize(std::vector<std::pair<int, int> > stack)
      {
        const std::size_t limit = 50 * t.size() + 1000;
        for(std::size_t iter = 0; !stack.empty() && iter < limit; iter++) {
          const std::pair<int, int> e = stack.back();
          stack.pop_back();
          const int i = e.first, j = e.second;
          if(t[i].c[j] >= 0 || t[i].n[j] < 0) continue;
          const int u = t[i].n[j];
          const int a = t[i].v[j], b = t[i].v[(j + 1) % 3],
                    c = t[i].v[(j + 2) % 3];
          const int jj = _at(t[u], b);
          if(jj < 0 || t[u].v[(jj + 1) % 3] != a) continue;
          const int d = t[u].v[(jj + 2) % 3];
          if(robustPredicates::incircle(_q[a].data(), _q[b].data(),
                                        _q[c].data(), _q[d].data()) <= 0.)
            continue;
          if(_orient(a, d, c) <= 0 || _orient(d, b, c) <= 0) continue;
          _flip(i, j);
          stack.push_back({i, 0});
          stack.push_back({i, 2});
          stack.push_back({u, 0});
          stack.push_back({u, 1});
        }
      }

      void _splitTriangle(int i, int p)
      {
        const Tri T = t[i];
        const int a = T.v[0], b = T.v[1], c = T.v[2];
        const int i2 = (int)t.size(), i3 = i2 + 1;
        t.resize(t.size() + 2);
        t[i] = {{a, b, p}, {T.n[0], i2, i3}, {T.c[0], -1, -1}};
        t[i2] = {{b, c, p}, {T.n[1], i3, i}, {T.c[1], -1, -1}};
        t[i3] = {{c, a, p}, {T.n[2], i, i2}, {T.c[2], -1, -1}};
        _setNeighbor(T.n[1], i, i2);
        _setNeighbor(T.n[2], i, i3);
        _vt[a] = i;
        _vt[b] = i2;
        _vt[c] = i3;
        _vt[p] = i;
        _legalize({{i, 0}, {i2, 0}, {i3, 0}});
      }

      // the edge j of the triangle i split at p (its parts constrained as it
      // is)
      void _splitEdge(int i, int j, int p)
      {
        const Tri T = t[i];
        const int a = T.v[j], b = T.v[(j + 1) % 3], c = T.v[(j + 2) % 3];
        const int nbc = T.n[(j + 1) % 3], nca = T.n[(j + 2) % 3];
        const int cab = T.c[j], cbc = T.c[(j + 1) % 3],
                  cca = T.c[(j + 2) % 3];
        const int u = T.n[j];
        const int i3 = (int)t.size();
        t.resize(t.size() + 1);
        if(u < 0) {
          t[i] = {{a, p, c}, {-1, i3, nca}, {cab, -1, cca}};
          t[i3] = {{p, b, c}, {-1, nbc, i}, {cab, cbc, -1}};
          _setNeighbor(nbc, i, i3);
          _vt[a] = i;
          _vt[c] = i;
          _vt[p] = i;
          _vt[b] = i3;
          _legalize({{i, 2}, {i3, 1}});
          return;
        }
        const Tri U = t[u];
        const int jj = _at(U, b), d = U.v[(jj + 2) % 3];
        const int nad = U.n[(jj + 1) % 3], ndb = U.n[(jj + 2) % 3];
        const int cad = U.c[(jj + 1) % 3], cdb = U.c[(jj + 2) % 3];
        const int i4 = (int)t.size();
        t.resize(t.size() + 1);
        t[i] = {{a, p, c}, {i4, i3, nca}, {cab, -1, cca}};
        t[i3] = {{p, b, c}, {u, nbc, i}, {cab, cbc, -1}};
        t[u] = {{b, p, d}, {i3, i4, ndb}, {cab, -1, cdb}};
        t[i4] = {{p, a, d}, {i, nad, u}, {cab, cad, -1}};
        _setNeighbor(nbc, i, i3);
        _setNeighbor(nad, u, i4);
        _vt[a] = i;
        _vt[c] = i;
        _vt[p] = i;
        _vt[b] = i3;
        _vt[d] = u;
        _legalize({{i, 2}, {i3, 1}, {u, 2}, {i4, 1}});
      }

      // the triangle containing the point g (exact walk, or search), the
      // orientations relative to its edges
      int _locate(int g, int o[3])
      {
        int i = _last < (int)t.size() ? _last : 0;
        const int limit = 4 * (int)t.size() + 100;
        for(int steps = 0; steps < limit; steps++) {
          _random = _random * 1103515245u + 12345u;
          const int r = (int)((_random >> 16) % 3);
          int next = -2;
          for(int e = 0; e < 3; e++) {
            const int j = (r + e) % 3;
            if(_orientPoint(t[i].v[j], t[i].v[(j + 1) % 3], g) < 0) {
              next = t[i].n[j];
              break;
            }
          }
          if(next == -2) break;
          if(next < 0) {
            i = -1;
            break;
          }
          i = next;
        }
        auto inside = [&](int u) {
          for(int j = 0; j < 3; j++) {
            o[j] = _orientPoint(t[u].v[j], t[u].v[(j + 1) % 3], g);
            if(o[j] < 0) return false;
          }
          return true;
        };
        if(i >= 0 && inside(i)) {
          _last = i;
          return i;
        }
        for(int u = 0; u < (int)t.size(); u++)
          if(inside(u)) {
            _last = u;
            return u;
          }
        return -1;
      }

      // the triangles from a list (counterclockwise), their neighbors
      void _build(const std::vector<std::array<int, 3> > &tris)
      {
        t.clear();
        std::unordered_map<uint64_t, std::pair<int, int> > half;
        for(std::size_t i = 0; i < tris.size(); i++) {
          Tri T;
          for(int j = 0; j < 3; j++) {
            T.v[j] = tris[i][j];
            T.n[j] = T.c[j] = -1;
          }
          t.push_back(T);
        }
        for(int i = 0; i < (int)t.size(); i++)
          for(int j = 0; j < 3; j++) {
            const int a = t[i].v[j], b = t[i].v[(j + 1) % 3];
            auto it = half.find((uint64_t)(uint32_t)b << 32 | (uint32_t)a);
            if(it != half.end()) {
              t[i].n[j] = it->second.first;
              t[it->second.first].n[it->second.second] = i;
            }
            else
              half[(uint64_t)(uint32_t)a << 32 | (uint32_t)b] = {i, j};
            _vt[a] = i;
          }
      }

      // the recovery of the edge from a to v by flips, the edges crossing it
      // given
      bool _recover(int a, int v,
                    const std::vector<std::pair<int, int> > &crossed)
      {
        std::deque<std::pair<int, int> > list(crossed.begin(), crossed.end());
        const std::size_t limit = 1000 * (list.size() + 10);
        for(std::size_t iter = 0; !list.empty(); iter++) {
          if(iter > limit) return false;
          const std::pair<int, int> e = list.front();
          list.pop_front();
          int i, j;
          if(!_edge(e.first, e.second, i, j)) continue;
          const int u = t[i].n[j];
          if(u < 0) return false;
          const int p = t[i].v[j], q = t[i].v[(j + 1) % 3],
                    c = t[i].v[(j + 2) % 3];
          const int d = t[u].v[(_at(t[u], q) + 2) % 3];
          if(_orient(p, d, c) > 0 && _orient(d, q, c) > 0) {
            _flip(i, j);
            if(c != a && c != v && d != a && d != v &&
               _orient(a, v, c) * _orient(a, v, d) < 0)
              list.push_back({c, d});
          }
          else
            list.push_back(e);
        }
        return true;
      }

    public:
      std::string error;

      Triangulation(Arrangement &a) : _a(a) {}

      // a new triangulation in the plane of the triangle plane
      void reset(int plane)
      {
        _plane = plane;
        _k = _a._axis[plane];
        _o = _a._orientation[plane];
        _gid.clear();
        _vt.clear();
        _local.clear();
        _q.clear();
        _sources.clear();
        t.clear();
        _last = 0;
        error.clear();
        const int *v = &_a._tri[3 * plane];
        const double *x0 = _a.X(v[0]), *x1 = _a.X(v[1]), *x2 = _a.X(v[2]);
        double u[3], w[3], n[3];
        for(int k = 0; k < 3; k++) {
          _origin[k] = x0[k];
          u[k] = x1[k] - x0[k];
          w[k] = x2[k] - x0[k];
        }
        n[0] = u[1] * w[2] - u[2] * w[1];
        n[1] = u[2] * w[0] - u[0] * w[2];
        n[2] = u[0] * w[1] - u[1] * w[0];
        _e2[0] = n[1] * u[2] - n[2] * u[1];
        _e2[1] = n[2] * u[0] - n[0] * u[2];
        _e2[2] = n[0] * u[1] - n[1] * u[0];
        double l1 = 0., l2 = 0.;
        for(int k = 0; k < 3; k++) {
          l1 += u[k] * u[k];
          l2 += _e2[k] * _e2[k];
        }
        l1 = std::sqrt(l1);
        l2 = std::sqrt(l2);
        for(int k = 0; k < 3; k++) {
          _e1[k] = u[k] / l1;
          _e2[k] /= l2;
        }
      }

      int vertex(int g)
      {
        auto it = _local.find(g);
        if(it != _local.end()) return it->second;
        const int l = (int)_gid.size();
        _local[g] = l;
        _gid.push_back(g);
        _vt.push_back(-1);
        const double *x = _a._points[g].x;
        double d[3], p = 0., q = 0.;
        for(int k = 0; k < 3; k++) {
          d[k] = x[k] - _origin[k];
          p += d[k] * _e1[k];
          q += d[k] * _e2[k];
        }
        _q.push_back({p, q});
        return l;
      }

      int local(int g) const
      {
        auto it = _local.find(g);
        return it == _local.end() ? -1 : it->second;
      }

      int global(int l) const { return _gid[l]; }

      // the first triangles (their global points, counterclockwise)
      void start(const std::vector<std::array<int, 3> > &tris)
      {
        std::vector<std::array<int, 3> > l;
        for(auto &T : tris) l.push_back({vertex(T[0]), vertex(T[1]), vertex(T[2])});
        _build(l);
      }

      // the insertion of a point
      bool insert(int g)
      {
        if(_local.count(g)) return true;
        int o[3];
        const int i = _locate(g, o);
        if(i < 0) {
          error = "a point outside of its triangle";
          return false;
        }
        const int zeros = (o[0] == 0) + (o[1] == 0) + (o[2] == 0);
        if(zeros > 1) {
          error = "two points at the same place";
          return false;
        }
        const int p = vertex(g);
        if(!zeros)
          _splitTriangle(i, p);
        else {
          int j = 0;
          while(o[j]) j++;
          _splitEdge(i, j, p);
        }
        return true;
      }

      // the insertion of the constraint from the point ga to gb (both
      // inserted), from a source: split at the points on it, at new points
      // where it crosses other constraints
      bool constrain(int ga, int gb, int source)
      {
        int a = local(ga);
        const int b = local(gb);
        if(a < 0 || b < 0) {
          error = "a segment with an end not in its triangle";
          return false;
        }
        const int s = (int)_sources.size();
        _sources.push_back(source);
        for(int guard = 0; a != b; guard++) {
          if(guard > 1000000) {
            error = "could not insert a segment";
            return false;
          }
          int i, j;
          if(_edge(a, b, i, j)) {
            _mark(i, j, s);
            return true;
          }
          // the triangle around a in the direction of b
          int start = -1, startEdge = -1, event = -1;
          _around(a, [&](int ti, int tj) {
            const int u = t[ti].v[(tj + 1) % 3], w = t[ti].v[(tj + 2) % 3];
            const int ou = _orient(a, u, b), ow = _orient(a, w, b);
            if(ou < 0 || ow > 0) return false;
            if(ou == 0)
              event = u;
            else if(ow == 0)
              event = w;
            else {
              start = ti;
              startEdge = (tj + 1) % 3;
            }
            return true;
          });
          // the edges crossed (their vertex on the right of ab first), to a
          // vertex on ab or a constraint crossed
          std::vector<std::pair<int, int> > crossed;
          int crossT = -1, crossJ = -1;
          if(event < 0) {
            if(start < 0) {
              error = "could not find the direction of a segment";
              return false;
            }
            int ti = start, tj = startEdge;
            while(true) {
              if(t[ti].c[tj] >= 0) {
                crossT = ti;
                crossJ = tj;
                break;
              }
              const int r = t[ti].v[tj], l = t[ti].v[(tj + 1) % 3];
              crossed.push_back({r, l});
              const int u = t[ti].n[tj];
              if(u < 0) {
                error = "a segment going out of its triangle";
                return false;
              }
              const int uj = _at(t[u], l);
              const int x = t[u].v[(uj + 2) % 3];
              if(x == b) {
                event = b;
                break;
              }
              const int ox = _orient(a, b, x);
              if(ox == 0) {
                event = x;
                break;
              }
              ti = u;
              tj = ox < 0 ? (uj + 2) % 3 : (uj + 1) % 3;
            }
          }
          if(crossT >= 0) {
            // the point where it crosses a constraint
            const int g = _a._crossing(_sources[s],
                                       _sources[t[crossT].c[crossJ]], _plane,
                                       _k);
            if(g < 0) {
              error = _a.error;
              return false;
            }
            if(_local.count(g)) {
              error = "two segments crossing at a point already there";
              return false;
            }
            _splitEdge(crossT, crossJ, vertex(g));
            continue;
          }
          if(!_recover(a, event, crossed) || !_edge(a, event, i, j)) {
            error = "could not recover a segment";
            return false;
          }
          _mark(i, j, s);
          a = event;
        }
        return true;
      }

      // the Delaunay criterion everywhere but on the constraints
      void finish()
      {
        std::vector<std::pair<int, int> > all;
        for(int i = 0; i < (int)t.size(); i++)
          for(int j = 0; j < 3; j++)
            if(t[i].n[j] > i) all.push_back({i, j});
        _legalize(all);
      }

      // the triangle on the left of the edge from ga to gb (-1 if none)
      int leftOf(int ga, int gb) const
      {
        const int a = local(ga), b = local(gb);
        int i, j;
        if(a < 0 || b < 0 || !_directed(a, b, i, j)) return -1;
        return i;
      }
    };

    // the point where two constraints cross in a plane (that of the triangle
    // plane, projected along k)
    int _crossing(int s1, int s2, int plane, int k)
    {
      if(s1 >= 0 && s2 >= 0) return _add(TPI, plane, s1, s2);
      if(s1 < 0 && s2 < 0) {
        const std::array<int, 2> &e1 = _edges[-s1 - 1], &e2 = _edges[-s2 - 1];
        return _add(LPI2, e1[0], e1[1], e2[0], e2[1], k);
      }
      if(s1 < 0) std::swap(s1, s2);
      const std::array<int, 2> &e = _edges[-s2 - 1];
      return _add(LPI3, e[0], e[1], s1);
    }

    void _output(Triangulation &T, int t, bool turned)
    {
      for(auto &tri : T.t) {
        Face f;
        f.t = t;
        f.v[0] = T.global(tri.v[0]);
        f.v[1] = T.global(tri.v[turned ? 2 : 1]);
        f.v[2] = T.global(tri.v[turned ? 1 : 2]);
        _faces.push_back(f);
      }
    }

    bool _single(Triangulation &T, int t)
    {
      T.reset(t);
      const int *v = &_tri[3 * t];
      T.start({{v[0], v[1], v[2]}});
      for(int i = 0; i < 3; i++)
        for(int g : _onEdge[_triEdges[3 * t + i]])
          if(!T.insert(g)) return false;
      for(int g : _inside[t])
        if(!T.insert(g)) return false;
      for(auto &s : _segments[t])
        if(!T.constrain(s.a, s.b, s.source)) return false;
      T.finish();
      _output(T, t, false);
      return true;
    }

    bool _group(Triangulation &T, const std::vector<int> &members)
    {
      const int plane = members[0], k = _axis[plane], o = _orientation[plane];
      T.reset(plane);
      // the convex hull of the vertices, a fan
      std::vector<int> v;
      for(int m : members)
        for(int i = 0; i < 3; i++) v.push_back(_tri[3 * m + i]);
      std::sort(v.begin(), v.end());
      v.erase(std::unique(v.begin(), v.end()), v.end());
      const int i = (k + 1) % 3, j = (k + 2) % 3;
      std::sort(v.begin(), v.end(), [&](int a, int b) {
        return X(a)[i] < X(b)[i] || (X(a)[i] == X(b)[i] && X(a)[j] < X(b)[j]);
      });
      std::vector<int> hull;
      for(int pass = 0; pass < 2; pass++) {
        const std::size_t base = hull.size();
        for(std::size_t l = 0; l < v.size(); l++) {
          const int p = pass ? v[v.size() - 1 - l] : v[l];
          while(hull.size() >= base + 2 &&
                orient2d(X(hull[hull.size() - 2]), X(hull.back()), X(p), k) <=
                  0)
            hull.pop_back();
          hull.push_back(p);
        }
        hull.pop_back();
      }
      if(o < 0) std::reverse(hull.begin(), hull.end());
      std::vector<std::array<int, 3> > fan;
      for(std::size_t l = 1; l + 1 < hull.size(); l++)
        fan.push_back({hull[0], hull[l], hull[l + 1]});
      T.start(fan);
      // the points
      std::vector<int> edges;
      for(int m : members)
        for(int l = 0; l < 3; l++) edges.push_back(_triEdges[3 * m + l]);
      std::sort(edges.begin(), edges.end());
      edges.erase(std::unique(edges.begin(), edges.end()), edges.end());
      for(int g : v)
        if(!T.insert(g)) return false;
      for(int e : edges)
        for(int g : _onEdge[e])
          if(!T.insert(g)) return false;
      for(int m : members)
        for(int g : _inside[m])
          if(!T.insert(g)) return false;
      // the constraints: the edges, the segments
      for(int e : edges)
        if(!T.constrain(_edges[e][0], _edges[e][1], -e - 1)) return false;
      for(int m : members)
        for(auto &s : _segments[m])
          if(!T.constrain(s.a, s.b, s.source)) return false;
      T.finish();
      // the triangles in each one: from its edges, inside them
      std::vector<char> in(T.t.size());
      for(int m : members) {
        const int *w = &_tri[3 * m];
        const bool turned = o * orient2d(X(w[0]), X(w[1]), X(w[2]), k) < 0;
        std::unordered_set<uint64_t> boundary;
        auto key = [&](int a, int b) {
          return (uint64_t)(uint32_t)std::min(a, b) << 32 |
                 (uint32_t)std::max(a, b);
        };
        int seed = -1;
        for(int l = 0; l < 3; l++) {
          const int e = _triEdges[3 * m + l];
          std::vector<int> chain(1, w[l]);
          const std::vector<int> &on = _onEdge[e];
          if(w[l] == _edges[e][0])
            chain.insert(chain.end(), on.begin(), on.end());
          else
            chain.insert(chain.end(), on.rbegin(), on.rend());
          chain.push_back(w[(l + 1) % 3]);
          for(std::size_t c = 0; c + 1 < chain.size(); c++) {
            const int a = T.local(chain[c]), b = T.local(chain[c + 1]);
            boundary.insert(key(a, b));
            if(seed < 0)
              seed = turned ? T.leftOf(chain[c + 1], chain[c]) :
                              T.leftOf(chain[c], chain[c + 1]);
          }
        }
        if(seed < 0) {
          error = "could not find the triangles of a triangle";
          return false;
        }
        std::fill(in.begin(), in.end(), 0);
        std::vector<int> stack(1, seed);
        in[seed] = 1;
        while(!stack.empty()) {
          const int c = stack.back();
          stack.pop_back();
          const auto &tri = T.t[c];
          Face f;
          f.t = m;
          f.v[0] = T.global(tri.v[0]);
          f.v[1] = T.global(tri.v[turned ? 2 : 1]);
          f.v[2] = T.global(tri.v[turned ? 1 : 2]);
          _faces.push_back(f);
          for(int l = 0; l < 3; l++) {
            const int n = tri.n[l];
            if(n < 0 || in[n] ||
               boundary.count(key(tri.v[l], tri.v[(l + 1) % 3])))
              continue;
            in[n] = 1;
            stack.push_back(n);
          }
        }
      }
      return true;
    }

    void _triangulateAll()
    {
      std::map<int, std::vector<int> > groups;
      for(int t = 0; t < _nt; t++) groups[_root(t)].push_back(t);
      Triangulation T(*this);
      for(auto &g : groups) {
        if(g.second.size() < 2) {
          const int t = g.second[0];
          bool touched = !_inside[t].empty() || !_segments[t].empty();
          for(int i = 0; i < 3 && !touched; i++)
            if(!_onEdge[_triEdges[3 * t + i]].empty()) touched = true;
          if(!touched) {
            Face f;
            f.t = t;
            for(int i = 0; i < 3; i++) f.v[i] = _tri[3 * t + i];
            _faces.push_back(f);
            continue;
          }
          if(!_single(T, t)) {
            error = "could not triangulate an intersected triangle (" +
                    T.error + ")";
            return;
          }
        }
        else if(!_group(T, g.second)) {
          if(error.empty())
            error = "could not triangulate overlapping triangles (" +
                    T.error + ")";
          return;
        }
      }
    }

    // ---- the winding numbers ----

    // the normal of a triangle, approximate and exact
    void _normal(int t, Approx n[3]) const
    {
      const int *v = &_tri[3 * t];
      Approx a[3], b[3];
      for(int k = 0; k < 3; k++) {
        a[k] = exact(X(v[1])[k]) - exact(X(v[0])[k]);
        b[k] = exact(X(v[2])[k]) - exact(X(v[0])[k]);
      }
      n[0] = a[1] * b[2] - a[2] * b[1];
      n[1] = a[2] * b[0] - a[0] * b[2];
      n[2] = a[0] * b[1] - a[1] * b[0];
    }

    void _normal(int t, Expansion n[3]) const
    {
      const int *v = &_tri[3 * t];
      for(int k = 0; k < 3; k++)
        n[k] = compress(orient2dExact(X(v[0]), X(v[1]), X(v[2]), k));
    }

    // the winding numbers of the inputs at the point p, by the triangles
    // crossed by the ray from p along -k (p moved by (0, e, e^2) on the axes
    // k + 1, k + 2 when it hits edges)
    Winding _ray(int p, int k) const
    {
      const int i = (k + 1) % 3, j = (k + 2) % 3;
      const Point &P = _points[p];
      std::array<double, 6> box;
      box[k] = -1e300;
      box[3 + k] = P.x[k] + P.e[k];
      box[i] = P.x[i] - P.e[i];
      box[3 + i] = P.x[i] + P.e[i];
      box[j] = P.x[j] - P.e[j];
      box[3 + j] = P.x[j] + P.e[j];
      std::map<int, int> w;
      _tree.query(box, [&](int u) {
        const int *v = &_tri[3 * u];
        const int o = orient2d(X(v[0]), X(v[1]), X(v[2]), k);
        if(!o) return;
        const int s = _side(u, p);
        if(-s * o <= 0) return;
        for(int l = 0; l < 3; l++) {
          const int a = v[l], b = v[(l + 1) % 3];
          int ol = _orient2d(a, b, p, k);
          if(!ol) {
            ol = sign(X(a)[j] - X(b)[j]);
            if(!ol) ol = sign(X(b)[i] - X(a)[i]);
          }
          if(ol != o) return;
        }
        w[_label[u]] -= o;
      });
      Winding r;
      for(auto &l : w)
        if(l.second) r.push_back(l);
      return r;
    }
  };

  bool Arrangement::winding(double thickness, std::vector<double> &oxyz,
                            std::vector<int> &otri, std::vector<int> &birth,
                            std::vector<std::vector<int> > &sets,
                            std::vector<std::array<int, 2> > &sides,
                            std::size_t &merged)
  {
    merged = 0;
    // the triangles at the same place: one, the inputs in its multiplicity
    // (as oriented as the first one, or turned over)
    const int nf = (int)_faces.size();
    std::vector<std::array<int, 4> > keys(nf);
    for(int f = 0; f < nf; f++) {
      std::array<int, 3> v = {
        {_faces[f].v[0], _faces[f].v[1], _faces[f].v[2]}};
      std::sort(v.begin(), v.end());
      keys[f] = {v[0], v[1], v[2], f};
    }
    std::sort(keys.begin(), keys.end());
    struct Unique {
      int v[3], t;
      Winding m;
    };
    std::vector<Unique> unique;
    std::vector<int> uniqueOf(nf);
    std::vector<char> turnedOf(nf);
    for(int i = 0; i < nf;) {
      int j = i;
      while(j < nf && keys[j][0] == keys[i][0] && keys[j][1] == keys[i][1] &&
            keys[j][2] == keys[i][2])
        j++;
      const Face &r = _faces[keys[i][3]];
      Unique U;
      for(int l = 0; l < 3; l++) U.v[l] = r.v[l];
      U.t = r.t;
      std::map<int, int> m;
      for(int l = i; l < j; l++) {
        const Face &f = _faces[keys[l][3]];
        int o = 0;
        while(f.v[o] != r.v[0]) o++;
        const bool turned = f.v[(o + 1) % 3] != r.v[1];
        m[_label[f.t]] += turned ? -1 : 1;
        uniqueOf[keys[l][3]] = (int)unique.size();
        turnedOf[keys[l][3]] = turned;
      }
      for(auto &l : m)
        if(l.second) U.m.push_back(l);
      unique.push_back(U);
      i = j;
    }
    const int nu = (int)unique.size();
    // the sides of the triangles (2 u behind, 2 u + 1 in front): those in the
    // same cell around their edges one (union-find)
    std::vector<int> parent(2 * nu);
    std::iota(parent.begin(), parent.end(), 0);
    auto root = [&](int x) {
      while(parent[x] != x) x = parent[x] = parent[parent[x]];
      return x;
    };
    auto unite = [&](int x, int y) {
      x = root(x);
      y = root(y);
      if(x != y) parent[std::max(x, y)] = std::min(x, y);
    };
    std::vector<std::array<int, 4> > edges;
    edges.reserve(3 * nu);
    for(int u = 0; u < nu; u++)
      for(int l = 0; l < 3; l++) {
        const int a = unique[u].v[l], b = unique[u].v[(l + 1) % 3];
        if(a < b)
          edges.push_back({a, b, u, 1});
        else
          edges.push_back({b, a, u, -1});
      }
    std::sort(edges.begin(), edges.end());
    // the side of a triangle after it turning around its edge ab (a < b)
    // counterclockwise (seen from b), the one before it
    auto after = [](int u, int s) { return s > 0 ? 2 * u + 1 : 2 * u; };
    auto before = [](int u, int s) { return s > 0 ? 2 * u : 2 * u + 1; };
    struct Around {
      int u, s;
      Approx a[3];
      bool exact = false;
      Expansion e[3];
    };
    std::vector<Around> around;
    for(std::size_t i = 0; i < edges.size();) {
      std::size_t j = i;
      while(j < edges.size() && edges[j][0] == edges[i][0] &&
            edges[j][1] == edges[i][1])
        j++;
      const int n = (int)(j - i);
      if(n == 1) {
        unite(2 * edges[i][2], 2 * edges[i][2] + 1);
        i = j;
        continue;
      }
      around.clear();
      for(std::size_t l = i; l < j; l++) {
        Around A;
        A.u = edges[l][2];
        A.s = edges[l][3];
        around.push_back(A);
      }
      if(n > 2) {
        // their order around the edge, by the normals of their planes (s
        // their direction, perpendicular to ab) around the edge e0 = n0 x
        // n1, ab along s e0
        const int a = edges[i][0], b = edges[i][1];
        for(Around &A : around) {
          _normal(unique[A.u].t, A.a);
          for(int k = 0; k < 3; k++) A.a[k] = A.a[k] * exact((double)A.s);
        }
        auto exactOf = [&](Around &A) -> Expansion * {
          if(!A.exact) {
            _normal(unique[A.u].t, A.e);
            if(A.s < 0)
              for(int k = 0; k < 3; k++)
                for(double &c : A.e[k]) c = -c;
            A.exact = true;
          }
          return A.e;
        };
        Approx e0a[3];
        Expansion e0[3];
        bool found = false;
        for(std::size_t l = 1; l < around.size() && !found; l++) {
          const Expansion *p = exactOf(around[0]), *q = exactOf(around[l]);
          e0[0] = sub(product(p[1], q[2]), product(p[2], q[1]));
          e0[1] = sub(product(p[2], q[0]), product(p[0], q[2]));
          e0[2] = sub(product(p[0], q[1]), product(p[1], q[0]));
          if(!sign(e0[0]) && !sign(e0[1]) && !sign(e0[2])) continue;
          const Approx *x = around[0].a, *y = around[l].a;
          e0a[0] = x[1] * y[2] - x[2] * y[1];
          e0a[1] = x[2] * y[0] - x[0] * y[2];
          e0a[2] = x[0] * y[1] - x[1] * y[0];
          found = true;
        }
        if(!found) {
          error = "triangles in the same plane on the same side of an edge";
          return false;
        }
        int m = -1;
        for(int k = 0; k < 3; k++)
          if(sign(e0[k]) &&
             (m < 0 || std::abs(estimate(e0[k])) > std::abs(estimate(e0[m]))))
            m = k;
        const int sigma = sign(e0[m]) * _compareAxis(b, a, m);
        if(!sigma) {
          error = "an edge of zero length";
          return false;
        }
        // (p x q) . e0, p . q
        auto det = [&](Around &P, Around &Q) {
          const Approx *p = P.a, *q = Q.a;
          const Approx d = (p[1] * q[2] - p[2] * q[1]) * e0a[0] +
                           (p[2] * q[0] - p[0] * q[2]) * e0a[1] +
                           (p[0] * q[1] - p[1] * q[0]) * e0a[2];
          if(certain(d)) return sign(d.v);
          const Expansion *x = exactOf(P), *y = exactOf(Q);
          return sign(sum(sum(product(sub(product(x[1], y[2]),
                                          product(x[2], y[1])),
                                      e0[0]),
                              product(sub(product(x[2], y[0]),
                                          product(x[0], y[2])),
                                      e0[1])),
                          product(sub(product(x[0], y[1]),
                                      product(x[1], y[0])),
                                  e0[2])));
        };
        auto dot = [&](Around &P, Around &Q) {
          const Approx *p = P.a, *q = Q.a;
          const Approx d = p[0] * q[0] + p[1] * q[1] + p[2] * q[2];
          if(certain(d)) return sign(d.v);
          const Expansion *x = exactOf(P), *y = exactOf(Q);
          return sign(sum(sum(product(x[0], y[0]), product(x[1], y[1])),
                          product(x[2], y[2])));
        };
        // the angles from the first one: 0, ]0, pi[, pi, ]pi, 2 pi[
        std::vector<int> category(n, 0);
        bool overlapping = false;
        for(int l = 1; l < n; l++) {
          const int c = sigma * det(around[0], around[l]);
          if(c > 0)
            category[l] = 1;
          else if(c < 0)
            category[l] = 3;
          else if(dot(around[0], around[l]) < 0)
            category[l] = 2;
          else
            overlapping = true;
        }
        std::vector<int> order(n);
        std::iota(order.begin(), order.end(), 0);
        std::sort(order.begin(), order.end(), [&](int x, int y) {
          if(category[x] != category[y]) return category[x] < category[y];
          if(category[x] == 0 || category[x] == 2) return false;
          const int c = sigma * det(around[x], around[y]);
          if(!c) overlapping = true;
          return c > 0;
        });
        if(overlapping) {
          error = "triangles of the arrangement overlapping each other";
          return false;
        }
        for(int l = 1; l < n; l++)
          if(category[order[l]] == category[order[l - 1]] &&
             (category[order[l]] == 0 || category[order[l]] == 2)) {
            error = "triangles of the arrangement overlapping each other";
            return false;
          }
        std::vector<Around> sorted;
        for(int l : order) sorted.push_back(around[l]);
        around.swap(sorted);
      }
      for(int l = 0; l < n; l++) {
        const Around &F = around[l], &G = around[(l + 1) % n];
        unite(after(F.u, F.s), before(G.u, G.s));
      }
      i = j;
    }
    // the cells (classes of sides), the sides in them
    std::vector<int> cellOf(2 * nu), cells;
    std::vector<int> start;
    {
      std::unordered_map<int, int> index;
      for(int x = 0; x < 2 * nu; x++) {
        const int r = root(x);
        auto it = index.insert({r, (int)index.size()});
        cellOf[x] = it.first->second;
      }
      const int nc = (int)index.size();
      start.assign(nc + 1, 0);
      for(int x = 0; x < 2 * nu; x++) start[cellOf[x] + 1]++;
      for(int c = 0; c < nc; c++) start[c + 1] += start[c];
      cells.resize(2 * nu);
      std::vector<int> fill(start.begin(), start.end() - 1);
      for(int x = 0; x < 2 * nu; x++) cells[fill[cellOf[x]]++] = x;
    }
    const int nc = (int)start.size() - 1;
    // the triangles of the arrangement in each input triangle
    std::vector<int> facesStart(_nt + 1, 0), facesOf(nf);
    for(int f = 0; f < nf; f++) facesStart[_faces[f].t + 1]++;
    for(int t = 0; t < _nt; t++) facesStart[t + 1] += facesStart[t];
    {
      std::vector<int> fill(facesStart.begin(), facesStart.end() - 1);
      for(int f = 0; f < nf; f++) facesOf[fill[_faces[f].t]++] = f;
    }
    // the winding numbers in each cell: in one of each set of cells next to
    // each other by a ray from a point inside a triangle, the others across
    // the triangles
    std::vector<Winding> w(nc);
    std::vector<char> known(nc, 0);
    const int weights[][3] = {{1, 1, 1}, {1, 1, 2}, {1, 2, 1}, {2, 1, 1},
                              {1, 2, 3}, {3, 2, 1}, {2, 3, 1}, {1, 3, 2},
                              {3, 1, 2}, {2, 1, 3}, {1, 1, 5}, {1, 5, 1},
                              {5, 1, 1}, {2, 3, 7}, {7, 3, 2}, {3, 7, 2}};
    for(int u = 0; u < nu; u++) {
      if(known[cellOf[2 * u]]) continue;
      const int t = unique[u].t, k = _axis[t], o = _orientation[t];
      int seed = -1;
      Winding ws;
      for(auto &wt : weights) {
        Point P;
        P.type = BARY;
        P.d[0] = t;
        P.d[1] = wt[0];
        P.d[2] = wt[1];
        P.d[3] = wt[2];
        P.d[4] = 0;
        std::array<Expansion, 4> h;
        if(!_round(P, h)) continue;
        const int p = (int)_points.size();
        _points.push_back(P);
        _exact[p] = h;
        for(int l = facesStart[t]; l < facesStart[t + 1] && seed < 0; l++) {
          const Face &f = _faces[facesOf[l]];
          bool inside = true;
          for(int i = 0; i < 3 && inside; i++)
            if(o * _orient2d(f.v[i], f.v[(i + 1) % 3], p, k) <= 0)
              inside = false;
          if(!inside) continue;
          // the side of f along -k: in front of it if its normal is along -k
          ws = _ray(p, k);
          const int side = (o < 0) != (bool)turnedOf[facesOf[l]] ? 1 : 0;
          seed = cellOf[2 * uniqueOf[facesOf[l]] + side];
        }
        _exact.erase(p);
        _points.pop_back();
        if(seed >= 0) break;
      }
      if(seed < 0) {
        error = "could not find a point inside a triangle";
        return false;
      }
      if(known[seed]) {
        error = "inconsistent winding numbers";
        return false;
      }
      w[seed] = ws;
      known[seed] = 1;
      std::vector<int> stack(1, seed);
      while(!stack.empty()) {
        const int c = stack.back();
        stack.pop_back();
        for(int l = start[c]; l < start[c + 1]; l++) {
          const int x = cells[l], f = x / 2;
          // across the triangle: w in front = w behind - m
          const Winding v = combined(w[c], unique[f].m, x % 2 ? 1 : -1);
          const int d = cellOf[x ^ 1];
          if(!known[d]) {
            w[d] = v;
            known[d] = 1;
            stack.push_back(d);
          }
          else if(w[d] != v) {
            error = "the winding numbers of the inputs are not consistent (an "
                    "input is not closed)";
            return false;
          }
        }
      }
    }
    // the thin cells: their volume and area (from the triangles around them,
    // relative to one of their points), those of their neighbors; each one
    // (by increasing volume) in the neighbor it shares most of its area with
    std::vector<int> into(nc);
    std::iota(into.begin(), into.end(), 0);
    auto finalCell = [&](int c) {
      while(into[c] != c) c = into[c] = into[into[c]];
      return c;
    };
    if(thickness > 0.) {
      std::vector<int> origin(nc, -1);
      std::vector<double> volume(nc, 0.), area(nc, 0.), faceArea(nu, 0.);
      auto X3 = [&](int p) { return _points[p].x; };
      for(int u = 0; u < nu; u++) {
        const double *a = X3(unique[u].v[0]), *b = X3(unique[u].v[1]),
                     *c = X3(unique[u].v[2]);
        double e1[3], e2[3];
        for(int k = 0; k < 3; k++) {
          e1[k] = b[k] - a[k];
          e2[k] = c[k] - a[k];
        }
        const double n[3] = {e1[1] * e2[2] - e1[2] * e2[1],
                             e1[2] * e2[0] - e1[0] * e2[2],
                             e1[0] * e2[1] - e1[1] * e2[0]};
        faceArea[u] = 0.5 * std::sqrt(n[0] * n[0] + n[1] * n[1] + n[2] * n[2]);
        for(int side = 0; side < 2; side++) {
          const int cell = cellOf[2 * u + side];
          if(cell == cellOf[2 * u + 1 - side]) continue;
          if(origin[cell] < 0) origin[cell] = unique[u].v[0];
          const double *o = X3(origin[cell]);
          double p[3][3];
          for(int k = 0; k < 3; k++) {
            p[0][k] = a[k] - o[k];
            p[1][k] = b[k] - o[k];
            p[2][k] = c[k] - o[k];
          }
          // (the triangle points out of the cell behind it)
          const double det = p[0][0] * (p[1][1] * p[2][2] - p[1][2] * p[2][1]) -
                             p[0][1] * (p[1][0] * p[2][2] - p[1][2] * p[2][0]) +
                             p[0][2] * (p[1][0] * p[2][1] - p[1][1] * p[2][0]);
          volume[cell] += (side ? -det : det) / 6.;
          area[cell] += faceArea[u];
        }
      }
      std::vector<int> thin;
      for(int c = 0; c < nc; c++)
        if(volume[c] > 0. && 2. * volume[c] < thickness * area[c])
          thin.push_back(c);
      std::sort(thin.begin(), thin.end(),
                [&](int a, int b) { return volume[a] < volume[b]; });
      for(int c : thin) {
        std::map<int, double> shared;
        for(int l = start[c]; l < start[c + 1]; l++) {
          const int x = cells[l], d = finalCell(cellOf[x ^ 1]);
          if(d != c) shared[d] += faceArea[x / 2];
        }
        int target = -1;
        for(auto &d : shared)
          if(target < 0 || d.second > shared[target]) target = d.first;
        if(target < 0) continue;
        into[c] = target;
        merged++;
      }
    }
    // the inputs inside the cells on both sides of the triangles
    sets.assign(1, std::vector<int>());
    std::map<std::vector<int>, int> setIndex;
    setIndex[std::vector<int>()] = 0;
    std::vector<int> setOf(nc);
    for(int c = 0; c < nc; c++) {
      std::vector<int> s;
      for(auto &l : w[finalCell(c)]) s.push_back(l.first);
      auto it = setIndex.insert({s, (int)sets.size()});
      if(it.second) sets.push_back(s);
      setOf[c] = it.first->second;
    }
    oxyz.resize(3 * _points.size());
    for(std::size_t p = 0; p < _points.size(); p++)
      for(int k = 0; k < 3; k++) oxyz[3 * p + k] = _points[p].x[k];
    otri.clear();
    birth.clear();
    sides.clear();
    for(int u = 0; u < nu; u++) {
      const std::array<int, 2> s = {
        {setOf[cellOf[2 * u]], setOf[cellOf[2 * u + 1]]}};
      if(s[0] == s[1]) continue;
      for(int l = 0; l < 3; l++) otri.push_back(unique[u].v[l]);
      birth.push_back(_birth[unique[u].t]);
      sides.push_back(s);
    }
    return true;
  }

} // namespace

bool haveMeshArrangement() { return true; }

bool meshArrangement(const std::vector<double> &xyz,
                     const std::vector<int> &tri,
                     const std::vector<int> &label, int labels,
                     double thickness, std::vector<double> &oxyz,
                     std::vector<int> &otri, std::vector<int> &birth,
                     std::vector<std::vector<int> > &sets,
                     std::vector<std::array<int, 2> > &sides,
                     std::size_t &merged, std::string &error)
{
  for(int l : label)
    if(l < 0 || l >= labels) {
      error = "a label out of range";
      return false;
    }
  Arrangement a;
  if(!a.compute(xyz, tri, label) ||
     !a.winding(thickness, oxyz, otri, birth, sets, sides, merged)) {
    error = a.error;
    return false;
  }
  return true;
}
