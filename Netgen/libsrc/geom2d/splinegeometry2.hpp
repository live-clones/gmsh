#ifndef FILE_SPLINEGEOMETRY2
#define FILE_SPLINEGEOMETRY2

/**************************************************************************/
/* File:   splinegeometry2.hpp                                            */
/* Author: Joachim Schoeberl                                              */
/* Date:   24. Jul. 96                                                    */
/**************************************************************************/



/// 
extern void LoadBoundarySplines (const char * filename,
				 ARRAY<GeomPoint2d> & geompoints,
				 ARRAY<SplineSegment*> & splines, 
				 double & elto0);
///
extern void PartitionBoundary (const ARRAY<SplineSegment*> & splines,
			       double h, double elto0,
			       Mesh & mesh2d);


class SplineGeometry2d
{
  ARRAY<GeomPoint2d> geompoints;
  ARRAY<SplineSegment*> splines;
  double elto0;

public:
  void Load (const char * filename);
  void PartitionBoundary (double h, Mesh & mesh2d);

  void CopyEdgeMesh (int from, int to, Mesh & mesh2d);

  const ARRAY<SplineSegment*> & GetSplines () const
  { return splines; }

  void GetBoundingBox (Box<2> & box) const;
};



#endif
