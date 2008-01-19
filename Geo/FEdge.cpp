#include "FEdge.h"
#include "Context.h"

extern Context_T CTX;

#if defined(HAVE_FOURIER_MODEL)

FEdge::FEdge(GModel *model, FM::TopoEdge* edge_, int tag, GVertex *v0, GVertex *v1) 
  : GEdge(model, tag, v0, v1), edge(edge_) 
{
  //meshAttributes.Method = TRANSFINI; 
  //meshAttributes.coeffTransfinite = 1.;
  //meshAttributes.nbPointsTransfinite = 10;
}

Range<double> FEdge::parBounds(int i) const
{ 
  return(Range<double>(0.,1.));
}

GPoint FEdge::point(double p) const 
{
  double x, y, z;
  edge->F(p,x,y,z);

  return GPoint(x,y,z);
}

double FEdge::parFromPoint(const SPoint3 &pt) const
{
  double p;
  edge->Inverse(pt.x(),pt.y(),pt.z(),p);

  return p;
}

SVector3 FEdge::firstDer(double par) const
{
  double x,y,z;
  edge->Dfdt(par,x,y,z);
  return SVector3(x,y,z);
}

int FEdge::minimumMeshSegments() const
{
  if(geomType() == Line || geomType() == Unknown)
    return GEdge::minimumMeshSegments();
  else
    return 2; // always put at least one mid-point on non-straight lines
}

int FEdge::minimumDrawSegments() const
{
  int n = GEdge::minimumDrawSegments();

  if(geomType() == Line)
    return n;
  else if(geomType() == Circle || geomType() == Ellipse)
    return CTX.geom.circle_points;
  else
    return 20 * n;
}

#endif
