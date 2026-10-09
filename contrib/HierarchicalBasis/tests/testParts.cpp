// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// The parts of the H(curl) and H(div) spaces, selected by name:
// - each part is a filter of the whole space: the two parts together are its
//   functions, with the same keys, information and values;
// - HcurlLegendreGrad<p> are exactly the gradients of the edge, face and bubble
//   functions of H1Legendre<p+1>, and the curls of HcurlLegendreNoGrad<p> are
//   linearly independent, but for the lowest order (Whitney) functions, which
//   span the gradients of the vertex functions;
// - HdivLegendreCurl<p> are divergence free (the gradients and curls being
//   computed without derivatives, so that this holds by construction; that
//   the derivatives of the functions are right is checked by testDerivatives
//   on the whole space, of which the parts are filters), and the divergences of
//   HdivLegendreNoCurl<p> are linearly independent, but for the lowest order
//   functions, which span the curls of the lowest order H(curl) functions; in
//   3D, the former are curls of HcurlLegendreNoGrad, of order p + 1 on
//   tetrahedra, p on the other elements;
// - on simplices, HcurlLegendreNoGrad<p> with HcurlLegendreGrad<p-1> span the
//   Nedelec space of the first kind of order p, and HdivLegendreCurl<p> with
//   HdivLegendreNoCurl<p+1> span the Raviart-Thomas space of order p.

#include <cmath>
#include "gmsh.h"
#include "basisTest.h"

namespace bt {

  static const double tol = 1e-10;

  // the vector polynomials spanning the Nedelec space of the first kind of
  // order p (p >= 1), P_p-1^d + {x x q, q homogeneous of degree p - 1}, or the
  // Raviart-Thomas space of order p, P_p^d + {x q, q homogeneous of degree p},
  // at the points uvw, in dimension d = 2 or 3
  static Eigen::MatrixXd nedelecOrRaviartThomas(int dim, int p, bool nedelec,
                                                const std::vector<double> &uvw)
  {
    int nq = uvw.size() / 3, full = nedelec ? p - 1 : p,
        top = nedelec ? p - 1 : p;
    std::vector<std::array<int, 3>> m = totalDegree(dim, full), h;
    for(auto &e : totalDegree(dim, top))
      if(e[0] + e[1] + e[2] == top) h.push_back(e);
    int extra = (nedelec && dim == 3) ? 3 : 1;
    Eigen::MatrixXd V =
      Eigen::MatrixXd::Zero(nq * dim, m.size() * dim + h.size() * extra);
    for(int q = 0; q < nq; q++) {
      const double *x = &uvw[3 * q];
      int col = 0;
      for(auto &e : m)
        for(int c = 0; c < dim; c++) V(q * dim + c, col++) = monomial(e, x);
      for(auto &e : h) {
        double v = monomial(e, x);
        if(!nedelec) // x q
          for(int c = 0; c < dim; c++) V(q * dim + c, col) = x[c] * v;
        else if(dim == 2) { // (-y, x) q
          V(q * dim, col) = -x[1] * v;
          V(q * dim + 1, col) = x[0] * v;
        }
        else // x times q e_c
          for(int c = 0; c < 3; c++) {
            double ec[3] = {0., 0., 0.}, r[3];
            ec[c] = v;
            r[0] = x[1] * ec[2] - x[2] * ec[1];
            r[1] = x[2] * ec[0] - x[0] * ec[2];
            r[2] = x[0] * ec[1] - x[1] * ec[0];
            for(int k = 0; k < 3; k++) V(q * dim + k, col + c) = r[k];
          }
        col += (nedelec && dim == 3) ? 3 : 1;
      }
    }
    return V;
  }

  // the columns of the parts of a space next to each other
  static Eigen::MatrixXd join(const Eigen::MatrixXd &A,
                              const Eigen::MatrixXd &B)
  {
    Eigen::MatrixXd C(A.rows(), A.cols() + B.cols());
    C << A, B;
    return C;
  }

  // the keys of the functions of a space
  static std::set<std::pair<int, std::size_t>> keys(std::size_t tag,
                                                    const std::string &fs)
  {
    std::vector<int> tk;
    std::vector<std::size_t> ek;
    std::vector<double> c;
    gmsh::model::mesh::getKeysForElement(tag, fs, tk, ek, c, false);
    std::set<std::pair<int, std::size_t>> k;
    for(std::size_t i = 0; i < tk.size(); i++) k.insert({tk[i], ek[i]});
    return k;
  }

  void testParts()
  {
    Random r(7);
    for(auto &e : elements()) {
      if(e.dim == 0) continue;
      bool simplex =
        (e.name == "line" || e.name == "triangle" || e.name == "tetrahedron");
      for(int numbering = 0; numbering < 2; numbering++) {
        std::vector<std::size_t> nodes = permutation(e.numVertices, r);
        std::size_t tag = singleElement(e, nodes);
        int o;
        gmsh::model::mesh::getBasisFunctionsOrientationForElement(
          tag, "HcurlLegendre1", o);
        // the increments of the H(curl) orders 0.5, 1, 1.5 and 2 of GetDP are
        // disjoint, and add up to the spaces of these orders
        if(e.dim >= 1) {
          const char *names[4] = {"HcurlLegendre0", "HcurlLegendre1:1",
                                  "HcurlLegendreNoGrad2:2",
                                  "HcurlLegendreGrad2:2"};
          std::set<std::pair<int, std::size_t>> sum;
          std::size_t total = 0;
          bool ok = true;
          for(int i = 0; i < 4; i++) {
            auto k = keys(tag, names[i]);
            total += k.size();
            sum.insert(k.begin(), k.end());
            if(i == 2) {
              auto a = keys(tag, "HcurlLegendreNoGrad2"),
                   b = keys(tag, "HcurlLegendreGrad1");
              a.insert(b.begin(), b.end());
              ok = ok && (a == sum);
            }
          }
          ok = ok && total == sum.size() && sum == keys(tag, "HcurlLegendre2");
          check(ok,
                "%s: the increments of GetDP's H(curl) orders do not add "
                "up",
                e.name.c_str());
        }
        for(auto &s : spaces()) {
          if(s.kind == H1 || !supported(s, e)) continue;
          bool curl = (s.kind == HCURL);
          std::string kernel = curl ? "Grad" : "Curl",
                      other = curl ? "NoGrad" : "NoCurl";
          // the divergence-free H(div) functions of 1D H(curl): none
          if(!curl && e.dim < 2) continue;
          // no parts of the H(div) space on prisms (see HdivPrism)
          if(!curl && e.name == "prism") {
            bool error = false;
            try {
              evaluate(e.type, interiorPoints(e, 1, r), "HdivLegendreCurl1",
                       {0});
            } catch(...) {
              error = true;
            }
            check(error, "prism HdivLegendreCurl1: no error");
            continue;
          }
          int nc = e.dim;
          for(int p = s.minOrder; p < maxOrder(e); p++) {
            std::string fs = spaceType(s, p);
            std::string fk = s.name + kernel + std::to_string(p);
            std::string fo = s.name + other + std::to_string(p);
            const char *n = e.name.c_str(), *f = fs.c_str();
            // enough points for the ranks to be meaningful
            int nf =
              evaluate(e.type, interiorPoints(e, 1, r), fs, {0}).numFunctions;
            std::vector<double> uvw = interiorPoints(e, 3 * nf + 10, r);

            // a filter of the whole space
            KeyedFunctions all = keyedFunctions(tag, e, uvw, fs),
                           k = keyedFunctions(tag, e, uvw, fk),
                           c = keyedFunctions(tag, e, uvw, fo);
            bool same = (k.size() + c.size() == all.size());
            for(auto *part : {&k, &c})
              for(auto &kv : *part) {
                auto it = all.find(kv.first);
                if(it == all.end() || it->second.type != kv.second.type ||
                   it->second.order != kv.second.order) {
                  same = false;
                  continue;
                }
                for(std::size_t j = 0; j < kv.second.values.size(); j++)
                  if(std::abs(kv.second.values[j] - it->second.values[j]) >
                     1e-14 * std::max(1., std::abs(it->second.values[j])))
                    same = false;
              }
            check(same,
                  "%s %s: the parts (%d and %d functions) are not the %d "
                  "functions of the space",
                  n, f, (int)k.size(), (int)c.size(), (int)all.size());

            Table tk = evaluate(e.type, uvw, fk, {o});
            Table to = evaluate(e.type, uvw, fo, {o});
            Table dk = evaluate(e.type, uvw,
                                s.derivative + kernel + std::to_string(p), {o});
            Table d = evaluate(e.type, uvw,
                               s.derivative + other + std::to_string(p), {o});
            double dmax = 0.;
            for(double v : dk.data) dmax = std::max(dmax, std::abs(v));
            check(dmax < 1e-12, "%s %s: the %s functions have a %s (%g)", n, f,
                  kernel.c_str(), curl ? "curl" : "divergence", dmax);
            // the dependencies between the lowest order functions: the
            // gradients of the vertex functions (H(curl), and H(div) in 2D),
            // the curls of the lowest order H(curl) functions (H(div) in 3D)
            int numEdges = (e.dim == 2)              ? e.numVertices :
                           (e.name == "tetrahedron") ? 6 :
                           (e.name == "prism")       ? 9 :
                                                       12;
            int lowest = (curl || e.dim == 2) ? e.numVertices - 1 :
                                                numEdges - e.numVertices + 1;
            int dr = rank(columns(d, 0, d.numComponents));
            if(e.dim >= 2)
              check(dr == to.numFunctions - lowest,
                    "%s %s: the %ss of the %d %s functions have rank %d, "
                    "expected %d",
                    n, f, curl ? "curl" : "divergence", to.numFunctions,
                    other.c_str(), dr, to.numFunctions - lowest);

            if(curl) {
              // the gradients of the H1 functions of order p + 1
              Table g = evaluate(e.type, uvw,
                                 "GradH1Legendre" + std::to_string(p + 1), {o});
              Eigen::MatrixXd G = columns(g, 0, nc), K = columns(tk, 0, nc);
              int found = 0;
              for(int j = 0; j < K.cols(); j++)
                for(int i = e.numVertices; i < G.cols(); i++)
                  if((K.col(j) - G.col(i)).norm() <
                     1e-12 * std::max(1., G.col(i).norm())) {
                    found++;
                    break;
                  }
              check(found == K.cols() && K.cols() == G.cols() - e.numVertices,
                    "%s %s: %d of the %d gradients are gradients of the %d "
                    "non-vertex H1 functions of order %d",
                    n, f, found, (int)K.cols(), (int)G.cols() - e.numVertices,
                    p + 1);
            }
            else if(e.dim == 3) {
              // curls of HcurlLegendreNoGrad
              int q = (e.name == "tetrahedron") ? p + 1 : p;
              Table cn =
                evaluate(e.type, uvw,
                         "CurlHcurlLegendreNoGrad" + std::to_string(q), {o});
              double res = spanResidual(columns(cn, 0, 3), columns(tk, 0, 3));
              check(res < tol,
                    "%s %s: the divergence-free functions are not curls of "
                    "HcurlLegendreNoGrad%d (%g)",
                    n, f, q, res);
            }

            // the first kind Nedelec and the Raviart-Thomas spaces
            if(!simplex || e.dim < 2) continue;
            Eigen::MatrixXd A;
            if(curl) {
              if(p < 1) continue;
              Table g = evaluate(e.type, uvw,
                                 s.name + kernel + std::to_string(p - 1), {o});
              A = join(columns(to, 0, nc), columns(g, 0, nc));
            }
            else {
              Table g = evaluate(e.type, uvw,
                                 s.name + other + std::to_string(p + 1), {o});
              A = join(columns(tk, 0, nc), columns(g, 0, nc));
            }
            Eigen::MatrixXd V = nedelecOrRaviartThomas(e.dim, p, curl, uvw);
            int dim = rank(V), ra = rank(A);
            double res = spanResidual(V, A);
            check(ra == A.cols() && ra == dim && res < tol,
                  "%s %s: %d functions of rank %d for the %s space of "
                  "dimension %d (residual %g)",
                  n, f, (int)A.cols(), ra,
                  curl ? "Nedelec first kind" : "Raviart-Thomas", dim, res);
          }
        }
      }
    }
  }

} // namespace bt
