#include "Message.h"
#include "FEdge.h"

#if defined(HAVE_FOURIER_MODEL)

Range<double> FEdge::parBounds(int i) const
{ 
  return(Range<double>(0.,1.));
}

GPoint FEdge::point(double p) const 
{
  double x, y, z;
  if (edge)
    edge->F(p,x,y,z);
  else {
    if (edgeNum == 0) {
      double p0, p1, q0, q1;
      face->Inverse(v0->x(),v0->y(),v0->z(),p0,q0);
      face->Inverse(v1->x(),v1->y(),v1->z(),p1,q1);
      face->F(p0+p*(p1-p0),0,x,y,z);
    }
    else if (edgeNum == 1) {
      double p0, p1, q0, q1;
      face->Inverse(v0->x(),v0->y(),v0->z(),q0,p0);
      face->Inverse(v1->x(),v1->y(),v1->z(),q1,p1);
      face->F(1.,p0+p*(p1-p0),x,y,z);
    }
    else if (edgeNum == 2) {
      double p0, p1, q0, q1;
      face->Inverse(v0->x(),v0->y(),v0->z(),p0,q0);
      face->Inverse(v1->x(),v1->y(),v1->z(),p1,q1);
      face->F(p0+p*(p1-p0),1.,x,y,z);
    }
    else if (edgeNum == 3) {
      double p0, p1, q0, q1;
      face->Inverse(v0->x(),v0->y(),v0->z(),q0,p0);
      face->Inverse(v1->x(),v1->y(),v1->z(),q1,p1);
      face->F(0.,p0+p*(p1-p0),x,y,z);
    }
    else
      Msg(INFO,"Invalid edge number.");
  }
  return GPoint(x,y,z);
}

double FEdge::parFromPoint(const SPoint3 &pt) const
{
  double p;
  if (edge)
    edge->Inverse(pt.x(),pt.y(),pt.z(),p);
  else {
    if ((edgeNum == 0) || (edgeNum == 2)) {
      double p0, p1, q0, q1, q;
      face->Inverse(v0->x(),v0->y(),v0->z(),p0,q0);
      face->Inverse(v1->x(),v1->y(),v1->z(),p1,q1);
      face->Inverse(pt.x(),pt.y(),pt.z(),p,q);
      p = p0 + p * (p1 - p0);
    }
    else if ((edgeNum == 1) || (edgeNum == 3)) {
      double p0, p1, q0, q1, q;
      face->Inverse(v0->x(),v0->y(),v0->z(),q0,p0);
      face->Inverse(v1->x(),v1->y(),v1->z(),q1,p1);
      face->Inverse(pt.x(),pt.y(),pt.z(),q,p);
      p = p0 + p * (p1 - p0);
    }
    else
      Msg(INFO,"Invalid edge number.");
  }
  return p;
}

#endif
