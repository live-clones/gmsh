#ifndef FILE_SINGULARREF
#define FILE_SINGULARREF

/**************************************************************************/
/* File:   singularref.hh                                                 */
/* Author: Joachim Schoeberl                                              */
/* Date:   25. Sep. 99                                                    */
/**************************************************************************/

/**
   Control for local refinement
*/



class SingularEdge 
{
public:
  double beta;
  const Solid *sol1, *sol2;
  ARRAY<Point<3> > points;
  ARRAY<INDEX_2> segms;
public:
  SingularEdge (double abeta, const Solid * asol1, const Solid * asol2);
  void FindPointsOnEdge (class Mesh & mesh);
  void SetMeshSize (class Mesh & mesh, double globalh);
};


class SingularPoint
{
public:
  double beta;
  const Solid *sol1, *sol2, *sol3;
  ARRAY<Point<3> > points;
 
public:
  SingularPoint (double abeta, const Solid * asol1, const Solid * asol2,
		 const Solid * asol3);
  void FindPoints (class Mesh & mesh);
  void SetMeshSize (class Mesh & mesh, double globalh);
};


#endif
