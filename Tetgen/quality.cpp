///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// quality.cpp    Implement the Delaunay Mesh Refinement Algorithm of        //
//                Shewchuk[2] to generate an almost good mesh.               //
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
// Generating a mesh whose elements have small aspect ratio and their sizes  //
// conform to a given control spacing function is one of the most important  //
// steps in numerical simulations. The aspect ratio of an element is usually //
// defined as the ratio of the radius of its circumsphere to the radius of   //
// its inscribed sphere. An alternative but weaker quality measurement is    //
// radius-edge ratio, which is the ratio of the circumradius to the shortest //
// edge length of the tetrahedron.                                           //
//                                                                           //
// In two-dimensions, many methods guaranteed to generate well-shaped meshes,//
// such as the two-dimensional Delaunay refinement method of J. Ruppert[1].  //
// Surprisingly, in three-dimensions, generating well-shaped meshes is       //
// considerablely more difficult, because it is difficult to identify and    //
// remove some bad-shaped tetrahedra(like sliver) from the mesh. Even so,    //
// generating a three-dimensional mesh with small radius-edge ratio is well  //
// understood. Shewchuk[2] extend the Ruppert's method to three-dimensions   //
// by proving that all tetrahedron will have radius-edge ratio no more than  //
// 2.                                                                        //
//                                                                           //
// In this file, I implement Shewchuk's algorithm to generate an almost good //
// tetrahedral mesh with good grading effect. But there is no guarantee that //
// slivers can be eliminated.  It can be done by an additional mesh smooth-  //
// ing and mesh improvement routines. This algorithm does not guarantee to   //
// terminate when there exists small angles in the domain. It may cause      //
// infinite loop in boundary protection step. For Tetgen can terminate in    //
// all conditions, I modified the algorithm slightly on the split encroached //
// subfaces rule. When a encroached subface is determined, it not always be  //
// splited, only there is no small angle at this subface(that is, angle      //
// between suface-to-subface and subface-to-subsegment is not a small angle  //
// (<=45 degree)). (I'm looking for a pleasant way to fix this problem.)     //
// Despite these unpleasant facts, the Delaunay refinement algorithm falls   //
// into the class of algorithms that usually outperform their worst-case     //
// bounds. One can apply a tighter bound (as low as 1.1)on radius-edge ratio //
// than the theory suggests is possible, or even apply bounds on dihedral    //
// angles, and still produce a small, nicely graded mesh.                    //
//                                                                           //
// Refernces:                                                                //
//                                                                           //
// [1] Jim Ruppert, A Delaunay Refinement Algorithm for Quality Two-         //
//     Dimensional Mesh Generation, Journal of Algorithms 18(3):548-585,     //
//     May 1995.                                                             //
// [2] Jonathan Richard Shewchuk, Delaunay Refinement Mesh Generation.       //
//     PhD thesis, School of Computer Science, Carnegie Mellon University,   //
//     May 1997.                                                             //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "tetlib.h"

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// dumplist()    Debug functions. Write the items of list to a text file.    //
//                                                                           //
// type = 0 tetrahedron, type = 1 subface, type = 2 subsegments.             //
// If sort > 0, sort list before output.                                     //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::dumplist(char* dumpfile, list* checklist, int type, int sort)
{
  FILE *outfile;
  triface *checktet;
  face *checksh;
  point3d torg, tdest, tapex, toppo;
  int i;

  outfile = fopen(dumpfile, "w");
  if (outfile == (FILE *) NULL) {
    printf("Error:  Cannot create file %s.\n", dumpfile);
    return;
  }
  if (!quiet) {
    printf("Writing %s.\n", dumpfile);
  }
  if (verbose < 1) {
    numbernodes(1);
  }
  if (sort > 0) {
    checklist->sort();
  }
  fprintf(outfile, "# Dumping %d items.\n", checklist->len());
  for (i = 0; i < checklist->len(); i++) {
    if (type == 0) {
      checktet = (triface*)(*checklist)[i];
      fprintf(outfile, "%4d  x%lx ", i, (unsigned long)(checktet->tet));
      if (isdead(checktet)) {
        fprintf(outfile, "(dead)\n");
      } else {
        org (*checktet, torg);
        dest(*checktet, tdest);
        apex(*checktet, tapex);
        oppo(*checktet, toppo);
        fprintf(outfile, "(%d, %d, %d, %d)\n", pointmark(torg),
                pointmark(tdest), pointmark(tapex), pointmark(toppo));
      }
    } else if (type == 1) {
      checksh = (face*)(*checklist)[i];
      fprintf(outfile, "%4d  x%lx ", i, (unsigned long)(checksh->sh));
      if (isdead(checksh)) {
        fprintf(outfile, "(dead)\n");
      } else {
        sorg (*checksh, torg);
        sdest(*checksh, tdest);
        sapex(*checksh, tapex);
        fprintf(outfile, "(%d, %d, %d)\n",
                pointmark(torg), pointmark(tdest), pointmark(tapex));
      }
    } else if (type == 2) {
      checksh = (face*)(*checklist)[i];
      fprintf(outfile, "%4d  x%lx ", i, (unsigned long)(checksh->sh));
      if (isdead(checksh)) {
        fprintf(outfile, "(dead)\n");
      } else {
        sorg (*checksh, torg);
        sdest(*checksh, tdest);
        fprintf(outfile, "(%d, %d)\n", pointmark(torg), pointmark(tdest));
      }
    }
  }
  fclose(outfile);
}

///////////////////////////////////////////////////////////////////////////////
// Mesh quality testing routines                                             //
// BEGIN                                                                     //
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// checkquality()    To test edges of the face is encroached if they are     //
//                   subsegments, otherwise to test if it is encroached if   //
//                   it is a subface, last to test if the two tets abuting   //
//                   this face are good quality.                             //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::checkquality(triface* testface)
{
  if (shsegflaws) {
    face testseg;
    int i;
    for (i = 0; i < 3; i++) {
      enextself(*testface);
      tsspivot(testface, &testseg);
      if (testseg.sh != dummysh) {
        uncheckedshseglist->append(&testseg);
      }
    }
  }
  if (shflaws) {
    face testsh;
    tspivot(*testface, testsh);
    if (testsh.sh != dummysh) {
      uncheckedshlist->append(&testsh);
    }
  }
  if (tetflaws) {
    triface neighbortet;
    uncheckedtetlist->append(testface);
    sym(*testface, neighbortet);
    if (neighbortet.tet != dummytet) {
      uncheckedtetlist->append(&neighbortet);
    }
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// checkedge4encroach()    Check a segment to see if it is encroached; add   //
//                         it to the list if it is.                          //
//                                                                           //
// An encroached segment is an unflippable edge that has a point in its      //
// diametral sphere (that is, it faces an angle greater than 90 degrees).    //
// This definition is due to Ruppert[1]. While in three dimension, A         //
// subsegment is encroached if a vertex other than its endpoints lies inside //
// or on its diametral sphere (that is, it faces an angle greater than or    //
// equal 90 degrees). This definition is due to Shewchuk[2]. This definition //
// of encroachment is slightly stronger than Ruppert's, to ensure that all   //
// unencroached subsegments are strongly Delaunay.                           //
//                                                                           //
// Returns a nonzero value if the edge is encroached.                        //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

// Check whether the apex('eapex') is inside the diametral sphere of the
//   subsegment(from 'eorg' to 'edest'). Pythagoras' Theorem is used to
//   check whether the angle at the vertex is greater than 90 degrees.

inline bool isedgeencroached(point3d eapex, point3d eorg, point3d edest)
{
  return (eapex[0] * (eorg[0] + edest[0]) +
          eapex[1] * (eorg[1] + edest[1]) +
          eapex[2] * (eorg[2] + edest[2]) >=
          eapex[0] * eapex[0] + eorg[0] * edest[0] +
          eapex[1] * eapex[1] + eorg[1] * edest[1] +
          eapex[2] * eapex[2] + eorg[2] * edest[2]);
}

int mesh3d::checkedge4encroach(face *testedge, point3d testpoint)
{
  badface3d *badedge;
  triface neighbortet, spintet;
  triface tmptet;
  face tmpseg;
  point3d eorg, edest, eapex;
  point3d torg, tdest, tapex;
  int encroachflag, smallangleflag;
  int hitbdry;

  encroachflag = 0;
  eorg = sorg(*testedge);
  edest = sdest(*testedge);

  if (testpoint == (point3d) NULL) {
    // Spin around subsegment 'testedge', find all faces which contained
    //   it. For each face, check whether its apex is inside the diametral
    //   sphere of the 'testedge'.
    sstpivot(testedge, &neighbortet);
    spintet = neighbortet;
    tapex = apex(neighbortet);
    hitbdry = 0;
    while (true) {
      if (fnextself(spintet)) {
        eapex = apex(spintet);
        if (eapex == tapex) {
          break; // Rewind, can leave now.
        }
        if (isedgeencroached(eapex, eorg, edest)) {
          encroachflag = 1;
          break;
        }
      } else {
        hitbdry ++;
        if (hitbdry >= 2) {
          break;
        } else {
          esym(neighbortet, spintet);
        }
      }
    }
    if (!encroachflag) {
      eapex = apex(neighbortet);
      if (isedgeencroached(eapex, eorg, edest)) {
        encroachflag = 1;
      }
    }
  } else {
    // Check does 'testedge' be encroached by 'testpoint'.
    if ((testpoint != eorg) && (testpoint != edest)) {
      if (isedgeencroached(testpoint, eorg, edest)) {
        encroachflag = 1;
        sstpivot(testedge, &neighbortet);
      }
    }
  }

  if (encroachflag && (!sinfected(*testedge)) &&
      (!nobisect || ((nobisect == 1) && !isridge(&neighbortet)))) {
    // 'testedge' is being encroached. It will be splitted by inserting its
    //   midpoint.
    // If 'testedge' is belong to one or more triangular faces which its
    //  (or their) three edges are all subsegments. Don't insert midpoint.
    //  Because it will create small angles which can't be removed by edge
    //  flips.
    spintet = neighbortet;
    tapex = apex(neighbortet);
    hitbdry = smallangleflag = 0;
    while (true) {
      if (fnextself(spintet)) {
        eapex = apex(spintet);
        if (eapex == tapex) {
          break; // Rewind, can leave now.
        }
        tmptet = spintet;
        enextself(tmptet);
        tsspivot(&tmptet, &tmpseg);
        if (tmpseg.sh != dummysh) {
          enextself(tmptet);
          tsspivot(&tmptet, &tmpseg);
          if (tmpseg.sh != dummysh) {
            smallangleflag = 1;
            break;
          }
        }
      } else {
        hitbdry ++;
        if (hitbdry >= 2) {
          break;
        } else {
          esym(neighbortet, spintet);
        }
      }
    }
    if (!smallangleflag) {
      tmptet = neighbortet;
      enextself(tmptet);
      tsspivot(&tmptet, &tmpseg);
      if (tmpseg.sh != dummysh) {
        enextself(tmptet);
        tsspivot(&tmptet, &tmpseg);
        if (tmpseg.sh != dummysh) {
          smallangleflag = 1;
        }
      }
    }

    if (!smallangleflag) {
      if (verbose > 2) {
        printf("    Queueing encroached segment from %d to %d.\n",
               pointmark(eorg), pointmark(edest));
      }
      // Add the shell edge to the list of encroached segments.
      badedge = (badface3d *) badsegments.alloc();
      badedge->shface = *testedge;
      badedge->faceorg = eorg;
      badedge->facedest = edest;
    } else {
      if (!quiet && verbose) {
        printf("Warning:  Not split encroached subsegment:\n");
        printf("  from (%.12g, %.12g, %.12g)\n",eorg[0], eorg[1], eorg[2]);
        printf("  to   (%.12g, %.12g, %.12g)\n", edest[0], edest[1], edest[2]);
      }
      // Set a flag in 'testedge' to avoid multiple tests later.
      //   Here temporarily use the tenth pointer ('testedge->sh[10]'), infect
      //   its shver field.
      sinfect(*testedge);
    }
  }

  // The return value indicate 'testedge' is being encroached.
  return encroachflag;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// checkface4encroach()    Check a subface to see if it is encroached; add   //
//                         it to the list if it is.                          //
//                                                                           //
// An encroached subface is an unflippable face that has a point lies in or  //
// on its equatorial sphere. This definition is due to Shewchuk[2].          //
//                                                                           //
// A priority queue used for keep Encroached faces. Why? The question 's     //
// answer could be found at Shewchuk's paper[2]:                             //
//   ...                                                                     //
//   One further amendment to the algorithm is necessary to obtain the best  //
// possible bound on the circumradius-to-shortest edge ratios of the tetrah- //
// edra. When several encroached subfacets exist, they should not be split   //
// in arbitrary order. If a vertex p encroaches upon a subfacet f of a facet //
// F, but the projection of p to F dest not lie in f,  then splitting f is   //
// not the best choice. One can show(Lemma 1) that there is some subfacet g  //
// of F that is encroached upon by p and contain the projection point of p   //
// to F. (The lemma assume that there are no encroached subsegments in the   //
// mesh, as they have priority.) A better bound is achieved if the algorithm //
// splits g first and delays the splitting of f indefinitely.                //
//   ...                                                                     //
//                                                                           //
// Returns a nonzero value if the edge is encroached.                        //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

int mesh3d::checkface4encroach(face* testface, point3d testpoint)
{
  triface testtet, tmptet, tmptmptet;
  face testsh, neighborsh;
  point3d forg, fdest, fapex, foppo;
  enum locateresult loc;
  REAL cent[3], proj[3];
  REAL dx, dy, dz;
  REAL radius2, dist2;
  int encroachflag;

  // If its a nonsolid face, need not check.
  if (isnonsolid(*testface)) return 0;

  // Find circumcenter of the face.
  forg = sorg(*testface);
  fdest = sdest(*testface);
  fapex = sapex(*testface);
  if ((testpoint != (point3d) NULL) &&
      ((testpoint == forg) || (testpoint == fdest) || (testpoint == fapex))) {
    return 0;
  }
  circumcenter(forg, fdest, fapex, cent);

  // Get the square radius of equatorial sphere.
  dx = forg[0] - cent[0];
  dy = forg[1] - cent[1];
  dz = forg[2] - cent[2];
  radius2 = dx * dx + dy * dy + dz * dz;

  encroachflag = 0;
  if (testpoint == (point3d) NULL) {
    // Check two opposite vertex to find encroaching point.
    testsh = *testface;
    stpivot(testsh, testtet);
    if (testtet.tet != dummytet) {
      foppo = oppo(testtet);
      dx = foppo[0] - cent[0];
      dy = foppo[1] - cent[1];
      dz = foppo[2] - cent[2];
      dist2 = dx * dx + dy * dy + dz * dz;
      if (dist2 <= radius2) {
        encroachflag = 1;
      }
    }
    if (!encroachflag) {
      sesymself(testsh);
      stpivot(testsh, testtet);
      if (testtet.tet != dummytet) {
        foppo = oppo(testtet);
        dx = foppo[0] - cent[0];
        dy = foppo[1] - cent[1];
        dz = foppo[2] - cent[2];
        dist2 = dx * dx + dy * dy + dz * dz;
        if (dist2 <= radius2) {
          encroachflag = 1;
        }
      }
    }
  } else {
    foppo = testpoint;
    dx = foppo[0] - cent[0];
    dy = foppo[1] - cent[1];
    dz = foppo[2] - cent[2];
    dist2 = dx * dx + dy * dy + dz * dz;
    if (dist2 <= radius2) {
      encroachflag = 1;
      testsh = *testface;
      stpivot(testsh, testtet);
      if (testtet.tet == dummytet) {
        sesymself(testsh);
        stpivot(testsh, testtet);
        assert(testtet.tet != dummytet);
      }
    }
  }

  if (encroachflag) {
    // Before add it to bad face queue, we need check its project point
    //   of this face to determine which queue(0 or 1) it should keep.
    proj[0] = foppo[0];
    proj[1] = foppo[1];
    proj[2] = foppo[2];
    projontoface(forg, fdest, fapex, proj);
    loc = iscoplanarintri(proj, &testtet);
    if (loc != OUTSIDE) {
      enqueuebadface(testface, cent, 1);
    } else {
      enqueuebadface(testface, cent, 0);
    }
  }

  return encroachflag;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// testtetrahedron()    Test a tetrahedron for quality measures.             //
//                                                                           //
// Tests a tetrahedron to see if it satisfies the minimum ratio condition    //
// and the maximum volume condition. Tetrahedra that aren't upto spec are    //
// added to the bad tetrahedron queue.                                       //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::testtetrahedron(triface* testtet)
{
  point3d torg, tdest, tapex, toppo;
  REAL dxod, dyod, dzod, dxda, dyda, dzda, dxao, dyao, dzao;
  REAL dxop, dyop, dzop, dxdp, dydp, dzdp, dxap, dyap, dzap;
  REAL dxod2, dyod2, dzod2, dxda2, dyda2, dzda2, dxao2, dyao2, dzao2;
  REAL dxop2, dyop2, dzop2, dxdp2, dydp2, dzdp2, dxap2, dyap2, dzap2;
  REAL dxoc, dyoc, dzoc, dxoc2, dyoc2, dzoc2;
  REAL edgelen[6], cent[3], smedgelen, radius, ratio2, volume;
  int i;

  torg = org(*testtet);
  tdest = dest(*testtet);
  tapex = apex(*testtet);
  toppo = oppo(*testtet);

  dxod = torg[0] - tdest[0];
  dyod = torg[1] - tdest[1];
  dzod = torg[2] - tdest[2];
  dxda = tdest[0] - tapex[0];
  dyda = tdest[1] - tapex[1];
  dzda = tdest[2] - tapex[2];
  dxao = tapex[0] - torg[0];
  dyao = tapex[1] - torg[1];
  dzao = tapex[2] - torg[2];

  dxop = torg[0] - toppo[0];
  dyop = torg[1] - toppo[1];
  dzop = torg[2] - toppo[2];
  dxdp = tdest[0] - toppo[0];
  dydp = tdest[1] - toppo[1];
  dzdp = tdest[2] - toppo[2];
  dxap = tapex[0] - toppo[0];
  dyap = tapex[1] - toppo[1];
  dzap = tapex[2] - toppo[2];

  dxod2 = dxod * dxod;
  dyod2 = dyod * dyod;
  dzod2 = dzod * dzod;
  dxda2 = dxda * dxda;
  dyda2 = dyda * dyda;
  dzda2 = dzda * dzda;
  dxao2 = dxao * dxao;
  dyao2 = dyao * dyao;
  dzao2 = dzao * dzao;

  dxop2 = dxop * dxop;
  dyop2 = dyop * dyop;
  dzop2 = dzop * dzop;
  dxdp2 = dxdp * dxdp;
  dydp2 = dydp * dydp;
  dzdp2 = dzdp * dzdp;
  dxap2 = dxap * dxap;
  dyap2 = dyap * dyap;
  dzap2 = dzap * dzap;

  // Find the lengths of the tetrahedron's siz edges.
  edgelen[0] = dxod2 + dyod2 + dzod2;
  edgelen[1] = dxda2 + dyda2 + dzda2;
  edgelen[2] = dxao2 + dyao2 + dzao2;
  edgelen[3] = dxop2 + dyop2 + dzop2;
  edgelen[4] = dxdp2 + dydp2 + dzdp2;
  edgelen[5] = dxap2 + dyap2 + dzap2;

  smedgelen = edgelen[0];
  for (i = 1; i < 6; i++) {
    if (smedgelen > edgelen[i]) smedgelen = edgelen[i];
  }
  if (smedgelen <= usertolerance) {
    printf("Precssion error in testtetrahedron(): \n");
    printf("  The shortest edge length %.12g is smaller than tolerance.\n",
           smedgelen);
    printf("  This probably means that I am trying to refine mesh to a\n");
    printf("    smaller size than can be accommodated by the finite \n");
    printf("    precision of floating point arithmetic. \n");
    precisionerror();
  }

  circumcenter(torg, tdest, tapex, toppo, cent);

  dxoc = torg[0] - cent[0];
  dyoc = torg[1] - cent[1];
  dzoc = torg[2] - cent[2];
  dxoc2 = dxoc * dxoc;
  dyoc2 = dyoc * dyoc;
  dzoc2 = dzoc * dzoc;

  radius = dxoc2 + dyoc2 + dzoc2;
  ratio2 = radius / smedgelen;

  // Check whether the ratio is smaller than permitted.
  if (ratio2 > goodratio) {
    // It's a bad-shaped tet, before we decide to split it, we need check
    //   if this bad-shaped tet is les on boundary with a small (dihedral)
    //   angle. If so, we should not split it, or it maybe cause endless
    //   loop until run out of your machine's precission.
    // Not done yet.
    // Add this tet to the list of bad tetrahedra.
    enqueuebadtet(testtet, ratio2, torg, tdest, tapex, toppo, cent);
    return;
  }
  if (varvolume || fixedvolume) {
    // Check whether the volume is larger than permitted.
    volume = tetvolume(torg, tdest, tapex, toppo);
    if (volume < 0) volume = -volume;
    if (fixedvolume && (volume > maxvolume)) {
      // Add this tetrahedron to the list of bad tetrahedra.
      enqueuebadtet(testtet, 0, torg, tdest, tapex, toppo, cent);
    } else if (varvolume) {
      // Nonpositive volume constraints are treated as unconstrained.
      if ((volume > volumebound(testtet->tet)) &&
          (volumebound(testtet->tet) > 0.0)) {
        // Add this tetrahedron to the list of bad tetrahedron.
        enqueuebadtet(testtet, 0, torg, tdest, tapex, toppo, cent);
      }
    }
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// enqueuebadface()    Add a bad subface to the end of a queue.              //
//                                                                           //
// The queue is actually a set of 2 queues.  'rank' should be 0 or 1.        //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::enqueuebadface(face *insface, point3d inscent, int rank)
{
  badface3d *newface;

  if (verbose > 2) {
    printf("    Queueing bad face: (%d, %d, %d) rank %i.\n",
           pointmark(sorg(*insface)), pointmark(sdest(*insface)),
           pointmark(sapex(*insface)), rank);
  }
  // Allocate space for the bad face.
  newface = (badface3d *) badfaces.alloc();
  newface->shface = *insface;
  if (inscent != NULL) {
    // We need not re-calculate circumcenter when split face.
    newface->badfacetet.tet = dummytet;
    newface->cent[0] = inscent[0];
    newface->cent[1] = inscent[1];
    newface->cent[2] = inscent[2];
  } else {
    // We need re-calculate circumcenter when split face.
    newface->badfacetet.tet = (tetrahedron *) NULL;
  }
  sapex(*insface, newface->faceapex);
  sorg(*insface, newface->faceorg);
  sdest(*insface, newface->facedest);
  newface->nextface = (badface3d *) NULL;
  // Add the face to the end of a queue.
  *facequetail[rank] = newface;
  // Maintain a pointer to the NULL pointer at the end of the queue.
  facequetail[rank] = &newface->nextface;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// dequeuebadface()    Remove a face from the front of the queue.            //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

badface3d* mesh3d::dequeuebadface()
{
  badface3d *result;
  int queuenumber;

  // Look for a nonempty queue.
  for (queuenumber = 1; queuenumber >= 0; queuenumber--) {
    result = facequefront[queuenumber];
    if (result != (badface3d *) NULL) {
      // Remove the face from the queue.
      facequefront[queuenumber] = result->nextface;
      // Maintain a pointer to the NULL pointer at the end of the queue.
      if (facequefront[queuenumber] == (badface3d *) NULL) {
        facequetail[queuenumber] = &facequefront[queuenumber];
      }
      return result;
    }
  }
  return (badface3d *) NULL;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// enqueuebadtet()    Add a bad tetrahedron to the end of a queue.           //
//                                                                           //
// The queue is actually a set of 64 queues.                                 //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::enqueuebadtet(triface *instet, REAL ratio, point3d insorg,
                           point3d insdest, point3d insapex, point3d insoppo,
                           point3d inscent)
{
  badtet *newtet;
  int queuenumber;

  // Allocate space for the bad tetrahedron.
  newtet = (badtet *) badtets.alloc();
  newtet->btet = *instet;
  newtet->key = ratio;
  newtet->cent[0] = inscent[0];
  newtet->cent[1] = inscent[1];
  newtet->cent[2] = inscent[2];
  newtet->tetorg = insorg;
  newtet->tetdest = insdest;
  newtet->tetapex = insapex;
  newtet->tetoppo = insoppo;
  newtet->nexttet = (badtet *) NULL;
  // Determine the appropriate queue to put the bad tetrahedron into.
  if (ratio > goodratio) { // square of 1.414
    queuenumber = (int) ((ratio - goodratio) / 0.5);
    if (queuenumber > 63) {
      queuenumber = 63;
    } else if (queuenumber < 0) {
      // The integer overflow( caused by a very large ratio.)
      queuenumber = 63;
    }
  } else {
    // It's not a bad ratio; put the tetrahedron in the lowest-priority
    //   queue.
    queuenumber = 0;
  }
  // Add the tetrahedron to the end of a queue.
  *tetquetail[queuenumber] = newtet;
  // Maintain a pointer to the NULL pointer at the end of the queue.
  tetquetail[queuenumber] = &newtet->nexttet;

  if (verbose > 2) {
    printf("    Queueing bad tet: (%d, %d, %d, %d), ratio %g, qnum %d.\n",
           pointmark(insorg), pointmark(insdest), pointmark(insapex),
           pointmark(insoppo), sqrt(ratio), queuenumber);
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// dequeuebadtet()    Remove a tetrahedron from the front of the queue.      //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

badtet* mesh3d::dequeuebadtet()
{
  badtet *result;
  int queuenumber;

  // Look for a nonempty queue.
  for (queuenumber = 63; queuenumber >= 0; queuenumber--) {
    result = tetquefront[queuenumber];
    if (result != (badtet *) NULL) {
      // Remove the tetrahedron from the queue.
      tetquefront[queuenumber] = result->nexttet;
      // Maintain a pointer to the NULL pointer at the end of the queue.
      if (tetquefront[queuenumber] == (badtet *) NULL) {
        tetquetail[queuenumber] = &tetquefront[queuenumber];
      }
      return result;
    }
  }
  return (badtet *) NULL;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// tallyencsegs()   Traverse the entire list of shell edges, check each edge //
//                  to see if it is encroached.  If so, add it to the list.  //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::tallyencsegs()
{
  face edgeloop;

  if (verbose) {
    printf("  Making a list of encroached segments.\n");
  }
  subsegs.traversalinit();
  edgeloop.shver = 0;
  edgeloop.sh = shellfacetraverse(&subsegs);
  while (edgeloop.sh != (shellface *) NULL) {
    // If the segment is encroached, add it to the list.
    checkedge4encroach(&edgeloop);
    edgeloop.sh = shellfacetraverse(&subsegs);
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// tallyencfaces()     Traverse the entire list of shell faces, check each   //
//                     face to see if it is encroached.  If so, add it to    //
//                     the list.                                             //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::tallyencfaces()
{
  face faceloop;

  if (verbose) {
    printf("  Making a list of encroached subfaces.\n");
  }
  subfaces.traversalinit();
  faceloop.shver = 0;
  faceloop.sh = shellfacetraverse(&subfaces);
  while (faceloop.sh != (shellface *) NULL) {
    // If the subface is encroached, add it to the list.
    checkface4encroach(&faceloop);
    faceloop.sh = shellfacetraverse(&subfaces);
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// tallytets()     Traverse the entire list of tetrahedra, check each tet to //
//                 see if it is bad quality.  If so, add it to the list.     //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::tallytets()
{
  triface tetloop;

  if (verbose) {
    printf("  Making a list of bad tetrahedra.\n");
  }
  tetrahedrons.traversalinit();
  tetloop.loc = 0;
  tetloop.ver = 0;
  tetloop.tet = tetrahedrontraverse();
  while (tetloop.tet != (tetrahedron *) NULL) {
    testtetrahedron(&tetloop);
    tetloop.tet = tetrahedrontraverse();
  }
}

///////////////////////////////////////////////////////////////////////////////
// END                                                                       //
// Mesh quality testing routines                                             //
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Mesh quality maintenance routines                                         //
// BEGIN                                                                     //
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// repairencsegs()    Find and repair all the encroached segments.           //
//                                                                           //
// Encroached segments are repaired by splitting them by inserting a point   //
// at or near their centers.                                                 //
//                                                                           //
// When a segment is split, the two resulting subsegments are always tested  //
// to see if they are encroached upon, regardless of the value of 'flaws'.   //                                                            //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::repairencsegs()
{
  badface3d *encloop;
  triface enctet;
  triface *checktet, *skiptet;
  face *checksh, *skipsh;
  point3d eorg, edest;
  point3d newpoint;
  REAL segmentlength, nearestpoweroftwo;
  REAL split;
  int acuteorg, acutedest;
  int flipcount;
  int i;

  while ((badsegments.items > 0) && (steinerleft != 0)) {
    badsegments.traversalinit();
    encloop = badsegmenttraverse();
    while ((encloop != (badface3d *) NULL) && (steinerleft != 0)) {
      // Check this edge is not splitted.
      eorg = sorg(encloop->shface);
      edest = sdest(encloop->shface);
      if (((eorg != (point3d) NULL) && (edest != (point3d) NULL)) &&
          ((eorg == encloop->faceorg) && (edest == encloop->facedest))) {
        // To decide where to split a segment, we need to know if the
        //   segment shares an endpoint with an adjacent segment.
        //   The concern is that, if we simply split every encroached
        //   segment in its center, two adjacent segments with a small
        //   angle between them might lead to an infinite loop; each
        //   point added to split one segment will encroach upon the
        //   other segment, which must then be split with a point that
        //   will encroach upon the first segment, and so on forever.
        // To avoid this, imagine a set of concentric circles, whose
        //   radii are powers of two, about each segment endpoint.
        //   These concentric circles determine where the segment is
        //   split.  (If both endpoints are shared with adjacent
        //   segments, split the segment in the middle, and apply the
        //   concentric shells for later splittings.)

        // Is the origin shared with another segment?
        acuteorg = isexistincidentseg(&(encloop->shface));
        // Is the destination shared with another segment?
        sesymself(encloop->shface);
        acutedest = isexistincidentseg(&(encloop->shface));
        sesymself(encloop->shface);

        // Use the concentric circles if exactly one endpoint is shared
        //   with another adjacent segment.
        if (acuteorg ^ acutedest) {
          segmentlength = sqrt((edest[0] - eorg[0]) * (edest[0] - eorg[0])
                               + (edest[1] - eorg[1]) * (edest[1] - eorg[1])
                               + (edest[2] - eorg[2]) * (edest[2] - eorg[2]));
          // Find the power of two nearest the segment's length.
          nearestpoweroftwo = 1.0;
          while (segmentlength > SQUAREROOTTWO * nearestpoweroftwo) {
            nearestpoweroftwo *= 2.0;
          }
          while (segmentlength < (0.5 * SQUAREROOTTWO) * nearestpoweroftwo) {
            nearestpoweroftwo *= 0.5;
          }
          // Where do we split the segment?
          split = 0.5 * nearestpoweroftwo / segmentlength;
          if (acutedest) {
            split = 1.0 - split;
          }
        } else {
          // If we're not worried about adjacent segments, split
          //   this segment in the middle.
          split = 0.5;
        }

        // Create the new point.
        newpoint = (point3d) points.alloc();
        // Interpolate its coordinate and attributes.
        for (i = 0; i < 3 + nextras; i++) {
          newpoint[i] = (1.0 - split) * eorg[i] + split * edest[i];
        }
        // The new point must lies on subsegment.
        setpointmark(newpoint, mark(encloop->shface));
        if (verbose > 1) {
          // Set pointmark of newpoint for Debuging outputs.
          setpointmark(newpoint, points.items);
        }
        // Check whether the new point lies on an endpoint.
        if ((compare2points(&newpoint, &eorg) == 0) ||
            (compare2points(&newpoint, &edest) == 0)) {
          printf("Error:  Ran out of precision at (%.12g, %.12g, %.12g).\n",
                 newpoint[0], newpoint[1], newpoint[2]);
          printf("  I attempted to split a segment to a smaller size than\n");
          printf("    can be accommodated by the finite precision of floating\n");
          printf("    point arithmetic.\n");
          precisionerror();
        }
        if (verbose > 1) {
          printf("  Insert circumcenter: (%.12g, %.12g, %.12g) %d\n",
                 newpoint[0], newpoint[1], newpoint[2], pointmark(newpoint));
          printf("    to split subsegment (%d, %d).\n",
                 pointmark(eorg), pointmark(edest));
        }
        if (shsegflaws) {
          uncheckedshseglist->clear();
        }
        if (shflaws) {
          uncheckedshlist->clear();
        }
        if (tetflaws) {
          uncheckedtetlist->clear();
        }
        // Find a tetra contain this subsegment.
        sstpivot(&(encloop->shface), &enctet);
        findversion(&enctet, &(encloop->shface));
        // Insert the splitting point.  This should always succssed.
        flipcount = insertonedge(newpoint, &enctet, &(encloop->shface));
        if (verbose > 1) {
          printf("  Successfully split subsegment with %d flips.\n", flipcount);
        }
        if (steinerleft > 0) {
          steinerleft--;
        }
        // Check all encroached segments, subfaces and bad tetrahedra caused
        //   by insert this point if there need.
        if (shsegflaws && (uncheckedshseglist->len() > 0)) {
          uncheckedshseglist->sort();
          skipsh = checksh = (face*)(*uncheckedshseglist)[0];
          if (!isdead(checksh)) {
            checkedge4encroach(checksh);
          }
          for (i = 1; i < uncheckedshseglist->len(); i++) {
            checksh = (face*)(*uncheckedshseglist)[i];
            if (checksh->sh != skipsh->sh) {
              if (!isdead(checksh)) {
                checkedge4encroach(checksh);
              }
              skipsh = checksh;
            }
          }
        }
        if (shflaws && (uncheckedshlist->len() > 0)) {
          uncheckedshlist->sort();
          skipsh = checksh = (face*)(*uncheckedshlist)[0];
          if (!isdead(checksh)) {
            checkface4encroach(checksh);
          }
          for (i = 1; i < uncheckedshlist->len(); i++) {
            checksh = (face*)(*uncheckedshlist)[i];
            if (checksh->sh != skipsh->sh) {
              if (!isdead(checksh)) {
                checkface4encroach(checksh);
              }
              skipsh = checksh;
            }
          }
        }
        if (tetflaws && (uncheckedtetlist->len() > 0)) {
          uncheckedtetlist->sort();
          skiptet = checktet = (triface*)(*uncheckedtetlist)[0];
          if (!isdead(checktet)) {
            testtetrahedron(checktet);
          }
          for (i = 1; i < uncheckedtetlist->len(); i++) {
            checktet = (triface*)(*uncheckedtetlist)[i];
            if (checktet->tet != skiptet->tet) {
              if (!isdead(checktet)) {
                testtetrahedron(checktet);
              }
              skiptet = checktet;
            }
          }
        }
        // Check the two new subsegments to see if they're encroached.
        checkedge4encroach(&(encloop->shface));
        senextself(encloop->shface);
        spivotself(encloop->shface);
        encloop->shface.shver = 0;
        checkedge4encroach(&(encloop->shface));
      }
      badsegmentdealloc(encloop);
      encloop = badsegmenttraverse();
    }
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// repairencfaces()    Find and repair all the encroached subfaces.          //
//                                                                           //
// Encroached subfaces are repaired by splitting them by inserting a point   //
// at or near their circumcenters. However, if the new point would encroach  //
// upon any any subsegment, it is not inserted; instead, all the subsegments //
// it would encroach upon are split.                                         //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::repairencfaces()
{
  list *neartetlist, *nearseglist;
  badface3d* badface;
  triface badfacetet;
  triface testtet, neighbortet;
  triface *checktet, *skiptet;
  face testseg;
  face *checksh, *skipsh;
  point3d borg, bdest, bapex;
  point3d newpoint;
  enum locateresult intersect;
  enum insertsiteresult success;
  int encroachedseg;
  int errorflag, flipcount;
  int i, j;

  neartetlist = nearseglist = NULL;

  while (badfaces.items > 0) {
    // Fix one encroached subfaces by inserting a point at its circumcenter.
    badface = dequeuebadface();
    assert(badface);
    borg = sorg(badface->shface);
    bdest = sdest(badface->shface);
    bapex = sapex(badface->shface);
    // Make sure that this subface is still the same subface when it was
    //   tested and determined to be encroached. Subsequent transformations
    //   may have made it a different subface.
    if (((borg != (point3d) NULL) && (bdest != (point3d) NULL) &&
         (bapex != (point3d) NULL)) && ((borg == badface->faceorg) &&
         (bdest == badface->facedest) && (bapex == badface->faceapex))) {
      errorflag = 0;
      // Create a new point at the subface's circumcenter.
      newpoint = (point3d) points.alloc();
      // Check if we need calculate circumcenter.
      if (badface->badfacetet.tet == (tetrahedron *) NULL) {
        circumcenter(borg, bdest, bapex, badface->cent);
      }
      newpoint[0] = badface->cent[0];
      newpoint[1] = badface->cent[1];
      newpoint[2] = badface->cent[2];
      if (issamepoint(newpoint, borg) || issamepoint(newpoint, bdest)
          || issamepoint(newpoint, bapex)) {
        if (!quiet) {
          printf("Warning:  Newpoint (%.12g, %.12g, %.12g) falls on",
                 newpoint[0], newpoint[1], newpoint[2]);
          printf(" existing vertex.\n");
        }
        errorflag = 1;
        pointdealloc(newpoint);
      } else {
        setpointmark(newpoint, mark(badface->shface));
        if (verbose > 1) {
          // Set pointmark of newpoint for Debuging outputs.
          setpointmark(newpoint, points.items);
        }
        // Find a tetrahedron that contain this face.
        stpivot(badface->shface, badfacetet);
        if (badfacetet.tet == dummytet) {
          sesymself(badface->shface);
          stpivot(badface->shface, badfacetet);
          assert(badfacetet.tet != dummytet);
        }
        // Find where the newpoint locates(ONFACE or ONEDGE), keep the
        //   result in 'badfacetet'.
        intersect = iscoplanarintri(newpoint, &badfacetet);
        if (intersect == OUTSIDE) {
          adjustedgering(badfacetet, CCW);
          intersect = preciselocate(newpoint, &badfacetet);
        }

        if ((intersect == ONFACE) || (intersect == ONEDGE)) {
          // If 'newpoint' is located ONFACE or ONEDGE, check if its
          //   location encroaches on any nearby subsegments. It's a two
          //   step process: First, gather all nearby subsegments; Second,
          //   check each subsegment to discover its encroachness.
          encroachedseg = 0;
          assert(badfacetet.tet != dummytet);
          if (!neartetlist) {
            neartetlist = new list(sizeof(triface));
            neartetlist->setcomp((compfunc) &compare2tets);
            nearseglist = new list(sizeof(face));
            nearseglist->setcomp((compfunc) &compare2shfaces);
          } else {
            neartetlist->clear();
            nearseglist->clear();
          }
          // Step 1, gather all nearby subsegments, store them in list
          //   'nearseglist'.
          // To address this, Boywer-Watson's scheme (Cavity) is adopted.
          //   All tetrahedra whose circumspheres contain 'newpoint' are
          //   found. Check the edges for each tetrahedron, if there exist
          //   a subsegment abutting this edge, add it to 'nearseglist'.
          testtet = badfacetet;
          // Check three edges of 'testtet''s current face.
          for (i = 0; i < 3; i++) {
            tsspivot(&testtet, &testseg);
            if (testseg.sh != dummysh) {
              nearseglist->append(&testseg);
            }
            enextself(testtet);
          }
          neartetlist->append(&testtet);
          sym(testtet, neighbortet);
          if (neighbortet.tet != dummytet) {
            if (iinsphere(&neighbortet, newpoint) == 1) {
              neartetlist->append(&neighbortet);
            }
          }
          for (i = 0; i < neartetlist->len(); i++) {
            // Get a tetra, which its circumsphere contain 'newpoint'.
            testtet = *(triface *)(* neartetlist)[i];
            adjustedgering(testtet, CCW);
            // Check other three edges of this tetra. At the same time,
            //   check other three neighbors of this tetra to see if their
            //   circumsphere contain 'newpoint'.
            for (j = 0; j < 3; j++) {
              fnext(testtet, neighbortet);
              enextself(neighbortet);
              tsspivot(&neighbortet, &testseg);
              if (testseg.sh != dummysh) {
                if (nearseglist->hasitem(&testseg) == -1) {
                  nearseglist->append(&testseg);
                }
              }
              symself(neighbortet);
              if (neighbortet.tet != dummytet) {
                if (iinsphere(&neighbortet, newpoint) == 1) {
                  if (neartetlist->hasitem(&neighbortet) == -1) {
                    neartetlist->append(&neighbortet);
                  }
                }
              }
              enextself(testtet);
            }
          }
          // Step 2, Check each segment to discover if they will be
          //   encroached by 'newpoint'.
          for (i = 0; i < nearseglist->len(); i++) {
            testseg = *(face *)(* nearseglist)[i];
            if (checkedge4encroach(&testseg, newpoint)) {
              encroachedseg++;
            }
          }

          if (encroachedseg == 0) {
            if (verbose > 1) {
              printf("  Insert circumcenter: (%.12g, %.12g, %.12g) %d\n",
                     newpoint[0], newpoint[1], newpoint[2],
                     pointmark(newpoint));
              printf("    to split subface (%d, %d, %d).\n",
                     pointmark(borg), pointmark(bdest), pointmark(bapex));
            }
            uncheckedshseglist->clear();
            if (shflaws) {
              uncheckedshlist->clear();
            }
            if (tetflaws) {
              uncheckedtetlist->clear();
            }
            if (intersect == ONFACE) {
              tspivot(badfacetet, badface->shface);
              assert(badface->shface.sh != dummysh);
              flipcount = insertonface(newpoint, &badfacetet,
                                       &(badface->shface));
            } else { // must intersect == ONEDGE
              flipcount = insertonedge(newpoint, &badfacetet, (face*) NULL);
            }
            if (verbose > 1) {
              printf("  Successfully split subface with %d flips.\n",
                     flipcount);
            }
            success = SUCCESSFUL;
          } else {
            success = VIOLATINGEDGE;
          }
        } else if (intersect == OUTSIDE) {
          success = FAILED;
        } else if (intersect == ONVERTEX) {
          success = DUPLICATE;
        } else {  // intersect == INTETRAHEDRON
          printf("Precision error in repairencface(): INTETRAHEDRON.\n");
          printf("  Failed to locate a subface to contain newpoint.\n");
          precisionerror();
        }

        if (success == SUCCESSFUL) {
          if (steinerleft > 0) {
            steinerleft--;
          }
          // We need check if new insert point cause other subfaces be
          //   encroached and cause bad quality tetrahedra.
          if (shflaws && (uncheckedshlist->len() > 0)) {
            uncheckedshlist->sort();
            skipsh = checksh = (face*)(*uncheckedshlist)[0];
            if (!isdead(checksh)) {
              checkface4encroach(checksh);
            }
            for (i = 1; i < uncheckedshlist->len(); i++) {
              checksh = (face*)(*uncheckedshlist)[i];
              if (checksh->sh != skipsh->sh) {
                if (!isdead(checksh)) {
                  checkface4encroach(checksh);
                }
                skipsh = checksh;
              }
            }
          }
          if (tetflaws && (uncheckedtetlist->len() > 0)) {
            uncheckedtetlist->sort();
            skiptet = checktet = (triface*)(*uncheckedtetlist)[0];
            if (!isdead(checktet)) {
              testtetrahedron(checktet);
            }
            for (i = 1; i < uncheckedtetlist->len(); i++) {
              checktet = (triface*)(*uncheckedtetlist)[i];
              if (checktet->tet != skiptet->tet) {
                if (!isdead(checktet)) {
                  testtetrahedron(checktet);
                }
                skiptet = checktet;
              }
            }
          }
        } else if (success == VIOLATINGEDGE) {
          // Failed to insert the new point, but some segment was
          //   marked as being encroached.
          pointdealloc(newpoint);
        } else if (success == VIOLATINGFACE) {
          printf("Internalerror in splitface(): Unexpected condition");
          printf(" success == VIOLATINGFACE.\n");
          internalerror();
        } else if (success == FAILED) {
          if (!quiet && verbose) {
            // Failed to insert the new point because it fails outside the
            //   mesh. It's a except condition caused by the existing of
            //   small angles in input model.
            printf("Warning:  New point (%.12g, %.12g, %.12g) falls",
                   newpoint[0], newpoint[1], newpoint[2]);
            printf("  outside the mesh.\n");
          }
          pointdealloc(newpoint);
        } else { // success == DUPLICATE
          if (!quiet) {
            // Failed to insert the new point because a vertex is already
            //   there.
            printf("Warning:  New point (%.12g, %.12g, %.12g) falls on",
                   newpoint[0], newpoint[1], newpoint[2]);
            printf(" existing vertex.\n");
          }
          pointdealloc(newpoint);
          errorflag = 1;
        }
      }
      if (errorflag) {
        if (verbose) {
          printf("  The new point is at the circumcenter of subface.\n");
          printf("    (%.12g, %.12g, %.12g) (%.12g, %.12g, %.12g)",
                 borg[0], borg[1], borg[2], bdest[0], bdest[1], bdest[2]);
          printf(" (%.12g, %.12g, %.12g)\n", bapex[0], bapex[1], bapex[2]);
        }
        printf("  This probably means that I am trying to refine subfaces\n");
        printf("    to a smaller size than can be accommodated by the finite\n");
        printf("    precision of floating point arithmetic.\n");
        precisionerror();
      }
    }
    // Return the badface to the pool.
    badfaces.dealloc((void *) badface);
    // Fix any encroached segments that may have resulted.
    if (badsegments.items > 0) {
      repairencsegs();
    }
  }

  if (neartetlist) {
    delete neartetlist;
    delete nearseglist;
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// splittet()    Inserts a point at the circumsphere of a bad quality        //
//               tetrahedron, thus eliminating the tetrahedron.              //
//                                                                           //
// If the new point would encroach upon any subsegment or subfacet, then it  //
// is not inserted; instead, all the subsegments it would encroach upon are  //
// split. If the bad quality tetrahedron is not eliminated as a result, then //
// all the subfacets its circumcenter would encroach upon are split.         //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::splittet(badtet* intet)
{
  triface searchtet;
  triface testtet, neighbortet;
  triface *checktet, *skiptet;
  face testsh, testseg;
  face *checksh, *skipsh;
  point3d borg, bdest, bapex, boppo;
  point3d newpoint;
  enum locateresult intersect;
  enum insertsiteresult success;
  int encroachedseg, encroachedface;
  int errorflag, flipcount;
  int i, j;

  borg = org(intet->btet);
  bdest = dest(intet->btet);
  bapex = apex(intet->btet);
  boppo = oppo(intet->btet);
  // Make sure that this tet is still the same tet it was when it was tested
  //   and determined to be encroached. Subsequent transformations may have
  //   made it a different tet.
  if (((borg != (point3d) NULL) && (bdest != (point3d) NULL) &&
       (bapex != (point3d) NULL) && (boppo != (point3d) NULL)) &&
      ((borg == intet->tetorg) && (bdest == intet->tetdest) &&
       (bapex == intet->tetapex) && (boppo == intet->tetoppo))) {
    errorflag = 0;
    // Create a new point at the tetrahedron's circumsphere.
    newpoint = (point3d) points.alloc();
    newpoint[0] = intet->cent[0];
    newpoint[1] = intet->cent[1];
    newpoint[2] = intet->cent[2];
    if (issamepoint(newpoint, borg) || issamepoint(newpoint, bdest)
        || issamepoint(newpoint, bapex) || issamepoint(newpoint, boppo)) {
      if (!quiet) {
        printf("Warning:  Newpoint (%.12g, %.12g, %.12g) falls on",
               newpoint[0], newpoint[1], newpoint[2]);
        printf(" existing vertex.\n");
      }
      pointdealloc(newpoint);
      errorflag = 1;
    } else {
      // The new point must be in mesh, set a marker of zero.
      setpointmark(newpoint, 0);
      if (verbose > 1) {
        // Set pointmark of newpoint for Debuging outputs.
        setpointmark(newpoint, points.items);
      }
      // Ensure that the circumcenter must above 'intet->btet', so point
      //   location will work.
      searchtet = intet->btet;
      searchtet.ver = 0;
      for (searchtet.loc = 0; searchtet.loc < 4; searchtet.loc++) {
        if (isaboveplane(&(searchtet), newpoint)) break;
      }
      assert(searchtet.loc < 4);
      // Find where the newpoint locates, keep the result in 'searchtet'.
      intersect = preciselocate(newpoint, &searchtet);

      if ((intersect == INTETRAHEDRON) || (intersect == ONFACE)
          || (intersect == ONEDGE)) {
        // If 'newpoint' is located inside current mesh, insert the point
        //   to split tetrahedron. Before insertion, check if its location
        //   encroaches on any nearby subsegments or subfaces. Use Boywer-
        //   Watson insertion scheme for encroach checking.
        encroachedseg = encroachedface = 0;
        cavetetlist->clear();
        caveshlist->clear();
        cavebdfacelist->clear();

        // Collect all tetra to form the cavity. At the same time, collect
        //   the boundary faces of this cavity and all encountered subfaces.
        testtet = searchtet;
        cavetetlist->append(&testtet);
        tspivot(testtet, testsh);
        if ((testsh.sh != dummysh) && !isnonsolid(testsh)) {
          caveshlist->append(&testsh);
          adjustedgering(testtet, CCW);
          cavebdfacelist->append(&testtet);
        } else {
          sym(testtet, neighbortet);
          assert(neighbortet.tet != dummytet);
          if (iinsphere(&neighbortet, newpoint) == 1) {
            cavetetlist->append(&neighbortet);
          } else {
            adjustedgering(testtet, CCW);
            cavebdfacelist->append(&testtet);
          }
        }
        for (i = 0; i < cavetetlist->len(); i++) {
          // Get a tetra, which its circumsphere contain 'newpoint'.
          testtet = *(triface *)(* cavetetlist)[i];
          adjustedgering(testtet, CCW);
          // Check other three neighbors of this tet.
          for (j = 0; j < 3; j++) {
            fnext(testtet, neighbortet);
            tspivot(neighbortet, testsh);
            if ((testsh.sh != dummysh) && !isnonsolid(testsh)) {
              caveshlist->append(&testsh);
              adjustedgering(neighbortet, CCW);
              cavebdfacelist->append(&neighbortet);
            } else {
              symself(neighbortet);
              assert(neighbortet.tet != dummytet);
              if (iinsphere(&neighbortet, newpoint) == 1) {
                if (cavetetlist->hasitem(&neighbortet) == -1) {
                  cavetetlist->append(&neighbortet);
                }
              } else {
                symself(neighbortet);
                adjustedgering(neighbortet, CCW);
                cavebdfacelist->append(&neighbortet);
              }
            }
            enextself(testtet);
          }
        }
        // Check for any encroached subsegments first.
        for (i = 0; i < caveshlist->len(); i++) {
          testsh = *(face *)(* caveshlist)[i];
          for (j = 0; j < 3; j++) {
            sspivot(testsh, testseg);
            if (testseg.sh != dummysh) {
              if (checkedge4encroach(&testseg, newpoint)) {
                encroachedseg++;
              }
            }
            senextself(testsh);
          }
        }
        if (encroachedseg) {
          success = VIOLATINGEDGE;
        } else {
          // If no subsegment be encroached, then check subfaces.
          for (i = 0; i < caveshlist->len(); i++) {
            testsh = *(face *)(* caveshlist)[i];
            if (checkface4encroach(&testsh, newpoint)) {
              encroachedface++;
            }
          }
          if (encroachedface) {
            success = VIOLATINGFACE;
          }
        }
        if ((!encroachedseg) && (!encroachedface)) {
          if (cavetetlist->hasitem(&(intet->btet)) != -1) {
            if (verbose > 1) {
              printf("  Insert circumcenter: (%.12g, %.12g, %.12g) %d\n",
                     newpoint[0], newpoint[1], newpoint[2],
                     pointmark(newpoint));
              printf("    to split tetra (%d, %d, %d, %d).\n",
                     pointmark(borg), pointmark(bdest), pointmark(bapex),
                     pointmark(boppo));
            }
            uncheckedshseglist->clear();
            uncheckedshlist->clear();
            uncheckedtetlist->clear();
            if (intersect == INTETRAHEDRON) {
              flipcount = insertininterior(newpoint, &searchtet);
            } else if (intersect == ONFACE) {
              tspivot(searchtet, testsh);
              if (testsh.sh != dummysh) {
                // Note: 'testsh' must be an nonsolid subface.
                assert(isnonsolid(testsh));
                flipcount = insertonface(newpoint, &searchtet, &testsh);
              } else {
                flipcount = insertonface(newpoint, &searchtet, (face*) NULL);
              }
            } else { // must intersect == ONEDGE
              // Note: 'newpoint' must locate on a interior edge.
              flipcount = insertonedge(newpoint, &searchtet, (face*) NULL);
            }
            if (verbose > 1) {
              printf("  Successfully split tetra with %d flips.\n", flipcount);
            }
            success = SUCCESSFUL;
          } else {
            // Do not insert 'newpoint', because it can't eliminate bad tet.
            if (!quiet && verbose) {
              printf("Warning:  A bad-quality tet survived.\n");
            }
            success = VIOLATINGEDGE;
          }
        }
      } else if (intersect == ONVERTEX) {
        success = DUPLICATE;
      } else { // intersect == OUTSIDE
        success = FAILED;
      }

      if (success == SUCCESSFUL) {
        if (steinerleft > 0) {
          steinerleft--;
        }
        // Check and queue the bad quality tetrahedra caused by inserting
        //   'newpoint'.
        if (uncheckedtetlist->len() > 0) {
          uncheckedtetlist->sort();
          skiptet = checktet = (triface*)(*uncheckedtetlist)[0];
          if (!isdead(checktet)) {
            testtetrahedron(checktet);
          }
          for (i = 1; i < uncheckedtetlist->len(); i++) {
            checktet = (triface*)(*uncheckedtetlist)[i];
            if (checktet->tet != skiptet->tet) {
              if (!isdead(checktet)) {
                testtetrahedron(checktet);
              }
              skiptet = checktet;
            }
          }
        }
      } else if ((success == VIOLATINGEDGE) || (success == VIOLATINGFACE)) {
        // Failed to insert the new point, but some segment and subfaces
        //   was marked as being encroached.
        pointdealloc(newpoint);
      } else if (success == FAILED) {
        if (!quiet && verbose) {
          // Failed to insert the new point because it fails outside the
          //   mesh. It's an except condition caused by the existing of
          //   small angles in input model.
          printf("Warning:  New point (%.12g, %.12g, %.12g) falls outside",
                 newpoint[0], newpoint[1], newpoint[2]);
          printf(" the mesh.\n");
        }
        pointdealloc(newpoint);
      } else { // success == DUPLICATE
        if (!quiet) {
          // Failed to insert the new point because a vertex is already there.
          printf("Warning:  New point (%.12g, %.12g, %.12g) falls on",
                 newpoint[0], newpoint[1], newpoint[2]);
          printf(" existing vertex.\n");
        }
        pointdealloc(newpoint);
        errorflag = 1;
      }
    }
    if (errorflag) {
      if (verbose) {
        printf("  The new point is at the circumsphere of tetrahedron:\n");
        printf("    (%.12g, %.12g, %.12g) (%.12g, %.12g, %.12g)\n",
               borg[0], borg[1], borg[2], bdest[0], bdest[1], bdest[2]);
        printf("    (%.12g, %.12g, %.12g) (%.12g, %.12g, %.12g)\n",
               bapex[0], bapex[1], bapex[2], boppo[0], boppo[1], boppo[2]);
      }
      printf("  This probably means that I am trying to refine tetrahedra\n");
      printf("    to a smaller size than can be accommodated by the finite\n");
      printf("    precision of floating point arithmetic.\n");
      precisionerror();
    }
  }
  // Return the badtet to the pool.
  badtets.dealloc((void *) intet);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// enforcequality()    Remove all the encroached edges and bad triangles     //
//                     from the triangulation.                               //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void mesh3d::enforcequality()
{
  int i;

  if (!quiet) {
    printf("Adding Steiner points to enforce quality.\n");
  }

  // Initialize the pool of encroached segments.
  badsegments.init(sizeof(badface3d), BADSHELLFACEPERBLOCK, POINTER, 0);
  // Initialize the queue of subsegments which might be encroached.
  uncheckedshseglist = new list(sizeof(face));
  uncheckedshseglist->setcomp((compfunc) &compare2shfaces);
  if (verbose) {
    printf("  Looking for encroached segments.\n");
  }
  // Test all segments to see if they're encroached.
  tallyencsegs();
  // Note that steinerleft == -1 if an unlimited number
  //   of Steiner points is allowed.
  while ((badsegments.items > 0) && (steinerleft != 0)) {
    if (verbose > 1) {
      printf("  Splitting %d encroached segments.\n", badsegments.items);
    }
    // Fix the segments without noting newly encroached segments or
    //   subfaces.
    repairencsegs();
    // Now, find all the segments that became encroached while adding
    //   points to split encroached segments.
    tallyencsegs();
  }

  // Initialize the pool of encroached subfaces.
  badfaces.init(sizeof(badface3d), BADSHELLFACEPERBLOCK, POINTER, 0);
  // Initialize the queue of subfaces which might be encroached.
  uncheckedshlist = new list(sizeof(face));
  uncheckedshlist->setcomp((compfunc) &compare2shfaces);
  // Initialize the queues of bad subfaces.
  for (i = 0; i < 2; i++) {
    facequefront[i] = (badface3d *) NULL;
    facequetail[i] = &facequefront[i];
  }
  if (verbose) {
    printf("  Looking for encroached subfaces.\n");
  }
  // Test all subfaces to see if they're encroached.
  tallyencfaces();
  shsegflaws = 1;
  // Note that steinerleft == -1 if an unlimited number
  //   of Steiner points is allowed.
  while ((badfaces.items > 0) && (steinerleft != 0)) {
    if (verbose > 1) {
      printf("  Splitting %d encroached subfaces.\n", badfaces.items);
    }
    // Fix the subfaces without noting newly encroached subfaces.
    repairencfaces();
    // Now, find all the subfaces that became encroached while adding
    //   points to split encroached subfaces.
    tallyencfaces();
  }
  // At this point, if we haven't run out of Steiner points, the
  //   triangulation should be (conforming) Delaunay.

  // Next, we worry about enforcing tetrahedra quality.
  if ((minratio > 0.0) || varvolume || fixedvolume) {
    // Initialize the pool of bad tetrahedra.
    badtets.init(sizeof(badtet), BADTETPERBLOCK, POINTER, 0);
    // Initialize the queue of tetrahedra which might have bad quality.
    uncheckedtetlist = new list(sizeof(triface));
    uncheckedtetlist->setcomp((compfunc) &compare2tets);
    // Initialize lists for Boywer-Watson point insertion scheme.
    cavetetlist = new list(sizeof(triface));
    cavetetlist->setcomp((compfunc) &compare2tets);
    caveshlist = new list(sizeof(face));
    caveshlist->setcomp((compfunc) &compare2shfaces);
    cavebdfacelist = new list(sizeof(triface));
    cavebdfacelist->setcomp((compfunc) &compare2tets);
    // Initialize the queues of bad tetrahedra.
    for (i = 0; i < 64; i++) {
      tetquefront[i] = (badtet *) NULL;
      tetquetail[i] = &tetquefront[i];
    }
    // Test all tetrahedra to see if they're bad.
    tallytets();
    if (verbose) {
      printf("  Splitting bad tetrahedra.\n");
    }
    shflaws = shsegflaws = tetflaws = 1;
    while ((badtets.items > 0) && (steinerleft != 0)) {
      // Fix one bad tetrahedron by inserting a point at its circumsphere.
      splittet(dequeuebadtet());
      // Fix any encroached segments and subfaces that may have resulted.
      //   Record any new bad tetrahedra or encroached segments, subfaces
      //   that result.
      if (badsegments.items > 0) {
        repairencsegs();
      }
      if (badfaces.items > 0) {
        repairencfaces();
      }
    }
    delete cavetetlist;
    delete caveshlist;
    delete cavebdfacelist;
    delete uncheckedtetlist;
  }
  delete uncheckedshseglist;
  delete uncheckedshlist;

  // At this point, if we haven't run out of Steiner points, the
  //   triangulation should be (conforming) Delaunay and have no
  //   low-quality tetrahedra except slivers.

  // Might we have run out of Steiner points too soon?
  if (!quiet && ((badsegments.items > 0) || (badfaces.items > 0))
      && (steinerleft == 0)) {
    printf("\nWarning:  I ran out of Steiner points, but the mesh has\n");
    printf("  %ld encroached segments and %ld encroached subfaces,\n",
           badsegments.items, badfaces.items);
    printf("  therefore might not be truly Delaunay.\n");
    printf("  If the Delaunay property is important to you, try increasing\n");
    printf("  the number of Steiner points (controlled by the -S switch)\n");
    printf("  slightly and try again.\n\n");
  }
}

///////////////////////////////////////////////////////////////////////////////
// END                                                                       //
// Mesh quality maintenance routines                                         //
///////////////////////////////////////////////////////////////////////////////
