#ifndef FILE_ADFRONT3
#define FILE_ADFRONT3

/**************************************************************************/
/* File:   adfront3.hh                                                    */
/* Author: Joachim Schoeberl                                              */
/* Date:   01. Okt. 95                                                    */
/**************************************************************************/

/*
    Advancing front class for volume meshing
*/



/// Point in advancing front
class FrontPoint3
{
  /// coordinates
  Point3d p;           
  /// global node index
  PointIndex globalindex;   
  /// number of faces connected to point 
  int nfacetopoint;    
  /// distance to original boundary
  int frontnr;
  /// 
  int cluster;
public:
  ///
  FrontPoint3 ();
  ///
  FrontPoint3 (const Point3d & ap, PointIndex agi);
  
  ///
  const Point3d & P () const
    { return p; }
  ///
  PointIndex GlobalIndex () const
    { return globalindex; }
  
  ///
  void AddFace ()
    { nfacetopoint++; }

  ///
  void RemoveFace()
    { 
      nfacetopoint--;
      if (nfacetopoint == 0) nfacetopoint = -1;
    }
  
  ///
  int Valid () const
  { return nfacetopoint >= 0; }

  ///
  void DecFrontNr (int afrontnr)
    {
      if (frontnr > afrontnr) frontnr = afrontnr;
    }
  
  ///
  int FrontNr () const
    { return frontnr; }

  ///
  friend class AdFront3;
};

/// Face in advancing front
class FrontFace
{
  ///
  Element2d f;
  ///
  int qualclass;
  ///
  char oldfront;
  ///
  int hashvalue;
  ///
  int cluster;

public:
  ///
  FrontFace ();
  ///
  FrontFace (const Element2d & af);
  ///
  const Element2d & Face () const
    { return f; }
    
  ///
  int QualClass () const
    { return qualclass; }

  ///
  void IncrementQualClass ()
    { qualclass++; }

  ///
  void ResetQualClass ()
    {
      if (qualclass > 1)
	{
	  qualclass = 1;
	  oldfront = 0;
	}
    }
  
  ///
  int Valid () const
  { 
    return !f.IsDeleted(); // PNum(1) != 0; 
  }

  ///
  void Invalidate ();
  ///
  int HashValue() const {return hashvalue;}
  ///
  void SetHashValue(int hv) {hashvalue = hv;}

  ///
  friend class AdFront3;

  int Cluster () const { return cluster; }
      
};  




/// Advancing front, 3D.
class AdFront3
{
  ///
  ARRAY<FrontPoint3,PointIndex::BASE> points;
  ///
  ARRAY<FrontFace> faces;
  ///
  ARRAY<PointIndex> delpointl;

  /// which points are connected to pi ?
  TABLE<int> * connectedpairs;
  
  /// number of total front faces;
  int nff;
  /// number of quads in front
  int nff4; 
  
  ///
  double vol;

  ///
  GeomSearch3d hashtable;

  /// 
  int hashon;

  ///
  int hashcreated;

  /// counter for rebuilding internal tables
  int rebuildcounter;
  /// last base element
  int lasti;
  /// minimal selection-value of baseelements
  int minval;

  ///
  class Box3dTree * facetree;
public:

  ///
  AdFront3 ();
  ///
  ~AdFront3 ();
  ///
  void GetPoints (ARRAY<Point3d> & apoints) const;
  ///
  int GetNP() const 
    { return points.Size(); }
  ///
  const Point3d & GetPoint (PointIndex pi) const
  { return points[pi].P(); }
  ///
  int GetNF() const
    { return nff; }
  ///
  const Element2d & GetFace (int i) const
    { return faces.Get(i).Face(); }
  ///
  void Print () const;
  ///
  int Empty () const
    { return nff == 0; }
  ///
  int Empty (int elnp) const
    {
      if (elnp == 4)
	return (nff4 == 0);
      return (nff - nff4 == 0);
    }
  ///
  int SelectBaseElement ();

  ///
  void CreateTrees ();

  ///
  void GetIntersectingFaces (const Point3d & pmin, const Point3d & pmax, 
			     ARRAY<int> & ifaces) const;

  ///
  void GetFaceBoundingBox (int i, Box3d & box) const;

  ///
  int GetLocals (int baseelement,
		 ARRAY<Point3d> & locpoints,
                 ARRAY<Element2d> & locfaces,   // local index
                 ARRAY<PointIndex> & pindex,
                 ARRAY<INDEX> & findex,
		 INDEX_2_HASHTABLE<int> & connectedpairs,
                 float xh,
		 float relh,
		 INDEX& facesplit);
  
  ///
  void GetGroup (int fi,
                 ARRAY<MeshPoint> & grouppoints,
                 ARRAY<Element2d> & groupelements,
                 ARRAY<PointIndex> & pindex,
                 ARRAY<INDEX> & findex
                 ) const;

  ///
  void DeleteFace (INDEX fi);
  ///
  INDEX AddPoint (const Point3d & p, PointIndex globind);
  ///
  INDEX AddFace (const Element2d & e);
  ///
  INDEX AddConnectedPair (const INDEX_2 & pair);
  ///
  void IncrementClass (INDEX fi);
  ///
  void ResetClass (INDEX fi);
  ///
  void SetStartFront (int baseelnp = 0);

  /// is Point p inside Surface ?
  int Inside (const Point3d & p) const;
  /// both points on same side ?
  int SameSide (const Point3d & lp1, const Point3d & lp2, const ARRAY<int> * testfaces = NULL) const;


  ///
  PointIndex GetGlobalIndex (PointIndex pi) const
    { return points[pi].GlobalIndex(); }
  ///
  double Volume () const
    { return vol; }


private:
  void RebuildInternalTables();
};




#endif
