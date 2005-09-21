#define NRANSI
#include "nrutil.h"

/* This file has been modified for inclusion in Gmsh (float->double) */

extern int nn;
extern double *fvec;
extern void (*nrfuncv)(int n, double v[], double f[]);

double fmin(double x[])
{
	int i;
	double sum;

	(*nrfuncv)(nn,x,fvec);
	for (sum=0.0,i=1;i<=nn;i++) sum += SQR(fvec[i]);
	return 0.5*sum;
}
#undef NRANSI
/* (C) Copr. 1986-92 Numerical Recipes Software J!0. */
