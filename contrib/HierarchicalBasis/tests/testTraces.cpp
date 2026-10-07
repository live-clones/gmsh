// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// The traces of the basis functions on the vertices, edges and faces of the
// element: the trace (value for H1, tangential components for H(curl), normal
// component for H(div)) of a function vanishes on every vertex, edge or face
// that does not contain the entity the function is associated with, and is
// not identically zero on that entity itself. Checked on a single element with
// several numberings of its nodes, i.e. in several orientations.

#include <algorithm>
#include <cmath>
#include "gmsh.h"
#include "basisTest.h"

namespace bt {

  // a vertex, edge or face of the element: its nodes and coordinates
  struct SubEntity {
    std::vector<std::size_t> nodes;
    std::vector<std::array<double, 3>> x;
  };

  static std::vector<SubEntity> subEntities(const Element &e)
  {
    std::vector<std::vector<std::size_t>> lists;
    std::vector<std::size_t> tags, nodes;
    gmsh::model::mesh::getElementsByType(e.type, tags, nodes);
    for(int i = 0; i < e.numVertices; i++) lists.push_back({nodes[i]});
    if(e.dim >= 2) {
      std::vector<std::size_t> en;
      gmsh::model::mesh::getElementEdgeNodes(e.type, en, -1, true);
      for(std::size_t i = 0; i < en.size(); i += 2)
        lists.push_back({en[i], en[i + 1]});
    }
    if(e.dim == 3) {
      std::vector<std::size_t> fn;
      std::vector<int> sizes;
      gmsh::model::mesh::getElementFaceNodes(e.type, fn, sizes, -1, true);
      for(std::size_t i = 0, o = 0; i < sizes.size(); o += sizes[i], i++)
        lists.push_back(
          std::vector<std::size_t>(fn.begin() + o, fn.begin() + o + sizes[i]));
    }
    std::vector<SubEntity> s;
    for(auto &l : lists) {
      SubEntity se;
      se.nodes = l;
      for(auto n : l) {
        std::vector<double> c, pc;
        int dim, tag;
        gmsh::model::mesh::getNode(n, c, pc, dim, tag);
        se.x.push_back({c[0], c[1], c[2]});
      }
      s.push_back(se);
    }
    return s;
  }

  typedef std::array<double, 3> Vec;
  static Vec sub(const Vec &a, const Vec &b)
  { return {a[0] - b[0], a[1] - b[1], a[2] - b[2]}; }
  static double dot(const Vec &a, const Vec &b)
  { return a[0] * b[0] + a[1] * b[1] + a[2] * b[2]; }

  // random points on a sub-entity, with the tangent vectors there
  static void pointsOn(const SubEntity &s, int n, Random &r,
                       std::vector<Vec> &points,
                       std::vector<std::vector<Vec>> &tangents)
  {
    const std::vector<Vec> &x = s.x;
    for(int i = 0; i < n; i++) {
      Vec p = x[0];
      std::vector<Vec> t;
      if(x.size() == 2) {
        double a = r.uniform(0.05, 0.95);
        for(int k = 0; k < 3; k++) p[k] = (1 - a) * x[0][k] + a * x[1][k];
        t.push_back(sub(x[1], x[0]));
      }
      else if(x.size() == 3) {
        double a = r.uniform(0.05, 0.9), b = r.uniform(0.05, 0.95 - a);
        for(int k = 0; k < 3; k++)
          p[k] = (1 - a - b) * x[0][k] + a * x[1][k] + b * x[2][k];
        t.push_back(sub(x[1], x[0]));
        t.push_back(sub(x[2], x[0]));
      }
      else if(x.size() == 4) {
        double a = r.uniform(0.05, 0.95), b = r.uniform(0.05, 0.95);
        Vec ts, tt;
        for(int k = 0; k < 3; k++) {
          p[k] = (1 - a) * (1 - b) * x[0][k] + a * (1 - b) * x[1][k] +
                 a * b * x[2][k] + (1 - a) * b * x[3][k];
          ts[k] = (1 - b) * (x[1][k] - x[0][k]) + b * (x[2][k] - x[3][k]);
          tt[k] = (1 - a) * (x[3][k] - x[0][k]) + a * (x[2][k] - x[1][k]);
        }
        t.push_back(ts);
        t.push_back(tt);
      }
      points.push_back(p);
      tangents.push_back(t);
    }
  }

  void testTraces()
  {
    Random r(4);
    for(auto &e : elements()) {
      if(e.dim == 0) continue;
      for(int numbering = 0; numbering < 3; numbering++) {
        std::vector<std::size_t> nodes = permutation(e.numVertices, r);
        if(!numbering) std::sort(nodes.begin(), nodes.end());
        std::size_t tag = singleElement(e, nodes);
        std::vector<SubEntity> se = subEntities(e);
        for(auto &s : spaces()) {
          if(!supported(s, e)) continue;
          if(s.kind != H1 && e.dim == 1) continue; // no traces
          for(int p = s.minOrder; p <= std::min(maxOrder(e), 5); p++) {
            std::string fs = spaceType(s, p);
            ElementKeys k = elementKeys(tag, fs);
            int o;
            gmsh::model::mesh::getBasisFunctionsOrientationForElement(tag, fs,
                                                                      o);
            for(auto &sub : se) {
              if(s.kind != H1 && sub.nodes.size() == 1) continue;
              // H(div) traces only on the edges of 2D elements
              if(s.kind == HDIV && sub.nodes.size() > 2) continue;
              std::vector<Vec> pts;
              std::vector<std::vector<Vec>> tan;
              pointsOn(sub, 4, r, pts, tan);
              std::vector<double> uvw;
              for(auto &q : pts) uvw.insert(uvw.end(), q.begin(), q.end());
              Table t = evaluate(e.type, uvw, fs, {o});
              double scale = 1.;
              for(double v : t.data) scale = std::max(scale, std::abs(v));
              std::set<std::size_t> nodesS(sub.nodes.begin(), sub.nodes.end());
              for(int f = 0; f < t.numFunctions; f++) {
                double trace = 0.;
                for(int q = 0; q < t.numPoints; q++) {
                  Vec v = {t(0, q, f, 0), 0., 0.};
                  if(s.kind != H1) v = {v[0], t(0, q, f, 1), t(0, q, f, 2)};
                  if(s.kind == H1)
                    trace = std::max(trace, std::abs(v[0]));
                  else if(s.kind == HCURL)
                    for(auto &tq : tan[q])
                      trace = std::max(trace, std::abs(dot(v, tq)));
                  else {
                    Vec nq = {tan[q][0][1], -tan[q][0][0], 0.};
                    trace = std::max(trace, std::abs(dot(v, nq)));
                  }
                }
                const std::set<std::size_t> &nodesE = k.entityNodes[f];
                bool inside = std::includes(nodesS.begin(), nodesS.end(),
                                            nodesE.begin(), nodesE.end());
                if(!inside)
                  check(trace < 1e-12 * scale,
                        "%s %s: function %d (type %d) has trace %g on an "
                        "entity with %d nodes not containing its own",
                        e.name.c_str(), fs.c_str(), f, k.functionType[f], trace,
                        (int)nodesS.size());
                else if(nodesE == nodesS)
                  check(trace > 1e-8 * scale,
                        "%s %s: function %d (type %d) has zero trace on its "
                        "own entity",
                        e.name.c_str(), fs.c_str(), f, k.functionType[f]);
              }
            }
          }
        }
      }
    }
  }

} // namespace bt
