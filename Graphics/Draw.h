#ifndef _DRAW_H_
#define _DRAW_H_

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

#include "SBoundingBox3d.h"

#define GMSH_RENDER    1
#define GMSH_SELECT    2
#define GMSH_FEEDBACK  3

void SetOpenglContext();
void ClearOpengl();

void InitProjection(int xpick=0, int ypick=0, int wpick=0, int hpick=0);
void InitPosition();
void InitRenderModel();

void Unproject(double x, double y, double p[3], double d[3]);
void Viewport2World(double win[3], double xyz[3]);
void World2Viewport(double xyz[3], double win[3]);

int Fix2DCoordinates(double *x, double *y);

void Draw3d();
void Draw2d();
void DrawPlugin(void (*draw)());
void Draw();

void Draw_String(char *s);
void Draw_String(char *s, double style);
void Draw_String_Center(char *s);
void Draw_String_Right(char *s);
void Draw_Geom();
void Draw_Mesh();
void Draw_Post();
void Draw_Graph2D();
void Draw_Text2D();
void Draw_OnScreenMessages();
void Draw_Scales();

void Draw_Sphere(double size, double x, double y, double z, int light);
void Draw_Cylinder(double width, double *x, double *y, double *z, int light);
void Draw_TapCylinder(double width, double val1, double val2, double ValMin, 
		      double ValMax, double *x, double *y, double *z, int light);
void Draw_Vector(int Type, int Fill,
		 double relHeadRadius, double relStemLength, double relStemRadius,
		 double x, double y, double z, double dx, double dy, double dz,
		 int light);
void Draw_Box(double xmin, double ymin, double zmin,
	      double xmax, double ymax, double zmax, bool labels=true);
void Draw_PlaneInBoundingBox(double xmin, double ymin, double zmin,
			     double xmax, double ymax, double zmax,
			     double a, double b, double c, double d, int shade=0);
void Draw_SmallAxes();
void Draw_Axes(int mode, int tics[3], char format[3][256], char label[3][256],
	       double bbox[6],int mikado);
void Draw_Axes(int mode, int tics[3], char format[3][256], char label[3][256],
	       SBoundingBox3d &bbox,int mikado);

#endif

