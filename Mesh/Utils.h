#ifndef _UTILS_H_
#define _UTILS_H_

// Copyright (C) 1997 - 2003 C. Geuzaine, J.-F. Remacle
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
// Please report all bugs and problems to "gmsh@geuz.org".

void direction (Vertex * v1, Vertex * v2, double d[3]);
void Projette (Vertex * v, double mat[3][3]);
void MeanPlane(List_T *point, Surface *s);
void find_bestuv (Surface * s, double X, double Y,
                  double *U, double *V, double *Z, int N);
void XYtoUV (Surface * s, double *X, double *Y,
             double *U, double *V, double *Z, double relax);
void XYZtoUV (Surface *s, double X, double Y, double Z, 
	      double *U, double *V, double relax);
int Oriente (List_T * cu, double n[3]);
double angle_3p (Vertex * V, Vertex * P1, Vertex * P2);
double angle_plan (Vertex * V, Vertex * P1, Vertex * P2, double n[3]);
double angle_3pts (Vertex * a, Vertex * b, Vertex * c);
double trapeze (IntPoint * P1, IntPoint * P2);
void RecursiveIntegration (IntPoint * from, IntPoint * to, double (*f) (double X),
                           List_T * pPoints, double Prec, int *depth);
double Integration (double t1, double t2, double (*f) (double X),
                    List_T * pPoints, double Prec);

#endif
