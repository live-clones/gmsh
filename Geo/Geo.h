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

#include <map>
#include <math.h>
#include "GmshDefines.h"
#include "gmshSurface.h"
#include "List.h"
#include "Tree.h"
#include "SPoint2.h"
#include "ExtrudeParams.h"

#define MSH_POINT              100
#define MSH_POINT_BND_LAYER    101
#define MSH_POINT_DISCRETE     102
#define MSH_POINT_FROM_GMODEL  103

#define MSH_SEGM_LINE          200
#define MSH_SEGM_SPLN          201
#define MSH_SEGM_CIRC          202
#define MSH_SEGM_CIRC_INV      203
#define MSH_SEGM_ELLI          204
#define MSH_SEGM_ELLI_INV      205
#define MSH_SEGM_LOOP          206
#define MSH_SEGM_BSPLN         207
#define MSH_SEGM_NURBS         208
#define MSH_SEGM_BEZIER        209
#define MSH_SEGM_PARAMETRIC    210
#define MSH_SEGM_BND_LAYER     211
#define MSH_SEGM_DISCRETE      212
#define MSH_SEGM_FROM_GMODEL   213

#define MSH_SURF_PLAN          300
#define MSH_SURF_REGL          301
#define MSH_SURF_TRIC          302
#define MSH_SURF_BND_LAYER     303
#define MSH_SURF_LOOP          304
#define MSH_SURF_DISCRETE      305
#define MSH_SURF_FROM_GMODEL   306

#define MSH_VOLUME             400
#define MSH_VOLUME_DISCRETE    401
#define MSH_VOLUME_FROM_GMODEL 402

#define MSH_PHYSICAL_POINT     500
#define MSH_PHYSICAL_LINE      501
#define MSH_PHYSICAL_SURFACE   502
#define MSH_PHYSICAL_VOLUME    503

struct Coord{
  double X, Y, Z;
};

class Vertex {
 public :
  int Num;
  int Typ;
  char Visible;
  double lc, u, w;
  Coord Pos;
  // a model vertex is usually defined in the euclidian coordinates
  // (Pos). Yet, it can also be defined in the parametric coordinates
  // of a surface: pntOnGeometry stores the local coodinates of the
  // vertex in the gmshSurface it belongs to.
  gmshSurface *geometry;
  SPoint2  pntOnGeometry;
  Vertex(double X=0., double Y=0., double Z=0., double l=1., double W=1.)
    : Num(0), Visible(1), lc(l), u(0.), w(W), geometry(0)
  {
    Typ = MSH_POINT;
    Pos.X = X;
    Pos.Y = Y;
    Pos.Z = Z;
  }
  void norme()
  {
    double d = sqrt(Pos.X * Pos.X + Pos.Y * Pos.Y + Pos.Z * Pos.Z);
    if(d == 0.0) return;
    Pos.X /= d;
    Pos.Y /= d;
    Pos.Z /= d;
  }
  Vertex operator % (Vertex & autre) // cross product
  {
    return Vertex(Pos.Y * autre.Pos.Z - Pos.Z * autre.Pos.Y,
		  -(Pos.X * autre.Pos.Z - Pos.Z * autre.Pos.X),
		  Pos.X * autre.Pos.Y - Pos.Y * autre.Pos.X, lc, w);
  }
};

class DrawingColor{
 public:
  int type;
  unsigned int geom, mesh;
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
  float *k;
  int degre;
  CircParam Circle;
  char functu[256], functv[256], functw[256];
  DrawingColor Color;
  gmshSurface *geometry;
}Curve;

typedef struct{
  int Num;
  List_T *Curves;
}EdgeLoop;

typedef struct{
  int Num;
  int Typ;
  char Visible;
  int Method;
  int Recombine;
  int Recombine_Dir; // -1 is left, +1 is right, 0 is alternated
  double RecombineAngle;
  int ipar[5];
  List_T *Generatrices;
  List_T *EmbeddedCurves;
  List_T *EmbeddedPoints;
  List_T *Control_Points;
  List_T *TrsfPoints;
  double plan[3][3];
  double a, b, c, d;
  ExtrudeParams *Extrude;
  DrawingColor Color;
  // A surface is defined topologically by its Generatrices
  // i.e. curves that are the closure of it.  The geometry of the
  // surface is defined hereafter.  Note that this representation
  // should be the only one in gmsh, so parameter "Type" should
  // disappear from the class Surface.
  gmshSurface *geometry;
}Surface;

typedef struct{
  int Num;
  List_T *Surfaces;
}SurfaceLoop;

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
  List_T *SurfacesByTag;
  DrawingColor Color;
}Volume;

typedef struct{
  int Num;
  int Typ;
  char Visible;
  List_T *Entities;
}PhysicalGroup;

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
} Shape;

int comparePosition(const void *a, const void *b);
int compareVertex(const void *a, const void *b);
int compareCurve(const void *a, const void *b);
int compareEdgeLoop(const void *a, const void *b);
int compareSurface(const void *a, const void *b);
int compareSurfaceLoop(const void *a, const void *b);
int compareVolume(const void *a, const void *b);
int comparePhysicalGroup(const void *a, const void *b);

Vertex *Create_Vertex(int Num, double X, double Y, double Z, double lc, double u);
Vertex *Create_Vertex(int Num, double u, double v, gmshSurface *s, double lc);
Curve *Create_Curve(int Num, int Typ, int Order, List_T * Liste,
		    List_T * Knots, int p1, int p2, double u1, double u2);
Curve *CreateReversedCurve(Curve *c);
Surface *Create_Surface(int Num, int Typ);
Volume *Create_Volume(int Num, int Typ);
EdgeLoop *Create_EdgeLoop(int Num, List_T * intlist);
SurfaceLoop *Create_SurfaceLoop(int Num, List_T * intlist);
PhysicalGroup *Create_PhysicalGroup(int Num, int typ, List_T * intlist);

void End_Curve(Curve * c);
void End_Surface(Surface * s);

void Free_Vertex (void *a, void *b);
void Free_Curve(void *a, void *b);
void Free_EdgeLoop(void *a, void *b);
void Free_Surface(void *a, void *b);
void Free_SurfaceLoop(void *a, void *b);
void Free_Volume(void *a, void *b);
void Free_PhysicalGroup(void *a, void *b);

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
EdgeLoop *FindEdgeLoop(int inum);
Surface *FindSurface(int inum);
SurfaceLoop *FindSurfaceLoop(int inum);
Volume *FindVolume(int inum);
PhysicalGroup *FindPhysicalGroup(int inum, int type);

void TranslateShapes(double X,double Y,double Z,
                     List_T *ListShapes);
void DilatShapes(double X,double Y,double Z, double A,
                 List_T *ListShapes);
void RotateShapes(double Ax,double Ay,double Az,
		  double Px,double Py, double Pz,
		  double alpha, List_T *ListShapes);
void SymmetryShapes(double A,double B,double C,
		    double D, List_T *ListShapes);
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
bool ProjectPointOnSurface(Surface *s, Vertex &p, double u[2]);

bool IntersectCurvesWithSurface(List_T *curve_ids, int surface_id, List_T *point_ids);

int recognize_seg(int typ, List_T *liste, int *seg);
int recognize_loop(List_T *liste, int *loop);
int recognize_surfloop(List_T *liste, int *loop);

void Projette(Vertex * v, double mat[3][3]);

void sortEdgesInLoop(int num, List_T *edges);
void setSurfaceGeneratrices(Surface *s, List_T *loops);
void setVolumeSurfaces(Volume *v, List_T * loops);
void setSurfaceEmbeddedPoints(Surface *s, List_T *points);
void setSurfaceEmbeddedCurves(Surface *s, List_T *curves);

#endif
