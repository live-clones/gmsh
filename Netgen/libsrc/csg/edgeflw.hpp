#ifndef FILE_EDGEFLW
#define FILE_EDGEFLW

/**************************************************************************/
/* File:   edgeflw.hh                                                     */
/* Author: Joachim Schoeberl                                              */
/* Date:   01. Okt. 95                                                    */
/**************************************************************************/

/*
  
   Edge - following function and
   Projection to edge of implicitly given edge

*/
 

/**
  Calculates edges.
  The edges of a solid geometry are computed. Special
  points have to be given.
 */
extern void CalcEdges (const CSGeometry & geometry,
                       const ARRAY<SpecialPoint> & specpoints,
                       double h, Mesh & mesh);





class EdgeCalculation
{
  const CSGeometry & geometry;
  const ARRAY<SpecialPoint> & specpoints;
  int cntedge;
public:
  EdgeCalculation (const CSGeometry & ageometry,
		   const ARRAY<SpecialPoint> & aspecpoints);

  void Calc(double h, Mesh & mesh);


private:
  void CalcEdges1 (double h, Mesh & mesh);


  void FollowEdge (int pi1, int & ep, int & pos,
		   const ARRAY<SpecialPoint> & hsp,
		   double h, const Mesh & mesh,
		   ARRAY<Point<3> > & edgepoints,
		   ARRAY<double> & curvelength);
		   

  void AnalyzeEdge (int s1, int s2, int pos, int layer,
		    const ARRAY<Point<3> > & edgepoints,
		    ARRAY<Segment> & refedges,
		    ARRAY<int> & refedgesinv);

  void StoreEdge (const ARRAY<Segment> & refedges,
		  const ARRAY<int> & refedgesinv,
		  const ARRAY<Point<3> > & edgepoints,
		  const ARRAY<double> & curvelength,
		  int layer,
		  Mesh & mesh);

  void StoreShortEdge (const ARRAY<Segment> & refedges,
		       const ARRAY<int> & refedgesinv,
		       const ARRAY<Point<3> > & edgepoints,
		       const ARRAY<double> & curvelength,
		       int layer,
		       Mesh & mesh);

  void CopyEdge (const ARRAY<Segment> & refedges,
		 const ARRAY<int> & refedgesinv,
		 int copyfromedge, 
		 const Point<3> & fromstart, const Point<3> & fromend,
		 const Point<3> & tostart, const Point<3> & toend,
		 int copyedgeidentification,
		 int layer,
		 Mesh & mesh);

  
  void SplitEqualOneSegEdges (Mesh & mesh);
  void FindClosedSurfaces (double h, Mesh & mesh);

};



#endif
