// $Id: Newton.cpp,v 1.1 2002-05-18 21:34:29 geuzaine Exp $

/* (C) Copr. 1986-92 Numerical Recipes Software J!0. */

#include <math.h>

#define NRANSI
#include "NRUtil.h"

#define SQR(a)   ((a)*(a))

// global variables

int nn;
double *fvec;
void (*nrfuncv) (int n, double v[], double f[]);

// fmin.cpp

double
fmin (double x[])
{
  int i;
  double sum;

  (*nrfuncv) (nn, x, fvec);
  for (sum = 0.0, i = 1; i <= nn; i++)
    sum += SQR (fvec[i]);
  return 0.5 * sum;
}

// newt.cpp

#define MAXITS 200
#define TOLF 1.0e-10 /* 1.0e-4 */
#define TOLMIN 1.0e-12 /* 1.0e-6 */
#define TOLX 1.0e-14 /* 1.0e-7 */
#define STPMX 100.0
#define FREERETURN {free_dvector(fvec,1,n);free_dvector(xold,1,n);\
        free_dvector(p,1,n);free_dvector(g,1,n);free_dmatrix(fjac,1,n,1,n);\
        free_ivector(indx,1,n);return;}

void
newt (double x[], int n, int *check, 
      void (*vecfunc) (int, double[], double[]))
{
  void fdjac (int n, double x[], double fvec[], double **df,
  	      void (*vecfunc) (int, double[], double[]));
  double fmin (double x[]);
  void lnsrch (int n, double xold[], double fold, double g[], double p[],
	       double x[], double *f, double stpmax, int *check,
	       double (*func) (double[]));
  void lubksb (double **a, int n, int *indx, double b[]);
  void ludcmp (double **a, int n, int *indx, double *d);
  int i, its, j, *indx;
  double d, den, f, fold, stpmax, sum, temp, test, **fjac, *g, *p, *xold;

  indx = ivector (1, n);
  fjac = dmatrix (1, n, 1, n);
  g = dvector (1, n);
  p = dvector (1, n);
  xold = dvector (1, n);
  fvec = dvector (1, n);
  nn = n;
  nrfuncv = vecfunc;
  f = fmin (x);
  test = 0.0;
  for (i = 1; i <= n; i++)
    if (fabs (fvec[i]) > test)
      test = fabs (fvec[i]);
  if (test < 0.01 * TOLF)
    FREERETURN;
  for (sum = 0.0, i = 1; i <= n; i++)
    sum += SQR (x[i]);
  stpmax = STPMX * MAX (sqrt (sum), (double) n);
  for (its = 1; its <= MAXITS; its++) {
    fdjac (n, x, fvec, fjac, vecfunc);
    //vecjac (n, x, fvec, fjac, vecfunc);
    for (i = 1; i <= n; i++) {
      for (sum = 0.0, j = 1; j <= n; j++)
	sum += fjac[j][i] * fvec[j];
      g[i] = sum;
    }
    for (i = 1; i <= n; i++)
      xold[i] = x[i];
    fold = f;
    for (i = 1; i <= n; i++)
      p[i] = -fvec[i];
    ludcmp (fjac, n, indx, &d);
    lubksb (fjac, n, indx, p);
    lnsrch (n, xold, fold, g, p, x, &f, stpmax, check, fmin);
    test = 0.0;
    for (i = 1; i <= n; i++)
      if (fabs (fvec[i]) > test)
	test = fabs (fvec[i]);
    if (test < TOLF) {
      *check = 0;
      FREERETURN;
    }
    if (*check) {
      test = 0.0;
      den = MAX (f, 0.5 * n);
      for (i = 1; i <= n; i++) {
	temp = fabs (g[i]) * MAX (fabs (x[i]), 1.0) / den;
	if (temp > test)
	  test = temp;
      }
      *check = (test < TOLMIN ? 1 : 0);
      FREERETURN;
    }
    test = 0.0;
    for (i = 1; i <= n; i++) {
      temp = (fabs (x[i] - xold[i])) / MAX (fabs (x[i]), 1.0);
      if (temp > test)
	test = temp;
    }
    if (test < TOLX)
      FREERETURN;
  }

  //Msg(WARNING, "MAXITS exceeded in newt");
  *check=1;
}

#undef MAXITS
#undef TOLF
#undef TOLMIN
#undef TOLX
#undef STPMX
#undef FREERETURN


// lnsrch.cpp

#define ALF 1.0e-8 /* 1.0e-4 */
#define TOLX 1.0e-14 /* 1.0e-7 */

void
lnsrch (int n, double xold[], double fold, double g[], double p[], double x[],
	double *f, double stpmax, int *check, double (*func) (double[]))
{
  int i;
  double a, alam, alam2, alamin, b, disc, f2, fold2, rhs1, rhs2, slope,
    sum, temp, test, tmplam;

  *check = 0;
  for (sum = 0.0, i = 1; i <= n; i++)
    sum += p[i] * p[i];
  sum = sqrt (sum);
  if (sum > stpmax)
    for (i = 1; i <= n; i++)
      p[i] *= stpmax / sum;
  for (slope = 0.0, i = 1; i <= n; i++)
    slope += g[i] * p[i];
  test = 0.0;
  for (i = 1; i <= n; i++) {
    temp = fabs (p[i]) / MAX (fabs (xold[i]), 1.0);
    if (temp > test)
      test = temp;
  }
  alamin = TOLX / test;
  alam = 1.0;
  for (;;) {
    for (i = 1; i <= n; i++)
      x[i] = xold[i] + alam * p[i];
    *f = (*func) (x);
    if (alam < alamin) {
      for (i = 1; i <= n; i++)
	x[i] = xold[i];
      *check = 1;
      return;
    }
    else if (*f <= fold + ALF * alam * slope)
      return;
    else {
      if (alam == 1.0)
	tmplam = -slope / (2.0 * (*f - fold - slope));
      else {
	rhs1 = *f - fold - alam * slope;
	rhs2 = f2 - fold2 - alam2 * slope;
	a = (rhs1 / (alam * alam) - rhs2 / (alam2 * alam2)) / (alam - alam2);
	b =
	  (-alam2 * rhs1 / (alam * alam) +
	   alam * rhs2 / (alam2 * alam2)) / (alam - alam2);
	if (a == 0.0)
	  tmplam = -slope / (2.0 * b);
	else {
	  disc = b * b - 3.0 * a * slope;
	  if (disc < 0.0)
	    nrerror ("Roundoff problem in lnsrch.");
	  else
	    tmplam = (-b + sqrt (disc)) / (3.0 * a);
	}
	if (tmplam > 0.5 * alam)
	  tmplam = 0.5 * alam;
      }
    }
    alam2 = alam;
    f2 = *f;
    fold2 = fold;
    alam = MAX (tmplam, 0.1 * alam);
  }
}

#undef ALF
#undef TOLX



// fdjac.cpp

#define EPS 1.0e-4 /* 1.0e-4 */

void
fdjac (int n, double x[], double fvec[], double **df,
       void (*vecfunc) (int, double[], double[]))
{
  int i, j;
  double h, temp, *f;

  f = dvector (1, n);
  for (j = 1; j <= n; j++) {
    temp = x[j];
    h = EPS * fabs (temp);
    if (h == 0.0)
      h = EPS;
    x[j] = temp + h;
    h = x[j] - temp;
    (*vecfunc) (n, x, f);
    x[j] = temp;
    for (i = 1; i <= n; i++)
      df[i][j] = (f[i] - fvec[i]) / h;
  }
  free_dvector (f, 1, n);
}

#undef EPS


// ludcmp.cpp

#define TINY 1.0e-20;

void
ludcmp (double **a, int n, int *indx, double *d)
{
  int i, imax, j, k;
  double big, dum, sum, temp;
  double *vv;

  vv = dvector (1, n);
  *d = 1.0;
  for (i = 1; i <= n; i++) {
    big = 0.0;
    for (j = 1; j <= n; j++)
      if ((temp = fabs (a[i][j])) > big)
	big = temp;
    if (big == 0.0)
      nrerror ("Singular matrix in routine ludcmp");
    vv[i] = 1.0 / big;
  }
  for (j = 1; j <= n; j++) {
    for (i = 1; i < j; i++) {
      sum = a[i][j];
      for (k = 1; k < i; k++)
	sum -= a[i][k] * a[k][j];
      a[i][j] = sum;
    }
    big = 0.0;
    for (i = j; i <= n; i++) {
      sum = a[i][j];
      for (k = 1; k < j; k++)
	sum -= a[i][k] * a[k][j];
      a[i][j] = sum;
      if ((dum = vv[i] * fabs (sum)) >= big) {
	big = dum;
	imax = i;
      }
    }
    if (j != imax) {
      for (k = 1; k <= n; k++) {
	dum = a[imax][k];
	a[imax][k] = a[j][k];
	a[j][k] = dum;
      }
      *d = -(*d);
      vv[imax] = vv[j];
    }
    indx[j] = imax;
    if (a[j][j] == 0.0)
      a[j][j] = TINY;
    if (j != n) {
      dum = 1.0 / (a[j][j]);
      for (i = j + 1; i <= n; i++)
	a[i][j] *= dum;
    }
  }
  free_dvector (vv, 1, n);
}

#undef TINY


// lubksb.cpp

void
lubksb (double **a, int n, int *indx, double b[])
{
  int i, ii = 0, ip, j;
  double sum;

  for (i = 1; i <= n; i++) {
    ip = indx[i];
    sum = b[ip];
    b[ip] = b[i];
    if (ii)
      for (j = ii; j <= i - 1; j++)
	sum -= a[i][j] * b[j];
    else if (sum)
      ii = i;
    b[i] = sum;
  }
  for (i = n; i >= 1; i--) {
    sum = b[i];
    for (j = i + 1; j <= n; j++)
      sum -= a[i][j] * b[j];
    b[i] = sum / a[i][i];
  }
}
