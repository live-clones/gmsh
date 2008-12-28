// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "GmshMessage.h"
#include "Numeric.h"

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

void minimize_N(int N, double (*f) (double*, void *data), 
                void (*df) (double*, double*, double &, void *data) ,
                void *data,int niter,
                double *, double &res)
{
  Msg::Error("Gmsh must be compiled with GSL support for minimize_N");
}

#endif
