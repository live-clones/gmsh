#ifndef _ISO_H_
#define _ISO_H_

// Copyright (C) 1997-2004 C. Geuzaine, J.-F. Remacle
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

#include "Views.h"

void CutTriangle1D(double *X, double *Y, double *Z, double *Val,
		   double V, double *Xp, double *Yp, double *Zp, int *nb);

int CutTriangle2D(double *X, double *Y, double *Z, double *Val,
		  double V1, double V2, double *Xp, double *Yp, double *Zp, 
		  int *nb, double *value);

void CutLine0D(double *X, double *Y, double *Z, double *Val,
	       double V, double *Xp, double *Yp, double *Zp, int *nb);

void CutLine1D(double *X, double *Y, double *Z, double *Val,
	       double V1, double V2, double *Xp, double *Yp, double *Zp,
	       int *nb, double *value);

void IsoSimplex(Post_View *View, int preproNormals, 
		double *X, double *Y, double *Z, double *Val, double V,
		unsigned int color);
  
#endif
