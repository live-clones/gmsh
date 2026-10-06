// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.

#pragma once

#include "qoHalfEdge.h"
#include "SVector3.h"
#include <algorithm>
#include <cmath>
#include <functional>
#include <set>
#include <vector>

class GFace;
class MVertex;

namespace QuadOpt {

  using Cell = HalfEdgeMesh::Cell;
  using Points = std::vector<SVector3>;

  // Area-weighted normal of a polygon, and its unit version (zero if null).
  inline SVector3 areaNormal(const SVector3 *p, int n)
  {
    SVector3 normal(0., 0., 0.);
    for(int i = 1; i + 1 < n; ++i)
      normal += crossprod(p[i] - p[0], p[i + 1] - p[0]);
    return normal;
  }

  inline SVector3 meanNormal(const SVector3 *p, int n)
  {
    SVector3 normal = areaNormal(p, n);
    if(normal.norm() > 0.) normal.normalize();
    return normal;
  }

  // Angle between two vectors in degrees (90 if one is null).
  inline double degrees(const SVector3 &a, const SVector3 &b)
  {
    const double la = a.norm(), lb = b.norm();
    if(!(la > 0.) || !(lb > 0.)) return 90.;
    return std::acos(std::max(-1., std::min(1., dot(a, b) / (la * lb)))) * 180. /
           M_PI;
  }

  inline double cornerAngle(const SVector3 *p, int n, int i)
  {
    return degrees(p[(i + n - 1) % n] - p[i], p[(i + 1) % n] - p[i]);
  }

  // Largest angle between the normals of the two triangles of a quad, over both
  // diagonals.
  inline double warping(const SVector3 *p)
  {
    double worst = 0.;
    for(int d = 0; d < 2; ++d) {
      const SVector3 t1[3] = {p[d], p[(d + 1) % 4], p[(d + 2) % 4]};
      const SVector3 t2[3] = {p[d], p[(d + 2) % 4], p[(d + 3) % 4]};
      const SVector3 a = areaNormal(t1, 3), b = areaNormal(t2, 3);
      if(!(a.norm() > 0.) || !(b.norm() > 0.)) return 180.;
      worst = std::max(worst, degrees(a, b));
    }
    return worst;
  }

  // Smallest signed corner sine, measured in the cell's own mean plane, times an
  // aspect factor; at most 1. Negative or tiny means invalid: reflex corner,
  // degenerate edge, or normal opposed to the reference normal.
  inline double quality(const SVector3 *p, int n, const SVector3 &nref)
  {
    SVector3 normal = areaNormal(p, n);
    const double area = normal.norm();
    if(!(area > 0.)) return -1.;
    normal *= 1. / area;
    if(dot(normal, nref) <= 0.) return -1.;
    double lmin = 1.e300, lmax = 0., sine = 1.e300;
    for(int i = 0; i < n; ++i) {
      const SVector3 a = p[i] - p[(i + n - 1) % n], b = p[(i + 1) % n] - p[i];
      const double la = a.norm(), lb = b.norm();
      if(!(la > 0.) || !(lb > 0.)) return -1.;
      lmin = std::min(lmin, lb);
      lmax = std::max(lmax, lb);
      sine = std::min(sine, dot(crossprod(a, b), normal) / (la * lb));
    }
    if(n == 3) sine /= 0.8660254037844386; // equilateral corner
    return std::min(sine, 1.) * std::min(1., 1.5 * lmin / lmax);
  }

  // Alignment of a cell with the CAD: cosine between its normal and the mean of
  // the CAD normals at its vertices; -1 if these diverge too much (a cell too
  // large for the curvature).
  inline double alignment(const SVector3 *p, const SVector3 *nv, int n)
  {
    SVector3 mean(0., 0., 0.);
    for(int i = 0; i < n; ++i) mean += nv[i] * (1. / n);
    if(mean.norm() < 0.7) return -1.;
    mean.normalize();
    return dot(meanNormal(p, n), mean);
  }

  // One surface mesh as an oriented half-edge complex, imported from a GFace and
  // written back to it. Everything the optimizer (qoOptimizer.cpp) and the
  // front advancement (qoQMorph.cpp) share: topology, CAD geometry, protected
  // edges. Vertices on the CAD boundary are fixed; the others may move and be
  // removed.
  class FaceMesh {
    friend class FrontAdvance;

  public:
    explicit FaceMesh(GFace *gf) : _gf(gf) {}
    bool build(); // false (face untouched) if it cannot be handled
    void sync(); // write the result back to the face

  protected:
    struct Vert {
      SVector3 p;
      double uv[2] = {0., 0.};
      bool hasUV = false;
      SVector3 n; // CAD normal, valid if hasN
      bool hasN = false;
      bool fixed = true; // on the CAD boundary: never moves, never removed
      MVertex *mv = nullptr; // null until a new vertex is synchronized
    };

    GFace *_gf;
    HalfEdgeMesh _he;
    std::vector<Vert> _v;
    std::set<std::uint64_t> _protected; // edges of CAD and embedded curves

    static std::uint64_t edgeKey(int a, int b)
    {
      return HalfEdgeMesh::key(std::min(a, b), std::max(a, b));
    }
    bool skip(const char *why) const;
    bool orient(std::vector<Cell> &cells);

    Points pointsOf(const Cell &c) const
    {
      Points p;
      for(int i = 0; i < c.n; ++i) p.push_back(_v[c.v[i]].p);
      return p;
    }
    int addVertex(const SVector3 &p, const double *uv); // new movable vertex
    bool ensureUV(int id);
    bool project(const SVector3 &x, const double *guess, SVector3 &out,
                 double *uv) const;
    SVector3 normalOf(int w, const SVector3 &fallback); // cached CAD normal
    double align(const Cell &c);
    double fit(const Cell &c); // quality against the CAD normal
    double selfQuality(const Cell &c) const;
    double deviation(const Cell &c);
    double maxDeviation(const std::vector<Cell> &cells);
  };

  // What the front advancement asks of the optimizer: relax a vertex, and
  // re-mesh a set of cells (a failed front is merged with a neighbor).
  struct Relaxer {
    virtual bool smooth(int vertex) = 0;
    virtual bool rewrite(const std::vector<int> &cells) = 0;
  };

  // Advance quadrangle fronts into the triangles of a face (qoQMorph.cpp).
  void advanceFronts(FaceMesh &mesh, Relaxer &relaxer);

} // namespace QuadOpt
