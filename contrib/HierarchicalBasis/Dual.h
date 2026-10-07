// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef DUAL_H
#define DUAL_H

#include <cmath>

// A "dual number": a scalar with its gradient with respect to the reference
// coordinates (u, v, w). Computing the basis functions with dual numbers gives
// their derivatives at the same time, by the chain rule.
struct Dual {
  double v; // value
  double d[3]; // gradient
  Dual(double value = 0.) : v(value), d{0., 0., 0.} {}
  // the i-th coordinate, equal to value
  static Dual coordinate(int i, double value)
  {
    Dual x(value);
    x.d[i] = 1.;
    return x;
  }
};

inline Dual operator+(const Dual &a, const Dual &b)
{
  Dual r(a.v + b.v);
  for(int i = 0; i < 3; i++) r.d[i] = a.d[i] + b.d[i];
  return r;
}
inline Dual operator-(const Dual &a, const Dual &b)
{
  Dual r(a.v - b.v);
  for(int i = 0; i < 3; i++) r.d[i] = a.d[i] - b.d[i];
  return r;
}
inline Dual operator-(const Dual &a)
{
  Dual r(-a.v);
  for(int i = 0; i < 3; i++) r.d[i] = -a.d[i];
  return r;
}
inline Dual operator*(const Dual &a, const Dual &b)
{
  Dual r(a.v * b.v);
  for(int i = 0; i < 3; i++) r.d[i] = a.d[i] * b.v + a.v * b.d[i];
  return r;
}
inline Dual operator*(double s, const Dual &a)
{
  Dual r(s * a.v);
  for(int i = 0; i < 3; i++) r.d[i] = s * a.d[i];
  return r;
}
inline Dual operator*(const Dual &a, double s) { return s * a; }
inline Dual operator+(const Dual &a, double s) { return a + Dual(s); }
inline Dual operator+(double s, const Dual &a) { return Dual(s) + a; }
inline Dual operator-(const Dual &a, double s) { return a - Dual(s); }
inline Dual operator-(double s, const Dual &a) { return Dual(s) - a; }

// f(x), given f(x.v) and f'(x.v)
inline Dual compose(double f, double df, const Dual &x)
{
  Dual r(f);
  for(int i = 0; i < 3; i++) r.d[i] = df * x.d[i];
  return r;
}
// The Legendre polynomials L_k(x) of degrees k = n, n - 1, n - 2 (zero for
// negative degrees), and the first two derivatives of L_n, by Bonnet's
// recurrence k L_k = (2k - 1) x L_k-1 - (k - 1) L_k-2, with L'_k = L'_k-2 +
// (2k - 1) L_k-1 and L''_k = L''_k-2 + (2k - 1) L'_k-1
struct Legendre {
  double L[3] = {1., 0., 0.}, dL = 0., d2L = 0.;
  Legendre(int n, double x)
  {
    double dl[2] = {0., 0.}, d2l[2] = {0., 0.}; // degrees k - 1, k - 2
    for(int k = 1; k <= n; k++) {
      double l = ((2. * k - 1.) * x * L[0] - (k - 1.) * L[1]) / k;
      double d = dl[1] + (2. * k - 1.) * L[0];
      double d2 = d2l[1] + (2. * k - 1.) * dl[0];
      L[2] = L[1];
      L[1] = L[0];
      L[0] = l;
      dl[1] = dl[0];
      dl[0] = d;
      d2l[1] = d2l[0];
      d2l[0] = d2;
    }
    dL = dl[0];
    d2L = d2l[0];
  }
};

// The Legendre polynomial L_n
inline Dual legendre(int n, const Dual &x)
{
  Legendre p(n, x.v);
  return compose(p.L[0], p.dL, x);
}

// The Lobatto polynomial l_n: (1 - x) / 2, (1 + x) / 2, then
// (L_n - L_n-2) / sqrt(2 (2n - 1)), of derivative sqrt((2n - 1) / 2) L_n-1
inline Dual lobatto(int n, const Dual &x)
{
  if(n == 0) return compose(0.5 * (1. - x.v), -0.5, x);
  if(n == 1) return compose(0.5 * (1. + x.v), 0.5, x);
  Legendre p(n, x.v);
  return compose((p.L[0] - p.L[2]) / std::sqrt(2. * (2. * n - 1.)),
                 std::sqrt((2. * n - 1.) / 2.) * p.L[1], x);
}

// The kernel function K_n = l_n+2 / (l_0 l_1), i.e.
// -4 sqrt((2n + 3) / 2) L'_n+1 / ((n + 1) (n + 2))
inline Dual kernel(int n, const Dual &x)
{
  Legendre p(n + 1, x.v);
  double c = -4. * std::sqrt((2. * n + 3.) / 2.) / ((n + 1.) * (n + 2.));
  return compose(c * p.dL, c * p.d2L, x);
}

// A vector field whose components are dual numbers, which gives its curl and
// its divergence.
struct Vec {
  Dual c[3];
  Vec() {}
  Vec(const Dual &x, const Dual &y, const Dual &z) : c{x, y, z} {}
  double curl(int i) const
  {
    int j = (i + 1) % 3, k = (i + 2) % 3;
    return c[k].d[j] - c[j].d[k];
  }
  double div() const { return c[0].d[0] + c[1].d[1] + c[2].d[2]; }
};

inline Vec operator+(const Vec &a, const Vec &b)
{ return Vec(a.c[0] + b.c[0], a.c[1] + b.c[1], a.c[2] + b.c[2]); }
inline Vec operator-(const Vec &a, const Vec &b)
{ return Vec(a.c[0] - b.c[0], a.c[1] - b.c[1], a.c[2] - b.c[2]); }
inline Vec operator*(const Dual &a, const Vec &b)
{ return Vec(a * b.c[0], a * b.c[1], a * b.c[2]); }
inline Vec operator*(double s, const Vec &b)
{ return Vec(s * b.c[0], s * b.c[1], s * b.c[2]); }

// The gradient of a, and its rotation (d/dv, -d/du, 0) in the plane, as
// vector fields. Their second derivatives are dropped: this keeps the curl of
// f * grad(g) and the divergence of f * rot(g) exact, since the Hessian of g
// is symmetric, but not the divergence of the former or the curl of the
// latter, which the H(curl) and H(div) spaces do not need.
inline Vec grad(const Dual &a)
{ return Vec(Dual(a.d[0]), Dual(a.d[1]), Dual(a.d[2])); }
inline Vec rot(const Dual &a)
{ return Vec(Dual(a.d[1]), Dual(-a.d[0]), Dual(0.)); }

// The rotation (v_y, -v_x, 0) of a vector field in the plane, which maps
// H(curl) to H(div) functions in 2D
inline Vec rotate(const Vec &v) { return Vec(v.c[1], -v.c[0], Dual(0.)); }

#endif
