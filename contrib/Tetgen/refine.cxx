#ifndef refineCXX
#define refineCXX

#include "tetgen.h"

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// checkedge4encroach()    Check a subsegment to see if it is encroached.    //
//                                                                           //
// If 'testpt' != NULL, only test if the segment is encroached by this point.//
// Otherwise, test all apexes of faces containing this segment.              //
//                                                                           //
// If 'enqflag' > 0, add the segment into list (badsegpool) if it is encroa- //
// ched.                                                                     //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

bool tetgenmesh::checkedge4encroach(face& seg, point testpt, int enqflag)
{
  badface *encseg;
  triface neightet, spintet;
  point pa, pb, pc, encpt;
  REAL midpt[3], r, d, diff;
  int encroached;
  int i;

  seg.shver = 0;
  pa = sorg(seg);
  pb = sdest(seg);

  for (i = 0; i < 3; i++) {
    midpt[i] = 0.5 * (pa[i] + pb[i]);
  }
  r = DIST(midpt, pa);

  encroached = 0;
  encpt = NULL;

  if (testpt == NULL) {
    // Check all apexes of faces containing [pa, pb].
    stpivot(seg, neightet); // sstpivot(seg, neightet);
    spintet = neightet;
    while (1) {
      pc = apex(spintet);
      if (pc != dummypoint) {
        d = DIST(midpt, pc);
        diff = fabs(r - d);
        if ((diff / r) < b->epsilon) {
          // testpt is on the diametric ball of [pa, pb].
          encroached = 0;
        } else {
          encroached = (d < r ? 1 : 0);
        }
        if (encroached) {
          encpt = pc; // pc is encroached [pa. pb].
          break;
        }
      }
      fnextself(spintet);
      if (spintet.tet == neightet.tet) break;
    }
  } else {
    d = DIST(midpt, testpt);
    diff = fabs(r - d);
    if ((diff / r) < b->epsilon) {
      // testpt is on the diametric ball of [pa, pb].
      encroached = 0;
    } else {
      encroached = (d < r ? 1 : 0);
      if (encroached) {
        encpt = testpt;
      }
    }
  }

  if (encroached && enqflag) {
    if (b->verbose > 1) {
      printf("    Queuing encroaching segment (%d, %d) ref (%d).\n", 
        pointmark(pa), pointmark(pb), pointmark(encpt));
    }
    encseg = (badface *) badsegpool->alloc();
    encseg->ss = seg;
    encseg->forg = pa;
    encseg->fdest = pb;
    encseg->foppo = encpt; // The encroaching point.
    smarktest(seg); // Flag it to avoid multiple testing.
  }

  return encroached > 0;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// repairencsegs()    Repair all queued encroached subsegments.              //
//                                                                           //
// Encroached segments are repaired by inserting a vertex inside them.  Each //
// newly inserted vertex may encroach other segments, or makeing them non-   //
// Delaunay, these segments are also repaired.                               //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::repairencsegs()
{
  badface *encloop;
  triface searchtet;
  face splitsh;
  point newpt, refpt;
  point pa, pb;

  while ((badsegpool->items > 0) && (b->steinerleft != 0)) {

    badsegpool->traversalinit();
    encloop = badfacetraverse(badsegpool);
    while ((encloop != NULL) && (b->steinerleft != 0)) {
      // assert(smarktested(encloop->ss));
      sunmarktest(encloop->ss);

      // Check if it is still the same segment when it is tested.
      pa = sorg(encloop->ss);
      pb = sdest(encloop->ss);
      if ((encloop->forg == pa) && (encloop->fdest == pb)) {

        refpt = encloop->foppo;
        if ((refpt == NULL) || getpointtype(refpt) == DEADVERTEX) {
          // Check if this segment can be split.
          assert(0); // Not handled yet.
        }
        // Create a new point in the segment.
        makepoint(&newpt);
        // getsegmentsplitpoint2(&(encloop->ss), refpt, newpt);
        getsegmentsplitpoint3(&(encloop->ss), refpt, newpt);
        setpointtype(newpt, STEINERVERTEX);

        // Decrease the number of allocated Steiner points (-S option).
        if (b->steinerleft != -1) {
          b->steinerleft--;
        }

        // Get an adjacent tet for point location.
        stpivot(encloop->ss, searchtet);

        // Split the segment by newpt. Two new subsegments and new subfaces
        //   are queued in subsegstack and subfacstack for recovery.
        spivot(encloop->ss, splitsh);
        sinsertvertex(newpt, &splitsh, &(encloop->ss), true, false);

        // Insert newpt into the DT. Since the mesh may be a CDT, always
        //   set visflag be true. Some existing egments and subfaces may be
        //   non-Delaunay due to this new vertex, they will be removed from
        //   the mesh, and are queued in subsegstack and subfacstack for
        //   recovery.
        // Newly encroached segments, subfaces, and badly-shaped tets are
        //   queued in badsegpool, badsubpool, and badtetpool, resp.
        insertvertex(newpt, &searchtet, true, true, false, false);

        // Recover missing subsegments.
        assert(subsegstack->objects > 0);
        delaunizesegments();
        // Recover missing subfaces.
        assert(subfacstack->objects > 0);
        constrainedfacets();
      }

      // Deallocate the badface.
      badfacedealloc(badsegpool, encloop);
      // Get the next badface.
      encloop = badfacetraverse(badsegpool);
    } // while (encloop != NULL)

  } // while (badsegpool->items > 0)
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// enforcequality()    Create quality conforming Delaunay mesh.              //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::enforcequality()
{
  face shloop;
  long bakptcount;

  if (!b->quiet) {
    printf("Conforming Delaunay meshing.\n");
  }

  // Initialize the pool for storing encroched segments.
  badsegpool = new memorypool(sizeof(badface), SUBPERBLOCK, POINTER, 0);

  // Initialize arrays.
  tg_crosstets = new arraypool(sizeof(triface), 10);
  tg_topnewtets = new arraypool(sizeof(triface), 10);
  tg_botnewtets = new arraypool(sizeof(triface), 10);
  tg_topfaces = new arraypool(sizeof(triface), 10);
  tg_botfaces = new arraypool(sizeof(triface), 10);
  tg_midfaces = new arraypool(sizeof(triface), 10);
  tg_toppoints = new arraypool(sizeof(point), 8);
  tg_botpoints = new arraypool(sizeof(point), 8);
  tg_facpoints = new arraypool(sizeof(point), 8);
  tg_facfaces = new arraypool(sizeof(face), 10);
  tg_topshells = new arraypool(sizeof(face), 10);
  tg_botshells = new arraypool(sizeof(face), 10);

  // Find all encroached segments.
  subsegpool->traversalinit();
  shloop.sh = shellfacetraverse(subsegpool);
  while (shloop.sh != NULL) {
    checkedge4encroach(shloop, NULL, 1);
    shloop.sh = shellfacetraverse(subsegpool);
  }

  if (b->verbose && (badsegpool->items > 0)) {
    printf("  Splitting encroached segments.\n");
  }
  bakptcount = pointpool->items;

  // Fix encroached segments.
  repairencsegs();
  // At this point, no segments should be encroached.

  if (b->verbose && ((pointpool->items - bakptcount) > 0)) {
    printf("  %ld Steiner points.\n", pointpool->items - bakptcount);
  }

  // Delete arrays.
  delete tg_crosstets;
  delete tg_topnewtets;
  delete tg_botnewtets;
  delete tg_topfaces;
  delete tg_botfaces;
  delete tg_midfaces;
  delete tg_toppoints;
  delete tg_botpoints;
  delete tg_facpoints;
  delete tg_facfaces;
  delete tg_topshells;
  delete tg_botshells;

  delete badsegpool;
}

#endif // #ifndef refineCXX
