#include <mystdlib.h>
#include <myadt.hpp>

#include <linalg.hpp>
#include <csg.hpp>
#include <meshing.hpp>

namespace netgen
{

SingularEdge :: SingularEdge (double abeta, 
			      const Solid * asol1, 
			      const Solid * asol2)
{
  beta = abeta;

  if (beta > 1) 
    {
      beta = 1;
      cout << "Warning: beta set to 1" << endl;
    }
  if (beta <= 1e-3)
    {
      beta = 1e-3;
      cout << "Warning: beta set to minimal value 0.001" << endl;
    }

  sol1 = asol1;
  sol2 = asol2;
}

void SingularEdge :: FindPointsOnEdge (class Mesh & mesh)
{
  (*testout) << "find points on edge" << endl;
  int i, j;
  points.SetSize(0);
  segms.SetSize(0);
  for (i = 1; i <= mesh.GetNSeg(); i++)
    {
      INDEX_2 i2 (mesh.LineSegment(i).p1,
		  mesh.LineSegment(i).p2);
      
      int onedge = 1;
      for (j = 1; j <= 2; j++)
	{
	  const Point<3> p = mesh.Point(i2.I(j));
	  if (sol1->IsIn (p, 1e-3) && sol2->IsIn(p, 1e-3) &&
	      !sol1->IsStrictIn (p, 1e-3) && !sol2->IsStrictIn(p, 1e-3))
	    {
	      ;

	    }
	  else
	    onedge = 0;
	}
      if (onedge)
	{
	  segms.Append (i2);
	  cout << "sing segment << " << i2 << endl;
	  points.Append (mesh.Point(i2.I1()));
	  points.Append (mesh.Point(i2.I2()));
	}	    
    }

  
  (*testout) << "Singular points:" << endl;
  for (i = 1; i <= points.Size(); i++)
    (*testout) << points.Get(i) << endl;
  /*
  for (i = 1; i <= mesh.GetNP(); i++)
    {
      const Point<3> p = mesh.Point(i);
      if (sol1->IsIn (p) && sol2->IsIn(p) &&
	  !sol1->IsStrictIn (p) && !sol2->IsStrictIn(p))
	{
	  points.Append (p);
	  cout << "Point " << p << " is on singular edge" << endl;
	}
    }
  */
}

void SingularEdge :: SetMeshSize (class Mesh & mesh, double globalh)
{
  int i;

  double hloc = pow (globalh, 1/beta);
  for (i = 1; i <= points.Size(); i++)
    mesh.RestrictLocalH (points.Get(i), hloc);
}






SingularPoint :: SingularPoint (double abeta, 
				const Solid * asol1, 
				const Solid * asol2,
				const Solid * asol3)
{
  beta = abeta;
  sol1 = asol1;
  sol2 = asol2;
  sol3 = asol3;
}


void SingularPoint :: FindPoints (class Mesh & mesh)
{
  int i;
  points.SetSize(0);
  for (i = 1; i <= mesh.GetNP(); i++)
    {
      const Point<3> p = mesh.Point(i);
      if (sol1->IsIn (p) && sol2->IsIn(p) && sol3->IsIn(p) &&
	  !sol1->IsStrictIn (p) && !sol2->IsStrictIn(p) && !sol3->IsStrictIn(p))
	{
	  points.Append (p);
	  cout << "Point " << p << " is a singular point" << endl;
	}
    }  
}


void SingularPoint :: SetMeshSize (class Mesh & mesh, double globalh)
{
  int i;

  double hloc = pow (globalh, 1/beta);
  for (i = 1; i <= points.Size(); i++)
    mesh.RestrictLocalH (points.Get(i), hloc);  
}
}
