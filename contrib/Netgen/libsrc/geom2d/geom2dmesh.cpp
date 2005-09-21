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
  
    //  (*testout) << "refine 2d line, ap1.dist, ap2.dist = " << ap1.dist << ", " << ap2.dist << endl;
    //  (*testout) << "p1, p2 = " << p1 << p2 << ", newp = " << p2d << endl;

    newp = Point3d (p2d(0), p2d(1), 0);
    newgi.edgenr = ap1.edgenr;
    newgi.dist = ((1-secpoint)*ap1.dist+secpoint*ap2.dist);
  }

}
