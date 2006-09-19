#ifndef _DELAUNAYINSERTION_H_
#define _DELAUNAYINSERTION_H_
#include "MElement.h"
#include <list>
#include <set>
class GRegion;

class MTet4
{
  bool deleted;
  double circum_radius;
  MTetrahedron *base;
  MTet4 *neigh[4];
 public :
  
  bool isDeleted () const {return deleted;}
  void   forceRadius (double r){circum_radius=r;}
  double getRadius ()const {return circum_radius;}
  
  MTet4 ( MTetrahedron * t, std::vector<double> & sizes) : deleted(false), base (t)
  {
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
  } 

  inline MTetrahedron * tet() const {return base;}
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
#endif
