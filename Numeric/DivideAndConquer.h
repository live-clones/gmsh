// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _DIVIDE_AND_CONQUER_H_
#define _DIVIDE_AND_CONQUER_H_

#include <vector>
#include <algorithm>
#include "fullMatrix.h"

// FIXME: should not introduce dependencies to Geo/ code in Numeric!
#include "SPoint2.h"
#include "simpleFunction.h"
#include "Octree.h"

class GFace;
typedef struct _CDLIST DListRecord, *DListPeek;
typedef int PointNumero;

typedef struct{
  double v;
  double h;
}DPoint;

struct PointRecord {
  DPoint where;
  DListPeek adjacent;
  void *data;
  int flag; //0:to be kept, 1:to be removed
  int identificator;
  std::vector<void*> vicinity;
  PointRecord() : adjacent(0), data (0) {}
};

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
  int _hullSize;
  PointNumero *_hull;
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
  int DListInsert(DListRecord **dlist, DPoint center, PointNumero newPoint);
  int Insert(PointNumero a, PointNumero b);
  int DListDelete(DListPeek *dlist, PointNumero oldPoint);
  int Delete(PointNumero a, PointNumero b);
  void ConvertDListToVoronoiData();
  int ConvertDListToTriangles();
  void RemoveAllDList();
  int BuildDelaunay();
  int CountPointsOnHull();
  void ConvexHull();
 public:
  STriangle *_adjacencies;
  int numPoints;        // number of points
  int size_points;
  PointRecord *points;  // points to triangulate
  int numTriangles;     // number of triangles
  Triangle *triangles;  // 2D results
  DocRecord(int n);
  double &x(int i){ return points[i].where.h; } 
  double &y(int i){ return points[i].where.v; } 
  void*  &data(int i){ return points[i].data; } 
  void setPoints(fullMatrix<double> *p);
  ~DocRecord();
  void MakeMeshWithPoints();
  void Voronoi ();
  int hullSize() {return _hullSize;}
  int onHull(PointNumero i) { return std::binary_search(_hull, _hull+_hullSize, i); }
  void makePosView(std::string, GFace *gf=NULL);
  void printMedialAxis(Octree *_octree, std::string, GFace *gf=NULL, GEdge *ge=NULL);
  double Lloyd (int);
  void voronoiCell (PointNumero pt, std::vector<SPoint2> &pts) const;
 
  std::set<std::pair<void*,void*> > boundaryEdges;

  void addBoundaryEdge(void* p1,void* p2)
  {
    void *a = (p1 < p2) ? p1 : p2;
    void *b = (p1 > p2) ? p1 : p2;
    boundaryEdges.insert(std::make_pair(a,b));
  }
  bool lookForBoundaryEdge(void* p1,void* p2)
  {
    void *a = (p1 < p2) ? p1 : p2;
    void *b = (p1 > p2) ? p1 : p2;
    std::set<std::pair<void*,void*> >::iterator it = 
      boundaryEdges.find(std::make_pair(a,b));
    return it != boundaryEdges.end();
  } 	
 
  void recur_tag_triangles(int, std::set<int>&, std::map<std::pair<void*,void*>,
                           std::pair<int,int> >&);
  std::set<int> tagInterior(double,double);
  void concave(double,double,GFace*);
  bool contain(int,int,int);
  void add(int,int);

  void initialize();
  bool remove_point(int);
  void remove_all();
  void add_point(double,double,GFace*);
	
  std::set<std::pair<void*,void*> > mesh_edges;
	
  void add_edge(void* p1,void* p2)
  {
    void *a = (p1 < p2) ? p1 : p2;
    void *b = (p1 > p2) ? p1 : p2;
    mesh_edges.insert(std::make_pair(a,b));
  }
  bool find_edge(void* p1,void* p2)
  {
    void *a = (p1 < p2) ? p1 : p2;
    void *b = (p1 > p2) ? p1 : p2;
    std::set<std::pair<void*,void*> >::iterator it = 
      mesh_edges.find(std::make_pair(a,b));
    return it != mesh_edges.end();
  } 	
	
  void build_edges();
  void clear_edges();
  bool delaunay_conformity(GFace*);		
	
  PointNumero *ConvertDlistToArray(DListPeek *dlist, int *n);
};

void centroidOfOrientedBox(std::vector<SPoint2> &pts,
                           const double &angle,
                           double &xc, 
                           double &yc, 
                           double &inertia, 
			   double &area);
void centroidOfPolygon(SPoint2 &pc,
                       std::vector<SPoint2> &pts,
                       double &xc, 
                       double &yc,
                       double &inertia,
		       double &areaCell,
                       simpleFunction<double> *bgm = 0);

#endif
