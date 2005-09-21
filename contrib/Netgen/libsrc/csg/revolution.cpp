#include <mystdlib.h>

#include <linalg.hpp>
#include <csg.hpp>

namespace netgen
{

#ifdef NONE

Revolution :: Revolution (const Point<3> & ap1, const Point<3> & ap2)
{
  p1 = ap1;
  p2 = ap2;
  v12 = p2 - p1;
  v12.Normalize();
}

Revolution :: ~Revolution ()
{
  ;
}

Primitive * Revolution :: CreateDefault ()
{
  return new Revolution( Point<3> (0, 0, 0),
			 Point<3> (1, 0, 0));
}

INSOLID_TYPE Revolution :: BoxInSolid (const BoxSphere<3> & box) const
{
  int i;

  Vec<3> v = box.Center() - p1;
  double x = v * v12;
  double y = sqrt (v.Length2() - x*x);
  
  Point<2> lp1, lp2;
  for (i = 1; i <= polygon.GetNP(); i++)
    {
      polygon.GetLine (i, lp1, lp2);

      double dist2 = MinDistLP2 (lp1, lp2, Point<2>(x,y));
      if (dist2 < sqr (box.Diam()))
	return DOES_INTERSECT;
    };

  return PointInSolid (box.Center(), 1e-3 * box.Diam());
}


INSOLID_TYPE Revolution :: PointInSolid (const Point<3> & p,
					 double eps) const
{
  int i, cnt;

  Vec<3> v(p1, p);
  double x = v * v12;
  double y = sqrt (v.Length2() - x*x);
  
  if (polygon.IsOn (Point<2> (x, y)))
    return DOES_INTERSECT;
  if (polygon.IsIn (Point<2> (x, y)))
    return IS_INSIDE;
  else
    return IS_OUTSIDE;
}



INSOLID_TYPE Revolution :: VecInSolid (const Point<3> & p,
				      const Vec<3> & v,
				      double eps) const
{
  Point<3> p2 = p + (1e-3/(v.Length()+1e-16)) * v;
  return PointInSolid (p2, eps);
}


void Revolution :: GetPrimitiveData (char *& classname, 
				    ARRAY<double> & coeffs) const
{
  classname = "Revolution";
  coeffs.SetSize(0);
  coeffs.Append (polygon.GetNP());
}

void Revolution :: SetPrimitiveData (ARRAY<double> & coeffs)
{
  ;
}

void Revolution :: Reduce (const BoxSphere<3> & box)
{
  int i;

  for (i = 1; i <= polygon.GetNP(); i++)
    surfaceactive.Elem (i) = 0;


  Vec<3> v = box.Center() - p1;
  double x = v * v12;
  double y = sqrt (v.Length2() - x*x);

  Point<2> lp1, lp2;
  for (i = 1; i <= polygon.GetNP(); i++)
    {
      polygon.GetLine (i, lp1, lp2);

      double dist2 = MinDistLP2 (lp1, lp2, Point<2>(x,y));
      if (dist2 < sqr (box.Diam()/2))
	surfaceactive.Elem(i) = 1;
    };
}

void Revolution :: UnReduce ()
{
  for (int i = 0; i < polygon.GetNP(); i++)
    surfaceactive[i] = 1;
}


int Revolution :: AddPoint (const Point<2> & p)
{
  polygon.AddPoint (p);
  return polygon.GetNP();
}

void Revolution :: Finish ()
{
  int i;
  Point<2> lp1, lp2;
  Point<3> cp1, cp2;

  for (i = 1; i <= polygon.GetNP(); i++)
    {
      polygon.GetLine (i, lp1, lp2);
      cp1 = p1 + lp1.X() * v12;
      cp2 = p1 + lp2.X() * v12;
      
      faces.Append (new Cone (cp1, cp2,
			      fabs (lp1.Y()), 
			      fabs (lp2.Y())));

      invsurf.Append (lp1.X() < lp2.X());
    }
}


#endif
}
