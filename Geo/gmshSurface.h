#ifndef _GMSH_SURFACE_H_
#define _GMSH_SURFACE_H_

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

#include <cmath>
#include <map>
#include "Pair.h"
#include "Range.h"
#include "SPoint2.h"
#include "SPoint3.h"
#include "SVector3.h"
#include "SBoundingBox3d.h"

class gmshSurface
{
protected:  
  static std::map<int,gmshSurface*> allGmshSurfaces;
public:
  static void reset () {
    std::map<int,gmshSurface*>::iterator it = allGmshSurfaces.begin();
    for ( ; it != allGmshSurfaces.end();++it)
      delete it->second;
    allGmshSurfaces.clear();
  };
  static gmshSurface* surfaceByTag ( int tag ) ;
  virtual Range<double> parBounds(int i) const = 0;
  /// Underlying geometric representation of this entity.
  enum gmshSurfaceType {
    Plane,
    Nurbs,
    Cylinder,
    Sphere,
    Cone,
    Torus
  };
  virtual gmshSurface::gmshSurfaceType geomType() const = 0;
  virtual SPoint3 point       (double par1, double par2) const = 0;
  virtual SPoint3  point      (const SPoint2 &p) const
  {return point(p.x(),p.y()); }
  virtual SPoint2 parFromPoint(double x, double y, double z) const = 0;
  // Return the normal to the face at the given parameter location.
  virtual SVector3 normal(const SPoint2 &param) const = 0;
  // Return the first derivate of the face at the parameter location.
  virtual Pair<SVector3,SVector3> firstDer(const SPoint2 &param) const = 0;
};


class gmshSphere : public gmshSurface
{
  double xc, yc, zc, r;
  gmshSphere ( double _x, double _y, double _z, double _r) : xc(_x),yc(_y),zc(_z),r(_r){}
public:
  static gmshSurface * NewSphere (  int _iSphere, double _x, double _y, double _z, double _r );
  virtual Range<double> parBounds(int i) const { 
    if (i == 0) return Range<double> ( 0. , 2 * M_PI) ;
    if (i == 1) return Range<double> ( 0. , M_PI) ;
    throw;
  }
  /// Underlying geometric representation of this entity.
  virtual gmshSurface::gmshSurfaceType geomType() const {return gmshSurface::Sphere;}
  virtual SPoint3  point       (double par1, double par2) const ;
  virtual SPoint2 parFromPoint(double x, double y, double z) const 
  {
    // 2 be done 
    throw;
  }
  // Return the normal to the face at the given parameter location.
  virtual SVector3 normal(const SPoint2 &param) const
  {
    SPoint3  p1 = gmshSurface::point (param);
    SPoint3  p2 (xc,yc,zc);
    SVector3 n (p1,p2);
    n.normalize();
    return n;
  }
  // Return the first derivate of the face at the parameter location.
  virtual Pair<SVector3,SVector3> firstDer(const SPoint2 &param) const
  {
    // 2 be done
    throw;
  }  
};

#endif
