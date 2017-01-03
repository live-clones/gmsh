// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.
//
// Contributed by Paul-Emile Bernard

#include <limits>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "GModel.h"
#include "GenericEdge.h"
#include "GenericFace.h"
#include "Context.h"

GenericEdge::ptrfunction_int_double_refvector GenericEdge::EdgeEvalXYZFromT = NULL;
GenericEdge::ptrfunction_int_refdouble_refdouble GenericEdge::EdgeEvalParBounds = NULL;
GenericEdge::ptrfunction_int_refstring GenericEdge::EdgeGeomType = NULL;
GenericEdge::ptrfunction_int_refbool GenericEdge::EdgeDegenerated = NULL;
GenericEdge::ptrfunction_int_double_refvector GenericEdge::EdgeEvalFirstDer = NULL;
GenericEdge::ptrfunction_int_double_refdouble GenericEdge::EdgeEvalCurvature = NULL;
GenericEdge::ptrfunction_int_refvector_refdouble_refvector_refbool GenericEdge::EdgeClosestPoint = NULL;
GenericEdge::ptrfunction_int_refbool GenericEdge::EdgeIs3D = NULL;
GenericEdge::ptrfunction_int_int_double_int_refvector GenericEdge::EdgeReparamOnFace = NULL;

GenericEdge::GenericEdge(GModel *m, int num, int _native_id, GVertex *v1, GVertex *v2, bool _isseam)
 : GEdge(m, num, v1, v2), id(_native_id),is_seam(_isseam)
{
  if ((!EdgeEvalParBounds)||(!EdgeEvalXYZFromT)) Msg::Error("GenericEdge::ERROR: Callback not set");
  bool ok = EdgeEvalParBounds(id,s0,s1);
  if (!ok) Msg::Error("GenericEdge::ERROR from EdgeEvalParBounds ! " );
}

GenericEdge::~GenericEdge()
{
}

Range<double> GenericEdge::parBounds(int i) const
{
  return Range<double>(s0, s1);
}

SPoint2 GenericEdge::reparamOnFace(const GFace *face, double par, int dir) const
{
  std::vector<double> res(2,0.);
  if (!EdgeReparamOnFace) Msg::Error("GenericEdge::ERROR: Callback EdgeReparamOnFace not set");
  bool ok = EdgeReparamOnFace(id,face->getNativeInt(),par, dir,res);
  if (!ok){
    Msg::Error("GenericEdge::ERROR from EdgeReparamOnFace ! Edge Native id %d",getNativeInt() );
  }
  return SPoint2(res[0],res[1]);;
}

GPoint GenericEdge::closestPoint(const SPoint3 &qp, double &param) const
{
  std::vector<double> queryPoint(3,0.);
  for (int i=0;i<3;i++) queryPoint[i] = qp[i];
  std::vector<double> res(3,0.);
  bool is_on_edge;
  if (!EdgeClosestPoint) Msg::Error("GenericEdge::ERROR: Callback EdgeClosestPoint not set");
  bool ok = EdgeClosestPoint(id,queryPoint,param,res,is_on_edge);
  if (!ok) Msg::Error("GenericEdge::ERROR from EdgeClosestPoint ! " );
  if (!is_on_edge) Msg::Warning("WARNING:GenericEdge::closestPoint closest point NOT on edge, out of bounds ! " );
  return GPoint(res[0], res[1], res[2], this, param);
}

bool GenericEdge::isSeam(const GFace *face) const
{
  return is_seam;
}

GPoint GenericEdge::point(double par) const
{
  std::vector<double> res(3,0.);
  if (!EdgeEvalXYZFromT) Msg::Error("GenericEdge::ERROR: Callback EdgeEvalXYZFromT not set");
  bool ok = EdgeEvalXYZFromT(id,par,res);
  if (!ok) Msg::Error("GenericEdge::ERROR from EdgeEvalXYZFromT ! " );
  return GPoint(res[0], res[1], res[2], this, par);
}

SVector3 GenericEdge::firstDer(double par) const
{
  std::vector<double> res(3,0.);
  if (!EdgeEvalFirstDer) Msg::Error("GenericEdge::ERROR: Callback EdgeEvalFirstDer not set");
  bool ok = EdgeEvalFirstDer(id,par,res);
  if (!ok) Msg::Error("GenericEdge::ERROR from EdgeEvalFirstDer ! " );
  return SVector3(res[0],res[1],res[2]);
}

GEntity::GeomType GenericEdge::geomType() const
{
  std::string s;
  if (!EdgeGeomType) Msg::Error("GenericEdge::ERROR: Callback EdgeGeomType not set");
  bool ok = EdgeGeomType(id,s);
  if (!ok){
    Msg::Error("GenericEdge::ERROR from EdgeGeomType ! Edge Native id %d",getNativeInt() );
    return Unknown;
  }

  if(s.compare("Line")==0)
    return Line;
  else if(s.compare("Circle")==0)
    return Circle;
  else if(s.compare("Ellipse")==0)
    return Ellipse;
  else if(s.compare("Parabola")==0)
    return Parabola;
  else if(s.compare("Hyperbola")==0)
    return Hyperbola;
  else if(s.compare("Bezier")==0)
    return Bezier;
  else if(s.compare("BSpline")==0)
    return BSpline;
  else if(s.compare("TrimmedCurve")==0)
    return TrimmedCurve;
  else if(s.compare("Intersection curve")==0)
    return BSpline;

  Msg::Warning("GenericEdge::geomType:: unknown type from callback: %s", s.c_str());

  return Unknown;
}

double GenericEdge::curvature(double par) const
{
  double res;
  if (!EdgeEvalCurvature) Msg::Error("GenericEdge::ERROR: Callback EdgeEvalCurvature not set");
  bool ok = EdgeEvalCurvature(id,par,res);
  if (!ok) Msg::Error("GenericEdge::ERROR from EdgeEvalCurvature ! " );
  return res;
}

bool GenericEdge::is3D() const
{
  bool res;
  if (!EdgeIs3D) Msg::Error("GenericEdge::ERROR: Callback EdgeIs3D not set");
  bool ok = EdgeIs3D(id,res);
  if (!ok) Msg::Error("GenericEdge::ERROR from EdgeIs3D ! " );
  return res;
}

bool GenericEdge::degenerate(int) const
{
  bool res=false;
  if (!EdgeDegenerated) Msg::Error("GenericEdge::ERROR: Callback EdgeDegenerated not set");
  bool ok = EdgeDegenerated(id,res);
  if (!ok) Msg::Error("GenericEdge::ERROR from EdgeDegenerated ! " );
  return res;
}

int GenericEdge::minimumDrawSegments() const
{
  if(geomType() == Line)
    return GEdge::minimumDrawSegments();
  else
    return CTX::instance()->geom.numSubEdges * GEdge::minimumDrawSegments();
}

LinearSeamEdge::LinearSeamEdge(GModel *m, int num, GVertex *v1, GVertex *v2):GEdge(m, num, v1, v2)
{
  s0=0.;
  s1=v1->xyz().distance(v2->xyz());
  first_der = SVector3(v1->xyz(),v2->xyz());
  first_der.normalize();
}

LinearSeamEdge::~LinearSeamEdge()
{
}

Range<double> LinearSeamEdge::parBounds(int i) const
{
  return Range<double>(s0, s1);
}

GPoint LinearSeamEdge::point(double par) const
{
  SVector3 res = v0->xyz() + par*first_der;
  return GPoint(res[0], res[1], res[2], this, par);
}

SVector3 LinearSeamEdge::firstDer(double par) const
{
  return first_der;
}

GEntity::GeomType LinearSeamEdge::geomType() const
{
  return Line;
}

double LinearSeamEdge::curvature(double par) const
{
  return 0.;
}

bool LinearSeamEdge::is3D() const
{
  return false;
}

bool LinearSeamEdge::degenerate(int) const
{
  return false;
}

GPoint LinearSeamEdge::closestPoint(const SPoint3 &q, double &t) const
{
  return GEdge::closestPoint(q,t);
}
