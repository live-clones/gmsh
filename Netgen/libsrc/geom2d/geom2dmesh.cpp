#include <mystdlib.h>

#include <csg.hpp>
#include <geometry2d.hpp>
#include <meshing.hpp>

namespace netgen
{

Refinement2d :: Refinement2d (const SplineGeometry2d & ageometry)
  : Refinement(), geometry(ageometry)
{
  ;
}

Refinement2d :: ~Refinement2d ()
{
  ;
}
  


void Refinement2d :: 
PointBetween (const Point3d & p1, const Point3d & p2, double secpoint,
	      int surfi, 
	      const PointGeomInfo & gi1, 
	      const PointGeomInfo & gi2,
	      Point3d & newp, PointGeomInfo & newgi)
{
  newp = p1+secpoint*(p2-p1);
  newgi.trignum = 1;
  /*
  if (surfi)
    {
      //      (*testout) << "surfi1 = " << surfi << endl;
      //      (*testout) << "np = " << newp << endl;
      geometry.GetSurface (surfi) -> Project (newp);
      newgi.trignum = 1;
      //      (*testout) << "np2 = " << newp << endl;
    }
  */
}



void Refinement2d :: 
PointBetween (const Point3d & p1, const Point3d & p2, double secpoint, 
	      int surfi1, int surfi2, 
	      const EdgePointGeomInfo & ap1, 
	      const EdgePointGeomInfo & ap2,
	      Point3d & newp, EdgePointGeomInfo & newgi)
{
  Point<2> p2d;

  p2d = geometry.GetSplines().Get(ap1.edgenr) -> 
    GetPoint (((1-secpoint)*ap1.dist+secpoint*ap2.dist));


/*

  // test routine: general function on first edge

  double x = secpoint;
  if (ap1.edgenr == 1)
      p2d = Point<2>((1-secpoint),fabs(x-0.5) < 0.2 ? (1+cos((x-0.5)*M_PI/0.2))*0.1 : 0);

*/

  //  (*testout) << "refine 2d line, ap1.dist, ap2.dist = " << ap1.dist << ", " << ap2.dist << endl;
  //  (*testout) << "p1, p2 = " << p1 << p2 << ", newp = " << p2d << endl;

  //  newp = Center (p1, p2);
  newp = Point3d (p2d(0), p2d(1), 0);
  newgi.edgenr = ap1.edgenr;
  newgi.dist = ((1-secpoint)*ap1.dist+secpoint*ap2.dist);

  /*
  if (surfi1 && surfi2 && surfi1 != surfi2)
    {
      //      (*testout) << "surfi1 = " << surfi1 << " surfi2 = " << surfi2 << endl;
      //      (*testout) << "np = " << newp << endl;
      //  geometry.GetSurface (surfi1) -> Project (newp);
      ProjectToEdge (geometry.GetSurface(surfi1), 
		     geometry.GetSurface(surfi2), 
		     newp);
      newgi.edgenr = 1;
      //      (*testout) << "np2 = " << newp << endl;
    }
  else if (surfi1)
    {
      geometry.GetSurface (surfi1) -> Project (newp);
    }
  */
};

}
