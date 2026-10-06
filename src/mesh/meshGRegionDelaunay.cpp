// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// The sequential 3D Delaunay mesher (del3d): the circumcenter of a
// tetrahedron, the tetrahedralization of a set of points, and filling a region
// with tetrahedra - the boundary mesh is recovered and classified, then points
// are inserted at the circumcenters of the tets that are too large. Two
// kernels do the insertion: the flat one, on index-based arrays, which is the
// default (Mesh.FlatRefine3D) and lives in meshGRegionDelaunayFlat.cpp, and
// the original one, on the MTet4 objects, which it is meant to replace and
// which is below. Optimizing a region is in meshGRegionOptimize.cpp; the
// parallel mesher (pdel3d) is in meshGRegionParallelDelaunay.cpp.

#include <array>
#include <cstring>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include "GmshMessage.h"
#include "robustPredicates.h"
#include "OS.h"
#include "meshGRegion.h"
#include "meshGRegionLocalMeshMod.h"
#include "meshGRegionDelaunay.h"
#include "meshGRegionDelaunayFlat.h"
#include "meshGRegionTet4.h"
#include "GModel.h"
#include "GRegion.h"
#include "GFace.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "Numeric.h"
#include "Context.h"
#include "MEdge.h"
#include "MVertex.h"
#include "MLine.h"
#include "ExtrudeParams.h"
#include "BackgroundMeshTools.h"
#include <stdlib.h>
#include <stack>
#include <vector>
#include <cmath>
#include "SPoint3.h"
#include "SBoundingBox3d.h"
#include "MTetrahedron.h"

double tetcircumcenter(double a[3], double b[3], double c[3], double d[3],
                       double circumcenter[3], double *xi, double *eta,
                       double *zeta)
{
  double xba, yba, zba, xca, yca, zca, xda, yda, zda;
  double balength, calength, dalength;
  double xcrosscd, ycrosscd, zcrosscd;
  double xcrossdb, ycrossdb, zcrossdb;
  double xcrossbc, ycrossbc, zcrossbc;
  double denominator;
  double xcirca, ycirca, zcirca;

  /* Use coordinates relative to point `a' of the tetrahedron. */
  xba = b[0] - a[0];
  yba = b[1] - a[1];
  zba = b[2] - a[2];
  xca = c[0] - a[0];
  yca = c[1] - a[1];
  zca = c[2] - a[2];
  xda = d[0] - a[0];
  yda = d[1] - a[1];
  zda = d[2] - a[2];
  /* Squares of lengths of the edges incident to `a'. */
  balength = xba * xba + yba * yba + zba * zba;
  calength = xca * xca + yca * yca + zca * zca;
  dalength = xda * xda + yda * yda + zda * zda;
  /* Cross products of these edges. */
  xcrosscd = yca * zda - yda * zca;
  ycrosscd = zca * xda - zda * xca;
  zcrosscd = xca * yda - xda * yca;
  xcrossdb = yda * zba - yba * zda;
  ycrossdb = zda * xba - zba * xda;
  zcrossdb = xda * yba - xba * yda;
  xcrossbc = yba * zca - yca * zba;
  ycrossbc = zba * xca - zca * xba;
  zcrossbc = xba * yca - xca * yba;

  /* Calculate the denominator of the formulae. */
  /* Use orient3d() from http://www.cs.cmu.edu/~quake/robust.html     */
  /*   to ensure a correctly signed (and reasonably accurate) result, */
  /*   avoiding any possibility of division by zero.                  */
  const double xxx = robustPredicates::orient3d(b, c, d, a);
  denominator = 0.5 / xxx;

  /* Calculate offset (from `a') of circumcenter. */
  xcirca = (balength * xcrosscd + calength * xcrossdb + dalength * xcrossbc) *
           denominator;
  ycirca = (balength * ycrosscd + calength * ycrossdb + dalength * ycrossbc) *
           denominator;
  zcirca = (balength * zcrosscd + calength * zcrossdb + dalength * zcrossbc) *
           denominator;
  circumcenter[0] = xcirca + a[0];
  circumcenter[1] = ycirca + a[1];
  circumcenter[2] = zcirca + a[2];

  if(xi != (double *)nullptr) {
    /* To interpolate a linear function at the circumcenter, define a    */
    /*   coordinate system with a xi-axis directed from `a' to `b',      */
    /*   an eta-axis directed from `a' to `c', and a zeta-axis directed  */
    /*   from `a' to `d'.  The values for xi, eta, and zeta are computed */
    /*   by Cramer's Rule for solving systems of linear equations.       */
    *xi = (xcirca * xcrosscd + ycirca * ycrosscd + zcirca * zcrosscd) *
          (2.0 * denominator);
    *eta = (xcirca * xcrossdb + ycirca * ycrossdb + zcirca * zcrossdb) *
           (2.0 * denominator);
    *zeta = (xcirca * xcrossbc + ycirca * ycrossbc + zcirca * zcrossbc) *
            (2.0 * denominator);
  }
  return xxx;
}

// Delaunay tetrahedralization of a point set (the initial tetrahedralization
// of the surface nodes): an incremental Bowyer-Watson insertion with its own
// vertex and tetrahedron structures, the points sorted along a Hilbert curve
// in coarse-to-fine rounds, inside a box of 8 extra vertices
namespace {

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
    { return Vert(x() * other, y() * other, z() * other, _lc * other); }
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

  // Total order on vertices for the symbolic perturbation and the face
  // keys. Comparing pointers made both depend on where the allocator put each
  // vertex, so cospherical configurations were resolved differently from run
  // to run. Every vertex has a unique number (see initialCube for the box
  // corners).
  static inline bool vertLess(const Vert *a, const Vert *b)
  {
    return a->getNum() < b->getNum();
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
          if(vertLess(pt[i + 1], pt[i])) {
            Vert *swappt = pt[i];
            pt[i] = pt[i + 1];
            pt[i + 1] = swappt;
            count++;
          }
        }
        swaps += count;
      } while(count > 0);
      double oriA = robustPredicates::orient3d(
        (double *)pt[1], (double *)pt[2], (double *)pt[3], (double *)pt[4]);
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
    if(vertLess(b, a)) {                                                       \
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
    { return v[0] == other.v[0] && v[1] == other.v[1] && v[2] == other.v[2]; }

    bool operator<(const Face &other) const
    {
      if(vertLess(v[0], other.v[0])) return true;
      if(vertLess(other.v[0], v[0])) return false;
      if(vertLess(v[1], other.v[1])) return true;
      if(vertLess(other.v[1], v[1])) return false;
      return vertLess(v[2], other.v[2]);
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
      const double permanent = fabs(xba) * (fabs(yca * zda) + fabs(yda * zca)) +
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
    { return _current + (_chunks.size() - 1) * _chunkSize; }
    Tet *operator()(std::size_t i) const
    { return _chunks[i / _chunkSize] + (i % _chunkSize); }
    tetContainer(std::size_t chunkSize)
      : _current(0), _chunkSize(chunkSize ? chunkSize : 1)
    { _chunks.push_back(new Tet[_chunkSize]); }
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
    { ComputeGrayCode(3); }
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
      if((depth + 1) == maxDepth) { return; }
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

  static void buildDelaunayBall(cavityContainer &cavity,
                                connContainer &faceToTet)
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
            Msg::Error("Datastructure Broken in %s line %5d", __FILE__,
                       __LINE__);
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
    std::stack<std::pair<std::pair<Tet *, Tet *>, std::pair<int, int>>> stack;
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
          stack.push(
            std::make_pair(std::make_pair(prev, t),
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
        const std::pair<std::pair<Tet *, Tet *>, std::pair<int, int>> &next =
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
  static void delaunayTrgl(const std::vector<Vert *> &S,
                           tetContainer &allocator)
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
    // unique numbers after the input vertices (1..N), for vertLess
    for(int i = 0; i < 8; i++) box[i]->setNum(v.size() + i + 1);

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
    SBoundingBox3d bbox;
    for(std::size_t i = 0; i < N; i++) {
      MVertex *mv = S[i];
      maxx = std::max(maxx, fabs(mv->x()));
      maxy = std::max(maxy, fabs(mv->y()));
      maxz = std::max(maxz, fabs(mv->z()));
      bbox += mv->point();
    }
    double d = 1 * sqrt(maxx * maxx + maxy * maxy + maxz * maxz);

    tetContainer allocator(S.size() * 10);

    // Perturb the nodes by up to Mesh.RandomFactor3D times the size of the
    // model (the boundary recovery restores them): the nodes of curved CAD
    // surfaces are cospherical to rounding, those of planar faces coplanar,
    // which sends the in-sphere tests to the exact arithmetic. Without it
    // (benchmarks/3d, October 2026), del3d still succeeds everywhere, but is
    // 2-2.5x slower on crux, fil and percolation. See also pdel3d
    // (meshGRegionParallelDelaunay.cpp), which depends on it more
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

    // the static filters bound the coordinate differences, up to the size of
    // the enclosing cube of initialCube()
    if(!bbox.empty()) {
      const SPoint3 a = bbox.min(), b = bbox.max();
      robustPredicates::exactinit(1.3 * (b.x() - a.x()), 1.3 * (b.y() - a.y()),
                                  1.3 * (b.z() - a.z()));
    }

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

} // namespace

void delaunayMeshIn3D(std::vector<MVertex *> &v,
                      std::vector<MTetrahedron *> &result, bool removeBox,
                      std::vector<std::int64_t> *neighbors)
{
  Msg::Info("Tetrahedrizing %d nodes...", v.size());
  double t1 = Cpu(), w1 = TimeOfDay();
  delaunayTriangulation(v, result, removeBox, neighbors);
  double t2 = Cpu(), w2 = TimeOfDay();
  Msg::Info("Done tetrahedrizing %d nodes (Wall %gs, CPU %gs)", v.size(),
            w2 - w1, t2 - t1);
}

#ifdef DEBUG_BOUNDARY_RECOVERY

static void testIfBoundaryIsRecovered(GRegion *gr)
{
  std::vector<GEdge *> const &e = gr->edges();
  std::vector<GFace *> f = gr->faces();

  std::map<MEdge, GEdge *, MEdgeLessThan> edges;
  std::map<MFace, GFace *, MFaceLessThan> faces;

  auto it = e.begin();
  auto itf = f.begin();
  for(; it != e.end(); ++it) {
    for(std::size_t i = 0; i < (*it)->lines.size(); ++i) {
      if(distance((*it)->lines[i]->getVertex(0),
                  (*it)->lines[i]->getVertex(1)) > 1.e-12)
        edges.insert(std::make_pair(
          MEdge((*it)->lines[i]->getVertex(0), (*it)->lines[i]->getVertex(1)),
          *it));
    }
  }
  for(; itf != f.end(); ++itf) {
    for(std::size_t i = 0; i < (*itf)->triangles.size(); ++i) {
      faces.insert(std::make_pair(MFace((*itf)->triangles[i]->getVertex(0),
                                        (*itf)->triangles[i]->getVertex(1),
                                        (*itf)->triangles[i]->getVertex(2)),
                                  *itf));
    }
  }
  Msg::Info("Searching for %d mesh edges and %d mesh faces among %d elements "
            "in region %d",
            edges.size(), faces.size(), gr->getNumMeshElements(), gr->tag());
  for(std::size_t k = 0; k < gr->getNumMeshElements(); k++) {
    for(int j = 0; j < gr->getMeshElement(k)->getNumEdges(); j++) {
      edges.erase(gr->getMeshElement(k)->getEdge(j));
    }
    for(int j = 0; j < gr->getMeshElement(k)->getNumFaces(); j++) {
      faces.erase(gr->getMeshElement(k)->getFace(j));
    }
  }
  if(edges.empty() && faces.empty()) {
    Msg::Info("All edges and faces are present in the initial mesh");
  }
  else {
    Msg::Error("All edges and faces are not present in the initial mesh");
  }
}

#endif

static void createAllEmbeddedEdges(GRegion *gr, edgeContainerB &embedded)
{
  std::vector<GEdge *> const &e = gr->embeddedEdges();
  for(auto it = e.begin(); it != e.end(); ++it) {
    for(std::size_t i = 0; i < (*it)->lines.size(); i++) {
      embedded.addNewEdge(
        MEdge((*it)->lines[i]->getVertex(0), (*it)->lines[i]->getVertex(1)));
    }
  }
}

static int faces[4][3] = {{0, 1, 2}, {0, 2, 3}, {0, 3, 1}, {1, 3, 2}};

struct vertex_comparator {
  bool operator()(MVertex *const a, MVertex *const b) const
  { return a->getNum() < b->getNum(); }
};

struct faceXtet {
  MVertex *v[3], *unsorted[3];
  MTet4 *t1;
  int i1;

  faceXtet(MTet4 *_t = nullptr, int iFac = 0) : t1(_t), i1(iFac)
  {
    unsorted[0] = v[0] = t1->tet()->getVertex(faces[iFac][0]);
    unsorted[1] = v[1] = t1->tet()->getVertex(faces[iFac][1]);
    unsorted[2] = v[2] = t1->tet()->getVertex(faces[iFac][2]);

    std::sort(v, v + 3, vertex_comparator());
  }

  MVertex *getVertex(int i) const { return unsorted[i]; }

  bool operator<(const faceXtet &other) const
  {
    if(v[0]->getNum() < other.v[0]->getNum()) return true;
    if(v[0]->getNum() > other.v[0]->getNum()) return false;
    if(v[1]->getNum() < other.v[1]->getNum()) return true;
    if(v[1]->getNum() > other.v[1]->getNum()) return false;
    if(v[2]->getNum() < other.v[2]->getNum()) return true;
    return false;
  }

  bool operator==(const faceXtet &other) const
  {
    return (v[0]->getNum() == other.v[0]->getNum() &&
            v[1]->getNum() == other.v[1]->getNum() &&
            v[2]->getNum() == other.v[2]->getNum());
  }

  bool visible(MVertex *v)
  {
    MVertex const *const v0 = t1->tet()->getVertex(faces[i1][0]);
    MVertex const *const v1 = t1->tet()->getVertex(faces[i1][1]);
    MVertex const *const v2 = t1->tet()->getVertex(faces[i1][2]);

    double a[3] = {v0->x(), v0->y(), v0->z()};
    double b[3] = {v1->x(), v1->y(), v1->z()};
    double c[3] = {v2->x(), v2->y(), v2->z()};
    double d[3] = {v->x(), v->y(), v->z()};

    return robustPredicates::orient3d(a, b, c, d) < 0.0;
  }
};
static void removeFromCavity(std::vector<faceXtet> &shell,
                             std::vector<MTet4 *> &cavity, faceXtet &toRemove)
{
  toRemove.t1->setDeleted(false);
  cavity.erase(
    std::remove_if(cavity.begin(), cavity.end(),
                   [toRemove](MTet4 *ptr) { return ptr == toRemove.t1; }));

  for(int i = 0; i < 4; i++) {
    faceXtet fxt2(toRemove.t1, i);
    auto it = std::find(shell.begin(), shell.end(), fxt2);
    if(it == shell.end()) {
      MTet4 *opposite = toRemove.t1->getNeigh(toRemove.i1);
      if(opposite) {
        for(int j = 0; j < 4; j++) {
          faceXtet fxt3(opposite, j);
          if(fxt3 == fxt2) { shell.push_back(fxt3); }
        }
      }
    }
    else
      shell.erase(it);
  }
}

static void extendCavity(std::vector<faceXtet> &shell,
                         std::vector<MTet4 *> &cavity, faceXtet &toExtend)
{
  MTet4 *t = toExtend.t1;
  MTet4 *opposite = t->getNeigh(toExtend.i1);
  for(int i = 0; i < 4; i++) {
    faceXtet fxt(opposite, i);
    auto it = std::find(shell.begin(), shell.end(), fxt);
    if(it == shell.end())
      shell.push_back(fxt);
    else
      shell.erase(it);
  }
  cavity.push_back(opposite);
  opposite->setDeleted(true);
}

// if all faces of the tet that are not in the shell see v, then it is ok
// either to add or to remove t from the shell
static bool verifyShell(MVertex *v, MTet4 *t, std::vector<faceXtet> &shell)
{
  if(!t) return false;
  return 1;
  int NBAD_BEFORE = 0, NBAD_AFTER = 0;
  for(int i = 0; i < 4; i++) {
    faceXtet fxt(t, i);
    bool starShaped = fxt.visible(v);
    if(!starShaped) {
      auto its = std::find(shell.begin(), shell.end(), fxt);
      if(its == shell.end())
        NBAD_AFTER++;
      else
        NBAD_BEFORE++;
    }
  }
  return 1;
  return (NBAD_AFTER < NBAD_BEFORE);
}

static int makeCavityStarShaped(std::vector<faceXtet> &shell,
                                std::vector<MTet4 *> &cavity, MVertex *v)
{
  std::vector<faceXtet> wrong;
  for(auto it = shell.begin(); it != shell.end(); ++it) {
    faceXtet &fxt = *it;
    bool starShaped = fxt.visible(v);
    if(!starShaped) { wrong.push_back(fxt); }
  }
  if(wrong.empty()) return 0;
  // printf("cavity %p (shell size %d cavity size %d)is not star shaped "
  //        "(%d faces not visible), correcting it\n",
  //         v, shell.size(), cavity.size(), wrong.size());
  while(!wrong.empty()) {
    faceXtet &fxt = *(wrong.begin());
    if(std::find(shell.begin(), shell.end(), fxt) != shell.end()) {
      if(fxt.t1->getNeigh(fxt.i1) &&
         fxt.t1->getNeigh(fxt.i1)->onWhat() == fxt.t1->onWhat() &&
         verifyShell(v, fxt.t1->getNeigh(fxt.i1), shell)) {
        extendCavity(shell, cavity, fxt);
      }
      else if(verifyShell(v, fxt.t1, shell)) {
        return -1;
        removeFromCavity(shell, cavity, fxt);
      }
      else {
        return -1;
      }
    }
    wrong.erase(wrong.begin());
  }
  // printf("after : shell size %d cavity size %d\n", shell.size(),
  // cavity.size());
  return 1;
}

static void findCavity(std::vector<faceXtet> &shell,
                       std::vector<MTet4 *> &cavity, MVertex *v, MTet4 *t)
{
  t->setDeleted(true);
  cavity.push_back(t);

  // breadth-first traversal: the cavity vector itself acts as the queue,
  // since each tet is appended to it exactly once
  for(std::size_t idx = 0; idx < cavity.size(); idx++) {
    MTet4 *const current = cavity[idx];
    for(int i = 0; i < 4; i++) {
      MTet4 *const neighbour = current->getNeigh(i);
      if(!neighbour) { shell.push_back(faceXtet(current, i)); }
      else if(!neighbour->isDeleted()) {
        if(neighbour->inCircumSphere(v) &&
           (neighbour->onWhat() == current->onWhat())) {
          neighbour->setDeleted(true);
          cavity.push_back(neighbour);
        }
        else {
          shell.push_back(faceXtet(current, i));
        }
      }
    }
  }
}

#ifdef PRINT_TETS

static void printTets(const char *fn, std::list<MTet4 *> &cavity,
                      bool force = false)
{
  FILE *f = Fopen(fn, "w");
  if(f) {
    fprintf(f, "View \"\"{\n");
    auto ittet = cavity.begin();
    auto ittete = cavity.end();
    while(ittet != ittete) {
      MTet4 *tet = *ittet;
      if(force || !tet->isDeleted()) {
        MTetrahedron *t = tet->tet();
        t->writePOS(f, false, false, false, false, true, false);
      }
      ittet++;
    }
    fprintf(f, "};\n");
    fclose(f);
  }
}

#endif

// Priority queue of tets ordered like compareTet4Ptr (largest circumradius
// first, ties broken on the smaller element number). The keys are stored
// inline in a 4-ary heap so that comparisons do not chase MTet4 pointers,
// which made the former std::set-based container dominate the run time.
// Entries are pushed once, when the tet is created; the caller never
// re-pushes a tet, so an entry is stale only if its tet was deleted in the
// meantime. Tets whose radius is already below the refinement target can
// never be refined: they bypass the heap and sit in an unordered side list,
// which is swept periodically to release the ones that got deleted.
class tetRadiusQueue {
  struct entry {
    double radius;
    std::size_t num;
    MTet4 *t;
  };
  static bool entryLess(const entry &a, const entry &b)
  {
    if(a.radius != b.radius) return a.radius < b.radius;
    return a.num > b.num;
  }
  MTet4Factory &_factory;
  double _threshold;
  std::vector<entry> _h;
  std::vector<MTet4 *> _small;
  std::size_t _smallAlive;

public:
  tetRadiusQueue(MTet4Factory &factory, double threshold)
    : _factory(factory), _threshold(threshold), _smallAlive(0)
  {
  }
  bool empty() const { return _h.empty(); }
  std::size_t totalSize() const { return _h.size() + _small.size(); }
  void push(MTet4 *t)
  {
    if(t->getRadius() < _threshold) {
      _small.push_back(t);
      if(_small.size() > 2 * _smallAlive + 1024) sweepSmall();
      return;
    }
    _h.push_back({t->getRadius(), t->tet()->getNum(), t});
    std::size_t i = _h.size() - 1;
    while(i) {
      std::size_t p = (i - 1) >> 2;
      if(entryLess(_h[p], _h[i]))
        std::swap(_h[p], _h[i]);
      else
        break;
      i = p;
    }
  }
  MTet4 *top() const { return _h.front().t; }
  void pop()
  {
    entry last = _h.back();
    _h.pop_back();
    const std::size_t n = _h.size();
    if(!n) return;
    std::size_t i = 0;
    while(true) {
      std::size_t c = 4 * i + 1;
      if(c >= n) break;
      std::size_t best = c;
      std::size_t end = std::min(c + 4, n);
      for(std::size_t j = c + 1; j < end; j++)
        if(entryLess(_h[best], _h[j])) best = j;
      if(entryLess(last, _h[best])) {
        _h[i] = _h[best];
        i = best;
      }
      else
        break;
    }
    _h[i] = last;
  }
  void sweepSmall()
  {
    std::size_t kept = 0;
    for(std::size_t i = 0; i < _small.size(); i++) {
      if(_small[i]->isDeleted())
        _factory.Free(_small[i]);
      else
        _small[kept++] = _small[i];
    }
    _small.resize(kept);
    _smallAlive = kept;
  }
  // Free the deleted tets and return the remaining ones ordered as
  // compareTet4Ptr would order them; "extra" contains alive tets whose entry
  // was already popped (failed insertions, with their radius forced to 0)
  void drainSorted(std::vector<MTet4 *> &extra, std::vector<MTet4 *> &sorted)
  {
    for(auto &e : _h) {
      if(e.t->isDeleted()) {
        _factory.Free(e.t);
        e.t = nullptr;
      }
    }
    sweepSmall();
    for(auto t : _small) _h.push_back({t->getRadius(), t->tet()->getNum(), t});
    _small.clear();
    for(auto t : extra) {
      if(t->isDeleted())
        _factory.Free(t);
      else
        _h.push_back({t->getRadius(), t->tet()->getNum(), t});
    }
    std::sort(_h.begin(), _h.end(), [](const entry &a, const entry &b) {
      if(a.radius != b.radius) return a.radius > b.radius;
      return a.num < b.num;
    });
    sorted.clear();
    sorted.reserve(_h.size());
    for(auto &e : _h) {
      if(e.t) sorted.push_back(e.t);
    }
    _h.clear();
  }
};

static bool
insertVertexB(std::vector<faceXtet> &shell, std::vector<MTet4 *> &cavity,
              MVertex *v, double lc1, double lc2, std::vector<double> &vSizes,
              std::vector<double> &vSizesBGM, MTet4 *t, MTet4Factory &myFactory,
              tetRadiusQueue &allTets,
              const std::set<MFace, MFaceLessThan> &allEmbeddedFaces)
{
  const bool hasEmbedded = !allEmbeddedFaces.empty();

  std::vector<MTet4 *> new_cavity;
  if(hasEmbedded) new_cavity.reserve(2 * shell.size());

  std::vector<MTet4 *> new_tets;
  new_tets.reserve(shell.size());

  auto it = shell.begin();

  double const lc = Extend2dMeshIn3dVolumes() ? std::min(lc1, lc2) : lc2;
  double const lcSq = (lc * .05) * (lc * .05);
  auto tooClose = [&](MVertex *w) {
    double dx = w->x() - v->x(), dy = w->y() - v->y(), dz = w->z() - v->z();
    return dx * dx + dy * dy + dz * dz < lcSq;
  };

  bool onePointIsTooClose = false;
  while(it != shell.end()) {
    MTetrahedron *tr = myFactory.createTet(it->getVertex(0), it->getVertex(1),
                                           it->getVertex(2), v);
    MTet4 *t4 = myFactory.Create(tr, vSizes, vSizesBGM, lc1, lc2);
    t4->setOnWhat(t->onWhat());

    if(tooClose(it->v[0]) || tooClose(it->v[1]) || tooClose(it->v[2]))
      onePointIsTooClose = true;

    new_tets.push_back(t4);

    if(hasEmbedded) {
      new_cavity.push_back(t4);
      MTet4 *otherSide = it->t1->getNeigh(it->i1);
      if(otherSide) new_cavity.push_back(otherSide);
    }
    ++it;
  }
  if(!onePointIsTooClose) {
    if(!hasEmbedded) {
      // connect the new tets directly, without sorting all their faces: the
      // new tet built on shell face k is (v0, v1, v2, v), so its face 0 is
      // the shell face itself, whose neighbor is the tet outside the cavity;
      // its faces 1, 2 and 3 contain the new vertex plus one shell face edge
      // each, and match the face of the new tet built on the shell face
      // sharing that edge
      struct shellEdge {
        MVertex *a, *b;
        int tetFace;
      };
      std::vector<shellEdge> edges;
      edges.reserve(3 * shell.size());
      for(std::size_t k = 0; k < shell.size(); k++) {
        MVertex *f0 = shell[k].getVertex(0);
        MVertex *f1 = shell[k].getVertex(1);
        MVertex *f2 = shell[k].getVertex(2);
        edges.push_back({std::min(f0, f2), std::max(f0, f2), (int)(4 * k + 1)});
        edges.push_back({std::min(f0, f1), std::max(f0, f1), (int)(4 * k + 2)});
        edges.push_back({std::min(f1, f2), std::max(f1, f2), (int)(4 * k + 3)});
      }
      std::sort(edges.begin(), edges.end(),
                [](const shellEdge &e1, const shellEdge &e2) {
                  if(e1.a != e2.a) return e1.a < e2.a;
                  return e1.b < e2.b;
                });
      for(std::size_t i = 0; i + 1 < edges.size(); i++) {
        const shellEdge &e1 = edges[i];
        const shellEdge &e2 = edges[i + 1];
        if(e1.a == e2.a && e1.b == e2.b) {
          MTet4 *t1 = new_tets[e1.tetFace >> 2];
          MTet4 *t2 = new_tets[e2.tetFace >> 2];
          t1->setNeigh(e1.tetFace & 3, t2);
          t2->setNeigh(e2.tetFace & 3, t1);
          ++i;
        }
      }
      for(std::size_t k = 0; k < shell.size(); k++) {
        MTet4 *otherSide = shell[k].t1->getNeigh(shell[k].i1);
        if(!otherSide) continue;
        new_tets[k]->setNeigh(0, otherSide);
        for(int j = 0; j < 4; j++) {
          if(otherSide->getNeigh(j) == shell[k].t1) {
            otherSide->setNeigh(j, new_tets[k]);
            break;
          }
        }
      }
    }
    else {
      connectTets(new_cavity.begin(), new_cavity.end(), &allEmbeddedFaces);
    }

    for(std::size_t i = 0; i < new_tets.size(); i++) allTets.push(new_tets[i]);

    return true;
  }
  else /* one point is too close */ {
    for(std::size_t i = 0; i < shell.size(); i++) myFactory.Free(new_tets[i]);
    auto ittet = cavity.begin();
    auto ittete = cavity.end();
    while(ittet != ittete) {
      (*ittet)->setDeleted(false);
      ++ittet;
    }
    return false;
  }
}

static void setLcs(MElement *t, std::unordered_map<MVertex *, double> &vSizes,
                   std::unordered_set<MVertex *> &bndVertices)
{
  auto setLc = [&](MVertex *vi, MVertex *vj) {
    bndVertices.insert(vi);
    bndVertices.insert(vj);
    double dx = vi->x() - vj->x();
    double dy = vi->y() - vj->y();
    double dz = vi->z() - vj->z();
    double l = std::sqrt(dx * dx + dy * dy + dz * dz);
    auto iti = vSizes.find(vi);
    auto itj = vSizes.find(vj);
    if(CTX::instance()->mesh.lcExtendFromBoundary == 2) {
      // use smallest edge length
      if(iti == vSizes.end() || iti->second > l) vSizes[vi] = l;
      if(itj == vSizes.end() || itj->second > l) vSizes[vj] = l;
    }
    else {
      // use largest edge length
      if(iti == vSizes.end() || iti->second < l) vSizes[vi] = l;
      if(itj == vSizes.end() || itj->second < l) vSizes[vj] = l;
    }
  };

  for(int i = 0; i < t->getNumEdges(); i++) {
    MEdge e = t->getEdge(i);
    setLc(e.getVertex(0), e.getVertex(1));
  }

  // use average edge length
  /*
  double l = 0;
  for(int i = 0; i < 3; i++){
    MEdge e = t->getEdge(i);
    MVertex *vi = e.getVertex(0);
    MVertex *vj = e.getVertex(1);
    double dx = vi->x()-vj->x();
    double dy = vi->y()-vj->y();
    double dz = vi->z()-vj->z();
    l += sqrt(dx * dx + dy * dy + dz * dz);
  }
  l /= 3;
  for(int i = 0; i < 3; i++){
    bndVertices.insert(t->getVertex(i));
    MEdge e = t->getEdge(i);
    MVertex *vi = e.getVertex(0);
    MVertex *vj = e.getVertex(1);
    auto iti = vSizes.find(vi);
    auto itj = vSizes.find(vj);
    // use largest edge length
    if (iti == vSizes.end() || iti->second > l) vSizes[vi] = l;
    if (itj == vSizes.end() || itj->second > l) vSizes[vj] = l;
  }
  */
}

static void setLcs(MTetrahedron *t,
                   std::unordered_map<MVertex *, double> &vSizes,
                   std::unordered_set<MVertex *> &bndVertices)
{
  for(int i = 0; i < 4; i++) {
    for(int j = i + 1; j < 4; j++) {
      MVertex *vi = t->getVertex(i);
      MVertex *vj = t->getVertex(j);

      if(bndVertices.find(vi) == bndVertices.end()) {
        auto iti = vSizes.find(vi);
        double const length =
          hypotenuse(vi->x() - vj->x(), vi->y() - vj->y(), vi->z() - vj->z());
        if(CTX::instance()->mesh.lcExtendFromBoundary == 2) {
          // use smallest edge length
          if(iti == vSizes.end() || iti->second > length) {
            vSizes[vi] = length;
          }
        }
        else {
          if(iti == vSizes.end() || iti->second < length) {
            vSizes[vi] = length;
          }
        }
      }

      if(bndVertices.find(vj) == bndVertices.end()) {
        auto itj = vSizes.find(vj);
        double const length =
          hypotenuse(vi->x() - vj->x(), vi->y() - vj->y(), vi->z() - vj->z());
        if(CTX::instance()->mesh.lcExtendFromBoundary == 2) {
          // use smallest edge length
          if(itj == vSizes.end() || itj->second > length) {
            vSizes[vj] = length;
          }
        }
        else {
          if(itj == vSizes.end() || itj->second < length) {
            vSizes[vj] = length;
          }
        }
      }
    }
  }
}

static void completeTheSetOfFaces(GModel *model, std::set<GFace *> &faces_bound)
{
  std::set<GFace *> toAdd;
  for(auto it = model->firstFace(); it != model->lastFace(); ++it) {
    if(faces_bound.find(*it) != faces_bound.end()) {
      if((*it)->compound.size()) {
        for(std::size_t i = 0; i < (*it)->compound.size(); ++i) {
          GFace *gf = static_cast<GFace *>((*it)->compound[i]);
          if(gf) toAdd.insert(gf);
        }
      }
    }
  }
  faces_bound.insert(toAdd.begin(), toAdd.end());
}

static GRegion *getRegionFromBoundingFaces(GModel *model,
                                           std::set<GFace *> &faces_bound)
{
  completeTheSetOfFaces(model, faces_bound);

  auto git = model->firstRegion();
  while(git != model->lastRegion()) {
    GRegion *gr = *git;
    ExtrudeParams *ep = gr->meshAttributes.extrude;
    if((ep && ep->mesh.ExtrudeMesh) ||
       gr->meshAttributes.method == MESH_TRANSFINITE) {
      // extruded meshes or transfinite should be considered as "void"
    }
    else {
      std::vector<GFace *> _faces = (*git)->faces();
      if(_faces.size() == faces_bound.size()) {
        bool ok = true;
        for(auto it = _faces.begin(); it != _faces.end(); ++it) {
          if(faces_bound.find(*it) == faces_bound.end()) ok = false;
        }
        if(ok) return *git;
      }
    }
    ++git;
  }
  return nullptr;
}

static void non_recursive_classify(MTet4 *t, std::list<MTet4 *> &theRegion,
                                   std::set<GFace *> &faces_bound,
                                   GRegion *bidon, GModel *model,
                                   const fs_cont &search)
{
  std::stack<MTet4 *> _stackounette;
  _stackounette.push(t);

  bool touchesOutsideBox = false;

  while(!_stackounette.empty()) {
    t = _stackounette.top();
    _stackounette.pop();
    if(!t) {
      Msg::Warning("A tetrahedron is not connected to a boundary face");
      touchesOutsideBox = true;
    }
    else if(!t->onWhat()) {
      theRegion.push_back(t);
      t->setOnWhat(bidon);
      bool FF[4] = {0, 0, 0, 0};
      for(int i = 0; i < 4; i++) {
        GFace *gfound = findInFaceSearchStructure(
          t->tet()->getVertex(faces[i][0]), t->tet()->getVertex(faces[i][1]),
          t->tet()->getVertex(faces[i][2]), search);
        if(gfound) {
          FF[i] = true;
          if(faces_bound.find(gfound) == faces_bound.end())
            faces_bound.insert(gfound);
        }
      }
      for(int i = 0; i < 4; i++) {
        if(!FF[i]) _stackounette.push(t->getNeigh(i));
      }
    }
  }
  if(touchesOutsideBox) faces_bound.clear();
}

static int isCavityCompatibleWithEmbeddedEdges(std::vector<MTet4 *> &cavity,
                                               std::vector<faceXtet> &shell,
                                               edgeContainerB &allEmbeddedEdges)
{
  if(allEmbeddedEdges.empty()) return 1;
  std::vector<MEdge> ed;
  ed.reserve(shell.size() * 3);

  for(auto it = shell.begin(); it != shell.end(); it++) {
    ed.push_back(MEdge(it->v[0], it->v[1]));
    ed.push_back(MEdge(it->v[1], it->v[2]));
    ed.push_back(MEdge(it->v[2], it->v[0]));
  }

  for(auto itc = cavity.begin(); itc != cavity.end(); ++itc) {
    for(int j = 0; j < 6; j++) {
      MEdge e = (*itc)->tet()->getEdge(j);
      if(std::find(ed.begin(), ed.end(), e) == ed.end() &&
         allEmbeddedEdges.find(e)) {
        return 0;
      }
    }
  }
  return 1;
}

static int isCavityCompatibleWithEmbeddedFace(
  const std::vector<MTet4 *> &cavity, const std::vector<faceXtet> &shell,
  const std::set<MFace, MFaceLessThan> &allEmbeddedFaces)
{
  if(allEmbeddedFaces.empty()) return 1;
  std::vector<MFace> shellFaces;
  shellFaces.reserve(shell.size());

  for(auto it = shell.begin(); it != shell.end(); it++) {
    const faceXtet &face = (*it);
    shellFaces.push_back(
      MFace(face.unsorted[0], face.unsorted[1], face.unsorted[2]));
  }

  for(auto itc = cavity.begin(); itc != cavity.end(); ++itc) {
    for(int j = 0; j < 4; j++) {
      MFace f = (*itc)->tet()->getFace(j);
      if((std::find(shellFaces.begin(), shellFaces.end(), f) ==
          shellFaces.end()) &&
         (allEmbeddedFaces.count(f) > 0)) {
        return 0;
      }
    }
  }
  return 1;
}

static void
refineRegionMTet4(GRegion *gr, int maxIter, double worstTetRadiusTarget,
                  std::vector<MTet4 *> &tets0, MTet4Factory &myFactory,
                  std::vector<double> &vSizes, std::vector<double> &vSizesBGM,
                  int &NUM,
                  const std::set<MFace, MFaceLessThan> &allEmbeddedFaces,
                  edgeContainerB &allEmbeddedEdges);

GFace *getSharedFace(GRegion *r1, GRegion *r2)
{
  std::vector<GFace *> f1 = r1->faces();
  std::vector<GFace *> f2 = r2->faces();
  for(GFace *f : f1) {
    if(std::find(f2.begin(), f2.end(), f) != f2.end()) return f;
  }
  return nullptr;
}

bool insertVertexInFaceTriangulation(GFace *gf, MVertex *v)
{
  double xyz[3] = {v->x(), v->y(), v->z()};
  const double eps = 1e-8;
  for(std::size_t i = 0; i < gf->triangles.size(); i++) {
    MTriangle *t = gf->triangles[i];
    double uvw[3];
    t->xyz2uvw(xyz, uvw);
    if(uvw[0] < -eps || uvw[1] < -eps || uvw[0] + uvw[1] > 1 + eps) continue;

    MVertex *a = t->getVertex(0), *b = t->getVertex(1), *c = t->getVertex(2);
    // xyz2uvw only checks the in-plane projection; also check that v
    // actually lies close to the plane of this specific triangle.
    double rebuilt[3] = {
      a->x() + uvw[0] * (b->x() - a->x()) + uvw[1] * (c->x() - a->x()),
      a->y() + uvw[0] * (b->y() - a->y()) + uvw[1] * (c->y() - a->y()),
      a->z() + uvw[0] * (b->z() - a->z()) + uvw[1] * (c->z() - a->z())};
    double dx = rebuilt[0] - xyz[0], dy = rebuilt[1] - xyz[1],
           dz = rebuilt[2] - xyz[2];
    double tol = eps * t->maxEdge();
    if(dx * dx + dy * dy + dz * dz > tol * tol) continue;

    gf->triangles.erase(gf->triangles.begin() + i);
    delete t;
    gf->triangles.push_back(new MTriangle(a, b, v));
    gf->triangles.push_back(new MTriangle(b, c, v));
    gf->triangles.push_back(new MTriangle(c, a, v));
    return true;
  }
  return false;
}

void classifyTetrahedraInRegions(std::vector<GRegion *> &regions,
                                 splitQuadRecovery *sqr)
{
  if(regions.size() < 2) return;

  GRegion *gr = regions[0];
  if(gr->tetrahedra.empty()) return;

  // Boundary recovery on a connected group of regions leaves every
  // tetrahedron of the whole group in regions[0]->tetrahedra, with no
  // per-tet region info yet (MTet4::onWhat() unset). Build adjacency and
  // flood-fill from each boundary, exactly like insertVerticesInRegion's own
  // classify step, then move each tet to the region it was found to belong
  // to (or drop it if it falls in the "void" outside every region).
  std::vector<MTet4 *> allTets;
  allTets.reserve(gr->tetrahedra.size());
  for(std::size_t i = 0; i < gr->tetrahedra.size(); i++) {
    gr->tetrahedra[i]->setVolumePositive();
    allTets.push_back(new MTet4(gr->tetrahedra[i], 0.));
  }
  gr->tetrahedra.clear();

  connectTets(allTets.begin(), allTets.end());

  fs_cont search;
  buildFaceSearchStructure(gr->model(), search, true); // only triangles
  if(sqr) search.insert(sqr->getTri().begin(), sqr->getTri().end());

  // Track every region a Steiner point gets claimed by below: a point
  // claimed by more than one region during this pass is not a genuine
  // interior point of either one -- it sits exactly on the interface
  // between them. This happens because meshGRegionBoundaryRecovery.cpp
  // unconditionally calls TetGen's suppresssteinerpoints(), which can
  // reclassify a facet-constrained Steiner point as a free interior point
  // (without moving its coordinates) once it determines the facet no
  // longer structurally needs it as a constraint -- TetGen has no notion
  // that this "facet" is actually a preserved interface between two of the
  // group's regions. See the follow-up pass after this loop.
  std::map<MVertex *, std::set<GRegion *>> multiRegionVertices;

  for(auto it = allTets.begin(); it != allTets.end(); ++it) {
    if(!(*it)->onWhat()) {
      std::list<MTet4 *> theRegion;
      std::set<GFace *> faces_bound;
      GRegion *bidon = (GRegion *)123;
      non_recursive_classify(*it, theRegion, faces_bound, bidon, gr->model(),
                             search);
      GRegion *myGRegion = getRegionFromBoundingFaces(gr->model(), faces_bound);
      if(myGRegion && myGRegion->tetrahedra.empty()) {
        for(auto it2 = theRegion.begin(); it2 != theRegion.end(); ++it2) {
          (*it2)->setOnWhat(myGRegion);
          // Make sure that Steiner points will end up in the right region
          std::vector<MVertex *> vertices;
          (*it2)->tet()->getVertices(vertices);
          for(auto itv = vertices.begin(); itv != vertices.end(); ++itv) {
            GEntity *oldGe = (*itv)->onWhat();
            if(oldGe != nullptr && oldGe->dim() == 3 && oldGe != myGRegion) {
              // The vertex is still registered in oldGe->mesh_vertices (it
              // was put there when created during boundary recovery on the
              // whole group, before per-region classification existed).
              // Drop it from there before re-adding it to myGRegion:
              // otherwise it ends up in two regions' mesh_vertices at once,
              // and refineMeshMMGGroup's/insertVerticesInRegion's cleanup
              // (which deletes every vertex of every region in the group)
              // double-frees it, corrupting the heap.
              std::vector<MVertex *> &oldMV = oldGe->mesh_vertices;
              oldMV.erase(std::remove(oldMV.begin(), oldMV.end(), *itv),
                          oldMV.end());
              myGRegion->addMeshVertex(*itv);
              (*itv)->setEntity(myGRegion);
              multiRegionVertices[*itv].insert(static_cast<GRegion *>(oldGe));
              multiRegionVertices[*itv].insert(myGRegion);
            }
          }
        }
      }
      else {
        // the tets are in the void
        for(auto it2 = theRegion.begin(); it2 != theRegion.end(); ++it2)
          (*it2)->setDeleted(true);
      }
    }
  }
  search.clear();

  for(auto &pr : multiRegionVertices) {
    MVertex *v = pr.first;
    std::set<GRegion *> &claimants = pr.second;
    if(claimants.size() != 2) {
      Msg::Warning("Mesh vertex %lu was claimed by %zu regions while "
                   "classifying a multi-domain mesh; leaving it as is",
                   v->getNum(), claimants.size());
      continue;
    }
    auto cit = claimants.begin();
    GRegion *r1 = *cit++;
    GRegion *r2 = *cit;
    GFace *shared = getSharedFace(r1, r2);
    if(!shared) {
      Msg::Warning("Mesh vertex %lu is shared between regions %d and %d "
                   "with no common surface; leaving it classified on a "
                   "region",
                   v->getNum(), r1->tag(), r2->tag());
      continue;
    }
    if(!insertVertexInFaceTriangulation(shared, v)) {
      Msg::Warning("Could not locate a triangle of surface %d containing "
                   "mesh vertex %lu; leaving it classified on a region",
                   shared->tag(), v->getNum());
      continue;
    }
    GEntity *currentGe = v->onWhat();
    if(currentGe) {
      std::vector<MVertex *> &curMV = currentGe->mesh_vertices;
      curMV.erase(std::remove(curMV.begin(), curMV.end(), v), curMV.end());
    }
    shared->addMeshVertex(v);
    v->setEntity(shared);
  }

  for(MTet4 *t : allTets) {
    if(!t->isDeleted() && t->onWhat())
      t->onWhat()->tetrahedra.push_back(t->tet());
    else
      delete t->tet();
    delete t;
  }
}

void insertVerticesInRegion(GRegion *gr, int maxIter,
                            double worstTetRadiusTarget, bool _classify,
                            splitQuadRecovery *sqr)
{
#ifdef DEBUG_BOUNDARY_RECOVERY
  testIfBoundaryIsRecovered(gr);
#endif

  std::vector<double> vSizes, vSizesBGM;
  MTet4Factory myFactory;
  // initial tets, ordered as the tetRadiusQueue (and the former std::set
  // container) would order them, so that the classification below - whose
  // iteration order can influence vertex and element ordering - is unchanged
  std::vector<MTet4 *> tets0;
  int NUM = 0;

  // leave this in a block so the map gets deallocated directly
  {
    std::unordered_map<MVertex *, double> vSizesMap;
    std::unordered_set<MVertex *> bndVertices;

    for(auto rit = gr->model()->firstRegion(); rit != gr->model()->lastRegion();
        ++rit) {
      std::vector<GEdge *> const &e = (*rit)->embeddedEdges();
      for(auto it = e.begin(); it != e.end(); ++it) {
        for(std::size_t i = 0; i < (*it)->lines.size(); i++) {
          MVertex *vi = (*it)->lines[i]->getVertex(0);
          MVertex *vj = (*it)->lines[i]->getVertex(1);
          double dx = vi->x() - vj->x();
          double dy = vi->y() - vj->y();
          double dz = vi->z() - vj->z();
          double l = std::sqrt(dx * dx + dy * dy + dz * dz);

          auto iti = vSizesMap.find(vi);
          auto itj = vSizesMap.find(vj);

          // smallest tet edge
          if(iti == vSizesMap.end() || iti->second > l) vSizesMap[vi] = l;
          if(itj == vSizesMap.end() || itj->second > l) vSizesMap[vj] = l;
        }
      }
    }

    for(auto rit = gr->model()->firstRegion(); rit != gr->model()->lastRegion();
        ++rit) {
      std::vector<GVertex *> const &vertices = (*rit)->embeddedVertices();
      for(auto it = vertices.begin(); it != vertices.end(); ++it) {
        MVertex *v = (*it)->getMeshVertex(0);
        double l = (*it)->prescribedMeshSizeAtVertex();
        auto itv = vSizesMap.find(v);
        if(itv == vSizesMap.end() || itv->second > l) vSizesMap[v] = l;
      }
    }

    for(auto it = gr->model()->firstFace(); it != gr->model()->lastFace();
        ++it) {
      GFace *gf = *it;
      for(std::size_t i = 0; i < gf->triangles.size(); i++) {
        setLcs(gf->triangles[i], vSizesMap, bndVertices);
      }
      for(std::size_t i = 0; i < gf->quadrangles.size(); i++) {
        setLcs(gf->quadrangles[i], vSizesMap, bndVertices);
      }
    }
    // if(sqr) {
    //      for(auto it = sqr->getTri().begin(); it != sqr->getTri().end();
    //      ++it) setLcs(it->first, vSizesMap, bndVertices);
    //}
    for(std::size_t i = 0; i < gr->tetrahedra.size(); i++)
      setLcs(gr->tetrahedra[i], vSizesMap, bndVertices);

    // assign the vertex indices in the same order (by vertex number) as the
    // former MVertexPtrLessThan-sorted map
    std::vector<std::pair<std::size_t, std::pair<MVertex *, double>>> bynum;
    bynum.reserve(vSizesMap.size());
    for(auto it = vSizesMap.begin(); it != vSizesMap.end(); ++it)
      bynum.push_back(std::make_pair(it->first->getNum(),
                                     std::make_pair(it->first, it->second)));
    std::sort(
      bynum.begin(), bynum.end(),
      [](const std::pair<std::size_t, std::pair<MVertex *, double>> &a,
         const std::pair<std::size_t, std::pair<MVertex *, double>> &b) {
        return a.first < b.first;
      });
    for(auto &p : bynum) {
      p.second.first->setIndex(NUM++);
      vSizes.push_back(p.second.second);
      vSizesBGM.push_back(p.second.second);
    }
  }

  for(std::size_t i = 0; i < gr->tetrahedra.size(); i++) {
    gr->tetrahedra[i]->setVolumePositive();
    tets0.push_back(myFactory.Create(gr->tetrahedra[i], vSizes, vSizesBGM));
  }
  std::sort(tets0.begin(), tets0.end(), compareTet4Ptr());

  gr->tetrahedra.clear();

  connectTetsFast(tets0.begin(), tets0.end());

  // classify the tets on the right region

  if(_classify) {
    fs_cont search;
    buildFaceSearchStructure(gr->model(), search, true); // only triangles
    if(sqr) search.insert(sqr->getTri().begin(), sqr->getTri().end());

    for(auto it = tets0.begin(); it != tets0.end(); ++it) {
      if(!(*it)->onWhat()) {
        std::list<MTet4 *> theRegion;
        std::set<GFace *> faces_bound;
        GRegion *bidon = (GRegion *)123;
        double _t1 = Cpu(), _w1 = TimeOfDay();
        Msg::Debug("start with a non classified tet");
        non_recursive_classify(*it, theRegion, faces_bound, bidon, gr->model(),
                               search);
        double _t2 = Cpu(), _w2 = TimeOfDay();
        Msg::Debug("Found %d tets with %d faces (Wall %gs, CPU %gs)",
                   theRegion.size(), faces_bound.size(), _w2 - _w1, _t2 - _t1);
        GRegion *myGRegion =
          getRegionFromBoundingFaces(gr->model(), faces_bound);
        if(myGRegion && myGRegion->tetrahedra.empty()) {
          // a geometrical region (with no mesh) associated to the list of faces
          // has been found
          Msg::Info("Found volume %d", myGRegion->tag());
          for(auto it2 = theRegion.begin(); it2 != theRegion.end(); ++it2) {
            (*it2)->setOnWhat(myGRegion);

            // Make sure that Steiner points will end up in the right region
            std::vector<MVertex *> vertices;
            (*it2)->tet()->getVertices(vertices);
            for(auto itv = vertices.begin(); itv != vertices.end(); ++itv) {
              if((*itv)->onWhat() != nullptr && (*itv)->onWhat()->dim() == 3 &&
                 (*itv)->onWhat() != myGRegion) {
                myGRegion->addMeshVertex((*itv));
                (*itv)->setEntity(myGRegion);
              }
            }
          }
        }
        else {
          // the tets are in the void
          Msg::Info("Found void region");
          for(auto it2 = theRegion.begin(); it2 != theRegion.end(); ++it2)
            (*it2)->setDeleted(true);
        }
      }
    }
    search.clear();
  }
  else {
    // FIXME ... too simple
    for(auto it = tets0.begin(); it != tets0.end(); ++it) (*it)->setOnWhat(gr);
  }

  // store all embedded edges and faces
  std::set<MFace, MFaceLessThan> allEmbeddedFaces;
  std::size_t N = 0;
  for(auto it = gr->model()->firstRegion(); it != gr->model()->lastRegion();
      ++it) {
    for(auto e : (*it)->embeddedEdges()) N += e->getNumMeshElements();
  }
  edgeContainerB allEmbeddedEdges(N);
  for(auto it = gr->model()->firstRegion(); it != gr->model()->lastRegion();
      ++it) {
    createAllEmbeddedFaces((*it), allEmbeddedFaces);
    createAllEmbeddedEdges((*it), allEmbeddedEdges);
  }
  if(allEmbeddedFaces.empty()) {
    // the neighbors computed before the classification are still valid: only
    // remove the links towards the tets that were deleted because they lie in
    // the void, exactly as reconnecting the alive tets from scratch would
    for(auto it = tets0.begin(); it != tets0.end(); ++it) {
      for(int i = 0; i < 4; i++) {
        MTet4 *n = (*it)->getNeigh(i);
        if(n && n->isDeleted()) (*it)->setNeigh(i, nullptr);
      }
    }
  }
  else {
    // rebuild the adjacencies without connecting tets across embedded faces
    for(auto it = tets0.begin(); it != tets0.end(); ++it) {
      (*it)->setNeigh(0, nullptr);
      (*it)->setNeigh(1, nullptr);
      (*it)->setNeigh(2, nullptr);
      (*it)->setNeigh(3, nullptr);
    }
    connectTets(tets0.begin(), tets0.end(), &allEmbeddedFaces);
  }
  Msg::Debug("All %d tets were connected", tets0.size());

  if(CTX::instance()->mesh.flatRefine3D)
    refineRegionFlat(gr, maxIter, worstTetRadiusTarget, tets0, myFactory,
                     vSizes, vSizesBGM, NUM, allEmbeddedFaces,
                     allEmbeddedEdges);
  else
    refineRegionMTet4(gr, maxIter, worstTetRadiusTarget, tets0, myFactory,
                      vSizes, vSizesBGM, NUM, allEmbeddedFaces,
                      allEmbeddedEdges);
}

// Bowyer-Watson refinement kernel: consumes the classified and connected tets
// of tets0 (all MTet4 wrappers are freed), grows vSizes/vSizesBGM and the
// vertex index counter NUM as nodes are inserted, adds the new vertices and
// the final tets to their respective regions
static void
refineRegionMTet4(GRegion *gr, int maxIter, double worstTetRadiusTarget,
                  std::vector<MTet4 *> &tets0, MTet4Factory &myFactory,
                  std::vector<double> &vSizes, std::vector<double> &vSizesBGM,
                  int &NUM,
                  const std::set<MFace, MFaceLessThan> &allEmbeddedFaces,
                  edgeContainerB &allEmbeddedEdges)
{
  tetRadiusQueue allTets(myFactory, worstTetRadiusTarget);

  for(auto t : tets0) allTets.push(t);
  tets0.clear();

  // alive tets whose queue entry was consumed by a failed insertion
  std::vector<MTet4 *> failedTets;

  int ITER = 0, REALCOUNT = 0;
  int NB_CORRECTION_OF_CAVITY = 0;
  int COUNT_MISS_1 = 0;
  int COUNT_MISS_2 = 0;

  double t1 = TimeOfDay();

  // scratch vectors reused across iterations
  std::vector<faceXtet> shell;
  std::vector<MTet4 *> cavity;

  // main loop in Delaunay inserstion starts here

  while(1) {
    if(maxIter > 0 && ITER >= maxIter) {
      Msg::Info("Max. number of iterations reached (%d) - stopping insertion",
                ITER);
      break;
    }
    if(allTets.empty()) {
      if(!allTets.totalSize())
        Msg::Warning("No tetrahedra in region %d", gr->tag());
      break;
    }

    MTet4 *worst = allTets.top();

    if(worst->isDeleted()) {
      allTets.pop();
      myFactory.Free(worst);
    }
    else {
      if(ITER++ % 500 == 0)
        Msg::Info("It. %d - %d nodes created - worst tet radius %g (nodes "
                  "removed %d %d)",
                  ITER - 1, REALCOUNT, worst->getRadius(), COUNT_MISS_1,
                  COUNT_MISS_2);
      if(worst->getRadius() < worstTetRadiusTarget) break;
      allTets.pop();
      MTet4 *popped = worst;

      double center[3];
      double uvw[3];
      // circumcenter cached at creation, computed with the exact same
      // floating-point operations as tetcircumcenter()
      worst->cachedCircumcenter(center);

      // A TEST !!!
      shell.clear();
      cavity.clear();
      MVertex vv(center[0], center[1], center[2], worst->onWhat());
      findCavity(shell, cavity, &vv, worst);
      bool FOUND = false;
      for(auto itc = cavity.begin(); itc != cavity.end(); ++itc) {
        MTetrahedron *toto = (*itc)->tet();
        // (*itc)->setDeleted(false);
        toto->xyz2uvw(center, uvw);
        // f("uvw = %g %g %g\n", uvw[0], uvw[1], uvw[2]);
        if(toto->isInside(uvw[0], uvw[1], uvw[2])) {
          worst = (*itc);
          FOUND = true;
          break;
        }
      }
      // END TEST

      if(FOUND && (!allEmbeddedEdges.empty() || !allEmbeddedFaces.empty())) {
        FOUND =
          isCavityCompatibleWithEmbeddedEdges(cavity, shell,
                                              allEmbeddedEdges) &&
          isCavityCompatibleWithEmbeddedFace(cavity, shell, allEmbeddedFaces);
      }

      bool correctedCavityIncompatibleWithEmbeddedEntities = false;

      if(FOUND) {
        MVertex *v =
          new MVertex(center[0], center[1], center[2], worst->onWhat());
        v->setIndex(NUM++);
#ifdef PRINT_TETS
        printTets("before.pos", cavity, true);
#endif
        bool starShaped = true;
        bool correctCavity = false;
        while(1) {
          int k = makeCavityStarShaped(shell, cavity, v);
          if(k == -1) {
            starShaped = false;
            break;
          }
          else if(k == 0)
            break;
          else if(k == 1)
            correctCavity = true;
        }
        if(correctCavity && starShaped) {
          NB_CORRECTION_OF_CAVITY++;
          if(!isCavityCompatibleWithEmbeddedEdges(cavity, shell,
                                                  allEmbeddedEdges) ||
             !isCavityCompatibleWithEmbeddedFace(cavity, shell,
                                                 allEmbeddedFaces)) {
            correctedCavityIncompatibleWithEmbeddedEntities = true;
          }
        }
        double lc1 = (1 - uvw[0] - uvw[1] - uvw[2]) *
                       vSizes[worst->tet()->getVertex(0)->getIndex()] +
                     uvw[0] * vSizes[worst->tet()->getVertex(1)->getIndex()] +
                     uvw[1] * vSizes[worst->tet()->getVertex(2)->getIndex()] +
                     uvw[2] * vSizes[worst->tet()->getVertex(3)->getIndex()];
        double lc2 =
          BGM_MeshSize(worst->onWhat(), 0, 0, center[0], center[1], center[2]);

        if(correctedCavityIncompatibleWithEmbeddedEntities || !starShaped ||
           !insertVertexB(shell, cavity, v, lc1, lc2, vSizes, vSizesBGM, worst,
                          myFactory, allTets, allEmbeddedFaces)) {
          COUNT_MISS_1++;
          popped->forceRadius(0.);
          failedTets.push_back(popped);
          for(auto itc = cavity.begin(); itc != cavity.end(); ++itc)
            (*itc)->setDeleted(false);
          delete v;
          NUM--;
        }
        else {
          vSizes.push_back(lc1);
          vSizesBGM.push_back(lc2);
          REALCOUNT++;
          v->onWhat()->mesh_vertices.push_back(v);
        }
      }

      else {
        popped->forceRadius(0.);
        failedTets.push_back(popped);
        COUNT_MISS_2++;
        for(auto itc = cavity.begin(); itc != cavity.end(); ++itc)
          (*itc)->setDeleted(false);
      }
    }
  }

  // free the deleted tets and recover the remaining ones, ordered as the
  // former std::set container would order them
  std::vector<MTet4 *> aliveTets;
  allTets.drainSorted(failedTets, aliveTets);

  double t2 = TimeOfDay();
  double dt = (t2 - t1);
  int COUNT_MISS = COUNT_MISS_1 + COUNT_MISS_2;
  Msg::Info("3D refinement terminated (%d nodes total):", (int)vSizes.size());
  Msg::Info(" - %d Delaunay cavities modified for star shapeness",
            NB_CORRECTION_OF_CAVITY);
  Msg::Info(" - %d nodes could not be inserted", COUNT_MISS);
  Msg::Info(" - %d tetrahedra created in %g sec. (%d tets/s)", aliveTets.size(),
            dt, (int)(aliveTets.size() / dt));

  // relocate vertices
  int nbReloc = 0;
  for(int SM = 0; SM < CTX::instance()->mesh.nbSmoothing; SM++) {
    for(auto it = aliveTets.begin(); it != aliveTets.end(); ++it) {
      if(!(*it)->isDeleted()) {
        double qq = (*it)->getQuality();
        if(qq < .4)
          for(int i = 0; i < 4; i++) {
            if(smoothVertex(*it, i, qmTetrahedron::QMTET_GAMMA)) nbReloc++;
          }
      }
    }
  }

  Msg::Info("%d node relocations", nbReloc);

  for(auto it = aliveTets.begin(); it != aliveTets.end(); ++it) {
    MTet4 *worst = *it;
    if(!worst->isDeleted()) {
      worst->onWhat()->tetrahedra.push_back(worst->tet());
      worst->tet() = nullptr;
    }
    myFactory.Free(worst);
  }
}
