#ifndef delaunayCXX
#define delaunayCXX

#include "tetgen.h"

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// randomnation()    Generate a random number between 0 and 'choices' - 1.   //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

unsigned long tetgenmesh::randomnation(unsigned long choices)
{
  unsigned long newrandom;

  if (choices >= 714025l) {
    newrandom = (randomseed * 1366l + 150889l) % 714025l;
    randomseed = (newrandom * 1366l + 150889l) % 714025l;
    newrandom = newrandom * (choices / 714025l) + randomseed;
    if (newrandom >= choices) {
      return newrandom - choices;
    } else {
      return newrandom;
    }
  } else {
    randomseed = (randomseed * 1366l + 150889l) % 714025l;
    return randomseed % choices;
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// randomsample()    Randomly sample the tetrahedra for point loation.       //
//                                                                           //
// This routine implements Muecke's Jump-and-walk point location algorithm.  //
// It improves the simple walk-through by "jumping" to a good starting point //
// via random sampling.  Searching begins from one of handles:  the input    //
// 'searchtet', a recently encountered tetrahedron 'recenttet',  or from one //
// chosen from a random sample.  The choice is made by determining which one //
// 's origin is closest to the point we are searcing for.  Having chosen the //
// starting tetrahedron, the simple Walk-through algorithm is executed.      //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::randomsample(point searchpt, triface *searchtet)
{
  tetrahedron *firsttet, *tetptr;
  point torg;
  void **sampleblock;
  long sampleblocks, samplesperblock, samplenum;
  unsigned long alignptr;
  REAL searchdist, dist;
  int tetblocks, i, j;

  if ((searchtet->tet != NULL) && (searchtet->tet[4] != NULL)) {
    // Get the distance from the suggested starting tet to the search point.
    if ((point) searchtet->tet[7] != dummypoint) {
      torg = org(*searchtet);
    } else {
      torg = (point) searchtet->tet[4];
    }
    searchdist = NORM2(searchpt[0] - torg[0], searchpt[1] - torg[1], 
                       searchpt[2] - torg[2]);
  } else {
    searchdist = NORM2(xmax - xmin, ymax - ymin, zmax - zmin);
  }

  // If a recently encountered tetrahedron has been recorded and has not
  //   been deallocated, test it as a good starting point.
  if ((recenttet.tet != NULL) && (recenttet.tet[4] != NULL)) {
    if ((point) recenttet.tet[7] != dummypoint) {
      torg = org(recenttet);
    } else {
      torg = (point) recenttet.tet[4];
    }
    dist = NORM2(searchpt[0] - torg[0], searchpt[1] - torg[1],
                 searchpt[2] - torg[2]);
    if (dist <= searchdist) {
      *searchtet = recenttet;
      searchdist = dist;
    }
  }

  // Select "good" candidate using k random samples, taking the closest one.
  //   The number of random samples taken is proportional to the fourth root
  //   of the number of tetrahedra in the mesh.
  while (samples * samples * samples * samples < tetrahedronpool->items) {
    samples++;
  }
  // Find how much blocks in current tet pool.
  tetblocks = (tetrahedronpool->maxitems + ELEPERBLOCK - 1) / ELEPERBLOCK;
  // Find the average samles per block. Each block at least have 1 sample.
  samplesperblock = (samples + tetblocks - 1) / tetblocks;
  sampleblocks = samples / samplesperblock;
  sampleblock = tetrahedronpool->firstblock;
  for (i = 0; i < sampleblocks; i++) {
    alignptr = (unsigned long) (sampleblock + 1);
    firsttet = (tetrahedron *)
               (alignptr + (unsigned long) tetrahedronpool->alignbytes
               - (alignptr % (unsigned long) tetrahedronpool->alignbytes));
    for (j = 0; j < samplesperblock; j++) {
      if (i == tetblocks - 1) {
        // This is the last block.
        samplenum = randomnation((int)
                      (tetrahedronpool->maxitems - (i * ELEPERBLOCK)));
      } else {
        samplenum = randomnation(ELEPERBLOCK);
      }
      tetptr = (tetrahedron *)
               (firsttet + (samplenum * tetrahedronpool->itemwords));
      if (tetptr[4] != (tetrahedron) NULL) {
        torg = (point) tetptr[4];
        dist = NORM2(searchpt[0] - torg[0], searchpt[1] - torg[1],
	             searchpt[2] - torg[2]);
        if (dist < searchdist) {
          searchtet->tet = tetptr;
          searchtet->loc = 0;
          searchtet->ver = 0;
          searchdist = dist;
        }
      } else {
        if (i != tetblocks - 1) j--;
      }
    }
    sampleblock = (void **) *sampleblock;
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// locate()    Find a simplex containing a given point.                      //
//                                                                           //
// This routine implements the simple Walk-through point location algorithm. //
// Begins its search from 'searchtet', assume there is a line segment L from //
// the origin of 'searchtet' to the query point 'searchpt', and simply walk  //
// towards 'searchpt' by traversing all faces intersected by L.              //
//                                                                           //
// On completion, 'searchtet' is a tetrahedron that contains 'searchpt'. The //
// returned value indicates one of the following cases:                      //
//   - ONVERTEX, the search point lies on the origin of 'searchtet'.         //
//   - ONEDGE, the search point lies on an edge of 'searchtet'.              //
//   - ONFACE, the search point lies on a face of 'searchtet'.               //
//   - INTET, the search point lies in the interior of 'searchtet'.          //
//   - OUTSIDE, the search point lies outside the mesh. 'searchtet' is a     //
//     hull tetrahedron whose base face is visible by the search point.      //
//                                                                           //
// WARNING: This routine is designed for convex triangulations, and will not //
// generally work after the holes and concavities have been carved.          //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

enum tetgenmesh::location tetgenmesh::locate(point searchpt,triface* searchtet)
{
  triface neightet;
  point torg, tdest, tapex, toppo, ntoppo;
  enum {ORGMOVE, DESTMOVE, APEXMOVE} nextmove;
  REAL ori, oriorg, oridest, oriapex;
  REAL searchdist, dist;

  tetrahedron ptr;
  int *iptr;

  if ((point) searchtet->tet[7] == dummypoint) {
    // A hull tet. Choose the neighbor of its base face.
    searchtet->loc = 0;
    symself(*searchtet);
  } else {
    // Stay in the 0th edge ring.
    if (searchtet->ver & 01) esymself(*searchtet);
  }
  // Let searchtet be the face such that 'searchpt' lies above to it.
  for (; ; searchtet->loc = (searchtet->loc + 1) % 4) { 
    torg = org(*searchtet);
    tdest = dest(*searchtet);
    tapex = apex(*searchtet);
    ori = orient3d(torg, tdest, tapex, searchpt); orient3dcount++;
    if (ori < 0) {
      // searchpt lies above searchtet's face.
      break;
    } else if (ori > 0) {
      // searchpt lies below searchtet's face.
      symself(*searchtet);
      torg = org(*searchtet);
      tdest = dest(*searchtet);
      tapex = apex(*searchtet);
      break;
    }
    // searchpt is coplanar with searchtet's face. Go to the next face.
  }

  // Walk through tetrahedra to locate the point.
  while (true) {

    ptloc_count++;  // Algorithimic count.

    toppo = oppo(*searchtet);
    
    // Check if we have walked out of the domain.
    if (toppo == dummypoint) {
      return OUTSIDE;
    }
    
    // Check if the vertex is we seek.
    if (toppo == searchpt) {
      // Adjust the origin of searchtet to be searchpt.
      enext0fnextself(*searchtet);
      esymself(*searchtet);
      enext2self(*searchtet);
      return ONVERTEX;
    }

    // We enter from serarchtet's base face. There are three other faces in
    //   searchtet (all connecting to toppo), which one is the exit?
    oriorg = orient3d(tdest, tapex, toppo, searchpt); 
    oridest = orient3d(tapex, torg, toppo, searchpt);
    oriapex = orient3d(torg, tdest, toppo, searchpt);
    orient3dcount+=3;

    // Now decide which face to move. It is possible there are more than one
    //   faces are viable moves. Use the opposite points of thier neighbors
    //   to discriminate, i.e., we choose the face whose opposite point has
    //   the shortest distance to searchpt.
    if (oriorg < 0) {
      if (oridest < 0) {
        if (oriapex < 0) {
          // Any of the three faces is a viable move. 
          nextmove = ORGMOVE;
          enextfnext(*searchtet, neightet);
          symself(neightet);
          ntoppo = oppo(neightet);
          if (ntoppo != dummypoint) {
            searchdist = NORM2(searchpt[0] - ntoppo[0],
                               searchpt[1] - ntoppo[1],
                               searchpt[2] - ntoppo[2]);
          } else {
            searchdist = NORM2(xmax - xmin, ymax - ymin, zmax - zmin);
          }
          enext2fnext(*searchtet, neightet);
          symself(neightet);
          ntoppo = oppo(neightet);
          if (ntoppo != dummypoint) {
            dist = NORM2(searchpt[0] - ntoppo[0], searchpt[1] - ntoppo[1],
                         searchpt[2] - ntoppo[2]);
          } else {
            dist = searchdist;
          }
          if (dist < searchdist) {
            nextmove = DESTMOVE;
            searchdist = dist;
          }
          enext0fnext(*searchtet, neightet);
          symself(neightet);
          ntoppo = oppo(neightet);
          if (ntoppo != dummypoint) {
            dist = NORM2(searchpt[0] - ntoppo[0], searchpt[1] - ntoppo[1],
                         searchpt[2] - ntoppo[2]);
          } else {
            dist = searchdist;
          }
          if (dist < searchdist) {
            nextmove = APEXMOVE;
            searchdist = dist;
          }
        } else {
          // Two faces, opposite to origin and destination, are viable.
          nextmove = ORGMOVE;
          enextfnext(*searchtet, neightet);
          symself(neightet);
          ntoppo = oppo(neightet);
          if (ntoppo != dummypoint) {
            searchdist = NORM2(searchpt[0] - ntoppo[0],
                               searchpt[1] - ntoppo[1],
                               searchpt[2] - ntoppo[2]);
          } else {
            searchdist = NORM2(xmax - xmin, ymax - ymin, zmax - zmin);
          }
          enext2fnext(*searchtet, neightet);
          symself(neightet);
          ntoppo = oppo(neightet);
          if (ntoppo != dummypoint) {
            dist = NORM2(searchpt[0] - ntoppo[0], searchpt[1] - ntoppo[1],
                         searchpt[2] - ntoppo[2]);
          } else {
            dist = searchdist;
          }
          if (dist < searchdist) {
            nextmove = DESTMOVE;
            searchdist = dist;
          }
        }
      } else {
        if (oriapex < 0) {
          // Two faces, opposite to origin and apex, are viable.
          nextmove = ORGMOVE;
          enextfnext(*searchtet, neightet);
          symself(neightet);
          ntoppo = oppo(neightet);
          if (ntoppo != dummypoint) {
            searchdist = NORM2(searchpt[0] - ntoppo[0],
                               searchpt[1] - ntoppo[1],
                               searchpt[2] - ntoppo[2]);
          } else {
            searchdist = NORM2(xmax - xmin, ymax - ymin, zmax - zmin);
          }
          enext0fnext(*searchtet, neightet);
          symself(neightet);
          ntoppo = oppo(neightet);
          if (ntoppo != dummypoint) {
            dist = NORM2(searchpt[0] - ntoppo[0], searchpt[1] - ntoppo[1],
                         searchpt[2] - ntoppo[2]);
          } else {
            dist = searchdist;
          }
          if (dist < searchdist) {
            nextmove = APEXMOVE;
            searchdist = dist;
          }
        } else {
          // Only the face opposite to origin is viable.
          nextmove = ORGMOVE;
        }
      }
    } else {
      if (oridest < 0) {
        if (oriapex < 0) {
          // Two faces, opposite to destination and apex, are viable.
          nextmove = DESTMOVE;
          enext2fnext(*searchtet, neightet);
          symself(neightet);
          ntoppo = oppo(neightet);
          if (ntoppo != dummypoint) {
            searchdist = NORM2(searchpt[0] - ntoppo[0],
                               searchpt[1] - ntoppo[1],
                               searchpt[2] - ntoppo[2]);
          } else {
            searchdist = NORM2(xmax - xmin, ymax - ymin, zmax - zmin);
          }
          enext0fnext(*searchtet, neightet);
          symself(neightet);
          ntoppo = oppo(neightet);
          if (ntoppo != dummypoint) {
            dist = NORM2(searchpt[0] - ntoppo[0], searchpt[1] - ntoppo[1],
                         searchpt[2] - ntoppo[2]);
          } else {
            dist = searchdist;
          }
          if (dist < searchdist) {
            nextmove = APEXMOVE;
            searchdist = dist;
          }
        } else {
          // Only the face opposite to destination is viable.
          nextmove = DESTMOVE;
        }
      } else {
        if (oriapex < 0) {
          // Only the face opposite to apex is viable.
          nextmove = APEXMOVE;
        } else {
          // The point we seek must be on the boundary of or inside this
          //   tetrahedron. Check for boundary cases.
          if (oriorg == 0) {
            // Go to the face opposite to origin.
            enextfnextself(*searchtet);
            if (oridest == 0) {
              enextself(*searchtet); // edge apex->oppo
              if (oriapex == 0) {
                enextself(*searchtet); // oppo is duplicated with p.
                return ONVERTEX;
              }
              return ONEDGE;
            }
            if (oriapex == 0) {
              enext2self(*searchtet);
              return ONEDGE;
            }
            return ONFACE;
          }
          if (oridest == 0) {
            // Go to the face opposite to destination.
            enext2fnextself(*searchtet);
            if (oriapex == 0) {
              enextself(*searchtet);
              return ONEDGE;
            }
            return ONFACE;
          }
          if (oriapex == 0) {
            // Go to the face opposite to apex
            enext0fnextself(*searchtet);
            return ONFACE;
          }
          return INTET;
        }
      }
    }
    
    // Move to the selected face.
    if (nextmove == ORGMOVE) {
      enextfnextself(*searchtet);
    } else if (nextmove == DESTMOVE) {
      enext2fnextself(*searchtet);
    } else {
      enext0fnextself(*searchtet);
    }
    // Move to the adjacent tetrahedron (maybe a hull tetrahedron).
    symself(*searchtet);
    // Retreat the three vertices of the base face.
    torg = org(*searchtet);
    tdest = dest(*searchtet);
    tapex = apex(*searchtet);

  } // while (true)
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// initialDT()    Create an initial Delaunay tetrahedralization.             //
//                                                                           //
// The tetrahedralization contains only one tetrahedron abcd, and four hull  //
// tetrahedra.  The points pa, pb, pc, and pd must be linearly independent.  //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::initialDT(point pa, point pb, point pc, point pd)
{
  triface firsttet, tetopa, tetopb, tetopc, tetopd;
  triface worktet, worktet1;
  int *iptr;

  if (b->verbose > 1) {
    printf("    Create init tet (%d, %d, %d, %d)\n", pointmark(pa),
      pointmark(pb), pointmark(pc), pointmark(pd));
  }

  // Create the first tetrahedron.
  maketetrahedron(&firsttet);
  setvertices(firsttet, pa, pb, pc, pd);
  // Create four hull tetrahedra.
  maketetrahedron(&tetopa);
  setvertices(tetopa, pb, pc, pd, dummypoint);
  maketetrahedron(&tetopb);
  setvertices(tetopb, pc, pa, pd, dummypoint);
  maketetrahedron(&tetopc);
  setvertices(tetopc, pa, pb, pd, dummypoint);
  maketetrahedron(&tetopd);
  setvertices(tetopd, pb, pa, pc, dummypoint);
  hullsize += 4;

  // Connect hull tetrahedra to firsttet (at four faces of firsttet).
  bond(firsttet, tetopd); // ab
  enext0fnext(firsttet, worktet);
  bond(worktet, tetopc); // ab
  enextfnext(firsttet, worktet);
  bond(worktet, tetopa); // bc 
  enext2fnext(firsttet, worktet);
  bond(worktet, tetopb); // ca

  // Connect hull tetrahedra together (at six edges of firsttet).
  enext0fnext(tetopc, worktet); 
  enext0fnext(tetopd, worktet1);
  bond(worktet, worktet1); // ab
  enext0fnext(tetopa, worktet);
  enext2fnext(tetopd, worktet1);
  bond(worktet, worktet1); // bc
  enext0fnext(tetopb, worktet);
  enextfnext(tetopd, worktet1);
  bond(worktet, worktet1); // ca
  enext2fnext(tetopc, worktet);
  enextfnext(tetopb, worktet1);
  bond(worktet, worktet1); // da
  enext2fnext(tetopa, worktet);
  enextfnext(tetopc, worktet1);
  bond(worktet, worktet1); // db
  enext2fnext(tetopb, worktet);
  enextfnext(tetopa, worktet1);
  bond(worktet, worktet1); // dc

  // Set the vertex type.
  if (getpointtype(pa) == UNUSEDVERTEX) {
    setpointtype(pa, VOLVERTEX);
  }
  if (getpointtype(pb) == UNUSEDVERTEX) {
    setpointtype(pb, VOLVERTEX);
  }
  if (getpointtype(pc) == UNUSEDVERTEX) {
    setpointtype(pc, VOLVERTEX);
  }
  if (getpointtype(pd) == UNUSEDVERTEX) {
    setpointtype(pd, VOLVERTEX);
  }

  // Update the point-to-tet map.
  // if (checksubsegs || checksubfaces) {
    point2tet(pa) = encode(firsttet);
    point2tet(pb) = encode(firsttet);
    point2tet(pc) = encode(firsttet);
    point2tet(pd) = encode(firsttet);
  // }

  // Remember the first tetrahedron.
  recenttet = firsttet;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// insertvertex()    Insert a point (p) into tetrahedralization (T).         //
//                                                                           //
// The point p will be first located in T. 'searchtet' is a suggested start- //
// tetrahedron, it can be NULL. Note that p may lies outside T. In such case,//
// the convex hull of T will be updated to include p as a vertex.            //
//                                                                           //
// If 'bwflag' is TRUE, the Bowyer-Watson algorithm is used to recover the   //
// Delaunayness of T. Otherwise, do nothing with regard to the Delaunayness  //
// T (T may be non-Delaunay after this function).                            //
//                                                                           //
// If 'visflag' is TRUE, force to check the visibility of the boundary faces //
// of cavity. This is needed when T is not Delaunay.                         //
//                                                                           //
// If 'noencflag' is TRUE, only insert the new point p if it does not cause  //
// any existing (sub)segment be non-Delaunay. This option only is checked    //
// when the global variable 'checksubsegs' is set.                           //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

enum tetgenmesh::location tetgenmesh::insertvertex(point insertpt, 
  triface *searchtet, bool bwflag, bool visflag, bool noencsegflag,
  bool noencsubflag)
{
  triface *cavetet, *parytet, spintet, neightet, newtet, neineitet;
  face *pssub, checksh;
  face *psseg, sseg;
  point *pts, pa, pb, pc;
  enum location loc;
  REAL sign, ori;
  long tetcount;
  bool enqflag;
  int i, j, k;

  badface *newflip, *lastflip;  // for bowyerwatson
  triface fliptets[5], baktets[2];

  tetrahedron ptr;
  int *iptr, tver;

  arraypool *swaplist; // for updating cavity.
  long updatecount;

  // clock_t loc_start, loc_end;

  if (b->verbose > 1) {
    printf("    Insert point %d\n", pointmark(insertpt));
  }

  // loc_start = clock();

  tetcount = ptloc_count;
  updatecount = 0l;
  
  if (searchtet->tet == NULL) {
    randomsample(insertpt, searchtet);
  }
  loc = locate(insertpt, searchtet);

  // loc_end = clock();
  // tloctime += ((REAL) (loc_end - loc_start)) / CLOCKS_PER_SEC;

  if (b->verbose > 1) {
    printf("    Walk distance (# tets): %ld\n", ptloc_count - tetcount);
  }

  if (ptloc_max_count < (ptloc_count - tetcount)) {
    ptloc_max_count = (ptloc_count - tetcount);
  }

  if (b->verbose > 1) {
    printf("    Located (%d) tet (%d, %d, %d, %d).\n", (int) loc,
      pointmark(org(*searchtet)), pointmark(dest(*searchtet)), 
      pointmark(apex(*searchtet)), pointmark(oppo(*searchtet)));
  }

  if (loc == ONVERTEX) {
    // The point already exists. Mark it and do nothing on it.
    if (b->object != tetgenbehavior::STL) {
      if (!b->quiet) {
        printf("Warning:  Point #%d is duplicated with Point #%d. Ignored!\n",
          pointmark(insertpt), pointmark(org(*searchtet)));
      }
    }
    point2ppt(insertpt) = org(*searchtet);
    setpointtype(insertpt, DUPLICATEDVERTEX);
    dupverts++;
    return loc;
  }

  // loc_start = clock();

  tetcount = 0l;  // The number of deallocated tets.

  // Create the initial boundary of the cavity.
  if (loc == INTET || loc == OUTSIDE) {
    // Add four adjacent boundary tets into list.
    for (i = 0; i < 4; i++) {
      decode(searchtet->tet[i], neightet);
      cavetetlist->newindex((void **) &parytet);
      *parytet = neightet;
    }
    if ((point) searchtet->tet[7] == dummypoint) hullsize--;
    // tetrahedrondealloc(searchtet->tet);
    infect(*searchtet);
    caveoldtetlist->newindex((void **) &parytet);
    *parytet = *searchtet;
    tetcount = 1;
    flip14count++;
  } else if (loc == ONFACE) {
    // Add six adjacent boundary tets into list.
    for (i = 0; i < 3; i++) {
      decode(searchtet->tet[locpivot[searchtet->loc][i]], neightet);
      cavetetlist->newindex((void **) &parytet);
      *parytet = neightet;
    }
    decode(searchtet->tet[searchtet->loc], spintet);
    for (i = 0; i < 3; i++) {
      decode(spintet.tet[locpivot[spintet.loc][i]], neightet);
      cavetetlist->newindex((void **) &parytet);
      *parytet = neightet;
    }
    if ((point) spintet.tet[7] == dummypoint) hullsize--;
    if ((point) searchtet->tet[7] == dummypoint) hullsize--;
    // tetrahedrondealloc(spintet.tet);
    infect(spintet);
    caveoldtetlist->newindex((void **) &parytet);
    *parytet = spintet;
    // tetrahedrondealloc(searchtet->tet);
    infect(*searchtet);
    caveoldtetlist->newindex((void **) &parytet);
    *parytet = *searchtet;
    tetcount = 2;
    flip26count++;
  } else if (loc == ONEDGE) {
    // Add all adjacent boundary tets into list.
    spintet = *searchtet;
    tetcount = 0;
    do {
      fnextself(spintet);
      tetcount++;
      decode(spintet.tet[locverpivot[spintet.loc][spintet.ver][0]], neightet);
      cavetetlist->newindex((void **) &parytet);
      *parytet = neightet;
      decode(spintet.tet[locverpivot[spintet.loc][spintet.ver][1]], neightet);
      cavetetlist->newindex((void **) &parytet);
      *parytet = neightet;
    } while (spintet.tet != searchtet->tet);
    // Delete old tets in the cavity.
    spintet = *searchtet;
    for (i = 0; i < tetcount; i++) {
      fnext(spintet, neightet);
      if ((point) spintet.tet[7] == dummypoint) hullsize--;
      // tetrahedrondealloc(spintet.tet);
      infect(spintet);
      caveoldtetlist->newindex((void **) &parytet);
      *parytet = spintet;
      spintet = neightet;
    }
    flipn2ncount++;
  }

  // Form the cavity by including tets from initial boundary.
  for (i = 0; i < cavetetlist->objects; i++) {
    // 'cavetet' is actually an adjacent tet to the cavity.
    cavetet = (triface *) fastlookup(cavetetlist, i);
    // Do check if it is not infected (not deleted yet).
    if (!infected(*cavetet)) { // if (cavetet->tet[4] != NULL) {
      // Check for two possible cases for this tet: 
      //   (1) It is a cavity tet, or
      //   (2) it is a cavity boundary face.
      // In case (1), the three other faces of this tet are added into
      //   'cavetetlist' for later checking (we use a bread-first search),
      //   and this tet gets deleted (infected).
      enqflag = false;
      if (!marktested(*cavetet)) {
        pts = (point *) cavetet->tet;
        if (pts[7] != dummypoint) {
          // A volume tet. Operate on it if it has not been tested yet.
          if (bwflag) {
            // Use Bowyer-Watson algorithm, do Delaunay check.
            sign = insphere_sos(pts[4], pts[5], pts[6], pts[7], insertpt);
            enqflag = (sign < 0.0);
          }
        } else {
          // It is a hull tet. Check if its base face is visible by p. 
          //   This happens when p lies outside the hull face.
          ori = orient3d(pts[4], pts[5], pts[6], insertpt); orient3dcount++;
          enqflag = (ori < 0.0);
          // Check if this face is coplanar with p. This case may create
          //   a degenerate tet (zero volume). 
          // Note: for convex domain, it can only happen at a hull face.
          if (bwflag && (ori == 0.0)) {
            newflip = (badface *) flippool->alloc();
            newflip->tt = *cavetet; // Queue the adjacent tet (not in cavity).
            newflip->tt.loc = 0; // Must be at the base face.
            newflip->nextitem = NULL;
            if (futureflip == NULL) {
              lastflip = futureflip = newflip;
            } else {
              lastflip->nextitem = newflip;
              lastflip = newflip;
            }
          }
        } // if (pts[7] != dummypoint)
        marktest(*cavetet); // Only test it once.
      }
      /*// Validation is needed when T is not a Delaunay triangulation. The
      //   default cavity may not be star-shaped (fig/dump-cavity-case8).
      if (visflag && !enqflag) {
        if ((point) cavetet->tet[7] != dummypoint) {
          // A non-hull cavity boundary face. Validate it.
          cavetet->ver = 4;
          pa = org(*cavetet);
          pb = dest(*cavetet);
          pc = apex(*cavetet);
          ori = orient3d(pa, pb, pc, insertpt); orient3dcount++;
          assert(ori != 0.0); // SELF_CHECK
          enqflag = (ori < 0.0);
          if (enqflag) {
            updatecount++; // Cavity is updated.
          }
        }
      }*/
      if (enqflag) {
        // Found a tet in the cavity. Put other three faces in check list.
        for (j = 0; j < 3; j++) {
          decode(cavetet->tet[locpivot[cavetet->loc][j]], neightet);
          cavetetlist->newindex((void **) &parytet);
          *parytet = neightet;
        }
        if ((point) cavetet->tet[7] == dummypoint) hullsize--;
        // tetrahedrondealloc(cavetet->tet);
        infect(*cavetet);
        caveoldtetlist->newindex((void **) &parytet);
        *parytet = *cavetet;
        tetcount++;
      } else {
        // Found a boundary face of the cavity. It may be a face of a hull
        //   tet which contains 'dummypoint'. Choose the edge in the face 
        //   such that its endpoints are not 'dummypoint', while its apex
        //   may be 'dummypoint' (see Fig. 1.4).
        cavetet->ver = 4;
        cavebdrylist->newindex((void **) &parytet);
        *parytet = *cavetet;
      }
    } // if (cavetet->tet[4] != NULL)
  }

  if (b->verbose > 1) {
    printf("    Size of the cavity: %d faces %d tets.\n",
           cavebdrylist->objects, tetcount);
  }

  totaldeadtets += tetcount;
  totalbowatcavsize += cavebdrylist->objects;
  if (maxbowatcavsize < cavebdrylist->objects) {
    maxbowatcavsize = cavebdrylist->objects;
  }

  if (checksubsegs || noencsegflag) {
    // Check if some (sub)segments are inside the cavity.
    for (i = 0; i < caveoldtetlist->objects; i++) {
      cavetet = (triface *) fastlookup(caveoldtetlist, i);
      for (j = 0; j < 6; j++) {
        cavetet->loc = edge2locver[j][0];
        cavetet->ver = edge2locver[j][1];
        tsspivot(*cavetet, sseg);
        if ((sseg.sh != NULL) && !sinfected(sseg)) {
          // Check if this segment is inside the cavity.
          spintet = *cavetet;
          pa = apex(spintet);
          enqflag = true;
          while (1) {
            fnextself(spintet);
            if (!infected(spintet)) {
              enqflag = false; break; // It is not inside.
            }
            if (apex(spintet) == pa) break;
          }
          if (enqflag) {
            if (b->verbose > 1) {
              printf("      Queue a missing segment (%d, %d).\n",
                pointmark(sorg(sseg)), pointmark(sdest(sseg)));
            }
            sinfect(sseg);  // Only save it once.
            subsegstack->newindex((void **) &psseg);
            *psseg = sseg;
          }
        }
      }
    }
  }

  if (noencsegflag && (subsegstack->objects > 0)) {
    // Found encroached subsegments! Do not insert this point.
    for (i = 0; i < caveoldtetlist->objects; i++) {
      cavetet = (triface *) fastlookup(caveoldtetlist, i);
      uninfect(*cavetet);
      unmarktest(*cavetet);
    }
    for (i = 0; i < cavebdrylist->objects; i++) {
      cavetet = (triface *) fastlookup(cavebdrylist, i);
      unmarktest(*cavetet); // Unmark it.
    }
    if (bwflag && (futureflip != NULL)) {
      flippool->restart();
      futureflip = NULL;
    }
    cavetetlist->restart();
    cavebdrylist->restart();
    caveoldtetlist->restart();
    return ENCSEGMENT;
  }

  if (checksubfaces || noencsubflag) {
    // Check if some subfaces are inside the cavity.
    for (i = 0; i < caveoldtetlist->objects; i++) {
      cavetet = (triface *) fastlookup(caveoldtetlist, i);
      neightet.tet = cavetet->tet;
      for (neightet.loc = 0; neightet.loc < 4; neightet.loc++) {
        tspivot(neightet, checksh);
        if (checksh.sh != NULL) {
          sym(neightet, neineitet);
          // Do not check it if it is a hull tet.
          if (infected(neineitet)) {
            if (b->verbose > 1) {
              printf("      Queue a missing subface (%d, %d, %d).\n",
                pointmark(sorg(checksh)), pointmark(sdest(checksh)),
                pointmark(sapex(checksh)));
            }
            tsdissolve(neineitet); // Disconnect a tet-sub bond.
            stdissolve(checksh); // Disconnect the sub-tet bond.
            // Add the missing subface into list.
            subfacstack->newindex((void **) &pssub);
            *pssub = checksh;
          }
        }
      }
    }
  }

  if (noencsubflag && (subfacstack->objects > 0)) {
    // Found encroached subfaces! Do not insert this point.
    for (i = 0; i < caveoldtetlist->objects; i++) {
      cavetet = (triface *) fastlookup(caveoldtetlist, i);
      uninfect(*cavetet);
      unmarktest(*cavetet);
    }
    for (i = 0; i < cavebdrylist->objects; i++) {
      cavetet = (triface *) fastlookup(cavebdrylist, i);
      unmarktest(*cavetet); // Unmark it.
    }
    if (bwflag && (futureflip != NULL)) {
      flippool->restart();
      futureflip = NULL;
    }
    cavetetlist->restart();
    cavebdrylist->restart();
    caveoldtetlist->restart();
    return ENCFACE;
  }

  if (visflag) {
    // If T is not a Delaunay triangulation, the formed cavity may not be
    //   star-shaped (fig/dump-cavity-case8). Validation is needed.
    cavetetlist->restart(); // Re-use it.
    for (i = 0; i < cavebdrylist->objects; i++) {
      cavetet = (triface *) fastlookup(cavebdrylist, i);
      // 'cavetet' is an exterior tet adjacent to the cavity.
      assert(cavetet->ver == 4); // SELF_CHECK
      symedge(*cavetet, neightet);
      if (infected(neightet)) {
        if ((point) cavetet->tet[7] != dummypoint) {
          pa = org(*cavetet);
          pb = dest(*cavetet);
          pc = apex(*cavetet);
          ori = orient3d(pa, pb, pc, insertpt); orient3dcount++;
          assert(ori != 0.0); // SELF_CHECK
          enqflag = (ori > 0.0);
        } else {
          enqflag = true; // A hull face.
        }
        if (enqflag) {
          // This face is valid, save it.
          cavetetlist->newindex((void **) &parytet);
          *parytet = *cavetet; 
        } else {
          if (b->verbose > 1) {
            printf("    Cut tet (%d, %d, %d, %d)\n", pointmark(pb), 
              pointmark(pa), pointmark(pc), pointmark(oppo(neightet)));
          }
          uninfect(neightet);
          unmarktest(neightet);
          updatecount++;
          // Add three new faces to find new boundaries.
          for (j = 0; j < 3; j++) {
            enext0fnext(neightet, neineitet);
            neineitet.ver = 4;
            cavebdrylist->newindex((void **) &parytet);
            *parytet = neineitet;
            enextself(neightet);
          }
        }
      } else {
        // This face is not on the cavity boundary anymore.
        unmarktest(*cavetet);
      }
    }
    if (updatecount > 0) {
      // Update the cavity boundary faces (fig/dump-cavity-case9).
      cavebdrylist->restart();
      for (i = 0; i < cavetetlist->objects; i++) {
        cavetet = (triface *) fastlookup(cavetetlist, i);
        // 'cavetet' was an exterior tet adjacent to the cavity.
        assert(cavetet->ver == 4); // SELF_CHECK
        symedge(*cavetet, neightet);
        if (infected(neightet)) {
          // It is a cavity boundary face.
          cavebdrylist->newindex((void **) &parytet);
          *parytet = *cavetet;
        } else {
          // Not a cavity boundary face.
          unmarktest(*cavetet);
        }
      }
      // Update the list of old tets.
      cavetetlist->restart();
      for (i = 0; i < caveoldtetlist->objects; i++) {
        cavetet = (triface *) fastlookup(caveoldtetlist, i);
        if (infected(*cavetet)) {
          cavetetlist->newindex((void **) &parytet);
          *parytet = *cavetet;
        }
      }
      assert(cavetetlist->objects < i);
      // Swap 'cavetetlist' and 'caveoldtetlist'.
      swaplist = caveoldtetlist;
      caveoldtetlist = cavetetlist;
      cavetetlist = swaplist;
      if (b->verbose > 1) {
        printf("    Size of the updated cavity: %d faces %d tets.\n",
          cavebdrylist->objects, caveoldtetlist->objects);
      }
    }
  }

  // Re-use this list for new cavity faces.
  cavetetlist->restart();

  // Create new tetrahedra in the Bowyer-Watson cavity and Connect them.
  for (i = 0; i < cavebdrylist->objects; i++) {
    cavetet = (triface *) fastlookup(cavebdrylist, i);
    neightet = *cavetet;
    unmarktest(neightet); // Unmark it.
    // Get the oldtet (inside the cavity).
    symedge(neightet, neineitet);
    if (apex(neightet) != dummypoint) {
      // Create a new tet in the cavity (see Fig. bowyerwatson 1 or 3).
      maketetrahedron(&newtet);
      setorg(newtet, dest(neightet));
      setdest(newtet, org(neightet));
      setapex(newtet, apex(neightet));
      setoppo(newtet, insertpt);
    } else {
      // Create a new hull tet (see Fig. bowyerwatson 2).
      hullsize++;
      maketetrahedron(&newtet);
      setorg(newtet, org(neightet));
      setdest(newtet, dest(neightet));
      setapex(newtet, insertpt);
      setoppo(newtet, dummypoint);
      // Note: the cavity boundary face is at the enext0fnext place.
      enext0fnextself(newtet);
    }
    // Connect newtet <==> neightet, this also disconnect the old bond.
    bond(newtet, neightet);
    // Let the oldtet knows newtet (for connecting adjacent new tets).
    if (org(newtet) != org(neineitet)) esymself(newtet);
    neineitet.tet[neineitet.loc] = encode(newtet);
    // Replace the old boundary face with the old tet in list.
    *cavetet = neineitet; // *cavetet = newtet;
    if (checksubsegs) {
      newtet.ver &= ~1;  // Keep in 0th edge ring.
      for (j = 0; j < 3; j++) {
        tsspivot(neightet, sseg);
        if (sseg.sh != NULL) {
          if (sinfected(sseg)) {
            // This case is only possible when the cavity has been updated.
            assert(updatecount > 0); // SELF_CHECK
            suninfect(sseg); // Dequeue a non-missing segment.
          }
          tssbond1(newtet, sseg);
        }
        enextself(neightet);
        enext2self(newtet);
      }
    }
    if (checksubfaces) {
      tspivot(neightet, checksh);
      if (checksh.sh != NULL) {
        tsbond(newtet, checksh); // Also disconnect the old bond.
      }
    }
    if (updatecount > 0l) {
      // Save this face for locally Delaunay test.
      cavetetlist->newindex((void **) &parytet);
      *parytet = newtet;
    }
  }

  // Set a handle for speeding point location.
  recenttet = newtet;
  point2tet(insertpt) = encode(newtet);

  /*// Connect the set of new tetrahedra together.
  for (i = 0; i < cavebdrylist->objects; i++) {
    cavetet = (triface *) fastlookup(cavebdrylist, i);
    cavetet->ver = 0;
    for (j = 0; j < 3; j++) {
      enext0fnext(*cavetet, newtet); // Go to the face.
      // Operate on it if it is open.
      if (newtet.tet[newtet.loc] == NULL) {
        // Find its adjacent face by rotating faces around the edge of
        //   cavetet. The rotating direction is opposite to newtet.
        //   Stop the rotate at a face which is open.
        esym(*cavetet, neightet); // Set the rotate dir.
        do {
          fnextself(neightet); // Go to the face in the adjacent tet.
        } while (neightet.tet[neightet.loc] != NULL);
        bond(newtet, neightet); // Connect newtet <==> neightet.
      }
      if (checksubsegs || checksubfaces) {
        point2tet(org(*cavetet)) = encode(*cavetet);
      }
      enextself(*cavetet);
    }
  }*/

  // Connect adjacent new tetrahedra together.
  for (i = 0; i < cavebdrylist->objects; i++) {
    cavetet = (triface *) fastlookup(cavebdrylist, i);
    decode(cavetet->tet[cavetet->loc], newtet);
    // assert(org(newtet) == org(*cavetet)); // SELF_CHECK
    for (j = 0; j < 3; j++) {
      enext0fnext(newtet, neightet); // Go to the face.
      if (neightet.tet[neightet.loc] == NULL) {
        spintet = *cavetet;
        while (1) {
          enext0fnextself(spintet);
          decode(spintet.tet[spintet.loc], neineitet);
          if (!infected(neineitet)) break;
          symedgeself(spintet);
        }
        // Find the corresponding edge in neineitet.
        pa = dest(newtet);
        for (k = 0; k < 3; k++) {
          if (org(neineitet) == pa) break;
          enextself(neineitet);
        }
        assert(k < 3);  // SELF_CHECK
        assert(dest(neineitet) == org(newtet)); // SELF_CHECK
        enext0fnextself(neineitet);
        bond(neightet, neineitet);
        // Queue the internal face if the visflag is set.
        //   See also fig/dump-cavity-case13.
        if (visflag) {
          cavetetlist->newindex((void **) &parytet);
          *parytet = neightet;
        }
      }
      point2tet(org(newtet)) = encode(newtet);
      enextself(newtet);
      enextself(*cavetet);
    }
  }

  // Delete the old cavity tets.
  for (i = 0; i < caveoldtetlist->objects; i++) {
    cavetet = (triface *) fastlookup(caveoldtetlist, i);
    tetrahedrondealloc(cavetet->tet);
  }

  // loc_end = clock();
  // tinserttime += ((REAL) (loc_end - loc_start)) / CLOCKS_PER_SEC;

  if (bwflag && (futureflip != NULL)) {
    // There may exist degenerate tets. Check and remove them.
    while (futureflip != NULL) {
      // Dequeue an adjacent tet to the cavity.
      fliptets[0] = futureflip->tt;
      futureflip = futureflip->nextitem;

      // Skip it if it is dead (by previous flip32s).
      if (fliptets[0].tet[4] == NULL) continue;

      // The possible degenerate tet, check it.
      symself(fliptets[0]); 
      // Skip it if its oppo is not 'p'. 
      if (oppo(fliptets[0]) != insertpt) continue;
      // This must be a new tet.
      assert(oppo(fliptets[0]) == insertpt); // SELF_CHECK

      pts = (point *) fliptets[0].tet;
      ori = orient3d(pts[4], pts[5], pts[6], pts[7]); orient3dcount++;
      
      if (ori == 0) {
        if (b->verbose > 1) {
          printf("    Removing tet (%d, %d, %d, %d).\n", pointmark(pts[4]),
            pointmark(pts[5]), pointmark(pts[6]), pointmark(pts[7]));
        }
        // Find the hull edge in cavetet.
        fliptets[0].ver = 0;
        for (j = 0; j < 3; j++) {
          enext0fnext(fliptets[0], neightet);
          symself(neightet);
          if ((point) neightet.tet[7] == dummypoint) break;
          enextself(fliptets[0]);
        }
        // Because of existing multiple degenerate cases. It is possible
        //   that the other hull face is not pop yet.
        if (j < 3) {
          // Collect tets for flipping the edge.
          for (j = 0; j < 3; j++) {
            fnext(fliptets[j], fliptets[j + 1]);
          }
          if (fliptets[3].tet != fliptets[0].tet) {
            printf("Internal error in insertvertex(): Unknown flip case.\n");
            terminatetetgen(1);
          }
          // Do a 3-to-2 flip to remove the degenerate tet.
          flip32(fliptets, 1, 0);
          // Rememebr the new tet.
          recenttet = fliptets[0];
        } else {
          // Put the face back into queue.
          symself(fliptets[0]);
          newflip = (badface *) flippool->alloc();
          newflip->tt = fliptets[0]; // the adjacent tet (not in cavity).
          newflip->nextitem = NULL;
          if (futureflip == NULL) {
            lastflip = futureflip = newflip;
          } else {
            lastflip->nextitem = newflip;
            lastflip = newflip;
          }
        } // if (j < 3)
      } // if (ori == 0)
    }
    flippool->restart();
  }

  if (bwflag && visflag) {
    // Some new faces may be locally non-Delaunay. Check and fix them.
    for (i = 0; i < cavetetlist->objects; i++) {
      // Get a new face (whose opposite is p).
      parytet = (triface *) fastlookup(cavetetlist, i);
      if ((point) parytet->tet[7] == dummypoint) continue; // A hull face.
      pa = oppo(*parytet);
      futureflip = flippush(futureflip, parytet, pa);
    }
    // Recover Delaunay faces.
    //   Set 'flipflag' = 2, s.t. all faces are checked for flipping.
    lawsonflip3d(2);
  }

  // Set the point type.
  if (getpointtype(insertpt) == UNUSEDVERTEX) {
    setpointtype(insertpt, VOLVERTEX);
  }

  cavetetlist->restart();
  cavebdrylist->restart();
  caveoldtetlist->restart();
  return loc;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// flipinsertvertex()    Insert a vertex (p) into tetrahedralization (T).    //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::flipinsertvertex(point insertpt, triface* searchtet, 
  int flipflag)
{
  enum location loc;
  long tetcount;

  if (b->verbose > 1) {
    printf("    Insert point %d\n", pointmark(insertpt));
  }

  tetcount = ptloc_count;
  
  if (searchtet->tet == NULL) {
    randomsample(insertpt, searchtet);
  }
  loc = locate(insertpt, searchtet);

  if (b->verbose > 1) {
    printf("    Walk distance (# tets): %ld\n", ptloc_count - tetcount);
  }

  if (ptloc_max_count < (ptloc_count - tetcount)) {
    ptloc_max_count = (ptloc_count - tetcount);
  }

  if (b->verbose > 1) {
    printf("    Located (%d) tet (%d, %d, %d, %d).\n", (int) loc,
      pointmark(org(*searchtet)), pointmark(dest(*searchtet)), 
      pointmark(apex(*searchtet)), pointmark(oppo(*searchtet)));
  }
  
  if (loc == ONVERTEX) {
    // The point already exists. Mark it and do nothing on it.
    // In a STL mesh, duplicated points are implicitly included.
    if (b->object != tetgenbehavior::STL) {
      if (!b->quiet) {
        printf("Warning:  Point #%d is duplicated with Point #%d. Ignored!\n",
          pointmark(insertpt), pointmark(org(*searchtet)));
      }
    }
    point2ppt(insertpt) = org(*searchtet);
    setpointtype(insertpt, DUPLICATEDVERTEX);
    dupverts++;
    return;
  }

  // Clear flip stack.
  futureflip = (badface *) NULL;

  // Insert the new point by flipping.
  if (loc == ONFACE) {
    flip26(insertpt, searchtet, flipflag);
  } else if (loc == ONEDGE) {
    flipn2n(insertpt, searchtet, flipflag);
  } else { // (loc == INTET) || (loc == OUTSIDE)
    flip14(insertpt, searchtet, flipflag);
  }

  recenttet = *searchtet; // Remember a handle.

  // Set the point type.
  if (getpointtype(insertpt) == UNUSEDVERTEX) {
    setpointtype(insertpt, VOLVERTEX);
  }

  // If flipflag > 0, do Delaunay flip.
  if (flipflag > 0) {
    lawsonflip3d(flipflag);
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// incrementaldelaunay()    Form a Delaunay tetrahedralization by increment- //
//                          ally inserting vertices.                         //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::incrementaldelaunay()
{
  triface searchtet;
  point *permutarray, swapvertex;
  REAL v1[3], v2[3], n[3];
  REAL bboxsize, bboxsize2, bboxsize3, ori;
  int randindex, i, j;

  if (!b->quiet) {
    printf("Delaunizing vertices.\n");
  }

  // Form a random permuation (uniformly at random) of the set of vertices.
  permutarray = new point[in->numberofpoints];
  pointpool->traversalinit();
  if (b->order == 3) { // '-o3' option (for debug)
    for (i = 0; i < in->numberofpoints; i++) {
      permutarray[i] = (point) pointpool->traverse();
    }
  } else {
    for (i = 0; i < in->numberofpoints; i++) {
      randindex = randomnation(i + 1);
      permutarray[i] = permutarray[randindex];
      permutarray[randindex] = (point) pointpool->traverse();
    }
  }

  // Calculate the diagonal size of its bounding box.
  bboxsize = sqrt(NORM2(xmax - xmin, ymax - ymin, zmax - zmin));
  bboxsize2 = bboxsize * bboxsize;
  bboxsize3 = bboxsize2 * bboxsize;
  
  // Make sure the second vertex is not identical with the first one.
  i = 1;
  while ((DIST(permutarray[0], permutarray[i]) / bboxsize) < b->epsilon) {
    i++;
    if (i == in->numberofpoints - 1) {
      printf("Exception:  All vertices are (nearly) identical (Tol = %g).\n",
             b->epsilon);
      terminatetetgen(1);
    }
  }
  if (i > 1) {
    // Swap to move the non-indetical vertex from index i to index 1.
    swapvertex = permutarray[i];
    permutarray[i] = permutarray[1];
    permutarray[1] = swapvertex;
  }

  // Make sure the third vertex is not collinear with the first two.
  i = 2;
  for (j = 0; j < 3; j++) {
    v1[j] = permutarray[1][j] - permutarray[0][j];
    v2[j] = permutarray[i][j] - permutarray[0][j];
  }
  CROSS(v1, v2, n);
  while ((sqrt(NORM2(n[0], n[1], n[2])) / bboxsize2) < b->epsilon) {
    i++;
    if (i == in->numberofpoints - 1) {
      printf("Exception:  All vertices are (nearly) collinear (Tol = %g).\n",
             b->epsilon);
      terminatetetgen(1);
    }
    for (j = 0; j < 3; j++) {
      v2[j] = permutarray[i][j] - permutarray[0][j];
    }
    CROSS(v1, v2, n);
  }
  if (i > 2) {
    // Swap to move the non-indetical vertex from index i to index 1.
    swapvertex = permutarray[i];
    permutarray[i] = permutarray[2];
    permutarray[2] = swapvertex;
  }

  // Make sure the fourth vertex is not coplanar with the first three.
  i = 3;
  ori = orient3d(permutarray[0], permutarray[1], permutarray[2], 
                 permutarray[i]);
  while ((fabs(ori) / bboxsize3) < b->epsilon) {
    i++;
    if (i == in->numberofpoints) {
      printf("Exception:  All vertices are coplanar (Tol = %g).\n",
             b->epsilon);
      terminatetetgen(1);
    }
    ori = orient3d(permutarray[0], permutarray[1], permutarray[2], 
                   permutarray[i]);
  }
  if (i > 3) {
    // Swap to move the non-indetical vertex from index i to index 1.
    swapvertex = permutarray[i];
    permutarray[i] = permutarray[3];
    permutarray[3] = swapvertex;
  }

  // Orient the first four vertices in permutarray so that they follow the
  //   right-hand rule.
  if (ori > 0.0) {
    // Swap the first two vertices.
    swapvertex = permutarray[0];
    permutarray[0] = permutarray[1];
    permutarray[1] = swapvertex;
  }

  // Create the initial Delaunay tetrahedralization.
  initialDT(permutarray[0], permutarray[1], permutarray[2], permutarray[3]);

  if (b->verbose) {
    printf("  Incremental inserting vertices.\n");
  }

  if (b->bowyerwatson) {
    // Use incremental Bowyer-Watson algorithm.
    for (i = 4; i < in->numberofpoints; i++) {
      if (b->verbose > 1) printf("    #%d", i);
      searchtet.tet = NULL;  // Randomly sample tetrahedra.
      insertvertex(permutarray[i], &searchtet, true, false, false, false);
    }
  } else {
    // Use incremental flip algorithm.
    for (i = 4; i < in->numberofpoints; i++) {
      if (b->verbose > 1) printf("    #%d", i);
      searchtet.tet = NULL;  // Randomly sample tetrahedra.
      flipinsertvertex(permutarray[i], &searchtet, 1); 
    }
  }

  delete [] permutarray;
}

#endif // #ifndef delaunayCXX