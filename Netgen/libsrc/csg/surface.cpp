#include <mystdlib.h>

#include <myadt.hpp>
#include <csg.hpp>

#include <linalg.hpp>
#include <meshing.hpp>


namespace netgen
{
Surface :: Surface ()
{
  maxh = 1e10;
  name = new char[7];
  strcpy (name, "noname");
  bcprop = -1;
}

Surface :: ~Surface()
{
  delete [] name;
}


void Surface :: SetName (const char * aname)
{
  delete [] name;
  name = new char[strlen (aname)+1];
  strcpy (name, aname);
}


int Surface :: PointOnSurface (const Point<3> & p,
			       double eps) const
{
  double val = CalcFunctionValue (p);
  return fabs (val) < eps;
}


void Surface :: CalcHesse (const Point<3> & point, Mat<3> & hesse) const
{
  double dx = 1e-5;
  Point<3> hp1, hp2;
  Vec<3> g1, g2;

  for (int i = 0; i < 3; i++)
    {
      hp1 = point;
      hp2 = point;

      hp1(i) += dx;
      hp2(i) -= dx;

      CalcGradient (hp1, g1);
      CalcGradient (hp2, g2);
      	
      for (int j = 0; j < 3; j++)
	hesse(i, j) = (g1(j) - g2(j)) / (2 * dx);
    }
}
  
void Surface :: GetNormalVector (const Point<3> & p, Vec<3> & n) const
{
  CalcGradient (p, n);
  n.Normalize();
  //  if (Inverse()) n *= -1;
}

void Surface :: DefineTangentialPlane (const Point<3> & ap1, 
				       const Point<3> & ap2)
{
  p1 = ap1;
  p2 = ap2;
  
  GetNormalVector (p1, ez);
  ex = p2 - p1;
  ex -= (ex * ez) * ez;
  ex.Normalize();
  ey = Cross (ez, ex);  
}

void Surface :: ToPlane (const Point<3> & p3d, Point<2> & pplane, 
			 double h, int & zone) const
{
  Vec<3> p1p, n;

  GetNormalVector (p3d, n);
  if (n * ez < 0)
    {
      zone = -1;
      pplane(0) = 1e8;
      pplane(1) = 1e9;
      return;
    }
  
  p1p = p3d - p1;
  pplane(0) = (p1p * ex) / h;
  pplane(1) = (p1p * ey) / h;
  zone = 0;
}	

void Surface :: FromPlane (const Point<2> & pplane, 
			   Point<3> & p3d, double h) const 
{ 
  p3d = p1 
    + (h * pplane(0)) * ex 
    + (h * pplane(1)) * ey;
  
  Project (p3d);
}

void Surface :: Project (Point<3> & p) const
{
  Vec<3> n;
  double val;

  for (int i = 1; i <= 10; i++)
    {
      val = CalcFunctionValue (p);
      if (fabs (val) < 1e-12) return;
	
      CalcGradient (p, n);
      p -= (val / Abs2 (n)) * n;
    }
}

double Surface :: MaxCurvature () const
{ 
  return 0.5 * HesseNorm (); 
}

double Surface :: 
MaxCurvatureLoc (const Point<3> & /* c */ , double /* rad */) const
{ 
  return MaxCurvature (); 
}
              


double Surface :: LocH (const Point<3> & p, double x, 
			double c, double hmax) const
  // finds h <= hmax, s.t.  h * \kappa_x*h < c
{
  /*
    double h, hmin, kappa;
    hmin = 0;
  
    while (hmin < 0.9 * hmax)
    {
    h = 0.5 * (hmin + hmax);
    kappa = 2 * MaxCurvatureLoc (p, x * h);
      
    if (kappa * h >= c)
    hmax = h;
    else
    hmin = h;
    }
    return h;
  */

  double hret;
  double kappa = MaxCurvatureLoc (p, x*hmax);

  kappa *= c *  mparam.curvaturesafety;
  
  if (hmax * kappa < 1)
    hret = hmax;
  else
    hret = 1 / kappa;

  if (maxh < hret)
    hret = maxh;

  return hret;
}




Primitive :: Primitive ()
{
  surfaceids.SetSize (1);
  surfaceactive.SetSize (1);
  surfaceactive[0] = 1;
}

Primitive :: ~Primitive()
{
  ;
}

int Primitive :: GetSurfaceId (int i) const
{
  return surfaceids[i];
}

void Primitive :: SetSurfaceId (int i, int id) 
{
  surfaceids[i] = id;
}




void Primitive :: GetPrimitiveData (char *& classname, 
				    ARRAY<double> & coeffs) const
{
  classname = "undef";
  coeffs.SetSize (0);
}

void Primitive :: SetPrimitiveData (ARRAY<double> & coeffs)
{
  ;
}

Primitive * Primitive :: CreatePrimitive (const char * classname)
{
  if (strcmp (classname, "sphere") == 0)
    return Sphere::CreateDefault();
  if (strcmp (classname, "plane") == 0)
    return Plane::CreateDefault();
  if (strcmp (classname, "cylinder") == 0)
    return Cylinder::CreateDefault();
  if (strcmp (classname, "cone") == 0)
    return Cone::CreateDefault();
  if (strcmp (classname, "brick") == 0)
    return Brick::CreateDefault();

  cout << "cannot create primitive " << classname << endl;
  return NULL;
}


Primitive * Primitive :: Copy () const
{
  cout << "Primitive called for baseclass" << endl;
  return NULL;
}


void Primitive :: Transform (Transformation<3> & trans)
{
  cout << "transform called for baseclass" << endl;
}


INSOLID_TYPE Primitive :: 
VecInSolid2 (const Point<3> & p,
	     const Vec<3> & v1,
	     const Vec<3> & v2,
	     double eps) const
{
  Point<3> hp = p + 1e-3 * v1 + 1e-5 * v2;
  return PointInSolid (hp, eps);
}






OneSurfacePrimitive :: OneSurfacePrimitive()
{
  ;
}

OneSurfacePrimitive :: ~OneSurfacePrimitive()
{
  ;
}


INSOLID_TYPE OneSurfacePrimitive :: 
PointInSolid (const Point<3> & p,
	      double eps) const
{
  double hv1 = (GetSurface(0).CalcFunctionValue(p));
  if (hv1 <= -eps)
    return IS_INSIDE;
  if (hv1 >= eps)
    return IS_OUTSIDE;
  return DOES_INTERSECT;
}
 
INSOLID_TYPE OneSurfacePrimitive :: 
VecInSolid (const Point<3> & p, const Vec<3> & v,
	    double eps) const
{
  Vec<3> hv;
  double hv1;
  GetSurface(0).CalcGradient (p, hv);

  hv1 = v * hv;

  if (hv1 <= -eps)
    return IS_INSIDE;
  if (hv1 >= eps)
    return IS_OUTSIDE;

  return DOES_INTERSECT;
}


INSOLID_TYPE OneSurfacePrimitive :: 
VecInSolid2 (const Point<3> & p,
	     const Vec<3> & v1,
	     const Vec<3> & v2,
	     double eps) const
{
  Vec<3> hv;
  double hv1, hv2;

  GetSurface(0).CalcGradient (p, hv);

  hv1 = v1 * hv;
  if (hv1 <= -eps)
    return IS_INSIDE;
  if (hv1 >= eps)
    return IS_OUTSIDE;

  hv2 = v2 * hv;
  if (hv2 <= 0)
    return IS_INSIDE;
  else
    return IS_OUTSIDE;
}
  



int OneSurfacePrimitive :: GetNSurfaces() const
{
  return 1;
}

Surface & OneSurfacePrimitive :: GetSurface (int i)
{
  return *this;
}

const Surface & OneSurfacePrimitive :: GetSurface (int i) const
{
  return *this;
}






void ProjectToEdge (const Surface * f1, const Surface * f2, Point<3> & hp)
{
  Vec<2> rs, lam;
  Vec<3> a1, a2;
  Mat<2> a;

  int i = 10;
  while (i > 0)
    {
      i--;
      rs(0) = f1 -> CalcFunctionValue (hp);
      rs(1) = f2 -> CalcFunctionValue (hp);
      f1->CalcGradient (hp, a1);
      f2->CalcGradient (hp, a2);

      a(0,0) = a1 * a1;
      a(0,1) = a(1,0) = a1 * a2;
      a(1,1) = a2 * a2;

      a.Solve (rs, lam);

      hp -= lam(0) * a1 + lam(1) * a2;

      if (Abs2 (rs) < 1e-24 && i > 1) i = 1;
    }
}
}
