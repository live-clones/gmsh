/* $Id: Views.h,v 1.6 2000-11-26 15:43:45 geuzaine Exp $ */
#ifndef _VIEWS_H_
#define _VIEWS_H_

#include "Const.h"

typedef struct{
  int    Dimension, Type;
  double *X, *Y, *Z, *V;
}Post_Simplex;

#include "ColorTable.h"

typedef struct{
  /* intrinsic to a view */
  int Num, Changed, DuplicateOf, Links;
  char FileName[NAME_STR_L], Name[NAME_STR_L];

  /* the data */
  List_T *Time;
  int NbSP, NbVP, NbTP;
  List_T *SP, *VP, *TP, *Points; // points
  int NbSL, NbVL, NbTL;
  List_T *SL, *VL, *TL, *Lines; // lines
  int NbST, NbVT, NbTT;
  List_T *ST, *VT, *TT, *Triangles; // triangles
  int NbSS, NbVS, NbTS;
  List_T *SS, *VS, *TS, *Tetrahedra; // tetrahedra
  int NbTimeStep, ScalarOnly;
  double Min, Max;

  /* options */
  char   Format[NAME_STR_L];
  double CustomMin, CustomMax;
  double Offset[3], Raise[3], ArrowScale;
  int Visible, IntervalsType, NbIso, Light ;
  int ShowElement, ShowTime, ShowScale;
  int TransparentScale, ScaleType, RangeType;
  int ArrowType, ArrowLocation;
  int TimeStep;
  ColorTable CT;

  /* dynamic */
  double (*GVFI) (double min, double max, int nb, int index);
  int (*GIFV) (double min, double max, int nb, double value);
}Post_View;

/* Type (The keys are important!) */
#define DRAW_POST_SCALAR  1
#define DRAW_POST_VECTOR  3
#define DRAW_POST_TENSOR  9

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

/* ArrowLocation */
#define DRAW_POST_LOCATE_COG     1
#define DRAW_POST_LOCATE_VERTEX  2

/* ScaleType */
#define DRAW_POST_DEFAULT 1
#define DRAW_POST_CUSTOM  2

/* RangeType */
#define DRAW_POST_LINEAR       1
#define DRAW_POST_LOGARITHMIC  2

/* Public functions */

int fcmpPostViewNum(const void *v1, const void *v2);
int fcmpPostViewDuplicateOf(const void *v1, const void *v2);

void BeginView (int alloc);
void EndView (int AddInUI, int Number, char *FileName, char *Name, 
              double XOffset, double YOffset, double ZOffset);
void FreeView(Post_View *v);

void Read_View(FILE *file, char *filename);
void CopyViewOptions(Post_View *src, Post_View *dest);

void AddView_ScalarSimplex(int dim, double *coord, int N, double *v);
void AddView_VectorSimplex(int dim, double *coord, int N, double *v);
void AddView_TensorSimplex(int dim, double *coord, int N, double *v);

int BGMWithView (Post_View *ErrView);
int CreateBGM(Post_View *ErrView, int OptiMethod, double Degree,
              double OptiValue, double *ObjFunct, char *OutFile);
double ErrorInView(Post_View * ErrView, int *n);

#endif
