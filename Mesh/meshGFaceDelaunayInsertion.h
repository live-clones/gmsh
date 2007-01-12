#ifndef _DELAUNAYINSERTIONFACE_H_
#define _DELAUNAYINSERTIONFACE_H_

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
#include <list>
#include <set>
#include <map>

class GFace;
class BDS_Mesh;
class BDS_Point;

struct gmsh2dMetric
{
  double a11,a21,a22;
  gmsh2dMetric (double lc); // uniform metric
  gmsh2dMetric (double _a11 = 1, double _a21= 0, double _a22=1)
    : a11(_a11),a21(_a21),a22(_a22)
  {}
  inline double eval ( const double &x, const double &y ) const
  {
    return x * a11 * x + 2 * x * a21 * y + y * a22 * y;
  }
};


class MTri3
{
  bool deleted;
  gmsh2dMetric metric;
  double xc,yc;
  double circum_radius;
  MTriangle *base;
  MTri3 *neigh[3];
 public :
  
  bool isDeleted () const {return deleted;}
  void   forceRadius (double r){circum_radius=r;}
  double getRadius ()const {return circum_radius;}
  inline void getCenter (double c[2]) const {c[0]=xc;c[1]=yc;}
  
  MTri3 ( MTriangle * t, std::vector<gmsh2dMetric> & sizes);
  inline MTriangle * tri() const {return base;}
  inline void  setNeigh (int iN , MTri3 *n) {neigh[iN]=n;}
  inline MTri3 *getNeigh (int iN ) const {return neigh[iN];}
  int inCircumCircle ( const double *p ) const; 
  inline int inCircumCircle ( double x, double y ) const 
  {
    const double p[2] = {x,y};
    return inCircumCircle ( p );
  }
  inline int inCircumCircle ( const MVertex * v) const
  {
    return inCircumCircle ( v->x(), v->y() );
  }

  void Center_Circum_Aniso(double a, double b, double d, double &x, double &y, double &r) const ;

  double getSurfaceXY () const { return base -> getSurfaceXY() ; };
  inline void setDeleted (bool d)
  {
    deleted = d;
  }
  inline bool assertNeigh() const 
    {
      if (deleted) return true;
      for (int i=0;i<3;i++)
	if (neigh[i] && (neigh[i]->isNeigh(this)==false))return false;
      return true;
    }

  inline bool isNeigh  (const MTri3 *t) const
  {
    for (int i=0;i<3;i++)
      if (neigh[i]==t) return true;
    return false;
  }

};

void connectTriangles ( std::list<MTri3*> & );
void insertVerticesInFace (GFace *gf, BDS_Mesh *);

class compareTri3Ptr
{
 public:
  inline bool operator () (  const MTri3 *a, const MTri3 *b ) 
    { 
      if (a->getRadius() > b->getRadius())return true;
      if (a->getRadius() < b->getRadius())return false;
      return a<b;
   }
};

#endif
