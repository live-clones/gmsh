// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// The spaces spanned by the basis functions, in several orientations:
// - the functions are linearly independent;
// - H1 of order p is the full polynomial space of the element (P_p on
//   simplices, Q_p on quadrangles and hexahedra, P_p x P_p on prisms);
// - H(curl) and H(div) of order p are exactly the claimed spaces (see
//   claimedSpace), and contain all the vector polynomials of
//   degree p, and the gradients (resp. rotated gradients in 2D) of H1 of
//   order p+1; H(div) in 3D contains the curls of H(curl), of order p+1 on
//   tetrahedra (0 for p = 0) and of order p on the other elements;
// - the sequence is exact: the null space of the gradient is the constants,
//   the null space of the curl (resp. divergence) has the dimension of H1 of
//   order p+1 minus one, i.e. it is made of the gradients (resp. rotated
//   gradients), and the null space of the divergence in 3D is made of the
//   curls, and, on prisms, of p + 1 vertical fields (the hierarchy of the
//   bases is checked by testHierarchy).

#include <cmath>
#include <functional>
#include "basisTest.h"

namespace bt {

  static const double tol = 1e-10;

  // the vector fields with one component equal to a monomial of total degree
  // <= p, and the others zero, at the points uvw
  static Eigen::MatrixXd vectorPolynomials(int dim, int p,
                                           const std::vector<double> &uvw)
  {
    std::vector<std::array<int, 3>> m = totalDegree(dim, p);
    int nq = uvw.size() / 3;
    Eigen::MatrixXd V = Eigen::MatrixXd::Zero(nq * dim, m.size() * dim);
    for(int q = 0; q < nq; q++)
      for(std::size_t i = 0; i < m.size(); i++)
        for(int c = 0; c < dim; c++)
          V(q * dim + c, i * dim + c) = monomial(m[i], &uvw[3 * q]);
    return V;
  }

  // The H(curl) or H(div) space of order p of the element, spanned by vector
  // fields at the points uvw: each component c spans the monomials u^a v^b w^d
  // with the degrees given by the space, plus some fields x q for the lowest
  // order spaces of simplices and prisms:
  // - simplices: P_p^dim for p >= 1; for p = 0, the constants and x x c (the
  //   Whitney functions) in H(curl), x in H(div);
  // - quadrangles and hexahedra: Q_(p, p+1, p+1) e_u + ... in H(curl),
  //   Q_(p+1, p, p) e_u + ... in H(div);
  // - prisms: the space of the triangle times P_p+1(w) (H(curl)) or P_p(w)
  //   (H(div)) horizontally, P_p+1(u, v) x P_p(w) e_w (H(curl)) or P_p(u, v) x
  //   P_p+1(w) e_w (H(div)) vertically.
  static Eigen::MatrixXd claimedSpace(const Element &e, Kind kind, int p,
                                      const std::vector<double> &uvw)
  {
    const int dim = e.dim, nq = uvw.size() / 3;
    const bool curl = (kind == HCURL);
    // whether the monomial u^a v^b w^d belongs to component c
    auto in = [&](int c, int a, int b, int d) {
      if(e.name == "line") return a <= p;
      if(e.name == "triangle" || e.name == "tetrahedron")
        return a + b + d <= (p ? p : 0);
      if(e.name == "quadrangle" || e.name == "hexahedron") {
        int k[3] = {a, b, d};
        for(int i = 0; i < dim; i++) {
          int max = (i == c) == curl ? p : p + 1;
          if(k[i] > max) return false;
        }
        return true;
      }
      // prisms
      if(c < 2)
        return a + b <= p && d <= (curl ? p + 1 : p) &&
               (p || !curl || a + b == 0);
      return a + b <= (curl ? p + 1 : p) && d <= (curl ? p : p + 1);
    };
    std::vector<std::array<double, 3>> fields; // per point and column
    std::vector<std::vector<double>> cols;
    for(int c = 0; c < dim; c++)
      for(int a = 0; a <= p + 1; a++)
        for(int b = 0; b <= (dim >= 2 ? p + 1 : 0); b++)
          for(int d = 0; d <= (dim == 3 ? p + 1 : 0); d++) {
            if(!in(c, a, b, d)) continue;
            std::vector<double> col(nq * dim, 0.);
            for(int q = 0; q < nq; q++)
              col[q * dim + c] = monomial({a, b, d}, &uvw[3 * q]);
            cols.push_back(col);
          }
    // the fields x q of the lowest order spaces
    auto addField =
      [&](std::function<std::array<double, 3>(const double *)> g) {
        std::vector<double> col(nq * dim);
        for(int q = 0; q < nq; q++) {
          std::array<double, 3> v = g(&uvw[3 * q]);
          for(int c = 0; c < dim; c++) col[q * dim + c] = v[c];
        }
        cols.push_back(col);
      };
    bool simplex = (e.name == "triangle" || e.name == "tetrahedron");
    if(p == 0 && simplex && !curl)
      addField([](const double *x) {
        return std::array<double, 3>{x[0], x[1], x[2]};
      });
    if(p == 0 && simplex && curl && dim == 2)
      addField(
        [](const double *x) { return std::array<double, 3>{-x[1], x[0], 0.}; });
    if(p == 0 && simplex && curl && dim == 3)
      for(int c = 0; c < 3; c++)
        addField([c](const double *x) {
          double ec[3] = {0., 0., 0.};
          ec[c] = 1.;
          return std::array<double, 3>{x[1] * ec[2] - x[2] * ec[1],
                                       x[2] * ec[0] - x[0] * ec[2],
                                       x[0] * ec[1] - x[1] * ec[0]};
        });
    if(p == 0 && e.name == "prism")
      for(int d = 0; d <= (curl ? 1 : 0); d++)
        addField([curl, d](const double *x) {
          double wd = d ? x[2] : 1.;
          return curl ? std::array<double, 3>{-x[1] * wd, x[0] * wd, 0.} :
                        std::array<double, 3>{x[0], x[1], 0.};
        });
    Eigen::MatrixXd V(nq * dim, cols.size());
    for(std::size_t j = 0; j < cols.size(); j++)
      for(int i = 0; i < nq * dim; i++) V(i, j) = cols[j][i];
    return V;
  }

  // the gradients (or the rotated gradients (d/dv, -d/du) if rotate is set) of
  // the monomials spanning H1 of order p
  static Eigen::MatrixXd gradients(const Element &e, int p,
                                   const std::vector<double> &uvw,
                                   bool rotate = false)
  {
    std::vector<std::array<int, 3>> m = monomials(e, p);
    int nq = uvw.size() / 3;
    Eigen::MatrixXd G(nq * e.dim, m.size());
    for(int q = 0; q < nq; q++)
      for(std::size_t i = 0; i < m.size(); i++) {
        std::array<double, 3> g = gradMonomial(m[i], &uvw[3 * q]);
        if(rotate) g = {g[1], -g[0], 0.};
        for(int c = 0; c < e.dim; c++) G(q * e.dim + c, i) = g[c];
      }
    return G;
  }

  void testSpaces()
  {
    Random r(3);
    for(auto &e : elements()) {
      if(e.dim == 0) continue;
      for(auto &s : spaces()) {
        if(!supported(s, e)) continue;
        for(int p = s.minOrder; p <= maxOrder(e); p++) {
          std::string fs = spaceType(s, p);
          const char *n = e.name.c_str(), *f = fs.c_str();
          int nc = (s.kind == H1) ? 1 : e.dim;
          int nf =
            evaluate(e.type, interiorPoints(e, 1, r), fs, {0}).numFunctions;
          // enough points for the least squares fits to be meaningful
          std::vector<double> uvw =
            interiorPoints(e, std::max(30, 3 * nf / nc + 10), r);
          Table t = evaluate(e.type, uvw, fs, {0});
          std::vector<int> o = orientations(t.totalOrientations, 4);
          t = evaluate(e.type, uvw, fs, o);
          Table d = evaluate(e.type, uvw, spaceType(s, p, true), o);
          int numKernel = monomials(e, p + 1).size() - 1;
          // in 3D, the curls of H(curl) of order p + 1 on tetrahedra (0 for
          // RT0), of order p on the other elements
          int q = (e.name != "tetrahedron") ? p : (p ? p + 1 : 0);
          Table curls;
          if(s.kind == HDIV && e.dim == 3)
            curls =
              evaluate(e.type, uvw, "CurlHcurlLegendre" + std::to_string(q), o);
          for(std::size_t i = 0; i < o.size(); i++) {
            Eigen::MatrixXd A = columns(t, i, nc);
            check(rank(A) == nf,
                  "%s %s orientation %d: rank %d for %d functions", n, f, o[i],
                  rank(A), nf);
            int dr = rank(columns(d, i, d.numComponents));
            if(s.kind == H1) {
              std::vector<std::array<int, 3>> m = monomials(e, p);
              Eigen::MatrixXd M(t.numPoints, m.size());
              for(int q = 0; q < t.numPoints; q++)
                for(std::size_t j = 0; j < m.size(); j++)
                  M(q, j) = monomial(m[j], &uvw[3 * q]);
              double res = spanResidual(A, M);
              check(res < tol,
                    "%s %s orientation %d: polynomials of the "
                    "element not reproduced (%g)",
                    n, f, o[i], res);
              check(nf - dr == 1,
                    "%s %s orientation %d: gradient null space "
                    "of dimension %d",
                    n, f, o[i], nf - dr);
            }
            else { // H(curl) and H(div): exactly the claimed space
              Eigen::MatrixXd V = claimedSpace(e, s.kind, p, uvw);
              double res = spanResidual(V, A);
              check(rank(V) == nf && res < tol,
                    "%s %s orientation %d: %d functions, claimed space of "
                    "dimension %d (residual %g)",
                    n, f, o[i], nf, rank(V), res);
            }
            if(s.kind == H1) {}
            else if(e.dim == 1) { // H(curl) on lines: polynomials of degree p
              double res = spanResidual(A, vectorPolynomials(1, p, uvw));
              check(res < tol,
                    "%s %s orientation %d: polynomials not "
                    "reproduced (%g)",
                    n, f, o[i], res);
            }
            else {
              double res = spanResidual(A, vectorPolynomials(e.dim, p, uvw));
              check(res < tol,
                    "%s %s orientation %d: vector polynomials of "
                    "degree %d not reproduced (%g)",
                    n, f, o[i], p, res);
              if(s.kind == HDIV && e.dim == 3) {
                Eigen::MatrixXd C = columns(curls, i, curls.numComponents);
                res = spanResidual(A, C);
                check(res < tol,
                      "%s %s orientation %d: curls of H(curl) of order %d "
                      "not reproduced (%g)",
                      n, f, o[i], q, res);
                numKernel = rank(C);
                // on prisms, also the vertical fields q(u, v) e_w with q
                // homogeneous of degree p >= 1, which are not curls of H(curl)
                // functions of order p
                if(e.name == "prism" && p) numKernel += p + 1;
              }
              else {
                res = spanResidual(A, gradients(e, p + 1, uvw, s.kind == HDIV));
                check(res < tol,
                      "%s %s orientation %d: %s of H1 of order %d not "
                      "reproduced (%g)",
                      n, f, o[i],
                      s.kind == HDIV ? "rotated gradients" : "gradients", p + 1,
                      res);
              }
              check(nf - dr == numKernel,
                    "%s %s orientation %d: %s null "
                    "space of dimension %d, expected %d",
                    n, f, o[i], s.kind == HDIV ? "divergence" : "curl", nf - dr,
                    numKernel);
            }
          }
        }
      }
    }
  }

} // namespace bt
