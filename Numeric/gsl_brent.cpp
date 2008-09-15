// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#if defined(HAVE_GSL)

#include "Message.h"
#include "Numeric.h"

#include <gsl/gsl_errno.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_min.h>

static double (*nrfunc) (double);

double fn1(double x, void *params)
{
  double val = nrfunc(x);
  return val;
}

int gsl_min_fminimizer_set_with_values_MOD(gsl_min_fminimizer *s,
                                           gsl_function *f,
                                           double x_minimum, double f_minimum, 
                                           double x_lower, double f_lower,
                                           double x_upper, double f_upper)
{
  s->function = f;
  s->x_minimum = x_minimum;
  s->x_lower = x_lower;
  s->x_upper = x_upper;
  if (x_lower > x_upper)
    {
      GSL_ERROR ("invalid interval (lower > upper)", GSL_EINVAL);
    }
  s->f_lower = f_lower;
  s->f_upper = f_upper;
  s->f_minimum = f_minimum;
  return (s->type->set) (s->state, s->function, 
                         x_minimum, f_minimum, 
                         x_lower, f_lower,
                         x_upper, f_upper);
}

#define MAXITER 100

// Returns the minimum betwen ax and cx to a given tolerance tol using
// brent's method.

double brent(double ax, double bx, double cx,
             double (*f) (double), double tol, double *xmin)
{
  // The solver can stall at the following internal tolerance in brent - so
  // this is about the lowest possible tolerance.
  if(tol == 0.) tol = 10.*GSL_SQRT_DBL_EPSILON;
  const double tolsq = tol*tol;
  int status;
  int iter = 0;
  double a, b, c;               // a < b < c
  double fa, fb, fc;
  const gsl_min_fminimizer_type *T;
  gsl_min_fminimizer *s;
  gsl_function F;

  // gsl wants a<b
  b = bx;
  if(ax < cx) {
    a = ax;
    c = cx;
  }
  else {
    a = cx;
    c = ax;
  }

  nrfunc = f;
  F.function = &fn1;
  F.params = 0;

  fa = f(a);
  fb = f(b);
  fc = f(c);
  if(fb > fa || fb > fc) {
    if(a < c) {
      b = a;
      fb = fa;
    }
    else {
      b = c;
      fb = fc;
    }
  }

  // if a-c < tol, return func(b)
  if(gsl_min_test_interval(a, c, tolsq, tol) == GSL_SUCCESS) {
    *xmin = b;
    return (fb);
  }

  T = gsl_min_fminimizer_brent;
  s = gsl_min_fminimizer_alloc(T);
//   gsl_min_fminimizer_set(s, &F, b, a, c);  // Standard
  // This mod avoids some error checks so we can have a minimum at an extent.
  gsl_min_fminimizer_set_with_values_MOD(s, &F, b, fb, a, fa, c, fc);

  do {
    iter++;
    status = gsl_min_fminimizer_iterate(s);
    if(status)
      break;    // solver problem    
    a = gsl_min_fminimizer_x_lower(s);
    c = gsl_min_fminimizer_x_upper(s);
//     fb = gsl_min_fminimizer_f_minimum(s);
//     fa = gsl_min_fminimizer_f_lower(s);
//     fc = gsl_min_fminimizer_f_upper(s);
    status = gsl_min_test_interval(a, c, tolsq, tol);
    // ... in case curve becomes too flat - not required?
//     std::fabs(fa - fc) < (std::fabs(fb) + tol)*tol
  }
  while(status == GSL_CONTINUE && iter < MAXITER);
  b = gsl_min_fminimizer_x_minimum(s);

  if(status != GSL_SUCCESS)
    Msg::Error("MIN1D not converged: f(%g) = %g", b, fn1(b, NULL));

  *xmin = b;
  gsl_min_fminimizer_free(s);
  return fn1(b, NULL);
}


// Find an initial bracketting of the minimum of func. Given 2 initial
// points ax and bx, mnbrak checks in which direction func decreases,
// and takes some steps in that direction, until the function
// increases--at cx. mnbrak returns ax and cx (possibly switched),
// bracketting a minimum.

#define MYGOLD_  1.618034
#define MYLIMIT_ 100.0
#define MYTINY_  1.0e-20
#define SIGN(a,b)((b) >= 0.0 ? fabs(a) : -fabs(a))

void mnbrak(double *ax, double *bx, double *cx, 
            double *fa_dummy, double *fb_dummy, double *fc_dummy, 
            double (*func) (double))
{
  double ulim, u, r, q;
  volatile double f_a, f_b, f_c, f_u;

  f_a = (*func) (*ax);
  f_b = (*func) (*bx);
  if(f_b > f_a) {
    double tmp;
    tmp = *ax;
    *ax = *bx;
    *bx = tmp;
    tmp = f_b;
    f_b = f_a;
    f_a = tmp;
  }

  *cx = *bx + MYGOLD_ * (*bx - *ax);
  f_c = (*func) (*cx);

  while(f_b > f_c) {
    r = (*bx - *ax) * (f_b - f_c);
    q = (*bx - *cx) * (f_b - f_a);
    u = (*bx) - ((*bx - *cx) * q - (*bx - *ax) * r) / 
      (2.0 * SIGN(std::max(fabs(q - r), MYTINY_), q - r));
    ulim = *bx + MYLIMIT_ * (*cx - *bx);

    if((*bx - u) * (u - *cx) > 0.0) {
      f_u = (*func) (u);
      if(f_u < f_c) {
        *ax = *bx;
        *bx = u;
        return;
      }
      else if(f_u > f_b) {
        *cx = u;
        return;
      }
      u = *cx + MYGOLD_ * (*cx - *bx);
      f_u = (*func) (u);
    }
    else if((*cx - u) * (u - ulim) > 0.0) {
      f_u = (*func) (u);
      if(f_u < f_c) {
        *bx = *cx;
        *cx = u;
        u = *cx + MYGOLD_ * (*cx - *bx);
        f_b = f_c;
        f_c = f_u;
        f_u = (*func) (u);
      }
    }
    else if((u - ulim) * (ulim - *cx) >= 0.0) {
      u = ulim;
      f_u = (*func) (u);
    }
    else {
      u = *cx + MYGOLD_ * (*cx - *bx);
      f_u = (*func) (u);
    }
    *ax = *bx;
    *bx = *cx;
    *cx = u;
    f_a = f_b;
    f_b = f_c;
    f_c = f_u;
  }
}

#endif
