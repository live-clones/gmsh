#include <math.h>
#define NRANSI
#include "nrutil.h"
#define EPS 1.0e-4

/* This file has been modified for inclusion in Gmsh (float->double) */

void fdjac(int n, double x[], double fvec[], double **df,
	void (*vecfunc)(int, double [], double []))
{
	int i,j;
	double h,temp,*f;

	f=dvector(1,n);
	for (j=1;j<=n;j++) {
		temp=x[j];
		h=EPS*fabs(temp);
		if (h == 0.0) h=EPS;
		x[j]=temp+h;
		h=x[j]-temp;
		(*vecfunc)(n,x,f);
		x[j]=temp;
		for (i=1;i<=n;i++) df[i][j]=(f[i]-fvec[i])/h;
	}
	free_dvector(f,1,n);
}
#undef EPS
#undef NRANSI
/* (C) Copr. 1986-92 Numerical Recipes Software J!0. */
