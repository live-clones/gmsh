#define NRANSI
#include "nrutil.h"

extern int nn;
extern float *fvec;
extern void (*nrfuncv) (int n, float v[], float f[]);

float 
fmin (float x[])
{
  int i;
  float sum;

  (*nrfuncv) (nn, x, fvec);
  for (sum = 0.0, i = 1; i <= nn; i++)
    sum += SQR (fvec[i]);
  return 0.5 * sum;
}
#undef NRANSI
/* (C) Copr. 1986-92 Numerical Recipes Software J!0. */
