// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _GEO_H_
#define _GEO_H_

#include <math.h>
#include <vector>
#include <list>
#include "GmshDefines.h"
#include "GeoDefines.h"
#include "gmshSurface.h"
#include "ListUtils.h"
#include "TreeUtils.h"
#include "SPoint2.h"
#include "ExtrudeParams.h"
#include "findLinks.h"

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
  int boundaryLayerIndex;
  Vertex(double X=0., double Y=0., double Z=0., double l=1., double W=1.)
    : Num(0), Visible(1), lc(l), u(0.), w(W), geometry(0), boundaryLayerIndex(0)
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
  void SetVisible(int value, bool recursive)
  {
    Visible = value;
  }
};

class DrawingColor{
 public:
  int type;
  unsigned int geom, mesh;
};

class CircParam{
 public:
  double t1, t2, f1, f2, incl;
  double invmat[3][3];
  double n[3];
};

class Curve{
 public:
  int Num;
  int Typ;
  bool degenerated;
  char Visible;
  int Method;
  int nbPointsTransfinite;
  int typeTransfinite;
  double coeffTransfinite;
  double l;
  double mat[4][4];
  Vertex *beg, *end;
  double ubeg, uend;
  List_T *Control_Points;
  ExtrudeParams *Extrude;
  float *k;
  int degre;
  CircParam Circle;
  DrawingColor Color;
  gmshSurface *geometry;
  std::vector<int> compound;
  int ReverseMesh;
  int master;
  std::list<double> affineTransformation;
  void SetVisible(int value, bool recursive)
  {
    Visible = value;
    if(recursive){
      if(beg) beg->SetVisible(value, recursive);
      if(end) end->SetVisible(value, recursive);
      for(int i = 0; i < List_Nbr(Control_Points); i++){
        Vertex *pV;
        List_Read(Control_Points, i, &pV);
        pV->SetVisible(value, recursive);
      }
    }
  }
  void SetColor(unsigned int value, bool recursive)
  {
    Color.type = 1;
    Color.geom = Color.mesh = value;
  }
  bool degenerate() const
  {
    if (beg == end && Typ ==  MSH_SEGM_LINE) return true;
    return false;
  }
};

class EdgeLoop{
 public:
  int Num;
  List_T *Curves;
};

class Surface{
 public:
  int Num;
  int Typ;
  char Visible;
  int Method;
  int Recombine;
  int Recombine_Dir; // -1 is left, +1 is right, -2/2 is alternated left/right
  double RecombineAngle;
  int TransfiniteSmoothing;
  List_T *Generatrices;
  List_T *GeneratricesByTag;
  List_T *TrsfPoints;
  Vertex *InSphereCenter;
  ExtrudeParams *Extrude;
  DrawingColor Color;
  // A surface is defined topologically by its Generatrices
  // i.e. curves that are the closure of it.  The geometry of the
  // surface is defined hereafter.  Note that this representation
  // should be the only one in gmsh, so parameter "Type" should
  // disappear from the class Surface.
  gmshSurface *geometry;
  std::vector<int> compound, compoundBoundary[4];
  int ReverseMesh;
  void SetVisible(int value, bool recursive)
  {
    Visible = value;
    if(recursive){
      for(int i = 0; i < List_Nbr(Generatrices); i++){
        Curve *pC;
        List_Read(Generatrices, i, &pC);
        pC->SetVisible(value, recursive);
      }
    }
  }
  void SetColor(unsigned int value, bool recursive)
  {
    Color.type = 1;
    Color.geom = Color.mesh = value;
    if(recursive){
      for(int i = 0; i < List_Nbr(Generatrices); i++){
        Curve *pC;
        List_Read(Generatrices, i, &pC);
        pC->SetColor(value, recursive);
      }
    }
  }
  bool degenerate() const;
};

class SurfaceLoop{
 public:
  int Num;
  List_T *Surfaces;
};

class Volume {
 public:
  int Num;
  int Typ;
  char Visible;
  int Method;
  int Recombine3D;
  int QuadTri;
  ExtrudeParams *Extrude;
  List_T *TrsfPoints;
  List_T *Surfaces;
  List_T *SurfacesOrientations;
  List_T *SurfacesByTag;
  DrawingColor Color;
  std::vector<int> compound;
  void SetVisible(int value, bool recursive)
  {
    Visible = value;
    if(recursive){
      for(int i = 0; i < List_Nbr(Surfaces); i++){
        Surface *pS;
        List_Read(Surfaces, i, &pS);
        pS->SetVisible(value, recursive);
      }
    }
  }
  void SetColor(unsigned int value, bool recursive)
  {
    Color.type = 1;
    Color.geom = Color.mesh = value;
    if(recursive){
      for(int i = 0; i < List_Nbr(Surfaces); i++){
        Surface *pS;
        List_Read(Surfaces, i, &pS);
        pS->SetColor(value, recursive);
      }
    }
  }
};

class PhysicalGroup{
 public:
  int Num;
  int Typ;
  char Visible;
  List_T *Entities;
};

int compareVertex(const void *a, const void *b);
int compareSurfaceLoop(const void *a, const void *b);
int compareEdgeLoop(const void *a, const void *b);
int compareCurve(const void *a, const void *b);
int compareSurface(const void *a, const void *b);
int compareVolume(const void *a, const void *b);
int comparePhysicalGroup(const void *a, const void *b);

void Free_Vertex(void *a, void *b);
void Free_PhysicalGroup(void *a, void *b);
void Free_EdgeLoop(void *a, void *b);
void Free_SurfaceLoop(void *a, void *b);
void Free_Curve(void *a, void *b);
void Free_Surface(void *a, void *b);
void Free_Volume(void *a, void *b);

void Projette(Vertex *v, double mat[3][3]);

Vertex *Create_Vertex(int Num, double X, double Y, double Z, double lc, double u);
Vertex *Create_Vertex(int Num, double u, double v, gmshSurface *s, double lc);
Curve *Create_Curve(int Num, int Typ, int Order, List_T *Liste,
                    List_T *Knots, int p1, int p2, double u1, double u2);
Curve *CreateReversedCurve(Curve *c);
Surface *Create_Surface(int Num, int Typ);
Volume *Create_Volume(int Num, int Typ);
EdgeLoop *Create_EdgeLoop(int Num, List_T *intlist);
SurfaceLoop *Create_SurfaceLoop(int Num, List_T *intlist);
PhysicalGroup *Create_PhysicalGroup(int Num, int typ, List_T *intlist);

void End_Curve(Curve *c);
void End_Surface(Surface *s);

Vertex *FindPoint(int inum);
Curve *FindCurve(int inum);
EdgeLoop *FindEdgeLoop(int inum);
Surface *FindSurface(int inum);
SurfaceLoop *FindSurfaceLoop(int inum);
Volume *FindVolume(int inum);
PhysicalGroup *FindPhysicalGroup(int inum, int type);

void TranslateShapes(double X,double Y,double Z, List_T *shapes);
void DilatShapes(double X,double Y,double Z, double A, double B, double C,
                 List_T *shapes);
void RotateShapes(double Ax,double Ay,double Az,
                  double Px,double Py, double Pz, double alpha, List_T *shapes);
void SymmetryShapes(double A,double B,double C, double D, List_T *shapes);

Vertex *DuplicateVertex(Vertex *v);
Curve *DuplicateCurve(Curve *c);
Surface *DuplicateSurface(Surface *s);
Volume *DuplicateVolume(Volume *s);

void DeletePoint(int Num);
void DeleteCurve(int Num);
void DeleteSurface(int Num);
void DeleteVolume(int Num);
void DeletePhysicalPoint(int Num);
void DeletePhysicalLine(int Num);
void DeletePhysicalSurface(int Num);
void DeletePhysicalVolume(int Num);

void SetPartition(int Type, int Num, int Partition);

void ColorShape(int Type, int Num, unsigned int Color, bool Recursive);

void VisibilityShape(int Type, int Num, int Mode, bool Recursive);
void VisibilityShape(char *str, int Type, int Mode, bool Recursive);

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

int Extrude_ProtudePoint(int type, int ip,
			 double T0, double T1, double T2,
			 double A0, double A1, double A2,
			 double X0, double X1, double X2, double alpha,
			 Curve **pc, Curve **prc, int final,
			 ExtrudeParams *e);
int Extrude_ProtudeCurve(int type, int ic,
			 double T0, double T1, double T2,
			 double A0, double A1, double A2,
			 double X0, double X1, double X2, double alpha,
			 Surface **ps, int final,
			 ExtrudeParams *e);
int Extrude_ProtudeSurface(int type, int is,
			   double T0, double T1, double T2,
			   double A0, double A1, double A2,
			   double X0, double X1, double X2, double alpha,
			   Volume **pv, ExtrudeParams *e);
void ProtudeXYZ(double &x, double &y, double &z, ExtrudeParams *e);

void ReplaceAllDuplicates();
void ReplaceAllDuplicatesNew(double tol = -1.);

bool ProjectPointOnSurface(Surface *s, Vertex &p, double uv[2]);
bool IntersectCurvesWithSurface(List_T *curve_ids, int surface_id, List_T *shapes);
bool SplitCurve(int line_id, List_T *vertices_id, List_T *shapes);

int RecognizeLineLoop(List_T *liste, int *loop);
int RecognizeSurfaceLoop(List_T *liste, int *loop);

void SortEdgesInLoop(int num, List_T *edges, bool orient=false);
void SetSurfaceGeneratrices(Surface *s, List_T *loops);
void SetVolumeSurfaces(Volume *v, List_T *loops);

#endif
