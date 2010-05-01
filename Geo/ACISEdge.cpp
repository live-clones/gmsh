// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <limits>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "GModel.h"
#include "ACISEdge.h"
#include "Context.h"

#if defined(HAVE_ACIS)

#include <interval.hxx>
#include <curve.hxx>
#include <curdef.hxx>

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
  
  SPAinterval interval = _e->get_param_range (); 
  s0 = interval.start_pt();
  s1 = interval.end_pt();
}

Range<double> ACISEdge::parBounds(int i) const
{ 
  return Range<double>(s0, s1);
}

SPoint2 ACISEdge::reparamOnFace(const GFace *face, double epar, int dir) const
{
  throw;
}

GPoint ACISEdge::closestPoint(const SPoint3 &qp, double &param) const{
  throw;
}


// True if the edge is a seam for the given face
bool ACISEdge::isSeam(const GFace *face) const
{
  throw;
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
  return SVector3(0,0,0);
}

GEntity::GeomType ACISEdge::geomType() const
{
  return Unknown;
}

int ACISEdge::minimumMeshSegments() const
{
  return GEdge::minimumMeshSegments();
}

int ACISEdge::minimumDrawSegments() const
{
  return GEdge::minimumDrawSegments();
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
