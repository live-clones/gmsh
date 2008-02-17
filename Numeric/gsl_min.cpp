// $Id: gsl_min.cpp,v 1.4 2008-02-17 08:48:02 geuzaine Exp $
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

#include "Message.h"

#if defined(HAVE_GSL)

#include "Numeric.h"
#include <gsl/gsl_errno.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_multimin.h>

static double (*f_stat) (double, double, void *data); 
static void (*df_stat) (double, double, double &, double &, double &, void *data);
static double (*f_stat3) (double, double, double, void *data); 
static void (*df_stat3) (double, double, double, double &, double &, double &, double &,void *data);
static double (*f_statN) (double*, void *data); 
static void (*df_statN) (double*, double *, double &,void *data);

double fobj (const gsl_vector * x, void * data){
  double u, v;
  u = gsl_vector_get(x, 0);
  v = gsl_vector_get(x, 1);
  return f_stat(u,v,data);
}


double fobj3 (const gsl_vector * x, void * data){
  double u, v,w;
  u = gsl_vector_get(x, 0);
  v = gsl_vector_get(x, 1);
  w = gsl_vector_get(x, 2);
  return f_stat3(u,v,w,data);
}

double fobjN (const gsl_vector * x, void * data){
  return f_statN(x->data,data);
}

void dfobj (const gsl_vector * x, void * params, gsl_vector * g){
  double u, v, f, duf, dvf;
  u = gsl_vector_get(x, 0);
  v = gsl_vector_get(x, 1);
  df_stat(u,v,f, duf,dvf,params);
  gsl_vector_set(g, 0, duf);
  gsl_vector_set(g, 1, dvf);
}

void dfobj3 (const gsl_vector * x, void * params, gsl_vector * g){
  double u, v, w,f, duf, dvf,dwf;
  u = gsl_vector_get(x, 0);
  v = gsl_vector_get(x, 1);
  w = gsl_vector_get(x, 2);
  df_stat3(u,v,w,f, duf,dvf,dwf,params);
  gsl_vector_set(g, 0, duf);
  gsl_vector_set(g, 1, dvf);
  gsl_vector_set(g, 2, dwf);
}

void dfobjN (const gsl_vector * x, void * params, gsl_vector * g){
  double f;
  df_statN(x->data, g->data,f,params);
}

void fdfobj (const gsl_vector * x, void * params, double * f, gsl_vector * g){
  double u, v, duf, dvf;
  u = gsl_vector_get(x, 0);
  v = gsl_vector_get(x, 1);
  df_stat(u,v,*f, duf,dvf,params);
  gsl_vector_set(g, 0, duf);
  gsl_vector_set(g, 1, dvf);
}

void fdfobj3 (const gsl_vector * x, void * params, double * f, gsl_vector * g){
  double u, v, w,duf, dvf,dwf;
  u = gsl_vector_get(x, 0);
  v = gsl_vector_get(x, 1);
  w = gsl_vector_get(x, 2);
  df_stat3(u,v,w,*f, duf,dvf,dwf,params);
  gsl_vector_set(g, 0, duf);
  gsl_vector_set(g, 1, dvf);
  gsl_vector_set(g, 2, dwf);
}

void fdfobjN (const gsl_vector * x, void * params, double * f, gsl_vector * g){
  df_statN(x->data,g->data,*f,params);
}

void minimize_2 ( double (*f) (double, double, void *data), 
		  void (*df) (double, double, double &, double &, double &, void *data) ,
		  void *data,int niter,
		  double &U, double &V, double &res){
  f_stat = f;
  df_stat = df;

  size_t iter = 0;
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

  gsl_multimin_fdfminimizer_set (s, &my_func, x, 0.01, 1e-4);

  //  printf("minimizing\n");

  do
    {
      iter++;
      status = gsl_multimin_fdfminimizer_iterate (s);
      
      if (status)
        break;
      
      status = gsl_multimin_test_gradient (s->gradient, 1e-3);
      
//       if (status == GSL_SUCCESS)
//         printf ("Minimum found at:\n");
      
//         printf ("%5d %.5f %.5f %22.15e\n", iter,
//                 gsl_vector_get (s->x, 0), 
//                 gsl_vector_get (s->x, 1), 
//                 s->f);
      
    }
  while (status == GSL_CONTINUE && iter < niter);

  U = gsl_vector_get (s->x, 0);
  V = gsl_vector_get (s->x, 1);
  res = s->f;
  gsl_multimin_fdfminimizer_free (s);
  gsl_vector_free (x);
  
} 					    

void minimize_3 ( double (*f) (double, double, double,void *data), 
		  void (*df)  (double  , double  , double , 
			       double &, double &, double &, double &,
			       void *data) ,
		  void *data,int niter,
		  double &U, double &V, double &W, double &res){
  f_stat3 = f;
  df_stat3 = df;

  size_t iter = 0;
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
  gsl_vector_set (x, 0, U);
  gsl_vector_set (x, 1, V);
  gsl_vector_set (x, 2, W);

  T = gsl_multimin_fdfminimizer_conjugate_fr;
  s = gsl_multimin_fdfminimizer_alloc (T, 3);

  gsl_multimin_fdfminimizer_set (s, &my_func, x, 0.01, 1e-4);

  //    printf("minimizing\n");

  do
    {
      iter++;
      status = gsl_multimin_fdfminimizer_iterate (s);
      
      if (status)
        break;
      
      status = gsl_multimin_test_gradient (s->gradient, 1e-3);
      
//       if (status == GSL_SUCCESS)
//         printf ("Minimum found at:\n");
      
//          printf ("%5d %4.5f %4.5f %4.5f %10.5f\n", iter,
//                  gsl_vector_get (s->x, 0), 
//                  gsl_vector_get (s->x, 1), 
//                  gsl_vector_get (s->x, 2), 
//                  s->f);
      
    }
  while (status == GSL_CONTINUE && iter < niter);

  U = gsl_vector_get (s->x, 0);
  V = gsl_vector_get (s->x, 1);
  W = gsl_vector_get (s->x, 2);
  res = s->f;
  gsl_multimin_fdfminimizer_free (s);
  gsl_vector_free (x);
  
} 					    

void minimize_N (int N, 
		 double (*f) (double*,void *data), 
		 void (*df)  (double*,double*,double &,void *data) ,
		 void *data,int niter,
		 double *U, double &res){
  f_statN = f;
  df_statN = df;

  size_t iter = 0;
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

  do
    {
      iter++;
      status = gsl_multimin_fdfminimizer_iterate (s);
      
      if (status)
        break;
      
      status = gsl_multimin_test_gradient (s->gradient, 1e-3);
      
//       if (status == GSL_SUCCESS)
//         printf ("Minimum found at:\n");
      
//          printf ("%5d %4.5f %4.5f %4.5f %10.5f\n", iter,
//                  gsl_vector_get (s->x, 0), 
//                  gsl_vector_get (s->x, 1), 
//                  gsl_vector_get (s->x, 2), 
//                  s->f);
      
    }
  while (status == GSL_CONTINUE && iter < niter);

  for (int i=0;i<N;i++)
    U[i] = gsl_vector_get (s->x, i);
  res = s->f;
  gsl_multimin_fdfminimizer_free (s);
  gsl_vector_free (x);
  
} 					    

#else

void minimize_2 ( double (*f) (double, double, void *data), 
		  void (*df) (double, double, double &, double &, double &, void *data) ,
		  void *data,int niter,
		  double &U, double &V, double &res)
{
  Msg(GERROR, "Gmsh must be compiled with GSL support for minimize_2");
}

void minimize_3 ( double (*f) (double, double, double, void *data), 
		  void (*df) (double, double, double , double &, double &, double &, double &, void *data) ,
		  void *data,int niter,
		  double &U, double &V, double &W, double &res)
{
  Msg(GERROR, "Gmsh must be compiled with GSL support for minimize_3");
}

void minimize_N (int N, 
		 double (*f) (double*, void *data), 
		 void (*df) (double*, double*, double &, void *data) ,
		 void *data,int niter,
		 double *, double &res)
{
  Msg(GERROR, "Gmsh must be compiled with GSL support for minimize_N");
}

#endif
