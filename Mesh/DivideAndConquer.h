// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _DIVIDE_AND_CONQUER_H_
#define _DIVIDE_AND_CONQUER_H_

typedef struct _CDLIST DListRecord, *DListPeek;
typedef int PointNumero;

typedef struct{
  double v;
  double h;
}DPoint;

typedef struct{
  DPoint where;
  DListPeek adjacent;
  void *data;
}PointRecord;

struct _CDLIST{
  PointNumero point_num;
  DListPeek next, prev;
};

typedef struct{
  PointNumero *t;
  int t_length;
}STriangle;

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
}Triangle;


class DocRecord{
 public:
  int numPoints;        // number of points
  PointRecord *points;  // points to triangulate
  int numTriangles;     // number of triangles
  Triangle *triangles;  // 2D results
  STriangle *striangle; // connected points
  DocRecord(int n);
  double & x(int i)
  {return points[i].where.v;} 
  double & y(int i)
  {return points[i].where.h;} 
  ~DocRecord();
  void MakeMeshWithPoints();
  void MakeVoronoi();
};

#endif
