#include <mystdlib.h>

#include <linalg.hpp>
#include <csg.hpp>

namespace netgen
{

Polyhedra::Face::Face (int pi1, int pi2, int pi3, const ARRAY<Point<3> > & points)
{
  pnums[0] = pi1;
  pnums[1] = pi2;
  pnums[2] = pi3;

  bbox.Set (points[pi1]);
  bbox.Add (points[pi2]);
  bbox.Add (points[pi3]);

  v1 = points[pi2] - points[pi1];
  v2 = points[pi3] - points[pi1];

  n = Cross (v1, v2);
  nn = n;
  nn.Normalize();
  //  PseudoInverse (v1, v2, w1, w2);
  
  Mat<2,3> mat;
  Mat<3,2> inv;
  for (int i = 0; i < 3; i++)
    {
      mat(0,i) = v1(i);
      mat(1,i) = v2(i);
    }
  CalcInverse (mat, inv);
  for (int i = 0; i < 3; i++)
    {
      w1(i) = inv(i,0);
      w2(i) = inv(i,1);
    }
}


Polyhedra :: Polyhedra ()
{
  surfaceactive.SetSize(0);
  surfaceids.SetSize(0);
}

Polyhedra :: ~Polyhedra ()
{
  ;
}

Primitive * Polyhedra :: CreateDefault ()
{
  return new Polyhedra();
}

INSOLID_TYPE Polyhedra :: BoxInSolid (const BoxSphere<3> & box) const
{
  /*
  for (i = 1; i <= faces.Size(); i++)
    if (FaceBoxIntersection (i, box))
      return DOES_INTERSECT;
  */
  for (int i = 0; i < faces.Size(); i++)
    {
      if (!faces[i].bbox.Intersect (box))
	continue;

      const Point<3> & p1 = points[faces[i].pnums[0]];
      const Point<3> & p2 = points[faces[i].pnums[1]];
      const Point<3> & p3 = points[faces[i].pnums[2]];

      if (fabs (faces[i].nn * (p1 - box.Center())) > box.Diam()/2)
	continue;

      double dist2 = MinDistTP2 (p1, p2, p3, box.Center());
      if (dist2 < sqr (box.Diam()/2))
	return DOES_INTERSECT;
    };

  return PointInSolid (box.Center(), 1e-3 * box.Diam());
}


INSOLID_TYPE Polyhedra :: PointInSolid (const Point<3> & p,
					double eps) const
{
  Vec<3> n, v1, v2;

  // random (?) numbers:
  n(0) = 0.123871;
  n(1) = 0.15432;
  n(2) = 0.43989;

  int cnt = 0;
  Point<3> pmeps (p(0) - eps, p(1) - eps, p(2) - eps);

  for (int i = 0; i < faces.Size(); i++)
    {
      const Point<3> & fpmax = faces[i].bbox.PMax();
      if (fpmax(0) < pmeps(0) ||
	  fpmax(1) < pmeps(1) ||
	  fpmax(2) < pmeps(2)) continue;

      const Point<3> & p1 = points[faces[i].pnums[0]];
      
      Vec<3> v0 = p - p1;
      double lam3 = -(faces[i].n * v0) / (faces[i].n * n);

      if (lam3 < -eps) continue;
      Vec<3> rs = v0 + lam3 * n;

      double lam1 = (faces[i].w1 * rs);
      double lam2 = (faces[i].w2 * rs);

      if (lam3 < eps)
	{
	  if (lam1 >= -eps && lam2 >= -eps && lam1+lam2 <= 1+eps)
	    return DOES_INTERSECT;
	}
      else if (lam1 >= 0 && lam2 >= 0 && lam1+lam2 <= 1)
	{  // lam3 > 0
	  cnt++;
	}

    }

  //  (*testout) << " inside = " << (cnt % 2) << endl;
  return (cnt % 2) ? IS_INSIDE : IS_OUTSIDE;
}



INSOLID_TYPE Polyhedra :: VecInSolid (const Point<3> & p,
				      const Vec<3> & v,
				      double eps) const
{
  int point_on_n_faces = 0;
  INSOLID_TYPE res;

  Vec<3> vn = v;
  vn.Normalize();
  for (int i = 0; i < faces.Size(); i++)
    {
      const Point<3> & p1 = points[faces[i].pnums[0]];
      
      Vec<3> v0 = p - p1;
      double lam3 = -(faces[i].n * v0);

      if (fabs (lam3) > eps) continue;

      double lam1 = (faces[i].w1 * v0);
      double lam2 = (faces[i].w2 * v0);

      if (lam1 >= -eps && lam2 >= -eps && lam1+lam2 <= 1+eps)
	{
	  point_on_n_faces++;

	  double scal = vn * faces[i].n;
	
	  res = DOES_INTERSECT;
	  if (scal > eps) res = IS_OUTSIDE;
	  if (scal < -eps) res = IS_INSIDE;
	}
    }

  if (point_on_n_faces == 1)
    return res;

  
  Point<3> p2 = p + (1e-3/(v.Length()+1e-16)) * v;
  res = PointInSolid (p2, eps);
  //  (*testout) << "p = " << p << " v = " << v << " p2 = " << p2 << endl;
  //  (*testout) << "polyeder::vecinsolid = " << int(res) << endl;
  return res;
}


INSOLID_TYPE Polyhedra :: VecInSolid2 (const Point<3> & p,
				       const Vec<3> & v1,
				       const Vec<3> & v2,
				       double eps) const
{
  int point_on_n_faces = 0;
  INSOLID_TYPE res;

  Vec<3> v1n = v1;
  v1n.Normalize();
  Vec<3> v2n = v2;
  v2n.Normalize();


  for (int i = 0; i < faces.Size(); i++)
    {
      const Point<3> & p1 = points[faces[i].pnums[0]];
      
      Vec<3> v0 = p - p1;
      double lam3 = -(faces[i].n * v0);

      if (fabs (lam3) > eps) continue;

      double lam1 = (faces[i].w1 * v0);
      double lam2 = (faces[i].w2 * v0);

      if (lam1 >= -eps && lam2 >= -eps && lam1+lam2 <= 1+eps)
	{
	  double scal1 = v1n * faces[i].n;
	  if (fabs (scal1) > eps) continue;


	  point_on_n_faces++;

	  double scal2 = v2n * faces[i].n;
	  res = DOES_INTERSECT;
	  if (scal2 > eps) res = IS_OUTSIDE;
	  if (scal2 < -eps) res = IS_INSIDE;
	}
    }

  if (point_on_n_faces == 1)
    return res;




  return Primitive :: VecInSolid2 (p, v1, v2, eps);
}




void Polyhedra :: GetPrimitiveData (char *& classname, 
				    ARRAY<double> & coeffs) const
{
  classname = "Polyhedra";
  coeffs.SetSize(0);
  coeffs.Append (points.Size());
  coeffs.Append (faces.Size());
  coeffs.Append (planes.Size());

  /*
  int i, j;
  for (i = 1; i <= planes.Size(); i++)
    {
      planes.Elem(i)->Print (*testout);
    }
  for (i = 1; i <= faces.Size(); i++)
    {
      (*testout) << "face " << i << " has plane " << faces.Get(i).planenr << endl;
      for (j = 1; j <= 3; j++)
	(*testout) << points.Get(faces.Get(i).pnums[j-1]);
      (*testout) << endl;
    }
  */
}

void Polyhedra :: SetPrimitiveData (ARRAY<double> & coeffs)
{
  ;
}

void Polyhedra :: Reduce (const BoxSphere<3> & box)
{
  for (int i = 0; i < planes.Size(); i++)
    surfaceactive[i] = 0;

  for (int i = 0; i < faces.Size(); i++)
    if (FaceBoxIntersection (i, box))
      surfaceactive[faces[i].planenr] = 1;
}

void Polyhedra :: UnReduce ()
{
  for (int i = 0; i < planes.Size(); i++)
    surfaceactive[i] = 1;
}

int Polyhedra :: AddPoint (const Point<3> & p)
{
  return points.Append (p);
}

int Polyhedra :: AddFace (int pi1, int pi2, int pi3)
{
  faces.Append (Face (pi1, pi2, pi3, points));
  
  Point<3> p1 = points[pi1];
  Point<3> p2 = points[pi2];
  Point<3> p3 = points[pi3];

  Vec<3> v1 = p2 - p1;
  Vec<3> v2 = p3 - p1;

  Vec<3> n = Cross (v1, v2); 
  n.Normalize();

  Plane pl (p1, n);
  int inverse;
  int identicto = -1;
  for (int i = 0; i < planes.Size(); i++)
    if (pl.IsIdentic (*planes[i], inverse, 1e-6))
      {
	if (!inverse)
	  identicto = i;
      }
  //  cout << "is identic = " << identicto << endl;

  if (identicto != -1)
    faces.Last().planenr = identicto;
  else
    {
      planes.Append (new Plane (p1, n));
      surfaceactive.Append (1);
      surfaceids.Append (0);
      faces.Last().planenr = planes.Size()-1;
    }

  return faces.Size();
}



int Polyhedra :: FaceBoxIntersection (int fnr, const BoxSphere<3> & box) const
{
  /*
  (*testout) << "check face box intersection, fnr = " << fnr << endl;
  (*testout) << "box = " << box << endl;
  (*testout) << "face-box = " << faces[fnr].bbox << endl;
  */

  if (!faces[fnr].bbox.Intersect (box))
    return 0;

  const Point<3> & p1 = points[faces[fnr].pnums[0]];
  const Point<3> & p2 = points[faces[fnr].pnums[1]];
  const Point<3> & p3 = points[faces[fnr].pnums[2]];

  double dist2 = MinDistTP2 (p1, p2, p3, box.Center());
  /*
  (*testout) << "p1 = " << p1 << endl;
  (*testout) << "p2 = " << p2 << endl;
  (*testout) << "p3 = " << p3 << endl;

  (*testout) << "box.Center() = " << box.Center() << endl;
  (*testout) << "center = " << box.Center() << endl;
  (*testout) << "dist2 = " << dist2 << endl;
  (*testout) << "diam = " << box.Diam() << endl;
  */
  if (dist2 < sqr (box.Diam()/2))
    {
      //      (*testout) << "intersect" << endl;
      return 1;
    }
  return 0;
}
}
