#ifndef _MESH_H_
#define _MESH_H_

// Copyright (C) 1997-2004 C. Geuzaine, J.-F. Remacle
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
#include "Tree.h"
#include "Vertex.h"
#include "Element.h"
#include "Simplex.h"
#include "Edge.h"
#include "ExtrudeParams.h"
#include "STL.h"
#include "VertexArray.h"

#define FORMAT_MSH           1
#define FORMAT_UNV           2
#define FORMAT_GREF          3
#define FORMAT_XPM           4
#define FORMAT_PS            5
#define FORMAT_BMP           6
#define FORMAT_GIF           7
#define FORMAT_GEO           8
#define FORMAT_JPEG          9
#define FORMAT_AUTO          10
#define FORMAT_PPM           11
#define FORMAT_YUV           12
#define FORMAT_DMG           13
#define FORMAT_SMS           14
#define FORMAT_OPT           15
#define FORMAT_VTK           16
#define FORMAT_JPEGTEX       17
#define FORMAT_TEX           18
#define FORMAT_VRML          19
#define FORMAT_EPS           20
#define FORMAT_EPSTEX        21
#define FORMAT_PNG           22
#define FORMAT_PNGTEX        23
#define FORMAT_PDF           24
#define FORMAT_PDFTEX        25
#define FORMAT_PS_RASTER     26
#define FORMAT_EPS_RASTER    27
#define FORMAT_PDF_RASTER    28
#define FORMAT_EPSTEX_RASTER 29
#define FORMAT_PDFTEX_RASTER 30
#define FORMAT_LC_SUR        31
#define FORMAT_LC_VOL        32

#define CONV_VALUE    0.8

#define VIS_GEOM  (1<<0)
#define VIS_MESH  (1<<1)

#define NOTTOLINK 1
#define TOLINK    2

#define BOF         1
#define A_TOUT_PRIX 2

#define CENTER_CIRCCIRC 1
#define BARYCENTER      2

#define EXTERN      1
#define INTERN      2

#define CONSTANT    1
#define ONFILE      2
#define WITHPOINTS  3
#define FUNCTION    4

#define TRANSFINI 1
#define LIBRE     2
#define ELLIPTIC  3

#define BOULE 1
#define BOITE 2

#define NB_HISTOGRAM 100

typedef struct _POINT PointRecord, *PointPeek;
typedef struct _CONTOUR ContourRecord, *ContourPeek;
typedef struct _DOC DocRecord, *DocPeek;
typedef struct _CDLIST DListRecord, *DListPeek;
typedef struct _MAILLAGE maillage, *maipeek;
typedef struct _DELAUNAY Delaunay, *delpeek;
typedef int PointNumero;

struct _DOC{
  PointRecord *points;  // points to triangulate
  List_T *hotpoints;    // hotpoints
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
  int initial, permu, info, info2, numcontour;
  double quality, qualityy, angle;
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

class NXE{
 public :
  Vertex *v;
  List_T *Liste;
  ~NXE();
  NXE();
};

typedef struct{
  int N;
  List_T *pT;
}Brick;

typedef struct{
  int init;
  List_T *Bricks;
  Coord min, max;
  int Nx, Ny, Nz;
}Grid_T;

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
  double RecombineAngle;
  int ipar[5];
  int Nu, Nv;
  List_T *Generatrices;
  List_T *Control_Points;
  List_T *TrsfPoints;
  double plan[3][3];
  double invplan[3][3];
  double a, b, c, d;
  List_T *Orientations;
  List_T *Contours;
  Tree_T *Simplexes;
  Tree_T *Quadrangles;
  Tree_T *Vertices;
  List_T *TrsfVertices;
  Tree_T *Edges;
  int OrderU, OrderV;
  float *ku, *kv, *cp;
  struct _Surf *Support;
  CylParam Cyl;
  Grid_T Grid;  // fast search grid
  ExtrudeParams *Extrude;
  STL_Data *STL; // stl representation of the surface
  POLY_rep *thePolyRep;
  int Dirty; // flag to prevent any meshing
  DrawingColor Color;
  VertexArray * TriVertexArray;
  VertexArray * QuadVertexArray;
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

typedef struct{
  Face F;
  Face Sorted;
  Simplex *S[2];
  int N;
}FxE;

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
  Tree_T *Edges;
  Tree_T *Faces;
  Tree_T *Simplexes;
  Tree_T *Simp_Surf; // for old extrusion mesh generator
  Tree_T *Quad_Surf; // for old extrusion mesh generator
  Tree_T *Hexahedra;
  Tree_T *Prisms;
  Tree_T *Pyramids;
  int Dirty; //flag to prevent any meshing
  DrawingColor Color;
}Volume;

typedef struct {
  Edge e1, e2;
  int iFac;
}exf_T;

// Edge-Simplex intersections

typedef struct{
  int NbIntersect;      // nombre total d'intersections
  Edge *e;              // arete
  Simplex *s;           // simplexe
  Face *f;              // face
  int NbVertex;         // nombre de noeuds du simplexe que coupe l'arete
  Vertex *V[12];        // noeuds du simplexe que coupe l'arete
  int iV[12];           // noeuds du simplexe que coupe l'arete
  int NbEdge;           // nombre d'intersections arete-arete
  int E[12];            // aretes
  Vertex *VE[12];       // noeuds d'intersection
  int NbFace;           // nombre d'intersections face-arete
  Face *F[12];          // faces
  int iF[12];           // faces
  Vertex *VF[12];       // position des points d'intersections face-arete
}Intersection;

typedef struct _Mesh Mesh;

typedef struct{
  int Typ;
  double lc;
  List_T *bgm;
}LcField;

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
  Tree_T *Simplexes;
  ExtrudeParams *Extrude;
  float *k, *cp;
  int degre;
  CircParam Circle;
  char functu[256], functv[256], functw[256];
  int Dirty; // flag to prevent any meshing
  DrawingColor Color;
}Curve;

typedef struct{
  int Num;
  int Typ;
  Vertex *v;
  Curve *c;
  Surface *s;
  double lc1, lc2;
  double Radius;
}Attractor;

#include "Metric.h"

#define QUALITY_EDGES_BASED 1
#define QUALITY_SIMPLEX_BASED 2
#define DELAUNAY_ISO 1
#define DELAUNAY_ANISO 2
#define DELAUNAY_TRIANGLE 3
#define FRONTAL_NETGEN 4

struct _Mesh{
  char name[256];
  int status; // current state of the mesh
  Tree_T *Points;
  Tree_T *Vertices;
  Tree_T *Simplexes;
  Tree_T *Curves;
  Tree_T *Surfaces;
  Tree_T *Volumes;
  Tree_T *SurfaceLoops;
  Tree_T *EdgeLoops;
  List_T *PhysicalGroups;
  List_T *Partitions;
  Grid_T Grid; // fast search grid
  LcField BGM; // background mesh
  double timing[3]; // timing for 1d, 2d and 3d mesh
  double quality_gamma[3]; // mesh quality statistics
  double quality_eta[3]; // mesh quality statistics
  double quality_rho[3]; // mesh quality statistics
  int Histogram[3][NB_HISTOGRAM]; // quality histograms
  GMSHMetric *Metric;
  int MaxPointNum, MaxLineNum, MaxLineLoopNum, MaxSurfaceNum;
  int MaxSurfaceLoopNum, MaxVolumeNum, MaxPhysicalNum;
};

typedef struct {
  Simplex *S;
  Face F;
  int NumFaceSimpl;
}SxF;

struct Map{
  int Num;
  List_T *List;
};


// public functions

void mai3d(Mesh * M, int Asked);

void Init_Mesh(Mesh * M);
void Create_BgMesh(int i, double d, Mesh * m);
void Print_Geo(Mesh * M, char *c);
void Print_Mesh(Mesh * M, char *c, int Type);
void Read_Mesh(Mesh * M, FILE *fp, char *filename, int Type);
void GetStatistics(double s[50]);

void Maillage_Dimension_1(Mesh *M);
void Maillage_Dimension_2(Mesh *M);
void Maillage_Dimension_3(Mesh *M);

void Maillage_Curve(void *data, void *dummy);
void Maillage_Surface(void *data, void *dum);
void Maillage_Volume(void *data, void *dum);

int Extrude_Mesh(Curve * c);
int Extrude_Mesh(Surface * s);
int Extrude_Mesh(Volume * v);
int Extrude_Mesh(Tree_T * Volumes);
void ExitExtrude();
void Extrude_Mesh_Old(Mesh *M);

int MeshTransfiniteSurface(Surface *sur);
int MeshTransfiniteVolume(Volume *vol);
int MeshCylindricalSurface(Surface * s);
int MeshParametricSurface(Surface * s);
int MeshEllipticSurface(Surface * sur);

int AlgorithmeMaillage2DAnisotropeModeJF(Surface * s);
void Maillage_Automatique_VieuxCode(Surface * pS, Mesh * m, int ori);
int Mesh_Triangle(Surface *s);
int Mesh_Netgen(Volume * v);
void Optimize_Netgen(Volume * v);
void Optimize_Netgen(Mesh * m);

int Calcule_Contours(Surface * s);
void Link_Simplexes(List_T * Sim, Tree_T * Tim);
void Calcule_Z(void *data, void *dum);
void Calcule_Z_Plan(void *data, void *dum);
void Projette_Plan_Moyen(void *a, void *b);
void Projette_Inverse(void *a, void *b);
void Freeze_Vertex(void *a, void *b);
void deFreeze_Vertex(void *a, void *b);
void ReOrientSurfaceMesh(Surface *s);

double Lc_XYZ(double X, double Y, double Z, Mesh * m);
void ActionLiss(void *data, void *dummy);
void ActionLissSurf(void *data, void *dummy);
int Recombine(Tree_T *TreeAllVert, Tree_T *TreeAllSimp, Tree_T *TreeAllQuad,
		double a);
void ApplyLcFactor(Mesh *M);
void ExportLcFieldOnVolume(Mesh * M, char *filename);
void ExportLcFieldOnSurfaces(Mesh * M, char *filename);

void Degre1();
void Degre2(int dim);
void Degre2_Curve(void *a, void *b);
void Degre2_Surface(void *a, void *b);

void Gamma_Maillage(Mesh * m, double *gamma, double *gammamax, double *gammamin);
void Eta_Maillage(Mesh * m, double *gamma, double *gammamax, double *gammamin);
void R_Maillage(Mesh * m, double *gamma, double *gammamax, double *gammamin);
void Mesh_Quality(Mesh *m);
void Print_Histogram(int *h);

#endif
