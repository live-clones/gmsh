// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef DUAL_H
#define DUAL_H

#include "OrthogonalPoly.h"

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
inline Dual lobatto(int n, const Dual &x)
{
  return compose(OrthogonalPoly::EvalLobatto(n, x.v),
                 OrthogonalPoly::EvalDLobatto(n, x.v), x);
}
inline Dual kernel(int n, const Dual &x)
{
  return compose(OrthogonalPoly::EvalKernelFunction(n, x.v),
                 OrthogonalPoly::EvalDKernelFunction(n, x.v), x);
}
inline Dual legendre(int n, const Dual &x)
{
  return compose(OrthogonalPoly::EvalLegendre(n, x.v),
                 OrthogonalPoly::EvalDLegendre(n, x.v), x);
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

#endif
