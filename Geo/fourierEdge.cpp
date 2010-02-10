// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "GmshConfig.h"
#include "fourierEdge.h"
#include "Context.h"

#if defined(HAVE_FOURIER_MODEL)

fourierEdge::fourierEdge(GModel *model, FM::TopoEdge* edge_, int tag,
                         GVertex *v0, GVertex *v1) 
  : GEdge(model, tag, v0, v1), edge(edge_) 
{
}

Range<double> fourierEdge::parBounds(int i) const
{ 
  return(Range<double>(0.,1.));
}

GPoint fourierEdge::point(double p) const 
{
  double x, y, z;
  edge->F(p,x,y,z);
  return GPoint(x,y,z);
}

SVector3 fourierEdge::firstDer(double par) const
{
  double x,y,z;
  edge->Dfdt(par,x,y,z);
  return SVector3(x,y,z);
}

int fourierEdge::minimumMeshSegments() const
{
  if(geomType() == Line || geomType() == Unknown)
    return GEdge::minimumMeshSegments();
  else
    return 2; // always put at least one mid-point on non-straight lines
}

int fourierEdge::minimumDrawSegments() const
{
  int n = GEdge::minimumDrawSegments();

  if(geomType() == Line)
    return n;
  else
    return CTX::instance()->geom.numSubEdges * n;
}

#endif
