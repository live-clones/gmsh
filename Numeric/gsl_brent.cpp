// $Id: gsl_brent.cpp,v 1.2 2003-02-19 00:17:01 geuzaine Exp $
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
// Author: Nicolas Tardiey <nicolas.tardieu@der.edf.fr>

#if defined(HAVE_GSL)

#include "Gmsh.h"
#include "Numeric.h"

#include <gsl/gsl_errno.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_min.h>

static double (*nrfunc)(double);

double fn1 (double x, void * params){
  return nrfunc(x);
}

#define MAXITER 100

// Returns the minimum betwen ax and bx to a given tol using brent's
// method.

double brent(double ax, double xx, double bx, 
	     double (*f)(double), double tol, double *xmin){
  int status;
  int iter = 0;
  double m, a, b;
  const gsl_min_fminimizer_type *T;
  gsl_min_fminimizer *s;
  gsl_function F;

  m = xx;

  // gsl wants a<b
  if(ax < bx){
    a = ax;
    b = bx;
  }
  else{
    a = bx;
    b = bx;
  }

  // if a-b < tol, return func(a)
  if(fabs(b-a) < tol){
    *xmin = ax;
    return(f(*xmin));
  }
 
  nrfunc = f;
  
  F.function = &fn1;
  F.params = 0;
  
  T = gsl_min_fminimizer_brent;
  s = gsl_min_fminimizer_alloc(T);
  gsl_min_fminimizer_set(s, &F, m, a, b);
  
  do{
    iter++;
    status = gsl_min_fminimizer_iterate(s);
    
    m = gsl_min_fminimizer_x_minimum(s);
    a = gsl_min_fminimizer_x_lower(s);
    b = gsl_min_fminimizer_x_upper(s);
    
    status = gsl_min_test_interval(a, b, tol, 0.0);
    
    //if(status == GSL_SUCCESS) printf ("Converged\n");
  }
  while(status == GSL_CONTINUE && iter < MAXITER);
  
  *xmin = m;
  return fn1(m, NULL);
}


// mnbrak finds an initial bracketting of the minimum of funct.  You
// give 2 initial points, ax and xx. The algo checks in which
// direction func decreases, and takes some steps in that direction,
// until the function increases. It then returns ax, xx (possibibly
// switched) and bx, and we know that there is a minimum between ax
// and bx.

#define GOLD 1.618034
#define GLIMIT 100.0
#define TINY 1.0e-20
#define SHFT(a,b,c,d) (a)=(b);(b)=(c);(c)=(d);

void mnbrak(double *ax, double *bx, double *cx, double *fa, double *fb, double *fc,
	    double (*func)(double)){
  double ulim,u,r,q,fu,dum;

  *fa=(*func)(*ax);
  *fb=(*func)(*bx);
  if(*fb > *fa){
    SHFT(dum,*ax,*bx,dum);
    SHFT(dum,*fb,*fa,dum);
  }
  *cx=(*bx)+GOLD*(*bx-*ax);
  *fc=(*func)(*cx);
  while(*fb > *fc){
    r=(*bx-*ax)*(*fb-*fc);
    q=(*bx-*cx)*(*fb-*fa);
    u=(*bx)-((*bx-*cx)*q-(*bx-*ax)*r)/(2.0*SIGN(FMAX(fabs(q-r),TINY),q-r));
    ulim=(*bx)+GLIMIT*(*cx-*bx);
    if((*bx-u)*(u-*cx) > 0.0){
      fu=(*func)(u);
      if(fu < *fc){
	*ax=(*bx);
	*bx=u;
	*fa=(*fb);
	*fb=fu;
	return;
      }
      else if(fu > *fb){
	*cx=u;
	*fc=fu;
	return;
      }
      u=(*cx)+GOLD*(*cx-*bx);
      fu=(*func)(u);
    }
    else if((*cx-u)*(u-ulim) > 0.0){
      fu=(*func)(u);
      if(fu < *fc){
	SHFT(*bx,*cx,u,*cx+GOLD*(*cx-*bx));
	SHFT(*fb,*fc,fu,(*func)(u));
      }
    }
    else if((u-ulim)*(ulim-*cx) >= 0.0){
      u=ulim;
      fu=(*func)(u);
    } 
    else{
      u=(*cx)+GOLD*(*cx-*bx);
      fu=(*func)(u);
    }
    SHFT(*ax,*bx,*cx,u);
    SHFT(*fa,*fb,*fc,fu);
  }
}

#endif
