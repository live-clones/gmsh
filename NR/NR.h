#ifndef _NR_H_
#define _NR_H_

#include "Gmsh.h"
#include "nrutil.h"

/* "public" routines used in Gmsh */

void dsvdcmp(double **a, int m, int n, double w[], double **v);
double brent(double ax, double bx, double cx,
	     double (*f)(double), double tol, double *xmin);
void mnbrak(double *ax, double *bx, double *cx, double *fa, double *fb,
	    double *fc, double (*func)(double));
void newt(double x[], int n, int *check,
	  void (*vecfunc)(int, double [], double []));

#endif
