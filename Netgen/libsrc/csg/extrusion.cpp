#include <mystdlib.h>

#include <linalg.hpp>
#include <csg.hpp>

namespace netgen
{



  ExtrusionSurface :: ExtrusionSurface (const Point<3> & ap0,
					const Vec<3> & aex, 
					const Vec<3> & aey,
					BSplineCurve2d * acurve,
					int asegnr)
    : p0(ap0), ex(aex), ey(aey), curve(acurve), segnr(asegnr)
  {
    ;
  }
  
  ExtrusionSurface :: ~ExtrusionSurface ()
  {
    ;
  }

  void ExtrusionSurface :: DefineTangentialPlane (const Point<3> & ap1, 
						  const Point<3> & ap2)
  {
    ;
  }

  void ExtrusionSurface :: ToPlane (const Point<3> & p3d, Point<2> & pplane, 
				    double h, int & zone) const
  {
    ;
  }
  
  void ExtrusionSurface :: FromPlane (const Point<2> & pplane, 
				      Point<3> & p3d, double h) const
  {
    ;
  }
  

  void ExtrusionSurface :: Project (Point<3> & p) const
  {
    ;
  }


  double ExtrusionSurface :: CalcFunctionValue (const Point<3> & point) const
  {
    return 0;
  }

  void ExtrusionSurface :: CalcGradient (const Point<3> & point, Vec<3> & grad) const
  {
    ;
  }

  Point<3> ExtrusionSurface :: GetSurfacePoint () const
  {
    return Point<3> (0,0,0);
  }

  double ExtrusionSurface :: HesseNorm () const
  {
    return 1;
  }

  void ExtrusionSurface :: Print (ostream & str) const
  {
    ;
  }

  void ExtrusionSurface :: GetTriangleApproximation (TriangleApproximation & tas, 
						     const Box<3> & boundingbox, 
						     double facets) const
  {
    Point<2> p2d;
    Point<3> p;
    int n = int(facets)+1;
    Vec<3> ez = Cross (ex, ey);
    cout << "ex = " << ex << endl;
    cout << "ey = " << ey << endl;
    for (double t = 0; t < 1.0001; t += 1.0 / n)
      {
	cout << "t = " << t << endl;
	p2d = curve -> Eval (segnr+t);
	p = p0 + p2d(0) * ex + p2d(1) * ey;
	cout << "p2d = " << p2d << endl;
	cout << "add point " << p << endl;
	tas.AddPoint (p);
	tas.AddPoint (p + ez);
      }

    for (int i = 0; i < n; i++)
      {
	cout << "add trig " << endl;
	tas.AddTriangle (TATriangle (0, 2*i, 2*i+2, 2*i+1));
	tas.AddTriangle (TATriangle (0, 2*i+2, 2*i+3, 2*i+1));
      }
  }
  



Extrusion :: Extrusion (const Point<3> & ap0,
			const Vec<3> & aex, 
			const Vec<3> & aey,
			const ARRAY< Point<2> > & points)
  : p0(ap0), ex(aex), ey(aey)
{
  int i;
  
  ex.Normalize();
  ey -= (ex*ey) * ex;
  ey.Normalize();

  for (i = 0; i < points.Size(); i++)
    curve.AddPoint (points[i]);

  surfs.SetSize (points.Size()/2);
  for (i = 0; i < surfs.Size(); i++)
    surfs = new ExtrusionSurface (p0, ex, ey, &curve, i);
}

Extrusion :: ~Extrusion ()
{
  int i;
  for (i = 0; i < surfs.Size(); i++)
    delete surfs[i];
}
 

INSOLID_TYPE Extrusion :: BoxInSolid (const BoxSphere<3> & box) const
{
  Vec<3> p0c = box.Center() - p0;
  Point<2> p2d (ex*p0c, ey*p0c);
  double r = box.Diam() / 2;
  double dist;
  bool inside =
    curve.Inside (p2d, dist);

  if (inside && dist > r) return IS_INSIDE;
  if (!inside && dist > r) return IS_OUTSIDE;
  return DOES_INTERSECT;
}


INSOLID_TYPE Extrusion :: PointInSolid (const Point<3> & p,
					double eps) const
{
  Vec<3> p0c = p - p0;
  Point<2> p2d (ex*p0c, ey*p0c);
  double dist;
  bool inside =
    curve.Inside (p2d, dist);
  
  if (dist < eps) return DOES_INTERSECT;
  if (inside) return IS_INSIDE;
  return IS_OUTSIDE;
}


INSOLID_TYPE Extrusion :: VecInSolid (const Point<3> & p,
				      const Vec<3> & v,
				      double eps) const
{
  Point<3> p2 = p + (1e-3/(v.Length()+1e-16)) * v;
  return PointInSolid (p2, eps);
}


}
