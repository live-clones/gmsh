#include "gmshModel.h"
#include "gmshEdge.h"
#include "gmshFace.h"
#include "Interpolation.h"
#include "CAD.h"
#include "Geo.h"
#include "Mesh.h"
#include "Create.h"
#include "Utils.h"

extern Mesh *THEM;

gmshFace::gmshFace(GModel *m, Surface *face)
  : GFace(m, face->Num), s(face)
{
  for (int i=0 ; i < List_Nbr(s->Generatrices) ; i++){
    Curve *c;
    List_Read(s->Generatrices, i, &c);
    GEdge *e = m->edgeByTag(abs(c->Num));
    if(!e) throw;
    l_edges.push_back(e);
    e->addFace(this);
    if(c->Num > 0) l_dirs.push_back(1);
    else l_dirs.push_back(-1);
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

int gmshFace::paramDegeneracies(int dir, double *par)
{
  return 0;
}

SBoundingBox3d gmshFace::bounds() const
{
  std::list<GEdge*>::const_iterator it = l_edges.begin();
  SBoundingBox3d res = (*it)->bounds();
  ++it;
  while (it != l_edges.end())
    {
      res += (*it)->bounds();  
      ++it;
    }
  return res;
}

SVector3 gmshFace::normal(const SPoint2 &param) const
{
  Vertex vu = InterpolateSurface(s, param[0], param[1], 1, 1);
  Vertex vv = InterpolateSurface(s, param[0], param[1], 1, 2);
  Vertex n = vu % vv;
  n.norme();
  return SVector3(n.Pos.X, n.Pos.Y, n.Pos.Z);
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
  return point(pt.x(),pt.y()); 
}


void computePlaneDatas (const GFace *gf, double VX[3],double VY[3],double &x, double &y, double &z)
{
  VX[0] = gf->mp.plan[0][0];
  VX[1] = gf->mp.plan[0][1];
  VX[2] = gf->mp.plan[0][2];
  VY[0] = gf->mp.plan[1][0];
  VY[1] = gf->mp.plan[1][1];
  VY[2] = gf->mp.plan[1][2];
  x=gf->mp.x;  
  y=gf->mp.y;  
  z=gf->mp.z;  
}


GPoint gmshFace::point(double par1,double par2) const
{
  double pp[2]={par1,par2};
  if(s->Typ == MSH_SURF_PLAN){
    double x,y,z,VX[3],VY[3];
    computePlaneDatas (this,VX,VY,x,y,z);
    return GPoint( x + VX[0] * par1 + VY[0] * par2,
		   y + VX[1] * par1 + VY[1] * par2,
		   z + VX[2] * par1 + VY[2] * par2, this,pp);
  }
  else{
    Vertex v = InterpolateSurface( s, par1, par2,0,0);
    return GPoint(v.Pos.X,v.Pos.Y,v.Pos.Z,this,pp);
  }
}

GPoint gmshFace::closestPoint(const SPoint3 & qp)
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
  if ((pt.x()>=uu.low() && pt.x()<=uu.high()) && (pt.y()>=vv.low() && pt.y()<=vv.high()))
     return 1;
  else 
     return 0;
}


SPoint2 gmshFace::parFromPoint(const SPoint3 &qp) const
{
  double u,v;
  if (s->Typ == MSH_SURF_PLAN){
    double x,y,z,VX[3],VY[3];
    computePlaneDatas (this,VX,VY,x,y,z);
    double vec[3] = {qp.x()-x,qp.y()-y,qp.z()-z};
    prosca(vec,VX,&u);
    prosca(vec,VY,&v);
  }
  else{
    XYZtoUV(s, qp.x(), qp.y(), qp.z(), &u, &v, 1.0);
  }
  SPoint2 pt2(u,v); 
  return pt2;
}

bool gmshFace::continuous(int dim) const
{ 
  return true;
}

bool gmshFace::periodic(int dim) const
{ 
  return false;
}

bool gmshFace::degenerate(int dim) const
{ 
  return false;
}

GEntity::GeomType gmshFace::geomType() const
{
  switch(s->Typ){
  case MSH_SURF_NURBS: return Nurb;
  case MSH_SURF_PLAN: return Plane;
  case MSH_SURF_DISCRETE: return DiscreteSurface;
  default: return Unknown;
  }
}

int gmshFace::geomDirection() const
{
  return 1;
}

void * gmshFace::getNativePtr() const
{ 
  return s; 
}

int gmshFace::containsPoint(const SPoint3 &pt) const
{ 
  throw;
}
