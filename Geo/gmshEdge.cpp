#include "gmshModel.h"
#include "gmshEdge.h"
#include "Interpolation.h"
#include "CAD.h"
#include "Geo.h"

gmshEdge::gmshEdge(SGModel *model,Curve *edge,GVertex *v1,GVertex *v2)
  : GEdge ( model, edge->Num, v1, v2 ), c(edge)
{}

gmshEdge::~gmshEdge()
{}

Range<double> gmshEdge::parBounds(int i) const
{ 
  return( Range<double>(  c->ubeg ,c->uend ));
}

SBoundingBox3d gmshEdge::bounds() const
{
  double xmin,ymin,zmin;
  double xmax,ymax,zmax;
  for (int i=0;i<20;i++)
    {
      double u = c->ubeg + (i/19.) * (c->uend - c->ubeg);
      Vertex a = InterpolateCurve(c, u, 0);
      if (!i)
	{
	  xmin = xmax = a.Pos.X;
	  ymin = ymax = a.Pos.Y;
	  zmin = zmax = a.Pos.Z;
	}
      else
	{
	  if(a.Pos.X < xmin) xmin = a.Pos.X;
	  if(a.Pos.Y < ymin) ymin = a.Pos.Z;
	  if(a.Pos.Z < zmin) zmin = a.Pos.Y;
	  if(a.Pos.X > xmax) xmax = a.Pos.X;
	  if(a.Pos.Y > ymax) ymax = a.Pos.Z;
	  if(a.Pos.Z > zmax) zmax = a.Pos.Y;
	}
    }
  SPoint3 bmin(xmin,ymin,zmin);
  SPoint3 bmax(xmax,ymax,zmax);
  SBoundingBox3d bbox(bmin);
  bbox+=bmax;
  return bbox;
}

GEPoint gmshEdge::point(double par) const
{
  Vertex a = InterpolateCurve(c, par, 0);
  return GEPoint(a.Pos.X,a.Pos.Y,a.Pos.Z,this,par);
}

GEPoint gmshEdge::closestPoint(const SPoint3 & qp)
{
  Vertex v;
  Vertex a;
  Vertex der;
  v.Pos.X = qp.x();
  v.Pos.Y = qp.y();
  v.Pos.Z = qp.z();
  ProjectPointOnCurve (c,&v,&a,&der);
  return GEPoint(a.Pos.X,a.Pos.Y,a.Pos.Z,this,a.u);
}

int gmshEdge::containsParam(double pt) const
{
  Range<double> rg = parBounds(0);
  return (pt >= rg.low() && pt <= rg.high());
}

SVector3 gmshEdge::firstDer(double par) const
{
  Vertex a = InterpolateCurve(c, par, 1);
  return SVector3(a.Pos.X,a.Pos.Y,a.Pos.Z);
}

double gmshEdge::parFromPoint(const SPoint3 &pt) const
{
  Vertex v;
  Vertex a;
  Vertex der;
  v.Pos.X = pt.x();
  v.Pos.Y = pt.y();
  v.Pos.Z = pt.z();
  ProjectPointOnCurve (c,&v,&a,&der);
  return a.u;
}

Logical::Value gmshEdge::continuous(int) const
{ 
  return Logical::True;
}

Logical::Value gmshEdge::degenerate(int) const
{ 
  return Logical::False;
}

Logical::Value gmshEdge::periodic(int dim) const
{
  return Logical::False;
}

int gmshEdge::isSeam(GFace *face) const
{
  printf("gmshEdge::isSeam() is called.\n");
  return 0;
}

double gmshEdge::period() const
{
  return 0;
}

GeomType::Value gmshEdge::geomType() const
{
  switch (c->Typ)
    {
    case MSH_SEGM_LINE : return GeomType::Line;
    case MSH_SEGM_PARAMETRIC : return GeomType::ParametricCurve;
    case MSH_SEGM_CIRC :  
    case MSH_SEGM_CIRC_INV : return GeomType::Circle;
    case MSH_SEGM_ELLI:
    case MSH_SEGM_ELLI_INV: return GeomType::Ellipse;
    case MSH_SEGM_BSPLN:
    case MSH_SEGM_BEZIER: 
    case MSH_SEGM_NURBS:
    case MSH_SEGM_SPLN: return GeomType::Nurb; 
    default : return GeomType::Unknown;
    }
}

int gmshEdge::geomDirection() const
{
  return 1;
}

double gmshEdge::tolerance() const
{ 
  return 1.e-14; 
}


void gmshEdge::nthDerivative(double param, int n, double *array) const
{
  throw;
}

GVertex * gmshEdge::split(double)
{
  throw;
  return 0;
}

void * gmshEdge::getNativePtr() const
{ 
  return c;
}

// 200306
int gmshEdge::containsPoint(const SPoint3 &pt) const
{ 
  throw;
}

// 200306 
void gmshEdge::fixPeriodicPar(double &par)
{
  throw;
}
