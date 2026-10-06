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
#include "qoFace.h"
#include "smallCavityWinslow.h"
#include "GFace.h"
#include "GModel.h"
#include "GmshMessage.h"
#include "SPoint2.h"
#include <algorithm>
#include <cmath>
#include <deque>
#include <functional>
#include <limits>
#include <unordered_map>

namespace QuadOpt {
  namespace {

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
    constexpr std::size_t kMaxLoop = 12; // largest cavity boundary
    constexpr std::size_t kMaxCandidates = 4000;

    // A piece of a candidate: valid, and a quad neither nearly flat nor warped
    // beyond the limits (otherwise a merge would recreate what the final split
    // removes, forever).
    bool acceptable(double q, const SVector3 *p, int n)
    {
      return n == 3 ? q > kMinQuality
                    : q >= kFlatQuality && warpingWithin(p, kMaxWarping);
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

    // At most twelve pieces: a candidate allocates nothing.
    struct Pieces {
      Piece p[12];
      int n = 0;
      void push_back(const Piece &piece) { p[n++] = piece; }
      void pop_back() { --n; }
      const Piece *begin() const { return p; }
      const Piece *end() const { return p + n; }
    };

    struct Candidate {
      Pieces pieces;
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

    class FaceOptimizer : public FaceMesh, public Relaxer {
    public:
      explicit FaceOptimizer(GFace *gf) : FaceMesh(gf) {}
      void run();
      void finish(); // write the result back and report
      bool smooth(int w) override
      {
        if(!smoothVertex(w)) return false;
        ++_moves;
        return true;
      }
      bool rewrite(const std::vector<int> &cells) override
      {
        return tryCavity(cells);
      }

    private:
      std::deque<int> _cellQueue, _vertexQueue;
      std::vector<char> _cellQueued, _vertexQueued;
      bool _final = false; // terminal phase: quads may be split
      std::size_t _rewrites = 0, _splits = 0, _moves = 0, _cells0 = 0, _tri0 = 0;

      double energyOf(const std::vector<int> &cells, const SVector3 &nref,
                      bool *valid = nullptr);
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
      bool placeInterior(Cavity &cavity, const Candidate &candidate,
                         SVector3 *points, double (*uv)[2]);
      bool commit(Cavity &cavity, const Candidate &candidate,
                  const SVector3 *points, double (*uv)[2]);
      bool tryCavity(const std::vector<int> &cells);
      bool needsSplit(const Cell &c) const;
      bool splitQuad(int c);
      std::vector<int> pathToTriangle(int c, int depth) const;
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
    // Energy of existing cells
    // ------------------------------------------------------------------------

    // Sum of cell costs; valid is false if one cell is not valid.
    double FaceOptimizer::energyOf(const std::vector<int> &cells,
                                   const SVector3 &nref, bool *valid)
    {
      double energy = 0.;
      if(valid) *valid = true;
      for(int id : cells) {
        const Cell &c = _he.cells[id];
        const Corners p = pointsOf(c);
        const double q = quality(p.data(), c.n, nref);
        energy += cost(align(c) > kMinCadAlignment ? q : -1., c.n);
        if(valid && !(q > kMinQuality)) *valid = false;
      }
      return energy;
    }

    // Sum of the corner angles of the cells around w, in degrees.
    double FaceOptimizer::angleAround(int w) const
    {
      double theta = 0.;
      for(int id : _he.star[w]) {
        const Cell &c = _he.cells[id];
        const Corners p = pointsOf(c);
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
      // One unknown vertex: a few iterations from the current position suffice.
      QuadOpt::SmallCavityWinslowOptions options;
      options.maxInnerIterations = 25;
      options.maxOuterIterations = 2;
      options.maxLineSearchSteps = 20;
      options.harmonicInitialization = false;
      const auto result =
        QuadOpt::optimizeLocalSurfacePatchWinslow(uv, fixed, tris, quads, 1., options);
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
      const Vert saved = _v[w];
      _v[w].p = projected;
      _v[w].uv[0] = uv[0], _v[w].uv[1] = uv[1];
      _v[w].hasN = false;
      bool valid;
      const double after = energyOf(star, normal, &valid);
      if(valid && after < before - kSmoothGain) {
        // Projections on the CAD are costly: only measured for improving moves.
        const Vert moved = _v[w];
        const double deviationAfter = maxDeviation(cells);
        _v[w] = saved;
        if(deviationAfter <= std::max(maxDeviation(cells), kCadTolerance)) {
          _v[w] = moved;
          return true;
        }
        return false;
      }
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
      std::function<void(std::vector<Interval>, Pieces &, double, int)>
        split = [&](std::vector<Interval> todo, Pieces &current,
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
      Pieces current;
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
      int count[kMaxLoop + 2] = {};
      char hasTriangle[kMaxLoop + 2] = {};
      double energy = 0., theta[2] = {0., 0.}; // angles at the interior points
      const double bound = cavity.energy - kGain; // every term is non-negative
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
        if(!(energy < bound)) return std::numeric_limits<double>::infinity();
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
    bool FaceOptimizer::placeInterior(Cavity &cavity, const Candidate &candidate,
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
        // Judge the candidate with the true CAD normal of the new point.
        SVector3 n = _gf->normal(SPoint2(uv[k][0], uv[k][1]));
        if(n.norm() > 0.) cavity.N[cavity.size() + k] = n * (1. / n.norm());
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
      for(int k = 0; k < candidate.interior; ++k)
        ids[m + k] = addVertex(points[k], uv[k]);
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
      Points Q = cavity.P;
      Q.resize(cavity.size() + 2);
      for(std::size_t k = 0; k < candidates.size(); ++k) {
        for(int j = 0; j < candidates[k].interior; ++j)
          Q[cavity.size() + j] = candidates[k].center[j];
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

    // Cells from triangle c to the nearest other triangle through edge
    // neighbors, at most `depth` steps away (empty if there is none).
    std::vector<int> FaceOptimizer::pathToTriangle(int c, int depth) const
    {
      std::vector<int> order = {c}, parent = {-1}, level = {0};
      for(std::size_t h = 0; h < order.size() && level[h] < depth; ++h)
        for(int i = 0; i < _he.cells[order[h]].n; ++i) {
          const int d = _he.across(order[h], i);
          if(d < 0 || std::find(order.begin(), order.end(), d) != order.end())
            continue;
          order.push_back(d), parent.push_back(int(h)), level.push_back(level[h] + 1);
          if(_he.cells[d].n != 3) continue;
          std::vector<int> path;
          for(int k = int(order.size()) - 1; k >= 0; k = parent[k])
            path.push_back(order[k]);
          return path;
        }
      return {};
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
        // The strip of cells to the nearest other triangle: re-meshing it moves
        // a triangle through the quads, as a chain of TQ -> QT swaps would.
        const std::vector<int> path = pathToTriangle(c, 4);
        if(path.size() > 2 && tryCavity(path)) return true;
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
      const Corners p = pointsOf(c);
      return selfQuality(c) < kFlatQuality || warping(p.data()) > kMaxWarping;
    }

    // Replace a quad by two triangles along the diagonal that stays closest to
    // the CAD, among the diagonals giving two valid triangles.
    bool FaceOptimizer::splitQuad(int id)
    {
      const Cell quad = _he.cells[id];
      const Corners p = pointsOf(quad);
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
      growQueues();
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

    void FaceOptimizer::finish()
    {
      sync();
      Msg::Info("QuadOpt face %d: cells %zu -> %zu, triangles %zu -> %zu, "
                "rewrites=%zu splits=%zu moves=%zu",
                _gf->tag(), _cells0,
                _gf->triangles.size() + _gf->quadrangles.size(), _tri0,
                _gf->triangles.size(), _rewrites, _splits, _moves);
    }

  } // namespace

  bool optimizeFace(GFace *gf, bool fronts)
  {
    FaceOptimizer optimizer(gf);
    if(!optimizer.build()) return false;
    if(fronts) advanceFronts(optimizer, optimizer);
    optimizer.run();
    optimizer.finish();
    return true;
  }

  void optimizeQuads(GModel *model)
  {
    for(GFace *gf : model->getFaces())
      if(!gf->quadrangles.empty()) optimizeFace(gf, false);
    model->deleteVertexArrays();
  }

} // namespace QuadOpt
