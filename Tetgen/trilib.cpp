///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// trilib.cpp    Implementation file for two-dimensional mesh generator.     //
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
// This file with it's couple file trilib.h are modified version of the      //
// triangle program of Jonathan Richard Shewchuk, which is public available  //
// from the following Web page with its license(see trilib.h):               //
//                                                                           //
//              http://www.cs.cmu.edu/~quake/triangle.html                   //
//                                                                           //
// Please see trilib.h for description of how to use this modified codes     //
// of triangle.                                                              //
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

#include "trilib.h"

/********* struct triangulateio routines begin here                  *********/
/**                                                                         **/
/**                                                                         **/

void triangulateioinit(struct triangulateio* io)
{
  io->pointlist = NULL;
  io->pointattributelist = NULL;
  io->pointmarkerlist = NULL;
  io->numberofpoints = 0;
  io->numberofpointattributes = 0;

  io->trianglelist = NULL;
  io->triangleattributelist = NULL;
  io->trianglearealist = NULL;
  io->neighborlist = NULL;
  io->numberoftriangles = 0;
  io->numberofcorners = 0;
  io->numberoftriangleattributes = 0;

  io->segmentlist = NULL;
  io->segmentmarkerlist = NULL;
  io->numberofsegments = 0;

  io->holelist = NULL;
  io->numberofholes = 0;

  io->regionlist = NULL;
  io->numberofregions = 0;

  io->edgelist = NULL;
  io->edgemarkerlist = NULL;
  io->normlist = NULL;
  io->numberofedges = 0;
}

void triangulateiodeinit(struct triangulateio* io)
{
  if (io->numberofpoints && io->pointlist) {
    delete [] io->pointlist;
    io->pointlist = NULL;
    io->numberofpoints = 0;
  }
  if (io->numberofpointattributes && io->pointattributelist) {
    delete [] io->pointattributelist;
    io->pointattributelist = NULL;
    io->numberofpointattributes = 0;
  }
  if (io->pointmarkerlist) {
    delete [] io->pointmarkerlist;
    io->pointmarkerlist = NULL;
  }

  if (io->numberoftriangles && io->trianglelist) {
    delete [] io->trianglelist;
    io->trianglelist = NULL;
    io->numberoftriangles = 0;
    io->numberofcorners = 0;
  }
  if (io->numberoftriangleattributes && io->triangleattributelist) {
    delete [] io->triangleattributelist;
    io->triangleattributelist = NULL;
    io->numberoftriangleattributes = 0;
  }
  if (io->trianglearealist) {
    delete [] io->trianglearealist;
    io->trianglearealist = NULL;
  }
  if (io->neighborlist) {
    delete [] io->neighborlist;
    io->neighborlist = NULL;
  }

  if (io->numberofsegments && io->segmentlist) {
    delete [] io->segmentlist;
    io->segmentlist = NULL;
    io->numberofsegments = 0;
  }
  if (io->segmentmarkerlist) {
    delete [] io->segmentmarkerlist;
    io->segmentmarkerlist = NULL;
  }

  if (io->numberofholes && io->holelist) {
    delete [] io->holelist;
    io->holelist = NULL;
    io->numberofholes = 0;
  }

  if (io->numberofregions && io->regionlist) {
    delete [] io->regionlist;
    io->regionlist = NULL;
    io->numberofregions = 0;
  }

  if (io->numberofedges && io->edgelist) {
    delete [] io->edgelist;
    io->edgelist = NULL;
    io->numberofedges = 0;
  }
  if (io->edgemarkerlist) {
    delete [] io->edgemarkerlist;
    io->edgemarkerlist = NULL;
  }
  if (io->normlist) {
    delete [] io->normlist;
    io->normlist = NULL;
  }
}

void triangulateioreport(struct triangulateio *io, int markers,
  int reporttriangles, int reportneighbors, int reportsegments,
  int reportedges, int reportnorms)
{
  int i, j;

  if (io->numberofpoints && io->pointlist)  {
    for (i = 0; i < io->numberofpoints; i++) {
      printf("Point %4d:", i + 1);
      for (j = 0; j < 2; j++) {
        printf("  %.6g", io->pointlist[i * 2 + j]);
      }
      if (io->numberofpointattributes > 0) {
        printf("   attributes");
      }
      for (j = 0; j < io->numberofpointattributes; j++) {
        printf("  %.6g",
               io->pointattributelist[i * io->numberofpointattributes + j]);
      }
      if (markers) {
        printf("   marker %d\n", io->pointmarkerlist[i]);
      } else {
        printf("\n");
      }
    }
    printf("\n");
  }

  if (reporttriangles || reportneighbors) {
    for (i = 0; i < io->numberoftriangles; i++) {
      if (reporttriangles) {
        printf("Triangle %4d points:", i + 1);
        for (j = 0; j < io->numberofcorners; j++) {
          printf("  %4d", io->trianglelist[i * io->numberofcorners + j] + 1);
        }
        if (io->numberoftriangleattributes > 0) {
          printf("   attributes");
        }
        for (j = 0; j < io->numberoftriangleattributes; j++) {
          printf("  %.6g", io->triangleattributelist[i *
                                         io->numberoftriangleattributes + j]);
        }
        printf("\n");
      }
      if (reportneighbors) {
        printf("Triangle %4d neighbors:", i + 1);
        for (j = 0; j < 3; j++) {
          if (io->neighborlist[i * 3 + j] < 0) {
            printf("  %4d", io->neighborlist[i * 3 + j]);
          } else {
            printf("  %4d", io->neighborlist[i * 3 + j] + 1);
          }
        }
        printf("\n");
      }
    }
    printf("\n");
  }

  if (reportsegments) {
    for (i = 0; i < io->numberofsegments; i++) {
      printf("Segment %4d points:", i + 1);
      for (j = 0; j < 2; j++) {
        printf("  %4d", io->segmentlist[i * 2 + j] + 1);
      }
      if (markers) {
        printf("   marker %d\n", io->segmentmarkerlist[i]);
      } else {
        printf("\n");
      }
    }
    printf("\n");
  }

  if (reportedges) {
    for (i = 0; i < io->numberofedges; i++) {
      printf("Edge %4d points:", i + 1);
      for (j = 0; j < 2; j++) {
        printf("  %4d", io->edgelist[i * 2 + j] + 1);
      }
      if (reportnorms && (io->edgelist[i * 2 + 1] == -1)) {
        for (j = 0; j < 2; j++) {
          printf("  %.6g", io->normlist[i * 2 + j]);
        }
      }
      if (markers) {
        printf("   marker %d\n", io->edgemarkerlist[i]);
      } else {
        printf("\n");
      }
    }
    printf("\n");
  }
}

/**                                                                         **/
/**                                                                         **/
/********* struct triangulateio routines end here                    *********/

/********* Mesh manipulation primitives begin here                   *********/
/**                                                                         **/
/**                                                                         **/

/* Fast lookup arrays to speed some of the mesh manipulation primitives.     */

int mesh2d::plus1mod3[3] = {1, 2, 0};
int mesh2d::minus1mod3[3] = {2, 0, 1};

/********* Primitives for triangles                                  *********/
/*                                                                           */
/*                                                                           */

/* decode() converts a pointer to an oriented triangle.  The orientation is  */
/*   extracted from the two least significant bits of the pointer.           */

#define decode(ptr, triedge)                                                  \
  (triedge).orient = (int) ((unsigned long) (ptr) & (unsigned long) 3l);      \
  (triedge).tri = (triangle *)                                                \
                  ((unsigned long) (ptr) ^ (unsigned long) (triedge).orient)

/* encode() compresses an oriented triangle into a single pointer.  It       */
/*   relies on the assumption that all triangles are aligned to four-byte    */
/*   boundaries, so the two least significant bits of (triedge).tri are zero.*/

#define encode(triedge)                                                       \
  (triangle) ((unsigned long) (triedge).tri | (unsigned long) (triedge).orient)

/* The following edge manipulation primitives are all described by Guibas    */
/*   and Stolfi.  However, they use an edge-based data structure, whereas I  */
/*   am using a triangle-based data structure.                               */

/* sym() finds the abutting triangle, on the same edge.  Note that the       */
/*   edge direction is necessarily reversed, because triangle/edge handles   */
/*   are always directed counterclockwise around the triangle.               */

#define sym(triedge1, triedge2)                                               \
  ptr = (triedge1).tri[(triedge1).orient];                                    \
  decode(ptr, triedge2);

#define symself(triedge)                                                      \
  ptr = (triedge).tri[(triedge).orient];                                      \
  decode(ptr, triedge);

/* lnext() finds the next edge (counterclockwise) of a triangle.             */

#define lnext(triedge1, triedge2)                                             \
  (triedge2).tri = (triedge1).tri;                                            \
  (triedge2).orient = plus1mod3[(triedge1).orient]

#define lnextself(triedge)                                                    \
  (triedge).orient = plus1mod3[(triedge).orient]

/* lprev() finds the previous edge (clockwise) of a triangle.                */

#define lprev(triedge1, triedge2)                                             \
  (triedge2).tri = (triedge1).tri;                                            \
  (triedge2).orient = minus1mod3[(triedge1).orient]

#define lprevself(triedge)                                                    \
  (triedge).orient = minus1mod3[(triedge).orient]

/* onext() spins counterclockwise around a point; that is, it finds the next */
/*   edge with the same origin in the counterclockwise direction.  This edge */
/*   will be part of a different triangle.                                   */

#define onext(triedge1, triedge2)                                             \
  lprev(triedge1, triedge2);                                                  \
  symself(triedge2);

#define onextself(triedge)                                                    \
  lprevself(triedge);                                                         \
  symself(triedge);

/* oprev() spins clockwise around a point; that is, it finds the next edge   */
/*   with the same origin in the clockwise direction.  This edge will be     */
/*   part of a different triangle.                                           */

#define oprev(triedge1, triedge2)                                             \
  sym(triedge1, triedge2);                                                    \
  lnextself(triedge2);

#define oprevself(triedge)                                                    \
  symself(triedge);                                                           \
  lnextself(triedge);

/* dnext() spins counterclockwise around a point; that is, it finds the next */
/*   edge with the same destination in the counterclockwise direction.  This */
/*   edge will be part of a different triangle.                              */

#define dnext(triedge1, triedge2)                                             \
  sym(triedge1, triedge2);                                                    \
  lprevself(triedge2);

#define dnextself(triedge)                                                    \
  symself(triedge);                                                           \
  lprevself(triedge);

/* dprev() spins clockwise around a point; that is, it finds the next edge   */
/*   with the same destination in the clockwise direction.  This edge will   */
/*   be part of a different triangle.                                        */

#define dprev(triedge1, triedge2)                                             \
  lnext(triedge1, triedge2);                                                  \
  symself(triedge2);

#define dprevself(triedge)                                                    \
  lnextself(triedge);                                                         \
  symself(triedge);

/* rnext() moves one edge counterclockwise about the adjacent triangle.      */
/*   (It's best understood by reading Guibas and Stolfi.  It involves        */
/*   changing triangles twice.)                                              */

#define rnext(triedge1, triedge2)                                             \
  sym(triedge1, triedge2);                                                    \
  lnextself(triedge2);                                                        \
  symself(triedge2);

#define rnextself(triedge)                                                    \
  symself(triedge);                                                           \
  lnextself(triedge);                                                         \
  symself(triedge);

/* rnext() moves one edge clockwise about the adjacent triangle.             */
/*   (It's best understood by reading Guibas and Stolfi.  It involves        */
/*   changing triangles twice.)                                              */

#define rprev(triedge1, triedge2)                                             \
  sym(triedge1, triedge2);                                                    \
  lprevself(triedge2);                                                        \
  symself(triedge2);

#define rprevself(triedge)                                                    \
  symself(triedge);                                                           \
  lprevself(triedge);                                                         \
  symself(triedge);

/* These primitives determine or set the origin, destination, or apex of a   */
/* triangle.                                                                 */

#define org(triedge, pointptr)                                                \
  pointptr = (point) (triedge).tri[plus1mod3[(triedge).orient] + 3]

#define dest(triedge, pointptr)                                               \
  pointptr = (point) (triedge).tri[minus1mod3[(triedge).orient] + 3]

#define apex(triedge, pointptr)                                               \
  pointptr = (point) (triedge).tri[(triedge).orient + 3]

#define setorg(triedge, pointptr)                                             \
  (triedge).tri[plus1mod3[(triedge).orient] + 3] = (triangle) pointptr

#define setdest(triedge, pointptr)                                            \
  (triedge).tri[minus1mod3[(triedge).orient] + 3] = (triangle) pointptr

#define setapex(triedge, pointptr)                                            \
  (triedge).tri[(triedge).orient + 3] = (triangle) pointptr

#define setvertices2null(triedge)                                             \
  (triedge).tri[3] = (triangle) NULL;                                         \
  (triedge).tri[4] = (triangle) NULL;                                         \
  (triedge).tri[5] = (triangle) NULL;

/* Bond two triangles together.                                              */

#define bond(triedge1, triedge2)                                              \
  (triedge1).tri[(triedge1).orient] = encode(triedge2);                       \
  (triedge2).tri[(triedge2).orient] = encode(triedge1)

/* Dissolve a bond (from one side).  Note that the other triangle will still */
/*   think it's connected to this triangle.  Usually, however, the other     */
/*   triangle is being deleted entirely, or bonded to another triangle, so   */
/*   it doesn't matter.                                                      */

#define dissolve(triedge)                                                     \
  (triedge).tri[(triedge).orient] = (triangle) dummytri

/* Copy a triangle/edge handle.                                              */

#define triedgecopy(triedge1, triedge2)                                       \
  (triedge2).tri = (triedge1).tri;                                            \
  (triedge2).orient = (triedge1).orient

/* Test for equality of triangle/edge handles.                               */

#define triedgeequal(triedge1, triedge2)                                      \
  (((triedge1).tri == (triedge2).tri) &&                                      \
   ((triedge1).orient == (triedge2).orient))

/* Primitives to infect or cure a triangle with the virus.  These rely on    */
/*   the assumption that all shell edges are aligned to four-byte boundaries.*/

#define infect(triedge)                                                       \
  (triedge).tri[6] = (triangle)                                               \
                     ((unsigned long) (triedge).tri[6] | (unsigned long) 2l)

#define uninfect(triedge)                                                     \
  (triedge).tri[6] = (triangle)                                               \
                     ((unsigned long) (triedge).tri[6] & ~ (unsigned long) 2l)

/* Test a triangle for viral infection.                                      */

#define infected(triedge)                                                     \
  (((unsigned long) (triedge).tri[6] & (unsigned long) 2l) != 0)

/* Check or set a triangle's attributes.                                     */

#define elemattribute(triedge, attnum)                                        \
  ((REAL *) (triedge).tri)[elemattribindex + (attnum)]

#define setelemattribute(triedge, attnum, value)                              \
  ((REAL *) (triedge).tri)[elemattribindex + (attnum)] = value

/* Check or set a triangle's maximum area bound.                             */

#define areabound(triedge)  ((REAL *) (triedge).tri)[areaboundindex]

#define setareabound(triedge, value)                                          \
  ((REAL *) (triedge).tri)[areaboundindex] = value

/********* Primitives for shell edges                                *********/
/*                                                                           */
/*                                                                           */

/* sdecode() converts a pointer to an oriented shell edge.  The orientation  */
/*   is extracted from the least significant bit of the pointer.  The two    */
/*   least significant bits (one for orientation, one for viral infection)   */
/*   are masked out to produce the real pointer.                             */

#define sdecode(sptr, edge)                                                   \
  (edge).shorient = (int) ((unsigned long) (sptr) & (unsigned long) 1l);      \
  (edge).sh = (shelle *)                                                      \
              ((unsigned long) (sptr) & ~ (unsigned long) 3l)

/* sencode() compresses an oriented shell edge into a single pointer.  It    */
/*   relies on the assumption that all shell edges are aligned to two-byte   */
/*   boundaries, so the least significant bit of (edge).sh is zero.          */

#define sencode(edge)                                                         \
  (shelle) ((unsigned long) (edge).sh | (unsigned long) (edge).shorient)

/* ssym() toggles the orientation of a shell edge.                           */

#define ssym(edge1, edge2)                                                    \
  (edge2).sh = (edge1).sh;                                                    \
  (edge2).shorient = 1 - (edge1).shorient

#define ssymself(edge)                                                        \
  (edge).shorient = 1 - (edge).shorient

/* spivot() finds the other shell edge (from the same segment) that shares   */
/*   the same origin.                                                        */

#define spivot(edge1, edge2)                                                  \
  sptr = (edge1).sh[(edge1).shorient];                                        \
  sdecode(sptr, edge2)

#define spivotself(edge)                                                      \
  sptr = (edge).sh[(edge).shorient];                                          \
  sdecode(sptr, edge)

/* snext() finds the next shell edge (from the same segment) in sequence;    */
/*   one whose origin is the input shell edge's destination.                 */

#define snext(edge1, edge2)                                                   \
  sptr = (edge1).sh[1 - (edge1).shorient];                                    \
  sdecode(sptr, edge2)

#define snextself(edge)                                                       \
  sptr = (edge).sh[1 - (edge).shorient];                                      \
  sdecode(sptr, edge)

/* These primitives determine or set the origin or destination of a shell    */
/*   edge.                                                                   */

#define sorg(edge, pointptr)                                                  \
  pointptr = (point) (edge).sh[2 + (edge).shorient]

#define sdest(edge, pointptr)                                                 \
  pointptr = (point) (edge).sh[3 - (edge).shorient]

#define setsorg(edge, pointptr)                                               \
  (edge).sh[2 + (edge).shorient] = (shelle) pointptr

#define setsdest(edge, pointptr)                                              \
  (edge).sh[3 - (edge).shorient] = (shelle) pointptr

/* These primitives read or set a shell marker.  Shell markers are used to   */
/*   hold user boundary information.                                         */

#define mark(edge)  (* (int *) ((edge).sh + 6))

#define setmark(edge, value)                                                  \
  * (int *) ((edge).sh + 6) = value

/* Bond two shell edges together.                                            */

#define sbond(edge1, edge2)                                                   \
  (edge1).sh[(edge1).shorient] = sencode(edge2);                              \
  (edge2).sh[(edge2).shorient] = sencode(edge1)

/* Dissolve a shell edge bond (from one side).  Note that the other shell    */
/*   edge will still think it's connected to this shell edge.                */

#define sdissolve(edge)                                                       \
  (edge).sh[(edge).shorient] = (shelle) dummysh

/* Copy a shell edge.                                                        */

#define shellecopy(edge1, edge2)                                              \
  (edge2).sh = (edge1).sh;                                                    \
  (edge2).shorient = (edge1).shorient

/* Test for equality of shell edges.                                         */

#define shelleequal(edge1, edge2)                                             \
  (((edge1).sh == (edge2).sh) &&                                              \
   ((edge1).shorient == (edge2).shorient))

/********* Primitives for interacting triangles and shell edges      *********/
/*                                                                           */
/*                                                                           */

/* tspivot() finds a shell edge abutting a triangle.                         */

#define tspivot(triedge, edge)                                                \
  sptr = (shelle) (triedge).tri[6 + (triedge).orient];                        \
  sdecode(sptr, edge)

/* stpivot() finds a triangle abutting a shell edge.  It requires that the   */
/*   variable `ptr' of type `triangle' be defined.                           */

#define stpivot(edge, triedge)                                                \
  ptr = (triangle) (edge).sh[4 + (edge).shorient];                            \
  decode(ptr, triedge)

/* Bond a triangle to a shell edge.                                          */

#define tsbond(triedge, edge)                                                 \
  (triedge).tri[6 + (triedge).orient] = (triangle) sencode(edge);             \
  (edge).sh[4 + (edge).shorient] = (shelle) encode(triedge)

/* Dissolve a bond (from the triangle side).                                 */

#define tsdissolve(triedge)                                                   \
  (triedge).tri[6 + (triedge).orient] = (triangle) dummysh

/* Dissolve a bond (from the shell edge side).                               */

#define stdissolve(edge)                                                      \
  (edge).sh[4 + (edge).shorient] = (shelle) dummytri

/********* Primitives for points                                     *********/
/*                                                                           */
/*                                                                           */

#define pointmark(pt)  ((int *) (pt))[pointmarkindex]

#define setpointmark(pt, value)                                               \
  ((int *) (pt))[pointmarkindex] = value

#define point2tri(pt)  ((triangle *) (pt))[point2triindex]

#define setpoint2tri(pt, value)                                               \
  ((triangle *) (pt))[point2triindex] = value

/**                                                                         **/
/**                                                                         **/
/********* Mesh manipulation primitives end here                     *********/

/********* User interaction routines begin here                      *********/
/**                                                                         **/
/**                                                                         **/

/*****************************************************************************/
/*                                                                           */
/*  syntax()   Print list of command line switches.                          */
/*                                                                           */
/*****************************************************************************/

void mesh2d::syntax()
{
  printf("triangle [-paAcevngBPNEIOXzo_YS__iFlsCQVh] input_file\n");
  exit(0);
}

/*****************************************************************************/
/*                                                                           */
/*  info()   Print out complete instructions.                                */
/*                                                                           */
/*****************************************************************************/

void mesh2d::info()
{
  printf("Triangle\n");
  printf(
"A Two-Dimensional Quality Mesh Generator and Delaunay Triangulator.\n");
  printf("Version 1.3\n\n");
  printf(
"Copyright 1996 Jonathan Richard Shewchuk  (bugs/comments to jrs@cs.cmu.edu)\n"
);
  printf("School of Computer Science / Carnegie Mellon University\n");
  printf("5000 Forbes Avenue / Pittsburgh, Pennsylvania  15213-3891\n");
  printf(
"Created as part of the Archimedes project (tools for parallel FEM).\n");
  printf(
"Supported in part by NSF Grant CMS-9318163 and an NSERC 1967 Scholarship.\n");
  printf("There is no warranty whatsoever.  Use at your own risk.\n");
}

/*****************************************************************************/
/*                                                                           */
/*  internalerror()   Ask the user to send me the defective product.  Exit.  */
/*                                                                           */
/*****************************************************************************/

void mesh2d::internalerror()
{
  printf("  Please report this bug to sihang@weboo.com\n");
  printf("  Include the message above, your input data set, and the exact\n");
  printf("    command line you used to run Triangle.\n");
  exit(1);
}

/*****************************************************************************/
/*                                                                           */
/*  parsecommandline()   Read the command line, identify switches, and set   */
/*                       up options and file names.                          */
/*                                                                           */
/*  The effects of this routine are felt entirely through global variables.  */
/*                                                                           */
/*****************************************************************************/

void mesh2d::parsecommandline(int argc, char **argv, int libflag)
{
  int startindex;
  char startchar;
  int increment;
  int meshnumber;
  int i, j, k;
  char workstring[FILENAMESIZE];

  poly = refine = quality = vararea = fixedarea = regionattrib = convex = 0;
  firstnumber = 1;
  edgesout = voronoi = neighbors = geomview = 0;
  nobound = nopolywritten = nonodewritten = noelewritten = noiterationnum = 0;
  noholes = noexact = 0;
  incremental = sweepline = 0;
  dwyer = 1;
  splitseg = 0;
  docheck = 0;
  nobisect = 0;
  steiner = -1;
  order = 1;
  minangle = 0.0;
  maxarea = -1.0;
  quiet = verbose = 0;

  if (libflag) {
    startindex = 0;
  } else {
    startindex = 1;
  }

  for (i = startindex; i < argc; i++) {
    if (libflag) {
      startchar = '-';
    } else {
      startchar = argv[i][0];
    }
    if (startchar == '-') {
      for (j = startindex; argv[i][j] != '\0'; j++) {
        if (argv[i][j] == 'p') {
          poly = 1;
        }
        if (argv[i][j] == 'r') {
          refine = 1;
	      }
        if (argv[i][j] == 'q') {
          quality = 1;
          if (((argv[i][j + 1] >= '0') && (argv[i][j + 1] <= '9')) ||
              (argv[i][j + 1] == '.')) {
            k = 0;
            while (((argv[i][j + 1] >= '0') && (argv[i][j + 1] <= '9')) ||
                   (argv[i][j + 1] == '.')) {
              j++;
              workstring[k] = argv[i][j];
              k++;
            }
            workstring[k] = '\0';
            minangle = (REAL) strtod(workstring, (char **) NULL);
          } else {
            minangle = 20.0;
          }
        }
        if (argv[i][j] == 'a') {
          quality = 1;
          if (((argv[i][j + 1] >= '0') && (argv[i][j + 1] <= '9')) ||
              (argv[i][j + 1] == '.')) {
            fixedarea = 1;
            k = 0;
            while (((argv[i][j + 1] >= '0') && (argv[i][j + 1] <= '9')) ||
                   (argv[i][j + 1] == '.')) {
              j++;
              workstring[k] = argv[i][j];
              k++;
            }
            workstring[k] = '\0';
            maxarea = (REAL) strtod(workstring, (char **) NULL);
            if (maxarea <= 0.0) {
              printf("Error:  Maximum area must be greater than zero.\n");
              exit(1);
            }
          } else {
            vararea = 1;
          }
        }
        if (argv[i][j] == 'A') {
          regionattrib = 1;
        }
        if (argv[i][j] == 'c') {
          convex = 1;
        }
        if (argv[i][j] == 'z') {
          firstnumber = 0;
        }
        if (argv[i][j] == 'e') {
          edgesout = 1;
        }
        if (argv[i][j] == 'v') {
          voronoi = 1;
        }
        if (argv[i][j] == 'n') {
          neighbors = 1;
        }
        if (argv[i][j] == 'g') {
          geomview = 1;
        }
        if (argv[i][j] == 'B') {
          nobound = 1;
        }
        if (argv[i][j] == 'P') {
          nopolywritten = 1;
        }
        if (argv[i][j] == 'N') {
          nonodewritten = 1;
        }
        if (argv[i][j] == 'E') {
          noelewritten = 1;
        }
        if (argv[i][j] == 'I') {
          noiterationnum = 1;
        }
        if (argv[i][j] == 'O') {
          noholes = 1;
        }
        if (argv[i][j] == 'X') {
          noexact = 1;
        }
        if (argv[i][j] == 'o') {
          if (argv[i][j + 1] == '2') {
            j++;
            order = 2;
          }
        }
        if (argv[i][j] == 'Y') {
          nobisect++;
        }
        if (argv[i][j] == 'S') {
          steiner = 0;
          while ((argv[i][j + 1] >= '0') && (argv[i][j + 1] <= '9')) {
            j++;
            steiner = steiner * 10 + (int) (argv[i][j] - '0');
          }
        }
        if (argv[i][j] == 'i') {
          incremental = 1;
        }
        if (argv[i][j] == 'F') {
          sweepline = 1;
        }
        if (argv[i][j] == 'l') {
          dwyer = 0;
        }
        if (argv[i][j] == 's') {
          splitseg = 1;
        }
        if (argv[i][j] == 'C') {
          docheck = 1;
        }
        if (argv[i][j] == 'Q') {
          quiet = 1;
        }
        if (argv[i][j] == 'V') {
          verbose++;
        }
        if ((argv[i][j] == 'h') || (argv[i][j] == 'H') ||
            (argv[i][j] == '?')) {
          info();
        }
      }
    }
  }

  steinerleft = steiner;
  useshelles = poly || refine || quality || convex;
  // Be careful not to add an extra attribute to each element unless the
  //   input supports it (PSLG in, but not refining a preexisting mesh).
  if (refine || !poly) {
    regionattrib = 0;
  }
}

/**                                                                         **/
/**                                                                         **/
/********* User interaction routines begin here                      *********/

/********* Debugging routines begin here                             *********/
/**                                                                         **/
/**                                                                         **/

/*****************************************************************************/
/*                                                                           */
/*  printtriangle()   Print out the details of a triangle/edge handle.       */
/*                                                                           */
/*  I originally wrote this procedure to simplify debugging; it can be       */
/*  called directly from the debugger, and presents information about a      */
/*  triangle/edge handle in digestible form.  It's also used when the        */
/*  highest level of verbosity (`-VVV') is specified.                        */
/*                                                                           */
/*****************************************************************************/

void mesh2d::printtriangle(struct triedge *t)
{
  struct triedge printtri;
  struct edge printsh;
  point printpoint;

  printf("triangle x%lx with orientation %d:\n", (unsigned long) t->tri,
         t->orient);
  decode(t->tri[0], printtri);
  if (printtri.tri == dummytri) {
    printf("    [0] = Outer space\n");
  } else {
    printf("    [0] = x%lx  %d\n", (unsigned long) printtri.tri,
           printtri.orient);
  }
  decode(t->tri[1], printtri);
  if (printtri.tri == dummytri) {
    printf("    [1] = Outer space\n");
  } else {
    printf("    [1] = x%lx  %d\n", (unsigned long) printtri.tri,
           printtri.orient);
  }
  decode(t->tri[2], printtri);
  if (printtri.tri == dummytri) {
    printf("    [2] = Outer space\n");
  } else {
    printf("    [2] = x%lx  %d\n", (unsigned long) printtri.tri,
           printtri.orient);
  }
  org(*t, printpoint);
  if (printpoint == (point) NULL)
    printf("    Origin[%d] = NULL\n", (t->orient + 1) % 3 + 3);
  else
    printf("    Origin[%d] = x%lx  (%.12g, %.12g)\n",
           (t->orient + 1) % 3 + 3, (unsigned long) printpoint,
           printpoint[0], printpoint[1]);
  dest(*t, printpoint);
  if (printpoint == (point) NULL)
    printf("    Dest  [%d] = NULL\n", (t->orient + 2) % 3 + 3);
  else
    printf("    Dest  [%d] = x%lx  (%.12g, %.12g)\n",
           (t->orient + 2) % 3 + 3, (unsigned long) printpoint,
           printpoint[0], printpoint[1]);
  apex(*t, printpoint);
  if (printpoint == (point) NULL)
    printf("    Apex  [%d] = NULL\n", t->orient + 3);
  else
    printf("    Apex  [%d] = x%lx  (%.12g, %.12g)\n",
           t->orient + 3, (unsigned long) printpoint,
           printpoint[0], printpoint[1]);
  if (useshelles) {
    sdecode(t->tri[6], printsh);
    if (printsh.sh != dummysh) {
      printf("    [6] = x%lx  %d\n", (unsigned long) printsh.sh,
             printsh.shorient);
    }
    sdecode(t->tri[7], printsh);
    if (printsh.sh != dummysh) {
      printf("    [7] = x%lx  %d\n", (unsigned long) printsh.sh,
             printsh.shorient);
    }
    sdecode(t->tri[8], printsh);
    if (printsh.sh != dummysh) {
      printf("    [8] = x%lx  %d\n", (unsigned long) printsh.sh,
             printsh.shorient);
    }
  }
  if (vararea) {
    printf("    Area constraint:  %.4g\n", areabound(*t));
  }
}

/*****************************************************************************/
/*                                                                           */
/*  printshelle()   Print out the details of a shell edge handle.            */
/*                                                                           */
/*  I originally wrote this procedure to simplify debugging; it can be       */
/*  called directly from the debugger, and presents information about a      */
/*  shell edge handle in digestible form.  It's also used when the highest   */
/*  level of verbosity (`-VVV') is specified.                                */
/*                                                                           */
/*****************************************************************************/

void mesh2d::printshelle(struct edge *s)
{
  struct edge printsh;
  struct triedge printtri;
  point printpoint;

  printf("shell edge x%lx with orientation %d and mark %d:\n",
         (unsigned long) s->sh, s->shorient, mark(*s));
  sdecode(s->sh[0], printsh);
  if (printsh.sh == dummysh) {
    printf("    [0] = No shell\n");
  } else {
    printf("    [0] = x%lx  %d\n", (unsigned long) printsh.sh,
           printsh.shorient);
  }
  sdecode(s->sh[1], printsh);
  if (printsh.sh == dummysh) {
    printf("    [1] = No shell\n");
  } else {
    printf("    [1] = x%lx  %d\n", (unsigned long) printsh.sh,
           printsh.shorient);
  }
  sorg(*s, printpoint);
  if (printpoint == (point) NULL)
    printf("    Origin[%d] = NULL\n", 2 + s->shorient);
  else
    printf("    Origin[%d] = x%lx  (%.12g, %.12g)\n",
           2 + s->shorient, (unsigned long) printpoint,
           printpoint[0], printpoint[1]);
  sdest(*s, printpoint);
  if (printpoint == (point) NULL)
    printf("    Dest  [%d] = NULL\n", 3 - s->shorient);
  else
    printf("    Dest  [%d] = x%lx  (%.12g, %.12g)\n",
           3 - s->shorient, (unsigned long) printpoint,
           printpoint[0], printpoint[1]);
  decode(s->sh[4], printtri);
  if (printtri.tri == dummytri) {
    printf("    [4] = Outer space\n");
  } else {
    printf("    [4] = x%lx  %d\n", (unsigned long) printtri.tri,
           printtri.orient);
  }
  decode(s->sh[5], printtri);
  if (printtri.tri == dummytri) {
    printf("    [5] = Outer space\n");
  } else {
    printf("    [5] = x%lx  %d\n", (unsigned long) printtri.tri,
           printtri.orient);
  }
}

/**                                                                         **/
/**                                                                         **/
/********* Debugging routines end here                               *********/

/********* Memory management routines begin here                     *********/
/**                                                                         **/
/**                                                                         **/

/*****************************************************************************/
/*                                                                           */
/*  dummyinit()   Initialize the triangle that fills "outer space" and the   */
/*                omnipresent shell edge.                                    */
/*                                                                           */
/*  The triangle that fills "outer space", called `dummytri', is pointed to  */
/*  by every triangle and shell edge on a boundary (be it outer or inner) of */
/*  the triangulation.  Also, `dummytri' points to one of the triangles on   */
/*  the convex hull (until the holes and concavities are carved), making it  */
/*  possible to find a starting triangle for point location.                 */
/*                                                                           */
/*  The omnipresent shell edge, `dummysh', is pointed to by every triangle   */
/*  or shell edge that doesn't have a full complement of real shell edges    */
/*  to point to.                                                             */
/*                                                                           */
/*****************************************************************************/

void mesh2d::dummyinit(int trianglewords, int shellewords)
{
  unsigned long alignptr;

  /* `triwords' and `shwords' are used by the mesh manipulation primitives */
  /*   to extract orientations of triangles and shell edges from pointers. */
  triwords = trianglewords;       /* Initialize `triwords' once and for all. */
  shwords = shellewords;           /* Initialize `shwords' once and for all. */

  /* Set up `dummytri', the `triangle' that occupies "outer space". */
  dummytribase = (triangle *) new BYTE[triwords * sizeof(triangle)
                                       + triangles.alignbytes];
  if (dummytribase == (triangle *) NULL) {
    printf("Error:  Out of memory.\n");
    exit(1);
  }
  /* Align `dummytri' on a `triangles.alignbytes'-byte boundary. */
  alignptr = (unsigned long) dummytribase;
  dummytri = (triangle *)
    (alignptr + (unsigned long) triangles.alignbytes
     - (alignptr % (unsigned long) triangles.alignbytes));
  /* Initialize the three adjoining triangles to be "outer space".  These  */
  /*   will eventually be changed by various bonding operations, but their */
  /*   values don't really matter, as long as they can legally be          */
  /*   dereferenced.                                                       */
  dummytri[0] = (triangle) dummytri;
  dummytri[1] = (triangle) dummytri;
  dummytri[2] = (triangle) dummytri;
  /* Three NULL vertex points. */
  dummytri[3] = (triangle) NULL;
  dummytri[4] = (triangle) NULL;
  dummytri[5] = (triangle) NULL;

  if (useshelles) {
    /* Set up `dummysh', the omnipresent "shell edge" pointed to by any      */
    /*   triangle side or shell edge end that isn't attached to a real shell */
    /*   edge.                                                               */
    dummyshbase = (shelle *) new BYTE[shwords * sizeof(shelle)
                                      + shelles.alignbytes];
    if (dummyshbase == (shelle *) NULL) {
      printf("Error:  Out of memory.\n");
      exit(1);
    }
    /* Align `dummysh' on a `shelles.alignbytes'-byte boundary. */
    alignptr = (unsigned long) dummyshbase;
    dummysh = (shelle *)
      (alignptr + (unsigned long) shelles.alignbytes
       - (alignptr % (unsigned long) shelles.alignbytes));
    /* Initialize the two adjoining shell edges to be the omnipresent shell */
    /*   edge.  These will eventually be changed by various bonding         */
    /*   operations, but their values don't really matter, as long as they  */
    /*   can legally be dereferenced.                                       */
    dummysh[0] = (shelle) dummysh;
    dummysh[1] = (shelle) dummysh;
    /* Two NULL vertex points. */
    dummysh[2] = (shelle) NULL;
    dummysh[3] = (shelle) NULL;
    /* Initialize the two adjoining triangles to be "outer space". */
    dummysh[4] = (shelle) dummytri;
    dummysh[5] = (shelle) dummytri;
    /* Set the boundary marker to zero. */
    * (int *) (dummysh + 6) = 0;

    /* Initialize the three adjoining shell edges of `dummytri' to be */
    /*   the omnipresent shell edge.                                  */
    dummytri[6] = (triangle) dummysh;
    dummytri[7] = (triangle) dummysh;
    dummytri[8] = (triangle) dummysh;
  }
}

/*****************************************************************************/
/*                                                                           */
/*  initializepointpool()   Calculate the size of the point data structure   */
/*                          and initialize its memory pool.                  */
/*                                                                           */
/*  This routine also computes the `pointmarkindex' and `point2triindex'     */
/*  indices used to find values within each point.                           */
/*                                                                           */
/*****************************************************************************/

void mesh2d::initializepointpool()
{
  int pointsize;

  /* The index within each point at which the boundary marker is found.  */
  /*   Ensure the point marker is aligned to a sizeof(int)-byte address. */
  pointmarkindex = ((mesh_dim + nextras) * sizeof(REAL) + sizeof(int) - 1)
                 / sizeof(int);
  pointsize = (pointmarkindex + 1) * sizeof(int);
  if (poly) {
    /* The index within each point at which a triangle pointer is found.   */
    /*   Ensure the pointer is aligned to a sizeof(triangle)-byte address. */
    point2triindex = (pointsize + sizeof(triangle) - 1) / sizeof(triangle);
    pointsize = (point2triindex + 1) * sizeof(triangle);
  }
  /* Initialize the pool of points. */
  points.init(pointsize, POINTPERBLOCK,
           (sizeof(REAL) >= sizeof(triangle)) ? FLOATINGPOINT : POINTER, 0);
}

/*****************************************************************************/
/*                                                                           */
/*  initializetrisegpools()   Calculate the sizes of the triangle and shell  */
/*                            edge data structures and initialize their      */
/*                            memory pools.                                  */
/*                                                                           */
/*  This routine also computes the `highorderindex', `elemattribindex', and  */
/*  `areaboundindex' indices used to find values within each triangle.       */
/*                                                                           */
/*****************************************************************************/

void mesh2d::initializetrisegpools()
{
  int trisize;

  /* The index within each triangle at which the extra nodes (above three)  */
  /*   associated with high order elements are found.  There are three      */
  /*   pointers to other triangles, three pointers to corners, and possibly */
  /*   three pointers to shell edges before the extra nodes.                */
  highorderindex = 6 + (useshelles * 3);
  /* The number of bytes occupied by a triangle. */
  trisize = ((order + 1) * (order + 2) / 2 + (highorderindex - 3)) *
            sizeof(triangle);
  /* The index within each triangle at which its attributes are found, */
  /*   where the index is measured in REALs.                           */
  elemattribindex = (trisize + sizeof(REAL) - 1) / sizeof(REAL);
  /* The index within each triangle at which the maximum area constraint  */
  /*   is found, where the index is measured in REALs.  Note that if the  */
  /*   `regionattrib' flag is set, an additional attribute will be added. */
  areaboundindex = elemattribindex + eextras + regionattrib;
  /* If triangle attributes or an area bound are needed, increase the number */
  /*   of bytes occupied by a triangle.                                      */
  if (vararea) {
    trisize = (areaboundindex + 1) * sizeof(REAL);
  } else if (eextras + regionattrib > 0) {
    trisize = areaboundindex * sizeof(REAL);
  }
  /* If a Voronoi diagram or triangle neighbor graph is requested, make    */
  /*   sure there's room to store an integer index in each triangle.  This */
  /*   integer index can occupy the same space as the shell edges or       */
  /*   attributes or area constraint or extra nodes.                       */
  if ((voronoi || neighbors) &&
      (trisize < 6 * sizeof(triangle) + sizeof(int))) {
    trisize = 6 * sizeof(triangle) + sizeof(int);
  }
  /* Having determined the memory size of a triangle, initialize the pool. */
  triangles.init(trisize, TRIPERBLOCK, POINTER, 4);

  if (useshelles) {
    /* Initialize the pool of shell edges. */
    shelles.init(6 * sizeof(triangle) + sizeof(int), SHELLEPERBLOCK,
                 POINTER, 4);

    /* Initialize the "outer space" triangle and omnipresent shell edge. */
    dummyinit(triangles.itemwords, shelles.itemwords);
  } else {
    /* Initialize the "outer space" triangle. */
    dummyinit(triangles.itemwords, 0);
  }
}

/*****************************************************************************/
/*                                                                           */
/*  triangledealloc()   Deallocate space for a triangle, marking it dead.    */
/*                                                                           */
/*****************************************************************************/

void mesh2d::triangledealloc(triangle *dyingtriangle)
{
  /* Set triangle's vertices to NULL.  This makes it possible to        */
  /*   detect dead triangles when traversing the list of all triangles. */
  dyingtriangle[3] = (triangle) NULL;
  dyingtriangle[4] = (triangle) NULL;
  dyingtriangle[5] = (triangle) NULL;
  triangles.dealloc(dyingtriangle);
}

/*****************************************************************************/
/*                                                                           */
/*  triangletraverse()   Traverse the triangles, skipping dead ones.         */
/*                                                                           */
/*****************************************************************************/

triangle* mesh2d::triangletraverse()
{
  triangle *newtriangle;

  do {
    newtriangle = (triangle *) triangles.traverse();
    if (newtriangle == (triangle *) NULL) {
      return (triangle *) NULL;
    }
  } while (newtriangle[3] == (triangle) NULL);            /* Skip dead ones. */
  return newtriangle;
}

/*****************************************************************************/
/*                                                                           */
/*  shelledealloc()   Deallocate space for a shell edge, marking it dead.    */
/*                                                                           */
/*****************************************************************************/

void mesh2d::shelledealloc(shelle *dyingshelle)
{
  /* Set shell edge's vertices to NULL.  This makes it possible to */
  /*   detect dead shells when traversing the list of all shells.  */
  dyingshelle[2] = (shelle) NULL;
  dyingshelle[3] = (shelle) NULL;
  shelles.dealloc(dyingshelle);
}

/*****************************************************************************/
/*                                                                           */
/*  shelletraverse()   Traverse the shell edges, skipping dead ones.         */
/*                                                                           */
/*****************************************************************************/

shelle* mesh2d::shelletraverse()
{
  shelle *newshelle;

  do {
    newshelle = (shelle *) shelles.traverse();
    if (newshelle == (shelle *) NULL) {
      return (shelle *) NULL;
    }
  } while (newshelle[2] == (shelle) NULL);                /* Skip dead ones. */
  return newshelle;
}

/*****************************************************************************/
/*                                                                           */
/*  pointdealloc()   Deallocate space for a point, marking it dead.          */
/*                                                                           */
/*****************************************************************************/

void mesh2d::pointdealloc(point dyingpoint)
{
  /* Mark the point as dead.  This makes it possible to detect dead points */
  /*   when traversing the list of all points.                             */
  setpointmark(dyingpoint, DEADPOINT);
  points.dealloc(dyingpoint);
}

/*****************************************************************************/
/*                                                                           */
/*  pointtraverse()   Traverse the points, skipping dead ones.               */
/*                                                                           */
/*****************************************************************************/

point mesh2d::pointtraverse()
{
  point newpoint;

  do {
    newpoint = (point) points.traverse();
    if (newpoint == (point) NULL) {
      return (point) NULL;
    }
  } while (pointmark(newpoint) == DEADPOINT);             /* Skip dead ones. */
  return newpoint;
}

/*****************************************************************************/
/*                                                                           */
/*  getpoint()   Get a specific point, by number, from the list.             */
/*                                                                           */
/*  The first point is number 'firstnumber'.                                 */
/*                                                                           */
/*  Note that this takes O(n) time (with a small constant, if POINTPERBLOCK  */
/*  is large).  I don't care to take the trouble to make it work in constant */
/*  time.                                                                    */
/*                                                                           */
/*****************************************************************************/

point mesh2d::getpoint(int number)
{
  void **getblock;
  point foundpoint;
  unsigned long alignptr;
  int current;

  getblock = points.firstblock;
  current = firstnumber;
  /* Find the right block. */
  while (current + points.itemsperblock <= number) {
    getblock = (void **) *getblock;
    current += points.itemsperblock;
  }
  /* Now find the right point. */
  alignptr = (unsigned long) (getblock + 1);
  foundpoint = (point) (alignptr + (unsigned long) points.alignbytes
                        - (alignptr % (unsigned long) points.alignbytes));
  while (current < number) {
    foundpoint += points.itemwords;
    current++;
  }
  return foundpoint;
}

/*****************************************************************************/
/*                                                                           */
/*  triangledeinit()   Free all remaining allocated memory.                  */
/*                                                                           */
/*****************************************************************************/

void mesh2d::triangledeinit()
{
  triangles.deinit();
  if (dummytribase) delete [] dummytribase;
  if (useshelles) {
    shelles.deinit();
    if (dummyshbase) delete [] dummyshbase;
  }
  points.deinit();
}

/**                                                                         **/
/**                                                                         **/
/********* Memory management routines end here                       *********/

/********* Constructors begin here                                   *********/
/**                                                                         **/
/**                                                                         **/

/*****************************************************************************/
/*                                                                           */
/*  maketriangle()   Create a new triangle with orientation zero.            */
/*                                                                           */
/*****************************************************************************/

void mesh2d::maketriangle(struct triedge *newtriedge)
{
  int i;

  newtriedge->tri = (triangle *) triangles.alloc();
  /* Initialize the three adjoining triangles to be "outer space". */
  newtriedge->tri[0] = (triangle) dummytri;
  newtriedge->tri[1] = (triangle) dummytri;
  newtriedge->tri[2] = (triangle) dummytri;
  /* Three NULL vertex points. */
  newtriedge->tri[3] = (triangle) NULL;
  newtriedge->tri[4] = (triangle) NULL;
  newtriedge->tri[5] = (triangle) NULL;
  /* Initialize the three adjoining shell edges to be the omnipresent */
  /*   shell edge.                                                    */
  if (useshelles) {
    newtriedge->tri[6] = (triangle) dummysh;
    newtriedge->tri[7] = (triangle) dummysh;
    newtriedge->tri[8] = (triangle) dummysh;
  }
  for (i = 0; i < eextras; i++) {
    setelemattribute(*newtriedge, i, 0.0);
  }
  if (vararea) {
    setareabound(*newtriedge, -1.0);
  }

  newtriedge->orient = 0;
}

/*****************************************************************************/
/*                                                                           */
/*  makeshelle()   Create a new shell edge with orientation zero.            */
/*                                                                           */
/*****************************************************************************/

void mesh2d::makeshelle(struct edge *newedge)
{
  newedge->sh = (shelle *) shelles.alloc();
  /* Initialize the two adjoining shell edges to be the omnipresent */
  /*   shell edge.                                                  */
  newedge->sh[0] = (shelle) dummysh;
  newedge->sh[1] = (shelle) dummysh;
  /* Two NULL vertex points. */
  newedge->sh[2] = (shelle) NULL;
  newedge->sh[3] = (shelle) NULL;
  /* Initialize the two adjoining triangles to be "outer space". */
  newedge->sh[4] = (shelle) dummytri;
  newedge->sh[5] = (shelle) dummytri;
  /* Set the boundary marker to zero. */
  setmark(*newedge, 0);

  newedge->shorient = 0;
}

/**                                                                         **/
/**                                                                         **/
/********* Constructors end here                                     *********/

/********* Determinant evaluation routines begin here                *********/
/**                                                                         **/
/**                                                                         **/

/* This routines were move to "predicate.cpp" file                           */

/**                                                                         **/
/**                                                                         **/
/********* Determinant evaluation routines end here                  *********/

/*****************************************************************************/
/*                                                                           */
/*  triangleinit()   Initialize some variables.                              */
/*                                                                           */
/*****************************************************************************/

void mesh2d::triangleinit()
{
  points.maxitems = triangles.maxitems = shelles.maxitems = viri.maxitems = 0l;
  points.itembytes = triangles.itembytes = shelles.itembytes =
    viri.itembytes = 0;
  recenttri.tri = (triangle *) NULL;    /* No triangle has been visited yet. */
  samples = 1;            /* Point location should take at least one sample. */
  checksegments = 0;      /* There are no segments in the triangulation yet. */
  circumcentercount = 0;
  randomseed = 1;
  incirclecount = counterclockcount = 0;
  dummytribase = NULL;
  dummyshbase = NULL;
  restartsymbol = 0;
}

/*****************************************************************************/
/*                                                                           */
/* trianglerestart()    Clear all remaining allocated memory, not free them. */
/*                                                                           */
/*****************************************************************************/

void mesh2d::trianglerestart()
{
  triangles.restart();
  if (useshelles) {
    shelles.restart();
  }
  points.restart();

  recenttri.tri = (triangle *) NULL;    // No triangle has been visited yet.
  samples = 1;            // Point location should take at least one sample.
  checksegments = 0;      // There are no segments in the triangulation yet.
  randomseed = 1;
  circumcentercount = 0;
  restartsymbol = 1;
}

/*****************************************************************************/
/*                                                                           */
/*  counterclockwise()   Return a positive value if the points pa, pb, and   */
/*                       pc occur in counterclockwise order; a negative      */
/*                       value if they occur in clockwise order; and zero    */
/*                       if they are collinear.  The result is also a rough  */
/*                       approximation of twice the signed area of the       */
/*                       triangle defined by the three points.               */
/*                                                                           */
/*  Uses exact arithmetic if necessary to ensure a correct answer.  The      */
/*  result returned is the determinant of a matrix.  This determinant is     */
/*  computed adaptively, in the sense that exact arithmetic is used only to  */
/*  the degree it is needed to ensure that the returned value has the        */
/*  correct sign.  Hence, this function is usually quite fast, but will run  */
/*  more slowly when the input points are collinear or nearly so.            */
/*                                                                           */
/*  See my Robust Predicates paper for details.                              */
/*                                                                           */
/*****************************************************************************/

#define dDIST2D(a, b) sqrt((a[0]-b[0])*(a[0]-b[0]) + (a[1]-b[1])*(a[1]-b[1]))

REAL mesh2d::counterclockwise(point pa, point pb, point pc)
{
  counterclockcount++;
  if (noexact) {
    REAL xa = pa[0], ya = pa[1];
    REAL xb = pb[0], yb = pb[1];
    REAL xc = pc[0], yc = pc[1];

    // Currently no exact arithmetic
    REAL dDet = ((xb - xa) * (yc - ya) - (xc - xa) * (yb - ya));
    // Scale the determinant by the mean of the magnitudes of vectors:
    REAL dScale = (dDIST2D (pa, pb)
                   + dDIST2D (pb, pc)
		               + dDIST2D (pc, pa)) / 3;
    REAL dScaleDet = dDet / (dScale * dScale);
    if (fabs(dScaleDet) <= 1.e-10) {
      dDet = 0.;
    }
    return dDet;
  } else {
    REAL dDet = orient2d(pa, pb, pc);
    return dDet;
  }
}

/*****************************************************************************/
/*                                                                           */
/*  incircle()   Return a positive value if the point pd lies inside the     */
/*               circle passing through pa, pb, and pc; a negative value if  */
/*               it lies outside; and zero if the four points are cocircular.*/
/*               The points pa, pb, and pc must be in counterclockwise       */
/*               order, or the sign of the result will be reversed.          */
/*                                                                           */
/*  Uses exact arithmetic if necessary to ensure a correct answer.  The      */
/*  result returned is the determinant of a matrix.  This determinant is     */
/*  computed adaptively, in the sense that exact arithmetic is used only to  */
/*  the degree it is needed to ensure that the returned value has the        */
/*  correct sign.  Hence, this function is usually quite fast, but will run  */
/*  more slowly when the input points are cocircular or nearly so.           */
/*                                                                           */
/*  See my Robust Predicates paper for details.                              */
/*                                                                           */
/*****************************************************************************/

REAL mesh2d::iincircle(point pa, point pb, point pc, point pd)
{
  incirclecount++;
  return incircle(pa, pb, pc, pd);
}

/*****************************************************************************/
/*                                                                           */
/*  randomnation()   Generate a random number between 0 and `choices' - 1.   */
/*                                                                           */
/*  This is a simple linear congruential random number generator.  Hence, it */
/*  is a bad random number generator, but good enough for most randomized    */
/*  geometric algorithms.                                                    */
/*                                                                           */
/*****************************************************************************/

unsigned long mesh2d::randomnation(unsigned int choices)
{
  randomseed = (randomseed * 1366l + 150889l) % 714025l;
  return randomseed / (714025l / choices + 1);
}

/********* Point location routines begin here                        *********/
/**                                                                         **/
/**                                                                         **/

/*****************************************************************************/
/*                                                                           */
/*  makepointmap()   Construct a mapping from points to triangles to improve  */
/*                  the speed of point location for segment insertion.       */
/*                                                                           */
/*  Traverses all the triangles, and provides each corner of each triangle   */
/*  with a pointer to that triangle.  Of course, pointers will be            */
/*  overwritten by other pointers because (almost) each point is a corner    */
/*  of several triangles, but in the end every point will point to some      */
/*  triangle that contains it.                                               */
/*                                                                           */
/*****************************************************************************/

void mesh2d::makepointmap()
{
  struct triedge triangleloop;
  point triorg;

  if (verbose) {
    printf("    Constructing mapping from points to triangles.\n");
  }
  triangles.traversalinit();
  triangleloop.tri = triangletraverse();
  while (triangleloop.tri != (triangle *) NULL) {
    /* Check all three points of the triangle. */
    for (triangleloop.orient = 0; triangleloop.orient < 3;
         triangleloop.orient++) {
      org(triangleloop, triorg);
      setpoint2tri(triorg, encode(triangleloop));
    }
    triangleloop.tri = triangletraverse();
  }
}

/*****************************************************************************/
/*                                                                           */
/*  preciselocate()   Find a triangle or edge containing a given point.      */
/*                                                                           */
/*  Begins its search from `searchtri'.  It is important that `searchtri'    */
/*  be a handle with the property that `searchpoint' is strictly to the left */
/*  of the edge denoted by `searchtri', or is collinear with that edge and   */
/*  does not intersect that edge.  (In particular, `searchpoint' should not  */
/*  be the origin or destination of that edge.)                              */
/*                                                                           */
/*  These conditions are imposed because preciselocate() is normally used in */
/*  one of two situations:                                                   */
/*                                                                           */
/*  (1)  To try to find the location to insert a new point.  Normally, we    */
/*       know an edge that the point is strictly to the left of.  In the     */
/*       incremental Delaunay algorithm, that edge is a bounding box edge.   */
/*       In Ruppert's Delaunay refinement algorithm for quality meshing,     */
/*       that edge is the shortest edge of the triangle whose circumcenter   */
/*       is being inserted.                                                  */
/*                                                                           */
/*  (2)  To try to find an existing point.  In this case, any edge on the    */
/*       convex hull is a good starting edge.  The possibility that the      */
/*       vertex one seeks is an endpoint of the starting edge must be        */
/*       screened out before preciselocate() is called.                      */
/*                                                                           */
/*  On completion, `searchtri' is a triangle that contains `searchpoint'.    */
/*                                                                           */
/*  This implementation differs from that given by Guibas and Stolfi.  It    */
/*  walks from triangle to triangle, crossing an edge only if `searchpoint'  */
/*  is on the other side of the line containing that edge.  After entering   */
/*  a triangle, there are two edges by which one can leave that triangle.    */
/*  If both edges are valid (`searchpoint' is on the other side of both      */
/*  edges), one of the two is chosen by drawing a line perpendicular to      */
/*  the entry edge (whose endpoints are `forg' and `fdest') passing through  */
/*  `fapex'.  Depending on which side of this perpendicular `searchpoint'    */
/*  falls on, an exit edge is chosen.                                        */
/*                                                                           */
/*  This implementation is empirically faster than the Guibas and Stolfi     */
/*  point location routine (which I originally used), which tends to spiral  */
/*  in toward its target.                                                    */
/*                                                                           */
/*  Returns ONVERTEX if the point lies on an existing vertex.  `searchtri'   */
/*  is a handle whose origin is the existing vertex.                         */
/*                                                                           */
/*  Returns ONEDGE if the point lies on a mesh edge.  `searchtri' is a       */
/*  handle whose primary edge is the edge on which the point lies.           */
/*                                                                           */
/*  Returns INTRIANGLE if the point lies strictly within a triangle.         */
/*  `searchtri' is a handle on the triangle that contains the point.         */
/*                                                                           */
/*  Returns OUTSIDE if the point lies outside the mesh.  `searchtri' is a    */
/*  handle whose primary edge the point is to the right of.  This might      */
/*  occur when the circumcenter of a triangle falls just slightly outside    */
/*  the mesh due to floating-point roundoff error.  It also occurs when      */
/*  seeking a hole or region point that a foolish user has placed outside    */
/*  the mesh.                                                                */
/*                                                                           */
/*  WARNING:  This routine is designed for convex triangulations, and will   */
/*  not generally work after the holes and concavities have been carved.     */
/*  However, it can still be used to find the circumcenter of a triangle, as */
/*  long as the search is begun from the triangle in question.               */
/*                                                                           */
/*****************************************************************************/

enum mesh2d::locateresult
mesh2d::preciselocate(point searchpoint, struct triedge *searchtri)
{
  struct triedge backtracktri;
  point forg, fdest, fapex;
  point swappoint;
  REAL orgorient, destorient;
  int moveleft;
  triangle ptr;                         /* Temporary variable used by sym(). */

  if (verbose > 2) {
    printf("  Searching for point (%.12g, %.12g).\n",
           searchpoint[0], searchpoint[1]);
  }
  /* Where are we? */
  org(*searchtri, forg);
  dest(*searchtri, fdest);
  apex(*searchtri, fapex);
  while (1) {
    if (verbose > 2) {
      printf("    At (%.12g, %.12g) (%.12g, %.12g) (%.12g, %.12g)\n",
             forg[0], forg[1], fdest[0], fdest[1], fapex[0], fapex[1]);
    }
    /* Check whether the apex is the point we seek. */
    if ((fapex[0] == searchpoint[0]) && (fapex[1] == searchpoint[1])) {
      lprevself(*searchtri);
      return ONVERTEX;
    }
    /* Does the point lie on the other side of the line defined by the */
    /*   triangle edge opposite the triangle's destination?            */
    destorient = counterclockwise(forg, fapex, searchpoint);
    /* Does the point lie on the other side of the line defined by the */
    /*   triangle edge opposite the triangle's origin?                 */
    orgorient = counterclockwise(fapex, fdest, searchpoint);
    if (destorient > 0.0) {
      if (orgorient > 0.0) {
        /* Move left if the inner product of (fapex - searchpoint) and  */
        /*   (fdest - forg) is positive.  This is equivalent to drawing */
        /*   a line perpendicular to the line (forg, fdest) passing     */
        /*   through `fapex', and determining which side of this line   */
        /*   `searchpoint' falls on.                                    */
        moveleft = (fapex[0] - searchpoint[0]) * (fdest[0] - forg[0]) +
                   (fapex[1] - searchpoint[1]) * (fdest[1] - forg[1]) > 0.0;
      } else {
        moveleft = 1;
      }
    } else {
      if (orgorient > 0.0) {
        moveleft = 0;
      } else {
        /* The point we seek must be on the boundary of or inside this */
        /*   triangle.                                                 */
        if (destorient == 0.0) {
          lprevself(*searchtri);
          return ONEDGE;
        }
        if (orgorient == 0.0) {
          lnextself(*searchtri);
          return ONEDGE;
        }
        return INTRIANGLE;
      }
    }

    /* Move to another triangle.  Leave a trace `backtracktri' in case */
    /*   floating-point roundoff or some such bogey causes us to walk  */
    /*   off a boundary of the triangulation.  We can just bounce off  */
    /*   the boundary as if it were an elastic band.                   */
    if (moveleft) {
      lprev(*searchtri, backtracktri);
      fdest = fapex;
    } else {
      lnext(*searchtri, backtracktri);
      forg = fapex;
    }
    sym(backtracktri, *searchtri);

    /* Check for walking off the edge. */
    if (searchtri->tri == dummytri) {
      /* Turn around. */
      triedgecopy(backtracktri, *searchtri);
      swappoint = forg;
      forg = fdest;
      fdest = swappoint;
      apex(*searchtri, fapex);
      /* Check if the point really is beyond the triangulation boundary. */
      destorient = counterclockwise(forg, fapex, searchpoint);
      orgorient = counterclockwise(fapex, fdest, searchpoint);
      if ((orgorient < 0.0) && (destorient < 0.0)) {
        return OUTSIDE;
      }
    } else {
      apex(*searchtri, fapex);
    }
  }
}

/*****************************************************************************/
/*                                                                           */
/*  locate()   Find a triangle or edge containing a given point.             */
/*                                                                           */
/*  Searching begins from one of:  the input `searchtri', a recently         */
/*  encountered triangle `recenttri', or from a triangle chosen from a       */
/*  random sample.  The choice is made by determining which triangle's       */
/*  origin is closest to the point we are searcing for.  Normally,           */
/*  `searchtri' should be a handle on the convex hull of the triangulation.  */
/*                                                                           */
/*  Details on the random sampling method can be found in the Mucke, Saias,  */
/*  and Zhu paper cited in the header of this code.                          */
/*                                                                           */
/*  On completion, `searchtri' is a triangle that contains `searchpoint'.    */
/*                                                                           */
/*  Returns ONVERTEX if the point lies on an existing vertex.  `searchtri'   */
/*  is a handle whose origin is the existing vertex.                         */
/*                                                                           */
/*  Returns ONEDGE if the point lies on a mesh edge.  `searchtri' is a       */
/*  handle whose primary edge is the edge on which the point lies.           */
/*                                                                           */
/*  Returns INTRIANGLE if the point lies strictly within a triangle.         */
/*  `searchtri' is a handle on the triangle that contains the point.         */
/*                                                                           */
/*  Returns OUTSIDE if the point lies outside the mesh.  `searchtri' is a    */
/*  handle whose primary edge the point is to the right of.  This might      */
/*  occur when the circumcenter of a triangle falls just slightly outside    */
/*  the mesh due to floating-point roundoff error.  It also occurs when      */
/*  seeking a hole or region point that a foolish user has placed outside    */
/*  the mesh.                                                                */
/*                                                                           */
/*  WARNING:  This routine is designed for convex triangulations, and will   */
/*  not generally work after the holes and concavities have been carved.     */
/*                                                                           */
/*****************************************************************************/

enum mesh2d::locateresult
mesh2d::locate(point searchpoint, struct triedge *searchtri)
{
  void **sampleblock;
  triangle *firsttri;
  struct triedge sampletri;
  point torg, tdest;
  unsigned long alignptr;
  REAL searchdist, dist;
  REAL ahead;
  long sampleblocks, samplesperblock, samplenum;
  long triblocks;
  long i, j;
  triangle ptr;                         /* Temporary variable used by sym(). */

  if (verbose > 2) {
    printf("  Randomly sampling for a triangle near point (%.12g, %.12g).\n",
           searchpoint[0], searchpoint[1]);
  }
  /* Record the distance from the suggested starting triangle to the */
  /*   point we seek.                                                */
  org(*searchtri, torg);
  searchdist = (searchpoint[0] - torg[0]) * (searchpoint[0] - torg[0])
             + (searchpoint[1] - torg[1]) * (searchpoint[1] - torg[1]);
  if (verbose > 2) {
    printf("    Boundary triangle has origin (%.12g, %.12g).\n",
           torg[0], torg[1]);
  }

  /* If a recently encountered triangle has been recorded and has not been */
  /*   deallocated, test it as a good starting point.                      */
  if (recenttri.tri != (triangle *) NULL) {
    if (recenttri.tri[3] != (triangle) NULL) {
      org(recenttri, torg);
      if ((torg[0] == searchpoint[0]) && (torg[1] == searchpoint[1])) {
        triedgecopy(recenttri, *searchtri);
        return ONVERTEX;
      }
      dist = (searchpoint[0] - torg[0]) * (searchpoint[0] - torg[0])
           + (searchpoint[1] - torg[1]) * (searchpoint[1] - torg[1]);
      if (dist < searchdist) {
        triedgecopy(recenttri, *searchtri);
        searchdist = dist;
        if (verbose > 2) {
          printf("    Choosing recent triangle with origin (%.12g, %.12g).\n",
                 torg[0], torg[1]);
        }
      }
    }
  }

  /* The number of random samples taken is proportional to the cube root of */
  /*   the number of triangles in the mesh.  The next bit of code assumes   */
  /*   that the number of triangles increases monotonically.                */
  while (SAMPLEFACTOR * samples * samples * samples < triangles.items) {
    samples++;
  }
  triblocks = (triangles.maxitems + TRIPERBLOCK - 1) / TRIPERBLOCK;
  samplesperblock = 1 + (samples / triblocks);
  sampleblocks = samples / samplesperblock;
  sampleblock = triangles.firstblock;
  sampletri.orient = 0;
  for (i = 0; i < sampleblocks; i++) {
    alignptr = (unsigned long) (sampleblock + 1);
    firsttri = (triangle *) (alignptr + (unsigned long) triangles.alignbytes
                          - (alignptr % (unsigned long) triangles.alignbytes));
    for (j = 0; j < samplesperblock; j++) {
      if (i == triblocks - 1) {
        samplenum = randomnation((int)
                                 (triangles.maxitems - (i * TRIPERBLOCK)));
      } else {
        samplenum = randomnation(TRIPERBLOCK);
      }
      sampletri.tri = (triangle *)
                      (firsttri + (samplenum * triangles.itemwords));
      if (sampletri.tri[3] != (triangle) NULL) {
        org(sampletri, torg);
        dist = (searchpoint[0] - torg[0]) * (searchpoint[0] - torg[0])
             + (searchpoint[1] - torg[1]) * (searchpoint[1] - torg[1]);
        if (dist < searchdist) {
          triedgecopy(sampletri, *searchtri);
          searchdist = dist;
          if (verbose > 2) {
            printf("    Choosing triangle with origin (%.12g, %.12g).\n",
                   torg[0], torg[1]);
          }
        }
      }
    }
    sampleblock = (void **) *sampleblock;
  }
  /* Where are we? */
  org(*searchtri, torg);
  dest(*searchtri, tdest);
  /* Check the starting triangle's vertices. */
  if ((torg[0] == searchpoint[0]) && (torg[1] == searchpoint[1])) {
    return ONVERTEX;
  }
  if ((tdest[0] == searchpoint[0]) && (tdest[1] == searchpoint[1])) {
    lnextself(*searchtri);
    return ONVERTEX;
  }
  /* Orient `searchtri' to fit the preconditions of calling preciselocate(). */
  ahead = counterclockwise(torg, tdest, searchpoint);
  if (ahead < 0.0) {
    /* Turn around so that `searchpoint' is to the left of the */
    /*   edge specified by `searchtri'.                        */
    symself(*searchtri);
  } else if (ahead == 0.0) {
    /* Check if `searchpoint' is between `torg' and `tdest'. */
    if (((torg[0] < searchpoint[0]) == (searchpoint[0] < tdest[0]))
        && ((torg[1] < searchpoint[1]) == (searchpoint[1] < tdest[1]))) {
      return ONEDGE;
    }
  }
  return preciselocate(searchpoint, searchtri);
}

/**                                                                         **/
/**                                                                         **/
/********* Point location routines end here                          *********/

/********* Mesh transformation routines begin here                   *********/
/**                                                                         **/
/**                                                                         **/

/*****************************************************************************/
/*                                                                           */
/*  insertshelle()   Create a new shell edge and insert it between two       */
/*                   triangles.                                              */
/*                                                                           */
/*  The new shell edge is inserted at the edge described by the handle       */
/*  `tri'.  Its vertices are properly initialized.  The marker `shellemark'  */
/*  is applied to the shell edge and, if appropriate, its vertices.          */
/*                                                                           */
/*****************************************************************************/

void mesh2d::insertshelle(struct triedge *tri, int shellemark)
{
  struct triedge oppotri;
  struct edge newshelle;
  point triorg, tridest;
  triangle ptr;                         /* Temporary variable used by sym(). */
  shelle sptr;                      /* Temporary variable used by tspivot(). */

  /* Mark points if possible. */
  org(*tri, triorg);
  dest(*tri, tridest);
  if (pointmark(triorg) == 0) {
    setpointmark(triorg, shellemark);
  }
  if (pointmark(tridest) == 0) {
    setpointmark(tridest, shellemark);
  }
  /* Check if there's already a shell edge here. */
  tspivot(*tri, newshelle);
  if (newshelle.sh == dummysh) {
    /* Make new shell edge and initialize its vertices. */
    makeshelle(&newshelle);
    setsorg(newshelle, tridest);
    setsdest(newshelle, triorg);
    /* Bond new shell edge to the two triangles it is sandwiched between. */
    /*   Note that the facing triangle `oppotri' might be equal to        */
    /*   `dummytri' (outer space), but the new shell edge is bonded to it */
    /*   all the same.                                                    */
    tsbond(*tri, newshelle);
    sym(*tri, oppotri);
    ssymself(newshelle);
    tsbond(oppotri, newshelle);
    setmark(newshelle, shellemark);
    if (verbose > 2) {
      printf("  Inserting new ");
      printshelle(&newshelle);
    }
  } else {
    if (mark(newshelle) == 0) {
      setmark(newshelle, shellemark);
    }
  }
}

/*****************************************************************************/
/*                                                                           */
/*  Terminology                                                              */
/*                                                                           */
/*  A "local transformation" replaces a small set of triangles with another  */
/*  set of triangles.  This may or may not involve inserting or deleting a   */
/*  point.                                                                   */
/*                                                                           */
/*  The term "casing" is used to describe the set of triangles that are      */
/*  attached to the triangles being transformed, but are not transformed     */
/*  themselves.  Think of the casing as a fixed hollow structure inside      */
/*  which all the action happens.  A "casing" is only defined relative to    */
/*  a single transformation; each occurrence of a transformation will        */
/*  involve a different casing.                                              */
/*                                                                           */
/*  A "shell" is similar to a "casing".  The term "shell" describes the set  */
/*  of shell edges (if any) that are attached to the triangles being         */
/*  transformed.  However, I sometimes use "shell" to refer to a single      */
/*  shell edge, so don't get confused.                                       */
/*                                                                           */
/*****************************************************************************/

/*****************************************************************************/
/*                                                                           */
/*  flip()   Transform two triangles to two different triangles by flipping  */
/*           an edge within a quadrilateral.                                 */
/*                                                                           */
/*  Imagine the original triangles, abc and bad, oriented so that the        */
/*  shared edge ab lies in a horizontal plane, with the point b on the left  */
/*  and the point a on the right.  The point c lies below the edge, and the  */
/*  point d lies above the edge.  The `flipedge' handle holds the edge ab    */
/*  of triangle abc, and is directed left, from vertex a to vertex b.        */
/*                                                                           */
/*  The triangles abc and bad are deleted and replaced by the triangles cdb  */
/*  and dca.  The triangles that represent abc and bad are NOT deallocated;  */
/*  they are reused for dca and cdb, respectively.  Hence, any handles that  */
/*  may have held the original triangles are still valid, although not       */
/*  directed as they were before.                                            */
/*                                                                           */
/*  Upon completion of this routine, the `flipedge' handle holds the edge    */
/*  dc of triangle dca, and is directed down, from vertex d to vertex c.     */
/*  (Hence, the two triangles have rotated counterclockwise.)                */
/*                                                                           */
/*  WARNING:  This transformation is geometrically valid only if the         */
/*  quadrilateral adbc is convex.  Furthermore, this transformation is       */
/*  valid only if there is not a shell edge between the triangles abc and    */
/*  bad.  This routine does not check either of these preconditions, and     */
/*  it is the responsibility of the calling routine to ensure that they are  */
/*  met.  If they are not, the streets shall be filled with wailing and      */
/*  gnashing of teeth.                                                       */
/*                                                                           */
/*****************************************************************************/

void mesh2d::flip(struct triedge *flipedge)
{
  struct triedge botleft, botright;
  struct triedge topleft, topright;
  struct triedge top;
  struct triedge botlcasing, botrcasing;
  struct triedge toplcasing, toprcasing;
  struct edge botlshelle, botrshelle;
  struct edge toplshelle, toprshelle;
  point leftpoint, rightpoint, botpoint;
  point farpoint;
  triangle ptr;                         /* Temporary variable used by sym(). */
  shelle sptr;                      /* Temporary variable used by tspivot(). */

  /* Identify the vertices of the quadrilateral. */
  org(*flipedge, rightpoint);
  dest(*flipedge, leftpoint);
  apex(*flipedge, botpoint);
  sym(*flipedge, top);
#ifdef SELF_CHECK
  if (top.tri == dummytri) {
    printf("Internal error in flip():  Attempt to flip on boundary.\n");
    lnextself(*flipedge);
    return;
  }
  if (checksegments) {
    tspivot(*flipedge, toplshelle);
    if (toplshelle.sh != dummysh) {
      printf("Internal error in flip():  Attempt to flip a segment.\n");
      lnextself(*flipedge);
      return;
    }
  }
#endif /* SELF_CHECK */
  apex(top, farpoint);

  /* Identify the casing of the quadrilateral. */
  lprev(top, topleft);
  sym(topleft, toplcasing);
  lnext(top, topright);
  sym(topright, toprcasing);
  lnext(*flipedge, botleft);
  sym(botleft, botlcasing);
  lprev(*flipedge, botright);
  sym(botright, botrcasing);
  /* Rotate the quadrilateral one-quarter turn counterclockwise. */
  bond(topleft, botlcasing);
  bond(botleft, botrcasing);
  bond(botright, toprcasing);
  bond(topright, toplcasing);

  if (checksegments) {
    /* Check for shell edges and rebond them to the quadrilateral. */
    tspivot(topleft, toplshelle);
    tspivot(botleft, botlshelle);
    tspivot(botright, botrshelle);
    tspivot(topright, toprshelle);
    if (toplshelle.sh == dummysh) {
      tsdissolve(topright);
    } else {
      tsbond(topright, toplshelle);
    }
    if (botlshelle.sh == dummysh) {
      tsdissolve(topleft);
    } else {
      tsbond(topleft, botlshelle);
    }
    if (botrshelle.sh == dummysh) {
      tsdissolve(botleft);
    } else {
      tsbond(botleft, botrshelle);
    }
    if (toprshelle.sh == dummysh) {
      tsdissolve(botright);
    } else {
      tsbond(botright, toprshelle);
    }
  }

  /* New point assignments for the rotated quadrilateral. */
  setorg(*flipedge, farpoint);
  setdest(*flipedge, botpoint);
  setapex(*flipedge, rightpoint);
  setorg(top, botpoint);
  setdest(top, farpoint);
  setapex(top, leftpoint);
  if (verbose > 2) {
    printf("  Edge flip results in left ");
    lnextself(topleft);
    printtriangle(&topleft);
    printf("  and right ");
    printtriangle(flipedge);
  }
}

/*****************************************************************************/
/*                                                                           */
/*  insertsite()   Insert a vertex into a Delaunay triangulation,            */
/*                 performing flips as necessary to maintain the Delaunay    */
/*                 property.                                                 */
/*                                                                           */
/*  The point `insertpoint' is located.  If `searchtri.tri' is not NULL,     */
/*  the search for the containing triangle begins from `searchtri'.  If      */
/*  `searchtri.tri' is NULL, a full point location procedure is called.      */
/*  If `insertpoint' is found inside a triangle, the triangle is split into  */
/*  three; if `insertpoint' lies on an edge, the edge is split in two,       */
/*  thereby splitting the two adjacent triangles into four.  Edge flips are  */
/*  used to restore the Delaunay property.  If `insertpoint' lies on an      */
/*  existing vertex, no action is taken, and the value DUPLICATEPOINT is     */
/*  returned.  On return, `searchtri' is set to a handle whose origin is the */
/*  existing vertex.                                                         */
/*                                                                           */
/*  Normally, the parameter `splitedge' is set to NULL, implying that no     */
/*  segment should be split.  In this case, if `insertpoint' is found to     */
/*  lie on a segment, no action is taken, and the value VIOLATINGPOINT is    */
/*  returned.  On return, `searchtri' is set to a handle whose primary edge  */
/*  is the violated segment.                                                 */
/*                                                                           */
/*  If the calling routine wishes to split a segment by inserting a point in */
/*  it, the parameter `splitedge' should be that segment.  In this case,     */
/*  `searchtri' MUST be the triangle handle reached by pivoting from that    */
/*  segment; no point location is done.                                      */
/*                                                                           */
/*  `segmentflaws' and `triflaws' are flags that indicate whether or not     */
/*  there should be checks for the creation of encroached segments or bad    */
/*  quality faces.  If a newly inserted point encroaches upon segments,      */
/*  these segments are added to the list of segments to be split if          */
/*  `segmentflaws' is set.  If bad triangles are created, these are added    */
/*  to the queue if `triflaws' is set.                                       */
/*                                                                           */
/*  If a duplicate point or violated segment does not prevent the point      */
/*  from being inserted, the return value will be ENCROACHINGPOINT if the    */
/*  point encroaches upon a segment (and checking is enabled), or            */
/*  SUCCESSFULPOINT otherwise.  In either case, `searchtri' is set to a      */
/*  handle whose origin is the newly inserted vertex.                        */
/*                                                                           */
/*  insertsite() does not use flip() for reasons of speed; some              */
/*  information can be reused from edge flip to edge flip, like the          */
/*  locations of shell edges.                                                */
/*                                                                           */
/*****************************************************************************/

enum mesh2d::insertsiteresult
mesh2d::insertsite(point insertpoint, struct triedge *searchtri,
                   struct edge *splitedge, int segmentflaws, int triflaws)
{
  struct triedge horiz;
  struct triedge top;
  struct triedge botleft, botright;
  struct triedge topleft, topright;
  struct triedge newbotleft, newbotright;
  struct triedge newtopright;
  struct triedge botlcasing, botrcasing;
  struct triedge toplcasing, toprcasing;
  struct triedge testtri;
  struct edge botlshelle, botrshelle;
  struct edge toplshelle, toprshelle;
  struct edge brokenshelle;
  struct edge checkshelle;
  struct edge rightedge;
  struct edge newedge;
  struct edge *encroached;
  point first;
  point leftpoint, rightpoint, botpoint, toppoint, farpoint;
  REAL attrib;
  REAL area;
  enum insertsiteresult success;
  enum locateresult intersect;
  int doflip;
  int mirrorflag;
  int i;
  triangle ptr;                         /* Temporary variable used by sym(). */
  shelle sptr;         /* Temporary variable used by spivot() and tspivot(). */

  if (verbose > 1) {
    printf("  Inserting (%.12g, %.12g).\n", insertpoint[0], insertpoint[1]);
  }
  if (splitedge == (struct edge *) NULL) {
    /* Find the location of the point to be inserted.  Check if a good */
    /*   starting triangle has already been provided by the caller.    */
    if (searchtri->tri == (triangle *) NULL) {
      /* Find a boundary triangle. */
      horiz.tri = dummytri;
      horiz.orient = 0;
      symself(horiz);
      /* Search for a triangle containing `insertpoint'. */
      intersect = locate(insertpoint, &horiz);
    } else {
      /* Start searching from the triangle provided by the caller. */
      triedgecopy(*searchtri, horiz);
      intersect = preciselocate(insertpoint, &horiz);
    }
  } else {
    /* The calling routine provides the edge in which the point is inserted. */
    triedgecopy(*searchtri, horiz);
    intersect = ONEDGE;
  }
  if (intersect == ONVERTEX) {
    /* There's already a vertex there.  Return in `searchtri' a triangle */
    /*   whose origin is the existing vertex.                            */
    triedgecopy(horiz, *searchtri);
    triedgecopy(horiz, recenttri);
    return DUPLICATEPOINT;
  }
  if ((intersect == ONEDGE) || (intersect == OUTSIDE)) {
    /* The vertex falls on an edge or boundary. */
    if (checksegments && (splitedge == (struct edge *) NULL)) {
      /* Check whether the vertex falls on a shell edge. */
      tspivot(horiz, brokenshelle);
      if (brokenshelle.sh != dummysh) {
        /* The vertex falls on a shell edge. */
        /* Return a handle whose primary edge contains the point, */
        /*   which has not been inserted.                         */
        triedgecopy(horiz, *searchtri);
        triedgecopy(horiz, recenttri);
        return VIOLATINGPOINT;
      }
    }
    /* Insert the point on an edge, dividing one triangle into two (if */
    /*   the edge lies on a boundary) or two triangles into four.      */
    lprev(horiz, botright);
    sym(botright, botrcasing);
    sym(horiz, topright);
    /* Is there a second triangle?  (Or does this edge lie on a boundary?) */
    mirrorflag = topright.tri != dummytri;
    if (mirrorflag) {
      lnextself(topright);
      sym(topright, toprcasing);
      maketriangle(&newtopright);
    } else {
      /* Splitting the boundary edge increases the number of boundary edges. */
      hullsize++;
    }
    maketriangle(&newbotright);

    /* Set the vertices of changed and new triangles. */
    org(horiz, rightpoint);
    dest(horiz, leftpoint);
    apex(horiz, botpoint);
    setorg(newbotright, botpoint);
    setdest(newbotright, rightpoint);
    setapex(newbotright, insertpoint);
    setorg(horiz, insertpoint);
    for (i = 0; i < eextras; i++) {
      /* Set the element attributes of a new triangle. */
      setelemattribute(newbotright, i, elemattribute(botright, i));
    }
    if (vararea) {
      /* Set the area constraint of a new triangle. */
      setareabound(newbotright, areabound(botright));
    }
    if (mirrorflag) {
      dest(topright, toppoint);
      setorg(newtopright, rightpoint);
      setdest(newtopright, toppoint);
      setapex(newtopright, insertpoint);
      setorg(topright, insertpoint);
      for (i = 0; i < eextras; i++) {
        /* Set the element attributes of another new triangle. */
        setelemattribute(newtopright, i, elemattribute(topright, i));
      }
      if (vararea) {
        /* Set the area constraint of another new triangle. */
        setareabound(newtopright, areabound(topright));
      }
    }

    /* There may be shell edges that need to be bonded */
    /*   to the new triangle(s).                       */
    if (checksegments) {
      tspivot(botright, botrshelle);
      if (botrshelle.sh != dummysh) {
        tsdissolve(botright);
        tsbond(newbotright, botrshelle);
      }
      if (mirrorflag) {
        tspivot(topright, toprshelle);
        if (toprshelle.sh != dummysh) {
          tsdissolve(topright);
          tsbond(newtopright, toprshelle);
        }
      }
    }

    /* Bond the new triangle(s) to the surrounding triangles. */
    bond(newbotright, botrcasing);
    lprevself(newbotright);
    bond(newbotright, botright);
    lprevself(newbotright);
    if (mirrorflag) {
      bond(newtopright, toprcasing);
      lnextself(newtopright);
      bond(newtopright, topright);
      lnextself(newtopright);
      bond(newtopright, newbotright);
    }

    if (splitedge != (struct edge *) NULL) {
      /* Split the shell edge into two. */
      setsdest(*splitedge, insertpoint);
      ssymself(*splitedge);
      spivot(*splitedge, rightedge);
      insertshelle(&newbotright, mark(*splitedge));
      tspivot(newbotright, newedge);
      sbond(*splitedge, newedge);
      ssymself(newedge);
      sbond(newedge, rightedge);
      ssymself(*splitedge);
    }

#ifdef SELF_CHECK
    if (counterclockwise(rightpoint, leftpoint, botpoint) < 0.0) {
      printf("Internal error in insertsite():\n");
      printf("  Clockwise triangle prior to edge point insertion (bottom).\n");
    }
    if (mirrorflag) {
      if (counterclockwise(leftpoint, rightpoint, toppoint) < 0.0) {
        printf("Internal error in insertsite():\n");
        printf("  Clockwise triangle prior to edge point insertion (top).\n");
      }
      if (counterclockwise(rightpoint, toppoint, insertpoint) < 0.0) {
        printf("Internal error in insertsite():\n");
        printf("  Clockwise triangle after edge point insertion (top right).\n"
               );
      }
      if (counterclockwise(toppoint, leftpoint, insertpoint) < 0.0) {
        printf("Internal error in insertsite():\n");
        printf("  Clockwise triangle after edge point insertion (top left).\n"
               );
      }
    }
    if (counterclockwise(leftpoint, botpoint, insertpoint) < 0.0) {
      printf("Internal error in insertsite():\n");
      printf("  Clockwise triangle after edge point insertion (bottom left).\n"
             );
    }
    if (counterclockwise(botpoint, rightpoint, insertpoint) < 0.0) {
      printf("Internal error in insertsite():\n");
      printf(
        "  Clockwise triangle after edge point insertion (bottom right).\n");
    }
#endif /* SELF_CHECK */
    if (verbose > 2) {
      printf("  Updating bottom left ");
      printtriangle(&botright);
      if (mirrorflag) {
        printf("  Updating top left ");
        printtriangle(&topright);
        printf("  Creating top right ");
        printtriangle(&newtopright);
      }
      printf("  Creating bottom right ");
      printtriangle(&newbotright);
    }

    /* Position `horiz' on the first edge to check for */
    /*   the Delaunay property.                        */
    lnextself(horiz);
  } else {
    /* Insert the point in a triangle, splitting it into three. */
    lnext(horiz, botleft);
    lprev(horiz, botright);
    sym(botleft, botlcasing);
    sym(botright, botrcasing);
    maketriangle(&newbotleft);
    maketriangle(&newbotright);

    /* Set the vertices of changed and new triangles. */
    org(horiz, rightpoint);
    dest(horiz, leftpoint);
    apex(horiz, botpoint);
    setorg(newbotleft, leftpoint);
    setdest(newbotleft, botpoint);
    setapex(newbotleft, insertpoint);
    setorg(newbotright, botpoint);
    setdest(newbotright, rightpoint);
    setapex(newbotright, insertpoint);
    setapex(horiz, insertpoint);
    for (i = 0; i < eextras; i++) {
      /* Set the element attributes of the new triangles. */
      attrib = elemattribute(horiz, i);
      setelemattribute(newbotleft, i, attrib);
      setelemattribute(newbotright, i, attrib);
    }
    if (vararea) {
      /* Set the area constraint of the new triangles. */
      area = areabound(horiz);
      setareabound(newbotleft, area);
      setareabound(newbotright, area);
    }

    /* There may be shell edges that need to be bonded */
    /*   to the new triangles.                         */
    if (checksegments) {
      tspivot(botleft, botlshelle);
      if (botlshelle.sh != dummysh) {
        tsdissolve(botleft);
        tsbond(newbotleft, botlshelle);
      }
      tspivot(botright, botrshelle);
      if (botrshelle.sh != dummysh) {
        tsdissolve(botright);
        tsbond(newbotright, botrshelle);
      }
    }

    /* Bond the new triangles to the surrounding triangles. */
    bond(newbotleft, botlcasing);
    bond(newbotright, botrcasing);
    lnextself(newbotleft);
    lprevself(newbotright);
    bond(newbotleft, newbotright);
    lnextself(newbotleft);
    bond(botleft, newbotleft);
    lprevself(newbotright);
    bond(botright, newbotright);

#ifdef SELF_CHECK
    if (counterclockwise(rightpoint, leftpoint, botpoint) < 0.0) {
      printf("Internal error in insertsite():\n");
      printf("  Clockwise triangle prior to point insertion.\n");
    }
    if (counterclockwise(rightpoint, leftpoint, insertpoint) < 0.0) {
      printf("Internal error in insertsite():\n");
      printf("  Clockwise triangle after point insertion (top).\n");
    }
    if (counterclockwise(leftpoint, botpoint, insertpoint) < 0.0) {
      printf("Internal error in insertsite():\n");
      printf("  Clockwise triangle after point insertion (left).\n");
    }
    if (counterclockwise(botpoint, rightpoint, insertpoint) < 0.0) {
      printf("Internal error in insertsite():\n");
      printf("  Clockwise triangle after point insertion (right).\n");
    }
#endif /* SELF_CHECK */
    if (verbose > 2) {
      printf("  Updating top ");
      printtriangle(&horiz);
      printf("  Creating left ");
      printtriangle(&newbotleft);
      printf("  Creating right ");
      printtriangle(&newbotright);
    }
  }

  /* The insertion is successful by default, unless an encroached */
  /*   edge is found.                                             */
  success = SUCCESSFULPOINT;
  /* Circle around the newly inserted vertex, checking each edge opposite */
  /*   it for the Delaunay property.  Non-Delaunay edges are flipped.     */
  /*   `horiz' is always the edge being checked.  `first' marks where to  */
  /*   stop circling.                                                     */
  org(horiz, first);
  rightpoint = first;
  dest(horiz, leftpoint);
  /* Circle until finished. */
  while (1) {
    /* By default, the edge will be flipped. */
    doflip = 1;
    if (checksegments) {
      /* Check for a segment, which cannot be flipped. */
      tspivot(horiz, checkshelle);
      if (checkshelle.sh != dummysh) {
        /* The edge is a segment and cannot be flipped. */
        doflip = 0;
      }
    }
    if (doflip) {
      /* Check if the edge is a boundary edge. */
      sym(horiz, top);
      if (top.tri == dummytri) {
        /* The edge is a boundary edge and cannot be flipped. */
        doflip = 0;
      } else {
        /* Find the point on the other side of the edge. */
        apex(top, farpoint);
        /* In the incremental Delaunay triangulation algorithm, any of    */
        /*   `leftpoint', `rightpoint', and `farpoint' could be vertices  */
        /*   of the triangular bounding box.  These vertices must be      */
        /*   treated as if they are infinitely distant, even though their */
        /*   "coordinates" are not.                                       */
        if ((leftpoint == infpoint1) || (leftpoint == infpoint2)
                   || (leftpoint == infpoint3)) {
          /* `leftpoint' is infinitely distant.  Check the convexity of */
          /*   the boundary of the triangulation.  'farpoint' might be  */
          /*   infinite as well, but trust me, this same condition      */
          /*   should be applied.                                       */
          doflip = counterclockwise(insertpoint, rightpoint, farpoint) > 0.0;
        } else if ((rightpoint == infpoint1) || (rightpoint == infpoint2)
                   || (rightpoint == infpoint3)) {
          /* `rightpoint' is infinitely distant.  Check the convexity of */
          /*   the boundary of the triangulation.  'farpoint' might be  */
          /*   infinite as well, but trust me, this same condition      */
          /*   should be applied.                                       */
          doflip = counterclockwise(farpoint, leftpoint, insertpoint) > 0.0;
        } else if ((farpoint == infpoint1) || (farpoint == infpoint2)
            || (farpoint == infpoint3)) {
          /* `farpoint' is infinitely distant and cannot be inside */
          /*   the circumcircle of the triangle `horiz'.           */
          doflip = 0;
        } else {
          /* Test whether the edge is locally Delaunay. */
          doflip = iincircle(leftpoint, insertpoint, rightpoint, farpoint)
                   > 0.0;
        }
        if (doflip) {
          /* We made it!  Flip the edge `horiz' by rotating its containing */
          /*   quadrilateral (the two triangles adjacent to `horiz').      */
          /* Identify the casing of the quadrilateral. */
          lprev(top, topleft);
          sym(topleft, toplcasing);
          lnext(top, topright);
          sym(topright, toprcasing);
          lnext(horiz, botleft);
          sym(botleft, botlcasing);
          lprev(horiz, botright);
          sym(botright, botrcasing);
          /* Rotate the quadrilateral one-quarter turn counterclockwise. */
          bond(topleft, botlcasing);
          bond(botleft, botrcasing);
          bond(botright, toprcasing);
          bond(topright, toplcasing);
          if (checksegments) {
            /* Check for shell edges and rebond them to the quadrilateral. */
            tspivot(topleft, toplshelle);
            tspivot(botleft, botlshelle);
            tspivot(botright, botrshelle);
            tspivot(topright, toprshelle);
            if (toplshelle.sh == dummysh) {
              tsdissolve(topright);
            } else {
              tsbond(topright, toplshelle);
            }
            if (botlshelle.sh == dummysh) {
              tsdissolve(topleft);
            } else {
              tsbond(topleft, botlshelle);
            }
            if (botrshelle.sh == dummysh) {
              tsdissolve(botleft);
            } else {
              tsbond(botleft, botrshelle);
            }
            if (toprshelle.sh == dummysh) {
              tsdissolve(botright);
            } else {
              tsbond(botright, toprshelle);
            }
          }
          /* New point assignments for the rotated quadrilateral. */
          setorg(horiz, farpoint);
          setdest(horiz, insertpoint);
          setapex(horiz, rightpoint);
          setorg(top, insertpoint);
          setdest(top, farpoint);
          setapex(top, leftpoint);
          for (i = 0; i < eextras; i++) {
            /* Take the average of the two triangles' attributes. */
            attrib = 0.5 * (elemattribute(top, i) + elemattribute(horiz, i));
            setelemattribute(top, i, attrib);
            setelemattribute(horiz, i, attrib);
          }
          if (vararea) {
            if ((areabound(top) <= 0.0) || (areabound(horiz) <= 0.0)) {
              area = -1.0;
            } else {
              /* Take the average of the two triangles' area constraints.    */
              /*   This prevents small area constraints from migrating a     */
              /*   long, long way from their original location due to flips. */
              area = 0.5 * (areabound(top) + areabound(horiz));
            }
            setareabound(top, area);
            setareabound(horiz, area);
          }
#ifdef SELF_CHECK
          if (insertpoint != (point) NULL) {
            if (counterclockwise(leftpoint, insertpoint, rightpoint) < 0.0) {
              printf("Internal error in insertsite():\n");
              printf("  Clockwise triangle prior to edge flip (bottom).\n");
            }
            /* The following test has been removed because constrainededge() */
            /*   sometimes generates inverted triangles that insertsite()    */
            /*   removes.                                                    */
/*
            if (counterclockwise(rightpoint, farpoint, leftpoint) < 0.0) {
              printf("Internal error in insertsite():\n");
              printf("  Clockwise triangle prior to edge flip (top).\n");
            }
*/
            if (counterclockwise(farpoint, leftpoint, insertpoint) < 0.0) {
              printf("Internal error in insertsite():\n");
              printf("  Clockwise triangle after edge flip (left).\n");
            }
            if (counterclockwise(insertpoint, rightpoint, farpoint) < 0.0) {
              printf("Internal error in insertsite():\n");
              printf("  Clockwise triangle after edge flip (right).\n");
            }
          }
#endif /* SELF_CHECK */
          if (verbose > 2) {
            printf("  Edge flip results in left ");
            lnextself(topleft);
            printtriangle(&topleft);
            printf("  and right ");
            printtriangle(&horiz);
          }
          /* On the next iterations, consider the two edges that were  */
          /*   exposed (this is, are now visible to the newly inserted */
          /*   point) by the edge flip.                                */
          lprevself(horiz);
          leftpoint = farpoint;
        }
      }
    }
    if (!doflip) {
      /* The handle `horiz' is accepted as locally Delaunay. */
      /* Look for the next edge around the newly inserted point. */
      lnextself(horiz);
      sym(horiz, testtri);
      /* Check for finishing a complete revolution about the new point, or */
      /*   falling off the edge of the triangulation.  The latter will     */
      /*   happen when a point is inserted at a boundary.                  */
      if ((leftpoint == first) || (testtri.tri == dummytri)) {
        /* We're done.  Return a triangle whose origin is the new point. */
        lnext(horiz, *searchtri);
        lnext(horiz, recenttri);
        return success;
      }
      /* Finish finding the next edge around the newly inserted point. */
      lnext(testtri, horiz);
      rightpoint = leftpoint;
      dest(horiz, leftpoint);
    }
  }
}

/**                                                                         **/
/**                                                                         **/
/********* Mesh transformation routines end here                     *********/

/********* Divide-and-conquer Delaunay triangulation begins here     *********/
/**                                                                         **/
/**                                                                         **/

/*****************************************************************************/
/*                                                                           */
/*  The divide-and-conquer bounding box                                      */
/*                                                                           */
/*  I originally implemented the divide-and-conquer and incremental Delaunay */
/*  triangulations using the edge-based data structure presented by Guibas   */
/*  and Stolfi.  Switching to a triangle-based data structure doubled the    */
/*  speed.  However, I had to think of a few extra tricks to maintain the    */
/*  elegance of the original algorithms.                                     */
/*                                                                           */
/*  The "bounding box" used by my variant of the divide-and-conquer          */
/*  algorithm uses one triangle for each edge of the convex hull of the      */
/*  triangulation.  These bounding triangles all share a common apical       */
/*  vertex, which is represented by NULL and which represents nothing.       */
/*  The bounding triangles are linked in a circular fan about this NULL      */
/*  vertex, and the edges on the convex hull of the triangulation appear     */
/*  opposite the NULL vertex.  You might find it easiest to imagine that     */
/*  the NULL vertex is a point in 3D space behind the center of the          */
/*  triangulation, and that the bounding triangles form a sort of cone.      */
/*                                                                           */
/*  This bounding box makes it easy to represent degenerate cases.  For      */
/*  instance, the triangulation of two vertices is a single edge.  This edge */
/*  is represented by two bounding box triangles, one on each "side" of the  */
/*  edge.  These triangles are also linked together in a fan about the NULL  */
/*  vertex.                                                                  */
/*                                                                           */
/*  The bounding box also makes it easy to traverse the convex hull, as the  */
/*  divide-and-conquer algorithm needs to do.                                */
/*                                                                           */
/*****************************************************************************/

/*****************************************************************************/
/*                                                                           */
/*  pointsort()   Sort an array of points by x-coordinate, using the         */
/*                y-coordinate as a secondary key.                           */
/*                                                                           */
/*  Uses quicksort.  Randomized O(n log n) time.  No, I did not make any of  */
/*  the usual quicksort mistakes.                                            */
/*                                                                           */
/*****************************************************************************/

void mesh2d::pointsort(point *sortarray, int arraysize)
{
  int left, right;
  int pivot;
  REAL pivotx, pivoty;
  point temp;

  if (arraysize == 2) {
    /* Recursive base case. */
    if ((sortarray[0][0] > sortarray[1][0]) ||
        ((sortarray[0][0] == sortarray[1][0]) &&
         (sortarray[0][1] > sortarray[1][1]))) {
      temp = sortarray[1];
      sortarray[1] = sortarray[0];
      sortarray[0] = temp;
    }
    return;
  }
  /* Choose a random pivot to split the array. */
  pivot = (int) randomnation(arraysize);
  pivotx = sortarray[pivot][0];
  pivoty = sortarray[pivot][1];
  /* Split the array. */
  left = -1;
  right = arraysize;
  while (left < right) {
    /* Search for a point whose x-coordinate is too large for the left. */
    do {
      left++;
    } while ((left <= right) && ((sortarray[left][0] < pivotx) ||
                                 ((sortarray[left][0] == pivotx) &&
                                  (sortarray[left][1] < pivoty))));
    /* Search for a point whose x-coordinate is too small for the right. */
    do {
      right--;
    } while ((left <= right) && ((sortarray[right][0] > pivotx) ||
                                 ((sortarray[right][0] == pivotx) &&
                                  (sortarray[right][1] > pivoty))));
    if (left < right) {
      /* Swap the left and right points. */
      temp = sortarray[left];
      sortarray[left] = sortarray[right];
      sortarray[right] = temp;
    }
  }
  if (left > 1) {
    /* Recursively sort the left subset. */
    pointsort(sortarray, left);
  }
  if (right < arraysize - 2) {
    /* Recursively sort the right subset. */
    pointsort(&sortarray[right + 1], arraysize - right - 1);
  }
}

/*****************************************************************************/
/*                                                                           */
/*  pointmedian()   An order statistic algorithm, almost.  Shuffles an array */
/*                  of points so that the first `median' points occur        */
/*                  lexicographically before the remaining points.           */
/*                                                                           */
/*  Uses the x-coordinate as the primary key if axis == 0; the y-coordinate  */
/*  if axis == 1.  Very similar to the pointsort() procedure, but runs in    */
/*  randomized linear time.                                                  */
/*                                                                           */
/*****************************************************************************/

void mesh2d::pointmedian(point *sortarray, int arraysize, int median, int axis)
{
  int left, right;
  int pivot;
  REAL pivot1, pivot2;
  point temp;

  if (arraysize == 2) {
    /* Recursive base case. */
    if ((sortarray[0][axis] > sortarray[1][axis]) ||
        ((sortarray[0][axis] == sortarray[1][axis]) &&
         (sortarray[0][1 - axis] > sortarray[1][1 - axis]))) {
      temp = sortarray[1];
      sortarray[1] = sortarray[0];
      sortarray[0] = temp;
    }
    return;
  }
  /* Choose a random pivot to split the array. */
  pivot = (int) randomnation(arraysize);
  pivot1 = sortarray[pivot][axis];
  pivot2 = sortarray[pivot][1 - axis];
  /* Split the array. */
  left = -1;
  right = arraysize;
  while (left < right) {
    /* Search for a point whose x-coordinate is too large for the left. */
    do {
      left++;
    } while ((left <= right) && ((sortarray[left][axis] < pivot1) ||
                                 ((sortarray[left][axis] == pivot1) &&
                                  (sortarray[left][1 - axis] < pivot2))));
    /* Search for a point whose x-coordinate is too small for the right. */
    do {
      right--;
    } while ((left <= right) && ((sortarray[right][axis] > pivot1) ||
                                 ((sortarray[right][axis] == pivot1) &&
                                  (sortarray[right][1 - axis] > pivot2))));
    if (left < right) {
      /* Swap the left and right points. */
      temp = sortarray[left];
      sortarray[left] = sortarray[right];
      sortarray[right] = temp;
    }
  }
  /* Unlike in pointsort(), at most one of the following */
  /*   conditionals is true.                             */
  if (left > median) {
    /* Recursively shuffle the left subset. */
    pointmedian(sortarray, left, median, axis);
  }
  if (right < median - 1) {
    /* Recursively shuffle the right subset. */
    pointmedian(&sortarray[right + 1], arraysize - right - 1,
                median - right - 1, axis);
  }
}

/*****************************************************************************/
/*                                                                           */
/*  alternateaxes()   Sorts the points as appropriate for the divide-and-    */
/*                    conquer algorithm with alternating cuts.               */
/*                                                                           */
/*  Partitions by x-coordinate if axis == 0; by y-coordinate if axis == 1.   */
/*  For the base case, subsets containing only two or three points are       */
/*  always sorted by x-coordinate.                                           */
/*                                                                           */
/*****************************************************************************/

void mesh2d::alternateaxes(point *sortarray, int arraysize, int axis)
{
  int divider;

  divider = arraysize >> 1;
  if (arraysize <= 3) {
    /* Recursive base case:  subsets of two or three points will be      */
    /*   handled specially, and should always be sorted by x-coordinate. */
    axis = 0;
  }
  /* Partition with a horizontal or vertical cut. */
  pointmedian(sortarray, arraysize, divider, axis);
  /* Recursively partition the subsets with a cross cut. */
  if (arraysize - divider >= 2) {
    if (divider >= 2) {
      alternateaxes(sortarray, divider, 1 - axis);
    }
    alternateaxes(&sortarray[divider], arraysize - divider, 1 - axis);
  }
}

/*****************************************************************************/
/*                                                                           */
/*  mergehulls()   Merge two adjacent Delaunay triangulations into a         */
/*                 single Delaunay triangulation.                            */
/*                                                                           */
/*  This is similar to the algorithm given by Guibas and Stolfi, but uses    */
/*  a triangle-based, rather than edge-based, data structure.                */
/*                                                                           */
/*  The algorithm walks up the gap between the two triangulations, knitting  */
/*  them together.  As they are merged, some of their bounding triangles     */
/*  are converted into real triangles of the triangulation.  The procedure   */
/*  pulls each hull's bounding triangles apart, then knits them together     */
/*  like the teeth of two gears.  The Delaunay property determines, at each  */
/*  step, whether the next "tooth" is a bounding triangle of the left hull   */
/*  or the right.  When a bounding triangle becomes real, its apex is        */
/*  changed from NULL to a real point.                                       */
/*                                                                           */
/*  Only two new triangles need to be allocated.  These become new bounding  */
/*  triangles at the top and bottom of the seam.  They are used to connect   */
/*  the remaining bounding triangles (those that have not been converted     */
/*  into real triangles) into a single fan.                                  */
/*                                                                           */
/*  On entry, `farleft' and `innerleft' are bounding triangles of the left   */
/*  triangulation.  The origin of `farleft' is the leftmost vertex, and      */
/*  the destination of `innerleft' is the rightmost vertex of the            */
/*  triangulation.  Similarly, `innerright' and `farright' are bounding      */
/*  triangles of the right triangulation.  The origin of `innerright' and    */
/*  destination of `farright' are the leftmost and rightmost vertices.       */
/*                                                                           */
/*  On completion, the origin of `farleft' is the leftmost vertex of the     */
/*  merged triangulation, and the destination of `farright' is the rightmost */
/*  vertex.                                                                  */
/*                                                                           */
/*****************************************************************************/

void mesh2d::mergehulls(struct triedge *farleft, struct triedge *innerleft,
                        struct triedge *innerright, struct triedge *farright,
                        int axis)
{
  struct triedge leftcand, rightcand;
  struct triedge baseedge;
  struct triedge nextedge;
  struct triedge sidecasing, topcasing, outercasing;
  struct triedge checkedge;
  point innerleftdest;
  point innerrightorg;
  point innerleftapex, innerrightapex;
  point farleftpt, farrightpt;
  point farleftapex, farrightapex;
  point lowerleft, lowerright;
  point upperleft, upperright;
  point nextapex;
  point checkvertex;
  int changemade;
  int badedge;
  int leftfinished, rightfinished;
  triangle ptr;                         /* Temporary variable used by sym(). */

  dest(*innerleft, innerleftdest);
  apex(*innerleft, innerleftapex);
  org(*innerright, innerrightorg);
  apex(*innerright, innerrightapex);
  /* Special treatment for horizontal cuts. */
  if (dwyer && (axis == 1)) {
    org(*farleft, farleftpt);
    apex(*farleft, farleftapex);
    dest(*farright, farrightpt);
    apex(*farright, farrightapex);
    /* The pointers to the extremal points are shifted to point to the */
    /*   topmost and bottommost point of each hull, rather than the    */
    /*   leftmost and rightmost points.                                */
    while (farleftapex[1] < farleftpt[1]) {
      lnextself(*farleft);
      symself(*farleft);
      farleftpt = farleftapex;
      apex(*farleft, farleftapex);
    }
    sym(*innerleft, checkedge);
    apex(checkedge, checkvertex);
    while (checkvertex[1] > innerleftdest[1]) {
      lnext(checkedge, *innerleft);
      innerleftapex = innerleftdest;
      innerleftdest = checkvertex;
      sym(*innerleft, checkedge);
      apex(checkedge, checkvertex);
    }
    while (innerrightapex[1] < innerrightorg[1]) {
      lnextself(*innerright);
      symself(*innerright);
      innerrightorg = innerrightapex;
      apex(*innerright, innerrightapex);
    }
    sym(*farright, checkedge);
    apex(checkedge, checkvertex);
    while (checkvertex[1] > farrightpt[1]) {
      lnext(checkedge, *farright);
      farrightapex = farrightpt;
      farrightpt = checkvertex;
      sym(*farright, checkedge);
      apex(checkedge, checkvertex);
    }
  }
  /* Find a line tangent to and below both hulls. */
  do {
    changemade = 0;
    /* Make innerleftdest the "bottommost" point of the left hull. */
    if (counterclockwise(innerleftdest, innerleftapex, innerrightorg) > 0.0) {
      lprevself(*innerleft);
      symself(*innerleft);
      innerleftdest = innerleftapex;
      apex(*innerleft, innerleftapex);
      changemade = 1;
    }
    /* Make innerrightorg the "bottommost" point of the right hull. */
    if (counterclockwise(innerrightapex, innerrightorg, innerleftdest) > 0.0) {
      lnextself(*innerright);
      symself(*innerright);
      innerrightorg = innerrightapex;
      apex(*innerright, innerrightapex);
      changemade = 1;
    }
  } while (changemade);
  /* Find the two candidates to be the next "gear tooth". */
  sym(*innerleft, leftcand);
  sym(*innerright, rightcand);
  /* Create the bottom new bounding triangle. */
  maketriangle(&baseedge);
  /* Connect it to the bounding boxes of the left and right triangulations. */
  bond(baseedge, *innerleft);
  lnextself(baseedge);
  bond(baseedge, *innerright);
  lnextself(baseedge);
  setorg(baseedge, innerrightorg);
  setdest(baseedge, innerleftdest);
  /* Apex is intentionally left NULL. */
  if (verbose > 2) {
    printf("  Creating base bounding ");
    printtriangle(&baseedge);
  }
  /* Fix the extreme triangles if necessary. */
  org(*farleft, farleftpt);
  if (innerleftdest == farleftpt) {
    lnext(baseedge, *farleft);
  }
  dest(*farright, farrightpt);
  if (innerrightorg == farrightpt) {
    lprev(baseedge, *farright);
  }
  /* The vertices of the current knitting edge. */
  lowerleft = innerleftdest;
  lowerright = innerrightorg;
  /* The candidate vertices for knitting. */
  apex(leftcand, upperleft);
  apex(rightcand, upperright);
  /* Walk up the gap between the two triangulations, knitting them together. */
  while (1) {
    /* Have we reached the top?  (This isn't quite the right question,       */
    /*   because even though the left triangulation might seem finished now, */
    /*   moving up on the right triangulation might reveal a new point of    */
    /*   the left triangulation.  And vice-versa.)                           */
    leftfinished = counterclockwise(upperleft, lowerleft, lowerright) <= 0.0;
    rightfinished = counterclockwise(upperright, lowerleft, lowerright) <= 0.0;
    if (leftfinished && rightfinished) {
      /* Create the top new bounding triangle. */
      maketriangle(&nextedge);
      setorg(nextedge, lowerleft);
      setdest(nextedge, lowerright);
      /* Apex is intentionally left NULL. */
      /* Connect it to the bounding boxes of the two triangulations. */
      bond(nextedge, baseedge);
      lnextself(nextedge);
      bond(nextedge, rightcand);
      lnextself(nextedge);
      bond(nextedge, leftcand);
      if (verbose > 2) {
        printf("  Creating top bounding ");
        printtriangle(&baseedge);
      }
      /* Special treatment for horizontal cuts. */
      if (dwyer && (axis == 1)) {
        org(*farleft, farleftpt);
        apex(*farleft, farleftapex);
        dest(*farright, farrightpt);
        apex(*farright, farrightapex);
        sym(*farleft, checkedge);
        apex(checkedge, checkvertex);
        /* The pointers to the extremal points are restored to the leftmost */
        /*   and rightmost points (rather than topmost and bottommost).     */
        while (checkvertex[0] < farleftpt[0]) {
          lprev(checkedge, *farleft);
          farleftapex = farleftpt;
          farleftpt = checkvertex;
          sym(*farleft, checkedge);
          apex(checkedge, checkvertex);
        }
        while (farrightapex[0] > farrightpt[0]) {
          lprevself(*farright);
          symself(*farright);
          farrightpt = farrightapex;
          apex(*farright, farrightapex);
        }
      }
      return;
    }
    /* Consider eliminating edges from the left triangulation. */
    if (!leftfinished) {
      /* What vertex would be exposed if an edge were deleted? */
      lprev(leftcand, nextedge);
      symself(nextedge);
      apex(nextedge, nextapex);
      /* If nextapex is NULL, then no vertex would be exposed; the */
      /*   triangulation would have been eaten right through.      */
      if (nextapex != (point) NULL) {
        /* Check whether the edge is Delaunay. */
        badedge = iincircle(lowerleft, lowerright, upperleft, nextapex) > 0.0;
        while (badedge) {
          /* Eliminate the edge with an edge flip.  As a result, the    */
          /*   left triangulation will have one more boundary triangle. */
          lnextself(nextedge);
          sym(nextedge, topcasing);
          lnextself(nextedge);
          sym(nextedge, sidecasing);
          bond(nextedge, topcasing);
          bond(leftcand, sidecasing);
          lnextself(leftcand);
          sym(leftcand, outercasing);
          lprevself(nextedge);
          bond(nextedge, outercasing);
          /* Correct the vertices to reflect the edge flip. */
          setorg(leftcand, lowerleft);
          setdest(leftcand, NULL);
          setapex(leftcand, nextapex);
          setorg(nextedge, NULL);
          setdest(nextedge, upperleft);
          setapex(nextedge, nextapex);
          /* Consider the newly exposed vertex. */
          upperleft = nextapex;
          /* What vertex would be exposed if another edge were deleted? */
          triedgecopy(sidecasing, nextedge);
          apex(nextedge, nextapex);
          if (nextapex != (point) NULL) {
            /* Check whether the edge is Delaunay. */
            badedge = iincircle(lowerleft, lowerright, upperleft, nextapex)
                      > 0.0;
          } else {
            /* Avoid eating right through the triangulation. */
            badedge = 0;
          }
        }
      }
    }
    /* Consider eliminating edges from the right triangulation. */
    if (!rightfinished) {
      /* What vertex would be exposed if an edge were deleted? */
      lnext(rightcand, nextedge);
      symself(nextedge);
      apex(nextedge, nextapex);
      /* If nextapex is NULL, then no vertex would be exposed; the */
      /*   triangulation would have been eaten right through.      */
      if (nextapex != (point) NULL) {
        /* Check whether the edge is Delaunay. */
        badedge = iincircle(lowerleft, lowerright, upperright, nextapex) > 0.0;
        while (badedge) {
          /* Eliminate the edge with an edge flip.  As a result, the     */
          /*   right triangulation will have one more boundary triangle. */
          lprevself(nextedge);
          sym(nextedge, topcasing);
          lprevself(nextedge);
          sym(nextedge, sidecasing);
          bond(nextedge, topcasing);
          bond(rightcand, sidecasing);
          lprevself(rightcand);
          sym(rightcand, outercasing);
          lnextself(nextedge);
          bond(nextedge, outercasing);
          /* Correct the vertices to reflect the edge flip. */
          setorg(rightcand, NULL);
          setdest(rightcand, lowerright);
          setapex(rightcand, nextapex);
          setorg(nextedge, upperright);
          setdest(nextedge, NULL);
          setapex(nextedge, nextapex);
          /* Consider the newly exposed vertex. */
          upperright = nextapex;
          /* What vertex would be exposed if another edge were deleted? */
          triedgecopy(sidecasing, nextedge);
          apex(nextedge, nextapex);
          if (nextapex != (point) NULL) {
            /* Check whether the edge is Delaunay. */
            badedge = iincircle(lowerleft, lowerright, upperright, nextapex)
                      > 0.0;
          } else {
            /* Avoid eating right through the triangulation. */
            badedge = 0;
          }
        }
      }
    }
    if (leftfinished || (!rightfinished &&
           (iincircle(upperleft, lowerleft, lowerright, upperright) > 0.0))) {
      /* Knit the triangulations, adding an edge from `lowerleft' */
      /*   to `upperright'.                                       */
      bond(baseedge, rightcand);
      lprev(rightcand, baseedge);
      setdest(baseedge, lowerleft);
      lowerright = upperright;
      sym(baseedge, rightcand);
      apex(rightcand, upperright);
    } else {
      /* Knit the triangulations, adding an edge from `upperleft' */
      /*   to `lowerright'.                                       */
      bond(baseedge, leftcand);
      lnext(leftcand, baseedge);
      setorg(baseedge, lowerright);
      lowerleft = upperleft;
      sym(baseedge, leftcand);
      apex(leftcand, upperleft);
    }
    if (verbose > 2) {
      printf("  Connecting ");
      printtriangle(&baseedge);
    }
  }
}

/*****************************************************************************/
/*                                                                           */
/*  divconqrecurse()   Recursively form a Delaunay triangulation by the      */
/*                     divide-and-conquer method.                            */
/*                                                                           */
/*  Recursively breaks down the problem into smaller pieces, which are       */
/*  knitted together by mergehulls().  The base cases (problems of two or    */
/*  three points) are handled specially here.                                */
/*                                                                           */
/*  On completion, `farleft' and `farright' are bounding triangles such that */
/*  the origin of `farleft' is the leftmost vertex (breaking ties by         */
/*  choosing the highest leftmost vertex), and the destination of            */
/*  `farright' is the rightmost vertex (breaking ties by choosing the        */
/*  lowest rightmost vertex).                                                */
/*                                                                           */
/*****************************************************************************/

void mesh2d::divconqrecurse(point *sortarray, int vertices, int axis,
                            struct triedge *farleft, struct triedge *farright)
{
  struct triedge midtri, tri1, tri2, tri3;
  struct triedge innerleft, innerright;
  REAL area;
  int divider;

  if (verbose > 2) {
    printf("  Triangulating %d points.\n", vertices);
  }
  if (vertices == 2) {
    /* The triangulation of two vertices is an edge.  An edge is */
    /*   represented by two bounding triangles.                  */
    maketriangle(farleft);
    setorg(*farleft, sortarray[0]);
    setdest(*farleft, sortarray[1]);
    /* The apex is intentionally left NULL. */
    maketriangle(farright);
    setorg(*farright, sortarray[1]);
    setdest(*farright, sortarray[0]);
    /* The apex is intentionally left NULL. */
    bond(*farleft, *farright);
    lprevself(*farleft);
    lnextself(*farright);
    bond(*farleft, *farright);
    lprevself(*farleft);
    lnextself(*farright);
    bond(*farleft, *farright);
    if (verbose > 2) {
      printf("  Creating ");
      printtriangle(farleft);
      printf("  Creating ");
      printtriangle(farright);
    }
    /* Ensure that the origin of `farleft' is sortarray[0]. */
    lprev(*farright, *farleft);
    return;
  } else if (vertices == 3) {
    /* The triangulation of three vertices is either a triangle (with */
    /*   three bounding triangles) or two edges (with four bounding   */
    /*   triangles).  In either case, four triangles are created.     */
    maketriangle(&midtri);
    maketriangle(&tri1);
    maketriangle(&tri2);
    maketriangle(&tri3);
    area = counterclockwise(sortarray[0], sortarray[1], sortarray[2]);
    if (area == 0.0) {
      /* Three collinear points; the triangulation is two edges. */
      setorg(midtri, sortarray[0]);
      setdest(midtri, sortarray[1]);
      setorg(tri1, sortarray[1]);
      setdest(tri1, sortarray[0]);
      setorg(tri2, sortarray[2]);
      setdest(tri2, sortarray[1]);
      setorg(tri3, sortarray[1]);
      setdest(tri3, sortarray[2]);
      /* All apices are intentionally left NULL. */
      bond(midtri, tri1);
      bond(tri2, tri3);
      lnextself(midtri);
      lprevself(tri1);
      lnextself(tri2);
      lprevself(tri3);
      bond(midtri, tri3);
      bond(tri1, tri2);
      lnextself(midtri);
      lprevself(tri1);
      lnextself(tri2);
      lprevself(tri3);
      bond(midtri, tri1);
      bond(tri2, tri3);
      /* Ensure that the origin of `farleft' is sortarray[0]. */
      triedgecopy(tri1, *farleft);
      /* Ensure that the destination of `farright' is sortarray[2]. */
      triedgecopy(tri2, *farright);
    } else {
      /* The three points are not collinear; the triangulation is one */
      /*   triangle, namely `midtri'.                                 */
      setorg(midtri, sortarray[0]);
      setdest(tri1, sortarray[0]);
      setorg(tri3, sortarray[0]);
      /* Apices of tri1, tri2, and tri3 are left NULL. */
      if (area > 0.0) {
        /* The vertices are in counterclockwise order. */
        setdest(midtri, sortarray[1]);
        setorg(tri1, sortarray[1]);
        setdest(tri2, sortarray[1]);
        setapex(midtri, sortarray[2]);
        setorg(tri2, sortarray[2]);
        setdest(tri3, sortarray[2]);
      } else {
        /* The vertices are in clockwise order. */
        setdest(midtri, sortarray[2]);
        setorg(tri1, sortarray[2]);
        setdest(tri2, sortarray[2]);
        setapex(midtri, sortarray[1]);
        setorg(tri2, sortarray[1]);
        setdest(tri3, sortarray[1]);
      }
      /* The topology does not depend on how the vertices are ordered. */
      bond(midtri, tri1);
      lnextself(midtri);
      bond(midtri, tri2);
      lnextself(midtri);
      bond(midtri, tri3);
      lprevself(tri1);
      lnextself(tri2);
      bond(tri1, tri2);
      lprevself(tri1);
      lprevself(tri3);
      bond(tri1, tri3);
      lnextself(tri2);
      lprevself(tri3);
      bond(tri2, tri3);
      /* Ensure that the origin of `farleft' is sortarray[0]. */
      triedgecopy(tri1, *farleft);
      /* Ensure that the destination of `farright' is sortarray[2]. */
      if (area > 0.0) {
        triedgecopy(tri2, *farright);
      } else {
        lnext(*farleft, *farright);
      }
    }
    if (verbose > 2) {
      printf("  Creating ");
      printtriangle(&midtri);
      printf("  Creating ");
      printtriangle(&tri1);
      printf("  Creating ");
      printtriangle(&tri2);
      printf("  Creating ");
      printtriangle(&tri3);
    }
    return;
  } else {
    /* Split the vertices in half. */
    divider = vertices >> 1;
    /* Recursively triangulate each half. */
    divconqrecurse(sortarray, divider, 1 - axis, farleft, &innerleft);
    divconqrecurse(&sortarray[divider], vertices - divider, 1 - axis,
                   &innerright, farright);
    if (verbose > 1) {
      printf("  Joining triangulations with %d and %d vertices.\n", divider,
             vertices - divider);
    }
    /* Merge the two triangulations into one. */
    mergehulls(farleft, &innerleft, &innerright, farright, axis);
  }
}

long mesh2d::removeghosts(struct triedge *startghost)
{
  struct triedge searchedge;
  struct triedge dissolveedge;
  struct triedge deadtri;
  point markorg;
  long hullsize;
  triangle ptr;                         /* Temporary variable used by sym(). */

  if (verbose) {
    printf("  Removing ghost triangles.\n");
  }
  /* Find an edge on the convex hull to start point location from. */
  lprev(*startghost, searchedge);
  symself(searchedge);
  dummytri[0] = encode(searchedge);
  /* Remove the bounding box and count the convex hull edges. */
  triedgecopy(*startghost, dissolveedge);
  hullsize = 0;
  do {
    hullsize++;
    lnext(dissolveedge, deadtri);
    lprevself(dissolveedge);
    symself(dissolveedge);
    /* If no PSLG is involved, set the boundary markers of all the points */
    /*   on the convex hull.  If a PSLG is used, this step is done later. */
    if (!poly) {
      /* Watch out for the case where all the input points are collinear. */
      if (dissolveedge.tri != dummytri) {
        org(dissolveedge, markorg);
        if (pointmark(markorg) == 0) {
          setpointmark(markorg, 1);
        }
      }
    }
    /* Remove a bounding triangle from a convex hull triangle. */
    dissolve(dissolveedge);
    /* Find the next bounding triangle. */
    sym(deadtri, dissolveedge);
    /* Delete the bounding triangle. */
    triangledealloc(deadtri.tri);
  } while (!triedgeequal(dissolveedge, *startghost));
  return hullsize;
}

/*****************************************************************************/
/*                                                                           */
/*  divconqdelaunay()   Form a Delaunay triangulation by the divide-and-     */
/*                      conquer method.                                      */
/*                                                                           */
/*  Sorts the points, calls a recursive procedure to triangulate them, and   */
/*  removes the bounding box, setting boundary markers as appropriate.       */
/*                                                                           */
/*****************************************************************************/

long mesh2d::divconqdelaunay()
{
  point *sortarray;
  struct triedge hullleft, hullright;
  int divider;
  int i, j;

  /* Allocate an array of pointers to points for sorting. */
  sortarray = (point *) new point[inpoints];
  if (sortarray == (point *) NULL) {
    printf("Error:  Out of memory.\n");
    exit(1);
  }
  points.traversalinit();
  for (i = 0; i < inpoints; i++) {
    sortarray[i] = pointtraverse();
  }
  if (verbose) {
    printf("  Sorting points.\n");
  }
  /* Sort the points. */
  pointsort(sortarray, inpoints);
  /* Discard duplicate points, which can really mess up the algorithm. */
  i = 0;
  for (j = 1; j < inpoints; j++) {
    if ((sortarray[i][0] == sortarray[j][0])
        && (sortarray[i][1] == sortarray[j][1])) {
      if (!quiet) {
        printf(
"Warning:  A duplicate point at (%.12g, %.12g) appeared and was ignored.\n",
               sortarray[j][0], sortarray[j][1]);
      }
/*  Commented out - would eliminate point from output .node file, but causes
    a failure if some segment has this point as an endpoint.
      setpointmark(sortarray[j], DEADPOINT);
*/
    } else {
      i++;
      sortarray[i] = sortarray[j];
    }
  }
  i++;
  if (dwyer) {
    /* Re-sort the array of points to accommodate alternating cuts. */
    divider = i >> 1;
    if (i - divider >= 2) {
      if (divider >= 2) {
        alternateaxes(sortarray, divider, 1);
      }
      alternateaxes(&sortarray[divider], i - divider, 1);
    }
  }
  if (verbose) {
    printf("  Forming triangulation.\n");
  }
  /* Form the Delaunay triangulation. */
  divconqrecurse(sortarray, i, 0, &hullleft, &hullright);
  delete [] sortarray;

  return removeghosts(&hullleft);
}

/**                                                                         **/
/**                                                                         **/
/********* Divide-and-conquer Delaunay triangulation ends here       *********/

/********* General mesh construction routines begin here             *********/
/**                                                                         **/
/**                                                                         **/

/*****************************************************************************/
/*                                                                           */
/*  delaunay()   Form a Delaunay triangulation.                              */
/*                                                                           */
/*****************************************************************************/

long mesh2d::delaunay()
{
  eextras = 0;
  if (!restartsymbol) {
    initializetrisegpools();
  }
  if (!quiet) {
    printf("Constructing Delaunay triangulation ");
    if (incremental) {
      printf("by incremental method.\n");
    } else if (sweepline) {
      printf("by sweepline method.\n");
    } else {
      printf("by divide-and-conquer method.\n");
    }
  }
  if (incremental) {
    // return incrementaldelaunay();
    printf("Sorry, the incremental delaunay algorithm have not");
    printf(" been transformed.\n");
    exit(1);
  } else if (sweepline) {
    // return sweeplinedelaunay();
    printf("Sorry, the sweepline delaunay algorithm have not");
    printf(" been transformed.\n");
    exit(1);
  } else {
    return divconqdelaunay();
  }
  return 0;
}

/**                                                                         **/
/**                                                                         **/
/********* General mesh construction routines end here               *********/

/********* Segment (shell edge) insertion begins here                *********/
/**                                                                         **/
/**                                                                         **/

/*****************************************************************************/
/*                                                                           */
/*  finddirection()   Find the first triangle on the path from one point     */
/*                    to another.                                            */
/*                                                                           */
/*  Finds the triangle that intersects a line segment drawn from the         */
/*  origin of `searchtri' to the point `endpoint', and returns the result    */
/*  in `searchtri'.  The origin of `searchtri' does not change, even though  */
/*  the triangle returned may differ from the one passed in.  This routine   */
/*  is used to find the direction to move in to get from one point to        */
/*  another.                                                                 */
/*                                                                           */
/*  The return value notes whether the destination or apex of the found      */
/*  triangle is collinear with the two points in question.                   */
/*                                                                           */
/*****************************************************************************/

enum mesh2d::finddirectionresult
mesh2d::finddirection(struct triedge *searchtri, point endpoint)
{
  struct triedge checktri;
  point startpoint;
  point leftpoint, rightpoint;
  REAL leftccw, rightccw;
  int leftflag, rightflag;
  triangle ptr;           /* Temporary variable used by onext() and oprev(). */

  org(*searchtri, startpoint);
  dest(*searchtri, rightpoint);
  apex(*searchtri, leftpoint);
  /* Is `endpoint' to the left? */
  leftccw = counterclockwise(endpoint, startpoint, leftpoint);
  leftflag = leftccw > 0.0;
  /* Is `endpoint' to the right? */
  rightccw = counterclockwise(startpoint, endpoint, rightpoint);
  rightflag = rightccw > 0.0;
  if (leftflag && rightflag) {
    /* `searchtri' faces directly away from `endpoint'.  We could go */
    /*   left or right.  Ask whether it's a triangle or a boundary   */
    /*   on the left.                                                */
    onext(*searchtri, checktri);
    if (checktri.tri == dummytri) {
      leftflag = 0;
    } else {
      rightflag = 0;
    }
  }
  while (leftflag) {
    /* Turn left until satisfied. */
    onextself(*searchtri);
    if (searchtri->tri == dummytri) {
      printf("Internal error in finddirection():  Unable to find a\n");
      printf("  triangle leading from (%.12g, %.12g) to", startpoint[0],
             startpoint[1]);
      printf("  (%.12g, %.12g).\n", endpoint[0], endpoint[1]);
      internalerror();
    }
    apex(*searchtri, leftpoint);
    rightccw = leftccw;
    leftccw = counterclockwise(endpoint, startpoint, leftpoint);
    leftflag = leftccw > 0.0;
  }
  while (rightflag) {
    /* Turn right until satisfied. */
    oprevself(*searchtri);
    if (searchtri->tri == dummytri) {
      printf("Internal error in finddirection():  Unable to find a\n");
      printf("  triangle leading from (%.12g, %.12g) to", startpoint[0],
             startpoint[1]);
      printf("  (%.12g, %.12g).\n", endpoint[0], endpoint[1]);
      internalerror();
    }
    dest(*searchtri, rightpoint);
    leftccw = rightccw;
    rightccw = counterclockwise(startpoint, endpoint, rightpoint);
    rightflag = rightccw > 0.0;
  }
  if (leftccw == 0.0) {
    return LEFTCOLLINEAR;
  } else if (rightccw == 0.0) {
    return RIGHTCOLLINEAR;
  } else {
    return WITHIN;
  }
}

/*****************************************************************************/
/*                                                                           */
/*  segmentintersection()   Find the intersection of an existing segment     */
/*                          and a segment that is being inserted.  Insert    */
/*                          a point at the intersection, splitting an        */
/*                          existing shell edge.                             */
/*                                                                           */
/*  The segment being inserted connects the apex of splittri to endpoint2.   */
/*  splitshelle is the shell edge being split, and MUST be opposite          */
/*  splittri.  Hence, the edge being split connects the origin and           */
/*  destination of splittri.                                                 */
/*                                                                           */
/*  On completion, splittri is a handle having the newly inserted            */
/*  intersection point as its origin, and endpoint1 as its destination.      */
/*                                                                           */
/*****************************************************************************/

void mesh2d::
segmentintersection(struct triedge *splittri, struct edge *splitshelle,
                    point endpoint2)
{
  point endpoint1;
  point torg, tdest;
  point leftpoint, rightpoint;
  point newpoint;
  enum insertsiteresult success;
  enum finddirectionresult collinear;
  REAL ex, ey;
  REAL tx, ty;
  REAL etx, ety;
  REAL split, denom;
  int i;
  triangle ptr;                       /* Temporary variable used by onext(). */

  /* Find the other three segment endpoints. */
  apex(*splittri, endpoint1);
  org(*splittri, torg);
  dest(*splittri, tdest);
  /* Segment intersection formulae; see the Antonio reference. */
  tx = tdest[0] - torg[0];
  ty = tdest[1] - torg[1];
  ex = endpoint2[0] - endpoint1[0];
  ey = endpoint2[1] - endpoint1[1];
  etx = torg[0] - endpoint2[0];
  ety = torg[1] - endpoint2[1];
  denom = ty * ex - tx * ey;
  if (denom == 0.0) {
    printf("Internal error in segmentintersection():");
    printf("  Attempt to find intersection of parallel segments.\n");
    internalerror();
  }
  split = (ey * etx - ex * ety) / denom;
  /* Create the new point. */
  newpoint = (point) points.alloc();
  /* Interpolate its coordinate and attributes. */
  for (i = 0; i < 2 + nextras; i++) {
    newpoint[i] = torg[i] + split * (tdest[i] - torg[i]);
  }
  setpointmark(newpoint, mark(*splitshelle));
  if (verbose > 1) {
    printf(
    "  Splitting edge (%.12g, %.12g) (%.12g, %.12g) at (%.12g, %.12g).\n",
           torg[0], torg[1], tdest[0], tdest[1], newpoint[0], newpoint[1]);
  }
  /* Insert the intersection point.  This should always succeed. */
  success = insertsite(newpoint, splittri, splitshelle, 0, 0);
  if (success != SUCCESSFULPOINT) {
    printf("Internal error in segmentintersection():\n");
    printf("  Failure to split a segment.\n");
    internalerror();
  }
  if (steinerleft > 0) {
    steinerleft--;
  }
  /* Inserting the point may have caused edge flips.  We wish to rediscover */
  /*   the edge connecting endpoint1 to the new intersection point.         */
  collinear = finddirection(splittri, endpoint1);
  dest(*splittri, rightpoint);
  apex(*splittri, leftpoint);
  if ((leftpoint[0] == endpoint1[0]) && (leftpoint[1] == endpoint1[1])) {
    onextself(*splittri);
  } else if ((rightpoint[0] != endpoint1[0]) ||
             (rightpoint[1] != endpoint1[1])) {
    printf("Internal error in segmentintersection():\n");
    printf("  Topological inconsistency after splitting a segment.\n");
    internalerror();
  }
  /* `splittri' should have destination endpoint1. */
}

/*****************************************************************************/
/*                                                                           */
/*  scoutsegment()   Scout the first triangle on the path from one endpoint  */
/*                   to another, and check for completion (reaching the      */
/*                   second endpoint), a collinear point, and the            */
/*                   intersection of two segments.                           */
/*                                                                           */
/*  Returns one if the entire segment is successfully inserted, and zero if  */
/*  the job must be finished by conformingedge() or constrainededge().       */
/*                                                                           */
/*  If the first triangle on the path has the second endpoint as its         */
/*  destination or apex, a shell edge is inserted and the job is done.       */
/*                                                                           */
/*  If the first triangle on the path has a destination or apex that lies on */
/*  the segment, a shell edge is inserted connecting the first endpoint to   */
/*  the collinear point, and the search is continued from the collinear      */
/*  point.                                                                   */
/*                                                                           */
/*  If the first triangle on the path has a shell edge opposite its origin,  */
/*  then there is a segment that intersects the segment being inserted.      */
/*  Their intersection point is inserted, splitting the shell edge.          */
/*                                                                           */
/*  Otherwise, return zero.                                                  */
/*                                                                           */
/*****************************************************************************/

int mesh2d::
scoutsegment(struct triedge *searchtri, point endpoint2, int newmark)
{
  struct triedge crosstri;
  struct edge crossedge;
  point leftpoint, rightpoint;
  point endpoint1;
  enum finddirectionresult collinear;
  shelle sptr;                      /* Temporary variable used by tspivot(). */

  collinear = finddirection(searchtri, endpoint2);
  dest(*searchtri, rightpoint);
  apex(*searchtri, leftpoint);
  if (((leftpoint[0] == endpoint2[0]) && (leftpoint[1] == endpoint2[1])) ||
      ((rightpoint[0] == endpoint2[0]) && (rightpoint[1] == endpoint2[1]))) {
    /* The segment is already an edge in the mesh. */
    if ((leftpoint[0] == endpoint2[0]) && (leftpoint[1] == endpoint2[1])) {
      lprevself(*searchtri);
    }
    /* Insert a shell edge, if there isn't already one there. */
    insertshelle(searchtri, newmark);
    return 1;
  } else if (collinear == LEFTCOLLINEAR) {
    /* We've collided with a point between the segment's endpoints. */
    /* Make the collinear point be the triangle's origin. */
    lprevself(*searchtri);
    insertshelle(searchtri, newmark);
    /* Insert the remainder of the segment. */
    return scoutsegment(searchtri, endpoint2, newmark);
  } else if (collinear == RIGHTCOLLINEAR) {
    /* We've collided with a point between the segment's endpoints. */
    insertshelle(searchtri, newmark);
    /* Make the collinear point be the triangle's origin. */
    lnextself(*searchtri);
    /* Insert the remainder of the segment. */
    return scoutsegment(searchtri, endpoint2, newmark);
  } else {
    lnext(*searchtri, crosstri);
    tspivot(crosstri, crossedge);
    /* Check for a crossing segment. */
    if (crossedge.sh == dummysh) {
      return 0;
    } else {
      org(*searchtri, endpoint1);
      /* Insert a point at the intersection. */
      segmentintersection(&crosstri, &crossedge, endpoint2);
      triedgecopy(crosstri, *searchtri);
      insertshelle(searchtri, newmark);
      /* Insert the remainder of the segment. */
      return scoutsegment(searchtri, endpoint2, newmark);
    }
  }
}

/*****************************************************************************/
/*                                                                           */
/*  conformingedge()   Force a segment into a conforming Delaunay            */
/*                     triangulation by inserting a point at its midpoint,   */
/*                     and recursively forcing in the two half-segments if   */
/*                     necessary.                                            */
/*                                                                           */
/*  Generates a sequence of edges connecting `endpoint1' to `endpoint2'.     */
/*  `newmark' is the boundary marker of the segment, assigned to each new    */
/*  splitting point and shell edge.                                          */
/*                                                                           */
/*  Note that conformingedge() does not always maintain the conforming       */
/*  Delaunay property.  Once inserted, segments are locked into place;       */
/*  points inserted later (to force other segments in) may render these      */
/*  fixed segments non-Delaunay.  The conforming Delaunay property will be   */
/*  restored by enforcequality() by splitting encroached segments.           */
/*                                                                           */
/*****************************************************************************/

void mesh2d::conformingedge(point endpoint1, point endpoint2, int newmark)
{
  struct triedge searchtri1, searchtri2;
  struct edge brokenshelle;
  point newpoint;
  point midpoint1, midpoint2;
  enum insertsiteresult success;
  int result1, result2;
  int i;
  shelle sptr;                      /* Temporary variable used by tspivot(). */

  if (verbose > 2) {
    printf("Forcing segment into triangulation by recursive splitting:\n");
    printf("  (%.12g, %.12g) (%.12g, %.12g)\n", endpoint1[0], endpoint1[1],
           endpoint2[0], endpoint2[1]);
  }
  /* Create a new point to insert in the middle of the segment. */
  newpoint = (point) points.alloc();
  /* Interpolate coordinates and attributes. */
  for (i = 0; i < 2 + nextras; i++) {
    newpoint[i] = 0.5 * (endpoint1[i] + endpoint2[i]);
  }
  setpointmark(newpoint, newmark);
  /* Find a boundary triangle to search from. */
  searchtri1.tri = (triangle *) NULL;
  /* Attempt to insert the new point. */
  success = insertsite(newpoint, &searchtri1, (struct edge *) NULL, 0, 0);
  if (success == DUPLICATEPOINT) {
    if (verbose > 2) {
      printf("  Segment intersects existing point (%.12g, %.12g).\n",
             newpoint[0], newpoint[1]);
    }
    /* Use the point that's already there. */
    pointdealloc(newpoint);
    org(searchtri1, newpoint);
  } else {
    if (success == VIOLATINGPOINT) {
      if (verbose > 2) {
        printf("  Two segments intersect at (%.12g, %.12g).\n",
               newpoint[0], newpoint[1]);
      }
      /* By fluke, we've landed right on another segment.  Split it. */
      tspivot(searchtri1, brokenshelle);
      success = insertsite(newpoint, &searchtri1, &brokenshelle, 0, 0);
      if (success != SUCCESSFULPOINT) {
        printf("Internal error in conformingedge():\n");
        printf("  Failure to split a segment.\n");
        internalerror();
      }
    }
    /* The point has been inserted successfully. */
    if (steinerleft > 0) {
      steinerleft--;
    }
  }
  triedgecopy(searchtri1, searchtri2);
  result1 = scoutsegment(&searchtri1, endpoint1, newmark);
  result2 = scoutsegment(&searchtri2, endpoint2, newmark);
  if (!result1) {
    /* The origin of searchtri1 may have changed if a collision with an */
    /*   intervening vertex on the segment occurred.                    */
    org(searchtri1, midpoint1);
    conformingedge(midpoint1, endpoint1, newmark);
  }
  if (!result2) {
    /* The origin of searchtri2 may have changed if a collision with an */
    /*   intervening vertex on the segment occurred.                    */
    org(searchtri2, midpoint2);
    conformingedge(midpoint2, endpoint2, newmark);
  }
}

/*****************************************************************************/
/*                                                                           */
/*  delaunayfixup()   Enforce the Delaunay condition at an edge, fanning out */
/*                    recursively from an existing point.  Pay special       */
/*                    attention to stacking inverted triangles.              */
/*                                                                           */
/*  This is a support routine for inserting segments into a constrained      */
/*  Delaunay triangulation.                                                  */
/*                                                                           */
/*  The origin of fixuptri is treated as if it has just been inserted, and   */
/*  the local Delaunay condition needs to be enforced.  It is only enforced  */
/*  in one sector, however, that being the angular range defined by          */
/*  fixuptri.                                                                */
/*                                                                           */
/*  This routine also needs to make decisions regarding the "stacking" of    */
/*  triangles.  (Read the description of constrainededge() below before      */
/*  reading on here, so you understand the algorithm.)  If the position of   */
/*  the new point (the origin of fixuptri) indicates that the vertex before  */
/*  it on the polygon is a reflex vertex, then "stack" the triangle by       */
/*  doing nothing.  (fixuptri is an inverted triangle, which is how stacked  */
/*  triangles are identified.)                                               */
/*                                                                           */
/*  Otherwise, check whether the vertex before that was a reflex vertex.     */
/*  If so, perform an edge flip, thereby eliminating an inverted triangle    */
/*  (popping it off the stack).  The edge flip may result in the creation    */
/*  of a new inverted triangle, depending on whether or not the new vertex   */
/*  is visible to the vertex three edges behind on the polygon.              */
/*                                                                           */
/*  If neither of the two vertices behind the new vertex are reflex          */
/*  vertices, fixuptri and fartri, the triangle opposite it, are not         */
/*  inverted; hence, ensure that the edge between them is locally Delaunay.  */
/*                                                                           */
/*  `leftside' indicates whether or not fixuptri is to the left of the       */
/*  segment being inserted.  (Imagine that the segment is pointing up from   */
/*  endpoint1 to endpoint2.)                                                 */
/*                                                                           */
/*****************************************************************************/

void mesh2d::delaunayfixup(struct triedge *fixuptri, int leftside)
{
  struct triedge neartri;
  struct triedge fartri;
  struct edge faredge;
  point nearpoint, leftpoint, rightpoint, farpoint;
  triangle ptr;                         /* Temporary variable used by sym(). */
  shelle sptr;                      /* Temporary variable used by tspivot(). */

  lnext(*fixuptri, neartri);
  sym(neartri, fartri);
  /* Check if the edge opposite the origin of fixuptri can be flipped. */
  if (fartri.tri == dummytri) {
    return;
  }
  tspivot(neartri, faredge);
  if (faredge.sh != dummysh) {
    return;
  }
  /* Find all the relevant vertices. */
  apex(neartri, nearpoint);
  org(neartri, leftpoint);
  dest(neartri, rightpoint);
  apex(fartri, farpoint);
  /* Check whether the previous polygon vertex is a reflex vertex. */
  if (leftside) {
    if (counterclockwise(nearpoint, leftpoint, farpoint) <= 0.0) {
      /* leftpoint is a reflex vertex too.  Nothing can */
      /*   be done until a convex section is found.     */
      return;
    }
  } else {
    if (counterclockwise(farpoint, rightpoint, nearpoint) <= 0.0) {
      /* rightpoint is a reflex vertex too.  Nothing can */
      /*   be done until a convex section is found.      */
      return;
    }
  }
  if (counterclockwise(rightpoint, leftpoint, farpoint) > 0.0) {
    /* fartri is not an inverted triangle, and farpoint is not a reflex */
    /*   vertex.  As there are no reflex vertices, fixuptri isn't an    */
    /*   inverted triangle, either.  Hence, test the edge between the   */
    /*   triangles to ensure it is locally Delaunay.                    */
    if (iincircle(leftpoint, farpoint, rightpoint, nearpoint) <= 0.0) {
      return;
    }
    /* Not locally Delaunay; go on to an edge flip. */
  }        /* else fartri is inverted; remove it from the stack by flipping. */
  flip(&neartri);
  lprevself(*fixuptri);    /* Restore the origin of fixuptri after the flip. */
  /* Recursively process the two triangles that result from the flip. */
  delaunayfixup(fixuptri, leftside);
  delaunayfixup(&fartri, leftside);
}

/*****************************************************************************/
/*                                                                           */
/*  constrainededge()   Force a segment into a constrained Delaunay          */
/*                      triangulation by deleting the triangles it           */
/*                      intersects, and triangulating the polygons that      */
/*                      form on each side of it.                             */
/*                                                                           */
/*  Generates a single edge connecting `endpoint1' to `endpoint2'.  The      */
/*  triangle `starttri' has `endpoint1' as its origin.  `newmark' is the     */
/*  boundary marker of the segment.                                          */
/*                                                                           */
/*  To insert a segment, every triangle whose interior intersects the        */
/*  segment is deleted.  The union of these deleted triangles is a polygon   */
/*  (which is not necessarily monotone, but is close enough), which is       */
/*  divided into two polygons by the new segment.  This routine's task is    */
/*  to generate the Delaunay triangulation of these two polygons.            */
/*                                                                           */
/*  You might think of this routine's behavior as a two-step process.  The   */
/*  first step is to walk from endpoint1 to endpoint2, flipping each edge    */
/*  encountered.  This step creates a fan of edges connected to endpoint1,   */
/*  including the desired edge to endpoint2.  The second step enforces the   */
/*  Delaunay condition on each side of the segment in an incremental manner: */
/*  proceeding along the polygon from endpoint1 to endpoint2 (this is done   */
/*  independently on each side of the segment), each vertex is "enforced"    */
/*  as if it had just been inserted, but affecting only the previous         */
/*  vertices.  The result is the same as if the vertices had been inserted   */
/*  in the order they appear on the polygon, so the result is Delaunay.      */
/*                                                                           */
/*  In truth, constrainededge() interleaves these two steps.  The procedure  */
/*  walks from endpoint1 to endpoint2, and each time an edge is encountered  */
/*  and flipped, the newly exposed vertex (at the far end of the flipped     */
/*  edge) is "enforced" upon the previously flipped edges, usually affecting */
/*  only one side of the polygon (depending upon which side of the segment   */
/*  the vertex falls on).                                                    */
/*                                                                           */
/*  The algorithm is complicated by the need to handle polygons that are not */
/*  convex.  Although the polygon is not necessarily monotone, it can be     */
/*  triangulated in a manner similar to the stack-based algorithms for       */
/*  monotone polygons.  For each reflex vertex (local concavity) of the      */
/*  polygon, there will be an inverted triangle formed by one of the edge    */
/*  flips.  (An inverted triangle is one with negative area - that is, its   */
/*  vertices are arranged in clockwise order - and is best thought of as a   */
/*  wrinkle in the fabric of the mesh.)  Each inverted triangle can be       */
/*  thought of as a reflex vertex pushed on the stack, waiting to be fixed   */
/*  later.                                                                   */
/*                                                                           */
/*  A reflex vertex is popped from the stack when a vertex is inserted that  */
/*  is visible to the reflex vertex.  (However, if the vertex behind the     */
/*  reflex vertex is not visible to the reflex vertex, a new inverted        */
/*  triangle will take its place on the stack.)  These details are handled   */
/*  by the delaunayfixup() routine above.                                    */
/*                                                                           */
/*****************************************************************************/

void mesh2d::
constrainededge(struct triedge *starttri, point endpoint2, int newmark)
{
  struct triedge fixuptri, fixuptri2;
  struct edge fixupedge;
  point endpoint1;
  point farpoint;
  REAL area;
  int collision;
  int done;
  triangle ptr;             /* Temporary variable used by sym() and oprev(). */
  shelle sptr;                      /* Temporary variable used by tspivot(). */

  org(*starttri, endpoint1);
  lnext(*starttri, fixuptri);
  flip(&fixuptri);
  /* `collision' indicates whether we have found a point directly */
  /*   between endpoint1 and endpoint2.                           */
  collision = 0;
  done = 0;
  do {
    org(fixuptri, farpoint);
    /* `farpoint' is the extreme point of the polygon we are "digging" */
    /*   to get from endpoint1 to endpoint2.                           */
    if ((farpoint[0] == endpoint2[0]) && (farpoint[1] == endpoint2[1])) {
      oprev(fixuptri, fixuptri2);
      /* Enforce the Delaunay condition around endpoint2. */
      delaunayfixup(&fixuptri, 0);
      delaunayfixup(&fixuptri2, 1);
      done = 1;
    } else {
      /* Check whether farpoint is to the left or right of the segment */
      /*   being inserted, to decide which edge of fixuptri to dig     */
      /*   through next.                                               */
      area = counterclockwise(endpoint1, endpoint2, farpoint);
      if (area == 0.0) {
        /* We've collided with a point between endpoint1 and endpoint2. */
        collision = 1;
        oprev(fixuptri, fixuptri2);
        /* Enforce the Delaunay condition around farpoint. */
        delaunayfixup(&fixuptri, 0);
        delaunayfixup(&fixuptri2, 1);
        done = 1;
      } else {
        if (area > 0.0) {         /* farpoint is to the left of the segment. */
          oprev(fixuptri, fixuptri2);
          /* Enforce the Delaunay condition around farpoint, on the */
          /*   left side of the segment only.                       */
          delaunayfixup(&fixuptri2, 1);
          /* Flip the edge that crosses the segment.  After the edge is */
          /*   flipped, one of its endpoints is the fan vertex, and the */
          /*   destination of fixuptri is the fan vertex.               */
          lprevself(fixuptri);
        } else {                 /* farpoint is to the right of the segment. */
          delaunayfixup(&fixuptri, 0);
          /* Flip the edge that crosses the segment.  After the edge is */
          /*   flipped, one of its endpoints is the fan vertex, and the */
          /*   destination of fixuptri is the fan vertex.               */
          oprevself(fixuptri);
        }
        /* Check for two intersecting segments. */
        tspivot(fixuptri, fixupedge);
        if (fixupedge.sh == dummysh) {
          flip(&fixuptri);   /* May create an inverted triangle on the left. */
        } else {
          /* We've collided with a segment between endpoint1 and endpoint2. */
          collision = 1;
          /* Insert a point at the intersection. */
          segmentintersection(&fixuptri, &fixupedge, endpoint2);
          done = 1;
        }
      }
    }
  } while (!done);
  /* Insert a shell edge to make the segment permanent. */
  insertshelle(&fixuptri, newmark);
  /* If there was a collision with an interceding vertex, install another */
  /*   segment connecting that vertex with endpoint2.                     */
  if (collision) {
    /* Insert the remainder of the segment. */
    if (!scoutsegment(&fixuptri, endpoint2, newmark)) {
      constrainededge(&fixuptri, endpoint2, newmark);
    }
  }
}

/*****************************************************************************/
/*                                                                           */
/*  insertsegment()   Insert a PSLG segment into a triangulation.            */
/*                                                                           */
/*****************************************************************************/

void mesh2d::insertsegment(point endpoint1, point endpoint2, int newmark)
{
  struct triedge searchtri1, searchtri2;
  triangle encodedtri;
  point checkpoint;
  triangle ptr;                         /* Temporary variable used by sym(). */

  if (verbose > 1) {
    printf("  Connecting (%.12g, %.12g) to (%.12g, %.12g).\n",
           endpoint1[0], endpoint1[1], endpoint2[0], endpoint2[1]);
  }

  /* Find a triangle whose origin is the segment's first endpoint. */
  checkpoint = (point) NULL;
  encodedtri = point2tri(endpoint1);
  if (encodedtri != (triangle) NULL) {
    decode(encodedtri, searchtri1);
    org(searchtri1, checkpoint);
  }
  if (checkpoint != endpoint1) {
    /* Find a boundary triangle to search from. */
    searchtri1.tri = dummytri;
    searchtri1.orient = 0;
    symself(searchtri1);
    /* Search for the segment's first endpoint by point location. */
    if (locate(endpoint1, &searchtri1) != ONVERTEX) {
      printf(
        "Internal error in insertsegment():  Unable to locate PSLG point\n");
      printf("  (%.12g, %.12g) in triangulation.\n",
             endpoint1[0], endpoint1[1]);
      internalerror();
    }
  }
  /* Remember this triangle to improve subsequent point location. */
  triedgecopy(searchtri1, recenttri);
  /* Scout the beginnings of a path from the first endpoint */
  /*   toward the second.                                   */
  if (scoutsegment(&searchtri1, endpoint2, newmark)) {
    /* The segment was easily inserted. */
    return;
  }
  /* The first endpoint may have changed if a collision with an intervening */
  /*   vertex on the segment occurred.                                      */
  org(searchtri1, endpoint1);

  /* Find a triangle whose origin is the segment's second endpoint. */
  checkpoint = (point) NULL;
  encodedtri = point2tri(endpoint2);
  if (encodedtri != (triangle) NULL) {
    decode(encodedtri, searchtri2);
    org(searchtri2, checkpoint);
  }
  if (checkpoint != endpoint2) {
    /* Find a boundary triangle to search from. */
    searchtri2.tri = dummytri;
    searchtri2.orient = 0;
    symself(searchtri2);
    /* Search for the segment's second endpoint by point location. */
    if (locate(endpoint2, &searchtri2) != ONVERTEX) {
      printf(
        "Internal error in insertsegment():  Unable to locate PSLG point\n");
      printf("  (%.12g, %.12g) in triangulation.\n",
             endpoint2[0], endpoint2[1]);
      internalerror();
    }
  }
  /* Remember this triangle to improve subsequent point location. */
  triedgecopy(searchtri2, recenttri);
  /* Scout the beginnings of a path from the second endpoint */
  /*   toward the first.                                     */
  if (scoutsegment(&searchtri2, endpoint1, newmark)) {
    /* The segment was easily inserted. */
    return;
  }
  /* The second endpoint may have changed if a collision with an intervening */
  /*   vertex on the segment occurred.                                       */
  org(searchtri2, endpoint2);

  if (splitseg) {
    /* Insert vertices to force the segment into the triangulation. */
    conformingedge(endpoint1, endpoint2, newmark);
  } else {
    /* Insert the segment directly into the triangulation. */
    constrainededge(&searchtri1, endpoint2, newmark);
  }
}

/*****************************************************************************/
/*                                                                           */
/*  markhull()   Cover the convex hull of a triangulation with shell edges.  */
/*                                                                           */
/*****************************************************************************/

void mesh2d::markhull()
{
  struct triedge hulltri;
  struct triedge nexttri;
  struct triedge starttri;
  triangle ptr;             /* Temporary variable used by sym() and oprev(). */

  /* Find a triangle handle on the hull. */
  hulltri.tri = dummytri;
  hulltri.orient = 0;
  symself(hulltri);
  /* Remember where we started so we know when to stop. */
  triedgecopy(hulltri, starttri);
  /* Go once counterclockwise around the convex hull. */
  do {
    /* Create a shell edge if there isn't already one here. */
    insertshelle(&hulltri, 1);
    /* To find the next hull edge, go clockwise around the next vertex. */
    lnextself(hulltri);
    oprev(hulltri, nexttri);
    while (nexttri.tri != dummytri) {
      triedgecopy(nexttri, hulltri);
      oprev(hulltri, nexttri);
    }
  } while (!triedgeequal(hulltri, starttri));
}

/*****************************************************************************/
/*                                                                           */
/*  formskeleton()   Create the shell edges of a triangulation, including    */
/*                   PSLG edges and edges on the convex hull.                */
/*                                                                           */
/*  The PSLG edges are read from a .poly file.  The return value is the      */
/*  number of segments in the file.                                          */
/*                                                                           */
/*****************************************************************************/

int mesh2d::
formskeleton(int *segmentlist, int *segmentmarkerlist, int numberofsegments)
{
  char polyfilename[6];
  int index;
  point endpoint1, endpoint2;
  int segments;
  int segmentmarkers;
  int end1, end2;
  int boundmarker;
  int i;

  if (poly) {
    if (!quiet) {
      printf("Inserting segments into Delaunay triangulation.\n");
    }
    strcpy(polyfilename, "input");
    segments = numberofsegments;
    segmentmarkers = segmentmarkerlist != (int *) NULL;
    index = 0;
    /* If segments are to be inserted, compute a mapping */
    /*   from points to triangles.                       */
    if (segments > 0) {
      if (verbose) {
        printf("  Inserting PSLG segments.\n");
      }
      makepointmap();
    }

    boundmarker = 0;
    /* Read and insert the segments. */
    for (i = 1; i <= segments; i++) {
      end1 = segmentlist[index++];
      end2 = segmentlist[index++];
      if (segmentmarkers) {
        boundmarker = segmentmarkerlist[i - 1];
      }
      if ((end1 < firstnumber) || (end1 >= firstnumber + inpoints)) {
        if (!quiet) {
          printf("Warning:  Invalid first endpoint of segment %d in %s.\n", i,
                 polyfilename);
        }
      } else if ((end2 < firstnumber) || (end2 >= firstnumber + inpoints)) {
        if (!quiet) {
          printf("Warning:  Invalid second endpoint of segment %d in %s.\n", i,
                 polyfilename);
        }
      } else {
        endpoint1 = getpoint(end1);
        endpoint2 = getpoint(end2);
        if ((endpoint1[0] == endpoint2[0]) && (endpoint1[1] == endpoint2[1])) {
          if (!quiet) {
            printf("Warning:  Endpoints of segment %d are coincident in %s.\n",
                   i, polyfilename);
          }
        } else {
          insertsegment(endpoint1, endpoint2, boundmarker);
        }
      }
    }
  } else {
    segments = 0;
  }
  if (convex || !poly) {
    /* Enclose the convex hull with shell edges. */
    if (verbose) {
      printf("  Enclosing convex hull with segments.\n");
    }
    markhull();
  }
  return segments;
}

/**                                                                         **/
/**                                                                         **/
/********* Segment (shell edge) insertion ends here                  *********/

/********* Carving out holes and concavities begins here             *********/
/**                                                                         **/
/**                                                                         **/

/*****************************************************************************/
/*                                                                           */
/*  infecthull()   Virally infect all of the triangles of the convex hull    */
/*                 that are not protected by shell edges.  Where there are   */
/*                 shell edges, set boundary markers as appropriate.         */
/*                                                                           */
/*****************************************************************************/

void mesh2d::infecthull()
{
  struct triedge hulltri;
  struct triedge nexttri;
  struct triedge starttri;
  struct edge hulledge;
  triangle **deadtri;
  point horg, hdest;
  triangle ptr;                         /* Temporary variable used by sym(). */
  shelle sptr;                      /* Temporary variable used by tspivot(). */

  if (verbose) {
    printf("  Marking concavities (external triangles) for elimination.\n");
  }
  /* Find a triangle handle on the hull. */
  hulltri.tri = dummytri;
  hulltri.orient = 0;
  symself(hulltri);
  /* Remember where we started so we know when to stop. */
  triedgecopy(hulltri, starttri);
  /* Go once counterclockwise around the convex hull. */
  do {
    /* Ignore triangles that are already infected. */
    if (!infected(hulltri)) {
      /* Is the triangle protected by a shell edge? */
      tspivot(hulltri, hulledge);
      if (hulledge.sh == dummysh) {
        /* The triangle is not protected; infect it. */
        infect(hulltri);
        deadtri = (triangle **) viri.alloc();
        *deadtri = hulltri.tri;
      } else {
        /* The triangle is protected; set boundary markers if appropriate. */
        if (mark(hulledge) == 0) {
          setmark(hulledge, 1);
          org(hulltri, horg);
          dest(hulltri, hdest);
          if (pointmark(horg) == 0) {
            setpointmark(horg, 1);
          }
          if (pointmark(hdest) == 0) {
            setpointmark(hdest, 1);
          }
        }
      }
    }
    /* To find the next hull edge, go clockwise around the next vertex. */
    lnextself(hulltri);
    oprev(hulltri, nexttri);
    while (nexttri.tri != dummytri) {
      triedgecopy(nexttri, hulltri);
      oprev(hulltri, nexttri);
    }
  } while (!triedgeequal(hulltri, starttri));
}

/*****************************************************************************/
/*                                                                           */
/*  plague()   Spread the virus from all infected triangles to any neighbors */
/*             not protected by shell edges.  Delete all infected triangles. */
/*                                                                           */
/*  This is the procedure that actually creates holes and concavities.       */
/*                                                                           */
/*  This procedure operates in two phases.  The first phase identifies all   */
/*  the triangles that will die, and marks them as infected.  They are       */
/*  marked to ensure that each triangle is added to the virus pool only      */
/*  once, so the procedure will terminate.                                   */
/*                                                                           */
/*  The second phase actually eliminates the infected triangles.  It also    */
/*  eliminates orphaned points.                                              */
/*                                                                           */
/*****************************************************************************/

void mesh2d::plague()
{
  struct triedge testtri;
  struct triedge neighbor;
  triangle **virusloop;
  triangle **deadtri;
  struct edge neighborshelle;
  point testpoint;
  point norg, ndest;
  point deadorg, deaddest, deadapex;
  int killorg;
  triangle ptr;             /* Temporary variable used by sym() and onext(). */
  shelle sptr;                      /* Temporary variable used by tspivot(). */

  if (verbose) {
    printf("  Marking neighbors of marked triangles.\n");
  }
  /* Loop through all the infected triangles, spreading the virus to */
  /*   their neighbors, then to their neighbors' neighbors.          */
  viri.traversalinit();
  virusloop = (triangle **) viri.traverse();
  while (virusloop != (triangle **) NULL) {
    testtri.tri = *virusloop;
    /* A triangle is marked as infected by messing with one of its shell */
    /*   edges, setting it to an illegal value.  Hence, we have to       */
    /*   temporarily uninfect this triangle so that we can examine its   */
    /*   adjacent shell edges.                                           */
    uninfect(testtri);
    if (verbose > 2) {
      /* Assign the triangle an orientation for convenience in */
      /*   checking its points.                                */
      testtri.orient = 0;
      org(testtri, deadorg);
      dest(testtri, deaddest);
      apex(testtri, deadapex);
      printf("    Checking (%.12g, %.12g) (%.12g, %.12g) (%.12g, %.12g)\n",
             deadorg[0], deadorg[1], deaddest[0], deaddest[1],
             deadapex[0], deadapex[1]);
    }
    /* Check each of the triangle's three neighbors. */
    for (testtri.orient = 0; testtri.orient < 3; testtri.orient++) {
      /* Find the neighbor. */
      sym(testtri, neighbor);
      /* Check for a shell between the triangle and its neighbor. */
      tspivot(testtri, neighborshelle);
      /* Check if the neighbor is nonexistent or already infected. */
      if ((neighbor.tri == dummytri) || infected(neighbor)) {
        if (neighborshelle.sh != dummysh) {
          /* There is a shell edge separating the triangle from its */
          /*   neighbor, but both triangles are dying, so the shell */
          /*   edge dies too.                                       */
          shelledealloc(neighborshelle.sh);
          if (neighbor.tri != dummytri) {
            /* Make sure the shell edge doesn't get deallocated again */
            /*   later when the infected neighbor is visited.         */
            uninfect(neighbor);
            tsdissolve(neighbor);
            infect(neighbor);
          }
        }
      } else {                   /* The neighbor exists and is not infected. */
        if (neighborshelle.sh == dummysh) {
          /* There is no shell edge protecting the neighbor, so */
          /*   the neighbor becomes infected.                   */
          if (verbose > 2) {
            org(neighbor, deadorg);
            dest(neighbor, deaddest);
            apex(neighbor, deadapex);
            printf(
              "    Marking (%.12g, %.12g) (%.12g, %.12g) (%.12g, %.12g)\n",
                   deadorg[0], deadorg[1], deaddest[0], deaddest[1],
                   deadapex[0], deadapex[1]);
          }
          infect(neighbor);
          /* Ensure that the neighbor's neighbors will be infected. */
          deadtri = (triangle **) viri.alloc();
          *deadtri = neighbor.tri;
        } else {               /* The neighbor is protected by a shell edge. */
          /* Remove this triangle from the shell edge. */
          stdissolve(neighborshelle);
          /* The shell edge becomes a boundary.  Set markers accordingly. */
          if (mark(neighborshelle) == 0) {
            setmark(neighborshelle, 1);
          }
          org(neighbor, norg);
          dest(neighbor, ndest);
          if (pointmark(norg) == 0) {
            setpointmark(norg, 1);
          }
          if (pointmark(ndest) == 0) {
            setpointmark(ndest, 1);
          }
        }
      }
    }
    /* Remark the triangle as infected, so it doesn't get added to the */
    /*   virus pool again.                                             */
    infect(testtri);
    virusloop = (triangle **) viri.traverse();
  }

  if (verbose) {
    printf("  Deleting marked triangles.\n");
  }
  viri.traversalinit();
  virusloop = (triangle **) viri.traverse();
  while (virusloop != (triangle **) NULL) {
    testtri.tri = *virusloop;

    /* Check each of the three corners of the triangle for elimination. */
    /*   This is done by walking around each point, checking if it is   */
    /*   still connected to at least one live triangle.                 */
    for (testtri.orient = 0; testtri.orient < 3; testtri.orient++) {
      org(testtri, testpoint);
      /* Check if the point has already been tested. */
      if (testpoint != (point) NULL) {
        killorg = 1;
        /* Mark the corner of the triangle as having been tested. */
        setorg(testtri, NULL);
        /* Walk counterclockwise about the point. */
        onext(testtri, neighbor);
        /* Stop upon reaching a boundary or the starting triangle. */
        while ((neighbor.tri != dummytri)
               && (!triedgeequal(neighbor, testtri))) {
          if (infected(neighbor)) {
            /* Mark the corner of this triangle as having been tested. */
            setorg(neighbor, NULL);
          } else {
            /* A live triangle.  The point survives. */
            killorg = 0;
          }
          /* Walk counterclockwise about the point. */
          onextself(neighbor);
        }
        /* If we reached a boundary, we must walk clockwise as well. */
        if (neighbor.tri == dummytri) {
          /* Walk clockwise about the point. */
          oprev(testtri, neighbor);
          /* Stop upon reaching a boundary. */
          while (neighbor.tri != dummytri) {
            if (infected(neighbor)) {
            /* Mark the corner of this triangle as having been tested. */
              setorg(neighbor, NULL);
            } else {
              /* A live triangle.  The point survives. */
              killorg = 0;
            }
            /* Walk clockwise about the point. */
            oprevself(neighbor);
          }
        }
        if (killorg) {
          if (verbose > 1) {
            printf("    Deleting point (%.12g, %.12g)\n",
                   testpoint[0], testpoint[1]);
          }
          pointdealloc(testpoint);
        }
      }
    }

    /* Record changes in the number of boundary edges, and disconnect */
    /*   dead triangles from their neighbors.                         */
    for (testtri.orient = 0; testtri.orient < 3; testtri.orient++) {
      sym(testtri, neighbor);
      if (neighbor.tri == dummytri) {
        /* There is no neighboring triangle on this edge, so this edge    */
        /*   is a boundary edge.  This triangle is being deleted, so this */
        /*   boundary edge is deleted.                                    */
        hullsize--;
      } else {
        /* Disconnect the triangle from its neighbor. */
        dissolve(neighbor);
        /* There is a neighboring triangle on this edge, so this edge */
        /*   becomes a boundary edge when this triangle is deleted.   */
        hullsize++;
      }
    }
    /* Return the dead triangle to the pool of triangles. */
    triangledealloc(testtri.tri);
    virusloop = (triangle **) viri.traverse();
  }
  /* Empty the virus pool. */
  viri.restart();
}

/*****************************************************************************/
/*                                                                           */
/*  regionplague()   Spread regional attributes and/or area constraints      */
/*                   (from a .poly file) throughout the mesh.                */
/*                                                                           */
/*  This procedure operates in two phases.  The first phase spreads an       */
/*  attribute and/or an area constraint through a (segment-bounded) region.  */
/*  The triangles are marked to ensure that each triangle is added to the    */
/*  virus pool only once, so the procedure will terminate.                   */
/*                                                                           */
/*  The second phase uninfects all infected triangles, returning them to     */
/*  normal.                                                                  */
/*                                                                           */
/*****************************************************************************/

void mesh2d::regionplague(REAL attribute, REAL area)
{
  struct triedge testtri;
  struct triedge neighbor;
  triangle **virusloop;
  triangle **regiontri;
  struct edge neighborshelle;
  point regionorg, regiondest, regionapex;
  triangle ptr;             /* Temporary variable used by sym() and onext(). */
  shelle sptr;                      /* Temporary variable used by tspivot(). */

  if (verbose > 1) {
    printf("  Marking neighbors of marked triangles.\n");
  }
  /* Loop through all the infected triangles, spreading the attribute      */
  /*   and/or area constraint to their neighbors, then to their neighbors' */
  /*   neighbors.                                                          */
  viri.traversalinit();
  virusloop = (triangle **) viri.traverse();
  while (virusloop != (triangle **) NULL) {
    testtri.tri = *virusloop;
    /* A triangle is marked as infected by messing with one of its shell */
    /*   edges, setting it to an illegal value.  Hence, we have to       */
    /*   temporarily uninfect this triangle so that we can examine its   */
    /*   adjacent shell edges.                                           */
    uninfect(testtri);
    if (regionattrib) {
      /* Set an attribute. */
      setelemattribute(testtri, eextras, attribute);
    }
    if (vararea) {
      /* Set an area constraint. */
      setareabound(testtri, area);
    }
    if (verbose > 2) {
      /* Assign the triangle an orientation for convenience in */
      /*   checking its points.                                */
      testtri.orient = 0;
      org(testtri, regionorg);
      dest(testtri, regiondest);
      apex(testtri, regionapex);
      printf("    Checking (%.12g, %.12g) (%.12g, %.12g) (%.12g, %.12g)\n",
             regionorg[0], regionorg[1], regiondest[0], regiondest[1],
             regionapex[0], regionapex[1]);
    }
    /* Check each of the triangle's three neighbors. */
    for (testtri.orient = 0; testtri.orient < 3; testtri.orient++) {
      /* Find the neighbor. */
      sym(testtri, neighbor);
      /* Check for a shell between the triangle and its neighbor. */
      tspivot(testtri, neighborshelle);
      /* Make sure the neighbor exists, is not already infected, and */
      /*   isn't protected by a shell edge.                          */
      if ((neighbor.tri != dummytri) && !infected(neighbor)
          && (neighborshelle.sh == dummysh)) {
        if (verbose > 2) {
          org(neighbor, regionorg);
          dest(neighbor, regiondest);
          apex(neighbor, regionapex);
          printf("    Marking (%.12g, %.12g) (%.12g, %.12g) (%.12g, %.12g)\n",
                 regionorg[0], regionorg[1], regiondest[0], regiondest[1],
                 regionapex[0], regionapex[1]);
        }
        /* Infect the neighbor. */
        infect(neighbor);
        /* Ensure that the neighbor's neighbors will be infected. */
        regiontri = (triangle **) viri.alloc();
        *regiontri = neighbor.tri;
      }
    }
    /* Remark the triangle as infected, so it doesn't get added to the */
    /*   virus pool again.                                             */
    infect(testtri);
    virusloop = (triangle **) viri.traverse();
  }

  /* Uninfect all triangles. */
  if (verbose > 1) {
    printf("  Unmarking marked triangles.\n");
  }
  viri.traversalinit();
  virusloop = (triangle **) viri.traverse();
  while (virusloop != (triangle **) NULL) {
    testtri.tri = *virusloop;
    uninfect(testtri);
    virusloop = (triangle **) viri.traverse();
  }
  /* Empty the virus pool. */
  viri.restart();
}

/*****************************************************************************/
/*                                                                           */
/*  carveholes()   Find the holes and infect them.  Find the area            */
/*                 constraints and infect them.  Infect the convex hull.     */
/*                 Spread the infection and kill triangles.  Spread the      */
/*                 area constraints.                                         */
/*                                                                           */
/*  This routine mainly calls other routines to carry out all these          */
/*  functions.                                                               */
/*                                                                           */
/*****************************************************************************/

void mesh2d::
carveholes(REAL *holelist, int holes, REAL *regionlist, int regions)
{
  struct triedge searchtri;
  struct triedge triangleloop;
  struct triedge *regiontris;
  triangle **holetri;
  triangle **regiontri;
  point searchorg, searchdest;
  enum locateresult intersect;
  int i;
  triangle ptr;                         /* Temporary variable used by sym(). */

  if (!(quiet || (noholes && convex))) {
    printf("Removing unwanted triangles.\n");
    if (verbose && (holes > 0)) {
      printf("  Marking holes for elimination.\n");
    }
  }

  if (regions > 0) {
    /* Allocate storage for the triangles in which region points fall. */
    regiontris = (struct triedge *) new struct triedge[regions];
    if (regiontris == (struct triedge *) NULL) {
      printf("Error:  Out of memory.\n");
      exit(1);
    }
  }

  if (((holes > 0) && !noholes) || !convex || (regions > 0)) {
    /* Initialize a pool of viri to be used for holes, concavities, */
    /*   regional attributes, and/or regional area constraints.     */
    viri.init(sizeof(triangle *), VIRUSPERBLOCK, POINTER, 0);
  }

  if (!convex) {
    /* Mark as infected any unprotected triangles on the boundary. */
    /*   This is one way by which concavities are created.         */
    infecthull();
  }

  if ((holes > 0) && !noholes) {
    /* Infect each triangle in which a hole lies. */
    for (i = 0; i < 2 * holes; i += 2) {
      /* Ignore holes that aren't within the bounds of the mesh. */
      if ((holelist[i] >= xmin) && (holelist[i] <= xmax)
          && (holelist[i + 1] >= ymin) && (holelist[i + 1] <= ymax)) {
        /* Start searching from some triangle on the outer boundary. */
        searchtri.tri = dummytri;
        searchtri.orient = 0;
        symself(searchtri);
        /* Ensure that the hole is to the left of this boundary edge; */
        /*   otherwise, locate() will falsely report that the hole    */
        /*   falls within the starting triangle.                      */
        org(searchtri, searchorg);
        dest(searchtri, searchdest);
        if (counterclockwise(searchorg, searchdest, &holelist[i]) > 0.0) {
          /* Find a triangle that contains the hole. */
          intersect = locate(&holelist[i], &searchtri);
          if ((intersect != OUTSIDE) && (!infected(searchtri))) {
            /* Infect the triangle.  This is done by marking the triangle */
            /*   as infect and including the triangle in the virus pool.  */
            infect(searchtri);
            holetri = (triangle **) viri.alloc();
            *holetri = searchtri.tri;
          }
        }
      }
    }
  }

  /* Now, we have to find all the regions BEFORE we carve the holes, because */
  /*   locate() won't work when the triangulation is no longer convex.       */
  /*   (Incidentally, this is the reason why regional attributes and area    */
  /*   constraints can't be used when refining a preexisting mesh, which     */
  /*   might not be convex; they can only be used with a freshly             */
  /*   triangulated PSLG.)                                                   */
  if (regions > 0) {
    /* Find the starting triangle for each region. */
    for (i = 0; i < regions; i++) {
      regiontris[i].tri = dummytri;
      /* Ignore region points that aren't within the bounds of the mesh. */
      if ((regionlist[4 * i] >= xmin) && (regionlist[4 * i] <= xmax) &&
          (regionlist[4 * i + 1] >= ymin) && (regionlist[4 * i + 1] <= ymax)) {
        /* Start searching from some triangle on the outer boundary. */
        searchtri.tri = dummytri;
        searchtri.orient = 0;
        symself(searchtri);
        /* Ensure that the region point is to the left of this boundary */
        /*   edge; otherwise, locate() will falsely report that the     */
        /*   region point falls within the starting triangle.           */
        org(searchtri, searchorg);
        dest(searchtri, searchdest);
        if (counterclockwise(searchorg, searchdest, &regionlist[4 * i]) >
            0.0) {
          /* Find a triangle that contains the region point. */
          intersect = locate(&regionlist[4 * i], &searchtri);
          if ((intersect != OUTSIDE) && (!infected(searchtri))) {
            /* Record the triangle for processing after the */
            /*   holes have been carved.                    */
            triedgecopy(searchtri, regiontris[i]);
          }
        }
      }
    }
  }

  if (viri.items > 0) {
    /* Carve the holes and concavities. */
    plague();
  }
  /* The virus pool should be empty now. */

  if (regions > 0) {
    if (!quiet) {
      if (regionattrib) {
        if (vararea) {
          printf("Spreading regional attributes and area constraints.\n");
        } else {
          printf("Spreading regional attributes.\n");
        }
      } else { 
        printf("Spreading regional area constraints.\n");
      }
    }
    if (regionattrib && !refine) {
      /* Assign every triangle a regional attribute of zero. */
      triangles.traversalinit();
      triangleloop.orient = 0;
      triangleloop.tri = triangletraverse();
      while (triangleloop.tri != (triangle *) NULL) {
        setelemattribute(triangleloop, eextras, 0.0);
        triangleloop.tri = triangletraverse();
      }
    }
    for (i = 0; i < regions; i++) {
      if (regiontris[i].tri != dummytri) {
        /* Make sure the triangle under consideration still exists. */
        /*   It may have been eaten by the virus.                   */
        if (regiontris[i].tri[3] != (triangle) NULL) {
          /* Put one triangle in the virus pool. */
          infect(regiontris[i]);
          regiontri = (triangle **) viri.alloc();
          *regiontri = regiontris[i].tri;
          /* Apply one region's attribute and/or area constraint. */
          regionplague(regionlist[4 * i + 2], regionlist[4 * i + 3]);
          /* The virus pool should be empty now. */
        }
      }
    }
    if (regionattrib && !refine) {
      /* Note the fact that each triangle has an additional attribute. */
      eextras++;
    }
  }

  /* Free up memory. */
  if (((holes > 0) && !noholes) || !convex || (regions > 0)) {
    viri.deinit();
  }
  if (regions > 0) {
    delete [] regiontris;
  }
}

/**                                                                         **/
/**                                                                         **/
/********* Carving out holes and concavities ends here               *********/

/********* I/O routines begin here                                   *********/
/**                                                                         **/
/**                                                                         **/

/*****************************************************************************/
/*                                                                           */
/*  transfernodes()   Read the points from memory.                           */
/*                                                                           */
/*****************************************************************************/

void mesh2d::transfernodes(REAL *pointlist, REAL *pointattriblist,
                           int *pointmarkerlist, int numberofpoints,
                           int numberofpointattribs)
{
  point pointloop;
  REAL x, y;
  int i, j;
  int coordindex;
  int attribindex;

  inpoints = numberofpoints;
  mesh_dim = 2;
  nextras = numberofpointattribs;
  readnodefile = 0;
  if (inpoints < 3) {
    printf("Error:  Input must have at least three input points.\n");
    exit(1);
  }

  if (!restartsymbol) {
    initializepointpool();
  }

  /* Read the points. */
  coordindex = 0;
  attribindex = 0;
  for (i = 0; i < inpoints; i++) {
    pointloop = (point) points.alloc();
    /* Read the point coordinates. */
    x = pointloop[0] = pointlist[coordindex++];
    y = pointloop[1] = pointlist[coordindex++];
    /* Read the point attributes. */
    for (j = 0; j < numberofpointattribs; j++) {
      pointloop[2 + j] = pointattriblist[attribindex++];
    }
    if (pointmarkerlist != (int *) NULL) {
      /* Read a point marker. */
      setpointmark(pointloop, pointmarkerlist[i]);
    } else {
      /* If no markers are specified, they default to zero. */
      setpointmark(pointloop, 0);
    }
    x = pointloop[0];
    y = pointloop[1];
    /* Determine the smallest and largest x and y coordinates. */
    if (i == 0) {
      xmin = xmax = x;
      ymin = ymax = y;
    } else {
      xmin = (x < xmin) ? x : xmin;
      xmax = (x > xmax) ? x : xmax;
      ymin = (y < ymin) ? y : ymin;
      ymax = (y > ymax) ? y : ymax;
    }
  }

  /* Nonexistent x value used as a flag to mark circle events in sweepline */
  /*   Delaunay algorithm.                                                 */
  xminextreme = 10 * xmin - 9 * xmax;
}

/*****************************************************************************/
/*                                                                           */
/*  writenodes()   Number the points and write them to a .node file.         */
/*                                                                           */
/*  To save memory, the point numbers are written over the shell markers     */
/*  after the points are written to a file.                                  */
/*                                                                           */
/*****************************************************************************/

void mesh2d::
writenodes(REAL **pointlist, REAL **pointattriblist, int **pointmarkerlist)
{
  REAL *plist;
  REAL *palist;
  int *pmlist;
  int coordindex;
  int attribindex;
  point pointloop;
  int pointnumber;
  int i;

  if (!quiet) {
    printf("Writing points.\n");
  }
  /* Allocate memory for output points if necessary. */
  if (*pointlist == (REAL *) NULL) {
    *pointlist = (REAL *) new REAL[points.items * 2];
    if (*pointlist == (REAL *) NULL) {
      printf("Error:  Out of memory.\n");
      exit(1);
    }
  }
  /* Allocate memory for output point attributes if necessary. */
  if ((nextras > 0) && (*pointattriblist == (REAL *) NULL)) {
    *pointattriblist = (REAL *) new REAL[points.items * nextras];
    if (*pointattriblist == (REAL *) NULL) {
      printf("Error:  Out of memory.\n");
      exit(1);
    }
  }
  /* Allocate memory for output point markers if necessary. */
  if (!nobound && (*pointmarkerlist == (int *) NULL)) {
    *pointmarkerlist = (int *) new int[points.items];
    if (*pointmarkerlist == (int *) NULL) {
      printf("Error:  Out of memory.\n");
      exit(1);
    }
  }
  plist = *pointlist;
  palist = *pointattriblist;
  pmlist = *pointmarkerlist;
  coordindex = 0;
  attribindex = 0;

  points.traversalinit();
  pointloop = pointtraverse();
  pointnumber = firstnumber;
  while (pointloop != (point) NULL) {
    /* X and y coordinates. */
    plist[coordindex++] = pointloop[0];
    plist[coordindex++] = pointloop[1];
    /* Point attributes. */
    for (i = 0; i < nextras; i++) {
      palist[attribindex++] = pointloop[2 + i];
    }
    if (!nobound) {
      /* Copy the boundary marker. */
      pmlist[pointnumber - firstnumber] = pointmark(pointloop);
    }

    setpointmark(pointloop, pointnumber);
    pointloop = pointtraverse();
    pointnumber++;
  }
}

/*****************************************************************************/
/*                                                                           */
/*  numbernodes()   Number the points.                                       */
/*                                                                           */
/*  Each point is assigned a marker equal to its number.                     */
/*                                                                           */
/*  Used when writenodes() is not called because no .node file is written.   */
/*                                                                           */
/*****************************************************************************/

void mesh2d::numbernodes()
{
  point pointloop;
  int pointnumber;

  points.traversalinit();
  pointloop = pointtraverse();
  pointnumber = firstnumber;
  while (pointloop != (point) NULL) {
    setpointmark(pointloop, pointnumber);
    pointloop = pointtraverse();
    pointnumber++;
  }
}

/*****************************************************************************/
/*                                                                           */
/*  writeelements()   Write the triangles to an .ele file.                   */
/*                                                                           */
/*****************************************************************************/

void mesh2d::writeelements(int **trianglelist, REAL **triangleattriblist)
{
  int *tlist;
  REAL *talist;
  int pointindex;
  int attribindex;
  struct triedge triangleloop;
  point p1, p2, p3;
  point mid1, mid2, mid3;
  int elementnumber;
  int i;

  if (!quiet) {
    printf("Writing triangles.\n");
  }
  /* Allocate memory for output triangles if necessary. */
  if (*trianglelist == (int *) NULL) {
    *trianglelist = (int *) new int[triangles.items *
                               ((order + 1) * (order + 2) / 2)];
    if (*trianglelist == (int *) NULL) {
      printf("Error:  Out of memory.\n");
      exit(1);
    }
  }
  /* Allocate memory for output triangle attributes if necessary. */
  if ((eextras > 0) && (*triangleattriblist == (REAL *) NULL)) {
    *triangleattriblist = (REAL *) new REAL[triangles.items * eextras];
    if (*triangleattriblist == (REAL *) NULL) {
      printf("Error:  Out of memory.\n");
      exit(1);
    }
  }
  tlist = *trianglelist;
  talist = *triangleattriblist;
  pointindex = 0;
  attribindex = 0;

  triangles.traversalinit();
  triangleloop.tri = triangletraverse();
  triangleloop.orient = 0;
  elementnumber = firstnumber;
  while (triangleloop.tri != (triangle *) NULL) {
    org(triangleloop, p1);
    dest(triangleloop, p2);
    apex(triangleloop, p3);
    if (order == 1) {
      tlist[pointindex++] = pointmark(p1);
      tlist[pointindex++] = pointmark(p2);
      tlist[pointindex++] = pointmark(p3);
    } else {
      mid1 = (point) triangleloop.tri[highorderindex + 1];
      mid2 = (point) triangleloop.tri[highorderindex + 2];
      mid3 = (point) triangleloop.tri[highorderindex];
      tlist[pointindex++] = pointmark(p1);
      tlist[pointindex++] = pointmark(p2);
      tlist[pointindex++] = pointmark(p3);
      tlist[pointindex++] = pointmark(mid1);
      tlist[pointindex++] = pointmark(mid2);
      tlist[pointindex++] = pointmark(mid3);
    }

    for (i = 0; i < eextras; i++) {
      talist[attribindex++] = elemattribute(triangleloop, i);
    }

    triangleloop.tri = triangletraverse();
    elementnumber++;
  }
}

/*****************************************************************************/
/*                                                                           */
/*  writepoly()   Write the segments and holes to a .poly file.              */
/*                                                                           */
/*****************************************************************************/

void mesh2d::writepoly(int **segmentlist, int **segmentmarkerlist)
{
  int *slist;
  int *smlist;
  int index;
  struct edge shelleloop;
  point endpoint1, endpoint2;
  int shellenumber;

  if (!quiet) {
    printf("Writing segments.\n");
  }
  /* Allocate memory for output segments if necessary. */
  if (*segmentlist == (int *) NULL) {
    *segmentlist = (int *) new int[shelles.items * 2];
    if (*segmentlist == (int *) NULL) {
      printf("Error:  Out of memory.\n");
      exit(1);
    }
  }
  /* Allocate memory for output segment markers if necessary. */
  if (!nobound && (*segmentmarkerlist == (int *) NULL)) {
    *segmentmarkerlist = (int *) new int[shelles.items];
    if (*segmentmarkerlist == (int *) NULL) {
      printf("Error:  Out of memory.\n");
      exit(1);
    }
  }
  slist = *segmentlist;
  smlist = *segmentmarkerlist;
  index = 0;

  shelles.traversalinit();
  shelleloop.sh = shelletraverse();
  shelleloop.shorient = 0;
  shellenumber = firstnumber;
  while (shelleloop.sh != (shelle *) NULL) {
    sorg(shelleloop, endpoint1);
    sdest(shelleloop, endpoint2);
    /* Copy indices of the segment's two endpoints. */
    slist[index++] = pointmark(endpoint1);
    slist[index++] = pointmark(endpoint2);
    if (!nobound) {
      /* Copy the boundary marker. */
      smlist[shellenumber - firstnumber] = mark(shelleloop);
    }

    shelleloop.sh = shelletraverse();
    shellenumber++;
  }
}

void mesh2d::writeedges(int **edgelist, int **edgemarkerlist)
{
  int *elist;
  int *emlist;
  int index;
  struct triedge triangleloop, trisym;
  struct edge checkmark;
  point p1, p2;
  int edgenumber;
  triangle ptr;                         /* Temporary variable used by sym(). */
  shelle sptr;                      /* Temporary variable used by tspivot(). */

  if (!quiet) {
    printf("Writing edges.\n");
  }
  /* Allocate memory for edges if necessary. */
  if (*edgelist == (int *) NULL) {
    *edgelist = (int *) new int[edges * 2];
    if (*edgelist == (int *) NULL) {
      printf("Error:  Out of memory.\n");
      exit(1);
    }
  }
  /* Allocate memory for edge markers if necessary. */
  if (!nobound && (*edgemarkerlist == (int *) NULL)) {
    *edgemarkerlist = (int *) new int[edges];
    if (*edgemarkerlist == (int *) NULL) {
      printf("Error:  Out of memory.\n");
      exit(1);
    }
  }
  elist = *edgelist;
  emlist = *edgemarkerlist;
  index = 0;

  triangles.traversalinit();
  triangleloop.tri = triangletraverse();
  edgenumber = firstnumber;
  /* To loop over the set of edges, loop over all triangles, and look at   */
  /*   the three edges of each triangle.  If there isn't another triangle  */
  /*   adjacent to the edge, operate on the edge.  If there is another     */
  /*   adjacent triangle, operate on the edge only if the current triangle */
  /*   has a smaller pointer than its neighbor.  This way, each edge is    */
  /*   considered only once.                                               */
  while (triangleloop.tri != (triangle *) NULL) {
    for (triangleloop.orient = 0; triangleloop.orient < 3;
         triangleloop.orient++) {
      sym(triangleloop, trisym);
      if ((triangleloop.tri < trisym.tri) || (trisym.tri == dummytri)) {
        org(triangleloop, p1);
        dest(triangleloop, p2);
        elist[index++] = pointmark(p1);
        elist[index++] = pointmark(p2);
        if (nobound) {
        } else {
          /* Edge number, indices of two endpoints, and a boundary marker. */
          /*   If there's no shell edge, the boundary marker is zero.      */
          if (useshelles) {
            tspivot(triangleloop, checkmark);
            if (checkmark.sh == dummysh) {
              emlist[edgenumber - firstnumber] = 0;
            } else {
              emlist[edgenumber - firstnumber] = mark(checkmark);
            }
          } else {
            emlist[edgenumber - firstnumber] = trisym.tri == dummytri;
          }
        }
        edgenumber++;
      }
    }
    triangleloop.tri = triangletraverse();
  }
}

void mesh2d::writeneighbors(int **neighborlist)
{
  int *nlist;
  int index;
  struct triedge triangleloop, trisym;
  int elementnumber;
  int neighbor1, neighbor2, neighbor3;
  triangle ptr;                         /* Temporary variable used by sym(). */

  if (!quiet) {
    printf("Writing neighbors.\n");
  }
  /* Allocate memory for neighbors if necessary. */
  if (*neighborlist == (int *) NULL) {
    *neighborlist = (int *) new int[triangles.items * 3];
    if (*neighborlist == (int *) NULL) {
      printf("Error:  Out of memory.\n");
      exit(1);
    }
  }
  nlist = *neighborlist;
  index = 0;

  triangles.traversalinit();
  triangleloop.tri = triangletraverse();
  triangleloop.orient = 0;
  elementnumber = firstnumber;
  while (triangleloop.tri != (triangle *) NULL) {
    * (int *) (triangleloop.tri + 6) = elementnumber;
    triangleloop.tri = triangletraverse();
    elementnumber++;
  }
  * (int *) (dummytri + 6) = -1;

  triangles.traversalinit();
  triangleloop.tri = triangletraverse();
  elementnumber = firstnumber;
  while (triangleloop.tri != (triangle *) NULL) {
    triangleloop.orient = 1;
    sym(triangleloop, trisym);
    neighbor1 = * (int *) (trisym.tri + 6);
    triangleloop.orient = 2;
    sym(triangleloop, trisym);
    neighbor2 = * (int *) (trisym.tri + 6);
    triangleloop.orient = 0;
    sym(triangleloop, trisym);
    neighbor3 = * (int *) (trisym.tri + 6);
    nlist[index++] = neighbor1;
    nlist[index++] = neighbor2;
    nlist[index++] = neighbor3;

    triangleloop.tri = triangletraverse();
    elementnumber++;
  }
}

void mesh2d::writegid(int trilibrary)
{
  FILE *outfile;
  point pointloop;
  char gidfilename[FILENAMESIZE];
  int pointnumber;
  int i;

  if (trilibrary) {
    sprintf(gidfilename, "tmpmesh.gid");
  }

  if (!quiet) {
    printf("Writing %s.\n", gidfilename);
  }
  outfile = fopen(gidfilename, "w");
  if (outfile == (FILE *) NULL) {
    printf("  Error:  Cannot create file %s.\n", gidfilename);
    return;
  }

  fprintf(outfile, "mesh dimension = 2 elemtype triangle nnode = 3\n");
  fprintf(outfile, "coordinates\n");

  points.traversalinit();
  pointloop = pointtraverse();
  pointnumber = firstnumber;
  while (pointloop != (point) NULL) {
    // Point number, x and y coordinates.
    if (firstnumber == 0) {
      // Gid need start index from one.
      fprintf(outfile, "%4d    %.17g  %.17g", pointnumber + 1, pointloop[0],
              pointloop[1]);
    } else {
      fprintf(outfile, "%4d    %.17g  %.17g", pointnumber, pointloop[0],
              pointloop[1]);
    }
    for (i = 0; i < nextras; i++) {
      // Write an attribute.
      fprintf(outfile, "  %.17g", pointloop[i + 2]);
    }
    fprintf(outfile, "\n");
    setpointmark(pointloop, pointnumber);
    pointloop = pointtraverse();
    pointnumber++;
  }

  fprintf(outfile, "end coordinates\n");

  struct triedge triangleloop;
  point p1, p2, p3;
  int elementnumber;

  fprintf(outfile, "elements\n");

  triangles.traversalinit();
  triangleloop.tri = triangletraverse();
  triangleloop.orient = 0;
  elementnumber = 1;
  while (triangleloop.tri != (triangle *) NULL) {
    org(triangleloop, p1);
    dest(triangleloop, p2);
    apex(triangleloop, p3);
    // Triangle number, indices for three points.
    if (firstnumber == 0) {
      // Gid need start index from one.
      fprintf(outfile, "%4d    %4d  %4d  %4d", elementnumber,
              pointmark(p1)+1, pointmark(p2)+1, pointmark(p3)+1);
    } else {
      fprintf(outfile, "%4d    %4d  %4d  %4d", elementnumber,
              pointmark(p1), pointmark(p2), pointmark(p3));
    }

    for (i = 0; i < eextras; i++) {
      fprintf(outfile, "  %.17g", elemattribute(triangleloop, i));
    }
    fprintf(outfile, "\n");

    triangleloop.tri = triangletraverse();
    elementnumber++;
  }

  fprintf(outfile, "end elements\n");
  fclose(outfile);
}

/**                                                                         **/
/**                                                                         **/
/********* I/O routines end here                                     *********/

/*****************************************************************************/
/*                                                                           */
/*  main() or triangulate()   Gosh, do everything.                           */
/*                                                                           */
/*  The sequence is roughly as follows.  Many of these steps can be skipped, */
/*  depending on the command line switches.                                  */
/*                                                                           */
/*  - Initialize constants and parse the command line.                       */
/*  - Read the points from a file and either                                 */
/*    - triangulate them (no -r), or                                         */
/*    - read an old mesh from files and reconstruct it (-r).                 */
/*  - Insert the PSLG segments (-p), and possibly segments on the convex     */
/*      hull (-c).                                                           */
/*  - Read the holes (-p), regional attributes (-pA), and regional area      */
/*      constraints (-pa).  Carve the holes and concavities, and spread the  */
/*      regional attributes and area constraints.                            */
/*  - Enforce the constraints on minimum angle (-q) and maximum area (-a).   */
/*      Also enforce the conforming Delaunay property (-q and -a).           */
/*  - Compute the number of edges in the resulting mesh.                     */
/*  - Promote the mesh's linear triangles to higher order elements (-o).     */
/*  - Write the output files and print the statistics.                       */
/*  - Check the consistency and Delaunay property of the mesh (-C).          */
/*                                                                           */
/*****************************************************************************/

void mesh2d::triangulate(struct triangulateio *in, struct triangulateio *out,
                         struct triangulateio *vorout)
{
  REAL *holearray;                                        /* Array of holes. */
  REAL *regionarray;   /* Array of regional attributes and area constraints. */

  transfernodes(in->pointlist, in->pointattributelist, in->pointmarkerlist,
                in->numberofpoints, in->numberofpointattributes);

  hullsize = delaunay();                        /* Triangulate the points. */

  /* Ensure that no point can be mistaken for a triangular bounding */
  /*   box point in insertsite().                                   */
  infpoint1 = (point) NULL;
  infpoint2 = (point) NULL;
  infpoint3 = (point) NULL;

  if (useshelles) {
    checksegments = 1;                  /* Segments will be introduced next. */
    if (!refine) {
      /* Insert PSLG segments and/or convex hull segments. */
      insegments = formskeleton(in->segmentlist, in->segmentmarkerlist,
                                in->numberofsegments);
    }
  }

  if (poly) {
    holearray = in->holelist;
    holes = in->numberofholes;
    regionarray = in->regionlist;
    regions = in->numberofregions;
    if (!refine) {
      /* Carve out holes and concavities. */
      carveholes(holearray, holes, regionarray, regions);
    }
  } else {
    /* Without a PSLG, there can be no holes or regional attributes   */
    /*   or area constraints.  The following are set to zero to avoid */
    /*   an accidental free() later.                                  */
    holes = 0;
    regions = 0;
  }

  /* Compute the number of edges. */
  edges = (3l * triangles.items + hullsize) / 2l;

  if (!quiet) {
    printf("\n");
  }

  if (out) {
    out->numberofpoints = points.items;
    out->numberofpointattributes = nextras;
    out->numberoftriangles = triangles.items;
    out->numberofcorners = (order + 1) * (order + 2) / 2;
    out->numberoftriangleattributes = eextras;
    out->numberofedges = edges;
    if (useshelles) {
      out->numberofsegments = shelles.items;
    } else {
      out->numberofsegments = hullsize;
    }
  }
  if (vorout != (struct triangulateio *) NULL) {
    vorout->numberofpoints = triangles.items;
    vorout->numberofpointattributes = nextras;
    vorout->numberofedges = edges;
  }
  if (out) {
    /* If not using iteration numbers, don't write a .node file if one was */
    /*   read, because the original one would be overwritten!              */
    if (nonodewritten || (noiterationnum && readnodefile)) {
      if (!quiet) {
        printf("NOT writing points.\n");
      }
      numbernodes();             /* We must remember to number the points. */
    } else {
      writenodes(&out->pointlist, &out->pointattributelist,
                 &out->pointmarkerlist);
    }
    if (noelewritten) {
      if (!quiet) {
        printf("NOT writing triangles.\n");
      }
    } else {
      writeelements(&out->trianglelist, &out->triangleattributelist);
    }
    /* The -c switch (convex switch) causes a PSLG to be written */
    /*   even if none was read.                                  */
    if (poly || convex) {
      /* If not using iteration numbers, don't overwrite the .poly file. */
      if (nopolywritten || noiterationnum) {
        if (!quiet) {
          printf("NOT writing segments.\n");
        }
      } else {
        writepoly(&out->segmentlist, &out->segmentmarkerlist);
        out->numberofholes = holes;
        out->numberofregions = regions;
        if (poly) {
          if (holes > 0) {
            out->holelist = new REAL[holes * 2];
            memcpy(out->holelist, in->holelist, holes * 2* sizeof(REAL));
          }
		      if (regions > 0) {
		        out->regionlist = new REAL[regions * 4];
		        memcpy(out->regionlist, in->regionlist, regions * 4 * sizeof(REAL));
		      }
        } else {
          out->holelist = (REAL *) NULL;
          out->regionlist = (REAL *) NULL;
        }
      }
    }
    if (edgesout) {
      writeedges(&out->edgelist, &out->edgemarkerlist);
    }
    if (neighbors) {
      writeneighbors(&out->neighborlist);
    }
  }
  if (geomview) {
    writegid(1);
  }
}
