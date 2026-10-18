// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.

#include "qoPatch.h"
#include <cmath>
#include <limits>

namespace QuadOpt {

  namespace {

    using Weights = std::vector<double>;

    template <class T> bool has(const std::vector<T> &v, const T &x)
    {
      return std::find(v.begin(), v.end(), x) != v.end();
    }

    // A pattern must keep the cell count of the patch: the mesh size is the one
    // of the cells that were there (a pair of triangles counting for one quad).
    bool sizeOk(const Patch &patch, int quads)
    {
      return std::abs(quads - patch.mass) <= std::max(2., patch.slack * patch.mass);
    }

    // ------------------------------------------------------------------------
    // Star pattern
    // ------------------------------------------------------------------------

    // n blocks around a vertex of valence n, the block j spanning the spokes j
    // and j + 1 (lengths p_j, p_{j+1}). Its n corners are the far corners of the
    // blocks, and the side from corner j to corner j + 1 is p_j + p_{j+2}. For
    // n = 4 this is a structured grid (opposite sides equal), for n = 3, 5 and 6
    // one singular vertex.
    //
    // The equations link the spokes j, j + 2, j + 4, ... : one cycle for odd n,
    // two cycles of n / 2 for even n. A cycle of odd length has one solution
    // (alternating sum of its sides), a cycle of length two (n = 4) has two equal
    // equations and a free split, taken balanced.
    bool fitStar(const std::vector<int> &side, std::vector<int> &p)
    {
      const int n = int(side.size());
      if(n < 3 || n > 6) return false;
      p.assign(n, 0);
      const int cycles = n % 2 ? 1 : 2, m = n / cycles;
      for(int r = 0; r < cycles; ++r) {
        auto j = [&](int t) { return (r + 2 * t) % n; };
        if(m == 2) {
          if(side[j(0)] != side[j(1)]) return false;
          p[j(0)] = side[j(0)] / 2;
          p[j(1)] = side[j(0)] - p[j(0)];
          continue;
        }
        int alternating = 0;
        for(int t = 0; t < m; ++t) alternating += (t % 2 ? -1 : 1) * side[j(t)];
        if(alternating % 2) return false;
        p[j(0)] = alternating / 2;
        for(int t = 1; t < m; ++t) p[j(t)] = side[j(t - 1)] - p[j(t - 1)];
      }
      for(int length : p)
        if(length < 1) return false;
      return true;
    }

    int starQuads(const std::vector<int> &p)
    {
      int quads = 0;
      for(std::size_t j = 0; j < p.size(); ++j) quads += p[j] * p[(j + 1) % p.size()];
      return quads;
    }

    // The mesh of a star on a loop of S vertices: ids are their numbers in the
    // rewrite and W their positions as weights (over the B vertices of the patch
    // loop). Block j has the coordinates (s, t), 0 <= s <= p_j, 0 <= t <=
    // p_{j+1}, with the center at (0, 0), the end of spoke j at (p_j, 0), corner j
    // at (p_j, p_{j+1}) and the end of spoke j + 1 at (0, p_{j+1}). The end of
    // spoke j + 1 is the loop vertex p_j after corner j. The center is the mean
    // of the spoke ends, weighted by 1 / p_j; spokes are straight, and the inside
    // of a block is the Coons patch of its four sides.
    void meshStar(const std::vector<int> &ids, const std::vector<Weights> &W,
                  const std::vector<int> &corner, const std::vector<int> &p,
                  int B, Rewrite &rewrite)
    {
      const int n = int(corner.size()), S = int(ids.size());
      auto loop = [&](int i) { return ((i % S) + S) % S; };
      std::vector<int> end(n); // loop index of the end of spoke j
      for(int j = 0; j < n; ++j)
        end[j] = loop(corner[(j + n - 1) % n] + p[(j + n - 1) % n]);

      auto combine = [&](double a, const Weights &x, double b, const Weights &y) {
        Weights w(B);
        for(int i = 0; i < B; ++i) w[i] = a * x[i] + b * y[i];
        return w;
      };
      // New vertices get the ids B, B + 1, ...
      auto add = [&](const Weights &w) {
        rewrite.weight.push_back(w);
        return B + int(rewrite.weight.size()) - 1;
      };

      Weights center(B, 0.);
      double sum = 0.;
      for(int j = 0; j < n; ++j) sum += 1. / p[j];
      for(int j = 0; j < n; ++j) center = combine(1., center, 1. / (p[j] * sum), W[end[j]]);
      const int centerId = add(center);
      std::vector<std::vector<Weights> > spoke(n); // points of each spoke
      std::vector<std::vector<int> > spokeId(n);
      for(int j = 0; j < n; ++j)
        for(int s = 0; s <= p[j]; ++s) {
          spoke[j].push_back(combine(1. - double(s) / p[j], center,
                                     double(s) / p[j], W[end[j]]));
          spokeId[j].push_back(s == 0 ? centerId :
                               s == p[j] ? ids[end[j]] : add(spoke[j].back()));
        }

      for(int j = 0; j < n; ++j) {
        const int a = p[j], b = p[(j + 1) % n], next = (j + 1) % n;
        std::vector<int> inner((a - 1) * (b - 1) + 1);
        for(int s = 1; s < a; ++s)
          for(int t = 1; t < b; ++t) {
            const double u = double(s) / a, v = double(t) / b;
            const Weights &bottom = spoke[j][s], &left = spoke[next][t];
            const Weights &top = W[loop(corner[j] + a - s)],
                          &right = W[loop(end[j] + t)];
            Weights w = combine(1. - v, bottom, v, top);
            w = combine(1., w, 1. - u, left);
            w = combine(1., w, u, right);
            const Weights corners =
              combine(1. - u, combine(1. - v, center, v, W[end[next]]), u,
                      combine(1. - v, W[end[j]], v, W[corner[j]]));
            inner[(s - 1) * (b - 1) + t - 1] = add(combine(1., w, -1., corners));
          }
        auto id = [&](int s, int t) {
          if(s == 0 && t == 0) return centerId;
          if(t == 0) return spokeId[j][s];
          if(s == 0) return spokeId[next][t];
          if(s == a) return ids[loop(end[j] + t)];
          if(t == b) return ids[loop(corner[j] + a - s)];
          return inner[(s - 1) * (b - 1) + t - 1];
        };
        for(int s = 0; s < a; ++s)
          for(int t = 0; t < b; ++t)
            rewrite.quad.push_back(
              {{id(s, t), id(s + 1, t), id(s + 1, t + 1), id(s, t + 1)}});
      }
    }

    // The loop of a patch as the identity: vertex i has id i and position i.
    void identity(int B, std::vector<int> &ids, std::vector<Weights> &W)
    {
      ids.resize(B);
      W.assign(B, Weights(B, 0.));
      for(int i = 0; i < B; ++i) ids[i] = i, W[i][i] = 1.;
    }

    bool fitStarPattern(Patch &patch)
    {
      return fitStar(patch.side, patch.param) &&
             sizeOk(patch, starQuads(patch.param));
    }

    void buildStar(const Patch &patch, Rewrite &rewrite)
    {
      std::vector<int> ids;
      std::vector<Weights> W;
      identity(int(patch.loop.size()), ids, W);
      meshStar(ids, W, patch.corner, patch.param, int(patch.loop.size()), rewrite);
    }

    int starSingularities(const Patch &patch)
    {
      return patch.corner.size() == 4 ? 0 : 1;
    }

    // ------------------------------------------------------------------------
    // Split pattern
    // ------------------------------------------------------------------------

    // A straight chord of l edges between two points a and b of the sides cuts
    // the patch into two parts, each a star. A chord end is a corner of both
    // parts, so the corners of the two add up to those of the patch plus four:
    // four corners give 3 + 5 (a pair of singular vertices), or 4 + 4.

    // The part of the patch from loop vertex a forward to loop vertex b, closed
    // by the chord: its corners (a, those between, b) as positions in its loop,
    // and its sides.
    std::vector<int> partSides(const Patch &patch, int a, int b, int l,
                               std::vector<int> &corner)
    {
      const int B = int(patch.loop.size()), length = (b - a + B) % B;
      corner = {0};
      std::vector<int> between;
      for(int c : patch.corner) {
        const int offset = (c - a + B) % B;
        if(offset > 0 && offset < length) between.push_back(offset);
      }
      std::sort(between.begin(), between.end());
      corner.insert(corner.end(), between.begin(), between.end());
      corner.push_back(length);
      std::vector<int> side;
      for(std::size_t k = 1; k < corner.size(); ++k)
        side.push_back(corner[k] - corner[k - 1]);
      side.push_back(l);
      return side;
    }

    // Chord of least size error; param = {a, b, l}.
    bool fitSplit(Patch &patch)
    {
      const int B = int(patch.loop.size());
      std::vector<char> isCorner(B, 0);
      for(int c : patch.corner) isCorner[c] = 1;
      double best = std::numeric_limits<double>::infinity();
      std::vector<int> corner, pa, pb;
      for(int a = 0; a < B; ++a)
        for(int b = a + 1; b < B; ++b) {
          if(isCorner[a] || isCorner[b]) continue;
          for(int l = 1; l <= B / 2; ++l) {
            if(!fitStar(partSides(patch, a, b, l, corner), pa) ||
               !fitStar(partSides(patch, b, a, l, corner), pb))
              continue;
            const int quads = starQuads(pa) + starQuads(pb);
            const double error = std::abs(quads - patch.mass);
            if(sizeOk(patch, quads) && error < best)
              best = error, patch.param = {a, b, l};
          }
        }
      return best < std::numeric_limits<double>::infinity();
    }

    void buildSplit(const Patch &patch, Rewrite &rewrite)
    {
      const int B = int(patch.loop.size());
      const int a = patch.param[0], b = patch.param[1], l = patch.param[2];
      std::vector<int> ids;
      std::vector<Weights> W;
      identity(B, ids, W);
      std::vector<int> chordId(l + 1, 0); // from a (t = 0) to b (t = l)
      std::vector<Weights> chordW(l + 1);
      chordId[0] = a, chordW[0] = W[a];
      chordId[l] = b, chordW[l] = W[b];
      for(int t = 1; t < l; ++t) {
        chordW[t].resize(B);
        for(int i = 0; i < B; ++i)
          chordW[t][i] = (1. - double(t) / l) * W[a][i] + double(t) / l * W[b][i];
        rewrite.weight.push_back(chordW[t]);
        chordId[t] = B + int(rewrite.weight.size()) - 1;
      }
      // Part from `from` to `to`, then back along the chord.
      for(int part = 0; part < 2; ++part) {
        const int from = part ? b : a, to = part ? a : b;
        std::vector<int> corner, p, partIds;
        std::vector<Weights> partW;
        const std::vector<int> side = partSides(patch, from, to, l, corner);
        fitStar(side, p);
        for(int k = from;; k = (k + 1) % B) {
          partIds.push_back(ids[k]), partW.push_back(W[k]);
          if(k == to) break;
        }
        for(int t = 1; t < l; ++t) {
          const int u = part ? t : l - t; // a -> b after b -> a before
          partIds.push_back(chordId[u]), partW.push_back(chordW[u]);
        }
        meshStar(partIds, partW, corner, p, B, rewrite);
      }
    }

    int splitSingularities(const Patch &patch)
    {
      std::vector<int> corner;
      return (partSides(patch, patch.param[0], patch.param[1], patch.param[2],
                        corner).size() != 4) +
             (partSides(patch, patch.param[1], patch.param[0], patch.param[2],
                        corner).size() != 4);
    }

    // ------------------------------------------------------------------------
    // Search
    // ------------------------------------------------------------------------

    // Corners and sides of a loop from the angle of the cells at each of its
    // vertices; false if some vertex is neither a corner nor a point of a side.
    bool corners(const HalfEdgeMesh &he, const Probe &mesh,
                 const std::vector<int> &cells, Patch &patch)
    {
      const int B = int(patch.loop.size());
      if(B % 2) return false; // quads only
      patch.corner.clear();
      for(int i = 0; i < B; ++i) {
        double degrees = 0.;
        for(int id : he.star[patch.loop[i]])
          if(has(cells, id))
            for(int k = 0; k < he.cells[id].n; ++k)
              if(he.cells[id].v[k] == patch.loop[i])
                degrees += mesh.degrees(id, k);
        const int quads = int(std::lround(degrees / 90.));
        if(quads < 1 || quads > 2) return false;
        if(quads == 1) patch.corner.push_back(i);
      }
      const int n = int(patch.corner.size());
      if(n < 3) return false;
      patch.side.resize(n);
      for(int j = 0; j < n; ++j)
        patch.side[j] =
          (patch.corner[(j + 1) % n] - patch.corner[j] + B) % B;
      return true;
    }

    // Triangles, and interior vertices of valence other than four.
    int defects(const HalfEdgeMesh &he, const Probe &mesh,
                const std::vector<int> &cells, const std::vector<int> &loop,
                bool &free)
    {
      int count = 0;
      std::vector<int> inner;
      for(int id : cells) {
        count += he.cells[id].n == 3;
        for(int k = 0; k < he.cells[id].n; ++k) {
          const int w = he.cells[id].v[k];
          if(has(loop, w) || has(inner, w)) continue;
          inner.push_back(w);
          count += he.star[w].size() != 4;
          free = free && mesh.movable(w);
        }
      }
      return count;
    }

  } // namespace

  const std::vector<Pattern> &patterns()
  {
    static const std::vector<Pattern> table = {
      {"star", fitStarPattern, buildStar, starSingularities},
      {"split", fitSplit, buildSplit, splitSingularities}};
    return table;
  }

  bool findPatch(const HalfEdgeMesh &he, const Probe &mesh,
                 const std::vector<int> &seeds, std::size_t maxCells,
                 double sizeSlack, Patch &patch)
  {
    std::vector<int> &cells = patch.cells;
    cells.clear();
    for(int w : seeds)
      for(int id : he.star[w])
        if(!has(cells, id)) cells.push_back(id);
    patch.slack = sizeSlack;
    while(!cells.empty() && cells.size() <= maxCells) {
      bool free = true;
      if(he.loop(cells, patch.loop) && corners(he, mesh, cells, patch)) {
        const int count = defects(he, mesh, cells, patch.loop, free);
        patch.mass = 0.;
        for(int id : cells) patch.mass += he.cells[id].n == 3 ? 0.5 : 1.;
        if(free)
          for(std::size_t k = 0; k < patterns().size(); ++k) {
            const Pattern &pattern = patterns()[k];
            if(pattern.fit(patch) && count > pattern.singularities(patch)) {
              patch.pattern = int(k);
              return true;
            }
          }
      }
      // Next ring: every cell touching a vertex of the patch.
      const std::size_t before = cells.size();
      for(std::size_t h = 0; h < before; ++h)
        for(int k = 0; k < he.cells[cells[h]].n; ++k)
          for(int id : he.star[he.cells[cells[h]].v[k]])
            if(!has(cells, id)) cells.push_back(id);
      if(cells.size() == before) break;
    }
    return false;
  }

} // namespace QuadOpt
