///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// tetlib.cpp    The implementation file for class mesh3d.  Include the mesh //
//               data structure and the kernel member functions.             //
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

#include "tetlib.h"

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Initialize all the lookup tables used by mesh manipulation primitives.    //                                             //
//                                                                           //
// The internal representation of the tetrahedron-based and triangle-edge    //
// data structures takes advantage of the predefined numbering scheme for    //
// vertices and faces of a tetrahedron, also takes advantage of that the     //
// structure of two edge rings of each face is identical. Therefore, it can  //
// be implemented by several global lookup tables as following.              //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

// For enext() primitive, use 'ver' as index.
int mesh3d::ve[6] = { 2, 5, 4, 1, 0, 3 };

// For org(), dest() and apex() primitives, use 'ver' as index.
int mesh3d::vo[6] = { 0, 1, 1, 2, 2, 0 };
int mesh3d::vd[6] = { 1, 0, 2, 1, 0, 2 };
int mesh3d::va[6] = { 2, 2, 0, 0, 1, 1 };

// For org(), dest() and apex() primitives, use 'loc' as first index and
//   'ver' as second index.
int mesh3d::locver2org[4][6]  = { 0, 1, 1, 2, 2, 0,
                                  0, 3, 3, 1, 1, 0,
                                  1, 3, 3, 2, 2, 1,
                                  2, 3, 3, 0, 0, 2 };
int mesh3d::locver2dest[4][6] = { 1, 0, 2, 1, 0, 2,
                                  3, 0, 1, 3, 0, 1,
                                  3, 1, 2, 3, 1, 2,
                                  3, 2, 0, 3, 2, 0 };
int mesh3d::locver2apex[4][6] = { 2, 2, 0, 0, 1, 1,
                                  1, 1, 0, 0, 3, 3,
                                  2, 2, 1, 1, 3, 3,
                                  0, 0, 2, 2, 3, 3 };

// For oppo() primitives, use 'loc' as index.
int mesh3d::loc2oppo[4] = { 3, 2, 0, 1 };

// For fnext() primitives, use 'loc' as first index and 'ver' as second
//   index, return a new 'loc' and new 'ver' in an int array.
// Note: Only valid for face version = 0, 2, 4.
int mesh3d::locver2nextf[4][6][2] =
               { { {1, 5}, {-1, -1}, {2, 5}, {-1, -1}, {3, 5}, {-1, -1} },
                 { {3, 3}, {-1, -1}, {2, 1}, {-1, -1}, {0, 1}, {-1, -1} },
                 { {1, 3}, {-1, -1}, {3, 1}, {-1, -1}, {0, 3}, {-1, -1} },
                 { {2, 3}, {-1, -1}, {1, 1}, {-1, -1}, {0, 5}, {-1, -1} } };

int mesh3d::plus1mod3[3] = {1, 2, 0};
int mesh3d::minus1mod3[3] = {2, 0, 1};

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Mesh data type linar-order functions used in list and link.  Refer to     //
// file linklist.h for the description about linar-order functions.          //
//                                                                           //
// compare2points()    Compare two points by their x-coordinate, using the   //
//                     y-coordinate as a secondary key, and the z-coordinate //
//                     if their need.                                        //
// compare2tets()      Compare two handles of tetrahedra by their addresses. //
// compare2shfaces()   Compare two handles of subfaces/subsegments by their  //
//                     addresses.                                            //
//                                                                           //
// Return 0 if they are same. Return 1 or -1 if they are not same.           //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

int compare2points(point3d *point1, point3d *point2)
{
  if ((*point1)[0] < (*point2)[0]) {
    return -1;
  } else if ((*point1)[0] > (*point2)[0]) {
    return +1;
  } else {
    if ((*point1)[1] < (*point2)[1]) {
      return -1;
    } else if ((*point1)[1] > (*point2)[1]) {
      return +1;
    } else {
      if ((*point1)[2] < (*point2)[2]) {
        return -1;
      } else if ((*point1)[2] > (*point2)[2]) {
        return +1;
      } else {
        return 0;
      }
    }
  }
}

int compare2tets(triface* tface1, triface* tface2)
{
  if (tface1->tet == tface2->tet) {
    return 0;                                   // These two tets are same.
  } else if (tface1->tet < tface2->tet) {
    return -1;
  } else {
    return 1;
  }
}

int compare2shfaces(face* sface1, face* sface2)
{
  if (sface1->sh == sface2->sh) {
    return 0;                      // These two subfaces/segments are same.
  } else if (sface1->sh < sface2->sh) {
    return -1;
  } else {
    return 1;
  }
}

///////////////////////////////////////////////////////////////////////////////
// Advanced Mesh Manipulaton Primitives                                      //
// BEGIN                                                                     //
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// getnextface()    Get next face of 'tface1' in the same face ring.         //
//                                                                           //
// The right-hand rule is used to determine where the next face is.          //
//                                                                           //
// The next face is returned in 'tface2' or 'tface1'(if tface2 == NULL).     //                                                                //
// If next face exists, return true. Otherwise, (it's a outer boundary face),//
// return false, and the return handle remain unchanged.                     //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

bool mesh3d::getnextface(triface* tface1, triface* tface2)
{
  // First we need decide where the next face in the face ring locate:
  //   in this tet('tface1') or in it's neigbhour?  This can do quickly by
  //   checking which edge ring of the 'tface1' version belong to.
  if (EdgeRing(tface1->ver) == CW) {
    // Indicate the next face is in the neigbhour tet.
    if (!issymexist(tface1)) {
      // Encounter Outer Space when spin face around edge. return.
      return false;
    }

    point3d torg, tdest;

    org(*tface1, torg);
    dest(*tface1, tdest);
    if (tface2) {
      sym(*tface1, *tface2);
      findversion(tface2, torg, tdest, 0); // 0 mean don't reverse direction.
    } else {
      symself(*tface1);
      findversion(tface1, torg, tdest, 0);
    }
  } else {
    // Indicate the next face is still in this tet('tface1').
    if (tface2) {
      *tface2 = *tface1;
    }
  }
  // At here,  we know the next face must in retface.tet.
  // assert(EdgeRing(tface2->ver) == CCW);
  int tloc, tver;

  if (tface2) {
    tloc = tface2->loc; tver = tface2->ver;
    tface2->loc = locver2nextf[tloc][tver][0];
    tface2->ver = locver2nextf[tloc][tver][1];
  } else {
    tloc = tface1->loc; tver = tface1->ver;
    tface1->loc = locver2nextf[tloc][tver][0];
    tface1->ver = locver2nextf[tloc][tver][1];
  }
  return true;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// tsspivot()    Finds a subsegment abutting on this tetrahderon's edge.     //
//                                                                           //
// To find if there has a subsegment adjoining to this tetrahedron's edge,   //
// first we need find a subface around this edge to see if there exist a     //
// subsegment adjoining to it. Why? Because There are no pointers directly   //
// connecting tetrahedron and adjoining subsegments. Connections between     //
// tetrahedron and subsegments are entirely mediate througth subfaces.       //
// Because a subsegment may be shared by any number of subfaces and          //
// tetrahedra, each subsegment has a pointer to only one adjoining subfaces  //
// (choose arbitrarly).                                                      //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::tsspivot(triface* tface, face* tseg)
{
  triface spintet;
  face tmpface;
  point3d tapex;
  int hitbdry;

  spintet = *tface;
  apex(*tface, tapex);
  hitbdry = 0;
  while (true) {
    if (fnextself(spintet)) {
      if (apex(spintet) == tapex) {
        break; // Rewind, can leave now.
      }
      tspivot(spintet, tmpface);
      if (tmpface.sh != dummysh) {
        findversion(&tmpface, tface);
        sspivot(tmpface, *tseg);
        return;
      }
    } else {
      hitbdry ++;
      if(hitbdry >= 2) {
        break;
      } else {
        esym(*tface, spintet);
      }
    }
  }
  // Check myself last.
  tspivot(*tface, tmpface);
  if (tmpface.sh != dummysh) {
    findversion(&tmpface, tface);
    sspivot(tmpface, *tseg);
    return;
  }
  // Not find a subsegment.
  tseg->sh = dummysh;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// sstpivot()    Finds a tetrahedron abutting a subsegment.                  //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::sstpivot(face* tseg, triface* tface)
{
  face parentface;

  // Get the subface which contains the segment.
  sdecode(tseg->sh[0], parentface);
  assert(parentface.sh != dummysh);
  // Get the tetrahera which the subface attches to.
  stpivot(parentface, *tface);
  if (tface->tet == dummytet) {
    sesymself(parentface);
    stpivot(parentface, *tface);
    assert(tface->tet != dummytet);
  }
  findversion(tface, tseg, 0);
}

///////////////////////////////////////////////////////////////////////////////
// END                                                                       //
// Advanced Mesh Manipulaton Primitives                                      //
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Auxiliary Mesh Manipulaton Primitives                                     //
// BEGIN                                                                     //
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// findversion()    Find and set version to indicate the directed edge in    //
//                  the input handle('tface' or 'sface'), which its origin   //
//                  is 'dorg' and destination is 'ddest'.                    //
//                                                                           //
// If 'symflag' = 1, inverse the edge direction(esymself) before return.     //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::
findversion(triface* tface, point3d dorg, point3d ddest, int symflag)
{
  point3d torg, tdest;

  tface->ver = 0;
  while (tface->ver < 6) {
    org(*tface, torg);
    dest(*tface, tdest);
    if ((torg == dorg) && (tdest == ddest)) {
      break;
    } else if ((torg == ddest) && (tdest == dorg)) {
      tface->ver++;
      break;
    }
    tface->ver += 2;
  }
  assert(tface->ver < 6);
  if (symflag) {
    esymself(*tface);
  }
}

void mesh3d::findversion(triface* tface, triface* dface, int symflag)
{
  findversion(tface, org(*dface), dest(*dface), symflag);
}

void mesh3d::findversion(triface* tface, face* sface, int symflag)
{
  findversion(tface, sorg(*sface), sdest(*sface), symflag);
}

void mesh3d::
findversion(face* sface, point3d dorg, point3d ddest, int symflag)
{
  point3d shorg, shdest;

  sface->shver = 0;
  while (sface->shver < 6) {
    sorg(*sface, shorg);
    sdest(*sface, shdest);
    if ((shorg == dorg) && (shdest == ddest)) {
      break;
    } else if ((shorg == ddest) && (shdest == dorg)) {
      sface->shver++;
      break;
    }
    sface->shver += 2;
  }
  assert(sface->shver < 6);
  if (symflag) {
    sesymself(*sface);
  }
}

void mesh3d::findversion(face* sface, triface* dface, int symflag)
{
  findversion(sface, org(*dface), dest(*dface), symflag);
}

void mesh3d::findversion(face* sface, face* sface1, int symflag)
{
  findversion(sface, sorg(*sface1), sdest(*sface1), symflag);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// findorg()    Find and set the version to indicate the desired point.      //
//                                                                           //
// If 'dorg' is a one of vertices of 'tface', set the origin of 'tface' be   //
// 'dorg' and return true, else return false.                                //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

bool mesh3d::findorg(triface* tface, point3d dorg)
{
  if (org(*tface) == dorg) {
    return true;
  }
  if (dest(*tface) == dorg) {
    enextself(*tface);
  } else {
    if (apex(*tface) == dorg) {
      enext2self(*tface);
    } else {
      if (oppo(*tface) == dorg) {
        // Keep in the same tet after fnext().
        adjustedgering(*tface, CCW);
        fnextself(*tface);
        enext2self(*tface);
      } else {
        return false;
      }
    }
  }
  return true;
}

bool mesh3d::findorg(face* sface, point3d dorg)
{
  point3d pointptr;

  sorg(*sface, pointptr);
  if (pointptr == dorg) {
    return true;
  }
  sdest(*sface, pointptr);
  if (pointptr == dorg) {
    senextself(*sface);
  } else {
    sapex(*sface, pointptr);
    if (pointptr == dorg) {
      senext2self(*sface);
    } else {
      return false;
    }
  }
  return true;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// isridge()    Returns true if the edge of tetrahedron(specified by loc and //
//              ver) is a ridge in the mesh.                                 //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

bool mesh3d::isridge(triface* tface)
{
  triface testtet;
  point3d tapex;

  // Spin current edge(loc and ver) to see if there will encounter
  //   'Outer boundary' (dummytet).
  if (!fnext(*tface, testtet)) {
    return true;
  }

  apex(*tface, tapex);
  do {
    if(!fnextself(testtet)) {
      return true;
    }
  } while (apex(testtet) != tapex);

  return false;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// isexistincidentseg()    Test if there exist any segment shares with input //
//                         segment's origin. return true if there exists at  //
//                         least one incident segment, otherwise return      //
//                         false.                                            //
//                                                                           //
// This primitive is used to help decide where to split a segment.           //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

bool mesh3d::isexistincidentseg(face* tseg)
{
  triface neighbortet, spintet, testtet;
  face testseg;
  point3d tapex;
  int findsegflag, reverseflag, hitbdry;

  // Get a tet that contain this segment with the same origin and
  //   destination of this segment.
  sstpivot(tseg, &neighbortet);
  // Spin around the tet, skip myself(tseg).
  apex(neighbortet, tapex);
  spintet = neighbortet;
  hitbdry = reverseflag = findsegflag = 0;
  while (true) {
    if (fnextself(spintet)) {
      if (apex(spintet) == tapex) {
        break; // Rewind, can leave now.
      }
      // Get the correct edge. Note the 'reverseflag'.
      if (!reverseflag) {
        enext2(spintet, testtet);
      } else {
        enext(spintet, testtet);
      }
      tsspivot(&testtet, &testseg);
      if (testseg.sh != dummysh) {
        findsegflag = 1;
        break;
      }
    } else {
      hitbdry ++;
      if(hitbdry >= 2) {
        break;
      } else {
        reverseflag = 1;
        esym(neighbortet, spintet);
      }
    }
  }
  if (!findsegflag) {
    enext2(neighbortet, testtet);
    tsspivot(&testtet, &testseg);
    if (testseg.sh != dummysh) {
      findsegflag = 1;
    }
  }
  return findsegflag == 1;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// issameface(), issameedge()    Compare the vertices of two faces/edges to  //
//                               see if they are the same face/edge. The     //
//                               inputs are handles of two tetrahedra.       //
//                               Return 0 (same) or 1 (diffrent).            //
//                                                                           //
// These two primitives mainly used as list or link's linear order functions.//
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

int mesh3d::issameface(triface* tface1, triface* tface2)
{
  point3d torg1, tdest1, tapex1;
  point3d torg2, tdest2, tapex2;
  int oldver, tmpver;

  org(*tface1, torg1);
  dest(*tface1, tdest1);
  apex(*tface1, tapex1);

  oldver = tface2->ver;
  tmpver = 0;
  while (tmpver < 6) {
    tface2->ver = tmpver;
    org(*tface2, torg2);
    dest(*tface2, tdest2);
    apex(*tface2, tapex2);
    if (((torg1 == torg2) && (tdest1 == tdest2) && (tapex1 == tapex2))
        || ((torg1 == tdest2) && (tdest1 == torg2) && (tapex1 == tapex2))) {
      break;
    }
    tmpver += 2;
  }

  tface2->ver = oldver;
  if (tmpver < 6) {
    return 0;  // These two faces are same.
  } else {
    return 1;
  }
}

int mesh3d::issameedge(triface* tface1, triface* tface2)
{
  point3d torg1, tdest1;
  point3d torg2, tdest2;

  org(*tface1, torg1);
  dest(*tface1, tdest1);
  org(*tface2, torg2);
  dest(*tface2, tdest2);

  if (((torg1 == torg2) && (tdest1 == tdest2))
        || ((torg1 == tdest2) && (tdest1 == torg2))) {
    return 0; // These two edges are same.
  } else {
    return 1;
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// dump()    For debuging, Print out the details of a tetrahedron/shellfacet //
//           handle to standard output.                                      //
//                                                                           //
// It can be called directly from the debugger, and presents information     //
// about a tetrahedron handle in digestible form. It's also used when the    //
// highest level of verbosity (`-VVV') is specified.                         //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::dump(triface* tface)
{
  triface tmpface, prtface;
  point3d tmppt;
  face tmpsh;
  int facecount;

  printf("Tetra x%lx with loc(%i) and ver(%i):\n",
         (unsigned long)(tface->tet), tface->loc, tface->ver);

  tmpface = *tface;
  facecount = 0;
  while(facecount < 4) {
    tmpface.loc = facecount;
    sym(tmpface, prtface);
    if(prtface.tet == dummytet) {
      printf("      [%i] Outer space.\n", facecount);
    } else {
      printf("      [%i] x%lx  loc(%i).\n", facecount,
             (unsigned long)(prtface.tet), prtface.loc);
    }
    facecount ++;
  }

  org(*tface, tmppt);
  if(tmppt == (point3d) NULL) {
    printf("      Org [%i] NULL\n", locver2org[tface->loc][tface->ver]);
  } else {
    printf("      Org [%i] x%lx (%.12g,%.12g,%.12g) %d\n",
           locver2org[tface->loc][tface->ver], (unsigned long)(tmppt),
           tmppt[0], tmppt[1], tmppt[2], pointmark(tmppt));
  }
  dest(*tface, tmppt);
  if(tmppt == (point3d) NULL) {
    printf("      Dest[%i] NULL\n", locver2dest[tface->loc][tface->ver]);
  } else {
    printf("      Dest[%i] x%lx (%.12g,%.12g,%.12g) %d\n",
           locver2dest[tface->loc][tface->ver], (unsigned long)(tmppt),
           tmppt[0], tmppt[1], tmppt[2], pointmark(tmppt));
  }
  apex(*tface, tmppt);
  if(tmppt == (point3d) NULL) {
    printf("      Apex[%i] NULL\n", locver2apex[tface->loc][tface->ver]);
  } else {
    printf("      Apex[%i] x%lx (%.12g,%.12g,%.12g) %d\n",
           locver2apex[tface->loc][tface->ver], (unsigned long)(tmppt),
           tmppt[0], tmppt[1], tmppt[2], pointmark(tmppt));
  }
  oppo(*tface, tmppt);
  if(tmppt == (point3d) NULL) {
    printf("      Oppo[%i] NULL\n", loc2oppo[tface->loc]);
  } else {
    printf("      Oppo[%i] x%lx (%.12g,%.12g,%.12g) %d\n",
           loc2oppo[tface->loc], (unsigned long)(tmppt),
           tmppt[0], tmppt[1], tmppt[2], pointmark(tmppt));
  }

  if (useshelles) {
    tmpface = *tface;
    facecount = 0;
    while(facecount < 4) {
      tmpface.loc = facecount;
      tspivot(tmpface, tmpsh);
      if(tmpsh.sh != dummysh) {
        printf("      [%i] x%lx  ver(%i).\n", facecount,
               (unsigned long)(tmpsh.sh), tmpsh.shver);
      }
      facecount ++;
    }
  }
}

void mesh3d::dump(face* sface)
{
  face printsh;
  triface printtet;
  point3d tapex, printpoint;

  sapex(*sface, tapex);
  if (tapex != NULL) {
    printf("subface x%lx with version %d and mark %d:\n",
           (unsigned long)(sface->sh), sface->shver, mark(*sface));
  } else {
    printf("Subsegment x%lx with version %d and mark %d:\n",
           (unsigned long)(sface->sh), sface->shver, mark(*sface));
  }

  if (tapex != NULL) {
    // Current we don't use the first three pointers in subface,
    //   so their values are always NULL. Skipped.
    /*sdecode(sface->sh[0], printsh);
    if (printsh.sh == dummysh) {
      printf("      [0] = No shell\n");
    } else {
      printf("      [0] = x%lx  %d\n",
             (unsigned long)(printsh.sh), printsh.shver);
    }
    sdecode(sface->sh[1], printsh);
    if (printsh.sh == dummysh) {
      printf("      [1] = No shell\n");
    } else {
      printf("      [1] = x%lx  %d\n",
             (unsigned long)(printsh.sh), printsh.shver);
    }
    sdecode(sface->sh[2], printsh);
    if (printsh.sh == dummysh) {
      printf("      [2] = No shell\n");
    } else {
      printf("      [2] = x%lx  %d\n",
             (unsigned long)(printsh.sh), printsh.shver);
    }*/
  } else {
    sdecode(sface->sh[0], printsh);
    if (printsh.sh == dummysh) {
      printf("      [0] = No shell\n");
    } else {
      printf("      [0] = x%lx  %d\n",
             (unsigned long)(printsh.sh), printsh.shver);
    }
    sdecode(sface->sh[1], printsh);
    if (printsh.sh != dummysh) {
      printf("      [1] = x%lx  %d\n",
             (unsigned long)(printsh.sh), printsh.shver);
    }
    sdecode(sface->sh[2], printsh);
    if (printsh.sh != dummysh) {
      printf("      [2] = x%lx  %d\n",
             (unsigned long)(printsh.sh), printsh.shver);
    }
  }

  sorg(*sface, printpoint);
  if (printpoint == (point3d) NULL)
    printf("      Org [%d] = NULL\n", vo[sface->shver]);
  else
    printf("      Org [%d] = x%lx  (%.12g,%.12g,%.12g) %d\n",
           vo[sface->shver], (unsigned long)(printpoint), printpoint[0],
           printpoint[1], printpoint[2], pointmark(printpoint));
  sdest(*sface, printpoint);
  if (printpoint == (point3d) NULL)
    printf("      Dest[%d] = NULL\n", vd[sface->shver]);
  else
    printf("      Dest[%d] = x%lx  (%.12g,%.12g,%.12g) %d\n",
            vd[sface->shver], (unsigned long)(printpoint), printpoint[0],
            printpoint[1], printpoint[2], pointmark(printpoint));

  if (tapex != NULL) {
    sapex(*sface, printpoint);
    if (printpoint == (point3d) NULL)
      printf("      Apex[%d] = NULL\n", va[sface->shver]);
    else
      printf("      Apex[%d] = x%lx  (%.12g,%.12g,%.12g) %d\n",
             va[sface->shver], (unsigned long)(printpoint), printpoint[0],
             printpoint[1], printpoint[2], pointmark(printpoint));

    decode(sface->sh[6], printtet);
    if (printtet.tet == dummytet) {
      printf("      [6] = Outer space\n");
    } else {
      printf("      [6] = x%lx  %d\n",
             (unsigned long)(printtet.tet), printtet.loc);
    }
    decode(sface->sh[7], printtet);
    if (printtet.tet == dummytet) {
      printf("      [7] = Outer space\n");
    } else {
      printf("      [7] = x%lx  %d\n",
             (unsigned long)(printtet.tet), printtet.loc);
    }

    sdecode(sface->sh[8], printsh);
    if (printsh.sh == dummysh) {
      printf("      [8] = No subsegment\n");
    } else {
      printf("      [8] = x%lx  %d\n",
             (unsigned long)(printsh.sh), printsh.shver);
    }
    sdecode(sface->sh[9], printsh);
    if (printsh.sh == dummysh) {
      printf("      [9] = No subsegment\n");
    } else {
      printf("      [9] = x%lx  %d\n",
             (unsigned long)(printsh.sh), printsh.shver);
    }
    sdecode(sface->sh[10], printsh);
    if (printsh.sh == dummysh) {
      printf("      [10]= No subsegment\n");
    } else {
      printf("      [10]= x%lx  %d\n",
             (unsigned long)(printsh.sh), printsh.shver);
    }
  }
}

///////////////////////////////////////////////////////////////////////////////
// END                                                                       //
// Auxiliary Mesh Manipulaton Primitives                                     //
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Memory Management Routines                                                //
// BEGIN                                                                     //
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// dummyinit()    Initialize the tetrahedron that fills "outer space" and    //
//                the omnipresent subface.                                   //
//                                                                           //
// The tetrahedron that fills "outer space" called 'dummytet', is pointed to //
// by every tetrahedron and subface on a boundary (be it outer or inner) of  //
// the tetrahedralization. Also, 'dummytet' points to one of the tetrahedron //
// on the convex hull(until the holes and concavities are carved), making it //
// possible to find a starting tetrahedron for point location.               //
//                                                                           //
// The omnipresent subface,'dummysh', is pointed to by every tetrahedron or  //
// subface that doesn't have a full complement of real subface to point to.  //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::dummyinit(int ttetwords, int tshwords)
{
  unsigned long alignptr;

  // 'tetwords' and 'shwords' are used by the mesh manipulation primitives
  //   to extract orientations of tetrahedra and subfaces from pointers.
  tetwords = ttetwords;           // Initialize `tetwords' once and for all.
  shwords = tshwords;              // Initialize `shwords' once and for all.

  // Set up 'dummytet', the 'tetrahedron' that occupies "outer space".
  dummytetbase = (tetrahedron *) new BYTE[tetwords * sizeof(tetrahedron)
                                          + tetrahedrons.alignbytes];
  // Align 'dummytet' on a 'tetrahedrons.alignbytes'-byte boundary.
  alignptr = (unsigned long) dummytetbase;
  dummytet = (tetrahedron *)
    (alignptr + (unsigned long) tetrahedrons.alignbytes
     - (alignptr % (unsigned long) tetrahedrons.alignbytes));
  // Initialize the four adjoining tetrahedrons to be "outer space". These
  //   will eventually be changed by various bonding operations, but their
  //   values don't really matter, as long as they can legally be
  //   dereferenced.
  dummytet[0] = (tetrahedron) dummytet;
  dummytet[1] = (tetrahedron) dummytet;
  dummytet[2] = (tetrahedron) dummytet;
  dummytet[3] = (tetrahedron) dummytet;
  // Four NULL vertex points.
  dummytet[4] = (tetrahedron) NULL;
  dummytet[5] = (tetrahedron) NULL;
  dummytet[6] = (tetrahedron) NULL;
  dummytet[7] = (tetrahedron) NULL;

  if (useshelles) {
    // Set up 'dummysh', the omnipresent "subface" pointed to by any
    //   tetrahedron side or subface end that isn't attached to a real
    //   subface.
    dummyshbase = (shellface *) new BYTE[shwords * sizeof(shellface)
                                         + subfaces.alignbytes];
    // Align 'dummysh' on a 'subfaces.alignbytes'-byte boundary.
    alignptr = (unsigned long) dummyshbase;
    dummysh = (shellface *)
      (alignptr + (unsigned long) subfaces.alignbytes
       - (alignptr % (unsigned long) subfaces.alignbytes));
    // Initialize the three adjoining subfaces to be the omnipresent subface.
    //   These will eventually be changed by various bonding operations, but
    //   their values don't really matter, as long as they can legally be
    //   dereferenced.
    dummysh[0] = (shellface) dummysh;
    dummysh[1] = (shellface) dummysh;
    dummysh[2] = (shellface) dummysh;
    // Three NULL vertex points.
    dummysh[3] = (shellface) NULL;
    dummysh[4] = (shellface) NULL;
    dummysh[5] = (shellface) NULL;
    // Initialize the two adjoining tetrahedra to be "outer space".
    dummysh[6] = (shellface) dummytet;
    dummysh[7] = (shellface) dummytet;
    // Initialize the three adjoining subsegments to be "out boundary".
    dummysh[8]  = (shellface) dummysh;
    dummysh[9]  = (shellface) dummysh;
    dummysh[10] = (shellface) dummysh;
    // Set the boundary marker to zero.
    * (int *) (dummysh + 11) = 0;
    // Initialize the four adjoining subfaces of 'dummytet' to be the
    //   omnipresent subface.
    dummytet[8 ] = (tetrahedron) dummysh;
    dummytet[9 ] = (tetrahedron) dummysh;
    dummytet[10] = (tetrahedron) dummysh;
    dummytet[11] = (tetrahedron) dummysh;
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// initializepointpool()    Calculate the size of the point data structure   //
//                          and initialize its memory pool.                  //
//                                                                           //
// This routine also computes the 'pointmarkindex' and `point2tetindex'      //
// indices used to find values within each point.                            //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::initializepointpool()
{
  int pointsize;

  // The index within each point at which the boundary marker is found.
  //   Ensure the point marker is aligned to a sizeof(int)-byte address.
  pointmarkindex = ((3 + nextras) * sizeof(REAL) + sizeof(int) - 1)
                 / sizeof(int);
  pointsize = (pointmarkindex + 1) * sizeof(int);
  if (poly || smesh) {
    // The index within each point at which a tetrahedron pointer is found.
    //   Ensure the pointer is aligned to a sizeof(tetrahedron)-byte address.
    point2tetindex = (pointsize + sizeof(tetrahedron) - 1)
                   / sizeof(tetrahedron);
    pointsize = (point2tetindex + 1) * sizeof(tetrahedron);
  }
  // Initialize the pool of points.
  points.init(pointsize, POINTPERBLOCK,
    (sizeof(REAL) >= sizeof(tetrahedron)) ? FLOATINGPOINT : POINTER, 4);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// initializetetshpools()    Calculate the sizes of the tetrahedron and      //
//                           subface data structures and initialize their    //
//                           memory pools.                                   //
//                                                                           //
// This routine also computes the 'highorderindex', 'elemattribindex', and   //
// 'volumeboundindex' indices used to find values within each tetrahedron.   //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::initializetetshpools()
{
  int tetsize;

  // There are four pointers to other tetrahedra, four pointers to
  //   corners, and possibly four pointers to subfaces.
  highorderindex = 8 + (useshelles * 4);
  // The number of bytes occupied by a tetrahedron.
  tetsize = highorderindex * sizeof(tetrahedron);
  // The index  within each tetrahedron at which its attributes are found,
  //   where the index is measured in REALs.
  elemattribindex = (tetsize + sizeof(REAL) - 1) / sizeof(REAL);
  // The index within each tetrahedron at which the maximum volume
  //   constraint is found, where the index is measured in REALs.  Note that
  //   if the 'regionattrib' flag is set, an additional attribute will be
  //   added.
  volumeboundindex = elemattribindex + eextras + regionattrib;
  // If tetrahedron attributes or a volume bound are needed, increase the
  //   number of bytes occupied by a tetrahedron.
  if (varvolume) {
    tetsize = (volumeboundindex + 1) * sizeof(REAL);
  } else if (eextras + regionattrib > 0) {
    tetsize = volumeboundindex * sizeof(REAL);
  }
  // If a Voronoi diagram or tetrahedron neighbor graph is requested, make
  //   sure there's room to store an integer index in each tetrahedron. This
  //   integer index can occupy the same space as the subfaces or attributes
  //   or volume constraint or extra nodes.
  if ((voronoi || neighbors) &&
      (tetsize < 8 * sizeof(tetrahedron) + sizeof(int))) {
    tetsize = 8 * sizeof(tetrahedron) + sizeof(int);
  }
  // Having determined the memory size of a tetrahedron, initialize the pool.
  tetrahedrons.init(tetsize, TETPERBLOCK, POINTER, 8);

  if (useshelles) {
    // Initialize the pool of subfaces. Note: Here we need eight-byte
    //   aligned for each subface record (to keep six version).
    subfaces.init(11 * sizeof(shellface) + sizeof(int), SUBFACEPERBLOCK,
                  POINTER, 8);
    // Initialize the pool of subsegments. The subsegment's record is same
    //   with subface.
    subsegs.init(11 * sizeof(shellface) + sizeof(int), SUBSEGPERBLOCK,
                 POINTER, 8);
    // Initialize the "outer space" tetrahedron and omnipresent subface.
    dummyinit(tetrahedrons.itemwords, subfaces.itemwords);
  } else {
    // Initialize the "outer space" tetrahedron.
    dummyinit(tetrahedrons.itemwords, 0);
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// tetrahedrondealloc()    Deallocate space for a tetrahedron, marking it    //
//                         dead.                                             //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::tetrahedrondealloc(tetrahedron *dyingtetrahedron)
{
  // Set tetrahedron's vertices to NULL. This makes it possible to detect
  //   dead tetrahedra when traversing the list of all tetrahedra.
  dyingtetrahedron[4] = (tetrahedron) NULL;
  dyingtetrahedron[5] = (tetrahedron) NULL;
  dyingtetrahedron[6] = (tetrahedron) NULL;
  dyingtetrahedron[7] = (tetrahedron) NULL;
  tetrahedrons.dealloc((void *) dyingtetrahedron);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// tetrahedrontraverse()    Traverse the tetrahedra, skipping dead ones.     //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

tetrahedron* mesh3d::tetrahedrontraverse()
{
  tetrahedron *newtetrahedron;

  do {
    newtetrahedron = (tetrahedron *) tetrahedrons.traverse();
    if (newtetrahedron == (tetrahedron *) NULL) {
      return (tetrahedron *) NULL;
    }
  } while (newtetrahedron[4] == (tetrahedron) NULL);      // Skip dead ones.
  return newtetrahedron;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// shellfacedealloc()    Deallocate space for a shellface, marking it dead.  //
//                       Used both for dealloc a subface and subsegment.     //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::shellfacedealloc(memorypool *pool, shellface *dyingshellface)
{
  // Set shellface's vertices to NULL. This makes it possible to detect dead
  //   shellfaces when traversing the list of all shellfaces.
  dyingshellface[3] = (shellface) NULL;
  dyingshellface[4] = (shellface) NULL;
  dyingshellface[5] = (shellface) NULL;
  pool->dealloc((void *) dyingshellface);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// shellfaceraverse()    Traverse the subfaces, skipping dead ones. Used for //
//                       both subfaces and subsegments pool traverse.        //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

shellface* mesh3d::shellfacetraverse(memorypool *pool)
{
  shellface *newshellface;

  do {
    newshellface = (shellface *) pool->traverse();
    if (newshellface == (shellface *) NULL) {
      return (shellface *) NULL;
    }
  } while (newshellface[3] == (shellface) NULL);        // Skip dead ones.
  return newshellface;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// badsegmentdealloc()    Deallocate space for a bad segment, marking it     //
//                        dead.                                              //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::badsegmentdealloc(badface3d *dyingshseg)
{
  // Set segment's faceorg to NULL. This makes it possible to detect dead
  //   segments when traversing the list of all segments.
  dyingshseg->faceorg = (point3d) NULL;
  badsegments.dealloc((void *) dyingshseg);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// badsegmenttraverse()    Traverse the bad segments, skipping dead ones.    //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

badface3d* mesh3d::badsegmenttraverse()
{
  badface3d *newsh;

  do {
    newsh = (badface3d *) badsegments.traverse();
    if (newsh == (badface3d *) NULL) {
      return (badface3d *) NULL;
    }
  } while (newsh->faceorg == (point3d) NULL);             // Skip dead ones.
  return newsh;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// pointdealloc()    Deallocate space for a point, marking it dead.          //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::pointdealloc(point3d dyingpoint)
{
  // Mark the point as dead. This  makes it possible to detect dead points
  //   when traversing the list of all points.
  setpointmark(dyingpoint, DEADPOINT);
  points.dealloc((void *) dyingpoint);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// pointtraverse()    Traverse the points, skipping dead ones.               //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

point3d mesh3d::pointtraverse()
{
  point3d newpoint;

  do {
    newpoint = (point3d) points.traverse();
    if (newpoint == (point3d) NULL) {
      return (point3d) NULL;
    }
  } while (pointmark(newpoint) == DEADPOINT);             // Skip dead ones.
  return newpoint;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// getpoint()    Get a specific point, by number, from the list.             //
//                                                                           //
// The first point is number 'firstnumber'.                                  //
//                                                                           //
// Note that this takes O(n) time ( with a small constant, if POINTPERBLOCK  //
// is large ). I don't care to take the trouble to make it work in constant  //
// time.                                                                     //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

point3d mesh3d::getpoint(int number)
{
  void **getblock;
  point3d foundpoint;
  unsigned long alignptr;
  int current;

  getblock = points.firstblock;
  current = firstnumber;
  // Find the right block.
  while (current + points.itemsperblock <= number) {
    getblock = (void **) *getblock;
    current += points.itemsperblock;
  }
  // Now find the right point.
  alignptr = (unsigned long) (getblock + 1);
  foundpoint = (point3d) (alignptr + (unsigned long) points.alignbytes
                     - (alignptr % (unsigned long) points.alignbytes));
  while (current < number) {
    foundpoint += points.itemwords;
    current++;
  }
  return foundpoint;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// maketetrahedron()    Create a new tetrahedron.                            //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::maketetrahedron(triface *newtet)
{
  newtet->tet = (tetrahedron *) tetrahedrons.alloc();
  // Initialize the four adjoining tetrahedra to be "outer space".
  newtet->tet[0] = (tetrahedron) dummytet;
  newtet->tet[1] = (tetrahedron) dummytet;
  newtet->tet[2] = (tetrahedron) dummytet;
  newtet->tet[3] = (tetrahedron) dummytet;
  // Four NULL vertex points.
  newtet->tet[4] = (tetrahedron) NULL;
  newtet->tet[5] = (tetrahedron) NULL;
  newtet->tet[6] = (tetrahedron) NULL;
  newtet->tet[7] = (tetrahedron) NULL;
  // Initialize the four adjoining subfaces to be the omnipresent subface.
  if (useshelles) {
    newtet->tet[8 ] = (tetrahedron) dummysh;
    newtet->tet[9 ] = (tetrahedron) dummysh;
    newtet->tet[10] = (tetrahedron) dummysh;
    newtet->tet[11] = (tetrahedron) dummysh;
  }
  for (int i = 0; i < eextras; i++) {
    setelemattribute(newtet->tet, i, 0.0);
  }
  if (varvolume) {
    setvolumebound(newtet->tet, -1.0);
  }
  // Initialize the location and version to be Zero.
  newtet->loc = 0;
  newtet->ver = 0;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// makeshellface()    Create a new shellface with version zero. Used both    //
//                    for subfaces and seusegments.                          //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::makeshellface(memorypool *pool, face *newface)
{
  newface->sh = (shellface *) pool->alloc();
  //Initialize the three adjoining subfaces to be the omnipresent subface.
  newface->sh[0] = (shellface) dummysh;
  newface->sh[1] = (shellface) dummysh;
  newface->sh[2] = (shellface) dummysh;
  // Three NULL vertex points.
  newface->sh[3] = (shellface) NULL;
  newface->sh[4] = (shellface) NULL;
  newface->sh[5] = (shellface) NULL;
  // Initialize the two adjoining tetrahedra to be "outer space".
  newface->sh[6] = (shellface) dummytet;
  newface->sh[7] = (shellface) dummytet;
  // Initialize the three adjoining subsegments to be the omnipresent
  //   subsegments.
  newface->sh [8] = (shellface) dummysh;
  newface->sh [9] = (shellface) dummysh;
  newface->sh[10] = (shellface) dummysh;
  // Set the boundary marker to zero.
  * (int *) (newface->sh + 11) = 0;
  // Initialize the version to be Zero.
  newface->shver = 0;
}

///////////////////////////////////////////////////////////////////////////////
// END                                                                       //
// Memory Management Routines                                                //
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Geometric Primitives                                                      //
// BEGIN                                                                     //
///////////////////////////////////////////////////////////////////////////////

inline bool mesh3d::iszero(const REAL value)
{
  if (noroundoff) {
    return value == 0.0;
  } else {
    return fabs(value) <= usertolerance;
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// iorient3d()    3D Orientation test.                                       //
//                                                                           //
// Return +1 if the point pd lies "below" the plane passing through pa, pb,  //
// and pc;  Return -1 if pd lies "above" the plane.  Return 0 if the points  //
// are coplanar.                                                             //
//                                                                           //
// "below" and "above" is defined use Right-Hand Rule, so that pa, pb, and   //
// pc appear in counterclockwise order when making a fist, the thumb points  //
// to the "above" direction of the plane.                                    //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

int mesh3d::iorient3d(point3d pa, point3d pb, point3d pc, point3d pd)
{
  orient3dcount++;

  if (!noexact) {
    // Using adaptive precision arithmetic and tolerance.
    REAL sign = orient3d(pa, pb, pc, pd);
    if (iszero(sign)) sign = 0.0;
    if (sign > 0) return (1);
    else if (sign < 0) return (-1);
    else return (0);
  } else {
    // Using as nearly exact arithmetic as required.
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MINMAX4(da, db, dc, dd, dMin, dMax) { \
      REAL dMax1, dMax2, dMin1, dMin2; \
      if (da > db) {dMax1 = da; dMin1 = db;} \
      else         {dMax1 = db; dMin1 = da;} \
      if (dc > dd) {dMax2 = dc; dMin2 = dd;} \
      else         {dMax2 = dd; dMin2 = dc;} \
      if (dMax1 > dMax2) dMax = dMax1; \
      else               dMax = dMax2; \
      if (dMin1 < dMin2) dMin = dMin1; \
      else               dMin = dMin2; \
    }
    REAL dXa = pa[0], dYa = pa[1], dZa = pa[2];
    REAL dXb = pb[0], dYb = pb[1], dZb = pb[2];
    REAL dXc = pc[0], dYc = pc[1], dZc = pc[2];
    REAL dXd = pd[0], dYd = pd[1], dZd = pd[2];

    REAL dMaxX, dMinX, dMaxY, dMinY, dMaxZ, dMinZ;

    REAL dDX2 = dXb - dXa;
    REAL dDX3 = dXc - dXa;
    REAL dDX4 = dXd - dXa;
    MINMAX4(dXa, dXb, dXc, dXd, dMinX, dMaxX);

    REAL dDY2 = dYb - dYa;
    REAL dDY3 = dYc - dYa;
    REAL dDY4 = dYd - dYa;
    MINMAX4(dYa, dYb, dYc, dYd, dMinY, dMaxY);

    REAL dDZ2 = dZb - dZa;
    REAL dDZ3 = dZc - dZa;
    REAL dDZ4 = dZd - dZa;
    MINMAX4(dZa, dZb, dZc, dZd, dMinZ, dMaxZ);
    REAL dMax = MAX( MAX(dMaxX-dMinX, dMaxY-dMinY), dMaxZ-dMinZ);

    // dDet is proportional to the cell volume
    REAL dDet = (dDX2*(dDY3*dDZ4 - dDY4*dDZ3)
                 + dDX3*(dDY4*dDZ2 - dDY2*dDZ4)
                 + dDX4*(dDY2*dDZ3 - dDY3*dDZ2));

    // Compute an upper bound on the error bound.
    REAL dError = usertolerance * dMax*dMax*dMax;

    // Note: This is an left-hand direction, we need translate
    //   it to right-hand direction we used.
    if (dDet > dError)
      return (-1);  // return (1);
    else if (dDet < -dError)
      return (1);   // return (-1);
    return(0);
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// iinsphere()    Insphere test.                                             //
//                                                                           //
// Determines whether point 'pe' is inside or outside the circumsphere of    //
// the tetrahedron formed by point pa, pb, pc, pd.                           //
//                                                                           //
// Return a positive value if the point 'pe' lies inside the sphere passing  //
// through pa, pb, pc, and pd; a negative value if it lies outside; and zero //
// if the five points are cospherical. The points pa, pb, pc, and pd must be //
// ordered so that they have a positive orientation (as defined by orient3d),//
// or the sign of the result will be reversed.                               //
//                                                                           //
// Note: We can skip to test pa, pb, pc, and pd 's orientation, because we   //
// always known the orientation of pa, pb, pc and pd in advance.             //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

int mesh3d::iinsphere(point3d pa, point3d pb, point3d pc, point3d pd,
                      point3d pe)
{
#ifdef SELF_CHECK
  assert(iorient3d(pa, pb, pc, pd) > 0);
#endif // defined SELF_CHECK

  inspherecount++;

  if (!noexact) {
    // Using adaptive precision arithmetic and tolerance.
    REAL sign = insphere(pa, pb, pc, pd, pe);
    if (iszero(sign)) sign = 0.0;
    if (sign > 0.) return (1);
    else if (sign < 0.) return (-1);
    else return (0);
  } else {
    // Using as nearly exact arithmetic as required.
#define dDet4By4(Mat4)                                    \
    (  Mat4[0][0] * (  Mat4[1][1]*Mat4[2][2]*Mat4[3][3]   \
                     + Mat4[1][2]*Mat4[2][3]*Mat4[3][1]   \
                     + Mat4[1][3]*Mat4[2][1]*Mat4[3][2]   \
                     - Mat4[3][1]*Mat4[2][2]*Mat4[1][3]   \
                     - Mat4[3][2]*Mat4[2][3]*Mat4[1][1]   \
                     - Mat4[3][3]*Mat4[2][1]*Mat4[1][2] ) \
     - Mat4[0][1] * (  Mat4[1][0]*Mat4[2][2]*Mat4[3][3]   \
                     + Mat4[1][2]*Mat4[2][3]*Mat4[3][0]   \
                     + Mat4[1][3]*Mat4[2][0]*Mat4[3][2]   \
                     - Mat4[3][0]*Mat4[2][2]*Mat4[1][3]   \
                     - Mat4[3][2]*Mat4[2][3]*Mat4[1][0]   \
                     - Mat4[3][3]*Mat4[2][0]*Mat4[1][2] ) \
     + Mat4[0][2] * (  Mat4[1][0]*Mat4[2][1]*Mat4[3][3]   \
                     + Mat4[1][1]*Mat4[2][3]*Mat4[3][0]   \
                     + Mat4[1][3]*Mat4[2][0]*Mat4[3][1]   \
                     - Mat4[3][0]*Mat4[2][1]*Mat4[1][3]   \
                     - Mat4[3][1]*Mat4[2][3]*Mat4[1][0]   \
                     - Mat4[3][3]*Mat4[2][0]*Mat4[1][1] ) \
     - Mat4[0][3] * (  Mat4[1][0]*Mat4[2][1]*Mat4[3][2]   \
                     + Mat4[1][1]*Mat4[2][2]*Mat4[3][0]   \
                     + Mat4[1][2]*Mat4[2][0]*Mat4[3][1]   \
                     - Mat4[3][0]*Mat4[2][1]*Mat4[1][2]   \
                     - Mat4[3][1]*Mat4[2][2]*Mat4[1][0]   \
                     - Mat4[3][2]*Mat4[2][0]*Mat4[1][1] ) \
    )
    REAL dXa = pa[0], dYa = pa[1], dZa = pa[2];
    REAL dXb = pb[0], dYb = pb[1], dZb = pb[2];
    REAL dXc = pc[0], dYc = pc[1], dZc = pc[2];
    REAL dXd = pd[0], dYd = pd[1], dZd = pd[2];
    REAL dXe = pe[0], dYe = pe[1], dZe = pe[2];

    REAL a2dInSphMat[4][4], dWa;
    dWa = dXa*dXa + dYa*dYa + dZa*dZa;

    a2dInSphMat[0][0] = dXb - dXa;
    a2dInSphMat[0][1] = dYb - dYa;
    a2dInSphMat[0][2] = dZb - dZa;
    a2dInSphMat[0][3] = dXb*dXb + dYb*dYb + dZb*dZb - dWa;

    a2dInSphMat[1][0] = dXc - dXa;
    a2dInSphMat[1][1] = dYc - dYa;
    a2dInSphMat[1][2] = dZc - dZa;
    a2dInSphMat[1][3] = dXc*dXc + dYc*dYc + dZc*dZc - dWa;

    a2dInSphMat[2][0] = dXd - dXa;
    a2dInSphMat[2][1] = dYd - dYa;
    a2dInSphMat[2][2] = dZd - dZa;
    a2dInSphMat[2][3] = dXd*dXd + dYd*dYd + dZd*dZd - dWa;

    a2dInSphMat[3][0] = dXe - dXa;
    a2dInSphMat[3][1] = dYe - dYa;
    a2dInSphMat[3][2] = dZe - dZa;
    a2dInSphMat[3][3] = dXe*dXe + dYe*dYe + dZe*dZe - dWa;

    // Set up a scale that is the average of the distance from A to each
    // of the other verts.  Use some trickery to take advantage of
    // already knowing what the differences in coordinates are.
    REAL dAveLen = 0.25 * (Mag3D(a2dInSphMat[0])
                           + Mag3D(a2dInSphMat[1])
                           + Mag3D(a2dInSphMat[2])
                           + Mag3D(a2dInSphMat[3]));
    REAL dScale = pow(dAveLen, 5);
    // REAL dDet = dDet4By4(a2dInSphMat) / dScale *
    //             iorient3d(pa, pb, pc, pd);
    REAL dDet = dDet4By4(a2dInSphMat) / dScale;
    if (dDet >  userubtolerance) {
      return (1); // return (-1);
    } else if (dDet < -userubtolerance) {
      return (-1); // return ( 1);
    } else {
      return (0);
    }
  }
}

int mesh3d::iinsphere(triface* tface, point3d testpoint)
{
  point3d torg, tdest, tapex, toppo;

  org(*tface, torg);
  dest(*tface, tdest);
  apex(*tface, tapex);
  oppo(*tface, toppo);
  // We need form a positive orientation of this points before test.
  if (EdgeRing(tface->ver) == CCW) {
    return iinsphere(tdest, torg, tapex, toppo, testpoint);
  } else {
    return iinsphere(torg, tdest, tapex, toppo, testpoint);
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Some convient functions for Geometric Primitives.                         //
//                                                                           //
// isbelowplane     Return ture iff point is 'below' the plane.              //
// isaboveplane     Return true iff point is 'above' the plane.              //
// iscoplane        Return true iff points are coplane.                      //
// iscoline         Return true iff three points are colinear.               //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

bool mesh3d::isbelowplane(triface* tface, point3d testpoint)
{
  point3d torg, tdest, tapex;

  org(*tface, torg);
  dest(*tface, tdest);
  apex(*tface, tapex);
  return iorient3d(torg, tdest, tapex, testpoint) > 0;
}

bool mesh3d::isaboveplane(triface* tface, point3d testpoint)
{
  point3d torg, tdest, tapex;

  org(*tface, torg);
  dest(*tface, tdest);
  apex(*tface, tapex);
  return iorient3d(torg, tdest, tapex, testpoint) < 0;
}

bool mesh3d::iscoplane(triface* tface, point3d testpoint)
{
  point3d torg, tdest, tapex;

  org(*tface, torg);
  dest(*tface, tdest);
  apex(*tface, tapex);
  return iorient3d(torg, tdest, tapex, testpoint) == 0;
}

bool mesh3d::isbelowplane(point3d pa, point3d pb, point3d pc, point3d pd)
{
  return iorient3d(pa, pb, pc, pd) > 0;
}

bool mesh3d::isaboveplane(point3d pa, point3d pb, point3d pc, point3d pd)
{
  return iorient3d(pa, pb, pc, pd) < 0;
}

bool mesh3d::iscoplane(point3d pa, point3d pb, point3d pc, point3d pd)
{
  return iorient3d(pa, pb, pc, pd) == 0;
}

bool mesh3d::iscoline(point3d pa, point3d pb, point3d pc)
{
  REAL v0[3], v1[3], v2[3];

  Sub3D(pa, pc, v0);
  Sub3D(pb, pc, v1);
  Cross3D(v0, v1, v2);
  return (iszero(v2[0])) && (iszero(v2[1])) && (iszero(v2[2]));
}

///////////////////////////////////////////////////////////////////////////////
// END                                                                       //
// Geometric Primitives                                                      //
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Geometric Functions                                                       //
// BEGIN                                                                     //
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// projontoface()    Get the orthogonal projection of point 'p' onto the     //
//                   plane passing through points a, b and c. Return by 'p'. //
//                                                                           //
// Given a facet F(contains point a, b and c) and a point p, the orthogonal  //
// projection p' of p onto F is the point that is coplanar with points a, b  //
// and c, and satisfies the requirement that the line pp' is orthogonal to F.//
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::projontoface(point3d a, point3d b, point3d c, point3d p)
{
  REAL ba[3], ca[3], pa[3], n[3];
  REAL dist;

  // Get unit normal of face abc.
  Sub3D(b, a, ba);
  Sub3D(c, a, ca);
  Cross3D(ba, ca, n);
  Normalize3D(n);

  Sub3D(p, a, pa);
  dist = Dot3D(pa, n);

  p[0] -= dist * n[0];
  p[1] -= dist * n[1];
  p[2] -= dist * n[2];
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// circumcenter()    Get the equatorial shpere center of a triangular face   //
//                   defines by vertices a, b and c. Return by 'res'.        //
//                                                                           //
// Equatorial shpere of a triangular face is the smallest sphere that passes //
// through the three vertices of the face.                                   //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::circumcenter(point3d a, point3d b, point3d c, point3d res)
{
  REAL adRow1[3], adRow2[3], adRow3[3];
  REAL dRHS1, dRHS2, dRHS3;
  REAL dTemp;

  Sub3D(a, b, adRow1);
  Sub3D(a, c, adRow2);
  Cross3D(adRow1, adRow2, adRow3);

#ifdef SELF_CHECK
  if (noexact) {
    noexact = 0;
    // Check three dividers to catch precission problems before going on.
    REAL adOrg[3] = {0, 0, 0};
    if (iorient3d(adRow1, adRow2, adRow3, adOrg) == 0) {
      printf("Precssion error in circumcenter():\n");
      printf("  Try to find circumcenter from three almost colinear points:\n");
      printf("    point 1: (%.12g, %.12g, %.12g).\n", a[0], a[1], a[2]);
      printf("    point 2: (%.12g, %.12g, %.12g).\n", b[0], b[1], b[2]);
      printf("    point 3: (%.12g, %.12g, %.12g).\n", c[0], c[1], c[2]);
      printf("  This probably means I am trying to refine mesh by splitting\n");
      printf("    a nearly degenerate subface(which created by the approximate\n");
      printf("    finite precision of floating point arithmetic).\n");
      noexact = 1;
      precisionerror();
    }
    noexact = 1;
  }
#endif // defined SELF_CHECK

  dRHS1 = 0.5 * (Dot3D(a, a) - Dot3D(b, b));
  dRHS2 = 0.5 * (Dot3D(a, a) - Dot3D(c, c));
  dRHS3 = Dot3D(a, adRow3);

  // Gussian elimination. Solve 3 by 3 linear system.

  // Pivot first column
  if (fabs(adRow1[0]) >= fabs(adRow2[0]) &&
      fabs(adRow1[0]) >= fabs(adRow3[0])) {
    ;
  } else if (fabs(adRow2[0]) >= fabs(adRow3[0])) {
    dTemp = dRHS1;
    dRHS1 = dRHS2;
    dRHS2 = dTemp;
    Swap3D(adRow1, adRow2);
  } else {
    dTemp = dRHS1;
    dRHS1 = dRHS3;
    dRHS3 = dTemp;
    Swap3D(adRow1, adRow3);
  }

  // Eliminate first column
  dRHS2 -= dRHS1 * adRow2[0]/adRow1[0];
  dRHS3 -= dRHS1 * adRow3[0]/adRow1[0];
  adRow2[1] = adRow2[1] - adRow1[1] * (adRow2[0]/adRow1[0]);
  adRow2[2] = adRow2[2] - adRow1[2] * (adRow2[0]/adRow1[0]);
  adRow3[1] = adRow3[1] - adRow1[1] * (adRow3[0]/adRow1[0]);
  adRow3[2] = adRow3[2] - adRow1[2] * (adRow3[0]/adRow1[0]);

  // Pivot second column
  if (fabs(adRow2[1]) >= fabs(adRow3[1])) {
    ;
  } else {
    dTemp = dRHS2;
    dRHS2 = dRHS3;
    dRHS3 = dTemp;
    Swap3D(adRow2, adRow3);
  }

  // Eliminate second column
  dRHS3 -= dRHS2 * adRow3[1]/adRow2[1];
  adRow3[2] = adRow3[2] - adRow2[2] * (adRow3[1]/adRow2[1]);

  // Solve for dRHS3 and back-substitute
  res[2] = dRHS3 /= adRow3[2];
  dRHS2 -= adRow2[2] * dRHS3;
  dRHS1 -= adRow1[2] * dRHS3;

  // Solve for dRHS2 and back-substitute
  res[1] = dRHS2 /= adRow2[1];
  dRHS1 -= adRow1[1] * dRHS2;

  // Solve for dRHS1
  res[0] = dRHS1 /= adRow1[0];
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// circumcenter()    Get the circumcenter of four points a, b, c and d.      //
//                   Return by 'res'.                                        //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::circumcenter(point3d a, point3d b, point3d c, point3d d,
                          point3d res)
{
  REAL adRow1[3], adRow2[3], adRow3[3];
  REAL dRHS1, dRHS2, dRHS3;
  REAL dTemp;

  Sub3D(a, b, adRow1);
  Sub3D(a, c, adRow2);
  Sub3D(a, d, adRow3);

#ifdef SELF_CHECK
  if (noexact) {
    noexact = 0;
    if (iorient3d(a, b, c, d) == 0) {
      printf("Precssion error in circumcenter():\n");
      printf("  Try to find circumcenter from four almost coplanar points:\n");
      printf("    point 1: (%.12g, %.12g, %.12g).\n", a[0], a[1], a[2]);
      printf("    point 2: (%.12g, %.12g, %.12g).\n", b[0], b[1], b[2]);
      printf("    point 3: (%.12g, %.12g, %.12g).\n", c[0], c[1], c[2]);
      printf("    point 4: (%.12g, %.12g, %.12g).\n", d[0], d[1], d[2]);
      printf("  This probably means I am trying to refine mesh by splitting\n");
      printf("    a nearly degenerate tetrahedron(which created by the \n");
      printf("    approximate finite precision of floating point arithmetic).\n");
      noexact = 1;
      precisionerror();
    }
    noexact = 1;
  }
#endif // defined SELF_CHECK

  dRHS1 = 0.5 * (Dot3D(a, a) - Dot3D(b, b));
  dRHS2 = 0.5 * (Dot3D(a, a) - Dot3D(c, c));
  dRHS3 = 0.5 * (Dot3D(a, a) - Dot3D(d, d));

  // Gussian elimination. Solve 3 by 3 linear system.

  // Pivot first column
  if (fabs(adRow1[0]) >= fabs(adRow2[0]) &&
      fabs(adRow1[0]) >= fabs(adRow3[0])) {
    ;
  } else if (fabs(adRow2[0]) >= fabs(adRow3[0])) {
    dTemp = dRHS1;
    dRHS1 = dRHS2;
    dRHS2 = dTemp;
    Swap3D(adRow1, adRow2);
  } else {
    dTemp = dRHS1;
    dRHS1 = dRHS3;
    dRHS3 = dTemp;
    Swap3D(adRow1, adRow3);
  }

  // Eliminate first column
  dRHS2 -= dRHS1 * adRow2[0]/adRow1[0];
  dRHS3 -= dRHS1 * adRow3[0]/adRow1[0];
  adRow2[1] = adRow2[1] - adRow1[1] * (adRow2[0]/adRow1[0]);
  adRow2[2] = adRow2[2] - adRow1[2] * (adRow2[0]/adRow1[0]);
  adRow3[1] = adRow3[1] - adRow1[1] * (adRow3[0]/adRow1[0]);
  adRow3[2] = adRow3[2] - adRow1[2] * (adRow3[0]/adRow1[0]);

  // Pivot second column
  if (fabs(adRow2[1]) >= fabs(adRow3[1])) {
    ;
  } else {
    dTemp = dRHS2;
    dRHS2 = dRHS3;
    dRHS3 = dTemp;
    Swap3D(adRow2, adRow3);
  }

  // Eliminate second column
  dRHS3 -= dRHS2 * adRow3[1]/adRow2[1];
  adRow3[2] = adRow3[2] - adRow2[2] * (adRow3[1]/adRow2[1]);

  // Solve for dRHS3 and back-substitute
  res[2] = dRHS3 /= adRow3[2];
  dRHS2 -= adRow2[2] * dRHS3;
  dRHS1 -= adRow1[2] * dRHS3;

  // Solve for dRHS2 and back-substitute
  res[1] = dRHS2 /= adRow2[1];
  dRHS1 -= adRow1[1] * dRHS2;

  // Solve for dRHS1
  res[0] = dRHS1 /= adRow1[0];
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// tetvolume()    Get the volume of tetrahedron formed by vertices a, b, c   //
//                and d.                                                     //
//                                                                           //
// Note: The return value may be negative. True volume is fabs(retval).      //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

REAL mesh3d::tetvolume(point3d a, point3d b, point3d c, point3d d)
{
  REAL adVec1[3], adVec2[3], adVec3[3];
  REAL adCross[3];

  Sub3D(b, a, adVec1);
  Sub3D(c, a, adVec2);
  Sub3D(d, a, adVec3);

  Cross3D(adVec2, adVec3, adCross);
  return Dot3D(adCross, adVec1) / 6.;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// facedihedral()    Get the diahedral angle of two faces, given by their    //
//                   vertices.                                               //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

REAL mesh3d::facedihedral(point3d forg1, point3d fdest1, point3d fapex1,
                          point3d forg2, point3d fdest2, point3d fapex2)
{
  REAL adNorm0[3], adNorm1[3];
  REAL dScale, dDot;

  Normal3D(forg1, fdest1, fapex1, adNorm0);
  Normalize3D(adNorm0);
  Normal3D(forg2, fdest2, fapex2, adNorm1);
  Normalize3D(adNorm1);

  dScale = 180. / acos(-1.);
  dDot = -Dot3D(adNorm0, adNorm1);
  if (dDot > 1.) dDot = 1.;
  else if (dDot < -1.) dDot = -1.;
  return acos(dDot) * dScale;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// tetalldihedral()    Get all(six) dihedral angles in tetrahedron form by   //
//                     vertices a, b, c and d. Return by array adDihed[6].   //
//                                                                           //
// The order in which the dihedrals are assigned matters for computation of  //
// solid angles. The way they're currently set up, combining them as (0,1,2),//
// (0,3,4), (1,3,5), (2,4,5) gives (in order) solid angles at vertices a, b, //
// c and d.                                                                  //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::tetalldihedral(point3d a, point3d b, point3d c, point3d d,
                            REAL adDihed[6])
{
  REAL adNorm0[3], adNorm1[3], adNorm2[3], adNorm3[3];
  REAL dScale, dDot;

  Normal3D(c, b, d, adNorm0);
  Normalize3D(adNorm0);
  Normal3D(a, c, d, adNorm1);
  Normalize3D(adNorm1);
  Normal3D(b, a, d, adNorm2);
  Normalize3D(adNorm2);
  Normal3D(a, b, c, adNorm3);
  Normalize3D(adNorm3);

  dScale = 180. / acos(-1.);
  dDot = -Dot3D(adNorm0, adNorm1);
  if (dDot > 1.) dDot = 1.;
  else if (dDot < -1.) dDot = -1.;
  adDihed[5] = acos(dDot) * dScale; // Edge CD

  dDot = -Dot3D(adNorm0, adNorm2);
  if (dDot > 1.) dDot = 1.;
  else if (dDot < -1.) dDot = -1.;
  adDihed[4] = acos(dDot) * dScale; // Edge BD

  dDot = -Dot3D(adNorm0, adNorm3);
  if (dDot > 1.) dDot = 1.;
  else if (dDot < -1.) dDot = -1.;
  adDihed[3] = acos(dDot) * dScale; // Edge BC

  dDot = -Dot3D(adNorm1, adNorm2);
  if (dDot > 1.) dDot = 1.;
  else if (dDot < -1.) dDot = -1.;
  adDihed[2] = acos(dDot) * dScale; // Edge AD

  dDot = -Dot3D(adNorm1, adNorm3);
  if (dDot > 1.) dDot = 1.;
  else if (dDot < -1.) dDot = -1.;
  adDihed[1] = acos(dDot) * dScale; // Edge AC

  dDot = -Dot3D(adNorm2, adNorm3);
  if (dDot > 1.) dDot = 1.;
  else if (dDot < -1.) dDot = -1.;
  adDihed[0] = acos(dDot) * dScale; // Edge AB
}

///////////////////////////////////////////////////////////////////////////////
// END                                                                       //
// Geometric Functions                                                       //
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Point Location Routines                                                   //
// BEGIN                                                                     //
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//   A crucial step in implementing many mesh generation algorithms is the   //
// point location problem. For example, in incremental insertion algorithms, //
// for each vertex to be inserted, we need to find the tetrahedron in which  //
// this vertex lies, so that it may be inserted.  In many circumstances, the //
// dominant cost is the time required for point location.                    //
//                                                                           //
//   Fortunately the point location problem is well studied in computational //
// geometry literature and and several theoretically optimal algorithms have //
// been proposed, such as the "Bucketing" algorithm of Asano et al.[1], the  //
// "Alternating Digital Tree(ADT)" algorithm of Bonet and Peraire[2] and the //
// Fast Randomized Point Location algorithm of Mucke, Isaac and Zhu[3], etc. //
// Where [3] is more suitable and faster algorithm for our 3D Delaunay mesh  //
// generator.                                                                //
//                                                                           //
//   Our mesh data structure is very suitable for implementing the algorithm //
// in [3], and with using the Adaptive Exact Geometric Predicates package of //
// Shewchuk to improve the robustness of implementation(use -X swith).       //
//                                                                           //
// Please see tetlib.h and predicate.h to learn more about the mesh data     //
// structure and exact floating-point arithmetic.                            //
//                                                                           //
// Refernces:                                                                //
//                                                                           //
// [1] T. Asano, M. Edahiro, H. Imai, M. Iri, and K. Murota. Practical use   //
//     of bucketing techniques in computational geometry. In G. T. Toussaint,//
//     editor, Computational Geometry, pages 153-195. North-Holland,         //
//     Amsterdam, Netherlands, 1985.                                         //
// [2] J. Bonet and J. Peraire. An alternating digital tree (ADT) algorithm  //
//     for 3D geometric searching and intersection problems. International   //
//     Journal for Numerical Methods in Engineering, 31:1-17, 1991.          //
// [3] Ernst P. Mucke, Isaac Saias, and Binhai Zhu, Fast Randomized Point    //
//     Location Without Preprocessing in Two- and Three-dimensional Delaunay //
//     Triangulations, Proceedings of the Twelfth Annual Symposium on        //
//     Computational Geometry, ACM, May 1996.                                //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// randomnation()    Generate a random number between 0 and 'choices' - 1.   //
//                                                                           //
// This is a simple linear congruential random number generator. Hence,it is //
// a bad random number generator, but good enough for most randomized geome- //
// tric algorithms.                                                          //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

unsigned long mesh3d::randomnation(unsigned int choices)
{
  randomseed = (randomseed * 1366l + 150889l) % 714025l;
  return randomseed / (714025l / choices + 1);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// makepointmap()    Construct a mapping from points to tetrahedra to        //
//                   improve the speed of point location for subsegment and  //
//                   subfacet insertion.                                     //
//                                                                           //
// Traverses all the tetrahedra, and provides each corner of each            //
// tetrahedron with a pointer to that tetrahedera. Of course, pointers will  //
// be overwritten by other pointers because (almost) each point is a corner  //
// of several tetrahedra, but in the end every point will point to some      //
// tetrahedron that contains it.                                             //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::makepointmap()
{
  triface tetloop;
  point3d pointptr;

  if (verbose) {
    printf("  Constructing mapping from points to tetrahedra.\n");
  }
  tetrahedrons.traversalinit();
  tetloop.tet = tetrahedrontraverse();
  while (tetloop.tet != (tetrahedron *) NULL) {
    // Check all four points of the tetrahedron.
    org(tetloop, pointptr);
    setpoint2tet(pointptr, encode(tetloop));
    dest(tetloop, pointptr);
    setpoint2tet(pointptr, encode(tetloop));
    apex(tetloop, pointptr);
    setpoint2tet(pointptr, encode(tetloop));
    oppo(tetloop, pointptr);
    setpoint2tet(pointptr, encode(tetloop));
    // Get another tet.
    tetloop.tet = tetrahedrontraverse();
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// isintet()    Determine whether a vertex lies inside, on or outside a      //
//              tetrahedron.                                                 //
//                                                                           //
// For 'testpoint' to be inside the tetrahedron formed by pa, pb, pc and pd, //
// the orientation has to be right with respect to every face of tetrahedron.//
//                                                                           //
// Return OUTSIDE if the point lies outside the tet; Return ONVERTEX if it   //
// coincides with a vertex in the tet;  Return ONEDGE if it lies on an edge; //
// Return ONFACE if it lies on a face; and Return INTETRAHEDRON if it lies   //
// strictly inside.                                                          //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

enum mesh3d::locateresult
mesh3d::isintet(point3d pa, point3d pb, point3d pc, point3d pd,
                point3d testpoint)
{
  int isign, icheck, iretval;

  // Get orientation of pa, pb, pc and pd.
  isign = iorient3d(pa, pb, pc, pd);
  assert(isign != 0);

  iretval = 0;
  icheck = iorient3d(pb, pd, pc, testpoint) * isign;
  if (icheck == -1) return OUTSIDE;
  iretval += icheck;

  icheck = iorient3d(pc, pd, pa, testpoint) * isign;
  if (icheck == -1) return OUTSIDE;
  iretval += icheck;

  icheck = iorient3d(pa, pd, pb, testpoint) * isign;
  if (icheck == -1) return OUTSIDE;
  iretval += icheck;

  icheck = iorient3d(pa, pb, pc, testpoint) * isign;
  if (icheck == -1) return OUTSIDE;
  iretval += icheck;

  if (iretval == 1) {
    return ONVERTEX;
  } else if (iretval == 2) {
    return ONEDGE;
  } else if (iretval == 3) {
    return ONFACE;
  } else {
    return INTETRAHEDRON;
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// distance()    Returns the minimum "distance" of triface to point p.       //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

static REAL square (REAL x)
{
  return (x * x);
}

REAL mesh3d::distance(triface* tface, point3d p)
{
#define Min(X,Y)  (((X) < (Y)) ? (X) : (Y))
  REAL d, da, db, dc;
  point3d tp;

  org(*tface, tp);
  da = square(p[0] - tp[0]) + square(p[1] - tp[1]) + square(p[2] - tp[2]);
  dest(*tface, tp);
  db = square(p[0] - tp[0]) + square(p[1] - tp[1]) + square(p[2] - tp[2]);
  apex(*tface, tp);
  dc = square(p[0] - tp[0]) + square(p[1] - tp[1]) + square(p[2] - tp[2]);
  d = Min (da, db);
  return (Min (d, dc));
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// iscoplanarintri()    Determine whether a vertex lies inside, on or        //
//                      outside a triangle in 3D. It assume the vert and the //
//                      triangle are coplanar. Approximate test. Nonrobust.  //
//                                                                           //
// Return OUTSIDE if the vertex lies outside the triangle.                   //
//                                                                           //
// Returns ONVERTEX if the point lies on an existing vertex.  'searchtet' is //
// a handle whose origin is the existing vertex.                             //
//                                                                           //
// Returns ONEDGE if the point lies on a mesh edge.  'searchtet' is a handle //
// whose face version is the edge on which the point lies.                   //
//                                                                           //
// Returns ONFACE if the point lies strictly within a facet.  1searchtet' is //
// a handle whose location is the face on which the point lies.              //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

enum mesh3d::locateresult
mesh3d::iscoplanarintri(point3d searchpoint, triface* searchtet)
{
  point3d torg, tdest, tapex;
  const REAL dTol = 5.e-9;
  const REAL dFloor = 1.e-6;
  REAL dSum, dDiff;                // Tempory variables used in fuzzycomp().
  int iCompRes;

#define fuzzycomp(dA, dB, iRes)                                            \
  dSum  = fabs(dA) + fabs(dB);                                             \
  dDiff = dA - dB;                                                         \
  dSum = (dSum > dFloor) ? dSum : dFloor;                                  \
  if (dDiff > dTol * dSum) iRes = 1;                                       \
  else if (dDiff < - dTol * dSum) iRes = -1;                               \
  else iRes = 0;

#define orient2dfast(pa, pb, pc)                                           \
  ((pa[0] - pc[0]) * (pb[1] - pc[1]) - (pa[1] - pc[1]) * (pb[0] - pc[0]))

// #define iszero3(v) (iszero(v[0]) && iszero(v[1]) && iszero(v[2]))
#define iszero3(v) \
  (sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]) <= userubtolerance)

  org(*searchtet, torg); //  torg = searchtet->org();
  // First find out the on vertex case, this must do first.
  fuzzycomp(searchpoint[0], torg[0], iCompRes);
  if (iCompRes == 0) {
    fuzzycomp(searchpoint[1], torg[1], iCompRes);
    if (iCompRes == 0) {
      fuzzycomp(searchpoint[2], torg[2], iCompRes);
      if (iCompRes == 0) {
        return ONVERTEX;
      }
    }
  }

  dest(*searchtet, tdest); // tdest = searchtet->dest();
  fuzzycomp(searchpoint[0], tdest[0], iCompRes);
  if (iCompRes == 0) {
    fuzzycomp(searchpoint[1], tdest[1], iCompRes);
    if (iCompRes == 0) {
      fuzzycomp(searchpoint[2], tdest[2], iCompRes);
      if (iCompRes == 0) {
        enextself(*searchtet);
        return ONVERTEX;
      }
    }
  }

  apex(*searchtet, tapex); // tapex = searchtet->apex();
  fuzzycomp(searchpoint[0], tapex[0], iCompRes);
  if (iCompRes == 0) {
    fuzzycomp(searchpoint[1], tapex[1], iCompRes);
    if (iCompRes == 0) {
      fuzzycomp(searchpoint[2], tapex[2], iCompRes);
      if (iCompRes == 0) {
        enext2self(*searchtet);
        return ONVERTEX;
      }
    }
  }

  // Next find out the on edge case.
  REAL v0[3], v1[3], v2[3];
  int iCompRes1, iCompRes2;

  Sub3D(torg, searchpoint, v0);
  Sub3D(tdest, searchpoint, v1);
  Cross3D(v0, v1, v2);
  if (iszero3(v2)) {
    fuzzycomp(torg[0], searchpoint[0], iCompRes1);
    fuzzycomp(searchpoint[0], tdest[0], iCompRes2);
    if ((iCompRes1 != 1) == (iCompRes2 != 1)) {
      fuzzycomp(torg[1], searchpoint[1], iCompRes1);
      fuzzycomp(searchpoint[1], tdest[1], iCompRes2);
      if ((iCompRes1 != 1) == (iCompRes2 != 1)) {
        fuzzycomp(torg[2], searchpoint[2], iCompRes1);
        fuzzycomp(searchpoint[2], tdest[2], iCompRes2);
        if ((iCompRes1 != 1) == (iCompRes2 != 1)) {
          return ONEDGE;
        }
      }
    }
  }
  Sub3D(tapex, searchpoint, v0);
  Cross3D(v0, v1, v2);
  if (iszero3(v2)) {
    fuzzycomp(tdest[0], searchpoint[0], iCompRes1);
    fuzzycomp(searchpoint[0], tapex[0], iCompRes2);
    if ((iCompRes1 != 1) == (iCompRes2 != 1)) {
      fuzzycomp(tdest[1], searchpoint[1], iCompRes1);
      fuzzycomp(searchpoint[1], tapex[1], iCompRes2);
      if ((iCompRes1 != 1) == (iCompRes2 != 1)) {
        fuzzycomp(tdest[2], searchpoint[2], iCompRes1);
        fuzzycomp(searchpoint[2], tapex[2], iCompRes2);
        if ((iCompRes1 != 1) == (iCompRes2 != 1)) {
          enextself(*searchtet);
          return ONEDGE;
        }
      }
    }
  }
  Sub3D(torg, searchpoint, v1);
  Cross3D(v0, v1, v2);
  if (iszero3(v2)) {
    fuzzycomp(tapex[0], searchpoint[0], iCompRes1);
    fuzzycomp(searchpoint[0], torg[0], iCompRes2);
    if ((iCompRes1 != 1) == (iCompRes2 != 1)) {
      fuzzycomp(tapex[1], searchpoint[1], iCompRes1);
      fuzzycomp(searchpoint[1], torg[1], iCompRes2);
      if ((iCompRes1 != 1) == (iCompRes2 != 1)) {
        fuzzycomp(tapex[2], searchpoint[2], iCompRes1);
        fuzzycomp(searchpoint[2], torg[2], iCompRes2);
        if ((iCompRes1 != 1) == (iCompRes2 != 1)) {
          enext2self(*searchtet);
          return ONEDGE;
        }
      }
    }
  }

  // Finally, to find if this point lies on face.
  REAL adNorm[3], adBasisX[3], adBasisY[3];
  REAL VProjA[2], VProjB[2], VProjC[2], VProj[2];
  REAL sign0, sign1, sign2;

  // Find a normal and two vectors in the plane.
  Sub3D(tdest, torg, v0);
  Sub3D(tapex, torg, v1);
  Cross3D(v0, v1, adNorm);
  Normalize3D(adNorm);
  Assign3D(v0, adBasisX);
  Normalize3D(adBasisX);
  Cross3D(adNorm, adBasisX, adBasisY);

  // Project onto a plane (adBasisX, adBasisY).
  VProjA[0] = Dot3D(torg, adBasisX);
  VProjA[1] = Dot3D(torg, adBasisY);
  VProjB[0] = Dot3D(tdest, adBasisX);
  VProjB[1] = Dot3D(tdest, adBasisY);
  VProjC[0] = Dot3D(tapex, adBasisX);
  VProjC[1] = Dot3D(tapex, adBasisY);
  VProj [0] = Dot3D(searchpoint, adBasisX);
  VProj [1] = Dot3D(searchpoint, adBasisY);

  sign0 = orient2dfast(VProjA, VProjB, VProj);
  sign1 = orient2dfast(VProjB, VProjC, VProj);
  sign2 = orient2dfast(VProjC, VProjA, VProj);

  if (((sign0 > 0.) == (sign1 > 0.)) && ((sign1 > 0.) == (sign2 > 0.))) {
    return ONFACE;
  } else {
    return OUTSIDE;
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// preciselocate()    Find a tetrahedron, a face or an edge containing a     //
//                    given point.                                           //
//                                                                           //
// Begins its search from 'searchtet'. It is important that 'searchtet' be a //
// handle with the property that 'searchpoint' is strictly lies 'above' of   //
// the facet denoted by 'searchtet', or is colplanar with that facet and     //
// does not intersect that facet. (In particular, 'searchpoint' should not   //
// be the vertex of that facet.)                                             //
//                                                                           //
// Returns ONVERTEX if the point lies on an existing vertex.  'searchtet' is //
// a handle whose origin is the existing vertex.                             //
//                                                                           //
// Returns ONEDGE if the point lies on a mesh edge.  'searchtet' is a handle //
// whose face version is the edge on which the point lies.                   //
//                                                                           //
// Returns ONFACE if the point lies strictly within a facet.  'searchtet' is //
// a handle whose location is the face on which the point lies.              //
//                                                                           //
// Returns INTETRAHEDRON if the point lies strictly within a tetrahededron.  //
// 'searchtet' is a handle on the tetrahedron that contains the point.       //
//                                                                           //
// Returns OUTSIDE if the point lies outside the mesh. 'searchtet' is a      //
// handle whose location is the face the point is to 'above' of. This might  //
// occur when the circumcenter of a tetrahedron falls just slightly outside  //
// the mesh due to floating-point roundoff error.  It also occurs when       //
// seeking a hole or region point that a foolish user has placed outside the //
// mesh.                                                                     //
//                                                                           //
// WARNING: This routine is designed for convex triangulations, and will not //
// generally work after the holes and concavities have been carved. However, //
// it can still be used to find the circumcenter of a triangle, a tetrahedron//
// as long as the search is begun from the tetrahedron in question.          //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

enum mesh3d::locateresult
mesh3d::preciselocate(point3d searchpoint, triface* searchtet)
{
  triface checkface, backtracetet;
  point3d torg, tdest, toppo;
  enum locateresult retval;
  int ahead, turns;

  assert(searchtet->tet != dummytet);
  if (verbose > 2) {
    printf("    Searching for point %d.\n", pointmark(searchpoint));
  }

  while (true) {
    // Check if we walk off the boundary of the triangulation.
    if (searchtet->tet == dummytet) {
      *searchtet = backtracetet;
      if (verbose > 2) {
        printf("    End Searching: Outside current mesh.\n");
      }
      return OUTSIDE;
    }
    if (verbose > 2) {
      printf("    From face (%d, %d, %d, %d)\n",
             pointmark(org(*searchtet)), pointmark(dest(*searchtet)),
             pointmark(apex(*searchtet)), pointmark(oppo(*searchtet)));
    }
    searchtet->ver = 0;
    // 'toppo' is the shared vertex at all orientation tests.
    oppo(*searchtet, toppo);
    // Check three side faces of 'searchtet' in order.
    //   To see if we need walk through this face.
    for (turns = 0; turns < 3; turns++) {
      fnext(*searchtet, checkface);
      org(checkface, torg);
      dest(checkface, tdest);
      ahead = iorient3d(torg, tdest, toppo, searchpoint);
      if (ahead == 0) {
        // Check if `searchpoint' is locate on face, on edge or on vertex.
        retval = iscoplanarintri(searchpoint, &checkface);
        if (retval != OUTSIDE) {
          *searchtet = checkface;
          if (verbose > 2) {
            printf("    End Searching: ");
            if (retval == ONVERTEX) {
              printf("On Vertex.");
            } else if (retval == ONEDGE) {
              printf("On Edge.");
            } else if (retval == ONFACE) {
              printf("On Face.");
            }
            printf("\n");
          }
          return retval;
        }
      } else if (ahead < 0) {
        // We need walk through this face and continue to search.
        backtracetet = checkface;
        sym(checkface, *searchtet);
        break;
      }
      enextself(*searchtet);
    }
    if (turns >= 3) {
      // Found! Inside tetrahedron.
      if (verbose > 2) {
        printf("    End Searching: Inside tetraheda.\n");
      }
      return INTETRAHEDRON;
    }
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// locate()    Find a tetrahedron, a face or an edge containing a given      //
//             point.                                                        //
//                                                                           //
// Searching begins from one of:  the input 'searchtet', a recently encount- //
// ered tetrahedron 'recenttet',  or from a tetrahedra chosen from a random  //
// sample.  The choice is made by determining which tetrahedron's vertexs is //
// closest to the point we are searcing for. Normally, 'searchtet' should be //
// a handle on the convex hull of the tetrahedrization.                      //
//                                                                           //
// On completion, 'searchtet' is a tetrahedron that contains 'searchpoint'.  //
//                                                                           //
// Returns ONVERTEX if the point lies on an existing vertex.  'searchtet' is //
// a handle whose origin is the existing vertex.                             //
//                                                                           //
// Returns ONEDGE if the point lies on a mesh edge.  'searchtet' is a handle //
// whose face version is the edge on which the point lies.                   //
//                                                                           //
// Returns ONFACE if the point lies strictly within a facet.  1searchtet' is //
// a handle whose location is the face on which the point lies.              //
//                                                                           //
// Returns INTETRAHEDRON if the point lies strictly within a tetrahededron.  //
// 'searchtet' is a handle on the tetrahedron that contains the point.       //
//                                                                           //
// Returns OUTSIDE if the point lies outside the mesh. 'searchtet' is a      //
// handle whose location is the face the point is to 'above' of. This might  //
// occur when the circumcenter of a tetrahedron falls just slightly outside  //
// the mesh due to floating-point roundoff error.  It also occurs when       //
// seeking a hole or region point that a foolish user has placed outside the //
// mesh.                                                                     //
//                                                                           //
// WARNING: This routine is designed for convex triangulations, and will not //
// not generally work after the holes and concavities have been carved.      //
//                                                                           //
// Details on the random sampling method can be found in [3].                //
//                                                                           //
// The simple method to implement this algorithm use  tet-tri data structure //
// is listed here: ( Suppose T is the current tetrahedrization, and p is the //
// point we are searching.)                                                  //
//                                                                           //
//   (1). Choose a random facet a (a belong to T), such that p belong to a+. //
//   (2). If T union a = NULL, then p lies outside the current triangulation,//
//        and a is visible from p. Otherwise,  there is a unique tetrahedron //
//        t(t include a+, t belong to T), If p belong to t, then p is locat- //
//        ed inside(the tetrahedron t(a+) of)T. In both cases we are done.If //
//        p not belong to t(a+), then there exists some facet b of the tetr- //
//        ahedron t(a+), with the same orientation of a, and p belong to b+. //
//        Repeat step (2) with a = b.                                        //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

enum mesh3d::locateresult
mesh3d::locate(point3d searchpoint, triface *searchtet)
{
  triface checkface;
  tetrahedron *firsttet, *tetptr;
  point3d torg, tdest, tapex;
  void **sampleblock;
  long sampleblocks, samplesperblock, samplenum;
  long tetblocks, i, j;
  unsigned long alignptr;
  REAL searchdist, dist;
  int ahead;

  // Record the distance from the suggested starting tetrahedron to the
  //   point we seek.
  if(searchtet->tet == dummytet) {
    // This is an 'Outer Space' handle, get a hull tetrahedron.
    searchtet->loc = 0;
    symself(*searchtet);
  }
  searchdist = distance(searchtet, searchpoint);

  // Select "good" candidate using k random samples, taking the closest one.
  //   (The trick here is that we use just normal FP distance() function.)

  // If a recently encountered tetrahedron has been recorded and has not
  //   been deallocated, test it as a good starting point.
  if (!isdead(&recenttet)) {
    // adjustedgering(recenttet, CCW);
    dist = distance(&recenttet, searchpoint);
    if (dist < searchdist) {
      *searchtet = recenttet;
      searchdist = dist;
    }
  }

  // The number of random samples taken is proportional to the cube root of
  //   the number of tetrahedra in the mesh. The next bit of code assumes
  //   that the number of tetrahedra increases monotonically.
  while (SAMPLEFACTOR * samples * samples * samples < tetrahedrons.items) {
    samples++;
  }
  // Find how much blocks in current tet pool.
  tetblocks = (tetrahedrons.maxitems + TETPERBLOCK - 1) / TETPERBLOCK;
  // Find the average samles per block. Each block at least have 1 sample.
  samplesperblock = 1 + (samples / tetblocks);
  sampleblocks = samples / samplesperblock;
  sampleblock = tetrahedrons.firstblock;
  for (i = 0; i < sampleblocks; i++) {
    alignptr = (unsigned long) (sampleblock + 1);
    firsttet = (tetrahedron *)
               (alignptr + (unsigned long) tetrahedrons.alignbytes
               - (alignptr % (unsigned long) tetrahedrons.alignbytes));
    for (j = 0; j < samplesperblock; j++) {
      if (i == tetblocks - 1) {
        // This is the last block.
        samplenum = randomnation((int)
                      (tetrahedrons.maxitems - (i * TETPERBLOCK)));
      } else {
        samplenum = randomnation(TETPERBLOCK);
      }
      tetptr = (tetrahedron *)
               (firsttet + (samplenum * tetrahedrons.itemwords));
      if (tetptr[4] != (tetrahedron) NULL) {
        checkface.tet = tetptr;
        dist = distance(&checkface, searchpoint);
        if (dist < searchdist) {
          *searchtet = checkface;
          searchdist = dist;
        }
      }
    }
    sampleblock = (void **) *sampleblock;
  }
  if (verbose > 2) {
    printf("    Randomly sampling %d times.\n", sampleblocks * samplesperblock);
  }

  // Orient 'searchtet' to fit the preconditions of calling preciselocate().
  adjustedgering(*searchtet, CCW);
  org(*searchtet, torg);
  dest(*searchtet, tdest);
  apex(*searchtet, tapex);
  ahead = iorient3d(torg, tdest, tapex, searchpoint);
  if (ahead > 0) {
    // 'searchpoint' is below the face, get the other side of the face.
    // Note: Must check first if searchtet is located on 'Outer Boundary'.
    if(!issymexist(searchtet)) {
      return OUTSIDE;
    }
    symself(*searchtet);
  } else if (ahead == 0) {
    // Check if `searchpoint' is locate on face, on edge or on vertex.
    enum locateresult retval = iscoplanarintri(searchpoint, searchtet);
    if (retval != OUTSIDE) {
      if (verbose > 2) {
        printf("    End Searching: ");
        if (retval == ONVERTEX) {
          printf("On Vertex.");
        } else if (retval == ONEDGE) {
          printf("On Edge.");
        } else if (retval == ONFACE) {
          printf("On Face.");
        }
        printf("\n");
      }
      return retval;
    }
  }
  return preciselocate(searchpoint, searchtet);
}

///////////////////////////////////////////////////////////////////////////////
// END                                                                       //
// Point Location Routines                                                   //
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Mesh Transformation Routines                                              //
// BEGIN                                                                     //
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Three-dimensional flip operators and algorithm.                           //
//                                                                           //
//   The "local transformation" (LTRANS for short) procedure for three-      //
// dimensional triangulations is analogous to the edge flipping procedure    //
// used first by Lawson[1] to construct two-dimensional triangulations. The  //
// LTRANS methods was instroduced (first) by Barry Joe[2]. He proved that    //
// the LTRANS can be used to construct a Delaunay triangulation when apply   //
// in an appropriate order to a special triangulation with his incermental   //
// flip algorithm[2].                                                        //
//                                                                           //
//   The LTRANS procedure is based on the possible configurations of five    //
// distinct non-coplanar three-dimensional points, a, b, c, d, e. See Barry  //
// Joe 's paper[2] fig 1 and fig 2. There show five possible configurations  //
// of the five points, named configuration 1 ,..., configuration 5. Let T be //
// a triangulation of the five points. the LTRANS procedure is that if the   //
// five points are in congiguration 1 or 3, then replace the triangulation   //
// T by other possible triangulation of the five points.The LTRANS procedure //
// can be consider to be a face swap. Joe also show that the LOTRANS applied //
// to the T are of the one of four types, called type 1 to 4(2-3 swap, 3-2   //
// swap, 2-2 swap, 4-4 swap, See paper[2] fig 3).                            //
//                                                                           //
//   Let T(i, 0) be the preliminary triangulation of the first i vertices    //
// obtained by joining the ith vertex to the visible bondary faces of T(i-1, //
// D). For k >= 1, let T(i, k) be the triangualtion obtained by applying the //
// LOTRANS procedure to a non-locally-optimal transformable(paper[1], defin- //
// ition 1 and 2) interior face of T(i, k-1). The following therom is proved //
// by Barry Joe(paper[2], Therom 3):                                         //
//   If T(i-1, D) is a Delaunay triangulation, then there exists a finite    //
//   m(m >= 0) such that T(i, m) = T(i, D) is a Delaunay triangulation.      //
//                                                                           //
//   Another useful notion in programming is face type, which described in   //
// [3]. Let abc be an interior face in a triangulation T of a point set V.   //
// Then abc is incident on two tetrahedron abcd and abce. We assign a face   //
// type to abc of the form 'Trs' and 'Nrs' where 'T' stands for transform-   //
// able and 'N' stands for nontransformable, and the possible types are:     //
// T23, T32, T22, T44, N44, N40, N30, N20. Except for the case r=s=4, 'r' is //
// number of tetrahedroa in the triangulation of a, b, c, d, e containing    //
// abcd and abce, and either 's' is zero if the configuration has only one   //
// possible triangulation or 's' is the number of tetrahedron in the other   //
// triangulation of a, b, c, d, e. the T44 and N44 types involv a sixth ver- //
// tex and a pair of simultaneous local transformations(involve 4 tetrahedron//
// before and after) as explained in paper[3].                               //
//                                                                           //
// Refernces:                                                                //
//                                                                           //
// [1] Lawson, C.L. (1977), Software for C1 surface interpolation, in J.R.   //
//     Rice, ed,. Mathematic Software III, Acadmeic Press, New York, 161-194.//
// [2] Barry Joe. Construction of three-dimensional Delaunay triangulations  //
//     using local transformations. Computer Aided Geometric Design, 8(1991),//
//     pp. 123-142.                                                          //
// [3] Barry Joe. Construction of Three-Dimensional Improved-Quality Triang- //
//     ulati on Using Local Transformations".  SIAM Journal on Scientific    //
//     Computing, 16(6):1292¨C1307, November 1995.                           //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// categorizeface()    Decide which type of triangular face this is, anyway. //
//                                                                           //
// The input is a handle of triangular face of a tetrahedron. Return an      //
// enumerate type of facecategory. Normally, the input handle will not be    //
// changed. If return 'eT32' and 'eN32',  function will reset the face       //
// version to the edge which is tansformable('eT32') or non-transformable    //
// ('eN32'). If return 'eT22', 'eT44', or 'eN44', function will reset the    //
// input face version to be the diagonal edge.                               //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

enum mesh3d::facecategory mesh3d::categorizeface(triface& horiz)
{
  triface symhoriz, abdcasing, bcdcasing, cadcasing;
  triface bad, abe, symbad, symabe;
  face tmpsh0, tmpsh1, tmpseg;
  point3d pa, pb, pc, pd, pe;
  point3d abdoppo, bcdoppo, cadoppo;
  int sharecount;

  sym(horiz, symhoriz);
  if (symhoriz.tet == dummytet) {
    return LOCKED;  // Can't swap a boundary face.
  }
  if (checksegments) {
    tspivot(horiz, tmpsh0);
    if (tmpsh0.sh != dummysh) {
      if (!isnonsolid(tmpsh0)) {
        return LOCKED;   // Can't swap a subface.
      }
    }
  }
  // Now we assume 'horiz' is tet<a, b, c, d>,
  adjustedgering(horiz, CCW);
  // Set 'symhoriz' be tet<b, a, c, e>.
  findversion(&symhoriz, &horiz);

  org(horiz, pa);
  dest(horiz, pb);
  apex(horiz, pc);
  oppo(horiz, pd);
  oppo(symhoriz, pe);

  // Find the number of tetrahedra that be a neighbor of both of the
  //   first two.
  sharecount = 2;
  abdoppo = bcdoppo = cadoppo = (point3d) NULL;

  // Set 'abdcasing', 'bcdcasing', 'cadcasing'.
  fnext(horiz, abdcasing);  // at edge<a, b>.
  if (issymexist(&abdcasing)) {
    symself(abdcasing);
    oppo(abdcasing, abdoppo);
    if (abdoppo == pe) sharecount++;
  }
  enextself(horiz);
  fnext(horiz, bcdcasing);  // at edge<b, c>.
  if (issymexist(&bcdcasing)) {
    symself(bcdcasing);
    oppo(bcdcasing, bcdoppo);
    if (bcdoppo == pe) sharecount++;
  }
  enextself(horiz);
  fnext(horiz, cadcasing);  // at edge<c, a>
  if (issymexist(&cadcasing)) {
    symself(cadcasing);
    oppo(cadcasing, cadoppo);
    if (cadoppo == pe) sharecount++;
  }
  enextself(horiz);  // Rewind.

  if (sharecount == 4) { // Four tet case.
    return N40;
  }

  if (sharecount == 3) { // Three tet case.
    if (abdoppo == pe) {
      // Check if edge<a, b> cross face<c, d, e>.
      if (!isbelowplane(pc, pd, pe, pa))
        return N30; // Either eN30 or eOther.
      if (!isaboveplane(pc, pd, pe, pb))
        return N30; // Either eN30 or eOther.
      // return eT32;  // Return edge<a, b>.
    } else if (bcdoppo == pe) {
      // Check if edge<b, c> cross the face<a, d, e>.
      if (!isbelowplane(pa, pd, pe, pb))
        return N30; // Either eN30 or eOther.
      if (!isaboveplane(pa, pd, pe, pc))
        return N30; // Either eN30 or eOther.
      enextself(horiz);
      // return eT32;  // Return edge<b, c>.
    } else {
      assert(cadoppo == pe);
      // Check if edge<c, a> cross the face<b, d, e>.
      if (!isbelowplane(pb, pd, pe, pc))
        return N30; // Either eN30 or eOther.
      if (!isaboveplane(pb, pd, pe, pa))
        return N30; // Either eN30 or eOther.
      enext2self(horiz);
      // return T32;  // Return edge<c, a>.
    }
    if (checksegments) {
      tsspivot(&horiz, &tmpseg);
      if (tmpseg.sh != dummysh) {
        // Unfortunately, it's a subsegment, not swappable.
        return LOCKED;
      }
    }
    return T32;
  } // End of three tet case.

  // Only leave two tets case: 'horiz' and 'symhoriz'.
  assert(sharecount == 2);
  // These returns take out all cases which allow the saving of an
  //   orientation primitive evaluation.  This is very useful, as
  //   this is a critical code path.
  // Check if e above face<b, c, d>.
  int iOrientA = iorient3d(pb, pc, pd, pe);
  if (iOrientA == -1) {
    enextself(horiz);
    return N32;  // Return edge<b, c>.
  }
  // Check if e above face<c, a, d>.
  int iOrientB = iorient3d(pc, pa, pd, pe);
  if (iOrientB == -1) {
    enext2self(horiz);
    return N32;  // Return edge<c, a>.
  }
  if (iOrientA + iOrientB == 0) return N20;
  // Check if e above face<a, b, d>.
  int iOrientC = iorient3d(pa, pb, pd, pe);
  if (iOrientC == -1) {
    return N32;  // Return edge<a, b>.
  }

  switch (iOrientA + iOrientB + iOrientC) {
    case 0:
      // Impossible, but included for completeness.
    case 1:
      // Two orientations are zero (three points co-linear). Hopelessly
      //   unswappable.  Bail out.
	    return N20;
    case 2:
      // Four points are coplanar; (T22, T44, N44) One orientation must
      //   be 0; verts are re-labeled to make it iOrientC. This implies
      //   that edge<a, b> is the coplanar edge.
      assert(!(iOrientA && iOrientB && iOrientC));
      if (iOrientA == 0) {
        // edge<b, c> is the diagonal.
        enextself(horiz);
        enext2self(symhoriz);
        org(horiz, pa);
        dest(horiz, pb);
        apex(horiz, pc);
      } else if (iOrientB == 0) {
        // edge<c, a> is the diagonal.
        enext2self(horiz);
        enextself(symhoriz);
        org(horiz, pa);
        dest(horiz, pb);
        apex(horiz, pc);
      }
      // Now we can sure edge<a, b> is the diagonal. Verify that the
      //   re-labeling was done correctly.
	    // assert(iorient3d(pa, pb, pd, pe) == 0);
      if (checksegments) {
        tsspivot(&horiz, &tmpseg);
        if (tmpseg.sh != dummysh) {
          // Unfortunately, it's a subsegment, not swappable.
          return LOCKED;
        }
      }

      // The configuration of these two tets is classified based on the
      //   properties of the coplanar faces:
      // 1 If both are BFaces with the same boundary condition, swappable
      //   two tets to two.
      // 2 If both are BFaces with different bdry cond, not swappable.
      // 3 If one is a BFace and the other not, not swappable.
      // 4 If neither is a BFace, both opposite cells are tets, and the
      //   tets have the same fourth vert, swappable four to four.
      // 5 If neither is a BFace, both opposite cells are tets, and the
      //   tets do not have the same fourth vert, not swappable, although
      //   some non-local transformations might make it so.
      // 6 If neither is a BFace and one or both opposite cells is not a
      //   tet, not swappable.
      fnext(horiz, bad);
      fnext(symhoriz, abe);
      sym(bad, symbad);
      sym(abe, symabe);

      if ((symbad.tet == dummytet) && (symabe.tet == dummytet)) {
        // Both faces are on the boundary.
        if (checksegments) {
          tspivot(bad, tmpsh0);
          tspivot(abe, tmpsh1);
          if ((tmpsh0.sh == dummysh) && (tmpsh1.sh == dummysh)) {
            return T22;       // case 1.
          } else if ((tmpsh0.sh != dummysh) && (tmpsh1.sh != dummysh)) {
            if (mark(tmpsh0) == mark(tmpsh1)) {
              return T22;     // case 1.
            } else {
              return LOCKED;  // case 2.
            }
          } else {
            if (tmpsh0.sh != dummysh) {
              if (isnonsolid(tmpsh0)) {
                return T22;   // case 1.
              }
            } else { // tmpsh1.sh != dummysh
              if (isnonsolid(tmpsh1)) {
                return T22;   // case 1.
              }
            }
            return LOCKED;    // case 2.
          }
        } else {
          return T22;         // case 1.
        }
      } else if ((symbad.tet != dummytet) && (symabe.tet != dummytet)) {
        // Both faces are inner facets.
        point3d badoppo, abeoppo;
        oppo(symbad, badoppo);
        oppo(symabe, abeoppo);
        if (badoppo == abeoppo) {
          if (checksegments) {
            tspivot(bad, tmpsh0);
            tspivot(abe, tmpsh1);
            if ((tmpsh0.sh == dummysh) && (tmpsh1.sh == dummysh)) {
              return T44;     // case 1.
            } else if ((tmpsh0.sh != dummysh) && (tmpsh1.sh != dummysh)) {
              if (mark(tmpsh0) == mark(tmpsh1)) {
                return T44;   // case 1.
              } else {
                return LOCKED; // case 2.
              }
            } else {
              if (tmpsh0.sh == dummysh) {
                if (isnonsolid(tmpsh1)) {
                  return T44; // case 1.
                }
              } else {
                if (isnonsolid(tmpsh0)) {
                  return T44; // case 1.
                }
              }
              return LOCKED;   // case 2.
            }
          } else {
            return T44;       // case 4.
          }
        } else {
          return N44;         // case 5.
        }
      } else {
        // Exactly one face on the boundary or internal faces with cells
        //   other than tets
	      return LOCKED;         // cases 3, 6.
      }
    case 3:
      // Configuration is convex and therefore swappable two tets to three.
	    return T23;
    default:
	    // No other cases should be possible
	    assert(0);
      return LOCKED;
  } // End of switch.
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// querydoswap()    Determines whether swapping is needed for current seting //
//                  swaptype.                                                //
//                                                                           //
// There are many measures can be used, like Delaunay criterion, local max-  //
// min solid angle criterion and max-min dihedral angle, etc. Current only   //
// use the Delaunay criterion.                                               //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

bool mesh3d::querydoswap(triface& queryface)
{
  triface symface;
  point3d symoppo;

  sym(queryface, symface);
  assert(symface.tet != dummytet);
  oppo(symface, symoppo);
  int sign = iinsphere(&queryface, symoppo);
  if (sign > 0) {
    return (true);
  } else if (sign < 0) {
    return (false);
  } else {
    cospherecount ++;
    return (false);
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// preservesubsegments()    Preserve subsegments that abutting a flipping    //
//                          subface(must be nonsolid).                       //
//                                                                           //
// This routine used in all local transformation routines to prevent missing //
// subsegments when flip away a nonsolid subface. The inputs are a handle    //
// of flipping face 'abc'(must be a nonsolid subface) and a handle of tetra  //
// that abutting this face 'abcd'. This routine will check each side of face //
// 'abc', to see if their exist a subsegment abutting at this side. If find, //
// still need determine whether there exist another subfaces hold this       //
// subsegment. If no such subface be found. We must insert a subface for     //
// holding this subsegment, otherwise, this subsegment will missing after do //
// flip. At each case, the face 'abc' will dealloc at end. Before 'abc' is   //
// deallocated, we must dissolve it from its two adjacent tets, otherwise,   //
// one of tet may still think it is connecting a subface.                    //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::preservesubsegments(face& abc, triface& abcd)
{
  triface tmpabcd, spintet;
  face checkseg, checksh;
  point3d tapex;
  int edgecount, successbonded, hitbdry;

  tmpabcd = abcd;
  adjustedgering(tmpabcd, CCW);              // For fnext() should be exist.
  findversion(&abc, &tmpabcd, false);    // For keep same enext() direction.

  edgecount = 0;
  while (edgecount < 3) {
    sspivot(abc, checkseg);
    if (checkseg.sh != dummysh) {
      // Find a subsegment adjoining at a nonsolid subface('abc').
      spivot(checkseg, checksh);
      if (checksh.sh != abc.sh) {
        // There must exist another subface that hold this segment. We can
        //   safely deallocte this subface.
      } else {
        // We must find another subface to hold this segment, if no such
        //   subface be found. Then we should insert a nonsolid subface.
        spintet = tmpabcd;
        apex(tmpabcd, tapex);
        successbonded = hitbdry = 0;
        while (true) {
          if (fnextself(spintet)) {
            if (apex(spintet) == tapex) {
              break; // Rewind, can leave now.
            }
            tspivot(spintet, checksh);
            if (checksh.sh != dummysh) {
              findversion(&checksh, &spintet);
              ssbond(checksh, checkseg);
              successbonded = 1;
              break;
            }
          } else {
            hitbdry ++;
            if(hitbdry >= 2) {
              break;
            } else {
              esym(tmpabcd, spintet);
            }
          }
        }
        if (!successbonded) {
          // Badly, We must insert a subface for holding this subsegment;
          //   otherwise, this subsegment will missing after do flip.
          triface tmptet;
          fnext(tmpabcd, tmptet);
          insertsubface(&tmptet, NONSOLIDFLAG, 1);
          face newsh;
          tspivot(tmptet, newsh);
          findversion(&newsh, &tmptet);
          ssbond(newsh, checkseg);
        }
      }
    }
    senextself(abc);
    enextself(tmpabcd);
    edgecount ++;
  }

  // Before dealloc subface, must dissolve it from its two side.
  tsdissolve(abcd);
  sym(abcd, tmpabcd);
  if (tmpabcd.tet != dummytet) {
    tsdissolve(tmpabcd);
  }
  // This subface can be dealloced now.
  shellfacedealloc(&subfaces, abc.sh);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// flip23()    Swap two tets for three.                                      //
//                                                                           //
// See Barry Joe's paper [2] as listed at above. See figure 1 in this paper. //
// We change configuration 1A to 1B. The input 'flipface' is face<abc>.      //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

int mesh3d::flip23(triface& flipface)
{
  triface abcd, bace;                                  // Old configuration.
  triface oldabd, oldbcd, oldcad;
  triface abdcasing, bcdcasing, cadcasing;
  face abdsh, bcdsh, cadsh;
  triface oldbae, oldcbe, oldace;
  triface baecasing, cbecasing, acecasing;
  face baesh, cbesh, acesh;
  face abcsh;                                           // Flipping subface.
  triface edab, edbc, edca;                            // New configuration.
  point3d pa, pb, pc, pd, pe;
  REAL attrib, volume;
  int flipcount, i;

  flip_t23s++;

  if (verbose > 2) {
    printf("    Do T23 on face (%d, %d, %d, %d).\n",
           pointmark(org(flipface)), pointmark(dest(flipface)),
           pointmark(apex(flipface)), pointmark(oppo(flipface)));
  }

  abcd = flipface;
  abcd.ver = 0;  // adjust at edge<ab>.
  sym(abcd, bace);
  findversion(&bace, &abcd); // adjust at edge<ba>.
  // Keep all old faces and their casings before doflip.
  oldabd = oldbcd = oldcad = abcd;
  fnextself(oldabd);
  enextfnextself(oldbcd);
  enext2fnextself(oldcad);
  oldbae = oldcbe = oldace = bace;
  fnextself(oldbae);
  enext2fnextself(oldcbe);
  enextfnextself(oldace);
  sym(oldabd, abdcasing);
  sym(oldbcd, bcdcasing);
  sym(oldcad, cadcasing);
  sym(oldbae, baecasing);
  sym(oldcbe, cbecasing);
  sym(oldace, acecasing);
  if (checksegments) {
    // Check the flip face<a, b, c> 's three edges to see if there exist
    //   subsegment. This step must do first.
    tspivot(abcd, abcsh);
    if (abcsh.sh != dummysh) {
      assert(isnonsolid(abcsh));
      preservesubsegments(abcsh, abcd);
    }
    // Now, we can find all subfaces abutting faces in old configuration.
    tspivot(oldabd, abdsh);
    tspivot(oldbcd, bcdsh);
    tspivot(oldcad, cadsh);
    tspivot(oldbae, baesh);
    tspivot(oldcbe, cbesh);
    tspivot(oldace, acesh);
  }
  org (abcd, pa);
  dest(abcd, pb);
  apex(abcd, pc);
  oppo(abcd, pd);
  oppo(bace, pe);

  // Set new configuration.
  edab.tet = abcd.tet;
  // default: 'edab' loc = 0, ver = 0.
  setorg (edab, pe);
  setdest(edab, pd);
  setapex(edab, pa);
  setoppo(edab, pb);

  edbc.tet = bace.tet;
  // defult: 'edbc' loc = 0, ver = 0.
  setorg (edbc, pe);
  setdest(edbc, pd);
  setapex(edbc, pb);
  setoppo(edbc, pc);

  maketetrahedron(&edca);
  // default: 'edca' loc = 0, ver = 0.
  setorg (edca, pe);
  setdest(edca, pd);
  setapex(edca, pc);
  setoppo(edca, pa);

  // Set the element attributes of the new tetrahedron('edca').
  for (i = 0; i < eextras; i++) {
    attrib = elemattribute(abcd.tet, i);
    setelemattribute(edca.tet, i, attrib);
  }
  // Set the volume constraint of the new tetrahedron('edca').
  if (varvolume) {
    volume = volumebound(abcd.tet);
    setvolumebound(edca.tet, volume);
  }

  // There may be shell facets that need to be bonded to new configuarton.
  if (checksegments) {
    // Clear old flags in 'edab'('abcd') and 'edbc'('bace').
    for (i = 0; i < 4; i ++) {
      edab.loc = i;
      tsdissolve(edab);
      edbc.loc = i;
      tsdissolve(edbc);
    }
    if (abdsh.sh != dummysh) {
      edab.loc = 2; // face<a, b, d>.
      tsbond(edab, abdsh);
    }
    if (baesh.sh != dummysh) {
      edab.loc = 3; // face<b, a, e>.
      tsbond(edab, baesh);
    }
    if (bcdsh.sh != dummysh) {
      edbc.loc = 2; // face<b, c, d>.
      tsbond(edbc, bcdsh);
    }
    if (cbesh.sh != dummysh) {
      edbc.loc = 3; // face<c, b, e>.
      tsbond(edbc, cbesh);
    }
    if (cadsh.sh != dummysh) {
      edca.loc = 2; // face<c, a, d>.
      tsbond(edca, cadsh);
    }
    if (acesh.sh != dummysh) {
      edca.loc = 3; // face<a, c, e>.
      tsbond(edca, acesh);
    }
  }

  // Clear old bonds in 'edab'('abcd') and 'edbc'('bace').
  for (i = 0; i < 4; i ++) {
    edab.loc = i;
    dissolve(edab);
    edbc.loc = i;
    dissolve(edbc);
  }
  // Bond the three tetrahedra.
  edab.loc = 0;
  edca.loc = 1;
  bond(edab, edca);
  edab.loc = 1;
  edbc.loc = 0;
  bond(edab, edbc);
  edbc.loc = 1;
  edca.loc = 0;
  bond(edbc, edca);
  // Bond each casing faces.
  edab.loc = 2;
  bond(edab, abdcasing);
  edab.loc = 3;
  bond(edab, baecasing);
  edbc.loc = 2;
  bond(edbc, bcdcasing);
  edbc.loc = 3;
  bond(edbc, cbecasing);
  edca.loc = 2;
  bond(edca, cadcasing);
  edca.loc = 3;
  bond(edca, acecasing);

  edab.loc = 0;
  edbc.loc = 0;
  edca.loc = 0;
#ifdef SELF_CHECK
  if (!isaboveplane(&edab, pb)) {
    printf("Internal error in flip23():\n");
    printf("  Clockwise tetrahedron after flip (edab).\n");
    internalerror();
  }
  if (!isaboveplane(&edbc, pc)) {
    printf("Internal error in flip23():\n");
    printf("  Clockwise tetrahedron after flip (edbc).\n");
    internalerror();
  }
  if (!isaboveplane(&edca, pa)) {
    printf("Internal error in flip23():\n");
    printf("  Clockwise tetrahedron after flip (edca).\n");
    internalerror();
  }
#endif // defined SELF_CHECK
  if (verbose > 2) {
    printf("    Updating edab ");
    dump(&edab);
    printf("    Updating edbc ");
    dump(&edbc);
    printf("    Creating edca ");
    dump(&edca);
  }

  if(usefliplist) {
    flipcount = 0;
    edab.loc = 2; // face<a, b, d>.
    enqueuefliplist(edab);
    edab.loc = 3; // face<b, a, e>.
    enqueuefliplist(edab);
    edbc.loc = 2; // face<b, c, d>.
    enqueuefliplist(edbc);
    edbc.loc = 3; // face<c, b, e>.
    enqueuefliplist(edbc);
    edca.loc = 2; // face<c, a, d>.
    enqueuefliplist(edca);
    edca.loc = 3; // face<a, c, e>.
    enqueuefliplist(edca);
  } else {
    flipcount = 1;
    edab.loc = 2; // face<a, b, d>.
    flipcount += flip(edab);
    edab.loc = 3; // face<b, a, e>.
    flipcount += flip(edab);
    edbc.loc = 2; // face<b, c, d>.
    flipcount += flip(edbc);
    edbc.loc = 3; // face<c, b, e>.
    flipcount += flip(edbc);
    edca.loc = 2; // face<c, a, d>.
    flipcount += flip(edca);
    edca.loc = 3; // face<a, c, e>.
    flipcount += flip(edca);
  }

  return flipcount;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// flip32()    Swap three tets for two.                                      //
//                                                                           //
// See Barry Joe's paper [2] as listed at above. See figure 1 in this paper. //
// We change configuration 1B to 1A. The input 'flipface' is edge<de>.       //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

int mesh3d::flip32(triface& flipface)
{
  triface edab, edbc, edca;                            // Old configuration.
  triface oldabd, oldbcd, oldcad;
  triface abdcasing, bcdcasing, cadcasing;
  face abdsh, bcdsh, cadsh;
  triface oldbae, oldcbe, oldace;
  triface baecasing, cbecasing, acecasing;
  face baesh, cbesh, acesh;
  triface abcd, bace;                                  // New configuration.
  point3d pa, pb, pc, pd, pe;
  int flipcount, i;

  flip_t32s++;

  if (verbose > 2) {
    printf("    Do T32 on face (%d, %d, %d, %d).\n",
           pointmark(org(flipface)), pointmark(dest(flipface)),
           pointmark(apex(flipface)), pointmark(oppo(flipface)));
  }

  // 'flipface' must be tet<e, d, a, b> or tet<d, e, a, -b>.
  edab = flipface;
  // Adjust face version first, so 'edab' be tet<e, d, a, b>.
  adjustedgering(edab, CCW);
  // Set 'edbc' and 'edca'.
  fnext(edab, edbc);
  symself(edbc);
  findversion(&edbc, &edab, 0);
  fnext(edbc, edca);
  symself(edca);
  findversion(&edca, &edab, 0);
  // Keep all old faces and their casings before doflip.
  oldabd = oldbae = edab;
  enextfnextself(oldabd);
  enext2fnextself(oldbae);
  oldbcd = oldcbe = edbc;
  enextfnextself(oldbcd);
  enext2fnextself(oldcbe);
  oldcad = oldace = edca;
  enextfnextself(oldcad);
  enext2fnextself(oldace);
  sym(oldabd, abdcasing);
  sym(oldbcd, bcdcasing);
  sym(oldcad, cadcasing);
  sym(oldbae, baecasing);
  sym(oldcbe, cbecasing);
  sym(oldace, acecasing);
  if (checksegments) {
    // Check faces around flip edge<e, d> to see if there exist subsegment
    //   attaching it. This step must do first. The three face are ed(abc).
    face tmpface;
    tspivot(edab, tmpface);
    if (tmpface.sh != dummysh) {
      assert(isnonsolid(tmpface));
      preservesubsegments(tmpface, edab);
    }
    tspivot(edbc, tmpface);
    if (tmpface.sh != dummysh) {
      assert(isnonsolid(tmpface));
      preservesubsegments(tmpface, edbc);
    }
    tspivot(edca, tmpface);
    if (tmpface.sh != dummysh) {
      assert(isnonsolid(tmpface));
      preservesubsegments(tmpface, edca);
    }
    // Find all subfaces abutting faces in old configuration.
    tspivot(oldabd, abdsh);
    tspivot(oldbcd, bcdsh);
    tspivot(oldcad, cadsh);
    tspivot(oldbae, baesh);
    tspivot(oldcbe, cbesh);
    tspivot(oldace, acesh);
  }
  apex(edab, pa);
  oppo(edab, pb);
  oppo(edbc, pc);
  dest(edab, pd);
  org (edab, pe);

  // Set new configuration.
  abcd.tet = edab.tet;
  // default: 'abcd' loc = 0, ver = 0.
  setorg (abcd, pa);
  setdest(abcd, pb);
  setapex(abcd, pc);
  setoppo(abcd, pd);

  bace.tet = edbc.tet;
  // default: 'bace' loc = 0, ver = 0.
  setorg (bace, pb);
  setdest(bace, pa);
  setapex(bace, pc);
  setoppo(bace, pe);

  // In flip32 case, we needn't reset element attributes and volume
  //   constraint, because no new tetrahedron be created.

  // There may be shell facets that need to be bonded to the new
  //   configuration.
  if (checksegments) {
    // Clear old flags in 'abcd'('edab') and 'bace'('edbc').
    for (i = 0; i < 4; i ++) {
      abcd.loc = i;
      tsdissolve(abcd);
      bace.loc = i;
      tsdissolve(bace);
    }
    if (abdsh.sh != dummysh) {
      abcd.loc = 1; // face<a, b, d>.
      tsbond(abcd, abdsh);
    }
    if (baesh.sh != dummysh) {
      bace.loc = 1; // face<b, a, e>.
      tsbond(bace, baesh);
    }
    if (bcdsh.sh != dummysh) {
      abcd.loc = 2; // face<b, c, d>.
      tsbond(abcd, bcdsh);
    }
    if (cbesh.sh != dummysh) {
      bace.loc = 3; // face<c, b, e>.
      tsbond(bace, cbesh);
    }
    if (cadsh.sh != dummysh) {
      abcd.loc = 3; // face<c, a, d>.
      tsbond(abcd, cadsh);
    }
    if (acesh.sh != dummysh) {
      bace.loc = 2; // face<a, c, e>.
      tsbond(bace, acesh);
    }
  }

  for (i = 0; i < 4; i ++) {
    abcd.loc = i;
    dissolve(abcd);
    bace.loc = i;
    dissolve(bace);
  }
  // Bond the new configuration.
  abcd.loc = 0;
  bace.loc = 0;
  bond(abcd, bace);
  // Bond each casing faces.
  abcd.loc = 1;
  bond(abcd, abdcasing);
  abcd.loc = 2;
  bond(abcd, bcdcasing);
  abcd.loc = 3;
  bond(abcd, cadcasing);
  bace.loc = 1;
  bond(bace, baecasing);
  bace.loc = 3;
  bond(bace, cbecasing);
  bace.loc = 2;
  bond(bace, acecasing);

  abcd.loc = 0;
  bace.loc = 0;
#ifdef SELF_CHECK
  if (!isaboveplane(&abcd, pd)) {
    printf("Internal error in flip32():\n");
    printf("  Clockwise tetrahedron after flip (abcd).\n");
    internalerror();
  }
  if (!isaboveplane(&bace, pe)) {
    printf("Internal error in flip32():\n");
    printf("  Clockwise tetrahedron after flip (bace).\n");
    internalerror();
  }
#endif // defined SELF_CHECK
  if (verbose > 2) {
    printf("    Updating abcd ");
    dump(&abcd);
    printf("    Updating bace ");
    dump(&bace);
    printf("    Deleting edca ");
    dump(&edca);
  }
  // Dealloc 'edca'.
  tetrahedrondealloc(edca.tet);

  if (usefliplist) {
    flipcount = 0;
    abcd.loc = 1; // face<a, b, d>.
    enqueuefliplist(abcd);
    bace.loc = 1; // face<b, a, e>.
    enqueuefliplist(bace);
    abcd.loc = 2; // face<b, c, d>.
    enqueuefliplist(abcd);
    bace.loc = 3; // face<c, b, e>.
    enqueuefliplist(bace);
    abcd.loc = 3; // face<c, a, d>.
    enqueuefliplist(abcd);
    bace.loc = 2; // face<a, c, e>.
    enqueuefliplist(bace);
  } else {
    flipcount = 1;
    abcd.loc = 1; // face<a, b, d>.
    flipcount += flip(abcd);
    bace.loc = 1; // face<b, a, e>.
    flipcount += flip(bace);
    abcd.loc = 2; // face<b, c, d>.
    flipcount += flip(abcd);
    bace.loc = 3; // face<c, b, e>.
    flipcount += flip(bace);
    abcd.loc = 3; // face<c, a, d>.
    flipcount += flip(abcd);
    bace.loc = 2; // face<a, c, e>.
    flipcount += flip(bace);
  }

  return flipcount;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// flip22()    Swap two tets for two, in the case where two faces are        //
//             coplanar.                                                     //
//                                                                           //
// See Barry Joe's paper [2] as listed at above. See figure 1 in this paper. //
// We change configuration 3A to 3B. The input 'flipface' lock at edge<ab>.  //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

int mesh3d::flip22(triface& flipface)
{
  triface abcd, bace;                                  // Old configuration.
  triface oldbcd, oldcad, oldcbe, oldace;
  triface bcdcasing, cadcasing, cbecasing, acecasing;
  face bcdsh, cadsh, cbesh, acesh;
  triface oldabd, oldbae;                                 // Flipping faces.
  face abdsh, baesh, abcsh;                            // Flipping subfaces.
  face abdrightseg, abdleftseg;
  face baerightseg, baeleftseg;
  triface ceda, cdeb;                                  // New configuration.
  face debsh, edash;
  triface ghosttet;
  point3d pa, pb, pc, pd, pe;
  int flipcount, i;

  flip_t22s++;

  if (verbose > 2) {
    printf("    Do T22 on face (%d, %d, %d, %d).\n",
           pointmark(org(flipface)), pointmark(dest(flipface)),
           pointmark(apex(flipface)), pointmark(oppo(flipface)));
  }

  // Set a 'ghosttet' handle the Outer space.
  ghosttet.tet = dummytet;

  abcd = flipface;
  adjustedgering(abcd, CCW);
  sym(abcd, bace);
  findversion(&bace, &abcd);
  oldbcd = oldcad = abcd;
  enextfnextself(oldbcd);
  enext2fnextself(oldcad);
  oldcbe = oldace = bace;
  enext2fnextself(oldcbe);
  enextfnextself(oldace);
  sym(oldbcd, bcdcasing);
  sym(oldcad, cadcasing);
  sym(oldcbe, cbecasing);
  sym(oldace, acecasing);
  if (checksegments) {
    // Check the flip face<a, b, c> 's three edges to see if there exist
    //   subsegment. This step must do first.
    tspivot(abcd, abcsh);
    if (abcsh.sh != dummysh) {
      assert(isnonsolid(abcsh));
      preservesubsegments(abcsh, abcd);
    }
    // Now, we can find all subfaces abutting faces in old configuration.
    tspivot(oldbcd, bcdsh);
    tspivot(oldcad, cadsh);
    tspivot(oldcbe, cbesh);
    tspivot(oldace, acesh);
    // Keep flip edge<ab> and its two(coplanar) flip faces.
    fnext(abcd, oldabd);
    fnext(bace, oldbae);
    tspivot(oldabd, abdsh);
    tspivot(oldbae, baesh);
    if ((abdsh.sh != dummysh) || (baesh.sh != dummysh)) {
      // Check if there missing a half subface.
      if (abdsh.sh == dummysh) {
        assert(baesh.sh != dummysh);
        insertsubface(&oldabd, NONSOLIDFLAG, 1);
        tspivot(oldabd, abdsh);
      } else if (baesh.sh == dummysh) {
        assert(abdsh.sh != dummysh);
        insertsubface(&oldbae, NONSOLIDFLAG, 1);
        tspivot(oldbae, baesh);
      }
      // Save segments which adhering to 'abdsh'.
      findversion(&abdsh, &abcd, 0);  // lock at edge<ab>.
      senextself(abdsh);              // arrive  edge<bd>.
      sspivot(abdsh, abdrightseg);
      senextself(abdsh);              // arrive  edge<da>
      sspivot(abdsh, abdleftseg);
      // Save segments which adhering to 'baesh'.
      findversion(&baesh, &bace, 0);  // lock at edge<ba>.
      senextself(baesh);              // arrive  edge<ae>.
      sspivot(baesh, baerightseg);
      senextself(baesh);              // arrive  edge<eb>.
      sspivot(baesh, baeleftseg);
    }
  }
  org (abcd, pa);
  dest(abcd, pb);
  apex(abcd, pc);
  oppo(abcd, pd);
  oppo(bace, pe);

  // Set new configuration.
  ceda.tet = abcd.tet;
  // default: 'ceda' loc = 0, ver = 0.
  setorg (ceda, pc);
  setdest(ceda, pe);
  setapex(ceda, pd);
  setoppo(ceda, pa);

  cdeb.tet = bace.tet;
  // default: 'cdeb' loc = 0, ver = 0.
  setorg (cdeb, pc);
  setdest(cdeb, pd);
  setapex(cdeb, pe);
  setoppo(cdeb, pb);

  // In flip22 case, we needn't reset element attributes and volume
  //   constraint, because no new tetrahedron be created.

  // There may be shell facets that need to be bonded to the new
  //   configuration.
  if (checksegments) {
    // Clear old flags in 'ceda'('abcd') and 'cdeb'('bace').
    for (i = 0; i < 4; i ++) {
      ceda.loc = i;
      tsdissolve(ceda);
      cdeb.loc = i;
      tsdissolve(cdeb);
    }
    if (bcdsh.sh != dummysh) {
      cdeb.loc = 1; // face<b, c, d>.
      tsbond(cdeb, bcdsh);
    }
    if (cbesh.sh != dummysh) {
      cdeb.loc = 3; // face<c, b, e>.
      tsbond(cdeb, cbesh);
    }
    if (cadsh.sh != dummysh) {
      ceda.loc = 3; // face<c, a, d>.
      tsbond(ceda, cadsh);
    }
    if (acesh.sh != dummysh) {
      ceda.loc = 1; // face<a, c, e>.
      tsbond(ceda, acesh);
    }
    if (abdsh.sh != dummysh) {
      debsh.sh = abdsh.sh;
      // default: 'debsh' ver = 0.
      setsorg (debsh, pd);
      setsdest(debsh, pe);
      setsapex(debsh, pb);

      edash.sh = baesh.sh;
      // default: 'edash' ver = 0.
      setsorg (edash, pe);
      setsdest(edash, pd);
      setsapex(edash, pa);

      ssdissolve(debsh);
      ssdissolve(edash);
      senextself(debsh);
      ssbond(debsh, baeleftseg);
      senextself(debsh);
      ssbond(debsh, abdrightseg);
      senextself(edash);
      ssbond(edash, abdleftseg);
      senextself(edash);
      ssbond(edash, baerightseg);

      // Bond with cdeb(loc = 2).
      cdeb.loc = 2;
      tsbond(cdeb, debsh);
      // Bond other side of cdeb('Outer space').
      sesymself(debsh);
      tsbond(ghosttet, debsh);
      // Bond with ceda.
      ceda.loc = 2;
      tsbond(ceda, edash);
      // Bond other side of ceda('Outer space').
      sesymself(edash);
      tsbond(ghosttet, edash);
    }
  }

  // Clear old flags in 'ceda'('abcd') and 'cdeb'('bace').
  for (i = 0; i < 4; i ++) {
    ceda.loc = i;
    dissolve(ceda);
    cdeb.loc = i;
    dissolve(cdeb);
  }
  // Bond the new configuration.
  ceda.loc = 0;
  cdeb.loc = 0;
  bond(ceda, cdeb);
  // Bond each casing facets.
  cdeb.loc = 1;
  bond(cdeb, bcdcasing);
  ceda.loc = 3;
  bond(ceda, cadcasing);
  cdeb.loc = 3;
  bond(cdeb, cbecasing);
  ceda.loc = 1;
  bond(ceda, acecasing);
  // Bond 'Outer space', diffrent in flip44.
  cdeb.loc = 2;
  bond(cdeb, ghosttet);
  ceda.loc = 2;
  bond(ceda, ghosttet);

  ceda.loc = 0;
  cdeb.loc = 0;
#ifdef SELF_CHECK
  if (!isaboveplane(&ceda, pa)) {
    printf("Internal error in flip22():\n");
    printf("  Clockwise tetrahedron after flip (ceda).\n");
    internalerror();
  }
  if (!isaboveplane(&cdeb, pb)) {
    printf("Internal error in flip22():\n");
    printf("  Clockwise tetrahedron after flip (cdeb).\n");
    internalerror();
  }
#endif // defined SELF_CHECK
  if (verbose > 2) {
    printf("    Updating ceda ");
    dump(&ceda);
    printf("    Updating cdeb ");
    dump(&cdeb);
  }

  if (usefliplist) {
    flipcount = 0;
    ceda.loc = 3; // face<c, a, d>.
    enqueuefliplist(ceda);
    ceda.loc = 1; // face<a, c, e>.
    enqueuefliplist(ceda);
    cdeb.loc = 1; // face<b, c, d>.
    enqueuefliplist(cdeb);
    cdeb.loc = 3; // face<c, b, e>.
    enqueuefliplist(cdeb);
  } else {
    flipcount = 1;
    ceda.loc = 3; // face<c, a, d>.
    flipcount += flip(ceda);
    ceda.loc = 1; // face<a, c, e>.
    flipcount += flip(ceda);
    cdeb.loc = 1; // face<b, c, d>.
    flipcount += flip(cdeb);
    cdeb.loc = 3; // face<c, b, e>.
    flipcount += flip(cdeb);
  }

  return flipcount;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// flip44()    Swap four tets for four, in the case where two faces are      //
//             coplanar.                                                     //
//                                                                           //
// See Barry Joe's paper [2] as listed at above. See figure 1 in this paper. //
// We change configuration 3A to 3B. The input 'flipface' lock at edge<ab>.  //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

int mesh3d::flip44(triface& flipface)
{
  triface abcd, bace, bafd, abfe;                      // Old configuration.
  triface oldbcd, oldcad, oldcbe, oldace;
  triface oldfbd, oldafd, oldbfe, oldfae;
  triface bcdcasing, cadcasing, cbecasing, acecasing;
  triface fbdcasing, afdcasing, bfecasing, faecasing;
  face bcdsh, cadsh, cbesh, acesh;
  face fbdsh, afdsh, bfesh, faesh;
  triface oldabd, oldbae;                                 // Flipping faces.
  face abdsh, baesh, abcsh, abfsh;                     // Flipping subfaces.
  face abdrightseg, abdleftseg;
  face baerightseg, baeleftseg;
  triface ceda, cdeb, fdea, fedb;                      // New configuration.
  face debsh, edash;
  point3d pa, pb, pc, pd, pe, pf;
  int flipcount, i;

  flip_t44s++;

  if (verbose > 2) {
    printf("    Do T44 on face (%d, %d, %d, %d).\n",
           pointmark(org(flipface)), pointmark(dest(flipface)),
           pointmark(apex(flipface)), pointmark(oppo(flipface)));
  }

  abcd = flipface;
  adjustedgering(abcd, CCW);
  sym(abcd, bace);
  findversion(&bace, &abcd);

  // Find the other side two tets of 'abcd' and 'bace'.
  bafd = abcd;
  fnextself(bafd);
  fnextself(bafd);
  esymself(bafd);
  abfe = bace;
  fnextself(abfe);
  fnextself(abfe);
  esymself(abfe);

  oldbcd = oldcad = abcd;
  enextfnextself(oldbcd);
  enext2fnextself(oldcad);
  oldcbe = oldace = bace;
  enext2fnextself(oldcbe);
  enextfnextself(oldace);

  oldfbd = oldafd = bafd;
  enext2fnextself(oldfbd);
  enextfnextself(oldafd);
  oldbfe = oldfae = abfe;
  enextfnextself(oldbfe);
  enext2fnextself(oldfae);

  sym(oldbcd, bcdcasing);
  sym(oldcad, cadcasing);
  sym(oldcbe, cbecasing);
  sym(oldace, acecasing);

  sym(oldfbd, fbdcasing);
  sym(oldafd, afdcasing);
  sym(oldbfe, bfecasing);
  sym(oldfae, faecasing);

  if (checksegments) {
    // Check the flip face<a, b, c> 's three edges to see if there exist
    //   subsegment. This step must do first.
    tspivot(abcd, abcsh);
    if (abcsh.sh != dummysh) {
      assert(isnonsolid(abcsh));
      preservesubsegments(abcsh, abcd);
    }
    // Now, we can find all subfaces abutting faces in old configuration.
    tspivot(oldbcd, bcdsh);
    tspivot(oldcad, cadsh);
    tspivot(oldcbe, cbesh);
    tspivot(oldace, acesh);

    // Check the flip face<a, b, f> 's three edges to see if there exist
    //   subsegment. This step must do first.
    tspivot(bafd, abfsh);
    if (abfsh.sh != dummysh) {
      assert(isnonsolid(abfsh));
      preservesubsegments(abfsh, bafd);
    }
    // Now, we can find all subfaces abutting faces in old configuration.
    tspivot(oldfbd, fbdsh);
    tspivot(oldafd, afdsh);
    tspivot(oldbfe, bfesh);
    tspivot(oldfae, faesh);

    // Keep flip edge and (coplanar) flip faces. This codes are diffrent
    //   with flip22. 'abdsh' and 'baesh' may be 'dummysh'.
    fnext(abcd, oldabd);
    fnext(bace, oldbae);
    tspivot(oldabd, abdsh);
    tspivot(oldbae, baesh);
    if ((abdsh.sh != dummysh) || (baesh.sh != dummysh)) {
      // Check if there missing a half subface.
      if (abdsh.sh == dummysh) {
        assert(baesh.sh != dummysh);
        insertsubface(&oldabd, NONSOLIDFLAG, 1);
        tspivot(oldabd, abdsh);
      } else if (baesh.sh == dummysh) {
        assert(abdsh.sh != dummysh);
        insertsubface(&oldbae, NONSOLIDFLAG, 1);
        tspivot(oldbae, baesh);
      }
      // Save segments which adhering to 'abdsh'.
      findversion(&abdsh, &abcd, 0);  // lock at edge<ab>.
      senextself(abdsh);
      sspivot(abdsh, abdrightseg);
      senextself(abdsh);
      sspivot(abdsh, abdleftseg);
      // Save segments which adhering to 'baesh'.
      findversion(&baesh, &bace, 0);  // lock at edge<ba>.
      senextself(baesh);
      sspivot(baesh, baerightseg);
      senextself(baesh);
      sspivot(baesh, baeleftseg);
    }
  }
  org (abcd, pa);
  dest(abcd, pb);
  apex(abcd, pc);
  oppo(abcd, pd);
  oppo(bace, pe);
  apex(bafd, pf);

  // Set new configuration.
  ceda.tet = abcd.tet;
  // default: 'ceda' loc = 0, ver = 0.
  setorg (ceda, pc);
  setdest(ceda, pe);
  setapex(ceda, pd);
  setoppo(ceda, pa);

  cdeb.tet = bace.tet;
  // default: 'cdeb' loc = 0, ver = 0.
  setorg (cdeb, pc);
  setdest(cdeb, pd);
  setapex(cdeb, pe);
  setoppo(cdeb, pb);

  fdea.tet = bafd.tet;
  // default: 'fdea' loc = 0, ver = 0.
  setorg (fdea, pf);
  setdest(fdea, pd);
  setapex(fdea, pe);
  setoppo(fdea, pa);

  fedb.tet = abfe.tet;
  // default: 'fedb' loc = 0, ver = 0.
  setorg (fedb, pf);
  setdest(fedb, pe);
  setapex(fedb, pd);
  setoppo(fedb, pb);

  // In flip44 case, we needn't reset element attributes and volume
  //   constraint, because no new tetrahedron be created.

  // There may be shell facets that need to be bonded to the new
  //   configuration.
  if (checksegments) {
    // Clear old flags in 'ceda'('abcd') and 'cdeb'('bace').
    for (i = 0; i < 4; i ++) {
      ceda.loc = i;
      tsdissolve(ceda);
      cdeb.loc = i;
      tsdissolve(cdeb);
    }
    if (bcdsh.sh != dummysh) {
      cdeb.loc = 1; // face<b, c, d>.
      tsbond(cdeb, bcdsh);
    }
    if (cbesh.sh != dummysh) {
      cdeb.loc = 3; // face<c, b, e>.
      tsbond(cdeb, cbesh);
    }
    if (cadsh.sh != dummysh) {
      ceda.loc = 3; // face<c, a, d>.
      tsbond(ceda, cadsh);
    }
    if (acesh.sh != dummysh) {
      ceda.loc = 1; // face<a, c, e>.
      tsbond(ceda, acesh);
    }

    // Clear old flags in 'fdea'('bafd') and 'fedb'('abfe').
    for (i = 0; i < 4; i ++) {
      fdea.loc = i;
      tsdissolve(fdea);
      fedb.loc = i;
      tsdissolve(fedb);
    }
    if (fbdsh.sh != dummysh) {
      fedb.loc = 3; // face<f, b, d>.
      tsbond(fedb, fbdsh);
    }
    if (bfesh.sh != dummysh) {
      fedb.loc = 1; // face<b, f, e>.
      tsbond(fedb, bfesh);
    }
    if (afdsh.sh != dummysh) {
      fdea.loc = 1; // face<a, f, d>.
      tsbond(fdea, afdsh);
    }
    if (faesh.sh != dummysh) {
      fdea.loc = 3; // face<f, a, e>.
      tsbond(fdea, faesh);
    }
    if (abdsh.sh != dummysh) {
      debsh.sh = abdsh.sh;
      // default: 'debsh' ver = 0.
      setsorg (debsh, pd);
      setsdest(debsh, pe);
      setsapex(debsh, pb);

      edash.sh = baesh.sh;
      // default: 'edash' ver = 0.
      setsorg (edash, pe);
      setsdest(edash, pd);
      setsapex(edash, pa);

      ssdissolve(debsh);
      ssdissolve(edash);
      senextself(debsh);
      ssbond(debsh, baeleftseg);
      senextself(debsh);
      ssbond(debsh, abdrightseg);
      senextself(edash);
      ssbond(edash, abdleftseg);
      senextself(edash);
      ssbond(edash, baerightseg);

      // Sandwich between 2 tets.
      cdeb.loc = 2;
      tsbond(cdeb, debsh);
      sesymself(debsh);   // Don't forget to change edgering.
      fedb.loc = 2;
      tsbond(fedb, debsh);
      // Sandwich between 2 tets.
      ceda.loc = 2;
      tsbond(ceda, edash);
      sesymself(edash);  // Don't forget to change edgering.
      fdea.loc = 2;
      tsbond(fdea, edash); 
    }
  }

  for (i = 0; i < 4; i ++) {
    ceda.loc = i;
    dissolve(ceda);
    cdeb.loc = i;
    dissolve(cdeb);
  }
  // Bond the new configuration.
  ceda.loc = 0;
  cdeb.loc = 0;
  bond(ceda, cdeb);
  // Bond each casing facets.
  cdeb.loc = 1;
  bond(cdeb, bcdcasing);
  ceda.loc = 3;
  bond(ceda, cadcasing);
  cdeb.loc = 3;
  bond(cdeb, cbecasing);
  ceda.loc = 1;
  bond(ceda, acecasing);

  for (i = 0; i < 4; i ++) {
    fdea.loc = i;
    dissolve(fdea);
    fedb.loc = i;
    dissolve(fedb);
  }
  // Bond the two new tetrahedron at other side.
  fdea.loc = 0;
  fedb.loc = 0;
  bond(fdea, fedb);
  // Bond each casing facets.
  fedb.loc = 3;
  bond(fedb, fbdcasing);
  fdea.loc = 1;
  bond(fdea, afdcasing);
  fedb.loc = 1;
  bond(fedb, bfecasing);
  fdea.loc = 3;
  bond(fdea, faecasing);

  // Bond two side tets.
  ceda.loc = 2;
  fdea.loc = 2;
  bond(ceda, fdea);
  cdeb.loc = 2;
  fedb.loc = 2;
  bond(cdeb, fedb);

  ceda.loc = 0;
  cdeb.loc = 0;
  fdea.loc = 0;
  fedb.loc = 0;
#ifdef SELF_CHECK
  if (!isaboveplane(&ceda, pa)) {
    printf("Internal error in flip44():\n");
    printf("  Clockwise tetrahedron after flip (ceda).\n");
    internalerror();
  }
  if (!isaboveplane(&cdeb, pb)) {
    printf("Internal error in flip44():\n");
    printf("  Clockwise tetrahedron after flip (cdeb).\n");
    internalerror();
  }
  if (!isaboveplane(&fdea, pa)) {
    printf("Internal error in flip44():\n");
    printf("  Clockwise tetrahedron after flip (fdea).\n");
    internalerror();
  }
  if (!isaboveplane(&fedb, pb)) {
    printf("Internal error in flip44():\n");
    printf("  Clockwise tetrahedron after flip (fedb).\n");
    internalerror();
  }
#endif // defined SELF_CHECK
  if (verbose > 2) {
    printf("    Updating ceda ");
    dump(&ceda);
    printf("    Updating cdeb ");
    dump(&cdeb);
    printf("    Updating fdea ");
    dump(&fdea);
    printf("    Updating fedb ");
    dump(&fedb);
  }

  if (usefliplist) {
    flipcount = 0;
    ceda.loc = 3; // face<c, a, d>.
    enqueuefliplist(ceda);
    ceda.loc = 1; // face<a, c, e>.
    enqueuefliplist(ceda);
    cdeb.loc = 1; // face<b, c, d>.
    enqueuefliplist(cdeb);
    cdeb.loc = 3; // face<c, b, e>.
    enqueuefliplist(cdeb);
    fdea.loc = 1; // face<a, f, d>.
    enqueuefliplist(fdea);
    fdea.loc = 3; // face<f, a, e>.
    enqueuefliplist(fdea);
    fedb.loc = 3; // face<f, b, d>.
    enqueuefliplist(fedb);
    fedb.loc = 1; // face<b, f, e>.
    enqueuefliplist(fedb);
  } else {
    flipcount = 1;
    ceda.loc = 3; // face<c, a, d>.
    flipcount += flip(ceda);
    ceda.loc = 1; // face<a, c, e>.
    flipcount += flip(ceda);
    cdeb.loc = 1; // face<b, c, d>.
    flipcount += flip(cdeb);
    cdeb.loc = 3; // face<c, b, e>.
    flipcount += flip(cdeb);
    fdea.loc = 1; // face<a, f, d>.
    flipcount += flip(fdea);
    fdea.loc = 3; // face<f, a, e>.
    flipcount += flip(fdea);
    fedb.loc = 3; // face<f, b, d>.
    flipcount += flip(fedb);
    fedb.loc = 1; // face<b, f, e>.
    flipcount += flip(fedb);
  }

  return flipcount;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// flip()    Swap away face if this is legal and improves the mesh quality   //
//           measure.                                                        //
//                                                                           //
// Swapping typically propagates through the mesh, and the return value is   //
// the total number of swaps done during this invocation.                    //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

int mesh3d::flip(triface& flipface)
{
  // If the face has been removed, don't bother
  if (isdead(&flipface)) return (0);

  enum facecategory fc = categorizeface(flipface);
  // Determine the preferable configuration and swap if necessary.
  switch (fc) {
    // These cases are handled by edge swapping.
    case N44:
    case N32:
      // if (edgeswapallow) {
        // if (querydoswap(flipface)) {
        //  return edgeswap(flipface, 0);
        // }
      // }
      break;
    // These cases are definitely unswappable
    case N40:
    case N30:
    case N20:
    case LOCKED:
      break;
    case T44:
      if (querydoswap(flipface)) {
        return flip44(flipface);
      }
      break;
    case T22:
      if (querydoswap(flipface)) {
        return flip22(flipface);
      }
      break;
    case T23:
      if (querydoswap(flipface)) {
        return flip23(flipface);
      }
      break;
    case T32:
      if (querydoswap(flipface)) {
        return flip32(flipface);
      }
      break;
    // Catch-all for bad cases
    default:
      // Shouldn't be here: face wasn't categorized.
      break;
  }
  checkquality(&flipface);
  return 0;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// enqueuefliplist()    Add a face which may be non-Delaunay to 'fliplist',  //
//                      so we can batch process all (to be flipped) faces    //
//                      together rather than flip a face at one time.        //
//                                                                           //
// This routine couple with dequeuefliplist() and dofliplist() are used for  //
// the implementation of Randomized Incremental Delaunay Algorithm.          //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::enqueuefliplist(triface& flipface)
{
  badface3d queface;

  queface.badfacetet = flipface;
  org (flipface, queface.faceorg);
  dest(flipface, queface.facedest);
  apex(flipface, queface.faceapex); 
  if (verbose > 2) {
    printf("    Queueing flip face: (%d, %d, %d).\n",
           pointmark(queface.faceorg), pointmark(queface.facedest),
           pointmark(queface.faceapex));
  }
  fliplist->push(&queface);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// dequeuefliplist()    Get a exist face from 'fliplist', check its Delaunay //
//                      -hood and perform corresponding flip operator if it  //
//                      is a non-Delaunay face.                              //
//                                                                           //
// This routine couple with enqueuefliplist() and dofliplist() are used for  //
// the implementation of Randomized Incremental Delaunay Algorithm.          //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

bool mesh3d::dequeuefliplist(triface& flipface)
{
  badface3d queface;
  point3d forg, fdest, fapex;

  while (fliplist->get(&queface)) {
    if (!isdead(&(queface.badfacetet))) {
      org (queface.badfacetet, forg);
      dest(queface.badfacetet, fdest);
      apex(queface.badfacetet, fapex);
      if ((forg == queface.faceorg)
          && (fdest == queface.facedest)
          && (fapex == queface.faceapex)) {
        flipface = queface.badfacetet;
        if (verbose > 2) {
          printf("    Getting  flip face: (%d, %d, %d).\n",
                 pointmark(queface.faceorg), pointmark(queface.facedest),
                 pointmark(queface.faceapex));
        }
        return true;
      }
    }
  }
  return false;
}

///////////////////////////////////////////////////////////////////////////////
// END                                                                       //
// Mesh Transformation Routines                                              //
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Insert/Delete point routines                                              //
// BEGIN                                                                     //
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// insertsite()    Insert a vertex into Delaunay tetrahedrization, perform-  //
//                 ing flips as necessary to maintain the Delaunay property. //
//                                                                           //
//   The point 'insertpoint' is located.  If 'searchtet.tet' is not NULL,    //
// the search for the containing tetrahedron begins from 'searchtet'. If     //
// 'searchtet.tet' is NULL, a full point location procedure is called. If    //
// 'inseertpoint' is found inside a tetrahedron, the tetrahedra is split     //
// into four by call routine insertininterior(); if 'insertpoint' lies on    //
// an edge, the edge is split in two, thereby splitting the adjacent         //
// tetrahedra. It will be done by call routine insertonedge();  if           //
// 'insertpoint' lies on an face, the face is split into three, thereby      //
// splitting the adjacent tetrahedra.  It will be done by call routine       //
// insertonface().  Face or edge flips are used to restore the Delaunay      //
// property.  If 'insertpoint' lies on an existing vertex, no action is      //
// taken, and value DUPLICATEPOINT is returned. On return, 'searchtet' is    //
// set to a handle contain the existing vertex.                              //
//                                                                           //
//   Normally, the parameter 'splitface' and 'splitedge' are set to NULL,    //
// implying that no subface and subsegment should be split. In this case, if //
// 'insertpoint' is found to lie on a subface or a subsegment, no action is  //
// taken, and the value VIOLATINGFACE or VIOLATINGEDGE is returned. On       //
// return, 'searchtet' is set to a handle whose primary face or edge is the  //
// violated subface or subsegment.                                           //
//                                                                           //
//   If the calling routine wishes to split a subface or subsegment by       //
// inserting a point in it, the parameter 'splitface' or 'splitedge' should  //
// be that subface or subsegment. In this case, 'searchtet' MUST be the      //
// tetrahedron handle reached by pivoting from that subface or subsegment;   //
// no point location is done.                                                //
//                                                                           //
//   If a point being inserted,  the return value will be SUCCESSFUL. If a   //
// point is found to locate outside the mesh and can't be inserted, the      //
// return value will be FAILED otherwise. In either case, 'searchtet' is set //
// to a handle whose contains the newly inserted vertex.                     //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

enum mesh3d::insertsiteresult
mesh3d::insertsite(point3d insertpoint, triface* searchtet, face* splitface,
                   face* splitedge)
{
  triface horiz;
  face brokenshell;
  badface3d *encroached;
  enum locateresult intersect;
  int flipcount;

  if (verbose > 1) {
    printf("  Insert point to mesh: (%.12g, %.12g, %.12g) %d.\n",
           insertpoint[0], insertpoint[1], insertpoint[2],
           pointmark(insertpoint));
  }

  if ((splitface == NULL) && (splitedge == NULL)) {
    // Find the location of the point to be inserted. Check if a good
    //   starting tetrahedron has already been provided by the caller.
    if (isdead(searchtet)) {
      // Find a boundary tetrahedron.
      horiz.tet = dummytet;
      horiz.loc = 0;
      symself(horiz);
      // Search for a tetrahedron containing 'insertpoint'.
      intersect = locate(insertpoint, &horiz);
    } else {
      // Start searching from the tetrahedron provided by the caller.
      horiz = *searchtet;
      intersect = preciselocate(insertpoint, &horiz);
    }
  } else {
    // The calling routine provides the edge or face in which the point
    //   is inserted.
    horiz = *searchtet;
    if ((splitface != NULL) && (splitedge == NULL))  {
      intersect = ONFACE;
    } else if ((splitface == NULL) && (splitedge != NULL)) {
      intersect = ONEDGE;
    } else {
      printf("Internal error in insertsite():");
      printf("  splitface and splitedge couldn't use together.\n");
      internalerror();
    }
  }

  // Keep search stat.
  *searchtet = horiz;
  recenttet = horiz;

  switch (intersect) {
    case ONVERTEX:
      // There's already a vertex there. Return in 'searchtet' a tetrahedron
      //   whose origin is the existing vertex.
      if (verbose > 1) {
        printf("  Not insert for duplicating point.\n");
      }
      return DUPLICATE;

    case ONEDGE:
      // The vertex falls on an edge or boundary.
      if (checksegments && (splitedge == NULL)) {
        // Check whether the vertex falls on a shell edge.
        tsspivot(&horiz, &brokenshell);
        if (brokenshell.sh != dummysh) {
          // The vertex falls on a shell edge.
          if (shsegflaws) {
            if (nobisect == 0) {
              // Add the shell edge to the list of encroached segments.
              encroached = (badface3d*) badsegments.alloc();
              encroached->shface = brokenshell;
              sorg (brokenshell, encroached->faceorg);
              sdest(brokenshell, encroached->facedest);
            } else if ((nobisect == 1) && (intersect == ONEDGE)) {
              // This segment may be split only if it is an internal
              //   boundary.
              if (!isridge(&horiz)) {
                // Add the shell edge to the list of encroached segments.
                encroached = (badface3d*) badsegments.alloc();
                encroached->shface = brokenshell;
                sorg (brokenshell, encroached->faceorg);
                sdest(brokenshell, encroached->facedest);
              }
            }
          }
          // Return a handle whose primary edge contains the point, which
          //   has not been inserted.
          if (verbose > 1) {
            printf("  Not insert for landing right on other subsegment.\n");
          }
          return VIOLATINGEDGE;
        }
      }
      flipcount = insertonedge(insertpoint, searchtet, splitedge);
      if (verbose > 1) {
        printf("  Successfully insert on edge with %d flips.\n", flipcount);
      }
      return SUCCESSFUL;

    case ONFACE:
      // The vertex falls on a facet or boundary.
      if (checksegments && (splitface == NULL)) {
        // Check whether the vertex falls on a shell facet.
        tspivot(horiz, brokenshell);
        if (brokenshell.sh != dummysh) {
          // The vertex falls on a shell facet.
          if (shflaws) {
            if (nobisect == 0) {
              // Add the shell facet to the list of encroached subfaces.
              enqueuebadface(&brokenshell, (point3d)NULL, 1);
            } else if ((nobisect == 1) && (intersect == ONEDGE)) {
              // This subface may be split only if it is an internal
              //   boundary.
              if (issymexist(&horiz)) {
                // Add the shell facet to the list of encroached subface.
                enqueuebadface(&brokenshell, (point3d)NULL, 1);
              }
            }
          }
          // Return a handle whose primary face contains the point,
          //   which has not been inserted.
          if (verbose > 1) {
            printf("  Not insert for landing right on other subface.\n");
          }
          return VIOLATINGFACE;
        }
      }
      flipcount = insertonface(insertpoint, searchtet, splitface);
      if (verbose > 1) {
        printf("  Successfully insert on face with %d flips.\n", flipcount);
      }
      return SUCCESSFUL;

    case INTETRAHEDRON:
      // This vertex falls inside a tetrahedron.
      flipcount = insertininterior(insertpoint, searchtet);
      if (verbose > 1) {
        printf("  Successfully insert in tetrahedron with %d flips.\n",
               flipcount);
      }
      return SUCCESSFUL;

    case OUTSIDE:
      if (verbose > 1) {
        printf("  Not insert for locating outside the mesh.\n");
      }
      return FAILED;
  } // End of switch(intersect)

  // Should never have a chance to reach here.
  return FAILED;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// insertininterior()     Insert the point in a  tetrahedron,   splitting it //
//                        into four.  Face or edge flips are used to restore //
//                        the Delaunay property.                             //
//                                                                           //
// 'insertpoint'(v) lies above wrt 'horiz'(abcd).                            //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

int mesh3d::insertininterior(point3d insertpoint, triface* horiz)
{
  triface oldabd, oldbcd, oldcad;                      // Old configuration.
  triface abdcasing, bcdcasing, cadcasing;
  face abdsh, bcdsh, cadsh;
  triface abcv, badv, cbdv, acdv;                      // New configuration.
  point3d pa, pb, pc, pd;
  REAL attrib, volume;
  int flipcount, i;

  abcv = *horiz;
  abcv.ver = 0;
  // Set the vertices of changed and new tetrahedron.
  org (abcv, pa);
  dest(abcv, pb);
  apex(abcv, pc);
  oppo(abcv, pd);

  oldabd = oldbcd = oldcad = abcv;
  fnextself(oldabd);
  enextfnextself(oldbcd);
  enext2fnextself(oldcad);
  sym(oldabd, abdcasing);
  sym(oldbcd, bcdcasing);
  sym(oldcad, cadcasing);
  maketetrahedron(&badv);
  maketetrahedron(&cbdv);
  maketetrahedron(&acdv);

  // Set 'badv' vertexs.
  setorg (badv, pb);
  setdest(badv, pa);
  setapex(badv, pd);
  setoppo(badv, insertpoint);
  // Set 'cbdv' vertexs.
  setorg (cbdv, pc);
  setdest(cbdv, pb);
  setapex(cbdv, pd);
  setoppo(cbdv, insertpoint);
  // Set 'acdv' vertexs.
  setorg (acdv, pa);
  setdest(acdv, pc);
  setapex(acdv, pd);
  setoppo(acdv, insertpoint);
  // Set 'abcv' vertexs
  setoppo(abcv, insertpoint);

  // Set the element attributes of the new tetrahedron.
  for (i = 0; i < eextras; i++) {
    attrib = elemattribute(abcv.tet, i);
    setelemattribute(badv.tet, i, attrib);
    setelemattribute(cbdv.tet, i, attrib);
    setelemattribute(acdv.tet, i, attrib);
  }
  // Set the volume constraint of the new tetrahedron.
  if (varvolume) {
    volume = volumebound(abcv.tet);
    setvolumebound(badv.tet, volume);
    setvolumebound(cbdv.tet, volume);
    setvolumebound(acdv.tet, volume);
  }

  // There may be shell facets that need to be bonded to
  //   the new tetrahedron.
  if (checksegments) {
    tspivot(oldabd, abdsh);
    if (abdsh.sh != dummysh) {
      tsdissolve(oldabd);
      tsbond(badv, abdsh);
    }
    tspivot(oldbcd, bcdsh);
    if (bcdsh.sh != dummysh) {
      tsdissolve(oldbcd);
      tsbond(cbdv, bcdsh);
    }
    tspivot(oldcad, cadsh);
    if (cadsh.sh != dummysh) {
      tsdissolve(oldcad);
      tsbond(acdv, cadsh);
    }
  }

  // Bond the new triangles to the surrounding tetrahedron.
  bond(badv, abdcasing);
  bond(cbdv, bcdcasing);
  bond(acdv, cadcasing);

  badv.loc = 3; // face<d, v, b>.
  cbdv.loc = 2;
  bond(badv, cbdv);
  cbdv.loc = 3; // face<d, v, c>.
  acdv.loc = 2;
  bond(cbdv, acdv);
  acdv.loc = 3; // face<d, v, a>.
  badv.loc = 2;
  bond(acdv, badv);
  badv.loc = 1; // face<b, v, a>.
  bond(badv, oldabd);
  cbdv.loc = 1; // face<c, v, b>.
  bond(cbdv, oldbcd);
  acdv.loc = 1; // face<a, v, c>.
  bond(acdv, oldcad);

  badv.loc = 0;
  cbdv.loc = 0;
  acdv.loc = 0;
#ifdef SELF_CHECK
  if (!isaboveplane(&abcv, insertpoint)) {
    printf("Internal error in insertininterior():\n");
    printf("  Clockwise tetrahedron prior to point insertion(abcv).\n");
    internalerror();
  }
  if (!isaboveplane(&badv, insertpoint)) {
    printf("Internal error in insertininterior():\n");
    printf("  Clockwise tetrahedron after point insertion (badv).\n");
    internalerror();
  }
  if (!isaboveplane(&cbdv, insertpoint)) {
    printf("Internal error in insertininterior():\n");
    printf("  Clockwise tetrahedron after point insertion (cbdv).\n");
    internalerror();
  }
  if (!isaboveplane(&acdv, insertpoint)) {
    printf("Internal error in insertininterior():\n");
    printf("  Clockwise tetrahedron after point insertion (acdv).\n");
    internalerror();
  }
#endif // defined SELF_CHECK
  if (verbose > 2) {
    printf("    Updating abcv ");
    dump(&abcv);
    printf("    Creating badv ");
    dump(&badv);
    printf("    Creating cbdv ");
    dump(&cbdv);
    printf("    Creating acdv ");
    dump(&acdv);
  }

  flipcount = 0;

  if (usefliplist) {
    enqueuefliplist(abcv);
    enqueuefliplist(badv);
    enqueuefliplist(cbdv);
    enqueuefliplist(acdv);
  } else {
    flipcount += flip(abcv);
    flipcount += flip(badv);
    flipcount += flip(cbdv);
    flipcount += flip(acdv);
  }

  if (isdead(horiz)) {
    // We need return a live tet.
    if (!isdead(&badv)) {
      *horiz = badv;
    } else if (!isdead(&cbdv)) {
      *horiz = cbdv;
    } else {
      // assert(!acdv.isdead());
      if (!isdead(&acdv)) {
        *horiz = acdv;
      } else {
        if (verbose) {
          printf("Warnning in insertininterior():\n");
          printf("  After %d flips, we can't return a live tet.\n", flipcount);
        }
      }
    }
  }

  return flipcount;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// insertonface()    Insert a point on a face of tetrahedron, splitting one  //
//                   tetrahedron into three (if the face lies on outer       //
//                   boundary), or two tetrahedras into six.  Face or edge   //
//                   flips are used to restore the Delaunay property.        //
//                                                                           //
// 'horiz.location()' indicates the face where 'insertpoint' lies on. If the //
// 'splitface' != NULL, this mean insert a point on boundary face.   'horiz' //
// should be a handle of this boundary face adjoining to.                    //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

int mesh3d::insertonface(point3d insertpoint, triface* horiz, face* splitface)
{
  triface oldbcd, oldcad, oldace, oldcbe;              // Old configuration.
  triface bcdcasing, cadcasing, acecasing, cbecasing;
  face bcdsh, cadsh, acesh, cbesh;
  triface badv, cbdv, acdv, abev, bcev, caev;          // New configuration.
  point3d pa, pb, pc, pd, pe;
  REAL attrib, volume;
  bool mirrorflag;
  int flipcount, i;

  badv = *horiz;
  badv.ver = 0;
  // Now assume 'badv' is tet<a, b, c, d>.
  org (badv, pa);
  dest(badv, pb);
  apex(badv, pc);
  oppo(badv, pd);
  // Is there a second tetrahderon?
  mirrorflag = issymexist(&badv);
  if (mirrorflag) {
    // This is a interior face.
    sym(badv, abev);
    findversion(&abev, &badv);
    // Now 'abev' is tet <b, a, c, e>.
    oppo(abev, pe);
  }

  oldbcd = oldcad = badv;
  enextfnextself(oldbcd);
  enext2fnextself(oldcad);
  fnextself(badv);
  esymself(badv);  // Now 'badv' is tet<b, a, d, c>.
  sym(oldbcd, bcdcasing);
  sym(oldcad, cadcasing);
  maketetrahedron(&cbdv);
  maketetrahedron(&acdv);
  // Is there a second tetrahderon?
  if (mirrorflag) {
    // This is a interior face.
    oldace = oldcbe = abev;
    enextfnextself(oldace);
    enext2fnextself(oldcbe);
    fnextself(abev);
    esymself(abev);  // Now abev is tet<a, b, e, c>.
    sym(oldace, acecasing);
    sym(oldcbe, cbecasing);
    maketetrahedron(&caev);
    maketetrahedron(&bcev);
  } else {
    // Splitting the boundary face increases the number of boundary faces.
    hullsize += 2;
  }

  // Set the vertices of changed and new tetrahedron.
  // Set 'cbdv'.
  setorg (cbdv, pc);
  setdest(cbdv, pb);
  setapex(cbdv, pd);
  setoppo(cbdv, insertpoint);
  // Set 'acdv'.
  setorg (acdv, pa);
  setdest(acdv, pc);
  setapex(acdv, pd);
  setoppo(acdv, insertpoint);
  // Set 'badv'.
  setoppo(badv, insertpoint);

  // Set the element attributes of new tetrahedron.
  for (i = 0; i < eextras; i++) {
    attrib = elemattribute(badv.tet, i);
    setelemattribute(cbdv.tet, i, attrib);
    setelemattribute(acdv.tet, i, attrib);
  }
  if (varvolume) {
    // Set the area constraint of new tetrahedron.
    volume = volumebound(badv.tet);
    setvolumebound(cbdv.tet, volume);
    setvolumebound(acdv.tet, volume);
  }

  if (mirrorflag) {
    // Set 'caev'.
    setorg (caev, pc);
    setdest(caev, pa);
    setapex(caev, pe);
    setoppo(caev, insertpoint);
    // Set 'bcev'.
    setorg(bcev, pb);
    setdest(bcev, pc);
    setapex(bcev, pe);
    setoppo(bcev, insertpoint);
    // Set 'abev'.
    setoppo(abev, insertpoint);

    // Set the element attributes of new tetrahedron.
    for (i = 0; i < eextras; i++) {
      attrib = elemattribute(abev.tet, i);
      setelemattribute(bcev.tet, i, attrib);
      setelemattribute(caev.tet, i, attrib);
    }
    if (varvolume) {
      // Set the area constraint of new tetrahedron.
      volume = volumebound(abev.tet);
      setvolumebound(bcev.tet, volume);
      setvolumebound(caev.tet, volume);
    }
  }

  // There may be shell facets that need to be bonded to the
  //   new tetrahedron.
  if (checksegments) {
    tspivot(oldbcd, bcdsh);
    if (bcdsh.sh != dummysh) {
      tsdissolve(oldbcd);
      tsbond(cbdv, bcdsh);
    }
    tspivot(oldcad, cadsh);
    if (cadsh.sh != dummysh) {
      tsdissolve(oldcad);
      tsbond(acdv, cadsh);
    }
    if (mirrorflag) {
      tspivot(oldace, acesh);
      if (acesh.sh != dummysh) {
        tsdissolve(oldace);
        tsbond(caev, acesh);
      }
      tspivot(oldcbe, cbesh);
      if (cbesh.sh != dummysh) {
        tsdissolve(oldcbe);
        tsbond(bcev, cbesh);
      }
    }
  }

  // Bond the new tetrahedron to the surrounding tetrahedron.
  bond(cbdv, bcdcasing);  // Default 'cbdv' loc = 0.
  bond(acdv, cadcasing);  // Default 'acdv' loc = 0.
  cbdv.loc = 2;
  bond(cbdv, oldbcd);
  cbdv.loc = 3;
  acdv.loc = 2;
  bond(cbdv, acdv);
  acdv.loc = 3;
  bond(acdv, oldcad);

  if (mirrorflag) {
    bond(caev, acecasing);  // Default 'bcev' loc = 0.
    bond(bcev, cbecasing);  // Default 'caev' loc = 0.
    caev.loc = 2;
    bond(caev, oldace);
    caev.loc = 3;
    bcev.loc = 2;
    bond(caev, bcev);
    bcev.loc = 3;
    bond(bcev, oldcbe);

    // Bond two new coplanar facets.
    cbdv.loc = 1;
    bcev.loc = 1;
    bond(cbdv, bcev);
    acdv.loc = 1;
    caev.loc = 1;
    bond(acdv, caev);
  }

  cbdv.loc = 0;
  acdv.loc = 0;
  if (mirrorflag) {
    bcev.loc = 0;
    caev.loc = 0;
  }

  if (splitface != (face *) NULL) {
    // We need insert two new subface into current mesh.
    triface righttet, lefttet;
    face oldrightshface, oldleftshface;
    face rightshseg, leftshseg;
    face newrightshface, newleftshface;

    // Init 'splitface' be face<a, b, c>
    findversion(splitface, pa, pb, 0);
    senext(*splitface, oldrightshface);  // face<b, c, a>
    senext2(*splitface, oldleftshface);  // face<c, a, b>

    // Set 'splitface' be face<a, b, v>
    setsapex(*splitface, insertpoint);
    // Insert two new shell facets at cbdv(right), and acdv(left).
    //   Set 'righttet' be tet<c, b, v, -d>.
    fnext(cbdv, righttet);
    //   Insert a new subface abutting 'righttet'.
    insertsubface(&righttet, mark(*splitface), 0);
    //   Set 'lefttet' tet<a, c, v, -d>.
    fnext(acdv, lefttet);
    //   Insert a new subface abutting 'leftete'.
    insertsubface(&lefttet, mark(*splitface), 0);

    // Set 'newrightshface' be face<b, c, v>
    tspivot(righttet, newrightshface);
    findversion(&newrightshface, pb, pc, 0);
    // Set 'newleftshface' be face<c, a, v>
    tspivot(lefttet, newleftshface);
    findversion(&newleftshface, pc, pa, 0);

    // Bond subsegments to two new shell facets if there have one. Do not
    //   forget to dissolve orgin bond first.
    sspivot(oldrightshface, rightshseg);
    if (rightshseg.sh != dummysh) {
      ssdissolve(oldrightshface);
      ssbond(newrightshface, rightshseg);
    }
    sspivot(oldleftshface, leftshseg);
    if (leftshseg.sh != dummysh) {
      ssdissolve(oldleftshface);
      ssbond(newleftshface, leftshseg);
    }

    if (shflaws) {
      // Now, the original 'splitface' was splitted to 'splitface',
      //   'newrightshface' and 'newleftshface'.
      // In quality mesh generation step, we need check if these three
      //   subfaces being encroached. (Because they are Delaunay faces
      //   and needn't do flip).
      uncheckedshlist->append(splitface);
      uncheckedshlist->append(&newrightshface);
      uncheckedshlist->append(&newleftshface);
    }
  } // if (splitface != (face *) NULL)

#ifdef SELF_CHECK
  if (!isaboveplane(&badv, insertpoint)) {
    printf("Internal error in insertonface():\n");
    printf("  Clockwise tetra prior to face point insertion (badv).\n");
    internalerror();
  }
  if (!isaboveplane(&cbdv, insertpoint)) {
    printf("Internal error in insertonface():\n");
    printf("  Clockwise tetra after face point insertion (cbdv).\n");
    internalerror();
  }
  if (!isaboveplane(&acdv, insertpoint)) {
    printf("Internal error in insertonface():\n");
    printf("  Clockwise tetra after face point insertion (acdv).\n");
    internalerror();
  }
  if (mirrorflag) {
    if (!isaboveplane(&abev, insertpoint)) {
      printf("Internal error in insertonface():\n");
      printf("  Clockwise tetra prior to face point insertion (abev).\n");
      internalerror();
    }
    if (!isaboveplane(&bcev, insertpoint)) {
      printf("Internal error in insertonface():\n");
      printf("  Clockwise tetra after face point insertion (bcev).\n");
      internalerror();
    }
    if (!isaboveplane(&caev, insertpoint)) {
      printf("Internal error in insertonface():\n");
      printf("  Clockwise tetra after face point insertion (caev).\n");
      internalerror();
    }
  }
#endif // defined SELF_CHECK
  if (verbose > 2) {
    printf("    Updating badv ");
    dump(&badv);
    printf("    Creating cbdv ");
    dump(&cbdv);
    printf("    Creating acdv ");
    dump(&acdv);
    if (mirrorflag) {
      printf("    Updating abev ");
      dump(&abev);
      printf("    Creating bcev ");
      dump(&bcev);
      printf("    Creating caev ");
      dump(&caev);
    }
  }

  flipcount = 0;

  if (usefliplist) {
    enqueuefliplist(badv);
    enqueuefliplist(cbdv);
    enqueuefliplist(acdv);
    if (mirrorflag) {
      enqueuefliplist(abev);
      enqueuefliplist(bcev);
      enqueuefliplist(caev);
    }
  } else {
    flipcount += flip(badv);
    flipcount += flip(cbdv);
    flipcount += flip(acdv);
    if (mirrorflag) {
      flipcount += flip(abev);
      flipcount += flip(bcev);
      flipcount += flip(caev);
    }
  }

  if (isdead(horiz)) {
    // We need return a live tet.
    if (splitface != (face*) NULL) {
      stpivot(*splitface, *horiz);
      if (horiz->tet == dummytet) {
        assert(mirrorflag == 0);
        sesymself(*splitface);
        stpivot(*splitface, *horiz);
      }
    } else if (!isdead(&cbdv)) {
      *horiz = cbdv;
    } else if (!isdead(&acdv)) {
      *horiz = acdv;
    } else {
      assert(mirrorflag);
      if (!isdead(&abev)) {
        *horiz = abev;
      } else if (!isdead(&bcev)) {
        *horiz = bcev;
      } else {
        // assert(!caev.isdead());
        if (!isdead(&caev)) {
          *horiz = caev;
        } else {
          if (verbose) {
            printf("Warnning in insertonface(): \n");
            printf("  After %d flips, we can't return a live tet.\n",
                   flipcount);
          }
        }
      }
    }
  }

  return flipcount;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// insertonedge()    Insert a point on an edge, splitting all tetrahedra     //
//                   which around this edge into two.  Face or edge flips    //
//                   are used to restore the Delaunay property.              //
//                                                                           //
// 'horiz.org()' and 'horiz.dest()'  indicates the edge where 'insertpoint'  //
// lies on. If the 'splitedge' != NULL, this mean insert a point on boundary //
// edge. 'horiz' should be a handle of this boundary edge adjoining to.      //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

int mesh3d::insertonedge(point3d insertpoint, triface* horiz, face* splitedge)
{
  triface bdrytet, spintet, tmptet;
  triface *bots, *oldtops, *topcasings, *newtops;
  face topshell;
  triface tmpbond0, tmpbond1;
  point3d pa, pb, nj, nj_1;
  point3d tapex;
  int wrapfacecount, wrapcount, hitbdry;
  int flipcount, i, k;

  // Adjust 'horiz''s face version. Let it belong to EdgeRing = 0.
  adjustedgering(*horiz, CCW);
  // Now, we can sure 'horiz' be tet<b, a, n1, n2>.

  // First find how much tetrahedron wrap around edge<ba>. As a side effect,
  //   we will find if edge<ba> lies on boundary, if so we keep the handle
  //   of first encountered boundary tetrahedron in 'bdrytet'.
  spintet = *horiz;
  apex(*horiz, tapex);
  wrapfacecount = 1;
  hitbdry = 0;
  while (true) {
    if (fnextself(spintet)) {
      if (apex(spintet) == tapex) {
        break;
      }
      wrapfacecount ++;
    } else {
      hitbdry ++;
      if (hitbdry >= 2) {
        break;
      } else {
        esym(spintet, bdrytet);
        esym(*horiz, spintet);
      }
    }
  }

  // Determine how much wrap tetrahedra from 'wrapfacecount'.
  if (hitbdry == 0) {
    wrapcount = wrapfacecount;
  } else {
    wrapcount = wrapfacecount - 1;
    // Splitting the boundary face increases the number of boundary faces.
    hullsize += 2;
  }
  assert(wrapcount >= 1);

  // Current state:
  //   Let i = wrapfacecount be the total found faces. Let the wrap faces'
  //     apex sequence be: n[1], n[2], ..., n[i].
  //   IF hitbdry = 0, THEN edge<ba> is inner edge. 'horiz' will be tet
  //     <b, a, n[1], n[2]>; ELSE the edge <ba> is on boundary. 'bdrytet'
  //     will be tet<a, b, n[j], n[j-1]>; (where 2 <= j <= i).
  //   Note: the 'horiz' and 'bdrytet' has inversed fnext direction.
  //
  // For using the same process to cope with the diffrence between 'horiz'
  //   and 'bdrytet', we adjust 'horiz' be tet<a, b, n[2], n[1]>. So they
  //   have the same fnext direction.
  if (hitbdry == 0) {
    fnext(*horiz, spintet);
    esymself(spintet);
  } else {
    spintet = bdrytet;
  }

  // Make lists of dividing(bot, oldtop) tetrahedra, Create new(newtop)
  //   tetrahedra for each original tetrahedron.
  bots = new triface[wrapcount];
  oldtops = new triface[wrapcount];
  topcasings = new triface[wrapcount];
  newtops = new triface[wrapcount];

  // Walk around the edge, gathering tetrahedra and setting up new tetra-
  //   hedra. If 'hitbdry' != 0, start from 'bdrytet', otherwise, start
  //   from 'horiz'. For convinence, we inverse the number sequence of the
  //   apex of each wrapfaces in Owen's paper, and let the vertex sequence
  //   be : 1, 2, ..., j-1, j. (where j = wrapcount.)
  for (i = 0; i < wrapcount; i ++) {
    fnextself(spintet);
    // Set 'tmptet' be tet<b, a, n[j], n[j-1]>.
    esym(spintet, tmptet);
    // Set 'bots[i]' be tet<n[j], a, n[j-1], b>.
    enextself(tmptet);
    fnext(tmptet, bots[i]);
    esymself(bots[i]);
    // Set 'oldtops[i]' be tet<n[j], b, n[j-1], -a>.
    enextself(tmptet);
    fnext(tmptet, oldtops[i]);
    // Set 'topcasing'.
    sym(oldtops[i], topcasings[i]);
    maketetrahedron(&(newtops[i]));
  }

  org (spintet, pa);
  dest(spintet, pb);
  // Set the vertices of changed and new tetrahedra.
  for (i = 0; i < wrapcount; i ++) {
    // 'bots[i]' is tet<n[j], a, n[j-1], b>.
    org (bots[i], nj); //
    apex(bots[i], nj_1);
    // Set 'newtops[i]' be tet<b, n[j], n[j-1], v>.
    setorg(newtops[i], pb);
    setdest(newtops[i], nj);
    setapex(newtops[i], nj_1);
    setoppo(newtops[i], insertpoint);
    // Set 'bots' be tet<n[j], a, n[j-1], v>.
    setoppo(bots[i], insertpoint);
    // Set the element attributes of a new tetrahedron.
    for (k = 0; k < eextras; k++) {
      setelemattribute(newtops[i].tet, k,
                       elemattribute(bots[i].tet, k));
    }
    if (varvolume) {
      // Set the area constraint of a new tetrahedron.
      setvolumebound(newtops[i].tet, volumebound(bots[i].tet));
    }
  }

  // There may be shell facets that need to be bonded to each new
  //   tetrahedron's topcasing side.
  if (checksegments) {
    // Check topcasing shell at each newtops side.
    for (i = 0; i < wrapcount; i ++) {
      tspivot(oldtops[i], topshell);
      if (topshell.sh != dummysh) {
        tsdissolve(oldtops[i]);
        tsbond(newtops[i], topshell);
      }
    }
  }

  // Bond newtops to topcasings and bots.
  for (i = 0; i < wrapcount; i ++) {
    // default: 'newtops[i]' loc = 0.
    bond(newtops[i], topcasings[i]);
    newtops[i].loc = 2;
    bond(newtops[i], oldtops[i]);
  }
  // Bond between each newtops. Becareful the boundary case.
  tmpbond0 = newtops[0];
  for (i = 1; i <= wrapcount; i ++) {
    if(i == wrapcount) {
      if(hitbdry == 0) {
        tmpbond1 = newtops[0];
      } else {
        break; // Insert on boundary edge case.
      }
    } else {
      tmpbond1 = newtops[i];
    }
    tmpbond0.loc = 1;
    tmpbond1.loc = 3;
    bond(tmpbond0, tmpbond1);
    tmpbond0 = tmpbond1;
  }

  for (i = 0; i < wrapcount; i ++) {
    newtops[i].loc = 0;
  }

  // There may be shell facets that need to be bonded to each new
  //   tetrahedron's sandwich side.
  if (checksegments || (splitedge != (face*) NULL)) {
    triface tmpbot, tmpnewtop;
    face botsandwichsh, modibotleftsh, modibotrightsh;
    face botleftshseg, botrightshseg;
    face newtopsandwichsh;

    for (i = 0; i < wrapcount; i ++) {
      // Set 'tmpbot' be tet<a, n[j], v, n[j-1]>.
      fnext(bots[i], tmpbot);
      esymself(tmpbot);
      tspivot(tmpbot, botsandwichsh);
      if (botsandwichsh.sh != dummysh) {
        findversion(&botsandwichsh, &tmpbot);
        // Set 'botsandwichsh' be face<n[j], a, v>
        setsapex(botsandwichsh, insertpoint);
        // Set 'modibotleftsh' be face<v, n[j], a>
        senext2(botsandwichsh, modibotleftsh);
        // Set 'tmpnewtop' be tet<n[j], b, v, n[j-1]>.
        fnext(newtops[i], tmpnewtop);
        esymself(tmpnewtop);
        // Insert a new shell facet at 'tmpnewtop'.
        insertsubface(&tmpnewtop, mark(botsandwichsh), 0);
        // Set 'newtopsandwichsh' be face<b, n[j], v>.
        tspivot(tmpnewtop, newtopsandwichsh);
        findversion(&newtopsandwichsh, &tmpnewtop);
        // Check subsegment that need bond to 'botleftshseg'.
        sspivot(modibotleftsh, botleftshseg);
        if (botleftshseg.sh != dummysh) {
          ssdissolve(modibotleftsh);
          ssbond(newtopsandwichsh, botleftshseg);
        }
        // Here we can skip checking the right side's segment, because
        //   if there exist a segment, it will be split later.
        if (shflaws) {
          // Now, the original 'botsandwichsh' was splitted to
          //   'botsandwichsh' and 'newtopsandwichsh'.
          // In quality mesh generation step, we need check if these two
          //   subfaces being encroached. (Because they are Delaunay faces
          //   and needn't do flip).
          uncheckedshlist->append(&botsandwichsh);
          uncheckedshlist->append(&newtopsandwichsh);
        }
      }
    }
    if (hitbdry != 0) {
      // Additional shell facet at bots[0] other side need split.
      // We recall: 'bots[0]' is tet<n[j], a, n[j-1], v>.
      //         'newtops[0]' is tet<b, n[j], n[j-1], v>.
      // Set 'tmpbot' be tet<n[j-1], pa, v, n[j]>.
      tmpbot = bots[0];
      enextfnextself(tmpbot);
      esymself(tmpbot);
      tspivot(tmpbot, botsandwichsh);
      if (botsandwichsh.sh != dummysh) {
        // Set 'botsandwichsh' be face<a, n[j-1], v>.
        findversion(&botsandwichsh, &tmpbot);
        setsapex(botsandwichsh, insertpoint);
        // Set 'modibotrightsh' be face<n[j-1], v, a>.
        senext(botsandwichsh, modibotrightsh);
        // Set 'tmpnewtop' be tet<b, n[j-1], v, n[j]>.
        tmpnewtop = newtops[0];
        enext2fnextself(tmpnewtop);
        esymself(tmpnewtop);
        // Insert a new shell facet at 'tmpnewtop'.
        insertsubface(&tmpnewtop, mark(botsandwichsh), 0);
        // Set 'newtopsandwichsh' be face<n[j-1], b, v>.
        tspivot(tmpnewtop, newtopsandwichsh);
        findversion(&newtopsandwichsh, &tmpnewtop);
        // Check subsegment that need bond to 'botrightshseg'.
        sspivot(modibotrightsh, botrightshseg);
        if (botrightshseg.sh != dummysh) {
          ssdissolve(modibotrightsh);
          ssbond(newtopsandwichsh, botrightshseg);
        }
        // Here we can skip checking the left side's segment, because
        //   if there exist a segment, it will be split later.
        if (shflaws) {
          uncheckedshlist->append(&botsandwichsh);
          uncheckedshlist->append(&newtopsandwichsh);
        }
      }
    }

    if (splitedge != (face*) NULL) {
      face newseg;
      face tmpbond0;
      // We need insert a new subsegments into current mesh.
      // Set 'splitedge' be edge<ab>.
      findversion(splitedge, pa, pb, 0);
      // Set 'splitedge' be edge<av>.
      setsdest(*splitedge, insertpoint);
      // Insert a new subsegment <vb> at 'tmpnewtop'.
      fnext(newtops[0], tmpnewtop);
      enext2self(tmpnewtop);
      insertsubsegment(&tmpnewtop, mark(*splitedge));
      tsspivot(&tmpnewtop, &newseg);
      findversion(&newseg, insertpoint, pb, 0);
      // Bond these two edges. So it can be quickly found each other after
      //   splitting this subsegment.
      senext(*splitedge, tmpbond0);
      senext2self(newseg);
      sbond(tmpbond0, newseg);
    }
  }

#ifdef SELF_CHECK
  for (i = 0; i < wrapcount; i ++) {
    if (!isaboveplane(&(bots[i]), insertpoint)) {
      printf("Internal error in insertonedge():\n");
      printf("  Clockwise tetra prior to point insertion (bots[%i]).\n", i);
      internalerror();
    }
    if (!isaboveplane(&(newtops[i]), insertpoint)) {
      printf("Internal error in insertonedge():\n");
      printf("  Clockwise tetra after point insertion (bots[%i]).\n", i);
      internalerror();
    }
  }
#endif // defined SELF_CHECK
  if (verbose > 2) {
    for (i = 0; i < wrapcount; i ++) {
      printf("    Updating bots[%i] ", i);
      dump(&(bots[i]));
      printf("    Creating newtops[%i] ", i);
      dump(&(newtops[i]));
    }
  }

  flipcount = 0;

  if (usefliplist) {
    for (i = 0; i < wrapcount; i ++) {
      enqueuefliplist(bots[i]);
      enqueuefliplist(newtops[i]);
    }
  } else {
    for (i = 0; i < wrapcount; i ++) {
      flipcount += flip(bots[i]);
      flipcount += flip(newtops[i]);
    }
  }

  if (isdead(horiz)) {
    // We need return a live tet.
    if (splitedge != (face*) NULL) {
      sstpivot(splitedge, horiz); // *horiz = splitedge->sstpivot();
    } else {
      for (i = 0; i < wrapcount; i ++) {
        if (!isdead(&(bots[i]))) {
          *horiz = bots[i];
          break;
        }
        if (!isdead(&(newtops[i]))) {
          *horiz = newtops[i];
          break;
        }
      }
      // assert(i < wrapcount);
      if (!(i < wrapcount)) {
        if (verbose) {
          printf("Warnning in insertonedge(): \n");
          printf("  After %d flips, we can't return a live tet.\n", flipcount);
        }
      }
    }
  }

  delete [] bots;
  delete [] oldtops;
  delete [] topcasings;
  delete [] newtops;

  return flipcount;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// insertsubface()    Create a new shell facet and insert it between two     //
//                    tetrahedra.                                            //
//                                                                           //
// The new shell facet is created at the face described by the handle 'tet'. //
// Its vertices are properly initialized. The marker 'shellemark' is applied //
// to the shell facet and, if appropriate, its vertices.                     //
//                                                                           //
// The 'autobondsegs' flag is used to indicate whether we need do a segment  //
// searching for the newly inserted subface. Generally, in mesh refinement   //
// stage, we always need searching segments for newly inserted subface, so   //
// the (triface).tsspivot() primitive will work correctly and efficiently.   //
// But when do a local transformation on a face or edge, the segments around //
// the subface always can be found before do flipping. So there need not do  //
// segments searching (set autobondsegs = 0).                                //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::insertsubface(triface* tet, int shellemark, int autobondsegs)
{
  triface abcd, bace;
  face newshell, bseg;
  point3d pa, pb, pc;
  int i;

  abcd = *tet;
  adjustedgering(abcd, CCW);
  // Mark points if possible.
  org (abcd, pa);
  dest(abcd, pb);
  apex(abcd, pc);
  if (shellemark != NONSOLIDFLAG) {
    if (pointmark(pa) == 0) {
      setpointmark(pa, shellemark);
    }
    if (pointmark(pb) == 0) {
      setpointmark(pb, shellemark);
    }
    if (pointmark(pc) == 0) {
      setpointmark(pc, shellemark);
    }
  }

  // Check if there's already exist a shell facet here.
  tspivot(abcd, newshell);
  if (newshell.sh == dummysh) {
    // Make new shell facet and initialize its vertices.
    makeshellface(&subfaces, &newshell);
    setsorg (newshell, pb);
    setsdest(newshell, pa);
    setsapex(newshell, pc);
    // Bond new shell facet to the two tetrahedra it is sandwiched
    //   between.  Note that the facing tetrahedron 'oppotet' might be
    //   equal to 'dummytet' (outer space), but the new shell facet is
    //   bonded to it all the same.
    tsbond(abcd, newshell);
    sym(abcd, bace);
    sesymself(newshell);
    tsbond(bace, newshell);
    if (autobondsegs) {
      // Check if there exist subsegments at three edge of this new
      //   subface. If so, set corresponding pointers in 'newshell' to
      //   link these subsegments.
      // Now 'abcd' and 'newshell' both locked at edge 'ab'.
      for (i = 0; i < 3; i ++) {
        enextself(abcd);
        senextself(newshell);
        tsspivot(&abcd, &bseg); // bseg = abcd.sspivot();
        if (bseg.sh != dummysh) {
          ssbond(newshell, bseg);
        }
      }
    }
    setmark(newshell, shellemark);
    if (verbose > 2) {
      printf("    Inserting new: ");
      dump(&newshell);
    }
  } else {
    // The exist shellface may be nonsolid(<0) or not have a marker(0), now
    //   we can make it solid or set new shell's mark.
    if (shellemark != NONSOLIDFLAG) {
      if (isnonsolid(newshell) || (mark(newshell) == 0)) {
        setmark(newshell, shellemark);
      }
    }
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// insertsubsegment()    Create a new subsegment and connect it to surround- //
//                       ing subface.                                        //
//                                                                           //
// The new subsegment is created at the face described by the handle 'tet'.  //
// Its vertices are properly initialized. The marker 'shellemark' is applied //
// to the shell facet and, if appropriate, its vertices.                     //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::insertsubsegment(triface* tet, int shellemark)
{
  triface abcd, spintet;
  face newseg, parentshell;
  point3d pa, pb;
  point3d tapex;
  int hitbdry, subfacecount;

  abcd = *tet;
  adjustedgering(abcd, CCW);
  org(abcd, pa);
  dest(abcd, pb);
  // Mark points if possible.
  if (shellemark != NONSOLIDFLAG) {
    if (pointmark(pa) == 0) {
      setpointmark(pa, shellemark);
    }
    if (pointmark(pb) == 0) {
      setpointmark(pb, shellemark);
    }
  }
  // Check if there's already exist a subsegment at this face's side.
  tsspivot(&abcd, &newseg); // newseg = abcd.sspivot();
  if (newseg.sh == dummysh) {
    // Make new subsegment and initialize its vertices.
    makeshellface(&subsegs, &newseg);
    setsorg(newseg, pb);
    setsdest(newseg, pa);
    setmark(newseg, shellemark);
    // To insert this subsegment, spin around this edge, to find all surro-
    //   unding subface and set connection between them. If there isn't
    //   exist such subface, we need create a nonsolid subface, and insert
    //   it to mesh for insert this subsegment.
    spintet = abcd;
    apex(abcd, tapex);
    subfacecount = 0;
    hitbdry = 0;
    tspivot(spintet, parentshell);
    if (parentshell.sh != dummysh) {
      findversion(&parentshell, &spintet);
      ssbond(parentshell, newseg);
      subfacecount++;
    }
    while (true) {
      if (fnextself(spintet)) {
        if (apex(spintet) == tapex) {
          break;  // Rewind, can leave now.
        }
        tspivot(spintet, parentshell);
        if (parentshell.sh != dummysh) {
          findversion(&parentshell, &spintet);
          ssbond(parentshell, newseg);
          subfacecount++;
        }
      } else {
        hitbdry ++;
        if(hitbdry >= 2) {
          break;
        } else {
          esym(abcd, spintet);
        }
      }
    }
    if (subfacecount == 0) {
      // Insert a new shell facet for holding the new subsegment.
      if (verbose > 2) {
        printf("    Inserting a nonsolid subface for holding subsegment.\n");
      }
      insertsubface(&abcd, NONSOLIDFLAG, 1);
      tspivot(abcd, parentshell);
      findversion(&parentshell, &abcd);
      ssbond(parentshell, newseg);
    }
    if (verbose > 2) {
      printf("    Inserting new: ");
      dump(&newseg);
    }
  } else {
    if (mark(newseg) == 0) {
      setmark(newseg, shellemark);
    }
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// deletesite()    Delete a vertex from a Delaunay triangulation, ensuring   //
//                 that the triangulation remains Delaunay.                  //
//                                                                           //
// The origin of `deltet' is deleted. Only interior points that do not lie   //
// on segments (shell edges) or boundaries may be deleted.                   //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

int mesh3d::deletesite(triface *deltet)
{
  list *incitetlist, *incishlist;
  list *equatorpointlist, *equatoredgelist;
  list *northpointlist, *sourthpointlist;
  list *equatorcasinglist;
  list *northcasinglist, *sourthcasinglist;
  list *northbacktracelist, *sourthbacktracelist;
  triface *giftfaces;
  triface *incitet, testtet, neighbortet;
  face *incish,  testsh, testseg;
  point3d *giftpoints;
  point3d delorg, deldest, delapex;
  point3d torg, tdest, tapex;
  point3d tnorth;
  triangulateio in, out;
  REAL norm[3], xaxi[3], yaxi[3];
  REAL v0[3], v1[3], dsin;
  REAL *northattribs, *sourthattribs;
  REAL northvolume, sourthvolume;
  int *equatoredge, shellmark, add2north;
  int bdrycount, bdry2count;
  int orgori, destori, apexori;
  int numberofgiftfaces, numberofgiftpoints;
  int success;
  int i, j, index;

  testtet = *deltet;
  delorg = org(testtet);
  adjustedgering(testtet, CCW);
  findorg(&testtet, delorg);

  if (verbose > 1) {
    printf("  Delete point from mesh: (%.12g, %.12g, %.12g) %d\n",
           delorg[0], delorg[1], delorg[2], pointmark(delorg));
  }

  // Get all tetrahedra and subfaces which incidents to the delete point.
  incitetlist = new list(sizeof(triface));
  incishlist = new list(sizeof(face));
  incitetlist->setcomp((compfunc) &compare2tets);
  incishlist->setcomp((compfunc) &compare2shfaces);
  bdrycount = bdry2count = 0;

  if (verbose > 2) {
    printf("    Queuing incident tet (%d, %d, %d, %d).\n",
           pointmark(org(testtet)), pointmark(dest(testtet)),
           pointmark(apex(testtet)), pointmark(oppo(testtet)));
  }
  incitetlist->append(&testtet);
  symself(testtet);
  if (testtet.tet != dummytet) {
    adjustedgering(testtet, CCW);
    findorg(&testtet, delorg);
    if (verbose > 2) {
      printf("    Queuing incident tet (%d, %d, %d, %d).\n",
             pointmark(org(testtet)), pointmark(dest(testtet)),
             pointmark(apex(testtet)), pointmark(oppo(testtet)));
    }
    incitetlist->append(&testtet);
    tspivot(testtet, testsh);
    if (testsh.sh != dummysh) {
      if (!isnonsolid(testsh)) {
        bdry2count++;
        findorg(&testsh, delorg);
        if (verbose > 2) {
           printf("    Queuing incident face (%d, %d, %d) (inner).\n",
                  pointmark(sorg(testsh)), pointmark(sdest(testsh)),
                  pointmark(sapex(testsh)));
        }
        incishlist->append(&testsh);
      }
    }
  } else {
    tspivot(*deltet, testsh);
    assert(testsh.sh != dummysh);
    assert(!isnonsolid(testsh));
    bdrycount++;
    findorg(&testsh, delorg);
    if (verbose > 2) {
      printf("    Queuing incident boundary face (%d, %d, %d).\n",
             pointmark(sorg(testsh)), pointmark(sdest(testsh)),
             pointmark(sapex(testsh)));
    }
    incishlist->append(&testsh);
  }
  // Keep adding tets and subfaces incident on delpoint until they're
  //   all there.
  for (i = 0; i < incitetlist->len(); i++) {
    incitet = (triface *)(* incitetlist)[i];
    for (j = 0; j < 2; j++) {
      testtet = *incitet;
      if (j == 1) {
        enext2self(testtet);
      }
      fnextself(testtet);
      if (issymexist(&testtet)) {
        symself(testtet);
        if (incitetlist->hasitem(&testtet) == -1) {
          // This tet need add to queue.
          adjustedgering(testtet, CCW);
          findorg(&testtet, delorg);
          if (verbose > 2) {
            printf("    Queuing incident tet (%d, %d, %d, %d).\n",
                   pointmark(org(testtet)), pointmark(dest(testtet)),
                   pointmark(apex(testtet)), pointmark(oppo(testtet)));
          }
          incitetlist->append(&testtet);
          tspivot(testtet, testsh);
          if (testsh.sh != dummysh) {
            if (!isnonsolid(testsh)) {
              bdry2count++;
              findorg(&testsh, delorg);
              if (verbose > 2) {
                printf("    Queuing incident face (%d, %d, %d) (inner).\n",
                       pointmark(sorg(testsh)), pointmark(sdest(testsh)),
                       pointmark(sapex(testsh)));
              }
              incishlist->append(&testsh);
            }
          }
        } else {
          // This tet has been added to queue, we still need check if there
          //   exist inner shell face at two side of this tet.
          tspivot(testtet, testsh);
          if (testsh.sh != dummysh) {
            if (!isnonsolid(testsh)) {
              if (incishlist->hasitem(&testsh) == -1) {
                bdry2count++;
                findorg(&testsh, delorg);
                if (verbose > 2) {
                  printf("    Queuing incident face (%d, %d, %d) (inner).\n",
                         pointmark(sorg(testsh)), pointmark(sdest(testsh)),
                         pointmark(sapex(testsh)));
                }
                incishlist->append(&testsh);
              }
            }
          }
        }
      } else {
        tspivot(testtet, testsh);
        assert(testsh.sh != dummysh);
        assert(!isnonsolid(testsh));
        bdrycount++;
        findorg(&testsh, delorg);
        if (verbose > 2) {
          printf("    Queuing incident boundary face (%d, %d, %d).\n",
                 pointmark(sorg(testsh)), pointmark(sdest(testsh)),
                 pointmark(sapex(testsh)));
        }
        incishlist->append(&testsh);
      }
    }
  }

  if (((bdry2count > 0) && (bdrycount > 0)) ||
      ((bdry2count == 1) || (bdrycount == 1))) {
    if (!quiet) {
      printf("Warnning: ");
      if ((bdry2count > 0) && (bdrycount > 0)) {
        printf("Try to delete a point which seems locating on the");
        printf(" intersection of two incident facets.\n");
      } else {
        printf("Try to delete a point which is an apex on boundary.\n");
      }
    }
    delete incitetlist;
    delete incishlist;
    return 0;
  }

  if ((bdry2count > 0) || (bdrycount > 0)) {
    if (verbose > 2) {
      printf("    Generating a triangulation for coplanar subfaces.\n");
    }
    equatorpointlist = new list("point");
    equatoredgelist = new list(sizeof(int) * 2);

    testsh = *(face *)(* incishlist)[0];
    assert(delorg == sorg(testsh));
    deldest = sdest(testsh);
    delapex = sapex(testsh);
    equatorpointlist->append(&deldest);
    equatorpointlist->append(&delapex);
    equatoredge = (int*) equatoredgelist->alloc();
    equatoredge[0] = 0;
    equatoredge[1] = 1;
    for (i = 1; i < incishlist->len(); i++) {
      incish = (face *)(* incishlist)[i];
      assert(delorg == sorg(*incish));
      tdest = sdest(*incish);
      tapex = sapex(*incish);
#ifdef SELF_CHECK
      if ((!iscoplane(delorg, deldest, delapex, tdest)) ||
          (!iscoplane(delorg, deldest, delapex, tapex))) {
        printf("Internal Error in deletesite(): Try to delete a point");
        printf(" which is an apex on the boundary.\n");
        internalerror();
      }
#endif // defined SELF_CHECK
      equatoredge = (int*) equatoredgelist->alloc();
      equatoredge[0] = equatorpointlist->hasitem(&tdest);
      if (equatoredge[0] == -1) {
        equatorpointlist->append(&tdest);
        equatoredge[0] = equatorpointlist->len() - 1;
      }
      equatoredge[1] = equatorpointlist->hasitem(&tapex);
      if (equatoredge[1] == -1) {
        equatorpointlist->append(&tapex);
        equatoredge[1] = equatorpointlist->len() - 1;
      }
    }
    assert(equatorpointlist->len() > 0);
    assert(equatoredgelist->len() > 0);
    if (verbose > 2) {
      printf("    There are %d points and %d segments at equator.\n",
             equatorpointlist->len(), equatoredgelist->len());
    }

    triangulateioinit(&in);
    triangulateioinit(&out);
    in.numberofpoints = equatorpointlist->len();
    in.pointlist = new REAL[in.numberofpoints * 2];
    in.numberofsegments = equatoredgelist->len();
    in.segmentlist = new int[in.numberofsegments * 2];
    index = 0;
    for (i = 0; i < in.numberofsegments; i ++) {
      equatoredge = (int*) (*equatoredgelist)[i];
      in.segmentlist[index++] = equatoredge[0];
      in.segmentlist[index++] = equatoredge[1];
    }
    // Determine normal, verify closed polygon.
    tdest = *(point3d*)(*equatorpointlist)[in.segmentlist[0]];
    tapex = *(point3d*)(*equatorpointlist)[in.segmentlist[1]];
    Sub3D(tapex, tdest, v0);
    Normalize3D(v0);
    index = 2;
    dsin = 0;
    for (i = 1; iszero(dsin); i++) {
      tdest = *(point3d*)(*equatorpointlist)[in.segmentlist[index++]];
      tapex = *(point3d*)(*equatorpointlist)[in.segmentlist[index++]];
      Sub3D(tapex, tdest, v1);
      Normalize3D(v1);
      Cross3D(v0, v1, norm);
      dsin = Mag3D(norm);
      if (!iszero(dsin)) Scale3D(norm, 1./dsin);
      if (i >= in.numberofsegments) {
        printf("Internal Error in deletesite(): Can't find a normal.\n");
        internalerror();
      }
    }
    // Project onto a plane
    Assign3D(v1, xaxi);
    Cross3D(norm, xaxi, yaxi);
    index = 0;
    for (i = 0; i < in.numberofpoints; i ++) {
      tdest = *(point*)(*equatorpointlist)[i];
      in.pointlist[index++] = Dot3D(tdest, xaxi);
      in.pointlist[index++] = Dot3D(tdest, yaxi);
    }
    // Now create the 2D mesh.
    surfmesh->triangulate(&in, &out, NULL);
    if (surfmesh->triangles.items <= 0) {
      printf("Internal Error in deletesite(): Can't form a surface");
      printf(" triangulation.\n");
      internalerror();
    }
    if (verbose > 2) {
      printf("    Triangulation result: %d triangles.\n",
             surfmesh->triangles.items);
    }
    surfmesh->trianglerestart();
  }

  if (verbose > 2) {
    printf("    Identify the casing faces at north");
  }
  northpointlist = new list("point");
  northcasinglist = new list(sizeof(triface));
  if (bdry2count > 0) {
    if (verbose > 2) {
      printf(" and sourth.\n");
    }
    sourthpointlist = new list("point");
    sourthcasinglist = new list(sizeof(triface));
    for (i = 0; i < incitetlist->len(); i++) {
      testtet = *(triface *)(* incitetlist)[i];
      enextfnextself(testtet);
      tspivot(testtet, testsh);
      torg = org(testtet);
      tdest = dest(testtet);
      tapex = apex(testtet);
      orgori = iorient3d(delorg, deldest, delapex, torg);
      destori = iorient3d(delorg, deldest, delapex, tdest);
      apexori = iorient3d(delorg, deldest, delapex, tapex);
      add2north = 1;
      if (orgori != 0) {
        if (orgori < 0) {
          if (northpointlist->hasitem(&torg) == -1) {
            northpointlist->append(&torg);
          }
        } else {
          if (sourthpointlist->hasitem(&torg) == -1) {
            sourthpointlist->append(&torg);
          }
          add2north = 0;
        }
      }
      if (destori != 0) {
        if (destori < 0) {
          if (northpointlist->hasitem(&tdest) == -1) {
            northpointlist->append(&tdest);
          }
        } else {
          if (sourthpointlist->hasitem(&tdest) == -1) {
            sourthpointlist->append(&tdest);
          }
          add2north = 0;
        }
      }
      if (apexori != 0) {
        if (apexori < 0) {
          if (northpointlist->hasitem(&tapex) == -1) {
            northpointlist->append(&tapex);
          }
        } else {
          if (sourthpointlist->hasitem(&tapex) == -1) {
            sourthpointlist->append(&tapex);
          }
          add2north = 0;
        }
      }
      symself(testtet);
      if (testtet.tet == dummytet) {
        assert (testsh.sh != dummysh);
        maketetrahedron(&testtet);
        setorg(testtet, torg);
        setdest(testtet, tdest);
        setapex(testtet, tapex);
        sesymself(testsh);
        tsbond(testtet, testsh);
        if (verbose > 2) {
          printf("    Creating a fake tet for holding face(%d, %d, %d).\n",
                 pointmark(torg), pointmark(tdest), pointmark(tapex));
        }
      }
      adjustedgering(testtet, CCW);
      if (add2north) {
        if (verbose > 2) {
          printf("    Queuing northcasing face (%d, %d, %d).\n",
                 pointmark(org(testtet)), pointmark(dest(testtet)),
                 pointmark(apex(testtet)));
        }
        northcasinglist->append(&testtet);
      } else {
        if (verbose > 2) {
          printf("    Queuing sourthcasing face (%d, %d, %d).\n",
                 pointmark(org(testtet)), pointmark(dest(testtet)),
                 pointmark(apex(testtet)));
        }
        sourthcasinglist->append(&testtet);
      }
    }
    assert(sourthcasinglist->len() > 0);
    if (verbose > 2) {
      printf("    There are %d points at sourth.\n", sourthpointlist->len());
    }
  } else {
    if (verbose > 2) {
      printf(".\n");
    }
    for (i = 0; i < incitetlist->len(); i++) {
      testtet = *(triface *)(* incitetlist)[i];
      enextfnextself(testtet);
      tspivot(testtet, testsh);
      torg = org(testtet);
      tdest = dest(testtet);
      tapex = apex(testtet);
      if (bdrycount > 0) {
        if (equatorpointlist->hasitem(&torg) == -1) {
          if (northpointlist->hasitem(&torg) == -1) {
            northpointlist->append(&torg);
          }
        }
        if (equatorpointlist->hasitem(&tdest) == -1) {
          if (northpointlist->hasitem(&tdest) == -1) {
            northpointlist->append(&tdest);
          }
        }
        if (equatorpointlist->hasitem(&tapex) == -1) {
          if (northpointlist->hasitem(&tapex) == -1) {
            northpointlist->append(&tapex);
          }
        }
      } else {
        if (northpointlist->hasitem(&torg) == -1) {
          northpointlist->append(&torg);
        }
        if (northpointlist->hasitem(&tdest) == -1) {
          northpointlist->append(&tdest);
        }
        if (northpointlist->hasitem(&tapex) == -1) {
          northpointlist->append(&tapex);
        }
      }
      symself(testtet);
      if (testtet.tet == dummytet) {
        assert (testsh.sh != dummysh);
        maketetrahedron(&testtet);
        setorg(testtet, torg);
        setdest(testtet, tdest);
        setapex(testtet, tapex);
        sesymself(testsh);
        tsbond(testtet, testsh);
        if (verbose > 2) {
          printf("    Creating a fake tet for holding face(%d, %d, %d).\n",
                 pointmark(torg), pointmark(tdest), pointmark(tapex));
        }
      }
      adjustedgering(testtet, CCW);
      if (verbose > 2) {
        printf("    Queuing northcasing face (%d, %d, %d).\n",
               pointmark(org(testtet)), pointmark(dest(testtet)),
               pointmark(apex(testtet)));
      }
      northcasinglist->append(&testtet);
    }
  }
  assert(northcasinglist->len() > 0);
  if (verbose > 2) {
    printf("    There are %d points at north.\n", northpointlist->len());
  }

  if (verbose > 2) {
    printf("    Protecting subsegments process.\n");
  }
  for (i = 0; i < northcasinglist->len(); i++) {
    testtet = *(triface*)(*northcasinglist)[i];
    tspivot(testtet, testsh);
    if (testsh.sh == dummysh) {
      for (j = 0; j < 3; j++) {
        tsspivot(&testtet, &testseg);
        if (testseg.sh != dummysh) {
          if (verbose > 2) {
            printf("    Segment (%d, %d) needs protect.\n",
                   pointmark(sorg(testseg)), pointmark(sdest(testseg)));
          }
          insertsubface(&testtet, NONSOLIDFLAG, 1);
          break;
        }
        enextself(testtet);
      }
    } else {
      // Bond all segments to this subface to ensure
      //   the subsegment-subface bond.
      for (j = 0; j < 3; j++) {
        sspivot(testsh, testseg);
        if (testseg.sh != dummysh) {
          ssbond(testsh, testseg);
        }
        senextself(testsh);
      }
    }
  }
  if (bdry2count > 0) {
    for (i = 0; i < sourthcasinglist->len(); i++) {
      testtet = *(triface*)(*sourthcasinglist)[i];
      tspivot(testtet, testsh);
      if (testsh.sh == dummysh) {
        for (j = 0; j < 3; j++) {
          tsspivot(&testtet, &testseg);
          if (testseg.sh != dummysh) {
            if (verbose > 2) {
              printf("    Segment (%d, %d) needs protect.\n",
                     pointmark(sorg(testseg)), pointmark(sdest(testseg)));
            }
            insertsubface(&testtet, NONSOLIDFLAG, 1);
            break;
          }
          enextself(testtet);
        }
      } else {
        // Bond all segments of to this subface to ensure
        //   the subsegment-subface bond.
        for (j = 0; j < 3; j++) {
          sspivot(testsh, testseg);
          if (testseg.sh != dummysh) {
            ssbond(testsh, testseg);
          }
          senextself(testsh);
        }
      }
    }
  }

  // Keep shellmark for subfaces.
  if ((bdrycount > 0) || (bdry2count > 0)) {
    incish = (face*)(*incishlist)[0];
    shellmark = mark(*incish);
#ifdef SELF_CHECK
    for (i = 1; i < incishlist->len(); i++) {
      incish = (face*)(*incishlist)[i];
      if (shellmark != mark(*incish)) {
        printf("Internal error in deletesite(): \n");
        printf("  Try to delete a point which seems on a subsegment.\n");
        internalerror();
      }
    }
#endif // defined SELF_CHECK
  }

  // Keep attribs and varvolume for new tets.
  if (eextras || varvolume) {
    if (eextras > 0) {
      northattribs = new REAL[eextras];
      if (bdry2count > 0) {
        sourthattribs = new REAL[eextras];
      }
    }
    if (bdry2count > 0) {
      // Find a incident tet which belong to sourth side.
      incish = (face*)(*incishlist)[0];
      // This is sourth side. (Above we use the first shell face as horiz).
      stpivot(*incish, testtet);
#ifdef SELF_CHECK
      assert(isbelowplane(delorg, deldest, delapex, oppo(testtet)));
#endif // defined SELF_CHECK
      for (i = 0; i < eextras; i++) {
        sourthattribs[i] = elemattribute(testtet.tet, i);
      }
      if (varvolume) {
        sourthvolume = volumebound(testtet.tet);
      }
      // Set north side.
      symself(testtet);
      assert(testtet.tet != dummytet);
      for (i = 0; i < eextras; i++) {
        northattribs[i] = elemattribute(testtet.tet, i);
      }
      if (varvolume) {
        northvolume = volumebound(testtet.tet);
      }
    } else {
      incitet = (triface*)(*incitetlist)[0];
      // There only north side.
      for (i = 0; i < eextras; i++) {
        northattribs[i] = elemattribute(incitet->tet, i);
      }
      if (varvolume) {
        northvolume = volumebound(incitet->tet);
      }
    }
  } else {
    northattribs = sourthattribs = NULL;
    northvolume = sourthvolume = 0;
  }

  if ((bdrycount > 0) || (bdry2count > 0)) {
    if (verbose > 2) {
      printf("    Creating casing faces for holding subfaces on equator.\n");
    }
    equatorcasinglist = new list(sizeof(triface));
    tnorth = *(point3d*)(*northpointlist)[0];
    for (i = 0; i < out.numberoftriangles; i++) {
      index = i * 3;
      orgori = out.trianglelist[index++];
      destori = out.trianglelist[index++];
      apexori = out.trianglelist[index++];
      torg = *(point3d*)(*equatorpointlist)[orgori];
      tdest = *(point3d*)(*equatorpointlist)[destori];
      tapex = *(point3d*)(*equatorpointlist)[apexori];
      maketetrahedron(&testtet);
      makeshellface(&subfaces, &testsh);
      setmark(testsh, shellmark);
      add2north = iorient3d(torg, tdest, tapex, tnorth);
      assert(add2north != 0);
      if (add2north < 0) {
        setorg(testtet, tdest);
        setdest(testtet, torg);
        setsorg(testsh, torg);
        setsdest(testsh, tdest);
      } else {
        setorg(testtet, torg);
        setdest(testtet, tdest);
        setsorg(testsh, tdest);
        setsdest(testsh, torg);
      }
      setapex(testtet, tapex);
      setsapex(testsh, tapex);
      tsbond(testtet, testsh);
      if (verbose > 2) {
        printf("    Creating and queuing equator casing face (%d, %d, %d).\n",
               pointmark(org(testtet)), pointmark(dest(testtet)),
               pointmark(apex(testtet)));
        printf("    Creating and bonding equator subface (%d, %d, %d).\n",
               pointmark(sorg(testsh)), pointmark(sdest(testsh)),
               pointmark(sapex(testsh)));
      }
      equatorcasinglist->append(&testtet);
    }
    assert(equatorcasinglist->len() > 0);
  }

  if ((bdrycount > 0) || (bdry2count > 0)) {
    numberofgiftfaces = equatorcasinglist->len() + northcasinglist->len();
    numberofgiftpoints = equatorpointlist->len() + northpointlist->len();
  } else {
    numberofgiftfaces = northcasinglist->len();
    numberofgiftpoints = northpointlist->len();
  }
  giftfaces = new triface[numberofgiftfaces];
  giftpoints = new point3d[numberofgiftpoints];
  // Create a backtrace list to keep all new tets be created during
  //   gift-wrapping stage, so we can delete them if gift-wrapping failed.
  northbacktracelist = new list(sizeof(triface));

  if ((bdrycount > 0) || (bdry2count > 0)) {
    //   Generate giftfaces.
    for (i = 0; i < equatorcasinglist->len(); i++) {
      giftfaces[i] = *(triface*)(*equatorcasinglist)[i];
    }
    for (j = i; j < numberofgiftfaces; j++) {
      giftfaces[j] = *(triface*)(*northcasinglist)[j - i];
    }
    //   Generate giftpoints.
    for (i = 0; i < equatorpointlist->len(); i++) {
      giftpoints[i] = *(point3d*)(*equatorpointlist)[i];
    }
    for (j = i; j < numberofgiftpoints; j++) {
      giftpoints[j] = *(point3d*)(*northpointlist)[j - i];
    }
  } else {
    //   Generate giftfaces.
    for (i = 0; i < numberofgiftfaces; i++) {
      giftfaces[i] = *(triface*)(*northcasinglist)[i];
    }
    //   Generate giftpoints.
    for (i = 0; i < numberofgiftpoints; i++) {
      giftpoints[i] = *(point3d*)(*northpointlist)[i];
    }
  }

  success = giftwrapping(numberofgiftfaces, giftfaces, numberofgiftpoints,
                         giftpoints, northattribs, northvolume,
                         northbacktracelist);

  if ((bdry2count > 0) && success) {
    if (verbose > 2) {
      printf("    Removing and replacing fake tets at equator with real tets.\n");
    }
    for (i = 0; i < equatorcasinglist->len(); i++) {
      incitet = (triface*)(*equatorcasinglist)[i];
      assert(oppo(*incitet) == (point3d) NULL);
      sym(*incitet, testtet);
      tspivot(*incitet, testsh);
      dissolve(testtet);
      stdissolve(testsh);
      // Remove fake tet.
      tetrahedrondealloc(incitet->tet);
      // Replace fake tet with a real tet.
      adjustedgering(testtet, CCW);
      *incitet = testtet;
      if (verbose > 2) {
        printf("    Changing (%d, %d, %d).\n", pointmark(org(testtet)),
               pointmark(dest(testtet)), pointmark(apex(testtet)));
      }
    }
    delete [] giftfaces;
    delete [] giftpoints;

    numberofgiftfaces = equatorcasinglist->len() + sourthcasinglist->len();
    numberofgiftpoints = equatorpointlist->len() + sourthpointlist->len();
    giftfaces = new triface[numberofgiftfaces];
    giftpoints = new point3d[numberofgiftpoints];
    // Create a backtrace list to keep all new tets be created during
    //   gift-wrapping stage, so we can delete them if gift-wrapping failed.
    sourthbacktracelist = new list(sizeof(triface));

    //   Generate giftfaces.
    for (i = 0; i < equatorcasinglist->len(); i++) {
      giftfaces[i] = *(triface*)(*equatorcasinglist)[i];
    }
    for (j = i; j < numberofgiftfaces; j++) {
      giftfaces[j] = *(triface*)(*sourthcasinglist)[j - i];
    }
    //   Generate giftpoints.
    for (i = 0; i < equatorpointlist->len(); i++) {
      giftpoints[i] = *(point3d*)(*equatorpointlist)[i];
    }
    for (j = i; j < numberofgiftpoints; j++) {
      giftpoints[j] = *(point3d*)(*sourthpointlist)[j - i];
    }

    success = giftwrapping(numberofgiftfaces, giftfaces, numberofgiftpoints,
                           giftpoints, sourthattribs, sourthvolume,
                           sourthbacktracelist);
    if (!success) {
      if (verbose > 2) {
        printf("    Badly, gift-wrapping failed, clear all new tets that");
        printf(" created at sourthcasing.\n");
      }
      // Removing new subfaces at equators first. Because after new tets
      //   being removed, subfaces will no holder.
      for (i = 0; i < equatorcasinglist->len(); i++) {
        testtet = *(triface*)(*equatorcasinglist)[i];
        tspivot(testtet, testsh);
        assert(testsh.sh != dummysh);
        shellfacedealloc(&subfaces, testsh.sh);
      }
      // Clear equatorcasinglist to avoid deallocate subfaces twice.
      equatorcasinglist->clear();
      // Dealloc all new tets in which created during gift-wrapping.
      for (i = 0; i < sourthbacktracelist->len(); i++) {
        incitet = (triface*)(*sourthbacktracelist)[i];
        if (verbose > 2) {
          printf("    Deleting new tet (%d, %d, %d, %d).\n",
                 pointmark(org(*incitet)), pointmark(dest(*incitet)),
                 pointmark(apex(*incitet)), pointmark(oppo(*incitet)));
        }
        tetrahedrondealloc(incitet->tet);
      }
    }
  }

  if (!success) {
    if (verbose > 2) {
      printf("    Badly, gift-wrapping failed, clear all new tets that");
      printf(" created during gift-wrapping.\n");
    }
    if ((bdrycount > 0) || (bdry2count > 0)) {
      // Removing new subfaces at equators.
      for (i = 0; i < equatorcasinglist->len(); i++) {
        testtet = *(triface*)(*equatorcasinglist)[i];
        tspivot(testtet, testsh);
        assert(testsh.sh != dummysh);
        shellfacedealloc(&subfaces, testsh.sh);
        // It's a equator casing fake tet, delete it.
        tetrahedrondealloc(testtet.tet);
      }
      equatorcasinglist->clear();
    }
    for (i = 0; i < northbacktracelist->len(); i++) {
      incitet = (triface*)(*northbacktracelist)[i];
      if (verbose > 2) {
        printf("    Deleting new tet (%d, %d, %d, %d).\n",
               pointmark(org(*incitet)), pointmark(dest(*incitet)),
               pointmark(apex(*incitet)), pointmark(oppo(*incitet)));
      }
      tetrahedrondealloc(incitet->tet);
    }
  }

  if (success) {
    if (verbose > 2) {
      printf("    Deleting all incident tets and incident faces.\n");
    }
    for (i = 0; i < incitetlist->len(); i++) {
      incitet = (triface*)(*incitetlist)[i];
      if (verbose > 2) {
        printf("    Deleting tet (%d, %d, %d, %d).\n",
               pointmark(org(*incitet)), pointmark(dest(*incitet)),
               pointmark(apex(*incitet)), pointmark(oppo(*incitet)));
      }
      tspivot(*incitet, testsh);
      if (testsh.sh != dummysh) {
        if (verbose > 2) {
          printf("    Deleting subface (%d, %d, %d).\n",
                 pointmark(sorg(testsh)), pointmark(sdest(testsh)),
                 pointmark(sapex(testsh)));
        }
        sym(*incitet, neighbortet);
        tsdissolve(neighbortet);
        shellfacedealloc(&subfaces, testsh.sh);
      }
      fnext(*incitet, testtet);
      tspivot(testtet, testsh);
      if (testsh.sh != dummysh) {
        if (verbose > 2) {
          printf("    Deleting subface (%d, %d, %d).\n",
                 pointmark(sorg(testsh)), pointmark(sdest(testsh)),
                 pointmark(sapex(testsh)));
        }
        sym(testtet, neighbortet);
        tsdissolve(neighbortet);
        shellfacedealloc(&subfaces, testsh.sh);
      }
      enext2(*incitet, testtet);
      fnextself(testtet);
      tspivot(testtet, testsh);
      if (testsh.sh != dummysh) {
        if (verbose > 2) {
          printf("    Deleting subface (%d, %d, %d).\n",
                 pointmark(sorg(testsh)), pointmark(sdest(testsh)),
                 pointmark(sapex(testsh)));
        }
        sym(testtet, neighbortet);
        tsdissolve(neighbortet);
        shellfacedealloc(&subfaces, testsh.sh);
      }
      tetrahedrondealloc(incitet->tet);
    }

    // Now we can delete the point.
    pointdealloc(delorg);
    if (bdrycount > 0) {
      // Deleting the boundary point decreases the number of boundary faces.
      hullsize -= 2;
    }
  } else {
    // Gift-wrapping failed, we need restore original configuration.
    //   This time, all tets in 'incitetlist' are still keep the pointers
    //   to its casing face, use this pointers to restore original config-
    //   uration.
    if (verbose > 2) {
      printf("    Fail to delete point, restoring original configuration.\n");
    }
    for (i = 0; i < incitetlist->len(); i++) {
      incitet = (triface*)(*incitetlist)[i];
      enextfnextself(*incitet);
      // Get and bond its casing face if its not a 'dummytet'.
      sym(*incitet, testtet);
      if (testtet.tet != dummytet) {
        bond(*incitet, testtet);
      }
      // Get and bond the subface if its not a 'dummysh'.
      tspivot(*incitet, testsh);
      if (testsh.sh != dummysh) {
        tsbond(*incitet, testsh);;
      }
    }
  }

  // Whatever success or not success, we must do the following step.
  if (verbose > 2) {
    printf("    Removing and replacing fake tets in north with dummytet.\n");
  }
  for (i = 0; i < northcasinglist->len(); i++) {
    testtet = *(triface*)(*northcasinglist)[i];
    if (oppo(testtet) == (point3d) NULL) {
      if (verbose > 2) {
        printf("    Changing (%d, %d, %d).\n", pointmark(org(testtet)),
               pointmark(dest(testtet)), pointmark(apex(testtet)));
      }
      if (success) {
        // Here do dissolve only success == 1.
        sym(testtet, neighbortet);
        dissolve(neighbortet);
      }
      tspivot(testtet, testsh);
      if (testsh.sh != dummysh) {
        stdissolve(testsh);
      }
      tetrahedrondealloc(testtet.tet);
      testtet = neighbortet;
      if (shflaws && success) {
        uncheckedshlist->append(&testsh);
      }
    }
    // Ensure adjoining tets quality at casing face.
    if (tetflaws && success) {
      uncheckedtetlist->append(&testtet);
      sym(testtet, neighbortet);
      if (neighbortet.tet != dummytet) {
        uncheckedtetlist->append(&neighbortet);
      }
    }
  }

  if (bdry2count > 0) {
    if (verbose > 2) {
      printf("    Removing and replacing fake tets in sourth with dummytet.\n");
    }
    for (i = 0; i < sourthcasinglist->len(); i++) {
      testtet = *(triface*)(*sourthcasinglist)[i];
      if (oppo(testtet) == (point3d) NULL) {
        // This is a fake tet, delete it and set it be 'dummytet'.
        if (verbose > 2) {
          printf("    Changing (%d, %d, %d).\n",
                 pointmark(org(testtet)), pointmark(dest(testtet)),
                 pointmark(apex(testtet)));
        }
        if (success) {
          // Here do dissolve only success == 1.
          sym(testtet, neighbortet);
          dissolve(neighbortet);
        }
        tspivot(testtet, testsh);
        if (testsh.sh != dummysh) {
          stdissolve(testsh);
        }
        tetrahedrondealloc(testtet.tet);
        testtet = neighbortet;
        if (shflaws && success) {
          uncheckedshlist->append(&testsh);
        }
      }
      // Ensure adjoining tets quality at casing face.
      if (tetflaws && success) {
        uncheckedtetlist->append(&testtet);
        sym(testtet, neighbortet);
        if (neighbortet.tet != dummytet) {
          uncheckedtetlist->append(&neighbortet);
        }
      }
    }
  }

  if ((bdrycount > 0) || (bdry2count > 0)) {
    if (verbose > 2) {
      printf("    Bonding subsegments to equator subfaces.\n");
    }
    for (i = 0; i < equatorcasinglist->len(); i++) {
      testtet = *(triface*)(*equatorcasinglist)[i];
      tspivot(testtet, testsh);
      // For keep the same enext() direction.
      findversion(&testsh, org(testtet), dest(testtet), 0);
      for (j = 0; j < 3; j++) {
        tsspivot(&testtet, &testseg);
        if (testseg.sh != dummysh) {
          ssbond(testsh, testseg);
        }
        enextself(testtet);
        senextself(testsh);
      }
      // Check quality if need.
      if (shflaws && success) {
        uncheckedshlist->append(&testsh);
      }
      if (bdry2count == 0) {
        // Remove and replacing fake tet at equator with 'dummytet'.
        sym(testtet, neighbortet);
        dissolve(neighbortet);
        tspivot(testtet, testsh);
        if (testsh.sh != dummysh) {
          stdissolve(testsh);
        }
        tetrahedrondealloc(testtet.tet);
        testtet = neighbortet;
      }
      if (tetflaws && success) {
        uncheckedtetlist->append(&testtet);
        if (bdry2count > 0) {
          symself(testtet);
          uncheckedtetlist->append(&testtet);
        }
      }
    }
  }

  if (!success && docheck) {
    checkmesh();
    checkshells();
  }

  delete [] giftfaces;
  delete [] giftpoints;
  delete incitetlist;
  delete incishlist;
  delete northpointlist;
  delete northcasinglist;
  delete northbacktracelist;
  if ((bdrycount > 0) || (bdry2count > 0)) {
    delete equatorpointlist;
    delete equatoredgelist;
    delete equatorcasinglist;
    if (bdry2count > 0) {
      delete sourthpointlist;
      delete sourthcasinglist;
      delete sourthbacktracelist;
    }
  }
  if (eextras) {
    delete [] northattribs;
    if (bdry2count > 0) {
      delete [] sourthattribs;
    }
  }
  return success;
}

///////////////////////////////////////////////////////////////////////////////
// END                                                                       //
// Insert/Delete point routines                                              //
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Giftwrapping Algorithm Implementation                                     //
// BEGIN                                                                     //
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Using gift-wrapping algorithm to construct a constrained Delaunay         //
// triangulation for input triangular faces bounded polyhedras.              //
//                                                                           //
//   Gift-wrapping (also called pivoting or incremental search) algorithm    //
// can be used to solve Convex Hull(CH) problem, construct Delaunay Triangu- //
// lation(DT) and Constrained Delaunay Triangulation(CDT) in d-dimension.    //
//                                                                           //
//   To construct three-dimensional CDT, gift-wrapping begins by finding a   //
// single constrained Delaunay tetrahedron, upon which the remaining         //
// Delaunay tetrahedras crystallize one by one. Say that a constraining      //
// triangluar face of a Delaunay tetrahedron is UNFINISHED if the algorithm  //
// has not yet identified the other Delaunay tetrahedron that shares the     //
// face. To finish a face is to find the other tetrahedron, one must test    //
// the visibility of each vertex from that face, If the face lies in the     //
// boundary of the input, the face becomes finished when the algorithm       //
// recognizes that there is no other adjoining tetrahedron.                  //
//                                                                           //
//   Generally, the running time for constructing a CDT using gift-wrapping  //
// is O(nv*nf*ns), where nv is the number of input vertexs, nf is the number //
// of constraining triangluar face and ns is the number of final tetrahedra. //
// There have many variant implementations of this algorithm to improve the  //
// poor time complexity of general gift-wrapping. Although in practice, gift //
// -wrapping is not very suitable for constructing CDT. But if the vertexs'  //
// and constraining faces number are tipically small, the performance of the //
// algorithm used is not critical, our improved implementation of gift-      //
// wrapping will suffice.                                                    //
//                                                                           //
//   The main idea in achieving an optimal result of gift-wrapping algorithm //
// is that of eliminating redundant computations. Observe for each           //
// UNFINISHED face, we must find a best visible vertex that can form a       //
// constrained Delaunay tetrahedron with this face. For each visible vertex,  //
// we need check all other constraining faces to see if they are obstructed  //
// the visibility of vertex from the face. If we have known some of these    //
// constraining faces can not obstructed the visibility of vertex in advance,//
// we could have same time not to compute them.                              //
//                                                                           //
//   For this purpose, I use a Weighted-Vertex approach, which is widely     //
// used in variety of graph algorithms, to help us determine whether a face  //
// can be safely skipped. At first each vertex's weight is the number of     //
// edges connected at this vertex. So all vertex's weight must great or      //
// equal than 3. During the procedure of gift-wrapping, the weight of vertex //
// will decrease 1 when an UNFINISHED face(contains this vertex) becaomes    //
// finished, and increase 1 when a new UNFINISHED face(contains this vertex) //
// be generated. Then, if a face contains a vertex with Zero-weight, it      //
// means the face has already been finished, so it has no chance to obstruct //
// other vertex(Remember the meaning of CDT), we can saftly skip this face   //
// in later computing. The weight of vertex also can help us in chossing a   //
// best face to start and chossing a best vertex when there exist more than  //
// one visible vertexs. Please see the functions getgiftface() and           //
// getgiftpoint() for a detail description.                                  //
//                                                                           //
//   At last, there need do a lot of triangle-triangle intersection tests in //
// finding a best vertex to finish a face. I use the codes of Tomas Moller   //
// directly to do the tests, see below.                                      //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Triangle/triangle intersection test routine, by Tomas Moller.             //
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Triangle/triangle intersection test routine,                              //
// by Tomas Moller, 1997.                                                    //
// See article "A Fast Triangle-Triangle Intersection Test",                 //
// Journal of Graphics Tools, 2(2), 1997                                     //
//                                                                           //
// int tri_tri_intersect(REAL V0[3], REAL V1[3], REAL V2[3],                 //
//                       REAL U0[3], REAL U1[3], REAL U2[3])                 //
//                                                                           //
// parameters: vertices of triangle 1: V0,V1,V2                              //
//             vertices of triangle 2: U0,U1,U2                              //
// result    : returns 1 if the triangles intersect, otherwise 0             //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// fuzzycomp_interval()    Compare two floating-point values dx and dy.      //
//                                                                           //
// Return +1 if dx > dy; Return -1 if dx < dy; Return  0 if dx == dy.        //
//                                                                           //
// Si hang added this function for compare intervals. July, 2001.            //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

int fuzzycomp_interval(REAL dA, REAL dB)
{
  REAL dSum, dDiff;
  REAL dTol = 5.e-9;
  REAL dFloor = 1.e-6;

  dSum  = fabs(dA) + fabs(dB);
  dDiff = dA - dB;
  dSum = (dSum > dFloor) ? dSum : dFloor;
  if (dDiff > dTol * dSum) return 1;
  else if (dDiff < - dTol * dSum) return -1;
  else return 0;
}

// if USE_EPSILON_TEST is true then we do a check:
//   if |dv|<EPSILON then dv=0.0;
// else no check is done (which is less robust)

#define USE_EPSILON_TEST TRUE
#define EPSILON 1e-7

// some macros
#define CROSS(dest,v1,v2)                                                  \
  dest[0]=v1[1]*v2[2]-v1[2]*v2[1];                                         \
  dest[1]=v1[2]*v2[0]-v1[0]*v2[2];                                         \
  dest[2]=v1[0]*v2[1]-v1[1]*v2[0];

#define DOT(v1,v2) (v1[0]*v2[0]+v1[1]*v2[1]+v1[2]*v2[2])

#define SUB(dest,v1,v2)                                                    \
  dest[0]=v1[0]-v2[0];                                                     \
  dest[1]=v1[1]-v2[1];                                                     \
  dest[2]=v1[2]-v2[2];

// sort so that a<=b
#define SORT(a,b)                                                          \
  if(a>b) {                                                                \
    REAL c;                                                                \
    c=a; a=b; b=c;                                                         \
  }

#define ISECT(VV0,VV1,VV2,D0,D1,D2,isect0,isect1)                          \
  isect0=VV0+(VV1-VV0)*D0/(D0-D1);                                         \
  isect1=VV0+(VV2-VV0)*D0/(D0-D2);

#define COMPUTE_INTERVALS(VV0,VV1,VV2,D0,D1,D2,D0D1,D0D2,isect0,isect1)    \
  if(D0D1>0.0f)                                                            \
  {                                                                        \
    /* here we know that D0D2<=0.0 */                                      \
/* that is D0, D1 are on the same side, D2 on the other or on the plane */ \
    ISECT(VV2,VV0,VV1,D2,D0,D1,isect0,isect1);                             \
  }                                                                        \
  else if(D0D2>0.0f)                                                       \
  {                                                                        \
    /* here we know that d0d1<=0.0 */                                      \
    ISECT(VV1,VV0,VV2,D1,D0,D2,isect0,isect1);                             \
  }                                                                        \
  else if(D1*D2>0.0f || D0!=0.0f)                                          \
  {                                                                        \
    /* here we know that d0d1<=0.0 or that D0!=0.0 */                      \
    ISECT(VV0,VV1,VV2,D0,D1,D2,isect0,isect1);                             \
  }                                                                        \
  else if(D1!=0.0f)                                                        \
  {                                                                        \
    ISECT(VV1,VV0,VV2,D1,D0,D2,isect0,isect1);                             \
  }                                                                        \
  else if(D2!=0.0f)                                                        \
  {                                                                        \
    ISECT(VV2,VV0,VV1,D2,D0,D1,isect0,isect1);                             \
  }                                                                        \
  else                                                                     \
  {                                                                        \
    /* triangles are coplanar */                                           \
    return coplanar_tri_tri(N1,V0,V1,V2,U0,U1,U2);                         \
  }

// this edge to edge test is based on Franlin Antonio's gem:
//   "Faster Line Segment Intersection", in Graphics Gems III,
//   pp. 199-202
#define EDGE_EDGE_TEST(V0,U0,U1)                                           \
  Bx=U0[i0]-U1[i0];                                                        \
  By=U0[i1]-U1[i1];                                                        \
  Cx=V0[i0]-U0[i0];                                                        \
  Cy=V0[i1]-U0[i1];                                                        \
  f=Ay*Bx-Ax*By;                                                           \
  d=By*Cx-Bx*Cy;                                                           \
  if((f>0 && d>=0 && d<=f) || (f<0 && d<=0 && d>=f))                       \
  {                                                                        \
    e=Ax*Cy-Ay*Cx;                                                         \
    if(f>0)                                                                \
    {                                                                      \
      if(e>=0 && e<=f) return 1;                                           \
    }                                                                      \
    else                                                                   \
    {                                                                      \
      if(e<=0 && e>=f) return 1;                                           \
    }                                                                      \
  }

#define EDGE_AGAINST_TRI_EDGES(V0,V1,U0,U1,U2)                             \
{                                                                          \
  REAL Ax,Ay,Bx,By,Cx,Cy,e,d,f;                                            \
  Ax=V1[i0]-V0[i0];                                                        \
  Ay=V1[i1]-V0[i1];                                                        \
  /* test edge U0,U1 against V0,V1 */                                      \
  EDGE_EDGE_TEST(V0,U0,U1);                                                \
  /* test edge U1,U2 against V0,V1 */                                      \
  EDGE_EDGE_TEST(V0,U1,U2);                                                \
  /* test edge U2,U1 against V0,V1 */                                      \
  EDGE_EDGE_TEST(V0,U2,U0);                                                \
}

#define POINT_IN_TRI(V0,U0,U1,U2)                                          \
{                                                                          \
  REAL a,b,c,d0,d1,d2;                                                     \
  /* is T1 completly inside T2? */                                         \
  /* check if V0 is inside tri(U0,U1,U2) */                                \
  a=U1[i1]-U0[i1];                                                         \
  b=-(U1[i0]-U0[i0]);                                                      \
  c=-a*U0[i0]-b*U0[i1];                                                    \
  d0=a*V0[i0]+b*V0[i1]+c;                                                  \
                                                                           \
  a=U2[i1]-U1[i1];                                                         \
  b=-(U2[i0]-U1[i0]);                                                      \
  c=-a*U1[i0]-b*U1[i1];                                                    \
  d1=a*V0[i0]+b*V0[i1]+c;                                                  \
                                                                           \
  a=U0[i1]-U2[i1];                                                         \
  b=-(U0[i0]-U2[i0]);                                                      \
  c=-a*U2[i0]-b*U2[i1];                                                    \
  d2=a*V0[i0]+b*V0[i1]+c;                                                  \
  if(d0*d1>0.0)                                                            \
  {                                                                        \
    if(d0*d2>0.0) return 1;                                                \
  }                                                                        \
}

int coplanar_tri_tri(const REAL N[3],
                     const REAL V0[3],const REAL V1[3],const REAL V2[3],
                     const REAL U0[3],const REAL U1[3],const REAL U2[3])
{
   REAL A[3];
   short i0,i1;
   // first project onto an axis-aligned plane, that maximizes the area
   //   of the triangles, compute indices: i0,i1.
   A[0]=fabs(N[0]);
   A[1]=fabs(N[1]);
   A[2]=fabs(N[2]);
   if(A[0]>A[1])
   {
      if(A[0]>A[2])
      {
          i0=1;      // A[0] is greatest
          i1=2;
      }
      else
      {
          i0=0;      // A[2] is greatest
          i1=1;
      }
   }
   else   // A[0]<=A[1]
   {
      if(A[2]>A[1])
      {
          i0=0;      // A[2] is greatest
          i1=1;
      }
      else
      {
          i0=0;      // A[1] is greatest
          i1=2;
      }
    }

    // test all edges of triangle 1 against the edges of triangle 2
    EDGE_AGAINST_TRI_EDGES(V0,V1,U0,U1,U2);
    EDGE_AGAINST_TRI_EDGES(V1,V2,U0,U1,U2);
    EDGE_AGAINST_TRI_EDGES(V2,V0,U0,U1,U2);

    // finally, test if tri1 is totally contained in tri2 or vice versa
    POINT_IN_TRI(V0,U0,U1,U2);
    POINT_IN_TRI(U0,V0,V1,V2);

    return 0;
}


int tri_tri_intersect(const REAL V0[3], const REAL V1[3], const REAL V2[3],
                      const REAL U0[3], const REAL U1[3], const REAL U2[3])
{
  REAL E1[3],E2[3];
  REAL N1[3],N2[3],d1,d2;
  REAL du0,du1,du2,dv0,dv1,dv2;
  REAL D[3];
  REAL isect1[2], isect2[2];
  REAL du0du1,du0du2,dv0dv1,dv0dv2;
  short index;
  REAL vp0,vp1,vp2;
  REAL up0,up1,up2;
  REAL b,c,max;

  // compute plane equation of triangle(V0,V1,V2)
  SUB(E1,V1,V0);
  SUB(E2,V2,V0);
  CROSS(N1,E1,E2);
  d1=-DOT(N1,V0);
  // plane equation 1: N1.X+d1=0

  // put U0,U1,U2 into plane equation 1 to compute signed distances to
  //   the plane
  du0=DOT(N1,U0)+d1;
  du1=DOT(N1,U1)+d1;
  du2=DOT(N1,U2)+d1;

  // coplanarity robustness check
#if USE_EPSILON_TEST==TRUE
  if(fabs(du0)<EPSILON) du0=0.0;
  if(fabs(du1)<EPSILON) du1=0.0;
  if(fabs(du2)<EPSILON) du2=0.0;
#endif
  du0du1=du0*du1;
  du0du2=du0*du2;

  if(du0du1>0.0f && du0du2>0.0f) // same sign on all of them + not equal 0 ?
    return 0;                    // no intersection occurs

  // compute plane of triangle (U0,U1,U2)
  SUB(E1,U1,U0);
  SUB(E2,U2,U0);
  CROSS(N2,E1,E2);
  d2=-DOT(N2,U0);
  // plane equation 2: N2.X+d2=0

  // put V0,V1,V2 into plane equation 2
  dv0=DOT(N2,V0)+d2;
  dv1=DOT(N2,V1)+d2;
  dv2=DOT(N2,V2)+d2;

#if USE_EPSILON_TEST==TRUE
  if(fabs(dv0)<EPSILON) dv0=0.0;
  if(fabs(dv1)<EPSILON) dv1=0.0;
  if(fabs(dv2)<EPSILON) dv2=0.0;
#endif

  dv0dv1=dv0*dv1;
  dv0dv2=dv0*dv2;

  if(dv0dv1>0.0f && dv0dv2>0.0f) // same sign on all of them + not equal 0 ?
    return 0;                    // no intersection occurs

  // compute direction of intersection line
  CROSS(D,N1,N2);

  // compute and index to the largest component of D
  max=fabs(D[0]);
  index=0;
  b=fabs(D[1]);
  c=fabs(D[2]);
  if(b>max) max=b,index=1;
  if(c>max) max=c,index=2;

  // this is the simplified projection onto L
  vp0=V0[index];
  vp1=V1[index];
  vp2=V2[index];

  up0=U0[index];
  up1=U1[index];
  up2=U2[index];

  // compute interval for triangle 1
  COMPUTE_INTERVALS(vp0,vp1,vp2,dv0,dv1,dv2,dv0dv1,dv0dv2,isect1[0],isect1[1]);

  // compute interval for triangle 2
  COMPUTE_INTERVALS(up0,up1,up2,du0,du1,du2,du0du1,du0du2,isect2[0],isect2[1]);

  SORT(isect1[0],isect1[1]);
  SORT(isect2[0],isect2[1]);

  // Origin code,
  // if(isect1[1]<isect2[0] || isect2[1]<isect1[0]) return 0;
  // New code, changed by Si hang
  if ((fuzzycomp_interval(isect1[1], isect2[0]) == -1) ||
      (fuzzycomp_interval(isect2[1], isect1[0]) == -1)) return 0;
  return 1;
}

///////////////////////////////////////////////////////////////////////////////
// Triangle/triangle intersection test routine, by Tomas Moller.             //
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// struct giftface                                                           //
//                                                                           //
// A struct used to store a face for giftwrapping algorithm to construct     //
// constrained Delaunay tetrahedralization. Where 'casing' is a handle of    //
// unfinished face, and 'iorg', 'idest' and 'iapex' are vertex index in      //
// pointweightlist. Use these values to get weights value for each vertices  //
// of this giftface.                                                         //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

typedef struct giftfacetype {
  triface casing;
  int iorg, idest, iapex;
} giftface;

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// dumpgifts()    Debug routine. Write current gift faces and gift points    //
//                infomation to file.                                        //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::dumpgifts(char *gfile, list *giftfacelist, int numberofgiftpoints,
                       point3d *giftpoints, int *pointweightlist)
{
  FILE *outfile;
  giftface *gfaceptr;
  int i;

  outfile = fopen(gfile, "w");
  if (outfile == (FILE *) NULL) {
    printf("  Error:  Cannot create file %s.\n", gfile);
    return;
  }
  if (!quiet) {
    printf("Writing %s.\n", gfile);
  }
  if (verbose < 1) {
    numbernodes(1);
  }
  fprintf(outfile, "# Dumpping %d giftfaces.\n", giftfacelist->len());
  for (i = 0; i < giftfacelist->len(); i++) {
    gfaceptr = (giftface*)(*giftfacelist)[i];
    fprintf(outfile, "%4d %4d %4d %4d  index %3d %3d %3d.\n", i,
            pointmark(org(gfaceptr->casing)),
            pointmark(dest(gfaceptr->casing)),
            pointmark(apex(gfaceptr->casing)),
            gfaceptr->iorg, gfaceptr->idest, gfaceptr->iapex);
  }
  fprintf(outfile, "# Dumpping %d giftpoints.\n", numberofgiftpoints);
  for (i = 0; i < numberofgiftpoints; i++) {
    fprintf(outfile, "%4d %4d %10.8g %10.8g %10.8g weight %4d.\n", i,
            pointmark(giftpoints[i]), giftpoints[i][0], giftpoints[i][1],
            giftpoints[i][2], pointweightlist[i]);
  }
  fclose(outfile);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// is_face_tet_inter_0()     Check if input face is intersecting with input  //
//                           tetrahedron(given by its four vertexs). There   //
//                           no shared points between face and tetrahedron.  //
//                                                                           //
// Take each faces of tetrahedron and do triangle-triangle intersection test //
// with the input face. They are intersected if one of face pairs are inter- //
// secting. If all face pairs are not intersecting, we still need to check   //
// if the face is fully in the tetrahedron.                                  //
//                                                                           //
// Return 1 if they are intersecting each other. Otherwise, return zero.     //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

int mesh3d::is_face_tet_inter_0(triface *checkface, point3d torg, point3d tdest,
                                point3d tapex, point3d toppo)
{
  point3d forg, fdest, fapex;
  int intersect;
  int i;

  org (*checkface, forg);
  dest(*checkface, fdest);
  apex(*checkface, fapex);

  intersect = 0;
  for (i = 0; i < 4; i++) {
    if (i == 0) {
      // 'checkface' must not intersect with base face. Remember, they are
      //    both the input constraining faces.
      // intersect = tri_tri_intersect(forg, fdest, fapex, torg, tdest, tapex);
    } else if (i == 1) {
      intersect = tri_tri_intersect(forg, fdest, fapex, torg, tdest, toppo);
    } else if (i == 2) {
      intersect = tri_tri_intersect(forg, fdest, fapex, tdest, tapex, toppo);
    } else if (i == 3) {
      intersect = tri_tri_intersect(forg, fdest, fapex, tapex, torg, toppo);
    }
    if (intersect) {
      return 1;
    }
  }
  // Check the face is located in the tetrahedron. That is to check each
  //   vertex of face is located in tetrahedron. Because no face pair is
  //   intersecting(above step guarantee this) and not exists share point.
  //   We only need check one vertex, choose aribitarily.
  enum locateresult loc = isintet(torg, tdest, tapex, toppo, forg);
  // There only two cases (in or out) can be happened.
  if ((intersect != OUTSIDE) && (intersect != INTETRAHEDRON)) {
    printf("Internal error in is_face_tet_inter_0(): \n");
    printf("  Invalid isintet() return value: %i. \n", intersect);
    printf("  (0 = coplanar, 1 = on vertex, 2 = on edge, 3 = on face.)\n");
    internalerror();
  }
  intersect = (loc == OUTSIDE) ? 0 : 1;
  return intersect;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// is_face_tet_inter_1()     Check if input face is intersecting with input  //
//                           tetrahedron(given by its four vertexs). There 1 //
//                           share points between face and tetrahedron.      //
//                                                                           //
// Here we can reuse is_face_tet_inter_0(). But before use it we must detach //
// the share point between face and tetrahedron.                             //
//                                                                           //
// Return 1 if they are intersecting each other. Otherwise, return zero.     //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

int mesh3d::is_face_tet_inter_1(triface *checkface, point3d torg, point3d tdest,
                                point3d tapex, point3d toppo)
{
  point3d forg, fdest, fapex;
  REAL tmpforg[3], center[3];
  int oldversion, intersect;
  int i;

  // We will change the checkface's version. So we must restore it after
  //   checking, otherwise, the index fields in each giftface will invalid.
  oldversion = checkface->ver;
  // First set the share vertex be origin of checkface.
  for (i = 0; i < 3; i++) {
    org(*checkface, forg);
    if ((forg == torg) || (forg == tdest) ||
        (forg == tapex) || (forg == toppo)) {
      dest(*checkface, fdest);
      apex(*checkface, fapex);
      break;
    }
    enextself(*checkface);
  }
  assert(i < 3);

  center[0] = 0.5 * (fdest[0] + fapex[0]);
  center[1] = 0.5 * (fdest[1] + fapex[1]);
  center[2] = 0.5 * (fdest[2] + fapex[2]);

  tmpforg[0] = 0.5 * (forg[0] + center[0]);
  tmpforg[1] = 0.5 * (forg[1] + center[1]);
  tmpforg[2] = 0.5 * (forg[2] + center[2]);

  setorg(*checkface, tmpforg);
  intersect = is_face_tet_inter_0(checkface, torg, tdest, tapex, toppo);
  setorg(*checkface, forg);
  checkface->ver = oldversion;

  return intersect;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// is_face_tet_inter_2()     Check if input face is intersecting with input  //
//                           tetrahedron(given by its four vertexs). There 2 //
//                           share points between face and tetrahedron.      //
//                                                                           //
// The algorithm:                                                            //
//                                                                           //
// Set the face be f, two share point be org, dest. The other point in face  //
//   be apex, The other two points in tetrahedron be v0, v1.                 //
// Take f as reference plane. Check spatial relation between f and v0, v1.   //
// IF (v0 and v1 are locating at the same side to f) THEN                    //
//   return No intersecyion;                                                 //
// ELSE IF (v0 and v1 are locating at diffrent side to f) THEN               //
//   Take a face f' in tetrahedron which contain v0 but not contain v1 as    //
//     reference plane. Check spatial relation between f' and apex, v1.      //
//   IF (apex and v1 are loacting at the same side of f') THEN               //
//     return Intersection;                                                  //
//   ELSE                                                                    //
//     return No intersection;                                               //
//   END                                                                     //
// ELSE IF (v0 or v1 is coplanar with f) THEN                                //
//   IF (v0 is coplanar with f) THEN                                         //
//     Take apex face f' in tetrahedron which contain v1 but not conatin v0  //
//       as reference plane. Check spatial relation between f' and apex, v0. //
//     IF (apex and v0 are loacting at the same side of f') THEN             //
//       return Intersection;                                                //
//     ELSE                                                                  //
//       return No intersection;                                             //
//     END                                                                   //
//   ELSE                                                                    //
//     (v1 is coplanar with f)                                               //
//     Take apex face f' in tetrahedron which contain v0 but not conatin v1  //
//       as reference plane. Check spatial relation between f' and apex, v1. //
//     IF (apex and v1 are loacting at the same side of f') THEN             //
//       return Intersection;                                                //
//     ELSE                                                                  //
//       return No intersection;                                             //
//     END                                                                   //
//   END                                                                     //
// ELSE                                                                      //
//   (both v0 and v1 are coplanar with f)                                    //
//   Impossible case. Throw;                                                 //
// END                                                                       //
//                                                                           //
// Return 1 if they are intersecting each other. Otherwise, return zero.     //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

int mesh3d::is_face_tet_inter_2(triface *checkface, point3d torg, point3d tdest,
                                point3d tapex, point3d toppo)
{
  point3d forg, fdest, fapex, v0, v1;
  int iori1, iori2, iori3, iori4;
  int oldversion, intersect;
  int i;

  // We will change the checkface's version. So we must restore it after
  //   checking, otherwise, the index fields in each giftface will invalid.
  oldversion = checkface->ver;
  // Get forg, fdest, fapex.
  for (i = 0; i < 3; i++) {
    org(*checkface, forg);
    dest(*checkface, fdest);
    if (((forg == torg) || (forg == tdest) ||
         (forg == tapex) || (forg == toppo)) &&
        ((fdest == torg) || (fdest == tdest) ||
         (fdest == tapex) || (fdest == toppo))) {
      apex(*checkface, fapex);
      break;
    }
    enextself(*checkface);
  }
  assert(i < 3);

  // Get v0, v1.
  if ((torg == forg) || (torg == fdest)) {
    if ((tdest == forg) || (tdest == fdest)) {
      v0 = tapex; v1 = toppo;
    } else if ((tapex == forg) || (tapex == fdest)) {
      v0 = tdest; v1 = toppo;
    } else {
      assert((toppo == forg) || (toppo == fdest));
      v0 = tdest; v1 = tapex;
    }
  } else {
    v0 = torg;
    if ((tdest == forg) || (tdest == fdest)) {
      if ((tapex == forg) || (tapex == fdest)) {
        v1 = toppo;
      } else {
        assert((toppo == forg) || (toppo == fdest));
        v1 = tapex;
      }
    } else {
      assert((tapex == forg) || (tapex == fdest));
      assert((toppo == forg) || (toppo == fdest));
      v1 = tdest;
    }
  }
  assert((v0 != forg) && (v0 != fdest));
  assert((v1 != forg) && (v1 != fdest));

  iori1 = iorient3d(forg, fdest, fapex, v0);
  iori2 = iorient3d(forg, fdest, fapex, v1);
  if (iori1 * iori2 != 0) {
    // No coplanar case.
    if (iori1 == iori2) {
      intersect = 0;  // No intersection.
    } else {
      iori3 = iorient3d(forg, fdest, v0, fapex);
      iori4 = iorient3d(forg, fdest, v0, v1);
      assert(iori3 * iori4 != 0);
      if (iori3 != iori4) {
        intersect = 0;  // No intersection.
      } else {
        intersect = 1;  // Intersection.
      }
    }
  } else {
    // v0, or v1 is coplanar with face.
    if (iori1 == 0) {
      assert(iori2 != 0);
      // v0 is coplanar with face, choose v1.
      iori3 = iorient3d(forg, fdest, v1, v0);
      iori4 = iorient3d(forg, fdest, v1, fapex);
    } else {
      assert(iori1 != 0);
      // v1 is coplanar with face, choose v0.
      iori3 = iorient3d(forg, fdest, v0, v1);
      iori4 = iorient3d(forg, fdest, v0, fapex);
    }
    assert(iori3 * iori4 != 0);
    if (iori3 != iori4) {
      intersect = 0;  // No intersection.
    } else {
      intersect = 1;  // Intersection.
    }
  }

  checkface->ver = oldversion;
  return intersect;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// getgiftface()    Search for a face that most suitable for finishing.      //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

int mesh3d::getgiftface(list *giftfacelist, int numberofgiftpoints,
                        int *pointweightlist, list *smallweightlist)
{
  giftface *gfaceptr;
  int smallestweight, smallestindex;
  int gpointindex, giftfaceweight;
  int i, j, index;

  // First find the smallest weight and index in giftpoint array.
  smallestweight = 1000;
  smallestindex = -1;
  for (i = 0; i < numberofgiftpoints; i++) {
    // We only need consider the unfinished giftpoint.
    if (pointweightlist[i] == 0) continue;
    if (pointweightlist[i] < smallestweight) {
      smallestweight = pointweightlist[i];
      smallestindex = i;
    }
  }
  assert(smallestindex != -1);

  if (smallestweight == 3) {
    for (i = 0; i < giftfacelist->len(); i++) {
      gfaceptr = (giftface*) (*giftfacelist)[i];
      if ((pointweightlist[gfaceptr->iorg] == 3)
          || (pointweightlist[gfaceptr->idest] == 3)
          || (pointweightlist[gfaceptr->iapex] == 3)) {
        break;
      }
    }
    assert(i < giftfacelist->len());
    return i;
  } else {
    // For there might exist more than one points have the same smallest
    //   weight, I use a list to keep all these points.
    smallweightlist = new list("int");
    smallweightlist->append(&smallestindex);
    for (i = smallestindex + 1; i < numberofgiftpoints; i++) {
      if (pointweightlist[i] == smallestweight) {
        smallweightlist->append(&i);
      }
    }
    // Find the most suit giftface. Get each point index from
    //   'smallweightlist', then find in giftface array. If a giftface
    //   contain this point, then sum its weight of three point. Get a
    //   giftface which have the smallest sum of weight.
    smallestweight = 1000;
    smallestindex = -1;
    for (i = 0; i < smallweightlist->len(); i++) {
      gpointindex = *(int*)(*smallweightlist)[i];
      for (j = 0; j < giftfacelist->len(); j++) {
        gfaceptr = (giftface*) (*giftfacelist)[j];
        if ((gfaceptr->iorg == gpointindex) ||
            (gfaceptr->idest == gpointindex) ||
            (gfaceptr->iapex == gpointindex)) {
          giftfaceweight = pointweightlist[gfaceptr->iorg]
                         + pointweightlist[gfaceptr->idest]
                         + pointweightlist[gfaceptr->iapex];
          if (smallestweight > giftfaceweight) {
            smallestweight = giftfaceweight;
            smallestindex = j;
          }
        }
      }
    }
    assert(smallestindex != -1);
    return smallestindex;
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// getgiftpoint()    Search for a point that finished input face.            //
//                                                                           //
// To get a visible giftpoint for input giftface, we need:                   //
//   (1) First find all points which visible from input face.                //
//   (2) Choose a best (gift)point among these points.                       //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

int mesh3d::getgiftpoint(triface *gface, list *giftfacelist,
                         int numberofgiftpoints, point3d *giftpoints,
                         int *pointweightlist, list *candpointindexlist,
                         list *bestpointindexlist)
{
  giftface *gfaceptr;
  point3d forg, fdest, fapex;
  point3d testpoint1, testpoint2;
  int intersect, sharecount;
  int inspheretest, findflag;
  int gpointindex1, gpointindex2;
  int largerweight;
  int i, j, index;

  // Get the vertexs of input (gift)face.
  dest(*gface, forg);
  org(*gface, fdest);
  apex(*gface, fapex);
  if (verbose > 2) {
    printf("    Finding a point for finishing face (%d, %d, %d).\n",
           pointmark(forg), pointmark(fdest), pointmark(fapex));
  }

  candpointindexlist->clear();

  // Step (1):
  for (i = 0; i < numberofgiftpoints; i++) {
    if (pointweightlist[i] == 0) {
      // All faces which contain this point were finished.
      continue;
    }
    testpoint1 = giftpoints[i];
    if ((testpoint1 == forg) || (testpoint1 == fdest) ||
        (testpoint1 == fapex)) {
      continue; // Skip the vertex of face.
    }
    if (!isaboveplane(forg, fdest, fapex, testpoint1)) {
      // This point is below or coplanar or coincident with this face.
      continue;
    }
    if (verbose > 2) {
      printf("    Checking point %d.\n", pointmark(testpoint1));
    }
    // Now, we found that this point is vivible form face, we still need
    //   to check if there exist any constraining face that will cause
    //   this point unvisible form face.
    intersect = 0;
    for (j = 0; j < giftfacelist->len(); j++) {
      gfaceptr = (giftface*) (*giftfacelist)[j];
      if ((pointweightlist[gfaceptr->iorg] == 0) ||
          (pointweightlist[gfaceptr->idest] == 0) ||
          (pointweightlist[gfaceptr->iapex] == 0)) {
        // This face contain a zero-weight point, skip it.
        continue;
      }
      if (verbose > 2) {
        printf("    Checking face (%d, %d, %d).\n",
               pointmark(org(gfaceptr->casing)),
               pointmark(dest(gfaceptr->casing)),
               pointmark(apex(gfaceptr->casing)));
      }
      // Check if this face's vertexs are share with the new tet.
      sharecount = 0;
      if (isfacehaspoint(&gfaceptr->casing, forg)) sharecount++;
      if (isfacehaspoint(&gfaceptr->casing, fdest)) sharecount++;
      if (isfacehaspoint(&gfaceptr->casing, fapex)) sharecount++;
      if (isfacehaspoint(&gfaceptr->casing, testpoint1)) sharecount++;
      // assert(sharecount < 4);
      if (sharecount == 0) {
        intersect = is_face_tet_inter_0(&gfaceptr->casing, forg, fdest, fapex,
                                        testpoint1);
      } else if (sharecount == 1) {
        intersect = is_face_tet_inter_1(&gfaceptr->casing, forg, fdest, fapex,
                                        testpoint1);
      } else if (sharecount == 2) {
        intersect = is_face_tet_inter_2(&gfaceptr->casing, forg, fdest, fapex,
                                        testpoint1);
      } else { // if (sharecount == 3)
        intersect = 0;
      }
      if (intersect) {
        // If exist intersection face. break find face loop.
        if (verbose > 2) {
          printf("    Skipped.\n");
        }
        break;
      }
    }
    if (!intersect) {
      if (verbose > 2) {
        printf("    Visible from face.\n");
      }
      candpointindexlist->append(&i);
    }
  }
  if (candpointindexlist->len() == 0) {
    return -1; // Cannot find a point that can finish input face.
  }

  // Setp (2):
  if (verbose > 2) {
    printf("    Find %d candidating points.\n", candpointindexlist->len());
  }

  // Find a best point index from 'candpointindexlist'. A best point
  //   should be satisfied following rules:
  //   (1) It must satisfy the empty circumsphere criteria with the input
  //       face. If there exist more than one such point, choose the point
  //       which has the largest weight.
  //   (2) The degenerate case is there exist cosphere points. If so, we
  //       should choose a point which has the largest weight (This will
  //       helpfully avoid form a tetrahedron that cause later giftwrapping
  //       failed).
  //   (3) If no satisfied point be found. This mean we can't form a constr-
  //       ained Delaunay tetrahedralization from this faces and points(In
  //       my case, it should not happen.) For complete the job, we choose
  //       the point which has the maximized minimum-dihedral angle (not
  //       done yet).

  bestpointindexlist->clear();

  for (i = 0; i < candpointindexlist->len(); i++) {
    findflag = 1;
    gpointindex1 = *(int*)(*candpointindexlist)[i];
    testpoint1 = giftpoints[gpointindex1];
    for (j = 0; j < candpointindexlist->len(); j++) {
      if (j == i) continue; // Skip the same point.
      gpointindex2 = *(int*)(*candpointindexlist)[j];
      testpoint2 = giftpoints[gpointindex2];
      inspheretest = iinsphere(fdest, forg, fapex, testpoint1, testpoint2);
      if (inspheretest > 0) {
        findflag = 0;
        break;
      } else if (inspheretest == 0) {
        if (pointweightlist[gpointindex1] < pointweightlist[gpointindex2]) {
          findflag = 0;
          break;
        }
      }
    }
    if (findflag) {
      bestpointindexlist->append(&gpointindex1);
    }
  }

  if (verbose > 2) {
    printf("    Find %d best points.\n", bestpointindexlist->len());
  }
  if (bestpointindexlist->len() == 1) {
    gpointindex1 = *(int*)(*bestpointindexlist)[0];
  } else if (bestpointindexlist->len() > 1) {
    for (i = 0; i < bestpointindexlist->len(); i++) {
      gpointindex2 = *(int*)(*bestpointindexlist)[i];
      if (verbose > 2) {
        printf("     Checking point %d, weight = %d.\n",
               pointmark(giftpoints[gpointindex2]),
               pointweightlist[gpointindex2]);
      }
      if (i == 0) {
        largerweight = pointweightlist[gpointindex2];
        gpointindex1 = gpointindex2;
      } else {
        if (largerweight < pointweightlist[gpointindex2]) {
          largerweight = pointweightlist[gpointindex2];
          gpointindex1 = gpointindex2;
        }
      }
    }
  } else {
    // No constrained Delaunay tetrahedralization can be formed.
    printf("Internal error in getgiftpoint(): \n");
    printf("  Cannot find a best point from %i points",
           candpointindexlist->len());
    internalerror();
  }

  return gpointindex1;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// giftwrapping()    Generate a constrained Delaunay tetrahedralization from //
//                   input faces and points use Giftwrapping algorithm.      //
//                                                                           //
// The Giftwrapping algorithm:                                               //
//   The gift-wrapping algorithm maintains a dictionary of unfinished faces, //
// which initially contains the d+1 faces of the first Delaunay d-simplex.   //
// Repeat the following step: remove an arbitrary unfinished face f from the //
// dictionary and search for a vertex that finishes f. This vertex must be   //
// above f, and have the property that the new d-simplex that results has an //
// empty circumsphere. Na¨ývely, this search takes O(n) time. If no vertex   //
// is above f, then f lies on the boundary of the convex hull. Otherwise, s  //
// becomes part of the growing triangulation. Check each (d-1)-face of s,    //
// except f against the dictionary. If a face is already present in the dic- //
// tionary, then the face is now finished, so remove it from the dictionary. //
// Otherwise, the face is new, so insert it into the dictionary.             //
//                                                                           //
// 'backtracelist' is a list to keep all new tets be created during gift-    //
// wrapping stage, so we can delete them if gift-wrapping failed.            //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

int mesh3d::giftwrapping(int numberofgiftfaces, triface *giftfaces,
                         int numberofgiftpoints, point3d *giftpoints,
                         REAL *tetattribs, REAL volumevar, list *backtracelist)
{
  list *giftfacelist;
  list *smallweightlist;
  list *candpointindexlist, *bestpointindexlist;
  giftface gface, *gfaceptr;
  triface newtetra, checkface;
  face checksh;
  point3d gpoint, checkorg, checkdest;
  int *pointweightlist;
  int gfaceindex, gpointindex;
  int success, facefinished;
  int i, j;

  if (verbose > 1) {
    printf("  Gift-wrapping begin with %d faces, %d points.\n",
           numberofgiftfaces, numberofgiftpoints);
  }
  giftfacelist = new list(sizeof(giftface));
  pointweightlist = new int[numberofgiftpoints];
  // Init giftfacelist. At init all giftfaces are unfinished.
  for (i = 0; i < numberofgiftfaces; i++) {
    gfaceptr = (giftface*) giftfacelist->alloc();
    gfaceptr->casing = giftfaces[i];
    gfaceptr->iorg = gfaceptr->idest = gfaceptr->iapex = 0;
  }
  // Generate weights for every giftpoint. At the same time, store all
  //   vertexs's index in giftpoints array of each giftface. This will
  //   avoid to search index every time when a giftface is finfished.
  for (i = 0; i < numberofgiftpoints; i++) {
    pointweightlist[i] = 0;
    for (j = 0; j < giftfacelist->len(); j++) {
      gfaceptr = (giftface*) (*giftfacelist)[j];
      if (org(gfaceptr->casing) == giftpoints[i]) {
        pointweightlist[i]++;
        gfaceptr->iorg = i;
      } else if (dest(gfaceptr->casing) == giftpoints[i]) {
        pointweightlist[i]++;
        gfaceptr->idest = i;
      } else if (apex(gfaceptr->casing) == giftpoints[i]) {
        pointweightlist[i]++;
        gfaceptr->iapex = i;
      }
    }
    assert(pointweightlist[i] > 0);
  }
  if (verbose > 3) {
    dumpgifts("gifts.txt", giftfacelist, numberofgiftpoints,
              giftpoints, pointweightlist);
  }

  success = 1;
  // For there might exist more than one points have the same smallest
  //   weight, I use a list to keep all these points.
  smallweightlist = new list("int");
  // A list to keep all indexs of points which visible from the input
  //   giftface(*gface) in giftpoints array.
  candpointindexlist = new list("int");
  // A list to keep the best point(s) for finishing a giftface.
  bestpointindexlist = new list("int");
  // These three lists are created here to avoid create and delete every
  //   time when finishing each giftface.

  // Do giftwrapping from 'giftfacelist' and 'giftpoints'.
  while (giftfacelist->len()) {
    // Get a most suit giftface to start.
    gfaceindex = getgiftface(giftfacelist, numberofgiftpoints, pointweightlist,
                             smallweightlist);
    gface = *(giftface*)(*giftfacelist)[gfaceindex];
    if (verbose > 2) {
      printf("    Choosing face (%d, %d, %d).\n", pointmark(org(gface.casing)),
             pointmark(dest(gface.casing)), pointmark(apex(gface.casing)));
    }
    // Decrease corresponding point's weight.
    pointweightlist[gface.iorg]--;
    pointweightlist[gface.idest]--;
    pointweightlist[gface.iapex]--;
    // Remove this giftface from unfinished list.
    giftfacelist->del(gfaceindex);
    // Get a giftpoint that can be formed a constrained Delaunay tetrahedron
    //   with this giftface.
    gpointindex = getgiftpoint(&gface.casing, giftfacelist, numberofgiftpoints,
                               giftpoints, pointweightlist, candpointindexlist,
                               bestpointindexlist);
    if (gpointindex == -1) {
      success = 0;
      break; // Giftwrapping failed.
    }
    gpoint = giftpoints[gpointindex];
    if (verbose > 2) {
      printf("    Choosing point %d.\n", pointmark(gpoint));
    }
    // Form a new tetrahedron from gface.casing and gpoint.
    maketetrahedron(&newtetra);
    backtracelist->append(&newtetra);
    setorg (newtetra, dest(gface.casing));
    setdest(newtetra, org(gface.casing));
    setapex(newtetra, apex(gface.casing));
    setoppo(newtetra, gpoint);
    // Bond the new tetra with gift face.
    bond(gface.casing, newtetra);
    tspivot(gface.casing, checksh);
    if (checksh.sh != dummysh) {
      sesymself(checksh);
      tsbond(newtetra, checksh);
    }
    if (tetattribs != NULL) {
      // Set the element attributes of the new tetrahedron.
      for (i = 0; i < eextras; i++) {
        setelemattribute(newtetra.tet, i, tetattribs[i]);
      }
    }
    if (varvolume) {
      // Set the area constraint of a new tetrahedron.
      setvolumebound(newtetra.tet, volumevar);
    }
    // Check three new faces of newtetra to see if they are finished by
    //   other gift faces. If find such gift face, its being finished,
    //   remove it from giftfaces(set face finished flag be 1). If not
    //   find such gift face, add this face to giftfaces.
    adjustedgering(newtetra, CCW);
    for (i = 0; i < 3; i++) {
      fnext(newtetra, checkface);
      checkorg = org(checkface);
      checkdest = dest(checkface);
      // Find in giftfacelist to see if any face be finished. If a face
      //   has both three points(checkorg, checkdest and gpoint). It must
      //   be finished.
      facefinished = 0;
      for (j = 0; j < giftfacelist->len(); j++) {
        gfaceptr = (giftface*)(*giftfacelist)[j];
        if (isfacehaspoint(&(gfaceptr->casing), checkorg) &&
            isfacehaspoint(&(gfaceptr->casing), checkdest) &&
            isfacehaspoint(&(gfaceptr->casing), gpoint)) {
          // Find such face, now it is finished.
          if (verbose > 2) {
            printf("    Finishing face (%d, %d, %d).\n",
                   pointmark(org(gfaceptr->casing)),
                   pointmark(dest(gfaceptr->casing)),
                   pointmark(apex(gfaceptr->casing)));
          }
          //   Decrease corresponding point's weight.
          pointweightlist[gfaceptr->iorg]--;
          pointweightlist[gfaceptr->idest]--;
          pointweightlist[gfaceptr->iapex]--;
          //   Bond these two tets.
          bond(gfaceptr->casing, checkface);
          tspivot(gfaceptr->casing, checksh);
          if (checksh.sh != dummysh) {
            sesymself(checksh);
            tsbond(checkface, checksh);
          }
          // Remove this giftface from unfinished list.
          giftfacelist->del(j);
          facefinished = 1;
          break;
        }
      }
      if (!facefinished) {
        // This is an unfinished face, add it to giftfacelist.
        gfaceptr = (giftface*) giftfacelist->alloc();
        adjustedgering(checkface, CCW);
        gfaceptr->casing = checkface;
        if (verbose > 2) {
          printf("    Adding an unfinished face (%d, %d, %d).\n",
                 pointmark(org(gfaceptr->casing)),
                 pointmark(dest(gfaceptr->casing)),
                 pointmark(apex(gfaceptr->casing)));
        }
        // Decide the index of point from gface. Note: here gface's enext()
        //   sequence is: (idest, iorg)->(iorg, iapex)->(iapex, idest) that
        //   corresponding to checkface's enext() sequence. But after do
        //   checkface.adjustedgering(0) it becomes inversed in each term:
        //   that is: (iorg, idest)->(iapex, iorg)->(idest, iapex).
        if (i == 0) {
          gfaceptr->iorg = gface.iorg;
          gfaceptr->idest = gface.idest;
        } else if (i == 1) {
          gfaceptr->iorg = gface.iapex;
          gfaceptr->idest = gface.iorg;
        } else { // i == 2
          gfaceptr->iorg = gface.idest;
          gfaceptr->idest = gface.iapex;
        }
        gfaceptr->iapex = gpointindex;
        // Increase each vertex's weight.
        pointweightlist[gfaceptr->iorg]++;
        pointweightlist[gfaceptr->idest]++;
        pointweightlist[gfaceptr->iapex]++;
      }
      enextself(newtetra);
    }
    if (verbose > 2) {
      printf("    Create new: ");
      dump(&newtetra);
    }
  }

  if (verbose > 1) {
    printf("  Gift-wrapping end: %s.\n", success ? "Success" : "Failed");
  }
  delete [] pointweightlist;
  delete giftfacelist;
  delete smallweightlist;
  delete bestpointindexlist;
  delete candpointindexlist;
  return success;
}

///////////////////////////////////////////////////////////////////////////////
// END                                                                       //
// Giftwrapping Algorithm Implementation                                     //
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Randomized Incremental Flip Delaunay Tetrahedrization                     //
// BEGIN                                                                     //
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//   Incremental insertion algorithm is the simplest and the most commonly   //
// used algorithm for constructing Delaunay triangulations. It extends in    //
// a straightforward way to three (or more) dimensions. In three-dimension   //
// there have several algorithms based on the incermental scheme, such as    //
// the algorithms proposed by Boywer/Watson[1], Joe[2] and Edelsbrunner and  //
// Shah[3], etc.                                                             //
//                                                                           //
//   Joe[2] provided an Incremental Flip algorithm to construct Delaunay     //
// tetrahedralization with time complexity of O(n ^ 2) in the worst case, n  //
// is the size of input point set. Edelsbrunner and Shah[3] extended Joe's   //
// algorithm to a Randomized Incremental Flip algorithm with time complexity //
// of O(n ^ (d+1)/2) in the worst case and O(n log n + n ^ ceiling(d/2)) in  //
// the expected case.  Empirical results with an existing implementation     //
// (Detri[4]) shows the Edelsbrunner and Shah[3]'s algorithm behaved well    //
// for both randomly and regular distributed point sets.                     //
//                                                                           //
//   Tetgen uses the Randomized Incremental Flip algorithm of Edelsbrunner   //
// and Shah[3] to construct Delaunay tetrahedralizations of 3D point sets.   //
// The implementation is robust and fast. It used the fast randomized point  //
// location algorithm of Mucke, Issac and Zhu's to perform point location.   //
// and optionally used the adaptive exact geometric predicates package of    //
// Shewchuk to perform exact orientation and insphere tests, Mucke's share-  //
// ware Detri[4] also implemented the same algorithm, but lack of speed. My  //
// implementation of this algorithm is faster than Detri[4].                 //
//                                                                           //
// Please see predicate.cpp, ptloc.cpp and flips.cpp for more infomation.    //
//                                                                           //
// Refernces:                                                                //
//                                                                           //
// [1] Adrian Bowyer. Computing Dirichlet Tessellations. Computer Journal    //
//     24(2):162-166, 1981.  David F. Watson. Computing the three-dimens-    //
//     ional Delaunay Tessellation with Application to Voronoi Polytopes.    //
//     Computer Journal 24(2):167-172, 1981.                                 //
// [2] Barry Joe. Construction of Three-Dimensional Triangulations using     //
//     Local Transformations. Computer Aided Geometric Design 8:123-142,     //
//     1991.                                                                 //
// [3] Herbert Edelsbrunner and Nimish Shah. Incremental topological         //
//     flipping works for regular triangulations. Algorithmica, 15:223-241,  //
//     1996.                                                                 //
// [4] Detri, The Code Constructs the 3D Delaunay Triangulation of a Given   //
//     Point Set Using a Variant of the Randomized Incremental-Flip          //
//     Algorithm,                                                            //
//     http://www.geom.umn.edu/software/cglist/GeomDir/Detri_2.6.a.tar.gz    //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// construct_initial_tetra()    Create an initial triangulation by building  //
//                              tetrahedron <a, b, c, o>; where the four     //
//                              points are not coplanar, and no three points //
//                              are colinear.                                //
//                                                                           //
// To construct the first tetrahedron, we should detect and avoid degenerate //
// cases. They are two duplicated points, three colinear points and four     //
// coplanar points. At two duplicated points case, we just ignored one of    //
// them; at colinear and coplanar points cases, we must skip current point   //
// and get next point, keep testing until a good point be found, all skipped //
// points will consider later, store them in 'skippointlist'.                //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::construct_initial_tetra(queue* skippointlist)
{
  triface newtet, ghosttet;
  point3d pointloop;
  point3d pa, pb, pc, pd;
  int pointnumber;
  int i, j;

  if (verbose > 1) {
    printf("  Construct an initial tetrahedron.\n");
  }
  // Set a 'ghosttet' handle the Outer space.
  ghosttet.tet = dummytet;
  pointnumber = points.items;
  points.traversalinit();
  pa = pointtraverse();
  i = 0;
  while (i < pointnumber) {
    pointloop = pointtraverse();
    i++;
    if(compare2points(&pa, &pointloop) == 0) {
      if (!quiet) {
        printf("Warning:  A duplicate point at (%.12g, %.12g, %.12g)",
               pointloop[0], pointloop[1], pointloop[2]);
        printf(" appeared and was ignored.\n");
      }
      // This will cause change from input points set.
      // pointdealloc(pointloop);
      continue;
    }
    break;
  }
  if (i >= pointnumber) {
    printf("\nAll points are duplicate, no tetrahedralization be");
    printf(" constructed.\n");
    exit(1);
  }
  pb = pointloop;
  while (i < pointnumber) {
    pointloop = pointtraverse();
    i++;
    if (iscoline(pa, pb, pointloop)) {
      if (verbose > 2) {
        printf("    A colinear point at (%.12g, %.12g, %.12g) %d",
          pointloop[0], pointloop[1], pointloop[2]);
        printf(" appeared and queued to process later.\n");
      }
      skippointlist->push(&pointloop);
      continue;
    }
    break;
  }
  if (i >= pointnumber) {
    printf("\nAll points are colinear, no tetrahedralization be");
    printf(" constructed.\n");
    exit(1);
  }
  pc = pointloop;
  while (i < pointnumber) {
    pointloop = pointtraverse();
    i++;
    if (iscoplane(pa, pb, pc, pointloop)) {
      if (verbose > 2) {
        printf("    A coplanar point at (%.12g, %.12g, %.12g)",
          pointloop[0], pointloop[1], pointloop[2]);
        printf(" appeared and queued to process later.\n");
      }
      skippointlist->push(&pointloop);
      continue;
    }
    break;
  }
  if (i >= pointnumber) {
    printf("All points are coplanar, no tetrahedrization be constructed.\n");
    exit(1);
  }
  pd = pointloop;

  if (!isaboveplane(pa, pb, pc, pd)) {
    pointloop = pa; pa = pb; pb = pointloop;
  }
  maketetrahedron(&newtet);
  setorg(newtet, pa);
  setdest(newtet, pb);
  setapex(newtet, pc);
  setoppo(newtet, pd);
  bond(newtet, ghosttet);
  if (verbose > 2) {
    printf("    Creating tetra ");
    dump(&newtet);
  }
  // At init, all faces of this tet are hull faces.
  hullsize = 4;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// collect_visibles()    Collects all CH facets visible from insertpoint and //
//                       stores them in fliplist. At the same time,construct //
//                       tetrahedra from insertpoint to all visible facets.  //
//                                                                           //
// The 'insertpoint' locate outside CH. And 'horiz' is a init hull facet ha- //
// ndle that visible from 'insertpoint'. ( We assume that an oracle provided //
// the initial facet which is on CH )   'fliplist' is a queue for return all //
// visible facets from 'insertpoint', which will check doflip later.         //
//                                                                           //
// 'ghosttet' is a handle that hold the 'Outer Space' of current mesh. Use   //
// this handle to bond new generated tetrahedron on current boundary, so     //
// later point location routines will work correctlly.                       //
//                                                                           //
// 'unfinfacelist' is a link to keep all unfinished faces for 'insertpoint'. //
// It is created in routine rand_incr_flip_delaunay() to avoid create it and //
// delete it every time when call this routine. At the beginning and end of  //
// this routine, 'unfinfacelist' should be empty.                            //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::collect_visibles(point3d insertpoint, triface *horiz,
                              triface *ghosttet, link *unfinfacelist)
{
  triface newtet, otherface, horizface;
  point3d torg, tdest, tapex;
  int findex;

  if (verbose > 1) {
    printf("  Collect visible facets for inserting point: \n");
  }

  enqueuefliplist(*horiz);
  adjustedgering(*horiz, CCW);
  org (*horiz, torg);
  dest(*horiz, tdest);
  apex(*horiz, tapex);
  // Mount the initial tetrahedron to mesh.  That is a tetrahedron consists
  //   of facet horiz and insertpoint.
  maketetrahedron(&newtet); // default newtet.ver = 0.
  setorg (newtet, tdest);
  setdest(newtet, torg);
  setapex(newtet, tapex);
  setoppo(newtet, insertpoint);
  // Make the connection of two tets.
  bond(newtet, *horiz);
  // Add the new tetrahedron's three faces to unfinished faces list.
  //   Keep 'insertpoint' be apex of each faces.
  fnext(newtet, otherface);
  unfinfacelist->add(&otherface);
  enextfnext(newtet, otherface);
  unfinfacelist->add(&otherface);
  enext2fnext(newtet, otherface);
  bond(otherface, *ghosttet);
  unfinfacelist->add(&otherface);
  if (verbose > 2) {
    printf("    Creating newtet ");
    dump(&newtet);
  }
  // Hull face number decreased caused by face bond() operation.
  hullsize --;

  // Loop untill unfinfacelist is empty.
  while (unfinfacelist->len() > 0) {
    horizface = * (triface *) unfinfacelist->getnitem(1);
    unfinfacelist->del(1);  // Remove it.
    otherface = horizface;
    adjustedgering(otherface, CCW);
    // Spin otherface around the edge of otherface. Stop when encounter
    //   Outer space.
    while (fnextself(otherface)) ;
    adjustedgering(horizface, CW);
    apex(otherface, tapex);
    if (isaboveplane(&horizface, tapex)) {
      // otherface is visible form insertpoint.
      enqueuefliplist(otherface);
      org (otherface, torg);
      dest(otherface, tdest);
      // Mount a tetrahedron to mesh.  This tetrahedron is consists of
      //   otherface's vertexs and insertpoint.
      maketetrahedron(&newtet);          // default newtet.ver = 0.
      setorg (newtet, torg);
      setdest(newtet, tdest);
      setapex(newtet, tapex);
      setoppo(newtet, insertpoint);
      // Make the connection of three tets.  Note:  The other two faces of
      //   new tet default bond to 'dummytet',  here need check if they are
      //   finished.
      bond(newtet, otherface);
      // Hull face number decrease caused by bond().
      hullsize --;
      fnext(newtet, otherface);
      bond(otherface, horizface);
      // Check other two face if they already exist in list Unfinshed.If so
      //   They are finished now and can be removed from list, then bond.
      enextfnext(newtet, otherface);
      findex = unfinfacelist->hasitem(&otherface);
      if ((findex > 0) && (findex <= unfinfacelist->len())) {
        horizface = * (triface *) unfinfacelist->getnitem(findex);
        unfinfacelist->del(findex);  // Remove it.
        bond(otherface, horizface);
      } else {
        bond(otherface, *ghosttet);
        unfinfacelist->add(&otherface);
      }
      enext2fnext(newtet, otherface);
      findex = unfinfacelist->hasitem(&otherface);
      if ((findex > 0) && (findex <= unfinfacelist->len())) {
        horizface = * (triface *) unfinfacelist->getnitem(findex);
        unfinfacelist->del(findex);  // Remove it.
        bond(otherface, horizface);
      } else {
        bond(otherface, *ghosttet);
        unfinfacelist->add(&otherface);
      }
      if (verbose > 2) {
        printf("    Createing newtet ");
        dump(&newtet);
      }
    } else {
      // This is a hull face.
      hullsize ++;
    }
  } // End of while.
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// dofliplist()    Flips non-Delaunay triangular facets in given 'fliplist'  //
//                 until all triangular facets are locally Delaunay.         //
//                                                                           //
// ASSUMPTION: Current tetrahedrization is non-Delaunay after inserting      //
// point v, AND: all possibly non-Delaunay link-facets after are on 'flip-   //
// list. Upon success (which should always happen, by now) dofliplist()      //
// returns the number of necessary flips. As a side effect,'fliplist' will   //
// be cleared, and current tetrahedrization updated accordingly.             //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

int mesh3d::dofliplist()
{
  triface flipface;
  enum facecategory fc;
  int flipcount;

  flipcount = flip_t23s + flip_t32s + flip_t22s + flip_t44s;
  // Start flip.
  if (verbose > 1) {
    printf("  Start do flip list: %d faces in list.", fliplist->len());
    if (verbose > 1) printf("\n");
  }
  while (dequeuefliplist(flipface)) {
    fc = categorizeface(flipface);
    // Determine the preferable configuration and swap if necessary.
    switch (fc) {
      // These cases are handled by edge swapping.
      case N44:
      case N32:
        break;
      // These cases are definitely unswappable
      case N40:
      case N30:
      case N20:
      case LOCKED:
        break;
      case T44:
        if (querydoswap(flipface)) {
          flip44(flipface);
        }
        break;
      case T22:
        if (querydoswap(flipface)) {
          flip22(flipface);
        }
        break;
      case T23:
        if (querydoswap(flipface)) {
          flip23(flipface);
        }
        break;
      case T32:
        if (querydoswap(flipface)) {
          flip32(flipface);
        }
        break;
      // Catch-all for bad cases
      default:
        break;
    }
  }
  flipcount = flip_t23s + flip_t32s + flip_t22s + flip_t44s - flipcount;
  if (verbose > 1) {
    printf("  Total %d flips.\n", flipcount);
  }
  return flipcount;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// rand_incr_flip_delaunay()   Construction delaunay tetrahedrization for a  //
//                             given three-dimensional point set use Random- //
//                             ize Incremental Flip algorithm.               //
//                                                                           //
// The basic idea of the incremental flip algorithm is the folloeing. S be a //
// set of points in IR{3}, Let 4 <= i <= n and assume that the Delaunay tri- //
// angulation of the first i-1 points in S is already constructed; call it   //
// D(i-1). Add the i-th point pi (belong to S) to the triangulation,and res- //
// tore Delaunayhood by flipping; this result in D(i). Repeat this procedure //
// until i = n. If implemented correctly, this strategy always leads to the  //
// Ddelaunay triangulation of S.                                             //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

long mesh3d::rand_incr_flip_delaunay()
{
  queue *skippointlist;
  link *unfinfacelist;
  triface starttet, ghosttet;
  point3d pointloop;
  enum insertsiteresult insres;
  long max_flips, flipcount;
  int max_flips_overflow;

  // max_flips is the upper bound on total number of flips.
  //   see Herbert's Triangulation notes, p95.
  max_flips = points.items * (points.items + 3) + 1;
  if (max_flips <= 0) {
    // The long number Overflow!
    max_flips_overflow = 1;
  } else {
    max_flips_overflow = 0;
  }

  usefliplist = 1;
  if (fliplist) {
    fliplist->clear();
  } else {
    fliplist = new queue(sizeof(badface3d));
  }

  // Set a queue for keeping all skipped points in routine
  //   construct_initial_tetra();
  skippointlist = new queue("point");

  // Set a 'ghosttet' handle the Outer space.
  //   This variable only used in routine collect_visible().
  ghosttet.tet = dummytet;
  // Setup a list for keeping all unfinished faces.
  //   This list only used in routine collect_visible(). It is created here
  //   to avoid create it and delete it every time when call this routine.
  unfinfacelist = new link(sizeof(triface));
  // Set user-defined compare function for comparing faces.
  unfinfacelist->setcomp((compfunc) &issameface);

  flip_t23s = flip_t32s = flip_t22s = flip_t44s = 0;
  cospherecount = 0;

  // Build a initial tetrahedron.
  construct_initial_tetra(skippointlist);

  // Delaunay tetrahedrization construction.
  //   Continue get points after above routine, need not do traverseinit().
  pointloop = pointtraverse();
  while (pointloop != (point3d) NULL) {
    starttet.tet = (tetrahedron *) NULL;
    insres = insertsite(pointloop, &starttet, NULL, NULL);
    if (insres == FAILED) {
      // Point is outside current mesh.
      collect_visibles(pointloop, &starttet, &ghosttet, unfinfacelist);
      assert(unfinfacelist->len() == 0);
    } else if (insres == DUPLICATE) {
      if (!quiet) {
        printf("Warning:  A duplicate point at (%.12g, %.12g, %.12g)",
               pointloop[0], pointloop[1], pointloop[2]);
        printf(" appeared and was ignored.\n");
      }
    }
    if (!fliplist->empty()) {
      flipcount = dofliplist();
      if (!max_flips_overflow) {
        max_flips -= flipcount;
      }
    }
    pointloop = pointtraverse();
  }
  if (!max_flips_overflow && (max_flips <= 0)) {
    printf("Error: Randomize Incremental Flip algorithm crashed!\n");
    internalerror();
  }

  if (skippointlist->len() > 0) {
    while (skippointlist->get(&pointloop)) {
      starttet.tet = (tetrahedron *) NULL;
      insres = insertsite(pointloop, &starttet, NULL, NULL);
      if (insres == FAILED) {
        // Point is outside current mesh.
        collect_visibles(pointloop, &starttet, &ghosttet, unfinfacelist);
        assert(unfinfacelist->len() == 0);
      } else if (insres == DUPLICATE) {
        if (!quiet) {
          printf("Warning:  A duplicate point at (%.12g, %.12g, %.12g)",
                 pointloop[0], pointloop[1], pointloop[2]);
          printf(" appeared and was ignored.\n");
        }
      }
      if (!fliplist->empty()) {
        flipcount = dofliplist();
        if (!max_flips_overflow) {
          max_flips -= flipcount;
        }
      }
    }
    if (!max_flips_overflow && (max_flips <= 0)) {
      printf("Error: Randomize Incremental Flip algorithm crashed!\n");
      internalerror();
    }
  }

  if (verbose) {
    printf("  Total flips: %d  Where T23: %d  T32: %d  T22: %d  T44: %d\n",
           flip_t23s + flip_t32s + flip_t22s + flip_t44s,
           flip_t23s, flip_t32s, flip_t22s, flip_t44s);
    printf("  Cosphere count: %d\n", cospherecount);
  }
  assert(fliplist->empty());
  usefliplist = 0;
  delete skippointlist;
  delete unfinfacelist;
  return hullsize;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// delaunay()   Form a Delaunay triangulation.                               //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

long mesh3d::delaunay()
{
  eextras = 0;
  initializetetshpools();

  if (!quiet) {
    if (noexact) {
      printf("Using approximate floating-point arthmetic ");
    } else {
      printf("Using adaptive exact floating-point arthmetic ");
    }
    if (noroundoff) {
      printf("without tolerance.\n");
    } else {
      printf("with tolerance %g.\n", usertolerance);
    }
    printf("Constructing Delaunay triangulation ");
    printf("by Randomized Incremental-Flip algorithm.\n");
  }

  return rand_incr_flip_delaunay();
}

///////////////////////////////////////////////////////////////////////////////
// END                                                                       //
// Randomized Incremental Flip Delaunay Tetrahedrization                     //
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// File I/O Routines                                                         //
// BEGIN                                                                     //
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// readline()    Read a nonempty line from a file.                           //
//                                                                           //
// A line is considered "nonempty" if it contains something that looks like  //
// a number.                                                                 //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

char* mesh3d::readline(char *string, FILE *infile, char *infilename)
{
  char *result;

  // Search for something that looks like a number.
  do {
    result = fgets(string, INPUTLINESIZE, infile);
    if (result == (char *) NULL) {
      printf("File I/O Error:  Unexpected end of file in %s.\n", infilename);
      exit(1);
    }
    // Skip anything that doesn't look like a number, a comment,
    //   or the end of a line.
    while ((*result != '\0') && (*result != '#')
           && (*result != '.') && (*result != '+') && (*result != '-')
           && ((*result < '0') || (*result > '9'))) {
      result++;
    }
  // If it's a comment or end of line, read another line and try again.
  } while ((*result == '#') || (*result == '\0'));
  return result;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// findfield()    Find the next field of a string.                           //
//                                                                           //
// Jumps past the current field by searching for whitespace, then jumps past //
// the whitespace to find the next field.                                    //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

char* mesh3d::findfield(char *string)
{
  char *result;

  result = string;
  // Skip the current field.  Stop upon reaching whitespace.
  while ((*result != '\0') && (*result != '#')
         && (*result != ' ') && (*result != '\t')) {
    result++;
  }
  // Now skip the whitespace and anything else that doesn't look like a
  //   number, a comment, or the end of a line.
  while ((*result != '\0') && (*result != '#')
         && (*result != '.') && (*result != '+') && (*result != '-')
         && ((*result < '0') || (*result > '9'))) {
    result++;
  }
  // Check for a comment (prefixed with `#').
  if (*result == '#') {
    *result = '\0';
  }
  return result;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// readnodes()    Read the points from a file, which may be a .node or .poly //
//                file.                                                      //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::readnodes(FILE **polyfile)
{
  FILE *infile;
  point3d pointloop;
  char inputline[INPUTLINESIZE];
  char *stringptr;
  char *infilename;
  REAL x, y, z;
  int firstnode;
  int nodemarkers;
  int currentmarker;
  int i, j;

  if (poly || smesh) {
    // Read the points from a .poly or .smesh file.
    if (poly) {
      if (!quiet) {
        printf("Opening %s.\n", inpolyfilename);
      }
      *polyfile = fopen(inpolyfilename, "r");
      if (*polyfile == (FILE *) NULL) {
        printf("File I/O Error:  Cannot access file %s.\n", inpolyfilename);
        exit(1);
      }
      stringptr = readline(inputline, *polyfile, inpolyfilename);
    } else {
      if (!quiet) {
        printf("Opening %s.\n", insmeshfilename);
      }
      *polyfile = fopen(insmeshfilename, "r");
      if (*polyfile == (FILE *) NULL) {
        printf("File I/O Error:  Cannot access file %s.\n", insmeshfilename);
        exit(1);
      }
      stringptr = readline(inputline, *polyfile, insmeshfilename);
    }
    // Read number of points, number of dimensions, number of point
    //   attributes, and number of boundary markers.
    inpoints = (int) strtol (stringptr, &stringptr, 0);
    stringptr = findfield(stringptr);
    if (*stringptr == '\0') {
      mesh_dim = 3;
    } else {
      mesh_dim = (int) strtol (stringptr, &stringptr, 0);
    }
    stringptr = findfield(stringptr);
    if (*stringptr == '\0') {
      nextras = 0;
    } else {
      nextras = (int) strtol (stringptr, &stringptr, 0);
    }
    stringptr = findfield(stringptr);
    if (*stringptr == '\0') {
      nodemarkers = 0;
    } else {
      nodemarkers = (int) strtol (stringptr, &stringptr, 0);
    }
    if (inpoints > 0) {
      readnodefile = 0;
      infilename = inpolyfilename;
      infile = *polyfile;
    } else {
      // If the .poly file claims there are zero points, that means that
      //   the points should be read from a separate .node file.
      readnodefile = 1;
      infilename = innodefilename;
    }
  } else {
    readnodefile = 1;
    infilename = innodefilename;
    *polyfile = (FILE *) NULL;
  }

  if (readnodefile) {
    // Read the points from a .node file.
    if (!quiet) {
      printf("Opening %s.\n", innodefilename);
    }
    infile = fopen(innodefilename, "r");
    if (infile == (FILE *) NULL) {
      printf("File I/O Error:  Cannot access file %s.\n", innodefilename);
      exit(1);
    }
    // Read number of points, number of dimensions, number of point
    //   attributes, and number of boundary markers.
    stringptr = readline(inputline, infile, innodefilename);
    inpoints = (int) strtol (stringptr, &stringptr, 0);
    stringptr = findfield(stringptr);
    if (*stringptr == '\0') {
      mesh_dim = 3;
    } else {
      mesh_dim = (int) strtol (stringptr, &stringptr, 0);
    }
    stringptr = findfield(stringptr);
    if (*stringptr == '\0') {
      nextras = 0;
    } else {
      nextras = (int) strtol (stringptr, &stringptr, 0);
    }
    stringptr = findfield(stringptr);
    if (*stringptr == '\0') {
      nodemarkers = 0;
    } else {
      nodemarkers = (int) strtol (stringptr, &stringptr, 0);
    }
  }

  if (inpoints < 4) {
    printf("Error:  Input must have at least four input points.\n");
    exit(1);
  }
  if (mesh_dim != 3) {
    printf("Error:  This program only works with three-dimensional meshes.\n");
    exit(1);
  }

  initializepointpool();

  // Read the points.
  for (i = 0; i < inpoints; i++) {
    pointloop = (point3d) points.alloc();
    stringptr = readline(inputline, infile, infilename);
    if (i == 0) {
      firstnode = (int) strtol (stringptr, &stringptr, 0);
      if ((firstnode == 0) || (firstnode == 1)) {
        firstnumber = firstnode;
      }
    }
    stringptr = findfield(stringptr);
    if (*stringptr == '\0') {
      printf("File I/O Error:  Point %d has no x coordinate.\n",
             firstnumber + i);
      exit(1);
    }
    x = (REAL) strtod(stringptr, &stringptr);
    stringptr = findfield(stringptr);
    if (*stringptr == '\0') {
      printf("File I/O Error:  Point %d has no y coordinate.\n",
             firstnumber + i);
      exit(1);
    }
    y = (REAL) strtod(stringptr, &stringptr);
    stringptr = findfield(stringptr);
    if (*stringptr == '\0') {
      printf("File I/O Error:  Point %d has no z coordinate.\n",
             firstnumber + i);
      exit(1);
    }
    z = (REAL) strtod(stringptr, &stringptr);
    pointloop[0] = x;
    pointloop[1] = y;
    pointloop[2] = z;
    // Read the point attributes.
    for (j = 3; j < 3 + nextras; j++) {
      stringptr = findfield(stringptr);
      if (*stringptr == '\0') {
        pointloop[j] = 0.0;
      } else {
        pointloop[j] = (REAL) strtod(stringptr, &stringptr);
      }
    }
    if (nodemarkers) {
      // Read a point marker.
      stringptr = findfield(stringptr);
      if (*stringptr == '\0') {
        setpointmark(pointloop, 0);
      } else {
        currentmarker = (int) strtol (stringptr, &stringptr, 0);
        setpointmark(pointloop, currentmarker);
      }
    } else {
      // If no markers are specified in the file, they default to zero.
      setpointmark(pointloop, 0);
    }
    // Determine the smallest and largest x and y coordinates.
    if (i == 0) {
      xmin = xmax = x;
      ymin = ymax = y;
      zmin = zmax = z;
    } else {
      xmin = (x < xmin) ? x : xmin;
      xmax = (x > xmax) ? x : xmax;
      ymin = (y < ymin) ? y : ymin;
      ymax = (y > ymax) ? y : ymax;
      zmin = (z < ymin) ? z : zmin;
      zmax = (z > zmax) ? z : zmax;
    }
  }
  if (readnodefile) {
    fclose(infile);
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// readholes()   Read the holes, and possibly regional attributes and volume //
//               constraints, from a .poly file.                             //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::readholes(FILE *polyfile, REAL **hlist, int *holes, REAL **rlist,
                       int *regions)
{
  REAL *holelist;
  REAL *regionlist;
  char inputline[INPUTLINESIZE];
  char *stringptr;
  int index;
  int i;

  // Read the holes.
  if (poly || smesh) {
    stringptr = readline(inputline, polyfile, inpolyfilename);
    *holes = (int) strtol (stringptr, &stringptr, 0);
  } else {
    // There need not hole section in smesh file format.
    *holes = 0;
  }
  if (*holes > 0) {
    holelist = (REAL *) new REAL[3 * *holes];
    *hlist = holelist;
    for (i = 0; i < 3 * *holes; i += 3) {
      stringptr = readline(inputline, polyfile, inpolyfilename);
      stringptr = findfield(stringptr);
      if (*stringptr == '\0') {
        printf("File I/O Error:  Hole %d has no x coordinate.\n",
               firstnumber + (i / 3));
        exit(1);
      } else {
        holelist[i] = (REAL) strtod(stringptr, &stringptr);
      }
      stringptr = findfield(stringptr);
      if (*stringptr == '\0') {
        printf("File I/O Error:  Hole %d has no y coordinate.\n",
               firstnumber + (i / 3));
        exit(1);
      } else {
        holelist[i + 1] = (REAL) strtod(stringptr, &stringptr);
      }
      stringptr = findfield(stringptr);
      if (*stringptr == '\0') {
        printf("File I/O Error:  Hole %d has no z coordinate.\n",
               firstnumber + (i / 3));
        exit(1);
      } else {
        holelist[i + 2] = (REAL) strtod(stringptr, &stringptr);
      }
    }
  } else {
    *hlist = (REAL *) NULL;
  }

  if ((regionattrib || varvolume) && !refine) {
    // Read the volume constraints.
    stringptr = readline(inputline, polyfile, inpolyfilename);
    *regions = (int) strtol (stringptr, &stringptr, 0);
    if (*regions > 0) {
      regionlist = (REAL *) new REAL[5 * *regions];
      *rlist = regionlist;
      index = 0;
      for (i = 0; i < *regions; i++) {
        stringptr = readline(inputline, polyfile, inpolyfilename);
        stringptr = findfield(stringptr);
        if (*stringptr == '\0') {
          printf("File I/O Error:  Region %d has no x coordinate.\n",
                 firstnumber + i);
          exit(1);
        } else {
          regionlist[index++] = (REAL) strtod(stringptr, &stringptr);
        }
        stringptr = findfield(stringptr);
        if (*stringptr == '\0') {
          printf("File I/O Error:  Region %d has no y coordinate.\n",
                 firstnumber + i);
          exit(1);
        } else {
          regionlist[index++] = (REAL) strtod(stringptr, &stringptr);
        }
        stringptr = findfield(stringptr);
        if (*stringptr == '\0') {
          printf("File I/O Error:  Region %d has no z coordinate.\n",
                 firstnumber + i);
          exit(1);
        } else {
          regionlist[index++] = (REAL) strtod(stringptr, &stringptr);
        }
        stringptr = findfield(stringptr);
        if (*stringptr == '\0') {
          printf("File I/O Error:  Region %d has no region attribute or",
                 firstnumber + i);
          printf(" volume constraint.\n");
          exit(1);
        } else {
          regionlist[index++] = (REAL) strtod(stringptr, &stringptr);
        }
        stringptr = findfield(stringptr);
        if (*stringptr == '\0') {
          regionlist[index] = regionlist[index - 1];
        } else {
          regionlist[index] = (REAL) strtod(stringptr, &stringptr);
        }
        index++;
      }
    }
  } else {
    // Set `*regions' to zero to avoid an accidental free() later.
    *regions = 0;
    *rlist = (REAL *) NULL;
  }

  fclose(polyfile);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// outnodes()    Number the points and write them to a .node file.           //
//                                                                           //
// To save memory, the point numbers are written over the shell markers      //
// after the points are written to a file.                                   //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::outnodes()
{
  FILE *outfile;
  point3d pointloop;
  int pointnumber;
  int i;

  if (!quiet) {
    printf("Writing %s.\n", outnodefilename);
  }
  outfile = fopen(outnodefilename, "w");
  if (outfile == (FILE *) NULL) {
    printf("File I/O Error:  Cannot create file %s.\n", outnodefilename);
    exit(1);
  }
  // Number of points, number of dimensions, number of point attributes,
  //   and number of boundary markers (zero or one).
  fprintf(outfile, "%ld  %d  %d  %d\n", points.items, mesh_dim, nextras,
          1 - nobound);

  points.traversalinit();
  pointloop = pointtraverse();
  pointnumber = firstnumber;
  while (pointloop != (point3d) NULL) {
    // Point number, x, y and z coordinates.
    fprintf(outfile, "%4d    %.17g  %.17g  %.17g", pointnumber, pointloop[0],
            pointloop[1], pointloop[2]);
    for (i = 0; i < nextras; i++) {
      // Write an attribute.
      fprintf(outfile, "  %.17g", pointloop[i + 3]);
    }
    if (nobound) {
      fprintf(outfile, "\n");
    } else {
      // Write the boundary marker.
      fprintf(outfile, "    %d\n", pointmark(pointloop));
    }
    setpointmark(pointloop, pointnumber);
    pointloop = pointtraverse();
    pointnumber++;
  }

  fprintf(outfile, "# Generated by %s\n", commandline);
  fclose(outfile);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// numbernodes()    Number the points.                                       //
//                                                                           //
// Each point is assigned a marker equal to its number.                      //
//                                                                           //
// Used when outnodes() is not called because no .node file is written.      //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::numbernodes(int myfirstnumber)
{
  point3d pointloop;
  int pointnumber;

  points.traversalinit();
  pointloop = pointtraverse();
  if (!myfirstnumber) {
    pointnumber = firstnumber;
  } else {
    pointnumber = myfirstnumber;
  }
  while (pointloop != (point3d) NULL) {
    setpointmark(pointloop, pointnumber);
    pointloop = pointtraverse();
    pointnumber++;
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// outelems()     Write the tetrahedra to an .ele file.                      //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::outelems()
{
  FILE *outfile;
  tetrahedron* tptr;
  point3d p1, p2, p3, p4;
  int elementnumber;
  int i;

  if (!quiet) {
    printf("Writing %s.\n", outelefilename);
  }
  outfile = fopen(outelefilename, "w");
  if (outfile == (FILE *) NULL) {
    printf("File I/O Error:  Cannot create file %s.\n", outelefilename);
    exit(1);
  }
  // Number of tetras, points per tetra, attributes per tetra.
  fprintf(outfile, "%ld  %d  %d\n", tetrahedrons.items, 4, eextras);

  tetrahedrons.traversalinit();
  tptr = tetrahedrontraverse();
  elementnumber = firstnumber;
  while (tptr != (tetrahedron *) NULL) {
    p1 = (point3d) tptr[4];
    p2 = (point3d) tptr[5];
    p3 = (point3d) tptr[6];
    p4 = (point3d) tptr[7];
    // Triangle number, indices for three points.
    fprintf(outfile, "%5d   %5d %5d %5d %5d", elementnumber,
            pointmark(p1), pointmark(p2), pointmark(p3), pointmark(p4));
    for (i = 0; i < eextras; i++) {
      fprintf(outfile, "    %.17g", elemattribute(tptr, i));
    }
    fprintf(outfile, "\n");
    tptr = tetrahedrontraverse();
    elementnumber++;
  }

  fprintf(outfile, "# Generated by %s\n", commandline);
  fclose(outfile);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// outelems2gid()    Generate mesh files for viewing by Gid.                 //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::outelems2gid()
{
  FILE *outfile;
  char gidfilename[FILENAMESIZE];
  tetrahedron* tetptr;
  point3d pointloop, p1, p2, p3, p4;;
  int pointnumber, elementnumber;
  int i;

  strcpy(gidfilename, outelefilename);
  strcat(gidfilename, ".gid");

  if (!quiet) {
    printf("Writing %s.\n", gidfilename);
  }
  outfile = fopen(gidfilename, "w");
  if (outfile == (FILE *) NULL) {
    printf("File I/O Error:  Cannot create file %s.\n", gidfilename);
    return;
  }

  fprintf(outfile, "mesh dimension = 3 elemtype tetrahedron nnode = 4\n");
  fprintf(outfile, "coordinates\n");

  points.traversalinit();
  pointloop = pointtraverse();
  pointnumber = 1;  // Gid mesh reader must need first number be '1'.
  while (pointloop != (point3d) NULL) {
    // Point number, x , y and z coordinates.
    fprintf(outfile, "%4d  %.17g %.17g %.17g", pointnumber, pointloop[0],
            pointloop[1], pointloop[2]);
    for (i = 0; i < nextras; i++) {
      // Write an attribute.
      fprintf(outfile, " %.17g", pointloop[i + 3]);
    }
    if (nobound) {
      fprintf(outfile, "\n");
    } else {
      // Write the boundary marker.
      fprintf(outfile, "    %d\n", pointmark(pointloop));
    }
    setpointmark(pointloop, pointnumber);
    pointloop = pointtraverse();
    pointnumber++;
  }

  fprintf(outfile, "end coordinates\n");
  fprintf(outfile, "elements\n");

  tetrahedrons.traversalinit();
  tetptr = tetrahedrontraverse();
  elementnumber = 1;
  while (tetptr != (tetrahedron *) NULL) {
    p1 = (point3d) tetptr[4];
    p2 = (point3d) tetptr[5];
    p3 = (point3d) tetptr[6];
    p4 = (point3d) tetptr[7];
    // tetrahedron number, indices for four points.
    fprintf(outfile, "%5d  %5d %5d %5d %5d", elementnumber,
            pointmark(p1), pointmark(p2), pointmark(p3), pointmark(p4));

    for (i = 0; i < eextras; i++) {
      fprintf(outfile, "  %.17g", elemattribute(tetptr, i));
    }
    fprintf(outfile, "\n");

    tetptr = tetrahedrontraverse();
    elementnumber++;
  }

  fprintf(outfile, "end elements\n");
  fclose(outfile);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// outelems2fa()    Generate mesh files for viewing by FA.                   //
//                                                                           //
// There need three files: .prj, .cor and .elm for FA.                       //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::outelems2fa()
{
  FILE *outfile;
  char fafilename[FILENAMESIZE];
  tetrahedron* tetptr;
  point3d pointloop, p1, p2, p3, p4;;
  int pointnumber, elementnumber;
  int i;

  strcpy(fafilename, outelefilename);
  strcat(fafilename, ".prj");

  if (!quiet) {
    printf("Writing %s.\n", fafilename);
  }
  outfile = fopen(fafilename, "w");
  if (outfile == (FILE *) NULL) {
    printf("File I/O Error:  Cannot create file %s.\n", fafilename);
    return;
  }
  fprintf(outfile, "%s\n", outelefilename);
  fprintf(outfile, "0\n0\n0\n");
  fclose(outfile);

  strcpy(fafilename, outelefilename);
  strcat(fafilename, ".cor");

  if (!quiet) {
    printf("Writing %s.\n", fafilename);
  }
  outfile = fopen(fafilename, "w");
  if (outfile == (FILE *) NULL) {
    printf("File I/O Error:  Cannot create file %s.\n", fafilename);
    return;
  }
  fprintf(outfile, "%d    3\n", points.items);

  points.traversalinit();
  pointloop = pointtraverse();
  pointnumber = 1;  // FA mesh reader must need first number be '1'.
  while (pointloop != (point3d) NULL) {
    // Point number, x , y and z coordinates.
    fprintf(outfile, "%.17g %.17g %.17g\n", pointloop[0],
            pointloop[1], pointloop[2]);
    setpointmark(pointloop, pointnumber);
    pointloop = pointtraverse();
    pointnumber++;
  }
  fclose(outfile);

  strcpy(fafilename, outelefilename);
  strcat(fafilename, ".elm");

  if (!quiet) {
    printf("Writing %s.\n", fafilename);
  }
  outfile = fopen(fafilename, "w");
  if (outfile == (FILE *) NULL) {
    printf("File I/O Error:  Cannot create file %s.\n", fafilename);
    return;
  }
  fprintf(outfile, "%d    5\n", tetrahedrons.items);

  tetrahedrons.traversalinit();
  tetptr = tetrahedrontraverse();
  elementnumber = 1;
  while (tetptr != (tetrahedron *) NULL) {
    p1 = (point3d) tetptr[4];
    p2 = (point3d) tetptr[5];
    p3 = (point3d) tetptr[6];
    p4 = (point3d) tetptr[7];
    // tetrahedron number, indices for four points.
    fprintf(outfile, "%5d %5d %5d %5d",
            pointmark(p1), pointmark(p2), pointmark(p3), pointmark(p4));
    if (eextras > 0) {
      fprintf(outfile, "  %.17g", elemattribute(tetptr, 0) + 1);
    } else {
      fprintf(outfile, "  1");
    }
    fprintf(outfile, "\n");

    tetptr = tetrahedrontraverse();
    elementnumber++;
  }
  fclose(outfile);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// outfaces()    Write the faces to a .face file.                            //
//                                                                           //
// Also use this routine to output hull faces(when hull = 1).                //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::outfaces(int hull)
{
  FILE *outfile;
  triface tface, tsymface;
  face checkmark;
  point3d torg, tdest, tapex;
  int facenumber;

  if (!quiet) {
    printf("Writing %s.\n", facefilename);
  }
  outfile = fopen(facefilename, "w");
  if (outfile == (FILE *) NULL) {
    printf("File I/O Error:  Cannot create file %s.\n", facefilename);
    exit(1);
  }
  // Number of faces, number of boundary markers (zero or one).
  if (hull) {
    fprintf(outfile, "%ld  %d\n", hullsize, 1 - nobound);
  } else {
    fprintf(outfile, "%ld  %d\n", faces, 1 - nobound);
  }

  tetrahedrons.traversalinit();
  tface.tet = tetrahedrontraverse();
  facenumber = firstnumber;
  // To loop over the set of faces, loop over all tetrahedrons, and look at
  //   the four faces of each tetrahedron. If there isn't another
  //   tetrahedron adjacent to the face, operate on the face.  If there is
  //   another adjacent tetrahedron, operate on the face only if the current
  //   tetrahedron has a smaller pointer than its neighbor.  This way, each
  //   face is considered only once.
  // If the 'hull' flag is set, only operate on faces which neighbour is
  //   'dummytet'. This will only output hull faces.
  while (tface.tet != (tetrahedron *) NULL) {
    for (tface.loc = 0; tface.loc < 4; tface.loc ++) {
      sym(tface, tsymface);
      if ((tface.tet < tsymface.tet) || (tsymface.tet == dummytet)) {
        org (tface, torg);
        dest(tface, tdest);
        apex(tface, tapex);
        if (hull) {
          if (tsymface.tet == dummytet) {
            // Only output hull faces.
            fprintf(outfile, "%5d   %4d  %4d  %4d\n", facenumber,
                    pointmark(torg), pointmark(tdest), pointmark(tapex));
            facenumber++;
          }
        } else {
          if (nobound) {
            // Face number, indices of three vertexs.
            fprintf(outfile, "%5d   %4d  %4d  %4d\n", facenumber,
                    pointmark(torg), pointmark(tdest), pointmark(tapex));
          } else {
            // Face number, indices of three vertexs, and a boundary marker.
            //   If there's no shell face, the boundary marker is zero.
            if (useshelles) {
              tspivot(tface, checkmark);
              if ((checkmark.sh == dummysh) || isnonsolid(checkmark)) {
                fprintf(outfile, "%5d   %4d  %4d  %4d  %4d\n", facenumber,
                        pointmark(torg), pointmark(tdest), pointmark(tapex), 0);
              } else {
                fprintf(outfile, "%5d   %4d  %4d  %4d  %4d\n", facenumber,
                        pointmark(torg), pointmark(tdest), pointmark(tapex),
                        mark(checkmark));
              }
            } else {
              fprintf(outfile, "%5d   %4d  %4d  %4d  %4d\n", facenumber,
                      pointmark(torg), pointmark(tdest), pointmark(tapex),
                      tsymface.tet == dummytet);
            }
          }
          facenumber++;
        }
      }
    }
    tface.tet = tetrahedrontraverse();
  }

  fprintf(outfile, "# Generated by %s\n", commandline);
  fclose(outfile);
}

void mesh3d::outfaces2gid(int hull)
{
  FILE *outfile;
  char gidfilename[FILENAMESIZE];
  triface tface, tsymface;
  face checkmark;
  point3d pointloop, torg, tdest, tapex;
  int pointnumber, facenumber, i;

  strcpy(gidfilename, facefilename);
  strcat(gidfilename, ".gid");

  if (!quiet) {
    printf("Writing %s.\n", gidfilename);
  }
  outfile = fopen(gidfilename, "w");
  if (outfile == (FILE *) NULL) {
    printf("File I/O Error:  Cannot create file %s.\n", gidfilename);
    return;
  }

  fprintf(outfile, "mesh dimension = 3 elemtype triangle nnode = 3\n");
  fprintf(outfile, "coordinates\n");

  points.traversalinit();
  pointloop = pointtraverse();
  pointnumber = 1;  // Gid mesh reader must need first number be '1'.
  while (pointloop != (point3d) NULL) {
    // Point number, x , y and z coordinates.
    fprintf(outfile, "%4d  %.17g %.17g %.17g", pointnumber, pointloop[0],
            pointloop[1], pointloop[2]);
    for (i = 0; i < nextras; i++) {
      // Write an attribute.
      fprintf(outfile, " %.17g", pointloop[i + 3]);
    }
    if (nobound) {
      fprintf(outfile, "\n");
    } else {
      // Write the boundary marker.
      fprintf(outfile, "    %d\n", pointmark(pointloop));
    }
    setpointmark(pointloop, pointnumber);
    pointloop = pointtraverse();
    pointnumber++;
  }

  fprintf(outfile, "end coordinates\n");
  fprintf(outfile, "elements\n");

  tetrahedrons.traversalinit();
  tface.tet = tetrahedrontraverse();
  facenumber = 1;
  // To loop over the set of faces, loop over all tetrahedra, and look at
  //   the four faces of each tetrahedron. If there isn't another tetrahedron
  //   adjacent to the face, operate on the face.  If there is another adj-
  //   acent tetrahedron, operate on the face only if the current tetrahedron
  //   has a smaller pointer than its neighbor.  This way, each face is
  //   considered only once.
  // If the 'hull' flag is set, only operate on faces which neighbour is
  //   'dummytet'. This will only output hull faces.
  while (tface.tet != (tetrahedron *) NULL) {
    for (tface.loc = 0; tface.loc < 4; tface.loc ++) {
      sym(tface, tsymface);
      if ((tface.tet < tsymface.tet) || (tsymface.tet == dummytet)) {
        org (tface, torg);
        dest(tface, tdest);
        apex(tface, tapex);
        if (hull) {
          if (tsymface.tet == dummytet) {
            // Only output hull faces.
            fprintf(outfile, "%5d   %d  %d  %d\n", facenumber,
                    pointmark(torg), pointmark(tdest), pointmark(tapex));
            facenumber++;
          }
        } else {
          if (nobound) {
            // Face number, indices of three vertexs.
            fprintf(outfile, "%5d   %d  %d  %d\n", facenumber,
                    pointmark(torg), pointmark(tdest), pointmark(tapex));
          } else {
            // Face number, indices of three vertexs, and a boundary marker.
            //   If there's no shell face, the boundary marker is zero.
            if (useshelles) {
              tspivot(tface, checkmark);
              if (checkmark.sh == dummysh) {
                fprintf(outfile, "%5d   %d  %d  %d  %d\n", facenumber,
                        pointmark(torg), pointmark(tdest), pointmark(tapex), 0);
              } else {
                fprintf(outfile, "%5d   %d  %d  %d  %d\n", facenumber,
                        pointmark(torg), pointmark(tdest), pointmark(tapex),
                        mark(checkmark));
              }
            } else {
              fprintf(outfile, "%5d   %d  %d  %d  %d\n", facenumber,
                      pointmark(torg), pointmark(tdest), pointmark(tapex),
                      tsymface.tet == dummytet);
            }
          }
          facenumber++;
        }
      }
    }
    tface.tet = tetrahedrontraverse();
  }

  fprintf(outfile, "end elements\n");
  fclose(outfile);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// outedges()    Write the edges (segments) to a .edge file.                 //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::outedges()
{
  FILE *outfile;
  face segloop;
  point3d torg, tdest;
  int edgenumber;

  if (!quiet) {
    printf("Writing %s.\n", edgefilename);
  }
  outfile = fopen(edgefilename, "w");
  if (outfile == (FILE *) NULL) {
    printf("File I/O Error:  Cannot create file %s.\n", edgefilename);
    exit(1);
  }
  // Number of edges.
  fprintf(outfile, "%ld\n", subsegs.items);

  subsegs.traversalinit();
  segloop.sh = shellfacetraverse(&subsegs);
  edgenumber = firstnumber;
  while (segloop.sh != (shellface*) NULL) {
    torg = sorg(segloop);
    tdest = sdest(segloop);
    fprintf(outfile, "%5d   %4d  %4d\n", edgenumber,
            pointmark(torg), pointmark(tdest));
    edgenumber++;
    segloop.sh = shellfacetraverse(&subsegs);
  }

  fprintf(outfile, "# Generated by %s\n", commandline);
  fclose(outfile);
}

void mesh3d::outedges2gid()
{
  FILE *outfile;
  char gidfilename[FILENAMESIZE];
  face segloop;
  point3d pointloop, torg, tdest;
  int pointnumber, edgenumber, i;

  strcpy(gidfilename, edgefilename);
  strcat(gidfilename, ".gid");

  if (!quiet) {
    printf("Writing %s.\n", gidfilename);
  }
  outfile = fopen(gidfilename, "w");
  if (outfile == (FILE *) NULL) {
    printf("File I/O Error:  Cannot create file %s.\n", gidfilename);
    return;
  }

  fprintf(outfile, "MESH    dimension 3 ElemType Linear  Nnode 2\n");
  fprintf(outfile, "Coordinates\n");

  points.traversalinit();
  pointloop = pointtraverse();
  pointnumber = 1;  // Gid mesh reader must need first number be '1'.
  while (pointloop != (point3d) NULL) {
    // Point number, x , y and z coordinates.
    fprintf(outfile, "%4d  %.17g %.17g %.17g", pointnumber, pointloop[0],
            pointloop[1], pointloop[2]);
    for (i = 0; i < nextras; i++) {
      // Write an attribute.
      fprintf(outfile, " %.17g", pointloop[i + 3]);
    }
    if (nobound) {
      fprintf(outfile, "\n");
    } else {
      // Write the boundary marker.
      fprintf(outfile, "    %d\n", pointmark(pointloop));
    }
    setpointmark(pointloop, pointnumber);
    pointloop = pointtraverse();
    pointnumber++;
  }

  fprintf(outfile, "end coordinates\n");
  fprintf(outfile, "Elements\n");

  subsegs.traversalinit();
  segloop.sh = shellfacetraverse(&subsegs);
  edgenumber = firstnumber;
  while (segloop.sh != (shellface*) NULL) {
    torg = sorg(segloop);
    tdest = sdest(segloop);
    fprintf(outfile, "%5d   %4d  %4d\n", edgenumber,
            pointmark(torg), pointmark(tdest));
    edgenumber++;
    segloop.sh = shellfacetraverse(&subsegs);
  }

  fprintf(outfile, "end elements\n");
  fclose(outfile);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// outneighbors()    Write neighbor elems to file *.neigh                    //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::outneighbors()
{
  FILE *outfile;
  tetrahedron *tptr;
  triface tetloop, tetsym;
  int elementnumber;
  int neighbor1, neighbor2, neighbor3, neighbor4;

  if (!quiet) {
    printf("Writing %s.\n", neighborfilename);
  }
  outfile = fopen(neighborfilename, "w");
  if (outfile == (FILE *) NULL) {
    printf("File I/O Error:  Cannot create file %s.\n", neighborfilename);
    exit(1);
  }
  // Number of tetrahedra, four faces per tetrahedron.
  fprintf(outfile, "%ld  %d\n", tetrahedrons.items, 4);

  tetrahedrons.traversalinit();
  tptr = tetrahedrontraverse();
  elementnumber = firstnumber;
  while (tptr != (tetrahedron *) NULL) {
    * (int *) (tptr + 8) = elementnumber;
    tptr = tetrahedrontraverse();
    elementnumber++;
  }
  * (int *) (dummytet + 8) = -1;

  tetrahedrons.traversalinit();
  tetloop.tet = tetrahedrontraverse();
  elementnumber = firstnumber;
  while (tetloop.tet != (tetrahedron *) NULL) {
    tetloop.loc = 0;
    sym(tetloop, tetsym);
    neighbor1 = * (int *) (tetsym.tet + 8);
    tetloop.loc = 1;
    sym(tetloop, tetsym);
    neighbor2 = * (int *) (tetsym.tet + 8);
    tetloop.loc = 2;
    sym(tetloop, tetsym);
    neighbor3 = * (int *) (tetsym.tet + 8);
    tetloop.loc = 3;
    sym(tetloop, tetsym);
    neighbor4 = * (int *) (tetsym.tet + 8);
    // Tetrahedra number, neighboring tetrahedron numbers.
    fprintf(outfile, "%4d    %4d  %4d  %4d  %4d\n", elementnumber,
            neighbor1, neighbor2, neighbor3, neighbor4);
    tptr = tetrahedrontraverse();
    elementnumber++;
  }

  fprintf(outfile, "# Generated by %s\n", commandline);
  fclose(outfile);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//  outoff()    Write the triangulation to an .off file.                     //
//                                                                           //
//  OFF stands for the Object File Format, a format used by the Geometry     //
//  Center's Geomview package.                                               //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::outoff()
{
  FILE *outfile;
  triface tface, tsymface;
  point3d pointloop;
  point3d torg, tdest, tapex;

  if (!quiet) {
    printf("Writing %s.\n", offfilename);
  }
  outfile = fopen(offfilename, "w");
  if (outfile == (FILE *) NULL) {
    printf("File I/O Error:  Cannot create file %s.\n", offfilename);
    exit(1);
  }
  // Number of points, faces, and edges(not used, here show hullsize).
  fprintf(outfile, "OFF\n%ld  %ld  %ld\n", points.items, faces, hullsize);

  // Write the points.
  points.traversalinit();
  pointloop = pointtraverse();
  while (pointloop != (point3d) NULL) {
    fprintf(outfile, " %.17g  %.17g  %.17g\n", pointloop[0],
            pointloop[1], pointloop[2]);
    pointloop = pointtraverse();
  }

  tetrahedrons.traversalinit();
  tface.tet = tetrahedrontraverse();
  // To loop over the set of faces, loop over all tetrahedra, and look at
  //   the four faces of each tetrahedron. If there isn't another tetrahedron
  //   adjacent to the face, operate on the face.  If there is another adj-
  //   acent tetrahedron, operate on the face only if the current tetrahedron
  //   has a smaller pointer than its neighbor.  This way, each face is
  //   considered only once.
  // If the 'hull' flag is set, only operate on faces which neighbour is
  //   'dummytet'. This will only output hull faces.
  while (tface.tet != (tetrahedron *) NULL) {
    for (tface.loc = 0; tface.loc < 4; tface.loc ++) {
      sym(tface, tsymface);
      if ((tface.tet < tsymface.tet) || (tsymface.tet == dummytet)) {
        org (tface, torg);
        dest(tface, tdest);
        apex(tface, tapex);
        // Face number, indices of three vertexs.
        fprintf(outfile, "3   %4d  %4d  %4d\n", pointmark(torg) - 1,
                pointmark(tdest) - 1, pointmark(tapex) - 1);
      }
    }
    tface.tet = tetrahedrontraverse();
  }

  fprintf(outfile, "# Generated by %s\n", commandline);
  fclose(outfile);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// dumpallbadelems()    Output all bad elements.                             //
//                                                                           //
// Bad elements include Sliver, Cap, Wedge, Spindle, Needle.                 //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::dumpallbadelems(char* badelemfilename)
{
  FILE *outfile;
  tetrahedron* tetptr;
  point3d pointloop, p1, p2, p3, p4;
  REAL alldihed[6], allsolid[4];
  REAL smallsolid, largesolid;
  REAL smalldihed, largedihed;
  REAL smallestdiangle, biggestdiangle;
  int pointnumber, elementnumber;
  int smalldihedcount, largedihedcount;
  int smallsolidcount, largesolidcount;
  int elemtype;
  int i;

  if (!quiet) {
    printf("Writing %s.\n", badelemfilename);
  }
  outfile = fopen(badelemfilename, "w");
  if (outfile == (FILE *) NULL) {
    printf("File I/O Error:  Cannot create file %s.\n", badelemfilename);
    return;
  }
  smallsolid = 3.;
  largesolid = 300.;
  smalldihed = 20.;
  largedihed = 160.;

  fprintf(outfile, "mesh dimension = 3 elemtype tetrahedron nnode = 4\n");
  fprintf(outfile, "coordinates\n");

  points.traversalinit();
  pointloop = pointtraverse();
  pointnumber = 1;  // Gid mesh reader must need first number be '1'.
  while (pointloop != (point3d) NULL) {
    // Point number, x , y and z coordinates.
    fprintf(outfile, "%4d  %.17g %.17g %.17g", pointnumber, pointloop[0],
            pointloop[1], pointloop[2]);
    for (i = 0; i < nextras; i++) {
      // Write an attribute.
      fprintf(outfile, " %.17g", pointloop[i + 3]);
    }
    if (nobound) {
      fprintf(outfile, "\n");
    } else {
      // Write the boundary marker.
      fprintf(outfile, "    %d\n", pointmark(pointloop));
    }
    setpointmark(pointloop, pointnumber);
    pointloop = pointtraverse();
    pointnumber++;
  }

  fprintf(outfile, "end coordinates\n");
  fprintf(outfile, "elements\n");

  tetrahedrons.traversalinit();
  tetptr = tetrahedrontraverse();
  elementnumber = 1;
  while (tetptr != (tetrahedron *) NULL) {
    p1 = (point3d) tetptr[4];
    p2 = (point3d) tetptr[5];
    p3 = (point3d) tetptr[6];
    p4 = (point3d) tetptr[7];

    tetalldihedral(p1, p2, p3, p4, alldihed);
    smalldihedcount = largedihedcount = 0;
    smallestdiangle = 180;
    biggestdiangle = 0;
    for (i = 0; i < 6; i++) {
      if (alldihed[i] < smallestdiangle) {
        smallestdiangle = alldihed[i];
      } else if (alldihed[i] > biggestdiangle) {
        biggestdiangle = alldihed[i];
      }
      if (alldihed[i] < smalldihed) {
        smalldihedcount++;
      } else if (alldihed[i] > largedihed) {
        largedihedcount++;
      }
    }
    allsolid[0] = alldihed[0] + alldihed[1] + alldihed[2] - 180;
    allsolid[1] = alldihed[0] + alldihed[3] + alldihed[4] - 180;
    allsolid[2] = alldihed[1] + alldihed[3] + alldihed[5] - 180;
    allsolid[3] = alldihed[2] + alldihed[4] + alldihed[5] - 180;
    smallsolidcount = largesolidcount = 0;
    for (i = 0; i < 4; i++) {
      if (allsolid[i] < smallsolid) {
        smallsolidcount++;
      } else if (allsolid[i] > largesolid) {
        largesolidcount++;
      }
    }
    if (largesolidcount >= 1) {
      elemtype = 1; // capcount++;
    } else if ((largedihedcount > 0) && (smalldihedcount > 0)) {
      elemtype = 2; // slivercount++;
    } else if (largedihedcount > 0) {
      elemtype = 3; // spindlecount++;
    } else if (smalldihedcount > 0) {
      elemtype = 4; // wedgecount++;
    } else if (smallsolidcount > 0) {
      elemtype = 5; // needlecount++;
    } else {
      elemtype = 0; // roundcount++;
    }

    if (elemtype) {
      // tetrahedron number, indices for four points.
      fprintf(outfile, "%5d  %5d %5d %5d %5d  %10.6g %10.6g", elementnumber,
              pointmark(p1), pointmark(p2), pointmark(p3), pointmark(p4),
              smallestdiangle, biggestdiangle);
      if (elemtype == 1) {
        fprintf(outfile, "      Cap");
      } else if (elemtype == 2) {
        fprintf(outfile, "      Sliver");
      } else if (elemtype == 3) {
        fprintf(outfile, "      Spindle");
      } else if (elemtype == 4) {
        fprintf(outfile, "      Wedge");
      } else if (elemtype == 5) {
        fprintf(outfile, "      Needle");
      }
      fprintf(outfile, "\n");
    }

    tetptr = tetrahedrontraverse();
    elementnumber++;
  }

  fprintf(outfile, "end elements\n");
  fclose(outfile);
}

///////////////////////////////////////////////////////////////////////////////
// END                                                                       //
// File I/O Routines                                                         //
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// internalerror()    Ask the user to send me the defective product.  Exit.  //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::internalerror()
{
  printf("  Please report this bug to sihang@weboo.com. Include the\n");
  printf("    message above, your input data set, and the exact command\n");
  printf("    line you used to run this program, thank you.\n");
  exit(1);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// precisionerror()    Print an error message for precision problems.        //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::precisionerror()
{
  if (noexact) {
    printf("  This problem maybe caused by the approximate floating-point\n");
    printf("    arthmetic. Try use -X switch in commandline and try again.\n");
  } else {
    printf("  Try increasing the volume criterion and/or increasing the\n");
    printf("    minimum allowable radius-edge ratio so that tiny tetrahedra\n");
    printf("    are not created.\n");
  }
#ifdef SINGLE
  printf("  Alternatively, try recompiling me with double precision\n");
  printf("    arithmetic (by removing \"#define SINGLE\" from the\n");
  printf("    source file or \"-DSINGLE\" from the makefile).\n");
#endif // SINGLE
  exit(1);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// recovererror()      Print an error message for recover problems.          //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::recovererror()
{
  printf("  You met a recover problem in your model. Please check your\n");
  printf("    input PLC facet data, make sure that all coplanar segments,\n");
  printf("    polygons and isolated points are list in this facet.\n");
  printf("  If there still has problem, please report this bug to \n");
  printf("    sihang@weboo.com. Include the message above, your input data\n");
  printf("    set, and the exact command line you used to run this program,\n");
  printf("    thank you.\n");
  exit(1);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// checkmesh()    Test the mesh for topological consistency.                 //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::checkmesh()
{
  triface tetraloop;
  triface oppotet, oppooppotet;
  point3d tetorg, tetdest, tetapex, tetoppo;
  point3d oppoorg, oppodest, oppoapex;
  int horrors;
  int saveexact;

  // Temporarily turn on exact arithmetic if it's off.
  saveexact = noexact;
  noexact = 0;
  if (!quiet) {
    printf("  Checking consistency of mesh...\n");
  }
  if (verbose < 1) {
    numbernodes(1);
  }
  horrors = 0;
  // Run through the list of tetrahedra, checking each one.
  tetrahedrons.traversalinit();
  tetraloop.tet = tetrahedrontraverse();
  while (tetraloop.tet != (tetrahedron *) NULL) {
    // Check all four faces of the tetrahedron.
    for (tetraloop.loc = 0; tetraloop.loc < 4; tetraloop.loc++) {
      org (tetraloop, tetorg);
      dest(tetraloop, tetdest);
      apex(tetraloop, tetapex);
      oppo(tetraloop, tetoppo);
      if (tetraloop.loc == 0) {             // Only test for inversion once.
        if (orient3d(tetorg, tetdest, tetapex, tetoppo) >= 0.0) {
          printf("  !! !! Inverted ");
          dump(&tetraloop);
          horrors++;
        }
      }
      // Find the neighboring tetrahedron on this face.
      sym(tetraloop, oppotet);
      if (oppotet.tet != dummytet) {
        // Check that the tetrahedron's neighbor knows it's a neighbor.
        sym(oppotet, oppooppotet);
        if ((tetraloop.tet != oppooppotet.tet)
            || (tetraloop.loc != oppooppotet.loc)) {
          printf("  !! !! Asymmetric tetra-tetra bond:\n");
          if (tetraloop.tet == oppooppotet.tet) {
            printf("   (Right tetrahedron, wrong orientation)\n");
          }
          printf("    First ");
          dump(&tetraloop);
          printf("    Second (nonreciprocating) ");
          dump(&oppotet);
          horrors++;
        }
        // Check that both tetrahedra agree on the identities
        //   of their shared vertices.
        if (findorg(&oppotet, tetorg)) {
          dest(oppotet, oppodest);
          apex(oppotet, oppoapex);
        } else {
          oppodest = (point3d) NULL;
        }
        if ((tetdest != oppoapex) || (tetapex != oppodest)) {
          printf("  !! !! Mismatched face coordinates between two tetras:\n");
          printf("    First mismatched ");
          dump(&tetraloop);
          printf("    Second mismatched ");
          dump(&oppotet);
          horrors++;
        }
      }
    }
    tetraloop.tet = tetrahedrontraverse();
  }
  if (horrors == 0) {
    if (!quiet) {
      printf("  In my studied opinion, the mesh appears to be consistent.\n");
    }
  } else if (horrors == 1) {
    printf("  !! !! !! !! Precisely one festering wound discovered.\n");
  } else {
    printf("  !! !! !! !! %d abominations witnessed.\n", horrors);
  }
  // Restore the status of exact arithmetic.
  noexact = saveexact;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// checkdelaunay()    Ensure that the mesh is (constrained or conforming)    //
//                    Delaunay.                                              //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::checkdelaunay()
{
  triface tetraloop;
  triface oppotet;
  face opposhelle;
  point3d tetorg, tetdest, tetapex, tetoppo;
  point3d oppooppo;
  int shouldbedelaunay;
  int horrors;
  int saveexact;

  // Temporarily turn on exact arithmetic if it's off.
  saveexact = noexact;
  noexact = 0;
  if (!quiet) {
    printf("  Checking Delaunay property of mesh...\n");
  }
  if (verbose < 1) {
    numbernodes(1);
  }
  horrors = 0;
  // Run through the list of triangles, checking each one.
  tetrahedrons.traversalinit();
  tetraloop.tet = tetrahedrontraverse();
  while (tetraloop.tet != (tetrahedron *) NULL) {
    // Check all three edges of the triangle.
    for (tetraloop.loc = 0; tetraloop.loc < 4; tetraloop.loc++) {
      org(tetraloop, tetorg);
      dest(tetraloop, tetdest);
      apex(tetraloop, tetapex);
      oppo(tetraloop, tetoppo);
      sym(tetraloop, oppotet);
      oppo(oppotet, oppooppo);
      // Only test that the face is locally Delaunay if there is an
      //   adjoining tetrahedron whose pointer is larger (to ensure that
      //   each pair isn't tested twice).
      shouldbedelaunay = (oppotet.tet != dummytet)
                          && (tetoppo != (point3d) NULL)
                          && (oppooppo != (point3d) NULL)
                          && (tetraloop.tet < oppotet.tet);
      if (checksegments && shouldbedelaunay) {
        // If a shell edge separates the triangles, then the edge is
        //   constrained, so no local Delaunay test should be done.
        tspivot(tetraloop, opposhelle);
        if (opposhelle.sh != dummysh){
          if (!isnonsolid(opposhelle)) {
            shouldbedelaunay = 0;
          }
        }
      }
      if (shouldbedelaunay) {
        if (iinsphere(tetdest, tetorg, tetapex, tetoppo, oppooppo) > 0) {
          printf("  !! !! Non-Delaunay pair of triangles:\n");
          printf("    First non-Delaunay ");
          dump(&tetraloop);
          printf("    Second non-Delaunay ");
          dump(&oppotet);
          horrors++;
        }
      }
    }
    tetraloop.tet = tetrahedrontraverse();
  }
  if (horrors == 0) {
    if (!quiet) {
      printf(
  "  By virtue of my perceptive intelligence, I declare the mesh Delaunay.\n");
    }
  } else if (horrors == 1) {
    printf(
         "  !! !! !! !! Precisely one terrifying transgression identified.\n");
  } else {
    printf("  !! !! !! !! %d obscenities viewed with horror.\n", horrors);
  }
  // Restore the status of exact arithmetic.
  noexact = saveexact;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// checkshells()       Test the shells of mesh for topological consistency.  //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::checkshells()
{
  triface oppotet, oppooppotet;
  triface testtet, spintet;
  face shloop, testsh;
  face segloop, testseg;
  point3d tapex, spapex;
  int hitbdry, edgecount;
  int horrors;

  if (!quiet) {
    printf("  Checking subfaces-tetrahedra connection...\n");
  }
  if (verbose < 1) {
    numbernodes(1);
  }
  horrors = 0;
  subfaces.traversalinit();
  shloop.sh = shellfacetraverse(&subfaces);
  while (shloop.sh != (shellface *) NULL) {
    shloop.shver = 0;
    stpivot(shloop, oppotet);
    if (oppotet.tet != dummytet) {
      tspivot(oppotet, testsh);
      if (testsh.sh != shloop.sh) {
        printf("  !! !! Wrong tetra-subface connection.\n");
        printf("    Tetra: ");
        dump(&oppotet);
        printf("    Subface: ");
        dump(&shloop);
        horrors++;
      }
    }
    sesymself(shloop);
    stpivot(shloop, oppooppotet);
    if (oppooppotet.tet != dummytet) {
      tspivot(oppooppotet, testsh);
      if (testsh.sh != shloop.sh) {
        printf("  !! !! Wrong tetra-subface connection.\n");
        printf("    Tetra: ");
        dump(&oppooppotet);
        printf("    Subface: ");
        dump(&shloop);
        horrors++;
      }
      if (oppotet.tet != dummytet) {
        sym(oppotet, testtet);
        if (testtet.tet != oppooppotet.tet) {
          printf("  !! !! Wrong tetra-subface-tetra connection.\n");
          printf("    Tetra 1: ");
          dump(&oppotet);
          printf("    Subface: ");
          dump(&shloop);
          printf("    Tetra 2: ");
          dump(&oppooppotet);
          horrors++;
        }
      }
    }
    shloop.sh = shellfacetraverse(&subfaces);
  }
  if (horrors == 0) {
    if (!quiet) {
      printf("  Subfaces-tetrahedra connected correctly.\n");
    }
  } else if (horrors == 1) {
    printf(
    "  !! !! !! !! Precisely one terrifying subface-tetrahedron identified.\n");
  } else {
    printf("  !! !! !! !! %d subface-tetrahedron viewed with horror.\n",
           horrors);
    return;
  }

  if (!quiet) {
    printf("  Checking Subfaces-subsegments connection...\n");
  }
  horrors = 0;
  horrors = 0;
  subfaces.traversalinit();
  shloop.sh = shellfacetraverse(&subfaces);
  while (shloop.sh != (shellface *) NULL) {
    shloop.shver = 0;
    for (edgecount = 0; edgecount < 3; edgecount++) {
      senextself(shloop);
      sspivot(shloop, testseg);
      if (testseg.sh != dummysh) {
        if (!((sorg(shloop) == sorg(testseg))
              && (sdest(shloop) == sdest(testseg)))
            && !((sorg(shloop) == sdest(testseg))
                 && (sdest(shloop) == sorg(testseg)))) {
          printf("  !! !! Wrong subface-subsegment connection.\n");
          printf("    Subface: ");
          dump(&shloop);
          printf("    Subsegment: ");
          dump(&testseg);
          horrors++;
        }
      }
    }
    shloop.sh = shellfacetraverse(&subfaces);
  }
  if (horrors == 0) {
    if (!quiet) {
      printf("  Subfaces-subsegments connected correctly.\n");
    }
  } else if (horrors == 1) {
    printf(
    "  !! !! !! !! Precisely one terrifying subface-subsegments identified.\n");
  } else {
    printf("  !! !! !! !! %d subface-subsegments viewed with horror.\n",
           horrors);
    return;
  }

  if (!quiet) {
    printf("  Checking Subsegments connection...\n");
  }
  horrors = 0;
  subsegs.traversalinit();
  segloop.sh = shellfacetraverse(&subsegs);
  while (segloop.sh != (shellface *) NULL) {
    segloop.shver = 0;
    sapex(segloop, spapex);
    if (spapex != (point3d) NULL) {
      printf("  !! !! Detect a subface in subsegs pool(apex() != NULL).\n");
      printf("    Wrong : ");
      dump(&segloop);
      horrors++;
      segloop.sh = shellfacetraverse(&subsegs);
      continue;
    }
    spivot(segloop, testsh);
    if (testsh.sh == dummysh) {
      printf("  !! !! A subsegment missing its parent subface.\n ");
      printf("    Wrong : ");
      dump(&segloop);
      horrors++;
      segloop.sh = shellfacetraverse(&subsegs);
      continue;
    }
    sspivot(testsh, testseg);
    if (testseg.sh != segloop.sh) {
      printf("  !! !! Wrong subface-subsegment connection.\n ");
      printf("    Wrong : ");
      dump(&testsh);
      printf("    Wrong : ");
      dump(&segloop);
      horrors++;
      segloop.sh = shellfacetraverse(&subsegs);
      continue;
    }
    stpivot(testsh, testtet);
    if (testtet.tet == dummytet) {
      sesymself(testsh);
      stpivot(testsh, testtet);
      if (testtet.tet == dummytet) {
        printf("  !! !! Parent subface not bonded to a valid tetrahedron.\n ");
        printf("    Wrong : ");
        dump(&testsh);
        horrors++;
        segloop.sh = shellfacetraverse(&subsegs);
        continue;
      }
    }
    findversion(&testtet, &testseg);
    spintet = testtet;
    apex(testtet, tapex);
    hitbdry = 0;
    while (true) {
      if (fnextself(spintet)) {
        apex(spintet, spapex);
        if (spapex == tapex) {
          break; // Rewind, can leave now.
        }
        tspivot(spintet, testsh);
        if (testsh.sh != dummysh) {
          findversion(&testsh, &spintet);
          sspivot(testsh, testseg);
          if (testseg.sh == dummysh) {
            printf("  !! !! Subface miss bond a subsegment.\n");
            printf("    Miss bond : ");
            dump(&testsh);
            printf("    Miss : ");
            dump(&segloop);
            horrors++;
          } else if (testseg.sh != segloop.sh) {
            printf("  !! !! Wrong subface-subsegment bond.\n");
            printf("    Wrong : ");
            dump(&testsh);
            printf("    Wrong : ");
            dump(&segloop);
            horrors++;
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
    segloop.sh = shellfacetraverse(&subsegs);
  }
  if (horrors == 0) {
    if (!quiet) {
      printf("  Subsegments connected correctly.\n");
    }
  } else if (horrors == 1) {
    printf(
    "  !! !! !! !! Precisely one terrifying subsegment identified.\n");
  } else {
    printf("  !! !! !! !! %d subsegments viewed with horror.\n", horrors);
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// quality_statistics()    Print statistics about the quality of the mesh.   //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::quality_statistics()
{
  triface tetloop;
  point3d p[4];
  REAL ratiotable[16];
  REAL dx[6], dy[6], dz[6];
  REAL edgelength[6];
  REAL alldihed[6], allsolid[4];
  REAL tetvol;
  REAL tetlongest2;
  REAL shortest, longest;
  REAL smallestvolume, biggestvolume;
  REAL tetminaltitude2;
  REAL minaltitude;
  REAL tetaspect2;
  REAL worstaspect;
  REAL smallestdiangle, biggestdiangle;
  REAL smallsolid, largesolid;
  REAL smalldihed, largedihed;
  unsigned long roundcount, slivercount, capcount;
  unsigned long needlecount, wedgecount, spindlecount;
  int dihedangletable[18];
  int aspecttable[16];
  int aspectindex;
  int tendegree;
  int smallsolidcount, largesolidcount;
  int smalldihedcount, largedihedcount;
  int i, ii, j, k;

  printf("Mesh quality statistics:\n\n");

  ratiotable[0]  =      1.5;      ratiotable[1]  =     2.0;
  ratiotable[2]  =      2.5;      ratiotable[3]  =     3.0;
  ratiotable[4]  =      4.0;      ratiotable[5]  =     6.0;
  ratiotable[6]  =     10.0;      ratiotable[7]  =    15.0;
  ratiotable[8]  =     25.0;      ratiotable[9]  =    50.0;
  ratiotable[10] =    100.0;      ratiotable[11] =   300.0;
  ratiotable[12] =   1000.0;      ratiotable[13] = 10000.0;
  ratiotable[14] = 100000.0;      ratiotable[15] =     0.0;
  for (i = 0; i < 16; i++) {
    aspecttable[i] = 0;
  }
  for (i = 0; i < 18; i++) {
    dihedangletable[i] = 0;
  }

  worstaspect = 0.0;
  minaltitude = xmax - xmin + ymax - ymin + zmax - zmin;
  minaltitude = minaltitude * minaltitude;
  shortest = minaltitude;
  longest = 0.0;
  smallestvolume = minaltitude;
  biggestvolume = 0.0;
  worstaspect = 0.0;
  smallestdiangle = 180.0;
  biggestdiangle = 0.0;
  smallsolid = 3.;
  largesolid = 300.;
  smalldihed = 18.;
  largedihed = 162.;
  roundcount = slivercount = 0l;
  capcount = spindlecount = wedgecount = needlecount = 0;

  tetrahedrons.traversalinit();
  tetloop.tet = tetrahedrontraverse();
  while (tetloop.tet != (tetrahedron *) NULL) {
    org (tetloop, p[0]);
    dest(tetloop, p[1]);
    apex(tetloop, p[2]);
    oppo(tetloop, p[3]);
    tetlongest2 = 0.0;

    for (i = 0; i < 3; i++) {
      j = plus1mod3[i];
      k = minus1mod3[i];
      dx[i] = p[j][0] - p[k][0];
      dy[i] = p[j][1] - p[k][1];
      dz[i] = p[j][2] - p[k][2];
      edgelength[i] = dx[i] * dx[i] + dy[i] * dy[i] + dz[i] * dz[i];
      if (edgelength[i] > tetlongest2) {
        tetlongest2 = edgelength[i];
      }
      if (edgelength[i] > longest) {
        longest = edgelength[i];
      }
      if (edgelength[i] < shortest) {
        shortest = edgelength[i];
      }
    }

    for (i = 3; i < 6; i++) {
      j = i - 3;
      k = 3;
      dx[i] = p[j][0] - p[k][0];
      dy[i] = p[j][1] - p[k][1];
      dz[i] = p[j][2] - p[k][2];
      edgelength[i] = dx[i] * dx[i] + dy[i] * dy[i] + dz[i] * dz[i];
      if (edgelength[i] > tetlongest2) {
        tetlongest2 = edgelength[i];
      }
      if (edgelength[i] > longest) {
        longest = edgelength[i];
      }
      if (edgelength[i] < shortest) {
        shortest = edgelength[i];
      }
    }

    tetvol = tetvolume(p[0], p[1], p[2], p[3]);
    if (tetvol < 0) tetvol = -tetvol;
    if (tetvol < smallestvolume) {
      smallestvolume = tetvol;
    }
    if (tetvol > biggestvolume) {
      biggestvolume = tetvol;
    }

    tetalldihedral(p[0], p[1], p[2], p[3], alldihed);
    smalldihedcount = largedihedcount = 0;
    for (i = 0; i < 6; i++) {
      if (alldihed[i] < smallestdiangle) {
        smallestdiangle = alldihed[i];
      } else if (alldihed[i] > biggestdiangle) {
        biggestdiangle = alldihed[i];
      }
      if (alldihed[i] < smalldihed) {
        smalldihedcount++;
      } else if (alldihed[i] > largedihed) {
        largedihedcount++;
      }
      tendegree = (int) (alldihed[i] / 10.);
      dihedangletable[tendegree]++;
    }
    allsolid[0] = alldihed[0] + alldihed[1] + alldihed[2] - 180;
    allsolid[1] = alldihed[0] + alldihed[3] + alldihed[4] - 180;
    allsolid[2] = alldihed[1] + alldihed[3] + alldihed[5] - 180;
    allsolid[3] = alldihed[2] + alldihed[4] + alldihed[5] - 180;
    smallsolidcount = largesolidcount = 0;
    for (i = 0; i < 4; i++) {
      if (allsolid[i] < smallsolid) {
        smallsolidcount++;
      } else if (allsolid[i] > largesolid) {
        largesolidcount++;
      }
    }
    if (largesolidcount >= 1) {
      capcount++;
    } else if ((largedihedcount > 0) && (smalldihedcount > 0)) {
      slivercount++;
    } else if (largedihedcount > 0) {
      spindlecount++;
    } else if (smalldihedcount > 0) {
      wedgecount++;
    } else if (smallsolidcount > 0) {
      needlecount++;
    } else {
      roundcount++;
    }

    tetloop.tet = tetrahedrontraverse();
  }

  shortest = sqrt(shortest);
  longest = sqrt(longest);
  minaltitude = sqrt(minaltitude);
  worstaspect = sqrt(worstaspect);

  printf("  Smallest volume: %16.5g   |  Largest volume: %16.5g\n",
         smallestvolume, biggestvolume);
  printf("  Shortest edge:   %16.5g   |  Longest edge:   %16.5g\n",
         shortest, longest);
  printf("\n");
  printf("  Smallest dihedral: %14.5g   |  Largest dihedral: %14.5g\n\n",
         smallestdiangle, biggestdiangle);
  printf("  Dihedral Angle histogram:\n");
  for (i = 0; i < 9; i++) {
    printf("      %3d - %3d degrees:  %8d    |    %3d - %3d degrees:  %8d\n",
           i * 10, i * 10 + 10, dihedangletable[i],
           i * 10 + 90, i * 10 + 100, dihedangletable[i + 9]);
  }
  printf("\n");

  printf("  Shape histogram:\n\n");
  printf("    Sliver:  %d\n", slivercount);
  printf("    Needle:  %d\n", needlecount);
  printf("    Spindle: %d\n", spindlecount);
  printf("    Wedge:   %d\n", wedgecount);
  printf("    Cap:     %d\n\n", capcount);
  printf("  There are %d bad elements among %d elements.\n",
         slivercount + needlecount + spindlecount + wedgecount + capcount,
         tetrahedrons.items);

  printf("\n");
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// statistics()    Print all sorts of cool facts.                            //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::statistics()
{
  printf("\nStatistics:\n\n");
  printf("  Input points: %d\n", inpoints);
  if (refine) {
    printf("  Input tetrahedra: %d\n", inelements);
  }
  if (poly) {
    printf("  Input facets: %d\n", infacets);
    if (!refine) {
      printf("  Input holes: %d\n", holes);
    }
  }

  printf("\n  Mesh points: %ld\n", points.items);
  printf("  Mesh tetrahedra: %ld\n", tetrahedrons.items);
  printf("  Mesh faces: %ld\n", faces);
  if (poly || refine) {
    printf("  Mesh boundary faces: %ld\n", hullsize);
    printf("  Mesh subfaces: %ld (include nonsolids)\n", subfaces.items);
    printf("  Mesh subsegments: %ld\n\n", subsegs.items);
  } else {
    printf("  Mesh convex hull faces: %ld\n\n", hullsize);
  }
  if (verbose) {
    if (quality) {
      quality_statistics();
    }
    printf("Memory allocation statistics:\n\n");
    printf("  Maximum number of points: %ld\n", points.maxitems);
    printf("  Maximum number of tetrahedra: %ld\n", tetrahedrons.maxitems);
    if (subfaces.maxitems > 0) {
      printf("  Maximum number of subfaces: %ld\n", subfaces.maxitems);
    }
    if (subsegs.maxitems > 0) {
      printf("  Maximum number of segments: %ld\n", subsegs.maxitems);
    }
    if (viri.maxitems > 0) {
      printf("  Maximum number of viri: %ld\n", viri.maxitems);
    }
    if (badfaces.maxitems > 0) {
      printf("  Maximum number of encroached subfaces: %ld\n",
             badfaces.maxitems);
    }
    if (badsegments.maxitems > 0) {
      printf("  Maximum number of encroached segments: %ld\n",
             badsegments.maxitems);
    }
    if (badtets.maxitems > 0) {
      printf("  Maximum number of bad tetrahedra: %ld\n", badtets.maxitems);
    }
    printf("  Approximate heap memory use (bytes): %ld\n\n",
           points.maxitems * points.itembytes
           + tetrahedrons.maxitems * tetrahedrons.itembytes
           + subfaces.maxitems * subfaces.itembytes
           + subsegs.maxitems * subsegs.itembytes
           + viri.maxitems * viri.itembytes
           + badfaces.maxitems * badfaces.itembytes
           + badsegments.maxitems * badsegments.itembytes
           + badtets.maxitems * badtets.itembytes);

    printf("Algorithmic statistics:\n\n");
    printf("  Number of insphere tests: %ld\n", inspherecount);
    printf("  Number of orientation tests: %ld\n", orient3dcount);
    if (segmentintersectioncount > 0) {
      printf("  Number of segment intersections: %ld\n",
             segmentintersectioncount);
    }
    printf("\n");
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// syntax()    Print list of command line switches.                          //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::syntax()
{
  printf("tetgen [-pq__a__AnfcgBPNEIOXzS__T__CQVh] input_file\n");
  printf("    -p  Triangulates a Piecewise Linear Complex (.poly file).\n");
  printf("    -q  Quality mesh generation. Use Shewchuk's Delaunay Refinement\n");
  printf("        Algorithm. A minimum radius-edge ratio may be specified.\n");
  printf("    -a  Applies a maximum tetrahedron volume constraint.\n");
  printf("    -A  Applies attributes to identify elements in certain regions.\n");
  printf("    -f  Generates a list of tetrahedron faces.\n");
  printf("    -e  Generates a list of edges (segments).\n");
  printf("    -c  Generates a list of convex hull faces.\n");
  printf("    -n  Generates a list of tetrahedron neighbors.\n");
  printf("    -g  Generates file for viewing mesh by Geomview(*.off) or Gid.\n");
  printf("    -B  Suppresses output of boundary information.\n");
  printf("    -P  Suppresses output of .poly file.\n");
  printf("    -N  Suppresses output of .node file.\n");
  printf("    -E  Suppresses output of .ele file.\n");
  printf("    -I  Suppresses mesh iteration numbers.\n");
  printf("    -O  Ignores holes in .poly file.\n");
  printf("    -X  Use exact arithmetic to perform geometric predicates.\n");
  printf("    -z  Numbers all items starting from zero (rather than one).\n");
  printf("    -S  Specifies maximum number of added Steiner points.\n");
  printf("    -T  Specifies the tolerance for round-to-zero.\n");
  printf("    -C  Check consistency of final mesh.\n");
  printf("    -Q  Quiet:  No terminal output except errors.\n");
  printf("    -V  Verbose:  Detailed information on what I'm doing.\n");
  printf("    -h  Help:  Detailed instructions for Tetgen.\n");
  exit(0);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// meshinit()     Initialize some variables.                                 //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::meshinit()
{
  recenttet.tet = (tetrahedron*) NULL;     // No tetra has been visited yet.
  samples = 1;            // Point location should take at least one sample.
  checksegments = 0;      // There are no segments in the triangulation yet.
  randomseed = 1;
  usefliplist = 0;
  shflaws = shsegflaws = tetflaws = 0;
  fliplist = NULL;
  dummytetbase = dummyshbase = NULL;
  surfmesh = NULL;

  // Init statistic variables.
  flip_t23s = flip_t32s = flip_t22s = flip_t44s = 0;
  cospherecount = segmentintersectioncount = 0l;
  inspherecount = orient3dcount = 0l;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// meshdeinit()     Free all remaining allocated memory.                     //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::meshdeinit()
{
  tetrahedrons.deinit();
  if (dummytetbase) {
    delete [] dummytetbase;
  }
  if (useshelles) {
    subfaces.deinit();
    subsegs.deinit();
    if (dummyshbase) {
      delete [] dummyshbase;
    }
  }
  points.deinit();
  if (poly && faces) {
    badsegments.deinit();
  }
  if (quality) {
    badfaces.deinit();
    if ((minratio > 0.0) || varvolume || fixedvolume) {
      badtets.deinit();
    }
  }
  if (fliplist) {
    delete fliplist;
  }
  if (surfmesh) {
    delete surfmesh;
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// parsecommandline()    Read the command line, identify switches, and set   //
//                       up options and file names.                          //
//                                                                           //
// The effects of this routine are felt entirely through global variables.   //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::parsecommandline(int argc, char **argv)
{
  int startindex;
  int increment;
  int meshnumber;
  int i, j, k;
  char workstring[FILENAMESIZE];

  poly = smesh = 0;
  refine = quality = varvolume = fixedvolume = regionattrib = convex = 0;
  firstnumber = 1;
  facesout = edgesout = voronoi = neighbors = geomview = 0;
  nobound = nopolywritten = nonodewritten = noelewritten = noiterationnum = 0;
  noholes = nobisect = 0;
  noexact = 1;   // default vaule, not use exact arithmetic.
  splitseg = 1;  // default value in 3D case.
  docheck = 0;
  steiner = -1;
  minratio = 2.0;  // Default radius-edge ratio.
  maxvolume = -1.0;
  noroundoff = 0;
  usertolerance = 1e-12;    // default tolerance.
  userubtolerance = 1e-10;
  badelemreport = 0;
  quiet = verbose = 0;
  innodefilename[0] = '\0';
  commandline[0] = '\0';

  startindex = 1;
  strcpy(commandline, argv[0]);
  strcat(commandline, " ");
  for (i = startindex; i < argc; i++) {
    if (argv[i][0] == '-') {
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
            minratio = (REAL) strtod(workstring, (char **) NULL);
            if (minratio <= 0.0) {
              printf("Command line Error:  After -q switch, the minimum");
              printf(" radius-edge ratio must greater than Zero.\n");
              exit(1);
            }
          } else {
            minratio = 2; // Default radius-edge ratio.
          }
        }
        if (argv[i][j] == 'a') {
          quality = 1;
          if (((argv[i][j + 1] >= '0') && (argv[i][j + 1] <= '9')) ||
              (argv[i][j + 1] == '.')) {
            fixedvolume = 1;
            k = 0;
            while (((argv[i][j + 1] >= '0') && (argv[i][j + 1] <= '9')) ||
                   (argv[i][j + 1] == '.')) {
              j++;
              workstring[k] = argv[i][j];
              k++;
            }
            workstring[k] = '\0';
            maxvolume = (REAL) strtod(workstring, (char **) NULL);
            if (maxvolume <= 0.0) {
              printf("Command line Error:  After -a switch, the maximum");
              printf(" volume constraints must greater than Zero.\n");
              exit(1);
            }
          } else {
            varvolume = 1;
          }
        }
        if (argv[i][j] == 'A') {
          regionattrib = 1;
        }
        if (argv[i][j] == 'c') {
          convex = 1;
        }
        if (argv[i][j] == 's') {
          splitseg = 0;
        }
        if (argv[i][j] == 'z') {
          firstnumber = 0;
        }
        if (argv[i][j] == 'f') {
          facesout = 1;
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
          noexact = 0; // Use exact arithmetic.
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
        if (argv[i][j] == 'T') {
          if (((argv[i][j + 1] >= '0') && (argv[i][j + 1] <= '9')) ||
              (argv[i][j + 1] == '.')) {
            k = 0;
            while (((argv[i][j + 1] >= '0') && (argv[i][j + 1] <= '9')) ||
                   (argv[i][j + 1] == '.') || (argv[i][j + 1] == 'e') ||
                   (argv[i][j + 1] == '-') || (argv[i][j + 1] == '+')) {
              j++;
              workstring[k] = argv[i][j];
              k++;
            }
            workstring[k] = '\0';
            usertolerance = (REAL) strtod(workstring, (char **) NULL);
            if (usertolerance <= 0.0) {
              printf("Command line Error:  After -T switch, tolerance");
              printf(" must greater than Zero.\n");
              exit(1);
            }
            userubtolerance = usertolerance * 1e+2;
          }
        }
        if (argv[i][j] == 'F') {
          noroundoff = 1;
        }
        if (argv[i][j] == 'b') {
          badelemreport = 1;
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
          syntax();
        }
      }
    } else {
      strncpy(innodefilename, argv[i], FILENAMESIZE - 1);
      innodefilename[FILENAMESIZE - 1] = '\0';
    }
    strcat(commandline, argv[i]);
    strcat(commandline, " ");
  }
  commandline[FILENAMESIZE - 1] = '\0';
  if (innodefilename[0] == '\0') {
    syntax();
  }
  if (!strcmp(&innodefilename[strlen(innodefilename) - 5], ".node")) {
    innodefilename[strlen(innodefilename) - 5] = '\0';
  }
  if (!strcmp(&innodefilename[strlen(innodefilename) - 5], ".poly")) {
    innodefilename[strlen(innodefilename) - 5] = '\0';
    poly = 1;
    smesh = 0;
  }
  if (!strcmp(&innodefilename[strlen(innodefilename) - 6], ".smesh")) {
    innodefilename[strlen(innodefilename) - 6] = '\0';
    smesh = 1;
    poly = 0;
  }
  if (!strcmp(&innodefilename[strlen(innodefilename) - 4], ".ele")) {
    innodefilename[strlen(innodefilename) - 4] = '\0';
    refine = 1;
  }
  if (!strcmp(&innodefilename[strlen(innodefilename) - 7], ".volume")) {
    innodefilename[strlen(innodefilename) - 5] = '\0';
    refine = 1;
    quality = 1;
    varvolume = 1;
  }
  steinerleft = steiner;
  useshelles = poly || smesh || refine || quality || convex;
  goodratio = minratio;
  goodratio *= goodratio;
  if (refine && noiterationnum) {
    printf("Command line Error:  You cannot use the -I switch when");
    printf(" refining a triangulation.\n");
    exit(1);
  }
  // Be careful not to allocate space for element volume constraints that
  //   will never be assigned any value (other than the default -1.0).
  if (!refine && !poly && !smesh) {
    varvolume = 0;
  }
  // Be careful not to add an extra attribute to each element unless the
  //   input supports it (PLC in, but not refining a preexisting mesh).
  if (refine || (!poly && !smesh)) {
    regionattrib = 0;
  }

  strcpy(inpolyfilename, innodefilename);
  strcpy(insmeshfilename, innodefilename);
  strcpy(inelefilename, innodefilename);
  strcpy(volumefilename, innodefilename);
  increment = 0;
  strcpy(workstring, innodefilename);
  j = 1;
  while (workstring[j] != '\0') {
    if ((workstring[j] == '.') && (workstring[j + 1] != '\0')) {
      increment = j + 1;
    }
    j++;
  }
  meshnumber = 0;
  if (increment > 0) {
    j = increment;
    do {
      if ((workstring[j] >= '0') && (workstring[j] <= '9')) {
        meshnumber = meshnumber * 10 + (int) (workstring[j] - '0');
      } else {
        increment = 0;
      }
      j++;
    } while (workstring[j] != '\0');
  }
  if (noiterationnum) {
    strcpy(outnodefilename, innodefilename);
    strcpy(outelefilename, innodefilename);
    strcpy(facefilename, innodefilename);
    strcpy(edgefilename, innodefilename);
    strcpy(neighborfilename, innodefilename);
    strcpy(offfilename, innodefilename);
    strcat(outnodefilename, ".node");
    strcat(outelefilename, ".ele");
    strcat(facefilename, ".face");
    strcat(edgefilename, ".edge");
    strcat(neighborfilename, ".neigh");
    strcat(offfilename, ".off");
  } else if (increment == 0) {
    strcpy(outnodefilename, innodefilename);
    strcpy(outpolyfilename, innodefilename);
    strcpy(outelefilename, innodefilename);
    strcpy(facefilename, innodefilename);
    strcpy(edgefilename, innodefilename);
    strcpy(neighborfilename, innodefilename);
    strcpy(offfilename, innodefilename);
    strcat(outnodefilename, ".1.node");
    strcat(outpolyfilename, ".1.poly");
    strcat(outelefilename, ".1.ele");
    strcat(facefilename, ".1.face");
    strcat(edgefilename, ".1.edge");
    strcat(neighborfilename, ".1.neigh");
    strcat(offfilename, ".1.off");
  } else {
    workstring[increment] = '%';
    workstring[increment + 1] = 'd';
    workstring[increment + 2] = '\0';
    sprintf(outnodefilename, workstring, meshnumber + 1);
    strcpy(outpolyfilename, outnodefilename);
    strcpy(outelefilename, outnodefilename);
    strcpy(facefilename, outnodefilename);
    strcpy(edgefilename, outnodefilename);
    strcpy(neighborfilename, outnodefilename);
    strcpy(offfilename, outnodefilename);
    strcat(outnodefilename, ".node");
    strcat(outpolyfilename, ".poly");
    strcat(outelefilename, ".ele");
    strcat(facefilename, ".face");
    strcat(edgefilename, ".edge");
    strcat(neighborfilename, ".neigh");
    strcat(offfilename, ".off");
  }
  strcat(innodefilename, ".node");
  strcat(inpolyfilename, ".poly");
  strcat(insmeshfilename, ".smesh");
  strcat(inelefilename, ".ele");
  strcat(volumefilename, ".volume");
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// triangulate()   Gosh, do everything.                                      //
//                                                                           //
// The sequence is roughly as follows.  Many of these steps can be skipped,  //
// depending on the command line switches.                                   //
//                                                                           //
// - Initialize constants and parse the command line.                        //
// - Read the points from a file and either                                  //
//   - triangulate them                                                      //
// - Insert the PLC segments and subfaces (-p).                              //
// - Read the holes (-p), regional attributes (-pA), and regional area       //
//     constraints (-pa).  Carve the holes and concavities, and spread the   //
//     regional attributes and area constraints.                             //
// - Enforce the constraints on minimum angle (-q) and maximum area (-a).    //
//     Also enforce the conforming Delaunay property (-q and -a).            //
// - Compute the number of edges in the resulting mesh.                      //
// - Write the output files and print the statistics.                        //
// - Check the consistency and Delaunay property of the mesh (-C).           //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::triangulate(int argc, char **argv)
{
  REAL *holearray;                                        // Array of holes.
  REAL *regionarray;   // Array of regional attributes and area constraints.
  FILE *polyfile;
  // Variables for timing the performance of Tetrahedra.
#ifndef NO_TIMER
  // The types are defined in sys/time.h.
  struct timeval tv0, tv1, tv2, tv3, tv4, tv5, tv6;
  struct timezone tz;
#else  // NO_TIMER
  // The types are defined in time.h.
  clock_t tv0, tv1, tv2, tv3, tv4, tv5, tv6;
#endif // NO_TIMER

#ifndef NO_TIMER
  gettimeofday(&tv0, &tz);
#else  // NO_TIMER
  tv0 = clock();
#endif // NO_TIMER

  exactinit();                     // Initialize exact arithmetic constants.
  parsecommandline(argc, argv);
  readnodes(&polyfile);

  if (verbose > 1) {
    // Number the points first when "-VV" or "-VVV" switch be set, so that
    //   the debug functions can output point indices for you.
    numbernodes(1);
  }

  if (!quiet) {
#ifndef NO_TIMER
    gettimeofday(&tv1, &tz);
#else  // NO_TIMER
    tv1 = clock();
#endif // NO_TIMER
  }

  if (refine) {
    // Read and reconstruct a mesh.
    printf("Sorry, the -r switch has not been implemented now.\n");
    exit(1);
  } else {
    hullsize = delaunay();                        // Triangulate the points.
  }

  if (!quiet) {
    if (refine) {
      printf("Mesh reconstruction");
    } else {
      printf("Delaunay");
    }
#ifndef NO_TIMER
    gettimeofday(&tv2, &tz);
    printf(" milliseconds:  %ld\n", 1000l * (tv2.tv_sec - tv1.tv_sec)
           + (tv2.tv_usec - tv1.tv_usec) / 1000l);
#else  // NO_TIMER
    tv2 = clock();
    printf(" milliseconds:  %g\n", 1000l * (tv2 - tv1) / (REAL) CLK_TCK);
#endif // NO_TIMER
  }

  if (useshelles) {
    checksegments = 1;                  // Segments will be introduced next.
    if (!refine) {
      // Insert PLC segments/facets and/or convex hull segments/facets.
      infacets = formskeleton(polyfile);
      if (docheck) {
        checkshells();
      }
    }
  }

  if (!quiet) {
#ifndef NO_TIMER
    gettimeofday(&tv3, &tz);
    if (useshelles && !refine) {
      printf("Segment and facet milliseconds:  %ld\n",
             1000l * (tv3.tv_sec - tv2.tv_sec)
             + (tv3.tv_usec - tv2.tv_usec) / 1000l);
    }
#else  // NO_TIMER
    tv3 = clock();
    if (useshelles && !refine) {
      printf("Segment and facet milliseconds:  %g\n",
             1000l * (tv3 - tv2) / (REAL) CLK_TCK);
    }
#endif // NO_TIMER
  }

  if (poly || smesh) {
    readholes(polyfile, &holearray, &holes, &regionarray, &regions);
    if (!refine) {
      // Carve out holes and concavities.
      carveholes(holearray, holes, regionarray, regions);
    }
  } else {
    // Without a PLC, there can be no holes or regional attributes
    //   or area constraints.  The following are set to zero to avoid
    //   an accidental free later.
    holes = 0;
    regions = 0;
  }

  if (!quiet) {
#ifndef NO_TIMER
    gettimeofday(&tv4, &tz);
    if (poly && !refine) {
      printf("Hole milliseconds:  %ld\n", 1000l * (tv4.tv_sec - tv3.tv_sec)
             + (tv4.tv_usec - tv3.tv_usec) / 1000l);
    }
#else  // NO_TIMER
    tv4 = clock();
    if (poly && !refine) {
      printf("Hole milliseconds:  %g\n", 1000l * (tv4 - tv3) / (REAL) CLK_TCK);
    }
#endif // NO_TIMER
  }

  if (quality) {
    enforcequality();                 // Enforce angle and area constraints.
  }

  if (!quiet) {
#ifndef NO_TIMER
    gettimeofday(&tv5, &tz);
    if (quality) {
      printf("Quality milliseconds:  %ld\n",
             1000l * (tv5.tv_sec - tv4.tv_sec)
             + (tv5.tv_usec - tv4.tv_usec) / 1000l);
    }
#else  // NO_TIMER
    tv5 = clock();
    if (quality) {
      printf("Quality milliseconds:  %g\n",
             1000l * (tv5 - tv4) / (REAL) CLK_TCK);
    }
#endif // NO_TIMER
  }

  // Compute the number of edges.
  faces = (4l * tetrahedrons.items + hullsize) / 2l;

  if (!quiet) {
    printf("\n");
  }

  // If not using iteration numbers, don't write a .node file if one was
  //   read, because the original one would be overwritten!
  if (nonodewritten || (noiterationnum && readnodefile)) {
    if (!quiet) {
      printf("NOT writing a .node file.\n");
    }
    numbernodes();                 // We must remember to number the points.
  } else {
    outnodes();                                   // Numbers the points too.
  }

  if (noelewritten) {
    if (!quiet) {
      printf("NOT writing an .ele file.\n");
    }
  } else {
    outelems();
  }

  if (regions > 0) {
    delete [] regionarray;
  }
  if (holes > 0) {
    delete [] holearray;
  }
  if (geomview) {
    outelems2gid();   // for gid mesh reader.
    outfaces2gid(1);  // only output hull faces.
    outoff();         // off file of geomview.
    // outelems2fa();    // Fa files.
  }
  if (facesout || convex) {
    outfaces(convex);
  }
  if (edgesout) {
    outedges();
  }
  if (neighbors) {
    outneighbors();
  }
  if (badelemreport) {
    dumpallbadelems("badelems.gid");
  }

  if (!quiet) {
#ifndef NO_TIMER
    gettimeofday(&tv6, &tz);
    printf("\nOutput milliseconds:  %ld\n",
           1000l * (tv6.tv_sec - tv5.tv_sec)
           + (tv6.tv_usec - tv5.tv_usec) / 1000l);
    printf("Total running milliseconds:  %ld\n",
           1000l * (tv6.tv_sec - tv0.tv_sec)
           + (tv6.tv_usec - tv0.tv_usec) / 1000l);
#else  // NO_TIMER
    tv6 = clock();
    printf("\nOutput milliseconds:  %g\n",
           1000l * (tv6 - tv5) / (REAL) CLK_TCK);
    printf("Total running milliseconds:  %g\n",
           1000l * (tv6 - tv0) / (REAL) CLK_TCK);
#endif // NO_TIMER
    statistics();
  }

  // If the "-C" swith be set.
  if (docheck) {
    checkmesh();
    if (checksegments) {
      checkshells();
    }
    checkdelaunay();
  }
}
