// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Tristan Carrier and Paul-Emile Bernard

#ifndef POINTINSERTIONRTREETOOLS_H
#define POINTINSERTIONRTREETOOLS_H

#include <cmath>
#include <queue>
#include "MVertex.h"
#include "STensor3.h"
#include "BackgroundMesh3D.h"
#include "GEntity.h"
#include "GFace.h"
#include "rtree.h"

static const double k1 = 0.61; // k1*h is the minimal distance between two nodes
static const double k2 = 0.5; // k2*h is the minimal distance to the boundary
static const double sqrt3 = 1.73205081;
static const double FACTOR = .61;

//static const int NUMDIR = 1;
//static const double DIRS[NUMDIR] = {0.0};

// static const int NUMDIR = 3;
// static const double DIRS [NUMDIR] = {0.0, M_PI/20.,-M_PI/20.};

class surfacePointWithExclusionRegion {
public:
  MVertex *_v;
  MVertex *_father;
  SPoint2 _center;
  SPoint2 _p[4];
  SPoint2 _q[4];
  SMetric3 _meshMetric;
  /*
     + p3
     p4   |
     +----c-----+ p2
     |
     + p1

   */
  surfacePointWithExclusionRegion(MVertex *v, SPoint2 p[8],
                                  SPoint2 &_mp, SMetric3 &meshMetric,
                                  surfacePointWithExclusionRegion *father = 0);

  bool inExclusionZone(const SPoint2 &p, MVertex *v);
  void minmax(double _min[2], double _max[2]) const;
  void print(FILE *f, int i);
};

class my_wrapper {
public:
  bool _tooclose;
  MVertex *_parent;
  SPoint2 _p;
  my_wrapper(const SPoint2 &sp, MVertex *parent) :
  _p(sp), _parent(parent), _tooclose(false){}
};

 bool rtree_callback(surfacePointWithExclusionRegion *neighbour,
		     void *point);

bool inExclusionZone(MVertex *parent,
		     SPoint2 &p,
		     RTree<surfacePointWithExclusionRegion *, double, 2, double> &rtree);

class Wrapper3D {
private:
  static frameFieldBackgroundMesh3D *bgmesh;
  MVertex *individual, *parent;
  double *size;
  STensor3 *cf;
  SVector3 *vec;
  bool ok;

public:
  Wrapper3D() : individual(0), parent(0), size(0), cf(0), vec(0), ok(true) {}
  Wrapper3D(MVertex *_i, MVertex *_p)
    : individual(_i), parent(_p), size(0), cf(0), vec(0), ok(true)
  {
  }
  ~Wrapper3D() {}
  void set_ok(bool b) { ok = b; }
  void set_individual(MVertex *vertex) { individual = vertex; }
  void set_parent(MVertex *vertex) { parent = vertex; }
  void set_size(double *h) { size = h; }
  void set_crossfield(STensor3 *_cf) { cf = _cf; }
  void set_direction(SVector3 *_v) { vec = _v; }
  bool get_ok() { return ok; }
  void set_bgm(frameFieldBackgroundMesh3D *bgm) { bgmesh = bgm; }
  frameFieldBackgroundMesh3D *bgm() { return bgmesh; }
  MVertex *get_individual() { return individual; }
  MVertex *get_parent() { return parent; }
  STensor3 *get_crossfield() { return cf; }
  SVector3 *get_direction() { return vec; }
  double *get_size() { return size; }
};

extern double infinity_distance_3D(const MVertex *v1, const MVertex *v2,
                                   STensor3 &cf);
extern bool rtree_callback_3D(MVertex *neighbour, void *w);
extern bool far_from_boundary_3D(frameFieldBackgroundMesh3D *bgm, MVertex *v,
                                 double h);
extern void fill_min_max(double x, double y, double z, double h, double *min,
                         double *max);

// TODO: this is not a pair anymore, the name has to be changed; this will be in
// listOfPoints AND in RTree: larger memory footprint but less CPU time...
class smoothness_vertex_pair {
public:
  smoothness_vertex_pair() : rank(0.), size(0.), v(0), dir(0), layer(0) {}
  ~smoothness_vertex_pair() {}
  STensor3 cf;
  SVector3 direction;
  double rank, size;
  MVertex *v;
  int dir, layer;
};

class compareSmoothnessVertexPairs {
private:
  const double threshold;
  double roundit(const double &d) const
  {
    // return (round(d/threshold)*threshold);
    return ((int)(d / threshold + 0.5) * threshold);
  }

public:
  compareSmoothnessVertexPairs() : threshold(0.05){};

  inline bool operator()(const smoothness_vertex_pair *a,
                         const smoothness_vertex_pair *b) const
  {
    if(a->rank == b->rank) return (a->v < b->v);
    return (a->rank > b->rank);
  }
};

class listOfPoints {
public:
  listOfPoints(){};
  virtual ~listOfPoints(){};
  virtual void insert(smoothness_vertex_pair *svp) = 0;
  virtual unsigned int size() = 0;
  virtual MVertex *get_first_vertex() = 0;
  virtual STensor3 get_first_crossfield() = 0;
  virtual double get_first_size() = 0;
  virtual int get_first_layer() = 0;
  virtual SVector3 get_first_direction() = 0;
  virtual void erase_first() = 0;
  virtual bool empty() = 0;
};

class listOfPointsScalarSmoothness : public listOfPoints {
public:
  listOfPointsScalarSmoothness() {}
  virtual ~listOfPointsScalarSmoothness()
  {
    while(!empty()) erase_first();
  }
  virtual void insert(smoothness_vertex_pair *svp) { points.insert(svp); }
  virtual unsigned int size() { return points.size(); }
  virtual MVertex *get_first_vertex() { return (*points.begin())->v; }
  virtual STensor3 get_first_crossfield() { return (*points.begin())->cf; }
  virtual double get_first_size() { return (*points.begin())->size; }
  virtual int get_first_layer() { return (*points.begin())->layer; }
  virtual SVector3 get_first_direction()
  {
    Msg::Error(
      "listOfPointsScalarSmoothness::get_first_direction NOT applicable");
    return SVector3(0.);
  }
  virtual void erase_first()
  {
    smoothness_vertex_pair *ptr = *(points.begin());
    points.erase(points.begin());
    delete ptr;
  }
  virtual bool empty() { return points.empty(); }

protected:
  std::set<smoothness_vertex_pair *, compareSmoothnessVertexPairs> points;
};

class listOfPointsVectorialSmoothness : public listOfPointsScalarSmoothness {
public:
  listOfPointsVectorialSmoothness() {}
  virtual ~listOfPointsVectorialSmoothness()
  {
    while(!empty()) erase_first();
  }
  virtual SVector3 get_first_direction()
  {
    return (*points.begin())->direction;
  }

protected:
  std::set<smoothness_vertex_pair *, compareSmoothnessVertexPairs> points;
};

class listOfPointsFifo : public listOfPoints {
public:
  listOfPointsFifo(){};
  virtual ~listOfPointsFifo()
  {
    while(!empty()) erase_first();
  };
  virtual void insert(smoothness_vertex_pair *svp) { points.push(svp); }
  virtual unsigned int size() { return points.size(); }
  virtual MVertex *get_first_vertex() { return (points.front())->v; }
  virtual STensor3 get_first_crossfield() { return (points.front())->cf; }
  virtual double get_first_size() { return (points.front())->size; }
  virtual int get_first_layer() { return (points.front())->layer; }
  virtual SVector3 get_first_direction()
  {
    Msg::Error("listOfPointsFifo::get_first_direction NOT applicable");
    return SVector3(0.);
  }
  virtual void erase_first()
  {
    smoothness_vertex_pair *ptr = points.front();
    points.pop();
    delete ptr;
  }
  virtual bool empty() { return points.empty(); }

protected:
  std::queue<smoothness_vertex_pair *> points;
};

#endif
