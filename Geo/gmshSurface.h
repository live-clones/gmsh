// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _GMSH_SURFACE_H_
#define _GMSH_SURFACE_H_

#include <math.h>
#include <map>
#include "Pair.h"
#include "Range.h"
#include "SPoint2.h"
#include "SPoint3.h"
#include "SVector3.h"
#include "SBoundingBox3d.h"
#include "Numeric.h"

class gmshSurface
{
protected:  
  static std::map<int, gmshSurface*> allGmshSurfaces;
public:
  //there are points define in this surface parameterization
  bool vertex_defined_on_surface;
  virtual ~gmshSurface(){}
  static void reset() 
  {
    std::map<int, gmshSurface*>::iterator it = allGmshSurfaces.begin();
    for (; it != allGmshSurfaces.end(); ++it){
      if(!it->second->vertex_defined_on_surface)
        delete it->second;
    }
    allGmshSurfaces.clear();
  };
  static gmshSurface* getSurface(int tag);
  virtual Range<double> parBounds(int i) const = 0;
  /// Underlying geometric representation of this entity.
  enum gmshSurfaceType {
    Plane,
    Nurbs,
    Cylinder,
    Sphere,
    Cone,
    Torus,
    ParametricSurface,
    PolarSphere
  };
  virtual gmshSurface::gmshSurfaceType geomType() const = 0;
  virtual SPoint3 point(double par1, double par2) const = 0;
  virtual SPoint3 point(const SPoint2 &p) const { return point(p.x(), p.y()); }
  virtual SPoint2 parFromPoint(double x, double y, double z);
  // Return the normal to the face at the given parameter location.
  virtual SVector3 normal(const SPoint2 &param) const;
  // Return the first derivate of the face at the parameter location.
  virtual Pair<SVector3,SVector3> firstDer(const SPoint2 &param);
  virtual double getMetricEigenvalue(const SPoint2 &);
};

class gmshSphere : public gmshSurface
{
  double xc, yc, zc, r;
  gmshSphere(double _x, double _y, double _z, double _r) : xc(_x), yc(_y), zc(_z), r(_r){}
public:
  static gmshSurface *NewSphere(int _iSphere, double _x, double _y, double _z, double _r);
  virtual Range<double> parBounds(int i) const 
  { 
    if(i == 0) 
      return Range<double>(0., 2 * M_PI);
    else
      return Range<double>(0., M_PI);
  }
  virtual gmshSurface::gmshSurfaceType geomType() const { return gmshSurface::Sphere; }
  virtual SPoint3 point(double par1, double par2) const;
  virtual SVector3 normal(const SPoint2 &param) const
  {
    SPoint3  p1 = gmshSurface::point(param);
    SPoint3  p2(xc, yc, zc);
    SVector3 n(p1, p2);
    n.normalize();
    return n;
  }
};

#include "stdio.h"
class gmshPolarSphere : public gmshSurface
{
  double r;
  SPoint3 o;
  gmshPolarSphere(double x, double y, double z, double _r);
public:
  static gmshSurface *NewPolarSphere(int _iSphere, double _x, double _y, double _z, double _r);
  virtual Range<double> parBounds(int i) const 
  { 
    if(i == 0)
      return Range<double>(-M_PI, M_PI);
    else
      return Range<double>(-M_PI, M_PI);
  }
  virtual gmshSurface::gmshSurfaceType geomType() const { return gmshSurface::PolarSphere; }
  virtual SPoint3 point(double par1, double par2) const;
  virtual SVector3 normal(const SPoint2 &param) const
  {
    SPoint3  p1 = gmshSurface::point(param);
    SVector3 n(p1, o);
    n.normalize();
    return n;
  }
  virtual double getMetricEigenvalue ( const SPoint2 &p)
  {
    double l = (4*r*r)/(4*r*r+p.x()*p.x()+p.y()*p.y());
    return l*l;
  }
};

class gmshParametricSurface : public gmshSurface
{
  void *evalX, *evalY, *evalZ;
  gmshParametricSurface(char*, char*, char*);
  ~gmshParametricSurface();
public:
  static gmshSurface *NewParametricSurface(int iSurf, char*, char*, char*);
  virtual Range<double> parBounds(int i) const;
  virtual gmshSurface::gmshSurfaceType geomType() const 
  { 
    return gmshSurface::ParametricSurface; 
  }
  virtual SPoint3 point(double par1, double par2) const;
};

#endif
