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
#include <cmath>
#include <cstdio>
#include <functional>
#include <map>
#include <memory>
#include <set>
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

  // a grid of nodes, by cells of size h
  struct nodeGrid {
    double h;
    std::map<std::array<long, 3>, std::vector<int> > cells;
    std::array<long, 3> cell(const std::array<double, 3> &p) const
    {
      return {{(long)std::floor(p[0] / h), (long)std::floor(p[1] / h),
               (long)std::floor(p[2] / h)}};
    }
    // the nodes in the cells of the box [lo - r, hi + r]
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

  // the degenerate and duplicated triangles removed (the first copy kept),
  // with their origins
  void compact(std::vector<std::array<int, 3> > &t, std::vector<std::size_t> &from)
  {
    std::set<std::array<int, 3> > seen;
    std::size_t j = 0;
    for(std::size_t i = 0; i < t.size(); i++) {
      const std::array<int, 3> c = t[i];
      if(c[0] == c[1] || c[1] == c[2] || c[2] == c[0]) continue;
      std::array<int, 3> key = c;
      std::sort(key.begin(), key.end());
      if(!seen.insert(key).second) continue;
      t[j] = c;
      from[j] = from[i];
      j++;
    }
    t.resize(j);
    from.resize(j);
  }
} // namespace

void zipFreeEdges(const std::vector<std::array<double, 3> > &x,
                  std::vector<std::array<int, 3> > &t, double tolerance,
                  DiscreteCADZipReport &report, std::vector<std::size_t> *origin)
{
  report = DiscreteCADZipReport();
  std::vector<std::size_t> from(t.size());
  for(std::size_t i = 0; i < t.size(); i++) from[i] = i;
  std::map<std::pair<int, int>, std::vector<std::size_t> > edges;
  std::vector<std::pair<int, int> > free;
  edgesOf(t, edges, free);
  report.freeBefore = free.size();
  const double tol2 = tolerance * tolerance;
  for(int iter = 0; tolerance > 0. && iter < 20 && !free.empty(); iter++) {
    bool changed = false;
    // the nodes of the free edges, and their triangles
    std::set<int> nodes;
    for(auto &e : free) {
      nodes.insert(e.first);
      nodes.insert(e.second);
    }
    std::map<int, std::vector<std::size_t> > trianglesOf;
    for(std::size_t i = 0; i < t.size(); i++)
      for(int n : t[i])
        if(nodes.count(n)) trianglesOf[n].push_back(i);

    // the nodes merged, the closest pairs first
    nodeGrid g{tolerance, {}};
    for(int n : nodes) g.cells[g.cell(x[n])].push_back(n);
    std::vector<std::pair<double, std::pair<int, int> > > pairs;
    for(int n : nodes)
      g.around(x[n], x[n], tolerance, [&](int m) {
        if(m <= n) return;
        const double d2 = distance2(x[n], x[m]);
        if(d2 < tol2) pairs.push_back({d2, {n, m}});
      });
    std::sort(pairs.begin(), pairs.end());
    std::map<int, int> rep;
    std::function<int(int)> find = [&](int n) {
      auto it = rep.find(n);
      if(it == rep.end() || it->second == n) return n;
      return it->second = find(it->second);
    };
    // (each merge made in the triangles of the two nodes, unless it would put
    // more than two distinct triangles along an edge: copies of a triangle
    // count once, those of the two nodes, shorter than the tolerance,
    // collapse)
    for(auto &p : pairs) {
      const int a = find(p.second.first), b = find(p.second.second);
      if(a == b || distance2(x[a], x[b]) >= tol2) continue;
      const int keep = std::min(a, b), away = std::max(a, b);
      std::vector<std::size_t> &tk = trianglesOf[keep], &ta = trianglesOf[away];
      bool ok = true;
      std::map<int, std::set<std::array<int, 3> > > at;
      for(const std::vector<std::size_t> *l : {&tk, &ta})
        for(std::size_t i : *l) {
          std::array<int, 3> tr = t[i];
          int seen = 0;
          for(int &n : tr) {
            if(n == away) n = keep;
            if(n == keep) seen++;
          }
          if(seen != 1) continue;
          std::array<int, 3> key = tr;
          std::sort(key.begin(), key.end());
          for(int n : tr)
            if(n != keep) at[n].insert(key);
        }
      for(auto &e : at)
        if(e.second.size() > 2) ok = false;
      if(!ok) continue;
      for(std::size_t i : ta)
        for(int &n : t[i])
          if(n == away) n = keep;
      tk.insert(tk.end(), ta.begin(), ta.end());
      ta.clear();
      rep[away] = keep;
      report.merged.push_back(away);
      changed = true;
    }
    if(!rep.empty()) {
      for(auto &tr : t)
        for(int &n : tr) n = find(n);
      compact(t, from);
      edgesOf(t, edges, free);
    }

    // the nodes inside free edges inserted into them, splitting their
    // triangles (one edge of a triangle at a time)
    nodes.clear();
    double h = 0.;
    for(auto &e : free) {
      nodes.insert(e.first);
      nodes.insert(e.second);
      h += std::sqrt(distance2(x[e.first], x[e.second]));
    }
    if(free.empty()) break;
    h = std::max(tolerance, h / free.size());
    nodeGrid ge{h, {}};
    for(int n : nodes) ge.cells[ge.cell(x[n])].push_back(n);
    std::map<std::size_t, std::pair<std::pair<int, int>,
                                    std::vector<std::pair<double, int> > > >
      inserts; // triangle -> (edge, (parameter, node))
    for(auto &e : free) {
      const std::size_t i = edges[e][0];
      auto it = inserts.find(i);
      if(it != inserts.end() && it->second.first != e) continue;
      std::vector<std::pair<double, int> > found;
      ge.around(x[e.first], x[e.second], tolerance, [&](int c) {
        if(c == t[i][0] || c == t[i][1] || c == t[i][2]) return;
        double d2;
        const double s = project(x[e.first], x[e.second], x[c], d2);
        if(d2 >= tol2 || distance2(x[c], x[e.first]) < tol2 ||
           distance2(x[c], x[e.second]) < tol2 || s <= 0. || s >= 1.)
          return;
        found.push_back({s, c});
      });
      if(found.empty()) continue;
      std::sort(found.begin(), found.end());
      found.erase(std::unique(found.begin(), found.end(),
                              [](const std::pair<double, int> &p,
                                 const std::pair<double, int> &q) {
                                return p.second == q.second;
                              }),
                  found.end());
      inserts[i] = {e, found};
    }
    for(auto &ins : inserts) {
      const std::size_t i = ins.first;
      const std::array<int, 3> tr = t[i];
      // (the edge in the order of the triangle: u to v, then w)
      int k = 0;
      while(k < 3 && std::minmax(tr[k], tr[(k + 1) % 3]) != ins.second.first) k++;
      if(k == 3) continue;
      const int u = tr[k], v = tr[(k + 1) % 3], w = tr[(k + 2) % 3];
      std::vector<int> chain = {u};
      std::vector<std::pair<double, int> > f = ins.second.second;
      if(u != ins.second.first.first) std::reverse(f.begin(), f.end());
      for(auto &p : f) {
        chain.push_back(p.second);
        report.inserted.push_back(p.second);
      }
      chain.push_back(v);
      t[i] = {{chain[0], chain[1], w}};
      for(std::size_t j = 1; j + 1 < chain.size(); j++) {
        t.push_back({{chain[j], chain[j + 1], w}});
        from.push_back(from[i]);
      }
      changed = true;
    }
    if(!inserts.empty()) {
      compact(t, from);
      edgesOf(t, edges, free);
    }
    if(!changed) break;
  }
  report.freeAfter = free.size();
  if(origin) *origin = from;
}

double zipTolerance(const std::vector<std::array<double, 3> > &x,
                    const std::vector<std::array<int, 3> > &t, std::string *why)
{
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
  // the free edges in the cells of a grid, by their middles
  nodeGrid g{median, {}};
  std::vector<std::array<double, 3> > middle(free.size());
  for(std::size_t k = 0; k < free.size(); k++) {
    for(int c = 0; c < 3; c++)
      middle[k][c] = 0.5 * (x[free[k].first][c] + x[free[k].second][c]);
    g.cells[g.cell(middle[k])].push_back((int)k);
  }
  double longest = *std::max_element(lengths.begin(), lengths.end());
  const double reach = std::min(4. * median + 0.5 * longest, 10. * median);
  // the distances from the nodes to the free edges not within three edges of
  // them along the free edges, in half decades
  std::map<int, int> histogram;
  int counted = 0;
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
    g.around(x[n.first], x[n.first], reach, [&](int k) {
      if(near.count(k)) return;
      double d2;
      project(x[free[k].first], x[free[k].second], x[n.first], d2);
      best = std::min(best, d2);
    });
    if(best >= 1e300) continue;
    const double d = std::sqrt(best);
    histogram[(int)std::floor(2. * std::log10(std::max(d, 1e-300)))]++;
    counted++;
  }
  if(histogram.empty()) {
    if(why) *why = "no free edges near each other";
    return 0.;
  }
  // the first peak and the main one, the emptiest bin between them
  const int lo = histogram.begin()->first, hi = histogram.rbegin()->first;
  auto count = [&](int b) {
    auto it = histogram.find(b);
    return it == histogram.end() ? 0 : it->second;
  };
  const int significant = std::max(5, counted / 200);
  int first = lo, main = lo;
  for(int b = lo; b <= hi; b++) {
    if(count(b) > count(main)) main = b;
  }
  for(int b = lo; b <= hi; b++)
    if(count(b) >= significant && count(b) >= count(b - 1) &&
       count(b) >= count(b + 1)) {
      first = b;
      break;
    }
  char text[256];
  auto edge = [](int b) { return std::pow(10., 0.5 * b); };
  // (cracks: much shorter than the free edges)
  if(edge(first + 1) > 0.01 * median) {
    snprintf(text, sizeof(text),
             "no cracks: the nearest free edges are %g to %g away, the free "
             "edges %g long",
             edge(first), edge(first + 1), median);
    if(why) *why = text;
    return 0.;
  }
  int valley = first + 1;
  if(main > first + 1) {
    for(int b = first + 1; b < main; b++)
      if(count(b) < count(valley)) valley = b;
  }
  else {
    // (only cracks: the first bin after them with few nodes)
    while(valley <= hi && count(valley) > count(first) / 20) valley++;
  }
  const double tolerance = edge(valley + 1);
  snprintf(text, sizeof(text),
           "proposed %g: the cracks from %g, the gaps between parts around %g, "
           "the free edges %g long",
           tolerance, edge(first), edge(main), median);
  if(why) *why = text;
  return tolerance;
}
