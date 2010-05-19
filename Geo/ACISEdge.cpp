// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <limits>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "GModel.h"
#include "ACISEdge.h"
#include "ACISFace.h"
#include "Context.h"

#if defined(HAVE_ACIS)

#include <interval.hxx>
#include <curve.hxx>
#include <curdef.hxx>
#include <intrapi.hxx>
#include <coedge.hxx>
#include <loop.hxx>
#include <surdef.hxx>

GEdge *getACISEdgeByNativePtr(GModel *model, EDGE * toFind)
{
  GModel::eiter it =model->firstEdge();
  for (; it !=model->lastEdge(); it++){
    ACISEdge *ed = dynamic_cast<ACISEdge*>(*it);
    if (ed){
      if (toFind == ed->getEDGE()){
	return *it;
      }
    }
  }
  return 0;
}


ACISEdge::ACISEdge(GModel *model, EDGE* edge, int num, GVertex *v1, GVertex *v2)
  : GEdge(model, num, v1, v2), _e(edge)
{
  CURVE *_cur = _e->geometry();
  //  SPAinterval interval=_cur->equation().param_range(); 
  SPAinterval interval=_e->param_range(); 
  s0 = interval.start_pt();
  s1 = interval.end_pt();
  if (_cur->equation().periodic()){
    //    s0 += _cur->equation().param_period()/2;
    //    s1 += _cur->equation().param_period()/2;
  }
  Msg::Info("ACIS Edge %d is %s goes from %g to %g",tag(),getTypeString().c_str(),s0,s1);


}

Range<double> ACISEdge::parBounds(int i) const
{ 
  return Range<double>(s0, s1);
}

SPoint2 ACISEdge::reparamOnFace(const GFace *face, double epar, int dir) const
{
  CURVE *c = _e->geometry();
  SPAposition vpos = c->equation().eval_position(epar);
  SPApar_pos fpar = ((FACE*)(face->getNativePtr()))->geometry()->equation().param(vpos);
  SPoint2 pt2(fpar.u, fpar.v);
  face->moveToValidRange(pt2);
  return pt2;
}

GPoint ACISEdge::closestPoint(const SPoint3 &qp, double &param) const{
  throw;
}


// True if the edge is a seam for the given face
bool ACISEdge::isSeam(const GFace *face) const
{
  CURVE *_cur = _e->geometry();
  if (!(((FACE*)face->getNativePtr())->geometry()->equation().periodic_u()) && 
      !(((FACE*)face->getNativePtr())->geometry()->equation().periodic_v()))
      return 0;
  else if ( (((FACE*)face->getNativePtr())->geometry()->equation().periodic_u()) && 
           !(((FACE*)face->getNativePtr())->geometry()->equation().periodic_v()))
  {
     SPAinterval cur_rang = _cur->equation().param_range();
     SPAinterval sur_rang_u = ((FACE*)face->getNativePtr())->geometry()->equation().param_range_u();
     SPAposition p1, p2;
     p1 = _cur->equation().eval_position(cur_rang.start_pt());
     p2 = _cur->equation().eval_position(cur_rang.end_pt());
     SPApar_pos p1_par, p2_par;
     p1_par = ((FACE*)face->getNativePtr())->geometry()->equation().param(p1);
     p2_par = ((FACE*)face->getNativePtr())->geometry()->equation().param(p2);
  
    if(((p1_par.u == sur_rang_u.start_pt()  || p1_par.u == sur_rang_u.end_pt()) && 
        (p2_par.u == sur_rang_u.start_pt()  || p2_par.u == sur_rang_u.end_pt())))
        return 1;
     else
        return 0;
  }
  else if (!(((FACE*)face->getNativePtr())->geometry()->equation().periodic_u()) && 
            (((FACE*)face->getNativePtr())->geometry()->equation().periodic_v()))
  {
     SPAinterval cur_rang = _cur->equation().param_range();
     SPAinterval sur_rang_v = ((FACE*)face->getNativePtr())->geometry()->equation().param_range_v();
     SPAposition p1, p2;
     p1 = _cur->equation().eval_position(cur_rang.start_pt());
     p2 = _cur->equation().eval_position(cur_rang.end_pt());
     SPApar_pos p1_par, p2_par;
     p1_par = ((FACE*)face->getNativePtr())->geometry()->equation().param(p1);
     p2_par = ((FACE*)face->getNativePtr())->geometry()->equation().param(p2);
  
    if(((p1_par.v == sur_rang_v.start_pt()  || p1_par.v == sur_rang_v.end_pt()) && 
        (p2_par.v == sur_rang_v.start_pt()  || p2_par.v == sur_rang_v.end_pt())) )
        return 1;
     else
        return 0;
  }
  else if ((((FACE*)face->getNativePtr())->geometry()->equation().periodic_u()) && 
           (((FACE*)face->getNativePtr())->geometry()->equation().periodic_v()))
  {
     SPAinterval cur_rang = _cur->equation().param_range();
     SPAinterval sur_rang_u = ((FACE*)face->getNativePtr())->geometry()->equation().param_range_u();
     SPAinterval sur_rang_v = ((FACE*)face->getNativePtr())->geometry()->equation().param_range_v();
     SPAposition p1, p2;
     p1 = _cur->equation().eval_position(cur_rang.start_pt());
     p2 = _cur->equation().eval_position(cur_rang.end_pt());
     SPApar_pos p1_par, p2_par;
     p1_par = ((FACE*)face->getNativePtr())->geometry()->equation().param(p1);
     p2_par = ((FACE*)face->getNativePtr())->geometry()->equation().param(p2);
  
     if ( ((p1_par.u == sur_rang_u.start_pt()  || p1_par.u == sur_rang_u.end_pt()) && 
        (p2_par.u == sur_rang_u.start_pt()  || p2_par.u == sur_rang_u.end_pt())) ||
       ((p1_par.v == sur_rang_v.start_pt()  || p1_par.v == sur_rang_v.end_pt()) && 
        (p2_par.v == sur_rang_v.start_pt()  || p2_par.v == sur_rang_v.end_pt())) )
        return 1;
     else
        return 0;
  }
}

bool ACISEdge::degenerate(int) const{
  return _e->length() == 0.0;
}


GPoint ACISEdge::point(double par) const
{
  CURVE *c = _e->geometry();
  const curve &equ = c->equation();
  if (&equ){
    SPAposition pos;
    equ.eval(par,pos);
    return GPoint(pos.coordinate(0),pos.coordinate(1),pos.coordinate(2),this,par);
  }
  Msg::Error("Unable to evaluate a point on a curve");
  return GPoint(0,0,0,this,par);  
}

SVector3 ACISEdge::firstDer(double par) const
{  
  CURVE *c = _e->geometry();
  const curve &equ = c->equation();
  SPAvector first_deriv;
  SPAposition pos;
  equ.eval (par, pos,first_deriv);
  return SVector3(first_deriv.component(0),first_deriv.component(1),first_deriv.component(2));
}

GEntity::GeomType ACISEdge::geomType() const
{
  CURVE *c = _e->geometry();
  if (!strcmp(c->type_name(),"circle"))return Circle;
  if (!strcmp(c->type_name(),"straight"))return Line;
  if (!strcmp(c->type_name(),"ellipse"))return Ellipse;
  if (!strcmp(c->type_name(),"bezier"))return Bezier;
  return Unknown;
}

int ACISEdge::minimumMeshSegments() const
{
  int np;
  if(geomType() == Line)
    np = GEdge::minimumMeshSegments();
  else 
    np = CTX::instance()->mesh.minCurvPoints - 1;
  
  // if the edge is closed, ensure that at least 3 points are
  // generated in the 1D mesh (4 segments, one of which is
  // degenerated)
  if (getBeginVertex() == getEndVertex()) np = std::max(4, np);

  return std::max(np, meshAttributes.minimumMeshSegments);
}

int ACISEdge::minimumDrawSegments() const
{
  if(geomType() == Line)
    return GEdge::minimumDrawSegments();
  else
    return CTX::instance()->geom.numSubEdges * GEdge::minimumDrawSegments();
}

double ACISEdge::curvature(double par) const 
{
  const double Crv = 1.e-15;
  return Crv;
}

void ACISEdge::writeGEO(FILE *fp)
{
}

#endif
