#ifndef _DRAW_H_
#define _DRAW_H_

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

#include "List.h"
#include "Mesh.h"
#include "Views.h"

#define GMSH_RENDER    1
#define GMSH_SELECT    2
#define GMSH_FEEDBACK  3

#define SELECTION_BUFFER_SIZE  1024

void InitOpengl(void);
void InitOverlay(void);
void InitShading(void);
void InitRenderModel(void);
void InitNoShading(void);
void InitPosition(void);

void Orthogonalize(int x, int y);
void ClearOpengl(void);

void set_r(int i, double val);
void set_t(int i, double val);
void set_s(int i, double val);

void Replot(void);

void RaiseFill (int i, double Val, double ValMin, double Raise[3][8]);
void Palette1 (Post_View * View, int nbi, int i);
void Palette2 (Post_View * View, double min, double max, double val);
void ColorSwitch(int i);

int  SelectEntity(int type, Vertex **v, Curve **c, Surface **s);
void ZeroHighlight(Mesh *m);
void BeginHighlight(void);
void EndHighlight(int permanent);
void HighlightEntity(Vertex *v,Curve *c, Surface *s, int permanent);
void HighlightEntityNum(int v, int c, int s, int permanant);

void Draw3d(void);
void Draw2d(void);
void DrawUI(void);
void Draw(void);

void Draw_String(char *s);
void Draw_Geom (Mesh *m);
void Draw_Mesh(Mesh *M);
void Draw_Post(void);
void Draw_Graph2D(void);
void Draw_Text2D(void);
void Draw_Text2D3D(int dim, int timestep, int nb, List_T *td, List_T *tc);
void Draw_Scales(void);
void Draw_Axes (double s);
void Draw_SmallAxes(void);
void Draw_Sphere(double size, double x, double y, double z);
void Draw_Cylinder (double width, double *x, double *y, double *z);
void Draw_Point(int type, double size, double *x, double *y, double *z, double Raise[3][8]);
void Draw_Line (int type, double width, double *x, double *y, double *z, double Raise[3][8]);
void Draw_Triangle (double *x, double *y, double *z,double *n,
                    double Raise[3][8], int shade);
void Draw_Quadrangle (double *x, double *y, double *z, double *n,
                      double Raise[3][8], int shade);
void Draw_Vector (int Type, int Fill,
                  double x, double y, double z,
                  double d, double dx, double dy, double dz,
                  double Raise[3][8]);

void Draw_Mesh_Volumes(void *a, void *b);
void Draw_Mesh_Surfaces(void *a, void *b);
void Draw_Mesh_Extruded_Surfaces(void *a, void *b);
void Draw_Mesh_Curves(void *a, void *b);
void Draw_Mesh_Points(void *a, void *b);

void Draw_Simplex_Volume (void *a, void *b);
void Draw_Simplex_Surface (void *a, void *b);
void Draw_Simplex_Surface_Simple (void *a, void *b);
void Draw_Simplex_Curves(void *a,void *b);

void Draw_Hexahedron_Volume (void *a, void *b);
void Draw_Prism_Volume (void *a, void *b);
void Draw_Pyramid_Volume (void *a, void *b);

void Draw_ScalarPoint(Post_View *View, int preproNormals,
		      double ValMin, double ValMax, double Raise[3][8],
		      double *X, double *Y, double *Z, double *V);
void Draw_VectorPoint(Post_View *View, 
		      double ValMin, double ValMax, double Raise[3][8],
		      double *X, double *Y, double *Z, double *V);
void Draw_TensorPoint(Post_View *View, 
		      double ValMin, double ValMax, double Raise[3][8],
		      double *X, double *Y, double *Z, double *V);
void Draw_ScalarLine(Post_View *View, int preproNormals,
		     double ValMin, double ValMax, double Raise[3][8],
		     double *X, double *Y, double *Z, double *V);
void Draw_VectorLine(Post_View *View, 
		     double ValMin, double ValMax, double Raise[3][8],
		     double *X, double *Y, double *Z, double *V);
void Draw_TensorLine(Post_View *View, 
		     double ValMin, double ValMax, double Raise[3][8],
		     double *X, double *Y, double *Z, double *V);
void Draw_ScalarTriangle(Post_View *View, int preproNormals,
			 double ValMin, double ValMax, double Raise[3][8],
			 double *X, double *Y, double *Z, double *V);
void Draw_VectorTriangle(Post_View *View, 
			 double ValMin, double ValMax, double Raise[3][8],
			 double *X, double *Y, double *Z, double *V);
void Draw_TensorTriangle(Post_View *View, 
			 double ValMin, double ValMax, double Raise[3][8],
			 double *X, double *Y, double *Z, double *V);
void Draw_ScalarTetrahedron(Post_View *View, int preproNormals,
			    double ValMin, double ValMax, double Raise[3][8],
			    double *X, double *Y, double *Z, double *V);
void Draw_VectorTetrahedron(Post_View *View, 
			    double ValMin, double ValMax, double Raise[3][8],
			    double *X, double *Y, double *Z, double *V);
void Draw_TensorTetrahedron(Post_View *View, 
			    double ValMin, double ValMax, double Raise[3][8],
			    double *X, double *Y, double *Z, double *V);
void Draw_ScalarQuadrangle(Post_View *View, int preproNormals,
			   double ValMin, double ValMax, double Raise[3][8],
			   double *X, double *Y, double *Z, double *V);
void Draw_VectorQuadrangle(Post_View *View, 
			   double ValMin, double ValMax, double Raise[3][8],
			   double *X, double *Y, double *Z, double *V);
void Draw_TensorQuadrangle(Post_View *View, 
			   double ValMin, double ValMax, double Raise[3][8],
			   double *X, double *Y, double *Z, double *V);
void Draw_ScalarHexahedron(Post_View *View, int preproNormals,
			   double ValMin, double ValMax, double Raise[3][8],
			   double *X, double *Y, double *Z, double *V);
void Draw_VectorHexahedron(Post_View *View, 
			   double ValMin, double ValMax, double Raise[3][8],
			   double *X, double *Y, double *Z, double *V);
void Draw_TensorHexahedron(Post_View *View, 
			   double ValMin, double ValMax, double Raise[3][8],
			   double *X, double *Y, double *Z, double *V);
void Draw_ScalarPrism(Post_View *View, int preproNormals,
		      double ValMin, double ValMax, double Raise[3][8],
		      double *X, double *Y, double *Z, double *V);
void Draw_VectorPrism(Post_View *View, 
		      double ValMin, double ValMax, double Raise[3][8],
		      double *X, double *Y, double *Z, double *V);
void Draw_TensorPrism(Post_View *View, 
		      double ValMin, double ValMax, double Raise[3][8],
		      double *X, double *Y, double *Z, double *V);
void Draw_ScalarPyramid(Post_View *View, int preproNormals,
			double ValMin, double ValMax, double Raise[3][8],
			double *X, double *Y, double *Z, double *V);
void Draw_VectorPyramid(Post_View *View, 
			double ValMin, double ValMax, double Raise[3][8],
			double *X, double *Y, double *Z, double *V);
void Draw_TensorPyramid(Post_View *View, 
			double ValMin, double ValMax, double Raise[3][8],
			double *X, double *Y, double *Z, double *V);

#endif
