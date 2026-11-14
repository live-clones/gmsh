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
#include <climits>
#include <cmath>
#include <cstdio>
#include <functional>
#include <limits>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <unordered_map>
#include "DiscreteCADHeal.h"
#include "DiscreteCADWinding.h"

void removeBadTriangles(std::vector<std::array<int, 3> > &triangles,
                        DiscreteCADHealReport &report,
                        std::vector<std::size_t> *kept)
{
  if(kept) kept->clear();
  std::set<std::array<int, 3> > seen;
  std::size_t j = 0;
  for(std::size_t i = 0; i < triangles.size(); i++) {
    const std::array<int, 3> &t = triangles[i];
    if(t[0] == t[1] || t[1] == t[2] || t[2] == t[0]) {
      report.degenerate++;
      continue;
    }
    std::array<int, 3> key = t;
    std::sort(key.begin(), key.end());
    if(!seen.insert(key).second) {
      report.duplicated++;
      continue;
    }
    if(kept) kept->push_back(i);
    triangles[j++] = t;
  }
  triangles.resize(j);
}

void orientTriangles(const std::vector<std::array<double, 3> > &x,
                     std::vector<std::array<int, 3> > &triangles,
                     DiscreteCADHealReport &report,
                     std::vector<int> *componentOf, std::vector<char> *turned)
{
  const std::size_t nt = triangles.size();
  std::map<std::pair<int, int>, std::vector<std::size_t> > edges;
  for(std::size_t i = 0; i < nt; i++)
    for(int k = 0; k < 3; k++)
      edges[std::minmax(triangles[i][k], triangles[i][(k + 1) % 3])].push_back(i);
  auto forwards = [&](std::size_t i, int a, int b) {
    for(int k = 0; k < 3; k++)
      if(triangles[i][k] == a && triangles[i][(k + 1) % 3] == b) return true;
    return false;
  };
  // (the last reason each triangle was turned over for, and whether it was
  // an odd number of times)
  std::vector<char> why(nt, 0), odd(nt, 0);
  auto reverse = [&](std::size_t i, char reason) {
    std::swap(triangles[i][1], triangles[i][2]);
    why[i] = reason;
    odd[i] = !odd[i];
  };

  // the components, each oriented as its first triangle, across the edges of
  // two triangles
  std::vector<int> component(nt, -1);
  std::vector<std::vector<std::size_t> > components;
  for(std::size_t s = 0; s < nt; s++) {
    if(component[s] >= 0) continue;
    const int c = (int)components.size();
    components.push_back({s});
    component[s] = c;
    std::vector<std::size_t> stack(1, s);
    while(!stack.empty()) {
      const std::size_t i = stack.back();
      stack.pop_back();
      for(int k = 0; k < 3; k++) {
        const int a = triangles[i][k], b = triangles[i][(k + 1) % 3];
        const std::vector<std::size_t> &l = edges[std::minmax(a, b)];
        if(l.size() != 2) continue;
        const std::size_t j = l[0] == i ? l[1] : l[0];
        if(component[j] >= 0) continue;
        if(forwards(j, a, b)) reverse(j, 1);
        component[j] = c;
        components[c].push_back(j);
        stack.push_back(j);
      }
    }
  }
  report.components = (int)components.size();

  // the closed ones outwards: their volume positive
  std::vector<char> closed(components.size(), 1);
  for(auto &e : edges)
    if(e.second.size() != 2)
      for(std::size_t i : e.second) closed[component[i]] = 0;
  auto volume = [&](const std::vector<std::size_t> &c) {
    double v = 0.;
    for(std::size_t i : c) {
      const std::array<double, 3> &a = x[triangles[i][0]], &b = x[triangles[i][1]],
                                  &d = x[triangles[i][2]];
      v += a[0] * (b[1] * d[2] - b[2] * d[1]) - a[1] * (b[0] * d[2] - b[2] * d[0]) +
           a[2] * (b[0] * d[1] - b[1] * d[0]);
    }
    return v / 6.;
  };
  for(std::size_t c = 0; c < components.size(); c++) {
    if(!closed[c]) continue;
    report.closed++;
    if(volume(components[c]) < 0.) {
      for(std::size_t i : components[c]) reverse(i, 2);
      report.reversedClosed++;
    }
  }

  // the open ones, by decreasing size: turned over if the winding number of
  // all the triangles is then nearer to whole numbers, and less negative, on
  // both sides of them
  auto penalty = [](double w) {
    if(w < 0.) return w * w;
    const double r = w - std::round(w);
    return r * r;
  };
  std::vector<std::size_t> open;
  for(std::size_t c = 0; c < components.size(); c++)
    if(!closed[c]) open.push_back(c);
  std::sort(open.begin(), open.end(), [&](std::size_t a, std::size_t b) {
    return components[a].size() > components[b].size();
  });
  for(int pass = 0; pass < 3; pass++) {
    bool changed = false;
    std::unique_ptr<DiscreteCADWinding> all(new DiscreteCADWinding(x, triangles));
    for(std::size_t c : open) {
      const std::vector<std::size_t> &tc = components[c];
      // (the size of the component, and the points a tenth of it away from
      // some of its triangles, on both sides)
      double lo[3] = {1e300, 1e300, 1e300}, hi[3] = {-1e300, -1e300, -1e300};
      for(std::size_t i : tc)
        for(int n : triangles[i])
          for(int k = 0; k < 3; k++) {
            lo[k] = std::min(lo[k], x[n][k]);
            hi[k] = std::max(hi[k], x[n][k]);
          }
      const double size = std::sqrt((hi[0] - lo[0]) * (hi[0] - lo[0]) +
                                    (hi[1] - lo[1]) * (hi[1] - lo[1]) +
                                    (hi[2] - lo[2]) * (hi[2] - lo[2]));
      if(!(size > 0.)) continue;
      const double d = 0.1 * size;
      std::vector<std::array<double, 3> > q;
      const std::size_t samples = 48;
      for(std::size_t s = 0; s < std::min(samples, tc.size()); s++) {
        const std::array<int, 3> &t = triangles[tc[s * tc.size() / std::min(samples, tc.size())]];
        double u[3], v[3], g[3];
        for(int k = 0; k < 3; k++) {
          u[k] = x[t[1]][k] - x[t[0]][k];
          v[k] = x[t[2]][k] - x[t[0]][k];
          g[k] = (x[t[0]][k] + x[t[1]][k] + x[t[2]][k]) / 3.;
        }
        double n[3] = {u[1] * v[2] - u[2] * v[1], u[2] * v[0] - u[0] * v[2],
                       u[0] * v[1] - u[1] * v[0]};
        const double l = std::sqrt(n[0] * n[0] + n[1] * n[1] + n[2] * n[2]);
        if(!(l > 0.)) continue;
        for(int side = -1; side <= 1; side += 2)
          q.push_back({{g[0] + side * d * n[0] / l, g[1] + side * d * n[1] / l,
                        g[2] + side * d * n[2] / l}});
      }
      if(q.empty()) continue;
      std::vector<std::array<int, 3> > own;
      for(std::size_t i : tc) own.push_back(triangles[i]);
      DiscreteCADWinding mine(x, own);
      std::vector<double> w, m;
      all->evaluate(q, w);
      mine.evaluate(q, m);
      double now = 0., turned = 0.;
      for(std::size_t i = 0; i < q.size(); i++) {
        now += penalty(w[i]);
        turned += penalty(w[i] - 2. * m[i]);
      }
      if(turned < 0.7 * now - 1.e-3 * q.size()) {
        for(std::size_t i : tc) reverse(i, 3);
        report.reversedOpen++;
        changed = true;
        all.reset(new DiscreteCADWinding(x, triangles));
      }
    }
    if(!changed) break;
  }
  if(componentOf) *componentOf = component;
  for(std::size_t i = 0; i < nt; i++)
    if(odd[i]) report.reversedTriangles++;
  if(turned) {
    turned->assign(nt, 0);
    for(std::size_t i = 0; i < nt; i++)
      if(odd[i]) (*turned)[i] = why[i];
  }
}

void findDefects(const std::vector<std::array<double, 3> > &x,
                 const std::vector<std::array<int, 3> > &triangles,
                 DiscreteCADDefects &d)
{
  d = DiscreteCADDefects();
  const std::size_t nt = triangles.size();
  auto sub = [&](int a, int b, double v[3]) {
    for(int k = 0; k < 3; k++) v[k] = x[b][k] - x[a][k];
  };
  auto norm = [](const double v[3]) {
    return std::sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
  };

  // the triangles
  std::set<std::array<int, 3> > seen;
  for(std::size_t i = 0; i < nt; i++) {
    const std::array<int, 3> &t = triangles[i];
    if(t[0] == t[1] || t[1] == t[2] || t[2] == t[0]) {
      d.degenerate.push_back(i);
      continue;
    }
    std::array<int, 3> key = t;
    std::sort(key.begin(), key.end());
    if(!seen.insert(key).second) {
      d.duplicated.push_back(i);
      continue;
    }
    double e[3][3], l[3];
    for(int k = 0; k < 3; k++) {
      sub(t[k], t[(k + 1) % 3], e[k]);
      l[k] = norm(e[k]);
    }
    const double c[3] = {e[0][1] * e[2][2] - e[0][2] * e[2][1],
                         e[0][2] * e[2][0] - e[0][0] * e[2][2],
                         e[0][0] * e[2][1] - e[0][1] * e[2][0]};
    const double area2 = norm(c);
    const double longest = std::max(l[0], std::max(l[1], l[2]));
    if(!(area2 > 1e-14 * longest * longest)) {
      d.degenerate.push_back(i);
      continue;
    }
    // (an acute angle whose sine is that of a degree or less)
    for(int k = 0; k < 3; k++) {
      const double s = area2 / (l[k] * l[(k + 2) % 3]);
      if(s < std::sin(M_PI / 180.)) {
        double dot = 0.;
        for(int m = 0; m < 3; m++) dot -= e[k][m] * e[(k + 2) % 3][m];
        if(dot > 0.) {
          d.needles.push_back(i);
          break;
        }
      }
    }
  }

  // the edges, of the triangles neither degenerate nor duplicated
  std::vector<char> bad(nt, 0);
  for(std::size_t i : d.degenerate) bad[i] = 1;
  for(std::size_t i : d.duplicated) bad[i] = 1;
  std::map<std::pair<int, int>, std::vector<std::size_t> > edges;
  for(std::size_t i = 0; i < nt; i++)
    for(int k = 0; k < 3; k++) {
      const int a = triangles[i][k], b = triangles[i][(k + 1) % 3];
      if(!bad[i]) edges[std::minmax(a, b)].push_back(i);
    }
  auto forwards = [&](std::size_t i, int a, int b) {
    for(int k = 0; k < 3; k++)
      if(triangles[i][k] == a && triangles[i][(k + 1) % 3] == b) return true;
    return false;
  };
  std::vector<std::size_t> parent(nt);
  for(std::size_t i = 0; i < nt; i++) parent[i] = i;
  std::function<std::size_t(std::size_t)> find = [&](std::size_t i) {
    while(parent[i] != i) i = parent[i] = parent[parent[i]];
    return i;
  };
  for(auto &e : edges) {
    if(e.second.size() == 1)
      d.free.push_back(e.first);
    else if(e.second.size() > 2)
      d.nonManifold.push_back(e.first);
    else {
      const std::size_t i = e.second[0], j = e.second[1];
      if(forwards(i, e.first.first, e.first.second) ==
         forwards(j, e.first.first, e.first.second))
        d.misoriented.push_back(e.first);
      parent[find(i)] = find(j);
    }
  }

  // the pieces, closed if they have no edge of one triangle or more than two
  // (none for the degenerate and duplicated triangles)
  std::map<std::size_t, int> pieceOfRoot;
  d.piece.assign(nt, -1);
  for(std::size_t i = 0; i < nt; i++) {
    if(bad[i]) continue;
    auto it = pieceOfRoot.insert({find(i), (int)pieceOfRoot.size()}).first;
    d.piece[i] = it->second;
  }
  d.closed.assign(pieceOfRoot.size(), 1);
  for(auto &e : edges)
    if(e.second.size() != 2)
      for(std::size_t i : e.second) d.closed[d.piece[i]] = 0;

  // the T-junctions: the nodes of free edges inside other free edges (within
  // a thousandth of their length), found in the cells of a grid
  if(d.free.empty()) return;
  double h = 0.;
  for(auto &e : d.free) {
    double v[3];
    sub(e.first, e.second, v);
    h += norm(v);
  }
  h /= d.free.size();
  if(!(h > 0.)) return;
  std::map<std::array<long, 3>, std::vector<int> > cells;
  auto cell = [&](const std::array<double, 3> &p) {
    return std::array<long, 3>{{(long)std::floor(p[0] / h),
                                (long)std::floor(p[1] / h),
                                (long)std::floor(p[2] / h)}};
  };
  std::set<int> ends;
  for(auto &e : d.free) {
    ends.insert(e.first);
    ends.insert(e.second);
  }
  for(int n : ends) cells[cell(x[n])].push_back(n);
  std::set<int> found;
  for(auto &e : d.free) {
    const std::array<double, 3> &a = x[e.first], &b = x[e.second];
    double ab[3];
    sub(e.first, e.second, ab);
    const double l = norm(ab);
    if(!(l > 0.)) continue;
    const double tol = 1e-3 * l;
    std::array<long, 3> lo = cell(a), hi = cell(b);
    for(int k = 0; k < 3; k++) {
      if(lo[k] > hi[k]) std::swap(lo[k], hi[k]);
      lo[k]--;
      hi[k]++;
    }
    for(long i = lo[0]; i <= hi[0]; i++)
      for(long j = lo[1]; j <= hi[1]; j++)
        for(long k = lo[2]; k <= hi[2]; k++) {
          auto it = cells.find({{i, j, k}});
          if(it == cells.end()) continue;
          for(int c : it->second) {
            if(c == e.first || c == e.second || found.count(c)) continue;
            double ac[3];
            sub(e.first, c, ac);
            const double s = (ac[0] * ab[0] + ac[1] * ab[1] + ac[2] * ab[2]) /
                             (l * l);
            if(s <= 1e-3 || s >= 1. - 1e-3) continue;
            double dist = 0.;
            for(int m = 0; m < 3; m++) {
              const double q = a[m] + s * ab[m] - x[c][m];
              dist += q * q;
            }
            if(std::sqrt(dist) < tol) found.insert(c);
          }
        }
  }
  d.tJunctions.assign(found.begin(), found.end());
}

namespace {
  // the edges of the triangles, each with its triangles, and the free ones
  void edgesOf(const std::vector<std::array<int, 3> > &t,
               std::map<std::pair<int, int>, std::vector<std::size_t> > &edges,
               std::vector<std::pair<int, int> > &free)
  {
    edges.clear();
    free.clear();
    for(std::size_t i = 0; i < t.size(); i++)
      for(int k = 0; k < 3; k++)
        edges[std::minmax(t[i][k], t[i][(k + 1) % 3])].push_back(i);
    for(auto &e : edges)
      if(e.second.size() == 1) free.push_back(e.first);
  }

  double distance2(const std::array<double, 3> &a, const std::array<double, 3> &b)
  {
    return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]) +
           (a[2] - b[2]) * (a[2] - b[2]);
  }

  // the parameter of the projection of c on the segment ab, and the square
  // of the distance from c to it
  double project(const std::array<double, 3> &a, const std::array<double, 3> &b,
                 const std::array<double, 3> &c, double &d2)
  {
    double ab[3], ac[3];
    for(int k = 0; k < 3; k++) {
      ab[k] = b[k] - a[k];
      ac[k] = c[k] - a[k];
    }
    const double l2 = ab[0] * ab[0] + ab[1] * ab[1] + ab[2] * ab[2];
    double s = l2 > 0. ? (ab[0] * ac[0] + ab[1] * ac[1] + ab[2] * ac[2]) / l2 : 0.;
    s = std::max(0., std::min(1., s));
    d2 = 0.;
    for(int k = 0; k < 3; k++) {
      const double q = a[k] + s * ab[k] - c[k];
      d2 += q * q;
    }
    return s;
  }

  // a grid by cells of size h (those with something in them), the indices of
  // points or segments in each one
  struct hashGrid {
    struct hash {
      std::size_t operator()(const std::array<long, 3> &c) const
      {
        return (std::size_t)c[0] * 73856093u ^ (std::size_t)c[1] * 19349663u ^
               (std::size_t)c[2] * 83492791u;
      }
    };
    double h;
    std::unordered_map<std::array<long, 3>, std::vector<int>, hash> cells;
    std::array<long, 3> cell(const std::array<double, 3> &p) const
    {
      return {{(long)std::floor(p[0] / h), (long)std::floor(p[1] / h),
               (long)std::floor(p[2] / h)}};
    }
    void add(int i, const std::array<double, 3> &p) { cells[cell(p)].push_back(i); }
    // (a segment in the cells of its points every half cell: each point of it
    // a quarter of a cell from one of them at most)
    void add(int i, const std::array<double, 3> &a, const std::array<double, 3> &b)
    {
      const int n = 1 + (int)std::ceil(2. * std::sqrt(distance2(a, b)) / h);
      std::array<long, 3> last = {{LONG_MIN, 0, 0}};
      for(int j = 0; j <= n; j++) {
        std::array<double, 3> p;
        for(int k = 0; k < 3; k++) p[k] = a[k] + (b[k] - a[k]) * j / n;
        const std::array<long, 3> c = cell(p);
        if(c == last) continue;
        cells[c].push_back(i);
        last = c;
      }
    }
    // the indices in the cells r cells away from the cell c
    template <class F> void ring(const std::array<long, 3> &c, long r, F f) const
    {
      for(long i = -r; i <= r; i++)
        for(long j = -r; j <= r; j++)
          for(long k = -r; k <= r; k++) {
            if(std::max(std::labs(i), std::max(std::labs(j), std::labs(k))) != r)
              continue;
            auto it = cells.find({{c[0] + i, c[1] + j, c[2] + k}});
            if(it == cells.end()) continue;
            for(int n : it->second) f(n);
          }
    }
    // the indices in the cells of the box [lo - r, hi + r]
    template <class F>
    void around(const std::array<double, 3> &lo, const std::array<double, 3> &hi,
                double r, F f) const
    {
      std::array<double, 3> a, b;
      for(int k = 0; k < 3; k++) {
        a[k] = std::min(lo[k], hi[k]) - r;
        b[k] = std::max(lo[k], hi[k]) + r;
      }
      const std::array<long, 3> ca = cell(a), cb = cell(b);
      for(long i = ca[0]; i <= cb[0]; i++)
        for(long j = ca[1]; j <= cb[1]; j++)
          for(long k = ca[2]; k <= cb[2]; k++) {
            auto it = cells.find({{i, j, k}});
            if(it == cells.end()) continue;
            for(int n : it->second) f(n);
          }
    }
  };

  // an event to come: the nodes a and b merged ('m'), or the node a inserted
  // into the free edge b ('t'), at the distance d
  struct candidate {
    double d;
    char kind;
    int a, b;
    bool operator>(const candidate &o) const
    {
      if(d != o.d) return d > o.d;
      if(kind != o.kind) return kind > o.kind;
      if(a != o.a) return a > o.a;
      return b > o.b;
    }
  };
} // namespace

void zipFreeEdges(const std::vector<std::array<double, 3> > &x,
                  std::vector<std::array<int, 3> > &t, double tolerance,
                  DiscreteCADZipReport &report, std::vector<std::size_t> *origin,
                  double reach)
{
  report = DiscreteCADZipReport();
  const double inf = std::numeric_limits<double>::infinity();
  const std::size_t n0 = t.size();
  std::vector<std::size_t> from(n0);
  std::vector<char> alive(n0, 1);
  // the triangles of each node (and some that do not have it any more)
  std::vector<std::vector<std::size_t> > at(x.size());
  for(std::size_t i = 0; i < n0; i++) {
    from[i] = i;
    if(t[i][0] == t[i][1] || t[i][1] == t[i][2] || t[i][2] == t[i][0])
      alive[i] = 0;
    else
      for(int n : t[i]) at[n].push_back(i);
  }
  auto has = [&](std::size_t i, int n) {
    return t[i][0] == n || t[i][1] == n || t[i][2] == n;
  };
  auto along = [&](int a, int b, std::vector<std::size_t> &l) {
    l.clear();
    for(std::size_t i : at[a])
      if(alive[i] && has(i, a) && has(i, b)) l.push_back(i);
  };
  std::vector<std::size_t> l;
  auto isFree = [&](int n) {
    for(std::size_t i : at[n]) {
      if(!alive[i] || !has(i, n)) continue;
      for(int m : t[i]) {
        if(m == n) continue;
        along(n, m, l);
        if(l.size() == 1) return true;
      }
    }
    return false;
  };
  // the nodes merged into others
  std::vector<int> rep(x.size());
  for(std::size_t n = 0; n < x.size(); n++) rep[n] = (int)n;
  auto find = [&](int n) {
    while(rep[n] != n) n = rep[n] = rep[rep[n]];
    return n;
  };
  // the pieces, by the triangles that are their roots (the path from each
  // triangle to its root kept: the roots it had, with the level from which
  // their piece was closed), with their triangles left and their edges of
  // one triangle or more than two
  std::vector<std::size_t> up(n0), size(n0, 1);
  std::vector<int> open(n0, 0), live(n0);
  std::vector<double> closedAt(n0, inf);
  for(std::size_t i = 0; i < n0; i++) {
    up[i] = i;
    live[i] = alive[i];
  }
  auto root = [&](std::size_t i) {
    while(up[i] != i) i = up[i];
    return i;
  };
  auto unite = [&](std::size_t i, std::size_t j) {
    i = root(i);
    j = root(j);
    if(i == j) return;
    if(size[i] < size[j]) std::swap(i, j);
    up[j] = i;
    size[i] += size[j];
    open[i] += open[j];
    live[i] += live[j];
  };
  auto roots = [&](const std::vector<std::size_t> &tri) {
    std::vector<std::size_t> r;
    for(std::size_t i : tri) r.push_back(root(i));
    std::sort(r.begin(), r.end());
    r.erase(std::unique(r.begin(), r.end()), r.end());
    return r;
  };

  // the free edges and the pieces of the input
  int freeCount = 0, openCount = 0, closedCount = 0;
  std::vector<std::pair<int, int> > odd;
  for(std::size_t i = 0; i < n0; i++) {
    if(!alive[i]) continue;
    for(int k = 0; k < 3; k++) {
      const int a = t[i][k], b = t[i][(k + 1) % 3];
      along(a, b, l);
      if(*std::min_element(l.begin(), l.end()) != i) continue;
      if(l.size() == 2)
        unite(l[0], l[1]);
      else
        odd.push_back(std::minmax(a, b));
      if(l.size() == 1) report.freeEdges.push_back(std::minmax(a, b));
    }
  }
  for(auto &e : odd) {
    along(e.first, e.second, l);
    for(std::size_t r : roots(l)) open[r]++;
  }
  for(std::size_t i = 0; i < n0; i++) {
    if(up[i] != i || !live[i]) continue;
    if(open[i])
      openCount++;
    else {
      closedCount++;
      closedAt[i] = 0.;
    }
  }
  freeCount = (int)report.freeEdges.size();
  report.freeBefore = report.freeEdges.size();
  report.open = openCount;
  report.closed = closedCount;

  // the reach of the events, the grids of the nodes and of the free edges
  std::vector<double> lengths;
  for(auto &e : report.freeEdges)
    lengths.push_back(std::sqrt(distance2(x[e.first], x[e.second])));
  double median = 0.;
  if(!lengths.empty()) {
    std::nth_element(lengths.begin(), lengths.begin() + lengths.size() / 2,
                     lengths.end());
    median = lengths[lengths.size() / 2];
  }
  reach = std::max(tolerance, reach * median);
  if(!(reach > 0.) || report.freeEdges.empty()) reach = 0.;
  report.reach = reach;
  // (a point within reach of a node, or a node within reach of a free edge,
  // is in a cell next to its cell)
  hashGrid nodes{std::max(1.5 * reach, median), {}};
  hashGrid edges{nodes.h, {}};
  std::vector<std::pair<int, int> > fe;
  std::vector<int> stamp;
  int visit = 0;
  std::vector<char> free(x.size(), 0);
  std::vector<double> nonFreeAt(x.size(), inf);
  std::priority_queue<candidate, std::vector<candidate>, std::greater<candidate> >
    queue;
  // (a node into a free edge: inside it, and its ends more than twice as far
  // from it as the edge)
  auto into = [&](int c, int id) {
    const int u = fe[id].first, v = fe[id].second;
    if(c == u || c == v) return;
    double d2;
    const double s = project(x[u], x[v], x[c], d2);
    if(s <= 0. || s >= 1. || d2 > reach * reach ||
       std::min(distance2(x[c], x[u]), distance2(x[c], x[v])) <= 4. * d2)
      return;
    queue.push({std::sqrt(d2), 't', c, id});
  };
  // (the events of a node of free edges: with the nodes of free edges, the
  // larger ones only for the nodes of the input, and into the free edges)
  auto fromNode = [&](int n, bool all) {
    nodes.around(x[n], x[n], nodes.h, [&](int m) {
      if(m == n || (!all && m < n)) return;
      const double d2 = distance2(x[n], x[m]);
      if(d2 <= reach * reach)
        queue.push({std::sqrt(d2), 'm', std::min(n, m), std::max(n, m)});
    });
    visit++;
    edges.around(x[n], x[n], edges.h, [&](int id) {
      if(stamp[id] == visit) return;
      stamp[id] = visit;
      into(n, id);
    });
  };
  auto addEdge = [&](int a, int b) {
    const int id = (int)fe.size();
    fe.push_back(std::minmax(a, b));
    stamp.push_back(0);
    edges.add(id, x[a], x[b]);
    return id;
  };
  if(reach > 0.) {
    for(auto &e : report.freeEdges) {
      addEdge(e.first, e.second);
      free[e.first] = free[e.second] = 1;
    }
    for(std::size_t n = 0; n < x.size(); n++)
      if(free[n]) nodes.add((int)n, x[n]);
    for(std::size_t n = 0; n < x.size(); n++)
      if(free[n]) fromNode((int)n, false);
  }

  // an event changes the triangles along the edges E: they and their pieces
  // taken out of the counts before it, back in after it
  std::vector<std::pair<int, int> > E;
  std::vector<std::size_t> touched;
  std::set<std::pair<int, int> > freeBefore;
  double level = 0.;
  auto collect = [&](std::vector<std::size_t> &tri) {
    for(auto &e : E) {
      along(e.first, e.second, l);
      tri.insert(tri.end(), l.begin(), l.end());
    }
  };
  auto count = [&](int sign) {
    for(auto &e : E) {
      along(e.first, e.second, l);
      if(l.size() == 1) freeCount += sign;
      if(l.size() == 0 || l.size() == 2) continue;
      for(std::size_t r : roots(l)) open[r] += sign;
    }
  };
  auto pieces = [&](int sign) {
    for(std::size_t r : roots(touched)) {
      if(!live[r]) continue;
      (open[r] ? openCount : closedCount) += sign;
      if(sign > 0) {
        if(open[r])
          closedAt[r] = inf;
        else if(closedAt[r] == inf)
          closedAt[r] = level;
      }
    }
  };
  auto start = [&]() {
    std::sort(E.begin(), E.end());
    E.erase(std::unique(E.begin(), E.end()), E.end());
    touched.clear();
    collect(touched);
    pieces(-1);
    count(-1);
    freeBefore.clear();
    for(auto &e : E) {
      along(e.first, e.second, l);
      if(l.size() == 1) freeBefore.insert(e);
    }
  };
  auto finish = [&]() {
    for(auto &e : E) {
      along(e.first, e.second, l);
      if(l.size() == 2) unite(l[0], l[1]);
    }
    count(1);
    collect(touched);
    pieces(1);
    // (the nodes that are no more, or newly, on free edges, the new free
    // edges)
    std::set<int> seen;
    for(auto &e : E)
      for(int n : {e.first, e.second}) {
        if(find(n) != n || !seen.insert(n).second) continue;
        const bool f = isFree(n);
        if(f && !free[n]) {
          free[n] = 1;
          nonFreeAt[n] = inf;
          nodes.add(n, x[n]);
          fromNode(n, true);
        }
        else if(!f && free[n]) {
          free[n] = 0;
          nonFreeAt[n] = level;
        }
      }
    for(auto &e : E) {
      if(freeBefore.count(e) || find(e.first) != e.first ||
         find(e.second) != e.second)
        continue;
      along(e.first, e.second, l);
      if(l.size() != 1) continue;
      const int id = addEdge(e.first, e.second);
      nodes.around(x[e.first], x[e.second], reach, [&](int m) {
        if(free[m] && find(m) == m) into(m, id);
      });
    }
  };
  auto kill = [&](std::size_t i) {
    alive[i] = 0;
    live[root(i)]--;
  };
  auto log = [&](char kind, int a, int b, int c) {
    report.events.push_back(
      {kind, level, a, b, c, freeCount, openCount, closedCount});
  };
  std::set<std::array<int, 3> > refused;
  auto refuse = [&](int a, int b, int c) {
    if(refused.insert(std::array<int, 3>{{a, b, c}}).second) log('r', a, b, c);
  };

  // a merged into b, unless more than two distinct triangles would be along
  // an edge (the triangles with both collapse)
  auto merge = [&](int a, int b) {
    std::map<int, std::set<std::array<int, 3> > > around;
    std::vector<std::size_t> tri;
    for(int n : {a, b})
      for(std::size_t i : at[n])
        if(alive[i] && has(i, n)) tri.push_back(i);
    std::sort(tri.begin(), tri.end());
    tri.erase(std::unique(tri.begin(), tri.end()), tri.end());
    for(std::size_t i : tri) {
      std::array<int, 3> tr = t[i];
      int seen = 0;
      for(int &n : tr) {
        if(n == a) n = b;
        if(n == b) seen++;
      }
      if(seen != 1) continue;
      std::sort(tr.begin(), tr.end());
      for(int n : tr)
        if(n != b) around[n].insert(tr);
    }
    for(auto &e : around)
      if(e.second.size() > 2) {
        refuse(std::min(a, b), std::max(a, b), -1);
        return;
      }
    E.clear();
    for(std::size_t i : tri)
      for(int k = 0; k < 3; k++) {
        const int p = t[i][k], q = t[i][(k + 1) % 3];
        const int pp = p == a ? b : p, qq = q == a ? b : q;
        E.push_back(std::minmax(p, q));
        if(pp != qq) E.push_back(std::minmax(pp, qq));
      }
    start();
    for(std::size_t i : tri)
      for(int &n : t[i])
        if(n == a) n = b;
    rep[a] = b;
    at[b] = tri;
    at[a].clear();
    std::set<std::array<int, 3> > copies;
    for(std::size_t i : tri) {
      if(t[i][0] == t[i][1] || t[i][1] == t[i][2] || t[i][2] == t[i][0]) {
        kill(i);
        continue;
      }
      std::array<int, 3> key = t[i];
      std::sort(key.begin(), key.end());
      if(!copies.insert(key).second) kill(i);
    }
    finish();
    log('m', a, b, -1);
  };

  // c inserted into the free edge uv of the triangle i, split in two, unless
  // more than two triangles would be along an edge
  auto insert = [&](int c, int u, int v, std::size_t i) {
    int k = 0;
    while(std::minmax(t[i][k], t[i][(k + 1) % 3]) != std::minmax(u, v)) k++;
    const int p = t[i][k], q = t[i][(k + 1) % 3], w = t[i][(k + 2) % 3];
    std::vector<std::size_t> pc, cq, cw;
    along(p, c, pc);
    along(c, q, cq);
    along(c, w, cw);
    if(pc.size() > 1 || cq.size() > 1 || !cw.empty()) {
      refuse(c, u, v);
      return;
    }
    E = {std::minmax(p, q), std::minmax(q, w), std::minmax(w, p),
         std::minmax(p, c), std::minmax(c, q), std::minmax(c, w)};
    start();
    const std::size_t j = t.size();
    t[i] = {{p, c, w}};
    t.push_back({{c, q, w}});
    alive.push_back(1);
    from.push_back(from[i]);
    up.push_back(j);
    size.push_back(1);
    open.push_back(0);
    live.push_back(1);
    closedAt.push_back(inf);
    // (c may have been in i before)
    if(std::find(at[c].begin(), at[c].end(), i) == at[c].end()) at[c].push_back(i);
    for(int n : {c, q, w}) at[n].push_back(j);
    finish();
    log('t', c, u, v);
  };

  // the events, from the closest; the triangles as they are when they reach
  // the tolerance
  std::vector<std::array<int, 3> > zipped;
  std::vector<std::size_t> zippedFrom;
  std::size_t within = 0;
  bool taken = false;
  auto take = [&]() {
    for(std::size_t i = 0; i < t.size(); i++)
      if(alive[i]) {
        zipped.push_back(t[i]);
        zippedFrom.push_back(from[i]);
      }
    report.freeAfter = freeCount;
    within = report.events.size();
    taken = true;
  };
  // (at most so many events, should they never end)
  const std::size_t most = 100 * (report.freeEdges.size() + 1);
  while(!queue.empty() && report.events.size() < most) {
    const candidate e = queue.top();
    queue.pop();
    if(!taken && e.d > tolerance) take();
    if(e.kind == 'm') {
      const int a = find(e.a), b = find(e.b);
      if(a == b || !free[a] || !free[b]) continue;
      const double d = std::sqrt(distance2(x[a], x[b]));
      if(d > e.d) {
        // (moved away by a merge before)
        if(d <= reach) queue.push({d, 'm', std::min(a, b), std::max(a, b)});
        continue;
      }
      level = std::max(level, e.d);
      merge(std::max(a, b), std::min(a, b));
    }
    else {
      const int c = find(e.a);
      if(!free[c]) continue;
      if(c != e.a) {
        // (merged before: the node it was merged into)
        into(c, e.b);
        continue;
      }
      const int u = fe[e.b].first, v = fe[e.b].second;
      if(find(u) != u || find(v) != v) continue;
      along(u, v, l);
      if(l.size() != 1 || has(l[0], c)) continue;
      level = std::max(level, e.d);
      insert(c, u, v, l[0]);
    }
  }
  if(!taken) take();

  for(std::size_t k = 0; k < within; k++) {
    const DiscreteCADZipReport::Event &e = report.events[k];
    if(e.kind == 'm') report.merged.push_back(e.a);
    if(e.kind == 't') report.inserted.push_back(e.a);
  }
  for(auto &e : report.freeEdges)
    report.freeLevel.push_back(
      std::max(nonFreeAt[find(e.first)], nonFreeAt[find(e.second)]));
  // (the first root of each triangle whose piece was closed)
  report.closedLevel.assign(n0, inf);
  for(std::size_t i = 0; i < n0; i++) {
    std::size_t r = i;
    while(closedAt[r] == inf && up[r] != r) r = up[r];
    report.closedLevel[i] = closedAt[r];
  }
  t = zipped;
  if(origin) *origin = zippedFrom;
}

double zipTolerance(const std::vector<std::array<double, 3> > &x,
                    const std::vector<std::array<int, 3> > &t, std::string *why,
                    std::map<int, int> *distribution)
{
  if(distribution) distribution->clear();
  std::map<std::pair<int, int>, std::vector<std::size_t> > edges;
  std::vector<std::pair<int, int> > free;
  edgesOf(t, edges, free);
  if(free.empty()) {
    if(why) *why = "no free edge";
    return 0.;
  }
  // the free edges by their nodes, their median length
  std::map<int, std::vector<std::size_t> > freeAt;
  std::vector<double> lengths;
  for(std::size_t k = 0; k < free.size(); k++) {
    freeAt[free[k].first].push_back(k);
    freeAt[free[k].second].push_back(k);
    lengths.push_back(std::sqrt(distance2(x[free[k].first], x[free[k].second])));
  }
  std::vector<double> sorted = lengths;
  std::nth_element(sorted.begin(), sorted.begin() + sorted.size() / 2, sorted.end());
  const double median = sorted[sorted.size() / 2];
  if(!(median > 0.)) return 0.;
  // the free edges in the cells of a grid
  hashGrid g{median, {}};
  for(std::size_t k = 0; k < free.size(); k++)
    g.add((int)k, x[free[k].first], x[free[k].second]);
  const double reach = 10. * median;
  // the distances from the nodes to the free edges not within three edges of
  // them along the free edges, in half decades (the cells r cells away from
  // that of a node, and those nearer, have all the free edges up to r - 1/4
  // cells from it)
  std::map<int, int> histogram;
  int counted = 0;
  std::vector<int> stamp(free.size(), -1);
  int visit = 0;
  for(auto &n : freeAt) {
    std::set<std::size_t> near;
    std::set<int> seen = {n.first};
    std::vector<int> front = {n.first};
    for(int depth = 0; depth < 3; depth++) {
      std::vector<int> next;
      for(int m : front)
        for(std::size_t k : freeAt[m]) {
          near.insert(k);
          for(int q : {free[k].first, free[k].second})
            if(seen.insert(q).second) next.push_back(q);
        }
      front = next;
    }
    double best = 1e300;
    visit++;
    const std::array<long, 3> c = g.cell(x[n.first]);
    for(long r = 0;; r++) {
      g.ring(c, r, [&](int k) {
        if(stamp[k] == visit) return;
        stamp[k] = visit;
        if(near.count(k)) return;
        double d2;
        project(x[free[k].first], x[free[k].second], x[n.first], d2);
        best = std::min(best, d2);
      });
      const double sure = (r - 0.25) * median;
      if(sure > reach || (sure > 0. && best <= sure * sure)) break;
    }
    if(best > reach * reach) continue;
    // (nodes on another free edge counted a billionth of the free edges away)
    const double d = std::max(std::sqrt(best), 1e-9 * median);
    histogram[(int)std::floor(2. * std::log10(d))]++;
    counted++;
  }
  if(distribution) *distribution = histogram;
  if(histogram.empty()) {
    if(why) *why = "no free edges near each other";
    return 0.;
  }
  // the peaks of the cracks (much shorter than the free edges), the main
  // peak after the last of them (the gaps between parts), the emptiest bin
  // between the two
  const int lo = histogram.begin()->first, hi = histogram.rbegin()->first;
  auto count = [&](int b) {
    auto it = histogram.find(b);
    return it == histogram.end() ? 0 : it->second;
  };
  auto edge = [](int b) { return std::pow(10., 0.5 * b); };
  const int significant = std::max(5, counted / 200);
  int lastCrack = lo - 1;
  for(int b = lo; b <= hi && edge(b + 1) <= 0.01 * median; b++)
    if(count(b) >= significant && count(b) >= count(b - 1) &&
       count(b) >= count(b + 1))
      lastCrack = b;
  char text[256];
  if(lastCrack < lo) {
    int first = lo;
    while(first < hi && !count(first)) first++;
    snprintf(text, sizeof(text),
             "no cracks: the nearest free edges are %g to %g away, the free "
             "edges %g long",
             edge(first), edge(first + 1), median);
    if(why) *why = text;
    return 0.;
  }
  int main = lastCrack + 1;
  for(int b = lastCrack + 1; b <= hi; b++)
    if(count(b) > count(main)) main = b;
  int valley = lastCrack + 1;
  if(main > lastCrack + 1 && count(main) >= significant) {
    for(int b = lastCrack + 1; b < main; b++)
      if(count(b) < count(valley)) valley = b;
  }
  else {
    // (only cracks: the first bin after them with few nodes)
    while(valley <= hi && count(valley) > count(lastCrack) / 20) valley++;
    main = lastCrack;
  }
  int first = lo;
  while(first < lastCrack && count(first) < significant) first++;
  const double tolerance = edge(valley + 1);
  // (from 0 if the first are nodes on other free edges)
  char start[64] = "0";
  if(edge(first + 1) <= 1e-9 * median || edge(first) > 1e-9 * median)
    snprintf(start, sizeof(start), "%g", edge(first));
  snprintf(text, sizeof(text),
           "proposed %g: the cracks from %s, the gaps between parts around %g, "
           "the free edges %g long",
           tolerance, start, edge(main), median);
  if(why) *why = text;
  return tolerance;
}
