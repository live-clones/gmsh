#ifndef FILE_MESHING3
#define FILE_MESHING3




// class PlotStatistics3d;


/*
///
class MeshingParameters3
{
public:
  /// global h
  double h;

  /// give up quality class
  int giveuptol;

  /// maximal outer steps
  int maxoutersteps;   

  /// if non-zero, baseelement must have baseelnp points
  int baseelnp;        

  /// class starting star-shape filling
  int starshapeclass;

  /// call blockfill function
  int blockfill;

  /// quality tolerances are handled less careful
  double sloppy;

  /// number of optimizationsteps
  int optsteps;

  ///
  char * optstr;

  ///
  MeshingParameters3();
};
*/


enum MESHING3_RESULT
{
  MESHING3_OK = 0,
  MESHING3_GIVEUP = 1,
  MESHING3_NEGVOL = 2,
  MESHING3_OUTERSTEPSEXCEEDED = 3,
  MESHING3_TERMINATE = 4,
  MESHING3_BADSURFACEMESH = 5
};


/// 3d volume mesh generation
class Meshing3
{
  /// current state of front
  AdFront3 * adfront;
  /// 3d generation rules
  ARRAY<vnetrule*> rules;
  /// counts how often a rule is used
  ARRAY<int> ruleused, canuse, foundmap;
  /// describes, why a rule is not applied
  ARRAY<char*> problems;
  /// tolerance criterion
  double tolfak;
public:
  /// 
  Meshing3 (const char * rulefilename); 
  /// 
  Meshing3 (const char * rulefilename, const char ** rulep);
  ///
  virtual ~Meshing3 ();
  
  ///
  void LoadRules (const char * filename, const char ** prules);
  ///
  MESHING3_RESULT GenerateMesh (Mesh & mesh, const MeshingParameters & mp);
  
  ///
  int ApplyRules (ARRAY<Point3d> & lpoints, ARRAY<int> & allowpoint,
		  ARRAY<Element2d> & lfaces, INDEX lfacesplit,
		  INDEX_2_HASHTABLE<int> & connectedpairs,
		  ARRAY<Element> & elements,
		  ARRAY<INDEX> & delfaces, int tolerance, 
		  double sloppy, int rotind1,
		  float & retminerr);
  
  ///
  int AddPoint (const Point3d & p, INDEX globind);
  ///
  void AddBoundaryElement (const Element2d & elem);
  ///
  int AddConnectedPair (const INDEX_2 & pair);
  
  ///
  void BlockFill (Mesh & mesh, double gh);
  ///
  void BlockFillLocalH (Mesh & mesh, const MeshingParameters & mp);

  /// uses points of adfront, and puts new elements into mesh
  void Delaunay (Mesh & mesh, const MeshingParameters & mp);
  ///
  friend class PlotVolMesh;
  ///
  friend void TestRules ();
};




/// status of mesh generation
class MeshingStat3d
{
public:
  ///
  MeshingStat3d ();
  ///
  int cntsucc;
  ///
  int cnttrials;
  ///
  int cntelem;
  ///
  int nff;
  ///
  int qualclass;
  ///
  double vol0;
  ///
  double vol;
  ///
  double h;
  ///
  int problemindex;
};


/*
///
class PlotStatistics3d
{
public:
  ///
  PlotStatistics3d () { }
  ///
  virtual void Plot (const MeshingStat3d & stat) const = 0;
};


///
class TerminalPlotStatistics3d : public PlotStatistics3d
{
  int oldne;
public:
  ///
  TerminalPlotStatistics3d ();
  ///
  virtual void Plot (const MeshingStat3d & stat) const;
};
*/



/*
template <typename POINTARRAY, typename FACEARRAY>
extern int FindInnerPoint (POINTARRAY & grouppoints,
			   FACEARRAY & groupfaces,
			   Point3d & p);

*/





#endif










