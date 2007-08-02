#include <list>
#include "FVertex.h"
#include "FFace.h"
#include "Message.h"

#if defined(HAVE_FOURIER_MODEL)

FFace::FFace(GModel *m, FM_Face *face_, int tag, std::list<GEdge*> l_edges_) 
  : GFace(m,tag), face(face_)
{
  for (std::list<GEdge*>::iterator it = l_edges_.begin();
       it != l_edges_.end(); it++) {
    l_edges.push_back((*it));
    l_dirs.push_back(1);   
  }
}

FFace::FFace(GModel *m, FM_Face *face_, int tag, std::list<GEdge*> l_edges_,
	     std::list<int> l_dirs_) : GFace(m,tag), face(face_)
{
  for (std::list<GEdge*>::iterator it = l_edges_.begin();
       it != l_edges_.end(); it++)
    l_edges.push_back((*it));  
  for (std::list<int>::iterator it = l_dirs_.begin();
       it != l_dirs_.end(); it++)
    l_dirs.push_back((*it));  
}

Range<double> FFace::parBounds(int i) const
{
  return Range<double>(0.,1.);
}

GPoint FFace::point(double par1, double par2) const
{
  double pp[2] = {par1,par2};
  double x,y,z;
  face->F(par1,par2,x,y,z);
  return GPoint(x, y, z, this, pp);
}

GPoint FFace::point(const SPoint2 &pt) const
{
  return point(pt[0], pt[1]);
}

SPoint2 FFace::parFromPoint(const SPoint3 &p) const
{
  double u, v, x, y, z;
  x = p.x(); y = p.y(); z = p.z();
  face->Inverse(x,y,z,u,v);

  return SPoint2(u, v);
}

GPoint FFace::closestPoint(const SPoint3 & queryPoint) const
{
  throw;
}

int FFace::containsPoint(const SPoint3 &pt) const
{
  throw;
}

int FFace::containsParam(const SPoint2 &pt) const
{
  const double tol = 1.e-6;
  if(pt[0] < 0. - tol || pt[0] > 1. + tol) return 0;
  if(pt[1] < 0. - tol || pt[1] > 1. + tol) return 0;
  return 1;
}

SVector3 FFace::normal(const SPoint2 &param) const
{
  double x,y,z;
  face->GetUnitNormal(param[0],param[1],x,y,z);
  return SVector3(x, y, z); 
}

GEntity::GeomType FFace::geomType() const
{
  return  GEntity::ParametricSurface;
}

bool FFace::surfPeriodic(int dim) const
{
  return face->IsPeriodic(dim);
}

double FFace::period(int dir) const
{
    return 1.;
}


#endif
