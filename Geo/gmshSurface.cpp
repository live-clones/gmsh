// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "GmshConfig.h"
#include "GmshMessage.h"
#include "gmshSurface.h"
#include "mathEvaluator.h"

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
SPoint3 gmshPolarSphere::point(double u, double v) const
{
  //stereographic projection from the south pole, origin of the axis
  //at the center of the sphere 
  //u=-x/(r+z) v=-y/(r+z)
  double rp2 = u*u+v*v;
  SPoint3 p(-2*r*u/(1+rp2),-2*r*v/(1+rp2),r*(1-rp2)/(1+rp2));
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
  std::vector<std::string> expressions(3), variables(2);
  expressions[0] = valX;
  expressions[1] = valY;
  expressions[2] = valZ;
  variables[0] = "u";
  variables[1] = "v";
  _f = new mathEvaluator(expressions, variables);
  if(expressions.empty()){
    delete _f;
    _f = 0;
  }
}

gmshParametricSurface::~gmshParametricSurface()
{
  if(_f) delete _f;
}

SPoint3 gmshParametricSurface::point(double par1, double par2) const
{
  if(_f){
    std::vector<double> values(2), res(3);
    values[0] = par1;
    values[1] = par2;
    if(_f->eval(values, res)) return SPoint3(res[0], res[1], res[2]);
  }
  return SPoint3(0., 0., 0.); 
}

Range<double> gmshParametricSurface::parBounds(int i) const
{
  Msg::Error("Parameter bounds not available for parametric surface");
  return Range<double>(0., 0.);
}
