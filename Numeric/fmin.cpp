// $Id: fmin.cpp,v 1.1 2002-05-18 07:18:03 geuzaine Exp $
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
