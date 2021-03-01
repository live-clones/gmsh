// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESH_GREGION_DELAUNAY_INSERTION_H
#define MESH_GREGION_DELAUNAY_INSERTION_H

#include <list>
#include <set>
#include <map>
#include <stack>
#include "MTetrahedron.h"
#include "Numeric.h"
#include "BackgroundMeshTools.h"
#include "qualityMeasures.h"
#include "robustPredicates.h"

//#define GMSH_PRE_ALLOCATE_STRATEGY 1
class GRegion;
class GFace;
class GModel;
class splitQuadRecovery;

double tetcircumcenter(double a[3], double b[3], double c[3], double d[3],
                       double circumcenter[3], double *xi, double *eta,
                       double *zeta);

class MTet4Factory;

// Memory usage for 1 million tets:
//
// * sizeof(MTet4) = 36 Bytes and sizeof(MTetrahedron) = 28 Bytes
//   -> 64 MB
// * rb tree containing all pointers sorted with respect to tet
//   radius: each bucket of the tree contains 4 pointers (16 Bytes)
//   plus the data -> 20 MB
// * sizeof(MVertex) = 44 Bytes and there are about 200000 verts per
//   million tet -> 9MB
// * vector of char lengths per vertex -> 1.6Mb
// * vectors in GEntities to store the element and vertex pointers
//   -> 5Mb
//
// Grand total should thus be about 100 MB.
//
// The observed mem usage with "demos/cube.geo -clscale 0.61" is
// 157MB. Where do the extra 57 MB come from?
//
// * surface mesh + all other overheads (model, etc.) is 19Mb
// * tetgen initial mesh is about 20Mb, but it is deleted before mesh
//   refinement.
// * ?

class MTet4 {
  friend class MTet4Factory;

private:
  bool deleted;
  double circum_radius;
  MTetrahedron *base;
  MTet4 *neigh[4];
  GRegion *gr;

public:
  static int radiusNorm; // 2 is euclidian norm, -1 is infinite norm
  ~MTet4() {}
  MTet4() : deleted(false), circum_radius(0.0), base(nullptr), gr(nullptr)
  {
    neigh[0] = neigh[1] = neigh[2] = neigh[3] = nullptr;
  }
  MTet4(MTetrahedron *t, double qual)
    : deleted(false), circum_radius(qual), base(t), gr(nullptr)
  {
    neigh[0] = neigh[1] = neigh[2] = neigh[3] = nullptr;
  }
  MTet4(MTetrahedron *t, const qmTetrahedron::Measures &qm)
    : deleted(false), base(t), gr(nullptr)
  {
    neigh[0] = neigh[1] = neigh[2] = neigh[3] = nullptr;
    double vol;
    circum_radius = qmTetrahedron::qm(t, qm, &vol);
  }
  void circumcenter(double *res)
  {
    MVertex *v0 = base->getVertex(0);
    MVertex *v1 = base->getVertex(1);
    MVertex *v2 = base->getVertex(2);
    MVertex *v3 = base->getVertex(3);
    double A[4] = {v0->x(), v0->y(), v0->z()};
    double B[4] = {v1->x(), v1->y(), v1->z()};
    double C[4] = {v2->x(), v2->y(), v2->z()};
    double D[4] = {v3->x(), v3->y(), v3->z()};
    tetcircumcenter(A, B, C, D, res, nullptr, nullptr, nullptr);
  }

  void setup(MTetrahedron *t, std::vector<double> &sizes,
             std::vector<double> &sizesBGM)
  {
    base = t;
    neigh[0] = neigh[1] = neigh[2] = neigh[3] = nullptr;
    double center[3];
    circumcenter(center);
    const double dx = base->getVertex(0)->x() - center[0];
    const double dy = base->getVertex(0)->y() - center[1];
    const double dz = base->getVertex(0)->z() - center[2];
    circum_radius = std::sqrt(dx * dx + dy * dy + dz * dz);
    /*
    if (base->getVertex(0)->getIndex() >= sizes.size() ||
    base->getVertex(1)->getIndex() >= sizes.size() ||
    base->getVertex(2)->getIndex() >= sizes.size() ||
    base->getVertex(3)->getIndex() >= sizes.size()){
      printf("ERROR %d vs %d %d %d %d\n",sizes.size() ,
         base->getVertex(0)->getIndex(),
         base->getVertex(1)->getIndex(),
         base->getVertex(2)->getIndex(),
         base->getVertex(3)->getIndex());

    }
    */
    double lc1 = 0.25 * (sizes[base->getVertex(0)->getIndex()] +
                         sizes[base->getVertex(1)->getIndex()] +
                         sizes[base->getVertex(2)->getIndex()] +
                         sizes[base->getVertex(3)->getIndex()]);
    double lcBGM = 0.25 * (sizesBGM[base->getVertex(0)->getIndex()] +
                           sizesBGM[base->getVertex(1)->getIndex()] +
                           sizesBGM[base->getVertex(2)->getIndex()] +
                           sizesBGM[base->getVertex(3)->getIndex()]);
    double lc = Extend2dMeshIn3dVolumes() ? std::min(lc1, lcBGM) : lcBGM;
    circum_radius /= lc;
    deleted = false;
  }

  void setup(MTetrahedron *t, std::vector<double> &sizes,
             std::vector<double> &sizesBGM, double lcA, double lcB)
  {
    base = t;
    neigh[0] = neigh[1] = neigh[2] = neigh[3] = nullptr;
    double center[3];
    circumcenter(center);
    const double dx = base->getVertex(0)->x() - center[0];
    const double dy = base->getVertex(0)->y() - center[1];
    const double dz = base->getVertex(0)->z() - center[2];
    circum_radius = std::sqrt(dx * dx + dy * dy + dz * dz);

    /*
    if (base->getVertex(0)->getIndex() >= sizes.size() ||
    base->getVertex(1)->getIndex() >= sizes.size() ||
    base->getVertex(2)->getIndex() >= sizes.size()){
      printf("ERROR %d vs %d %d %d %d\n",sizes.size() ,
         base->getVertex(0)->getIndex(),
         base->getVertex(1)->getIndex(),
         base->getVertex(2)->getIndex(),
         base->getVertex(3)->getIndex());

    }
    */
    double lc1 = 0.25 * (sizes[base->getVertex(0)->getIndex()] +
                         sizes[base->getVertex(1)->getIndex()] +
                         sizes[base->getVertex(2)->getIndex()] + lcA);
    double lcBGM = 0.25 * (sizesBGM[base->getVertex(0)->getIndex()] +
                           sizesBGM[base->getVertex(1)->getIndex()] +
                           sizesBGM[base->getVertex(2)->getIndex()] + lcB);
    double lc = Extend2dMeshIn3dVolumes() ? std::min(lc1, lcBGM) : lcBGM;
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

void connectTets(std::list<MTet4 *> &,
                 const std::set<MFace, MFaceLessThan> * = nullptr);
void connectTets(std::vector<MTet4 *> &,
                 const std::set<MFace, MFaceLessThan> * = nullptr);
void delaunayMeshIn3D(std::vector<MVertex *> &, std::vector<MTetrahedron *> &,
                      bool removeBox = false);
void insertVerticesInRegion(GRegion *gr, int maxIter,
                            double worstTetRadiusTarget, bool _classify = true,
                            splitQuadRecovery *sqr = nullptr);
void bowyerWatsonFrontalLayers(GRegion *gr, bool hex);

struct compareTet4Ptr {
  bool operator()(MTet4 const *const a, MTet4 const *const b) const
  {
    if(a->getRadius() > b->getRadius()) return true;
    if(a->getRadius() < b->getRadius()) return false;
    return a->tet()->getNum() < b->tet()->getNum();
  }
};

class MTet4Factory {
public:
  typedef std::set<MTet4 *, compareTet4Ptr> container;
  typedef container::iterator iterator;

private:
  container allTets;
#ifdef GMSH_PRE_ALLOCATE_STRATEGY
  MTet4 *allSlots;
  int s_last, s_alloc;
  std::stack<MTet4 *> emptySlots;
  inline MTet4 *getANewSlot()
  {
    if(s_last >= s_alloc) return 0;
    MTet4 *t = &(allSlots[s_last]);
    s_last++;
    return t;
  }
  inline MTet4 *getAnEmptySlot()
  {
    if(!emptySlots.empty()) {
      MTet4 *t = emptySlots.top();
      emptySlots.pop();
      return t;
    }
    return getANewSlot();
  };
#endif
public:
  MTet4Factory(int _size = 1000000)
  {
#ifdef GMSH_PRE_ALLOCATE_STRATEGY
    s_last = 0;
    s_alloc = _size;
    allSlots = new MTet4[s_alloc];
#endif
  }
  ~MTet4Factory()
  {
#ifdef GMSH_PRE_ALLOCATE_STRATEGY
    delete[] allSlots;
#endif
  }
  MTet4 *Create(MTetrahedron *t, std::vector<double> &sizes,
                std::vector<double> &sizesBGM)
  {
#ifdef GMSH_PRE_ALLOCATE_STRATEGY
    MTet4 *t4 = getAnEmptySlot();
#else
    MTet4 *t4 = new MTet4;
#endif
    t4->setup(t, sizes, sizesBGM);
    return t4;
  }
  MTet4 *Create(MTetrahedron *t, std::vector<double> &sizes,
                std::vector<double> &sizesBGM, double lc1, double lc2)
  {
#ifdef GMSH_PRE_ALLOCATE_STRATEGY
    MTet4 *t4 = getAnEmptySlot();
#else
    MTet4 *t4 = new MTet4;
#endif
    t4->setup(t, sizes, sizesBGM, lc1, lc2);
    return t4;
  }

  void Free(MTet4 *t)
  {
    if(t->tet()) delete t->tet();
    t->tet() = nullptr;
#ifdef GMSH_PRE_ALLOCATE_STRATEGY
    emptySlots.push(t);
    t->setDeleted(true);
#else
    delete t;
#endif
  }
  void changeTetRadius(iterator it, double r)
  {
    MTet4 *t = *it;
    allTets.erase(it);
    t->forceRadius(r);
    allTets.insert(t);
  }
  container &getAllTets() { return allTets; }
};

void optimizeMesh(GRegion *gr, const qmTetrahedron::Measures &qm);

#endif
