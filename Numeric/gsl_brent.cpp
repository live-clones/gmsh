// $Id: gsl_brent.cpp,v 1.20 2008-05-04 08:31:16 geuzaine Exp $
//
// Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.

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

#define MAXITER 100

// Returns the minimum betwen ax and cx to a given tolerance tol using
// brent's method.

double brent(double ax, double bx, double cx,
             double (*f) (double), double tol, double *xmin)
{
  int status;
  int iter = 0;
  double a, b, c;               // a < b < c
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
    a = ax;
    c = cx;
  }

  // if a-b < tol, return func(a)
  if(fabs(c - a) < tol) {
    *xmin = ax;
    return (f(*xmin));
  }

  nrfunc = f;

  F.function = &fn1;
  F.params = 0;

  T = gsl_min_fminimizer_brent;
  s = gsl_min_fminimizer_alloc(T);
  gsl_min_fminimizer_set(s, &F, b, a, c);

  do {
    iter++;
    status = gsl_min_fminimizer_iterate(s);
    if(status)
      break;    // solver problem    
    b = gsl_min_fminimizer_minimum(s);
    // this is deprecated: we should use gsl_min_fminimizer_x_minimum(s) instead
    a = gsl_min_fminimizer_x_lower(s);
    c = gsl_min_fminimizer_x_upper(s);
    // we should think about the tolerance more carefully...
    status = gsl_min_test_interval(a, c, tol, tol);
  }
  while(status == GSL_CONTINUE && iter < MAXITER);

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
      (2.0 * SIGN(MAX(fabs(q - r), MYTINY_), q - r));
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
