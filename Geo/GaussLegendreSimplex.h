// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _GAUSS_LEGENDRE_SIMPLEX_H_
#define _GAUSS_LEGENDRE_SIMPLEX_H_

#include "MElement.h"

int GaussLegendreTet(int n1,int n2, int n3, IntPt *pts); 
int GaussLegendreTri(int n1,int n2,IntPt *pts);
int GaussLegendreHex(int n1, int n2, int n3, IntPt *pts);
#endif
