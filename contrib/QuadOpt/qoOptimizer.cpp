// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.

// Local optimization of a mixed triangle/quad surface mesh, one face at a time.
//
//  - The face is imported into a half-edge complex (qoHalfEdge.h).
//  - A cavity is a small disk of cells. Every way of re-meshing it with the same
//    boundary (with or without one or two interior points) is a candidate.
//  - A candidate, like a nodal move (tangent-plane Winslow projected on the CAD),
//    is applied only if the energy decreases and all its cells are valid, so the
//    process terminates. The energy is the shape of the cells plus a valence term
//    after Kinney (CleanUp, 1997): a node should have angle/90 quads around it.
//  - A work queue schedules cavities around what changed.
//  - Warping is not in the energy: an invalid or too warped quad is finally split
//    in two triangles along the diagonal closest to the CAD.

#include "qoOptimizer.h"
#include "qoHalfEdge.h"
#include "smallCavityWinslow.h"
#include "GModel.h"
#include "GFace.h"
#include "GEdge.h"
#include "GPoint.h"
#include "GmshMessage.h"
#include "MLine.h"
#include "MQuadrangle.h"
#include "MTriangle.h"
#include "MVertex.h"
#include "SPoint2.h"
#include "SPoint3.h"
#include "SVector3.h"
#include <algorithm>
#include <cmath>
#include <deque>
#include <functional>
#include <limits>
#include <set>
#include <unordered_map>

namespace QuadOpt {
  namespace {

    using Cell = HalfEdgeMesh::Cell;
    using Points = std::vector<SVector3>;

    // ------------------------------------------------------------------------
    // Energy model
    // ------------------------------------------------------------------------

    constexpr double kTriangleCost = 0.3; // a triangle costs this much extra
    constexpr double kValenceWeight = 0.03;
    constexpr double kMinQuality = 1.e-3; // below: the cell is not valid
    constexpr double kGain = 1.e-3; // minimal energy drop of a rewrite
    constexpr double kSmoothGain = 1.e-4; // minimal energy drop of a move
    constexpr double kCadTolerance = 0.03; // centroid-to-CAD / mean edge length
    constexpr double kCadSlack = 0.1; // a rewrite may cut the CAD this much more
    constexpr double kMaxWarping = 25.; // degrees; a quad above is split
    constexpr double kMinSplitQuality = 0.2; // triangles of a split: ~10 deg
    constexpr double kFlatQuality = 0.1; // a quad below (angle > ~174) is split
    constexpr double kMinCadAlignment = 0.3; // cosine(cell normal, CAD normal)
    constexpr std::size_t kMaxLoop = 10; // largest cavity boundary
    constexpr std::size_t kMaxCandidates = 4000;

    // Area-weighted normal of a polygon, and its unit version (zero if null).
    SVector3 areaNormal(const SVector3 *p, int n)
    {
      SVector3 normal(0., 0., 0.);
      for(int i = 1; i + 1 < n; ++i)
        normal += crossprod(p[i] - p[0], p[i + 1] - p[0]);
      return normal;
    }

    SVector3 meanNormal(const SVector3 *p, int n)
    {
      SVector3 normal = areaNormal(p, n);
      if(normal.norm() > 0.) normal.normalize();
      return normal;
    }

    // Alignment of a cell with the CAD: cosine between its normal and the mean of
    // the CAD normals at its vertices; -1 if these diverge too much (a cell too
    // large for the curvature).
    double alignment(const SVector3 *p, const SVector3 *nv, int n)
    {
      SVector3 mean(0., 0., 0.);
      for(int i = 0; i < n; ++i) mean += nv[i] * (1. / n);
      if(mean.norm() < 0.7) return -1.;
      mean.normalize();
      return dot(meanNormal(p, n), mean);
    }

    // Angle between two vectors in degrees (90 if one is null).
    double degrees(const SVector3 &a, const SVector3 &b)
    {
      const double la = a.norm(), lb = b.norm();
      if(!(la > 0.) || !(lb > 0.)) return 90.;
      return std::acos(std::max(-1., std::min(1., dot(a, b) / (la * lb)))) *
             180. / M_PI;
    }

    double cornerAngle(const SVector3 *p, int n, int i)
    {
      return degrees(p[(i + n - 1) % n] - p[i], p[(i + 1) % n] - p[i]);
    }

    // Largest angle between the normals of the two triangles of a quad, over
    // both diagonals.
    double warping(const SVector3 *p)
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

    // Smallest signed corner sine, measured in the cell's own mean plane, times
    // an aspect factor; at most 1. Negative or tiny means invalid: reflex
    // corner, degenerate edge, or normal opposed to the reference normal.
    double quality(const SVector3 *p, int n, const SVector3 &nref)
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

    // A piece of a candidate: valid, and a quad neither nearly flat nor warped
    // beyond the limits (otherwise a merge would recreate what the final split
    // removes, forever).
    bool acceptable(double q, const SVector3 *p, int n)
    {
      return n == 3 ? q > kMinQuality
                    : q >= kFlatQuality && warping(p) <= kMaxWarping;
    }

    double cost(double q, int n)
    {
      q = std::max(q, -1.);
      const double bad = std::max(0., 0.3 - q);
      return (1. - q) * (1. - q) + 10. * bad * bad +
             (n == 3 ? kTriangleCost : 0.);
    }

    // A node with n cells around an angle theta (degrees) should have theta/90
    // of them. Ignored if a triangle touches the node.
    double valenceCost(int n, double theta)
    {
      const double d = n - theta / 90.;
      return kValenceWeight * d * d;
    }

    // ------------------------------------------------------------------------
    // Candidates and cavities
    // ------------------------------------------------------------------------

    struct Piece {
      int n;
      std::array<int, 4> v; // indices in the cavity loop; loop size = interior 1
    };

    struct Candidate {
      std::vector<Piece> pieces;
      int interior = 0; // new points, at indices loop.size() and loop.size() + 1
      SVector3 center[2]; // first guesses for them
    };

    // A disk of cells, with everything needed to judge a replacement.
    struct Cavity {
      std::vector<int> cells;
      std::vector<int> loop; // oriented boundary
      std::vector<int> inner; // vertices strictly inside (all movable)
      Points P; // loop positions
      SVector3 normal; // mean normal of the loop
      std::vector<int> count; // old cells at each loop vertex
      std::vector<double> theta; // angle around each loop vertex, degrees
      std::vector<char> triangle; // a triangle outside the cavity touches it
      Points N; // CAD normals at the loop vertices, then at the interior points
      int triangles = 0;
      double energy = 0.; // current energy, valence included
      double deviation = -1.; // CAD deviation of the cells, computed lazily
      int size() const { return int(loop.size()); }
    };

    // Laplacian relaxation of the interior points of a candidate, loop fixed: a
    // cheap stand-in for judging it after smoothing.
    void relax(Candidate &candidate, const Points &P)
    {
      const int m = int(P.size());
      Points Q = P;
      for(int k = 0; k < candidate.interior; ++k) Q.push_back(candidate.center[k]);
      for(int iteration = 0; iteration < 4; ++iteration)
        for(int k = 0; k < candidate.interior; ++k) {
          SVector3 sum(0., 0., 0.);
          int n = 0;
          for(const Piece &piece : candidate.pieces)
            for(int i = 0; i < piece.n; ++i)
              if(piece.v[i] == m + k) {
                sum += Q[piece.v[(i + 1) % piece.n]] + Q[piece.v[(i + piece.n - 1) % piece.n]];
                n += 2;
              }
          if(n) Q[m + k] = sum * (1. / n);
        }
      for(int k = 0; k < candidate.interior; ++k) candidate.center[k] = Q[m + k];
    }

    class FaceOptimizer {
    public:
      explicit FaceOptimizer(GFace *gf) : _gf(gf) {}
      bool build();
      void run();
      void sync();

    private:
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
      std::set<std::uint64_t> _protected; // edges of embedded curves
      std::deque<int> _cellQueue, _vertexQueue;
      std::vector<char> _cellQueued, _vertexQueued;
      bool _final = false; // terminal phase: quads may be split
      std::size_t _rewrites = 0, _splits = 0, _moves = 0, _cells0 = 0, _tri0 = 0;

      // -- import ----------------------------------------------------------
      bool skip(const char *why) const
      {
        Msg::Warning("QuadOpt: face %d left unchanged: %s", _gf->tag(), why);
        return false;
      }
      bool orient(std::vector<Cell> &cells);
      static std::uint64_t edgeKey(int a, int b)
      {
        return HalfEdgeMesh::key(std::min(a, b), std::max(a, b));
      }

      // -- geometry --------------------------------------------------------
      Points pointsOf(const Cell &c) const
      {
        Points p;
        for(int i = 0; i < c.n; ++i) p.push_back(_v[c.v[i]].p);
        return p;
      }
      bool ensureUV(int id);
      bool project(const SVector3 &x, const double *guess, SVector3 &out,
                   double *uv) const;
      double deviation(const Cell &c);
      double maxDeviation(const std::vector<Cell> &cells);
      SVector3 normalOf(int w, const SVector3 &fallback);
      double align(const Cell &c);
      double energyOf(const std::vector<int> &cells, const SVector3 &nref,
                      bool *valid = nullptr);
      double selfQuality(const Cell &c) const;
      double angleAround(int w) const;
      bool touchesTriangle(int w) const;

      // -- nodal smoothing -------------------------------------------------
      bool winslowProposal(int w, SVector3 &normal, SVector3 &proposal);
      bool smoothVertex(int w);

      // -- cavity rewrites -------------------------------------------------
      bool describe(const std::vector<int> &cells, Cavity &cavity);
      void partitions(const Cavity &cavity, int maxTriangles,
                      std::vector<Candidate> &out) const;
      void stars(const Cavity &cavity, std::vector<Candidate> &out) const;
      double energyOf(const Cavity &cavity, const Candidate &candidate,
                      const Points &Q, int *triangles) const;
      bool placeInterior(const Cavity &cavity, const Candidate &candidate,
                         SVector3 *points, double (*uv)[2]);
      bool commit(Cavity &cavity, const Candidate &candidate,
                  const SVector3 *points, double (*uv)[2]);
      bool tryCavity(const std::vector<int> &cells);
      bool needsSplit(const Cell &c) const;
      bool splitQuad(int c);
      bool attempt(int c);

      // -- scheduler -------------------------------------------------------
      void pushCell(int c)
      {
        if(c >= 0 && !_cellQueued[c]) _cellQueued[c] = 1, _cellQueue.push_back(c);
      }
      void pushVertex(int w)
      {
        if(!_v[w].fixed && !_vertexQueued[w])
          _vertexQueued[w] = 1, _vertexQueue.push_back(w);
      }
      void growQueues()
      {
        _cellQueued.resize(_he.cells.size(), 0);
        _vertexQueued.resize(_v.size(), 0);
      }
      // Queue the cells created by a rewrite, and their neighbors.
      void pushAround(const std::vector<int> &created)
      {
        growQueues();
        for(int c : created) {
          pushCell(c);
          for(int i = 0; i < _he.cells[c].n; ++i) pushCell(_he.across(c, i));
        }
      }
      // Invalid cells first (Kinney: chevrons and bowties before the rest).
      void pushAllCells()
      {
        for(int pass = 0; pass < 2; ++pass)
          for(std::size_t c = 0; c < _he.cells.size(); ++c)
            if(_he.cells[c].alive &&
               (selfQuality(_he.cells[c]) <= kMinQuality) == (pass == 0))
              pushCell(int(c));
      }
      void smoothQueued();
      void rounds(int maximum);
      void smoothAll();
    };

    // ------------------------------------------------------------------------
    // Import and export
    // ------------------------------------------------------------------------

    bool FaceOptimizer::build()
    {
      if(_gf->quadrangles.empty()) return false;
      std::vector<MElement *> elements(_gf->triangles.begin(),
                                       _gf->triangles.end());
      elements.insert(elements.end(), _gf->quadrangles.begin(),
                      _gf->quadrangles.end());
      std::unordered_map<MVertex *, int> id;
      std::vector<Cell> cells;
      for(MElement *e : elements) {
        if(e->getPolynomialOrder() != 1) return skip("high-order elements");
        Cell cell;
        cell.n = e->getNumVertices();
        for(int i = 0; i < cell.n; ++i) {
          MVertex *mv = e->getVertex(i);
          auto it = id.find(mv);
          if(it == id.end()) {
            it = id.emplace(mv, _he.addVertex()).first;
            Vert vert;
            vert.mv = mv;
            vert.p = SVector3(mv->x(), mv->y(), mv->z());
            vert.fixed = mv->onWhat() != _gf;
            vert.hasUV = !vert.fixed && mv->getParameter(0, vert.uv[0]) &&
                         mv->getParameter(1, vert.uv[1]);
            _v.push_back(vert);
          }
          cell.v[i] = it->second;
        }
        cells.push_back(cell);
      }
      if(!orient(cells)) return skip("not orientable or non-manifold");
      for(const Cell &c : cells)
        if(_he.add(c) < 0) return skip("overlapping cells");
      for(GEdge *ge : _gf->embeddedEdges())
        for(MLine *l : ge->lines) {
          auto a = id.find(l->getVertex(0)), b = id.find(l->getVertex(1));
          if(a != id.end() && b != id.end())
            _protected.insert(edgeKey(a->second, b->second));
        }
      growQueues();
      return true;
    }

    // Orient every connected component coherently (neighbors traverse their
    // shared edge in opposite directions), then along the CAD normal. False if
    // the face is not orientable or has a non-manifold edge.
    bool FaceOptimizer::orient(std::vector<Cell> &cells)
    {
      const int count = int(cells.size());
      std::unordered_map<std::uint64_t, std::vector<int> > byEdge;
      for(int k = 0; k < count; ++k)
        for(int i = 0; i < cells[k].n; ++i)
          byEdge[edgeKey(cells[k].v[i], cells[k].v[(i + 1) % cells[k].n])]
            .push_back(k);
      for(const auto &entry : byEdge)
        if(entry.second.size() > 2) return false;
      auto traverses = [&](int k, int a, int b) { // input orientation: a -> b ?
        const Cell &c = cells[k];
        for(int i = 0; i < c.n; ++i)
          if(c.v[i] == a && c.v[(i + 1) % c.n] == b) return true;
        return false;
      };

      std::vector<char> flipped(count, 0), seen(count, 0);
      for(int root = 0; root < count; ++root) {
        if(seen[root]) continue;
        std::vector<int> component = {root};
        seen[root] = 1;
        for(std::size_t h = 0; h < component.size(); ++h) {
          const int k = component[h];
          for(int i = 0; i < cells[k].n; ++i) {
            const int a = cells[k].v[i], b = cells[k].v[(i + 1) % cells[k].n];
            for(int j : byEdge[edgeKey(a, b)]) {
              if(j == k) continue;
              const bool wanted = traverses(j, a, b) == !flipped[k];
              if(!seen[j]) {
                seen[j] = 1;
                flipped[j] = wanted;
                component.push_back(j);
              }
              else if(bool(flipped[j]) != wanted)
                return false; // not orientable
            }
          }
        }
        // Along the CAD normal, on a sample of the component.
        int vote = 0;
        const std::size_t stride = std::max<std::size_t>(1, component.size() / 200);
        for(std::size_t h = 0; h < component.size(); h += stride) {
          const Cell &c = cells[component[h]];
          if(!ensureUV(c.v[0])) continue;
          Points p = pointsOf(c);
          if(flipped[component[h]]) std::reverse(p.begin(), p.end());
          const double d = dot(
            meanNormal(p.data(), c.n),
            _gf->normal(SPoint2(_v[c.v[0]].uv[0], _v[c.v[0]].uv[1])));
          vote += d > 0. ? 1 : (d < 0. ? -1 : 0);
        }
        if(vote < 0)
          for(int k : component) flipped[k] = !flipped[k];
      }
      for(int k = 0; k < count; ++k)
        if(flipped[k])
          std::reverse(cells[k].v.begin(), cells[k].v.begin() + cells[k].n);
      return true;
    }

    // Write the optimized complex back to the face.
    void FaceOptimizer::sync()
    {
      for(Vert &v : _v) {
        if(v.fixed) continue;
        if(!v.mv) {
          v.mv =
            new MFaceVertex(v.p.x(), v.p.y(), v.p.z(), _gf, v.uv[0], v.uv[1]);
          _gf->mesh_vertices.push_back(v.mv);
        }
        else {
          v.mv->setXYZ(v.p.x(), v.p.y(), v.p.z());
          v.mv->setParameter(0, v.uv[0]);
          v.mv->setParameter(1, v.uv[1]);
        }
      }
      for(MTriangle *t : _gf->triangles) delete t;
      for(MQuadrangle *q : _gf->quadrangles) delete q;
      _gf->triangles.clear();
      _gf->quadrangles.clear();
      // Gmsh orients a face from its first element only (orientMeshGFace): list
      // the best-shaped triangle and quad first, so that a nearly flat first
      // element cannot reverse the whole face.
      int best[5] = {-1, -1, -1, -1, -1};
      double bestQuality[5] = {-2., -2., -2., -2., -2.};
      for(int c = 0; c < int(_he.cells.size()); ++c)
        if(_he.cells[c].alive) {
          const int n = _he.cells[c].n;
          const double q = selfQuality(_he.cells[c]);
          if(q > bestQuality[n]) bestQuality[n] = q, best[n] = c;
        }
      auto emit = [&](int c) {
        const Cell &cell = _he.cells[c];
        MVertex *w[4];
        for(int i = 0; i < cell.n; ++i) w[i] = _v[cell.v[i]].mv;
        if(cell.n == 3)
          _gf->triangles.push_back(new MTriangle(w[0], w[1], w[2]));
        else
          _gf->quadrangles.push_back(new MQuadrangle(w[0], w[1], w[2], w[3]));
      };
      for(int n : {3, 4})
        if(best[n] >= 0) emit(best[n]);
      for(int c = 0; c < int(_he.cells.size()); ++c)
        if(_he.cells[c].alive && c != best[3] && c != best[4]) emit(c);

      std::set<MVertex *> removed; // movable vertices no cell uses anymore
      for(std::size_t w = 0; w < _v.size(); ++w)
        if(!_v[w].fixed && _he.star[w].empty()) removed.insert(_v[w].mv);
      auto &owned = _gf->mesh_vertices;
      owned.erase(std::remove_if(owned.begin(), owned.end(),
                                 [&](MVertex *v) { return removed.count(v); }),
                  owned.end());
      for(MVertex *v : removed) delete v;
      _gf->deleteVertexArrays();
      Msg::Info("QuadOpt face %d: cells %zu -> %zu, triangles %zu -> %zu, "
                "rewrites=%zu splits=%zu moves=%zu",
                _gf->tag(), _cells0,
                _gf->triangles.size() + _gf->quadrangles.size(), _tri0,
                _gf->triangles.size(), _rewrites, _splits, _moves);
    }

    // ------------------------------------------------------------------------
    // Geometry
    // ------------------------------------------------------------------------

    bool FaceOptimizer::ensureUV(int id)
    {
      Vert &v = _v[id];
      if(v.hasUV) return true;
      SPoint2 uv;
      if(_gf->geomType() == GEntity::DiscreteSurface)
        uv = _gf->parFromPoint(SPoint3(v.p.x(), v.p.y(), v.p.z()), true, true);
      else if(!v.mv || !reparamMeshVertexOnFace(v.mv, _gf, uv, true, false))
        return false;
      if(!std::isfinite(uv.x()) || !std::isfinite(uv.y())) return false;
      v.uv[0] = uv.x();
      v.uv[1] = uv.y();
      v.hasUV = true;
      return true;
    }

    // Closest point on the CAD surface and its parameters.
    bool FaceOptimizer::project(const SVector3 &x, const double *guess,
                                SVector3 &out, double *uv) const
    {
      const GPoint gp = _gf->closestPoint(SPoint3(x.x(), x.y(), x.z()), guess);
      if(!gp.succeeded()) return false;
      out = SVector3(gp.x(), gp.y(), gp.z());
      uv[0] = gp.u();
      uv[1] = gp.v();
      return std::isfinite(out.norm());
    }

    // Distance of the cell centroid to the CAD, relative to the mean edge
    // length: large when the cell cuts through the geometry.
    double FaceOptimizer::deviation(const Cell &c)
    {
      const Points p = pointsOf(c);
      SVector3 centroid(0., 0., 0.);
      double h = 0.;
      for(int i = 0; i < c.n; ++i) {
        centroid += p[i] * (1. / c.n);
        h += (p[(i + 1) % c.n] - p[i]).norm() / c.n;
      }
      if(!(h > 0.) || !ensureUV(c.v[0])) return 1.e9;
      SVector3 q;
      double uv[2];
      if(!project(centroid, _v[c.v[0]].uv, q, uv)) return 1.e9;
      return (q - centroid).norm() / h;
    }

    double FaceOptimizer::maxDeviation(const std::vector<Cell> &cells)
    {
      double result = 0.;
      for(const Cell &c : cells) result = std::max(result, deviation(c));
      return result;
    }

    // CAD normal at a vertex (cached); the fallback if it cannot be evaluated.
    SVector3 FaceOptimizer::normalOf(int w, const SVector3 &fallback)
    {
      Vert &v = _v[w];
      if(!v.hasN && ensureUV(w)) {
        v.n = _gf->normal(SPoint2(v.uv[0], v.uv[1]));
        if(v.n.norm() > 0.) v.n.normalize(), v.hasN = true;
      }
      return v.hasN ? v.n : fallback;
    }

    double FaceOptimizer::align(const Cell &c)
    {
      const Points p = pointsOf(c);
      const SVector3 fallback = meanNormal(p.data(), c.n);
      SVector3 nv[4];
      for(int i = 0; i < c.n; ++i) nv[i] = normalOf(c.v[i], fallback);
      return alignment(p.data(), nv, c.n);
    }

    // Sum of cell costs; valid is false if one cell is not valid.
    double FaceOptimizer::energyOf(const std::vector<int> &cells,
                                   const SVector3 &nref, bool *valid)
    {
      double energy = 0.;
      if(valid) *valid = true;
      for(int id : cells) {
        const Cell &c = _he.cells[id];
        const Points p = pointsOf(c);
        const double q = quality(p.data(), c.n, nref);
        energy += cost(align(c) > kMinCadAlignment ? q : -1., c.n);
        if(valid && !(q > kMinQuality)) *valid = false;
      }
      return energy;
    }

    double FaceOptimizer::selfQuality(const Cell &c) const
    {
      const Points p = pointsOf(c);
      return quality(p.data(), c.n, meanNormal(p.data(), c.n));
    }

    // Sum of the corner angles of the cells around w, in degrees.
    double FaceOptimizer::angleAround(int w) const
    {
      double theta = 0.;
      for(int id : _he.star[w]) {
        const Cell &c = _he.cells[id];
        const Points p = pointsOf(c);
        for(int i = 0; i < c.n; ++i)
          if(c.v[i] == w) theta += cornerAngle(p.data(), c.n, i);
      }
      return theta;
    }

    bool FaceOptimizer::touchesTriangle(int w) const
    {
      for(int id : _he.star[w])
        if(_he.cells[id].n == 3) return true;
      return false;
    }

    // ------------------------------------------------------------------------
    // Nodal smoothing
    // ------------------------------------------------------------------------

    // Winslow in the tangent plane of the star of w: w is the only unknown, the
    // other vertices of the star are fixed. Returns the new position of w (not
    // yet on the CAD) and the mean normal of the star.
    bool FaceOptimizer::winslowProposal(int w, SVector3 &normal,
                                        SVector3 &proposal)
    {
      const std::vector<int> &star = _he.star[w];
      normal = SVector3(0., 0., 0.);
      for(int c : star)
        normal += areaNormal(pointsOf(_he.cells[c]).data(), _he.cells[c].n);
      if(!(normal.norm() > 0.)) return false;
      normal.normalize();
      const SVector3 axis =
        std::abs(normal.x()) < 0.6 ? SVector3(1, 0, 0) : SVector3(0, 1, 0);
      SVector3 t1 = axis - normal * dot(axis, normal);
      t1.normalize();
      const SVector3 t2 = crossprod(normal, t1); // (t1, t2, normal) is direct

      // Local chart: coordinates in the tangent plane, orientation +1.
      std::unordered_map<int, std::size_t> local;
      std::vector<std::array<double, 2> > uv;
      std::vector<bool> fixed;
      std::vector<std::array<std::size_t, 3> > tris;
      std::vector<std::array<std::size_t, 4> > quads;
      const SVector3 origin = _v[w].p;
      auto localId = [&](int v) {
        auto it = local.find(v);
        if(it != local.end()) return it->second;
        const SVector3 d = _v[v].p - origin;
        local.emplace(v, uv.size());
        uv.push_back({{dot(d, t1), dot(d, t2)}});
        fixed.push_back(v != w);
        return uv.size() - 1;
      };
      for(int c : star) {
        const Cell &cell = _he.cells[c];
        if(cell.n == 3)
          tris.push_back({{localId(cell.v[0]), localId(cell.v[1]),
                           localId(cell.v[2])}});
        else
          quads.push_back({{localId(cell.v[0]), localId(cell.v[1]),
                            localId(cell.v[2]), localId(cell.v[3])}});
      }
      const auto result = QuadOpt::optimizeLocalSurfacePatchWinslow(
        uv, fixed, tris, quads, 1., QuadOpt::SmallCavityWinslowOptions());
      if(!result.success) return false;
      const std::size_t k = local[w];
      proposal = origin + t1 * uv[k][0] + t2 * uv[k][1];
      return true;
    }

    // Move w to the Winslow position projected on the CAD, if the energy of its
    // star decreases, its cells stay valid and it does not leave the CAD.
    bool FaceOptimizer::smoothVertex(int w)
    {
      if(_v[w].fixed || _he.star[w].empty() || !ensureUV(w)) return false;
      const std::vector<int> star = _he.star[w];
      SVector3 normal, proposal, projected;
      double uv[2];
      if(!winslowProposal(w, normal, proposal) ||
         !project(proposal, _v[w].uv, projected, uv))
        return false;

      std::vector<Cell> cells;
      for(int c : star) cells.push_back(_he.cells[c]);
      const double before = energyOf(star, normal);
      const double deviationBefore = maxDeviation(cells);
      const Vert saved = _v[w];
      _v[w].p = projected;
      _v[w].uv[0] = uv[0], _v[w].uv[1] = uv[1];
      _v[w].hasN = false;
      bool valid;
      const double after = energyOf(star, normal, &valid);
      if(valid && after < before - kSmoothGain &&
         maxDeviation(cells) <= std::max(deviationBefore, kCadTolerance))
        return true;
      _v[w] = saved;
      return false;
    }

    // ------------------------------------------------------------------------
    // Cavity rewrites
    // ------------------------------------------------------------------------

    // Collect everything about a set of cells that candidates are judged on.
    // False if the set is not a small disk, or cannot be re-meshed freely.
    bool FaceOptimizer::describe(const std::vector<int> &cells, Cavity &cavity)
    {
      cavity.cells = cells;
      if(!_he.loop(cells, cavity.loop) || cavity.size() < 3 ||
         cavity.size() > int(kMaxLoop))
        return false;
      auto indexOf = [](const std::vector<int> &v, int x) {
        return int(std::find(v.begin(), v.end(), x) - v.begin());
      };
      auto inCavity = [&](int c) { return indexOf(cells, c) < int(cells.size()); };
      cavity.count.assign(cavity.size(), 0);
      for(int id : cells) {
        const Cell &c = _he.cells[id];
        cavity.triangles += c.n == 3;
        for(int i = 0; i < c.n; ++i) {
          const int w = c.v[i], k = indexOf(cavity.loop, w);
          if(k < cavity.size())
            ++cavity.count[k];
          else if(indexOf(cavity.inner, w) == int(cavity.inner.size())) {
            if(_v[w].fixed) return false;
            cavity.inner.push_back(w);
          }
          // An edge of an embedded curve must not disappear.
          if(_protected.count(edgeKey(w, _he.next(c, i))) &&
             inCavity(_he.across(id, i)))
            return false;
        }
      }
      for(int w : cavity.loop) {
        cavity.P.push_back(_v[w].p);
        cavity.theta.push_back(angleAround(w));
        char outside = 0;
        for(int id : _he.star[w])
          if(_he.cells[id].n == 3 && !inCavity(id)) outside = 1;
        cavity.triangle.push_back(outside);
      }
      cavity.normal = meanNormal(cavity.P.data(), cavity.size());
      if(!(cavity.normal.norm() > 0.)) return false;
      SVector3 mean(0., 0., 0.);
      for(int w : cavity.loop) {
        cavity.N.push_back(normalOf(w, cavity.normal));
        mean += cavity.N.back() * (1. / cavity.size());
      }
      const SVector3 inner =
        mean.norm() > 0. ? mean * (1. / mean.norm()) : cavity.normal;
      cavity.N.push_back(inner);
      cavity.N.push_back(inner);

      cavity.energy = energyOf(cells, cavity.normal);
      for(int k = 0; k < cavity.size(); ++k)
        if(!touchesTriangle(cavity.loop[k]))
          cavity.energy += valenceCost(int(_he.star[cavity.loop[k]].size()),
                                       cavity.theta[k]);
      for(int w : cavity.inner)
        if(!touchesTriangle(w))
          cavity.energy += valenceCost(int(_he.star[w].size()), angleAround(w));
      return true;
    }

    // All ways to split the loop polygon into triangles and quads by
    // non-crossing diagonals. Pieces are costed on their own; every cost is
    // non-negative, so a partial sum above the current energy is cut off.
    void FaceOptimizer::partitions(const Cavity &cavity, int maxTriangles,
                                   std::vector<Candidate> &out) const
    {
      using Interval = std::pair<int, int>; // sub-polygon i..j, closed by (j,i)
      const Points &P = cavity.P;
      const double bound = cavity.energy - kGain;
      auto pieceCost = [&](int a, int b, int c, int d) {
        const SVector3 p[4] = {P[a], P[b], P[c], d < 0 ? SVector3() : P[d]};
        const int n = d < 0 ? 3 : 4;
        const double q = quality(p, n, cavity.normal);
        const SVector3 nv[4] = {cavity.N[a], cavity.N[b], cavity.N[c],
                                d < 0 ? SVector3() : cavity.N[d]};
        return acceptable(q, p, n) && alignment(p, nv, n) > kMinCadAlignment
                 ? cost(q, n)
                 : std::numeric_limits<double>::infinity();
      };
      std::function<void(std::vector<Interval>, std::vector<Piece> &, double,
                         int)>
        split = [&](std::vector<Interval> todo, std::vector<Piece> &current,
                    double energy, int triangles) {
          if(out.size() >= kMaxCandidates) return;
          while(!todo.empty() && todo.back().second - todo.back().first < 2)
            todo.pop_back();
          if(todo.empty()) {
            out.emplace_back();
            out.back().pieces = current;
            return;
          }
          const int i = todo.back().first, j = todo.back().second;
          todo.pop_back();
          // The piece on edge (i,j) is a triangle (i,k,j) or a quad (i,k,l,j).
          for(int k = i + 1; k < j && triangles < maxTriangles; ++k) {
            const double e = energy + pieceCost(i, k, j, -1);
            if(!(e < bound)) continue;
            auto rest = todo;
            rest.push_back({i, k});
            rest.push_back({k, j});
            current.push_back({3, {{i, k, j, -1}}});
            split(rest, current, e, triangles + 1);
            current.pop_back();
          }
          for(int k = i + 1; k < j; ++k)
            for(int l = k + 1; l < j; ++l) {
              const double e = energy + pieceCost(i, k, l, j);
              if(!(e < bound)) continue;
              auto rest = todo;
              rest.push_back({i, k});
              rest.push_back({k, l});
              rest.push_back({l, j});
              current.push_back({4, {{i, k, l, j}}});
              split(rest, current, e, triangles);
              current.pop_back();
            }
        };
      std::vector<Piece> current;
      split({{0, cavity.size() - 1}}, current, 0., 0);
    }

    // One new interior point joined to a subset S of the loop, with gaps of 1
    // (triangle) or 2 (quad) between consecutive members of S; or two adjacent
    // interior points, each joined to every second vertex of an arc, all quads.
    void FaceOptimizer::stars(const Cavity &cavity,
                              std::vector<Candidate> &out) const
    {
      const int m = cavity.size();
      std::vector<int> S;
      std::function<void(int)> grow = [&](int last) {
        if(out.size() >= kMaxCandidates) return;
        if(S.size() >= 3 && m - last + S.front() <= 2) {
          Candidate candidate;
          candidate.interior = 1;
          SVector3 center(0., 0., 0.);
          for(std::size_t a = 0; a < S.size(); ++a) {
            const int s = S[a], t = S[(a + 1) % S.size()];
            if((t - s + m) % m == 1)
              candidate.pieces.push_back({3, {{m, s, t, -1}}});
            else
              candidate.pieces.push_back({4, {{m, s, (s + 1) % m, t}}});
            center += cavity.P[s] * (1. / S.size());
          }
          candidate.center[0] = center;
          out.push_back(candidate);
        }
        for(int gap = 1; gap <= 2 && last + gap < m; ++gap) {
          S.push_back(last + gap);
          grow(last + gap);
          S.pop_back();
        }
      };
      for(int first = 0; first <= 1; ++first) { // the smallest member is 0 or 1
        S.assign(1, first);
        grow(first);
      }
      // Arc 1 is a..b, arc 2 is b+1..a-1+m; two quads join the new points. Only
      // useful to remove triangles around a large cavity.
      for(int a = 0; a < m && m % 2 == 0 && m >= 6 && cavity.triangles > 0; ++a)
        for(int b = a + 2; b + 3 <= a + m - 1 && out.size() < kMaxCandidates;
            b += 2) {
          Candidate candidate;
          candidate.interior = 2;
          for(int k = 0; k < 2; ++k) {
            const int first = k ? b + 1 : a, last = k ? a - 1 + m : b;
            for(int s = first; s < last; s += 2)
              candidate.pieces.push_back(
                {4, {{m + k, s % m, (s + 1) % m, (s + 2) % m}}});
            candidate.center[k] = (cavity.P[first % m] + cavity.P[last % m]) * 0.5;
          }
          candidate.pieces.push_back({4, {{m, b % m, (b + 1) % m, m + 1}}});
          candidate.pieces.push_back(
            {4, {{m + 1, (a + m - 1) % m, a % m, m}}});
          relax(candidate, cavity.P);
          out.push_back(candidate);
        }
    }

    // Energy of the cavity after the candidate; Q = loop positions followed by
    // the interior point. Infinite if a cell is invalid.
    double FaceOptimizer::energyOf(const Cavity &cavity,
                                   const Candidate &candidate, const Points &Q,
                                   int *triangles) const
    {
      const int m = cavity.size();
      std::vector<int> count(m + 2, 0);
      std::vector<char> hasTriangle(m + 2, 0);
      double energy = 0., theta[2] = {0., 0.}; // angles at the interior points
      *triangles = 0;
      for(const Piece &piece : candidate.pieces) {
        SVector3 p[4];
        for(int i = 0; i < piece.n; ++i) {
          p[i] = Q[piece.v[i]];
          ++count[piece.v[i]];
          if(piece.n == 3) hasTriangle[piece.v[i]] = 1;
        }
        for(int i = 0; i < piece.n; ++i)
          if(piece.v[i] >= m)
            theta[piece.v[i] - m] += cornerAngle(p, piece.n, i);
        const double q = quality(p, piece.n, cavity.normal);
        SVector3 nv[4];
        for(int i = 0; i < piece.n; ++i) nv[i] = cavity.N[piece.v[i]];
        if(!acceptable(q, p, piece.n) ||
           alignment(p, nv, piece.n) <= kMinCadAlignment)
          return std::numeric_limits<double>::infinity();
        energy += cost(q, piece.n);
        *triangles += piece.n == 3;
      }
      for(int i = 0; i < m; ++i)
        if(!cavity.triangle[i] && !hasTriangle[i])
          energy += valenceCost(
            int(_he.star[cavity.loop[i]].size()) - cavity.count[i] + count[i],
            cavity.theta[i]);
      for(int k = 0; k < candidate.interior; ++k)
        if(!hasTriangle[m + k]) energy += valenceCost(count[m + k], theta[k]);
      return energy;
    }

    // Put the interior points on the CAD, and check that the candidate still
    // improves the energy there.
    bool FaceOptimizer::placeInterior(const Cavity &cavity,
                                      const Candidate &candidate,
                                      SVector3 *points, double (*uv)[2])
    {
      double guess[2] = {0., 0.};
      int known = 0;
      for(int w : cavity.loop)
        if(!_v[w].fixed && ensureUV(w)) {
          guess[0] += _v[w].uv[0], guess[1] += _v[w].uv[1], ++known;
        }
      if(!known) return false;
      guess[0] /= known, guess[1] /= known;
      Points Q = cavity.P;
      for(int k = 0; k < candidate.interior; ++k) {
        if(!project(candidate.center[k], guess, points[k], uv[k])) return false;
        Q.push_back(points[k]);
      }
      int triangles;
      return energyOf(cavity, candidate, Q, &triangles) < cavity.energy - kGain;
    }

    // Replace the cavity by the candidate, unless it cuts the CAD more than the
    // cells it replaces.
    bool FaceOptimizer::commit(Cavity &cavity, const Candidate &candidate,
                               const SVector3 *points, double (*uv)[2])
    {
      const int m = cavity.size();
      std::vector<int> ids = cavity.loop;
      ids.resize(m + 2, -1);
      for(int k = 0; k < candidate.interior; ++k) {
        ids[m + k] = _he.addVertex();
        Vert vert;
        vert.p = points[k];
        vert.uv[0] = uv[k][0], vert.uv[1] = uv[k][1];
        vert.hasUV = true;
        vert.fixed = false;
        _v.push_back(vert);
      }
      std::vector<Cell> fresh;
      for(const Piece &piece : candidate.pieces) {
        Cell cell;
        cell.n = piece.n;
        for(int i = 0; i < piece.n; ++i) cell.v[i] = ids[piece.v[i]];
        fresh.push_back(cell);
      }
      if(cavity.deviation < 0.) {
        std::vector<Cell> old;
        for(int c : cavity.cells) old.push_back(_he.cells[c]);
        cavity.deviation = maxDeviation(old);
      }
      std::vector<int> created;
      if(maxDeviation(fresh) <= cavity.deviation + kCadSlack &&
         _he.replace(cavity.cells, fresh, created)) {
        pushAround(created);
        for(int w : cavity.loop) pushVertex(w);
        for(int k = 0; k < candidate.interior; ++k) pushVertex(ids[m + k]);
        return true;
      }
      for(int k = 0; k < candidate.interior; ++k) { // undo the new vertices
        _v.pop_back();
        _he.star.pop_back();
      }
      return false;
    }

    // Best improving candidate for a set of cells: rank by energy, then try the
    // first few (the interior point is only placed on the CAD for those).
    bool FaceOptimizer::tryCavity(const std::vector<int> &cells)
    {
      Cavity cavity;
      if(!describe(cells, cavity)) return false;
      std::vector<Candidate> candidates;
      partitions(cavity, cavity.triangles, candidates); // never add triangles
      stars(cavity, candidates);

      std::vector<std::pair<double, int> > ranked;
      for(std::size_t k = 0; k < candidates.size(); ++k) {
        Points Q = cavity.P;
        for(int j = 0; j < candidates[k].interior; ++j)
          Q.push_back(candidates[k].center[j]);
        int triangles;
        const double e = energyOf(cavity, candidates[k], Q, &triangles);
        if(e < cavity.energy - kGain && triangles <= cavity.triangles)
          ranked.push_back({e, int(k)});
      }
      std::sort(ranked.begin(), ranked.end());
      for(std::size_t r = 0; r < ranked.size() && r < 4; ++r) {
        const Candidate &candidate = candidates[ranked[r].second];
        SVector3 points[2] = {candidate.center[0], candidate.center[1]};
        double uv[2][2] = {{0., 0.}, {0., 0.}};
        if(candidate.interior && !placeInterior(cavity, candidate, points, uv))
          continue;
        if(commit(cavity, candidate, points, uv)) {
          ++_rewrites;
          return true;
        }
      }
      return false;
    }

    // Cavities seeded by cell c, from the smallest to the largest.
    bool FaceOptimizer::attempt(int c)
    {
      const Cell cell = _he.cells[c];
      auto unite = [&](int a, int b) { // union of the stars of two vertices
        std::vector<int> both = _he.star[a];
        for(int d : _he.star[b])
          if(std::find(both.begin(), both.end(), d) == both.end())
            both.push_back(d);
        return both;
      };
      for(int i = 0; i < cell.n; ++i) { // the cell and one neighbor
        const int d = _he.across(c, i);
        if(d >= 0 && tryCavity({c, d})) return true;
      }
      if(cell.n == 3) { // the triangle and its neighbors
        std::vector<int> ring = {c};
        for(int i = 0; i < 3; ++i) {
          const int d = _he.across(c, i);
          if(d >= 0 && std::find(ring.begin(), ring.end(), d) == ring.end())
            ring.push_back(d);
        }
        if(ring.size() > 2 && tryCavity(ring)) return true;
      }
      for(int i = 0; i < cell.n; ++i) // star of a vertex, boundary ones included
        if(tryCavity(_he.star[cell.v[i]])) return true;
      for(int i = 0; i < cell.n; ++i) { // stars of both ends of an edge
        const int a = cell.v[i], b = _he.next(cell, i);
        if(_v[a].fixed || _v[b].fixed) continue;
        const std::vector<int> both = unite(a, b);
        if(both.size() <= 8 && tryCavity(both)) return true;
      }
      if(cell.n == 4) // stars of two opposite corners: diagonal collapse
        for(int d = 0; d < 2; ++d) {
          const std::vector<int> both = unite(cell.v[d], cell.v[d + 2]);
          if(both.size() <= 8 && tryCavity(both)) return true;
        }
      return _final && cell.n == 4 && needsSplit(cell) && splitQuad(c);
    }

    // A quad is split if it is invalid, nearly flat at a corner (Kinney: angles
    // above 160 degrees must go) or too warped.
    bool FaceOptimizer::needsSplit(const Cell &c) const
    {
      const Points p = pointsOf(c);
      return selfQuality(c) < kFlatQuality || warping(p.data()) > kMaxWarping;
    }

    // Replace a quad by two triangles along the diagonal that stays closest to
    // the CAD, among the diagonals giving two valid triangles.
    bool FaceOptimizer::splitQuad(int id)
    {
      const Cell quad = _he.cells[id];
      const Points p = pointsOf(quad);
      const SVector3 normal = meanNormal(p.data(), 4);
      const double limit = deviation(quad) + kCadSlack;
      // The triangles must be better than the quad, but not necessarily good:
      // validity first.
      const double minQuality =
        std::max(kMinQuality, std::min(kMinSplitQuality, selfQuality(quad)));
      std::vector<Cell> best;
      double bestChord = 0.;
      for(int d = 0; d < 2; ++d) {
        std::vector<Cell> pair(2);
        pair[0].n = pair[1].n = 3;
        for(int k = 0; k < 3; ++k) pair[0].v[k] = quad.v[(d + k) % 4];
        pair[1].v = {{quad.v[d], quad.v[(d + 2) % 4], quad.v[(d + 3) % 4], -1}};
        bool valid = true;
        for(const Cell &t : pair)
          valid = valid &&
                  quality(pointsOf(t).data(), 3, normal) > minQuality &&
                  align(t) > kMinCadAlignment;
        if(!valid || maxDeviation(pair) > limit) continue;
        // The new edge is the diagonal: keep the one closest to the CAD.
        const SVector3 mid = (p[d] + p[d + 2]) * 0.5;
        SVector3 q;
        double uv[2];
        const double chord =
          project(mid, _v[quad.v[d]].uv, q, uv)
            ? (q - mid).norm() / (p[d + 2] - p[d]).norm()
            : 1.e9;
        if(best.empty() || chord < bestChord) best = pair, bestChord = chord;
      }
      std::vector<int> created;
      if(best.empty() || !_he.replace({id}, best, created)) return false;
      pushAround(created);
      ++_splits;
      return true;
    }

    // ------------------------------------------------------------------------
    // Scheduler
    // ------------------------------------------------------------------------

    // Smooth the queued vertices; a move queues its neighbors and cells.
    void FaceOptimizer::smoothQueued()
    {
      std::size_t budget = 20 * _v.size() + 1000;
      while(!_vertexQueue.empty() && budget--) {
        const int w = _vertexQueue.front();
        _vertexQueue.pop_front();
        _vertexQueued[w] = 0;
        if(!smoothVertex(w)) continue;
        ++_moves;
        for(int c : _he.star[w]) {
          pushCell(c);
          for(int i = 0; i < _he.cells[c].n; ++i) pushVertex(_he.cells[c].v[i]);
        }
      }
      for(int w : _vertexQueue) _vertexQueued[w] = 0;
      _vertexQueue.clear();
    }

    // Alternate rewrites and queued smoothing until nothing changes.
    void FaceOptimizer::rounds(int maximum)
    {
      for(int round = 0; round < maximum; ++round) {
        std::size_t changed = 0;
        for(; !_cellQueue.empty(); _cellQueue.pop_front()) {
          const int c = _cellQueue.front();
          _cellQueued[c] = 0;
          if(_he.cells[c].alive && attempt(c)) ++changed;
        }
        smoothQueued();
        if(!changed && _cellQueue.empty()) break;
      }
    }

    // Smooth every vertex, until nothing moves.
    void FaceOptimizer::smoothAll()
    {
      for(int w = 0; w < int(_v.size()); ++w) pushVertex(w);
      smoothQueued();
    }

    void FaceOptimizer::run()
    {
      for(const Cell &c : _he.cells) {
        _cells0 += c.alive;
        _tri0 += c.alive && c.n == 3;
      }
      smoothAll();
      pushAllCells();
      rounds(50);
      // Terminal phase: Winslow sweeps, then the quads that must be split.
      smoothAll();
      _final = true;
      pushAllCells();
      rounds(10);
    }

  } // namespace

  void optimizeQuads(GModel *model)
  {
    for(GFace *gf : model->getFaces()) {
      FaceOptimizer optimizer(gf);
      if(!optimizer.build()) continue;
      optimizer.run();
      optimizer.sync();
    }
    model->deleteVertexArrays();
  }

} // namespace QuadOpt
