#ifndef _NURBS_H_
#define _NURBS_H_

// Copyright (C) 1997-2006 C. Geuzaine, J.-F. Remacle
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

#include "Vertex.h"
#include "Mesh.h"
#include "List.h"

Vertex InterpolateCubicSpline (Vertex * v[4], double t, double mat[4][4],
                               int derivee, double t1, double t2);
Vertex InterpolateUBS (Curve * Curve, double u, int derivee);
Vertex InterpolateNurbs (Curve * Curve, double u, int derivee);
Vertex InterpolateNurbsSurface (Surface * s, double u, double v);

void CreateNurbsSurface (int Num, int Order1, int Order2, List_T *, List_T *, List_T *);
void CreateNurbsSurfaceSupport (int Num, int Order2, int Order1, 
                                List_T * List, List_T *, List_T *);

#endif
