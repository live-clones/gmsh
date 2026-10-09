// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// The L2 bases, which close the sequences:
// - L2Legendre<p> spans the polynomials of H1Legendre<p> (P_p on simplices,
//   Q_p on quadrangles and hexahedra, P_p x P_p on prisms), with linearly
//   independent functions that do not depend on the orientation;
// - the functions of order p are those of order p + 1 with an order of at most
//   p, with the same keys;
// - the divergences of HdivLegendre<p> span L2Legendre<p> on quadrangles,
//   hexahedra and prisms, L2Legendre<p-1> on triangles and tetrahedra
//   (Brezzi-Douglas-Marini), and those of HdivLegendreCurl<p> with
//   HdivLegendreNoCurl<p+1> (Raviart-Thomas) span L2Legendre<p> there too.

#include <cmath>
#include "gmsh.h"
#include "basisTest.h"

namespace bt {

  static const double tol = 1e-10;

  void testL2()
  {
    Random r(8);
    for(auto &e : elements()) {
      if(e.dim == 0) continue;
      const char *n = e.name.c_str();
      bool simplex = (e.name == "triangle" || e.name == "tetrahedron");
      for(int p = 0; p <= maxOrder(e); p++) {
        std::string fs = "L2Legendre" + std::to_string(p);
        const char *f = fs.c_str();
        std::vector<std::array<int, 3>> m = monomials(e, p);
        std::vector<double> uvw = interiorPoints(e, 2 * m.size() + 10, r);
        int no = evaluate(e.type, uvw, fs, {0}).totalOrientations;
        Table t = evaluate(e.type, uvw, fs, orientations(no, 16));
        Eigen::MatrixXd A = columns(t, 0, 1);
        Eigen::MatrixXd M(t.numPoints, m.size());
        for(int q = 0; q < t.numPoints; q++)
          for(std::size_t j = 0; j < m.size(); j++)
            M(q, j) = monomial(m[j], &uvw[3 * q]);
        double res = std::max(spanResidual(A, M), spanResidual(M, A));
        check(t.numFunctions == (int)m.size() && rank(A) == t.numFunctions &&
                res < tol,
              "%s %s: %d functions of rank %d for %d polynomials (%g)", n, f,
              t.numFunctions, rank(A), (int)m.size(), res);
        double diff = 0.;
        for(int o = 1; o < t.numOrientations; o++)
          diff = std::max(diff, (columns(t, o, 1) - A).norm());
        check(diff < 1e-14, "%s %s: the functions depend on the orientation", n,
              f);

        // keys and orders, through a single element
        std::size_t tag = singleElement(e, permutation(e.numVertices, r));
        KeyedFunctions a = keyedFunctions(tag, e, uvw, fs),
                       b = keyedFunctions(tag, e, uvw,
                                          "L2Legendre" + std::to_string(p + 1));
        int ok = 0;
        for(auto &kv : b)
          if(kv.second.order <= p && a.count(kv.first) &&
             a.at(kv.first).values == kv.second.values &&
             kv.second.type == e.dim)
            ok++;
        check(ok == (int)a.size(),
              "%s %s: %d of the %d functions are functions of order %d with "
              "the same keys",
              n, f, ok, (int)a.size(), p + 1);

        // the divergences of the H(div) functions
        if(e.dim < 2) continue;
        auto divergences = [&](const std::string &name, int order) {
          return columns(
            evaluate(e.type, uvw, name + std::to_string(order), {0}), 0, 1);
        };
        Eigen::MatrixXd D = divergences("DivHdivLegendre", p);
        int q = simplex ? p - 1 : p;
        if(q >= 0) {
          Eigen::MatrixXd L = columns(
            evaluate(e.type, uvw, "L2Legendre" + std::to_string(q), {0}), 0, 1);
          res = std::max(spanResidual(L, D), spanResidual(D, L));
          check(rank(D) == L.cols() && res < tol,
                "%s DivHdivLegendre%d: rank %d, not onto L2Legendre%d of "
                "dimension %d (%g)",
                n, p, rank(D), q, (int)L.cols(), res);
        }
        if(simplex && p + 1 <= maxOrder(e)) {
          Eigen::MatrixXd Dk = divergences("DivHdivLegendreCurl", p),
                          Dn = divergences("DivHdivLegendreNoCurl", p + 1);
          Eigen::MatrixXd DRT(Dk.rows(), Dk.cols() + Dn.cols());
          DRT << Dk, Dn;
          res = std::max(spanResidual(A, DRT), spanResidual(DRT, A));
          check(rank(DRT) == A.cols() && res < tol,
                "%s: the divergences of RT%d are not onto L2Legendre%d (%g)", n,
                p, p, res);
        }
      }
    }
  }

} // namespace bt
