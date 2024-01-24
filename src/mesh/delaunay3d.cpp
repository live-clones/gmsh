// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#if defined(_OPENMP)
#include <omp.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <stack>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include "SPoint3.h"
#include "SBoundingBox3d.h"
#include "delaunay3d.h"
#include "MVertex.h"
#include "MTetrahedron.h"
#include "meshGRegionLocalMeshMod.h"
#include "Context.h"
#include "robustPredicates.h"
#include "OS.h"

#ifndef MAX_NUM_THREADS_
#define MAX_NUM_THREADS_ 8
#endif

typedef unsigned char CHECKTYPE;
struct Tet;

struct Vert {
private:
  double _x[3];
  double _lc;
  std::size_t _num;
  Tet *_t;

public:
  inline void setT(Tet *t) { _t = t; }
  inline Tet *getT() const { return _t; }
  inline std::size_t getNum() const { return _num; }
  inline void setNum(std::size_t n) { _num = n; }
  unsigned char _thread;
  inline double x() const { return _x[0]; }
  inline double y() const { return _x[1]; }
  inline double z() const { return _x[2]; }
  inline double lc() const { return _lc; }
  inline double &x() { return _x[0]; }
  inline double &y() { return _x[1]; }
  inline double &z() { return _x[2]; }
  inline double &lc() { return _lc; }
  inline operator double *() { return _x; }
  Vert(double X = 0, double Y = 0, double Z = 0, double lc = 0, int num = 0)
    : _num(num), _t(nullptr), _thread(0)
  {
    _x[0] = X;
    _x[1] = Y;
    _x[2] = Z;
    _lc = lc;
  }
  Vert operator+(const Vert &other)
  {
    return Vert(x() + other.x(), y() + other.y(), z() + other.z(),
                other.lc() + _lc);
  }
  Vert operator*(const double &other)
  {
    return Vert(x() * other, y() * other, z() * other, _lc * other);
  }
  SPoint3 point() const { return SPoint3(x(), y(), z()); }
};

static double orientationTestFast(double *pa, double *pb, double *pc,
                                  double *pd)
{
  const double adx = pa[0] - pd[0];
  const double bdx = pb[0] - pd[0];
  const double cdx = pc[0] - pd[0];
  const double ady = pa[1] - pd[1];
  const double bdy = pb[1] - pd[1];
  const double cdy = pc[1] - pd[1];
  const double adz = pa[2] - pd[2];
  const double bdz = pb[2] - pd[2];
  const double cdz = pc[2] - pd[2];

  return adx * (bdy * cdz - bdz * cdy) + bdx * (cdy * adz - cdz * ady) +
         cdx * (ady * bdz - adz * bdy);
}

static bool inSphereTest_s(Vert *va, Vert *vb, Vert *vc, Vert *vd, Vert *ve)
{
  double val = robustPredicates::insphere(
    (double *)va, (double *)vb, (double *)vc, (double *)vd, (double *)ve);
  if(val == 0.0) {
    Msg::Info("Symbolic perturbation needed vol %22.15E",
              orientationTestFast((double *)va, (double *)vb, (double *)vc,
                                  (double *)vd));
    int count;
    // symbolic perturbation
    Vert *pt[5] = {va, vb, vc, vd, ve};
    int swaps = 0;
    int n = 5;
    do {
      count = 0;
      n = n - 1;
      for(int i = 0; i < n; i++) {
        if(pt[i] > pt[i + 1]) {
          Vert *swappt = pt[i];
          pt[i] = pt[i + 1];
          pt[i + 1] = swappt;
          count++;
        }
      }
      swaps += count;
    } while(count > 0);
    double oriA = robustPredicates::orient3d((double *)pt[1], (double *)pt[2],
                                             (double *)pt[3], (double *)pt[4]);
    if(oriA != 0.0) {
      // Flip the sign if there are odd number of swaps.
      if((swaps % 2) != 0) oriA = -oriA;
      val = oriA;
    }
    else {
      double oriB = -robustPredicates::orient3d(
        (double *)pt[0], (double *)pt[2], (double *)pt[3], (double *)pt[4]);
      if(oriB == 0.0) {
        Msg::Error("Symbolic perturbation failed in icCircle Predicate");
      }
      // Flip the sign if there are odd number of swaps.
      if((swaps % 2) != 0) oriB = -oriB;
      val = oriB;
    }
  }
  return val > 0;
}

struct Face {
  Vert *v[3];
  Vert *V[3];
  Face(Vert *v1, Vert *v2, Vert *v3)
  {
    V[0] = v[0] = v1;
    V[1] = v[1] = v2;
    V[2] = v[2] = v3;
#define cswap(a, b)                                                            \
  do {                                                                         \
    if(a > b) {                                                                \
      Vert *tmp = a;                                                           \
      a = b;                                                                   \
      b = tmp;                                                                 \
    }                                                                          \
  } while(0)
    cswap(v[0], v[1]);
    cswap(v[1], v[2]);
    cswap(v[0], v[1]);
  }

  bool operator==(const Face &other) const
  {
    return v[0] == other.v[0] && v[1] == other.v[1] && v[2] == other.v[2];
  }

  bool operator<(const Face &other) const
  {
    if(v[0] < other.v[0]) return true;
    if(v[0] > other.v[0]) return false;
    if(v[1] < other.v[1]) return true;
    if(v[1] > other.v[1]) return false;
    if(v[2] < other.v[2]) return true;
    return false;
  }
};

struct Tet {
  Tet *T[4];
  Vert *V[4];
  CHECKTYPE _bitset[MAX_NUM_THREADS_];
  bool _modified;

  Tet() : _modified(true)
  {
    V[0] = V[1] = V[2] = V[3] = nullptr;
    T[0] = T[1] = T[2] = T[3] = nullptr;
    setAllDeleted();
  }
  int setVerticesNoTest(Vert *v0, Vert *v1, Vert *v2, Vert *v3)
  {
    _modified = true;
    V[0] = v0;
    V[1] = v1;
    V[2] = v2;
    V[3] = v3;
    for(int i = 0; i < 4; i++)
      if(V[i]) V[i]->setT(this);
    return 1;
  }
  int setVertices(Vert *v0, Vert *v1, Vert *v2, Vert *v3)
  {
    _modified = true;
    double val = robustPredicates::orient3d((double *)v0, (double *)v1,
                                            (double *)v2, (double *)v3);
    V[0] = v0;
    V[1] = v1;
    V[2] = v2;
    V[3] = v3;
    for(int i = 0; i < 4; i++)
      if(V[i]) V[i]->setT(this);
    if(val > 0) { return 1; }
    else if(val < 0) {
      V[0] = v1;
      V[1] = v0;
      V[2] = v2;
      V[3] = v3;
      return -1;
    }
    else {
      return 0;
    }
  }
  Tet(Vert *v0, Vert *v1, Vert *v2, Vert *v3)
  {
    setVertices(v0, v1, v2, v3);
    T[0] = T[1] = T[2] = T[3] = nullptr;
    setAllDeleted();
  }
  void setAllDeleted()
  {
    for(int i = 0; i < MAX_NUM_THREADS_; i++) _bitset[i] = 0x0;
  }
  void unset(int thread, int iPnt) { _bitset[thread] &= ~(1 << iPnt); }
  void set(int thread, int iPnt) { _bitset[thread] |= (1 << iPnt); }
  CHECKTYPE isSet(int thread, int iPnt) const
  {
    return _bitset[thread] & (1 << iPnt);
  }
  Face getFace(int k) const
  {
    const int fac[4][3] = {{0, 1, 2}, {1, 3, 2}, {2, 3, 0}, {1, 0, 3}};
    return Face(V[fac[k][0]], V[fac[k][1]], V[fac[k][2]]);
  }
  Vert *getOppositeVertex(int k) const
  {
    const int o[4] = {3, 0, 1, 2};
    return V[o[k]];
  }
  bool inSphere(Vert *vd, int thread)
  {
    return inSphereTest_s(V[0], V[1], V[2], V[3], vd);
  }
};

struct conn {
  Face f;
  int i;
  Tet *t;
  conn() : f(nullptr, nullptr, nullptr), i(0), t(nullptr) {}
  conn(Face _f, int _i, Tet *_t) : f(_f), i(_i), t(_t) {}
  bool operator==(const conn &c) const { return f == c.f; }
  bool operator<(const conn &c) const { return f < c.f; }
};

// tetrahedra (one per thread)
template <class T> class aBunchOfStuff {
public:
  std::vector<T *> _all;
  std::size_t _current;
  std::size_t _nbAlloc;
  std::size_t size() { return _current + (_all.size() - 1) * _nbAlloc; }

public:
  T *operator()(std::size_t i)
  {
    const std::size_t _array = i / _nbAlloc;
    const std::size_t _offset = i % _nbAlloc;
    return _all[_array] + _offset;
  }
  aBunchOfStuff(std::size_t s) : _current(0), _nbAlloc(s)
  {
    if(!_nbAlloc) _nbAlloc = 1;
    _all.push_back(new T[_nbAlloc]);
  }
  ~aBunchOfStuff()
  {
    for(std::size_t i = 0; i < _all.size(); i++) { delete[] _all[i]; }
  }
  T *newStuff()
  {
    if(_current == _nbAlloc) {
      _all.push_back(new T[_nbAlloc]);
      _current = 0;
    }
    _current++;
    return _all[_all.size() - 1] + (_current - 1);
  }
};

// tetAllocator owns the tets that have been allocated by itself
class tetContainer {
  std::vector<aBunchOfStuff<Tet> *> _perThread;

public:
  std::size_t size(int thread) const
  {
    if((int)_perThread.size() <= thread) return 0;
    return _perThread[thread]->size();
  }
  Tet *operator()(int thread, int j) const { return (*_perThread[thread])(j); }
  tetContainer(int nbThreads, int preallocSizePerThread)
  {
    _perThread.resize(nbThreads);
    for(std::size_t i = 0; i < _perThread.size(); i++) {
      _perThread[i] = new aBunchOfStuff<Tet>(preallocSizePerThread);
    }
  }
  Tet *newTet(int thread) { return _perThread[thread]->newStuff(); }
  ~tetContainer()
  {
    for(std::size_t i = 0; i < _perThread.size(); i++) delete _perThread[i];
  }
};

typedef std::vector<Tet *> cavityContainer;
typedef std::vector<conn> connContainer;

struct HilbertSortB {
  // The code for generating table transgc from:
  // http://graphics.stanford.edu/~seander/bithacks.html.
  int transgc[8][3][8];
  int tsb1mod3[8];
  int maxDepth;
  int Limit;
  SBoundingBox3d bbox;
  void ComputeGrayCode(int n);
  int Split(Vert **vertices, int arraysize, int GrayCode0, int GrayCode1,
            double BoundingBoxXmin, double BoundingBoxXmax,
            double BoundingBoxYmin, double BoundingBoxYmax,
            double BoundingBoxZmin, double BoundingBoxZmax);
  void Sort(Vert **vertices, int arraysize, int e, int d,
            double BoundingBoxXmin, double BoundingBoxXmax,
            double BoundingBoxYmin, double BoundingBoxYmax,
            double BoundingBoxZmin, double BoundingBoxZmax, int depth);
  HilbertSortB(int m = 0, int l = 2) : maxDepth(m), Limit(l)
  {
    ComputeGrayCode(3);
  }
  void MultiscaleSortHilbert(Vert **vertices, int arraysize, int threshold,
                             double ratio, int *depth,
                             std::vector<int> &indices)
  {
    int middle = 0;
    if(arraysize >= threshold) {
      (*depth)++;
      middle = (int)(arraysize * ratio);
      MultiscaleSortHilbert(vertices, middle, threshold, ratio, depth, indices);
    }
    indices.push_back(middle);
    Sort(&(vertices[middle]), arraysize - middle, 0, 0, bbox.min().x(),
         bbox.max().x(), bbox.min().y(), bbox.max().y(), bbox.min().z(),
         bbox.max().z(), 0);
  }
  void Apply(std::vector<Vert *> &v, std::vector<int> &indices)
  {
    indices.clear();
    if(v.empty()) return;
    for(size_t i = 0; i < v.size(); i++) {
      Vert *pv = v[i];
      bbox += SPoint3(pv->x(), pv->y(), pv->z());
    }
    bbox *= 1.01;
    Vert **pv = &v[0];
    int depth;
    indices.clear();
    MultiscaleSortHilbert(pv, (int)v.size(), 64, .125, &depth, indices);
    indices.push_back(v.size());
  }
};

void HilbertSortB::ComputeGrayCode(int n)
{
  int gc[8], N, mask, travel_bit;
  int e, d, f, k, g;
  int v, c;
  int i;

  N = (n == 2) ? 4 : 8;
  mask = (n == 2) ? 3 : 7;

  // Generate the Gray code sequence.
  for(i = 0; i < N; i++) { gc[i] = i ^ (i >> 1); }

  for(e = 0; e < N; e++) {
    for(d = 0; d < n; d++) {
      // Calculate the end point (f).
      f = e ^ (1 << d); // Toggle the d-th bit of 'e'.
      // travel_bit = 2**p, the bit we want to travel.
      travel_bit = e ^ f;
      for(i = 0; i < N; i++) {
        // // Rotate gc[i] left by (p + 1) % n bits.
        k = gc[i] * (travel_bit * 2);
        g = ((k | (k / N)) & mask);
        // Calculate the permuted Gray code by xor with the start point (e).
        transgc[e][d][i] = (g ^ e);
      }
      //      assert(transgc[e][d][0] == e);
      //      assert(transgc[e][d][N - 1] == f);
    } // d
  } // e

  // Count the consecutive '1' bits (trailing) on the right.
  tsb1mod3[0] = 0;
  for(i = 1; i < N; i++) {
    v = ~i; // Count the 0s.
    v = (v ^ (v - 1)) >> 1; // Set v's trailing 0s to 1s and zero rest
    for(c = 0; v; c++) { v >>= 1; }
    tsb1mod3[i] = c % n;
  }
}

int HilbertSortB::Split(Vert **vertices, int arraysize, int GrayCode0,
                        int GrayCode1, double BoundingBoxXmin,
                        double BoundingBoxXmax, double BoundingBoxYmin,
                        double BoundingBoxYmax, double BoundingBoxZmin,
                        double BoundingBoxZmax)
{
  Vert *swapvert;
  int axis, d;
  double split;

  // Find the current splitting axis. 'axis' is a value 0, or 1, or 2, which
  // correspoding to x-, or y- or z-axis.
  axis = (GrayCode0 ^ GrayCode1) >> 1;

  // Calulate the split position along the axis.
  if(axis == 0) { split = 0.5 * (BoundingBoxXmin + BoundingBoxXmax); }
  else if(axis == 1) {
    split = 0.5 * (BoundingBoxYmin + BoundingBoxYmax);
  }
  else { // == 2
    split = 0.5 * (BoundingBoxZmin + BoundingBoxZmax);
  }

  // Find the direction (+1 or -1) of the axis. If 'd' is +1, the direction of
  // the axis is to the positive of the axis, otherwise, it is -1.
  d = ((GrayCode0 & (1 << axis)) == 0) ? 1 : -1;

  // Partition the vertices into left- and right-arrays such that left points
  // have Hilbert indices lower than the right points.
  int i = 0;
  int j = arraysize - 1;

  // Partition the vertices into left- and right-arrays.
  if(d > 0) {
    do {
      for(; i < arraysize; i++) {
        if(vertices[i]->point()[axis] >= split) break;
      }
      for(; j >= 0; j--) {
        if(vertices[j]->point()[axis] < split) break;
      }
      // Is the partition finished?
      if(i >= (j + 1)) break;
      // Swap i-th and j-th vertices.
      swapvert = vertices[i];
      vertices[i] = vertices[j];
      vertices[j] = swapvert;
      // Continue patitioning the array;
    } while(true);
  }
  else {
    do {
      for(; i < arraysize; i++) {
        if(vertices[i]->point()[axis] <= split) break;
      }
      for(; j >= 0; j--) {
        if(vertices[j]->point()[axis] > split) break;
      }
      // Is the partition finished?
      if(i >= (j + 1)) break;
      // Swap i-th and j-th vertices.
      swapvert = vertices[i];
      vertices[i] = vertices[j];
      vertices[j] = swapvert;
      // Continue patitioning the array;
    } while(true);
  }

  return i;
}

// The sorting code is inspired by Tetgen 1.5
void HilbertSortB::Sort(Vert **vertices, int arraysize, int e, int d,
                        double BoundingBoxXmin, double BoundingBoxXmax,
                        double BoundingBoxYmin, double BoundingBoxYmax,
                        double BoundingBoxZmin, double BoundingBoxZmax,
                        int depth)
{
  double x1, x2, y1, y2, z1, z2;
  int p[9], w, e_w, d_w, k, ei, di;
  int n = 3, mask = 7;

  p[0] = 0;
  p[8] = arraysize;

  p[4] = Split(vertices, p[8], transgc[e][d][3], transgc[e][d][4],
               BoundingBoxXmin, BoundingBoxXmax, BoundingBoxYmin,
               BoundingBoxYmax, BoundingBoxZmin, BoundingBoxZmax);
  p[2] = Split(vertices, p[4], transgc[e][d][1], transgc[e][d][2],
               BoundingBoxXmin, BoundingBoxXmax, BoundingBoxYmin,
               BoundingBoxYmax, BoundingBoxZmin, BoundingBoxZmax);
  p[1] = Split(vertices, p[2], transgc[e][d][0], transgc[e][d][1],
               BoundingBoxXmin, BoundingBoxXmax, BoundingBoxYmin,
               BoundingBoxYmax, BoundingBoxZmin, BoundingBoxZmax);
  p[3] =
    Split(&(vertices[p[2]]), p[4] - p[2], transgc[e][d][2], transgc[e][d][3],
          BoundingBoxXmin, BoundingBoxXmax, BoundingBoxYmin, BoundingBoxYmax,
          BoundingBoxZmin, BoundingBoxZmax) +
    p[2];
  p[6] =
    Split(&(vertices[p[4]]), p[8] - p[4], transgc[e][d][5], transgc[e][d][6],
          BoundingBoxXmin, BoundingBoxXmax, BoundingBoxYmin, BoundingBoxYmax,
          BoundingBoxZmin, BoundingBoxZmax) +
    p[4];
  p[5] =
    Split(&(vertices[p[4]]), p[6] - p[4], transgc[e][d][4], transgc[e][d][5],
          BoundingBoxXmin, BoundingBoxXmax, BoundingBoxYmin, BoundingBoxYmax,
          BoundingBoxZmin, BoundingBoxZmax) +
    p[4];
  p[7] =
    Split(&(vertices[p[6]]), p[8] - p[6], transgc[e][d][6], transgc[e][d][7],
          BoundingBoxXmin, BoundingBoxXmax, BoundingBoxYmin, BoundingBoxYmax,
          BoundingBoxZmin, BoundingBoxZmax) +
    p[6];

  if(maxDepth > 0) {
    if((depth + 1) == maxDepth) {
      // printf("max depth attained\n");
      return;
    }
  }

  // Recursively sort the points in sub-boxes.
  for(w = 0; w < 8; w++) {
    if((p[w + 1] - p[w]) > Limit) {
      if(w == 0) { e_w = 0; }
      else {
        k = 2 * ((w - 1) / 2);
        e_w = k ^ (k >> 1);
      }
      k = e_w;
      e_w = ((k << (d + 1)) & mask) | ((k >> (n - d - 1)) & mask);
      ei = e ^ e_w;
      if(w == 0) { d_w = 0; }
      else {
        d_w = ((w % 2) == 0) ? tsb1mod3[w - 1] : tsb1mod3[w];
      }
      di = (d + d_w + 1) % n;
      if(transgc[e][d][w] & 1) {
        x1 = 0.5 * (BoundingBoxXmin + BoundingBoxXmax);
        x2 = BoundingBoxXmax;
      }
      else {
        x1 = BoundingBoxXmin;
        x2 = 0.5 * (BoundingBoxXmin + BoundingBoxXmax);
      }
      if(transgc[e][d][w] & 2) { // y-axis
        y1 = 0.5 * (BoundingBoxYmin + BoundingBoxYmax);
        y2 = BoundingBoxYmax;
      }
      else {
        y1 = BoundingBoxYmin;
        y2 = 0.5 * (BoundingBoxYmin + BoundingBoxYmax);
      }
      if(transgc[e][d][w] & 4) { // z-axis
        z1 = 0.5 * (BoundingBoxZmin + BoundingBoxZmax);
        z2 = BoundingBoxZmax;
      }
      else {
        z1 = BoundingBoxZmin;
        z2 = 0.5 * (BoundingBoxZmin + BoundingBoxZmax);
      }
      Sort(&(vertices[p[w]]), p[w + 1] - p[w], ei, di, x1, x2, y1, y2, z1, z2,
           depth + 1);
    }
  }
}

static void SortHilbert(std::vector<Vert *> &v, std::vector<int> &indices)
{
  HilbertSortB h(1000);
  h.Apply(v, indices);
}

static void computeAdjacencies(Tet *t, int iFace, connContainer &faceToTet)
{
  conn c(t->getFace(iFace), iFace, t);
  auto it = std::find(faceToTet.begin(), faceToTet.end(), c);
  if(it == faceToTet.end()) { faceToTet.push_back(c); }
  else {
    t->T[iFace] = it->t;
    it->t->T[it->i] = t;
    faceToTet.erase(it);
  }
}

/*
static void printtet(const char *c, Tet *t)
{
  printf("%s ", c);
  if(t->V[0])
    printf("%7d %7d %7d %7d\n", t->V[0]->getNum(), t->V[1]->getNum(),
           t->V[2]->getNum(), t->V[3]->getNum());
}
*/

// Fixing a non star shaped cavity (non delaunay triangulations). See
// P.L. George's paper "Improvements on Delaunay-based three-dimensional
// automatic mesh generator", Finite Elements in Analysis and Design 25 (1997)
// 297-317

static void starShapeness(Vert *v, connContainer &bndK,
                          std::vector<std::size_t> &_negatives)
{
  _negatives.clear();
  for(std::size_t i = 0; i < bndK.size(); i++) {
    // no symbolic perturbation
    const double val = robustPredicates::orient3d(
      (double *)bndK[i].f.V[0], (double *)bndK[i].f.V[1],
      (double *)bndK[i].f.V[2], (double *)v);
    if(val <= 0.0) { _negatives.push_back(i); }
  }
}

static Tet *tetContainsV(Vert *v, cavityContainer &cavity)
{
  for(std::size_t i = 0; i < cavity.size(); i++) {
    std::size_t count = 0;
    for(std::size_t j = 0; j < 4; j++) {
      Face f = cavity[i]->getFace(j);
      const double val = robustPredicates::orient3d(
        (double *)f.V[0], (double *)f.V[1], (double *)f.V[2], (double *)v);
      if(val >= 0) { count++; }
    }
    if(count == 4) return cavity[i];
  }
  return nullptr;
}

static void buildDelaunayBall(cavityContainer &cavity, connContainer &faceToTet)
{
  faceToTet.clear();
  for(std::size_t i = 0; i < cavity.size(); i++) {
    Tet *t = cavity[i];
    for(std::size_t iFace = 0; iFace < 4; iFace++) {
      Tet *neigh = t->T[iFace];
      conn c(t->getFace(iFace), iFace, neigh);
      auto it = std::find(faceToTet.begin(), faceToTet.end(), c);
      if(it == faceToTet.end()) { faceToTet.push_back(c); }
      else {
        faceToTet.erase(it);
      }
    }
  }
}

static bool removeIsolatedTets(Tet *containsV, cavityContainer &cavity,
                               connContainer &bndK, int myThread, int K)
{
  cavityContainer cc;
  cc.push_back(containsV);
  std::stack<Tet *> _stack;
  _stack.push(containsV);

  while(!_stack.empty()) {
    Tet *t = _stack.top();
    _stack.pop();
    for(int i = 0; i < 4; i++) {
      Tet *neigh = t->T[i];
      if(neigh && (std::find(cc.begin(), cc.end(), neigh) == cc.end()) &&
         (std::find(cavity.begin(), cavity.end(), neigh) != cavity.end())) {
        cc.push_back(neigh);
        _stack.push(neigh);
      }
    }
  }
  if(cc.size() == cavity.size()) return false;
  // Msg::Info("   cavity updated(%3ld elements) %3ld isolated tet removed",
  //           cavity.size(),cavity.size()-cc.size());
  cavity = cc;
  return true;
}

static Tet *tetInsideCavityWithFAce(Face &f, cavityContainer &cavity)
{
  // printf("size of cavity %ld\n",cavity.size());
  for(std::size_t i = 0; i < cavity.size(); i++) {
    Tet *t = cavity[i];
    for(std::size_t iFace = 0; iFace < 4; iFace++) {
      if(t->getFace(iFace) == f) { return t; }
    }
  }
  return nullptr;
}

static bool fixDelaunayCavity(Vert *v, cavityContainer &cavity,
                              connContainer &bndK, int myThread, int K,
                              std::vector<std::size_t> &_negatives)
{
  starShapeness(v, bndK, _negatives);

  if(_negatives.empty()) return false;

  // unset all tets of the cavity
  for(std::size_t i = 0; i < cavity.size(); i++) cavity[i]->unset(myThread, K);
  for(std::size_t i = 0; i < bndK.size(); i++)
    if(bndK[i].t) bndK[i].t->unset(myThread, K);

  // return true;

  Msg::Debug("Fixing cavity (%3ld,%3ld) : %ld negatives", cavity.size(),
             bndK.size(), _negatives.size());

  Tet *containsV = tetContainsV(v, cavity);

  if(!containsV) return true;

  while(!_negatives.empty()) {
    for(std::size_t i = 0; i < _negatives.size(); i++) {
      conn &c = bndK[_negatives[i]];
      Tet *toRemove = tetInsideCavityWithFAce(c.f, cavity);
      if(toRemove) {
        auto it = std::find(cavity.begin(), cavity.end(), toRemove);
        if(it != cavity.end()) { cavity.erase(it); }
        else {
          Msg::Error("Datastructure Broken in %s line %5d", __FILE__, __LINE__);
          break;
        }
      }
    }
    removeIsolatedTets(containsV, cavity, bndK, myThread, K);
    buildDelaunayBall(cavity, bndK);
    starShapeness(v, bndK, _negatives);
  }
  for(std::size_t i = 0; i < cavity.size(); i++) cavity[i]->set(myThread, K);
  for(std::size_t i = 0; i < bndK.size(); i++)
    if(bndK[i].t) bndK[i].t->set(myThread, K);
  return false;
}

static void delaunayCavity2(Tet *tet, Tet *prevTet, Vert *v,
                            cavityContainer &cavity, connContainer &bnd,
                            int thread, int iPnt)
{
  std::stack<std::pair<std::pair<Tet *, Tet *>, std::pair<int, int> > > stack;
  bool finished = false;
  Tet *t = tet;
  Tet *prev = prevTet;
  int iNeighStart = 0;
  const int maxNumberNeigh = 4;
  int iNeighEnd = maxNumberNeigh;
  while(!finished) {
    if(iNeighStart == 0) {
      t->set(thread, iPnt); // Mark the triangle
      cavity.push_back(t);
    }

    for(int iNeigh = iNeighStart; iNeigh < iNeighEnd; iNeigh++) {
      Tet *neigh = t->T[iNeigh];
      if(neigh == nullptr) {
        bnd.push_back(conn(t->getFace(iNeigh), iNeigh, neigh));
      }
      else if(neigh == prev) {
      }
      else if(!neigh->inSphere(v, thread)) {
        bnd.push_back(conn(t->getFace(iNeigh), iNeigh, neigh));
        neigh->set(thread, iPnt);
      }
      else if(!(neigh->isSet(thread, iPnt))) {
        // First, add rest of neighbours to stack
        stack.push(std::make_pair(std::make_pair(prev, t),
                                  std::make_pair(iNeigh + 1, maxNumberNeigh)));

        // Second, add neighbour itself to stack
        stack.push(std::make_pair(std::make_pair(t, neigh),
                                  std::make_pair(0, maxNumberNeigh)));

        // Break out loop
        break;
      }
    }

    if(stack.empty()) { finished = true; }
    else {
      const std::pair<std::pair<Tet *, Tet *>, std::pair<int, int> > &next =
        stack.top();
      prev = next.first.first;
      t = next.first.second;
      iNeighStart = next.second.first;
      iNeighEnd = next.second.second;
      stack.pop();
    }
  }
}

static Tet *walk(Tet *t, Vert *v, int maxx, double &totSearch, int thread)
{
  std::set<Tet *> investigatedTets;
  std::queue<Tet *> tets;
  investigatedTets.insert(t);
  while(1) {
    totSearch++;
    if(t == nullptr) {
      return nullptr; // we should NEVER return here
    }
    // if(t->inSphere(v,thread)){return t;}
    double _min = 0.0;
    int NEIGH = -1;
    int count = 0;
    for(int iNeigh = 0; iNeigh < 4; iNeigh++) {
      Face f = t->getFace(iNeigh);
      double val = robustPredicates::orient3d(
        (double *)f.V[0], (double *)f.V[1], (double *)f.V[2], (double *)v);
      if(val >= 0.0) count++;
      if(val < _min) {
        if(!investigatedTets.count(t->T[iNeigh])) {
          NEIGH = iNeigh;
          _min = val;
        }
        else {
          tets.push(t->T[iNeigh]);
        }
      }
    }
    if(count == 4 && t->inSphere(v, thread)) return t;
    if(NEIGH >= 0) {
      t = t->T[NEIGH];
      investigatedTets.insert(t);
    }
    else if(tets.empty()) {
      Msg::Error("Jump-and-walk failed (no neighbor)");
      return nullptr;
    }
    else {
      t = tets.front();
      tets.pop();
    }
  }
  Msg::Error("Jump-and-walk failed (no neighbor)");
  return nullptr;
}

/*
static void print(const char *name, connContainer &conn, Vert *v)
{
  FILE *f = fopen(name, "w");
  fprintf(f, "View \"\"{\n");

  if(v) fprintf(f, "SP(%g,%g,%g){%d};\n", v->x(), v->y(), v->z(), v->getNum());

  for(std::size_t i = 0; i < conn.size(); i++) {
    fprintf(f, "ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g};\n",
            conn[i].f.V[0]->x(), conn[i].f.V[0]->y(), conn[i].f.V[0]->z(),
            conn[i].f.V[1]->x(), conn[i].f.V[1]->y(), conn[i].f.V[1]->z(),
            conn[i].f.V[2]->x(), conn[i].f.V[2]->y(), conn[i].f.V[2]->z(), 1.,
            1., 1.);
  }
  fprintf(f, "};\n");
  fclose(f);
}
*/

/*
static void print(const char *name, int thread, tetContainer &T, Vert *v)
{
  FILE *f = fopen(name, "w");
  fprintf(f, "View \"\"{\n");
  if(v) fprintf(f, "SP(%g,%g,%g){%d};\n", v->x(), v->y(), v->z(), v->getNum());

  for(std::size_t i = 0; i < T.size(thread); i++) {
    Tet *tt = T(thread, i);
    if(tt->V[0]) {
      // double val = robustPredicates::orient3d
      //
((double*)tt->V[0],(double*)tt->V[1],(double*)tt->V[2],(double*)tt->V[3]);
      if(!v) {
        fprintf(f, "SS(%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g,%g};\n",
                tt->V[0]->x(), tt->V[0]->y(), tt->V[0]->z(), tt->V[1]->x(),
                tt->V[1]->y(), tt->V[1]->z(), tt->V[2]->x(), tt->V[2]->y(),
                tt->V[2]->z(), tt->V[3]->x(), tt->V[3]->y(), tt->V[3]->z(),
                tt->V[0]->lc(), tt->V[1]->lc(), tt->V[2]->lc(), tt->V[3]->lc());
      }
      else {
        fprintf(f, "SS(%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g){%d,%d,%d,%d};\n",
                tt->V[0]->x(), tt->V[0]->y(), tt->V[0]->z(), tt->V[1]->x(),
                tt->V[1]->y(), tt->V[1]->z(), tt->V[2]->x(), tt->V[2]->y(),
                tt->V[2]->z(), tt->V[3]->x(), tt->V[3]->y(), tt->V[3]->z(),
                tt->V[0]->getNum(), tt->V[1]->getNum(), tt->V[2]->getNum(),
                tt->V[3]->getNum());
      }
    }
  }
  fprintf(f, "};\n");
  fclose(f);
}
*/

// xx10000 ok if all bits on my right are 0

static bool canWeProcessCavity(cavityContainer &cavity, std::size_t myThread,
                               std::size_t iPt)
{
  std::size_t cSize = cavity.size();
  for(std::size_t j = 0; j < cSize; j++) {
    Tet *f = cavity[j];
    for(std::size_t index = 0; index < myThread; index++) {
      if(f->_bitset[index]) return false;
    }
    if(iPt) {
      if(f->_bitset[myThread] & ((1 << iPt) - 1)) return false;
    }
  }
  return true;
}

/*
static bool checkLocalDelaunayness(Tet *t)
{
  if(t->V[0]) {
    for(int i = 0; i < 4; i++) {
      Tet *n = t->T[i];
      if(n && n->inSphere(t->getOppositeVertex(i), 0)) return false;
    }
  }
  return true;
}
*/

/*
static int checkLocalDelaunayness(tetContainer &c, int thread, char *msg)
{
  int nLoc = 0;
  for(std::size_t i = 0; i < c.size(thread); i++) {
    if(!checkLocalDelaunayness(c(thread, i))) nLoc++;
  }
  if(nLoc != 0) Msg::Info("%s --> %d tets are not locally delaunay", msg, nLoc);
  return nLoc;
}
*/

static Tet *randomTet(int thread, tetContainer &allocator)
{
  std::size_t N = allocator.size(thread);
  //  printf("coucou random TET %d %d\n",thread,N);
  while(1) {
    Tet *t = allocator(thread, rand() % N);
    if(t->V[0]) return t;
  }
}

//#define VERBOSE

void delaunayTrgl(const std::size_t numThreads, const std::size_t NPTS_AT_ONCE,
                  std::size_t Npts, std::vector<Vert *> assignTo[],
                  tetContainer &allocator)
{
#if defined(VERBOSE)
  double totSearchGlob = 0;
  double totCavityGlob = 0;
  printf("%d threads for inserting %d points\n", numThreads, Npts);
#endif

  // checkLocalDelaunayness(allocator, 0, "initial");

  std::vector<int> invalidCavities(numThreads);
  std::vector<int> cacheMisses(numThreads, 0);

  std::size_t maxLocSizeK = 0;
  for(std::size_t i = 0; i < numThreads * NPTS_AT_ONCE; i++) {
    std::size_t s = assignTo[i].size();
    maxLocSizeK = std::max(maxLocSizeK, s);
  }

#pragma omp parallel num_threads(numThreads)
  {
#if defined(_OPENMP)
    int myThread = omp_get_thread_num();
#else
    int myThread = 0;
#endif

    double totSearch = 0;
    std::vector<std::size_t> _negatives;
    std::vector<cavityContainer> cavity(NPTS_AT_ONCE);
    std::vector<connContainer> bnd(NPTS_AT_ONCE);
    std::vector<bool> ok(NPTS_AT_ONCE);
    connContainer faceToTet;
    std::vector<Tet *> Choice(NPTS_AT_ONCE);
    for(std::size_t K = 0; K < NPTS_AT_ONCE; K++)
      Choice[K] = randomTet(0, allocator);

    invalidCavities[myThread] = 0;
    for(std::size_t K = 0; K < NPTS_AT_ONCE; K++) {
      for(std::size_t iP = 0; iP < assignTo[K + myThread * NPTS_AT_ONCE].size();
          iP++) {
        if(numThreads != 1)
          assignTo[K + myThread * NPTS_AT_ONCE][iP]->_thread = myThread;
      }
    }

    std::vector<Vert *> vToAdd(NPTS_AT_ONCE);

#pragma omp barrier

    // Main loop
    for(std::size_t iPGlob = 0; iPGlob < maxLocSizeK; iPGlob++) {
#pragma omp barrier
      std::vector<Tet *> t(NPTS_AT_ONCE);

      // FIND SEEDS
      for(std::size_t K = 0; K < NPTS_AT_ONCE; K++) {
        vToAdd[K] = (iPGlob < assignTo[K + myThread * NPTS_AT_ONCE].size()) ?
                      assignTo[K + myThread * NPTS_AT_ONCE][iPGlob] :
                      nullptr;

        if(vToAdd[K]) {
          // In 3D, insertion of a point may lead to deletion of tets !!
          if(!Choice[K]->V[0]) Choice[K] = randomTet(0, allocator);
          while(1) {
            t[K] = walk(Choice[K], vToAdd[K], Npts, totSearch, myThread);
            if(t[K]) break;
            // the domain may not be convex. we then start from a random tet and
            // walk from there
            Choice[K] = randomTet(0, allocator);
          }
        }
      }

      // BUILD CAVITIES
      for(std::size_t K = 0; K < NPTS_AT_ONCE; K++) {
        if(vToAdd[K]) {
          cavityContainer &cavityK = cavity[K];
          connContainer &bndK = bnd[K];
          for(std::size_t i = 0; i < cavityK.size(); i++)
            cavityK[i]->unset(myThread, K);
          for(std::size_t i = 0; i < bndK.size(); i++)
            if(bndK[i].t) bndK[i].t->unset(myThread, K);
          cavityK.clear();
          bndK.clear();
          delaunayCavity2(t[K], nullptr, vToAdd[K], cavityK, bndK, myThread, K);
          // verify the cavity
          if(fixDelaunayCavity(vToAdd[K], cavityK, bndK, myThread, K,
                               _negatives)) {
            vToAdd[K] = nullptr;
            invalidCavities[myThread]++;
          }
        }
      }

#pragma omp barrier
      for(std::size_t K = 0; K < NPTS_AT_ONCE; K++) {
        if(!vToAdd[K])
          ok[K] = false;
        else
          ok[K] = canWeProcessCavity(cavity[K], myThread, K);
      }

      for(std::size_t K = 0; K < NPTS_AT_ONCE; K++) {
        if(ok[K]) {
          cavityContainer &cavityK = cavity[K];
          connContainer &bndK = bnd[K];
          faceToTet.clear();
          const std::size_t cSize = cavityK.size();
          const std::size_t bSize = bndK.size();
          Choice[K] = cavityK[0];
          for(std::size_t i = 0; i < bSize; i++) {
            // reuse memory slots of invalid elements
            Tet *t = (i < cSize) ? cavityK[i] : allocator.newTet(myThread);
            if(i < cSize && t->V[0]->_thread != myThread)
              cacheMisses[myThread]++;
            t->setVerticesNoTest(bndK[i].f.V[0], bndK[i].f.V[1], bndK[i].f.V[2],
                                 vToAdd[K]);
            Tet *neigh = bndK[i].t;
            t->T[0] = neigh;
            t->T[1] = t->T[2] = t->T[3] = nullptr;
            if(neigh) {
              if(neigh->getFace(0) == bndK[i].f)
                neigh->T[0] = t;
              else if(neigh->getFace(1) == bndK[i].f)
                neigh->T[1] = t;
              else if(neigh->getFace(2) == bndK[i].f)
                neigh->T[2] = t;
              else if(neigh->getFace(3) == bndK[i].f)
                neigh->T[3] = t;
              else {
                Msg::Error("Datastructure broken in triangulation");
                break;
              }
            }
            computeAdjacencies(t, 1, faceToTet);
            computeAdjacencies(t, 2, faceToTet);
            computeAdjacencies(t, 3, faceToTet);
          }
          for(std::size_t i = bSize; i < cSize; i++) {
            cavityK[i]->V[0] = nullptr;
          }
        }
      }
    }
#if defined(VERBOSE)
#pragma omp critical
    {
      totCavityGlob += totCavity;
      totSearchGlob += totSearch;
    }
#endif
#pragma omp barrier
    // clear last cavity
    for(std::size_t K = 0; K < NPTS_AT_ONCE; K++) {
      for(std::size_t i = 0; i < cavity[K].size(); i++)
        cavity[K][i]->unset(myThread, K);
      for(std::size_t i = 0; i < bnd[K].size(); i++)
        if(bnd[K][i].t) bnd[K][i].t->unset(myThread, K);
    }
  }

  if(invalidCavities[0]) Msg::Error("%d invalid cavities", invalidCavities[0]);

#if defined(VERBOSE)
  printf("average searches per point  %12.5E\n", totSearchGlob / Npts);
  printf("average size for del cavity %12.5E\n", totCavityGlob / Npts);
  printf("cache misses: ");
  for(std::size_t i = 0; i < numThreads; i++) {
    printf("%4ud ", (int)cacheMisses[i]);
  }
  printf("\n");
#endif

  for(std::size_t myThread = 0; myThread < numThreads; myThread++)
    for(std::size_t i = 0; i < allocator.size(myThread); i++)
      allocator(myThread, i)->setAllDeleted();
}

static void initialCube(std::vector<Vert *> &v, Vert *box[8],
                        tetContainer &allocator)
{
  SBoundingBox3d bbox;
  for(size_t i = 0; i < v.size(); i++) {
    Vert *pv = v[i];
    bbox += SPoint3(pv->x(), pv->y(), pv->z());
  }
  bbox *= 1.3;
  box[0] =
    new Vert(bbox.min().x(), bbox.min().y(), bbox.min().z(), bbox.diag());
  box[1] =
    new Vert(bbox.max().x(), bbox.min().y(), bbox.min().z(), bbox.diag());
  box[2] =
    new Vert(bbox.max().x(), bbox.max().y(), bbox.min().z(), bbox.diag());
  box[3] =
    new Vert(bbox.min().x(), bbox.max().y(), bbox.min().z(), bbox.diag());
  box[4] =
    new Vert(bbox.min().x(), bbox.min().y(), bbox.max().z(), bbox.diag());
  box[5] =
    new Vert(bbox.max().x(), bbox.min().y(), bbox.max().z(), bbox.diag());
  box[6] =
    new Vert(bbox.max().x(), bbox.max().y(), bbox.max().z(), bbox.diag());
  box[7] =
    new Vert(bbox.min().x(), bbox.max().y(), bbox.max().z(), bbox.diag());

  Tet *t0 = allocator.newTet(0);
  t0->setVertices(box[7], box[2], box[3], box[1]);
  Tet *t1 = allocator.newTet(0);
  t1->setVertices(box[7], box[0], box[1], box[3]);
  Tet *t2 = allocator.newTet(0);
  t2->setVertices(box[1], box[6], box[7], box[2]);
  Tet *t3 = allocator.newTet(0);
  t3->setVertices(box[1], box[0], box[7], box[4]);
  Tet *t4 = allocator.newTet(0);
  t4->setVertices(box[4], box[1], box[5], box[7]);
  Tet *t5 = allocator.newTet(0);
  t5->setVertices(box[7], box[1], box[5], box[6]);

  connContainer ctnr;
  for(int i = 0; i < 4; i++) {
    computeAdjacencies(t0, i, ctnr);
    computeAdjacencies(t1, i, ctnr);
    computeAdjacencies(t2, i, ctnr);
    computeAdjacencies(t3, i, ctnr);
    computeAdjacencies(t4, i, ctnr);
    computeAdjacencies(t5, i, ctnr);
  }
}

static void delaunayTriangulation(const int numThreads, const int nptsatonce,
                                  std::vector<Vert *> &S, Vert *box[8],
                                  tetContainer &allocator)
{
  int N = S.size();

  std::vector<int> indices;
  SortHilbert(S, indices);
  if(!allocator.size(0)) { initialCube(S, box, allocator); }

  int nbBlocks = nptsatonce * numThreads;

  std::vector<std::vector<Vert *> > assignTo(nbBlocks);

  for(std::size_t i = 1; i < indices.size(); i++) {
    int start = indices[i - 1];
    int end = indices[i];
    int sizePerBlock = (nbBlocks * ((end - start) / nbBlocks)) / nbBlocks;
    int currentBlock = 0;
    int localCounter = 0;
    for(int jPt = start; jPt < end; jPt++) {
      if(localCounter++ >= sizePerBlock && currentBlock != nbBlocks - 1) {
        localCounter = 0;
        currentBlock++;
      }
      assignTo[currentBlock].push_back(S[jPt]);
    }
  }

  delaunayTrgl(numThreads, nptsatonce, N, &assignTo[0], allocator);
  // print("finalTetrahedrization.pos",0, allocator);
}

void delaunayTriangulation(const int numThreads, const int nptsatonce,
                           std::vector<MVertex *> &S,
                           std::vector<MTetrahedron *> &T, bool removeBox)
{
  std::vector<MVertex *> _temp;
  std::vector<Vert *> _vertices;
  std::size_t N = S.size();
  _temp.resize(N + 1 + 8);
  double maxx = 0, maxy = 0, maxz = 0;
  for(std::size_t i = 0; i < N; i++) {
    MVertex *mv = S[i];
    maxx = std::max(maxx, fabs(mv->x()));
    maxy = std::max(maxy, fabs(mv->y()));
    maxz = std::max(maxz, fabs(mv->z()));
  }
  double d = 1 * sqrt(maxx * maxx + maxy * maxy + maxz * maxz);

  tetContainer allocator(numThreads, S.size() * 10);

  for(std::size_t i = 0; i < N; i++) {
    MVertex *mv = S[i];
    double dx =
      d * CTX::instance()->mesh.randFactor3d * (double)rand() / RAND_MAX;
    double dy =
      d * CTX::instance()->mesh.randFactor3d * (double)rand() / RAND_MAX;
    double dz =
      d * CTX::instance()->mesh.randFactor3d * (double)rand() / RAND_MAX;
    mv->x() += dx;
    mv->y() += dy;
    mv->z() += dz;
    Vert *v = new Vert(mv->x(), mv->y(), mv->z(), 1.e22, i + 1);
    _vertices.push_back(v);
    _temp[v->getNum()] = mv;
  }

  robustPredicates::exactinit(maxx, maxy, maxz);

  Vert *box[8];
  delaunayTriangulation(numThreads, nptsatonce, _vertices, box, allocator);
  // print("finalTetrahedrization.pos",0, allocator);

  for(int i = 0; i < 8; i++) {
    Vert *v = box[i];
    if(removeBox) { v->setNum(0); }
    else {
      v->setNum(N + i + 1);
      MVertex *mv = new MVertex(v->x(), v->y(), v->z(), nullptr, N + (i + 1));
      _temp[v->getNum()] = mv;
      S.push_back(mv);
    }
  }

  for(int myThread = 0; myThread < numThreads; myThread++) {
    for(std::size_t i = 0; i < allocator.size(myThread); i++) {
      Tet *t = allocator(myThread, i);
      if(t->V[0]) {
        if(t->V[0]->getNum() && t->V[1]->getNum() && t->V[2]->getNum() &&
           t->V[3]->getNum()) {
          MVertex *v1 = _temp[t->V[0]->getNum()];
          MVertex *v2 = _temp[t->V[1]->getNum()];
          MVertex *v3 = _temp[t->V[2]->getNum()];
          MVertex *v4 = _temp[t->V[3]->getNum()];
          MTetrahedron *tr = new MTetrahedron(v1, v2, v3, v4);
          T.push_back(tr);
        }
        else if(!removeBox) {
          Msg::Error("Error in triangulation");
        }
      }
    }
  }

  for(int i = 0; i < 8; i++) delete box[i];
  for(std::size_t i = 0; i < _vertices.size(); i++) delete _vertices[i];
}
