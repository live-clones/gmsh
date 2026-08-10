// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESH_GREGION_TET4_H
#define MESH_GREGION_TET4_H

// The tetrahedron wrapper the object-based 3D kernels work on, its
// allocator, and the routines that build the adjacencies of a set of such
// tetrahedra. This is internal to the 3D meshing sources: the entry points
// the rest of Gmsh calls are in meshGRegionDelaunay.h.

#include <cstdint>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <vector>
#include "MTetrahedron.h"
#include "MFace.h"
#include "Numeric.h"
#include "BackgroundMeshTools.h"
#include "qualityMeasures.h"
#include "robustPredicates.h"
#include "meshGRegionDelaunay.h"
#include "GModel.h"

class GRegion;
class GFace;
class GModel;
class MTet4Factory;

// local face numbering of a tetrahedron: face k is made of the vertices
// tet4Faces[k][0..2] (the face routines below sort them, so only the set
// matters, not the orientation)
static const int tet4Faces[4][3] = {{0, 1, 2}, {0, 2, 3}, {0, 3, 1}, {1, 3, 2}};

// same as tetcircumcenter (with bit-identical result), but also returns a
// conservative bound on the roundoff error of the computed circumcenter
double tetcircumcenterBounded(double a[3], double b[3], double c[3],
                              double d[3], double circumcenter[3],
                              double *err);

class MTet4 {
  friend class MTet4Factory;


private:
  bool deleted;
  // sign of orient3d on the vertices in storage order, cached by setup();
  // 0 means unknown, in which case inCircumSphere computes it on the fly
  signed char orientSgn;
  double circum_radius;
  // circumcenter, squared circumradius and roundoff bound cached by setup(),
  // so that most in-sphere tests are a simple distance comparison; sphTol is
  // set to 1e300 when the cache cannot be trusted and the exact predicates
  // must always be used
  double cc[3], r2, sphTol;
  MTetrahedron *base;
  MTet4 *neigh[4];
  GRegion *gr;

public:
  ~MTet4() {}
  MTet4()
    : deleted(false), orientSgn(0), circum_radius(0.0), sphTol(1.e300),
      base(nullptr), gr(nullptr)
  {
    neigh[0] = neigh[1] = neigh[2] = neigh[3] = nullptr;
  }
  MTet4(MTetrahedron *t, double qual)
    : deleted(false), orientSgn(0), circum_radius(qual), sphTol(1.e300),
      base(t), gr(nullptr)
  {
    neigh[0] = neigh[1] = neigh[2] = neigh[3] = nullptr;
  }
  MTet4(MTetrahedron *t, const qmTetrahedron::Measures &qm)
    : deleted(false), orientSgn(0), sphTol(1.e300), base(t), gr(nullptr)
  {
    neigh[0] = neigh[1] = neigh[2] = neigh[3] = nullptr;
    double vol;
    circum_radius = qmTetrahedron::qm(t, qm, &vol);
  }
  // returns orient3d on vertices (1, 2, 3, 0), i.e. minus the orientation of
  // the tet
  double circumcenter(double *res)
  {
    MVertex *v0 = base->getVertex(0);
    MVertex *v1 = base->getVertex(1);
    MVertex *v2 = base->getVertex(2);
    MVertex *v3 = base->getVertex(3);
    double A[4] = {v0->x(), v0->y(), v0->z()};
    double B[4] = {v1->x(), v1->y(), v1->z()};
    double C[4] = {v2->x(), v2->y(), v2->z()};
    double D[4] = {v3->x(), v3->y(), v3->z()};
    return tetcircumcenter(A, B, C, D, res, nullptr, nullptr, nullptr);
  }
  double circumcenterBounded(double *res, double *err)
  {
    MVertex *v0 = base->getVertex(0);
    MVertex *v1 = base->getVertex(1);
    MVertex *v2 = base->getVertex(2);
    MVertex *v3 = base->getVertex(3);
    double A[4] = {v0->x(), v0->y(), v0->z()};
    double B[4] = {v1->x(), v1->y(), v1->z()};
    double C[4] = {v2->x(), v2->y(), v2->z()};
    double D[4] = {v3->x(), v3->y(), v3->z()};
    return tetcircumcenterBounded(A, B, C, D, res, err);
  }
  // circumcenter cached by setup()
  void cachedCircumcenter(double *res) const
  {
    res[0] = cc[0];
    res[1] = cc[1];
    res[2] = cc[2];
  }
  double cachedR2() const { return r2; }
  double cachedSphTol() const { return sphTol; }
  int cachedOrientSgn() const { return orientSgn; }

  void setupGeom()
  {
    double cerr;
    const double o = circumcenterBounded(cc, &cerr);
    orientSgn = (o > 0) ? -1 : (o < 0) ? 1 : 0;
    const double dx = base->getVertex(0)->x() - cc[0];
    const double dy = base->getVertex(0)->y() - cc[1];
    const double dz = base->getVertex(0)->z() - cc[2];
    r2 = dx * dx + dy * dy + dz * dz;
    circum_radius = std::sqrt(r2);
    // 3 covers the sqrt(2) slack of bounding 2*cerr*(d+r) by
    // sphTol*sqrt(d^2+r^2) in inCircumSphere
    sphTol = orientSgn ? 3. * cerr : 1.e300;
  }

  void setup(MTetrahedron *t, std::vector<double> &sizes,
             std::vector<double> &sizesBGM, bool extend)
  {
    base = t;
    gr = nullptr;
    neigh[0] = neigh[1] = neigh[2] = neigh[3] = nullptr;
    setupGeom();
    double lc1 = 0.25 * (sizes[base->getVertex(0)->getIndex()] +
                         sizes[base->getVertex(1)->getIndex()] +
                         sizes[base->getVertex(2)->getIndex()] +
                         sizes[base->getVertex(3)->getIndex()]);
    double lcBGM = 0.25 * (sizesBGM[base->getVertex(0)->getIndex()] +
                           sizesBGM[base->getVertex(1)->getIndex()] +
                           sizesBGM[base->getVertex(2)->getIndex()] +
                           sizesBGM[base->getVertex(3)->getIndex()]);
    double lc = extend ? std::min(lc1, lcBGM) : lcBGM;
    circum_radius /= lc;
    deleted = false;
  }

  void setup(MTetrahedron *t, std::vector<double> &sizes,
             std::vector<double> &sizesBGM, double lcA, double lcB, bool extend)
  {
    base = t;
    gr = nullptr;
    neigh[0] = neigh[1] = neigh[2] = neigh[3] = nullptr;
    setupGeom();
    double lc1 = 0.25 * (sizes[base->getVertex(0)->getIndex()] +
                         sizes[base->getVertex(1)->getIndex()] +
                         sizes[base->getVertex(2)->getIndex()] + lcA);
    double lcBGM = 0.25 * (sizesBGM[base->getVertex(0)->getIndex()] +
                           sizesBGM[base->getVertex(1)->getIndex()] +
                           sizesBGM[base->getVertex(2)->getIndex()] + lcB);
    double lc = extend ? std::min(lc1, lcBGM) : lcBGM;
    circum_radius /= lc;
    deleted = false;
  }

  GRegion *onWhat() const { return gr; }
  void setOnWhat(GRegion *g) { gr = g; }
  bool isDeleted() const { return deleted; }
  void forceRadius(double r) { circum_radius = r; }
  double getRadius() const { return circum_radius; }
  double getQuality() const { return circum_radius; }
  void setQuality(const double &q) { circum_radius = q; }
  MTetrahedron *tet() const { return base; }
  MTetrahedron *&tet() { return base; }
  void setTet(MTetrahedron *t) { base = t; }
  void setNeigh(int iN, MTet4 *n) { neigh[iN] = n; }
  MTet4 *getNeigh(int iN) const { return neigh[iN]; }
  int inCircumSphere(const double *p) const;
  int inCircumSphere(double x, double y, double z) const
  {
    const double p[3] = {x, y, z};
    return inCircumSphere(p);
  }
  int inCircumSphere(const MVertex *v) const
  {
    return inCircumSphere(v->x(), v->y(), v->z());
  }
  double getVolume() const
  {
    double pa[3] = {base->getVertex(0)->x(), base->getVertex(0)->y(),
                    base->getVertex(0)->z()};
    double pb[3] = {base->getVertex(1)->x(), base->getVertex(1)->y(),
                    base->getVertex(1)->z()};
    double pc[3] = {base->getVertex(2)->x(), base->getVertex(2)->y(),
                    base->getVertex(2)->z()};
    double pd[3] = {base->getVertex(3)->x(), base->getVertex(3)->y(),
                    base->getVertex(3)->z()};
    return std::abs(robustPredicates::orient3d(pa, pb, pc, pd)) / 6.0;
  }
  void setDeleted(bool const d) { deleted = d; }
  bool assertNeigh() const
  {
    if(deleted) return true;
    for(int i = 0; i < 4; i++)
      if(neigh[i] && (neigh[i]->isNeigh(this) == false)) return false;
    return true;
  }
  inline bool isNeigh(const MTet4 *t) const
  {
    for(int i = 0; i < 4; i++)
      if(neigh[i] == t) return true;
    return false;
  }
};

struct compareTet4Ptr {
  bool operator()(MTet4 const *const a, MTet4 const *const b) const
  {
    if(a->getRadius() > b->getRadius()) return true;
    if(a->getRadius() < b->getRadius()) return false;
    return a->tet()->getNum() < b->tet()->getNum();
  }
};

// Creates and recycles the MTet4 and MTetrahedron objects of the Delaunay
// refinement: freed objects are kept in free lists and handed out again,
// which avoids the constant allocator churn of cavity remeshing. Recycled
// MTetrahedra get a fresh element number, so the numbering is the same as
// with plain new/delete.
class MTet4Factory {
private:
  bool extend;
  std::vector<MTet4 *> freeTet4;
  std::vector<MTetrahedron *> freeTet;

public:
  MTet4Factory();
  ~MTet4Factory()
  {
    for(auto t : freeTet) delete t;
    for(auto t : freeTet4) delete t;
  }
  MTetrahedron *createTet(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3);
  MTet4 *Create(MTetrahedron *t, std::vector<double> &sizes,
                std::vector<double> &sizesBGM)
  {
    MTet4 *t4;
    if(!freeTet4.empty()) {
      t4 = freeTet4.back();
      freeTet4.pop_back();
    }
    else
      t4 = new MTet4;
    t4->setup(t, sizes, sizesBGM, extend);
    return t4;
  }
  MTet4 *Create(MTetrahedron *t, std::vector<double> &sizes,
                std::vector<double> &sizesBGM, double lc1, double lc2)
  {
    MTet4 *t4;
    if(!freeTet4.empty()) {
      t4 = freeTet4.back();
      freeTet4.pop_back();
    }
    else
      t4 = new MTet4;
    t4->setup(t, sizes, sizesBGM, lc1, lc2, extend);
    return t4;
  }
  void Free(MTet4 *t)
  {
    if(t->tet()) freeTet.push_back(t->tet());
    t->tet() = nullptr;
    freeTet4.push_back(t);
  }
};

void optimizeMesh(GRegion *gr, const qmTetrahedron::Measures &qm);


// Connect the tets by matching their faces, keyed on the sorted vertex
// numbers of each face so that nothing chases the vertex pointers twice.
// The faces are bucketed on their smallest vertex with a counting sort,
// which is linear and writes each face once, and only the (small) buckets
// are sorted, on the two remaining vertices: a pair of matching faces is
// then always adjacent inside one bucket. KEY is the smallest unsigned
// integer type that can hold the vertex numbers.
template <class KEY, class ITER>
void connectTetsFastT(ITER beg, ITER end)
{
  struct tetFace {
    KEY v1, v2; // the two largest vertices of the face
    KEY tet; // index of the tet in [beg, end)
    KEY i; // face of that tet
    bool operator<(const tetFace &o) const
    {
      if(v1 != o.v1) return v1 < o.v1;
      return v2 < o.v2;
    }
  };

  // the smallest vertex of a face, which is what it is bucketed on
  auto minVertex = [](const KEY n[4], int j) {
    KEY a = n[tet4Faces[j][0]];
    a = std::min(a, n[tet4Faces[j][1]]);
    return std::min(a, n[tet4Faces[j][2]]);
  };
  auto tetNums = [](MTet4 *t, KEY n[4]) {
    for(int k = 0; k < 4; k++) n[k] = (KEY)t->tet()->getVertex(k)->getNum();
  };

  // count the faces of each bucket
  std::vector<KEY> start(
    (std::size_t)GModel::current()->getMaxVertexNumber() + 2, 0);
  for(ITER IT = beg; IT != end; ++IT) {
    if((*IT)->isDeleted()) continue;
    KEY n[4];
    tetNums(*IT, n);
    for(int j = 0; j < 4; j++) start[minVertex(n, j) + 1]++;
  }
  for(std::size_t v = 1; v < start.size(); v++) start[v] += start[v - 1];
  const std::size_t nFaces = start.back();
  if(!nFaces) return;

  // scatter the faces into their bucket
  std::vector<tetFace> sorted(nFaces);
  {
    std::vector<KEY> cursor(start.begin(), start.end() - 1);
    KEY idx = 0;
    for(ITER IT = beg; IT != end; ++IT, ++idx) {
      if((*IT)->isDeleted()) continue;
      KEY n[4];
      tetNums(*IT, n);
      for(int j = 0; j < 4; j++) {
        KEY a = n[tet4Faces[j][0]], b = n[tet4Faces[j][1]], c = n[tet4Faces[j][2]];
        if(a > b) std::swap(a, b);
        if(b > c) std::swap(b, c);
        if(a > b) std::swap(a, b);
        tetFace &f = sorted[cursor[a]++];
        f.v1 = b;
        f.v2 = c;
        f.tet = idx;
        f.i = (KEY)j;
      }
    }
  }

  // inside a bucket, matching faces end up next to each other
  for(std::size_t v = 0; v + 1 < start.size(); v++) {
    const std::size_t b = start[v], e = start[v + 1];
    if(e - b < 2) continue;
    std::sort(sorted.begin() + b, sorted.begin() + e);
    for(std::size_t k = b; k + 1 < e; k++) {
      const tetFace &f1 = sorted[k];
      const tetFace &f2 = sorted[k + 1];
      if(f1.v1 == f2.v1 && f1.v2 == f2.v2) {
        MTet4 *t1 = *(beg + f1.tet);
        MTet4 *t2 = *(beg + f2.tet);
        if(t1 != t2) {
          t1->setNeigh(f1.i, t2);
          t2->setNeigh(f2.i, t1);
          ++k;
        }
      }
    }
  }
}

template <class ITER>
void connectTetsFast(ITER beg, ITER end)
{
  if(GModel::current()->getMaxVertexNumber() <= 0xffffffffull)
    connectTetsFastT<std::uint32_t>(beg, end);
  else
    connectTetsFastT<std::size_t>(beg, end);
}

// connect the tets of a range by matching their faces on the sorted vertex
// numbers: the faces are collected in one array and sorted, which brings the
// two copies of a face next to each other. The local mesh modifications call
// this on the few tets around a cavity, so the array stays small; a std::set
// of faces would allocate a node per face and chase the vertex pointers at
// every comparison.
template <class ITER>
void connectTets(
  ITER beg, ITER end,
  const std::set<MFace, MFaceLessThan> *allEmbeddedFaces = nullptr)
{
  struct tetFace {
    std::size_t v0, v1, v2;
    MTet4 *t;
    int i;
    bool operator<(const tetFace &o) const
    {
      if(v0 != o.v0) return v0 < o.v0;
      if(v1 != o.v1) return v1 < o.v1;
      return v2 < o.v2;
    }
  };
  const bool hasEmbedded = allEmbeddedFaces && !allEmbeddedFaces->empty();

  std::vector<tetFace> conn;
  for(ITER IT = beg; IT != end; ++IT) {
    MTet4 *t = *IT;
    if(t->isDeleted()) continue;
    for(int j = 0; j < 4; j++) {
      std::size_t a = t->tet()->getVertex(tet4Faces[j][0])->getNum();
      std::size_t b = t->tet()->getVertex(tet4Faces[j][1])->getNum();
      std::size_t c = t->tet()->getVertex(tet4Faces[j][2])->getNum();
      if(a > b) std::swap(a, b);
      if(b > c) std::swap(b, c);
      if(a > b) std::swap(a, b);
      conn.push_back({a, b, c, t, j});
    }
  }
  std::sort(conn.begin(), conn.end());

  for(std::size_t k = 0; k + 1 < conn.size(); k++) {
    const tetFace &f1 = conn[k];
    const tetFace &f2 = conn[k + 1];
    if(f1.v0 != f2.v0 || f1.v1 != f2.v1 || f1.v2 != f2.v2) continue;
    if(f1.t != f2.t) {
      // if a face is embedded, do not connect tets on both sides!
      if(hasEmbedded &&
         allEmbeddedFaces->find(MFace(f1.t->tet()->getVertex(tet4Faces[f1.i][0]),
                                      f1.t->tet()->getVertex(tet4Faces[f1.i][1]),
                                      f1.t->tet()->getVertex(tet4Faces[f1.i][2]))) !=
           allEmbeddedFaces->end())
        continue;
      f1.t->setNeigh(f1.i, f2.t);
      f2.t->setNeigh(f2.i, f1.t);
    }
    k++;
  }
}


// connect the tets of a range by matching their faces; the faces of a set
// that is embedded in the region are never connected, so that they stay
// boundaries of the mesh
void connectTets(std::list<MTet4 *> &,
                 const std::set<MFace, MFaceLessThan> * = nullptr);
void connectTets(std::vector<MTet4 *> &,
                 const std::set<MFace, MFaceLessThan> * = nullptr);

// the faces and edges meshed on the entities embedded in a region
void createAllEmbeddedFaces(GRegion *gr,
                            std::set<MFace, MFaceLessThan> &allEmbeddedFaces);
void createAllEmbeddedEdges(GRegion *gr,
                            std::set<MEdge, MEdgeLessThan> &allEmbeddedEdges);

#endif
