#ifndef _VIEWS_H_
#define _VIEWS_H_

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

#include <map>
#include "ColorTable.h"
#include "List.h"
#include "VertexArray.h"
#include "SmoothNormals.h"
#include "AdaptiveViews.h"

#define VIEW_NB_ELEMENT_TYPES  (8*3)
#define VAL_INF 1.e200

#define POST_POINT           0
#define POST_LINE            1
#define POST_TRIANGLE        2
#define POST_QUADRANGLE      3
#define POST_TETRAHEDRON     4
#define POST_HEXAHEDRON      5
#define POST_PRISM           6
#define POST_PYRAMID         7

class Post_View{
 public :
  // intrinsic to a view
  int Num, Index, Changed, AliasOf, Links, Dirty;
  char FileName[256], Name[256];

  // the data
  int DataSize; // size(double) or sizeof(float)
  int NbTimeStep, ScalarOnly, TextOnly;
  double Min, Max, BBox[6], *TimeStepMin, *TimeStepMax;
  List_T *Time;
  int NbSP, NbVP, NbTP;
  List_T *SP, *VP, *TP; // points
  int NbSL, NbVL, NbTL, NbSL2, NbVL2, NbTL2;
  List_T *SL, *VL, *TL, *SL2, *VL2, *TL2; // lines
  int NbST, NbVT, NbTT, NbST2, NbVT2, NbTT2;
  List_T *ST, *VT, *TT, *ST2, *VT2, *TT2; // triangles
  int NbSQ, NbVQ, NbTQ, NbSQ2, NbVQ2, NbTQ2;
  List_T *SQ, *VQ, *TQ, *SQ2, *VQ2, *TQ2; // quadrangles
  int NbSS, NbVS, NbTS, NbSS2, NbVS2, NbTS2;
  List_T *SS, *VS, *TS, *SS2, *VS2, *TS2; // tetrahedra
  int NbSH, NbVH, NbTH, NbSH2, NbVH2, NbTH2;
  List_T *SH, *VH, *TH, *SH2, *VH2, *TH2; // hexahedra
  int NbSI, NbVI, NbTI, NbSI2, NbVI2, NbTI2;
  List_T *SI, *VI, *TI, *SI2, *VI2, *TI2; // prisms
  int NbSY, NbVY, NbTY, NbSY2, NbVY2, NbTY2;
  List_T *SY, *VY, *TY, *SY2, *VY2, *TY2; // pyramids
  int NbT2, NbT3;
  List_T *T2D, *T2C, *T3D, *T3C; // 2D and 3D text strings
  std::map < int , List_T * >  *Grains; // For LMGC90, grains shapes
  std::map < int , int >       *DisplayListsOfGrains; // For LMGC90, grains shapes


  // vertex arrays to draw triangles and lines efficiently
  VertexArray *TriVertexArray, *LinVertexArray;

  // options
  int Type;
  int Position[2], Size[2], AutoPosition;
  char Format[256];
  int Axes, AxesAutoPosition, AxesTics[3];
  char AxesFormat[3][256], AxesLabel[3][256];
  double AxesPosition[6];
  double CustomMin, CustomMax;
  double Offset[3], Raise[3], Transform[3][3], DisplacementFactor, Explode;
  double ArrowSize, ArrowRelHeadRadius, ArrowRelStemRadius, ArrowRelStemLength;
  double Normals, Tangents;
  int Visible, IntervalsType, NbIso, ArrowSizeProportional;
  int Light, LightTwoSide, LightLines, SmoothNormals;
  double AngleSmoothNormals;
  int SaturateValues, FakeTransparency;
  int ShowElement, ShowTime, ShowScale;
  int ScaleType, RangeType;
  int VectorType, TensorType, GlyphLocation;
  int TimeStep;
  int DrawStrings;
  int DrawPoints, DrawLines, DrawTriangles, DrawQuadrangles;
  int DrawTetrahedra, DrawHexahedra, DrawPrisms, DrawPyramids;
  int DrawScalars, DrawVectors, DrawTensors;
  int Boundary, PointType, LineType;
  double PointSize, LineWidth;
  GmshColorTable CT;
  int UseStipple, Stipple[10][2];
  char StippleString[10][32];
  int ExternalViewIndex, ViewIndexForGenRaise;
  int UseGenRaise;
  double GenRaiseFactor;
  char GenRaiseX[256], GenRaiseY[256], GenRaiseZ[256];
  void *GenRaise_f[3];

  // color options
  struct{
    unsigned int point, line, triangle, quadrangle;
    unsigned int tetrahedron, hexahedron, prism, pyramid;
    unsigned int tangents, normals;
    unsigned int text2d, text3d, axes;
  } color;

  // dynamic
  double (*GVFI)(double min, double max, int nb, int index);
  int (*GIFV)(double min, double max, int nb, double value);
  int ExternalElementIndex;
  double ExternalMin, ExternalMax;
  double TmpBBox[6]; // dynamically computed during drawing

  // smooth the view
  void smooth();
  // smooth normals
  smooth_normals *normals;
  void reset_normals();

  // some generic access functions
  int empty();
  void get_raw_data(int type, List_T **list, int **nbe, int *nbc, int *nbn);

  // transforms curved elements into linear ones
  void splitCurvedElements();

  // If the view is high order, coeffs are interpreated as
  // coefficients of a high order interpolation. So, a pre-pro
  // is done at the end of the view that sets the view to the
  // minimal resolution. Then, we can interactively modify the
  // resolution.
  Adaptive_Post_View *adaptive;
  void setGlobalResolutionLevel(int level)
  {
    if (adaptive)
      adaptive->setGlobalResolutionLevel(this, level);
  }
  void setAdaptiveResolutionLevel (int level, GMSH_Post_Plugin *plug = 0)
  {
    if (adaptive)
      adaptive->setAdaptiveResolutionLevel(this, level, plug);
  }

};

// Type
#define DRAW_POST_3D       1
#define DRAW_POST_2D_SPACE 2
#define DRAW_POST_2D_TIME  3

// IntervalsType
#define DRAW_POST_ISO        1
#define DRAW_POST_CONTINUOUS 2
#define DRAW_POST_DISCRETE   3
#define DRAW_POST_NUMERIC    4

// VectorType
#define DRAW_POST_SEGMENT      1
#define DRAW_POST_ARROW        2
#define DRAW_POST_PYRAMID      3
#define DRAW_POST_ARROW3D      4
#define DRAW_POST_DISPLACEMENT 5

// GlyphLocation
#define DRAW_POST_LOCATE_COG    1
#define DRAW_POST_LOCATE_VERTEX 2

// TensorType
#define DRAW_POST_VONMISES     		1
#define DRAW_POST_LMGC90       		2
#define DRAW_POST_LMGC90_TYPE  		3
#define DRAW_POST_LMGC90_COORD  	4
#define DRAW_POST_LMGC90_PRES   	5
#define DRAW_POST_LMGC90_SN     	6
#define DRAW_POST_LMGC90_DEPX   	7	
#define DRAW_POST_LMGC90_DEPY   	8
#define DRAW_POST_LMGC90_DEPZ   	9
#define DRAW_POST_LMGC90_DEPAV  	10
#define DRAW_POST_LMGC90_DEPNORM  	11
// RangeType
#define DRAW_POST_RANGE_DEFAULT  1
#define DRAW_POST_RANGE_CUSTOM   2
#define DRAW_POST_RANGE_PER_STEP 3

// ScaleType
#define DRAW_POST_LINEAR            1
#define DRAW_POST_LOGARITHMIC       2
#define DRAW_POST_DOUBLELOGARITHMIC 3 // for vorticity e.g.

// Public functions

int fcmpPostViewNum(const void *v1, const void *v2);
int fcmpPostViewAliasOf(const void *v1, const void *v2);

Post_View *BeginView(int alloc);
void EndView(Post_View *v, int AddInUI, char *FileName, char *Name);
void AliasView(int num, int withoptions);
void FreeView(Post_View *v);
bool RemoveViewByIndex(int index);
bool RemoveViewByNumber(int num);
int ReadView(char *filename);
void WriteView(Post_View *v, char *filename, int format, int append);
void CopyViewOptions(Post_View *src, Post_View *dest);
void CombineViews(int time, int how, int remove);

int BGMWithView(Post_View *ErrView);
Post_View *Create2DGraph(char *xname, char *yname, int nbdata, double *x, double *y);

GmshColorTable *Get_ColorTable(int num);
void Print_ColorTable(int num, int diff, char *prefix, FILE *file);

double ComputeVonMises(double* val);

void InitGeneralizedRaise(Post_View *v);
void FreeGeneralizedRaise(Post_View *v);
void ApplyGeneralizedRaise(Post_View * v, int numNodes, int numComp, double *vals,
			   double *x, double *y, double *z);

#endif
