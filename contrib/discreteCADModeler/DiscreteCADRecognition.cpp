// Gmsh Discrete CAD Modeler - Copyright (C) 2026 C. Geuzaine and J.-F. Remacle
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

#include <algorithm>
#include <cmath>
#include <functional>
#include <map>
#include <queue>
#include <set>
#include "DiscreteCADRecognition.h"

namespace {
  const double pi = 3.14159265358979323846;

  double dot(const double a[3], const double b[3])
  {
    return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
  }

  void cross(const double a[3], const double b[3], double c[3])
  {
    c[0] = a[1] * b[2] - a[2] * b[1];
    c[1] = a[2] * b[0] - a[0] * b[2];
    c[2] = a[0] * b[1] - a[1] * b[0];
  }

  double norm(const double a[3]) { return std::sqrt(dot(a, a)); }

  bool normalize(double a[3])
  {
    const double l = norm(a);
    if(!(l > 0.)) return false;
    for(int k = 0; k < 3; k++) a[k] /= l;
    return true;
  }

  // two unit vectors e0, e1 making a direct orthonormal frame with the unit
  // vector a
  void frame(const double a[3], double e0[3], double e1[3])
  {
    int m = 0;
    for(int k = 1; k < 3; k++)
      if(std::abs(a[k]) < std::abs(a[m])) m = k;
    for(int k = 0; k < 3; k++) e0[k] = (k == m) - a[m] * a[k];
    normalize(e0);
    cross(a, e0, e1);
  }

  // the eigenvalues, increasing, and the eigenvectors (the rows of v) of the
  // symmetric matrix a (Jacobi rotations)
  void eigen(const double a[3][3], double w[3], double v[3][3])
  {
    double m[3][3], r[3][3];
    for(int i = 0; i < 3; i++)
      for(int j = 0; j < 3; j++) {
        m[i][j] = a[i][j];
        r[i][j] = i == j;
      }
    for(int sweep = 0; sweep < 50; sweep++) {
      const double off =
        std::abs(m[0][1]) + std::abs(m[0][2]) + std::abs(m[1][2]);
      const double diagonal =
        std::abs(m[0][0]) + std::abs(m[1][1]) + std::abs(m[2][2]);
      if(off <= 1.e-300 || off <= 1.e-17 * diagonal) break;
      for(int p = 0; p < 2; p++)
        for(int q = p + 1; q < 3; q++) {
          if(m[p][q] == 0.) continue;
          const double theta = (m[q][q] - m[p][p]) / (2. * m[p][q]);
          const double t = (theta >= 0. ? 1. : -1.) /
                           (std::abs(theta) + std::sqrt(theta * theta + 1.));
          const double c = 1. / std::sqrt(t * t + 1.), s = t * c;
          for(int k = 0; k < 3; k++) {
            const double mkp = m[k][p], mkq = m[k][q];
            m[k][p] = c * mkp - s * mkq;
            m[k][q] = s * mkp + c * mkq;
          }
          for(int k = 0; k < 3; k++) {
            const double mpk = m[p][k], mqk = m[q][k];
            m[p][k] = c * mpk - s * mqk;
            m[q][k] = s * mpk + c * mqk;
          }
          for(int k = 0; k < 3; k++) {
            const double rkp = r[k][p], rkq = r[k][q];
            r[k][p] = c * rkp - s * rkq;
            r[k][q] = s * rkp + c * rkq;
          }
        }
    }
    int order[3] = {0, 1, 2};
    std::sort(order, order + 3,
              [&](int i, int j) { return m[i][i] < m[j][j]; });
    for(int i = 0; i < 3; i++) {
      w[i] = m[order[i]][order[i]];
      for(int k = 0; k < 3; k++) v[i][k] = r[k][order[i]];
    }
  }

  // the solution of a x = b (n unknowns, a row by row) in b, false if a is
  // singular (Gaussian elimination with partial pivoting)
  bool solve(int n, std::vector<double> a, std::vector<double> &b)
  {
    for(int c = 0; c < n; c++) {
      int p = c;
      for(int r = c + 1; r < n; r++)
        if(std::abs(a[r * n + c]) > std::abs(a[p * n + c])) p = r;
      if(a[p * n + c] == 0.) return false;
      if(p != c) {
        for(int k = 0; k < n; k++) std::swap(a[p * n + k], a[c * n + k]);
        std::swap(b[p], b[c]);
      }
      for(int r = c + 1; r < n; r++) {
        const double f = a[r * n + c] / a[c * n + c];
        for(int k = c; k < n; k++) a[r * n + k] -= f * a[c * n + k];
        b[r] -= f * b[c];
      }
    }
    for(int c = n - 1; c >= 0; c--) {
      double s = b[c];
      for(int k = c + 1; k < n; k++) s -= a[c * n + k] * b[k];
      b[c] = s / a[c * n + c];
    }
    for(double v : b)
      if(!std::isfinite(v)) return false;
    return true;
  }

  // the linear least squares solution of the rows of a (n unknowns) = b
  bool leastSquares(int n, const std::vector<double> &a,
                    const std::vector<double> &b, std::vector<double> &x)
  {
    std::vector<double> ata(n * n, 0.);
    x.assign(n, 0.);
    for(std::size_t i = 0; i < b.size(); i++)
      for(int j = 0; j < n; j++) {
        x[j] += a[i * n + j] * b[i];
        for(int k = 0; k < n; k++) ata[j * n + k] += a[i * n + j] * a[i * n + k];
      }
    return solve(n, ata, x);
  }

  // the circle (center (cu, cv), radius r) nearest to the points (u, v), in
  // the algebraic sense
  bool circle(const std::vector<double> &u, const std::vector<double> &v,
              double &cu, double &cv, double &r)
  {
    std::vector<double> a, b, x;
    for(std::size_t i = 0; i < u.size(); i++) {
      a.insert(a.end(), {u[i], v[i], 1.});
      b.push_back(-(u[i] * u[i] + v[i] * v[i]));
    }
    if(!leastSquares(3, a, b, x)) return false;
    cu = -x[0] / 2.;
    cv = -x[1] / 2.;
    const double r2 = cu * cu + cv * cv - x[2];
    if(!(r2 > 0.)) return false;
    r = std::sqrt(r2);
    return true;
  }

  typedef std::function<void(const std::vector<double> &,
                             std::vector<double> &)>
    Residuals;

  // the parameters p minimizing the sum of the squares of the residuals
  // (Levenberg-Marquardt, the Jacobian by central differences), stopped when
  // it stagnates above target (the residuals cannot all get below it)
  void minimize(std::vector<double> &p, const Residuals &residuals,
                double target)
  {
    const int np = (int)p.size();
    std::vector<double> r, rq, q;
    residuals(p, r);
    const int n = (int)r.size();
    auto sum = [](const std::vector<double> &v) {
      double s = 0.;
      for(double x : v) s += x * x;
      return s;
    };
    double cost = sum(r), lambda = 1.e-3;
    std::vector<double> jac(n * np), plus, minus;
    for(int it = 0; it < 50; it++) {
      for(int j = 0; j < np; j++) {
        const double h = 1.e-7 * (1. + std::abs(p[j]));
        q = p;
        q[j] = p[j] + h;
        residuals(q, plus);
        q[j] = p[j] - h;
        residuals(q, minus);
        for(int i = 0; i < n; i++)
          jac[i * np + j] = (plus[i] - minus[i]) / (2. * h);
      }
      std::vector<double> jtj(np * np, 0.), jtr(np, 0.);
      for(int i = 0; i < n; i++)
        for(int j = 0; j < np; j++) {
          jtr[j] += jac[i * np + j] * r[i];
          for(int k = 0; k < np; k++)
            jtj[j * np + k] += jac[i * np + j] * jac[i * np + k];
        }
      const double previous = cost;
      bool improved = false;
      for(int k = 0; k < 20 && !improved; k++) {
        std::vector<double> a = jtj, b(np);
        for(int j = 0; j < np; j++) {
          a[j * np + j] += lambda * jtj[j * np + j] + 1.e-15;
          b[j] = -jtr[j];
        }
        if(solve(np, a, b)) {
          q = p;
          for(int j = 0; j < np; j++) q[j] += b[j];
          residuals(q, rq);
          const double c = sum(rq);
          if(c < cost) {
            p = q;
            r = rq;
            cost = c;
            improved = true;
            lambda = std::max(lambda * 0.3, 1.e-12);
            break;
          }
        }
        lambda *= 10.;
      }
      if(!improved || previous - cost <= 1.e-14 * previous) break;
      if(previous - cost < 1.e-2 * previous && cost > n * target * target)
        break;
    }
  }

  // the unit vector of parameters p[i], p[i + 1], p[i + 2]
  void direction(const std::vector<double> &p, int i, double a[3])
  {
    for(int k = 0; k < 3; k++) a[k] = p[i + k];
    if(!normalize(a)) a[0] = 1.;
  }
} // namespace

double DiscreteCADAnalyticSurface::distance(const double x[3]) const
{
  double d[3];
  for(int k = 0; k < 3; k++) d[k] = x[k] - o[k];
  const double h = dot(d, axis);
  double e[3];
  for(int k = 0; k < 3; k++) e[k] = d[k] - h * axis[k];
  const double rho = norm(e);
  switch(type) {
  case PLANE: return h;
  case SPHERE: return norm(d) - r1;
  case CYLINDER: return rho - r1;
  case CONE: return rho * std::cos(r1) - h * std::sin(r1);
  case TORUS: return std::sqrt((rho - r1) * (rho - r1) + h * h) - r2;
  default: return 0.;
  }
}

void DiscreteCADAnalyticSurface::normal(const double x[3], double n[3]) const
{
  double d[3];
  for(int k = 0; k < 3; k++) d[k] = x[k] - o[k];
  const double h = dot(d, axis);
  double e[3];
  for(int k = 0; k < 3; k++) e[k] = d[k] - h * axis[k];
  const bool radial = normalize(e);
  switch(type) {
  case PLANE:
    for(int k = 0; k < 3; k++) n[k] = axis[k];
    break;
  case SPHERE:
    for(int k = 0; k < 3; k++) n[k] = d[k];
    normalize(n);
    break;
  case CYLINDER:
    for(int k = 0; k < 3; k++) n[k] = radial ? e[k] : 0.;
    break;
  case CONE:
    for(int k = 0; k < 3; k++)
      n[k] = (radial ? std::cos(r1) * e[k] : 0.) - std::sin(r1) * axis[k];
    break;
  case TORUS:
    // from the center of the section
    for(int k = 0; k < 3; k++) n[k] = d[k] - (radial ? r1 * e[k] : 0.);
    normalize(n);
    break;
  default:
    for(int k = 0; k < 3; k++) n[k] = 0.;
  }
}

namespace {
  // the conformal coordinate of the angle a around the section of a torus,
  // ds = r2 da / (r1 + r2 cos(a)), continuous for all a, and its inverse
  double conformalCoordinate(double r1, double r2, double a)
  {
    const double c = std::sqrt(r1 * r1 - r2 * r2);
    const double k = std::sqrt((r1 - r2) / (r1 + r2));
    return 2. * r2 / c * std::atan(k * std::tan(a / 2.)) +
           2. * pi * r2 / c * std::floor((a + pi) / (2. * pi));
  }
  double conformalAngle(double r1, double r2, double s)
  {
    const double c = std::sqrt(r1 * r1 - r2 * r2);
    const double k = std::sqrt((r1 - r2) / (r1 + r2));
    const double period = 2. * pi * r2 / c;
    const double m = std::round(s / period);
    const double s0 = s - m * period;
    return 2. * std::atan(std::tan(s0 * c / (2. * r2)) / k) + 2. * pi * m;
  }
  // the angle a + 2 k pi nearest to the reference
  double near(double a, double reference)
  {
    return a + 2. * pi * std::round((reference - a) / (2. * pi));
  }
} // namespace

void DiscreteCADAnalyticMap::point(double u, double v, double x[3]) const
{
  const double *o = surface.o, *a = surface.axis;
  switch(kind) {
  case PLANE:
    for(int k = 0; k < 3; k++) x[k] = o[k] + u * e0[k] + v * e1[k];
    break;
  case DEVELOPED:
  case DISK:
    if(surface.type == DiscreteCADAnalyticSurface::CYLINDER) {
      const double r = surface.r1, t = u / r;
      for(int k = 0; k < 3; k++)
        x[k] = o[k] + r * std::cos(t) * e0[k] + r * std::sin(t) * e1[k] +
               v * a[k];
    }
    else {
      // a cone: the distance to the apex and the angle around the axis
      const double sinHalf = std::sin(surface.r1), cosHalf = std::cos(surface.r1);
      double s, t;
      if(kind == DISK) {
        s = scale * std::hypot(u, v);
        t = std::atan2(v, u);
      }
      else {
        s = std::hypot(u, v);
        t = near(std::atan2(v, u), reference) / sinHalf;
      }
      for(int k = 0; k < 3; k++)
        x[k] = o[k] + s * (sinHalf * (std::cos(t) * e0[k] + std::sin(t) * e1[k]) +
                           cosHalf * a[k]);
    }
    break;
  case STEREOGRAPHIC: {
    const double w = u * u + v * v;
    for(int k = 0; k < 3; k++)
      x[k] = o[k] + surface.r1 * (2. * u * e0[k] + 2. * v * e1[k] +
                                  scale * (1. - w) * d[k]) /
                      (1. + w);
  } break;
  case ANNULUS: {
    const double rho = std::hypot(u, v), t = std::atan2(v, u);
    const double phi =
      conformalAngle(surface.r1, surface.r2, lowest + std::log(rho) / scale);
    const double radial = surface.r1 + surface.r2 * std::cos(phi);
    for(int k = 0; k < 3; k++)
      x[k] = o[k] + radial * (std::cos(t) * e0[k] + std::sin(t) * e1[k]) +
             surface.r2 * std::sin(phi) * a[k];
  } break;
  default:
    for(int k = 0; k < 3; k++) x[k] = 0.;
  }
}

void DiscreteCADAnalyticMap::parameters(const double x[3], const double *guess,
                                        double uv[2]) const
{
  const double *o = surface.o, *a = surface.axis;
  double p[3];
  for(int k = 0; k < 3; k++) p[k] = x[k] - o[k];
  const double c0 = dot(p, e0), c1 = dot(p, e1), c2 = dot(p, a);
  const double t = std::atan2(c1, c0), rho = std::hypot(c0, c1);
  switch(kind) {
  case PLANE:
    uv[0] = c0;
    uv[1] = c1;
    break;
  case DEVELOPED:
  case DISK:
    if(surface.type == DiscreteCADAnalyticSurface::CYLINDER) {
      const double r = surface.r1;
      const double ref = guess ? guess[0] / r : reference;
      uv[0] = r * near(t, ref);
      uv[1] = c2;
    }
    else {
      // the point of the generatrix in the plane of the axis and x nearest
      // to it
      const double sinHalf = std::sin(surface.r1), cosHalf = std::cos(surface.r1);
      const double s = std::max(0., rho * sinHalf + c2 * cosHalf);
      if(kind == DISK) {
        uv[0] = s / scale * std::cos(t);
        uv[1] = s / scale * std::sin(t);
      }
      else {
        // (the angle t + 2 k pi whose developed angle is nearest to the
        // reference)
        const double ref =
          guess ? near(std::atan2(guess[1], guess[0]), reference) : reference;
        const double phi = near(t, ref / sinHalf) * sinHalf;
        uv[0] = s * std::cos(phi);
        uv[1] = s * std::sin(phi);
      }
    }
    break;
  case STEREOGRAPHIC: {
    double q[3] = {p[0], p[1], p[2]};
    normalize(q);
    const double den = 1. + scale * dot(q, d);
    uv[0] = dot(q, e0) / den;
    uv[1] = dot(q, e1) / den;
  } break;
  case ANNULUS: {
    double phi = std::atan2(c2, rho - surface.r1);
    phi = cut + std::fmod(std::fmod(phi - cut, 2. * pi) + 2. * pi, 2. * pi);
    const double r =
      std::exp(scale * (conformalCoordinate(surface.r1, surface.r2, phi) - lowest));
    uv[0] = r * std::cos(t);
    uv[1] = r * std::sin(t);
  } break;
  default: uv[0] = uv[1] = 0.;
  }
}

void DiscreteCADAnalyticMap::setReference(
  const std::vector<std::array<std::array<double, 2>, 3> > &uv)
{
  if(kind != DEVELOPED || uv.empty()) return;
  if(surface.type == DiscreteCADAnalyticSurface::CYLINDER) {
    double lo = 1e300, hi = -1e300;
    for(auto &t : uv)
      for(auto &p : t) {
        lo = std::min(lo, p[0]);
        hi = std::max(hi, p[0]);
      }
    reference = (lo + hi) / 2. / surface.r1;
  }
  else {
    double su = 0., sv = 0.;
    for(auto &t : uv)
      for(auto &p : t) {
        su += p[0];
        sv += p[1];
      }
    reference = std::atan2(sv, su);
  }
}

DiscreteCADAnalyticSurface
recognizeSurface(const std::vector<std::array<double, 3> > &x,
                 const std::vector<std::array<int, 3> > &triangles,
                 double tolerance, double angle)
{
  typedef DiscreteCADAnalyticSurface Analytic;
  const std::size_t n = x.size(), nt = triangles.size();
  if(n < 3 || !nt) return Analytic();

  // the coordinates scaled around the center of their bounding box
  double lo[3] = {1e300, 1e300, 1e300}, hi[3] = {-1e300, -1e300, -1e300};
  for(auto &p : x)
    for(int k = 0; k < 3; k++) {
      lo[k] = std::min(lo[k], p[k]);
      hi[k] = std::max(hi[k], p[k]);
    }
  double m[3], size = 0.;
  for(int k = 0; k < 3; k++) {
    m[k] = (lo[k] + hi[k]) / 2.;
    size += (hi[k] - lo[k]) * (hi[k] - lo[k]);
  }
  size = std::sqrt(size) / 2.;
  if(!(size > 0.)) return Analytic();
  std::vector<std::array<double, 3> > y(n);
  for(std::size_t i = 0; i < n; i++)
    for(int k = 0; k < 3; k++) y[i][k] = (x[i][k] - m[k]) / size;
  // the unit normals, areas and centroids of the triangles (scaled)
  std::vector<std::array<double, 3> > normal(nt), centroid(nt);
  std::vector<double> area(nt);
  for(std::size_t t = 0; t < nt; t++) {
    const std::array<double, 3> &a = y[triangles[t][0]],
                                &b = y[triangles[t][1]],
                                &c = y[triangles[t][2]];
    double u[3], v[3], w[3];
    for(int k = 0; k < 3; k++) {
      u[k] = b[k] - a[k];
      v[k] = c[k] - a[k];
      centroid[t][k] = (a[k] + b[k] + c[k]) / 3.;
    }
    cross(u, v, w);
    area[t] = norm(w) / 2.;
    if(area[t] > 0.) normalize(w);
    normal[t] = {{w[0], w[1], w[2]}};
  }
  // the nodes the fits use (at most about 500)
  std::vector<std::size_t> sample;
  const std::size_t stride = std::max<std::size_t>(1, n / 500);
  for(std::size_t i = 0; i < n; i += stride) sample.push_back(i);
  const std::size_t ns = sample.size();
  const double scaledTolerance = tolerance / size;

  // the surfaces fitted in the scaled coordinates, candidates if they are
  // within the tolerance of all the nodes and their normals agree with those
  // of the triangles (on the same side); the simplest one at most twice as far
  // from the nodes as the nearest one (the rounding apart) is chosen: a short
  // cylinder can be within the tolerance of a sphere
  std::vector<std::pair<Analytic, double> > candidates;
  const double rounding = 1.e-12 * size;
  auto choice = [&]() {
    double nearest = 1e300;
    for(auto &c : candidates) nearest = std::min(nearest, c.second);
    for(auto &c : candidates)
      if(c.second <= 2. * nearest + rounding) return c.first;
    return Analytic();
  };
  const double cosAngle = std::cos(angle);
  // (true if it is exact: no other surface can then be chosen)
  auto accept = [&](Analytic s) {
    for(int k = 0; k < 3; k++) s.o[k] = m[k] + size * s.o[k];
    if(s.type != Analytic::CONE) s.r1 *= size;
    s.r2 *= size;
    if(!normalize(s.axis)) return false;
    double deviation = 0.;
    for(std::size_t i = 0; i < n; i++) {
      const double d = std::abs(s.distance(x[i].data()));
      if(!(d <= tolerance)) return false;
      deviation = std::max(deviation, d);
    }
    int side = 0;
    for(std::size_t t = 0; t < nt; t++) {
      if(!(area[t] > 0.)) continue;
      double c[3], sn[3];
      for(int k = 0; k < 3; k++) c[k] = m[k] + size * centroid[t][k];
      s.normal(c, sn);
      const double d = dot(sn, normal[t].data());
      if(!(std::abs(d) >= cosAngle)) return false;
      const int sd = d > 0. ? 1 : -1;
      if(side && sd != side) return false;
      side = sd;
    }
    candidates.push_back({s, deviation});
    return deviation <= rounding;
  };

  // a plane: the principal axes of the nodes
  {
    double c[3] = {0., 0., 0.}, cov[3][3] = {{0.}}, w[3], v[3][3];
    for(auto &p : y)
      for(int k = 0; k < 3; k++) c[k] += p[k] / n;
    for(auto &p : y)
      for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++) cov[i][j] += (p[i] - c[i]) * (p[j] - c[j]);
    eigen(cov, w, v);
    Analytic s;
    s.type = Analytic::PLANE;
    for(int k = 0; k < 3; k++) {
      s.o[k] = c[k];
      s.axis[k] = v[0][k];
    }
    if(accept(s)) return choice();
  }

  // a sphere: the algebraic fit |y|^2 + d.y + e = 0, then the geometric one
  if(n >= 10) {
    std::vector<double> a, b, sol;
    for(std::size_t i : sample) {
      a.insert(a.end(), {y[i][0], y[i][1], y[i][2], 1.});
      b.push_back(-(y[i][0] * y[i][0] + y[i][1] * y[i][1] + y[i][2] * y[i][2]));
    }
    if(leastSquares(4, a, b, sol)) {
      std::vector<double> p = {-sol[0] / 2., -sol[1] / 2., -sol[2] / 2., 0.};
      const double r2 = p[0] * p[0] + p[1] * p[1] + p[2] * p[2] - sol[3];
      if(r2 > 0.) {
        p[3] = std::sqrt(r2);
        minimize(p, [&](const std::vector<double> &q, std::vector<double> &r) {
          r.resize(ns);
          for(std::size_t j = 0; j < ns; j++) {
            const std::array<double, 3> &z = y[sample[j]];
            r[j] = std::sqrt((z[0] - q[0]) * (z[0] - q[0]) +
                             (z[1] - q[1]) * (z[1] - q[1]) +
                             (z[2] - q[2]) * (z[2] - q[2])) -
                   q[3];
          }
        }, scaledTolerance);
        Analytic s;
        s.type = Analytic::SPHERE;
        for(int k = 0; k < 3; k++) s.o[k] = p[k];
        s.axis[2] = 1.;
        s.r1 = std::abs(p[3]);
        if(accept(s)) return choice();
      }
    }
  }

  // the axes of a cylinder or a cone: those along which the normals of the
  // triangles vary the least
  double axes[3][3];
  {
    double c[3] = {0., 0., 0.}, cov[3][3] = {{0.}}, w[3], total = 0.;
    for(std::size_t t = 0; t < nt; t++) {
      total += area[t];
      for(int k = 0; k < 3; k++) c[k] += area[t] * normal[t][k];
    }
    if(!(total > 0.)) return Analytic();
    for(int k = 0; k < 3; k++) c[k] /= total;
    for(std::size_t t = 0; t < nt; t++)
      for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
          cov[i][j] +=
            area[t] * (normal[t][i] - c[i]) * (normal[t][j] - c[j]);
    eigen(cov, w, axes);
  }
  // the residuals fixing the free parameters of an axis (point p[0..2],
  // direction p[3..5]) from res[i]: the norm of its direction and, for a
  // cylinder, the position of its point along it
  auto gauge = [](const std::vector<double> &p, std::vector<double> &res,
                  std::size_t i, bool cylinder) {
    res[i] = p[3] * p[3] + p[4] * p[4] + p[5] * p[5] - 1.;
    if(cylinder) res[i + 1] = p[0] * p[3] + p[1] * p[4] + p[2] * p[5];
  };
  // the distance of y to the axis of point p[i..i+2] and direction p[j..j+2]
  // and its height along it
  auto axial = [](const std::array<double, 3> &z, const std::vector<double> &p,
                  int i, int j, double &h) {
    double a[3], d[3], e[3];
    direction(p, j, a);
    for(int k = 0; k < 3; k++) d[k] = z[k] - p[i + k];
    h = dot(d, a);
    for(int k = 0; k < 3; k++) e[k] = d[k] - h * a[k];
    return norm(e);
  };

  // a cylinder: the circle of the nodes projected along the axis, then the
  // geometric fit
  if(n >= 12) {
    for(int candidate = 0; candidate < 2; candidate++) {
      const double *a = axes[candidate];
      double e0[3], e1[3];
      frame(a, e0, e1);
      std::vector<double> u, v;
      for(std::size_t i : sample) {
        u.push_back(dot(y[i].data(), e0));
        v.push_back(dot(y[i].data(), e1));
      }
      double cu, cv, r;
      if(!circle(u, v, cu, cv, r)) continue;
      std::vector<double> p(7);
      for(int k = 0; k < 3; k++) {
        p[k] = cu * e0[k] + cv * e1[k];
        p[3 + k] = a[k];
      }
      p[6] = r;
      minimize(p, [&](const std::vector<double> &q, std::vector<double> &res) {
        res.resize(ns + 2);
        double h;
        for(std::size_t j = 0; j < ns; j++)
          res[j] = axial(y[sample[j]], q, 0, 3, h) - q[6];
        gauge(q, res, ns, true);
      }, scaledTolerance);
      Analytic s;
      s.type = Analytic::CYLINDER;
      direction(p, 3, s.axis);
      for(int k = 0; k < 3; k++) s.o[k] = p[k];
      s.r1 = std::abs(p[6]);
      if(accept(s)) return choice();
    }
  }

  // a cone: its apex on the tangent planes at the centroids of the triangles,
  // its half angle from the nodes, then the geometric fit
  if(n >= 14) {
    for(int candidate = 0; candidate < 2; candidate++) {
      double a[3] = {axes[candidate][0], axes[candidate][1],
                     axes[candidate][2]};
      std::vector<double> nn(9, 0.), rhs(3, 0.);
      for(std::size_t t = 0; t < nt; t++) {
        const double d = dot(normal[t].data(), centroid[t].data());
        for(int i = 0; i < 3; i++) {
          rhs[i] += area[t] * normal[t][i] * d;
          for(int j = 0; j < 3; j++)
            nn[i * 3 + j] += area[t] * normal[t][i] * normal[t][j];
        }
      }
      if(!solve(3, nn, rhs)) continue;
      double mean = 0.;
      for(std::size_t i : sample) {
        double d[3];
        for(int k = 0; k < 3; k++) d[k] = y[i][k] - rhs[k];
        mean += dot(d, a);
      }
      if(mean < 0.)
        for(int k = 0; k < 3; k++) a[k] = -a[k];
      double half = 0.;
      for(std::size_t i : sample) {
        double d[3], e[3];
        for(int k = 0; k < 3; k++) d[k] = y[i][k] - rhs[k];
        const double h = dot(d, a);
        for(int k = 0; k < 3; k++) e[k] = d[k] - h * a[k];
        half += std::atan2(norm(e), h) / ns;
      }
      std::vector<double> p = {rhs[0], rhs[1], rhs[2], a[0], a[1], a[2], half};
      minimize(p, [&](const std::vector<double> &q, std::vector<double> &res) {
        res.resize(ns + 1);
        double h;
        for(std::size_t j = 0; j < ns; j++) {
          const double rho = axial(y[sample[j]], q, 0, 3, h);
          res[j] = rho * std::cos(q[6]) - h * std::sin(q[6]);
        }
        gauge(q, res, ns, false);
      }, scaledTolerance);
      if(!(p[6] > 0. && p[6] < pi / 2.)) continue;
      Analytic s;
      s.type = Analytic::CONE;
      direction(p, 3, s.axis);
      for(int k = 0; k < 3; k++) s.o[k] = p[k];
      s.r1 = p[6];
      if(accept(s)) return choice();
    }
  }

  // a torus: its axis, the line meeting the normal lines at the centroids of
  // the triangles (in Pluecker coordinates (a, m), a . (c x n) + n . m = 0,
  // m eliminated), the circle of its section in the half plane of the nodes
  // around it, then the geometric fit
  if(n >= 16) {
    double aw[3][3] = {{0.}}, b[3][3] = {{0.}};
    std::vector<double> c(9, 0.);
    for(std::size_t t = 0; t < nt; t++) {
      double w[3];
      cross(centroid[t].data(), normal[t].data(), w);
      for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++) {
          aw[i][j] += area[t] * w[i] * w[j];
          b[i][j] += area[t] * w[i] * normal[t][j];
          c[i * 3 + j] += area[t] * normal[t][i] * normal[t][j];
        }
    }
    // x = c^-1 b^T, column by column
    double x3[3][3];
    bool invertible = true;
    for(int j = 0; j < 3 && invertible; j++) {
      std::vector<double> col = {b[j][0], b[j][1], b[j][2]};
      invertible = solve(3, c, col);
      for(int i = 0; i < 3; i++) x3[i][j] = col[i];
    }
    if(invertible) {
      double s3[3][3], w[3], v[3][3];
      for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++) {
          s3[i][j] = aw[i][j];
          for(int k = 0; k < 3; k++) s3[i][j] -= b[i][k] * x3[k][j];
        }
      for(int i = 0; i < 3; i++)
        for(int j = 0; j < i; j++) s3[i][j] = s3[j][i] =
            (s3[i][j] + s3[j][i]) / 2.;
      eigen(s3, w, v);
      const double *a = v[0];
      double mo[3], q[3];
      for(int i = 0; i < 3; i++)
        mo[i] = -(x3[i][0] * a[0] + x3[i][1] * a[1] + x3[i][2] * a[2]);
      cross(a, mo, q);
      std::vector<double> rho, h;
      for(std::size_t i : sample) {
        double d[3], e[3];
        for(int k = 0; k < 3; k++) d[k] = y[i][k] - q[k];
        const double z = dot(d, a);
        for(int k = 0; k < 3; k++) e[k] = d[k] - z * a[k];
        rho.push_back(norm(e));
        h.push_back(z);
      }
      double r0, z0, r;
      if(circle(rho, h, r0, z0, r)) {
        std::vector<double> p = {q[0] + z0 * a[0], q[1] + z0 * a[1],
                                 q[2] + z0 * a[2], a[0], a[1], a[2], r0, r};
        minimize(p,
                 [&](const std::vector<double> &pq, std::vector<double> &res) {
                   res.resize(ns + 1);
                   double z;
                   for(std::size_t j = 0; j < ns; j++) {
                     const double d = axial(y[sample[j]], pq, 0, 3, z);
                     res[j] = std::sqrt((d - pq[6]) * (d - pq[6]) + z * z) -
                              pq[7];
                   }
                   gauge(pq, res, ns, false);
                 }, scaledTolerance);
        if(p[7] > 0. && p[6] > p[7]) {
          Analytic s;
          s.type = Analytic::TORUS;
          direction(p, 3, s.axis);
          for(int k = 0; k < 3; k++) s.o[k] = p[k];
          s.r1 = p[6];
          s.r2 = p[7];
          if(accept(s)) return choice();
        }
      }
    }
  }
  return choice();
}

void sheetAngles(const std::vector<std::array<double, 3> > &x,
                 const std::vector<std::array<int, 3> > &triangles,
                 const std::vector<std::array<int, 4> > &edges, double lower,
                 std::vector<double> &angles, std::vector<double> &raw)
{
  angles.assign(edges.size(), 0.);
  auto unit = [&](int t, double n[3]) {
    const std::array<double, 3> &a = x[triangles[t][0]], &b = x[triangles[t][1]],
                                &c = x[triangles[t][2]];
    double u[3], v[3];
    for(int k = 0; k < 3; k++) {
      u[k] = b[k] - a[k];
      v[k] = c[k] - a[k];
    }
    cross(u, v, n);
    return normalize(n);
  };
  auto between = [](const double m[3], const double n[3]) {
    return std::acos(std::max(-1., std::min(1., dot(m, n))));
  };
  // the angles between the triangles, and the edges of each triangle (the
  // other ones cannot be crossed)
  std::map<std::pair<int, int>, std::size_t> edgeOf;
  for(std::size_t i = 0; i < edges.size(); i++) {
    edgeOf[std::minmax(edges[i][0], edges[i][1])] = i;
    double n[2][3];
    if(unit(edges[i][2], n[0]) && unit(edges[i][3], n[1]))
      angles[i] = between(n[0], n[1]);
  }
  raw = angles;
  for(std::size_t i = 0; i < edges.size(); i++) {
    const int a = edges[i][0], b = edges[i][1], t[2] = {edges[i][2], edges[i][3]};
    double n[2][3];
    if(raw[i] < lower || !unit(t[0], n[0]) || !unit(t[1], n[1])) continue;
    // the axis of the edge, its middle, and the directions of the two
    // triangles around it
    double e[3], m[3], side[2][3];
    for(int k = 0; k < 3; k++) {
      e[k] = x[b][k] - x[a][k];
      m[k] = (x[a][k] + x[b][k]) / 2.;
    }
    if(!normalize(e)) continue;
    for(int s = 0; s < 2; s++) {
      int c = triangles[t[s]][0];
      for(int k = 1; k < 3 && (c == a || c == b); k++) c = triangles[t[s]][k];
      double w[3];
      for(int k = 0; k < 3; k++) w[k] = x[c][k] - m[k];
      const double h = dot(w, e);
      for(int k = 0; k < 3; k++) side[s][k] = w[k] - h * e[k];
      normalize(side[s]);
    }
    // the nodes on each side (around the axis; those near the axis, on the
    // extension of the edge, on none), in the frame of the triangle of the
    // side: the normal at the middle of the edge of the quadric (or the
    // plane) fitted to them, with the nodes of the edge
    double normal[2][3];
    bool fitted = true;
    for(int s = 0; s < 2 && fitted; s++) {
      double f0[3], f1[3];
      for(int k = 0; k < 3; k++) f0[k] = e[k];
      cross(n[s], f0, f1);
      // (the nodes of the triangles within three steps of the triangle of the
      // side across edges not sharper than this one)
      std::set<int> ring = {a, b};
      std::map<int, int> depth = {{t[s], 0}};
      std::vector<int> queue = {t[s]};
      for(std::size_t q = 0; q < queue.size(); q++) {
        const int u = queue[q];
        for(int k = 0; k < 3; k++) ring.insert(triangles[u][k]);
        if(depth[u] == 3) continue;
        for(int k = 0; k < 3; k++) {
          auto it = edgeOf.find(
            std::minmax(triangles[u][k], triangles[u][(k + 1) % 3]));
          if(it == edgeOf.end() || it->second == i ||
             raw[it->second] > 1.1 * raw[i])
            continue;
          const int w = edges[it->second][2] == u ? edges[it->second][3] :
                                                     edges[it->second][2];
          if(depth.insert({w, depth[u] + 1}).second) queue.push_back(w);
        }
      }
      std::vector<std::array<double, 3> > local;
      for(int v : ring) {
        double w[3];
        for(int k = 0; k < 3; k++) w[k] = x[v][k] - m[k];
        if(v != a && v != b) {
          const double h = dot(w, e);
          double r[3];
          for(int k = 0; k < 3; k++) r[k] = w[k] - h * e[k];
          const double l = norm(r);
          if(l < 0.2 * norm(w)) continue;
          if((dot(r, side[s]) < dot(r, side[1 - s]))) continue;
        }
        local.push_back({{dot(w, f0), dot(w, f1), dot(w, n[s])}});
      }
      // (in units of the length of the edge; the quadratic terms regularized:
      // those the nodes do not determine, as along the edge for nodes on two
      // lines, vanish)
      if(local.size() < 4) {
        fitted = false;
        break;
      }
      double length = 0.;
      for(int k = 0; k < 3; k++)
        length += (x[b][k] - x[a][k]) * (x[b][k] - x[a][k]);
      length = std::sqrt(length);
      std::vector<double> ata(36, 0.), sol(6, 0.);
      for(auto &p : local) {
        const double u = p[0] / length, v = p[1] / length, w = p[2] / length;
        const double row[6] = {1., u, v, u * u, u * v, v * v};
        for(int j = 0; j < 6; j++) {
          sol[j] += row[j] * w;
          for(int k = 0; k < 6; k++) ata[j * 6 + k] += row[j] * row[k];
        }
      }
      double quadratic = 0.;
      for(int j = 3; j < 6; j++) quadratic += ata[j * 6 + j] / 3.;
      for(int j = 3; j < 6; j++) ata[j * 6 + j] += 1.e-3 * quadratic + 1.e-12;
      if(!solve(6, ata, sol)) {
        fitted = false;
        break;
      }
      for(int k = 0; k < 3; k++)
        normal[s][k] = -sol[1] * f0[k] - sol[2] * f1[k] + n[s][k];
      normalize(normal[s]);
    }
    if(fitted) angles[i] = std::min(raw[i], between(normal[0], normal[1]));
  }
}

double coordinatePrecision(const std::vector<std::array<double, 3> > &x)
{
  // the decimals and significant digits of the coordinates, if they all have
  // a finite decimal expansion
  bool single = true, decimal = true;
  std::vector<std::pair<int, int> > counts; // decimals, significant digits
  for(auto &p : x)
    for(double v : p) {
      if(v == 0.) continue;
      if((double)(float)v != v) single = false;
      if(!decimal) continue;
      int d = 0;
      double t = v;
      while(std::abs(t - std::round(t)) > 1.e-14 * std::max(1., std::abs(t))) {
        t *= 10.;
        if(++d > 17 || std::abs(t) >= 1.e15) break;
      }
      if(d > 17 || std::abs(t) >= 1.e15) {
        decimal = false;
        continue;
      }
      counts.push_back({d, d + (int)std::floor(std::log10(std::abs(v))) + 1});
    }
  // written with few decimals or significant digits (as text): most of them
  // have that many (exact values, as products of short decimals, have various
  // numbers of decimals, some large); or else single or double precision
  // floats
  int decimals = 0, digits = 0;
  for(auto &c : counts) {
    decimals = std::max(decimals, c.first);
    digits = std::max(digits, c.second);
  }
  std::size_t withDecimals = 0, withDigits = 0;
  for(auto &c : counts) {
    if(c.first == decimals) withDecimals++;
    if(c.second == digits) withDigits++;
  }
  const bool fixed = decimal && decimals <= 9 && 2 * withDecimals >= counts.size();
  const bool significant =
    decimal && digits <= 9 && 2 * withDigits >= counts.size();
  double q = 0.;
  for(auto &p : x)
    for(double v : p) {
      if(v == 0.) continue;
      double qv = std::abs(v) * (single ? std::ldexp(1., -24) : std::ldexp(1., -53));
      double r = 1e300;
      if(fixed) r = std::pow(10., -decimals);
      if(significant)
        r = std::min(r, std::pow(10., std::floor(std::log10(std::abs(v))) + 1 -
                                        digits));
      if(fixed || significant) qv = std::max(qv, r / 2.);
      q = std::max(q, qv);
    }
  return std::sqrt(3.) * q;
}

void segmentSurface(const std::vector<std::array<double, 3> > &x,
                    const std::vector<std::array<int, 3> > &triangles,
                    const std::vector<std::vector<int> > &neighbors,
                    double tolerance, double precision, double angle,
                    std::vector<int> &piece,
                    std::vector<DiscreteCADAnalyticSurface> &surfaces)
{
  typedef DiscreteCADAnalyticSurface Analytic;
  const std::size_t n = x.size(), nt = triangles.size();
  piece.assign(nt, -1);
  surfaces.clear();
  if(!nt) return;
  double lo[3] = {1e300, 1e300, 1e300}, hi[3] = {-1e300, -1e300, -1e300};
  for(auto &p : x)
    for(int k = 0; k < 3; k++) {
      lo[k] = std::min(lo[k], p[k]);
      hi[k] = std::max(hi[k], p[k]);
    }
  double size = 0.;
  for(int k = 0; k < 3; k++) size += (hi[k] - lo[k]) * (hi[k] - lo[k]);
  // the regions are on analytic surfaces up to the precision of the
  // coordinates
  const double tau =
    std::min(tolerance, 2. * precision + 1.e-12 * std::sqrt(size));
  const double cosAngle = std::cos(angle);
  // the unit normals, areas and centroids of the triangles
  std::vector<std::array<double, 3> > normal(nt), centroid(nt);
  std::vector<double> area(nt);
  for(std::size_t t = 0; t < nt; t++) {
    const std::array<double, 3> &a = x[triangles[t][0]], &b = x[triangles[t][1]],
                                &c = x[triangles[t][2]];
    double u[3], v[3], w[3];
    for(int k = 0; k < 3; k++) {
      u[k] = b[k] - a[k];
      v[k] = c[k] - a[k];
      centroid[t][k] = (a[k] + b[k] + c[k]) / 3.;
    }
    cross(u, v, w);
    area[t] = norm(w) / 2.;
    if(area[t] > 0.) normalize(w);
    normal[t] = {{w[0], w[1], w[2]}};
  }
  // the analytic surface within tol of the nodes of a set of triangles
  auto fit = [&](const std::vector<int> &set, double tol) {
    std::map<int, int> local;
    std::vector<std::array<double, 3> > lx;
    std::vector<std::array<int, 3> > lt;
    for(int t : set) {
      std::array<int, 3> l;
      for(int k = 0; k < 3; k++) {
        auto it = local.insert({triangles[t][k], (int)lx.size()});
        if(it.second) lx.push_back(x[triangles[t][k]]);
        l[k] = it.first->second;
      }
      lt.push_back(l);
    }
    return recognizeSurface(lx, lt, tol, angle);
  };
  // whether the normal of a triangle makes an angle smaller than angle with
  // that of a surface at its centroid, on the side side (the first one if 0)
  auto agrees = [&](int t, const Analytic &s, int &side) {
    if(!(area[t] > 0.)) return true;
    double sn[3];
    s.normal(centroid[t].data(), sn);
    const double d = dot(sn, normal[t].data());
    if(!(std::abs(d) >= cosAngle)) return false;
    const int sd = d > 0. ? 1 : -1;
    if(side && sd != side) return false;
    side = sd;
    return true;
  };
  auto on = [&](int t, const Analytic &s, double tol, int &side) {
    for(int k = 0; k < 3; k++)
      if(!(std::abs(s.distance(x[triangles[t][k]].data())) <= tol))
        return false;
    return agrees(t, s, side);
  };

  // the regions grown from the seeds
  std::vector<int> stamp(nt, 0), nodeStamp(n, 0), order(nt);
  std::vector<char> tried(nt, 0);
  int current = 0;
  for(std::size_t t = 0; t < nt; t++) order[t] = (int)t;
  std::stable_sort(order.begin(), order.end(),
                   [&](int a, int b) { return area[a] > area[b]; });
  for(int seed : order) {
    if(piece[seed] >= 0 || tried[seed]) continue;
    // the rings around the seed (at least 2 rings, 30 triangles and 16 nodes),
    // fewer if no surface fits them (a small face)
    current++;
    std::vector<int> region = {seed}, best;
    std::vector<std::pair<std::size_t, std::size_t> > rings; // triangles, nodes
    stamp[seed] = current;
    std::size_t nodes = 0, front = 0;
    for(int ring = 0; ring < 10; ring++) {
      for(std::size_t j = front; j < region.size(); j++)
        for(int k = 0; k < 3; k++) {
          int &ns = nodeStamp[triangles[region[j]][k]];
          if(ns != current) {
            ns = current;
            nodes++;
          }
        }
      rings.push_back({region.size(), nodes});
      if(ring >= 2 && region.size() >= 30 && nodes >= 16) break;
      const std::size_t end = region.size();
      for(std::size_t j = front; j < end; j++)
        for(int u : neighbors[region[j]])
          if(piece[u] < 0 && stamp[u] != current) {
            stamp[u] = current;
            region.push_back(u);
          }
      front = end;
      if(region.size() == end) break;
    }
    // (the triangles of the smallest one tested are no other seeds)
    Analytic s;
    std::size_t smallest = 1;
    for(std::size_t r = rings.size(); r-- > 0 && rings[r].second >= 16;) {
      smallest = rings[r].first;
      std::vector<int> seedRegion(region.begin(), region.begin() + smallest);
      s = fit(seedRegion, tau);
      if(s.type == Analytic::NONE) continue;
      best = seedRegion;
      break;
    }
    for(std::size_t j = 0; j < smallest; j++) tried[region[j]] = 1;
    if(best.empty()) continue;
    // the region grown on the surface, refitted as it grows
    current++;
    region = best;
    int side = 0;
    for(int t : region) {
      stamp[t] = current;
      agrees(t, s, side);
    }
    for(int pass = 0; pass < 20; pass++) {
      const std::size_t before = region.size();
      std::vector<int> queue = region;
      while(!queue.empty()) {
        const int t = queue.back();
        queue.pop_back();
        for(int u : neighbors[t]) {
          if(piece[u] >= 0 || stamp[u] == current || !on(u, s, tau, side))
            continue;
          stamp[u] = current;
          region.push_back(u);
          queue.push_back(u);
        }
      }
      if(region.size() == before) break;
      const Analytic r = fit(region, tau);
      if(r.type == Analytic::NONE) break;
      s = r;
    }
    for(int t : region) piece[t] = (int)surfaces.size();
    surfaces.push_back(s);
  }
  if(surfaces.empty()) return;

  // the pieces optimized together (variational shape approximation, with
  // analytic surfaces, Cohen-Steiner et al. 2004, Wu and Kobbelt 2005): the
  // triangles given to the surface of the pieces nearest to their nodes by
  // flooding from the triangle of each piece nearest to its surface (keeping
  // the pieces connected; those within tau of no surface free), then the
  // surfaces fitted to their pieces, until the pieces do not change; then
  // two pieces next to each other on the same surface merged, and so on
  // (the distances of the nodes and of the centroid, which tells the surface
  // of a triangle whose nodes are on two of them, along the curve between
  // them)
  auto error = [&](int t, const Analytic &a) {
    const double d = a.distance(centroid[t].data());
    double e = d * d;
    for(int k = 0; k < 3; k++) {
      const double dk = a.distance(x[triangles[t][k]].data());
      e += dk * dk;
    }
    return e;
  };
  std::vector<int> sideOf;
  auto admissible = [&](int t, int p) {
    for(int k = 0; k < 3; k++)
      if(!(std::abs(surfaces[p].distance(x[triangles[t][k]].data())) <= tau))
        return false;
    int side = sideOf[p];
    return agrees(t, surfaces[p], side);
  };
  auto lloyd = [&]() {
    for(int iteration = 0; iteration < 20; iteration++) {
      const std::size_t np = surfaces.size();
      std::vector<int> seedOf(np, -1);
      std::vector<double> best(np, 1e300);
      for(std::size_t t = 0; t < nt; t++) {
        const int p = piece[t];
        if(p < 0) continue;
        const double e = error((int)t, surfaces[p]);
        if(e < best[p]) {
          best[p] = e;
          seedOf[p] = (int)t;
        }
      }
      sideOf.assign(np, 0);
      std::vector<int> label(nt, -1);
      std::priority_queue<std::pair<double, std::pair<int, int> >,
                          std::vector<std::pair<double, std::pair<int, int> > >,
                          std::greater<std::pair<double, std::pair<int, int> > > >
        queue;
      for(std::size_t p = 0; p < np; p++) {
        if(seedOf[p] < 0) continue;
        agrees(seedOf[p], surfaces[p], sideOf[p]);
        label[seedOf[p]] = (int)p;
        for(int u : neighbors[seedOf[p]])
          if(label[u] < 0 && admissible(u, (int)p))
            queue.push({error(u, surfaces[p]), {u, (int)p}});
      }
      while(!queue.empty()) {
        const int t = queue.top().second.first, p = queue.top().second.second;
        queue.pop();
        if(label[t] >= 0) continue;
        label[t] = p;
        for(int u : neighbors[t])
          if(label[u] < 0 && admissible(u, p))
            queue.push({error(u, surfaces[p]), {u, p}});
      }
      // the surfaces of the pieces that changed fitted to them
      std::vector<char> changed(np, 0);
      bool any = false;
      for(std::size_t t = 0; t < nt; t++) {
        if(label[t] == piece[t]) continue;
        any = true;
        if(label[t] >= 0) changed[label[t]] = 1;
        if(piece[t] >= 0) changed[piece[t]] = 1;
      }
      piece = label;
      if(!any) break;
      std::vector<std::vector<int> > members(np);
      for(std::size_t t = 0; t < nt; t++)
        if(piece[t] >= 0) members[piece[t]].push_back((int)t);
      for(std::size_t p = 0; p < np; p++) {
        if(!changed[p] || members[p].empty()) continue;
        const Analytic r = fit(members[p], tau);
        if(r.type != Analytic::NONE) surfaces[p] = r;
      }
    }
  };
  lloyd();
  for(bool merged = true; merged;) {
    merged = false;
    std::set<std::pair<int, int> > pairs;
    for(std::size_t t = 0; t < nt; t++)
      for(int u : neighbors[t])
        if(piece[t] >= 0 && piece[u] >= 0 && piece[t] != piece[u])
          pairs.insert(std::minmax(piece[t], piece[u]));
    for(auto &pq : pairs) {
      std::vector<int> both;
      for(std::size_t t = 0; t < nt; t++)
        if(piece[t] == pq.first || piece[t] == pq.second) both.push_back((int)t);
      const Analytic r = fit(both, tau);
      if(r.type == Analytic::NONE) continue;
      for(int t : both) piece[t] = pq.first;
      surfaces[pq.first] = r;
      merged = true;
      break;
    }
    if(merged) lloyd();
  }
  // (the pieces left empty removed)
  {
    std::vector<int> renumber(surfaces.size(), -1);
    std::vector<Analytic> kept;
    for(std::size_t t = 0; t < nt; t++) {
      const int p = piece[t];
      if(p < 0) continue;
      if(renumber[p] < 0) {
        renumber[p] = (int)kept.size();
        kept.push_back(surfaces[p]);
      }
      piece[t] = renumber[p];
    }
    surfaces = kept;
  }

  // the components of free triangles all along pieces added to them
  std::vector<char> seen(nt, 0);
  for(std::size_t t0 = 0; t0 < nt; t0++) {
    if(piece[t0] >= 0 || seen[t0]) continue;
    std::vector<int> component = {(int)t0};
    seen[t0] = 1;
    bool band = true;
    for(std::size_t j = 0; j < component.size(); j++) {
      bool along = false;
      for(int u : neighbors[component[j]]) {
        if(piece[u] >= 0) along = true;
        else if(!seen[u]) {
          seen[u] = 1;
          component.push_back(u);
        }
      }
      if(!along) band = false;
    }
    if(!band) continue;
    std::vector<int> joined(component.size(), -1);
    for(std::size_t j = 0; j < component.size(); j++) {
      const int t = component[j];
      double nearest = 1e300;
      for(int u : neighbors[t]) {
        const int p = piece[u];
        if(p < 0) continue;
        const double d = std::abs(surfaces[p].distance(centroid[t].data()));
        if(d < nearest) {
          nearest = d;
          joined[j] = p;
        }
      }
    }
    for(std::size_t j = 0; j < component.size(); j++)
      piece[component[j]] = joined[j];
  }
}

void analyticParameters(const DiscreteCADAnalyticSurface &s,
                        const std::vector<std::array<double, 3> > &x,
                        const std::vector<std::array<int, 3> > &triangles,
                        double tolerance,
                        std::vector<std::array<std::array<double, 2>, 3> > &uv,
                        std::vector<int> &half, int &apex,
                        std::vector<DiscreteCADAnalyticMap> &maps)
{
  typedef DiscreteCADAnalyticSurface Analytic;
  typedef DiscreteCADAnalyticMap Map;
  const std::size_t n = x.size(), nt = triangles.size();
  uv.assign(nt, std::array<std::array<double, 2>, 3>());
  half.assign(nt, 0);
  apex = -1;
  double e0[3], e1[3];
  frame(s.axis, e0, e1);
  maps.assign(1, Map());
  maps[0].surface = s;
  for(int k = 0; k < 3; k++) {
    maps[0].e0[k] = e0[k];
    maps[0].e1[k] = e1[k];
  }
  // the coordinates of the nodes in the frame (e0, e1, axis) from the origin
  // of the surface, and their angle around the axis
  std::vector<std::array<double, 3> > c(n);
  std::vector<double> theta(n);
  for(std::size_t i = 0; i < n; i++) {
    double d[3];
    for(int k = 0; k < 3; k++) d[k] = x[i][k] - s.o[k];
    c[i] = {{dot(d, e0), dot(d, e1), dot(d, s.axis)}};
    theta[i] = std::atan2(c[i][1], c[i][0]);
  }
  // the angles of the corners of a triangle within pi of the first one (of
  // those away from the axis)
  auto unwrapped = [&](std::size_t t, double a[3]) {
    int first = -1;
    for(int k = 0; k < 3; k++) {
      const std::array<double, 3> &p = c[triangles[t][k]];
      if(first < 0 && (p[0] != 0. || p[1] != 0.)) first = k;
    }
    for(int k = 0; k < 3; k++) {
      a[k] = theta[triangles[t][k]];
      if(first >= 0)
        a[k] += 2. * pi * std::round((a[first] - a[k]) / (2. * pi));
    }
    // a node on the axis: the mean angle of the others
    for(int k = 0; k < 3; k++) {
      const std::array<double, 3> &p = c[triangles[t][k]];
      if(p[0] != 0. || p[1] != 0. || first < 0) continue;
      double sum = 0.;
      int count = 0;
      for(int l = 0; l < 3; l++) {
        const std::array<double, 3> &q = c[triangles[t][l]];
        if(q[0] == 0. && q[1] == 0.) continue;
        sum += a[l];
        count++;
      }
      a[k] = sum / count;
    }
  };
  // the angles of the corners of the triangles around the axis, continuous
  // across their edges, except along a cut if the surface goes around the
  // axis: the shortest path along the edges between two of its boundaries
  // that go around it (its seam, along a generatrix if the nodes allow it)
  auto aroundAxis = [&]() {
    auto wrap = [](double d) { return d - 2. * pi * std::round(d / (2. * pi)); };
    std::map<std::pair<int, int>, std::vector<int> > edges;
    for(std::size_t t = 0; t < nt; t++)
      for(int k = 0; k < 3; k++)
        edges[std::minmax(triangles[t][k], triangles[t][(k + 1) % 3])]
          .push_back((int)t);
    std::map<int, std::vector<int> > boundary, adjacent;
    for(auto &e : edges) {
      adjacent[e.first.first].push_back(e.first.second);
      adjacent[e.first.second].push_back(e.first.first);
      if(e.second.size() != 1) continue;
      boundary[e.first.first].push_back(e.first.second);
      boundary[e.first.second].push_back(e.first.first);
    }
    std::vector<std::vector<int> > around;
    std::set<int> seen;
    for(auto &b : boundary) {
      if(seen.count(b.first) || b.second.size() != 2) continue;
      std::vector<int> loop = {b.first};
      seen.insert(b.first);
      int previous = b.first, current = b.second[0];
      double turns = 0.;
      bool simple = true;
      while(current != b.first) {
        turns += wrap(theta[current] - theta[previous]);
        if(seen.count(current) || boundary[current].size() != 2) {
          simple = false;
          break;
        }
        seen.insert(current);
        loop.push_back(current);
        const std::vector<int> &nb = boundary[current];
        const int following = nb[0] == previous ? nb[1] : nb[0];
        previous = current;
        current = following;
      }
      if(!simple) continue;
      turns += wrap(theta[b.first] - theta[previous]);
      if(std::abs(turns) > pi) around.push_back(loop);
    }
    std::set<std::pair<int, int> > cut;
    if(around.size() >= 2) {
      std::vector<double> distance(n, 1e300);
      std::vector<int> from(n, -1);
      std::priority_queue<std::pair<double, int>,
                          std::vector<std::pair<double, int> >,
                          std::greater<std::pair<double, int> > >
        queue;
      for(int v : around[0]) {
        distance[v] = 0.;
        queue.push({0., v});
      }
      const std::set<int> target(around[1].begin(), around[1].end());
      int reached = -1;
      while(!queue.empty()) {
        const std::pair<double, int> top = queue.top();
        queue.pop();
        const int v = top.second;
        if(top.first > distance[v]) continue;
        if(target.count(v)) {
          reached = v;
          break;
        }
        for(int w : adjacent[v]) {
          double l = 0.;
          for(int k = 0; k < 3; k++) l += (x[w][k] - x[v][k]) * (x[w][k] - x[v][k]);
          const double d = top.first + std::sqrt(l);
          if(d < distance[w]) {
            distance[w] = d;
            from[w] = v;
            queue.push({d, w});
          }
        }
      }
      for(int v = reached; v >= 0 && from[v] >= 0; v = from[v])
        cut.insert(std::minmax(v, from[v]));
    }
    std::vector<std::array<double, 3> > angle(nt);
    std::vector<char> done(nt, 0);
    for(std::size_t t0 = 0; t0 < nt; t0++) {
      if(done[t0]) continue;
      unwrapped(t0, angle[t0].data());
      done[t0] = 1;
      std::vector<int> stack = {(int)t0};
      while(!stack.empty()) {
        const int t = stack.back();
        stack.pop_back();
        for(int k = 0; k < 3; k++) {
          const int p = triangles[t][k], q = triangles[t][(k + 1) % 3];
          const std::pair<int, int> key = std::minmax(p, q);
          if(cut.count(key)) continue;
          for(int u : edges[key]) {
            if(done[u]) continue;
            for(int l = 0; l < 3; l++) {
              const int v = triangles[u][l];
              if(v == p)
                angle[u][l] = angle[t][k];
              else if(v == q)
                angle[u][l] = angle[t][(k + 1) % 3];
              else
                angle[u][l] = angle[t][k] + wrap(theta[v] - angle[t][k]);
            }
            done[u] = 1;
            stack.push_back(u);
          }
        }
      }
    }
    return angle;
  };

  switch(s.type) {
  case Analytic::PLANE:
    maps[0].kind = Map::PLANE;
    for(std::size_t t = 0; t < nt; t++)
      for(int k = 0; k < 3; k++) {
        const std::array<double, 3> &p = c[triangles[t][k]];
        uv[t][k] = {{p[0], p[1]}};
      }
    break;
  case Analytic::CYLINDER: {
    maps[0].kind = Map::DEVELOPED;
    const std::vector<std::array<double, 3> > angle = aroundAxis();
    for(std::size_t t = 0; t < nt; t++)
      for(int k = 0; k < 3; k++)
        uv[t][k] = {{s.r1 * angle[t][k], c[triangles[t][k]][2]}};
  } break;
  case Analytic::CONE: {
    double smax = 0., nearest = 1e300;
    std::vector<double> dist(n);
    for(std::size_t i = 0; i < n; i++) {
      dist[i] = std::sqrt(c[i][0] * c[i][0] + c[i][1] * c[i][1] +
                          c[i][2] * c[i][2]);
      smax = std::max(smax, dist[i]);
      if(dist[i] < nearest) {
        nearest = dist[i];
        apex = (int)i;
      }
    }
    if(nearest > tolerance) apex = -1;
    const double sinHalf = std::sin(s.r1);
    maps[0].kind = apex >= 0 ? Map::DISK : Map::DEVELOPED;
    maps[0].scale = smax;
    std::vector<std::array<double, 3> > angle;
    if(apex < 0) angle = aroundAxis();
    for(std::size_t t = 0; t < nt; t++) {
      double a[3];
      if(apex >= 0)
        unwrapped(t, a);
      else
        for(int k = 0; k < 3; k++) a[k] = angle[t][k];
      for(int k = 0; k < 3; k++) {
        const int i = triangles[t][k];
        if(apex >= 0) {
          const double r = i == apex ? 0. : dist[i] / smax;
          uv[t][k] = {{r * std::cos(a[k]), r * std::sin(a[k])}};
        }
        else
          uv[t][k] = {{dist[i] * std::cos(a[k] * sinHalf),
                       dist[i] * std::sin(a[k] * sinHalf)}};
      }
    }
  } break;
  case Analytic::SPHERE: {
    // the direction of the center of the surface (seen from the center of the
    // sphere), and the halves if it goes beyond 120 degrees from it
    double d[3] = {0., 0., 0.}, total = 0.;
    for(std::size_t t = 0; t < nt; t++) {
      double g[3] = {0., 0., 0.}, u[3], v[3], w[3];
      for(int k = 0; k < 3; k++) {
        for(int l = 0; l < 3; l++) g[l] += (x[triangles[t][k]][l] - s.o[l]) / 3.;
        u[k] = x[triangles[t][1]][k] - x[triangles[t][0]][k];
        v[k] = x[triangles[t][2]][k] - x[triangles[t][0]][k];
      }
      cross(u, v, w);
      const double a = norm(w) / 2.;
      normalize(g);
      total += a;
      for(int k = 0; k < 3; k++) d[k] += a * g[k];
    }
    if(!(norm(d) > 1.e-3 * total) || !normalize(d)) {
      for(int k = 0; k < 3; k++) d[k] = s.axis[k];
    }
    double f0[3], f1[3];
    frame(d, f0, f1);
    bool split = false;
    {
      const Map whole = maps[0];
      maps.assign(2, whole);
    }
    for(int h = 0; h < 2; h++) {
      maps[h].kind = Map::STEREOGRAPHIC;
      maps[h].scale = h ? -1. : 1.;
      for(int k = 0; k < 3; k++) {
        maps[h].d[k] = d[k];
        maps[h].e0[k] = f0[k];
        maps[h].e1[k] = f1[k];
      }
    }
    std::vector<std::array<double, 3> > q(n);
    for(std::size_t i = 0; i < n; i++) {
      for(int k = 0; k < 3; k++) q[i][k] = (x[i][k] - s.o[k]) / s.r1;
      normalize(q[i].data());
      if(dot(q[i].data(), d) < -0.5) split = true;
    }
    for(std::size_t t = 0; t < nt; t++) {
      if(split) {
        double g = 0.;
        for(int k = 0; k < 3; k++) g += dot(q[triangles[t][k]].data(), d);
        half[t] = g < 0. ? 1 : 0;
      }
      // the stereographic projection from -d (+d for the second half)
      const double sign = half[t] ? -1. : 1.;
      for(int k = 0; k < 3; k++) {
        const double *p = q[triangles[t][k]].data();
        const double den = 1. + sign * dot(p, d);
        uv[t][k] = {{dot(p, f0) / den, dot(p, f1) / den}};
      }
    }
  } break;
  case Analytic::TORUS: {
    // the angle phi of the nodes around the section; the angles covered by
    // the triangles (in 5 degree bins); without a gap, the halves on each side
    // of the equatorial plane
    std::vector<double> phi(n);
    for(std::size_t i = 0; i < n; i++)
      phi[i] = std::atan2(c[i][2], std::hypot(c[i][0], c[i][1]) - s.r1);
    const int bins = 72;
    auto bin = [&](double a) {
      int b = (int)std::floor((a + pi) / (2. * pi) * bins);
      return ((b % bins) + bins) % bins;
    };
    auto cornersPhi = [&](std::size_t t, double a[3]) {
      for(int k = 0; k < 3; k++) {
        a[k] = phi[triangles[t][k]];
        a[k] += 2. * pi * std::round((a[0] - a[k]) / (2. * pi));
      }
    };
    // the middle of the largest gap of the angles of a set of triangles, or
    // false if they cover all the angles
    auto gap = [&](int h, double &middle) {
      std::vector<char> covered(bins, 0);
      for(std::size_t t = 0; t < nt; t++) {
        if(half[t] != h) continue;
        double a[3];
        cornersPhi(t, a);
        const double lo = std::min({a[0], a[1], a[2]}),
                     hi = std::max({a[0], a[1], a[2]});
        const int b0 = bin(lo);
        const int count = std::min(bins, (int)std::ceil((hi - lo) /
                                                        (2. * pi) * bins) + 1);
        for(int b = 0; b < count; b++) covered[(b0 + b) % bins] = 1;
      }
      int best = 0, start = -1;
      for(int b = 0; b < 2 * bins; b++) {
        if(covered[b % bins]) continue;
        int e = b;
        while(e < b + bins && !covered[e % bins]) e++;
        if(e - b > best) {
          best = e - b;
          start = b;
        }
        b = e;
      }
      if(best == 0 || best >= bins) return best >= bins;
      middle = -pi + (start + best / 2.) * 2. * pi / bins;
      return true;
    };
    double cut[2] = {0., 0.};
    if(!gap(0, cut[0])) {
      for(std::size_t t = 0; t < nt; t++) {
        double h = 0.;
        for(int k = 0; k < 3; k++) h += c[triangles[t][k]][2];
        half[t] = h < 0. ? 1 : 0;
      }
      cut[0] = -pi / 2.;
      cut[1] = pi / 2.;
    }
    // the conformal coordinate of phi, ds = r2 dphi / (r1 + r2 cos(phi)),
    // continuous for all phi
    const double r1 = s.r1, r2 = s.r2, cc = std::sqrt(r1 * r1 - r2 * r2);
    const double ratio = std::sqrt((r1 - r2) / (r1 + r2));
    auto conformal = [&](double a) {
      return 2. * r2 / cc * std::atan(ratio * std::tan(a / 2.)) +
             2. * pi * r2 / cc * std::floor((a + pi) / (2. * pi));
    };
    // phi after the cut, its conformal coordinate, and its range in each half
    std::vector<std::array<double, 3> > sc(nt);
    double smin[2] = {1e300, 1e300}, smax[2] = {-1e300, -1e300};
    for(std::size_t t = 0; t < nt; t++) {
      const int h = half[t];
      for(int k = 0; k < 3; k++) {
        double a = phi[triangles[t][k]];
        a = cut[h] + std::fmod(std::fmod(a - cut[h], 2. * pi) + 2. * pi,
                               2. * pi);
        sc[t][k] = conformal(a);
        smin[h] = std::min(smin[h], sc[t][k]);
        smax[h] = std::max(smax[h], sc[t][k]);
      }
    }
    // the parameters exp(lambda (s - smin)) (cos(theta), sin(theta)), the
    // range of the radius limited to a factor 4
    {
      const Map whole = maps[0];
      maps.assign(2, whole);
    }
    for(int h = 0; h < 2; h++) {
      const double range = smax[h] - smin[h], maxRange = std::log(4.);
      maps[h].kind = Map::ANNULUS;
      maps[h].scale = range > maxRange ? maxRange / range : 1.;
      maps[h].lowest = smin[h];
      maps[h].cut = cut[h];
    }
    for(std::size_t t = 0; t < nt; t++) {
      const int h = half[t];
      const double range = smax[h] - smin[h], maxRange = std::log(4.);
      const double lambda = range > maxRange ? maxRange / range : 1.;
      for(int k = 0; k < 3; k++) {
        const double r = std::exp(lambda * (sc[t][k] - smin[h]));
        const double a = theta[triangles[t][k]];
        uv[t][k] = {{r * std::cos(a), r * std::sin(a)}};
      }
    }
  } break;
  default: break;
  }
}
