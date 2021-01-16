// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GEO_H
#define GEO_H

// Internal data structures and functions for the built-in CAD kernel. This is
// legacy code and should never be used directly: use GEO_Internals instead, or
// the public api.

#include <cmath>
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

struct Coord {
  double X, Y, Z;
};

class Vertex {
public:
  int Num;
  int Typ;
  double lc, u, w;
  Coord Pos;
  // a model vertex is usually defined in the euclidian coordinates
  // (Pos). Yet, it can also be defined in the parametric coordinates
  // of a surface: pntOnGeometry stores the local coodinates of the
  // vertex in the gmshSurface it belongs to.
  gmshSurface *geometry;
  SPoint2 pntOnGeometry;
  int boundaryLayerIndex;
  Vertex(double X = 0., double Y = 0., double Z = 0., double l = 1.,
         double W = 1.)
    : Num(0), lc(l), u(0.), w(W), geometry(nullptr), boundaryLayerIndex(0)
  {
    Typ = MSH_POINT;
    Pos.X = X;
    Pos.Y = Y;
    Pos.Z = Z;
  }
  void norme()
  {
    double const d = std::sqrt(Pos.X * Pos.X + Pos.Y * Pos.Y + Pos.Z * Pos.Z);
    if(d == 0.0) return;
    Pos.X /= d;
    Pos.Y /= d;
    Pos.Z /= d;
  }
  Vertex operator%(Vertex &autre) // cross product
  {
    return Vertex(Pos.Y * autre.Pos.Z - Pos.Z * autre.Pos.Y,
                  -(Pos.X * autre.Pos.Z - Pos.Z * autre.Pos.X),
                  Pos.X * autre.Pos.Y - Pos.Y * autre.Pos.X, lc, w);
  }
};

class CircParam {
public:
  double t1, t2, f1, f2, incl;
  double invmat[3][3];
  double n[3];
};

class Curve {
public:
  int Num;
  int Typ;
  bool degenerated;
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
  gmshSurface *geometry;
  int ReverseMesh;
  int master;
  std::list<double> affineTransformation;
  bool degenerate() const
  {
    if(beg == end && Typ == MSH_SEGM_LINE) return true;
    return false;
  }
};

class EdgeLoop {
public:
  int Num;
  List_T *Curves;
};

class Surface {
public:
  int Num;
  int Typ;
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
  // A surface is defined topologically by its Generatrices i.e. curves that are
  // the closure of it.  The geometry of the surface is defined hereafter.  Note
  // that this representation should be the only one in gmsh, so parameter
  // "Type" should disappear from the class Surface.
  gmshSurface *geometry;
  int ReverseMesh, MeshAlgorithm, MeshSizeFromBoundary;
  bool degenerate() const;
};

class SurfaceLoop {
public:
  int Num;
  List_T *Surfaces;
};

class Volume {
public:
  int Num;
  int Typ;
  int Method;
  int Recombine3D;
  int QuadTri;
  ExtrudeParams *Extrude;
  List_T *TrsfPoints;
  List_T *Surfaces;
  List_T *SurfacesOrientations;
  List_T *SurfacesByTag;
};

class PhysicalGroup {
public:
  int Num;
  int Typ;
  List_T *Entities;
};

int CompareVertex(const void *a, const void *b);
int CompareSurfaceLoop(const void *a, const void *b);
int CompareEdgeLoop(const void *a, const void *b);
int CompareCurve(const void *a, const void *b);
int CompareSurface(const void *a, const void *b);
int CompareVolume(const void *a, const void *b);
int ComparePhysicalGroup(const void *a, const void *b);

void FreeVertex(void *a, void *b);
void FreePhysicalGroup(void *a, void *b);
void FreeEdgeLoop(void *a, void *b);
void FreeSurfaceLoop(void *a, void *b);
void FreeCurve(void *a, void *b);
void FreeSurface(void *a, void *b);
void FreeVolume(void *a, void *b);

inline void Projette(Vertex *v, double mat[3][3])
{
  double X = v->Pos.X * mat[0][0] + v->Pos.Y * mat[0][1] + v->Pos.Z * mat[0][2];
  double Y = v->Pos.X * mat[1][0] + v->Pos.Y * mat[1][1] + v->Pos.Z * mat[1][2];
  double Z = v->Pos.X * mat[2][0] + v->Pos.Y * mat[2][1] + v->Pos.Z * mat[2][2];
  v->Pos.X = X;
  v->Pos.Y = Y;
  v->Pos.Z = Z;
}

Vertex *CreateVertex(int Num, double X, double Y, double Z, double lc,
                     double u);
Vertex *CreateVertex(int Num, double u, double v, gmshSurface *s, double lc);
Curve *CreateCurve(int Num, int Typ, int Order, List_T *Liste, List_T *Knots,
                   int p1, int p2, double u1, double u2, bool &ok);
Curve *CreateReversedCurve(Curve *c);
Surface *CreateSurface(int Num, int Typ);
Volume *CreateVolume(int Num, int Typ);
EdgeLoop *CreateEdgeLoop(int Num, List_T *intlist);
SurfaceLoop *CreateSurfaceLoop(int Num, List_T *intlist);
PhysicalGroup *CreatePhysicalGroup(int Num, int typ, List_T *intlist);

bool EndCurve(Curve *c);
void EndSurface(Surface *s);

Vertex *FindPoint(int inum);
Curve *FindCurve(int inum);
EdgeLoop *FindEdgeLoop(int inum);
Surface *FindSurface(int inum);
SurfaceLoop *FindSurfaceLoop(int inum);
Volume *FindVolume(int inum);
PhysicalGroup *FindPhysicalGroup(int inum, int type);

bool TranslateShapes(double X, double Y, double Z, List_T *shapes);
bool DilatShapes(double X, double Y, double Z, double A, double B, double C,
                 List_T *shapes);
bool RotateShapes(double Ax, double Ay, double Az, double Px, double Py,
                  double Pz, double alpha, List_T *shapes);
bool SymmetryShapes(double A, double B, double C, double D, List_T *shapes);

Vertex *DuplicateVertex(Vertex *v);
Curve *DuplicateCurve(Curve *c);
Surface *DuplicateSurface(Surface *s);
Volume *DuplicateVolume(Volume *s);

void DeletePoint(int Num, bool recursive = false);
void DeleteCurve(int Num, bool recursive = false);
void DeleteSurface(int Num, bool recursive = false);
void DeleteVolume(int Num, bool recursive = false);
void DeletePhysicalPoint(int Num);
void DeletePhysicalLine(int Num);
void DeletePhysicalSurface(int Num);
void DeletePhysicalVolume(int Num);

void ExtrudeShapes(int extrude_type, List_T *in, double T0, double T1,
                   double T2, double A0, double A1, double A2, double X0,
                   double X1, double X2, double alpha, ExtrudeParams *e,
                   List_T *out);
void ProtudeXYZ(double &x, double &y, double &z, ExtrudeParams *e);

void ReplaceAllDuplicates();
void ReplaceAllDuplicatesNew(double tol = -1.);

bool ProjectPointOnSurface(Surface *s, Vertex &p, double uv[2]);
bool IntersectCurvesWithSurface(List_T *curve_ids, int surface_id,
                                List_T *shapes);
bool SplitCurve(int line_id, List_T *vertices_id, List_T *curves);

int RecognizeLineLoop(List_T *liste, int *loop);
int RecognizeSurfaceLoop(List_T *liste, int *loop);

bool SortEdgesInLoop(int num, List_T *edges, bool reorient = false);
bool SetSurfaceGeneratrices(Surface *s, List_T *loops);
bool SetVolumeSurfaces(Volume *v, List_T *loops);

void SetTranslationMatrix(double matrix[4][4], double T[3]);
void SetSymmetryMatrix(double matrix[4][4], double A, double B, double C,
                       double D);
void SetDilatationMatrix(double matrix[4][4], double T[3], double A, double B,
                         double C);
void SetRotationMatrix(double matrix[4][4], double Axe[3], double alpha);

int NEWPOINT();
int NEWLINE();
int NEWLINELOOP();
int NEWSURFACE();
int NEWSURFACELOOP();
int NEWVOLUME();
int NEWREG();
int NEWFIELD();
int NEWPHYSICAL();

#endif
