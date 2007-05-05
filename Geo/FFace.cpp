#include <list>
#include "FVertex.h"
#include "FFace.h"
#include "Message.h"

#if defined(HAVE_FOURIER_MODEL)

FFace::FFace(GModel *m, FM_Face *face_, int tag) : GFace(m,tag), face(face_) 
{
  if (face->GetNumEdges()) {
    std::list<GVertex*> corners;
    std::list<GVertex*>::iterator itStart, itEnd;

    corners.push_back(new FVertex(m,0,face->GetEdge(0)->
				  GetStartPoint()));
    corners.push_back(new FVertex(m,1,face->GetEdge(1)->
				  GetStartPoint()));
    corners.push_back(new FVertex(m,2,face->GetEdge(2)->
				  GetStartPoint()));
    corners.push_back(new FVertex(m,3,face->GetEdge(3)->
				  GetStartPoint()));

    itStart = itEnd = corners.begin(); itEnd++;
    for (int i=0;i<face->GetNumEdges();i++) {
      l_edges.push_back(new FEdge(m,face->GetEdge(i),i,*itStart,*itEnd));
      l_dirs.push_back(1);      
      itStart++; itEnd++;
      if (itEnd == corners.end()) {
	itEnd = corners.begin();
      }
    }
    for (std::list<GEdge*>::iterator it = l_edges.begin();it != l_edges.end();
	 it++) {
      GVertex *start = (*it)->getBeginVertex();
      GVertex *end = (*it)->getEndVertex();
      Msg(INFO,"(%g,%g,%g) --- (%g,%g,%g)",start->x(),start->y(),start->z(),
	  end->x(),end->y(),end->z());
    }
  }
  else {
    double x,y,z;
    face->F(0.,0.,x,y,z);
    GVertex* p0 = new FVertex(m,0,new FM_Vertex(x,y,z));
    face->F(1.,0.,x,y,z);
    GVertex* p1 = new FVertex(m,1,new FM_Vertex(x,y,z));
    face->F(1.,1.,x,y,z);
    GVertex* p2 = new FVertex(m,2,new FM_Vertex(x,y,z));
    face->F(0.,1.,x,y,z);
    GVertex* p3 = new FVertex(m,3,new FM_Vertex(x,y,z));
    l_edges.push_back(new FEdge(m,face,0,0,p0,p1));
    l_edges.push_back(new FEdge(m,face,1,1,p1,p2));
    l_edges.push_back(new FEdge(m,face,2,2,p2,p3));
    l_edges.push_back(new FEdge(m,face,3,3,p3,p0));
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
