// Gmsh Boundary Layer Plugin - Copyright (C) 2026 C. Geuzaine and J.-F. Remacle
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

#include "winslowUntanglerGMSH.h"

#include "GmshMessage.h"
#include "OS.h"
#include "gmshLBFGS.h"

#include <algorithm>
#include <cfloat>
#include <cmath>
#include <cstdlib>
#include <limits>

#if defined(_OPENMP)
#include <omp.h>
#endif

namespace {
  using vec2 = std::array<double, 2>;
  using vec3 = std::array<double, 3>;

  static double triArea(const vec2 &a, const vec2 &b, const vec2 &c)
  {
    return .5 * ((b[1] - a[1]) * (b[0] + a[0]) + (c[1] - b[1]) * (c[0] + b[0]) +
                 (a[1] - c[1]) * (a[0] + c[0]));
  }

  static vec3 cross(const vec3 &a, const vec3 &b)
  {
    return {a[1] * b[2] - a[2] * b[1], a[2] * b[0] - a[0] * b[2],
            a[0] * b[1] - a[1] * b[0]};
  }

  static double dot(const vec3 &a, const vec3 &b)
  {
    return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
  }

  static vec3 sub(const vec3 &a, const vec3 &b)
  {
    return {a[0] - b[0], a[1] - b[1], a[2] - b[2]};
  }

  static vec3 scale(const vec3 &a, double s)
  {
    return {s * a[0], s * a[1], s * a[2]};
  }

  static double tetVolume(const vec3 &a, const vec3 &b, const vec3 &c,
                          const vec3 &d)
  {
    return dot(sub(a, d), cross(sub(b, d), sub(c, d))) / 6.;
  }

  static double coefChi(double D, double eps)
  {
    return 0.5 * (D + std::sqrt(eps * eps + D * D));
  }

  static double coefChip(double D, double eps)
  {
    return 0.5 + D / (2. * std::sqrt(eps * eps + D * D));
  }

  struct UntanglerDataGMSH {
    int dim = 0;
    double lambda = 1.;
    double eps = 0.;
    double energy = 0.;
    double JDetMin = DBL_MAX;
    size_t nbInvalid = 0;
    std::vector<bool> locked;
    std::vector<std::array<uint32_t, 3>> triangles;
    std::vector<std::array<uint32_t, 4>> tetrahedra;
    std::vector<std::array<std::array<double, 2>, 3>> triNormals;
    std::vector<std::array<std::array<double, 3>, 4>> tetNormals;
    std::vector<double> JDet;
    std::vector<double> gradThreadBuffers;
    std::vector<double> elementEnergy;
    double profileTotal = 0.;
    double profileLBFGS = 0.;
    double profileCallback = 0.;
    size_t profileCallbackCalls = 0;
    double profileLBFGSFunction = 0.;
    double profileLBFGSDirection = 0.;
    double profileLBFGSLineSearch = 0.;
    double profileLBFGSUpdate = 0.;
    int profileLBFGSEvaluations = 0;
    int profileThreadsMin = 1000000;
    int profileThreadsMax = 0;
  };

  static int requestedNumThreads()
  {
    const int defaultThreads = 8;
    const char *env = std::getenv("GMSH_WINSLOW_THREADS");
    if(!env || !env[0]) return defaultThreads;
    char *end = nullptr;
    const long n = std::strtol(env, &end, 10);
    if(end == env || n < 1) {
      Msg::Warning("Ignoring invalid GMSH_WINSLOW_THREADS='%s'", env);
      return defaultThreads;
    }
    return (n > 1024) ? 1024 : (int)n;
  }

  static int numElementThreads(size_t nElements)
  {
    int nthreads = requestedNumThreads();
#if defined(_OPENMP)
    if((size_t)nthreads > nElements) nthreads = (int)nElements;
    if(nthreads < 1) nthreads = 1;
    omp_set_dynamic(0);
#else
    nthreads = 1;
#endif
    return nthreads;
  }

  static double area(const std::vector<vec2> &points,
                     const std::vector<std::array<uint32_t, 3>> &triangles)
  {
    double sum = 0.;
    for(const auto &t : triangles)
      sum += triArea(points[t[0]], points[t[1]], points[t[2]]);
    return sum;
  }

  static double volume(const std::vector<vec3> &points,
                       const std::vector<std::array<uint32_t, 4>> &tets)
  {
    double sum = 0.;
    for(const auto &t : tets)
      sum += tetVolume(points[t[0]], points[t[1]], points[t[2]], points[t[3]]);
    return sum;
  }

  static double updateJacobian2D(size_t t, UntanglerDataGMSH &w,
                                 const std::vector<double> &X)
  {
    const auto &tri = w.triangles[t];
    const auto &N = w.triNormals[t];
    const double x0 = X[2 * tri[0] + 0], y0 = X[2 * tri[0] + 1];
    const double x1 = X[2 * tri[1] + 0], y1 = X[2 * tri[1] + 1];
    const double x2 = X[2 * tri[2] + 0], y2 = X[2 * tri[2] + 1];
    const double J00 = x0 * N[0][0] + x1 * N[1][0] + x2 * N[2][0];
    const double J10 = x0 * N[0][1] + x1 * N[1][1] + x2 * N[2][1];
    const double J01 = y0 * N[0][0] + y1 * N[1][0] + y2 * N[2][0];
    const double J11 = y0 * N[0][1] + y1 * N[1][1] + y2 * N[2][1];
    const double det = J00 * J11 - J01 * J10;
    w.JDet[t] = det;
    return det;
  }

  static double updateJacobian3D(size_t t, UntanglerDataGMSH &w,
                                 const std::vector<double> &X)
  {
    const auto &tet = w.tetrahedra[t];
    const auto &N = w.tetNormals[t];
    const double x0 = X[3 * tet[0] + 0], y0 = X[3 * tet[0] + 1],
                 z0 = X[3 * tet[0] + 2];
    const double x1 = X[3 * tet[1] + 0], y1 = X[3 * tet[1] + 1],
                 z1 = X[3 * tet[1] + 2];
    const double x2 = X[3 * tet[2] + 0], y2 = X[3 * tet[2] + 1],
                 z2 = X[3 * tet[2] + 2];
    const double x3 = X[3 * tet[3] + 0], y3 = X[3 * tet[3] + 1],
                 z3 = X[3 * tet[3] + 2];
    const double J00 =
      x0 * N[0][0] + x1 * N[1][0] + x2 * N[2][0] + x3 * N[3][0];
    const double J10 =
      x0 * N[0][1] + x1 * N[1][1] + x2 * N[2][1] + x3 * N[3][1];
    const double J20 =
      x0 * N[0][2] + x1 * N[1][2] + x2 * N[2][2] + x3 * N[3][2];
    const double J01 =
      y0 * N[0][0] + y1 * N[1][0] + y2 * N[2][0] + y3 * N[3][0];
    const double J11 =
      y0 * N[0][1] + y1 * N[1][1] + y2 * N[2][1] + y3 * N[3][1];
    const double J21 =
      y0 * N[0][2] + y1 * N[1][2] + y2 * N[2][2] + y3 * N[3][2];
    const double J02 =
      z0 * N[0][0] + z1 * N[1][0] + z2 * N[2][0] + z3 * N[3][0];
    const double J12 =
      z0 * N[0][1] + z1 * N[1][1] + z2 * N[2][1] + z3 * N[3][1];
    const double J22 =
      z0 * N[0][2] + z1 * N[1][2] + z2 * N[2][2] + z3 * N[3][2];
    const double det = J00 * (J11 * J22 - J12 * J21) -
                       J01 * (J10 * J22 - J12 * J20) +
                       J02 * (J10 * J21 - J11 * J20);
    w.JDet[t] = det;
    return det;
  }

  static bool
  prepareData2D(const std::vector<vec2> &points,
                const std::vector<bool> &locked,
                const std::vector<std::array<uint32_t, 3>> &triangles,
                const std::vector<std::array<vec2, 3>> &triIdealShapes,
                UntanglerDataGMSH &data)
  {
    if(triIdealShapes.size() != 0 &&
       triIdealShapes.size() != triangles.size()) {
      Msg::Error("Winslow untangler GMSH 2D: incoherent sizes in triangles / "
                 "triIdealShapes");
      return false;
    }
    data.dim = 2;
    data.locked = locked;
    data.triangles = triangles;
    data.triNormals.resize(triangles.size());
    data.JDet.assign(triangles.size(), 0.);
    const double avgArea = area(points, triangles) / double(triangles.size());
    if(avgArea <= 0.)
      Msg::Warning("Winslow untangler GMSH 2D: average triangle area is "
                   "negative: %.3e",
                   avgArea);

    vec2 equi[3] = {{1., 0.},
                    {std::cos(2. * M_PI / 3.), std::sin(2. * M_PI / 3.)},
                    {std::cos(4. * M_PI / 3.), std::sin(4. * M_PI / 3.)}};
    for(size_t t = 0; t < triangles.size(); ++t) {
      vec2 shape[3] = {equi[0], equi[1], equi[2]};
      if(!triIdealShapes.empty()) {
        shape[0] = triIdealShapes[t][0];
        shape[1] = triIdealShapes[t][1];
        shape[2] = triIdealShapes[t][2];
      }
      const double a = triArea(shape[0], shape[1], shape[2]);
      if(std::isnan(a)) {
        Msg::Warning("Winslow untangler GMSH 2D: area of ideal shape for tri "
                     "%li: %f, cancel smoothing",
                     t, a);
        return false;
      }
      else if(a <= 0.) {
        Msg::Warning("Winslow untangler GMSH 2D: area of ideal shape for tri "
                     "%li: %f",
                     t, a);
      }
      for(size_t le = 0; le < 3; ++le) {
        const vec2 td = {shape[(le + 2) % 3][0] - shape[(le + 1) % 3][0],
                         shape[(le + 2) % 3][1] - shape[(le + 1) % 3][1]};
        data.triNormals[t][le][0] = -td[1] / (2. * a);
        data.triNormals[t][le][1] = td[0] / (2. * a);
      }
    }
    return true;
  }

  static bool
  prepareData3D(const std::vector<vec3> &points,
                const std::vector<bool> &locked,
                const std::vector<std::array<uint32_t, 4>> &tets,
                const std::vector<std::array<vec3, 4>> &tetIdealShapes,
                UntanglerDataGMSH &data)
  {
    if(tetIdealShapes.size() != 0 && tetIdealShapes.size() != tets.size()) {
      Msg::Error("Winslow untangler GMSH 3D: incoherent sizes in tets / "
                 "tetIdealShapes");
      return false;
    }
    data.dim = 3;
    data.locked = locked;
    data.tetrahedra = tets;
    data.tetNormals.resize(tets.size());
    data.JDet.assign(tets.size(), 0.);
    const double avgVol = volume(points, tets) / double(tets.size());
    if(avgVol <= 0.)
      Msg::Warning("Winslow untangler GMSH 3D: average tet volume is "
                   "negative: %.3e",
                   avgVol);

    vec3 equi[4] = {{.5, 0, -1. / (2. * std::sqrt(2.))},
                    {-.5, 0, -1. / (2. * std::sqrt(2.))},
                    {0, .5, 1. / (2. * std::sqrt(2.))},
                    {0, -.5, 1. / (2. * std::sqrt(2.))}};
    const double regVol = tetVolume(equi[0], equi[1], equi[2], equi[3]);
    const double regScale = 1. / std::pow(regVol, 1. / 3.);
    for(size_t i = 0; i < 4; ++i) equi[i] = scale(equi[i], regScale);

    constexpr int facetVertex[4][3] = {
      {1, 3, 2}, {0, 2, 3}, {3, 1, 0}, {0, 1, 2}};

    for(size_t t = 0; t < tets.size(); ++t) {
      vec3 shape[4] = {equi[0], equi[1], equi[2], equi[3]};
      if(!tetIdealShapes.empty()) {
        shape[0] = tetIdealShapes[t][0];
        shape[1] = tetIdealShapes[t][1];
        shape[2] = tetIdealShapes[t][2];
        shape[3] = tetIdealShapes[t][3];
      }
      const double v = tetVolume(shape[0], shape[1], shape[2], shape[3]);
      if(std::isnan(v)) {
        Msg::Warning("Winslow untangler GMSH 3D: volume of ideal shape for tet "
                     "%li: %f, cancel smoothing",
                     t, v);
        return false;
      }
      else if(v < 0.) {
        Msg::Warning("Winslow untangler GMSH 3D: volume of ideal shape for tet "
                     "%li: %f",
                     t, v);
      }
      for(size_t lf = 0; lf < 4; ++lf) {
        const vec3 e0 =
          sub(shape[facetVertex[lf][1]], shape[facetVertex[lf][0]]);
        const vec3 e1 =
          sub(shape[facetVertex[lf][2]], shape[facetVertex[lf][0]]);
        const vec3 n = scale(cross(e1, e0), 0.5 / (3. * v));
        data.tetNormals[t][lf] = n;
      }
    }
    return true;
  }

  static double computeEnergyAndGradient2D(UntanglerDataGMSH &w,
                                           const std::vector<double> &X,
                                           std::vector<double> &grad)
  {
    w.JDetMin = DBL_MAX;
    w.nbInvalid = 0;
    double energy = 0.;

    const size_t nElements = w.triangles.size();
    const size_t gradLength = grad.size();
    const int nthreads = numElementThreads(nElements);
    if(w.gradThreadBuffers.size() != (size_t)nthreads * gradLength)
      w.gradThreadBuffers.assign((size_t)nthreads * gradLength, 0.);
    if(w.elementEnergy.size() != nElements) w.elementEnergy.resize(nElements);
    std::vector<double> &GL = w.gradThreadBuffers;

#if defined(_OPENMP)
#pragma omp parallel num_threads(nthreads)
#endif
    {
      int threadNum = 0;
      int actualThreads = 1;
#if defined(_OPENMP)
      threadNum = omp_get_thread_num();
      actualThreads = omp_get_num_threads();
#endif
      double *gradLocal = &GL[(size_t)threadNum * gradLength];
      for(size_t i = 0; i < gradLength; ++i) gradLocal[i] = 0.;

      const size_t tBegin =
        nElements * (size_t)threadNum / (size_t)actualThreads;
      const size_t tEnd =
        nElements * (size_t)(threadNum + 1) / (size_t)actualThreads;
      for(size_t t = tBegin; t < tEnd; ++t) {
        const auto &tri = w.triangles[t];
        const auto &N = w.triNormals[t];
        const double x0 = X[2 * tri[0] + 0], y0 = X[2 * tri[0] + 1];
        const double x1 = X[2 * tri[1] + 0], y1 = X[2 * tri[1] + 1];
        const double x2 = X[2 * tri[2] + 0], y2 = X[2 * tri[2] + 1];
        const double J00 = x0 * N[0][0] + x1 * N[1][0] + x2 * N[2][0];
        const double J10 = x0 * N[0][1] + x1 * N[1][1] + x2 * N[2][1];
        const double J01 = y0 * N[0][0] + y1 * N[1][0] + y2 * N[2][0];
        const double J11 = y0 * N[0][1] + y1 * N[1][1] + y2 * N[2][1];
        const double det = J00 * J11 - J01 * J10;
        w.JDet[t] = det;

        const double chi = coefChi(det, w.eps);
        const double chip = coefChip(det, w.eps);
        const double traceJtJ = J00 * J00 + J10 * J10 + J01 * J01 + J11 * J11;
        const double fEps = traceJtJ / chi;
        const double gEps = (det * det + 1.) / chi;
        w.elementEnergy[t] = fEps + w.lambda * gEps;

        const double coeff =
          fEps * chip - 2. * w.lambda * det + w.lambda * gEps * chip;
        const double scaleA = 2. / chi;
        const double scaleB = coeff / chi;
        const double d00 = scaleA * J00 - scaleB * J11;
        const double d10 = scaleA * J10 + scaleB * J01;
        const double d01 = scaleA * J01 + scaleB * J10;
        const double d11 = scaleA * J11 - scaleB * J00;
        for(size_t k = 0; k < 3; ++k) {
          const uint32_t v = tri[k];
          if(w.locked[v]) continue;
          const double n0 = N[k][0], n1 = N[k][1];
          gradLocal[2 * v + 0] += d00 * n0 + d10 * n1;
          gradLocal[2 * v + 1] += d01 * n0 + d11 * n1;
        }
      }

#if defined(_OPENMP)
#pragma omp barrier
#endif
      const size_t gBegin =
        gradLength * (size_t)threadNum / (size_t)actualThreads;
      const size_t gEnd =
        gradLength * (size_t)(threadNum + 1) / (size_t)actualThreads;
      for(size_t i = gBegin; i < gEnd; ++i) {
        double g = 0.;
        for(int j = 0; j < actualThreads; ++j)
          g += GL[(size_t)j * gradLength + i];
        grad[i] = g;
      }
    }
    w.profileThreadsMin = std::min(w.profileThreadsMin, nthreads);
    w.profileThreadsMax = std::max(w.profileThreadsMax, nthreads);

    for(size_t t = 0; t < nElements; ++t) {
      if(w.JDet[t] < w.JDetMin) w.JDetMin = w.JDet[t];
      if(w.JDet[t] <= 0.) w.nbInvalid++;
      energy += w.elementEnergy[t];
    }

    if(std::isnan(energy)) energy = std::numeric_limits<double>::max();
    w.energy = energy;
    return w.energy;
  }

  static double computeEnergyAndGradient3D(UntanglerDataGMSH &w,
                                           const std::vector<double> &X,
                                           std::vector<double> &grad)
  {
    w.JDetMin = DBL_MAX;
    w.nbInvalid = 0;
    double energy = 0.;

    const size_t nElements = w.tetrahedra.size();
    const size_t gradLength = grad.size();
    const int nthreads = numElementThreads(nElements);
    if(w.gradThreadBuffers.size() != (size_t)nthreads * gradLength)
      w.gradThreadBuffers.assign((size_t)nthreads * gradLength, 0.);
    if(w.elementEnergy.size() != nElements) w.elementEnergy.resize(nElements);
    std::vector<double> &GL = w.gradThreadBuffers;

#if defined(_OPENMP)
#pragma omp parallel num_threads(nthreads)
#endif
    {
      int threadNum = 0;
      int actualThreads = 1;
#if defined(_OPENMP)
      threadNum = omp_get_thread_num();
      actualThreads = omp_get_num_threads();
#endif
      double *gradLocal = &GL[(size_t)threadNum * gradLength];
      for(size_t i = 0; i < gradLength; ++i) gradLocal[i] = 0.;

      const size_t tBegin =
        nElements * (size_t)threadNum / (size_t)actualThreads;
      const size_t tEnd =
        nElements * (size_t)(threadNum + 1) / (size_t)actualThreads;
      for(size_t t = tBegin; t < tEnd; ++t) {
        const auto &tet = w.tetrahedra[t];
        const auto &N = w.tetNormals[t];
        const double x0 = X[3 * tet[0] + 0], y0 = X[3 * tet[0] + 1],
                     z0 = X[3 * tet[0] + 2];
        const double x1 = X[3 * tet[1] + 0], y1 = X[3 * tet[1] + 1],
                     z1 = X[3 * tet[1] + 2];
        const double x2 = X[3 * tet[2] + 0], y2 = X[3 * tet[2] + 1],
                     z2 = X[3 * tet[2] + 2];
        const double x3 = X[3 * tet[3] + 0], y3 = X[3 * tet[3] + 1],
                     z3 = X[3 * tet[3] + 2];
        const double J00 =
          x0 * N[0][0] + x1 * N[1][0] + x2 * N[2][0] + x3 * N[3][0];
        const double J10 =
          x0 * N[0][1] + x1 * N[1][1] + x2 * N[2][1] + x3 * N[3][1];
        const double J20 =
          x0 * N[0][2] + x1 * N[1][2] + x2 * N[2][2] + x3 * N[3][2];
        const double J01 =
          y0 * N[0][0] + y1 * N[1][0] + y2 * N[2][0] + y3 * N[3][0];
        const double J11 =
          y0 * N[0][1] + y1 * N[1][1] + y2 * N[2][1] + y3 * N[3][1];
        const double J21 =
          y0 * N[0][2] + y1 * N[1][2] + y2 * N[2][2] + y3 * N[3][2];
        const double J02 =
          z0 * N[0][0] + z1 * N[1][0] + z2 * N[2][0] + z3 * N[3][0];
        const double J12 =
          z0 * N[0][1] + z1 * N[1][1] + z2 * N[2][1] + z3 * N[3][1];
        const double J22 =
          z0 * N[0][2] + z1 * N[1][2] + z2 * N[2][2] + z3 * N[3][2];
        const double det = J00 * (J11 * J22 - J12 * J21) -
                           J01 * (J10 * J22 - J12 * J20) +
                           J02 * (J10 * J21 - J11 * J20);
        w.JDet[t] = det;

        const double chi = coefChi(det, w.eps);
        const double chip = coefChip(det, w.eps);
        const double chi13 = std::cbrt(chi);
        const double chi23 = chi13 * chi13;
        const double traceJtJ = J00 * J00 + J10 * J10 + J20 * J20 + J01 * J01 +
                                J11 * J11 + J21 * J21 + J02 * J02 + J12 * J12 +
                                J22 * J22;
        const double fEps = traceJtJ / chi23;
        const double gEps = (det * det + 1.) / chi;
        w.elementEnergy[t] = fEps + w.lambda * gEps;

        const double coeff =
          2. / 3. * fEps * chip - 2. * w.lambda * det + w.lambda * gEps * chip;
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
          const uint32_t v = tet[k];
          if(w.locked[v]) continue;
          const double n0 = N[k][0], n1 = N[k][1], n2 = N[k][2];
          gradLocal[3 * v + 0] += d00 * n0 + d10 * n1 + d20 * n2;
          gradLocal[3 * v + 1] += d01 * n0 + d11 * n1 + d21 * n2;
          gradLocal[3 * v + 2] += d02 * n0 + d12 * n1 + d22 * n2;
        }
      }

#if defined(_OPENMP)
#pragma omp barrier
#endif
      const size_t gBegin =
        gradLength * (size_t)threadNum / (size_t)actualThreads;
      const size_t gEnd =
        gradLength * (size_t)(threadNum + 1) / (size_t)actualThreads;
      for(size_t i = gBegin; i < gEnd; ++i) {
        double g = 0.;
        for(int j = 0; j < actualThreads; ++j)
          g += GL[(size_t)j * gradLength + i];
        grad[i] = g;
      }
    }
    w.profileThreadsMin = std::min(w.profileThreadsMin, nthreads);
    w.profileThreadsMax = std::max(w.profileThreadsMax, nthreads);

    for(size_t t = 0; t < nElements; ++t) {
      if(w.JDet[t] < w.JDetMin) w.JDetMin = w.JDet[t];
      if(w.JDet[t] <= 0.) w.nbInvalid++;
      energy += w.elementEnergy[t];
    }

    if(std::isnan(energy)) energy = std::numeric_limits<double>::max();
    w.energy = energy;
    return w.energy;
  }

  static bool initializeEnergy(UntanglerDataGMSH &data,
                               const std::vector<double> &x)
  {
    data.JDetMin = DBL_MAX;
    data.nbInvalid = 0;
    for(size_t t = 0; t < data.JDet.size(); ++t) {
      const double det = (data.dim == 2) ? updateJacobian2D(t, data, x) :
                                           updateJacobian3D(t, data, x);
      if(det < data.JDetMin) data.JDetMin = det;
      if(det <= 0.) data.nbInvalid++;
    }
    data.eps =
      std::sqrt(1.e-12 + 0.04 * std::pow(std::min(data.JDetMin, 0.), 2));

    std::vector<double> grad(x.size(), 0.);
    if(data.dim == 2)
      computeEnergyAndGradient2D(data, x, grad);
    else
      computeEnergyAndGradient3D(data, x, grad);
    return true;
  }

  static void initialLaplacianSmooth3D(
    std::vector<double> &x, const std::vector<bool> &locked,
    const std::vector<std::array<uint32_t, 4>> &tets)
  {
    const int nIter = 10;
    const size_t nVertices = locked.size();
    std::vector<std::vector<uint32_t>> adj(nVertices);

    auto addEdge = [&adj](uint32_t a, uint32_t b) {
      adj[a].push_back(b);
      adj[b].push_back(a);
    };
    for(const auto &tet : tets) {
      addEdge(tet[0], tet[1]);
      addEdge(tet[0], tet[2]);
      addEdge(tet[0], tet[3]);
      addEdge(tet[1], tet[2]);
      addEdge(tet[1], tet[3]);
      addEdge(tet[2], tet[3]);
    }
    for(auto &a : adj) {
      std::sort(a.begin(), a.end());
      a.erase(std::unique(a.begin(), a.end()), a.end());
    }

    std::vector<double> xNew(x.size());
    for(int iter = 0; iter < nIter; ++iter) {
      xNew = x;
      for(size_t v = 0; v < nVertices; ++v) {
        if(locked[v] || adj[v].empty()) continue;
        double sx = 0., sy = 0., sz = 0.;
        for(uint32_t u : adj[v]) {
          sx += x[3 * u + 0];
          sy += x[3 * u + 1];
          sz += x[3 * u + 2];
        }
        const double inv = 1. / (double)adj[v].size();
        xNew[3 * v + 0] = sx * inv;
        xNew[3 * v + 1] = sy * inv;
        xNew[3 * v + 2] = sz * inv;
      }
      x.swap(xNew);
    }
  }

  static bool optimize(UntanglerDataGMSH &data, std::vector<double> &x,
                       double *points, size_t NV, int iterMaxInner,
                       int iterMaxOuter, int iterFailMax, double timeMax)
  {
    bool converged = false;
    int nFail = 0;
    double t0 = Cpu();
    double EPrev = data.energy;

    for(int iter = 0; iter < iterMaxOuter; ++iter) {
      data.eps =
        std::sqrt(1.e-12 + 0.04 * std::pow(std::min(data.JDetMin, 0.), 2));

      GmshLBFGS::Options options;
      options.maxIterations = iterMaxInner;
      options.memory = (int)std::min<size_t>(15, x.size());
      options.gradientTolerance = 1.e-4;
      options.functionTolerance = 1.e-12;
      options.stepTolerance = 1.e-12;
      options.maxLineSearchSteps = 80;
      options.verbose = 0;
      options.numThreads = requestedNumThreads();
      int lastInner = 0;
      double lastGradNorm = 0.;
      double lastStep = 0.;
      if(data.dim == 3) {
        options.iterationCallback =
          [&lastInner, &lastGradNorm,
           &lastStep](int inner, double /*f*/, double gradNorm, double step) {
            lastInner = inner;
            lastGradNorm = gradNorm;
            lastStep = step;
          };
      }

      auto fg = [&data](const std::vector<double> &xin,
                        std::vector<double> &gout) {
        const double t1 = TimeOfDay();
        const double f = (data.dim == 2) ?
                           computeEnergyAndGradient2D(data, xin, gout) :
                           computeEnergyAndGradient3D(data, xin, gout);
        data.profileCallback += TimeOfDay() - t1;
        data.profileCallbackCalls++;
        return f;
      };

      const double tLBFGS = TimeOfDay();
      GmshLBFGS::Result result = GmshLBFGS::minimize(x, fg, options);
      data.profileLBFGS += TimeOfDay() - tLBFGS;
      data.profileLBFGSFunction += result.timeFunction;
      data.profileLBFGSDirection += result.timeDirection;
      data.profileLBFGSLineSearch += result.timeLineSearch;
      data.profileLBFGSUpdate += result.timeUpdate;
      data.profileLBFGSEvaluations += result.functionEvaluations;

      const double dErel =
        data.energy > 0 ? std::abs(data.energy - EPrev) / data.energy : 0.;
      for(size_t i = 0; i < data.dim * NV; ++i) points[i] = x[i];
      if(data.dim == 3) {
        Msg::Info("GMSH Winslow 3D outer %d: eps %.6g, E %.6e, detmin "
                  "%.6g, invalid %d, |g| %.6g, step %.6g, inner %d, "
                  "term %d",
                  iter, data.eps, data.energy, data.JDetMin, data.nbInvalid,
                  lastGradNorm, lastStep, lastInner, result.terminationType);
      }
      if(result.terminationType != 4 &&
         !(result.terminationType == 5 && dErel > 1.e-5))
        nFail++;

      Msg::Debug("GMSH Winslow iter %d: eps=%g E=%.3e dE/E=%.3e "
                 "min(detJ)=%g inner=%d term=%d",
                 iter, data.eps, data.energy, dErel, data.JDetMin,
                 result.iterations, result.terminationType);
      if(data.JDetMin > 0. && dErel < 1.e-5) {
        converged = true;
        Msg::Debug("GMSH Winslow iter %d: converged |E-E_prev|/E = %.3e < "
                   "1.e-5",
                   iter, dErel);
        break;
      }
      if(nFail > iterFailMax) break;
      if(Cpu() - t0 > timeMax) break;
      EPrev = data.energy;
    }
    return converged;
  }
} // namespace

bool untangle_triangles_2D_GMSH(
  std::vector<std::array<double, 2>> &points, const std::vector<bool> &locked,
  const std::vector<std::array<uint32_t, 3>> &triangles,
  const std::vector<std::array<std::array<double, 2>, 3>> &triIdealShapes,
  double lambda, int iterMaxInner, int iterMaxOuter, int iterFailMax,
  double timeMax)
{
  if(points.empty() || triangles.empty()) {
    Msg::Warning("Wrong input sizes (%li vertices, %li triangles) in GMSH 2D "
                 "Winslow untangler",
                 points.size(), triangles.size());
    return false;
  }

  UntanglerDataGMSH data;
  data.lambda = lambda;
  data.profileTotal = TimeOfDay();
  if(!prepareData2D(points, locked, triangles, triIdealShapes, data))
    return false;

  std::vector<double> x(2 * points.size());
  for(size_t i = 0; i < points.size(); ++i) {
    x[2 * i + 0] = points[i][0];
    x[2 * i + 1] = points[i][1];
  }
  initializeEnergy(data, x);
  const bool converged =
    optimize(data, x, points.front().data(), points.size(), iterMaxInner,
             iterMaxOuter, iterFailMax, timeMax);
  data.profileTotal = TimeOfDay() - data.profileTotal;
  Msg::Info("GMSH Winslow 2D profiling: total %g s, LBFGS %g s, "
            "energy/gradient %g s in %zu calls, threads %d..%d",
            data.profileTotal, data.profileLBFGS, data.profileCallback,
            data.profileCallbackCalls, data.profileThreadsMin,
            data.profileThreadsMax);
  Msg::Info("GMSH LBFGS 2D profiling: function %g s, direction %g s, "
            "line-search %g s, update %g s, other %g s, evaluations %d",
            data.profileLBFGSFunction, data.profileLBFGSDirection,
            data.profileLBFGSLineSearch, data.profileLBFGSUpdate,
            data.profileLBFGS - data.profileLBFGSFunction -
              data.profileLBFGSDirection - data.profileLBFGSLineSearch -
              data.profileLBFGSUpdate,
            data.profileLBFGSEvaluations);
  return converged;
}

bool untangle_tetrahedra_GMSH(
  std::vector<std::array<double, 3>> &points, const std::vector<bool> &locked,
  const std::vector<std::array<uint32_t, 4>> &tets,
  const std::vector<std::array<std::array<double, 3>, 4>> &tetIdealShapes,
  double lambda, int iterMaxInner, int iterMaxOuter, int iterFailMax,
  double timeMax)
{
  if(points.empty() || tets.empty()) {
    Msg::Warning("Wrong input sizes (%li vertices, %li tetrahedra) in GMSH 3D "
                 "Winslow untangler",
                 points.size(), tets.size());
    return false;
  }

  UntanglerDataGMSH data;
  data.lambda = lambda;
  data.profileTotal = TimeOfDay();
  if(!prepareData3D(points, locked, tets, tetIdealShapes, data)) return false;

  std::vector<double> x(3 * points.size());
  for(size_t i = 0; i < points.size(); ++i) {
    x[3 * i + 0] = points[i][0];
    x[3 * i + 1] = points[i][1];
    x[3 * i + 2] = points[i][2];
  }
  initialLaplacianSmooth3D(x, locked, tets);
  for(size_t i = 0; i < points.size(); ++i) {
    points[i][0] = x[3 * i + 0];
    points[i][1] = x[3 * i + 1];
    points[i][2] = x[3 * i + 2];
  }
  initializeEnergy(data, x);
  const bool converged =
    optimize(data, x, points.front().data(), points.size(), iterMaxInner,
             iterMaxOuter, iterFailMax, timeMax);
  data.profileTotal = TimeOfDay() - data.profileTotal;
  Msg::Info("GMSH Winslow 3D profiling: total %g s, LBFGS %g s, "
            "energy/gradient %g s in %zu calls, threads %d..%d",
            data.profileTotal, data.profileLBFGS, data.profileCallback,
            data.profileCallbackCalls, data.profileThreadsMin,
            data.profileThreadsMax);
  Msg::Info("GMSH LBFGS 3D profiling: function %g s, direction %g s, "
            "line-search %g s, update %g s, other %g s, evaluations %d",
            data.profileLBFGSFunction, data.profileLBFGSDirection,
            data.profileLBFGSLineSearch, data.profileLBFGSUpdate,
            data.profileLBFGS - data.profileLBFGSFunction -
              data.profileLBFGSDirection - data.profileLBFGSLineSearch -
              data.profileLBFGSUpdate,
            data.profileLBFGSEvaluations);
  return converged;
}
