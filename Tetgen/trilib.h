///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// trilib.h    Declaration class mesh2d for two-dimensional mesh generator.  //
//                                                                           //
// Tetgen Version 1.0 beta                                                   //
// July, 2001                                                                //
//                                                                           //
// Si hang                                                                   //
// Email: sihang@weboo.com                                                   //
// http://www.weboo.com/sh/tetgen.htm                                        //
//                                                                           //
// You are free to use, copy and modify the sources under certain            //
// circumstances, provided this copyright notice remains intact.             //
// See the file LICENSE for details.                                         //
//                                                                           //
// This file with it's couple file trilib.cpp are modified version of the    //
// triangle program of Jonathan Richard Shewchuk, which is public available  //
// from the following Web page with its license(see below):                  //
//                                                                           //
//             http://www.cs.cmu.edu/~quake/triangle.html                    //
//                                                                           //
// In Tetgen, there frequently need to generate a constrained Delaunay       //
// triangulation of a given facet. For example, in facet recovery stage, for //
// each facet, it is necessary maintain a two-dimensional Delaunay triangul- //
// ation of its vertices, independent from the tetrahedralization in which   //
// we hope its subfaces will eventually appear. For each triangular subface  //
// in a facet triangulation, look for a matching face in the tetrahedraliza- //
// tion.                                                                     //
//                                                                           //
// For this purpose, I embeded an object of two-dimensional Delaunay triang- //
// ulator as member variable of class mesh3d(declared in tetlib.h). The type //
// (class mesh2d) of this object is declared in this file, it encapsulates   //
// most of the variables and functions of triangle program.                  //
//                                                                           //
// The usage of class mesh2d is very simple. To call mesh2d in functions,    //
// use the triangulateio structure(defined below). You only write following  //
// lines in functions:                                                       //
//                                                                           //
//      mesh2d mymesh;                                                       //
//      struct triangulateio in, out;                                        //
//      char switches[] = "pznQXPN";  // Commandline switches.               //
//                                                                           //
//      // Initialize 'in' and 'out'                                         //
//      triangulateioinit(&in);                                              //
//      triangulateioinit(&out);                                             //
//                                                                           //
//      // Set input PSLG data to 'in'                                       //
//      ...                                                                  //
//                                                                           //
//      // Do mesh, the corresponding result will store in 'out'             //
//      mymesh(switches, &in, &out, NULL);                                   //
//                                                                           //
//      ...                                                                  //
//                                                                           //
//      // Before return, don't forget to free 'in' and 'out'                //
//      triangulateiodeinit(&in);                                            //
//      triangulateiodeinit(&out);                                           //
//                                                                           //
// Please see the above Web page to get more detail descripton of command    //
// line switches.                                                            //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

/*****************************************************************************/
/*                                                                           */
/*  Traingle program license:                                                */
/*                                                                           */
/*  Triangle                                                                 */
/*  A Two-Dimensional Quality Mesh Generator                                 */
/*  and Delaunay Triangulator.                                               */
/*  Version 1.3                                                              */
/*                                                                           */
/*  Copyright 1996                                                           */
/*  Jonathan Richard Shewchuk                                                */
/*  School of Computer Science                                               */
/*  Carnegie Mellon University                                               */
/*  5000 Forbes Avenue                                                       */
/*  Pittsburgh, Pennsylvania  15213-3891                                     */
/*  jrs@cs.cmu.edu                                                           */
/*                                                                           */
/*  This program may be freely redistributed under the condition that the    */
/*    copyright notices (including this entire header and the copyright      */
/*    notice printed when the `-h' switch is selected) are not removed, and  */
/*    no compensation is received.  Private, research, and institutional     */
/*    use is free.  You may distribute modified versions of this code UNDER  */
/*    THE CONDITION THAT THIS CODE AND ANY MODIFICATIONS MADE TO IT IN THE   */
/*    SAME FILE REMAIN UNDER COPYRIGHT OF THE ORIGINAL AUTHOR, BOTH SOURCE   */
/*    AND OBJECT CODE ARE MADE FREELY AVAILABLE WITHOUT CHARGE, AND CLEAR    */
/*    NOTICE IS GIVEN OF THE MODIFICATIONS.  Distribution of this code as    */
/*    part of a commercial system is permissible ONLY BY DIRECT ARRANGEMENT  */
/*    WITH THE AUTHOR.  (If you are not directly supplying this code to a    */
/*    customer, and you are instead telling them how they can obtain it for  */
/*    free, then you are not required to make any arrangement with me.)      */
/*                                                                           */
/*  Disclaimer:  Neither I nor Carnegie Mellon warrant this code in any way  */
/*    whatsoever.  This code is provided "as-is".  Use at your own risk.     */
/*                                                                           */
/*****************************************************************************/

#ifndef trilibH
#define trilibH

#include "defines.h"
#include "linklist.h"

/*****************************************************************************/
/*                                                                           */
/*  The `triangulateio' structure.                                           */
/*                                                                           */
/*  Used to pass data into and out of the triangulate() procedure.           */
/*                                                                           */
/*                                                                           */
/*  Arrays are used to store points, triangles, markers, and so forth.  In   */
/*  all cases, the first item in any array is stored starting at index [0].  */
/*  However, that item is item number `1' unless the `z' switch is used, in  */
/*  which case it is item number `0'.  Hence, you may find it easier to      */
/*  index points (and triangles in the neighbor list) if you use the `z'     */
/*  switch.  Unless, of course, you're calling Triangle from a Fortran       */
/*  program.                                                                 */
/*                                                                           */
/*  Description of fields (except the `numberof' fields, which are obvious): */
/*                                                                           */
/*  `pointlist':  An array of point coordinates.  The first point's x        */
/*    coordinate is at index [0] and its y coordinate at index [1], followed */
/*    by the coordinates of the remaining points.  Each point occupies two   */
/*    REALs.                                                                 */
/*  `pointattributelist':  An array of point attributes.  Each point's       */
/*    attributes occupy `numberofpointattributes' REALs.                     */
/*  `pointmarkerlist':  An array of point markers; one int per point.        */
/*                                                                           */
/*  `trianglelist':  An array of triangle corners.  The first triangle's     */
/*    first corner is at index [0], followed by its other two corners in     */
/*    counterclockwise order, followed by any other nodes if the triangle    */
/*    represents a nonlinear element.  Each triangle occupies                */
/*    `numberofcorners' ints.                                                */
/*  `triangleattributelist':  An array of triangle attributes.  Each         */
/*    triangle's attributes occupy `numberoftriangleattributes' REALs.       */
/*  `trianglearealist':  An array of triangle area constraints; one REAL per */
/*    triangle.  Input only.                                                 */
/*  `neighborlist':  An array of triangle neighbors; three ints per          */
/*    triangle.  Output only.                                                */
/*                                                                           */
/*  `segmentlist':  An array of segment endpoints.  The first segment's      */
/*    endpoints are at indices [0] and [1], followed by the remaining        */
/*    segments.  Two ints per segment.                                       */
/*  `segmentmarkerlist':  An array of segment markers; one int per segment.  */
/*                                                                           */
/*  `holelist':  An array of holes.  The first hole's x and y coordinates    */
/*    are at indices [0] and [1], followed by the remaining holes.  Two      */
/*    REALs per hole.  Input only, although the pointer is copied to the     */
/*    output structure for your convenience.                                 */
/*                                                                           */
/*  `regionlist':  An array of regional attributes and area constraints.     */
/*    The first constraint's x and y coordinates are at indices [0] and [1], */
/*    followed by the regional attribute and index [2], followed by the      */
/*    maximum area at index [3], followed by the remaining area constraints. */
/*    Four REALs per area constraint.  Note that each regional attribute is  */
/*    used only if you select the `A' switch, and each area constraint is    */
/*    used only if you select the `a' switch (with no number following), but */
/*    omitting one of these switches does not change the memory layout.      */
/*    Input only, although the pointer is copied to the output structure for */
/*    your convenience.                                                      */
/*                                                                           */
/*  `edgelist':  An array of edge endpoints.  The first edge's endpoints are */
/*    at indices [0] and [1], followed by the remaining edges.  Two ints per */
/*    edge.  Output only.                                                    */
/*  `edgemarkerlist':  An array of edge markers; one int per edge.  Output   */
/*    only.                                                                  */
/*  `normlist':  An array of normal vectors, used for infinite rays in       */
/*    Voronoi diagrams.  The first normal vector's x and y magnitudes are    */
/*    at indices [0] and [1], followed by the remaining vectors.  For each   */
/*    finite edge in a Voronoi diagram, the normal vector written is the     */
/*    zero vector.  Two REALs per edge.  Output only.                        */
/*                                                                           */
/*                                                                           */
/*  Any input fields that Triangle will examine must be initialized.         */
/*  Furthermore, for each output array that Triangle will write to, you      */
/*  must either provide space by setting the appropriate pointer to point    */
/*  to the space you want the data written to, or you must initialize the    */
/*  pointer to NULL, which tells Triangle to allocate space for the results. */
/*  The latter option is preferable, because Triangle always knows exactly   */
/*  how much space to allocate.  The former option is provided mainly for    */
/*  people who need to call Triangle from Fortran code, though it also makes */
/*  possible some nasty space-saving tricks, like writing the output to the  */
/*  same arrays as the input.                                                */
/*                                                                           */
/*  Triangle will not free() any input or output arrays, including those it  */
/*  allocates itself; that's up to you.                                      */
/*                                                                           */
/*  Here's a guide to help you decide which fields you must initialize       */
/*  before you call triangulate().                                           */
/*                                                                           */
/*  `in':                                                                    */
/*                                                                           */
/*    - `pointlist' must always point to a list of points; `numberofpoints'  */
/*      and `numberofpointattributes' must be properly set.                  */
/*      `pointmarkerlist' must either be set to NULL (in which case all      */
/*      markers default to zero), or must point to a list of markers.  If    */
/*      `numberofpointattributes' is not zero, `pointattributelist' must     */
/*      point to a list of point attributes.                                 */
/*    - If the `r' switch is used, `trianglelist' must point to a list of    */
/*      triangles, and `numberoftriangles', `numberofcorners', and           */
/*      `numberoftriangleattributes' must be properly set.  If               */
/*      `numberoftriangleattributes' is not zero, `triangleattributelist'    */
/*      must point to a list of triangle attributes.  If the `a' switch is   */
/*      used (with no number following), `trianglearealist' must point to a  */
/*      list of triangle area constraints.  `neighborlist' may be ignored.   */
/*    - If the `p' switch is used, `segmentlist' must point to a list of     */
/*      segments, `numberofsegments' must be properly set, and               */
/*      `segmentmarkerlist' must either be set to NULL (in which case all    */
/*      markers default to zero), or must point to a list of markers.        */
/*    - If the `p' switch is used without the `r' switch, then               */
/*      `numberofholes' and `numberofregions' must be properly set.  If      */
/*      `numberofholes' is not zero, `holelist' must point to a list of      */
/*      holes.  If `numberofregions' is not zero, `regionlist' must point to */
/*      a list of region constraints.                                        */
/*    - If the `p' switch is used, `holelist', `numberofholes',              */
/*      `regionlist', and `numberofregions' is copied to `out'.  (You can    */
/*      nonetheless get away with not initializing them if the `r' switch is */
/*      used.)                                                               */
/*    - `edgelist', `edgemarkerlist', `normlist', and `numberofedges' may be */
/*      ignored.                                                             */
/*                                                                           */
/*  `out':                                                                   */
/*                                                                           */
/*    - `pointlist' must be initialized (NULL or pointing to memory) unless  */
/*      the `N' switch is used.  `pointmarkerlist' must be initialized       */
/*      unless the `N' or `B' switch is used.  If `N' is not used and        */
/*      `in->numberofpointattributes' is not zero, `pointattributelist' must */
/*      be initialized.                                                      */
/*    - `trianglelist' must be initialized unless the `E' switch is used.    */
/*      `neighborlist' must be initialized if the `n' switch is used.  If    */
/*      the `E' switch is not used and (`in->numberofelementattributes' is   */
/*      not zero or the `A' switch is used), `elementattributelist' must be  */
/*      initialized.  `trianglearealist' may be ignored.                     */
/*    - `segmentlist' must be initialized if the `p' or `c' switch is used,  */
/*      and the `P' switch is not used.  `segmentmarkerlist' must also be    */
/*      initialized under these circumstances unless the `B' switch is used. */
/*    - `edgelist' must be initialized if the `e' switch is used.            */
/*      `edgemarkerlist' must be initialized if the `e' switch is used and   */
/*      the `B' switch is not.                                               */
/*    - `holelist', `regionlist', `normlist', and all scalars may be ignored.*/
/*                                                                           */
/*  `vorout' (only needed if `v' switch is used):                            */
/*                                                                           */
/*    - `pointlist' must be initialized.  If `in->numberofpointattributes'   */
/*      is not zero, `pointattributelist' must be initialized.               */
/*      `pointmarkerlist' may be ignored.                                    */
/*    - `edgelist' and `normlist' must both be initialized.                  */
/*      `edgemarkerlist' may be ignored.                                     */
/*    - Everything else may be ignored.                                      */
/*                                                                           */
/*  After a call to triangulate(), the valid fields of `out' and `vorout'    */
/*  will depend, in an obvious way, on the choice of switches used.  Note    */
/*  that when the `p' switch is used, the pointers `holelist' and            */
/*  `regionlist' are copied from `in' to `out', but no new space is          */
/*  allocated; be careful that you don't free() the same array twice.  On    */
/*  the other hand, Triangle will never copy the `pointlist' pointer (or any */
/*  others); new space is allocated for `out->pointlist', or if the `N'      */
/*  switch is used, `out->pointlist' remains uninitialized.                  */
/*                                                                           */
/*  All of the meaningful `numberof' fields will be properly set; for        */
/*  instance, `numberofedges' will represent the number of edges in the      */
/*  triangulation whether or not the edges were written.  If segments are    */
/*  not used, `numberofsegments' will indicate the number of boundary edges. */
/*                                                                           */
/*****************************************************************************/

struct triangulateio {
  REAL *pointlist;                                               /* In / out */
  REAL *pointattributelist;                                      /* In / out */
  int *pointmarkerlist;                                          /* In / out */
  int numberofpoints;                                            /* In / out */
  int numberofpointattributes;                                   /* In / out */

  int *trianglelist;                                             /* In / out */
  REAL *triangleattributelist;                                   /* In / out */
  REAL *trianglearealist;                                         /* In only */
  int *neighborlist;                                             /* Out only */
  int numberoftriangles;                                         /* In / out */
  int numberofcorners;                                           /* In / out */
  int numberoftriangleattributes;                                /* In / out */

  int *segmentlist;                                              /* In / out */
  int *segmentmarkerlist;                                        /* In / out */
  int numberofsegments;                                          /* In / out */

  REAL *holelist;                        /* In / pointer to array copied out */
  int numberofholes;                                      /* In / copied out */

  REAL *regionlist;                      /* In / pointer to array copied out */
  int numberofregions;                                    /* In / copied out */

  int *edgelist;                                                 /* Out only */
  int *edgemarkerlist;            /* Not used with Voronoi diagram; out only */
  REAL *normlist;                /* Used only with Voronoi diagram; out only */
  int numberofedges;                                             /* Out only */
};

void triangulateioinit(struct triangulateio*);
void triangulateiodeinit(struct triangulateio*);
void triangulateioreport(struct triangulateio*, int, int, int, int, int, int);

/* The triangle data structure.  Each triangle contains three pointers to    */
/*   adjoining triangles, plus three pointers to vertex points, plus three   */
/*   pointers to shell edges (defined below; these pointers are usually      */
/*   `dummysh').  It may or may not also contain user-defined attributes     */
/*   and/or a floating-point "area constraint".  It may also contain extra   */
/*   pointers for nodes, when the user asks for high-order elements.         */
/*   Because the size and structure of a `triangle' is not decided until     */
/*   runtime, I haven't simply defined the type `triangle' to be a struct.   */

typedef REAL **triangle;            /* Really:  typedef triangle *triangle   */

/* An oriented triangle:  includes a pointer to a triangle and orientation.  */
/*   The orientation denotes an edge of the triangle.  Hence, there are      */
/*   three possible orientations.  By convention, each edge is always        */
/*   directed to point counterclockwise about the corresponding triangle.    */

struct triedge {
  triangle *tri;
  int orient;                                         /* Ranges from 0 to 2. */
};

/* The shell data structure.  Each shell edge contains two pointers to       */
/*   adjoining shell edges, plus two pointers to vertex points, plus two     */
/*   pointers to adjoining triangles, plus one shell marker.                 */

typedef REAL **shelle;                  /* Really:  typedef shelle *shelle   */

/* An oriented shell edge:  includes a pointer to a shell edge and an        */
/*   orientation.  The orientation denotes a side of the edge.  Hence, there */
/*   are two possible orientations.  By convention, the edge is always       */
/*   directed so that the "side" denoted is the right side of the edge.      */

struct edge {
  shelle *sh;
  int shorient;                                       /* Ranges from 0 to 1. */
};

/* The point data structure.  Each point is actually an array of REALs.      */
/*   The number of REALs is unknown until runtime.  An integer boundary      */
/*   marker, and sometimes a pointer to a triangle, is appended after the    */
/*   REALs.                                                                  */

typedef REAL *point;

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// class mesh2d                                                              //
//                                                                           //
// The class simply encapsulating the well-coded and well-performed 2D unst- //
// ructed mesh generator TRIANGLE's functions into a single calss so it can  //
// be called directly from my 3D mesh program.                               //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

class mesh2d {

  public:

    enum locateresult {INTRIANGLE, ONEDGE, ONVERTEX, OUTSIDE};
    enum insertsiteresult {SUCCESSFULPOINT, ENCROACHINGPOINT, VIOLATINGPOINT,
                           DUPLICATEPOINT};
    enum finddirectionresult {WITHIN, LEFTCOLLINEAR, RIGHTCOLLINEAR};

  public:

    memorypool triangles;
    memorypool shelles;
    memorypool points;
    memorypool viri;

    REAL xmin, xmax, ymin, ymax;
    REAL xminextreme;
    int inpoints, inelements, insegments, holes, regions;
    long edges, hullsize;
    int mesh_dim;
    int nextras, eextras;
    int triwords, shwords;
    int pointmarkindex, point2triindex;
    int highorderindex, elemattribindex, areaboundindex;
    int checksegments;
    int readnodefile;
    long samples;
    unsigned long randomseed;
    long incirclecount, counterclockcount;
    long circumcentercount;

    int poly, refine, quality, vararea, fixedarea, regionattrib, convex;
    int firstnumber;
    int edgesout, voronoi, neighbors, geomview;
    int nopolywritten, nonodewritten, noelewritten, noiterationnum;
    int nobound, noholes, nobisect, noexact;
    int incremental, sweepline, dwyer;
    int splitseg, steiner, steinerleft;
    int docheck, quiet, verbose;
    int useshelles, order;
    int restartsymbol;
    REAL minangle, goodangle;
    REAL maxarea;

    point infpoint1, infpoint2, infpoint3;

    triangle *dummytri;
    triangle *dummytribase;
    shelle *dummysh;
    shelle *dummyshbase;

    struct triedge recenttri;

    static int plus1mod3[3];
    static int minus1mod3[3];

  public:

    // User interaction routines
    void syntax();
    void info();
    void internalerror();
    void parsecommandline(int, char**, int);

    // Debugging routines
    void printtriangle(struct triedge*);
    void printshelle(struct edge*);

    // Memory management routines
    void dummyinit(int, int);
    void initializepointpool();
    void initializetrisegpools();
    void triangledealloc(triangle*);
    triangle *triangletraverse();
    void shelledealloc(shelle*);
    shelle *shelletraverse();
    void pointdealloc(point);
    point pointtraverse();
    point getpoint(int number);

    // Constructors
    void maketriangle(struct triedge*);
    void makeshelle(struct edge*);

    void triangleinit();
    void triangledeinit();
    void trianglerestart();

    // Geometric predicates
    REAL counterclockwise(point, point, point);
    REAL iincircle(point, point, point, point);

    // Point location routines
    unsigned long randomnation(unsigned int);
    void makepointmap();
    enum locateresult preciselocate(point, struct triedge*);
    enum locateresult locate(point, struct triedge*);

    // Mesh transformation routines
    void insertshelle(struct triedge*, int);
    void flip(struct triedge*);
    enum insertsiteresult insertsite(point, struct triedge*, struct edge*,
                                     int, int);

    // Divide-and-conquer Delaunay triangulation
    void pointsort(point*, int);
    void pointmedian(point*, int, int, int);
    void alternateaxes(point*, int, int);
    void mergehulls(struct triedge*, struct triedge*, struct triedge*,
                    struct triedge*, int);
    void divconqrecurse(point*, int, int, struct triedge*, struct triedge*);
    long removeghosts(struct triedge*);
    long divconqdelaunay();

    // General mesh construction routines
    long delaunay();

    // Segment (shell edge) insertion routines
    enum finddirectionresult finddirection(struct triedge*, point);
    void segmentintersection(struct triedge*, struct edge*, point);
    int scoutsegment(struct triedge*, point, int);
    void conformingedge(point, point, int);
    void delaunayfixup(struct triedge*, int);
    void constrainededge(struct triedge*, point, int);
    void insertsegment(point endpoint1, point endpoint2, int newmark);
    void markhull();
    int formskeleton(int*, int*, int);

    // Carving out holes and concavities routines
    void infecthull();
    void plague();
    void regionplague(REAL attribute, REAL area);
    void carveholes(REAL*, int, REAL*, int);

    // I/O routines
    void transfernodes(REAL*, REAL*, int*, int, int);
    void numbernodes();
    void writenodes(REAL**, REAL**, int**);
    void writeelements(int**, REAL**);
    void writepoly(int**, int**);
    void writeedges(int**, int**);
    void writeneighbors(int**);
    void writegid(int);

  public:

    mesh2d(char* triswtches) {
      triangleinit();
      parsecommandline(1, &triswtches, 1);
    }
    ~mesh2d() { triangledeinit(); }

    void triangulate(struct triangulateio *in, struct triangulateio *out,
                     struct triangulateio *vorout);
};

#endif // ifndef trilibH
