// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author : Maxence Reberol
//        : JF Remacle added the support of P2 triangles, parallelize, vectorize
//        and optimized the code
// This module re-implements the constrained 2d/3d untangler described in the
// paper:
//
//      Foldover-free maps in 50 lines of code.
//      Garanzha, V., Kaporin, I., Kudryavtseva, L., Protais, F., Ray, N., &
//      Sokolov, D. (2021). arXiv preprint arXiv:2102.03069.
//      reference implementation: https://github.com/ssloy/invertible-maps

#include "winslowUntangler.h"

#include <math.h>
#include <algorithm>
#include <cfloat>

#include "gmshLBFGS.h"
#include "GmshMessage.h"
#include "OS.h"

#if defined(_OPENMP)
#include <omp.h>
#endif

#if defined(HAVE_EIGEN)
#include <Eigen/Core>
#include <Eigen/Dense>
#endif

#if defined(HAVE_ALGLIB)
#include <stdafx.h>
#include <optimization.h>
#endif

#if defined(HAVE_QUADMESHINGTOOLS)
#include "arrayGeometry.h"
#include "cppUtils.h"
#endif

size_t perTriangleP2 = 19;

#if defined(HAVE_EIGEN) && defined(HAVE_ALGLIB) &&                             \
  defined(HAVE_QUADMESHINGTOOLS)

using namespace ArrayGeometry;

namespace WinslowUntangler {

  static inline double tri_area(vec2 a, vec2 b, vec2 c)
  {
    return .5 * ((b[1] - a[1]) * (b[0] + a[0]) + (c[1] - b[1]) * (c[0] + b[0]) +
                 (a[1] - c[1]) * (a[0] + c[0]));
  }

  static double area(const std::vector<std::array<double, 2>> &points,
                     const std::vector<std::array<uint32_t, 3>> &triangles)
  {
    double sum = 0.;
    for(size_t i = 0; i < triangles.size(); ++i) {
      sum += tri_area(points[triangles[i][0]], points[triangles[i][1]],
                      points[triangles[i][2]]);
    }
    return sum;
  }

  static inline double tet_volume(vec3 a, vec3 b, vec3 c, vec3 d)
  {
    return dot((a - d), cross(b - d, c - d)) / 6.;
  }

  static double volume(const std::vector<std::array<double, 3>> &points,
                       const std::vector<std::array<uint32_t, 4>> &tets)
  {
    double sum = 0.;
    for(size_t i = 0; i < tets.size(); ++i) {
      double tvol = tet_volume(points[tets[i][0]], points[tets[i][1]],
                               points[tets[i][2]], points[tets[i][3]]);
      sum += tvol;
    }
    return sum;
  }

  static inline double coef_chi(double D, double eps)
  {
    return 0.5 * (D + std::sqrt(eps * eps + D * D));
  }

  static inline double coef_chip(double D, double eps)
  {
    return 0.5 + D / (2. * std::sqrt(eps * eps + D * D));
  }

  // Data of the problem, which are passed to
  // and updated by the callback in the solver
  struct UntanglerData {
    // Parameters
    size_t dim = 2;
    double eps = 0.;
    double lambda = 1.;
    std::vector<bool> locked;

    // Data for 2D planar
    // ---------------------------------------------------
    // -- THIS IS A QUICK FIX --
    // In case of p2 triangles, half of the triangles
    // are used in a standard fashion and the other
    // half is only used for ensuring jacobian positivity
    bool isP2 = false;
    // ---------------------------------------------------
    std::vector<std::array<uint32_t, 3>> triangles;
    std::vector<Eigen::Matrix<double, 3, 2>> tri_normals;

    // Data for 3D volume
    std::vector<std::array<uint32_t, 4>> tetrahedra;
    std::vector<Eigen::Matrix<double, 4, 3>> tet_normals;

    // Data updated during computations
    std::vector<Eigen::Matrix2d> J_mat_2D;
    std::vector<Eigen::Matrix<double, 3, 3>> J_mat_3D;
    std::vector<double> J_det;

    // Stats
    double J_det_min = 0;
    int nb_invalid = 0;
    double energy = 0.;
    double profile_total = 0.;
    double profile_lbfgs = 0.;
    double profile_callback = 0.;
    size_t profile_callback_calls = 0;
    int profile_threads_min = 1000000;
    int profile_threads_max = 0;
    std::vector<double> grad_thread_buffers;
    std::vector<double> element_energy;
  };

  static double update_jacobian_matrix(size_t t, UntanglerData &w,
                                       const std::vector<double> &X)
  {
    if(w.dim == 2) {
      Eigen::Matrix<double, 2, 3> coords;
      for(size_t k = 0; k < 3; ++k) {
        coords(0, k) = X[2 * w.triangles[t][k] + 0];
        coords(1, k) = X[2 * w.triangles[t][k] + 1];
      }
      w.J_mat_2D[t] = (coords * w.tri_normals[t]).transpose();
      const double det = w.J_mat_2D[t].determinant();
      w.J_det[t] = det;
      return det;
    }
    else if(w.dim == 3) {
      Eigen::Matrix<double, 3, 4> coords;
      for(size_t k = 0; k < 4; ++k) {
        coords(0, k) = X[3 * w.tetrahedra[t][k] + 0];
        coords(1, k) = X[3 * w.tetrahedra[t][k] + 1];
        coords(2, k) = X[3 * w.tetrahedra[t][k] + 2];
      }
      w.J_mat_3D[t] = (coords * w.tet_normals[t]).transpose();
      const double det = w.J_mat_3D[t].determinant();
      w.J_det[t] = det;
      return det;
    }
    return -DBL_MAX;
  }

  static void compute_energy_and_gradient_2D_P2(UntanglerData &w,
                                                const std::vector<double> &X,
                                                std::vector<double> &grad,
                                                size_t nElements,
                                                double &energy)
  {
    size_t dT = (perTriangleP2 - 4) / 3;
    //      printf("%zu %zu\n",(w.triangles.size()-nElements)/dT,nElements);
    double signs[5] = {1, 1, -1, -1, -1};
    for(size_t tg = 0; tg < (w.triangles.size() - nElements) / dT; tg++) {
      // Update jacobian with current triangle coordinates
      double det = 0.0;
      for(size_t l = 0; l < dT; l++) {
        size_t t = nElements + tg * dT;
        double D = update_jacobian_matrix(t + l, w, X); //
        det += signs[l] * D;
      }
      // printf("det = %12.5E\n", det);

      // Compute energy contribution from
      // combination of 5 triangles (3 for the moment)
      const double chi = coef_chi(det, w.eps);
      const double chip = coef_chip(det, w.eps);
      const double g_eps = (det * det + 1.) / chi;
      const double Ec = w.lambda * g_eps;

      if(det < w.J_det_min) w.J_det_min = det;
      if(det <= 0.) w.nb_invalid += 1;
      energy += Ec;

      // Compute contribution to global gradient
      for(size_t j = 0; j < dT; j++) {
        size_t t = nElements + tg * dT;
        const double J00 = w.J_mat_2D[t + j](0, 0);
        const double J01 = w.J_mat_2D[t + j](0, 1);
        const double J10 = w.J_mat_2D[t + j](1, 0);
        const double J11 = w.J_mat_2D[t + j](1, 1);
        const double scale =
          w.lambda * signs[j] / chi * (2. * det - g_eps * chip);
        const double d00 = scale * J11;
        const double d10 = -scale * J01;
        const double d01 = -scale * J10;
        const double d11 = scale * J00;

        for(size_t k = 0; k < 3; ++k) {
          uint32_t v = w.triangles[t + j][k];
          if(w.locked[v]) continue;
          const double n0 = w.tri_normals[t + j](k, 0);
          const double n1 = w.tri_normals[t + j](k, 1);
          grad[2 * v + 0] += d00 * n0 + d10 * n1;
          grad[2 * v + 1] += d01 * n0 + d11 * n1;
        }
      }
    }
  }

  static double compute_energy_and_gradient_2D(UntanglerData &w,
                                               const std::vector<double> &X,
                                               std::vector<double> &grad)
  {
    // Initial values
    w.J_det_min = DBL_MAX;
    w.nb_invalid = 0;
    double energy = 0.;

    for(size_t i = 0; i < grad.size(); ++i) grad[i] = 0.;

    // Loop over triangle/tet contributions
    const size_t nElements =
      w.isP2 ? 4 * (w.triangles.size() / perTriangleP2) : w.triangles.size();

    for(size_t t = 0; t < nElements; t++) {
      const auto &tri = w.triangles[t];
      const auto &N = w.tri_normals[t];

      const double x0 = X[2 * tri[0] + 0], y0 = X[2 * tri[0] + 1];
      const double x1 = X[2 * tri[1] + 0], y1 = X[2 * tri[1] + 1];
      const double x2 = X[2 * tri[2] + 0], y2 = X[2 * tri[2] + 1];

      const double J00 = x0 * N(0, 0) + x1 * N(1, 0) + x2 * N(2, 0);
      const double J10 = x0 * N(0, 1) + x1 * N(1, 1) + x2 * N(2, 1);
      const double J01 = y0 * N(0, 0) + y1 * N(1, 0) + y2 * N(2, 0);
      const double J11 = y0 * N(0, 1) + y1 * N(1, 1) + y2 * N(2, 1);

      const double det = J00 * J11 - J01 * J10;
      w.J_mat_2D[t](0, 0) = J00;
      w.J_mat_2D[t](0, 1) = J01;
      w.J_mat_2D[t](1, 0) = J10;
      w.J_mat_2D[t](1, 1) = J11;
      w.J_det[t] = det;

      // Compute energy contribution from triangle
      const double chi = coef_chi(det, w.eps);
      const double chip = coef_chip(det, w.eps);
      const double traceJtJ = J00 * J00 + J10 * J10 + J01 * J01 + J11 * J11;
      const double f_eps = traceJtJ / chi;
      const double g_eps = (det * det + 1.) / chi;
      const double Ec = f_eps + w.lambda * g_eps;
      // printf("%12.5E %12.5E %12.5E %12.5E\n", f_eps, g_eps, det, chi);

      if(det < w.J_det_min) w.J_det_min = det;
      // if(det <= 0.) w.nb_invalid += 1;
      energy += Ec;

      // Compute contribution to global gradient
      const double coeff =
        f_eps * chip - 2. * w.lambda * det + w.lambda * g_eps * chip;
      const double scaleA = 2. / chi;
      const double scaleB = coeff / chi;
      const double d00 = scaleA * J00 - scaleB * J11;
      const double d10 = scaleA * J10 + scaleB * J01;
      const double d01 = scaleA * J01 + scaleB * J10;
      const double d11 = scaleA * J11 - scaleB * J00;

      for(size_t k = 0; k < 3; ++k) {
        uint32_t v = tri[k];
        if(w.locked[v]) continue;
        const double n0 = N(k, 0), n1 = N(k, 1);
        grad[2 * v + 0] += d00 * n0 + d10 * n1;
        grad[2 * v + 1] += d01 * n0 + d11 * n1;
      }
    }

    //    printf("COMPUTING ENERGY eps = %22.15E\n",w.eps);

    if(w.isP2 && 0) {
      compute_energy_and_gradient_2D_P2(w, X, grad, nElements, energy);
    }

    //    printf("energy = %12.5E\n",energy);
    //    exit(1);
    if(std::isnan(energy)) energy = std::numeric_limits<double>::max();
    w.energy = energy;
    return w.energy;
  }

  static double compute_energy_and_gradient3D_scalarized(
    UntanglerData &w, const std::vector<double> &X, std::vector<double> &grad)
  {
    w.J_det_min = DBL_MAX;
    w.nb_invalid = 0;
    double energy = 0.;

    const size_t nElements = w.tetrahedra.size();
    const size_t gradLength = grad.size();
    int nthreads = 1;
#if defined(_OPENMP)
    const int maxThreads3DScalarized = 8;
    nthreads = (nElements < (size_t)maxThreads3DScalarized) ?
                 (int)nElements :
                 maxThreads3DScalarized;
    if(nthreads < 1) nthreads = 1;
    omp_set_dynamic(0);
#endif
    if(w.grad_thread_buffers.size() != (size_t)nthreads * gradLength)
      w.grad_thread_buffers.assign((size_t)nthreads * gradLength, 0.);
    if(w.element_energy.size() != nElements) w.element_energy.resize(nElements);
    std::vector<double> &GL = w.grad_thread_buffers;

#if defined(_OPENMP)
#pragma omp parallel num_threads(nthreads)
#endif
    {
#if defined(_OPENMP)
      int thread_num = omp_get_thread_num();
      int actual_threads = omp_get_num_threads();
#else
      int thread_num = 0;
      int actual_threads = 1;
#endif
#if defined(_OPENMP)
#pragma omp single
#endif
      {
        if(actual_threads < w.profile_threads_min)
          w.profile_threads_min = actual_threads;
        if(actual_threads > w.profile_threads_max)
          w.profile_threads_max = actual_threads;
      }
      double *gradLocal = &GL[thread_num * gradLength];
      for(size_t i = 0; i < gradLength; ++i) gradLocal[i] = 0.;

      const size_t tBegin =
        nElements * (size_t)thread_num / (size_t)actual_threads;
      const size_t tEnd =
        nElements * (size_t)(thread_num + 1) / (size_t)actual_threads;
      for(size_t t = tBegin; t < tEnd; t++) {
        const auto &tet = w.tetrahedra[t];
        const auto &N = w.tet_normals[t];

        const double x0 = X[3 * tet[0] + 0], y0 = X[3 * tet[0] + 1],
                     z0 = X[3 * tet[0] + 2];
        const double x1 = X[3 * tet[1] + 0], y1 = X[3 * tet[1] + 1],
                     z1 = X[3 * tet[1] + 2];
        const double x2 = X[3 * tet[2] + 0], y2 = X[3 * tet[2] + 1],
                     z2 = X[3 * tet[2] + 2];
        const double x3 = X[3 * tet[3] + 0], y3 = X[3 * tet[3] + 1],
                     z3 = X[3 * tet[3] + 2];

        const double J00 =
          x0 * N(0, 0) + x1 * N(1, 0) + x2 * N(2, 0) + x3 * N(3, 0);
        const double J10 =
          x0 * N(0, 1) + x1 * N(1, 1) + x2 * N(2, 1) + x3 * N(3, 1);
        const double J20 =
          x0 * N(0, 2) + x1 * N(1, 2) + x2 * N(2, 2) + x3 * N(3, 2);
        const double J01 =
          y0 * N(0, 0) + y1 * N(1, 0) + y2 * N(2, 0) + y3 * N(3, 0);
        const double J11 =
          y0 * N(0, 1) + y1 * N(1, 1) + y2 * N(2, 1) + y3 * N(3, 1);
        const double J21 =
          y0 * N(0, 2) + y1 * N(1, 2) + y2 * N(2, 2) + y3 * N(3, 2);
        const double J02 =
          z0 * N(0, 0) + z1 * N(1, 0) + z2 * N(2, 0) + z3 * N(3, 0);
        const double J12 =
          z0 * N(0, 1) + z1 * N(1, 1) + z2 * N(2, 1) + z3 * N(3, 1);
        const double J22 =
          z0 * N(0, 2) + z1 * N(1, 2) + z2 * N(2, 2) + z3 * N(3, 2);

        const double det = J00 * (J11 * J22 - J12 * J21) -
                           J01 * (J10 * J22 - J12 * J20) +
                           J02 * (J10 * J21 - J11 * J20);
        w.J_det[t] = det;

        const double chi = coef_chi(det, w.eps);
        const double chip = coef_chip(det, w.eps);
        const double chi13 = std::cbrt(chi);
        const double chi23 = chi13 * chi13;
        const double traceJtJ = J00 * J00 + J10 * J10 + J20 * J20 + J01 * J01 +
                                J11 * J11 + J21 * J21 + J02 * J02 + J12 * J12 +
                                J22 * J22;
        const double f_eps = traceJtJ / chi23;
        const double g_eps = (det * det + 1.) / chi;
        const double Ec = f_eps + w.lambda * g_eps;

        w.element_energy[t] = Ec;

        const double coeff = 2. / 3. * f_eps * chip - 2. * w.lambda * det +
                             w.lambda * g_eps * chip;
        const double scaleA = 2. / chi23;
        const double scaleB = coeff / chi;

        const double b00 = J11 * J22 - J21 * J12;
        const double b10 = J21 * J02 - J01 * J22;
        const double b20 = J01 * J12 - J11 * J02;
        const double d00 = scaleA * J00 - scaleB * b00;
        const double d10 = scaleA * J10 - scaleB * b10;
        const double d20 = scaleA * J20 - scaleB * b20;

        const double b01 = J12 * J20 - J22 * J10;
        const double b11 = J22 * J00 - J02 * J20;
        const double b21 = J02 * J10 - J12 * J00;
        const double d01 = scaleA * J01 - scaleB * b01;
        const double d11 = scaleA * J11 - scaleB * b11;
        const double d21 = scaleA * J21 - scaleB * b21;

        const double b02 = J10 * J21 - J20 * J11;
        const double b12 = J20 * J01 - J00 * J21;
        const double b22 = J00 * J11 - J10 * J01;
        const double d02 = scaleA * J02 - scaleB * b02;
        const double d12 = scaleA * J12 - scaleB * b12;
        const double d22 = scaleA * J22 - scaleB * b22;

        for(size_t k = 0; k < 4; ++k) {
          uint32_t v = tet[k];
          if(w.locked[v]) continue;
          const double n0 = N(k, 0), n1 = N(k, 1), n2 = N(k, 2);
          gradLocal[3 * v + 0] += d00 * n0 + d10 * n1 + d20 * n2;
          gradLocal[3 * v + 1] += d01 * n0 + d11 * n1 + d21 * n2;
          gradLocal[3 * v + 2] += d02 * n0 + d12 * n1 + d22 * n2;
        }
      }

#if defined(_OPENMP)
#pragma omp barrier
#endif
      const size_t gBegin =
        gradLength * (size_t)thread_num / (size_t)actual_threads;
      const size_t gEnd =
        gradLength * (size_t)(thread_num + 1) / (size_t)actual_threads;
      for(size_t i = gBegin; i < gEnd; ++i) {
        double g = 0.;
        for(int j = 0; j < actual_threads; ++j)
          g += GL[(size_t)j * gradLength + i];
        grad[i] = g;
      }
    }

    energy = 0.;
    w.J_det_min = DBL_MAX;
    for(size_t t = 0; t < nElements; ++t) {
      if(w.J_det[t] < w.J_det_min) w.J_det_min = w.J_det[t];
      energy += w.element_energy[t];
    }

    if(std::isnan(energy)) energy = std::numeric_limits<double>::max();
    w.energy = energy;
    return w.energy;
  }

  struct AlglibLBFGSData {
    UntanglerData *data = nullptr;
    std::vector<double> x;
    std::vector<double> grad;
  };

  static void lbfgs_callback(const alglib::real_1d_array &x, double &f,
                             alglib::real_1d_array &grad, void *ptr)
  {
    AlglibLBFGSData *callbackData = static_cast<AlglibLBFGSData *>(ptr);
    UntanglerData &w = *callbackData->data;
    double t1 = TimeOfDay();
    callbackData->x.resize(x.length());
    callbackData->grad.resize(x.length());
    for(size_t i = 0; i < x.length(); ++i) callbackData->x[i] = x[i];
    f =
      (w.dim == 3) ?
        compute_energy_and_gradient3D_scalarized(w, callbackData->x,
                                                 callbackData->grad) :
        compute_energy_and_gradient_2D(w, callbackData->x, callbackData->grad);
    for(size_t i = 0; i < x.length(); ++i) grad[i] = callbackData->grad[i];
    w.profile_callback += TimeOfDay() - t1;
    w.profile_callback_calls++;
  }

  static void checkIfP2(UntanglerData &data, std::vector<size_t> &permut)
  {
    if(perTriangleP2 < 10) return;
    // if P2 triangles are considered, I send to
    // the optimizer the three "bezier corner" triangles
    if(data.triangles.size() % perTriangleP2 != 0) return;
    // Three successive triangles should always be numbered as
    // (a,d,f)(b,e,d)(c,f,e) which correspond to bezier triangles
    for(size_t i = 0; i < data.triangles.size(); i += perTriangleP2) {
      auto t1 = data.triangles[i + 0];
      auto t2 = data.triangles[i + 1];
      auto t3 = data.triangles[i + 2];
      if(t1[1] != t2[2]) return;
      if(t2[1] != t3[2]) return;
      if(t3[1] != t1[2]) return;
    }
    auto xxx = data.triangles;
    data.triangles.clear();
    for(size_t i = 0; i < xxx.size(); i += perTriangleP2) {
      for(size_t j = 0; j < 4; j++) {
        permut.push_back(i + j);
        data.triangles.push_back(xxx[i + j]);
      }
    }
    for(size_t i = 0; i < xxx.size(); i += perTriangleP2) {
      for(size_t j = 4; j < perTriangleP2; j++) {
        permut.push_back(i + j);
        data.triangles.push_back(xxx[i + j]);
      }
    }

    data.isP2 = true;
    //    for (auto i : permut)printf("%zu ",i);
    printf(" --- > FOUND A P2 MESH\n");
  }

  static bool prepareData2D(
    const std::vector<std::array<double, 2>> &points,
    const std::vector<bool> &locked,
    const std::vector<std::array<uint32_t, 3>> &tris,
    const std::vector<std::array<std::array<double, 2>, 3>> &triIdealShapes,
    UntanglerData &data)
  {
    if(triIdealShapes.size() != 0 &&
       triIdealShapes.size() != (size_t)tris.size()) {
      Msg::Error(
        "Winslow untangler 2D: incoherent sizes in triangles / triIdealShapes");
      return false;
    }
    data.dim = 2;
    data.triangles = tris;
    // ----------------------------------------------------
    // Quick FIX -- verify if the structure of P2 triangles
    // given here correspond to a P2 mesh
    // If it is true, add additional triangles that allow
    // to verify the positivity of P2 triangles ...
    std::vector<size_t> permut;
    checkIfP2(data, permut);
    // ----------------------------------------------------
    data.locked = locked;
    data.J_mat_2D.resize(data.triangles.size());
    data.J_det.resize(data.triangles.size(), 0.);
    data.tri_normals.resize(data.triangles.size());
    double avg_tri_area =
      area(points, data.triangles) / double(data.triangles.size());
    if(avg_tri_area <= 0) {
      Msg::Warning(
        "Winslow untangler 2D: average triangle area is negative: %.3e",
        avg_tri_area);
    }

    // Build equilateral triangle centered in origin
    // with unit area
    vec2 equi[3] = {{1., 0.},
                    {cos(2. * M_PI / 3.), sin(2 * M_PI / 3.)},
                    {cos(4. * M_PI / 3.), sin(4 * M_PI / 3.)}};
    const vec3 N = {0, 0, -1};
    for(size_t tt = 0; tt < data.triangles.size(); ++tt) {
      size_t t = permut.empty() ? tt : permut[tt];
      vec2 shape[3] = {equi[0], equi[1], equi[2]};
      if(triIdealShapes.size() > 0.) {
        shape[0] = triIdealShapes[t][0];
        shape[1] = triIdealShapes[t][1];
        shape[2] = triIdealShapes[t][2];
      }

      double area = tri_area(shape[0], shape[1], shape[2]);
      if(std::isnan(area)) {
        Msg::Warning("Winslow untangler 2D: area of ideal shape for tri %li: "
                     "%f, cancel smoothing",
                     t, area);
        return false;
      }
      else if(area <= 0.) {
        Msg::Warning(
          "Winslow untangler 2D: area of ideal shape for tri %li: %f", t, area);
      }

      // Compute normals
      for(size_t le = 0; le < 3; ++le) {
        vec2 td = (shape[(le + 2) % 3] - shape[(le + 1) % 3]);
        vec3 n = cross(std::array<double, 3>{td[0], td[1], 0.}, N) *
                 (1. / (2. * area));
        data.tri_normals[tt](le, 0) = n[0];
        data.tri_normals[tt](le, 1) = n[1];
      }
    }

    // Update jacobian matrices with current triangle coordinates
    std::vector<double> x0(2 * points.size());
    for(size_t i = 0; i < points.size(); ++i) {
      x0[2 * i + 0] = points[i][0];
      x0[2 * i + 1] = points[i][1];
    }
    data.J_det_min = DBL_MAX;
    data.nb_invalid = 0;
    data.energy = 0.;
    for(size_t t = 0; t < data.triangles.size(); t++) {
      const double det = update_jacobian_matrix(t, data, x0);
      if(det < data.J_det_min) data.J_det_min = det;
      if(det <= 0.) data.nb_invalid += 1;
    }
    data.eps =
      std::sqrt(1.e-12 + 0.04 * std::pow(std::min(data.J_det_min, 0.), 2));

    // Compute initial energy
    size_t max_t = data.isP2 ? 4 * (data.triangles.size() / perTriangleP2) :
                               data.triangles.size();
    for(size_t t = 0; t < max_t; t++) {
      //      printf("%zu %g\n",t,data.J_det[t]);
      const double det = data.J_det[t];
      const double chi = coef_chi(det, data.eps);
      const double f_eps =
        (data.J_mat_2D[t].transpose() * data.J_mat_2D[t]).trace() / chi;
      const double g_eps = (det * det + 1.) / chi;
      const double Ec = f_eps + data.lambda * g_eps;
      data.energy += Ec;
    }
    // P2 extension

    size_t dT = (perTriangleP2 - 4) / 3;
    double signs[5] = {1, 1, -1, -1, -1};
    for(size_t t = max_t; t < data.triangles.size(); t += dT) {
      double det = 0;
      for(size_t l = 0; l < dT; l++) det += signs[l] * data.J_det[t + l];

      const double chi = coef_chi(det, data.eps);
      const double g_eps = (det * det + 1.) / chi;
      const double Ec = data.lambda * g_eps;
      data.energy += Ec;
    }
    //    printf("FOUND A P2 MESH -- ENERGY %g\n",data.energy);
    return true;
  }

  static bool prepareData3D(
    const std::vector<std::array<double, 3>> &points,
    const std::vector<bool> &locked,
    const std::vector<std::array<uint32_t, 4>> &tets,
    const std::vector<std::array<std::array<double, 3>, 4>> &tetIdealShapes,
    UntanglerData &data)
  {
    if(tetIdealShapes.size() != 0 &&
       tetIdealShapes.size() != (size_t)tets.size()) {
      Msg::Error(
        "Winslow untangler 3D: incoherent sizes in tets / tetIdealShapes");
      return false;
    }
    data.dim = 3;
    data.tetrahedra = tets;
    data.locked = locked;
    data.J_mat_3D.resize(tets.size());
    data.J_det.resize(tets.size(), 0.);
    data.tet_normals.resize(tets.size());
    double avg_tet_vol = volume(points, tets) / double(tets.size());
    if(avg_tet_vol <= 0) {
      Msg::Warning("Winslow untangler 3D: average tet area is negative: %.3e",
                   avg_tet_vol);
    }

    // Build regular tet centered in origin
    // with unit volume
    vec3 equi[4] = {{.5, 0, -1. / (2. * std::sqrt(2.))},
                    {-.5, 0, -1. / (2. * std::sqrt(2.))},
                    {0, .5, 1. / (2. * std::sqrt(2.))},
                    {0, -.5, 1. / (2. * std::sqrt(2.))}};
    double reg_vol = tet_volume(equi[0], equi[1], equi[2], equi[3]);

    for(size_t lv = 0; lv < 4; ++lv) {
      equi[lv] = equi[lv] * (1. / std::pow(reg_vol, 1. / 3.));
    }

    constexpr int facet_vertex[4][3] = {
      {1, 3, 2}, {0, 2, 3}, {3, 1, 0}, {0, 1, 2}};

    //    double avg_ideal_vol = 1.;
    //    if(tetIdealShapes.size() > 0.) {
    //      for(size_t t = 0; t < tetIdealShapes.size(); ++t) {
    //        avg_ideal_vol += tet_volume(tetIdealShapes[t][0],
    //        tetIdealShapes[t][1],
    //                                    tetIdealShapes[t][2],
    //                                    tetIdealShapes[t][3]);
    //      }
    //      avg_ideal_vol /= double(tetIdealShapes.size());
    //    }

    // Build ideal tet normals
    for(size_t t = 0; t < tets.size(); ++t) {
      vec3 shape[4] = {equi[0], equi[1], equi[2], equi[3]};
      if(tetIdealShapes.size() > 0.) {
        shape[0] = tetIdealShapes[t][0];
        shape[1] = tetIdealShapes[t][1];
        shape[2] = tetIdealShapes[t][2];
        shape[3] = tetIdealShapes[t][3];
      }

      //      for(size_t lv = 0; lv < 4; ++lv) {
      //        shape[lv] = shape[lv] * (1. / std::pow(avg_ideal_vol, 1. / 3.) *
      //                                 std::pow(avg_tet_vol, 1. / 3.));
      //      }

      double vol = tet_volume(shape[0], shape[1], shape[2], shape[3]);
      if(std::isnan(vol)) {
        Msg::Warning("Winslow untangler 3D: volume of ideal shape for tet %li: "
                     "%f, cancel smoothing",
                     t, vol);
        return false;
      }
      else if(vol < 0.) {
        Msg::Warning(
          "Winslow untangler 3D: volume of ideal shape for tet %li: %f", t,
          vol);
      }

      // Compute normals
      for(size_t lf = 0; lf < 4; ++lf) {
        vec3 e0 = shape[facet_vertex[lf][1]] - shape[facet_vertex[lf][0]];
        vec3 e1 = shape[facet_vertex[lf][2]] - shape[facet_vertex[lf][0]];
        vec3 n = 0.5 * cross(e1, e0) * (1. / (3. * vol));

        data.tet_normals[t](lf, 0) = n[0];
        data.tet_normals[t](lf, 1) = n[1];
        data.tet_normals[t](lf, 2) = n[2];
      }
    }

    // Update jacobian matrices with current triangle coordinates
    std::vector<double> x0(3 * points.size());
    for(size_t i = 0; i < points.size(); ++i) {
      x0[3 * i + 0] = points[i][0];
      x0[3 * i + 1] = points[i][1];
      x0[3 * i + 2] = points[i][2];
    }
    data.J_det_min = DBL_MAX;
    data.nb_invalid = 0;
    data.energy = 0.;
    for(size_t t = 0; t < data.tetrahedra.size(); t++) {
      const double det = update_jacobian_matrix(t, data, x0);
      //      printf("det = %12.5E\n",det);
      if(det < data.J_det_min) data.J_det_min = det;
      if(det <= 0.) data.nb_invalid += 1;
    }
    data.eps =
      std::sqrt(1.e-12 + 0.04 * std::pow(std::min(data.J_det_min, 0.), 2));

    // Compute initial energy
    for(size_t t = 0; t < data.tetrahedra.size(); t++) {
      const double det = data.J_det[t];
      const double chi = coef_chi(det, data.eps);
      const double f_eps =
        (data.J_mat_3D[t].transpose() * data.J_mat_3D[t]).trace() /
        std::pow(chi, 2. / 3.);
      const double g_eps = (det * det + 1.) / chi;
      const double Ec = f_eps + data.lambda * g_eps;
      data.energy += Ec;
    }

    return true;
  }

  static void optional_lbfgs_callback(const alglib::real_1d_array &x,
                                      double func, void *ptr)
  {
    (void)x;
    (void)ptr;
    printf("F = %12.5E\n", func);
  }

  // same function for 2D and 3D to avoid redundant code
  // only the structs of the appropriate dimension are used
  static bool untangle_simplex_elements(
    size_t dim, std::vector<std::array<double, 2>> &points2D,
    std::vector<std::array<double, 3>> &points3D,
    const std::vector<bool> &locked,
    const std::vector<std::array<uint32_t, 3>> &triangles,
    const std::vector<std::array<std::array<double, 2>, 3>> &triIdealShapes,
    const std::vector<std::array<uint32_t, 4>> &tetrahedra,
    const std::vector<std::array<std::array<double, 3>, 4>> &tetIdealShapes,
    double lambda, int iterMaxInner, int iterMaxOuter, int iterFailMax,
    double timeMax,
    const std::function<
      void(const std::vector<std::array<double, 2>> &points,
           const std::vector<std::array<uint32_t, 3>> &triangles,
           std::vector<double> &s, // size and grad sizes at nodes
           std::vector<std::array<double, 3>> &grads)> &sizeField,
    const std::function<
      void(const std::vector<std::array<double, 2>> &points,
           const std::vector<std::array<uint32_t, 3>> &triangles,
           std::vector<std::array<std::array<double, 2>, 3>> &triIdealShapes)>
      &updateIdealTriangularShapes)
  {
    if(dim != 2 && dim != 3) return false;
    if(dim == 2 && (points2D.size() == 0 || triangles.size() == 0)) {
      Msg::Warning("Wrong input sizes (%li vertices, %li triangles) in 2D "
                   "Winslow untangler",
                   points2D.size(), triangles.size());
      return false;
    }
    if(dim == 3 && (points3D.size() == 0 || tetrahedra.size() == 0)) {
      Msg::Warning("Wrong input sizes (%li vertices, %li tetrahedra) in 3D "
                   "Windlow untangler",
                   points2D.size(), triangles.size());
      return false;
    }
    (void)sizeField;

    // Save initial positions, in case they need to be restored
    bool restore = false;
    std::vector<std::array<double, 2>> backup2D = points2D;
    std::vector<std::array<double, 3>> backup3D = points3D;

    UntanglerData data;
    data.lambda = lambda;
    data.profile_total = TimeOfDay();

    /* Transfer/preprocess data */
    size_t NV = (dim == 2) ? points2D.size() : points3D.size();
    if(dim == 2) {
      auto triIdealShapesS = triIdealShapes;
      if(updateIdealTriangularShapes)
        updateIdealTriangularShapes(points2D, triangles, triIdealShapesS);

      bool okp =
        prepareData2D(points2D, locked, triangles, triIdealShapesS, data);
      if(!okp) return false;
    }
    else if(dim == 3) {
      auto tetIdealShapesS = tetIdealShapes;
      bool okp =
        prepareData3D(points3D, locked, tetrahedra, tetIdealShapesS, data);
      if(!okp) return false;
    }
    double *points =
      (dim == 2) ? points2D.front().data() : points3D.front().data();

    /* Optimization loop */
    bool converged = false;
    int nFail = 0;
    double t0 = Cpu();
    double E_prev = data.energy;
    // Copy positions in solver array
    std::vector<double> x(dim * NV);
    for(size_t i = 0; i < x.size(); ++i) x[i] = points[i];

    for(int iter = 0; iter < iterMaxOuter; iter++) {
      // Update regularized epsilon parameter
      data.eps =
        std::sqrt(1.e-12 + 0.04 * std::pow(std::min(data.J_det_min, 0.), 2));

      //      printf("eps %g %d %d\n",data.eps,  iterMaxOuter, iterMaxInner);

      double epsg = 1.e-4;
      double epsf = 1.e-12;
      double epsx = 1.e-12;
      // LBFGS solver: 0 = ALGLIB, 1 = GmshLBFGS skeleton
      static int lbfgsSolver = 1;
      int lbfgsIter = 0;
      try {
        int terminationType = 0;
        if(lbfgsSolver == 0) {
          alglib::real_1d_array xAlg;
          xAlg.setcontent((alglib::ae_int_t)x.size(), x.data());
          AlglibLBFGSData callbackData;
          callbackData.data = &data;
          // Setup of the LBFGS solver
          alglib::ae_int_t N = dim * NV;
          alglib::ae_int_t corr =
            N < 15 ? N : 15; // Num of corrections in the scheme in [3,7]
          alglib::minlbfgsstate state;
          alglib::minlbfgsreport rep;
          minlbfgscreate(N, corr, xAlg, state);
          // LBFGS stopping criteria
          minlbfgssetcond(state, epsg, epsf, epsx,
                          (alglib::ae_int_t)iterMaxInner);
          // Run LBFGS
          double tLbfgs = TimeOfDay();
          minlbfgsoptimize(state, lbfgs_callback, optional_lbfgs_callback,
                           &callbackData);
          data.profile_lbfgs += TimeOfDay() - tLbfgs;

          // Extract coordinates
          minlbfgsresults(state, xAlg, rep);
          for(size_t i = 0; i < x.size(); ++i) x[i] = xAlg[i];
          lbfgsIter = rep.iterationscount;
          terminationType = rep.terminationtype;
        }
        else {
          GmshLBFGS::Options options;
          options.maxIterations = iterMaxInner;
          options.memory = (int)std::min<size_t>(15, x.size());
          options.gradientTolerance = epsg;
          options.functionTolerance = epsf;
          options.stepTolerance = epsx;
          options.maxLineSearchSteps = 80;
          options.verbose = 0;
          options.numThreads = 8;

          auto fg = [&data](const std::vector<double> &xin,
                            std::vector<double> &gout) {
            double t1 = TimeOfDay();
            double f =
              (data.dim == 3) ?
                compute_energy_and_gradient3D_scalarized(data, xin, gout) :
                compute_energy_and_gradient_2D(data, xin, gout);
            data.profile_callback += TimeOfDay() - t1;
            data.profile_callback_calls++;
            return f;
          };

          double tLbfgs = TimeOfDay();
          GmshLBFGS::Result result = GmshLBFGS::minimize(x, fg, options);
          data.profile_lbfgs += TimeOfDay() - tLbfgs;

          lbfgsIter = result.iterations;
          terminationType = result.converged ? 4 : result.terminationType;
          Msg::Info("GmshLBFGS profiling: total %g s, function %g s, "
                    "direction %g s, line-search %g s, update %g s, "
                    "unaccounted %g s, evaluations %d",
                    result.timeTotal, result.timeFunction, result.timeDirection,
                    result.timeLineSearch, result.timeUpdate,
                    result.timeTotal - result.timeFunction -
                      result.timeDirection - result.timeLineSearch -
                      result.timeUpdate,
                    result.functionEvaluations);
        }

        for(size_t v = 0; v < NV; ++v) {
          for(size_t d = 0; d < dim; ++d) {
            points[dim * v + d] = x[dim * v + d];
          }
        }

        if(updateIdealTriangularShapes) {
          auto triIdealShapesS = triIdealShapes;
          updateIdealTriangularShapes(points2D, triangles, triIdealShapesS);
          prepareData2D(points2D, locked, triangles, triIdealShapesS, data);
        }

        if(terminationType != 4 && terminationType != 5) { nFail += 1; }
        Msg::Debug(" detmin = %22.15E eps= %22.15E %i iter term %i",
                   data.J_det_min, data.eps, lbfgsIter, terminationType);
      } catch(alglib::ap_error e) {
        Msg::Warning("Winslow untangler, iter %i: Alglib exception thrown in "
                     "LBFGS step, error: %s",
                     iter, e.msg.c_str());
        restore = true;
        converged = false;
        nFail += 1;
        break;
      } catch(...) {
        Msg::Warning(
          "Winslow untangler, iter %i: Alglib exception thrown in LBFGS step",
          iter);
        restore = true;
        converged = false;
        nFail += 1;
        break;
      }

      // Check outer loop stopping criteria
      double dErel =
        data.energy > 0 ? std::abs(data.energy - E_prev) / data.energy : 0.;

      Msg::Debug("- iter %i: eps = %f, E: %.3e, dE/E=%.3e, min(detJ)=%f, "
                 "#(det<0)=%i (LBFGS: %i iters)",
                 iter, data.eps, data.energy, dErel, data.J_det_min,
                 data.nb_invalid, lbfgsIter);

      if(data.J_det_min > 0 && dErel < 1e-5) {
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
      E_prev = data.energy;
    }

    if(restore) {
      points2D = backup2D;
      points3D = backup3D;
    }

#if 0 // TEST OF GRADIENT !!
    {
      std::vector<double> GRAD(dim * NV), GRAD2(dim * NV);
      double EN = compute_energy_and_gradient_2D(data, x, GRAD);
      for(size_t i = 0; i < dim * NV; i++) {
        x[i] += 1.e-8;
        double EN2 = compute_energy_and_gradient_2D(data, x, GRAD2);
        x[i] -= 1.e-8;
        printf("%zu GRAD %12.5E DIFF %12.5E\n", i, GRAD[i],
               1.e8 * (EN2 - EN));
      }
    }
#endif

    data.profile_total = TimeOfDay() - data.profile_total;
    if(dim == 3) {
      Msg::Info("Winslow 3D profiling: total %g s, LBFGS %g s, "
                "energy/gradient %g s in %zu calls, other %g s, "
                "threads %d..%d",
                data.profile_total, data.profile_lbfgs, data.profile_callback,
                data.profile_callback_calls,
                data.profile_total - data.profile_callback,
                data.profile_threads_min, data.profile_threads_max);
    }

    return converged;
  }
} // namespace WinslowUntangler

using namespace WinslowUntangler;

#endif

bool untangle_triangles_2D(
  std::vector<std::array<double, 2>> &points, const std::vector<bool> &locked,
  const std::vector<std::array<uint32_t, 3>> &triangles,
  const std::vector<std::array<std::array<double, 2>, 3>> &triIdealShapes,
  double lambda, int iterMaxInner, int iterMaxOuter, int iterFailMax,
  double timeMax,
  const std::function<
    void(const std::vector<std::array<double, 2>> &points,
         const std::vector<std::array<uint32_t, 3>> &triangles,
         std::vector<double> &s, // size and grad sizes at nodes
         std::vector<std::array<double, 3>> &grads)> &sizeField,
  const std::function<
    void(const std::vector<std::array<double, 2>> &points,
         const std::vector<std::array<uint32_t, 3>> &triangles,
         std::vector<std::array<std::array<double, 2>, 3>> &triIdealShapes)>
    &updateIdealTriangularShapes)
{
#if defined(HAVE_EIGEN) && defined(HAVE_ALGLIB) &&                             \
  defined(HAVE_QUADMESHINGTOOLS)
  std::vector<std::array<double, 3>> points3D;
  const std::vector<std::array<uint32_t, 4>> tetrahedra;
  const std::vector<std::array<std::array<double, 3>, 4>> tetIdealShapes;
  return untangle_simplex_elements(
    2, points, points3D, locked, triangles, triIdealShapes, tetrahedra,
    tetIdealShapes, lambda, iterMaxInner, iterMaxOuter, iterFailMax, timeMax,
    sizeField, updateIdealTriangularShapes);
#else
  Msg::Error(
    "Winslow untangler requires modules Eigen, Alglib and QuadMeshingTools");
  return false;
#endif
}

bool untangle_tetrahedra(
  std::vector<std::array<double, 3>> &points, const std::vector<bool> &locked,
  const std::vector<std::array<uint32_t, 4>> &tets,
  const std::vector<std::array<std::array<double, 3>, 4>> &tetIdealShapes,
  double lambda, int iterMaxInner, int iterMaxOuter, int iterFailMax,
  double timeMax)
{
#if defined(HAVE_EIGEN) && defined(HAVE_ALGLIB) &&                             \
  defined(HAVE_QUADMESHINGTOOLS)
  std::vector<std::array<double, 2>> points2D;
  const std::vector<std::array<uint32_t, 3>> tris;
  const std::vector<std::array<std::array<double, 2>, 3>> triIdealShapes;
  return untangle_simplex_elements(
    3, points2D, points, locked, tris, triIdealShapes, tets, tetIdealShapes,
    lambda, iterMaxInner, iterMaxOuter, iterFailMax, timeMax, nullptr, nullptr);
#else
  Msg::Error(
    "Winslow untangler requires modules Eigen, Alglib and QuadMeshingTools");
  return false;
#endif
}
