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
  int j;
  points.SetSize(0);
  segms.SetSize(0);
  for (SegmentIndex si = 0; si < mesh.GetNSeg(); si++)
    {
      INDEX_2 i2 (mesh[si].p1, mesh[si].p2);
      
      bool onedge = 1;
      for (j = 1; j <= 2; j++)
	{
	  const Point<3> p = mesh[ PointIndex (i2.I(j)) ];
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
	  PrintMessage (5, "sing segment ", i2.I1(), " - ", i2.I2());
	  points.Append (mesh[ PointIndex (i2.I1())]);
	  points.Append (mesh[ PointIndex (i2.I2())]);
	  mesh[si].singedge_left = 1;
	  mesh[si].singedge_right = 1;
	}	    
    }

  /*  
  (*testout) << "Singular points:" << endl;
  for (int i = 0; i < points.Size(); i++)
    (*testout) << points[i] << endl;
  */
}

void SingularEdge :: SetMeshSize (class Mesh & mesh, double globalh)
{
  double hloc = pow (globalh, 1/beta);
  for (int i = 0; i < points.Size(); i++)
    mesh.RestrictLocalH (points[i], hloc);
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
  points.SetSize(0);
  for (PointIndex pi = PointIndex::BASE; 
       pi < mesh.GetNP()+PointIndex::BASE; pi++)
    {
      const Point<3> p = mesh[pi];
      if (sol1->IsIn (p) && sol2->IsIn(p) && sol3->IsIn(p) &&
	  !sol1->IsStrictIn (p) && !sol2->IsStrictIn(p) && !sol3->IsStrictIn(p))
	{
	  points.Append (p);
	  PrintMessage (5, "Point (", p(0), ", ", p(1), ", ", p(2), ") is singular");
	  mesh[pi].SetSingular();
	}
    }  
}


void SingularPoint :: SetMeshSize (class Mesh & mesh, double globalh)
{
  double hloc = pow (globalh, 1/beta);
  for (int i = 1; i <= points.Size(); i++)
    mesh.RestrictLocalH (points.Get(i), hloc);  
}
}
