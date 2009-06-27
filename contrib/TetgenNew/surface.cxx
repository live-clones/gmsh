#ifndef surfaceCXX
#define surfaceCXX

#include "tetgen.h"

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// calculateabovepoint()    Calculate a point above a facet in 'dummypoint'. //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

bool tetgenmesh::calculateabovepoint(arraypool *facpoints, point *ppa,
  point *ppb, point *ppc)
{
  point *ppt, pa, pb, pc;
  REAL v1[3], v2[3], n[3];
  REAL lab, len, A, area;
  REAL x, y, z;
  int i;

  ppt = (point *) fastlookup(facpoints, 0);
  pa = *ppt; // a is the first point.

  // Get a point b s.t. the length of [a, b] is maximal.
  lab = 0;
  for (i = 1; i < facpoints->objects; i++) {
    ppt = (point *) fastlookup(facpoints, i);
    x = (*ppt)[0] - pa[0];
    y = (*ppt)[1] - pa[1];
    z = (*ppt)[2] - pa[2];
    len = x * x + y * y + z * z;
    if (len > lab) {
      lab = len;
      pb = *ppt;
    }
  }
  lab = sqrt(lab);
  if (lab == 0) {
    if (!b->quiet) {
      printf("Warning:  All points of a facet are coincident with %d.\n",
        pointmark(pa));
    }
    return false;
  }

  // Get a point c s.t. the area of [a, b, c] is maximal.
  v1[0] = pb[0] - pa[0];
  v1[1] = pb[1] - pa[1];
  v1[2] = pb[2] - pa[2];
  A = 0;
  for (i = 1; i < facpoints->objects; i++) {
    ppt = (point *) fastlookup(facpoints, i);
    v2[0] = (*ppt)[0] - pa[0];
    v2[1] = (*ppt)[1] - pa[1];
    v2[2] = (*ppt)[2] - pa[2];
    CROSS(v1, v2, n);
    area = DOT(n, n);
    if (area > A) {
      A = area;
      pc = *ppt;
    }
  }
  if (A == 0) {
    // All points are collinear. No above point.
    if (!b->quiet) {
      printf("Warning:  All points of a facet are collinaer with [%d, %d].\n",
        pointmark(pa), pointmark(pb));
    }
    return false;
  }

  // Calculate an above point of this facet.
  facenormal(pa, pb, pc, n, 1);
  len = sqrt(DOT(n, n));
  n[0] /= len;
  n[1] /= len;
  n[2] /= len;
  lab /= 2.0;
  dummypoint[0] = 0.5 * (pa[0] + pb[0]) + lab * n[0];
  dummypoint[1] = 0.5 * (pa[1] + pb[1]) + lab * n[1];
  dummypoint[2] = 0.5 * (pa[2] + pb[2]) + lab * n[2];

  if (ppa != NULL) {
    // Return the three points.
    *ppa = pa;
    *ppb = pb;
    *ppc = pc;
  }

  return true;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// slocate()    Locate a point in a surface triangulation.                   //
//                                                                           //
// Search the point (p) from the input 'searchsh' (it should not be NULL).   //
//                                                                           //
// It is assumed that 'dummypoint' lies above the facet of the triangulation,//
// hence a CCW test (2D orientation) is equal to a below-plane (3D) test.    //
//                                                                           //
// The returned value inducates the following cases:                         //
//   - ONVERTEX, p is the origin of 'searchsh'.                              //
//   - ONEDGE, p lies on the edge of 'searchsh'.                             //
//   - ONFACE, p lies in the interior of 'searchsh'.                         //
//   - OUTSIDE, p lies outside of the triangulation, p is on the left-hand   //
//     side of the edge 'searchsh'(s), i.e., org(s), dest(s), p are CW.      //
//                                                                           //
// If 'cflag' is not TRUE, the triangulation may not be convex.  Stop search //
// when a segment is met and return OUTSIDE.                                 //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

enum tetgenmesh::location tetgenmesh::slocate(point searchpt, face* searchsh, 
  bool cflag)
{
  face neighsh;
  face checkseg;
  point pa, pb, pc, pd;
  REAL ori, ori_bc, ori_ca;
  REAL dist_bc, dist_ca;
  int i;

  enum {MOVE_BC, MOVE_CA} nextmove;

  shellface sptr;

  // Adjust the face orientation s.t. 'dummypt' lies above to it.
  pa = sorg(*searchsh);
  pb = sdest(*searchsh);
  pc = sapex(*searchsh);
  ori = orient3d(pa, pb, pc, dummypoint);
  assert(ori != 0); // SELF_CHECK
  if (ori > 0) {
    sesymself(*searchsh); // Reverse the face orientation.
  }

  // Find an edge of the face s.t. p lies on its right-hand side (CCW).
  for (i = 0; i < 3; i++) {
    pa = sorg(*searchsh);
    pb = sdest(*searchsh);
    ori = orient3d(pa, pb, dummypoint, searchpt);
    if (ori > 0) break;
    senextself(*searchsh);
  }
  assert(i < 3); // SELF_CHECK

  while (1) {

    pc = sapex(*searchsh);

    if (pc == searchpt) {
      senext2self(*searchsh);
      return ONVERTEX;
    }

    ori_bc = orient3d(pb, pc, dummypoint, searchpt);
    ori_ca = orient3d(pc, pa, dummypoint, searchpt);

    if (ori_bc < 0) {
      if (ori_ca < 0) { // (--)
        // Any of the edges is a viable move.
        senext(*searchsh, neighsh); // At edge [b, c].
        spivotself(neighsh);
        if (neighsh.sh != NULL) {
          pd = sapex(neighsh);
          dist_bc = NORM2(searchpt[0] - pd[0], searchpt[1] - pd[1],
            searchpt[2] - pd[2]);
        } else {
          dist_bc = NORM2(xmax - xmin, ymax - ymin, zmax - zmin);
        }
        senext2(*searchsh, neighsh); // At edge [c, a].
        spivotself(neighsh);
        if (neighsh.sh != NULL) {
          pd = sapex(neighsh);
          dist_ca = NORM2(searchpt[0] - pd[0], searchpt[1] - pd[1],
            searchpt[2] - pd[2]);
        } else {
          dist_ca = dist_bc;
        }
        if (dist_ca < dist_bc) {
          nextmove = MOVE_CA;
        } else {
          nextmove = MOVE_BC;
        }
      } else { // (-#)
        // Edge [b, c] is viable.
        nextmove = MOVE_BC;
      }
    } else {
      if (ori_ca < 0) { // (#-)
        // Edge [c, a] is viable.
        nextmove = MOVE_CA;
      } else {
        if (ori_bc > 0) {
          if (ori_ca > 0) { // (++)
            return ONFACE;  // Inside [a, b, c].
          } else { // (+0)
            senext2self(*searchsh); // On edge [c, a].
            return ONEDGE;
          }
        } else { // ori_bc == 0
          if (ori_ca > 0) { // (0+)
            senextself(*searchsh); // On edge [b, c].
            return ONEDGE;
          } else { // (00)
            // On vertex c. Should be checked in above.
            assert(0); // SELF_CHECK
          }
        }
      }
    }

    // Move to the next face.
    if (nextmove == MOVE_BC) {
      senextself(*searchsh);
    } else {
      senext2self(*searchsh);
    }
    if (!cflag) {
      // NON-convex case. Chekc if we will cross a boundary.
      sspivot(*searchsh, checkseg);
      if (checkseg.sh != NULL) {
        return OUTSIDE; // Do not cross a boundary edge.
      }
    }
    spivot(*searchsh, neighsh);
    if (neighsh.sh == NULL) {
      return OUTSIDE; // A hull edge.
    }
    // Adjust the edge orientation.
    if (sorg(neighsh) != sdest(*searchsh)) {
      sesymself(neighsh);
    }
    assert(sorg(neighsh) == sdest(*searchsh)); // SELF_CHECK

    // Update the newly discovered face and its endpoints.
    *searchsh = neighsh;
    pa = sorg(*searchsh);
    pb = sdest(*searchsh);
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// sinsertvertex()    Insert a vertex into a triangulation of a facet.       //
//                                                                           //
// The new point (p) will be located. Searching from 'splitsh'. If 'splitseg'//
// is not NULL, p is on a segment, no search is needed.                      //
//                                                                           //
// If 'cflag' is not TRUE, the triangulation may be not convex. Don't insert //
// p if it is found in outside.                                              //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

enum tetgenmesh::location tetgenmesh::sinsertvertex(point insertpt, 
  face *splitsh, face *splitseg, bool bwflag, bool cflag)
{
  face *abfaces, *parysh, *pssub;
  face neighsh, newsh, casout, casin;
  face aseg, bseg, aoutseg, boutseg;
  face checkseg;
  triface neightet, spintet;
  point pa, pb, pc;
  enum location loc;
  REAL sign, ori, area;
  int n, s, i, j;

  tetrahedron ptr;
  shellface sptr;

  if (splitseg != NULL) {
    spivot(*splitseg, *splitsh);
    loc = ONEDGE;
  } else {
    assert(splitsh->sh != NULL); // SELF_CHECK
    loc = slocate(insertpt, splitsh, false);
  }

  // Return if p lies on a vertex.
  if (loc == ONVERTEX) return loc;

  if (loc == OUTSIDE) {
    // Return if 'cflag' is not set.
    if (!cflag) return loc;
  }

  if (loc == ONEDGE) {
    if (splitseg == NULL) {
      // Do not split a segment.
      sspivot(*splitsh, checkseg);
      if (checkseg.sh != NULL) return loc; // return ONSUBSEG;
      // Check if this edge is on the hull.
      spivot(*splitsh, neighsh);
      if (neighsh.sh == NULL) {
        // A convex hull edge. The new point is on the hull.
        loc = OUTSIDE;
      }
    }
  }

  if (b->verbose > 1) {
    pa = sorg(*splitsh);
    pb = sdest(*splitsh);
    pc = sapex(*splitsh);
    printf("    Insert point %d (%d, %d, %d) loc %d\n", pointmark(insertpt),
      pointmark(pa), pointmark(pb), pointmark(pc), (int) loc);
  }

  // Does 'insertpt' lie on a segment?
  if (splitseg != NULL) {
    splitseg->shver = 0;
    pa = sorg(*splitseg);
    // Count the number of faces at segment [a, b].
    n = 0;
    neighsh = *splitsh;
    do {
      spivotself(neighsh);
      n++;
    } while ((neighsh.sh != NULL) && (neighsh.sh != splitsh->sh));
    // n is at least 1.
    abfaces = new face[n];
    // Collect faces at seg [a, b].
    abfaces[0] = *splitsh;
    if (sorg(abfaces[0]) != pa) sesymself(abfaces[0]);
    for (i = 1; i < n; i++) {
      spivot(abfaces[i - 1], abfaces[i]);
      if (sorg(abfaces[i]) != pa) sesymself(abfaces[i]);
    }
  }

  // Initialize the cavity.
  if (loc == ONEDGE) {
    smarktest(*splitsh);
    caveshlist->newindex((void **) &parysh);
    *parysh = *splitsh;
    if (splitseg != NULL) {
      for (i = 1; i < n; i++) {
        smarktest(abfaces[i]);
        caveshlist->newindex((void **) &parysh);
        *parysh = abfaces[i];
      }
    } else {
      spivot(*splitsh, neighsh);
      if (neighsh.sh != NULL) {
        smarktest(neighsh);
        caveshlist->newindex((void **) &parysh);
        *parysh = neighsh;
      }
    }
  } else if (loc == ONFACE) {
    smarktest(*splitsh);
    caveshlist->newindex((void **) &parysh);
    *parysh = *splitsh;
  } else { // loc == OUTSIDE;
    // This is only possible when T is convex.
    assert(cflag); // SELF_CHECK
    // Assume p is on top of the edge ('splitsh'). Find a right-most edge
    //   which is visible by p.
    neighsh = *splitsh;
    while (1) {
      senext2self(neighsh);
      spivot(neighsh, casout);
      if (casout.sh == NULL) {
        // A convex hull edge. Is it visible by p.
        pa = sorg(neighsh);
        pb = sdest(neighsh);
        ori = orient3d(pa, pb, dummypoint, insertpt);
        if (ori < 0) {
          *splitsh = neighsh; // Update 'splitsh'.
        } else {
          break; // 'splitsh' is the right-most visible edge.
        }
      } else {
        if (sorg(casout) != sdest(neighsh)) sesymself(casout);
        neighsh = casout;
      }
    }
    // Create new triangles for all visible edges of p (from right to left).
    casin.sh = NULL;  // No adjacent face at right.
    pa = sorg(*splitsh);
    pb = sdest(*splitsh);
    while (1) {
      // Create a new subface on top of the (visible) edge.
      makeshellface(subfacepool, &newsh); 
      setshvertices(newsh, pb, pa, insertpt);
      setshellmark(newsh, getshellmark(*splitsh));
      if (checkconstraints) {
        area = areabound(*splitsh);
        areabound(newsh) = area;
      }
      // Connect the new subface to the bottom subfaces.
      sbond1(newsh, *splitsh);
      sbond1(*splitsh, newsh);
      // Connect the new subface to its right-adjacent subface.
      if (casin.sh != NULL) {
        senext(newsh, casout);
        sbond1(casout, casin);
        sbond1(casin, casout);
      }
      // The left-adjacent subface has not been created yet.
      senext2(newsh, casin);
      // Add the new face into list.
      smarktest(newsh);
      caveshlist->newindex((void **) &parysh);
      *parysh = newsh;
      // Move to the convex hull edge at the left of 'splitsh'.
      neighsh = *splitsh;
      while (1) {
        senextself(neighsh);
        spivot(neighsh, casout);
        if (casout.sh == NULL) {
          *splitsh = neighsh;
          break;
        }
        if (sorg(casout) != sdest(neighsh)) sesymself(casout);
        neighsh = casout;
      }
      // A convex hull edge. Is it visible by p.
      pa = sorg(*splitsh);
      pb = sdest(*splitsh);
      ori = orient3d(pa, pb, dummypoint, insertpt);
      if (ori >= 0) break;
    }
  }

  // Form the Bowyer-Watson cavity.
  for (i = 0; i < caveshlist->objects; i++) {
    parysh = (face *) fastlookup(caveshlist, i);
    for (j = 0; j < 3; j++) {
      sspivot(*parysh, checkseg);
      if (checkseg.sh == NULL) {
        spivot(*parysh, neighsh);
        if (neighsh.sh != NULL) {
          if (!smarktested(neighsh)) {
            if (bwflag) {
              pa = sorg(neighsh);
              pb = sdest(neighsh);
              pc = sapex(neighsh);
              sign = incircle3d(pa, pb, pc, insertpt);
              if (sign < 0) {
                smarktest(neighsh);
                caveshlist->newindex((void **) &pssub);
                *pssub = neighsh;
              }
            } else {
              sign = 1; // A boundary edge.
            }
          } else {
            sign = -1; // Not a boundary edge.
          }
        } else {
          if (loc == OUTSIDE) {
            // It is a boundary edge if it does not contain insertp.
            if ((sorg(*parysh)==insertpt) || (sdest(*parysh)==insertpt)) {
              sign = -1; // Not a boundary edge.
            } else {
              sign = 1; // A boundary edge.
            }
          } else {
            sign = 1; // A boundary edge.
          }
        }
      } else {
        sign = 1; // A segment!
      }
      if (sign >= 0) {
        // Add a boundary edge.
        caveshbdlist->newindex((void **) &pssub);
        *pssub = *parysh;
      }
      senextself(*parysh);
    }
  }

  // Creating new subfaces.
  for (i = 0; i < caveshbdlist->objects; i++) {
    parysh = (face *) fastlookup(caveshbdlist, i);
    sspivot(*parysh, checkseg);
    if ((parysh->shver & 01) != 0) sesymself(*parysh);
    pa = sorg(*parysh);
    pb = sdest(*parysh);
    // Create a new subface.
    makeshellface(subfacepool, &newsh); 
    setshvertices(newsh, pa, pb, insertpt);
    setshellmark(newsh, getshellmark(*parysh));
    if (checkconstraints) {
      area = areabound(*parysh);
      areabound(newsh) = area;
    }
    // Connect newsh to outer subfaces.
    spivot(*parysh, casout);
    if (casout.sh != NULL) {
      casin = casout;
      if (checkseg.sh != NULL) {
        spivot(casin, neighsh);
        while (neighsh.sh != parysh->sh) {
          casin = neighsh;
          spivot(casin, neighsh);
        }
      }
      sbond1(newsh, casout);
      sbond1(casin, newsh);
    }
    if (checkseg.sh != NULL) {
      ssbond(newsh, checkseg);
    }
    // Connect oldsh <== newsh (for connecting adjacent new subfaces).
    sbond1(*parysh, newsh);
  }

  // Set a handle for searching.
  recentsh = newsh;

  // Connect adjacent new subfaces together.
  for (i = 0; i < caveshbdlist->objects; i++) {
    // Get an old subface at edge [a, b].
    parysh = (face *) fastlookup(caveshbdlist, i);
    sspivot(*parysh, checkseg);
    spivot(*parysh, newsh); // The new subface [a, b, p].
    senextself(newsh); // At edge [b, p].
    spivot(newsh, neighsh);
    if (neighsh.sh == NULL) {
      // Find the adjacent new subface at edge [b, p].
      pb = sdest(*parysh);
      neighsh = *parysh;
      while (1) {
        senextself(neighsh);
        spivotself(neighsh);
        if (neighsh.sh == NULL) break;
        if (!smarktested(neighsh)) break;
        if (sdest(neighsh) != pb) sesymself(neighsh);
      }
      if (neighsh.sh != NULL) {
        // Now 'neighsh' is a new subface at edge [b, #].
        if (sorg(neighsh) != pb) sesymself(neighsh);
        assert(sorg(neighsh) == pb); // SELF_CHECK
        assert(sapex(neighsh) == insertpt); // SELF_CHECK
        senext2self(neighsh); // Go to the open edge [p, b].
        spivot(neighsh, casout); // SELF_CHECK
        assert(casout.sh == NULL); // SELF_CHECK
        sbond2(newsh, neighsh);
      } else {
        assert(loc == OUTSIDE); // SELF_CHECK
      }
    }
    spivot(*parysh, newsh); // The new subface [a, b, p].
    senext2self(newsh); // At edge [p, a].
    spivot(newsh, neighsh);
    if (neighsh.sh == NULL) {
      // Find the adjacent new subface at edge [p, a].
      pa = sorg(*parysh);
      neighsh = *parysh;
      while (1) {
        senext2self(neighsh);
        spivotself(neighsh);
        if (neighsh.sh == NULL) break;
        if (!smarktested(neighsh)) break;
        if (sorg(neighsh) != pa) sesymself(neighsh);
      }
      if (neighsh.sh != NULL) {
        // Now 'neighsh' is a new subface at edge [#, a].
        if (sdest(neighsh) != pa) sesymself(neighsh);
        assert(sdest(neighsh) == pa); // SELF_CHECK
        assert(sapex(neighsh) == insertpt); // SELF_CHECK
        senextself(neighsh); // Go to the open edge [a, p].
        spivot(neighsh, casout); // SELF_CHECK
        assert(casout.sh == NULL); // SELF_CHECK
        sbond2(newsh, neighsh);
      } else {
        assert(loc == OUTSIDE); // SELF_CHECK
      }
    }
  }

  if (checksubfaces) {
    // Add all new subfaces into list.
    for (i = 0; i < caveshbdlist->objects; i++) {
      // Get an old subface at edge [a, b].
      parysh = (face *) fastlookup(caveshbdlist, i);
      spivot(*parysh, newsh); // The new subface [a, b, p].
      if (b->verbose > 1) {
        printf("      Queue a new subface (%d, %d, %d).\n",
          pointmark(sorg(newsh)), pointmark(sdest(newsh)),
          pointmark(sapex(newsh)));
      }
      subfacstack->newindex((void **) &pssub);
      *pssub = newsh;
    }
  }

  if (splitseg != NULL) {
    // Split the segment [a, b].
    aseg = *splitseg;
    pa = sorg(aseg);
    pb = sdest(aseg);
    if (b->verbose > 1) {
      printf("    Split seg (%d, %d) by %d.\n", pointmark(pa), pointmark(pb), 
        pointmark(insertpt));
    }
    // Detach the adjacent tets from this segment.
    stpivot(aseg, neightet);
    if (neightet.tet != NULL) {
      // It should not be a dead tet.
      assert(neightet.tet[4] != NULL); // SELF_CHECK
      assert(((org(neightet) == pa) && (dest(neightet) == pb)) ||
             ((org(neightet) == pb) && (dest(neightet) == pa))); // SELF_CHECK
      spintet = neightet;
      while (1) {
        tssdissolve(spintet);
        fnextself(spintet);
        if (spintet.tet == neightet.tet) break;
      }
      // Clean the seg-to-tet pointer.
      stdissolve(aseg);
    }
    // Insert the new point p.
    makeshellface(subsegpool, &bseg);
    setshvertices(bseg, insertpt, pb, NULL);
    setsdest(aseg, insertpt);
    setshellmark(bseg, getshellmark(aseg));
    if (checkconstraints) {
      areabound(bseg) = areabound(aseg);
    }
    // Connect [p, b]<->[b, #].
    senext(aseg, aoutseg);
    spivotself(aoutseg);
    if (aoutseg.sh != NULL) {
      senext(bseg, boutseg);
      sbond2(boutseg, aoutseg);
    }
    // Connect [a, p] <-> [p, b].
    senext(aseg, aoutseg);
    senext2(bseg, boutseg);
    sbond2(aoutseg, boutseg);
    // Connect subsegs [a, p] and [p, b] to the true new subfaces.
    for (i = 0; i < n; i++) {
      spivot(abfaces[i], newsh); // The faked new subface.
      if (sorg(newsh) != pa) sesymself(newsh);
      senext2(newsh, neighsh); // The edge [p, a] in newsh
      spivot(neighsh, casout);
      ssbond(casout, aseg);
      senext(newsh, neighsh); // The edge [b, p] in newsh
      spivot(neighsh, casout);
      ssbond(casout, bseg);
    }
    if (n > 1) {
      // Create the two face rings at [a, p] and [p, b].
      for (i = 0; i < n; i++) {
        spivot(abfaces[i], newsh); // The faked new subface.
        if (sorg(newsh) != pa) sesymself(newsh);
        spivot(abfaces[(i + 1) % n], neighsh); // The next faked new subface.
        if (sorg(neighsh) != pa) sesymself(neighsh);
        senext2(newsh, casout); // The edge [p, a] in newsh.
        senext2(neighsh, casin); // The edge [p, a] in neighsh.
        spivotself(casout);
        spivotself(casin);
        sbond1(casout, casin); // Let the i's face point to (i+1)'s face.
        senext(newsh, casout); // The edge [b, p] in newsh.
        senext(neighsh, casin); // The edge [b, p] in neighsh.
        spivotself(casout);
        spivotself(casin);
        sbond1(casout, casin);
      }
    } else { 
      // Only one subface contains this segment.
      // assert(n == 1);
      spivot(abfaces[0], newsh);  // The faked new subface.
      if (sorg(newsh) != pa) sesymself(newsh);
      senext2(newsh, casout); // The edge [p, a] in newsh.
      spivotself(casout);
      sdissolve(casout); // Disconnect to faked subface.
      senext(newsh, casout); // The edge [b, p] in newsh.
      spivotself(casout);
      sdissolve(casout); // Disconnect to faked subface.
    }
    // Delete the faked new subfaces.
    for (i = 0; i < n; i++) {
      spivot(abfaces[i], newsh); // The faked new subface.
      shellfacedealloc(subfacepool, newsh.sh);
    }
    if (checksubsegs) {
      // Add two subsegs into stack (for recovery).
      if (!sinfected(aseg)) {
        s = randomnation(subsegstack->objects + 1);
        subsegstack->newindex((void **) &parysh);
        *parysh = * (face *) fastlookup(subsegstack, s);
        sinfect(aseg); 
        parysh = (face *) fastlookup(subsegstack, s);
        *parysh = aseg;
      }
      assert(!sinfected(bseg)); // SELF_CHECK
      s = randomnation(subsegstack->objects + 1);
      subsegstack->newindex((void **) &parysh);
      *parysh = * (face *) fastlookup(subsegstack, s);
      sinfect(bseg);
      parysh = (face *) fastlookup(subsegstack, s);
      *parysh = bseg;
    }
    delete [] abfaces;
  }

  // Delete the old subfaces.
  for (i = 0; i < caveshlist->objects; i++) {
    parysh = (face *) fastlookup(caveshlist, i);
    if (checksubfaces) {		 
      // Disconnect in the neighbor tets.		 
      stpivot(*parysh, neightet);		 
      if (neightet.tet != NULL) {		 
        tsdissolve(neightet);		 
        symself(neightet);		 
        tsdissolve(neightet);		 
      }		 
    }
    shellfacedealloc(subfacepool, parysh->sh);
  }

  // Clean the working lists.
  caveshlist->restart();
  caveshbdlist->restart();

  return loc;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// sscoutsegment()    Look for a segment in surface triangulation.           //
//                                                                           //
// The segment is given by the origin of 'searchsh' and 'endpt'.  Assume the //
// orientation of 'searchsh' is CCW w.r.t. the above point.                  //
//                                                                           //
// If an edge in T is found matching this segment, the segment is "locaked"  //
// in T at the edge.  Otherwise, flip the first edge in T that the segment   //
// crosses. Continue the search from the flipped face.                       //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

enum tetgenmesh::intersection tetgenmesh::sscoutsegment(face *searchsh,
  point endpt)
{
  face flipshs[2], neighsh;
  face newseg, checkseg;
  point startpt, pa, pb, pc, pd;
  enum intersection dir;
  REAL ori_ab, ori_ca;
  REAL dist_b, dist_c;

  enum {MOVE_AB, MOVE_CA} nextmove;

  shellface sptr;

  // The origin of 'searchsh' is fixed.
  startpt = sorg(*searchsh); // pa = startpt;

  if (b->verbose > 1) {
    printf("    Scout segment (%d, %d).\n", pointmark(startpt),
      pointmark(endpt));
  }

  // Search an edge in 'searchsh' on the path of this segment.
  while (1) {

    pb = sdest(*searchsh);
    if (pb == endpt) {
      dir = SHAREEDGE; // Found!
      break;
    }

    pc = sapex(*searchsh);
    if (pc == endpt) {
      senext2self(*searchsh);
      sesymself(*searchsh);
      dir = SHAREEDGE; // Found!
      break;
    }

    ori_ab = orient3d(startpt, pb, dummypoint, endpt);
    ori_ca = orient3d(pc, startpt, dummypoint, endpt);

    if (ori_ab < 0) {
      if (ori_ca < 0) { // (--)
        // Both sides are viable moves.
        spivot(*searchsh, neighsh); // At edge [a, b].
        assert(neighsh.sh != NULL); // SELF_CHECK
        pd = sapex(neighsh);
        dist_b = NORM2(endpt[0] - pd[0], endpt[1] - pd[1], endpt[2] - pd[2]);
        senext2(*searchsh, neighsh); // At edge [c, a].
        spivotself(neighsh);
        assert(neighsh.sh != NULL); // SELF_CHECK
        pd = sapex(neighsh);
        dist_c = NORM2(endpt[0] - pd[0], endpt[1] - pd[1], endpt[2] - pd[2]);
        if (dist_c < dist_b) {
          nextmove = MOVE_CA;
        } else {
          nextmove = MOVE_AB;
        }
      } else { // (-#)
        nextmove = MOVE_AB;
      }
    } else {
      if (ori_ca < 0) { // (#-)
        nextmove = MOVE_CA;
      } else {
        if (ori_ab > 0) {
          if (ori_ca > 0) { // (++)
            // The segment intersects with edge [b, c].
            dir = ACROSSEDGE;
            break;
          } else { // (+0)
            // The segment collinear with edge [c, a].
            senext2self(*searchsh);
            sesymself(*searchsh);
            dir = ACROSSVERT;
            break;
          }
        } else {
          if (ori_ca > 0) { // (0+)
            // The segment collinear with edge [a, b].
            dir = ACROSSVERT;
            break;
          } else { // (00)
            // startpt == endpt. Not possible.
            assert(0); // SELF_CHECK
          }
        }
      }
    }

    // Move 'searchsh' to the next face, keep the origin unchanged.
    if (nextmove == MOVE_AB) {
      spivot(*searchsh, neighsh);
      if (sorg(neighsh) != pb) sesymself(neighsh);
      senext(neighsh, *searchsh);      
    } else {
      senext2(*searchsh, neighsh);
      spivotself(neighsh);
      if (sdest(neighsh) != pc) sesymself(neighsh);
      *searchsh = neighsh;
    }
    assert(sorg(*searchsh) == startpt); // SELF_CHECK

  } // while

  if (dir == SHAREEDGE) {
    // Insert the segment into the triangulation.
    makeshellface(subsegpool, &newseg);
    setshvertices(newseg, startpt, endpt, NULL);
    ssbond(*searchsh, newseg);
    spivot(*searchsh, neighsh);
    if (neighsh.sh != NULL) {
      ssbond(neighsh, newseg);
    }
    return dir;
  }

  if (dir == ACROSSVERT) {
    // A point is found collinear with this segment.
    return dir;
  }

  if (dir == ACROSSEDGE) {
    // Edge [b, c] intersects with the segment.
    senext(*searchsh, flipshs[0]);
    sspivot(flipshs[0], checkseg);
    if (checkseg.sh != NULL) {
      printf("Error:  Invalid PLC.\n");
      pb = sorg(flipshs[0]);
      pc = sdest(flipshs[0]);
      printf("  Two segments (%d, %d) and (%d, %d) intersect.\n",
        pointmark(startpt), pointmark(endpt), pointmark(pb), pointmark(pc));
      terminatetetgen(2);
    }
    // Flip edge [b, c], queue unflipped edges (for Delaunay checks).
    spivot(flipshs[0], flipshs[1]);
    assert(flipshs[1].sh != NULL); // SELF_CHECK
    if (sorg(flipshs[1]) != sdest(flipshs[0])) sesymself(flipshs[1]);
    flip22(flipshs, 1);
    // The flip may create an invered triangle, check it.
    pa = sapex(flipshs[1]);
    pb = sapex(flipshs[0]);
    pc = sorg(flipshs[0]);
    pd = sdest(flipshs[0]);
    // Check if pa and pb are on the different sides of [pc, pd]. 
    // Re-use ori_ab, ori_ca for the tests.
    ori_ab = orient3d(pc, pd, dummypoint, pb);
    ori_ca = orient3d(pd, pc, dummypoint, pa);
    assert(ori_ab * ori_ca != 0); // SELF_CHECK
    if (ori_ab < 0) {
      if (b->verbose > 1) {
        printf("    Queue an inversed triangle (%d, %d, %d) %d\n",
          pointmark(pc), pointmark(pd), pointmark(pb), pointmark(pa));
      }
      futureflip = flipshpush(futureflip, &flipshs[0]);
    } else if (ori_ca < 0) {
      if (b->verbose > 1) {
        printf("    Queue an inversed triangle (%d, %d, %d) %d\n",
          pointmark(pd), pointmark(pc), pointmark(pa), pointmark(pb));
      }
      futureflip = flipshpush(futureflip, &flipshs[1]);
    }
    // Set 'searchsh' s.t. its origin is 'startpt'.
    *searchsh = flipshs[0];
    assert(sorg(*searchsh) == startpt);
  }

  return sscoutsegment(searchsh, endpt);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// scarveholes()    Remove triangles not in the facet.                       //
//                                                                           //
// This routine re-uses the two global arrays: caveshlist and caveshbdlist.  //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::scarveholes(int holes, REAL* holelist)
{
  face *parysh, searchsh, neighsh;
  face checkseg;
  enum location loc;
  int i, j;

  // Get all triangles. Infect unprotected convex hull triangles. 
  smarktest(recentsh);
  caveshlist->newindex((void **) &parysh);
  *parysh = recentsh;
  for (i = 0; i < caveshlist->objects; i++) {
    parysh = (face *) fastlookup(caveshlist, i);
    searchsh = *parysh;
    searchsh.shver = 0;
    for (j = 0; j < 3; j++) {
      spivot(searchsh, neighsh);
      // Is this side on the convex hull?
      if (neighsh.sh != NULL) {
        if (!smarktested(neighsh)) {
          smarktest(neighsh);
          caveshlist->newindex((void **) &parysh);
          *parysh = neighsh;
        }
      } else {
        // A hull side. Check if it is protected by a segment.
        sspivot(searchsh, checkseg);
        if (checkseg.sh == NULL) {
          // Not protected. Save this face.
          if (!sinfected(searchsh)) {
            sinfect(searchsh);
            caveshbdlist->newindex((void **) &parysh);
            *parysh = searchsh;
          }
        }
      }
      senextself(searchsh);
    }
  }

  // Infect the triangles in the holes.
  for (i = 0; i < 3 * holes; i += 3) {
    searchsh = recentsh;
    loc = slocate(&(holelist[i]), &searchsh, true);
    if (loc != OUTSIDE) {
      sinfect(searchsh);
      caveshbdlist->newindex((void **) &parysh);
      *parysh = searchsh;
    }
  }

  // Find and infect all exterior triangles.
  for (i = 0; i < caveshbdlist->objects; i++) {
    parysh = (face *) fastlookup(caveshbdlist, i);
    searchsh = *parysh;
    searchsh.shver = 0;
    for (j = 0; j < 3; j++) {
      spivot(searchsh, neighsh);
      if (neighsh.sh != NULL) {
        sspivot(searchsh, checkseg);
        if (checkseg.sh == NULL) {
          if (!sinfected(neighsh)) {
            sinfect(neighsh);
            caveshbdlist->newindex((void **) &parysh);
            *parysh = neighsh;
          }
        } else {
          sdissolve(neighsh); // Disconnect a protected face.
        }
      }
      senextself(searchsh);
    }
  }

  // Delete exterior triangles, unmark interior triangles.
  for (i = 0; i < caveshlist->objects; i++) {
    parysh = (face *) fastlookup(caveshlist, i);
    if (sinfected(*parysh)) {
      shellfacedealloc(subfacepool, parysh->sh);
    } else {
      sunmarktest(*parysh);
    }
  }

  caveshlist->restart();
  caveshbdlist->restart();
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// triangulate()    Create a CDT for the facet.                              //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::triangulate(int shmark, arraypool* ptlist, arraypool* conlist,
  int holes, REAL* holelist)
{
  face searchsh, newsh; 
  face newseg;
  point pa, pb, pc, *ppt, *cons;
  enum location loc;
  int i;

  if (b->verbose > 1) {
    printf("    %ld vertices, %ld segments",ptlist->objects,conlist->objects);
    if (holes > 0) {
      printf(", %d holes", holes);
    }
    printf(", shmark: %d.\n", shmark);
  }

  if (ptlist->objects < 3l) {
    return; // No enough points. Do nothing.
  }
  if (conlist->objects < 3l) {
    return; // No enough segments. Do nothing.
  }

  if (ptlist->objects == 3l) {
    // The facet has only one triangle.
    pa = * (point *) fastlookup(ptlist, 0);
    pb = * (point *) fastlookup(ptlist, 1);
    pc = * (point *) fastlookup(ptlist, 2);
    makeshellface(subfacepool, &newsh);
    setshvertices(newsh, pa, pb, pc);
    setshellmark(newsh, shmark);
    // Create three new segments.
    for (i = 0; i < 3; i++) {
      makeshellface(subsegpool, &newseg);
      setshvertices(newseg, sorg(newsh), sdest(newsh), NULL);
      ssbond(newsh, newseg);
      senextself(newsh);
    }
    if (getpointtype(pa) == VOLVERTEX) {
      setpointtype(pa, FACETVERTEX);
    }
    if (getpointtype(pb) == VOLVERTEX) {
      setpointtype(pb, FACETVERTEX);
    }
    if (getpointtype(pc) == VOLVERTEX) {
      setpointtype(pc, FACETVERTEX);
    }
    return;
  }

  // Calulcate an above point of this facet.
  if (!calculateabovepoint(ptlist, &pa, &pb, &pc)) {
    return; // The point set is degenerate.
  }

  // Create an initial triangulation.
  makeshellface(subfacepool, &newsh);
  setshvertices(newsh, pa, pb, pc);
  setshellmark(newsh, shmark);
  recentsh = newsh;

  if (getpointtype(pa) == VOLVERTEX) {
    setpointtype(pa, FACETVERTEX);
  }
  if (getpointtype(pb) == VOLVERTEX) {
    setpointtype(pb, FACETVERTEX);
  }
  if (getpointtype(pc) == VOLVERTEX) {
    setpointtype(pc, FACETVERTEX);
  }

  // Incrementally build the triangulation.
  pinfect(pa);
  pinfect(pb);
  pinfect(pc);
  for (i = 0; i < ptlist->objects; i++) {
    ppt = (point *) fastlookup(ptlist, i);
    if (!pinfected(*ppt)) {
      searchsh = recentsh;
      loc = sinsertvertex(*ppt, &searchsh, NULL, true, true);
      if (getpointtype(*ppt) == VOLVERTEX) {
        setpointtype(*ppt, FACETVERTEX);
      }
    } else {
      puninfect(*ppt); // This point has inserted.
    }
  }

  // Insert the segments.
  for (i = 0; i < conlist->objects; i++) {
    cons = (point *) fastlookup(conlist, i);
    searchsh = recentsh;
    loc = slocate(cons[0], &searchsh, true);
    assert(loc == ONVERTEX); // SELF_CHECK
    // Recover the segment. Some edges may be flipped.
    sscoutsegment(&searchsh, cons[1]);
    if (futureflip != NULL) {
      // Recover locally Delaunay edges.
      lawsonflip();
    }
  }

  // Remove exterior and hole triangles.
  scarveholes(holes, holelist);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// unifysubfaces()    Unify two identical subfaces.                          //
//                                                                           //
// Two subfaces, f1 [a, b, c] and f2 [a, b, d], share the same edge [a, b].  //
// If c = d, then f1 and f2 are identical. In such case, f2 is deleted, all  //
// connections to f2 are re-directed to f1.  Otherwise, these two subfaces   //
// intersect, and the mesher is stopped.                                     //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::unifysubfaces(face *f1, face *f2)
{
  face casout, casin, neighsh;
  face sseg, checkseg;
  point pa, pb, pc, pd;
  int i;

  assert(f1->sh != f2->sh); // SELF_CHECK

  pa = sorg(*f1);
  pb = sdest(*f1);
  pc = sapex(*f1);

  assert(sorg(*f2) == pa); // SELF_CHECK
  assert(sdest(*f2) == pb); // SELF_CHECK
  pd = sapex(*f2);

  if (pc != pd) {
    printf("Error:  Invalid PLC! Two coplanar subfaces intersect.\n");
    printf("  1st (#%4d): (%d, %d, %d)\n", getshellmark(*f1),
      pointmark(pa), pointmark(pb), pointmark(pc));
    printf("  2nd (#%4d): (%d, %d, %d)\n", getshellmark(*f2),
      pointmark(pa), pointmark(pb), pointmark(pd));
    terminatetetgen(2);
  }

  // f1 and f2 are identical, replace f2 by f1.
  if (!b->quiet) {
    printf("Warning:  Facet #%d is duplicated with Facet #%d. Removed!\n",
      getshellmark(*f2), getshellmark(*f1));
  }

  // Make possible disconnections/reconnections at neighbors of f2.
  for (i = 0; i < 3; i++) {
    spivot(*f1, casout);
    if (casout.sh == NULL) {
      // f1 has no adjacent subfaces yet.
      spivot(*f2, casout);
      if (casout.sh != NULL) {
        // Re-direct the adjacent connections of f2 to f1.
        casin = casout;
        spivot(casin, neighsh);
        while (neighsh.sh != f2->sh) {
          casin = neighsh;
          spivot(casin, neighsh);
        }
        // Connect casout <= f1 <= casin.
        sbond1(*f1, casout);
        sbond1(casin, *f1);
      }
    }
    sspivot(*f2, sseg); 
    if (sseg.sh != NULL) {
      // f2 has a segment. It must be different to f1's.
      sspivot(*f1, checkseg); // SELF_CHECK
      if (checkseg.sh != NULL) { // SELF_CHECK
        assert(checkseg.sh != sseg.sh); // SELF_CHECK
      }
      // Disconnect bonds of subfaces to this segment.
      spivot(*f2, casout);
      if (casout.sh != NULL) {
        casin = casout;
        ssdissolve(casin);
        spivot(casin, neighsh);
        while (neighsh.sh != f2->sh) {
          casin = neighsh;
          ssdissolve(casin);
          spivot(casin, neighsh);
        }
      }
      // Delete the segment.
      shellfacedealloc(subsegpool, sseg.sh);
    }
    spivot(*f2, casout);
    if (casout.sh != NULL) {
      // Find the subface (casin) pointing to f2.
      casin = casout;
      spivot(casin, neighsh);
      while (neighsh.sh != f2->sh) {
        casin = neighsh;
        spivot(casin, neighsh);
      }
      // Disconnect f2 <= casin.
      sdissolve(casin);
    }
    senextself(*f1);
    senextself(*f2);
  } // i

  // Delete f2.
  shellfacedealloc(subfacepool, f2->sh);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// unifysegments()    Remove redundant segments and create face links.       //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::unifysegments()
{
  badface *facelink, *newlinkitem, *f1, *f2;
  face *facperverlist, sface;
  face subsegloop, testseg;
  point torg, tdest;
  REAL ori1, ori2, ori3;
  REAL n1[3], n2[3];
  int *idx2faclist;
  int segmarker;
  int idx, k, m;

  if (b->verbose > 1) {
    printf("  Unifying segments.\n");
  }

  // Create a mapping from vertices to subfaces.
  makepoint2submap(subfacepool, idx2faclist, facperverlist);

  segmarker = 1;
  subsegloop.shver = 0;
  subsegpool->traversalinit();
  subsegloop.sh = shellfacetraverse(subsegpool);
  while (subsegloop.sh != (shellface *) NULL) {
    torg = sorg(subsegloop);
    tdest = sdest(subsegloop);

    idx = pointmark(torg) - in->firstnumber;
    // Loop through the set of subfaces containing 'torg'.  Get all the
    //   subfaces containing the edge (torg, tdest). Save and order them
    //   in 'sfacelist', the ordering is defined by the right-hand rule
    //   with thumb points from torg to tdest.
    for (k = idx2faclist[idx]; k < idx2faclist[idx + 1]; k++) {
      sface = facperverlist[k];
      // The face may be deleted if it is a duplicated face.
      if (sface.sh[3] == NULL) continue;
      // Search the edge torg->tdest.
      assert(sorg(sface) == torg); // SELF_CHECK
      if (sdest(sface) != tdest) {
        senext2self(sface);
        sesymself(sface);
      }
      if (sdest(sface) != tdest) continue;

      // Save the face f in facelink.
      if (flippool->items >= 2) {
        f1 = facelink;
        for (m = 0; m < flippool->items - 1; m++) {
          f2 = f1->nextitem;
          ori1 = orient3d(torg, tdest, sapex(f1->ss), sapex(f2->ss));
          ori2 = orient3d(torg, tdest, sapex(f1->ss), sapex(sface));
          if (ori1 > 0) {
            // apex(f2) is below f1.
            if (ori2 > 0) {
              // apex(f) is below f1 (see Fig.1). 
              ori3 = orient3d(torg, tdest, sapex(f2->ss), sapex(sface));
              if (ori3 > 0) {
                // apex(f) is below f2, insert it.
                break; 
              } else if (ori3 < 0) {
                // apex(f) is above f2, continue.
              } else { // ori3 == 0; 
                // f is coplanar and codirection with f2.
                unifysubfaces(&(f2->ss), &sface);
                break;
              }
            } else if (ori2 < 0) {
              // apex(f) is above f1 below f2, inset it (see Fig. 2).
              break;
            } else { // ori2 == 0;
              // apex(f) is coplanar with f1 (see Fig. 5).
              ori3 = orient3d(torg, tdest, sapex(f2->ss), sapex(sface));
              if (ori3 > 0) {
                // apex(f) is below f2, insert it.
                break; 
              } else {
                // f is coplanar and codirection with f1.
                unifysubfaces(&(f1->ss), &sface);
                break;
              }
            }
          } else if (ori1 < 0) {
            // apex(f2) is above f1.
            if (ori2 > 0) {
              // apex(f) is below f1, continue (see Fig. 3).
            } else if (ori2 < 0) {
              // apex(f) is above f1 (see Fig.4).
              ori3 = orient3d(torg, tdest, sapex(f2->ss), sapex(sface));
              if (ori3 > 0) {
                // apex(f) is below f2, insert it.
                break;
              } else if (ori3 < 0) {
                // apex(f) is above f2, continue.
              } else { // ori3 == 0;
                // f is coplanar and codirection with f2.
                unifysubfaces(&(f2->ss), &sface);
                break;
              }
            } else { // ori2 == 0;
              // f is coplanar and with f1 (see Fig. 6).
              ori3 = orient3d(torg, tdest, sapex(f2->ss), sapex(sface));
              if (ori3 > 0) {
                // f is also codirection with f1.
                unifysubfaces(&(f1->ss), &sface);
                break;
              } else {
                // f is above f2, continue.
              }
            }
          } else { // ori1 == 0;
            // apex(f2) is coplanar with f1. By assumption, f1 is not
            //   coplanar and codirection with f2.
            if (ori2 > 0) {
              // apex(f) is below f1, continue (see Fig. 7).
            } else if (ori2 < 0) {
              // apex(f) is above f1, insert it (see Fig. 7).
              break;
            } else { // ori2 == 0.
              // apex(f) is coplanar with f1 (see Fig. 8).
              // f is either codirection with f1 or is codirection with f2. 
              facenormal(torg, tdest, sapex(f1->ss), n1, 1);
              facenormal(torg, tdest, sapex(sface), n2, 1);
              if (DOT(n1, n2) > 0) {
                unifysubfaces(&(f1->ss), &sface);
              } else {
                unifysubfaces(&(f2->ss), &sface);
              }
              break;
            }
          }
          // Go to the next item;
          f1 = f2;
        } // for (m = 0; ...)
        if (sface.sh[3] != NULL) {
          // Insert sface between f1 and f2.
          newlinkitem = (badface *) flippool->alloc();
          newlinkitem->ss = sface;
          newlinkitem->nextitem = f1->nextitem;
          f1->nextitem = newlinkitem;
        }
      } else if (flippool->items == 1) {
        f1 = facelink;
        // Make sure that f is not coplanar and codirection with f1.
        ori1 = orient3d(torg, tdest, sapex(f1->ss), sapex(sface));
        if (ori1 == 0) {
          // f is coplanar with f1 (see Fig. 8).
          facenormal(torg, tdest, sapex(f1->ss), n1, 1);
          facenormal(torg, tdest, sapex(sface), n2, 1);
          if (DOT(n1, n2) > 0) {
            // The two faces are codirectional as well.
            unifysubfaces(&(f1->ss), &sface);
          }
        }
        // Add this face to link if it is not deleted.
        if (sface.sh[3] != NULL) {
          // Add this face into link.
          newlinkitem = (badface *) flippool->alloc();
          newlinkitem->ss = sface;
          newlinkitem->nextitem = NULL;
          f1->nextitem = newlinkitem;
        }
      } else {
        // The first face.
        newlinkitem = (badface *) flippool->alloc();
        newlinkitem->ss = sface;
        newlinkitem->nextitem = NULL;
        facelink = newlinkitem;
      }
    } // for (k = idx2faclist[idx]; ...)

    if (b->verbose > 1) {
      printf("    Found %ld segments at (%d  %d).\n", flippool->items,
             pointmark(torg), pointmark(tdest));
    }

    // Set the connection between this segment and faces containing it,
    //   at the same time, remove redundant segments.
    f1 = facelink;
    for (k = 0; k < flippool->items; k++) {
      sspivot(f1->ss, testseg);
      // If 'testseg' is not 'subsegloop' and is not dead, it is redundant.
      if ((testseg.sh != subsegloop.sh) && (testseg.sh[3] != NULL)) {
        shellfacedealloc(subsegpool, testseg.sh);
      }
      // Bonds the subface and the segment together.
      ssbond(f1->ss, subsegloop);
      f1 = f1->nextitem;
    }

    // Create the face ring at the segment.
    if (flippool->items > 1) {
      f1 = facelink;
      for (k = 1; k <= flippool->items; k++) {
        k < flippool->items ? f2 = f1->nextitem : f2 = facelink;
        if (b->verbose > 2) {
          printf("    Bond subfaces (%d, %d, %d) and (%d, %d, %d).\n",
                 pointmark(torg), pointmark(tdest), pointmark(sapex(f1->ss)),
                 pointmark(torg), pointmark(tdest), pointmark(sapex(f2->ss)));
        }
        sbond1(f1->ss, f2->ss);
        f1 = f2;
      }
    }

    // Set the unique segment marker into the unified segment.
    setshellmark(subsegloop, segmarker);
    segmarker++;
    flippool->restart();

    subsegloop.sh = shellfacetraverse(subsegpool);
  }

  delete [] idx2faclist;
  delete [] facperverlist;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// mergefacets()    Merge adjacent coplanar facets.                          //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::mergefacets()
{
  arraypool *ptlist;
  face parentsh, neighsh, neineighsh;
  face segloop;
  point eorg, edest, *parypt;
  REAL ori, ori1, ori2;
  bool mergeflag, aboveflag;
  int* segspernodelist;
  int fidx1, fidx2;
  int i, j;

  if (b->verbose > 1) {
    printf("  Merging adjacent coplanar facets.\n");
  }

  // Initialize 'segspernodelist'.
  segspernodelist = new int[pointpool->items + 1];
  for (i = 0; i < pointpool->items + 1; i++) segspernodelist[i] = 0;

  // Allocate a list for calculate an above point.
  ptlist = new arraypool(sizeof(point *), 4);

  // Loop all segments, counter the number of segments sharing each vertex.
  subsegpool->traversalinit();
  segloop.sh = shellfacetraverse(subsegpool);
  while (segloop.sh != (shellface *) NULL) {
    // Increment the number of sharing segments for each endpoint.
    for (i = 0; i < 2; i++) {
      j = pointmark((point) segloop.sh[3 + i]);
      segspernodelist[j]++;
    }
    segloop.sh = shellfacetraverse(subsegpool);
  }

  // Loop all segments, merge adjacent coplanar facets.
  subsegpool->traversalinit();
  segloop.sh = shellfacetraverse(subsegpool);
  while (segloop.sh != (shellface *) NULL) {
    eorg = sorg(segloop);
    edest = sdest(segloop);
    spivot(segloop, parentsh);
    spivot(parentsh, neighsh);
    if (neighsh.sh != NULL) {
      spivot(neighsh, neineighsh);
      if (parentsh.sh == neineighsh.sh) {
        // Exactly two subfaces at this segment.
        fidx1 = getshellmark(parentsh) - 1;
        fidx2 = getshellmark(neighsh) - 1;
        // Possible to merge them if they are not in the same facet.
        if (fidx1 != fidx2) {
          // Test if they are coplanar wrt the tolerance.
          ori = orient3d(eorg, edest, sapex(parentsh), sapex(neighsh));
          if ((ori == 0) || iscoplanar(eorg, edest, sapex(parentsh),
            sapex(neighsh), ori)) {
            // Found two adjacent coplanar facets.
            // Only can remove the segment if both apexes are on the 
            //   different sides of the edge [eorg, edest].
            ptlist->newindex((void **) &parypt);
            *parypt = eorg;
            ptlist->newindex((void **) &parypt);
            *parypt = edest;
            ptlist->newindex((void **) &parypt);
            *parypt = sapex(parentsh);
            ptlist->newindex((void **) &parypt);
            *parypt = sapex(neighsh);
            aboveflag = calculateabovepoint(ptlist, NULL, NULL, NULL);
            if (aboveflag) {
              ori1 = orient3d(eorg, edest, dummypoint, sapex(parentsh));
              ori2 = orient3d(eorg, edest, dummypoint, sapex(neighsh));
            } else {
              ori1 = ori2 = 1.0; // Bad data.
            }
            if (ori1 * ori2 < 0) {
              mergeflag = ((in->facetmarkerlist == NULL) || 
                (in->facetmarkerlist[fidx1] == in->facetmarkerlist[fidx2]));
              if (mergeflag) {
                if (b->verbose > 1) {
                  printf("  Removing segment (%d, %d).\n", pointmark(eorg),
                         pointmark(edest));
                }
                ssdissolve(parentsh);
                ssdissolve(neighsh);
                shellfacedealloc(subsegpool, segloop.sh);
                j = pointmark(eorg);
                segspernodelist[j]--;
                if (segspernodelist[j] == 0) {
                  setpointtype(eorg, FACETVERTEX);
                }
                j = pointmark(edest);
                segspernodelist[j]--;
                if (segspernodelist[j] == 0) {
                  setpointtype(edest, FACETVERTEX);
                }
                // Add the edge to flip stack.
                futureflip = flipshpush(futureflip, &parentsh);
              }
            }
            ptlist->restart(); // For the next test.
          }
        }
      }
    } // if (neighsh.sh != NULL)
    segloop.sh = shellfacetraverse(subsegpool);
  }

  if (futureflip != NULL) {
    // Do Delaunay flip.
    lawsonflip();
  }

  delete ptlist;
  delete [] segspernodelist;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// markacutevertices()    Classify vertices as ACUTEVERTEXs or RIDGEVERTEXs. //
//                                                                           //
// Initially, all segment vertices are marked as VOLVERTEX (after calling    //
// incrementaldelaunay()).                                                   //
//                                                                           //
// A segment vertex is ACUTEVERTEX if it two segments incident it form an    //
// interior angle less than 60 degree, otherwise, it is a RIDGEVERTEX.       //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::markacutevertices()
{
  point pa, pb, pc;
  REAL anglimit, ang;
  bool acuteflag;
  int acutecount;
  int idx, i, j;

  face* segperverlist;
  int* idx2seglist;

  if (b->verbose) {
    printf("  Marking acute vertices.\n");
  }

  // Construct a map from points to segments.
  makepoint2submap(subsegpool, idx2seglist, segperverlist);

  anglimit = PI / 3.0;  // 60 degree.
  acutecount = 0;

  // Loop over the set of vertices.
  pointpool->traversalinit();
  pa = pointtraverse();
  while (pa != NULL) {
    idx = pointmark(pa) - in->firstnumber;
    // Mark it if it is an endpoint of some segments.
    if (idx2seglist[idx + 1] > idx2seglist[idx]) {
      acuteflag = false;
      // Do a brute-force pair-pair check.
      for (i = idx2seglist[idx]; i < idx2seglist[idx + 1] && !acuteflag; i++) {
        pb = sdest(segperverlist[i]);
        for (j = i + 1; j < idx2seglist[idx + 1] && !acuteflag; j++) {
          pc = sdest(segperverlist[j]);
          ang = interiorangle(pa, pb, pc, NULL);
          acuteflag = ang < anglimit;
        }
      }
      // Now mark the vertex.
      if (b->verbose > 1) {
        printf("    Mark %d as %s.\n", pointmark(pa), acuteflag ?
          "ACUTEVERTEX" : "RIDGEVERTEX");
      }
      setpointtype(pa, acuteflag ? ACUTEVERTEX : RIDGEVERTEX);
      acutecount += (acuteflag ? 1 : 0);
    }
    pa = pointtraverse();
  }

  if (b->verbose) {
    printf("  %d acute vertices.\n", acutecount);
  }

  delete [] idx2seglist;
  delete [] segperverlist;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// meshsurface()    Create a surface mesh of the input PLC.                  //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::meshsurface()
{
  arraypool *ptlist, *conlist;
  point *idx2verlist;
  point tstart, tend, *pnewpt, *cons;
  tetgenio::facet *f;
  tetgenio::polygon *p;
  int end1, end2;
  int shmark, i, j;

  if (!b->quiet) {
    printf("Creating surface mesh.\n");
  }

  // Create a map from indices to points.
  makeindex2pointmap(idx2verlist);

  // Initialize arrays (block size: 2^8 = 256).
  ptlist = new arraypool(sizeof(point *), 8);
  conlist = new arraypool(2 * sizeof(point *), 8);

  // Loop the facet list, triangulate each facet.
  for (shmark = 1; shmark <= in->numberoffacets; shmark++) {

    // Get a facet F.
    f = &in->facetlist[shmark - 1];

    // Process the duplicated points first, they are marked with type
    //   DUPLICATEDVERTEX.  If p and q are duplicated, and p'index > q's,
    //   then p is substituted by q.
    if (dupverts > 0l) {
      // Loop all polygons of this facet.
      for (i = 0; i < f->numberofpolygons; i++) {
        p = &(f->polygonlist[i]);
        // Loop other vertices of this polygon.
        for (j = 0; j < p->numberofvertices; j++) {
          end1 = p->vertexlist[j];
          tstart = idx2verlist[end1];
          if (getpointtype(tstart) == DUPLICATEDVERTEX) {
            // Reset the index of vertex-j.
            tend = point2ppt(tstart);
            end2 = pointmark(tend);
            p->vertexlist[j] = end2;
          }
        }
      }
    }

    // Loop polygons of F, get the set of vertices and segments.
    for (i = 0; i < f->numberofpolygons; i++) {
      // Get a polygon.
      p = &(f->polygonlist[i]);
      // Get the first vertex.
      end1 = p->vertexlist[0];
      if ((end1 < in->firstnumber) || 
          (end1 >= in->firstnumber + in->numberofpoints)) {
        if (!b->quiet) {
          printf("Warning:  Invalid the 1st vertex %d of polygon", end1);
          printf(" %d in facet %d.\n", i + 1, shmark);
        }
        continue; // Skip this polygon.
      }
      tstart = idx2verlist[end1];
      // Add tstart to V if it haven't been added yet.
      if (!pinfected(tstart)) {
        pinfect(tstart);
        ptlist->newindex((void **) &pnewpt);
        *pnewpt = tstart;
      }
      // Loop other vertices of this polygon.
      for (j = 1; j <= p->numberofvertices; j++) {
        // get a vertex.
        if (j < p->numberofvertices) {
          end2 = p->vertexlist[j];
        } else {
          end2 = p->vertexlist[0];  // Form a loop from last to first.
        }
        if ((end2 < in->firstnumber) ||
            (end2 >= in->firstnumber + in->numberofpoints)) {
          if (!b->quiet) {
            printf("Warning:  Invalid vertex %d in polygon %d", end2, i + 1);
            printf(" in facet %d.\n", shmark);
          }
        } else {
          if (end1 != end2) {
            // 'end1' and 'end2' form a segment.
            tend = idx2verlist[end2];
            // Add tstart to V if it haven't been added yet.
            if (!pinfected(tend)) {
              pinfect(tend);
              ptlist->newindex((void **) &pnewpt);
              *pnewpt = tend;
            }
            // Save the segment in S (conlist).
            conlist->newindex((void **) &cons);
            cons[0] = tstart;
            cons[1] = tend;
            // Set the start for next continuous segment.
            end1 = end2;
            tstart = tend;
          } else {
            // Two identical vertices mean an isolated vertex of F.
            if (p->numberofvertices > 2) {
              // This may be an error in the input, anyway, we can continue
              //   by simply skipping this segment.
              if (!b->quiet) {
                printf("Warning:  Polygon %d has two identical verts", i + 1);
                printf(" in facet %d.\n", shmark);
              }
            } 
            // Ignore this vertex.
          }
        }
        // Is the polygon degenerate (a segment or a vertex)?
        if (p->numberofvertices == 2) break;
      }
    }
    // Unmark vertices.
    for (i = 0; i < ptlist->objects; i++) {
      pnewpt = (point *) fastlookup(ptlist, i);
      puninfect(*pnewpt);
    }

    // Triangulate F into a CDT.
    triangulate(shmark, ptlist, conlist, f->numberofholes, f->holelist);

    // Clear working lists.
    ptlist->restart();
    conlist->restart();
  }

  delete ptlist;
  delete conlist;
  delete [] idx2verlist;

  // Remove redundant segments and build the face links.
  unifysegments();

  if (b->object == tetgenbehavior::STL) {
    // Remove redundant vertices (for .stl input mesh).
    jettisonnodes();
  }

  if (!b->nomerge && !b->nobisect) {
    // Merge adjacent coplanar facets.
    mergefacets();
  }

  // Mark acutes vertices.
  markacutevertices();

  // The total number of iunput segments.
  insegments = subsegpool->items;
}

#endif // #ifndef surfaceCXX