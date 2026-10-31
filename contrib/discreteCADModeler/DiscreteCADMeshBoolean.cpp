// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>
#include <deque>
#include <functional>
#include <iterator>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
#include "DiscreteCADMeshBoolean.h"
#include "meshPolyMesh.h"
#include "robustPredicates.h"

namespace {

  // exact arithmetic: expansions (Shewchuk), sums of nonoverlapping
  // components by increasing magnitude, of the sign of the last one, with
  // the routines of gmsh's robust predicates

  typedef std::vector<double> Expansion;

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
    return h;
  }

  inline int sign(const Expansion &e)
  {
    return e.back() > 0. ? 1 : e.back() < 0. ? -1 : 0;
  }

  inline int sign(double a) { return a > 0. ? 1 : a < 0. ? -1 : 0; }

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

  // a / b, b certainly not zero
  inline Approx divide(Approx a, Approx b)
  {
    const double v = a.v / b.v;
    return {v, (a.e + std::abs(v) * b.e) / (std::abs(b.v) - b.e) +
                 unit * std::abs(v)};
  }

  // the orientations of points: orient3d positive if d is below the plane of
  // a, b, c (seen counterclockwise from above), orient2d positive if a, b, c
  // are counterclockwise in the projection along the axis k, i.e. on the
  // axes k + 1, k + 2 (that of positive normals along k)

  // of input points: the exact signs and values of gmsh's robust predicates
  // (orient3d without the static filter that depends on the coordinate
  // ranges given to exactinit)

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

  // of points with approximate coordinates

  Approx orient3dApprox(const Approx *a, const Approx *b, const Approx *c,
                        const Approx *d)
  {
    Approx ad[3], bd[3], cd[3];
    for(int k = 0; k < 3; k++) {
      ad[k] = a[k] - d[k];
      bd[k] = b[k] - d[k];
      cd[k] = c[k] - d[k];
    }
    return ad[0] * (bd[1] * cd[2] - bd[2] * cd[1]) -
           ad[1] * (bd[0] * cd[2] - bd[2] * cd[0]) +
           ad[2] * (bd[0] * cd[1] - bd[1] * cd[0]);
  }

  Approx orient2dApprox(const Approx *a, const Approx *b, const Approx *c,
                        int k)
  {
    const int i = (k + 1) % 3, j = (k + 2) % 3;
    return (a[i] - c[i]) * (b[j] - c[j]) - (a[j] - c[j]) * (b[i] - c[i]);
  }

  // the simplices of the operands: their dimension in the 2 high bits and
  // their index (vertices, edges and triangles of A, then those of B)

  inline uint32_t simplex(int dim, int index)
  {
    return (uint32_t)dim << 30 | (uint32_t)index;
  }

  inline int dimension(uint32_t s) { return (int)(s >> 30); }

  inline int index(uint32_t s) { return (int)(s & 0x3fffffffu); }

  // an intersection point: the simplices of A and of B in the relative
  // interiors of which it lies
  inline uint64_t label(uint32_t a, uint32_t b)
  {
    return (uint64_t)a << 32 | b;
  }

  // a point on the segment pq of input vertices (p < q), p + a / (a - b) (q -
  // p), a and b the orientations of p and q relative to the plane of the
  // input vertices r, s, t, or, if t < 0, relative to the line rs in the
  // projection along the axis -t - 1
  struct Ratio {
    int p, q, r, s, t;
  };

  inline uint64_t edgeKey(int a, int b)
  {
    return (uint64_t)(uint32_t)a << 32 | (uint32_t)b;
  }

  // a bounding volume hierarchy of boxes
  class BoxTree {
    struct Node {
      double lo[3], hi[3];
      int left, right, first, count;
    };
    std::vector<Node> _nodes;
    std::vector<int> _items;
    const std::vector<std::array<double, 6> > *_boxes;
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

  class MeshBoolean {
  public:
    std::string error;

  private:
    // the input: the vertices and the triangles of A, then those of B
    std::vector<double> _x;
    std::vector<int> _tri;
    int _nvA, _ntA, _nv, _nt;
    // the edges: their vertices (the smallest first), their 2 triangles
    std::vector<std::array<int, 2> > _edges, _edgeTriangles;
    std::vector<int> _triEdges; // 3 per triangle: edge (v_k, v_k+1)
    int _neA;
    // the triangles around the vertices
    std::vector<int> _vtStart, _vt;
    // the projection of the triangles (the axis of their largest normal
    // component) and its orientation
    std::vector<int> _axis, _orientation;
    // the new points (their ids after those of the input vertices)
    struct Point {
      uint64_t label;
      Ratio along[2];
      int nAlong;
      Approx c[3];
      mutable bool exact = false;
      mutable Expansion h[4];
    };
    std::vector<Point> _points;
    std::unordered_map<uint64_t, int> _pointOfLabel;
    // the vertices of B at vertices of A
    std::vector<int> _alias;
    // the input vertices on the other operand, with their labels
    std::vector<char> _onOther;
    std::vector<uint64_t> _vertexLabel;
    // the flat regions of the triangles: connected coplanar triangles
    std::vector<int> _region;
    // the triangles of zero area (rounded), left out of the intersections
    std::vector<char> _degenerate;
    // the points on the edges, inside the triangles, the constraints in the
    // triangles (with the triangle of the other operand they lie in)
    struct OnEdge {
      int point;
      Ratio along;
    };
    std::vector<std::vector<OnEdge> > _onEdge;
    std::vector<std::vector<int> > _inside;
    struct Constraint {
      int a, b, other;
    };
    std::vector<std::vector<Constraint> > _constraints;
    // the final triangles of each operand, the triangles of the other
    // operand along their edges (-1 if none)
    struct Final {
      int v[3], birth, along[3];
    };
    std::vector<Final> _final[2];
    std::vector<std::vector<int> > _alongs;

    const double *X(int v) const { return &_x[3 * v]; }

    bool _inA(int t) const { return t < _ntA; }

    void _coords(int p, Approx c[3]) const
    {
      if(p < _nv)
        for(int k = 0; k < 3; k++) c[k] = exact(_x[3 * p + k]);
      else
        for(int k = 0; k < 3; k++) c[k] = _points[p - _nv].c[k];
    }

    // the orientations defining a ratio, approximate and exact
    void _orientations(const Ratio &r, Approx &a, Approx &b) const
    {
      Approx P[3], Q[3], R[3], S[3], T[3];
      _coords(r.p, P);
      _coords(r.q, Q);
      _coords(r.r, R);
      _coords(r.s, S);
      if(r.t >= 0) {
        _coords(r.t, T);
        a = orient3dApprox(R, S, T, P);
        b = orient3dApprox(R, S, T, Q);
      }
      else {
        a = orient2dApprox(R, S, P, -r.t - 1);
        b = orient2dApprox(R, S, Q, -r.t - 1);
      }
    }

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

    // the homogeneous coordinates of a point, exact
    void _homogeneous(int p, Expansion h[4]) const
    {
      if(p < _nv) {
        for(int k = 0; k < 3; k++) h[k] = Expansion(1, _x[3 * p + k]);
        h[3] = Expansion(1, 1.);
        return;
      }
      const Point &n = _points[p - _nv];
      if(!n.exact) {
        Expansion a, b;
        _orientations(n.along[0], a, b);
        for(int k = 0; k < 3; k++)
          n.h[k] =
            sub(scale(a, X(n.along[0].q)[k]), scale(b, X(n.along[0].p)[k]));
        n.h[3] = sub(a, b);
        n.exact = true;
      }
      for(int k = 0; k < 4; k++) h[k] = n.h[k];
    }

    // the orientation of 3 points (input vertices or new points) in the
    // projection along the axis k
    int _orient2d(int a, int b, int c, int k) const
    {
      if(a < _nv && b < _nv && c < _nv) return orient2d(X(a), X(b), X(c), k);
      Approx A[3], B[3], C[3];
      _coords(a, A);
      _coords(b, B);
      _coords(c, C);
      const Approx d = orient2dApprox(A, B, C, k);
      if(certain(d)) return sign(d.v);
      if(_collinear(a, b, c)) return 0;
      Expansion ha[4], hb[4], hc[4];
      _homogeneous(a, ha);
      _homogeneous(b, hb);
      _homogeneous(c, hc);
      const int u = (k + 1) % 3, v = (k + 2) % 3;
      const Expansion det =
        sum(sub(product(ha[u], sub(product(hb[v], hc[3]),
                                   product(hb[3], hc[v]))),
                product(ha[v], sub(product(hb[u], hc[3]),
                                   product(hb[3], hc[u])))),
            product(ha[3],
                    sub(product(hb[u], hc[v]), product(hb[v], hc[u]))));
      return sign(det) * sign(ha[3]) * sign(hb[3]) * sign(hc[3]);
    }

    // the simplices of A and B a point lies in (-1 if none)
    void _support(int p, int64_t s[2]) const
    {
      s[0] = s[1] = -1;
      if(p >= _nv) {
        const uint64_t l = _points[p - _nv].label;
        s[0] = (uint32_t)(l >> 32);
        s[1] = (uint32_t)l;
        return;
      }
      s[p < _nvA ? 0 : 1] = simplex(0, p);
      if(_onOther[p]) {
        const uint64_t l = _vertexLabel[p];
        s[p < _nvA ? 1 : 0] = p < _nvA ? (uint32_t)l : (uint32_t)(l >> 32);
      }
    }

    // the flat regions of the triangles around a simplex
    void _regions(uint32_t s, std::vector<int> &r) const
    {
      r.clear();
      if(dimension(s) == 2)
        r.push_back(_region[index(s)]);
      else if(dimension(s) == 1)
        for(int t : _edgeTriangles[index(s)]) r.push_back(_region[t]);
      else
        for(int i = _vtStart[index(s)]; i < _vtStart[index(s) + 1]; i++)
          r.push_back(_region[_vt[i]]);
      std::sort(r.begin(), r.end());
      r.erase(std::unique(r.begin(), r.end()), r.end());
    }

    // collinear by construction: on a same flat region of A and of B (on the
    // line of their planes), or on a same input edge
    bool _collinear(int a, int b, int c) const
    {
      int64_t s[3][2];
      _support(a, s[0]);
      _support(b, s[1]);
      _support(c, s[2]);
      // on a same edge (or its vertices)
      for(int i = 0; i < 3; i++)
        for(int o = 0; o < 2; o++) {
          if(s[i][o] < 0 || dimension((uint32_t)s[i][o]) != 1) continue;
          const int g = index((uint32_t)s[i][o]);
          bool on = true;
          for(int j = 0; j < 3 && on; j++) {
            const int64_t u = s[j][o];
            if(u == s[i][o]) continue;
            if(u < 0 || dimension((uint32_t)u) != 0 ||
               (index((uint32_t)u) != _edges[g][0] &&
                index((uint32_t)u) != _edges[g][1]))
              on = false;
          }
          if(on) return true;
        }
      // on a same flat region of each operand
      std::vector<int> r[3], common[2];
      for(int o = 0; o < 2; o++) {
        for(int i = 0; i < 3; i++) {
          if(s[i][o] < 0) return false;
          _regions((uint32_t)s[i][o], r[i]);
        }
        std::vector<int> ab;
        std::set_intersection(r[0].begin(), r[0].end(), r[1].begin(),
                              r[1].end(), std::back_inserter(ab));
        std::set_intersection(ab.begin(), ab.end(), r[2].begin(), r[2].end(),
                              std::back_inserter(common[o]));
        if(common[o].empty()) return false;
      }
      for(int ra : common[0])
        for(int rb : common[1])
          if(!_coplanar(ra, rb)) return true;
      return false;
    }

    // the side of a point relative to the plane of a triangle: positive
    // below (inside an operand oriented outwards)
    int _side(int t, int z) const
    {
      const int *v = &_tri[3 * t];
      if(z < _nv) return orient3d(X(v[0]), X(v[1]), X(v[2]), X(z));
      Approx V[3][3], Z[3];
      for(int i = 0; i < 3; i++) _coords(v[i], V[i]);
      _coords(z, Z);
      const Approx d = orient3dApprox(V[0], V[1], V[2], Z);
      if(certain(d)) return sign(d.v);
      // orient3d being affine in z
      const Ratio &r = _points[z - _nv].along[0];
      Expansion a, b;
      _orientations(r, a, b);
      const Expansion dp = orient3dExact(X(v[0]), X(v[1]), X(v[2]), X(r.p));
      const Expansion dq = orient3dExact(X(v[0]), X(v[1]), X(v[2]), X(r.q));
      return sign(sub(product(a, dq), product(b, dp))) * sign(sub(a, b));
    }

    // the sign of a1 / (a1 - b1) - a2 / (a2 - b2) for two ratios along the
    // same segment
    int _compare(const Ratio &r1, const Ratio &r2) const
    {
      Approx a1, b1, a2, b2;
      _orientations(r1, a1, b1);
      _orientations(r2, a2, b2);
      const Approx d1 = a1 - b1, d2 = a2 - b2, n = a2 * b1 - a1 * b2;
      if(certain(n) && certain(d1) && certain(d2))
        return sign(n.v) * sign(d1.v) * sign(d2.v);
      Expansion A1, B1, A2, B2;
      _orientations(r1, A1, B1);
      _orientations(r2, A2, B2);
      return sign(sub(product(A2, B1), product(A1, B2))) *
             sign(sub(A1, B1)) * sign(sub(A2, B2));
    }

    // the location of an input vertex in the plane of a triangle: outside
    // (false), or in the relative interior of the simplex loc
    bool _locate(int w, int t, uint32_t &loc) const
    {
      const int *v = &_tri[3 * t];
      const int k = _axis[t], o = _orientation[t];
      int s[3];
      for(int i = 0; i < 3; i++) {
        s[i] = o * orient2d(X(v[i]), X(v[(i + 1) % 3]), X(w), k);
        if(s[i] < 0) return false;
      }
      const int zeros = (s[0] == 0) + (s[1] == 0) + (s[2] == 0);
      if(zeros == 0)
        loc = simplex(2, t);
      else if(zeros == 1) {
        int i = 0;
        while(s[i]) i++;
        loc = simplex(1, _triEdges[3 * t + i]);
      }
      else {
        int i = 0;
        while(s[i] || s[(i + 1) % 3]) i++;
        loc = simplex(0, v[(i + 1) % 3]);
      }
      return true;
    }

    uint64_t _label(uint32_t onEdgeSide, uint32_t onTriangleSide,
                    bool edgeInA) const
    {
      return edgeInA ? label(onEdgeSide, onTriangleSide) :
                       label(onTriangleSide, onEdgeSide);
    }

    // the intersection of the edge e with the triangle t of the other
    // operand, coplanar: in the projection along the axis of t
    int _intersectCoplanar(int e, int t, uint64_t out[2]) const
    {
      const int p = _edges[e][0], q = _edges[e][1];
      const bool edgeInA = e < _neA;
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
      auto endpoint = [&](int i, bool entering, uint64_t &l) {
        uint32_t loc;
        if(i < 0 || (entering && sq[i] == 0) || (!entering && sp[i] == 0)) {
          // an endpoint of pq
          const int w = (i < 0) == entering ? p : q;
          _locate(w, t, loc);
          l = _label(simplex(0, w), loc, edgeInA);
          return;
        }
        const int a = v[i], b = v[(i + 1) % 3];
        if(orient2d(X(p), X(q), X(a), k) == 0)
          l = _label(simplex(1, e), simplex(0, a), edgeInA);
        else if(orient2d(X(p), X(q), X(b), k) == 0)
          l = _label(simplex(1, e), simplex(0, b), edgeInA);
        else
          l = _label(simplex(1, e), simplex(1, _triEdges[3 * t + i]),
                     edgeInA);
      };
      endpoint(enter, true, out[0]);
      endpoint(exit, false, out[1]);
      return out[0] == out[1] ? 1 : 2;
    }

    // the intersection of the edge e with the triangle t of the other
    // operand: 0, 1 or 2 points
    int _intersect(int e, int t, uint64_t out[2]) const
    {
      const int p = _edges[e][0], q = _edges[e][1];
      const bool edgeInA = e < _neA;
      const int *v = &_tri[3 * t];
      const int dp = orient3d(X(v[0]), X(v[1]), X(v[2]), X(p));
      const int dq = orient3d(X(v[0]), X(v[1]), X(v[2]), X(q));
      if(dp * dq > 0) return 0;
      if(!dp && !dq) return _intersectCoplanar(e, t, out);
      uint32_t loc;
      if(!dp || !dq) {
        const int w = dp ? q : p;
        if(!_locate(w, t, loc)) return 0;
        out[0] = _label(simplex(0, w), loc, edgeInA);
        return 1;
      }
      int s[3];
      for(int i = 0; i < 3; i++)
        s[i] = orient3d(X(p), X(q), X(v[i]), X(v[(i + 1) % 3]));
      if((s[0] > 0 || s[1] > 0 || s[2] > 0) &&
         (s[0] < 0 || s[1] < 0 || s[2] < 0))
        return 0;
      const int zeros = (s[0] == 0) + (s[1] == 0) + (s[2] == 0);
      if(zeros == 0)
        loc = simplex(2, t);
      else if(zeros == 1) {
        int i = 0;
        while(s[i]) i++;
        loc = simplex(1, _triEdges[3 * t + i]);
      }
      else {
        int i = 0;
        while(s[i] || s[(i + 1) % 3]) i++;
        loc = simplex(0, v[(i + 1) % 3]);
      }
      out[0] = _label(simplex(1, e), loc, edgeInA);
      return 1;
    }

    // a ratio for the point of the edge g in the relative interior of the
    // simplex s of the other operand
    Ratio _ratioAlong(int g, uint32_t s) const
    {
      const int p = _edges[g][0], q = _edges[g][1];
      auto plane = [&](int t, Ratio &r) {
        const int *v = &_tri[3 * t];
        if(!orient3d(X(v[0]), X(v[1]), X(v[2]), X(p)) &&
           !orient3d(X(v[0]), X(v[1]), X(v[2]), X(q)))
          return false;
        r = Ratio{p, q, v[0], v[1], v[2]};
        return true;
      };
      Ratio r{p, q, p, q, -1};
      if(dimension(s) == 2) {
        plane(index(s), r);
        return r;
      }
      if(dimension(s) == 1) {
        const int f = index(s);
        for(int t : _edgeTriangles[f])
          if(plane(t, r)) return r;
        // g in the planes of both triangles of f
        const int t = _degenerate[_edgeTriangles[f][0]] ?
                        _edgeTriangles[f][1] :
                        _edgeTriangles[f][0];
        return Ratio{p, q, _edges[f][0], _edges[f][1], -_axis[t] - 1};
      }
      const int w = index(s);
      for(int i = _vtStart[w]; i < _vtStart[w + 1]; i++)
        if(plane(_vt[i], r)) return r;
      // g in the planes of all the triangles around w: relative to an edge
      // of w not along g
      int t = _vt[_vtStart[w]];
      for(int i = _vtStart[w]; i < _vtStart[w + 1]; i++)
        if(!_degenerate[_vt[i]]) t = _vt[i];
      const int k = _axis[t];
      for(int i = _vtStart[w]; i < _vtStart[w + 1]; i++) {
        const int *v = &_tri[3 * _vt[i]];
        for(int j = 0; j < 3; j++)
          if(v[j] != w && orient2d(X(p), X(q), X(v[j]), k))
            return Ratio{p, q, w, v[j], -k - 1};
      }
      return r;
    }

    // the point of a label, created the first time with its insertion in
    // the edges and triangles it lies in
    int _point(uint64_t l)
    {
      auto it = _pointOfLabel.find(l);
      if(it != _pointOfLabel.end()) return it->second;
      const uint32_t a = (uint32_t)(l >> 32), b = (uint32_t)l;
      int id;
      if(dimension(a) == 0) {
        id = index(a);
        if(dimension(b) == 0) _alias[index(b)] = id;
      }
      else if(dimension(b) == 0)
        id = index(b);
      else {
        Point n;
        n.nAlong = 0;
        if(dimension(a) == 1) n.along[n.nAlong++] = _ratioAlong(index(a), b);
        if(dimension(b) == 1) n.along[n.nAlong++] = _ratioAlong(index(b), a);
        Approx A, B;
        _orientations(n.along[0], A, B);
        const Approx d = A - B;
        const double *P = X(n.along[0].p), *Q = X(n.along[0].q);
        if(certain(d)) {
          const Approx lambda = divide(A, d);
          for(int k = 0; k < 3; k++)
            n.c[k] = exact(P[k]) + lambda * (exact(Q[k]) - exact(P[k]));
        }
        else
          for(int k = 0; k < 3; k++)
            n.c[k] = {0.5 * (P[k] + Q[k]),
                      0.5 * std::abs(Q[k] - P[k]) * (1. + 4. * unit) +
                        unit * std::abs(P[k] + Q[k])};
        id = _nv + (int)_points.size();
        _points.push_back(n);
      }
      _pointOfLabel[l] = id;
      if(id >= _nv) _points[id - _nv].label = l;
      for(uint32_t s : {a, b})
        if(dimension(s) == 0) {
          _onOther[index(s)] = 1;
          _vertexLabel[index(s)] = l;
        }
      // its insertion
      const uint32_t s[2] = {a, b};
      for(int i = 0; i < 2; i++) {
        if(dimension(s[i]) == 1) {
          const int g = index(s[i]);
          Ratio r;
          if(id >= _nv) {
            const Point &n = _points[id - _nv];
            r = n.along[0];
            for(int j = 0; j < n.nAlong; j++)
              if(n.along[j].p == _edges[g][0] && n.along[j].q == _edges[g][1])
                r = n.along[j];
          }
          else
            r = _ratioAlong(g, s[1 - i]);
          _onEdge[g].push_back({id, r});
        }
        else if(dimension(s[i]) == 2)
          _inside[index(s[i])].push_back(id);
      }
      return id;
    }

    bool _setup(const std::vector<double> &xyzA, const std::vector<int> &triA,
                const std::vector<double> &xyzB, const std::vector<int> &triB)
    {
      _nvA = (int)xyzA.size() / 3;
      _ntA = (int)triA.size() / 3;
      _nv = _nvA + (int)xyzB.size() / 3;
      _nt = _ntA + (int)triB.size() / 3;
      _x = xyzA;
      _x.insert(_x.end(), xyzB.begin(), xyzB.end());
      _tri = triA;
      for(int v : triB) _tri.push_back(v + _nvA);
      // the edges, each operand closed and manifold
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
        if(j - i != 2) {
          error = "an operand is not a closed manifold triangulation";
          return false;
        }
        const int e = (int)_edges.size();
        _edges.push_back({half[i][0], half[i][1]});
        _edgeTriangles.push_back({half[i][2], half[i + 1][2]});
        _triEdges[3 * half[i][2] + half[i][3]] = e;
        _triEdges[3 * half[i + 1][2] + half[i + 1][3]] = e;
        i = j;
      }
      // the edges of A first (the vertices of A come first)
      _neA = 0;
      while(_neA < (int)_edges.size() && _edges[_neA][0] < _nvA) _neA++;
      // the triangles around the vertices
      _vtStart.assign(_nv + 1, 0);
      for(int v : _tri) _vtStart[v + 1]++;
      for(int v = 0; v < _nv; v++) _vtStart[v + 1] += _vtStart[v];
      _vt.resize(_tri.size());
      std::vector<int> fill(_vtStart.begin(), _vtStart.end() - 1);
      for(int t = 0; t < _nt; t++)
        for(int k = 0; k < 3; k++) _vt[fill[_tri[3 * t + k]]++] = t;
      // the projections of the triangles
      _degenerate.assign(_nt, 0);
      _axis.resize(_nt);
      _orientation.resize(_nt);
      for(int t = 0; t < _nt; t++) {
        const double *a = X(_tri[3 * t]), *b = X(_tri[3 * t + 1]),
                     *c = X(_tri[3 * t + 2]);
        const double n[3] = {
          (b[1] - a[1]) * (c[2] - a[2]) - (b[2] - a[2]) * (c[1] - a[1]),
          (b[2] - a[2]) * (c[0] - a[0]) - (b[0] - a[0]) * (c[2] - a[2]),
          (b[0] - a[0]) * (c[1] - a[1]) - (b[1] - a[1]) * (c[0] - a[0])};
        int axes[3] = {0, 1, 2};
        std::sort(axes, axes + 3, [&](int i, int j) {
          return std::abs(n[i]) > std::abs(n[j]);
        });
        _orientation[t] = 0;
        for(int i = 0; i < 3 && !_orientation[t]; i++) {
          _axis[t] = axes[i];
          _orientation[t] = orient2d(a, b, c, axes[i]);
        }
        _degenerate[t] = !_orientation[t];
      }
      _alias.resize(_nv);
      for(int v = 0; v < _nv; v++) _alias[v] = v;
      _onOther.assign(_nv, 0);
      _vertexLabel.assign(_nv, 0);
      // the flat regions
      _region.assign(_nt, -1);
      for(int t = 0; t < _nt; t++) {
        if(_region[t] >= 0) continue;
        std::vector<int> stack(1, t);
        _region[t] = t;
        while(!stack.empty()) {
          const int u = stack.back();
          stack.pop_back();
          if(_degenerate[u]) continue;
          const int *v = &_tri[3 * u];
          for(int k = 0; k < 3; k++) {
            const std::array<int, 2> &n = _edgeTriangles[_triEdges[3 * u + k]];
            const int w = n[0] == u ? n[1] : n[0];
            if(_region[w] >= 0 || _degenerate[w]) continue;
            const int *x = &_tri[3 * w];
            int opposite = x[0];
            for(int j = 0; j < 3; j++)
              if(x[j] != v[0] && x[j] != v[1] && x[j] != v[2]) opposite = x[j];
            if(orient3d(X(v[0]), X(v[1]), X(v[2]), X(opposite))) continue;
            _region[w] = t;
            stack.push_back(w);
          }
        }
      }
      _onEdge.resize(_edges.size());
      _inside.resize(_nt);
      _constraints.resize(_nt);
      return true;
    }

    // the intersections of the triangles of A and B
    bool _intersectAll()
    {
      std::vector<std::array<double, 6> > boxes(_nt);
      for(int t = 0; t < _nt; t++) {
        std::array<double, 6> &b = boxes[t];
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
      std::vector<int> itemsB;
      for(int t = _ntA; t < _nt; t++) itemsB.push_back(t);
      BoxTree tree;
      tree.build(boxes, itemsB);
      for(int ta = 0; ta < _ntA && error.empty(); ta++) {
        if(_degenerate[ta]) continue;
        tree.query(boxes[ta], [&](int tb) {
          if(!error.empty() || _degenerate[tb]) return;
          const int *a = &_tri[3 * ta], *b = &_tri[3 * tb];
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
            // coplanar: the edges of each one clipped by the other,
            // constraints of both
            for(int k = 0; k < 6; k++) {
              uint64_t l[2];
              const int m =
                k < 3 ? _intersect(_triEdges[3 * ta + k], tb, l) :
                        _intersect(_triEdges[3 * tb + k - 3], ta, l);
              if(!m) continue;
              const int p0 = _point(l[0]);
              if(m == 2) {
                const int p1 = _point(l[1]);
                _constraints[ta].push_back({p0, p1, tb});
                _constraints[tb].push_back({p0, p1, ta});
              }
            }
            return;
          }
          uint64_t labels[12];
          int n = 0;
          for(int k = 0; k < 3; k++)
            n += _intersect(_triEdges[3 * ta + k], tb, labels + n);
          for(int k = 0; k < 3; k++)
            n += _intersect(_triEdges[3 * tb + k], ta, labels + n);
          std::sort(labels, labels + n);
          n = (int)(std::unique(labels, labels + n) - labels);
          if(!n) return;
          if(n > 2) {
            error = "inconsistent intersection of two triangles";
            return;
          }
          const int p0 = _point(labels[0]);
          if(n == 2) {
            const int p1 = _point(labels[1]);
            _constraints[ta].push_back({p0, p1, tb});
            _constraints[tb].push_back({p0, p1, ta});
          }
        });
      }
      return error.empty();
    }

    // the constrained Delaunay triangulation (gmsh's PolyMesh) of a triangle
    // with the points on its edges and inside it, and its constraints: the
    // Delaunay criterion on approximate coordinates in an orthonormal frame
    // of its plane, the validity of the triangulation (locations, convexity
    // of the flips, crossings of the constraints) decided exactly
    class Face {
      typedef PolyMesh::Vertex Vertex;
      typedef PolyMesh::HalfEdge HalfEdge;
      const MeshBoolean &_m;
      int _k, _o;
      PolyMesh _pm;
      double _origin[3], _e1[3], _e2[3];
      std::unordered_map<int, Vertex *> _vertexOf;
      PolyMesh::Face *_last = nullptr;
      unsigned _random = 12345;
      // the orientation of points (their global ids), positive
      // counterclockwise on the triangle
      int _orient(int a, int b, int c) const
      {
        return _o * _m._orient2d(a, b, c, _k);
      }
      int _orient(const Vertex *a, const Vertex *b, const Vertex *c) const
      {
        return _orient(a->data, b->data, c->data);
      }
      // the coordinates of a point in the frame of the triangle
      SVector3 _position(int g) const
      {
        Approx c[3];
        _m._coords(g, c);
        double d[3], x = 0., y = 0.;
        for(int k = 0; k < 3; k++) {
          d[k] = c[k].v - _origin[k];
          x += d[k] * _e1[k];
          y += d[k] * _e2[k];
        }
        return SVector3(x, y, 0.);
      }
      // gmsh's Delaunay criterion, a flip only if it is valid
      static int _flip(HalfEdge *he, void *data)
      {
        const Face *f = (const Face *)data;
        if(!he->opposite || he->data >= 0) return 0;
        Vertex *a = he->v, *b = he->next->v, *c = he->next->next->v,
               *d = he->opposite->next->next->v;
        const double pa[2] = {a->position.x(), a->position.y()};
        const double pb[2] = {b->position.x(), b->position.y()};
        const double pc[2] = {c->position.x(), c->position.y()};
        const double pd[2] = {d->position.x(), d->position.y()};
        if(robustPredicates::incircle(pa, pb, pc, pd) <= 0.) return 0;
        return f->_orient(a, d, c) > 0 && f->_orient(d, b, c) > 0 ? 1 : 0;
      }
      // the flips propagated from some edges (as in PolyMesh::split_triangle)
      void _cascade(std::vector<HalfEdge *> stack)
      {
        std::vector<HalfEdge *> touched;
        std::size_t guard = 0;
        while(!stack.empty() && ++guard < 1000000) {
          HalfEdge *he = stack.back();
          stack.pop_back();
          touched.push_back(he);
          he->touched = 1;
          if(_flip(he, this) != 1) continue;
          _pm.swap_edge(he);
          HalfEdge *H[2] = {he, he->opposite};
          for(int k = 0; k < 2; k++) {
            HalfEdge *b = H[k]->next, *c = b->next;
            if(!b->touched && !(b->opposite && b->opposite->touched))
              stack.push_back(b);
            if(!c->touched && !(c->opposite && c->opposite->touched))
              stack.push_back(c);
          }
        }
        for(HalfEdge *he : touched) he->touched = 0;
      }
      // the half-edges leaving a vertex
      void _star(Vertex *v, std::vector<HalfEdge *> &out) const
      {
        out.clear();
        HalfEdge *h = v->he;
        do {
          out.push_back(h);
          h = h->opposite ? h->opposite->next : nullptr;
        } while(h && h != v->he);
        if(h == v->he) return;
        h = v->he->prev->opposite;
        while(h) {
          out.push_back(h);
          h = h->prev->opposite;
        }
      }
      HalfEdge *_edge(Vertex *a, Vertex *b) const
      {
        std::vector<HalfEdge *> star;
        _star(a, star);
        for(HalfEdge *h : star)
          if(h->next->v == b) return h;
        _star(b, star);
        for(HalfEdge *h : star)
          if(h->next->v == a) return h;
        return nullptr;
      }
      // the split of the boundary edge h at a new vertex, the next part of
      // the boundary
      HalfEdge *_splitBoundary(HalfEdge *h, int g)
      {
        HalfEdge *h1 = h->next, *h2 = h1->next;
        Vertex *a = h->v, *b = h1->v, *c = h2->v;
        const SVector3 p = _position(g);
        Vertex *m = new Vertex(p.x(), p.y(), 0., g);
        _pm.vertices.push_back(m);
        _vertexOf[g] = m;
        HalfEdge *hmc = new HalfEdge(m), *hmb = new HalfEdge(m),
                 *hcm = new HalfEdge(c);
        _pm.hedges.push_back(hmc);
        _pm.hedges.push_back(hmb);
        _pm.hedges.push_back(hcm);
        hmc->opposite = hcm;
        hcm->opposite = hmc;
        PolyMesh::Face *f = new PolyMesh::Face(hmb);
        _pm.faces.push_back(f);
        _pm.createFace(h->f, a, m, c, h, hmc, h2);
        _pm.createFace(f, m, b, c, hmb, h1, hcm);
        _cascade({h1, h2});
        return hmb;
      }
      // the face containing a point (exact walk, or search), the orientations
      // relative to its edges
      PolyMesh::Face *_locate(int g, int o[3])
      {
        PolyMesh::Face *f = _last ? _last : _pm.faces.back();
        const int limit = 4 * (int)_pm.faces.size() + 100;
        for(int steps = 0; steps < limit; steps++) {
          HalfEdge *he = f->he;
          _random = _random * 1103515245u + 12345u;
          for(int r = (int)((_random >> 16) % 3); r > 0; r--) he = he->next;
          PolyMesh::Face *next = nullptr;
          for(int i = 0; i < 3 && !next; i++, he = he->next)
            if(he->opposite && _orient(he->v->data, he->next->v->data, g) < 0)
              next = he->opposite->f;
          if(!next) break;
          f = next;
        }
        auto inside = [&](PolyMesh::Face *u) {
          HalfEdge *he = u->he;
          for(int i = 0; i < 3; i++, he = he->next) {
            o[i] = _orient(he->v->data, he->next->v->data, g);
            if(o[i] < 0) return false;
          }
          return true;
        };
        if(inside(f)) return f;
        for(PolyMesh::Face *u : _pm.faces)
          if(inside(u)) return u;
        return nullptr;
      }
      // the insertion of a point inside the triangle
      bool _insert(int g)
      {
        int o[3];
        PolyMesh::Face *f = _locate(g, o);
        if(!f) return false;
        const int zeros = (o[0] == 0) + (o[1] == 0) + (o[2] == 0);
        if(zeros == 0) {
          // split, then the flips of its edges (the new vertex known)
          const SVector3 p = _position(g);
          HalfEdge *h0 = f->he, *h1 = h0->next, *h2 = h1->next;
          _pm.split_triangle(-1, p.x(), p.y(), 0., f);
          _pm.vertices.back()->data = g;
          _vertexOf[g] = _pm.vertices.back();
          _cascade({h0, h1, h2});
          _last = f;
          return true;
        }
        HalfEdge *he = f->he;
        int i = 0;
        while(o[i]) {
          i++;
          he = he->next;
        }
        if(zeros == 2) {
          // at a vertex (input vertices at the same place): identified
          _vertexOf[g] = o[(i + 1) % 3] ? he->v : he->next->v;
          return true;
        }
        if(!he->opposite) {
          _splitBoundary(he, g);
          return true;
        }
        _pm.split_edge(he, _position(g), g);
        Vertex *m = _pm.vertices.back();
        _vertexOf[g] = m;
        std::vector<HalfEdge *> star, outer;
        _star(m, star);
        for(HalfEdge *h : star) outer.push_back(h->next);
        _cascade(outer);
        _last = f;
        return true;
      }
      // the recovery of the constraint ab by flips, split at the vertices on
      // it
      bool _recover(Vertex *a, Vertex *b,
                    std::vector<std::pair<Vertex *, Vertex *> > &pieces)
      {
        if(a == b) return true;
        if(_edge(a, b)) {
          pieces.push_back({a, b});
          return true;
        }
        std::vector<HalfEdge *> star;
        _star(a, star);
        HalfEdge *crossed = nullptr;
        for(HalfEdge *h : star) {
          Vertex *u = h->next->v, *w = h->next->next->v;
          const int o1 = _orient(a, u, b), o2 = _orient(a, w, b);
          if(o1 == 0 && o2 < 0) {
            pieces.push_back({a, u});
            return _recover(u, b, pieces);
          }
          if(o2 == 0 && o1 > 0) {
            pieces.push_back({a, w});
            return _recover(w, b, pieces);
          }
          if(o1 > 0 && o2 < 0) {
            crossed = h->next;
            break;
          }
        }
        if(!crossed) return false;
        // the edges crossed by ab (from its right to its left), to the
        // vertex of ab after a
        std::deque<HalfEdge *> list(1, crossed);
        Vertex *end = b;
        for(int guard = 0;; guard++) {
          HalfEdge *o = crossed->opposite;
          if(!o || guard > 1000000) return false;
          Vertex *x = o->next->next->v;
          if(x == b) break;
          const int ox = _orient(a, b, x);
          if(ox == 0) {
            end = x;
            break;
          }
          crossed = ox > 0 ? o->next : o->next->next;
          list.push_back(crossed);
        }
        for(int guard = 0; !list.empty(); guard++) {
          if(guard > 1000000) return false;
          HalfEdge *he = list.front();
          list.pop_front();
          Vertex *p = he->v, *q = he->next->v, *c = he->next->next->v,
                 *d = he->opposite->next->next->v;
          if(_orient(p, d, c) > 0 && _orient(d, q, c) > 0) {
            _pm.swap_edge(he);
            if(c != a && c != end && d != a && d != end &&
               _orient(a, end, c) * _orient(a, end, d) < 0)
              list.push_back(he);
          }
          else
            list.push_back(he);
        }
        pieces.push_back({a, end});
        if(end != b) return _recover(end, b, pieces);
        return true;
      }

    public:
      std::vector<std::array<int, 3> > triangles;
      std::unordered_map<uint64_t, std::vector<int> > constrained;
      Face(const MeshBoolean &m, int t) : _m(m)
      {
        _k = m._axis[t];
        _o = m._orientation[t];
      }
      bool triangulate(int t)
      {
        const int *v = &_m._tri[3 * t];
        // the frame of the triangle
        const double *x0 = _m.X(v[0]), *x1 = _m.X(v[1]), *x2 = _m.X(v[2]);
        double n[3], l1 = 0., l2 = 0.;
        for(int k = 0; k < 3; k++) {
          _origin[k] = x0[k];
          _e1[k] = x1[k] - x0[k];
        }
        const double u[3] = {x2[0] - x0[0], x2[1] - x0[1], x2[2] - x0[2]};
        n[0] = _e1[1] * u[2] - _e1[2] * u[1];
        n[1] = _e1[2] * u[0] - _e1[0] * u[2];
        n[2] = _e1[0] * u[1] - _e1[1] * u[0];
        _e2[0] = n[1] * _e1[2] - n[2] * _e1[1];
        _e2[1] = n[2] * _e1[0] - n[0] * _e1[2];
        _e2[2] = n[0] * _e1[1] - n[1] * _e1[0];
        for(int k = 0; k < 3; k++) {
          l1 += _e1[k] * _e1[k];
          l2 += _e2[k] * _e2[k];
        }
        l1 = std::sqrt(l1);
        l2 = std::sqrt(l2);
        for(int k = 0; k < 3; k++) {
          _e1[k] /= l1;
          _e2[k] /= l2;
        }
        // the triangle, its edges split at their points in their order
        Vertex *w[3];
        for(int i = 0; i < 3; i++) {
          const SVector3 p = _position(v[i]);
          w[i] = new Vertex(p.x(), p.y(), 0., v[i]);
          _pm.vertices.push_back(w[i]);
          _vertexOf[v[i]] = w[i];
          // (a vertex of B at a vertex of A: the points there have its id)
          _vertexOf[_m._alias[v[i]]] = w[i];
        }
        HalfEdge *h[3];
        for(int i = 0; i < 3; i++) {
          h[i] = new HalfEdge(w[i]);
          _pm.hedges.push_back(h[i]);
        }
        PolyMesh::Face *f = new PolyMesh::Face(h[0]);
        _pm.faces.push_back(f);
        _pm.createFace(f, w[0], w[1], w[2], h[0], h[1], h[2]);
        for(int i = 0; i < 3; i++) {
          const int e = _m._triEdges[3 * t + i];
          const std::vector<OnEdge> &on = _m._onEdge[e];
          const bool reverse = v[i] != _m._edges[e][0];
          HalfEdge *b = h[i];
          for(std::size_t j = 0; j < on.size(); j++)
            b = _splitBoundary(b, on[reverse ? on.size() - 1 - j : j].point);
        }
        // the points inside
        for(int g : _m._inside[t])
          if(!_insert(g)) return false;
        // the constraints
        for(const Constraint &c : _m._constraints[t]) {
          std::vector<std::pair<Vertex *, Vertex *> > pieces;
          auto a = _vertexOf.find(c.a), b = _vertexOf.find(c.b);
          if(a == _vertexOf.end() || b == _vertexOf.end()) return false;
          if(!_recover(a->second, b->second, pieces)) return false;
          for(auto &p : pieces) {
            HalfEdge *e = _edge(p.first, p.second);
            if(!e) return false;
            e->data = 1;
            if(e->opposite) e->opposite->data = 1;
            const int a = std::min(p.first->data, p.second->data);
            const int b = std::max(p.first->data, p.second->data);
            constrained[edgeKey(a, b)].push_back(c.other);
          }
        }
        // the Delaunay criterion everywhere else
        std::vector<HalfEdge *> all;
        for(HalfEdge *he : _pm.hedges)
          if(he->opposite && he->data < 0 && he < he->opposite)
            all.push_back(he);
        _cascade(all);
        for(PolyMesh::Face *u : _pm.faces)
          triangles.push_back({u->he->v->data, u->he->next->v->data,
                               u->he->next->next->v->data});
        return true;
      }
    };

    bool _triangulateAll()
    {
      // the points on the edges in their order
      for(std::size_t e = 0; e < _edges.size(); e++) {
        std::vector<OnEdge> &on = _onEdge[e];
        std::sort(on.begin(), on.end(),
                  [&](const OnEdge &a, const OnEdge &b) {
                    return _compare(a.along, b.along) < 0;
                  });
      }
      for(int t = 0; t < _nt; t++) {
        bool split = !_inside[t].empty() || !_constraints[t].empty();
        for(int i = 0; i < 3 && !split; i++)
          if(!_onEdge[_triEdges[3 * t + i]].empty()) split = true;
        const int o = _inA(t) ? 0 : 1;
        if(!split) {
          Final f;
          for(int i = 0; i < 3; i++) {
            f.v[i] = _alias[_tri[3 * t + i]];
            f.along[i] = -1;
          }
          f.birth = t;
          _final[o].push_back(f);
          continue;
        }
        Face face(*this, t);
        if(_degenerate[t]) {
          // a fan of its boundary, of zero area
          std::vector<int> b;
          for(int i = 0; i < 3; i++) {
            const int e = _triEdges[3 * t + i];
            const bool reverse = _tri[3 * t + i] != _edges[e][0];
            b.push_back(_tri[3 * t + i]);
            for(std::size_t j = 0; j < _onEdge[e].size(); j++)
              b.push_back(
                _onEdge[e][reverse ? _onEdge[e].size() - 1 - j : j].point);
          }
          for(std::size_t j = 1; j + 1 < b.size(); j++)
            face.triangles.push_back({b[0], b[j], b[j + 1]});
        }
        else if(!face.triangulate(t)) {
          error = "could not triangulate an intersected triangle";
          return false;
        }
        for(auto &T : face.triangles) {
          Final f;
          for(int i = 0; i < 3; i++) {
            f.v[i] = T[i] < _nv ? _alias[T[i]] : T[i];
            const int a = std::min(T[i], T[(i + 1) % 3]);
            const int b = std::max(T[i], T[(i + 1) % 3]);
            auto it = face.constrained.find(edgeKey(a, b));
            f.along[i] = -1;
            if(it != face.constrained.end()) {
              f.along[i] = (int)_alongs.size();
              _alongs.push_back(it->second);
            }
          }
          f.birth = t;
          _final[o].push_back(f);
        }
      }
      return true;
    }

    // triangles in the same plane
    bool _coplanar(int t, int u) const
    {
      const int *v = &_tri[3 * t], *w = &_tri[3 * u];
      for(int j = 0; j < 3; j++)
        if(orient3d(X(v[0]), X(v[1]), X(v[2]), X(w[j]))) return false;
      return true;
    }

    // the state of a final triangle relative to the other operand, from the
    // triangles of the other operand along its edge i: 1 inside, -1 outside
    // (locally, two of them sharing an edge: by their dihedral angle), 2 on
    // a coplanar triangle of the same orientation, 3 of the opposite
    // orientation, 0 if undecided
    int _state(const Final &f, int i) const
    {
      std::vector<int> o = _alongs[f.along[i]];
      std::sort(o.begin(), o.end());
      o.erase(std::unique(o.begin(), o.end()), o.end());
      const int t = f.birth, k = _axis[t];
      const int u = f.v[i], w = f.v[(i + 1) % 3], z = f.v[(i + 2) % 3];
      std::vector<int> transversal;
      for(int c : o) {
        if(!_coplanar(t, c)) {
          transversal.push_back(c);
          continue;
        }
        // on it, if on the side of its interior
        const int *v = &_tri[3 * c];
        const int sc = orient2d(X(v[0]), X(v[1]), X(v[2]), k);
        bool on = true;
        for(int j = 0; j < 3 && on; j++) {
          const int a = v[j], b = v[(j + 1) % 3];
          if(!_orient2d(a, b, u, k) && !_orient2d(a, b, w, k) &&
             sc * _orient2d(a, b, z, k) <= 0)
            on = false;
        }
        if(on) return sc == _orientation[t] ? 2 : 3;
      }
      if(transversal.size() == 1) return _side(transversal[0], z);
      if(transversal.size() != 2) return 0;
      const int s1 = _side(transversal[0], z), s2 = _side(transversal[1], z);
      if(!s1 || !s2) return 0;
      // the vertex of the second one not on the first one
      const int *v1 = &_tri[3 * transversal[0]], *v2 = &_tri[3 * transversal[1]];
      int x = -1;
      for(int j = 0; j < 3; j++)
        if(v2[j] != v1[0] && v2[j] != v1[1] && v2[j] != v1[2]) x = v2[j];
      if(x < 0) return 0;
      const bool convex = _side(transversal[0], x) > 0;
      if(convex) return (s1 > 0 && s2 > 0) ? 1 : -1;
      return (s1 > 0 || s2 > 0) ? 1 : -1;
    }

    // inside the other operand, by the parity of the crossings of rays
    int _insideByRays(int v, int o) const
    {
      const int first = o ? 0 : _ntA, last = o ? _ntA : _nt;
      double lo[3] = {1e300, 1e300, 1e300}, hi[3] = {-1e300, -1e300, -1e300};
      for(int i = 0; i < _nv; i++)
        for(int k = 0; k < 3; k++) {
          lo[k] = std::min(lo[k], _x[3 * i + k]);
          hi[k] = std::max(hi[k], _x[3 * i + k]);
        }
      const double size = 2. * (std::abs(hi[0] - lo[0]) + std::abs(hi[1] - lo[1]) +
                                std::abs(hi[2] - lo[2])) + 1.;
      const double directions[6][3] = {
        {0.5773502, 0.5773503, 0.5773504}, {-0.62, 0.48, 0.6197},
        {0.31, -0.81, 0.4975}, {-0.21, -0.37, -0.9031}, {0.83, 0.12, -0.5446},
        {-0.47, 0.71, -0.5235}};
      const double *p = X(v);
      for(int d = 0; d < 6; d++) {
        const double q[3] = {p[0] + size * directions[d][0],
                             p[1] + size * directions[d][1],
                             p[2] + size * directions[d][2]};
        int crossings = 0;
        bool degenerate = false;
        for(int t = first; t < last && !degenerate; t++) {
          if(_degenerate[t]) continue;
          const int *w = &_tri[3 * t];
          const int dp = orient3d(X(w[0]), X(w[1]), X(w[2]), p);
          const int dq = orient3d(X(w[0]), X(w[1]), X(w[2]), q);
          if(dp * dq > 0) continue;
          if(!dp || !dq) {
            uint32_t loc;
            if(!dp && !_locate(v, t, loc)) continue;
            degenerate = true;
            continue;
          }
          int s[3];
          for(int i = 0; i < 3; i++)
            s[i] = orient3d(p, q, X(w[i]), X(w[(i + 1) % 3]));
          if((s[0] > 0 || s[1] > 0 || s[2] > 0) &&
             (s[0] < 0 || s[1] < 0 || s[2] < 0))
            continue;
          if(!s[0] || !s[1] || !s[2]) {
            degenerate = true;
            continue;
          }
          crossings++;
        }
        if(!degenerate) return crossings % 2 ? 1 : -1;
      }
      return 0;
    }

    // the classification of the final triangles of the operand o: their
    // states
    bool _classify(int o, std::vector<int> &inside)
    {
      std::vector<Final> &F = _final[o];
      const int n = (int)F.size();
      std::vector<int> parent(n);
      for(int i = 0; i < n; i++) parent[i] = i;
      std::function<int(int)> find = [&](int i) {
        while(parent[i] != i) i = parent[i] = parent[parent[i]];
        return i;
      };
      std::unordered_map<uint64_t, std::array<int, 3> > edgeOf;
      edgeOf.reserve(3 * n);
      for(int i = 0; i < n; i++)
        for(int k = 0; k < 3; k++) {
          const int a = std::min(F[i].v[k], F[i].v[(k + 1) % 3]);
          const int b = std::max(F[i].v[k], F[i].v[(k + 1) % 3]);
          auto &e = edgeOf.emplace(edgeKey(a, b), std::array<int, 3>{-1, -1, 0})
                      .first->second;
          if(e[0] < 0)
            e[0] = i;
          else
            e[1] = i;
          if(F[i].along[k] >= 0) e[2] = 1;
        }
      for(auto &e : edgeOf) {
        if(e.second[1] < 0) {
          error = "the result is not closed";
          return false;
        }
        if(!e.second[2]) parent[find(e.second[0])] = find(e.second[1]);
      }
      std::unordered_map<int, int> patch; // root -> state
      for(int i = 0; i < n; i++)
        for(int k = 0; k < 3; k++) {
          if(F[i].along[k] < 0) continue;
          const int r = find(i);
          const int s = _state(F[i], k);
          if(!s) continue;
          auto it = patch.find(r);
          if(it == patch.end())
            patch[r] = s;
          else if(it->second != s) {
            error = "inconsistent classification of a patch";
            return false;
          }
        }
      inside.resize(n);
      for(int i = 0; i < n; i++) {
        const int r = find(i);
        auto it = patch.find(r);
        if(it == patch.end()) {
          // a patch not crossed: by rays from one of its input vertices not
          // on the other operand
          int s = 0;
          for(int j = 0; j < n && !s; j++) {
            if(find(j) != r) continue;
            for(int k = 0; k < 3 && !s; k++) {
              const int v = F[j].v[k];
              if(v < _nv && !_onOther[v]) s = _insideByRays(v, o);
            }
          }
          if(!s) {
            error = "could not classify a patch";
            return false;
          }
          it = patch.emplace(r, s).first;
        }
        inside[i] = it->second;
      }
      return true;
    }

  public:
    bool compute(int op, const std::vector<double> &xyzA,
                 const std::vector<int> &triA, const std::vector<double> &xyzB,
                 const std::vector<int> &triB, std::vector<double> &xyz,
                 std::vector<int> &tri, std::vector<int> &birth)
    {
      if(!_setup(xyzA, triA, xyzB, triB)) return false;
      if(!_intersectAll()) return false;
      if(!_triangulateAll()) return false;
      std::vector<int> inside[2];
      if(!_classify(0, inside[0]) || !_classify(1, inside[1])) return false;
      // the triangles kept, the vertices used
      std::vector<int> used(_nv + _points.size(), -1);
      xyz.clear();
      tri.clear();
      birth.clear();
      for(int o = 0; o < 2; o++)
        for(std::size_t i = 0; i < _final[o].size(); i++) {
          const Final &f = _final[o][i];
          const int state = inside[o][i];
          const bool in = state == 1;
          bool keep, flip = false;
          if(state == 2) // on the other one, oriented the same way: A once
            keep = o == 0 && op != 2;
          else if(state == 3) // oriented the opposite way
            keep = o == 0 && op == 2;
          else if(op == 0)
            keep = !in;
          else if(op == 1)
            keep = in;
          else {
            keep = o == 0 ? !in : in;
            flip = o == 1;
          }
          if(!keep) continue;
          int v[3] = {f.v[0], f.v[1], f.v[2]};
          if(flip) std::swap(v[1], v[2]);
          for(int k = 0; k < 3; k++) {
            if(used[v[k]] < 0) {
              used[v[k]] = (int)xyz.size() / 3;
              Approx c[3];
              _coords(v[k], c);
              for(int j = 0; j < 3; j++) xyz.push_back(c[j].v);
            }
            tri.push_back(used[v[k]]);
          }
          birth.push_back(f.birth);
        }
      _clean(xyz, tri, birth);
      return true;
    }

    // the edges whose ends are rounded to the same coordinates (the exact
    // intersection points can be closer than the rounding) collapsed, if the
    // ends have no other common neighbors than the vertices opposite to the
    // edge (the result stays manifold); the others left as they are
    static void _clean(std::vector<double> &xyz, std::vector<int> &tri,
                       std::vector<int> &birth)
    {
      const int nv = (int)xyz.size() / 3, nt = (int)tri.size() / 3;
      auto same = [&](int a, int b) {
        return std::equal(&xyz[3 * a], &xyz[3 * a + 3], &xyz[3 * b]);
      };
      bool any = false;
      for(int t = 0; t < nt && !any; t++)
        for(int k = 0; k < 3; k++)
          if(same(tri[3 * t + k], tri[3 * t + (k + 1) % 3])) any = true;
      if(!any) return;
      std::vector<std::vector<int> > around(nv);
      for(int t = 0; t < nt; t++)
        for(int k = 0; k < 3; k++) around[tri[3 * t + k]].push_back(t);
      std::vector<char> dead(nt, 0);
      auto has = [&](int t, int v) {
        return tri[3 * t] == v || tri[3 * t + 1] == v || tri[3 * t + 2] == v;
      };
      auto neighbors = [&](int u, std::vector<int> &n) {
        n.clear();
        for(int t : around[u])
          if(!dead[t])
            for(int k = 0; k < 3; k++)
              if(tri[3 * t + k] != u) n.push_back(tri[3 * t + k]);
        std::sort(n.begin(), n.end());
        n.erase(std::unique(n.begin(), n.end()), n.end());
      };
      std::vector<int> nu, nw, common;
      bool changed = true;
      while(changed) {
        changed = false;
        for(int t = 0; t < nt; t++) {
          if(dead[t]) continue;
          for(int k = 0; k < 3 && !dead[t]; k++) {
            const int u = tri[3 * t + k], w = tri[3 * t + (k + 1) % 3];
            if(!same(u, w)) continue;
            std::vector<int> edge;
            for(int s : around[u])
              if(!dead[s] && has(s, w)) edge.push_back(s);
            if(edge.size() != 2) continue;
            neighbors(u, nu);
            neighbors(w, nw);
            common.clear();
            std::set_intersection(nu.begin(), nu.end(), nw.begin(), nw.end(),
                                  std::back_inserter(common));
            if(common.size() != 2) continue;
            // w collapsed into u
            dead[edge[0]] = dead[edge[1]] = 1;
            for(int s : around[w]) {
              if(dead[s]) continue;
              for(int j = 0; j < 3; j++)
                if(tri[3 * s + j] == w) tri[3 * s + j] = u;
              around[u].push_back(s);
            }
            around[w].clear();
            changed = true;
          }
        }
      }
      std::vector<int> t2, b2, used(nv, -1);
      std::vector<double> x;
      for(int t = 0; t < nt; t++) {
        if(dead[t]) continue;
        for(int k = 0; k < 3; k++) {
          int &v = used[tri[3 * t + k]];
          if(v < 0) {
            v = (int)x.size() / 3;
            x.insert(x.end(), &xyz[3 * tri[3 * t + k]],
                     &xyz[3 * tri[3 * t + k] + 3]);
          }
          t2.push_back(v);
        }
        b2.push_back(birth[t]);
      }
      xyz = x;
      tri = t2;
      birth = b2;
    }
  };

} // namespace

bool meshBoolean(int op, const std::vector<double> &xyzA,
                 const std::vector<int> &triA,
                 const std::vector<double> &xyzB,
                 const std::vector<int> &triB, std::vector<double> &xyz,
                 std::vector<int> &tri, std::vector<int> &birth,
                 std::string &error)
{
  MeshBoolean m;
  const bool ok = m.compute(op, xyzA, triA, xyzB, triB, xyz, tri, birth);
  error = m.error;
  return ok;
}
