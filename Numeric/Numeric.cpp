// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "GmshMessage.h"
#include "Numeric.h"
#include "GmshMatrix.h"

// This file contains the routines that depend on the GSL, some of
// which need to be reimplemented (e.g. in terms of Gmsh_Matrix)
// before we can get rid of the GSL completely.

#if defined(HAVE_GSL)

#include <gsl/gsl_errno.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_min.h>
#include <gsl/gsl_multimin.h>
#include <gsl/gsl_multiroots.h>
#include <gsl/gsl_linalg.h>

void my_gsl_msg(const char *reason, const char *file, int line,
		int gsl_errno)
{
  Msg::Error("GSL: %s (%s, line %d)", reason, file, line);
}

int Init_Numeric()
{
  // set new error handler
  gsl_set_error_handler(&my_gsl_msg);

  // initilize robust geometric predicates
  gmsh::exactinit() ;
  return 1;
}

#define MAX_DIM_NEWT 10
#define MAXITER 100
#define PREC 1.e-8

static int nrdim;
static double nru[MAX_DIM_NEWT], nrv[MAX_DIM_NEWT];
static void (*nrfunc) (int n, double x[], double y[]);
struct gsl_dummy{ int i; };

static void convert_vector_from_gsl(const gsl_vector * gv, double *v)
{
  int i, m;
  m = gv->size;
  for(i = 0; i < m; i++) {
    v[i + 1] = gsl_vector_get(gv, i);
  }
}

static void convert_vector_to_gsl(double *v, int n, gsl_vector * gv)
{
  int i;
  for(i = 0; i < n; i++) {
    gsl_vector_set(gv, i, v[i + 1]);
  }
}

static int gslfunc(const gsl_vector * xx, void *params, gsl_vector * f)
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

static double (*f_statN) (double*, void *data); 

static void (*df_statN) (double*, double*, double &, void *data);

static double fobjN (const gsl_vector *x, void *data)
{
  return f_statN(x->data, data);
}

static void dfobjN(const gsl_vector *x, void *params, gsl_vector *g)
{
  double f;
  df_statN(x->data, g->data, f, params);
}

static void fdfobjN(const gsl_vector *x, void *params, double *f, gsl_vector *g)
{
  df_statN(x->data, g->data, *f, params);
}

void minimize_N(int N, double (*f)(double*, void *data), 
                void (*df)(double*, double*, double &, void *data),
                void *data, int niter, double *U, double &res)
{
  f_statN = f;
  df_statN = df;

  int iter = 0;
  int status;
  
  const gsl_multimin_fdfminimizer_type *T;
  gsl_multimin_fdfminimizer *s;
  gsl_vector *x;
  gsl_multimin_function_fdf my_func;

  my_func.f = &fobjN;
  my_func.df = &dfobjN;
  my_func.fdf = &fdfobjN;
  my_func.n = N;
  my_func.params = data;

  x = gsl_vector_alloc(N);
  for (int i = 0; i < N; i++)
    gsl_vector_set(x, i, U[i]);

  T = gsl_multimin_fdfminimizer_conjugate_fr;
  s = gsl_multimin_fdfminimizer_alloc(T, N);

  gsl_multimin_fdfminimizer_set(s, &my_func, x, 0.01, 1e-4);

  do{
    iter++;
    status = gsl_multimin_fdfminimizer_iterate(s);
    
    if (status)
      break;
    
    status = gsl_multimin_test_gradient(s->gradient, 1e-3);
  }
  while (status == GSL_CONTINUE && iter < niter);
  
  for (int i = 0; i < N; i++)
    U[i] = gsl_vector_get(s->x, i);
  res = s->f;
  gsl_multimin_fdfminimizer_free(s);
  gsl_vector_free(x);
}                                           

#else

int Init_Numeric()
{
  gmsh::exactinit() ;
  return 1;
}

double brent(double ax, double bx, double cx,
             double (*f) (double), double tol, double *xmin)
{
  Msg::Error("Gmsh must be compiled with GSL support for brent");
}

void newt(double x[], int n, int *check,
          void (*func) (int, double[], double[]))
{
  Msg::Error("Gmsh must be compiled with GSL support for newt");
}

void minimize_N(int N, double (*f) (double*, void *data), 
                void (*df) (double*, double*, double &, void *data) ,
                void *data,int niter,
                double *, double &res)
{
  Msg::Error("Gmsh must be compiled with GSL support for minimize_N");
}

#endif
