// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <algorithm>
#include <cmath>
#include <functional>
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
  // (Levenberg-Marquardt, the Jacobian by central differences)
  void minimize(std::vector<double> &p, const Residuals &residuals)
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
    for(int it = 0; it < 100; it++) {
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
  // the nodes the fits use (at most about 1000)
  std::vector<std::size_t> sample;
  const std::size_t stride = std::max<std::size_t>(1, n / 1000);
  for(std::size_t i = 0; i < n; i += stride) sample.push_back(i);
  const std::size_t ns = sample.size();

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
        });
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
        res.resize(ns);
        double h;
        for(std::size_t j = 0; j < ns; j++)
          res[j] = axial(y[sample[j]], q, 0, 3, h) - q[6];
      });
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
        res.resize(ns);
        double h;
        for(std::size_t j = 0; j < ns; j++) {
          const double rho = axial(y[sample[j]], q, 0, 3, h);
          res[j] = rho * std::cos(q[6]) - h * std::sin(q[6]);
        }
      });
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
                   res.resize(ns);
                   double z;
                   for(std::size_t j = 0; j < ns; j++) {
                     const double d = axial(y[sample[j]], pq, 0, 3, z);
                     res[j] = std::sqrt((d - pq[6]) * (d - pq[6]) + z * z) -
                              pq[7];
                   }
                 });
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

void analyticParameters(const DiscreteCADAnalyticSurface &s,
                        const std::vector<std::array<double, 3> > &x,
                        const std::vector<std::array<int, 3> > &triangles,
                        double tolerance,
                        std::vector<std::array<std::array<double, 2>, 3> > &uv,
                        std::vector<int> &half, int &apex)
{
  typedef DiscreteCADAnalyticSurface Analytic;
  const std::size_t n = x.size(), nt = triangles.size();
  uv.assign(nt, std::array<std::array<double, 2>, 3>());
  half.assign(nt, 0);
  apex = -1;
  double e0[3], e1[3];
  frame(s.axis, e0, e1);
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

  switch(s.type) {
  case Analytic::PLANE:
    for(std::size_t t = 0; t < nt; t++)
      for(int k = 0; k < 3; k++) {
        const std::array<double, 3> &p = c[triangles[t][k]];
        uv[t][k] = {{p[0], p[1]}};
      }
    break;
  case Analytic::CYLINDER:
    for(std::size_t t = 0; t < nt; t++) {
      double a[3];
      unwrapped(t, a);
      for(int k = 0; k < 3; k++)
        uv[t][k] = {{s.r1 * a[k], c[triangles[t][k]][2]}};
    }
    break;
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
    for(std::size_t t = 0; t < nt; t++) {
      double a[3];
      unwrapped(t, a);
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
