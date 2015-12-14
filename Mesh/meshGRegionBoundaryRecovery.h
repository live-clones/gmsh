// Gmsh - Copyright (C) 1997-2014 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#ifndef _MESH_GREGION_BOUNDARY_RECOVERY_H_
#define _MESH_GREGION_BOUNDARY_RECOVERY_H_

#include "GRegion.h"
#include <time.h>

#define REAL double

class meshGRegionInputs {
 public:
  int firstnumber;
  meshGRegionInputs() {
    firstnumber = 0;
  }
};

class meshGRegionOptions {

 public:

  int plc;
  int psc;
  int refine;
  int quality;
  int nobisect;
  int coarsen;
  int weighted;
  int brio_hilbert;
  int incrflip;
  int flipinsert;
  int metric;
  int varvolume;
  int fixedvolume;
  int regionattrib;
  int conforming;
  int insertaddpoints;
  int diagnose;
  int convex;
  int nomergefacet;
  int nomergevertex;
  int noexact;
  int nostaticfilter;
  int zeroindex;
  int facesout;
  int edgesout;
  int neighout;
  int voroout;
  int meditview;
  int vtkview;
  int nobound;
  int nonodewritten;
  int noelewritten;
  int nofacewritten;
  int noiterationnum;
  int nojettison;
  int reversetetori;
  int docheck;
  int quiet;
  int verbose;

  int vertexperblock;
  int tetrahedraperblock;
  int shellfaceperblock;
  int nobisect_param;
  int addsteiner_algo;
  int coarsen_param;
  int weighted_param;
  int fliplinklevel;
  int flipstarsize;
  int fliplinklevelinc;
  int reflevel;
  int optlevel;
  int optscheme;
  int delmaxfliplevel;
  int order;
  int steinerleft;
  int no_sort;
  int hilbert_order;
  int hilbert_limit;
  int brio_threshold;
  REAL brio_ratio;
  REAL facet_ang_tol;
  REAL maxvolume;
  REAL minratio;
  REAL mindihedral;
  REAL optmaxdihedral;
  REAL optminsmtdihed;
  REAL optminslidihed;
  REAL epsilon;
  REAL minedgelength;
  REAL coarsen_percent;

 // Initialize all variables.
  meshGRegionOptions()
  {
    plc = 1;   // -p
    psc = 0;
    refine = 0;
    quality = 0;
    nobisect = 1;
    coarsen = 0;
    metric = 0;
    weighted = 0;
    brio_hilbert = 1; // -Y
    incrflip = 0;
    flipinsert = 0;
    varvolume = 0;
    fixedvolume = 0;
    noexact = 0;
    nostaticfilter = 0;
    insertaddpoints = 0;
    regionattrib = 1; // -A
    conforming = 0;
    diagnose = 0;
    convex = 1;  // -c
    zeroindex = 0;
    facesout = 0;
    edgesout = 0;
    neighout = 0;
    voroout = 0;
    meditview = 0;
    vtkview = 0;
    nobound = 0;
    nonodewritten = 0;
    noelewritten = 0;
    nofacewritten = 0;
    noiterationnum = 0;
    nomergefacet = 0;
    nomergevertex = 0;
    nojettison = 0;
    reversetetori = 0;
    docheck = 0;
    quiet = 0;
    verbose = 0;

    vertexperblock = 4092;
    tetrahedraperblock = 8188;
    shellfaceperblock = 4092;
    nobisect_param = 2;
    addsteiner_algo = 1;
    coarsen_param = 0;
    weighted_param = 0;
    fliplinklevel = -1; // No limit on linklevel.
    flipstarsize = -1;  // No limit on flip star size.
    fliplinklevelinc = 1;
    reflevel = 3;
    optscheme = 7;  // 1 & 2 & 4, // min_max_dihedral.
    optlevel = 2;
    delmaxfliplevel = 1;
    order = 1;
    steinerleft = -1;
    no_sort = 0;
    hilbert_order = 52; //-1;
    hilbert_limit = 8;
    brio_threshold = 64;
    brio_ratio = 0.125;
    facet_ang_tol = 179.9;
    maxvolume = -1.0;
    minratio = 2.0;
    mindihedral = 0.0; // 5.0;
    optmaxdihedral = 179.0;
    optminsmtdihed = 179.999;
    optminslidihed = 179.999;
    epsilon = 1.0e-8;
    minedgelength = 0.0;
    coarsen_percent = 1.0;
  }
};

class meshGRegionBoundaryRecovery {

 public:

  // Mesh data structure
  typedef REAL **tetrahedron;
  typedef REAL **shellface;
  typedef REAL *point;

  // Mesh handles
  class triface {
  public:
    tetrahedron *tet;
    int ver; // Range from 0 to 11.
    triface() : tet(0), ver(0) {}
    triface& operator=(const triface& t) {
      tet = t.tet; ver = t.ver;
      return *this;
    }
  };

  class face {
  public:
    shellface *sh;
    int shver; // Range from 0 to 5.
    face() : sh(0), shver(0) {}
    face& operator=(const face& s) {
      sh = s.sh; shver = s.shver;
      return *this;
    }
  };

  // Arraypool (J. R. Shewchuk)
  class arraypool {
  public:
    int objectbytes;
    int objectsperblock;
    int log2objectsperblock;
    int objectsperblockmark;
    int toparraylen;
    char **toparray;
    long objects;
    unsigned long totalmemory;
    void restart();
    void poolinit(int sizeofobject, int log2objperblk);
    char* getblock(int objectindex);
    void* lookup(int objectindex);
    int newindex(void **newptr);
    arraypool(int sizeofobject, int log2objperblk);
    ~arraypool();
  };

#define fastlookup(pool, index) \
  (void *) ((pool)->toparray[(index) >> (pool)->log2objectsperblock] + \
            ((index) & (pool)->objectsperblockmark) * (pool)->objectbytes)

  // Memorypool (J. R. Shewchuk)
  class memorypool {
  public:
    void **firstblock, **nowblock;
    void *nextitem;
    void *deaditemstack;
    void **pathblock;
    void *pathitem;
    int  alignbytes;
    int  itembytes, itemwords;
    int  itemsperblock;
    long items, maxitems;
    int  unallocateditems;
    int  pathitemsleft;
    memorypool();
    memorypool(int, int, int, int);
    ~memorypool();
    void poolinit(int, int, int, int);
    void restart();
    void *alloc();
    void dealloc(void*);
    void traversalinit();
    void *traverse();
  };

  class badface {
  public:
    triface tt;
    face ss;
    REAL key, cent[6];  // circumcenter or cos(dihedral angles) at 6 edges.
    point forg, fdest, fapex, foppo, noppo;
    badface *nextitem;
    badface() : key(0), forg(0), fdest(0), fapex(0), foppo(0), noppo(0),
      nextitem(0) {}
  };

  // Parameters for vertex insertion, flips, and optimizations.
  class insertvertexflags {
  public:
    int iloc;  // input/output.
    int bowywat, lawson;
    int splitbdflag, validflag, respectbdflag;
    int rejflag, chkencflag, cdtflag;
    int assignmeshsize;
    int sloc, sbowywat;
    // Used by Delaunay refinement.
    int refineflag; // 0, 1, 2, 3
    triface refinetet;
    face refinesh;
    int smlenflag; // for useinsertradius.
    REAL smlen; // for useinsertradius.
    point parentpt;

    insertvertexflags() {
      iloc = bowywat = lawson = 0;
      splitbdflag = validflag = respectbdflag = 0;
      rejflag = chkencflag = cdtflag = 0;
      assignmeshsize = 0;
      sloc = sbowywat = 0;

      refineflag = 0;
      refinetet.tet = NULL;
      refinesh.sh = NULL;
      smlenflag = 0;
      smlen = 0.0;
    }
  };

  class flipconstraints {
  public:
    // Elementary flip flags.
    int enqflag; // (= flipflag)
    int chkencflag;
    // Control flags
    int unflip;  // Undo the performed flips.
    int collectnewtets; // Collect the new tets created by flips.
    int collectencsegflag;
    // Optimization flags.
    int remove_ndelaunay_edge; // Remove a non-Delaunay edge.
    REAL bak_tetprism_vol; // The value to be minimized.
    REAL tetprism_vol_sum;
    int remove_large_angle; // Remove a large dihedral angle at edge.
    REAL cosdihed_in; // The input cosine of the dihedral angle (> 0).
    REAL cosdihed_out; // The improved cosine of the dihedral angle.
    // Boundary recovery flags.
    int checkflipeligibility;
    point seg[2];  // A constraining edge to be recovered.
    point fac[3];  // A constraining face to be recovered.
    point remvert; // A vertex to be removed.

    flipconstraints() {
      enqflag = 0;
      chkencflag = 0;
      unflip = 0;
      collectnewtets = 0;
      collectencsegflag = 0;
      remove_ndelaunay_edge = 0;
      bak_tetprism_vol = 0.0;
      tetprism_vol_sum = 0.0;
      remove_large_angle = 0;
      cosdihed_in = 0.0;
      cosdihed_out = 0.0;
      checkflipeligibility = 0;
      seg[0] = NULL;
      fac[0] = NULL;
      remvert = NULL;
    }
  };

  class optparameters {
  public:
    // The one of goals of optimization.
    int max_min_volume;      // Maximize the minimum volume.
	int min_max_aspectratio; // Minimize the maximum aspect ratio.
    int min_max_dihedangle;  // Minimize the maximum dihedral angle.
    // The initial and improved value.
    REAL initval, imprval;
    int numofsearchdirs;
    REAL searchstep;
    int maxiter;  // Maximum smoothing iterations (disabled by -1).
    int smthiter; // Performed iterations.

    optparameters() {
      max_min_volume = 0;
      min_max_aspectratio = 0;
      min_max_dihedangle = 0;
      initval = imprval = 0.0;
      numofsearchdirs = 10;
      searchstep = 0.01;
      maxiter = -1;   // Unlimited smoothing iterations.
      smthiter = 0;
    }
  };

  // Labels
  enum verttype {UNUSEDVERTEX, DUPLICATEDVERTEX, RIDGEVERTEX, ACUTEVERTEX,
                 FACETVERTEX, VOLVERTEX, FREESEGVERTEX, FREEFACETVERTEX,
                 FREEVOLVERTEX, NREGULARVERTEX, DEADVERTEX};
  enum interresult {DISJOINT, INTERSECT, SHAREVERT, SHAREEDGE, SHAREFACE,
                    TOUCHEDGE, TOUCHFACE, ACROSSVERT, ACROSSEDGE, ACROSSFACE,
                    COLLISIONFACE, ACROSSSEG, ACROSSSUB};
  enum locateresult {UNKNOWN, OUTSIDE, INTETRAHEDRON, ONFACE, ONEDGE, ONVERTEX,
                     ENCVERTEX, ENCSEGMENT, ENCSUBFACE, NEARVERTEX, NONREGULAR,
                     INSTAR, BADELEMENT};

  meshGRegionInputs *in;
  meshGRegionOptions *b;
  meshGRegionBoundaryRecovery *bgm;

  // Class variables
  memorypool *tetrahedrons, *subfaces, *subsegs, *points;
  memorypool *tet2subpool, *tet2segpool;

  memorypool *flippool;
  arraypool *unflipqueue;
  badface *flipstack;

  memorypool *badtetrahedrons, *badsubfacs, *badsubsegs;

  // Arrays used for point insertion (the Bowyer-Watson algorithm).
  arraypool *cavetetlist, *cavebdrylist, *caveoldtetlist;
  arraypool *cavetetshlist, *cavetetseglist, *cavetetvertlist;
  arraypool *caveencshlist, *caveencseglist;
  arraypool *caveshlist, *caveshbdlist, *cavesegshlist;

  // Stacks used for CDT construction and boundary recovery.
  arraypool *subsegstack, *subfacstack, *subvertstack;

  // The infinite vertex.
  point dummypoint;
  // The recently visited tetrahedron, subface.
  triface recenttet;
  face recentsh;

  // PI is the ratio of a circle's circumference to its diameter.
  static REAL PI;

  // Various variables.
  int numpointattrib;
  int numelemattrib;
  int sizeoftensor;
  int pointmtrindex;
  int pointparamindex;
  int point2simindex;
  int pointmarkindex;
  int pointinsradiusindex;
  int elemattribindex;
  int volumeboundindex;
  int elemmarkerindex;
  int shmarkindex;
  int areaboundindex;
  int checksubsegflag;
  int checksubfaceflag;
  int checkconstraints;
  int nonconvex;
  int autofliplinklevel;
  int useinsertradius;
  long samples;
  unsigned long randomseed;
  REAL cosmaxdihed, cosmindihed;
  REAL cossmtdihed;
  REAL cosslidihed;
  REAL minfaceang, minfacetdihed;
  REAL tetprism_vol_sum;
  REAL longest;
  REAL xmax, xmin, ymax, ymin, zmax, zmin;

  // Counters.
  long insegments;
  long hullsize;
  long meshedges;
  long meshhulledges;
  long steinerleft;
  long dupverts;
  long unuverts;
  long nonregularcount;
  long st_segref_count, st_facref_count, st_volref_count;
  long fillregioncount, cavitycount, cavityexpcount;
  long flip14count, flip26count, flipn2ncount;
  long flip23count, flip32count, flip44count, flip41count;
  long flip31count, flip22count;
  unsigned long totalworkmemory;      // Total memory used by working arrays.

  // Fast lookup tables for mesh manipulation primitives.
  static int bondtbl[12][12], fsymtbl[12][12];
  static int esymtbl[12], enexttbl[12], eprevtbl[12];
  static int enextesymtbl[12], eprevesymtbl[12];
  static int eorgoppotbl[12], edestoppotbl[12];
  static int facepivot1[12], facepivot2[12][12];
  static int orgpivot[12], destpivot[12], apexpivot[12], oppopivot[12];
  static int tsbondtbl[12][6], stbondtbl[12][6];
  static int tspivottbl[12][6], stpivottbl[12][6];
  static int ver2edge[12], edge2ver[6], epivot[12];
  static int sorgpivot [6], sdestpivot[6], sapexpivot[6];
  static int snextpivot[6];
  void inittables();

  // Primitives for tetrahedra.
  inline tetrahedron encode(triface& t);
  inline tetrahedron encode2(tetrahedron* ptr, int ver);
  inline void decode(tetrahedron ptr, triface& t);
  inline void bond(triface& t1, triface& t2);
  inline void dissolve(triface& t);
  inline void esym(triface& t1, triface& t2);
  inline void esymself(triface& t);
  inline void enext(triface& t1, triface& t2);
  inline void enextself(triface& t);
  inline void eprev(triface& t1, triface& t2);
  inline void eprevself(triface& t);
  inline void enextesym(triface& t1, triface& t2);
  inline void enextesymself(triface& t);
  inline void eprevesym(triface& t1, triface& t2);
  inline void eprevesymself(triface& t);
  inline void eorgoppo(triface& t1, triface& t2);
  inline void eorgoppoself(triface& t);
  inline void edestoppo(triface& t1, triface& t2);
  inline void edestoppoself(triface& t);
  inline void fsym(triface& t1, triface& t2);
  inline void fsymself(triface& t);
  inline void fnext(triface& t1, triface& t2);
  inline void fnextself(triface& t);
  inline point org (triface& t);
  inline point dest(triface& t);
  inline point apex(triface& t);
  inline point oppo(triface& t);
  inline void setorg (triface& t, point p);
  inline void setdest(triface& t, point p);
  inline void setapex(triface& t, point p);
  inline void setoppo(triface& t, point p);
  inline REAL elemattribute(tetrahedron* ptr, int attnum);
  inline void setelemattribute(tetrahedron* ptr, int attnum, REAL value);
  inline REAL volumebound(tetrahedron* ptr);
  inline void setvolumebound(tetrahedron* ptr, REAL value);
  inline int  elemindex(tetrahedron* ptr);
  inline void setelemindex(tetrahedron* ptr, int value);
  inline int  elemmarker(tetrahedron* ptr);
  inline void setelemmarker(tetrahedron* ptr, int value);
  inline void infect(triface& t);
  inline void uninfect(triface& t);
  inline bool infected(triface& t);
  inline void marktest(triface& t);
  inline void unmarktest(triface& t);
  inline bool marktested(triface& t);
  inline void markface(triface& t);
  inline void unmarkface(triface& t);
  inline bool facemarked(triface& t);
  inline void markedge(triface& t);
  inline void unmarkedge(triface& t);
  inline bool edgemarked(triface& t);
  inline void marktest2(triface& t);
  inline void unmarktest2(triface& t);
  inline bool marktest2ed(triface& t);
  inline int  elemcounter(triface& t);
  inline void setelemcounter(triface& t, int value);
  inline void increaseelemcounter(triface& t);
  inline void decreaseelemcounter(triface& t);
  inline bool ishulltet(triface& t);
  inline bool isdeadtet(triface& t);

  // Primitives for subfaces and subsegments.
  inline void sdecode(shellface sptr, face& s);
  inline shellface sencode(face& s);
  inline shellface sencode2(shellface *sh, int shver);
  inline void spivot(face& s1, face& s2);
  inline void spivotself(face& s);
  inline void sbond(face& s1, face& s2);
  inline void sbond1(face& s1, face& s2);
  inline void sdissolve(face& s);
  inline point sorg(face& s);
  inline point sdest(face& s);
  inline point sapex(face& s);
  inline void setsorg(face& s, point pointptr);
  inline void setsdest(face& s, point pointptr);
  inline void setsapex(face& s, point pointptr);
  inline void sesym(face& s1, face& s2);
  inline void sesymself(face& s);
  inline void senext(face& s1, face& s2);
  inline void senextself(face& s);
  inline void senext2(face& s1, face& s2);
  inline void senext2self(face& s);
  inline REAL areabound(face& s);
  inline void setareabound(face& s, REAL value);
  inline int shellmark(face& s);
  inline void setshellmark(face& s, int value);
  inline void sinfect(face& s);
  inline void suninfect(face& s);
  inline bool sinfected(face& s);
  inline void smarktest(face& s);
  inline void sunmarktest(face& s);
  inline bool smarktested(face& s);
  inline void smarktest2(face& s);
  inline void sunmarktest2(face& s);
  inline bool smarktest2ed(face& s);
  inline void smarktest3(face& s);
  inline void sunmarktest3(face& s);
  inline bool smarktest3ed(face& s);
  inline void setfacetindex(face& f, int value);
  inline int  getfacetindex(face& f);

  // Primitives for interacting tetrahedra and subfaces.
  inline void tsbond(triface& t, face& s);
  inline void tsdissolve(triface& t);
  inline void stdissolve(face& s);
  inline void tspivot(triface& t, face& s);
  inline void stpivot(face& s, triface& t);

  // Primitives for interacting tetrahedra and segments.
  inline void tssbond1(triface& t, face& seg);
  inline void sstbond1(face& s, triface& t);
  inline void tssdissolve1(triface& t);
  inline void sstdissolve1(face& s);
  inline void tsspivot1(triface& t, face& s);
  inline void sstpivot1(face& s, triface& t);

  // Primitives for interacting subfaces and segments.
  inline void ssbond(face& s, face& edge);
  inline void ssbond1(face& s, face& edge);
  inline void ssdissolve(face& s);
  inline void sspivot(face& s, face& edge);

  // Primitives for points.
  inline int  pointmark(point pt);
  inline void setpointmark(point pt, int value);
  inline enum verttype pointtype(point pt);
  inline void setpointtype(point pt, enum verttype value);
  inline int  pointgeomtag(point pt);
  inline void setpointgeomtag(point pt, int value);
  inline REAL pointgeomuv(point pt, int i);
  inline void setpointgeomuv(point pt, int i, REAL value);
  inline void pinfect(point pt);
  inline void puninfect(point pt);
  inline bool pinfected(point pt);
  inline void pmarktest(point pt);
  inline void punmarktest(point pt);
  inline bool pmarktested(point pt);
  inline void pmarktest2(point pt);
  inline void punmarktest2(point pt);
  inline bool pmarktest2ed(point pt);
  inline void pmarktest3(point pt);
  inline void punmarktest3(point pt);
  inline bool pmarktest3ed(point pt);
  inline tetrahedron point2tet(point pt);
  inline void setpoint2tet(point pt, tetrahedron value);
  inline shellface point2sh(point pt);
  inline void setpoint2sh(point pt, shellface value);
  inline point point2ppt(point pt);
  inline void setpoint2ppt(point pt, point value);
  inline tetrahedron point2bgmtet(point pt);
  inline void setpoint2bgmtet(point pt, tetrahedron value);
  inline void setpointinsradius(point pt, REAL value);
  inline REAL getpointinsradius(point pt);
  inline bool issteinerpoint(point pt);

  // Advanced primitives.
  inline void point2tetorg(point pt, triface& t);
  inline void point2shorg(point pa, face& s);
  inline point farsorg(face& seg);
  inline point farsdest(face& seg);

  // Memory managment
  void tetrahedrondealloc(tetrahedron*);
  tetrahedron *tetrahedrontraverse();
  tetrahedron *alltetrahedrontraverse();
  void shellfacedealloc(memorypool*, shellface*);
  shellface *shellfacetraverse(memorypool*);
  void pointdealloc(point);
  point pointtraverse();

  void makeindex2pointmap(point*&);
  void makepoint2submap(memorypool*, int*&, face*&);
  void maketetrahedron(triface*);
  void makeshellface(memorypool*, face*);
  void makepoint(point*, enum verttype);

  void initializepools();

  // Symbolic perturbations (robust)
  REAL insphere_s(REAL*, REAL*, REAL*, REAL*, REAL*);

  // Triangle-edge intersection test (robust)
  int tri_edge_2d(point, point, point, point, point, point, int, int*, int*);
  int tri_edge_tail(point, point, point, point, point, point, REAL, REAL, int,
                    int*, int*);
  int tri_edge_test(point, point, point, point, point, point, int, int*, int*);

  // Linear algebra functions
  inline REAL dot(REAL* v1, REAL* v2);
  inline void cross(REAL* v1, REAL* v2, REAL* n);
  bool lu_decmp(REAL lu[4][4], int n, int* ps, REAL* d, int N);
  void lu_solve(REAL lu[4][4], int n, int* ps, REAL* b, int N);

  // Geometric calculations (non-robust)
  REAL orient3dfast(REAL *pa, REAL *pb, REAL *pc, REAL *pd);
  inline REAL norm2(REAL x, REAL y, REAL z);
  inline REAL distance(REAL* p1, REAL* p2);
  REAL incircle3d(point pa, point pb, point pc, point pd);
  void facenormal(point pa, point pb, point pc, REAL *n, int pivot, REAL *lav);
  bool tetalldihedral(point, point, point, point, REAL*, REAL*, REAL*);
  void tetallnormal(point, point, point, point, REAL N[4][3], REAL* volume);
  REAL tetaspectratio(point, point, point, point);
  bool circumsphere(REAL*, REAL*, REAL*, REAL*, REAL* cent, REAL* radius);
  void planelineint(REAL*, REAL*, REAL*, REAL*, REAL*, REAL*, REAL*);
  int linelineint(REAL*, REAL*, REAL*, REAL*, REAL*, REAL*, REAL*, REAL*);
  REAL tetprismvol(REAL* pa, REAL* pb, REAL* pc, REAL* pd);
  void calculateabovepoint4(point, point, point, point);

  // The elementary flips.
  void flip23(triface*, int, flipconstraints* fc);
  void flip32(triface*, int, flipconstraints* fc);
  void flip41(triface*, int, flipconstraints* fc);
  // A generalized edge flip.
  int flipnm(triface*, int n, int level, int, flipconstraints* fc);
  int flipnm_post(triface*, int n, int nn, int, flipconstraints* fc);
  // Point insertion.
  int  insertpoint(point, triface*, face*, face*, insertvertexflags*);
  void insertpoint_abort(face*, insertvertexflags*);

  // Point sorting.
  int  transgc[8][3][8], tsb1mod3[8];
  void hilbert_init(int n);
  int  hilbert_split(point* vertexarray, int arraysize, int gc0, int gc1,
                     REAL, REAL, REAL, REAL, REAL, REAL);
  void hilbert_sort3(point* vertexarray, int arraysize, int e, int d,
                     REAL, REAL, REAL, REAL, REAL, REAL, int depth);
  void brio_multiscale_sort(point*,int,int threshold,REAL ratio,int* depth);

  // Point location.
  unsigned long randomnation(unsigned int choices);
  void randomsample(point searchpt, triface *searchtet);
  enum locateresult locate(point searchpt, triface *searchtet);

  // Incremental flips.
  void flippush(badface*&, triface*);
  int  incrementalflip(point newpt, int, flipconstraints *fc);

  // Incremental Delaunay construction.
  void initialdelaunay(point pa, point pb, point pc, point pd);
  void incrementaldelaunay(clock_t&);

  // Surface meshing.
  void flipshpush(face*);
  void flip22(face*, int, int);
  void flip31(face*, int);
  long lawsonflip();
  int sinsertvertex(point newpt, face*, face*, int iloc, int bowywat, int);
  int sremovevertex(point delpt, face*, face*, int lawson);
  enum locateresult slocate(point, face*, int, int, int);

  // Boundary recovery
  enum interresult finddirection(triface* searchtet, point endpt);
  int checkflipeligibility(int fliptype, point, point, point, point, point,
                           int level, int edgepivot, flipconstraints* fc);

  int removeedgebyflips(triface*, flipconstraints*);
  int removefacebyflips(triface*, flipconstraints*);
  int recoveredgebyflips(point, point, triface*, int fullsearch);
  int add_steinerpt_in_schoenhardtpoly(triface*, int, int chkencflag);
  int add_steinerpt_in_segment(face*, int searchlevel);
  int addsteiner4recoversegment(face*, int);
  int recoversegments(arraypool*, int fullsearch, int steinerflag);
  int recoverfacebyflips(point, point, point, face*, triface*);
  int recoversubfaces(arraypool*, int steinerflag);
  int getvertexstar(int, point searchpt, arraypool*, arraypool*, arraypool*);
  int getedge(point, point, triface*);
  int reduceedgesatvertex(point startpt, arraypool* endptlist);
  int removevertexbyflips(point steinerpt);
  int suppressbdrysteinerpoint(point steinerpt);
  int suppresssteinerpoints();
  void recoverboundary(clock_t&);

  // Mesh reconstruct
  void carveholes();

  // Mesh optimize
  long lawsonflip3d(flipconstraints *fc);
  void recoverdelaunay();
  int  gettetrahedron(point, point, point, point, triface *);
  long improvequalitybyflips();
  int  smoothpoint(point smtpt, arraypool*, int ccw, optparameters *opm);
  long improvequalitybysmoothing(optparameters *opm);
  int  splitsliver(triface *, REAL, int);
  long removeslivers(int);
  void optimizemesh();

  // Constructor & desctructor.
  meshGRegionBoundaryRecovery()
  {
    in = new meshGRegionInputs();
    b = new meshGRegionOptions();
    bgm = NULL;

    tetrahedrons = subfaces = subsegs = points = NULL;
    badtetrahedrons = badsubfacs = badsubsegs = NULL;
    tet2segpool = tet2subpool = NULL;
    flippool = NULL;

    dummypoint = NULL;
    flipstack = NULL;
    unflipqueue = NULL;

    cavetetlist = cavebdrylist = caveoldtetlist = NULL;
    cavetetshlist = cavetetseglist = cavetetvertlist = NULL;
    caveencshlist = caveencseglist = NULL;
    caveshlist = caveshbdlist = cavesegshlist = NULL;

    subsegstack = subfacstack = subvertstack = NULL;

    numpointattrib = numelemattrib = 0;
    sizeoftensor = 0;
    pointmtrindex = 0;
    pointparamindex = 0;
    pointmarkindex = 0;
    point2simindex = 0;
    pointinsradiusindex = 0;
    elemattribindex = 0;
    volumeboundindex = 0;
    shmarkindex = 0;
    areaboundindex = 0;
    checksubsegflag = 0;
    checksubfaceflag = 0;
    checkconstraints = 0;
    nonconvex = 0;
    autofliplinklevel = 1;
    useinsertradius = 0;
    samples = 0l;
    randomseed = 1l;
    minfaceang = minfacetdihed = PI;
    tetprism_vol_sum = 0.0;
    longest = 0.0;
    xmax = xmin = ymax = ymin = zmax = zmin = 0.0;

    insegments = 0l;
    hullsize = 0l;
    meshedges = meshhulledges = 0l;
    steinerleft = -1;
    dupverts = 0l;
    unuverts = 0l;
    nonregularcount = 0l;
    st_segref_count = st_facref_count = st_volref_count = 0l;
    fillregioncount = cavitycount = cavityexpcount = 0l;
    flip14count = flip26count = flipn2ncount = 0l;
    flip23count = flip32count = flip44count = flip41count = 0l;
    flip22count = flip31count = 0l;
    totalworkmemory = 0l;
  }

  ~meshGRegionBoundaryRecovery()
  {
    delete in;
    delete b;

    if (points != (memorypool *) NULL) {
      delete points;
      delete [] dummypoint;
    }

    if (tetrahedrons != (memorypool *) NULL) {
      delete tetrahedrons;
    }

    if (subfaces != (memorypool *) NULL) {
      delete subfaces;
      delete subsegs;
    }

    if (tet2segpool != NULL) {
      delete tet2segpool;
      delete tet2subpool;
    }

    if (flippool != NULL) {
      delete flippool;
      delete unflipqueue;
    }

    if (cavetetlist != NULL) {
      delete cavetetlist;
      delete cavebdrylist;
      delete caveoldtetlist;
      delete cavetetvertlist;
    }

    if (caveshlist != NULL) {
      delete caveshlist;
      delete caveshbdlist;
      delete cavesegshlist;
      delete cavetetshlist;
      delete cavetetseglist;
      delete caveencshlist;
      delete caveencseglist;
    }

    if (subsegstack != NULL) {
      delete subsegstack;
      delete subfacstack;
      delete subvertstack;
    }
  }

  // Debug functions
  void outsurfacemesh(const char* mfilename);
  void outmesh2medit(const char* mfilename);

  void unifysubfaces(face *f1, face *f2);
  void unifysegments();
  void jettisonnodes();
  void reconstructmesh(GRegion *_gr);
};

void terminateBoundaryRecovery(void *, int exitcode);

#endif
