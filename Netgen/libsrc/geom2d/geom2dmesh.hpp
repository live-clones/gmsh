#ifndef FILE_GEOM2DMESH
#define FILE_GEOM2DMESH

/**************************************************************************/
/* File:   geom2dmesh.hh                                                  */
/* Author: Joachim Schoeberl                                              */
/* Date:   22. Jan. 01                                                    */
/**************************************************************************/


class Refinement2d : public Refinement
{
  const SplineGeometry2d & geometry;

public:
  Refinement2d (const SplineGeometry2d & ageometry);
  virtual ~Refinement2d ();
  
  virtual void PointBetween (const Point3d & p1, const Point3d & p2, double secpoint,
			     int surfi, 
			     const PointGeomInfo & gi1, 
			     const PointGeomInfo & gi2,
			     Point3d & newp, PointGeomInfo & newgi);

  virtual void PointBetween (const Point3d & p1, const Point3d & p2, double secpoint,
			     int surfi1, int surfi2, 
			     const EdgePointGeomInfo & ap1, 
			     const EdgePointGeomInfo & ap2,
			     Point3d & newp, EdgePointGeomInfo & newgi);
			     
};






#endif
