#ifndef FILE_SPECPOIN
#define FILE_SPECPOIN


/**************************************************************************/
/* File:   specpoin.hh                                                    */
/* Author: Joachim Schoeberl                                              */
/* Date:   01. Okt. 95                                                    */
/**************************************************************************/

/*

Special Point Calculation
  
*/

class Surface;
class Solid;

/// Special point.
class SpecialPoint
{
public:
  
  /// coordinates
  Point<3> p;
  /// tangential to edge
  Vec<3> v;
  ///
  int layer;
  /// point must be used in mesh 
  bool unconditional; 

  /// surfaces defining edge 
  int s1, s2;        

  ///
  SpecialPoint () : p(), v(), layer(0)
  { ; }

  ///
  SpecialPoint (const SpecialPoint & sp2);

  ///
  SpecialPoint & operator= (const SpecialPoint & sp2);
  
  ///
  void Print (ostream & str);


  int GetLayer() const { return layer; }

  ///
  bool HasSurfaces (int as1, int as2) const;
};



///
class SpecialPointCalculation
{
private:
  ///
  const CSGeometry * geometry;
  ///
  ARRAY<MeshPoint> * points;
  ///
  ARRAY<long int> boxesinlevel;

  ///
  double size;
  ///
  double relydegtest;   // maximal dimension of bisection intervall for
                        /// test of degeneration parameters
  double cpeps1, epeps1, epeps2, epspointdist2;

public: 

  ///
  SpecialPointCalculation (); 
  
  ///
  void CalcSpecialPoints (const CSGeometry & ageometry, 
			  ARRAY<MeshPoint> & points);
  ///
  void AnalyzeSpecialPoints (const CSGeometry & geometry, 
			     ARRAY<MeshPoint> & points, 
			     ARRAY<SpecialPoint> & specpoints);

protected:
  ///
  void CalcSpecialPointsRec (const Solid * sol, int layer,
			     const BoxSphere<3> & box, 
			     int level, 
			     bool calccp, bool calcep);


  ///
  bool CrossPointNewtonConvergence (const Surface * f1, const Surface * f2, 
				    const Surface * f3, const Point<3> & p);  
  ///
  bool CrossPointDegenerated (const Surface * f1, const Surface * f2,
			      const Surface * f3, const BoxSphere<3> & box) const;
  ///
  void CrossPointNewton (const Surface * f1, const Surface * f2, 
			 const Surface * f3, Point<3> & p);
  
  bool EdgeNewtonConvergence (const Surface * f1, const Surface * f2, 
			      const Point<3> & p);  
  ///
  bool EdgeDegenerated (const Surface * f1, const Surface * f2,
			const BoxSphere<3> & box) const;
  ///
  void EdgeNewton (const Surface * f1, const Surface * f2, 
		   Point<3> & p);
  ///
  bool IsEdgeExtremalPoint (const Surface * f1, const Surface * f2, 
			    const Point<3> & p, Point<3> & pp, double rad);




  ///
  bool ExtremalPointPossible (const Surface * f1, const Surface * f2, 
			      int dir, const BoxSphere<3> & box);
  ///
  bool ExtremalPointDegenerated (const Surface * f1, const Surface * f2, 
				 int dir, const BoxSphere<3> & box);
  ///
  bool ExtremalPointNewtonConvergence (const Surface * f1, const Surface * f2, 
				       int dir, const BoxSphere<3> & box);
  ///
  void ExtremalPointNewton (const Surface * f1, const Surface * f2, 
			    int dir, Point<3> & p);


  ///
  bool AddPoint (const Point<3> & p, int layer);
};

#endif


