///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// constrain.cpp    Implement the boundary-constranied Delaunay mesh         //
//                  generation routines.                                     //
//                                                                           //
// Tetgen Version 1.0 beta                                                   //
// November, 2001                                                            //
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
// Unlike the two-dimension case that is guaranteed to recover the segment,  //
// the three-dimension case has no such guarantee to recover the segment and //
// facet. The Schonart polyhedron[1] is an example of polyhedron which can   //
// not be triangulated without adding internal point. So in three-dimension, //
// boundary-constrained mesh generation is a complex problem which can be    //
// defined in many ways and several solutions can be proposed.               //
//                                                                           //
// Currently, there exist several methods to solve this problem. Weatherill  //
// [2] and Borouchaki[3] retriangulated the elements intersected by a        //
// constrained face so as to create a triangulation of the face. In this     //
// case, the Steiner points are created on the boundary. George et al. [4]   //
// and Owen[5] regenerated the missing edges and faces in boundary by means  //
// of local transformations and the possible Steiner points insertion inside //
// the domain. Shewchuk[6] thought of the constrained boundary triangulation //
// problem as a subproblem of mesh improvement in his Delaunay refinement    //
// algorithm and proposed a method to recover boundary only need inserting   //
// points on segments.                                                       //
//                                                                           //
// The method I used to recover segments and facets is relatively derived    //
// from above methods. It has two stages: Segment recover and Facet recover. //
// It can be simply described below, the detail please refer to my thesis:   //
//                                                                           //
// We use the 'edge flip' + 'stitching' method to recover missing segments.  //
// For each missing segment, try edge flip operations(flip23, flip22 and     //
// flip44) first. Under most cases, after one or a series of flip operations,//
// the missing segment can be recovered. If edge flips failed, inserting a   //
// vertex into the mesh at the midpoint of the segment (more accurately, at  //
// the midpoint of the place where the segment should be). After the mesh is //
// adjusted to maintain the Delaunay property, the two resulting subsegments //
// may appear in the mesh. If not, the whole procedure is repeated           //
// recursively for each missing subsegment until the original segment is     //
// represented by a contiguous linear sequence of edges of the mesh. We are  //
// assure of eventual success because the Delaunay triangulation always      //
// connects a vertex to its nearest neighbour; once the spacing of vertices  //
// along a segment is sufficiently small, its entire length will be          //
// represented.                                                              //
//                                                                           //
// When all missing subsegments are recovered missing facets are recovered   //
// in an analogous manner. For each facet, it is necessary maintain a        //
// two-dimensional Delaunay triangulation of its vertices, independent from  //
// the tetrahedralization in which we hope its subfaces will eventually      //
// appear. For each triangular subface in a facet triangulation, look for    //
// a matching face in the tetrahedralization. If there could't find a match  //
// subface, we can sure this subface is missing from current mesh. When we   //
// find a subface is missing from the mesh, a local re-meshing method is     //
// used to recovery all missing subfaces (start from this subface). Please   //
// refer to Usermanual chapter 4.4.2 for detail description of this methhod. //
//                                                                           //
// However, There is no guarantee to recover facets in all condition of my   //
// implementation now. Acctually, It's a KNOWN BUG now there are still valid //
// input files for which Tetgen program can not produce a valid mesh. If     //
// you come across one of these, please send it to sihang@weboo.com so that  //
// I can continue to make the code more robust, thank you.                   //
//                                                                           //
// Refernces:                                                                //
//                                                                           //
// [1] E. Schonardt, Uber die Zerlegung von Dreieckspolyedern inTetraeder,   //
//     Mathematische Annalen, vol 98, pp. 309-312, 1928.                     //
// [2] N.P. Weatherill and O. Hassan, Efficient three-dimensional Delaunay   //
//     triangulation with automatic point creation and imposed boundary con- //
//     straints, Int. J. Numer. Meth. in Eng., vol 37, pp. 2005-2039, 1994.  //
// [3] H. Borouchaki, Triangulation sous contraintes en dimension quelconque,//
//     Rapport de Recherche INRIA, RR-2373, 1994.                            //
// [4] P.L. George, F. Hecht and E. Saltel, Automatic mesh generator with    //
//     specified boundary, Comp. Meth. in Appl. Mech. and Eng., vol 13,      //
//     pp. 269-288, 1991.                                                    //
// [5] Steven J. Owen, Constrained Triangulation: Application to Hex-Domaint //
//     Mesh Generation. Proceedings, 8th International Meshing Roundtable,   //
//     South Lake Tahoe, CA, U.S.A., pp.31-41, October 1999                  //
// [6] Jonathan Richard Shewchuk, Tetrahedral Mesh Generation by Delaunay    //
//     Refinement. Proceedings of the Fourteenth Annual Symopsium on Comput- //
//     ional Geometry (Minneapolis, Minnesota), pages 86-95, Association for //
//     Computing Machinery, June, 1998.                                      //
// [7] Jonathan Richard Shewchuk, A Condition Guaranteeing the Existence of  //
//     Higher-Dimensional Constrained Delaunay Triangulations. Proceedings   //
//     of the Fourteenth Annual Symopsium on Computional Geometry (Minneapo- //
//     lis, Minnesota), pages 76-85, Association for Computing Machinery,    //
//     June, 1998.                                                           //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "tetlib.h"

///////////////////////////////////////////////////////////////////////////////
// Segment/Facet (Boundary) Constrained Routines.                            //
// BEGIN                                                                     //
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// finddirection()    Find the first tetrahedron on the path from one point  //
//                    to another.                                            //
//                                                                           //
// Finds the tetrahedron that intersects a line segment drawn from the       //
// origin of 'searchtet' to the point 'endpoint', and returns the result in  //
// 'searchtet'.  The origin of 'searchtet' does not change, even though the  //
// tetrahedron returned may differ from the one passed in. This routine is   //
// used to find the direction to move in to get from one point to another.   //
//                                                                           //
// The return value notes whether the destination, apex or oppo of the found //
// tetrahedron is collinear with the two points in question.                 //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

enum mesh3d::finddirectionresult
mesh3d::finddirection(triface *searchtet, point3d tend)
{
  triface checktet;
  point3d tstart, tright, tleft, toppo;
  int baseorient, rightorient, leftorient, forwardorient;
  int rightflag, leftflag, forwardflag;
  int basezeroflag, rightzeroflag, leftzeroflag, forwardzeroflag;

  tstart = org(*searchtet);
  adjustedgering(*searchtet, CCW);
  if (tstart != org(*searchtet)) {
    enextself(*searchtet);
  }
  tright = dest(*searchtet);
  if (tright == tend) {
    return RIGHTCOLLINEAR;
  }
  tleft = apex(*searchtet);
  if (tleft == tend) {
    return LEFTCOLLINEAR;
  }

  // Base plane is the plane include face(tstart, tright, tleft), the normal
  //   is direct to toppo(toppo is above the base plane).
  basezeroflag = 0;
  // Is 'tend' below the base plane?
  baseorient = iorient3d(tstart, tright, tleft, tend);
  if (baseorient > 0) {
    // Get another side's tetrahdera of base face, so 'tend' is above the
    //   base plane, need reset tright and tleft.
    symself(*searchtet);
    assert(searchtet->tet != dummytet);
    findversion(searchtet, tstart, tleft, 0);
    tright = tleft;
    tleft = apex(*searchtet);
  } else if (baseorient == 0) {
    basezeroflag = 1;
  }

  if (verbose > 2) {
    printf("    Find direction to point %d, from tet(%d, %d, %d, %d).\n",
           pointmark(tend), pointmark(tstart), pointmark(tright),
           pointmark(tleft), pointmark(oppo(*searchtet)));
  }

  // Repeat turn right and turn left until find a satisfied tetrahedron.
  while (true) {
    toppo = oppo(*searchtet);
    if (toppo == tend) {
      return TOPCOLLINEAR;
    }
    // Must reset 'rightflag' and 'leftflag' at each start time. Because
    //   we not always turn the same side in three-dimensional case.
    rightflag = leftflag = forwardflag = 0;
    rightzeroflag = leftzeroflag = 0; forwardzeroflag = 0;

    // Is 'endpoint' to the right?
    rightorient = iorient3d(tend, tstart, tright, toppo);
    if (rightorient == 0) {
      rightzeroflag = 1;
    } else {
      rightflag = rightorient > 0;
    }
    // Is 'endpoint' to the left?
    leftorient = iorient3d(tstart, tend, tleft, toppo);
    if (leftorient == 0) {
      leftzeroflag = 1;
    } else {
      leftflag = leftorient > 0;
    }
    // Is 'endpoint' forward to the opposite?
    forwardorient = iorient3d(tright, toppo, tleft, tend);
    if (forwardorient == 0) {
      forwardzeroflag = 1;
    } else {
      forwardflag = forwardorient > 0;
    }

    // Check zero flag first.
    if (basezeroflag) {
      if (rightzeroflag && forwardflag) {
        return RIGHTCOLLINEAR;
      } else if (leftzeroflag && forwardflag) {
        return LEFTCOLLINEAR;
      } else if (forwardflag) {
        if ((rightflag == 0) && (leftflag == 0)) {
          return WITHIN;
        }
      }
    }

    if (rightzeroflag) {
      if (leftzeroflag && forwardflag) {
        return TOPCOLLINEAR;
      }
      if (!leftflag && forwardflag) {
        // This condition is tend coplanar with the right side(may be WITHIN
        //   ) of this tet, and we can't turn left side(because the leftflag
        //   is 0). The only choice is try to turn right. Check if there has
        //   a boundary on the right.
        fnext(*searchtet, checktet);
        if (issymexist(&checktet)) {
          rightflag = 1; // Here leftflag = 0;
        } else {
          // Hit a boundary when try turn right, take the right side as
          //   base plane, then continue...
          fnextself(*searchtet);
          esymself(*searchtet);  // Don't miss the tstart.
          enextself(*searchtet);
          tleft = tright;
          tright = toppo;
          basezeroflag = 1;
          if (verbose > 2) {
            printf("    Take right as base palne. Get tet(%d, %d, %d, %d).\n",
                   pointmark(tstart), pointmark(tright),
                   pointmark(tleft), pointmark(oppo(*searchtet)));
          }
          continue;
        }
      }
    } else if (leftzeroflag) {
      if (rightzeroflag && forwardflag) {
        return TOPCOLLINEAR;
      }
      if (!rightflag && forwardflag) {
        // This condition is tend coplanar with the left side(may be WITHIN
        //   ) of this tet, and we can't turn right side(because the right-
        //   flag is 0). The only choice is try to turn left. Check if there
        //   has a boundary on the left.
        checktet = *searchtet;
        enext2fnextself(checktet);
        if (issymexist(&checktet)) {
          leftflag = 1; // Here rightflag = 0;
        } else {
          // Hit a boundary when try turn left, take the left side as
          //   base plane, then continue...
          enext2fnextself(*searchtet);
          esymself(*searchtet); // Don't miss the tstart.
          tright = tleft;
          tleft = toppo;
          basezeroflag = 1;
          if (verbose > 2) {
            printf("    Take left as base palne. Get tet(%d, %d, %d, %d).\n",
                   pointmark(tstart), pointmark(tright),
                   pointmark(tleft), pointmark(oppo(*searchtet)));
          }
          continue;
        }
      }
    } else {
      // None zero flag(!rightzeroflag && !leftzeroflag) cases.
      if (!rightflag && !leftflag) {
        // Both rightflag = 0 and leftflag = 0. This mean tend is both below
        //   the right side and left side. There have two conditions, decide
        //   by current forwardflag.
        if (forwardflag) {
          return ACROSS;
        } else {
          // 'searchtet' faces directly away from `tend'.  We could go left
          //   or right. Ask whether it's a tetrahedron or a boundary on the
          //   right.
          fnext(*searchtet, checktet);
          if (issymexist(&checktet)) {
            rightflag = 1; // leftflag = 0;
          } else {
            leftflag = 1;  // rightflag = 0;
          }
        }
      } else if (rightflag && leftflag) {
        // 'searchtet' faces directly away from `tend'.  We could go left
        //   or right. Ask whether it's a tetrahedron or a boundary on the
        //   right.
        fnext(*searchtet, checktet);
        if (issymexist(&checktet)) {
          leftflag = 0;  // rightflag = 1;
        } else {
          rightflag = 0; // leftflag = 1;
        }
      }
    }

    if (rightflag) {
      // Turn right once.
      fnextself(*searchtet);
      symself(*searchtet);
      assert(searchtet->tet != dummytet);
      findversion(searchtet, tstart, tright, 0);
      tleft = toppo;
      basezeroflag = rightzeroflag;
      if (verbose > 2) {
        printf("    Turn right side.");
      }
    } else {
      assert(leftflag);
      // Turn left once.
      enext2fnextself(*searchtet);
      symself(*searchtet);
      assert(searchtet->tet != dummytet);
      findversion(searchtet, tstart, toppo, 0);
      tright = toppo;
      basezeroflag = leftzeroflag;
      if (verbose > 2) {
        printf("    Turn left side.");
      }
    }
    if (verbose > 2) {
      printf(" Get tet(%d, %d, %d, %d).\n",
           pointmark(tstart), pointmark(tright),
           pointmark(tleft), pointmark(oppo(*searchtet)));
    }
#ifdef SELF_CHECK
    baseorient = iorient3d(tstart, tright, tleft, tend);
    if (baseorient > 0) {
      printf("Internal error in finddirection():\n");
      printf("  'baseorient' shouldn't below the base plane.\n");
      internalerror();
    }
#endif // defined SELF_CHECK
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// segmentintersection()    Find the intersection of an existing segment and //
//                          a segment that is being inserted. Insert a point //
//                          at the intersection, splitting an existing shell //
//                          edge(subsegment).                                //
//                                                                           //
// The segment being inserted connects the apex of splittet to endpoint2.    //
// splitsubseg is the subsegment being split, the edge being split connects  //
// the origin and destination of splittet.                                   //
//                                                                           //
// On completion, splittet is a handle having the newly inserted             //
// intersection point as its origin, and endpoint1 as its destination.       //
//                                                                           //
// Use line and plane intersection algorithm to calculate the intersection   //
// point of two segment in 3-space:                                          //
//   If the plane is defined as:                                             //
//     a*x + b*y + c*z + d = 0           (1)                                 //
//   and the line is defined as:                                             //
//     x = x1 + (x2 - x1)*t = x1 + e*t                                       //
//     y = y1 + (y2 - y1)*t = y1 + f*t   (2)                                 //
//     z = z1 + (z2 - z1)*t = z1 + g*t                                       //
//   Then just substitute (2) into the plane equation (1). You end up with:  //
//     t = - (a*x1 + b*y1 + c*z1 + d)/(a*e + b*f + c*g)                      //
//   When the denominator is zero, the line is contained in the plane if the //
//   numerator is also zero (the point at t=0 satisfies the plane equation), //
//   otherwise the line is parallel to the plane.                            //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::segmentintersection(triface *splittet, face *splitshseg,
                                 point3d endpoint2)
{
  point3d endpoint1, torg, tdest;
  point3d leftpoint, rightpoint, oppopoint;
  point3d newpoint;
  enum insertsiteresult success;
  enum finddirectionresult collinear;
  enum locateresult locval;
  REAL a, b, c, d, e, f, g, t;
  REAL v12[3], v34[3], norm0[3], norm1[3];
  int i;

  segmentintersectioncount++;

  // Find the other three segment endpoints.
  endpoint1 = apex(*splittet);
  torg = org(*splittet);
  tdest = dest(*splittet);

  // Segment intersection formulae; see the graphic algorithm faq.
  Sub3D(tdest, torg, v12);
  Sub3D(endpoint2, endpoint1, v34);
  Cross3D(v12, v34, norm0);
  Cross3D(v34, norm0, norm1);

  a = norm1[0];
  b = norm1[1];
  c = norm1[2];
  d = -(a * endpoint1[0] + b * endpoint1[1] + c * endpoint1[2]);
  e = v12[0];
  f = v12[1];
  g = v12[2];
  t = -(a * torg[0] + b * torg[1] + c * torg[2] + d) / (a * e + b * f + c * g);

  // Create the new point.
  newpoint = (point3d) points.alloc();
  // Interpolate its coordinate and attributes.
  for (i = 0; i < 3 + nextras; i++) {
    newpoint[i] = torg[i] + t * v12[i];
  }
  setpointmark(newpoint, mark(*splitshseg));
  if (verbose > 1) {
    // For debug, need use the pointmark to keep point's index.
    setpointmark(newpoint, points.items);
  }
  if (verbose > 1) {
    printf("  Splitting edge (%.12g, %.12g, %.12g) (%.12g, %.12g, %.12g)\n",
           torg[0], torg[1], torg[2], tdest[0], tdest[1], tdest[2]);
    printf("    at (%.12g, %.12g, %.12g).\n", newpoint[0], newpoint[1],
           newpoint[2]);
  }
  // Insert the intersection point.  This should always succeed.
  success = insertsite(newpoint, splittet, (face*) NULL, splitshseg);
  if (success != SUCCESSFUL) {
    printf("Internal error in segmentintersection():");
    printf("  Fail to split a segment.\n");
    internalerror();
  }
  if (steinerleft > 0) {
    steinerleft--;
  }
  // Find newpoint in splittet, set it as origin of splittet,
  if (!findorg(splittet, newpoint)) {
    splittet->ver = 0;
    for (splittet->loc = 0; splittet->loc < 4; splittet->loc++) {
      if (isaboveplane(splittet, newpoint)) break;
    }
    assert(splittet->loc < 4);
    locval = preciselocate(newpoint, splittet);
    assert(locval == ONVERTEX);
  }
  setpoint2tet(newpoint, encode(*splittet));

  // Inserting the point may have caused edge flips.  We wish to rediscover
  //   the edge connecting endpoint1 to the new intersection point.
  collinear = finddirection(splittet, endpoint1);
  rightpoint = dest(*splittet);
  leftpoint = apex(*splittet);
  oppopoint = oppo(*splittet);
  if (leftpoint == endpoint1) {
    enext2self(*splittet);
    esymself(*splittet);
  } else if (oppopoint == endpoint1) {
    fnextself(*splittet);
    enext2self(*splittet);
    esymself(*splittet);
  } else if (rightpoint != endpoint1) {
    printf("Internal error in segmentintersection():\n");
    printf("  Topological inconsistency after splitting a segment.\n");
    internalerror();
  }
  // 'splittet' should have destination endpoint1.
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// scoutsegment()    Scout the first tetrahedron on the path from one        //
//                   endpoint to another, and check for completion(reaching  //
//                   the second endpoint), a collinear point, and the        //
//                   intersection of two segments or the intersection of a   //
//                   segment and a facet.                                    //
//                                                                           //
// Returns one if the entire segment is successfully  inserted,  and zero if //
// the job must be finished by conformingedge() or constrainededge().        //
//                                                                           //
// If the first tetrahedron on the path has the second endpoint as its       //
// destination, apex or opposite, a subsegment is inserted and the job is    //
// done.                                                                     //
//                                                                           //
// If the first tetrahedron  on the path has a  destination or apex that     //
// lies on the segment, a subsegment is inserted connecting the first        //
// endpoint to the collinear point, and the search is continued from the     //
// collinear point.                                                          //
//                                                                           //
// If the first tetrahedron on the path has a subsegment opposite its origin,//
// then there is a segment that intersects the segment being inserted. Their //
// intersection point is inserted, splitting the subsegment.                 //
//                                                                           //
// If the first tetrahedron on the path has a subface opposite its origin,   //
// then there is a facet that intersects the segment being inserted. Their   //
// intersection point is inserted, splitting the subface.                    //
//                                                                           //
// Otherwise, return zero.                                                   //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

int mesh3d::scoutsegment(triface *searchtet, point3d endpoint2, int newmark)
{
  triface crosstet;
  face crossface, crossedge;
  point3d leftpoint, rightpoint, oppopoint;
  point3d endpoint1;
  enum finddirectionresult collinear;

  endpoint1 = org(*searchtet);
  if (verbose > 2) {
    printf("    Scout segment from %d to %d.\n",
           pointmark(endpoint1), pointmark(endpoint2));
  }
  collinear = finddirection(searchtet, endpoint2);
  rightpoint = dest(*searchtet);
  leftpoint = apex(*searchtet);
  oppopoint = oppo(*searchtet);
  if ((oppopoint == endpoint2) || (leftpoint == endpoint2) ||
      (rightpoint == endpoint2)) {
    if (oppopoint == endpoint2) {
      fnextself(*searchtet);
      enext2self(*searchtet);
    } else if (leftpoint == endpoint2) {
      enext2self(*searchtet);
    }
    // Insert a subsegment, if there isn't already one there.
    insertsubsegment(searchtet, newmark);
    return 1;
  } else if (collinear == LEFTCOLLINEAR) {
    // We've collided with a point between the segment's endpoints.
    // Make the collinear point be the tetrahedron's origin.
    enext2self(*searchtet);
    insertsubsegment(searchtet, newmark);
    // Insert the remainder of the segment.
    return scoutsegment(searchtet, endpoint2, newmark);
  } else if (collinear == RIGHTCOLLINEAR) {
    // We've collided with a point between the segment's endpoints.
    insertsubsegment(searchtet, newmark);
    // Make the collinear point be the tetrahedron's origin.
    enextself(*searchtet);
    // Insert the remainder of the segment.
    return scoutsegment(searchtet, endpoint2, newmark);
  } else if (collinear == TOPCOLLINEAR) {
    // We've collided with a point between the segment's endpoints.
    // Make the collinear point be the tetrahedron's origin.
    fnextself(*searchtet);
    enext2self(*searchtet);
    insertsubsegment(searchtet, newmark);
    // Insert the remainder of the segment.
    return scoutsegment(searchtet, endpoint2, newmark);
  } else if (collinear == ACROSS) {
    // Check for a crossing subface.
    enextfnext(*searchtet, crosstet);
    tspivot(crosstet, crossface);
    if ((crossface.sh != dummysh) && !isnonsolid(crossface)) {
      /*// Insert a point at the intersection.
      segmentfacetintersection(&crosstet, &crossface, endpoint2);
      *searchtet = crosstet;
      insertsubsegment(searchtet, newmark);
      // Insert the remainder of the segment.
      return scoutsegment(searchtet, endpoint2, newmark); */
      printf("Segment-Facet intersection has not implemented now.\n");
      exit(1);
    } else {
      // Try to do flip23 on the acrossing face.
      if (categorizeface(crosstet) == T23) {
        if (verbose > 1) {
          printf("  Do face-edge swap (T23).\n");
        }
        usefliplist = 1;
        flip23(crosstet);
        usefliplist = 0;
        findorg(searchtet, endpoint1);
        assert(org(*searchtet) == endpoint1);
        return scoutsegment(searchtet, endpoint2, newmark);
      }
    }
  } else {
    assert(collinear == WITHIN);
    // Check for a crossing segment.
    enextfnext(*searchtet, crosstet);
    tsspivot(&crosstet, &crossedge);
    if (crossedge.sh != dummysh) {
      // Insert a point at the intersection.
      segmentintersection(&crosstet, &crossedge, endpoint2);
      *searchtet = crosstet;
      insertsubsegment(searchtet, newmark);
      // Insert the remainder of the segment.
      return scoutsegment(searchtet, endpoint2, newmark);
    } else {
      // Try to do flip22 or flip44 on the acrossing edge.
      point3d fliporg, flipdest;
      enum facecategory fc;

      fliporg = org(crosstet);
      flipdest = dest(crosstet);
      fc = categorizeface(crosstet);
      if ((fc == T22) || (fc == T44)) {
        // Check the flipface does not changed by categorizeface().
        if (((org(crosstet) == fliporg) && (dest(crosstet) == flipdest))
            || ((org(crosstet) == flipdest) && (dest(crosstet) == fliporg))) {
          if (verbose > 1) {
            printf("  Do face-edge swap (%s).\n", fc == T22 ? "T22" : "T44");
          }
          usefliplist = 1;
          if (fc == T22) {
            flip22(crosstet);
          } else {
            flip44(crosstet);
          }
          usefliplist = 0;
          findorg(searchtet, endpoint1);
          assert(org(*searchtet) == endpoint1);
          return scoutsegment(searchtet, endpoint2, newmark);
        }
      }
    }
  }
  // Can't find such segment, job must be completed by insert points.
  return 0;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// conformingedge()    Force a segment into a conforming Delaunay            //
//                     triangulation by inserting a point at its midpoint,   //
//                     and recursively forcing in the two half-segments if   //
//                     necessary.                                            //
//                                                                           //
// Generates a sequence of edges connecting `endpoint1' to `endpoint2'.      //
// `newmark' is the boundary marker of the segment, assigned to each new     //
// splitting point and shell edge.                                           //
//                                                                           //
// Note that conformingedge() does not always maintain the conforming        //
// Delaunay property.  Once inserted, segments are locked into place; points //
// inserted later (to force other segments in) may render these fixed        //
// segments non-Delaunay.  The conforming Delaunay property will be restored //
// by enforcequality() by splitting encroached segments.                     //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::conformingedge(point3d endpoint1, point3d endpoint2, int newmark)
{
  triface searchtet1, searchtet2;
  face brokenshseg, brokenshface;
  point3d newpoint;
  point3d midpoint1, midpoint2;
  enum insertsiteresult success;
  enum locateresult locval;
  int result1, result2;
  int i;

  if (verbose > 2) {
    printf("    Forcing segment into triangulation by recursive splitting:");
    printf(" %d, %d\n", pointmark(endpoint1), pointmark(endpoint2));
  }
  // Create a new point to insert in the middle of the segment.
  newpoint = (point3d) points.alloc();
  // Interpolate coordinates and attributes.
  for (i = 0; i < 3 + nextras; i++) {
    newpoint[i] = 0.5 * (endpoint1[i] + endpoint2[i]);
  }
  setpointmark(newpoint, newmark);
  if (verbose > 1) {
    // For debug, need use the pointmark to keep point's index.
    setpointmark(newpoint, points.items);
  }
  // Find a boundary tetrahedron to search from.
  searchtet1.tet = (tetrahedron *) NULL;
  // Attempt to insert the new point.
  success = insertsite(newpoint, &searchtet1, (face *) NULL, (face *) NULL);
  if (success == DUPLICATE) {
    if (verbose > 2) {
      printf("    Segment intersects existing point (%.12g, %.12g, %.12g).\n",
             newpoint[0], newpoint[1], newpoint[2]);
    }
    // Use the point that's already there.
    points.dealloc(newpoint);
    newpoint = org(searchtet1);
  } else {
    if (success == VIOLATINGEDGE) {
      if (verbose > 2) {
        printf("    Two segments intersect at (%.12g, %.12g, %.12g).\n",
               newpoint[0], newpoint[1], newpoint[2]);
      }
      // By fluke, we've landed right on another segment.  Split it.
      tsspivot(&searchtet1, &brokenshseg);
      success = insertsite(newpoint, &searchtet1, (face*) NULL, &brokenshseg);
      if (success != SUCCESSFUL) {
        printf("Internal error in conformingedge():");
        printf("  Failure to split a segment.\n");
        internalerror();
      }
    } else if (success == VIOLATINGFACE) {
      if (verbose > 2) {
        printf("    Segments intersect a subface at (%.12g, %.12g, %.12g).\n",
               newpoint[0], newpoint[1], newpoint[2]);
      }
      // By fluke, we've landed right on a subface.  Split it.
      tspivot(searchtet1, brokenshface);
      success = insertsite(newpoint, &searchtet1, &brokenshface, (face*) NULL);
      if (success != SUCCESSFUL) {
        printf("Internal error in conformingedge():");
        printf("  Failure to split a subface.\n");
        internalerror();
      }
    }
    // The point has been inserted successfully.
    if (steinerleft > 0) {
      steinerleft--;
    }
    // Find newpoint in searchtet1, set it as origin of splittet,
    if (!findorg(&searchtet1, newpoint)) {
      searchtet1.ver = 0;
      for (searchtet1.loc = 0; searchtet1.loc < 4; searchtet1.loc++) {
        if (isaboveplane(&searchtet1, newpoint)) break;
      }
      assert(searchtet1.loc < 4);
      locval = preciselocate(newpoint, &searchtet1);
      assert(locval == ONVERTEX);
    }
    setpoint2tet(newpoint, encode(searchtet1));
  }

  searchtet2 = searchtet1;
  result1 = scoutsegment(&searchtet1, endpoint1, newmark);
  result2 = scoutsegment(&searchtet2, endpoint2, newmark);
  if (!result1) {
    // The origin of searchtet1 may have changed if a collision with an
    //   intervening vertex on the segment occurred.
    midpoint1 = org(searchtet1);
    conformingedge(midpoint1, endpoint1, newmark);
  }
  if (!result2) {
    // The origin of searchtet2 may have changed if a collision with an
    //   intervening vertex on the segment occurred.
    midpoint2 = org(searchtet2);
    conformingedge(midpoint2, endpoint2, newmark);
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// insertsegment()    Insert a PLC segment into a triangulation.             //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::insertsegment(point3d endpoint1, point3d endpoint2, int newmark)
{
  triface searchtet1, searchtet2;
  tetrahedron encodedtet;
  point3d checkpoint;

  if (verbose > 1) {
    printf("  Connecting %d to %d.\n", pointmark(endpoint1),
           pointmark(endpoint2));
  }

  // Find a tetrahedron whose origin is the segment's first endpoint.
  checkpoint = (point3d) NULL;
  encodedtet = point2tet(endpoint1);
  if (encodedtet != (tetrahedron) NULL) {
    decode(encodedtet, searchtet1);
    if (findorg(&searchtet1, endpoint1)) {
      checkpoint = org(searchtet1);
    }
  }
  if (checkpoint != endpoint1) {
    // Find a boundary tetrahedron to search from.
    searchtet1.tet = dummytet;
    searchtet1.loc = 0;
    symself(searchtet1);
    // Search for the segment's first endpoint by point location.
    if (locate(endpoint1, &searchtet1) != ONVERTEX) {
      printf("Internal error in insertsegment():  Unable to locate point\n");
      printf("  (%.12g, %.12g, %.12g) in triangulation.\n",
             endpoint1[0], endpoint1[1], endpoint1[2]);
      internalerror();
    }
  }
  // Remember this tetrahedron to improve subsequent point location.
  recenttet = searchtet1;
  // Scout the beginnings of a path from the first endpoint
  //   toward the second.
  if (scoutsegment(&searchtet1, endpoint2, newmark)) {
    // The segment was easily inserted.
    if (!fliplist->empty()) {
      // Restore Delaunayness if necessary.
      dofliplist();
    }
    return;
  }
  // The first endpoint may have changed if a collision with an intervening
  //   vertex on the segment occurred.
  endpoint1 = org(searchtet1);

  // Find a tetrahedron whose origin is the segment's second endpoint.
  checkpoint = (point3d) NULL;
  encodedtet = point2tet(endpoint2);
  if (encodedtet != (tetrahedron) NULL) {
    decode(encodedtet, searchtet2);
    if (findorg(&searchtet2, endpoint2)) {
      checkpoint = org(searchtet2);
    }
  }
  if (checkpoint != endpoint2) {
    // Find a boundary tetrahedron to search from.
    searchtet2.tet = dummytet;
    searchtet2.loc = 0;
    symself(searchtet2);
    // Search for the segment's second endpoint by point location.
    if (locate(endpoint2, &searchtet2) != ONVERTEX) {
      printf("Internal error in insertsegment():  Unable to locate point\n");
      printf("  (%.12g, %.12g, %.12g) in triangulation.\n",
             endpoint2[0], endpoint2[1], endpoint2[2]);
      internalerror();
    }
  }
  // Remember this tetrahedron to improve subsequent point location.
  recenttet = searchtet2;
  // Scout the beginnings of a path from the second endpoint
  //   toward the first.
  if (scoutsegment(&searchtet2, endpoint1, newmark)) {
    // The segment was easily inserted.
    if (!fliplist->empty()) {
      // Restore Delaunayness if necessary.
      dofliplist();
    }
    return;
  }
  // The second endpoint may have changed if a collision with an intervening
  //   vertex on the segment occurred.
  endpoint2 = org(searchtet2);

  // Insert vertices to force the segment into the triangulation.
  conformingedge(endpoint1, endpoint2, newmark);
  if (!fliplist->empty()) {
    // Restore Delaunayness if necessary.
    dofliplist();
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// getsteinersinseg()    Find all steiner points in a given segment. Return  //
//                       in a List.                                          //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::getsteinersinseg(point3d endpoint1, point3d endpoint2,
                              list* steinerpoints)
{
  triface searchtet;
  tetrahedron encodedtet;
  point3d checkpoint;
  point3d leftpoint, rightpoint, oppopoint;
  enum finddirectionresult collinear;

  if (verbose > 2) {
    printf("    Get steiner points in segment from %d to %d.\n",
           pointmark(endpoint1), pointmark(endpoint2));
  }

  // Find a tetrahedron whose origin is the endpoint1.
  checkpoint = (point3d) NULL;
  encodedtet = point2tet(endpoint1);
  if (encodedtet != (tetrahedron) NULL) {
    decode(encodedtet, searchtet);
    if (findorg(&searchtet, endpoint1)) {
      checkpoint = org(searchtet);
    }
  }
  if (checkpoint != endpoint1) {
    // Find a boundary tetrahedron to search from.
    searchtet.tet = dummytet;
    searchtet.loc = 0;
    symself(searchtet);
    // Search for the segment's first endpoint by point location.
    if (locate(endpoint1, &searchtet) != ONVERTEX) {
      printf("Internal error in insertsegment():  Unable to locate point\n");
      printf("  (%.12g, %.12g, %.12g) in triangulation.\n",
             endpoint1[0], endpoint1[1], endpoint1[2]);
      internalerror();
    }
  }
  // Remember this tetrahedron to improve subsequent point location.
  recenttet = searchtet;

  while (true) {
    collinear = finddirection(&searchtet, endpoint2);
    rightpoint = dest(searchtet);
    leftpoint = apex(searchtet);
    oppopoint = oppo(searchtet);
    if ((oppopoint == endpoint2) || (leftpoint == endpoint2) ||
        (rightpoint == endpoint2)) {
      // We are reach the endpoint2, end of searching.
      return;
    } else if (collinear == LEFTCOLLINEAR) {
      // We've collided with a point between the segment's endpoints.
      steinerpoints->append(&leftpoint);
      // Make the collinear point be the tetrahedron's origin.
      enext2self(searchtet);
    } else if (collinear == RIGHTCOLLINEAR) {
      // We've collided with a point between the segment's endpoints.
      steinerpoints->append(&rightpoint);
      // Make the collinear point be the tetrahedron's origin.
      enextself(searchtet);
    } else if (collinear == TOPCOLLINEAR) {
      // We've collided with a point between the segment's endpoints.
      steinerpoints->append(&oppopoint);
      // Make the collinear point be the tetrahedron's origin.
      fnextself(searchtet);
      enext2self(searchtet);
    } else {  // collinear == ACROSS or collinear == WITHIN
      printf("Internal error in getsteinersinseg(): Segment is missing.\n");
      internalerror();
    }
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// getdiagonalapexindex()    Get the diagonal point index of the specified   //
//                           triangle edge(that is, get the neighbour tri    //
//                           at this edge, then get this edge's apex in it)  //
//                           in the input triangulateio structure.           //
//                                                                           //
// It required that the input triangulateio structure must be created by     //
// triangle with a switch -n, so triangle will generates a list of triangle  //
// neighbors in the 'neighborlist' field of triangulateio structure.         //
//                                                                           //
// If the diagonal point exist, return the index in pointlist (>= 0), other- //
// wise, return -1.                                                          //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

int mesh3d::
getdiagonalapexindex(triangulateio* out, int triindex, int edgeorient)
{
  int tribase, ntribase;
  int ntriindex;
  int iorg, idest;
  int nidiag;

  tribase = triindex * 3;
  ntriindex = out->neighborlist[tribase + minus1mod3[edgeorient]];
  if (ntriindex == -1) {
    return -1;
  }
  ntribase = ntriindex * 3;

  iorg = out->trianglelist[tribase + edgeorient];
  idest = out->trianglelist[tribase + plus1mod3[edgeorient]];

  nidiag = out->trianglelist[ntribase];
  if ((nidiag != iorg) && (nidiag != idest)) {
    return nidiag;
  }
  nidiag = out->trianglelist[ntribase + 1];
  if ((nidiag != iorg) && (nidiag != idest)) {
    return nidiag;
  }
  nidiag = out->trianglelist[ntribase + 2];
  if ((nidiag != iorg) && (nidiag != idest)) {
    return nidiag;
  }
  return -1;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// getneighbourtriedge()    Get the neighbour triangle's index and edge of   //
//                          the specified triangle edge(that is, get the     //
//                          neighbour tri at this edge, then get this edge's //
//                          orient) from the input triangulateio structure.  //
//                                                                           //
// It required that the input triangulateio structure must be created by     //
// triangle with a switch -n, so triangle will generates a list of triangle  //
// neighbors in the 'neighborlist' field of triangulateio structure.         //
//                                                                           //
// If the neighbour tri exist and the edge orient is found, return 1, other- //
// wise, return -1.                                                          //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

int mesh3d::
getneighbourtriedge(struct triangulateio* out, int triindex, int edgeorient,
                    int* ntriindex, int* nedgeorient)
{
  int tribase, ntribase;
  int iorg, idest;
  int niorg, nidest;
  int i;

  tribase = triindex * 3;
  *ntriindex = out->neighborlist[tribase + minus1mod3[edgeorient]];
  if (*ntriindex == -1) {
    return -1;
  }
  ntribase = *ntriindex * 3;

  iorg = out->trianglelist[tribase + edgeorient];
  idest = out->trianglelist[tribase + plus1mod3[edgeorient]];

  *nedgeorient = -1;
  for (i = 0; i < 3; i++) {
    niorg = out->trianglelist[ntribase + i];
    nidest = out->trianglelist[ntribase + plus1mod3[i]];
    if ((niorg == idest) && (nidest == iorg)) {
      *nedgeorient = i;
      return 1;
    }
  }

  return -1;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// swapdiagonal()   To do an edge flip in the input triangulateio structure. //
//                                                                           //
// It required that the input triangulateio structure must be created by     //
// triangle with a switch -n, so triangle will generates a list of triangle  //
// neighbors in the 'neighborlist' field of triangulateio structure.         //
//                                                                           //
//              nleftcasing                                                  //
//                                                                           //
//          dest  norg__ napex             dest ______   napex               //
//              |\ \     |                     |     / /|                    //
//              | \ \<----- nswapedge          |    / / |                    //
// rightcasing  |  \ \   |                     |   / /  |                    //
//              |   \ \  | nrightcasing        |  / /   |                    //
//    swapedge ----->\ \ |                     | / /    |                    //
//              |_____\ \|                     |/ /_____|                    //
//          apex    org  ndest             apex          ndest               //
//                                                                           //
//             leftcasing                                                    //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

int mesh3d::
swapdiagonal(struct triangulateio* out, int triindex, int fixedge, int swapedge)
{
  int tribase, ntribase;
  int ntriindex;
  int nswapedge;
  int org, dest, apex;
  int norg, ndest, napex;
  int rightcasing, leftcasing;
  int nrightcasing, nleftcasing;

  tribase = triindex * 3;
  ntriindex = out->neighborlist[tribase + minus1mod3[swapedge]];
  if (ntriindex == -1) {
    return 0; // ntriindex does not exist.
  }
  ntribase = ntriindex * 3;

  org = out->trianglelist[tribase + swapedge];
  dest = out->trianglelist[tribase + plus1mod3[swapedge]];
  apex = out->trianglelist[tribase + minus1mod3[swapedge]];
  // Find edge(sorg, sdest)'s orient in ntriindex.
  napex = -1;
  for (nswapedge = 0; nswapedge < 3; nswapedge++) {
    norg = out->trianglelist[ntribase + nswapedge];
    ndest = out->trianglelist[ntribase + plus1mod3[nswapedge]];
    if ((norg == dest) && (ndest == org)) {
      napex = out->trianglelist[ntribase + minus1mod3[nswapedge]];
      break;
    }
  }
  if (napex == -1) {
    return 0; // ntriindex does not contain the swap edge.
  }
  rightcasing = out->neighborlist[tribase + swapedge];
  leftcasing = out->neighborlist[tribase + plus1mod3[swapedge]];
  nrightcasing = out->neighborlist[ntribase + nswapedge];
  nleftcasing = out->neighborlist[ntribase + plus1mod3[nswapedge]];

  if (fixedge == plus1mod3[swapedge]) {
    // Right edge (dest, apex) of swap edge is fixed (not change).
    //   org <-- napex
    out->trianglelist[tribase + swapedge] = napex;
    //   leftcasing <-- ntriindex
    out->neighborlist[tribase + plus1mod3[swapedge]] = ntriindex;
    //   ntriindex <-- nleftcasing
    out->neighborlist[tribase + minus1mod3[swapedge]] = nleftcasing;
    //   norg <-- apex
    out->trianglelist[ntribase + nswapedge] = apex;
    //   nleftcasing <-- triindex
    out->neighborlist[ntribase + plus1mod3[nswapedge]] = triindex;
    //   triindex <-- leftcasing
    out->neighborlist[ntribase + minus1mod3[nswapedge]] = leftcasing;
  } else if (fixedge == minus1mod3[swapedge]) {
    // Left edge (apex, org) of swap edge is fixed (not change).
    //   dest <--> napex
    out->trianglelist[tribase + plus1mod3[swapedge]] = napex;
    //   rightcasing <-- ntriindex
    out->neighborlist[tribase + swapedge] = ntriindex;
    //   ntriindex <-- nrightcasing
    out->neighborlist[tribase + minus1mod3[swapedge]] = nrightcasing;
    //   ndest <--> apex
    out->trianglelist[ntribase + plus1mod3[nswapedge]] = apex;
    //   nrightcasing <-- triindex
    out->neighborlist[ntribase + nswapedge] = triindex;
    //   triindex <-- rightcasing
    out->neighborlist[ntribase + minus1mod3[nswapedge]] = rightcasing;
  } else {
    return 0;  // Wrong fixedge number.
  }
  return 1;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// matchface()     Matching the subface of a tetrahedron that has the same   //
//                 vertexs as inputs. If such face be found, a subface is    //
//                 inserted and the job is done.                             //
//                                                                           //
// If searchtet->tet == dummytet, the subface is defined by 'torg', 'tdest'  //
// and 'tapex'. If searchtet->tet != dummytet, the subface is defined by     //
// 'searchtet->org()', 'searchtet->dest()' and 'tapex'.                      //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

enum mesh3d::matchfaceresult
mesh3d::matchface(point3d torg, point3d tdest, point3d tapex,
                  triface* searchtet, int newmark)
{
  triface spintet;
  tetrahedron encodedtet;
  point3d checkpoint;
  point3d leftpoint, rightpoint, oppopoint;
  enum finddirectionresult collinear;
  int hitbdry;

  if (searchtet->tet == dummytet) {
    // Find a tetrahedron whose origin is the face's org.
    checkpoint = (point3d) NULL;
    encodedtet = point2tet(torg);
    if (encodedtet != (tetrahedron) NULL) {
      decode(encodedtet, *searchtet);
      if (findorg(searchtet, torg)) {
        checkpoint = org(*searchtet);
      }
    }
    if (checkpoint != torg) {
      // Find a boundary tetrahedron to search from.
      searchtet->tet = dummytet;
      searchtet->loc = 0;
      symself(*searchtet);
      // Search for the segment's first endpoint by point location.
      if (locate(torg, searchtet) != ONVERTEX) {
        printf("Internal error in insertsegment():  Unable to locate point\n");
        printf("  (%.12g, %.12g, %.12g) in triangulation.\n",
               torg[0], tdest[1], tapex[2]);
        internalerror();
      }
    }
    // Remember this tetrahedron to improve subsequent point location.
    recenttet = *searchtet;
    collinear = finddirection(searchtet, tdest);
    rightpoint = dest(*searchtet);
    leftpoint = apex(*searchtet);
    oppopoint = oppo(*searchtet);
    if ((oppopoint == tdest) || (leftpoint == tdest) ||
        (rightpoint == tdest)) {
      if (oppopoint == tdest) {
        fnextself(*searchtet);
        enext2self(*searchtet);
        esymself(*searchtet);
      } else if (leftpoint == tdest) {
        enext2self(*searchtet);
        esymself(*searchtet);
      }
    } else {
      return EDGEMISSING;
    }
    // Here the origin of 'searchtet' must be is torg.
    assert(org(*searchtet) == torg);
  }

  if (apex(*searchtet) != tapex) {
    // Spin around edge torg and tdest, to find a face that contain tapex.
    spintet = *searchtet;
    hitbdry = 0;
    while (true) {
      if (fnextself(spintet)) {
        if (apex(spintet) == apex(*searchtet)) {
          break; // Rewind, can leave now.
        }
        if (apex(spintet) == tapex) {
          // This is the face we looking for.
          *searchtet = spintet;
          break;
        }
      } else {
        hitbdry ++;
        if(hitbdry >= 2) {
          break;
        } else {
          esym(*searchtet, spintet);
        }
      }
    }
  }
  if (apex(*searchtet) == tapex) {
    // Insert a subface, if there isn't already one there.
    insertsubface(searchtet, newmark, 1);
    return FACEMATCHING;
  } else {
    return APEXMISSING;
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// insertfieldpoint()    Generate and insert a field(steiner) point into     //
//                       current mesh to form a triangulation for the input  //
//                       triangular faces.                                   //
//                                                                           //
// This routine is called when gift-wrapping failed. The recover facet job   //
// will be done(not neccessary) by insert field point to mesh.               //
//                                                                           //
// An important thing is the new field point must lies 'below' all the faces //
// (giftfaces) (that is visivle from all faces) and lies 'in' the hole.      //
//                                                                           //
// The 'crosstetlist' is a list which keeps all crossing tets, that can help //
// us to determine if the new field point is located in the hole.            //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

int mesh3d::insertfieldpoint(int numberofgiftfaces, triface* giftfaces,
                             int numberofgiftpoints, point3d* giftpoints,
                             list* crosstetlist)
{
  link *unfinfacelist;
  triface newtet, otherface, *checktetptr;
  face checksh;
  point3d newpoint;
  enum locateresult loc;
  int findex;
  int i, j;

  if (verbose > 1) {
    printf("  Generate field point to complete recover face.\n");
  }
  // Create the new point.
  newpoint = (point3d) points.alloc();
  // It's a inner point.
  setpointmark(newpoint, 0);
  if (verbose > 1) {
    // For debug, need use the pointmark to keep point's index.
    setpointmark(newpoint, points.items);
  }
  newpoint[0] = newpoint[1] = newpoint[2] = 0.0;
  for (i = 0; i < numberofgiftpoints; i++) {
    newpoint[0] += giftpoints[i][0];
    newpoint[1] += giftpoints[i][1];
    newpoint[2] += giftpoints[i][2];
    // Interpolate its coordinate and attributes.
    for (j = 3; j < 3 + nextras; j++) {
      newpoint[j] += giftpoints[i][j];
    }
  }
  newpoint[0] /= numberofgiftpoints;
  newpoint[1] /= numberofgiftpoints;
  newpoint[2] /= numberofgiftpoints;
  // Interpolate its coordinate and attributes.
  for (j = 3; j < 3 + nextras; j++) {
    newpoint[j] /= numberofgiftpoints;
  }

  // Check if newpoint lies in the hole.
  for (i = 0; i < crosstetlist->len(); i++) {
    checktetptr = (triface*) (*crosstetlist)[i];
    loc = isintet(org(*checktetptr), dest(*checktetptr), apex(*checktetptr),
                  oppo(*checktetptr), newpoint);
    if (loc != OUTSIDE) {
      break;
    }
  }
  if (i >= crosstetlist->len()) {
    // This new point is outside the hole.
    if (!quiet) {
      printf("Internal error in insertfieldpoint(): \n");
      printf("  The barycenter of each corner points locates outside the\n");
      printf("    polyhedra of this corner point and their bounding faces.\n");
      internalerror();
    }
    pointdealloc(newpoint);
    return 0;
  }
  // Check if newpoint lies below(is visible from) the all giftface.
  for (i = 0; i < numberofgiftfaces; i++) {
    if (!isbelowplane(&(giftfaces[i]), newpoint)) {
      break;
    }
  }
  if (i < numberofgiftfaces) {
    if (!quiet) {
      printf("Internal error in insertfieldpoint(): \n");
      printf("  The barycenter of each corner points does not visible from\n");
      printf("    all bounding faces of the polyhedra.\n");
      internalerror();
    }
    pointdealloc(newpoint);
    return 0;
  }

  if (verbose > 1) {
    printf("  Create new point (%.12g, %.12g, %.12g) %d.\n",
           newpoint[0], newpoint[1], newpoint[2], pointmark(newpoint));
  }

  // Setup a list for keeping all unfinished faces.
  unfinfacelist = new link(sizeof(triface));
  // Set user-defined compare function for comparing faces.
  unfinfacelist->setcomp((compfunc) &issameface);

  // Create a initial tet use giftfaces[0] and newpoint.
  maketetrahedron(&newtet);
  setorg(newtet, dest(giftfaces[0]));
  setdest(newtet, org(giftfaces[0]));
  setapex(newtet, apex(giftfaces[0]));
  setoppo(newtet, newpoint);
  // Make the connection between giftfaces[i] and newtet.
  bond(newtet, giftfaces[0]);
  tspivot(giftfaces[0], checksh);
  if (checksh.sh != dummysh) {
    sesymself(checksh);
    tsbond(newtet, checksh);
  }
  // Add the new tetrahedron's three faces to unfinished faces list.
  //   Keep 'newpoint' be apex of each faces.
  otherface = newtet;
  fnextself(otherface);
  unfinfacelist->add(&otherface);
  otherface = newtet;
  enextfnextself(otherface);
  unfinfacelist->add(&otherface);
  otherface = newtet;
  enext2fnextself(otherface);
  unfinfacelist->add(&otherface);
  if (verbose > 2) {
    printf("    Creating newtet ");
    dump(&newtet);
  }
  for (i = 1; i < numberofgiftfaces; i++) {
    maketetrahedron(&newtet);
    setorg(newtet, dest(giftfaces[i]));
    setdest(newtet, org(giftfaces[i]));
    setapex(newtet, apex(giftfaces[i]));
    setoppo(newtet, newpoint);
    // Make the connection between giftfaces[i] and newtet.
    bond(newtet, giftfaces[i]);
    tspivot(giftfaces[i], checksh);
    if (checksh.sh != dummysh) {
      sesymself(checksh);
      tsbond(newtet, checksh);
    }
    // Check and bond three inner faces of newtet.
    otherface = newtet;
    fnextself(otherface);
    findex = unfinfacelist->hasitem(&otherface);
    if ((findex > 0) && (findex <= unfinfacelist->len())) {
      checktetptr = (triface *) unfinfacelist->getnitem(findex);
      bond(otherface, *checktetptr);
      unfinfacelist->del(findex);  // Remove it.
    } else {
      unfinfacelist->add(&otherface);
    }
    otherface = newtet;
    enextfnextself(otherface);
    findex = unfinfacelist->hasitem(&otherface);
    if ((findex > 0) && (findex <= unfinfacelist->len())) {
      checktetptr = (triface *) unfinfacelist->getnitem(findex);
      bond(otherface, *checktetptr);
      unfinfacelist->del(findex);  // Remove it.
    } else {
      unfinfacelist->add(&otherface);
    }
    otherface = newtet;
    enext2fnextself(otherface);
    findex = unfinfacelist->hasitem(&otherface);
    if ((findex > 0) && (findex <= unfinfacelist->len())) {
      checktetptr = (triface *) unfinfacelist->getnitem(findex);
      bond(otherface, *checktetptr);
      unfinfacelist->del(findex);  // Remove it.
    } else {
      unfinfacelist->add(&otherface);
    }
    if (verbose > 2) {
      printf("    Creating newtet ");
      dump(&newtet);
    }
  }
  assert(unfinfacelist->len() == 0);

  delete unfinfacelist;
  return 1;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// recoverface()    Recover a subface that is missing from the volume mesh.  //
//                                                                           //
// This is done by local re-triangulate the missing faces area. Use gift-    //
// wrapping algorithm do local triangulation.                                //
//                                                                           //
// This function follow these steps:                                         //
//                                                                           //
// (1) Identify all missing faces from 2D surface mesh, and all vertexs of   //
//     these missing faces. The missing face will be found one by one start  //
//     from the input triedge(triindex and edgeorient, this edge must exist  //
//     in current tetrahedralization). Check other 2 edges are existed. If   //
//     find oneof edges is missing, this edge's neighbour face is a missing  //
//     face, take the neighbour triedge and keep it. Then loop untill all    //
//     missing faces be found. We use a list(missingfacelist) to keep all    //
//     missingface's index in 2D mesh(out), use a list(equatorpointlist) to  //
//     keep all the vertexs of missing faces.                                //
//                                                                           //
// (2) Identify all the cross edges. These edges penerate all the missing    //
//     faces and cause they cannot present in current tetrahedralization.    //
//     The cross edges will be found one by one. A loop is used untill all   //
//     cross edges are found. We use a list(crossedgelist) to keep all the   //
//     cross edges.                                                          //
//                                                                           //
// (3) Identify all the cross tetrahedra and classify north and sourth       //
//     points of endpoints of cross edges. We can identify the cross tets    //
//     from cross edges. Each cross edge has a set of tetrahedra surrounding //
//     it in the mesh. The identify all cross tets procedure proceeds by     //
//     interrogating the tetrahedra around each cross edge. At the same time,//
//     we can identify the endpoint of a cross edge's location (north or     //
//     sourth). We use a list(crosstetlist) to keep all cross tetrahedra,    //
//     two list(northpointlist and sourthpointlist) to keep the endpoints of //
//     cross edges respectly.                                                //
//                                                                           //
// (4) Identify and classify all the casing tets(tet which adjoining the     //
//     cross tets but not a cross tet). Casing tets will be used to generate //
//     giftfaces. Pay special attention to protect subsegments for all cross //
//     tets. Because they will be deleted before do gift-wrapping. There has //
//     a special codes to protect subsegments from cross tets to casing tets //
//     and dellocate inner nonsolid subfaces (Here we can't use preservesub- //
//     segment() routine directly). If a casing tet doesnot exist, this will //
//     happened when a cross tet lies on boundary.  We create a fake tet for //
//     holding the casing tet's face temporarily. After gift-wrapping, do a  //
//     remove fake tets job. At last,  We can delete all crosstets. So the   //
//     memory can be re-used for later re-generation. We use two list(north- //
//     cassinglist and sourthcassinglist) to keep all the casing tets.       //
//                                                                           //
// (5) Create all the equatorcasing tets. At first, there not exist equator- //
//     casing tet. So like above, temporarily create a fake tetrahedron(oppo //
//     = null) for holding this equator face. After re-triangulation, they   //
//     will be removed. First, all casing tets are faceing toward 'tsourth', //
//     because we triangulating the 'tnorth' side first. We use a list(equa- //
//     tcasinglist) to keep all equator casing tets.                         //
//                                                                           //
// (6) Do local re-meshing at both north and sourth side of this facet. The  //
//     well-known Gift-wrapping algorithm is used at here.                   //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

int mesh3d::recoverface(list* pointlist, triangulateio* out, int triindex,
                        int edgeorient)
{
  list *missingfacelist;
  list *crossedgelist, *crosstetlist;
  list *equatorpointlist, *northpointlist, *sourthpointlist;
  list *equatorcasinglist, *northcasinglist, *sourthcasinglist;
  list *backtracelist;
  triface *giftfaces;
  triface crossedge, crosstet;
  triface starttet, spintet;
  triface checkface, *checkfaceptr;
  face checksh, checkshseg;
  point3d torg, tdest, tapex;
  point3d tnorth, tsourth, tother;
  point3d *giftpoints;
  enum matchfaceresult match;
  int numberofgiftfaces, numberofgiftpoints;
  int *iptr, iorg, idest, iapex;
  int hitbdry, orient1, orient2;
  int edgecount, successbonded;
  int i, j, index, errorflag;

  if (verbose > 1) {
    printf("  Recover missing subfaces by local re-triangulation.\n");
  }

  // Step (1):
  if (verbose > 2) {
    printf("    Identify all missing subfaces.\n");
  }
  equatorpointlist = new list("point");
  missingfacelist = new list(sizeof(int) * 2);

  iptr = (int*) missingfacelist->alloc();
  iptr[0] = triindex;
  iptr[1] = edgeorient;
  for (i = 0; i < missingfacelist->len(); i++) {
    iptr = (int*) (*missingfacelist)[i];
    triindex = iptr[0];
    edgeorient = iptr[1];
    index = triindex * 3;
    iorg = out->trianglelist[index + edgeorient];
    idest = out->trianglelist[index + plus1mod3[edgeorient]];
    iapex = out->trianglelist[index + minus1mod3[edgeorient]];
    torg = *(point3d*)(*pointlist)[iorg];
    tdest = *(point3d*)(*pointlist)[idest];
    tapex = *(point3d*)(*pointlist)[iapex];
    if (verbose > 2) {
      printf("    Subface (%d, %d, %d) is missing.\n",
             pointmark(torg), pointmark(tdest), pointmark(tapex));
    }
    if (equatorpointlist->hasitem(&torg) == -1) {
      equatorpointlist->append(&torg);
    }
    if (equatorpointlist->hasitem(&tdest) == -1) {
      equatorpointlist->append(&tdest);
    }
    if (equatorpointlist->hasitem(&tapex) == -1) {
      equatorpointlist->append(&tapex);
    }
    // Skip the current edge; Check other edges are existing.
    starttet.tet = dummytet;
    match = matchface(tdest, tapex, torg, &starttet, 0);
    assert(match != FACEMATCHING);
    if (match == EDGEMISSING) {
      // There must exist another missing face.
      iptr = (int*) missingfacelist->alloc();
      // Get neighbour triangle's index and edgeorient.
      getneighbourtriedge(out, triindex, plus1mod3[edgeorient],
                          &iptr[0], &iptr[1]);
      assert((iptr[0] != -1) && (iptr[1] != -1));
    }
    starttet.tet = dummytet;
    match = matchface(tapex, torg, tdest, &starttet, 0);
    assert(match != FACEMATCHING);
    if (match == EDGEMISSING) {
      // There must exist another missing face.
      iptr = (int*) missingfacelist->alloc();
      // Get neighbour triangle's index and edgeorient.
      getneighbourtriedge(out, triindex, minus1mod3[edgeorient],
                          &iptr[0], &iptr[1]);
      assert((iptr[0] != -1) && (iptr[1] != -1));
    }
  }

  // Step (2):
  if (verbose > 2) {
    printf("    Identify all the cross edges.\n");
  }
  crossedgelist = new list(sizeof(triface));
  crossedgelist->setcomp((compfunc) &issameedge);

  // Find one cross edge which cause this subface missing. Here we can
  //   search from starttet. (starttet hold one of existing edges of the
  //   last found missing face: torg, tdest, tapex.)

  // First find one of points in 'torg', 'tdest' and 'tapex', which does
  //   not belong to 'starttet'.
  if (isfacehaspoint(&starttet, torg)) {
    if (isfacehaspoint(&starttet, tdest)) {
      tnorth = tapex;
    } else {
      tnorth = tdest;
    }
  } else {
    tnorth = torg;
  }
  // Find which (fnext) direction we should go.
  if (!isaboveplane(&starttet, tnorth)) {
    esymself(starttet);
  }
  spintet = starttet;
  hitbdry = 0;
  orient1 = iorient3d(torg, tdest, tapex, apex(spintet));
  errorflag = 0;
  while (true) {
    if (fnextself(spintet)) {
      if (apex(spintet) == apex(starttet)) {
        errorflag = 1;
        break;
      }
      orient2 = iorient3d(torg, tdest, tapex, apex(spintet));
      if (orient1 == 0) {
        if (orient2 != 0) orient1 = orient2;
      } else {
        if ((orient2 != 0) && (orient1 != orient2)) {
          crossedge = spintet;
          adjustedgering(crossedge, CCW);
          enextfnextself(crossedge);
          enextself(crossedge);
          break;
        }
      }
    } else {
      hitbdry ++;
      if (hitbdry >= 2) {
        errorflag = 1;
        break;
      } else {
        esym(starttet, spintet);
      }
    }
  }
  if (errorflag) {
    // No cross edge be found. It may cause by co-circular points of this
    //   facet(The Delaunay triangulation is not unique).
    if (verbose > 1) {
      printf("  No cross edge be found, return anyway.\n");
    }
    delete equatorpointlist;
    delete missingfacelist;
    delete crossedgelist;
    return 0;
  }
  // Get all other cross edges.
  if (verbose > 2) {
    printf("    Queueing cross edge (%d, %d).\n",
           pointmark(org(crossedge)), pointmark(dest(crossedge)));
  }
  crossedgelist->append(&crossedge);
  // Walk around this edge, identifying all other incident cross edges.
  //   Note: Here we should not hit boundry.
  for (i = 0; i < crossedgelist->len(); i++) {
    spintet = starttet = *(triface*)(*crossedgelist)[i];
    while (fnextself(spintet)) {
      if (apex(spintet) == apex(starttet)) {
        break; // Rewind, can leave now.
      }
      // Grab other vertex of this face.
      tother = apex(spintet);
      // If vertex is not one of equators(and should not coplanar with
      //   them), there's another bad edge here. Identify it and store it.
      if (equatorpointlist->hasitem(&tother) == -1) {
        // Find which edge is across the plane in spintet.
        orient1 = iorient3d(torg, tdest, tapex, org(spintet));
        orient2 = iorient3d(torg, tdest, tapex, tother);
        crossedge = spintet;
        if (orient1 != orient2) {
          // edge tother and 'org' is the cross edge.
          enext2self(crossedge);
          esymself(crossedge);
        } else {
          // egde 'dest' and tother is the cross edge.
          enextself(crossedge);
          esymself(crossedge);
        }
        if (crossedgelist->hasitem(&crossedge) == -1) {
          if (verbose > 2) {
            printf("    Queueing cross edge (%d, %d).\n",
                   pointmark(org(crossedge)), pointmark(dest(crossedge)));
          }
          crossedgelist->append(&crossedge);
        }
      }
    }
  }

  // Step (3):
  if (verbose > 2) {
    printf("    Classify all the north and sourth points and\n");
    printf("      identify all the cross(to be dead) tetrahedra.\n");
  }
  crosstetlist = new list(sizeof(triface));
  crosstetlist->setcomp((compfunc) &compare2tets);
  northpointlist = new list("point");
  sourthpointlist = new list("point");

  for (i = 0; i < crossedgelist->len(); i++) {
    spintet = starttet = *(triface*)(*crossedgelist)[i];
    orient1 = iorient3d(torg, tdest, tapex, org(spintet));
    assert(orient1 != 0);
    if (orient1 < 0) {
      tnorth = org(spintet);
      tsourth = dest(spintet);
    } else { // orient1 > 0
      tnorth = dest(spintet);
      tsourth = org(spintet);
    }
    if (northpointlist->hasitem(&tnorth) == -1) {
      if (verbose > 2) {
        printf("    Queueing north point %d.\n", pointmark(tnorth));
      }
      northpointlist->append(&tnorth);
    }
    if (sourthpointlist->hasitem(&tsourth) == -1) {
      if (verbose > 2) {
        printf("    Queueing sourth point %d.\n", pointmark(tsourth));
      }
      sourthpointlist->append(&tsourth);
    }
    if (crosstetlist->hasitem(&spintet) == -1) {
      if (verbose > 2) {
        printf("    Queueing cross tet (%d, %d, %d, %d).\n",
               pointmark(org(spintet)), pointmark(dest(spintet)),
               pointmark(apex(spintet)), pointmark(oppo(spintet)));
      }
      crosstetlist->append(&spintet);
    }
    while (fnextself(spintet)) {
      if (apex(spintet) == apex(starttet)) {
        break; // Rewind, can leave now.
      }
      if (crosstetlist->hasitem(&spintet) == -1) {
        if (verbose > 2) {
          printf("    Queueing cross tet (%d, %d, %d, %d).\n",
                 pointmark(org(spintet)), pointmark(dest(spintet)),
                 pointmark(apex(spintet)), pointmark(oppo(spintet)));
        }
        crosstetlist->append(&spintet);
      }
    }
  }

  // Step (4):
  if (verbose > 2) {
    printf("    Identifying and classifying north and sourth casing faces.\n");
  }
  northcasinglist = new list(sizeof(triface));
  sourthcasinglist = new list(sizeof(triface));

  for (i = 0; i < crosstetlist->len(); i++) {
    crosstet = *(triface*) (*crosstetlist)[i];
    if (verbose > 2) {
      printf("    Get cross tet (%d, %d, %d, %d).\n",
             pointmark(org(crosstet)), pointmark(dest(crosstet)),
             pointmark(apex(crosstet)), pointmark(oppo(crosstet)));
    }
    // Check each face of this crosstet to see if there exist casing face.
    //   If a face's neighbour tet not in crosstetlist, then it's a casing
    //   face. At the same time, find the inner subface if exist and delete
    //   it, don't forget to protect subsegment before delete subface.
    for (j = 0; j < 4; j++) {
      crosstet.loc = j;
      sym(crosstet, checkface);
      tspivot(crosstet, checksh);
      // Here checkface maybe hold 'dummytet'.
      if (crosstetlist->hasitem(&checkface) == -1) {
        // It's a casing face of the cavity.
        adjustedgering(crosstet, CCW);
        torg = org(crosstet);
        tdest = dest(crosstet);
        tapex = apex(crosstet);
        if (checkface.tet == dummytet) {
          // This side of crosstet is a boundary face, we need it.
          //   Temporarily create a fake tetrahedron(oppo = null) for
          //   holding the face. After re-generation, it will be removed.
          maketetrahedron(&checkface);
          checkface.loc = 0; // For sure.
          setorg(checkface, tdest);
          setdest(checkface, torg);
          setapex(checkface, tapex);
          // setoppo(checkface, NULL);
          if (verbose > 2) {
            printf("    Creating a fake tet for holding face(%d, %d, %d).\n",
                   pointmark(tdest), pointmark(torg), pointmark(tapex));
          }
          // Temporarily bond them for later protect segments.
          bond(checkface, crosstet);
          if (checksh.sh != dummysh) {
            sesymself(checksh);
            tsbond(checkface, checksh);
          }
        }
        adjustedgering(checkface, CCW);
        if ((northpointlist->hasitem(&torg) >= 0) ||
            (northpointlist->hasitem(&tdest) >= 0) ||
            (northpointlist->hasitem(&tapex) >= 0)) {
          if (verbose > 2) {
            printf("    Queuing northcasing face (%d, %d, %d).\n",
                   pointmark(org(checkface)), pointmark(dest(checkface)),
                   pointmark(apex(checkface)));
          }
          northcasinglist->append(&checkface);
        } else {
          if (verbose > 2) {
            printf("    Queuing sourthcasing face (%d, %d, %d).\n",
                   pointmark(org(checkface)), pointmark(dest(checkface)),
                   pointmark(apex(checkface)));
          }
          sourthcasinglist->append(&checkface);
        }
      } else {
        // Its a inner face. Check if there exist(to be dead) subface.
        if (checksh.sh != dummysh) {
          assert(isnonsolid(checksh));
          // Protect subsegment if there need.
          findversion(&crosstet, &checksh, 0); // For same enext() direction.
          edgecount = 0;
          while (edgecount < 3) {
            sspivot(checksh, checkshseg);
            if (checkshseg.sh != dummysh) {
              face tmpchecksh;
              spivot(checkshseg, tmpchecksh);
              if (tmpchecksh.sh == checksh.sh) {
                // We must protect this subsegment, otherwise the pointer
                //   in checkshseg will be invalid after deallocate checksh.
                spintet = crosstet;
                hitbdry = 0;
                successbonded = 0;
                while (true) {
                  if (fnextself(spintet)) {
                    if (apex(spintet) == apex(crosstet)) {
                      break;
                    }
                    tspivot(spintet, tmpchecksh);
                    if (tmpchecksh.sh != dummysh) {
                      findversion(&tmpchecksh, &spintet);
                      ssbond(tmpchecksh, checkshseg);
                      successbonded = 1;
                      break;
                    }
                  } else {
                    hitbdry ++;
                    if (hitbdry >= 2) {
                      break;
                    } else {
                      esym(crosstet, spintet);
                    }
                  }
                }
                if (!successbonded) {
                  // Can't find a exist subface to hold this subsegment.
                  //   We must insert a new (nonsolid) subface which must
                  //   be inserted at a face which its tet is not in
                  //   crosstetlist.
                  // Note:
                  //   (1) If we find such face, still need check if it's
                  //   a face of fake tet(oppo() = NULL), if so, we need
                  //   insert the new subface at its real face side, so
                  //   during the gift-wrapping stage, it will be bonded
                  //   automatically and we can safely remove the fake tet.
                  //   (2) If we can't find such face,
                  spintet = crosstet;
                  hitbdry = 0;
                  while (true) {
                    if (fnextself(spintet)) {
                      if (apex(spintet) == apex(crosstet)) {
                        break;
                      }
                      if (crosstetlist->hasitem(&spintet) == -1) {
                        if (spintet.tet[7] == NULL) {
                          // It's a fake tet. the subface should insert at
                          //   its real face(that is, loc = 0).
                          spintet.loc = 0;
                          if (verbose > 2) {
                            printf("    Creating a nonsolid subface at fake");
                            printf(" tet (%d, %d %d)\n",
                                   pointmark(org(spintet)),
                                   pointmark(dest(spintet)),
                                   pointmark(apex(spintet)));
                          }
                        } else {
                          if (verbose > 2) {
                            printf("    Creating a nonsolid subface at");
                            printf(" casing tet (%d, %d, %d, %d)\n",
                                   pointmark(org(spintet)),
                                   pointmark(dest(spintet)),
                                   pointmark(apex(spintet)),
                                   pointmark(oppo(spintet)));
                          }
                        }
                        if (verbose > 2) {
                           printf("      for holding subsegment (%d, %d).\n",
                                  pointmark(sorg(checkshseg)),
                                  pointmark(sdest(checkshseg)));
                        }
                        insertsubface(&spintet, NONSOLIDFLAG, 1);
                        successbonded = 1;
                        break;
                      }
                    } else {
                      hitbdry ++;
                      if (hitbdry >= 2) {
                        break;
                      } else {
                        esym(crosstet, spintet);
                      }
                    }
                  }
                  if (!successbonded) {
                    // We can't find a face suitable for holding subsegment.
                    //   Find a boundary face around this subsegment(spintet
                    //   ) and create a fake tet at this face, then insert
                    //   a new subface at this fake tet. We can sure, this
                    //   fake tet will be added to casing face list later.
                    triface tmpfaketet;
                    int count = 1000;
                    while (fnextself(spintet) && count) count--;
                    if (count <= 0) {
                      if (verbose) {
                        printf("Warnning in recoverface():\n");
                        printf("  We can't find a face suitable for holding");
                        printf(" subsegment, skip anyway.\n");
                      }
                    } else {
                      adjustedgering(spintet, CCW);
                      torg = org(spintet);
                      tdest = dest(spintet);
                      tapex = apex(spintet);
                      maketetrahedron(&tmpfaketet);
                      tmpfaketet.loc = 0; // For sure.
                      setorg(tmpfaketet, tdest);
                      setdest(tmpfaketet, torg);
                      setapex(tmpfaketet, tapex);
                      // setoppo(tmpfaketet, NULL);
                      if (verbose > 2) {
                        printf("    Creating a fake tet for holding");
                        printf(" subface (%d, %d, %d).\n", pointmark(tdest),
                               pointmark(torg), pointmark(tapex));
                      }
                      bond(tmpfaketet, spintet);
                      if (verbose > 2) {
                        printf("    Creating a nonsolid subface (%d, %d, %d)\n",
                               pointmark(torg), pointmark(tdest),
                               pointmark(tapex));
                        printf("      for holding subsegment (%d, %d).\n",
                               pointmark(sorg(checkshseg)),
                               pointmark(sdest(checkshseg)));
                      }
                      // Insert a new subface, and it will automatically bond
                      //   the subsegment(set autobond flag be '1').
                      insertsubface(&spintet, NONSOLIDFLAG, 1);
                      successbonded = 1;
                    }
                  }
                  // assert(successbonded);
                }
              }
            }
            senextself(checksh);
            enextself(crosstet);
            edgecount++;
          }
          // This subface can be dealloced now. Before dealloc, we must
          //   dissolve it from two side tetrahedra.
          tsdissolve(crosstet);
          tsdissolve(checkface);
          if (verbose > 2) {
            printf("    Deleting subface (%d, %d, %d) (nonsolid).\n",
                   pointmark(sorg(checksh)), pointmark(sdest(checksh)),
                   pointmark(sapex(checksh)));
          }
          shellfacedealloc(&subfaces, checksh.sh);
        }
      }
    }
  }
  assert(northcasinglist->len());
  assert(sourthcasinglist->len());

  // Step (5):
  if (verbose > 2) {
    printf("    Creating casing faces for missing faces(at equator).\n");
  }
  equatorcasinglist = new list(sizeof(triface));

  for (i = 0; i < missingfacelist->len(); i++) {
    iptr = (int*) (*missingfacelist)[i];
    index = iptr[0] * 3;
    iorg = out->trianglelist[index + edgeorient];
    idest = out->trianglelist[index + plus1mod3[edgeorient]];
    iapex = out->trianglelist[index + minus1mod3[edgeorient]];
    torg = *(point3d*)(*pointlist)[iorg];
    tdest = *(point3d*)(*pointlist)[idest];
    tapex = *(point3d*)(*pointlist)[iapex];
    maketetrahedron(&checkface);
    orient1 = iorient3d(torg, tdest, tapex, tsourth);
    assert(orient1 != 0);
    if (orient1 < 0) {
      setorg(checkface, torg);
      setdest(checkface, tdest);
    } else {
      setorg(checkface, tdest);
      setdest(checkface, torg);
    }
    setapex(checkface, tapex);
    if (verbose > 2) {
      printf("    Creating and queuing equatorcasing face (%d, %d, %d).\n",
             pointmark(org(checkface)), pointmark(dest(checkface)),
             pointmark(apex(checkface)));
    }
    equatorcasinglist->append(&checkface);
  }
  assert(equatorcasinglist->len());

  // Step (6):
  //   Generate giftfaces, giftpoints and giftpointdegrees at north side.
  numberofgiftfaces = equatorcasinglist->len() + northcasinglist->len();
  numberofgiftpoints = equatorpointlist->len() + northpointlist->len();
  giftfaces = new triface[numberofgiftfaces];
  giftpoints = new point3d[numberofgiftpoints];
  // Create a backtrace list to keep all new tets be created during
  //   gift-wrapping stage, so we can delete them if gift-wrapping failed.
  backtracelist = new list(sizeof(triface));

  //   Generate giftfaces.
  for (i = 0; i < equatorcasinglist->len(); i++) {
    giftfaces[i] = *(triface*)(*equatorcasinglist)[i];
  }
  for (j = i; j < numberofgiftfaces; j++) {
    giftfaces[j] = *(triface*)(*northcasinglist)[j - i];
    dissolve(giftfaces[j]);
  }
  //   Generate giftpoints.
  for (i = 0; i < equatorpointlist->len(); i++) {
    giftpoints[i] = *(point3d*)(*equatorpointlist)[i];
  }
  for (j = i; j < numberofgiftpoints; j++) {
    giftpoints[j] = *(point3d*)(*northpointlist)[j - i];
  }

  errorflag = giftwrapping(numberofgiftfaces, giftfaces, numberofgiftpoints,
                           giftpoints, NULL, 0, backtracelist);
  if (errorflag == 0) {
    if (verbose > 2) {
      printf("    Badly, gift-wrapping failed, clear all new tets that");
      printf(" created during gift-wrapping.\n");
    }
    for (i = 0; i < backtracelist->len(); i++) {
      checkfaceptr = (triface*)(*backtracelist)[i];
      if (verbose > 2) {
        printf("    Deleting new tet (%d, %d, %d, %d).\n",
               pointmark(org(*checkfaceptr)), pointmark(dest(*checkfaceptr)),
               pointmark(apex(*checkfaceptr)), pointmark(oppo(*checkfaceptr)));
      }
      tetrahedrondealloc(checkfaceptr->tet);
    }
    if (!insertfieldpoint(numberofgiftfaces, giftfaces, numberofgiftpoints,
                          giftpoints, crosstetlist)) {
      printf("Internalerror in recoverface(): Insert field point failed.\n");
      internalerror();
    }
  }

  if (verbose > 2) {
    printf("    Removing and replacing fake tets at equator with real tets.\n");
  }
  for (i = 0; i < equatorcasinglist->len(); i++) {
    checkfaceptr = (triface*)(*equatorcasinglist)[i];
    assert(oppo(*checkfaceptr) == (point3d) NULL);
    sym(*checkfaceptr, starttet);
    dissolve(starttet);
    // Remove fake tet.
    tetrahedrondealloc(checkfaceptr->tet);
    // Replace fake tet with a real tet.
    adjustedgering(starttet, CCW);
    *checkfaceptr = starttet;
    // Set a hit pointer in vertexs of face.
    torg = org(starttet);
    tdest = dest(starttet);
    tapex = apex(starttet);
    setpoint2tet(torg, encode(starttet));
    setpoint2tet(tdest, encode(starttet));
    setpoint2tet(tapex, encode(starttet));
    if (verbose > 2) {
      printf("    Changing (%d, %d, %d).\n",
             pointmark(torg), pointmark(tdest), pointmark(tapex));
    }
  }
  delete [] giftfaces;
  delete [] giftpoints;
  backtracelist->clear();

  //   Generate giftfaces, giftpoints and giftpointdegrees at sourth side.
  numberofgiftfaces = equatorcasinglist->len() + sourthcasinglist->len();
  numberofgiftpoints = equatorpointlist->len() + sourthpointlist->len();
  giftfaces = new triface[numberofgiftfaces];
  giftpoints = new point3d[numberofgiftpoints];

  //   Generate giftfaces.
  for (i = 0; i < equatorcasinglist->len(); i++) {
    giftfaces[i] = *(triface*)(*equatorcasinglist)[i];
  }
  for (j = i; j < numberofgiftfaces; j++) {
    giftfaces[j] = *(triface*)(*sourthcasinglist)[j - i];
    dissolve(giftfaces[j]);
  }
  //   Generate giftpoints.
  for (i = 0; i < equatorpointlist->len(); i++) {
    giftpoints[i] = *(point3d*)(*equatorpointlist)[i];
  }
  for (j = i; j < numberofgiftpoints; j++) {
    giftpoints[j] = *(point3d*)(*sourthpointlist)[j - i];
  }

  errorflag = giftwrapping(numberofgiftfaces, giftfaces, numberofgiftpoints,
                           giftpoints, NULL, 0, backtracelist);
  if (errorflag == 0) {
    if (verbose > 2) {
      printf("    Badly, gift-wrapping failed, clear all new tets that");
      printf(" created during gift-wrapping.\n");
    }
    for (i = 0; i < backtracelist->len(); i++) {
      checkfaceptr = (triface*)(*backtracelist)[i];
      if (verbose > 2) {
        printf("    Deleting new tet (%d, %d, %d, %d).\n",
               pointmark(org(*checkfaceptr)), pointmark(dest(*checkfaceptr)),
               pointmark(apex(*checkfaceptr)), pointmark(oppo(*checkfaceptr)));
      }
      tetrahedrondealloc(checkfaceptr->tet);
    }
    if (!insertfieldpoint(numberofgiftfaces, giftfaces, numberofgiftpoints,
                          giftpoints, crosstetlist)) {
      printf("Internalerror in recoverface(): Generate field point failed.\n");
      internalerror();
    }
  }

  if (verbose > 2) {
    printf("    Removing and replacing fake tets in north with dummytet.\n");
  }
  for (i = 0; i < northcasinglist->len(); i++) {
    checkface = *(triface*)(*northcasinglist)[i];
    if (oppo(checkface) == (point3d) NULL) {
      if (verbose > 2) {
        printf("    Changing (%d, %d, %d).\n",
               pointmark(org(checkface)), pointmark(dest(checkface)),
               pointmark(apex(checkface)));
      }
      sym(checkface, starttet);
      dissolve(starttet);
      tspivot(checkface, checksh);
      if (checksh.sh != dummysh) {
        stdissolve(checksh);
      }
      tetrahedrondealloc(checkface.tet);
      checkface = starttet;
    }
    // Set a hit pointer in vertexs of face.
    torg = org(checkface);
    tdest = dest(checkface);
    tapex = apex(checkface);
    setpoint2tet(torg, encode(checkface));
    setpoint2tet(tdest, encode(checkface));
    setpoint2tet(tapex, encode(checkface));
  }

  if (verbose > 2) {
    printf("    Removing and replacing fake tets in sourth with dummytet.\n");
  }
  for (i = 0; i < sourthcasinglist->len(); i++) {
    checkface = *(triface*)(*sourthcasinglist)[i];
    if (oppo(checkface) == (point3d) NULL) {
      if (verbose > 2) {
        printf("    Changing (%d, %d, %d).\n",
               pointmark(org(checkface)), pointmark(dest(checkface)),
               pointmark(apex(checkface)));
      }
      sym(checkface, starttet);
      dissolve(starttet);
      tspivot(checkface, checksh);
      if (checksh.sh != dummysh) {
        stdissolve(checksh);
      }
      tetrahedrondealloc(checkface.tet);
      checkface = starttet;
    }
    // Set a hit pointer in vertexs of face.
    torg = org(checkface);
    tdest = dest(checkface);
    tapex = apex(checkface);
    setpoint2tet(torg, encode(checkface));
    setpoint2tet(tdest, encode(checkface));
    setpoint2tet(tapex, encode(checkface));
  }

  // We can delete all crosstets in crosstetlist.
  for (i = 0; i < crosstetlist->len(); i++) {
    crosstet = *(triface*)(*crosstetlist)[i];
    if (verbose > 2) {
      printf("    Deleting tet (%d, %d, %d, %d).\n",
             pointmark(org(crosstet)), pointmark(dest(crosstet)),
             pointmark(apex(crosstet)), pointmark(oppo(crosstet)));
    }
    tetrahedrondealloc(crosstet.tet);
  }

  delete [] giftfaces;
  delete [] giftpoints;
  delete missingfacelist;
  delete crossedgelist;
  delete crosstetlist;
  delete equatorpointlist;
  delete northpointlist;
  delete sourthpointlist;
  delete equatorcasinglist;
  delete northcasinglist;
  delete sourthcasinglist;
  delete backtracelist;
  return 1;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// insertfacet()     Force the facet of PLC existing in tetrahedralization.  //
//                                                                           //
// First, we need form a triangulation of the PSLG facet. Obviously, we can  //
// not only consider the verteices of a facet given in the .poly or .smesh   //
// file. Which vertices of the tetrahedralization need to be considered in a //
// facet triangulation?  The answer can be found from Shewchuk's paper [6]:  //
//   ...                                                                     //
//   It is a fact, albeit somewhat nonintuitive, that if a facet appears in  //
// a Delaunay tetrahedralization as a union of faces, then the triangulation //
// of the facet is determined solely by the vertices of the tetrahedralizat- //
// ion that lies in the plane of the facet.  If a vertex lies close to a     //
// facet, but not in the same plane, it may cause a subfacet to be missing,  //
// but it can not affect the shape of the triangulation if all subfacets are //
// present. The detail please see Jonathan's Ph.D. thesis page 92.           //
//   Hence the facet triangulation need only consider vertices lying in the  //
// plane of the facet. Furthermore, because each facet is segment-bounded,   //
// and segment are recovered (in the tetrahedralization) before facets, each //
// facet triangulation can saftly ignore vertices that lie outside the facet //
// (even in the same plane). The only addtional vertices to be considered    //
// are those that were inserted on segments to force segments and other      //
// facets into the mesh.                                                     //
//   Unfortunately, if a facet triangulation is not unique because of        //
// cocircularity degeneracies, then foregoing statement about extraplanar    //
// vertices having no effect on the triangulation does not apply. To be      //
// specific, suppose a facet triangulation has four or more cocircular       //
// vertices, which are triangulate one way, whereas the tetrahedralization   //
// contains a set of faces that triangulate the same vertices with a         //
// diffrent (but also Delaunay) set of triangles. An aggressive implementat- //
// ion might identify these cases and correct the facet triangulation so     //
// that it matches the tetrahedralization (it is not always possible to      //
// force the tetrahedralization to match the triangulation). However,        //
// inserting a new vertex at the center of the collective circumcircle is    //
// always available as a lazy alternative. Here I use the first method.      //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::insertfacet(list* facetseglist, list* holelist, int boundmark,
                         int facenumber)
{
  list *pointlist, *conlist;
  list *indexlist, *steinerlist;
  queue *matchlist;
  triface searchtet;
  point3d torg, tdest, tapex, tfarapex;
  point3d *segendpoints;
  enum matchfaceresult match;
  struct triangulateio in, out;
  REAL norm[3], xaxi[3], yaxi[3];
  REAL v0[3], v1[3], dsin;
  REAL *holecoords;
  int *indexofsegendpoints, *indexofconpoints;
  int iorg, idest, iapex, ifarapex;
  int edgeorient, isswapable, maxlooptimes;
  int i, j, index;

  // Set a pointlist and conlist for PSLG facet. 'pointlist' keep all the
  //   pointers of points. 'conlist' keep each segment's endpoint index in
  //   'pointlist'.
  pointlist = new list("point");
  conlist = new list(sizeof(int) * 2);

  // First form a PSLG from the input 'facetseglist'.  Remeber, at this
  //   time, every segment is existed in the domain and is represented by
  //   a contiguous linear sequence of edges of the tetrahedralization. We
  //   must get all the steiner vertexs in the segment not merely get the
  //   segment's endpoints.
  indexlist = new list(sizeof(int) * 2);
  for (i = 0; i < facetseglist->len(); i++) {
    segendpoints = (point3d*) (*facetseglist)[i];
    indexofsegendpoints = (int*) indexlist->alloc();
    if (segendpoints[1] == (point3d) NULL) {
      // It's a isolate point in PSLG.
      pointlist->append(&segendpoints[0]);
      // We don't need this point's index.
      indexofsegendpoints[0] = indexofsegendpoints[1] = -1;
    } else {
      indexofsegendpoints[0] = pointlist->hasitem(&segendpoints[0]);
      if (indexofsegendpoints[0] == -1) {
        pointlist->append(&segendpoints[0]);
        indexofsegendpoints[0] = pointlist->len() - 1;
      }
      indexofsegendpoints[1] = pointlist->hasitem(&segendpoints[1]);
      if (indexofsegendpoints[1] == -1) {
        pointlist->append(&segendpoints[1]);
        indexofsegendpoints[1] = pointlist->len() - 1;
      }
    }
  }
  // Get all steiner points in segments and make connection infomation.
  steinerlist = new list("point", 10, 5);
  for (i = 0; i < facetseglist->len(); i++) {
    segendpoints = (point3d*) (*facetseglist)[i];
    if (segendpoints[1] != (point3d) NULL) {
      getsteinersinseg(segendpoints[0], segendpoints[1], steinerlist);
      indexofsegendpoints = (int*) (*indexlist)[i];
      indexofconpoints = (int*) conlist->alloc();
      indexofconpoints[0] = indexofsegendpoints[0];
      for (j = 0; j < steinerlist->len(); j++) {
        pointlist->append((*steinerlist)[j]);
        indexofconpoints[1] = pointlist->len() - 1;
        indexofconpoints = (int*) conlist->alloc();
        indexofconpoints[0] = pointlist->len() - 1;
      }
      indexofconpoints[1] = indexofsegendpoints[1];
      steinerlist->clear();
    }
  }
  delete steinerlist;
  delete indexlist;

  // Create the 2D mesh that will know what the correct subfaces are.
  if (verbose > 1) {
    printf("  Generate %d surface mesh: %d points, %d segments",
           facenumber, pointlist->len(), conlist->len());
    if (holelist) {
      printf(", %d holes.", holelist->len());
    }
    printf("\n");
  }
  triangulateioinit(&in);
  triangulateioinit(&out);
  if ((pointlist->len() == 3) && (conlist->len() == 3)) {
    // The facet is a triangle, this case we need not do surface mesh and
    //   set the output mesh directly.
    out.numberoftriangles = 1;
    out.trianglelist = new int[3];
    out.trianglelist[0] = 0;
    out.trianglelist[1] = 1;
    out.trianglelist[2] = 2;
    out.neighborlist = new int[3];
    out.neighborlist[0] = -1;
    out.neighborlist[1] = -1;
    out.neighborlist[2] = -1;
  } else {
    in.numberofpoints = pointlist->len();
    in.pointlist = new REAL[in.numberofpoints * 2];
    in.numberofsegments = conlist->len();
    in.segmentlist = new int[in.numberofsegments * 2];
    index = 0;
    for (i = 0; i < in.numberofsegments; i ++) {
      indexofconpoints = (int*) (*conlist)[i];
      in.segmentlist[index++] = indexofconpoints[0];
      in.segmentlist[index++] = indexofconpoints[1];
    }
    // Determine normal, we need find two not coliner vectors from
    //   input points.
    torg = *(point3d*)(*pointlist)[in.segmentlist[0]];
    tdest = *(point3d*)(*pointlist)[in.segmentlist[1]];
    Sub3D(tdest, torg, v0);
    Normalize3D(v0);
    index = 2;
    dsin = 0;
    for (i = 1; fabs(dsin) <= usertolerance; i++) {
      torg = *(point3d*)(*pointlist)[in.segmentlist[index++]];
      tdest = *(point3d*)(*pointlist)[in.segmentlist[index++]];
      Sub3D(tdest, torg, v1);
      Normalize3D(v1);
      Cross3D(v0, v1, norm);
      dsin = Mag3D(norm);
      if (!(fabs(dsin) <= usertolerance)) Scale3D(norm, 1./dsin);
      if (i >= in.numberofsegments) {
        printf("Recover Error: Can't find normal for %d facet.\n", facenumber);
        recovererror();
      }
    }
    // Project onto a plane
    Assign3D(v1, xaxi);
    Cross3D(norm, xaxi, yaxi);
    index = 0;
    for (i = 0; i < in.numberofpoints; i ++) {
      torg = *(point*)(*pointlist)[i];
      in.pointlist[index++] = Dot3D(torg, xaxi);
      in.pointlist[index++] = Dot3D(torg, yaxi);
    }
    if (holelist) {
      if (holelist->len() > 0) {
        in.numberofholes = holelist->len();
        in.holelist = new REAL[in.numberofholes * 2];
        index = 0;
        for (i = 0; i < in.numberofholes; i++) {
          holecoords = (REAL *) (*holelist)[i];
          in.holelist[index++] = Dot3D(holecoords, xaxi);
          in.holelist[index++] = Dot3D(holecoords, yaxi);
        }
      }
    }
    index = 0;
    // Now create the 2D mesh.
    surfmesh->triangulate(&in, &out, NULL);
    if (surfmesh->triangles.items <= 0) {
      printf("Recover error: Can't form a surface mesh for facet %d.\n",
             facenumber);
      recovererror();
    }
    if (verbose > 1) {
      printf("  Surface mesh result: %d triangles.\n",
             surfmesh->triangles.items);
    }
    surfmesh->trianglerestart();
  }

  // Set up a list to keep all the subface's index.
  matchlist = new queue("int");
  for (i = 0; i < out.numberoftriangles; i++) {
    matchlist->push(&i);
  }
  // To recover each of faces by swapping.  In this case, though,
  //   no point insertion is ever needed.
  maxlooptimes = out.numberoftriangles * 4; // Set a emergency break times.
  if (maxlooptimes <= 0) {
    // int type Overflow, set it be the largest int number.
    maxlooptimes = 0x7fffffff;
  }
  while (matchlist->get(&i) && maxlooptimes) {
    maxlooptimes--;
    index = i * 3;
    iorg = out.trianglelist[index++];
    idest = out.trianglelist[index++];
    iapex = out.trianglelist[index++];
    torg = *(point3d*)(*pointlist)[iorg];
    tdest = *(point3d*)(*pointlist)[idest];
    tapex = *(point3d*)(*pointlist)[iapex];
    if (verbose > 1) {
      printf("  Matching subface (%d, %d, %d).\n",
             pointmark(torg), pointmark(tdest), pointmark(tapex));
    }
    edgeorient = 0;
    searchtet.tet = dummytet;
    match = matchface(torg, tdest, tapex, &searchtet, boundmark);
    if (match == EDGEMISSING) {
      // edge (torg, tdest) is missing. Check if other edges are missing.
      searchtet.tet = dummytet;
      match = matchface(tdest, tapex, torg, &searchtet, boundmark);
      if (match == EDGEMISSING) {
        searchtet.tet = dummytet;
        match = matchface(tapex, torg, tdest, &searchtet, boundmark);
        if (match == EDGEMISSING) {
          // All edges of subface are missing. Push back to list to
          //   handle it later.
          matchlist->push(&i);
          continue;
        } else {
          // edge (tapex, torg) exist, both other 2 edges are missing.
          assert(match == APEXMISSING);
          edgeorient = 2;
        }
      } else {
        // edge (tdest, tapex) exist.
        assert(match == APEXMISSING);
        edgeorient = 1;
      }
    }
    if (match == APEXMISSING) {
      // Two edges are missing. Check if there exist degenerate case.
      //   'searchtet' must be a handle of the exist edge.
      ifarapex = getdiagonalapexindex(&out, i, plus1mod3[edgeorient]);
      if (ifarapex != -1) {
        // Before repair the degenerate case, we should ensure that the
        //   new triangle is valid (it's three corners appear in counter-
        //   clockwise direction). Sep. 5, 2001.
        // Thanks Prof. Renato Cardoso Mesquita (renato@cpdee.ufmg.br).
        isswapable = 1;
        if (edgeorient == 0) {
          if (orient2d(&(in.pointlist[iorg * 2]), &(in.pointlist[idest * 2]),
                       &(in.pointlist[ifarapex * 2])) <= 0) {
            isswapable = 0;
          }
        } else if (edgeorient == 1) {
          if (orient2d(&(in.pointlist[idest * 2]), &(in.pointlist[iapex * 2]),
                       &(in.pointlist[ifarapex * 2])) <= 0) {
            isswapable = 0;
          }
        } else { // edgeorient == 2
          if (orient2d(&(in.pointlist[iapex * 2]), &(in.pointlist[iorg * 2]),
                       &(in.pointlist[ifarapex * 2])) <= 0) {
            isswapable = 0;
          }
        }
        if (isswapable) {
          tfarapex = *(point3d*)(*pointlist)[ifarapex];
          match = matchface(NULL, NULL, tfarapex, &searchtet, boundmark);
          if (match == FACEMATCHING) {
            swapdiagonal(&out, i, edgeorient, plus1mod3[edgeorient]);
            continue;
          }
        }
      }
      ifarapex = getdiagonalapexindex(&out, i, minus1mod3[edgeorient]);
      if (ifarapex != -1) {
        // Before repair the degenerate case, we should ensure that the
        //   new triangle is valid (it's three corners appear in counter-
        //   clockwise direction). Sep. 5, 2001.
        // Thanks Prof. Renato Cardoso Mesquita (renato@cpdee.ufmg.br).
        isswapable = 1;
        if (edgeorient == 0) {
          if (orient2d(&(in.pointlist[iorg * 2]), &(in.pointlist[idest * 2]),
                       &(in.pointlist[ifarapex * 2])) <= 0) {
            isswapable = 0;
          }
        } else if (edgeorient == 1) {
          if (orient2d(&(in.pointlist[idest * 2]), &(in.pointlist[iapex * 2]),
                       &(in.pointlist[ifarapex * 2])) <= 0) {
            isswapable = 0;
          }
        } else { // edgeorient == 2
          if (orient2d(&(in.pointlist[iapex * 2]), &(in.pointlist[iorg * 2]),
                       &(in.pointlist[ifarapex * 2])) <= 0) {
            isswapable = 0;
          }
        }
        if (isswapable) {
          tfarapex = *(point3d*)(*pointlist)[ifarapex];
          match = matchface(NULL, NULL, tfarapex, &searchtet, boundmark);
          if (match == FACEMATCHING) {
            swapdiagonal(&out, i, edgeorient, minus1mod3[edgeorient]);
            continue;
          }
        }
      }
      // Subface is missing.
      matchlist->push(&i);
      // Recover the missing face.
      recoverface(pointlist, &out, i, edgeorient);
    }
  }

  if (maxlooptimes == 0) {
    printf("Recover error in insertfacet():\n");
    printf("  Failed to recover facet %d.\n", facenumber);
    recovererror();
  }
  triangulateiodeinit(&in);
  triangulateiodeinit(&out);
  delete matchlist;
  delete pointlist;
  delete conlist;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// formskeleton()    Create the shell segments and subfaces of a triangula-  //
//                   tion, including PLC edges, facets and facets on the     //
//                   convex hull.                                            //
//                                                                           //
// The PLC edges and facets are read from a .poly or .smesh file. The return //
// value is the number of facets in the file.                                //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

int mesh3d::formskeleton(FILE *polyfile)
{
  list **seglist, **holelist;
  point3d *segendpoints;
  REAL *holecoords;
  char inputline[INPUTLINESIZE];
  char *stringptr;
  int *boundmarkers;
  int facets, polygons, segments, inholes;
  int facetmarkers;
  int head, end1, end2, end3;
  int i, j, k;

  if (poly || smesh) {
    // Read number of facets and number of boundary markers from a .poly or
    //   .smesh file.
    stringptr = readline(inputline, polyfile, inpolyfilename);
    facets = (int) strtol (stringptr, &stringptr, 0);
    stringptr = findfield(stringptr);
    if (*stringptr == '\0') {
      facetmarkers = 0;
    } else {
      facetmarkers = (int) strtol (stringptr, &stringptr, 0);
    }
  } else {
    facets = 0;
  }

  if (facets > 0) {
    if (!quiet) {
      printf("Inserting segments into Delaunay triangulation.\n");
    }
    // Compute a mapping from points to tetrahedra.
    makepointmap();
    // For each facet, create a list for keeping the endpoints of
    //   segments of each facet, and create a list for keeping the
    //   holes point (coordinates) of each facet.
    boundmarkers = new int[facets];
    seglist = new list*[facets];
    holelist = new list*[facets];
    for (i = 0; i < facets; i++) {
      boundmarkers[i] = 0;
      seglist[i] = NULL;
      holelist[i] = NULL;
    }

    if (poly) {
      // For each facet, read and insert all segments.
      for (i = 1; i <= facets; i++) {
        seglist[i - 1] = new list(sizeof(point3d) * 2);
        // Read number of polygons, number of holes and boundary marker of
        //   this facets.
        // Note: I assume each polygon in facet at least has two endpoints.
        stringptr = readline(inputline, polyfile, inpolyfilename);
        polygons = (int) strtol (stringptr, &stringptr, 0);
        stringptr = findfield(stringptr);
        if (*stringptr == '\0') {
          inholes = 0;
          boundmarkers[i - 1] = 0;  // no boundary marker for this facet.
        } else {
          inholes = (int) strtol (stringptr, &stringptr, 0);
          if (facetmarkers == 1) {
            stringptr = findfield(stringptr);
            if (*stringptr == '\0') {
              boundmarkers[i - 1] = 0;  // no boundary marker for this facet.
            } else {
              boundmarkers[i - 1] = (int) strtol (stringptr, &stringptr, 0);
            }
          }
        }

        // For each polygon in this facet, raed and insert all segments.
        for (j = 1; j <= polygons; j++) {
          // Read number of segments of a polygon.
          stringptr = readline(inputline, polyfile, inpolyfilename);
          segments = (int) strtol (stringptr, &stringptr, 0);
          if (segments <= 1) {
            printf("File I/O Error:  Wrong vertex number of polygon %d", j);
            printf(" in facet %d in %s.\n", i, inpolyfilename);
            if (segments == 1) {
              printf("  If you want define a isolate point in facet, you can\n");
              printf("  define a degenrate segment(with two same endpoints)\n ");
              printf("  in stead of.\n");
            }
            exit(1);
          }
          // Read and insert the segments.
          stringptr = findfield(stringptr);
          if (*stringptr == '\0') {
            // Try load another non-empty line to continue
            stringptr = readline(inputline, polyfile, inpolyfilename);
            if (*stringptr == '\0') {
              printf("File I/O Error:  No endpoints for polygon %d", j);
              printf(" in facet %d in %s.\n", i, inpolyfilename);
              exit(1);
            } else {
              head = end1 = (int) strtol (stringptr, &stringptr, 0);
            }
          } else {
            head = end1 = (int) strtol (stringptr, &stringptr, 0);
          }
          for (k = 1; k < segments; k++) {
            stringptr = findfield(stringptr);
            if (*stringptr == '\0') {
              // Try load another non-empty line to continue
              stringptr = readline(inputline, polyfile, inpolyfilename);
              if (*stringptr == '\0') {
                printf("File I/O Error:  Missing %d endpoints for", segments - k);
                printf(" polygon %d in facet %d in %s.\n", j, i, inpolyfilename);
                exit(1);
              } else {
                end2 = (int) strtol (stringptr, &stringptr, 0);
              }
            } else {
              end2 = (int) strtol (stringptr, &stringptr, 0);
            }
            if ((end1 < firstnumber) || (end1 >= firstnumber + inpoints)) {
              if (!quiet) {
                printf("Warning:  Invalid endpoint %d of polygon %d", k, j);
                printf(" in facet %d in %s.\n", i, inpolyfilename);
              }
            } else if ((end2 < firstnumber) || (end2 >= firstnumber + inpoints)) {
              if (!quiet) {
                printf("Warning:  Invalid endpoint %d of polygon %d", k + 1, j);
                printf(" in facet %d in %s.\n", i, inpolyfilename);
              }
            } else {
              segendpoints = (point3d *) seglist[i - 1]->alloc();
              segendpoints[0] = getpoint(end1);
              segendpoints[1] = getpoint(end2);
              if (segendpoints[0] == segendpoints[1]) {
                if (segments == 2) {
                  // A degenrate edge, it represent an isolate point in facet.
                  segendpoints[1] = (point3d) NULL;
                } else {
                  printf("Warning:  Polygon %d has two identical endpoints", j);
                  printf(" in facet %d in %s.\n", i, inpolyfilename);
                }
              } else {
                insertsegment(segendpoints[0], segendpoints[1], boundmarkers[i-1]);
              }
            }
            end1 = end2;
          }
          if (segments > 2) {
            if (((end2 >= firstnumber) && (end2 < firstnumber + inpoints))
                  && ((head >= firstnumber) && (head < firstnumber + inpoints))) {
              segendpoints = (point3d *) seglist[i - 1]->alloc();
              segendpoints[0] = getpoint(end2);
              segendpoints[1] = getpoint(head);
              if (segendpoints[0] == segendpoints[1]) {
                if (segments == 2) {
                  // A degenrate edge, it represent an isolate point in the facet.
                  segendpoints[1] = (point3d) NULL;
                } else {
                  printf("Warning:  Polygon %d has two identical endpoints", j);
                  printf(" in facet %d in %s.\n", i, inpolyfilename);
                }
              } else {
                insertsegment(segendpoints[0], segendpoints[1], boundmarkers[i-1]);
              }
            }
          }
        }

        // Read the holes' coordinates.
        if (inholes > 0) {
          holelist[i - 1] = new list(sizeof(REAL) * 3);
          for (j = 1; j <= inholes; j++) {
            holecoords = (REAL *) holelist[i - 1]->alloc();
            stringptr = readline(inputline, polyfile, inpolyfilename);
            stringptr = findfield(stringptr);
            if (*stringptr == '\0') {
              printf("File I/O Error:  Hole %d in facet %d", j, i);
              printf(" has no coordinates in %s.\n", inpolyfilename);
              exit(1);
            } else {
              holecoords[0] = (REAL) strtod (stringptr, &stringptr);
            }
            stringptr = findfield(stringptr);
            if (*stringptr == '\0') {
              printf("File I/O Error:  Hole %d in facet %d", j, i);
              printf(" is missing its y-coordinate in %s.\n", inpolyfilename);
              exit(1);
            } else {
              holecoords[1] = (REAL) strtod (stringptr, &stringptr);
            }
            stringptr = findfield(stringptr);
            if (*stringptr == '\0') {
              printf("File I/O Error:  Hole %d in facet %d", j, i);
              printf(" is missing its z-coordinate in %s.\n", inpolyfilename);
              exit(1);
            } else {
              holecoords[2] = (REAL) strtod (stringptr, &stringptr);
            }
          }
        }
      } // end inserting all segments loop.
    } else if (smesh) {
      // Read all input triangular facets and its boundary markers.
      for (i = 1; i <= facets; i++) {
        // Read three endpoints of this facet.
        stringptr = readline(inputline, polyfile, insmeshfilename);
        segments = (int) strtol (stringptr, &stringptr, 0);
        if (segments <= 1) {
          printf("File I/O Error:  Wrong vertex number of facet %d", i);
          printf(" in %s.\n", insmeshfilename);
          if (segments == 1) {
            printf("  If you want define a isolate point in facet, you can\n");
            printf("  define a degenrate segment(with two same endpoints)\n ");
            printf("  in stead of.\n");
          }
          exit(1);
        }
        seglist[i - 1] = new list(sizeof(point3d) * 2, segments);
        // In smesh files, we obtain facet's boundary mark at last.
        boundmarkers[i-1] = 0;
        // Read and insert the segments.
        stringptr = findfield(stringptr);
        if (*stringptr == '\0') {
          // Try load another non-empty line to continue
          stringptr = readline(inputline, polyfile, insmeshfilename);
          if (*stringptr == '\0') {
            printf("File I/O Error:  No endpoints for facet %d", i);
            printf(" in %s.\n", insmeshfilename);
            exit(1);
          } else {
            head = end1 = (int) strtol (stringptr, &stringptr, 0);
          }
        } else {
          head = end1 = (int) strtol (stringptr, &stringptr, 0);
        }
        for (k = 1; k < segments; k++) {
          stringptr = findfield(stringptr);
          if (*stringptr == '\0') {
            // Try load another non-empty line to continue
            stringptr = readline(inputline, polyfile, inpolyfilename);
            if (*stringptr == '\0') {
              printf("File I/O Error:  Missing %d endpoints for", segments - k);
              printf(" facet %d in %s.\n", i, insmeshfilename);
              exit(1);
            } else {
              end2 = (int) strtol (stringptr, &stringptr, 0);
            }
          } else {
            end2 = (int) strtol (stringptr, &stringptr, 0);
          }
          if ((end1 < firstnumber) || (end1 >= firstnumber + inpoints)) {
            if (!quiet) {
              printf("Warning:  Invalid endpoint %d of facet %d", k, i);
              printf(" in %s.\n", insmeshfilename);
            }
          } else if ((end2 < firstnumber) || (end2 >= firstnumber + inpoints)) {
            if (!quiet) {
              printf("Warning:  Invalid endpoint %d of facet %d", k + 1, i);
              printf(" in %s.\n", insmeshfilename);
            }
          } else {
            segendpoints = (point3d *) seglist[i - 1]->alloc();
            segendpoints[0] = getpoint(end1);
            segendpoints[1] = getpoint(end2);
            if (segendpoints[0] == segendpoints[1]) {
              if (segments == 2) {
                // A degenrate edge, it represent an isolate point in facet.
                segendpoints[1] = (point3d) NULL;
              } else {
                printf("Warning:  Facet %d has two identical endpoints", i);
                printf(" in %s.\n", insmeshfilename);
              }
            } else {
              insertsegment(segendpoints[0], segendpoints[1], boundmarkers[i-1]);
            }
          }
          end1 = end2;
        }
        if (segments > 2) {
          if (((end2 >= firstnumber) && (end2 < firstnumber + inpoints))
                && ((head >= firstnumber) && (head < firstnumber + inpoints))) {
            segendpoints = (point3d *) seglist[i - 1]->alloc();
            segendpoints[0] = getpoint(end2);
            segendpoints[1] = getpoint(head);
            if (segendpoints[0] == segendpoints[1]) {
              if (segments == 2) {
                // A degenrate edge, it represent an isolate point in the facet.
                segendpoints[1] = (point3d) NULL;
              } else {
                printf("Warning:  Facet %d has two identical endpoints", i);
                printf(" in %s.\n", insmeshfilename);
              }
            } else {
              insertsegment(segendpoints[0], segendpoints[1], boundmarkers[i-1]);
            }
          }
        }
        // Read facet's boundary marker at last.
        if (facetmarkers == 1) {
          stringptr = findfield(stringptr);
          if (*stringptr == '\0') {
            boundmarkers[i - 1] = 0;  // no boundary marker for this facet.
          } else {
            boundmarkers[i - 1] = (int) strtol (stringptr, &stringptr, 0);
          }
        }
      }
    }

    // At this point, we can sure there are no missing segments in the
    //   tetrahedralization(that is: every segment is existed in the domain
    //   and is represented by a contiguous linear sequence of edges of the
    //   tetrahedralization).
    if (!quiet) {
      printf("Inserting facets into Delaunay triangulation.\n");
    }
    // Re-compute a mapping from points to tetrahedra.
    makepointmap();
    // Set up a 2D mesh object. Switches are chosen to read a PSLG (p),
    //   numbers all items starting from zero (rather than one) (z),
    //   generates a list of triangle neighbors (n), no terminal output
    //   except errors (Q). suppresses use of exact arithmetic (X),
    //   suppresses output of segments (P), suppresses node output (N).
    // surfmesh = new mesh2d("pznQXPN");
    surfmesh = new mesh2d("pznQPN");

    for (i = 0; i < facets; i++) {
      if (seglist[i]->len() > 2) {
        insertfacet(seglist[i], holelist[i], boundmarkers[i], i + 1);
      }
      delete seglist[i];
      if (holelist[i]) {
        delete holelist[i];
      }
    }
    delete [] boundmarkers;
    delete [] seglist;
    delete [] holelist;
  }

  return facets;
}

///////////////////////////////////////////////////////////////////////////////
// END                                                                       //
// Segment/Facet (Boundary) Constrained Routines.                            //
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Carving out Holes and Concavities Routines.                               //
// BEGIN                                                                     //
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// infecthull()    Virally infect all of the tetrahedra of the convex hull   //
//                 that are not protected by subfaces.  Where there are      //
//                 subfaces, set boundary markers as appropriate.            //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::infecthull()
{
  triface tetloop, tsymtet;
  tetrahedron **deadtet;
  face hullface;
  point3d horg, hdest, hapex;

  if (verbose) {
    printf("  Marking concavities (external tetrahedra) for elimination.\n");
  }
  tetrahedrons.traversalinit();
  tetloop.tet = tetrahedrontraverse();
  while (tetloop.tet != (tetrahedron *) NULL) {
    // Is this tetrahedron on the hull?
    for (tetloop.loc = 0; tetloop.loc < 4; tetloop.loc++) {
      sym(tetloop, tsymtet);
      if (tsymtet.tet == dummytet) {
        // Is the tetrahedron protected by a subface?
        tspivot(tetloop, hullface);
        if ((hullface.sh == dummysh) || (isnonsolid(hullface))) {
          // The tetrahedron is not protected; infect it.
          if (!infected(tetloop)) {
            infect(tetloop);
            deadtet = (tetrahedron **) viri.alloc();
            *deadtet = tetloop.tet;
            break;  // Go and get next tet.
          }
        } else {
          // The tetrahedron is protected; set boundary markers if appropriate.
          if (mark(hullface) == 0) {
            setmark(hullface, 1);
            horg = sorg(hullface);
            hdest = sdest(hullface);
            hapex = sapex(hullface);
            if (pointmark(horg) == 0) {
              setpointmark(horg, 1);
            }
            if (pointmark(hdest) == 0) {
              setpointmark(hdest, 1);
            }
            if (pointmark(hapex) == 0) {
              setpointmark(hapex, 1);
            }
          }
        }
      }
    }
    tetloop.tet = tetrahedrontraverse();
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// plague()    Spread the virus from all infected tetrahedra to any          //
//             neighbors not protected by subfaces.  Delete all infected     //
//             tetrahedra.                                                   //
//                                                                           //
// This is the procedure that actually creates holes and concavities.        //
//                                                                           //
// This procedure operates in two phases.  The first phase identifies all    //
// the tetrahedra that will die, and marks them as infected.  They are       //
// marked to ensure that each tetrahedron is added to the virus pool only    //
// once, so the procedure will terminate.                                    //
//                                                                           //
// The second phase actually eliminates the infected tetrahedra.  It also    //
// eliminates orphaned segments and points(not done now).                    //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::plague()
{
  triface testtet;
  triface neighbor;
  triface spintet, swaptet, livetet;
  tetrahedron **virusloop;
  tetrahedron **deadtet;
  face neighborshell;
  face testseg, testface;
  point3d testpoint;
  point3d norg, ndest, napex;
  point3d deadorg, deaddest, deadapex, deadoppo;
  int killseg, killorg;
  int edgecount, successbonded, hitbdry;

  if (verbose) {
    printf("  Marking neighbors of marked tetrahedra.\n");
  }
  // Loop through all the infected tetrahedra, spreading the virus to
  //   their neighbors, then to their neighbors' neighbors.
  viri.traversalinit();
  virusloop = (tetrahedron **) viri.traverse();
  while (virusloop != (tetrahedron **) NULL) {
    testtet.tet = *virusloop;
    // A tetrahedron is marked as infected by messing with one of its
    //   vertices(opposite), setting it to an illegal value.  Hence, we
    //   have to temporarily uninfect this tetrahedron so that we can get
    //   the proper vertex of this tetrahedron.
    uninfect(testtet);
    if (verbose > 2) {
      // Assign the tetrahedron an orientation for convenience in
      //   checking its points.
      testtet.loc = 0;
      deadorg = org(testtet);
      deaddest = dest(testtet);
      deadapex = apex(testtet);
      deadoppo = oppo(testtet);
      printf("    Checking (%d, %d, %d, %d)\n", pointmark(deadorg),
             pointmark(deaddest), pointmark(deadapex), pointmark(deadoppo));
    }
    // Check each of the tetrahedron's four neighbors.
    for (testtet.loc = 0; testtet.loc < 4; testtet.loc++) {
      // Find the neighbor.
      sym(testtet, neighbor);
      // Check for a shell between the tetrahedron and its neighbor.
      tspivot(testtet, neighborshell);
      // Check if the neighbor is nonexistent or already infected.
      if ((neighbor.tet == dummytet) || infected(neighbor)) {
        if (neighborshell.sh != dummysh) {
          // There is a subface separating the tetrahedron from its neighbor,
          //   but both tetrahedra are dying, so the subface dies too.
          //   Before deallocte the subface, check each of the three sides
          //   of the subface for preserving subsegments if there need. This
          //   is done by spinning around each edge, checking if it is still
          //   connected to at least one live tetrahedron.
          neighborshell.shver = 0;
          // For keep the same enext() direction.
          findversion(&testtet, &neighborshell, 0);
          for (edgecount = 0; edgecount < 3; edgecount++) {
            sspivot(neighborshell, testseg);
            if (testseg.sh != dummysh) {
              spivot(testseg, testface);
              if (testface.sh == neighborshell.sh) {
                killseg = 1;
                spintet = testtet;
                successbonded = hitbdry = 0;
                while (true) {
                  if (fnextself(spintet)) {
                    if (apex(spintet) == apex(testtet)) {
                      break; // Rewind, can leave now.
                    }
                    if (spintet.tet == testtet.tet) {
                      continue;
                    }
                    if (!infected(spintet)) {
                      // A live tetrahedron.  The segment survives.
                      killseg = 0;
                      tspivot(spintet, testface);
                      if (testface.sh == dummysh) {
                        livetet = spintet;
                        adjustedgering(livetet, CCW);
                        fnextself(livetet);
                        tspivot(livetet, testface);
                      }
                      if (testface.sh != dummysh) {
                        findversion(&testface, &spintet);
                        ssbond(testface, testseg);
                        successbonded = 1;
                        break;
                      }
                    }
                  } else {
                    hitbdry ++;
                    if(hitbdry >= 2) {
                      break;
                    } else {
                      esym(testtet, spintet);
                    }
                  }
                }
                if (killseg) {
                  if (verbose > 1) {
                    printf("  Deleting subsegment (%d, %d)\n",
                           pointmark(sorg(testseg)),
                           pointmark(sdest(testseg)));
                  }
                  shellfacedealloc(&subsegs, testseg.sh);
                } else {
                  if (!successbonded) {
                    // Badly, We must insert a nonsolid subface for holding
                    //   this subsegment; otherwise, it will missing after
                    //   removing all infected tetrahedra.
                    insertsubface(&livetet, NONSOLIDFLAG, 1);
                    tspivot(livetet, testface);
                    findversion(&testface, &testtet);
                    ssbond(testface, testseg);
                  }
                }
              }
            }
            senextself(neighborshell);
            enextself(testtet);
          }
          shellfacedealloc(&subfaces, neighborshell.sh);
          if (neighbor.tet != dummytet) {
            // Make sure the subface doesn't get deallocated again later
            //  when the infected neighbor is visited.
            tsdissolve(neighbor);
          }
        }
      } else {                   // The neighbor exists and is not infected.
        if ((neighborshell.sh == dummysh) || (isnonsolid(neighborshell))) {
          // There is no subface protecting the neighbor, so
          //   the neighbor becomes infected.
          if (verbose > 2) {
            deadorg = org(neighbor);
            deaddest = dest(neighbor);
            deadapex = apex(neighbor);
            deadoppo = oppo(neighbor);
            printf("    Marking (%d, %d, %d, %d)\n", pointmark(deadorg),
             pointmark(deaddest), pointmark(deadapex), pointmark(deadoppo));
          }
          infect(neighbor);
          // Ensure that the neighbor's neighbors will be infected.
          deadtet = (tetrahedron **) viri.alloc();
          *deadtet = neighbor.tet;
        } else {               // The neighbor is protected by a subface.
          // Remove this tetrahedron from the subface.
          stdissolve(neighborshell);
          // The subface becomes a boundary.  Set markers accordingly.
          if (mark(neighborshell) == 0) {
            setmark(neighborshell, 1);
          }
          norg = org(neighbor);
          ndest = dest(neighbor);
          napex = apex(neighbor);
          if (pointmark(norg) == 0) {
            setpointmark(norg, 1);
          }
          if (pointmark(ndest) == 0) {
            setpointmark(ndest, 1);
          }
          if (pointmark(napex) == 0) {
            setpointmark(napex, 1);
          }
        }
      }
    }
    // Remark the tetrahedron as infected, so it doesn't get added to the
    //   virus pool again.
    infect(testtet);
    virusloop = (tetrahedron **) viri.traverse();
  }

  if (verbose) {
    printf("  Deleting marked tetrahedra.\n");
  }
  viri.traversalinit();
  virusloop = (tetrahedron **) viri.traverse();
  while (virusloop != (tetrahedron **) NULL) {
    testtet.tet = *virusloop;

    // Check each of the four corners of the tetrahedron for elimination.
    // To be finished...

    // Record changes in the number of boundary faces, and disconnect
    //   dead tetrahedra from their neighbors.
    for (testtet.loc = 0; testtet.loc < 4; testtet.loc++) {
      sym(testtet, neighbor);
      if (neighbor.tet == dummytet) {
        // There is no neighboring tetrahedron on this face, so this face
        //   is a boundary face.  This tetrahedron is being deleted, so this
        //   boundary face is deleted.
        hullsize--;
      } else {
        // Disconnect the tetrahedron from its neighbor.
        dissolve(neighbor);
        // There is a neighboring tetrahedron on this face, so this face
        //   becomes a boundary face when this tetrahedron is deleted.
        hullsize++;
      }
    }
    // Return the dead tetrahedron to the pool of tetrahedra.
    tetrahedrondealloc(testtet.tet);
    virusloop = (tetrahedron **) viri.traverse();
  }
  // Empty the virus pool.
  viri.restart();
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// regionplague()    Spread regional attributes and/or volume constraints    //
//                   (from a .poly file) throughout the mesh.                //
//                                                                           //
// This procedure operates in two phases.  The first phase spreads an        //
// attribute and/or an volume constraint through a (segment-bounded) region. //
// The tetrahedra are marked to ensure that each tetrahedra is added to the  //
// virus pool only once, so the procedure will terminate.                    //
//                                                                           //
// The second phase uninfects all infected tetrahedra, returning them to     //
// normal.                                                                   //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::regionplague(REAL attribute, REAL volume)
{
  triface testtet;
  triface neighbor;
  tetrahedron **virusloop;
  tetrahedron **regiontet;
  face neighborshell;
  point3d regionorg, regiondest, regionapex, regionoppo;

  if (verbose > 1) {
    printf("  Marking neighbors of marked tetrahedra.\n");
  }
  // Loop through all the infected tetrahedra, spreading the attribute
  //   and/or volume constraint to their neighbors, then to their neighbors'
  //   neighbors.
  viri.traversalinit();
  virusloop = (tetrahedron **) viri.traverse();
  while (virusloop != (tetrahedron **) NULL) {
    testtet.tet = *virusloop;
    // A tetrahedron is marked as infected by messing with one of its
    //   vertices(opposite), setting it to an illegal value.  Hence, we
    //   have to temporarily uninfect this tetrahedron so that we can get
    //   the proper vertex of this tetrahedron.
    uninfect(testtet);
    if (regionattrib) {
      // Set an attribute.
      setelemattribute(testtet.tet, eextras, attribute);
    }
    if (varvolume) {
      // Set an volume constraint.
      setvolumebound(testtet.tet, volume);
    }
    if (verbose > 2) {
      // Assign the tetrahedron an orientation for convenience in
      //   checking its points.
      testtet.loc = 0;
      regionorg = org(testtet);
      regiondest = dest(testtet);
      regionapex = apex(testtet);
      regionoppo = oppo(testtet);
      printf("    Checking (%d, %d, %d, %d)\n", pointmark(regionorg),
        pointmark(regiondest), pointmark(regionapex), pointmark(regionoppo));
    }
    // Check each of the tetrahedron's four neighbors.
    for (testtet.loc = 0; testtet.loc < 4; testtet.loc++) {
      // Find the neighbor.
      sym(testtet, neighbor);
      // Check for a subface between the tetrahedron and its neighbor.
      tspivot(testtet, neighborshell);
      // Make sure the neighbor exists, is not already infected, and
      //   isn't protected by a subface, or is protected by a nonsolid
      //   subface.
      if ((neighbor.tet != dummytet) && !infected(neighbor)
          && ((neighborshell.sh == dummysh) || (isnonsolid(neighborshell)))) {
        if (verbose > 2) {
          regionorg = org(neighbor);
          regiondest = dest(neighbor);
          regionapex = apex(neighbor);
          regionoppo = oppo(neighbor);
          printf("    Marking (%d, %d, %d, %d)\n", pointmark(regionorg),
            pointmark(regiondest), pointmark(regionapex), pointmark(regionoppo));
        }
        // Infect the neighbor.
        infect(neighbor);
        // Ensure that the neighbor's neighbors will be infected.
        regiontet = (tetrahedron **) viri.alloc();
        *regiontet = neighbor.tet;
      }
    }
    // Remark the tetrahedron as infected, so it doesn't get added to the
    //   virus pool again.
    infect(testtet);
    virusloop = (tetrahedron **) viri.traverse();
  }

  // Uninfect all tetrahedra.
  if (verbose > 1) {
    printf("  Unmarking marked tetrahedra.\n");
  }
  viri.traversalinit();
  virusloop = (tetrahedron **) viri.traverse();
  while (virusloop != (tetrahedron **) NULL) {
    testtet.tet = *virusloop;
    uninfect(testtet);
    virusloop = (tetrahedron **) viri.traverse();
  }
  // Empty the virus pool.
  viri.restart();
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// carveholes()    Find the holes and infect them.  Find the volume          //
//                 constraints and infect them.  Infect the convex hull.     //
//                 Spread the infection and kill tetrahedra.  Spread the     //
//                 volume constraints.                                       //
//                                                                           //
// This routine mainly calls other routines to carry out all these functions.//                                                               //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::carveholes(REAL *holelist, int holes, REAL *regionlist,
                        int regions)
{
  triface searchtet;
  tetrahedron *tptr;
  triface *holetets;
  triface *regiontets;
  tetrahedron **holetet;
  tetrahedron **regiontet;
  enum locateresult intersect;
  int i;

  if (!(quiet || (noholes && convex))) {
    printf("Removing unwanted tetrahedra.\n");
    if (verbose && (holes > 0)) {
      printf("  Marking holes for elimination.\n");
    }
  }

  if ((holes > 0) && !noholes) {
    // Allocate storage for the tetrahedra in which hole points fall.
    holetets = (triface *) new triface[holes];
  }

  if (regions > 0) {
    // Allocate storage for the tetrahedra in which region points fall.
    regiontets = (triface *) new triface[regions];
  }

  // Now, we have to find all the holes and regions BEFORE we infect hull
  //   and carve the holes, because locate() won't work when there exist
  //   infect tetrahedra and the tetrahedronlization is no longer convex.

  if ((holes > 0) && !noholes) {
    // Infect each tetrahedron in which a hole lies.
    for (i = 0; i < 3 * holes; i += 3) {
      // Ignore holes that aren't within the bounds of the mesh.
      if ((holelist[i] >= xmin) && (holelist[i] <= xmax)
          && (holelist[i + 1] >= ymin) && (holelist[i + 1] <= ymax)
          && (holelist[i + 2] >= zmin) && (holelist[i + 2] <= zmax)) {
        // Start searching from some tetrahedron on the outer boundary.
        searchtet.tet = dummytet;
        searchtet.loc = 0;
        symself(searchtet);
        // Ensure that the hole is above the boundary face; otherwise,
        //   locate() will falsely report that the hole falls within the
        //   starting tetrahedron.
        adjustedgering(searchtet, CCW);
        if (isaboveplane(&searchtet, &holelist[i])) {
          // Find a tetrahedron that contains the hole.
          intersect = locate(&holelist[i], &searchtet);
          if ((intersect != OUTSIDE) && (!infected(searchtet))) {
            // Record the tetrahedron for processing carve hole.
            holetets[i / 3] = searchtet;
          }
        }
      }
    }
  }

  if (regions > 0) {
    // Find the starting tetrahedron for each region.
    for (i = 0; i < regions; i++) {
      regiontets[i].tet = dummytet;
      // Ignore region points that aren't within the bounds of the mesh.
      if ((regionlist[5 * i] >= xmin) && (regionlist[5 * i] <= xmax) &&
          (regionlist[5 * i + 1] >= ymin) && (regionlist[5 * i + 1] <= ymax) &&
          (regionlist[5 * i + 2] >= zmin) && (regionlist[5 * i + 2] <= zmax)) {
        // Start searching from some tetrahedron on the outer boundary.
        searchtet.tet = dummytet;
        searchtet.loc = 0;
        symself(searchtet);
        // Ensure that the region point above the boundary  face; otherwise,
        //   locate() will falsely report that the region point falls within
        //   the starting tetrahedron.
        adjustedgering(searchtet, CCW);
        if (isaboveplane(&searchtet, &regionlist[5 * i])) {
          // Find a tetrahedron that contains the region point.
          intersect = locate(&regionlist[5 * i], &searchtet);
          if ((intersect != OUTSIDE) && (!infected(searchtet))) {
            // Record the tetrahedron for processing after the
            //   holes have been carved.
            regiontets[i] = searchtet;
          }
        }
      }
    }
  }

  if (((holes > 0) && !noholes) || !convex || (regions > 0)) {
    // Initialize a pool of viri to be used for holes, concavities,
    //   regional attributes, and/or regional volume constraints.
    viri.init(sizeof(tetrahedron *), VIRUSPERBLOCK, POINTER, 0);
  }

  if (!convex) {
    // Mark as infected any unprotected tetrahedra on the boundary.
    //   This is one way by which concavities are created.
    infecthull();
  }

  if ((holes > 0) && !noholes) {
    // Infect the hole tetrahedron.  This is done by marking the
    //  tetrahedron as infect and including the tetrahedron in
    //  the virus pool.
    for (i = 0; i < holes; i++) {
      infect(holetets[i]);
      holetet = (tetrahedron **) viri.alloc();
      *holetet = holetets[i].tet;
    }
  }

  if (viri.items > 0) {
    // Carve the holes and concavities.
    plague();
  }
  // The virus pool should be empty now.

  if (regions > 0) {
    if (!quiet) {
      if (regionattrib) {
        if (varvolume) {
          printf("Spreading regional attributes and volume constraints.\n");
        } else {
          printf("Spreading regional attributes.\n");
        }
      } else {
        printf("Spreading regional volume constraints.\n");
      }
    }
    if (regionattrib && !refine) {
      // Assign every tetrahedron a regional attribute of zero.
      tetrahedrons.traversalinit();
      tptr = tetrahedrontraverse();
      while (tptr != (tetrahedron *) NULL) {
        setelemattribute(tptr, eextras, 0.0);
        tptr = tetrahedrontraverse();
      }
    }
    for (i = 0; i < regions; i++) {
      if (regiontets[i].tet != dummytet) {
        // Make sure the tetrahedron under consideration still exists.
        //   It may have been eaten by the virus.
        if (!isdead(&(regiontets[i]))) {
          // Put one tetrahedron in the virus pool.
          infect(regiontets[i]);
          regiontet = (tetrahedron **) viri.alloc();
          *regiontet = regiontets[i].tet;
          // Apply one region's attribute and/or volume constraint.
          regionplague(regionlist[5 * i + 3], regionlist[5 * i + 4]);
          // The virus pool should be empty now.
        }
      }
    }
    if (regionattrib && !refine) {
      // Note the fact that each tetrahedron has an additional attribute.
      eextras++;
    }
  }

  // Free up memory.
  if (((holes > 0) && !noholes) || !convex || (regions > 0)) {
    viri.deinit();
  }
  if ((holes > 0) && !noholes) {
    delete [] holetets;
  }
  if (regions > 0) {
    delete [] regiontets;
  }
}

///////////////////////////////////////////////////////////////////////////////
// END                                                                       //
// Carving out Holes and Concavities Routines.                               //
///////////////////////////////////////////////////////////////////////////////
