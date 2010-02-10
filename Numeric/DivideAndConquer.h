// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
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
 private:
  PointNumero Predecessor(PointNumero a, PointNumero b);
  PointNumero Successor(PointNumero a, PointNumero b);
  int FixFirst(PointNumero x, PointNumero f);
  PointNumero First(PointNumero x);
  int IsLeftOf(PointNumero x, PointNumero y, PointNumero check);
  int IsRightOf(PointNumero x, PointNumero y, PointNumero check);
  Segment LowerCommonTangent(DT vl, DT vr);
  Segment UpperCommonTangent(DT vl, DT vr);
  int Qtest(PointNumero h, PointNumero i, PointNumero j, PointNumero k);
  int Merge(DT vl, DT vr);
  DT RecurTrig(PointNumero left, PointNumero right);
  int BuildDelaunay();
  int DListInsert(DListRecord **dlist, DPoint center, PointNumero newPoint);
  int Insert(PointNumero a, PointNumero b);
  int DListDelete(DListPeek *dlist, PointNumero oldPoint);
  int Delete(PointNumero a, PointNumero b);
  int CountPointsOnHull(int n);
  PointNumero *ConvertDlistToArray(DListPeek *dlist, int *n);
  int ConvertDListToTriangles();
  void RemoveAllDList();
 public:
  int numPoints;        // number of points
  PointRecord *points;  // points to triangulate
  int numTriangles;     // number of triangles
  Triangle *triangles;  // 2D results
  DocRecord(int n);
  double &x(int i){ return points[i].where.v; } 
  double &y(int i){ return points[i].where.h; } 
  ~DocRecord();
  void MakeMeshWithPoints();
};

#endif
