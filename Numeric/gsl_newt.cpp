// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributor(s):
//   Nicolas Tardieu
//

// This implements a Newton method using the GSL.

#include "GmshMessage.h"

#if defined(HAVE_GSL)

#include "Numeric.h"

#include <gsl/gsl_math.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_multiroots.h>
#include <gsl/gsl_linalg.h>

#define MAX_DIM_NEWT 10
#define MAXITER 100
#define PREC 1.e-8

int nrdim;
double nru[MAX_DIM_NEWT], nrv[MAX_DIM_NEWT];
static void (*nrfunc) (int n, double x[], double y[]);
struct gsl_dummy{ int i; };

void convert_vector_from_gsl(const gsl_vector * gv, double *v)
{
  int i, m;
  m = gv->size;
  for(i = 0; i < m; i++) {
    v[i + 1] = gsl_vector_get(gv, i);
  }
}

void convert_vector_to_gsl(double *v, int n, gsl_vector * gv)
{
  int i;
  for(i = 0; i < n; i++) {
    gsl_vector_set(gv, i, v[i + 1]);
  }
}

int gslfunc(const gsl_vector * xx, void *params, gsl_vector * f)
{
  convert_vector_from_gsl(xx, nru);
  (*nrfunc) (nrdim, nru, nrv);
  // Msg::Info("f(%lf,%lf) = %lf %lf\n",nru[1],nru[2],nrv[1],nrv[2]);
  convert_vector_to_gsl(nrv, nrdim, f);
  return GSL_SUCCESS;
}

// Warning: for compatibility with the old newt from NR, x[] and the
// arguments of func() are indexed from 1 to n...

void newt(double x[], int n, int *check,
          void (*func) (int, double[], double[]))
{
  const gsl_multiroot_fsolver_type *T;
  gsl_multiroot_fsolver *s;
  int status;
  size_t iter = 0;
  struct gsl_dummy p = { 1 };
  gsl_multiroot_function f = { &gslfunc, n, &p };
  gsl_vector *xx = gsl_vector_alloc(n);

  if(n > MAX_DIM_NEWT - 1)
    Msg::Fatal("Maximum Newton dimension exceeded\n");
  nrdim = n;

  nrfunc = func;
  convert_vector_to_gsl(x, n, xx);

  T = gsl_multiroot_fsolver_hybrid;
  s = gsl_multiroot_fsolver_alloc(T, n);
  gsl_multiroot_fsolver_set(s, &f, xx);

  do {
    iter++;
    status = gsl_multiroot_fsolver_iterate(s);
    // Msg::Info("status %d %d %d %lf %lf\n",
    //     status,n,iter,gsl_vector_get(s->x,0),gsl_vector_get(s->x,1));
     if(status)
       break;    // solver problem
    status = gsl_multiroot_test_residual(s->f, n * PREC);
  }
  while(status == GSL_CONTINUE && iter < MAXITER);

  if(status == GSL_CONTINUE) {
    *check = 1; // problem !!!
  }
  else {
    // Msg::Info("status %d %d %d %lf %lf\n",
    //     status,n,iter,gsl_vector_get(s->x,0),gsl_vector_get(s->x,1));
    convert_vector_from_gsl(s->x, x);
    *check = 0; // converged
  }

  gsl_multiroot_fsolver_free(s);
  gsl_vector_free(xx);
}

#endif
