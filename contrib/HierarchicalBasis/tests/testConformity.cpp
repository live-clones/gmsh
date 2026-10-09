// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// Conformity across elements: on meshes mixing element types, two elements
// sharing a vertex (1D), an edge (2D) or a face (3D) must agree on the trace of
// each basis function they share (same key), once the functions are oriented
// with getBasisFunctionsOrientationForElement() and mapped to the physical
// element (covariant Piola map for H(curl), contravariant for H(div)); the
// functions of only one of the elements must have zero trace there. Checked for
// several numberings of the nodes, i.e. with many different orientations.

#include <algorithm>
#include <cmath>
#include <map>
#include "gmsh.h"
#include "basisTest.h"

namespace bt {

  typedef std::array<double, 3> Vec;

  // a square split into triangles (left) and quadrangles (right)
  static void square(double lc)
  {
    namespace geo = gmsh::model::geo;
    std::vector<std::pair<double, double>> xy = {{0, 0}, {.5, 0}, {1, 0},
                                                 {1, 1}, {.5, 1}, {0, 1}};
    for(std::size_t i = 0; i < xy.size(); i++)
      geo::addPoint(xy[i].first, xy[i].second, 0, lc, i + 1);
    std::vector<std::pair<int, int>> lines = {{1, 2}, {2, 5}, {5, 6}, {6, 1},
                                              {2, 3}, {3, 4}, {4, 5}};
    for(std::size_t i = 0; i < lines.size(); i++)
      geo::addLine(lines[i].first, lines[i].second, i + 1);
    geo::addCurveLoop({1, 2, 3, 4}, 1);
    geo::addCurveLoop({5, 6, 7, -2}, 2);
    geo::addPlaneSurface({1}, 1);
    geo::addPlaneSurface({2}, 2);
    geo::mesh::setRecombine(2, 2);
  }

  void mixedMesh(int dim)
  {
    gmsh::clear();
    gmsh::model::add("conformity");
    namespace geo = gmsh::model::geo;
    if(dim == 1) {
      geo::addPoint(0, 0, 0, 1, 1);
      geo::addPoint(1, 0.3, 0, 1, 2);
      geo::addLine(1, 2, 1);
      geo::mesh::setTransfiniteCurve(1, 5);
    }
    else if(dim == 2) {
      square(0.3);
    }
    else {
      // prisms and hexahedra by extrusion of the square, and tetrahedra on top
      // of the prisms
      square(0.4);
      std::vector<std::pair<int, int>> out;
      geo::extrude({{2, 1}, {2, 2}}, 0, 0, 0.5, out, {2}, {}, true);
      std::vector<std::pair<int, int>> out2;
      geo::extrude({out[0]}, 0, 0, 0.5, out2);
    }
    geo::synchronize();
    gmsh::model::mesh::generate(dim);
  }

  // the facets (vertices in 1D, edges in 2D, faces in 3D) shared by two
  // elements of dimension dim: their nodes and the two elements
  struct Facet {
    std::vector<std::size_t> nodes;
    std::vector<std::size_t> elements;
  };

  static std::vector<Facet> facets(int dim)
  {
    std::map<std::vector<std::size_t>, Facet> m;
    std::vector<int> types;
    gmsh::model::mesh::getElementTypes(types, dim);
    for(int type : types) {
      std::vector<std::size_t> tags, nodes, fn;
      std::vector<int> sizes;
      gmsh::model::mesh::getElementsByType(type, tags, nodes);
      if(dim == 1) {
        for(std::size_t i = 0; i < tags.size(); i++) {
          fn.push_back(nodes[2 * i]);
          fn.push_back(nodes[2 * i + 1]);
          sizes.push_back(1);
          sizes.push_back(1);
        }
      }
      else if(dim == 2) {
        gmsh::model::mesh::getElementEdgeNodes(type, fn, -1, true);
        sizes.assign(fn.size() / 2, 2);
      }
      else {
        gmsh::model::mesh::getElementFaceNodes(type, fn, sizes, -1, true);
      }
      std::size_t perElement = sizes.size() / tags.size();
      for(std::size_t i = 0, o = 0; i < sizes.size(); o += sizes[i], i++) {
        std::vector<std::size_t> f(fn.begin() + o, fn.begin() + o + sizes[i]);
        std::vector<std::size_t> key = f;
        std::sort(key.begin(), key.end());
        Facet &facet = m[key];
        if(facet.nodes.empty()) facet.nodes = f;
        facet.elements.push_back(tags[i / perElement]);
      }
    }
    std::vector<Facet> f;
    for(auto &kv : m)
      if(kv.second.elements.size() == 2) f.push_back(kv.second);
    return f;
  }

  static Vec node(std::size_t tag)
  {
    std::vector<double> c, pc;
    int dim, t;
    gmsh::model::mesh::getNode(tag, c, pc, dim, t);
    return {c[0], c[1], c[2]};
  }

  // random points on the facet, with its tangent vectors (and its normal in
  // the plane z = 0 for edges) there
  static void facetPoints(const Facet &f, Random &r, std::vector<Vec> &p,
                          std::vector<std::vector<Vec>> &t)
  {
    std::vector<Vec> x;
    for(auto n : f.nodes) x.push_back(node(n));
    for(int i = 0; i < 3; i++) {
      Vec q;
      std::vector<Vec> tq;
      if(x.size() == 1) { q = x[0]; }
      else if(x.size() == 2) {
        double a = r.uniform(0.05, 0.95);
        for(int k = 0; k < 3; k++) q[k] = (1 - a) * x[0][k] + a * x[1][k];
        tq.push_back({x[1][0] - x[0][0], x[1][1] - x[0][1], 0.});
        tq.push_back({x[1][1] - x[0][1], x[0][0] - x[1][0], 0.}); // normal
      }
      else if(x.size() == 3) {
        double a = r.uniform(0.05, 0.9), b = r.uniform(0.05, 0.95 - a);
        Vec t1, t2;
        for(int k = 0; k < 3; k++) {
          q[k] = (1 - a - b) * x[0][k] + a * x[1][k] + b * x[2][k];
          t1[k] = x[1][k] - x[0][k];
          t2[k] = x[2][k] - x[0][k];
        }
        tq = {t1, t2};
      }
      else {
        double a = r.uniform(0.05, 0.95), b = r.uniform(0.05, 0.95);
        Vec t1, t2;
        for(int k = 0; k < 3; k++) {
          q[k] = (1 - a) * (1 - b) * x[0][k] + a * (1 - b) * x[1][k] +
                 a * b * x[2][k] + (1 - a) * b * x[3][k];
          t1[k] = (1 - b) * (x[1][k] - x[0][k]) + b * (x[2][k] - x[3][k]);
          t2[k] = (1 - a) * (x[3][k] - x[0][k]) + a * (x[2][k] - x[1][k]);
        }
        tq = {t1, t2};
      }
      p.push_back(q);
      t.push_back(tq);
    }
  }

  // the traces at the points p of the basis functions of the element, by key
  static std::map<std::pair<int, std::size_t>, std::vector<double>>
  traces(std::size_t tag, const Space &s, const std::string &fs,
         const std::vector<Vec> &p, const std::vector<std::vector<Vec>> &t,
         double &scale)
  {
    int type, dim, entity;
    std::vector<std::size_t> nodes;
    gmsh::model::mesh::getElement(tag, type, nodes, dim, entity);
    std::vector<double> uvw;
    for(auto &q : p) {
      double u, v, w;
      gmsh::model::mesh::getLocalCoordinatesInElement(tag, q[0], q[1], q[2], u,
                                                      v, w);
      uvw.insert(uvw.end(), {u, v, w});
    }
    int o;
    gmsh::model::mesh::getBasisFunctionsOrientationForElement(tag, fs, o);
    Table b = evaluate(type, uvw, fs, {o});
    std::vector<double> jac, det, xyz;
    gmsh::model::mesh::getJacobian(tag, uvw, jac, det, xyz);
    std::vector<int> typeKeys;
    std::vector<std::size_t> entityKeys;
    std::vector<double> coord;
    gmsh::model::mesh::getKeysForElement(tag, fs, typeKeys, entityKeys, coord,
                                         false);
    std::map<std::pair<int, std::size_t>, std::vector<double>> tr;
    for(int f = 0; f < b.numFunctions; f++) {
      std::vector<double> &v = tr[{typeKeys[f], entityKeys[f]}];
      for(int q = 0; q < b.numPoints; q++) {
        // J(i, j) = d x_j / d u_i
        Eigen::Map<const Eigen::Matrix<double, 3, 3, Eigen::RowMajor>> J(
          &jac[9 * q]);
        Eigen::Vector3d ref(b(0, q, f, 0), 0., 0.), phys;
        if(s.kind != H1) ref = {b(0, q, f, 0), b(0, q, f, 1), b(0, q, f, 2)};
        if(s.kind == H1) {
          v.push_back(ref(0));
          scale = std::max(scale, std::abs(ref(0)));
          continue;
        }
        if(s.kind == HCURL)
          phys = J.inverse() * ref;
        else
          phys = J.transpose() * ref / det[q];
        scale = std::max(scale, phys.norm());
        if(s.kind == HCURL) {
          // tangential components (only the edge tangent in 2D)
          std::size_t nt = (t[q].size() == 2 && dim == 2) ? 1 : t[q].size();
          for(std::size_t k = 0; k < nt; k++)
            v.push_back(phys.dot(Eigen::Vector3d(t[q][k].data())));
        }
        else if(dim == 2) // the normal to the edge
          v.push_back(phys.dot(Eigen::Vector3d(t[q][1].data())));
        else { // the normal to the face
          Eigen::Vector3d t1(t[q][0].data()), t2(t[q][1].data());
          v.push_back(phys.dot(t1.cross(t2)));
        }
      }
    }
    return tr;
  }

  void testConformity()
  {
    Random r(5);
    for(int dim = 1; dim <= 3; dim++) {
      mixedMesh(dim);
      for(int numbering = 0; numbering < 3; numbering++) {
        if(numbering) {
          std::vector<std::size_t> tags;
          std::vector<double> c, pc;
          gmsh::model::mesh::getNodes(tags, c, pc);
          std::vector<std::size_t> p = permutation(tags.size(), r);
          gmsh::model::mesh::renumberNodes(tags, p);
        }
        std::vector<Facet> fa = facets(dim);
        check(!fa.empty(), "%dD mesh: no shared facets", dim);
        for(auto &s : spaces()) {
          if(dim == 1 && s.kind != H1) continue;
          int maxp = (s.kind == H1) ? 4 : 3;
          for(int p = s.minOrder; p <= maxp; p++) {
            std::string fs = spaceType(s, p);
            double worst = 0., worstScale = 1.;
            int numFacets = 0;
            for(auto &f : fa) {
              bool ok = true;
              for(auto tag : f.elements) {
                int type, d, e;
                std::vector<std::size_t> n;
                gmsh::model::mesh::getElement(tag, type, n, d, e);
                for(auto &el : elements())
                  if(el.type == type && !supported(s, el)) ok = false;
              }
              if(!ok) continue;
              numFacets++;
              std::vector<Vec> pts;
              std::vector<std::vector<Vec>> tan;
              facetPoints(f, r, pts, tan);
              double scale = 1.;
              auto t0 = traces(f.elements[0], s, fs, pts, tan, scale);
              auto t1 = traces(f.elements[1], s, fs, pts, tan, scale);
              for(auto &kv : t0) {
                auto it = t1.find(kv.first);
                for(std::size_t i = 0; i < kv.second.size(); i++) {
                  double other = (it == t1.end()) ? 0. : it->second[i];
                  double diff = std::abs(kv.second[i] - other) / scale;
                  if(diff > worst) {
                    worst = diff;
                    worstScale = scale;
                  }
                }
              }
              for(auto &kv : t1) {
                if(t0.count(kv.first)) continue;
                for(double v : kv.second)
                  if(std::abs(v) / scale > worst) {
                    worst = std::abs(v) / scale;
                    worstScale = scale;
                  }
              }
            }
            check(worst < 1e-9,
                  "%dD mesh, numbering %d, %s: traces differ by %g (relative "
                  "to %g) over %d facets",
                  dim, numbering, fs.c_str(), worst, worstScale, numFacets);
          }
        }
      }
    }
  }

} // namespace bt
