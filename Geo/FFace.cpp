#include "FVertex.h"
#include "FFace.h"

#if defined(HAVE_FOURIER_MODEL)

FFace::FFace(GModel *m, FM_Face *face_, int tag) : GFace(m,tag), face(face_) 
{
  int curCorner = 0;
  for (int i=0;i<face->GetNumEdges();i++) {
    GVertex* p0 = new FVertex(m,curCorner,face->GetEdge(i)->GetStartPoint());
    curCorner = (curCorner + 1) % face->GetNumEdges();
    GVertex* p1 = new FVertex(m,curCorner,face->GetEdge(i)->GetEndPoint());
    l_edges.push_back(new FEdge(m,face->GetEdge(i),i,p0,p1));
    l_dirs.push_back(1);
  }
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

#endif
