#ifndef _EIGSOLVE_H_
#define _EIGSOLVE_H_

// Copyright (C) 1997-2005 C. Geuzaine, J.-F. Remacle
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
//
// Contributor(s):
//   Laurent Stainier

int EigSolve(int nm,int n,double *A,double *wr,double *wi,
	     double *v,int *work1,double *work2);
int EigSolveSym(int n,int nm,double *A,double *d,double *V,
		double *b,double *z);
void EigSort(int n, double *wr, double *wi, double *B);

int EigSolve3x3(const double A[9], double wr[3], double wi[3], double v[9]);

#endif
