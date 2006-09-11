#ifndef _DELAUNAYINSERTION_H_
#define _DELAUNAYINSERTION_H_
#include "MElement.h"
#include <list>
class MTet4
{
  bool deleted;
  double size;
  MTetrahedron *base;
  MTet4 *neigh[4];
 public :
  MTet4 ( MTetrahedron * t) : deleted(false), base (t)
  {
    neigh[0] = neigh[1] = neigh[2] = neigh[3] = 0;
  } 
  inline MTetrahedron * tet() const {return base;}
  inline void  setNeigh (int iN , MTet4 *n) {neigh[iN]=n;}
  inline MTet4 *getNeigh (int iN ) const {return neigh[iN];}
  double inCircumSphere ( const double *p ) const; 
  inline double inCircumSphere ( double x, double y, double z ) const 
  {
    const double p[3] = {x,y,z};
    return inCircumSphere ( p );
  }
  inline double inCircumSphere ( const MVertex * v) const
  {
    return inCircumSphere ( v->x(), v->y(), v->z() );
  }

  double getVolume () const { return base -> getVolume() ; };
  inline bool operator < ( const MTet4 & other) const {return size < other.size;}
  inline void remove ()
  {
    deleted = true;
    for (int i=0;i<4;i++)
      if (neigh[i])neigh[i]->remove (this); 
  }
  inline void remove (MTet4 *t)
  {
    for (int i=0;i<4;i++)
      if (neigh[i]==t)neigh[i]=0;
  }

};
void connectTets ( std::list<MTet4*> & );
bool insertVertex ( MVertex *v  , MTet4 *t);


#endif
