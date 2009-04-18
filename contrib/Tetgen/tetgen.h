///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// TetGen                                                                    //
//                                                                           //
// A Quality Tetrahedral Mesh Generator and 3D Delaunay Triangulator         //
//                                                                           //
// Develop version                                                           //
// Start: August 9, 2008                                                     //
//                                                                           //
// Copyright (C) 2002--2008                                                  //
// Hang Si                                                                   //
// Research Group: Numerical Mathematics and Scientific Computing            //
// Weierstrass Institute for Applied Analysis and Stochastics                //
// Mohrenstr. 39, 10117 Berlin, Germany                                      //
// si@wias-berlin.de                                                         //
//                                                                           //
// TetGen is freely available through the website: http://tetgen.berlios.de. //
//   It may be copied, modified, and redistributed for non-commercial use.   //
//   Please consult the file LICENSE for the detailed copyright notices.     //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#ifndef tetgenH
#define tetgenH

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// tetgen.h                                                                  //
//                                                                           //
// Header file of the TetGen library. Also is the user-level header file.    //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

// Header files for using the C/C++ standard library.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// TetGen Library                                                            //
//                                                                           //
// The library consists of three classes: tetgenio, tetgenbehavior, and      //
// tetgenmesh. Tetgenio provides interfaces for passing data into and out of //
// the library; tetgenbehavior keeps the runtime options and thus controls   //
// the behaviors of TetGen; tetgenmesh implements mesh data strcutures and   //
// algorithms for generating meshes.                                         //
//                                                                           //
// There are few global functions. tetrahedralize() is provided for calling  //
// TetGen from another program. Two functions: orient3d() and insphere() are //
// incorporated from a public C code provided by Shewchuk.  They performing  //
// exact geometrical tests.                                                  //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

// To compile TetGen as a library instead of an executable program, define
//   the TETLIBRARY symbol.

// #define TETLIBRARY

// Uncomment the following line to disable assert macros. These macros are
//   inserted in places where I hope to catch bugs.

// #define NDEBUG

// To insert lots of self-checks for internal errors, define the SELF_CHECK
//   symbol.  This will slow down the program significantly. 

// #define SELF_CHECK

// For single precision ( which will save some memory and reduce paging),
//   define the symbol SINGLE by using the -DSINGLE compiler switch or by
//   writing "#define SINGLE" below.
//
// For double precision ( which will allow you to refine meshes to a smaller
//   edge length), leave SINGLE undefined.

// #define SINGLE

#ifdef SINGLE
  #define REAL float
#else
  #define REAL double
#endif 	// not defined SINGLE

// Maximum number of characters in a file name (including the null).

enum {FILENAMESIZE = 1024};

// Maximum numbers of chars in a line read from a file (incl. the null).

enum {INPUTLINESIZE = 1024};

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// tetgenio    Passing data into and out of the library.                     //
//                                                                           //
// This class contains a collection of arrays which stores points, facets,   //
// tetrahedra, and so forth. TetGen will read and write these arrays accord- //
// ing to the options specified in a tetgenbehavior object. The arrays are   //
// corresponding to the fields defined in TetGen's input/output file formats.//
// If you want to use the library of TetGen, It is necessary to understand   //
// TetGen's input/output file formats (see user's manual).                   //
//                                                                           //
// Once an object of tetgenio is declared,  no array is created. One has to  //
// allocate enough memory for them, e.g., use the "new" operator in C++. On  //
// deletion of the object, the memory occupied by these arrays needs to be   //
// freed.  Routine deinitialize() will be automatically called. It will de-  //
// allocate the memory for an array if it is not a NULL. However, it assumes //
// that the memory is allocated by the C++ "new" operator. If you use malloc //
// (), you should free() them and set the pointers to NULLs before reaching  //
// deinitialize().                                                           //
//                                                                           //
// In all cases, the first item in an array is stored starting at index [0]. //
// However, that item is item number `firstnumber' which may be '0' or '1'.  //
// Be sure to set the 'firstnumber' be '1' if your indices pointing into the //
// pointlist is starting from '1'. Default, it is '0'.                       //
//                                                                           //
// Tetgenio also contains routines for reading and writing TetGen's files as //
// well.  Both the library of TetGen and TetView use these routines to parse //
// input files, i.e., .node, .poly, .smesh, .ele, .face, and .edge files.    //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

class tetgenio {

  public:

    // The polygon structure.  A "polygon" is a planar polygon which may be
    //   non-convex but contains no holes. 
    // 'vertexlist' is a list of vertices (indices) of the polygon odered in
    //   either counterclockwise or clockwise way. 
    
    typedef struct {
      int *vertexlist;
      int numberofvertices;
    } polygon;

    static void init(polygon* p) {
      p->vertexlist = (int *) NULL;
      p->numberofvertices = 0;
    }

    // The facet structure.  A "facet" is a facet. It may be non-convex and
    //   contains arbitrary number of holes. Hence it consistes of a list of
    //   polygons and a list holes.

    typedef struct {
      polygon *polygonlist;
      int numberofpolygons;
      REAL *holelist;
      int numberofholes;
    } facet;

    static void init(facet* f) {
      f->polygonlist = (polygon *) NULL;
      f->numberofpolygons = 0;
      f->holelist = (REAL *) NULL;
      f->numberofholes = 0;
    }

    // A 'voroedge' is an edge of the Voronoi diagram. It corresponds to a
    //   Delaunay face.  Each voroedge is either a line segment connecting
    //   two Voronoi vertices or a ray starting from a Voronoi vertex to an
    //   "infinite vertex".  'v1' and 'v2' are two indices pointing to the
    //   list of Voronoi vertices. 'v1' must be non-negative, while 'v2' may
    //   be -1 if it is a ray, in this case, the unit normal of this ray is
    //   given in 'vnormal'. 
    
    typedef struct {
      int v1, v2;
      REAL vnormal[3];
    } voroedge;

    // A 'vorofacet' is an facet of the Voronoi diagram. It corresponds to a
    //   Delaunay edge.  Each Voronoi facet is a convex polygon formed by a
    //   list of Voronoi edges, it may not be closed.  'c1' and 'c2' are two
    //   indices pointing into the list of Voronoi cells, i.e., the two cells
    //   share this facet.  'elist' is an array of indices pointing into the
    //   list of Voronoi edges, 'elist[0]' saves the number of Voronoi edges
    //   (including rays) of this facet.
    
    typedef struct {
      int c1, c2;
      int *elist;
    } vorofacet;

    // The periodic boundary condition group data structure.  A "pbcgroup"
    //   contains the definition of a pbc and the list of pbc point pairs.
    //   'fmark1' and 'fmark2' are the facetmarkers of the two pbc facets f1
    //   and f2, respectively. 'transmat' is the transformation matrix which
    //   maps a point in f1 into f2.  An array of pbc point pairs are saved
    //   in 'pointpairlist'. The first point pair is at indices [0] and [1],
    //   followed by remaining pairs. Two integers per pair.
    
    typedef struct {
      int fmark1, fmark2;
      REAL transmat[4][4];
      int numberofpointpairs;
      int *pointpairlist;
    } pbcgroup;

  public:

    // Items are numbered starting from 'firstnumber' (0 or 1), default is 0.
    int firstnumber; 
    // Dimension of the mesh (2 or 3), default is 3.
    int mesh_dim;
    // Does the lines in .node file contain index or not, default is TRUE.
    bool useindex;

    // 'pointlist':  The array of point coordinates.  The first point's x
    //   coordinate is at index [0] and its y coordinate at index [1], its
    //   z coordinate is at index [2], followed by the coordinates of the
    //   remaining points.  Each point occupies three REALs. 
    // 'pointattributelist':  An array of point attributes.  Each point's
    //   attributes occupy 'numberofpointattributes' REALs.
    // 'pointmtrlist': An array of metric tensors at points. Each point's
    //   tensor occupies 'numberofpointmtr' REALs.
    // 'pointmarkerlist':  An array of point markers; one int per point.
    
    REAL *pointlist;
    REAL *pointattributelist;
    REAL *pointmtrlist;
    int *pointmarkerlist;
    int numberofpoints;
    int numberofpointattributes;
    int numberofpointmtrs;
 
    // 'tetrahedronlist':  The array of tetrahedra.  The first tet's first
    //   node is at index [0], followed by its other nodes, optionally
    //   followed by quadratc nodes of the tet.  Each tet occupies
    //   'numberofcorners' (4 or 6) ints.
    // 'tetrahedronattributelist':  The array of tet attributes.  Each tet
    //   has `numberoftetrahedronattributes' REALs.
    // 'tetrahedronvolumelist':  The array of constraints, i.e. tetrahedron's
    //   maximum volume; one REAL per element. Input only.
    // 'neighborlist':  The array of element neighbors; 'numberofcorners'
    //   ints per element. Output only.
    
    int *tetrahedronlist;
    REAL *tetrahedronattributelist;
    REAL *tetrahedronvolumelist;
    int *neighborlist;
    int numberoftetrahedra;
    int numberofcorners;
    int numberoftetrahedronattributes;

    // `facetlist':  The array of facets.  Each entry is a structure of facet.
    // `facetmarkerlist':  An array of facet markers; one int per facet.
    
    facet *facetlist;
    int *facetmarkerlist;
    int numberoffacets;

    // `holelist':  The array of volume holes.  The first hole's x, y and z
    //   coordinates  are at indices [0], [1] and [2], followed by the
    //   remaining holes. Three REALs per hole. 
    
    REAL *holelist;
    int numberofholes;

    // `regionlist': The array of regional attributes and volume constraints.
    //   The first constraint's x, y and z coordinates are at indices [0],
    //   [1] and [2], followed by the regional attribute at index [3], foll-
    //   owed by the maximum volume at index [4]. Five REALs per constraint. 
    // Note that each regional attribute is used only if you select the `A'
    //   switch, and each volume constraint is used only if you select the
    //   `a' switch (with no number following).
    
    REAL *regionlist;
    int numberofregions;

    // `facetconstraintlist': The array of facet maximal area constraints.
    //   Two REALs per constraint. The first one is the facet marker (cast
    //   it to int), the second is its maximum area bound.
    // Note the 'facetconstraintlist' is used only for the 'q' switch. 
    
    REAL *facetconstraintlist;
    int numberoffacetconstraints;

    // `segmentconstraintlist': The array of segment max. length constraints.
    //   Three REALs per constraint. The first two are the indices (pointing
    //   into 'pointlist') of the endpoints of the segment, the third is its
    //   maximum length bound.
    // Note the 'segmentconstraintlist' is used only for the 'q' switch.
     
    REAL *segmentconstraintlist;
    int numberofsegmentconstraints;

    // 'pbcgrouplist':  The array of periodic boundary condition groups.
    
    pbcgroup *pbcgrouplist;
    int numberofpbcgroups;

    // `trifacelist':  The array of triangluar face list.  The first face's
    //   endpoints are at indices [0], [1] and [2], followed by the
    //   remaining faces.  Three ints per face.
    // `adjtetlist':  The array of adjacent tets. Each face has at most two
    //   adjacent tets, the first face's adjacent tets are at [0], [1]. Two
    //   ints per face. A '-1' indicates outside (no adj. tet).  This list
    //   is output when '-nn' switch is used.
    // `trifacemarkerlist':  The array of face markers; one int per face.
    
    int *trifacelist;
    int *adjtetlist;
    int *trifacemarkerlist;
    int numberoftrifaces;

    // `edgelist':  The array of edges (or segments).  The first edge's 
    //   endpoints are at indices [0] and [1], followed by the remaining 
    //   edges.  Two ints per edge.
    // `edgemarkerlist':  The array of edge markers; one int per edge.
    
    int *edgelist;
    int *edgemarkerlist;
    int numberofedges;

    // 'vpointlist':  The array of Voronoi vertex coordinates (like pointlist).
    // 'vedgelist':  The array of Voronoi edges.  Each entry is a 'voroedge'.
    // 'vfacetlist':  The array of Voronoi facets. Each entry is a 'vorofacet'.
    // 'vcelllist':  The array of Voronoi cells.  Each entry is an array of
    //   indices pointing into 'vfacetlist'. The 0th entry is used to store
    //   the length of this array.
    
    REAL *vpointlist;
    voroedge *vedgelist;
    vorofacet *vfacetlist;
    int **vcelllist;
    int numberofvpoints;
    int numberofvedges;
    int numberofvfacets;
    int numberofvcells;

  public:

    // Initialize routine.
    void initialize();
    void deinitialize();

    // Input & output routines.
    bool load_node_call(FILE* infile, int markers, const char* nodefilename);
    bool load_node(const char* filename);
    bool load_pbc(const char* filename);
    bool load_var(const char* filename);
    bool load_mtr(const char* filename);
    bool load_poly(const char* filename);
    bool load_off(const char* filename);
    bool load_ply(const char* filename);
    bool load_stl(const char* filename);
    bool load_medit(const char* filename);
    bool load_vtk(const char* filename);
    bool load_plc(const char* filename, int object);
    bool load_tetmesh(const char* filename);
    bool load_voronoi(const char* filename);
    void save_nodes(const char* filename);
    void save_elements(const char* filename);
    void save_faces(const char* filename);
    void save_edges(const char* filename);
    void save_neighbors(const char* filename);
    void save_poly(const char* filename);

    // Read line and parse string functions.
    char *readline(char* string, FILE* infile, int *linenumber);
    char *findnextfield(char* string);
    char *readnumberline(char* string, FILE* infile, const char* infilename);
    char *findnextnumber(char* string);

    // Constructor and destructor.
    tetgenio() {initialize();}
    ~tetgenio() {deinitialize();}
};

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// tetgenbehavior    Parsing command line switches and file names.           //
//                                                                           //
// It includes a list of variables corresponding to the commandline switches //
// for control the behavior of TetGen.  These varibales are all initialized  //
// to their default values.                                                  //
//                                                                           //
// Use function parse_commandline() to set the vaules of the variables.  It  //
// accepts the standard parameters (e.g., 'argc' and 'argv') that pass to C  //
// & C++ main() function. Alternatively a string which contains the command  //
// line options can be used as its parameter.  Please refer to the User's    //
// manula for the availble options of TetGen.                                //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

class tetgenbehavior {    // Begin of class tetgenbehavior

  public:

  // Labels defining the input objects supported by TetGen. They are 
  //   identified from the file extension of the inputs.
  //   - NODES, a list of nodes (.node); 
  //   - POLY, a piecewise linear complex (.poly or .smesh); 
  //   - OFF, a polyhedron (.off, Geomview's file format); 
  //   - PLY, a polyhedron (.ply, file format from gatech);
  //   - STL, a surface mesh (.stl, stereolithography format);
  //   - MEDIT, a surface mesh (.mesh, Medit's file format); 
  //   - MESH, a tetrahedral mesh (.ele).
  //   If no extension is available, the imposed commandline switch
  //   (-p or -r) implies the type of the object. 

  enum objecttype {NONE, NODES, POLY, OFF, PLY, STL, MEDIT, VTK, MESH};

  // Variables of command line switches. Each variable corresponds to a
  //   switch. Most of them are initialized to 0.

  int plc;                                                           // -p
  int quality;                                                       // -q
  int refine;                                                        // -r
  int coarse;                                                        // -R
  int metric;                                                        // -m
  int varvolume;                                    // -a without a number
  int fixedvolume;                                     // -a with a number
  int bowyerwatson;                                                  // -b
  int convexity;                                                     // -c
  int insertaddpoints;                                               // -i
  int regionattrib;                                                  // -A
  int conformdel;                                                    // -D
  int diagnose;                                                      // -d
  int zeroindex;                                                     // -z
  int order;                                                         // -o
  int facesout;                                                      // -f
  int edgesout;                                                      // -e
  int neighout;                                                      // -n
  int voroout;                                                       // -v
  int meditview;                                                     // -g
  int gidview;                                                       // -G
  int geomview;                                                      // -O
  int nobound;                                                       // -B
  int nonodewritten;                                                 // -N
  int noelewritten;                                                  // -E
  int nofacewritten;                                                 // -F
  int noiterationnum;                                                // -I
  int nomerge;                                                       // -M
  int nobisect;                                                      // -Y
  int nojettison;                                                    // -J
  int steiner;                                         // -S with a number
  int docheck;                                                       // -C
  int quiet;                                                         // -Q
  int verbose;                                                       // -V
  int useshelles;                                 // -p, -r, -q, -d, or -R
  REAL minratio;                                        // number after -q
  REAL goodratio;                     // number calculated from 'minratio' 
  REAL minangle;                                    // minimum angle bound
  REAL goodangle;                            // cosine squared of minangle
  REAL maxvolume;                                       // number after -a
  REAL mindihedral;                                    // number after -qq
  REAL maxdihedral;                                   // number after -qqq
  REAL epsilon;                                         // number after -T
  enum objecttype object;                       // determined by -p, or -r

  // Variables used to save command line switches and in/out file names.
  char commandline[1024];
  char infilename[1024];
  char outfilename[1024];
  char addinfilename[1024];
  char bgmeshfilename[1024];

  void versioninfo();
  void syntax();
  void usage();

  // Command line parse routine.
  bool parse_commandline(int argc, char **argv);
  bool parse_commandline(char *switches) {
    return parse_commandline(0, &switches);
  }
  
  tetgenbehavior();
  ~tetgenbehavior() {}  
};

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Geometric predicates                                                      //
//                                                                           //
// Return one of the values +1, 0, and -1 on basic geometric questions such  //
// as the orientation of point sets, in-circle, and in-sphere tests.  They   //
// are basic units for implmenting geometric algorithms.  TetGen uses two 3D //
// geometric predicates: the orientation and in-sphere tests.                //
//                                                                           //
// Orientation test:  let a, b, c be a sequence of 3 non-collinear points in //
// R^3.  They defines a unique hypeplane H.  Let H+ and H- be the two spaces //
// separated by H, which are defined as follows (using the left-hand rule):  //
// make a fist using your left hand in such a way that your fingers follow   //
// the order of a, b and c, then your thumb is pointing to H+.  Given any    //
// point d in R^3, the orientation test returns +1 if d lies in H+, -1 if d  //
// lies in H-, or 0 if d lies on H.                                          //
//                                                                           //
// In-sphere test:  let a, b, c, d be 4 non-coplanar points in R^3.  They    //
// defines a unique circumsphere S.  Given any point e in R^3, the in-sphere //
// test returns +1 if e lies inside S, or -1 if e lies outside S, or 0 if e  //
// lies on S.                                                                //
//                                                                           //
// The correctness of geometric predicates is crucial for the control flow   //
// and hence for the correctness and robustness of an implementation of a    //
// geometric algorithm.  The following routines use arbitrary precision      //
// floating-point arithmetic. They are fast and robust. It is provided by J. //
// Schewchuk in public domain (http://www.cs.cmu.edu/~quake/robust.html).    //
// The source code are found in a separate file "predicates.cxx".            //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

REAL exactinit();
REAL orient3d(REAL *pa, REAL *pb, REAL *pc, REAL *pd);
REAL insphere(REAL *pa, REAL *pb, REAL *pc, REAL *pd, REAL *pe);

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Class tetgenmesh                                                          //
//                                                                           //
// An object of tetgenmesh can be used to store a triangular or tetrahedral  //
// mesh and its settings. TetGen's functions operates on one mesh each time. //
// This type allows reusing of the same function for different meshes.       //
//                                                                           //
// The mesh data structure (tetrahedron-based and triangle-edge data struct- //
// ures) are declared. There are other accessary data type defined as well,  //
// for efficient memory management and link list operations, etc.            //
//                                                                           //
// All algorithms TetGen used are implemented in this data type as member    //
// functions. References of these algorithms can be found in user's manual.  //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
class tetgenmesh {  // Begin of class tetgenmesh
///////////////////////////////////////////////////////////////////////////////

public:
  
// For efficiency, a variety of data structures are allocated in bulk.
//   The following constants determine how many of each structure is
//   allocated at once.

enum {VERPERBLOCK = 4092, SUBPERBLOCK = 4092, ELEPERBLOCK = 8188};
    
// Labels that signify whether a record consists primarily of pointers
//   or of floating-point words. Used for data alignment in memorypool.

enum wordtype {POINTER, FLOATINGPOINT};

// Labels that signify the type of a vertex. 

enum verttype {UNUSEDVERTEX, DUPLICATEDVERTEX, VOLVERTEX, RIDGEVERTEX, 
  ACUTEVERTEX, FACETVERTEX, STEINERVERTEX, DEADVERTEX};

// Labels that signify the result of point location.

enum location {INTET, ONFACE, ONEDGE, ONVERTEX, OUTSIDE, ENCSEGMENT, ENCFACE};

// Labels that signify the result of intersection tests.

enum intersection {DISJOINT, INTERSECT, SHAREVERT, SHAREEDGE, SHAREFACE,
  TOUCHEDGE, TOUCHFACE, ACROSSVERT, ACROSSEDGE, ACROSSFACE, ACROSSTET,
  TRIEDGEINT, EDGETRIINT, COLLISIONFACE, ACROSSSUBSEG, ACROSSSUBFACE};

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Mesh data structures                                                      //
//                                                                           //
// There are four types of mesh elements: tetrahedra, subfaces, subsegments, //
// and points,  where subfaces and subsegments are triangles and edges which //
// appear on boundaries.  The elements of all the four types consist of a    //
// tetrahedral mesh of a 3D domain.  TetGen uses three data types:  'tetra-  //
// hedron', 'shellface', and 'point'. A 'tetrahedron' is a tetrahedron;  a   //
// 'shellface' represents either a subface or a subsegment;  and a 'point'   //
// is a point.  These three data types, linked by pointers comprise a mesh.  //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

// The tetrahedron data structure.  
typedef REAL **tetrahedron;

// The shellface data structure. 
typedef REAL **shellface;

// The point data structure.  
typedef REAL *point;

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Mesh handles                                                              //
//                                                                           //
// Two special data types, 'triface' and 'face' are defined for maintaining  //
// and updating meshes. They are like pointers (or handles), which allow you //
// to hold one particular part of the mesh, i.e., a tetrahedron, a triangle, //
// an edge and a vertex.  However, these data types do not themselves store  //
// any part of the mesh. The mesh is made of the data types defined above.   //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

// A 'triface' holds a tetrahedron 'tet'. In particular, it holds one
//   edge of a face of the tetrahedron.  Since each tetrahedron has 4
//   faces and each face has 6 directed edges, hence there are total
//   24 different edges in 'tet'. Each edge of 'tet' is represented by
//   a pair (loc, ver), where 'loc' (range from 0 to 3) indicates a face
//   of 'tet', and 'ver' (range from 0 to 5) indicates a directed edge
//   edge of that face.

class triface {

  public:

  tetrahedron* tet;
  int loc, ver;

  // Constructors;
  triface() : tet(0), loc(0), ver(0) {}
  // Operators;
  triface& operator=(const triface& t) {
    tet = t.tet; loc = t.loc; ver = t.ver;
    return *this;
  }
  bool operator==(triface& t) {
    return tet == t.tet && loc == t.loc && ver == t.ver;
  }
  bool operator!=(triface& t) {
    return tet != t.tet || loc != t.loc || ver != t.ver;
  }
};

// A 'face' holds a shellface 'sh'. In particular, it holds one directed
//   edge of the shellface. There are 6 directed edges in a triangle.
//   'shver' (range from 0 to 5) indicates a directed edge in 'sh'.

class face {

  public:

  shellface *sh;
  int shver;

  // Constructors;
  face() : sh(0), shver(0) {}
  // Operators;
  face& operator=(const face& s) {
    sh = s.sh; shver = s.shver;
    return *this;
  }
  bool operator==(face& s) {return (sh == s.sh) && (shver == s.shver);}
  bool operator!=(face& s) {return (sh != s.sh) || (shver != s.shver);}
};

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Arraypool    A dynamic array                                              //
//                                                                           //
// Each arraypool contains an array of pointers to a number of blocks.  Each //
// block contains the same fixed number of objects.  Each index of the array //
// addesses a particular object in the pool.  The most significant bits add- //
// ress the index of the block containing the object. The less significant   //
// bits address this object within the block.                                //
//                                                                           //
// 'objectbytes' is the size of one object in blocks; 'log2objectsperblock'  //
// is the base-2 logarithm of 'objectsperblock'; 'objects' counts the number //
// of allocated objects; 'totalmemory' is the totoal memorypool in bytes.    //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

class arraypool {

  public:

  int objectbytes;
  int objectsperblock;
  int log2objectsperblock; 
  int toparraylen;
  char **toparray;
  unsigned long objects;
  unsigned long totalmemory;

  void restart();
  void poolinit(int sizeofobject, int log2objperblk);
  char* getblock(int objectindex);
  void* lookup(int objectindex);
  int newindex(void **newptr);

  arraypool(int sizeofobject, int log2objperblk);
  ~arraypool();
};

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Memorypool    A dynamic pool of memory                                    //
//                                                                           //
// A type used to allocate memory written by J. Shewchuk.                    //
//                                                                           //
// firstblock is the first block of items. nowblock is the block from which  //
//   items are currently being allocated. nextitem points to the next slab   //
//   of free memory for an item. deaditemstack is the head of a linked list  //
//   (stack) of deallocated items that can be recycled.  unallocateditems is //
//   the number of items that remain to be allocated from nowblock.          //
//                                                                           //
// Traversal is the process of walking through the entire list of items, and //
//   is separate from allocation.  Note that a traversal will visit items on //
//   the "deaditemstack" stack as well as live items.  pathblock points to   //
//   the block currently being traversed.  pathitem points to the next item  //
//   to be traversed.  pathitemsleft is the number of items that remain to   //
//   be traversed in pathblock.                                              //
//                                                                           //
// itemwordtype is set to POINTER or FLOATINGPOINT, and is used to suggest   //
//   what sort of word the record is primarily made up of.  alignbytes       //
//   determines how new records should be aligned in memory.  itembytes and  //
//   itemwords are the length of a record in bytes (after rounding up) and   //
//   words.  itemsperblock is the number of items allocated at once in a     //
//   single block.  items is the number of currently allocated items.        //
//   maxitems is the maximum number of items that have been allocated at     //
//   once; it is the current number of items plus the number of records kept //
//   on deaditemstack.                                                       //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

class memorypool {

  public:

  void **firstblock, **nowblock;
  void *nextitem;
  void *deaditemstack;
  void **pathblock;
  void *pathitem;
  wordtype itemwordtype;
  int  alignbytes;
  int  itembytes, itemwords;
  int  itemsperblock;
  long items, maxitems;
  int  unallocateditems;
  int  pathitemsleft;

  void poolinit(int, int, enum wordtype, int);
  void restart();
  void *alloc();
  void dealloc(void*);
  void traversalinit();
  void *traverse();

  memorypool() {}
  memorypool(int, int, enum wordtype, int);
  ~memorypool();
};

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// The badface structure                                                     //
//                                                                           //
// A multiple usages structure. Despite of its name, a 'badface' can be used //
// to represent the following objects:                                       //
//   - a face of a tetrahedron which is (possibly) non-Delaunay;             //
//   - an encroached subsegment or subface;                                  //
//   - a bad-quality tetrahedron, i.e, has too large radius-edge ratio;      //
//   - a sliver, i.e., has good radius-edge ratio but nearly zero volume;    //
//   - a degenerate tetrahedron (see routine checkdegetet()).                //
//   - a recently flipped face (saved for undoing the flip later).           //
//                                                                           //
// It has the following fields:  'tt' holds a tetrahedron; 'ss' holds a sub- //
// segment or subface; 'cent' is the circumcent of 'tt' or 'ss', 'key' is a  //
// special value depending on the use, it can be either the square of the    //
// radius-edge ratio of 'tt' or the flipped type of 'tt';  'forg', 'fdest',  //
// 'fapex', and 'foppo' are vertices saved for checking the object in 'tt'   //
// or 'ss' is still the same when it was stored; 'noppo' is the fifth vertex //
// of a degenerate point set.  'previtem' and 'nextitem' implement a double  //
// link for managing many basfaces.                                          //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

struct badface {
  triface tt; 
  face ss; 
  REAL key;
  REAL cent[3];
  point forg, fdest, fapex, foppo, noppo;
  struct badface *previtem, *nextitem; 
};

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Fast Lookup Tables                                                        //
//                                                                           //
// The mesh data structures additionally store geometric informations which  //
// help for fast queries.                                                    //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

// For enext() primitive, uses 'ver' as the key.
static int ve[6], ve2[6];

// For sorg(), sdest, spaex(), use 'shver' as the key.
static int vo[6], vd[6], va[6];

// For bond(), t1 and t2 are two symmetric faces sharing the same edges, it
//   takes t1's and t2's edge versions as the first and second keys, returns
//   t2's edge corresponds to t1's 0th edge.
// Note: the returned edge version is in {0, 2, 4}. The same follows.
static int verver2zero[6][6];

// For bond(), t1's edge corresponds to t2's 0th edge, it takes t1's edge
//   version as the key, returns t2's edge corresponds to t1's 0th edge.
static int ver2zero[6];

// For fnext(), symedge(), t1 and t2 share the same face, and t2's edge
//   corresponds to t1's 0th edge, it takes t1's and t2's edge versions as
//   the first and second keys, return t2's edge corresponds to t1's edge. 
static int zero2ver[6][6];

// For org(), dest() and apex() primitives, use ('loc', 'ver') as the key.
static int locver2org[4][6];
static int locver2dest[4][6];
static int locver2apex[4][6];

// For oppo() primitives, uses 'loc' as the key.
static int loc2oppo[4];

// For fnext() primitives, uses ('loc' * 8 + 'ver') as the key. Returns
//   an array containing a new ('loc', 'ver'). 
// Note: Only valid for 'ver' equals one of {0, 2, 4}.
static int locver2nextf[32];

// Twos maps between ('loc', 'ver') and the edge number (from 0 to 5).
static int locver2edge[4][6];
static int edge2locver[6][2];

// The map from a given face ('loc') to the other three faces in the tet.
//   and the map from a given face's edge ('loc', 'ver') to other two
//   faces in the tet opposite to this edge. (used in speeding the Bowyer-
//   Watson cavity construction).
static int locpivot[4][3];
static int locverpivot[4][6][2];

static int mi1mo3[3];

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Mesh manipulation primitives                                              //
//                                                                           //
// Mesh navigation and updating are accomplished through a set of mesh       //
// manipulation primitives which operate on trifaces and faces.  They are    //
// introduced below.                                                         //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Primitives for tetrahedron                                                //
//                                                                           //
// Each tetrahedron contains four pointers to its adjacent tetrahedra, with  //
// their face indices (loc in [0, 3]) and edge versions (ver in [0, 5]).  To //
// save memory, all informations of an adjacent tetrahedron are compressed   //
// in a single pointer. To make this possible, all tetrahedra are aligned to //
// 16-byte boundaries, so that the last four bits of each pointer are zeros. //
// Each face indice (loc) is compressed into the last two bits,  each edge   //
// version (ver) is compressed into the second last two bits of the pointer, //
// respectively. encode() and decode() functions implement this feature.     //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

// encode() -- to compress a triface 't' into a single pointer. 
//   't.ver' is in [0, 5], first we map it to [0, 2], this is equal to
//   divide it by 2 (>> 1), next we shift it to the second last two bits
//   of the pointer, this is equal to multiply it by 4 (<< 2). 
// Note: Do not combine the bit options for (t).ver.

#define encode(t) (tetrahedron) ((unsigned long) (t).tet | \
  ((unsigned long) (((t).ver >> 1) << 2)) | (unsigned long) (t).loc)

// decode() -- to decompose a pointer 'ptr' into a triface 't'. 
//   For obtaining t.ver, we first extract it (& 12l), then shift it to
//   the right by 2 bits (>> 2), then multiply it by 2 (<< 1), hence 
//   t.ver is in {0,2,4}. Combining the last two operations, we only
//   need to divide it by 2 (>> 1).

#define decode(ptr, t) \
  (t).loc = (int) ((unsigned long) (ptr) & (unsigned long) 3l);\
  (t).ver = (int) (((unsigned long) (ptr) & (unsigned long) 12l) >> 1);\
  (t).tet = (tetrahedron *) ((unsigned long) (ptr) & ~(unsigned long) 15l)
    
// sym() -- given triface 't1', get a triface 't2', where 't1' and 't2'
//   are the same face in two adjacent tetrahedra. But they may not be 
//   the same edge. (Refer to bond() function.)
    
#define sym(t1, t2) decode((t1).tet[(t1).loc], (t2))
    
#define symself(t) \
  ptr = (t).tet[(t).loc];\
  decode(ptr, (t))
  
// symedge() -- given triface 't1', get a triface 't2', where 't1' and 't2'
//   are the same face and the same edge in two adjacent tetrahedra.
// Require "tetrahedron ptr;" and "int tver".

#define symedge(t1, t2) \
  decode((t1).tet[(t1).loc], (t2));\
  (t2).ver = zero2ver[(t1).ver][(t2).ver]

#define symedgeself(t) \
  ptr = (t).tet[(t).loc];\
  tver = (t).ver;\
  decode(ptr, (t));\
  (t).ver = zero2ver[tver][(t).ver];

// org(), dest(), apex(), oppo() -- return the origin, destination, apex,
//   and opposite vertices of the triface.
    
#define org(t) (point) (t).tet[locver2org[(t).loc][(t).ver] + 4]

#define dest(t) (point) (t).tet[locver2dest[(t).loc][(t).ver] + 4]

#define apex(t) (point) (t).tet[locver2apex[(t).loc][(t).ver] + 4]

#define oppo(t) (point) (t).tet[loc2oppo[(t).loc] + 4]

#define setorg(t, p) \
  (t).tet[locver2org[(t).loc][(t).ver] + 4] = (tetrahedron) (p)

#define setdest(t, p) \
  (t).tet[locver2dest[(t).loc][(t).ver] + 4] = (tetrahedron) (p)

#define setapex(t, p) \
  (t).tet[locver2apex[(t).loc][(t).ver] + 4] = (tetrahedron) (p)

#define setoppo(t, p) (t).tet[loc2oppo[(t).loc] + 4] = (tetrahedron) (p)

#define setvertices(t, p1, p2, p3, p4) \
  setorg(t, p1); \
  setdest(t, p2); \
  setapex(t, p3); \
  setoppo(t, p4)

// esym(), enext(), enext2() -- primitives for moving edges in face.
//   The face remains the same.

#define esym(t1, t2) \
  (t2).tet = (t1).tet; (t2).loc = (t1).loc;\
  (t2).ver = (t1).ver + (((t1).ver & 01) ? -1 : 1)

#define esymself(t) (t).ver += (((t).ver & 01) ? -1 : 1)

#define enext(t1, t2) \
  (t2).tet = (t1).tet; (t2).loc = (t1).loc;\
  (t2).ver = ve[(t1).ver]

#define enextself(t) (t).ver = ve[(t).ver]

#define enext2(t1, t2) \
  (t2).tet = (t1).tet; (t2).loc = (t1).loc;\
  (t2).ver = ve2[(t1).ver]

#define enext2self(t) (t).ver = ve2[(t).ver]

// enextfnext(), enext2fnext() -- primitives for moving faces in tet.
//   the tetrahedron remains the same. 
// Note: The input edge version is in {0, 2, 4}.

#define enext0fnext(t1, t2) \
  iptr = &(locver2nextf[(t1).loc * 8 + (t1).ver]);\
  (t2).tet = (t1).tet;\
  (t2).loc = iptr[0];\
  (t2).ver = iptr[1]

#define enext0fnextself(t) \
  iptr = &(locver2nextf[(t).loc * 8 + (t).ver]);\
  (t).loc = iptr[0];\
  (t).ver = iptr[1]

#define enextfnext(t1, t2) \
  iptr = &(locver2nextf[(t1).loc * 8 + ve[(t1).ver]]);\
  (t2).tet = (t1).tet;\
  (t2).loc = iptr[0];\
  (t2).ver = iptr[1]

#define enextfnextself(t) \
  iptr = &(locver2nextf[(t).loc * 8 + ve[(t).ver]]);\
  (t).loc = iptr[0];\
  (t).ver = iptr[1]

#define enext2fnext(t1, t2) \
  iptr = &(locver2nextf[(t1).loc * 8 + ve2[(t1).ver]]);\
  (t2).tet = (t1).tet;\
  (t2).loc = iptr[0];\
  (t2).ver = iptr[1]

#define enext2fnextself(t) \
  iptr = &(locver2nextf[(t).loc * 8 + ve2[(t).ver]]);\
  (t).loc = iptr[0];\
  (t).ver = iptr[1]

// fnext() -- given an edge (i, j) of a face (i, j, k1) = t1, find the
//   next face t2 in the face ring of (i, j), i.e. a face (i, j, k2),
//   where (i, j, k1) and (i, j, k2) belong to two tetrahedra.
    
void fnext(triface& t1, triface& t2) {
  int *iptr;
  if (t1.ver & 01) {
    // Get the adjacent tet.
    decode(t1.tet[t1.loc], t2);
    // Adjust the edge (see Fig. fnext-base).
    t2.ver = zero2ver[t1.ver][t2.ver];
    // Go to the next face in t2.
    iptr = &(locver2nextf[t2.loc * 8 + t2.ver]);
    t2.loc = iptr[0];
    t2.ver = iptr[1];
  } else {
    // Go to the next face in t1.
    iptr = &(locver2nextf[t1.loc * 8 + t1.ver]);
    // Get the adjacent tet.
    decode(t1.tet[iptr[0]], t2);
    // Adjust the edge (see Fig. fnext-base).
    t2.ver = zero2ver[iptr[1]][t2.ver];
  }
}

void fnextself(triface& t) {
  tetrahedron ptr;
  int *iptr, tver;
  if (t.ver & 01) {
    ptr = t.tet[t.loc];
    tver = t.ver;
    decode(ptr, t);
    t.ver = zero2ver[tver][t.ver];
    iptr = &(locver2nextf[t.loc * 8 + t.ver]);
    t.loc = iptr[0];
    t.ver = iptr[1]; 
  } else {
    iptr = &(locver2nextf[t.loc * 8 + t.ver]);
    ptr = t.tet[iptr[0]];
    decode(ptr, t);
    t.ver = zero2ver[iptr[1]][t.ver];
  }
}

// bond() -- to setup the connections between 't1.loc' <==> 't2.loc'.
//   From t1 <-- t2, we bond the edge in 't2' corresponding to the 0-th
//   edge in 't1', and vice versa for t1 --> t2.
// NOTE: We assume that t1 and t2 refer to the same edge on input.  

void bond(triface& t1, triface& t2) {
  // We will modify edge vers, backup them.
  int t1ver = t1.ver, t2ver = t2.ver;
  // Find t2's edge corresponds to the t1's 0th edge.
  t2.ver = verver2zero[t1.ver][t2.ver];
  // t1 <-- t2
  t1.tet[t1.loc] = encode(t2);
  // Find t1's edge corresponds to t2's 0th edge.
  t1.ver = ver2zero[t2.ver];
  // t1 --> t2
  t2.tet[t2.loc] = encode(t1);
  // Restore the original vers.
  t1.ver = t1ver; t2.ver = t2ver;
}

// elemmarker() -- to read or set element's marker.

#define elemmarker(ptr) ((int *) (ptr))[elemmarkerindex]

// elemattribute() -- to check or set element attributes.

#define elemattribute(ptr, num) (((REAL *) (ptr))[elemattribindex + num])

#define setelemattribute(ptr, num, value) \
  ((REAL *) (ptr))[elemattribindex + num] = value

// volumebound() -- to check or set element's maximum volume bound.

#define volumebound(ptr) (((REAL *) (ptr))[volumeboundindex])

#define setvolumebound(ptr, value) \
  ((REAL *) (ptr))[volumeboundindex] = value

// infect(), infected(), uninfect() -- primitives to flag or unflag a
//   tetrahedron. The last bit of the element marker is flagged (1)
//   or unflagged (0).

#define infect(t) elemmarker((t).tet) |= 1

#define uninfect(t) elemmarker((t).tet) &= ~1

#define infected(t) ((elemmarker((t).tet) & 1) != 0)

// marktest(), marktested(), unmarktest() -- primitives to flag or unflag a
//   tetrahedron.  The last second bit of the element marker is marked (1)
//   or unmarked (0).
// One needs them in forming Bowyer-Watson cavity, to mark a tetrahedron if
//   it has been checked (for Delaunay case) so later check can be avoided.

#define marktest(t) elemmarker((t).tet) |= 2

#define unmarktest(t) elemmarker((t).tet) &= ~2
    
#define marktested(t) ((elemmarker((t).tet) & 2) != 0)

// markface(), unmarkface(), facemarked() -- primitives to flag or unflag a
//   face of a tetrahedron.  From the last 3rd to 6th bits are used for
//   face markers, e.g., the last third bit corresponds to loc = 0. 
// One use of the face marker is in flip algorithm. Each queued face (check
//   for locally Delaunay) is marked.

#define markface(t) elemmarker((t).tet) |= (4<<(t).loc)

#define unmarkface(t) elemmarker((t).tet) &= ~(4<<(t).loc)

#define facemarked(t) ((elemmarker((t).tet) & (4<<(t).loc)) != 0)

// markedge(), unmarkedge(), edgemarked() -- primitives to flag or unflag an
//   edge of a tetrahedron.  From the last 7th to 12th bits are used for
//   edge markers, e.g., the last 7th bit corresponds to the 0th edge, etc. 
// Remark: The last 7th bit is marked by 2^6 = 64.

#define markedge(t) elemmarker((t).tet) |= (64<<locver2edge[(t).loc][(t).ver])

#define unmarkedge(t) \
  elemmarker((t).tet) &= ~(64<<locver2edge[(t).loc][(t).ver])

#define edgemarked(t) \
  ((elemmarker((t).tet) & (64<<locver2edge[(t).loc][(t).ver])) != 0)

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Primitives for shellfaces                                                 //
//                                                                           //
// Each shellface contains three pointers to its adjacent shellfaces, with   //
// their edge versions (shver in [0, 5]).  To save memory, all informations  //
// of an adjacent shellface are compressed in a single pointer. To make this //
// possible, all shellface are aligned to 8-byte boundaries.                 //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

// sencode(), sdecode -- to compress/uncompress a face/pointer. 
//   The pointer 's.sh' is assumed to be 8-byte aligned.

#define sencode(s) \
  (shellface) ((unsigned long) (s).sh | (unsigned long) (s).shver)

#define sdecode(sptr, s) \
  (s).shver = (int) ((unsigned long) (sptr) & (unsigned long) 7l);\
  (s).sh = (shellface *) ((unsigned long) (sptr) & ~ (unsigned long) 7l)

// sorg(), sdest(), sapex() -- return the origin, destination, apex,
//   of the subface.
    
#define sorg(s) (point) (s).sh[vo[(s).shver] + 3]

#define sdest(s) (point) (s).sh[vd[(s).shver] + 3]

#define sapex(s) (point) (s).sh[va[(s).shver] + 3]

#define setsdest(s, p) (s).sh[vd[(s).shver] + 3] = (shellface) (p)

#define setsapex(s, p) (s).sh[va[(s).shver] + 3] = (shellface) (p)

#define setshvertices(s, p1, p2, p3) \
  (s).sh[vo[(s).shver] + 3] = (shellface) (p1); \
  (s).sh[vd[(s).shver] + 3] = (shellface) (p2); \
  (s).sh[va[(s).shver] + 3] = (shellface) (p3)

// sesym() - change the origin and destination of the face edge.

#define sesym(s1, s2) \
  (s2).sh = (s1).sh;\
  (s2).shver = (s1).shver + (((s1).shver & 01) ? -1 : 1);

#define sesymself(s) \
  (s).shver += (((s).shver & 01) ? -1 : 1);

// senext(), senext2() -- go to the next (or the previous) face edge.

#define senext(s1, s2) \
  (s2).sh = (s1).sh;\
  (s2).shver = ve[(s1).shver]
  
#define senextself(s) \
  (s).shver = ve[(s).shver]

#define senext2(s1, s2) \
  (s2).sh = (s1).sh;\
  (s2).shver = ve2[(s1).shver]
  
#define senext2self(s) \
  (s).shver = ve2[(s).shver]

// The general rule to connect two subfaces s1 and s2 is:  Let s1's edge
//   be a->b, which is in s1's 0th edge ring, then the edge b->a of s2 is
//   bonded to s1.  The same rule for connecting a subface and a subseg.

// sbond1() -- s1 and s2 share an edge, connect s1 <-- s2, i.e., s1 knows
//   its neighbor is s2. sbond2() connects s1 <==> s2.

#define sbond1(s1, s2) (s1).sh[(s1).shver >> 1] = sencode(s2);

#define sbond2(s1, s2) \
  (s1).sh[(s1).shver >> 1] = sencode(s2);\
  (s2).sh[(s2).shver >> 1] = sencode(s1)

// sdisolve() -- dissolve a subface-subface connection (at one side).

#define sdissolve(s) (s).sh[(s).shver >> 1] = NULL;

// ssbond() -- connect a subface (s) and a subsegment (seg) together.
// NOTE: we allow that 'seg.sh' should not be NULL.

#define ssbond(s, seg) \
  (s).sh[((s).shver >> 1) + 6] = sencode(seg);\
  if ((seg).sh != NULL) (seg).sh[0] = sencode(s)

// ssdisolve() -- dissolve a subface-subsegment connection (at subface side).

#define ssdissolve(s) (s).sh[((s).shver >> 1) + 6] = NULL;

// spivot() -- find the next face in the face ring.

#define spivot(s1, s2) sdecode((s1).sh[(s1).shver >> 1], s2)

#define spivotself(s) \
  sptr = (s).sh[(s).shver >> 1];\
  sdecode(sptr, s)

// sspivot() -- find the abutting subsegment (seg) at the face (s).

#define sspivot(s, seg) sdecode((s).sh[((s).shver >> 1) + 6], seg)

// shellmark() -- set or read the shell mark.

// #define shellmark(s) ((int *) ((s).sh))[shmarkindex]

// The last two bits of the int ((int *) ((s).sh))[shmarkindex] are used
//   by sinfect() and smarktest().

int getshellmark(face& s) {
  return (((int *) ((s).sh))[shmarkindex]) >> 2;
}

void setshellmark(face& s, int mark) {
  ((int *) ((s).sh))[shmarkindex] = (mark << 2) + 
    ((((int *) ((s).sh))[shmarkindex]) & 3);
}

// areabound() -- set of read the maximal area bound.

#define areabound(s) ((REAL *) ((s).sh))[areaboundindex]

// sinfect(), sinfected(), suninfect() -- primitives to flag or unflag a
//   subface. The last bit of ((int *) ((s).sh))[shmarkindex] is flaged.

#define sinfect(s) \
  ((int *) ((s).sh))[shmarkindex] = (((int *) ((s).sh))[shmarkindex] | 1)

#define suninfect(s) \
  ((int *) ((s).sh))[shmarkindex] = (((int *) ((s).sh))[shmarkindex] & ~1)

#define sinfected(s) ((((int *) ((s).sh))[shmarkindex] & 1) != 0)

// smarktest(), smarktested(), sunmarktest() -- primitives to flag or unflag
//   a subface. The last 2nd bit of ((int *) ((s).sh))[shmarkindex] is flaged.

#define smarktest(s) \
  ((int *) ((s).sh))[shmarkindex] = (((int *) ((s).sh))[shmarkindex] | 2)

#define sunmarktest(s) \
  ((int *) ((s).sh))[shmarkindex] = (((int *) ((s).sh))[shmarkindex] & ~2)

#define smarktested(s) ((((int *) ((s).sh))[shmarkindex] & 2) != 0)

// farsorg(), farsdest() -- s is a subsegment, return the origin or
//   destination of the segment containing s.
// Note: here we assume that two subsegment (a->p) and (p->b) bonded
//   at p as: (p->nil->a) and (nil->p->b), in flipn2nf().

point farsorg(face& s) {
  face travesh, neighsh;
  shellface sptr;
  travesh = s;
  while (1) {
    senext2(travesh, neighsh);
    spivotself(neighsh); 
    if (neighsh.sh == NULL) break;
    if (sorg(neighsh) != sorg(travesh)) sesymself(neighsh);
    assert(sorg(neighsh) == sorg(travesh)); // SELF_CHECK
    senext2(neighsh, travesh); 
  }
  return sorg(travesh);
}

point farsdest(face& s) {
  face travesh, neighsh;
  shellface sptr;
  travesh = s;
  while (1) {
    senext(travesh, neighsh);
    spivotself(neighsh); 
    if (neighsh.sh == NULL) break;
    if (sdest(neighsh) != sdest(travesh)) sesymself(neighsh);
    assert(sdest(neighsh) == sdest(travesh)); // SELF_CHECK
    senext(neighsh, travesh); 
  }
  return sdest(travesh);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Interactions between tetrahedra and subfaces and subsegments.             //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

// tspivot(), stpivot -- given a tet's face t (or a subface s), find the
//   abutting subface (or tet).

void tspivot(triface& t, face& s) {
  if ((t).tet[9] != NULL) {
    sdecode(((shellface *) (t).tet[9])[(t).loc], s);
  } else {
    (s).sh = NULL;
  }
}

#define stpivot(s, t) decode((tetrahedron) (s).sh[9], t)

// tsbond() -- connect a tet and subface.

void tsbond(triface& t, face& s) {
  if ((t).tet[9] == NULL) {
    // Allocate space for this tet.
    (t).tet[9] = (tetrahedron) tet2subpool->alloc();
    // NULL all fields in this space.
    for (int i = 0; i < 4; i++) {
      ((shellface *) (t).tet[9])[i] = NULL;
    }
  }
  // Bond t <==> s.
  ((shellface *) (t).tet[9])[(t).loc] = sencode(s);
  (s).sh[9] = (shellface) encode(t);
}

// tsdissolve() -- dissolve a tet-subface bond at the tet side.

void tsdissolve(triface& t) {
  if ((t).tet[9] != NULL) {
    ((shellface *) (t).tet[9])[(t).loc] = NULL;
  }
}

// stdissolve() -- dissolbe a tet-subface bond at the subface side.

#define stdissolve(s) (s).sh[9] = NULL;

// tsspivot() -- given a tet's edge t, return a subsegment s at this edge.
//   t and s is bonded through tssbond1(). if s.sh == NULL, the edge is
//   not a subsegment.

void tsspivot(triface& t, face& s) {
  if ((t).tet[8] != NULL) {
    sdecode(((shellface *) (t).tet[8])[locver2edge[(t).loc][(t).ver]], s);
  } else {
    (s).sh = NULL;
  }
}

// tssbond1() -- bond a tet edge and a segment (only at tet's edge).

void tssbond1(triface& t, face& s) {
  if ((t).tet[8] == NULL) {
    // Allocate space for this tet.
    (t).tet[8] = (tetrahedron) tet2segpool->alloc();
    // NULL all fields in this space.
    for (int i = 0; i < 6; i++) {
      ((shellface *) (t).tet[8])[i] = NULL;
    }
  }
  // Bond the segment.
  ((shellface *) (t).tet[8])[locver2edge[(t).loc][(t).ver]] = sencode((s));
} 

// tssdissolve() -- dissolve a tet-seg bond at the tet edge.

void tssdissolve(triface& t) {
  if ((t).tet[8] != NULL) {
    ((shellface *) (t).tet[8])[locver2edge[(t).loc][(t).ver]] = NULL;
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Primitives for points                                                     //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#define pointmark(pt) ((int *) (pt))[pointmarkindex]
    
#define point2tet(pt) ((tetrahedron *) (pt))[point2tetindex]

// Given a point 'pa', return a tet 'searchtet' whose origin is pa.

void point2tetorg(point pa, triface& searchtet)
{
  int i;

  // Search a tet whose origin is pa.
  decode(point2tet(pa), searchtet);
  assert(searchtet.tet != NULL); // SELF_CHECK
  for (i = 4; i < 8; i++) {
    if ((point) searchtet.tet[i] == pa) {
      // Found. Set pa as its origin.
      switch (i) {
        case 4: searchtet.loc = 0; searchtet.ver = 0; break;
        case 5: searchtet.loc = 0; searchtet.ver = 2; break;
        case 6: searchtet.loc = 0; searchtet.ver = 4; break;
        case 7: searchtet.loc = 1; searchtet.ver = 2; break;
      }
      break;
    }
  }
  assert(i < 8); // SELF_CHECK
}
    
#define point2ppt(pt) ((point *) (pt))[point2tetindex + 1]

// #define pointtype(pt) ((enum verttype *) (pt))[pointmarkindex + 1]

enum verttype getpointtype(point pt) {
  return (enum verttype) (((int *) (pt))[pointmarkindex + 1] >> 1);
}

void setpointtype(point pt, enum verttype type) {
  ((int *) (pt))[pointmarkindex + 1] = 
    ((int) type << 1) + (((int *) (pt))[pointmarkindex + 1] & 1);
}

// pinfect(), puninfect(), pinfected() -- primitives to flag or unflag
//   a point. The last bit of the integer '[pointindex+1]' is flaged.

#define pinfect(pt) \
  ((int *) (pt))[pointmarkindex + 1] = ((int *) (pt))[pointmarkindex + 1] | 1

#define puninfect(pt) \
  ((int *) (pt))[pointmarkindex + 1] = ((int *) (pt))[pointmarkindex + 1] & ~1

#define pinfected(pt) ((((int *) (pt))[pointmarkindex + 1] & 1) != 0)

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Primitives for arraypools.                                                //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

// fastlookup() -- A fast, unsafe operation. Return the pointer to the object
//   with a given index.  Note: The object's block must have been allocated,
//   i.e., by the function newindex().

#define fastlookup(pool, index) \
  (void *) ((pool)->toparray[(index) >> (pool)->log2objectsperblock] + \
            ((index) & ((pool)->objectsperblock - 1)) * (pool)->objectbytes)

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Class Variables.                                                          //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

// Pointer to the input data (a PLC or a mesh).
tetgenio *in;

// Pointer to the options (and filenames).
tetgenbehavior *b;

// Pools of tetrahedra, shellfaces, points, etc.
memorypool *tetrahedronpool;
memorypool *subsegpool, *subfacepool;
memorypool *tet2segpool, *tet2subpool;
memorypool *pointpool;
memorypool *flippool;

// A dummy point at infinity (see [Guibas & Stolfi 85]).  All the hull
//   tetrahedra having this point as a vertex.
point dummypoint;

// Statck and queue (use flippool) for flips.
badface *futureflip;

// Arrays used by Bowyer-Watson algorithm.
arraypool *cavetetlist, *cavebdrylist, *caveoldtetlist;
arraypool *caveshlist, *caveshbdlist;

// Stacks used by the boundary recovery algorithm.
arraypool *subsegstack, *subfacstack;

// Variables for accessing data fields (initialized in initializepools()).
int point2tetindex, pointmarkindex;
int elemmarkerindex;
int elemattribindex, volumeboundindex, highorderindex;
int shmarkindex, areaboundindex;

// The number of hull tetrahedra (= the number of outer boundary faces).
long hullsize;

// Current random number seed, number of random samples (for point location).
unsigned long randomseed, samples;

// Pointers to a recently visited tetrahedron and subface.
triface recenttet;
face recentsh;

// Two handles used in facet recovery (formcavity and fillcavity).
triface firsttopface, firstbotface;

// The size of bounding boxes.
REAL xmax, xmin, ymax, ymin, zmax, zmin;

// The number of duplicated vertices, mesh edges, and input segments.
long dupverts, meshedges, meshsubedges, insegments;

// Flags to check imposed constraints, subfaces, subsegs.
int checkconstraints, checksubfaces, checksubsegs, checkpbcs;

// Algorithm statistical counters.
long ptloc_count, ptloc_max_count;
long orient3dcount;
long inspherecount, insphere_sos_count;
long maxbowatcavsize, totalbowatcavsize, totaldeadtets;
long flip14count, flip26count, flipn2ncount;
long flip23count, flip32count, flipnmcount;
long flip13count, flip22count, flipn2nfcount;
REAL tloctime, tfliptime, tinserttime;
long triedgcount, triedgcopcount, trivercopcount;
long across_face_count, across_edge_count, across_max_count;
long r1count, r2count, r3count;
long maxcavsize, maxregionsize;
long ndelaunayedgecount, cavityexpcount;

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Functions for using memorypools.                                          //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void initializepools();
void tetrahedrondealloc(tetrahedron*);
tetrahedron *tetrahedrontraverse();
tetrahedron *alltetrahedrontraverse();
void shellfacedealloc(memorypool*, shellface*);
shellface *shellfacetraverse(memorypool*);
void badfacedealloc(memorypool*, badface*);
badface *badfacetraverse(memorypool*);
void pointdealloc(point);
point pointtraverse();
void maketetrahedron(triface*);
void makeshellface(memorypool*, face*);
void makepoint(point*);
void makeindex2pointmap(point*&);
void makepoint2submap(memorypool*, int*&, face*&);
void makepoint2tetmap();

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Linear algebra operators.                                                 //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#define NORM2(x, y, z) ((x) * (x) + (y) * (y) + (z) * (z))

#define DIST(p1, p2) \
  sqrt(NORM2((p2)[0] - (p1)[0], (p2)[1] - (p1)[1], (p2)[2] - (p1)[2]))

#define DOT(v1, v2) \
  ((v1)[0] * (v2)[0] + (v1)[1] * (v2)[1] + (v1)[2] * (v2)[2])

#define CROSS(v1, v2, n) \
  (n)[0] =   (v1)[1] * (v2)[2] - (v2)[1] * (v1)[2];\
  (n)[1] = -((v1)[0] * (v2)[2] - (v2)[0] * (v1)[2]);\
  (n)[2] =   (v1)[0] * (v2)[1] - (v2)[0] * (v1)[1]

#define SETVECTOR3(V, a0, a1, a2) (V)[0] = (a0); (V)[1] = (a1); (V)[2] = (a2)

#define SWAP2(a0, a1, tmp) (tmp) = (a0); (a0) = (a1); (a1) = (tmp)

bool lu_decmp(REAL lu[4][4], int n, int* ps, REAL* d, int N);
void lu_solve(REAL lu[4][4], int n, int* ps, REAL* b, int N);

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Geometric predicates, advanced tests, intersections.                      //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

static REAL PI;

REAL interiorangle(point o, point p1, point p2, REAL* n);
void facenormal(point, point, point, REAL *n, int pivot);
void circumsphere(point, point, point, point, REAL* cent, REAL* radius);

REAL insphere_sos(point pa, point pb, point pc, point pd, point pe);
REAL incircle3d(point pa, point pb, point pc, point pd);
bool iscoplanar(point k, point l, point m, point n, REAL ori);

int tri_edge_2d(point,point,point,point,point,point,int,int*,int*);
int tri_edge_test(point,point,point,point,point,point,int,int*,int*);
int tri_tri_2d(point,point,point,point,point,point,point,int,int*,int*);
int tri_tri_test(point,point,point,point,point,point,point,int,int*,int*);

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Mesh transformation operations.                                           //
//                                                                           //
// Mesh transformation operations translate an old set of tetrahedra into a  //
// new set of tetrahedra in the same region of the tetrahedralization. Such  //
// operations include face/edge flips, vertex insertion/deletions.           //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

badface* flipshpush(badface* flipstack, face* flipedge);
void flip13(point newpt, face* splitface, int flipflag);
void flipn2nf(point newpt, face* splitedges, int flipflag);
void flip22(face* flipfaces, int flipflag);
void lawsonflip();

badface* flippush(badface* flipstack, triface* flipface, point pushpt);
void flip14(point newpt, triface* splittet, int flipflag);
void flip26(point newpt, triface* splitface, int flipflag);
void flipn2n(point newpt, triface* splitedge, int flipflag);
void flip23(triface* fliptets, int hullflag, int flipflag);
void flip32(triface* fliptets, int hullflag, int flipflag);
//bool flipnm(int n, triface* fliptets, int flipflag);
void lawsonflip3d(int flipflag);

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Jump-and-Walk point location algorithm.                                   //
//                                                                           //
// The following functions implemented the randomized jump-and-walk point    //
// location algorithm of Muecke, Saias, and Zhu [MueckeSaiasZhu96].          //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

unsigned long randomnation(unsigned long choices);
void randomsample(point searchpt, triface* searchtet);
enum location locate(point searchpt, triface* searchtet);

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Incremental Delaunay tetrahedralization algorithms.                       //
//                                                                           //
// Bowyer and Watson's incrmental insertion algorithm [Bowyer81, Watson81],  //
// and Edelsbrunner and Shah's incrmental flip algorithm [Edelsbrunner96].   //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void initialDT(point pa, point pb, point pc, point pd);
enum location insertvertex(point, triface*, bool, bool, bool, bool);
void flipinsertvertex(point, triface*, int);
void incrementaldelaunay();

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Surface mesh routines.                                                    //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

bool calculateabovepoint(arraypool*, point*, point*, point*);
enum location slocate(point, face*, bool);
enum location sinsertvertex(point, face*, face*, bool, bool);
enum intersection sscoutsegment(face* searchsh, point endpt);
void scarveholes(int, REAL*);
void triangulate(int, arraypool*, arraypool*, int, REAL*);

void unifysubfaces(face*, face*);
void unifysegments();
void mergefacets();
void markacutevertices();
void meshsurface();

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Boundary recovery functions.                                              //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

enum intersection finddirection(triface* searchtet, point endpt);
enum intersection scoutsegment(face* sseg, triface* searchtet, point* refpt);
void getsegmentsplitpoint(face* sseg, point refpt, REAL* vt);
void delaunizesegments();

enum intersection scoutsubface(face* ssub, triface* searchtet);
enum intersection scoutcrosstet(face* ssub, triface* searchtet, arraypool*);
void recoversubfacebyflips(face* pssub, triface* crossface, arraypool*);
void formcavity(face*, arraypool*, arraypool*, arraypool*, arraypool*, 
                arraypool*, arraypool*);
bool delaunizecavity(arraypool*, arraypool*, arraypool*, arraypool*,
                     arraypool*, arraypool*);
bool fillcavity(arraypool*, arraypool*, arraypool*, arraypool*);
void carvecavity(arraypool*, arraypool*, arraypool*);
void restorecavity(arraypool*, arraypool*, arraypool*);
void splitsubedge(point, face*, arraypool*, arraypool*);
void constrainedfacets();

enum intersection scoutedge(point, point, triface*, arraypool*, arraypool*,
                            arraypool*);

void formskeleton();
void carveholes();

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Mesh input & output functions.                                            //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void transfernodes();
void reconstructmesh();
void jettisonnodes();
void highorder();
void numberedges();
void numbersubedges();
void outnodes(tetgenio* out);
void outelements(tetgenio* out);
void outfaces(tetgenio* out);
void outhullfaces(tetgenio* out);
void outsubfaces(tetgenio* out);
void outedges(tetgenio* out);
void outsubsegments(tetgenio* out);
void outneighbors(tetgenio* out);
void outvoronoi(tetgenio* out);

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Mesh statistic functions.                                                 //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void checkmesh();
int checkshells(int);
int checkdelaunay(int);
int checksegments();
void checkconforming();
void algorithmstatistics();
void qualitystatistics();
void statistics();

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Class Constructor and Destructor.                                         //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void initialize()
{
  in = (tetgenio *) NULL;
  b = (tetgenbehavior *) NULL;
  tetrahedronpool = (memorypool *) NULL;
  subfacepool = subsegpool = (memorypool *) NULL;
  tet2segpool = tet2subpool = (memorypool *) NULL;
  pointpool = (memorypool *) NULL;
  flippool = (memorypool *) NULL;
  dummypoint = (point) NULL;
  futureflip = (badface *) NULL;
  cavetetlist = cavebdrylist = caveoldtetlist = (arraypool *) NULL;
  caveshlist = caveshbdlist = (arraypool *) NULL;
  subsegstack = subfacstack = (arraypool *) NULL;
  point2tetindex = pointmarkindex = 0;
  elemmarkerindex = 0;
  elemattribindex = volumeboundindex = highorderindex = 0;
  hullsize = 0l;
  randomseed = samples = 1l;
  recenttet.tet = (tetrahedron *) NULL;
  recenttet.loc = recenttet.ver = 0;
  xmax = xmin = ymax = ymin = zmax = zmin = 0.0;
  dupverts = meshedges = meshsubedges = insegments = 0l;
  checkconstraints = checksubfaces = checksubsegs = checkpbcs = 0;
  ptloc_count = ptloc_max_count = 0l;
  orient3dcount = 0l;
  inspherecount = insphere_sos_count = 0l;
  maxbowatcavsize = totalbowatcavsize = totaldeadtets = 0l;
  flip14count = flip26count = flipn2ncount = 0l;
  flip23count = flip32count = flipnmcount = 0l;
  flip13count = flip22count = flipn2nfcount = 0l;
  tloctime = tfliptime = tinserttime = 0.0;
  triedgcount = triedgcopcount = trivercopcount = 0l;
  across_face_count = across_edge_count = across_max_count = 0l;
  r1count = r2count = r3count = 0l;
  maxcavsize = maxregionsize = 0l;
  ndelaunayedgecount = cavityexpcount = 0l;
}

void deinitialize()
{
  in = (tetgenio *) NULL;
  b = (tetgenbehavior *) NULL;
  if (pointpool != (memorypool *) NULL) {
    delete pointpool;
    delete [] dummypoint;
  }
  if (tetrahedronpool != (memorypool *) NULL) {
    delete tetrahedronpool;
    delete cavetetlist;
    delete cavebdrylist;
    delete caveoldtetlist;
    delete flippool;
  }
  if (subfacepool != (memorypool *) NULL) {
    delete subfacepool;
    delete subsegpool;
    delete tet2segpool;
    delete tet2subpool;
    delete subsegstack;
    delete subfacstack;
    delete caveshlist;
    delete caveshbdlist;
  }
  futureflip = (badface *) NULL;
}

tetgenmesh() 
{
  initialize();
}

~tetgenmesh() 
{
  deinitialize();
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Debug functions.                                                          //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void ptet(triface* t);
void psh(face* s);
void pteti(int i, int j, int k, int l);
void pface(int i, int j, int k);
bool pedge(int i, int j);
void psubface(int i, int j, int k);
void psubseg(int i, int j);
int pmark(point p);
void pvert(point p);
int pverti(int i);
REAL test_orient3d(int i, int j, int k, int l);
REAL test_insphere(int i, int j, int k, int l, int m);
int test_tritri(int a, int b, int c, int p,  int q, int r);
void print_cavebdrylist();
void print_flipstack();
void print_tetarray(arraypool* tetarray, bool nohulltet);
void print_facearray(arraypool* facearray);
void print_subfacearray(arraypool* subfacearray);
void dump_cavity(arraypool *topfaces, arraypool *botfaces);
void dump_facetof(face* pssub, char* filename);

///////////////////////////////////////////////////////////////////////////////
};  // End of class tetgenmesh;
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// terminatetetgen()    Terminate TetGen with a given exit code.             //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void terminatetetgen(int x);

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// tetrahedralize()    Interface for using TetGen's library to generate      //
//                     Delaunay tetrahedralizations, constrained Delaunay    //
//                     tetrahedralizations, quality tetrahedral meshes.      //
//                                                                           //
// 'in' is an object of 'tetgenio' which contains a PLC you want to tetrahed-//
// ralize or a previously generated tetrahedral mesh you want to refine.  It //
// must not be a NULL. 'out' is another object of 'tetgenio' for storing the //
// generated tetrahedral mesh. It can be a NULL. If so, the output will be   //
// saved to file(s). If 'bgmin' != NULL, it contains a background mesh which //
// defines a mesh size distruction function.                                 //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetrahedralize(tetgenbehavior *b, tetgenio *in, tetgenio *out, 
                    tetgenio *addin = NULL, tetgenio *bgmin = NULL);

void tetrahedralize(char *switches, tetgenio *in, tetgenio *out,
                    tetgenio *addin = NULL, tetgenio *bgmin = NULL);

#endif // #ifndef tetgenH
