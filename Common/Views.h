/* $Id: Views.h,v 1.2 2000-11-23 14:11:28 geuzaine Exp $ */
#ifndef _VIEWS_H_
#define _VIEWS_H_

#include "Const.h"

typedef struct{
  int Type;
  double X[4], Y[4], Z[4];
  double *V;
}Post_Simplex;

typedef struct{
  int Type;
  double X[3], Y[3], Z[3];
  double *V;
}Post_Triangle;

typedef struct{
  int Type;
  double X[2], Y[2], Z[2];
  double *V;
}Post_Line;

typedef struct{
  int Type;
  double X, Y, Z;
  double *V;
}Post_Point;

/* Post_XXX.Type. The keys are important ! */
#define DRAW_POST_SCALAR 1
#define DRAW_POST_VECTOR 3
#define DRAW_POST_TENSOR 9

/* IntervalsType */
#define DRAW_POST_ISO          1
#define DRAW_POST_CONTINUOUS   2
#define DRAW_POST_DISCRETE     3
#define DRAW_POST_NUMERIC      4

/* ArrowType */
#define DRAW_POST_SEGMENT      1
#define DRAW_POST_ARROW        2
#define DRAW_POST_PYRAMID      3
#define DRAW_POST_CONE         4
#define DRAW_POST_DISPLACEMENT 5
#define DRAW_POST_ARROW_HEAD   6

/* ArrowLovation */
#define DRAW_POST_LOCATE_COG     1
#define DRAW_POST_LOCATE_VERTEX  2

/* ScaleType */
#define DRAW_POST_DEFAULT 1
#define DRAW_POST_CUSTOM  2

/* RangeType */
#define DRAW_POST_LINEAR       1
#define DRAW_POST_LOGARITHMIC  2

#include "ColorTable.h"

typedef struct{
  int Num, Changed, Allocated;
  char Name[NAME_STR_L], Format[NAME_STR_L];
  double Min, Max, CustomMin, CustomMax;
  double Offset[3], Raise[3], ArrowScale;
  int Visible, ScalarOnly;
  int IntervalsType, NbIso, Light, ShowElement;
  int ShowScale, TransparentScale, ScaleType, RangeType;
  int ArrowType, ArrowLocation;
  int TimeStep, NbTimeStep;
  ColorTable CT;
  List_T *Simplices, *Triangles, *Lines, *Points;
  
  double (*GVFI) (double min, double max, int nb, int index);
  int (*GIFV) (double min, double max, int nb, double value);
}Post_View;



void BeginView (int alloc);
void EndView (char *Name, double XOffset, double YOffset, double ZOffset);

void AddView_ScalarSimplex (double x0, double y0, double z0,
			    double x1, double y1, double z1,
			    double x2, double y2, double z2,
			    double x3, double y3, double z3,
			    List_T * v);

void AddView_VectorSimplex (double x0, double y0, double z0,
			    double x1, double y1, double z1,
			    double x2, double y2, double z2,
			    double x3, double y3, double z3,
			    List_T * v);

void AddView_TensorSimplex (double x0, double y0, double z0,
			    double x1, double y1, double z1,
			    double x2, double y2, double z2,
			    double x3, double y3, double z3,
			    List_T * v);

void AddView_ScalarTriangle (double x0, double y0, double z0,
			     double x1, double y1, double z1,
			     double x2, double y2, double z2,
			     List_T * v);

void AddView_VectorTriangle (double x0, double y0, double z0,
			     double x1, double y1, double z1,
			     double x2, double y2, double z2,
			     List_T * v);

void AddView_TensorTriangle (double x0, double y0, double z0,
			     double x1, double y1, double z1,
			     double x2, double y2, double z2,
			     List_T * v);

void AddView_ScalarLine (double x0, double y0, double z0,
			 double x1, double y1, double z1,
			 List_T * v);

void AddView_VectorLine (double x0, double y0, double z0,
			 double x1, double y1, double z1,
			 List_T * v);

void AddView_TensorLine (double x0, double y0, double z0,
			 double x1, double y1, double z1,
			 List_T * v);

void AddView_ScalarPoint(double x0,double y0,double z0,
			List_T *v);

void AddView_VectorPoint(double x0,double y0,double z0,
			 List_T *v);

void AddView_TensorPoint(double x0,double y0,double z0,
			 List_T *v);

int BGMWithView (Post_View *ErrView);
int  CreateBGM(Post_View *ErrView, int OptiMethod, double Degree,
	       double OptiValue, double *ObjFunct, char *OutFile);
double ErrorInView(Post_View * ErrView, int *n);

#endif
