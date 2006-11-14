// $Id: OCCEdge.cpp,v 1.1 2006-11-14 17:11:33 remacle Exp $
//
// Copyright (C) 1997-2006 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.

#ifdef _HAVE_OCC_
#include "GModel.h"
#include "OCCEdge.h"

OCCEdge::OCCEdge(GModel *model, TopoDS_Edge edge, int num, GVertex *v1, GVertex *v2)
  : GEdge(model, num, v1, v2), c(edge)
{
  curve = BRep_Tool::Curve(edge, s0, s1);
}

Range<double> OCCEdge::parBounds(int i) const
{ 
  double a,b;
  BRep_Tool::Range (c,a,b); 
  return(Range<double>(a,b));
}

GPoint OCCEdge::point(double par) const
{
  gp_Pnt pnt = curve->Value (par);
  return GPoint(pnt.X(),pnt.Y(),pnt.Z());
}

GPoint OCCEdge::closestPoint(const SPoint3 & qp)
{
  throw;
}

int OCCEdge::containsParam(double pt) const
{
  Range<double> rg = parBounds(0);
  return (pt >= rg.low() && pt <= rg.high());
}

SVector3 OCCEdge::firstDer(double par) const
{
  
  BRepAdaptor_Curve brepc(c);
  BRepLProp_CLProps prop(brepc, 1, 1e-5);
  prop.SetParameter (par);
  gp_Vec d1 = prop.D1();
  return SVector3(d1.X(), d1.Y(), d1.Z());
}

double OCCEdge::parFromPoint(const SPoint3 &pt) const
{
  throw;
}

GEntity::GeomType OCCEdge::geomType() const
{
  return Unknown;
}

int OCCEdge::minimumMeshSegments () const
{
  return GEdge::minimumMeshSegments () ;
}

int OCCEdge::minimumDrawSegments () const
{
  return CTX.geom.circle_points;
}
#endif
