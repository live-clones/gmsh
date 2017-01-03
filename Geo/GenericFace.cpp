// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.
//
// Contributed by Paul-Emile Bernard

#include <math.h>
#include "GmshMessage.h"
#include "GModel.h"
#include "GEdgeLoop.h"
#include "GenericVertex.h"
#include "GenericEdge.h"
#include "GenericFace.h"
#include "Numeric.h"
#include "Context.h"

GenericFace::ptrfunction_int_refstring GenericFace::FaceGeomType = NULL;
GenericFace::ptrfunction_int_refvector_refvector GenericFace::FaceUVFromXYZ = NULL;
GenericFace::ptrfunction_int_refvector_refvector_refvector GenericFace::FaceClosestPoint = NULL;
GenericFace::ptrfunction_int_refvector_refbool GenericFace::FaceContainsPointFromXYZ = NULL;
GenericFace::ptrfunction_int_refvector_refbool GenericFace::FaceContainsPointFromUV = NULL;
GenericFace::ptrfunction_int_refvector_refvector GenericFace::FaceXYZFromUV = NULL;
GenericFace::ptrfunction_int_int_refdouble_refdouble GenericFace::FaceParBounds = NULL;
GenericFace::ptrfunction_int_refvector_refvector_refvector_refdouble_refdouble GenericFace::FaceCurvatures = NULL;
GenericFace::ptrfunction_int_refvector_refvector GenericFace::FaceEvalNormal = NULL;
GenericFace::ptrfunction_int_refvector_refvector_refvector GenericFace::FaceFirstDer = NULL;
GenericFace::ptrfunction_int_refvector_refvector_refvector_refvector GenericFace::FaceSecondDer = NULL;
GenericFace::ptrfunction_int_refbool_refbool_refdouble_refdouble GenericFace::FacePeriodicInfo = NULL;

GenericFace::GenericFace(GModel *m, int num, int _native_id):GFace(m, num), id(_native_id)
{
  if (!FaceParBounds) Msg::Fatal("Genericface::ERROR: Callback FaceParBounds not set");

  bool ok = FaceParBounds(id,0,umin,umax);
  if (!ok) Msg::Error("GenericEdge::ERROR from EdgeEvalParBounds ! " );
  ok = FaceParBounds(id,1,vmin,vmax);

  computePeriodicity();
}

GenericFace::~GenericFace()
{
}

Range<double> GenericFace::parBounds(int i) const
{
  if(i == 0) return Range<double>(umin, umax);
  return Range<double>(vmin, vmax);
}

SVector3 GenericFace::normal(const SPoint2 &param) const
{
  std::vector<double> res(3,0.);
  std::vector<double> par(2,0.);
  for (int i = 0; i < 2; i++) par[i] = param[i];
  if (!FaceEvalNormal) Msg::Fatal("Genericface::ERROR: Callback FaceEvalNormal not set");
  bool ok = FaceEvalNormal(id,par,res);
  if (!ok) Msg::Error("GenericFace::ERROR from FaceEvalNormal ! " );
  return SVector3(res[0],res[1],res[2]);
}

Pair<SVector3,SVector3> GenericFace::firstDer(const SPoint2 &param) const
{
  if (!FaceFirstDer) Msg::Fatal("Genericface::ERROR: Callback FaceFirstDer not set");
  std::vector<double> deru(3,0.);
  std::vector<double> derv(3,0.);
  std::vector<double> par(2,0.);
  for (int i = 0; i < 2; i++) par[i] = param[i];
  bool ok = FaceFirstDer(id,par,deru,derv);
  if (!ok) Msg::Error("GenericFace::ERROR from FaceFirstDer ! " );
  return Pair<SVector3,SVector3>(SVector3(deru[0],deru[1],deru[2]),
                                 SVector3(derv[0],derv[1],derv[2]));
}

void GenericFace::secondDer(const SPoint2 &param,SVector3 *dudu, SVector3 *dvdv, SVector3 *dudv) const
{
  std::vector<double> deruu(3,0.);
  std::vector<double> dervv(3,0.);
  std::vector<double> deruv(3,0.);
  std::vector<double> par(2,0.);
  for (int i = 0; i < 2; i++) par[i] = param[i];
  if (!FaceSecondDer) Msg::Fatal("Genericface::ERROR: Callback FaceSecondDer not set");
  bool ok = FaceSecondDer(id,par,deruu,dervv,deruv);
  if (!ok) Msg::Error("GenericFace::ERROR from FaceSecondDer ! " );
  *dudu = SVector3(deruu[0],deruu[1],deruu[2]);
  *dvdv = SVector3(dervv[0],dervv[1],dervv[2]);
  *dudv = SVector3(deruv[0],deruv[1],deruv[2]);
  return;
}

GPoint GenericFace::point(double par1, double par2) const
{
  std::vector<double> uv(2,0.);
  uv[0] = par1;
  uv[1] = par2;
  std::vector<double> xyz(3,0.);
  double pp[2] = {par1, par2};
  if (!FaceXYZFromUV) Msg::Fatal("Genericface::ERROR: Callback FaceXYZFromUV not set");
  bool ok = FaceXYZFromUV(id,uv,xyz);
  if (!ok){
    Msg::Error("GenericFace::ERROR from FaceXYZFromUV ! " );
    GPoint p(xyz[0], xyz[1], xyz[2], this, pp);
    p.setNoSuccess();
    return p;
  }
  return GPoint(xyz[0], xyz[1], xyz[2], this, pp);
}


GPoint GenericFace::closestPoint(const SPoint3 &qp, const double initialGuess[2]) const
{
  std::vector<double> uvres(2,0.);
  std::vector<double> xyzres(3,0.);
  std::vector<double> queryPoint(3,0.);
  for (int i=0;i<3;i++) queryPoint[i] = qp[i];
  if (!FaceClosestPoint) Msg::Fatal("Genericface::ERROR: Callback FaceClosestPoint not set");
  bool ok = FaceClosestPoint(id,queryPoint,xyzres,uvres);// orthogonal projection
  if (!ok) Msg::Error("GenericFace::ERROR from FaceClosestPoint ! " );

  // check if the projected point lies on the face...
  bool on_the_face;

  if (!FaceContainsPointFromUV) Msg::Fatal("Genericface::ERROR: Callback FaceContainsPointFromUV not set");
  ok = FaceContainsPointFromUV(id,uvres,on_the_face);
  if (!ok) Msg::Error("GenericFace::ERROR from FaceContainsPointFromUV ! " );
  if (!on_the_face) Msg::Warning("GenericFace::closestPoint::Warning (using UV)  !!!! The returned point does not lies on the face ! " );
  double pp[2] = {uvres[0], uvres[1]};
  return GPoint(xyzres[0], xyzres[1], xyzres[2], this, pp);
}

SPoint2 GenericFace::parFromPoint(const SPoint3 &qp, bool onSurface) const
{
  std::vector<double> uvres(2,0.);
  std::vector<double> xyzres(3,0.);
  std::vector<double> queryPoint(3,0.);
  for (int i=0;i<3;i++) queryPoint[i] = qp[i];
  bool ok=true;
  if (onSurface){
    if (!FaceUVFromXYZ) Msg::Fatal("Genericface::ERROR: Callback FaceUVFromXYZ not set");
    ok = FaceUVFromXYZ(id,queryPoint,uvres);// assuming point is on surface
    if (!ok) Msg::Error("GenericFace::ERROR from FaceUVFromXYZ ! " );
  }
  if ((!onSurface)||(!ok)){// if not on surface
    if (!FaceClosestPoint) Msg::Fatal("Genericface::ERROR: Callback FaceClosestPoint not set");
    ok = FaceClosestPoint(id,queryPoint,xyzres,uvres);// orthogonal projection
    if (!ok) Msg::Error("GenericFace::ERROR from FaceClosestPoint ! " );
    bool on_the_face;
    if (!FaceContainsPointFromXYZ) Msg::Fatal("Genericface::ERROR: Callback FaceContainsPointFromXYZ not set");
    ok = FaceContainsPointFromXYZ(id,xyzres,on_the_face);// check if the projected point lies on the face...
    if (!ok) Msg::Error("GenericFace::parFromPoint::ERROR from FaceContainsPointFromXYZ ! " );
    if (!on_the_face) Msg::Warning("GenericFace::parFromPoint::Warning !!!! The returned point does not lies on the face ! " );
  }
  return SPoint2(uvres[0],uvres[1]);
}

GEntity::GeomType GenericFace::geomType() const
{
  std::string s;
  if (!FaceGeomType) Msg::Fatal("Genericface::ERROR: Callback FaceGeomType not set");
  bool ok = FaceGeomType(id,s);
  if (!ok){
    Msg::Error("GenericFace::ERROR from FaceGeomType ! " );
    return Unknown;
  }

  if(s.compare("Plane")==0)
    return Plane;
  else if(s.compare("Cylinder")==0)
    return Cylinder;
  else if(s.compare("Cone")==0)
    return Cone;
  else if(s.compare("Sphere")==0)
    return Sphere;
  else if(s.compare("Torus")==0)
    return Torus;
  else if(s.compare("BezierSurface")==0)
    return BezierSurface;
  else if(s.compare("BSplineSurface")==0)
    return BSplineSurface;
  else if(s.compare("SurfaceOfRevolution")==0)
    return SurfaceOfRevolution;

  return Unknown;
}

double GenericFace::curvatureMax(const SPoint2 &param) const
{
  std::vector<double> dirMax(3,0.);
  std::vector<double> dirMin(3,0.);
  double curvMax,curvMin;
  std::vector<double> par(2,0.);
  for (int i = 0; i < 2; i++) par[i] = param[i];
  if (!FaceCurvatures) Msg::Fatal("Genericface::ERROR: Callback FaceCurvatures not set");
  bool ok = FaceCurvatures(id,par,dirMax,dirMin,curvMax,curvMin);
  if (!ok) Msg::Error("GenericFace::ERROR from FaceCurvatures ! " );
  return std::max(fabs(curvMax), fabs(curvMin));
}

double GenericFace::curvatures(const SPoint2 &_param,SVector3 *_dirMax,SVector3 *_dirMin,
                               double *curvMax,double *curvMin) const
{
  std::vector<double> param(2,0.);
  for (int i = 0; i < 2; i++) param[i] = _param[i];
  std::vector<double> dirMax(3,0.);
  std::vector<double> dirMin(3,0.);

  if (!FaceCurvatures) Msg::Fatal("Genericface::ERROR: Callback FaceCurvatures not set");
  bool ok = FaceCurvatures(id,param,dirMax,dirMin,*curvMax,*curvMin);
  if (!ok) Msg::Error("GenericFace::ERROR from FaceCurvatures ! " );

  *_dirMax = SVector3(dirMax[0],dirMax[1],dirMax[2]);
  *_dirMin = SVector3(dirMin[0],dirMin[1],dirMin[2]);
  return *curvMax;
}

bool GenericFace::containsPoint(const SPoint3 &pt) const
{
  bool res;
  std::vector<double> queryPoint(3,0.);
  for (int i = 0; i < 3; i++) queryPoint[i] = pt[i];
  if (!FaceContainsPointFromXYZ) Msg::Fatal("Genericface::ERROR: Callback FaceContainsPointFromXYZ not set");
  bool ok = FaceContainsPointFromXYZ(id,queryPoint,res);
  if (!ok) Msg::Error("GenericFace::containsPoint::ERROR from FaceContainsPointFromXYZ ! " );
  return res;
}

void GenericFace::computePeriodicity()
{
  if (!FacePeriodicInfo) Msg::Fatal("Genericface::ERROR: Callback FacePeriodicInfo not set");
  bool ok = FacePeriodicInfo(id,_periodic[0], _periodic[1],_period[0],_period[1]);
  if (!ok) Msg::Error("GenericFace::ERROR from FacePeriodicInfo ! " );
}

void GenericFace::createLoops()
{
  edgeLoops.clear();
  l_edges.clear();
  l_dirs.clear();

  for (std::set<int>::iterator it_loop = loopsnumber.begin();
       it_loop != loopsnumber.end(); it_loop++){// for each loop
    std::pair<std::multimap<int, std::pair<GEdge*,int> >::iterator,
              std::multimap<int, std::pair<GEdge*,int> >::iterator>
      range = bnd.equal_range(*it_loop);
    std::list<GEdge*> l_wire;
    for (std::multimap<int, std::pair<GEdge*,int> >::iterator it = range.first;
         it!=range.second;it++){// for all edges
      l_wire.push_back(it->second.first);
    }
    GEdgeLoop el(l_wire);
    for(GEdgeLoop::citer it = el.begin(); it != el.end(); ++it){
      l_edges.push_back(it->ge);
      l_dirs.push_back(it->_sign);
      if (el.count() == 2){
        it->ge->meshAttributes.minimumMeshSegments =
          std::max(it->ge->meshAttributes.minimumMeshSegments,2);
      }
      if (el.count() == 1){
        it->ge->meshAttributes.minimumMeshSegments =
          std::max(it->ge->meshAttributes.minimumMeshSegments,3);
      }
    }
    edgeLoops.push_back(el);
  }
}
