#include "FEdge.h"

#if defined(HAVE_FOURIER_MODEL)

Range<double> FEdge::parBounds(int i) const
{ 
  return(Range<double>(0.,1.));
}

GPoint FEdge::point(double p) const 
{
  double x, y, z;

  edge->F(p,x,y,z);
  return GPoint(x,y,z);
}

double FEdge::parFromPoint(const SPoint3 &pt) const
{
  double t;
  edge->Inverse(pt.x(),pt.y(),pt.z(),t);
  return t;
}

#endif
