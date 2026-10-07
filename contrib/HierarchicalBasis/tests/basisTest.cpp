// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <algorithm>
#include <cmath>
#include <cstdarg>
#include <cstdio>
#include <map>
#include "gmsh.h"
#include "basisTest.h"

namespace bt {

  const std::vector<Element> &elements()
  {
    static const std::vector<Element> e = {
      {15, "point", 0, 1},      {1, "line", 1, 2},
      {2, "triangle", 2, 3},    {3, "quadrangle", 2, 4},
      {4, "tetrahedron", 3, 4}, {5, "hexahedron", 3, 8},
      {6, "prism", 3, 6}};
    return e;
  }

  const std::vector<Space> &spaces()
  {
    static const std::vector<Space> s = {
      {H1, "H1Legendre", "GradH1Legendre", 1},
      {HCURL, "HcurlLegendre", "CurlHcurlLegendre", 0},
      {HDIV, "HdivLegendre", "DivHdivLegendre", 0}};
    return s;
  }

  bool supported(const Space &s, const Element &e)
  {
    switch(s.kind) {
    case H1: return true;
    case HCURL: return e.dim >= 1;
    case HDIV: return e.name == "triangle";
    }
    return false;
  }

  int maxOrder(const Element &e)
  {
    if(e.dim <= 1) return 12;
    if(e.dim == 2) return 9;
    if(e.name == "tetrahedron") return 7;
    return 5;
  }

  std::string spaceType(const Space &s, int order, bool derivative)
  { return (derivative ? s.derivative : s.name) + std::to_string(order); }

  Table evaluate(int elementType, const std::vector<double> &uvw,
                 const std::string &fsType,
                 const std::vector<int> &orientations)
  {
    Table t;
    gmsh::model::mesh::getBasisFunctions(elementType, uvw, fsType,
                                         t.numComponents, t.data,
                                         t.totalOrientations, orientations);
    t.numOrientations =
      orientations.empty() ? t.totalOrientations : orientations.size();
    t.numPoints = uvw.size() / 3;
    std::size_t n = std::size_t(t.numOrientations) * t.numPoints *
                    std::max(t.numComponents, 1);
    t.numFunctions = n ? t.data.size() / n : 0;
    return t;
  }

  Eigen::MatrixXd columns(const Table &t, int o, int numComponents)
  {
    Eigen::MatrixXd A(t.numPoints * numComponents, t.numFunctions);
    for(int q = 0; q < t.numPoints; q++)
      for(int c = 0; c < numComponents; c++)
        for(int f = 0; f < t.numFunctions; f++)
          A(q * numComponents + c, f) = t(o, q, f, c);
    return A;
  }

  std::vector<int> orientations(int numOrientations, int max)
  {
    std::vector<int> o;
    if(numOrientations <= max) {
      for(int i = 0; i < numOrientations; i++) o.push_back(i);
      return o;
    }
    Random r(12345);
    std::set<int> s = {0, numOrientations - 1};
    while((int)s.size() < max) s.insert(r.integer(numOrientations));
    return std::vector<int>(s.begin(), s.end());
  }

  double Random::uniform(double a, double b)
  {
    // 64-bit linear congruential generator (Knuth's MMIX constants)
    _state = 6364136223846793005ULL * _state + 1442695040888963407ULL;
    return a + (b - a) * double(_state >> 11) / double(1ULL << 53);
  }

  int Random::integer(int n) { return std::min(int(uniform() * n), n - 1); }

  std::vector<double> interiorPoints(const Element &e, int n, Random &r)
  {
    std::vector<double> p;
    while((int)p.size() < 3 * n) {
      double u = r.uniform(), v = r.uniform(), w = r.uniform();
      double s = r.uniform(-0.98, 0.98), t = r.uniform(-0.98, 0.98),
             z = r.uniform(-0.98, 0.98);
      if(e.dim == 0) { p.insert(p.end(), {0., 0., 0.}); }
      else if(e.name == "line") {
        p.insert(p.end(), {s, 0., 0.});
      }
      else if(e.name == "quadrangle") {
        p.insert(p.end(), {s, t, 0.});
      }
      else if(e.name == "hexahedron") {
        p.insert(p.end(), {s, t, z});
      }
      else if(e.name == "triangle" && u + v < 0.98 && u > 0.01 && v > 0.01) {
        p.insert(p.end(), {u, v, 0.});
      }
      else if(e.name == "prism" && u + v < 0.98 && u > 0.01 && v > 0.01) {
        p.insert(p.end(), {u, v, z});
      }
      else if(e.name == "tetrahedron" && u + v + w < 0.98 && u > 0.01 &&
              v > 0.01 && w > 0.01) {
        p.insert(p.end(), {u, v, w});
      }
    }
    return p;
  }

  std::vector<double> referenceVertices(const Element &e)
  {
    std::string name;
    int dim, order, numNodes, numPrimaryNodes;
    std::vector<double> coord;
    gmsh::model::mesh::getElementProperties(e.type, name, dim, order, numNodes,
                                            coord, numPrimaryNodes);
    // the API returns dim coordinates per node
    std::vector<double> xyz(3 * numPrimaryNodes, 0.);
    for(int i = 0; i < numPrimaryNodes; i++)
      for(int j = 0; j < dim; j++) xyz[3 * i + j] = coord[dim * i + j];
    return xyz;
  }

  std::vector<std::array<int, 3>> monomials(const Element &e, int p)
  {
    std::vector<std::array<int, 3>> m;
    for(int a = 0; a <= p; a++)
      for(int b = 0; b <= p; b++)
        for(int c = 0; c <= p; c++) {
          if((e.dim < 1 && a) || (e.dim < 2 && b) || (e.dim < 3 && c)) continue;
          if((e.name == "triangle" || e.name == "tetrahedron") && a + b + c > p)
            continue;
          if(e.name == "prism" && a + b > p) continue;
          m.push_back({a, b, c});
        }
    return m;
  }

  std::vector<std::array<int, 3>> totalDegree(int dim, int p)
  {
    std::vector<std::array<int, 3>> m;
    for(int a = 0; a <= p; a++)
      for(int b = 0; b <= (dim > 1 ? p - a : 0); b++)
        for(int c = 0; c <= (dim > 2 ? p - a - b : 0); c++)
          m.push_back({a, b, c});
    return m;
  }

  double monomial(const std::array<int, 3> &m, const double *uvw)
  {
    return std::pow(uvw[0], m[0]) * std::pow(uvw[1], m[1]) *
           std::pow(uvw[2], m[2]);
  }

  std::array<double, 3> gradMonomial(const std::array<int, 3> &m,
                                     const double *uvw)
  {
    std::array<double, 3> g;
    for(int i = 0; i < 3; i++) {
      if(!m[i]) {
        g[i] = 0.;
        continue;
      }
      std::array<int, 3> d = m;
      d[i]--;
      g[i] = m[i] * monomial(d, uvw);
    }
    return g;
  }

  int rank(const Eigen::MatrixXd &A, double tol)
  {
    if(!A.size()) return 0;
    Eigen::BDCSVD<Eigen::MatrixXd> svd(A);
    const Eigen::VectorXd &s = svd.singularValues();
    int r = 0;
    for(int i = 0; i < s.size(); i++)
      if(s(i) > tol * s(0)) r++;
    return r;
  }

  double spanResidual(const Eigen::MatrixXd &A, const Eigen::MatrixXd &B)
  {
    double nb = B.norm();
    if(nb == 0.) return 0.;
    Eigen::MatrixXd X = A.colPivHouseholderQr().solve(B);
    return (A * X - B).norm() / nb;
  }

  std::vector<std::size_t> permutation(int n, Random &r)
  {
    std::vector<std::size_t> p(n);
    for(int i = 0; i < n; i++) p[i] = i + 1;
    for(int i = n - 1; i > 0; i--) std::swap(p[i], p[r.integer(i + 1)]);
    return p;
  }

  std::size_t singleElement(const Element &e,
                            const std::vector<std::size_t> &nodeTags)
  {
    gmsh::clear();
    gmsh::model::add("single");
    int tag = gmsh::model::addDiscreteEntity(e.dim);
    gmsh::model::mesh::addNodes(e.dim, tag, nodeTags, referenceVertices(e));
    gmsh::model::mesh::addElementsByType(tag, e.type, {1}, nodeTags);
    return 1;
  }

  ElementKeys elementKeys(std::size_t elementTag, const std::string &fsType)
  {
    ElementKeys k;
    std::vector<double> coord;
    gmsh::model::mesh::getKeysForElement(elementTag, fsType, k.typeKeys,
                                         k.entityKeys, coord, false);
    int type, dim, tag;
    std::vector<std::size_t> nodes;
    gmsh::model::mesh::getElement(elementTag, type, nodes, dim, tag);
    gmsh::vectorpair info;
    gmsh::model::mesh::getKeysInformation(k.typeKeys, k.entityKeys, type,
                                          fsType, info);

    // the nodes of the edges and faces of the element, by their global tag
    if(dim >= 1) gmsh::model::mesh::createEdges();
    if(dim >= 2) gmsh::model::mesh::createFaces();
    int numVertices = 0;
    for(auto &e : elements())
      if(e.type == type) numVertices = e.numVertices;
    std::set<std::size_t> vertices(nodes.begin(), nodes.begin() + numVertices);
    std::map<std::size_t, std::set<std::size_t>> edges, faces;
    std::vector<std::size_t> elementTags, elementNodes;
    gmsh::model::mesh::getElementsByType(type, elementTags, elementNodes, tag);
    std::size_t index =
      std::find(elementTags.begin(), elementTags.end(), elementTag) -
      elementTags.begin();
    if(dim >= 1) {
      std::vector<std::size_t> edgeNodes, edgeTags;
      std::vector<int> orientations;
      gmsh::model::mesh::getElementEdgeNodes(type, edgeNodes, tag, true);
      std::size_t n = edgeNodes.size() / elementTags.size();
      std::vector<std::size_t> mine(edgeNodes.begin() + index * n,
                                    edgeNodes.begin() + (index + 1) * n);
      gmsh::model::mesh::getEdges(mine, edgeTags, orientations);
      for(std::size_t i = 0; i < edgeTags.size(); i++)
        edges[edgeTags[i]] = {mine[2 * i], mine[2 * i + 1]};
    }
    if(dim == 2) {
      std::vector<std::size_t> faceTags;
      std::vector<int> orientations;
      std::vector<std::size_t> mine(nodes.begin(), nodes.begin() + numVertices);
      gmsh::model::mesh::getFaces(mine, {numVertices}, faceTags, orientations);
      faces[faceTags[0]] = vertices;
    }
    else if(dim == 3) {
      std::vector<std::size_t> faceNodes, faceTags;
      std::vector<int> faceSizes, orientations;
      gmsh::model::mesh::getElementFaceNodes(type, faceNodes, faceSizes, tag,
                                             true);
      std::size_t nf = faceSizes.size() / elementTags.size(), offset = 0;
      for(std::size_t i = 0; i < index * nf; i++) offset += faceSizes[i];
      std::vector<int> sizes(faceSizes.begin() + index * nf,
                             faceSizes.begin() + (index + 1) * nf);
      std::size_t total = 0;
      for(int s : sizes) total += s;
      std::vector<std::size_t> mine(faceNodes.begin() + offset,
                                    faceNodes.begin() + offset + total);
      gmsh::model::mesh::getFaces(mine, sizes, faceTags, orientations);
      for(std::size_t i = 0, o = 0; i < faceTags.size(); o += sizes[i], i++)
        faces[faceTags[i]] =
          std::set<std::size_t>(mine.begin() + o, mine.begin() + o + sizes[i]);
    }

    for(std::size_t i = 0; i < k.typeKeys.size(); i++) {
      k.functionType.push_back(info[i].first);
      switch(info[i].first) {
      case 0: k.entityNodes.push_back({k.entityKeys[i]}); break;
      case 1: k.entityNodes.push_back(edges[k.entityKeys[i]]); break;
      case 2: k.entityNodes.push_back(faces[k.entityKeys[i]]); break;
      default: k.entityNodes.push_back(vertices); break;
      }
    }
    return k;
  }

  static int _numFailures = 0, _numChecks = 0;

  bool check(bool ok, const char *fmt, ...)
  {
    _numChecks++;
    if(ok) return true;
    if(++_numFailures <= 100) {
      va_list args;
      va_start(args, fmt);
      std::printf("FAIL: ");
      std::vprintf(fmt, args);
      std::printf("\n");
      va_end(args);
    }
    return false;
  }

  int numFailures() { return _numFailures; }
  int numChecks() { return _numChecks; }

} // namespace bt
