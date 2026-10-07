// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.

#include "qoPatch.h"
#include <cmath>

namespace QuadOpt {

  namespace {

    // Star pattern: n blocks around a vertex of valence n, the block j spanning
    // the spokes j and j + 1 (lengths p_j, p_{j+1}). Its n corners are the far
    // corners of the blocks, and the side from corner j to corner j + 1 is
    // p_j + p_{j+2}. For n = 4 this is a structured grid (opposite sides equal),
    // for n = 3, 5 and 6 one singular vertex.
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

    int starSingularities(int corners) { return corners == 4 ? 0 : 1; }

    // The mesh of a star patch: block j has the coordinates (s, t), 0 <= s <=
    // p_j, 0 <= t <= p_{j+1}, with the center at (0, 0), the end of spoke j at
    // (p_j, 0), corner j at (p_j, p_{j+1}) and the end of spoke j + 1 at
    // (0, p_{j+1}). The end of spoke j + 1 is the loop vertex p_j after corner j.
    // The center is the mean of the spoke ends, weighted by 1 / p_j; spokes are
    // straight, and the inside of a block is the Coons patch of its four sides.
    void buildStar(const Patch &patch, Rewrite &rewrite)
    {
      const int n = int(patch.corner.size()), B = int(patch.loop.size());
      const std::vector<int> &p = patch.param;
      auto loop = [&](int i) { return ((i % B) + B) % B; };
      std::vector<int> end(n); // loop index of the end of spoke j
      for(int j = 0; j < n; ++j)
        end[j] = loop(patch.corner[(j + n - 1) % n] + p[(j + n - 1) % n]);

      using Weights = std::vector<double>;
      auto unit = [&](int i) {
        Weights w(B, 0.);
        w[loop(i)] = 1.;
        return w;
      };
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
      for(int j = 0; j < n; ++j) center[end[j]] += 1. / (p[j] * sum);
      const int centerId = add(center);
      std::vector<std::vector<Weights> > spoke(n); // points of each spoke
      std::vector<std::vector<int> > spokeId(n);
      for(int j = 0; j < n; ++j)
        for(int s = 0; s <= p[j]; ++s) {
          spoke[j].push_back(combine(1. - double(s) / p[j], center,
                                     double(s) / p[j], unit(end[j])));
          spokeId[j].push_back(s == 0 ? centerId :
                               s == p[j] ? loop(end[j]) : add(spoke[j].back()));
        }

      rewrite.quad.clear();
      for(int j = 0; j < n; ++j) {
        const int a = p[j], b = p[(j + 1) % n], next = (j + 1) % n;
        std::vector<int> inner((a - 1) * (b - 1) + 1);
        for(int s = 1; s < a; ++s)
          for(int t = 1; t < b; ++t) {
            const double u = double(s) / a, v = double(t) / b;
            const Weights &bottom = spoke[j][s], &left = spoke[next][t];
            const Weights top = unit(patch.corner[j] + a - s),
                          right = unit(end[j] + t);
            Weights w = combine(1. - v, bottom, v, top);
            w = combine(1., w, 1. - u, left);
            w = combine(1., w, u, right);
            const Weights corners =
              combine(1. - u, combine(1. - v, center, v, unit(end[next])), u,
                      combine(1. - v, unit(end[j]), v, unit(patch.corner[j])));
            inner[(s - 1) * (b - 1) + t - 1] = add(combine(1., w, -1., corners));
          }
        auto id = [&](int s, int t) {
          if(s == 0 && t == 0) return centerId;
          if(t == 0) return spokeId[j][s];
          if(s == 0) return spokeId[next][t];
          if(s == a) return loop(end[j] + t);
          if(t == b) return loop(patch.corner[j] + a - s);
          return inner[(s - 1) * (b - 1) + t - 1];
        };
        for(int s = 0; s < a; ++s)
          for(int t = 0; t < b; ++t)
            rewrite.quad.push_back(
              {{id(s, t), id(s + 1, t), id(s + 1, t + 1), id(s, t + 1)}});
      }
    }

    template <class T> bool has(const std::vector<T> &v, const T &x)
    {
      return std::find(v.begin(), v.end(), x) != v.end();
    }

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
      {"star", fitStar, buildStar, starSingularities}};
    return table;
  }

  bool findPatch(const HalfEdgeMesh &he, const Probe &mesh,
                 const std::vector<int> &seeds, std::size_t maxCells,
                 Patch &patch)
  {
    std::vector<int> &cells = patch.cells;
    cells.clear();
    for(int w : seeds)
      for(int id : he.star[w])
        if(!has(cells, id)) cells.push_back(id);
    while(!cells.empty() && cells.size() <= maxCells) {
      bool free = true;
      if(he.loop(cells, patch.loop) && corners(he, mesh, cells, patch)) {
        const int count = defects(he, mesh, cells, patch.loop, free);
        if(free)
          for(std::size_t k = 0; k < patterns().size(); ++k) {
            const Pattern &pattern = patterns()[k];
            if(count > pattern.singularities(int(patch.corner.size())) &&
               pattern.fit(patch.side, patch.param)) {
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
