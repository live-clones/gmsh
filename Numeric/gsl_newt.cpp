// $Id: gsl_newt.cpp,v 1.3 2003-02-20 10:05:09 remacle Exp $
//
// Copyright (C) 1997 - 2003 C. Geuzaine, J.-F. Remacle
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
// Please report all bugs and problems to "gmsh@geuz.org".

// This implements a Newton method using the GSL.
//
// Original author: Nicolas Tardieu <nicolas.tardieu@der.edf.fr>

#if defined(HAVE_GSL)

#include "Gmsh.h"
#include "Numeric.h"

#include <gsl/gsl_math.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_multiroots.h>
#include <gsl/gsl_linalg.h>

#define MAX_DIM_NEWT 10
#define MAXITER 10000
#define PREC 1.e-8

int     gsl_dim;
double  gsl_u[MAX_DIM_NEWT], gsl_v[MAX_DIM_NEWT];
static void  (*nrfunc)(int n, double x[],double y[]);
struct  gsl_dummy{;};

void convert_vector_from_gsl(const gsl_vector *gv, double * v){
  int i, m;
  m=gv->size;
  for (i=0;i<m;i++){
    v[i+1]=gsl_vector_get(gv,i);
  }
}

void convert_vector_to_gsl(double *v, int n, gsl_vector *gv){
  int i;
  for (i=0;i<n;i++){
    gsl_vector_set (gv, i, v[i+1]);
  }
}

int gslfunc(const gsl_vector *xx, void *params, gsl_vector *f){
  convert_vector_from_gsl(xx,gsl_u);
  (*nrfunc)(gsl_dim,gsl_u,gsl_v);
  //  Msg(INFO, "f(%lf,%lf) = %lf %lf\n",gsl_u[1],gsl_u[2],gsl_v[1],gsl_v[2]);
  convert_vector_to_gsl(gsl_v,gsl_dim,f);
  return GSL_SUCCESS;
}

void newt(double x[], int n, int *check, void (*func)(int, double [],double [])){
  const gsl_multiroot_fsolver_type *T;
  gsl_multiroot_fsolver *s;
  int status;
  size_t i, iter = 0;
  struct gsl_dummy p = {};
  gsl_multiroot_function f = {&gslfunc, n, &p};
  gsl_vector *xx = gsl_vector_alloc (n);

  if(n > MAX_DIM_NEWT) Msg(FATAL, "Maximum Newton dimension exceeded\n");
  gsl_dim = n;

  nrfunc = func;
  convert_vector_to_gsl(x,n,xx);

  T = gsl_multiroot_fsolver_hybrid;
  s = gsl_multiroot_fsolver_alloc(T, 2);
  gsl_multiroot_fsolver_set(s, &f, xx);

  do{
    iter++;
    status = gsl_multiroot_fsolver_iterate(s);
    //    Msg(INFO, "status %d %d %d %lf %lf\n",status,n,iter,gsl_vector_get(s->x,0),gsl_vector_get(s->x,1));
    if(status) break; // solver problem
    status = gsl_multiroot_test_residual(s->f, n*PREC);
  }
  while(status == GSL_CONTINUE && iter < MAXITER);

  if (status == GSL_CONTINUE)// problem !!!
    {
      *check=1;
    }
  else// converged
    {
      //      Msg(INFO, "status %d %d %d %lf %lf\n",status,n,iter,gsl_vector_get(s->x,0),gsl_vector_get(s->x,1));
      convert_vector_from_gsl(s->x,x);
      *check=0;
    }

  gsl_multiroot_fsolver_free(s);
  gsl_vector_free(xx); 
}

#endif
