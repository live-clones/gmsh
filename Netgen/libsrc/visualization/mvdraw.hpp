#ifndef FILE_MVDRAW
#define FILE_MVDRAW

class VisualizationParameters
{
public:
  double lightamb;
  double lightdiff;
  double lightspec;
  double shininess;
  double transp;
  int locviewer;
  char selectvisual[20];
  int showstltrias;
  
  Vec3d clipnormal;
  double clipdist;
  int clipenable;
  int clipplanetimestamp;

  int colormeshsize;

  int drawfilledtrigs;
  int drawbadels;
  int drawoutline;
  int drawedges;
  int subdivisions;

  int drawprisms;
  int drawpyramids;
  int drawhexes;
  double shrink;
  int drawidentified;
  int drawpointnumbers;
  int drawedgenumbers;
  int drawfacenumbers;
  int drawelementnumbers;
  int drawdomainsurf;
  int drawtets;
  int drawtetsdomain;

  int drawededges;
  int drawedpoints;
  int drawedpointnrs;
  int drawedtangents;
  int drawededgenrs;

  int drawcurveproj;
  int drawcurveprojedge;
  

  int centerpoint;
  int drawelement;

  // stl:
  int stlshowtrias;
  int stlshowfilledtrias;
  int stlshowedges;
  int stlshowmarktrias;
  int stlshowactivechart;
  int stlchartnumber;
  int stlchartnumberoffset;

  bool whitebackground;
  int stereo;
  bool usedispllists;
  bool drawcoordinatecross;
  bool drawcolorbar;
  bool drawnetgenlogo;

  
public:
  VisualizationParameters();
};
extern VisualizationParameters vispar;



extern void InitDrawMesh ();
extern void DrawMesh ();
extern void MouseMove(int oldx, int oldy,
		      int newx, int newy,
		      char mode);

extern void Render ();


class VisualScene
{
protected:
  static Point3d center;
  static double rad;

  static float lookatmat[16];
  static float transmat[16];
  static float rotmat[16];
  static float centermat[16];
  static float transformationmat[16];

  GLdouble clipplane[4];

  int changeval;
  static double backcolor;

public:
  static GLuint fontbase;
  static GLubyte * colortexture;
  static GLuint coltexname;
  static int ntexcols;
  // static bool linear_colors;
  int invcolor;


public:
  VisualScene ();
  virtual ~VisualScene();

  virtual void BuildScene (int zoomall = 0);
  virtual void DrawScene ();
  
  void CalcTransformationMatrices();
  void StandardRotation (const char * dir);

  void MouseMove(int oldx, int oldy,
		 int newx, int newy,
		 char mode);

  void LookAt (const Point<3> & cam, const Point<3> & obj,
	       const Point<3> & camup);

  void SetClippingPlane ();

  virtual void MouseDblClick (int px, int py);

  void SetLight ();
  static void SetBackGroundColor (double col)
    { backcolor = col; }

  void CreateTexture (int ncols, int linear);
  void DrawColorBar (double minval, double maxval, int logscale = 0);
  void DrawCoordinateCross ();
  void DrawNetgenLogo ();
  void SetOpenGlColor(double val, double valmin, double valmax, int logscale = 0);
};


class VisualSceneGeometry : public VisualScene
{
  ARRAY<int> trilists;
  int selsurf;
public:
  VisualSceneGeometry ();
  virtual ~VisualSceneGeometry ();

  virtual void SelectSurface (int aselsurf);
  virtual void BuildScene (int zoomall = 0);
  virtual void DrawScene ();
};



class VisualSceneSTLGeometry : public VisualScene
{
  ARRAY<int> trilists;
  
public:
  VisualSceneSTLGeometry ();
  virtual ~VisualSceneSTLGeometry ();

  virtual void BuildScene (int zoomall = 0);
  virtual void DrawScene ();
};


class VisualSceneGeometry2d : public VisualScene
{
public:
  VisualSceneGeometry2d ();
  virtual ~VisualSceneGeometry2d ();

  virtual void BuildScene (int zoomall = 0);
  virtual void DrawScene ();
};


#ifdef OCCGEOMETRY
class VisualSceneOCCGeometry : public VisualScene
{
  ARRAY<int> trilists;
  ARRAY<int> linelists;
  int selsurf;
public:
  VisualSceneOCCGeometry ();
  virtual ~VisualSceneOCCGeometry ();

  virtual void BuildScene (int zoomall = 0);
  virtual void DrawScene ();
};
#endif




#ifdef STEP
class VisualSceneSTEPGeometry : public VisualScene
{
  ARRAY<int> gllists;
  
public:
  VisualSceneSTEPGeometry ();
  virtual ~VisualSceneSTEPGeometry ();

  virtual void BuildScene (int zoomall = 0);
  virtual void DrawScene ();
};
#endif


class VisualSceneSTLMeshing : public VisualScene
{
  ARRAY<int> trilists;
  int selecttrig, nodeofseltrig;

public:
  VisualSceneSTLMeshing ();
  virtual ~VisualSceneSTLMeshing ();

  virtual void BuildScene (int zoomall = 0);
  virtual void DrawScene ();
  virtual void MouseDblClick (int px, int py);

  int seltria;
};




class VisualSceneSurfaceMeshing : public VisualScene
{
public:
  VisualSceneSurfaceMeshing ();
  virtual ~VisualSceneSurfaceMeshing ();

  virtual void BuildScene (int zoomall = 0);
  virtual void DrawScene ();
};







class VisualSceneMesh : public VisualScene
{
  int filledlist;
  int linelist;
  int pointnumberlist;

  int tetlist;
  int prismlist;
  int pyramidlist;
  int hexlist;

  int badellist;
  int identifiedlist;
  int domainsurflist;

  int vstimestamp, selecttimestamp;
  int filledtimestamp;
  int linetimestamp;
  int pointnumbertimestamp;

  int tettimestamp;
  int prismtimestamp;
  int pyramidtimestamp;
  int hextimestamp;

  int badeltimestamp;
  int identifiedtimestamp;
  int domainsurftimestamp;

  NgLock *lock;

  int selface, selelement;
  int selpoint, selpoint2, locpi;
  int seledge;

  double minh, maxh; // for meshsize coloring

public:
  VisualSceneMesh ();
  virtual ~VisualSceneMesh ();

  virtual void BuildScene (int zoomall = 0);
  virtual void DrawScene ();
  virtual void MouseDblClick (int px, int py);

  int SelectedFace () const
    { return selface; }
  void SetSelectedFace (int asf) 
    { selface = asf; selecttimestamp = GetTimeStamp(); }

  int SelectedEdge () const
    { return seledge; }
  int SelectedElement () const
    { return selelement; }
  int SelectedPoint () const
    { return selpoint; }
private:
  void BuildFilledList();
  void BuildLineList();
  void BuildPointNumberList();

  void BuildTetList();
  void BuildPrismList();
  void BuildPyramidList();
  void BuildHexList();

  void BuildBadelList();
  void BuildIdentifiedList();
  void BuildDomainSurfList();
};







class VisualSceneSpecPoints : public VisualScene
{
public:
  VisualSceneSpecPoints ();
  virtual ~VisualSceneSpecPoints ();

  virtual void BuildScene (int zoomall = 0);
  virtual void DrawScene ();

  double len;
};

// extern struct Tcl_Interp * hinterp;


extern void AddVisualizationScene (const string & name, 
				   VisualScene * vs);



#endif

