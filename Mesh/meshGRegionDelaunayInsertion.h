#ifndef _DELAUNAYINSERTION_H_
#define _DELAUNAYINSERTION_H_

// Copyright (C) 1997-2007 C. Geuzaine, J.-F. Remacle
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

#include "MElement.h"
#include "qualityMeasures.h"
#include <list>
#include <set>
#include <stack>

//#define _GMSH_PRE_ALLOCATE_STRATEGY_ 1
class GRegion;

class MTet4Factory;

class MTet4
{
  friend class MTet4Factory;
  // a total of 36 Bytes for a MTet4
  // Normally it should take 36 MByte in excess per million of tets
  // 36 MB for 10e6 Tets
  // Each MTetrahedron has a size of 28 Bytes
  // The total memory required for a tet is 64 Bytes
  // i.e. 64 MB per 10e6 Tet
  // Yet, we store also a rb tree containing all pointers
  // sorted with respect to tet radius.
  // each bucket of the tree contain 4 pointers, i.e. 16 Bytes plus
  // the data.  We have therefor an extra cost of 20 Bytes/Tet
  // i.e. 84 MB/ million tets  
  // A MVertex has a cost of 40 Bytes and there are about 200000 of them
  // per million tet: a new cost of 8MB/10e6 tet  : total 92 MB/10e6 tet
  // (I observe 160M MB !!!)

  bool deleted;
  double circum_radius;
  MTetrahedron *base;
  MTet4 *neigh[4];
  GRegion *gr;


 public :

  ~MTet4 (){}
  MTet4 () : deleted(false), base (0), gr(0),circum_radius(0.0)
    {
      neigh[0] = neigh[1] = neigh[2] = neigh[3] = 0;
    }
  MTet4 (MTetrahedron * t, double qual) : deleted(false),  gr(0),circum_radius(qual),base(t)
  {
    neigh[0] = neigh[1] = neigh[2] = neigh[3] = 0;
  }
  MTet4 (MTetrahedron * t, const gmshQualityMeasure4Tet &qm) : deleted(false), gr(0),base(t)
  {
    neigh[0] = neigh[1] = neigh[2] = neigh[3] = 0;
    double vol;
    circum_radius = qmTet(t,qm,&vol);
  }

  void setup ( MTetrahedron * t, std::vector<double> & sizes)
  {
    base = t;
    neigh[0] = neigh[1] = neigh[2] = neigh[3] = 0;
    double center[3];
    base->circumcenter(center);
    const double dx = base->getVertex(0)->x() - center[0];
    const double dy = base->getVertex(0)->y() - center[1];
    const double dz = base->getVertex(0)->z() - center[2];
    circum_radius = sqrt ( dx*dx + dy*dy + dz*dz);

    double lc = 0.25*(sizes [base->getVertex(0)->getNum()]+
		      sizes [base->getVertex(1)->getNum()]+
		      sizes [base->getVertex(2)->getNum()]+
		      sizes [base->getVertex(3)->getNum()]);
    circum_radius /= lc;
    deleted = false;
  } 

  inline GRegion * onWhat () const {return gr;}
  inline void      setOnWhat (GRegion *g) {gr=g;}
  
  bool isDeleted () const {return deleted;}
  void   forceRadius (double r){circum_radius=r;}
  inline double getRadius  ()const {return circum_radius;}
  inline double getQuality ()const {return circum_radius;} 
  inline double setQuality (const double &q){circum_radius=q;} 
  inline MTetrahedron * tet() const {return base;}
  inline MTetrahedron * &tet() {return base;}
  inline void  setNeigh (int iN , MTet4 *n) {neigh[iN]=n;}
  inline MTet4 *getNeigh (int iN ) const {return neigh[iN];}
  int inCircumSphere ( const double *p ) const; 
  inline int inCircumSphere ( double x, double y, double z ) const 
  {
    const double p[3] = {x,y,z};
    return inCircumSphere ( p );
  }
  inline int inCircumSphere ( const MVertex * v) const
  {
    return inCircumSphere ( v->x(), v->y(), v->z() );
  }

  double getVolume () const { return base -> getVolume() ; };
  inline void setDeleted (bool d)
  {
    //    circum_radius = d ? fabs(circum_radius) : fabs(circum_radius)
    deleted = d;
  }
  inline bool assertNeigh() const 
    {
      if (deleted) return true;
      for (int i=0;i<4;i++)
	if (neigh[i] && (neigh[i]->isNeigh(this)==false))return false;
      return true;
    }

  inline bool isNeigh  (const MTet4 *t) const
  {
    for (int i=0;i<4;i++)
      if (neigh[i]==t) return true;
    return false;
  }

};

void connectTets ( std::list<MTet4*> & );
void connectTets ( std::vector<MTet4*> & );
void insertVerticesInRegion (GRegion *gr) ;

class compareTet4Ptr
{
 public:
  inline bool operator () (  const MTet4 *a, const MTet4 *b ) 
    { 
      if (a->getRadius() > b->getRadius())return true;
      if (a->getRadius() < b->getRadius())return false;
      return a<b;
   }
};

class MTet4Factory
{
public:
  typedef std::set<MTet4*,compareTet4Ptr> container;
  typedef container::iterator iterator;
private:
  container allTets;
#ifdef _GMSH_PRE_ALLOCATE_STRATEGY_
  MTet4* allSlots;
  int s_last, s_alloc;
  std::stack<MTet4*> emptySlots;

  inline MTet4 * getANewSlot()
  {
    if (s_last >= s_alloc)return 0;
    MTet4 * t  = &(allSlots[s_last]);
    s_last++;
    return t;
  }
  inline MTet4 * getAnEmptySlot()
  {
    if(!emptySlots.empty())
      {
	MTet4* t = emptySlots.top();
	emptySlots.pop();
	return t;
      }
    return getANewSlot();
  };    
#endif
  

 public :
  MTet4Factory (int _size = 1000000) 
  {
#ifdef _GMSH_PRE_ALLOCATE_STRATEGY_
    s_last=0; s_alloc=_size;
    allSlots = new MTet4 [s_alloc];
#endif
  }
  ~MTet4Factory () {
#ifdef _GMSH_PRE_ALLOCATE_STRATEGY_
    delete [] allSlots;
#endif
  }
  MTet4 * Create (MTetrahedron * t, std::vector<double> & sizes)
  {
#ifdef _GMSH_PRE_ALLOCATE_STRATEGY_
    MTet4 * t4 = getAnEmptySlot();
#else
    MTet4 * t4 = new MTet4;
#endif
    t4->setup(t,sizes);
    return t4;
  }
  void Free (MTet4* t)
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

  void changeTetRadius ( iterator it , double r)
  {
    allTets.erase(it);
    (*it)->forceRadius(r);
    allTets.insert(*it);
  }
  container & getAllTets () {return allTets;}

};

void gmshOptimizeMesh (GRegion *gr, const gmshQualityMeasure4Tet &qm);

#endif
