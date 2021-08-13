// This file is part of Tetgen/BR, the Boundary Recovery code of TetGen
//
// Copyright 2015-2016 Weierstrass Institute for Applied Analysis and
// Stochastics
//
// This file is relicensed under the terms of LICENSE.txt for use in Gmsh thanks
// to a Software License Agreement between Weierstrass Institute for Applied
// Analysis and Stochastics and GMESH SPRL.


///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// TetGen                                                                    //
//                                                                           //
// A Quality Tetrahedral Mesh Generator and A 3D Delaunay Triangulator       //
//                                                                           //
// Version 1.5                                                               //
// May 31, 2014                                                              //
//                                                                           //
// Copyright (C) 2002--2016                                                  //
//                                                                           //
// TetGen is freely available through the website: http://www.tetgen.org.    //
//   It may be copied, modified, and redistributed for non-commercial use.   //
//   Please consult the file LICENSE for the detailed copyright notices.     //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "TetGenPredicates.h"
#include "robustPredicates.h"

#include <cassert>


namespace TetGenPredicates {

  using namespace robustPredicates;

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Linear algebra operators.                                                 //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

// dot() returns the dot product: v1 dot v2.
inline REAL dot(REAL *v1, REAL *v2)
{
  return v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2];
}

// cross() computes the cross product: n = v1 cross v2.
inline void cross(REAL *v1, REAL *v2, REAL *n)
{
  n[0] = v1[1] * v2[2] - v2[1] * v1[2];
  n[1] = -(v1[0] * v2[2] - v2[0] * v1[2]);
  n[2] = v1[0] * v2[1] - v2[0] * v1[1];
}

// distance() computes the Euclidean distance between two points.
inline REAL distance(REAL *p1, REAL *p2)
{
  return sqrt((p2[0] - p1[0]) * (p2[0] - p1[0]) +
              (p2[1] - p1[1]) * (p2[1] - p1[1]) +
              (p2[2] - p1[2]) * (p2[2] - p1[2]));
}

inline REAL norm2(REAL x, REAL y, REAL z)
{
  return (x) * (x) + (y) * (y) + (z) * (z);
}

void facenormal(point pa, point pb, point pc, REAL *n, int pivot,
                            REAL* lav)
{
  REAL v1[3], v2[3], v3[3], *pv1, *pv2;
  REAL L1, L2, L3;

  v1[0] = pb[0] - pa[0];  // edge vector v1: a->b
  v1[1] = pb[1] - pa[1];
  v1[2] = pb[2] - pa[2];
  v2[0] = pa[0] - pc[0];  // edge vector v2: c->a
  v2[1] = pa[1] - pc[1];
  v2[2] = pa[2] - pc[2];

  // Default, normal is calculated by: v1 x (-v2) (see Fig. fnormal).
  if (pivot > 0) {
    // Choose edge vectors by Burdakov's algorithm.
    v3[0] = pc[0] - pb[0];  // edge vector v3: b->c
    v3[1] = pc[1] - pb[1];
    v3[2] = pc[2] - pb[2];
    L1 = dot(v1, v1);
    L2 = dot(v2, v2);
    L3 = dot(v3, v3);
    // Sort the three edge lengths.
    if (L1 < L2) {
      if (L2 < L3) {
        pv1 = v1; pv2 = v2; // n = v1 x (-v2).
      } else {
        pv1 = v3; pv2 = v1; // n = v3 x (-v1).
      }
    } else {
      if (L1 < L3) {
        pv1 = v1; pv2 = v2; // n = v1 x (-v2).
      } else {
        pv1 = v2; pv2 = v3; // n = v2 x (-v3).
      }
    }
    if (lav) {
      // return the average edge length.
      *lav = (sqrt(L1) + sqrt(L2) + sqrt(L3)) / 3.0;
    }
  } else {
    pv1 = v1; pv2 = v2; // n = v1 x (-v2).
  }

  // Calculate the face normal.
  cross(pv1, pv2, n);
  // Inverse the direction;
  n[0] = -n[0];
  n[1] = -n[1];
  n[2] = -n[2];
}


///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// tri_edge_test()    Triangle-edge intersection test.                       //
//                                                                           //
// This routine takes a triangle T (with vertices A, B, C) and an edge E (P, //
// Q) in 3D, and tests if they intersect each other.                         //
//                                                                           //
// If the point 'R' is not NULL, it lies strictly above the plane defined by //
// A, B, C. It is used in test when T and E are coplanar.                    //
//                                                                           //
// If T and E intersect each other, they may intersect in different ways. If //
// 'level' > 0, their intersection type will be reported 'types' and 'pos'.  //
//                                                                           //
// The return value indicates one of the following cases:                    //
//   - 0, T and E are disjoint.                                              //
//   - 1, T and E intersect each other.                                      //
//   - 2, T and E are not coplanar. They intersect at a single point.        //
//   - 4, T and E are coplanar. They intersect at a single point or a line   //
//        segment (if types[1] != DISJOINT).                                 //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#define SETVECTOR3(V, a0, a1, a2) (V)[0] = (a0); (V)[1] = (a1); (V)[2] = (a2)

#define SWAP2(a0, a1, tmp) (tmp) = (a0); (a0) = (a1); (a1) = (tmp)

int tri_edge_2d(point A, point B, point C, point P, point Q,
                            point R, int level, int *types, int *pos)
{
  point U[3], V[3];  // The permuted vectors of points.
  int pu[3], pv[3];  // The original positions of points.
  REAL abovept[3];
  REAL sA, sB, sC;
  REAL s1, s2, s3, s4;
  int z1;

  if (R == NULL) {
    // Calculate a lift point.
    if (1) {
      REAL n[3], len;
      // Calculate a lift point, saved in dummypoint.
      facenormal(A, B, C, n, 1, NULL);
      len = sqrt(dot(n, n));
      if (len != 0) {
        n[0] /= len;
        n[1] /= len;
        n[2] /= len;
        len = distance(A, B);
        len += distance(B, C);
        len += distance(C, A);
        len /= 3.0;
        R = abovept; //dummypoint;
        R[0] = A[0] + len * n[0];
        R[1] = A[1] + len * n[1];
        R[2] = A[2] + len * n[2];
      } else {
        // The triangle [A,B,C] is (nearly) degenerate, i.e., it is (close)
        //   to a line.  We need a line-line intersection test.
        // !!! A non-save return value.!!!
        return 0;  // DISJOINT
      }
    }
  }

  // Test A's, B's, and C's orientations wrt plane PQR.
  sA = orient3d(P, Q, R, A);
  sB = orient3d(P, Q, R, B);
  sC = orient3d(P, Q, R, C);


  if (sA < 0) {
    if (sB < 0) {
      if (sC < 0) { // (---).
        return 0;
      } else {
        if (sC > 0) { // (--+).
          // All points are in the right positions.
          SETVECTOR3(U, A, B, C);  // I3
          SETVECTOR3(V, P, Q, R);  // I2
          SETVECTOR3(pu, 0, 1, 2);
          SETVECTOR3(pv, 0, 1, 2);
          z1 = 0;
        } else { // (--0).
          SETVECTOR3(U, A, B, C);  // I3
          SETVECTOR3(V, P, Q, R);  // I2
          SETVECTOR3(pu, 0, 1, 2);
          SETVECTOR3(pv, 0, 1, 2);
          z1 = 1;
        }
      }
    } else {
      if (sB > 0) {
        if (sC < 0) { // (-+-).
          SETVECTOR3(U, C, A, B);  // PT = ST
          SETVECTOR3(V, P, Q, R);  // I2
          SETVECTOR3(pu, 2, 0, 1);
          SETVECTOR3(pv, 0, 1, 2);
          z1 = 0;
        } else {
          if (sC > 0) { // (-++).
            SETVECTOR3(U, B, C, A);  // PT = ST x ST
            SETVECTOR3(V, Q, P, R);  // PL = SL
            SETVECTOR3(pu, 1, 2, 0);
            SETVECTOR3(pv, 1, 0, 2);
            z1 = 0;
          } else { // (-+0).
            SETVECTOR3(U, C, A, B);  // PT = ST
            SETVECTOR3(V, P, Q, R);  // I2
            SETVECTOR3(pu, 2, 0, 1);
            SETVECTOR3(pv, 0, 1, 2);
            z1 = 2;
          }
        }
      } else {
        if (sC < 0) { // (-0-).
          SETVECTOR3(U, C, A, B);  // PT = ST
          SETVECTOR3(V, P, Q, R);  // I2
          SETVECTOR3(pu, 2, 0, 1);
          SETVECTOR3(pv, 0, 1, 2);
          z1 = 1;
        } else {
          if (sC > 0) { // (-0+).
            SETVECTOR3(U, B, C, A);  // PT = ST x ST
            SETVECTOR3(V, Q, P, R);  // PL = SL
            SETVECTOR3(pu, 1, 2, 0);
            SETVECTOR3(pv, 1, 0, 2);
            z1 = 2;
          } else { // (-00).
            SETVECTOR3(U, B, C, A);  // PT = ST x ST
            SETVECTOR3(V, Q, P, R);  // PL = SL
            SETVECTOR3(pu, 1, 2, 0);
            SETVECTOR3(pv, 1, 0, 2);
            z1 = 3;
          }
        }
      }
    }
  } else {
    if (sA > 0) {
      if (sB < 0) {
        if (sC < 0) { // (+--).
          SETVECTOR3(U, B, C, A);  // PT = ST x ST
          SETVECTOR3(V, P, Q, R);  // I2
          SETVECTOR3(pu, 1, 2, 0);
          SETVECTOR3(pv, 0, 1, 2);
          z1 = 0;
        } else {
          if (sC > 0) { // (+-+).
            SETVECTOR3(U, C, A, B);  // PT = ST
            SETVECTOR3(V, Q, P, R);  // PL = SL
            SETVECTOR3(pu, 2, 0, 1);
            SETVECTOR3(pv, 1, 0, 2);
            z1 = 0;
          } else { // (+-0).
            SETVECTOR3(U, C, A, B);  // PT = ST
            SETVECTOR3(V, Q, P, R);  // PL = SL
            SETVECTOR3(pu, 2, 0, 1);
            SETVECTOR3(pv, 1, 0, 2);
            z1 = 2;
          }
        }
      } else {
        if (sB > 0) {
          if (sC < 0) { // (++-).
            SETVECTOR3(U, A, B, C);  // I3
            SETVECTOR3(V, Q, P, R);  // PL = SL
            SETVECTOR3(pu, 0, 1, 2);
            SETVECTOR3(pv, 1, 0, 2);
            z1 = 0;
          } else {
            if (sC > 0) { // (+++).
              return 0;
            } else { // (++0).
              SETVECTOR3(U, A, B, C);  // I3
              SETVECTOR3(V, Q, P, R);  // PL = SL
              SETVECTOR3(pu, 0, 1, 2);
              SETVECTOR3(pv, 1, 0, 2);
              z1 = 1;
            }
          }
        } else { // (+0#)
          if (sC < 0) { // (+0-).
            SETVECTOR3(U, B, C, A);  // PT = ST x ST
            SETVECTOR3(V, P, Q, R);  // I2
            SETVECTOR3(pu, 1, 2, 0);
            SETVECTOR3(pv, 0, 1, 2);
            z1 = 2;
          } else {
            if (sC > 0) { // (+0+).
              SETVECTOR3(U, C, A, B);  // PT = ST
              SETVECTOR3(V, Q, P, R);  // PL = SL
              SETVECTOR3(pu, 2, 0, 1);
              SETVECTOR3(pv, 1, 0, 2);
              z1 = 1;
            } else { // (+00).
              SETVECTOR3(U, B, C, A);  // PT = ST x ST
              SETVECTOR3(V, P, Q, R);  // I2
              SETVECTOR3(pu, 1, 2, 0);
              SETVECTOR3(pv, 0, 1, 2);
              z1 = 3;
            }
          }
        }
      }
    } else {
      if (sB < 0) {
        if (sC < 0) { // (0--).
          SETVECTOR3(U, B, C, A);  // PT = ST x ST
          SETVECTOR3(V, P, Q, R);  // I2
          SETVECTOR3(pu, 1, 2, 0);
          SETVECTOR3(pv, 0, 1, 2);
          z1 = 1;
        } else {
          if (sC > 0) { // (0-+).
            SETVECTOR3(U, A, B, C);  // I3
            SETVECTOR3(V, P, Q, R);  // I2
            SETVECTOR3(pu, 0, 1, 2);
            SETVECTOR3(pv, 0, 1, 2);
            z1 = 2;
          } else { // (0-0).
            SETVECTOR3(U, C, A, B);  // PT = ST
            SETVECTOR3(V, Q, P, R);  // PL = SL
            SETVECTOR3(pu, 2, 0, 1);
            SETVECTOR3(pv, 1, 0, 2);
            z1 = 3;
          }
        }
      } else {
        if (sB > 0) {
          if (sC < 0) { // (0+-).
            SETVECTOR3(U, A, B, C);  // I3
            SETVECTOR3(V, Q, P, R);  // PL = SL
            SETVECTOR3(pu, 0, 1, 2);
            SETVECTOR3(pv, 1, 0, 2);
            z1 = 2;
          } else {
            if (sC > 0) { // (0++).
              SETVECTOR3(U, B, C, A);  // PT = ST x ST
              SETVECTOR3(V, Q, P, R);  // PL = SL
              SETVECTOR3(pu, 1, 2, 0);
              SETVECTOR3(pv, 1, 0, 2);
              z1 = 1;
            } else { // (0+0).
              SETVECTOR3(U, C, A, B);  // PT = ST
              SETVECTOR3(V, P, Q, R);  // I2
              SETVECTOR3(pu, 2, 0, 1);
              SETVECTOR3(pv, 0, 1, 2);
              z1 = 3;
            }
          }
        } else { // (00#)
          if (sC < 0) { // (00-).
            SETVECTOR3(U, A, B, C);  // I3
            SETVECTOR3(V, Q, P, R);  // PL = SL
            SETVECTOR3(pu, 0, 1, 2);
            SETVECTOR3(pv, 1, 0, 2);
            z1 = 3;
          } else {
            if (sC > 0) { // (00+).
              SETVECTOR3(U, A, B, C);  // I3
              SETVECTOR3(V, P, Q, R);  // I2
              SETVECTOR3(pu, 0, 1, 2);
              SETVECTOR3(pv, 0, 1, 2);
              z1 = 3;
            } else { // (000)
              // Not possible unless ABC is degenerate.
              // Avoiding compiler warnings.
              SETVECTOR3(U, A, B, C);  // I3
              SETVECTOR3(V, P, Q, R);  // I2
              SETVECTOR3(pu, 0, 1, 2);
              SETVECTOR3(pv, 0, 1, 2);
              z1 = 4;
            }
          }
        }
      }
    }
  }

  s1 = orient3d(U[0], U[2], R, V[1]);  // A, C, R, Q
  s2 = orient3d(U[1], U[2], R, V[0]);  // B, C, R, P

  if (s1 > 0) {
    return 0;
  }
  if (s2 < 0) {
    return 0;
  }

  if (level == 0) {
    return 1;  // They are intersected.
  }


  if (z1 == 1) {
    if (s1 == 0) {  // (0###)
      // C = Q.
      types[0] = (int) SHAREVERT;
      pos[0] = pu[2]; // C
      pos[1] = pv[1]; // Q
      types[1] = (int) DISJOINT;
    } else {
      if (s2 == 0) { // (#0##)
        // C = P.
        types[0] = (int) SHAREVERT;
        pos[0] = pu[2]; // C
        pos[1] = pv[0]; // P
        types[1] = (int) DISJOINT;
      } else { // (-+##)
        // C in [P, Q].
        types[0] = (int) ACROSSVERT;
        pos[0] = pu[2]; // C
        pos[1] = pv[0]; // [P, Q]
        types[1] = (int) DISJOINT;
      }
    }
    return 4;
  }

  s3 = orient3d(U[0], U[2], R, V[0]);  // A, C, R, P
  s4 = orient3d(U[1], U[2], R, V[1]);  // B, C, R, Q

  if (z1 == 0) {  // (tritri-03)
    if (s1 < 0) {
      if (s3 > 0) {
        if (s4 > 0) {
          // [P, Q] overlaps [k, l] (-+++).
          types[0] = (int) ACROSSEDGE;
          pos[0] = pu[2]; // [C, A]
          pos[1] = pv[0]; // [P, Q]
          types[1] = (int) TOUCHFACE;
          pos[2] = 3;     // [A, B, C]
          pos[3] = pv[1]; // Q
        } else {
          if (s4 == 0) {
            // Q = l, [P, Q] contains [k, l] (-++0).
            types[0] = (int) ACROSSEDGE;
            pos[0] = pu[2]; // [C, A]
            pos[1] = pv[0]; // [P, Q]
            types[1] = (int) TOUCHEDGE;
            pos[2] = pu[1]; // [B, C]
            pos[3] = pv[1]; // Q
          } else { // s4 < 0
            // [P, Q] contains [k, l] (-++-).
            types[0] = (int) ACROSSEDGE;
            pos[0] = pu[2]; // [C, A]
            pos[1] = pv[0]; // [P, Q]
            types[1] = (int) ACROSSEDGE;
            pos[2] = pu[1]; // [B, C]
            pos[3] = pv[0]; // [P, Q]
          }
        }
      } else {
        if (s3 == 0) {
          if (s4 > 0) {
            // P = k, [P, Q] in [k, l] (-+0+).
            types[0] = (int) TOUCHEDGE;
            pos[0] = pu[2]; // [C, A]
            pos[1] = pv[0]; // P
            types[1] = (int) TOUCHFACE;
            pos[2] = 3;     // [A, B, C]
            pos[3] = pv[1]; // Q
          } else {
            if (s4 == 0) {
              // [P, Q] = [k, l] (-+00).
              types[0] = (int) TOUCHEDGE;
              pos[0] = pu[2]; // [C, A]
              pos[1] = pv[0]; // P
              types[1] = (int) TOUCHEDGE;
              pos[2] = pu[1]; // [B, C]
              pos[3] = pv[1]; // Q
            } else {
              // P = k, [P, Q] contains [k, l] (-+0-).
              types[0] = (int) TOUCHEDGE;
              pos[0] = pu[2]; // [C, A]
              pos[1] = pv[0]; // P
              types[1] = (int) ACROSSEDGE;
              pos[2] = pu[1]; // [B, C]
              pos[3] = pv[0]; // [P, Q]
            }
          }
        } else { // s3 < 0
          if (s2 > 0) {
            if (s4 > 0) {
              // [P, Q] in [k, l] (-+-+).
              types[0] = (int) TOUCHFACE;
              pos[0] = 3;     // [A, B, C]
              pos[1] = pv[0]; // P
              types[1] = (int) TOUCHFACE;
              pos[2] = 3;     // [A, B, C]
              pos[3] = pv[1]; // Q
            } else {
              if (s4 == 0) {
                // Q = l, [P, Q] in [k, l] (-+-0).
                types[0] = (int) TOUCHFACE;
                pos[0] = 3;     // [A, B, C]
                pos[1] = pv[0]; // P
                types[1] = (int) TOUCHEDGE;
                pos[2] = pu[1]; // [B, C]
                pos[3] = pv[1]; // Q
              } else { // s4 < 0
                // [P, Q] overlaps [k, l] (-+--).
                types[0] = (int) TOUCHFACE;
                pos[0] = 3;     // [A, B, C]
                pos[1] = pv[0]; // P
                types[1] = (int) ACROSSEDGE;
                pos[2] = pu[1]; // [B, C]
                pos[3] = pv[0]; // [P, Q]
              }
            }
          } else { // s2 == 0
            // P = l (#0##).
            types[0] = (int) TOUCHEDGE;
            pos[0] = pu[1]; // [B, C]
            pos[1] = pv[0]; // P
            types[1] = (int) DISJOINT;
          }
        }
      }
    } else { // s1 == 0
      // Q = k (0####)
      types[0] = (int) TOUCHEDGE;
      pos[0] = pu[2]; // [C, A]
      pos[1] = pv[1]; // Q
      types[1] = (int) DISJOINT;
    }
  } else if (z1 == 2) {  // (tritri-23)
    if (s1 < 0) {
      if (s3 > 0) {
        if (s4 > 0) {
          // [P, Q] overlaps [A, l] (-+++).
          types[0] = (int) ACROSSVERT;
          pos[0] = pu[0]; // A
          pos[1] = pv[0]; // [P, Q]
          types[1] = (int) TOUCHFACE;
          pos[2] = 3;     // [A, B, C]
          pos[3] = pv[1]; // Q
        } else {
          if (s4 == 0) {
            // Q = l, [P, Q] contains [A, l] (-++0).
            types[0] = (int) ACROSSVERT;
            pos[0] = pu[0]; // A
            pos[1] = pv[0]; // [P, Q]
            types[1] = (int) TOUCHEDGE;
            pos[2] = pu[1]; // [B, C]
            pos[3] = pv[1]; // Q
          } else { // s4 < 0
            // [P, Q] contains [A, l] (-++-).
            types[0] = (int) ACROSSVERT;
            pos[0] = pu[0]; // A
            pos[1] = pv[0]; // [P, Q]
            types[1] = (int) ACROSSEDGE;
            pos[2] = pu[1]; // [B, C]
            pos[3] = pv[0]; // [P, Q]
          }
        }
      } else {
        if (s3 == 0) {
          if (s4 > 0) {
            // P = A, [P, Q] in [A, l] (-+0+).
            types[0] = (int) SHAREVERT;
            pos[0] = pu[0]; // A
            pos[1] = pv[0]; // P
            types[1] = (int) TOUCHFACE;
            pos[2] = 3;     // [A, B, C]
            pos[3] = pv[1]; // Q
          } else {
            if (s4 == 0) {
              // [P, Q] = [A, l] (-+00).
              types[0] = (int) SHAREVERT;
              pos[0] = pu[0]; // A
              pos[1] = pv[0]; // P
              types[1] = (int) TOUCHEDGE;
              pos[2] = pu[1]; // [B, C]
              pos[3] = pv[1]; // Q
            } else { // s4 < 0
              // Q = l, [P, Q] in [A, l] (-+0-).
              types[0] = (int) SHAREVERT;
              pos[0] = pu[0]; // A
              pos[1] = pv[0]; // P
              types[1] = (int) ACROSSEDGE;
              pos[2] = pu[1]; // [B, C]
              pos[3] = pv[0]; // [P, Q]
            }
          }
        } else { // s3 < 0
          if (s2 > 0) {
            if (s4 > 0) {
              // [P, Q] in [A, l] (-+-+).
              types[0] = (int) TOUCHFACE;
              pos[0] = 3;     // [A, B, C]
              pos[1] = pv[0]; // P
              types[0] = (int) TOUCHFACE;
              pos[0] = 3;     // [A, B, C]
              pos[1] = pv[1]; // Q
            } else {
              if (s4 == 0) {
                // Q = l, [P, Q] in [A, l] (-+-0).
                types[0] = (int) TOUCHFACE;
                pos[0] = 3;     // [A, B, C]
                pos[1] = pv[0]; // P
                types[0] = (int) TOUCHEDGE;
                pos[0] = pu[1]; // [B, C]
                pos[1] = pv[1]; // Q
              } else { // s4 < 0
                // [P, Q] overlaps [A, l] (-+--).
                types[0] = (int) TOUCHFACE;
                pos[0] = 3;     // [A, B, C]
                pos[1] = pv[0]; // P
                types[0] = (int) ACROSSEDGE;
                pos[0] = pu[1]; // [B, C]
                pos[1] = pv[0]; // [P, Q]
              }
            }
          } else { // s2 == 0
            // P = l (#0##).
            types[0] = (int) TOUCHEDGE;
            pos[0] = pu[1]; // [B, C]
            pos[1] = pv[0]; // P
            types[1] = (int) DISJOINT;
          }
        }
      }
    } else { // s1 == 0
      // Q = A (0###).
      types[0] = (int) SHAREVERT;
      pos[0] = pu[0]; // A
      pos[1] = pv[1]; // Q
      types[1] = (int) DISJOINT;
    }
  } else if (z1 == 3) {  // (tritri-33)
    if (s1 < 0) {
      if (s3 > 0) {
        if (s4 > 0) {
          // [P, Q] overlaps [A, B] (-+++).
          types[0] = (int) ACROSSVERT;
          pos[0] = pu[0]; // A
          pos[1] = pv[0]; // [P, Q]
          types[1] = (int) TOUCHEDGE;
          pos[2] = pu[0]; // [A, B]
          pos[3] = pv[1]; // Q
        } else {
          if (s4 == 0) {
            // Q = B, [P, Q] contains [A, B] (-++0).
            types[0] = (int) ACROSSVERT;
            pos[0] = pu[0]; // A
            pos[1] = pv[0]; // [P, Q]
            types[1] = (int) SHAREVERT;
            pos[2] = pu[1]; // B
            pos[3] = pv[1]; // Q
          } else { // s4 < 0
            // [P, Q] contains [A, B] (-++-).
            types[0] = (int) ACROSSVERT;
            pos[0] = pu[0]; // A
            pos[1] = pv[0]; // [P, Q]
            types[1] = (int) ACROSSVERT;
            pos[2] = pu[1]; // B
            pos[3] = pv[0]; // [P, Q]
          }
        }
      } else {
        if (s3 == 0) {
          if (s4 > 0) {
            // P = A, [P, Q] in [A, B] (-+0+).
            types[0] = (int) SHAREVERT;
            pos[0] = pu[0]; // A
            pos[1] = pv[0]; // P
            types[1] = (int) TOUCHEDGE;
            pos[2] = pu[0]; // [A, B]
            pos[3] = pv[1]; // Q
          } else {
            if (s4 == 0) {
              // [P, Q] = [A, B] (-+00).
              types[0] = (int) SHAREEDGE;
              pos[0] = pu[0]; // [A, B]
              pos[1] = pv[0]; // [P, Q]
              types[1] = (int) DISJOINT;
            } else { // s4 < 0
              // P= A, [P, Q] in [A, B] (-+0-).
              types[0] = (int) SHAREVERT;
              pos[0] = pu[0]; // A
              pos[1] = pv[0]; // P
              types[1] = (int) ACROSSVERT;
              pos[2] = pu[1]; // B
              pos[3] = pv[0]; // [P, Q]
            }
          }
        } else { // s3 < 0
          if (s2 > 0) {
            if (s4 > 0) {
              // [P, Q] in [A, B] (-+-+).
              types[0] = (int) TOUCHEDGE;
              pos[0] = pu[0]; // [A, B]
              pos[1] = pv[0]; // P
              types[1] = (int) TOUCHEDGE;
              pos[2] = pu[0]; // [A, B]
              pos[3] = pv[1]; // Q
            } else {
              if (s4 == 0) {
                // Q = B, [P, Q] in [A, B] (-+-0).
                types[0] = (int) TOUCHEDGE;
                pos[0] = pu[0]; // [A, B]
                pos[1] = pv[0]; // P
                types[1] = (int) SHAREVERT;
                pos[2] = pu[1]; // B
                pos[3] = pv[1]; // Q
              } else { // s4 < 0
                // [P, Q] overlaps [A, B] (-+--).
                types[0] = (int) TOUCHEDGE;
                pos[0] = pu[0]; // [A, B]
                pos[1] = pv[0]; // P
                types[1] = (int) ACROSSVERT;
                pos[2] = pu[1]; // B
                pos[3] = pv[0]; // [P, Q]
              }
            }
          } else { // s2 == 0
            // P = B (#0##).
            types[0] = (int) SHAREVERT;
            pos[0] = pu[1]; // B
            pos[1] = pv[0]; // P
            types[1] = (int) DISJOINT;
          }
        }
      }
    } else { // s1 == 0
      // Q = A (0###).
      types[0] = (int) SHAREVERT;
      pos[0] = pu[0]; // A
      pos[1] = pv[1]; // Q
      types[1] = (int) DISJOINT;
    }
  }

  return 4;
}

int tri_edge_tail(point A,point B,point C,point P,point Q,point R,
                              REAL sP,REAL sQ,int level,int *types,int *pos)
{
  point U[3], V[3]; //, Ptmp;
  int pu[3], pv[3]; //, itmp;
  REAL s1, s2, s3;
  int z1;


  if (sP < 0) {
    if (sQ < 0) { // (--) disjoint
      return 0;
    } else {
      if (sQ > 0) { // (-+)
        SETVECTOR3(U, A, B, C);
        SETVECTOR3(V, P, Q, R);
        SETVECTOR3(pu, 0, 1, 2);
        SETVECTOR3(pv, 0, 1, 2);
        z1 = 0;
      } else { // (-0)
        SETVECTOR3(U, A, B, C);
        SETVECTOR3(V, P, Q, R);
        SETVECTOR3(pu, 0, 1, 2);
        SETVECTOR3(pv, 0, 1, 2);
        z1 = 1;
      }
    }
  } else {
    if (sP > 0) { // (+-)
      if (sQ < 0) {
        SETVECTOR3(U, A, B, C);
        SETVECTOR3(V, Q, P, R);  // P and Q are flipped.
        SETVECTOR3(pu, 0, 1, 2);
        SETVECTOR3(pv, 1, 0, 2);
        z1 = 0;
      } else {
        if (sQ > 0) { // (++) disjoint
          return 0;
        } else { // (+0)
          SETVECTOR3(U, B, A, C); // A and B are flipped.
          SETVECTOR3(V, P, Q, R);
          SETVECTOR3(pu, 1, 0, 2);
          SETVECTOR3(pv, 0, 1, 2);
          z1 = 1;
        }
      }
    } else { // sP == 0
      if (sQ < 0) { // (0-)
        SETVECTOR3(U, A, B, C);
        SETVECTOR3(V, Q, P, R);  // P and Q are flipped.
        SETVECTOR3(pu, 0, 1, 2);
        SETVECTOR3(pv, 1, 0, 2);
        z1 = 1;
      } else {
        if (sQ > 0) { // (0+)
          SETVECTOR3(U, B, A, C);  // A and B are flipped.
          SETVECTOR3(V, Q, P, R);  // P and Q are flipped.
          SETVECTOR3(pu, 1, 0, 2);
          SETVECTOR3(pv, 1, 0, 2);
          z1 = 1;
        } else { // (00)
          // A, B, C, P, and Q are coplanar.
          z1 = 2;
        }
      }
    }
  }

  if (z1 == 2) {
    // The triangle and the edge are coplanar.
    return tri_edge_2d(A, B, C, P, Q, R, level, types, pos);
  }

  s1 = orient3d(U[0], U[1], V[0], V[1]);
  if (s1 < 0) {
    return 0;
  }

  s2 = orient3d(U[1], U[2], V[0], V[1]);
  if (s2 < 0) {
    return 0;
  }

  s3 = orient3d(U[2], U[0], V[0], V[1]);
  if (s3 < 0) {
    return 0;
  }

  if (level == 0) {
    return 1;  // The are intersected.
  }

  types[1] = (int) DISJOINT; // No second intersection point.

  if (z1 == 0) {
    if (s1 > 0) {
      if (s2 > 0) {
        if (s3 > 0) { // (+++)
          // [P, Q] passes interior of [A, B, C].
          types[0] = (int) ACROSSFACE;
          pos[0] = 3;  // interior of [A, B, C]
          pos[1] = 0;  // [P, Q]
        } else { // s3 == 0 (++0)
          // [P, Q] intersects [C, A].
          types[0] = (int) ACROSSEDGE;
          pos[0] = pu[2];  // [C, A]
          pos[1] = 0;  // [P, Q]
        }
      } else { // s2 == 0
        if (s3 > 0) { // (+0+)
          // [P, Q] intersects [B, C].
          types[0] = (int) ACROSSEDGE;
          pos[0] = pu[1];  // [B, C]
          pos[1] = 0;  // [P, Q]
        } else { // s3 == 0 (+00)
          // [P, Q] passes C.
          types[0] = (int) ACROSSVERT;
          pos[0] = pu[2];  // C
          pos[1] = 0;  // [P, Q]
        }
      }
    } else { // s1 == 0
      if (s2 > 0) {
        if (s3 > 0) { // (0++)
          // [P, Q] intersects [A, B].
          types[0] = (int) ACROSSEDGE;
          pos[0] = pu[0];  // [A, B]
          pos[1] = 0;  // [P, Q]
        } else { // s3 == 0 (0+0)
          // [P, Q] passes A.
          types[0] = (int) ACROSSVERT;
          pos[0] = pu[0];  // A
          pos[1] = 0;  // [P, Q]
        }
      } else { // s2 == 0
        if (s3 > 0) { // (00+)
          // [P, Q] passes B.
          types[0] = (int) ACROSSVERT;
          pos[0] = pu[1];  // B
          pos[1] = 0;  // [P, Q]
        }
      }
    }
  } else { // z1 == 1
    if (s1 > 0) {
      if (s2 > 0) {
        if (s3 > 0) { // (+++)
          // Q lies in [A, B, C].
          types[0] = (int) TOUCHFACE;
          pos[0] = 0; // [A, B, C]
          pos[1] = pv[1]; // Q
        } else { // s3 == 0 (++0)
          // Q lies on [C, A].
          types[0] = (int) TOUCHEDGE;
          pos[0] = pu[2]; // [C, A]
          pos[1] = pv[1]; // Q
        }
      } else { // s2 == 0
        if (s3 > 0) { // (+0+)
          // Q lies on [B, C].
          types[0] = (int) TOUCHEDGE;
          pos[0] = pu[1]; // [B, C]
          pos[1] = pv[1]; // Q
        } else { // s3 == 0 (+00)
          // Q = C.
          types[0] = (int) SHAREVERT;
          pos[0] = pu[2]; // C
          pos[1] = pv[1]; // Q
        }
      }
    } else { // s1 == 0
      if (s2 > 0) {
        if (s3 > 0) { // (0++)
          // Q lies on [A, B].
          types[0] = (int) TOUCHEDGE;
          pos[0] = pu[0]; // [A, B]
          pos[1] = pv[1]; // Q
        } else { // s3 == 0 (0+0)
          // Q = A.
          types[0] = (int) SHAREVERT;
          pos[0] = pu[0]; // A
          pos[1] = pv[1]; // Q
        }
      } else { // s2 == 0
        if (s3 > 0) { // (00+)
          // Q = B.
          types[0] = (int) SHAREVERT;
          pos[0] = pu[1]; // B
          pos[1] = pv[1]; // Q
        }
      }
    }
  }

  // T and E intersect in a single point.
  return 2;
}

int tri_edge_test(point A, point B, point C, point P, point Q,
                              point R, int level, int *types, int *pos)
{
  REAL sP, sQ;

  // Test the locations of P and Q with respect to ABC.
  sP = orient3d(A, B, C, P);
  sQ = orient3d(A, B, C, Q);

  return tri_edge_tail(A, B, C, P, Q, R, sP, sQ, level, types, pos);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// tri_tri_inter()    Test whether two triangle (abc) and (opq) are          //
//                    intersecting or not.                                   //
//                                                                           //
// Return 0 if they are disjoint. Otherwise, return 1. 'type' returns one of //
// the four cases: SHAREVERTEX, SHAREEDGE, SHAREFACE, and INTERSECT.         //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

int tri_edge_inter_tail(REAL* A, REAL* B, REAL* C,  REAL* P,
                                    REAL* Q, REAL s_p, REAL s_q)
{
  int types[2], pos[4];
  int ni;  // =0, 2, 4

  ni = tri_edge_tail(A, B, C, P, Q, NULL, s_p, s_q, 1, types, pos);

  if (ni > 0) {
    if (ni == 2) {
      // Get the intersection type.
      if (types[0] == (int) SHAREVERT) {
        return (int) SHAREVERT;
      } else {
        return (int) INTERSECT;
      }
    } else if (ni == 4) {
      // There may be two intersections.
      if (types[0] == (int) SHAREVERT) {
        if (types[1] == (int) DISJOINT) {
          return (int) SHAREVERT;
        } else {
          return (int) INTERSECT;
        }
      } else {
        if (types[0] == (int) SHAREEDGE) {
          return (int) SHAREEDGE;
        } else {
          return (int) INTERSECT;
        }
      }
    }
  }

  return (int) DISJOINT;
}

int tri_tri_inter(REAL* A,REAL* B,REAL* C,REAL* O,REAL* P,REAL* Q)
{
  REAL s_o, s_p, s_q;
  REAL s_a, s_b, s_c;

  s_o = orient3d(A, B, C, O);
  s_p = orient3d(A, B, C, P);
  s_q = orient3d(A, B, C, Q);
  if ((s_o * s_p > 0.0) && (s_o * s_q > 0.0)) {
    // o, p, q are all in the same halfspace of ABC.
    return 0; // DISJOINT;
  }

  s_a = orient3d(O, P, Q, A);
  s_b = orient3d(O, P, Q, B);
  s_c = orient3d(O, P, Q, C);
  if ((s_a * s_b > 0.0) && (s_a * s_c > 0.0)) {
    // a, b, c are all in the same halfspace of OPQ.
    return 0; // DISJOINT;
  }

  int abcop, abcpq, abcqo;
  int shareedge = 0;

  abcop = tri_edge_inter_tail(A, B, C, O, P, s_o, s_p);
  if (abcop == (int) INTERSECT) {
    return (int) INTERSECT;
  } else if (abcop == (int) SHAREEDGE) {
    shareedge++;
  }
  abcpq = tri_edge_inter_tail(A, B, C, P, Q, s_p, s_q);
  if (abcpq == (int) INTERSECT) {
    return (int) INTERSECT;
  } else if (abcpq == (int) SHAREEDGE) {
    shareedge++;
  }
  abcqo = tri_edge_inter_tail(A, B, C, Q, O, s_q, s_o);
  if (abcqo == (int) INTERSECT) {
    return (int) INTERSECT;
  } else if (abcqo == (int) SHAREEDGE) {
    shareedge++;
  }
  if (shareedge == 3) {
    // opq are coincident with abc.
    return (int) SHAREFACE;
  }

  // Continue to detect whether opq and abc are intersecting or not.
  int opqab, opqbc, opqca;

  opqab = tri_edge_inter_tail(O, P, Q, A, B, s_a, s_b);
  if (opqab == (int) INTERSECT) {
    return (int) INTERSECT;
  }
  opqbc = tri_edge_inter_tail(O, P, Q, B, C, s_b, s_c);
  if (opqbc == (int) INTERSECT) {
    return (int) INTERSECT;
  }
  opqca = tri_edge_inter_tail(O, P, Q, C, A, s_c, s_a);
  if (opqca == (int) INTERSECT) {
    return (int) INTERSECT;
  }

  // At this point, two triangles are not intersecting and not coincident.
  //   They may be share an edge, or share a vertex, or disjoint.
  if (abcop == (int) SHAREEDGE) {
    // op is coincident with an edge of abc.
    return (int) SHAREEDGE;
  }
  if (abcpq == (int) SHAREEDGE) {
    // pq is coincident with an edge of abc.
    return (int) SHAREEDGE;
  }
  if (abcqo == (int) SHAREEDGE) {
    // qo is coincident with an edge of abc.
    return (int) SHAREEDGE;
  }

  // They may share a vertex or disjoint.
  if (abcop == (int) SHAREVERT) {
    return (int) SHAREVERT;
  }
  if (abcpq == (int) SHAREVERT) {
    // q is the coincident vertex.
    return (int) SHAREVERT;
  }

  // They are disjoint.
  return (int) DISJOINT;
}


}
