// $Id: OCCFace.cpp,v 1.3 2006-11-15 14:35:03 remacle Exp $
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
// Please report all bugs and problems to <OCC@geuz.org>.

#ifdef _HAVE_OCC_
#include "GModel.h"
#include "OCCVertex.h"
#include "OCCEdge.h"
#include "OCCFace.h"
#include "Message.h"

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
	  l_edges.push_back(e);
	  l_wire.push_back(e);
	  e->addFace(this);
	}      
      if (l_wire.size() == 1)l_dirs.push_back(1);
      else
	{
	  GVertex *last;
	  std::list<GEdge*>::iterator it = l_wire.begin();
	  GEdge *e1 = *it;
	  ++it;
	  GEdge *e2 = *it;

	  if (e1->getEndVertex() == e2->getEndVertex() ||e1->getEndVertex() == e2->getBeginVertex())
	    {
	      last = e1->getEndVertex();
	      l_dirs.push_back(1);
	      Msg(INFO,"OCC Face %d - Edge %d (%d,%d) dir 1",num,e1->tag(),e1->getBeginVertex()->tag(),e1->getEndVertex()->tag());
	    }
	  else if (e1->getBeginVertex() == e2->getEndVertex() ||e1->getBeginVertex() == e2->getBeginVertex())
	    {
	      last = e1->getBeginVertex();
	      l_dirs.push_back(-1);
	      Msg(INFO,"OCC Face %d - Edge %d (%d,%d) dir -1",num,e1->tag(),e1->getBeginVertex()->tag(),e1->getEndVertex()->tag());
	    }
	  for ( ; it != l_wire.end() ; ++it)
	    {
	      GEdge *e = *it;
	      if ( last == e->getBeginVertex())
		{
		  l_dirs.push_back(1);
		  last = e->getEndVertex();
		  Msg(INFO,"OCC Face %d - Edge %d (%d,%d) dir 1",num,e->tag(),e->getBeginVertex()->tag(),e->getEndVertex()->tag());
		}
	      else if (last == e->getEndVertex())
		{
		  l_dirs.push_back(-1);
		  last = e->getBeginVertex();
		  Msg(INFO,"OCC Face %d - Edge %d (%d,%d) dir -1",num,e->tag(),e->getBeginVertex()->tag(),e->getEndVertex()->tag());
		}
	      else
		{
		  Msg(GERROR,"Incoherent surface %d",num);
		}
	    }
	}      
    }

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
  pnt = proj.NearestPoint();
  double pp[2];
  proj.LowerDistanceParameters (pp[0], pp[1]);
  return SPoint2(pp[0],pp[1]);
}

GEntity::GeomType OCCFace::geomType() const
{
  return Unknown;
}

int OCCFace::containsPoint(const SPoint3 &pt) const
{ 
  Msg(GERROR,"Not Done Yet ...");
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
