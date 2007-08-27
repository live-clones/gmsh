#ifndef _ISO_H_
#define _ISO_H_

// Copyright (C) 1997-2007 C. Geuzaine, J.-F. Remacle
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

int IsoLine(double *X, double *Y, double *Z, double *Val, double V,
	    double *Xp, double *Yp, double *Zp);

int IsoTriangle(double *X, double *Y, double *Z, double *Val, double V, 
		double *Xp, double *Yp, double *Zp);

int IsoSimplex(double *X, double *Y, double *Z, double *Val, double V,
	       double *Xp, double *Yp, double *Zp, double n[3]);

int CutLine(double *x, double *y, double *z, double *v,
	    double min, double max, 
	    double *xp, double *yp, double *zp, double *vp);

int CutTriangle(double *x, double *y, double *z, double *v,
		double min, double max, 
		double *xp, double *yp, double *zp, double *vp);


// ******** FIXME: REMOVE EVERYTHING BELOW THIS LINE ***************

#include "Views.h"

void IsoLine_Old(Post_View *View, double *X, double *Y, double *Z, 
		 double *Val, double V);

void IsoTriangle_Old(Post_View *View, 
		     double *X, double *Y, double *Z, double *Val, double V,
		     unsigned int color);

void IsoSimplex_Old(Post_View *View, int preproNormals, 
		    double *X, double *Y, double *Z, double *Val, double V,
		    unsigned int color);
  
#endif
