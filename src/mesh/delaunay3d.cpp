// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <stdlib.h>
#include <set>
#include <stack>
#include <unordered_map>
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

struct Tet;

struct Vert {
private:
  double _x[3];
  double _lc;
  std::size_t _num;

public:
  inline std::size_t getNum() const { return _num; }
  inline void setNum(std::size_t n) { _num = n; }
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
    : _num(num)
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
  // circumcenter, squared circumradius and roundoff bound, cached when the
  // vertices are set so that most in-sphere tests are a simple distance
  // comparison; sphTol is set to 1e300 when the cache cannot be trusted and
  // the exact predicates must always be used
  double cc[3], r2, sphTol;
  // visited mark of the cavity search
  bool _cavity;

  Tet() : sphTol(1.e300), _cavity(false)
  {
    V[0] = V[1] = V[2] = V[3] = nullptr;
    T[0] = T[1] = T[2] = T[3] = nullptr;
  }
  void computeSphere()
  {
    sphTol = 1.e300;
    if(!V[0] || !V[1] || !V[2] || !V[3]) return;
    const double *a = (double *)V[0];
    const double *b = (double *)V[1];
    const double *c = (double *)V[2];
    const double *d = (double *)V[3];
    const double xba = b[0] - a[0], yba = b[1] - a[1], zba = b[2] - a[2];
    const double xca = c[0] - a[0], yca = c[1] - a[1], zca = c[2] - a[2];
    const double xda = d[0] - a[0], yda = d[1] - a[1], zda = d[2] - a[2];
    const double balength = xba * xba + yba * yba + zba * zba;
    const double calength = xca * xca + yca * yca + zca * zca;
    const double dalength = xda * xda + yda * yda + zda * zda;
    const double xcrosscd = yca * zda - yda * zca;
    const double ycrosscd = zca * xda - zda * xca;
    const double zcrosscd = xca * yda - xda * yca;
    const double xcrossdb = yda * zba - yba * zda;
    const double ycrossdb = zda * xba - zba * xda;
    const double zcrossdb = xda * yba - xba * yda;
    const double xcrossbc = yba * zca - yca * zba;
    const double ycrossbc = zba * xca - zca * xba;
    const double zcrossbc = xba * yca - xca * yba;
    // plain floating-point determinant: only use the cache when it is far
    // enough from zero for its sign and magnitude to be reliable
    const double det = xba * xcrosscd + yba * ycrosscd + zba * zcrosscd;
    const double permanent =
      fabs(xba) * (fabs(yca * zda) + fabs(yda * zca)) +
      fabs(yba) * (fabs(zca * xda) + fabs(zda * xca)) +
      fabs(zba) * (fabs(xca * yda) + fabs(xda * yca));
    const double eps = 2.220446049250313e-16;
    if(fabs(det) < 1.e6 * eps * permanent) return;
    const double denominator = 0.5 / det;
    const double xcirca =
      (balength * xcrosscd + calength * xcrossdb + dalength * xcrossbc) *
      denominator;
    const double ycirca =
      (balength * ycrosscd + calength * ycrossdb + dalength * ycrossbc) *
      denominator;
    const double zcirca =
      (balength * zcrosscd + calength * zcrossdb + dalength * zcrossbc) *
      denominator;
    cc[0] = xcirca + a[0];
    cc[1] = ycirca + a[1];
    cc[2] = zcirca + a[2];
    // measure the radius from the stored (rounded) center, so that its
    // roundoff cancels between the two sides of the in-sphere comparison
    const double dxr = a[0] - cc[0], dyr = a[1] - cc[1], dzr = a[2] - cc[2];
    r2 = dxr * dxr + dyr * dyr + dzr * dzr;
    // conservative bound on the roundoff of the center, dominated by the
    // cancellations in the cross products and numerator sums plus the
    // relative error of the plain determinant; generous safety margins
    const double across =
      fabs(yca * zda) + fabs(yda * zca) + fabs(yda * zba) + fabs(yba * zda) +
      fabs(yba * zca) + fabs(yca * zba) + fabs(zca * xda) + fabs(zda * xca) +
      fabs(zda * xba) + fabs(zba * xda) + fabs(zba * xca) + fabs(zca * xba) +
      fabs(xca * yda) + fabs(xda * yca) + fabs(xda * yba) + fabs(xba * yda) +
      fabs(xba * yca) + fabs(xca * yba);
    const double maxlength = std::max(balength, std::max(calength, dalength));
    const double relden = 64. * eps * permanent / fabs(det);
    const double cerr =
      maxlength * across * fabs(denominator) * (4096. * eps + 2. * relden);
    sphTol = 3. * cerr;
  }
  int setVerticesNoTest(Vert *v0, Vert *v1, Vert *v2, Vert *v3)
  {
    V[0] = v0;
    V[1] = v1;
    V[2] = v2;
    V[3] = v3;
    computeSphere();
    return 1;
  }
  int setVertices(Vert *v0, Vert *v1, Vert *v2, Vert *v3)
  {
    double val = robustPredicates::orient3d((double *)v0, (double *)v1,
                                            (double *)v2, (double *)v3);
    V[0] = v0;
    V[1] = v1;
    V[2] = v2;
    V[3] = v3;
    computeSphere();
    if(val > 0) { return 1; }
    else if(val < 0) {
      V[0] = v1;
      V[1] = v0;
      V[2] = v2;
      V[3] = v3;
      computeSphere();
      return -1;
    }
    else {
      return 0;
    }
  }
  Tet(Vert *v0, Vert *v1, Vert *v2, Vert *v3) : _cavity(false)
  {
    setVertices(v0, v1, v2, v3);
    T[0] = T[1] = T[2] = T[3] = nullptr;
  }
  void unset() { _cavity = false; }
  void set() { _cavity = true; }
  bool isSet() const { return _cavity; }
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
  bool inSphere(Vert *vd)
  {
    // filtered test on the cached circumsphere: decide with a simple
    // distance comparison when it lies outside the roundoff bound, and fall
    // back to the exact predicates otherwise
    const double dx = vd->x() - cc[0], dy = vd->y() - cc[1],
                 dz = vd->z() - cc[2];
    const double d2 = dx * dx + dy * dy + dz * dz;
    const double diff = d2 - r2;
    const double s = d2 + r2;
    const double bound = sphTol * std::sqrt(s) + 1.e-12 * s;
    if(std::abs(diff) > bound) return diff < 0;
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

// chunked storage owning the tets: grows without ever moving them
class tetContainer {
  std::vector<Tet *> _chunks;
  std::size_t _current, _chunkSize;

public:
  std::size_t size() const
  {
    return _current + (_chunks.size() - 1) * _chunkSize;
  }
  Tet *operator()(std::size_t i) const
  {
    return _chunks[i / _chunkSize] + (i % _chunkSize);
  }
  tetContainer(std::size_t chunkSize)
    : _current(0), _chunkSize(chunkSize ? chunkSize : 1)
  {
    _chunks.push_back(new Tet[_chunkSize]);
  }
  ~tetContainer()
  {
    for(std::size_t i = 0; i < _chunks.size(); i++) delete[] _chunks[i];
  }
  Tet *newTet()
  {
    if(_current == _chunkSize) {
      _chunks.push_back(new Tet[_chunkSize]);
      _current = 0;
    }
    _current++;
    return _chunks.back() + (_current - 1);
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
  // sort a fraction "ratio" of the points first (recursively), then the
  // rest: points are inserted in rounds of increasing density, each round
  // being itself Hilbert-ordered (biased randomized insertion order)
  void MultiscaleSortHilbert(Vert **vertices, int arraysize, int threshold,
                             double ratio)
  {
    int middle = 0;
    if(arraysize >= threshold) {
      middle = (int)(arraysize * ratio);
      MultiscaleSortHilbert(vertices, middle, threshold, ratio);
    }
    Sort(&(vertices[middle]), arraysize - middle, 0, 0, bbox.min().x(),
         bbox.max().x(), bbox.min().y(), bbox.max().y(), bbox.min().z(),
         bbox.max().z(), 0);
  }
  void Apply(std::vector<Vert *> &v)
  {
    if(v.empty()) return;
    for(size_t i = 0; i < v.size(); i++) {
      Vert *pv = v[i];
      bbox += SPoint3(pv->x(), pv->y(), pv->z());
    }
    bbox *= 1.01;
    MultiscaleSortHilbert(&v[0], (int)v.size(), 64, .125);
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

static void SortHilbert(std::vector<Vert *> &v)
{
  HilbertSortB h(1000);
  h.Apply(v);
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
                               connContainer &bndK)
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
  cavity = cc;
  return true;
}

static Tet *tetInsideCavityWithFAce(Face &f, cavityContainer &cavity)
{
  for(std::size_t i = 0; i < cavity.size(); i++) {
    Tet *t = cavity[i];
    for(std::size_t iFace = 0; iFace < 4; iFace++) {
      if(t->getFace(iFace) == f) { return t; }
    }
  }
  return nullptr;
}

static bool fixDelaunayCavity(Vert *v, cavityContainer &cavity,
                              connContainer &bndK,
                              std::vector<std::size_t> &_negatives)
{
  starShapeness(v, bndK, _negatives);

  if(_negatives.empty()) return false;

  // unset all tets of the cavity
  for(std::size_t i = 0; i < cavity.size(); i++) cavity[i]->unset();
  for(std::size_t i = 0; i < bndK.size(); i++)
    if(bndK[i].t) bndK[i].t->unset();

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
    removeIsolatedTets(containsV, cavity, bndK);
    buildDelaunayBall(cavity, bndK);
    starShapeness(v, bndK, _negatives);
  }
  for(std::size_t i = 0; i < cavity.size(); i++) cavity[i]->set();
  for(std::size_t i = 0; i < bndK.size(); i++)
    if(bndK[i].t) bndK[i].t->set();
  return false;
}

// collect the connected set of tets whose circumsphere contains v (the
// Delaunay cavity), and its boundary faces; the visited tets are marked, and
// the caller releases the marks
static void delaunayCavity(Tet *tet, Vert *v, cavityContainer &cavity,
                           connContainer &bnd)
{
  std::stack<std::pair<std::pair<Tet *, Tet *>, std::pair<int, int> > > stack;
  bool finished = false;
  Tet *t = tet;
  Tet *prev = nullptr;
  int iNeighStart = 0;
  const int maxNumberNeigh = 4;
  int iNeighEnd = maxNumberNeigh;
  while(!finished) {
    if(iNeighStart == 0) {
      t->set(); // mark the tet
      cavity.push_back(t);
    }

    for(int iNeigh = iNeighStart; iNeigh < iNeighEnd; iNeigh++) {
      Tet *neigh = t->T[iNeigh];
      if(neigh == nullptr) {
        bnd.push_back(conn(t->getFace(iNeigh), iNeigh, neigh));
      }
      else if(neigh == prev) {
      }
      else if(!neigh->inSphere(v)) {
        bnd.push_back(conn(t->getFace(iNeigh), iNeigh, neigh));
        neigh->set();
      }
      else if(!(neigh->isSet())) {
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

// walk from t towards v, stepping to the neighbor across the face v lies
// most behind, until a tet containing v is found; returns null when the walk
// gets stuck, which happens on non-convex domains (the caller then restarts
// from another tet)
static Tet *walk(Tet *t, Vert *v)
{
  std::set<Tet *> investigatedTets;
  std::queue<Tet *> tets;
  investigatedTets.insert(t);
  while(1) {
    if(t == nullptr) return nullptr;
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
    if(count == 4 && t->inSphere(v)) return t;
    if(NEIGH >= 0) {
      t = t->T[NEIGH];
      investigatedTets.insert(t);
    }
    else if(tets.empty()) {
      return nullptr;
    }
    else {
      t = tets.front();
      tets.pop();
    }
  }
}

static Tet *randomTet(tetContainer &allocator)
{
  std::size_t N = allocator.size();
  while(1) {
    Tet *t = allocator(rand() % N);
    if(t->V[0]) return t;
  }
}

// an edge of the cavity boundary, used to connect the new tets to each
// other: the new tet built on boundary face k has that face as its face 0,
// whose neighbor is already known; its three other faces each contain the
// inserted vertex plus one edge of the boundary face, and match the face of
// the new tet built on the boundary face sharing that edge
struct ballEdge {
  Vert *a, *b;
  std::size_t tetFace; // 4 * (index of the new tet) + (face of that tet)
};

// buffers reused by all the insertions, kept out of the insertion routine so
// that they are allocated once
struct insertionBuffers {
  cavityContainer cavity;
  connContainer bnd;
  std::vector<std::size_t> negatives;
  std::vector<ballEdge> ballEdges;
  std::vector<Tet *> newTets;
};

// insert v: find the tet containing it, carve out the Delaunay cavity and
// retriangulate the cavity onto v. seed is the tet the walk starts from, and
// is updated to a tet of the new ball. Returns false when the cavity could
// not be made star-shaped, in which case v is not inserted.
static bool delaunayInsert(Vert *v, Tet *&seed, tetContainer &allocator,
                           insertionBuffers &buf)
{
  // in 3D, inserting a point may delete tets, so the seed may be dead
  if(!seed->V[0]) seed = randomTet(allocator);
  Tet *t;
  while(1) {
    t = walk(seed, v);
    if(t) break;
    // the domain may not be convex: restart the walk from a random tet
    seed = randomTet(allocator);
  }

  cavityContainer &cavity = buf.cavity;
  connContainer &bnd = buf.bnd;
  cavity.clear();
  bnd.clear();
  delaunayCavity(t, v, cavity, bnd);
  // fixDelaunayCavity releases the marks itself when it gives up
  if(fixDelaunayCavity(v, cavity, bnd, buf.negatives)) return false;

  // the marks are not needed beyond this point, and the tets of the cavity
  // are about to be reused or freed
  for(std::size_t i = 0; i < cavity.size(); i++) cavity[i]->unset();
  for(std::size_t i = 0; i < bnd.size(); i++)
    if(bnd[i].t) bnd[i].t->unset();

  const std::size_t cSize = cavity.size();
  const std::size_t bSize = bnd.size();
  seed = cavity[0];

  std::vector<ballEdge> &ballEdges = buf.ballEdges;
  std::vector<Tet *> &newTets = buf.newTets;
  ballEdges.clear();
  newTets.clear();
  for(std::size_t i = 0; i < bSize; i++) {
    // reuse the memory slots of the tets that have just been deleted
    Tet *nt = (i < cSize) ? cavity[i] : allocator.newTet();
    Vert *f0 = bnd[i].f.V[0];
    Vert *f1 = bnd[i].f.V[1];
    Vert *f2 = bnd[i].f.V[2];
    nt->setVerticesNoTest(f0, f1, f2, v);
    newTets.push_back(nt);
    Tet *neigh = bnd[i].t;
    nt->T[0] = neigh;
    nt->T[1] = nt->T[2] = nt->T[3] = nullptr;
    if(neigh) {
      if(neigh->getFace(0) == bnd[i].f)
        neigh->T[0] = nt;
      else if(neigh->getFace(1) == bnd[i].f)
        neigh->T[1] = nt;
      else if(neigh->getFace(2) == bnd[i].f)
        neigh->T[2] = nt;
      else if(neigh->getFace(3) == bnd[i].f)
        neigh->T[3] = nt;
      else {
        Msg::Error("Datastructure broken in triangulation");
        break;
      }
    }
    // faces 1, 2, 3 of nt contain the inserted vertex and one edge of the
    // boundary face (see the face numbering in Tet::getFace)
    ballEdges.push_back({std::min(f1, f2), std::max(f1, f2), 4 * i + 1});
    ballEdges.push_back({std::min(f0, f2), std::max(f0, f2), 4 * i + 2});
    ballEdges.push_back({std::min(f0, f1), std::max(f0, f1), 4 * i + 3});
  }

  // sorting brings the two faces sharing an edge of the ball next to each
  // other, which pairs them in O(k log k) instead of a quadratic search
  std::sort(ballEdges.begin(), ballEdges.end(),
            [](const ballEdge &e1, const ballEdge &e2) {
              if(e1.a != e2.a) return e1.a < e2.a;
              return e1.b < e2.b;
            });
  for(std::size_t i = 0; i + 1 < ballEdges.size(); i++) {
    const ballEdge &e1 = ballEdges[i];
    const ballEdge &e2 = ballEdges[i + 1];
    if(e1.a == e2.a && e1.b == e2.b) {
      Tet *t1 = newTets[e1.tetFace >> 2];
      Tet *t2 = newTets[e2.tetFace >> 2];
      t1->T[e1.tetFace & 3] = t2;
      t2->T[e2.tetFace & 3] = t1;
      ++i;
    }
  }

  // the cavity slots that have not been reused are now free
  for(std::size_t i = bSize; i < cSize; i++) cavity[i]->V[0] = nullptr;
  return true;
}

// insert all the points of S, in the given order
static void delaunayTrgl(const std::vector<Vert *> &S, tetContainer &allocator)
{
  insertionBuffers buf;
  Tet *seed = randomTet(allocator);
  int invalidCavities = 0;

  for(std::size_t i = 0; i < S.size(); i++) {
    if(!delaunayInsert(S[i], seed, allocator, buf)) invalidCavities++;
  }

  if(invalidCavities) Msg::Error("%d invalid cavities", invalidCavities);
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

  Tet *t0 = allocator.newTet();
  t0->setVertices(box[7], box[2], box[3], box[1]);
  Tet *t1 = allocator.newTet();
  t1->setVertices(box[7], box[0], box[1], box[3]);
  Tet *t2 = allocator.newTet();
  t2->setVertices(box[1], box[6], box[7], box[2]);
  Tet *t3 = allocator.newTet();
  t3->setVertices(box[1], box[0], box[7], box[4]);
  Tet *t4 = allocator.newTet();
  t4->setVertices(box[4], box[1], box[5], box[7]);
  Tet *t5 = allocator.newTet();
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

static void delaunayTriangulation(std::vector<Vert *> &S, Vert *box[8],
                                  tetContainer &allocator)
{
  // sorting the points along a Hilbert curve, in coarse-to-fine rounds,
  // makes every walk start close to its target
  SortHilbert(S);
  if(!allocator.size()) { initialCube(S, box, allocator); }
  delaunayTrgl(S, allocator);
}

void delaunayTriangulation(std::vector<MVertex *> &S,
                           std::vector<MTetrahedron *> &T, bool removeBox,
                           std::vector<std::int64_t> *neighbors)
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

  tetContainer allocator(S.size() * 10);

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
  delaunayTriangulation(_vertices, box, allocator);

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

  std::vector<Tet *> outTets;
  for(std::size_t i = 0; i < allocator.size(); i++) {
    Tet *t = allocator(i);
    if(t->V[0]) {
      if(t->V[0]->getNum() && t->V[1]->getNum() && t->V[2]->getNum() &&
         t->V[3]->getNum()) {
        MVertex *v1 = _temp[t->V[0]->getNum()];
        MVertex *v2 = _temp[t->V[1]->getNum()];
        MVertex *v3 = _temp[t->V[2]->getNum()];
        MVertex *v4 = _temp[t->V[3]->getNum()];
        MTetrahedron *tr = new MTetrahedron(v1, v2, v3, v4);
        T.push_back(tr);
        if(neighbors) outTets.push_back(t);
      }
      else if(!removeBox) {
        Msg::Error("Error in triangulation");
      }
    }
  }

  if(neighbors) {
    std::unordered_map<Tet *, std::int64_t> idxOf;
    idxOf.reserve(outTets.size());
    for(std::size_t i = 0; i < outTets.size(); i++)
      idxOf[outTets[i]] = (std::int64_t)i;
    neighbors->clear();
    neighbors->reserve(4 * outTets.size());
    for(std::size_t i = 0; i < outTets.size(); i++) {
      for(int k = 0; k < 4; k++) {
        Tet *n = outTets[i]->T[k];
        std::int64_t idx = -1;
        if(n && n->V[0]) {
          auto it = idxOf.find(n);
          if(it != idxOf.end()) idx = it->second;
        }
        neighbors->push_back(idx);
      }
    }
  }

  for(int i = 0; i < 8; i++) delete box[i];
  for(std::size_t i = 0; i < _vertices.size(); i++) delete _vertices[i];
}
