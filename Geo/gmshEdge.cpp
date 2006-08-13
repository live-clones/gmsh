#include "gmshModel.h"
#include "gmshEdge.h"
#include "Interpolation.h"
#include "CAD.h"
#include "Geo.h"
#include "Mesh.h"
#include "Create.h"
#include "Context.h"

extern Context_T CTX;
extern Mesh *THEM;

gmshEdge::gmshEdge(GModel *model, Curve *edge, GVertex *v1, GVertex *v2)
  : GEdge(model, edge->Num, v1, v2), c(edge)
{
}

gmshEdge::gmshEdge(GModel *model, int num)
  : GEdge(model, num, 0, 0)
{
  c = Create_Curve(num, MSH_SEGM_DISCRETE, 0, NULL, NULL, -1, -1, 0., 1.);
  Tree_Add(THEM->Curves, &c);
  CreateReversedCurve(THEM, c);
}

gmshEdge::~gmshEdge()
{
}

Range<double> gmshEdge::parBounds(int i) const
{ 
  return(Range<double>(c->ubeg, c->uend));
}

SBoundingBox3d gmshEdge::bounds() const
{
  SBoundingBox3d bbox;
  const int N = 10;
  for (int i = 0; i < N; i++){
    double u = c->ubeg + (double)i/(double)(N - 1) * (c->uend - c->ubeg);
    Vertex a = InterpolateCurve(c, u, 0);
    bbox += SPoint3(a.Pos.X, a.Pos.Y, a.Pos.Z);
  }
  return bbox;
}

GPoint gmshEdge::point(double par) const
{
  Vertex a = InterpolateCurve(c, par, 0);
  return GPoint(a.Pos.X,a.Pos.Y,a.Pos.Z,this,par);
}

GPoint gmshEdge::closestPoint(const SPoint3 & qp)
{
  Vertex v;
  Vertex a;
  Vertex der;
  v.Pos.X = qp.x();
  v.Pos.Y = qp.y();
  v.Pos.Z = qp.z();
  ProjectPointOnCurve (c, &v, &a, &der);
  return GPoint(a.Pos.X, a.Pos.Y, a.Pos.Z, this, a.u);
}

int gmshEdge::containsParam(double pt) const
{
  Range<double> rg = parBounds(0);
  return (pt >= rg.low() && pt <= rg.high());
}

SVector3 gmshEdge::firstDer(double par) const
{
  if(!c) return SVector3(0., 0., 0.);
  Vertex a = InterpolateCurve(c, par, 1);
  return SVector3(a.Pos.X, a.Pos.Y, a.Pos.Z);
}

double gmshEdge::parFromPoint(const SPoint3 &pt) const
{
  Vertex v;
  Vertex a;
  Vertex der;
  v.Pos.X = pt.x();
  v.Pos.Y = pt.y();
  v.Pos.Z = pt.z();
  ProjectPointOnCurve(c, &v, &a, &der);
  return a.u;
}

bool gmshEdge::continuous(int) const
{ 
  return true;
}

bool gmshEdge::degenerate(int) const
{ 
  return false;
}

bool gmshEdge::periodic(int dim) const
{
  return false;
}


GEntity::GeomType gmshEdge::geomType() const
{
  switch (c->Typ){
  case MSH_SEGM_LINE : return Line;
  case MSH_SEGM_PARAMETRIC : return ParametricCurve;
  case MSH_SEGM_CIRC :  
  case MSH_SEGM_CIRC_INV : return Circle;
  case MSH_SEGM_ELLI:
  case MSH_SEGM_ELLI_INV: return Ellipse;
  case MSH_SEGM_BSPLN:
  case MSH_SEGM_BEZIER: 
  case MSH_SEGM_NURBS:
  case MSH_SEGM_SPLN: return Nurb; 
  case MSH_SEGM_DISCRETE: return DiscreteCurve; 
  default : return Unknown;
  }
}


void * gmshEdge::getNativePtr() const
{ 
  return c;
}

int gmshEdge::containsPoint(const SPoint3 &pt) const
{ 
  throw;
}

int gmshEdge::minimumMeshSegments () const
{
  if(geomType() == Circle || geomType() == Ellipse)
    return (int)(fabs(c->Circle.t1 - c->Circle.t2) *
		 (double)CTX.mesh.min_circ_points / Pi) - 1;
  else
    return GEdge::minimumMeshSegments () ;
}

int gmshEdge::minimumDrawSegments () const
{
  int n = List_Nbr(c->Control_Points) - 1;
  if(!n) n = GEdge::minimumDrawSegments();

  if(geomType() == Line)
    return n;
  else if(geomType() == Circle || geomType() == Ellipse)
    return CTX.geom.circle_points;
  else
    return 10 * n;
}
