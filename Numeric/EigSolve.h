// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _EIGSOLVE_H_
#define _EIGSOLVE_H_

int EigSolve(int nm,int n,double *A,double *wr,double *wi,
             double *v,int *work1,double *work2);
int EigSolveSym(int n,int nm,double *A,double *d,double *V,
                double *b,double *z);
void EigSort(int n, double *wr, double *wi, double *B);

int EigSolve3x3(const double A[9], double wr[3], double wi[3], double v[9]);

#endif
