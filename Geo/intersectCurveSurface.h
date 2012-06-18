// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _INTERSECT_CURVE_SURFACE_
#define _INTERSECT_CURVE_SURFACE_

// Intersection of a curve and a surface using newton's method
// FD are used to compute derivatives of the parametrizations
#include "SPoint3.h"
#include "SVector3.h"
#include "GFace.h"
#include "GEdge.h"
#include "math.h"

class surfaceFunctor 
{
public :
  virtual ~surfaceFunctor(){}
  virtual SPoint3 operator () (double u, double v) const = 0;
};

class curveFunctor 
{
public :
  virtual ~curveFunctor(){}
  virtual SPoint3 operator () (double t) const = 0;
};

class surfaceFunctorGFace : public surfaceFunctor
{
  const GFace *gf;
public :
  surfaceFunctorGFace(const GFace *_gf) : gf(_gf) {}
  virtual SPoint3 operator () (double u, double v) const {
    GPoint gp =  gf->point(u,v);
    return SPoint3(gp.x(),gp.y(),gp.z());
  }
};

class curveFunctorGEdge : public curveFunctor
{
  const GEdge *ge;
public :
  curveFunctorGEdge(const GEdge *_ge) : ge(_ge) {}
  virtual SPoint3 operator () (double t) const {
    GPoint gp =  ge->point(t);
    return SPoint3(gp.x(),gp.y(),gp.z());
  }
};

class curveFunctorCircle : public curveFunctor
{
  SVector3 n1,n2;
  SVector3 middle;
  double d;
public :
  curveFunctorCircle(const SVector3 & _n1, const SVector3 & _n2, const SVector3 & _middle, const double & _d) : 
  n1(_n1),n2(_n2),middle(_middle),d(_d) {
  }
  virtual SPoint3 operator () (double t) const {
    SVector3 dir = (n1*cos(t)+n2*sin(t))*d;
    return SPoint3(middle.x() + dir.x(),
		   middle.y() + dir.y(),
		   middle.z() + dir.z());
  }
};

class surfaceFunctorPlane : public surfaceFunctor
{
  const SPoint3 p;
  const SVector3 v1,v2;
public :
  surfaceFunctorPlane(const SPoint3 &_p, const SVector3 &_v1, const SVector3 &_v2) : p(_p),v1(_v1),v2(_v2) {}
  virtual SPoint3 operator () (double u, double v) const {
    return SPoint3 (p.x() + u * v1.x() + v * v2.x(),
		   p.y() + u * v1.y() + v * v2.y(),
		   p.z() + u * v1.z() + v * v2.z()) ;
  }
};
// intersects the curve and the surface using Newton.
// the initial guess should be a good guess
// returns 1 --> OK
// returns 0 --> NOT CONVERGED
int intersectCurveSurface (curveFunctor &c, surfaceFunctor & s, double uvt[3], double epsilon);

#endif
