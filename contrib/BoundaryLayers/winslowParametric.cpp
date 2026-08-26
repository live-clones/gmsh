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

#include "winslowParametric.h"

#include "GFace.h"
#include "GaussIntegration.h"
#include "GmshMessage.h"
#include "OS.h"
#include "SPoint2.h"
#include "SVector3.h"
#include "gmshLBFGS.h"

#include <algorithm>
#include <array>
#include <cfloat>
#include <cmath>
#include <limits>

namespace {
  using vec2 = std::array<double, 2>;

  struct ParametricMetric {
    double weight = 1.;
    double g00 = 1., g01 = 0., g11 = 1.;
    double sqrtDetG = 1.;
  };

  struct ParametricTriangle {
    std::array<uint32_t, 3> v;
    std::array<vec2, 3> dShape;
    std::vector<ParametricMetric> metric;
  };

  struct ParametricWinslowData {
    double lambda = 1.;
    double eps = 1.e-6;
    double energy = 0.;
    double detMin = DBL_MAX;
    std::size_t invalid = 0;
    std::vector<bool> locked;
    std::vector<ParametricTriangle> triangles;
    std::vector<double> detJ;
    int quadratureOrder = 2;
    int quadraturePoints = 3;
  };

  static int triangleQuadratureOrderFromPointCount(int requestedPoints)
  {
    if(requestedPoints <= 1) return 1;
    for(int order = 2; order <= 8; ++order) {
      if(getNGQTPts(order) >= requestedPoints) return order;
    }
    return 8;
  }

  static inline double triArea(const vec2 &a, const vec2 &b, const vec2 &c)
  {
    return .5 * ((b[1] - a[1]) * (b[0] + a[0]) +
                 (c[1] - b[1]) * (c[0] + b[0]) +
                 (a[1] - c[1]) * (a[0] + c[0]));
  }

  static inline void coefChiAndChip(double D, double eps2, double &chi,
                                    double &chip)
  {
    const double s = std::sqrt(eps2 + D * D);
    chi = 0.5 * (D + s);
    chip = 0.5 + D / (2. * s);
  }

  static inline double coefChi(double D, double eps2)
  {
    return 0.5 * (D + std::sqrt(eps2 + D * D));
  }

  static bool surfaceMetricAt(GFace *gf, const vec2 &uv, double &g00,
                              double &g01, double &g11, double &sqrtDetG)
  {
    if(!gf) return false;
    const auto der = gf->firstDer(SPoint2(uv[0], uv[1]));
    g00 = dot(der.first, der.first);
    g01 = dot(der.first, der.second);
    g11 = dot(der.second, der.second);
    const double detG = g00 * g11 - g01 * g01;
    if(!(detG > 0.) || !std::isfinite(detG)) return false;
    sqrtDetG = std::sqrt(detG);
    return true;
  }

  static bool addTriangleData(
    GFace *gf, const std::vector<vec2> &points,
    const std::array<uint32_t, 3> &tri,
    const std::array<vec2, 3> &idealShape, int quadratureOrder,
    ParametricTriangle &out)
  {
    out.v = tri;

    const double a = triArea(idealShape[0], idealShape[1], idealShape[2]);
    if(std::isnan(a) || std::abs(a) <= 1.e-300) return false;
    if(a <= 0.)
      Msg::Warning("Winslow parametric: area of ideal triangle is %g", a);

    for(std::size_t le = 0; le < 3; ++le) {
      const vec2 td = {
        idealShape[(le + 2) % 3][0] - idealShape[(le + 1) % 3][0],
        idealShape[(le + 2) % 3][1] - idealShape[(le + 1) % 3][1]};
      out.dShape[le][0] = -td[1] / (2. * a);
      out.dShape[le][1] = td[0] / (2. * a);
    }

    const int npts = getNGQTPts(quadratureOrder);
    IntPt *qpts = getGQTPts(quadratureOrder);
    out.metric.resize(npts);
    for(int q = 0; q < npts; ++q) {
      const double xi = qpts[q].pt[0], eta = qpts[q].pt[1];
      const double bary[3] = {1. - xi - eta, xi, eta};
      vec2 uv = {{0., 0.}};
      for(int i = 0; i < 3; ++i) {
        if(tri[i] >= points.size()) return false;
        uv[0] += bary[i] * points[tri[i]][0];
        uv[1] += bary[i] * points[tri[i]][1];
      }

      ParametricMetric &m = out.metric[q];
      m.weight = 2. * qpts[q].weight;
      if(!surfaceMetricAt(gf, uv, m.g00, m.g01, m.g11, m.sqrtDetG)) {
        Msg::Warning("Winslow parametric: could not compute a positive surface "
                     "metric at uv=(%g,%g)",
                     uv[0], uv[1]);
        return false;
      }
    }
    return true;
  }

  static bool prepareData(
    GFace *gf, const std::vector<vec2> &points, const std::vector<bool> &locked,
    const std::vector<std::array<uint32_t, 3>> &triangles,
    const std::vector<std::array<vec2, 3>> &triIdealShapes,
    ParametricWinslowData &data, int requestedQuadraturePoints)
  {
    if(!gf) return false;
    if(points.empty() || triangles.empty()) return false;
    if(locked.size() != points.size()) {
      Msg::Error("Winslow parametric: wrong locked vector size");
      return false;
    }
    if(!triIdealShapes.empty() && triIdealShapes.size() != triangles.size()) {
      Msg::Error("Winslow parametric: incoherent triangle / ideal shape sizes");
      return false;
    }

    data.locked = locked;
    data.triangles.resize(triangles.size());
    data.detJ.assign(triangles.size(), 0.);
    data.quadratureOrder =
      triangleQuadratureOrderFromPointCount(requestedQuadraturePoints);
    data.quadraturePoints = getNGQTPts(data.quadratureOrder);

    const vec2 equi[3] = {
      {{1., 0.}},
      {{std::cos(2. * M_PI / 3.), std::sin(2. * M_PI / 3.)}},
      {{std::cos(4. * M_PI / 3.), std::sin(4. * M_PI / 3.)}}};

    for(std::size_t t = 0; t < triangles.size(); ++t) {
      std::array<vec2, 3> ideal = {{equi[0], equi[1], equi[2]}};
      if(!triIdealShapes.empty()) ideal = triIdealShapes[t];
      if(!addTriangleData(gf, points, triangles[t], ideal,
                          data.quadratureOrder, data.triangles[t]))
        return false;
    }
    return true;
  }

  static double energyOnly(const ParametricWinslowData &data,
                           const std::vector<double> &X)
  {
    const double eps2 = data.eps * data.eps;
    double energy = 0.;
    for(const ParametricTriangle &t : data.triangles) {
      const auto &tri = t.v;
      const double u0 = X[2 * tri[0] + 0], v0 = X[2 * tri[0] + 1];
      const double u1 = X[2 * tri[1] + 0], v1 = X[2 * tri[1] + 1];
      const double u2 = X[2 * tri[2] + 0], v2 = X[2 * tri[2] + 1];

      const double A00 = u0 * t.dShape[0][0] + u1 * t.dShape[1][0] +
                         u2 * t.dShape[2][0];
      const double A10 = u0 * t.dShape[0][1] + u1 * t.dShape[1][1] +
                         u2 * t.dShape[2][1];
      const double A01 = v0 * t.dShape[0][0] + v1 * t.dShape[1][0] +
                         v2 * t.dShape[2][0];
      const double A11 = v0 * t.dShape[0][1] + v1 * t.dShape[1][1] +
                         v2 * t.dShape[2][1];

      const double detA = A00 * A11 - A01 * A10;
      for(const ParametricMetric &m : t.metric) {
        const double det = m.sqrtDetG * detA;
        const double chi = coefChi(det, eps2);
        const double invChi = 1. / chi;
        const double trace =
          m.g00 * (A00 * A00 + A10 * A10) +
          2. * m.g01 * (A00 * A01 + A10 * A11) +
          m.g11 * (A01 * A01 + A11 * A11);
        energy +=
          m.weight *
          (trace * invChi + data.lambda * (det * det + 1.) * invChi);
      }
    }
    return energy;
  }

  static double energyAndGradient(ParametricWinslowData &data,
                                  const std::vector<double> &X,
                                  std::vector<double> &grad)
  {
    std::fill(grad.begin(), grad.end(), 0.);
    data.detMin = DBL_MAX;
    data.invalid = 0;

    const double eps2 = data.eps * data.eps;
    double energy = 0.;
    for(std::size_t it = 0; it < data.triangles.size(); ++it) {
      const ParametricTriangle &t = data.triangles[it];
      const auto &tri = t.v;
      const double u0 = X[2 * tri[0] + 0], v0 = X[2 * tri[0] + 1];
      const double u1 = X[2 * tri[1] + 0], v1 = X[2 * tri[1] + 1];
      const double u2 = X[2 * tri[2] + 0], v2 = X[2 * tri[2] + 1];

      const double A00 = u0 * t.dShape[0][0] + u1 * t.dShape[1][0] +
                         u2 * t.dShape[2][0];
      const double A10 = u0 * t.dShape[0][1] + u1 * t.dShape[1][1] +
                         u2 * t.dShape[2][1];
      const double A01 = v0 * t.dShape[0][0] + v1 * t.dShape[1][0] +
                         v2 * t.dShape[2][0];
      const double A11 = v0 * t.dShape[0][1] + v1 * t.dShape[1][1] +
                         v2 * t.dShape[2][1];

      const double detA = A00 * A11 - A01 * A10;
      data.detJ[it] = DBL_MAX;
      for(const ParametricMetric &m : t.metric) {
        const double det = m.sqrtDetG * detA;
        if(det < data.detJ[it]) data.detJ[it] = det;
        if(det < data.detMin) data.detMin = det;
        if(det <= 0.) data.invalid++;

        double chi, chip;
        coefChiAndChip(det, eps2, chi, chip);
        const double invChi = 1. / chi;
        const double trace =
          m.g00 * (A00 * A00 + A10 * A10) +
          2. * m.g01 * (A00 * A01 + A10 * A11) +
          m.g11 * (A01 * A01 + A11 * A11);
        const double elemEnergy =
          trace * invChi + data.lambda * (det * det + 1.) * invChi;
        energy += m.weight * elemEnergy;

        const double cD =
          (2. * data.lambda * det - elemEnergy * chip) * invChi;
        const double dI00 = 2. * (m.g00 * A00 + m.g01 * A01);
        const double dI10 = 2. * (m.g00 * A10 + m.g01 * A11);
        const double dI01 = 2. * (m.g01 * A00 + m.g11 * A01);
        const double dI11 = 2. * (m.g01 * A10 + m.g11 * A11);
        const double d00 =
          m.weight * (invChi * dI00 + cD * m.sqrtDetG * A11);
        const double d10 =
          m.weight * (invChi * dI10 - cD * m.sqrtDetG * A01);
        const double d01 =
          m.weight * (invChi * dI01 - cD * m.sqrtDetG * A10);
        const double d11 =
          m.weight * (invChi * dI11 + cD * m.sqrtDetG * A00);

        for(int k = 0; k < 3; ++k) {
          const uint32_t v = tri[k];
          if(data.locked[v]) continue;
          const double n0 = t.dShape[k][0], n1 = t.dShape[k][1];
          grad[2 * v + 0] += d00 * n0 + d10 * n1;
          grad[2 * v + 1] += d01 * n0 + d11 * n1;
        }
      }
    }
    data.energy = energy;
    return energy;
  }

  static double bboxDiag(const std::vector<vec2> &points)
  {
    if(points.empty()) return 1.;
    double umin = DBL_MAX, vmin = DBL_MAX;
    double umax = -DBL_MAX, vmax = -DBL_MAX;
    for(const vec2 &p : points) {
      umin = std::min(umin, p[0]);
      umax = std::max(umax, p[0]);
      vmin = std::min(vmin, p[1]);
      vmax = std::max(vmax, p[1]);
    }
    const double du = umax - umin, dv = vmax - vmin;
    return std::sqrt(du * du + dv * dv);
  }

} // namespace

bool untangle_triangles_parametric_GMSH(
  GFace *gf, std::vector<std::array<double, 2>> &parametricPoints,
  const std::vector<bool> &locked,
  const std::vector<std::array<uint32_t, 3>> &triangles,
  const std::vector<std::array<std::array<double, 2>, 3>> &triIdealShapes,
  double lambda, int iterMax, double timeMax, int quadraturePoints)
{
  if(!gf || parametricPoints.empty() || triangles.empty()) {
    Msg::Warning("Wrong input sizes in parametric Winslow untangler");
    return false;
  }

  ParametricWinslowData data;
  data.lambda = lambda;
  if(!prepareData(gf, parametricPoints, locked, triangles, triIdealShapes, data,
                  quadraturePoints))
    return false;

  std::vector<double> x(2 * parametricPoints.size());
  for(std::size_t i = 0; i < parametricPoints.size(); ++i) {
    x[2 * i + 0] = parametricPoints[i][0];
    x[2 * i + 1] = parametricPoints[i][1];
  }

  std::vector<double> grad(x.size());
  const double initialEnergy = energyAndGradient(data, x, grad);

  GmshLBFGS::Options options;
  options.maxIterations = std::max(1, iterMax);
  options.memory = 10;
  options.gradientTolerance = 1.e-8;
  options.functionTolerance = 1.e-14;
  options.stepTolerance = 1.e-14;
  options.maxStepNorm = std::max(1.e-12, 0.1 * bboxDiag(parametricPoints));
  options.verbose = 0;
  (void)timeMax;

  const double t0 = TimeOfDay();
  auto fg = [&](const std::vector<double> &X, std::vector<double> &G) {
    return energyAndGradient(data, X, G);
  };
  auto f = [&](const std::vector<double> &X) { return energyOnly(data, X); };
  GmshLBFGS::Result result = GmshLBFGS::minimize(x, fg, f, options);
  const double total = TimeOfDay() - t0;

  for(std::size_t i = 0; i < parametricPoints.size(); ++i) {
    parametricPoints[i][0] = x[2 * i + 0];
    parametricPoints[i][1] = x[2 * i + 1];
  }

  Msg::Info("GMSH parametric Winslow profiling: total %g s, quadrature %d "
            "points (order %d), "
            "initial E %.6e, final E %.6e, detmin %.6g, invalid %zu, "
            "iterations %d, evaluations %d",
            total, data.quadraturePoints, data.quadratureOrder, initialEnergy,
            data.energy, data.detMin, data.invalid, result.iterations,
            result.functionEvaluations);
  return result.terminationType >= 0;
}
