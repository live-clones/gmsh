#ifndef FILE_ADFRONT2
#define FILE_ADFRONT2

/**************************************************************************/
/* File:   adfront2.hh                                                    */
/* Author: Joachim Schoeberl                                              */
/* Date:   01. Okt. 95                                                    */
/**************************************************************************/

/*
    Advancing front class for surfaces
*/


/*
#define FRONTLINE_GEOMINFO_SIZE 8
#define FRONTPOINT_GEOMINFO_SIZE 4
*/

///
class AdFront2
{

  ///
  class FrontPoint2
  {
    /// coordinates
    Point3d p;            
    /// global node index
    PointIndex globalindex;   
    /// number of front lines connected to point 
    int nlinetopoint;    
    /// distance to original boundary
    int frontnr;          
    //   char geominfo[FRONTLINE_GEOMINFO_SIZE];    
  public:
    ///
    MultiPointGeomInfo * mgi;

    ///
    FrontPoint2 ()
    {
      globalindex = -1;
      nlinetopoint = 0;
      frontnr = INT_MAX-10;    // attention: overflow on calculating  INT_MAX + 1
      mgi = NULL;
    }

    ///
    FrontPoint2 (const Point3d & ap, PointIndex agi,
		 MultiPointGeomInfo * amgi);
    ///
    ~FrontPoint2 () { ; }

    ///
    const Point3d & P () const { return p; }
    ///
    PointIndex GlobalIndex () const { return globalindex; }

    ///
    void AddLine () { nlinetopoint++; }
    ///
    void RemoveLine ()
    {
      nlinetopoint--;
      if (nlinetopoint == 0)
	nlinetopoint = -1;
    }

    ///
    bool Valid () const
    { return nlinetopoint >= 0; }

    ///
    void DecFrontNr (int afrontnr)
    {
      if (frontnr > afrontnr) frontnr = afrontnr;
    }
    
    ///
    int FrontNr () const { return frontnr; }
  };

  
  ///
  class FrontLine
  {
  private:
    /// Point Indizes
    INDEX_2 l;            
    /// quality class 
    int lineclass;      
    /// geometry specific data
    //    char geominfo[FRONTLINE_GEOMINFO_SIZE];
    PointGeomInfo geominfo[2];
  public:

    FrontLine ();
    ///
    FrontLine (const INDEX_2 & al);

    ///
    const INDEX_2 & L () const
    {
      return l;
    }

    ///
    int LineClass() const
    {
      return lineclass;
    }

    ///
    void IncrementClass ()
    {
      lineclass++;
    }
    ///
    void ResetClass ()
    {
      lineclass = 1;
    }

    ///
    bool Valid () const
    {
      return l.I1() != -1;
    }
    ///
    void Invalidate ()
    {
      l.I1() = -1;
      l.I2() = -1;
      lineclass = 1000;
    }

    void SetGeomInfo (const PointGeomInfo & gi1, const PointGeomInfo & gi2)
      {
	geominfo[0] = gi1;
	geominfo[1] = gi2;
      }

    const PointGeomInfo * GetGeomInfo () const
    { return geominfo; }
    
    const PointGeomInfo & GetGeomInfo (int endp) const
    { return geominfo[endp-1]; }

    friend class AdFront2;
  };



  ///
  ARRAY<FrontPoint2> points;  /// front points
  ARRAY<FrontLine> lines;     /// front lines

  Box3d boundingbox;
  Box3dTree linesearchtree;       /// search tree for lines
  Point3dTree cpointsearchtree;   /// search tree for cone points

  ARRAY<INDEX> delpointl;     /// list of deleted front points
  ARRAY<INDEX> dellinel;      /// list of deleted front lines

  INDEX nfl;                  /// number of front lines;
  INDEX_2_HASHTABLE<int> * allflines; /// all front lines ever have been


  int minval;
  int starti;

public:
  ///
  //  AdFront2 ();
  AdFront2 (const Box3d & aboundingbox);
  ///
  ~AdFront2 ();

  ///
  void GetPoints (ARRAY<Point3d> & apoints) const;
  ///
  void Print (ostream & ost) const;

  ///
  bool Empty () const
  {
    return nfl == 0;
  }
  ///
  int GetNFL () const { return nfl; }
  ///
  int SelectBaseLine (Point3d & p1, Point3d & p2, 
		      const PointGeomInfo *& geominfo1,
		      const PointGeomInfo *& geominfo2);

  ///
  int GetLocals (int baseline, 
		 ARRAY<Point3d> & locpoints,
		 ARRAY<MultiPointGeomInfo> & pgeominfo,
                 ARRAY<INDEX_2> & loclines,   // local index
                 ARRAY<INDEX> & pindex,
                 ARRAY<INDEX> & lindex,
                 double xh);

  ///
  void DeleteLine (INDEX li);
  ///
  INDEX AddPoint (const Point3d & p, PointIndex globind, 
		  MultiPointGeomInfo * mgi = NULL);
  ///
  INDEX AddLine (INDEX pi1, INDEX pi2, 
		 const PointGeomInfo & gi1, const PointGeomInfo & gi2);
  ///
  int ExistsLine (int gpi1, int gpi2);
  ///
  void IncrementClass (INDEX li);
  ///
  void ResetClass (INDEX li);

  ///
  const PointGeomInfo & GetLineGeomInfo (int li, int lend) const
    { return lines.Get(li).GetGeomInfo (lend); }
  ///

  PointIndex GetGlobalIndex (int pi) const
  {
    return points.Get(pi).GlobalIndex();
  }
  ///
  void SetStartFront ();
  ///
  void PrintOpenSegments (ostream & ost) const;
};






/*
inline int AdFront2::FrontPoint2 :: Valid () const
{
  return nlinetopoint >= 0;
}
*/
/*
inline const Point3d & AdFront2::FrontPoint2 :: P () const
{
  return p;
}

inline PointIndex AdFront2::FrontPoint2 :: GlobalIndex () const
{
  return globalindex;
}

inline void AdFront2::FrontPoint2 :: AddLine ()
{
  nlinetopoint++;
}

inline void AdFront2::FrontPoint2 :: RemoveLine ()
{
  nlinetopoint--;
  if (nlinetopoint == 0)
    nlinetopoint = -1;
}

inline int AdFront2::FrontPoint2 :: FrontNr () const
{
  return frontnr;
}

inline void AdFront2::FrontPoint2 :: DecFrontNr (int afrontnr)
{
  if (frontnr > afrontnr) frontnr = afrontnr;
}
*/








/*
inline int AdFront2::FrontLine :: Valid () const
{
  return l.I1() != 0;
}

inline void AdFront2::FrontLine :: Invalidate ()
{
  l.I1() = 0;
  l.I2() = 0;
  lineclass = 1000;
}

inline const INDEX_2 & AdFront2::FrontLine :: L () const
{
  return l;
}

inline int AdFront2::FrontLine :: LineClass () const
{
  return lineclass;
}


inline void AdFront2::FrontLine :: IncrementClass ()
{
  lineclass++;
}

inline void AdFront2::FrontLine :: ResetClass ()
{
  lineclass = 1;
}


inline int AdFront2 :: Empty () const
{
  return nfl == 0;
}

inline INDEX AdFront2 :: GetGlobalIndex (INDEX pi) const
{
  return points.Get(pi).GlobalIndex();
}
*/
#endif



