// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "GmshConfig.h"
#include "GmshMessage.h"
#include "gmshSurface.h"

#if defined(HAVE_MATH_EVAL)
#include "matheval.h"
#endif

std::map<int,gmshSurface*> gmshSurface::allGmshSurfaces;

SPoint2 gmshSurface::parFromPoint(double x, double y, double z)
{
  Msg::Error("Parametric coordinate computation not implemented for this type of surface");
  return SPoint2();
}

SVector3 gmshSurface::normal(const SPoint2 &param) const
{
  Msg::Error("Normal computation not implemented for this type of surface");
  return SVector3();
}

Pair<SVector3, SVector3> gmshSurface::firstDer(const SPoint2 &param)
{
  Msg::Error("First derivative not implemented for this type of surface");
  return Pair<SVector3, SVector3>();
}

double gmshSurface::getMetricEigenvalue(const SPoint2 &)
{
  Msg::Error("Metric eigenvalue not implemented for this type of surface");
  return 0;
}

gmshSurface *gmshSphere::NewSphere(int iSphere, double x, double y, double z, double r)
{
  gmshSphere *sph = new gmshSphere(x, y, z, r);
  
  if(allGmshSurfaces.find(iSphere) != allGmshSurfaces.end()){
    Msg::Error("gmshSurface %d already exists",iSphere);
  }
  
  allGmshSurfaces[iSphere] = sph;
  return sph;
}

gmshSurface *gmshSurface::getSurface(int iSurface)
{
  std::map<int, gmshSurface*>::iterator it = allGmshSurfaces.find(iSurface);
  if(it == allGmshSurfaces.end()){
    Msg::Error("gmshSurface %d does not exist",iSurface);
    return 0;
  }
  return it->second;
}

SPoint3 gmshSphere::point(double par1, double par2) const
{
  par2 += M_PI*.5;
  const double x = xc + r * sin(par2) * cos(par1);
  const double y = yc + r * sin(par2) * sin(par1);
  const double z = zc - r * cos(par2); 
  return SPoint3(x, y, z);
}

gmshSurface *gmshPolarSphere::NewPolarSphere(int iSphere, double x, double y, double z,
                                             double r)
{
  gmshPolarSphere *sph = new gmshPolarSphere(x, y, z, r);
  
  if(allGmshSurfaces.find(iSphere) != allGmshSurfaces.end()){
    Msg::Error("gmshSurface %d already exists", iSphere);
  }

  allGmshSurfaces[iSphere] = sph;
  return sph;
}

gmshPolarSphere::gmshPolarSphere(double x, double y, double z, double _r) : r(_r), o(x,y,z) {
}
SPoint3 gmshPolarSphere::point(double parA, double parB) const
{
  //stereographic projection from the south pole, origin of the axis
  //at the center of the sphere 
  //parA=2rx/(r+z) parB=2ry/(r+z)
  double rp2 = parA * parA + parB * parB;
  SPoint3 p(2*parA/(1+rp2),2*parB/(1+rp2),(rp2-1)/(rp2+1));
  p *= -r;
  p += o;
  return p;
}

gmshSurface *gmshParametricSurface::NewParametricSurface(int iSurf, char *valX,
                                                         char *valY, char *valZ)
{
  gmshParametricSurface *sph = new gmshParametricSurface(valX, valY, valZ);
  
  if(allGmshSurfaces.find(iSurf) != allGmshSurfaces.end()){
    Msg::Error("gmshSurface %d already exists",iSurf);
  }
  allGmshSurfaces[iSurf] = sph;
  return sph;
}

gmshParametricSurface::gmshParametricSurface(char *valX, char *valY, char *valZ)
{
#if !defined(HAVE_MATH_EVAL)
  Msg::Error("MathEval is not compiled in this version of Gmsh");
#else
  evalX = evaluator_create(valX);
  evalY = evaluator_create(valY);
  evalZ = evaluator_create(valZ);
#endif
}

gmshParametricSurface::~gmshParametricSurface()
{
#if !defined(HAVE_MATH_EVAL)
  Msg::Error("MathEval is not compiled in this version of Gmsh");
#else
  evaluator_destroy(evalX);
  evaluator_destroy(evalY);
  evaluator_destroy(evalZ);
#endif
}

SPoint3 gmshParametricSurface::point(double par1, double par2) const
{
#if !defined(HAVE_MATH_EVAL)
  Msg::Error("MathEval is not compiled in this version of Gmsh");
  return SPoint3(0.,0.,0.);
#else
  char *names[2] = {"u", "v"};
  double values [2] = {par1, par2};
  const double x = evaluator_evaluate(evalX, 2, names, values);
  const double y = evaluator_evaluate(evalY, 2, names, values);
  const double z = evaluator_evaluate(evalZ, 2, names, values);
  return SPoint3(x, y, z);
#endif
}

Range<double> gmshParametricSurface::parBounds(int i) const
{
  Msg::Error("Parameter bounds not available for parametric surface");
  return Range<double>(0., 0.);
}
