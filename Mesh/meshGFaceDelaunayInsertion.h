// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESH_GFACE_DELAUNAY_INSERTIONFACE_H
#define MESH_GFACE_DELAUNAY_INSERTIONFACE_H

#include "MTriangle.h"
#include "MQuadrangle.h"
#include "STensor3.h"
#include "GEntity.h"
#include "MFace.h"
#include <list>
#include <set>
#include <map>

class GModel;
class GFace;
class BDS_Mesh;
class BDS_Point;

struct bidimMeshData {
  std::map<MVertex *, int> indices;
  std::vector<double> Us, Vs, vSizes, vSizesBGM;
  std::vector<SMetric3> vMetricsBGM;
  std::map<MVertex *, MVertex *> *equivalence;
  std::map<MVertex *, SPoint2> *parametricCoordinates;
  std::set<MEdge, MEdgeLessThan> internalEdges; // embedded edges
  //  std::set<MVertex*> internalVertices; // embedded vertices
  inline void addVertex(MVertex *mv, double u, double v, double size,
                        double sizeBGM)
  {
    int index = Us.size();
    if(mv->onWhat()->dim() == 2)
      mv->setIndex(index);
    else
      indices[mv] = index;
    if(parametricCoordinates) {
      auto it = parametricCoordinates->find(mv);
      if(it != parametricCoordinates->end()) {
        u = it->second.x();
        v = it->second.y();
      }
    }
    Us.push_back(u);
    Vs.push_back(v);
    vSizes.push_back(size);
    vSizesBGM.push_back(sizeBGM);
  }
  inline int getIndex(MVertex *mv)
  {
    if(mv->onWhat()->dim() == 2) return mv->getIndex();
    return indices[mv];
  }
  inline MVertex *equivalent(MVertex *v1) const
  {
    if(equivalence) {
      auto it = equivalence->find(v1);
      if(it == equivalence->end()) return nullptr;
      return it->second;
    }
    return nullptr;
  }
  bidimMeshData(std::map<MVertex *, MVertex *> *e = nullptr,
                std::map<MVertex *, SPoint2> *p = nullptr)
    : equivalence(e), parametricCoordinates(p)
  {
  }
};

void buildMetric(GFace *gf, double *uv, double *metric);
int inCircumCircleAniso(GFace *gf, double *p1, double *p2, double *p3,
                        double *p4, double *metric);
int inCircumCircleAniso(GFace *gf, MTriangle *base, const double *uv,
                        const double *metric, bidimMeshData &data);

class MTri3 {
protected:
  bool deleted;
  double circum_radius;
  MTriangle *base;
  MTri3 *neigh[3];

public:
  /// 2 is euclidian norm, -1 is infinite norm  , 3 quality
  static int radiusNorm;
  bool isDeleted() const { return deleted; }
  void forceRadius(double r) { circum_radius = r; }
  inline double getRadius() const { return circum_radius; }
  inline MVertex *otherSide(int i)
  {
    MTri3 *n = neigh[i];
    if(!n) return nullptr;
    MVertex *v1 = base->getVertex((i + 2) % 3);
    MVertex *v2 = base->getVertex(i);
    for(int j = 0; j < 3; j++)
      if(n->tri()->getVertex(j) != v1 && n->tri()->getVertex(j) != v2)
        return n->tri()->getVertex(j);
    return nullptr;
  }
  MTri3(MTriangle *t, double lc, SMetric3 *m = nullptr,
        bidimMeshData *data = nullptr, GFace *gf = nullptr);
  inline void setTri(MTriangle *t) { base = t; }
  inline MTriangle *tri() const { return base; }
  inline void setNeigh(int iN, MTri3 *n) { neigh[iN] = n; }
  inline MTri3 *getNeigh(int iN) const { return neigh[iN]; }
  int inCircumCircle(const double *p) const;
  inline int inCircumCircle(double x, double y) const
  {
    const double p[2] = {x, y};
    return inCircumCircle(p);
  }
  inline int inCircumCircle(const MVertex *v) const
  {
    return inCircumCircle(v->x(), v->y());
  }
  inline void setDeleted(bool d) { deleted = d; }
  inline bool assertNeigh() const
  {
    if(deleted) return true;
    for(int i = 0; i < 3; i++)
      if(neigh[i] && (neigh[i]->isNeigh(this) == false)) return false;
    return true;
  }
  inline bool isNeigh(const MTri3 *t) const
  {
    for(int i = 0; i < 3; i++)
      if(neigh[i] == t) return true;
    return false;
  }
};

class compareTri3Ptr {
  MFaceLessThan lf;

public:
  inline bool operator()(const MTri3 *a, const MTri3 *b) const
  {
    if(a->getRadius() > b->getRadius()) return true;
    if(a->getRadius() < b->getRadius()) return false;
    return lf(a->tri()->getFace(0), b->tri()->getFace(0));
  }
};

void connectTriangles(std::list<MTri3 *> &);
void connectTriangles(std::vector<MTri3 *> &);
void connectTriangles(std::set<MTri3 *, compareTri3Ptr> &AllTris);
void bowyerWatson(
  GFace *gf, int MAXPNT = 1000000000,
  std::map<MVertex *, MVertex *> *equivalence = nullptr,
  std::map<MVertex *, SPoint2> *parametricCoordinates = nullptr);
void bowyerWatsonFrontal(
  GFace *gf, std::map<MVertex *, MVertex *> *equivalence = nullptr,
  std::map<MVertex *, SPoint2> *parametricCoordinates = nullptr,
  std::vector<SPoint2> *true_boundary = nullptr);
void bowyerWatsonFrontalLayers(
  GFace *gf, bool quad, std::map<MVertex *, MVertex *> *equivalence = nullptr,
  std::map<MVertex *, SPoint2> *parametricCoordinates = nullptr);
void bowyerWatsonParallelograms(
  GFace *gf, std::map<MVertex *, MVertex *> *equivalence = nullptr,
  std::map<MVertex *, SPoint2> *parametricCoordinates = nullptr);
void bowyerWatsonParallelogramsConstrained(
  GFace *gf, const std::set<MVertex *> &constr_vertices,
  std::map<MVertex *, MVertex *> *equivalence = nullptr,
  std::map<MVertex *, SPoint2> *parametricCoordinates = nullptr);
void buildBackgroundMesh(
  GFace *gf, bool crossFieldClosestPoint = false,
  std::map<MVertex *, MVertex *> *equivalence = nullptr,
  std::map<MVertex *, SPoint2> *parametricCoordinates = nullptr);

void delaunayMeshIn2D(std::vector<MVertex *> &, std::vector<MTriangle *> &,
                      bool removeBox = true,
                      std::vector<MEdge> *edgesToRecover = nullptr,
                      bool hilbertSort = true);

struct edgeXface {
  MVertex *v[2];
  MTri3 *t1;
  int i1;
  int ori;
  edgeXface(MTri3 *_t, int iFac) : t1(_t), i1(iFac), ori(1)
  {
    v[0] = t1->tri()->getVertex(iFac == 0 ? 2 : iFac - 1);
    v[1] = t1->tri()->getVertex(iFac);
    if(v[0]->getNum() > v[1]->getNum()) {
      ori = -1;
      MVertex *tmp = v[0];
      v[0] = v[1];
      v[1] = tmp;
    }
  }
  inline MVertex *_v(int i) const { return v[i]; }
  inline bool operator<(const edgeXface &other) const
  {
    if(_v(0)->getNum() < other._v(0)->getNum()) return true;
    if(_v(0)->getNum() > other._v(0)->getNum()) return false;
    if(_v(1)->getNum() < other._v(1)->getNum()) return true;
    return false;
  }
  inline bool operator==(const edgeXface &other) const
  {
    if(_v(0)->getNum() == other._v(0)->getNum() &&
       _v(1)->getNum() == other._v(1)->getNum())
      return true;
    return false;
  }
};

#endif
