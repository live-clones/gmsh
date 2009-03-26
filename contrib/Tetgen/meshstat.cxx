#ifndef meshstatCXX
#define meshstatCXX

#include "tetgen.h"

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Initialize fast look-up tables.                                           //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

int tetgenmesh::ve[6] = { 2, 5, 4, 1, 0, 3 };
int tetgenmesh::ve2[6] = { 4, 3, 0, 5, 2, 1 };

int tetgenmesh::vo[6] = { 0, 1, 1, 2, 2, 0 };
int tetgenmesh::vd[6] = { 1, 0, 2, 1, 0, 2 };
int tetgenmesh::va[6] = { 2, 2, 0, 0, 1, 1 };

int tetgenmesh::verver2zero[6][6] = {
  {0, 0, 2, 2, 4, 4},
  {0, 0, 2, 2, 4, 4},
  {2, 2, 4, 4, 0, 0},
  {2, 2, 4, 4, 0, 0},
  {4, 4, 0, 0, 2, 2},
  {4, 4, 0, 0, 2, 2}
};

int tetgenmesh::ver2zero[6] = {0, 0, 2, 2, 4, 4};

int tetgenmesh::zero2ver[6][6] = {
  {0, 0, 2, 2, 4, 4}, 
  {0, 0, 2, 2, 4, 4},
  {4, 4, 0, 0, 2, 2},
  {4, 4, 0, 0, 2, 2},
  {2, 2, 4, 4, 0, 0},
  {2, 2, 4, 4, 0, 0}
};

int tetgenmesh::locver2org[4][6]  = {
  {0, 1, 1, 2, 2, 0},
  {0, 3, 3, 1, 1, 0},
  {1, 3, 3, 2, 2, 1},
  {2, 3, 3, 0, 0, 2} 
};

int tetgenmesh::locver2dest[4][6] = { 
  {1, 0, 2, 1, 0, 2},
  {3, 0, 1, 3, 0, 1},
  {3, 1, 2, 3, 1, 2},
  {3, 2, 0, 3, 2, 0}
};

int tetgenmesh::locver2apex[4][6] = { 
  {2, 2, 0, 0, 1, 1},
  {1, 1, 0, 0, 3, 3},
  {2, 2, 1, 1, 3, 3},
  {0, 0, 2, 2, 3, 3}
};

int tetgenmesh::loc2oppo[4] = { 3, 2, 0, 1 };

int tetgenmesh::locver2nextf[32] = {
  1, 5, 2, 5, 3, 5, 0, 0,
  3, 3, 2, 1, 0, 1, 0, 0,
  1, 3, 3, 1, 0, 3, 0, 0,
  2, 3, 1, 1, 0, 5, 0, 0
};

int tetgenmesh::locver2edge[4][6] = {
  {0, 0, 1, 1, 2, 2},
  {3, 3, 4, 4, 0, 0},
  {4, 4, 5, 5, 1, 1},
  {5, 5, 3, 3, 2, 2}
};

int tetgenmesh::edge2locver[6][2] = {
  {0, 0}, // 0  v0 -> v1
  {0, 2}, // 1  v1 -> v2
  {0, 4}, // 2  v2 -> v0
  {1, 0}, // 3  v0 -> v3
  {1, 2}, // 4  v1 -> v3
  {2, 2}  // 5  v2 -> v3
};

int tetgenmesh::locpivot[4][3] = {
  {1, 2, 3},
  {0, 2, 3},
  {0, 1, 3},
  {0, 1, 2}
};

int tetgenmesh::locverpivot[4][6][2] = {
  {{2, 3}, {2, 3}, {1, 3}, {1, 3}, {1, 2}, {1, 2}},
  {{0, 2}, {0, 2}, {0, 3}, {0, 3}, {2, 3}, {2, 3}},
  {{0, 3}, {0, 3}, {0, 1}, {0, 1}, {1, 3}, {1, 3}},
  {{0, 1}, {0, 1}, {0, 2}, {0, 2}, {1, 2}, {1, 2}}
};

int tetgenmesh::mi1mo3[3] = {2, 0, 1};

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// checkmesh()    Test mesh for geometrical and topological consistencies.   //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::checkmesh()
{
  triface tetloop;
  triface neightet, symtet;
  point pa, pb, pc, pd;
  REAL ori;
  int horrors;

  if (!b->quiet) {
    printf("  Checking consistency of mesh...\n");
  }

  horrors = 0;
  tetloop.ver = 0;
  // Run through the list of tetrahedra, checking each one.
  tetrahedronpool->traversalinit();
  tetloop.tet = tetrahedrontraverse();
  while (tetloop.tet != (tetrahedron *) NULL) {
    // Check all four faces of the tetrahedron.
    for (tetloop.loc = 0; tetloop.loc < 4; tetloop.loc++) {
      pa = org(tetloop);
      pb = dest(tetloop);
      pc = apex(tetloop);
      pd = oppo(tetloop);
      if (tetloop.loc == 0) {  // Only test for inversion once.
        if (pd != dummypoint) {  // Only do test if it is not a hull tet.
          ori = orient3d(pa, pb, pc, pd);
          if (ori >= 0.0) {
            printf("  !! !! %s ", ori > 0.0 ? "Inverted" : "Degenerated");
            printf("  (%d, %d, %d, %d) (ori = %.17g)\n", pointmark(pa),
              pointmark(pb), pointmark(pc), pointmark(pd), ori);
            horrors++;
          }
        }
        if (infected(tetloop)) {
          printf("  !! (%d, %d, %d, %d) is infected.\n", pointmark(pa),
            pointmark(pb), pointmark(pc), pointmark(pd));
        }
        if (marktested(tetloop)) {
          printf("  !! (%d, %d, %d, %d) is marked.\n", pointmark(pa),
            pointmark(pb), pointmark(pc), pointmark(pd));
        }
      }
      if (tetloop.tet[tetloop.loc] == NULL) {
        printf("  !! !! No neighbor at face (%d, %d, %d).\n", pointmark(pa),
            pointmark(pb), pointmark(pc));
        horrors++;
      } else {
        // Find the neighboring tetrahedron on this face.
        symedge(tetloop, neightet);
        // Check that the tetrahedron's neighbor knows it's a neighbor.
        sym(neightet, symtet);
        if ((tetloop.tet != symtet.tet) || (tetloop.loc != symtet.loc)) {
          printf("  !! !! Asymmetric tetra-tetra bond:\n");
          if (tetloop.tet == symtet.tet) {
            printf("   (Right tetrahedron, wrong orientation)\n");
          }
          printf("    First:  (%d, %d, %d, %d)\n", pointmark(pa),
            pointmark(pb), pointmark(pc), pointmark(pd));
          printf("    Second: (%d, %d, %d, %d)\n", pointmark(org(neightet)),
            pointmark(dest(neightet)), pointmark(apex(neightet)),
            pointmark(oppo(neightet)));
          horrors++;
        }
        // Check if they have the same edge (the bond() operation).
        if ((org(neightet) != pb) || (dest(neightet) != pa)) {
          printf("  !! !! Wrong edge-edge bond:\n");
          printf("    First:  (%d, %d, %d, %d)\n", pointmark(pa),
            pointmark(pb), pointmark(pc), pointmark(pd));
          printf("    Second: (%d, %d, %d, %d)\n", pointmark(org(neightet)),
            pointmark(dest(neightet)), pointmark(apex(neightet)),
            pointmark(oppo(neightet)));
          horrors++;
        }
        // Check if they have the same opposite.
        if (oppo(neightet) == pd) {
          printf("  !! !! Two identical tetra:\n");
          printf("    First:  (%d, %d, %d, %d)\n", pointmark(pa),
            pointmark(pb), pointmark(pc), pointmark(pd));
          printf("    Second: (%d, %d, %d, %d)\n", pointmark(org(neightet)),
            pointmark(dest(neightet)), pointmark(apex(neightet)),
            pointmark(oppo(neightet)));
          horrors++;
        }
      }
    }
    tetloop.tet = tetrahedrontraverse();
  }
  if (horrors == 0) {
    if (!b->quiet) {
      printf("  In my studied opinion, the mesh appears to be consistent.\n");
    }
  } else {
    printf("  !! !! !! !! %d %s witnessed.\n", horrors, 
      horrors > 1 ? "abnormity" : "abnormities");
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// checkshells()    Test the surface mesh for consistencies.                 //
//                                                                           //
// If 'sub2tet' > 0, it also checks the subface-to-tet connections.          //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

int tetgenmesh::checkshells(int sub2tet)
{
  triface neightet, symtet;
  face shloop, spinsh, nextsh;
  face checkseg;
  point pa, pb;
  int horrors, i;

  tetrahedron ptr;

  if (!b->quiet) {
    printf("  Checking consistency of the mesh boundary...\n");
  }
  horrors = 0;

  void **bakpathblock = subfacepool->pathblock;
  void *bakpathitem = subfacepool->pathitem;
  int bakpathitemsleft = subfacepool->pathitemsleft;
  int bakalignbytes = subfacepool->alignbytes;

  subfacepool->traversalinit();
  shloop.sh = shellfacetraverse(subfacepool);
  while (shloop.sh != NULL) {
    shloop.shver = 0;
    for (i = 0; i < 3; i++) {
      // Check the face ring at this edge.
      pa = sorg(shloop);
      pb = sdest(shloop);
      spinsh = shloop;
      spivot(spinsh, nextsh);
      while ((nextsh.sh != NULL) && (nextsh.sh != shloop.sh)) {
        // check if they have the same edge.
        if (!((sorg(nextsh) == pa) && (sdest(nextsh) == pb) ||
             (sorg(nextsh) == pb) && (sdest(nextsh) == pa))) {
           printf("  !! !! Wrong subface-subface connection.\n");
           printf("    First: x%lx (%d, %d, %d).\n", (unsigned long) spinsh.sh,
             pmark(sorg(spinsh)), pmark(sdest(spinsh)), pmark(sapex(spinsh)));
           printf("    Scond: x%lx (%d, %d, %d).\n", (unsigned long) nextsh.sh,
             pmark(sorg(nextsh)), pmark(sdest(nextsh)), pmark(sapex(nextsh)));
           horrors++;
        }
        spinsh = nextsh;
        spivot(spinsh, nextsh);
      }
      // Check subface-subseg bond.
      sspivot(shloop, checkseg);
      if (checkseg.sh != NULL) {
        if (!((sorg(checkseg) == pa) && (sdest(checkseg) == pb) ||
             (sorg(checkseg) == pb) && (sdest(checkseg) == pa))) {
          printf("  !! !! Wrong subface-subseg connection.\n");
          printf("    Sub: x%lx (%d, %d, %d).\n", (unsigned long) shloop.sh,
            pmark(sorg(shloop)), pmark(sdest(shloop)), pmark(sapex(shloop)));
          printf("    Seg: x%lx (%d, %d).\n", (unsigned long) checkseg.sh,
            pmark(sorg(checkseg)), pmark(sdest(checkseg)));
          horrors++;
        }
      }
      senextself(shloop);
    }
    if (sub2tet > 0) {
      // Check the tet-subface connections.
      stpivot(shloop, neightet);
      if (neightet.tet != NULL) {
        tspivot(neightet, spinsh);
        if (spinsh.sh != shloop.sh) {
          printf("  !! !! Wrong connection betwee tet and subface.\n");
          printf("    Sub: x%lx (%d, %d, %d).\n", (unsigned long) shloop.sh,
            pmark(sorg(shloop)), pmark(sdest(shloop)), pmark(sapex(shloop)));
          printf("    Tet: x%lx (%d, %d, %d, %d).\n", 
            (unsigned long) neightet.tet, pmark(org(neightet)), 
            pmark(dest(neightet)), pmark(apex(neightet)), 
            pmark(oppo(neightet)));
          horrors++;
        } else {
          symself(neightet);
          tspivot(neightet, spinsh);
          if (spinsh.sh != shloop.sh) {
            printf("  !! !! Wrong connection betwee tet and subface.\n");
            printf("    Sub: x%lx (%d, %d, %d).\n", (unsigned long) shloop.sh,
              pmark(sorg(shloop)), pmark(sdest(shloop)), pmark(sapex(shloop)));
            printf("    Tet: x%lx (%d, %d, %d, %d).\n", 
              (unsigned long) neightet.tet, pmark(org(neightet)), 
              pmark(dest(neightet)), pmark(apex(neightet)), 
              pmark(oppo(neightet)));
            horrors++;
          }
        }
      } else {
        // printf("  !! A dangling subface.\n");
        // printf("    Sub: x%lx (%d, %d, %d).\n", (unsigned long) shloop.sh,
        //   pmark(sorg(shloop)), pmark(sdest(shloop)), pmark(sapex(shloop)));
        // horrors++;
      }
    }
    shloop.sh = shellfacetraverse(subfacepool);
  }

  if (horrors == 0) {
    if (!b->quiet) {
      printf("  Mesh boundaries connected correctly.\n");
    }
  } else {
    printf("  !! !! !! !! %d boundary connection viewed with horror.\n",
           horrors);
  }

  subfacepool->pathblock = bakpathblock;
  subfacepool->pathitem = bakpathitem;
  subfacepool->pathitemsleft = bakpathitemsleft;
  subfacepool->alignbytes = bakalignbytes;

  return horrors;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// checkdelaunay()    Ensure that the mesh is (constrained) Delaunay.        //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

int tetgenmesh::checkdelaunay(int constrained)
{
  triface tetloop;
  triface symtet;
  face checksh;
  point pa, pb, pc, pd, pe;
  REAL sign;
  int horrors;

  if (!b->quiet) {
    printf("  Checking %s property of the mesh...\n",  constrained > 0 ? 
      "constrained Delaunay" : "Delaunay");
  }
  
  horrors = 0;
  tetloop.ver = 0;
  // Run through the list of triangles, checking each one.
  tetrahedronpool->traversalinit();
  tetloop.tet = tetrahedrontraverse();
  while (tetloop.tet != (tetrahedron *) NULL) {
    // Check all four faces of the tetrahedron.
    for (tetloop.loc = 0; tetloop.loc < 4; tetloop.loc++) {
      sym(tetloop, symtet);
      // Only do test if its adjoining tet is not a hull tet or its pointer
      //   is larger (to ensure that each pair isn't tested twice).
      if (((point) symtet.tet[7] != dummypoint)&&(tetloop.tet < symtet.tet)) {
        pa = org(tetloop);
        pb = dest(tetloop);
        pc = apex(tetloop);
        pd = oppo(tetloop);
        pe = oppo(symtet);
        sign = insphere_sos(pa, pb, pc, pd, pe);
        if (sign < 0.0) {
          if (constrained > 0) {
            tspivot(tetloop, checksh);
          }
          if ((constrained == 0) || 
             ((constrained > 0) && (checksh.sh == NULL))) {
            printf("  !! Non-locally Delaunay (%d, %d, %d) - %d, %d\n",
              pointmark(pa), pointmark(pb), pointmark(pc), pointmark(pd),
              pointmark(pe));
            horrors++;
          }
        }
      }
    }
    tetloop.tet = tetrahedrontraverse();
  }

  if (horrors == 0) {
    if (!b->quiet) {
      printf("  The mesh is %s.\n", constrained > 0 ? "constrained Delaunay" 
        : "Delaunay");
    }
  } else {
    printf("  !! !! !! !! Found %d non-Delaunay faces.\n", horrors);
  }

  return horrors;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// checksegments()    Check the connections between tetrahedra and segments. //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

int tetgenmesh::checksegments()
{
  triface tetloop, neightet;
  shellface *segs;
  face sseg, checkseg;
  point pa, pb;
  int horrors, i;

  if (!b->quiet) {
    printf("  Checking tet-seg connections...\n");
  }

  horrors = 0;
  tetrahedronpool->traversalinit();
  tetloop.tet = tetrahedrontraverse();
  while (tetloop.tet != NULL) {
    // Loop the six edges of the tet.
    if (tetloop.tet[8] != NULL) {
      segs = (shellface *) tetloop.tet[8];
      for (i = 0; i < 6; i++) {
        sdecode(segs[i], sseg);
        if (sseg.sh != NULL) {
          // Get the edge of the tet.
          tetloop.loc = edge2locver[i][0];
          tetloop.ver = edge2locver[i][1];
          // Check if they are the same edge.
          pa = (point) sseg.sh[3];
          pb = (point) sseg.sh[4];
          if (!(((org(tetloop) == pa) && (dest(tetloop) == pb)) ||
                ((org(tetloop) == pb) && (dest(tetloop) == pa)))) {
            printf("  !! Wrong tet-seg connection.\n");
            printf("    Tet: x%lx (%d, %d, %d, %d) - Seg: x%lx (%d, %d).\n", 
              (unsigned long) tetloop.tet, pointmark(org(tetloop)),
              pointmark(dest(tetloop)), pointmark(apex(tetloop)),
              pointmark(oppo(tetloop)), (unsigned long) sseg.sh,
              pointmark(pa), pointmark(pb));
            horrors++;
          } else {
            // Loop all tets sharing at this edge.
            neightet = tetloop;
            do {
              tsspivot(neightet, checkseg);
              if (checkseg.sh != sseg.sh) {
                printf("  !! Wrong tet-seg connection.\n");
                printf("    Tet: x%lx (%d, %d, %d, %d) - ", 
                  (unsigned long) tetloop.tet, pointmark(org(tetloop)),
                  pointmark(dest(tetloop)), pointmark(apex(tetloop)),
                  pointmark(oppo(tetloop)));
                if (checkseg.sh != NULL) {
                  printf("Seg x%lx (%d, %d).\n", (unsigned long) checkseg.sh,
                  pointmark(sorg(checkseg)), pointmark(sdest(checkseg))); 
                } else {
                  printf("Seg: NULL.\n");
                }
                horrors++;
              }
              fnextself(neightet);
            } while (neightet.tet != tetloop.tet);
          }
        }
      }
    }
    tetloop.tet = tetrahedrontraverse();
  }

  if (horrors == 0) {
    printf("  Segments are connected properly.\n");
  } else {
    printf("  !! !! !! !! Found %d missing connections.\n", horrors);
  }

  return horrors;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// algorithmstatistics()    Report algorithmic performances.                 //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::algorithmstatistics()
{
  /*// Report memory usages.
    unsigned long totalmeshbytes;
    printf("Memory allocation statistics:\n\n");
    printf("  Maximum number of vertices: %ld\n", pointpool->maxitems);
    totalmeshbytes = pointpool->maxitems * pointpool->itembytes;
    printf("  Maximum number of tetrahedra: %ld\n", tetrahedronpool->maxitems);
    totalmeshbytes += tetrahedronpool->maxitems * tetrahedronpool->itembytes;
    if (subfacepool != (memorypool *) NULL) {
      printf("  Maximum number of subfaces: %ld\n", subfacepool->maxitems);
      totalmeshbytes += subfacepool->maxitems * subfacepool->itembytes;
    }
    if (subsegpool != (memorypool *) NULL) {
      printf("  Maximum number of segments: %ld\n", subsegpool->maxitems);
      totalmeshbytes += subsegpool->maxitems * subsegpool->itembytes;
    }
    printf("  Heap memory used by the mesh (K bytes): %g\n\n",
           ((double) totalmeshbytes) / 1024.0);
  */

  printf("Algorithmic statistics:\n\n");

  printf("  Number of orient3d tests: %ld\n", orient3dcount);
  printf("  Number of insphere tests: %ld\n", inspherecount);
  printf("  Number of symbolic insphere tests: %ld\n", insphere_sos_count);
  printf("  Number of visited tets in point location: %ld\n", ptloc_count);
  printf("  Maximal number of tets per point location: %ld\n",ptloc_max_count);
  printf("  Number of 1-to-4 flips: %ld\n", flip14count);
  printf("  Number of 2-to-6 flips: %ld\n", flip26count);
  printf("  Number of n-t-2n flips: %ld\n", flipn2ncount);

  if (!b->plc) {
    if (b->bowyerwatson) {
      printf("  Number of deleted tets: %ld\n", totaldeadtets);
      printf("  Number of created tets: %ld\n", totalbowatcavsize);
      printf("  Maximum number of tets per new point: %ld\n", maxbowatcavsize);
      printf("  Number of 3-to-2 flips: %ld\n", flip32count);
    } else {
      printf("  Number of 3-to-2 flips: %ld\n", flip32count);
      printf("  Number of 2-to-3 flips: %ld\n", flip23count);
      printf("  Number of n-to-m flips: %ld\n", flipnmcount);
      printf("  Total number of primitive flips: %ld\n",
        flip23count + flip32count);
    }
  }

  if (b->plc) {
    printf("  Number of 2-to-2 flips: %ld\n", flip22count);
    printf("  Number of tri-edge inter (coplanar) tests: %ld (%ld)\n",
      triedgcount, triedgcopcount);
    printf("  Number of crossed faces (edges) in scout segs: %ld (%ld)\n",
      across_face_count, across_edge_count);
    printf("  Maximal number of crossed faces per segment: %ld\n",
      across_max_count);
    printf("  Number of rule-1 points: %ld\n", r1count);
    printf("  Number of rule-2 points: %ld\n", r2count);
    printf("  Number of rule-3 points: %ld\n", r3count);
    printf("  Maximal size of a missing region: %ld\n", maxregionsize);
    printf("  Maximal size of a recovered cavity: %ld\n", maxcavsize);
    printf("  Number of non-Delaunay edges: %ld\n", ndelaunayedgecount);
    printf("  Number of cavity expansions: %ld\n", cavityexpcount);
  }
  
  // printf("  Total point location time (millisec):  %g\n", tloctime * 1e+3);
  // printf("  Total point insertion time (millisec):  %g\n",tinserttime*1e+3);
  // if (b->bowyerwatson == 0) {
  //   printf("  Total flip time (millisec):  %g\n", tfliptime * 1e+3);
  // }

  printf("\n");
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// statistics()    Print all sorts of cool facts.                            //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::statistics()
{
  long tetnumber, facenumber;

  printf("\nStatistics:\n\n");
  printf("  Input points: %d\n", in->numberofpoints);
  if (b->refine) {
    printf("  Input tetrahedra: %d\n", in->numberoftetrahedra);
  }
  if (b->plc) {
    printf("  Input facets: %d\n", in->numberoffacets);
    printf("  Input segments: %ld\n", insegments);
    printf("  Input holes: %d\n", in->numberofholes);
    printf("  Input regions: %d\n", in->numberofregions);
  }

  tetnumber = tetrahedronpool->items - hullsize;
  facenumber = (tetnumber * 4l + hullsize) / 2l;

  printf("\n  Mesh points: %ld\n", pointpool->items);
  printf("  Mesh tetrahedra: %ld\n", tetnumber);
  printf("  Mesh faces: %ld\n", facenumber);
  printf("  Mesh edges: %ld\n", meshedges);

  if (b->plc || b->refine) {
    printf("  Mesh boundary faces: %ld\n", subfacepool->items);
    printf("  Mesh boundary edges: %ld\n", meshsubedges);
    printf("  Mesh subsegments: %ld\n", subsegpool->items);
  } else {
    printf("  Convex hull faces: %ld\n", hullsize);
  }
  printf("\n");

  if (b->verbose > 0) {
    printf("  Euler characteristic of mesh domain: %ld\n", pointpool->items 
      - meshedges + facenumber - tetnumber);
    printf("  Euler characteristic of boundary: %ld\n", pointpool->items 
      - meshsubedges + subfacepool->items);
    printf("\n");
  }

  if (b->verbose > 0) {
    // qualitystatistics();
    algorithmstatistics();
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// terminatetetgen()    Terminate TetGen with a given exit code.             //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void terminatetetgen(int x)
{
#ifdef TETLIBRARY
  throw x;
#else
  exit(x);
#endif // #ifdef TETLIBRARY
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Debug functions.                                                          //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Print the detail informations of a tetrahedron.

void tetgenmesh::ptet(triface* t)
{
  triface tmpface, prtface;
  shellface *shells;
  face checksh;
  point *pts, tmppt;
  REAL ori;
  int facecount;

  printf("Tetra x%lx with loc(%i) ver(%i):",
         (unsigned long)(t->tet), t->loc, t->ver);
  if (t->tet == NULL) {
    printf("  !! NOT A VALID HANDLE\n");
    return;
  }
  pts = (point *) t->tet;
  if (pts[4] == NULL) {
    printf("  !! A DEAD TET\n");
    return;
  }
  if (pts[7] != dummypoint) {
    ori = orient3d(pts[4], pts[5], pts[6], pts[7]);
    printf("  ori = %g.\n", ori);
  } else {
    printf("  (hull tet).\n");
  }
  // Report the status of this tet.
  printf("      ");
  if (infected(*t)) {
    printf("(infected) ");
  }
  if (marktested(*t)) {
    printf("(marktested) ");
  }
  if (edgemarked(*t)) {
    printf("(edgemarked) ");
  }
  if (b->regionattrib) {
    printf("attr(%d)", elemattribute(t->tet, 0));
  }
  printf("\n");

  tmpface = *t;
  facecount = 0;
  while(facecount < 4) {
    tmpface.loc = facecount;
    sym(tmpface, prtface);
    if (prtface.tet == NULL) {
      printf("      [%i] Open !!\n", facecount);
    } else {
      printf("      [%i] x%lx  loc(%i) ver(%i)", facecount,
             (unsigned long)(prtface.tet), prtface.loc, prtface.ver);
      if ((point) prtface.tet[7] == dummypoint) {
        printf("  (hull tet)");
      }
      if (infected(prtface)) {
        printf(" (infected)");
      }
      printf("\n");
    }
    facecount++;
  }

  tmppt = org(*t);
  if(tmppt == (point) NULL) {
    printf("      Org [%i] NULL\n", locver2org[t->loc][t->ver]);
  } else {
    printf("      Org [%i] x%lx (%.12g,%.12g,%.12g) %d\n",
           locver2org[t->loc][t->ver], (unsigned long)(tmppt),
           tmppt[0], tmppt[1], tmppt[2], pointmark(tmppt));
  }
  tmppt = dest(*t);
  if(tmppt == (point) NULL) {
    printf("      Dest[%i] NULL\n", locver2dest[t->loc][t->ver]);
  } else {
    printf("      Dest[%i] x%lx (%.12g,%.12g,%.12g) %d\n",
           locver2dest[t->loc][t->ver], (unsigned long)(tmppt),
           tmppt[0], tmppt[1], tmppt[2], pointmark(tmppt));
  }
  tmppt = apex(*t);
  if(tmppt == (point) NULL) {
    printf("      Apex[%i] NULL\n", locver2apex[t->loc][t->ver]);
  } else {
    printf("      Apex[%i] x%lx (%.12g,%.12g,%.12g) %d\n",
           locver2apex[t->loc][t->ver], (unsigned long)(tmppt),
           tmppt[0], tmppt[1], tmppt[2], pointmark(tmppt));
  }
  tmppt = oppo(*t);
  if(tmppt == (point) NULL) {
    printf("      Oppo[%i] NULL\n", loc2oppo[t->loc]);
  } else {
    printf("      Oppo[%i] x%lx (%.12g,%.12g,%.12g) %d\n",
           loc2oppo[t->loc], (unsigned long)(tmppt),
           tmppt[0], tmppt[1], tmppt[2], pointmark(tmppt));
  }

  if (checksubsegs) {
    if (t->tet[8] != NULL) {
      shells = (shellface *) t->tet[8];
      for (facecount = 0; facecount < 6; facecount++) {
        sdecode(shells[facecount], checksh);
        if (checksh.sh != NULL) {
          printf("      [%d] x%lx %d.", facecount, (unsigned long) checksh.sh,
            checksh.shver);
        } else {
          printf("      [%d] NULL.", facecount);
        }
        if (locver2edge[t->loc][t->ver] == facecount) {
          printf(" (*)");  // It is the current edge.
        }
        printf("\n");
      }
    }
  }

  if (checksubfaces) {
    if (t->tet[9] != NULL) {
      shells = (shellface *) t->tet[9];
      for (facecount = 0; facecount < 4; facecount++) {
        sdecode(shells[facecount], checksh);
        if (checksh.sh != NULL) {
          printf("      [%d] x%lx %d.", facecount, (unsigned long) checksh.sh,
            checksh.shver);
        } else {
          printf("      [%d] NULL.", facecount);
        }
        if (t->loc == facecount) {
          printf(" (*)");  // It is the current face.
        }
        printf("\n");
      }
    }
  }
}

///////////////////////////////////////////////////////////////////////////////
// Print the detail informations of a shellface.

void tetgenmesh::psh(face *s)
{
  face prtsh;
  triface prttet;
  point *pt, printpoint;
  REAL n[3];

  if (s->sh == NULL) {
    printf("Not a handle.\n");
    return;
  }

  if (s->sh[3] == NULL) {
    printf("A dead subface x%lx.\n", (unsigned long)(s->sh));
    return;
  }

  pt = (point *) s->sh;
  if (s->sh[5] != NULL) {
    printf("subface x%lx, ver %d, mark %d:\n",(unsigned long)(s->sh),s->shver,
      getshellmark(*s));
    facenormal(pt[3], pt[4], pt[5], n, 1);
    printf("      area %g, edge lengths %g %g %g\n", 0.5 * sqrt(DOT(n, n)),
      DIST(pt[3], pt[4]), DIST(pt[4], pt[5]), DIST(pt[5], pt[3]));
  } else {
    printf("Subsegment x%lx, ver %d, mark %d:\n", (unsigned long)(s->sh),
      s->shver, getshellmark(*s));
    printf("      length %g", DIST(pt[3], pt[4]));
  }
  if (sinfected(*s)) {
    printf(" (infected)");
  }
  if (smarktested(*s)) {
    printf(" (marked)");
  }
  // if (shell2badface(*sface)) {
  //   printf(" (queued)");
  // }
  // if (checkpbcs) {
  //   if (shellpbcgroup(*sface) >= 0) {
  //     printf(" (pbc %d)", shellpbcgroup(*sface));
  //   }
  // }
  printf("\n");

  sdecode(s->sh[0], prtsh);
  if (prtsh.sh == NULL) {
    printf("      [0] = No shell\n");
  } else {
    printf("      [0] = x%lx  %d\n", (unsigned long)(prtsh.sh), prtsh.shver);
  }
  sdecode(s->sh[1], prtsh);
  if (prtsh.sh == NULL) {
    printf("      [1] = No shell\n");
  } else {
    printf("      [1] = x%lx  %d\n", (unsigned long)(prtsh.sh), prtsh.shver);
  }
  sdecode(s->sh[2], prtsh);
  if (prtsh.sh == NULL) {
    printf("      [2] = No shell\n");
  } else {
    printf("      [2] = x%lx  %d\n", (unsigned long)(prtsh.sh), prtsh.shver);
  }

  printpoint = sorg(*s);
  if (printpoint == (point) NULL)
    printf("      Org [%d] = NULL\n", vo[s->shver]);
  else
    printf("      Org [%d] = x%lx  (%.12g,%.12g,%.12g) %d\n",
           vo[s->shver], (unsigned long)(printpoint), printpoint[0],
           printpoint[1], printpoint[2], pointmark(printpoint));
  printpoint = sdest(*s);
  if (printpoint == (point) NULL)
    printf("      Dest[%d] = NULL\n", vd[s->shver]);
  else
    printf("      Dest[%d] = x%lx  (%.12g,%.12g,%.12g) %d\n",
           vd[s->shver], (unsigned long)(printpoint), printpoint[0],
           printpoint[1], printpoint[2], pointmark(printpoint));

  printpoint = sapex(*s);
  if (printpoint == (point) NULL)
    printf("      Apex[%d] = NULL\n", va[s->shver]);
  else
    printf("      Apex[%d] = x%lx  (%.12g,%.12g,%.12g) %d\n",
           va[s->shver], (unsigned long)(printpoint), printpoint[0],
           printpoint[1], printpoint[2], pointmark(printpoint));

  if (s->sh[5] != NULL) {
    sdecode(s->sh[6], prtsh);
    if (prtsh.sh == NULL) {
      printf("      [6] = No subsegment\n");
    } else {
      printf("      [6] = x%lx  %d\n", (unsigned long) prtsh.sh, prtsh.shver);
    }
    sdecode(s->sh[7], prtsh);
    if (prtsh.sh == NULL) {
      printf("      [7] = No subsegment\n");
    } else {
      printf("      [7] = x%lx  %d\n", (unsigned long) prtsh.sh, prtsh.shver);
    }
    sdecode(s->sh[8], prtsh);
    if (prtsh.sh == NULL) {
      printf("      [8] = No subsegment\n");
    } else {
      printf("      [8] = x%lx  %d\n", (unsigned long) prtsh.sh, prtsh.shver);
    }

    decode(s->sh[9], prttet);
    if (prttet.tet == NULL) {
      printf("      [9] = Outer space\n");
    } else {
      printf("      [9] = x%lx  %d\n",(unsigned long) prttet.tet, prttet.loc);
    }
  }
}

///////////////////////////////////////////////////////////////////////////////
// Find and print the tetrahedron (or face or edge) with the given indices.
// Do not handle 'dummypoint' (-1).

void tetgenmesh::pteti(int i, int j, int k, int l)
{
  triface t;
  point *pts;
  int *marklist;
  int ii;

  marklist = new int[pointpool->items + 1];
  for (ii = 0; ii < pointpool->items + 1; ii++) marklist[ii] = 0;
  // Marke the given indices. 
  marklist[i] = marklist[j] = marklist[k] = marklist[l] = 1;

  t.loc = t.ver = 0;
  tetrahedronpool->traversalinit();
  t.tet = tetrahedrontraverse();
  while (t.tet != NULL) {
    pts = (point *) t.tet;
    if (pts[7] != dummypoint) {
      if ((marklist[pointmark(pts[4])] + marklist[pointmark(pts[5])] +
           marklist[pointmark(pts[6])] + marklist[pointmark(pts[7])]) == 4) {
        ptet(&t);  // Find!
        break;
      }
    }
    t.tet = tetrahedrontraverse();
  }
  
  if (t.tet == NULL) {
    printf("  !! Not exist.\n");
  }
  delete [] marklist;
}

void tetgenmesh::pface(int i, int j, int k)
{
  triface t, t1;
  point *pts;
  REAL sign;
  int *marklist;
  int ii;

  marklist = new int[pointpool->items + 1];
  for (ii = 0; ii < pointpool->items + 1; ii++) marklist[ii] = 0;
  // Marke the given indices. 
  marklist[i] = marklist[j] = marklist[k] = 1;

  t.ver = t1.ver = 0;
  tetrahedronpool->traversalinit();
  t.tet = tetrahedrontraverse();
  while (t.tet != NULL) {
    pts = (point *) t.tet;
    if (pts[7] != dummypoint) {
      if ((marklist[pointmark(pts[4])] + marklist[pointmark(pts[5])] +
           marklist[pointmark(pts[6])] + marklist[pointmark(pts[7])]) == 3) {
        // Find a tet containing the search face.
        for (t.loc = 0; t.loc < 4; t.loc++) {
          sym(t, t1);
          pts = (point *) t1.tet;
          if ((marklist[pointmark(pts[4])] + marklist[pointmark(pts[5])] +
              marklist[pointmark(pts[6])] + 
              (pts[7] != dummypoint ? marklist[pointmark(pts[7])] : 0)) == 3)
            break;
        }
        assert(t.loc < 4);
        // Now t and t1 share the face.
        printf("  tet x%lx (%d, %d, %d, %d) %d\n", (unsigned long) t.tet,
          pointmark(org(t)), pointmark(dest(t)), pointmark(apex(t)), 
          pointmark(oppo(t)), t.loc);
        printf("  tet x%lx (%d, %d, %d, %d) %d\n", (unsigned long) t1.tet,
          pointmark(org(t1)), pointmark(dest(t1)), pointmark(apex(t1)),
          pointmark(oppo(t1)), t1.loc);
        if ((point) t1.tet[7] != dummypoint) {
          pts = (point *) t.tet;
          sign = insphere(pts[4], pts[5], pts[6], pts[7], oppo(t1));
          printf("  %s (sign = %.g).\n", sign > 0 ? "Delaunay" :
            (sign < 0 ? "Non-Delaunay" : "Cosphere"), sign);
          if (sign == 0) {
            sign = insphere_sos(pts[4], pts[5], pts[6], pts[7], oppo(t1));
            printf("  %s (symbolic).\n", sign > 0 ? "Delaunay":"Non-Delaunay");
          }
        }
        break;
      }
    }
    t.tet = tetrahedrontraverse();
  }
  
  if (t.tet == NULL) {
    printf("  !! Not exist.\n");
  }
  delete [] marklist;
}

bool tetgenmesh::pedge(int i, int j)
{
  triface t, t1;
  face ssub, sseg;
  int ii;

  t.ver = t1.ver = 0;
  tetrahedronpool->traversalinit();
  t.tet = tetrahedrontraverse();
  while (t.tet != NULL) {
    for (ii = 0; ii < 6; ii++) {
      t.loc = edge2locver[ii][0];
      t.ver = edge2locver[ii][1];
      if ((pointmark(org(t)) == i && pointmark(dest(t)) == j) ||
          (pointmark(org(t)) == j && pointmark(dest(t)) == i)) break;
    }
    if (ii < 6) {
      // Now t is the edge (i, j). Find all tets at (i, j).
      t1 = t;
      do {
        printf("  tet x%lx (%d, %d, %d, %d)", (unsigned long) t1.tet,
          pointmark(org(t1)), pointmark(dest(t1)), pointmark(apex(t1)), 
          pointmark(oppo(t1)));
        if (checksubsegs) {
          tsspivot(t1, sseg);
          if (sseg.sh != NULL) {
            printf(" (seg)");
          }
        }
        if (checksubfaces) {
          tspivot(t1, ssub);
          if (ssub.sh != NULL) {
            printf(" (sub)");
          }
        } 
        if (edgemarked(t1)) {
          printf(" (marked)");
        }
        printf("\n");
        // Go to the next tet.
        fnextself(t1);
      } while (t1.tet != t.tet);
      break;
    }
    t.tet = tetrahedrontraverse();
  }
  
  if (t.tet == NULL) {
    printf("  !! Not exist.\n");
  }
  return t.tet != NULL;
}

///////////////////////////////////////////////////////////////////////////////
// Find the subface with indices (i, j, k)

void tetgenmesh::psubface(int i, int j, int k)
{
  triface t, t1;
  face s, s1;
  point *pts;
  REAL n[3], sign;
  int *marklist;
  int ii;

  void **bakpathblock = subfacepool->pathblock;
  void *bakpathitem = subfacepool->pathitem;
  int bakpathitemsleft = subfacepool->pathitemsleft;
  int bakalignbytes = subfacepool->alignbytes;

  marklist = new int[pointpool->items + 1];
  for (ii = 0; ii < pointpool->items + 1; ii++) marklist[ii] = 0;
  // Marke the given indices. 
  marklist[i] = marklist[j] = marklist[k] = 1;

  s.shver = 0;
  subfacepool->traversalinit();
  s.sh = shellfacetraverse(subfacepool);
  while (s.sh != NULL) {
    pts = (point *) s.sh;
    if (pts[3] != NULL) {
      if ((marklist[pointmark(pts[3])] + marklist[pointmark(pts[4])] +
           marklist[pointmark(pts[5])]) == 3) {
        // Found.
        printf("  sub x%lx (%d, %d, %d) mark=%d\n", (unsigned long) s.sh,
          pointmark(pts[3]), pointmark(pts[4]), pointmark(pts[5]),
          getshellmark(s));
        facenormal(pts[3], pts[4], pts[5], n, 1);
        printf("    area=%g, lengths: %g, %g, %g\n", 0.5 * sqrt(DOT(n, n)),
          DIST(pts[3], pts[4]), DIST(pts[4], pts[5]), DIST(pts[5], pts[3]));
        // Print coplanar adjacent subfaces.
        s.shver = 0;
        for (ii = 0; ii < 3; ii++) {
          sspivot(s, s1);
          if (s1.sh != NULL) {
            printf("  seg x%lx (%d, %d)\n", (unsigned long) s1.sh, 
              pointmark(sorg(s1)), pointmark(sdest(s1)));
          } else {
            spivot(s, s1);
            if (s1.sh != NULL) {
              printf("  sub x%lx (%d, %d, %d)\n", (unsigned long) s1.sh, 
          pointmark(sorg(s1)), pointmark(sdest(s1)), pointmark(sapex(s1)));
            } else {
              printf("  No seg and sub at (%d, %d)!\n", pointmark(sorg(s)), 
                pointmark(sdest(s)));
            }
          }
          senextself(s);
        }
        stpivot(s, t);
        if (t.tet != NULL) {
          // Print two adjacent tets.
          symedge(t, t1);
          // Now t and t1 share the face.
          printf("  tet x%lx (%d, %d, %d, %d) %d\n", (unsigned long) t.tet,
            pointmark(org(t)), pointmark(dest(t)), pointmark(apex(t)), 
            pointmark(oppo(t)), t.loc);
          printf("  tet x%lx (%d, %d, %d, %d) %d\n", (unsigned long) t1.tet,
            pointmark(org(t1)), pointmark(dest(t1)), pointmark(apex(t1)),
            pointmark(oppo(t1)), t1.loc);
          if (((point) t1.tet[7] != dummypoint) && 
              ((point) t.tet[7] != dummypoint)) {
            pts = (point *) t.tet;
            sign = insphere(pts[4], pts[5], pts[6], pts[7], oppo(t1));
            printf("  %s (sign = %.g).\n", sign > 0 ? "Delaunay" :
              (sign < 0 ? "Non-Delaunay" : "Cosphere"), sign);
            if (sign == 0) {
            sign = insphere_sos(pts[4], pts[5], pts[6], pts[7], oppo(t1));
            printf("  %s (symbolic).\n", sign > 0 ? "Delaunay":"Non-Delaunay");
            }
          }
        }
        break;
      }
    }
    s.sh = shellfacetraverse(subfacepool);
  }

  if (s.sh == NULL) {
    printf("  !! Not exist.\n");
  }
  delete [] marklist;

  subfacepool->pathblock = bakpathblock;
  subfacepool->pathitem = bakpathitem;
  subfacepool->pathitemsleft = bakpathitemsleft;
  subfacepool->alignbytes = bakalignbytes;
}

///////////////////////////////////////////////////////////////////////////////
// Print the information of the subsegment (i, j).

void tetgenmesh::psubseg(int i, int j)
{
  face s; //, s1;
  point forg, fdest;
  bool bflag;

  bflag = false;
  s.shver = 0;
  subsegpool->traversalinit();
  s.sh = shellfacetraverse(subsegpool);
  while (s.sh != NULL) {
    if (pointmark(sorg(s)) == i) {
      if (pointmark(sdest(s)) == j) {
        bflag = true;
      }
    } else if (pointmark(sorg(s)) == j) {
      if (pointmark(sdest(s)) == i) {
        sesymself(s);
        bflag = true;
      }
    }
    if (bflag) {
      // Print the original segment containing [i, j]
      forg = farsorg(s);
      fdest = farsdest(s);
      printf("  seg x%lx (%d, %d) < (%d, %d)\n", (unsigned long) s.sh, i, j,
        pointmark(forg), pointmark(fdest));
      /*// Print the adjacent subsegments at i and j.
      senext2(s, s1);
      spivotself(s1);
      if (s1.sh != NULL) {
        if (sdest(s1) != i) sesymself(s1);
        printf("  [%d] seg x%lx (%d, %d)\n", i, (unsigned long) s1.sh,
          pointmark(sorg(s1)), pointmark(sdest(s1))); 
      } else {
        printf("  [%d] NULL", i);
      }
      senext(s, s1);
      spivotself(s1);
      if (s1.sh != NULL) {
        if (sorg(s1) != j) sesymself(s1);
        printf("  [%d] seg x%lx (%d, %d)\n", j, (unsigned long) s1.sh,
          pointmark(sorg(s1)), pointmark(sdest(s1))); 
      } else {
        printf("  [%d] NULL", j);
      }*/
      break;
    }
    s.sh = shellfacetraverse(subsegpool);
  }

  if (!bflag) {
    printf("  !! Not exist.\n");
  }
}

///////////////////////////////////////////////////////////////////////////////
// Print the index of the point.

int tetgenmesh::pmark(point p)
{
  return pointmark(p);
}

void tetgenmesh::pvert(point pt)
{
  triface adjtet;
  int idx;

  idx = ((int *) (pt))[pointmarkindex];
  printf("  vertex %d: x%lx\n", idx, (unsigned long) pt);
  idx = ((int *) (pt))[pointmarkindex + 1];
  printf("  type: %d (%s infected).\n", idx >> 1, idx & 1 ? " " : "not");

  decode(point2tet(pt), adjtet);
  if (adjtet.tet != NULL) {
    printf("  adjtet: x%lx (%d, %d, %d, %d).\n", (unsigned long) adjtet.tet,
      pointmark(adjtet.tet[4]), pointmark(adjtet.tet[5]),
      pointmark(adjtet.tet[6]), pointmark(adjtet.tet[7]));
  } else {
    printf("  No adjacent tet.\n");
  }
}

int tetgenmesh::pverti(int idx)
{
  triface adjtet;
  point pt;

  // Search the vertex.
  pointpool->traversalinit();
  pt = pointtraverse();
  while (pt != NULL) {
    if (idx == ((int *) (pt))[pointmarkindex]) break;
    pt = pointtraverse();
  }

  if (pt == NULL) {
    printf(" Not exist.\n");
    return 0;
  }

  printf("  vertex %d: x%lx\n", idx, (unsigned long) pt);
  idx = ((int *) (pt))[pointmarkindex + 1];
  printf("  type: %d (%s infected).\n", idx >> 1, idx & 1 ? " " : "not");

  decode(point2tet(pt), adjtet);
  if (adjtet.tet == NULL) {
    printf("  No adjacent tet.\n");
    return 0;
  }
  if (adjtet.tet[4] == NULL) {
    printf("  !! A DEAD adjacent tet.\n");
    return 0;
  }
  printf("  adjtet: x%lx (%d, %d, %d, %d).\n", (unsigned long) adjtet.tet,
    pointmark(adjtet.tet[4]), pointmark(adjtet.tet[5]),
    pointmark(adjtet.tet[6]), pointmark(adjtet.tet[7]));

  if (((point) adjtet.tet[4] == pt) || ((point) adjtet.tet[5] == pt) ||
      ((point) adjtet.tet[6] == pt) || ((point) adjtet.tet[7] == pt)) {
    return 0;
  } else {
    return 1;  // Bad point-to-tet map.
  }
}

///////////////////////////////////////////////////////////////////////////////
// Geometrical tests.

REAL tetgenmesh::test_orient3d(int i, int j, int k, int l)
{
  point *idx2ptmap;
  REAL ori;
  int idx;

  idx = (int) pointpool->items;
  if ((i > idx) || (j > idx) || (k > idx) || (l > idx)) {
    printf("Input indices are invalid.\n");
    return 0;
  }

  makeindex2pointmap(idx2ptmap);
  ori = orient3d(idx2ptmap[i], idx2ptmap[j], idx2ptmap[k], idx2ptmap[l]);
  delete [] idx2ptmap;
  
  return ori;
}

REAL tetgenmesh::test_insphere(int i, int j, int k, int l, int m)
{
  point *idx2ptmap;
  REAL sign;
  int idx;

  idx = (int) pointpool->items;
  if ((i > idx) || (j > idx) || (k > idx) || (l > idx) || (m > idx)) {
    printf("Input indices are invalid.\n");
    return 0;
  }

  makeindex2pointmap(idx2ptmap);
  sign = insphere(idx2ptmap[i], idx2ptmap[j], idx2ptmap[k], idx2ptmap[l],
                  idx2ptmap[m]);
  if (sign == 0) {
    printf("  sign == 0.0! (symbolic perturbed) \n");
    sign = insphere_sos(idx2ptmap[i], idx2ptmap[j], idx2ptmap[k], idx2ptmap[l],
                        idx2ptmap[m]);
  }
  delete [] idx2ptmap;
  
  return sign;
}

///////////////////////////////////////////////////////////////////////////////
// test_tritri()    Test if two triangles are intersecting.

int tetgenmesh::test_tritri(int a, int b, int c, int p,  int q, int r)
{
  point *idx2ptmap;
  point A, B, C, P, Q, R;
  enum intersection dir;
  int ret, types[2], pos[4];
  int idx, i;

  idx = (int) pointpool->items;
  if ((a > idx) || (b > idx) || (c > idx) || 
      (p > idx) || (q > idx) || (r > idx) ||
      (a<in->firstnumber) || (b<in->firstnumber) || (c<in->firstnumber) || 
      (p<in->firstnumber) || (q<in->firstnumber) || (r<in->firstnumber)) {
    printf("Input indices are invalid.\n");
    return 0;
  }

  makeindex2pointmap(idx2ptmap);
  A = idx2ptmap[a];
  B = idx2ptmap[b];
  C = idx2ptmap[c];
  P = idx2ptmap[p];
  Q = idx2ptmap[q];
  R = idx2ptmap[r];

  ret = tri_tri_test(A, B, C, P, Q, R, NULL, 1, types, pos);

  // Report the intersection types and positions.
  for (i = 0; i < 2; i++) {
    dir = (enum tetgenmesh::intersection) types[i];
    switch (dir) {
    case tetgenmesh::DISJOINT: 
      printf("  DISJOINT\n"); break;
    case tetgenmesh::SHAREVERT: 
      printf("  SHAREVERT %d %d\n", pos[i*2], pos[i*2+1]); break;
    case tetgenmesh::SHAREEDGE: 
      printf("  SHAREEDGE %d %d\n", pos[i*2], pos[i*2+1]); break;
    case tetgenmesh::SHAREFACE: 
      printf("  SHAREFACE\n"); break;
    case tetgenmesh::TOUCHEDGE: 
      printf("  TOUCHEDGE %d %d\n", pos[i*2], pos[i*2+1]); break;
    case tetgenmesh::TOUCHFACE: 
      printf("  TOUCHFACE %d %d\n", pos[i*2], pos[i*2+1]); break;
    case tetgenmesh::ACROSSVERT: 
      printf("  ACROSSVERT %d %d\n", pos[i*2], pos[i*2+1]); break;
    case tetgenmesh::ACROSSEDGE: 
      printf("  ACROSSEDGE %d %d\n", pos[i*2], pos[i*2+1]); break;
    case tetgenmesh::ACROSSFACE: 
      printf("  ACROSSFACE %d %d\n", pos[i*2], pos[i*2+1]); break;
    case tetgenmesh::ACROSSTET: 
      printf("  ACROSSTET\n"); break;
    case tetgenmesh::TRIEDGEINT:
      printf("  TRIEDGEINT %d %d\n", pos[i*2], pos[i*2+1]); break;
    case tetgenmesh::EDGETRIINT:
      printf("  EDGETRIINT %d %d\n", pos[i*2], pos[i*2+1]); break;
    }
  }

  delete [] idx2ptmap;
  return ret;
}

///////////////////////////////////////////////////////////////////////////////
// Print an array of tetrahedra (in draw command)

void tetgenmesh::print_cavebdrylist()
{
  FILE *fout;
  triface *cavetet;
  int i;

  printf("  Dump %ld faces to dump_cavebdry.lua.\n", cavebdrylist->objects);

  fout = fopen("dump_cavebdry.lua", "w");
  for (i = 0; i < cavebdrylist->objects; i++) {
    cavetet = (triface *) fastlookup(cavebdrylist, i);
    fprintf(fout, "p:draw_subface(%d, %d, %d) -- %d\n", 
      pointmark(org(*cavetet)), pointmark(dest(*cavetet)), 
      pointmark(apex(*cavetet)), i);
  }
  fclose(fout);
}

///////////////////////////////////////////////////////////////////////////////
// Print current faces in flipstack (in draw command)

void tetgenmesh::print_flipstack()
{
  badface *traveface;
  int i;

  traveface = futureflip; 
  i = 0;
  while (traveface != NULL) {
    if (traveface->tt.tet[4] != NULL) {
      printf("%2d  (%d, %d, %d, %d) - %d\n",i+1,pointmark(org(traveface->tt)),
        pointmark(dest(traveface->tt)), pointmark(apex(traveface->tt)),
        pointmark(oppo(traveface->tt)), pointmark(traveface->foppo));
    }
    traveface = traveface->nextitem;
    i++;
  }
}

///////////////////////////////////////////////////////////////////////////////
// Print an array of tetrahedra, faces, subfaces (in draw command)
// If 'nohulltet' is TRUE, ignore hull tets.

void tetgenmesh::print_tetarray(arraypool *tetarray, bool nohulltet)
{
  triface *parytet;
  int i;

  for (i = 0; i < tetarray->objects; i++) {
    parytet = (triface *) fastlookup(tetarray, i);
    if (parytet->tet == NULL) {
      printf("-- NOT A TET -- %d\n", i + 1); continue;
    }
    if (nohulltet) {
      if ((point) parytet->tet[7] == dummypoint) continue;
    }
    if (parytet->tet[4] == NULL) {
      printf("-- A DEAD TET -- %d\n", i + 1); continue;
    }
    if ((point) parytet->tet[7] != dummypoint) {
      printf("p:draw_tet(%d, %d, %d, %d) -- %d", 
        pointmark(org(*parytet)), pointmark(dest(*parytet)),
        pointmark(apex(*parytet)), pointmark(oppo(*parytet)), i + 1);
    } else {
      printf("-- p:draw_tet(%d, %d, %d, %d) -- %d (hulltet)", 
        pointmark(org(*parytet)), pointmark(dest(*parytet)),
        pointmark(apex(*parytet)), pointmark(oppo(*parytet)), i + 1);
    }
    if (marktested(*parytet)) {
      printf(" (marked)");
    }
    if (infected(*parytet)) {
      printf(" (infect)");
    }
    printf("\n");
  }
}

void tetgenmesh::print_facearray(arraypool *facearray)
{
  triface *parytet;
  int i;

  for (i = 0; i < facearray->objects; i++) {
    parytet = (triface *) fastlookup(facearray, i);
    printf("p:draw_subface(%d, %d, %d) -- %d\n", 
      pointmark(org(*parytet)), pointmark(dest(*parytet)),
      pointmark(apex(*parytet)), i + 1);
  }
}

void tetgenmesh::print_subfacearray(arraypool *subfacearray)
{
  face *parysub;
  int i;

  for (i = 0; i < subfacearray->objects; i++) {
    parysub = (face *) fastlookup(subfacearray, i);
    printf("p:draw_subface(%d, %d, %d) -- %d\n", 
      pointmark(sorg(*parysub)), pointmark(sdest(*parysub)),
      pointmark(sapex(*parysub)), i + 1);
  }
}

///////////////////////////////////////////////////////////////////////////////
// dump the boundary faces of a cavity into file "cavity.lua"
// 'topfaces' and 'botfaces' are two arrays. 
// NOTE: hull tets may be included.

void tetgenmesh::dump_cavity(arraypool *topfaces, arraypool *botfaces = NULL)
{
  FILE *fout;
  arraypool *cavfaces;
  triface *paryface;
  int i, k;

  printf("  dump %ld topfaces to cavity.lua\n", topfaces->objects);
  if (botfaces != NULL) {
    printf("  dump %ld botfaces to cavity.lua\n", botfaces->objects);
  }
  fout = fopen("cavity.lua", "w");

  for (k = 0; k < 2; k++) {
    cavfaces = (k == 0 ? topfaces : botfaces);
    if (cavfaces != NULL) {
      for (i = 0; i < cavfaces->objects; i++) {
        paryface = (triface *) fastlookup(cavfaces, i);
        fprintf(fout, "p:draw_subface(%d, %d, %d) -- %d\n", 
          pointmark(org(*paryface)), pointmark(dest(*paryface)),
          pointmark(apex(*paryface)), i + 1);
      }
    }
  }

  fclose(fout);
}

///////////////////////////////////////////////////////////////////////////////
// dump a facet containing a given subface s.

void tetgenmesh::dump_facetof(face *pssub, char *filename)
{
  FILE *fout;
  char outfilename[256];
  arraypool *tmpfaces;
  face *parysh, *parysh2, s;
  face checkseg;
  int ii, jj;

  tmpfaces = new arraypool(sizeof(face), 8);

  smarktest(*pssub);
  tmpfaces->newindex((void **) &parysh);
  *parysh = *pssub;

  for (ii = 0; ii < tmpfaces->objects; ii++) {
    parysh = (face *) fastlookup(tmpfaces, ii);
    for (jj = 0; jj < 3; jj++) {
      sspivot(*parysh, checkseg);
      if (checkseg.sh == NULL) {
        spivot(*parysh, s);
        if (s.sh != NULL) {
          if (!smarktested(s)) {
            smarktest(s);
            tmpfaces->newindex((void **) &parysh2);
            *parysh2 = s;
          }
        }
      }
      senextself(*parysh);
    }
  }

  for (ii = 0; ii < tmpfaces->objects; ii++) {
    parysh = (face *) fastlookup(tmpfaces, ii);
    sunmarktest(*parysh);
  }

  if (filename != NULL) {
    sprintf(outfilename, filename);
  } else {
    sprintf(outfilename, "facet.lua");
  }

  printf("  dump %ld subfaces to %s\n", tmpfaces->objects, outfilename);
  fout = fopen(outfilename, "w");

  for (ii = 0; ii < tmpfaces->objects; ii++) {
    parysh = (face *) fastlookup(tmpfaces, ii);
    fprintf(fout, "p:draw_subface(%d, %d, %d) -- %d\n", 
      pointmark(sorg(*parysh)), pointmark(sdest(*parysh)),
      pointmark(sapex(*parysh)), ii + 1);
  }

  fclose(fout);

  delete tmpfaces;
}

#endif // #ifndef meshstatCXX