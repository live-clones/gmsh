#ifndef _DRAW_H_
#define _DRAW_H_

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

#include "List.h"
#include "Views.h"

class GVertex;
class GEdge;
class GFace;
class GRegion;

#define GMSH_RENDER    1
#define GMSH_SELECT    2
#define GMSH_FEEDBACK  3

// selection buffer size = 5 * number of hits (in our case)
#define SELECTION_BUFFER_SIZE  50000
#define SELECTION_MAX_HITS     10000

void SetOpenglContext(void);
void ClearOpengl(void);

void InitProjection(int xpick=0, int ypick=0, int wpick=0, int hpick=0);
void InitPosition(void);
void InitRenderModel(void);

int Process_SelectionBuffer(int type, bool multi, 
			    int x, int y, int w, int h, 
			    GVertex *v[SELECTION_MAX_HITS], 
			    GEdge *c[SELECTION_MAX_HITS], 
			    GFace *s[SELECTION_MAX_HITS],
			    GRegion *r[SELECTION_MAX_HITS]);
char SelectEntity(int type, int *n,
		  GVertex *v[SELECTION_MAX_HITS], 
		  GEdge *c[SELECTION_MAX_HITS], 
		  GFace *s[SELECTION_MAX_HITS],
		  GRegion *r[SELECTION_MAX_HITS]);

void unproject(double x, double y, double p[3], double d[3]);
void Viewport2World(double win[3], double xyz[3]);
void World2Viewport(double xyz[3], double win[3]);

unsigned int PaletteContinuous(Post_View * View, double min, double max, double val);
unsigned int PaletteContinuousLinear(Post_View * v, double min, double max, double val);
unsigned int PaletteDiscrete(Post_View * View, int nbi, int i);

void HighlightEntity(GVertex *v, GEdge *c, GFace *s, GRegion *r, int permanent);
void HighlightEntityNum(int v, int c, int s, int r, int permanant);
void ZeroHighlightEntity(GVertex *v, GEdge *c, GFace *s, GRegion *r);
void ZeroHighlightEntityNum(int v, int c, int s, int r);
void ZeroHighlight();

void Draw3d(void);
void Draw2d(void);
void DrawPlugin(void (*draw)(void));
void Draw(void);

void Draw_String(char *s);
void Draw_String(char *s, double style);
void Draw_String_Center(char *s);
void Draw_String_Right(char *s);
void Draw_Geom(void);
void Draw_Mesh(void);
void Draw_Post(void);
void Draw_Graph2D(void);
void Draw_Text2D(void);
void Draw_Text2D3D(int dim, int timestep, int nb, List_T *td, List_T *tc);
int Fix2DCoordinates(double *x, double *y);
void Draw_OnScreenMessages(void);
void Draw_Scales(void);
void Draw_Disk(double size, double rint, double x, double y, double z, int light);
void Draw_Sphere(double size, double x, double y, double z, int light);
void Draw_Cylinder(double width, double *x, double *y, double *z, int light);
void Draw_Point(int type, double size, double *x, double *y, double *z, 
		int light);
void Draw_Line(int type, double width, double *x, double *y, double *z,
	       int light);
void Draw_Triangle_Overlay(double r, double g, double b,
			   double *v1, double *v2, double *v3);
void Draw_Vector(int Type, int Fill,
		 double relHeadRadius, double relStemLength, double relStemRadius,
		 double x, double y, double z, double dx, double dy, double dz,
		 int light);
void Draw_Box(double xmin, double ymin, double zmin,
	      double xmax, double ymax, double zmax, bool labels=true);
void Draw_PlaneInBoundingBox(double xmin, double ymin, double zmin,
			     double xmax, double ymax, double zmax,
			     double a, double b, double c, double d, int shade=0);
void Draw_SmallAxes(void);
void Draw_Axes(int mode, int tics[3], char format[3][256], char label[3][256],
	       double bbox[6]);

#define ARGS Post_View *View, int preproNormals, \
             double ValMin, double ValMax, 	 \
             double *X, double *Y, double *Z, double *V

void Draw_ScalarPoint(ARGS);
void Draw_VectorPoint(ARGS);
void Draw_TensorPoint(ARGS);
void Draw_ScalarLine(ARGS);
void Draw_VectorLine(ARGS);
void Draw_TensorLine(ARGS);
void Draw_ScalarTriangle(ARGS);
void Draw_VectorTriangle(ARGS);
void Draw_TensorTriangle(ARGS);
void Draw_ScalarTetrahedron(ARGS);
void Draw_VectorTetrahedron(ARGS);
void Draw_TensorTetrahedron(ARGS);
void Draw_ScalarQuadrangle(ARGS);
void Draw_VectorQuadrangle(ARGS);
void Draw_TensorQuadrangle(ARGS);
void Draw_ScalarHexahedron(ARGS);
void Draw_VectorHexahedron(ARGS);
void Draw_TensorHexahedron(ARGS);
void Draw_ScalarPrism(ARGS);
void Draw_VectorPrism(ARGS);
void Draw_TensorPrism(ARGS);
void Draw_ScalarPyramid(ARGS);
void Draw_VectorPyramid(ARGS);
void Draw_TensorPyramid(ARGS);

void Draw_ScalarElement(int type, ARGS);
void Draw_VectorElement(int type, ARGS);
void Draw_TensorElement(int type, ARGS);

#undef ARGS

double GiveValueFromIndex_Lin(double ValMin, double ValMax, int NbIso, int Iso);
double GiveValueFromIndex_Log(double ValMin, double ValMax, int NbIso, int Iso);
double GiveValueFromIndex_DoubleLog(double ValMin, double ValMax, int NbIso, int Iso);
int GiveIndexFromValue_Lin(double ValMin, double ValMax, int NbIso, double Val);
int GiveIndexFromValue_Log(double ValMin, double ValMax, int NbIso, double Val);
int GiveIndexFromValue_DoubleLog(double ValMin, double ValMax, int NbIso, double Val);

int GetValuesFromExternalView(Post_View *v, int type, int refcomp, 
			      int *nbcomp, double **vals, int viewIndex);

#endif
