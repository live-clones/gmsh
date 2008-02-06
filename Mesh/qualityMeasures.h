#ifndef _QUALITY_MEASURES_H_
#define _QUALITY_MEASURES_H_

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

class BDS_Point;
class BDS_Face;
class MVertex;
class MTriangle;
class MTetrahedron;
enum gmshQualityMeasure4Triangle {QMTRI_RHO};
enum gmshQualityMeasure4Tet      {QMTET_1,QMTET_2,QMTET_3,QMTET_ONE};

double qmTriangle(MTriangle *f, const gmshQualityMeasure4Triangle &cr); 
double qmTriangle(BDS_Face *f, const gmshQualityMeasure4Triangle &cr); 
double qmTriangle(const BDS_Point *p1, const BDS_Point *p2, const BDS_Point *p3, 
		  const gmshQualityMeasure4Triangle &cr); 
double qmTriangle(const MVertex *v1, const MVertex *v2, const MVertex *v3, 
		  const gmshQualityMeasure4Triangle &cr);
double qmTriangle(const double *d1, const double *d2, const double *d3, 
		  const gmshQualityMeasure4Triangle &cr);
double qmTriangle(const double &x1, const double &y1, const double &z1, 
		  const double &x2, const double &y2, const double &z2, 
		  const double &x3, const double &y3, const double &z3, 
		  const gmshQualityMeasure4Triangle &cr);
double qmTet(MTetrahedron *t, const gmshQualityMeasure4Tet &cr, double *volume = 0);
double qmTet(const MVertex *v1, const MVertex *v2, const MVertex *v3, 
	     const MVertex *v4, const gmshQualityMeasure4Tet &cr, double *volume = 0);
double qmTet(const double &x1, const double &y1, const double &z1, 
	     const double &x2, const double &y2, const double &z2, 
	     const double &x3, const double &y3, const double &z3, 
	     const double &x4, const double &y4, const double &z4, 
	     const gmshQualityMeasure4Tet &cr, double *volume = 0);

#endif
