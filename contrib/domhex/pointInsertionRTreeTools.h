// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
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
#include "rtree.h"

static const double k1 = 0.61; // k1*h is the minimal distance between two nodes
static const double k2 = 0.5; // k2*h is the minimal distance to the boundary
static const double sqrt3 = 1.73205081;
static const double FACTOR = .71;

static const int NUMDIR = 1;
static const double DIRS[NUMDIR] = {0.0};

// static const int NUMDIR = 3;
// static const double DIRS [NUMDIR] = {0.0, M_PI/20.,-M_PI/20.};

class surfacePointWithExclusionRegion {
public:
  MVertex *_v;
  SPoint2 _center;
  SPoint2 _p[4][NUMDIR];
  SPoint2 _q[4];
  SMetric3 _meshMetric;
  double _distanceSummed;
  /*
     + p3
     p4   |
     +----c-----+ p2
     |
     + p1

   */
  surfacePointWithExclusionRegion(
    MVertex *v, SPoint2 p[4][NUMDIR], SPoint2 &_mp, SMetric3 &meshMetric,
    surfacePointWithExclusionRegion *father = nullptr);

  bool inExclusionZone(const SPoint2 &p);
  void minmax(double _min[2], double _max[2]) const;
  void print(FILE *f, int i);
};

class my_wrapper {
public:
  bool _tooclose;
  SPoint2 _p;
  my_wrapper(const SPoint2 &sp);
};

struct smoothness_point_pair {
  double rank;
  surfacePointWithExclusionRegion *ptr;
};

class compareSurfacePointWithExclusionRegionPtr_Smoothness {
public:
  inline bool operator()(const smoothness_point_pair &a,
                         const smoothness_point_pair &b) const
  {
    if(a.rank == b.rank) {
      if(a.ptr->_distanceSummed > b.ptr->_distanceSummed) return false;
      if(a.ptr->_distanceSummed < b.ptr->_distanceSummed) return true;
      return a.ptr < b.ptr;
    }
    return (a.rank < b.rank);
  }
};

class compareSurfacePointWithExclusionRegionPtr {
public:
  inline bool operator()(const surfacePointWithExclusionRegion *a,
                         const surfacePointWithExclusionRegion *b) const
  {
    if(a->_distanceSummed > b->_distanceSummed) return false;
    if(a->_distanceSummed < b->_distanceSummed) return true;
    return a < b;
  }
};

extern bool rtree_callback(surfacePointWithExclusionRegion *neighbour,
                           void *point);

extern bool inExclusionZone(
  SPoint2 &p,
  RTree<surfacePointWithExclusionRegion *, double, 2, double> &rtree,
  std::vector<surfacePointWithExclusionRegion *> &all);

class Wrapper3D {
private:
  static frameFieldBackgroundMesh3D *bgmesh;
  MVertex *individual, *parent;
  double *size;
  STensor3 *cf;
  SVector3 *vec;
  bool ok;

public:
  Wrapper3D()
    : individual(nullptr), parent(nullptr), size(nullptr), cf(nullptr),
      vec(nullptr), ok(true)
  {
  }
  Wrapper3D(MVertex *_i, MVertex *_p)
    : individual(_i), parent(_p), size(nullptr), cf(nullptr), vec(nullptr),
      ok(true)
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
  smoothness_vertex_pair() : rank(0.), size(0.), v(nullptr), dir(0), layer(0) {}
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
