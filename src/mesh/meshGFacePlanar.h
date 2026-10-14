// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESH_GFACE_PLANAR_H
#define MESH_GFACE_PLANAR_H

// The triangle mesh of a planar surface as flat arrays in the plane of the
// surface, for the optimizations that move its nodes (Mesh.ODTSmoothing2D).
// The surface is read once and written back once. Nodes on curves and points
// stay on them; the nodes on curves may slide along their curve, between
// their two neighbors on it (Mesh.BoundaryNodeSliding2D), except where
// another mesh uses them or their distribution is imposed.

#include <algorithm>
#include <array>
#include <cmath>
#include <functional>
#include <limits>
#include <unordered_map>
#include <utility>
#include <vector>
#include "SPoint3.h"
#include "SVector3.h"

class GFace;
class GEdge;
class MVertex;

// Smooth the triangle mesh of a planar surface toward the optimal Delaunay
// triangulation (ODT) of its size, with iterations passes, the nodes on
// curves sliding along them if Mesh.BoundaryNodeSliding2D is set
void smoothPlanarFaceODT(GFace *gf, int iterations);

namespace planar {

  struct V2 {
    double x, y;
  };
  inline V2 operator+(V2 a, V2 b) { return {a.x + b.x, a.y + b.y}; }
  inline V2 operator-(V2 a, V2 b) { return {a.x - b.x, a.y - b.y}; }
  inline V2 operator*(double s, V2 a) { return {s * a.x, s * a.y}; }
  inline double norm(V2 a) { return std::sqrt(a.x * a.x + a.y * a.y); }
  inline double dot(V2 a, V2 b) { return a.x * b.x + a.y * b.y; }

  inline double orient(V2 p, V2 q, V2 r)
  {
    return (q.x - p.x) * (r.y - p.y) - (q.y - p.y) * (r.x - p.x);
  }

  // gamma = 2 r_in / R_circ (1 for the equilateral); the signed area when
  // the triangle is inverted or flat
  inline double gammaOf(V2 p, V2 q, V2 r)
  {
    const double a = norm(r - q), b = norm(p - r), c = norm(q - p);
    const double A = 0.5 * orient(p, q, r);
    if(A <= 0) return A;
    return 16 * A * A / (a * b * c * (a + b + c));
  }

  const double INF = std::numeric_limits<double>::infinity();

  // the nodes, the triangles and the stars of the nodes, with the moves that
  // keep the connectivity
  struct Mesh {
    std::vector<V2> x;
    std::vector<std::array<int, 3>> tri;
    std::vector<char> aliveT, aliveV, onBnd;
    // local size of the input mesh at each node (mean length of its edges),
    // fixed: the ODT smoother keeps this density
    std::vector<double> h0;
    std::vector<std::vector<int>> vt;
    int nv = 0;
    // nodes on curves sliding along them: curve index (-1: fixed),
    // parameter, and their two neighbors on the curve, with the parameter of
    // each on the curve of the node when it cannot slide itself (NaN
    // otherwise: read its own parameter); curvePoint gives the position of a
    // parameter
    bool slideOn = false;
    std::vector<int> slideCurve;
    std::vector<double> tpar;
    std::vector<std::array<int, 2>> slideNb;
    std::vector<std::array<double, 2>> slideNbT;
    std::function<V2(int, double)> curvePoint;
    bool slidable(int v) const
    {
      return slideOn && v < (int)slideCurve.size() && slideCurve[v] >= 0 &&
             aliveV[v];
    }
    double tparOf(int v) const { return v < (int)tpar.size() ? tpar[v] : 0.; }
    // parameter of the k-th curve neighbor of a sliding node on its curve
    double slideLim(int v, int k) const
    {
      return std::isnan(slideNbT[v][k]) ? tparOf(slideNb[v][k]) :
                                          slideNbT[v][k];
    }

    // onCurve: nodes on curves or points (fixed unless they slide)
    Mesh(const std::vector<V2> &x0, const std::vector<std::array<int, 3>> &t0,
         const std::vector<char> &onCurve)
      : x(x0), tri(t0)
    {
      nv = (int)x.size();
      for(auto &t : tri)
        if(orient(x[t[0]], x[t[1]], x[t[2]]) < 0) std::swap(t[1], t[2]);
      aliveT.assign(tri.size(), 1);
      aliveV.assign(nv, 1);
      std::vector<int> degree(nv, 0);
      for(auto &t : tri)
        for(int v : t) degree[v]++;
      vt.assign(nv, {});
      for(int v = 0; v < nv; v++) vt[v].reserve(degree[v]);
      for(int i = 0; i < (int)tri.size(); i++)
        for(int v : tri[i]) vt[v].push_back(i);
      // the edges (a, b), a < b: an edge is on the boundary if a single
      // triangle uses it; the mean length of the edges of each node
      onBnd = onCurve;
      h0.assign(nv, 0.);
      std::vector<int> nEdgesOf(nv, 0);
      std::vector<int> nb;
      for(int a = 0; a < nv; a++) {
        nb.clear();
        for(int t : vt[a])
          for(int b : tri[t])
            if(b > a) nb.push_back(b);
        std::sort(nb.begin(), nb.end());
        for(std::size_t i = 0, j; i < nb.size(); i = j) {
          const int b = nb[i];
          for(j = i + 1; j < nb.size() && nb[j] == b;) j++;
          if(j - i == 1) onBnd[a] = onBnd[b] = 1;
          const double l = norm(x[a] - x[b]);
          h0[a] += l;
          h0[b] += l;
          nEdgesOf[a]++;
          nEdgesOf[b]++;
        }
      }
      for(int v = 0; v < nv; v++) h0[v] /= std::max(1, nEdgesOf[v]);
    }

    double triGamma(int t) const
    {
      return gammaOf(x[tri[t][0]], x[tri[t][1]], x[tri[t][2]]);
    }
    double starGamma(int v, const V2 *pos = nullptr) const
    {
      double g = 1.;
      for(int t : vt[v]) {
        V2 P[3];
        for(int k = 0; k < 3; k++)
          P[k] = (tri[t][k] == v && pos) ? *pos : x[tri[t][k]];
        g = std::min(g, gammaOf(P[0], P[1], P[2]));
      }
      return g;
    }
    double minGamma(const std::vector<int> &tris) const
    {
      double g = 1.;
      for(int t : tris)
        if(aliveT[t]) g = std::min(g, triGamma(t));
      return g;
    }

    // slide a node along its curve, between its two neighbors on it, to the
    // parameter that maximizes the worst triangle of its star (sampling,
    // then golden section); true if it moved
    bool slideBest(int v)
    {
      const double lim[2] = {slideLim(v, 0), slideLim(v, 1)};
      double a = std::min(lim[0], lim[1]), b = std::max(lim[0], lim[1]);
      const double margin = 0.1 * (b - a);
      a += margin;
      b -= margin;
      if(!(b > a)) return false;
      const int c = slideCurve[v];
      auto quality = [&](double t) {
        V2 p = curvePoint(c, t);
        return starGamma(v, &p);
      };
      const double g0 = starGamma(v);
      double bt = tpar[v], bg = g0;
      const int N = 8;
      for(int k = 0; k <= N; k++) {
        double t = a + (b - a) * k / N;
        double g = quality(t);
        if(g > bg) {
          bg = g;
          bt = t;
        }
      }
      double lo = std::max(a, bt - (b - a) / N);
      double hi = std::min(b, bt + (b - a) / N);
      const double r = 0.5 * (std::sqrt(5.) - 1);
      double t1 = hi - r * (hi - lo), t2 = lo + r * (hi - lo);
      double g1 = quality(t1), g2 = quality(t2);
      for(int it = 0; it < 12; it++) {
        if(g1 > g2) {
          hi = t2;
          t2 = t1;
          g2 = g1;
          t1 = hi - r * (hi - lo);
          g1 = quality(t1);
        }
        else {
          lo = t1;
          t1 = t2;
          g1 = g2;
          t2 = lo + r * (hi - lo);
          g2 = quality(t2);
        }
      }
      if(g1 > bg) {
        bg = g1;
        bt = t1;
      }
      if(g2 > bg) {
        bg = g2;
        bt = t2;
      }
      if(!(bg > g0 + 1e-12)) return false;
      x[v] = curvePoint(c, bt);
      tpar[v] = bt;
      return true;
    }
  };

  // global smoothing, node by node: each node to the ODT position, only if
  // the worst triangle of its star does not get worse (half the step is
  // tried when the full one is refused); the nodes on curves slide along
  // them
  void smoothODT(Mesh &m, int iters);

  // the triangle mesh of a planar surface in the frame of its plane: read
  // from the surface, then written back
  class Face {
  public:
    // the nodes (x, onCurve: on a curve or a point) and the triangles
    std::vector<V2> x;
    std::vector<char> onCurve;
    std::vector<std::array<int, 3>> tri;

    explicit Face(GFace *gf);
    // no triangles, or no plane
    bool empty() const { return x.empty(); }
    // let the nodes of the curves of the surface slide along them, except on
    // the curves whose nodes another mesh uses or whose distribution is
    // imposed; the number of sliding nodes
    int setupSliding(Mesh &m);
    // write the nodes back
    void write(const Mesh &m);

  private:
    GFace *_gf;
    std::vector<MVertex *> _verts;
    std::unordered_map<MVertex *, int> _id;
    SPoint3 _origin;
    SVector3 _e1, _e2;
    std::vector<GEdge *> _curves;
    std::unordered_map<MVertex *, std::vector<MVertex *>> _curveNb;
    V2 _to2D(double X, double Y, double Z) const;
    SPoint3 _to3D(V2 p) const;
  };

} // namespace planar

#endif
