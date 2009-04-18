#ifndef constrainCXX
#define constrainCXX

#include "tetgen.h"

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// finddirection()    Find the tet on the path from one point to another.    //
//                                                                           //
// The path starts from 'searchtet''s origin and ends at 'endpt'. On finish, //
// 'searchtet' contains a tet on the path, its origin does not change.       //
//                                                                           //
// The return value indicates one of the following cases (let 'searchtet' be //
// abcd, a is the origin of the path):                                       //
//   - ACROSSVERT, edge ab is collinear with the path;                       //
//   - ACROSSEDGE, edge bc intersects with the path;                         //
//   - ACROSSFACE, face bcd intersects with the path.                        //
//                                                                           //
// WARNING: This routine is designed for convex triangulations, and will not //
// generally work after the holes and concavities have been carved.          //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

enum tetgenmesh::intersection tetgenmesh::finddirection(triface* searchtet, 
  point endpt)
{
  triface neightet;
  point pa, pb, pc, pd, pn;
  enum {HMOVE, RMOVE, LMOVE} nextmove;
  enum {HCOPLANE, RCOPLANE, LCOPLANE, NCOPLANE} cop;
  REAL hori, rori, lori;
  REAL dmin, dist;

  tetrahedron ptr;
  int *iptr, tver;

  // The origin is fixed.
  pa = org(*searchtet);
  if ((point) searchtet->tet[7] == dummypoint) {
    // A hull tet. Choose the neighbor of its base face.
    searchtet->loc = 0;
    symself(*searchtet);
    // Reset the origin to be pa.
    if ((point) searchtet->tet[4] == pa) {
      searchtet->loc = 0; searchtet->ver = 0;
    } else if ((point) searchtet->tet[5] == pa) {
      searchtet->loc = 0; searchtet->ver = 2;
    } else if ((point) searchtet->tet[6] == pa) {
      searchtet->loc = 0; searchtet->ver = 4;
    } else {
      assert((point) searchtet->tet[7] == pa); // SELF_CHECK
      searchtet->loc = 1; searchtet->ver = 2;
    }
  }
  if (searchtet->ver & 01) {
    // Switch to the 0th edge ring.
    esymself(*searchtet);
    enextself(*searchtet);
  }
  pb = dest(*searchtet);
  pc = apex(*searchtet);

  // Check whether the destination or apex is 'endpt'.
  if (pb == endpt) {
    // pa->pb is the search edge.
    return ACROSSVERT;
  }
  if (pc == endpt) {
    // pa->pc is the search edge.
    enext2self(*searchtet);
    esymself(*searchtet);
    return ACROSSVERT;
  }

  // Walk through tets at pa until the right one is found.
  while (1) {

    pd = oppo(*searchtet);

    if (b->verbose > 2) {
      printf("      From tet (%d, %d, %d, %d) to %d.\n", pointmark(pa),
        pointmark(pb), pointmark(pc), pointmark(pd), pointmark(endpt));
    }

    // Check whether the opposite vertex is 'endpt'.
    if (pd == endpt) {
      // pa->pd is the search edge.
      enext0fnextself(*searchtet);
      enext2self(*searchtet);
      esymself(*searchtet);
      return ACROSSVERT;
    }
    // Check if we have entered outside of the domain.
    if (pd == dummypoint) {
      assert(0);
    }

    // Now assume that the base face abc coincides with the horizon plane,
    //   and d lies above the horizon.  The search point 'endpt' may lie
    //   above or below the horizon.  We test the orientations of 'endpt'
    //   with respect to three planes: abc (horizon), bad (right plane),
    //   and acd (left plane). 
    hori = orient3d(pa, pb, pc, endpt);
    rori = orient3d(pb, pa, pd, endpt);
    lori = orient3d(pa, pc, pd, endpt);
    orient3dcount += 3;

    // Now decide the tet to move.  It is possible there are more than one
    //   tet are viable moves. Use the opposite points of thier neighbors
    //   to discriminate, i.e., we choose the tet whose opposite point has
    //   the shortest distance to 'endpt'.
    if (hori > 0) {
      if (rori > 0) {
        if (lori > 0) {
          // Any of the three neighbors is a viable move.
          nextmove = HMOVE;
          sym(*searchtet, neightet);
          pn = oppo(neightet);
          if (pn != dummypoint) {
            dmin = NORM2(endpt[0] - pn[0], endpt[1] - pn[1], endpt[2] - pn[2]);
          } else {
            dmin = NORM2(xmax - xmin, ymax - ymin, zmax - zmin);
          }
          enext0fnext(*searchtet, neightet);
          symself(neightet);
          pn = oppo(neightet);
          if (pn != dummypoint) {
            dist = NORM2(endpt[0] - pn[0], endpt[1] - pn[1], endpt[2] - pn[2]);
          } else {
            dist = dmin;
          }
          if (dist < dmin) {
            nextmove = RMOVE;
            dmin = dist;
          }
          enext2fnext(*searchtet, neightet);
          symself(neightet);
          pn = oppo(neightet);
          if (pn != dummypoint) {
            dist = NORM2(endpt[0] - pn[0], endpt[1] - pn[1], endpt[2] - pn[2]);
          } else {
            dist = dmin;
          }
          if (dist < dmin) {
            nextmove = LMOVE;
            dmin = dist;
          }
        } else {
          // Two tets, below horizon and below right, are viable.
          nextmove = HMOVE;
          sym(*searchtet, neightet);
          pn = oppo(neightet);
          if (pn != dummypoint) {
            dmin = NORM2(endpt[0] - pn[0], endpt[1] - pn[1], endpt[2] - pn[2]);
          } else {
            dmin = NORM2(xmax - xmin, ymax - ymin, zmax - zmin);
          }
          enext0fnext(*searchtet, neightet);
          symself(neightet);
          pn = oppo(neightet);
          if (pn != dummypoint) {
            dist = NORM2(endpt[0] - pn[0], endpt[1] - pn[1], endpt[2] - pn[2]);
          } else {
            dist = dmin;
          }
          if (dist < dmin) {
            nextmove = RMOVE;
            dmin = dist;
          }
        }
      } else {
        if (lori > 0) {
          // Two tets, below horizon and below left, are viable.
          nextmove = HMOVE;
          sym(*searchtet, neightet);
          pn = oppo(neightet);
          if (pn != dummypoint) {
            dmin = NORM2(endpt[0] - pn[0], endpt[1] - pn[1], endpt[2] - pn[2]);
          } else {
            dmin = NORM2(xmax - xmin, ymax - ymin, zmax - zmin);
          }
          enext2fnext(*searchtet, neightet);
          symself(neightet);
          pn = oppo(neightet);
          if (pn != dummypoint) {
            dist = NORM2(endpt[0] - pn[0], endpt[1] - pn[1], endpt[2] - pn[2]);
          } else {
            dist = dmin;
          }
          if (dist < dmin) {
            nextmove = LMOVE;
            dmin = dist;
          }
        } else {
          // The tet below horizon is chosen.
          nextmove = HMOVE;
        }
      }
    } else {
      if (rori > 0) {
        if (lori > 0) {
          // Two tets, below right and below left, are viable.
          nextmove = RMOVE;
          enext0fnext(*searchtet, neightet);
          symself(neightet);
          pn = oppo(neightet);
          if (pn != dummypoint) {
            dmin = NORM2(endpt[0] - pn[0], endpt[1] - pn[1], endpt[2] - pn[2]);
          } else {
            dmin = NORM2(xmax - xmin, ymax - ymin, zmax - zmin);
          }
          enext2fnext(*searchtet, neightet);
          symself(neightet);
          pn = oppo(neightet);
          if (pn != dummypoint) {
            dist = NORM2(endpt[0] - pn[0], endpt[1] - pn[1], endpt[2] - pn[2]);
          } else {
            dist = dmin;
          }
          if (dist < dmin) {
            nextmove = LMOVE;
            dmin = dist;
          }
        } else {
          // The tet below right is chosen.
          nextmove = RMOVE;
        }
      } else {
        if (lori > 0) {
          // The tet below left is chosen.
          nextmove = LMOVE;
        } else {
          // 'endpt' lies either on the plane(s) or across face bcd.
          if (hori == 0) {
            if (rori == 0) {
              // pa->'endpt' is COLLINEAR with pa->pb.
              return ACROSSVERT;
            }
            if (lori == 0) {
              // pa->'endpt' is COLLINEAR with pa->pc.
              enext2self(*searchtet);
              esymself(*searchtet);
              return ACROSSVERT;
            }
            // pa->'endpt' crosses the edge pb->pc.
            // enextself(*searchtet);
            // return ACROSSEDGE;
            cop = HCOPLANE;
            break;
          }
          if (rori == 0) {
            if (lori == 0) {
              // pa->'endpt' is COLLINEAR with pa->pd.
              enext0fnextself(*searchtet); // face abd.
              enext2self(*searchtet);
              esymself(*searchtet);
              return ACROSSVERT;
            }
            // pa->'endpt' crosses the edge pb->pd.
            // enext0fnextself(*searchtet); // face abd.
            // enextself(*searchtet);
            // return ACROSSEDGE;
            cop = RCOPLANE;
            break;
          }
          if (lori == 0) {
            // pa->'endpt' crosses the edge pc->pd.
            // enext2fnextself(*searchtet);  // face cad
            // enext2self(*searchtet);
            // return ACROSSEDGE;
            cop = LCOPLANE;
            break;
          }
          // pa->'endpt' crosses the face bcd.
          // enextfnextself(*searchtet);
          // return ACROSSFACE;
          cop = NCOPLANE;
          break;
        }
      }
    }

    // Move to the next tet, fix pa as its origin.
    if (nextmove == RMOVE) {
      fnextself(*searchtet);
    } else if (nextmove == LMOVE) {
      enext2self(*searchtet);
      fnextself(*searchtet);
      enextself(*searchtet);
    } else { // HMOVE
      symedgeself(*searchtet);
      enextself(*searchtet);
    }
    assert(org(*searchtet) == pa); // SELF_CHECK
    pb = dest(*searchtet);
    pc = apex(*searchtet);

  } // while (1)

  // Either case ACROSSEDGE or ACROSSFACE.
  if (b->epsilon > 0) {
    // Use tolerance to re-evaluate the orientations.
    if (cop != HCOPLANE) {
      if (iscoplanar(pa, pb, pc, endpt, hori)) hori = 0;
    }
    if (cop != RCOPLANE) {
      if (iscoplanar(pb, pa, pd, endpt, rori)) rori = 0;
    }
    if (cop != LCOPLANE) {
      if (iscoplanar(pa, pc, pd, endpt, lori)) lori = 0;
    }
    // It is not possible that all orientations are zero.
    assert(!((hori == 0) && (rori == 0) && (lori == 0))); // SELF_CHECK
  }
  
  // Now decide the degenerate cases.
  if (hori == 0) {
    if (rori == 0) {
      // pa->'endpt' is COLLINEAR with pa->pb.
      return ACROSSVERT;
    }
    if (lori == 0) {
      // pa->'endpt' is COLLINEAR with pa->pc.
      enext2self(*searchtet);
      esymself(*searchtet);
      return ACROSSVERT;
    }
    // pa->'endpt' crosses the edge pb->pc.
    return ACROSSEDGE;
  }
  if (rori == 0) {
    if (lori == 0) {
      // pa->'endpt' is COLLINEAR with pa->pd.
      enext0fnextself(*searchtet); // face abd.
      enext2self(*searchtet);
      esymself(*searchtet);
      return ACROSSVERT;
    }
    // pa->'endpt' crosses the edge pb->pd.
    enext0fnextself(*searchtet); // face abd.
    esymself(*searchtet);
    enextself(*searchtet);
    return ACROSSEDGE;
  }
  if (lori == 0) {
    // pa->'endpt' crosses the edge pc->pd.
    enext2fnextself(*searchtet);  // face cad
    esymself(*searchtet);
    return ACROSSEDGE;
  }
  // pa->'endpt' crosses the face bcd.
  return ACROSSFACE;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// scoutsegment()    Look for a given segment in the tetrahedralization T.   //
//                                                                           //
// Search an edge in the tetrahedralization that matches the given segmment. //
// If such an edge is found, the segment is 'locked' at the edge.            //
//                                                                           //
// If 'searchtet' != NULL, it's origin must be the origin of 'sseg'.  It is  //
// used as the starting tet for searching the edge.                          //
//                                                                           //
// The returned value indicates one of the following cases:                  //
//   - SHAREVERT, the segment exists and is inserted in T;                   //
//   - ACROSSVERT, a vertex ('refpt') lies on the segment;                   //
//   - ACROSSEDGE, the segment is missing;                                   //
//   - ACROSSFACE, the segment is missing;                                   //
//                                                                           //
// If the returned value is ACROSSEDGE or ACROSSFACE, i.e., the segment is   //
// missing, 'refpt' returns the reference point for splitting thus segment,  //
// 'searchtet' returns a tet containing the 'refpt'.                         //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

enum tetgenmesh::intersection tetgenmesh::scoutsegment(face* sseg,
  triface* searchtet, point* refpt)
{
  triface neightet, reftet;
  face splitsh, checkseg;
  point startpt, endpt;
  point pa, pb, pc, pd;
  enum location loc;
  enum intersection dir;
  REAL angmax, ang;
  long facecount;
  bool orgflag;
  int types[2], poss[4];
  int shver, pos, i;

  tetrahedron ptr;
  shellface sptr;
  int *iptr, tver;

  // Is 'searchtet' a valid handle?
  if (searchtet->tet == NULL) {
    orgflag = false;
    // Search a tet whose origin is one of the endpoints of 'sseg'.
    for (shver = 0; shver < 2 && !orgflag; shver++) {
      startpt = (point) sseg->sh[shver + 3];
      decode(point2tet(startpt), *searchtet);
      if ((searchtet->tet != NULL) && (searchtet->tet[4] != NULL)) {
        // Check if this tet contains pa.
        for (i = 4; i < 8 && !orgflag; i++) {
          if ((point) searchtet->tet[i] == startpt) {
            // Found. Set pa as its origin.
            switch (i) {
              case 4: searchtet->loc = 0; searchtet->ver = 0; break;
              case 5: searchtet->loc = 0; searchtet->ver = 2; break;
              case 6: searchtet->loc = 0; searchtet->ver = 4; break;
              case 7: searchtet->loc = 1; searchtet->ver = 2; break;
            }
            sseg->shver = shver;
            orgflag = true;
          }
        }
      }
    }
    assert(orgflag); // SELF_CHECK
  } else {
    startpt = sorg(*sseg);
    assert(org(*searchtet) == startpt); // SELF_CHECK
  }
  endpt = sdest(*sseg);

  if (b->verbose > 1) {
    printf("    Scout seg (%d, %d).\n", pointmark(startpt), pointmark(endpt));
  }

  dir = finddirection(searchtet, endpt);

  if (dir == ACROSSVERT) {
    pd = dest(*searchtet);
    if (pd == endpt) {
      // Found! Insert the segment.
      tsspivot(*searchtet, checkseg);  // SELF_CHECK
      if (checkseg.sh == NULL) {
        neightet = *searchtet;
        do {
          tssbond1(neightet, *sseg);
          fnextself(neightet);
        } while (neightet.tet != searchtet->tet);
      } else {
        // Collision! This can happy during facet recovery.
        // See fig/dump-cavity-case19, -case20.
        assert(checkseg.sh == sseg->sh); // SELF_CHECK
      }
      // The job is done. 
      return SHAREVERT;
    } else {
      // A point is on the path.
      *refpt = pd;
      return ACROSSVERT;
    }
  }

  if (b->verbose > 1) {
    printf("    Scout ref point of seg (%d, %d).\n", pointmark(startpt), 
      pointmark(endpt));
  }
  facecount = across_face_count;

  enextfnextself(*searchtet); // Go to the opposite face.
  symedgeself(*searchtet); // Enter the adjacent tet.

  pa = org(*searchtet);
  angmax = interiorangle(pa, startpt, endpt, NULL);
  *refpt = pa;
  pb = dest(*searchtet);
  ang = interiorangle(pb, startpt, endpt, NULL);
  if (ang > angmax) {
    angmax = ang;
    *refpt = pb;
  }

  // Check whether two segments are intersecting.
  if (dir == ACROSSEDGE) {
    tsspivot(*searchtet, checkseg);
    if (checkseg.sh != NULL) {
      printf("Error:  Invalid PLC. Two segments intersect.\n");
      startpt = farsorg(*sseg);
      endpt = farsdest(*sseg);
      pa = farsorg(checkseg);
      pb = farsdest(checkseg);
      printf("  1st: (%d, %d), 2nd: (%d, %d).\n", pointmark(startpt), 
        pointmark(endpt), pointmark(pa), pointmark(pb));
      terminatetetgen(1);
    }
    across_edge_count++;
  }
  
  pc = apex(*searchtet);
  ang = interiorangle(pc, startpt, endpt, NULL);
  if (ang > angmax) {
    angmax = ang;
    *refpt = pc;
  }
  reftet = *searchtet; // Save the tet containing the refpt.

  // Search intersecting faces along the segment.
  while (1) {

    pd = oppo(*searchtet);
    assert(pd != dummypoint);  // SELF_CHECK

    if (b->verbose > 2) {
      printf("      Passing face (%d, %d, %d, %d), dir(%d).\n", pointmark(pa),
        pointmark(pb), pointmark(pc), pointmark(pd), (int) dir);
    }
    across_face_count++;

    // Stop if we meet 'endpt'.
    if (pd == endpt) break;

    ang = interiorangle(pd, startpt, endpt, NULL);
    if (ang > angmax) {
      angmax = ang;
      *refpt = pd;
      reftet = *searchtet;
    }

    // Find a face intersecting the segment.
    if (dir == ACROSSFACE) {
      // One of the three oppo faces in 'searchtet' intersects the segment.
      neightet.tet = searchtet->tet;
      neightet.ver = 0;
      for (i = 0; i < 3; i++) {
        neightet.loc = locpivot[searchtet->loc][i];
        pa = org(neightet);
        pb = dest(neightet);
        pc = apex(neightet);
        pd = oppo(neightet); // The above point.
        if (tri_edge_test(pa, pb, pc, startpt, endpt, pd, 1, types, poss)) {
          dir = (enum intersection) types[0];
          pos = poss[0];
          break;
        } else {
          dir = DISJOINT;
          pos = 0;
        }
      }
      assert(dir != DISJOINT);  // SELF_CHECK
    } else { // dir == ACROSSEDGE
      // Check the two opposite faces (of the edge) in 'searchtet'.
      neightet = *searchtet;
      neightet.ver = 0;
      for (i = 0; i < 2; i++) {
        neightet.loc = locverpivot[searchtet->loc][searchtet->ver][i];
        pa = org(neightet);
        pb = dest(neightet);
        pc = apex(neightet);
        pd = oppo(neightet); // The above point.
        if (tri_edge_test(pa, pb, pc, startpt, endpt, pd, 1, types, poss)) {
          dir = (enum intersection) types[0];
          pos = poss[0];
          break;
        } else {
          dir = DISJOINT;
          pos = 0;
        }
      }
      if (dir == DISJOINT) {
        // No intersection. Go to the next tet.
        dir = ACROSSEDGE;
        fnextself(*searchtet);
        continue;
      }
    }

    if (dir == ACROSSVERT) {
      // This segment passing a vertex. Choose it and return.
      for (i = 0; i < pos; i++) {
        enextself(neightet);
      }
      pd = org(neightet);
      if (b->verbose > 2) {
        angmax = interiorangle(pd, startpt, endpt, NULL);
      }
      *refpt = pd;
      break;
    }
    if (dir == ACROSSEDGE) {
      // Get the edge intersects with the segment.
      for (i = 0; i < pos; i++) {
        enextself(neightet);
      }
    }
    // Go to the next tet.
    symedge(neightet, *searchtet);

    if (dir == ACROSSEDGE) {
      // Check whether two segments are intersecting.
      tsspivot(*searchtet, checkseg);
      if (checkseg.sh != NULL) {
        printf("Error:  Invalid PLC! Two segments intersect.\n");
        startpt = farsorg(*sseg);
        endpt = farsdest(*sseg);
        pa = farsorg(checkseg);
        pb = farsdest(checkseg);
        printf("    1st: (%d, %d), 2nd: (%d, %d).\n", pointmark(startpt), 
          pointmark(endpt), pointmark(pa), pointmark(pb));
        terminatetetgen(1);
      }
      across_edge_count++;
    }

  } // while (1)

  // dir is either ACROSSVERT, or ACROSSEDGE, or ACROSSFACE.
  if (b->verbose > 2) {
    printf("      Refpt %d (%g), visited %ld faces.\n", pointmark(*refpt),
      angmax / PI * 180.0, (int) dir, across_face_count - facecount);
  }
  if (across_face_count - facecount > across_max_count) {
    across_max_count = across_face_count - facecount;
  }

  *searchtet = reftet;
  return dir;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// getsegmentsplitpoint()    Calculate a split point in the given segment.   //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::getsegmentsplitpoint(face* sseg, point refpt, REAL* vt)
{
  point ei, ej, ek;
  REAL split, L, d, d1, d2, d3;
  int stype, sign;
  int i;

  // Decide the type of this segment.
  sign = 1;
  ei = sorg(*sseg);
  ej = sdest(*sseg);

  if (getpointtype(ei) == ACUTEVERTEX) {
    if (getpointtype(ej) == ACUTEVERTEX) {
      // Both ei and ej are ACUTEVERTEX.
      stype = 0;
    } else {
      // ej is either a RIDGEVERTEX or a STEINERVERTEX.
      stype = 1;
    }
  } else {
    if (getpointtype(ei) == RIDGEVERTEX) {
      if (getpointtype(ej) == ACUTEVERTEX) {
        stype = 1; sign = -1;
      } else {
        if (getpointtype(ej) == RIDGEVERTEX) {
          // Both ei and ej are non-acute.
          stype = 0;
        } else {
          // ej is a STEINERVETEX.
          ek = farsdest(*sseg);
          if (getpointtype(ek) == ACUTEVERTEX) {
            stype = 1; sign = -1;
          } else {
            stype = 0;
          }
        }
      }
    } else {
      // ei is a STEINERVERTEX.
      if (getpointtype(ej) == ACUTEVERTEX) {
        stype = 1; sign = -1;
      } else {
        ek = farsorg(*sseg);
        if (getpointtype(ej) == RIDGEVERTEX) {
          if (getpointtype(ek) == ACUTEVERTEX) {
            stype = 1;
          } else {
            stype = 0;
          }
        } else {
          // Both ei and ej are STEINERVETEXs. ei has priority.
          if (getpointtype(ek) == ACUTEVERTEX) {
            stype = 1;
          } else {
            ek = farsdest(*sseg);
            if (getpointtype(ek) == ACUTEVERTEX) {
              stype = 1; sign = -1;
            } else {
              stype = 0;
            }
          }
        }
      }
    }
  }

  // Adjust the endpoints: ei, ej.
  if (sign == -1) {
    sesymself(*sseg);
    ei = sorg(*sseg);
    ej = sdest(*sseg);
  }

  if (b->verbose > 1) {
    printf("    Split a type-%d seg(%d, %d) ref(%d)", stype,
      pointmark(ei), pointmark(ej), pointmark(refpt));
    if (stype) {
      ek = farsorg(*sseg);
      printf(" ek(%d)", pointmark(ek));
    }
    printf(".\n");
  }

  // Calculate the split point.
  if (stype == 0) {
    // Use rule-1.
    L = DIST(ei, ej);
    d1 = DIST(ei, refpt);
    d2 = DIST(ej, refpt);
    if (d1 < d2) {
      // Choose ei as center.
      if (d1 < 0.5 * L) {
        split = d1 / L;
        // Adjust split if it is close to middle. (2009-02-01)
        if ((split > 0.4) || (split < 0.6)) split = 0.5;
      } else {
        split = 0.5;
      }
      for (i = 0; i < 3; i++) {
        vt[i] = ei[i] + split * (ej[i] - ei[i]);
      }
    } else {
      // Choose ej as center.
      if (d2 < 0.5 * L) {
        split = d2 / L;
        // Adjust split if it is close to middle. (2009-02-01)
        if ((split > 0.4) || (split < 0.6)) split = 0.5;
      } else {
        split = 0.5;
      }
      for (i = 0; i < 3; i++) {
        vt[i] = ej[i] + split * (ei[i] - ej[i]);
      }
    }
    r1count++;
  } else {
    // Use rule-2.
    ek = farsorg(*sseg);
    L = DIST(ek, ej);
    d = DIST(ek, refpt);
    split = d / L;
    for (i = 0; i < 3; i++) {
      vt[i] = ek[i] + split * (ej[i] - ek[i]);
    }
    d1 = DIST(vt, refpt);
    d2 = DIST(vt, ej);
    if (d1 > d2) {
      // Use rule-3.
      d3 = DIST(ei, refpt);
      if (d1 < 0.5 * d3) {
        split = (d - d1) / L;
      } else {
        split = (d - 0.5 * d3) / L;
      }
      for (i = 0; i < 3; i++) {
        vt[i] = ek[i] + split * (ej[i] - ek[i]);
      }
    }
    d1 > d2 ? r3count++ : r2count++;
  }

  if (b->verbose > 1) {
    printf("    split (%g), vt (%g, %g, %g).\n", split, vt[0], vt[1], vt[2]);
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// delaunizesegments()    Recover segments in a Delaunay tetrahedralization. //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::delaunizesegments()
{
  triface searchtet;
  face splitsh;
  face *psseg, sseg;
  point refpt, newpt;
  enum intersection dir;
  bool visflag;

  if (b->verbose) {
    printf("  Delaunizing segments.\n");
  }

  // Loop until 'subsegstack' is empty.
  while (subsegstack->objects > 0l) {
    // seglist is used as a stack.
    subsegstack->objects--;
    psseg = (face *) fastlookup(subsegstack, subsegstack->objects);
    sseg = *psseg;

    if (!sinfected(sseg)) continue; // Not a missing segment.
    suninfect(sseg);

    // Insert the segment.
    searchtet.tet = NULL;
    dir = scoutsegment(&sseg, &searchtet, &refpt);

    if (dir != SHAREVERT) {
      // The segment is missing, split it.
      spivot(sseg, splitsh);
      if (dir != ACROSSVERT) {
        // Create the new point.
        makepoint(&newpt);
        getsegmentsplitpoint(&sseg, refpt, newpt);
        setpointtype(newpt, STEINERVERTEX);
        // Split the segment by newpt.
        sinsertvertex(newpt, &splitsh, &sseg, true, false);
        // Insert newpt into the DT. If 'checksubfaces == 1' the current
        //   mesh is constrained Delaunay (but may not Delaunay).
        visflag = (checksubfaces == 1);
        insertvertex(newpt, &searchtet, true, visflag, false, false);
      } else {
        /*if (getpointtype(refpt) != ACUTEVERTEX) {
          setpointtype(refpt, RIDGEVERTEX);
        }
        // Split the segment by refpt.
        sinsertvertex(refpt, &splitsh, &sseg, true, false);*/
        printf("Error:  Invalid PLC! A point and a segment intersect.\n");
        point pa, pb;
        pa = farsorg(sseg);
        pb = farsdest(sseg);
        printf("  Point: %d. Segment: (%d, %d).\n", pointmark(refpt),
          pointmark(pa), pointmark(pb));
        terminatetetgen(1);
      }
    }
  }

  if (b->verbose) {
    printf("  %d protecting points.\n", r1count + r2count + r3count);
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// scoutsubface()    Look for a given subface in the tetrahedralization T.   //
//                                                                           //
// 'ssub' is the subface, denoted as abc. If abc exists in T, it is 'locked' //
// at the place where the two tets sharing at it.                            //
//                                                                           //
// The returned value indicates one of the following cases:                  //
//   - SHAREFACE, abc exists and is inserted;                                //
//   - TOUCHEDGE, a vertex (the origin of 'searchtet') lies on ab.           //
//   - EDGETRIINT, all three edges of abc are missing.                       //
//   - ACROSSTET, a tet (in 'searchtet') crosses the facet containg abc.     //
//                                                                           //
// If the retunred value is ACROSSTET, the subface is missing.  'searchtet'  //
// returns a tet which shares the same edge as 'pssub'.                      //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

enum tetgenmesh::intersection tetgenmesh::scoutsubface(face* pssub,
  triface* searchtet)
{
  triface spintet;
  face checksh;
  point pa, pb, pc, pd;
  enum intersection dir;
  int i;

  tetrahedron ptr;
  int tver;

  if (searchtet->tet == NULL) {
    // Search an edge of 'ssub' in tetrahedralization.
    pssub->shver = 0;
    for (i = 0; i < 3; i++) {
      pa = sorg(*pssub);
      pb = sdest(*pssub);
      // Do not search dummypoint.
      assert(pa != dummypoint); // SELF_CHECK
      assert(pb != dummypoint); // SELF_CHECK
      // Get a tet whose origin is pa.
      decode(point2tet(pa), *searchtet);
      assert(searchtet->tet != NULL); // SELF_CHECK
      assert(searchtet->tet[4] != NULL); // SELF_CHECK
      if ((point) searchtet->tet[4] == pa) {
        searchtet->loc = 0; searchtet->ver = 0;
      } else if ((point) searchtet->tet[5] == pa) {
        searchtet->loc = 0; searchtet->ver = 2;
      } else if ((point) searchtet->tet[6] == pa) {
        searchtet->loc = 0; searchtet->ver = 4;
      } else {
        if ((point) searchtet->tet[7] != pa) {
          printf("Error: Bad pt-to-tet at %d\n", pointmark(pa));
          assert(0);
        }
        searchtet->loc = 1; searchtet->ver = 2;
      }
      // Search the edge from pa->pb.
      dir = finddirection(searchtet, pb);
      if (dir == ACROSSVERT) {
        if (dest(*searchtet) == pb) {
          // Found the edge. Break the loop.
          break;
        } else {
          // A vertex lies on the search edge. Return it.
          enextself(*searchtet);
          return TOUCHEDGE;
        }
      }
      senextself(*pssub);
    }
    if (i == 3) {
      // None of the three edges exists.
      return EDGETRIINT; // ab intersects the face in 'searchtet'.
    }
  } else {
    // 'searchtet' holds the current edge of 'pssub'.
    pa = org(*searchtet);
    pb = dest(*searchtet);
  }

  pc = sapex(*pssub);

  if (b->verbose > 1) {
    printf("    Scout subface (%d, %d, %d) (%ld).\n", pointmark(pa),
      pointmark(pb), pointmark(pc), subfacstack->objects);
  }

  // Searchtet holds edge pa->pb. Search a face with apex pc.
  spintet = *searchtet;
  while (1) {
    fnextself(spintet);
    pd = apex(spintet);  // pd may be dummypoint. Search the face anyway.
    if (pd == pc) {
      // Found! Insert the subface.
      tspivot(spintet, checksh); // SELF_CHECK
      if (checksh.sh == NULL) {
        tsbond(spintet, *pssub);
        symedgeself(spintet);
        tspivot(spintet, checksh); // SELF_CHECK
        assert(checksh.sh == NULL); // SELF_CHECK
        tsbond(spintet, *pssub);
        return SHAREFACE;
      } else {
        // Another subface is laready inserted.
        assert(checksh.sh != pssub->sh); // SELF_CHECK
        // Comment: This is possible when there are faked tets.
        *searchtet = spintet;
        return COLLISIONFACE;
      }
    }
    if (pd == apex(*searchtet)) break;
  }

  return ACROSSTET;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// scoutcrosstet()    Scout a tetrahedron across a facet.                    //
//                                                                           //
// A subface (abc) of the facet (F) is given in 'pssub', 'searchtet' holds   //
// the edge ab, it is the tet starting the search.  'facpoints' contains all //
// points which are co-facet with a, b, and c.                               //
//                                                                           //
// The subface (abc) was produced by a 2D CDT algorithm under the Assumption //
// that F is flat. In real data, however, F may not be strictly flat.  Hence //
// a tet (abde) that crosses abc may be in one of the two cases: (i) abde    //
// intersects F in its interior, or (ii) abde intersects F on its boundary.  //
// In case (i) F (or part of it) is missing in DT and needs to be recovered. //
// In (ii) F is not missing, the surface mesh of F needs to be adjusted.     //
//                                                                           //
// This routine distinguishes the two cases by the returned value, which is  //
//   - ACROSSTET, if it is case (i), 'searchtet' is abde, d and e lies below //
//     and above abc, respectively, neither d nor e is dummypoint; or        //
//   - ACROSSFACE, if it is case (ii), 'searchtet' is abde, where the face   //
//     abd intersects abc, i.e., d is co-facet with abc, e may be co-facet   //
//     with abc or dummypoint.                                               //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

enum tetgenmesh::intersection tetgenmesh::scoutcrosstet(face *pssub, 
  triface* searchtet, arraypool* facpoints)
{
  triface spintet, crossface;
  point pa, pb, pc, pd, pe;
  REAL ori, ori1, len, n[3];
  REAL r, dr, drmin;
  bool cofacetflag;
  int i;

  if (facpoints != NULL) {
    // Infect all vertices of the facet.
    for (i = 0; i < facpoints->objects; i++) {
      pd = * (point *) fastlookup(facpoints, i);
      pinfect(pd);
    }
  }

  // Search an edge crossing the facet containing abc.
  if (searchtet->ver & 01) {
    esymself(*searchtet); // Adjust to 0th edge ring.
    sesymself(*pssub);
  }

  pa = sorg(*pssub);
  pb = sdest(*pssub);
  pc = sapex(*pssub);

  // Search an apex lies below the subface. Note that such apex may not
  //   exist which indicates there is a co-facet apex.
  cofacetflag = false;
  pd = apex(*searchtet);
  spintet = *searchtet;
  while (1) {
    if (pd != dummypoint) {
      ori = orient3d(pa, pb, pc, pd);
      if ((ori != 0) && pinfected(pd)) {
        ori = 0; // Force d be co-facet with abc.
      }
      if (ori > 0) {
        break; // Found a lower point.
      }
    }
    fnextself(spintet); // Go to the next face.
    pd = apex(spintet);
    if (pd == apex(*searchtet)) {
      cofacetflag = true; break; // Not found.
    }
  }
  if (!cofacetflag) {
    // Search a tet whose apex->oppo crosses the facet containig abc.
    while (1) {
      pe = oppo(spintet);
      if (pe != dummypoint) {
        ori = orient3d(pa, pb, pc, pe);
        if ((ori != 0) && pinfected(pe)) {
          ori = 0; // Force pe be co-facet with abc.
        }
        if (ori < 0) {
          break;  // stop at pd->pe.
        }
        if (ori == 0) {
          cofacetflag = true; break; // Found a co-facet point.
        }
      }    
      fnextself(spintet);
    }
    *searchtet = spintet;
    // Now if "cofacetflag != true", searchtet contains a cross tet (abde), 
    //   where d and e lie below and above abc, respectively, and 
    //   orient3d(a, b, d, e) < 0.
  }

  if (cofacetflag) {
    // There are co-facet points. Calculate a point above the subface.
    facenormal(pa, pb, pc, n, 1);
    len = sqrt(DOT(n, n));
    n[0] /= len;
    n[1] /= len;
    n[2] /= len;
    len = DIST(pa, pb);
    len += DIST(pb, pc);
    len += DIST(pc, pa);
    len /= 3.0;
    dummypoint[0] = pa[0] + len * n[0];
    dummypoint[1] = pa[1] + len * n[1];
    dummypoint[2] = pa[2] + len * n[2];
    // Search a co-facet point d, s.t. (i) [a, b, d] intersects [a, b, c],
    //   AND (ii) a, b, c, d has the closet circumradius of [a, b, c].
    // NOTE: (ii) is needed since there may be several points satisfy (i).
    circumsphere(pa, pb, pc, NULL, n, &r);
    crossface.tet = NULL;
    pe = apex(*searchtet);
    spintet = *searchtet;
    while (1) {
      pd = apex(spintet);
      if (pd != dummypoint) {
        ori = orient3d(pa, pb, pc, pd);
        if ((ori == 0) || pinfected(pd)) {
          ori1 = orient3d(pa, pb, dummypoint, pd);
          if (ori1 > 0) {
            // [a, b, d] intersects with [a, b, c].
            if (pinfected(pd)) {
              len = DIST(n, pd);
              dr = fabs(len - r);
              if (crossface.tet == NULL) {
                // This is the first cross face.
                crossface = spintet;
                drmin = dr;
              } else {
                if (dr < drmin) {
                  crossface = spintet;
                  drmin = dr;
                }
              }
            } else {
              assert(ori == 0); // SELF_CHECK
              // Found a coplanar but not co-facet point (pd).
              printf("Error:  Invalid PLC! A point and a subface intersect\n");
              // get_origin_facet_corners(pssub, &pa, &pb, &pc);
              printf("  Point %d. Subface (#%d) (%d, %d, %d)\n", 
                pointmark(pd), getshellmark(*pssub), pointmark(pa), 
                pointmark(pb), pointmark(pc));
              terminatetetgen(1);
            }
          }
        }
      }
      fnextself(spintet); // Go to the next face.
      // assert(apex(spintet) != pe); // SELF_CHECK
      if (apex(spintet) == pe) {
        break;
      }
    }
    if(crossface.tet == NULL) {
      assert(crossface.tet != NULL); // Not handled yet.
    }
    *searchtet = crossface;
    dummypoint[0] = dummypoint[1] = dummypoint[2] = 0;
  }

  if (cofacetflag) {
    if (b->verbose > 1) {
      printf("    Found a co-facet face (%d, %d, %d) op (%d).\n", 
        pointmark(pa), pointmark(pb), pointmark(apex(*searchtet)), 
        pointmark(oppo(*searchtet)));
    }
    if (facpoints != NULL) {
      // Unmark all facet vertices.
      for (i = 0; i < facpoints->objects; i++) {
        pd = * (point *) fastlookup(facpoints, i);
        puninfect(pd);
      }
    }
    // Comment: Now no vertex is infected.
    if (getpointtype(apex(*searchtet)) == VOLVERTEX) {
      // A vertex lies on the facet.
      enext2self(*searchtet); // org(*searchtet) == pd
      return TOUCHFACE;
    }
    return ACROSSFACE;
  } else {
    // Return a crossing tet.
    if (b->verbose > 1) {
      printf("    Found a crossing tet (%d, %d, %d, %d).\n", pointmark(pa),
        pointmark(pb), pointmark(apex(spintet)), pointmark(pe));
    }
    // Comment: if facpoints != NULL, co-facet vertices are stll infected.
    //   They will be uninfected in formcavity();
    return ACROSSTET; // abc intersects the volume of 'searchtet'.
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// recoversubfacebyflips()   Recover a subface by flips in the surface mesh. //
//                                                                           //
// A subface [a, b, c] ('pssub') intersects with a face [a, b, d] ('cross-   //
// face'), where a, b, c, and d belong to the same facet.  It indicates that //
// the face [a, b, d] should appear in the surface mesh.                     //
//                                                                           //
// This routine recovers [a, b, d] in the surface mesh through a sequence of //
// 2-to-2 flips. No Steiner points is needed. 'pssub' returns [a, b, d].     //
//                                                                           //
// If 'facfaces' is not NULL, all flipped subfaces are queued for recovery.  //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::recoversubfacebyflips(face* pssub, triface* crossface, 
  arraypool *facfaces)
{
  triface neightet;
  face flipfaces[2];
  face checkseg;
  point pa, pb, pc, pd, pe;
  REAL ori, len, n[3];

  tetrahedron ptr;
  shellface sptr;
  int tver;

  // Get the missing subface is [a, b, c].
  pa = sorg(*pssub);
  pb = sdest(*pssub);
  pc = sapex(*pssub);

  // The crossface is [a, b, d, e].
  // assert(org(*crossface) == pa);
  // assert(dest(*crossface) == pb);
  pd = apex(*crossface);
  pe = dummypoint; // oppo(*crossface);

  if (pe == dummypoint) {
    // Calculate a point above the faces.
    facenormal(pa, pb, pd, n, 1);
    len = sqrt(DOT(n, n));
    n[0] /= len;
    n[1] /= len;
    n[2] /= len;
    len = DIST(pa, pb);
    len += DIST(pb, pd);
    len += DIST(pd, pa);
    len /= 3.0;
    pe[0] = pa[0] + len * n[0];
    pe[1] = pa[1] + len * n[1];
    pe[2] = pa[2] + len * n[2];
  }

  // Adjust face [a, b, c], so that edge [b, c] crosses edge [a, d].
  ori = orient3d(pb, pc, pe, pd);
  assert(ori != 0); // SELF_CHECK

  if (ori > 0) {
    // Swap a and b.
    sesymself(*pssub);
    symedgeself(*crossface);
    pa = sorg(*pssub);
    pb = sdest(*pssub);
    if (pe == dummypoint) {
      pe[0] = pe[1] = pe[2] = 0;
    }
    pe = dummypoint; // oppo(*crossface);
  }

  while (1) {

    // Flip edge [b, c], edge [a, d] is missing.
    senext(*pssub, flipfaces[0]);
    sspivot(flipfaces[0], checkseg); // SELF_CHECK
    assert(checkseg.sh == NULL); // SELF_CHECK
    spivot(flipfaces[0], flipfaces[1]);

    stpivot(flipfaces[1], neightet);
    if (neightet.tet != NULL) {
      // A recovered subface, clean sub<==>tet connections.
      tsdissolve(neightet);
      symself(neightet);
      tsdissolve(neightet);
      stdissolve(flipfaces[1]);
    }

    flip22(flipfaces, 0);

    // Add them into list (make ensure that they must be recovered).
    facfaces->newindex((void **) &pssub);
    *pssub = flipfaces[0];
    facfaces->newindex((void **) &pssub);
    *pssub = flipfaces[1];

    // Find the edge [a, b].
    senext(flipfaces[1], *pssub);
    assert(sorg(*pssub) == pa); // SELF_CHECK
    assert(sdest(*pssub) == pb); // SELF_CHECK

    pc = sapex(*pssub);
    if (pc == pd) break;

    if (pe == dummypoint) {
      // Calculate a point above the faces.
      facenormal(pa, pb, pd, n, 1);
      len = sqrt(DOT(n, n));
      n[0] /= len;
      n[1] /= len;
      n[2] /= len;
      len = DIST(pa, pb);
      len += DIST(pb, pd);
      len += DIST(pd, pa);
      len /= 3.0;
      pe[0] = pa[0] + len * n[0];
      pe[1] = pa[1] + len * n[1];
      pe[2] = pa[2] + len * n[2];
    }

    while (1) {
      ori = orient3d(pb, pc, pe, pd);
      assert(ori != 0); // SELF_CHECK
      if (ori > 0) {
        senext2self(*pssub);
        spivotself(*pssub);
        if (sorg(*pssub) != pa) sesymself(*pssub);
        pb = sdest(*pssub);
        pc = sapex(*pssub);
        continue;
      }
      break;
    }
  }

  if (pe == dummypoint) {
    pe[0] = pe[1] = pe[2] = 0;
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// formcavity()    Form the cavity of a missing region.                      //
//                                                                           //
// A missing region R is a set of co-facet (co-palanr) subfaces. 'pssub' is  //
// a missing subface [a, b, c]. 'crosstets' contains only one tet, [a, b, d, //
// e], where d and e lie below and above [a, b, c], respectively.  Other     //
// crossing tets are sought from this tet and saved in 'crosstets'.          //
//                                                                           //
// The cavity C is divided into two parts by R,one at top and one at bottom. //
// 'topfaces' and 'botfaces' return the upper and lower boundary faces of C. //
// 'toppoints' contains vertices of 'crosstets' in the top part of C, and so //
// does 'botpoints'. Both 'toppoints' and 'botpoints' contain vertices of R. //
//                                                                           //
// NOTE: 'toppoints' may contain points which are not vertices of any top    //
// faces, and so may 'botpoints'. Such points may belong to other facets and //
// need to be present after the recovery of this cavity (P1029.poly).        //
//                                                                           //
// A pair of boundary faces: 'firsttopface' and 'firstbotface', are saved.   //
// They share the same edge in the boundary of the missing region.           //
//                                                                           //
// 'facpoints' contains all vertices of the facet containing R.  They are    //
// used for searching the crossing tets. On input all vertices are infected. //
// They are uninfected after the cavity is formed.                           //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::formcavity(face *pssub, arraypool* crosstets, 
  arraypool* topfaces, arraypool* botfaces, arraypool* toppoints,
  arraypool* botpoints, arraypool* facpoints)
{
  arraypool *crossedges;
  triface *parytet, crosstet, spintet, neightet, faketet;
  face neighsh, checksh;
  face checkseg;
  point pa, pb, pc, pf, pg;
  point *ppt;
  REAL ori;
  int i, j;

  int *iptr;

  // Get the missing subface abc.
  pa = sorg(*pssub);
  pb = sdest(*pssub);
  pc = sapex(*pssub);

  // Comment: Now all facet vertices are infected.

  // Get a crossing tet abde.
  parytet = (triface *) fastlookup(crosstets, 0); // face abd.
  // The edge de crosses the facet. d lies below abc.
  enext2fnext(*parytet, crosstet);
  enext2self(crosstet); 
  esymself(crosstet); // the edge d->e at face [d,e,a]
  infect(crosstet);
  *parytet = crosstet; // Save it in list.

  // Temporarily re-use 'topfaces'.
  crossedges = topfaces;
  crossedges->newindex((void **) &parytet);
  *parytet = crosstet;

  // Collect all crossing tets.  Each cross tet is saved in the standard
  //   form deab, where de is a corrsing edge, orient3d(d,e,a,b) < 0. 
  // NOTE: hull tets may be collected. See fig/dump-cavity-case2a(b).lua.
  //   Make sure that neither d nor e is dummypoint.
  for (i = 0; i < crossedges->objects; i++) {
    crosstet = * (triface *) fastlookup(crossedges, i);
    // It may already be tested.
    if (!edgemarked(crosstet)) {
      // Collect all tets sharing at the edge.
      pg = apex(crosstet);
      spintet = crosstet;
      while (1) {
        // Mark this edge as tested.
        markedge(spintet);
        if (!infected(spintet)) {
          infect(spintet);
          crosstets->newindex((void **) &parytet);
          *parytet = spintet;
        }
        // Go to the neighbor tet.
        fnextself(spintet);
        // Check the validity of the PLC.
        tspivot(spintet, checksh);
        if (checksh.sh != NULL) {
          printf("Error:  Invalid PLC! Two subfaces intersect.\n");
          printf("  1st (#%4d): (%d, %d, %d)\n", getshellmark(*pssub),
            pointmark(pa), pointmark(pb), pointmark(pc));
          printf("  2nd (#%4d): (%d, %d, %d)\n", getshellmark(checksh),
            pointmark(sorg(checksh)), pointmark(sdest(checksh)),
            pointmark(sapex(checksh)));
          terminatetetgen(1);
        }
        if (apex(spintet) == pg) break;
      }
      // Detect new cross edges.
      while (1) {
        // Remember: spintet is edge d->e, d lies below abc.
        pf = apex(spintet);
        if (pf != dummypoint) { // Do not grab a hull edge.
          if (!pinfected(pf)) {
            // There exist a crossing edge, either d->f, or f->e.
            ori = orient3d(pa, pb, pc, pf);
            if (ori == 0) {
              printf("Error:  Invalid PLC! Point and subface intersect.\n");
              printf("   Point %d, subface (#%4d): (%d, %d, %d)\n", 
                pointmark(pf), getshellmark(*pssub), pointmark(pa), 
                pointmark(pb), pointmark(pc));
              terminatetetgen(1);
            }
            if (ori < 0) {
              // The edge d->f corsses the facet.
              enext2fnext(spintet, neightet);
              esymself(neightet); // d->f.
            } else {
              // The edge f->e crosses the face.
              enextfnext(spintet, neightet);
              esymself(neightet); // f->e.
            }
            if (!edgemarked(neightet)) {
              // Add a new cross edge.
              crossedges->newindex((void **) &parytet);
              *parytet = neightet;
            }
          }
        }
        fnextself(spintet);
        if (apex(spintet) == pg) break;
      }
    }
  }

  // Unmark all facet vertices.
  for (i = 0; i < facpoints->objects; i++) {
    ppt = (point *) fastlookup(facpoints, i);
    puninfect(*ppt);
  }

  // Comments: Now no vertex is marked. Next we will mark vertices which 
  //   belong to the top and bottom boundary faces of the cavity and put
  //   them in 'toppopints' and 'botpoints', respectively.

  // All cross tets are found. Unmark cross edges.
  for (i = 0; i < crossedges->objects; i++) {
    crosstet = * (triface *) fastlookup(crossedges, i);
    if (edgemarked(crosstet)) {
      // Add the vertices of the cross edge [d, e] in lists. It must be
      //   that d lies below the facet (i.e., its a bottom vertex).
      //   Note that a cross edge contains no dummypoint.
      pf = org(crosstet);
      assert(pf != dummypoint); // SELF_CHECK
      if (!pinfected(pf)) {
        pinfect(pf);
        botpoints->newindex((void **) &ppt); // Add a bottom vertex.
        *ppt = pf;
      }
      pf = dest(crosstet);
      assert(pf != dummypoint); // SELF_CHECK
      if (!pinfected(pf)) {
        pinfect(pf);
        toppoints->newindex((void **) &ppt); // Add a top vertex.
        *ppt = pf;
      }
      // Unmark this edge in all tets containing it.
      pg = apex(crosstet);
      spintet = crosstet;
      while (1) {
        assert(edgemarked(spintet)); // SELF_CHECK
        unmarkedge(spintet);
        fnextself(spintet); // Go to the neighbor tet.
        if (apex(spintet) == pg) break;
      }
    }
  }

  if (b->verbose > 1) {
    printf("    Formed cavity: %ld (%ld) cross tets (edges).\n", 
      crosstets->objects, crossedges->objects);
  }
  crossedges->restart();

  // Find a pair of cavity boundary faces from the top and bottom sides of
  //   the facet each, and they share the same edge. Save them in the
  //   global variables: firsttopface, firstbotface. They will be used in
  //   fillcavity() for gluing top and bottom new tets.
  for (i = 0; i < crosstets->objects; i++) {
    crosstet = * (triface *) fastlookup(crosstets, i);
    enextfnext(crosstet, spintet);
    enextself(spintet);
    symedge(spintet, neightet);
    if (!infected(neightet)) {
      // A top face.
      firsttopface = neightet;
    } else {
      continue; // Go to the next cross tet.
    }
    enext2fnext(crosstet, spintet);
    enext2self(spintet);
    symedge(spintet, neightet);
    if (!infected(neightet)) {
      // A bottom face.
      firstbotface = neightet;
    } else {
      continue;
    }
    break;
  }
  assert(i < crosstets->objects); // SELF_CHECK
  
  // Collect the top and bottom faces and the middle vertices. Since all top
  //   and bottom vertices have been marked in above. Unmarked vertices are
  //   middle vertices.
  // NOTE 1: Hull tets may be collected. Process them as normal one.
  //   (see fig/dump-cavity-case2.lua.)
  // NOTE 2: Some previously recovered subfaces may be completely
  //   contained in a cavity (see fig/dump-cavity-case6.lua). In such case,
  //   we create two faked tets to hold this subface, one at each side.
  //   The faked tets will be removed in fillcavity().
  for (i = 0; i < crosstets->objects; i++) {
    crosstet = * (triface *) fastlookup(crosstets, i);
    enextfnext(crosstet, spintet);
    enextself(spintet);
    symedge(spintet, neightet);
    if (!infected(neightet)) {
      // A top face.
      topfaces->newindex((void **) &parytet);
      *parytet = neightet;
    } else {
      // Check if this side is a subface.
      tspivot(spintet, neighsh);
      if (neighsh.sh != NULL) {
        // Found a subface (inside the cavity)!
        maketetrahedron(&faketet);  // Create a faked tet.
        setorg(faketet, org(spintet));
        setdest(faketet, dest(spintet));
        setapex(faketet, apex(spintet));
        setoppo(faketet, NULL);
        tsbond(faketet, neighsh); // Let it hold the subface.
        // Add a top face (at faked tet).
        topfaces->newindex((void **) &parytet);
        *parytet = faketet;
      }
    }
    enext2fnext(crosstet, spintet);
    enext2self(spintet);
    symedge(spintet, neightet);
    if (!infected(neightet)) {
      // A bottom face.
      botfaces->newindex((void **) &parytet);
      *parytet = neightet;
    } else {
      tspivot(spintet, neighsh);
      if (neighsh.sh != NULL) {
        // Found a subface (inside the cavity)!
        maketetrahedron(&faketet);  // Create a faked tet.
        setorg(faketet, org(spintet));
        setdest(faketet, dest(spintet));
        setapex(faketet, apex(spintet));
        setoppo(faketet, NULL);
        tsbond(faketet, neighsh); // Let it hold the subface.
        // Add a bottom face (at faked tet).
        botfaces->newindex((void **) &parytet);
        *parytet = faketet;
      }
    }
    // Add middle vertices if there are (skip dummypoint).
    pf = org(neightet);
    if (!pinfected(pf)) {
      if (pf != dummypoint) {
        pinfect(pf);
        botpoints->newindex((void **) &ppt); // Add a bottom vertex.
        *ppt = pf;
        toppoints->newindex((void **) &ppt); // Add a top vertex.
        *ppt = pf;
      }
    }
    pf = dest(neightet);
    if (!pinfected(pf)) {
      if (pf != dummypoint) {
        pinfect(pf);
        botpoints->newindex((void **) &ppt); // Add a bottom vertex.
        *ppt = pf;
        toppoints->newindex((void **) &ppt); // Add a top vertex.
        *ppt = pf;
      }
    }
  }

  // Unmark all collected top, bottom, and middle vertices.
  for (i = 0; i < toppoints->objects; i++) {
    ppt = (point *) fastlookup(toppoints, i);
    puninfect(*ppt);
  }
  for (i = 0; i < botpoints->objects; i++) {
    ppt = (point *) fastlookup(botpoints, i);
    puninfect(*ppt);
  }
  // Comments: Now no vertex is marked.
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// delaunizecavity()    Fill a cavity by Delaunay tetrahedra.                //
//                                                                           //
// The tetrahedralizing cavity is the half (top or bottom part) of the whole //
// cavity.  The boundary faces of the half cavity are given in 'cavfaces',   //
// the bounday faces of the internal facet are not given.  These faces will  //
// be recovered later in fillcavity().                                       //
//                                                                           //
// This routine first constructs the DT of the vertices by the Bowyer-Watson //
// algorithm.  Then it identifies the boundary faces of the cavity in DT.    //
// The DT is returned in 'newtets'.                                          //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

bool tetgenmesh::delaunizecavity(arraypool *cavpoints, arraypool *cavfaces, 
  arraypool *cavshells, arraypool *newtets, arraypool *crosstets,
  arraypool *misfaces)
{
  triface *parytet, searchtet, neightet, spintet, *parytet1;
  face checksh, tmpsh, *parysh;
  point pa, pb, pc, pd, pt[3], *parypt;
  // badface *newflipface;
  enum intersection dir;
  REAL ori;
  // int miscount;
  int i, j;

  tetrahedron ptr;
  int *iptr, tver;

  if (b->verbose > 1) {
    printf("    Delaunizing cavity: %ld points, %ld faces.\n", 
      cavpoints->objects, cavfaces->objects);
  }

  // Get four non-coplanar points (no dummypoint).
  parytet = (triface *) fastlookup(cavfaces, 0);
  pa = org(*parytet);
  pb = dest(*parytet);
  pc = apex(*parytet);
  pinfect(pa);
  pinfect(pb);
  pinfect(pc);
  pd = NULL;
  for (i = 1; i < cavfaces->objects; i++) {
    parytet = (triface *) fastlookup(cavfaces, i);
    pt[0] = org(*parytet);
    pt[1] = dest(*parytet);
    pt[2] = apex(*parytet);
    for (j = 0; j < 3; j++) {
      if (pt[j] != dummypoint) { // Do not include a hull point.
        if (!pinfected(pt[j])) {
          ori = orient3d(pa, pb, pc, pt[j]);
          if (ori != 0) {
            pd = pt[j];
            if (ori > 0) {  // Swap pa and pb.
              pt[j] = pa; pa = pb; pb = pt[j]; 
            }
            break;
          }
        }
      }
    }
    if (pd != NULL) break;
  }
  assert(i < cavfaces->objects); // SELF_CHECK
  pinfect(pd);

  // Create an init DT.
  initialDT(pa, pb, pc, pd);

  for (i = 0; i < cavpoints->objects; i++) {
    pt[0] = * (point *) fastlookup(cavpoints, i);
    assert(pt[0] != dummypoint); // SELF_CHECK
    if (!pinfected(pt[0])) {
      pinfect(pt[0]); // Mark it as inserted.
      searchtet = recenttet;
      insertvertex(pt[0], &searchtet, true, false, false, false);
    } else {
      // puninfect(pt[0]); // It is already inserted.
    }
  }
  // Comment: All vertices of the cavity are marked.

  while (1) {

  // Indentify boundary faces. Mark interior tets. Save missing faces.
  for (i = 0; i < cavfaces->objects; i++) {
    parytet = (triface *) fastlookup(cavfaces, i);
    // Skip an interior face (due to the enlargement of the cavity).
    if (infected(*parytet)) continue;
    // This face may contain dummypoint (See fig/dum-cavity-case2).
    //   If so, dummypoint must be its apex.
    parytet->ver = 4; 
    pt[0] = org(*parytet);
    pt[1] = dest(*parytet);
    pt[2] = apex(*parytet);
    // Create a temp subface.
    makeshellface(subfacepool, &tmpsh);
    setshvertices(tmpsh, pt[0], pt[1], pt[2]);
    // Insert tmpsh in DT.
    searchtet.tet = NULL; 
    dir = scoutsubface(&tmpsh, &searchtet);
    if (dir == SHAREFACE) {
      // Identify the inter and outer tets at tempsh.
      stpivot(tmpsh, neightet);
      // neightet and tmpsh refer to the same edge [pt[0], pt[1]].
      //   Moreover, neightet is in 0th edge ring (see decode()).
      if (org(neightet) != pt[1]) {
        symedgeself(neightet);
        assert(org(neightet) == pt[1]); // SELF_CHECK
        // Make sure that tmpsh is connected with an interior tet. 
        tsbond(neightet, tmpsh);
      }
      assert(dest(neightet) == pt[0]); // SELF_CHECK
      // Mark neightet as interior.
      if (!infected(neightet)) {
        infect(neightet);
      }
    } else if (dir == COLLISIONFACE) {
      // A subface is already inserted (see fig/dum-cavity-case6).
      assert(oppo(*parytet) == NULL); // It must be a faked tet.
      // Searchtet's face collides it. Adjust to 0th edge ring.
      if ((searchtet.ver & 01) != 0) esymself(searchtet);
      // Let the subface remember its adjacent tet at its inside.
      if (org(searchtet) != pt[1]) {
        symedgeself(searchtet);
        assert(org(searchtet) == pt[1]); // SELF_CHECK
      }
      assert(dest(searchtet) == pt[0]); // SELF_CHECK
      tmpsh.sh[9] = (shellface) encode(searchtet);
    } else {
      if (b->verbose > 1) {
        printf("  p:draw_subface(%d, %d, %d) -- %d is missing\n",
          pointmark(pt[0]), pointmark(pt[1]), pointmark(pt[2]), i);
      }
      shellfacedealloc(subfacepool, tmpsh.sh);
      // Save this face in list.
      misfaces->newindex((void **) &parytet1);
      *parytet1 = *parytet;
      /*if (dir == EDGETRIINT) {
        assert(0); // Face unmatched. Not process yet.
      }
      // Search an edge crossing this face.
      dir = scoutcrosstet(&tmpsh, &searchtet, NULL);
      assert(dir == ACROSSTET); // SELF_CHECK
      // Save this pair of points.
      newflipface = (badface *) flippool->alloc();
      newflipface->forg = apex(searchtet);
      newflipface->fdest = oppo(searchtet);
      newflipface->nextitem = futureflip;
      futureflip = newflipface;
      // if (b->verbose > 1) {        
        printf("  p:draw_subseg(%d, %d)\n", pointmark(newflipface->forg),
          pointmark(newflipface->fdest));
      // }
      miscount++;*/
      continue;
    }
    // Remember tmpsh (use the adjacent tet slot). 
    // parytet->tet[parytet->loc] = (tetrahedron) sencode(tmpsh);
    tmpsh.sh[0] = (shellface) encode(*parytet);
    // Save this subface.
    cavshells->newindex((void **) &parysh);
    *parysh = tmpsh;
  }

  if (misfaces->objects > 0) {
    // Removing tempoaray subfaces.
    for (i = 0; i < cavshells->objects; i++) {
      parysh = (face *) fastlookup(cavshells, i);
      stpivot(*parysh, neightet);
      uninfect(neightet);
      tsdissolve(neightet); // Detach it from adj. tets.
      symself(neightet);
      tsdissolve(neightet);
      shellfacedealloc(subfacepool, parysh->sh);
    }
    cavshells->restart();
    // Enlarge the cavity.
    for (i = 0; i < misfaces->objects; i++) {
      // Get a missing face.
      parytet = (triface *) fastlookup(misfaces, i);
      // Check for a missing subface.
      tspivot(*parytet, checksh);
      if (checksh.sh != NULL) {
        if (b->verbose > 1) {
          printf("    Queue a subface x%lx (%d, %d, %d).\n", 
            (unsigned long) checksh.sh, pointmark(sorg(checksh)),
            pointmark(sdest(checksh)), pointmark(sapex(checksh)));
        }
        stdissolve(checksh);
        subfacstack->newindex((void **) &parysh);
        *parysh = checksh;
      }
      if (!infected(*parytet)) {
        // Put it into crossing tet list.
        infect(*parytet);
        crosstets->newindex((void **) &parytet1);
        *parytet1 = *parytet;
        // Insert the opposite point if it is not in DT.
        pd = oppo(*parytet);
        if (!pinfected(pd)) {
          if (b->verbose > 1) {
            printf("    Insert the opposite point %d.\n", pointmark(pd));
          }
          pinfect(pd);
          cavpoints->newindex((void **) &parypt);
          *parypt = pd;
          searchtet = recenttet;
          insertvertex(pd, &searchtet, true, false, false, false);
        }
        // Add three opposite faces into the boundary list.
        for (j = 0; j < 3; j++) {
          enext0fnext(*parytet, neightet);
          symself(neightet);
          if (!infected(neightet)) {
            if (b->verbose > 1) {
              printf("    Add a cavface (%d, %d, %d).\n",
                pointmark(org(neightet)), pointmark(dest(neightet)),
                pointmark(apex(neightet)));
            }
            cavfaces->newindex((void **) &parytet1);
            *parytet1 = neightet;
          } else {
            // Check if a subface is missing again.
            tspivot(neightet, checksh);
            if (checksh.sh != NULL) {
              if (b->verbose > 1) {
                printf("    Queue a subface x%lx (%d, %d, %d).\n", 
                  (unsigned long) checksh.sh, pointmark(sorg(checksh)),
                  pointmark(sdest(checksh)), pointmark(sapex(checksh)));
              }
              stdissolve(checksh);
              subfacstack->newindex((void **) &parysh);
              *parysh = checksh;
            }
          }
          enextself(*parytet);
        } // j
      } // if (!infected(parytet))
    }
    misfaces->restart();
    cavityexpcount++;
    continue;
  }

  break;

  } // while (1)

  // Collect all tets of the DT. All new tets are marktested.
  marktest(recenttet);
  newtets->newindex((void **) &parytet);
  *parytet = recenttet;
  for (i = 0; i < newtets->objects; i++) {
    searchtet = * (triface *) fastlookup(newtets, i);
    for (searchtet.loc = 0; searchtet.loc < 4; searchtet.loc++) {
      sym(searchtet, neightet);
      if (!marktested(neightet)) {
        marktest(neightet);
        newtets->newindex((void **) &parytet);
        *parytet = neightet;
      }
    }
  }

  // Uninfect all points of the DT.
  for (i = 0; i < cavpoints->objects; i++) {
    parypt = (point *) fastlookup(cavpoints, i);
    puninfect(*parypt);
  }
  cavpoints->restart();
  // Comment: Now no vertex is marked.
  cavfaces->restart();

  if (cavshells->objects > maxcavsize) {
    maxcavsize = cavshells->objects;
  }

  return true;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// fillcavity()    Fill new tets into the cavity.                            //
//                                                                           //
// The new tets are stored in two disjoint sets(which share the same facet). //
// 'topfaces' and 'botfaces' are the boundaries of these two sets, respect-  //
// ively. 'midfaces' is empty on input, and will store faces in the facet.   //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

bool tetgenmesh::fillcavity(arraypool* topshells, arraypool* botshells,
  arraypool* midfaces, arraypool* facpoints)
{
  arraypool *cavshells;
  triface *parytet, bdrytet, toptet, bottet, neightet, midface;
  face checksh, *parysh;
  face checkseg;
  point pa, pb, pc, pf, pg;
  REAL ori, len, n[3];
  bool mflag, bflag;
  int i, j, k;

  tetrahedron ptr;
  int *iptr, tver;

  // Connect newtets to tets outside the cavity.
  for (k = 0; k < 2; k++) {
    cavshells = (k == 0 ? topshells : botshells);
    for (i = 0; i < cavshells->objects; i++) {
      // Get a temp subface.
      parysh = (face *) fastlookup(cavshells, i);
      // Get the boundary tet outsode the cavity.
      decode(parysh->sh[0], bdrytet);
      pa = org(bdrytet);
      pb = dest(bdrytet);
      pc = apex(bdrytet);
      // Get the adjacent new tet.
      stpivot(*parysh, neightet);
      assert(org(neightet) == pb); // SELF_CHECK
      assert(dest(neightet) == pa); // SELF_CHECK
      if (oppo(bdrytet) != NULL) {
        // Bond the two tets.
        bond(bdrytet, neightet); // Also cleared the pointer to tmpsh.
      }
      // Bond a subface (if it exists).
      tspivot(bdrytet, checksh);
      if (checksh.sh != NULL) {
        tsbond(neightet, checksh); // Also cleared the pointer to tmpsh.
      } else {
        tsdissolve(neightet); // No subface, clear the pointer to tmpsh.
      }
      // Update the point-to-tets map.
      point2tet(pa) = encode(neightet);
      point2tet(pb) = encode(neightet);
      point2tet(pc) = encode(neightet);
      // Delete the temp subface.
      // shellfacedealloc(subfacepool, parysh->sh);
      if (oppo(bdrytet) == NULL) {
        // Delete a faked tet.
        tetrahedrondealloc(bdrytet.tet);
      }
    }
  }

  // Mark all facet vertices for finding middle subfaces.
  for (i = 0; i < facpoints->objects; i++) {
    pf = * (point *) fastlookup(facpoints, i);
    pinfect(pf);
  }

  mflag = true;  // Initialize it.

  // The first pair of top and bottom tets share the same edge [a, b].
  // toptet = * (triface *) fastlookup(topfaces, 0);
  if (infected(firsttopface)) {
    // The cavity was enlarged. This tet is included in the interior
    //   (as those of a crossing tet). Find the updated top boundary face
    //   by rotating the faces around this edge (until an uninfect tet).
    pa = apex(firsttopface);
    while (1) {
      fnextself(firsttopface);
      if (!infected(firsttopface)) break;
      assert(apex(firsttopface) != pa); // SELF_CHECK
    }
  }
  toptet = firsttopface;
  symedgeself(toptet);
  // Search a subface from the top mesh.
  while (1) {
    enext0fnextself(toptet); // The next face in the same tet.
    pc = apex(toptet);
    if (pinfected(pc)) break; // [a,b,c] is a subface.
    symedgeself(toptet); // Go to the same face in the adjacent tet.
  }
  // Search the subface [a,b,c] in the bottom mesh.
  // bottet = * (triface *) fastlookup(botfaces, 0);
  if (infected(firstbotface)) {
    pa = apex(firstbotface);
    while (1) {
      fnextself(firstbotface);
      if (!infected(firstbotface)) break;
      assert(apex(firstbotface) != pa); // SELF_CHECK
    }
  }
  bottet = firstbotface;
  symedgeself(bottet);
  while (1) {
    enext0fnextself(bottet); // The next face in the same tet.
    pf = apex(bottet);
    if (pf == pc) break; // Face matched.
    if (pinfected(pf)) {
      mflag = false; break; // Not matched.
    }
    symedgeself(bottet);
  }
  if (mflag) {
    // Connect the two tets together.
    bond(toptet, bottet);
    // Both are interior tets.
    infect(toptet);
    infect(bottet);
    // Add this face into search list.
    esymself(toptet); // Choose the 0th edge ring.
    markface(toptet);
    midfaces->newindex((void **) &parytet);
    *parytet = toptet;
  }

  // Match pairs of subfaces (middle faces), connect top and bottom tets.
  for (i = 0; i < midfaces->objects && mflag; i++) {
    // Get a matched middle face [a, b, c]
    midface = * (triface *) fastlookup(midfaces, i);
    // It is inside the cavity.
    assert(marktested(midface)); // SELF_CHECK 
    // Check the neighbors at edges [b, c] and [c, a].
    for (j = 0; j < 2 && mflag; j++) {
      enextself(midface); // [b, c] or [c, a].
      pg = apex(midface);
      toptet = midface;
      bflag = false;
      while (1) {
        // Go to the next face in the same tet.
        enext0fnextself(toptet);
        pc = apex(toptet);
        if (pinfected(pc)) {
          break; // Find a subface.
        }
        if (pc == dummypoint) {
          break; // Find a subface.
        }
        /* if (pc == pg) {
          // The adjacent face is not a middle face.
          bflag = true; break; 
        }*/
        // Go to the same face in the adjacent tet.
        symedgeself(toptet);
        // Do we walk outside the cavity? 
        if (!marktested(toptet)) {
          // Yes, the adjacent face is not a middle face.
          bflag = true; break; 
        }
      }
      if (!bflag) {
        // assert(marktested(toptet)); // SELF_CHECK
        if (!facemarked(toptet)) {
          symedge(midface, bottet);
          while (1) {
            enext0fnextself(bottet);
            pf = apex(bottet);
            if (pf == pc) break; // Face matched.
            if (pinfected(pf)) {
              mflag = false; break; // Not matched
            }
            symedgeself(bottet);
          }
          if (mflag) {
            if (marktested(bottet)) {
              // Connect two tets together.
              bond(toptet, bottet);
              // Both are interior tets.
              infect(toptet);
              infect(bottet);
              // Add this face into list.
              esymself(toptet);
              markface(toptet);
              midfaces->newindex((void **) &parytet);
              *parytet = toptet;
            } else {
              // The 'bottet' is not inside the cavity! 
              // This case can happen when the cavity was enlarged, and the
              //   'toptet' is a co-facet (sub)face adjacent to the missing
              //   region, and it is a boundary face of the top cavity.
              // So the toptet and bottet should be bonded already through
              //   a temp subface. See fig/dump-cavity-case18. Check it.
              symedge(toptet, neightet);
              assert(neightet.tet == bottet.tet); // SELF_CHECK
              assert(neightet.loc == bottet.loc); // SELF_CHECK
              // Do not add this face into 'midfaces'.
            }
          }
        }
      }
    } // j
  } // i


  if (mflag) {
    if (b->verbose > 1) {
      printf("    Found %ld middle subfaces.\n", midfaces->objects);
    }
    if (midfaces->objects > maxregionsize) {
      maxregionsize = midfaces->objects;
    }
    // Unmark middle faces.
    for (i = 0; i < midfaces->objects; i++) {
      // Get a matched middle face [a, b, c]
      midface = * (triface *) fastlookup(midfaces, i);
      assert(facemarked(midface)); // SELF_CHECK
      unmarkface(midface);
    }
    // Bond subsegments to new tets. 
    // Comment: *** The following code does redundant job. Should be
    //   re-placed in the future.
    for (k = 0; k < 2; k++) {
      cavshells = (k == 0 ? topshells : botshells);
      for (i = 0; i < cavshells->objects; i++) {
        parysh = (face *) fastlookup(cavshells, i);
        decode(parysh->sh[0], bdrytet);
        if (bdrytet.tet[4] != NULL) {
          // Not a faked tet. Bond a subsegment (if it exists).
          for (j = 0; j < 3; j++) {
            tsspivot(bdrytet, checkseg);
            if (checkseg.sh != NULL) {
              symedge(bdrytet, neightet);
              assert(marktested(neightet)); // SELF_CHECK
              while (1) {
                tssbond1(neightet, checkseg);
                fnextself(neightet);
                if (!marktested(neightet)) break;
              }
            }
            enextself(bdrytet);
          }
        } else {
          // A faked tet. There is an interior subface. Use it.
          // See fig/dump-cavity-case19.
          stpivot(*parysh, neightet);
          assert(marktested(neightet)); // SELF_CHECK
          tspivot(neightet, checksh);
          assert(checksh.sh != NULL); // SELF_CHECK
          assert(checksh.sh != parysh->sh); // // SELF_CHECK
          // Align them at the same directed edge.
          pa = org(neightet);
          pb = dest(neightet);
          for (j = 0; j < 3; j++) {
            if (sorg(checksh) == pa) break;
            senextself(checksh);
          }
          assert(j < 3); // SELF_CHECK
          if (sdest(checksh) != pb) {
            senext2self(checksh);
            sesymself(checksh);
          }
          assert(sdest(checksh) == pb); // SELF_CHECK
          // Bond a subsegment (if it exists).
          for (j = 0; j < 3; j++) {
            sspivot(checksh, checkseg);
            if (checkseg.sh != NULL) {
              toptet = neightet;
              while (1) {
                tssbond1(toptet, checkseg);
                fnextself(toptet);
                if (apex(toptet) == apex(neightet)) break;
              }
            }
            senextself(checksh);
            enextself(neightet);
          }
        }
      }
    }
  } else {
    // Faces at top and bottom are not matched. There exists non-Delaunay
    //   subedges. See fig/dump-cavity-case5.lua. 
    pa = org(toptet);
    pb = dest(toptet);
    pc = apex(toptet);
    pf = apex(bottet);
    if (b->verbose > 1) {
      printf("  p:draw_tet(%d, %d, %d, %d) -- top tet.\n", pointmark(pa), 
        pointmark(pb), pointmark(pc), pointmark(oppo(toptet)));
      printf("  p:draw_tet(%d, %d, %d, %d) -- bot tet.\n", 
        pointmark(org(bottet)), pointmark(dest(bottet)), 
        pointmark(apex(bottet)), pointmark(oppo(bottet)));
    }
    // Calculate a point above the faces.
    facenormal(pa, pb, pc, n, 1);
    len = sqrt(DOT(n, n));
    n[0] /= len;
    n[1] /= len;
    n[2] /= len;
    len = DIST(pa, pb);
    len += DIST(pb, pc);
    len += DIST(pc, pa);
    len /= 3.0;
    dummypoint[0] = pa[0] + len * n[0];
    dummypoint[1] = pa[1] + len * n[1];
    dummypoint[2] = pa[2] + len * n[2];
    // Find the crossing edges.
    ori = orient3d(pb, pc, dummypoint, pf);
    assert(ori != 0); // SELF_CHECK
    if (ori < 0) {
      // The top edge [b, c] intersects the bot edge [a, f].
      enextself(toptet); 
      enextself(bottet);
    } else {
      // The top edge [c, a] intersects the bot edge [f, b].
      enext2self(toptet); 
      enext2self(bottet); 
    }
    // Split one of the edges, choose the one has longer length.
    n[0] = DIST(org(toptet), dest(toptet));
    n[1] = DIST(org(bottet), dest(bottet));
    if (n[0] > n[1]) {
      pf = org(toptet);
      pg = dest(toptet);
    } else {
      pf = org(bottet);
      pg = dest(bottet);
    }
    if (b->verbose > 1) {
      printf("  Found a non-Delaunay edge (%d, %d)\n", pointmark(pf), 
        pointmark(pg));
    }
    // Create the midpoint of the non-Delaunay edge.
    for (i = 0; i < 3; i++) {
      dummypoint[i] = 0.5 * (pf[i] + pg[i]);
    }
    // Set a tet for searching the new point.
    recenttet = firsttopface;
    // dummypoint[0] = dummypoint[1] = dummypoint[2] = 0;
    ndelaunayedgecount++;
  }
  // Unmark all facet vertices.
  for (i = 0; i < facpoints->objects; i++) {
    pf = * (point *) fastlookup(facpoints, i);
    puninfect(pf);
  }
  // Delete the temp subfaces.
  for (k = 0; k < 2; k++) {
    cavshells = (k == 0 ? topshells : botshells);
    for (i = 0; i < cavshells->objects; i++) {
      parysh = (face *) fastlookup(cavshells, i);
      shellfacedealloc(subfacepool, parysh->sh);
    }
  }
  topshells->restart();
  botshells->restart();
  midfaces->restart();
  // Comment: Now no vertex is marked.

  return mflag;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// carvecavity()    Delete old tets and outer new tets of the cavity.        //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::carvecavity(arraypool *crosstets, arraypool *topnewtets,
  arraypool *botnewtets)
{
  arraypool *newtets;
  triface *parytet, *pnewtet, neightet;
  face checkseg, *parysh;
  int i, j, k;

  // NOTE: Some subsegments may contained inside the cavity. They must be
  //   queued for recovery. See fig/dump-cavity-case20.
  for (i = 0; i < crosstets->objects; i++) {
    parytet = (triface *) fastlookup(crosstets, i);
    assert(infected(*parytet)); // SELF_CHECK
    if (parytet->tet[8] != NULL) {
      for (j = 0; j < 6; j++) {
        parytet->loc = edge2locver[j][0];
        parytet->ver = edge2locver[j][1];
        tsspivot(*parytet, checkseg);
        if (checkseg.sh != NULL) {
          if (!sinfected(checkseg)) {
            // It is not queued yet.
            neightet = *parytet;
            while (1) {
              fnextself(neightet);
              if (!infected(neightet)) break;
              if (apex(neightet) == apex(*parytet)) break;
            }
            if (infected(neightet)) {
              if (b->verbose > 1) {
                printf("    Queue a missing segment (%d, %d).\n",
                  pointmark(sorg(checkseg)), pointmark(sdest(checkseg)));
              }
              sinfect(checkseg);
              subsegstack->newindex((void **) &parysh);
              *parysh = checkseg;
            }
          }
        }
      }
    }
  }

  // Delete the old tets in cavity.
  for (i = 0; i < crosstets->objects; i++) {
    parytet = (triface *) fastlookup(crosstets, i);
    tetrahedrondealloc(parytet->tet);
  }
  crosstets->restart(); // crosstets will be re-used.

  // Collect infected new tets in cavity.
  for (k = 0; k < 2; k++) {
    newtets = (k == 0 ? topnewtets : botnewtets);
    for (i = 0; i < newtets->objects; i++) {
      parytet = (triface *) fastlookup(newtets, i);
      if (infected(*parytet)) {
        crosstets->newindex((void **) &pnewtet);
        *pnewtet = *parytet;
      }
    }
  }
  // Collect all new tets in cavity.
  for (i = 0; i < crosstets->objects; i++) {
    parytet = (triface *) fastlookup(crosstets, i);
    for (j = 0; j < 4; j++) {
      decode(parytet->tet[j], neightet);
      if (marktested(neightet)) { // Is it a new tet?
        if (!infected(neightet)) {
          // Find an interior tet.
          assert((point) neightet.tet[7] != dummypoint); // SELF_CHECK
          infect(neightet);
          crosstets->newindex((void **) &pnewtet);
          *pnewtet = neightet;
        }
      }
    }
  }

  // Delete outer new tets.
  for (k = 0; k < 2; k++) {
    newtets = (k == 0 ? topnewtets : botnewtets);
    for (i = 0; i < newtets->objects; i++) {
      parytet = (triface *) fastlookup(newtets, i);
      if (infected(*parytet)) {
        // This is an interior tet.
        uninfect(*parytet);
        unmarktest(*parytet);
      } else {
        // An outer tet. Delete it.
        tetrahedrondealloc(parytet->tet);
      }
    }
  }

  crosstets->restart();
  topnewtets->restart();
  botnewtets->restart();
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// restorecavity()    Reconnect old tets and delete new tets of the cavity.  //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::restorecavity(arraypool *crosstets, arraypool *topnewtets,
  arraypool *botnewtets)
{
  triface *parytet, neightet;
  face checksh;
  point *ppt;
  int i, j;

  // Reconnect crossing tets to cavity boundary.
  for (i = 0; i < crosstets->objects; i++) {
    parytet = (triface *) fastlookup(crosstets, i);
    assert(infected(*parytet)); // SELF_CHECK
    parytet->ver = 0;
    for (parytet->loc = 0; parytet->loc < 4; parytet->loc++) {
      symedge(*parytet, neightet);
      if (!infected(neightet)) {
        bond(*parytet, neightet);
        tspivot(*parytet, checksh);
        if (checksh.sh != NULL) {
          tsbond(*parytet, checksh);
        }
      }
    }
    // Update the point-to-tet map.
    parytet->loc = 0;
    ppt = (point *) &(parytet->tet[4]);
    for (j = 0; j < 4; j++) {
      point2tet(ppt[j]) = encode(*parytet);
    }
  }

  // Uninfect all crossing tets.
  for (i = 0; i < crosstets->objects; i++) {
    parytet = (triface *) fastlookup(crosstets, i);
    uninfect(*parytet);
  }

  // Delete new tets.
  for (i = 0; i < topnewtets->objects; i++) {
    parytet = (triface *) fastlookup(topnewtets, i);
    tetrahedrondealloc(parytet->tet);
  }

  for (i = 0; i < botnewtets->objects; i++) {
    parytet = (triface *) fastlookup(botnewtets, i);
    tetrahedrondealloc(parytet->tet);
  }

  crosstets->restart();
  topnewtets->restart();
  botnewtets->restart();
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// splitsubedge()    Split a non-Delaunay edge (not a segment) in the        //
//                   surface mesh of a facet.                                //
//                                                                           //
// The new point 'newpt' will be inserted in the tetrahedral mesh if it does //
// not cause any existing (sub)segments become non-Delaunay.  Otherwise, the //
// new point is not inserted and one of such subsegments will be split.      //
//                                                                           //
// Next,the actual inserted new point is also inserted into the surface mesh.//
// Non-Delaunay segments and newly created subfaces are queued for recovery. //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::splitsubedge(point newpt, face *searchsh, arraypool *facfaces,
  arraypool *facpoints)
{
  triface searchtet;
  face *psseg, sseg;
  point pa, pb;
  enum location loc;
  int s, i;

  // Try to insert the point. Do not insert if it will encroach any segment
  //   (noencsegflag is TRUE). Queue encroacged subfaces.
  assert(subsegstack->objects == 0l); // SELF_CHECK
  searchtet = recenttet; // Start search it from recentet
  loc = insertvertex(newpt, &searchtet, true, true, true, false);

  if (loc == ENCSEGMENT) {
    // Some segments are encroached. Randomly pick one to split.
    assert(subsegstack->objects > 0l);
    s = randomnation(subsegstack->objects);
    psseg = (face *) fastlookup(subsegstack, s);
    sseg = *psseg;
    pa = sorg(sseg);
    pb = sdest(sseg);
    for (i = 0; i < 3; i++) newpt[i] = 0.5 * (pa[i] + pb[i]);
    // Uninfect all queued segments.
    for (i = 0; i < subsegstack->objects; i++) {
      psseg = (face *) fastlookup(subsegstack, i);
      suninfect(*psseg);
    }
    subsegstack->restart();  // Clear the queue.
    // Split the segment. Two subsegments are queued.
    sinsertvertex(newpt, searchsh, &sseg, true, false);
    // Insert the point. Missing segments are queued. 
    searchtet = recenttet; // Start search it from recentet
    insertvertex(newpt, &searchtet, true, true, false, false);
  } else {
    // Calc an above point for point location in surface triangulation.
    calculateabovepoint(facpoints, NULL, NULL, NULL); 
    // Insert the new point on facet. New subfaces are queued for reocvery.
    loc = sinsertvertex(newpt, searchsh, NULL, true, false);
    if (loc == OUTSIDE) {
      assert(0); // Not handled yet.
    }
    // Clear the above point.
    dummypoint[0] = dummypoint[1] = dummypoint[2] = 0;
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// constrainedfacets()    Recover subfaces saved in 'subfacestack'.          //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::constrainedfacets()
{
  arraypool *crosstets, *topnewtets, *botnewtets;
  arraypool *topfaces, *botfaces, *midfaces;
  arraypool *topshells, *botshells, *facfaces;
  arraypool *toppoints, *botpoints, *facpoints;
  triface *parytet, searchtet, neightet;
  face *pssub, ssub, neighsh;
  face checkseg;
  point *ppt, pt, newpt;
  enum intersection dir;
  bool success, delaunayflag;
  long bakflip22count;
  long cavitycount;
  int facetcount;
  int bakhullsize;
  int s, i, j;

  if (b->verbose) {
    printf("  Constraining facets.\n");
  }

  // Initialize arrays.
  crosstets = new arraypool(sizeof(triface), 10);
  topnewtets = new arraypool(sizeof(triface), 10);
  botnewtets = new arraypool(sizeof(triface), 10);
  topfaces = new arraypool(sizeof(triface), 10);
  botfaces = new arraypool(sizeof(triface), 10);
  midfaces = new arraypool(sizeof(triface), 10);
  toppoints = new arraypool(sizeof(point), 8);
  botpoints = new arraypool(sizeof(point), 8);
  facpoints = new arraypool(sizeof(point), 8);
  facfaces = new arraypool(sizeof(face), 10);
  topshells = new arraypool(sizeof(face), 10);
  botshells = new arraypool(sizeof(face), 10);

  bakflip22count = flip22count;
  cavitycount = 0;
  facetcount = 0;

  // Loop until 'subfacstack' is empty.
  while (subfacstack->objects > 0l) {
    subfacstack->objects--;
    pssub = (face *) fastlookup(subfacstack, subfacstack->objects);
    ssub = *pssub;

    if (ssub.sh[3] == NULL) continue; // Skip a dead subface.

    stpivot(ssub, neightet);
    if (neightet.tet == NULL) {
      // Find an unrecovered subface.
      smarktest(ssub);
      facfaces->newindex((void **) &pssub);
      *pssub = ssub;
      // Get all subfaces and vertices of the same facet.
      for (i = 0; i < facfaces->objects; i++) {
        ssub = * (face *) fastlookup(facfaces, i);
        for (j = 0; j < 3; j++) {
          sspivot(ssub, checkseg);
          if (checkseg.sh == NULL) {
            spivot(ssub, neighsh);
            assert(neighsh.sh != NULL); // SELF_CHECK
            if (!smarktested(neighsh)) {
              // It may be already recovered.
              stpivot(neighsh, neightet);
              if (neightet.tet == NULL) {
                smarktest(neighsh);
                facfaces->newindex((void **) &pssub);
                *pssub = neighsh;
              }
            }
          }
          pt = sorg(ssub);
          if (!pinfected(pt)) {
            pinfect(pt);
            facpoints->newindex((void **) &ppt);
            *ppt = pt;
          }
          senextself(ssub);
        } // j
      } // i
      // Have found all facet subfaces (vertices). Uninfect them.
      for (i = 0; i < facfaces->objects; i++) {
        pssub = (face *) fastlookup(facfaces, i);
        sunmarktest(*pssub);
      }
      for (i = 0; i < facpoints->objects; i++) {
        ppt = (point *) fastlookup(facpoints, i);
        puninfect(*ppt);
      }
      if (b->verbose > 1) {
        printf("  Recover facet #%d: %ld subfaces, %ld vertices.\n", 
          facetcount + 1, facfaces->objects, facpoints->objects);
      }
      facetcount++;

      // Loop until 'facfaces' is empty.
      while (facfaces->objects > 0l) {
        // Get the last subface of this array.
        facfaces->objects--;
        pssub = (face *) fastlookup(facfaces, facfaces->objects);
        ssub = *pssub;

        stpivot(ssub, neightet);
        if (neightet.tet != NULL) continue; // Not a missing subface.

        // Insert the subface.
        searchtet.tet = NULL;
        dir = scoutsubface(&ssub, &searchtet);
        if (dir == SHAREFACE) continue; // The subface is inserted.
        assert(dir != COLLISIONFACE); // SELF_CHECK

        // Not exist. Push the subface back into stack.
        s = randomnation(facfaces->objects + 1);
        facfaces->newindex((void **) &pssub);
        *pssub = * (face *) fastlookup(facfaces, s);
        * (face *) fastlookup(facfaces, s) = ssub;

        if (dir == EDGETRIINT) continue; // All three edges are missing.

        // Search for a crossing tet.
        dir = scoutcrosstet(&ssub, &searchtet, facpoints);

        if (dir == ACROSSTET) {
          // Recover subfaces by local retetrahedralization.
          cavitycount++;
          bakhullsize = hullsize;
          checksubsegs = checksubfaces = 0;
          crosstets->newindex((void **) &parytet);
          *parytet = searchtet;
          // Form a cavity of crossing tets.
          formcavity(&ssub, crosstets, topfaces, botfaces, toppoints,
            botpoints, facpoints);
          delaunayflag = true;
          // Tetrahedralize the top part. Re-use 'midfaces'.
          success = delaunizecavity(toppoints, topfaces, topshells,
            topnewtets, crosstets, midfaces);
          if (success) {
            // Tetrahedralize the bottom part. Re-use 'midfaces'.
            success = delaunizecavity(botpoints, botfaces, botshells, 
              botnewtets, crosstets, midfaces);
            if (success) {
              // Fill the cavity with new tets.
              success = fillcavity(topshells, botshells, midfaces, facpoints);
              if (success) {
                // Delete old tets and outer new tets.
                carvecavity(crosstets, topnewtets, botnewtets);
              }
            } else {
              delaunayflag = false;
            }
          } else {
            delaunayflag = false;
          }
          if (!success) {
            // Restore old tets and delete new tets.
            restorecavity(crosstets, topnewtets, botnewtets);
          }
          /*if (!delaunayflag) {
            dump_facetof(&ssub, "facet1.lua");
            while (futureflip != NULL) {
              formedgecavity(futureflip->forg, futureflip->fdest, crosstets, 
                topfaces, toppoints);
              crosstets->restart();
              topfaces->restart();
              toppoints->restart();
              futureflip = futureflip->nextitem;
            }
            flippool->restart();
            outnodes(0);
            checkmesh();
            checkshells(1);
            assert(0); // Stop the program.
          }*/
          hullsize = bakhullsize;
          checksubsegs = checksubfaces = 1;
        } else if (dir == ACROSSFACE) {
          // Recover subfaces by flipping edges in surface mesh.
          recoversubfacebyflips(&ssub, &searchtet, facfaces);
          success = true;
        } else { // dir == TOUCHFACE
          assert(0);
        }
        if (!success) break;
      } // while

      if (facfaces->objects > 0l) {
        // Found a non-Delaunay edge, split it (or a segment close to it).
        // Create a new point at the middle of this edge, its coordinates
        //   were saved in dummypoint in 'fillcavity()'.
        makepoint(&newpt);
        for (i = 0; i < 3; i++) newpt[i] = dummypoint[i];
        setpointtype(newpt, STEINERVERTEX);
        dummypoint[0] = dummypoint[1] = dummypoint[2] = 0;
        // Insert the new point. Starting search it from 'ssub'.
        splitsubedge(newpt, &ssub, facfaces, facpoints);
        facfaces->restart();
      }
      // Clear the list of facet vertices.
      facpoints->restart();

      // Some subsegments may be queued, recover them.
      if (subsegstack->objects > 0l) {
        b->verbose--; // Suppress the message output.
        delaunizesegments();
        b->verbose++;
      }
      // Now the mesh should be constrained Delaunay.
    } // if (neightet.tet == NULL) 
  }

  if (b->verbose) {
    printf("  %ld subedge flips.\n", flip22count - bakflip22count);
    printf("  %ld cavities remeshed.\n", cavitycount);
  }

  // Delete arrays.
  delete crosstets;
  delete topnewtets;
  delete botnewtets;
  delete topfaces;
  delete botfaces;
  delete midfaces;
  delete toppoints;
  delete botpoints;
  delete facpoints;
  delete facfaces;
  delete topshells;
  delete botshells;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// scoutedge()    Search an edge in current tetrahedralization.              //
//                                                                           //
// The edge [a, b] will be searched. If the edge exists, return a handle in  //
// the tetrahedralization ('searchtet') referring to this edge. If the edge  //
// is missing, and the array 'crosstets' is not a NULL,  return the cavity   //
// of all corssing tets of this edge.                                        //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

enum tetgenmesh::intersection tetgenmesh::scoutedge(point pa, point pb,
  triface* searchtet, arraypool* crosstets, arraypool* cavfaces,
  arraypool* cavpoints)
{
  triface neightet, spintet, *parytet;
  face checksh, checkseg;
  point pc, pd, pe, pf, *ppt, *parypt;
  enum intersection dir;
  int types[2], poss[4];
  int pos, i;

  tetrahedron ptr;
  int *iptr, tver;

  if (b->verbose > 1) {
    printf("    Search edge (%d, %d).\n", pointmark(pa), pointmark(pb));
  }

  // Search a tet whose origin is pa.
  point2tetorg(pa, *searchtet);

  // Search the line segment [pa, pb].
  dir = finddirection(searchtet, pb);
  if (dir == ACROSSVERT) {
    if (dest(*searchtet) == pb) {
      // Found! Does there already exist a segment.
      return SHAREEDGE; // The edge is not missing.
    } else {
      return ACROSSVERT; // The edge intersects a vertex.
    }
  }

  // The edge is missing, shall we form the edge cavity?
  if ((crosstets == NULL) && (cavfaces == NULL) && (cavpoints == NULL)) {
    return dir; // ACROSSFACE and ACROSSEDGE
  }

  // The possible cases are: ACROSSFACE and ACROSSEDGE.
  // Go to the opposite (intersect) face.
  enextfnextself(*searchtet);
  // Add this tet into list.
  infect(*searchtet);
  crosstets->newindex((void **) &parytet);
  *parytet = *searchtet;
  // Add all vertices of this tet into list.
  ppt = (point *) &(searchtet->tet[4]);
  for (i = 0; i < 4; i++) {
    pinfect(ppt[i]);
    cavpoints->newindex((void **) &parypt);
    *parypt = ppt[i];
  }

  // Collect all crossing tets of the edge [a, b].
  while (1) {

    // Enter the next crossing tet.
    symedgeself(*searchtet);
    pf = oppo(*searchtet);

    if (dir == ACROSSFACE) {
      if (!infected(*searchtet)) { // Add this tet into list.
        infect(*searchtet);
        crosstets->newindex((void **) &parytet);
        *parytet = *searchtet;
      }
      if (!pinfected(pf)) { // Add the opposite point into list.
        pinfect(pf);
        cavpoints->newindex((void **) &parypt);
        *parypt = pf;
      }
      tspivot(*searchtet, checksh); // Check if a subface is crossed.
      if (checksh.sh != NULL) {
        // The edge intersect a subface.
        dir = ACROSSSUBFACE;
        break;
      }
    } else { // dir == ACROSSEDGE
      // Add all tets containing this edge into list.
      pc = apex(*searchtet);
      spintet = *searchtet;
      while (1) {
        fnextself(spintet);
        if (!infected(spintet)) { // Add this tet into list.
          infect(spintet);
          crosstets->newindex((void **) &parytet);
          *parytet = spintet;
        }
        pd = oppo(spintet);
        if (!pinfected(pd)) { // Add the opposite point into list.
          pinfect(pd);
          cavpoints->newindex((void **) &parypt);
          *parypt = pd;
        }
        if (apex(spintet) == pc) break;
      }
      tsspivot(spintet, checkseg); // Check if a segment is crossed.
      if (checkseg.sh != NULL) {
        // The edge intersects a subsegment.
        dir = ACROSSSUBSEG;
        break;
      }
    }

    // Stop if we reach the endpoint.
    if (pf == pb) break;

    // Search the next tet crossing by [a, b].
    if (dir == ACROSSFACE) {
      // One of the 3 opposite faces in 'searchtet' must intersect [a, b].
      neightet.tet = searchtet->tet;
      neightet.ver = 0;
      for (i = 0; i < 3; i++) {
        neightet.loc = locpivot[searchtet->loc][i];
        pc = org(neightet);
        pd = dest(neightet);
        pe = apex(neightet);
        pf = oppo(neightet); // The above point.
        // Test if face [c, d, e] intersects edge [a, b]? Report their
        //   intersection type ('level' = 1).
        if (tri_edge_test(pc, pd, pe, pa, pb, pf, 1, types, poss)) {
          dir = (enum intersection) types[0];
          pos = poss[0];
          break;
        } else {
          dir = DISJOINT;
          pos = 0;
        }
      }
      assert(dir != DISJOINT);  // SELF_CHECK
    } else { // dir == ACROSSEDGE
      // Find a face (or edge) intersecting with [a, b].
      spintet = *searchtet; // Backup the starting tet.
      while (1) {
        // Check the two opposite faces (of the edge) in 'searchtet'.
        neightet.tet = searchtet->tet;
        neightet.ver = 0;
        for (i = 0; i < 2; i++) {
          neightet.loc = locverpivot[searchtet->loc][searchtet->ver][i];
          pc = org(neightet);
          pd = dest(neightet);
          pe = apex(neightet);
          pf = oppo(neightet); // The above point.
          // Test if face [c, d, e] intersects edge [a, b]? Report their
          //   intersection type ('level' = 1).
          if (tri_edge_test(pc, pd, pe, pa, pb, pf, 1, types, poss)) {
            dir = (enum intersection) types[0];
            pos = poss[0];
            break;
          } else {
            dir = DISJOINT;
            pos = 0;
          }
        }
        if (dir == DISJOINT) {
          // No intersection. Go to the next tet.
          fnextself(*searchtet);
          // Should NOT return to the starting tet.
          assert(searchtet->tet != spintet.tet); // SELF_CHECK
          continue; // Continue the search.
        }
        break; // Found!
      } // while (1)
    }

    // Go to the intersect face or edge.
    if (dir != ACROSSFACE) {
      // 'dir' is either ACROSSFACE or ACROSSEDGE.
      assert(dir == ACROSSEDGE); // SELF_CHECK
      for (i = 0; i < pos; i++) {
        enextself(neightet);
      }
    }
    *searchtet = neightet;

  } // while (1)

  if ((dir == ACROSSSUBSEG) || (dir == ACROSSSUBFACE)) {
    // Uninfect the collected crossing tets and vertices.
    for (i = 0; i < crosstets->objects; i++) {
      parytet = (triface *) fastlookup(crosstets, i);
      uninfect(*parytet);
    }
    for (i = 0; i < cavpoints->objects; i++) {
      parypt = (point *) fastlookup(cavpoints, i);
      puninfect(*parypt);
    }
    crosstets->restart();
    cavpoints->restart();
    return dir;
  }

  //We can form the edge cavity.
  for (i = 0; i < crosstets->objects; i++) {
    parytet = (triface *) fastlookup(crosstets, i);
    *searchtet = *parytet;
    for (searchtet->loc = 0; searchtet->loc < 4; searchtet->loc++) {
      sym(*searchtet, neightet);
      if (!infected(neightet)) {
        // A cavity bounday face.
        cavfaces->newindex((void **) &parytet);
        *parytet = neightet;
      }
    }
  }

  // Uninfect the collected crossing tets and vertices.
  for (i = 0; i < crosstets->objects; i++) {
    parytet = (triface *) fastlookup(crosstets, i);
    uninfect(*parytet);
  }
  for (i = 0; i < cavpoints->objects; i++) {
    parypt = (point *) fastlookup(cavpoints, i);
    puninfect(*parypt);
  }

  if (b->verbose > 1) {
    printf("    Formed edge cavity: %ld tets, %ld faces, %ld vertices.\n",
      crosstets->objects, cavfaces->objects, cavpoints->objects);
  }

  return ACROSSFACE; // or ACROSSEDGE
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// formskeleton()    Form a constrained tetrahedralization.                  //
//                                                                           //
// The segments and facets of a PLS will be recovered.                       //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::formskeleton()
{
  face *pssub, ssub;
  REAL bakeps;
  int s, i;

  if (!b->quiet) {
    printf("Recovering boundaries.\n");
  }

  // Bakup the epsilon.
  bakeps = b->epsilon;
  b->epsilon = 0;

  // Put all segments into the list.
  if (b->order == 4) {  // '-o4' option (for debug)
    // The sequential order.
    subsegpool->traversalinit();
    for (i = 0; i < subsegpool->items; i++) {
      ssub.sh = shellfacetraverse(subsegpool);
      sinfect(ssub);  // Only save it once.
      subsegstack->newindex((void **) &pssub);
      *pssub = ssub;
    }
  } else {
    // Randomly order the segments.
    subsegpool->traversalinit();
    for (i = 0; i < subsegpool->items; i++) {
      s = randomnation(i + 1);
      // Move the s-th seg to the i-th.
      subsegstack->newindex((void **) &pssub);
      *pssub = * (face *) fastlookup(subsegstack, s);
      // Put i-th seg to be the s-th.
      ssub.sh = shellfacetraverse(subsegpool);
      sinfect(ssub);  // Only save it once.
      pssub = (face *) fastlookup(subsegstack, s);
      *pssub = ssub;
    }
  }

  // Segments will be introduced.
  checksubsegs = 1;
  // Recover segments.
  delaunizesegments();

  // Randomly order the subfaces.
  subfacepool->traversalinit();
  for (i = 0; i < subfacepool->items; i++) {
    s = randomnation(i + 1);
    // Move the s-th subface to the i-th.
    subfacstack->newindex((void **) &pssub);
    *pssub = * (face *) fastlookup(subfacstack, s);
    // Put i-th subface to be the s-th.
    ssub.sh = shellfacetraverse(subfacepool);
    pssub = (face *) fastlookup(subfacstack, s);
    *pssub = ssub;
  }

  // Subfaces will be introduced.
  checksubfaces = 1;
  // Recover facets.
  constrainedfacets();

  // checksubsegs = 0;
  b->epsilon = bakeps;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// carveholes()    Remove tetrahedra not in the mesh domain.                 //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::carveholes()
{
  arraypool *tetarray;
  triface tetloop, neightet, hulltet, *parytet, *parytet1, fliptets[3];
  triface openface, casface;
  triface *regiontets;
  face checksh, neighsh, flipshs[2];
  face checkseg;
  point *ppt, pa, pb, pc;
  enum location loc;
  REAL volume;
  int attrnum, attr, maxattr;
  int flatcount;
  int i, j, k;

  tetrahedron ptr;
  int *iptr, tver;

  if (!b->quiet) {
    printf("Removing exterior tetrahedra.\n");
  }

  // Initialize the pool of exterior tets.
  tetarray = new arraypool(sizeof(triface), 10);

  maxattr = 0; // Choose a small number here.
  attrnum = in->numberoftetrahedronattributes;

  // Mark as infected any unprotected hull tets.
  tetrahedronpool->traversalinit();
  tetloop.loc = 0;
  tetloop.tet = alltetrahedrontraverse();
  while (tetloop.tet != (tetrahedron *) NULL) {
    if ((point) tetloop.tet[7] == dummypoint) {
      // Is this side protected by a subface?
      tspivot(tetloop, checksh);
      if (checksh.sh == NULL) {
        infect(tetloop);
        tetarray->newindex((void **) &parytet);
        *parytet = tetloop;
      }
    }
    tetloop.tet = alltetrahedrontraverse();
  }

  hullsize -= tetarray->objects;

  if (in->numberofholes > 0) {
    // Mark as infected any tets inside volume holes.
    for (i = 0; i < 3 * in->numberofholes; i += 3) {
      // Search a tet containing the i-th hole point.
      neightet.tet = NULL;
      randomsample(&(in->holelist[i]), &neightet);
      loc = locate(&(in->holelist[i]), &neightet);
      if (loc != OUTSIDE) {
        infect(neightet);
        tetarray->newindex((void **) &parytet);
        *parytet = neightet;
      }
    }
  }

  if (b->regionattrib && (in->numberofregions > 0)) { // If has -A option.
    // Record the tetrahedra that contains the region points for assigning
    //   region attributes after the holes have been carved.
    regiontets = new triface[in->numberofregions];
    // Mark as marktested any tetrahedra inside volume regions.
    for (i = 0; i < 5 * in->numberofregions; i += 5) {
      // Search a tet containing the i-th hole point.
      neightet.tet = NULL;
      randomsample(&(in->regionlist[i]), &neightet);
      loc = locate(&(in->regionlist[i]), &neightet);
      if (loc != OUTSIDE) {
        regiontets[i/5] = neightet;
        if ((int) in->regionlist[i + 3] > maxattr) {
          maxattr = (int) in->regionlist[i + 3];
        }
      } else {
        if (b->verbose) {
          printf("Warning:  The %d-th region point is in outside.\n", i/5+1);
        }
        regiontets[i/5].tet = NULL;
      }
    }
  }

  // Find and infect all exterior tets.
  for (i = 0; i < tetarray->objects; i++) {
    parytet = (triface *) fastlookup(tetarray, i);
    tetloop = *parytet;
    for (tetloop.loc = 0; tetloop.loc < 4; tetloop.loc++) {
      symedge(tetloop, neightet);
      // Is this side protected by a subface?
      tspivot(tetloop, checksh);
      if (checksh.sh == NULL) {
        // Not protected. Infect it if it is not a hull tet.
        if ((point) neightet.tet[7] != dummypoint) {
          if (!infected(neightet)) {
            infect(neightet);
            tetarray->newindex((void **) &parytet);
            *parytet = neightet;
          }
        }
      } else {
        // Its adjacent tet is protected.
        if ((point) neightet.tet[7] == dummypoint) {
          // A hull tet. It is dead.
          assert(!infected(neightet));
          infect(neightet);
          tetarray->newindex((void **) &parytet);
          *parytet = neightet;
          // Both sides of this subface are exterior.
          stdissolve(checksh);
          hullsize--;
        } else {
          if (!infected(neightet)) {
            // Let the subface connect to the "live" tet.
            tsbond(neightet, checksh);
          } else {
            // Both sides of this subface are exterior.
            stdissolve(checksh);
          }
        }
      }
    }
  }

  if (b->regionattrib && (in->numberofregions > 0)) {
    // Re-check saved region tets to see if they lie outside.
    for (i = 0; i < in->numberofregions; i++) {
      if (infected(regiontets[i])) {
        if (b->verbose) {
          printf("Warning:  The %d-th region point is in outside.\n", i+1);
        }
        regiontets[i].tet = NULL;
      }
    }
  }

  // Remove all exterior tetrahedra (including infected hull tets).
  for (i = 0; i < tetarray->objects; i++) {
    parytet = (triface *) fastlookup(tetarray, i);
    tetloop = *parytet;
    for (tetloop.loc = 0; tetloop.loc < 4; tetloop.loc++) {
      symedge(tetloop, neightet);
      if (!infected(neightet)) {
        // A "live" tet (may be a hull tet). Clear its adjacent tet.
        neightet.tet[neightet.loc] = NULL;
      }
    }
    tetrahedrondealloc(parytet->tet);
  }

  tetarray->restart(); // Re-use it for new hull tets.

  // Create new hull faces and update the point-to-tet map.
  tetrahedronpool->traversalinit();
  tetloop.ver = 0;
  tetloop.tet = tetrahedrontraverse();
  while (tetloop.tet != (tetrahedron *) NULL) {
    for (tetloop.loc = 0; tetloop.loc < 4; tetloop.loc++) {
      if (tetloop.tet[tetloop.loc] == NULL) {
        tspivot(tetloop, checksh);
        assert(checksh.sh != NULL); // SELF_CHECK
        // Create a new hull tet.
        maketetrahedron(&hulltet);
        pa = org(tetloop);
        pb = dest(tetloop);
        pc = apex(tetloop);
        setvertices(hulltet, pb, pa, pc, dummypoint);
        bond(tetloop, hulltet);
        tsbond(hulltet, checksh);
        // Save this hull tet in list.
        tetarray->newindex((void **) &parytet);
        *parytet = hulltet;
      }
    }
    tetloop.loc = 0;
    ptr = encode(tetloop);
    ppt = (point *) tetloop.tet;
    for (i = 4; i < 8; i++) {
      point2tet(ppt[i]) = ptr;
    }
    tetloop.tet = tetrahedrontraverse();
  }

  // Update the hull size.
  hullsize += tetarray->objects;

  // Connect new hull tets.
  for (i = 0; i < tetarray->objects; i++) {
    parytet = (triface *) fastlookup(tetarray, i);
    hulltet = *parytet;
    assert(oppo(hulltet) == dummypoint); // SELF_CHECK
    hulltet.ver = 0;
    for (j = 0; j < 3; j++) {
      enext0fnext(hulltet, neightet);
      if (neightet.tet[neightet.loc] == NULL) {
        esym(hulltet, casface);
        while (1) {
          symedgeself(casface);
          enext0fnextself(casface);
          if (apex(casface) == dummypoint) break;
        }
        bond(neightet, casface);
      }
      enextself(hulltet);
    }
  }

  //////////////////////////////////////////////////////////////////////
  // Peel off "flat" tetrahedra at boundary. 

  tetarray->restart(); // Re-use this array.
  flatcount = 0;

  // Queue flat tets.
  tetrahedronpool->traversalinit();
  tetloop.ver = 0;
  tetloop.tet = tetrahedrontraverse();
  while (tetloop.tet != (tetrahedron *) NULL) {
    // Does this tet contain subfaces?
    if (tetloop.tet[9] != NULL) {
      // Look at shared subface at its 6 edges.
      for (i = 0; i < 6; i++) {
        tetloop.loc = edge2locver[i][0];
        tetloop.ver = edge2locver[i][1];
        // Is this edge a segment?
        tsspivot(tetloop, checkseg);
        if (checkseg.sh == NULL) {
          // No segment. Is this edge shared by two subfaces?
          tspivot(tetloop, checksh);
          if (checksh.sh != NULL) {
            enext0fnext(tetloop, neightet);
            tspivot(neightet, neighsh);
            if (neighsh.sh != NULL) {
              if (b->verbose > 1) {
                ppt = (point *) &tetloop.tet[4];
                printf("    p:draw_tet(%d, %d, %d, %d) -- flat\n",
                  pointmark(ppt[0]), pointmark(ppt[1]), pointmark(ppt[2]),
                  pointmark(ppt[3]));
              }
              tetarray->newindex((void **) &parytet);
              *parytet = tetloop;
              break;
            } // neighsh.sh != NULL
          } // checksh.sh != NULL
        } // checkseg.sh != NULL
      } // i
    }
    tetloop.tet = tetrahedrontraverse();
  }

  if (tetarray->objects > 0) {
    if (b->verbose) {
      printf("  Removing flat boundary tetrahedra.\n");
    }
  }

  // Remove flat tets, new flat tets are queued.
  for (i = 0; i < tetarray->objects; i++) {
    parytet = (triface *) fastlookup(tetarray, i);
    assert(parytet->tet[4] != NULL); // SELF_CHECK
    sym(*parytet, neightet);
    if ((point) neightet.tet[7] != dummypoint) {
      continue; // An internal face. Can't be peeled off.
    }

    if (b->verbose > 1) {
      printf("    i = %d.\n", i);
    }

    enext0fnext(*parytet, neightet);
    pa = org(*parytet);
    pb = dest(*parytet);
    tspivot(*parytet, flipshs[0]); // [0] abc
    for (j = 0; j < 3; j++) {
      if (sorg(flipshs[0]) == pa) break;
      senextself(flipshs[0]);
    }
    assert(j < 3); // SELF_CHECK
    if (sdest(flipshs[0]) != pb) {
      senext2self(flipshs[0]);
      sesymself(flipshs[0]);
    }
    assert(sdest(flipshs[0]) == pb); // SELF_CHECK
    tspivot(neightet, flipshs[1]); // [1] bda
    for (j = 0; j < 3; j++) {
      if (sorg(flipshs[1]) == pb) break;
      senextself(flipshs[1]);
    }
    assert(j < 3); // SELF_CHECK
    if (sdest(flipshs[1]) != pa) {
      senext2self(flipshs[1]);
      sesymself(flipshs[1]);
    }
    assert(sdest(flipshs[1]) == pa); // SELF_CHECK

    // Detach abc and bad.
    sym(*parytet, casface);
    tsdissolve(*parytet);
    tsdissolve(casface);
    sym(neightet, casface);
    tsdissolve(neightet);
    tsdissolve(casface);

    // flip [0]abc,[1]bad to [0]cdb, [1]dca
    flip22(flipshs, 0);

    for (k = 0; k < 2; k++) {
      if (k == 0) {
        // Insert flipshs[0] [c,d,b] to adjacent tets.
        enextfnext(*parytet, neightet); // face [b,c,d].
        enextself(neightet); // edge [c,d] in face [c,d,b].
      } else {
        // Insert flipshs[1] [d,c,a] to adjacent tets.
        enext2fnext(*parytet, neightet); // face [c,a,d].
        enext2self(neightet); // edge [d,c] in face [d,c,a].
      }
      symedge(neightet, casface);
      assert((point) casface.tet[7] != dummypoint); // SELF_CHECK
      tspivot(neightet, checksh); // SELF_CHECK
      assert(checksh.sh == NULL); // SELF_CHECK
      tsbond(neightet, flipshs[k]);
      tsbond(casface, flipshs[k]);
      // Check for new invalid tet(s) (at edge [d,b] and [b,c]).
      for (j = 0; j < 2; j++) {
        enextself(casface); // edges [d,b], [b,c].
        tsspivot(casface, checkseg);
        if (checkseg.sh == NULL) {
          enext0fnext(casface, openface);
          tspivot(openface, checksh);
          if (checksh.sh != NULL) {
            if (b->verbose > 1) {
               ppt = (point *) &casface.tet[4];
               printf("    p:draw_tet(%d, %d, %d, %d) -- flat\n",
                 pointmark(ppt[0]), pointmark(ppt[1]), pointmark(ppt[2]),
                 pointmark(ppt[3]));
            }
            tetarray->newindex((void **) &parytet1);
            *parytet1 = casface;
            break;
          }
        }
      } // j
    } // k

    // Peel the flat boundary tet by a flip32.
    fliptets[0] = *parytet;
    fnext(fliptets[0], fliptets[1]);
    fnext(fliptets[1], fliptets[2]);
    assert(apex(fliptets[2]) == dummypoint); // SELF_CHECK
    assert(oppo(fliptets[2]) == apex(fliptets[0])); // SELF_CHECK

    // Flip the tets (with hull tets, do not propagate).
    flip32(fliptets, 1, 0);
    // Now the flat boundary tet is removed.
    flatcount++;
  } // i

  if (tetarray->objects > 0) {
    if (b->verbose) {
      printf("  %d flat tets are removed.\n", flatcount);
    }
  }

  /////////////////////////////////////////////////////////////////////////

  // Set region attributes (when has -A and -AA options).
  if (b->regionattrib) {

    if (!b->quiet) {
      printf("Spreading region attributes.\n");
    }

    // If has user-defined region attributes.
    if (in->numberofregions > 0) {
      // Spread region attributes.
      for (i = 0; i < 5 * in->numberofregions; i += 5) {
        if (regiontets[i/5].tet != NULL) {
          attr = (int) in->regionlist[i + 3];
          volume = in->regionlist[i + 4];
          tetarray->restart(); // Re-use this array.
          infect(regiontets[i/5]);
          tetarray->newindex((void **) &parytet);
          *parytet = regiontets[i/5];
          // Collect and set attrs for all tets of this region.
          for (j = 0; j < tetarray->objects; j++) {
            parytet = (triface *) fastlookup(tetarray, j);
            tetloop = *parytet;
            setelemattribute(tetloop.tet, attrnum, attr);
            if (b->varvolume) { // If has -a option.
              setvolumebound(tetloop.tet, volume);
            }
            for (tetloop.loc = 0; tetloop.loc < 4; tetloop.loc++) {
              sym(tetloop, neightet);
              // Is this side protected by a subface?
              tspivot(tetloop, checksh);
              if (checksh.sh == NULL) {
                // Not protected. It must not be a hull tet.
                // assert((point) neightet.tet[7] != dummypoint);
                if ((point) neightet.tet[7] == dummypoint) {
                  assert(0);
                }
                if (!infected(neightet)) {
                  infect(neightet);
                  tetarray->newindex((void **) &parytet);
                  *parytet = neightet;
                }
              } else {
                // Protected. Set attribute for hull tet as well.
                if ((point) neightet.tet[7] == dummypoint) {
                  setelemattribute(neightet.tet, attrnum, attr);
                  if (b->varvolume) { // If has -a option.
                    setvolumebound(neightet.tet, volume);
                  }
                }
              }
            } // loc
          } // j
        }
      } // i
      delete [] regiontets;
    }

    if (b->regionattrib > 1) { // If has -AA option.
      // Set attributes for all tetrahedra.
      attr = maxattr + 1;
      tetrahedronpool->traversalinit();
      tetloop.tet = tetrahedrontraverse();
      while (tetloop.tet != (tetrahedron *) NULL) {
        if (!infected(tetloop)) {
          // An unmarked region.
          tetarray->restart(); // Re-use this array.
          infect(tetloop);
          tetarray->newindex((void **) &parytet);
          *parytet = tetloop;
          // Find and mark all tets.
          for (j = 0; j < tetarray->objects; j++) {
            parytet = (triface *) fastlookup(tetarray, j);
            tetloop = *parytet;
            setelemattribute(tetloop.tet, attrnum, attr);
            for (tetloop.loc = 0; tetloop.loc < 4; tetloop.loc++) {
              sym(tetloop, neightet);
              // Is this side protected by a subface?
              tspivot(tetloop, checksh);
              if (checksh.sh == NULL) {
                // Not protected. It must not be a hull tet.
                assert((point) neightet.tet[7] != dummypoint);
                if (!infected(neightet)) {
                  infect(neightet);
                  tetarray->newindex((void **) &parytet);
                  *parytet = neightet;
                }
              } else {
                // Protected. Set attribute for hull tet as well.
                if ((point) neightet.tet[7] == dummypoint) {
                  setelemattribute(neightet.tet, attrnum, attr);
                }
              }
            } // loc
          }
          attr++; // Increase the attribute.
        }
        tetloop.tet = tetrahedrontraverse();
      }
      // Until here, every tet has a region attribute.
    }

    // Uninfect processed tets.
    tetrahedronpool->traversalinit();
    tetloop.tet = tetrahedrontraverse();
    while (tetloop.tet != (tetrahedron *) NULL) {
      uninfect(tetloop);
      tetloop.tet = tetrahedrontraverse();
    }

    // Mesh elements contain region attributes now.
    in->numberoftetrahedronattributes++;

  } // if (b->regionattrib)

  delete tetarray;
}

#endif // #ifndef constrainCXX
