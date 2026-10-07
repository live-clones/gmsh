// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// Helpers for the tests of the hierarchical basis functions. The tests only use
// the public C++ API, so that they remain valid when the implementation of the
// basis functions changes.

#ifndef BASIS_TEST_H
#define BASIS_TEST_H

#include <array>
#include <cstdint>
#include <set>
#include <string>
#include <vector>
#include <Eigen/Dense>

namespace bt {

  // the first-order elements on which the basis functions are defined
  struct Element {
    int type; // MSH element type
    std::string name;
    int dim;
    int numVertices;
  };
  const std::vector<Element> &elements();

  // the families of hierarchical function spaces
  enum Kind { H1, HCURL, HDIV };
  struct Space {
    Kind kind;
    std::string name; // e.g. "HcurlLegendre"
    std::string derivative; // e.g. "CurlHcurlLegendre"
    int minOrder;
  };
  const std::vector<Space> &spaces();
  // is the space defined on the element?
  bool supported(const Space &s, const Element &e);
  // the highest order tested on the element
  int maxOrder(const Element &e);
  // the function space type string given to the API, e.g. "HcurlLegendre3"
  std::string spaceType(const Space &s, int order, bool derivative = false);

  // basis function values: (orientation, point, function, component)
  struct Table {
    int numOrientations = 0, numPoints = 0, numFunctions = 0, numComponents = 0;
    int totalOrientations = 0; // number of possible orientations
    std::vector<double> data;
    double operator()(int o, int q, int f, int c) const
    {
      return data[((std::size_t(o) * numPoints + q) * numFunctions + f) *
                    numComponents +
                  c];
    }
  };
  // evaluate the basis functions at the points uvw (flat u, v, w) for the
  // given orientations (all of them if empty)
  Table evaluate(int elementType, const std::vector<double> &uvw,
                 const std::string &fsType,
                 const std::vector<int> &orientations = {});

  // matrix of the values for orientation o: one column per function, one row
  // per (point, component), keeping the first numComponents components
  Eigen::MatrixXd columns(const Table &t, int o, int numComponents);

  // the orientations to test: all of them, or a fixed sample of about max
  // when there are too many (hexahedra have 40320)
  std::vector<int> orientations(int numOrientations, int max = 64);

  // pseudo-random numbers, identical on all platforms
  class Random {
    std::uint64_t _state;

  public:
    explicit Random(std::uint64_t seed) : _state(seed) {}
    double uniform(double a = 0., double b = 1.);
    int integer(int n); // in [0, n)
  };

  // random points strictly inside the reference element (flat u, v, w)
  std::vector<double> interiorPoints(const Element &e, int n, Random &r);

  // the vertices of the reference element (flat x, y, z)
  std::vector<double> referenceVertices(const Element &e);

  // the exponents (a, b, c) of the monomials u^a v^b w^c spanning the
  // polynomial space reproduced by the H1 functions of order p
  std::vector<std::array<int, 3>> monomials(const Element &e, int p);
  // the monomials of total degree <= p in dim variables
  std::vector<std::array<int, 3>> totalDegree(int dim, int p);
  double monomial(const std::array<int, 3> &m, const double *uvw);
  // gradient of a monomial
  std::array<double, 3> gradMonomial(const std::array<int, 3> &m,
                                     const double *uvw);

  // linear algebra
  int rank(const Eigen::MatrixXd &A, double tol = 1e-10);
  // relative residual of the least squares fit of the columns of B by
  // combinations of the columns of A (0 if span(B) is in span(A))
  double spanResidual(const Eigen::MatrixXd &A, const Eigen::MatrixXd &B);

  // a random permutation of the node tags 1, ..., n
  std::vector<std::size_t> permutation(int n, Random &r);

  // clear all models and create one with a single element of type e, whose
  // nodes, placed at the vertices of the reference element, have the given
  // tags: the physical coordinates are then the reference coordinates; return
  // the element tag
  std::size_t singleElement(const Element &e,
                            const std::vector<std::size_t> &nodeTags);

  // clear all models and create a small mesh of dimension dim mixing element
  // types: segments in 1D, triangles and quadrangles in 2D, tetrahedra, prisms
  // and hexahedra in 3D
  void mixedMesh(int dim);

  // the keys of the basis functions of an element in the current model, with
  // the nodes of the mesh entity (vertex, edge, face or element) each one is
  // associated with
  struct ElementKeys {
    std::vector<int> typeKeys;
    std::vector<std::size_t> entityKeys;
    std::vector<int> functionType; // 0: vertex, 1: edge, 2: face, 3: bubble
    std::vector<std::set<std::size_t>> entityNodes;
  };
  ElementKeys elementKeys(std::size_t elementTag, const std::string &fsType);

  // record the result of a check; print a message and count the failures
  bool check(bool ok, const char *fmt, ...);
  int numFailures();
  int numChecks();

  // the tests: each one returns normally, failures being counted by check()
  void testCounts();
  void testDerivatives();
  void testSpaces();
  void testTraces();
  void testConformity();
  void testApi();
  void testPeriodic();
  void testReference(const std::string &file, bool write);

} // namespace bt

#endif
