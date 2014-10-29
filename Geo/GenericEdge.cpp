// Gmsh - Copyright (C) 1997-2014 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

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

GenericEdge::GenericEdge(GModel *m, int num, int _native_id, GVertex *v1, GVertex *v2)
  : GEdge(m, num, v1, v2), id(_native_id)
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
  vector<double> res(2,0.);
  if (!EdgeReparamOnFace) Msg::Error("GenericEdge::ERROR: Callback EdgeReparamOnFace not set");
  bool ok = EdgeReparamOnFace(id,face->getNativeInt(),par, dir,res);
  if (!ok) Msg::Error("GenericEdge::ERROR from EdgeReparamOnFace ! " );
  return SPoint2(res[0],res[1]);;
}

GPoint GenericEdge::closestPoint(const SPoint3 &qp, double &param) const
{
  vector<double> queryPoint(3,0.);
  for (int i=0;i<3;i++) queryPoint[i] = qp[i];
  vector<double> res(3,0.);
  bool is_on_edge;
  if (!EdgeClosestPoint) Msg::Error("GenericEdge::ERROR: Callback EdgeClosestPoint not set");
  bool ok = EdgeClosestPoint(id,queryPoint,param,res,is_on_edge);
  if (!ok) Msg::Error("GenericEdge::ERROR from EdgeClosestPoint ! " );
  if (!is_on_edge) Msg::Warning("WARNING:GenericEdge::closestPoint closest point NOT on edge, out of bounds ! " );
  return GPoint(res[0], res[1], res[2], this, param);
}

// True if the edge is a seam for the given face
bool GenericEdge::isSeam(const GFace *face) const
{
  Msg::Error("GenericEdge::isSeam: not implemented yet ! ");
  return false;
}

GPoint GenericEdge::point(double par) const
{
  vector<double> res(3,0.);
  if (!EdgeEvalXYZFromT) Msg::Error("GenericEdge::ERROR: Callback EdgeEvalXYZFromT not set");
  bool ok = EdgeEvalXYZFromT(id,par,res);
  if (!ok) Msg::Error("GenericEdge::ERROR from EdgeEvalXYZFromT ! " );
  return GPoint(res[0], res[1], res[2], this, par);
}

SVector3 GenericEdge::firstDer(double par) const
{
  vector<double> res(3,0.);
  if (!EdgeEvalFirstDer) Msg::Error("GenericEdge::ERROR: Callback EdgeEvalFirstDer not set");
  bool ok = EdgeEvalFirstDer(id,par,res);
  if (!ok) Msg::Error("GenericEdge::ERROR from EdgeEvalFirstDer ! " );
  return SVector3(res[0],res[1],res[2]);
}

GEntity::GeomType GenericEdge::geomType() const
{
  string s;
  if (!EdgeGeomType) Msg::Error("GenericEdge::ERROR: Callback EdgeGeomType not set");
  bool ok = EdgeGeomType(id,s);
  if (!ok){
    Msg::Error("GenericEdge::ERROR from EdgeGeomType ! " );
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

  Msg::Warning("GenericEdge::geomType:: unknown type from callback: ", s.c_str());

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
  bool res;
  if (!EdgeDegenerated) Msg::Error("GenericEdge::ERROR: Callback EdgeDegenerated not set");
  bool ok = EdgeDegenerated(id,res);
  if (!ok) Msg::Error("GenericEdge::ERROR from EdgeDegenerated ! " );
  return res;
}
