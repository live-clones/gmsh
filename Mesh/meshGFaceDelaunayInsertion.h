// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _MESH_GFACE_DELAUNAY_INSERTIONFACE_H_
#define _MESH_GFACE_DELAUNAY_INSERTIONFACE_H_

#include "MTriangle.h"
#include "STensor3.h"
#include <list>
#include <set>
#include <map>

class GModel;
class GFace;
class BDS_Mesh;
class BDS_Point;

void buildMetric(GFace *gf, double *uv, double *metric);
int inCircumCircleAniso(GFace *gf, double *p1, double *p2, double *p3, double *p4,
                        double *metric);
int inCircumCircleAniso(GFace *gf, MTriangle *base, const double *uv, const double *metric,
                        const std::vector<double> &Us, const std::vector<double> &Vs);
void circumCenterMetric(double *pa, double *pb, double *pc,
                        const double *metric,
                        double *x, double &Radius2);
void circumCenterMetric(MTriangle *base,
                        const double *metric,
                        const std::vector<double> &Us,
                        const std::vector<double> &Vs,
                        double *x, double &Radius2);
bool circumCenterMetricInTriangle(MTriangle *base,
                                  const double *metric,
                                  const std::vector<double> &Us,
                                  const std::vector<double> &Vs);
bool invMapUV(MTriangle *t, double *p,
              const std::vector<double> &Us, const std::vector<double> &Vs,
              double *uv, double tol);

class MTri3
{
  bool deleted;
  double circum_radius;
  MTriangle *base;
  MTri3 *neigh[3];

 public :
  //  char done;
  bool isDeleted () const { return deleted; }
  void forceRadius (double r){ circum_radius = r; }
  double getRadius () const { return circum_radius; }

  MTri3(MTriangle *t, double lc, SMetric3 *m = 0);
  inline MTriangle *tri() const { return base; }
  inline void  setNeigh(int iN , MTri3 *n) { neigh[iN] = n; }
  inline MTri3 *getNeigh(int iN ) const { return neigh[iN]; }
  int inCircumCircle(const double *p) const;
  inline int inCircumCircle(double x, double y) const
  {
    const double p[2] = {x, y};
    return inCircumCircle(p);
  }
  inline int inCircumCircle(const MVertex * v) const
  {
    return inCircumCircle(v->x(), v->y());
  }
  inline void setDeleted (bool d){ deleted = d; }
  inline bool assertNeigh() const
  {
    if (deleted) return true;
    for (int i = 0; i < 3; i++)
      if (neigh[i] && (neigh[i]->isNeigh(this) == false)) return false;
    return true;
  }
  inline bool isNeigh(const MTri3 *t) const
  {
    for (int i = 0; i < 3; i++)
      if (neigh[i] == t) return true;
    return false;
  }
};

class compareTri3Ptr
{
public:
  inline bool operator () (const MTri3 *a, const MTri3 *b)  const
  {
    if (a->getRadius() > b->getRadius()) return true;
    if (a->getRadius() < b->getRadius()) return false;
    return a<b;
  }
};

void connectTriangles(std::list<MTri3*> &);
void connectTriangles(std::vector<MTri3*> &);
void connectTriangles(std::set<MTri3*,compareTri3Ptr> &AllTris);
void gmshBowyerWatson(GFace *gf);
void gmshBowyerWatsonFrontal(GFace *gf);

struct edgeXface
{
  MVertex *v[2];
  MTri3 * t1;
  int i1;
  edgeXface(MTri3 *_t, int iFac) : t1(_t), i1(iFac)
  {
    v[0] = t1->tri()->getVertex(iFac == 0 ? 2 : iFac-1);
    v[1] = t1->tri()->getVertex(iFac);
    std::sort(v, v + 2);
  }
  inline bool operator < ( const edgeXface &other) const
  {
    if (v[0] < other.v[0]) return true;
    if (v[0] > other.v[0]) return false;
    if (v[1] < other.v[1]) return true;
    return false;
  }
};

#endif
