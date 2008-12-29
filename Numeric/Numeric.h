// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _NUMERIC_H_
#define _NUMERIC_H_

#include "NumericEmbedded.h"

int Init_Numeric();
void minimize_N(int N, double (*f) (double*, void *data), 
                void (*df) (double*, double*, double &, void *data),
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
