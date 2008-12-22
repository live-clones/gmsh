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

int check_gsl()
{
  // set new error handler
  gsl_set_error_handler(&my_gsl_msg);

  // initilize robust geometric predicates
  gmsh::exactinit() ;
  return 1;
}

static double (*nrfuncbrent) (double);

static double fn1(double x, void *params)
{
  double val = nrfuncbrent(x);
  return val;
}

static int gsl_min_fminimizer_set_with_values_MOD(gsl_min_fminimizer *s,
                                                  gsl_function *f,
                                                  double x_minimum, double f_minimum, 
                                                  double x_lower, double f_lower,
                                                  double x_upper, double f_upper)
{
  s->function = f;
  s->x_minimum = x_minimum;
  s->x_lower = x_lower;
  s->x_upper = x_upper;
  if (x_lower > x_upper){
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

// Returns the minimum betwen ax and cx to a given tolerance tol using
// brent's method.
double brent(double ax, double bx, double cx,
             double (*f) (double), double tol, double *xmin)
{
#define MAXITER 100
  // The solver can stall at the following internal tolerance in brent - so
  // this is about the lowest possible tolerance.
  if(tol == 0.) tol = 10. * GSL_SQRT_DBL_EPSILON;
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

  nrfuncbrent = f;
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
  // gsl_min_fminimizer_set(s, &F, b, a, c);  // Standard
  // This mod avoids some error checks so we can have a minimum at an extent.
  gsl_min_fminimizer_set_with_values_MOD(s, &F, b, fb, a, fa, c, fc);

  do {
    iter++;
    status = gsl_min_fminimizer_iterate(s);
    if(status)
      break;    // solver problem    
    a = gsl_min_fminimizer_x_lower(s);
    c = gsl_min_fminimizer_x_upper(s);
    // fb = gsl_min_fminimizer_f_minimum(s);
    // fa = gsl_min_fminimizer_f_lower(s);
    // fc = gsl_min_fminimizer_f_upper(s);
    status = gsl_min_test_interval(a, c, tolsq, tol);
    // ... in case curve becomes too flat - not required?
    // std::fabs(fa - fc) < (std::fabs(fb) + tol)*tol
  }
  while(status == GSL_CONTINUE && iter < MAXITER);
  b = gsl_min_fminimizer_x_minimum(s);

  if(status != GSL_SUCCESS)
    Msg::Error("minimization did not converge: f(%g) = %g", b, fn1(b, NULL));
  
  *xmin = b;
  gsl_min_fminimizer_free(s);
  return fn1(b, NULL);
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

static double (*f_stat) (double, double, void *data); 
static void (*df_stat) (double, double, double &, double &, double &, void *data);
static double (*f_stat3) (double, double, double, void *data); 
static void (*df_stat3) (double, double, double, double &, double &, 
                         double &, double &,void *data);
static double (*f_statN) (double*, void *data); 
static void (*df_statN) (double*, double *, double &,void *data);

static double fobj(const gsl_vector * x, void * data)
{
  double u, v;
  u = gsl_vector_get(x, 0);
  v = gsl_vector_get(x, 1);
  return f_stat(u, v, data);
}

static double fobj3(const gsl_vector * x, void * data)
{
  double u, v,w;
  u = gsl_vector_get(x, 0);
  v = gsl_vector_get(x, 1);
  w = gsl_vector_get(x, 2);
  return f_stat3(u, v, w, data);
}

static double fobjN (const gsl_vector * x, void * data)
{
  return f_statN(x->data, data);
}

static void dfobj (const gsl_vector * x, void * params, gsl_vector * g)
{
  double u, v, f, duf, dvf;
  u = gsl_vector_get(x, 0);
  v = gsl_vector_get(x, 1);
  df_stat(u, v, f, duf, dvf, params);
  gsl_vector_set(g, 0, duf);
  gsl_vector_set(g, 1, dvf);
}

static void dfobj3 (const gsl_vector * x, void * params, gsl_vector * g)
{
  double u, v, w,f, duf, dvf,dwf;
  u = gsl_vector_get(x, 0);
  v = gsl_vector_get(x, 1);
  w = gsl_vector_get(x, 2);
  df_stat3(u, v, w, f, duf, dvf, dwf, params);
  gsl_vector_set(g, 0, duf);
  gsl_vector_set(g, 1, dvf);
  gsl_vector_set(g, 2, dwf);
}

static void dfobjN(const gsl_vector * x, void * params, gsl_vector * g)
{
  double f;
  df_statN(x->data, g->data,f,params);
}

static void fdfobj(const gsl_vector * x, void * params, double * f, gsl_vector * g)
{
  double u, v, duf, dvf;
  u = gsl_vector_get(x, 0);
  v = gsl_vector_get(x, 1);
  df_stat(u, v, *f, duf, dvf, params);
  gsl_vector_set(g, 0, duf);
  gsl_vector_set(g, 1, dvf);
}

static void fdfobj3(const gsl_vector * x, void * params, double * f, gsl_vector * g)
{
  double u, v, w,duf, dvf,dwf;
  u = gsl_vector_get(x, 0);
  v = gsl_vector_get(x, 1);
  w = gsl_vector_get(x, 2);
  df_stat3(u, v, w, *f, duf, dvf, dwf, params);
  gsl_vector_set(g, 0, duf);
  gsl_vector_set(g, 1, dvf);
  gsl_vector_set(g, 2, dwf);
}

static void fdfobjN(const gsl_vector * x, void * params, double * f, gsl_vector * g)
{
  df_statN(x->data,g->data,*f,params);
}

void minimize_2(double (*f) (double, double, void *data), 
                void (*df) (double, double, double &, double &, double &, void *data) ,
                void *data,int niter,
                double &U, double &V, double &res)
{
  f_stat = f;
  df_stat = df;

  int iter = 0;
  int status;
  
  const gsl_multimin_fdfminimizer_type *T;
  gsl_multimin_fdfminimizer *s;
  gsl_vector *x;
  gsl_multimin_function_fdf my_func;

  my_func.f = &fobj;
  my_func.df = &dfobj;
  my_func.fdf = &fdfobj;
  my_func.n = 2;
  my_func.params = data;

  x = gsl_vector_alloc (2);
  gsl_vector_set (x, 0, U);
  gsl_vector_set (x, 1, V);

  T = gsl_multimin_fdfminimizer_conjugate_fr;
  s = gsl_multimin_fdfminimizer_alloc (T, 2);

  gsl_multimin_fdfminimizer_set(s, &my_func, x, 0.01, 1e-4);

  do{
    iter++;
    status = gsl_multimin_fdfminimizer_iterate(s);
    if(status)
      break;
    status = gsl_multimin_test_gradient(s->gradient, 1e-3);
  }
  while (status == GSL_CONTINUE && iter < niter);

  U = gsl_vector_get(s->x, 0);
  V = gsl_vector_get(s->x, 1);
  res = s->f;
  gsl_multimin_fdfminimizer_free (s);
  gsl_vector_free (x);
}                                           

void minimize_3(double (*f) (double, double, double,void *data), 
                void (*df) (double  , double  , double , 
                            double &, double &, double &, double &,
                            void *data) ,
                void *data,int niter,
                double &U, double &V, double &W, double &res)
{
  f_stat3 = f;
  df_stat3 = df;
  
  int iter = 0;
  int status;
  
  const gsl_multimin_fdfminimizer_type *T;
  gsl_multimin_fdfminimizer *s;
  gsl_vector *x;
  gsl_multimin_function_fdf my_func;

  my_func.f = &fobj3;
  my_func.df = &dfobj3;
  my_func.fdf = &fdfobj3;
  my_func.n = 3;
  my_func.params = data;

  x = gsl_vector_alloc (3);
  gsl_vector_set(x, 0, U);
  gsl_vector_set(x, 1, V);
  gsl_vector_set(x, 2, W);

  T = gsl_multimin_fdfminimizer_conjugate_fr;
  s = gsl_multimin_fdfminimizer_alloc(T, 3);

  gsl_multimin_fdfminimizer_set (s, &my_func, x, 0.01, 1e-4);
  
  do{
    iter++;
    status = gsl_multimin_fdfminimizer_iterate (s);
    if (status)
      break;
    status = gsl_multimin_test_gradient (s->gradient, 1e-3);
  }
  while (status == GSL_CONTINUE && iter < niter);

  U = gsl_vector_get (s->x, 0);
  V = gsl_vector_get (s->x, 1);
  W = gsl_vector_get (s->x, 2);
  res = s->f;
  gsl_multimin_fdfminimizer_free (s);
  gsl_vector_free (x);
}                                           

void minimize_N(int N, 
                double (*f) (double*,void *data), 
                void (*df)  (double*,double*,double &,void *data) ,
                void *data,int niter,
                double *U, double &res)
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

  x = gsl_vector_alloc (N);
  for (int i=0;i<N;i++)
    gsl_vector_set (x, i, U[i]);

  T = gsl_multimin_fdfminimizer_conjugate_fr;
  s = gsl_multimin_fdfminimizer_alloc (T, N);

  gsl_multimin_fdfminimizer_set (s, &my_func, x, 0.01, 1e-4);

  do{
    iter++;
    status = gsl_multimin_fdfminimizer_iterate (s);
    
    if (status)
      break;
    
    status = gsl_multimin_test_gradient (s->gradient, 1e-3);
  }
  while (status == GSL_CONTINUE && iter < niter);
  
  for (int i=0;i<N;i++)
    U[i] = gsl_vector_get (s->x, i);
  res = s->f;
  gsl_multimin_fdfminimizer_free (s);
  gsl_vector_free (x);
}                                           

#else

int check_gsl()
{
  // initilize robust geometric predicates
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

void minimize_2(double (*f) (double, double, void *data), 
                void (*df) (double, double, double &, double &, double &, void *data) ,
                void *data,int niter,
                double &U, double &V, double &res)
{
  Msg::Error("Gmsh must be compiled with GSL support for minimize_2");
}

void minimize_3(double (*f) (double, double, double, void *data), 
                void (*df) (double, double, double , double &, double &, 
                            double &, double &, void *data) ,
                void *data,int niter,
                double &U, double &V, double &W, double &res)
{
  Msg::Error("Gmsh must be compiled with GSL support for minimize_3");
}

void minimize_N(int N, double (*f) (double*, void *data), 
                void (*df) (double*, double*, double &, void *data) ,
                void *data,int niter,
                double *, double &res)
{
  Msg::Error("Gmsh must be compiled with GSL support for minimize_N");
}

#endif
