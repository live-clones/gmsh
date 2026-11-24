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
#include <cctype>
#include <cmath>
#include <climits>
#include <memory>
#include <cstdio>
#include "DiscreteCADModeler.h"
#include "DiscreteCADHeal.h"
#include "DiscreteCADMeshBoolean.h"
#include "DiscreteCADArrangement.h"
#include "DiscreteCADRecognition.h"
#include "DiscreteCADWinding.h"
#include "GmshMessage.h"
#include "Context.h"
#include "GModel.h"
#include "GModelIO_GEO.h"
#include "GModelIO_OCC.h"
#include "OpenFile.h"
#include "OS.h"
#include "StringUtils.h"
#include "discreteVertex.h"
#include "discreteEdge.h"
#include "discreteFace.h"
#include "discreteRegion.h"
#include "MVertex.h"
#include "MLine.h"
#include "MTriangle.h"
#include "SPoint2.h"
#include "SPoint3.h"
#include "GEdgeLoop.h"
#include "GModelParametrize.h"

#if defined(HAVE_OCC)
#include <BRep_Builder.hxx>
#include <BRep_Tool.hxx>
#include <BRepMesh_IncrementalMesh.hxx>
#include <Poly_Triangulation.hxx>
#include <Standard_Version.hxx>
#include <TopLoc_Location.hxx>
#include <TopoDS.hxx>
#include <TopoDS_Compound.hxx>
#include <TopoDS_Face.hxx>
#endif

namespace {
  const char *entityName(int dim)
  {
    static const char *names[4] = {"point", "curve", "surface", "volume"};
    return names[dim];
  }

  // the maximum distance between the unit sphere and the triangles of an
  // octant of the octahedron, n times subdivided, projected on it: 1 - the
  // distance of the plane of each triangle to the center (the distance to
  // the circumcenter of the triangle, an upper bound when it lies outside)
  double octantDeviation(int n)
  {
    auto point = [n](int i, int j) {
      std::array<double, 3> p = {(double)i, (double)j, (double)(n - i - j)};
      const double r = std::sqrt(p[0] * p[0] + p[1] * p[1] + p[2] * p[2]);
      for(int k = 0; k < 3; k++) p[k] /= r;
      return p;
    };
    auto deviation = [](const std::array<double, 3> &a,
                        const std::array<double, 3> &b,
                        const std::array<double, 3> &c) {
      const double u[3] = {b[0] - a[0], b[1] - a[1], b[2] - a[2]};
      const double v[3] = {c[0] - a[0], c[1] - a[1], c[2] - a[2]};
      const double w[3] = {u[1] * v[2] - u[2] * v[1], u[2] * v[0] - u[0] * v[2],
                           u[0] * v[1] - u[1] * v[0]};
      const double l = std::sqrt(w[0] * w[0] + w[1] * w[1] + w[2] * w[2]);
      return 1. - std::abs(w[0] * a[0] + w[1] * a[1] + w[2] * a[2]) / l;
    };
    double d = 0.;
    for(int i = 0; i < n; i++)
      for(int j = 0; i + j < n; j++) {
        d = std::max(d, deviation(point(i, j), point(i + 1, j), point(i, j + 1)));
        if(i + j + 2 <= n)
          d = std::max(d, deviation(point(i + 1, j), point(i + 1, j + 1),
                                    point(i, j + 1)));
      }
    return d;
  }

  const double pi = 3.14159265358979323846;

  // the report of a step of the import of triangulations, added to the list
  // of the reports however the step ends
  struct stepReport {
    std::vector<DiscreteCAD_Internals::Report> &reports;
    std::string text;
    std::vector<DiscreteCAD_Internals::ReportItem> items;
    DiscreteCAD_Internals::Zip zip;
    DiscreteCAD_Internals::Fit fit;
    ~stepReport() { reports.push_back({text, items, zip, fit}); }
    // an item: the triangles (dim 2), the edges (1) or the nodes (0) given
    // by their nodes, if there are some, with their values (1 if none)
    void add(const std::string &label, int dim, const std::vector<int> &nodes,
             const std::vector<double> &values = std::vector<double>())
    {
      if(nodes.empty()) return;
      DiscreteCAD_Internals::ReportItem it;
      it.label = label;
      it.dim = dim;
      it.nodes = nodes;
      it.values = values;
      it.values.resize(nodes.size() / (dim + 1), 1.);
      items.push_back(it);
    }
  };

  // a value in [0, 1) for each number, scattered (the colors of the pieces,
  // volumes or surfaces of a report)
  double scattered(int n) { return (double)(((unsigned)n * 2654435761u) % 997) / 997.; }

  std::string plural(std::size_t n, const char *one, const char *many)
  {
    return std::to_string(n) + " " + (n == 1 ? one : many);
  }

  // a tolerance for recognize, in fit.proposed: in the distribution of the
  // distances of the nearest surfaces fitted to the classified faces (by half
  // decades, in fit; those nearer than twice the precision of the coordinates
  // counted there), the middle of the highest run of half decades with few
  // faces (fewer than 3, or than one in 200) between two with more: between
  // the faces on analytic surfaces, up to the rounding of their coordinates
  // or to the tolerance of the modeler that made them, and those only near
  // such surfaces (free form surfaces near a sphere, a cone...); 0 if there
  // is none. What it is made of
  std::string fitTolerance(DiscreteCAD_Internals::Fit &fit)
  {
    const double floor = std::max(2. * fit.precision, 1.e-300);
    std::vector<int> bins;
    for(auto &dv : fit.deviations) {
      double m = 1e300;
      for(int t = 1; t < 6; t++) m = std::min(m, dv[t]);
      if(m <= fit.reach)
        bins.push_back((int)std::floor(2. * std::log10(std::max(m, floor))));
    }
    fit.proposed = 0.;
    fit.counts.clear();
    char text[256];
    if(bins.empty()) {
      snprintf(text, sizeof(text),
               "no tolerance proposed: no face within %g of a plane, a sphere, "
               "a cylinder, a cone or a torus",
               fit.reach);
      return text;
    }
    fit.first = *std::min_element(bins.begin(), bins.end());
    for(int b : bins) {
      const std::size_t i = (std::size_t)(b - fit.first);
      if(fit.counts.size() <= i) fit.counts.resize(i + 1, 0);
      fit.counts[i]++;
    }
    auto edge = [&](int i) { return std::pow(10., 0.5 * (fit.first + i)); };
    const int few = std::max(3, (int)bins.size() / 200);
    const int nb = (int)fit.counts.size();
    // (the highest run, from its first half decade to the one after its last)
    int from = -1, to = -1;
    for(int i = 0, last = -1; i < nb; i++) {
      if(fit.counts[i] < few) continue;
      if(last >= 0 && i - last > 1) {
        from = last + 1;
        to = i;
      }
      last = i;
    }
    if(from < 0) {
      snprintf(text, sizeof(text),
               "no tolerance proposed: the faces from %g to %g away from "
               "their nearest surfaces, without a gap",
               edge(0), edge(nb));
      return text;
    }
    int below = 0, above = 0;
    for(int i = 0; i < nb; i++) (i < to ? below : above) += fit.counts[i];
    fit.proposed = std::pow(10., 0.25 * (2 * fit.first + from + to));
    snprintf(text, sizeof(text),
             "proposed %g: %d faces within %g of their nearest surfaces, %d "
             "others from %g (the coordinates within %g)",
             fit.proposed, below, edge(from), above, edge(to), fit.precision);
    return text;
  }


  // A triangulation cut open into a disk, the triangles of the copies of its
  // nodes (and the node of each copy in nodeOfCopy): the corners of a node
  // share a copy if they are connected across uncut edges of two triangles.
  // The cut: the edges of two triangles that a spanning tree of the
  // triangles, grown from the triangle farthest from the boundary, does not
  // cross, without the branches ending inside the triangulation (it then
  // joins its boundaries and goes around its handles: a cut graph); for a
  // closed triangulation of genus 0, a path between two nodes far apart. The
  // edges of one triangle or more than two are boundaries, never cut.
  std::vector<std::array<int, 3> >
  cutOpen(const std::vector<std::array<int, 3> > &t,
          std::vector<int> &nodeOfCopy)
  {
    const std::size_t nt = t.size();
    std::map<std::pair<int, int>, std::vector<std::size_t> > edges;
    for(std::size_t i = 0; i < nt; i++)
      for(int k = 0; k < 3; k++)
        edges[std::minmax(t[i][k], t[i][(k + 1) % 3])].push_back(i);
    // the triangles across the edges of two triangles, by their distance to
    // the boundary
    std::vector<std::vector<std::size_t> > across(nt);
    std::vector<int> distance(nt, -1);
    std::vector<std::size_t> queue;
    for(auto &e : edges) {
      if(e.second.size() == 2) {
        across[e.second[0]].push_back(e.second[1]);
        across[e.second[1]].push_back(e.second[0]);
      }
      else
        for(std::size_t i : e.second)
          if(distance[i] < 0) {
            distance[i] = 0;
            queue.push_back(i);
          }
    }
    if(queue.empty()) {
      distance[0] = 0;
      queue.push_back(0);
    }
    for(std::size_t q = 0; q < queue.size(); q++)
      for(std::size_t j : across[queue[q]])
        if(distance[j] < 0) {
          distance[j] = distance[queue[q]] + 1;
          queue.push_back(j);
        }
    // (the spanning tree, of each connected piece)
    std::set<std::pair<int, int> > crossed;
    std::vector<char> reached(nt, 0);
    std::vector<std::size_t> order(nt);
    for(std::size_t i = 0; i < nt; i++) order[i] = i;
    std::stable_sort(order.begin(), order.end(),
                     [&](std::size_t a, std::size_t b) {
                       return distance[a] > distance[b];
                     });
    auto sharedEdge = [&](std::size_t i, std::size_t j) -> std::pair<int, int> {
      for(int k = 0; k < 3; k++) {
        const int a = t[i][k], b = t[i][(k + 1) % 3];
        for(int l = 0; l < 3; l++)
          if(std::minmax(a, b) == std::minmax(t[j][l], t[j][(l + 1) % 3]))
            return std::minmax(a, b);
      }
      return std::pair<int, int>(-1, -1);
    };
    for(std::size_t seed : order) {
      if(reached[seed]) continue;
      reached[seed] = 1;
      std::vector<std::size_t> front = {seed};
      for(std::size_t q = 0; q < front.size(); q++)
        for(std::size_t j : across[front[q]])
          if(!reached[j]) {
            reached[j] = 1;
            crossed.insert(sharedEdge(front[q], j));
            front.push_back(j);
          }
    }
    // the cut, its branches ending inside pruned
    std::set<std::pair<int, int> > cut;
    std::map<int, int> degree;
    std::map<int, std::vector<std::pair<int, int> > > cutAt;
    bool closed = true;
    for(auto &e : edges) {
      if(e.second.size() != 2) {
        closed = false;
        degree[e.first.first]++;
        degree[e.first.second]++;
      }
      else if(!crossed.count(e.first)) {
        cut.insert(e.first);
        degree[e.first.first]++;
        degree[e.first.second]++;
        cutAt[e.first.first].push_back(e.first);
        cutAt[e.first.second].push_back(e.first);
      }
    }
    std::vector<int> leaves;
    for(auto &d : degree)
      if(d.second == 1) leaves.push_back(d.first);
    while(!leaves.empty()) {
      const int n = leaves.back();
      leaves.pop_back();
      if(degree[n] != 1) continue;
      for(auto &e : cutAt[n]) {
        if(!cut.erase(e)) continue;
        const int m = e.first == n ? e.second : e.first;
        degree[n]--;
        if(--degree[m] == 1) leaves.push_back(m);
        break;
      }
    }
    if(closed && cut.empty()) {
      // (a path between two nodes far apart: from the node farthest from a
      // node to the one farthest from it)
      std::map<int, std::vector<int> > neighbors;
      for(auto &e : edges) {
        neighbors[e.first.first].push_back(e.first.second);
        neighbors[e.first.second].push_back(e.first.first);
      }
      auto farthest = [&](int from, std::map<int, int> &previous) {
        previous.clear();
        previous[from] = from;
        std::vector<int> front = {from};
        for(std::size_t q = 0; q < front.size(); q++)
          for(int m : neighbors[front[q]])
            if(!previous.count(m)) {
              previous[m] = front[q];
              front.push_back(m);
            }
        return front.back();
      };
      std::map<int, int> previous;
      const int u = farthest(t[0][0], previous);
      const int w = farthest(u, previous);
      for(int n = w; n != u; n = previous[n])
        cut.insert(std::minmax(n, previous[n]));
    }
    // the copies of the nodes
    std::vector<std::size_t> parent(3 * nt);
    for(std::size_t c = 0; c < 3 * nt; c++) parent[c] = c;
    std::function<std::size_t(std::size_t)> find = [&](std::size_t c) {
      while(parent[c] != c) c = parent[c] = parent[parent[c]];
      return c;
    };
    auto corner = [&](std::size_t i, int n) {
      int k = 0;
      while(k < 2 && t[i][k] != n) k++;
      return 3 * i + k;
    };
    for(auto &e : edges) {
      if(e.second.size() != 2 || cut.count(e.first)) continue;
      for(int n : {e.first.first, e.first.second})
        parent[find(corner(e.second[0], n))] = find(corner(e.second[1], n));
    }
    std::map<std::size_t, int> copyOf;
    nodeOfCopy.clear();
    std::vector<std::array<int, 3> > copies(nt);
    for(std::size_t i = 0; i < nt; i++)
      for(int k = 0; k < 3; k++) {
        auto it = copyOf.insert({find(3 * i + k), (int)nodeOfCopy.size()});
        if(it.second) nodeOfCopy.push_back(t[i][k]);
        copies[i][k] = it.first->second;
      }
    return copies;
  }

  void normalize(double v[3])
  {
    const double l = std::sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
    if(l > 0.)
      for(int k = 0; k < 3; k++) v[k] /= l;
  }

  // the frame of origin (x, y, z), of third axis zAxis and first axis xAxis
  // made orthogonal to it (the z axis, and the x or y axis, if empty)
  DiscreteCAD_Internals::Frame frame(double x, double y, double z,
                                     const std::vector<double> &zAxis,
                                     const std::vector<double> &xAxis)
  {
    DiscreteCAD_Internals::Frame f;
    f.o[0] = x;
    f.o[1] = y;
    f.o[2] = z;
    double *e0 = f.e[0], *e1 = f.e[1], *e2 = f.e[2];
    for(int k = 0; k < 3; k++) e2[k] = zAxis.size() == 3 ? zAxis[k] : k == 2;
    normalize(e2);
    double t[3] = {1., 0., 0.};
    if(xAxis.size() == 3)
      for(int k = 0; k < 3; k++) t[k] = xAxis[k];
    for(int pass = 0; pass < 2; pass++) {
      const double d = t[0] * e2[0] + t[1] * e2[1] + t[2] * e2[2];
      for(int k = 0; k < 3; k++) e0[k] = t[k] - d * e2[k];
      if(e0[0] * e0[0] + e0[1] * e0[1] + e0[2] * e0[2] > 1.e-12) break;
      // xAxis (or x) along zAxis: y instead
      t[0] = 0.;
      t[1] = 1.;
      t[2] = 0.;
    }
    normalize(e0);
    e1[0] = e2[1] * e0[2] - e2[2] * e0[1];
    e1[1] = e2[2] * e0[0] - e2[0] * e0[2];
    e1[2] = e2[0] * e0[1] - e2[1] * e0[0];
    return f;
  }

  // the divisions (even, at least 4) of a circle of radius r whose chords are
  // at most tolerance away from it
  int circleDivisions(double r, double tolerance)
  {
    const int maxDivisions = 4096;
    if(tolerance >= r) return 4;
    int n = (int)std::ceil(pi / std::acos(1. - tolerance / r) - 1.e-9);
    n = std::max(4, n + n % 2);
    return std::min(n, maxDivisions);
  }

  // the triangles between the halves [h pi, (h + 1) pi] of rings a and b
  // (closed, of an even number of nodes, or a single node), by increasing
  // angle: oriented outwards for b above a on a surface of revolution, and
  // along the axis for b inside a in a plane
  void zipHalf(const std::vector<int> &a, const std::vector<int> &b, int h,
               std::vector<std::array<int, 3> > &triangles)
  {
    auto half = [h](const std::vector<int> &r) {
      const int n = (int)r.size();
      std::vector<int> p;
      if(n == 1) p.push_back(r[0]);
      else
        for(int i = h * n / 2; i <= (h + 1) * n / 2; i++) p.push_back(r[i % n]);
      return p;
    };
    const std::vector<int> pa = half(a), pb = half(b);
    const int na = (int)pa.size() - 1, nb = (int)pb.size() - 1;
    int i = 0, j = 0;
    while(i < na || j < nb) {
      // on the ring whose next node comes first
      if(j == nb || (i < na && (double)(i + 1) / na <= (double)(j + 1) / nb)) {
        triangles.push_back({{pa[i], pa[i + 1], pb[j]}});
        i++;
      }
      else {
        triangles.push_back({{pa[i], pb[j + 1], pb[j]}});
        j++;
      }
    }
  }

  void reverse(std::vector<std::array<int, 3> > &triangles)
  {
    for(auto &t : triangles) std::swap(t[1], t[2]);
  }

  // the triangles of the simple polygon p oriented as o (the sign of the
  // cross products at its convex corners), cut off one at a time at the
  // corner whose triangle is the best shaped of those without other corners
  // in them; none if there is no such corner
  std::vector<std::array<int, 3> > triangulatePolygon(const std::vector<SPoint2> &p,
                                                       double o)
  {
    auto area = [&](int i, int j, int k) {
      return o * ((p[j].x() - p[i].x()) * (p[k].y() - p[i].y()) -
                  (p[j].y() - p[i].y()) * (p[k].x() - p[i].x()));
    };
    std::vector<int> left(p.size());
    for(std::size_t i = 0; i < p.size(); i++) left[i] = (int)i;
    std::vector<std::array<int, 3> > triangles;
    while(left.size() > 2) {
      const std::size_t m = left.size();
      std::size_t best = m;
      double quality = 1.e-9;
      for(std::size_t i = 0; i < m; i++) {
        const int a = left[(i + m - 1) % m], b = left[i], c = left[(i + 1) % m];
        const double s =
          p[a].distance(p[b]) + p[b].distance(p[c]) + p[c].distance(p[a]);
        const double q = area(a, b, c) / (s * s);
        if(!(q > quality)) continue;
        bool empty = true;
        for(std::size_t j = 0; j < m && empty; j++) {
          const int d = left[j];
          if(d != a && d != b && d != c)
            empty = !(area(a, b, d) >= 0. && area(b, c, d) >= 0. &&
                      area(c, a, d) >= 0.);
        }
        if(!empty) continue;
        best = i;
        quality = q;
      }
      if(best == m) return {};
      triangles.push_back(
        {left[(best + m - 1) % m], left[best], left[(best + 1) % m]});
      left.erase(left.begin() + best);
    }
    return triangles;
  }

  // the chart of an analytic surface (the parameters uv of its points xyz,
  // those of map with v times flip; node: the node of each point) fitted to
  // the curves on the intersection of analytic surfaces (segments: their
  // surfaces, by the nodes of the segments of their polylines), so that it
  // contains them (bounded by their chords, it leaves out their arcs that
  // bulge out of it, whose closest points are then on the chords): its
  // edges on the boundary along them replaced by points of the curves (in
  // the planes normal to the edge, enough for the arcs between them to be
  // within 1e-3 times its length of their chords) and the apices of the
  // triangles on the chords enclosing the arcs that bulge out (tangent at
  // their ends to the parabola through their ends and middle, a quarter
  // higher for arcs of varying curvature), the triangle along the edge by
  // the fan from its opposite corner, if all of it keeps its orientation,
  // else, for an arc out of the triangle, the triangle kept and the polygon
  // between the chord and the arc triangulated (the opposite corner nearly
  // on the line of the edge, a sliver of the triangulation: the fan folds
  // over; an arc into such a triangle, out of it through another edge, is
  // in the chart and left); the parameters of the ends of the edges those
  // of their points. The numbers of edges fitted and left as chords
  std::pair<int, int> fitChartToCurves(
    const DiscreteCADAnalyticMap &map, double flip,
    const std::map<std::pair<int, int>,
                   std::vector<const DiscreteCADAnalyticSurface *> > &segments,
    const std::vector<int> &node, std::vector<SPoint2> &uv,
    std::vector<SPoint3> &xyz, std::vector<int> &triangles)
  {
    auto parameters = [&](const SPoint3 &x, double u, double v) {
      const double p[3] = {x.x(), x.y(), x.z()}, guess[2] = {u, flip * v};
      double q[2];
      map.parameters(p, guess, q);
      return SPoint2(q[0], flip * q[1]);
    };
    // the point x of the curve of the surfaces s in the plane normal to ab
    // through a + f (b - a)
    auto onCurve = [](const std::vector<const DiscreteCADAnalyticSurface *> &s,
                      const SPoint3 &a, const SPoint3 &b, double f,
                      SPoint3 &x) {
      double p[3], t[3], y[3];
      for(int k = 0; k < 3; k++) {
        p[k] = a[k] + f * (b[k] - a[k]);
        t[k] = b[k] - a[k];
      }
      normalize(t);
      if(!intersectSurfaces(s, p, t, y)) return false;
      x = SPoint3(y[0], y[1], y[2]);
      return true;
    };
    auto cross = [](const SPoint2 &a, const SPoint2 &b, const SPoint2 &c) {
      return (b.x() - a.x()) * (c.y() - a.y()) -
             (b.y() - a.y()) * (c.x() - a.x());
    };
    std::map<std::pair<int, int>, int> uses;
    for(std::size_t i = 0; i < triangles.size(); i++)
      uses[std::minmax(triangles[i], triangles[i - i % 3 + (i + 1) % 3])]++;
    std::map<std::pair<int, int>,
             const std::vector<const DiscreteCADAnalyticSurface *> *>
      along;
    for(auto &e : uses) {
      if(e.second != 1) continue;
      auto s =
        segments.find(std::minmax(node[e.first.first], node[e.first.second]));
      if(s != segments.end()) along[e.first] = &s->second;
    }
    std::pair<int, int> fitted(0, 0);
    for(std::size_t t = 0; t < triangles.size() / 3; t++) {
      for(int k = 0; k < 3; k++) {
        const int a = triangles[3 * t + k], b = triangles[3 * t + (k + 1) % 3],
                  c = triangles[3 * t + (k + 2) % 3];
        auto e = along.find(std::minmax(a, b));
        if(e == along.end()) continue;
        const std::vector<const DiscreteCADAnalyticSurface *> &s = *e->second;
        along.erase(e);
        uv[a] = parameters(xyz[a], uv[a].x(), uv[a].y());
        uv[b] = parameters(xyz[b], uv[b].x(), uv[b].y());
        const double l = xyz[a].distance(xyz[b]);
        SPoint3 m;
        if(!onCurve(s, xyz[a], xyz[b], 0.5, m)) {
          fitted.second++;
          continue;
        }
        const SPoint3 middle(0.5 * (xyz[a].x() + xyz[b].x()),
                             0.5 * (xyz[a].y() + xyz[b].y()),
                             0.5 * (xyz[a].z() + xyz[b].z()));
        const double sagitta = m.distance(middle);
        if(!(sagitta > 1.e-9 * l)) continue;
        const int n = std::min(
          16, (int)std::ceil(std::sqrt(sagitta / (1.e-3 * l)) - 1.e-9));
        std::vector<SPoint3> x(n + 1);
        std::vector<SPoint2> p(n + 1);
        x[0] = xyz[a];
        p[0] = uv[a];
        x[n] = xyz[b];
        p[n] = uv[b];
        bool found = true;
        for(int i = 1; i < n && found; i++) {
          const double f = (double)i / n;
          found = onCurve(s, xyz[a], xyz[b], f, x[i]);
          p[i] = parameters(x[i], (1. - f) * uv[a].x() + f * uv[b].x(),
                            (1. - f) * uv[a].y() + f * uv[b].y());
        }
        // (the side out of the chart, to the right of ab if the triangle is
        // positively oriented)
        const double o = cross(uv[a], uv[b], uv[c]) > 0. ? 1. : -1.;
        std::vector<SPoint2> fanUV(1, p[0]);
        std::vector<SPoint3> fanXYZ(1, x[0]);
        for(int i = 0; i < n && found; i++) {
          if(i) {
            fanUV.push_back(p[i]);
            fanXYZ.push_back(x[i]);
          }
          SPoint3 y;
          found = onCurve(s, x[i], x[i + 1], 0.5, y);
          if(!found) break;
          const double mu = 0.5 * (p[i].x() + p[i + 1].x());
          const double mv = 0.5 * (p[i].y() + p[i + 1].y());
          const SPoint2 q = parameters(y, mu, mv);
          const double eu = p[i + 1].x() - p[i].x();
          const double ev = p[i + 1].y() - p[i].y();
          const double du = q.x() - mu, dv = q.y() - mv;
          const double ee = eu * eu + ev * ev;
          if(!(ee > 0.) || o * (eu * dv - ev * du) >= 0.) continue;
          // (the bulge normal to the chord)
          const double h = 2.5 * (du * eu + dv * ev) / ee;
          const SPoint2 apex(mu + 2.5 * du - h * eu, mv + 2.5 * dv - h * ev);
          double z[3];
          map.point(apex.x(), flip * apex.y(), z);
          fanUV.push_back(apex);
          fanXYZ.push_back(SPoint3(z[0], z[1], z[2]));
        }
        fanUV.push_back(p[n]);
        fanXYZ.push_back(x[n]);
        bool fan = found;
        for(std::size_t i = 0; i + 1 < fanUV.size() && fan; i++)
          fan = o * cross(fanUV[i], fanUV[i + 1], uv[c]) >
                1.e-9 * fanUV[i].distance(fanUV[i + 1]) *
                  fanUV[i].distance(uv[c]);
        std::vector<std::array<int, 3> > out;
        if(found && !fan) {
          bool outside = true;
          for(std::size_t i = 1; i + 1 < fanUV.size() && outside; i++)
            outside = o * cross(uv[a], uv[b], fanUV[i]) < 0.;
          if(outside) out = triangulatePolygon(fanUV, o);
        }
        if(!fan && out.empty()) {
          fitted.second++;
          continue;
        }
        std::vector<int> points(1, a);
        for(std::size_t i = 1; i + 1 < fanUV.size(); i++) {
          points.push_back((int)uv.size());
          uv.push_back(fanUV[i]);
          xyz.push_back(fanXYZ[i]);
        }
        points.push_back(b);
        fitted.first++;
        if(!fan) {
          for(auto &tr : out)
            for(int i : tr) triangles.push_back(points[i]);
          continue;
        }
        triangles[3 * t + (k + 1) % 3] = points[1];
        for(std::size_t i = 1; i + 1 < points.size(); i++) {
          triangles.push_back(points[i]);
          triangles.push_back(points[i + 1]);
          triangles.push_back(c);
        }
        // (the edges of the triangle again, its edge ca maybe along a curve)
        k = -1;
      }
    }
    return fitted;
  }

  // the triangulation of a face of a boundary representation: the one
  // OpenCASCADE made of all the faces together (see _readTriangulations),
  // else its own
  bool faceTriangulation(GFace *gf, std::vector<SPoint3> &xyz,
                         std::vector<int> &tri)
  {
    xyz.clear();
    tri.clear();
#if defined(HAVE_OCC) && OCC_VERSION_HEX >= 0x070600
    if(gf->getNativeType() == GEntity::OpenCascadeModel) {
      const TopoDS_Face &s = *(const TopoDS_Face *)gf->getNativePtr();
      TopLoc_Location loc;
      Handle(Poly_Triangulation) t = BRep_Tool::Triangulation(s, loc);
      if(!t.IsNull()) {
        for(int i = 1; i <= t->NbNodes(); i++) {
          double x = t->Node(i).X(), y = t->Node(i).Y(), z = t->Node(i).Z();
          loc.Transformation().Transforms(x, y, z);
          xyz.push_back(SPoint3(x, y, z));
        }
        const bool reversed = s.Orientation() == TopAbs_REVERSED;
        for(int i = 1; i <= t->NbTriangles(); i++) {
          int a, b, c;
          t->Triangle(i).Get(a, b, c);
          tri.push_back(a - 1);
          tri.push_back((reversed ? c : b) - 1);
          tri.push_back((reversed ? b : c) - 1);
        }
        return !tri.empty();
      }
    }
#endif
    if(!gf->buildSTLTriangulation()) return false;
    xyz = gf->stl_vertices_xyz;
    tri = gf->stl_triangles;
    return !tri.empty();
  }

  // a temporary model, current while it exists (the numbering of the nodes
  // and elements of the current one is left alone); creating it hides the
  // others
  class TemporaryModel {
    int _current;
    std::vector<int> _visible;

  public:
    GModel *model;
    TemporaryModel() : _current(GModel::getCurrentIndex())
    {
      for(GModel *m : GModel::list) _visible.push_back(m->getVisibility());
      model = new GModel();
      GModel::setCurrent(model);
    }
    ~TemporaryModel()
    {
      delete model;
      GModel::setCurrentIndex(_current);
      for(std::size_t i = 0; i < GModel::list.size() && i < _visible.size();
          i++)
        GModel::list[i]->setVisibility(_visible[i]);
    }
  };

  // the points closer than close (in the L1 norm) taken as one: the index of
  // each point, the first one met kept in x
  class pointMerger {
    double _close, _step;
    std::map<std::array<long long, 3>, std::vector<int> > _cells;

  public:
    std::vector<std::array<double, 3> > x;
    pointMerger(double close) : _close(close), _step(close > 0. ? close : 1.)
    {
    }
    int operator()(const double p[3])
    {
      std::array<long long, 3> c;
      for(int k = 0; k < 3; k++) c[k] = (long long)std::floor(p[k] / _step);
      for(long long a = -1; a <= 1; a++)
        for(long long b = -1; b <= 1; b++)
          for(long long d = -1; d <= 1; d++) {
            auto g = _cells.find({{c[0] + a, c[1] + b, c[2] + d}});
            if(g == _cells.end()) continue;
            for(int n : g->second)
              if(std::abs(p[0] - x[n][0]) + std::abs(p[1] - x[n][1]) +
                   std::abs(p[2] - x[n][2]) <= _close)
                return n;
          }
      x.push_back({{p[0], p[1], p[2]}});
      _cells[c].push_back((int)x.size() - 1);
      return (int)x.size() - 1;
    }
  };
} // namespace

DiscreteCAD_Internals::DiscreteCAD_Internals() { reset(); }

void DiscreteCAD_Internals::reset()
{
  _nodes.clear();
  _vertices.clear();
  _curves.clear();
  _surfaces.clear();
  _volumes.clear();
  for(int dim = 0; dim < 4; dim++) _maxTag[dim] = 0;
  _synchronized.clear();
  _reports.clear();
  _changed = false;
}

bool DiscreteCAD_Internals::_exists(int dim, int tag) const
{
  switch(dim) {
  case 0: return _vertices.count(tag) > 0;
  case 1: return _curves.count(tag) > 0;
  case 2: return _surfaces.count(tag) > 0;
  default: return _volumes.count(tag) > 0;
  }
}

bool DiscreteCAD_Internals::_assignTag(int dim, int &tag)
{
  if(tag > 0 && _exists(dim, tag)) {
    Msg::Error("Discrete CAD %s %d already exists", entityName(dim), tag);
    return false;
  }
  GModel *model = GModel::current();
  GEO_Internals *geo = model ? model->getGEOInternals() : nullptr;
  OCC_Internals *occ = model ? model->getOCCInternals() : nullptr;
  if(tag <= 0) {
    // after the entities of the model and of the other kernels
    tag = _maxTag[dim];
    if(model) tag = std::max(tag, model->getMaxElementaryNumber(dim));
    if(geo) tag = std::max(tag, geo->getMaxTag(dim));
    if(occ) tag = std::max(tag, occ->getMaxTag(dim));
    tag++;
  }
  _maxTag[dim] = std::max(_maxTag[dim], tag);
  _changed = true;
  // the other kernels number their new entities after it
  if(geo) geo->setMaxTag(dim, std::max(geo->getMaxTag(dim), tag));
  if(occ) occ->setMaxTag(dim, tag);
  return true;
}

int DiscreteCAD_Internals::_addNode(double x, double y, double z)
{
  _nodes.push_back({{x, y, z}});
  return (int)_nodes.size() - 1;
}

int DiscreteCAD_Internals::_addVertex(int node)
{
  int tag = -1;
  _assignTag(0, tag);
  _vertices[tag] = {node};
  return tag;
}

int DiscreteCAD_Internals::_addCurve(int v0, int v1,
                                     const std::vector<int> &nodes)
{
  int tag = -1;
  _assignTag(1, tag);
  _curves[tag] = {v0, v1, nodes};
  return tag;
}

int DiscreteCAD_Internals::_addSurface(
  const std::vector<int> &curves,
  const std::vector<std::array<int, 3> > &triangles)
{
  int tag = -1;
  _assignTag(2, tag);
  _surfaces[tag] = {curves, triangles};
  return tag;
}

bool DiscreteCAD_Internals::addBox(int &tag, double x, double y, double z,
                                   double dx, double dy, double dz)
{
  if(!dx || !dy || !dz) {
    Msg::Error("Discrete CAD box with a zero extent");
    return false;
  }
  if(!_assignTag(3, tag)) return false;
  // a positive extent along each axis
  if(dx < 0.) {
    x += dx;
    dx = -dx;
  }
  if(dy < 0.) {
    y += dy;
    dy = -dy;
  }
  if(dz < 0.) {
    z += dz;
    dz = -dz;
  }
  // corner i + 2 j + 4 k at (x + i dx, y + j dy, z + k dz)
  int corner[8];
  for(int c = 0; c < 8; c++)
    corner[c] = _addVertex(
      _addNode(x + (c & 1) * dx, y + ((c >> 1) & 1) * dy, z + (c >> 2) * dz));
  // the 12 edges, from their corner of smaller index
  static const int edges[12][2] = {{0, 1}, {2, 3}, {4, 5}, {6, 7},
                                   {0, 2}, {1, 3}, {4, 6}, {5, 7},
                                   {0, 4}, {1, 5}, {2, 6}, {3, 7}};
  std::map<std::pair<int, int>, int> curveOf;
  for(auto &e : edges) {
    const int a = corner[e[0]], b = corner[e[1]];
    curveOf[{e[0], e[1]}] =
      _addCurve(a, b, {_vertices[a].node, _vertices[b].node});
  }
  // the 6 faces, their corners counterclockwise seen from outside
  static const int faces[6][4] = {{0, 4, 6, 2}, {1, 3, 7, 5}, {0, 1, 5, 4},
                                  {2, 6, 7, 3}, {0, 2, 3, 1}, {4, 5, 7, 6}};
  Volume volume;
  for(auto &f : faces) {
    std::vector<int> loop;
    for(int k = 0; k < 4; k++) {
      const int a = f[k], b = f[(k + 1) % 4];
      loop.push_back(a < b ? curveOf[{a, b}] : -curveOf[{b, a}]);
    }
    int n[4];
    for(int k = 0; k < 4; k++) n[k] = _vertices[corner[f[k]]].node;
    const int face =
      _addSurface(loop, {{{n[0], n[1], n[2]}}, {{n[0], n[2], n[3]}}});
    // along the edges from the first corner
    double eu[3], ev[3];
    for(int k = 0; k < 3; k++) {
      eu[k] = _nodes[n[1]][k] - _nodes[n[0]][k];
      ev[k] = _nodes[n[3]][k] - _nodes[n[0]][k];
    }
    normalize(eu);
    normalize(ev);
    _planarUV(face, _nodes[n[0]].data(), eu, ev);
    volume.surfaces.push_back(face);
  }
  _volumes[tag] = volume;
  return true;
}

bool DiscreteCAD_Internals::addSphere(int &tag, double xc, double yc,
                                      double zc, double radius,
                                      double tolerance)
{
  if(radius <= 0.) {
    Msg::Error("Discrete CAD sphere with a non-positive radius");
    return false;
  }
  if(!_assignTag(3, tag)) return false;
  if(tolerance <= 0.)
    tolerance = CTX::instance()->geom.discreteTolerance * radius;
  // the octants of the octahedron, n times subdivided along their edges, the
  // fewest subdivisions within the tolerance (the deviation decreases as
  // 1 / n^2)
  const int maxDivisions = 1024;
  int n = (int)std::ceil(
    std::sqrt(octantDeviation(1) * radius / tolerance) - 1.e-12);
  n = std::min(std::max(n, 1), maxDivisions);
  while(n > 1 && octantDeviation(n - 1) * radius <= tolerance) n--;
  while(n < maxDivisions && octantDeviation(n) * radius > tolerance) n++;
  if(octantDeviation(n) * radius > tolerance)
    Msg::Warning("Discrete CAD sphere: tolerance %g not reached with %d "
                 "subdivisions (%g)",
                 tolerance, n, octantDeviation(n) * radius);
  // the nodes, shared by the octants through their integer coordinates
  // (signed, zero on the planes of the octants)
  std::map<std::array<int, 3>, int> nodeOf;
  auto node = [&](int i, int j, int k) {
    const std::array<int, 3> key = {{i, j, k}};
    auto it = nodeOf.find(key);
    if(it != nodeOf.end()) return it->second;
    const double r = std::sqrt((double)(i * i + j * j + k * k));
    const int id = _addNode(xc + radius * i / r, yc + radius * j / r,
                            zc + radius * k / r);
    nodeOf[key] = id;
    return id;
  };
  // the two hemispheres, their triangles oriented outwards
  std::vector<std::array<int, 3> > north, south;
  for(int s = 0; s < 8; s++) {
    const int sx = (s & 1) ? -1 : 1, sy = (s & 2) ? -1 : 1,
              sz = (s & 4) ? -1 : 1;
    auto add = [&](int i0, int j0, int i1, int j1, int i2, int j2) {
      std::array<int, 3> t = {
        {node(sx * i0, sy * j0, sz * (n - i0 - j0)),
         node(sx * i1, sy * j1, sz * (n - i1 - j1)),
         node(sx * i2, sy * j2, sz * (n - i2 - j2))}};
      // outwards for the octant (+, +, +); a reflection of an odd number of
      // axes reverses it
      if(sx * sy * sz < 0) std::swap(t[1], t[2]);
      (sz > 0 ? north : south).push_back(t);
    };
    for(int i = 0; i < n; i++)
      for(int j = 0; i + j < n; j++) {
        add(i, j, i + 1, j, i, j + 1);
        if(i + j + 2 <= n) add(i + 1, j, i + 1, j + 1, i, j + 1);
      }
  }
  // the equator, two arcs between the vertices at -x and +x: A through +y,
  // B through -y
  const int east = _addVertex(node(n, 0, 0)), west = _addVertex(node(-n, 0, 0));
  std::vector<int> arcA, arcB;
  for(int m = 0; m <= n; m++) arcA.push_back(node(n - m, m, 0));
  for(int m = 1; m <= n; m++) arcA.push_back(node(-m, n - m, 0));
  for(int m = 0; m <= n; m++) arcB.push_back(node(-(n - m), -m, 0));
  for(int m = 1; m <= n; m++) arcB.push_back(node(m, -(n - m), 0));
  const int a = _addCurve(east, west, arcA), b = _addCurve(west, east, arcB);
  // the loops counterclockwise seen from outside
  Volume volume;
  volume.surfaces.push_back(_addSurface({a, b}, north));
  volume.surfaces.push_back(_addSurface({-b, -a}, south));
  for(int h = 0; h < 2; h++) {
    DiscreteCADAnalyticSurface &a = _surfaces[volume.surfaces[h]].analytic.surface;
    a.type = DiscreteCADAnalyticSurface::SPHERE;
    a.o[0] = xc;
    a.o[1] = yc;
    a.o[2] = zc;
    a.r1 = radius;
  }
  // the stereographic projections from the opposite poles, on the unit disk
  for(int h = 0; h < 2; h++)
    _setUV(volume.surfaces[h], [&](int n) {
      const std::array<double, 3> &x = _nodes[n];
      const double q[3] = {(x[0] - xc) / radius, (x[1] - yc) / radius,
                           (x[2] - zc) / radius};
      const double d = 1. + (h ? -q[2] : q[2]);
      return std::array<double, 2>{{q[0] / d, q[1] / d}};
    });
  _volumes[tag] = volume;
  return true;
}

std::vector<int> DiscreteCAD_Internals::_addRing(const Frame &f, double rx,
                                                double ry, double w, int n)
{
  std::vector<int> ring;
  for(int i = 0; i < n; i++) {
    const double t = 2. * pi * i / n;
    const double u = n == 1 ? 0. : rx * std::cos(t);
    const double v = n == 1 ? 0. : ry * std::sin(t);
    double p[3];
    for(int k = 0; k < 3; k++)
      p[k] = f.o[k] + u * f.e[0][k] + v * f.e[1][k] + w * f.e[2][k];
    ring.push_back(_addNode(p[0], p[1], p[2]));
  }
  return ring;
}

void DiscreteCAD_Internals::_addArcs(const std::vector<int> &ring, int &a,
                                     int &b)
{
  const std::size_t n = ring.size();
  const int v0 = _addVertex(ring[0]), v1 = _addVertex(ring[n / 2]);
  std::vector<int> first(ring.begin(), ring.begin() + n / 2 + 1);
  std::vector<int> second(ring.begin() + n / 2, ring.end());
  second.push_back(ring[0]);
  a = _addCurve(v0, v1, first);
  b = _addCurve(v1, v0, second);
}

std::vector<std::array<int, 3> >
DiscreteCAD_Internals::_fillEllipse(const Frame &f, double rx, double ry,
                                    double w, const std::vector<int> &ring)
{
  // rings about as far apart as their nodes
  std::vector<std::array<int, 3> > triangles;
  const int n = (int)ring.size();
  const int m = std::max(1, (int)std::lround(n / (2. * pi)));
  std::vector<int> outer = ring;
  for(int k = m - 1; k >= 0; k--) {
    int nk = 1;
    if(k > 0) {
      nk = (int)std::lround((double)n * k / m);
      nk = std::max(4, nk + nk % 2);
    }
    const std::vector<int> inner =
      _addRing(f, rx * k / m, ry * k / m, w, nk);
    zipHalf(outer, inner, 0, triangles);
    zipHalf(outer, inner, 1, triangles);
    outer = inner;
  }
  return triangles;
}

void DiscreteCAD_Internals::_setUV(
  int surface, const std::function<std::array<double, 2>(int)> &uvOfNode)
{
  Surface &sf = _surfaces[surface];
  sf.uv.clear();
  for(auto &t : sf.triangles)
    sf.uv.push_back({{uvOfNode(t[0]), uvOfNode(t[1]), uvOfNode(t[2])}});
}

void DiscreteCAD_Internals::_planarUV(int surface, const double o[3],
                                      const double eu[3], const double ev[3])
{
  // (its plane through one of its nodes, o being only the origin of its
  // parameters)
  DiscreteCADAnalyticSurface &a = _surfaces[surface].analytic.surface;
  a.type = DiscreteCADAnalyticSurface::PLANE;
  for(int k = 0; k < 3; k++)
    a.o[k] = _nodes[_surfaces[surface].triangles[0][0]][k];
  a.axis[0] = eu[1] * ev[2] - eu[2] * ev[1];
  a.axis[1] = eu[2] * ev[0] - eu[0] * ev[2];
  a.axis[2] = eu[0] * ev[1] - eu[1] * ev[0];
  normalize(a.axis);
  _setUV(surface, [&](int n) {
    const std::array<double, 3> &x = _nodes[n];
    const double d[3] = {x[0] - o[0], x[1] - o[1], x[2] - o[2]};
    return std::array<double, 2>{{d[0] * eu[0] + d[1] * eu[1] + d[2] * eu[2],
                                  d[0] * ev[0] + d[1] * ev[1] + d[2] * ev[2]}};
  });
}

bool DiscreteCAD_Internals::addRectangle(int &tag, double x, double y,
                                         double z, double dx, double dy)
{
  if(!dx || !dy) {
    Msg::Error("Discrete CAD rectangle with a zero extent");
    return false;
  }
  if(!_assignTag(2, tag)) return false;
  if(dx < 0.) {
    x += dx;
    dx = -dx;
  }
  if(dy < 0.) {
    y += dy;
    dy = -dy;
  }
  // counterclockwise seen from +z
  int v[4], n[4], c[4];
  for(int k = 0; k < 4; k++) {
    n[k] = _addNode(x + (k == 1 || k == 2) * dx, y + (k >= 2) * dy, z);
    v[k] = _addVertex(n[k]);
  }
  for(int k = 0; k < 4; k++)
    c[k] = _addCurve(v[k], v[(k + 1) % 4], {n[k], n[(k + 1) % 4]});
  _surfaces[tag] = {{c[0], c[1], c[2], c[3]},
                    {{{n[0], n[1], n[2]}}, {{n[0], n[2], n[3]}}}};
  const double eu[3] = {1., 0., 0.}, ev[3] = {0., 1., 0.};
  _planarUV(tag, _nodes[n[0]].data(), eu, ev);
  return true;
}

bool DiscreteCAD_Internals::addDisk(int &tag, double xc, double yc, double zc,
                                    double rx, double ry,
                                    const std::vector<double> &zAxis,
                                    const std::vector<double> &xAxis,
                                    double tolerance)
{
  if(rx <= 0. || ry <= 0.) {
    Msg::Error("Discrete CAD disk with a non-positive radius");
    return false;
  }
  if(!_assignTag(2, tag)) return false;
  const double rmin = std::min(rx, ry), rmax = std::max(rx, ry);
  if(tolerance <= 0.)
    tolerance = CTX::instance()->geom.discreteTolerance * rmax;
  const Frame f = frame(xc, yc, zc, zAxis, xAxis);
  // the chords of the ellipse are at most (2 pi rmax / n)^2 / (8 rmin^2 /
  // rmax) away from it: as those of a circle of radius rmax^3 / rmin^2
  const std::vector<int> ring = _addRing(
    f, rx, ry, 0., circleDivisions(rmax * rmax * rmax / (rmin * rmin), tolerance));
  int a, b;
  _addArcs(ring, a, b);
  _surfaces[tag] = {{a, b}, _fillEllipse(f, rx, ry, 0., ring)};
  _planarUV(tag, f.o, f.e[0], f.e[1]);
  return true;
}

bool DiscreteCAD_Internals::addCylinder(int &tag, double x, double y,
                                        double z, double dx, double dy,
                                        double dz, double r, double tolerance)
{
  if(r <= 0.) {
    Msg::Error("Discrete CAD cylinder with a non-positive radius");
    return false;
  }
  return addCone(tag, x, y, z, dx, dy, dz, r, r, tolerance);
}

bool DiscreteCAD_Internals::addCone(int &tag, double x, double y, double z,
                                    double dx, double dy, double dz, double r1,
                                    double r2, double tolerance)
{
  const double h = std::sqrt(dx * dx + dy * dy + dz * dz);
  if(!h || r1 < 0. || r2 < 0. || (!r1 && !r2)) {
    Msg::Error("Discrete CAD cone with a zero axis or invalid radii");
    return false;
  }
  if(!_assignTag(3, tag)) return false;
  const double rmax = std::max(r1, r2);
  if(tolerance <= 0.) tolerance = CTX::instance()->geom.discreteTolerance * rmax;
  const Frame f = frame(x, y, z, {dx, dy, dz}, {});
  // the rings at the ends of the lateral surface, ruled: a single band of
  // triangles between them is within the tolerance; a zero radius gives an
  // apex
  const double slant = std::sqrt(h * h + (r2 - r1) * (r2 - r1));
  const int m = 1;
  std::vector<std::vector<int> > rings(m + 1);
  for(int k = 0; k <= m; k++) {
    const double r = r1 + (r2 - r1) * k / m;
    rings[k] = _addRing(f, r, r, h * k / m, r > 0. ? circleDivisions(r, tolerance) : 1);
  }
  // the lateral surface, bounded by the circles at its ends (two arcs each)
  // and, without apex, by its seam at the angle 0, used twice; and the disks
  // at the ends. Their loops counterclockwise seen from outside
  const bool apex = !r1 || !r2;
  int a1 = 0, b1 = 0, a2 = 0, b2 = 0;
  if(r1 > 0.) _addArcs(rings[0], a1, b1);
  if(r2 > 0.) _addArcs(rings[m], a2, b2);
  std::vector<int> column;
  int seam = 0;
  if(!apex) {
    for(int k = 0; k <= m; k++) column.push_back(rings[k][0]);
    seam = _addCurve(_curves[a1].v0, _curves[a2].v0, column);
  }
  std::vector<std::array<int, 3> > triangles;
  for(int k = 0; k < m; k++)
    for(int half = 0; half < 2; half++)
      zipHalf(rings[k], rings[k + 1], half, triangles);
  std::vector<int> loop;
  if(r1 > 0.) loop.insert(loop.end(), {a1, b1});
  if(seam) loop.push_back(seam);
  if(r2 > 0.) loop.insert(loop.end(), {-b2, -a2});
  if(seam) loop.push_back(-seam);
  Volume volume;
  const int lateral = _addSurface(loop, triangles);
  volume.surfaces.push_back(lateral);
  {
    DiscreteCADAnalyticSurface &a = _surfaces[lateral].analytic.surface;
    a.type = r1 == r2 ? DiscreteCADAnalyticSurface::CYLINDER :
                        DiscreteCADAnalyticSurface::CONE;
    // (a cone from its apex, its axis towards its points)
    const double w = r1 == r2 ? 0. : -r1 * h / (r2 - r1);
    const double s = r2 >= r1 ? 1. : -1.;
    for(int k = 0; k < 3; k++) {
      a.o[k] = f.o[k] + w * f.e[2][k];
      a.axis[k] = (r1 == r2 ? 1. : s) * f.e[2][k];
    }
    a.r1 = r1 == r2 ? r1 : std::atan(std::abs(r2 - r1) / h);
  }
  // with an apex, a disk: the parameters (r / rmax) (cos(theta), sin(theta)),
  // the apex at the center as an embedded vertex
  if(apex) {
    _surfaces[lateral].embeddedVertices.push_back(
      _addVertex(r1 > 0. ? rings[m][0] : rings[0][0]));
    _setUV(lateral, [&](int n) {
      const std::array<double, 3> &x = _nodes[n];
      double c[3];
      for(int k = 0; k < 3; k++)
        c[k] = (x[0] - f.o[0]) * f.e[k][0] + (x[1] - f.o[1]) * f.e[k][1] +
               (x[2] - f.o[2]) * f.e[k][2];
      return std::array<double, 2>{{c[0] / rmax, c[1] / rmax}};
    });
  }
  // without apex, its developed parameters, an isometry: (r theta, z) for a
  // cylinder, s (cos(theta sin(beta)), sin(theta sin(beta))) for a cone, s
  // the distance to its apex and beta its half angle; the angles of the nodes
  // of a triangle across the seam from 0 to 2 pi
  else {
    std::map<int, double> angle;
    for(auto &ring : rings)
      for(std::size_t i = 0; i < ring.size(); i++)
        angle[ring[i]] = 2. * pi * i / ring.size();
    const double sinBeta = std::abs(r2 - r1) / slant;
    auto developed = [&](int n, double theta) {
      const std::array<double, 3> &x = _nodes[n];
      const double w = (x[0] - f.o[0]) * f.e[2][0] +
                       (x[1] - f.o[1]) * f.e[2][1] + (x[2] - f.o[2]) * f.e[2][2];
      if(r1 == r2) return std::array<double, 2>{{r1 * theta, w}};
      const double s = (r1 + (r2 - r1) * w / h) / sinBeta;
      return std::array<double, 2>{
        {s * std::cos(theta * sinBeta), s * std::sin(theta * sinBeta)}};
    };
    Surface &sf = _surfaces[lateral];
    for(auto &t : sf.triangles) {
      double theta[3];
      for(int k = 0; k < 3; k++) theta[k] = angle[t[k]];
      if(std::max({theta[0], theta[1], theta[2]}) -
           std::min({theta[0], theta[1], theta[2]}) > pi)
        for(int k = 0; k < 3; k++)
          if(theta[k] < pi) theta[k] += 2. * pi;
      sf.uv.push_back({{developed(t[0], theta[0]), developed(t[1], theta[1]),
                        developed(t[2], theta[2])}});
    }
    // (the seam used forwards at the angle 2 pi)
    auto &sides = sf.seams[seam];
    for(int n : column) {
      sides[0].push_back(developed(n, 2. * pi));
      sides[1].push_back(developed(n, 0.));
    }
  }
  if(r1 > 0.) {
    std::vector<std::array<int, 3> > bottom =
      _fillEllipse(f, r1, r1, 0., rings[0]);
    reverse(bottom);
    const int disk = _addSurface({-b1, -a1}, bottom);
    _planarUV(disk, f.o, f.e[0], f.e[1]);
    volume.surfaces.push_back(disk);
  }
  if(r2 > 0.) {
    const int disk =
      _addSurface({a2, b2}, _fillEllipse(f, r2, r2, h, rings[m]));
    _planarUV(disk, f.o, f.e[0], f.e[1]);
    volume.surfaces.push_back(disk);
  }
  _volumes[tag] = volume;
  return true;
}

bool DiscreteCAD_Internals::addTorus(int &tag, double x, double y, double z,
                                     double r1, double r2,
                                     const std::vector<double> &zAxis,
                                     double tolerance)
{
  if(r2 <= 0. || r1 <= r2) {
    Msg::Error("Discrete CAD torus with invalid radii (0 < r2 < r1)");
    return false;
  }
  if(!_assignTag(3, tag)) return false;
  if(tolerance <= 0.) tolerance = CTX::instance()->geom.discreteTolerance * r2;
  const Frame f = frame(x, y, z, zAxis, {});
  // the point at the angles theta (around the axis) and phi (around the
  // center circle)
  auto point = [&](double theta, double phi, double p[3]) {
    const double rho = r1 + r2 * std::cos(phi);
    const double u = rho * std::cos(theta), v = rho * std::sin(theta),
                 w = r2 * std::sin(phi);
    for(int k = 0; k < 3; k++)
      p[k] = f.o[k] + u * f.e[0][k] + v * f.e[1][k] + w * f.e[2][k];
  };
  // the distance of the centroids of the triangles of a band of quads (the
  // same at every theta) to the torus
  auto deviation = [&](int nt, int np) {
    double d = 0.;
    for(int j = 0; j < np; j++) {
      double p[4][3];
      point(0., 2. * pi * j / np, p[0]);
      point(2. * pi / nt, 2. * pi * j / np, p[1]);
      point(2. * pi / nt, 2. * pi * (j + 1) / np, p[2]);
      point(0., 2. * pi * (j + 1) / np, p[3]);
      static const int tri[2][3] = {{0, 1, 2}, {0, 2, 3}};
      for(auto &t : tri) {
        double c[3], q[3];
        for(int k = 0; k < 3; k++)
          c[k] = (p[t[0]][k] + p[t[1]][k] + p[t[2]][k]) / 3. - f.o[k];
        for(int k = 0; k < 3; k++)
          q[k] = c[0] * f.e[k][0] + c[1] * f.e[k][1] + c[2] * f.e[k][2];
        const double rho = std::sqrt(q[0] * q[0] + q[1] * q[1]);
        d = std::max(d, std::abs(std::sqrt((rho - r1) * (rho - r1) +
                                           q[2] * q[2]) - r2));
      }
    }
    return d;
  };
  int nt = circleDivisions(r1 + r2, tolerance / 2.);
  int np = circleDivisions(r2, tolerance / 2.);
  for(int pass = 0; pass < 10; pass++) {
    const double d = deviation(nt, np);
    if(d <= tolerance) break;
    const double factor = std::sqrt(d / tolerance) * 1.05;
    nt = (int)std::ceil(nt * factor);
    np = (int)std::ceil(np * factor);
    nt += nt % 2;
    np += np % 2;
  }
  std::vector<int> grid(nt * np);
  for(int i = 0; i < nt; i++)
    for(int j = 0; j < np; j++) {
      double p[3];
      point(2. * pi * i / nt, 2. * pi * j / np, p);
      grid[i * np + j] = _addNode(p[0], p[1], p[2]);
    }
  auto node = [&](int i, int j) { return grid[(i % nt) * np + j % np]; };
  // the vertices at theta in {0, pi} on the outer (phi = 0) and inner (phi =
  // pi) equators, the arcs of the equators between them
  int vertex[2][2], equator[2][2];
  for(int a = 0; a < 2; a++)
    for(int b = 0; b < 2; b++)
      vertex[a][b] = _addVertex(node(a * nt / 2, b * np / 2));
  for(int b = 0; b < 2; b++)
    for(int h = 0; h < 2; h++) {
      std::vector<int> nodes;
      for(int i = h * nt / 2; i <= (h + 1) * nt / 2; i++)
        nodes.push_back(node(i, b * np / 2));
      equator[b][h] = _addCurve(vertex[h][b], vertex[(h + 1) % 2][b], nodes);
    }
  // the two halves phi in [hp pi, (hp + 1) pi], their triangles oriented
  // outwards (d/dtheta x d/dphi), their loops counterclockwise in (theta, phi),
  // and their parameters: the angle theta and a radius exp(s), with s the
  // conformal coordinate of phi, ds = r2 dphi / (r1 + r2 cos phi) (a
  // conformal map of the half onto an annulus), its range limited to a factor
  // 4
  const double c = std::sqrt(r1 * r1 - r2 * r2);
  const double range = pi * r2 / c, maxRange = std::log(4.);
  const double lambda = range > maxRange ? maxRange / range : 1.;
  auto conformal = [&](double phi) {
    // phi in [-pi, pi]
    return std::abs(2. * r2 / c *
                    std::atan(std::sqrt((r1 - r2) / (r1 + r2)) *
                              std::tan(phi / 2.)));
  };
  Volume volume;
  for(int hp = 0; hp < 2; hp++) {
    std::vector<std::array<int, 3> > triangles;
    for(int i = 0; i < nt; i++)
      for(int j = hp * np / 2; j < (hp + 1) * np / 2; j++) {
        triangles.push_back({{node(i, j), node(i + 1, j), node(i + 1, j + 1)}});
        triangles.push_back({{node(i, j), node(i + 1, j + 1), node(i, j + 1)}});
      }
    const std::vector<int> loops = {
      equator[hp][0], equator[hp][1], -equator[(hp + 1) % 2][1],
      -equator[(hp + 1) % 2][0]};
    const int half = _addSurface(loops, triangles);
    DiscreteCADAnalyticSurface &a = _surfaces[half].analytic.surface;
    a.type = DiscreteCADAnalyticSurface::TORUS;
    for(int k = 0; k < 3; k++) {
      a.o[k] = f.o[k];
      a.axis[k] = f.e[2][k];
    }
    a.r1 = r1;
    a.r2 = r2;
    std::map<int, std::array<double, 2> > uv;
    for(int i = 0; i < nt; i++)
      for(int j = hp * np / 2; j <= (hp + 1) * np / 2; j++) {
        const double theta = 2. * pi * i / nt;
        const double phi = 2. * pi * j / np - (hp ? 2. * pi : 0.);
        const double rho = std::exp(lambda * conformal(phi));
        uv[node(i, j)] = {{rho * std::cos(theta), rho * std::sin(theta)}};
      }
    _setUV(half, [&](int n) { return uv.at(n); });
    volume.surfaces.push_back(half);
  }
  _volumes[tag] = volume;
  return true;
}

void DiscreteCAD_Internals::_removeVolume(int tag)
{
  auto vit = _volumes.find(tag);
  if(vit == _volumes.end()) return;
  std::vector<int> surfaces = vit->second.surfaces;
  surfaces.insert(surfaces.end(), vit->second.embeddedSurfaces.begin(),
                  vit->second.embeddedSurfaces.end());
  _volumes.erase(vit);
  // the entities still used
  std::set<int> usedSurfaces;
  for(auto &v : _volumes) {
    for(int s : v.second.surfaces) usedSurfaces.insert(std::abs(s));
    for(int s : v.second.embeddedSurfaces) usedSurfaces.insert(s);
  }
  for(int s : surfaces)
    if(!usedSurfaces.count(std::abs(s))) _surfaces.erase(std::abs(s));
  _removeUnused();
}

bool DiscreteCAD_Internals::_operandSurfaces(
  const std::pair<int, int> &dimTag, std::vector<int> &surfaces) const
{
  surfaces.clear();
  if(dimTag.first == 3) {
    auto it = _volumes.find(dimTag.second);
    if(it != _volumes.end()) {
      surfaces = it->second.surfaces;
      if(!it->second.embeddedSurfaces.empty())
        Msg::Warning("Discrete CAD boolean operation: the surfaces inside "
                     "volume %d left out",
                     dimTag.second);
      return true;
    }
  }
  else if(dimTag.first == 2) {
    auto it = _surfaces.find(dimTag.second);
    if(it != _surfaces.end() && !it->second.raw) {
      surfaces.push_back(dimTag.second);
      return true;
    }
  }
  Msg::Error("Discrete CAD boolean operations apply to volumes and "
             "surfaces: no discrete CAD volume or surface (%d, %d)",
             dimTag.first, dimTag.second);
  return false;
}

void DiscreteCAD_Internals::_removeOperand(const std::pair<int, int> &dimTag)
{
  if(dimTag.first == 3) {
    _removeVolume(dimTag.second);
    return;
  }
  for(auto &v : _volumes) {
    for(int s : v.second.surfaces)
      if(std::abs(s) == dimTag.second) return;
    for(int s : v.second.embeddedSurfaces)
      if(s == dimTag.second) return;
  }
  _surfaces.erase(dimTag.second);
  _removeUnused();
}

void DiscreteCAD_Internals::_removeUnused()
{
  std::set<int> usedCurves, usedVertices;
  for(auto &s : _surfaces) {
    for(int c : s.second.curves) usedCurves.insert(std::abs(c));
    for(int c : s.second.embeddedCurves) usedCurves.insert(c);
    for(int v : s.second.embeddedVertices) usedVertices.insert(v);
  }
  for(auto it = _curves.begin(); it != _curves.end();) {
    if(!usedCurves.count(it->first)) it = _curves.erase(it);
    else {
      usedVertices.insert(it->second.v0);
      usedVertices.insert(it->second.v1);
      ++it;
    }
  }
  for(auto it = _vertices.begin(); it != _vertices.end();) {
    if(!usedVertices.count(it->first)) it = _vertices.erase(it);
    else ++it;
  }
  _changed = true;
}

void DiscreteCAD_Internals::_addBooleanTopology(
  const std::vector<std::array<int, 3> > &triangles,
  const std::vector<int> &fromSurface,
  const std::vector<std::size_t> &fromTriangle, const std::map<int, int> *alias,
  std::vector<int> &surfaceOf)
{
  const std::size_t nt = triangles.size();

  // the parameters of the corners: those of the nodes of the triangle each
  // one comes from, if its surface has parameters, or interpolated along its
  // edge the corner is on (the same on both sides of the edge, whatever the
  // shape of the triangles), or else inside it
  std::vector<std::array<std::array<double, 2>, 3> > uv(nt);
  std::vector<char> hasUV(nt, 0);
  for(std::size_t i = 0; i < nt; i++) {
    const Surface &sf = _surfaces[fromSurface[i]];
    if(sf.uv.empty()) continue;
    hasUV[i] = 1;
    const std::array<int, 3> &t = sf.triangles[fromTriangle[i]];
    const std::array<std::array<double, 2>, 3> &tuv = sf.uv[fromTriangle[i]];
    double longest = 0.;
    for(int k = 0; k < 3; k++) {
      const std::array<double, 3> &x = _nodes[t[k]], &y = _nodes[t[(k + 1) % 3]];
      longest = std::max(longest, std::sqrt((y[0] - x[0]) * (y[0] - x[0]) +
                                            (y[1] - x[1]) * (y[1] - x[1]) +
                                            (y[2] - x[2]) * (y[2] - x[2])));
    }
    for(int k = 0; k < 3; k++) {
      const int n = triangles[i][k];
      const std::array<double, 3> &p = _nodes[n];
      int j = 0;
      while(j < 3 && t[j] != n) j++;
      if(j < 3) {
        uv[i][k] = tuv[j];
        continue;
      }
      // the nearest edge, its nodes in increasing order
      double nearest = 1e300, along = 0.;
      int a = 0, b = 1;
      for(int e = 0; e < 3; e++) {
        int ea = e, eb = (e + 1) % 3;
        if(t[ea] > t[eb]) std::swap(ea, eb);
        const std::array<double, 3> &x = _nodes[t[ea]], &y = _nodes[t[eb]];
        double l = 0., d2 = 0.;
        for(int m = 0; m < 3; m++) {
          l += (p[m] - x[m]) * (y[m] - x[m]);
          d2 += (y[m] - x[m]) * (y[m] - x[m]);
        }
        l = d2 ? std::min(1., std::max(0., l / d2)) : 0.;
        double d = 0.;
        for(int m = 0; m < 3; m++) {
          const double q = x[m] + l * (y[m] - x[m]) - p[m];
          d += q * q;
        }
        if(d < nearest) {
          nearest = d;
          along = l;
          a = ea;
          b = eb;
        }
      }
      if(std::sqrt(nearest) <= 1.e-9 * longest) {
        for(int m = 0; m < 2; m++)
          uv[i][k][m] = (1. - along) * tuv[a][m] + along * tuv[b][m];
        continue;
      }
      double e1[3], e2[3], d[3];
      for(int m = 0; m < 3; m++) {
        e1[m] = _nodes[t[1]][m] - _nodes[t[0]][m];
        e2[m] = _nodes[t[2]][m] - _nodes[t[0]][m];
        d[m] = p[m] - _nodes[t[0]][m];
      }
      const double a11 = e1[0] * e1[0] + e1[1] * e1[1] + e1[2] * e1[2];
      const double a12 = e1[0] * e2[0] + e1[1] * e2[1] + e1[2] * e2[2];
      const double a22 = e2[0] * e2[0] + e2[1] * e2[1] + e2[2] * e2[2];
      const double b1 = d[0] * e1[0] + d[1] * e1[1] + d[2] * e1[2];
      const double b2 = d[0] * e2[0] + d[1] * e2[1] + d[2] * e2[2];
      const double det = a11 * a22 - a12 * a12;
      const double l1 = det ? (a22 * b1 - a12 * b2) / det : 0.;
      const double l2 = det ? (a11 * b2 - a12 * b1) / det : 0.;
      for(int m = 0; m < 2; m++)
        uv[i][k][m] =
          (1. - l1 - l2) * tuv[0][m] + l1 * tuv[1][m] + l2 * tuv[2][m];
    }
  }

  // the surfaces, curves and vertices of the result: the triangles coming
  // from the same surface, connected; their creases, along the embedded
  // curves of the surfaces (between triangles coming from two triangles of a
  // surface across one of them)
  std::vector<int> label(nt);
  for(std::size_t i = 0; i < nt; i++) {
    label[i] = fromSurface[i];
    if(alias) {
      auto it = alias->find(label[i]);
      if(it != alias->end()) label[i] = it->second;
    }
  }
  std::set<std::pair<int, int> > inputCreases, creases;
  std::set<int> inputSurfaces;
  inputSurfaces.insert(fromSurface.begin(), fromSurface.end());
  for(int is : inputSurfaces) {
    for(int c : _surfaces[is].embeddedCurves) {
      const std::vector<int> &n = _curves[c].nodes;
      for(std::size_t j = 0; j + 1 < n.size(); j++)
        inputCreases.insert(std::minmax(n[j], n[j + 1]));
    }
  }
  if(!inputCreases.empty()) {
    std::map<std::pair<int, int>, std::vector<std::size_t> > edgeTriangles;
    for(std::size_t i = 0; i < nt; i++)
      for(int k = 0; k < 3; k++)
        edgeTriangles[std::minmax(triangles[i][k], triangles[i][(k + 1) % 3])]
          .push_back(i);
    for(auto &e : edgeTriangles) {
      if(e.second.size() != 2) continue;
      const std::size_t i0 = e.second[0], i1 = e.second[1];
      if(fromSurface[i0] != fromSurface[i1] ||
         fromTriangle[i0] == fromTriangle[i1])
        continue;
      const Surface &sf = _surfaces[fromSurface[i0]];
      const std::array<int, 3> &t0 = sf.triangles[fromTriangle[i0]],
                               &t1 = sf.triangles[fromTriangle[i1]];
      for(int k = 0; k < 3; k++) {
        const std::pair<int, int> edge = std::minmax(t0[k], t0[(k + 1) % 3]);
        if(!inputCreases.count(edge)) continue;
        if(std::count(t1.begin(), t1.end(), edge.first) &&
           std::count(t1.begin(), t1.end(), edge.second))
          creases.insert(e.first);
      }
    }
  }
  _addTopology(triangles, label, uv, hasUV, creases, pi, surfaceOf);
  // (the exact geometry of the surfaces they come from, or the angles they
  // were classified with)
  for(std::size_t i = 0; i < nt; i++) {
    const Surface &from = _surfaces[fromSurface[i]];
    Surface &to = _surfaces[surfaceOf[i]];
    to.analytic = from.analytic;
    to.classified = from.classified;
    to.angle = from.angle;
    to.curveAngle = from.curveAngle;
  }
}

bool DiscreteCAD_Internals::booleanOperation(
  int op, const std::vector<std::pair<int, int> > &objectDimTags,
  const std::vector<std::pair<int, int> > &toolDimTags,
  std::vector<std::pair<int, int> > &outDimTags,
  std::vector<std::vector<std::pair<int, int> > > &outDimTagsMap, int tag,
  bool removeObject, bool removeTool, double merge,
  const std::map<int, int> *alias)
{
  outDimTags.clear();
  outDimTagsMap.clear();

  // the triangulations of the volumes of each operand, oriented outwards,
  // with the input entity, surface and triangle each triangle comes from
  struct Origin {
    int input, surface;
    std::size_t triangle;
  };
  std::vector<Origin> origins;
  struct Triangulation {
    std::vector<double> xyz;
    std::vector<int> tri, origin;
  };
  std::vector<Triangulation> volumes[2];
  std::map<std::array<double, 3>, int> nodeOf;
  const std::vector<std::pair<int, int> > *operands[2] = {&objectDimTags,
                                                          &toolDimTags};
  int input = 0;
  std::vector<int> inputTag, inputOperand, inputDim;
  for(int o = 0; o < 2; o++) {
    for(auto &dt : *operands[o]) {
      inputTag.push_back(dt.second);
      inputOperand.push_back(o);
      inputDim.push_back(dt.first);
      // (the surfaces of a volume, or a surface: open, it has no inside)
      std::vector<int> surfaces;
      if(!_operandSurfaces(dt, surfaces)) return false;
      if(dt.first != (*operands[o])[0].first) {
        Msg::Error("Discrete CAD boolean operations: the %s mixes volumes "
                   "and surfaces",
                   o ? "tool" : "object");
        return false;
      }
      Triangulation v;
      std::map<int, int> local;
      for(int s : surfaces) {
        const Surface &sf = _surfaces[std::abs(s)];
        for(std::size_t i = 0; i < sf.triangles.size(); i++) {
          std::array<int, 3> t = sf.triangles[i];
          if(s < 0) std::swap(t[1], t[2]);
          for(int n : t) {
            auto it = local.find(n);
            if(it == local.end()) {
              it = local.insert({n, (int)local.size()}).first;
              v.xyz.insert(v.xyz.end(), _nodes[n].begin(), _nodes[n].end());
              nodeOf[_nodes[n]] = n;
            }
            v.tri.push_back(it->second);
          }
          v.origin.push_back((int)origins.size());
          origins.push_back({input, std::abs(s), i});
        }
      }
      volumes[o].push_back(v);
      input++;
    }
  }
  if(volumes[0].empty() || volumes[1].empty()) return false;

  // the boolean operation of two triangulations: the volumes of each operand
  // fused first (each operation then has operands without
  // self-intersections), then the operation
  std::string error;
  auto boolean = [&](int o, const Triangulation &a, const Triangulation &b,
                     Triangulation &r) {
    std::vector<int> birth;
    if(!meshBoolean(o, a.xyz, a.tri, b.xyz, b.tri, r.xyz, r.tri, birth,
                    error))
      return false;
    const std::size_t na = a.tri.size() / 3;
    r.origin.resize(birth.size());
    for(std::size_t i = 0; i < birth.size(); i++)
      r.origin[i] = (std::size_t)birth[i] < na ? a.origin[birth[i]] :
                                                 b.origin[birth[i] - na];
    return true;
  };
  Triangulation operand[2], result;
  bool ok = true;
  for(int o = 0; o < 2 && ok; o++) {
    operand[o] = volumes[o][0];
    for(std::size_t k = 1; k < volumes[o].size() && ok; k++) {
      Triangulation r;
      ok = boolean(0, operand[o], volumes[o][k], r);
      operand[o] = r;
    }
  }
  if(ok) ok = boolean(op, operand[0], operand[1], result);
  if(!ok) {
    Msg::Error("Discrete CAD boolean operation: %s", error.c_str());
    return false;
  }
  std::vector<double> rxyz = result.xyz;
  std::vector<int> rtri = result.tri, birth = result.origin;

  // the nodes of the result: those of the operands kept, new ones elsewhere
  std::vector<int> rnode(rxyz.size() / 3);
  for(std::size_t v = 0; v < rnode.size(); v++) {
    const std::array<double, 3> p = {
      {rxyz[3 * v], rxyz[3 * v + 1], rxyz[3 * v + 2]}};
    auto it = nodeOf.find(p);
    rnode[v] = it != nodeOf.end() ? it->second : _addNode(p[0], p[1], p[2]);
  }
  // the nodes closer than the rounding of the exact result merged (the oldest
  // kept): its clusters of nodes where the operands touch each other, which
  // would make the triangles of the next operations degenerate; the
  // triangles degenerate or folded onto each other then removed
  double lo[3] = {1e300, 1e300, 1e300}, hi[3] = {-1e300, -1e300, -1e300};
  for(std::size_t v = 0; v < rnode.size(); v++)
    for(int k = 0; k < 3; k++) {
      lo[k] = std::min(lo[k], rxyz[3 * v + k]);
      hi[k] = std::max(hi[k], rxyz[3 * v + k]);
    }
  const double close =
    merge * std::sqrt((hi[0] - lo[0]) * (hi[0] - lo[0]) +
                       (hi[1] - lo[1]) * (hi[1] - lo[1]) +
                       (hi[2] - lo[2]) * (hi[2] - lo[2]));
  std::map<int, int> merged;
  std::function<int(int)> representative = [&](int n) {
    auto it = merged.find(n);
    if(it == merged.end() || it->second == n) return n;
    return it->second = representative(it->second);
  };
  for(std::size_t i = 0; i < rtri.size() / 3; i++)
    for(int k = 0; k < 3; k++) {
      int a = representative(rnode[rtri[3 * i + k]]);
      int b = representative(rnode[rtri[3 * i + (k + 1) % 3]]);
      if(a == b) continue;
      const std::array<double, 3> &x = _nodes[a], &y = _nodes[b];
      if(std::abs(x[0] - y[0]) + std::abs(x[1] - y[1]) +
           std::abs(x[2] - y[2]) > close)
        continue;
      if(a > b) std::swap(a, b);
      merged[b] = a;
    }
  std::vector<std::array<int, 3> > triangles;
  std::vector<int> kept;
  std::map<std::array<int, 3>, std::size_t> sorted;
  for(std::size_t i = 0; i < birth.size(); i++) {
    std::array<int, 3> t;
    for(int k = 0; k < 3; k++) t[k] = representative(rnode[rtri[3 * i + k]]);
    if(t[0] == t[1] || t[1] == t[2] || t[2] == t[0]) continue;
    std::array<int, 3> key = t;
    std::sort(key.begin(), key.end());
    auto it = sorted.find(key);
    if(it != sorted.end()) {
      // a triangle folded onto another one: both removed if they are
      // opposite
      const std::array<int, 3> &u = triangles[it->second];
      int k = 0;
      while(u[k] != t[0]) k++;
      if(u[(k + 1) % 3] != t[1]) kept[it->second] = -1;
      continue;
    }
    sorted[key] = triangles.size();
    triangles.push_back(t);
    kept.push_back(birth[i]);
  }
  {
    std::size_t j = 0;
    for(std::size_t i = 0; i < triangles.size(); i++) {
      if(kept[i] < 0) continue;
      triangles[j] = triangles[i];
      kept[j++] = kept[i];
    }
    triangles.resize(j);
    kept.resize(j);
    birth = kept;
  }
  const std::size_t nt = birth.size();
  std::vector<int> fromSurface(nt), surfaceOf;
  std::vector<std::size_t> fromTriangle(nt);
  for(std::size_t i = 0; i < nt; i++) {
    fromSurface[i] = origins[birth[i]].surface;
    fromTriangle[i] = origins[birth[i]].triangle;
  }
  _addBooleanTopology(triangles, fromSurface, fromTriangle, alias, surfaceOf);

  // the operands removed before the volumes are created (one of them can
  // take the tag of an operand)
  if(removeObject)
    for(auto &dt : objectDimTags) _removeOperand(dt);
  if(removeTool)
    for(auto &dt : toolDimTags) _removeOperand(dt);

  // the volumes, their tags: the one given for the first, or that of the
  // only removed object they come from, or else of the only removed tool;
  // the surfaces inside them (of a surface given, inside a volume, not
  // splitting it)
  std::map<int, std::set<int> > inputsOfSurface;
  for(std::size_t i = 0; i < nt; i++)
    inputsOfSurface[surfaceOf[i]].insert(origins[birth[i]].input);
  std::vector<std::vector<int> > inside;
  const std::vector<std::vector<std::vector<int> > > cells =
    _cells(triangles, surfaceOf, &inside);
  for(std::size_t c = 0; c < cells.size(); c++) {
    const std::vector<std::vector<int> > &cell = cells[c];
    int t = (tag > 0 && outDimTags.empty()) ? tag : -1;
    std::set<int> from;
    for(int s : cell[0]) {
      const std::set<int> &in = inputsOfSurface[std::abs(s)];
      from.insert(in.begin(), in.end());
    }
    for(int o = 0; o < 2 && t < 0; o++) {
      if(!(o ? removeTool : removeObject)) continue;
      std::set<int> tags;
      for(int i : from)
        if(inputOperand[i] == o && inputDim[i] == 3)
          tags.insert(inputTag[i]);
      if(tags.size() == 1 && !_exists(3, *tags.begin())) t = *tags.begin();
    }
    if(!_assignTag(3, t)) {
      t = -1;
      _assignTag(3, t);
    }
    _volumes[t] = Volume();
    for(auto &shell : cell)
      for(int s : shell) _volumes[t].surfaces.push_back(s);
    _volumes[t].embeddedSurfaces = inside[c];
    outDimTags.push_back({3, t});
  }
  // the surfaces in no volume (of the surfaces given)
  std::set<int> inVolume;
  for(auto &v : outDimTags) {
    for(int s : _volumes[v.second].surfaces) inVolume.insert(std::abs(s));
    for(int s : _volumes[v.second].embeddedSurfaces) inVolume.insert(s);
  }
  for(int s : std::set<int>(surfaceOf.begin(), surfaceOf.end()))
    if(!inVolume.count(s)) outDimTags.push_back({2, s});

  // the resulting volumes coming from each input volume, the resulting
  // surfaces coming from each input surface
  outDimTagsMap.resize(input);
  std::map<int, int> volumeOfSurface;
  for(auto &v : outDimTags)
    if(v.first == 3)
      for(int s : _volumes[v.second].surfaces)
        volumeOfSurface[std::abs(s)] = v.second;
  std::vector<std::set<int> > from(input), fromSurfaces(input);
  for(std::size_t i = 0; i < nt; i++) {
    const int in = origins[birth[i]].input;
    if(inputDim[in] == 2) {
      fromSurfaces[in].insert(surfaceOf[i]);
      continue;
    }
    auto it = volumeOfSurface.find(surfaceOf[i]);
    if(it != volumeOfSurface.end()) from[in].insert(it->second);
  }
  for(int i = 0; i < input; i++) {
    for(int v : from[i]) outDimTagsMap[i].push_back({3, v});
    for(int s : fromSurfaces[i]) outDimTagsMap[i].push_back({2, s});
  }

  _changed = true;
  return true;
}

bool DiscreteCAD_Internals::booleanFragments(
  const std::vector<std::pair<int, int> > &objectDimTags,
  const std::vector<std::pair<int, int> > &toolDimTags,
  std::vector<std::pair<int, int> > &outDimTags,
  std::vector<std::vector<std::pair<int, int> > > &outDimTagsMap, int tag,
  bool removeObject, bool removeTool, double merge)
{
  outDimTags.clear();
  outDimTagsMap.clear();

  // the triangulations of the input volumes, oriented outwards, with the
  // surface and triangle each triangle comes from (and their bounding boxes)
  struct Triangulation {
    std::vector<double> xyz;
    std::vector<int> tri, origin;
    double lo[3], hi[3];
    // (the points of an arrangement: their index in it)
    std::vector<int> id;
  };
  auto box = [](Triangulation &t) {
    for(int k = 0; k < 3; k++) {
      t.lo[k] = 1e300;
      t.hi[k] = -1e300;
    }
    for(std::size_t v = 0; v < t.xyz.size() / 3; v++)
      for(int k = 0; k < 3; k++) {
        t.lo[k] = std::min(t.lo[k], t.xyz[3 * v + k]);
        t.hi[k] = std::max(t.hi[k], t.xyz[3 * v + k]);
      }
  };
  std::vector<std::pair<int, std::size_t> > origins;
  std::vector<int> originInput;
  std::vector<Triangulation> inputs;
  std::vector<int> inputTag;
  std::vector<bool> inputRemoved;
  // the surfaces given (open: they have no inside), apart; the position of
  // the volumes and surfaces among the entities given
  std::vector<Triangulation> sheets;
  std::vector<std::pair<int, int> > sheetDimTag;
  std::vector<bool> sheetRemoved;
  std::vector<int> inputPosition, sheetPosition;
  int positions = 0;
  std::map<std::array<double, 3>, int> nodeOf;
  for(int o = 0; o < 2; o++) {
    for(auto &dt : o ? toolDimTags : objectDimTags) {
      std::vector<int> surfaces;
      if(!_operandSurfaces(dt, surfaces)) return false;
      const bool sheet = dt.first == 2;
      Triangulation v;
      std::map<int, int> local;
      for(int s : surfaces) {
        const Surface &sf = _surfaces[std::abs(s)];
        for(std::size_t i = 0; i < sf.triangles.size(); i++) {
          std::array<int, 3> t = sf.triangles[i];
          if(s < 0) std::swap(t[1], t[2]);
          for(int n : t) {
            auto it = local.find(n);
            if(it == local.end()) {
              it = local.insert({n, (int)local.size()}).first;
              v.xyz.insert(v.xyz.end(), _nodes[n].begin(), _nodes[n].end());
              nodeOf[_nodes[n]] = n;
            }
            v.tri.push_back(it->second);
          }
          v.origin.push_back((int)origins.size());
          origins.push_back({std::abs(s), i});
          originInput.push_back(sheet ? -1 - (int)sheets.size() :
                                        (int)inputs.size());
        }
      }
      box(v);
      if(sheet) {
        sheets.push_back(v);
        sheetDimTag.push_back(dt);
        sheetRemoved.push_back(o ? removeTool : removeObject);
        sheetPosition.push_back(positions++);
        continue;
      }
      inputs.push_back(v);
      inputTag.push_back(dt.second);
      inputRemoved.push_back(o ? removeTool : removeObject);
      inputPosition.push_back(positions++);
    }
  }
  if(inputs.empty() && sheets.empty()) return false;

  std::string error;
  auto boolean = [&](int op, const Triangulation &a, const Triangulation &b,
                     Triangulation &r) {
    std::vector<int> birth;
    if(!meshBoolean(op, a.xyz, a.tri, b.xyz, b.tri, r.xyz, r.tri, birth,
                    error))
      return false;
    const std::size_t na = a.tri.size() / 3;
    r.origin.resize(birth.size());
    for(std::size_t i = 0; i < birth.size(); i++)
      r.origin[i] = (std::size_t)birth[i] < na ? a.origin[birth[i]] :
                                                 b.origin[birth[i] - na];
    box(r);
    return true;
  };
  struct Piece {
    Triangulation t;
    std::set<int> in;
  };
  // the diagonal of the bounding box of a triangulation
  auto diagonal = [](const Triangulation &t) {
    double d = 0.;
    for(int k = 0; k < 3; k++)
      if(t.hi[k] > t.lo[k]) d += (t.hi[k] - t.lo[k]) * (t.hi[k] - t.lo[k]);
    return std::sqrt(d);
  };
  // the points of triangle j of a triangulation, and the triangle sorted
  auto ids = [](pointMerger &m, const Triangulation &t, std::size_t j) {
    std::array<int, 3> n;
    for(int k = 0; k < 3; k++) n[k] = m(&t.xyz[3 * t.tri[3 * j + k]]);
    return n;
  };
  auto sortedKey = [](std::array<int, 3> n) {
    std::sort(n.begin(), n.end());
    return n;
  };
  // a triangulation of triangles of points of m (their origins in t), those
  // degenerate left out
  auto build = [&](const pointMerger &m,
                   const std::vector<std::array<int, 3> > &tri,
                   Triangulation &t) {
    std::vector<int> origin;
    std::map<int, int> local;
    t.xyz.clear();
    t.tri.clear();
    for(std::size_t j = 0; j < tri.size(); j++) {
      const std::array<int, 3> &n = tri[j];
      if(n[0] == n[1] || n[1] == n[2] || n[2] == n[0]) continue;
      for(int k = 0; k < 3; k++) {
        auto l = local.insert({n[k], (int)local.size()});
        if(l.second)
          t.xyz.insert(t.xyz.end(), m.x[n[k]].begin(), m.x[n[k]].end());
        t.tri.push_back(l.first->second);
      }
      origin.push_back(t.origin[j]);
    }
    t.origin = origin;
    box(t);
  };
  // the pieces made to agree: two operations can triangulate the part of a
  // triangle of the inputs on the boundary of two pieces differently (the
  // constrained Delaunay triangulations of the same points and edges, its
  // near ties broken otherwise): the triangles of the other piece in that
  // part, not those of its twin (nor of the union U), replaced by those of the
  // first one, turned over (connected sets of triangles of the same triangle
  // of the inputs in each piece, with the same boundary)
  auto agree = [&](std::vector<Piece> &ps, const Triangulation &u) {
    pointMerger m(merge * diagonal(u));
    std::vector<std::vector<std::array<int, 3> > > tri(ps.size());
    std::map<std::array<int, 3>, std::vector<std::size_t> > uses;
    for(std::size_t p = 0; p < ps.size(); p++)
      for(std::size_t j = 0; j < ps[p].t.tri.size() / 3; j++) {
        tri[p].push_back(ids(m, ps[p].t, j));
        uses[sortedKey(tri[p].back())].push_back(p);
      }
    std::set<std::array<int, 3> > outer;
    for(std::size_t j = 0; j < u.tri.size() / 3; j++)
      outer.insert(sortedKey(ids(m, u, j)));
    // the triangles of one piece inside U, by triangle of the inputs, piece
    std::map<int, std::map<std::size_t, std::vector<std::size_t> > > lone;
    for(std::size_t p = 0; p < ps.size(); p++)
      for(std::size_t j = 0; j < tri[p].size(); j++) {
        const std::array<int, 3> key = sortedKey(tri[p][j]);
        if(uses[key].size() == 1 && !outer.count(key))
          lone[ps[p].t.origin[j]][p].push_back(j);
      }
    struct Part {
      std::size_t piece;
      std::vector<std::size_t> triangles;
      std::set<std::pair<int, int> > boundary;
    };
    std::vector<std::set<std::size_t> > removed(ps.size());
    std::vector<std::vector<std::array<int, 3> > > added(ps.size());
    std::vector<std::vector<int> > addedOrigin(ps.size());
    std::size_t replaced = 0;
    for(auto &o : lone) {
      std::vector<Part> parts;
      for(auto &pt : o.second) {
        // (the connected sets of the triangles of a piece, across edges)
        const std::vector<std::size_t> &js = pt.second;
        std::vector<std::size_t> parent(js.size());
        for(std::size_t a = 0; a < js.size(); a++) parent[a] = a;
        std::function<std::size_t(std::size_t)> find = [&](std::size_t a) {
          return parent[a] == a ? a : parent[a] = find(parent[a]);
        };
        std::map<std::pair<int, int>, std::vector<std::size_t> > edges;
        for(std::size_t a = 0; a < js.size(); a++)
          for(int k = 0; k < 3; k++)
            edges[std::minmax(tri[pt.first][js[a]][k],
                              tri[pt.first][js[a]][(k + 1) % 3])]
              .push_back(a);
        for(auto &e : edges)
          for(std::size_t a : e.second) parent[find(a)] = find(e.second[0]);
        std::map<std::size_t, std::size_t> partOf;
        for(std::size_t a = 0; a < js.size(); a++) {
          auto it = partOf.insert({find(a), parts.size()});
          if(it.second) parts.push_back({pt.first, {}, {}});
          parts[it.first->second].triangles.push_back(js[a]);
        }
        for(auto &e : edges)
          if(e.second.size() == 1)
            parts[partOf[find(e.second[0])]].boundary.insert(e.first);
      }
      std::vector<bool> used(parts.size(), false);
      for(std::size_t a = 0; a < parts.size(); a++)
        for(std::size_t b = a + 1; b < parts.size() && !used[a]; b++) {
          if(used[b] || parts[a].piece == parts[b].piece ||
             parts[a].boundary != parts[b].boundary)
            continue;
          used[a] = used[b] = true;
          const Part &keep = parts[a], &drop = parts[b];
          for(std::size_t j : drop.triangles) removed[drop.piece].insert(j);
          for(std::size_t j : keep.triangles) {
            std::array<int, 3> n = tri[keep.piece][j];
            std::swap(n[1], n[2]);
            added[drop.piece].push_back(n);
            addedOrigin[drop.piece].push_back(o.first);
          }
          replaced += drop.triangles.size();
        }
    }
    for(std::size_t p = 0; p < ps.size(); p++) {
      if(removed[p].empty() && added[p].empty()) continue;
      std::vector<std::array<int, 3> > t;
      std::vector<int> origin;
      for(std::size_t j = 0; j < tri[p].size(); j++)
        if(!removed[p].count(j)) {
          t.push_back(tri[p][j]);
          origin.push_back(ps[p].t.origin[j]);
        }
      t.insert(t.end(), added[p].begin(), added[p].end());
      origin.insert(origin.end(), addedOrigin[p].begin(),
                    addedOrigin[p].end());
      ps[p].t.origin = origin;
      build(m, t, ps[p].t);
    }
    if(replaced)
      Msg::Debug("Discrete CAD boolean fragments: %lu triangles replaced to "
                 "make the pieces agree",
                 replaced);
  };

  // the pieces, with the inputs they are in: each input V splits the pieces
  // made of the previous ones near it, P into P n V and P - V, and adds V - U
  // (U their union, also made of the triangles of the pieces); a triangle on
  // the boundary of two pieces is cut the same way in both
  std::vector<Piece> pieces;
  Triangulation all;
  // (with the mesh arrangements: all the inputs at once, the cells of their
  // arrangement, each piece the cells inside the same inputs, by their
  // winding numbers: inputs with self-intersections, crossing or touching
  // each other)
  bool arranged = false;
  if(haveMeshArrangement() && !inputs.empty()) {
    const double t0 = TimeOfDay();
    std::vector<double> xyz;
    std::vector<int> tri, label, originOf;
    for(std::size_t i = 0; i < inputs.size(); i++) {
      const int offset = (int)(xyz.size() / 3);
      xyz.insert(xyz.end(), inputs[i].xyz.begin(), inputs[i].xyz.end());
      for(int n : inputs[i].tri) tri.push_back(offset + n);
      for(std::size_t j = 0; j < inputs[i].tri.size() / 3; j++) {
        label.push_back((int)i);
        originOf.push_back(inputs[i].origin[j]);
      }
    }
    std::vector<double> axyz;
    std::vector<int> atri, abirth;
    std::vector<std::vector<int> > sets;
    std::vector<std::array<int, 2> > sides;
    std::size_t merged = 0;
    if(!meshArrangement(xyz, tri, label, (int)inputs.size(),
                        CTX::instance()->geom.toleranceBoolean, axyz, atri,
                        abirth, sets, sides, merged, error)) {
      Msg::Error("Discrete CAD boolean fragments: %s", error.c_str());
      return false;
    }
    // the triangles of each piece (the inputs it is in) pointing out of it,
    // and those of the union of the inputs
    std::map<int, std::size_t> pieceOf;
    std::vector<std::vector<std::array<int, 3> > > pieceTri;
    std::vector<std::vector<int> > pieceOrigin;
    std::vector<std::array<int, 3> > allTri;
    std::vector<int> allOrigin;
    for(std::size_t f = 0; f < sides.size(); f++) {
      const std::array<int, 3> t = {
        {atri[3 * f], atri[3 * f + 1], atri[3 * f + 2]}};
      for(int side = 0; side < 2; side++) {
        const int s = sides[f][side];
        if(!s) continue;
        auto it = pieceOf.insert({s, pieces.size()});
        if(it.second) {
          Piece p;
          p.in.insert(sets[s].begin(), sets[s].end());
          pieces.push_back(p);
          pieceTri.push_back({});
          pieceOrigin.push_back({});
        }
        // (behind the triangle: as it is; in front: turned over)
        pieceTri[it.first->second].push_back(
          side ? std::array<int, 3>{{t[0], t[2], t[1]}} : t);
        pieceOrigin[it.first->second].push_back(originOf[abirth[f]]);
        if(!sides[f][1 - side]) {
          allTri.push_back(pieceTri[it.first->second].back());
          allOrigin.push_back(originOf[abirth[f]]);
        }
      }
    }
    auto local = [&](const std::vector<std::array<int, 3> > &ts,
                     const std::vector<int> &origin, Triangulation &t) {
      std::map<int, int> node;
      for(auto &u : ts)
        for(int n : u) {
          auto l = node.insert({n, (int)node.size()});
          if(l.second) {
            t.xyz.insert(t.xyz.end(), axyz.begin() + 3 * n,
                         axyz.begin() + 3 * n + 3);
            t.id.push_back(n);
          }
          t.tri.push_back(l.first->second);
        }
      t.origin = origin;
      box(t);
    };
    for(std::size_t p = 0; p < pieces.size(); p++)
      local(pieceTri[p], pieceOrigin[p], pieces[p].t);
    local(allTri, allOrigin, all);
    Msg::Info("Discrete CAD boolean fragments: arrangement of %lu volumes "
              "(%lu triangles) in %lu pieces (%lu triangles), %g s",
              inputs.size(), tri.size() / 3, pieces.size(), sides.size(),
              TimeOfDay() - t0);
    if(merged)
      Msg::Info("Discrete CAD boolean fragments: %lu cells thinner than %g "
                "(Geometry.ToleranceBoolean) part of their neighbors",
                merged, CTX::instance()->geom.toleranceBoolean);
    arranged = true;
  }
  if(!arranged) {
    for(std::size_t i = 0; i < inputs.size(); i++) {
      const Triangulation &v = inputs[i];
      if(pieces.empty()) {
        pieces.push_back({v, {(int)i}});
        all = v;
        continue;
      }
      double size = 0.;
      for(int k = 0; k < 3; k++)
        size = std::max(size, std::max(all.hi[k], v.hi[k]) -
                                std::min(all.lo[k], v.lo[k]));
      const double margin = 1e-9 * size;
      std::vector<Piece> next;
      bool ok = true;
      for(Piece &p : pieces) {
        bool near = true;
        for(int k = 0; k < 3; k++)
          if(p.t.lo[k] > v.hi[k] + margin || v.lo[k] > p.t.hi[k] + margin)
            near = false;
        if(!near) {
          next.push_back(p);
          continue;
        }
        Piece in, out;
        if(!boolean(1, p.t, v, in.t) || !boolean(2, p.t, v, out.t)) {
          ok = false;
          break;
        }
        in.in = p.in;
        in.in.insert((int)i);
        out.in = p.in;
        if(!in.t.tri.empty()) next.push_back(in);
        if(!out.t.tri.empty()) next.push_back(out);
      }
      // (V - U from the operations on U and V, in this order as those on P and
      // V, which cut the triangles of U the same way: the triangles of V in U u
      // V, and, turned over, those of U in U n V, and those of U on V oriented
      // the other way, in U - V, not in U u V; their points that the operations
      // round differently are one)
      Triangulation u, common, minus;
      if(ok)
        ok = boolean(0, all, v, u) && boolean(1, all, v, common) &&
             boolean(2, all, v, minus);
      if(!ok) {
        Msg::Error("Discrete CAD boolean fragments: %s", error.c_str());
        return false;
      }
      pointMerger point(merge * diagonal(u));
      auto fromV = [&](const Triangulation &t, std::size_t j) {
        return originInput[t.origin[j]] == (int)i;
      };
      std::set<std::array<int, 3> > outer;
      for(std::size_t j = 0; j < u.tri.size() / 3; j++)
        if(!fromV(u, j)) outer.insert(sortedKey(ids(point, u, j)));
      Piece rest;
      std::vector<std::array<int, 3> > restTri;
      for(std::size_t j = 0; j < u.tri.size() / 3; j++)
        if(fromV(u, j)) {
          restTri.push_back(ids(point, u, j));
          rest.t.origin.push_back(u.origin[j]);
        }
      for(const Triangulation *t : {&common, &minus})
        for(std::size_t j = 0; j < t->tri.size() / 3; j++) {
          if(fromV(*t, j)) continue;
          std::array<int, 3> n = ids(point, *t, j);
          if(outer.count(sortedKey(n))) continue;
          std::swap(n[1], n[2]);
          restTri.push_back(n);
          rest.t.origin.push_back(t->origin[j]);
        }
      build(point, restTri, rest.t);
      rest.in = {(int)i};
      if(!rest.t.tri.empty()) next.push_back(rest);
      agree(next, u);
      all = u;
      pieces = next;
    }
  }

  // the nodes of the pieces: those of the inputs kept, the others by their
  // coordinates, a point of two pieces one node (the operations giving two
  // pieces can round it differently: the points closer than the rounding of
  // the exact pieces, as in booleanOperation, are one node)
  double lo[3] = {1e300, 1e300, 1e300}, hi[3] = {-1e300, -1e300, -1e300};
  for(Piece &p : pieces)
    for(int k = 0; k < 3; k++) {
      lo[k] = std::min(lo[k], p.t.lo[k]);
      hi[k] = std::max(hi[k], p.t.hi[k]);
    }
  for(Triangulation &t : sheets)
    for(int k = 0; k < 3; k++) {
      lo[k] = std::min(lo[k], t.lo[k]);
      hi[k] = std::max(hi[k], t.hi[k]);
    }
  const double close =
    merge * std::sqrt((hi[0] - lo[0]) * (hi[0] - lo[0]) +
                       (hi[1] - lo[1]) * (hi[1] - lo[1]) +
                       (hi[2] - lo[2]) * (hi[2] - lo[2]));
  const double cell = close > 0. ? close : 1.;
  std::map<std::array<long long, 3>, std::vector<int> > grid;
  auto cellOf = [&](const std::array<double, 3> &x) {
    std::array<long long, 3> c;
    for(int k = 0; k < 3; k++) c[k] = (long long)std::floor((x[k] - lo[k]) / cell);
    return c;
  };
  for(auto &n : nodeOf) grid[cellOf(n.first)].push_back(n.second);
  auto nodeAt = [&](const std::array<double, 3> &x) {
    auto it = nodeOf.find(x);
    if(it != nodeOf.end()) return it->second;
    const std::array<long long, 3> c = cellOf(x);
    for(long long i = -1; i <= 1; i++)
      for(long long j = -1; j <= 1; j++)
        for(long long k = -1; k <= 1; k++) {
          auto g = grid.find({{c[0] + i, c[1] + j, c[2] + k}});
          if(g == grid.end()) continue;
          for(int n : g->second) {
            const std::array<double, 3> &y = _nodes[n];
            if(std::abs(x[0] - y[0]) + std::abs(x[1] - y[1]) +
                 std::abs(x[2] - y[2]) <= close)
              return n;
          }
        }
    const int n = _addNode(x[0], x[1], x[2]);
    nodeOf[x] = n;
    grid[c].push_back(n);
    return n;
  };
  // (the points of an arrangement are those of one triangulation: one node
  // each, those of the inputs their nodes, whatever their coordinates once
  // rounded)
  std::map<int, int> arrangementNode;
  const int nodesBefore = (int)_nodes.size();
  auto nodeOfPoint = [&](const Triangulation &t, std::size_t v) {
    const std::array<double, 3> x = {
      {t.xyz[3 * v], t.xyz[3 * v + 1], t.xyz[3 * v + 2]}};
    if(t.id.empty()) return nodeAt(x);
    auto it = arrangementNode.find(t.id[v]);
    if(it != arrangementNode.end()) return it->second;
    auto in = nodeOf.find(x);
    int n;
    if(in != nodeOf.end() && in->second < nodesBefore)
      n = in->second;
    else {
      // (found by the surfaces given with the volumes, cut afterwards)
      n = _addNode(x[0], x[1], x[2]);
      nodeOf[x] = n;
      grid[cellOf(x)].push_back(n);
    }
    arrangementNode[t.id[v]] = n;
    return n;
  };
  std::vector<std::array<int, 3> > tri;
  std::vector<int> triOrigin;
  std::vector<std::size_t> triPiece;
  for(std::size_t p = 0; p < pieces.size(); p++) {
    const Triangulation &t = pieces[p].t;
    std::vector<int> node(t.xyz.size() / 3);
    for(std::size_t v = 0; v < node.size(); v++) node[v] = nodeOfPoint(t, v);
    for(std::size_t i = 0; i < t.tri.size() / 3; i++) {
      tri.push_back({{node[t.tri[3 * i]], node[t.tri[3 * i + 1]],
                      node[t.tri[3 * i + 2]]}});
      triOrigin.push_back(t.origin[i]);
      triPiece.push_back(p);
    }
  }
  // the nodes of an edge closer than the rounding merged, as in
  // booleanOperation
  std::map<int, int> merged;
  std::function<int(int)> representative = [&](int n) {
    auto it = merged.find(n);
    if(it == merged.end() || it->second == n) return n;
    return it->second = representative(it->second);
  };
  for(auto &t : tri)
    for(int k = 0; k < 3 && !arranged; k++) {
      int a = representative(t[k]), b = representative(t[(k + 1) % 3]);
      if(a == b) continue;
      const std::array<double, 3> &x = _nodes[a], &y = _nodes[b];
      if(std::abs(x[0] - y[0]) + std::abs(x[1] - y[1]) +
           std::abs(x[2] - y[2]) > close)
        continue;
      if(a > b) std::swap(a, b);
      merged[b] = a;
    }
  // the triangles, each one once, oriented as the triangle of the input it
  // comes from (outwards of its input), with the piece behind it (in the
  // input) and the one in front of it, if any: the piece of a triangle is in
  // the input it comes from if it points out of the input, the triangles of
  // two pieces oriented both ways
  std::vector<std::array<int, 3> > triangles;
  std::vector<int> birth;
  std::vector<std::array<int, 2> > sides;
  std::map<std::array<int, 3>, std::size_t> sorted;
  std::size_t conflicts = 0;
  for(std::size_t i = 0; i < tri.size(); i++) {
    std::array<int, 3> t;
    for(int k = 0; k < 3; k++) t[k] = representative(tri[i][k]);
    if(t[0] == t[1] || t[1] == t[2] || t[2] == t[0]) continue;
    std::array<int, 3> key = t;
    std::sort(key.begin(), key.end());
    auto it = sorted.find(key);
    int side;
    if(it == sorted.end()) {
      side = pieces[triPiece[i]].in.count(originInput[triOrigin[i]]) ? 0 : 1;
      if(side) std::swap(t[1], t[2]);
      it = sorted.insert({key, triangles.size()}).first;
      triangles.push_back(t);
      birth.push_back(triOrigin[i]);
      sides.push_back({{-1, -1}});
    }
    else {
      const std::array<int, 3> &u = triangles[it->second];
      int k = 0;
      while(u[k] != t[0]) k++;
      side = u[(k + 1) % 3] == t[1] ? 0 : 1;
    }
    int &s = sides[it->second][side];
    if(s >= 0 && s != (int)triPiece[i]) conflicts++;
    s = (int)triPiece[i];
  }
  const std::size_t nt = triangles.size();
  // (the triangles of one piece are those of the union of the inputs, the
  // others those of two pieces)
  std::set<std::array<int, 3> > outer;
  for(std::size_t i = 0; i < all.tri.size() / 3; i++) {
    std::array<int, 3> t;
    for(int k = 0; k < 3; k++)
      t[k] = representative(nodeOfPoint(all, all.tri[3 * i + k]));
    std::sort(t.begin(), t.end());
    outer.insert(t);
  }
  std::size_t single = 0;
  for(std::size_t i = 0; i < nt; i++) {
    if(sides[i][0] >= 0 && sides[i][1] >= 0) continue;
    std::array<int, 3> t = triangles[i];
    std::sort(t.begin(), t.end());
    if(!outer.count(t)) single++;
  }
  if(single || conflicts) {
    Msg::Error("Discrete CAD boolean fragments: the pieces do not match "
               "(%lu triangles of one piece inside the inputs, %lu triangles "
               "on the same side of two pieces)",
               single, conflicts);
    return false;
  }

  // the surfaces given, one after the other, cut by the triangles so far
  // (of the pieces, and of the surfaces before) and cutting them: their
  // co-refinement, the triangles of the surface on those so far left out;
  // the pieces on the two sides of the triangles of the pieces, none for
  // those of the surfaces (the surface given they come from in sheetOf)
  std::vector<int> sheetOf(triangles.size(), -1);
  for(std::size_t k = 0; k < sheets.size(); k++) {
    const Triangulation &b = sheets[k];
    Triangulation a;
    std::map<int, int> local;
    for(auto &t : triangles)
      for(int n : t) {
        auto l = local.insert({n, (int)local.size()});
        if(l.second)
          a.xyz.insert(a.xyz.end(), _nodes[n].begin(), _nodes[n].end());
        a.tri.push_back(l.first->second);
      }
    std::vector<double> rxyz = b.xyz;
    std::vector<int> rtri = b.tri, rbirth;
    for(std::size_t i = 0; i < b.tri.size() / 3; i++) rbirth.push_back((int)i);
    if(!triangles.empty() && !meshBoolean(3, a.xyz, a.tri, b.xyz, b.tri, rxyz,
                                          rtri, rbirth, error)) {
      Msg::Error("Discrete CAD boolean fragments: %s", error.c_str());
      return false;
    }
    const std::size_t na = triangles.size();
    std::vector<int> node(rxyz.size() / 3);
    for(std::size_t v = 0; v < node.size(); v++)
      node[v] = nodeAt({{rxyz[3 * v], rxyz[3 * v + 1], rxyz[3 * v + 2]}});
    std::vector<std::array<int, 3> > t2;
    std::vector<int> birth2, sheetOf2;
    std::vector<std::array<int, 2> > sides2;
    for(std::size_t i = 0; i < rbirth.size(); i++) {
      const std::array<int, 3> t = {
        {node[rtri[3 * i]], node[rtri[3 * i + 1]], node[rtri[3 * i + 2]]}};
      if(t[0] == t[1] || t[1] == t[2] || t[2] == t[0]) continue;
      t2.push_back(t);
      const std::size_t from = rbirth[i];
      if(from < na) {
        birth2.push_back(birth[from]);
        sides2.push_back(sides[from]);
        sheetOf2.push_back(sheetOf[from]);
      }
      else {
        birth2.push_back(b.origin[from - na]);
        sides2.push_back({{-1, -1}});
        sheetOf2.push_back((int)k);
      }
    }
    triangles = t2;
    birth = birth2;
    sides = sides2;
    sheetOf = sheetOf2;
  }
  const std::size_t nf = triangles.size();

  std::vector<int> fromSurface(nf), surfaceOf;
  std::vector<std::size_t> fromTriangle(nf);
  for(std::size_t i = 0; i < nf; i++) {
    fromSurface[i] = origins[birth[i]].first;
    fromTriangle[i] = origins[birth[i]].second;
  }
  _addBooleanTopology(triangles, fromSurface, fromTriangle, nullptr,
                      surfaceOf);

  // the inputs removed before the volumes are created (one of them can take
  // the tag of an input)
  for(std::size_t i = 0; i < inputs.size(); i++)
    if(inputRemoved[i]) _removeVolume(inputTag[i]);
  for(std::size_t k = 0; k < sheets.size(); k++)
    if(sheetRemoved[k]) _removeOperand(sheetDimTag[k]);

  // the volumes: the cells of each piece, found from the triangles of its
  // boundary only, turned to point out of it (the pieces on the two sides of
  // the triangles known, the triangles around the edges where pieces meet,
  // some of them without area, are not sorted); their tags: the one given
  // for the first, or that of the only removed input they are in, or else of
  // the last removed input they are in, if it is free
  // (the triangles of the surfaces given with them, as they are oriented:
  // on the boundary of the cells of a piece where they split it, inside one
  // otherwise)
  std::vector<std::vector<std::size_t> > boundaryOf(pieces.size());
  std::vector<std::size_t> ofSheets;
  for(std::size_t i = 0; i < nf; i++) {
    for(int side = 0; side < 2; side++)
      if(sides[i][side] >= 0) boundaryOf[sides[i][side]].push_back(2 * i + side);
    if(sheetOf[i] >= 0) ofSheets.push_back(i);
  }
  std::vector<std::pair<std::vector<std::vector<int> >, int> > cells;
  std::vector<std::vector<int> > cellInside;
  for(std::size_t p = 0; p < pieces.size(); p++) {
    std::vector<std::array<int, 3> > tri;
    std::vector<int> surf;
    std::map<int, int> sign;
    for(std::size_t s : boundaryOf[p]) {
      std::array<int, 3> t = triangles[s / 2];
      if(s % 2) std::swap(t[1], t[2]);
      tri.push_back(t);
      surf.push_back(surfaceOf[s / 2]);
      sign[surfaceOf[s / 2]] = s % 2 ? -1 : 1;
    }
    for(std::size_t i : ofSheets) {
      tri.push_back(triangles[i]);
      surf.push_back(surfaceOf[i]);
    }
    std::vector<std::vector<int> > inside;
    std::vector<std::vector<std::vector<int> > > cs = _cells(tri, surf, &inside);
    for(std::size_t c = 0; c < cs.size(); c++) {
      for(auto &shell : cs[c])
        for(int &s : shell) {
          auto it = sign.find(std::abs(s));
          if(it != sign.end()) s *= it->second;
        }
      cells.push_back({cs[c], (int)p});
      cellInside.push_back(inside[c]);
    }
  }
  std::vector<int> tagOf(cells.size(), -1);
  std::set<int> taken;
  if(tag > 0 && !cells.empty()) {
    tagOf[0] = tag;
    taken.insert(tag);
  }
  for(int pass = 0; pass < 2; pass++)
    for(std::size_t c = 0; c < cells.size(); c++) {
      const std::set<int> &in = pieces[cells[c].second].in;
      if(tagOf[c] > 0 || (pass == 0 && in.size() != 1)) continue;
      for(auto it = in.rbegin(); it != in.rend(); ++it) {
        const int t = inputTag[*it];
        if(inputRemoved[*it] && !_exists(3, t) && !taken.count(t)) {
          tagOf[c] = t;
          taken.insert(t);
          break;
        }
      }
    }
  outDimTagsMap.resize(positions);
  for(std::size_t c = 0; c < cells.size(); c++) {
    const std::vector<std::vector<int> > &cell = cells[c].first;
    const std::set<int> &in = pieces[cells[c].second].in;
    int t = tagOf[c];
    if(!_assignTag(3, t)) {
      t = -1;
      _assignTag(3, t);
    }
    _volumes[t] = Volume();
    for(auto &shell : cell)
      for(int sf : shell) _volumes[t].surfaces.push_back(sf);
    _volumes[t].embeddedSurfaces = cellInside[c];
    outDimTags.push_back({3, t});
    for(int i : in) outDimTagsMap[inputPosition[i]].push_back({3, t});
  }
  // the surfaces of the surfaces given: in no volume, the surfaces of the
  // result; all of them, the surfaces coming from each one
  std::set<int> inVolume;
  for(auto &v : outDimTags) {
    for(int s : _volumes[v.second].surfaces) inVolume.insert(std::abs(s));
    for(int s : _volumes[v.second].embeddedSurfaces) inVolume.insert(s);
  }
  std::vector<std::set<int> > ofSheet(sheets.size());
  for(std::size_t i : ofSheets) ofSheet[sheetOf[i]].insert(surfaceOf[i]);
  std::set<int> free;
  for(std::size_t k = 0; k < sheets.size(); k++)
    for(int s : ofSheet[k]) {
      outDimTagsMap[sheetPosition[k]].push_back({2, s});
      if(!inVolume.count(s)) free.insert(s);
    }
  for(int s : free) outDimTags.push_back({2, s});

  _changed = true;
  return true;
}

bool DiscreteCAD_Internals::_detach(
  const std::vector<std::pair<int, int> > &dimTags, bool all,
  std::set<int> entities[4], std::map<int, int> copyOf[4],
  std::set<int> &nodes)
{
  for(int d = 0; d < 4; d++) {
    entities[d].clear();
    copyOf[d].clear();
  }
  nodes.clear();
  // the entities and their boundaries
  for(auto &dt : dimTags) {
    if(dt.first < 0 || dt.first > 3 || !_exists(dt.first, dt.second)) {
      Msg::Error("Unknown discrete CAD entity (%d, %d)", dt.first, dt.second);
      return false;
    }
    entities[dt.first].insert(dt.second);
  }
  for(int v : entities[3]) {
    for(int s : _volumes[v].surfaces) entities[2].insert(std::abs(s));
    for(int s : _volumes[v].embeddedSurfaces) entities[2].insert(s);
  }
  for(int s : entities[2]) {
    const Surface &sf = _surfaces[s];
    for(int c : sf.curves) entities[1].insert(std::abs(c));
    for(int c : sf.embeddedCurves) entities[1].insert(c);
    for(int v : sf.embeddedVertices) entities[0].insert(v);
  }
  for(int c : entities[1]) {
    entities[0].insert(_curves[c].v0);
    entities[0].insert(_curves[c].v1);
  }

  // those that other entities use, with the entities of their boundaries
  // (that they keep)
  std::set<int> shared[4];
  if(all) {
    for(int d = 0; d < 4; d++) shared[d] = entities[d];
  }
  else {
    for(auto &v : _volumes) {
      if(entities[3].count(v.first)) continue;
      for(int s : v.second.surfaces)
        if(entities[2].count(std::abs(s))) shared[2].insert(std::abs(s));
      for(int s : v.second.embeddedSurfaces)
        if(entities[2].count(s)) shared[2].insert(s);
    }
    for(auto &s : _surfaces) {
      if(entities[2].count(s.first) && !shared[2].count(s.first)) continue;
      for(int c : s.second.curves)
        if(entities[1].count(std::abs(c))) shared[1].insert(std::abs(c));
      for(int c : s.second.embeddedCurves)
        if(entities[1].count(c)) shared[1].insert(c);
      for(int v : s.second.embeddedVertices)
        if(entities[0].count(v)) shared[0].insert(v);
    }
    for(auto &c : _curves) {
      if(entities[1].count(c.first) && !shared[1].count(c.first)) continue;
      if(entities[0].count(c.second.v0)) shared[0].insert(c.second.v0);
      if(entities[0].count(c.second.v1)) shared[0].insert(c.second.v1);
    }
  }

  // their copies, in their place
  for(int d = 0; d < 4; d++)
    for(int e : shared[d]) {
      int t = -1;
      _assignTag(d, t);
      copyOf[d][e] = t;
      entities[d].erase(e);
      entities[d].insert(t);
      if(d == 0) {
        const Vertex v = _vertices[e];
        _vertices[t] = v;
      }
      else if(d == 1) {
        const Curve c = _curves[e];
        _curves[t] = c;
      }
      else if(d == 2) {
        const Surface s = _surfaces[e];
        _surfaces[t] = s;
      }
      else {
        const Volume v = _volumes[e];
        _volumes[t] = v;
      }
    }
  auto renamed = [&](int d, int e) {
    auto it = copyOf[d].find(std::abs(e));
    return it == copyOf[d].end() ? e : (e > 0 ? it->second : -it->second);
  };
  for(int v : entities[3]) {
    for(int &s : _volumes[v].surfaces) s = renamed(2, s);
    for(int &s : _volumes[v].embeddedSurfaces) s = renamed(2, s);
  }
  for(int s : entities[2]) {
    Surface &sf = _surfaces[s];
    for(int &c : sf.curves) c = renamed(1, c);
    for(int &c : sf.embeddedCurves) c = renamed(1, c);
    for(int &v : sf.embeddedVertices) v = renamed(0, v);
    std::map<int, std::array<std::vector<std::array<double, 2> >, 2> > seams;
    for(auto &sm : sf.seams) seams[renamed(1, sm.first)] = sm.second;
    sf.seams = seams;
  }
  for(int c : entities[1]) {
    _curves[c].v0 = renamed(0, _curves[c].v0);
    _curves[c].v1 = renamed(0, _curves[c].v1);
  }

  // their nodes, those of other entities copied
  std::set<int> outside;
  for(auto &v : _vertices)
    if(!entities[0].count(v.first)) outside.insert(v.second.node);
  for(auto &c : _curves)
    if(!entities[1].count(c.first))
      outside.insert(c.second.nodes.begin(), c.second.nodes.end());
  for(auto &s : _surfaces)
    if(!entities[2].count(s.first))
      for(auto &t : s.second.triangles) outside.insert(t.begin(), t.end());
  std::map<int, int> copied;
  auto own = [&](int &n) {
    if(outside.count(n)) {
      auto it = copied.find(n);
      if(it == copied.end()) {
        const std::array<double, 3> x = _nodes[n];
        it = copied.insert({n, _addNode(x[0], x[1], x[2])}).first;
      }
      n = it->second;
    }
    nodes.insert(n);
  };
  for(int v : entities[0]) own(_vertices[v].node);
  for(int c : entities[1])
    for(int &n : _curves[c].nodes) own(n);
  for(int s : entities[2])
    for(auto &t : _surfaces[s].triangles)
      for(int &n : t) own(n);
  _changed = true;
  return true;
}

// the analytic surface of a surface, its parameters and the orientation of
// its triangles after the affine map x -> A x + b: a similarity of ratio s (A
// / s orthogonal) keeps its map (the parameters of planes and developed
// cylinders and cones are lengths, multiplied by s), another map (s = 0)
// leaves its triangulation as its geometry; its triangles turned over, with
// its curves and seams, if the map reverses the orientation
static void transformSurface(DiscreteCAD_Internals::Surface &sf,
                             const double A[3][3], const double b[3],
                             double s, bool reverse)
{
  DiscreteCADAnalyticMap &m = sf.analytic;
  if(s > 0.) {
    auto vector = [&](double x[3]) {
      double y[3];
      for(int i = 0; i < 3; i++)
        y[i] = (A[i][0] * x[0] + A[i][1] * x[1] + A[i][2] * x[2]) / s;
      for(int i = 0; i < 3; i++) x[i] = y[i];
    };
    DiscreteCADAnalyticSurface &a = m.surface;
    double o[3];
    for(int i = 0; i < 3; i++)
      o[i] = A[i][0] * a.o[0] + A[i][1] * a.o[1] + A[i][2] * a.o[2] + b[i];
    for(int i = 0; i < 3; i++) a.o[i] = o[i];
    vector(a.axis);
    // (the half angle of a cone)
    if(a.type != DiscreteCADAnalyticSurface::CONE) a.r1 *= s;
    a.r2 *= s;
    vector(m.e0);
    vector(m.e1);
    vector(m.d);
    if(m.kind == DiscreteCADAnalyticMap::DISK) m.scale *= s;
    if(m.kind == DiscreteCADAnalyticMap::PLANE ||
       m.kind == DiscreteCADAnalyticMap::DEVELOPED) {
      for(auto &t : sf.uv)
        for(auto &p : t)
          for(int k = 0; k < 2; k++) p[k] *= s;
      for(auto &sm : sf.seams)
        for(int side = 0; side < 2; side++)
          for(auto &p : sm.second[side])
            for(int k = 0; k < 2; k++) p[k] *= s;
    }
  }
  else
    m = DiscreteCADAnalyticMap();
  if(!reverse) return;
  for(std::size_t i = 0; i < sf.triangles.size(); i++) {
    std::swap(sf.triangles[i][1], sf.triangles[i][2]);
    if(i < sf.uv.size()) std::swap(sf.uv[i][1], sf.uv[i][2]);
  }
  for(int &c : sf.curves) c = -c;
  for(auto &sm : sf.seams) std::swap(sm.second[0], sm.second[1]);
}

bool DiscreteCAD_Internals::affineTransform(
  const std::vector<std::pair<int, int> > &dimTags,
  const std::vector<double> &matrix)
{
  if(matrix.size() != 12 && matrix.size() != 16) {
    Msg::Error("Discrete CAD affine transform: 12 or 16 values expected, %lu "
               "given",
               matrix.size());
    return false;
  }
  double A[3][3], b[3];
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) A[i][j] = matrix[4 * i + j];
    b[i] = matrix[4 * i + 3];
  }
  const double det = A[0][0] * (A[1][1] * A[2][2] - A[1][2] * A[2][1]) -
                     A[0][1] * (A[1][0] * A[2][2] - A[1][2] * A[2][0]) +
                     A[0][2] * (A[1][0] * A[2][1] - A[1][1] * A[2][0]);
  if(!det || !std::isfinite(det)) {
    Msg::Error("Discrete CAD affine transform: singular matrix");
    return false;
  }
  // a similarity: A^T A = s^2 I
  double s = std::cbrt(std::abs(det));
  for(int i = 0; i < 3 && s; i++)
    for(int j = 0; j < 3; j++) {
      const double p =
        A[0][i] * A[0][j] + A[1][i] * A[1][j] + A[2][i] * A[2][j];
      if(std::abs(p - (i == j ? s * s : 0.)) > 1e-12 * s * s) s = 0.;
    }
  std::set<int> entities[4], nodes;
  std::map<int, int> copyOf[4];
  if(!_detach(dimTags, false, entities, copyOf, nodes)) return false;
  for(int n : nodes) {
    const std::array<double, 3> x = _nodes[n];
    for(int i = 0; i < 3; i++)
      _nodes[n][i] = A[i][0] * x[0] + A[i][1] * x[1] + A[i][2] * x[2] + b[i];
  }
  for(int t : entities[2]) transformSurface(_surfaces[t], A, b, s, det < 0.);
  return true;
}

bool DiscreteCAD_Internals::translate(
  const std::vector<std::pair<int, int> > &dimTags, double dx, double dy,
  double dz)
{
  return affineTransform(dimTags, {1., 0., 0., dx, 0., 1., 0., dy, 0., 0., 1.,
                                   dz});
}

bool DiscreteCAD_Internals::rotate(
  const std::vector<std::pair<int, int> > &dimTags, double x, double y,
  double z, double ax, double ay, double az, double angle)
{
  const double l = std::sqrt(ax * ax + ay * ay + az * az);
  if(!l) {
    Msg::Error("Discrete CAD rotation around a zero axis");
    return false;
  }
  const double k[3] = {ax / l, ay / l, az / l}, p[3] = {x, y, z};
  const double c = std::cos(angle), s = std::sin(angle);
  // (Rodrigues' formula)
  const double R[3][3] = {
    {c + (1 - c) * k[0] * k[0], (1 - c) * k[0] * k[1] - s * k[2],
     (1 - c) * k[0] * k[2] + s * k[1]},
    {(1 - c) * k[1] * k[0] + s * k[2], c + (1 - c) * k[1] * k[1],
     (1 - c) * k[1] * k[2] - s * k[0]},
    {(1 - c) * k[2] * k[0] - s * k[1], (1 - c) * k[2] * k[1] + s * k[0],
     c + (1 - c) * k[2] * k[2]}};
  std::vector<double> m(12);
  for(int i = 0; i < 3; i++) {
    m[4 * i + 3] = p[i];
    for(int j = 0; j < 3; j++) {
      m[4 * i + j] = R[i][j];
      m[4 * i + 3] -= R[i][j] * p[j];
    }
  }
  return affineTransform(dimTags, m);
}

bool DiscreteCAD_Internals::dilate(
  const std::vector<std::pair<int, int> > &dimTags, double x, double y,
  double z, double a, double b, double c)
{
  return affineTransform(dimTags, {a, 0., 0., (1 - a) * x, 0., b, 0.,
                                   (1 - b) * y, 0., 0., c, (1 - c) * z});
}

bool DiscreteCAD_Internals::symmetry(
  const std::vector<std::pair<int, int> > &dimTags, double a, double b,
  double c, double d)
{
  const double n[3] = {a, b, c}, l = a * a + b * b + c * c;
  if(!l) {
    Msg::Error("Discrete CAD symmetry with respect to no plane");
    return false;
  }
  std::vector<double> m(12);
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) m[4 * i + j] = (i == j) - 2. * n[i] * n[j] / l;
    m[4 * i + 3] = -2. * d * n[i] / l;
  }
  return affineTransform(dimTags, m);
}

bool DiscreteCAD_Internals::copy(
  const std::vector<std::pair<int, int> > &dimTags,
  std::vector<std::pair<int, int> > &outDimTags)
{
  outDimTags.clear();
  std::set<int> entities[4], nodes;
  std::map<int, int> copyOf[4];
  if(!_detach(dimTags, true, entities, copyOf, nodes)) return false;
  for(auto &dt : dimTags)
    outDimTags.push_back({dt.first, copyOf[dt.first][dt.second]});
  return true;
}

void DiscreteCAD_Internals::remove(
  const std::vector<std::pair<int, int> > &dimTags, bool recursive)
{
  std::set<int> removed[4], given[4];
  for(auto &dt : dimTags) {
    if(dt.first < 0 || dt.first > 3 || !_exists(dt.first, dt.second)) {
      Msg::Warning("Unknown discrete CAD entity (%d, %d)", dt.first,
                   dt.second);
      continue;
    }
    removed[dt.first].insert(dt.second);
    given[dt.first].insert(dt.second);
  }
  if(recursive) {
    for(int v : removed[3]) {
      for(int s : _volumes[v].surfaces) removed[2].insert(std::abs(s));
      for(int s : _volumes[v].embeddedSurfaces) removed[2].insert(s);
    }
    for(int s : removed[2]) {
      const Surface &sf = _surfaces[s];
      for(int c : sf.curves) removed[1].insert(std::abs(c));
      for(int c : sf.embeddedCurves) removed[1].insert(c);
      for(int v : sf.embeddedVertices) removed[0].insert(v);
    }
    for(int c : removed[1]) {
      removed[0].insert(_curves[c].v0);
      removed[0].insert(_curves[c].v1);
    }
  }
  // not those used by entities left
  std::set<int> used[3];
  for(auto &v : _volumes)
    if(!removed[3].count(v.first)) {
      for(int s : v.second.surfaces) used[2].insert(std::abs(s));
      for(int s : v.second.embeddedSurfaces) used[2].insert(s);
    }
  for(int s : used[2]) removed[2].erase(s);
  for(auto &s : _surfaces) {
    if(removed[2].count(s.first)) continue;
    for(int c : s.second.curves) used[1].insert(std::abs(c));
    for(int c : s.second.embeddedCurves) used[1].insert(c);
    for(int v : s.second.embeddedVertices) used[0].insert(v);
  }
  for(int c : used[1]) removed[1].erase(c);
  for(auto &c : _curves) {
    if(removed[1].count(c.first)) continue;
    used[0].insert(c.second.v0);
    used[0].insert(c.second.v1);
  }
  for(int v : used[0]) removed[0].erase(v);
  for(int d = 0; d < 3; d++)
    for(int e : given[d])
      if(!removed[d].count(e))
        Msg::Warning("Discrete CAD %s %d used by other entities: not removed",
                     entityName(d), e);
  for(int e : removed[3]) _volumes.erase(e);
  for(int e : removed[2]) _surfaces.erase(e);
  for(int e : removed[1]) _curves.erase(e);
  for(int e : removed[0]) _vertices.erase(e);
  _changed = true;
}

void DiscreteCAD_Internals::_addTopology(
  const std::vector<std::array<int, 3> > &triangles,
  const std::vector<int> &label,
  std::vector<std::array<std::array<double, 2>, 3> > &uv,
  const std::vector<char> &hasUV,
  const std::set<std::pair<int, int> > &creases, double curveAngle,
  std::vector<int> &surfaceOf)
{
  const std::size_t nt = triangles.size();

  // the surfaces: the triangles of the same label, connected
  std::map<std::pair<int, int>, std::vector<std::size_t> > edgeTriangles;
  for(std::size_t i = 0; i < nt; i++)
    for(int k = 0; k < 3; k++)
      edgeTriangles[std::minmax(triangles[i][k], triangles[i][(k + 1) % 3])]
        .push_back(i);
  std::vector<std::size_t> parent(nt);
  for(std::size_t i = 0; i < nt; i++) parent[i] = i;
  std::function<std::size_t(std::size_t)> find = [&](std::size_t i) {
    while(parent[i] != i) i = parent[i] = parent[parent[i]];
    return i;
  };
  for(auto &e : edgeTriangles)
    if(e.second.size() == 2 && label[e.second[0]] == label[e.second[1]])
      parent[find(e.second[0])] = find(e.second[1]);
  std::map<std::size_t, int> surfaceOfRoot;
  surfaceOf.assign(nt, 0);
  for(std::size_t i = 0; i < nt; i++) {
    const std::size_t r = find(i);
    auto it = surfaceOfRoot.find(r);
    if(it == surfaceOfRoot.end()) {
      int t = -1;
      _assignTag(2, t);
      _surfaces[t] = Surface();
      it = surfaceOfRoot.insert({r, t}).first;
    }
    surfaceOf[i] = it->second;
    _surfaces[it->second].triangles.push_back(triangles[i]);
  }

  // the edges of the curves: between different surfaces, or where the
  // parameters of a surface jump (its seam)
  auto cornerUV = [&](std::size_t i, int n) {
    int k = 0;
    while(k < 2 && triangles[i][k] != n) k++;
    return uv[i][k];
  };
  auto jumps = [&](std::size_t i, std::size_t j, int a, int b) {
    if(!hasUV[i] || !hasUV[j]) return false;
    for(int n : {a, b}) {
      const std::array<double, 2> p = cornerUV(i, n), q = cornerUV(j, n);
      const double d = std::abs(p[0] - q[0]) + std::abs(p[1] - q[1]);
      if(d > 1.e-9 * (1. + std::abs(p[0]) + std::abs(p[1]))) return true;
    }
    return false;
  };
  // the parameters made continuous across the seam of a surface that does not
  // go around it: the pieces of the surface on both sides of the seam (the
  // connected triangles with continuous parameters) moved onto each other by
  // the isometry of the plane given by the seam
  std::vector<std::size_t> piece(nt);
  for(std::size_t i = 0; i < nt; i++) piece[i] = i;
  std::function<std::size_t(std::size_t)> findPiece = [&](std::size_t i) {
    while(piece[i] != i) i = piece[i] = piece[piece[i]];
    return i;
  };
  struct Link {
    std::size_t a, b;
    int na, nb;
    double length;
  };
  std::vector<Link> links;
  for(auto &e : edgeTriangles) {
    const std::vector<std::size_t> &t = e.second;
    if(t.size() != 2 || surfaceOf[t[0]] != surfaceOf[t[1]] || !hasUV[t[0]])
      continue;
    if(!jumps(t[0], t[1], e.first.first, e.first.second))
      piece[findPiece(t[0])] = findPiece(t[1]);
    else {
      const std::array<double, 2> p = cornerUV(t[0], e.first.first),
                                  q = cornerUV(t[0], e.first.second);
      links.push_back({t[0], t[1], e.first.first, e.first.second,
                       std::hypot(q[0] - p[0], q[1] - p[1])});
    }
  }
  std::sort(links.begin(), links.end(), [](const Link &l, const Link &m) {
    return l.length > m.length;
  });
  std::map<std::size_t, std::vector<std::size_t> > trianglesOfPiece;
  for(std::size_t i = 0; i < nt; i++)
    if(hasUV[i]) trianglesOfPiece[findPiece(i)].push_back(i);
  std::map<std::size_t, std::vector<const Link *> > linksOfPiece;
  for(auto &l : links) {
    linksOfPiece[findPiece(l.a)].push_back(&l);
    linksOfPiece[findPiece(l.b)].push_back(&l);
  }
  std::set<std::size_t> placed;
  std::vector<std::pair<std::size_t, std::size_t> > pieces; // size, root
  for(auto &p : trianglesOfPiece) pieces.push_back({p.second.size(), p.first});
  std::sort(pieces.rbegin(), pieces.rend());
  for(auto &p : pieces) {
    if(placed.count(p.second)) continue;
    placed.insert(p.second);
    std::vector<std::size_t> queue = {p.second};
    while(!queue.empty()) {
      const std::size_t c = queue.back();
      queue.pop_back();
      for(const Link *l : linksOfPiece[c]) {
        // the triangle along the link on the placed side, and on the other
        const bool aPlaced = findPiece(l->a) == c;
        const std::size_t ti = aPlaced ? l->a : l->b, tj = aPlaced ? l->b : l->a;
        const std::size_t d = findPiece(tj);
        if(placed.count(d)) continue;
        const std::array<double, 2> pa = cornerUV(ti, l->na),
                                    pb = cornerUV(ti, l->nb),
                                    qa = cornerUV(tj, l->na),
                                    qb = cornerUV(tj, l->nb);
        const double angle =
          std::atan2(pb[1] - pa[1], pb[0] - pa[0]) -
          std::atan2(qb[1] - qa[1], qb[0] - qa[0]);
        const double c0 = std::cos(angle), s0 = std::sin(angle);
        const double tx = pa[0] - (c0 * qa[0] - s0 * qa[1]);
        const double ty = pa[1] - (s0 * qa[0] + c0 * qa[1]);
        for(std::size_t i : trianglesOfPiece[d])
          for(auto &q : uv[i])
            q = {{c0 * q[0] - s0 * q[1] + tx, s0 * q[0] + c0 * q[1] + ty}};
        placed.insert(d);
        queue.push_back(d);
      }
    }
  }
  for(auto &s : surfaceOfRoot) _surfaces[s.second].uv.clear();
  for(std::size_t i = 0; i < nt; i++)
    if(hasUV[i]) _surfaces[surfaceOf[i]].uv.push_back(uv[i]);
  for(auto &s : surfaceOfRoot) {
    Surface &sf = _surfaces[s.second];
    if(sf.uv.size() != sf.triangles.size()) sf.uv.clear();
  }

  // (and the creases inside the surfaces, their embedded curves)
  enum Kind { FEATURE, SEAM, CREASE };
  std::map<std::pair<int, int>, Kind> special;
  // (the surfaces of the triangles along each of these edges, as many times
  // as they have triangles there)
  std::map<std::pair<int, int>, std::vector<int> > around;
  std::map<int, std::vector<int> > neighbors;
  for(auto &e : edgeTriangles) {
    const std::vector<std::size_t> &t = e.second;
    Kind kind = FEATURE;
    if(t.size() == 2 && surfaceOf[t[0]] == surfaceOf[t[1]]) {
      if(jumps(t[0], t[1], e.first.first, e.first.second))
        kind = SEAM;
      else if(creases.count(e.first))
        kind = CREASE;
      else
        continue;
    }
    special[e.first] = kind;
    std::vector<int> &s = around[e.first];
    for(std::size_t i : t) s.push_back(surfaceOf[i]);
    std::sort(s.begin(), s.end());
    neighbors[e.first.first].push_back(e.first.second);
    neighbors[e.first.second].push_back(e.first.first);
  }

  // the curves: chains of these edges between the nodes where more or less
  // than two of them meet, where their kind changes, where the surfaces along
  // them change (where a surface stops along a curve going on: the end of a
  // sheet hanging from the inside of a surface, its free edge going on) or
  // where they turn by more than curveAngle, closed chains split in two arcs
  // at the nodes where they turn the most
  auto turn = [&](int p, int n, int q) {
    const std::array<double, 3> &a = _nodes[p], &x = _nodes[n],
                                &b = _nodes[q];
    double uv = 0., uu = 0., vv = 0.;
    for(int k = 0; k < 3; k++) {
      uv += (x[k] - a[k]) * (b[k] - x[k]);
      uu += (x[k] - a[k]) * (x[k] - a[k]);
      vv += (b[k] - x[k]) * (b[k] - x[k]);
    }
    if(uu == 0. || vv == 0.) return 0.;
    return std::acos(std::max(-1., std::min(1., uv / std::sqrt(uu * vv))));
  };
  auto corner = [&](int n) {
    const std::vector<int> &nb = neighbors[n];
    return nb.size() != 2 ||
           special[std::minmax(n, nb[0])] != special[std::minmax(n, nb[1])] ||
           around[std::minmax(n, nb[0])] != around[std::minmax(n, nb[1])] ||
           turn(nb[0], n, nb[1]) > curveAngle;
  };
  std::map<int, int> vertexOf;
  auto vertex = [&](int n) {
    auto it = vertexOf.find(n);
    if(it == vertexOf.end()) it = vertexOf.insert({n, _addVertex(n)}).first;
    return it->second;
  };
  std::set<std::pair<int, int> > visited;
  std::map<std::pair<int, int>, int> curveOfEdge; // directed edge -> +-curve
  auto addChain = [&](const std::vector<int> &nodes) {
    const int c =
      _addCurve(vertex(nodes.front()), vertex(nodes.back()), nodes);
    for(std::size_t j = 0; j + 1 < nodes.size(); j++) {
      curveOfEdge[{nodes[j], nodes[j + 1]}] = c;
      curveOfEdge[{nodes[j + 1], nodes[j]}] = -c;
    }
  };
  auto walk = [&](int a, int b) {
    std::vector<int> nodes = {a, b};
    visited.insert(std::minmax(a, b));
    while(!corner(nodes.back()) && nodes.back() != nodes.front()) {
      const int last = nodes.back(), previous = nodes[nodes.size() - 2];
      const int next = neighbors[last][0] == previous ? neighbors[last][1] :
                                                       neighbors[last][0];
      if(visited.count(std::minmax(last, next))) break;
      visited.insert(std::minmax(last, next));
      nodes.push_back(next);
    }
    return nodes;
  };
  for(auto &nb : neighbors) {
    if(!corner(nb.first)) continue;
    for(int b : nb.second)
      if(!visited.count(std::minmax(nb.first, b)))
        addChain(walk(nb.first, b));
  }
  for(auto &nb : neighbors)
    for(int b : nb.second)
      if(!visited.count(std::minmax(nb.first, b))) {
        std::vector<int> loop = walk(nb.first, b);
        // the node where it turns the most, and the one where it turns the
        // most at least a quarter of the loop away
        const std::size_t n = loop.size() - 1;
        std::vector<double> angle(n);
        for(std::size_t i = 0; i < n; i++)
          angle[i] = turn(loop[(i + n - 1) % n], loop[i], loop[i + 1]);
        std::size_t first = 0;
        for(std::size_t i = 1; i < n; i++)
          if(angle[i] > angle[first]) first = i;
        std::size_t second = (first + n / 2) % n;
        for(std::size_t i = 0; i < n; i++) {
          const std::size_t d = (i + n - first) % n;
          if(std::min(d, n - d) >= std::max<std::size_t>(1, n / 4) &&
             angle[i] > angle[second])
            second = i;
        }
        std::vector<int> arc[2];
        for(std::size_t i = first;; i = (i + 1) % n) {
          arc[0].push_back(loop[i]);
          if(i == second) break;
        }
        for(std::size_t i = second;; i = (i + 1) % n) {
          arc[1].push_back(loop[i]);
          if(i == first) break;
        }
        addChain(arc[0]);
        addChain(arc[1]);
      }

  // the curves of the surfaces, oriented as their triangles, their seams
  // twice, with their parameters on their two sides: from the triangles along
  // them in their direction (side 0) and in the other one; their creases, and
  // the curves with the surface on their two sides where other surfaces meet
  // it (a surface ending inside it), embedded
  auto bothSides = [&](int surface, int a, int b) {
    bool forward = false, backward = false;
    for(std::size_t i : edgeTriangles[std::minmax(a, b)]) {
      if(surfaceOf[i] != surface) continue;
      int k = 0;
      while(k < 3 && triangles[i][k] != a) k++;
      if(triangles[i][(k + 1) % 3] == b)
        forward = true;
      else
        backward = true;
    }
    return forward && backward;
  };
  for(auto &s : surfaceOfRoot) {
    Surface &sf = _surfaces[s.second];
    std::set<int> curves;
    for(std::size_t i = 0; i < nt; i++) {
      if(surfaceOf[i] != s.second) continue;
      for(int k = 0; k < 3; k++) {
        const int a = triangles[i][k], b = triangles[i][(k + 1) % 3];
        auto it = curveOfEdge.find({a, b});
        if(it == curveOfEdge.end()) continue;
        const int c = std::abs(it->second);
        if(!curves.insert(c).second) continue;
        const Kind kind = special[std::minmax(a, b)];
        if(kind == SEAM) {
          sf.curves.push_back(c);
          sf.curves.push_back(-c);
          sf.seams[c];
        }
        else if(kind == CREASE || bothSides(s.second, a, b))
          sf.embeddedCurves.push_back(c);
        else
          sf.curves.push_back(it->second);
      }
    }
    for(auto &sm : sf.seams) {
      const std::vector<int> &n = _curves[sm.first].nodes;
      for(int side = 0; side < 2; side++) sm.second[side].resize(n.size());
      for(std::size_t j = 0; j + 1 < n.size(); j++)
        for(std::size_t i : edgeTriangles[std::minmax(n[j], n[j + 1])]) {
          int k = 0;
          while(k < 3 && triangles[i][k] != n[j]) k++;
          const int side = triangles[i][(k + 1) % 3] == n[j + 1] ? 0 : 1;
          sm.second[side][j] = cornerUV(i, n[j]);
          sm.second[side][j + 1] = cornerUV(i, n[j + 1]);
        }
    }
  }
}

std::vector<std::vector<std::vector<int> > >
DiscreteCAD_Internals::_cells(const std::vector<std::array<int, 3> > &triangles,
                              const std::vector<int> &surfaceOf,
                              std::vector<std::vector<int> > *embedded) const
{
  const std::size_t nt = triangles.size();
  std::map<std::pair<int, int>, std::vector<std::size_t> > edgeTriangles;
  for(std::size_t i = 0; i < nt; i++)
    for(int k = 0; k < 3; k++)
      edgeTriangles[std::minmax(triangles[i][k], triangles[i][(k + 1) % 3])]
        .push_back(i);
  // the connected pieces of the triangulation, and its shells: the sides of
  // the triangles (2 i behind triangle i, its normal pointing out of the cell
  // on that side, 2 i + 1 in front of it) facing the same cell, joined around
  // their edges
  std::vector<std::size_t> piece(nt), side(2 * nt);
  for(std::size_t i = 0; i < nt; i++) piece[i] = i;
  for(std::size_t i = 0; i < 2 * nt; i++) side[i] = i;
  auto find = [](std::vector<std::size_t> &parent, std::size_t i) {
    while(parent[i] != i) i = parent[i] = parent[parent[i]];
    return i;
  };
  auto along = [&](std::size_t i, int a, int b) {
    for(int k = 0; k < 3; k++)
      if(triangles[i][k] == a) return triangles[i][(k + 1) % 3] == b;
    return false;
  };
  for(auto &e : edgeTriangles) {
    const int a = e.first.first, b = e.first.second;
    std::vector<std::size_t> t = e.second;
    if(t.size() > 2) {
      // around the edge, by increasing angle of their third node
      const std::array<double, 3> &pa = _nodes[a], &pb = _nodes[b];
      double z[3] = {pb[0] - pa[0], pb[1] - pa[1], pb[2] - pa[2]};
      normalize(z);
      int m = 0;
      for(int k = 1; k < 3; k++)
        if(std::abs(z[k]) < std::abs(z[m])) m = k;
      double x[3] = {0., 0., 0.};
      x[m] = 1.;
      const double d = z[m];
      for(int k = 0; k < 3; k++) x[k] -= d * z[k];
      normalize(x);
      const double y[3] = {z[1] * x[2] - z[2] * x[1], z[2] * x[0] - z[0] * x[2],
                           z[0] * x[1] - z[1] * x[0]};
      std::vector<std::pair<double, std::size_t> > angles;
      for(std::size_t i : t) {
        int c = triangles[i][0];
        for(int k = 1; k < 3 && (c == a || c == b); k++) c = triangles[i][k];
        double u = 0., v = 0.;
        for(int k = 0; k < 3; k++) {
          u += (_nodes[c][k] - pa[k]) * x[k];
          v += (_nodes[c][k] - pa[k]) * y[k];
        }
        angles.push_back({std::atan2(v, u), i});
      }
      std::sort(angles.begin(), angles.end());
      for(std::size_t k = 0; k < t.size(); k++) t[k] = angles[k].second;
    }
    // the sides facing the cell between two consecutive triangles i and j: in
    // front of i if it goes from a to b, in front of j if it goes from b to a
    for(std::size_t k = 0; k < t.size(); k++) {
      const std::size_t i = t[k], j = t[(k + 1) % t.size()];
      side[find(side, 2 * i + (along(i, a, b) ? 1 : 0))] =
        find(side, 2 * j + (along(j, b, a) ? 1 : 0));
      piece[find(piece, i)] = find(piece, j);
    }
  }

  // the shells, their pieces, bounding boxes and volumes, and the volumes
  // enclosed by their triangles as oriented (the triangles with both sides in
  // a shell do not bound it)
  struct Shell {
    std::vector<std::size_t> sides;
    std::size_t piece;
    double volume, oriented, lo[3], hi[3];
  };
  std::vector<Shell> shells;
  std::map<std::size_t, std::size_t> shellOf;
  for(std::size_t s = 0; s < 2 * nt; s++) {
    auto it = shellOf.insert({find(side, s), shells.size()}).first;
    if(it->second == shells.size()) {
      shells.push_back(Shell());
      shells.back().piece = find(piece, s / 2);
    }
    shells[it->second].sides.push_back(s);
  }
  auto bounds = [&](std::size_t i) {
    return find(side, 2 * i) != find(side, 2 * i + 1);
  };
  for(Shell &sh : shells) {
    const std::array<double, 3> &o = _nodes[triangles[sh.sides[0] / 2][0]];
    sh.volume = sh.oriented = 0.;
    for(int k = 0; k < 3; k++) {
      sh.lo[k] = 1e300;
      sh.hi[k] = -1e300;
    }
    for(std::size_t s : sh.sides) {
      const std::array<int, 3> &t = triangles[s / 2];
      for(int n : t)
        for(int k = 0; k < 3; k++) {
          sh.lo[k] = std::min(sh.lo[k], _nodes[n][k]);
          sh.hi[k] = std::max(sh.hi[k], _nodes[n][k]);
        }
      if(!bounds(s / 2)) continue;
      double p[3][3];
      for(int j = 0; j < 3; j++)
        for(int k = 0; k < 3; k++) p[j][k] = _nodes[t[j]][k] - o[k];
      const double v = (p[0][0] * (p[1][1] * p[2][2] - p[1][2] * p[2][1]) -
                        p[0][1] * (p[1][0] * p[2][2] - p[1][2] * p[2][0]) +
                        p[0][2] * (p[1][0] * p[2][1] - p[1][1] * p[2][0])) /
                       6.;
      sh.volume += s % 2 ? -v : v;
      sh.oriented += v;
    }
  }
  // the winding number of a shell around a point (see DiscreteCADWinding,
  // the tree of its triangles made once)
  std::map<std::size_t, std::unique_ptr<DiscreteCADWinding> > trees;
  auto winding = [&](std::size_t c, const double p[3]) {
    auto it = trees.find(c);
    if(it == trees.end()) {
      std::map<int, int> local;
      std::vector<std::array<double, 3> > x;
      std::vector<std::array<int, 3> > t;
      for(std::size_t s : shells[c].sides) {
        if(!bounds(s / 2)) continue;
        std::array<int, 3> tr = triangles[s / 2];
        // (behind it, as oriented; in front of it, turned over)
        if(s % 2) std::swap(tr[1], tr[2]);
        for(int &n : tr) {
          auto l = local.insert({n, (int)x.size()});
          if(l.second) x.push_back(_nodes[n]);
          n = l.first->second;
        }
        t.push_back(tr);
      }
      it = trees.emplace(c, std::unique_ptr<DiscreteCADWinding>(
                              new DiscreteCADWinding(x, t))).first;
    }
    return (*it->second)(p);
  };

  // the cells: the shells of positive volume; the others, of negative volume,
  // bound the space around a piece, inside the smallest cell of another piece
  // around them, if any
  std::map<std::size_t, std::size_t> around; // shell of negative volume -> cell
  std::map<std::size_t, std::size_t> outside; // piece -> its largest such shell
  for(std::size_t n = 0; n < shells.size(); n++) {
    const Shell &sh = shells[n];
    if(sh.volume >= 0.) continue;
    auto o = outside.find(sh.piece);
    if(o == outside.end() || shells[o->second].volume > sh.volume)
      outside[sh.piece] = n;
    std::size_t i = 0;
    while(!bounds(sh.sides[i] / 2)) i++;
    const std::array<int, 3> &t = triangles[sh.sides[i] / 2];
    double p[3];
    for(int k = 0; k < 3; k++)
      p[k] = (_nodes[t[0]][k] + _nodes[t[1]][k] + _nodes[t[2]][k]) / 3.;
    double smallest = 1e300;
    for(std::size_t c = 0; c < shells.size(); c++) {
      const Shell &cl = shells[c];
      if(cl.volume <= 0. || cl.piece == sh.piece || cl.volume >= smallest)
        continue;
      bool in = true;
      for(int k = 0; k < 3; k++)
        if(p[k] < cl.lo[k] || p[k] > cl.hi[k]) in = false;
      if(!in || winding(c, p) < 0.5) continue;
      smallest = cl.volume;
      around[n] = c;
    }
  }
  // the cells of a piece are volumes if the space around it is in no cell,
  // or if its triangles point out of it (around it, as oriented, they enclose
  // a positive volume), holes otherwise
  auto isSolid = [&](std::size_t pc) {
    auto o = outside.find(pc);
    if(o == outside.end() || !around.count(o->second)) return true;
    return shells[o->second].oriented > 0.;
  };

  // the signed surfaces of a shell; those on both sides of it, inside the
  // volume, in inside
  auto surfaces = [&](const Shell &sh, std::vector<int> &inside) {
    std::map<int, int> signOf;
    for(std::size_t s : sh.sides) {
      const int sf = surfaceOf[s / 2], sign = s % 2 ? -1 : 1;
      auto it = signOf.insert({sf, sign}).first;
      if(it->second != sign) it->second = 0;
    }
    std::vector<int> r;
    for(auto &sg : signOf) {
      if(sg.second)
        r.push_back(sg.second * sg.first);
      else if(embedded)
        inside.push_back(sg.first);
      else
        Msg::Warning("Discrete CAD surface %d inside a volume, not on its "
                     "boundary: ignored",
                     sg.first);
    }
    return r;
  };
  std::map<std::size_t, std::size_t> volumeOf; // cell -> volume
  struct Cell {
    std::vector<std::vector<int> > shells;
    std::vector<int> inside;
  };
  std::vector<Cell> volumes;
  for(std::size_t c = 0; c < shells.size(); c++) {
    if(shells[c].volume <= 0. || !isSolid(shells[c].piece)) continue;
    std::vector<int> inside;
    std::vector<int> outer = surfaces(shells[c], inside);
    if(outer.empty()) continue;
    volumeOf[c] = volumes.size();
    volumes.push_back({{outer}, inside});
  }
  // the shells around the pieces inside a volume, the holes and the volumes
  // in it
  for(auto &a : around) {
    auto v = volumeOf.find(a.second);
    if(v != volumeOf.end())
      volumes[v->second].shells.push_back(
        surfaces(shells[a.first], volumes[v->second].inside));
  }
  // the pieces bounding nothing (surfaces, both sides of their triangles in
  // the same shell) inside a volume, in its smallest cell around them
  for(std::size_t n = 0; n < shells.size() && embedded; n++) {
    const Shell &sh = shells[n];
    bool flat = true;
    for(std::size_t i = 0; i < sh.sides.size() && flat; i++)
      if(bounds(sh.sides[i] / 2)) flat = false;
    if(!flat) continue;
    const std::array<int, 3> &t = triangles[sh.sides[0] / 2];
    double p[3];
    for(int k = 0; k < 3; k++)
      p[k] = (_nodes[t[0]][k] + _nodes[t[1]][k] + _nodes[t[2]][k]) / 3.;
    double smallest = 1e300;
    std::size_t in = shells.size();
    for(std::size_t c = 0; c < shells.size(); c++) {
      const Shell &cl = shells[c];
      if(cl.volume <= 0. || cl.piece == sh.piece || cl.volume >= smallest ||
         !volumeOf.count(c))
        continue;
      bool inBox = true;
      for(int k = 0; k < 3; k++)
        if(p[k] < cl.lo[k] || p[k] > cl.hi[k]) inBox = false;
      if(!inBox || winding(c, p) < 0.5) continue;
      smallest = cl.volume;
      in = c;
    }
    if(in < shells.size())
      surfaces(sh, volumes[volumeOf[in]].inside);
  }
  // in the order of their surfaces
  std::sort(volumes.begin(), volumes.end(), [](const Cell &v, const Cell &w) {
    return std::abs(v.shells[0][0]) < std::abs(w.shells[0][0]);
  });
  std::vector<std::vector<std::vector<int> > > r;
  if(embedded) embedded->clear();
  for(Cell &c : volumes) {
    r.push_back(c.shells);
    if(embedded) {
      std::sort(c.inside.begin(), c.inside.end());
      c.inside.erase(std::unique(c.inside.begin(), c.inside.end()),
                     c.inside.end());
      embedded->push_back(c.inside);
    }
  }
  return r;
}

bool DiscreteCAD_Internals::_mergeNodes(
  const std::vector<double> &coord, const std::vector<std::size_t> &triangles,
  const std::vector<int> &pieces, std::vector<std::array<int, 3> > &tri,
  std::vector<int> &piece)
{
  tri.clear();
  piece.clear();
  const std::size_t nn = coord.size() / 3;
  if(coord.size() % 3 || triangles.size() % 3 ||
     (!pieces.empty() && pieces.size() != triangles.size() / 3)) {
    Msg::Error("Discrete CAD triangulation: %lu coordinates, %lu node "
               "indices and %lu pieces",
               coord.size(), triangles.size(), pieces.size());
    return false;
  }
  for(std::size_t n : triangles) {
    if(n < nn) continue;
    Msg::Error("Discrete CAD triangulation: unknown node %lu", n);
    return false;
  }

  // the nodes, those at the same coordinates merged
  std::map<std::array<double, 3>, int> nodeOf;
  std::vector<int> node(nn, -1);
  for(std::size_t i = 0; i < triangles.size() / 3; i++) {
    std::array<int, 3> t;
    for(int k = 0; k < 3; k++) {
      const std::size_t n = triangles[3 * i + k];
      if(node[n] < 0) {
        const std::array<double, 3> p = {
          {coord[3 * n], coord[3 * n + 1], coord[3 * n + 2]}};
        auto it = nodeOf.find(p);
        if(it == nodeOf.end())
          it = nodeOf.insert({p, _addNode(p[0], p[1], p[2])}).first;
        node[n] = it->second;
      }
      t[k] = node[n];
    }
    tri.push_back(t);
    piece.push_back(pieces.empty() ? 0 : pieces[i]);
  }
  return true;
}

bool DiscreteCAD_Internals::_cleanTriangles(
  std::vector<std::array<int, 3> > &tri, std::vector<int> &piece)
{
  DiscreteCADHealReport r;
  std::vector<std::size_t> kept;
  removeBadTriangles(tri, r, &kept);
  for(std::size_t j = 0; j < kept.size(); j++) piece[j] = piece[kept[j]];
  piece.resize(kept.size());
  if(r.degenerate || r.duplicated)
    Msg::Warning("Discrete CAD triangulation: %d degenerate and %d "
                 "duplicate triangles ignored",
                 r.degenerate, r.duplicated);
  if(tri.empty()) {
    Msg::Error("Discrete CAD triangulation without triangles");
    return false;
  }
  std::vector<std::vector<std::size_t> > components;
  std::vector<char> closed, turned;
  if(!orientAsNeighbors(tri, components, closed, turned))
    Msg::Warning("Discrete CAD triangulation not orientable");
  return true;
}

void DiscreteCAD_Internals::_patches(
  const std::vector<std::array<int, 3> > &tri, const std::vector<int> &piece,
  double angle, std::vector<int> &label,
  std::set<std::pair<int, int> > &barrier)
{
  const std::size_t nt = tri.size();
  std::map<std::pair<int, int>, std::vector<std::size_t> > edgeTriangles;
  for(std::size_t i = 0; i < nt; i++)
    for(int k = 0; k < 3; k++)
      edgeTriangles[std::minmax(tri[i][k], tri[i][(k + 1) % 3])].push_back(i);

  // the surfaces: the triangles of the same piece connected across edges of
  // two triangles that are not sharp
  std::vector<std::size_t> parent(nt);
  for(std::size_t i = 0; i < nt; i++) parent[i] = i;
  std::function<std::size_t(std::size_t)> find = [&](std::size_t i) {
    while(parent[i] != i) i = parent[i] = parent[parent[i]];
    return i;
  };
  // (the sharp edges: where the angle between the triangles is at least angle
  // and that between the sheets of the surface, see sheetAngles, at least
  // angle / 2 (on a coarse triangulation of a smooth surface, it is
  // smaller), or where the latter is at least angle / 2 continuing sharp
  // edges, at the end of their chains or between two of them; curves, on the
  // boundary of the surfaces or embedded in them)
  std::vector<std::array<int, 4> > inner;
  for(auto &e : edgeTriangles) {
    if(e.second.size() != 2) continue;
    const std::size_t i = e.second[0], j = e.second[1];
    if(piece[i] != piece[j]) continue;
    inner.push_back({{e.first.first, e.first.second, (int)i, (int)j}});
  }
  std::vector<double> sheet, raw;
  sheetAngles(_nodes, tri, inner, angle / 2., sheet, raw);
  std::set<std::pair<int, int> > sharp;
  std::map<int, std::vector<std::size_t> > weakAt;
  for(std::size_t k = 0; k < inner.size(); k++) {
    const std::pair<int, int> edge(inner[k][0], inner[k][1]);
    if(raw[k] >= angle && sheet[k] >= angle / 2.)
      sharp.insert(edge);
    else if(sheet[k] >= angle / 2.) {
      weakAt[edge.first].push_back(k);
      weakAt[edge.second].push_back(k);
    }
  }
  // (the weak ones continuing sharp ones, turning by less than 45 degrees;
  // then one of the edges around a triangle all of whose edges are sharp
  // removed, and the chains of those leaving the middle of a chain of sharp
  // edges without reaching another one)
  std::set<std::pair<int, int> > promoted;
  std::vector<std::pair<int, int> > front; // (node, previous node)
  for(auto &e : sharp)
    front.insert(front.end(), {{e.first, e.second}, {e.second, e.first}});
  while(!front.empty()) {
    const int v = front.back().first, u = front.back().second;
    front.pop_back();
    auto it = weakAt.find(v);
    if(it == weakAt.end()) continue;
    for(std::size_t k : it->second) {
      const std::pair<int, int> edge(inner[k][0], inner[k][1]);
      const int w = edge.first == v ? edge.second : edge.first;
      double p[3], q[3];
      for(int j = 0; j < 3; j++) {
        p[j] = _nodes[v][j] - _nodes[u][j];
        q[j] = _nodes[w][j] - _nodes[v][j];
      }
      const double c = (p[0] * q[0] + p[1] * q[1] + p[2] * q[2]) /
                       std::sqrt((p[0] * p[0] + p[1] * p[1] + p[2] * p[2]) *
                                 (q[0] * q[0] + q[1] * q[1] + q[2] * q[2]));
      if(!(c > std::cos(pi / 4.))) continue;
      if(!sharp.insert(edge).second) continue;
      promoted.insert(edge);
      front.push_back({w, v});
    }
  }
  if(!promoted.empty()) {
    std::map<std::pair<int, int>, double> sheetOf;
    for(std::size_t k = 0; k < inner.size(); k++)
      sheetOf[std::make_pair(inner[k][0], inner[k][1])] = sheet[k];
    for(std::size_t i = 0; i < nt; i++) {
      std::pair<int, int> weakest(-1, -1);
      bool closed = true;
      for(int k = 0; k < 3 && closed; k++) {
        const std::pair<int, int> edge =
          std::minmax(tri[i][k], tri[i][(k + 1) % 3]);
        auto it = edgeTriangles.find(edge);
        const bool boundary = it->second.size() != 2 ||
                              piece[it->second[0]] != piece[it->second[1]];
        if(!boundary && !sharp.count(edge)) closed = false;
        if(promoted.count(edge) &&
           (weakest.first < 0 || sheetOf[edge] < sheetOf[weakest]))
          weakest = edge;
      }
      if(closed && weakest.first >= 0) {
        sharp.erase(weakest);
        promoted.erase(weakest);
      }
    }
  }
  for(bool removed = true; removed && !promoted.empty();) {
    removed = false;
    std::map<int, std::vector<std::pair<int, int> > > sharpAt;
    for(auto &e : sharp) {
      sharpAt[e.first].push_back(e);
      sharpAt[e.second].push_back(e);
    }
    std::set<std::pair<int, int> > visited;
    for(auto &e0 : std::set<std::pair<int, int> >(promoted)) {
      if(visited.count(e0)) continue;
      // the chain of promoted edges through nodes of two sharp edges, and its
      // ends
      std::vector<std::pair<int, int> > chain = {e0};
      visited.insert(e0);
      int ends[2] = {e0.first, e0.second};
      for(int side = 0; side < 2; side++) {
        std::pair<int, int> last = e0;
        while(sharpAt[ends[side]].size() == 2) {
          const std::vector<std::pair<int, int> > &at = sharpAt[ends[side]];
          const std::pair<int, int> next = at[0] == last ? at[1] : at[0];
          if(!promoted.count(next) || visited.count(next)) break;
          visited.insert(next);
          chain.push_back(next);
          ends[side] = next.first == ends[side] ? next.second : next.first;
          last = next;
        }
      }
      const std::size_t d0 = sharpAt[ends[0]].size(), d1 = sharpAt[ends[1]].size();
      if((d0 == 1 && d1 >= 3) || (d1 == 1 && d0 >= 3) || (d0 == 1 && d1 == 1)) {
        for(auto &e : chain) {
          sharp.erase(e);
          promoted.erase(e);
        }
        removed = true;
      }
    }
  }
  for(auto &e : inner)
    if(!sharp.count(std::make_pair(e[0], e[1]))) parent[find(e[2])] = find(e[3]);
  label.assign(nt, 0);
  for(std::size_t i = 0; i < nt; i++) label[i] = (int)find(i);
  barrier = sharp;
  for(auto &e : edgeTriangles)
    if(e.second.size() == 2 && piece[e.second[0]] != piece[e.second[1]])
      barrier.insert(e.first);
}

bool DiscreteCAD_Internals::_build(
  std::vector<std::array<int, 3> > &tri, std::vector<int> &label,
  const std::set<std::pair<int, int> > &barrier, double angle,
  double curveAngle, double tolerance, bool recognize,
  std::vector<std::pair<int, int> > &outDimTags, Fit *fit,
  const std::map<int, std::vector<std::array<std::array<double, 2>, 3> > >
    *charts)
{
  const std::size_t nt = tri.size();
  const std::set<std::pair<int, int> > &sharp = barrier;
  // (the labels given, and the number of triangles of each one, for the
  // charts)
  const std::vector<int> labelOf = charts ? label : std::vector<int>();
  std::map<int, std::size_t> countOf;
  for(int l : labelOf) countOf[l]++;
  std::map<std::pair<int, int>, std::vector<std::size_t> > edgeTriangles;
  for(std::size_t i = 0; i < nt; i++)
    for(int k = 0; k < 3; k++)
      edgeTriangles[std::minmax(tri[i][k], tri[i][(k + 1) % 3])].push_back(i);
  std::vector<std::size_t> parent(nt);
  std::function<std::size_t(std::size_t)> find = [&](std::size_t i) {
    while(parent[i] != i) i = parent[i] = parent[parent[i]];
    return i;
  };

  // the analytic surfaces, if recognize: the planes, spheres, cylinders, cones
  // and tori within the tolerance of the nodes of the surfaces or, for those
  // on none, of their pieces (see segmentSurface), with the parameters of the
  // primitives (a sphere or a torus split in two halves if needed, the apex of
  // a cone inside its surface an embedded vertex)
  // (the distances of the surfaces fitted to the surfaces kept up to ten
  // times the tolerance, or the default one, for the report)
  std::string given = "given";
  double reach = 0.;
  if(recognize) {
    double lo[3] = {1e300, 1e300, 1e300}, hi[3] = {-1e300, -1e300, -1e300};
    for(auto &t : tri)
      for(int n : t)
        for(int k = 0; k < 3; k++) {
          lo[k] = std::min(lo[k], _nodes[n][k]);
          hi[k] = std::max(hi[k], _nodes[n][k]);
        }
    const double size = std::sqrt((hi[0] - lo[0]) * (hi[0] - lo[0]) +
                                  (hi[1] - lo[1]) * (hi[1] - lo[1]) +
                                  (hi[2] - lo[2]) * (hi[2] - lo[2]));
    const double byDefault = CTX::instance()->geom.discreteTolerance * size;
    if(tolerance <= 0.) {
      tolerance = byDefault;
      char g[128];
      snprintf(g, sizeof(g), "Geometry.DiscreteTolerance %g times the size %g",
               CTX::instance()->geom.discreteTolerance, size);
      given = g;
    }
    reach = 10. * std::max(tolerance, byDefault);
  }
  std::vector<std::array<std::array<double, 2>, 3> > uv(nt);
  std::vector<char> hasUV(nt, 0);
  std::vector<int> apexes;
  int recognized[6] = {0, 0, 0, 0, 0, 0};
  std::vector<DiscreteCADAnalyticMap> maps;
  std::vector<int> mapOf(nt, -1);
  double precision = 0.;
  if(recognize) {
    std::set<int> used;
    for(auto &t : tri) used.insert(t.begin(), t.end());
    std::vector<std::array<double, 3> > x;
    for(int n : used) x.push_back(_nodes[n]);
    precision = coordinatePrecision(x);
    if(fit) {
      fit->tolerance = tolerance;
      fit->precision = precision;
      fit->reach = reach;
      fit->faces.label = "classified faces";
      fit->faces.dim = 2;
    }
  }
  if(recognize) {
    std::map<int, std::vector<std::size_t> > trianglesOf;
    for(std::size_t i = 0; i < nt; i++) trianglesOf[label[i]].push_back(i);
    int next = (int)nt;
    static const char *names[6] = {"", "plane", "sphere", "cylinder", "cone",
                                   "torus"};
    // the nodes (local) of some triangles of a surface
    auto localTriangles = [&](const std::vector<std::size_t> &which,
                              std::vector<std::array<double, 3> > &x,
                              std::vector<std::array<int, 3> > &lt,
                              std::vector<int> &global) {
      std::map<int, int> local;
      for(std::size_t i : which) {
        std::array<int, 3> t;
        for(int k = 0; k < 3; k++) {
          auto it = local.insert({tri[i][k], (int)x.size()});
          if(it.second) {
            x.push_back(_nodes[tri[i][k]]);
            global.push_back(tri[i][k]);
          }
          t[k] = it.first->second;
        }
        lt.push_back(t);
      }
    };
    for(auto &tl : trianglesOf) {
      std::vector<std::array<double, 3> > x;
      std::vector<std::array<int, 3> > lt;
      std::vector<int> global;
      localTriangles(tl.second, x, lt, global);
      std::vector<int> pieceOf;
      std::vector<DiscreteCADAnalyticSurface> analytic;
      std::array<double, 6> deviations;
      const DiscreteCADAnalyticSurface as =
        recognizeSurface(x, lt, tolerance, angle, reach, &deviations);
      if(fit) {
        // (as recognizeSurface rounds)
        double lo[3] = {1e300, 1e300, 1e300}, hi[3] = {-1e300, -1e300, -1e300};
        for(auto &p : x)
          for(int k = 0; k < 3; k++) {
            lo[k] = std::min(lo[k], p[k]);
            hi[k] = std::max(hi[k], p[k]);
          }
        double d = 0.;
        for(int k = 0; k < 3; k++) d += (hi[k] - lo[k]) * (hi[k] - lo[k]);
        const double face = (double)fit->deviations.size();
        fit->deviations.push_back(deviations);
        fit->rounding.push_back(1.e-12 * std::sqrt(d) / 2.);
        for(std::size_t i : tl.second) {
          fit->faces.nodes.insert(fit->faces.nodes.end(), tri[i].begin(),
                                  tri[i].end());
          fit->faces.values.push_back(face);
        }
      }
      if(as.type != DiscreteCADAnalyticSurface::NONE) {
        pieceOf.assign(lt.size(), 0);
        analytic.push_back(as);
      }
      else {
        // its triangles across the edges of two triangles, not sharp
        std::map<std::pair<int, int>, std::vector<int> > edges;
        for(std::size_t j = 0; j < lt.size(); j++)
          for(int k = 0; k < 3; k++)
            edges[std::minmax(lt[j][k], lt[j][(k + 1) % 3])].push_back((int)j);
        std::vector<std::vector<int> > neighbors(lt.size());
        for(auto &e : edges) {
          if(e.second.size() != 2 ||
             sharp.count(std::minmax(global[e.first.first],
                                     global[e.first.second])))
            continue;
          neighbors[e.second[0]].push_back(e.second[1]);
          neighbors[e.second[1]].push_back(e.second[0]);
        }
        segmentSurface(x, lt, neighbors, tolerance, precision, angle, pieceOf,
                       analytic);
      }
      for(std::size_t p = 0; p < analytic.size(); p++) {
        std::vector<std::size_t> which;
        for(std::size_t j = 0; j < lt.size(); j++)
          if(pieceOf[j] == (int)p) which.push_back(tl.second[j]);
        if(which.empty()) continue;
        std::vector<std::array<double, 3> > px;
        std::vector<std::array<int, 3> > pt;
        std::vector<int> pglobal;
        localTriangles(which, px, pt, pglobal);
        const DiscreteCADAnalyticSurface &a = analytic[p];
        recognized[a.type]++;
        double deviation = 0.;
        for(auto &q : px)
          deviation = std::max(deviation, std::abs(a.distance(q.data())));
        Msg::Debug("Discrete CAD triangulation: %lu triangles on a %s (%g, %g, "
                   "%g), axis (%g, %g, %g), %g, %g, at most %g away",
                   which.size(), names[a.type], a.o[0], a.o[1], a.o[2],
                   a.axis[0], a.axis[1], a.axis[2], a.r1, a.r2, deviation);
        std::vector<std::array<std::array<double, 2>, 3> > luv;
        std::vector<int> half;
        std::vector<DiscreteCADAnalyticMap> halves;
        int apex;
        analyticParameters(a, px, pt, tolerance, luv, half, apex, halves);
        const int first = next++, second = next++;
        for(std::size_t j = 0; j < which.size(); j++) {
          const std::size_t i = which[j];
          uv[i] = luv[j];
          hasUV[i] = 1;
          label[i] = half[j] ? second : first;
          mapOf[i] = (int)maps.size() + (half[j] && halves.size() > 1 ? 1 : 0);
        }
        maps.insert(maps.end(), halves.begin(), halves.end());
        if(apex >= 0) apexes.push_back(pglobal[apex]);
      }
    }
  }

  // (the other triangles of a surface, in several pieces around those on
  // analytic surfaces, a surface for each piece)
  {
    for(std::size_t i = 0; i < nt; i++) parent[i] = i;
    for(auto &e : edgeTriangles) {
      if(e.second.size() != 2) continue;
      const std::size_t i = e.second[0], j = e.second[1];
      if(!hasUV[i] && !hasUV[j] && label[i] == label[j])
        parent[find(i)] = find(j);
    }
    for(std::size_t i = 0; i < nt; i++)
      if(!hasUV[i]) label[i] = (int)find(i);
  }

  // the parameters of the other surfaces, those of charts for a label left
  // whole, or else computed on their triangulations as createGeometry would,
  // each one cut open into a disk along seams if it is not one (see cutOpen;
  // the boolean operations then interpolate them)
  {
    TemporaryModel tmp;
    std::map<int, std::vector<std::size_t> > trianglesOf;
    for(std::size_t i = 0; i < nt; i++)
      if(!hasUV[i]) trianglesOf[label[i]].push_back(i);
    int failed = 0;
    for(auto &tl : trianglesOf) {
      if(charts) {
        const int l = labelOf[tl.second[0]];
        auto c = charts->find(l);
        if(c != charts->end() && c->second.size() == tl.second.size() &&
           countOf[l] == tl.second.size()) {
          for(std::size_t j = 0; j < tl.second.size(); j++) {
            uv[tl.second[j]] = c->second[j];
            hasUV[tl.second[j]] = 1;
          }
          continue;
        }
      }
      std::vector<std::array<int, 3> > lt;
      for(std::size_t i : tl.second) lt.push_back(tri[i]);
      std::vector<int> nodeOfCopy;
      const std::vector<std::array<int, 3> > copies = cutOpen(lt, nodeOfCopy);
      std::vector<MVertex *> vertexOf(nodeOfCopy.size());
      for(std::size_t c = 0; c < nodeOfCopy.size(); c++) {
        const std::array<double, 3> &x = _nodes[nodeOfCopy[c]];
        vertexOf[c] = new MVertex(x[0], x[1], x[2]);
      }
      std::vector<MTriangle *> ts;
      for(auto &t : copies)
        ts.push_back(
          new MTriangle(vertexOf[t[0]], vertexOf[t[1]], vertexOf[t[2]]));
      std::vector<MVertex *> nodes;
      std::vector<SPoint2> nodesUV;
      std::vector<SPoint3> nodesXYZ;
      std::vector<int> corners;
      if(computeParametrization(ts, nodes, nodesUV, nodesXYZ, corners)) {
        for(std::size_t j = 0; j < tl.second.size(); j++) {
          const std::size_t i = tl.second[j];
          for(int k = 0; k < 3; k++) {
            const SPoint2 &p = nodesUV[corners[3 * j + k]];
            uv[i][k] = {{p.x(), p.y()}};
          }
          hasUV[i] = 1;
        }
      }
      else
        failed++;
      for(MTriangle *t : ts) delete t;
      for(MVertex *v : vertexOf) delete v;
    }
    if(failed)
      Msg::Warning("Discrete CAD triangulation: %d surface%s not parametrized",
                   failed, failed == 1 ? "" : "s");
  }

  // the surfaces, curves and vertices, and the volumes
  // (the curves where different surfaces meet, the seams of the surfaces, and
  // the sharp edges inside a surface, which separate nothing (a crease fading
  // out at both ends, as the crest of a thread): its embedded curves, or the
  // meshes would cut across them)
  std::vector<int> surfaceOf;
  // (the chains of those shorter than Geometry.DiscreteCreaseLength left out:
  // the noise of a scan, its spikes, would be as many tiny curves)
  std::set<std::pair<int, int> > creases;
  int creasesLeft = 0;
  {
    std::map<int, int> up;
    std::function<int(int)> root = [&](int n) {
      auto it = up.find(n);
      if(it == up.end()) {
        up[n] = n;
        return n;
      }
      while(up[n] != n) n = up[n] = up[up[n]];
      return n;
    };
    std::vector<std::pair<int, int> > inner;
    for(auto &e : sharp) {
      auto it = edgeTriangles.find(e);
      if(it == edgeTriangles.end() || it->second.size() != 2 ||
         label[it->second[0]] != label[it->second[1]])
        continue;
      inner.push_back(e);
      up[root(e.first)] = root(e.second);
    }
    std::map<int, double> length;
    for(auto &e : inner) {
      double d = 0.;
      for(int k = 0; k < 3; k++)
        d += (_nodes[e.first][k] - _nodes[e.second][k]) *
             (_nodes[e.first][k] - _nodes[e.second][k]);
      length[root(e.first)] += std::sqrt(d);
    }
    const double minLength = CTX::instance()->geom.discreteCreaseLength;
    for(auto &l : length)
      if(l.second < minLength) creasesLeft++;
    for(auto &e : inner)
      if(length[root(e.first)] >= minLength) creases.insert(e);
  }
  _addTopology(tri, label, uv, hasUV, creases, curveAngle, surfaceOf);
  for(std::size_t i = 0; i < nt; i++) {
    Surface &sf = _surfaces[surfaceOf[i]];
    if(mapOf[i] >= 0) sf.analytic = maps[mapOf[i]];
    if(recognize) continue;
    sf.classified = true;
    sf.angle = angle;
    sf.curveAngle = curveAngle;
  }
  std::vector<std::vector<std::vector<int> > > cells = _cells(tri, surfaceOf);
  // (the apexes of the cones inside their surfaces)
  for(int a : apexes) {
    std::size_t i = 0;
    while(i < nt && tri[i][0] != a && tri[i][1] != a && tri[i][2] != a) i++;
    if(i == nt) continue;
    Surface &sf = _surfaces[surfaceOf[i]];
    bool inside = true;
    for(int c : sf.curves)
      for(int n : _curves[std::abs(c)].nodes)
        if(n == a) inside = false;
    if(inside) sf.embeddedVertices.push_back(_addVertex(a));
  }

  // the surfaces oriented outwards of the first volume whose outer shell they
  // are on, or else of the first volume they bound
  std::map<int, int> signOf;
  for(auto &cell : cells)
    for(int s : cell[0]) signOf.insert({std::abs(s), s > 0 ? 1 : -1});
  for(auto &cell : cells)
    for(auto &shell : cell)
      for(int s : shell) signOf.insert({std::abs(s), s > 0 ? 1 : -1});
  for(auto &sg : signOf) {
    if(sg.second > 0) continue;
    Surface &sf = _surfaces[sg.first];
    for(auto &t : sf.triangles) std::swap(t[1], t[2]);
    for(auto &q : sf.uv) std::swap(q[1], q[2]);
    for(auto &sm : sf.seams) std::swap(sm.second[0], sm.second[1]);
    for(int &c : sf.curves) c = -c;
  }
  for(auto &cell : cells) {
    std::vector<int> shells;
    for(auto &shell : cell)
      for(int s : shell) shells.push_back(signOf[std::abs(s)] > 0 ? s : -s);
    int t = -1;
    _assignTag(3, t);
    _volumes[t] = Volume();
    _volumes[t].surfaces = shells;
    outDimTags.push_back({3, t});
  }
  std::set<int> surfaces(surfaceOf.begin(), surfaceOf.end());
  for(int s : surfaces)
    if(!signOf.count(s)) outDimTags.push_back({2, s});
  std::set<int> curves, embedded;
  for(int s : surfaces) {
    for(int c : _surfaces[s].curves) curves.insert(std::abs(c));
    for(int c : _surfaces[s].embeddedCurves) embedded.insert(c);
  }
  std::string inside;
  if(!embedded.empty())
    inside += plural(embedded.size(), "curve", "curves") +
              " embedded in the surfaces (sharp edges inside them)";
  if(creasesLeft) {
    char l[64];
    snprintf(l, sizeof(l), "%g", CTX::instance()->geom.discreteCreaseLength);
    inside += std::string(inside.empty() ? "" : ", ") +
              plural(creasesLeft, "chain", "chains") +
              " of sharp edges inside them shorter than " + l +
              " (Geometry.DiscreteCreaseLength) left out";
  }
  Msg::Info("Discrete CAD triangulation: %lu volume%s, %lu surface%s, %lu "
            "curve%s%s%s",
            cells.size(), cells.size() == 1 ? "" : "s", surfaces.size(),
            surfaces.size() == 1 ? "" : "s", curves.size(),
            curves.size() == 1 ? "" : "s", inside.empty() ? "" : "; ",
            inside.c_str());
  _built = plural(cells.size(), "volume", "volumes") + ", " +
           plural(surfaces.size(), "surface", "surfaces") + " and " +
           plural(curves.size(), "curve", "curves");
  if(!inside.empty()) _built += "\n" + inside;
  if(recognize) {
    char tol[64];
    snprintf(tol, sizeof(tol), "%g", tolerance);
    const std::string found =
      plural(recognized[1], "plane", "planes") + ", " +
      plural(recognized[2], "sphere", "spheres") + ", " +
      plural(recognized[3], "cylinder", "cylinders") + ", " +
      plural(recognized[4], "cone", "cones") + " and " +
      plural(recognized[5], "torus", "tori") + " within " + tol + " (" +
      given + ")";
    _built += "\n" + found;
    Msg::Info("Discrete CAD triangulation: %s, precision of the coordinates %g",
              found.c_str(), precision);
  }
  _changed = true;
  return true;
}

bool DiscreteCAD_Internals::addTriangulation(
  const std::vector<double> &coord, const std::vector<std::size_t> &triangles,
  const std::vector<int> &pieces, double angle, double curveAngle,
  double tolerance, std::vector<std::pair<int, int> > &outDimTags)
{
  outDimTags.clear();
  std::vector<std::array<int, 3> > tri;
  std::vector<int> piece, label;
  if(!_mergeNodes(coord, triangles, pieces, tri, piece) ||
     !_cleanTriangles(tri, piece))
    return false;
  std::set<std::pair<int, int> > barrier;
  _patches(tri, piece, angle, label, barrier);
  return _build(tri, label, barrier, angle, curveAngle, tolerance, true,
                outDimTags);
}

bool DiscreteCAD_Internals::_readTriangulations(
  const std::string &fileName, std::vector<double> &coord,
  std::vector<std::size_t> &triangles, std::vector<int> &pieces)
{
  coord.clear();
  triangles.clear();
  pieces.clear();
  std::string ext = SplitFileName(fileName)[2];
  std::transform(ext.begin(), ext.end(), ext.begin(), ::tolower);

  std::size_t others = 0;
  int status = 0;
  {
    // the file read in a temporary model (destroyed before the topology is
    // built)
    TemporaryModel tmp;
    GModel *model = tmp.model;
    // a boundary representation: the triangulations of its faces made by
    // OpenCASCADE (Mesh.StlLinearDeflection, Mesh.StlAngularDeflection), the
    // nodes of their common curves merged by their coordinates
    const bool brep = ext == ".brep" || ext == ".step" || ext == ".stp" ||
                      ext == ".iges" || ext == ".igs";
    if(ext == ".brep")
      status = model->readOCCBREP(fileName);
    else if(ext == ".step" || ext == ".stp")
      status = model->readOCCSTEP(fileName);
    else if(ext == ".iges" || ext == ".igs")
      status = model->readOCCIGES(fileName);
    else if(ext == ".stl")
      status = model->readSTL(fileName, CTX::instance()->geom.tolerance);
    else if(ext == ".msh")
      status = model->readMSH(fileName);
    else if(ext == ".obj")
      status = model->readOBJ(fileName);
    else if(ext == ".ply")
      status = model->readPLY(fileName);
    else if(ext == ".off")
      status = model->readOFF(fileName);
    else if(ext == ".vtk")
      status = model->readVTK(fileName, CTX::instance()->bigEndian);
    else if(ext == ".mesh")
      status = model->readMESH(fileName);
    else
      Msg::Error("Discrete CAD import: unknown format of '%s'",
                 fileName.c_str());

#if defined(HAVE_OCC) && OCC_VERSION_HEX > 0x070300
    if(brep && status) {
      // its faces triangulated together, so that two faces share the nodes of
      // their common curves (one by one, they do not: cracks, T-junctions);
      // each face then keeps its triangulation below
      TopoDS_Compound all;
      BRep_Builder builder;
      builder.MakeCompound(all);
      for(auto it = model->firstFace(); it != model->lastFace(); ++it)
        if((*it)->getNativeType() == GEntity::OpenCascadeModel)
          builder.Add(all, *(const TopoDS_Face *)(*it)->getNativePtr());
      BRepMesh_IncrementalMesh(all, CTX::instance()->mesh.stlLinearDeflection,
                               CTX::instance()->mesh.stlLinearDeflectionRelative,
                               CTX::instance()->mesh.stlAngularDeflection, true);
    }
#endif

    // the triangles of its surfaces, each surface a piece
    std::map<MVertex *, std::size_t> index;
    int count = 0;
    for(auto it = model->firstFace(); it != model->lastFace(); ++it, ++count) {
      GFace *gf = *it;
      if(brep) {
        std::vector<SPoint3> xyz;
        std::vector<int> tri;
        if(!faceTriangulation(gf, xyz, tri)) {
          Msg::Warning("Discrete CAD import: no triangulation of surface %d "
                       "of '%s'",
                       gf->tag(), fileName.c_str());
          continue;
        }
        const std::size_t first = coord.size() / 3;
        for(const SPoint3 &p : xyz) {
          coord.push_back(p.x());
          coord.push_back(p.y());
          coord.push_back(p.z());
        }
        for(std::size_t i = 0; i + 2 < tri.size(); i += 3) {
          for(int k = 0; k < 3; k++) triangles.push_back(first + tri[i + k]);
          pieces.push_back(count);
        }
        continue;
      }
      for(MTriangle *t : gf->triangles) {
        for(int k = 0; k < 3; k++) {
          MVertex *v = t->getVertex(k);
          auto r = index.insert({v, index.size()});
          if(r.second) {
            coord.push_back(v->x());
            coord.push_back(v->y());
            coord.push_back(v->z());
          }
          triangles.push_back(r.first->second);
        }
        pieces.push_back(count);
      }
      others += gf->quadrangles.size() + gf->polygons.size();
    }
  }
  if(!status) return false;
  if(others)
    Msg::Warning("Discrete CAD import: %lu surface elements other than "
                 "triangles ignored in '%s'",
                 others, fileName.c_str());
  if(triangles.empty()) {
    Msg::Error("Discrete CAD import: no triangles in '%s'", fileName.c_str());
    return false;
  }
  return true;
}

bool DiscreteCAD_Internals::importShapes(
  const std::string &fileName, double angle, double curveAngle,
  double tolerance, std::vector<std::pair<int, int> > &outDimTags)
{
  outDimTags.clear();
  std::vector<double> coord;
  std::vector<std::size_t> triangles;
  std::vector<int> pieces;
  stepReport report{_reports, "Failed (see the messages)"};
  if(!_readTriangulations(fileName, coord, triangles, pieces)) return false;
  if(!addTriangulation(coord, triangles, pieces, angle, curveAngle, tolerance,
                       outDimTags))
    return false;
  report.text = _built;
  return true;
}

bool DiscreteCAD_Internals::importTriangulations(
  const std::string &fileName, std::vector<std::pair<int, int> > &outDimTags)
{
  outDimTags.clear();
  std::vector<double> coord;
  std::vector<std::size_t> triangles;
  std::vector<int> pieces;
  stepReport report{_reports, "Failed (see the messages)"};
  if(!_readTriangulations(fileName, coord, triangles, pieces)) return false;
  std::vector<std::array<int, 3> > tri;
  std::vector<int> piece;
  if(!_mergeNodes(coord, triangles, pieces, tri, piece)) return false;
  std::map<int, std::vector<std::array<int, 3> > > trianglesOf;
  for(std::size_t i = 0; i < tri.size(); i++)
    trianglesOf[piece[i]].push_back(tri[i]);
  for(auto &p : trianglesOf) {
    int t = -1;
    _assignTag(2, t);
    Surface &sf = _surfaces[t];
    sf.triangles = p.second;
    sf.raw = true;
    outDimTags.push_back({2, t});
  }
  std::set<int> nodes;
  for(auto &t : tri) nodes.insert(t.begin(), t.end());
  report.text = plural(tri.size(), "triangle", "triangles") + " and " +
                plural(nodes.size(), "node", "nodes") + " read, in " +
                plural(trianglesOf.size(), "triangulation", "triangulations") +
                " (the surfaces of the file)";
  Msg::Info("Discrete CAD import: %s", report.text.c_str());

  // their defects, and their pieces
  DiscreteCADDefects d;
  findDefects(_nodes, tri, d);
  auto ofTriangles = [&](const std::vector<std::size_t> &which) {
    std::vector<int> n;
    for(std::size_t i : which) n.insert(n.end(), tri[i].begin(), tri[i].end());
    return n;
  };
  auto ofEdges = [&](const std::vector<std::pair<int, int> > &which) {
    std::vector<int> n;
    for(auto &e : which) {
      n.push_back(e.first);
      n.push_back(e.second);
    }
    return n;
  };
  report.add(plural(d.degenerate.size(), "degenerate triangle",
                    "degenerate triangles") + " (two nodes the same)",
             2, ofTriangles(d.degenerate));
  report.add(plural(d.duplicated.size(), "duplicated triangle",
                    "duplicated triangles") + " (the nodes of another one)",
             2, ofTriangles(d.duplicated));
  report.add(plural(d.needles.size(), "needle", "needles") +
               " (no area, or an angle smaller than a degree)",
             2, ofTriangles(d.needles));
  report.add(plural(d.free.size(), "free edge", "free edges") +
               " (of one triangle: holes and gaps)",
             1, ofEdges(d.free));
  report.add(plural(d.nonManifold.size(), "non-manifold edge",
                    "non-manifold edges") + " (of more than two triangles)",
             1, ofEdges(d.nonManifold));
  report.add(plural(d.misoriented.size(), "edge", "edges") +
               " between triangles of opposite orientations",
             1, ofEdges(d.misoriented));
  report.add(plural(d.tJunctions.size(), "T-junction", "T-junctions") +
               " (a node inside an edge of other triangles)",
             0, d.tJunctions);
  std::vector<int> closedNodes, openNodes;
  std::vector<double> closedValues, openValues;
  for(std::size_t i = 0; i < tri.size(); i++) {
    const int p = d.piece[i];
    if(p < 0) continue;
    std::vector<int> &n = d.closed[p] ? closedNodes : openNodes;
    n.insert(n.end(), tri[i].begin(), tri[i].end());
    (d.closed[p] ? closedValues : openValues).push_back(scattered(p));
  }
  int closed = 0;
  for(char c : d.closed) closed += c;
  const int open = (int)d.closed.size() - closed;
  report.add(plural(closed, "closed piece", "closed pieces") +
               " (triangles connected by their edges, without free or "
               "non-manifold edge)",
             2, closedNodes, closedValues);
  report.add(plural(open, "open piece", "open pieces"), 2, openNodes,
             openValues);
  const std::string defects =
    plural(d.degenerate.size(), "degenerate", "degenerate") + ", " +
    plural(d.duplicated.size(), "duplicated triangle", "duplicated triangles") +
    ", " + plural(d.needles.size(), "needle", "needles") + "; " +
    plural(d.free.size(), "free edge", "free edges") + ", " +
    plural(d.nonManifold.size(), "non-manifold edge", "non-manifold edges") +
    ", " +
    plural(d.misoriented.size(), "edge", "edges") +
    " between opposite orientations, " +
    plural(d.tJunctions.size(), "T-junction", "T-junctions");
  const std::string piecesText = plural(d.closed.size(), "piece", "pieces") +
                             ": " + std::to_string(closed) + " closed, " +
                             std::to_string(open) + " open";
  report.text += "\n" + defects + "\n" + piecesText;
  Msg::Info("Discrete CAD import: %s", defects.c_str());
  Msg::Info("Discrete CAD import: %s", piecesText.c_str());
  _changed = true;
  return true;
}

// the raw surfaces among tags, all of them if tags is empty (an error for the
// others)
static bool rawSurfaces(const std::map<int, DiscreteCAD_Internals::Surface> &s,
                        const std::vector<int> &tags, const char *what,
                        std::vector<int> &raw)
{
  if(tags.empty())
    for(auto &it : s)
      if(it.second.raw) raw.push_back(it.first);
  std::set<int> seen;
  for(int t : tags) {
    auto it = s.find(t);
    if(it == s.end() || !it->second.raw) {
      Msg::Error("Discrete CAD %s: surface %d is not a triangulation as read "
                 "(see importTriangulations)",
                 what, t);
      return false;
    }
    if(seen.insert(t).second) raw.push_back(t);
  }
  if(raw.empty()) {
    Msg::Error("Discrete CAD %s: no surfaces", what);
    return false;
  }
  return true;
}

bool DiscreteCAD_Internals::heal(const std::vector<int> &surfaceTags,
                                 double tolerance)
{
  stepReport report{_reports, "Failed (see the messages)"};
  std::vector<int> raw;
  if(!rawSurfaces(_surfaces, surfaceTags, "heal", raw)) return false;
  std::vector<std::array<int, 3> > tri;
  std::vector<int> surfaceOf;
  for(int s : raw)
    for(auto &t : _surfaces[s].triangles) {
      tri.push_back(t);
      surfaceOf.push_back(s);
    }
  // (each stage said when it starts, but the first one, and what it did when
  // it is done, with its time)
  const double wall = TimeOfDay(), cpu = Cpu();
  double stage = wall;
  auto done = [&](const std::string &what) {
    const double now = TimeOfDay();
    Msg::Info("Discrete CAD heal: %s (Wall %gs)", what.c_str(), now - stage);
    stage = now;
  };
  Msg::StatusBar(true, "Healing %s of %s...",
                 plural(tri.size(), "triangle", "triangles").c_str(),
                 plural(raw.size(), "triangulation", "triangulations").c_str());

  // the degenerate and duplicated triangles removed
  DiscreteCADHealReport r;
  std::vector<std::size_t> kept;
  removeBadTriangles(tri, r, &kept);
  {
    std::vector<int> degenerate, duplicated;
    std::vector<char> isKept(surfaceOf.size(), 0);
    for(std::size_t i : kept) isKept[i] = 1;
    std::size_t i = 0;
    for(int s : raw)
      for(auto &t : _surfaces[s].triangles) {
        if(isKept[i++]) continue;
        std::vector<int> &n = isDegenerate(t) ? degenerate : duplicated;
        n.insert(n.end(), t.begin(), t.end());
      }
    report.add(plural(degenerate.size() / 3, "degenerate triangle",
                      "degenerate triangles") + " removed",
               2, degenerate);
    report.add(plural(duplicated.size() / 3, "duplicated triangle",
                      "duplicated triangles") + " removed",
               2, duplicated);
  }
  std::string removed =
    plural(r.degenerate, "degenerate triangle", "degenerate triangles") +
    " (two nodes the same) and " +
    plural(r.duplicated, "duplicated triangle", "duplicated triangles") +
    " (the same three nodes) removed";
  done(removed);

  // the triangles oriented
  Msg::Info("Discrete CAD heal: orienting the triangles as their neighbors, "
            "then the pieces outwards (the open ones by the winding "
            "number)...");
  std::vector<int> component;
  std::vector<char> turnedOver;
  orientTriangles(_nodes, tri, r, &component, &turnedOver);
  const std::string pieces =
    plural(r.components, "piece", "pieces") +
    " (triangles connected by their edges): " + std::to_string(r.closed) +
    " closed, " + std::to_string(r.components - r.closed) + " open";
  std::string turned;
  if(!r.reversedTriangles)
    turned = "no triangle turned over: all were oriented consistently";
  else
    turned = plural(r.reversedTriangles, "triangle", "triangles") +
             " turned over: those against their neighbors, and " +
             plural(r.reversedClosed, "closed piece", "closed pieces") +
             " of negative volume and " +
             plural(r.reversedOpen, "open piece", "open pieces") +
             " against the winding number of the others";
  Msg::Info("Discrete CAD heal: %s", pieces.c_str());
  done(turned);

  // the triangles bounding no volume, outside all of them, removed (on other
  // triangles the other way: the winding number about 0 on their two sides);
  // the volumes overlapping or touching others kept as they are, the parts of
  // their fragments
  Msg::Info("Discrete CAD heal: the triangles bounding no volume, by the "
            "winding number on their two sides...");
  std::string nothing;
  {
    std::vector<char> none;
    std::vector<double> behind, front;
    boundingNothing(_nodes, tri, none, &behind, &front);
    // (what the winding number says of the triangles kept: its value behind
    // each one; those inside other volumes too, and those it would turn over)
    std::vector<int> gone, all, inside, against;
    std::vector<double> allValues, insideValues, againstValues;
    for(std::size_t i = 0; i < tri.size(); i++) {
      if(none[i] || std::isnan(behind[i])) continue;
      all.insert(all.end(), tri[i].begin(), tri[i].end());
      allValues.push_back(behind[i]);
      if(behind[i] > 1.5) {
        inside.insert(inside.end(), tri[i].begin(), tri[i].end());
        insideValues.push_back(behind[i]);
      }
      if(front[i] - behind[i] > 0.5) {
        against.insert(against.end(), tri[i].begin(), tri[i].end());
        againstValues.push_back(behind[i] - front[i]);
      }
    }
    std::size_t j = 0;
    for(std::size_t i = 0; i < tri.size(); i++) {
      if(none[i]) {
        gone.insert(gone.end(), tri[i].begin(), tri[i].end());
        continue;
      }
      tri[j] = tri[i];
      kept[j] = kept[i];
      component[j] = component[i];
      turnedOver[j] = turnedOver[i];
      j++;
    }
    tri.resize(j);
    kept.resize(j);
    component.resize(j);
    turnedOver.resize(j);
    nothing = gone.empty() ? std::string("no triangle bounding no volume") :
                             plural(gone.size() / 3, "triangle", "triangles") +
                               " bounding no volume removed (on others the "
                               "other way, outside the volumes)";
    report.add(plural(gone.size() / 3, "triangle bounding no volume",
                      "triangles bounding no volume") +
                 " removed",
               2, gone);
    report.add("the winding number just behind the triangles (1 on the "
               "boundary of a volume, 1/2 on a sheet, 2 inside another volume "
               "too)",
               2, all, allValues);
    report.add(plural(inside.size() / 3, "triangle", "triangles") +
                 " inside other volumes too (overlapping or touching: the "
                 "winding number 2 or more behind), kept as parts of their "
                 "fragments",
               2, inside, insideValues);
    report.add(plural(against.size() / 3, "triangle", "triangles") +
                 " against the winding number (larger in front), left as "
                 "they are",
               2, against, againstValues);
  }
  done(nothing);

  // the open pieces bounding volumes
  Msg::Info("Discrete CAD heal: the open pieces bounding volumes, by the "
            "winding number of their triangles...");
  std::vector<char> kind;
  componentKinds(_nodes, tri, component, kind);
  std::map<char, int> kinds;
  for(char k : kind) kinds[k]++;
  const std::string open =
    r.components == r.closed ?
      std::string("no open piece") :
      plural(r.components - r.closed, "open piece", "open pieces") + ": " +
        std::to_string(kinds['v'] + kinds['w']) + " bounding volumes (" +
        std::to_string(kinds['v']) + " alone, with holes, " +
        std::to_string(kinds['w']) + " with other pieces), " +
        plural(kinds['s'], "sheet", "sheets") + ", " +
        std::to_string(kinds['o']) + " other";
  done(open);

  // the tolerance
  Msg::Info("Discrete CAD heal: the distances across the cracks, for the "
            "tolerance...");
  std::string proposed;
  std::map<int, int> distances;
  const double tolerance0 = zipTolerance(_nodes, tri, &proposed, &distances);
  char tol[64];
  if(tolerance > 0.) {
    snprintf(tol, sizeof(tol), "%g", tolerance);
    done("tolerance " + std::string(tol) + " given (" + proposed + ")");
    proposed.clear();
  }
  else {
    tolerance = tolerance0;
    done(proposed);
  }

  // the volumes closed within the tolerance: the cracks zipped as a
  // filtration (its events up to twice the length of the free edges, for
  // other tolerances), its events kept for the pieces it closes within the
  // tolerance; the cracks of each other piece zipped within it, the piece
  // alone (never sewn to another one)
  snprintf(tol, sizeof(tol), "%g", tolerance);
  Msg::Info("Discrete CAD heal: closing the volumes within %s...", tol);
  const std::vector<std::array<int, 3> > unzipped = tri;
  DiscreteCADZipReport z;
  std::vector<std::size_t> zipped;
  zipFreeEdges(_nodes, tri, tolerance, z, &zipped, 2.);
  auto closes = [&](std::size_t i) {
    return z.closedLevel[i] > 0. && z.closedLevel[i] <= tolerance;
  };
  std::vector<std::array<int, 3> > shells;
  std::vector<std::size_t> shellFrom;
  for(std::size_t j = 0; j < tri.size(); j++)
    if(closes(zipped[j])) {
      shells.push_back(tri[j]);
      shellFrom.push_back(zipped[j]);
    }
  // (the shells oriented again, should pieces closed together have been
  // oriented against each other)
  DiscreteCADHealReport rs;
  std::vector<char> turnedShell;
  orientTriangles(_nodes, shells, rs, nullptr, &turnedShell);
  // (the triangles of the shells, then those of the other pieces: the
  // triangle of the input each one comes from, and why it ends turned over;
  // the nodes merged and inserted, the pieces of the shells, the other
  // pieces closed alone)
  std::vector<std::size_t> from;
  std::vector<char> why;
  tri.clear();
  for(std::size_t j = 0; j < shells.size(); j++) {
    const char a = turnedOver[shellFrom[j]], b = turnedShell[j];
    tri.push_back(shells[j]);
    from.push_back(shellFrom[j]);
    why.push_back(a && b ? 0 : b ? b : a);
  }
  std::vector<char> inShell(_nodes.size(), 0);
  std::set<int> shellPieces;
  std::vector<std::vector<std::size_t> > members(kind.size());
  for(std::size_t i = 0; i < unzipped.size(); i++)
    if(closes(i)) {
      for(int n : unzipped[i]) inShell[n] = 1;
      shellPieces.insert(component[i]);
    }
    else
      members[component[i]].push_back(i);
  std::vector<int> mergedNodes, insertedNodes;
  for(int n : z.merged)
    if(inShell[n]) mergedNodes.push_back(n);
  for(int n : z.inserted)
    if(inShell[n]) insertedNodes.push_back(n);
  std::vector<char> closedAlone(kind.size(), 0), filled(kind.size(), 0);
  int filledPieces = 0, filledLoops = 0, loopsLeft = 0;
  std::vector<int> fillNodes;
  for(std::size_t c = 0; c < members.size(); c++) {
    if(members[c].empty()) continue;
    std::vector<std::array<int, 3> > t;
    for(std::size_t i : members[c]) t.push_back(unzipped[i]);
    std::vector<std::size_t> o(t.size());
    for(std::size_t j = 0; j < t.size(); j++) o[j] = j;
    if(kind[c] != 'c') {
      DiscreteCADZipReport zc;
      zipFreeEdges(_nodes, t, tolerance, zc, &o, 0.);
      mergedNodes.insert(mergedNodes.end(), zc.merged.begin(), zc.merged.end());
      insertedNodes.insert(insertedNodes.end(), zc.inserted.begin(),
                           zc.inserted.end());
      if(zc.closedLevel[0] > 0. && zc.closedLevel[0] <= tolerance)
        closedAlone[c] = 1;
    }
    // (the holes of a piece bounding a volume alone, still open, closed
    // whatever their size: each loop of its free edges triangulated without
    // new nodes, the geometry of the piece as it is)
    const std::size_t before = t.size();
    if(kind[c] == 'v' && !closedAlone[c]) {
      std::vector<std::array<int, 3> > added;
      std::vector<std::size_t> beside;
      int loops = 0, left = 0;
      fillHoles(_nodes, t, added, beside, loops, left);
      for(std::size_t k = 0; k < added.size(); k++) {
        t.push_back(added[k]);
        o.push_back(o[beside[k]]);
        fillNodes.insert(fillNodes.end(), added[k].begin(), added[k].end());
      }
      filledLoops += loops;
      loopsLeft += left;
      if(loops) filledPieces++;
      if(loops && !left) filled[c] = 1;
    }
    for(std::size_t j = 0; j < t.size(); j++) {
      tri.push_back(t[j]);
      from.push_back(members[c][o[j]]);
      why.push_back(j < before ? turnedOver[from.back()] : 0);
    }
  }
  // (the pieces bounding volumes left open, by the level from which the
  // zipping closes them)
  std::map<int, double> openFrom;
  std::map<int, std::size_t> openSize;
  for(std::size_t i = 0; i < unzipped.size(); i++) {
    const int c = component[i];
    if(closes(i) || closedAlone[c] || filled[c] ||
       (kind[c] != 'v' && kind[c] != 'w'))
      continue;
    auto it = openFrom.insert({c, z.closedLevel[i]}).first;
    it->second = std::min(it->second, z.closedLevel[i]);
    openSize[c]++;
  }
  std::vector<std::pair<double, int> > nearest;
  for(auto &o : openFrom)
    if(o.second <= z.reach) nearest.push_back({o.second, o.first});
  std::sort(nearest.begin(), nearest.end());
  int alone = 0;
  for(char a : closedAlone) alone += a;
  std::string closing =
    plural(rs.closed + alone, "closed piece", "closed pieces") + " made of " +
    plural(shellPieces.size() + alone, "open piece", "open pieces") +
    ", the cracks of the others zipped, each piece alone (" +
    plural(mergedNodes.size(), "node", "nodes") + " merged, " +
    plural(insertedNodes.size(), "node", "nodes") +
    " inserted into free edges in all)";
  if(rs.reversedTriangles)
    closing += ", " +
               plural(rs.reversedTriangles, "triangle", "triangles") +
               " of them turned over again";
  if(filledPieces || loopsLeft) {
    closing += "; the holes of " +
               plural(filledPieces, "piece bounding a volume alone",
                      "pieces bounding volumes alone") +
               " closed (" + plural(filledLoops, "loop", "loops") + ", " +
               plural(fillNodes.size() / 3, "triangle", "triangles") + ")";
    if(loopsLeft)
      closing += ", " + plural(loopsLeft, "loop", "loops") +
                 " of free edges not closed";
  }
  closing += "; " +
             plural(openFrom.size(), "piece bounding a volume",
                    "pieces bounding volumes") +
             " left open";
  if(!openFrom.empty()) {
    closing += ":";
    if(!nearest.empty()) {
      closing += " " + std::to_string(nearest.size()) + " closing from";
      for(std::size_t k = 0; k < nearest.size() && k < 3; k++) {
        char level[64];
        snprintf(level, sizeof(level), "%g", nearest[k].first);
        closing += std::string(k ? ", " : " ") + level + " (" +
                   plural(openSize[nearest[k].second], "triangle",
                          "triangles") +
                   ")";
      }
      if(nearest.size() > 3) closing += ", ...";
    }
    if(openFrom.size() > nearest.size()) {
      char reach[64];
      snprintf(reach, sizeof(reach), "%g", z.reach);
      closing += std::string(nearest.empty() ? " " : ", ") +
                 std::to_string(openFrom.size() - nearest.size()) +
                 " not within " + reach;
    }
  }
  if(!z.freeBefore) closing = "nothing to close: no free edge";
  const std::string cracks =
    "volumes closed within " + std::string(tol) +
    (proposed.empty() ? std::string("") : " (" + proposed + ")") + ": " +
    closing;
  done(closing);
  {
    DiscreteCAD_Internals::Zip &zip = report.zip;
    zip.tolerance = tolerance;
    zip.proposed = tolerance0;
    zip.reach = z.reach;
    if(!distances.empty()) {
      zip.first = distances.begin()->first;
      zip.counts.assign(distances.rbegin()->first - zip.first + 1, 0);
      for(auto &d : distances) zip.counts[d.first - zip.first] = d.second;
    }
    int merged = 0, inserted = 0, refused = 0;
    auto step = [&](double level, int free, int open, int closed) {
      zip.levels.push_back(level);
      zip.free.push_back(free);
      zip.open.push_back(open);
      zip.closed.push_back(closed);
      zip.merged.push_back(merged);
      zip.inserted.push_back(inserted);
      zip.refused.push_back(refused);
    };
    step(0., (int)z.freeBefore, z.open, z.closed);
    DiscreteCAD_Internals::ReportItem edges{"free edges", 1, {}, z.freeLevel},
      nodes{"nodes merged", 1, {}, {}}, points{"nodes inserted", 0, {}, {}},
      no{"merges and insertions refused", 1, {}, {}},
      closed{"pieces closed", 2, {}, {}};
    for(auto &e : z.freeEdges) edges.nodes.insert(edges.nodes.end(), {e.first, e.second});
    auto d2 = [&](int a, int b) {
      double d = 0.;
      for(int k = 0; k < 3; k++)
        d += (_nodes[a][k] - _nodes[b][k]) * (_nodes[a][k] - _nodes[b][k]);
      return d;
    };
    for(auto &e : z.events) {
      if(e.kind == 'm') {
        merged++;
        nodes.nodes.insert(nodes.nodes.end(), {e.a, e.b});
        nodes.values.push_back(e.level);
      }
      else if(e.kind == 't') {
        inserted++;
        points.nodes.push_back(e.a);
        points.values.push_back(e.level);
      }
      else {
        refused++;
        no.nodes.insert(no.nodes.end(),
                        {e.a, e.c >= 0 && d2(e.a, e.c) < d2(e.a, e.b) ? e.c : e.b});
        no.values.push_back(e.level);
      }
      step(e.level, e.free, e.open, e.closed);
    }
    for(std::size_t i = 0; i < unzipped.size(); i++)
      if(z.closedLevel[i] > 0. && z.closedLevel[i] <= z.reach) {
        closed.nodes.insert(closed.nodes.end(), unzipped[i].begin(),
                            unzipped[i].end());
        closed.values.push_back(z.closedLevel[i]);
      }
    zip.items = {edges, nodes, points, no, closed};
  }
  {
    std::vector<std::size_t> input(from.size());
    for(std::size_t j = 0; j < from.size(); j++) input[j] = kept[from[j]];
    kept = input;
  }
  for(int s : raw) _surfaces[s].triangles.clear();
  for(std::size_t i = 0; i < tri.size(); i++)
    _surfaces[surfaceOf[kept[i]]].triangles.push_back(tri[i]);
  int emptied = 0;
  for(int s : raw)
    if(_surfaces[s].triangles.empty()) {
      _surfaces.erase(s);
      emptied++;
    }
  if(emptied) {
    const std::string empty =
      plural(emptied, "triangulation", "triangulations") +
      " left empty removed";
    removed += ", " + empty;
    Msg::Info("Discrete CAD heal: %s", empty.c_str());
  }

  // what is left
  Msg::Info("Discrete CAD heal: the defects left...");
  DiscreteCADDefects after;
  findDefects(_nodes, tri, after);
  const std::string left =
    "left: " + plural(after.free.size(), "free edge", "free edges") + ", " +
    plural(after.nonManifold.size(), "non-manifold edge", "non-manifold edges") +
    ", " + plural(after.misoriented.size(), "misoriented edge", "misoriented edges") +
    ", " + plural(after.tJunctions.size(), "T-junction", "T-junctions") + ", " +
    plural(after.needles.size(), "needle", "needles");
  {
    auto ofEdges = [](const std::vector<std::pair<int, int> > &which) {
      std::vector<int> n;
      for(auto &e : which) {
        n.push_back(e.first);
        n.push_back(e.second);
      }
      return n;
    };
    // (the nodes merged and inserted, the free edges left, the triangles
    // turned over)
    report.add(plural(mergedNodes.size(), "node", "nodes") +
                 " of free edges merged into nodes of others (cracks)",
               0, mergedNodes);
    report.add(plural(insertedNodes.size(), "node", "nodes") +
                 " inserted into free edges (T-junctions)",
               0, insertedNodes);
    report.add(plural(fillNodes.size() / 3, "triangle", "triangles") +
                 " closing the holes of pieces bounding volumes alone",
               2, fillNodes);
    report.add(plural(after.free.size(), "free edge", "free edges") +
                 " left (of the volumes not closed within the tolerance, "
                 "and of the sheets)",
               1, ofEdges(after.free));
    static const char *because[4] = {
      "", " turned over against their neighbors",
      " turned over with closed pieces of negative volume",
      " turned over with open pieces against the winding number"};
    for(int w = 1; w <= 3; w++) {
      std::vector<int> n;
      for(std::size_t i = 0; i < tri.size(); i++)
        if(why[i] == w) n.insert(n.end(), tri[i].begin(), tri[i].end());
      report.add(plural(n.size() / 3, "triangle", "triangles") + because[w], 2,
                 n);
    }
    // (the pieces: closed, or open by their kind)
    static const std::string kindNames[5][2] = {
      {"closed piece, oriented outwards (a volume)",
       "closed pieces, oriented outwards (the volumes)"},
      {"open piece bounding a volume alone (holes wider than the tolerance)",
       "open pieces bounding volumes alone (holes wider than the "
       "tolerance)"},
      {"open piece bounding a volume with others (gaps wider than the "
       "tolerance)",
       "open pieces bounding volumes with others (gaps wider than the "
       "tolerance)"},
      {"sheet (an open piece)", "sheets (open pieces)"},
      {"other open piece", "other open pieces"}};
    std::vector<int> nodes[5];
    std::vector<double> values[5];
    std::set<int> counted[5];
    for(std::size_t i = 0; i < tri.size(); i++) {
      const int p = after.piece[i];
      int k = 4, id = p;
      if(p >= 0 && after.closed[p])
        k = 0;
      else {
        id = component[from[i]];
        const char c = kind[id];
        k = c == 'v' ? 1 : c == 'w' ? 2 : c == 's' ? 3 : 4;
        id += (int)after.closed.size();
      }
      nodes[k].insert(nodes[k].end(), tri[i].begin(), tri[i].end());
      values[k].push_back(scattered(id));
      counted[k].insert(id);
    }
    for(int k = 0; k < 5; k++)
      report.add(std::to_string(counted[k].size()) + " " +
                   kindNames[k][counted[k].size() == 1 ? 0 : 1],
                 2, nodes[k], values[k]);
    report.add(plural(after.nonManifold.size(), "non-manifold edge",
                      "non-manifold edges") +
                 " left (of more than two triangles)",
               1, ofEdges(after.nonManifold));
  }
  report.text = removed + "\n" + pieces + "\n" + turned + "\n" + nothing +
                "\n" + open + "\n" + cracks + "\n" + left;
  done(left);
  Msg::StatusBar(true, "Done healing (Wall %gs, CPU %gs)", TimeOfDay() - wall,
                 Cpu() - cpu);
  _changed = true;
  return true;
}

bool DiscreteCAD_Internals::classify(
  const std::vector<int> &surfaceTags, double angle, double curveAngle,
  std::vector<std::pair<int, int> > &outDimTags)
{
  outDimTags.clear();
  stepReport report{_reports, "Failed (see the messages)"};
  std::vector<int> raw;
  if(!rawSurfaces(_surfaces, surfaceTags, "classify", raw)) return false;
  std::vector<std::array<int, 3> > tri;
  std::vector<int> piece, label;
  for(std::size_t p = 0; p < raw.size(); p++)
    for(auto &t : _surfaces[raw[p]].triangles) {
      tri.push_back(t);
      piece.push_back((int)p);
    }
  if(!_cleanTriangles(tri, piece)) return false;
  for(int s : raw) _surfaces.erase(s);
  std::set<std::pair<int, int> > barrier;
  _patches(tri, piece, angle, label, barrier);
  if(!_build(tri, label, barrier, angle, curveAngle, 0., false, outDimTags))
    return false;
  report.text = _built;
  std::vector<int> volumeNodes, freeNodes;
  std::vector<double> volumeValues, freeValues;
  int volumes = 0, free = 0;
  for(auto &dt : outDimTags) {
    if(dt.first == 3) {
      volumes++;
      for(int s : _volumes[dt.second].surfaces)
        for(auto &t : _surfaces[std::abs(s)].triangles) {
          volumeNodes.insert(volumeNodes.end(), t.begin(), t.end());
          volumeValues.push_back(scattered(dt.second));
        }
    }
    else {
      free++;
      for(auto &t : _surfaces[dt.second].triangles) {
        freeNodes.insert(freeNodes.end(), t.begin(), t.end());
        freeValues.push_back(scattered(dt.second));
      }
    }
  }
  report.add(plural(volumes, "volume", "volumes") + " (their surfaces)", 2,
             volumeNodes, volumeValues);
  report.add(plural(free, "surface", "surfaces") + " bounding no volume", 2,
             freeNodes, freeValues);
  // (the curves of the surfaces made, each its color; those embedded in a
  // surface; those along which more than two sides of surfaces meet, the
  // number of sides as value: fragments touching, sheets hanging from
  // surfaces)
  std::set<int> made;
  for(auto &dt : outDimTags) {
    if(dt.first == 3)
      for(int s : _volumes[dt.second].surfaces) made.insert(std::abs(s));
    else if(dt.first == 2)
      made.insert(dt.second);
  }
  std::map<int, int> sides;
  std::set<int> embedded;
  for(int s : made) {
    for(int c : _surfaces[s].curves) sides[std::abs(c)]++;
    for(int c : _surfaces[s].embeddedCurves) {
      sides[c] += 2;
      embedded.insert(c);
    }
  }
  std::vector<int> curveNodes, embeddedNodes, meetNodes;
  std::vector<double> curveValues, embeddedValues, meetValues;
  int meet = 0;
  for(auto &cs : sides) {
    const std::vector<int> &n = _curves[cs.first].nodes;
    if(cs.second > 2) meet++;
    for(std::size_t j = 0; j + 1 < n.size(); j++) {
      curveNodes.insert(curveNodes.end(), {n[j], n[j + 1]});
      curveValues.push_back(scattered(cs.first));
      if(embedded.count(cs.first)) {
        embeddedNodes.insert(embeddedNodes.end(), {n[j], n[j + 1]});
        embeddedValues.push_back(scattered(cs.first));
      }
      if(cs.second > 2) {
        meetNodes.insert(meetNodes.end(), {n[j], n[j + 1]});
        meetValues.push_back(cs.second);
      }
    }
  }
  report.add(plural(sides.size(), "curve", "curves") + " (each its color)", 1,
             curveNodes, curveValues);
  report.add(plural(embedded.size(), "curve", "curves") +
               " embedded in surfaces (the surface on their two sides)",
             1, embeddedNodes, embeddedValues);
  report.add(plural(meet, "curve", "curves") +
               " where more than two sides of surfaces meet (their number)",
             1, meetNodes, meetValues);
  return true;
}

bool DiscreteCAD_Internals::recognize(
  const std::vector<std::pair<int, int> > &dimTags, double tolerance,
  std::vector<std::pair<int, int> > &outDimTags)
{
  outDimTags.clear();
  stepReport report{_reports, "Failed (see the messages)"};
  // the classified surfaces given, and those of the volumes given (all of
  // them if dimTags is empty)
  std::set<int> surfaces;
  if(dimTags.empty())
    for(auto &s : _surfaces)
      if(s.second.classified) surfaces.insert(s.first);
  for(auto &dt : dimTags) {
    if(dt.first == 3 && _volumes.count(dt.second))
      for(int s : _volumes[dt.second].surfaces) surfaces.insert(std::abs(s));
    else if(dt.first == 2 && _surfaces.count(dt.second))
      surfaces.insert(dt.second);
    else {
      Msg::Error("Discrete CAD recognize: no %s %d", entityName(dt.first),
                 dt.second);
      return false;
    }
  }
  if(surfaces.empty()) {
    report.text = "No classified surface to recognize";
    Msg::Info("Discrete CAD recognize: %s", report.text.c_str());
    return true;
  }
  // with those they share curves or volumes with, built again together
  std::map<int, std::vector<int> > surfacesOfCurve, volumesOfSurface;
  for(auto &s : _surfaces) {
    for(int c : s.second.curves) surfacesOfCurve[std::abs(c)].push_back(s.first);
    for(int c : s.second.embeddedCurves) surfacesOfCurve[c].push_back(s.first);
  }
  for(auto &v : _volumes)
    for(int s : v.second.surfaces) volumesOfSurface[std::abs(s)].push_back(v.first);
  std::set<int> volumes;
  std::vector<int> stack(surfaces.begin(), surfaces.end());
  while(!stack.empty()) {
    const int s = stack.back();
    stack.pop_back();
    const Surface &sf = _surfaces[s];
    std::vector<int> next;
    for(int c : sf.curves)
      for(int t : surfacesOfCurve[std::abs(c)]) next.push_back(t);
    for(int c : sf.embeddedCurves)
      for(int t : surfacesOfCurve[c]) next.push_back(t);
    for(int v : volumesOfSurface[s])
      if(volumes.insert(v).second)
        for(int t : _volumes[v].surfaces) next.push_back(std::abs(t));
    for(int t : next)
      if(surfaces.insert(t).second) stack.push_back(t);
  }
  for(int s : surfaces)
    if(!_surfaces[s].classified) {
      Msg::Error("Discrete CAD recognize: surface %d (with the classified "
                 "surfaces given) not made by classify",
                 s);
      return false;
    }

  // their triangles, each one with its surface (as a piece, see _patches,
  // for the sharp edges inside them) and its parameters (kept for those left
  // whole), and the tags of the volumes and of the surfaces by their
  // triangles (their number and the first one), to be kept
  std::vector<std::array<int, 3> > tri;
  std::vector<int> label;
  typedef std::pair<std::size_t, std::array<int, 3> > Signature;
  auto signature = [&](const std::vector<int> &of) {
    Signature g(0, {{INT_MAX, INT_MAX, INT_MAX}});
    for(int s : of)
      for(auto t : _surfaces[std::abs(s)].triangles) {
        std::sort(t.begin(), t.end());
        g.first++;
        g.second = std::min(g.second, t);
      }
    return g;
  };
  std::map<Signature, int> oldSurface, oldVolume;
  std::map<int, std::vector<std::array<std::array<double, 2>, 3> > > charts;
  int piece = 0;
  for(int s : surfaces) {
    const Surface &sf = _surfaces[s];
    for(auto &t : sf.triangles) {
      tri.push_back(t);
      label.push_back(piece);
    }
    if(sf.uv.size() == sf.triangles.size()) charts[piece] = sf.uv;
    piece++;
    oldSurface[signature({s})] = s;
  }
  for(int v : volumes) oldVolume[signature(_volumes[v].surfaces)] = v;
  const Surface &first = _surfaces[*surfaces.begin()];
  const double angle = first.angle, curveAngle = first.curveAngle;
  std::vector<int> patches;
  std::set<std::pair<int, int> > barrier;
  _patches(tri, label, angle, patches, barrier);
  for(int v : volumes) _volumes.erase(v);
  for(int s : surfaces) _surfaces.erase(s);
  _removeUnused();
  std::set<int> before, beforeVolumes;
  for(auto &s : _surfaces) before.insert(s.first);
  for(auto &v : _volumes) beforeVolumes.insert(v.first);
  if(!_build(tri, label, barrier, angle, curveAngle, tolerance, true,
             outDimTags, &report.fit, &charts))
    return false;
  const std::string proposed = fitTolerance(report.fit);

  // (the tags kept)
  std::map<int, int> renamed;
  std::vector<int> made;
  for(auto &s : _surfaces)
    if(!before.count(s.first)) made.push_back(s.first);
  for(int s : made) {
    auto o = oldSurface.find(signature({s}));
    if(o == oldSurface.end() || _surfaces.count(o->second)) continue;
    _surfaces[o->second] = _surfaces[s];
    _surfaces.erase(s);
    renamed[s] = o->second;
  }
  std::vector<int> madeVolumes;
  for(auto &v : _volumes)
    if(!beforeVolumes.count(v.first)) madeVolumes.push_back(v.first);
  for(int v : madeVolumes)
    for(int &s : _volumes[v].surfaces) {
      auto r = renamed.find(std::abs(s));
      if(r != renamed.end()) s = s > 0 ? r->second : -r->second;
    }
  for(int v : madeVolumes) {
    auto o = oldVolume.find(signature(_volumes[v].surfaces));
    if(o == oldVolume.end() || _volumes.count(o->second)) continue;
    _volumes[o->second] = _volumes[v];
    _volumes.erase(v);
    renamed[-v] = -o->second;
  }
  for(auto &dt : outDimTags) {
    auto r = renamed.find(dt.first == 3 ? -dt.second : dt.second);
    if(r != renamed.end()) dt.second = std::abs(r->second);
  }
  std::sort(outDimTags.begin(), outDimTags.end());

  // the faces by the analytic surfaces they are on, a piece of a sphere or a
  // torus counted once for its two halves
  std::set<int> built;
  for(auto &s : _surfaces)
    if(!before.count(s.first)) built.insert(s.first);
  int faces[6] = {0, 0, 0, 0, 0, 0};
  std::vector<int> faceNodes[6];
  std::vector<double> faceValues[6];
  for(int s : built) {
    const Surface &sf = _surfaces[s];
    const int type = sf.analytic.kind == DiscreteCADAnalyticMap::NONE ?
                       0 :
                       (int)sf.analytic.surface.type;
    faces[type]++;
    for(auto &t : sf.triangles) {
      faceNodes[type].insert(faceNodes[type].end(), t.begin(), t.end());
      faceValues[type].push_back(scattered(s));
    }
  }
  report.text = _built + "\n" +
                plural(surfaces.size(), "classified surface",
                       "classified surfaces") +
                " built again: " + std::to_string(faces[1] + faces[2] + faces[3] +
                                                  faces[4] + faces[5]) +
                " faces made exact, " + std::to_string(faces[0]) +
                " left as triangulated\n" + proposed;
  static const char *kinds[6][2] = {{"free form surface", "free form surfaces"},
                                    {"plane", "planes"},
                                    {"sphere", "spheres"},
                                    {"cylinder", "cylinders"},
                                    {"cone", "cones"},
                                    {"torus", "tori"}};
  for(int k = 1; k <= 6; k++) {
    const int type = k % 6;
    report.add(plural(faces[type], "face", "faces") + " on " + kinds[type][1],
               2, faceNodes[type], faceValues[type]);
  }
  Msg::Info("Discrete CAD recognize: %s", report.text.c_str());
  return true;
}

void DiscreteCAD_Internals::synchronize(GModel *model)
{
  // the entities of the previous call, those of highest dimension first (an
  // entity is only removed after those it bounds)
  std::sort(_synchronized.begin(), _synchronized.end(),
            [](const std::pair<int, int> &p, const std::pair<int, int> &q) {
              return p.first > q.first ||
                     (p.first == q.first && p.second < q.second);
            });
  std::vector<GEntity *> removed;
  model->remove(_synchronized, removed);
  for(GEntity *e : removed) delete e;
  _synchronized.clear();

  // the geometry of the entities is computed from a temporary mesh, the
  // polylines and triangulations, deleted afterwards without changing the
  // numbering of the mesh of the model
  const std::size_t maxVertex = model->getMaxVertexNumber();
  const std::size_t maxElement = model->getMaxElementNumber();

  // the exact geometry of the curves along which two analytic surfaces meet
  // at an angle: their intersection, the nodes of their polylines moved onto
  // it; and the vertices moved onto the intersection of the analytic surfaces
  // around them (of three of them, or else two, meeting at the largest angle)
  std::map<int, std::set<int> > surfacesOfCurve, surfacesOfVertex;
  for(auto &it : _surfaces)
    for(int c : it.second.curves) {
      const Curve &cv = _curves[std::abs(c)];
      surfacesOfCurve[std::abs(c)].insert(it.first);
      surfacesOfVertex[cv.v0].insert(it.first);
      surfacesOfVertex[cv.v1].insert(it.first);
    }
  auto analytic = [&](int surface) -> const DiscreteCADAnalyticSurface * {
    const Surface &sf = _surfaces[surface];
    const DiscreteCADAnalyticMap &m = sf.analytic;
    return m.kind == DiscreteCADAnalyticMap::NONE ? nullptr : &m.surface;
  };
  std::map<int, std::array<double, 3> > exact;
  for(auto &it : _vertices) {
    std::vector<const DiscreteCADAnalyticSurface *> s;
    for(int f : surfacesOfVertex[it.first])
      if(analytic(f)) s.push_back(analytic(f));
    const double *p = _nodes[it.second.node].data();
    // (the sets of three, then two, surfaces by decreasing angle at p)
    std::vector<std::array<double, 3> > n(s.size());
    for(std::size_t i = 0; i < s.size(); i++) s[i]->normal(p, n[i].data());
    using Set = std::pair<std::pair<int, double>, std::vector<std::size_t> >;
    std::vector<Set> sets;
    for(std::size_t i = 0; i < s.size(); i++)
      for(std::size_t j = i + 1; j < s.size(); j++) {
        const std::array<double, 3> &a = n[i], &b = n[j];
        const double c[3] = {a[1] * b[2] - a[2] * b[1],
                             a[2] * b[0] - a[0] * b[2],
                             a[0] * b[1] - a[1] * b[0]};
        sets.push_back(
          {{2, std::sqrt(c[0] * c[0] + c[1] * c[1] + c[2] * c[2])}, {i, j}});
        for(std::size_t k = j + 1; k < s.size(); k++)
          sets.push_back({{3, std::abs(c[0] * n[k][0] + c[1] * n[k][1] +
                                       c[2] * n[k][2])},
                          {i, j, k}});
      }
    std::sort(sets.begin(), sets.end(),
              [](const Set &a, const Set &b) { return a.first > b.first; });
    for(auto &set : sets) {
      std::vector<const DiscreteCADAnalyticSurface *> ss;
      for(std::size_t i : set.second) ss.push_back(s[i]);
      std::array<double, 3> x;
      if(intersectSurfaces(ss, p, nullptr, x.data()) &&
         isIntersectionNear(ss, p, x.data())) {
        exact[it.second.node] = x;
        break;
      }
    }
  }
  auto position = [&](int n) -> const std::array<double, 3> & {
    auto it = exact.find(n);
    return it == exact.end() ? _nodes[n] : it->second;
  };
  std::map<int, std::array<const DiscreteCADAnalyticSurface *, 2> >
    intersections;
  for(auto &it : _curves) {
    const std::set<int> &f = surfacesOfCurve[it.first];
    if(f.size() != 2) continue;
    const std::vector<const DiscreteCADAnalyticSurface *> s = {
      analytic(*f.begin()), analytic(*f.rbegin())};
    if(!s[0] || !s[1]) continue;
    // (the nodes in the planes normal to the polyline through them)
    const std::vector<int> &nodes = it.second.nodes;
    std::vector<std::array<double, 3> > x(nodes.size());
    bool found = nodes.size() >= 2;
    for(std::size_t i = 0; i < nodes.size() && found; i++) {
      const std::array<double, 3> &p = position(nodes[i]),
                                  &a = position(nodes[i ? i - 1 : i]),
                                  &b = position(
                                    nodes[i + 1 < nodes.size() ? i + 1 : i]);
      double t[3] = {b[0] - a[0], b[1] - a[1], b[2] - a[2]};
      normalize(t);
      found = intersectSurfaces(s, p.data(), t, x[i].data()) &&
              isIntersectionNear(s, p.data(), x[i].data());
    }
    if(!found) continue;
    for(std::size_t i = 1; i + 1 < nodes.size(); i++) exact[nodes[i]] = x[i];
    intersections[it.first] = {{s[0], s[1]}};
  }
  Msg::Debug("Discrete CAD: %lu of %lu curves on the intersection of two "
             "analytic surfaces, %lu nodes moved onto intersections",
             intersections.size(), _curves.size(), exact.size());

  std::vector<MVertex *> mesh(_nodes.size(), nullptr);
  auto node = [&](int n, GEntity *e) {
    if(!mesh[n]) {
      const std::array<double, 3> &x = position(n);
      mesh[n] = new MVertex(x[0], x[1], x[2], e);
      e->mesh_vertices.push_back(mesh[n]);
    }
    return mesh[n];
  };
  auto taken = [&](int dim, int tag) {
    if(!model->getEntityByTag(dim, tag)) return false;
    Msg::Error("The model already has a %s %d: discrete CAD %s %d ignored",
               entityName(dim), tag, entityName(dim), tag);
    return true;
  };
  std::vector<GEntity *> created;
  for(auto &it : _vertices) {
    if(taken(0, it.first)) continue;
    const std::array<double, 3> &x = position(it.second.node);
    discreteVertex *gv =
      new discreteVertex(model, it.first, x[0], x[1], x[2], false);
    gv->setNativeType(GEntity::DiscreteCADModel);
    model->add(gv);
    node(it.second.node, gv);
    created.push_back(gv);
  }
  for(auto &it : _curves) {
    if(taken(1, it.first)) continue;
    discreteEdge *ge = new discreteEdge(
      model, it.first, model->getVertexByTag(it.second.v0),
      model->getVertexByTag(it.second.v1), false);
    ge->setNativeType(GEntity::DiscreteCADModel);
    model->add(ge);
    const std::vector<int> &n = it.second.nodes;
    for(std::size_t i = 0; i + 1 < n.size(); i++)
      ge->lines.push_back(new MLine(node(n[i], ge), node(n[i + 1], ge)));
    auto in = intersections.find(it.first);
    if(in != intersections.end()) {
      const DiscreteCADAnalyticSurface a = *in->second[0], b = *in->second[1];
      ge->setExactGeometry([a, b](const SPoint3 &p, const SVector3 &t,
                                  SPoint3 &x, SVector3 &tangent,
                                  SVector3 &curvature) {
        const double pp[3] = {p.x(), p.y(), p.z()};
        const double tt[3] = {t.x(), t.y(), t.z()};
        double xx[3], tx[3], kx[3];
        if(!intersectSurfaces({&a, &b}, pp, tt, xx)) return false;
        intersectionCurve(a, b, xx, tt, tx, kx);
        x = SPoint3(xx[0], xx[1], xx[2]);
        tangent = SVector3(tx[0], tx[1], tx[2]);
        curvature = SVector3(kx[0], kx[1], kx[2]);
        return true;
      });
    }
    created.push_back(ge);
  }
  for(auto &it : _surfaces) {
    if(it.second.raw || taken(2, it.first)) continue;
    discreteFace *gf = new discreteFace(model, it.first, false);
    std::vector<int> tags, signs;
    for(int c : it.second.curves) {
      tags.push_back(std::abs(c));
      signs.push_back(c > 0 ? 1 : -1);
    }
    gf->setBoundEdges(tags, signs);
    for(int v : it.second.embeddedVertices) {
      GVertex *gv = model->getVertexByTag(v);
      if(gv) gf->addEmbeddedVertex(gv);
    }
    for(int c : it.second.embeddedCurves) {
      GEdge *ge = model->getEdgeByTag(c);
      if(ge) gf->addEmbeddedEdge(ge);
    }
    gf->setNativeType(GEntity::DiscreteCADModel);
    model->add(gf);
    // without parameters, the parametrization is computed from the mesh
    if(it.second.uv.empty())
      for(auto &t : it.second.triangles)
        gf->triangles.push_back(
          new MTriangle(node(t[0], gf), node(t[1], gf), node(t[2], gf)));
    created.push_back(gf);
  }
  for(auto &it : _volumes) {
    if(taken(3, it.first)) continue;
    discreteRegion *gr = new discreteRegion(model, it.first, false);
    std::vector<int> tags, signs;
    for(int s : it.second.surfaces) {
      tags.push_back(std::abs(s));
      signs.push_back(s > 0 ? 1 : -1);
    }
    gr->setBoundFaces(tags, signs);
    for(int s : it.second.embeddedSurfaces) {
      GFace *gf = model->getFaceByTag(s);
      if(gf) gr->addEmbeddedFace(gf);
    }
    gr->setNativeType(GEntity::DiscreteCADModel);
    model->add(gr);
    created.push_back(gr);
  }
  for(GEntity *e : created) _synchronized.push_back({e->dim(), e->tag()});
  model->createGeometryOfDiscreteEntities(_synchronized);
  std::map<std::pair<int, int>,
           std::vector<const DiscreteCADAnalyticSurface *> >
    segments;
  for(auto &it : intersections) {
    const std::vector<int> &n = _curves[it.first].nodes;
    for(std::size_t i = 0; i + 1 < n.size(); i++)
      segments[std::minmax(n[i], n[i + 1])] = {it.second[0], it.second[1]};
  }
  std::pair<int, int> fitted(0, 0);
  // the parametrizations given with the surfaces, positively oriented (the
  // nodes of a seam twice, with their parameters on each side), those of the
  // analytic surfaces fitted to the curves on intersections
  for(GEntity *e : created) {
    if(e->dim() != 2) continue;
    discreteFace *gf = static_cast<discreteFace *>(e);
    const Surface &sf = _surfaces[e->tag()];
    if(sf.uv.empty()) continue;
    std::map<std::pair<int, std::array<double, 2> >, int> local;
    std::vector<SPoint2> uv;
    std::vector<SPoint3> xyz;
    std::vector<int> triangles, nodeOf;
    double area = 0.;
    for(std::size_t i = 0; i < sf.triangles.size(); i++) {
      for(int k = 0; k < 3; k++) {
        const int n = sf.triangles[i][k];
        const std::array<double, 2> &p = sf.uv[i][k];
        auto it = local.find({n, p});
        if(it == local.end()) {
          it = local.insert({{n, p}, (int)uv.size()}).first;
          const std::array<double, 3> &x = position(n);
          uv.push_back(SPoint2(p[0], p[1]));
          xyz.push_back(SPoint3(x[0], x[1], x[2]));
          nodeOf.push_back(n);
        }
        triangles.push_back(it->second);
      }
      const std::array<double, 2> &a = sf.uv[i][0], &b = sf.uv[i][1],
                                  &c = sf.uv[i][2];
      area += (b[0] - a[0]) * (c[1] - a[1]) - (b[1] - a[1]) * (c[0] - a[0]);
    }
    const double flip = area < 0. ? -1. : 1.;
    for(SPoint2 &p : uv) p = SPoint2(p.x(), flip * p.y());
    // (its parameters and its geometry given by the map of its analytic
    // surface)
    DiscreteCADAnalyticMap map = sf.analytic;
    if(map.kind != DiscreteCADAnalyticMap::NONE) {
      map.setReference(sf.uv);
      const std::pair<int, int> f =
        fitChartToCurves(map, flip, segments, nodeOf, uv, xyz, triangles);
      fitted.first += f.first;
      fitted.second += f.second;
    }
    gf->setParametrization(uv, xyz, triangles);
    // the exact geometry of an analytic surface
    if(map.kind != DiscreteCADAnalyticMap::NONE) {
      gf->setExactGeometry(
        [map, flip](double u, double v) {
          double x[3];
          map.point(u, flip * v, x);
          return SPoint3(x[0], x[1], x[2]);
        },
        [map, flip](double u, double v, SVector3 d[5]) {
          double der[5][3];
          map.derivatives(u, flip * v, der);
          for(int i = 0; i < 5; i++) {
            // (the derivatives once in v change sign with it)
            const double f = (i == 1 || i == 4) ? flip : 1.;
            d[i] = SVector3(f * der[i][0], f * der[i][1], f * der[i][2]);
          }
        },
        [map, flip](const SPoint3 &p, const double *guess) {
          const double x[3] = {p.x(), p.y(), p.z()};
          double g[2], uv[2];
          if(guess) {
            g[0] = guess[0];
            g[1] = flip * guess[1];
          }
          map.parameters(x, guess ? g : nullptr, uv);
          return SPoint2(uv[0], flip * uv[1]);
        });
    }
    // the parameters of its curves on it, from the triangles along them (the
    // two sides of the seam given)
    std::map<std::pair<int, int>, std::size_t> triangleOf;
    for(std::size_t i = 0; i < sf.triangles.size(); i++)
      for(int k = 0; k < 3; k++)
        triangleOf[std::minmax(sf.triangles[i][k],
                               sf.triangles[i][(k + 1) % 3])] = i;
    auto corner = [&](std::size_t i, int n) {
      int k = 0;
      while(k < 2 && sf.triangles[i][k] != n) k++;
      return SPoint2(sf.uv[i][k][0], flip * sf.uv[i][k][1]);
    };
    // (the parameters along each use of a curve, in its direction)
    std::vector<std::vector<SPoint2> > along;
    for(int c : sf.curves) {
      const int tag = std::abs(c);
      along.push_back(std::vector<SPoint2>());
      discreteEdge *de = dynamic_cast<discreteEdge *>(model->getEdgeByTag(tag));
      if(!de) continue;
      auto sm = sf.seams.find(tag);
      if(sm != sf.seams.end()) {
        std::vector<SPoint2> side[2];
        for(int k = 0; k < 2; k++)
          for(const std::array<double, 2> &p : sm->second[k])
            side[k].push_back(SPoint2(p[0], flip * p[1]));
        de->setReparamOnFace(gf, side[0], side[1]);
        along.back() = side[c > 0 ? 0 : 1];
      }
      else {
        const std::vector<int> &n = _curves[tag].nodes;
        std::vector<SPoint2> p(n.size());
        bool found = true;
        for(std::size_t j = 0; j + 1 < n.size() && found; j++) {
          auto it = triangleOf.find(std::minmax(n[j], n[j + 1]));
          if(it == triangleOf.end()) found = false;
          else {
            p[j] = corner(it->second, n[j]);
            p[j + 1] = corner(it->second, n[j + 1]);
          }
        }
        if(!found) continue;
        de->setReparamOnFace(gf, p);
        along.back() = p;
      }
      if(c < 0) std::reverse(along.back().begin(), along.back().end());
    }
    for(int c : sf.embeddedCurves) {
      discreteEdge *de = dynamic_cast<discreteEdge *>(model->getEdgeByTag(c));
      if(!de) continue;
      const std::vector<int> &n = _curves[c].nodes;
      std::vector<SPoint2> p(n.size());
      bool found = true;
      for(std::size_t j = 0; j + 1 < n.size() && found; j++) {
        auto it = triangleOf.find(std::minmax(n[j], n[j + 1]));
        if(it == triangleOf.end()) found = false;
        else {
          p[j] = corner(it->second, n[j]);
          p[j + 1] = corner(it->second, n[j + 1]);
        }
      }
      if(found) de->setReparamOnFace(gf, p);
    }
    if(sf.seams.empty()) continue;
    // the loops of a surface with seams, the curves in their order (the
    // mesher of periodic surfaces follows them), chained by their parameters
    gf->edgeLoops.clear();
    std::vector<bool> used(sf.curves.size(), false);
    for(std::size_t first = 0; first < sf.curves.size(); first++) {
      if(used[first]) continue;
      GEdgeLoop loop;
      std::size_t current = first;
      while(current < sf.curves.size()) {
        used[current] = true;
        const int c = sf.curves[current];
        loop.add(c > 0 ? 1 : -1, model->getEdgeByTag(std::abs(c)));
        if(along[current].empty() || along[first].empty()) break;
        const SPoint2 &end = along[current].back();
        double best = end.distance(along[first].front());
        current = sf.curves.size();
        for(std::size_t j = 0; j < sf.curves.size(); j++) {
          if(used[j] || along[j].empty()) continue;
          const double d = end.distance(along[j].front());
          if(d < best) {
            best = d;
            current = j;
          }
        }
      }
      gf->edgeLoops.push_back(loop);
    }
  }
  Msg::Debug("Discrete CAD: %d edges of the parametrizations fitted to the "
             "curves on intersections, %d left as chords",
             fitted.first, fitted.second);
  for(GEntity *e : created) e->deleteMesh();
  model->resetMaxVertexNumber(maxVertex);
  model->resetMaxElementNumber(maxElement);
  // the raw surfaces: their triangulations, as meshes without geometry
  for(auto &it : _surfaces) {
    if(!it.second.raw || taken(2, it.first)) continue;
    discreteFace *gf = new discreteFace(model, it.first, false);
    gf->setNativeType(GEntity::DiscreteCADModel);
    model->add(gf);
    std::map<int, MVertex *> vertexOf;
    for(auto &t : it.second.triangles) {
      MVertex *v[3];
      for(int k = 0; k < 3; k++) {
        MVertex *&mv = vertexOf[t[k]];
        if(!mv) {
          const std::array<double, 3> &x = _nodes[t[k]];
          mv = new MVertex(x[0], x[1], x[2], gf);
          gf->mesh_vertices.push_back(mv);
        }
        v[k] = mv;
      }
      gf->triangles.push_back(new MTriangle(v[0], v[1], v[2]));
    }
    _synchronized.push_back({2, it.first});
  }
  _changed = false;
  // the bounding box of the model (and its characteristic length), as the
  // other kernels
  SetBoundingBox();
}
