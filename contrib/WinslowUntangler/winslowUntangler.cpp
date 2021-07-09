// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol
//
// This module re-implements the constrained 2d/3d untangler described in the
// paper:
//
//      Foldover-free maps in 50 lines of code.
//      Garanzha, V., Kaporin, I., Kudryavtseva, L., Protais, F., Ray, N., &
//      Sokolov, D. (2021). arXiv preprint arXiv:2102.03069.
//
//  whose reference implementation is available at:
//  https://github.com/ssloy/invertible-maps
//
//  The untangler is re-implemented here to avoid the dependencies of the
//  reference implementation and to use the LBFGS solver available in Gmsh
//  (ALGLIB). The goal is to have the same behavior.

#include "winslowUntangler.h"

#include <math.h>
#include <iostream> // debugging
#include <cfloat>

#include "Context.h"
#include "GmshMessage.h"
#include "OS.h"

#if defined(HAVE_EIGEN)
#include <Eigen/Core>
#include <Eigen/Dense>
#endif

#if defined(HAVE_ALGLIB)
#include <stdafx.h>
#include <optimization.h>
#endif

#if defined(HAVE_EIGEN) && defined(HAVE_ALGLIB)

namespace WinslowUntangler {
  /* Copy useful functions from contrib/QuadMeshingTools/arrayGeometry.h
   * because this functions should work without QUADMESHINGTOOLS module */

  using vec3 = std::array<double, 3>;
  inline vec3 operator-(const vec3 &a, const vec3 &b)
  {
    return {{a[0] - b[0], a[1] - b[1], a[2] - b[2]}};
  }
  inline vec3 operator+(const vec3 &a, const vec3 &b)
  {
    return {{a[0] + b[0], a[1] + b[1], a[2] + b[2]}};
  }
  inline vec3 operator*(const double &a, const vec3 &b)
  {
    return {{a * b[0], a * b[1], a * b[2]}};
  }
  inline vec3 operator*(const vec3 &a, const double &b)
  {
    return {{a[0] * b, a[1] * b, a[2] * b}};
  }
  inline double dot(const vec3 &a, const vec3 &b)
  {
    return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
  }
  inline vec3 cross(const vec3 &a, const vec3 &b)
  {
    return {{a[1] * b[2] - a[2] * b[1], a[2] * b[0] - a[0] * b[2],
             a[0] * b[1] - a[1] * b[0]}};
  }
  inline double length2(const vec3 &a) { return dot(a, a); }
  inline double maxAbs(double x, double y, double z)
  {
    return std::max(std::abs(x), std::max(std::abs(y), std::abs(z)));
  }
  inline double maxAbs(const vec3 &a) { return maxAbs(a[0], a[1], a[2]); }
  inline void normalizeFast(vec3 &a)
  {
    a = 1. / std::sqrt(length2(a)) * a;
  } /* no check, not safe, not accurate */
  inline void normalize(vec3 &a)
  {
    double amp = maxAbs(a);
    if(amp == 0.) { return; }
    a = amp * a;
    normalizeFast(a);
  }

  using vec2 = std::array<double, 2>;
  inline vec2 operator-(const vec2 &a, const vec2 &b)
  {
    return {{a[0] - b[0], a[1] - b[1]}};
  }
  inline vec2 operator+(const vec2 &a, const vec2 &b)
  {
    return {{a[0] + b[0], a[1] + b[1]}};
  }
  inline vec2 operator*(const double &a, const vec2 &b)
  {
    return {{a * b[0], a * b[1]}};
  }
  inline vec2 operator*(const vec2 &a, const double &b)
  {
    return {{a[0] * b, a[1] * b}};
  }
  inline double dot(const vec2 &a, const vec2 &b)
  {
    return a[0] * b[0] + a[1] * b[1];
  }

  inline double area(vec2 a, vec2 b, vec2 c)
  {
    return .5 * ((b[1] - a[1]) * (b[0] + a[0]) + (c[1] - b[1]) * (c[0] + b[0]) +
                 (a[1] - c[1]) * (a[0] + c[0]));
  }

  void bbox_minmax(const std::vector<vec3> &points, vec3 &bmin, vec3 &bmax)
  {
    bmin = {DBL_MAX, DBL_MAX, DBL_MAX};
    bmax = {-DBL_MAX, -DBL_MAX, -DBL_MAX};
    for(size_t i = 0; i < points.size(); ++i)
      for(size_t d = 0; d < 3; ++d) {
        bmin[d] = std::min(points[i][d], bmin[d]);
        bmax[d] = std::max(points[i][d], bmax[d]);
      }
  }

  void bbox_minmax(const std::vector<vec2> &points, vec2 &bmin, vec2 &bmax)
  {
    bmin = {DBL_MAX, DBL_MAX};
    bmax = {-DBL_MAX, -DBL_MAX};
    for(size_t i = 0; i < points.size(); ++i)
      for(size_t d = 0; d < 2; ++d) {
        bmin[d] = std::min(points[i][d], bmin[d]);
        bmax[d] = std::max(points[i][d], bmax[d]);
      }
  }

  double area(const std::vector<std::array<double, 2> > &points,
              const std::vector<std::array<uint32_t, 3> > &triangles)
  {
    double sum = 0.;
    for(size_t i = 0; i < triangles.size(); ++i) {
      sum += area(points[triangles[i][0]], points[triangles[i][1]],
                  points[triangles[i][2]]);
    }
    return sum;
  }

  inline double volume(vec3 a, vec3 b, vec3 c, vec3 d)
  {
    return dot((a - d), cross(b - d, c - d)) / 6.;
  }

  double volume(const std::vector<std::array<double, 3> > &points,
                const std::vector<std::array<uint32_t, 4> > &tets)
  {
    double sum = 0.;
    for(size_t i = 0; i < tets.size(); ++i) {
      double tvol = volume(points[tets[i][0]], points[tets[i][1]],
                           points[tets[i][2]], points[tets[i][3]]);
      // printf("- tet %li: %.3f\n", i, tvol);
      sum += tvol;
    }
    return sum;
  }

  struct UntanglerData2D {
    double theta = 0.5;
    double detmin = 0;
    int ninverted = 0;
    double eps = 0.;
    std::vector<bool> locked;
    std::vector<std::array<uint32_t, 3> > triangles;
    std::vector<Eigen::Matrix<double, 3, 2> > ref_tri;
    std::vector<Eigen::Matrix<double, 2, 2> > J;
    std::vector<Eigen::Matrix<double, 2, 2> > K;
    std::vector<double> det;
  };

  void evaluate_jacobian(UntanglerData2D &w, const alglib::real_1d_array &X)
  {
    w.detmin = std::numeric_limits<double>::max();
    w.ninverted = 0;
    for(size_t t = 0; t < w.triangles.size(); ++t) {
      w.J[t].setZero();
      for(size_t i = 0; i < 2; ++i) {
        for(size_t j = 0; j < 2; ++j) {
          for(size_t k = 0; k < 3; ++k) {
            w.J[t](i, j) += w.ref_tri[t](k, j) * X[2 * w.triangles[t][k] + i];
          }
        }
      }
      w.det[t] = w.J[t].determinant();
      w.detmin = std::min(w.detmin, w.det[t]);
      w.ninverted += (w.det[t] <= 0);
      // dual basis
      w.K[t](0, 0) = w.J[t](1, 1);
      w.K[t](0, 1) = -w.J[t](1, 0);
      w.K[t](1, 0) = -w.J[t](0, 1);
      w.K[t](1, 1) = w.J[t](0, 0);
    }
  }

  inline double chi(double eps, double det)
  {
    if(det > 0) return (det + std::sqrt(eps * eps + det * det)) * .5;
    return .5 * eps * eps / (std::sqrt(eps * eps + det * det) - det);
  }

  inline double chi_deriv(double eps, double det)
  {
    return .5 + det / (2. * std::sqrt(eps * eps + det * det));
  }

  double evaluate_energy(UntanglerData2D &w, const alglib::real_1d_array &X)
  {
    evaluate_jacobian(w, X);
    double E = 0;
    for(int t = 0; t < w.triangles.size(); t++) {
      double chi_ = chi(w.eps, w.det[t]);
      double f = (w.J[t].transpose() * w.J[t]).trace() / chi_;
      double g = (1 + std::pow(w.det[t], 2)) / chi_;
      E += (1. - w.theta) * f + w.theta * g;
    }
    if(std::isnan(E)) { E = std::numeric_limits<double>::max(); }
    return E;
  }

  void print_array(const alglib::real_1d_array &x, const std::string &name = "")
  {
    std::cout << name << ": ";
    for(size_t i = 0; i < x.length(); ++i) { std::cout << " " << x[i]; }
    std::cout << std::endl;
  }

  void lbfgs_callback_2D(const alglib::real_1d_array &x, double &func,
                         alglib::real_1d_array &grad, void *ptr)
  {
    const size_t DIM = 2;
    UntanglerData2D *wp = static_cast<UntanglerData2D *>(ptr);
    UntanglerData2D &w = *wp;
    for(size_t i = 0; i < grad.length(); ++i) { grad[i] = 0; }

    func = evaluate_energy(w, x);

    // gradient
    for(int t = 0; t < w.triangles.size(); t++) {
      double c1 = chi(w.eps, w.det[t]);
      double c2 = chi_deriv(w.eps, w.det[t]);

      double f = (w.J[t].transpose() * w.J[t]).trace() / c1;
      double g = (1 + std::pow(w.det[t], 2)) / c1;

      for(size_t d = 0; d < DIM; ++d) {
        vec2 a = {w.J[t](d, 0), w.J[t](d, 1)}; // tangent basis
        vec2 b = {w.K[t](d, 0), w.K[t](d, 1)}; // dual basis
        // printf("a=%f %f | b=%f %f | c1=%f c2=%f | f=%f g=%f det=%f\n",
        //     a[0], a[1], b[0], b[1], c1, c2, f, g, w.det[t]);
        vec2 dfda = (a * 2. - b * f * c2) * (1. / c1);
        vec2 dgda = b * (2 * w.det[t] - g * c2) * (1. / c1);
        for(int i = 0; i < 3; i++) {
          uint32_t v = w.triangles[t][i];
          if(!w.locked[v]) {
            vec2 n = {w.ref_tri[t](i, 0), w.ref_tri[t](i, 1)};
            grad[v * DIM + d] +=
              dot((dfda * (1. - w.theta) + dgda * w.theta), n);
            // printf("---v=%i,dim=%li | dfda=(%f %f), dgda=(%f %f),  G+=%f\n",
            //     v, d, dfda[0], dfda[1], dgda[0], dgda[1],
            //     dot((dfda*(1.-w.theta) + dgda*w.theta), n));
          }
        }
      }
    }
    // Msg::Debug("- F = %f:", func);
    // print_array(x,"X");
    // print_array(grad,"gradient");
  }

  struct UntanglerData3D {
    double theta = 0.5;
    double detmin = 0;
    int ninverted = 0;
    double eps = 1.e-3;
    std::vector<bool> locked;
    std::vector<std::array<uint32_t, 4> > tets;
    std::vector<std::array<vec3, 4> > ref_tets;
    std::vector<Eigen::Matrix<double, 3, 3> > J;
    std::vector<Eigen::Matrix<double, 3, 3> > K;
    std::vector<double> det;
  };

  bool prepareReferenceTets(
    const std::vector<std::array<double, 3> > &points,
    const std::vector<std::array<uint32_t, 4> > &tets,
    const std::vector<std::array<std::array<double, 3>, 4> > &tetIdealShapes,
    UntanglerData3D &w)
  { // prepare the reference tetrahedron
    constexpr int facet_vertex[4][3] = {
      {1, 3, 2}, {0, 2, 3}, {3, 1, 0}, {0, 1, 2}};
    w.ref_tets.resize(tetIdealShapes.size());
    if(tetIdealShapes.size() != 0 &&
       tetIdealShapes.size() != (size_t)tets.size()) {
      Msg::Error(
        "Winslow untangler 3D: incoherent sizes in prepareReferenceTets");
      return false;
    }

    double total_vol = volume(points, tets);
    double volume = total_vol / double(w.tets.size());

    for(size_t t = 0; t < tets.size(); ++t) {
      vec3 tet[4] = {{.5, 0, -1. / (2. * std::sqrt(2.))},
                     {-.5, 0, -1. / (2. * std::sqrt(2.))},
                     {0, .5, 1. / (2. * std::sqrt(2.))},
                     {0, -.5, 1. / (2. * std::sqrt(2.))}};
      if(tetIdealShapes.size() > 0) {
        tet[0] = {tetIdealShapes[t][0][0], tetIdealShapes[t][0][1],
                  tetIdealShapes[t][0][2]};
        tet[1] = {tetIdealShapes[t][1][0], tetIdealShapes[t][1][1],
                  tetIdealShapes[t][1][2]};
        tet[2] = {tetIdealShapes[t][2][0], tetIdealShapes[t][2][1],
                  tetIdealShapes[t][2][2]};
        tet[3] = {tetIdealShapes[t][3][0], tetIdealShapes[t][3][1],
                  tetIdealShapes[t][3][2]};
      }
      // scale the tet
      double a = std::cbrt(volume * 6. * std::sqrt(2.));
      for(size_t lv = 0; lv < 4; ++lv) { tet[lv] = tet[lv] * a; }
      // prepare the data for gradient processing: compute the normal vectors
      for(size_t lf = 0; lf < 4; ++lf) {
        vec3 e0 = tet[facet_vertex[lf][1]] - tet[facet_vertex[lf][0]];
        vec3 e1 = tet[facet_vertex[lf][2]] - tet[facet_vertex[lf][0]];
        w.ref_tets[t][lf] = -1. * (cross(e0, e1) * 0.5) * (1. / (3. * volume));
      }
    }
    return true;
  }

  void evaluate_jacobian(UntanglerData3D &w, const alglib::real_1d_array &X)
  {
    // std::cout << "########## EVALUATE JACOBIAN ##########\n";
    w.detmin = std::numeric_limits<double>::max();
    w.ninverted = 0;
    for(size_t t = 0; t < w.tets.size(); ++t) {
      w.J[t].setZero();
      for(size_t i = 0; i < 3; ++i) {
        for(size_t j = 0; j < 3; ++j) {
          for(size_t k = 0; k < 4; ++k) {
            w.J[t](i, j) += w.ref_tets[t][k][j] * X[3 * w.tets[t][k] + i];
          }
        }
      }
      w.det[t] = w.J[t].determinant();
      w.detmin = std::min(w.detmin, w.det[t]);
      w.ninverted += (w.det[t] <= 0);
      // dual basis
      auto &Jl = w.J[t];
      auto &Kl = w.K[t];
      Kl(0, 0) = Jl(1, 1) * Jl(2, 2) - Jl(1, 2) * Jl(2, 1);
      Kl(0, 1) = Jl(1, 2) * Jl(2, 0) - Jl(1, 0) * Jl(2, 2);
      Kl(0, 2) = Jl(1, 0) * Jl(2, 1) - Jl(1, 1) * Jl(2, 0);

      Kl(1, 0) = Jl(0, 2) * Jl(2, 1) - Jl(0, 1) * Jl(2, 2);
      Kl(1, 1) = Jl(0, 0) * Jl(2, 2) - Jl(0, 2) * Jl(2, 0);
      Kl(1, 2) = Jl(0, 1) * Jl(2, 0) - Jl(0, 0) * Jl(2, 1);

      Kl(2, 0) = Jl(0, 1) * Jl(1, 2) - Jl(0, 2) * Jl(1, 1);
      Kl(2, 1) = Jl(0, 2) * Jl(1, 0) - Jl(0, 0) * Jl(1, 2);
      Kl(2, 2) = Jl(0, 0) * Jl(1, 1) - Jl(0, 1) * Jl(1, 0);
    }
    // Msg::Debug("- detmin: %f, ninverted = %i", w.detmin, w.ninverted);
  }

  double evaluate_energy(UntanglerData3D &w, const alglib::real_1d_array &X)
  {
    // std::cout << "########## EVALUATE ENERGY ##########\n";
    evaluate_jacobian(w, X);
    double E = 0;
    for(int t = 0; t < w.tets.size(); t++) {
      double chi_ = chi(w.eps, w.det[t]);
      double f =
        (w.J[t].transpose() * w.J[t]).trace() / std::pow(chi_, 2. / 3.);
      double g = (1 + std::pow(w.det[t], 2)) / chi_;
      E += (1. - w.theta) * f + w.theta * g;
      // Msg::Debug("-- %i: f=%f g=%f chi=%f --- E += %f", t, f, g, chi_,
      // (1.-w.theta)*f + w.theta*g);
    }
    if(std::isnan(E)) { E = std::numeric_limits<double>::max(); }
    // Msg::Debug("- energy: %f (eps: %f)", E, w.eps);
    std::cout << std::flush;
    return E;
  }

  void lbfgs_callback_3D(const alglib::real_1d_array &x, double &func,
                         alglib::real_1d_array &grad, void *ptr)
  {
    const size_t DIM = 3;
    UntanglerData3D *wp = static_cast<UntanglerData3D *>(ptr);
    UntanglerData3D &w = *wp;
    for(size_t i = 0; i < grad.length(); ++i) { grad[i] = 0; }

    func = evaluate_energy(w, x);

    // gradient
    for(int t = 0; t < w.tets.size(); t++) {
      auto &a = w.J[t];
      auto &b = w.K[t];

      double c1 = chi(w.eps, w.det[t]);
      double c2 = std::pow(c1, 2. / 3.);
      double c3 = chi_deriv(w.eps, w.det[t]);
      // printf("--t=%i | det=%.3f, c1=%.3f, c2=%.3f,
      // c3=%.3f\n",t,w.det[t],c1,c2,c3);

      double f = (w.J[t].transpose() * w.J[t]).trace() / c2;
      double g = (1 + std::pow(w.det[t], 2)) / c1;

      for(size_t d = 0; d < DIM; ++d) {
        auto dfda =
          a.row(d) * (2. / c2) - b.row(d) * ((2. * f * c3) / (3. * c1));
        auto dgda = b.row(d) * ((2 * w.det[t] - g * c3) / c1);
        for(int i = 0; i < 4; i++) {
          uint32_t v = w.tets[t][i];
          if(!w.locked[v]) {
            Eigen::Vector3d n = {w.ref_tets[t][i][0], w.ref_tets[t][i][1],
                                 w.ref_tets[t][i][2]};
            double contrib = (dfda * (1. - w.theta) + dgda * w.theta) * n;
            grad[v * DIM + d] += contrib;

            // printf("---v=%i,dim=%li | dfda=(%f %f %f), dgda=(%f %f %f),
            // G+=%f\n",
            //     v, d, dfda[0], dfda[1], dfda[2], dgda[0], dgda[1], dgda[2],
            //     contrib);
          }
        }
      }
    }
    // Msg::Info("- F = %f:", func);
    // print_array(x,"X");
    // print_array(grad,"gradient");
  }

  bool scaleToBoxSize(std::vector<std::array<double, 2> > &points, vec2 &bbmin,
                      vec2 &bbmax, double boxsize = 10., double shrink = 1.3)
  {
    bbox_minmax(points, bbmin, bbmax);
    const vec2 unit = {1., 1.};
    const vec2 center = (bbmin + bbmax) * 0.5;
    double maxside = std::max(bbmax[0] - bbmin[0], bbmax[1] - bbmin[1]);
    for(size_t v = 0; v < points.size(); ++v) {
      points[v] = (points[v] - center) * (boxsize / (shrink * maxside)) +
                  unit * boxsize * 0.5;
    }
    return true;
  }

  bool unscale(std::vector<std::array<double, 2> > &points, vec2 bbmin,
               vec2 bbmax, double boxsize = 10., double shrink = 1.3)
  {
    const vec2 unit = {1., 1.};
    const vec2 center = (bbmin + bbmax) * 0.5;
    double maxside = std::max(bbmax[0] - bbmin[0], bbmax[1] - bbmin[1]);
    for(size_t v = 0; v < points.size(); ++v) {
      points[v] =
        (points[v] - unit * boxsize * 0.5) * ((shrink * maxside) / boxsize) +
        center;
    }
    return true;
  }

  bool scaleToBoxSize(std::vector<std::array<double, 3> > &points, vec3 &bbmin,
                      vec3 &bbmax, double boxsize = 10., double shrink = 1.3)
  {
    bbox_minmax(points, bbmin, bbmax);
    const vec3 unit = {1., 1., 1.};
    const vec3 center = (bbmin + bbmax) * 0.5;
    double maxside = std::max(bbmax[0] - bbmin[0], bbmax[1] - bbmin[1]);
    maxside = std::max(maxside, bbmax[2] - bbmin[2]);
    for(size_t v = 0; v < points.size(); ++v) {
      points[v] = (points[v] - center) * (boxsize / (shrink * maxside)) +
                  unit * boxsize * 0.5;
    }
    return true;
  }

  bool unscale(std::vector<std::array<double, 3> > &points, vec3 bbmin,
               vec3 bbmax, double boxsize = 10., double shrink = 1.3)
  {
    const vec3 unit = {1., 1., 1.};
    const vec3 center = (bbmin + bbmax) * 0.5;
    double maxside = std::max(bbmax[0] - bbmin[0], bbmax[1] - bbmin[1]);
    maxside = std::max(maxside, bbmax[2] - bbmin[2]);
    for(size_t v = 0; v < points.size(); ++v) {
      points[v] =
        (points[v] - unit * boxsize * 0.5) * ((shrink * maxside) / boxsize) +
        center;
    }
    return true;
  }
} // namespace WinslowUntangler

using namespace WinslowUntangler;

#endif

bool untangle_triangles_2D(
  std::vector<std::array<double, 2> > &points, const std::vector<bool> &locked,
  const std::vector<std::array<uint32_t, 3> > &triangles,
  const std::vector<std::array<std::array<double, 3>, 3> > &triIdealShapes,
  double theta, int iterMaxInner, int iterMaxOuter, int iterFailMax,
  double timeMax)
{
#if defined(HAVE_EIGEN) && defined(HAVE_ALGLIB)

  const size_t NV = points.size();
  const size_t NT = triangles.size();
  if(NV == 0 || NT == 0) {
    Msg::Error(
      "Winslow untangler 2D: wrong input sizes: %li vertices, %li triangles",
      NV, NT);
    return false;
    ;
  }

  vec2 bbmin, bbmax;
  scaleToBoxSize(points, bbmin, bbmax);

  double total_area = area(points, triangles);
  double avg_area = total_area / double(triangles.size());
  Msg::Debug(
    "Winslow untangler 2D: %li points, %li triangles, total area: %.3f",
    points.size(), triangles.size(), total_area);

  if(triIdealShapes.size() > 0) {
    Msg::Warning(
      "Winslow untangler 2D: ideal triangle shapes not supported yet");
  }

  // Initialization
  const size_t DIM = 2;
  UntanglerData2D w;
  w.theta = theta;
  w.locked = locked;
  w.triangles = triangles;
  w.ref_tri.resize(NT);
  w.J.resize(NT);
  w.K.resize(NT);
  w.det.resize(NT);

  for(size_t t = 0; t < NT; ++t) {
    double a = std::sqrt(4 * avg_area / std::sqrt(3.));
    // equilateral triangle with unit side length (sqrt(3)/4 area): three
    // non-unit normal vectors
    double c = a / (-2. * avg_area);
    w.ref_tri[t] << c * 0., -c * 1., c * std::sqrt(3.) / 2., c * .5,
      -c * std::sqrt(3.) / 2., c * .5;
  }

  /* Initialize jacobian computations */
  alglib::real_1d_array x0;
  x0.setcontent(DIM * points.size(), points.front().data());
  double E_prev = evaluate_energy(w, x0);

  /* Optimization loop */
  double detmin_prev = 0.;
  int ninverted_prev = 0;
  int nFail = 0;
  w.eps = 0;
  double t0 = Cpu();
  bool converged = false;

  double e0 = 1.e-3;
  for(int iter = 0; iter < iterMaxOuter; iter++) {
    if(iter && iter % 10 == 0 && e0 > 1e-10) e0 /= 2.;
    w.eps =
      w.detmin > 0 ? e0 : std::sqrt(e0 * e0 + 0.04 * (w.detmin * w.detmin));

    // Copy positions in solver array
    alglib::real_1d_array x;
    x.setcontent(DIM * points.size(), points.front().data());

    // Setup of the LBFGS solver
    alglib::ae_int_t dim = 2 * NV;
    alglib::ae_int_t corr = 3; // Num of corrections in the scheme in [3,7]
    alglib::minlbfgsstate state;
    alglib::minlbfgsreport rep;

    minlbfgscreate(dim, corr, x, state);

    // stopping criteria
    const double epsg = 1.e-12;
    const double epsf = 0.;
    const double epsx = 0.;
    const alglib::ae_int_t maxits = iterMaxInner;
    minlbfgssetcond(state, epsg, epsf, epsx, maxits);

    // run
    minlbfgsoptimize(state, lbfgs_callback_2D, nullptr, &w);

    // Get results
    minlbfgsresults(state, x, rep);
    for(size_t v = 0; v < NV; ++v) {
      points[v][0] = x[2 * v + 0];
      points[v][1] = x[2 * v + 1];
    }
    if(rep.terminationtype != 4) { nFail += 1; }

    double E = evaluate_energy(w, x);
    double dErel = std::abs(E - E_prev) / E;
    Msg::Debug(
      "- iter %i: eps = %f, E: %.3e, dE/E=%.3e, detmin=%f, ninverted=%i", iter,
      w.eps, E, dErel, w.detmin, w.ninverted);

    if(w.detmin > 0 && dErel < 1e-5) {
      converged = true;
      Msg::Debug("- iter %i: converged |E-E_prev|/E = %.3e < 1.e-5", iter,
                 dErel);
      break;
    }

    if(nFail > iterFailMax) {
      Msg::Debug("- iter %i: reached maximum number of failures (%i)", iter,
                 nFail);
      break;
    }

    if(Cpu() - t0 > timeMax) {
      Msg::Debug("- iter %i: reached time max (%f sec)", iter, Cpu() - t0);
      break;
    }

    detmin_prev = w.detmin;
    ninverted_prev = w.ninverted;
    E_prev = E;

    // TODO try catch around LBFGS ?
  }

  unscale(points, bbmin, bbmax);

  return converged;

#else

  Msg::Error("Winslow untangler requires Eigen and Alglib");
  return false;

#endif
}

bool untangle_tetrahedra(
  std::vector<std::array<double, 3> > &points, const std::vector<bool> &locked,
  const std::vector<std::array<uint32_t, 4> > &tets,
  const std::vector<std::array<std::array<double, 3>, 4> > &tetIdealShapes,
  double theta, int iterMaxInner, int iterMaxOuter, int iterFailMax,
  double timeMax)
{
#if defined(HAVE_EIGEN) && defined(HAVE_ALGLIB)

  const size_t NV = points.size();
  const size_t NT = tets.size();
  if(NV == 0 || NT == 0) {
    Msg::Error(
      "Winslow untangler 3D: wrong input sizes: %li vertices, %li tets", NV,
      NT);
    return false;
    ;
  }

  vec3 bbmin, bbmax;
  scaleToBoxSize(points, bbmin, bbmax);

  double total_vol = volume(points, tets);
  double avg_vol = total_vol / double(tets.size());
  Msg::Debug("Winslow untangler 3D: %li points, %li tets, total volume: %.3f",
             points.size(), tets.size(), total_vol);

  // Initialization
  const size_t DIM = 3;
  UntanglerData3D w;
  w.theta = theta;
  w.locked = locked;
  w.tets = tets;
  w.ref_tets.resize(NT);
  w.J.resize(NT);
  w.K.resize(NT);
  w.det.resize(NT);
  prepareReferenceTets(points, tets, tetIdealShapes, w);

  /* Initialize jacobian computations */
  alglib::real_1d_array x0;
  x0.setcontent(DIM * points.size(), points.front().data());
  double E_prev = evaluate_energy(w, x0);

  /* Optimization loop */
  double detmin_prev = 0.;
  int ninverted_prev = 0;
  int nFail = 0;
  w.eps = 0;
  double t0 = Cpu();
  bool converged = false;

  double e0 = 1.e-3;
  for(int iter = 0; iter < iterMaxOuter; iter++) {
    if(iter && iter % 10 == 0 && e0 > 1e-10) e0 /= 2.;
    w.eps =
      w.detmin > 0 ? e0 : std::sqrt(e0 * e0 + 0.04 * (w.detmin * w.detmin));

    // Copy positions in solver array
    alglib::real_1d_array x;
    x.setcontent(DIM * points.size(), points.front().data());

    // Setup of the LBFGS solver
    alglib::ae_int_t N = 3 * NV;
    alglib::ae_int_t corr = 3; // Num of corrections in the scheme in [3,7]
    alglib::minlbfgsstate state;
    alglib::minlbfgsreport rep;

    minlbfgscreate(N, corr, x, state);

    // stopping criteria
    // TODO: these values may not be optimal / right
    const double epsg = 0.1;
    const double epsf = 0.;
    const double epsx = 0.;
    const alglib::ae_int_t maxits = iterMaxInner;
    minlbfgssetcond(state, epsg, epsf, epsx, maxits);

    // run
    minlbfgsoptimize(state, lbfgs_callback_3D, nullptr, &w);

    // Get results
    minlbfgsresults(state, x, rep);
    for(size_t v = 0; v < NV; ++v) {
      points[v][0] = x[DIM * v + 0];
      points[v][1] = x[DIM * v + 1];
      points[v][2] = x[DIM * v + 2];
    }
    if(rep.terminationtype != 4) { nFail += 1; }

    double E = evaluate_energy(w, x);
    double dErel = std::abs(E - E_prev) / E;
    Msg::Debug(
      "- iter %i: eps = %f, E: %.3e, dE/E=%.3e, detmin=%f, ninverted=%i", iter,
      w.eps, E, dErel, w.detmin, w.ninverted);

    if(w.detmin > 0 && dErel < 1e-5) {
      converged = true;
      Msg::Debug("- iter %i: converged |E-E_prev|/E = %.3e < 1.e-5", iter,
                 dErel);
      break;
    }

    if(nFail > iterFailMax) {
      Msg::Debug("- iter %i: reached maximum number of failures (%i)", iter,
                 nFail);
      break;
    }

    if(Cpu() - t0 > timeMax) {
      Msg::Debug("- iter %i: reached time max (%f sec)", iter, Cpu() - t0);
      break;
    }

    detmin_prev = w.detmin;
    ninverted_prev = w.ninverted;
    E_prev = E;

    // TODO try catch around LBFGS ?
  }

  unscale(points, bbmin, bbmax);

  return converged;

#else

  Msg::Error("Winslow untangler requires Eigen and Alglib");
  return false;

#endif
}
