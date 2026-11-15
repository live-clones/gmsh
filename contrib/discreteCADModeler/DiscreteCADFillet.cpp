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

// The fillets of the discrete CAD modeler: for each chain of curves to fillet
// (those given, and those continuing them tangentially), a tool swept along
// the line of the centers of the ball rolling on the two surfaces of the
// curves, whose section is the arc of the ball between its points of contact
// closed by a path around the curve (in the air for a convex curve, in the
// solid for a concave one); the tools of three chains meeting at a corner
// joined by the part of the ball between them, those of two chains ending at
// the same point by a section on the plane between them, the others extended
// beyond their ends, or ended on the plane of the surface there when the
// extension would change the solid; then the boolean difference of the
// volume and the tools of the convex curves, after its union with those of
// the concave ones. The arcs of the tools become the surfaces of the
// fillets, with the exact geometry of a cylinder, a torus or a sphere when
// they are on one.

#include <algorithm>
#include <cmath>
#include <functional>
#include <map>
#include <set>
#include "DiscreteCADModeler.h"
#include "DiscreteCADRecognition.h"
#include "GmshMessage.h"
#include "Context.h"

namespace {
  const double pi = 3.14159265358979323846;

  typedef std::array<double, 3> Vec;

  Vec operator+(const Vec &a, const Vec &b)
  {
    return {{a[0] + b[0], a[1] + b[1], a[2] + b[2]}};
  }
  Vec operator-(const Vec &a, const Vec &b)
  {
    return {{a[0] - b[0], a[1] - b[1], a[2] - b[2]}};
  }
  Vec operator*(double s, const Vec &a) { return {{s * a[0], s * a[1], s * a[2]}}; }
  double dot(const Vec &a, const Vec &b)
  {
    return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
  }
  Vec cross(const Vec &a, const Vec &b)
  {
    return {{a[1] * b[2] - a[2] * b[1], a[2] * b[0] - a[0] * b[2],
             a[0] * b[1] - a[1] * b[0]}};
  }
  double norm(const Vec &a) { return std::sqrt(dot(a, a)); }
  Vec unit(const Vec &a)
  {
    const double l = norm(a);
    return l > 0. ? (1. / l) * a : a;
  }
  double angle(const Vec &a, const Vec &b)
  {
    return std::atan2(norm(cross(a, b)), dot(a, b));
  }

  // the solution of the 3x3 system whose rows are r0, r1, r2; false if it is
  // singular
  bool solve(const Vec &r0, const Vec &r1, const Vec &r2, const Vec &b, Vec &x)
  {
    const Vec c12 = cross(r1, r2);
    const double det = dot(r0, c12);
    if(!(std::abs(det) > 1.e-14 * norm(r0) * norm(r1) * norm(r2))) return false;
    // (Cramer: the columns of the inverse are the cross products of the rows)
    const Vec c20 = cross(r2, r0), c01 = cross(r0, r1);
    for(int k = 0; k < 3; k++)
      x[k] = (b[0] * c12[k] + b[1] * c20[k] + b[2] * c01[k]) / det;
    return true;
  }

  // the point of triangle abc nearest to p
  Vec nearestOnTriangle(const Vec &p, const Vec &a, const Vec &b, const Vec &c)
  {
    const Vec ab = b - a, ac = c - a, ap = p - a;
    const double d1 = dot(ab, ap), d2 = dot(ac, ap);
    if(d1 <= 0. && d2 <= 0.) return a;
    const Vec bp = p - b;
    const double d3 = dot(ab, bp), d4 = dot(ac, bp);
    if(d3 >= 0. && d4 <= d3) return b;
    const double vc = d1 * d4 - d3 * d2;
    if(vc <= 0. && d1 >= 0. && d3 <= 0.) return a + (d1 / (d1 - d3)) * ab;
    const Vec cp = p - c;
    const double d5 = dot(ab, cp), d6 = dot(ac, cp);
    if(d6 >= 0. && d5 <= d6) return c;
    const double vb = d5 * d2 - d1 * d6;
    if(vb <= 0. && d2 >= 0. && d6 <= 0.) return a + (d2 / (d2 - d6)) * ac;
    const double va = d3 * d6 - d5 * d4;
    if(va <= 0. && d4 - d3 >= 0. && d5 - d6 >= 0.)
      return b + ((d4 - d3) / ((d4 - d3) + (d5 - d6))) * (c - b);
    const double s = 1. / (va + vb + vc);
    return a + (vb * s) * ab + (vc * s) * ac;
  }

  // a surface the ball rolls on: its analytic surface if it has one (or one
  // is fitted to it), else its triangles (oriented outwards of the volume)
  struct Support {
    DiscreteCADAnalyticSurface surface;
    // the side of the analytic surface outside the volume
    double sign;
    const std::vector<std::array<double, 3> > *nodes;
    std::vector<std::array<int, 3> > triangles;
    Support() : sign(1.), nodes(nullptr) {}
    // the point of its triangles nearest to x, and their normal there
    Vec nearest(const Vec &x, Vec *normal = nullptr) const
    {
      double best = 1e300;
      Vec y = x;
      for(auto &t : triangles) {
        const Vec &a = (*nodes)[t[0]], &b = (*nodes)[t[1]], &c = (*nodes)[t[2]];
        const Vec q = nearestOnTriangle(x, a, b, c);
        const double d = dot(q - x, q - x);
        if(d < best) {
          best = d;
          y = q;
          if(normal) *normal = unit(cross(b - a, c - a));
        }
      }
      return y;
    }
    // the signed distance to x (positive outside of the volume) and its
    // gradient, the normal at the nearest point
    double distance(const Vec &x, Vec &gradient) const
    {
      if(surface.type != DiscreteCADAnalyticSurface::NONE) {
        double n[3];
        surface.normal(x.data(), n);
        for(int k = 0; k < 3; k++) gradient[k] = sign * n[k];
        return sign * surface.distance(x.data());
      }
      const Vec y = nearest(x, &gradient);
      return dot(x - y, gradient);
    }
  };

  // the point c at the signed distance d (negative inside) of the surfaces of
  // s (two, in the plane through p normal to t, or three): Newton steps from
  // c; false if they do not converge
  bool offsetPoint(const std::vector<const Support *> &s, double d,
                   const Vec &p, const Vec &t, double scale, Vec &c)
  {
    for(int it = 0; it < 60; it++) {
      Vec g[3], f;
      for(std::size_t i = 0; i < s.size(); i++)
        f[i] = s[i]->distance(c, g[i]) - d;
      if(s.size() == 2) {
        g[2] = t;
        f[2] = dot(c - p, t);
      }
      Vec step;
      if(!solve(g[0], g[1], g[2], f, step)) return false;
      c = c - step;
      if(norm(step) < 1.e-14 * scale) return true;
    }
    Vec g;
    for(auto *si : s)
      if(std::abs(si->distance(c, g) - d) > 1.e-9 * scale) return false;
    return true;
  }

  // the solid angle of triangle abc seen from x (Van Oosterom and Strackee)
  double solidAngle(const Vec &x, const Vec &a, const Vec &b, const Vec &c)
  {
    const Vec p = a - x, q = b - x, r = c - x;
    const double lp = norm(p), lq = norm(q), lr = norm(r);
    return 2. * std::atan2(dot(p, cross(q, r)), lp * lq * lr + dot(p, q) * lr +
                                                  dot(p, r) * lq +
                                                  dot(q, r) * lp);
  }

  // the triangles oriented as their neighbors, outwards of the volume they
  // bound; false if they do not bound a volume (an edge not of two
  // triangles)
  bool orientOutwards(const std::vector<std::array<double, 3> > &nodes,
                      std::vector<std::array<int, 3> > &triangles)
  {
    std::map<std::pair<int, int>, std::vector<std::size_t> > edgeTriangles;
    for(std::size_t i = 0; i < triangles.size(); i++)
      for(int k = 0; k < 3; k++)
        edgeTriangles[std::minmax(triangles[i][k], triangles[i][(k + 1) % 3])]
          .push_back(i);
    for(auto &e : edgeTriangles)
      if(e.second.size() != 2) return false;
    auto has = [&](std::size_t i, int a, int b) {
      for(int k = 0; k < 3; k++)
        if(triangles[i][k] == a && triangles[i][(k + 1) % 3] == b) return true;
      return false;
    };
    std::vector<char> done(triangles.size(), 0);
    for(std::size_t s = 0; s < triangles.size(); s++) {
      if(done[s]) continue;
      done[s] = 1;
      std::vector<std::size_t> stack(1, s), component(1, s);
      while(!stack.empty()) {
        const std::size_t i = stack.back();
        stack.pop_back();
        for(int k = 0; k < 3; k++) {
          const int a = triangles[i][k], b = triangles[i][(k + 1) % 3];
          for(std::size_t j : edgeTriangles[std::minmax(a, b)]) {
            if(j == i) continue;
            if(done[j]) {
              if(has(j, a, b)) return false;
              continue;
            }
            if(has(j, a, b)) std::swap(triangles[j][1], triangles[j][2]);
            done[j] = 1;
            stack.push_back(j);
            component.push_back(j);
          }
        }
      }
      double volume = 0.;
      for(std::size_t i : component)
        volume += dot(nodes[triangles[i][0]],
                      cross(nodes[triangles[i][1]], nodes[triangles[i][2]]));
      if(volume < 0.)
        for(std::size_t i : component) std::swap(triangles[i][1], triangles[i][2]);
    }
    return true;
  }
} // namespace

bool DiscreteCAD_Internals::fillet(const std::vector<int> &volumeTags,
                                   const std::vector<int> &curveTags,
                                   const std::vector<double> &radii,
                                   std::vector<std::pair<int, int> > &outDimTags,
                                   bool removeVolume)
{
  outDimTags.clear();
  if(radii.empty() || (radii.size() != 1 && radii.size() != curveTags.size() &&
                       radii.size() != 2 * curveTags.size())) {
    Msg::Error("Discrete CAD fillet: %lu radii for %lu curves", radii.size(),
               curveTags.size());
    return false;
  }
  if(radii.size() > 1 && radii.size() == 2 * curveTags.size())
    Msg::Warning("Discrete CAD fillet: radii varying along the curves not "
                 "available, the radius at their first end used");
  std::map<int, double> radiusOf;
  for(std::size_t i = 0; i < curveTags.size(); i++) {
    const double r = radii.size() == 1                ? radii[0] :
                     radii.size() == curveTags.size() ? radii[i] :
                                                        radii[2 * i];
    if(!(r > 0.)) {
      Msg::Error("Discrete CAD fillet: radius %g of curve %d not positive", r,
                 curveTags[i]);
      return false;
    }
    radiusOf[std::abs(curveTags[i])] = r;
  }
  for(int v : volumeTags) {
    if(!_volumes.count(v)) {
      Msg::Error("Discrete CAD fillet: no discrete CAD volume %d", v);
      return false;
    }
    std::vector<std::pair<int, int> > out;
    if(!_filletVolume(v, radiusOf, removeVolume, out)) return false;
    outDimTags.insert(outDimTags.end(), out.begin(), out.end());
  }
  _changed = true;
  return true;
}

bool DiscreteCAD_Internals::_filletVolume(
  int volume, const std::map<int, double> &radiusOf, bool removeVolume,
  std::vector<std::pair<int, int> > &outDimTags)
{
  const std::vector<std::array<double, 3> > &X = _nodes;

  // the triangles of the volume, oriented outwards, their surfaces, and the
  // triangle along each oriented edge
  std::vector<std::array<int, 3> > tri;
  std::vector<int> surfaceOf;
  for(int s : _volumes[volume].surfaces) {
    for(auto t : _surfaces[std::abs(s)].triangles) {
      if(s < 0) std::swap(t[1], t[2]);
      tri.push_back(t);
      surfaceOf.push_back(std::abs(s));
    }
  }
  std::map<std::pair<int, int>, std::size_t> along;
  std::map<int, std::set<int> > surfacesAt;
  for(std::size_t i = 0; i < tri.size(); i++)
    for(int k = 0; k < 3; k++) {
      along[{tri[i][k], tri[i][(k + 1) % 3]}] = i;
      surfacesAt[tri[i][k]].insert(surfaceOf[i]);
    }
  auto normalOf = [&](std::size_t i) {
    return unit(cross(X[tri[i][1]] - X[tri[i][0]], X[tri[i][2]] - X[tri[i][0]]));
  };
  double lo[3] = {1e300, 1e300, 1e300}, hi[3] = {-1e300, -1e300, -1e300};
  for(auto &t : tri)
    for(int n : t)
      for(int k = 0; k < 3; k++) {
        lo[k] = std::min(lo[k], X[n][k]);
        hi[k] = std::max(hi[k], X[n][k]);
      }
  const double size =
    norm(Vec{{hi[0] - lo[0], hi[1] - lo[1], hi[2] - lo[2]}});
  auto inside = [&](const Vec &x) {
    double omega = 0.;
    for(auto &t : tri) omega += solidAngle(x, X[t[0]], X[t[1]], X[t[2]]);
    return omega > 2. * pi;
  };

  // the curves between two surfaces of the volume: the surface whose
  // triangles go along them (A) and the other one (B), whether they are
  // convex, their tangents at their ends (along them)
  struct Edge {
    int A, B;
    bool convex;
    Vec t0, t1;
  };
  std::map<int, Edge> edges;
  std::set<int> curves;
  for(int s : _volumes[volume].surfaces)
    for(int c : _surfaces[std::abs(s)].curves) curves.insert(std::abs(c));
  auto endTangent = [&](const std::vector<int> &n) {
    // (the first two chords, the nodes along them skipped; the first one
    // turned by half the angle to the second one, exact on an arc of equal
    // chords)
    auto chord = [&](std::size_t i) {
      const Vec d = unit(X[n[i + 1]] - X[n[i]]);
      std::size_t j = i + 1;
      while(j + 1 < n.size() && angle(d, X[n[j + 1]] - X[n[j]]) < 1.e-4) j++;
      return j;
    };
    const std::size_t i = chord(0);
    const Vec d0 = unit(X[n[i]] - X[n[0]]);
    if(i + 1 >= n.size()) return d0;
    return unit(3. * d0 - unit(X[n[chord(i)]] - X[n[i]]));
  };
  for(int c : curves) {
    const std::vector<int> &n = _curves[c].nodes;
    if(n.size() < 2) continue;
    const std::size_t j = (n.size() - 1) / 2;
    auto ia = along.find({n[j], n[j + 1]}), ib = along.find({n[j + 1], n[j]});
    if(ia == along.end() || ib == along.end()) continue;
    Edge e;
    e.A = surfaceOf[ia->second];
    e.B = surfaceOf[ib->second];
    if(e.A == e.B) continue;
    const std::array<int, 3> &ta = tri[ia->second];
    int third = ta[0];
    for(int m : ta)
      if(m != n[j] && m != n[j + 1]) third = m;
    const Vec dir = unit(X[n[j + 1]] - X[n[j]]);
    Vec d = X[third] - X[n[j]];
    d = d - dot(d, dir) * dir;
    const Vec nA = normalOf(ia->second), nB = normalOf(ib->second);
    if(angle(nA, nB) < 1.e-3) continue;
    e.convex = dot(d, nB) < 0.;
    e.t0 = endTangent(n);
    std::vector<int> r(n.rbegin(), n.rend());
    e.t1 = -1. * endTangent(r);
    edges[c] = e;
  }

  // the curves to fillet: those given, and those continuing them tangentially
  // (as OpenCASCADE does)
  std::map<int, double> selected;
  for(auto &cr : radiusOf)
    if(edges.count(cr.first)) selected[cr.first] = cr.second;
  for(auto &cr : radiusOf)
    if(!edges.count(cr.first) && curves.count(cr.first))
      Msg::Warning("Discrete CAD fillet: curve %d of volume %d is not between "
                   "two of its surfaces meeting at an angle",
                   cr.first, volume);
  if(selected.empty()) {
    Msg::Warning("Discrete CAD fillet: no curve to fillet on volume %d",
                 volume);
    outDimTags.push_back({3, volume});
    return true;
  }
  std::map<int, std::vector<int> > curvesAt;
  for(auto &e : edges) {
    curvesAt[_curves[e.first].v0].push_back(e.first);
    curvesAt[_curves[e.first].v1].push_back(e.first);
  }
  // (the direction of curve c away from its vertex v)
  auto away = [&](int c, int v) {
    return _curves[c].v0 == v ? edges[c].t0 : -1. * edges[c].t1;
  };
  const double tangentAngle = 10. * pi / 180.;
  auto continues = [&](int c, int d, int v) {
    return edges[c].convex == edges[d].convex &&
           angle(-1. * away(c, v), away(d, v)) < tangentAngle;
  };
  for(bool grown = true; grown;) {
    grown = false;
    const std::map<int, double> current = selected;
    for(auto &s : current)
      for(int v : {_curves[s.first].v0, _curves[s.first].v1})
        for(int d : curvesAt[v])
          if(!selected.count(d) && continues(s.first, d, v)) {
            selected[d] = s.second;
            grown = true;
          }
  }

  // the chains of curves to fillet, joined at the vertices where only two of
  // them meet, continuing each other: their curves, in order, used forwards
  // or not
  auto partner = [&](int c, int v) {
    std::vector<int> s;
    for(int d : curvesAt[v])
      if(selected.count(d)) s.push_back(d);
    if(s.size() != 2 || s[0] == s[1]) return 0;
    const int d = s[0] == c ? s[1] : s[0];
    return continues(c, d, v) ? d : 0;
  };
  struct Chain {
    std::vector<std::pair<int, bool> > curves;
    bool closed, convex;
    double radius;
    // the nodes, the curve of the segment after each, the surfaces (A on the
    // side of the triangles going along the chain) at each node, the
    // directions of the chain and the lengths along it
    std::vector<int> nodes, segment;
    std::vector<std::pair<int, int> > faces;
    std::vector<Vec> tangent;
    std::vector<double> s;
  };
  std::vector<Chain> chains;
  std::set<int> used;
  for(auto &sc : selected) {
    if(used.count(sc.first)) continue;
    // (back to the start of the chain)
    int c = sc.first;
    bool forward = true;
    std::set<int> seen = {c};
    while(true) {
      const int v = forward ? _curves[c].v0 : _curves[c].v1;
      const int d = partner(c, v);
      if(!d || seen.count(d)) break;
      seen.insert(d);
      forward = _curves[d].v1 == v;
      c = d;
    }
    Chain ch;
    ch.closed = false;
    const int first = c;
    while(true) {
      ch.curves.push_back({c, forward});
      used.insert(c);
      const int v = forward ? _curves[c].v1 : _curves[c].v0;
      const int d = partner(c, v);
      if(!d) break;
      if(d == first) {
        ch.closed = true;
        break;
      }
      if(used.count(d)) break;
      forward = _curves[d].v0 == v;
      c = d;
    }
    if(!ch.closed) {
      // (a chain ending where it starts, continuing itself there: a closed
      // curve)
      const std::pair<int, bool> &f = ch.curves.front(), &l = ch.curves.back();
      const int v0 = f.second ? _curves[f.first].v0 : _curves[f.first].v1;
      const int v1 = l.second ? _curves[l.first].v1 : _curves[l.first].v0;
      const Vec in = l.second ? edges[l.first].t1 : -1. * edges[l.first].t0;
      const Vec out = f.second ? edges[f.first].t0 : -1. * edges[f.first].t1;
      int others = 0;
      for(int d : curvesAt[v0])
        if(selected.count(d) && d != f.first && d != l.first) others++;
      ch.closed = v0 == v1 && !others && angle(in, out) < tangentAngle;
    }
    ch.convex = edges[first].convex;
    ch.radius = selected[first];
    for(auto &cf : ch.curves)
      if(std::abs(selected[cf.first] - ch.radius) > 1.e-12 * ch.radius)
        Msg::Warning("Discrete CAD fillet: curves %d and %d continue each "
                     "other with different radii, %g used",
                     first, cf.first, ch.radius);
    for(auto &cf : ch.curves) {
      std::vector<int> n = _curves[cf.first].nodes;
      if(!cf.second) std::reverse(n.begin(), n.end());
      const Edge &e = edges[cf.first];
      const std::pair<int, int> f =
        cf.second ? std::make_pair(e.A, e.B) : std::make_pair(e.B, e.A);
      for(std::size_t j = ch.nodes.empty() ? 0 : 1; j < n.size(); j++) {
        ch.nodes.push_back(n[j]);
        ch.faces.push_back(f);
      }
      for(std::size_t j = 0; j + 1 < n.size(); j++)
        ch.segment.push_back(cf.first);
    }
    if(ch.closed) {
      ch.nodes.pop_back();
      ch.faces.pop_back();
    }
    const std::size_t m = ch.nodes.size();
    ch.tangent.resize(m);
    ch.s.assign(m, 0.);
    for(std::size_t j = 1; j < m; j++)
      ch.s[j] = ch.s[j - 1] + norm(X[ch.nodes[j]] - X[ch.nodes[j - 1]]);
    for(std::size_t j = 0; j < m; j++) {
      if(!ch.closed && (j == 0 || j + 1 == m)) {
        std::vector<int> n;
        if(j == 0)
          for(std::size_t i = 0; i < std::min<std::size_t>(3, m); i++)
            n.push_back(ch.nodes[i]);
        else
          for(std::size_t i = 0; i < std::min<std::size_t>(3, m); i++)
            n.push_back(ch.nodes[m - 1 - i]);
        ch.tangent[j] = j == 0 ? endTangent(n) : -1. * endTangent(n);
        continue;
      }
      const Vec &p = X[ch.nodes[(j + m - 1) % m]], &x = X[ch.nodes[j]],
                &q = X[ch.nodes[(j + 1) % m]];
      ch.tangent[j] = unit(unit(x - p) + unit(q - x));
    }
    chains.push_back(ch);
  }

  // the surfaces the balls roll on: their analytic surfaces, or those fitted
  // to them, else their triangles
  const double relative = CTX::instance()->geom.discreteTolerance;
  std::map<int, Support> supports;
  auto support = [&](int s) -> const Support & {
    auto it = supports.find(s);
    if(it != supports.end()) return it->second;
    Support &sp = supports[s];
    sp.nodes = &_nodes;
    for(std::size_t i = 0; i < tri.size(); i++)
      if(surfaceOf[i] == s) sp.triangles.push_back(tri[i]);
    const Surface &sf = _surfaces[s];
    if(sf.analytic.surface.type != DiscreteCADAnalyticSurface::NONE)
      sp.surface = sf.analytic.surface;
    else {
      std::map<int, int> local;
      std::vector<std::array<double, 3> > x;
      std::vector<std::array<int, 3> > t;
      double l[3] = {1e300, 1e300, 1e300}, h[3] = {-1e300, -1e300, -1e300};
      for(auto &tr : sp.triangles) {
        std::array<int, 3> lt;
        for(int k = 0; k < 3; k++) {
          auto in = local.insert({tr[k], (int)x.size()});
          if(in.second) {
            x.push_back(X[tr[k]]);
            for(int m = 0; m < 3; m++) {
              l[m] = std::min(l[m], X[tr[k]][m]);
              h[m] = std::max(h[m], X[tr[k]][m]);
            }
          }
          lt[k] = in.first->second;
        }
        t.push_back(lt);
      }
      const double extent = norm(Vec{{h[0] - l[0], h[1] - l[1], h[2] - l[2]}});
      sp.surface = recognizeSurface(x, t, 2. * relative * extent, 10. * pi / 180.);
    }
    if(sp.surface.type != DiscreteCADAnalyticSurface::NONE) {
      // (its side outside of the volume, at its largest triangle)
      double best = -1.;
      for(auto &tr : sp.triangles) {
        const Vec n = cross(X[tr[1]] - X[tr[0]], X[tr[2]] - X[tr[0]]);
        if(norm(n) <= best) continue;
        best = norm(n);
        const Vec g = (1. / 3.) * (X[tr[0]] + X[tr[1]] + X[tr[2]]);
        double a[3];
        sp.surface.normal(g.data(), a);
        sp.sign = dot(Vec{{a[0], a[1], a[2]}}, n) < 0. ? -1. : 1.;
      }
    }
    return sp;
  };

  // the sections of the tools: the ball (center c, contacts a on A and b on
  // B, the angle between them) at the point p of a chain, and the direction
  // of the path around p
  struct Section {
    Vec p, t, c, a, b, m;
    int A, B;
    double theta, u;
    std::vector<int> nodes;
  };
  auto ball = [&](const Chain &ch, const Vec &p, const Vec &t, int A, int B,
                  Section &sc) {
    const Support &sa = support(A), &sb = support(B);
    const double d = ch.convex ? -ch.radius : ch.radius;
    Vec ga, gb;
    sa.distance(p, ga);
    sb.distance(p, gb);
    const double cab = dot(ga, gb);
    if(!(1. + cab > 1.e-6)) return false;
    sc.p = p;
    sc.t = t;
    sc.A = A;
    sc.B = B;
    sc.c = p + (d / (1. + cab)) * (ga + gb);
    if(!offsetPoint({&sa, &sb}, d, p, t, ch.radius, sc.c)) return false;
    sa.distance(sc.c, ga);
    sb.distance(sc.c, gb);
    sc.a = sc.c - d * ga;
    sc.b = sc.c - d * gb;
    sc.theta = angle(sc.a - sc.c, sc.b - sc.c);
    sc.m = -1. * unit(unit(sc.a - p) + unit(sc.b - p));
    return true;
  };

  // the ends of the open chains at the vertices, and the corners: three
  // chains of the same radius and kind meeting at a vertex of three curves,
  // where the ball touches their three surfaces
  struct End {
    std::size_t chain;
    bool last;
  };
  std::map<int, std::vector<End> > endsAt;
  for(std::size_t k = 0; k < chains.size(); k++) {
    if(chains[k].closed) continue;
    endsAt[chains[k].nodes.front()].push_back({k, false});
    endsAt[chains[k].nodes.back()].push_back({k, true});
  }
  struct Corner {
    int vertex;
    std::vector<End> ends;
    int faces[3];
    Vec c;
    // the contacts on the faces, and the points of the chains whose sections
    // go through the center
    Vec contact[3];
    std::vector<Vec> p;
    std::vector<double> s;
  };
  std::vector<Corner> corners;
  // (the length along each chain where it is cut by a corner at its ends)
  std::vector<std::array<double, 2> > cut(chains.size());
  std::vector<std::array<int, 2> > cornerOf(chains.size(), {{-1, -1}});
  for(std::size_t k = 0; k < chains.size(); k++)
    cut[k] = {{-1e300, 1e300}};
  for(auto &ea : endsAt) {
    const std::vector<End> &ends = ea.second;
    if(ends.size() != 3) continue;
    int vertex = 0;
    for(auto &v : _vertices)
      if(v.second.node == ea.first) vertex = v.first;
    std::size_t degree = 0;
    for(int c : curves)
      degree += (_curves[c].v0 == vertex) + (_curves[c].v1 == vertex);
    const Chain &c0 = chains[ends[0].chain];
    bool same = degree == 3;
    std::map<int, int> count;
    for(auto &e : ends) {
      const Chain &ch = chains[e.chain];
      same = same && ch.convex == c0.convex &&
             std::abs(ch.radius - c0.radius) <= 1.e-12 * c0.radius;
      const std::pair<int, int> &f =
        e.last ? ch.faces.back() : ch.faces.front();
      count[f.first]++;
      count[f.second]++;
    }
    for(std::size_t i = 0; i < 3; i++)
      for(std::size_t j = 0; j < i; j++)
        same = same && ends[i].chain != ends[j].chain;
    same = same && count.size() == 3;
    for(auto &n : count) same = same && n.second == 2;
    if(!same) {
      Msg::Warning("Discrete CAD fillet: no corner at point %d (fillets of "
                   "different radii or kinds): the fillets intersect there",
                   vertex);
      continue;
    }
    Corner cn;
    cn.vertex = ea.first;
    cn.ends = ends;
    int i = 0;
    for(auto &n : count) cn.faces[i++] = n.first;
    const Support *s[3] = {&support(cn.faces[0]), &support(cn.faces[1]),
                           &support(cn.faces[2])};
    const double d = c0.convex ? -c0.radius : c0.radius;
    const Vec &v = X[ea.first];
    Vec g[3];
    for(int f = 0; f < 3; f++) s[f]->distance(v, g[f]);
    Vec shift;
    if(!solve(g[0], g[1], g[2], Vec{{d, d, d}}, shift)) continue;
    cn.c = v + shift;
    if(!offsetPoint({s[0], s[1], s[2]}, d, v, Vec(), c0.radius, cn.c)) {
      Msg::Warning("Discrete CAD fillet: no ball touching the three surfaces "
                   "at point %d", vertex);
      continue;
    }
    for(int f = 0; f < 3; f++) {
      s[f]->distance(cn.c, g[f]);
      cn.contact[f] = cn.c - d * g[f];
    }
    // (the points of the chains nearest to the center)
    bool fits = true;
    for(auto &e : ends) {
      const Chain &ch = chains[e.chain];
      double best = 1e300, at = 0.;
      Vec p;
      for(std::size_t j = 0; j + 1 < ch.nodes.size(); j++) {
        const Vec &x = X[ch.nodes[j]], &y = X[ch.nodes[j + 1]];
        const double l = dot(y - x, y - x);
        const double f =
          l > 0. ? std::min(1., std::max(0., dot(cn.c - x, y - x) / l)) : 0.;
        const Vec q = x + f * (y - x);
        if(norm(q - cn.c) < best) {
          best = norm(q - cn.c);
          p = q;
          at = ch.s[j] + f * (ch.s[j + 1] - ch.s[j]);
        }
      }
      cn.p.push_back(p);
      cn.s.push_back(at);
      std::array<double, 2> &ct = cut[e.chain];
      (e.last ? ct[1] : ct[0]) = at;
      if(ct[0] >= ct[1]) fits = false;
      cornerOf[e.chain][e.last ? 1 : 0] = (int)corners.size();
    }
    if(!fits) {
      Msg::Error("Discrete CAD fillet: radius %g too large for the curves "
                 "between the corners of volume %d", c0.radius, volume);
      return false;
    }
    corners.push_back(cn);
  }

  // the sections at the nodes of the chains, between their cuts: at their
  // ends, where their curves meet and where they turn (the nodes inside
  // their segments, as the booleans leave them, would give sections across
  // them, not around their curvature); those going back from the previous
  // one left out
  std::vector<std::vector<Section> > sections(chains.size());
  double widest = 0.;
  for(std::size_t k = 0; k < chains.size(); k++) {
    const Chain &ch = chains[k];
    const std::size_t m = ch.nodes.size();
    const double gap = 0.05 * ch.radius;
    std::vector<std::size_t> kept;
    for(std::size_t j = 0; j < m; j++) {
      const bool end = !ch.closed && (j == 0 || j + 1 == m);
      const bool meet = (j > 0 || ch.closed) &&
                        ch.segment[(j + m - 1) % m] != ch.segment[j];
      if(!end && !meet &&
         angle(X[ch.nodes[j]] - X[ch.nodes[(j + m - 1) % m]],
               X[ch.nodes[(j + 1) % m]] - X[ch.nodes[j]]) < 1.e-4)
        continue;
      kept.push_back(j);
    }
    const std::size_t mk = kept.size();
    for(std::size_t i = 0; i < mk; i++) {
      const std::size_t j = kept[i];
      if(ch.s[j] <= cut[k][0] + gap || ch.s[j] >= cut[k][1] - gap) continue;
      Vec t = ch.tangent[j];
      const int in = ch.segment[(j + m - 1) % m], out = ch.segment[j];
      if((j > 0 || ch.closed) && in != out) {
        // (where two curves meet tangentially: the mean of their tangents
        // there, along the chain)
        bool fin = true, fout = true;
        for(auto &cf : ch.curves) {
          if(cf.first == in) fin = cf.second;
          if(cf.first == out) fout = cf.second;
        }
        t = unit((fin ? edges[in].t1 : -1. * edges[in].t0) +
                 (fout ? edges[out].t0 : -1. * edges[out].t1));
      }
      else if(ch.closed || (i > 0 && i + 1 < mk)) {
        const Vec &x = X[ch.nodes[j]];
        t = unit(unit(x - X[ch.nodes[kept[(i + mk - 1) % mk]]]) +
                 unit(X[ch.nodes[kept[(i + 1) % mk]]] - x));
      }
      Section sc;
      if(!ball(ch, X[ch.nodes[j]], t, ch.faces[j].first, ch.faces[j].second,
               sc)) {
        Msg::Error("Discrete CAD fillet: no ball of radius %g rolling on "
                   "surfaces %d and %d at node (%g, %g, %g)",
                   ch.radius, ch.faces[j].first, ch.faces[j].second,
                   X[ch.nodes[j]][0], X[ch.nodes[j]][1], X[ch.nodes[j]][2]);
        return false;
      }
      if((j > 0 || ch.closed) && in != out) {
        // (where the surface the ball rolls on changes, its contact on the
        // curve between them)
        const std::pair<int, int> &fin = ch.faces[j], &fout = ch.faces[(j + 1) % m];
        for(int side = 0; side < 2; side++) {
          const int f = side ? fin.second : fin.first,
                    g = side ? fout.second : fout.first;
          if(f == g) continue;
          Vec &x = side ? sc.b : sc.a;
          double best = 1e300;
          Vec y = x;
          for(int c : curves) {
            const std::vector<int> &cn = _curves[c].nodes;
            if(cn.size() < 2 || (cn.front() != ch.nodes[j] && cn.back() != ch.nodes[j]))
              continue;
            auto ia = along.find({cn[0], cn[1]}), ib = along.find({cn[1], cn[0]});
            if(ia == along.end() || ib == along.end()) continue;
            const int sa = surfaceOf[ia->second], sb = surfaceOf[ib->second];
            if(!((sa == f && sb == g) || (sa == g && sb == f))) continue;
            for(std::size_t q = 0; q + 1 < cn.size(); q++) {
              const Vec &u = X[cn[q]], &v = X[cn[q + 1]];
              const double l = dot(v - u, v - u);
              const double fr =
                l > 0. ? std::min(1., std::max(0., dot(x - u, v - u) / l)) : 0.;
              const Vec z = u + fr * (v - u);
              if(norm(z - x) < best) {
                best = norm(z - x);
                y = z;
              }
            }
          }
          x = y;
        }
      }
      sc.u = ch.s[j];
      std::vector<Section> &ss = sections[k];
      if(!ss.empty()) {
        const Section &pr = ss.back();
        if(dot(sc.c - pr.c, pr.t) <= 0. || dot(sc.a - pr.a, pr.t) <= 0. ||
           dot(sc.b - pr.b, pr.t) <= 0.)
          continue;
      }
      widest = std::max(widest, sc.theta);
      ss.push_back(sc);
    }
  }
  for(auto &cn : corners)
    for(int i = 0; i < 3; i++)
      for(int j = 0; j < i; j++)
        widest = std::max(widest, angle(cn.contact[i] - cn.c,
                                        cn.contact[j] - cn.c));

  // the divisions of the arcs: their chords at most the tolerance of the
  // primitives away from them
  const double step =
    relative < 1. ? 2. * std::acos(1. - relative) : pi / 2.;
  const int n = std::max(2, (int)std::ceil(widest / step - 1.e-9));
  const int K = n + 4;
  const double h = 0.5;

  // the nodes of the sections: the arc from the contact on A (on its
  // triangles) to the contact on B, and the path around the chain, out of
  // B, beyond the curve, back onto A
  std::set<int> exact;
  auto arcNodes = [&](const Vec &c, const Vec &a, const Vec &b, double r,
                      int na, int nb) {
    std::vector<int> nodes(1, na);
    const Vec u = unit(a - c);
    const Vec w = unit((b - c) - dot(b - c, u) * u);
    const double theta = angle(a - c, b - c);
    for(int i = 1; i < n; i++) {
      const double f = theta * i / n;
      const Vec x = c + r * (std::cos(f) * u + std::sin(f) * w);
      nodes.push_back(_addNode(x[0], x[1], x[2]));
      exact.insert(nodes.back());
    }
    nodes.push_back(nb);
    return nodes;
  };
  auto addNode = [&](const Vec &x) { return _addNode(x[0], x[1], x[2]); };
  // (the contacts on the triangles of the surfaces, moved off them towards
  // the path around the chain by much more than the rounding of the
  // coordinates and than the noise the booleans leave on the surfaces: the
  // arcs then cross the surfaces instead of touching them; the nodes of the
  // booleans where they cross the surfaces nearly tangentially, closer than
  // 1e-9 times the size, merged)
  const double lift = 1.e-14 * size;
  auto onFace = [&](int f, const Vec &x, double r, bool convex, int &node) {
    Vec normal;
    const Vec y = support(f).nearest(x, &normal);
    if(norm(y - x) > 0.05 * r + 2. * relative * size) return false;
    node = addNode(y + ((convex ? 1. : -1.) * lift) * normal);
    return true;
  };
  auto outer = [&](const Chain &ch, int f, const Vec &x) {
    Vec g;
    support(f).distance(x, g);
    return x + ((ch.convex ? 1. : -1.) * h * ch.radius) * g;
  };
  auto tooLarge = [&](const Chain &ch, int face) {
    Msg::Error("Discrete CAD fillet: radius %g too large, the ball rolls off "
               "surface %d of volume %d", ch.radius, face, volume);
    return false;
  };
  auto noEnd = [&](const Chain &ch, const Vec &v) {
    Msg::Error("Discrete CAD fillet: the fillet of curve %d cannot end at "
               "point (%g, %g, %g)", ch.curves[0].first, v[0], v[1], v[2]);
    return false;
  };
  for(std::size_t k = 0; k < chains.size(); k++) {
    const Chain &ch = chains[k];
    for(auto &sc : sections[k]) {
      int na, nb;
      if(!onFace(sc.A, sc.a, ch.radius, ch.convex, na))
        return tooLarge(ch, sc.A);
      if(!onFace(sc.B, sc.b, ch.radius, ch.convex, nb))
        return tooLarge(ch, sc.B);
      sc.nodes = arcNodes(sc.c, sc.a, sc.b, ch.radius, na, nb);
      sc.nodes.push_back(addNode(outer(ch, sc.B, X[nb])));
      sc.nodes.push_back(addNode(sc.p + (h * ch.radius) * sc.m));
      sc.nodes.push_back(addNode(outer(ch, sc.A, X[na])));
    }
  }

  // the corners: the sections of their chains through the center of the
  // ball, the arcs between their contacts shared, and the triangles of the
  // ball between them (rows from the arc between the first two contacts to
  // the third one) and of the path around the vertex
  std::vector<std::array<int, 3> > triangles;
  std::vector<int> label;
  // (labels: the curve of a fillet, -1 - i for corner i, 0 for the paths)
  for(std::size_t i = 0; i < corners.size(); i++) {
    Corner &cn = corners[i];
    const Chain &c0 = chains[cn.ends[0].chain];
    const double r = c0.radius;
    int contact[3], out[3];
    for(int f = 0; f < 3; f++) {
      if(!onFace(cn.faces[f], cn.contact[f], r, c0.convex, contact[f]))
        return tooLarge(c0, cn.faces[f]);
      out[f] = addNode(outer(c0, cn.faces[f], X[contact[f]]));
    }
    std::map<std::pair<int, int>, std::vector<int> > arcs;
    for(int a = 0; a < 3; a++)
      for(int b = a + 1; b < 3; b++)
        arcs[{a, b}] = arcNodes(cn.c, cn.contact[a], cn.contact[b], r,
                                contact[a], contact[b]);
    auto arc = [&](int a, int b) {
      if(a < b) return arcs[{a, b}];
      std::vector<int> nodes = arcs[{b, a}];
      std::reverse(nodes.begin(), nodes.end());
      return nodes;
    };
    auto index = [&](int face) {
      int f = 0;
      while(cn.faces[f] != face) f++;
      return f;
    };
    std::map<std::pair<int, int>, int> beyond; // (face, face) -> node
    for(std::size_t e = 0; e < cn.ends.size(); e++) {
      const End &end = cn.ends[e];
      const Chain &ch = chains[end.chain];
      const std::pair<int, int> &f =
        end.last ? ch.faces.back() : ch.faces.front();
      Section sc;
      sc.p = cn.p[e];
      sc.c = cn.c;
      sc.A = f.first;
      sc.B = f.second;
      const int a = index(f.first), b = index(f.second);
      sc.a = cn.contact[a];
      sc.b = cn.contact[b];
      sc.theta = angle(sc.a - sc.c, sc.b - sc.c);
      sc.m = -1. * unit(unit(sc.a - sc.p) + unit(sc.b - sc.p));
      sc.u = cn.s[e];
      sc.nodes = arc(a, b);
      sc.nodes.push_back(out[b]);
      const int w = addNode(sc.p + (h * r) * sc.m);
      sc.nodes.push_back(w);
      sc.nodes.push_back(out[a]);
      beyond[std::minmax(a, b)] = w;
      std::vector<Section> &ss = sections[end.chain];
      if(end.last) ss.push_back(sc);
      else ss.insert(ss.begin(), sc);
    }
    std::vector<std::vector<int> > rows(n + 1);
    const std::vector<int> ac = arc(0, 2), bc = arc(1, 2);
    rows[0] = arc(0, 1);
    for(int j = 1; j <= n; j++) {
      rows[j].push_back(ac[j]);
      if(j < n) {
        const Vec u = unit(X[ac[j]] - cn.c), v = unit(X[bc[j]] - cn.c);
        const double theta = angle(u, v);
        const Vec w = unit(v - dot(v, u) * u);
        for(int m = 1; m < n - j; m++) {
          const double f = theta * m / (n - j);
          const Vec x = cn.c + r * (std::cos(f) * u + std::sin(f) * w);
          rows[j].push_back(addNode(x));
          exact.insert(rows[j].back());
        }
        rows[j].push_back(bc[j]);
      }
    }
    for(int j = 0; j < n; j++) {
      const std::vector<int> &p = rows[j], &q = rows[j + 1];
      for(int m = 0; m + 1 < (int)p.size(); m++) {
        triangles.push_back({{p[m], p[m + 1], q[m]}});
        label.push_back(-1 - (int)i);
        if(m + 1 < (int)q.size()) {
          triangles.push_back({{p[m + 1], q[m + 1], q[m]}});
          label.push_back(-1 - (int)i);
        }
      }
    }
    // (around the vertex: out of the faces and beyond the curves, in turn)
    Vec z = X[cn.vertex], sum{{0., 0., 0.}};
    for(int f = 0; f < 3; f++) {
      Vec g;
      support(cn.faces[f]).distance(X[cn.vertex], g);
      sum = sum + g;
    }
    z = z + ((c0.convex ? 1. : -1.) * h * r) * unit(sum);
    const int center = addNode(z);
    const int ring[6] = {out[0], beyond[{0, 1}], out[1], beyond[{1, 2}],
                         out[2], beyond[{0, 2}]};
    for(int j = 0; j < 6; j++) {
      triangles.push_back({{center, ring[j], ring[(j + 1) % 6]}});
      label.push_back(0);
    }
  }

  // the ends of the chains elsewhere: the tool extended along the chain if
  // it removes no solid there (adds none for a concave curve), else ended on
  // the plane between the chain and another one ending there (shared by both
  // if neither can be extended), or else on the plane of the other surface
  // there
  struct Cap {
    std::size_t chain;
    bool last;
    Vec t;
    bool extend;
  };
  std::vector<Cap> caps;
  for(std::size_t k = 0; k < chains.size(); k++) {
    const Chain &ch = chains[k];
    if(ch.closed) continue;
    if(sections[k].size() < 2) {
      Msg::Error("Discrete CAD fillet: radius %g too large for curve %d",
                 ch.radius, ch.curves[0].first);
      return false;
    }
    for(int last = 0; last < 2; last++) {
      if(cornerOf[k][last] >= 0) continue;
      const Section &sc = last ? sections[k].back() : sections[k].front();
      const Vec t = last ? sc.t : -1. * sc.t;
      const Vec y = sc.p + (0.1 * ch.radius) * t - (0.1 * ch.radius) * sc.m;
      caps.push_back({k, last != 0, t, inside(y) != ch.convex});
    }
  }
  // (the nodes of a section moved along t onto the plane through o of
  // normal nu, the coordinate along an axis normal to it exact)
  auto onPlane = [&](const Section &sc, const Vec &t, const Vec &o,
                     const Vec &nu, std::vector<Vec> &x) {
    x.clear();
    const double tn = dot(t, nu);
    if(std::abs(tn) < 0.05) return false;
    int axis = -1;
    for(int k = 0; k < 3; k++)
      if(std::abs(nu[k]) > 1. - 1.e-12) axis = k;
    for(int node : sc.nodes) {
      const double l = dot(o - X[node], nu) / tn;
      Vec y = X[node] + l * t;
      if(axis >= 0) y[axis] = o[axis];
      x.push_back(y);
    }
    return true;
  };
  // (the end section of a chain moved onto a plane, the sections before it
  // dropped while it would fold over them)
  auto endOnPlane = [&](const Cap &cp, const Vec &o, const Vec &nu,
                        std::vector<Vec> &x) {
    std::vector<Section> &ss = sections[cp.chain];
    while(true) {
      const Section &sc = cp.last ? ss.back() : ss.front();
      const Vec t = cp.last ? sc.t : -1. * sc.t;
      if(!onPlane(sc, t, o, nu, x)) return false;
      if(ss.size() < 3) return true;
      const Section &pr = cp.last ? ss[ss.size() - 2] : ss[1];
      const double room = dot(sc.p - pr.p, t);
      bool fold = false;
      for(int k = 0; k < K; k++)
        fold = fold || dot(x[k] - X[sc.nodes[k]], t) < -0.9 * room;
      if(!fold) return true;
      if(cp.last) ss.pop_back();
      else ss.erase(ss.begin());
    }
  };
  // (the nodes of the arcs moved onto the planes, on the ball if the chain
  // is straight there)
  std::set<int> moved;
  std::vector<int> capCenter(caps.size(), -1), capFace(caps.size(), 0);
  std::set<std::size_t> shared;
  for(std::size_t i = 0; i < caps.size(); i++) {
    if(shared.count(i)) continue;
    const Cap &cp = caps[i];
    const Chain &ch = chains[cp.chain];
    const int vertex = cp.last ? ch.nodes.back() : ch.nodes.front();
    const Vec &v = X[vertex];
    auto end = [&](std::size_t j) -> Section & {
      return caps[j].last ? sections[caps[j].chain].back() :
                            sections[caps[j].chain].front();
    };
    // (the other chain ending there that shares a surface with this one: one
    // section for both, on the plane between them, its nodes the means of
    // their nodes moved onto it, in the order of the surfaces of this one)
    std::size_t other = caps.size();
    for(std::size_t j = 0; j < caps.size(); j++) {
      if(j == i || shared.count(j)) continue;
      const Chain &co = chains[caps[j].chain];
      const int w = caps[j].last ? co.nodes.back() : co.nodes.front();
      const Section &sc = end(i), &so = end(j);
      if(w == vertex && co.convex == ch.convex &&
         (so.A == sc.A || so.A == sc.B || so.B == sc.A || so.B == sc.B))
        other = j;
    }
    if(other < caps.size()) {
      const Vec nu = unit(cp.t - caps[other].t);
      std::vector<Vec> x, y;
      if(!endOnPlane(cp, v, nu, x) || !endOnPlane(caps[other], v, nu, y))
        return noEnd(ch, v);
      Section &sc = end(i), &so = end(other);
      const bool reversed = so.A == sc.B || so.B == sc.A;
      auto match = [&](int k) {
        if(!reversed) return k;
        return k <= n ? n - k : k == n + 1 ? n + 3 : k == n + 3 ? n + 1 : k;
      };
      std::vector<int> nodes(K), o(K);
      bool symmetric = true;
      for(int k = 0; k < K; k++) {
        nodes[k] = addNode(0.5 * (x[k] + y[match(k)]));
        o[match(k)] = nodes[k];
        symmetric = symmetric && norm(x[k] - y[match(k)]) <= 1.e-12 * ch.radius;
      }
      if(symmetric)
        for(int k = 1; k < n; k++) moved.insert(nodes[k]);
      sc.nodes = nodes;
      so.nodes = o;
      shared.insert(i);
      shared.insert(other);
      continue;
    }
    Section &sc = end(i);
    if(cp.extend) {
      // (beyond the other surfaces there)
      double l = (1. + h) * ch.radius;
      for(int f : surfacesAt[vertex]) {
        if(f == sc.A || f == sc.B) continue;
        Vec g;
        support(f).distance(v, g);
        const double tg = dot(cp.t, g);
        if(tg < 0.05) continue;
        for(int node : sc.nodes)
          l = std::max(l, (0.1 * ch.radius - dot(X[node] - v, g)) / tg);
      }
      l = std::min(l, 10. * (1. + h) * ch.radius);
      // (the end section moved there, not left in the plane of a surface;
      // its arc on the ball if the chain is straight there)
      for(int &node : sc.nodes) node = addNode(X[node] + l * cp.t);
      for(int k = 1; k < n; k++) moved.insert(sc.nodes[k]);
      sc.p = sc.p + l * cp.t;
      sc.u += cp.last ? l : -l;
      capCenter[i] = addNode(sc.p);
      continue;
    }
    // (on the plane of the other surface there the chain goes into most,
    // closed by a fan around the vertex)
    int face = 0;
    double best = 0.05;
    Vec nu;
    for(int f : surfacesAt[vertex]) {
      if(f == sc.A || f == sc.B) continue;
      Vec g;
      support(f).distance(v, g);
      if(std::abs(dot(cp.t, g)) > best) {
        best = std::abs(dot(cp.t, g));
        face = f;
        nu = g;
      }
    }
    std::vector<Vec> x;
    if(!face || !endOnPlane(cp, v, nu, x)) return noEnd(ch, v);
    Section &se = end(i);
    se.nodes.clear();
    for(auto &y : x) se.nodes.push_back(addNode(y));
    for(int k = 1; k < n; k++) moved.insert(se.nodes[k]);
    capFace[i] = face;
  }

  // the triangles of the tools along the chains: their arcs labeled by their
  // curves, the paths by 0; the parameters of the arcs: the length along the
  // chain and along the arc
  std::map<std::size_t, std::array<std::array<double, 2>, 3> > uvOf;
  auto quad = [&](int a, int b, int c, int d, int l,
                  const std::array<std::array<double, 2>, 4> &q) {
    // (abcd around, cut along its shorter diagonal)
    if(norm(X[a] - X[c]) <= norm(X[b] - X[d])) {
      triangles.push_back({{a, b, c}});
      triangles.push_back({{a, c, d}});
      uvOf[triangles.size() - 2] = {{q[0], q[1], q[2]}};
      uvOf[triangles.size() - 1] = {{q[0], q[2], q[3]}};
    }
    else {
      triangles.push_back({{a, b, d}});
      triangles.push_back({{b, c, d}});
      uvOf[triangles.size() - 2] = {{q[0], q[1], q[3]}};
      uvOf[triangles.size() - 1] = {{q[1], q[2], q[3]}};
    }
    label.push_back(l);
    label.push_back(l);
  };
  auto band = [&](const std::vector<int> &p, const std::vector<int> &q,
                  double up, double uq, double tp, double tq, double r,
                  int curve) {
    for(int k = 0; k < K; k++) {
      const int l = k < n ? curve : 0;
      const std::array<std::array<double, 2>, 4> uv = {
        {{{up, r * tp * k / n}},
         {{up, r * tp * (k + 1) / n}},
         {{uq, r * tq * (k + 1) / n}},
         {{uq, r * tq * k / n}}}};
      quad(p[k], p[(k + 1) % K], q[(k + 1) % K], q[k], l, uv);
    }
  };
  // (the curve of the chain at length s along it)
  auto curveAt = [&](const Chain &ch, double s) {
    std::size_t j = 0;
    while(j + 2 < ch.nodes.size() && ch.s[j + 1] <= s) j++;
    return ch.segment[std::min(j, ch.segment.size() - 1)];
  };
  for(std::size_t k = 0; k < chains.size(); k++) {
    const Chain &ch = chains[k];
    const std::vector<Section> &ss = sections[k];
    const double length = ch.closed ? ch.s.back() + norm(X[ch.nodes.front()] -
                                                         X[ch.nodes.back()]) :
                                      0.;
    for(std::size_t j = 0; j + 1 < ss.size(); j++)
      band(ss[j].nodes, ss[j + 1].nodes, ss[j].u, ss[j + 1].u, ss[j].theta,
           ss[j + 1].theta, ch.radius, curveAt(ch, 0.5 * (ss[j].u + ss[j + 1].u)));
    if(ch.closed)
      band(ss.back().nodes, ss.front().nodes, ss.back().u, length,
           ss.back().theta, ss.front().theta, ch.radius, ch.segment.back());
  }
  for(std::size_t i = 0; i < caps.size(); i++) {
    if(shared.count(i)) continue;
    const Cap &cp = caps[i];
    const Section &sc =
      cp.last ? sections[cp.chain].back() : sections[cp.chain].front();
    const std::vector<int> &end = sc.nodes;
    if(capFace[i]) {
      // (on the plane of a surface, a fan from the point beyond the curve,
      // labeled to become part of that surface)
      const int l = -1000000 - (int)i;
      for(int k = n + 3; k != n + 1; k = (k + 1) % K) {
        triangles.push_back({{end[n + 2], end[k], end[(k + 1) % K]}});
        label.push_back(l);
      }
      continue;
    }
    if(capCenter[i] < 0) continue;
    for(int k = 0; k < K; k++) {
      triangles.push_back({{capCenter[i], end[k], end[(k + 1) % K]}});
      label.push_back(0);
    }
  }
  const std::vector<std::array<int, 3> > unoriented = triangles;
  if(!orientOutwards(_nodes, triangles)) {
    Msg::Error("Discrete CAD fillet: the tools of volume %d are not closed",
               volume);
    return false;
  }
  for(auto &q : uvOf)
    if(triangles[q.first] != unoriented[q.first]) std::swap(q.second[1], q.second[2]);

  // the tools: the volumes of their connected triangles, of temporary
  // surfaces (one for the arcs of each curve, with the exact geometry of the
  // analytic surface they are on, if any, one for each corner, one for the
  // paths), those of the convex curves and of the concave ones
  std::vector<std::size_t> parent(triangles.size());
  for(std::size_t i = 0; i < parent.size(); i++) parent[i] = i;
  std::function<std::size_t(std::size_t)> find = [&](std::size_t i) {
    while(parent[i] != i) i = parent[i] = parent[parent[i]];
    return i;
  };
  {
    std::map<std::pair<int, int>, std::size_t> first;
    for(std::size_t i = 0; i < triangles.size(); i++)
      for(int k = 0; k < 3; k++) {
        auto in = first.insert(
          {std::minmax(triangles[i][k], triangles[i][(k + 1) % 3]), i});
        if(!in.second) parent[find(i)] = find(in.first->second);
      }
  }
  std::map<int, bool> convexOf; // label -> convex
  std::map<std::size_t, bool> convexTool;
  for(std::size_t k = 0; k < chains.size(); k++)
    for(auto &cf : chains[k].curves) convexOf[cf.first] = chains[k].convex;
  for(std::size_t i = 0; i < corners.size(); i++)
    convexOf[-1 - (int)i] = chains[corners[i].ends[0].chain].convex;
  for(std::size_t i = 0; i < caps.size(); i++)
    convexOf[-1000000 - (int)i] = chains[caps[i].chain].convex;
  for(std::size_t i = 0; i < triangles.size(); i++)
    if(label[i]) convexTool[find(i)] = convexOf[label[i]];
  std::map<std::pair<std::size_t, int>, std::vector<std::size_t> > groups;
  for(std::size_t i = 0; i < triangles.size(); i++)
    groups[{find(i), label[i]}].push_back(i);
  std::vector<std::pair<int, int> > tools[2]; // concave, convex
  std::map<int, int> alias;
  std::map<std::size_t, int> volumeOfTool;
  int fillets = 0;
  for(auto &g : groups) {
    int s = -1;
    _assignTag(2, s);
    Surface &sf = _surfaces[s];
    for(std::size_t i : g.second) sf.triangles.push_back(triangles[i]);
    const int l = g.first.second;
    if(l <= -1000000) {
      // (the part of a surface: its exact geometry, and the parameters of
      // its plane, from one of its triangles)
      const int face = capFace[-1000000 - l];
      const Surface &fs = _surfaces[face];
      sf.analytic = fs.analytic;
      alias[s] = face;
      if(!fs.uv.empty()) {
        const std::array<int, 3> &t = fs.triangles[0];
        const Vec e1 = X[t[1]] - X[t[0]], e2 = X[t[2]] - X[t[0]];
        const double a11 = dot(e1, e1), a12 = dot(e1, e2), a22 = dot(e2, e2);
        const double det = a11 * a22 - a12 * a12;
        for(auto &tr : sf.triangles) {
          std::array<std::array<double, 2>, 3> q;
          for(int k = 0; k < 3; k++) {
            const Vec d = X[tr[k]] - X[t[0]];
            const double b1 = dot(d, e1), b2 = dot(d, e2);
            const double l1 = (a22 * b1 - a12 * b2) / det;
            const double l2 = (a11 * b2 - a12 * b1) / det;
            for(int m = 0; m < 2; m++)
              q[k][m] = fs.uv[0][0][m] + l1 * (fs.uv[0][1][m] - fs.uv[0][0][m]) +
                        l2 * (fs.uv[0][2][m] - fs.uv[0][0][m]);
          }
          sf.uv.push_back(q);
        }
      }
    }
    else if(l) {
      fillets++;
      // (the analytic surface fitted to the nodes on the ball)
      std::map<int, int> local;
      std::vector<std::array<double, 3> > x;
      std::vector<std::array<int, 3> > all, onBall, nearBall;
      for(auto &t : sf.triangles) {
        std::array<int, 3> lt;
        bool ballOnly = true, nearOnly = true;
        for(int k = 0; k < 3; k++) {
          auto in = local.insert({t[k], (int)x.size()});
          if(in.second) x.push_back(X[t[k]]);
          lt[k] = in.first->second;
          ballOnly = ballOnly && exact.count(t[k]);
          nearOnly = nearOnly && (exact.count(t[k]) || moved.count(t[k]));
        }
        all.push_back(lt);
        if(ballOnly) onBall.push_back(lt);
        if(nearOnly) nearBall.push_back(lt);
      }
      if(onBall.size() < 2) onBall = nearBall;
      const double r = l > 0 ? selected[l] :
                               chains[corners[-1 - l].ends[0].chain].radius;
      DiscreteCADAnalyticSurface a;
      if(onBall.size() >= 2) {
        std::map<int, int> sub;
        std::vector<std::array<double, 3> > y;
        std::vector<std::array<int, 3> > st;
        for(auto &t : onBall) {
          std::array<int, 3> lt;
          for(int k = 0; k < 3; k++) {
            auto in = sub.insert({t[k], (int)y.size()});
            if(in.second) y.push_back(x[t[k]]);
            lt[k] = in.first->second;
          }
          st.push_back(lt);
        }
        a = recognizeSurface(y, st, 1.e-9 * r, 20. * pi / 180.);
        if(a.type == DiscreteCADAnalyticSurface::PLANE)
          a = DiscreteCADAnalyticSurface();
      }
      bool done = false;
      if(a.type != DiscreteCADAnalyticSurface::NONE) {
        std::vector<std::array<std::array<double, 2>, 3> > uv;
        std::vector<int> half;
        std::vector<DiscreteCADAnalyticMap> maps;
        int apex;
        analyticParameters(a, x, all, 1.e-9 * r, uv, half, apex, maps);
        // (one map, or the same half of two for all the triangles)
        const bool one = std::count(half.begin(), half.end(), half[0]) ==
                         (std::ptrdiff_t)half.size();
        if(apex < 0 && one && half[0] < (int)maps.size()) {
          sf.uv = uv;
          sf.analytic = maps[half[0]];
          done = true;
        }
      }
      if(!done && l > 0)
        for(std::size_t i : g.second) sf.uv.push_back(uvOf[i]);
    }
    auto it = volumeOfTool.find(g.first.first);
    if(it == volumeOfTool.end()) {
      int v = -1;
      _assignTag(3, v);
      _volumes[v] = Volume();
      it = volumeOfTool.insert({g.first.first, v}).first;
      tools[convexTool[g.first.first] ? 1 : 0].push_back({3, v});
    }
    _volumes[it->second].surfaces.push_back(s);
  }

  // the booleans: the union with the tools of the concave curves, then the
  // difference with those of the convex ones
  std::vector<std::pair<int, int> > object = {{3, volume}};
  bool remove = removeVolume, ok = true;
  for(int op = 0; op < 2 && ok; op++) {
    if(tools[op].empty()) continue;
    std::vector<std::pair<int, int> > out;
    std::vector<std::vector<std::pair<int, int> > > map;
    ok = booleanOperation(op ? 2 : 0, object, tools[op], out, map, -1, remove,
                          false, 1.e-9, &alias);
    if(ok) {
      object = out;
      remove = true;
    }
  }
  for(auto &vt : volumeOfTool) _removeVolume(vt.second);
  if(ok) {
    // the new nodes of the result very close to the edges of the triangles
    // of the volume (the merged nodes where the arcs cross the surfaces next
    // to them) moved onto them: else the triangles along the edges are
    // tilted by about as much as the contacts of the next fillets are moved
    // off the surfaces
    std::set<int> old;
    for(auto &t : tri) old.insert(t.begin(), t.end());
    std::set<std::pair<int, int> > edgesOfVolume;
    for(auto &t : tri)
      for(int k = 0; k < 3; k++)
        edgesOfVolume.insert(std::minmax(t[k], t[(k + 1) % 3]));
    const double near = 1.e-9 * size, cell = size / 64.;
    std::map<std::array<long, 3>, std::vector<std::pair<int, int> > > cells;
    auto cellOf = [&](double x, double y, double z) {
      return std::array<long, 3>{{(long)std::floor(x / cell),
                                  (long)std::floor(y / cell),
                                  (long)std::floor(z / cell)}};
    };
    for(auto &e : edgesOfVolume) {
      // (in the cells its box overlaps, with the margin)
      const Vec &a = X[e.first], &b = X[e.second];
      const std::array<long, 3> lo =
        cellOf(std::min(a[0], b[0]) - near, std::min(a[1], b[1]) - near,
               std::min(a[2], b[2]) - near);
      const std::array<long, 3> hi =
        cellOf(std::max(a[0], b[0]) + near, std::max(a[1], b[1]) + near,
               std::max(a[2], b[2]) + near);
      for(long cx = lo[0]; cx <= hi[0]; cx++)
        for(long cy = lo[1]; cy <= hi[1]; cy++)
          for(long cz = lo[2]; cz <= hi[2]; cz++)
            cells[{{cx, cy, cz}}].push_back(e);
    }
    std::set<int> moved;
    for(auto &o : object)
      for(int sf : _volumes[o.second].surfaces)
        for(auto &t : _surfaces[std::abs(sf)].triangles)
          for(int node : t) {
            if(old.count(node) || !moved.insert(node).second) continue;
            auto it = cells.find(
              cellOf(_nodes[node][0], _nodes[node][1], _nodes[node][2]));
            if(it == cells.end()) continue;
            const Vec x = _nodes[node];
            double best = near;
            Vec y = x;
            for(auto &e : it->second) {
              const Vec &a = X[e.first], &b = X[e.second];
              const double l = dot(b - a, b - a);
              const double f =
                l > 0. ? std::min(1., std::max(0., dot(x - a, b - a) / l)) : 0.;
              const Vec z = a + f * (b - a);
              if(norm(z - x) < best) {
                best = norm(z - x);
                y = z;
              }
            }
            _nodes[node] = y;
          }
  }
  if(!ok) {
    Msg::Error("Discrete CAD fillet of volume %d failed", volume);
    return false;
  }
  outDimTags = object;
  Msg::Info("Discrete CAD fillet: %lu chain%s of curves of volume %d, %lu "
            "corner%s, %d fillet surface%s",
            chains.size(), chains.size() == 1 ? "" : "s", volume,
            corners.size(), corners.size() == 1 ? "" : "s", fillets,
            fillets == 1 ? "" : "s");
  return true;
}
