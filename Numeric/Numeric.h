#ifndef _NUMERIC_H_
#define _NUMERIC_H_

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

#include "NumericEmbedded.h"

int check_gsl();
void invert_singular_matrix3x3(double MM[3][3], double II[3][3]);

// Numerical routines implemented using either Numerical Recipes or
// the GSL
double brent(double ax, double bx, double cx,
             double (*f)(double), double tol, double *xmin);
void mnbrak(double *ax, double *bx, double *cx, double *fa, double *fb,
            double *fc, double (*func)(double));
void newt(double x[], int n, int *check,
          void (*vecfunc)(int, double [], double []));
void minimize_2 (double (*f) (double, double, void *data), 
                 void (*df) (double, double, double &, double &, double &, void *data) ,
                 void *data,int niter,
                 double &U, double &V, double &res);
void minimize_3 (double (*f) (double, double, double, void *data), 
                 void (*df) (double, double, double , double &, double &, 
                             double &, double &, void *data),
                 void *data,int niter,
                 double &U, double &V, double &W, double &res);
void minimize_N (int N, 
                 double (*f) (double*, void *data), 
                 void (*df) (double*, double*, double &, void *data) ,
                 void *data,int niter,
                 double *, double &res);

// Robust geometrical predicates
namespace gmsh{
double exactinit();
double incircle(double *pa, double *pb, double *pc, double *pd);
double insphere(double *pa, double *pb, double *pc, double *pd, double *pe);
double orient2d(double *pa, double *pb, double *pc);
double orient3d(double *pa, double *pb, double *pc, double *pd);
}

#endif
