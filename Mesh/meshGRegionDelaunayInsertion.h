#ifndef _MESH_GREGION_DELAUNAY_INSERTION_H_
#define _MESH_GREGION_DELAUNAY_INSERTION_H_

// Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.

#include <list>
#include <set>
#include <map>
#include <stack>
#include "MElement.h"
#include "BackgroundMesh.h"
#include "qualityMeasures.h"

//#define _GMSH_PRE_ALLOCATE_STRATEGY_ 1
class GRegion;
class GFace;
class GModel;

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

class MTet4
{
  friend class MTet4Factory;
 private:
  bool deleted;
  double circum_radius;
  MTetrahedron *base;
  MTet4 *neigh[4];
  GRegion *gr;
 public :
  ~MTet4(){}
  MTet4() 
    : deleted(false), circum_radius(0.0), base(0), gr(0)
  {
    neigh[0] = neigh[1] = neigh[2] = neigh[3] = 0;
  }
  MTet4(MTetrahedron *t, double qual) 
    : deleted(false), circum_radius(qual), base(t), gr(0)
  {
    neigh[0] = neigh[1] = neigh[2] = neigh[3] = 0;
  }
  MTet4(MTetrahedron *t, const gmshQualityMeasure4Tet &qm) 
    : deleted(false), base(t), gr(0)
  {
    neigh[0] = neigh[1] = neigh[2] = neigh[3] = 0;
    double vol;
    circum_radius = qmTet(t, qm, &vol);
  }

  void setup(MTetrahedron *t, std::vector<double> &sizes, std::vector<double> &sizesBGM)
  {
    base = t;
    neigh[0] = neigh[1] = neigh[2] = neigh[3] = 0;
    double center[3];
    base->circumcenter(center);
    const double dx = base->getVertex(0)->x() - center[0];
    const double dy = base->getVertex(0)->y() - center[1];
    const double dz = base->getVertex(0)->z() - center[2];
    circum_radius = sqrt ( dx*dx + dy*dy + dz*dz);

    double lc1 = 0.25*(sizes[base->getVertex(0)->getNum()]+
		      sizes[base->getVertex(1)->getNum()]+
		       sizes[base->getVertex(2)->getNum()]+
		       sizes[base->getVertex(3)->getNum()]);
    double lcBGM = 0.25*(sizesBGM[base->getVertex(0)->getNum()]+
			 sizesBGM[base->getVertex(1)->getNum()]+
			 sizesBGM[base->getVertex(2)->getNum()]+
			 sizesBGM[base->getVertex(3)->getNum()]);
    double lc = Extend2dMeshIn3dVolumes() ? std::min(lc1, lcBGM) : lcBGM;
    
    circum_radius /= lc;
    deleted = false;
  } 
  inline GRegion *onWhat () const { return gr; }
  inline void setOnWhat (GRegion *g) { gr = g; }
  inline bool isDeleted () const { return deleted; }
  inline void forceRadius (double r){ circum_radius = r; }
  inline double getRadius () const { return circum_radius; }
  inline double getQuality () const { return circum_radius; } 
  inline void setQuality (const double &q){ circum_radius = q; } 
  inline MTetrahedron *tet() const { return base; }
  inline MTetrahedron *&tet() { return base; }
  inline void setNeigh(int iN, MTet4 *n) { neigh[iN] = n; }
  inline MTet4 *getNeigh(int iN) const { return neigh[iN]; }
  int inCircumSphere(const double *p) const; 
  inline int inCircumSphere(double x, double y, double z) const 
  {
    const double p[3] = {x, y, z};
    return inCircumSphere(p);
  }
  inline int inCircumSphere(const MVertex *v) const
  {
    return inCircumSphere(v->x(), v->y(), v->z());
  }
  inline double getVolume() const { return base->getVolume(); }
  inline void setDeleted(bool d)
  {
    deleted = d;
  }
  inline bool assertNeigh() const 
  {
    if (deleted) return true;
    for (int i = 0; i < 4; i++)
      if (neigh[i] && (neigh[i]->isNeigh(this) == false)) return false;
    return true;
  }
  inline bool isNeigh(const MTet4 *t) const
  {
    for (int i = 0; i < 4; i++)
      if (neigh[i] == t) return true;
    return false;
  }
};

void connectTets(std::list<MTet4*> &);
void connectTets(std::vector<MTet4*> &);
void insertVerticesInRegion(GRegion *gr);

class compareTet4Ptr
{
 public:
  inline bool operator () (const MTet4 *a, const MTet4 *b) 
  { 
    if (a->getRadius() > b->getRadius()) return true;
    if (a->getRadius() < b->getRadius()) return false;
    return a < b;
  }
};

class MTet4Factory
{
 public:
  typedef std::set<MTet4*, compareTet4Ptr> container;
  typedef container::iterator iterator;
 private:
  container allTets;
#ifdef _GMSH_PRE_ALLOCATE_STRATEGY_
  MTet4* allSlots;
  int s_last, s_alloc;
  std::stack<MTet4*> emptySlots;
  inline MTet4 *getANewSlot()
  {
    if (s_last >= s_alloc) return 0;
    MTet4 * t  = &(allSlots[s_last]);
    s_last++;
    return t;
  }
  inline MTet4 *getAnEmptySlot()
  {
    if(!emptySlots.empty()){
      MTet4* t = emptySlots.top();
      emptySlots.pop();
      return t;
    }
    return getANewSlot();
  };    
#endif
 public :
  MTet4Factory(int _size = 1000000)
  {
#ifdef _GMSH_PRE_ALLOCATE_STRATEGY_
    s_last = 0; s_alloc = _size;
    allSlots = new MTet4[s_alloc];
#endif
  }
  ~MTet4Factory () 
  {
#ifdef _GMSH_PRE_ALLOCATE_STRATEGY_
    delete [] allSlots;
#endif
  }
  MTet4 * Create (MTetrahedron * t, std::vector<double> &sizes, 
		  std::vector<double> &sizesBGM)
  {
#ifdef _GMSH_PRE_ALLOCATE_STRATEGY_
    MTet4 *t4 = getAnEmptySlot();
#else
    MTet4 *t4 = new MTet4;
#endif
    t4->setup(t, sizes, sizesBGM);
    return t4;
  }
  void Free(MTet4 *t)
  {
    if (t->tet()) delete t->tet();
    t->tet() = 0;
#ifdef _GMSH_PRE_ALLOCATE_STRATEGY_
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
  container &getAllTets(){ return allTets; }
};

void gmshOptimizeMesh(GRegion *gr, const gmshQualityMeasure4Tet &qm);

#endif
