///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// tetlib.h    Head file for the mesh data structures and mesh3d class       //
//             declaration.                                                  //
//                                                                           //
// Tetgen Version 1.0 beta                                                   //
// Oct. 2001                                                                 //
//                                                                           //
// Si hang                                                                   //
// Email: sihang@weboo.com                                                   //
// http://www.weboo.com/sh/tetgen.htm                                        //
//                                                                           //
// You are free to use, copy and modify the sources under certain            //
// circumstances, provided this copyright notice remains intact.             //
// See the file LICENSE for details.                                         //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//   Tetgen is based on the Delaunay method and incorporates face-swapping   //
// techniques. It generates meshes composed of tetrahedral elements. Tetgen  //
// generates exact Delaunay tetrahedralization for three-dimensional point   //
// sets, generates boundary constrained Delaunay tetrahedralization and      //
// quality (conforming) Delaunay tetrahedralizations for three-dimensional   //
// Piecewise Linear Complex(PLC).                                            //
//                                                                           //
//   The Tetgen mesh generator is based on:                                  //
//                                                                           //
// [*] Integrating two relative mesh data structures: The tetrahedron-based  //
//     mesh data structure and triangle-edge mesh data structure.            //
//                                                                           //
// [*] Using the randomized incremental flip algorithm to construct Delaunay //
//     tetrahedralization for 3D point sets.                                 //
//                                                                           //
// [*] Using simple face/edge swapping method and local re-meshing method to //
//     construct boundary-constrained Delaunay tetrahedralization.           //
//                                                                           //
// [*] Using the Delaunay refinement algorithm and the radius-edge ratio     //
//     quality measure to incrementally insert (steiner) points into the     //
//     mesh to eliminate bad quality tetrahedra and generate an almost good  //
//     mesh with good grading.                                               //
//                                                                           //
// [*] Other algorithms involve fast randomized point location algorithm to  //
//     perform fast point location and using gift-wrapping algorithm to      //
//     construct a constrained Delaunay triangulation for triangular faces   //
//     bounded polyhedras.                                                   //
//                                                                           //
// [*] Embedding the 2D mesh generator Triangle to generate planar surface   //
//     mesh, Optionally using the adaptive exact arithmetic package to       //
//     improve the robustness of the implementation.                         //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#ifndef tetlibH
#define tetlibH

#include "defines.h"
#include "linklist.h"
#include "trilib.h"

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Mesh data structures                                                      //
//                                                                           //
//   The efficiency of a tetrahedral mesh generator is rests on its          //
// algorithms and data structures. It was important to begin with a robust   //
// data structure that was flexible and encompassing enough to serve as the  //
// basis for a wide variety of applications. In Tetgen, the data structure   //
// was so designed make it suitable for both Delaunay and Advancing-Front    //
// methods.                                                                  //
//                                                                           //
//   Tetgen integrates two relative mesh data structures: The tetrahedron-   //
// based data structure of Shewchuk[1] and the triangle-edge data structure  //
// of Mucke[2]. Where the tetrahedron-based data structure is convenient for //
// storing tetrahedral mesh and is deeply discussed in [1]. The triangle-    //
// edge data structure is convenient for face classification and mesh        //
// manipulation, it was mainly described in [2].                             //
//                                                                           //
//   Please refer to Dobkin and Laszlo[3], Guibas and Stolfi[4], and Owen[5] //
// for more general discussions about mesh data structures.                  //
//                                                                           //
// Refernces:                                                                //
//                                                                           //
// [1] Jonathan Richard Shewchuk, Delaunay Refinement Mesh Generation. Ph.D. //
//     thesis, School of Computer Science, Carnegie Mellon University, Pitt- //
//     sburgh, Pennsylvania. May 1997. Available as Technical Rreport CMU-CS //
//     -97-137.                                                              //
// [2] Ernst P. Mucke, Shapes and Implementations in Three-Dimensional Geom- //
//     etry. Ph.D. thesis, Technical Report UIUCDCS-R-93-1836. Department of //
//     Computer Science, University of Illinois at Urbana-Champaign, Urbana, //
//     Illinois, 1993.                                                       //
// [3] David P. Dobkin and Michael J. Laszlo. Primitives for the Manipulati- //
//     on of Three-Dimensional Subdivisions. Algorithmica 4:3-32, 1989.      //
// [4] Leonidas J. Guibas and Jorge Stolfi, Primitives for the Manipulation  //
//     of General Subdivisions and the Computation of Voronoi Diagrams, ACM  //
//     Transactions on Graphics 4(2):74-123, April 1985.                     //
// [5] Steven J. Owen, Non-Simplicial Unstructured Mesh Generation, Ph.D.    //
//     Dissertation, Carnegie Mellon University, 1999.                       //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Basic data structure: tetrahedron                                         //
//                                                                           //
//   Each tetrahedron contain four pointers to its vertices, and four        //
// pointers to the adjoining tetrahedra. Plus four pointers to subfaces      //
// (define below, these pointers are usually 'dummysh'). It may or may not   //
// also contain user-defined attributes and/or a floating-point volume       //
// constraint.                                                               //
//   Because the size and structure of a 'tetrahedron' is not decided until  //
// runtime,  It is not simply defined to be a structure or a class.          //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

typedef REAL **tetrahedron;

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Basic data structure: shellface                                           //
//                                                                           //
//   The shell (triangular) face data structure. Both subface and subsegment //
// are represented by shellface(see[1]).                                     //
//   Each subface contains three pointers to its vertices, three pointers to //
// adjoining subfaces, and two pointers to adjoining tetrahedron,  plus one  //
// boundary marker.  Three pointer to adjoining subfaces are only used for   //
// coplanar neighbours in a common facet, or used for applications of gener- //
// ating surface meshes. Each subface also has three pointers to adjoining   //
// subsegments. To save space, there are no pointers directly connecting     //
// tetrahedra and adjoining subsegments;  connections between tetrahedra and //
// subsegments are entirely mediated through subfaces.                       //
//   Because a subsegment may be shared by any number of subfaces and        //
// tetrahedra, each subsegment has a pointer to only one adjoining subface //
// (chosen arbitrarily);  the others must be found through the connectivity  //
// of the mesh.                                                              //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

typedef REAL **shellface;

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Basic data structure: point3d                                             //
//                                                                           //
//   The point data structure.  Each point is actually an array of REALs.    //
// The number of REALs is unknown until runtime. An integer boundary marker, //
// and sometimes a pointer to a tetrahedron, is appended after the REALs.    //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

typedef REAL *point3d;

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Handle                                                                    //
//                                                                           //
//   The oriented triangular face 'triface' and oriented shell face 'face'   //
// data structures defined below do not themselves store any part of the     //
// mesh. The mesh itself is made of 'tetrahedron's, 'shellface's, and        //
// 'point3d's.                                                               //
//                                                                           //
//   Oriented triangular faces and oriented shell faces will usually be      //
// referred to as "handles".  A handle is essentially a pointer into the     //
// mesh; it allows you to "hold" one particular part of the mesh.  Handles   //
// are used to specify the regions in which one is traversing and modifying  //
// the mesh.                                                                 //
//                                                                           //
//    A 'triface' is a handle that holds a tetrahedron. It holds a specific  //
// side of the tetrahedron. An 'face' is a handle that holds a shell face.   //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// The handle data structure: triface                                        //
//                                                                           //
//   triface is an oriented triangluar face of tetrahedron in 3D. The        //
// orientation is determined by face vertices. A triface includes a pointer  //
// to a tetrahedron, a face location and a face version. where face location //
// is an integer number varies from 0 to 3. It was used to indicate a face   //
// of tetrahedron. Face version is an integer number varies from 0 to 5. It  //
// was used to represent an oriented edge of face.                           //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

class triface {

  public:

    tetrahedron* tet;
    int loc;                                           // Range from 0 to 3.
    int ver;                                           // Range from 0 to 5.

    // Constructors;
    triface() : tet(0), loc(0), ver(0) {}
    triface(const triface& tface) {
      tet = tface.tet; loc = tface.loc; ver = tface.ver;
    }

    // Operators;
    triface& operator=(const triface& tface) {
      tet = tface.tet; loc = tface.loc; ver = tface.ver;
      return *this;
    }
    bool operator==(triface& tface) {
      return (tet == tface.tet) && (loc == tface.loc) && (ver == tface.ver);
    }
    bool operator!=(triface& tface) {
      return (tet != tface.tet) || (loc != tface.loc) || (ver != tface.ver);
    }
};

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// The handle data structure: face                                           //
//                                                                           //
//   face is an oriented subface in 3D. The orientation is determined by its //
// vertices. A face includes a pointer to a shell face, and a face version.  //
// where face version is an integer number varies from 0 to 5. It was used   //
// to represent an oriented edge of face.                                    //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

class face {

  public:

    shellface *sh;
    int shver;                                        // Ranges from 0 to 5.

    // Constructors;
    face() : sh(0), shver(0) {}
    face(const face& sface) {
      sh = sface.sh; shver = sface.shver;
    }

    // Operators;
    face& operator=(const face& sface) {
      sh = sface.sh; shver = sface.shver;
      return *this;
    }
    bool operator==(face& sface) {
      return (sh == sface.sh) && (shver == sface.shver);
    }
    bool operator!=(face& sface) {
      return (sh != sface.sh) || (shver != sface.shver);
    }
};

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Mesh data type linar-order functions used in list and link data types.    //
// See linklist.h for detail description about linar-order functions.        //
//                                                                           //
// compare2points()    Compare two point3ds by their x-coordinate, using the //
//                     y-coordinate as a secondary key, and the z-coordinate //
//                     if their need.                                        //
// compare2tets()      Compare two handles of tetrahedra by thire address.   //
// compare2shfaces()   Compare two handles of subfaces/subsegments by thire  //
//                     address.                                              //
//                                                                           //
// Return 0 if they are the same. Return 1 or -1 if they are not the same.   //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

int compare2points(point3d*, point3d*);
int compare2tets(triface*, triface*);
int compare2shfaces(face*, face*);

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// struct badface3d                                                          //
//                                                                           //
//   A queue used to store bad triangular faces.  Each face's vertices are   //
// stored so that one can check whether a face is still the same.            //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

typedef struct badface3dtype {
  triface badfacetet;                    // A tetrahedron hold the bad face.
  face shface;                                                // A bad face.
  REAL cent[3];                           // The circumcenters' coordinates.
  point3d faceorg, facedest, faceapex;                // The three vertices.
  struct badface3dtype *nextface;               // Pointer to next bad face.
} badface3d;

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// struct badtet                                                             //
//                                                                           //
//   A queue used to store bad tetrahedra. Each tetrahedron's vertices are   //
// stored so that one can check whether a tetrahedron is still the same.     //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

typedef struct badtettype {
  triface btet;                                                // A bad tet.
  REAL key;                                          // radius-edge ratio^2.
  REAL cent[3];                           // The circumcenters' coordinates.
  point3d tetorg, tetdest, tetapex, tetoppo;           // The four vertices.
  struct badtettype *nexttet;                    // Pointer to next bad tet.
} badtet;

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// class mesh3d    The quality Tetrahedral mesh Generator and Delaunay       //
//                 triangulator implementation class.                        //
//                                                                           //
//   Tetgen is based on the Delaunay method and incorporates face-swapping   //
// techniques. It generates meshed composed of tetrahedral elements. Tetgen  //
// generates exact Delaunay tetrahedralization for three-dimensional point   //
// sets, generates boundary constrained Delaunay tetrahedralization and      //
// quality (conforming) Delaunay tetrahedralizations for three-dimensional   //
// Piecewise Linear Complex(PLC).                                            //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

class mesh3d {

  public:

    // Labels that signify the result of point location.  The result of a
    //   search indicates that the point falls in the interior of a tetra-
    //   hedra, on a face, on an edge, on a vertex, or outside the mesh.
    enum locateresult {INTETRAHEDRON, ONFACE, ONEDGE, ONVERTEX, OUTSIDE};

    // Labels that signify the result of site insertion.  The result indica-
    //   tes that the point was inserted with complete success, was inserted
    //   but encroaches on a segment or a subface, was not inserted because
    //   it lies on a segment or a subface, or was not inserted because
    //   another point occupies the same location.
    enum insertsiteresult {SUCCESSFUL, FAILED, VIOLATINGEDGE, VIOLATINGFACE,
                           DUPLICATE};

    // Labels that signify the result of direction finding.  The result
    //   indicates that a segment connecting the two query points falls
    //   within the tetrahedron's face, along the left edge of the face
    //   along the right edge of the face, along the top edge of the face
    //   or cross the opposite face of the query point.
    enum finddirectionresult {LEFTCOLLINEAR, RIGHTCOLLINEAR, TOPCOLLINEAR,
                              WITHIN, ACROSS};

    // Labels that signify the result of subface matching.  The result of a
    //   match indicates that the match face is existing in mesh, one edge
    //   of the match face is missing, or two edge of the match face is mis-
    //   sing.
    enum matchfaceresult {FACEMATCHING, EDGEMISSING, APEXMISSING};

    // Labels that signify the result of tetrahedral face category. The
    //   result of face category are used for purposes of face and edge
    //   swapping. 'T' indicates that the face is transformable, 'N'
    //   indicates non-transformable. For 'T' faces, the digits are the
    //   number of tets before and after the transformation.  For 'N' faces,
    //   the digits are the number of tets that would be present for a
    //   transformable case; a zero as the second digit indicates that the
    //   case is irrevocably unswappable.
    enum facecategory {T23, T32, T22, T44, N32, N44, N40, N30, N20, LOCKED};

    // Labels that signify two edge ring of a triangle, one(CCW) traversing
    //   edges in counterclockwise direction and one(CW) travesing edges in
    //   clockwise direction.
    enum {CCW = 0, CW = 1};

  public:

    // Variables used to allocate and access memory.
    memorypool tetrahedrons;
    memorypool subfaces;
    memorypool subsegs;
    memorypool points;
    memorypool viri;
    memorypool badsegments;
    memorypool badfaces;
    memorypool badtets;

    // Variables for global used.
    REAL xmin, xmax, ymin, ymax, zmin, zmax;
    int inpoints, inelements, infacets, holes, regions;
    int mesh_dim, nextras, eextras;
    long faces, hullsize;
    int tetwords, shwords;
    int pointmarkindex, point2tetindex;
    int highorderindex, elemattribindex, volumeboundindex;
    int checksegments;
    int readnodefile;
    long samples;
    unsigned long randomseed;

    // Vraiables for switches.
    int poly, smesh;
    int refine, quality, varvolume, fixedvolume, regionattrib, convex;
    int firstnumber;
    int facesout, edgesout, voronoi, neighbors, geomview;
    int nopolywritten, nonodewritten, noelewritten, noiterationnum;
    int nobound, noholes, nobisect, noexact, noroundoff;
    int splitseg, steiner, steinerleft;
    int docheck;
    int quiet, verbose;
    int useshelles, usefliplist;
    int shflaws, shsegflaws, tetflaws;
    int badelemreport;
    REAL minratio, goodratio;
    REAL maxvolume;
    REAL usertolerance, userubtolerance;

    // A queue used to keep all uncategorized tetrahedra's face, which
    //   maybe non local optimal.
    queue *fliplist;

    // Pointer to the two-dimensional mesh generator. Used in surface
    //   recover process.
    mesh2d *surfmesh;

    // Pointer to a recently visited tetrahedron. Improves point location
    //   if proximate points are inserted sequentially.
    triface recenttet;

    // Pointer to the 'tetrahedron' that occupies all of "outer space".
    tetrahedron *dummytet;
    tetrahedron *dummytetbase; // Keep base address so we can free it later.

    // Pointer to the omnipresent shell face.  Referenced by any tetrahedron,
    //   or subface that isn't really connected to a shell face at that
    //   location.
    shellface *dummysh;
    shellface *dummyshbase;  // Keep base address so we can free() it later.

    // Variables used to quality mesh generation.
    badface3d *facequefront[2];
    badface3d **facequetail[2];
    badtet *tetquefront[64];
    badtet **tetquetail[64];
    list *uncheckedshseglist;
    list *uncheckedshlist;
    list *uncheckedtetlist;
    // Three lists used for Boywer-Watson point insertion scheme.
    list *cavetetlist;
    list *caveshlist;
    list *cavebdfacelist;

    long inspherecount;               // Number of insphere tests performed.
    long orient3dcount;               // Number of orient3d tests performed.
    long cospherecount;                        // Number of cosphere tested.
    long segmentintersectioncount; // Number segment intersection performed.
    // Number of flips performed.
    long flip_t23s, flip_t32s, flip_t22s, flip_t44s;

    // Vraiables for filenames.
    char innodefilename[FILENAMESIZE];
    char inelefilename[FILENAMESIZE];
    char inpolyfilename[FILENAMESIZE];
    char insmeshfilename[FILENAMESIZE];
    char volumefilename[FILENAMESIZE];
    char outnodefilename[FILENAMESIZE];
    char outelefilename[FILENAMESIZE];
    char outpolyfilename[FILENAMESIZE];
    char facefilename[FILENAMESIZE];
    char edgefilename[FILENAMESIZE];
    char neighborfilename[FILENAMESIZE];
    char offfilename[FILENAMESIZE];
    char commandline[FILENAMESIZE];

  public:

    ////////////////////////////////////////////////////////////////////////
    //                                                                    //
    // Mesh manipulation primitives.                                      //
    //                                                                    //
    //   Each tetrahedron contains four pointers to other tetrahedra,     //
    // with face locations. Each pointer  points not to the first pointer //
    // of a tetrahedron, but to one of the first four pointers of a       //
    // tetrahedron. It is necessary to extract both the tetrahedron       //
    // itself and the face location. To save memory,  We keep both pieces //
    // (a tet pointer, a face loction) of information in one pointer, and //
    // do not allocate space for face version.  To make this possible,  I //
    // assume that all tetrahedra are aligned to eight-byte boundaries.   //
    // The three least significant bits (two for face locations, one for  //
    // viral infection) are masked out to produce the real pointer. The   //
    // 'decode' primitive below decodes a pointer, extracting a face      //
    // location, and a pointer to the a tetrahedron. The 'encode'         //
    // primitive compresses a pointer to a tetrahedron and a face         //
    // location into a single pointer.                                    //
    //                                                                    //
    ////////////////////////////////////////////////////////////////////////

    // Fast lookup tables for mesh manipulation primitives. These tables are
    //   just like global variables that used by all objects of the class.

    // For enext() primitive, use 'ver' as index.
    static int ve[6];

    // For org(), dest() and apex() primitives, use 'ver' as index.
    static int vo[6], vd[6], va[6];

    // For org(), dest() and apex() primitives, use 'loc' as first index
    //   and 'ver' as second index.
    static int locver2org[4][6];
    static int locver2dest[4][6];
    static int locver2apex[4][6];
    // For oppo() primitives, use 'loc' as index.
    static int loc2oppo[4];

    // For fnext() primitives, use 'loc' as first index and 'ver' as second
    //   index, return a new 'loc' and new 'ver' in an int array.
    // Note: Only valid for face version = 0, 2, 4.
    static int locver2nextf[4][6][2];

    static int plus1mod3[3];
    static int minus1mod3[3];

    // Some macros for convenience
    #define Div2  >> 1
    #define Mod2  & 01
    // NOTE: These bit operators should only be used in macros below.

    // Get orient(Range from 0 to 2) from face version(Range from 0 to 5).
    #define Orient(V)   ((V) Div2)

    // Determine edge ring(0 or 1) from face version(Range from 0 to 5).
    #define EdgeRing(V) ((V) Mod2)

    ////////////////////////////////////////////////////////////////////////
    // Primitives for tetrahedron                                         //
    ////////////////////////////////////////////////////////////////////////

    // decode() converts a pointer to a triface.  The location is
    //   extracted from the two least significant bits of the pointer.
    static void decode(tetrahedron ptr, triface& tface) {
      tface.loc = (int) ((unsigned long) (ptr) & (unsigned long) 3l);
      tface.tet = (tetrahedron *)
                  ((unsigned long) (ptr) & ~(unsigned long) 7l);
    }

    // encode() compresses a triface into a single pointer.  It relies on
    //   the assumption that all tetrahedra are aligned to four-byte
    //   boundaries, so the two least significant bits of (triface).tet are
    //   zero.
    static tetrahedron encode(triface& tface) {
      return (tetrahedron)
             ((unsigned long) tface.tet | (unsigned long) tface.loc);
    }

    // sym() finds the abutting tetrahedron on the same face.
    static void sym(triface& tface1, triface& tface2) {
      tetrahedron ptr = tface1.tet[tface1.loc];
      decode(ptr, tface2);
    }

    static void symself(triface& tface) {
      tetrahedron ptr = tface.tet[tface.loc];
      decode(ptr, tface);
    }

    // The bond() and dissolve() primitives are just like the splice()
    //   primitive of Mucke[2]'s.

    // Bond two tetrahedra together at their faces.
    static void bond(triface& tface1, triface& tface2) {
      tface1.tet[tface1.loc] = encode(tface2);
      tface2.tet[tface2.loc] = encode(tface1);
    }

    // Dissolve a bond (from one side).  Note that the other tetrahedron
    //   will still think it's connected to this tetrahedron.  Usually,
    //   however, the other tetrahedron is being deleted entirely, or bonded
    //   to another tetrahedron, so it doesn't matter.
    // Note: 'dummytet' isn't a static member variable of class, that's
    //   the reason why dissolve() can not be declared with 'static'.
    void dissolve(triface& tface) {
      tface.tet[tface.loc] = (tetrahedron) dummytet;
    }

    // These primitives determine or set the origin, destination, apex or
    //   opposition of a tetrahedron with respect to 'loc' and 'ver'.

    static void org(triface& tface, point3d& pointptr) {
      pointptr = (point3d) tface.tet[locver2org[tface.loc][tface.ver] + 4];
    }

    static point3d org(triface& tface) {
      return (point3d) tface.tet[locver2org[tface.loc][tface.ver] + 4];
    }

    static void dest(triface& tface, point3d& pointptr) {
      pointptr = (point3d) tface.tet[locver2dest[tface.loc][tface.ver] + 4];
    }

    static point3d dest(triface& tface) {
      return (point3d) tface.tet[locver2dest[tface.loc][tface.ver] + 4];
    }

    static void apex(triface& tface, point3d& pointptr) {
      pointptr = (point3d) tface.tet[locver2apex[tface.loc][tface.ver] + 4];
    }

    static point3d apex(triface& tface) {
      return (point3d) tface.tet[locver2apex[tface.loc][tface.ver] + 4];
    }

    static void oppo(triface& tface, point3d& pointptr) {
      pointptr = (point3d) tface.tet[loc2oppo[tface.loc] + 4];
    }

    static point3d oppo(triface& tface) {
      return (point3d) tface.tet[loc2oppo[tface.loc] + 4];
    }

    static void setorg(triface& tface, point3d pointptr) {
      tface.tet[locver2org[tface.loc][tface.ver] + 4] = (tetrahedron) pointptr;
    }

    static void setdest(triface& tface, point3d pointptr) {
      tface.tet[locver2dest[tface.loc][tface.ver] + 4] = (tetrahedron) pointptr;
    }

    static void setapex(triface& tface, point3d pointptr) {
      tface.tet[locver2apex[tface.loc][tface.ver] + 4] = (tetrahedron) pointptr;
    }

    static void setoppo(triface& tface, point3d pointptr) {
      tface.tet[loc2oppo[tface.loc] + 4] = (tetrahedron) pointptr;
    }

    static void setvertices2null(triface& tface) {
      tface.tet[4] = (tetrahedron) NULL;
      tface.tet[5] = (tetrahedron) NULL;
      tface.tet[6] = (tetrahedron) NULL;
      tface.tet[7] = (tetrahedron) NULL;
    }

    // These primitives were drived from Mucke[2]'s triangle-based data
    //   structure to change face-edge relation in a tetrahedron (esym,
    //   enext and enext2) or between two tetrahedra (fnext).

    // If e0 = e(i, j), e1 = e(j, i), that is e0 and e1 are the two
    //   direction of the same undirected edge of a triangular face.
    //   e0.sym() = e1 and vice versa.
    static void esym(triface& tface1, triface& tface2) {
      tface2.tet = tface1.tet;
      tface2.loc = tface1.loc;
      tface2.ver = tface1.ver + (EdgeRing(tface1.ver) ? -1 : 1);
    }

    static void esymself(triface& tface) {
      tface.ver += (EdgeRing(tface.ver) ? -1 : 1);
    }

    // If e0 and e1 are both in the same edge ring of a triangular face,
    //   e1 = e0.enext(). Then e1 is the successor of e0.
    static void enext(triface& tface1, triface& tface2) {
      tface2.tet = tface1.tet;
      tface2.loc = tface1.loc;
      tface2.ver = ve[tface1.ver];
    }

    static void enextself(triface& tface) {
      tface.ver = ve[tface.ver];
    }

    // enext2() is equal to e2 = e0.enext().enext()
    static void enext2(triface& tface1, triface& tface2) {
      tface2.tet = tface1.tet;
      tface2.loc = tface1.loc;
      tface2.ver = ve[ve[tface1.ver]];
    }

    static void enext2self(triface& tface) {
      tface.ver = ve[ve[tface.ver]];
    }

    // If f0 and f1 are both in the same triangle ring of a triangular face,
    //   f1 = f0.fnext(), Then f1 is the successor of f0. Return true if f1
    //   exist. Return false if f1 not exist(f0 is a boundary face).
    #define fnext(triface1, triface2)                                      \
      getnextface(&(triface1), &(triface2))

    #define fnextself(triface)                                             \
      getnextface(&(triface), NULL)

    // enextfnext() and enext2fnext() are combination primitives of enext()
    //   and fnext().
    #define enextfnext(triface1, triface2)                                 \
      enext(triface1, triface2);                                           \
      fnextself(triface2)

    #define enextfnextself(triface)                                        \
      enextself(triface);                                                  \
      fnextself(triface)

    #define enext2fnext(triface1, triface2)                                \
      enext2(triface1, triface2);                                          \
      fnextself(triface2)

    #define enext2fnextself(triface)                                       \
      enext2self(triface);                                                 \
      fnextself(triface)

    // Primitives to infect or cure a tetrahedron with the virus. These rely
    //   on the assumption that all tetrahedron are aligned to eight-byte
    //   boundaries.
    static void infect(triface& tface) {
      tface.tet[0] = (tetrahedron)
                    ((unsigned long) tface.tet[0] | (unsigned long) 4l);
    }

    static void uninfect(triface& tface) {
      tface.tet[0] = (tetrahedron)
                  ((unsigned long) tface.tet[0] & ~ (unsigned long) 4l);
    }

    // Test a tetrahedron for viral infection.
    static bool infected(triface& tface) {
      return (((unsigned long) tface.tet[0] & (unsigned long) 4l) != 0);
    }

    // Check or set a tetrahedron's attributes.
    REAL elemattribute(tetrahedron* ptr, int attnum) {
      return ((REAL *) (ptr))[elemattribindex + attnum];
    }

    void setelemattribute(tetrahedron* ptr, int attnum, REAL value) {
      ((REAL *) (ptr))[elemattribindex + attnum] = value;
    }

    // Check or set a tetrahedron's maximum volume bound.
    REAL volumebound(tetrahedron* ptr) {
      return ((REAL *) (ptr))[volumeboundindex];
    }

    void setvolumebound(tetrahedron* ptr, REAL value) {
      ((REAL *) (ptr))[volumeboundindex] = value;
    }

    ////////////////////////////////////////////////////////////////////////
    // Primitives for shellface                                           //
    ////////////////////////////////////////////////////////////////////////

    // sdecode() converts a pointer to an oriented shell face.  The face
    //   version is extracted from the least three significant bit of the
    //   pointer.  The three least significant bits are masked out to
    //   produce the real pointer.
    static void sdecode(shellface sptr, face& sface) {
      sface.shver = (int) ((unsigned long) (sptr) & (unsigned long) 7l);
      sface.sh = (shellface *)
             ((unsigned long) (sptr) & ~ (unsigned long) 7l);
    }

    // sencode() compresses an oriented shell face into a single pointer.
    //   It relies on the assumption that all shell faces are aligned to
    //   eight-byte boundaries, so the least three significant bit of
    //   (face).sh is zero.
    static shellface sencode(face& sface) {
      return (shellface)
             ((unsigned long) sface.sh | (unsigned long) sface.shver);
    }

    // spivot() finds the other shell face (from the same face) that shares
    //   the same edge.
    static void spivot(face& sface1, face& sface2) {
      shellface sptr = sface1.sh[Orient(sface1.shver)];
      sdecode(sptr, sface2);
    }

    static void spivotself(face& sface) {
      shellface sptr = sface.sh[Orient(sface.shver)];
      sdecode(sptr, sface);
    }

    // Bond two shell faces together.
    static void sbond(face& sface1, face& sface2) {
      sface1.sh[Orient(sface1.shver)] = sencode(sface2);
      sface2.sh[Orient(sface2.shver)] = sencode(sface1);
    }

    // Dissolve a shell face bond (from one side).  Note that the other
    //   shell face will still think it's connected to this shell face.
    // Note: 'dummysh' isn't a static member variable of class, that's
    //   the reason why sdissolve() can not be declared with 'static'.
    void sdissolve(face& sface) {
      sface.sh[Orient(sface.shver)] = (shellface) dummysh;
    }

    // These primitives determine or set the origin, destination, or apex
    //   of a shell face with respect to current face version.

    static void sorg(face& sface, point3d& pointptr) {
      pointptr = (point3d) sface.sh[3 + vo[sface.shver]];
    }

    static point3d sorg(face& sface) {
      return (point3d) sface.sh[3 + vo[sface.shver]];
    }

    static void sdest(face& sface, point3d& pointptr) {
      pointptr = (point3d) sface.sh[3 + vd[sface.shver]];
    }

    static point3d sdest(face& sface) {
      return (point3d) sface.sh[3 + vd[sface.shver]];
    }

    static void sapex(face& sface, point3d& pointptr) {
      pointptr = (point3d) sface.sh[3 + va[sface.shver]];
    }

    static point3d sapex(face& sface) {
      return (point3d) sface.sh[3 + va[sface.shver]];
    }

    static void setsorg(face& sface, point3d pointptr) {
      sface.sh[3 + vo[sface.shver]] = (shellface) pointptr;
    }

    static void setsdest(face& sface, point3d pointptr) {
      sface.sh[3 + vd[sface.shver]] = (shellface) pointptr;
    }

    static void setsapex(face& sface, point3d pointptr) {
      sface.sh[3 + va[sface.shver]] = (shellface) pointptr;
    }

    // These primitives were drived from Mucke[2]'s triangle-based data
    //   structure to change face-edge relation in a tetrahedron (sesym,
    //   senext and senext2).

    static void sesym(face& sface1, face& sface2) {
      sface2.sh = sface1.sh;
      sface2.shver = sface1.shver + (EdgeRing(sface1.shver) ? -1 : 1);
    }

    static void sesymself(face& sface) {
      sface.shver += (EdgeRing(sface.shver) ? -1 : 1);
    }

    static void senext(face& sface1, face& sface2) {
      sface2.sh = sface1.sh;
      sface2.shver = ve[sface1.shver];
    }

    static void senextself(face& sface) { sface.shver = ve[sface.shver]; }

    static void senext2(face& sface1, face& sface2) {
      sface2.sh = sface1.sh;
      sface2.shver = ve[ve[sface1.shver]];
    }

    static void senext2self(face& sface) {
      sface.shver = ve[ve[sface.shver]];
    }

    // These primitives read or set a shell marker.  Shell markers are used
    //   to hold user boundary information.

    static int mark(face& sface) { return (* (int *) (sface.sh + 11)); }

    static void setmark(face& sface, int value) {
      * (int *) (sface.sh + 11) = value;
    }

    // Primitives to infect or cure a shell face with the virus. These rely
    //   on the assumption that all shell face are aligned to eight-byte
    //   boundaries.
    static void sinfect(face& sface) {
      sface.sh[10] = (shellface)
                     ((unsigned long) sface.sh[10] | (unsigned long) 4l);
    }

    static void suninfect(face& sface) {
      sface.sh[10] = (shellface)
                     ((unsigned long) sface.sh[10] & ~ (unsigned long) 4l);
    }

    // Test a shell face for viral infection.
    static bool sinfected(face& sface) {
      return (((unsigned long) sface.sh[10] & (unsigned long) 4l) != 0);
    }

    ////////////////////////////////////////////////////////////////////////
    // Primitives for interacting tetrahedra and subfaces                 //
    ////////////////////////////////////////////////////////////////////////

    // tspivot() finds a subface abutting on this tetrahdera.
    static void tspivot(triface& tface, face& sface) {
      shellface sptr = (shellface) tface.tet[8 + tface.loc];
      sdecode(sptr, sface);
    }

    // stpivot() finds a tetrahedron abutting a subface.
    static void stpivot(face& sface, triface& tface) {
      tetrahedron ptr = (tetrahedron) sface.sh[6 + EdgeRing(sface.shver)];
      decode(ptr, tface);
    }

    // tsbond() bond a tetrahedron to a subface.
    static void tsbond(triface& tface, face& sface) {
      tface.tet[8 + tface.loc] = (tetrahedron) sencode(sface);
      sface.sh[6 + EdgeRing(sface.shver)] = (shellface) encode(tface);
    }

    // tsdissolve() dissolve a bond (from the tetrahedron side).
    void tsdissolve(triface& tface) {
      tface.tet[8 + tface.loc] = (tetrahedron) dummysh;
    }

    // stdissolve() dissolve a bond (from the subface side).
    void stdissolve(face& sface) {
      sface.sh[6 + EdgeRing(sface.shver)] = (shellface) dummytet;
    }

    ////////////////////////////////////////////////////////////////////////
    // Primitives for interacting subfaces and subsegments                //
    ////////////////////////////////////////////////////////////////////////

    // sspivot() finds a subsegment abutting a subface.
    static void sspivot(face& sface, face& edge) {
      shellface sptr = (shellface) sface.sh[8 + Orient(sface.shver)];
      sdecode(sptr, edge);
    }

    // ssbond() bond a subface to a subsegment.
    static void ssbond(face& sface, face& edge) {
      sface.sh[8 + Orient(sface.shver)] = sencode(edge);
      edge.sh[0] = sencode(sface);
    }

    // ssdisolve() dissolve a bond (from the subface side)
    void ssdissolve(face& sface) {
      sface.sh[8 + Orient(sface.shver)] = (shellface) dummysh;
    }

    ////////////////////////////////////////////////////////////////////////
    // Primitives for point3d                                             //
    ////////////////////////////////////////////////////////////////////////

    int pointmark(point3d pt) { return ((int *) (pt))[pointmarkindex]; }

    void setpointmark(point3d pt, int value) {
      ((int *) (pt))[pointmarkindex] = value;
    }

    tetrahedron point2tet(point3d pt) {
      return ((tetrahedron *) (pt))[point2tetindex];
    }

    void setpoint2tet(point3d pt, tetrahedron value) {
      ((tetrahedron *) (pt))[point2tetindex] = value;
    }

    ////////////////////////////////////////////////////////////////////////
    // Advanced primitives                                                //
    ////////////////////////////////////////////////////////////////////////

    // Implement the fnext(), fnextself() primitives of tetrahedron.
    bool getnextface(triface*, triface*);

    // Finds a subsegment abutting on this tetrahdera.
    void tsspivot(triface*, face*);

    // Finds a tetrahedron abutting a subsegment.
    void sstpivot(face*, triface*);

    ////////////////////////////////////////////////////////////////////////
    // Useful auxiliary primitives                                        //
    ////////////////////////////////////////////////////////////////////////

    // Find and set version to indicate the directed edge.
    static void findversion(triface*, point3d, point3d, int symflag = 1);
    static void findversion(triface*, triface*, int symflag = 1);
    static void findversion(triface*, face*, int symflag = 1);
    static void findversion(face*, point3d, point3d, int symflag = 1);
    static void findversion(face*, triface*, int symflag = 1);
    static void findversion(face*, face*, int symflag = 1);

    // Find and set the version to indicate the desired point.
    bool findorg(triface*, point3d);
    bool findorg(face*, point3d);

    // Adjusts edge version(ver) to corresponding edge ring if necessary.
    //   Here direction is only valid for 0(CCW) or 1(CW).
    static void adjustedgering(triface& tface, int direction) {
      if (EdgeRing(tface.ver) != direction) {
        esymself(tface);
      }
    }

    // Returns true if adjoining tetrahedron exist.
    // Note: 'dummytet' is not a static member variable.
    bool issymexist(triface* tface) {
      tetrahedron *ptr = (tetrahedron *)
        ((unsigned long)(tface->tet[tface->loc]) & ~(unsigned long)3l);
      return ptr != dummytet;
    }

    // Returns true if this tetrahedron is dealloced.
    static bool isdead(triface* tface) {
      if (tface->tet == (tetrahedron*) NULL) {
        return true;
      } else {
        return tface->tet[4] == (tetrahedron) NULL;
      }
    }

    // Returns true if this shellface is dealloced.
    static bool isdead(face* sface) {
      if (sface->sh == (shellface*) NULL) {
        return true;
      } else {
        return sface->sh[3] == (shellface) NULL;
      }
    }

    // Test if the subface is a non-solid subface. Every non-solid subface
    //   is marked with a special flag NONSOLIDFLAG.
    static bool isnonsolid(face& sface) {
      return mark(sface) == NONSOLIDFLAG;
    }

    // Return true if the point is one of vertices of input triangular face.
    static bool isfacehaspoint(triface* tface, point3d testpoint) {
      return  ((org(*tface) == testpoint)
               || (dest(*tface) == testpoint)
               || (apex(*tface) == testpoint));
    }

    // Compare the coordinates of two points to see if they are coincident.
    //   Return true if they are coincident, otherwise return false;
    bool issamepoint(point3d p1, point3d p2) {
      return (fabs(p1[0] - p2[0]) <= usertolerance)
              && (fabs(p1[1] - p2[1]) <= usertolerance)
              && (fabs(p1[2] - p2[2]) <= usertolerance);
    }

    // Returns true if the edge of tetrahedron(specified by loc and ver)
    //   is a ridge in the mesh.
    bool isridge(triface*);

    // Test if there exist any segment shars with input segment's origin.
    //   Return true if exist such segment, otherwise return false.
    bool isexistincidentseg(face*);

    // Compare the vertices of two faces/edges to see if they are the same
    //   face/edge. The inputs are handles of two tetrahedra. Only return
    //   0 (same) or 1 (diffrent). The two primitives mainly used as list
    //   or link's linear order functions.
    static int issameface(triface*, triface*);
    static int issameedge(triface*, triface*);

    // For debuging, print out the details of a tetrahedron/shellfacet
    //   handle to standard output.
    void dump(triface*);
    void dump(face*);

    ////////////////////////////////////////////////////////////////////////
    // End of mesh manipulation primitives                                //
    ////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////
    // Commonly used vector operations                                    //
    ////////////////////////////////////////////////////////////////////////

    // Assign3D(), Return: vres = va.
    static void Assign3D(REAL* va, REAL* vres) {
      vres[0] = va[0]; vres[1] = va[1]; vres[2] = va[2];
    }

    // Sub3D(), Return: vres = va - vb.
    static void Sub3D(REAL* va, REAL* vb, REAL* vres) {
      vres[0] = va[0] - vb[0];
      vres[1] = va[1] - vb[1];
      vres[2] = va[2] - vb[2];
    }

    // Scale3D(), Return: vres = vres * scale.
    static void Scale3D(REAL* vres, REAL scale) {
      vres[0] *= scale; vres[1] *= scale; vres[2] *= scale;
    }

    // Dot3D(), Return: va dot vb.
    static REAL Dot3D(REAL* va, REAL* vb) {
      return (va[0] * vb[0] + va[1] * vb[1] + va[2] * vb[2]);
    }

    // Cross3D(), Return: vres = va cross vb.
    static void Cross3D(REAL* va, REAL* vb, REAL* vres) {
      vres[0] = va[1] * vb[2] - va[2] * vb[1];
      vres[1] = va[2] * vb[0] - va[0] * vb[2];
      vres[2] = va[0] * vb[1] - va[1] * vb[0];
    }

    // Mag3D(), Return: Mod of va.
    static REAL Mag3D(REAL* va) {
      return sqrt(va[0] * va[0] + va[1] * va[1] + va[2] * va[2]);
    }

    // Dist3D(), Return the Euler distance of va and vb.
    static REAL Dist3D(REAL* va, REAL* vb) {
      return sqrt((va[0] - vb[0]) * (va[0] - vb[0])
                  + (va[1] - vb[1]) * (va[1] - vb[1])
                  + (va[2] - vb[2]) * (va[2] - vb[2]));
    }

    // Normal3D(), Compute the vector normal for a set of three points.
    static void Normal3D(REAL* va, REAL* vb, REAL* vc, REAL* vnormal) {
      REAL tempb[3], tempc[3];
      Sub3D(vb, va, tempb);
      Sub3D(vc, va, tempc);
      Cross3D(tempb, tempc, vnormal);
    }

    // Normalize3D(), Return: Unit vector of va.
    static void Normalize3D(REAL* va) {
      REAL invmag = 1. / Mag3D(va);
      Scale3D(va, invmag);
    }

    static void Swap3D(REAL* va, REAL* vb) {
      REAL temp;
      temp = vb[0]; vb[0] = va[0]; va[0] = temp;
      temp = vb[1]; vb[1] = va[1]; va[1] = temp;
      temp = vb[2]; vb[2] = va[2]; va[2] = temp;
    }

    ////////////////////////////////////////////////////////////////////////
    // End of commonly used vector operations                             //
    ////////////////////////////////////////////////////////////////////////

    // Memory management routines
    void dummyinit(int, int);
    void initializepointpool();
    void initializetetshpools();
    void tetrahedrondealloc(tetrahedron*);
    tetrahedron *tetrahedrontraverse();
    void shellfacedealloc(memorypool*, shellface*);
    shellface *shellfacetraverse(memorypool*);
    void badsegmentdealloc(badface3d*);
    badface3d *badsegmenttraverse();
    void pointdealloc(point3d);
    point3d pointtraverse();
    point3d getpoint(int number);
    // tetrahedron, subface and subsegment construct routines
    void maketetrahedron(triface*);
    void makeshellface(memorypool*, face*);

    // Geometric primitives.
    inline bool iszero(const REAL);
    int iorient3d(point3d, point3d, point3d, point3d);
    int iinsphere(point3d, point3d, point3d, point3d, point3d);
    int iinsphere(triface*, point3d);
    bool isbelowplane(point3d, point3d, point3d, point3d);
    bool isbelowplane(triface*, point3d);
    bool isaboveplane(point3d, point3d, point3d, point3d);
    bool isaboveplane(triface*, point3d);
    bool iscoplane(point3d, point3d, point3d, point3d);
    bool iscoplane(triface*, point3d);
    bool iscoline(point3d, point3d, point3d);

    // Geometric functions.
    void projontoface(point3d, point3d, point3d, point3d);
    void circumcenter(point3d, point3d, point3d, point3d);
    void circumcenter(point3d, point3d, point3d, point3d, point3d);
    REAL tetvolume(point3d, point3d, point3d, point3d);
    REAL facedihedral(point3d, point3d, point3d, point3d, point3d, point3d);
    void tetalldihedral(point3d, point3d, point3d, point3d, REAL[6]);

    // Point location routines.
    // (Fast Randomized Point Location Algorithm of Mucke, Issac and Zhu.)
    unsigned long randomnation(unsigned int);
    void makepointmap();
    REAL distance(triface*, point3d);
    enum locateresult isintet(point3d, point3d, point3d, point3d, point3d);
    enum locateresult iscoplanarintri(point3d, triface*);
    enum locateresult preciselocate(point3d, triface*);
    enum locateresult locate(point3d, triface*);

    // Mesh transformation routines.
    enum facecategory categorizeface(triface&);
    bool querydoswap(triface&);
    // bool querydoswap(triface&, enum facecategory);
    void preservesubsegments(face&, triface&);
    void enqueuefliplist(triface&);
    bool dequeuefliplist(triface&);
    int flip23(triface&);
    int flip32(triface&);
    int flip22(triface&);
    int flip44(triface&);
    int flip(triface&);

    // Insert/Delete point routines.
    enum insertsiteresult insertsite(point3d, triface*, face*, face*);
    int insertonedge(point3d, triface*, face*);
    int insertonface(point3d, triface*, face*);
    int insertininterior(point3d, triface*);
    void insertsubface(triface*, int, int);
    void insertsubsegment(triface*, int);
    int deletesite(triface*);

    // Giftwrapping Algorithm
    int is_face_tet_inter_0(triface*, point3d, point3d, point3d, point3d);
    int is_face_tet_inter_1(triface*, point3d, point3d, point3d, point3d);
    int is_face_tet_inter_2(triface*, point3d, point3d, point3d, point3d);
    int getgiftface(list*, int, int*, list*);
    int getgiftpoint(triface*, list*, int, point3d*, int*, list*, list*);
    int giftwrapping(int, triface*, int, point3d*, REAL*, REAL, list*);

    // Delaunay tetrahedrization construct routines.
    // (Randomized Incremental Flip Algorithm.)
    void construct_initial_tetra(queue*);
    void collect_visibles(point3d, triface*, triface*, link*);
    int dofliplist();
    long rand_incr_flip_delaunay();
    long delaunay();

    // Segment/facet (boundary) constrained routines.
    enum finddirectionresult finddirection(triface*, point3d);
    void segmentintersection(triface*, face*, point3d);
    int scoutsegment(triface*, point3d, int);
    void conformingedge(point3d, point3d, int);
    void insertsegment(point3d, point3d, int);
    void getsteinersinseg(point3d, point3d, list*);
    int getdiagonalapexindex(struct triangulateio*, int, int);
    int getneighbourtriedge(struct triangulateio*, int, int, int*, int*);
    int swapdiagonal(struct triangulateio*, int, int, int);
    enum matchfaceresult matchface(point3d, point3d, point3d, triface*, int);
    int insertfieldpoint(int, triface*, int, point3d*, list*);
    int recoverface(list*, triangulateio*, int, int);
    void insertfacet(list*, list*, int, int);
    int formskeleton(FILE*);

    // Carving out holes and concavities routines.
    void infecthull();
    void plague();
    void regionplague(REAL, REAL);
    void carveholes(REAL*, int, REAL*, int);

    // Mesh quality testing routines.
    void checkquality(triface*);
    int checkedge4encroach(face*, point3d testpoint = NULL);
    int checkface4encroach(face*, point3d testpoint = NULL);
    void testtetrahedron(triface*);
    void enqueuebadface(face*, point3d, int);
    badface3d *dequeuebadface();
    void enqueuebadtet(triface*, REAL, point3d, point3d, point3d, point3d,
                       point3d);
    badtet *dequeuebadtet();
    // Mesh quality maintenance routines.
    void tallyencsegs();
    void tallyencfaces();
    void tallytets();
    void repairencsegs();
    void repairencfaces();
    void splittet(badtet*);
    void enforcequality();

    // File I/O routines.
    char *readline(char*, FILE*, char*);
    char *findfield(char*);
    void readnodes(FILE**);
    void readholes(FILE*, REAL**, int*, REAL**, int*);
    void numbernodes(int myfirstnumber = 0);
    void outnodes();
    void outelems();
    void outfaces(int hull = 0);
    void outedges();
    void outneighbors();
    void outoff();
    void outelems2gid();
    void outfaces2gid(int hull = 0);
    void outedges2gid();
    void outelems2fa();

    // Debug routines.
    void dumpgifts(char*, list*, int, point3d*, int*);
    void dumplist(char*, list*, int, int);
    void dumpallbadelems(char*);

    void internalerror();
    void precisionerror();
    void recovererror();

    void checkmesh();
    void checkdelaunay();
    void checkshells();
    void statistics();
    void quality_statistics();
    void syntax();

    void meshinit();
    void meshdeinit();
    void parsecommandline(int, char**);

  public:

    mesh3d() { meshinit(); }
    ~mesh3d() { meshdeinit(); }

    // General mesh construction.
    void triangulate(int, char**);
};

#endif // #ifndef tetlibH
