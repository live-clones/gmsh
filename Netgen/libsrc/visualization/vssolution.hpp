#ifndef FILE_VSSOLUTION
#define FILE_VSSOLUTION





extern int Ng_Vis_Set (ClientData clientData,
		       Tcl_Interp * interp,
		       int argc, tcl_const char *argv[]);

class VisualSceneSolution : public VisualScene
{
  class ClipPlaneTrig
  {
  public:
    struct ps 
    {
      Point<3> lami;
      Point<3> p;
    };
    ps points[3];
    ElementIndex elnr;
  };

  class ClipPlanePoint
  {
  public:
    ElementIndex elnr;
    double lam1, lam2, lam3;
    Point<3> p;
  };


  int surfellist;
  int linelist;
  int clipplanelist;
  int isolinelist;
  int surface_vector_list;
  int cone_list;

  bool draw_fieldlines;
  int num_fieldlines;
  bool fieldlines_randomstart;
  int fieldlineslist;
  int num_fieldlineslists;

  int surfeltimestamp, clipplanetimestamp, solutiontimestamp;
  int fieldlinestimestamp, surface_vector_timestamp;
  double minval, maxval;

  

  NgLock *lock;

public:

  enum EvalFunc { 
    FUNC_ABS = 1, 
    FUNC_ABS_TENSOR = 2,
    FUNC_MISES = 3, 
    FUNC_MAIN = 4
  };
  EvalFunc evalfunc;

  enum SolType
    { 
      SOL_NODAL = 1, 
      SOL_ELEMENT = 2, 
      SOL_SURFACE_ELEMENT = 3, 
      SOL_NONCONTINUOUS = 4, 
      SOL_SURFACE_NONCONTINUOUS = 5,
      SOL_VIRTUALFUNCTION = 6,
      SOL_MARKED_ELEMENTS = 10,
      SOL_ELEMENT_ORDER = 11,
    };

  class SolData
  {
  public:
    char * name;
    double * data;
    int components;
    int dist;
    int order;
    bool iscomplex;
    bool draw_volume;
    bool draw_surface;
    SolType soltype;
    SolutionData * solclass;

    // internal variables:
    int size;
  };

  ARRAY<SolData*> soldata;
  


  int usetexture;
  int clipsolution;  // 0..no, 1..scal, 2..vec
  int scalfunction, scalcomp, vecfunction;
  int gridsize;

  int autoscale, logscale;
  double mminval, mmaxval;
  int numisolines;
  int subdivisions;

  bool showclipsolution;
  bool showsurfacesolution;
  bool lineartexture;
  int numtexturecols;

  // bool fieldlineplot;
  double time;

  int deform;
  double scaledeform;
  bool imag_part;

public:
  VisualSceneSolution ();
  virtual ~VisualSceneSolution ();

  virtual void BuildScene (int zoomall = 0);
  virtual void DrawScene ();
  virtual void MouseDblClick (int px, int py);

  void BuildFieldLinesPlot ();

  void AddSolutionData (SolData * soldata);
  void ClearSolutionData ();
  void UpdateSolutionTimeStamp ();
  SolData * GetSolData (int i);
  int GetNSolData () { return soldata.Size(); }

  void SaveSolutionData (const char * filename);
private:
  void GetMinMax (int funcnr, int comp, double & minv, double & maxv) const;

  void GetClippingPlaneTrigs (ARRAY<ClipPlaneTrig> & trigs);
  void GetClippingPlaneGrid (ARRAY<ClipPlanePoint> & pts);
  void DrawCone (const Point<3> & p1, const Point<3> & p2, double r);
  void DrawCylinder (const Point<3> & p1, const Point<3> & p2, double r);


  // Get Function Value, local coordinates lam1, lam2, lam3, 
  double GetValue (const SolData * data, ElementIndex elnr, 
		   double lam1, double lam2, double lam3,
		   int comp) const;
  double GetSurfValue (const SolData * data, SurfaceElementIndex elnr,
		       double lam1, double lam2, 
		       int comp) const;
  void GetValues (const SolData * data, ElementIndex elnr, 
		  double lam1, double lam2, double lam3,
		  double * values) const;
  void GetSurfValues (const SolData * data, SurfaceElementIndex elnr,
		      double lam1, double lam2, 
		      double * values) const;

  void GetDeformation (ElementIndex elnr, double lam1, double lam2, double lam3,
		       Vec<3> & def) const;
  void GetSurfDeformation (SurfaceElementIndex selnr, double lam1, double lam2,
			   Vec<3> & def) const;

  void GetPointDeformation (int pnum, Point<3> & p, SurfaceElementIndex elnr = -1) const;

  /// draw elements (build lists)
  void DrawSurfaceElements ();
  void DrawSurfaceElementLines ();
  void DrawSurfaceVectors ();
  
  void DrawIsoLines (const Point3d & p1, 
		     const Point3d & p2, 
		     const Point3d & p3,
		     double val1, double val2, double val3,
		     double minval, double maxval, int n);

  // draw isolines between lines (p1,p2) and (p3,p4)
  void DrawIsoLines2 (const Point3d & p1, 
		      const Point3d & p2, 
		      const Point3d & p3,
		      const Point3d & p4,
		      double val1, double val2, double val3, double val4,
		      double minval, double maxval, int n);
		     

  void DrawClipPlaneTrig (const SolData * sol, 
			  int comp,
			  const ClipPlaneTrig & trig, 
			  int level);
			  
  void SetOpenGlColor(double val, double valmin, double valmax, int logscale = 0);

  
  friend int Ng_Vis_Set (ClientData clientData,
			 Tcl_Interp * interp,
			 int argc, tcl_const char *argv[]);



};


extern VisualSceneSolution vssolution;




#endif

