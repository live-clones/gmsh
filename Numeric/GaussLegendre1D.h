#ifndef _GAUSS_LEGENDRE_1D_H_
#define _GAUSS_LEGENDRE_1D_H_

// Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
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

/* 1 point rule points */
static double _GL_pt1[1]={
  0.000000000000000e+00};

/* 1 point rule weights */
static double _GL_wt1[1]={
  2.000000000000000e+00};

/* 2 point rule points */
static double _GL_pt2[2]={
  -5.773502691896257e-01, 5.773502691896257e-01};

/* 2 point rule weights */
static double _GL_wt2[2]={
  1.000000000000000e+00, 1.000000000000000e+00};

/* 3 point rule points */
static double _GL_pt3[3]={
  -7.745966692414834e-01, 0.000000000000000e+00, 7.745966692414834e-01};

/* 3 point rule weights */
static double _GL_wt3[3]={
  5.555555555555552e-01, 8.888888888888888e-01, 5.555555555555552e-01};

/* 4 point rule points */
static double _GL_pt4[4]={
  -8.611363115940526e-01,-3.399810435848563e-01, 3.399810435848563e-01, 8.611363115940526e-01};

/* 4 point rule weights */
static double _GL_wt4[4]={
  3.478548451374537e-01, 6.521451548625464e-01, 6.521451548625464e-01, 3.478548451374537e-01};

/* 5 point rule points */
static double _GL_pt5[5]={
  -9.061798459386640e-01,-5.384693101056831e-01, 0.000000000000000e+00, 5.384693101056831e-01, 9.061798459386640e-01};

/* 5 point rule weights */
static double _GL_wt5[5]={
  2.369268850561890e-01, 4.786286704993665e-01, 5.688888888888889e-01, 4.786286704993665e-01, 2.369268850561890e-01};

/* 6 point rule points */
static double _GL_pt6[6]={
  -9.324695142031521e-01,-6.612093864662646e-01,-2.386191860831969e-01, 2.386191860831969e-01, 6.612093864662646e-01, 9.324695142031521e-01};

/* 6 point rule weights */
static double _GL_wt6[6]={
  1.713244923791705e-01, 3.607615730481386e-01, 4.679139345726913e-01, 4.679139345726913e-01, 3.607615730481386e-01, 1.713244923791705e-01};

inline void gmshGaussLegendre1D(int nbQuadPoints, double **t, double **w)
{
  switch (nbQuadPoints){
  case 1:
    *t = _GL_pt1;
    *w = _GL_wt1;
    break;
  case 2:
    *t = _GL_pt2;
    *w = _GL_wt2;
    break;
  case 3:
    *t = _GL_pt3;
    *w = _GL_wt3;
    break;
  case 4:
    *t = _GL_pt4;
    *w = _GL_wt4;
    break;
  case 5:
    *t = _GL_pt5;
    *w = _GL_wt5;
    break;
  case 6:
    *t = _GL_pt6;
    *w = _GL_wt6;
    break;
  default :
    throw;
  }
}

#endif
