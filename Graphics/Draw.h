/* $Id: Draw.h,v 1.5 2000-11-25 15:26:10 geuzaine Exp $ */
#ifndef _DRAW_H_
#define _DRAW_H_

#include "Views.h"

#define GMSH_RENDER    1
#define GMSH_SELECT    2
#define GMSH_FEEDBACK  3

#define TO_SCREEN  1
#define TO_FILE    2

#define PRINT_XDUMP            1
#define PRINT_GL2PS_SIMPLE     2
#define PRINT_GL2PS_RECURSIVE  3
#define PRINT_GL2PS_IMAGE      4
#define PRINT_GL2GIF           5

void Init(void);
void InitOv(void);
void InitShading(void);
void InitNoShading(void);
void InitPosition(void);

void Replot(void);

void RaiseFill (int i, double Val, double ValMin, double Raise[3][5]);
void Palette (Post_View * View, int nbi, int i);
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
void Draw(void);

void Draw_String(char *s);
void Draw_Geom (Mesh *m);
void Draw_Mesh(Mesh *M);
void Draw_Post(void);
void Draw_Scales(void);
void Draw_Axes (double s);
void Draw_SmallAxes(void);
void Draw_Point(double *x, double *y, double *z,
		double *Offset, double Raise[3][5]);
void Draw_Line (double *x, double *y, double *z,
		double *Offset, double Raise[3][5]);
void Draw_Triangle (double *x, double *y, double *z,
		    double *Offset, double Raise[3][5], int shade);
void Draw_Quadrangle (double *x, double *y, double *z,
		      double *Offset, double Raise[3][5], int shade);
void Draw_Polygon (int n, double *x, double *y, double *z,
		   double *Offset, double Raise[3][5]);
void Draw_Vector (int Type, int Fill,
		  double x, double y, double z,
		  double d, double dx, double dy, double dz,
		  double *Offset, double Raise[3][5]);
void Draw_Mesh_Volumes(void *a, void *b);
void Draw_Mesh_Surfaces(void *a, void *b);
void Draw_Mesh_Curves(void *a, void *b);
void Draw_Mesh_Points(void *a, void *b);
void Draw_Simplex_Surfaces (void *a, void *b);
void Draw_Simplex_Points(void *a,void *b);
void Draw_Extruded_Surfaces(void *a, void *b);
void Draw_Simplex_Volume (void *a, void *b);
void Draw_Hexahedron_Volume (void *a, void *b);
void Draw_Prism_Volume (void *a, void *b);

void Draw_Post_Tetrahedron (Post_View * View, Post_Simplex * s,
			    double ValMin, double ValMax, double Raise[3][5]);
void Draw_Post_Triangle (Post_View * View, Post_Simplex * t,
			 double ValMin, double ValMax, double Raise[3][5]);
void Draw_Post_Line (Post_View * View, Post_Simplex * l,
		     double ValMin, double ValMax, double Raise[3][5]);
void Draw_Post_Point (Post_View * View, Post_Simplex * p,
		      double ValMin, double ValMax, double Raise[3][5]);

#endif
