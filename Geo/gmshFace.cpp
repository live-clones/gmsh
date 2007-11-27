// $Id: gmshFace.cpp,v 1.43 2007-11-27 16:45:27 geuzaine Exp $
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
#include "gmshVertex.h"
#include "gmshEdge.h"
#include "gmshFace.h"
#include "Geo.h"
#include "GeoInterpolation.h"
#include "Numeric.h"
#include "Message.h"

gmshFace::gmshFace(GModel *m, Surface *face)
  : GFace(m, face->Num), s(face)
{
  for(int i = 0 ; i < List_Nbr(s->Generatrices); i++){
    Curve *c;
    List_Read(s->Generatrices, i, &c);
    GEdge *e = m->edgeByTag(abs(c->Num));
    if(e){
      l_edges.push_back(e);
      e->addFace(this);
      l_dirs.push_back((c->Num > 0) ? 1 : -1);
    }
    else
      Msg(GERROR, "Unknown curve %d", c->Num);
  }

  // always compute and store the mean plane for plane surfaces
  // (simply using the bounding vertices)
  if(s->Typ == MSH_SURF_PLAN){
    computeMeanPlane();
    for(int i = 0; i < 3; i++)
      for(int j = 0; j < 3; j++)
	s->plan[i][j] = meanPlane.plan[i][j];
    s->a = meanPlane.a;
    s->b = meanPlane.b;
    s->c = meanPlane.c;
    s->d = meanPlane.d;
  }
  
  if(s->EmbeddedCurves){
    for(int i = 0 ; i < List_Nbr(s->EmbeddedCurves); i++){
      Curve *c;
      List_Read(s->EmbeddedCurves, i, &c);
      GEdge *e = m->edgeByTag(abs(c->Num));
      if(e)
	embedded_edges.push_back(e);
      else
	Msg(GERROR, "Unknown curve %d", c->Num);
    }
  }
  if(s->EmbeddedPoints){
    for(int i = 0 ; i < List_Nbr(s->EmbeddedPoints); i++){
      Vertex *v;
      List_Read(s->EmbeddedPoints, i, &v);
      GVertex *gv = m->vertexByTag(v->Num);
      if(gv)
	embedded_vertices.push_back(gv);
      else
	Msg(GERROR, "Unknown point %d", v->Num);
    }
  }
  //  face->print_info();

  resetMeshAttributes();
}


double gmshFace::getMetricEigenvalue ( const SPoint2 &pt) 
{
  if(!s->geometry)return 1;
  return s->geometry->getMetricEigenvalue (pt) ;
}

gmshFace::gmshFace(GModel *m, int num)
  : GFace(m, num)
{
  s = Create_Surface(num, MSH_SURF_DISCRETE);
  Tree_Add(m->getGEOInternals()->Surfaces, &s);
  meshStatistics.status = GFace::DONE;
}

void gmshFace::setModelEdges(std::list<GEdge*>&ed)
{
  for (std::list<GEdge*>::iterator it = ed.begin(); it!=ed.end() ; ++it)
    {
      l_edges.push_back(*it);
      (*it)->addFace(this);
      l_dirs.push_back( 1 );
    }
}

void gmshFace::resetMeshAttributes()
{
  meshAttributes.recombine = s->Recombine;
  meshAttributes.recombineAngle = s->RecombineAngle;
  meshAttributes.Method = s->Method;
  meshAttributes.extrude = s->Extrude;
  if(meshAttributes.Method == TRANSFINI){
    meshAttributes.transfiniteArrangement = s->Recombine_Dir;
    meshAttributes.corners.clear();
    for(int i = 0; i < List_Nbr(s->TrsfPoints); i++){
      Vertex *corn;
      List_Read(s->TrsfPoints, i, &corn);
      GVertex *gv = model()->vertexByTag(corn->Num);
      if(gv)
	meshAttributes.corners.push_back(gv);
      else
	Msg(GERROR, "Unknown vertex %d in transfinite attributes", corn->Num);
    }
  }
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
    // We cannot use InterpolateSurface() for plane surfaces since it
    // relies on the mean plane, which does not respect the
    // orientation

    // FIXME: move this test at the end of the MeanPlane computation
    // routine--and store the correct normal, damn it!

    double n[3] = {meanPlane.a, meanPlane.b, meanPlane.c};
    norme(n);
    double angle = 0.;
    GPoint pt = point(param.x(), param.y());
    double v[3] = {pt.x(), pt.y(), pt.z()};
    for(int i = 0; i < List_Nbr(s->Generatrices); i++) {
      Curve *c;
      List_Read(s->Generatrices, i, &c);
      int N = (c->Typ == MSH_SEGM_LINE) ? 1 : 3;
      for(int j = 0; j < N; j++) {
	double u1 = (double)j / (double)N;
	double u2 = (double)(j + 1) / (double)N;
	Vertex p1 = InterpolateCurve(c, u1, 0);
	Vertex p2 = InterpolateCurve(c, u2, 0);
	double v1[3] = {p1.Pos.X, p1.Pos.Y, p1.Pos.Z};
	double v2[3] = {p2.Pos.X, p2.Pos.Y, p2.Pos.Z};
	angle += angle_plan(v, v1, v2, n);
      }
    }
    if(angle > 0)
      return SVector3(n[0], n[1], n[2]);
    else
      return SVector3(-n[0], -n[1], -n[2]);
  }
}

Pair<SVector3,SVector3> gmshFace::firstDer(const SPoint2 &param) const
{
  Vertex vu = InterpolateSurface(s, param[0], param[1], 1, 1);
  Vertex vv = InterpolateSurface(s, param[0], param[1], 1, 2);
  return Pair<SVector3,SVector3>(SVector3(vu.Pos.X, vu.Pos.Y, vu.Pos.Z),
				 SVector3(vv.Pos.X, vv.Pos.Y, vv.Pos.Z));
}

GPoint gmshFace::point(double par1, double par2) const
{
  double pp[2] = {par1, par2};
  if(s->Typ == MSH_SURF_PLAN && !s->geometry){
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
  double u[2];
  v.Pos.X = qp.x();
  v.Pos.Y = qp.y();
  v.Pos.Z = qp.z();
  ProjectPointOnSurface(s, v, u);
  return GPoint(v.Pos.X, v.Pos.Y, v.Pos.Z, this, u);
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
    double x, y, z, VX[3], VY[3];
    getMeanPlaneData(VX, VY, x, y, z);
    double u, v, vec[3] = {qp.x()-x, qp.y()-y, qp.z()-z};
    prosca(vec, VX, &u);
    prosca(vec, VY, &v);
    return SPoint2(u, v); 
  }
  else{
    return GFace::parFromPoint(qp);
  }
}

GEntity::GeomType gmshFace::geomType() const
{
  switch(s->Typ){
  case MSH_SURF_PLAN: return Plane;
  case MSH_SURF_REGL:
  case MSH_SURF_TRIC: return RuledSurface;
  case MSH_SURF_DISCRETE: return DiscreteSurface;
  case MSH_SURF_BND_LAYER: return BoundaryLayerSurface;
  default: return Unknown;
  }
}

int gmshFace::containsPoint(const SPoint3 &pt) const
{ 
  if(geomType() == Plane){
    // OK to use the normal from the mean plane here: we compensate
    // for the (possibly wrong) orientation at the end
    double n[3] = {meanPlane.a, meanPlane.b, meanPlane.c};
    norme(n);
    double angle = 0.;
    double v[3] = {pt.x(), pt.y(), pt.z()};
    for(int i = 0; i < List_Nbr(s->Generatrices); i++) {
      Curve *c;
      List_Read(s->Generatrices, i, &c);
      int N = (c->Typ == MSH_SEGM_LINE) ? 1 : 10;
      for(int j = 0; j < N; j++) {
	double u1 = (double)j / (double)N;
	double u2 = (double)(j + 1) / (double)N;
	Vertex p1 = InterpolateCurve(c, u1, 0);
	Vertex p2 = InterpolateCurve(c, u2, 0);
	double v1[3] = {p1.Pos.X, p1.Pos.Y, p1.Pos.Z};
	double v2[3] = {p2.Pos.X, p2.Pos.Y, p2.Pos.Z};
	angle += angle_plan(v, v1, v2, n);
      }
    }
    // we're inside if angle equals 2 * pi
    if(fabs(angle) > 2 * M_PI - 0.5 && fabs(angle) < 2 * M_PI + 0.5) 
      return true;
    return false;
  }

  return false;
}
