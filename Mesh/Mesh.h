#ifndef _MESH_H_
#define _MESH_H_

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

#include "GmshDefines.h"
#include "List.h"
#include "Tree.h"
#include "Vertex.h"
#include "ExtrudeParams.h"

class BDS_Mesh;

typedef struct _POINT PointRecord, *PointPeek;
typedef struct _CONTOUR ContourRecord, *ContourPeek;
typedef struct _DOC DocRecord, *DocPeek;
typedef struct _CDLIST DListRecord, *DListPeek;
typedef struct _MAILLAGE maillage, *maipeek;
typedef struct _DELAUNAY Delaunay, *delpeek;
typedef int PointNumero;

struct _DOC{
  PointRecord *points;  // points to triangulate
  int numPoints;        // number of points
  int numTriangles;     // number of triangles
  Delaunay *delaunay;   // 2D results
};

typedef struct{
  double v;
  double h;
}MPoint;

struct _POINT{
  MPoint where;
  DListPeek adjacent;
  int initial, permu, numcontour;
  double quality;
  void *data;
};

typedef struct{
  int Num;
  double t, lc, p;
}IntPoint;

struct _CDLIST{
  PointNumero point_num;
  DListPeek next, prev;
};

typedef struct{
  PointNumero search;
  PointNumero already;
}demi_triangle;

typedef struct{
  demi_triangle *info;
  PointNumero *t;
  int t_length, info_length;
}Striangle;

typedef struct {
  PointNumero from;
  PointNumero to;
  int num;
  int seg;
}edge;

typedef struct{
  PointNumero begin;
  PointNumero end;
}DT;

typedef struct{
  PointNumero from;
  PointNumero to;
}Segment;

typedef struct{
  PointNumero a, b, c;
  double xc, yc;
  double quality_value;
  int position, info, info2;
}Triangle;

typedef struct {
  Delaunay *voisin1, *voisin2, *voisin3;
}Voronoi;

struct _DELAUNAY{
  Triangle t;
  Voronoi v;
};

struct _CONTOUR{
  PointRecord *oriented_points;
  MPoint *perturbations;
  int numpoints, numerocontour, numerozon, info;
};

struct _MAILLAGE{
  PointRecord *points;
  delpeek *listdel;
  edge *listedges;
  int numedges, numtriangles, numpoints;
  int zone;
};

typedef struct{
  double zaxis[3];
  double radius1;
  double radius2;
  double xaxis[3];
  double center[3];
}CylParam;

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
  Tree_T *Vertices;
  List_T *TrsfVertices;
  int OrderU, OrderV;
  float *ku, *kv, *cp;
  struct _Surf *Support;
  CylParam Cyl;
  ExtrudeParams *Extrude;
  DrawingColor Color;
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

typedef struct{
  int Index;
  int Num;
  char Visible;
}MeshPartition;

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
  Tree_T *Vertices;
  DrawingColor Color;
}Volume;

typedef struct _Mesh Mesh;

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
  List_T *Vertices;
  ExtrudeParams *Extrude;
  float *k, *cp;
  int degre;
  CircParam Circle;
  char functu[256], functv[256], functw[256];
  DrawingColor Color;
}Curve;

struct _Mesh{
  char name[256];
  int status; // current state of the mesh
  Tree_T *Points;
  Tree_T *Vertices;
  Tree_T *Curves;
  Tree_T *Surfaces;
  Tree_T *Volumes;
  Tree_T *SurfaceLoops;
  Tree_T *EdgeLoops;
  List_T *PhysicalGroups;
  List_T *Partitions;
  BDS_Mesh *bds;
  BDS_Mesh *bds_mesh;
  int MaxPointNum, MaxLineNum, MaxLineLoopNum, MaxSurfaceNum;
  int MaxSurfaceLoopNum, MaxVolumeNum, MaxPhysicalNum;
};

// public functions

void mai3d(int Asked);
void Init_Mesh0();
void Init_Mesh();
void Maillage_Dimension_1();
void Maillage_Dimension_2();
void Maillage_Dimension_3();
void Make_Mesh_With_Points(DocRecord * ptr, PointRecord * Liste, int Numpoints);
double BGMXYZ(double X, double Y, double Z);
int BGMExists();
void ApplyLcFactor();
void Degre1();
void Degre2(bool linear=true, bool incomplete=false);

#endif
