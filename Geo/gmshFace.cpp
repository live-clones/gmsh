// $Id: gmshFace.cpp,v 1.21 2006-11-14 20:20:18 remacle Exp $
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

#include "GModel.h"
#include "gmshVertex.h"
#include "gmshEdge.h"
#include "gmshFace.h"
#include "Interpolation.h"
#include "CAD.h"
#include "Geo.h"
#include "Mesh.h"
#include "Create.h"
#include "Utils.h"
#include "Message.h"

extern Mesh *THEM;

gmshFace::gmshFace(GModel *m, Surface *face)
  : GFace(m, face->Num), s(face)
{
  for(int i = 0 ; i < List_Nbr(s->Generatrices); i++){
    Curve *c;
    List_Read(s->Generatrices, i, &c);
    GEdge *e = m->edgeByTag(abs(c->Num));
    if(!e) throw;
    l_edges.push_back(e);
    e->addFace(this);
    if(c->Num > 0) l_dirs.push_back(1);
    else l_dirs.push_back(-1);
  }
  // always compute and store the mean plane for plane surfaces
  // (simply using the bounding vertices)
  if(s->Typ == MSH_SURF_PLAN) computeMeanPlane();

  if(s->EmbeddedCurves){
    for(int i = 0 ; i < List_Nbr(s->EmbeddedCurves); i++){
      Curve *c;
      List_Read(s->EmbeddedCurves, i, &c);
      GEdge *e = m->edgeByTag(abs(c->Num));
      if(!e) throw;
      embedded_edges.push_back(e);
    }
  }
  if(s->EmbeddedPoints){
    for(int i = 0 ; i < List_Nbr(s->EmbeddedPoints); i++){
      Vertex *v;
      List_Read(s->EmbeddedPoints, i, &v);
      GVertex *gv = m->vertexByTag(v->Num);
      if(!gv) throw;
      embedded_vertices.push_back(gv);
    }
  }

  meshAttributes.recombine = s->Recombine;
  meshAttributes.recombineAngle = s->RecombineAngle;
  meshAttributes.Method = s->Method;
  if (s->Method == TRANSFINI)
    {
      meshAttributes.Method = s->Method;
      meshAttributes.transfiniteArrangement = s->Recombine_Dir;
      for (int i=0;i< List_Nbr(s->TrsfPoints);i++)
	{
	  Vertex *corn;
	  List_Read(s->TrsfPoints, i, &corn);
	  GVertex *gv = m->vertexByTag(corn->Num);
	  if(!gv) throw;
	  meshAttributes.corners.push_back(gv);
	}
    }
}

gmshFace::gmshFace(GModel *m, int num)
  : GFace(m, num)
{
  s = Create_Surface(num, MSH_SURF_DISCRETE);
  Tree_Add(THEM->Surfaces, &s);
}

Range<double> gmshFace::parBounds(int i) const
{ 
  return Range<double>(0, 1);
}

SVector3 gmshFace::normal(const SPoint2 &param) const
{
  if(geomType() != Plane){
    Vertex vu = InterpolateSurface(s, param[0], param[1], 1, 1);
    Vertex vv = InterpolateSurface(s, param[0], param[1], 1, 2);
    Vertex n = vu % vv;
    n.norme();
    return SVector3(n.Pos.X, n.Pos.Y, n.Pos.Z);
  }
  else{
    // We cannot use InterpolateSurface() for plane surfaces since
    // InterpolateSurface() relies on the mean plane, which does *not*
    // respect the orientation
    GPoint p = point(param);
    double t1[3], t2[3], n[3] = {0., 0., 0.};
    Curve *c;
    if(List_Nbr(s->Generatrices) > 1){
      List_Read(s->Generatrices, 0, &c);
      if(c->beg){
	t1[0] = p.x() - c->beg->Pos.X;
	t1[1] = p.y() - c->beg->Pos.Y;
	t1[2] = p.z() - c->beg->Pos.Z;
	// 1) try to get a point close to 'beg' on the same curve
	// 2) if we are unlucky and these two points are aligned with
	//    (x,y,z), which we know is inside or on the boundary of
	//    the surface, then get a point from the next edge
	// 3) repeat
	for(int i = 0; i < List_Nbr(s->Generatrices); i++){
	  List_Read(s->Generatrices, i, &c);
	  Vertex v = InterpolateCurve(c, 0.1, 0);
	  t2[0] = p.x() - v.Pos.X;
	  t2[1] = p.y() - v.Pos.Y;
	  t2[2] = p.z() - v.Pos.Z;
	  prodve(t1, t2, n);
	  if(norme(n))
	    break;
	}
      }
    }
    if(norme(n))
      return SVector3(n[0], n[1], n[2]);
    else{
      Msg(WARNING, "Using mean plane normal for surface %d", s->Num);
      return SVector3(meanPlane.a, meanPlane.b, meanPlane.c);
    }
  }
}

Pair<SVector3,SVector3> gmshFace::firstDer(const SPoint2 &param) const
{
  Vertex vu = InterpolateSurface(s, param[0], param[1], 1, 1);
  Vertex vv = InterpolateSurface(s, param[0], param[1], 1, 2);
  return Pair<SVector3,SVector3>(SVector3(vu.Pos.X, vu.Pos.Y, vu.Pos.Z),
				 SVector3(vv.Pos.X, vv.Pos.Y, vv.Pos.Z));
}

GPoint gmshFace::point(const SPoint2 &pt) const
{   
  return point(pt.x(), pt.y()); 
}

GPoint gmshFace::point(double par1, double par2) const
{
  double pp[2] = {par1, par2};
  if(s->Typ == MSH_SURF_PLAN){
    double x, y, z, VX[3], VY[3];
    getMeanPlaneData(VX, VY, x, y, z);
    return GPoint(x + VX[0] * par1 + VY[0] * par2,
		  y + VX[1] * par1 + VY[1] * par2,
		  z + VX[2] * par1 + VY[2] * par2, this, pp);
  }
  else{
    Vertex v = InterpolateSurface(s, par1, par2, 0, 0);
    return GPoint(v.Pos.X, v.Pos.Y, v.Pos.Z, this, pp);
  }
}

GPoint gmshFace::closestPoint(const SPoint3 & qp) const
{
  Vertex v;
  v.Pos.X = qp.x();
  v.Pos.Y = qp.y();
  v.Pos.Z = qp.z();

  if(s->Typ != MSH_SURF_PLAN)
    ProjectPointOnSurface(s, v);
  return GPoint(v.Pos.X, v.Pos.Y, v.Pos.Z, this, v.us);
}

int gmshFace::containsParam(const SPoint2 &pt) const
{
  Range<double> uu = parBounds(0);
  Range<double> vv = parBounds(1);
  if((pt.x() >= uu.low() && pt.x() <= uu.high()) && 
     (pt.y() >= vv.low() && pt.y() <= vv.high()))
    return 1;
  else 
    return 0;
}

SPoint2 gmshFace::parFromPoint(const SPoint3 &qp) const
{
  if(s->Typ == MSH_SURF_PLAN){
    double u,v;
    double x,y,z,VX[3],VY[3];
    getMeanPlaneData(VX, VY, x, y, z);
    double vec[3] = {qp.x()-x,qp.y()-y,qp.z()-z};
    prosca(vec,VX,&u);
    prosca(vec,VY,&v);
    return SPoint2(u, v); 
  }
  else{
    //    XYZtoUV(s, qp.x(), qp.y(), qp.z(), &u, &v, 1.0);
    return GFace::parFromPoint(qp);
  }
}

GEntity::GeomType gmshFace::geomType() const
{
  switch(s->Typ){
  case MSH_SURF_NURBS: return Nurb;
  case MSH_SURF_PLAN: return Plane;
  case MSH_SURF_REGL:
  case MSH_SURF_TRIC: return RuledSurface;
  case MSH_SURF_DISCRETE: return DiscreteSurface;
  default: return Unknown;
  }
}

int gmshFace::containsPoint(const SPoint3 &pt) const
{ 
  if(geomType() == Plane){
    // OK to use the normal from the mean plane here: we compensate
    // for the (possibly wrong) orientation at the end
    double n[3] = {meanPlane.a, meanPlane.b, meanPlane.c};
    double angle = 0.;
    Vertex v;
    v.Pos.X = pt.x();
    v.Pos.Y = pt.y();
    v.Pos.Z = pt.z();
    for(int i = 0; i < List_Nbr(s->Generatrices); i++) {
      Curve *c;
      List_Read(s->Generatrices, i, &c);
      int N = (c->Typ == MSH_SEGM_LINE) ? 1 : 10;
      for(int j = 0; j < N; j++) {
	double u1 = (double)j / (double)N;
	double u2 = (double)(j + 1) / (double)N;
	Vertex p1 = InterpolateCurve(c, u1, 0);
	Vertex p2 = InterpolateCurve(c, u2, 0);
	angle += angle_plan(&v, &p1, &p2, n);
      }
    }
    // we're inside if angle equals 2 * pi
    if(fabs(angle) > 2 * M_PI - 0.5 && fabs(angle) < 2 * M_PI + 0.5) 
      return true;
    return false;
  }
  else
    throw;
}
