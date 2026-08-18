// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// Mesh.Algorithm = 12, "Frontal-Delaunay Optimized": a performance-oriented
// variant of the 2D Frontal-Delaunay algorithm (Mesh.Algorithm = 6,
// bowyerWatsonFrontal in meshGFaceDelaunayInsertion.cpp). The algorithm is
// the same - same in-circle and optimal-point formulas, same insertion
// checks, same active-front priority - but it runs on an indexed
// structure-of-arrays backend instead of algo 6's std::set<MTri3*> of
// individually allocated triangles:
//  - vertices are plain parallel arrays (parametric coordinates, sizes, xyz,
//    dimension) indexed by a vertex id, kept sorted by MVertex::getNum();
//  - triangles are vertex-id triplets in parallel arrays (neighbors, metric
//    circumradius, flags) indexed by a triangle slot, with deleted slots
//    recycled through a free-list;
//  - the active front is a binary heap of (radius, slot) entries instead of
//    a std::set ordered by radius;
//  - the cavity is grown with an explicit stack instead of recursion.
// The in-circle and optimal-point computations follow algo 6's formulas.
// For isotropic metrics (and planar surfaces) they use a circumcircle
// cached per triangle: the same quantity, computed once in closed form
// instead of per test, whose different floating-point route can flip the
// rare near-cocircular decisions. The mesh can therefore differ from
// algo 6 at rounding class on isotropic/planar cases (node counts within
// ~0.1%, no bias); anisotropic metrics and curved-surface optimal points
// keep algo 6's exact code paths. The algorithm remains fully
// deterministic for a given input, and the final triangles are emitted in
// slot order instead of radius order.

#include <set>
#include <array>
#include <algorithm>
#include <limits>
#include <numeric>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "robustPredicates.h"
#include "BackgroundMesh.h"
#include "meshGFaceDelaunayInsertion.h"
#include "meshGFaceOptimize.h"
#include "meshGFace.h"
#include "qualityMeasures.h"
#include "GFace.h"
#include "Numeric.h"
#include "Context.h"
#include "discreteFace.h"
#include "intersectCurveSurface.h"

static constexpr double ONE_THIRD = 1.0 / 3.0;
// radius threshold (in metric units) below which a triangle is small enough
// and does not need to be refined
static const double LIMIT_ = 0.5 * std::sqrt(2.0);

static inline bool intersection_segments_2(double *p1, double *p2, double *q1,
                                           double *q2)
{
  double a = robustPredicates::orient2d(p1, p2, q1);
  double b = robustPredicates::orient2d(p1, p2, q2);
  if(a * b > 0) return 0;
  a = robustPredicates::orient2d(q1, q2, p1);
  b = robustPredicates::orient2d(q1, q2, p2);
  if(a * b > 0) return 0;
  return 1;
}

// Circumcenter x and squared circumradius Radius2 of the triangle (pa,pb,pc)
// in the metric (a b; b d): x is equidistant from the three points, i.e.
// (x-pb) M (x-pb) = (x-pa) M (x-pa) and the same for pc, a linear 2x2 system.
// Same formulas as algo 6 (circumCenterMetric in
// meshGFaceDelaunayInsertion.cpp); x is (0,0) if the system is singular.
static void circumCenterMetric(double *pa, double *pb, double *pc,
                               const double *metric, double *x, double &Radius2)
{
  double sys[2][2];
  double rhs[2];

  const double a = metric[0];
  const double b = metric[1];
  const double d = metric[2];

  if(b == 0.0) {
    // Diagonal metric: the cross terms "+ 2*b*(...)" are exactly zero, so
    // drop them. Bit-identical to the general branch below (adding 0.0),
    // with ~25% fewer operations. This is the common case.
    sys[0][0] = 2. * a * (pa[0] - pb[0]);
    sys[0][1] = 2. * d * (pa[1] - pb[1]);
    sys[1][0] = 2. * a * (pa[0] - pc[0]);
    sys[1][1] = 2. * d * (pa[1] - pc[1]);
    rhs[0] =
      a * (pa[0] * pa[0] - pb[0] * pb[0]) + d * (pa[1] * pa[1] - pb[1] * pb[1]);
    rhs[1] =
      a * (pa[0] * pa[0] - pc[0] * pc[0]) + d * (pa[1] * pa[1] - pc[1] * pc[1]);
  }
  else {
    sys[0][0] = 2. * a * (pa[0] - pb[0]) + 2. * b * (pa[1] - pb[1]);
    sys[0][1] = 2. * d * (pa[1] - pb[1]) + 2. * b * (pa[0] - pb[0]);
    sys[1][0] = 2. * a * (pa[0] - pc[0]) + 2. * b * (pa[1] - pc[1]);
    sys[1][1] = 2. * d * (pa[1] - pc[1]) + 2. * b * (pa[0] - pc[0]);
    rhs[0] = a * (pa[0] * pa[0] - pb[0] * pb[0]) +
             d * (pa[1] * pa[1] - pb[1] * pb[1]) +
             2. * b * (pa[0] * pa[1] - pb[0] * pb[1]);
    rhs[1] = a * (pa[0] * pa[0] - pc[0] * pc[0]) +
             d * (pa[1] * pa[1] - pc[1] * pc[1]) +
             2. * b * (pa[0] * pa[1] - pc[0] * pc[1]);
  }

  // Inlined sys2x2 (Numeric.cpp), which is otherwise a cross-TU call per
  // in-circle test. Same arithmetic (norm uses x*x, identical to pow(x,2)
  // on this libm), so the result matches algo 6 bit-for-bit.
  {
    const double det = sys[0][0] * sys[1][1] - sys[1][0] * sys[0][1];
    const double norm = sys[0][0] * sys[0][0] + sys[1][1] * sys[1][1] +
                        sys[0][1] * sys[0][1] + sys[1][0] * sys[1][0];
    if(norm == 0.0 || std::abs(det) / norm < 1.e-16) { x[0] = x[1] = 0.0; }
    else {
      const double ud = 1.0 / det;
      x[0] = (rhs[0] * sys[1][1] - sys[0][1] * rhs[1]) * ud;
      x[1] = (sys[0][0] * rhs[1] - sys[1][0] * rhs[0]) * ud;
    }
  }

  Radius2 =
    (x[0] - pa[0]) * (x[0] - pa[0]) * a + (x[1] - pa[1]) * (x[1] - pa[1]) * d;
  if(b != 0.0) Radius2 += 2. * (x[0] - pa[0]) * (x[1] - pa[1]) * b;
}

static double lengthMetric(const double p[2], const double q[2],
                           const double metric[3])
{
  return std::sqrt((p[0] - q[0]) * metric[0] * (p[0] - q[0]) +
                   2 * (p[0] - q[0]) * metric[1] * (p[1] - q[1]) +
                   (p[1] - q[1]) * metric[2] * (p[1] - q[1]));
}

static constexpr std::size_t INVALID_TRIANGLE =
  std::numeric_limits<std::size_t>::max();

struct IndexedMeshData;

// Per-triangle state, packed in one byte per slot (IndexedMeshData::flags)
enum TriangleFlag : unsigned char {
  TRI_NONE = 0,
  TRI_DELETED = 1, // removed from the mesh (cavity), pending slot release
  TRI_IN_QUEUE = 2, // an active-queue entry references this slot
  TRI_FREE_SLOT = 4 // slot is in the free-list, ready for reuse
};

static inline TriangleFlag operator|(TriangleFlag a, TriangleFlag b)
{
  return TriangleFlag((unsigned char)a | (unsigned char)b);
}
static inline TriangleFlag operator&(TriangleFlag a, TriangleFlag b)
{
  return TriangleFlag((unsigned char)a & (unsigned char)b);
}
static inline TriangleFlag operator~(TriangleFlag a)
{
  return TriangleFlag(~(unsigned char)a);
}
static inline TriangleFlag &operator|=(TriangleFlag &a, TriangleFlag b)
{
  return a = a | b;
}
static inline TriangleFlag &operator&=(TriangleFlag &a, TriangleFlag b)
{
  return a = a & b;
}

// Oriented edge iFac of triangle t1, with its vertex ids stored sorted
// (ori records whether they were swapped) - the indexed counterpart of
// edgeXface (meshGFaceDelaunayInsertion.h).
struct IndexedEdgeFace {
  std::size_t v[2];
  std::size_t t1;
  int i1;
  int ori;

  IndexedEdgeFace(const IndexedMeshData &data, std::size_t t, int iFac);

  inline bool operator<(const IndexedEdgeFace &other) const
  {
    if(v[0] < other.v[0]) return true;
    if(v[0] > other.v[0]) return false;
    return v[1] < other.v[1];
  }

  inline bool operator==(const IndexedEdgeFace &other) const
  {
    return v[0] == other.v[0] && v[1] == other.v[1];
  }
};

// All the data of the algorithm, in structure-of-arrays layout.
//
// Vertices are parallel arrays indexed by a vertex id: parametric
// coordinates and sizes (same content as algo 6's bidimMeshData), xyz
// (interleaved, one cache line) and onWhat()->dim(), so the hot loop never
// needs the MVertex object. The import fills the arrays in MVertex::getNum()
// order and the refinement appends its vertices in creation order, so the
// id is a creation-order key (see faceKey). Internal (embedded) edges are
// stored as sorted id pairs, so the cavity walk needs no MEdge/MVertex.
//
// Triangles are parallel arrays indexed by a triangle slot id: vertex-id
// triplets, neighbor slots, metric circumradius and state flags, replacing
// algo 6's std::set<MTri3*> of individually allocated objects. Deleted
// slots are recycled through a free-list, with one invariant: a slot that
// is still referenced by an active-queue entry is not released until that
// entry is popped (see releaseTriangleSlot callers and
// IndexedActiveQueue::pop), so a queue entry never designates a reused slot.
struct IndexedMeshData {
  // per-vertex arrays
  std::vector<double> Us, Vs, vSizes, vSizesBGM;
  // MVertex backing per vertex id. Filled for the imported block; interior
  // slots stay null during meshing and are materialized at transfer.
  std::vector<MVertex *> vertices;
  std::vector<std::array<double, 3>> vxyz;
  std::vector<char> vdim;
  // internal (embedded) edges as sorted id pairs, in a sorted vector
  // (immutable after import, looked up with std::binary_search)
  std::vector<std::pair<std::size_t, std::size_t>> internalEdgeIds;
  // Number of imported vertices; slots >= numBoundary are the interior
  // vertices created by the refinement, materialized at transfer.
  std::size_t numBoundary = 0;
  // Hoisted per-face facts, constant during meshing but not free to query
  // (geomType() is virtual, the discreteFace dynamic_cast has a cost and
  // Extend1dMeshIn2dSurfaces re-reads CTX and the face attributes). Set at
  // import.
  discreteFace *discrete = nullptr;
  bool planar = false;
  bool extend1d = false;
  // per-triangle arrays
  std::vector<std::array<std::size_t, 3>> triangles;
  std::vector<std::array<std::size_t, 3>> neigh;
  std::vector<double> circumRadius;
  // Per-triangle parametric circumcircle {cx, cy, r^2}, computed once
  // (closed form) at creation and used by the in-circle test for isotropic
  // metrics. For M = lambda*I the metric circumcircle equals the parametric
  // one (lambda cancels), so this is the same quantity as algo 6's per-test
  // metric solve; only the floating-point route differs, flipping the rare
  // near-cocircular decisions (rounding-class divergence from algo 6).
  // Anisotropic metrics keep the exact per-test solve.
  std::vector<std::array<double, 3>> circumCircle;
  std::vector<TriangleFlag> flags;
  std::vector<std::size_t> freeTriangleSlots;
  // Original MTriangle of imported triangles (reused at transfer), null for
  // triangles created by the refinement (materialized at transfer).
  std::vector<MTriangle *> sourceTriangles;
  // Scratch buffers reused across insertions.
  std::vector<IndexedEdgeFace> shellBuffer;
  std::vector<std::size_t> cavityBuffer;
  std::vector<std::size_t> cavityStack;
  std::vector<std::size_t> newCavityBuffer;

  inline MVertex *vertex(std::size_t i) const { return vertices[i]; }

  // Register a newly inserted vertex, SoA only - no MVertex is created
  // until the transfer. It is always interior to the face (dim 2), and
  // unlike at import no parametric-coordinate override applies (the
  // periodic map can only contain pre-existing vertices).
  std::size_t addInteriorVertex(double u, double v, double x, double y,
                                double z, double size, double sizeBGM)
  {
    const std::size_t idx = Us.size();
    Us.push_back(u);
    Vs.push_back(v);
    vSizes.push_back(size);
    vSizesBGM.push_back(sizeBGM);
    vertices.push_back(nullptr);
    vxyz.push_back({{x, y, z}});
    vdim.push_back(2);
    return idx;
  }

  // Rejected insertion: drop the vertex from every array.
  void removeLastInteriorVertex()
  {
    Us.pop_back();
    Vs.pop_back();
    vSizes.pop_back();
    vSizesBGM.pop_back();
    vertices.pop_back();
    vxyz.pop_back();
    vdim.pop_back();
  }

  void releaseTriangleSlot(std::size_t t)
  {
    if(flags[t] & TRI_FREE_SLOT) return;
    if(sourceTriangles[t]) {
      delete sourceTriangles[t];
      sourceTriangles[t] = nullptr;
    }
    flags[t] |= TRI_FREE_SLOT;
    freeTriangleSlots.push_back(t);
  }

  // Sorted vertex-id triplet of triangle t, computed on demand (only used
  // by the active-front comparator on circum-radius ties, which are rare).
  // Comparing id triplets is identical to comparing algo 6's sorted
  // getNum() triplets because both are creation-order keys: the imported
  // block is sorted by getNum() and the refinement creates its vertices in
  // id order, exactly as algo 6 creates its vertices in num order.
  std::array<std::size_t, 3> faceKey(std::size_t t) const
  {
    std::array<std::size_t, 3> key = triangles[t];
    std::sort(key.begin(), key.end());
    return key;
  }
};

// Active-front heap element. The circum radius is stored inline (packed with
// the triangle index) so the comparator does not chase circumRadius[idx] - a
// dependent random-access load - on every heap sift. A triangle's radius
// is fixed once it is in the queue (it is only written at creation and, for the
// just-popped "worst", after removal; in-queue deleted triangles keep their
// slot until popped), so the packed value always equals circumRadius[idx] and
// the ordering is identical.
struct IndexedActiveEntry {
  double radius;
  std::size_t t;
};

// Same priority as algo 6's compareTri3Ptr: largest circumradius first, ties
// broken on the sorted vertex triplet (see IndexedMeshData::faceKey).
struct IndexedActiveCompare {
  const IndexedMeshData *data;

  bool operator()(const IndexedActiveEntry &a,
                  const IndexedActiveEntry &b) const
  {
    if(a.radius < b.radius) return true;
    if(a.radius > b.radius) return false;
    const std::array<std::size_t, 3> ka = data->faceKey(a.t);
    const std::array<std::size_t, 3> kb = data->faceKey(b.t);
    if(kb < ka) return true;
    if(ka < kb) return false;
    return a.t > b.t;
  }
};

// The active front as a contiguous binary heap (std::push_heap/pop_heap)
// instead of algo 6's std::set<MTri3*>: same top element at every pop, no
// per-node allocation. The TRI_IN_QUEUE flag gives the O(1) membership test
// that the set gave for free.
struct IndexedActiveQueue {
  IndexedMeshData *data;
  IndexedActiveCompare compare;
  std::vector<IndexedActiveEntry> heap;

  explicit IndexedActiveQueue(IndexedMeshData *d) : data(d), compare{d} {}

  inline bool empty() const { return heap.empty(); }

  void push(std::size_t t)
  {
    if(data->flags[t] & TRI_IN_QUEUE) return;
    data->flags[t] |= TRI_IN_QUEUE;
    heap.push_back({data->circumRadius[t], t});
    std::push_heap(heap.begin(), heap.end(), compare);
  }

  void pushUnordered(std::size_t t)
  {
    if(data->flags[t] & TRI_IN_QUEUE) return;
    data->flags[t] |= TRI_IN_QUEUE;
    heap.push_back({data->circumRadius[t], t});
  }

  void makeHeap() { std::make_heap(heap.begin(), heap.end(), compare); }

  std::size_t pop()
  {
    std::pop_heap(heap.begin(), heap.end(), compare);
    std::size_t t = heap.back().t;
    heap.pop_back();
    data->flags[t] &= ~TRI_IN_QUEUE;
    if(data->flags[t] & TRI_DELETED) data->releaseTriangleSlot(t);
    return t;
  }
};

// Queue radius of a triangle - the same quantity, computed with the same
// formulas, as the MTri3 constructor (meshGFaceDelaunayInsertion.cpp), for
// each of the three MTri3::radiusNorm conventions.
static double computeRadius(const IndexedMeshData &data,
                            const std::array<std::size_t, 3> &tri, double lc,
                            GFace *gf, MTriangle *source = nullptr)
{
  double center[3];
  double pa[3] = {data.vxyz[tri[0]][0], data.vxyz[tri[0]][1],
                  data.vxyz[tri[0]][2]};
  double pb[3] = {data.vxyz[tri[1]][0], data.vxyz[tri[1]][1],
                  data.vxyz[tri[1]][2]};
  double pc[3] = {data.vxyz[tri[2]][0], data.vxyz[tri[2]][1],
                  data.vxyz[tri[2]][2]};
  double radius = 0.0;

  if(MTri3::radiusNorm == 3) {
    // same chain as MTriangle::gammaShapeMeasure -> qmTriangle::gamma
    radius = 1. / qmTriangle::gamma(pa[0], pa[1], pa[2], pb[0], pb[1], pb[2],
                                    pc[0], pc[1], pc[2]);
  }
  else if(MTri3::radiusNorm == 2) {
    circumCenterXYZ(pa, pb, pc, center);
    const double dx = pa[0] - center[0];
    const double dy = pa[1] - center[1];
    const double dz = pa[2] - center[2];
    radius = std::sqrt(dx * dx + dy * dy + dz * dz) / lc;
  }
  else {
    double const p1[2] = {data.Us[tri[0]], data.Vs[tri[0]]};
    double const p2[2] = {data.Us[tri[1]], data.Vs[tri[1]]};
    double const p3[2] = {data.Us[tri[2]], data.Vs[tri[2]]};

    double midpoint[2] = {(p1[0] + p2[0] + p3[0]) * ONE_THIRD,
                          (p1[1] + p2[1] + p3[1]) * ONE_THIRD};

    double quadAngle =
      backgroundMesh::current() ?
        backgroundMesh::current()->getAngle(midpoint[0], midpoint[1], 0) :
        0.0;
    const double ca = std::cos(quadAngle), sa = std::sin(quadAngle);

    double x0 = p1[0] * ca + p1[1] * sa;
    double y0 = -p1[0] * sa + p1[1] * ca;
    double x1 = p2[0] * ca + p2[1] * sa;
    double y1 = -p2[0] * sa + p2[1] * ca;
    double x2 = p3[0] * ca + p3[1] * sa;
    double y2 = -p3[0] * sa + p3[1] * ca;
    double xmax = std::max(std::max(x0, x1), x2);
    double ymax = std::max(std::max(y0, y1), y2);
    double xmin = std::min(std::min(x0, x1), x2);
    double ymin = std::min(std::min(y0, y1), y2);

    double metric[3];
    buildMetric(gf, midpoint, metric);
    double RATIO =
      std::pow(metric[0] * metric[2] - metric[1] * metric[1], -0.25);

    radius = std::max(xmax - xmin, ymax - ymin) / (RATIO * lc);
  }

  if(gf && source) {
    BoundaryLayerColumns *columns = gf->getColumns();
    if(columns && columns->_toFirst.find(source) != columns->_toFirst.end())
      radius = 0;
  }

  return radius;
}

// Closed-form parametric circumcircle {cx, cy, r^2} of triangle tri.
static std::array<double, 3>
computeParamCircumCircle(const IndexedMeshData &data,
                         const std::array<std::size_t, 3> &tri)
{
  const double x1 = data.Us[tri[0]], y1 = data.Vs[tri[0]];
  const double x2 = data.Us[tri[1]], y2 = data.Vs[tri[1]];
  const double x3 = data.Us[tri[2]], y3 = data.Vs[tri[2]];
  const double d = 2. * (y1 * (x2 - x3) + y2 * (x3 - x1) + y3 * (x1 - x2));
  const double a1 = x1 * x1 + y1 * y1;
  const double a2 = x2 * x2 + y2 * y2;
  const double a3 = x3 * x3 + y3 * y3;
  const double cx = (a1 * (y3 - y2) + a2 * (y1 - y3) + a3 * (y2 - y1)) / d;
  const double cy = (a1 * (x2 - x3) + a2 * (x3 - x1) + a3 * (x1 - x2)) / d;
  return {{cx, cy, (cx - x1) * (cx - x1) + (cy - y1) * (cy - y1)}};
}

static std::size_t storeTriangle(IndexedMeshData &data,
                                 const std::array<std::size_t, 3> &tri,
                                 double radius, MTriangle *source,
                                 const std::array<double, 3> *circle = nullptr)
{
  std::array<std::size_t, 3> invalid = {
    {INVALID_TRIANGLE, INVALID_TRIANGLE, INVALID_TRIANGLE}};
  const std::array<double, 3> cc =
    circle ? *circle : computeParamCircumCircle(data, tri);

  std::size_t idx;
  if(!data.freeTriangleSlots.empty()) {
    idx = data.freeTriangleSlots.back();
    data.freeTriangleSlots.pop_back();
    if(data.sourceTriangles[idx]) delete data.sourceTriangles[idx];
    data.triangles[idx] = tri;
    data.neigh[idx] = invalid;
    data.circumRadius[idx] = radius;
    data.circumCircle[idx] = cc;
    data.flags[idx] = TRI_NONE;
    data.sourceTriangles[idx] = source;
  }
  else {
    idx = data.triangles.size();
    data.triangles.push_back(tri);
    data.neigh.push_back(invalid);
    data.circumRadius.push_back(radius);
    data.circumCircle.push_back(cc);
    data.flags.push_back(TRI_NONE);
    data.sourceTriangles.push_back(source);
  }
  return idx;
}

static std::size_t addTriangle(IndexedMeshData &data,
                               const std::array<std::size_t, 3> &tri, double lc,
                               GFace *gf, MTriangle *source = nullptr)
{
  // On a plane the parametric circumradius equals the 3D one, so derive the
  // queue radius from the circumcircle that storeTriangle caches anyway
  // (sqrt(r2)/lc), skipping the separate 3D circumCenterXYZ solve. Rounds
  // differently than the 3D path, so the heap order can flip on near-ties
  // (rounding-class divergence from algo 6).
  if(MTri3::radiusNorm == 2 && data.planar) {
    const std::array<double, 3> cc = computeParamCircumCircle(data, tri);
    double radius = std::sqrt(cc[2]) / lc;
    if(source) {
      BoundaryLayerColumns *columns = gf->getColumns();
      if(columns && columns->_toFirst.find(source) != columns->_toFirst.end())
        radius = 0;
    }
    return storeTriangle(data, tri, radius, source, &cc);
  }
  return storeTriangle(data, tri, computeRadius(data, tri, lc, gf, source),
                       source);
}

IndexedEdgeFace::IndexedEdgeFace(const IndexedMeshData &data, std::size_t t,
                                 int iFac)
  : t1(t), i1(iFac), ori(1)
{
  const std::array<std::size_t, 3> &tri = data.triangles[t1];
  v[0] = tri[iFac == 0 ? 2 : iFac - 1];
  v[1] = tri[iFac];
  if(v[0] > v[1]) {
    ori = -1;
    std::swap(v[0], v[1]);
  }
}

// Per-vertex mesh size of the initial mesh: length of the shortest incident
// mesh edge, skipping edges that connect a vertex to its periodic
// counterpart. Same computation (and same FP operations) as setLcsInit and
// setLcs in meshGFaceOptimize.cpp, which fill the algo-6 structures.
static void setLcsInit(MTriangle *t, std::map<MVertex *, double> &vSizes)
{
  for(int i = 0; i < 3; i++) {
    for(int j = i + 1; j < 3; j++) {
      MVertex *vi = t->getVertex(i);
      MVertex *vj = t->getVertex(j);
      vSizes[vi] = -1;
      vSizes[vj] = -1;
    }
  }
}

static void setLcs(MTriangle *t, std::map<MVertex *, double> &vSizes,
                   std::map<MVertex *, MVertex *> *equivalence)
{
  // a vertex's periodic counterpart, or null (as bidimMeshData::equivalent)
  auto equivalent = [equivalence](MVertex *v) -> MVertex * {
    if(!equivalence) return nullptr;
    auto it = equivalence->find(v);
    return it == equivalence->end() ? nullptr : it->second;
  };
  for(int i = 0; i < 3; i++) {
    for(int j = i + 1; j < 3; j++) {
      MVertex *vi = t->getVertex(i);
      MVertex *vj = t->getVertex(j);
      if(vi != equivalent(vj) && vj != equivalent(vi)) {
        double dx = vi->x() - vj->x();
        double dy = vi->y() - vj->y();
        double dz = vi->z() - vj->z();
        double l = sqrt(dx * dx + dy * dy + dz * dz);
        auto iti = vSizes.find(vi);
        auto itj = vSizes.find(vj);
        if(iti->second < 0 || iti->second > l) iti->second = l;
        if(itj->second < 0 || itj->second > l) itj->second = l;
      }
    }
  }
}

// Pair up the triangle edges to fill neigh[][]: sort all edges (their vertex
// ids are stored sorted), equal consecutive entries are the two sides of one
// interior edge. Same pairing as algo 6's connectTriangles.
static void connectTriangles(IndexedMeshData &data)
{
  std::vector<IndexedEdgeFace> conn;
  conn.reserve(3 * data.triangles.size());
  for(std::size_t t = 0; t < data.triangles.size(); t++)
    for(int j = 0; j < 3; j++) conn.push_back(IndexedEdgeFace(data, t, j));

  std::sort(conn.begin(), conn.end());

  for(std::size_t i = 0; i + 1 < conn.size(); i++) {
    IndexedEdgeFace &f1 = conn[i];
    IndexedEdgeFace &f2 = conn[i + 1];
    if(f1 == f2 && f1.t1 != f2.t1) {
      data.neigh[f1.t1][f1.i1] = f2.t1;
      data.neigh[f2.t1][f2.i1] = f1.t1;
      ++i;
    }
  }
}

// Import the initial mesh into the indexed representation. This performs the
// same computations as the shared buildMeshGenerationDataStructures
// (meshGFaceOptimize.cpp) - per-vertex sizes, embedded vertices and edges,
// per-triangle queue radii - without going through the algo-6 structures
// (bidimMeshData, MTri3), so the optimized algorithm does not depend on
// them. One deliberate difference: the vertices are laid out in
// MVertex::getNum() order (the shared builder iterates a pointer-keyed map,
// so its vertex order is not even deterministic across runs). Interior
// vertices are appended later in creation order with strictly larger nums,
// so "index order == num order" holds for every vertex pair, and the
// active-front tie-break can compare sorted vertex-index triplets - exactly
// algo 6's sorted getNum() triplets (see IndexedMeshData::faceKey).
static bool buildMeshGenerationDataStructures(
  GFace *gf, IndexedMeshData &data, std::map<MVertex *, MVertex *> *equivalence,
  std::map<MVertex *, SPoint2> *parametricCoordinates)
{
  std::map<MVertex *, double> vSizesMap;

  for(std::size_t i = 0; i < gf->triangles.size(); i++)
    setLcsInit(gf->triangles[i], vSizesMap);

  if(vSizesMap.find(nullptr) != vSizesMap.end()) {
    Msg::Error("Some NULL points exist in 2D mesh");
    return false;
  }

  for(std::size_t i = 0; i < gf->triangles.size(); i++)
    setLcs(gf->triangles[i], vSizesMap, equivalence);

  // take care of embedded vertices
  std::set<MVertex *> embeddedVertices;
  for(GVertex *gv : gf->getEmbeddedVertices()) {
    if(gv->mesh_vertices.size()) {
      MVertex *v = *(gv->mesh_vertices.begin());
      vSizesMap[v] = std::min(vSizesMap[v], gv->prescribedMeshSizeAtVertex());
      embeddedVertices.insert(v);
    }
  }

  // take care of small edges in order not to "pollute" the size field
  for(GEdge *ge : gf->edges()) {
    if(ge->isMeshDegenerated()) continue;
    for(std::size_t i = 0; i < ge->lines.size(); i++) {
      double d =
        distance(ge->lines[i]->getVertex(0), ge->lines[i]->getVertex(1));
      double d0 = vSizesMap[ge->lines[i]->getVertex(0)];
      double d1 = vSizesMap[ge->lines[i]->getVertex(1)];
      if(d0 < .5 * d) vSizesMap[ge->lines[i]->getVertex(0)] = .5 * d;
      if(d1 < .5 * d) vSizesMap[ge->lines[i]->getVertex(1)] = .5 * d;
    }
  }

  // Fill the per-vertex arrays, in num order. The id of a face-interior
  // (dim 2) vertex is stored in MVertex::_index; dim < 2 vertices are shared
  // with the other faces meshed in parallel, so their id lives in a local
  // map instead - only the import needs it (the refinement works on ids and
  // only ever creates dim 2 vertices).
  std::vector<std::pair<MVertex *, double>> byNum(vSizesMap.begin(),
                                                  vSizesMap.end());
  std::sort(byNum.begin(), byNum.end(),
            [](const std::pair<MVertex *, double> &a,
               const std::pair<MVertex *, double> &b) {
              return a.first->getNum() < b.first->getNum();
            });
  std::map<MVertex *, std::size_t> boundaryIndex;
  auto vertexId = [&](MVertex *v) -> std::size_t {
    if(v->onWhat()->dim() == 2) return (std::size_t)v->getIndex();
    return boundaryIndex[v];
  };
  for(auto &p : byNum) {
    MVertex *v = p.first;
    SPoint2 param;
    reparamMeshVertexOnFace(v, gf, param);
    // embedded vertices get the background-mesh size; the other vertices use
    // the incident-edge size for both fields
    const double lcBGM =
      (embeddedVertices.count(v) > 0) ?
        BGM_MeshSize(gf, param[0], param[1], v->x(), v->y(), v->z()) :
        p.second;
    // periodic meshing prescribes the parametric coordinates explicitly
    if(parametricCoordinates) {
      auto it = parametricCoordinates->find(v);
      if(it != parametricCoordinates->end()) {
        param[0] = it->second.x();
        param[1] = it->second.y();
      }
    }
    const std::size_t idx = data.Us.size();
    if(v->onWhat()->dim() == 2)
      v->setIndex((long int)idx);
    else
      boundaryIndex[v] = idx;
    data.Us.push_back(param[0]);
    data.Vs.push_back(param[1]);
    data.vSizes.push_back(p.second);
    data.vSizesBGM.push_back(lcBGM);
    data.vertices.push_back(v);
    data.vxyz.push_back({{v->x(), v->y(), v->z()}});
    data.vdim.push_back((char)v->onWhat()->dim());
  }
  data.numBoundary = data.Us.size();

  if(gf->geomType() == GEntity::DiscreteSurface)
    data.discrete = dynamic_cast<discreteFace *>(gf);
  data.planar = gf->geomType() == GEntity::Plane;
  data.extend1d = Extend1dMeshIn2dSurfaces(gf);

  // index the internal (embedded) edges by vertex ids so the cavity walk
  // needs no MEdge/MVertex
  for(GEdge *ge : gf->getEmbeddedEdges()) {
    if(ge->isMeshDegenerated()) continue;
    for(std::size_t i = 0; i < ge->lines.size(); i++) {
      std::size_t a = vertexId(ge->lines[i]->getVertex(0));
      std::size_t b = vertexId(ge->lines[i]->getVertex(1));
      if(a > b) std::swap(a, b);
      data.internalEdgeIds.push_back(std::make_pair(a, b));
    }
  }
  std::sort(data.internalEdgeIds.begin(), data.internalEdgeIds.end());

  for(std::size_t i = 0; i < gf->triangles.size(); i++) {
    MTriangle *t = gf->triangles[i];
    const std::array<std::size_t, 3> tri = {{vertexId(t->getVertex(0)),
                                             vertexId(t->getVertex(1)),
                                             vertexId(t->getVertex(2))}};
    // 0.3333333333 (and not 1./3.) reproduces the shared builder's constant:
    // the sizes feed the queue radii, where the last bit matters for the
    // front ordering
    double lc = 0.3333333333 * (data.vSizes[tri[0]] + data.vSizes[tri[1]] +
                                data.vSizes[tri[2]]);
    double lcBGM =
      0.3333333333 * (data.vSizesBGM[tri[0]] + data.vSizesBGM[tri[1]] +
                      data.vSizesBGM[tri[2]]);
    double LL = data.extend1d ? std::min(lc, lcBGM) : lcBGM;
    // imported triangles keep the 3D circumradius route on every surface
    // (addTriangle's planar shortcut is for the refinement-created
    // triangles): the initial front must order exactly as algo 6's
    storeTriangle(data, tri, computeRadius(data, tri, LL, gf, t), t);
  }
  gf->triangles.clear();
  connectTriangles(data);

  return true;
}

// a triangle is "active" when it has at least one edge on the front, i.e.
// shared with a triangle that is either outside the domain or small enough
static bool isActive(const IndexedMeshData &data, std::size_t t, double limit_,
                     int &active)
{
  if(data.flags[t] & TRI_DELETED) return false;
  for(active = 0; active < 3; active++) {
    std::size_t neigh = data.neigh[t][active];
    if(neigh == INVALID_TRIANGLE ||
       (data.circumRadius[neigh] < limit_ && data.circumRadius[neigh] > 0))
      return true;
  }
  return false;
}

static void circumCenterMetric(std::size_t base, const double *metric,
                               const IndexedMeshData &data, double *x,
                               double &Radius2)
{
  const std::array<std::size_t, 3> &tri = data.triangles[base];
  double pa[2] = {data.Us[tri[0]], data.Vs[tri[0]]};
  double pb[2] = {data.Us[tri[1]], data.Vs[tri[1]]};
  double pc[2] = {data.Us[tri[2]], data.Vs[tri[2]]};
  circumCenterMetric(pa, pb, pc, metric, x, Radius2);
}

// Is uv inside the metric circumcircle of triangle base? Same computation as
// algo 6's inCircumCircleAniso(GFace*, MTriangle*, ...).
static int inCircumCircleAniso(GFace *gf, std::size_t base, const double *uv,
                               const double *metricb,
                               const IndexedMeshData &data)
{
  // For an isotropic metric M = lambda*I the metric circumcircle equals the
  // parametric one and lambda cancels in the comparison, so use the
  // circumcircle cached at triangle creation - a single distance test -
  // instead of rebuilding and solving the 2x2 metric system on every test.
  // Genuine anisotropic metrics keep the exact solve below.
  if(metricb && metricb[1] == 0.0 && metricb[0] == metricb[2]) {
    const std::array<double, 3> &cc = data.circumCircle[base];
    const double d0 = cc[0] - uv[0];
    const double d1 = cc[1] - uv[1];
    return d0 * d0 + d1 * d1 < cc[2];
  }

  double x[2], Radius2;
  double metric[3];
  if(!metricb) {
    const std::array<std::size_t, 3> &tri = data.triangles[base];
    double pa[2] = {
      (data.Us[tri[0]] + data.Us[tri[1]] + data.Us[tri[2]]) * ONE_THIRD,
      (data.Vs[tri[0]] + data.Vs[tri[1]] + data.Vs[tri[2]]) * ONE_THIRD};
    buildMetric(gf, pa, metric);
  }
  else {
    metric[0] = metricb[0];
    metric[1] = metricb[1];
    metric[2] = metricb[2];
  }
  circumCenterMetric(base, metric, data, x, Radius2);

  const double a = metric[0];
  const double b = metric[1];
  const double d = metric[2];

  const double d0 = (x[0] - uv[0]);
  const double d1 = (x[1] - uv[1]);
  // the cross term is exactly 0 for a diagonal metric (common case); skip
  // it then (bit-identical, adding 0.0)
  double d3 = d0 * d0 * a + d1 * d1 * d;
  if(b != 0.0) d3 += 2.0 * d0 * d1 * b;
  return d3 < Radius2;
}

// Grow the cavity of triangles whose metric circumcircle contains the new
// point param, collecting its boundary edges in the shell. Same cavity and
// shell SETS as algo 6's recursive recurFindCavityAniso (the in-circle
// predicate is deterministic and traversal-independent), computed with an
// explicit stack of triangle ids; only the order in which entries are
// collected differs, which permutes triangle slot reuse and therefore the
// element order of the final export.
static void findCavityAniso(GFace *gf, std::vector<IndexedEdgeFace> &shell,
                            std::vector<std::size_t> &cavity, double *metric,
                            double *param, std::size_t t, IndexedMeshData &data)
{
  shell.clear();
  cavity.clear();

  // the isotropic cached-circle in-circle test is hoisted out of the walk
  // and inlined: one branch per cavity instead of one call per edge
  const bool iso = metric && metric[1] == 0.0 && metric[0] == metric[2];
  const bool noInternal = data.internalEdgeIds.empty();
  const double pu = param[0], pv = param[1];

  std::vector<std::size_t> &stack = data.cavityStack;
  stack.clear();
  stack.push_back(t);

  while(!stack.empty()) {
    const std::size_t current = stack.back();
    stack.pop_back();
    if(data.flags[current] & TRI_DELETED) continue;
    data.flags[current] |= TRI_DELETED;
    cavity.push_back(current);

    for(int i = 0; i < 3; i++) {
      const std::size_t neigh = data.neigh[current][i];
      IndexedEdgeFace exf(data, current, i);
      // take care of untouchable internal edges; exf.v is sorted and
      // internalEdgeIds stores sorted id pairs
      const bool internal =
        !noInternal && std::binary_search(data.internalEdgeIds.begin(),
                                          data.internalEdgeIds.end(),
                                          std::make_pair(exf.v[0], exf.v[1]));
      if(neigh == INVALID_TRIANGLE || internal) { shell.push_back(exf); }
      else if(!(data.flags[neigh] & TRI_DELETED)) {
        bool circ;
        if(iso) {
          const std::array<double, 3> &cc = data.circumCircle[neigh];
          const double d0 = cc[0] - pu;
          const double d1 = cc[1] - pv;
          circ = d0 * d0 + d1 * d1 < cc[2];
        }
        else
          circ = inCircumCircleAniso(gf, neigh, param, metric, data);
        if(circ)
          stack.push_back(neigh);
        else
          shell.push_back(exf);
      }
    }
  }
}

static bool invMapUV(std::size_t t, double *p, const IndexedMeshData &data,
                     double *uv, double tol)
{
  double mat[2][2];
  double b[2];

  const std::array<std::size_t, 3> &tri = data.triangles[t];

  double u0 = data.Us[tri[0]];
  double v0 = data.Vs[tri[0]];
  double u1 = data.Us[tri[1]];
  double v1 = data.Vs[tri[1]];
  double u2 = data.Us[tri[2]];
  double v2 = data.Vs[tri[2]];

  mat[0][0] = u1 - u0;
  mat[0][1] = u2 - u0;
  mat[1][0] = v1 - v0;
  mat[1][1] = v2 - v0;

  b[0] = p[0] - u0;
  b[1] = p[1] - v0;
  sys2x2(mat, b, uv);

  return uv[0] >= -tol && uv[1] >= -tol && uv[0] <= 1. + tol &&
         uv[1] <= 1. + tol && 1. - uv[0] - uv[1] > -tol;
}

static inline double getSurfUV(const std::array<std::size_t, 3> &tri,
                               const IndexedMeshData &data)
{
  double u1 = data.Us[tri[0]];
  double v1 = data.Vs[tri[0]];
  double u2 = data.Us[tri[1]];
  double v2 = data.Vs[tri[1]];
  double u3 = data.Us[tri[2]];
  double v3 = data.Vs[tri[2]];

  const double vv1[2] = {u2 - u1, v2 - v1};
  const double vv2[2] = {u3 - u1, v3 - v1};

  return 0.5 * (vv1[0] * vv2[1] - vv1[1] * vv2[0]);
}

static inline double getSurfUV(std::size_t t, const IndexedMeshData &data)
{
  return getSurfUV(data.triangles[t], data);
}

// walk from t towards pt, crossing the edge whose supporting line separates
// the current triangle's barycenter from pt
static std::size_t search4Triangle(std::size_t t, double pt[2],
                                   const IndexedMeshData &data, double uv[2])
{
  if(t == INVALID_TRIANGLE || (data.flags[t] & TRI_DELETED))
    return INVALID_TRIANGLE;

  bool inside = invMapUV(t, pt, data, uv, 1.e-8);

  if(inside) return t;
  SPoint3 q1(pt[0], pt[1], 0);
  std::size_t ITER = 0;
  while(ITER++ <= data.triangles.size()) {
    const std::array<std::size_t, 3> &tri = data.triangles[t];
    SPoint3 q2(
      (data.Us[tri[0]] + data.Us[tri[1]] + data.Us[tri[2]]) * ONE_THIRD,
      (data.Vs[tri[0]] + data.Vs[tri[1]] + data.Vs[tri[2]]) * ONE_THIRD, 0);
    int i;
    for(i = 0; i < 3; i++) {
      std::size_t i1 = tri[i == 0 ? 2 : i - 1];
      std::size_t i2 = tri[i];
      SPoint3 p1(data.Us[i1], data.Vs[i1], 0);
      SPoint3 p2(data.Us[i2], data.Vs[i2], 0);
      if(intersection_segments_2(p1, p2, q1, q2)) break;
    }
    if(i >= 3) {
      Msg::Warning("Impossible case in triangle search");
      break;
    }
    t = data.neigh[t][i];
    if(t == INVALID_TRIANGLE) break;
    if(data.flags[t] & TRI_DELETED) break;
    inside = invMapUV(t, pt, data, uv, 1.e-8);
    if(inside) return t;
  }

  return INVALID_TRIANGLE;
}

static inline std::size_t shellStart(const IndexedEdgeFace &edge)
{
  return edge.ori > 0 ? edge.v[0] : edge.v[1];
}

static inline std::size_t shellEnd(const IndexedEdgeFace &edge)
{
  return edge.ori > 0 ? edge.v[1] : edge.v[0];
}

// Order the shell edges into a closed loop around the cavity (each edge's
// end vertex is the next edge's start vertex), so the new triangles can be
// wired to their ring neighbors by position. Returns false if the shell is
// not a single closed loop, in which case the cavity is invalid.
static bool orderShell(std::vector<IndexedEdgeFace> &shell)
{
  if(shell.empty()) return false;

  auto it = shell.begin();
  while(it != shell.end()) {
    std::size_t next_v = shellEnd(*it);
    auto it2 = std::next(it);
    if(it2 == shell.end()) break;

    auto found =
      std::find_if(it2, shell.end(), [next_v](const IndexedEdgeFace &edge) {
        return shellStart(edge) == next_v;
      });
    if(found == shell.end()) return false;
    if(found != it2) std::iter_swap(it2, found);
    ++it;
  }

  return shellEnd(shell.back()) == shellStart(shell.front());
}

// In which of otherSide's three neighbor slots is deletedTriangle? -1 if
// otherSide is invalid, deleted, or inconsistent.
static int findOtherSideSlot(const IndexedMeshData &data, std::size_t otherSide,
                             std::size_t deletedTriangle)
{
  if(otherSide == INVALID_TRIANGLE || (data.flags[otherSide] & TRI_DELETED))
    return -1;
  for(int f = 0; f < 3; f++) {
    if(data.neigh[otherSide][f] == deletedTriangle) return f;
  }
  return -1;
}

// Retriangulate the cavity by connecting the new vertex iv to the ordered
// shell, in two passes. Pass 1 performs every validation check before the
// mesh is modified in any way - cavity area conservation, proximity/angle
// checks and the adjacency consistency guard - so no staging or rollback
// machinery is needed; pass 2 then creates and wires the new triangles in
// a single sweep over the ordered shell. Negative return values are the
// same rejection codes as algo 6 (-6/-7 are additional consistency guards
// on the shell ring).
//
// The proximity checks are algo 6's tests in squared form (no square
// roots): d < t  <=>  d^2 < t^2, and
// cos < -0.9999  <=>  num < 0 && num^2 > (2*0.9999)^2 d1^2 d2^2 with
// num = d1^2 + d2^2 - d3^2. Decisions can differ from the sqrt forms only
// within a rounding error of the thresholds.
static int insertVertexB(std::vector<IndexedEdgeFace> &shell,
                         std::vector<std::size_t> &cavity, GFace *gf,
                         std::size_t iv, IndexedActiveQueue &activeTets,
                         IndexedMeshData &data)
{
  if(cavity.size() == 1) return -1;

  if(shell.size() != cavity.size() + 2) return -2;

  if(!orderShell(shell)) return -6;

  const double EPS = 1.e-12;

  // check that the cavity area is conserved by the retriangulation (i.e.
  // that the cavity is star-shaped around the new vertex)
  double newArea = 0.0;

  double oldArea =
    std::accumulate(begin(cavity), end(cavity), 0.0,
                    [&](double area, const std::size_t triangle) {
                      return area + std::abs(getSurfUV(triangle, data));
                    });

  bool onePointIsTooClose = false;

  // loop-invariant across shell edges: the inserted vertex's sizes and
  // coordinates
  const double vSizeIv = data.vSizes[iv];
  const double vSizeBGMIv = data.vSizesBGM[iv];
  const std::array<double, 3> &pvv = data.vxyz[iv];
  constexpr double cosThreshSq = (2. * .9999) * (2. * .9999);

  for(auto it = shell.begin(); it != shell.end(); ++it) {
    const std::size_t i0 = shellStart(*it);
    const std::size_t i1 = shellEnd(*it);

    {
      const double lc =
        ONE_THIRD * (data.vSizes[i0] + data.vSizes[i1] + vSizeIv);
      const double lcBGM =
        ONE_THIRD * (data.vSizesBGM[i0] + data.vSizesBGM[i1] + vSizeBGMIv);
      const double LL = std::min(lc, lcBGM);

      const std::array<double, 3> &pv0 = data.vxyz[i0];
      const std::array<double, 3> &pv1 = data.vxyz[i1];
      auto dist3sq = [](const std::array<double, 3> &a,
                        const std::array<double, 3> &b) {
        const double dx = a[0] - b[0];
        const double dy = a[1] - b[1];
        const double dz = a[2] - b[2];
        return dx * dx + dy * dy + dz * dz;
      };
      const double d1sq = dist3sq(pv0, pvv);
      const double d2sq = dist3sq(pv1, pvv);
      const double d3sq = dist3sq(pv0, pv1);
      const double h = LL * .5;
      bool tooClose = d1sq < h * h || d2sq < h * h;

      if(!tooClose && data.vdim[i0] != 2 && data.vdim[i1] != 2) {
        // d4 = |v0v1 x v0v| / d3 < 0.4 LL  <=>  |cross|^2 < (0.4 LL)^2 d3^2
        const double ax = pv1[0] - pv0[0], ay = pv1[1] - pv0[1],
                     az = pv1[2] - pv0[2];
        const double bx = pvv[0] - pv0[0], by = pvv[1] - pv0[1],
                     bz = pvv[2] - pv0[2];
        const double cx = ay * bz - az * by, cy = az * bx - ax * bz,
                     cz = ax * by - ay * bx;
        const double crossSq = cx * cx + cy * cy + cz * cz;
        const double t = LL * .4;
        tooClose = crossSq < t * t * d3sq;
      }
      if(!tooClose) {
        // avoid angles that are too obtuse
        const double num = d1sq + d2sq - d3sq;
        tooClose = num < 0. && num * num > cosThreshSq * d1sq * d2sq;
      }
      if(tooClose) onePointIsTooClose = true;
    }

    const std::array<std::size_t, 3> tri = {{i0, i1, iv}};
    double ss = std::abs(getSurfUV(tri, data));
    if(ss < 1.e-25) ss = 1.e22;
    newArea += ss;

    const std::size_t otherSide = data.neigh[it->t1][it->i1];
    if(otherSide != INVALID_TRIANGLE &&
       findOtherSideSlot(data, otherSide, it->t1) < 0)
      return -7;
  }

  // for adding a point we require that the area remains the same after
  // addition of the point, and that the point is not too close to an edge
  if(std::abs(oldArea - newArea) < EPS * oldArea && !onePointIsTooClose) {
    // Pass 2: all checks passed - create the new triangles and wire them in
    // one sweep over the ordered shell: to the outer neighbor across the
    // shell edge (slot 1) and to the ring neighbors (slots 0 and 2,
    // consecutive shell edges share the new vertex). The cavity slots are
    // released only after the sweep, so the neigh[] rows of the deleted
    // cavity triangles read by the wiring stay valid.
    std::vector<std::size_t> &new_cavity = data.newCavityBuffer;
    new_cavity.clear();
    new_cavity.reserve(shell.size() * 2);

    std::size_t first = INVALID_TRIANGLE;
    std::size_t prev = INVALID_TRIANGLE;
    for(auto it = shell.begin(); it != shell.end(); ++it) {
      const std::size_t i0 = shellStart(*it);
      const std::size_t i1 = shellEnd(*it);

      const double lc =
        ONE_THIRD * (data.vSizes[i0] + data.vSizes[i1] + vSizeIv);
      const double lcBGM =
        ONE_THIRD * (data.vSizesBGM[i0] + data.vSizesBGM[i1] + vSizeBGMIv);
      const double radiusLc = data.extend1d ? std::min(lc, lcBGM) : lcBGM;

      const std::size_t otherSide = data.neigh[it->t1][it->i1];
      const std::size_t nt = addTriangle(data, {{i0, i1, iv}}, radiusLc, gf);
      new_cavity.push_back(nt);

      data.neigh[nt][1] = otherSide;
      if(otherSide != INVALID_TRIANGLE) {
        new_cavity.push_back(otherSide);
        for(int f = 0; f < 3; f++) {
          if(data.neigh[otherSide][f] == it->t1) {
            data.neigh[otherSide][f] = nt;
            break;
          }
        }
      }
      if(prev != INVALID_TRIANGLE) {
        data.neigh[nt][0] = prev;
        data.neigh[prev][2] = nt;
      }
      else {
        first = nt;
      }
      prev = nt;
    }
    data.neigh[first][0] = prev;
    data.neigh[prev][2] = first;

    for(std::size_t triangle : cavity) {
      if(!(data.flags[triangle] & TRI_IN_QUEUE))
        data.releaseTriangleSlot(triangle);
    }

    for(auto i = new_cavity.begin(); i != new_cavity.end(); ++i) {
      int active_edge;
      if(isActive(data, *i, LIMIT_, active_edge) &&
         data.circumRadius[*i] > LIMIT_) {
        activeTets.push(*i);
      }
    }
    return 1;
  }
  else {
    // the cavity is NOT star shaped: undelete it (nothing was created)
    std::for_each(begin(cavity), end(cavity), [&](std::size_t triangle) {
      data.flags[triangle] &= ~TRI_DELETED;
    });
    if(std::abs(oldArea - newArea) > EPS * oldArea) return -3;
    if(onePointIsTooClose) return -4;
    return -5;
  }
}

static bool insertAPoint(GFace *gf, double center[2], double metric[3],
                         IndexedMeshData &data, IndexedActiveQueue &activeTris,
                         std::size_t worst)
{
  if(worst == INVALID_TRIANGLE || (data.flags[worst] & TRI_DELETED)) {
    Msg::Error("Could not insert point");
    return false;
  }

  std::size_t ptin = INVALID_TRIANGLE;
  std::vector<IndexedEdgeFace> &shell = data.shellBuffer;
  std::vector<std::size_t> &cavity = data.cavityBuffer;
  shell.clear();
  cavity.clear();
  double uv[2];

  // if the point is able to break the bad triangle "worst"
  if(inCircumCircleAniso(gf, worst, center, metric, data)) {
    findCavityAniso(gf, shell, cavity, metric, center, worst, data);
    for(auto itc = cavity.begin(); itc != cavity.end(); ++itc) {
      if(invMapUV(*itc, center, data, uv, 1.e-8)) {
        ptin = *itc;
        break;
      }
    }
  }
  else {
    ptin = search4Triangle(worst, center, data, uv);
    if(ptin != INVALID_TRIANGLE) {
      findCavityAniso(gf, shell, cavity, metric, center, ptin, data);
    }
  }

  if(ptin != INVALID_TRIANGLE) {
    // we use here local coordinates as real coordinates x,y and z will be
    // computed hereafter
    GPoint p = gf->point(center[0], center[1]);
    if(!p.succeeded()) {
      Msg::Debug("Point %g %g cannot be inserted because the surface "
                 "projection failed",
                 center[0], center[1]);
      data.circumRadius[worst] = -1;
      for(auto itc = cavity.begin(); itc != cavity.end(); ++itc)
        data.flags[*itc] &= ~TRI_DELETED;
      return false;
    }

    const std::array<std::size_t, 3> &tri = data.triangles[ptin];
    double lc1 = (1. - uv[0] - uv[1]) * data.vSizes[tri[0]] +
                 uv[0] * data.vSizes[tri[1]] + uv[1] * data.vSizes[tri[2]];
    double lc;
    if(CTX::instance()->mesh.algo2d == ALGO_2D_BAMG)
      lc = 1.;
    else
      lc = BGM_MeshSize(gf, center[0], center[1], p.x(), p.y(), p.z());

    // SoA only: the MFaceVertex is materialized at transfer
    std::size_t iv = data.addInteriorVertex(center[0], center[1], p.x(), p.y(),
                                            p.z(), lc1, lc);

    int result = insertVertexB(shell, cavity, gf, iv, activeTris, data);
    if(result != 1) {
      if(result == -1)
        Msg::Debug("Point %g %g cannot be inserted because cavity is of size 1",
                   center[0], center[1]);
      if(result == -2)
        Msg::Debug("Point %g %g cannot be inserted because euler formula is "
                   "not fulfilled",
                   center[0], center[1]);
      if(result == -3)
        Msg::Debug(
          "Point %g %g cannot be inserted because cavity is not star shaped",
          center[0], center[1]);
      if(result == -4)
        Msg::Debug("Point %g %g cannot be inserted because it is too close to "
                   "another point)",
                   center[0], center[1]);
      if(result == -5)
        Msg::Debug("Point %g %g cannot be inserted because it is out of the "
                   "parametric domain)",
                   center[0], center[1]);
      if(result == -6)
        Msg::Debug("Point %g %g cannot be inserted because the cavity shell "
                   "cannot be ordered",
                   center[0], center[1]);
      if(result == -7)
        Msg::Debug("Point %g %g cannot be inserted because the cavity "
                   "neighborhood is inconsistent",
                   center[0], center[1]);

      data.circumRadius[worst] = -1;
      data.removeLastInteriorVertex();
      for(auto itc = cavity.begin(); itc != cavity.end(); ++itc)
        data.flags[*itc] &= ~TRI_DELETED;
      return false;
    }
    else {
      // gf->mesh_vertices is filled at transfer, in acceptance order
      return true;
    }
  }
  else {
    for(auto itc = cavity.begin(); itc != cavity.end(); ++itc)
      data.flags[*itc] &= ~TRI_DELETED;
    data.circumRadius[worst] = 0;
    return false;
  }
}

static double optimalPointFrontal(GFace *gf, std::size_t worst, int active_edge,
                                  const IndexedMeshData &data,
                                  double newPoint[2], double metric[3])
{
  double center[2], r2;
  const std::array<std::size_t, 3> &base = data.triangles[worst];
  if(data.planar) {
    // A plane's parametrization is isometric: the metric is the identity
    // and the circumcenter is the one cached at triangle creation - no
    // buildMetric (virtual firstDer) and no per-insertion metric solve.
    metric[0] = 1.;
    metric[1] = 0.;
    metric[2] = 1.;
    center[0] = data.circumCircle[worst][0];
    center[1] = data.circumCircle[worst][1];
  }
  else {
    double pa[2] = {
      (data.Us[base[0]] + data.Us[base[1]] + data.Us[base[2]]) * ONE_THIRD,
      (data.Vs[base[0]] + data.Vs[base[1]] + data.Vs[base[2]]) * ONE_THIRD};
    buildMetric(gf, pa, metric);
    circumCenterMetric(worst, metric, data, center, r2);
  }
  // compute the middle point of the edge
  int ip1 = active_edge - 1 < 0 ? 2 : active_edge - 1;
  int ip2 = active_edge;

  double P[2] = {data.Us[base[ip1]], data.Vs[base[ip1]]};
  double Q[2] = {data.Us[base[ip2]], data.Vs[base[ip2]]};
  double midpoint[2] = {0.5 * (P[0] + Q[0]), 0.5 * (P[1] + Q[1])};

  // now we have the edge center and the center of the circumcircle, we try to
  // find a point that would produce a perfect triangle while connecting the 2
  // points of the active edge
  double dir[2] = {center[0] - midpoint[0], center[1] - midpoint[1]};
  double norm = std::sqrt(dir[0] * dir[0] + dir[1] * dir[1]);
  dir[0] /= norm;
  dir[1] /= norm;
  const double RATIO =
    std::sqrt(dir[0] * dir[0] * metric[0] + 2 * dir[1] * dir[0] * metric[1] +
              dir[1] * dir[1] * metric[2]);

  const double rhoM1 = 0.5 * (data.vSizes[base[ip1]] + data.vSizes[base[ip2]]);
  const double rhoM2 =
    0.5 * (data.vSizesBGM[base[ip1]] + data.vSizesBGM[base[ip2]]);
  const double rhoM = data.extend1d ? std::min(rhoM1, rhoM2) : rhoM2;
  const double rhoM_hat = rhoM;

  const double q = lengthMetric(center, midpoint, metric);
  const double d = rhoM_hat * std::sqrt(3.0) * 0.5;

  const double L = std::min(d, q);

  newPoint[0] = midpoint[0] + L * dir[0] / RATIO;
  newPoint[1] = midpoint[1] + L * dir[1] / RATIO;

  return L;
}

/*
            x
            |
            |
            | d =  3^{1/2}/2 h
            |
            |
      ------p------->   n
            h

   x point of the plane

   h being some kind of average between the size field
   and the edge length
*/

static bool optimalPointFrontalB(GFace *gf, std::size_t worst, int active_edge,
                                 const IndexedMeshData &data,
                                 double newPoint[2], double metric[3])
{
  // as a starting point, let us use the "fast algo"
  double d =
    optimalPointFrontal(gf, worst, active_edge, data, newPoint, metric);

  // On a plane the parametric optimal point IS the surface point: skip the
  // 3D frame construction and the circle/surface Newton projection (which
  // converges immediately on a plane).
  if(data.planar) return true;

  const std::array<std::size_t, 3> &base = data.triangles[worst];
  int ip1 = (active_edge + 2) % 3;
  int ip2 = active_edge;
  int ip3 = (active_edge + 1) % 3;
  const std::array<double, 3> &a1 = data.vxyz[base[ip1]];
  const std::array<double, 3> &a2 = data.vxyz[base[ip2]];
  const std::array<double, 3> &a3 = data.vxyz[base[ip3]];
  SVector3 middle((a1[0] + a2[0]) * .5, (a1[1] + a2[1]) * .5,
                  (a1[2] + a2[2]) * .5);
  SVector3 v1v2(a2[0] - a1[0], a2[1] - a1[1], a2[2] - a1[2]);
  SVector3 tmp(a3[0] - middle.x(), a3[1] - middle.y(), a3[2] - middle.z());
  SVector3 n1 = crossprod(v1v2, tmp);
  if(n1.norm() < 1.e-12) return true;

  SVector3 n2 = crossprod(n1, v1v2);
  n1.normalize();
  n2.normalize();
  // we look for a point that is
  // P = d * (n1 std::cos(t) + n2 std::sin(t)) that is on the surface
  // so we have to find t, starting with t = 0

#if defined(HAVE_HXT)
  if(data.discrete) {
    GPoint gp =
      data.discrete->intersectionWithCircleSpatial(n1, n2, middle, d,
                                                   newPoint);
    if(gp.succeeded()) return true;
    return false;
  }
#endif

  double uvt[3] = {newPoint[0], newPoint[1], 0.0};
  curveFunctorCircle cc(n2, n1, middle, d);
  surfaceFunctorGFace ss(gf);

  if(intersectCurveSurface(cc, ss, uvt, d * 1.e-8)) {
    newPoint[0] = uvt[0];
    newPoint[1] = uvt[1];
    return true;
  }

  return true;
}

// Same as computeEquivalences (meshGFaceOptimize.cpp), which takes the shared
// bidimMeshData; only the equivalence map is actually used.
static void computeEquivalences(GFace *gf,
                                std::map<MVertex *, MVertex *> *equivalence)
{
  if(equivalence) {
    std::vector<MTriangle *> newT;
    for(std::size_t i = 0; i < gf->triangles.size(); i++) {
      MTriangle *t = gf->triangles[i];
      MVertex *v[3];
      for(int j = 0; j < 3; j++) {
        v[j] = t->getVertex(j);
        auto it = equivalence->find(v[j]);
        if(it != equivalence->end()) { v[j] = it->second; }
      }
      if(v[0] != v[1] && v[0] != v[2] && v[2] != v[1])
        newT.push_back(new MTriangle(v[0], v[1], v[2]));
      delete t;
    }
    gf->triangles = newT;
  }
}

template <class V> static void releaseVector(V &v) { V().swap(v); }

static void transferDataStructure(GFace *gf, IndexedMeshData &data,
                                  std::map<MVertex *, MVertex *> *equivalence)
{
  // Refinement is over: release everything the transfer does not need
  // before materializing the final mesh (MVertex + MTriangle), so the dead
  // refinement structures do not coexist with it at the memory peak. The
  // transfer still needs Us/Vs (orientation), vertices, triangles,
  // sourceTriangles and the TRI_DELETED bit of flags.
  releaseVector(data.neigh);
  releaseVector(data.circumRadius);
  releaseVector(data.circumCircle);
  releaseVector(data.freeTriangleSlots);
  releaseVector(data.shellBuffer);
  releaseVector(data.cavityBuffer);
  releaseVector(data.cavityStack);
  releaseVector(data.newCavityBuffer);
  releaseVector(data.vdim);
  releaseVector(data.vSizes);
  releaseVector(data.vSizesBGM);

  // Materialize the interior vertices (deferred during meshing) in index
  // order, which is their acceptance order; mesh_vertices is filled in the
  // same order. The MVertex constructor assigns the node numbers through an
  // atomic counter increment: consecutive in serial, interleaved across
  // faces meshed in parallel - unique either way.
  for(std::size_t i = data.numBoundary; i < data.vertices.size(); i++) {
    MVertex *v = new MFaceVertex(data.vxyz[i][0], data.vxyz[i][1],
                                 data.vxyz[i][2], gf, data.Us[i], data.Vs[i]);
    v->setIndex(
      (long int)i); // face-owned vertices carry their id, as at import
    data.vertices[i] = v;
    gf->mesh_vertices.push_back(v);
  }
  releaseVector(data.vxyz);

  // Create the MTriangles and orient them consistently with the reference
  // (first) triangle in a single pass. The parametric coordinates that the
  // normals need are read directly through the vertex ids in
  // data.triangles[t] - the same values the shared transferDataStructure
  // (meshGFaceOptimize.cpp) obtains per vertex through
  // bidimMeshData::getIndex - so the orientation decisions are identical.
  // gf->triangles is empty here (the import consumed and cleared it, and the
  // boundary-layer elements are only re-inserted by the caller after the
  // algorithm returns), so the reference is the first live triangle.
  const bool BL = !gf->getColumns()->_toFirst.empty();
  double n1[3];
  bool haveRef = false;

  for(std::size_t t = 0; t < data.triangles.size(); t++) {
    if(data.flags[t] & TRI_DELETED) {
      if(data.sourceTriangles[t]) delete data.sourceTriangles[t];
      continue;
    }
    const std::array<std::size_t, 3> &tri = data.triangles[t];
    MTriangle *mt = data.sourceTriangles[t] ?
                      data.sourceTriangles[t] :
                      new MTriangle(data.vertex(tri[0]), data.vertex(tri[1]),
                                    data.vertex(tri[2]));
    gf->triangles.push_back(mt);

    double n2[3];
    if(!BL)
      normal3points(data.Us[tri[0]], data.Vs[tri[0]], 0., data.Us[tri[1]],
                    data.Vs[tri[1]], 0., data.Us[tri[2]], data.Vs[tri[2]], 0.,
                    n2);
    else {
      MVertex *v0 = data.vertex(tri[0]), *v1 = data.vertex(tri[1]),
              *v2 = data.vertex(tri[2]);
      normal3points(v0->x(), v0->y(), v0->z(), v1->x(), v1->y(), v1->z(),
                    v2->x(), v2->y(), v2->z(), n2);
    }

    if(!haveRef) {
      n1[0] = n2[0];
      n1[1] = n2[1];
      n1[2] = n2[2];
      haveRef = true;
    }
    else if(prosca(n1, n2) < 0.0)
      mt->reverse();
  }
  computeEquivalences(gf, equivalence);
}

void bowyerWatsonFrontalOptimized(
  GFace *gf, std::map<MVertex *, MVertex *> *equivalence,
  std::map<MVertex *, SPoint2> *parametricCoordinates,
  std::vector<SPoint2> *true_boundary)
{
  IndexedMeshData DATA;
  IndexedActiveQueue ActiveTris(&DATA);
  if(!buildMeshGenerationDataStructures(gf, DATA, equivalence,
                                        parametricCoordinates)) {
    Msg::Error("Invalid meshing data structure");
    return;
  }

  int ITER = 0, active_edge;
  // seed the front: collect every active triangle, then heapify once (linear
  // instead of algo 6's scan of the radius-ordered set)
  for(std::size_t t = 0; t < DATA.triangles.size(); t++) {
    if(DATA.circumRadius[t] > LIMIT_ && isActive(DATA, t, LIMIT_, active_edge))
      ActiveTris.pushUnordered(t);
  }
  ActiveTris.makeHeap();

  Range<double> RU = gf->parBounds(0);
  Range<double> RV = gf->parBounds(1);
  SPoint2 FAR(RU.high() + (RU.high() - RU.low()),
              RV.high() + (RV.high() - RV.low()));

  // insert points
  while(!ActiveTris.empty()) {
    std::size_t worst = ActiveTris.pop();

    if(!(DATA.flags[worst] & TRI_DELETED) &&
       isActive(DATA, worst, LIMIT_, active_edge) &&
       DATA.circumRadius[worst] > LIMIT_) {
      if(ITER++ % 5000 == 0)
        Msg::Debug("%7zu points created -- Worst tri radius is %8.3f",
                   DATA.vertices.size() - DATA.numBoundary,
                   DATA.circumRadius[worst]);
      double newPoint[2], metric[3];
      if(optimalPointFrontalB(gf, worst, active_edge, DATA, newPoint, metric)) {
        SPoint2 NP(newPoint[0], newPoint[1]);
        int nIntersections;
        if(!true_boundary ||
           pointInsideParametricDomain(*true_boundary, NP, FAR, nIntersections))
          insertAPoint(gf, newPoint, metric, DATA, ActiveTris, worst);
      }
      else {
        Msg::Debug("no point found");
      }
    }
  }

  // the queue is empty but its heap vector kept its capacity
  releaseVector(ActiveTris.heap);

  transferDataStructure(gf, DATA, equivalence);

  splitElementsInBoundaryLayerIfNeeded(gf);
}
