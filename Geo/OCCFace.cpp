// $Id: OCCFace.cpp,v 1.16 2006-11-29 16:57:01 remacle Exp $
//
// Copyright (C) 1997-2007 C. Geuzaine, J.-F. Remacle
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

#include "GModel.h"
#include "GEdgeLoop.h"
#include "OCCVertex.h"
#include "OCCEdge.h"
#include "OCCFace.h"
#include "Message.h"
#include "Numeric.h"

#if defined(HAVE_OCC)
#include "Geom_CylindricalSurface.hxx"
#include "Geom_ConicalSurface.hxx"
#include "Geom_BSplineSurface.hxx"
#include "Geom_SphericalSurface.hxx"
#include "Geom_Plane.hxx"
#include "gp_Pln.hxx"

OCCFace::OCCFace(GModel *m, TopoDS_Face _s, int num, TopTools_IndexedMapOfShape &emap)
  : GFace(m, num), s(_s)
{
  TopExp_Explorer exp0, exp01, exp1, exp2, exp3;
  for (exp2.Init (s, TopAbs_WIRE); exp2.More(); exp2.Next())
    {
      TopoDS_Shape wire = exp2.Current();
      Msg(INFO,"OCC Face %d - New Wire",num);
      std::list<GEdge*> l_wire;
      for (exp3.Init (wire, TopAbs_EDGE); exp3.More(); exp3.Next())
	{	  
	  TopoDS_Edge edge = TopoDS::Edge (exp3.Current());
	  int index = emap.FindIndex(edge);
	  GEdge *e = m->edgeByTag(index);
	  if(!e) throw;
	  l_wire.push_back(e);
	  e->addFace(this);
	  if (!e->is3D())
	    {
	      OCCEdge *occe = (OCCEdge*)e;
	      occe->setTrimmed(this);
	    }
	}      

      GEdgeLoop el (l_wire);

      for (GEdgeLoop::citer it = el.begin() ; it != el.end() ; ++it)
	{
	  l_edges.push_back(it->ge);
	  l_dirs.push_back(it->_sign);
	}
      
      edgeLoops.push_back(el);
    }
  BRepAdaptor_Surface surface( s );
  _periodic[0] = surface.IsUPeriodic();
  _periodic[1] = surface.IsVPeriodic();
// 	      surface.IsVPeriodic()

  Msg(INFO,"OCC Face %d with %d edges",num,l_edges.size());
  ShapeAnalysis::GetFaceUVBounds (s, umin, umax, vmin, vmax);
  // we do that for the projections to converge on the 
  // borders of the surface
  umin -= fabs(umax-umin)/100.0;
  vmin -= fabs(vmax-vmin)/100.0;
  umax += fabs(umax-umin)/100.0;
  vmax += fabs(vmax-vmin)/100.0;
  occface = BRep_Tool::Surface(s);
}

Range<double> OCCFace::parBounds(int i) const
{  
  double umin2, umax2, vmin2, vmax2;

  ShapeAnalysis::GetFaceUVBounds (s, umin2, umax2, vmin2, vmax2);
  if (i==0)
    return Range<double>(umin2, umax2);
  return Range<double>(vmin2, vmax2);
}

SVector3 OCCFace::normal(const SPoint2 &param) const
{
  gp_Pnt pnt;
  gp_Vec du, dv;

  occface->D1(param.x(), param.y(),pnt,du,dv);

  SVector3 t1 (du.X(),du.Y(),du.Z());
  SVector3 t2 (dv.X(),dv.Y(),dv.Z());
  SVector3 n ( crossprod (t1,t2));
  n.normalize();
  if (s.Orientation() == TopAbs_REVERSED) return n*(-1.);  
  return n;  
}

Pair<SVector3,SVector3> OCCFace::firstDer(const SPoint2 &param) const
{
  gp_Pnt pnt;
  gp_Vec du, dv;
  occface->D1(param.x(), param.y(),pnt,du,dv);

  return Pair<SVector3,SVector3>(SVector3(du.X(), du.Y(), du.Z()),
				 SVector3(dv.X(), dv.Y(), dv.Z()));
}

GPoint OCCFace::point(const SPoint2 &pt) const
{   
  return point(pt.x(), pt.y()); 
}

GPoint OCCFace::point(double par1, double par2) const
{
  double pp[2] = {par1,par2};
  gp_Pnt val = occface->Value (par1, par2);
  return GPoint(val.X(),val.Y(),val.Z(), this, pp);
}

GPoint OCCFace::closestPoint(const SPoint3 & qp) const
{
  gp_Pnt pnt(qp.x(),qp.y(),qp.z());
  GeomAPI_ProjectPointOnSurf proj(pnt, occface, umin, umax, vmin, vmax);
  if (!proj.NbPoints())
    Msg(GERROR,"OCC Project Point on Surface FAIL");

  pnt = proj.NearestPoint();
  double pp[2];
  proj.LowerDistanceParameters (pp[0], pp[1]);
  return GPoint(pnt.X(),pnt.Y(),pnt.Z(), this, pp);
}

int OCCFace::containsParam(const SPoint2 &pt) const
{
  Range<double> uu = parBounds(0);
  Range<double> vv = parBounds(1);
  if((pt.x() >= uu.low() && pt.x() <= uu.high()) && 
     (pt.y() >= vv.low() && pt.y() <= vv.high()))
    return 1;
  else 
    return 0;
}

SPoint2 OCCFace::parFromPoint(const SPoint3 &qp) const
{
  gp_Pnt pnt(qp.x(),qp.y(),qp.z());
  GeomAPI_ProjectPointOnSurf proj(pnt, occface, umin, umax, vmin, vmax);
  if (!proj.NbPoints())
    {
      Msg(GERROR,"OCC Project Point on Surface FAIL");
      return GFace::parFromPoint(qp);
    }   
  double U,V;
  proj.LowerDistanceParameters (U, V);
  return SPoint2(U,V);
}

GEntity::GeomType OCCFace::geomType() const
{
  if (occface->DynamicType() == STANDARD_TYPE(Geom_Plane))
    return Plane;
  else if (occface->DynamicType() == STANDARD_TYPE(Geom_CylindricalSurface))
    return Cylinder;
  else if (occface->DynamicType() == STANDARD_TYPE(Geom_ConicalSurface))
    return Cone;
   else if (occface->DynamicType() == STANDARD_TYPE(Geom_SphericalSurface))
     return Sphere;
   else if (occface->DynamicType() == STANDARD_TYPE(Geom_BSplineSurface))
     return BSplineSurface;
  return Unknown;
}


double OCCFace::curvature (const SPoint2 &param) const
{
  const double eps = 1.e-12;
  BRepAdaptor_Surface sf(s, Standard_True);
  BRepLProp_SLProps prop(sf, 2, eps);
  prop.SetParameters (param.x(),param.y());

  if (!prop.IsCurvatureDefined())
    {
      return eps;
    }
  return std::max(fabs(prop.MinCurvature()), fabs(prop.MaxCurvature()));
}


int OCCFace::containsPoint(const SPoint3 &pt) const
{ 
  if(geomType() == Plane)
    {
      gp_Pln pl = Handle(Geom_Plane)::DownCast(occface)->Pln();

      // OK to use the normal from the mean plane here: we compensate
      // for the (possibly wrong) orientation at the end
      double n[3] , c;
      pl.Coefficients ( n[0], n[1], n[2], c );
      norme(n);
      double angle = 0.;
      double v[3] = {pt.x(), pt.y(), pt.z()};
      for(std::list<GEdge*>::const_iterator  it = l_edges.begin(); it != l_edges.end(); it++) {
	GEdge *c = *it;
	int N=10;
	Range<double> range = c->parBounds(0);
	for(int j = 0; j < N ; j++) {
	  double u1 = (double)j / (double)N;
	  double u2 = (double)(j + 1) / (double)N;
	  GPoint pp1 = c->point(range.low() + u1 * (range.high() - range.low() ));
	  GPoint pp2 = c->point(range.low() + u2 * (range.high() - range.low() ));
	  double v1[3] = {pp1.x(), pp1.y(), pp1.z()};
	  double v2[3] = {pp2.x(), pp2.y(), pp2.z()};
	  angle += angle_plan(v, v1, v2, n);
	}
      }
      // we're inside if angle equals 2 * pi
      if(fabs(angle) > 2 * M_PI - 0.5 && fabs(angle) < 2 * M_PI + 0.5) 
	return true;
      return false;
    }
  else
    Msg(GERROR,"Not Done Yet ...");
  return false;
}
// void OCCFace::buildVisTriangulation ();
// {
//   TopLoc_Location loc;
//   Handle(Poly_Triangulation) triangulation = BRep_Tool::Triangulation (occface, loc);
//   int ntriangles = triangulation -> NbTriangles();
//   for (int j = 1; j <= ntriangles; j++)
//     {
//       Poly_Triangle triangle = (triangulation -> Triangles())(j);
//     }  
// }

#endif
