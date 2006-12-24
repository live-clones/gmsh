#ifndef _GEO_H_
#define _GEO_H_

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

#include <math.h>
#include "GmshDefines.h"
#include "List.h"
#include "Tree.h"
#include "ExtrudeParams.h"

#define MSH_POINT            1
#define MSH_POINT_DISCRETE   100

#define MSH_SEGM_LINE        2
#define MSH_SEGM_SPLN        3
#define MSH_SEGM_CIRC        4
#define MSH_SEGM_CIRC_INV    5
#define MSH_SEGM_ELLI        6
#define MSH_SEGM_ELLI_INV    7
#define MSH_SEGM_LOOP        8
#define MSH_SEGM_BSPLN       15
#define MSH_SEGM_URBS        16
#define MSH_SEGM_NURBS       17
#define MSH_SEGM_BEZIER      18
#define MSH_SEGM_PARAMETRIC  19
#define MSH_SEGM_DISCRETE    101

#define MSH_SURF_PLAN        9
#define MSH_SURF_REGL        10
#define MSH_SURF_TRIC        11
#define MSH_SURF_NURBS       12
#define MSH_SURF_LOOP        13
#define MSH_SURF_TRIMMED     21
#define MSH_SURF_DISCRETE    102

#define MSH_VOLUME           14
#define MSH_VOLUME_DISCRETE  103

#define MSH_PHYSICAL_POINT   300
#define MSH_PHYSICAL_LINE    310
#define MSH_PHYSICAL_SURFACE 320
#define MSH_PHYSICAL_VOLUME  330

class DrawingColor{
 public:
  int type;
  unsigned int geom, mesh;
};

struct _Surf{
  int Num;
  int Typ;
  char Visible;
  int Method;
  int Recombine;
  int Recombine_Dir; // -1 is left, +1 is right, 0 is alternated
  double RecombineAngle;
  int ipar[5];
  int Nu, Nv;
  List_T *Generatrices;
  List_T *EmbeddedCurves;
  List_T *EmbeddedPoints;
  List_T *Control_Points;
  List_T *TrsfPoints;
  double plan[3][3];
  double invplan[3][3];
  double a, b, c, d;
  List_T *Orientations;
  List_T *Contours;
  int OrderU, OrderV;
  float *ku, *kv, *cp;
  struct _Surf *Support;
  ExtrudeParams *Extrude;
  DrawingColor Color;
  void print_info ();
};

typedef struct _Surf Surface;

typedef struct{
  int Num;
  List_T *Curves;
}EdgeLoop;

typedef struct{
  int Num;
  List_T *Surfaces;
}SurfaceLoop;

typedef struct{
  int Num;
  int Typ;
  char Visible;
  List_T *Entities;
}PhysicalGroup;

typedef struct {
  int Num;
  int Typ;
  char Visible;
  int Method;
  int ipar[8];
  ExtrudeParams *Extrude;
  List_T *TrsfPoints;
  List_T *Surfaces;
  List_T *SurfacesOrientations;
  DrawingColor Color;
}Volume;

struct Coord{
  double X,Y,Z;
};

class Vertex {
  public :
  int Num;
  char Visible;
  double lc, u, us[3], w;
  Coord Pos;
  Vertex()
  {
    Visible = 1;
    Pos.X = 0.0;
    Pos.Y = 0.0;
    Pos.Z = 0.0;
    w = 1.0;
    lc = 1.0;
  }
  Vertex(double X,double Y,double Z=0.0, double l=1.0, double W=1.0)
  {
    Visible = 1;
    Pos.X = X;
    Pos.Y = Y;
    Pos.Z = Z;
    w = W;
    lc = l;
  }
  void norme()
  {
    double d = sqrt(Pos.X * Pos.X + Pos.Y * Pos.Y + Pos.Z * Pos.Z);
    if(d == 0.0)
      return;
    Pos.X /= d;
    Pos.Y /= d;
    Pos.Z /= d;
  }
  Vertex operator %(Vertex & autre)
  {       // cross product
    return Vertex(Pos.Y * autre.Pos.Z - Pos.Z * autre.Pos.Y,
		  -(Pos.X * autre.Pos.Z - Pos.Z * autre.Pos.X),
		  Pos.X * autre.Pos.Y - Pos.Y * autre.Pos.X, lc, w);
  }
};

typedef struct{
  double t1, t2, f1, f2, incl;
  Vertex *v[4];
  double invmat[3][3];
  double n[3];
}CircParam;

typedef struct{
  int Num;
  int Typ;
  char Visible;
  int Method;
  int ipar[4];
  double dpar[4];
  double l;
  double mat[4][4];
  Vertex *beg, *end;
  double ubeg, uend;
  List_T *Control_Points;
  ExtrudeParams *Extrude;
  float *k, *cp;
  int degre;
  CircParam Circle;
  char functu[256], functv[256], functw[256];
  DrawingColor Color;
}Curve;

class Mesh{
private:
  void alloc_all();
  void free_all();
public:
  Tree_T *Points;
  Tree_T *Curves;
  Tree_T *Surfaces;
  Tree_T *Volumes;
  Tree_T *SurfaceLoops;
  Tree_T *EdgeLoops;
  List_T *PhysicalGroups;
  int MaxPointNum, MaxLineNum, MaxLineLoopNum, MaxSurfaceNum;
  int MaxSurfaceLoopNum, MaxVolumeNum, MaxPhysicalNum;
  Mesh(){ alloc_all(); }
  ~Mesh(){ free_all(); }
  void destroy(){ free_all(); alloc_all(); }
};

typedef struct {
  int Type;
  int Num;
  union {
    int I;
    double F;
    double V[4];
    List_T *ListDouble;
  } obj;
} Shape;

int compareVertex (const void *a, const void *b);
int comparePosition (const void *a, const void *b);
int compareSurfaceLoop(const void *a, const void *b);
int compareEdgeLoop(const void *a, const void *b);
int compareQuality(const void *a, const void *b);
int compareCurve(const void *a, const void *b);
int compareSurface(const void *a, const void *b);
int compareVolume(const void *a, const void *b);
int compareSxF(const void *a, const void *b);
int comparePhysicalGroup(const void *a, const void *b);

Vertex        *Create_Vertex (int Num, double X, double Y, double Z, double lc, double u);
PhysicalGroup *Create_PhysicalGroup(int Num, int typ, List_T * intlist);
Curve         *Create_Curve(int Num, int Typ, int Order, List_T * Liste,
			    List_T * Knots, int p1, int p2, double u1, double u2);
Surface       *Create_Surface(int Num, int Typ);
Volume        *Create_Volume(int Num, int Typ);
EdgeLoop      *Create_EdgeLoop(int Num, List_T * intlist);
SurfaceLoop   *Create_SurfaceLoop(int Num, List_T * intlist);

void CreateNurbsSurface (int Num, int Order1, int Order2, List_T *, List_T *, List_T *);
void CreateNurbsSurfaceSupport (int Num, int Order2, int Order1, 
                                List_T * List, List_T *, List_T *);

void Free_Vertex (void *a, void *b);
void Free_PhysicalGroup(void *a, void *b);
void Free_Surface(void *a, void *b);
void Free_Volume(void *a, void *b);
void Free_Volume_But_Not_Elements(void *a, void *b);
void Free_Curve(void *a, void *b);
void Free_EdgeLoop(void *a, void *b);
void Free_SurfaceLoop(void *a, void *b);

void End_Curve(Curve * c);
void End_Surface(Surface * s, int reset_orientations=1);

int NEWPOINT(void);
int NEWLINE(void);
int NEWLINELOOP(void);
int NEWSURFACE(void);
int NEWSURFACELOOP(void);
int NEWVOLUME(void);
int NEWPHYSICAL(void);
int NEWREG(void);

Vertex *FindPoint(int inum);
Curve *FindCurve(int inum);
Surface *FindSurface(int inum);
Volume *FindVolume(int inum);
EdgeLoop *FindEdgeLoop(int inum);
SurfaceLoop *FindSurfaceLoop(int inum);
PhysicalGroup *FindPhysicalGroup(int inum, int type);

Curve *CreateReversedCurve(Curve *c);
void ModifyLcPoint(int ip, double lc);

void TranslateShapes(double X,double Y,double Z,
                     List_T *ListShapes, int final);
void DilatShapes(double X,double Y,double Z, double A,
                 List_T *ListShapes, int final);
void RotateShapes(double Ax,double Ay,double Az,
		  double Px,double Py, double Pz,
		  double alpha, List_T *ListShapes, int final);
void SymmetryShapes(double A,double B,double C,
		    double D, List_T *ListShapes, int final);
void CopyShape(int Type, int Num, int *New);
void DeleteShape(int Type, int Num);
void ColorShape(int Type, int Num, unsigned int Color);
void VisibilityShape(int Type, int Num, int Mode);
void VisibilityShape(char *str, int Type, int Mode);
void ExtrudeShape(int extrude_type, int shape_type, int shape_num,
		  double T0, double T1, double T2,
		  double A0, double A1, double A2,
		  double X0, double X1, double X2, double alpha,
		  ExtrudeParams *e,
		  List_T *out);
void ExtrudeShapes(int extrude_type, List_T *in,
		   double T0, double T1, double T2,
		   double A0, double A1, double A2,
		   double X0, double X1, double X2, double alpha,
		   ExtrudeParams *e,
		   List_T *out);

void ProtudeXYZ(double &x, double &y, double &z, ExtrudeParams *e);

void ReplaceAllDuplicates();

bool ProjectPointOnCurve(Curve *c, Vertex *v, Vertex *RES, Vertex *DER);
bool ProjectPointOnSurface(Surface *s, Vertex &p);
bool ProjectPointOnSurface(Surface *s, Vertex *p,double *u, double *v);

int recognize_seg(int typ, List_T *liste, int *seg);
int recognize_loop(List_T *liste, int *loop);
int recognize_surfloop(List_T *liste, int *loop);

void direction(Vertex * v1, Vertex * v2, double d[3]);
void Projette(Vertex * v, double mat[3][3]);

#endif
