#ifndef _VIEWS_H_
#define _VIEWS_H_

#include "ColorTable.h"

class smooth_container;

class Post_View{
  public :
  // intrinsic to a view
  int Num, Index, Changed, DuplicateOf, Links, Dirty;
  char FileName[256], Name[256], AbscissaName[256];

  // the data
  int datasize; // size(double) or sizeof(float)
  int NbTimeStep, ScalarOnly, TextOnly;
  double Min, Max, BBox[6];
  List_T *Time;
  int NbSP, NbVP, NbTP;
  List_T *SP, *VP, *TP; // points
  int NbSL, NbVL, NbTL;
  List_T *SL, *VL, *TL; // lines
  int NbST, NbVT, NbTT;
  List_T *ST, *VT, *TT; // triangles
  int NbSS, NbVS, NbTS;
  List_T *SS, *VS, *TS; // tetrahedra
  int NbT2, NbT3;
  List_T *T2D, *T2C, *T3D, *T3C; // 2D and 3D text strings

  // options
  int Type, Position[2], AutoPosition, Size[2];
  char   Format[256];
  double CustomMin, CustomMax;
  double Offset[3], Raise[3], ArrowScale, Explode;
  int Visible, IntervalsType, NbIso, NbAbscissa, Light, SmoothNormals ;
  double AngleSmoothNormals;
  int SaturateValues;
  int ShowElement, ShowTime, ShowScale;
  int TransparentScale, ScaleType, RangeType;
  int ArrowType, ArrowLocation;
  int TimeStep;
  int DrawStrings;
  int DrawPoints, DrawLines, DrawTriangles, DrawTetrahedra;
  int DrawScalars, DrawVectors, DrawTensors;
  int Boundary, PointSize, LineWidth, Grid;
  ColorTable CT;

  // dynamic
  double (*GVFI) (double min, double max, int nb, int index);
  int (*GIFV) (double min, double max, int nb, double value);
  // smooth the view
  void smooth();
  // smooth the normals
  smooth_container *normals;
  void reset_normals();
  void add_normal(double x, double y, double z, 
		  double nx, double ny, double nz);
  bool get_normal(double x, double y, double z, 
		  double &nx, double &ny, double &nz);
  // transform the view
  void transform(double mat[3][3]);
};

// Type
#define DRAW_POST_3D       1
#define DRAW_POST_2D_SPACE 2
#define DRAW_POST_2D_TIME  3

// IntervalsType
#define DRAW_POST_ISO          1
#define DRAW_POST_CONTINUOUS   2
#define DRAW_POST_DISCRETE     3
#define DRAW_POST_NUMERIC      4

// ArrowType
#define DRAW_POST_SEGMENT      1
#define DRAW_POST_ARROW        2
#define DRAW_POST_PYRAMID      3
#define DRAW_POST_CONE         4
#define DRAW_POST_DISPLACEMENT 5
#define DRAW_POST_ARROW_HEAD   6

// ArrowLocation
#define DRAW_POST_LOCATE_COG     1
#define DRAW_POST_LOCATE_VERTEX  2

// RangeType
#define DRAW_POST_DEFAULT 1
#define DRAW_POST_CUSTOM  2

// ScaleType
#define DRAW_POST_LINEAR             1
#define DRAW_POST_LOGARITHMIC        2
#define DRAW_POST_DOUBLELOGARITHMIC  3 // for vorticity e.g.

// Public functions

int fcmpPostViewNum(const void *v1, const void *v2);
int fcmpPostViewDuplicateOf(const void *v1, const void *v2);

Post_View * BeginView (int alloc);
void EndView (Post_View *v, int AddInUI, char *FileName, char *Name);
void FreeView(Post_View *v);
bool FreeView(int);
void Read_View(FILE *file, char *filename);
void Write_View(int Flag_BIN, Post_View *v, char *filename);
void CopyViewOptions(Post_View *src, Post_View *dest);

int BGMWithView (Post_View *ErrView);
int CreateBGM(Post_View *ErrView, int OptiMethod, double Degree,
              double OptiValue, double *ObjFunct, char *OutFile);
double ErrorInView(Post_View * ErrView, int *n);
Post_View *Create2DGraph(char *xname, char *yname, int nbdata, double *x, double *y);

ColorTable *Get_ColorTable(int num);
void Print_ColorTable(int num, char *prefix, FILE *file);

#endif
