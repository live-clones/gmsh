// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s):
//   Koen Hillewaert
//

#include <algorithm>
#include <sstream>
#include <cstdint>
#include <mutex>
#include <unordered_map>
#include "Hash.h"
#include "MFaceHash.h"
#include <vector>
#include "GmshConfig.h"
#include "GModel.h"
#include "HighOrder.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "MPyramid.h"
#include "GmshMessage.h"
#include "OS.h"
#include "fullMatrix.h"
#include "BasisFactory.h"
#include "nodalBasis.h"
#include "InnerVertexPlacement.h"
#include "Context.h"
#include "MFace.h"
#include "ExtrudeParams.h"
#include "Field.h"

// For each edge (a pair of nodes, the one of smaller number first) and for each
// face, the high-order nodes created on it, in the orientation of its key. The
// nodes are stored in a single array, and the keys in an open addressing hash
// table with linear probing: millions of edges are looked up, and a
// std::unordered_map with a std::vector per entry spends its time in cache
// misses and allocations
template <class KEY, class HASH, class EQUAL> class nodeMap {
public:
  struct entry {
    KEY key;
    std::size_t first; // index of the first node in the array
    int num; // number of nodes, -1 for an empty slot
  };

private:
  std::vector<entry> _table; // size 0 or a power of 2
  int _bits;
  std::size_t _size;
  std::vector<MVertex *> _nodes;
  HASH _hash;
  EQUAL _equal;
  // (the low bits of the hash; the shard is chosen from the high ones, see
  // shardedContainer)
  std::size_t _slot(const KEY &k) const
  { return _hash(k) & (_table.size() - 1); }
  void _grow()
  {
    std::vector<entry> old;
    old.swap(_table);
    _bits = std::max(10, _bits + 1);
    _table.resize(std::size_t(1) << _bits);
    for(entry &e : _table) e.num = -1;
    for(entry &e : old) {
      if(e.num < 0) continue;
      std::size_t i = _slot(e.key);
      while(_table[i].num >= 0) i = (i + 1) & (_table.size() - 1);
      _table[i] = std::move(e);
    }
  }

public:
  nodeMap() : _bits(0), _size(0) {}
  const entry *find(const KEY &k) const
  {
    if(_table.empty()) return nullptr;
    for(std::size_t i = _slot(k);; i = (i + 1) & (_table.size() - 1)) {
      const entry &e = _table[i];
      if(e.num < 0) return nullptr;
      if(_equal(e.key, k)) return &e;
    }
  }
  MVertex *const *nodes(const entry *e) const { return &_nodes[e->first]; }
  // k must not be in the map yet; the entry is valid until the next insertion
  template <class IT> const entry *insert(const KEY &k, IT begin, IT end)
  {
    if(4 * (_size + 1) > 3 * _table.size()) _grow();
    std::size_t i = _slot(k);
    while(_table[i].num >= 0) i = (i + 1) & (_table.size() - 1);
    entry &e = _table[i];
    e.key = k;
    e.first = _nodes.size();
    _nodes.insert(_nodes.end(), begin, end);
    e.num = (int)(_nodes.size() - e.first);
    _size++;
    return &e;
  }
};

struct MVertexPairHash {
  std::size_t operator()(const std::pair<MVertex *, MVertex *> &p) const
  {
    // (the pair is ordered: not an MEdge)
    return HashMix(HashCombine(p.first->getNum(), p.second->getNum()));
  }
};
typedef nodeMap<std::pair<MVertex *, MVertex *>, MVertexPairHash,
                std::equal_to<std::pair<MVertex *, MVertex *> > >
  edgeMap;
typedef nodeMap<MFace, MFaceHash, MFaceEqual> faceMap;

// The two containers above are shared by all the entities being curved, and are
// written to while the elements of an entity are treated in parallel. They are
// thus split in shards: a given edge (resp. face) always lands in the same
// shard, and a thread only ever locks the shard it is about to touch. With a
// single shard no lock is taken at all, i.e. the behaviour - and in particular
// the order in which the nodes are created, hence their numbering - is exactly
// the serial one.
template <class MAP, class KEY, class HASH> class shardedContainer {
private:
  std::vector<MAP> _shards;
  std::vector<std::mutex> _locks;
  HASH _hash;

public:
  shardedContainer(std::size_t nShards)
    : _shards(nShards < 1 ? 1 : nShards), _locks(nShards < 1 ? 1 : nShards)
  {
  }
  bool isParallel() const { return _shards.size() > 1; }
  std::size_t shardOf(const KEY &k) const
  { return HashShard(_hash(k), (int)_shards.size()); }
  MAP &shard(std::size_t i) { return _shards[i]; }
  void lock(std::size_t i)
  {
    if(_shards.size() > 1) _locks[i].lock();
  }
  void unlock(std::size_t i)
  {
    if(_shards.size() > 1) _locks[i].unlock();
  }
};

typedef shardedContainer<edgeMap, std::pair<MVertex *, MVertex *>,
                         MVertexPairHash>
  edgeContainer;
typedef shardedContainer<faceMap, MFace, MFaceHash> faceContainer;

template <class C> class shardLock {
private:
  C &_container;
  std::size_t _shard;

public:
  shardLock(C &c, std::size_t shard) : _container(c), _shard(shard)
  {
    _container.lock(_shard);
  }
  ~shardLock() { _container.unlock(_shard); }
};

// Reparametrizing a node classified on a curve or on a point goes through the
// (stateful) OCCEdge/OCCVertex caches, which are not thread-safe. Those nodes
// are only the ones on the boundary of the surface being curved, i.e. a small
// fraction of them, so simply serializing those reparametrizations costs
// nothing measurable.
static std::mutex boundaryReparamMutex;

static inline bool onBoundaryOfFace(const MVertex *v)
{
  return v->onWhat() && v->onWhat()->dim() < 2;
}

// Functions that help optimizing placement of points on geometry

// The aim here is to build a polynomial representation that consist
// in polynomial segments of equal length

static double mylength(GEdge *ge, int i, double *u)
{
  return ge->length(u[i], u[i + 1], 10);
}

static void myresid(int N, GEdge *ge, double *u, fullVector<double> &r,
                    double *weight = nullptr)
{
  double L[100];
  for(int i = 0; i < N - 1; i++) L[i] = mylength(ge, i, u);
  if(weight)
    for(int i = 0; i < N - 2; i++)
      r(i) = L[i + 1] / weight[i + 1] - L[i] / weight[i];
  else
    for(int i = 0; i < N - 2; i++) r(i) = L[i + 1] - L[i];
}

static bool computeEquidistantParameters(GEdge *ge, double u0, double uN, int N,
                                         double *u, double underRelax)
{
  const double PRECISION = 1.e-6;
  const int MAX_ITER = 50;
  const double eps = (uN - u0) * 1.e-5;

  // newton algorithm
  // N is the total number of points (3 for quadratic, 4 for cubic ...)
  // u[0] = u0;
  // u[N-1] = uN;
  // initialize as equidistant in parameter space
  u[0] = u0;
  double du = (uN - u0) / (N - 1);
  for(int i = 1; i < N; i++) { u[i] = u[i - 1] + du; }

  // return true;

  // create the tangent matrix
  const int M = N - 2;
  fullMatrix<double> J(M, M);
  fullVector<double> DU(M);
  fullVector<double> R(M);
  fullVector<double> Rp(M);

  int iter = 1;

  while(iter < MAX_ITER) {
    iter++;
    myresid(N, ge, u, R);

    for(int i = 0; i < M; i++) {
      u[i + 1] += eps;
      myresid(N, ge, u, Rp);
      for(int j = 0; j < M; j++) { J(i, j) = (Rp(j) - R(j)) / eps; }
      u[i + 1] -= eps;
    }

    if(M == 1)
      DU(0) = R(0) / J(0, 0);
    else
      J.luSolve(R, DU);

    for(int i = 0; i < M; i++) { u[i + 1] -= underRelax * DU(i); }

    if(u[1] < u0) break;
    if(u[N - 2] > uN) break;

    double newt_norm = DU.norm();
    if(newt_norm < PRECISION) { return true; }
  }
  return false;
}

static bool computeGLLParametersP6(GEdge *ge, double u0, double uN, int N,
                                   double *u, double underRelax)
{
  static const double GLLQL[7] = {
    -1.000000000000000, -0.830223896278567, -0.468848793470714, 0,
    0.468848793470714,  0.830223896278567,  1.000000000000000};
  double weight[6];
  for(int i = 0; i < 6; ++i) { weight[i] = GLLQL[i + 1] - GLLQL[i]; }

  const double PRECISION = 1.e-6;
  const int MAX_ITER = 50;
  const double eps = (uN - u0) * 1.e-5;

  // newton algorithm
  // N is the total number of points (3 for quadratic, 4 for cubic ...)
  // u[0] = u0;
  // u[N-1] = uN;
  // initialize as equidistant in parameter space
  u[0] = u0;
  u[N - 1] = uN;
  double uMiddle = .5 * (u0 + uN);
  double du = .5 * (uN - u0);
  for(int i = 1; i < N - 1; i++) { u[i] = uMiddle + GLLQL[i] * du; }

  // create the tangent matrix
  const int M = N - 2;
  fullMatrix<double> J(M, M);
  fullVector<double> DU(M);
  fullVector<double> R(M);
  fullVector<double> Rp(M);

  int iter = 1;

  while(iter < MAX_ITER) {
    iter++;
    myresid(N, ge, u, R, weight);

    for(int i = 0; i < M; i++) {
      u[i + 1] += eps;
      myresid(N, ge, u, Rp, weight);
      for(int j = 0; j < M; j++) { J(i, j) = (Rp(j) - R(j)) / eps; }
      u[i + 1] -= eps;
    }

    if(M == 1)
      DU(0) = R(0) / J(0, 0);
    else
      J.luSolve(R, DU);

    for(int i = 0; i < M; i++) { u[i + 1] -= underRelax * DU(i); }

    if(u[1] < u0) break;
    if(u[N - 2] > uN) break;

    double newt_norm = DU.norm();
    if(newt_norm < PRECISION) { return true; }
  }
  return false;
}

static bool computeEquidistantParameters(GFace *gf, double u0, double uN,
                                         double v0, double vN, SPoint3 &p0,
                                         SPoint3 &pN, int N, bool geodesic,
                                         double *u, double *v)
{
  const int NI = N - 1;
  u[0] = u0;
  v[0] = v0;
  u[NI] = uN;
  v[NI] = vN;
  const double fact = 1. / (double)NI;
  for(int i = 1; i < NI; i++) {
    const double t = i * fact;
    u[i] = u0 + (uN - u0) * t;
    v[i] = v0 + (vN - v0) * t;
    // only use closestPoint for non-plane surfaces (for performance reasons -
    // it's very slow in OpenCASCADE)
    if(geodesic && gf->geomType() != GEntity::Plane) {
      SPoint3 pc(t * pN + (1. - t) * p0);
      double guess[2] = {u[i], v[i]};
      GPoint gp = gf->closestPoint(pc, guess);
      // the guess is a linear interpolation of the parameters of the two
      // endpoints, which is meaningless if the edge crosses a seam: if the
      // projection lands further away than the edge is long, it converged to
      // some other part of the surface - redo it without the guess
      if(gp.succeeded() &&
         pc.distance(SPoint3(gp.x(), gp.y(), gp.z())) > p0.distance(pN))
        gp = gf->closestPoint(pc, nullptr);
      if(gp.succeeded()) {
        u[i] = gp.u();
        v[i] = gp.v();
      }
    }
  }
  return true;
}

static fullMatrix<double> *lob2lagP6 = nullptr;

void createMatLob2LagP6()
{
  const double lobPt[7] = {
    -1.000000000000000, -0.830223896278567, -0.468848793470714, 0,
    0.468848793470714,  0.830223896278567,  1.000000000000000};
  const double lagPt[7] = {
    -1.000000000000000, -0.666666666666666, -0.333333333333333, 0,
    0.333333333333333,  0.666666666666666,  1.000000000000000};
  const int ndofs = 7;

  const double monomial[7] = {0, 1, 2, 3, 4, 5, 6};

  fullMatrix<double> Vandermonde(ndofs, ndofs);
  for(int i = 0; i < ndofs; i++) {
    for(int j = 0; j < ndofs; j++) {
      Vandermonde(i, j) = pow_int(lobPt[i], monomial[j]);
    }
  }

  fullMatrix<double> coefficient(ndofs, ndofs);
  Vandermonde.invert(coefficient);

  lob2lagP6 = new fullMatrix<double>(ndofs, ndofs);

  for(int i = 0; i < ndofs; i++) {
    for(int j = 0; j < ndofs; j++) {
      Vandermonde(i, j) = pow_int(lagPt[i], monomial[j]);
    }
  }

  Vandermonde.mult(coefficient, (*lob2lagP6));
}

// Creation of high-order edge vertices

static bool getEdgeVerticesOnGeo(GEdge *ge, MVertex *v0, MVertex *v1,
                                 std::vector<MVertex *> &ve, int nPts = 1)
{
  static bool GLLquad = false;
  static const double relaxFail = 1e-2;
  double u0 = 0., u1 = 0., US[100];
  bool reparamOK = reparamMeshVertexOnEdge(v0, ge, u0) &&
                   reparamMeshVertexOnEdge(v1, ge, u1);
  // the seam node of a periodic curve has both parameter bounds: take the
  // one on the side of the other node (the edge may come in either
  // orientation)
  if(reparamOK && ge->periodic(0) && ge->getEndVertex() &&
     ge->getEndVertex()->getNumMeshVertices() > 0) {
    MVertex *seam = ge->getEndVertex()->mesh_vertices[0];
    const Range<double> b = ge->parBounds(0);
    auto nearest = [&](double u) {
      return std::fabs(u - b.low()) < std::fabs(u - b.high()) ? b.low() :
                                                                 b.high();
    };
    if(v1 == seam && v0 != seam) u1 = nearest(u0);
    else if(v0 == seam && v1 != seam) u0 = nearest(u1);
  }

  if(reparamOK) {
    double uMin = std::min(u0, u1), uMax = std::max(u0, u1);
    bool failed = true;
    double relax = 1.;
    while(failed && (relax > relaxFail)) {
      if(GLLquad)
        failed = !computeGLLParametersP6(ge, uMin, uMax, nPts + 2, US, relax);
      else
        failed =
          !computeEquidistantParameters(ge, uMin, uMax, nPts + 2, US, relax);
      relax *= 0.5;
    }
    if(failed) {
      Msg::Warning(
        "Failed to compute equidistant parameters (relax = %g, value = %g) "
        "for edge %d-%d parametrized with %g %g on curve %d",
        relax, US[1], v0->getNum(), v1->getNum(), u0, u1, ge->tag());
      US[0] = uMin;
      const double du = (uMax - uMin) / (nPts + 1);
      for(int i = 1; i <= nPts; i++) US[i] = US[i - 1] + du;
    }
  }
  else
    Msg::Error("Cannot reparametrize a mesh node in high order meshing");

  if(!reparamOK) return false;

  if(GLLquad) {
    fullMatrix<double> M(7, 3);
    M(0, 0) = u0 < u1 ? v0->x() : v1->x();
    M(0, 1) = u0 < u1 ? v0->y() : v1->y();
    M(0, 2) = u0 < u1 ? v0->z() : v1->z();
    M(6, 0) = u0 < u1 ? v1->x() : v0->x();
    M(6, 1) = u0 < u1 ? v1->y() : v0->y();
    M(6, 2) = u0 < u1 ? v1->z() : v0->z();
    for(int j = 0; j < nPts; j++) {
      int count = u0 < u1 ? j + 1 : nPts + 1 - (j + 1);
      GPoint pc = ge->point(US[count]);
      M(j + 1, 0) = pc.x();
      M(j + 1, 1) = pc.y();
      M(j + 1, 2) = pc.z();
    }
    fullMatrix<double> Mlag(7, 3);
    if(!lob2lagP6) createMatLob2LagP6();
    lob2lagP6->mult(M, Mlag);

    for(int j = 0; j < nPts; j++) {
      MVertex *v;
      int count = u0 < u1 ? j + 1 : nPts + 1 - (j + 1);
      // FIXME US[count] false!!!
      v = new MEdgeVertex(Mlag(count, 0), Mlag(count, 1), Mlag(count, 2), ge,
                          US[count]);
      // this destroys the ordering of the mesh vertices on the edge
      ve.push_back(v);
    }
  }
  else {
    for(int j = 0; j < nPts; j++) {
      MVertex *v;
      int count = u0 < u1 ? j + 1 : nPts + 1 - (j + 1);
      GPoint pc = ge->point(US[count]);
      v = new MEdgeVertex(pc.x(), pc.y(), pc.z(), ge, US[count]);
      // this destroys the ordering of the mesh vertices on the edge
      ve.push_back(v);
    }
  }

  //  GLLquad = false;
  return true;
}

static bool getEdgeVerticesOnGeo(GFace *gf, MVertex *v0, MVertex *v1,
                                 std::vector<MVertex *> &ve, int nPts = 1)
{
  SPoint2 p0, p1;
  double US[100], VS[100];
  bool reparamOK;
  if(onBoundaryOfFace(v0) || onBoundaryOfFace(v1)) {
    std::lock_guard<std::mutex> lock(boundaryReparamMutex);
    reparamOK = reparamMeshEdgeOnFace(v0, v1, gf, p0, p1);
  }
  else
    reparamOK = reparamMeshEdgeOnFace(v0, v1, gf, p0, p1);
  if(reparamOK) {
    SPoint3 pnt0, pnt1;
    if(nPts >= 30)
      computeEquidistantParameters(gf, p0[0], p1[0], p0[1], p1[1], pnt0, pnt1,
                                   nPts + 2, false, US, VS);
    else {
      pnt0 = v0->point();
      pnt1 = v1->point();
      // warning: using the geodesic is sometimes a bad idea when the edge is
      // "far away" from the surface (e.g. on the diameter of a circle!);
      // however removing this can cause failures on surfaces with singular
      // parametrizations like spheroids (see #1271)
      computeEquidistantParameters(gf, p0[0], p1[0], p0[1], p1[1], pnt0, pnt1,
                                   nPts + 2, true, US, VS);
    }
  }
  else {
    Msg::Error("Cannot reparametrize mesh edge %zu-%zu on surface %d",
               v0->getNum(), v1->getNum(), gf->tag());
    return false;
  }

  for(int j = 0; j < nPts; j++) {
    GPoint pc = gf->point(US[j + 1], VS[j + 1]);
    MVertex *v =
      new MFaceVertex(pc.x(), pc.y(), pc.z(), gf, US[j + 1], VS[j + 1]);
    ve.push_back(v);
  }

  return true;
}

static void interpVerticesInExistingEdge(GEntity *ge, const MElement *edgeEl,
                                         std::vector<MVertex *> &veEdge,
                                         int nPts)
{
  const fullMatrix<double> &points = edgeEl->getFunctionSpace(nPts + 1)->points;
  for(int k = 2; k < nPts + 2; k++) {
    SPoint3 pos;
    edgeEl->pnt(points(k, 0), 0., 0., pos);
    MVertex *v = new MVertex(pos.x(), pos.y(), pos.z(), ge);
    veEdge.push_back(v);
  }
}

// Interpolate new nodes on an existing edge, given by its nodes in the canonical
// orientation (see canonicalEdgeVertices)
static void interpVerticesInExistingEdge(GEntity *ge,
                                         const std::vector<MVertex *> &ve,
                                         int order,
                                         std::vector<MVertex *> &veEdge,
                                         int nPts)
{
  if(order == 1) { // avoid copying the nodes in an MLineN
    const MLine edgeEl(ve[0], ve[1]);
    interpVerticesInExistingEdge(ge, &edgeEl, veEdge, nPts);
  }
  else {
    const MLineN edgeEl(ve, order);
    interpVerticesInExistingEdge(ge, &edgeEl, veEdge, nPts);
  }
}

inline static bool getMinMaxVert(MVertex *v0, MVertex *v1, MVertex *&vMin,
                                 MVertex *&vMax)
{
  const bool increasing = (v0->getNum() < v1->getNum());
  if(increasing) {
    vMin = v0;
    vMax = v1;
  }
  else {
    vMin = v1;
    vMax = v0;
  }
  return increasing;
}

// The nodes of an edge element in the orientation from its end node of
// smaller number to the one of larger number, interior nodes following. The
// high-order nodes of an edge are created in this orientation whichever
// element asks for them first, so that their positions do not depend on that
// element (nor, with threads, on which one came first)
static void canonicalEdgeVertices(const std::vector<MVertex *> &ve,
                                  bool increasing, std::vector<MVertex *> &out)
{
  if(increasing) {
    out = ve;
    return;
  }
  out.clear();
  out.push_back(ve[1]);
  out.push_back(ve[0]);
  for(std::size_t i = ve.size(); i > 2; i--) out.push_back(ve[i - 1]);
}

// Get new interior vertices for a 1D element
static void getEdgeVertices(GEdge *ge, MElement *ele,
                            std::vector<MVertex *> &ve,
                            edgeContainer &edgeVertices, bool linear,
                            int nPts = 1)
{
  if(!ge->haveParametrization()) linear = true;

  std::vector<MVertex *> veOld;
  ele->getVertices(veOld);
  MVertex *vMin, *vMax;
  const bool increasing = getMinMaxVert(veOld[0], veOld[1], vMin, vMax);
  std::pair<MVertex *, MVertex *> p(vMin, vMax);

  // created in the canonical orientation (see canonicalEdgeVertices)
  std::vector<MVertex *> veCanon, veEdge;
  canonicalEdgeVertices(veOld, increasing, veCanon);
  // Get vertices on geometry if asked
  bool gotVertOnGeo =
    linear ? false : getEdgeVerticesOnGeo(ge, vMin, vMax, veEdge, nPts);
  // If not on geometry, create from mesh interpolation
  if(!gotVertOnGeo) {
    interpVerticesInExistingEdge(ge, veCanon, ele->getPolynomialOrder(),
                                 veEdge, nPts);
  }
  if(!increasing) std::reverse(veEdge.begin(), veEdge.end());
  const std::size_t sh = edgeVertices.shardOf(p);
  shardLock<edgeContainer> lock(edgeVertices, sh);
  edgeMap &em = edgeVertices.shard(sh);
  if(!em.find(p)) {
    if(increasing) // Add newly created vertices to list
      em.insert(p, veEdge.begin(), veEdge.end());
    else
      em.insert(p, veEdge.rbegin(), veEdge.rend());
  }
  else if(p.first != p.second) {
    // Vertices already exist and edge is not a degenerated edge
    Msg::Error(
      "Mesh edges from different curves share nodes: create a finer mesh "
      "(curve involved: %d)",
      ge->tag());
  }
  ve.insert(ve.end(), veEdge.begin(), veEdge.end());
}

// Get new interior vertices for an edge in a 2D element
static void getEdgeVertices(GFace *gf, MElement *ele,
                            std::vector<MVertex *> &ve,
                            edgeContainer &edgeVertices, bool linear,
                            int nPts = 1)
{
  if(!gf->haveParametrization()) linear = true;

  for(int i = 0; i < ele->getNumEdges(); i++) {
    std::vector<MVertex *> veOld;
    ele->getEdgeVertices(i, veOld);
    MVertex *vMin, *vMax;
    const bool increasing = getMinMaxVert(veOld[0], veOld[1], vMin, vMax);
    std::pair<MVertex *, MVertex *> p(vMin, vMax);
    std::vector<MVertex *> veEdge;

    const std::size_t sh = edgeVertices.shardOf(p);
    shardLock<edgeContainer> lock(edgeVertices, sh);
    edgeMap &em = edgeVertices.shard(sh);
    const edgeMap::entry *eIter = em.find(p);

    if(eIter) { // Vertices already exist
      MVertex *const *eVtcs = em.nodes(eIter);
      if(increasing)
        veEdge.assign(eVtcs, eVtcs + eIter->num);
      else
        veEdge.assign(std::reverse_iterator<MVertex *const *>(eVtcs + eIter->num),
                      std::reverse_iterator<MVertex *const *>(eVtcs));
    }
    else { // Vertices do not exist, create them, in the canonical
           // orientation (see canonicalEdgeVertices)
      std::vector<MVertex *> veCanon;
      canonicalEdgeVertices(veOld, increasing, veCanon);
      // Get vertices on geometry if asked
      bool gotVertOnGeo =
        linear ? false : getEdgeVerticesOnGeo(gf, vMin, vMax, veEdge, nPts);
      if(!gotVertOnGeo) {
        // If not on geometry, create from mesh interpolation
        interpVerticesInExistingEdge(gf, veCanon, ele->getPolynomialOrder(),
                                     veEdge, nPts);
      }
      if(!increasing) std::reverse(veEdge.begin(), veEdge.end());

      if(increasing) // Add newly created vertices to list
        em.insert(p, veEdge.begin(), veEdge.end());
      else
        em.insert(p, veEdge.rbegin(), veEdge.rend());
    }
    ve.insert(ve.end(), veEdge.begin(), veEdge.end());
  }
}

// Get new interior vertices for an edge in a 3D element
static void getEdgeVertices(GRegion *gr, MElement *ele,
                            std::vector<MVertex *> &ve,
                            edgeContainer &edgeVertices, int nPts = 1)
{
  std::vector<MVertex *> veOld, veEdge, veCanon;
  ve.reserve(ve.size() + ele->getNumEdges() * nPts);
  for(int i = 0; i < ele->getNumEdges(); i++) {
    veOld.clear();
    ele->getEdgeVertices(i, veOld);
    MVertex *vMin, *vMax;
    const bool increasing = getMinMaxVert(veOld[0], veOld[1], vMin, vMax);
    std::pair<MVertex *, MVertex *> p(vMin, vMax);
    veEdge.clear();
    const std::size_t sh = edgeVertices.shardOf(p);
    shardLock<edgeContainer> lock(edgeVertices, sh);
    edgeMap &em = edgeVertices.shard(sh);
    const edgeMap::entry *eIter = em.find(p);
    if(eIter) { // Vertices already exist
      MVertex *const *eVtcs = em.nodes(eIter);
      if(increasing)
        veEdge.assign(eVtcs, eVtcs + eIter->num);
      else
        veEdge.assign(std::reverse_iterator<MVertex *const *>(eVtcs + eIter->num),
                      std::reverse_iterator<MVertex *const *>(eVtcs));
    }
    else { // Vertices do not exist, create them, in the canonical
           // orientation (see canonicalEdgeVertices)
      canonicalEdgeVertices(veOld, increasing, veCanon);
      interpVerticesInExistingEdge(gr, veCanon, ele->getPolynomialOrder(),
                                   veEdge, nPts);
      if(!increasing) std::reverse(veEdge.begin(), veEdge.end());
      if(increasing) // Add newly created vertices to list
        em.insert(p, veEdge.begin(), veEdge.end());
      else
        em.insert(p, veEdge.rbegin(), veEdge.rend());
    }
    ve.insert(ve.end(), veEdge.begin(), veEdge.end());
  }
}

// Creation of high-order face vertices

static void reorientTrianglePoints(std::vector<MVertex *> &vtcs,
                                   int orientation, bool swap)
{
  int nbPts = vtcs.size();
  if(nbPts <= 1) return;
  std::vector<MVertex *> tmp(nbPts);
  int interiorOrder = (int)((sqrt(1. + 8. * nbPts) - 3) / 2);
  int pos = 0;
  for(int o = interiorOrder; o > 0; o -= 3) {
    if(swap) {
      tmp[pos] = vtcs[pos];
      tmp[pos + 1] = vtcs[pos + 2];
      tmp[pos + 2] = vtcs[pos + 1];
      for(int i = 0; i < 3 * (o - 1); i++)
        tmp[pos + 3 + i] = vtcs[pos + 3 * o - i - 1];
    }
    else {
      for(int i = 0; i < 3 * o; i++) tmp[pos + i] = vtcs[pos + i];
    }
    for(int i = 0; i < 3; i++) {
      int ri = (i + orientation) % 3;
      vtcs[pos + ri] = tmp[pos + i];
      for(int j = 0; j < o - 1; j++)
        vtcs[pos + 3 + (o - 1) * ri + j] = tmp[pos + 3 + (o - 1) * i + j];
    }
    pos += 3 * o;
  }
}

static void reorientQuadPoints(std::vector<MVertex *> &vtcs, int orientation,
                               bool swap, int order)
{
  int nbPts = vtcs.size();
  if(nbPts <= 1) return;
  std::vector<MVertex *> tmp(nbPts);

  int start = 0;
  while(1) {
    // CORNERS
    int index = 0;
    if(order == 0) { start++; }
    else {
      int i1(0), i2(0), i3(0), i4(0);
      if(!swap) {
        if(orientation == 0) {
          i1 = 0;
          i2 = 1;
          i3 = 2;
          i4 = 3;
        }
        else if(orientation == 1) {
          i1 = 3;
          i2 = 0;
          i3 = 1;
          i4 = 2;
        }
        else if(orientation == 2) {
          i1 = 2;
          i2 = 3;
          i3 = 0;
          i4 = 1;
        }
        else if(orientation == 3) {
          i1 = 1;
          i2 = 2;
          i3 = 3;
          i4 = 0;
        }
      }
      else {
        if(orientation == 0) {
          i1 = 0;
          i2 = 3;
          i3 = 2;
          i4 = 1;
        }
        else if(orientation == 3) {
          i1 = 3;
          i2 = 2;
          i3 = 1;
          i4 = 0;
        }
        else if(orientation == 2) {
          i1 = 2;
          i2 = 1;
          i3 = 0;
          i4 = 3;
        }
        else if(orientation == 1) {
          i1 = 1;
          i2 = 0;
          i3 = 3;
          i4 = 2;
        }
      }

      int indices[4] = {i1, i2, i3, i4};
      for(int i = 0; i < 4; i++) tmp[i] = vtcs[start + indices[i]];
      for(int i = 0; i < 4; i++) vtcs[start + i] = tmp[i];

      // EDGES
      start += 4;
      for(int iEdge = 0; iEdge < 4; iEdge++) {
        int p1 = indices[iEdge];
        int p2 = indices[(iEdge + 1) % 4];
        int nbP = order - 1;
        if(p1 == 0 && p2 == 1) {
          for(int i = start + 0 * nbP; i < start + 1 * nbP; i++)
            tmp[index++] = vtcs[i];
        }
        else if(p1 == 1 && p2 == 2) {
          for(int i = start + 1 * nbP; i < start + 2 * nbP; i++)
            tmp[index++] = vtcs[i];
        }
        else if(p1 == 2 && p2 == 3) {
          for(int i = start + 2 * nbP; i < start + 3 * nbP; i++)
            tmp[index++] = vtcs[i];
        }
        else if(p1 == 3 && p2 == 0) {
          for(int i = start + 3 * nbP; i < start + 4 * nbP; i++)
            tmp[index++] = vtcs[i];
        }
        else if(p1 == 1 && p2 == 0) {
          for(int i = start + 1 * nbP - 1; i >= start + 0 * nbP; i--)
            tmp[index++] = vtcs[i];
        }
        else if(p1 == 2 && p2 == 1) {
          for(int i = start + 2 * nbP - 1; i >= start + 1 * nbP; i--)
            tmp[index++] = vtcs[i];
        }
        else if(p1 == 3 && p2 == 2) {
          for(int i = start + 3 * nbP - 1; i >= start + 2 * nbP; i--)
            tmp[index++] = vtcs[i];
        }
        else if(p1 == 0 && p2 == 3) {
          for(int i = start + 4 * nbP - 1; i >= start + 3 * nbP; i--)
            tmp[index++] = vtcs[i];
        }
        else
          Msg::Error("Something wrong in reorientQuadPoints");
      }
      for(int i = 0; i < index; i++) vtcs[start + i] = tmp[i];
      start += index;
    }

    order -= 2;
    if(start >= (int)vtcs.size()) break;
  }
}

static void interpVerticesInExistingFace(GEntity *ge,
                                         const fullMatrix<double> &coefficients,
                                         const std::vector<MVertex *> &vertices,
                                         std::vector<MVertex *> &vFace)
{
  for(int k = 0; k < coefficients.size1(); k++) {
    double x(0), y(0), z(0);
    for(int j = 0; j < coefficients.size2(); j++) {
      MVertex *v = vertices[j];
      x += coefficients(k, j) * v->x();
      y += coefficients(k, j) * v->y();
      z += coefficients(k, j) * v->z();
    }
    vFace.push_back(new MVertex(x, y, z, ge));
  }
}

static bool getFaceVerticesOnExtrudedGeo(GFace *gf,
                                         const fullMatrix<double> &coefficients,
                                         const std::vector<MVertex *> &vertices,
                                         std::vector<MVertex *> &vf)
{
  // special case for 9 node quads...
  if(coefficients.size1() != 1 || vertices.size() != 8) return false;

  // ...on surfaces with recombined extruded meshes, generated by translation...
  ExtrudeParams *ep = gf->meshAttributes.extrude;
  if(!ep || !ep->mesh.ExtrudeMesh || !ep->mesh.Recombine ||
     ep->geo.Mode != EXTRUDED_ENTITY || ep->geo.Type != TRANSLATE)
    return false;

  // ...then this is exact
  interpVerticesInExistingFace(gf, coefficients, vertices, vf);
  return true;
}

static void getFaceVerticesOnGeo(GFace *gf,
                                 const fullMatrix<double> &coefficients,
                                 const std::vector<MVertex *> &vertices,
                                 std::vector<MVertex *> &vf)
{
  SPoint2 pts[1000];
  bool reparamOK = true;
  bool onBoundary = false;
  for(std::size_t k = 0; k < vertices.size(); ++k)
    onBoundary = onBoundary || onBoundaryOfFace(vertices[k]);
  if(onBoundary) {
    std::lock_guard<std::mutex> lock(boundaryReparamMutex);
    for(std::size_t k = 0; k < vertices.size(); ++k)
      reparamOK &= reparamMeshVertexOnFace(vertices[k], gf, pts[k]);
  }
  else {
    for(std::size_t k = 0; k < vertices.size(); ++k)
      reparamOK &= reparamMeshVertexOnFace(vertices[k], gf, pts[k]);
  }
  for(int k = 0; k < coefficients.size1(); k++) {
    double X(0), Y(0), Z(0), GUESS[2] = {0, 0};
    for(int j = 0; j < coefficients.size2(); j++) {
      MVertex *vt = vertices[j];
      X += coefficients(k, j) * vt->x();
      Y += coefficients(k, j) * vt->y();
      Z += coefficients(k, j) * vt->z();
      if(reparamOK) {
        GUESS[0] += coefficients(k, j) * pts[j][0];
        GUESS[1] += coefficients(k, j) * pts[j][1];
      }
    }
    MVertex *v;
    if(reparamOK) {
      // closestPoint is absolutely necessary when the parameterization is
      // degenerate
      GPoint gp;
      if(gf->geomType() == GEntity::Plane) {
        gp = gf->point(SPoint2(GUESS[0], GUESS[1]));
      }
      else {
        SPoint3 pc(X, Y, Z);
        gp = gf->closestPoint(pc, GUESS);
        // see the comment in computeEquidistantParameters(): an interpolated
        // guess is not reliable across a seam, so check that the projection
        // stays within the element it was computed from
        if(gp.succeeded()) {
          double h = 0.;
          for(std::size_t j = 0; j < vertices.size(); j++)
            h = std::max(h, pc.distance(vertices[j]->point()));
          if(pc.distance(SPoint3(gp.x(), gp.y(), gp.z())) > h)
            gp = gf->closestPoint(pc, nullptr);
        }
      }
      if(gp.g()) {
        v = new MFaceVertex(gp.x(), gp.y(), gp.z(), gf, gp.u(), gp.v());
      }
      else {
        v = new MVertex(X, Y, Z, gf);
      }
    }
    else {
      // no reparametrization: GUESS was never computed, so don't pass it on
      GPoint gp = gf->closestPoint(SPoint3(X, Y, Z), nullptr);
      if(gp.succeeded())
        v = new MVertex(gp.x(), gp.y(), gp.z(), gf);
      else
        v = new MVertex(X, Y, Z, gf);
    }
    vf.push_back(v);
  }
}

// Get new interior vertices for a 2D element
static void getFaceVertices(GFace *gf, MElement *ele,
                            std::vector<MVertex *> &newVertices,
                            faceContainer &faceVertices, bool linear,
                            int nPts = 1)
{
  if(!gf->haveParametrization()) linear = true;

  std::vector<MVertex *> boundaryVertices;
  {
    std::size_t nCorner = ele->getNumPrimaryVertices();
    boundaryVertices.reserve(nCorner + newVertices.size());
    ele->getVertices(boundaryVertices);
    boundaryVertices.resize(nCorner);
    boundaryVertices.insert(boundaryVertices.end(), newVertices.begin(),
                            newVertices.end());
  }
  int type = ele->getType();
  fullMatrix<double> *coefficients = getInnerVertexPlacement(type, nPts + 1);
  std::vector<MVertex *> vFace;
  if(!linear) { // Get vertices on geometry if asked...
    // special case for 2nd order quads on surfaces generated by extrusion
    // (translation): this allows to speed up a common case (extruded OCC
    // models) by orders of magnitudes, where OCC closestPoint() is atrociously
    // slow
    if(!getFaceVerticesOnExtrudedGeo(gf, *coefficients, boundaryVertices,
                                     vFace))
      getFaceVerticesOnGeo(gf, *coefficients, boundaryVertices, vFace);
  }
  else { // ... otherwise, create from mesh interpolation
    interpVerticesInExistingFace(gf, *coefficients, boundaryVertices, vFace);
  }

  MFace face = ele->getFace(0);
  {
    const std::size_t sh = faceVertices.shardOf(face);
    shardLock<faceContainer> lock(faceVertices, sh);
    faceMap &fm = faceVertices.shard(sh);
    if(!fm.find(face)) fm.insert(face, vFace.begin(), vFace.end());
  }
  newVertices.insert(newVertices.end(), vFace.begin(), vFace.end());
}

static int retrieveFaceBoundaryVertices(int k, int type, int nPts,
                                        const std::vector<MVertex *> &vCorner,
                                        const std::vector<MVertex *> &vEdges,
                                        std::vector<MVertex *> &v)
{
  v.clear();
  int nCorner;
  switch(type) {
  case TYPE_TET:
    v.push_back(vCorner[MTetrahedron::faces_tetra(k, 0)]);
    v.push_back(vCorner[MTetrahedron::faces_tetra(k, 1)]);
    v.push_back(vCorner[MTetrahedron::faces_tetra(k, 2)]);
    for(int i = 0; i < 3; ++i) {
      int edge = MTetrahedron::faces2edge_tetra(k, i);
      int n = std::abs(edge) - 1;
      v.insert(v.end(), vEdges.begin() + n * nPts,
               vEdges.begin() + (n + 1) * nPts);
      if(edge < 0) std::reverse(v.end() - nPts, v.end());
    }
    return TYPE_TRI;
  case TYPE_HEX:
    v.push_back(vCorner[MHexahedron::faces_hexa(k, 0)]);
    v.push_back(vCorner[MHexahedron::faces_hexa(k, 1)]);
    v.push_back(vCorner[MHexahedron::faces_hexa(k, 2)]);
    v.push_back(vCorner[MHexahedron::faces_hexa(k, 3)]);
    for(int i = 0; i < 4; ++i) {
      int edge = MHexahedron::faces2edge_hexa(k, i);
      int n = std::abs(edge) - 1;
      v.insert(v.end(), vEdges.begin() + n * nPts,
               vEdges.begin() + (n + 1) * nPts);
      if(edge < 0) std::reverse(v.end() - nPts, v.end());
    }
    return TYPE_QUA;
  case TYPE_PRI:
    nCorner = k < 2 ? 3 : 4;
    v.push_back(vCorner[MPrism::faces_prism(k, 0)]);
    v.push_back(vCorner[MPrism::faces_prism(k, 1)]);
    v.push_back(vCorner[MPrism::faces_prism(k, 2)]);
    if(nCorner == 4) v.push_back(vCorner[MPrism::faces_prism(k, 3)]);
    for(int i = 0; i < nCorner; ++i) {
      int edge = MPrism::faces2edge_prism(k, i);
      int n = std::abs(edge) - 1;
      v.insert(v.end(), vEdges.begin() + n * nPts,
               vEdges.begin() + (n + 1) * nPts);
      if(edge < 0) std::reverse(v.end() - nPts, v.end());
    }
    return nCorner == 3 ? TYPE_TRI : TYPE_QUA;
  case TYPE_PYR:
    nCorner = k < 4 ? 3 : 4;
    v.push_back(vCorner[MPyramid::faces_pyramid(k, 0)]);
    v.push_back(vCorner[MPyramid::faces_pyramid(k, 1)]);
    v.push_back(vCorner[MPyramid::faces_pyramid(k, 2)]);
    if(nCorner == 4) v.push_back(vCorner[MPyramid::faces_pyramid(k, 3)]);
    for(int i = 0; i < nCorner; ++i) {
      int edge = MPyramid::faces2edge_pyramid(k, i);
      int n = std::abs(edge) - 1;
      v.insert(v.end(), vEdges.begin() + n * nPts,
               vEdges.begin() + (n + 1) * nPts);
      if(edge < 0) std::reverse(v.end() - nPts, v.end());
    }
    return nCorner == 3 ? TYPE_TRI : TYPE_QUA;
  default: return -1;
  }
}

// The boundary nodes of a face (its corners, then the nodes of its edges, from
// each corner to the next) in the orientation starting from its corner of
// smallest number, towards the neighbor of smaller number. The high-order nodes
// of a face are created in this orientation whichever element asks for them
// first, so that their positions do not depend on that element (nor, with
// threads, on which one came first)
static void canonicalFaceVertices(const std::vector<MVertex *> &b, int nCorner,
                                  int nPts, std::vector<MVertex *> &out)
{
  int s = 0;
  for(int i = 1; i < nCorner; i++)
    if(b[i]->getNum() < b[s]->getNum()) s = i;
  const bool forward = b[(s + 1) % nCorner]->getNum() <
                       b[(s + nCorner - 1) % nCorner]->getNum();
  out.clear();
  for(int i = 0; i < nCorner; i++)
    out.push_back(b[forward ? (s + i) % nCorner : (s - i + nCorner) % nCorner]);
  for(int i = 0; i < nCorner; i++) {
    if(forward) {
      auto e = b.begin() + nCorner + ((s + i) % nCorner) * nPts;
      out.insert(out.end(), e, e + nPts);
    }
    else { // the edge from corner s - i to s - i - 1, reversed
      auto e = b.begin() + nCorner + ((s - i - 1 + 2 * nCorner) % nCorner) * nPts;
      out.insert(out.end(), std::reverse_iterator<decltype(e)>(e + nPts),
                 std::reverse_iterator<decltype(e)>(e));
    }
  }
}

// Get new face (excluding edge) vertices for a face of a 3D element
static void getFaceVertices(GRegion *gr, MElement *ele,
                            std::vector<MVertex *> &newVertices,
                            faceContainer &faceVertices, int nPts = 1)
{
  std::vector<MVertex *> vCorner;
  ele->getVertices(vCorner);
  // NB: We can get more than corner vertices but we use only corners

  std::vector<MVertex *> vFace, faceBoundaryVertices, canonical;
  for(int i = 0; i < ele->getNumFaces(); i++) {
    MFace face = ele->getFace(i);
    vFace.clear();
    const std::size_t sh = faceVertices.shardOf(face);
    shardLock<faceContainer> lock(faceVertices, sh);
    faceMap &fm = faceVertices.shard(sh);
    const faceMap::entry *fIter = fm.find(face);
    if(!fIter) { // Vertices do not exist, create them by interpolation, in the
                 // canonical orientation (see canonicalFaceVertices)
      int type = retrieveFaceBoundaryVertices(
        i, ele->getType(), nPts, vCorner, newVertices, faceBoundaryVertices);
      const int nCorner = (type == TYPE_TRI) ? 3 : 4;
      canonicalFaceVertices(faceBoundaryVertices, nCorner, nPts, canonical);
      fullMatrix<double> *coefficients =
        getInnerVertexPlacement(type, nPts + 1);
      interpVerticesInExistingFace(gr, *coefficients, canonical, vFace);
      const MFace key(canonical[0], canonical[1], canonical[2],
                      nCorner == 4 ? canonical[3] : nullptr);
      fIter = fm.insert(key, vFace.begin(), vFace.end());
    }
    vFace.assign(fm.nodes(fIter), fm.nodes(fIter) + fIter->num);
    int orientation;
    bool swap;
    if(fIter->key.computeCorrespondence(face, orientation, swap)) {
      // Check correspondence and apply permutation if needed
      if(face.getNumVertices() == 3 && nPts > 1)
        reorientTrianglePoints(vFace, orientation, swap);
      else if(face.getNumVertices() == 4)
        reorientQuadPoints(vFace, orientation, swap, nPts - 1);
    }
    else
      Msg::Error("Error in face lookup for retrieval of high order face nodes");
    newVertices.insert(newVertices.end(), vFace.begin(), vFace.end());
  }
}

// Get new interior vertices for a 3D element
static void getVolumeVertices(GRegion *gr, MElement *ele,
                              std::vector<MVertex *> &newVertices, int nPts = 1)
{
  std::vector<MVertex *> boundaryVertices;
  {
    std::size_t nCorner = ele->getNumPrimaryVertices();
    boundaryVertices.reserve(nCorner + newVertices.size());
    ele->getVertices(boundaryVertices);
    boundaryVertices.resize(nCorner);
    boundaryVertices.insert(boundaryVertices.end(), newVertices.begin(),
                            newVertices.end());
  }
  int type = ele->getType();
  fullMatrix<double> &coefficients = *getInnerVertexPlacement(type, nPts + 1);

  for(int k = 0; k < coefficients.size1(); k++) {
    double x(0), y(0), z(0);
    for(int j = 0; j < coefficients.size2(); j++) {
      MVertex *v = boundaryVertices[j];
      x += coefficients(k, j) * v->x();
      y += coefficients(k, j) * v->y();
      z += coefficients(k, j) * v->z();
    }
    MVertex *v = new MVertex(x, y, z, gr);
    newVertices.push_back(v);
  }
}

// Creation of high-order elements

// The nodal bases (BasisFactory) and the inner node placement matrices are
// global caches, filled on first use behind an unprotected lookup. Fill the
// entries the loops below are going to need before going parallel, so that they
// are only ever read from several threads.
template <class T>
static void warmUpCaches(const std::vector<T *> &elements, int nPts)
{
  if(elements.empty()) return;
  MElement *e = elements[0];
  e->getFunctionSpace();
  e->getFunctionSpace(nPts + 1);
  getInnerVertexPlacement(e->getType(), nPts + 1);
  for(int i = 0; i < e->getNumFaces(); i++) {
    MFace f = e->getFace(i);
    getInnerVertexPlacement(f.getNumVertices() == 3 ? TYPE_TRI : TYPE_QUA,
                            nPts + 1);
  }
  if(e->getNumEdges()) { // used to interpolate the nodes of an existing edge
    std::vector<MVertex *> ve;
    e->getEdgeVertices(0, ve);
    const MLineN edgeEl(ve, e->getPolynomialOrder());
    edgeEl.getFunctionSpace();
    edgeEl.getFunctionSpace(nPts + 1);
  }
}

static void setHighOrder(GEdge *ge, edgeContainer &edgeVertices, bool linear,
                         int nbPts = 1)
{
  std::vector<MLine *> lines2;
  for(std::size_t i = 0; i < ge->lines.size(); i++) {
    MLine *l = ge->lines[i];
    std::vector<MVertex *> ve;
    getEdgeVertices(ge, l, ve, edgeVertices, linear, nbPts);
    if(nbPts == 1)
      lines2.push_back(
        new MLine3(l->getVertex(0), l->getVertex(1), ve[0], l->getPartition()));
    else
      lines2.push_back(
        new MLineN(l->getVertex(0), l->getVertex(1), ve, l->getPartition()));
    delete l;
  }
  ge->lines = lines2;
  ge->deleteVertexArrays();
}

static MTriangle *setHighOrder(MTriangle *t, GFace *gf,
                               edgeContainer &edgeVertices,
                               faceContainer &faceVertices, bool linear,
                               bool incomplete, int nPts)
{
  std::vector<MVertex *> v;
  getEdgeVertices(gf, t, v, edgeVertices, linear, nPts);
  if(nPts == 1) {
    return new MTriangle6(t->getVertex(0), t->getVertex(1), t->getVertex(2),
                          v[0], v[1], v[2], 0, t->getPartition());
  }
  else {
    if(!incomplete) getFaceVertices(gf, t, v, faceVertices, linear, nPts);
    return new MTriangleN(t->getVertex(0), t->getVertex(1), t->getVertex(2), v,
                          nPts + 1, 0, t->getPartition());
  }
}

static MQuadrangle *setHighOrder(MQuadrangle *q, GFace *gf,
                                 edgeContainer &edgeVertices,
                                 faceContainer &faceVertices, bool linear,
                                 bool incomplete, int nPts)
{
  std::vector<MVertex *> v;
  getEdgeVertices(gf, q, v, edgeVertices, linear, nPts);
  if(incomplete) {
    if(nPts == 1) {
      return new MQuadrangle8(q->getVertex(0), q->getVertex(1), q->getVertex(2),
                              q->getVertex(3), v[0], v[1], v[2], v[3], 0,
                              q->getPartition());
    }
    else {
      return new MQuadrangleN(q->getVertex(0), q->getVertex(1), q->getVertex(2),
                              q->getVertex(3), v, nPts + 1, 0,
                              q->getPartition());
    }
  }
  else {
    getFaceVertices(gf, q, v, faceVertices, linear, nPts);
    if(nPts == 1) {
      return new MQuadrangle9(q->getVertex(0), q->getVertex(1), q->getVertex(2),
                              q->getVertex(3), v[0], v[1], v[2], v[3], v[4], 0,
                              q->getPartition());
    }
    else {
      return new MQuadrangleN(q->getVertex(0), q->getVertex(1), q->getVertex(2),
                              q->getVertex(3), v, nPts + 1, 0,
                              q->getPartition());
    }
  }
}

static void setHighOrder(GFace *gf, edgeContainer &edgeVertices,
                         faceContainer &faceVertices, bool linear,
                         bool incomplete, int nPts = 1, int nthreads = 1)
{
  warmUpCaches(gf->triangles, nPts);
  warmUpCaches(gf->quadrangles, nPts);

  std::vector<MTriangle *> triangles2(gf->triangles.size());
#pragma omp parallel for schedule(static) num_threads(nthreads)                \
  if(nthreads > 1)
  for(std::size_t i = 0; i < gf->triangles.size(); i++) {
    triangles2[i] = setHighOrder(gf->triangles[i], gf, edgeVertices,
                                 faceVertices, linear, incomplete, nPts);
  }
  for(std::size_t i = 0; i < gf->triangles.size(); i++) delete gf->triangles[i];
  gf->triangles = triangles2;

  std::vector<MQuadrangle *> quadrangles2(gf->quadrangles.size());
#pragma omp parallel for schedule(static) num_threads(nthreads)                \
  if(nthreads > 1)
  for(std::size_t i = 0; i < gf->quadrangles.size(); i++) {
    quadrangles2[i] = setHighOrder(gf->quadrangles[i], gf, edgeVertices,
                                   faceVertices, linear, incomplete, nPts);
  }
  for(std::size_t i = 0; i < gf->quadrangles.size(); i++)
    delete gf->quadrangles[i];
  gf->quadrangles = quadrangles2;
  gf->deleteVertexArrays();
}

static MTetrahedron *setHighOrder(MTetrahedron *t, GRegion *gr,
                                  edgeContainer &edgeVertices,
                                  faceContainer &faceVertices, bool incomplete,
                                  int nPts)
{
  std::vector<MVertex *> v;
  getEdgeVertices(gr, t, v, edgeVertices, nPts);
  if(nPts == 1) {
    return new MTetrahedron10(t->getVertex(0), t->getVertex(1), t->getVertex(2),
                              t->getVertex(3), v[0], v[1], v[2], v[3], v[4],
                              v[5], 0, t->getPartition());
  }
  else {
    if(!incomplete) {
      getFaceVertices(gr, t, v, faceVertices, nPts);
      getVolumeVertices(gr, t, v, nPts);
    }
    return new MTetrahedronN(t->getVertex(0), t->getVertex(1), t->getVertex(2),
                             t->getVertex(3), v, nPts + 1, 0,
                             t->getPartition());
  }
}

static MHexahedron *setHighOrder(MHexahedron *h, GRegion *gr,
                                 edgeContainer &edgeVertices,
                                 faceContainer &faceVertices, bool incomplete,
                                 int nPts)
{
  std::vector<MVertex *> v;
  getEdgeVertices(gr, h, v, edgeVertices, nPts);
  if(incomplete) {
    if(nPts == 1) {
      return new MHexahedron20(
        h->getVertex(0), h->getVertex(1), h->getVertex(2), h->getVertex(3),
        h->getVertex(4), h->getVertex(5), h->getVertex(6), h->getVertex(7),
        v[0], v[1], v[2], v[3], v[4], v[5], v[6], v[7], v[8], v[9], v[10],
        v[11], 0, h->getPartition());
    }
    else {
      return new MHexahedronN(h->getVertex(0), h->getVertex(1), h->getVertex(2),
                              h->getVertex(3), h->getVertex(4), h->getVertex(5),
                              h->getVertex(6), h->getVertex(7), v, nPts + 1, 0,
                              h->getPartition());
    }
  }
  else {
    getFaceVertices(gr, h, v, faceVertices, nPts);
    getVolumeVertices(gr, h, v, nPts);
    if(nPts == 1) {
      return new MHexahedron27(
        h->getVertex(0), h->getVertex(1), h->getVertex(2), h->getVertex(3),
        h->getVertex(4), h->getVertex(5), h->getVertex(6), h->getVertex(7),
        v[0], v[1], v[2], v[3], v[4], v[5], v[6], v[7], v[8], v[9], v[10],
        v[11], v[12], v[13], v[14], v[15], v[16], v[17], v[18], 0,
        h->getPartition());
    }
    else {
      return new MHexahedronN(h->getVertex(0), h->getVertex(1), h->getVertex(2),
                              h->getVertex(3), h->getVertex(4), h->getVertex(5),
                              h->getVertex(6), h->getVertex(7), v, nPts + 1, 0,
                              h->getPartition());
    }
  }
}

static MPrism *setHighOrder(MPrism *p, GRegion *gr, edgeContainer &edgeVertices,
                            faceContainer &faceVertices, bool incomplete,
                            int nPts)
{
  std::vector<MVertex *> v;
  getEdgeVertices(gr, p, v, edgeVertices, nPts);
  if(incomplete) {
    if(nPts == 1) {
      return new MPrism15(p->getVertex(0), p->getVertex(1), p->getVertex(2),
                          p->getVertex(3), p->getVertex(4), p->getVertex(5),
                          v[0], v[1], v[2], v[3], v[4], v[5], v[6], v[7], v[8],
                          0, p->getPartition());
    }
    else {
      return new MPrismN(p->getVertex(0), p->getVertex(1), p->getVertex(2),
                         p->getVertex(3), p->getVertex(4), p->getVertex(5), v,
                         nPts + 1, 0, p->getPartition());
    }
  }
  else {
    getFaceVertices(gr, p, v, faceVertices, nPts);
    if(nPts == 1) {
      return new MPrism18(p->getVertex(0), p->getVertex(1), p->getVertex(2),
                          p->getVertex(3), p->getVertex(4), p->getVertex(5),
                          v[0], v[1], v[2], v[3], v[4], v[5], v[6], v[7], v[8],
                          v[9], v[10], v[11], 0, p->getPartition());
    }
    else {
      getVolumeVertices(gr, p, v, nPts);
      return new MPrismN(p->getVertex(0), p->getVertex(1), p->getVertex(2),
                         p->getVertex(3), p->getVertex(4), p->getVertex(5), v,
                         nPts + 1, 0, p->getPartition());
    }
  }
}

static MPyramid *setHighOrder(MPyramid *p, GRegion *gr,
                              edgeContainer &edgeVertices,
                              faceContainer &faceVertices, bool incomplete,
                              int nPts)
{
  std::vector<MVertex *> v;
  getEdgeVertices(gr, p, v, edgeVertices, nPts);
  if(!incomplete) {
    getFaceVertices(gr, p, v, faceVertices, nPts);
    if(nPts > 1) { getVolumeVertices(gr, p, v, nPts); }
  }
  return new MPyramidN(p->getVertex(0), p->getVertex(1), p->getVertex(2),
                       p->getVertex(3), p->getVertex(4), v, nPts + 1, 0,
                       p->getPartition());
}

static void setHighOrder(GRegion *gr, edgeContainer &edgeVertices,
                         faceContainer &faceVertices, bool incomplete,
                         int nPts = 1, int nthreads = 1)
{
  warmUpCaches(gr->tetrahedra, nPts);
  warmUpCaches(gr->hexahedra, nPts);
  warmUpCaches(gr->prisms, nPts);
  warmUpCaches(gr->pyramids, nPts);

  std::vector<MTetrahedron *> tetrahedra2(gr->tetrahedra.size());
#pragma omp parallel for schedule(static) num_threads(nthreads)                \
  if(nthreads > 1)
  for(std::size_t i = 0; i < gr->tetrahedra.size(); i++) {
    tetrahedra2[i] = setHighOrder(gr->tetrahedra[i], gr, edgeVertices, faceVertices, incomplete,
                         nPts);
  }
  for(std::size_t i = 0; i < gr->tetrahedra.size(); i++) delete gr->tetrahedra[i];
  gr->tetrahedra = tetrahedra2;

  std::vector<MHexahedron *> hexahedra2(gr->hexahedra.size());
#pragma omp parallel for schedule(static) num_threads(nthreads)                \
  if(nthreads > 1)
  for(std::size_t i = 0; i < gr->hexahedra.size(); i++) {
    hexahedra2[i] = setHighOrder(gr->hexahedra[i], gr, edgeVertices, faceVertices, incomplete,
                         nPts);
  }
  for(std::size_t i = 0; i < gr->hexahedra.size(); i++) delete gr->hexahedra[i];
  gr->hexahedra = hexahedra2;

  std::vector<MPrism *> prisms2(gr->prisms.size());
#pragma omp parallel for schedule(static) num_threads(nthreads)                \
  if(nthreads > 1)
  for(std::size_t i = 0; i < gr->prisms.size(); i++) {
    prisms2[i] = setHighOrder(gr->prisms[i], gr, edgeVertices, faceVertices, incomplete,
                         nPts);
  }
  for(std::size_t i = 0; i < gr->prisms.size(); i++) delete gr->prisms[i];
  gr->prisms = prisms2;

  std::vector<MPyramid *> pyramids2(gr->pyramids.size());
#pragma omp parallel for schedule(static) num_threads(nthreads)                \
  if(nthreads > 1)
  for(std::size_t i = 0; i < gr->pyramids.size(); i++) {
    pyramids2[i] = setHighOrder(gr->pyramids[i], gr, edgeVertices, faceVertices, incomplete,
                         nPts);
  }
  for(std::size_t i = 0; i < gr->pyramids.size(); i++) delete gr->pyramids[i];
  gr->pyramids = pyramids2;

  gr->deleteVertexArrays();
}

// High-level functions

template <class T>
static void setFirstOrder(GEntity *e, std::vector<T *> &elements,
                          bool onlyVisible, bool skipDiscrete)
{
  if(onlyVisible && !e->getVisibility()) return;
  if(skipDiscrete && e->isFullyDiscrete()) return;
  std::vector<T *> elements1;
  for(std::size_t i = 0; i < elements.size(); i++) {
    T *ele = elements[i];
    std::size_t n = ele->getNumPrimaryVertices();
    std::vector<MVertex *> v1;
    v1.reserve(n);
    for(std::size_t j = 0; j < n; j++) v1.push_back(ele->getVertex(j));
    elements1.push_back(new T(v1, 0, ele->getPartition()));
    delete ele;
  }
  elements = elements1;
  e->deleteVertexArrays();
}

static void deleteHighOrderVertices(GEntity *e, bool onlyVisible,
                                    bool skipDiscrete)
{
  if(onlyVisible && !e->getVisibility()) return;
  if(skipDiscrete && e->isFullyDiscrete()) return;
  std::vector<MVertex *> v1;
  for(std::size_t i = 0; i < e->mesh_vertices.size(); i++) {
    if(e->mesh_vertices[i]->getPolynomialOrder() > 1)
      delete e->mesh_vertices[i];
    else
      v1.push_back(e->mesh_vertices[i]);
  }
  e->mesh_vertices = v1;
  e->deleteVertexArrays();
}

void SetOrder1(GModel *m, bool onlyVisible, bool skipDiscrete)
{
  m->destroyMeshCaches();

  // replace all elements with first order elements
  for(auto it = m->firstEdge(); it != m->lastEdge(); ++it) {
    setFirstOrder(*it, (*it)->lines, onlyVisible, skipDiscrete);
  }
  for(auto it = m->firstFace(); it != m->lastFace(); ++it) {
    setFirstOrder(*it, (*it)->triangles, onlyVisible, skipDiscrete);
    setFirstOrder(*it, (*it)->quadrangles, onlyVisible, skipDiscrete);
  }
  for(auto it = m->firstRegion(); it != m->lastRegion(); ++it) {
    setFirstOrder(*it, (*it)->tetrahedra, onlyVisible, skipDiscrete);
    setFirstOrder(*it, (*it)->hexahedra, onlyVisible, skipDiscrete);
    setFirstOrder(*it, (*it)->prisms, onlyVisible, skipDiscrete);
    setFirstOrder(*it, (*it)->pyramids, onlyVisible, skipDiscrete);
  }

  // remove all high order vertices
  for(auto it = m->firstEdge(); it != m->lastEdge(); ++it)
    deleteHighOrderVertices(*it, onlyVisible, skipDiscrete);
  for(auto it = m->firstFace(); it != m->lastFace(); ++it)
    deleteHighOrderVertices(*it, onlyVisible, skipDiscrete);
  for(auto it = m->firstRegion(); it != m->lastRegion(); ++it)
    deleteHighOrderVertices(*it, onlyVisible, skipDiscrete);
}

void checkHighOrderTriangles(const char *cc, GModel *m,
                             std::vector<MElement *> &bad, double &minJGlob)
{
  bad.clear();
  minJGlob = 1.0;
  double minGGlob = 1.0;
  double avg = 0.0;
  int count = 0, nbfair = 0;
  for(auto it = m->firstFace(); it != m->lastFace(); ++it) {
    for(std::size_t i = 0; i < (*it)->triangles.size(); i++) {
      MTriangle *t = (*it)->triangles[i];
      double disto_ = t->distoShapeMeasure();
      double gamma_ = t->gammaShapeMeasure();
      double disto = disto_;
      minJGlob = std::min(minJGlob, disto);
      minGGlob = std::min(minGGlob, gamma_);
      avg += disto;
      count++;
      if(disto < 0)
        bad.push_back(t);
      else if(disto < 0.2)
        nbfair++;
    }
    /*
    for(std::size_t i = 0; i < (*it)->quadrangles.size(); i++){
      MQuadrangle *t = (*it)->quadrangles[i];
      double disto_ = t->distoShapeMeasure();
      double gamma_ = t->gammaShapeMeasure();
      double disto = disto_;
      minJGlob = std::min(minJGlob, disto);
      minGGlob = std::min(minGGlob, gamma_);
      avg += disto; count++;
      if (disto < 0) bad.push_back(t);
      else if (disto < 0.2) nbfair++;
    }
    */
  }
  if(!count) return;
  if(minJGlob > 0)
    Msg::Info(
      "%s: worst distortion = %g (%d elements in ]0, 0.2]); worst gamma = %g",
      cc, minJGlob, nbfair, minGGlob);
  else
    Msg::Warning(
      "%s: worst distortion = %g (avg = %g, %d elements with jac. < 0); "
      "worst gamma = %g",
      cc, minJGlob, avg / (count ? count : 1), bad.size(), minGGlob);
}

// The high-order nodes of a straight tetrahedron are where its corners put
// them: its scaled Jacobian is then 1 everywhere, and computing its distortion
// (the bulk of the time spent in the check, most tetrahedra being straight) can
// be skipped
static bool isStraight(MTetrahedron *t)
{
  const int n = t->getNumVertices();
  if(n == 4) return true;
  const fullMatrix<double> &pts = t->getFunctionSpace()->points;
  SPoint3 p0 = t->getVertex(0)->point(), p1 = t->getVertex(1)->point(),
          p2 = t->getVertex(2)->point(), p3 = t->getVertex(3)->point();
  const double tol =
    1e-10 * std::max(p0.distance(p1), std::max(p0.distance(p2), p0.distance(p3)));
  for(int i = 4; i < n; i++) {
    const double u = pts(i, 0), v = pts(i, 1), w = pts(i, 2);
    const SPoint3 p = p0 * (1. - u - v - w) + p1 * u + p2 * v + p3 * w;
    if(p.distance(t->getVertex(i)->point()) > tol) return false;
  }
  return true;
}

void checkHighOrderTetrahedron(const char *cc, GModel *m,
                               std::vector<MElement *> &bad, double &minJGlob)
{
  bad.clear();
  minJGlob = 1.0;
  double avg = 0.0;
  int count = 0, nbfair = 0;
  for(auto it = m->firstRegion(); it != m->lastRegion(); ++it) {
    for(std::size_t i = 0; i < (*it)->tetrahedra.size(); i++) {
      MTetrahedron *t = (*it)->tetrahedra[i];
      double disto_ = isStraight(t) ? 1. : t->distoShapeMeasure();
      minJGlob = std::min(minJGlob, disto_);
      avg += disto_;
      count++;
      if(disto_ < 0)
        bad.push_back(t);
      else if(disto_ < 0.2)
        nbfair++;
    }
  }
  if(!count) return;

  if(minJGlob > 0)
    Msg::Info("%s: worst distortion = %g (%d elements in ]0, 0.2])", cc,
              minJGlob, nbfair);
  else
    Msg::Warning(
      "%s: worst distortion = %g (avg = %g, %d elements with jac. < 0)", cc,
      minJGlob, avg / (count ? count : 1), bad.size());
}

// extruded meshes and boundary layer columns are not thread-safe either, so
// the entities carrying them are curved serially
template <class T> static int threadsFor(T *ge, int nthreads)
{
  if(nthreads <= 1) return 1;
  if(ge->meshAttributes.extrude &&
     ge->meshAttributes.extrude->mesh.ExtrudeMesh)
    return 1;
  return nthreads;
}

static int getOrder(GEntity *ge)
{
  for(std::size_t i = 0; i < ge->getNumMeshElements(); i++)
    return ge->getMeshElement(i)->getPolynomialOrder();
  return 0;
}

static void setHighOrderFromExistingMesh(GEdge *ge, edgeContainer &edgeVertices)
{
  for(std::size_t i = 0; i < ge->getNumMeshElements(); i++) {
    MElement *e = ge->getMeshElement(i);
    std::vector<MVertex *> v;
    e->getVertices(v);
    MVertex *vMin, *vMax;
    const bool increasing = getMinMaxVert(v[0], v[1], vMin, vMax);
    std::pair<MVertex *, MVertex *> p(vMin, vMax);
    const std::size_t sh = edgeVertices.shardOf(p);
    shardLock<edgeContainer> lock(edgeVertices, sh);
    edgeMap &em = edgeVertices.shard(sh);
    if(!em.find(p)) {
      if(increasing)
        em.insert(p, v.begin() + e->getNumPrimaryVertices(), v.end());
      else
        em.insert(p, v.rbegin(), v.rend() - e->getNumPrimaryVertices());
    }
  }
}

static void setHighOrderFromExistingMesh(GFace *gf, edgeContainer &edgeVertices,
                                         faceContainer &faceVertices)
{
  for(std::size_t i = 0; i < gf->getNumMeshElements(); i++) {
    MElement *e = gf->getMeshElement(i);
    for(int j = 0; j < e->getNumEdges(); j++) {
      MEdge edg = e->getEdge(j);
      MVertex *vMin, *vMax;
      const bool increasing =
        getMinMaxVert(edg.getVertex(0), edg.getVertex(1), vMin, vMax);
      std::pair<MVertex *, MVertex *> p(vMin, vMax);
      const std::size_t sh = edgeVertices.shardOf(p);
      shardLock<edgeContainer> lock(edgeVertices, sh);
      edgeMap &em = edgeVertices.shard(sh);
      if(!em.find(p)) {
        std::vector<MVertex *> edgv;
        e->getEdgeVertices(j, edgv);
        if(increasing)
          em.insert(p, edgv.begin() + 2, edgv.end());
        else
          em.insert(p, edgv.rbegin(), edgv.rend() - 2);
      }
    }
    MFace f = e->getFace(0);
    std::vector<MVertex *> facev;
    const std::size_t fsh = faceVertices.shardOf(f);
    shardLock<faceContainer> flock(faceVertices, fsh);
    faceMap &fm = faceVertices.shard(fsh);
    if(!fm.find(f)) {
      e->getFaceVertices(0, facev);
      fm.insert(f,
                facev.begin() + e->getNumPrimaryVertices() +
                  e->getNumEdgeVertices(),
                facev.end());
    }
  }
}

// Store the nodes created by SetOrderN in the entities they are classified on,
// entity by entity in the order of their first appearance in the elements, and
// number them and the new elements in that order: what
// pruneMeshVertexAssociations() followed by renumberMeshCanonically() do, but
// without sorting all the nodes, as the old ones stay where they are. Returns
// false (and does nothing) when the classification of a new node is not the
// one pruneMeshVertexAssociations() would give, i.e. the last entity of lowest
// dimension whose elements use it (e.g. between the surfaces of a compound)
static bool storeNewVertices(GModel *m, std::size_t maxVertexBefore,
                             std::size_t maxElementBefore)
{
  std::vector<GEntity *> entities;
  m->getEntities(entities);
  // the new nodes are told by their number, given by the model since
  // maxVertexBefore (unless the numbers are too sparse)
  std::size_t refs = 0;
  for(GEntity *ge : entities)
    if(ge->getNumMeshElements())
      refs += ge->getNumMeshElements() * ge->getMeshElement(0)->getNumVertices();
  const std::size_t maxNum = m->getMaxVertexNumber();
  if(maxNum < maxVertexBefore || maxNum - maxVertexBefore > 2 * refs + 1000000)
    return false;
  std::vector<char> stored(maxNum - maxVertexBefore, 0);
  std::vector<std::size_t> first(entities.size());
  for(std::size_t i = 0; i < entities.size(); i++)
    first[i] = entities[i]->mesh_vertices.size();
  const std::size_t firstV = std::max(1, CTX::instance()->mesh.firstNodeTag),
                    firstE = std::max(1, CTX::instance()->mesh.firstElementTag);
  std::size_t ne = std::max(maxElementBefore, firstE - 1);
  bool ok = true;
  // the entities come by increasing dimension: a new node is stored when met
  // in an element of its entity, and must have been stored already when met in
  // an element of an entity of higher dimension
  for(std::size_t i = 0; i < entities.size() && ok; i++) {
    GEntity *ge = entities[i];
    for(std::size_t j = 0; j < ge->getNumMeshElements() && ok; j++) {
      MElement *e = ge->getMeshElement(j);
      if(e->getNum() > maxElementBefore) e->forceNum(++ne);
      for(std::size_t k = 0; k < e->getNumVertices(); k++) {
        MVertex *v = e->getVertex(k);
        if(v->getNum() <= maxVertexBefore) continue;
        if(v->getNum() > maxNum) {
          ok = false;
          break;
        }
        char &s = stored[v->getNum() - maxVertexBefore - 1];
        if(v->onWhat() == ge) {
          if(!s) {
            s = 1;
            ge->mesh_vertices.push_back(v);
          }
        }
        else if(!s || ge->dim() <= v->onWhat()->dim()) {
          ok = false;
          break;
        }
      }
    }
  }
  if(!ok) { // renumberMeshCanonically() will number the elements again
    for(std::size_t i = 0; i < entities.size(); i++)
      entities[i]->mesh_vertices.resize(first[i]);
    return false;
  }
  m->destroyMeshCaches();
  // number the new nodes once all are stored, the test above being on the
  // numbers
  std::size_t nv = std::max(maxVertexBefore, firstV - 1);
  for(std::size_t i = 0; i < entities.size(); i++) {
    std::vector<MVertex *> &list = entities[i]->mesh_vertices;
    for(std::size_t j = first[i]; j < list.size(); j++) list[j]->forceNum(++nv);
  }
  m->resetMaxVertexNumber(nv);
  m->resetMaxElementNumber(ne);
  return true;
}

void SetOrderN(GModel *m, int order, bool linear, bool incomplete,
               bool onlyVisible)
{
  if(CTX::instance()->abortOnError && Msg::GetErrorCount()) return;

  // replace all the elements in the mesh with second order elements
  // by creating unique vertices on the edges/faces of the mesh:
  //
  // - if linear is set to true, new vertices are created by linear
  //   interpolation between existing ones. If not, new vertices are
  //   created on the exact geometry, provided that the geometrical
  //   edges/faces are discretized with 1D/2D elements. (I.e., if
  //   there are only 3D elements in the mesh then any new vertices on
  //   the boundary will always be created by linear interpolation,
  //   whether linear is set or not.)
  //
  // - if incomplete is set to true, we only create new vertices on
  //   edges (creating 8-node quads, 20-node hexas, etc., instead of
  //   9-node quads, 27-node hexas, etc.)

  // - if onlyVisible is true, then only the visible entities will be curved.

  int nPts = order - 1;

  char msg[256];
  sprintf(msg, "Meshing order %d (curvilinear %s)...", order,
          linear ? "off" : "on");

  Msg::StatusBar(true, msg);

  double t1 = Cpu(), w1 = TimeOfDay();

  m->destroyMeshCaches();

  // placing high-order nodes always provides an initial guess for the point
  // projections, and checks the result (see computeEquidistantParameters() and
  // getFaceVerticesOnGeo()), so we can use the fast local projection here even
  // though it is off by default for the rest of the code
  int oldFastProjection = CTX::instance()->geom.occFastProjection;
  CTX::instance()->geom.occFastProjection = 1;

  // Curving the elements of a surface or of a volume is done in parallel, on
  // General.NumThreads threads, or on Mesh.MaxNumThreads2D/3D if they are set -
  // as for the meshers. The containers below are shared, hence sharded (with
  // more shards than threads, so that two threads rarely want the same one at
  // the same time). A single thread means a single shard, i.e. no locking and
  // the exact serial behaviour, down to the node numbering.
  int nthreads2D = CTX::instance()->numThreads;
  if(CTX::instance()->mesh.maxNumThreads2D > 0)
    nthreads2D = CTX::instance()->mesh.maxNumThreads2D;
  if(!nthreads2D) nthreads2D = Msg::GetMaxThreads();
  int nthreads3D = CTX::instance()->numThreads;
  if(CTX::instance()->mesh.maxNumThreads3D > 0)
    nthreads3D = CTX::instance()->mesh.maxNumThreads3D;
  if(!nthreads3D) nthreads3D = Msg::GetMaxThreads();
  if(nthreads2D < 1) nthreads2D = 1;
  if(nthreads3D < 1) nthreads3D = 1;
  // boundary layers are not yet thread-safe
  if(m->getFields()->getNumBoundaryLayerFields()) {
    nthreads2D = 1;
    nthreads3D = 1;
  }
  const int nthreadsMax = std::max(nthreads2D, nthreads3D);
  const std::size_t nShards = (nthreadsMax > 1) ? 16 * nthreadsMax : 1;

  // the nodes created below are numbered as the threads create them: they
  // are renumbered canonically at the end, after the ones existing now
  std::size_t maxVertexBefore, maxElementBefore;
  m->getMaxMeshNumbersInUse(maxVertexBefore, maxElementBefore);

  // Keep track of vertex/entities created
  edgeContainer edgeVertices(nShards);
  faceContainer faceVertices(nShards);

  int counter = 0;
  int nTot = m->getNumEdges() + m->getNumFaces() + m->getNumRegions();
  Msg::StartProgressMeter(nTot);

  // TODO: we can leak nodes of discrete entities with existing high-order
  // nodes, if we ask a mesh with a different order

  // high-order nodes of another order are dropped by the elements replaced
  // below, and must be dropped by their entities too
  bool otherOrder = false;
  {
    std::vector<GEntity *> entities;
    m->getEntities(entities);
    for(GEntity *ge : entities) {
      const int o = getOrder(ge);
      if(o > 1 && o != order) otherOrder = true;
    }
  }

  for(auto it = m->firstEdge(); it != m->lastEdge(); ++it) {
    Msg::Info("Meshing curve %d order %d", (*it)->tag(), order);
    Msg::ProgressMeter(++counter, false, msg);
    if(onlyVisible && !(*it)->getVisibility()) continue;
    if(getOrder(*it) != order)
      setHighOrder(*it, edgeVertices, linear, nPts);
    else
      setHighOrderFromExistingMesh(*it, edgeVertices);
  }

  for(auto it = m->firstFace(); it != m->lastFace(); ++it) {
    Msg::Info("Meshing surface %d order %d", (*it)->tag(), order);
    Msg::ProgressMeter(++counter, false, msg);
    if(onlyVisible && !(*it)->getVisibility()) continue;
    if(getOrder(*it) != order)
      setHighOrder(*it, edgeVertices, faceVertices, linear, incomplete, nPts,
                   threadsFor(*it, nthreads2D));
    else
      setHighOrderFromExistingMesh(*it, edgeVertices, faceVertices);
    if((*it)->getColumns() != nullptr) (*it)->getColumns()->clearElementData();
  }

  for(auto it = m->firstRegion(); it != m->lastRegion(); ++it) {
    Msg::Info("Meshing volume %d order %d", (*it)->tag(), order);
    Msg::ProgressMeter(++counter, false, msg);
    if(onlyVisible && !(*it)->getVisibility()) continue;
    if(getOrder(*it) != order)
      setHighOrder(*it, edgeVertices, faceVertices, incomplete, nPts,
                   threadsFor(*it, nthreads3D));
    if((*it)->getColumns() != nullptr) (*it)->getColumns()->clearElementData();
  }

  CTX::instance()->geom.occFastProjection = oldFastProjection;

  // store nodes in entities
  if(otherOrder ||
     !storeNewVertices(m, maxVertexBefore, maxElementBefore)) {
    m->pruneMeshVertexAssociations();
    m->renumberMeshCanonically(maxVertexBefore, maxElementBefore);
  }

  Msg::StopProgressMeter();
  double t2 = Cpu(), w2 = TimeOfDay();

  if(!linear && !CTX::instance()->mesh.hoSkipQualityCheck) {
    std::vector<MElement *> bad;
    double worst;
    checkHighOrderTriangles("Surface mesh", m, bad, worst);
    checkHighOrderTetrahedron("Volume mesh", m, bad, worst);
  }

  Msg::StatusBar(true, "Done meshing order %d (Wall %gs, CPU %gs)", order,
                 w2 - w1, t2 - t1);
}
