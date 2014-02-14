// Gmsh - Copyright (C) 1997-2014 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include "meshGRegionBoundaryRecovery.h"
#include "robustPredicates.h"
#include "GFace.h"
#include "MVertex.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MTetrahedron.h"
#include "meshGRegionDelaunayInsertion.h"

#define orient3d robustPredicates::orient3d
#define insphere robustPredicates::insphere

#ifdef _MSC_VER // Microsoft Visual C++
#  ifdef _WIN64
     typedef __int64 intptr_t;
     typedef unsigned __int64 uintptr_t;
#  else // not _WIN64
     typedef int intptr_t;
     typedef unsigned int uintptr_t;
#  endif
#else // not Visual C++
#  include <stdint.h>
#endif

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Primitives for tetrahedra                                                 //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

inline meshGRegionBoundaryRecovery::tetrahedron
  meshGRegionBoundaryRecovery::encode(triface& t) {
  return (tetrahedron) ((uintptr_t) (t).tet | (uintptr_t) (t).ver);
}

inline meshGRegionBoundaryRecovery::tetrahedron
  meshGRegionBoundaryRecovery::encode2(tetrahedron* ptr, int ver) {
  return (tetrahedron) ((uintptr_t) (ptr) | (uintptr_t) (ver));
}

inline void meshGRegionBoundaryRecovery::decode(tetrahedron ptr, triface& t) {
  (t).ver = (int) ((uintptr_t) (ptr) & (uintptr_t) 15);
  (t).tet = (tetrahedron *) ((uintptr_t) (ptr) ^ (uintptr_t) (t).ver);
}

inline void meshGRegionBoundaryRecovery::bond(triface& t1, triface& t2) {
  t1.tet[t1.ver & 3] = encode2(t2.tet, bondtbl[t1.ver][t2.ver]);
  t2.tet[t2.ver & 3] = encode2(t1.tet, bondtbl[t2.ver][t1.ver]);
}

inline void meshGRegionBoundaryRecovery::dissolve(triface& t) {
  t.tet[t.ver & 3] = NULL;
}

inline void meshGRegionBoundaryRecovery::enext(triface& t1, triface& t2) {
  t2.tet = t1.tet;
  t2.ver = enexttbl[t1.ver];
}

inline void meshGRegionBoundaryRecovery::enextself(triface& t) {
  t.ver = enexttbl[t.ver];
}

inline void meshGRegionBoundaryRecovery::eprev(triface& t1, triface& t2) {
  t2.tet = t1.tet;
  t2.ver = eprevtbl[t1.ver];
}

inline void meshGRegionBoundaryRecovery::eprevself(triface& t) {
  t.ver = eprevtbl[t.ver];
}

inline void meshGRegionBoundaryRecovery::esym(triface& t1, triface& t2) {
  (t2).tet = (t1).tet;
  (t2).ver = esymtbl[(t1).ver];
}

inline void meshGRegionBoundaryRecovery::esymself(triface& t) {
  (t).ver = esymtbl[(t).ver];
}

inline void meshGRegionBoundaryRecovery::enextesym(triface& t1, triface& t2) {
  t2.tet = t1.tet;
  t2.ver = enextesymtbl[t1.ver];
}

inline void meshGRegionBoundaryRecovery::enextesymself(triface& t) {
  t.ver = enextesymtbl[t.ver];
}

inline void meshGRegionBoundaryRecovery::eprevesym(triface& t1, triface& t2) {
  t2.tet = t1.tet;
  t2.ver = eprevesymtbl[t1.ver];
}

inline void meshGRegionBoundaryRecovery::eprevesymself(triface& t) {
  t.ver = eprevesymtbl[t.ver];
}

inline void meshGRegionBoundaryRecovery::eorgoppo(triface& t1, triface& t2) {
  t2.tet = t1.tet;
  t2.ver = eorgoppotbl[t1.ver];
}

inline void meshGRegionBoundaryRecovery::eorgoppoself(triface& t) {
  t.ver = eorgoppotbl[t.ver];
}

inline void meshGRegionBoundaryRecovery::edestoppo(triface& t1, triface& t2) {
  t2.tet = t1.tet;
  t2.ver = edestoppotbl[t1.ver];
}

inline void meshGRegionBoundaryRecovery::edestoppoself(triface& t) {
  t.ver = edestoppotbl[t.ver];
}

inline void meshGRegionBoundaryRecovery::fsym(triface& t1, triface& t2) {
  decode((t1).tet[(t1).ver & 3], t2);
  t2.ver = fsymtbl[t1.ver][t2.ver];
}

#define fsymself(t) \
  t1ver = (t).ver; \
  decode((t).tet[(t).ver & 3], (t));\
  (t).ver = fsymtbl[t1ver][(t).ver]

inline void meshGRegionBoundaryRecovery::fnext(triface& t1, triface& t2) {
  decode(t1.tet[facepivot1[t1.ver]], t2);
  t2.ver = facepivot2[t1.ver][t2.ver];
}

#define fnextself(t) \
  t1ver = (t).ver; \
  decode((t).tet[facepivot1[(t).ver]], (t)); \
  (t).ver = facepivot2[t1ver][(t).ver]


inline meshGRegionBoundaryRecovery::point
  meshGRegionBoundaryRecovery::org(triface& t) {
  return (point) (t).tet[orgpivot[(t).ver]];
}

inline meshGRegionBoundaryRecovery::point
  meshGRegionBoundaryRecovery:: dest(triface& t) {
  return (point) (t).tet[destpivot[(t).ver]];
}

inline meshGRegionBoundaryRecovery::point
  meshGRegionBoundaryRecovery::apex(triface& t) {
  return (point) (t).tet[apexpivot[(t).ver]];
}

inline meshGRegionBoundaryRecovery::point
  meshGRegionBoundaryRecovery::oppo(triface& t) {
  return (point) (t).tet[oppopivot[(t).ver]];
}

inline void meshGRegionBoundaryRecovery::setorg(triface& t, point p) {
  (t).tet[orgpivot[(t).ver]] = (tetrahedron) (p);
}

inline void meshGRegionBoundaryRecovery::setdest(triface& t, point p) {
  (t).tet[destpivot[(t).ver]] = (tetrahedron) (p);
}

inline void meshGRegionBoundaryRecovery:: setapex(triface& t, point p) {
  (t).tet[apexpivot[(t).ver]] = (tetrahedron) (p);
}

inline void meshGRegionBoundaryRecovery::setoppo(triface& t, point p) {
  (t).tet[oppopivot[(t).ver]] = (tetrahedron) (p);
}

#define setvertices(t, torg, tdest, tapex, toppo) \
  (t).tet[orgpivot[(t).ver]] = (tetrahedron) (torg);\
  (t).tet[destpivot[(t).ver]] = (tetrahedron) (tdest); \
  (t).tet[apexpivot[(t).ver]] = (tetrahedron) (tapex); \
  (t).tet[oppopivot[(t).ver]] = (tetrahedron) (toppo)

inline REAL meshGRegionBoundaryRecovery::elemattribute(tetrahedron* ptr,
  int attnum) {
  return ((REAL *) (ptr))[elemattribindex + attnum];
}

inline void meshGRegionBoundaryRecovery::setelemattribute(tetrahedron* ptr,
  int attnum,
  REAL value) {
  ((REAL *) (ptr))[elemattribindex + attnum] = value;
}

inline REAL meshGRegionBoundaryRecovery::volumebound(tetrahedron* ptr) {
  return ((REAL *) (ptr))[volumeboundindex];
}

inline void meshGRegionBoundaryRecovery::setvolumebound(tetrahedron* ptr,
  REAL value) {
  ((REAL *) (ptr))[volumeboundindex] = value;
}

inline int meshGRegionBoundaryRecovery::elemindex(tetrahedron* ptr) {
  int *iptr = (int *) &(ptr[10]);
  return iptr[0];
}

inline void meshGRegionBoundaryRecovery::setelemindex(tetrahedron* ptr,
  int value) {
  int *iptr = (int *) &(ptr[10]);
  iptr[0] = value;
}

inline int meshGRegionBoundaryRecovery::elemmarker(tetrahedron* ptr) {
  return ((int *) (ptr))[elemmarkerindex];
}

inline void meshGRegionBoundaryRecovery::setelemmarker(tetrahedron* ptr,
  int value) {
  ((int *) (ptr))[elemmarkerindex] = value;
}

inline void meshGRegionBoundaryRecovery::infect(triface& t) {
  ((int *) (t.tet))[elemmarkerindex] |= 1;
}

inline void meshGRegionBoundaryRecovery::uninfect(triface& t) {
  ((int *) (t.tet))[elemmarkerindex] &= ~1;
}

inline bool meshGRegionBoundaryRecovery::infected(triface& t) {
  return (((int *) (t.tet))[elemmarkerindex] & 1) != 0;
}

inline void meshGRegionBoundaryRecovery::marktest(triface& t) {
  ((int *) (t.tet))[elemmarkerindex] |= 2;
}

inline void meshGRegionBoundaryRecovery::unmarktest(triface& t) {
  ((int *) (t.tet))[elemmarkerindex] &= ~2;
}

inline bool meshGRegionBoundaryRecovery::marktested(triface& t) {
  return (((int *) (t.tet))[elemmarkerindex] & 2) != 0;
}

inline void meshGRegionBoundaryRecovery::markface(triface& t) {
  ((int *) (t.tet))[elemmarkerindex] |= (4 << (t.ver & 3));
}

inline void meshGRegionBoundaryRecovery::unmarkface(triface& t) {
  ((int *) (t.tet))[elemmarkerindex] &= ~(4 << (t.ver & 3));
}

inline bool meshGRegionBoundaryRecovery::facemarked(triface& t) {
  return (((int *) (t.tet))[elemmarkerindex] & (4 << (t.ver & 3))) != 0;
}

inline void meshGRegionBoundaryRecovery::markedge(triface& t) {
  ((int *) (t.tet))[elemmarkerindex] |= (int) (64 << ver2edge[(t).ver]);
}

inline void meshGRegionBoundaryRecovery::unmarkedge(triface& t) {
  ((int *) (t.tet))[elemmarkerindex] &= ~(int) (64 << ver2edge[(t).ver]);
}

inline bool meshGRegionBoundaryRecovery::edgemarked(triface& t) {
  return (((int *) (t.tet))[elemmarkerindex] &
           (int) (64 << ver2edge[(t).ver])) != 0;
}

inline void meshGRegionBoundaryRecovery::marktest2(triface& t) {
  ((int *) (t.tet))[elemmarkerindex] |= (int) (4096);
}

inline void meshGRegionBoundaryRecovery::unmarktest2(triface& t) {
  ((int *) (t.tet))[elemmarkerindex] &= ~(int) (4096);
}

inline bool meshGRegionBoundaryRecovery::marktest2ed(triface& t) {
  return (((int *) (t.tet))[elemmarkerindex] & (int) (4096)) != 0;
}

inline int meshGRegionBoundaryRecovery::elemcounter(triface& t) {
  return (((int *) (t.tet))[elemmarkerindex]) >> 16;
}

inline void meshGRegionBoundaryRecovery::setelemcounter(triface& t, int value) {
  int c = ((int *) (t.tet))[elemmarkerindex];
  // Clear the old counter while keep the other flags.
  c &= 65535; // sum_{i=0^15} 2^i
  c |= (value << 16);
  ((int *) (t.tet))[elemmarkerindex] = c;
}

inline void meshGRegionBoundaryRecovery::increaseelemcounter(triface& t) {
  int c = elemcounter(t);
  setelemcounter(t, c + 1);
}

inline void meshGRegionBoundaryRecovery::decreaseelemcounter(triface& t) {
  int c = elemcounter(t);
  setelemcounter(t, c - 1);
}

inline bool meshGRegionBoundaryRecovery::ishulltet(triface& t) {
  return (point) (t).tet[7] == dummypoint;
}

inline bool meshGRegionBoundaryRecovery::isdeadtet(triface& t) {
  return ((t.tet == NULL) || (t.tet[4] == NULL));
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Primitives for subfaces and subsegments                                   //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

inline void meshGRegionBoundaryRecovery::sdecode(shellface sptr, face& s) {
  s.shver = (int) ((uintptr_t) (sptr) & (uintptr_t) 7);
  s.sh = (shellface *) ((uintptr_t) (sptr) ^ (uintptr_t) (s.shver));
}

inline meshGRegionBoundaryRecovery::shellface
  meshGRegionBoundaryRecovery::sencode(face& s) {
  return (shellface) ((uintptr_t) s.sh | (uintptr_t) s.shver);
}

inline meshGRegionBoundaryRecovery::shellface
  meshGRegionBoundaryRecovery::sencode2(shellface *sh, int shver) {
  return (shellface) ((uintptr_t) sh | (uintptr_t) shver);
}

inline void meshGRegionBoundaryRecovery::sbond(face& s1, face& s2) {
  s1.sh[s1.shver >> 1] = sencode(s2);
  s2.sh[s2.shver >> 1] = sencode(s1);
}

inline void meshGRegionBoundaryRecovery::sbond1(face& s1, face& s2) {
  s1.sh[s1.shver >> 1] = sencode(s2);
}

inline void meshGRegionBoundaryRecovery::sdissolve(face& s) {
  s.sh[s.shver >> 1] = NULL;
}

inline void meshGRegionBoundaryRecovery::spivot(face& s1, face& s2) {
  shellface sptr = s1.sh[s1.shver >> 1];
  sdecode(sptr, s2);
}

inline void meshGRegionBoundaryRecovery::spivotself(face& s) {
  shellface sptr = s.sh[s.shver >> 1];
  sdecode(sptr, s);
}

inline meshGRegionBoundaryRecovery::point
  meshGRegionBoundaryRecovery::sorg(face& s) {
  return (point) s.sh[sorgpivot[s.shver]];
}

inline meshGRegionBoundaryRecovery::point
  meshGRegionBoundaryRecovery::sdest(face& s) {
  return (point) s.sh[sdestpivot[s.shver]];
}

inline meshGRegionBoundaryRecovery::point
  meshGRegionBoundaryRecovery::sapex(face& s) {
  return (point) s.sh[sapexpivot[s.shver]];
}

inline void meshGRegionBoundaryRecovery::setsorg(face& s, point pointptr) {
  s.sh[sorgpivot[s.shver]] = (shellface) pointptr;
}

inline void meshGRegionBoundaryRecovery::setsdest(face& s, point pointptr) {
  s.sh[sdestpivot[s.shver]] = (shellface) pointptr;
}

inline void meshGRegionBoundaryRecovery::setsapex(face& s, point pointptr) {
  s.sh[sapexpivot[s.shver]] = (shellface) pointptr;
}

#define setshvertices(s, pa, pb, pc)\
  setsorg(s, pa);\
  setsdest(s, pb);\
  setsapex(s, pc)

inline void meshGRegionBoundaryRecovery::sesym(face& s1, face& s2) {
  s2.sh = s1.sh;
  s2.shver = (s1.shver ^ 1);  // Inverse the last bit.
}

inline void meshGRegionBoundaryRecovery::sesymself(face& s) {
  s.shver ^= 1;
}

inline void meshGRegionBoundaryRecovery::senext(face& s1, face& s2) {
  s2.sh = s1.sh;
  s2.shver = snextpivot[s1.shver];
}

inline void meshGRegionBoundaryRecovery::senextself(face& s) {
  s.shver = snextpivot[s.shver];
}

inline void meshGRegionBoundaryRecovery::senext2(face& s1, face& s2) {
  s2.sh = s1.sh;
  s2.shver = snextpivot[snextpivot[s1.shver]];
}

inline void meshGRegionBoundaryRecovery::senext2self(face& s) {
  s.shver = snextpivot[snextpivot[s.shver]];
}


inline REAL meshGRegionBoundaryRecovery::areabound(face& s) {
  return ((REAL *) (s.sh))[areaboundindex];
}

inline void meshGRegionBoundaryRecovery::setareabound(face& s, REAL value) {
  ((REAL *) (s.sh))[areaboundindex] = value;
}

inline int meshGRegionBoundaryRecovery::shellmark(face& s) {
  return ((int *) (s.sh))[shmarkindex];
}

inline void meshGRegionBoundaryRecovery::setshellmark(face& s, int value) {
  ((int *) (s.sh))[shmarkindex] = value;
}

inline void meshGRegionBoundaryRecovery::sinfect(face& s) {
  ((int *) ((s).sh))[shmarkindex+1] =
    (((int *) ((s).sh))[shmarkindex+1] | (int) 1);
}

inline void meshGRegionBoundaryRecovery::suninfect(face& s) {
  ((int *) ((s).sh))[shmarkindex+1] =
    (((int *) ((s).sh))[shmarkindex+1] & ~(int) 1);
}

inline bool meshGRegionBoundaryRecovery::sinfected(face& s) {
  return (((int *) ((s).sh))[shmarkindex+1] & (int) 1) != 0;
}

inline void meshGRegionBoundaryRecovery::smarktest(face& s) {
  ((int *) ((s).sh))[shmarkindex+1] =
    (((int *)((s).sh))[shmarkindex+1] | (int) 2);
}

inline void meshGRegionBoundaryRecovery::sunmarktest(face& s) {
  ((int *) ((s).sh))[shmarkindex+1] =
    (((int *)((s).sh))[shmarkindex+1] & ~(int)2);
}

inline bool meshGRegionBoundaryRecovery::smarktested(face& s) {
  return ((((int *) ((s).sh))[shmarkindex+1] & (int) 2) != 0);
}

inline void meshGRegionBoundaryRecovery::smarktest2(face& s) {
  ((int *) ((s).sh))[shmarkindex+1] =
    (((int *)((s).sh))[shmarkindex+1] | (int) 4);
}

inline void meshGRegionBoundaryRecovery::sunmarktest2(face& s) {
  ((int *) ((s).sh))[shmarkindex+1] =
    (((int *)((s).sh))[shmarkindex+1] & ~(int)4);
}

inline bool meshGRegionBoundaryRecovery::smarktest2ed(face& s) {
  return ((((int *) ((s).sh))[shmarkindex+1] & (int) 4) != 0);
}

inline void meshGRegionBoundaryRecovery::smarktest3(face& s) {
  ((int *) ((s).sh))[shmarkindex+1] =
    (((int *)((s).sh))[shmarkindex+1] | (int) 8);
}

inline void meshGRegionBoundaryRecovery::sunmarktest3(face& s) {
  ((int *) ((s).sh))[shmarkindex+1] =
    (((int *)((s).sh))[shmarkindex+1] & ~(int)8);
}

inline bool meshGRegionBoundaryRecovery::smarktest3ed(face& s) {
  return ((((int *) ((s).sh))[shmarkindex+1] & (int) 8) != 0);
}

inline void meshGRegionBoundaryRecovery::setfacetindex(face& s, int value) {
  ((int *) (s.sh))[shmarkindex + 2] = value;
}

inline int meshGRegionBoundaryRecovery::getfacetindex(face& s) {
  return ((int *) (s.sh))[shmarkindex + 2];
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Primitives for interacting between tetrahedra and subfaces                //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

inline void meshGRegionBoundaryRecovery::tsbond(triface& t, face& s) {
  if ((t).tet[9] == NULL) {
    // Allocate space for this tet.
    (t).tet[9] = (tetrahedron) tet2subpool->alloc();
    // Initialize.
    for (int i = 0; i < 4; i++) {
      ((shellface *) (t).tet[9])[i] = NULL;
    }
  }
  // Bond t <== s.
  ((shellface *) (t).tet[9])[(t).ver & 3] =
    sencode2((s).sh, tsbondtbl[t.ver][s.shver]);
  // Bond s <== t.
  s.sh[9 + ((s).shver & 1)] =
    (shellface) encode2((t).tet, stbondtbl[t.ver][s.shver]);
}

inline void meshGRegionBoundaryRecovery::tspivot(triface& t, face& s) {
  if ((t).tet[9] == NULL) {
    (s).sh = NULL;
    return;
  }
  // Get the attached subface s.
  sdecode(((shellface *) (t).tet[9])[(t).ver & 3], (s));
  (s).shver = tspivottbl[t.ver][s.shver];
}

// Quickly check if the handle (t, v) is a subface.
#define issubface(t) \
  ((t).tet[9] && ((t).tet[9])[(t).ver & 3])

inline void meshGRegionBoundaryRecovery::stpivot(face& s, triface& t) {
  decode((tetrahedron) s.sh[9 + (s.shver & 1)], t);
  if ((t).tet == NULL) {
    return;
  }
  (t).ver = stpivottbl[t.ver][s.shver];
}

#define isshtet(s) \
  ((s).sh[9 + ((s).shver & 1)])

inline void meshGRegionBoundaryRecovery::tsdissolve(triface& t) {
  if ((t).tet[9] != NULL) {
    ((shellface *) (t).tet[9])[(t).ver & 3] = NULL;
  }
}

inline void meshGRegionBoundaryRecovery::stdissolve(face& s) {
  (s).sh[9] = NULL;
  (s).sh[10] = NULL;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Primitives for interacting between subfaces and segments                  //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

inline void meshGRegionBoundaryRecovery::ssbond(face& s, face& edge) {
  s.sh[6 + (s.shver >> 1)] = sencode(edge);
  edge.sh[0] = sencode(s);
}

inline void meshGRegionBoundaryRecovery::ssbond1(face& s, face& edge) {
  s.sh[6 + (s.shver >> 1)] = sencode(edge);
  //edge.sh[0] = sencode(s);
}

inline void meshGRegionBoundaryRecovery::ssdissolve(face& s) {
  s.sh[6 + (s.shver >> 1)] = NULL;
}

inline void meshGRegionBoundaryRecovery::sspivot(face& s, face& edge) {
  sdecode((shellface) s.sh[6 + (s.shver >> 1)], edge);
}

#define isshsubseg(s) \
  ((s).sh[6 + ((s).shver >> 1)])

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Primitives for interacting between tetrahedra and segments                //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

inline void meshGRegionBoundaryRecovery::tssbond1(triface& t, face& s) {
  if ((t).tet[8] == NULL) {
    // Allocate space for this tet.
    (t).tet[8] = (tetrahedron) tet2segpool->alloc();
    // Initialization.
    for (int i = 0; i < 6; i++) {
      ((shellface *) (t).tet[8])[i] = NULL;
    }
  }
  ((shellface *) (t).tet[8])[ver2edge[(t).ver]] = sencode((s));
}

inline void meshGRegionBoundaryRecovery::sstbond1(face& s, triface& t) {
  ((tetrahedron *) (s).sh)[9] = encode(t);
}

inline void meshGRegionBoundaryRecovery::tssdissolve1(triface& t) {
  if ((t).tet[8] != NULL) {
    ((shellface *) (t).tet[8])[ver2edge[(t).ver]] = NULL;
  }
}

inline void meshGRegionBoundaryRecovery::sstdissolve1(face& s) {
  ((tetrahedron *) (s).sh)[9] = NULL;
}

inline void meshGRegionBoundaryRecovery::tsspivot1(triface& t, face& s) {
  if ((t).tet[8] != NULL) {
    sdecode(((shellface *) (t).tet[8])[ver2edge[(t).ver]], s);
  } else {
    (s).sh = NULL;
  }
}

#define issubseg(t) \
  ((t).tet[8] && ((t).tet[8])[ver2edge[(t).ver]])

inline void meshGRegionBoundaryRecovery::sstpivot1(face& s, triface& t) {
  decode((tetrahedron) s.sh[9], t);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Primitives for points                                                     //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

inline int meshGRegionBoundaryRecovery::pointmark(point pt) {
  return ((int *) (pt))[pointmarkindex];
}

inline void meshGRegionBoundaryRecovery::setpointmark(point pt, int value) {
  ((int *) (pt))[pointmarkindex] = value;
}


inline enum meshGRegionBoundaryRecovery::verttype
  meshGRegionBoundaryRecovery::pointtype(point pt) {
  return (enum verttype) (((int *) (pt))[pointmarkindex + 1] >> (int) 8);
}

inline void meshGRegionBoundaryRecovery::setpointtype(point pt,
  enum verttype value) {
  ((int *) (pt))[pointmarkindex + 1] =
    ((int) value << 8) + (((int *) (pt))[pointmarkindex + 1] & (int) 255);
}

inline int meshGRegionBoundaryRecovery::pointgeomtag(point pt) {
  return ((int *) (pt))[pointmarkindex + 2];
}

inline void meshGRegionBoundaryRecovery::setpointgeomtag(point pt, int value) {
  ((int *) (pt))[pointmarkindex + 2] = value;
}

inline REAL meshGRegionBoundaryRecovery::pointgeomuv(point pt, int i) {
  return pt[pointparamindex + i];
}

inline void meshGRegionBoundaryRecovery::setpointgeomuv(point pt, int i,
  REAL value) {
  pt[pointparamindex + i] = value;
}

inline void meshGRegionBoundaryRecovery::pinfect(point pt) {
  ((int *) (pt))[pointmarkindex + 1] |= (int) 1;
}

inline void meshGRegionBoundaryRecovery::puninfect(point pt) {
  ((int *) (pt))[pointmarkindex + 1] &= ~(int) 1;
}

inline bool meshGRegionBoundaryRecovery::pinfected(point pt) {
  return (((int *) (pt))[pointmarkindex + 1] & (int) 1) != 0;
}

inline void meshGRegionBoundaryRecovery::pmarktest(point pt) {
  ((int *) (pt))[pointmarkindex + 1] |= (int) 2;
}

inline void meshGRegionBoundaryRecovery::punmarktest(point pt) {
  ((int *) (pt))[pointmarkindex + 1] &= ~(int) 2;
}

inline bool meshGRegionBoundaryRecovery::pmarktested(point pt) {
  return (((int *) (pt))[pointmarkindex + 1] & (int) 2) != 0;
}

inline void meshGRegionBoundaryRecovery::pmarktest2(point pt) {
  ((int *) (pt))[pointmarkindex + 1] |= (int) 4;
}

inline void meshGRegionBoundaryRecovery::punmarktest2(point pt) {
  ((int *) (pt))[pointmarkindex + 1] &= ~(int) 4;
}

inline bool meshGRegionBoundaryRecovery::pmarktest2ed(point pt) {
  return (((int *) (pt))[pointmarkindex + 1] & (int) 4) != 0;
}

inline void meshGRegionBoundaryRecovery::pmarktest3(point pt) {
  ((int *) (pt))[pointmarkindex + 1] |= (int) 8;
}

inline void meshGRegionBoundaryRecovery::punmarktest3(point pt) {
  ((int *) (pt))[pointmarkindex + 1] &= ~(int) 8;
}

inline bool meshGRegionBoundaryRecovery::pmarktest3ed(point pt) {
  return (((int *) (pt))[pointmarkindex + 1] & (int) 8) != 0;
}

inline meshGRegionBoundaryRecovery::tetrahedron
  meshGRegionBoundaryRecovery::point2tet(point pt) {
  return ((tetrahedron *) (pt))[point2simindex];
}

inline void meshGRegionBoundaryRecovery::setpoint2tet(point pt,
  tetrahedron value) {
  ((tetrahedron *) (pt))[point2simindex] = value;
}

inline meshGRegionBoundaryRecovery::point
  meshGRegionBoundaryRecovery::point2ppt(point pt) {
  return (point) ((tetrahedron *) (pt))[point2simindex + 1];
}

inline void meshGRegionBoundaryRecovery::setpoint2ppt(point pt, point value) {
  ((tetrahedron *) (pt))[point2simindex + 1] = (tetrahedron) value;
}

inline meshGRegionBoundaryRecovery::shellface
  meshGRegionBoundaryRecovery::point2sh(point pt) {
  return (shellface) ((tetrahedron *) (pt))[point2simindex + 2];
}

inline void meshGRegionBoundaryRecovery::setpoint2sh(point pt,
  shellface value) {
  ((tetrahedron *) (pt))[point2simindex + 2] = (tetrahedron) value;
}


inline meshGRegionBoundaryRecovery::tetrahedron
  meshGRegionBoundaryRecovery::point2bgmtet(point pt) {
  return ((tetrahedron *) (pt))[point2simindex + 3];
}

inline void meshGRegionBoundaryRecovery::setpoint2bgmtet(point pt,
  tetrahedron value) {
  ((tetrahedron *) (pt))[point2simindex + 3] = value;
}

inline void meshGRegionBoundaryRecovery::setpointinsradius(point pt,
  REAL value) {
  pt[pointmtrindex + sizeoftensor - 1] = value;
}

inline REAL meshGRegionBoundaryRecovery::getpointinsradius(point pt) {
  return pt[pointmtrindex + sizeoftensor - 1];
}

inline bool meshGRegionBoundaryRecovery::issteinerpoint(point pt) {
 return (pointtype(pt) == FREESEGVERTEX) || (pointtype(pt) == FREEFACETVERTEX)
        || (pointtype(pt) == FREEVOLVERTEX);
}

inline void meshGRegionBoundaryRecovery::point2tetorg(point pa,
  triface& searchtet) {
  decode(point2tet(pa), searchtet);
  if ((point) searchtet.tet[4] == pa) {
    searchtet.ver = 11;
  } else if ((point) searchtet.tet[5] == pa) {
    searchtet.ver = 3;
  } else if ((point) searchtet.tet[6] == pa) {
    searchtet.ver = 7;
  } else {
    //assert((point) searchtet.tet[7] == pa); // SELF_CHECK
    searchtet.ver = 0;
  }
}

inline void meshGRegionBoundaryRecovery::point2shorg(point pa, face& searchsh){
  sdecode(point2sh(pa), searchsh);
  if ((point) searchsh.sh[3] == pa) {
    searchsh.shver = 0;
  } else if ((point) searchsh.sh[4] == pa) {
    searchsh.shver = (searchsh.sh[5] != NULL ? 2 : 1);
  } else {
    //assert((point) searchsh.sh[5] == pa); // SELF_CHECK
    searchsh.shver = 4;
  }
}

inline meshGRegionBoundaryRecovery::point
  meshGRegionBoundaryRecovery::farsorg(face& s) {
  face travesh, neighsh;
  travesh = s;
  while (1) {
    senext2(travesh, neighsh);
    spivotself(neighsh);
    if (neighsh.sh == NULL) break;
    if (sorg(neighsh) != sorg(travesh)) sesymself(neighsh);
    senext2(neighsh, travesh);
  }
  return sorg(travesh);
}

inline meshGRegionBoundaryRecovery::point
  meshGRegionBoundaryRecovery::farsdest(face& s) {
  face travesh, neighsh;
  travesh = s;
  while (1) {
    senext(travesh, neighsh);
    spivotself(neighsh);
    if (neighsh.sh == NULL) break;
    if (sdest(neighsh) != sdest(travesh)) sesymself(neighsh);
    senext(neighsh, travesh);
  }
  return sdest(travesh);
}

// dot() returns the dot product: v1 dot v2.
inline REAL meshGRegionBoundaryRecovery::dot(REAL* v1, REAL* v2)
{
  return v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2];
}

// cross() computes the cross product: n = v1 cross v2.
inline void meshGRegionBoundaryRecovery::cross(REAL* v1, REAL* v2, REAL* n)
{
  n[0] =   v1[1] * v2[2] - v2[1] * v1[2];
  n[1] = -(v1[0] * v2[2] - v2[0] * v1[2]);
  n[2] =   v1[0] * v2[1] - v2[0] * v1[1];
}

// distance() computes the Euclidean distance between two points.
inline REAL meshGRegionBoundaryRecovery::distance(REAL* p1, REAL* p2)
{
  return sqrt((p2[0] - p1[0]) * (p2[0] - p1[0]) +
              (p2[1] - p1[1]) * (p2[1] - p1[1]) +
              (p2[2] - p1[2]) * (p2[2] - p1[2]));
}

inline REAL meshGRegionBoundaryRecovery::norm2(REAL x, REAL y, REAL z)
{
  return (x) * (x) + (y) * (y) + (z) * (z);
}

//// mempool_cxx //////////////////////////////////////////////////////////////
////                                                                       ////
////                                                                       ////

int meshGRegionBoundaryRecovery::bondtbl[12][12] = {{0,},};
int meshGRegionBoundaryRecovery::enexttbl[12] = {0,};
int meshGRegionBoundaryRecovery::eprevtbl[12] = {0,};
int meshGRegionBoundaryRecovery::enextesymtbl[12] = {0,};
int meshGRegionBoundaryRecovery::eprevesymtbl[12] = {0,};
int meshGRegionBoundaryRecovery::eorgoppotbl[12] = {0,};
int meshGRegionBoundaryRecovery::edestoppotbl[12] = {0,};
int meshGRegionBoundaryRecovery::fsymtbl[12][12] = {{0,},};
int meshGRegionBoundaryRecovery::facepivot1[12] = {0,};
int meshGRegionBoundaryRecovery::facepivot2[12][12] = {{0,},};
int meshGRegionBoundaryRecovery::tsbondtbl[12][6] = {{0,},};
int meshGRegionBoundaryRecovery::stbondtbl[12][6] = {{0,},};
int meshGRegionBoundaryRecovery::tspivottbl[12][6] = {{0,},};
int meshGRegionBoundaryRecovery::stpivottbl[12][6] = {{0,},};

int meshGRegionBoundaryRecovery::esymtbl[12] =
  {9, 6, 11, 4, 3, 7, 1, 5, 10, 0, 8, 2};
int meshGRegionBoundaryRecovery:: orgpivot[12] =
  {7, 7, 5, 5, 6, 4, 4, 6, 5, 6, 7, 4};
int meshGRegionBoundaryRecovery::destpivot[12] =
  {6, 4, 4, 6, 5, 6, 7, 4, 7, 7, 5, 5};
int meshGRegionBoundaryRecovery::apexpivot[12] =
  {5, 6, 7, 4, 7, 7, 5, 5, 6, 4, 4, 6};
int meshGRegionBoundaryRecovery::oppopivot[12] =
  {4, 5, 6, 7, 4, 5, 6, 7, 4, 5, 6, 7};
int meshGRegionBoundaryRecovery::ver2edge[12] =
  {0, 1, 2, 3, 3, 5, 1, 5, 4, 0, 4, 2};
int meshGRegionBoundaryRecovery::edge2ver[ 6] = {0, 1, 2, 3, 8, 5};
int meshGRegionBoundaryRecovery::epivot[12] =
  {4, 5, 2, 11, 4, 5, 2, 11, 4, 5, 2, 11};
int meshGRegionBoundaryRecovery::snextpivot[6] = {2, 5, 4, 1, 0, 3};
int meshGRegionBoundaryRecovery::sorgpivot [6] = {3, 4, 4, 5, 5, 3};
int meshGRegionBoundaryRecovery::sdestpivot[6] = {4, 3, 5, 4, 3, 5};
int meshGRegionBoundaryRecovery::sapexpivot[6] = {5, 5, 3, 3, 4, 4};

void meshGRegionBoundaryRecovery::inittables()
{
  int i, j;

  // i = t1.ver; j = t2.ver;
  for (i = 0; i < 12; i++) {
    for (j = 0; j < 12; j++) {
      bondtbl[i][j] = (j & 3) + (((i & 12) + (j & 12)) % 12);
    }
  }

  // i = t1.ver; j = t2.ver
  for (i = 0; i < 12; i++) {
    for (j = 0; j < 12; j++) {
      fsymtbl[i][j] = (j + 12 - (i & 12)) % 12;
    }
  }

  for (i = 0; i < 12; i++) {
    facepivot1[i] = (esymtbl[i] & 3);
  }

  for (i = 0; i < 12; i++) {
    for (j = 0; j < 12; j++) {
      facepivot2[i][j] = fsymtbl[esymtbl[i]][j];
    }
  }

  for (i = 0; i < 12; i++) {
    enexttbl[i] = (i + 4) % 12;
    eprevtbl[i] = (i + 8) % 12;
  }

  for (i = 0; i < 12; i++) {
    enextesymtbl[i] = esymtbl[enexttbl[i]];
    eprevesymtbl[i] = esymtbl[eprevtbl[i]];
  }

  for (i = 0; i < 12; i++) {
    eorgoppotbl [i] = eprevtbl[esymtbl[enexttbl[i]]];
    edestoppotbl[i] = enexttbl[esymtbl[eprevtbl[i]]];
  }

  int soffset, toffset;

  // i = t.ver, j = s.shver
  for (i = 0; i < 12; i++) {
    for (j = 0; j < 6; j++) {
      if ((j & 1) == 0) {
        soffset = (6 - ((i & 12) >> 1)) % 6;
        toffset = (12 - ((j & 6) << 1)) % 12;
      } else {
        soffset = (i & 12) >> 1;
        toffset = (j & 6) << 1;
      }
      tsbondtbl[i][j] = (j & 1) + (((j & 6) + soffset) % 6);
      stbondtbl[i][j] = (i & 3) + (((i & 12) + toffset) % 12);
    }
  }

  // i = t.ver, j = s.shver
  for (i = 0; i < 12; i++) {
    for (j = 0; j < 6; j++) {
      if ((j & 1) == 0) {
        soffset = (i & 12) >> 1;
        toffset = (j & 6) << 1;
      } else {
        soffset = (6 - ((i & 12) >> 1)) % 6;
        toffset = (12 - ((j & 6) << 1)) % 12;
      }
      tspivottbl[i][j] = (j & 1) + (((j & 6) + soffset) % 6);
      stpivottbl[i][j] = (i & 3) + (((i & 12) + toffset) % 12);
    }
  }
}

void meshGRegionBoundaryRecovery::arraypool::restart()
{
  objects = 0l;
}

void meshGRegionBoundaryRecovery::arraypool::poolinit(int sizeofobject,
  int log2objperblk)
{
  // Each object must be at least one byte long.
  objectbytes = sizeofobject > 1 ? sizeofobject : 1;

  log2objectsperblock = log2objperblk;
  // Compute the number of objects in each block.
  objectsperblock = ((int) 1) << log2objectsperblock;
  objectsperblockmark = objectsperblock - 1;

  // No memory has been allocated.
  totalmemory = 0l;
  // The top array has not been allocated yet.
  toparray = (char **) NULL;
  toparraylen = 0;

  // Ready all indices to be allocated.
  restart();
}

meshGRegionBoundaryRecovery::arraypool::arraypool(int sizeofobject,
  int log2objperblk)
{
  poolinit(sizeofobject, log2objperblk);
}

meshGRegionBoundaryRecovery::arraypool::~arraypool()
{
  int i;

  // Has anything been allocated at all?
  if (toparray != (char **) NULL) {
    // Walk through the top array.
    for (i = 0; i < toparraylen; i++) {
      // Check every pointer; NULLs may be scattered randomly.
      if (toparray[i] != (char *) NULL) {
        // Free an allocated block.
        free((void *) toparray[i]);
      }
    }
    // Free the top array.
    free((void *) toparray);
  }

  // The top array is no longer allocated.
  toparray = (char **) NULL;
  toparraylen = 0;
  objects = 0;
  totalmemory = 0;
}

char* meshGRegionBoundaryRecovery::arraypool::getblock(int objectindex)
{
  char **newarray;
  char *block;
  int newsize;
  int topindex;
  int i;

  // Compute the index in the top array (upper bits).
  topindex = objectindex >> log2objectsperblock;
  // Does the top array need to be allocated or resized?
  if (toparray == (char **) NULL) {
    // Allocate the top array big enough to hold 'topindex', and NULL out
    //   its contents.
    newsize = topindex + 128;
    toparray = (char **) malloc((size_t) (newsize * sizeof(char *)));
    toparraylen = newsize;
    for (i = 0; i < newsize; i++) {
      toparray[i] = (char *) NULL;
    }
    // Account for the memory.
    totalmemory = newsize * (uintptr_t) sizeof(char *);
  } else if (topindex >= toparraylen) {
    // Resize the top array, making sure it holds 'topindex'.
    newsize = 3 * toparraylen;
    if (topindex >= newsize) {
      newsize = topindex + 128;
    }
    // Allocate the new array, copy the contents, NULL out the rest, and
    //   free the old array.
    newarray = (char **) malloc((size_t) (newsize * sizeof(char *)));
    for (i = 0; i < toparraylen; i++) {
      newarray[i] = toparray[i];
    }
    for (i = toparraylen; i < newsize; i++) {
      newarray[i] = (char *) NULL;
    }
    free(toparray);
    // Account for the memory.
    totalmemory += (newsize - toparraylen) * sizeof(char *);
    toparray = newarray;
    toparraylen = newsize;
  }

  // Find the block, or learn that it hasn't been allocated yet.
  block = toparray[topindex];
  if (block == (char *) NULL) {
    // Allocate a block at this index.
    block = (char *) malloc((size_t) (objectsperblock * objectbytes));
    toparray[topindex] = block;
    // Account for the memory.
    totalmemory += objectsperblock * objectbytes;
  }

  // Return a pointer to the block.
  return block;
}

void* meshGRegionBoundaryRecovery::arraypool::lookup(int objectindex)
{
  char *block;
  int topindex;

  // Has the top array been allocated yet?
  if (toparray == (char **) NULL) {
    return (void *) NULL;
  }

  // Compute the index in the top array (upper bits).
  topindex = objectindex >> log2objectsperblock;
  // Does the top index fit in the top array?
  if (topindex >= toparraylen) {
    return (void *) NULL;
  }

  // Find the block, or learn that it hasn't been allocated yet.
  block = toparray[topindex];
  if (block == (char *) NULL) {
    return (void *) NULL;
  }

  // Compute a pointer to the object with the given index.  Note that
  //   'objectsperblock' is a power of two, so the & operation is a bit mask
  //   that preserves the lower bits.
  return (void *)(block + (objectindex & (objectsperblock - 1)) * objectbytes);
}

int meshGRegionBoundaryRecovery::arraypool::newindex(void **newptr)
{
  // Allocate an object at index 'firstvirgin'.
  int newindex = objects;
  *newptr = (void *) (getblock(objects) +
    (objects & (objectsperblock - 1)) * objectbytes);
  objects++;

  return newindex;
}


meshGRegionBoundaryRecovery::memorypool::memorypool()
{
  firstblock = nowblock = (void **) NULL;
  nextitem = (void *) NULL;
  deaditemstack = (void *) NULL;
  pathblock = (void **) NULL;
  pathitem = (void *) NULL;
  alignbytes = 0;
  itembytes = itemwords = 0;
  itemsperblock = 0;
  items = maxitems = 0l;
  unallocateditems = 0;
  pathitemsleft = 0;
}

meshGRegionBoundaryRecovery::memorypool::memorypool(int bytecount,
  int itemcount, int wsize, int alignment)
{
  poolinit(bytecount, itemcount, wsize, alignment);
}

meshGRegionBoundaryRecovery::memorypool::~memorypool()
{
  while (firstblock != (void **) NULL) {
    nowblock = (void **) *(firstblock);
    free(firstblock);
    firstblock = nowblock;
  }
}

void meshGRegionBoundaryRecovery::memorypool::poolinit(int bytecount,
  int itemcount,int wordsize, int alignment)
{
  // Find the proper alignment, which must be at least as large as:
  //   - The parameter `alignment'.
  //   - The primary word type, to avoid unaligned accesses.
  //   - sizeof(void *), so the stack of dead items can be maintained
  //       without unaligned accesses.
  if (alignment > wordsize) {
    alignbytes = alignment;
  } else {
    alignbytes = wordsize;
  }
  if ((int) sizeof(void *) > alignbytes) {
    alignbytes = (int) sizeof(void *);
  }
  itemwords = ((bytecount + alignbytes - 1) /  alignbytes)
            * (alignbytes / wordsize);
  itembytes = itemwords * wordsize;
  itemsperblock = itemcount;

  // Allocate a block of items.  Space for `itemsperblock' items and one
  //   pointer (to point to the next block) are allocated, as well as space
  //   to ensure alignment of the items.
  firstblock = (void **) malloc(itemsperblock * itembytes + sizeof(void *)
                                + alignbytes);
  if (firstblock == (void **) NULL) {
    terminateBoundaryRecovery(NULL, 1);
  }
  // Set the next block pointer to NULL.
  *(firstblock) = (void *) NULL;
  restart();
}

void meshGRegionBoundaryRecovery::memorypool::restart()
{
  uintptr_t alignptr;

  items = 0;
  maxitems = 0;

  // Set the currently active block.
  nowblock = firstblock;
  // Find the first item in the pool.  Increment by the size of (void *).
  alignptr = (uintptr_t) (nowblock + 1);
  // Align the item on an `alignbytes'-byte boundary.
  nextitem = (void *)
    (alignptr + (uintptr_t) alignbytes -
     (alignptr % (uintptr_t) alignbytes));
  // There are lots of unallocated items left in this block.
  unallocateditems = itemsperblock;
  // The stack of deallocated items is empty.
  deaditemstack = (void *) NULL;
}

void* meshGRegionBoundaryRecovery::memorypool::alloc()
{
  void *newitem;
  void **newblock;
  uintptr_t alignptr;

  // First check the linked list of dead items.  If the list is not
  //   empty, allocate an item from the list rather than a fresh one.
  if (deaditemstack != (void *) NULL) {
    newitem = deaditemstack;                     // Take first item in list.
    deaditemstack = * (void **) deaditemstack;
  } else {
    // Check if there are any free items left in the current block.
    if (unallocateditems == 0) {
      // Check if another block must be allocated.
      if (*nowblock == (void *) NULL) {
        // Allocate a new block of items, pointed to by the previous block.
        newblock = (void **) malloc(itemsperblock * itembytes + sizeof(void *)
                                    + alignbytes);
        if (newblock == (void **) NULL) {
          terminateBoundaryRecovery(NULL, 1);
        }
        *nowblock = (void *) newblock;
        // The next block pointer is NULL.
        *newblock = (void *) NULL;
      }
      // Move to the new block.
      nowblock = (void **) *nowblock;
      // Find the first item in the block.
      //   Increment by the size of (void *).
      alignptr = (uintptr_t) (nowblock + 1);
      // Align the item on an `alignbytes'-byte boundary.
      nextitem = (void *)
        (alignptr + (uintptr_t) alignbytes -
         (alignptr % (uintptr_t) alignbytes));
      // There are lots of unallocated items left in this block.
      unallocateditems = itemsperblock;
    }
    // Allocate a new item.
    newitem = nextitem;
    // Advance `nextitem' pointer to next free item in block.
    nextitem = (void *) ((uintptr_t) nextitem + itembytes);
    unallocateditems--;
    maxitems++;
  }
  items++;
  return newitem;
}

void meshGRegionBoundaryRecovery::memorypool::dealloc(void *dyingitem)
{
  // Push freshly killed item onto stack.
  *((void **) dyingitem) = deaditemstack;
  deaditemstack = dyingitem;
  items--;
}

void meshGRegionBoundaryRecovery::memorypool::traversalinit()
{
  uintptr_t alignptr;

  // Begin the traversal in the first block.
  pathblock = firstblock;
  // Find the first item in the block.  Increment by the size of (void *).
  alignptr = (uintptr_t) (pathblock + 1);
  // Align with item on an `alignbytes'-byte boundary.
  pathitem = (void *)
    (alignptr + (uintptr_t) alignbytes -
     (alignptr % (uintptr_t) alignbytes));
  // Set the number of items left in the current block.
  pathitemsleft = itemsperblock;
}

void* meshGRegionBoundaryRecovery::memorypool::traverse()
{
  void *newitem;
  uintptr_t alignptr;

  // Stop upon exhausting the list of items.
  if (pathitem == nextitem) {
    return (void *) NULL;
  }
  // Check whether any untraversed items remain in the current block.
  if (pathitemsleft == 0) {
    // Find the next block.
    pathblock = (void **) *pathblock;
    // Find the first item in the block.  Increment by the size of (void *).
    alignptr = (uintptr_t) (pathblock + 1);
    // Align with item on an `alignbytes'-byte boundary.
    pathitem = (void *)
      (alignptr + (uintptr_t) alignbytes -
       (alignptr % (uintptr_t) alignbytes));
    // Set the number of items left in the current block.
    pathitemsleft = itemsperblock;
  }
  newitem = pathitem;
  // Find the next item in the block.
  pathitem = (void *) ((uintptr_t) pathitem + itembytes);
  pathitemsleft--;
  return newitem;
}

void meshGRegionBoundaryRecovery::makeindex2pointmap(point*& idx2verlist)
{
  point pointloop;
  int idx;

  if (b->verbose > 1) {
    printf("  Constructing mapping from indices to points.\n");
  }

  idx2verlist = new point[points->items + 1];

  points->traversalinit();
  pointloop = pointtraverse();
  idx =  in->firstnumber;
  while (pointloop != (point) NULL) {
    idx2verlist[idx++] = pointloop;
    pointloop = pointtraverse();
  }
}

void meshGRegionBoundaryRecovery::makepoint2submap(memorypool* pool,
  int*& idx2faclist, face*& facperverlist)
{
  face shloop;
  int i, j, k;

  if (b->verbose > 1) {
    printf("  Making a map from points to subfaces.\n");
  }

  // Initialize 'idx2faclist'.
  idx2faclist = new int[points->items + 1];
  for (i = 0; i < points->items + 1; i++) idx2faclist[i] = 0;

  // Loop all subfaces, counter the number of subfaces incident at a vertex.
  pool->traversalinit();
  shloop.sh = shellfacetraverse(pool);
  while (shloop.sh != (shellface *) NULL) {
    // Increment the number of incident subfaces for each vertex.
    j = pointmark((point) shloop.sh[3]) - in->firstnumber;
    idx2faclist[j]++;
    j = pointmark((point) shloop.sh[4]) - in->firstnumber;
    idx2faclist[j]++;
    // Skip the third corner if it is a segment.
    if (shloop.sh[5] != NULL) {
      j = pointmark((point) shloop.sh[5]) - in->firstnumber;
      idx2faclist[j]++;
    }
    shloop.sh = shellfacetraverse(pool);
  }

  // Calculate the total length of array 'facperverlist'.
  j = idx2faclist[0];
  idx2faclist[0] = 0;  // Array starts from 0 element.
  for (i = 0; i < points->items; i++) {
    k = idx2faclist[i + 1];
    idx2faclist[i + 1] = idx2faclist[i] + j;
    j = k;
  }

  // The total length is in the last unit of idx2faclist.
  facperverlist = new face[idx2faclist[i]];

  // Loop all subfaces again, remember the subfaces at each vertex.
  pool->traversalinit();
  shloop.sh = shellfacetraverse(pool);
  while (shloop.sh != (shellface *) NULL) {
    j = pointmark((point) shloop.sh[3]) - in->firstnumber;
    shloop.shver = 0; // save the origin.
    facperverlist[idx2faclist[j]] = shloop;
    idx2faclist[j]++;
    // Is it a subface or a subsegment?
    if (shloop.sh[5] != NULL) {
      j = pointmark((point) shloop.sh[4]) - in->firstnumber;
      shloop.shver = 2; // save the origin.
      facperverlist[idx2faclist[j]] = shloop;
      idx2faclist[j]++;
      j = pointmark((point) shloop.sh[5]) - in->firstnumber;
      shloop.shver = 4; // save the origin.
      facperverlist[idx2faclist[j]] = shloop;
      idx2faclist[j]++;
    } else {
      j = pointmark((point) shloop.sh[4]) - in->firstnumber;
      shloop.shver = 1; // save the origin.
      facperverlist[idx2faclist[j]] = shloop;
      idx2faclist[j]++;
    }
    shloop.sh = shellfacetraverse(pool);
  }

  // Contents in 'idx2faclist' are shifted, now shift them back.
  for (i = points->items - 1; i >= 0; i--) {
    idx2faclist[i + 1] = idx2faclist[i];
  }
  idx2faclist[0] = 0;
}

void meshGRegionBoundaryRecovery::tetrahedrondealloc(tetrahedron
  *dyingtetrahedron)
{
  // Set tetrahedron's vertices to NULL. This makes it possible to detect
  //   dead tetrahedra when traversing the list of all tetrahedra.
  dyingtetrahedron[4] = (tetrahedron) NULL;

  // Dealloc the space to subfaces/subsegments.
  if (dyingtetrahedron[8] != NULL) {
    tet2segpool->dealloc((shellface *) dyingtetrahedron[8]);
  }
  if (dyingtetrahedron[9] != NULL) {
    tet2subpool->dealloc((shellface *) dyingtetrahedron[9]);
  }

  tetrahedrons->dealloc((void *) dyingtetrahedron);
}

meshGRegionBoundaryRecovery::tetrahedron*
  meshGRegionBoundaryRecovery::tetrahedrontraverse()
{
  tetrahedron *newtetrahedron;

  do {
    newtetrahedron = (tetrahedron *) tetrahedrons->traverse();
    if (newtetrahedron == (tetrahedron *) NULL) {
      return (tetrahedron *) NULL;
    }
  } while ((newtetrahedron[4] == (tetrahedron) NULL) ||
           ((point) newtetrahedron[7] == dummypoint));
  return newtetrahedron;
}

meshGRegionBoundaryRecovery::tetrahedron*
  meshGRegionBoundaryRecovery::alltetrahedrontraverse()
{
  tetrahedron *newtetrahedron;

  do {
    newtetrahedron = (tetrahedron *) tetrahedrons->traverse();
    if (newtetrahedron == (tetrahedron *) NULL) {
      return (tetrahedron *) NULL;
    }
  } while (newtetrahedron[4] == (tetrahedron) NULL); // Skip dead ones.
  return newtetrahedron;
}

void meshGRegionBoundaryRecovery::shellfacedealloc(memorypool *pool,
  shellface *dyingsh)
{
  // Set shellface's vertices to NULL. This makes it possible to detect dead
  //   shellfaces when traversing the list of all shellfaces.
  dyingsh[3] = (shellface) NULL;
  pool->dealloc((void *) dyingsh);
}

meshGRegionBoundaryRecovery::shellface* meshGRegionBoundaryRecovery::shellfacetraverse(memorypool *pool)
{
  shellface *newshellface;

  do {
    newshellface = (shellface *) pool->traverse();
    if (newshellface == (shellface *) NULL) {
      return (shellface *) NULL;
    }
  } while (newshellface[3] == (shellface) NULL);          // Skip dead ones.
  return newshellface;
}

void meshGRegionBoundaryRecovery::pointdealloc(point dyingpoint)
{
  // Mark the point as dead. This  makes it possible to detect dead points
  //   when traversing the list of all points.
  setpointtype(dyingpoint, DEADVERTEX);
  points->dealloc((void *) dyingpoint);
}

meshGRegionBoundaryRecovery::point meshGRegionBoundaryRecovery::pointtraverse()
{
  point newpoint;

  do {
    newpoint = (point) points->traverse();
    if (newpoint == (point) NULL) {
      return (point) NULL;
    }
  } while (pointtype(newpoint) == DEADVERTEX);            // Skip dead ones.
  return newpoint;
}

void meshGRegionBoundaryRecovery::maketetrahedron(triface *newtet)
{
  newtet->tet = (tetrahedron *) tetrahedrons->alloc();

  // Initialize the four adjoining tetrahedra to be "outer space".
  newtet->tet[0] = NULL;
  newtet->tet[1] = NULL;
  newtet->tet[2] = NULL;
  newtet->tet[3] = NULL;
  // Four NULL vertices.
  newtet->tet[4] = NULL;
  newtet->tet[5] = NULL;
  newtet->tet[6] = NULL;
  newtet->tet[7] = NULL;
  // No attached segments and subfaces yet.
  newtet->tet[8] = NULL;
  newtet->tet[9] = NULL;
  // Initialize the marker (clear all flags).
  setelemmarker(newtet->tet, 0);
  for (int i = 0; i < numelemattrib; i++) {
    setelemattribute(newtet->tet, i, 0.0);
  }
  if (b->varvolume) {
    setvolumebound(newtet->tet, -1.0);
  }

  // Initialize the version to be Zero.
  newtet->ver = 11;
}

void meshGRegionBoundaryRecovery::makeshellface(memorypool *pool, face *newface)
{
  newface->sh = (shellface *) pool->alloc();

  // No adjointing subfaces.
  newface->sh[0] = NULL;
  newface->sh[1] = NULL;
  newface->sh[2] = NULL;
  // Three NULL vertices.
  newface->sh[3] = NULL;
  newface->sh[4] = NULL;
  newface->sh[5] = NULL;
  // No adjoining subsegments.
  newface->sh[6] = NULL;
  newface->sh[7] = NULL;
  newface->sh[8] = NULL;
  // No adjoining tetrahedra.
  newface->sh[9] = NULL;
  newface->sh[10] = NULL;
  if (checkconstraints) {
    // Initialize the maximum area bound.
    setareabound(*newface, 0.0);
  }
  // Clear the infection and marktest bits.
  ((int *) (newface->sh))[shmarkindex + 1] = 0;
  if (useinsertradius) {
    setfacetindex(*newface, 0);
  }
  // Set the boundary marker to zero.
  setshellmark(*newface, 0);

  newface->shver = 0;
}

void meshGRegionBoundaryRecovery::makepoint(point* pnewpoint,
  enum verttype vtype)
{
  int i;

  *pnewpoint = (point) points->alloc();

  // Initialize the point attributes.
  for (i = 0; i < numpointattrib; i++) {
    (*pnewpoint)[3 + i] = 0.0;
  }
  // Initialize the metric tensor.
  for (i = 0; i < sizeoftensor; i++) {
    (*pnewpoint)[pointmtrindex + i] = 0.0;
  }
  setpoint2tet(*pnewpoint, NULL);
  setpoint2ppt(*pnewpoint, NULL);
  if (b->plc || b->refine) {
    // Initialize the point-to-simplex field.
    setpoint2sh(*pnewpoint, NULL);
    if (b->metric && (bgm != NULL)) {
      setpoint2bgmtet(*pnewpoint, NULL);
    }
  }
  // Initialize the point marker (starting from in->firstnumber).
  setpointmark(*pnewpoint, (int) (points->items) - (!in->firstnumber));
  // Clear all flags.
  ((int *) (*pnewpoint))[pointmarkindex + 1] = 0;
  // Initialize (set) the point type.
  setpointtype(*pnewpoint, vtype);
}

void meshGRegionBoundaryRecovery::initializepools()
{
  int pointsize = 0, elesize = 0, shsize = 0;
  int i;

  if (b->verbose) {
    printf("  Initializing memorypools.\n");
    printf("  tetrahedron per block: %d.\n", b->tetrahedraperblock);
  }

  inittables();

  if (b->plc || b->refine) {
    // Save the insertion radius for Steiner points if boundaries
    //   are allowed be split.
    if (!b->nobisect || checkconstraints) {
      useinsertradius = 1;
    }
  }

  // The index within each point at which its metric tensor is found.
  // Each vertex has three coordinates.
  if (b->psc) {
    // '-s' option (PSC), the u,v coordinates are provided.
    pointmtrindex = 5 + numpointattrib;
    // The index within each point at which its u, v coordinates are found.
    // Comment: They are saved after the list of point attributes.
    pointparamindex = pointmtrindex - 2;
  } else {
    pointmtrindex = 3 + numpointattrib;
  }
  // The index within each point at which an element pointer is found, where
  //   the index is measured in pointers. Ensure the index is aligned to a
  //   sizeof(tetrahedron)-byte address.
  point2simindex = ((pointmtrindex + sizeoftensor) * sizeof(REAL)
                 + sizeof(tetrahedron) - 1) / sizeof(tetrahedron);
  if (b->plc || b->refine || b->voroout) {
    // Increase the point size by three pointers, which are:
    //   - a pointer to a tet, read by point2tet();
    //   - a pointer to a parent point, read by point2ppt()).
    //   - a pointer to a subface or segment, read by point2sh();
    if (b->metric && (bgm != NULL)) {
      // Increase one pointer into the background mesh, point2bgmtet().
      pointsize = (point2simindex + 4) * sizeof(tetrahedron);
    } else {
      pointsize = (point2simindex + 3) * sizeof(tetrahedron);
    }
  } else {
    // Increase the point size by two pointer, which are:
    //   - a pointer to a tet, read by point2tet();
    //   - a pointer to a parent point, read by point2ppt()). -- Used by btree.
    pointsize = (point2simindex + 2) * sizeof(tetrahedron);
  }
  // The index within each point at which the boundary marker is found,
  //   Ensure the point marker is aligned to a sizeof(int)-byte address.
  pointmarkindex = (pointsize + sizeof(int) - 1) / sizeof(int);
  // Now point size is the ints (indicated by pointmarkindex) plus:
  //   - an integer for boundary marker;
  //   - an integer for vertex type;
  //   - an integer for geometry tag (optional, -s option).
  pointsize = (pointmarkindex + 2 + (b->psc ? 1 : 0)) * sizeof(tetrahedron);

  // Initialize the pool of vertices.
  points = new memorypool(pointsize, b->vertexperblock, sizeof(REAL), 0);

  if (b->verbose) {
    printf("  Size of a point: %d bytes.\n", points->itembytes);
  }

  // Initialize the infinite vertex.
  dummypoint = (point) new char[pointsize];
  // Initialize all fields of this point.
  dummypoint[0] = 0.0;
  dummypoint[1] = 0.0;
  dummypoint[2] = 0.0;
  for (i = 0; i < numpointattrib; i++) {
    dummypoint[3 + i] = 0.0;
  }
  // Initialize the metric tensor.
  for (i = 0; i < sizeoftensor; i++) {
    dummypoint[pointmtrindex + i] = 0.0;
  }
  setpoint2tet(dummypoint, NULL);
  setpoint2ppt(dummypoint, NULL);
  if (b->plc || b->psc || b->refine) {
    // Initialize the point-to-simplex field.
    setpoint2sh(dummypoint, NULL);
    if (b->metric && (bgm != NULL)) {
      setpoint2bgmtet(dummypoint, NULL);
    }
  }
  // Initialize the point marker (starting from in->firstnumber).
  setpointmark(dummypoint, -1); // The unique marker for dummypoint.
  // Clear all flags.
  ((int *) (dummypoint))[pointmarkindex + 1] = 0;
  // Initialize (set) the point type.
  setpointtype(dummypoint, UNUSEDVERTEX); // Does not matter.

  elesize = 12 * sizeof(tetrahedron);

  // The index to find the element markers. An integer containing varies
  //   flags and element counter.
  assert(sizeof(int) <= sizeof(tetrahedron));
  assert((sizeof(tetrahedron) % sizeof(int)) == 0);
  elemmarkerindex = (elesize - sizeof(tetrahedron)) / sizeof(int);

  // The actual number of element attributes. Note that if the
  //   `b->regionattrib' flag is set, an additional attribute will be added.
  //numelemattrib = in->numberoftetrahedronattributes + (b->regionattrib > 0);
  numelemattrib = (b->regionattrib > 0);

  // The index within each element at which its attributes are found, where
  //   the index is measured in REALs.
  elemattribindex = (elesize + sizeof(REAL) - 1) / sizeof(REAL);
  // The index within each element at which the maximum volume bound is
  //   found, where the index is measured in REALs.
  volumeboundindex = elemattribindex + numelemattrib;
  // If element attributes or an constraint are needed, increase the number
  //   of bytes occupied by an element.
  if (b->varvolume) {
    elesize = (volumeboundindex + 1) * sizeof(REAL);
  } else if (numelemattrib > 0) {
    elesize = volumeboundindex * sizeof(REAL);
  }


  // Having determined the memory size of an element, initialize the pool.
  tetrahedrons = new memorypool(elesize, b->tetrahedraperblock, sizeof(void *),
                                16);

  if (b->verbose) {
    printf("  Size of a tetrahedron: %d (%d) bytes.\n", elesize,
           tetrahedrons->itembytes);
  }

  if (b->plc || b->refine) { // if (b->useshelles) {
    // The number of bytes occupied by a subface.  The list of pointers
    //   stored in a subface are: three to other subfaces, three to corners,
    //   three to subsegments, two to tetrahedra.
    shsize = 11 * sizeof(shellface);
    // The index within each subface at which the maximum area bound is
    //   found, where the index is measured in REALs.
    areaboundindex = (shsize + sizeof(REAL) - 1) / sizeof(REAL);
    // If -q switch is in use, increase the number of bytes occupied by
    //   a subface for saving maximum area bound.
    if (checkconstraints) {
      shsize = (areaboundindex + 1) * sizeof(REAL);
    } else {
      shsize = areaboundindex * sizeof(REAL);
    }
    // The index within subface at which the facet marker is found. Ensure
    //   the marker is aligned to a sizeof(int)-byte address.
    shmarkindex = (shsize + sizeof(int) - 1) / sizeof(int);
    // Increase the number of bytes by two or three integers, one for facet
    //   marker, one for shellface type, and optionally one for pbc group.
    shsize = (shmarkindex + 2) * sizeof(shellface);
    if (useinsertradius) {
      // Increase the number of byte by one integer for storing facet index.
      //    set/read by setfacetindex() and getfacetindex.
      shsize = (shmarkindex + 3) * sizeof(shellface);
    }

    // Initialize the pool of subfaces. Each subface record is eight-byte
    //   aligned so it has room to store an edge version (from 0 to 5) in
    //   the least three bits.
    subfaces = new memorypool(shsize, b->shellfaceperblock, sizeof(void *), 8);

    if (b->verbose) {
      printf("  Size of a shellface: %d (%d) bytes.\n", shsize,
             subfaces->itembytes);
    }

    // Initialize the pool of subsegments. The subsegment's record is same
    //   with subface.
    subsegs = new memorypool(shsize, b->shellfaceperblock, sizeof(void *), 8);

    // Initialize the pool for tet-subseg connections.
    tet2segpool = new memorypool(6 * sizeof(shellface), b->shellfaceperblock,
                                 sizeof(void *), 0);
    // Initialize the pool for tet-subface connections.
    tet2subpool = new memorypool(4 * sizeof(shellface), b->shellfaceperblock,
                                 sizeof(void *), 0);

    // Initialize arraypools for segment & facet recovery.
    subsegstack = new arraypool(sizeof(face), 10);
    subfacstack = new arraypool(sizeof(face), 10);
    subvertstack = new arraypool(sizeof(point), 8);

    // Initialize arraypools for surface point insertion/deletion.
    caveshlist = new arraypool(sizeof(face), 8);
    caveshbdlist = new arraypool(sizeof(face), 8);
    cavesegshlist = new arraypool(sizeof(face), 4);

    cavetetshlist = new arraypool(sizeof(face), 8);
    cavetetseglist = new arraypool(sizeof(face), 8);
    caveencshlist = new arraypool(sizeof(face), 8);
    caveencseglist = new arraypool(sizeof(face), 8);
  }

  // Initialize the pools for flips.
  flippool = new memorypool(sizeof(badface), 1024, sizeof(void *), 0);
  unflipqueue = new arraypool(sizeof(badface), 10);

  // Initialize the arraypools for point insertion.
  cavetetlist = new arraypool(sizeof(triface), 10);
  cavebdrylist = new arraypool(sizeof(triface), 10);
  caveoldtetlist = new arraypool(sizeof(triface), 10);
  cavetetvertlist = new arraypool(sizeof(point), 10);
}

////                                                                       ////
////                                                                       ////
//// mempool_cxx //////////////////////////////////////////////////////////////

//// geom_cxx /////////////////////////////////////////////////////////////////
////                                                                       ////
////                                                                       ////

REAL meshGRegionBoundaryRecovery::PI = 3.14159265358979323846264338327950288419716939937510582;

REAL meshGRegionBoundaryRecovery::insphere_s(REAL* pa, REAL* pb, REAL* pc,
  REAL* pd, REAL* pe)
{
  REAL sign;

  sign = insphere(pa, pb, pc, pd, pe);
  if (sign != 0.0) {
    return sign;
  }

  // Symbolic perturbation.
  point pt[5], swappt;
  REAL oriA, oriB;
  int swaps, count;
  int n, i;

  pt[0] = pa;
  pt[1] = pb;
  pt[2] = pc;
  pt[3] = pd;
  pt[4] = pe;

  // Sort the five points such that their indices are in the increasing
  //   order. An optimized bubble sort algorithm is used, i.e., it has
  //   the worst case O(n^2) runtime, but it is usually much faster.
  swaps = 0; // Record the total number of swaps.
  n = 5;
  do {
    count = 0;
    n = n - 1;
    for (i = 0; i < n; i++) {
      if (pointmark(pt[i]) > pointmark(pt[i+1])) {
        swappt = pt[i]; pt[i] = pt[i+1]; pt[i+1] = swappt;
        count++;
      }
    }
    swaps += count;
  } while (count > 0); // Continue if some points are swapped.

  oriA = orient3d(pt[1], pt[2], pt[3], pt[4]);
  if (oriA != 0.0) {
    // Flip the sign if there are odd number of swaps.
    if ((swaps % 2) != 0) oriA = -oriA;
    return oriA;
  }

  oriB = -orient3d(pt[0], pt[2], pt[3], pt[4]);
  assert(oriB != 0.0); // SELF_CHECK
  // Flip the sign if there are odd number of swaps.
  if ((swaps % 2) != 0) oriB = -oriB;
  return oriB;
}

REAL orient4dfast(REAL* pa, REAL* pb, REAL* pc, REAL* pd, REAL* pe,
              REAL aheight, REAL bheight, REAL cheight, REAL dheight,
              REAL eheight)
{
 REAL aex, bex, cex, dex;
 REAL aey, bey, cey, dey;
 REAL aez, bez, cez, dez;
 REAL aexbey, bexaey, bexcey, cexbey, cexdey, dexcey, dexaey, aexdey;
 REAL aexcey, cexaey, bexdey, dexbey;
 REAL aeheight, beheight, ceheight, deheight;
 REAL ab, bc, cd, da, ac, bd;
 REAL abc, bcd, cda, dab;
 REAL det;

 aex = pa[0] - pe[0];
 bex = pb[0] - pe[0];
 cex = pc[0] - pe[0];
 dex = pd[0] - pe[0];
 aey = pa[1] - pe[1];
 bey = pb[1] - pe[1];
 cey = pc[1] - pe[1];
 dey = pd[1] - pe[1];
 aez = pa[2] - pe[2];
 bez = pb[2] - pe[2];
 cez = pc[2] - pe[2];
 dez = pd[2] - pe[2];
 aeheight = aheight - eheight;
 beheight = bheight - eheight;
 ceheight = cheight - eheight;
 deheight = dheight - eheight;

 aexbey = aex * bey;
 bexaey = bex * aey;
 ab = aexbey - bexaey;
 bexcey = bex * cey;
 cexbey = cex * bey;
 bc = bexcey - cexbey;
 cexdey = cex * dey;
 dexcey = dex * cey;
 cd = cexdey - dexcey;
 dexaey = dex * aey;
 aexdey = aex * dey;
 da = dexaey - aexdey;

 aexcey = aex * cey;
 cexaey = cex * aey;
 ac = aexcey - cexaey;
 bexdey = bex * dey;
 dexbey = dex * bey;
 bd = bexdey - dexbey;

 abc = aez * bc - bez * ac + cez * ab;
 bcd = bez * cd - cez * bd + dez * bc;
 cda = cez * da + dez * ac + aez * cd;
 dab = dez * ab + aez * bd + bez * da;

 det = (deheight * abc - ceheight * dab) + (beheight * cda - aeheight * bcd);

 return det;
}

#define SETVECTOR3(V, a0, a1, a2) (V)[0] = (a0); (V)[1] = (a1); (V)[2] = (a2)

#define SWAP2(a0, a1, tmp) (tmp) = (a0); (a0) = (a1); (a1) = (tmp)

int meshGRegionBoundaryRecovery::tri_edge_2d(point A, point B, point C,
  point P, point Q, point R, int level, int *types, int *pos)
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
        //assert(0);
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

  assert(z1 != 4); // SELF_CHECK

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
        assert(s2 > 0); // SELF_CHECK
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
          assert(s2 > 0); // SELF_CHECK
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
        assert(s2 > 0); // SELF_CHECK
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
          assert(s2 > 0); // SELF_CHECK
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
        assert(s2 > 0); // SELF_CHECK
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
          assert(s2 > 0); // SELF_CHECK
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

int meshGRegionBoundaryRecovery::tri_edge_tail(point A,point B,point C,point P,
  point Q,point R, REAL sP,REAL sQ,int level,int *types,int *pos)
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
        } else { // s3 == 0 (000)
          // Impossible.
          assert(0);
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
        } else { // s3 == 0 (000)
          // Impossible.
          assert(0);
        }
      }
    }
  }

  // T and E intersect in a single point.
  return 2;
}

int meshGRegionBoundaryRecovery::tri_edge_test(point A, point B, point C,
  point P, point Q, point R, int level, int *types, int *pos)
{
  REAL sP, sQ;

  // Test the locations of P and Q with respect to ABC.
  sP = orient3d(A, B, C, P);
  sQ = orient3d(A, B, C, Q);

  return tri_edge_tail(A, B, C, P, Q, R, sP, sQ, level, types, pos);
}

bool meshGRegionBoundaryRecovery::lu_decmp(REAL lu[4][4], int n, int* ps,
  REAL* d, int N)
{
  REAL scales[4];
  REAL pivot, biggest, mult, tempf;
  int pivotindex = 0;
  int i, j, k;

  *d = 1.0;                                      // No row interchanges yet.

  for (i = N; i < n + N; i++) {                             // For each row.
    // Find the largest element in each row for row equilibration
    biggest = 0.0;
    for (j = N; j < n + N; j++)
      if (biggest < (tempf = fabs(lu[i][j])))
        biggest  = tempf;
    if (biggest != 0.0)
      scales[i] = 1.0 / biggest;
    else {
      scales[i] = 0.0;
      return false;                            // Zero row: singular matrix.
    }
    ps[i] = i;                                 // Initialize pivot sequence.
  }

  for (k = N; k < n + N - 1; k++) {                      // For each column.
    // Find the largest element in each column to pivot around.
    biggest = 0.0;
    for (i = k; i < n + N; i++) {
      if (biggest < (tempf = fabs(lu[ps[i]][k]) * scales[ps[i]])) {
        biggest = tempf;
        pivotindex = i;
      }
    }
    if (biggest == 0.0) {
      return false;                         // Zero column: singular matrix.
    }
    if (pivotindex != k) {                         // Update pivot sequence.
      j = ps[k];
      ps[k] = ps[pivotindex];
      ps[pivotindex] = j;
      *d = -(*d);                          // ...and change the parity of d.
    }

    // Pivot, eliminating an extra variable  each time
    pivot = lu[ps[k]][k];
    for (i = k + 1; i < n + N; i++) {
      lu[ps[i]][k] = mult = lu[ps[i]][k] / pivot;
      if (mult != 0.0) {
        for (j = k + 1; j < n + N; j++)
          lu[ps[i]][j] -= mult * lu[ps[k]][j];
      }
    }
  }

  // (lu[ps[n + N - 1]][n + N - 1] == 0.0) ==> A is singular.
  return lu[ps[n + N - 1]][n + N - 1] != 0.0;
}

void meshGRegionBoundaryRecovery::lu_solve(REAL lu[4][4], int n, int* ps,
  REAL* b, int N)
{
  int i, j;
  REAL X[4], dot;

  for (i = N; i < n + N; i++) X[i] = 0.0;

  // Vector reduction using U triangular matrix.
  for (i = N; i < n + N; i++) {
    dot = 0.0;
    for (j = N; j < i + N; j++)
      dot += lu[ps[i]][j] * X[j];
    X[i] = b[ps[i]] - dot;
  }

  // Back substitution, in L triangular matrix.
  for (i = n + N - 1; i >= N; i--) {
    dot = 0.0;
    for (j = i + 1; j < n + N; j++)
      dot += lu[ps[i]][j] * X[j];
    X[i] = (X[i] - dot) / lu[ps[i]][i];
  }

  for (i = N; i < n + N; i++) b[i] = X[i];
}

REAL meshGRegionBoundaryRecovery::incircle3d(point pa, point pb, point pc,
  point pd)
{
  REAL area2[2], n1[3], n2[3], c[3];
  REAL sign, r, d;

  // Calculate the areas of the two triangles [a, b, c] and [b, a, d].
  facenormal(pa, pb, pc, n1, 1, NULL);
  area2[0] = dot(n1, n1);
  facenormal(pb, pa, pd, n2, 1, NULL);
  area2[1] = dot(n2, n2);

  if (area2[0] > area2[1]) {
    // Choose [a, b, c] as the base triangle.
    circumsphere(pa, pb, pc, NULL, c, &r);
    d = distance(c, pd);
  } else {
    // Choose [b, a, d] as the base triangle.
    if (area2[1] > 0) {
      circumsphere(pb, pa, pd, NULL, c, &r);
      d = distance(c, pc);
    } else {
      // The four points are collinear. This case only happens on the boundary.
      return 0; // Return "not inside".
    }
  }

  sign = d - r;
  if (fabs(sign) / r < b->epsilon) {
    sign = 0;
  }

  return sign;
}

void meshGRegionBoundaryRecovery::facenormal(point pa, point pb, point pc,
  REAL *n, int pivot, REAL* lav)
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

REAL meshGRegionBoundaryRecovery::orient3dfast(REAL *pa, REAL *pb, REAL *pc,
  REAL *pd)
{
  REAL adx, bdx, cdx;
  REAL ady, bdy, cdy;
  REAL adz, bdz, cdz;

  adx = pa[0] - pd[0];
  bdx = pb[0] - pd[0];
  cdx = pc[0] - pd[0];
  ady = pa[1] - pd[1];
  bdy = pb[1] - pd[1];
  cdy = pc[1] - pd[1];
  adz = pa[2] - pd[2];
  bdz = pb[2] - pd[2];
  cdz = pc[2] - pd[2];

  return adx * (bdy * cdz - bdz * cdy)
       + bdx * (cdy * adz - cdz * ady)
       + cdx * (ady * bdz - adz * bdy);
}

bool meshGRegionBoundaryRecovery::tetalldihedral(point pa, point pb, point pc,
  point pd, REAL* cosdd, REAL* cosmaxd, REAL* cosmind)
{
  REAL N[4][3], vol, cosd, len;
  int f1 = 0, f2 = 0, i, j;

  vol = 0; // Check if the tet is valid or not.

  // Get four normals of faces of the tet.
  tetallnormal(pa, pb, pc, pd, N, &vol);

  if (vol > 0) {
    // Normalize the normals.
    for (i = 0; i < 4; i++) {
      len = sqrt(dot(N[i], N[i]));
      if (len != 0.0) {
        for (j = 0; j < 3; j++) N[i][j] /= len;
      } else {
        // There are degeneracies, such as duplicated vertices.
        vol = 0; //assert(0);
      }
    }
  }

  if (vol <= 0) { // if (vol == 0.0) {
    // A degenerated tet or an inverted tet.
    facenormal(pc, pb, pd, N[0], 1, NULL);
    facenormal(pa, pc, pd, N[1], 1, NULL);
    facenormal(pb, pa, pd, N[2], 1, NULL);
    facenormal(pa, pb, pc, N[3], 1, NULL);
    // Normalize the normals.
    for (i = 0; i < 4; i++) {
      len = sqrt(dot(N[i], N[i]));
      if (len != 0.0) {
        for (j = 0; j < 3; j++) N[i][j] /= len;
      } else {
        // There are degeneracies, such as duplicated vertices.
        break; // Not a valid normal.
      }
    }
    if (i < 4) {
      // Do not calculate dihedral angles.
      // Set all angles be 0 degree. There will be no quality optimization for
      //   this tet! Use volume optimization to correct it.
      if (cosdd != NULL) {
        for (i = 0; i < 6; i++) {
          cosdd[i] = -1.0; // 180 degree.
        }
      }
      // This tet has zero volume.
      if (cosmaxd != NULL) {
        *cosmaxd = -1.0; // 180 degree.
      }
      if (cosmind != NULL) {
        *cosmind = -1.0; // 180 degree.
      }
      return false;
    }
  }

  // Calculate the cosine of the dihedral angles of the edges.
  for (i = 0; i < 6; i++) {
    switch (i) {
    case 0: f1 = 0; f2 = 1; break; // [c,d].
    case 1: f1 = 1; f2 = 2; break; // [a,d].
    case 2: f1 = 2; f2 = 3; break; // [a,b].
    case 3: f1 = 0; f2 = 3; break; // [b,c].
    case 4: f1 = 2; f2 = 0; break; // [b,d].
    case 5: f1 = 1; f2 = 3; break; // [a,c].
    }
    cosd = -dot(N[f1], N[f2]);
    if (cosd < -1.0) cosd = -1.0; // Rounding.
    if (cosd >  1.0) cosd =  1.0; // Rounding.
    if (cosdd) cosdd[i] = cosd;
    if (cosmaxd || cosmind) {
      if (i == 0) {
        if (cosmaxd) *cosmaxd = cosd;
        if (cosmind) *cosmind = cosd;
      } else {
        if (cosmaxd) *cosmaxd = cosd < *cosmaxd ? cosd : *cosmaxd;
        if (cosmind) *cosmind = cosd > *cosmind ? cosd : *cosmind;
      }
    }
  }

  return true;
}

void meshGRegionBoundaryRecovery::tetallnormal(point pa, point pb, point pc,
  point pd, REAL N[4][3], REAL* volume)
{
  REAL A[4][4], rhs[4], D;
  int indx[4];
  int i, j;

  // get the entries of A[3][3].
  for (i = 0; i < 3; i++) A[0][i] = pa[i] - pd[i];  // d->a vec
  for (i = 0; i < 3; i++) A[1][i] = pb[i] - pd[i];  // d->b vec
  for (i = 0; i < 3; i++) A[2][i] = pc[i] - pd[i];  // d->c vec

  // Compute the inverse of matrix A, to get 3 normals of the 4 faces.
  if (lu_decmp(A, 3, indx, &D, 0)) { // Decompose the matrix just once.
    if (volume != NULL) {
      // Get the volume of the tet.
      *volume = fabs((A[indx[0]][0] * A[indx[1]][1] * A[indx[2]][2])) / 6.0;
    }
    for (j = 0; j < 3; j++) {
      for (i = 0; i < 3; i++) rhs[i] = 0.0;
      rhs[j] = 1.0;  // Positive means the inside direction
      lu_solve(A, 3, indx, rhs, 0);
      for (i = 0; i < 3; i++) N[j][i] = rhs[i];
    }
    // Get the fourth normal by summing up the first three.
    for (i = 0; i < 3; i++) N[3][i] = - N[0][i] - N[1][i] - N[2][i];
  } else {
    // The tet is degenerated.
    if (volume != NULL) {
      *volume = 0;
    }
  }
}

REAL meshGRegionBoundaryRecovery::tetaspectratio(point pa, point pb, point pc,
  point pd)
{
  REAL vda[3], vdb[3], vdc[3];
  REAL N[4][3], A[4][4], rhs[4], D;
  REAL H[4], volume, radius2, minheightinv;
  int indx[4];
  int i, j;

  // Set the matrix A = [vda, vdb, vdc]^T.
  for (i = 0; i < 3; i++) A[0][i] = vda[i] = pa[i] - pd[i];
  for (i = 0; i < 3; i++) A[1][i] = vdb[i] = pb[i] - pd[i];
  for (i = 0; i < 3; i++) A[2][i] = vdc[i] = pc[i] - pd[i];
  // Lu-decompose the matrix A.
  lu_decmp(A, 3, indx, &D, 0);
  // Get the volume of abcd.
  volume = (A[indx[0]][0] * A[indx[1]][1] * A[indx[2]][2]) / 6.0;
  // Check if it is zero.
  if (volume == 0.0) return 1.0e+200; // A degenerate tet.
  // if (volume < 0.0) volume = -volume;
  // Check the radiu-edge ratio of the tet.
  rhs[0] = 0.5 * dot(vda, vda);
  rhs[1] = 0.5 * dot(vdb, vdb);
  rhs[2] = 0.5 * dot(vdc, vdc);
  lu_solve(A, 3, indx, rhs, 0);
  // Get the circumcenter.
  // for (i = 0; i < 3; i++) circumcent[i] = pd[i] + rhs[i];
  // Get the square of the circumradius.
  radius2 = dot(rhs, rhs);

  // Compute the 4 face normals (N[0], ..., N[3]).
  for (j = 0; j < 3; j++) {
    for (i = 0; i < 3; i++) rhs[i] = 0.0;
    rhs[j] = 1.0;  // Positive means the inside direction
    lu_solve(A, 3, indx, rhs, 0);
    for (i = 0; i < 3; i++) N[j][i] = rhs[i];
  }
  // Get the fourth normal by summing up the first three.
  for (i = 0; i < 3; i++) N[3][i] = - N[0][i] - N[1][i] - N[2][i];
  // Normalized the normals.
  for (i = 0; i < 4; i++) {
    // H[i] is the inverse of the height of its corresponding face.
    H[i] = sqrt(dot(N[i], N[i]));
    // if (H[i] > 0.0) {
    //   for (j = 0; j < 3; j++) N[i][j] /= H[i];
    // }
  }
  // Get the radius of the inscribed sphere.
  // insradius = 1.0 / (H[0] + H[1] + H[2] + H[3]);
  // Get the biggest H[i] (corresponding to the smallest height).
  minheightinv = H[0];
  for (i = 1; i < 4; i++) {
    if (H[i] > minheightinv) minheightinv = H[i];
  }

  return sqrt(radius2) * minheightinv;
}

bool meshGRegionBoundaryRecovery::circumsphere(REAL* pa, REAL* pb, REAL* pc,
  REAL* pd, REAL* cent, REAL* radius)
{
  REAL A[4][4], rhs[4], D;
  int indx[4];

  // Compute the coefficient matrix A (3x3).
  A[0][0] = pb[0] - pa[0];
  A[0][1] = pb[1] - pa[1];
  A[0][2] = pb[2] - pa[2];
  A[1][0] = pc[0] - pa[0];
  A[1][1] = pc[1] - pa[1];
  A[1][2] = pc[2] - pa[2];
  if (pd != NULL) {
    A[2][0] = pd[0] - pa[0];
    A[2][1] = pd[1] - pa[1];
    A[2][2] = pd[2] - pa[2];
  } else {
    cross(A[0], A[1], A[2]);
  }

  // Compute the right hand side vector b (3x1).
  rhs[0] = 0.5 * dot(A[0], A[0]);
  rhs[1] = 0.5 * dot(A[1], A[1]);
  if (pd != NULL) {
    rhs[2] = 0.5 * dot(A[2], A[2]);
  } else {
    rhs[2] = 0.0;
  }

  // Solve the 3 by 3 equations use LU decomposition with partial pivoting
  //   and backward and forward substitute..
  if (!lu_decmp(A, 3, indx, &D, 0)) {
    if (radius != (REAL *) NULL) *radius = 0.0;
    return false;
  }
  lu_solve(A, 3, indx, rhs, 0);
  if (cent != (REAL *) NULL) {
    cent[0] = pa[0] + rhs[0];
    cent[1] = pa[1] + rhs[1];
    cent[2] = pa[2] + rhs[2];
  }
  if (radius != (REAL *) NULL) {
    *radius = sqrt(rhs[0] * rhs[0] + rhs[1] * rhs[1] + rhs[2] * rhs[2]);
  }
  return true;
}

void meshGRegionBoundaryRecovery::planelineint(REAL* pa, REAL* pb, REAL* pc,
  REAL* e1, REAL* e2, REAL* ip, REAL* u)
{
  REAL n[3], det, det1;

  // Calculate N.
  facenormal(pa, pb, pc, n, 1, NULL);
  // Calculate N dot (e2 - e1).
  det = n[0] * (e2[0] - e1[0]) + n[1] * (e2[1] - e1[1])
      + n[2] * (e2[2] - e1[2]);
  if (det != 0.0) {
    // Calculate N dot (pa - e1)
    det1 = n[0] * (pa[0] - e1[0]) + n[1] * (pa[1] - e1[1])
         + n[2] * (pa[2] - e1[2]);
    *u = det1 / det;
    ip[0] = e1[0] + *u * (e2[0] - e1[0]);
    ip[1] = e1[1] + *u * (e2[1] - e1[1]);
    ip[2] = e1[2] + *u * (e2[2] - e1[2]);
  } else {
    *u = 0.0;
  }
}

int meshGRegionBoundaryRecovery::linelineint(REAL* A, REAL* B, REAL* C,
  REAL* D, REAL* P, REAL* Q, REAL* tp, REAL* tq)
{
  REAL vab[3], vcd[3], vca[3];
  REAL vab_vab, vcd_vcd, vab_vcd;
  REAL vca_vab, vca_vcd;
  REAL det, eps;
  int i;

  for (i = 0; i < 3; i++) {
    vab[i] = B[i] - A[i];
    vcd[i] = D[i] - C[i];
    vca[i] = A[i] - C[i];
  }

  vab_vab = dot(vab, vab);
  vcd_vcd = dot(vcd, vcd);
  vab_vcd = dot(vab, vcd);

  det = vab_vab * vcd_vcd - vab_vcd * vab_vcd;
  // Round the result.
  eps = det / (fabs(vab_vab * vcd_vcd) + fabs(vab_vcd * vab_vcd));
  if (eps < b->epsilon) {
    return 0;
  }

  vca_vab = dot(vca, vab);
  vca_vcd = dot(vca, vcd);

  *tp = (vcd_vcd * (- vca_vab) + vab_vcd * vca_vcd) / det;
  *tq = (vab_vcd * (- vca_vab) + vab_vab * vca_vcd) / det;

  for (i = 0; i < 3; i++) P[i] = A[i] + (*tp) * vab[i];
  for (i = 0; i < 3; i++) Q[i] = C[i] + (*tq) * vcd[i];

  return 1;
}

REAL meshGRegionBoundaryRecovery::tetprismvol(REAL* p0, REAL* p1, REAL* p2,
  REAL* p3)
{
  REAL *p4, *p5, *p6, *p7;
  REAL w4, w5, w6, w7;
  REAL vol[4];

  p4 = p0;
  p5 = p1;
  p6 = p2;
  p7 = p3;

  // TO DO: these weights can be pre-calculated!
  w4 = dot(p0, p0);
  w5 = dot(p1, p1);
  w6 = dot(p2, p2);
  w7 = dot(p3, p3);

  // Calculate the volume of the tet-prism.
  vol[0] = orient4dfast(p5, p6, p4, p3, p7, w5, w6, w4, 0, w7);
  vol[1] = orient4dfast(p3, p6, p2, p0, p1,  0, w6,  0, 0,  0);
  vol[2] = orient4dfast(p4, p6, p3, p0, p1, w4, w6,  0, 0,  0);
  vol[3] = orient4dfast(p6, p5, p4, p3, p1, w6, w5, w4, 0,  0);

  return fabs(vol[0]) + fabs(vol[1]) + fabs(vol[2]) + fabs(vol[3]);
}

void meshGRegionBoundaryRecovery::calculateabovepoint4(point pa, point pb,
  point pc, point pd)
{
  REAL n1[3], n2[3], *norm;
  REAL len, len1, len2;

  // Select a base.
  facenormal(pa, pb, pc, n1, 1, NULL);
  len1 = sqrt(dot(n1, n1));
  facenormal(pa, pb, pd, n2, 1, NULL);
  len2 = sqrt(dot(n2, n2));
  if (len1 > len2) {
    norm = n1;
    len = len1;
  } else {
    norm = n2;
    len = len2;
  }
  assert(len > 0);
  norm[0] /= len;
  norm[1] /= len;
  norm[2] /= len;
  len = distance(pa, pb);
  dummypoint[0] = pa[0] + len * norm[0];
  dummypoint[1] = pa[1] + len * norm[1];
  dummypoint[2] = pa[2] + len * norm[2];
}

////                                                                       ////
////                                                                       ////
//// geom_cxx /////////////////////////////////////////////////////////////////

//// flip_cxx /////////////////////////////////////////////////////////////////
////                                                                       ////
////                                                                       ////

void meshGRegionBoundaryRecovery::flip23(triface* fliptets, int hullflag, flipconstraints *fc)
{
  triface topcastets[3], botcastets[3];
  triface newface, casface;
  point pa, pb, pc, pd, pe;
  REAL attrib, volume;
  int dummyflag = 0;  // range = {-1, 0, 1, 2}.
  int i;

  if (hullflag > 0) {
    // Check if e is dummypoint.
    if (oppo(fliptets[1]) == dummypoint) {
      // Swap the two old tets.
      newface = fliptets[0];
      fliptets[0] = fliptets[1];
      fliptets[1] = newface;
      dummyflag = -1;  // d is dummypoint.
    } else {
      // Check if either a or b is dummypoint.
      if (org(fliptets[0]) == dummypoint) {
        dummyflag = 1; // a is dummypoint.
        enextself(fliptets[0]);
        eprevself(fliptets[1]);
      } else if (dest(fliptets[0]) == dummypoint) {
        dummyflag = 2; // b is dummypoint.
        eprevself(fliptets[0]);
        enextself(fliptets[1]);
      } else {
        dummyflag = 0; // either c or d may be dummypoint.
      }
    }
  }

  pa =  org(fliptets[0]);
  pb = dest(fliptets[0]);
  pc = apex(fliptets[0]);
  pd = oppo(fliptets[0]);
  pe = oppo(fliptets[1]);

  flip23count++;

  // Get the outer boundary faces.
  for (i = 0; i < 3; i++) {
    fnext(fliptets[0], topcastets[i]);
    enextself(fliptets[0]);
  }
  for (i = 0; i < 3; i++) {
    fnext(fliptets[1], botcastets[i]);
    eprevself(fliptets[1]);
  }

  // Re-use fliptets[0] and fliptets[1].
  fliptets[0].ver = 11;
  fliptets[1].ver = 11;
  setelemmarker(fliptets[0].tet, 0); // Clear all flags.
  setelemmarker(fliptets[1].tet, 0);
  // NOTE: the element attributes and volume constraint remain unchanged.
  if (checksubsegflag) {
    // Dealloc the space to subsegments.
    if (fliptets[0].tet[8] != NULL) {
      tet2segpool->dealloc((shellface *) fliptets[0].tet[8]);
      fliptets[0].tet[8] = NULL;
    }
    if (fliptets[1].tet[8] != NULL) {
      tet2segpool->dealloc((shellface *) fliptets[1].tet[8]);
      fliptets[1].tet[8] = NULL;
    }
  }
  if (checksubfaceflag) {
    // Dealloc the space to subfaces.
    if (fliptets[0].tet[9] != NULL) {
      tet2subpool->dealloc((shellface *) fliptets[0].tet[9]);
      fliptets[0].tet[9] = NULL;
    }
    if (fliptets[1].tet[9] != NULL) {
      tet2subpool->dealloc((shellface *) fliptets[1].tet[9]);
      fliptets[1].tet[9] = NULL;
    }
  }
  // Create a new tet.
  maketetrahedron(&(fliptets[2]));
  // The new tet have the same attributes from the old tet.
  for (i = 0; i < numelemattrib; i++) {
    attrib = elemattribute(fliptets[0].tet, i);
    setelemattribute(fliptets[2].tet, i, attrib);
  }
  if (b->varvolume) {
    volume = volumebound(fliptets[0].tet);
    setvolumebound(fliptets[2].tet, volume);
  }

  if (hullflag > 0) {
    // Check if d is dummytet.
    if (pd != dummypoint) {
      setvertices(fliptets[0], pe, pd, pa, pb); // [e,d,a,b] *
      setvertices(fliptets[1], pe, pd, pb, pc); // [e,d,b,c] *
      // Check if c is dummypoint.
      if (pc != dummypoint) {
        setvertices(fliptets[2], pe, pd, pc, pa);  // [e,d,c,a] *
      } else {
        setvertices(fliptets[2], pd, pe, pa, pc); // [d,e,a,c]
        esymself(fliptets[2]);                    // [e,d,c,a] *
      }
      // The hullsize does not change.
    } else {
      // d is dummypoint.
      setvertices(fliptets[0], pa, pb, pe, pd); // [a,b,e,d]
      setvertices(fliptets[1], pb, pc, pe, pd); // [b,c,e,d]
      setvertices(fliptets[2], pc, pa, pe, pd); // [c,a,e,d]
      // Adjust the faces to [e,d,a,b], [e,d,b,c], [e,d,c,a] *
      for (i = 0; i < 3; i++) {
        eprevesymself(fliptets[i]);
        enextself(fliptets[i]);
      }
      // We deleted one hull tet, and created three hull tets.
      hullsize += 2;
    }
  } else {
    setvertices(fliptets[0], pe, pd, pa, pb); // [e,d,a,b] *
    setvertices(fliptets[1], pe, pd, pb, pc); // [e,d,b,c] *
    setvertices(fliptets[2], pe, pd, pc, pa); // [e,d,c,a] *
  }

  if (fc->remove_ndelaunay_edge) { // calc_tetprism_vol
    REAL volneg[2], volpos[3], vol_diff;
    if (pd != dummypoint) {
      if (pc != dummypoint) {
        volpos[0] = tetprismvol(pe, pd, pa, pb);
        volpos[1] = tetprismvol(pe, pd, pb, pc);
        volpos[2] = tetprismvol(pe, pd, pc, pa);
        volneg[0] = tetprismvol(pa, pb, pc, pd);
        volneg[1] = tetprismvol(pb, pa, pc, pe);
      } else { // pc == dummypoint
        volpos[0] = tetprismvol(pe, pd, pa, pb);
        volpos[1] = 0.;
        volpos[2] = 0.;
        volneg[0] = 0.;
        volneg[1] = 0.;
      }
    } else { // pd == dummypoint.
      volpos[0] = 0.;
      volpos[1] = 0.;
      volpos[2] = 0.;
      volneg[0] = 0.;
      volneg[1] = tetprismvol(pb, pa, pc, pe);
    }
    vol_diff = volpos[0] + volpos[1] + volpos[2] - volneg[0] - volneg[1];
    fc->tetprism_vol_sum  += vol_diff; // Update the total sum.
  }

  // Bond three new tets together.
  for (i = 0; i < 3; i++) {
    esym(fliptets[i], newface);
    bond(newface, fliptets[(i + 1) % 3]);
  }
  // Bond to top outer boundary faces (at [a,b,c,d]).
  for (i = 0; i < 3; i++) {
    eorgoppo(fliptets[i], newface); // At edges [b,a], [c,b], [a,c].
    bond(newface, topcastets[i]);
  }
  // Bond bottom outer boundary faces (at [b,a,c,e]).
  for (i = 0; i < 3; i++) {
    edestoppo(fliptets[i], newface); // At edges [a,b], [b,c], [c,a].
    bond(newface, botcastets[i]);
  }

  if (checksubsegflag) {
    // Bond subsegments if there are.
    // Each new tet has 5 edges to be checked (except the edge [e,d]).
    face checkseg;
    // The middle three: [a,b], [b,c], [c,a].
    for (i = 0; i < 3; i++) {
      if (issubseg(topcastets[i])) {
        tsspivot1(topcastets[i], checkseg);
        eorgoppo(fliptets[i], newface);
        tssbond1(newface, checkseg);
        sstbond1(checkseg, newface);
        if (fc->chkencflag & 1) {
          //enqueuesubface(badsubsegs, &checkseg);
        }
      }
    }
    // The top three: [d,a], [d,b], [d,c]. Two tets per edge.
    for (i = 0; i < 3; i++) {
      eprev(topcastets[i], casface);
      if (issubseg(casface)) {
        tsspivot1(casface, checkseg);
        enext(fliptets[i], newface);
        tssbond1(newface, checkseg);
        sstbond1(checkseg, newface);
        esym(fliptets[(i + 2) % 3], newface);
        eprevself(newface);
        tssbond1(newface, checkseg);
        sstbond1(checkseg, newface);
        if (fc->chkencflag & 1) {
          //enqueuesubface(badsubsegs, &checkseg);
        }
      }
    }
    // The bot three: [a,e], [b,e], [c,e]. Two tets per edge.
    for (i = 0; i < 3; i++) {
      enext(botcastets[i], casface);
      if (issubseg(casface)) {
        tsspivot1(casface, checkseg);
        eprev(fliptets[i], newface);
        tssbond1(newface, checkseg);
        sstbond1(checkseg, newface);
        esym(fliptets[(i + 2) % 3], newface);
        enextself(newface);
        tssbond1(newface, checkseg);
        sstbond1(checkseg, newface);
        if (fc->chkencflag & 1) {
          //enqueuesubface(badsubsegs, &checkseg);
        }
      }
    }
  } // if (checksubsegflag)

  if (checksubfaceflag) {
    // Bond 6 subfaces if there are.
    face checksh;
    for (i = 0; i < 3; i++) {
      if (issubface(topcastets[i])) {
        tspivot(topcastets[i], checksh);
        eorgoppo(fliptets[i], newface);
        sesymself(checksh);
        tsbond(newface, checksh);
        if (fc->chkencflag & 2) {
          //enqueuesubface(badsubfacs, &checksh);
        }
      }
    }
    for (i = 0; i < 3; i++) {
      if (issubface(botcastets[i])) {
        tspivot(botcastets[i], checksh);
        edestoppo(fliptets[i], newface);
        sesymself(checksh);
        tsbond(newface, checksh);
        if (fc->chkencflag & 2) {
          //enqueuesubface(badsubfacs, &checksh);
        }
      }
    }
  } // if (checksubfaceflag)

  if (fc->chkencflag & 4) {
    // Put three new tets into check list.
    for (i = 0; i < 3; i++) {
      //enqueuetetrahedron(&(fliptets[i]));
    }
  }

  // Update the point-to-tet map.
  setpoint2tet(pa, (tetrahedron) fliptets[0].tet);
  setpoint2tet(pb, (tetrahedron) fliptets[0].tet);
  setpoint2tet(pc, (tetrahedron) fliptets[1].tet);
  setpoint2tet(pd, (tetrahedron) fliptets[0].tet);
  setpoint2tet(pe, (tetrahedron) fliptets[0].tet);

  if (hullflag > 0) {
    if (dummyflag != 0) {
      // Restore the original position of the points (for flipnm()).
      if (dummyflag == -1) {
        // Reverse the edge.
        for (i = 0; i < 3; i++) {
          esymself(fliptets[i]);
        }
        // Swap the last two new tets.
        newface = fliptets[1];
        fliptets[1] = fliptets[2];
        fliptets[2] = newface;
      } else {
        // either a or b were swapped.
        if (dummyflag == 1) {
          // a is dummypoint.
          newface = fliptets[0];
          fliptets[0] = fliptets[2];
          fliptets[2] = fliptets[1];
          fliptets[1] = newface;
        } else { // dummyflag == 2
          // b is dummypoint.
          newface = fliptets[0];
          fliptets[0] = fliptets[1];
          fliptets[1] = fliptets[2];
          fliptets[2] = newface;
        }
      }
    }
  }

  if (fc->enqflag > 0) {
    // Queue faces which may be locally non-Delaunay.
    for (i = 0; i < 3; i++) {
      eprevesym(fliptets[i], newface);
      flippush(flipstack, &newface);
    }
    if (fc->enqflag > 1) {
      for (i = 0; i < 3; i++) {
        enextesym(fliptets[i], newface);
        flippush(flipstack, &newface);
      }
    }
  }

  recenttet = fliptets[0];
}

void meshGRegionBoundaryRecovery::flip32(triface* fliptets, int hullflag, flipconstraints *fc)
{
  triface topcastets[3], botcastets[3];
  triface newface, casface;
  face flipshs[3];
  face checkseg;
  point pa, pb, pc, pd, pe;
  REAL attrib, volume;
  int dummyflag = 0;  // Rangle = {-1, 0, 1, 2}
  int spivot = -1, scount = 0; // for flip22()
  int t1ver;
  int i, j;

  if (hullflag > 0) {
    // Check if e is 'dummypoint'.
    if (org(fliptets[0]) == dummypoint) {
      // Reverse the edge.
      for (i = 0; i < 3; i++) {
        esymself(fliptets[i]);
      }
      // Swap the last two tets.
      newface = fliptets[1];
      fliptets[1] = fliptets[2];
      fliptets[2] = newface;
      dummyflag = -1; // e is dummypoint.
    } else {
      // Check if a or b is the 'dummypoint'.
      if (apex(fliptets[0]) == dummypoint) {
        dummyflag = 1;  // a is dummypoint.
        newface = fliptets[0];
        fliptets[0] = fliptets[1];
        fliptets[1] = fliptets[2];
        fliptets[2] = newface;
      } else if (apex(fliptets[1]) == dummypoint) {
        dummyflag = 2;  // b is dummypoint.
        newface = fliptets[0];
        fliptets[0] = fliptets[2];
        fliptets[2] = fliptets[1];
        fliptets[1] = newface;
      } else {
        dummyflag = 0;  // either c or d may be dummypoint.
      }
    }
  }

  pa = apex(fliptets[0]);
  pb = apex(fliptets[1]);
  pc = apex(fliptets[2]);
  pd = dest(fliptets[0]);
  pe = org(fliptets[0]);

  flip32count++;

  // Get the outer boundary faces.
  for (i = 0; i < 3; i++) {
    eorgoppo(fliptets[i], casface);
    fsym(casface, topcastets[i]);
  }
  for (i = 0; i < 3; i++) {
    edestoppo(fliptets[i], casface);
    fsym(casface, botcastets[i]);
  }

  if (checksubfaceflag) {
    // Check if there are interior subfaces at the edge [e,d].
    for (i = 0; i < 3; i++) {
      tspivot(fliptets[i], flipshs[i]);
      if (flipshs[i].sh != NULL) {
        // Found an interior subface.
        stdissolve(flipshs[i]); // Disconnect the sub-tet bond.
        scount++;
      } else {
        spivot = i;
      }
    }
  }

  // Re-use fliptets[0] and fliptets[1].
  fliptets[0].ver = 11;
  fliptets[1].ver = 11;
  setelemmarker(fliptets[0].tet, 0); // Clear all flags.
  setelemmarker(fliptets[1].tet, 0);
  if (checksubsegflag) {
    // Dealloc the space to subsegments.
    if (fliptets[0].tet[8] != NULL) {
      tet2segpool->dealloc((shellface *) fliptets[0].tet[8]);
      fliptets[0].tet[8] = NULL;
    }
    if (fliptets[1].tet[8] != NULL) {
      tet2segpool->dealloc((shellface *) fliptets[1].tet[8]);
      fliptets[1].tet[8] = NULL;
    }
  }
  if (checksubfaceflag) {
    // Dealloc the space to subfaces.
    if (fliptets[0].tet[9] != NULL) {
      tet2subpool->dealloc((shellface *) fliptets[0].tet[9]);
      fliptets[0].tet[9] = NULL;
    }
    if (fliptets[1].tet[9] != NULL) {
      tet2subpool->dealloc((shellface *) fliptets[1].tet[9]);
      fliptets[1].tet[9] = NULL;
    }
  }
  if (checksubfaceflag) {
    if (scount > 0) {
      // The element attributes and volume constraint must be set correctly.
      // There are two subfaces involved in this flip. The three tets are
      //   separated into two different regions, one may be exterior. The
      //   first region has two tets, and the second region has only one.
      //   The two created tets must be in the same region as the first region.
      //   The element attributes and volume constraint must be set correctly.
      //assert(spivot != -1);
      // The tet fliptets[spivot] is in the first region.
      for (j = 0; j < 2; j++) {
        for (i = 0; i < numelemattrib; i++) {
          attrib = elemattribute(fliptets[spivot].tet, i);
          setelemattribute(fliptets[j].tet, i, attrib);
        }
        if (b->varvolume) {
          volume = volumebound(fliptets[spivot].tet);
          setvolumebound(fliptets[j].tet, volume);
        }
      }
    }
  }
  // Delete an old tet.
  tetrahedrondealloc(fliptets[2].tet);

  if (hullflag > 0) {
    // Check if c is dummypointc.
    if (pc != dummypoint) {
      // Check if d is dummypoint.
      if (pd != dummypoint) {
        // No hull tet is involved.
      } else {
        // We deleted three hull tets, and created one hull tet.
        hullsize -= 2;
      }
      setvertices(fliptets[0], pa, pb, pc, pd);
      setvertices(fliptets[1], pb, pa, pc, pe);
    } else {
      // c is dummypoint. The two new tets are hull tets.
      setvertices(fliptets[0], pb, pa, pd, pc);
      setvertices(fliptets[1], pa, pb, pe, pc);
      // Adjust badc -> abcd.
      esymself(fliptets[0]);
      // Adjust abec -> bace.
      esymself(fliptets[1]);
      // The hullsize does not change.
    }
  } else {
    setvertices(fliptets[0], pa, pb, pc, pd);
    setvertices(fliptets[1], pb, pa, pc, pe);
  }

  if (fc->remove_ndelaunay_edge) { // calc_tetprism_vol
    REAL volneg[3], volpos[2], vol_diff;
    if (pc != dummypoint) {
      if (pd != dummypoint) {
        volneg[0] = tetprismvol(pe, pd, pa, pb);
        volneg[1] = tetprismvol(pe, pd, pb, pc);
        volneg[2] = tetprismvol(pe, pd, pc, pa);
        volpos[0] = tetprismvol(pa, pb, pc, pd);
        volpos[1] = tetprismvol(pb, pa, pc, pe);
      } else { // pd == dummypoint
        volneg[0] = 0.;
        volneg[1] = 0.;
        volneg[2] = 0.;
        volpos[0] = 0.;
        volpos[1] = tetprismvol(pb, pa, pc, pe);
      }
    } else { // pc == dummypoint.
      volneg[0] = tetprismvol(pe, pd, pa, pb);
      volneg[1] = 0.;
      volneg[2] = 0.;
      volpos[0] = 0.;
      volpos[1] = 0.;
    }
    vol_diff = volpos[0] + volpos[1] - volneg[0] - volneg[1] - volneg[2];
    fc->tetprism_vol_sum  += vol_diff; // Update the total sum.
  }

  // Bond abcd <==> bace.
  bond(fliptets[0], fliptets[1]);
  // Bond new faces to top outer boundary faces (at abcd).
  for (i = 0; i < 3; i++) {
    esym(fliptets[0], newface);
    bond(newface, topcastets[i]);
    enextself(fliptets[0]);
  }
  // Bond new faces to bottom outer boundary faces (at bace).
  for (i = 0; i < 3; i++) {
    esym(fliptets[1], newface);
    bond(newface, botcastets[i]);
    eprevself(fliptets[1]);
  }

  if (checksubsegflag) {
    // Bond 9 segments to new (flipped) tets.
    for (i = 0; i < 3; i++) { // edges a->b, b->c, c->a.
      if (issubseg(topcastets[i])) {
        tsspivot1(topcastets[i], checkseg);
        tssbond1(fliptets[0], checkseg);
        sstbond1(checkseg, fliptets[0]);
        tssbond1(fliptets[1], checkseg);
        sstbond1(checkseg, fliptets[1]);
        if (fc->chkencflag & 1) {
          //enqueuesubface(badsubsegs, &checkseg);
        }
      }
      enextself(fliptets[0]);
      eprevself(fliptets[1]);
    }
    // The three top edges.
    for (i = 0; i < 3; i++) { // edges b->d, c->d, a->d.
      esym(fliptets[0], newface);
      eprevself(newface);
      enext(topcastets[i], casface);
      if (issubseg(casface)) {
        tsspivot1(casface, checkseg);
        tssbond1(newface, checkseg);
        sstbond1(checkseg, newface);
        if (fc->chkencflag & 1) {
          //enqueuesubface(badsubsegs, &checkseg);
        }
      }
      enextself(fliptets[0]);
    }
    // The three bot edges.
    for (i = 0; i < 3; i++) { // edges b<-e, c<-e, a<-e.
      esym(fliptets[1], newface);
      enextself(newface);
      eprev(botcastets[i], casface);
      if (issubseg(casface)) {
        tsspivot1(casface, checkseg);
        tssbond1(newface, checkseg);
        sstbond1(checkseg, newface);
        if (fc->chkencflag & 1) {
          //enqueuesubface(badsubsegs, &checkseg);
        }
      }
      eprevself(fliptets[1]);
    }
  } // if (checksubsegflag)

  if (checksubfaceflag) {
    face checksh;
    // Bond the top three casing subfaces.
    for (i = 0; i < 3; i++) { // At edges [b,a], [c,b], [a,c]
      if (issubface(topcastets[i])) {
        tspivot(topcastets[i], checksh);
        esym(fliptets[0], newface);
        sesymself(checksh);
        tsbond(newface, checksh);
        if (fc->chkencflag & 2) {
          //enqueuesubface(badsubfacs, &checksh);
        }
      }
      enextself(fliptets[0]);
    }
    // Bond the bottom three casing subfaces.
    for (i = 0; i < 3; i++) { // At edges [a,b], [b,c], [c,a]
      if (issubface(botcastets[i])) {
        tspivot(botcastets[i], checksh);
        esym(fliptets[1], newface);
        sesymself(checksh);
        tsbond(newface, checksh);
        if (fc->chkencflag & 2) {
          //enqueuesubface(badsubfacs, &checksh);
        }
      }
      eprevself(fliptets[1]);
    }

    if (scount > 0) {
      face flipfaces[2];
      // Perform a 2-to-2 flip in subfaces.
      flipfaces[0] = flipshs[(spivot + 1) % 3];
      flipfaces[1] = flipshs[(spivot + 2) % 3];
      sesymself(flipfaces[1]);
      flip22(flipfaces, 0, fc->chkencflag);
      // Connect the flipped subfaces to flipped tets.
      // First go to the corresponding flipping edge.
      //   Re-use top- and botcastets[0].
      topcastets[0] = fliptets[0];
      botcastets[0] = fliptets[1];
      for (i = 0; i < ((spivot + 1) % 3); i++) {
        enextself(topcastets[0]);
        eprevself(botcastets[0]);
      }
      // Connect the top subface to the top tets.
      esymself(topcastets[0]);
      sesymself(flipfaces[0]);
      // Check if there already exists a subface.
      tspivot(topcastets[0], checksh);
      if (checksh.sh == NULL) {
        tsbond(topcastets[0], flipfaces[0]);
        fsymself(topcastets[0]);
        sesymself(flipfaces[0]);
        tsbond(topcastets[0], flipfaces[0]);
      } else {
        // An invalid 2-to-2 flip. Report a bug.
        terminateBoundaryRecovery(this, 2);
      }
      // Connect the bot subface to the bottom tets.
      esymself(botcastets[0]);
      sesymself(flipfaces[1]);
      // Check if there already exists a subface.
      tspivot(botcastets[0], checksh);
      if (checksh.sh == NULL) {
        tsbond(botcastets[0], flipfaces[1]);
        fsymself(botcastets[0]);
        sesymself(flipfaces[1]);
        tsbond(botcastets[0], flipfaces[1]);
      } else {
        // An invalid 2-to-2 flip. Report a bug.
        terminateBoundaryRecovery(this, 2);
      }
    } // if (scount > 0)
  } // if (checksubfaceflag)

  if (fc->chkencflag & 4) {
    // Put two new tets into check list.
    for (i = 0; i < 2; i++) {
      //enqueuetetrahedron(&(fliptets[i]));
    }
  }

  setpoint2tet(pa, (tetrahedron) fliptets[0].tet);
  setpoint2tet(pb, (tetrahedron) fliptets[0].tet);
  setpoint2tet(pc, (tetrahedron) fliptets[0].tet);
  setpoint2tet(pd, (tetrahedron) fliptets[0].tet);
  setpoint2tet(pe, (tetrahedron) fliptets[1].tet);

  if (hullflag > 0) {
    if (dummyflag != 0) {
      // Restore the original position of the points (for flipnm()).
      if (dummyflag == -1) {
        // e were dummypoint. Swap the two new tets.
        newface = fliptets[0];
        fliptets[0] = fliptets[1];
        fliptets[1] = newface;
      } else {
        // a or b was dummypoint.
        if (dummyflag == 1) {
          eprevself(fliptets[0]);
          enextself(fliptets[1]);
        } else { // dummyflag == 2
          enextself(fliptets[0]);
          eprevself(fliptets[1]);
        }
      }
    }
  }

  if (fc->enqflag > 0) {
    // Queue faces which may be locally non-Delaunay.
    // pa = org(fliptets[0]); // 'a' may be a new vertex.
    enextesym(fliptets[0], newface);
    flippush(flipstack, &newface);
    eprevesym(fliptets[1], newface);
    flippush(flipstack, &newface);
    if (fc->enqflag > 1) {
      //pb = dest(fliptets[0]);
      eprevesym(fliptets[0], newface);
      flippush(flipstack, &newface);
      enextesym(fliptets[1], newface);
      flippush(flipstack, &newface);
      //pc = apex(fliptets[0]);
      esym(fliptets[0], newface);
      flippush(flipstack, &newface);
      esym(fliptets[1], newface);
      flippush(flipstack, &newface);
    }
  }

  recenttet = fliptets[0];
}

void meshGRegionBoundaryRecovery::flip41(triface* fliptets, int hullflag, flipconstraints *fc)
{
  triface topcastets[3], botcastet;
  triface newface, neightet;
  face flipshs[4];
  point pa, pb, pc, pd, pp;
  int dummyflag = 0; // in {0, 1, 2, 3, 4}
  int spivot = -1, scount = 0;
  int t1ver;
  int i;

  pa =  org(fliptets[3]);
  pb = dest(fliptets[3]);
  pc = apex(fliptets[3]);
  pd = dest(fliptets[0]);
  pp =  org(fliptets[0]); // The removing vertex.

  flip41count++;

  // Get the outer boundary faces.
  for (i = 0; i < 3; i++) {
    enext(fliptets[i], topcastets[i]);
    fnextself(topcastets[i]); // [d,a,b,#], [d,b,c,#], [d,c,a,#]
    enextself(topcastets[i]); // [a,b,d,#], [b,c,d,#], [c,a,d,#]
  }
  fsym(fliptets[3], botcastet); // [b,a,c,#]

  if (checksubfaceflag) {
    // Check if there are three subfaces at 'p'.
    //   Re-use 'newface'.
    for (i = 0; i < 3; i++) {
      fnext(fliptets[3], newface); // [a,b,p,d],[b,c,p,d],[c,a,p,d].
      tspivot(newface, flipshs[i]);
      if (flipshs[i].sh != NULL) {
        spivot = i; // Remember this subface.
        scount++;
      }
      enextself(fliptets[3]);
    }
    if (scount > 0) {
      // There are three subfaces connecting at p.
      if (scount < 3) {
        // The new subface is one of {[a,b,d], [b,c,d], [c,a,d]}.
        assert(scount == 1); // spivot >= 0
        // Go to the tet containing the three subfaces.
        fsym(topcastets[spivot], neightet);
        // Get the three subfaces connecting at p.
        for (i = 0; i < 3; i++) {
          esym(neightet, newface);
          tspivot(newface, flipshs[i]);
          assert(flipshs[i].sh != NULL);
          eprevself(neightet);
        }
      } else {
        spivot = 3; // The new subface is [a,b,c].
      }
    }
  } // if (checksubfaceflag)


  // Re-use fliptets[0] for [a,b,c,d].
  fliptets[0].ver = 11;
  setelemmarker(fliptets[0].tet, 0); // Clean all flags.
  // NOTE: the element attributes and volume constraint remain unchanged.
  if (checksubsegflag) {
    // Dealloc the space to subsegments.
    if (fliptets[0].tet[8] != NULL) {
      tet2segpool->dealloc((shellface *) fliptets[0].tet[8]);
      fliptets[0].tet[8] = NULL;
    }
  }
  if (checksubfaceflag) {
    // Dealloc the space to subfaces.
    if (fliptets[0].tet[9] != NULL) {
      tet2subpool->dealloc((shellface *) fliptets[0].tet[9]);
      fliptets[0].tet[9] = NULL;
    }
  }
  // Delete the other three tets.
  for (i = 1; i < 4; i++) {
    tetrahedrondealloc(fliptets[i].tet);
  }

  if (pp != dummypoint) {
    // Mark the point pp as unused.
    setpointtype(pp, UNUSEDVERTEX);
    unuverts++;
  }

  // Create the new tet [a,b,c,d].
  if (hullflag > 0) {
    // One of the five vertices may be 'dummypoint'.
    if (pa == dummypoint) {
      // pa is dummypoint.
      setvertices(fliptets[0], pc, pb, pd, pa);
      esymself(fliptets[0]);  // [b,c,a,d]
      eprevself(fliptets[0]); // [a,b,c,d]
      dummyflag = 1;
    } else if (pb == dummypoint) {
      setvertices(fliptets[0], pa, pc, pd, pb);
      esymself(fliptets[0]);  // [c,a,b,d]
      enextself(fliptets[0]); // [a,b,c,d]
      dummyflag = 2;
    } else if (pc == dummypoint) {
      setvertices(fliptets[0], pb, pa, pd, pc);
      esymself(fliptets[0]);  // [a,b,c,d]
      dummyflag = 3;
    } else if (pd == dummypoint) {
      setvertices(fliptets[0], pa, pb, pc, pd);
      dummyflag = 4;
    } else {
      setvertices(fliptets[0], pa, pb, pc, pd);
      if (pp == dummypoint) {
        dummyflag = -1;
      } else {
        dummyflag = 0;
      }
    }
    if (dummyflag > 0) {
      // We deleted 3 hull tets, and create 1 hull tet.
      hullsize -= 2;
    } else if (dummyflag < 0) {
      // We deleted 4 hull tets.
      hullsize -= 4;
      // meshedges does not change.
    }
  } else {
    setvertices(fliptets[0], pa, pb, pc, pd);
  }

  if (fc->remove_ndelaunay_edge) { // calc_tetprism_vol
    REAL volneg[4], volpos[1], vol_diff;
    if (dummyflag > 0) {
      if (pa == dummypoint) {
        volneg[0] = 0.;
        volneg[1] = tetprismvol(pp, pd, pb, pc);
        volneg[2] = 0.;
        volneg[3] = 0.;
      } else if (pb == dummypoint) {
        volneg[0] = 0.;
        volneg[1] = 0.;
        volneg[2] = tetprismvol(pp, pd, pc, pa);
        volneg[3] = 0.;
      } else if (pc == dummypoint) {
        volneg[0] = tetprismvol(pp, pd, pa, pb);
        volneg[1] = 0.;
        volneg[2] = 0.;
        volneg[3] = 0.;
      } else { // pd == dummypoint
        volneg[0] = 0.;
        volneg[1] = 0.;
        volneg[2] = 0.;
        volneg[3] = tetprismvol(pa, pb, pc, pp);
      }
      volpos[0] = 0.;
    } else if (dummyflag < 0) {
      volneg[0] = 0.;
      volneg[1] = 0.;
      volneg[2] = 0.;
      volneg[3] = 0.;
      volpos[0] = tetprismvol(pa, pb, pc, pd);
    } else {
      volneg[0] = tetprismvol(pp, pd, pa, pb);
      volneg[1] = tetprismvol(pp, pd, pb, pc);
      volneg[2] = tetprismvol(pp, pd, pc, pa);
      volneg[3] = tetprismvol(pa, pb, pc, pp);
      volpos[0] = tetprismvol(pa, pb, pc, pd);
    }
    vol_diff = volpos[0] - volneg[0] - volneg[1] - volneg[2] - volneg[3];
    fc->tetprism_vol_sum  += vol_diff; // Update the total sum.
  }

  // Bond the new tet to adjacent tets.
  for (i = 0; i < 3; i++) {
    esym(fliptets[0], newface); // At faces [b,a,d], [c,b,d], [a,c,d].
    bond(newface, topcastets[i]);
    enextself(fliptets[0]);
  }
  bond(fliptets[0], botcastet);

  if (checksubsegflag) {
    face checkseg;
    // Bond 6 segments (at edges of [a,b,c,d]) if there there are.
    for (i = 0; i < 3; i++) {
      eprev(topcastets[i], newface); // At edges [d,a],[d,b],[d,c].
      if (issubseg(newface)) {
        tsspivot1(newface, checkseg);
        esym(fliptets[0], newface);
        enextself(newface); // At edges [a,d], [b,d], [c,d].
        tssbond1(newface, checkseg);
        sstbond1(checkseg, newface);
        if (fc->chkencflag & 1) {
          //enqueuesubface(badsubsegs, &checkseg);
        }
      }
      enextself(fliptets[0]);
    }
    for (i = 0; i < 3; i++) {
      if (issubseg(topcastets[i])) {
        tsspivot1(topcastets[i], checkseg); // At edges [a,b],[b,c],[c,a].
        tssbond1(fliptets[0], checkseg);
        sstbond1(checkseg, fliptets[0]);
        if (fc->chkencflag & 1) {
          //enqueuesubface(badsubsegs, &checkseg);
        }
      }
      enextself(fliptets[0]);
    }
  }

  if (checksubfaceflag) {
    face checksh;
    // Bond 4 subfaces (at faces of [a,b,c,d]) if there are.
    for (i = 0; i < 3; i++) {
      if (issubface(topcastets[i])) {
        tspivot(topcastets[i], checksh); // At faces [a,b,d],[b,c,d],[c,a,d]
        esym(fliptets[0], newface); // At faces [b,a,d],[c,b,d],[a,c,d]
        sesymself(checksh);
        tsbond(newface, checksh);
        if (fc->chkencflag & 2) {
          //enqueuesubface(badsubfacs, &checksh);
        }
      }
      enextself(fliptets[0]);
    }
    if (issubface(botcastet)) {
      tspivot(botcastet, checksh); // At face [b,a,c]
      sesymself(checksh);
      tsbond(fliptets[0], checksh);
      if (fc->chkencflag & 2) {
        //enqueuesubface(badsubfacs, &checksh);
      }
    }

    if (spivot >= 0) {
      // Perform a 3-to-1 flip in surface triangulation.
      // Depending on the value of 'spivot', the three subfaces are:
      //   - 0: [a,b,p], [b,d,p], [d,a,p]
      //   - 1: [b,c,p], [c,d,p], [d,b,p]
      //   - 2: [c,a,p], [a,d,p], [d,c,p]
      //   - 3: [a,b,p], [b,c,p], [c,a,p]
      // Adjust the three subfaces such that their origins are p, i.e.,
      //   - 3: [p,a,b], [p,b,c], [p,c,a]. (Required by the flip31()).
      for (i = 0; i < 3; i++) {
        senext2self(flipshs[i]);
      }
      flip31(flipshs, 0);
      // Delete the three old subfaces.
      for (i = 0; i < 3; i++) {
        shellfacedealloc(subfaces, flipshs[i].sh);
      }
      if (spivot < 3) {
        // // Bond the new subface to the new tet [a,b,c,d].
        tsbond(topcastets[spivot], flipshs[3]);
        fsym(topcastets[spivot], newface);
        sesym(flipshs[3], checksh);
        tsbond(newface, checksh);
      } else {
        // Bound the new subface [a,b,c] to the new tet [a,b,c,d].
        tsbond(fliptets[0], flipshs[3]);
        fsym(fliptets[0], newface);
        sesym(flipshs[3], checksh);
        tsbond(newface, checksh);
      }
    } // if (spivot > 0)
  } // if (checksubfaceflag)

  if (fc->chkencflag & 4) {
    //enqueuetetrahedron(&(fliptets[0]));
  }

  // Update the point-to-tet map.
  setpoint2tet(pa, (tetrahedron) fliptets[0].tet);
  setpoint2tet(pb, (tetrahedron) fliptets[0].tet);
  setpoint2tet(pc, (tetrahedron) fliptets[0].tet);
  setpoint2tet(pd, (tetrahedron) fliptets[0].tet);

  if (fc->enqflag > 0) {
    // Queue faces which may be locally non-Delaunay.
    flippush(flipstack, &(fliptets[0])); // [a,b,c] (opposite to new point).
    if (fc->enqflag > 1) {
      for (i = 0; i < 3; i++) {
        esym(fliptets[0], newface);
        flippush(flipstack, &newface);
        enextself(fliptets[0]);
      }
    }
  }

  recenttet = fliptets[0];
}

int meshGRegionBoundaryRecovery::flipnm(triface* abtets, int n, int level, int abedgepivot,
                       flipconstraints* fc)
{
  triface fliptets[3], spintet, flipedge;
  triface *tmpabtets, *parytet;
  point pa, pb, pc, pd, pe, pf;
  REAL ori;
  int hullflag, hulledgeflag;
  int reducflag, rejflag;
  int reflexlinkedgecount;
  int edgepivot;
  int n1, nn;
  int t1ver;
  int i, j;

  pa = org(abtets[0]);
  pb = dest(abtets[0]);

  if (n > 3) {
    // Try to reduce the size of the Star(ab) by flipping a face in it.
    reflexlinkedgecount = 0;

    for (i = 0; i < n; i++) {
      // Let the face of 'abtets[i]' be [a,b,c].
      if (checksubfaceflag) {
        if (issubface(abtets[i])) {
          continue; // Skip a subface.
        }
      }
      // Do not flip this face if it is involved in two Stars.
      if ((elemcounter(abtets[i]) > 1) ||
          (elemcounter(abtets[(i - 1 + n) % n]) > 1)) {
        continue;
      }

      pc = apex(abtets[i]);
      pd = apex(abtets[(i + 1) % n]);
      pe = apex(abtets[(i - 1 + n) % n]);
      if ((pd == dummypoint) || (pe == dummypoint)) {
        continue; // [a,b,c] is a hull face.
      }


      // Decide whether [a,b,c] is flippable or not.
      reducflag = 0;

      hullflag = (pc == dummypoint); // pc may be dummypoint.
      hulledgeflag = 0;
      if (hullflag == 0) {
        ori = orient3d(pb, pc, pd, pe); // Is [b,c] locally convex?
        if (ori > 0) {
          ori = orient3d(pc, pa, pd, pe); // Is [c,a] locally convex?
          if (ori > 0) {
            // Test if [a,b] is locally convex OR flat.
            ori = orient3d(pa, pb, pd, pe);
            if (ori > 0) {
              // Found a 2-to-3 flip: [a,b,c] => [e,d]
              reducflag = 1;
            } else if (ori == 0) {
              // [a,b] is flat.
              if (n == 4) {
                // The "flat" tet can be removed immediately by a 3-to-2 flip.
                reducflag = 1;
                // Check if [e,d] is a hull edge.
                pf = apex(abtets[(i + 2) % n]);
                hulledgeflag = (pf == dummypoint);
              }
            }
          }
        }
        if (!reducflag) {
          reflexlinkedgecount++;
        }
      } else {
        // 'c' is dummypoint.
        if (n == 4) {
          // Let the vertex opposite to 'c' is 'f'.
          // A 4-to-4 flip is possible if the two tets [d,e,f,a] and [e,d,f,b]
          //   are valid tets.
          // Note: When the mesh is not convex, it is possible that [a,b] is
          //   locally non-convex (at hull faces [a,b,e] and [b,a,d]).
          //   In this case, an edge flip [a,b] to [e,d] is still possible.
          pf = apex(abtets[(i + 2) % n]);
          assert(pf != dummypoint);
          ori = orient3d(pd, pe, pf, pa);
          if (ori < 0) {
            ori = orient3d(pe, pd, pf, pb);
            if (ori < 0) {
              // Found a 4-to-4 flip: [a,b] => [e,d]
              reducflag = 1;
              ori = 0; // Signal as a 4-to-4 flip (like a co-planar case).
              hulledgeflag = 1; // [e,d] is a hull edge.
            }
          }
        }
      } // if (hullflag)

      if (reducflag) {
        if (nonconvex && hulledgeflag) {
          // We will create a hull edge [e,d]. Make sure it does not exist.
          if (getedge(pe, pd, &spintet)) {
            // The 2-to-3 flip is not a topological valid flip.
            reducflag = 0;
          }
        }
      }

      if (reducflag) {
        // [a,b,c] could be removed by a 2-to-3 flip.
        rejflag = 0;
        if (fc->checkflipeligibility) {
          // Check if the flip can be performed.
          rejflag = checkflipeligibility(1, pa, pb, pc, pd, pe, level,
                                         abedgepivot, fc);
        }
        if (!rejflag) {
          // Do flip: [a,b,c] => [e,d].
          fliptets[0] = abtets[i];
          fsym(fliptets[0], fliptets[1]); // abtets[i-1].
          flip23(fliptets, hullflag, fc);

          // Shrink the array 'abtets', maintain the original order.
          //   Two tets 'abtets[i-1] ([a,b,e,c])' and 'abtets[i] ([a,b,c,d])'
          //   are flipped, i.e., they do not in Star(ab) anymore.
          //   'fliptets[0]' ([e,d,a,b]) is in Star(ab), it is saved in
          //   'abtets[i-1]' (adjust it to be [a,b,e,d]), see below:
          //
          //            before                   after
          //     [0] |___________|        [0] |___________|
          //     ... |___________|        ... |___________|
          //   [i-1] |_[a,b,e,c]_|      [i-1] |_[a,b,e,d]_|
          //     [i] |_[a,b,c,d]_| -->    [i] |_[a,b,d,#]_|
          //   [i+1] |_[a,b,d,#]_|      [i+1] |_[a,b,#,*]_|
          //     ... |___________|        ... |___________|
          //   [n-2] |___________|      [n-2] |___________|
          //   [n-1] |___________|      [n-1] |_[i]_2-t-3_|
          //
          edestoppoself(fliptets[0]); // [a,b,e,d]
          // Increase the counter of this new tet (it is in Star(ab)).
          increaseelemcounter(fliptets[0]);
          abtets[(i - 1 + n) % n] = fliptets[0];
          for (j = i; j < n - 1; j++) {
            abtets[j] = abtets[j + 1];  // Upshift
          }
          // The last entry 'abtets[n-1]' is empty. It is used in two ways:
          //   (i) it remembers the vertex 'c' (in 'abtets[n-1].tet'), and
          //  (ii) it remembers the position [i] where this flip took place.
          // These informations let us to either undo this flip or recover
          //   the original edge link (for collecting new created tets).
          //abtets[n - 1] = fliptets[1]; // [e,d,b,c] is remembered.
          abtets[n - 1].tet = (tetrahedron *) pc;
          abtets[n - 1].ver = 0; // Clear it.
          // 'abtets[n - 1].ver' is in range [0,11] -- only uses 4 bits.
          // Use the 5th bit in 'abtets[n - 1].ver' to signal a 2-to-3 flip.
          abtets[n - 1].ver |= (1 << 4);
          // The poisition [i] of this flip is saved above the 7th bit.
          abtets[n - 1].ver |= (i << 6);

          if (fc->collectnewtets) {
            // Push the two new tets [e,d,b,c] and [e,d,c,a] into a stack.
            //   Re-use the global array 'cavetetlist'.
            for (j = 1; j < 3; j++) {
              cavetetlist->newindex((void **) &parytet);
              *parytet = fliptets[j]; // fliptets[1], fliptets[2].
            }
          }

          // Star(ab) is reduced. Try to flip the edge [a,b].
          nn = flipnm(abtets, n - 1, level, abedgepivot, fc);

          if (nn == 2) {
            // The edge has been flipped.
            return nn;
          } else { // if (nn > 2)
            // The edge is not flipped.
            if (fc->unflip || (ori == 0)) {
              // Undo the previous 2-to-3 flip, i.e., do a 3-to-2 flip to
              //   transform [e,d] => [a,b,c].
              // 'ori == 0' means that the previous flip created a degenerated
              //   tet. It must be removed.
              // Remember that 'abtets[i-1]' is [a,b,e,d]. We can use it to
              //   find another two tets [e,d,b,c] and [e,d,c,a].
              fliptets[0] = abtets[(i-1 + (n-1)) % (n-1)]; // [a,b,e,d]
              edestoppoself(fliptets[0]); // [e,d,a,b]
              fnext(fliptets[0], fliptets[1]); // [1] is [e,d,b,c]
              fnext(fliptets[1], fliptets[2]); // [2] is [e,d,c,a]
              assert(apex(fliptets[0]) == oppo(fliptets[2])); // SELF_CHECK
              // Restore the two original tets in Star(ab).
              flip32(fliptets, hullflag, fc);
              // Marktest the two restored tets in Star(ab).
              for (j = 0; j < 2; j++) {
                increaseelemcounter(fliptets[j]);
              }
              // Expand the array 'abtets', maintain the original order.
              for (j = n - 2; j>= i; j--) {
                abtets[j + 1] = abtets[j];  // Downshift
              }
              // Insert the two new tets 'fliptets[0]' [a,b,c,d] and
              //  'fliptets[1]' [b,a,c,e] into the (i-1)-th and i-th entries,
              //  respectively.
              esym(fliptets[1], abtets[(i - 1 + n) % n]); // [a,b,e,c]
              abtets[i] = fliptets[0]; // [a,b,c,d]
              nn++;
              if (fc->collectnewtets) {
                // Pop two (flipped) tets from the stack.
                cavetetlist->objects -= 2;
              }
            } // if (unflip || (ori == 0))
          } // if (nn > 2)

          if (!fc->unflip) {
            // The flips are not reversed. The current Star(ab) can not be
            //   further reduced. Return its current size (# of tets).
            return nn;
          }
          // unflip is set.
          // Continue the search for flips.
        }
      } // if (reducflag)
    } // i

    // The Star(ab) is not reduced.
    if (reflexlinkedgecount > 0) {
      // There are reflex edges in the Link(ab).
      if (((b->fliplinklevel < 0) && (level < autofliplinklevel)) ||
          ((b->fliplinklevel >= 0) && (level < b->fliplinklevel))) {
        // Try to reduce the Star(ab) by flipping a reflex edge in Link(ab).
        for (i = 0; i < n; i++) {
          // Do not flip this face [a,b,c] if there are two Stars involved.
          if ((elemcounter(abtets[i]) > 1) ||
              (elemcounter(abtets[(i - 1 + n) % n]) > 1)) {
            continue;
          }
          pc = apex(abtets[i]);
          if (pc == dummypoint) {
            continue; // [a,b] is a hull edge.
          }
          pd = apex(abtets[(i + 1) % n]);
          pe = apex(abtets[(i - 1 + n) % n]);
          if ((pd == dummypoint) || (pe == dummypoint)) {
            continue; // [a,b,c] is a hull face.
          }


          edgepivot = 0; // No edge is selected yet.

          // Test if [b,c] is locally convex or flat.
          ori = orient3d(pb, pc, pd, pe);
          if (ori <= 0) {
            // Select the edge [c,b].
            enext(abtets[i], flipedge); // [b,c,a,d]
            edgepivot = 1;
          }
          if (!edgepivot) {
            // Test if [c,a] is locally convex or flat.
            ori = orient3d(pc, pa, pd, pe);
            if (ori <= 0) {
              // Select the edge [a,c].
              eprev(abtets[i], flipedge); // [c,a,b,d].
              edgepivot = 2;
            }
          }

          if (!edgepivot) continue;

          // An edge is selected.
          if (checksubsegflag) {
            // Do not flip it if it is a segment.
            if (issubseg(flipedge)) {
              if (fc->collectencsegflag) {
                face checkseg, *paryseg;
                tsspivot1(flipedge, checkseg);
                if (!sinfected(checkseg)) {
                  // Queue this segment in list.
                  sinfect(checkseg);
                  caveencseglist->newindex((void **) &paryseg);
                  *paryseg = checkseg;
                }
              }
              continue;
            }
          }

          // Try to flip the selected edge ([c,b] or [a,c]).
          esymself(flipedge);
          // Count the number of tets at the edge.
          n1 = 0;
          j = 0; // Sum of the star counters.
          spintet = flipedge;
          while (1) {
            n1++;
            j += (elemcounter(spintet));
            fnextself(spintet);
            if (spintet.tet == flipedge.tet) break;
          }
          assert(n1 >= 3);
          if (j > 2) {
            // The Star(flipedge) overlaps other Stars.
            continue; // Do not flip this edge.
          }
          // Only two tets can be marktested.
          assert(j == 2);

          if ((b->flipstarsize > 0) && (n1 > b->flipstarsize)) {
            // The star size exceeds the given limit.
            continue; // Do not flip it.
          }

          // Allocate spaces for Star(flipedge).
          tmpabtets = new triface[n1];
          // Form the Star(flipedge).
          j = 0;
          spintet = flipedge;
          while (1) {
            tmpabtets[j] = spintet;
            // Increase the star counter of this tet.
            increaseelemcounter(tmpabtets[j]);
            j++;
            fnextself(spintet);
            if (spintet.tet == flipedge.tet) break;
          }

          // Try to flip the selected edge away.
          nn = flipnm(tmpabtets, n1, level + 1, edgepivot, fc);

          if (nn == 2) {
            // The edge is flipped. Star(ab) is reduced.
            // Shrink the array 'abtets', maintain the original order.
            if (edgepivot == 1) {
              // 'tmpabtets[0]' is [d,a,e,b] => contains [a,b].
              spintet = tmpabtets[0]; // [d,a,e,b]
              enextself(spintet);
              esymself(spintet);
              enextself(spintet); // [a,b,e,d]
            } else {
              // 'tmpabtets[1]' is [b,d,e,a] => contains [a,b].
              spintet = tmpabtets[1]; // [b,d,e,a]
              eprevself(spintet);
              esymself(spintet);
              eprevself(spintet); // [a,b,e,d]
            } // edgepivot == 2
            assert(elemcounter(spintet) == 0); // It's a new tet.
            increaseelemcounter(spintet); // It is in Star(ab).
            // Put the new tet at [i-1]-th entry.
            abtets[(i - 1 + n) % n] = spintet;
            for (j = i; j < n - 1; j++) {
              abtets[j] = abtets[j + 1];  // Upshift
            }
            // Remember the flips in the last entry of the array 'abtets'.
            // They can be used to recover the flipped edge.
            abtets[n - 1].tet = (tetrahedron *) tmpabtets; // The star(fedge).
            abtets[n - 1].ver = 0; // Clear it.
            // Use the 1st and 2nd bit to save 'edgepivot' (1 or 2).
            abtets[n - 1].ver |= edgepivot;
            // Use the 6th bit to signal this n1-to-m1 flip.
            abtets[n - 1].ver |= (1 << 5);
            // The poisition [i] of this flip is saved from 7th to 19th bit.
            abtets[n - 1].ver |= (i << 6);
            // The size of the star 'n1' is saved from 20th bit.
            abtets[n - 1].ver |= (n1 << 19);

            // Remember the flipped link vertex 'c'. It can be used to recover
            //   the original edge link of [a,b], and to collect new tets.
            tmpabtets[0].tet = (tetrahedron *) pc;
            tmpabtets[0].ver = (1 << 5); // Flag it as a vertex handle.

            // Continue to flip the edge [a,b].
            nn = flipnm(abtets, n - 1, level, abedgepivot, fc);

            if (nn == 2) {
              // The edge has been flipped.
              return nn;
            } else { // if (nn > 2) {
              // The edge is not flipped.
              if (fc->unflip) {
                // Recover the flipped edge ([c,b] or [a,c]).
                assert(nn == (n - 1));
                // The sequence of flips are saved in 'tmpabtets'.
                // abtets[(i-1) % (n-1)] is [a,b,e,d], i.e., the tet created by
                //   the flipping of edge [c,b] or [a,c].It must still exist in
                //   Star(ab). It is the start tet to recover the flipped edge.
                if (edgepivot == 1) {
                  // The flip edge is [c,b].
                  tmpabtets[0] = abtets[((i-1)+(n-1))%(n-1)]; // [a,b,e,d]
                  eprevself(tmpabtets[0]);
                  esymself(tmpabtets[0]);
                  eprevself(tmpabtets[0]); // [d,a,e,b]
                  fsym(tmpabtets[0], tmpabtets[1]); // [a,d,e,c]
                } else {
                  // The flip edge is [a,c].
                  tmpabtets[1] = abtets[((i-1)+(n-1))%(n-1)]; // [a,b,e,d]
                  enextself(tmpabtets[1]);
                  esymself(tmpabtets[1]);
                  enextself(tmpabtets[1]); // [b,d,e,a]
                  fsym(tmpabtets[1], tmpabtets[0]); // [d,b,e,c]
                } // if (edgepivot == 2)

                // Recover the flipped edge ([c,b] or [a,c]).
                flipnm_post(tmpabtets, n1, 2, edgepivot, fc);

                // Insert the two recovered tets into Star(ab).
                for (j = n - 2; j >= i; j--) {
                  abtets[j + 1] = abtets[j];  // Downshift
                }
                if (edgepivot == 1) {
                  // tmpabtets[0] is [c,b,d,a] ==> contains [a,b]
                  // tmpabtets[1] is [c,b,a,e] ==> contains [a,b]
                  // tmpabtets[2] is [c,b,e,d]
                  fliptets[0] = tmpabtets[1];
                  enextself(fliptets[0]);
                  esymself(fliptets[0]); // [a,b,e,c]
                  fliptets[1] = tmpabtets[0];
                  esymself(fliptets[1]);
                  eprevself(fliptets[1]); // [a,b,c,d]
                } else {
                  // tmpabtets[0] is [a,c,d,b] ==> contains [a,b]
                  // tmpabtets[1] is [a,c,b,e] ==> contains [a,b]
                  // tmpabtets[2] is [a,c,e,d]
                  fliptets[0] = tmpabtets[1];
                  eprevself(fliptets[0]);
                  esymself(fliptets[0]); // [a,b,e,c]
                  fliptets[1] = tmpabtets[0];
                  esymself(fliptets[1]);
                  enextself(fliptets[1]); // [a,b,c,d]
                } // edgepivot == 2
                for (j = 0; j < 2; j++) {
                  increaseelemcounter(fliptets[j]);
                }
                // Insert the two recovered tets into Star(ab).
                abtets[(i - 1 + n) % n] = fliptets[0];
                abtets[i] = fliptets[1];
                nn++;
                // Release the allocated spaces.
                delete [] tmpabtets;
              } // if (unflip)
            } // if (nn > 2)

            if (!fc->unflip) {
              // The flips are not reversed. The current Star(ab) can not be
              //   further reduced. Return its size (# of tets).
              return nn;
            }
            // unflip is set.
            // Continue the search for flips.
          } else {
            // The selected edge is not flipped.
            if (fc->unflip) {
              // The memory should already be freed.
              assert(nn == n1);
            } else {
              // Release the memory used in this attempted flip.
              flipnm_post(tmpabtets, n1, nn, edgepivot, fc);
            }
            // Decrease the star counters of tets in Star(flipedge).
            for (j = 0; j < nn; j++) {
              assert(elemcounter(tmpabtets[j]) > 0); // SELF_CHECK
              decreaseelemcounter(tmpabtets[j]);
            }
            // Release the allocated spaces.
            delete [] tmpabtets;
          }
        } // i
      } // if (level...)
    } // if (reflexlinkedgecount > 0)
  } else {
    // Check if a 3-to-2 flip is possible.
    // Let the three apexes be c, d,and e. Hull tets may be involved. If so,
    //   we rearrange them such that the vertex e is dummypoint.
    hullflag = 0;

    if (apex(abtets[0]) == dummypoint) {
      pc = apex(abtets[1]);
      pd = apex(abtets[2]);
      pe = apex(abtets[0]);
      hullflag = 1;
    } else if (apex(abtets[1]) == dummypoint) {
      pc = apex(abtets[2]);
      pd = apex(abtets[0]);
      pe = apex(abtets[1]);
      hullflag = 2;
    } else {
      pc = apex(abtets[0]);
      pd = apex(abtets[1]);
      pe = apex(abtets[2]);
      hullflag = (pe == dummypoint) ? 3 : 0;
    }

    reducflag = 0;
    rejflag = 0;


    if (hullflag == 0) {
      // Make sure that no inverted tet will be created, i.e. the new tets
      //   [d,c,e,a] and [c,d,e,b] must be valid tets.
      ori = orient3d(pd, pc, pe, pa);
      if (ori < 0) {
        ori = orient3d(pc, pd, pe, pb);
        if (ori < 0) {
          reducflag = 1;
        }
      }
    } else {
      // [a,b] is a hull edge.
      //   Note: This can happen when it is in the middle of a 4-to-4 flip.
      //   Note: [a,b] may even be a non-convex hull edge.
      if (!nonconvex) {
        //  The mesh is convex, only do flip if it is a coplanar hull edge.
        ori = orient3d(pa, pb, pc, pd);
        if (ori == 0) {
          reducflag = 1;
        }
      } else { // nonconvex
        reducflag = 1;
      }
      if (reducflag == 1) {
        // [a,b], [a,b,c] and [a,b,d] are on the convex hull.
        // Make sure that no inverted tet will be created.
        point searchpt = NULL, chkpt;
        REAL bigvol = 0.0, ori1, ori2;
        // Search an interior vertex which is an apex of edge [c,d].
        //   In principle, it can be arbitrary interior vertex.  To avoid
        //   numerical issue, we choose the vertex which belongs to a tet
        //   't' at edge [c,d] and 't' has the biggest volume.
        fliptets[0] = abtets[hullflag % 3]; // [a,b,c,d].
        eorgoppoself(fliptets[0]);  // [d,c,b,a]
        spintet = fliptets[0];
        while (1) {
          fnextself(spintet);
          chkpt = oppo(spintet);
          if (chkpt == pb) break;
          if ((chkpt != dummypoint) && (apex(spintet) != dummypoint)) {
            ori = -orient3d(pd, pc, apex(spintet), chkpt);
            assert(ori > 0);
            if (ori > bigvol) {
              bigvol = ori;
              searchpt = chkpt;
            }
          }
        }
        if (searchpt != NULL) {
          // Now valid the configuration.
          ori1 = orient3d(pd, pc, searchpt, pa);
          ori2 = orient3d(pd, pc, searchpt, pb);
          if (ori1 * ori2 >= 0.0) {
            reducflag = 0; // Not valid.
          } else {
            ori1 = orient3d(pa, pb, searchpt, pc);
            ori2 = orient3d(pa, pb, searchpt, pd);
            if (ori1 * ori2 >= 0.0) {
              reducflag = 0; // Not valid.
            }
          }
        } else {
          // No valid searchpt is found.
          reducflag = 0; // Do not flip it.
        }
      } // if (reducflag == 1)
    } // if (hullflag == 1)

    if (reducflag) {
      // A 3-to-2 flip is possible.
      if (checksubfaceflag) {
        // This edge (must not be a segment) can be flipped ONLY IF it belongs
        //   to either 0 or 2 subfaces.  In the latter case, a 2-to-2 flip in
        //   the surface mesh will be automatically performed within the
        //   3-to-2 flip.
        nn = 0;
        edgepivot = -1; // Re-use it.
        for (j = 0; j < 3; j++) {
          if (issubface(abtets[j])) {
            nn++; // Found a subface.
          } else {
            edgepivot = j;
          }
        }
        assert(nn < 3);
        if (nn == 1) {
          // Found only 1 subface containing this edge. This can happen in
          //   the boundary recovery phase. The neighbor subface is not yet
          //   recovered. This edge should not be flipped at this moment.
          rejflag = 1;
        } else if (nn == 2) {
          // Found two subfaces. A 2-to-2 flip is possible. Validate it.
          // Below we check if the two faces [p,q,a] and [p,q,b] are subfaces.
          eorgoppo(abtets[(edgepivot + 1) % 3], spintet); // [q,p,b,a]
          if (issubface(spintet)) {
            rejflag = 1; // Conflict to a 2-to-2 flip.
          } else {
            esymself(spintet);
            if (issubface(spintet)) {
              rejflag = 1; // Conflict to a 2-to-2 flip.
            }
          }
        }
      }
      if (!rejflag && fc->checkflipeligibility) {
        // Here we must exchange 'a' and 'b'. Since in the check... function,
        //   we assume the following point sequence, 'a,b,c,d,e', where
        //   the face [a,b,c] will be flipped and the edge [e,d] will be
        //   created. The two new tets are [a,b,c,d] and [b,a,c,e].
        rejflag = checkflipeligibility(2, pc, pd, pe, pb, pa, level,
                                       abedgepivot, fc);
      }
      if (!rejflag) {
        // Do flip: [a,b] => [c,d,e]
        flip32(abtets, hullflag, fc);
        if (fc->remove_ndelaunay_edge) {
          if (level == 0) {
            // It is the desired removing edge. Check if we have improved
            //   the objective function.
            if ((fc->tetprism_vol_sum >= 0.0) ||
                (fabs(fc->tetprism_vol_sum) < fc->bak_tetprism_vol)) {
              // No improvement! flip back: [c,d,e] => [a,b].
              flip23(abtets, hullflag, fc);
              // Increase the element counter -- They are in cavity.
              for (j = 0; j < 3; j++) {
                increaseelemcounter(abtets[j]);
              }
              return 3;
            }
          } // if (level == 0)
        }
        if (fc->collectnewtets) {
          // Collect new tets.
          if (level == 0) {
            // Push the two new tets into stack.
            for (j = 0; j < 2; j++) {
              cavetetlist->newindex((void **) &parytet);
              *parytet = abtets[j];
            }
          } else {
            // Only one of the new tets is collected. The other one is inside
            //   the reduced edge star. 'abedgepivot' is either '1' or '2'.
            cavetetlist->newindex((void **) &parytet);
            if (abedgepivot == 1) { // [c,b]
              *parytet = abtets[1];
            } else {
              assert(abedgepivot == 2); // [a,c]
              *parytet = abtets[0];
            }
          }
        } // if (fc->collectnewtets)
        return 2;
      }
    } // if (reducflag)
  } // if (n == 3)

  // The current (reduced) Star size.
  return n;
}

int meshGRegionBoundaryRecovery::flipnm_post(triface* abtets, int n, int nn,
  int abedgepivot, flipconstraints* fc)
{
  triface fliptets[3], flipface;
  triface *tmpabtets;
  int fliptype;
  int edgepivot;
  int t, n1;
  int i, j;


  if (nn == 2) {
    // The edge [a,b] has been flipped.
    // 'abtets[0]' is [c,d,e,b] or [#,#,#,b].
    // 'abtets[1]' is [d,c,e,a] or [#,#,#,a].
    if (fc->unflip) {
      // Do a 2-to-3 flip to recover the edge [a,b]. There may be hull tets.
      flip23(abtets, 1, fc);
      if (fc->collectnewtets) {
        // Pop up new (flipped) tets from the stack.
        if (abedgepivot == 0) {
          // Two new tets were collected.
          cavetetlist->objects -= 2;
        } else {
          // Only one of the two new tets was collected.
          cavetetlist->objects -= 1;
        }
      }
    }
    // The initial size of Star(ab) is 3.
    nn++;
  }

  // Walk through the performed flips.
  for (i = nn; i < n; i++) {
    // At the beginning of each step 'i', the size of the Star([a,b]) is 'i'.
    // At the end of this step, the size of the Star([a,b]) is 'i+1'.
    // The sizes of the Link([a,b]) are the same.
    fliptype = ((abtets[i].ver >> 4) & 3); // 0, 1, or 2.
    if (fliptype == 1) {
      // It was a 2-to-3 flip: [a,b,c]->[e,d].
      t = (abtets[i].ver >> 6);
      assert(t <= i);
      if (fc->unflip) {
        if (b->verbose > 2) {
          printf("      Recover a 2-to-3 flip at f[%d].\n", t);
        }
        // 'abtets[(t-1)%i]' is the tet [a,b,e,d] in current Star(ab), i.e.,
        //   it is created by a 2-to-3 flip [a,b,c] => [e,d].
        fliptets[0] = abtets[((t - 1) + i) % i]; // [a,b,e,d]
        eprevself(fliptets[0]);
        esymself(fliptets[0]);
        enextself(fliptets[0]); // [e,d,a,b]
        fnext(fliptets[0], fliptets[1]); // [e,d,b,c]
        fnext(fliptets[1], fliptets[2]); // [e,d,c,a]
        // Do a 3-to-2 flip: [e,d] => [a,b,c].
        // NOTE: hull tets may be invloved.
        flip32(fliptets, 1, fc);
        // Expand the array 'abtets', maintain the original order.
        // The new array length is (i+1).
        for (j = i - 1; j >= t; j--) {
          abtets[j + 1] = abtets[j];  // Downshift
        }
        // The tet abtets[(t-1)%i] is deleted. Insert the two new tets
        //   'fliptets[0]' [a,b,c,d] and 'fliptets[1]' [b,a,c,e] into
        //   the (t-1)-th and t-th entries, respectively.
        esym(fliptets[1], abtets[((t-1) + (i+1)) % (i+1)]); // [a,b,e,c]
        abtets[t] = fliptets[0]; // [a,b,c,d]
        if (fc->collectnewtets) {
          // Pop up two (flipped) tets from the stack.
          cavetetlist->objects -= 2;
        }
      }
    } else if (fliptype == 2) {
      tmpabtets = (triface *) (abtets[i].tet);
      n1 = ((abtets[i].ver >> 19) & 8191); // \sum_{i=0^12}{2^i} = 8191
      edgepivot = (abtets[i].ver & 3);
      t = ((abtets[i].ver >> 6) & 8191);
      assert(t <= i);
      if (fc->unflip) {
        if (b->verbose > 2) {
          printf("      Recover a %d-to-m flip at e[%d] of f[%d].\n", n1,
                 edgepivot, t);
        }
        // Recover the flipped edge ([c,b] or [a,c]).
        // abtets[(t - 1 + i) % i] is [a,b,e,d], i.e., the tet created by
        //   the flipping of edge [c,b] or [a,c]. It must still exist in
        //   Star(ab). Use it to recover the flipped edge.
        if (edgepivot == 1) {
          // The flip edge is [c,b].
          tmpabtets[0] = abtets[(t - 1 + i) % i]; // [a,b,e,d]
          eprevself(tmpabtets[0]);
          esymself(tmpabtets[0]);
          eprevself(tmpabtets[0]); // [d,a,e,b]
          fsym(tmpabtets[0], tmpabtets[1]); // [a,d,e,c]
        } else {
          // The flip edge is [a,c].
          tmpabtets[1] = abtets[(t - 1 + i) % i]; // [a,b,e,d]
          enextself(tmpabtets[1]);
          esymself(tmpabtets[1]);
          enextself(tmpabtets[1]); // [b,d,e,a]
          fsym(tmpabtets[1], tmpabtets[0]); // [d,b,e,c]
        } // if (edgepivot == 2)

        // Do a n1-to-m1 flip to recover the flipped edge ([c,b] or [a,c]).
        flipnm_post(tmpabtets, n1, 2, edgepivot, fc);

        // Insert the two recovered tets into the original Star(ab).
        for (j = i - 1; j >= t; j--) {
          abtets[j + 1] = abtets[j];  // Downshift
        }
        if (edgepivot == 1) {
          // tmpabtets[0] is [c,b,d,a] ==> contains [a,b]
          // tmpabtets[1] is [c,b,a,e] ==> contains [a,b]
          // tmpabtets[2] is [c,b,e,d]
          fliptets[0] = tmpabtets[1];
          enextself(fliptets[0]);
          esymself(fliptets[0]); // [a,b,e,c]
          fliptets[1] = tmpabtets[0];
          esymself(fliptets[1]);
          eprevself(fliptets[1]); // [a,b,c,d]
        } else {
          // tmpabtets[0] is [a,c,d,b] ==> contains [a,b]
          // tmpabtets[1] is [a,c,b,e] ==> contains [a,b]
          // tmpabtets[2] is [a,c,e,d]
          fliptets[0] = tmpabtets[1];
          eprevself(fliptets[0]);
          esymself(fliptets[0]); // [a,b,e,c]
          fliptets[1] = tmpabtets[0];
          esymself(fliptets[1]);
          enextself(fliptets[1]); // [a,b,c,d]
        } // edgepivot == 2
        // Insert the two recovered tets into Star(ab).
        abtets[((t-1) + (i+1)) % (i+1)] = fliptets[0];
        abtets[t] = fliptets[1];
      }
      else {
        // Only free the spaces.
        flipnm_post(tmpabtets, n1, 2, edgepivot, fc);
      } // if (!unflip)
      if (b->verbose > 2) {
        printf("      Release %d spaces at f[%d].\n", n1, i);
      }
      delete [] tmpabtets;
    }
  } // i

  return 1;
}

int meshGRegionBoundaryRecovery::insertpoint(point insertpt,
  triface *searchtet, face *splitsh, face *splitseg, insertvertexflags *ivf)
{
  arraypool *swaplist;
  triface *cavetet, spintet, neightet, neineitet, *parytet;
  triface oldtet, newtet, newneitet;
  face checksh, neighsh, *parysh;
  face checkseg, *paryseg;
  point *pts, pa, pb, pc, *parypt;
  enum locateresult loc = OUTSIDE;
  REAL sign, ori;
  REAL attrib, volume;
  bool enqflag;
  int t1ver;
  int i, j, k, s;

  if (b->verbose > 2) {
    printf("      Insert point %d\n", pointmark(insertpt));
  }

  // Locate the point.
  if (searchtet->tet != NULL) {
    loc = (enum locateresult) ivf->iloc;
  }

  if (loc == OUTSIDE) {
    if (searchtet->tet == NULL) {
      if (!b->weighted) {
        randomsample(insertpt, searchtet);
      } else {
        // Weighted DT. There may exist dangling vertex.
        *searchtet = recenttet;
      }
    }
    // Locate the point.
    loc = locate(insertpt, searchtet);
  }

  ivf->iloc = (int) loc; // The return value.

  /*
  if (b->weighted) {
    if (loc != OUTSIDE) {
      // Check if this vertex is regular.
      pts = (point *) searchtet->tet;
      assert(pts[7] != dummypoint);
      sign = orient4d_s(pts[4], pts[5], pts[6], pts[7], insertpt,
                        pts[4][3], pts[5][3], pts[6][3], pts[7][3],
                        insertpt[3]);
      if (sign > 0) {
        // This new vertex does not lie below the lower hull. Skip it.
        setpointtype(insertpt, NREGULARVERTEX);
        nonregularcount++;
        ivf->iloc = (int) NONREGULAR;
        return 0;
      }
    }
  }
  */

  // Create the initial cavity C(p) which contains all tetrahedra that
  //   intersect p. It may include 1, 2, or n tetrahedra.
  // If p lies on a segment or subface, also create the initial sub-cavity
  //   sC(p) which contains all subfaces (and segment) which intersect p.

  if (loc == OUTSIDE) {
    flip14count++;
    // The current hull will be enlarged.
    // Add four adjacent boundary tets into list.
    for (i = 0; i < 4; i++) {
      decode(searchtet->tet[i], neightet);
      neightet.ver = epivot[neightet.ver];
      cavebdrylist->newindex((void **) &parytet);
      *parytet = neightet;
    }
    infect(*searchtet);
    caveoldtetlist->newindex((void **) &parytet);
    *parytet = *searchtet;
  } else if (loc == INTETRAHEDRON) {
    flip14count++;
    // Add four adjacent boundary tets into list.
    for (i = 0; i < 4; i++) {
      decode(searchtet->tet[i], neightet);
      neightet.ver = epivot[neightet.ver];
      cavebdrylist->newindex((void **) &parytet);
      *parytet = neightet;
    }
    infect(*searchtet);
    caveoldtetlist->newindex((void **) &parytet);
    *parytet = *searchtet;
  } else if (loc == ONFACE) {
    flip26count++;
    // Add six adjacent boundary tets into list.
    j = (searchtet->ver & 3); // The current face number.
    for (i = 1; i < 4; i++) {
      decode(searchtet->tet[(j + i) % 4], neightet);
      neightet.ver = epivot[neightet.ver];
      cavebdrylist->newindex((void **) &parytet);
      *parytet = neightet;
    }
    decode(searchtet->tet[j], spintet);
    j = (spintet.ver & 3); // The current face number.
    for (i = 1; i < 4; i++) {
      decode(spintet.tet[(j + i) % 4], neightet);
      neightet.ver = epivot[neightet.ver];
      cavebdrylist->newindex((void **) &parytet);
      *parytet = neightet;
    }
    infect(spintet);
    caveoldtetlist->newindex((void **) &parytet);
    *parytet = spintet;
    infect(*searchtet);
    caveoldtetlist->newindex((void **) &parytet);
    *parytet = *searchtet;

    if (ivf->splitbdflag) {
      if ((splitsh != NULL) && (splitsh->sh != NULL)) {
        // Create the initial sub-cavity sC(p).
        smarktest(*splitsh);
        caveshlist->newindex((void **) &parysh);
        *parysh = *splitsh;
      }
    } // if (splitbdflag)
  } else if (loc == ONEDGE) {
    flipn2ncount++;
    // Add all adjacent boundary tets into list.
    spintet = *searchtet;
    while (1) {
      eorgoppo(spintet, neightet);
      decode(neightet.tet[neightet.ver & 3], neightet);
      neightet.ver = epivot[neightet.ver];
      cavebdrylist->newindex((void **) &parytet);
      *parytet = neightet;
      edestoppo(spintet, neightet);
      decode(neightet.tet[neightet.ver & 3], neightet);
      neightet.ver = epivot[neightet.ver];
      cavebdrylist->newindex((void **) &parytet);
      *parytet = neightet;
      infect(spintet);
      caveoldtetlist->newindex((void **) &parytet);
      *parytet = spintet;
      fnextself(spintet);
      if (spintet.tet == searchtet->tet) break;
    } // while (1)

    if (ivf->splitbdflag) {
      // Create the initial sub-cavity sC(p).
      if ((splitseg != NULL) && (splitseg->sh != NULL)) {
        smarktest(*splitseg);
        splitseg->shver = 0;
        spivot(*splitseg, *splitsh);
      }
      if (splitsh != NULL) {
        if (splitsh->sh != NULL) {
          // Collect all subfaces share at this edge.
          pa = sorg(*splitsh);
          neighsh = *splitsh;
          while (1) {
            // Adjust the origin of its edge to be 'pa'.
            if (sorg(neighsh) != pa) {
              sesymself(neighsh);
            }
            // Add this face into list (in B-W cavity).
            smarktest(neighsh);
            caveshlist->newindex((void **) &parysh);
            *parysh = neighsh;
            // Add this face into face-at-splitedge list.
            cavesegshlist->newindex((void **) &parysh);
            *parysh = neighsh;
            // Go to the next face at the edge.
            spivotself(neighsh);
            // Stop if all faces at the edge have been visited.
            if (neighsh.sh == splitsh->sh) break;
            if (neighsh.sh == NULL) break;
          } // while (1)
        } // if (not a dangling segment)
      }
    } // if (splitbdflag)
  } else if (loc == INSTAR) {
    // We assume that all tets in the star are given in 'caveoldtetlist',
    //   and they are all infected.
    assert(caveoldtetlist->objects > 0);
    // Collect the boundary faces of the star.
    for (i = 0; i < caveoldtetlist->objects; i++) {
      cavetet = (triface *) fastlookup(caveoldtetlist, i);
      // Check its 4 neighbor tets.
      for (j = 0; j < 4; j++) {
        decode(cavetet->tet[j], neightet);
        if (!infected(neightet)) {
          // It's a boundary face.
          neightet.ver = epivot[neightet.ver];
          cavebdrylist->newindex((void **) &parytet);
          *parytet = neightet;
        }
      }
    }
  } else if (loc == ONVERTEX) {
    // The point already exist. Do nothing and return.
    return 0;
  }

  /*
  if (ivf->assignmeshsize) {
    // Assign mesh size for the new point.
    if (bgm != NULL) {
      // Interpolate the mesh size from the background mesh.
      bgm->decode(point2bgmtet(org(*searchtet)), neightet);
      int bgmloc = (int) bgm->scoutpoint(insertpt, &neightet, 0);
      if (bgmloc != (int) OUTSIDE) {
        insertpt[pointmtrindex] =
          bgm->getpointmeshsize(insertpt, &neightet, bgmloc);
        setpoint2bgmtet(insertpt, bgm->encode(neightet));
      }
    } else {
      insertpt[pointmtrindex] = getpointmeshsize(insertpt,searchtet,(int)loc);
    }
  } // if (assignmeshsize)
  */

  if (ivf->bowywat) {
    // Update the cavity C(p) using the Bowyer-Watson algorithm.
    swaplist = cavetetlist;
    cavetetlist = cavebdrylist;
    cavebdrylist = swaplist;
    for (i = 0; i < cavetetlist->objects; i++) {
      // 'cavetet' is an adjacent tet at outside of the cavity.
      cavetet = (triface *) fastlookup(cavetetlist, i);
      // The tet may be tested and included in the (enlarged) cavity.
      if (!infected(*cavetet)) {
        // Check for two possible cases for this tet:
        //   (1) It is a cavity tet, or
        //   (2) it is a cavity boundary face.
        enqflag = false;
        if (!marktested(*cavetet)) {
          // Do Delaunay (in-sphere) test.
          pts = (point *) cavetet->tet;
          if (pts[7] != dummypoint) {
            // A volume tet. Operate on it.
            if (b->weighted) {
              /*
              sign = orient4d_s(pts[4], pts[5], pts[6], pts[7], insertpt,
                                pts[4][3], pts[5][3], pts[6][3], pts[7][3],
                                insertpt[3]);
              */
            } else {
              sign = insphere_s(pts[4], pts[5], pts[6], pts[7], insertpt);
            }
            enqflag = (sign < 0.0);
          } else {
            if (!nonconvex) {
              // Test if this hull face is visible by the new point.
              ori = orient3d(pts[4], pts[5], pts[6], insertpt);
              if (ori < 0) {
                // A visible hull face.
                //if (!nonconvex) {
                // Include it in the cavity. The convex hull will be enlarged.
                enqflag = true; // (ori < 0.0);
		        //}
              } else if (ori == 0.0) {
                // A coplanar hull face. We need to test if this hull face is
                //   Delaunay or not. We test if the adjacent tet (not faked)
                //   of this hull face is Delaunay or not.
                decode(cavetet->tet[3], neineitet);
                if (!infected(neineitet)) {
                  if (!marktested(neineitet)) {
                    // Do Delaunay test on this tet.
                    pts = (point *) neineitet.tet;
                    assert(pts[7] != dummypoint);
                    if (b->weighted) {
                      /*
                      sign = orient4d_s(pts[4],pts[5],pts[6],pts[7], insertpt,
                                        pts[4][3], pts[5][3], pts[6][3],
                                        pts[7][3], insertpt[3]);
                      */
                    } else {
                      sign = insphere_s(pts[4],pts[5],pts[6],pts[7], insertpt);
                    }
                    enqflag = (sign < 0.0);
                  }
                } else {
                  // The adjacent tet is non-Delaunay. The hull face is non-
                  //   Delaunay as well. Include it in the cavity.
                  enqflag = true;
                } // if (!infected(neineitet))
              } // if (ori == 0.0)
            } else {
              // A hull face (must be a subface).
              // We FIRST include it in the initial cavity if the adjacent tet
              //   (not faked) of this hull face is not Delaunay wrt p.
              //   Whether it belongs to the final cavity will be determined
              //   during the validation process. 'validflag'.
              decode(cavetet->tet[3], neineitet);
              if (!infected(neineitet)) {
                if (!marktested(neineitet)) {
                  // Do Delaunay test on this tet.
                  pts = (point *) neineitet.tet;
                  assert(pts[7] != dummypoint);
                  if (b->weighted) {
                    /*
                    sign = orient4d_s(pts[4],pts[5],pts[6],pts[7], insertpt,
                                      pts[4][3], pts[5][3], pts[6][3],
                                      pts[7][3], insertpt[3]);
                    */
                  } else {
                    sign = insphere_s(pts[4],pts[5],pts[6],pts[7], insertpt);
                  }
                  enqflag = (sign < 0.0);
                }
              } else {
                // The adjacent tet is non-Delaunay. The hull face is non-
                //   Delaunay as well. Include it in the cavity.
                enqflag = true;
              } // if (infected(neineitet))
            } // if (nonconvex)
          } // if (pts[7] != dummypoint)
          marktest(*cavetet); // Only test it once.
        } // if (!marktested(*cavetet))

        if (enqflag) {
          // Found a tet in the cavity. Put other three faces in check list.
          k = (cavetet->ver & 3); // The current face number
          for (j = 1; j < 4; j++) {
            decode(cavetet->tet[(j + k) % 4], neightet);
            cavetetlist->newindex((void **) &parytet);
            *parytet = neightet;
          }
          infect(*cavetet);
          caveoldtetlist->newindex((void **) &parytet);
          *parytet = *cavetet;
        } else {
          // Found a boundary face of the cavity.
          cavetet->ver = epivot[cavetet->ver];
          cavebdrylist->newindex((void **) &parytet);
          *parytet = *cavetet;
        }
      } // if (!infected(*cavetet))
    } // i

    cavetetlist->restart(); // Clear the working list.
  } // if (ivf->bowywat)

  if (checksubsegflag) {
    // Collect all segments of C(p).
    shellface *ssptr;
    for (i = 0; i < caveoldtetlist->objects; i++) {
      cavetet = (triface *) fastlookup(caveoldtetlist, i);
      if ((ssptr = (shellface*) cavetet->tet[8]) != NULL) {
        for (j = 0; j < 6; j++) {
          if (ssptr[j]) {
            sdecode(ssptr[j], checkseg);
            if (!sinfected(checkseg)) {
              sinfect(checkseg);
              cavetetseglist->newindex((void **) &paryseg);
              *paryseg = checkseg;
            }
          }
        } // j
      }
    } // i
    // Uninfect collected segments.
    for (i = 0; i < cavetetseglist->objects; i++) {
      paryseg = (face *) fastlookup(cavetetseglist, i);
      suninfect(*paryseg);
    }

    /*
    if (ivf->rejflag & 1) {
      // Reject this point if it encroaches upon any segment.
      face *paryseg1;
      for (i = 0; i < cavetetseglist->objects; i++) {
        paryseg1 = (face *) fastlookup(cavetetseglist, i);
        if (checkseg4encroach((point) paryseg1->sh[3], (point) paryseg1->sh[4],
                              insertpt)) {
          encseglist->newindex((void **) &paryseg);
          *paryseg = *paryseg1;
        }
      } // i
      if (encseglist->objects > 0) {
        insertpoint_abort(splitseg, ivf);
        ivf->iloc = (int) ENCSEGMENT;
        return 0;
      }
    }
    */
  } // if (checksubsegflag)

  if (checksubfaceflag) {
    // Collect all subfaces of C(p).
    shellface *sptr;
    for (i = 0; i < caveoldtetlist->objects; i++) {
      cavetet = (triface *) fastlookup(caveoldtetlist, i);
      if ((sptr = (shellface*) cavetet->tet[9]) != NULL) {
        for (j = 0; j < 4; j++) {
          if (sptr[j]) {
            sdecode(sptr[j], checksh);
            if (!sinfected(checksh)) {
              sinfect(checksh);
              cavetetshlist->newindex((void **) &parysh);
              *parysh = checksh;
            }
          }
        } // j
      }
    } // i
    // Uninfect collected subfaces.
    for (i = 0; i < cavetetshlist->objects; i++) {
      parysh = (face *) fastlookup(cavetetshlist, i);
      suninfect(*parysh);
    }

    /*
    if (ivf->rejflag & 2) {
      REAL rd, cent[3];
      badface *bface;
      // Reject this point if it encroaches upon any subface.
      for (i = 0; i < cavetetshlist->objects; i++) {
        parysh = (face *) fastlookup(cavetetshlist, i);
        if (checkfac4encroach((point) parysh->sh[3], (point) parysh->sh[4],
                              (point) parysh->sh[5], insertpt, cent, &rd)) {
          encshlist->newindex((void **) &bface);
          bface->ss = *parysh;
          bface->forg = (point) parysh->sh[3]; // Not a dad one.
          for (j = 0; j < 3; j++) bface->cent[j] = cent[j];
          bface->key = rd;
        }
      }
      if (encshlist->objects > 0) {
        insertpoint_abort(splitseg, ivf);
        ivf->iloc = (int) ENCSUBFACE;
        return 0;
      }
    }
    */
  } // if (checksubfaceflag)

  if ((ivf->iloc == (int) OUTSIDE) && ivf->refineflag) {
    // The vertex lies outside of the domain. And it does not encroach
    //   upon any boundary segment or subface. Do not insert it.
    insertpoint_abort(splitseg, ivf);
    return 0;
  }

  if (ivf->splitbdflag) {
    // The new point locates in surface mesh. Update the sC(p).
    // We have already 'smarktested' the subfaces which directly intersect
    //   with p in 'caveshlist'. From them, we 'smarktest' their neighboring
    //   subfaces which are included in C(p). Do not across a segment.
    for (i = 0; i < caveshlist->objects; i++) {
      parysh = (face *) fastlookup(caveshlist, i);
      assert(smarktested(*parysh));
      checksh = *parysh;
      for (j = 0; j < 3; j++) {
        if (!isshsubseg(checksh)) {
          spivot(checksh, neighsh);
          assert(neighsh.sh != NULL);
          if (!smarktested(neighsh)) {
            stpivot(neighsh, neightet);
            if (infected(neightet)) {
              fsymself(neightet);
              if (infected(neightet)) {
                // This subface is inside C(p).
                // Check if its diametrical circumsphere encloses 'p'.
                //   The purpose of this check is to avoid forming invalid
                //   subcavity in surface mesh.
                sign = incircle3d(sorg(neighsh), sdest(neighsh),
                                  sapex(neighsh), insertpt);
                if (sign < 0) {
                  smarktest(neighsh);
                  caveshlist->newindex((void **) &parysh);
                  *parysh = neighsh;
                }
              }
            }
          }
        }
        senextself(checksh);
      } // j
    } // i
  } // if (ivf->splitbdflag)

  if (ivf->validflag) {
    // Validate C(p) and update it if it is not star-shaped.
    int cutcount = 0;

    if (ivf->respectbdflag) {
      // The initial cavity may include subfaces which are not on the facets
      //   being splitting. Find them and make them as boundary of C(p).
      // Comment: We have already 'smarktested' the subfaces in sC(p). They
      //   are completely inside C(p).
      for (i = 0; i < cavetetshlist->objects; i++) {
        parysh = (face *) fastlookup(cavetetshlist, i);
        stpivot(*parysh, neightet);
        if (infected(neightet)) {
          fsymself(neightet);
          if (infected(neightet)) {
            // Found a subface inside C(p).
            if (!smarktested(*parysh)) {
              // It is possible that this face is a boundary subface.
              // Check if it is a hull face.
              //assert(apex(neightet) != dummypoint);
              if (oppo(neightet) != dummypoint) {
                fsymself(neightet);
              }
              if (oppo(neightet) != dummypoint) {
                ori = orient3d(org(neightet), dest(neightet), apex(neightet),
                               insertpt);
                if (ori < 0) {
                  // A visible face, get its neighbor face.
                  fsymself(neightet);
                  ori = -ori; // It must be invisible by p.
                }
              } else {
                // A hull tet. It needs to be cut.
                ori = 1;
              }
              // Cut this tet if it is either invisible by or coplanar with p.
              if (ori >= 0) {
                uninfect(neightet);
                unmarktest(neightet);
                cutcount++;
                neightet.ver = epivot[neightet.ver];
                cavebdrylist->newindex((void **) &parytet);
                *parytet = neightet;
                // Add three new faces to find new boundaries.
                for (j = 0; j < 3; j++) {
                  esym(neightet, neineitet);
                  neineitet.ver = epivot[neineitet.ver];
                  cavebdrylist->newindex((void **) &parytet);
                  *parytet = neineitet;
                  enextself(neightet);
                }
              } // if (ori >= 0)
            }
          }
        }
      } // i

      // The initial cavity may include segments in its interior. We need to
      //   Update the cavity so that these segments are on the boundary of
      //   the cavity.
      for (i = 0; i < cavetetseglist->objects; i++) {
        paryseg = (face *) fastlookup(cavetetseglist, i);
        // Check this segment if it is not a splitting segment.
        if (!smarktested(*paryseg)) {
          sstpivot1(*paryseg, neightet);
          spintet = neightet;
          while (1) {
            if (!infected(spintet)) break;
            fnextself(spintet);
            if (spintet.tet == neightet.tet) break;
          }
          if (infected(spintet)) {
            // Find an adjacent tet at this segment such that both faces
            //   at this segment are not visible by p.
            pa = org(neightet);
            pb = dest(neightet);
            spintet = neightet;
            j = 0;
            while (1) {
              // Check if this face is visible by p.
              pc = apex(spintet);
              if (pc != dummypoint) {
                ori = orient3d(pa, pb, pc, insertpt);
                if (ori >= 0) {
                  // Not visible. Check another face in this tet.
                  esym(spintet, neineitet);
                  pc = apex(neineitet);
                  if (pc != dummypoint) {
                    ori = orient3d(pb, pa, pc, insertpt);
                    if (ori >= 0) {
                      // Not visible. Found this face.
                      j = 1; // Flag that it is found.
                      break;
                    }
                  }
                }
              }
              fnextself(spintet);
              if (spintet.tet == neightet.tet) break;
            }
            if (j == 0) {
              // Not found such a face.
              assert(0); // debug this case.
            }
            neightet = spintet;
            if (b->verbose > 3) {
               printf("        Cut tet (%d, %d, %d, %d)\n",
                      pointmark(org(neightet)), pointmark(dest(neightet)),
                      pointmark(apex(neightet)), pointmark(oppo(neightet)));
            }
            uninfect(neightet);
            unmarktest(neightet);
            cutcount++;
            neightet.ver = epivot[neightet.ver];
            cavebdrylist->newindex((void **) &parytet);
            *parytet = neightet;
            // Add three new faces to find new boundaries.
            for (j = 0; j < 3; j++) {
              esym(neightet, neineitet);
              neineitet.ver = epivot[neineitet.ver];
              cavebdrylist->newindex((void **) &parytet);
              *parytet = neineitet;
              enextself(neightet);
            }
          }
        }
      } // i
    } // if (ivf->respectbdflag)

    // Update the cavity by removing invisible faces until it is star-shaped.
    for (i = 0; i < cavebdrylist->objects; i++) {
      cavetet = (triface *) fastlookup(cavebdrylist, i);
      // 'cavetet' is an exterior tet adjacent to the cavity.
      // Check if its neighbor is inside C(p).
      fsym(*cavetet, neightet);
      if (infected(neightet)) {
        if (apex(*cavetet) != dummypoint) {
          // It is a cavity boundary face. Check its visibility.
          if (oppo(neightet) != dummypoint) {
            ori = orient3d(org(*cavetet), dest(*cavetet), apex(*cavetet),
                           insertpt);
            enqflag = (ori > 0);
            // Comment: if ori == 0 (coplanar case), we also cut the tet.
          } else {
            // It is a hull face. And its adjacent tet (at inside of the
            //   domain) has been cut from the cavity. Cut it as well.
            //assert(nonconvex);
            enqflag = false;
          }
        } else {
          enqflag = true; // A hull edge.
        }
        if (enqflag) {
          // This face is valid, save it.
          cavetetlist->newindex((void **) &parytet);
          *parytet = *cavetet;
        } else {
          uninfect(neightet);
          unmarktest(neightet);
          cutcount++;
          // Add three new faces to find new boundaries.
          for (j = 0; j < 3; j++) {
            esym(neightet, neineitet);
            neineitet.ver = epivot[neineitet.ver];
            cavebdrylist->newindex((void **) &parytet);
            *parytet = neineitet;
            enextself(neightet);
          }
          // 'cavetet' is not on the cavity boundary anymore.
          unmarktest(*cavetet);
        }
      } else {
        // 'cavetet' is not on the cavity boundary anymore.
        unmarktest(*cavetet);
      }
    } // i

    if (cutcount > 0) {
      // The cavity has been updated.
      // Update the cavity boundary faces.
      cavebdrylist->restart();
      for (i = 0; i < cavetetlist->objects; i++) {
        cavetet = (triface *) fastlookup(cavetetlist, i);
        // 'cavetet' was an exterior tet adjacent to the cavity.
        fsym(*cavetet, neightet);
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
      // Swap 'cavetetlist' and 'caveoldtetlist'.
      swaplist = caveoldtetlist;
      caveoldtetlist = cavetetlist;
      cavetetlist = swaplist;

      // The cavity should contain at least one tet.
      if (caveoldtetlist->objects == 0l) {
        insertpoint_abort(splitseg, ivf);
        ivf->iloc = (int) BADELEMENT;
        return 0;
      }

      if (ivf->splitbdflag) {
        int cutshcount = 0;
        // Update the sub-cavity sC(p).
        for (i = 0; i < caveshlist->objects; i++) {
          parysh = (face *) fastlookup(caveshlist, i);
          if (smarktested(*parysh)) {
            enqflag = false;
            stpivot(*parysh, neightet);
            if (infected(neightet)) {
              fsymself(neightet);
              if (infected(neightet)) {
                enqflag = true;
              }
            }
            if (!enqflag) {
              sunmarktest(*parysh);
              // Use the last entry of this array to fill this entry.
              j = caveshlist->objects - 1;
              checksh = * (face *) fastlookup(caveshlist, j);
              *parysh = checksh;
              cutshcount++;
              caveshlist->objects--; // The list is shrinked.
              i--;
            }
          }
        }

        if (cutshcount > 0) {
          i = 0; // Count the number of invalid subfaces/segments.
          // Valid the updated sub-cavity sC(p).
          if (loc == ONFACE) {
            if ((splitsh != NULL) && (splitsh->sh != NULL)) {
              // The to-be split subface should be in sC(p).
              if (!smarktested(*splitsh)) i++;
            }
          } else if (loc == ONEDGE) {
            if ((splitseg != NULL) && (splitseg->sh != NULL)) {
              // The to-be split segment should be in sC(p).
              if (!smarktested(*splitseg)) i++;
            }
            if ((splitsh != NULL) && (splitsh->sh != NULL)) {
              // All subfaces at this edge should be in sC(p).
              pa = sorg(*splitsh);
              neighsh = *splitsh;
              while (1) {
                // Adjust the origin of its edge to be 'pa'.
                if (sorg(neighsh) != pa) {
                  sesymself(neighsh);
                }
                // Add this face into list (in B-W cavity).
                if (!smarktested(neighsh)) i++;
                // Go to the next face at the edge.
                spivotself(neighsh);
                // Stop if all faces at the edge have been visited.
                if (neighsh.sh == splitsh->sh) break;
                if (neighsh.sh == NULL) break;
              } // while (1)
            }
          }

          if (i > 0) {
            // The updated sC(p) is invalid. Do not insert this vertex.
            insertpoint_abort(splitseg, ivf);
            ivf->iloc = (int) BADELEMENT;
            return 0;
          }
        } // if (cutshcount > 0)
      } // if (ivf->splitbdflag)
    } // if (cutcount > 0)

  } // if (ivf->validflag)

  if (ivf->refineflag) {
    // The new point is inserted by Delaunay refinement, i.e., it is the
    //   circumcenter of a tetrahedron, or a subface, or a segment.
    //   Do not insert this point if the tetrahedron, or subface, or segment
    //   is not inside the final cavity.
    if (((ivf->refineflag == 1) && !infected(ivf->refinetet)) ||
        ((ivf->refineflag == 2) && !smarktested(ivf->refinesh))) {
      insertpoint_abort(splitseg, ivf);
      ivf->iloc = (int) BADELEMENT;
      return 0;
    }
  } // if (ivf->refineflag)

  if (b->plc && (loc != INSTAR)) {
    // Reject the new point if it lies too close to an existing point (b->plc),
    // or it lies inside a protecting ball of near vertex (ivf->rejflag & 4).
    // Collect the list of vertices of the initial cavity.
    if (loc == OUTSIDE) {
      pts = (point *) &(searchtet->tet[4]);
      for (i = 0; i < 3; i++) {
        cavetetvertlist->newindex((void **) &parypt);
        *parypt = pts[i];
      }
    } else if (loc == INTETRAHEDRON) {
      pts = (point *) &(searchtet->tet[4]);
      for (i = 0; i < 4; i++) {
        cavetetvertlist->newindex((void **) &parypt);
        *parypt = pts[i];
      }
    } else if (loc == ONFACE) {
      pts = (point *) &(searchtet->tet[4]);
      for (i = 0; i < 3; i++) {
        cavetetvertlist->newindex((void **) &parypt);
        *parypt = pts[i];
      }
      if (pts[3] != dummypoint) {
        cavetetvertlist->newindex((void **) &parypt);
        *parypt = pts[3];
      }
      fsym(*searchtet, spintet);
      if (oppo(spintet) != dummypoint) {
        cavetetvertlist->newindex((void **) &parypt);
        *parypt = oppo(spintet);
      }
    } else if (loc == ONEDGE) {
      spintet = *searchtet;
      cavetetvertlist->newindex((void **) &parypt);
      *parypt = org(spintet);
      cavetetvertlist->newindex((void **) &parypt);
      *parypt = dest(spintet);
      while (1) {
        if (apex(spintet) != dummypoint) {
          cavetetvertlist->newindex((void **) &parypt);
          *parypt = apex(spintet);
        }
        fnextself(spintet);
        if (spintet.tet == searchtet->tet) break;
      }
    }

    int rejptflag = (ivf->rejflag & 4);
    REAL rd;
    pts = NULL;

    for (i = 0; i < cavetetvertlist->objects; i++) {
      parypt = (point *) fastlookup(cavetetvertlist, i);
      rd = distance(*parypt, insertpt);
      // Is the point very close to an existing point?
      if (rd < b->minedgelength) {
        pts = parypt;
        loc = NEARVERTEX;
        break;
      }
      if (rejptflag) {
        // Is the point encroaches upon an existing point?
        if (rd < (0.5 * (*parypt)[pointmtrindex])) {
          pts = parypt;
          loc = ENCVERTEX;
          break;
        }
      }
    }
    cavetetvertlist->restart(); // Clear the work list.

    if (pts != NULL) {
      // The point is either too close to an existing vertex (NEARVERTEX)
      //   or encroaches upon (inside the protecting ball) of that vertex.
      if (loc == NEARVERTEX) {
        if (b->nomergevertex) { // -M0/1 option.
          // In this case, we still insert this vertex. Although it is very
          //   close to an existing vertex. Give a warning, anyway.
          if (!b->quiet) {
            printf("Warning:  Two points, %d and %d, are very close.\n",
                   pointmark(insertpt), pointmark(*pts));
            printf("  Creating a very short edge (len = %g) (< %g).\n",
                   rd, b->minedgelength);
            printf("  You may try a smaller tolerance (-T) (current is %g)\n",
                   b->epsilon);
            printf("  to avoid this warning.\n");
          }
        } else {
          insertpt[3] = rd; // Only for reporting.
          setpoint2ppt(insertpt, *pts);
          insertpoint_abort(splitseg, ivf);
          ivf->iloc = (int) loc;
          return 0;
        }
      } else { // loc == ENCVERTEX
        // The point lies inside the protection ball.
        setpoint2ppt(insertpt, *pts);
        insertpoint_abort(splitseg, ivf);
        ivf->iloc = (int) loc;
        return 0;
      }
    }
  } // if (b->plc && (loc != INSTAR))

  if (b->weighted || ivf->cdtflag || ivf->smlenflag
      ) {
    // There may be other vertices inside C(p). We need to find them.
    // Collect all vertices of C(p).
    for (i = 0; i < caveoldtetlist->objects; i++) {
      cavetet = (triface *) fastlookup(caveoldtetlist, i);
      //assert(infected(*cavetet));
      pts = (point *) &(cavetet->tet[4]);
      for (j = 0; j < 4; j++) {
        if (pts[j] != dummypoint) {
          if (!pinfected(pts[j])) {
            pinfect(pts[j]);
            cavetetvertlist->newindex((void **) &parypt);
            *parypt = pts[j];
          }
        }
      } // j
    } // i
    // Uninfect all collected (cavity) vertices.
    for (i = 0; i < cavetetvertlist->objects; i++) {
      parypt = (point *) fastlookup(cavetetvertlist, i);
      puninfect(*parypt);
    }
    if (ivf->smlenflag) {
      REAL len;
      // Get the length of the shortest edge connecting to 'newpt'.
      parypt = (point *) fastlookup(cavetetvertlist, 0);
      ivf->smlen = distance(*parypt, insertpt);
      ivf->parentpt = *parypt;
      for (i = 1; i < cavetetvertlist->objects; i++) {
        parypt = (point *) fastlookup(cavetetvertlist, i);
        len = distance(*parypt, insertpt);
        if (len < ivf->smlen) {
          ivf->smlen = len;
          ivf->parentpt = *parypt;
        }
      }
    }
  }


  if (ivf->cdtflag) {
    // Unmark tets.
    for (i = 0; i < caveoldtetlist->objects; i++) {
      cavetet = (triface *) fastlookup(caveoldtetlist, i);
      unmarktest(*cavetet);
    }
    for (i = 0; i < cavebdrylist->objects; i++) {
      cavetet = (triface *) fastlookup(cavebdrylist, i);
      unmarktest(*cavetet);
    }
    // Clean up arrays which are not needed.
    cavetetlist->restart();
    if (checksubsegflag) {
      cavetetseglist->restart();
    }
    if (checksubfaceflag) {
      cavetetshlist->restart();
    }
    return 1;
  }

  // Before re-mesh C(p). Process the segments and subfaces which are on the
  //   boundary of C(p). Make sure that each such segment or subface is
  //   connecting to a tet outside C(p). So we can re-connect them to the
  //   new tets inside the C(p) later.

  if (checksubsegflag) {
    for (i = 0; i < cavetetseglist->objects; i++) {
      paryseg = (face *) fastlookup(cavetetseglist, i);
      // Operate on it if it is not the splitting segment, i.e., in sC(p).
      if (!smarktested(*paryseg)) {
        // Check if the segment is inside the cavity.
        //   'j' counts the num of adjacent tets of this seg.
        //   'k' counts the num of adjacent tets which are 'sinfected'.
        j = k = 0;
        sstpivot1(*paryseg, neightet);
        spintet = neightet;
        while (1) {
          j++;
          if (!infected(spintet)) {
            neineitet = spintet; // An outer tet. Remember it.
          } else {
            k++; // An in tet.
          }
          fnextself(spintet);
          if (spintet.tet == neightet.tet) break;
        }
        // assert(j > 0);
        if (k == 0) {
          // The segment is not connect to C(p) anymore. Remove it by
          //   Replacing it by the last entry of this list.
          s = cavetetseglist->objects - 1;
          checkseg = * (face *) fastlookup(cavetetseglist, s);
          *paryseg = checkseg;
          cavetetseglist->objects--;
          i--;
        } else if (k < j) {
          // The segment is on the boundary of C(p).
          sstbond1(*paryseg, neineitet);
        } else { // k == j
          // The segment is inside C(p).
          if (!ivf->splitbdflag) {
            checkseg = *paryseg;
            sinfect(checkseg); // Flag it as an interior segment.
            caveencseglist->newindex((void **) &paryseg);
            *paryseg = checkseg;
          } else {
            assert(0); // Not possible.
          }
        }
      } else {
        // assert(smarktested(*paryseg));
        // Flag it as an interior segment. Do not queue it, since it will
        //   be deleted after the segment splitting.
        sinfect(*paryseg);
      }
    } // i
  } // if (checksubsegflag)

  if (checksubfaceflag) {
    for (i = 0; i < cavetetshlist->objects; i++) {
      parysh = (face *) fastlookup(cavetetshlist, i);
      // Operate on it if it is not inside the sub-cavity sC(p).
      if (!smarktested(*parysh)) {
        // Check if this subface is inside the cavity.
        k = 0;
        for (j = 0; j < 2; j++) {
          stpivot(*parysh, neightet);
          if (!infected(neightet)) {
            checksh = *parysh; // Remember this side.
          } else {
            k++;
          }
          sesymself(*parysh);
        }
        if (k == 0) {
          // The subface is not connected to C(p). Remove it.
          s = cavetetshlist->objects - 1;
          checksh = * (face *) fastlookup(cavetetshlist, s);
          *parysh = checksh;
          cavetetshlist->objects--;
          i--;
        } else if (k == 1) {
          // This side is the outer boundary of C(p).
          *parysh = checksh;
        } else { // k == 2
          if (!ivf->splitbdflag) {
            checksh = *parysh;
            sinfect(checksh); // Flag it.
            caveencshlist->newindex((void **) &parysh);
            *parysh = checksh;
          } else {
            assert(0); // Not possible.
          }
        }
      } else {
        // assert(smarktested(*parysh));
        // Flag it as an interior subface. Do not queue it. It will be
        //   deleted after the facet point insertion.
        sinfect(*parysh);
      }
    } // i
  } // if (checksubfaceflag)

  // Create new tetrahedra to fill the cavity.

  for (i = 0; i < cavebdrylist->objects; i++) {
    cavetet = (triface *) fastlookup(cavebdrylist, i);
    neightet = *cavetet;
    unmarktest(neightet); // Unmark it.
    // Get the oldtet (inside the cavity).
    fsym(neightet, oldtet);
    if (apex(neightet) != dummypoint) {
      // Create a new tet in the cavity.
      maketetrahedron(&newtet);
      setorg(newtet, dest(neightet));
      setdest(newtet, org(neightet));
      setapex(newtet, apex(neightet));
      setoppo(newtet, insertpt);
    } else {
      // Create a new hull tet.
      hullsize++;
      maketetrahedron(&newtet);
      setorg(newtet, org(neightet));
      setdest(newtet, dest(neightet));
      setapex(newtet, insertpt);
      setoppo(newtet, dummypoint); // It must opposite to face 3.
      // Adjust back to the cavity bounday face.
      esymself(newtet);
    }
    // The new tet inherits attribtes from the old tet.
    for (j = 0; j < numelemattrib; j++) {
      attrib = elemattribute(oldtet.tet, j);
      setelemattribute(newtet.tet, j, attrib);
    }
    if (b->varvolume) {
      volume = volumebound(oldtet.tet);
      setvolumebound(newtet.tet, volume);
    }
    // Connect newtet <==> neightet, this also disconnect the old bond.
    bond(newtet, neightet);
    // oldtet still connects to neightet.
    *cavetet = oldtet; // *cavetet = newtet;
  } // i

  // Set a handle for speeding point location.
  recenttet = newtet;
  //setpoint2tet(insertpt, encode(newtet));
  setpoint2tet(insertpt, (tetrahedron) (newtet.tet));

  // Re-use this list to save new interior cavity faces.
  cavetetlist->restart();

  // Connect adjacent new tetrahedra together.
  for (i = 0; i < cavebdrylist->objects; i++) {
    cavetet = (triface *) fastlookup(cavebdrylist, i);
    // cavtet is an oldtet, get the newtet at this face.
    oldtet = *cavetet;
    fsym(oldtet, neightet);
    fsym(neightet, newtet);
    // Comment: oldtet and newtet must be at the same directed edge.
    // Connect the three other faces of this newtet.
    for (j = 0; j < 3; j++) {
      esym(newtet, neightet); // Go to the face.
      if (neightet.tet[neightet.ver & 3] == NULL) {
        // Find the adjacent face of this newtet.
        spintet = oldtet;
        while (1) {
          fnextself(spintet);
          if (!infected(spintet)) break;
        }
        fsym(spintet, newneitet);
        esymself(newneitet);
        assert(newneitet.tet[newneitet.ver & 3] == NULL);
        bond(neightet, newneitet);
        if (ivf->lawson > 1) {
          cavetetlist->newindex((void **) &parytet);
          *parytet = neightet;
        }
      }
      //setpoint2tet(org(newtet), encode(newtet));
      setpoint2tet(org(newtet), (tetrahedron) (newtet.tet));
      enextself(newtet);
      enextself(oldtet);
    }
    *cavetet = newtet; // Save the new tet.
  } // i

  if (checksubfaceflag) {
    // Connect subfaces on the boundary of the cavity to the new tets.
    for (i = 0; i < cavetetshlist->objects; i++) {
      parysh = (face *) fastlookup(cavetetshlist, i);
      // Connect it if it is not a missing subface.
      if (!sinfected(*parysh)) {
        stpivot(*parysh, neightet);
        fsym(neightet, spintet);
        sesymself(*parysh);
        tsbond(spintet, *parysh);
      }
    }
  }

  if (checksubsegflag) {
    // Connect segments on the boundary of the cavity to the new tets.
    for (i = 0; i < cavetetseglist->objects; i++) {
      paryseg = (face *) fastlookup(cavetetseglist, i);
      // Connect it if it is not a missing segment.
      if (!sinfected(*paryseg)) {
        sstpivot1(*paryseg, neightet);
        spintet = neightet;
        while (1) {
          tssbond1(spintet, *paryseg);
          fnextself(spintet);
          if (spintet.tet == neightet.tet) break;
        }
      }
    }
  }

  if (((splitsh != NULL) && (splitsh->sh != NULL)) ||
      ((splitseg != NULL) && (splitseg->sh != NULL))) {
    // Split a subface or a segment.
    sinsertvertex(insertpt, splitsh, splitseg, ivf->sloc, ivf->sbowywat, 0);
  }

  if (checksubfaceflag) {
    if (ivf->splitbdflag) {
      // Recover new subfaces in C(p).
      for (i = 0; i < caveshbdlist->objects; i++) {
        // Get an old subface at edge [a, b].
        parysh = (face *) fastlookup(caveshbdlist, i);
        spivot(*parysh, checksh); // The new subface [a, b, p].
        // Do not recover a deleted new face (degenerated).
        if (checksh.sh[3] != NULL) {
          // Note that the old subface still connects to adjacent old tets
          //   of C(p), which still connect to the tets outside C(p).
          stpivot(*parysh, neightet);
          assert(infected(neightet));
          // Find the adjacent tet containing the edge [a,b] outside C(p).
          spintet = neightet;
          while (1) {
            fnextself(spintet);
            if (!infected(spintet)) break;
            assert(spintet.tet != neightet.tet);
          }
          // The adjacent tet connects to a new tet in C(p).
          fsym(spintet, neightet);
          assert(!infected(neightet));
          // Find the tet containing the face [a, b, p].
          spintet = neightet;
          while (1) {
            fnextself(spintet);
            if (apex(spintet) == insertpt) break;
            assert(spintet.tet != neightet.tet);
          }
          // Adjust the edge direction in spintet and checksh.
          if (sorg(checksh) != org(spintet)) {
            sesymself(checksh);
            assert(sorg(checksh) == org(spintet));
          }
          assert(sdest(checksh) == dest(spintet));
          // Connect the subface to two adjacent tets.
          tsbond(spintet, checksh);
          fsymself(spintet);
          sesymself(checksh);
          tsbond(spintet, checksh);
        } // if (checksh.sh[3] != NULL)
      }
      // There should be no missing interior subfaces in C(p).
      assert(caveencshlist->objects == 0l);
    } else {
      // The Boundary recovery phase.
      // Put all new subfaces into stack for recovery.
      for (i = 0; i < caveshbdlist->objects; i++) {
        // Get an old subface at edge [a, b].
        parysh = (face *) fastlookup(caveshbdlist, i);
        spivot(*parysh, checksh); // The new subface [a, b, p].
        // Do not recover a deleted new face (degenerated).
        if (checksh.sh[3] != NULL) {
          subfacstack->newindex((void **) &parysh);
          *parysh = checksh;
        }
      }
      // Put all interior subfaces into stack for recovery.
      for (i = 0; i < caveencshlist->objects; i++) {
        parysh = (face *) fastlookup(caveencshlist, i);
        assert(sinfected(*parysh));
        // Some subfaces inside C(p) might be split in sinsertvertex().
        //   Only queue those faces which are not split.
        if (!smarktested(*parysh)) {
          checksh = *parysh;
          suninfect(checksh);
          stdissolve(checksh); // Detach connections to old tets.
          subfacstack->newindex((void **) &parysh);
          *parysh = checksh;
        }
      }
    }
  } // if (checksubfaceflag)

  if (checksubsegflag) {
    if (ivf->splitbdflag) {
      if (splitseg != NULL) {
        // Recover the two new subsegments in C(p).
        for (i = 0; i < cavesegshlist->objects; i++) {
          paryseg = (face *) fastlookup(cavesegshlist, i);
          // Insert this subsegment into C(p).
          checkseg = *paryseg;
          // Get the adjacent new subface.
          checkseg.shver = 0;
          spivot(checkseg, checksh);
          if (checksh.sh != NULL) {
            // Get the adjacent new tetrahedron.
            stpivot(checksh, neightet);
          } else {
            // It's a dangling segment.
            point2tetorg(sorg(checkseg), neightet);
            finddirection(&neightet, sdest(checkseg));
            assert(dest(neightet) == sdest(checkseg));
          }
          assert(!infected(neightet));
          sstbond1(checkseg, neightet);
          spintet = neightet;
          while (1) {
            tssbond1(spintet, checkseg);
            fnextself(spintet);
            if (spintet.tet == neightet.tet) break;
          }
        }
      } // if (splitseg != NULL)
      // There should be no interior segment in C(p).
      assert(caveencseglist->objects == 0l);
    } else {
      // The Boundary Recovery Phase.
      // Queue missing segments in C(p) for recovery.
      if (splitseg != NULL) {
        // Queue two new subsegments in C(p) for recovery.
        for (i = 0; i < cavesegshlist->objects; i++) {
          paryseg = (face *) fastlookup(cavesegshlist, i);
          checkseg = *paryseg;
          //sstdissolve1(checkseg); // It has not been connected yet.
          s = randomnation(subsegstack->objects + 1);
          subsegstack->newindex((void **) &paryseg);
          *paryseg = * (face *) fastlookup(subsegstack, s);
          paryseg = (face *) fastlookup(subsegstack, s);
          *paryseg = checkseg;
        }
      } // if (splitseg != NULL)
      for (i = 0; i < caveencseglist->objects; i++) {
        paryseg = (face *) fastlookup(caveencseglist, i);
        assert(sinfected(*paryseg));
        if (!smarktested(*paryseg)) { // It may be split.
          checkseg = *paryseg;
          suninfect(checkseg);
          sstdissolve1(checkseg); // Detach connections to old tets.
          s = randomnation(subsegstack->objects + 1);
          subsegstack->newindex((void **) &paryseg);
          *paryseg = * (face *) fastlookup(subsegstack, s);
          paryseg = (face *) fastlookup(subsegstack, s);
          *paryseg = checkseg;
        }
      }
    }
  } // if (checksubsegflag)

  if (b->weighted
      ) {
    // Some vertices may be completed inside the cavity. They must be
    //   detected and added to recovering list.
    // Since every "live" vertex must contain a pointer to a non-dead
    //   tetrahedron, we can check for each vertex this pointer.
    for (i = 0; i < cavetetvertlist->objects; i++) {
      pts = (point *) fastlookup(cavetetvertlist, i);
      decode(point2tet(*pts), *searchtet);
      assert(searchtet->tet != NULL); // No tet has been deleted yet.
      if (infected(*searchtet)) {
        if (b->weighted) {
          if (b->verbose > 1) {
            printf("    Point #%d is non-regular after the insertion of #%d.\n",
                   pointmark(*pts), pointmark(insertpt));
          }
          setpointtype(*pts, NREGULARVERTEX);
          nonregularcount++;
        }
      }
    }
  }

  if (ivf->chkencflag & 1) {
    // Queue all segment outside C(p).
    for (i = 0; i < cavetetseglist->objects; i++) {
      paryseg = (face *) fastlookup(cavetetseglist, i);
      // Skip if it is the split segment.
      if (!sinfected(*paryseg)) {
        //enqueuesubface(badsubsegs, paryseg);
      }
    }
    if (splitseg != NULL) {
      // Queue the two new subsegments inside C(p).
      for (i = 0; i < cavesegshlist->objects; i++) {
        paryseg = (face *) fastlookup(cavesegshlist, i);
        //enqueuesubface(badsubsegs, paryseg);
      }
    }
  } // if (chkencflag & 1)

  if (ivf->chkencflag & 2) {
    // Queue all subfaces outside C(p).
    for (i = 0; i < cavetetshlist->objects; i++) {
      parysh = (face *) fastlookup(cavetetshlist, i);
      // Skip if it is a split subface.
      if (!sinfected(*parysh)) {
        //enqueuesubface(badsubfacs, parysh);
      }
    }
    // Queue all new subfaces inside C(p).
    for (i = 0; i < caveshbdlist->objects; i++) {
      // Get an old subface at edge [a, b].
      parysh = (face *) fastlookup(caveshbdlist, i);
      spivot(*parysh, checksh); // checksh is a new subface [a, b, p].
      // Do not recover a deleted new face (degenerated).
      if (checksh.sh[3] != NULL) {
        //enqueuesubface(badsubfacs, &checksh);
      }
    }
  } // if (chkencflag & 2)

  if (ivf->chkencflag & 4) {
    // Queue all new tetrahedra in C(p).
    for (i = 0; i < cavebdrylist->objects; i++) {
      cavetet = (triface *) fastlookup(cavebdrylist, i);
      //enqueuetetrahedron(cavetet);
    }
  }

  // C(p) is re-meshed successfully.

  // Delete the old tets in C(p).
  for (i = 0; i < caveoldtetlist->objects; i++) {
    searchtet = (triface *) fastlookup(caveoldtetlist, i);
    if (ishulltet(*searchtet)) {
      hullsize--;
    }
    tetrahedrondealloc(searchtet->tet);
  }

  if (((splitsh != NULL) && (splitsh->sh != NULL)) ||
      ((splitseg != NULL) && (splitseg->sh != NULL))) {
    // Delete the old subfaces in sC(p).
    for (i = 0; i < caveshlist->objects; i++) {
      parysh = (face *) fastlookup(caveshlist, i);
      if (checksubfaceflag) {//if (bowywat == 2) {
        // It is possible that this subface still connects to adjacent
        //   tets which are not in C(p). If so, clear connections in the
        //   adjacent tets at this subface.
        stpivot(*parysh, neightet);
        if (neightet.tet != NULL) {
          if (neightet.tet[4] != NULL) {
            // Found an adjacent tet. It must be not in C(p).
            assert(!infected(neightet));
            tsdissolve(neightet);
            fsymself(neightet);
            assert(!infected(neightet));
            tsdissolve(neightet);
          }
        }
      }
      shellfacedealloc(subfaces, parysh->sh);
    }
    if ((splitseg != NULL) && (splitseg->sh != NULL)) {
      // Delete the old segment in sC(p).
      shellfacedealloc(subsegs, splitseg->sh);
    }
  }

  if (ivf->lawson) {
    for (i = 0; i < cavebdrylist->objects; i++) {
      searchtet = (triface *) fastlookup(cavebdrylist, i);
      flippush(flipstack, searchtet);
    }
    if (ivf->lawson > 1) {
      for (i = 0; i < cavetetlist->objects; i++) {
        searchtet = (triface *) fastlookup(cavetetlist, i);
        flippush(flipstack, searchtet);
      }
    }
  }


  // Clean the working lists.

  caveoldtetlist->restart();
  cavebdrylist->restart();
  cavetetlist->restart();

  if (checksubsegflag) {
    cavetetseglist->restart();
    caveencseglist->restart();
  }

  if (checksubfaceflag) {
    cavetetshlist->restart();
    caveencshlist->restart();
  }

  if (b->weighted || ivf->validflag) {
    cavetetvertlist->restart();
  }

  if (((splitsh != NULL) && (splitsh->sh != NULL)) ||
      ((splitseg != NULL) && (splitseg->sh != NULL))) {
    caveshlist->restart();
    caveshbdlist->restart();
    cavesegshlist->restart();
  }

  return 1; // Point is inserted.
}

void meshGRegionBoundaryRecovery::insertpoint_abort(face *splitseg, insertvertexflags *ivf)
{
  triface *cavetet;
  face *parysh;
  int i;

  for (i = 0; i < caveoldtetlist->objects; i++) {
    cavetet = (triface *) fastlookup(caveoldtetlist, i);
    uninfect(*cavetet);
    unmarktest(*cavetet);
  }
  for (i = 0; i < cavebdrylist->objects; i++) {
    cavetet = (triface *) fastlookup(cavebdrylist, i);
    unmarktest(*cavetet);
  }
  cavetetlist->restart();
  cavebdrylist->restart();
  caveoldtetlist->restart();
  cavetetseglist->restart();
  cavetetshlist->restart();
  if (ivf->splitbdflag) {
    if ((splitseg != NULL) && (splitseg->sh != NULL)) {
      sunmarktest(*splitseg);
    }
    for (i = 0; i < caveshlist->objects; i++) {
      parysh = (face *) fastlookup(caveshlist, i);
      assert(smarktested(*parysh));
      sunmarktest(*parysh);
    }
    caveshlist->restart();
    cavesegshlist->restart();
  }
}

////                                                                       ////
////                                                                       ////
//// flip_cxx /////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// hilbert_init()    Initialize the Gray code permutation table.             //
//                                                                           //
// The table 'transgc' has 8 x 3 x 8 entries. It contains all possible Gray  //
// code sequences traveled by the 1st order Hilbert curve in 3 dimensions.   //
// The first column is the Gray code of the entry point of the curve, and    //
// the second column is the direction (0, 1, or 2, 0 means the x-axis) where //
// the exit point of curve lies.                                             //
//                                                                           //
// The table 'tsb1mod3' contains the numbers of trailing set '1' bits of the //
// indices from 0 to 7, modulo by '3'. The code for generating this table is //
// from: http://graphics.stanford.edu/~seander/bithacks.html.                //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void meshGRegionBoundaryRecovery::hilbert_init(int n)
{
  int gc[8], N, mask, travel_bit;
  int e, d, f, k, g;
  int v, c;
  int i;

  N = (n == 2) ? 4 : 8;
  mask = (n == 2) ? 3 : 7;

  // Generate the Gray code sequence.
  for (i = 0; i < N; i++) {
    gc[i] = i ^ (i >> 1);
  }

  for (e = 0; e < N; e++) {
    for (d = 0; d < n; d++) {
      // Calculate the end point (f).
      f = e ^ (1 << d);  // Toggle the d-th bit of 'e'.
      // travel_bit = 2**p, the bit we want to travel.
      travel_bit = e ^ f;
      for (i = 0; i < N; i++) {
        // // Rotate gc[i] left by (p + 1) % n bits.
        k = gc[i] * (travel_bit * 2);
        g = ((k | (k / N)) & mask);
        // Calculate the permuted Gray code by xor with the start point (e).
        transgc[e][d][i] = (g ^ e);
      }
      assert(transgc[e][d][0] == e);
      assert(transgc[e][d][N - 1] == f);
    } // d
  } // e

  // Count the consecutive '1' bits (trailing) on the right.
  tsb1mod3[0] = 0;
  for (i = 1; i < N; i++) {
    v = ~i; // Count the 0s.
    v = (v ^ (v - 1)) >> 1; // Set v's trailing 0s to 1s and zero rest
    for (c = 0; v; c++) {
      v >>= 1;
    }
    tsb1mod3[i] = c % n;
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// hilbert_sort3()    Sort points using the 3d Hilbert curve.                //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

int meshGRegionBoundaryRecovery::hilbert_split(point* vertexarray,int arraysize,int gc0,int gc1,
                              REAL bxmin, REAL bxmax, REAL bymin, REAL bymax,
                              REAL bzmin, REAL bzmax)
{
  point swapvert;
  int axis, d;
  REAL split;
  int i, j;


  // Find the current splitting axis. 'axis' is a value 0, or 1, or 2, which
  //   correspoding to x-, or y- or z-axis.
  axis = (gc0 ^ gc1) >> 1;

  // Calulate the split position along the axis.
  if (axis == 0) {
    split = 0.5 * (bxmin + bxmax);
  } else if (axis == 1) {
    split = 0.5 * (bymin + bymax);
  } else { // == 2
    split = 0.5 * (bzmin + bzmax);
  }

  // Find the direction (+1 or -1) of the axis. If 'd' is +1, the direction
  //   of the axis is to the positive of the axis, otherwise, it is -1.
  d = ((gc0 & (1<<axis)) == 0) ? 1 : -1;


  // Partition the vertices into left- and right-arrays such that left points
  //   have Hilbert indices lower than the right points.
  i = 0;
  j = arraysize - 1;

  // Partition the vertices into left- and right-arrays.
  if (d > 0) {
    do {
      for (; i < arraysize; i++) {
        if (vertexarray[i][axis] >= split) break;
      }
      for (; j >= 0; j--) {
        if (vertexarray[j][axis] < split) break;
      }
      // Is the partition finished?
      if (i == (j + 1)) break;
      // Swap i-th and j-th vertices.
      swapvert = vertexarray[i];
      vertexarray[i] = vertexarray[j];
      vertexarray[j] = swapvert;
      // Continue patitioning the array;
    } while (true);
  } else {
    do {
      for (; i < arraysize; i++) {
        if (vertexarray[i][axis] <= split) break;
      }
      for (; j >= 0; j--) {
        if (vertexarray[j][axis] > split) break;
      }
      // Is the partition finished?
      if (i == (j + 1)) break;
      // Swap i-th and j-th vertices.
      swapvert = vertexarray[i];
      vertexarray[i] = vertexarray[j];
      vertexarray[j] = swapvert;
      // Continue patitioning the array;
    } while (true);
  }

  return i;
}

void meshGRegionBoundaryRecovery::hilbert_sort3(point* vertexarray, int arraysize, int e, int d,
                               REAL bxmin, REAL bxmax, REAL bymin, REAL bymax,
                               REAL bzmin, REAL bzmax, int depth)
{
  REAL x1, x2, y1, y2, z1, z2;
  int p[9], w, e_w, d_w, k, ei, di;
  int n = 3, mask = 7;

  p[0] = 0;
  p[8] = arraysize;

  // Sort the points according to the 1st order Hilbert curve in 3d.
  p[4] = hilbert_split(vertexarray, p[8], transgc[e][d][3], transgc[e][d][4],
                       bxmin, bxmax, bymin, bymax, bzmin, bzmax);
  p[2] = hilbert_split(vertexarray, p[4], transgc[e][d][1], transgc[e][d][2],
                       bxmin, bxmax, bymin, bymax, bzmin, bzmax);
  p[1] = hilbert_split(vertexarray, p[2], transgc[e][d][0], transgc[e][d][1],
                       bxmin, bxmax, bymin, bymax, bzmin, bzmax);
  p[3] = hilbert_split(&(vertexarray[p[2]]), p[4] - p[2],
                       transgc[e][d][2], transgc[e][d][3],
                       bxmin, bxmax, bymin, bymax, bzmin, bzmax) + p[2];
  p[6] = hilbert_split(&(vertexarray[p[4]]), p[8] - p[4],
                       transgc[e][d][5], transgc[e][d][6],
                       bxmin, bxmax, bymin, bymax, bzmin, bzmax) + p[4];
  p[5] = hilbert_split(&(vertexarray[p[4]]), p[6] - p[4],
                       transgc[e][d][4], transgc[e][d][5],
                       bxmin, bxmax, bymin, bymax, bzmin, bzmax) + p[4];
  p[7] = hilbert_split(&(vertexarray[p[6]]), p[8] - p[6],
                       transgc[e][d][6], transgc[e][d][7],
                       bxmin, bxmax, bymin, bymax, bzmin, bzmax) + p[6];

  if (b->hilbert_order > 0) {
    // A maximum order is prescribed.
    if ((depth + 1) == b->hilbert_order) {
      // The maximum prescribed order is reached.
      return;
    }
  }

  // Recursively sort the points in sub-boxes.
  for (w = 0; w < 8; w++) {
    // w is the local Hilbert index (NOT Gray code).
    // Sort into the sub-box either there are more than 2 points in it, or
    //   the prescribed order of the curve is not reached yet.
    //if ((p[w+1] - p[w] > b->hilbert_limit) || (b->hilbert_order > 0)) {
    if ((p[w+1] - p[w]) > b->hilbert_limit) {
      // Calculcate the start point (ei) of the curve in this sub-box.
      //   update e = e ^ (e(w) left_rotate (d+1)).
      if (w == 0) {
        e_w = 0;
      } else {
        //   calculate e(w) = gc(2 * floor((w - 1) / 2)).
        k = 2 * ((w - 1) / 2);
        e_w = k ^ (k >> 1); // = gc(k).
      }
      k = e_w;
      e_w = ((k << (d+1)) & mask) | ((k >> (n-d-1)) & mask);
      ei = e ^ e_w;
      // Calulcate the direction (di) of the curve in this sub-box.
      //   update d = (d + d(w) + 1) % n
      if (w == 0) {
        d_w = 0;
      } else {
        d_w = ((w % 2) == 0) ? tsb1mod3[w - 1] : tsb1mod3[w];
      }
      di = (d + d_w + 1) % n;
      // Calculate the bounding box of the sub-box.
      if (transgc[e][d][w] & 1) { // x-axis
        x1 = 0.5 * (bxmin + bxmax);
        x2 = bxmax;
      } else {
        x1 = bxmin;
        x2 = 0.5 * (bxmin + bxmax);
      }
      if (transgc[e][d][w] & 2) { // y-axis
        y1 = 0.5 * (bymin + bymax);
        y2 = bymax;
      } else {
        y1 = bymin;
        y2 = 0.5 * (bymin + bymax);
      }
      if (transgc[e][d][w] & 4) { // z-axis
        z1 = 0.5 * (bzmin + bzmax);
        z2 = bzmax;
      } else {
        z1 = bzmin;
        z2 = 0.5 * (bzmin + bzmax);
      }
      hilbert_sort3(&(vertexarray[p[w]]), p[w+1] - p[w], ei, di,
                    x1, x2, y1, y2, z1, z2, depth+1);
    } // if (p[w+1] - p[w] > 1)
  } // w
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// brio_multiscale_sort()    Sort the points using BRIO and Hilbert curve.   //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void meshGRegionBoundaryRecovery::brio_multiscale_sort(point* vertexarray, int arraysize,
                                      int threshold, REAL ratio, int *depth)
{
  int middle;

  middle = 0;
  if (arraysize >= threshold) {
    (*depth)++;
    middle = arraysize * ratio;
    brio_multiscale_sort(vertexarray, middle, threshold, ratio, depth);
  }
  // Sort the right-array (rnd-th round) using the Hilbert curve.
  hilbert_sort3(&(vertexarray[middle]), arraysize - middle, 0, 0, // e, d
                xmin, xmax, ymin, ymax, zmin, zmax, 0); // depth.
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// randomnation()    Generate a random number between 0 and 'choices' - 1.   //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

unsigned long meshGRegionBoundaryRecovery::randomnation(unsigned int choices)
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
// Searching begins from one of handles:  the input 'searchtet', a recently  //
// encountered tetrahedron 'recenttet',  or from one chosen from a random    //
// sample.  The choice is made by determining which one's origin is closest  //
// to the point we are searching for.                                        //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void meshGRegionBoundaryRecovery::randomsample(point searchpt,triface *searchtet)
{
  tetrahedron *firsttet, *tetptr;
  point torg;
  void **sampleblock;
  uintptr_t alignptr;
  long sampleblocks, samplesperblock, samplenum;
  long tetblocks, i, j;
  REAL searchdist, dist;

  if (b->verbose > 2) {
    printf("      Random sampling tetrahedra for searching point %d.\n",
           pointmark(searchpt));
  }

  if (!nonconvex) {
    if (searchtet->tet == NULL) {
      // A null tet. Choose the recenttet as the starting tet.
      *searchtet = recenttet;
      // Recenttet should not be dead.
      assert(recenttet.tet[4] != NULL);
    }

    // 'searchtet' should be a valid tetrahedron. Choose the base face
    //   whose vertices must not be 'dummypoint'.
    searchtet->ver = 3;
    // Record the distance from its origin to the searching point.
    torg = org(*searchtet);
    searchdist = (searchpt[0] - torg[0]) * (searchpt[0] - torg[0]) +
                 (searchpt[1] - torg[1]) * (searchpt[1] - torg[1]) +
                 (searchpt[2] - torg[2]) * (searchpt[2] - torg[2]);

    // If a recently encountered tetrahedron has been recorded and has not
    //   been deallocated, test it as a good starting point.
    if (recenttet.tet != searchtet->tet) {
      recenttet.ver = 3;
      torg = org(recenttet);
      dist = (searchpt[0] - torg[0]) * (searchpt[0] - torg[0]) +
             (searchpt[1] - torg[1]) * (searchpt[1] - torg[1]) +
             (searchpt[2] - torg[2]) * (searchpt[2] - torg[2]);
      if (dist < searchdist) {
        *searchtet = recenttet;
        searchdist = dist;
      }
    }
  } else {
    // The mesh is non-convex. Do not use 'recenttet'.
    assert(samples >= 1l); // Make sure at least 1 sample.
    searchdist = longest;
  }

  // Select "good" candidate using k random samples, taking the closest one.
  //   The number of random samples taken is proportional to the fourth root
  //   of the number of tetrahedra in the mesh.
  while (samples * samples * samples * samples < tetrahedrons->items) {
    samples++;
  }
  // Find how much blocks in current tet pool.
  tetblocks = (tetrahedrons->maxitems + b->tetrahedraperblock - 1)
            / b->tetrahedraperblock;
  // Find the average samples per block. Each block at least have 1 sample.
  samplesperblock = 1 + (samples / tetblocks);
  sampleblocks = samples / samplesperblock;
  sampleblock = tetrahedrons->firstblock;
  for (i = 0; i < sampleblocks; i++) {
    alignptr = (uintptr_t) (sampleblock + 1);
    firsttet = (tetrahedron *)
               (alignptr + (uintptr_t) tetrahedrons->alignbytes
               - (alignptr % (uintptr_t) tetrahedrons->alignbytes));
    for (j = 0; j < samplesperblock; j++) {
      if (i == tetblocks - 1) {
        // This is the last block.
        samplenum = randomnation((int)
                      (tetrahedrons->maxitems - (i * b->tetrahedraperblock)));
      } else {
        samplenum = randomnation(b->tetrahedraperblock);
      }
      tetptr = (tetrahedron *)
               (firsttet + (samplenum * tetrahedrons->itemwords));
      torg = (point) tetptr[4];
      if (torg != (point) NULL) {
        dist = (searchpt[0] - torg[0]) * (searchpt[0] - torg[0]) +
               (searchpt[1] - torg[1]) * (searchpt[1] - torg[1]) +
               (searchpt[2] - torg[2]) * (searchpt[2] - torg[2]);
        if (dist < searchdist) {
          searchtet->tet = tetptr;
          searchtet->ver = 11; // torg = org(t);
          searchdist = dist;
        }
      } else {
        // A dead tet. Re-sample it.
        if (i != tetblocks - 1) j--;
      }
    }
    sampleblock = (void **) *sampleblock;
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// locate()    Find a tetrahedron containing a given point.                  //
//                                                                           //
// Begins its search from 'searchtet', assume there is a line segment L from //
// a vertex of 'searchtet' to the query point 'searchpt', and simply walk    //
// towards 'searchpt' by traversing all faces intersected by L.              //
//                                                                           //
// On completion, 'searchtet' is a tetrahedron that contains 'searchpt'. The //
// returned value indicates one of the following cases:                      //
//   - ONVERTEX, the search point lies on the origin of 'searchtet'.         //
//   - ONEDGE, the search point lies on an edge of 'searchtet'.              //
//   - ONFACE, the search point lies on a face of 'searchtet'.               //
//   - INTET, the search point lies in the interior of 'searchtet'.          //
//   - OUTSIDE, the search point lies outside the mesh. 'searchtet' is a     //
//              hull face which is visible by the search point.              //
//                                                                           //
// WARNING: This routine is designed for convex triangulations, and will not //
// generally work after the holes and concavities have been carved.          //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

enum meshGRegionBoundaryRecovery::locateresult meshGRegionBoundaryRecovery::locate(point searchpt,
                                                 triface* searchtet)
{
  point torg, tdest, tapex, toppo;
  enum {ORGMOVE, DESTMOVE, APEXMOVE} nextmove;
  REAL ori, oriorg, oridest, oriapex;
  enum locateresult loc = OUTSIDE;
  int t1ver;
  int s;

  if (searchtet->tet == NULL) {
    // A null tet. Choose the recenttet as the starting tet.
    searchtet->tet = recenttet.tet;
  }

  // Check if we are in the outside of the convex hull.
  if (ishulltet(*searchtet)) {
    // Get its adjacent tet (inside the hull).
    searchtet->ver = 3;
    fsymself(*searchtet);
  }

  // Let searchtet be the face such that 'searchpt' lies above to it.
  for (searchtet->ver = 0; searchtet->ver < 4; searchtet->ver++) {
    torg = org(*searchtet);
    tdest = dest(*searchtet);
    tapex = apex(*searchtet);
    ori = orient3d(torg, tdest, tapex, searchpt);
    if (ori < 0.0) break;
  }
  assert(searchtet->ver != 4);

  // Walk through tetrahedra to locate the point.
  while (true) {

    toppo = oppo(*searchtet);

    // Check if the vertex is we seek.
    if (toppo == searchpt) {
      // Adjust the origin of searchtet to be searchpt.
      esymself(*searchtet);
      eprevself(*searchtet);
      loc = ONVERTEX; // return ONVERTEX;
      break;
    }

    // We enter from one of serarchtet's faces, which face do we exit?
    oriorg = orient3d(tdest, tapex, toppo, searchpt);
    oridest = orient3d(tapex, torg, toppo, searchpt);
    oriapex = orient3d(torg, tdest, toppo, searchpt);

    // Now decide which face to move. It is possible there are more than one
    //   faces are viable moves. If so, randomly choose one.
    if (oriorg < 0) {
      if (oridest < 0) {
        if (oriapex < 0) {
          // All three faces are possible.
          s = randomnation(3); // 's' is in {0,1,2}.
          if (s == 0) {
            nextmove = ORGMOVE;
          } else if (s == 1) {
            nextmove = DESTMOVE;
          } else {
            nextmove = APEXMOVE;
          }
        } else {
          // Two faces, opposite to origin and destination, are viable.
          //s = randomnation(2); // 's' is in {0,1}.
          if (randomnation(2)) {
            nextmove = ORGMOVE;
          } else {
            nextmove = DESTMOVE;
          }
        }
      } else {
        if (oriapex < 0) {
          // Two faces, opposite to origin and apex, are viable.
          //s = randomnation(2); // 's' is in {0,1}.
          if (randomnation(2)) {
            nextmove = ORGMOVE;
          } else {
            nextmove = APEXMOVE;
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
          //s = randomnation(2); // 's' is in {0,1}.
          if (randomnation(2)) {
            nextmove = DESTMOVE;
          } else {
            nextmove = APEXMOVE;
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
            enextesymself(*searchtet);
            if (oridest == 0) {
              eprevself(*searchtet); // edge oppo->apex
              if (oriapex == 0) {
                // oppo is duplicated with p.
                loc = ONVERTEX; // return ONVERTEX;
                break;
              }
              loc = ONEDGE; // return ONEDGE;
              break;
            }
            if (oriapex == 0) {
              enextself(*searchtet); // edge dest->oppo
              loc = ONEDGE; // return ONEDGE;
              break;
            }
            loc = ONFACE; // return ONFACE;
            break;
          }
          if (oridest == 0) {
            // Go to the face opposite to destination.
            eprevesymself(*searchtet);
            if (oriapex == 0) {
              eprevself(*searchtet); // edge oppo->org
              loc = ONEDGE; // return ONEDGE;
              break;
            }
            loc = ONFACE; // return ONFACE;
            break;
          }
          if (oriapex == 0) {
            // Go to the face opposite to apex
            esymself(*searchtet);
            loc = ONFACE; // return ONFACE;
            break;
          }
          loc = INTETRAHEDRON; // return INTETRAHEDRON;
          break;
        }
      }
    }

    // Move to the selected face.
    if (nextmove == ORGMOVE) {
      enextesymself(*searchtet);
    } else if (nextmove == DESTMOVE) {
      eprevesymself(*searchtet);
    } else {
      esymself(*searchtet);
    }
    // Move to the adjacent tetrahedron (maybe a hull tetrahedron).
    fsymself(*searchtet);
    if (oppo(*searchtet) == dummypoint) {
      loc = OUTSIDE; // return OUTSIDE;
      break;
    }

    // Retreat the three vertices of the base face.
    torg = org(*searchtet);
    tdest = dest(*searchtet);
    tapex = apex(*searchtet);

  } // while (true)

  return loc;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// flippush()    Push a face (possibly will be flipped) into flipstack.      //
//                                                                           //
// The face is marked. The flag is used to check the validity of the face on //
// its popup.  Some other flips may change it already.                       //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void meshGRegionBoundaryRecovery::flippush(badface*& fstack, triface* flipface)
{
  if (!facemarked(*flipface)) {
    badface *newflipface = (badface *) flippool->alloc();
    newflipface->tt = *flipface;
    markface(newflipface->tt);
    // Push this face into stack.
    newflipface->nextitem = fstack;
    fstack = newflipface;
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// initialdelaunay()    Create an initial Delaunay tetrahedralization.       //
//                                                                           //
// The tetrahedralization contains only one tetrahedron abcd, and four hull  //
// tetrahedra. The points pa, pb, pc, and pd must be linearly independent.   //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void meshGRegionBoundaryRecovery::initialdelaunay(point pa, point pb, point pc, point pd)
{
  triface firsttet, tetopa, tetopb, tetopc, tetopd;
  triface worktet, worktet1;

  if (b->verbose > 2) {
    printf("      Create init tet (%d, %d, %d, %d)\n", pointmark(pa),
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
  bond(firsttet, tetopd);
  esym(firsttet, worktet);
  bond(worktet, tetopc); // ab
  enextesym(firsttet, worktet);
  bond(worktet, tetopa); // bc
  eprevesym(firsttet, worktet);
  bond(worktet, tetopb); // ca

  // Connect hull tetrahedra together (at six edges of firsttet).
  esym(tetopc, worktet);
  esym(tetopd, worktet1);
  bond(worktet, worktet1); // ab
  esym(tetopa, worktet);
  eprevesym(tetopd, worktet1);
  bond(worktet, worktet1); // bc
  esym(tetopb, worktet);
  enextesym(tetopd, worktet1);
  bond(worktet, worktet1); // ca
  eprevesym(tetopc, worktet);
  enextesym(tetopb, worktet1);
  bond(worktet, worktet1); // da
  eprevesym(tetopa, worktet);
  enextesym(tetopc, worktet1);
  bond(worktet, worktet1); // db
  eprevesym(tetopb, worktet);
  enextesym(tetopa, worktet1);
  bond(worktet, worktet1); // dc

  // Set the vertex type.
  if (pointtype(pa) == UNUSEDVERTEX) {
    setpointtype(pa, VOLVERTEX);
  }
  if (pointtype(pb) == UNUSEDVERTEX) {
    setpointtype(pb, VOLVERTEX);
  }
  if (pointtype(pc) == UNUSEDVERTEX) {
    setpointtype(pc, VOLVERTEX);
  }
  if (pointtype(pd) == UNUSEDVERTEX) {
    setpointtype(pd, VOLVERTEX);
  }

  setpoint2tet(pa, encode(firsttet));
  setpoint2tet(pb, encode(firsttet));
  setpoint2tet(pc, encode(firsttet));
  setpoint2tet(pd, encode(firsttet));

  // Remember the first tetrahedron.
  recenttet = firsttet;
}

////                                                                       ////
////                                                                       ////
//// delaunay_cxx /////////////////////////////////////////////////////////////

//// surface_cxx //////////////////////////////////////////////////////////////
////                                                                       ////
////                                                                       ////

void meshGRegionBoundaryRecovery::flipshpush(face* flipedge)
{
  badface *newflipface;

  newflipface = (badface *) flippool->alloc();
  newflipface->ss = *flipedge;
  newflipface->forg = sorg(*flipedge);
  newflipface->fdest = sdest(*flipedge);
  newflipface->nextitem = flipstack;
  flipstack = newflipface;
}

void meshGRegionBoundaryRecovery::flip22(face* flipfaces, int flipflag,
  int chkencflag)
{
  face bdedges[4], outfaces[4], infaces[4];
  face bdsegs[4];
  face checkface;
  point pa, pb, pc, pd;
  int i;

  pa = sorg(flipfaces[0]);
  pb = sdest(flipfaces[0]);
  pc = sapex(flipfaces[0]);
  pd = sapex(flipfaces[1]);

  if (sorg(flipfaces[1]) != pb) {
    sesymself(flipfaces[1]);
  }

  flip22count++;

  // Collect the four boundary edges.
  senext(flipfaces[0], bdedges[0]);
  senext2(flipfaces[0], bdedges[1]);
  senext(flipfaces[1], bdedges[2]);
  senext2(flipfaces[1], bdedges[3]);

  // Collect outer boundary faces.
  for (i = 0; i < 4; i++) {
    spivot(bdedges[i], outfaces[i]);
    infaces[i] = outfaces[i];
    sspivot(bdedges[i], bdsegs[i]);
    if (outfaces[i].sh != NULL) {
      if (isshsubseg(bdedges[i])) {
        spivot(infaces[i], checkface);
        while (checkface.sh != bdedges[i].sh) {
          infaces[i] = checkface;
          spivot(infaces[i], checkface);
        }
      }
    }
  }

  // The flags set in these two subfaces do not change.
  // Shellmark does not change.
  // area constraint does not change.

  // Transform [a,b,c] -> [c,d,b].
  setshvertices(flipfaces[0], pc, pd, pb);
  // Transform [b,a,d] -> [d,c,a].
  setshvertices(flipfaces[1], pd, pc, pa);

  // Update the point-to-subface map.
  if (pointtype(pa) == FREEFACETVERTEX) {
    setpoint2sh(pa, sencode(flipfaces[1]));
  }
  if (pointtype(pb) == FREEFACETVERTEX) {
    setpoint2sh(pb, sencode(flipfaces[0]));
  }
  if (pointtype(pc) == FREEFACETVERTEX) {
    setpoint2sh(pc, sencode(flipfaces[0]));
  }
  if (pointtype(pd) == FREEFACETVERTEX) {
    setpoint2sh(pd, sencode(flipfaces[0]));
  }

  // Reconnect boundary edges to outer boundary faces.
  for (i = 0; i < 4; i++) {
    if (outfaces[(3 + i) % 4].sh != NULL) {
      // Make sure that the subface has the ori as the segment.
      if (bdsegs[(3 + i) % 4].sh != NULL) {
        bdsegs[(3 + i) % 4].shver = 0;
        if (sorg(bdedges[i]) != sorg(bdsegs[(3 + i) % 4])) {
          sesymself(bdedges[i]);
        }
      }
      sbond1(bdedges[i], outfaces[(3 + i) % 4]);
      sbond1(infaces[(3 + i) % 4], bdedges[i]);
    } else {
      sdissolve(bdedges[i]);
    }
    if (bdsegs[(3 + i) % 4].sh != NULL) {
      ssbond(bdedges[i], bdsegs[(3 + i) % 4]);
      if (chkencflag & 1) {
        // Queue this segment for encroaching check.
        //enqueuesubface(badsubsegs, &(bdsegs[(3 + i) % 4]));
      }
    } else {
      ssdissolve(bdedges[i]);
    }
  }

  if (chkencflag & 2) {
    // Queue the flipped subfaces for quality/encroaching checks.
    for (i = 0; i < 2; i++) {
      //enqueuesubface(badsubfacs, &(flipfaces[i]));
    }
  }

  recentsh = flipfaces[0];

  if (flipflag) {
    // Put the boundary edges into flip stack.
    for (i = 0; i < 4; i++) {
      flipshpush(&(bdedges[i]));
    }
  }
}

void meshGRegionBoundaryRecovery::flip31(face* flipfaces, int flipflag)
{
  face bdedges[3], outfaces[3], infaces[3];
  face bdsegs[3];
  face checkface;
  point pa, pb, pc;
  int i;

  pa = sdest(flipfaces[0]);
  pb = sdest(flipfaces[1]);
  pc = sdest(flipfaces[2]);

  flip31count++;

  // Collect all infos at the three boundary edges.
  for (i = 0; i < 3; i++) {
    senext(flipfaces[i], bdedges[i]);
    spivot(bdedges[i], outfaces[i]);
    infaces[i] = outfaces[i];
    sspivot(bdedges[i], bdsegs[i]);
    if (outfaces[i].sh != NULL) {
      if (isshsubseg(bdedges[i])) {
        spivot(infaces[i], checkface);
        while (checkface.sh != bdedges[i].sh) {
          infaces[i] = checkface;
          spivot(infaces[i], checkface);
        }
      }
    }
  } // i

  // Create a new subface.
  makeshellface(subfaces, &(flipfaces[3]));
  setshvertices(flipfaces[3], pa, pb,pc);
  setshellmark(flipfaces[3], shellmark(flipfaces[0]));
  if (checkconstraints) {
    //area = areabound(flipfaces[0]);
    setareabound(flipfaces[3], areabound(flipfaces[0]));
  }
  if (useinsertradius) {
    setfacetindex(flipfaces[3], getfacetindex(flipfaces[0]));
  }

  // Update the point-to-subface map.
  if (pointtype(pa) == FREEFACETVERTEX) {
    setpoint2sh(pa, sencode(flipfaces[3]));
  }
  if (pointtype(pb) == FREEFACETVERTEX) {
    setpoint2sh(pb, sencode(flipfaces[3]));
  }
  if (pointtype(pc) == FREEFACETVERTEX) {
    setpoint2sh(pc, sencode(flipfaces[3]));
  }

  // Update the three new boundary edges.
  bdedges[0] = flipfaces[3];         // [a,b]
  senext(flipfaces[3], bdedges[1]);  // [b,c]
  senext2(flipfaces[3], bdedges[2]); // [c,a]

  // Reconnect boundary edges to outer boundary faces.
  for (i = 0; i < 3; i++) {
    if (outfaces[i].sh != NULL) {
      // Make sure that the subface has the ori as the segment.
      if (bdsegs[i].sh != NULL) {
        bdsegs[i].shver = 0;
        if (sorg(bdedges[i]) != sorg(bdsegs[i])) {
          sesymself(bdedges[i]);
        }
      }
      sbond1(bdedges[i], outfaces[i]);
      sbond1(infaces[i], bdedges[i]);
    }
    if (bdsegs[i].sh != NULL) {
      ssbond(bdedges[i], bdsegs[i]);
    }
  }

  recentsh = flipfaces[3];

  if (flipflag) {
    // Put the boundary edges into flip stack.
    for (i = 0; i < 3; i++) {
      flipshpush(&(bdedges[i]));
    }
  }
}

long meshGRegionBoundaryRecovery::lawsonflip()
{
  badface *popface;
  face flipfaces[2];
  point pa, pb, pc, pd;
  REAL sign;
  long flipcount = 0;

  if (b->verbose > 2) {
    printf("      Lawson flip %ld edges.\n", flippool->items);
  }

  while (flipstack != (badface *) NULL) {

    // Pop an edge from the stack.
    popface = flipstack;
    flipfaces[0] = popface->ss;
    pa = popface->forg;
    pb = popface->fdest;
    flipstack = popface->nextitem; // The next top item in stack.
    flippool->dealloc((void *) popface);

    // Skip it if it is dead.
    if (flipfaces[0].sh[3] == NULL) continue;
    // Skip it if it is not the same edge as we saved.
    if ((sorg(flipfaces[0]) != pa) || (sdest(flipfaces[0]) != pb)) continue;
    // Skip it if it is a subsegment.
    if (isshsubseg(flipfaces[0])) continue;

    // Get the adjacent face.
    spivot(flipfaces[0], flipfaces[1]);
    if (flipfaces[1].sh == NULL) continue; // Skip a hull edge.
    pc = sapex(flipfaces[0]);
    pd = sapex(flipfaces[1]);

    sign = incircle3d(pa, pb, pc, pd);

    if (sign < 0) {
      // It is non-locally Delaunay. Flip it.
      flip22(flipfaces, 1, 0);
      flipcount++;
    }
  }

  if (b->verbose > 2) {
    printf("      Performed %ld flips.\n", flipcount);
  }

  return flipcount;
}

int meshGRegionBoundaryRecovery::sinsertvertex(point insertpt, face *searchsh,
  face *splitseg, int iloc, int bowywat, int rflag)
{
  face cavesh, neighsh, *parysh;
  face newsh, casout, casin;
  face checkseg;
  point pa, pb;
  enum locateresult loc = OUTSIDE;
  REAL sign, ori;
  int i, j;

  if (b->verbose > 2) {
    printf("      Insert facet point %d.\n", pointmark(insertpt));
  }

  if (bowywat == 3) {
    loc = INSTAR;
  }

  if ((splitseg != NULL) && (splitseg->sh != NULL)) {
    // A segment is going to be split, no point location.
    spivot(*splitseg, *searchsh);
    if (loc != INSTAR) loc = ONEDGE;
  } else {
    if (loc != INSTAR) loc = (enum locateresult) iloc;
    if (loc == OUTSIDE) {
      // Do point location in surface mesh.
      if (searchsh->sh == NULL) {
        *searchsh = recentsh;
      }
      // Search the vertex. An above point must be provided ('aflag' = 1).
      loc = slocate(insertpt, searchsh, 1, 1, rflag);
    }
  }


  // Form the initial sC(p).
  if (loc == ONFACE) {
    // Add the face into list (in B-W cavity).
    smarktest(*searchsh);
    caveshlist->newindex((void **) &parysh);
    *parysh = *searchsh;
  } else if (loc == ONEDGE) {
    if ((splitseg != NULL) && (splitseg->sh != NULL)) {
      splitseg->shver = 0;
      pa = sorg(*splitseg);
    } else {
      pa = sorg(*searchsh);
    }
    if (searchsh->sh != NULL) {
      // Collect all subfaces share at this edge.
      neighsh = *searchsh;
      while (1) {
        // Adjust the origin of its edge to be 'pa'.
        if (sorg(neighsh) != pa) sesymself(neighsh);
        // Add this face into list (in B-W cavity).
        smarktest(neighsh);
        caveshlist->newindex((void **) &parysh);
        *parysh = neighsh;
        // Add this face into face-at-splitedge list.
        cavesegshlist->newindex((void **) &parysh);
        *parysh = neighsh;
        // Go to the next face at the edge.
        spivotself(neighsh);
        // Stop if all faces at the edge have been visited.
        if (neighsh.sh == searchsh->sh) break;
        if (neighsh.sh == NULL) break;
      }
    } // If (not a non-dangling segment).
  } else if (loc == ONVERTEX) {
    return (int) loc;
  } else if (loc == OUTSIDE) {
    // Comment: This should only happen during the surface meshing step.
    // Enlarge the convex hull of the triangulation by including p.
    // An above point of the facet is set in 'dummypoint' to replace
    // orient2d tests by orient3d tests.
    // Imagine that the current edge a->b (in 'searchsh') is horizontal in a
    //   plane, and a->b is directed from left to right, p lies above a->b.
    //   Find the right-most edge of the triangulation which is visible by p.
    neighsh = *searchsh;
    while (1) {
      senext2self(neighsh);
      spivot(neighsh, casout);
      if (casout.sh == NULL) {
        // A convex hull edge. Is it visible by p.
        ori = orient3d(sorg(neighsh), sdest(neighsh), dummypoint, insertpt);
        if (ori < 0) {
          *searchsh = neighsh; // Visible, update 'searchsh'.
        } else {
          break; // 'searchsh' is the right-most visible edge.
        }
      } else {
        if (sorg(casout) != sdest(neighsh)) sesymself(casout);
        neighsh = casout;
      }
    }
    // Create new triangles for all visible edges of p (from right to left).
    casin.sh = NULL;  // No adjacent face at right.
    pa = sorg(*searchsh);
    pb = sdest(*searchsh);
    while (1) {
      // Create a new subface on top of the (visible) edge.
      makeshellface(subfaces, &newsh);
      setshvertices(newsh, pb, pa, insertpt);
      setshellmark(newsh, shellmark(*searchsh));
      if (checkconstraints) {
        //area = areabound(*searchsh);
        setareabound(newsh, areabound(*searchsh));
      }
      if (useinsertradius) {
        setfacetindex(newsh, getfacetindex(*searchsh));
      }
      // Connect the new subface to the bottom subfaces.
      sbond1(newsh, *searchsh);
      sbond1(*searchsh, newsh);
      // Connect the new subface to its right-adjacent subface.
      if (casin.sh != NULL) {
        senext(newsh, casout);
        sbond1(casout, casin);
        sbond1(casin, casout);
      }
      // The left-adjacent subface has not been created yet.
      senext2(newsh, casin);
      // Add the new face into list (inside the B-W cavity).
      smarktest(newsh);
      caveshlist->newindex((void **) &parysh);
      *parysh = newsh;
      // Move to the convex hull edge at the left of 'searchsh'.
      neighsh = *searchsh;
      while (1) {
        senextself(neighsh);
        spivot(neighsh, casout);
        if (casout.sh == NULL) {
          *searchsh = neighsh;
          break;
        }
        if (sorg(casout) != sdest(neighsh)) sesymself(casout);
        neighsh = casout;
      }
      // A convex hull edge. Is it visible by p.
      pa = sorg(*searchsh);
      pb = sdest(*searchsh);
      ori = orient3d(pa, pb, dummypoint, insertpt);
      // Finish the process if p is not visible by the hull edge.
      if (ori >= 0) break;
    }
  } else if (loc == INSTAR) {
    // Under this case, the sub-cavity sC(p) has already been formed in
    //   insertvertex().
  }

  // Form the Bowyer-Watson cavity sC(p).
  for (i = 0; i < caveshlist->objects; i++) {
    cavesh = * (face *) fastlookup(caveshlist, i);
    for (j = 0; j < 3; j++) {
      if (!isshsubseg(cavesh)) {
        spivot(cavesh, neighsh);
        if (neighsh.sh != NULL) {
          // The adjacent face exists.
          if (!smarktested(neighsh)) {
            if (bowywat) {
              if (loc == INSTAR) { // if (bowywat > 2) {
                // It must be a boundary edge.
                sign = 1;
              } else {
                // Check if this subface is connected to adjacent tet(s).
                if (!isshtet(neighsh)) {
                  // Check if the subface is non-Delaunay wrt. the new pt.
                  sign = incircle3d(sorg(neighsh), sdest(neighsh),
                                    sapex(neighsh), insertpt);
                } else {
                  // It is connected to an adjacent tet. A boundary edge.
                  sign = 1;
                }
              }
              if (sign < 0) {
                // Add the adjacent face in list (in B-W cavity).
                smarktest(neighsh);
                caveshlist->newindex((void **) &parysh);
                *parysh = neighsh;
              }
            } else {
              sign = 1; // A boundary edge.
            }
          } else {
            sign = -1; // Not a boundary edge.
          }
        } else {
          // No adjacent face. It is a hull edge.
          if (loc == OUTSIDE) {
            // It is a boundary edge if it does not contain p.
            if ((sorg(cavesh) == insertpt) || (sdest(cavesh) == insertpt)) {
              sign = -1; // Not a boundary edge.
            } else {
              sign = 1; // A boundary edge.
            }
          } else {
            sign = 1; // A boundary edge.
          }
        }
      } else {
        // Do not across a segment. It is a boundary edge.
        sign = 1;
      }
      if (sign >= 0) {
        // Add a boundary edge.
        caveshbdlist->newindex((void **) &parysh);
        *parysh = cavesh;
      }
      senextself(cavesh);
    } // j
  } // i


  // Creating new subfaces.
  for (i = 0; i < caveshbdlist->objects; i++) {
    parysh = (face *) fastlookup(caveshbdlist, i);
    sspivot(*parysh, checkseg);
    if ((parysh->shver & 01) != 0) sesymself(*parysh);
    pa = sorg(*parysh);
    pb = sdest(*parysh);
    // Create a new subface.
    makeshellface(subfaces, &newsh);
    setshvertices(newsh, pa, pb, insertpt);
    setshellmark(newsh, shellmark(*parysh));
    if (checkconstraints) {
      //area = areabound(*parysh);
      setareabound(newsh, areabound(*parysh));
    }
    if (useinsertradius) {
      setfacetindex(newsh, getfacetindex(*parysh));
    }
    // Update the point-to-subface map.
    if (pointtype(pa) == FREEFACETVERTEX) {
      setpoint2sh(pa, sencode(newsh));
    }
    if (pointtype(pb) == FREEFACETVERTEX) {
      setpoint2sh(pb, sencode(newsh));
    }
    // Connect newsh to outer subfaces.
    spivot(*parysh, casout);
    if (casout.sh != NULL) {
      casin = casout;
      if (checkseg.sh != NULL) {
        // Make sure that newsh has the right ori at this segment.
        checkseg.shver = 0;
        if (sorg(newsh) != sorg(checkseg)) {
          sesymself(newsh);
          sesymself(*parysh); // This side should also be inverse.
        }
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
    //   *parysh and newsh point to the same edge and the same ori.
    sbond1(*parysh, newsh);
  }

  if (newsh.sh != NULL) {
    // Set a handle for searching.
    recentsh = newsh;
  }

  // Update the point-to-subface map.
  if (pointtype(insertpt) == FREEFACETVERTEX) {
    setpoint2sh(insertpt, sencode(newsh));
  }

  // Connect adjacent new subfaces together.
  for (i = 0; i < caveshbdlist->objects; i++) {
    // Get an old subface at edge [a, b].
    parysh = (face *) fastlookup(caveshbdlist, i);
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
        senext2self(neighsh); // Go to the open edge [p, b].
        sbond(newsh, neighsh);
      } else {
        // There is no adjacent new face at this side.
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
        senextself(neighsh); // Go to the open edge [a, p].
        sbond(newsh, neighsh);
      } else {
        // There is no adjacent new face at this side.
        assert(loc == OUTSIDE); // SELF_CHECK
      }
    }
  }

  if ((loc == ONEDGE) || ((splitseg != NULL) && (splitseg->sh != NULL))
      || (cavesegshlist->objects > 0l)) {
    // An edge is being split. We distinguish two cases:
    //   (1) the edge is not on the boundary of the cavity;
    //   (2) the edge is on the boundary of the cavity.
    // In case (2), the edge is either a segment or a hull edge. There are
    //   degenerated new faces in the cavity. They must be removed.
    face aseg, bseg, aoutseg, boutseg;

    for (i = 0; i < cavesegshlist->objects; i++) {
      // Get the saved old subface.
      parysh = (face *) fastlookup(cavesegshlist, i);
      // Get a possible new degenerated subface.
      spivot(*parysh, cavesh);
      if (sapex(cavesh) == insertpt) {
        // Found a degenerated new subface, i.e., case (2).
        if (cavesegshlist->objects > 1) {
          // There are more than one subface share at this edge.
          j = (i + 1) % (int) cavesegshlist->objects;
          parysh = (face *) fastlookup(cavesegshlist, j);
          spivot(*parysh, neighsh);
          // Adjust cavesh and neighsh both at edge a->b, and has p as apex.
          if (sorg(neighsh) != sorg(cavesh)) {
            sesymself(neighsh);
            assert(sorg(neighsh) == sorg(cavesh)); // SELF_CHECK
          }
          assert(sapex(neighsh) == insertpt); // SELF_CHECK
          // Connect adjacent faces at two other edges of cavesh and neighsh.
          //   As a result, the two degenerated new faces are squeezed from the
          //   new triangulation of the cavity. Note that the squeezed faces
          //   still hold the adjacent informations which will be used in
          //   re-connecting subsegments (if they exist).
          for (j = 0; j < 2; j++) {
            senextself(cavesh);
            senextself(neighsh);
            spivot(cavesh, newsh);
            spivot(neighsh, casout);
            sbond1(newsh, casout); // newsh <- casout.
          }
        } else {
          // There is only one subface containing this edge [a,b]. Squeeze the
          //   degenerated new face [a,b,c] by disconnecting it from its two
          //   adjacent subfaces at edges [b,c] and [c,a]. Note that the face
          //   [a,b,c] still hold the connection to them.
          for (j = 0; j < 2; j++) {
            senextself(cavesh);
            spivot(cavesh, newsh);
            sdissolve(newsh);
          }
        }
        //recentsh = newsh;
        // Update the point-to-subface map.
        if (pointtype(insertpt) == FREEFACETVERTEX) {
          setpoint2sh(insertpt, sencode(newsh));
        }
      }
    }

    if ((splitseg != NULL) && (splitseg->sh != NULL)) {
      if (loc != INSTAR) { // if (bowywat < 3) {
        smarktest(*splitseg); // Mark it as being processed.
      }

      aseg = *splitseg;
      pa = sorg(*splitseg);
      pb = sdest(*splitseg);

      // Insert the new point p.
      makeshellface(subsegs, &aseg);
      makeshellface(subsegs, &bseg);

      setshvertices(aseg, pa, insertpt, NULL);
      setshvertices(bseg, insertpt, pb, NULL);
      setshellmark(aseg, shellmark(*splitseg));
      setshellmark(bseg, shellmark(*splitseg));
      if (checkconstraints) {
        setareabound(aseg, areabound(*splitseg));
        setareabound(bseg, areabound(*splitseg));
      }
      if (useinsertradius) {
        setfacetindex(aseg, getfacetindex(*splitseg));
        setfacetindex(bseg, getfacetindex(*splitseg));
      }

      // Connect [#, a]<->[a, p].
      senext2(*splitseg, boutseg); // Temporarily use boutseg.
      spivotself(boutseg);
      if (boutseg.sh != NULL) {
        senext2(aseg, aoutseg);
        sbond(boutseg, aoutseg);
      }
      // Connect [p, b]<->[b, #].
      senext(*splitseg, aoutseg);
      spivotself(aoutseg);
      if (aoutseg.sh != NULL) {
        senext(bseg, boutseg);
        sbond(boutseg, aoutseg);
      }
      // Connect [a, p] <-> [p, b].
      senext(aseg, aoutseg);
      senext2(bseg, boutseg);
      sbond(aoutseg, boutseg);

      // Connect subsegs [a, p] and [p, b] to adjacent new subfaces.
      // Although the degenerated new faces have been squeezed. They still
      //   hold the connections to the actual new faces.
      for (i = 0; i < cavesegshlist->objects; i++) {
        parysh = (face *) fastlookup(cavesegshlist, i);
        spivot(*parysh, neighsh);
        // neighsh is a degenerated new face.
        if (sorg(neighsh) != pa) {
          sesymself(neighsh);
        }
        senext2(neighsh, newsh);
        spivotself(newsh); // The edge [p, a] in newsh
        ssbond(newsh, aseg);
        senext(neighsh, newsh);
        spivotself(newsh); // The edge [b, p] in newsh
        ssbond(newsh, bseg);
      }


      // Let the point remember the segment it lies on.
      if (pointtype(insertpt) == FREESEGVERTEX) {
        setpoint2sh(insertpt, sencode(aseg));
      }
      // Update the point-to-seg map.
      if (pointtype(pa) == FREESEGVERTEX) {
        setpoint2sh(pa, sencode(aseg));
      }
      if (pointtype(pb) == FREESEGVERTEX) {
        setpoint2sh(pb, sencode(bseg));
      }
    } // if ((splitseg != NULL) && (splitseg->sh != NULL))

    // Delete all degenerated new faces.
    for (i = 0; i < cavesegshlist->objects; i++) {
      parysh = (face *) fastlookup(cavesegshlist, i);
      spivotself(*parysh);
      if (sapex(*parysh) == insertpt) {
        shellfacedealloc(subfaces, parysh->sh);
      }
    }
    cavesegshlist->restart();

    if ((splitseg != NULL) && (splitseg->sh != NULL)) {
      // Return the two new subsegments (for further process).
      //   Re-use 'cavesegshlist'.
      cavesegshlist->newindex((void **) &parysh);
      *parysh = aseg;
      cavesegshlist->newindex((void **) &parysh);
      *parysh = bseg;
    }
  } // if (loc == ONEDGE)


  return (int) loc;
}

int meshGRegionBoundaryRecovery::sremovevertex(point delpt, face* parentsh,
  face* parentseg, int lawson)
{
  face flipfaces[4], spinsh, *parysh;
  point pa, pb, pc, pd;
  REAL ori1, ori2;
  int it, i, j;

  if (parentseg != NULL) {
    // 'delpt' (p) should be a Steiner point inserted in a segment [a,b],
    //   where 'parentseg' should be [p,b]. Find the segment [a,p].
    face startsh, neighsh, nextsh;
    face abseg, prevseg, checkseg;
    face adjseg1, adjseg2;
    face fakesh;
    senext2(*parentseg, prevseg);
    spivotself(prevseg);
    prevseg.shver = 0;
    assert(sdest(prevseg) == delpt);
    // Restore the original segment [a,b].
    pa = sorg(prevseg);
    pb = sdest(*parentseg);
    if (b->verbose > 2) {
      printf("      Remove vertex %d from segment [%d, %d].\n",
             pointmark(delpt), pointmark(pa), pointmark(pb));
    }
    makeshellface(subsegs, &abseg);
    setshvertices(abseg, pa, pb, NULL);
    setshellmark(abseg, shellmark(*parentseg));
    if (checkconstraints) {
      setareabound(abseg, areabound(*parentseg));
    }
    if (useinsertradius) {
      setfacetindex(abseg, getfacetindex(*parentseg));
    }
    // Connect [#, a]<->[a, b].
    senext2(prevseg, adjseg1);
    spivotself(adjseg1);
    if (adjseg1.sh != NULL) {
      adjseg1.shver = 0;
      assert(sdest(adjseg1) == pa);
      senextself(adjseg1);
      senext2(abseg, adjseg2);
      sbond(adjseg1, adjseg2);
    }
    // Connect [a, b]<->[b, #].
    senext(*parentseg, adjseg1);
    spivotself(adjseg1);
    if (adjseg1.sh != NULL) {
      adjseg1.shver = 0;
      assert(sorg(adjseg1) == pb);
      senext2self(adjseg1);
      senext(abseg, adjseg2);
      sbond(adjseg1, adjseg2);
    }
    // Update the point-to-segment map.
    setpoint2sh(pa, sencode(abseg));
    setpoint2sh(pb, sencode(abseg));

    // Get the faces in face ring at segment [p, b].
    //   Re-use array 'caveshlist'.
    spivot(*parentseg, *parentsh);
    if (parentsh->sh != NULL) {
      spinsh = *parentsh;
      while (1) {
        // Save this face in list.
        caveshlist->newindex((void **) &parysh);
        *parysh = spinsh;
        // Go to the next face in the ring.
        spivotself(spinsh);
        if (spinsh.sh == parentsh->sh) break;
      }
    }

    // Create the face ring of the new segment [a,b]. Each face in the ring
    //   is [a,b,p] (degenerated!). It will be removed (automatically).
    for (i = 0; i < caveshlist->objects; i++) {
      parysh = (face *) fastlookup(caveshlist, i);
      startsh = *parysh;
      if (sorg(startsh) != delpt) {
        sesymself(startsh);
        assert(sorg(startsh) == delpt);
      }
      // startsh is [p, b, #1], find the subface [a, p, #2].
      neighsh = startsh;
      while (1) {
        senext2self(neighsh);
        sspivot(neighsh, checkseg);
        if (checkseg.sh != NULL) {
          // It must be the segment [a, p].
          assert(checkseg.sh == prevseg.sh);
          break;
        }
        spivotself(neighsh);
        assert(neighsh.sh != NULL);
        if (sorg(neighsh) != delpt) sesymself(neighsh);
      }
      // Now neighsh is [a, p, #2].
      if (neighsh.sh != startsh.sh) {
        // Detach the two subsegments [a,p] and [p,b] from subfaces.
        ssdissolve(startsh);
        ssdissolve(neighsh);
        // Create a degenerated subface [a,b,p]. It is used to: (1) hold the
        //   new segment [a,b]; (2) connect to the two adjacent subfaces
        //   [p,b,#] and [a,p,#].
        makeshellface(subfaces, &fakesh);
        setshvertices(fakesh, pa, pb, delpt);
        setshellmark(fakesh, shellmark(startsh));
        // Connect fakesh to the segment [a,b].
        ssbond(fakesh, abseg);
        // Connect fakesh to adjacent subfaces: [p,b,#1] and [a,p,#2].
        senext(fakesh, nextsh);
        sbond(nextsh, startsh);
        senext2(fakesh, nextsh);
        sbond(nextsh, neighsh);
        smarktest(fakesh); // Mark it as faked.
      } else {
        // Special case. There exists already a degenerated face [a,b,p]!
        //   There is no need to create a faked subface here.
        senext2self(neighsh); // [a,b,p]
        assert(sapex(neighsh) == delpt);
        // Since we will re-connect the face ring using the faked subfaces.
        //   We put the adjacent face of [a,b,p] to the list.
        spivot(neighsh, startsh); // The original adjacent subface.
        if (sorg(startsh) != pa) sesymself(startsh);
        sdissolve(startsh);
        // Connect fakesh to the segment [a,b].
        ssbond(startsh, abseg);
        fakesh = startsh; // Do not mark it!
        // Delete the degenerated subface.
        shellfacedealloc(subfaces, neighsh.sh);
      }
      // Save the fakesh in list (for re-creating the face ring).
      cavesegshlist->newindex((void **) &parysh);
      *parysh = fakesh;
    } // i
    caveshlist->restart();

    // Re-create the face ring.
    if (cavesegshlist->objects > 1) {
      for (i = 0; i < cavesegshlist->objects; i++) {
        parysh = (face *) fastlookup(cavesegshlist, i);
        fakesh = *parysh;
        // Get the next face in the ring.
        j = (i + 1) % cavesegshlist->objects;
        parysh = (face *) fastlookup(cavesegshlist, j);
        nextsh = *parysh;
        sbond1(fakesh, nextsh);
      }
    }

    // Delete the two subsegments containing p.
    shellfacedealloc(subsegs, parentseg->sh);
    shellfacedealloc(subsegs, prevseg.sh);
    // Return the new segment.
    *parentseg = abseg;
  } else {
    // p is inside the surface.
    if (b->verbose > 2) {
      printf("      Remove vertex %d from surface.\n", pointmark(delpt));
    }
    assert(sorg(*parentsh) == delpt);
    // Let 'delpt' be its apex.
    senextself(*parentsh);
    // For unifying the code, we add parentsh to list.
    cavesegshlist->newindex((void **) &parysh);
    *parysh = *parentsh;
  }

  // Remove the point (p).

  for (it = 0; it < cavesegshlist->objects; it++) {
    parentsh = (face *) fastlookup(cavesegshlist, it); // [a,b,p]
    senextself(*parentsh); // [b,p,a].
    spivotself(*parentsh);
    if (sorg(*parentsh) != delpt) sesymself(*parentsh);
    // now parentsh is [p,b,#].
    if (sorg(*parentsh) != delpt) {
      // The vertex has already been removed in above special case.
      assert(!smarktested(*parentsh));
      continue;
    }

    while (1) {
      // Initialize the flip edge list. Re-use 'caveshlist'.
      spinsh = *parentsh; // [p, b, #]
      while (1) {
        caveshlist->newindex((void **) &parysh);
        *parysh = spinsh;
        senext2self(spinsh);
        spivotself(spinsh);
        assert(spinsh.sh != NULL);
        if (spinsh.sh == parentsh->sh) break;
        if (sorg(spinsh) != delpt) sesymself(spinsh);
        assert(sorg(spinsh) == delpt);
      } // while (1)

      if (caveshlist->objects == 3) {
        // Delete the point by a 3-to-1 flip.
        for (i = 0; i < 3; i++) {
          parysh = (face *) fastlookup(caveshlist, i);
          flipfaces[i] = *parysh;
        }
        flip31(flipfaces, lawson);
        for (i = 0; i < 3; i++) {
          shellfacedealloc(subfaces, flipfaces[i].sh);
        }
        caveshlist->restart();
        // Save the new subface.
        caveshbdlist->newindex((void **) &parysh);
        *parysh = flipfaces[3];
        // The vertex is removed.
        break;
      }

      // Search an edge to flip.
      for (i = 0; i < caveshlist->objects; i++) {
        parysh = (face *) fastlookup(caveshlist, i);
        flipfaces[0] = *parysh;
        spivot(flipfaces[0], flipfaces[1]);
        if (sorg(flipfaces[0]) != sdest(flipfaces[1]))
          sesymself(flipfaces[1]);
        // Skip this edge if it belongs to a faked subface.
        if (!smarktested(flipfaces[0]) && !smarktested(flipfaces[1])) {
          pa = sorg(flipfaces[0]);
          pb = sdest(flipfaces[0]);
          pc = sapex(flipfaces[0]);
          pd = sapex(flipfaces[1]);
          calculateabovepoint4(pa, pb, pc, pd);
          // Check if a 2-to-2 flip is possible.
          ori1 = orient3d(pc, pd, dummypoint, pa);
          ori2 = orient3d(pc, pd, dummypoint, pb);
          if (ori1 * ori2 < 0) {
            // A 2-to-2 flip is found.
            flip22(flipfaces, lawson, 0);
            // The i-th edge is flipped. The i-th and (i-1)-th subfaces are
            //   changed. The 'flipfaces[1]' contains p as its apex.
            senext2(flipfaces[1], *parentsh);
            // Save the new subface.
            caveshbdlist->newindex((void **) &parysh);
            *parysh = flipfaces[0];
            break;
          }
        } //
      } // i

      if (i == caveshlist->objects) {
        // This can happen only if there are 4 edges at p, and they are
        //   orthogonal to each other, see Fig. 2010-11-01.
        assert(caveshlist->objects == 4);
        // Do a flip22 and a flip31 to remove p.
        parysh = (face *) fastlookup(caveshlist, 0);
        flipfaces[0] = *parysh;
        spivot(flipfaces[0], flipfaces[1]);
        if (sorg(flipfaces[0]) != sdest(flipfaces[1])) {
          sesymself(flipfaces[1]);
        }
        flip22(flipfaces, lawson, 0);
        senext2(flipfaces[1], *parentsh);
        // Save the new subface.
        caveshbdlist->newindex((void **) &parysh);
        *parysh = flipfaces[0];
      }

      // The edge list at p are changed.
      caveshlist->restart();
    } // while (1)

  } // it

  cavesegshlist->restart();

  if (b->verbose > 2) {
    printf("      Created %ld new subfaces.\n", caveshbdlist->objects);
  }


  if (lawson) {
    lawsonflip();
  }

  return 0;
}

enum meshGRegionBoundaryRecovery::locateresult
  meshGRegionBoundaryRecovery::slocate(point searchpt, face* searchsh,
  int aflag, int cflag, int rflag)
{
  face neighsh;
  point pa, pb, pc;
  enum locateresult loc;
  enum {MOVE_BC, MOVE_CA} nextmove;
  REAL ori, ori_bc, ori_ca;
  int i;

  pa = sorg(*searchsh);
  pb = sdest(*searchsh);
  pc = sapex(*searchsh);

  if (!aflag) {
    // No above point is given. Calculate an above point for this facet.
    calculateabovepoint4(pa, pb, pc, searchpt);
  }

  // 'dummypoint' is given. Make sure it is above [a,b,c]
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

  pc = sapex(*searchsh);

  if (pc == searchpt) {
    senext2self(*searchsh);
    return ONVERTEX;
  }

  while (1) {

    ori_bc = orient3d(pb, pc, dummypoint, searchpt);
    ori_ca = orient3d(pc, pa, dummypoint, searchpt);

    if (ori_bc < 0) {
      if (ori_ca < 0) { // (--)
        // Any of the edges is a viable move.
        if (randomnation(2)) {
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
            loc = ONFACE;  // Inside [a, b, c].
            break;
          } else { // (+0)
            senext2self(*searchsh); // On edge [c, a].
            loc = ONEDGE;
            break;
          }
        } else { // ori_bc == 0
          if (ori_ca > 0) { // (0+)
            senextself(*searchsh); // On edge [b, c].
            loc = ONEDGE;
            break;
          } else { // (00)
            // p is coincident with vertex c.
            senext2self(*searchsh);
            return ONVERTEX;
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
      // NON-convex case. Check if we will cross a boundary.
      if (isshsubseg(*searchsh)) {
        return ENCSEGMENT;
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
    pc = sapex(*searchsh);

    if (pc == searchpt) {
      senext2self(*searchsh);
      return ONVERTEX;
    }

  } // while (1)

  // assert(loc == ONFACE || loc == ONEDGE);


  if (rflag) {
    // Round the locate result before return.
    REAL n[3], area_abc, area_abp, area_bcp, area_cap;

    pa = sorg(*searchsh);
    pb = sdest(*searchsh);
    pc = sapex(*searchsh);

    facenormal(pa, pb, pc, n, 1, NULL);
    area_abc = sqrt(dot(n, n));

    facenormal(pb, pc, searchpt, n, 1, NULL);
    area_bcp = sqrt(dot(n, n));
    if ((area_bcp / area_abc) < b->epsilon) {
      area_bcp = 0; // Rounding.
    }

    facenormal(pc, pa, searchpt, n, 1, NULL);
    area_cap = sqrt(dot(n, n));
    if ((area_cap / area_abc) < b->epsilon) {
      area_cap = 0; // Rounding
    }

    if ((loc == ONFACE) || (loc == OUTSIDE)) {
      facenormal(pa, pb, searchpt, n, 1, NULL);
      area_abp = sqrt(dot(n, n));
      if ((area_abp / area_abc) < b->epsilon) {
        area_abp = 0; // Rounding
      }
    } else { // loc == ONEDGE
      area_abp = 0;
    }

    if (area_abp == 0) {
      if (area_bcp == 0) {
        assert(area_cap != 0);
        senextself(*searchsh);
        loc = ONVERTEX; // p is close to b.
      } else {
        if (area_cap == 0) {
          loc = ONVERTEX; // p is close to a.
        } else {
          loc = ONEDGE; // p is on edge [a,b].
        }
      }
    } else if (area_bcp == 0) {
      if (area_cap == 0) {
        senext2self(*searchsh);
        loc = ONVERTEX; // p is close to c.
      } else {
        senextself(*searchsh);
        loc = ONEDGE; // p is on edge [b,c].
      }
    } else if (area_cap == 0) {
      senext2self(*searchsh);
      loc = ONEDGE; // p is on edge [c,a].
    } else {
      loc = ONFACE; // p is on face [a,b,c].
    }
  } // if (rflag)

  return loc;
}

////                                                                       ////
////                                                                       ////
//// surface_cxx //////////////////////////////////////////////////////////////

//// steiner_cxx //////////////////////////////////////////////////////////////
////                                                                       ////
////                                                                       ////

enum meshGRegionBoundaryRecovery::interresult
  meshGRegionBoundaryRecovery::finddirection(triface* searchtet, point endpt)
{
  triface neightet;
  point pa, pb, pc, pd;
  enum {HMOVE, RMOVE, LMOVE} nextmove;
  REAL hori, rori, lori;
  int t1ver;
  int s;

  // The origin is fixed.
  pa = org(*searchtet);
  if ((point) searchtet->tet[7] == dummypoint) {
    // A hull tet. Choose the neighbor of its base face.
    decode(searchtet->tet[3], *searchtet);
    // Reset the origin to be pa.
    if ((point) searchtet->tet[4] == pa) {
      searchtet->ver = 11;
    } else if ((point) searchtet->tet[5] == pa) {
      searchtet->ver = 3;
    } else if ((point) searchtet->tet[6] == pa) {
      searchtet->ver = 7;
    } else {
      assert((point) searchtet->tet[7] == pa);
      searchtet->ver = 0;
    }
  }

  pb = dest(*searchtet);
  // Check whether the destination or apex is 'endpt'.
  if (pb == endpt) {
    // pa->pb is the search edge.
    return ACROSSVERT;
  }

  pc = apex(*searchtet);
  if (pc == endpt) {
    // pa->pc is the search edge.
    eprevesymself(*searchtet);
    return ACROSSVERT;
  }

  // Walk through tets around pa until the right one is found.
  while (1) {

    pd = oppo(*searchtet);
    // Check whether the opposite vertex is 'endpt'.
    if (pd == endpt) {
      // pa->pd is the search edge.
      esymself(*searchtet);
      enextself(*searchtet);
      return ACROSSVERT;
    }
    // Check if we have entered outside of the domain.
    if (pd == dummypoint) {
      // This is possible when the mesh is non-convex.
      assert(nonconvex);
      return ACROSSSUB; // Hit a bounday.
    }

    // Now assume that the base face abc coincides with the horizon plane,
    //   and d lies above the horizon.  The search point 'endpt' may lie
    //   above or below the horizon.  We test the orientations of 'endpt'
    //   with respect to three planes: abc (horizon), bad (right plane),
    //   and acd (left plane).
    hori = orient3d(pa, pb, pc, endpt);
    rori = orient3d(pb, pa, pd, endpt);
    lori = orient3d(pa, pc, pd, endpt);

    // Now decide the tet to move.  It is possible there are more than one
    //   tets are viable moves. Is so, randomly choose one.
    if (hori > 0) {
      if (rori > 0) {
        if (lori > 0) {
          // Any of the three neighbors is a viable move.
          s = randomnation(3);
          if (s == 0) {
            nextmove = HMOVE;
          } else if (s == 1) {
            nextmove = RMOVE;
          } else {
            nextmove = LMOVE;
          }
        } else {
          // Two tets, below horizon and below right, are viable.
          //s = randomnation(2);
          if (randomnation(2)) {
            nextmove = HMOVE;
          } else {
            nextmove = RMOVE;
          }
        }
      } else {
        if (lori > 0) {
          // Two tets, below horizon and below left, are viable.
          //s = randomnation(2);
          if (randomnation(2)) {
            nextmove = HMOVE;
          } else {
            nextmove = LMOVE;
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
          //s = randomnation(2);
          if (randomnation(2)) {
            nextmove = RMOVE;
          } else {
            nextmove = LMOVE;
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
              eprevesymself(*searchtet); // // [a,c,d]
              return ACROSSVERT;
            }
            // pa->'endpt' crosses the edge pb->pc.
            return ACROSSEDGE;
          }
          if (rori == 0) {
            if (lori == 0) {
              // pa->'endpt' is COLLINEAR with pa->pd.
              esymself(*searchtet); // face bad.
              enextself(*searchtet); // face [a,d,b]
              return ACROSSVERT;
            }
            // pa->'endpt' crosses the edge pb->pd.
            esymself(*searchtet); // face bad.
            enextself(*searchtet); // face adb
            return ACROSSEDGE;
          }
          if (lori == 0) {
            // pa->'endpt' crosses the edge pc->pd.
            eprevesymself(*searchtet); // [a,c,d]
            return ACROSSEDGE;
          }
          // pa->'endpt' crosses the face bcd.
          return ACROSSFACE;
        }
      }
    }

    // Move to the next tet, fix pa as its origin.
    if (nextmove == RMOVE) {
      fnextself(*searchtet);
    } else if (nextmove == LMOVE) {
      eprevself(*searchtet);
      fnextself(*searchtet);
      enextself(*searchtet);
    } else { // HMOVE
      fsymself(*searchtet);
      enextself(*searchtet);
    }
    assert(org(*searchtet) == pa);
    pb = dest(*searchtet);
    pc = apex(*searchtet);

  } // while (1)
}

int meshGRegionBoundaryRecovery::checkflipeligibility(int fliptype, point pa,
  point pb, point pc, point pd, point pe, int level, int edgepivot,
  flipconstraints* fc)
{
  point tmppts[3];
  enum interresult dir;
  int types[2], poss[4];
  int intflag;
  int rejflag = 0;
  int i;

  if (fc->seg[0] != NULL) {
    // A constraining edge is given (e.g., for edge recovery).
    if (fliptype == 1) {
      // A 2-to-3 flip: [a,b,c] => [e,d,a], [e,d,b], [e,d,c].
      tmppts[0] = pa;
      tmppts[1] = pb;
      tmppts[2] = pc;
      for (i = 0; i < 3 && !rejflag; i++) {
        if (tmppts[i] != dummypoint) {
          // Test if the face [e,d,#] intersects the edge.
          intflag = tri_edge_test(pe, pd, tmppts[i], fc->seg[0], fc->seg[1],
                                  NULL, 1, types, poss);
          if (intflag == 2) {
            // They intersect at a single point.
            dir = (enum interresult) types[0];
            if (dir == ACROSSFACE) {
              // The interior of [e,d,#] intersect the segment.
              rejflag = 1;
            } else if (dir == ACROSSEDGE) {
              if (poss[0] == 0) {
                // The interior of [e,d] intersect the segment.
                // Since [e,d] is the newly created edge. Reject this flip.
                rejflag = 1;
              }
            }
          } else if (intflag == 4) {
            // They may intersect at either a point or a line segment.
            dir = (enum interresult) types[0];
            if (dir == ACROSSEDGE) {
              if (poss[0] == 0) {
                // The interior of [e,d] intersect the segment.
                // Since [e,d] is the newly created edge. Reject this flip.
                rejflag = 1;
              }
            }
          }
        } // if (tmppts[0] != dummypoint)
      } // i
    } else if (fliptype == 2) {
      // A 3-to-2 flip: [e,d,a], [e,d,b], [e,d,c] => [a,b,c]
      if (pc != dummypoint) {
        // Check if the new face [a,b,c] intersect the edge in its interior.
        intflag = tri_edge_test(pa, pb, pc, fc->seg[0], fc->seg[1], NULL,
                                1, types, poss);
        if (intflag == 2) {
          // They intersect at a single point.
          dir = (enum interresult) types[0];
          if (dir == ACROSSFACE) {
            // The interior of [a,b,c] intersect the segment.
            rejflag = 1; // Do not flip.
          }
        } else if (intflag == 4) {
          // [a,b,c] is coplanar with the edge.
          dir = (enum interresult) types[0];
          if (dir == ACROSSEDGE) {
            // The boundary of [a,b,c] intersect the segment.
            rejflag = 1; // Do not flip.
          }
        }
      } // if (pc != dummypoint)
    }
  } // if (fc->seg[0] != NULL)

  if ((fc->fac[0] != NULL) && !rejflag) {
    // A constraining face is given (e.g., for face recovery).
    if (fliptype == 1) {
      // A 2-to-3 flip.
      // Test if the new edge [e,d] intersects the face.
      intflag = tri_edge_test(fc->fac[0], fc->fac[1], fc->fac[2], pe, pd,
                              NULL, 1, types, poss);
      if (intflag == 2) {
        // They intersect at a single point.
        dir = (enum interresult) types[0];
        if (dir == ACROSSFACE) {
          rejflag = 1;
        } else if (dir == ACROSSEDGE) {
          rejflag = 1;
        }
      } else if (intflag == 4) {
        // The edge [e,d] is coplanar with the face.
        // There may be two intersections.
        for (i = 0; i < 2 && !rejflag; i++) {
          dir = (enum interresult) types[i];
          if (dir == ACROSSFACE) {
            rejflag = 1;
          } else if (dir == ACROSSEDGE) {
            rejflag = 1;
          }
        }
      }
    } // if (fliptype == 1)
  } // if (fc->fac[0] != NULL)

  if ((fc->remvert != NULL) && !rejflag) {
    // The vertex is going to be removed. Do not create a new edge which
    //   contains this vertex.
    if (fliptype == 1) {
      // A 2-to-3 flip.
      if ((pd == fc->remvert) || (pe == fc->remvert)) {
        rejflag = 1;
      }
    }
  }

  if (fc->remove_large_angle && !rejflag) {
    // Remove a large dihedral angle. Do not create a new small angle.
    REAL cosmaxd = 0, diff;
    if (fliptype == 1) {
      // We assume that neither 'a' nor 'b' is dummypoint.
      assert((pa != dummypoint) && (pb != dummypoint)); // SELF_CHECK
      // A 2-to-3 flip: [a,b,c] => [e,d,a], [e,d,b], [e,d,c].
      // The new tet [e,d,a,b] will be flipped later. Only two new tets:
      //   [e,d,b,c] and [e,d,c,a] need to be checked.
      if ((pc != dummypoint) && (pe != dummypoint) && (pd != dummypoint)) {
        // Get the largest dihedral angle of [e,d,b,c].
        tetalldihedral(pe, pd, pb, pc, NULL, &cosmaxd, NULL);
        diff = cosmaxd - fc->cosdihed_in;
        if (fabs(diff/fc->cosdihed_in) < b->epsilon) diff = 0.0; // Rounding.
        if (diff <= 0) { //if (cosmaxd <= fc->cosdihed_in) {
          rejflag = 1;
        } else {
          // Record the largest new angle.
          if (cosmaxd < fc->cosdihed_out) {
            fc->cosdihed_out = cosmaxd;
          }
          // Get the largest dihedral angle of [e,d,c,a].
          tetalldihedral(pe, pd, pc, pa, NULL, &cosmaxd, NULL);
          diff = cosmaxd - fc->cosdihed_in;
          if (fabs(diff/fc->cosdihed_in) < b->epsilon) diff = 0.0; // Rounding.
          if (diff <= 0) { //if (cosmaxd <= fc->cosdihed_in) {
            rejflag = 1;
          } else {
            // Record the largest new angle.
            if (cosmaxd < fc->cosdihed_out) {
              fc->cosdihed_out = cosmaxd;
            }
          }
        }
      } // if (pc != dummypoint && ...)
    } else if (fliptype == 2) {
      // A 3-to-2 flip: [e,d,a], [e,d,b], [e,d,c] => [a,b,c]
      // We assume that neither 'e' nor 'd' is dummypoint.
      assert((pe != dummypoint) && (pd != dummypoint)); // SELF_CHECK
      if (level == 0) {
        // Both new tets [a,b,c,d] and [b,a,c,e] are new tets.
        if ((pa != dummypoint) && (pb != dummypoint) && (pc != dummypoint)) {
          // Get the largest dihedral angle of [a,b,c,d].
          tetalldihedral(pa, pb, pc, pd, NULL, &cosmaxd, NULL);
          diff = cosmaxd - fc->cosdihed_in;
          if (fabs(diff/fc->cosdihed_in) < b->epsilon) diff = 0.0; // Rounding
          if (diff <= 0) { //if (cosmaxd <= fc->cosdihed_in) {
            rejflag = 1;
          } else {
            // Record the largest new angle.
            if (cosmaxd < fc->cosdihed_out) {
              fc->cosdihed_out = cosmaxd;
            }
            // Get the largest dihedral angle of [b,a,c,e].
            tetalldihedral(pb, pa, pc, pe, NULL, &cosmaxd, NULL);
            diff = cosmaxd - fc->cosdihed_in;
            if (fabs(diff/fc->cosdihed_in) < b->epsilon) diff = 0.0;// Rounding
            if (diff <= 0) { //if (cosmaxd <= fc->cosdihed_in) {
              rejflag = 1;
            } else {
              // Record the largest new angle.
              if (cosmaxd < fc->cosdihed_out) {
                fc->cosdihed_out = cosmaxd;
              }
            }
          }
        }
      } else { // level > 0
        assert(edgepivot != 0);
        if (edgepivot == 1) {
          // The new tet [a,b,c,d] will be flipped. Only check [b,a,c,e].
          if ((pa != dummypoint) && (pb != dummypoint) && (pc != dummypoint)) {
            // Get the largest dihedral angle of [b,a,c,e].
            tetalldihedral(pb, pa, pc, pe, NULL, &cosmaxd, NULL);
            diff = cosmaxd - fc->cosdihed_in;
            if (fabs(diff/fc->cosdihed_in) < b->epsilon) diff = 0.0;// Rounding
            if (diff <= 0) { //if (cosmaxd <= fc->cosdihed_in) {
              rejflag = 1;
            } else {
              // Record the largest new angle.
              if (cosmaxd < fc->cosdihed_out) {
                fc->cosdihed_out = cosmaxd;
              }
            }
          }
        } else {
          assert(edgepivot == 2);
          // The new tet [b,a,c,e] will be flipped. Only check [a,b,c,d].
          if ((pa != dummypoint) && (pb != dummypoint) && (pc != dummypoint)) {
            // Get the largest dihedral angle of [b,a,c,e].
            tetalldihedral(pa, pb, pc, pd, NULL, &cosmaxd, NULL);
            diff = cosmaxd - fc->cosdihed_in;
            if (fabs(diff/fc->cosdihed_in) < b->epsilon) diff = 0.0;// Rounding
            if (diff <= 0) { //if (cosmaxd <= fc->cosdihed_in) {
              rejflag = 1;
            } else {
              // Record the largest new angle.
              if (cosmaxd < fc->cosdihed_out) {
                fc->cosdihed_out = cosmaxd;
              }
            }
          }
        } // edgepivot
      } // level
    }
  }

  return rejflag;
}

int meshGRegionBoundaryRecovery::removeedgebyflips(triface *flipedge, flipconstraints* fc)
{
  triface *abtets, spintet;
  int t1ver;
  int n, nn, i;


  if (checksubsegflag) {
    // Do not flip a segment.
    if (issubseg(*flipedge)) {
      if (fc->collectencsegflag) {
        face checkseg, *paryseg;
        tsspivot1(*flipedge, checkseg);
        if (!sinfected(checkseg)) {
          // Queue this segment in list.
          sinfect(checkseg);
          caveencseglist->newindex((void **) &paryseg);
          *paryseg = checkseg;
        }
      }
      return 0;
    }
  }

  // Count the number of tets at edge [a,b].
  n = 0;
  spintet = *flipedge;
  while (1) {
    n++;
    fnextself(spintet);
    if (spintet.tet == flipedge->tet) break;
  }
  assert(n >= 3);

  if ((b->flipstarsize > 0) && (n > b->flipstarsize)) {
    // The star size exceeds the limit.
    return 0; // Do not flip it.
  }

  // Allocate spaces.
  abtets = new triface[n];
  // Collect the tets at edge [a,b].
  spintet = *flipedge;
  i = 0;
  while (1) {
    abtets[i] = spintet;
    setelemcounter(abtets[i], 1);
    i++;
    fnextself(spintet);
    if (spintet.tet == flipedge->tet) break;
  }


  // Try to flip the edge (level = 0, edgepivot = 0).
  nn = flipnm(abtets, n, 0, 0, fc);


  if (nn > 2) {
    // Edge is not flipped. Unmarktest the remaining tets in Star(ab).
    for (i = 0; i < nn; i++) {
      setelemcounter(abtets[i], 0);
    }
    // Restore the input edge (needed by Lawson's flip).
    *flipedge = abtets[0];
  }

  // Release the temporary allocated spaces.
  // NOTE: fc->unflip must be 0.
  int bakunflip = fc->unflip;
  fc->unflip = 0;
  flipnm_post(abtets, n, nn, 0, fc);
  fc->unflip = bakunflip;

  delete [] abtets;

  return nn;
}

int meshGRegionBoundaryRecovery::removefacebyflips(triface *flipface, flipconstraints* fc)
{
  if (checksubfaceflag) {
    if (issubface(*flipface)) {
      return 0;
    }
  }

  triface fliptets[3], flipedge;
  point pa, pb, pc, pd, pe;
  REAL ori;
  int reducflag = 0;

  fliptets[0] = *flipface;
  fsym(*flipface, fliptets[1]);
  pa = org(fliptets[0]);
  pb = dest(fliptets[0]);
  pc = apex(fliptets[0]);
  pd = oppo(fliptets[0]);
  pe = oppo(fliptets[1]);

  ori = orient3d(pa, pb, pd, pe);
  if (ori > 0) {
    ori = orient3d(pb, pc, pd, pe);
    if (ori > 0) {
      ori = orient3d(pc, pa, pd, pe);
      if (ori > 0) {
        // Found a 2-to-3 flip.
        reducflag = 1;
      } else {
        eprev(*flipface, flipedge); // [c,a]
      }
    } else {
      enext(*flipface, flipedge); // [b,c]
    }
  } else {
    flipedge = *flipface; // [a,b]
  }

  if (reducflag) {
    // A 2-to-3 flip is found.
    flip23(fliptets, 0, fc);
    return 1;
  } else {
    // Try to flip the selected edge of this face.
    if (removeedgebyflips(&flipedge, fc) == 2) {
      return 1;
    }
  }

  // Face is not removed.
  return 0;
}

int meshGRegionBoundaryRecovery::recoveredgebyflips(point startpt,
  point endpt, triface* searchtet, int fullsearch)
{
  flipconstraints fc;
  enum interresult dir;

  fc.seg[0] = startpt;
  fc.seg[1] = endpt;
  fc.checkflipeligibility = 1;

  // The mainloop of the edge reocvery.
  while (1) { // Loop I

    // Search the edge from 'startpt'.
    point2tetorg(startpt, *searchtet);
    dir = finddirection(searchtet, endpt);
    if (dir == ACROSSVERT) {
      if (dest(*searchtet) == endpt) {
        return 1; // Edge is recovered.
      } else {
        terminateBoundaryRecovery(this, 3); // // It may be a PLC problem.
      }
    }

    // The edge is missing.

    // Try to flip the first intersecting face/edge.
    enextesymself(*searchtet); // Go to the opposite face.
    if (dir == ACROSSFACE) {
      // A face is intersected with the segment. Try to flip it.
      if (removefacebyflips(searchtet, &fc)) {
        continue;
      }
    } else if (dir == ACROSSEDGE) {
      // An edge is intersected with the segment. Try to flip it.
      if (removeedgebyflips(searchtet, &fc) == 2) {
        continue;
      }
    } else {
      terminateBoundaryRecovery(this, 3); // It may be a PLC problem.
    }

    // The edge is missing.

    if (fullsearch) {
      // Try to flip one of the faces/edges which intersects the edge.
      triface neightet, spintet;
      point pa, pb, pc, pd;
      badface bakface;
      enum interresult dir1;
      int types[2], poss[4], pos = 0;
      int success = 0;
      int t1ver;
      int i, j;

      // Loop through the sequence of intersecting faces/edges from
      //   'startpt' to 'endpt'.
      point2tetorg(startpt, *searchtet);
      dir = finddirection(searchtet, endpt);
      //assert(dir != ACROSSVERT);

      // Go to the face/edge intersecting the searching edge.
      enextesymself(*searchtet); // Go to the opposite face.
      // This face/edge has been tried in previous step.

      while (1) { // Loop I-I

        // Find the next intersecting face/edge.
        fsymself(*searchtet);
        if (dir == ACROSSFACE) {
          neightet = *searchtet;
          j = (neightet.ver & 3); // j is the current face number.
          for (i = j + 1; i < j + 4; i++) {
            neightet.ver = (i % 4);
            pa = org(neightet);
            pb = dest(neightet);
            pc = apex(neightet);
            pd = oppo(neightet); // The above point.
            if (tri_edge_test(pa,pb,pc,startpt,endpt, pd, 1, types, poss)) {
              dir = (enum interresult) types[0];
              pos = poss[0];
              break;
            } else {
              dir = DISJOINT;
              pos = 0;
            }
          } // i
          // There must be an intersection face/edge.
          assert(dir != DISJOINT);  // SELF_CHECK
        } else {
          assert(dir == ACROSSEDGE);
          while (1) { // Loop I-I-I
            // Check the two opposite faces (of the edge) in 'searchtet'.
            for (i = 0; i < 2; i++) {
              if (i == 0) {
                enextesym(*searchtet, neightet);
              } else {
                eprevesym(*searchtet, neightet);
              }
              pa = org(neightet);
              pb = dest(neightet);
              pc = apex(neightet);
              pd = oppo(neightet); // The above point.
              if (tri_edge_test(pa,pb,pc,startpt,endpt,pd,1, types, poss)) {
                dir = (enum interresult) types[0];
                pos = poss[0];
                break; // for loop
              } else {
                dir = DISJOINT;
                pos = 0;
              }
            } // i
            if (dir != DISJOINT) {
              // Find an intersection face/edge.
              break;  // Loop I-I-I
            }
            // No intersection. Rotate to the next tet at the edge.
            fnextself(*searchtet);
          } // while (1) // Loop I-I-I
        }

        // Adjust to the intersecting edge/vertex.
        for (i = 0; i < pos; i++) {
          enextself(neightet);
        }

        if (dir == SHAREVERT) {
          // Check if we have reached the 'endpt'.
          pd = org(neightet);
          if (pd == endpt) {
            // Failed to recover the edge.
            break; // Loop I-I
          } else {
            // We need to further check this case. It might be a PLC problem
            //   or a Steiner point that was added at a bad location.
            assert(0);
          }
        }

        // The next to be flipped face/edge.
        *searchtet = neightet;

        // Bakup this face (tetrahedron).
        bakface.forg = org(*searchtet);
        bakface.fdest = dest(*searchtet);
        bakface.fapex = apex(*searchtet);
        bakface.foppo = oppo(*searchtet);

        // Try to flip this intersecting face/edge.
        if (dir == ACROSSFACE) {
          if (removefacebyflips(searchtet, &fc)) {
            success = 1;
            break; // Loop I-I
          }
        } else if (dir == ACROSSEDGE) {
          if (removeedgebyflips(searchtet, &fc) == 2) {
            success = 1;
            break; // Loop I-I
          }
        } else {
          assert(0); // A PLC problem.
        }

        // The face/edge is not flipped.
        if ((searchtet->tet == NULL) ||
            (org(*searchtet) != bakface.forg) ||
            (dest(*searchtet) != bakface.fdest) ||
            (apex(*searchtet) != bakface.fapex) ||
            (oppo(*searchtet) != bakface.foppo)) {
          // 'searchtet' was flipped. We must restore it.
          point2tetorg(bakface.forg, *searchtet);
          dir1 = finddirection(searchtet, bakface.fdest);
          if (dir1 == ACROSSVERT) {
            assert(dest(*searchtet) == bakface.fdest);
            spintet = *searchtet;
            while (1) {
              if (apex(spintet) == bakface.fapex) {
                // Found the face.
                *searchtet = spintet;
                break;
              }
              fnextself(spintet);
              if (spintet.tet == searchtet->tet) {
                searchtet->tet = NULL;
                break; // Not find.
              }
	        } // while (1)
            if (searchtet->tet != NULL) {
              if (oppo(*searchtet) != bakface.foppo) {
                fsymself(*searchtet);
                if (oppo(*searchtet) != bakface.foppo) {
                  assert(0); // Check this case.
                  searchtet->tet = NULL;
                  break; // Not find.
                }
              }
            }
          } else {
            searchtet->tet = NULL; // Not find.
          }
          if (searchtet->tet == NULL) {
            success = 0; // This face/edge has been destroyed.
            break; // Loop I-I
          }
        }
      } // while (1) // Loop I-I

      if (success) {
        // One of intersecting faces/edges is flipped.
        continue;
      }

    } // if (fullsearch)

    // The edge is missing.
    break; // Loop I

  } // while (1) // Loop I

  return 0;
}

int meshGRegionBoundaryRecovery::
  add_steinerpt_in_schoenhardtpoly(triface *abtets, int n, int chkencflag)
{
  triface worktet, *parytet;
  triface faketet1, faketet2;
  point pc, pd, steinerpt;
  insertvertexflags ivf;
  optparameters opm;
  REAL vcd[3], sampt[3], smtpt[3];
  REAL maxminvol = 0.0, minvol = 0.0, ori;
  int success, maxidx = 0;
  int it, i;


  pc = apex(abtets[0]);   // pc = p0
  pd = oppo(abtets[n-1]); // pd = p_(n-1)


  // Find an optimial point in edge [c,d]. It is visible by all outer faces
  //   of 'abtets', and it maxmizes the min volume.

  // initialize the list of 2n boundary faces.
  for (i = 0; i < n; i++) {
    edestoppo(abtets[i], worktet); // [p_i,p_i+1,a]
    cavetetlist->newindex((void **) &parytet);
    *parytet = worktet;
    eorgoppo(abtets[i], worktet);  // [p_i+1,p_i,b]
    cavetetlist->newindex((void **) &parytet);
    *parytet = worktet;
  }

  int N = 100;
  REAL stepi = 0.01;

  // Search the point along the edge [c,d].
  for (i = 0; i < 3; i++) vcd[i] = pd[i] - pc[i];

  // Sample N points in edge [c,d].
  for (it = 1; it < N; it++) {
    for (i = 0; i < 3; i++) {
      sampt[i] = pc[i] + (stepi * (double) it) * vcd[i];
    }
    for (i = 0; i < cavetetlist->objects; i++) {
      parytet = (triface *) fastlookup(cavetetlist, i);
      ori = orient3d(dest(*parytet), org(*parytet), apex(*parytet), sampt);
      if (i == 0) {
        minvol = ori;
      } else {
        if (minvol > ori) minvol = ori;
      }
    } // i
    if (it == 1) {
      maxminvol = minvol;
      maxidx = it;
    } else {
      if (maxminvol < minvol) {
        maxminvol = minvol;
        maxidx = it;
      }
    }
  } // it

  if (maxminvol <= 0) {
    cavetetlist->restart();
    return 0;
  }

  for (i = 0; i < 3; i++) {
    smtpt[i] = pc[i] + (stepi * (double) maxidx) * vcd[i];
  }

  // Create two faked tets to hold the two non-existing boundary faces:
  //   [d,c,a] and [c,d,b].
  maketetrahedron(&faketet1);
  setvertices(faketet1, pd, pc, org(abtets[0]), dummypoint);
  cavetetlist->newindex((void **) &parytet);
  *parytet = faketet1;
  maketetrahedron(&faketet2);
  setvertices(faketet2, pc, pd, dest(abtets[0]), dummypoint);
  cavetetlist->newindex((void **) &parytet);
  *parytet = faketet2;

  // Point smooth options.
  opm.max_min_volume = 1;
  opm.numofsearchdirs = 20;
  opm.searchstep = 0.001;
  opm.maxiter = 100; // Limit the maximum iterations.
  opm.initval = 0.0; // Initial volume is zero.

  // Try to relocate the point into the inside of the polyhedron.
  success = smoothpoint(smtpt, cavetetlist, 1, &opm);

  if (success) {
    while (opm.smthiter == 100) {
      // It was relocated and the prescribed maximum iteration reached.
      // Try to increase the search stepsize.
      opm.searchstep *= 10.0;
      //opm.maxiter = 100; // Limit the maximum iterations.
      opm.initval = opm.imprval;
      opm.smthiter = 0; // Init.
      smoothpoint(smtpt, cavetetlist, 1, &opm);
    }
  } // if (success)

  // Delete the two faked tets.
  tetrahedrondealloc(faketet1.tet);
  tetrahedrondealloc(faketet2.tet);

  cavetetlist->restart();

  if (!success) {
    return 0;
  }


  // Insert the Steiner point.
  makepoint(&steinerpt, FREEVOLVERTEX);
  for (i = 0; i < 3; i++) steinerpt[i] = smtpt[i];

  // Insert the created Steiner point.
  for (i = 0; i < n; i++) {
    infect(abtets[i]);
    caveoldtetlist->newindex((void **) &parytet);
    *parytet = abtets[i];
  }
  worktet = abtets[0]; // No need point location.
  ivf.iloc = (int) INSTAR;
  ivf.chkencflag = chkencflag;
  ivf.assignmeshsize = b->metric;
  if (ivf.assignmeshsize) {
    // Search the tet containing 'steinerpt' for size interpolation.
    locate(steinerpt, &(abtets[0]));
    worktet = abtets[0];
  }

  // Insert the new point into the tetrahedralization T.
  // Note that T is convex (nonconvex = 0).
  if (insertpoint(steinerpt, &worktet, NULL, NULL, &ivf)) {
    // The vertex has been inserted.
    st_volref_count++;
    if (steinerleft > 0) steinerleft--;
    return 1;
  } else {
    // Not inserted.
    pointdealloc(steinerpt);
    return 0;
  }
}

int meshGRegionBoundaryRecovery::add_steinerpt_in_segment(face* misseg,
  int searchlevel)
{
  triface searchtet;
  face *paryseg, candseg;
  point startpt, endpt, pc, pd;
  flipconstraints fc;
  enum interresult dir;
  REAL P[3], Q[3], tp, tq;
  REAL len, smlen = 0, split = 0, split_q = 0;
  int success;
  int i;

  startpt = sorg(*misseg);
  endpt = sdest(*misseg);

  fc.seg[0] = startpt;
  fc.seg[1] = endpt;
  fc.checkflipeligibility = 1;
  fc.collectencsegflag = 1;

  point2tetorg(startpt, searchtet);
  dir = finddirection(&searchtet, endpt);
  //assert(dir != ACROSSVERT);

  // Try to flip the first intersecting face/edge.
  enextesymself(searchtet); // Go to the opposite face.

  int bak_fliplinklevel = b->fliplinklevel;
  b->fliplinklevel = searchlevel;

  if (dir == ACROSSFACE) {
    // A face is intersected with the segment. Try to flip it.
    success = removefacebyflips(&searchtet, &fc);
    assert(success == 0);
  } else if (dir == ACROSSEDGE) {
    // An edge is intersected with the segment. Try to flip it.
    success = removeedgebyflips(&searchtet, &fc);
    assert(success != 2);
  } else {
    terminateBoundaryRecovery(this, 3); // It may be a PLC problem.
  }

  split = 0;
  for (i = 0; i < caveencseglist->objects; i++) {
    paryseg = (face *) fastlookup(caveencseglist, i);
    suninfect(*paryseg);
    // Calculate the shortest edge between the two lines.
    pc = sorg(*paryseg);
    pd = sdest(*paryseg);
    tp = tq = 0;
    if (linelineint(startpt, endpt, pc, pd, P, Q, &tp, &tq)) {
      // Does the shortest edge lie between the two segments?
      // Round tp and tq.
      if ((tp > 0) && (tq < 1)) {
        if (tp < 0.5) {
          if (tp < (b->epsilon * 1e+3)) tp = 0.0;
        } else {
          if ((1.0 - tp) < (b->epsilon * 1e+3)) tp = 1.0;
        }
      }
      if ((tp <= 0) || (tp >= 1)) continue;
      if ((tq > 0) && (tq < 1)) {
        if (tq < 0.5) {
          if (tq < (b->epsilon * 1e+3)) tq = 0.0;
        } else {
          if ((1.0 - tq) < (b->epsilon * 1e+3)) tq = 1.0;
        }
      }
      if ((tq <= 0) || (tq >= 1)) continue;
      // It is a valid shortest edge. Calculate its length.
      len = distance(P, Q);
      if (split == 0) {
        smlen = len;
        split = tp;
        split_q = tq;
        candseg = *paryseg;
      } else {
        if (len < smlen) {
          smlen = len;
          split = tp;
          split_q = tq;
          candseg = *paryseg;
        }
      }
    }
  }

  caveencseglist->restart();
  b->fliplinklevel = bak_fliplinklevel;

  if (split == 0) {
    // Found no crossing segment.
    return 0;
  }

  face splitsh;
  face splitseg;
  point steinerpt, *parypt;
  insertvertexflags ivf;

  if (b->addsteiner_algo == 1) {
    // Split the segment at the closest point to a near segment.
    makepoint(&steinerpt, FREESEGVERTEX);
    for (i = 0; i < 3; i++) {
      steinerpt[i] = startpt[i] + split * (endpt[i] - startpt[i]);
    }
  } else { // b->addsteiner_algo == 2
    for (i = 0; i < 3; i++) {
      P[i] = startpt[i] + split * (endpt[i] - startpt[i]);
    }
    pc = sorg(candseg);
    pd = sdest(candseg);
    for (i = 0; i < 3; i++) {
      Q[i] = pc[i] + split_q * (pd[i] - pc[i]);
    }
    makepoint(&steinerpt, FREEVOLVERTEX);
    for (i = 0; i < 3; i++) {
      steinerpt[i] = 0.5 * (P[i] + Q[i]);
    }
  }

  // We need to locate the point. Start searching from 'searchtet'.
  if (split < 0.5) {
    point2tetorg(startpt, searchtet);
  } else {
    point2tetorg(endpt, searchtet);
  }
  if (b->addsteiner_algo == 1) {
    splitseg = *misseg;
    spivot(*misseg, splitsh);
  } else {
    splitsh.sh = NULL;
    splitseg.sh = NULL;
  }
  ivf.iloc = (int) OUTSIDE;
  ivf.bowywat = 1;
  ivf.lawson = 0;
  ivf.rejflag = 0;
  ivf.chkencflag = 0;
  ivf.sloc = (int) ONEDGE;
  ivf.sbowywat = 1;
  ivf.splitbdflag = 0;
  ivf.validflag = 1;
  ivf.respectbdflag = 1;
  ivf.assignmeshsize = b->metric;

  if (!insertpoint(steinerpt, &searchtet, &splitsh, &splitseg, &ivf)) {
    pointdealloc(steinerpt);
    return 0;
  }

  if (b->addsteiner_algo == 1) {
    // Save this Steiner point (for removal).
    //   Re-use the array 'subvertstack'.
    subvertstack->newindex((void **) &parypt);
    *parypt = steinerpt;
    st_segref_count++;
  } else { // b->addsteiner_algo == 2
    // Queue the segment for recovery.
    subsegstack->newindex((void **) &paryseg);
    *paryseg = *misseg;
    st_volref_count++;
  }
  if (steinerleft > 0) steinerleft--;

  return 1;
}

int meshGRegionBoundaryRecovery::addsteiner4recoversegment(face* misseg,
  int splitsegflag)
{
  triface *abtets, searchtet, spintet;
  face splitsh;
  face *paryseg;
  point startpt, endpt;
  point pa, pb, pd, steinerpt, *parypt;
  enum interresult dir;
  insertvertexflags ivf;
  int types[2], poss[4];
  int n, endi, success;
  int t1ver;
  int i;

  startpt = sorg(*misseg);
  if (pointtype(startpt) == FREESEGVERTEX) {
    sesymself(*misseg);
    startpt = sorg(*misseg);
  }
  endpt = sdest(*misseg);

  // Try to recover the edge by adding Steiner points.
  point2tetorg(startpt, searchtet);
  dir = finddirection(&searchtet, endpt);
  enextself(searchtet);
  //assert(apex(searchtet) == startpt);

  if (dir == ACROSSFACE) {
    // The segment is crossing at least 3 faces. Find the common edge of
    //   the first 3 crossing faces.
    esymself(searchtet);
    fsym(searchtet, spintet);
    pd = oppo(spintet);
    for (i = 0; i < 3; i++) {
      pa = org(spintet);
      pb = dest(spintet);
      //pc = apex(neightet);
      if (tri_edge_test(pa, pb, pd, startpt, endpt, NULL, 1, types, poss)) {
        break; // Found the edge.
      }
      enextself(spintet);
      eprevself(searchtet);
    }
    assert(i < 3);
    esymself(searchtet);
  } else {
    assert(dir == ACROSSEDGE);
    // PLC check.
    if (issubseg(searchtet)) {
      face checkseg;
      tsspivot1(searchtet, checkseg);
      printf("Found two segments intersect each other.\n");
      pa = farsorg(*misseg);
      pb = farsdest(*misseg);
      printf("  1st: [%d,%d] %d.\n", pointmark(pa), pointmark(pb),
             shellmark(*misseg));
      pa = farsorg(checkseg);
      pb = farsdest(checkseg);
      printf("  2nd: [%d,%d] %d.\n", pointmark(pa), pointmark(pb),
             shellmark(checkseg));
      terminateBoundaryRecovery(this, 3);
    }
  }
  assert(apex(searchtet) == startpt);

  spintet = searchtet;
  n = 0; endi = -1;
  while (1) {
    // Check if the endpt appears in the star.
    if (apex(spintet) == endpt) {
      endi = n; // Remember the position of endpt.
    }
    n++; // Count a tet in the star.
    fnextself(spintet);
    if (spintet.tet == searchtet.tet) break;
  }
  assert(n >= 3);

  if (endi > 0) {
    // endpt is also in the edge star
    // Get all tets in the edge star.
    abtets = new triface[n];
    spintet = searchtet;
    for (i = 0; i < n; i++) {
      abtets[i] = spintet;
      fnextself(spintet);
    }

    success = 0;

    if (dir == ACROSSFACE) {
      // Find a Steiner points inside the polyhedron.
      if (add_steinerpt_in_schoenhardtpoly(abtets, endi, 0)) {
        success = 1;
      }
    } else if (dir == ACROSSEDGE) {
      if (n > 4) {
        // In this case, 'abtets' is separated by the plane (containing the
        //   two intersecting edges) into two parts, P1 and P2, where P1
        //   consists of 'endi' tets: abtets[0], abtets[1], ...,
        //   abtets[endi-1], and P2 consists of 'n - endi' tets:
        //   abtets[endi], abtets[endi+1], abtets[n-1].
        if (endi > 2) { // P1
          // There are at least 3 tets in the first part.
          if (add_steinerpt_in_schoenhardtpoly(abtets, endi, 0)) {
            success++;
          }
        }
        if ((n - endi) > 2) { // P2
          // There are at least 3 tets in the first part.
          if (add_steinerpt_in_schoenhardtpoly(&(abtets[endi]), n - endi, 0)) {
            success++;
          }
        }
      } else {
        // In this case, a 4-to-4 flip should be re-cover the edge [c,d].
        //   However, there will be invalid tets (either zero or negtive
        //   volume). Otherwise, [c,d] should already be recovered by the
        //   recoveredge() function.
        terminateBoundaryRecovery(this, 2); // Report a bug.
      }
    } else {
      terminateBoundaryRecovery(this, 10); // A PLC problem.
    }

    delete [] abtets;

    if (success) {
      // Add the missing segment back to the recovering list.
      subsegstack->newindex((void **) &paryseg);
      *paryseg = *misseg;
      return 1;
    }
  } // if (endi > 0)

  if (!splitsegflag) {
    return 0;
  }

  if (b->verbose > 2) {
    printf("      Splitting segment (%d, %d)\n", pointmark(startpt),
           pointmark(endpt));
  }
  steinerpt = NULL;

  if (b->addsteiner_algo > 0) { // -Y/1 or -Y/2
    if (add_steinerpt_in_segment(misseg, 3)) {
      return 1;
    }
    sesymself(*misseg);
    if (add_steinerpt_in_segment(misseg, 3)) {
      return 1;
    }
    sesymself(*misseg);
  }




  if (steinerpt == NULL) {
    // Split the segment at its midpoint.
    makepoint(&steinerpt, FREESEGVERTEX);
    for (i = 0; i < 3; i++) {
      steinerpt[i] = 0.5 * (startpt[i] + endpt[i]);
    }

    // We need to locate the point.
    assert(searchtet.tet != NULL); // Start searching from 'searchtet'.
    spivot(*misseg, splitsh);
    ivf.iloc = (int) OUTSIDE;
    ivf.bowywat = 1;
    ivf.lawson = 0;
    ivf.rejflag = 0;
    ivf.chkencflag = 0;
    ivf.sloc = (int) ONEDGE;
    ivf.sbowywat = 1;
    ivf.splitbdflag = 0;
    ivf.validflag = 1;
    ivf.respectbdflag = 1;
    ivf.assignmeshsize = b->metric;
    if (!insertpoint(steinerpt, &searchtet, &splitsh, misseg, &ivf)) {
      assert(0);
    }
  } // if (endi > 0)

  // Save this Steiner point (for removal).
  //   Re-use the array 'subvertstack'.
  subvertstack->newindex((void **) &parypt);
  *parypt = steinerpt;

  st_segref_count++;
  if (steinerleft > 0) steinerleft--;

  return 1;
}

int meshGRegionBoundaryRecovery::recoversegments(arraypool *misseglist,
  int fullsearch, int steinerflag)
{
  triface searchtet, spintet;
  face sseg, *paryseg;
  point startpt, endpt;
  int success;
  int t1ver;
  long bak_inpoly_count = st_volref_count;
  long bak_segref_count = st_segref_count;

  if (b->verbose > 1) {
    printf("    Recover segments [%s level = %2d] #:  %ld.\n",
           (b->fliplinklevel > 0) ? "fixed" : "auto",
           (b->fliplinklevel > 0) ? b->fliplinklevel : autofliplinklevel,
           subsegstack->objects);
  }

  // Loop until 'subsegstack' is empty.
  while (subsegstack->objects > 0l) {
    // seglist is used as a stack.
    subsegstack->objects--;
    paryseg = (face *) fastlookup(subsegstack, subsegstack->objects);
    sseg = *paryseg;

    // Check if this segment has been recovered.
    sstpivot1(sseg, searchtet);
    if (searchtet.tet != NULL) {
      continue; // Not a missing segment.
    }

    startpt = sorg(sseg);
    endpt = sdest(sseg);

    if (b->verbose > 2) {
      printf("      Recover segment (%d, %d).\n", pointmark(startpt),
             pointmark(endpt));
    }

    success = 0;

    if (recoveredgebyflips(startpt, endpt, &searchtet, 0)) {
      success = 1;
    } else {
      // Try to recover it from the other direction.
      if (recoveredgebyflips(endpt, startpt, &searchtet, 0)) {
        success = 1;
      }
    }

    if (!success && fullsearch) {
      if (recoveredgebyflips(startpt, endpt, &searchtet, fullsearch)) {
        success = 1;
      }
    }

    if (success) {
      // Segment is recovered. Insert it.
      // Let the segment remember an adjacent tet.
      sstbond1(sseg, searchtet);
      // Bond the segment to all tets containing it.
      spintet = searchtet;
      do {
        tssbond1(spintet, sseg);
        fnextself(spintet);
      } while (spintet.tet != searchtet.tet);
    } else {
      if (steinerflag > 0) {
        // Try to recover the segment but do not split it.
        if (addsteiner4recoversegment(&sseg, 0)) {
          success = 1;
        }
        if (!success && (steinerflag > 1)) {
          // Split the segment.
          addsteiner4recoversegment(&sseg, 1);
          success = 1;
        }
      }
      if (!success) {
        if (misseglist != NULL) {
          // Save this segment.
          misseglist->newindex((void **) &paryseg);
          *paryseg = sseg;
        }
      }
    }

  } // while (subsegstack->objects > 0l)

  if (steinerflag) {
    if (b->verbose > 1) {
      // Report the number of added Steiner points.
      if (st_volref_count > bak_inpoly_count) {
        printf("    Add %ld Steiner points in volume.\n",
               st_volref_count - bak_inpoly_count);
      }
      if (st_segref_count > bak_segref_count) {
        printf("    Add %ld Steiner points in segments.\n",
               st_segref_count - bak_segref_count);
      }
    }
  }

  return 0;
}

int meshGRegionBoundaryRecovery::recoverfacebyflips(point pa, point pb,
  point pc, face *searchsh, triface* searchtet)
{
  triface spintet, flipedge;
  point pd, pe;
  enum interresult dir;
  flipconstraints fc;
  int types[2], poss[4], intflag;
  int success, success1;
  int t1ver;
  int i, j;


  fc.fac[0] = pa;
  fc.fac[1] = pb;
  fc.fac[2] = pc;
  fc.checkflipeligibility = 1;
  success = 0;

  for (i = 0; i < 3 && !success; i++) {
    while (1) {
      // Get a tet containing the edge [a,b].
      point2tetorg(fc.fac[i], *searchtet);
      dir = finddirection(searchtet, fc.fac[(i+1)%3]);
      //assert(dir == ACROSSVERT);
      assert(dest(*searchtet) == fc.fac[(i+1)%3]);
      // Search the face [a,b,c]
      spintet = *searchtet;
      while (1) {
        if (apex(spintet) == fc.fac[(i+2)%3]) {
          // Found the face.
          *searchtet = spintet;
          // Return the face [a,b,c].
          for (j = i; j > 0; j--) {
            eprevself(*searchtet);
          }
          success = 1;
          break;
        }
        fnextself(spintet);
        if (spintet.tet == searchtet->tet) break;
      } // while (1)
      if (success) break;
      // The face is missing. Try to recover it.
      success1 = 0;
      // Find a crossing edge of this face.
      spintet = *searchtet;
      while (1) {
        pd = apex(spintet);
        pe = oppo(spintet);
        if ((pd != dummypoint) && (pe != dummypoint)) {
          // Check if [d,e] intersects [a,b,c]
          intflag = tri_edge_test(pa, pb, pc, pd, pe, NULL, 1, types, poss);
          if (intflag > 0) {
            // By our assumptions, they can only intersect at a single point.
            if (intflag == 2) {
              // Check the intersection type.
              dir = (enum interresult) types[0];
              if ((dir == ACROSSFACE) || (dir == ACROSSEDGE)) {
                // Go to the edge [d,e].
                edestoppo(spintet, flipedge); // [d,e,a,b]
                if (searchsh != NULL) {
                  // Check if [e,d] is a segment.
                  if (issubseg(flipedge)) {
                    if (!b->quiet) {
                      face checkseg;
                      tsspivot1(flipedge, checkseg);
                      printf("Found a segment and a subface intersect.\n");
                      pd = farsorg(checkseg);
                      pe = farsdest(checkseg);
                      printf("  1st: [%d, %d] %d.\n",  pointmark(pd),
                             pointmark(pe), shellmark(checkseg));
                      printf("  2nd: [%d,%d,%d] %d\n", pointmark(pa),
                        pointmark(pb), pointmark(pc), shellmark(*searchsh));
	                }
                    terminateBoundaryRecovery(this, 3);
		          }
                }
                // Try to flip the edge [d,e].
                success1 = (removeedgebyflips(&flipedge, &fc) == 2);
              } else {
                if (dir == TOUCHFACE) {
                  point touchpt, *parypt;
                  if (poss[1] == 0) {
                    touchpt = pd; // pd is a coplanar vertex.
                  } else {
                    touchpt = pe; // pe is a coplanar vertex.
                  }
                  if (pointtype(touchpt) == FREEVOLVERTEX) {
                    // A volume Steiner point was added in this subface.
                    // Split this subface by this point.
                    face checksh, *parysh;
                    int siloc = (int) ONFACE;
                    int sbowat = 0; // Only split this subface.
                    setpointtype(touchpt, FREEFACETVERTEX);
                    sinsertvertex(touchpt, searchsh, NULL, siloc, sbowat, 0);
                    st_volref_count--;
                    st_facref_count++;
                    // Queue this vertex for removal.
                    subvertstack->newindex((void **) &parypt);
                    *parypt = touchpt;
                    // Queue new subfaces for recovery.
                    // Put all new subfaces into stack for recovery.
                    for (i = 0; i < caveshbdlist->objects; i++) {
                      // Get an old subface at edge [a, b].
                      parysh = (face *) fastlookup(caveshbdlist, i);
                      spivot(*parysh, checksh); // The new subface [a, b, p].
                      // Do not recover a deleted new face (degenerated).
                      if (checksh.sh[3] != NULL) {
                        subfacstack->newindex((void **) &parysh);
                        *parysh = checksh;
                      }
                    }
                    // Delete the old subfaces in sC(p).
                    assert(caveshlist->objects == 1);
                    for (i = 0; i < caveshlist->objects; i++) {
                      parysh = (face *) fastlookup(caveshlist, i);
                      shellfacedealloc(subfaces, parysh->sh);
                    }
                    // Clear working lists.
                    caveshlist->restart();
                    caveshbdlist->restart();
                    cavesegshlist->restart();
                    // We can return this function.
                    searchsh->sh = NULL; // It has been split.
                    success1 = 0;
                    success = 1;
                  } else {
                    // It should be a PLC problem.
                    if (pointtype(touchpt) == FREESEGVERTEX) {
                      // A segment and a subface intersect.
                    } else if (pointtype(touchpt) == FREEFACETVERTEX) {
                      // Two facets self-intersect.
                    }
                    terminateBoundaryRecovery(this, 3);
                  }
                } else {
                  assert(0); // Unknown cases. Debug.
                }
              }
              break;
            } else { // intflag == 4. Coplanar case.
              // This may be an input PLC error.
              assert(0);
            }
          } // if (intflag > 0)
        }
        fnextself(spintet);
        assert(spintet.tet != searchtet->tet);
      } // while (1)
      if (!success1) break;
    } // while (1)
  } // i

  return success;
}

int meshGRegionBoundaryRecovery::recoversubfaces(arraypool *misshlist,
  int steinerflag)
{
  triface searchtet, neightet, spintet;
  face searchsh, neighsh, neineish, *parysh;
  face bdsegs[3];
  point startpt, endpt, apexpt, *parypt;
  point steinerpt;
  enum interresult dir;
  insertvertexflags ivf;
  int success;
  int t1ver;
  int i, j;

  if (b->verbose > 1) {
    printf("    Recover subfaces [%s level = %2d] #:  %ld.\n",
           (b->fliplinklevel > 0) ? "fixed" : "auto",
           (b->fliplinklevel > 0) ? b->fliplinklevel : autofliplinklevel,
           subfacstack->objects);
  }

  // Loop until 'subfacstack' is empty.
  while (subfacstack->objects > 0l) {

    subfacstack->objects--;
    parysh = (face *) fastlookup(subfacstack, subfacstack->objects);
    searchsh = *parysh;

    if (searchsh.sh[3] == NULL) continue; // Skip a dead subface.

    stpivot(searchsh, neightet);
    if (neightet.tet != NULL) continue; // Skip a recovered subface.


    if (b->verbose > 2) {
      printf("      Recover subface (%d, %d, %d).\n",pointmark(sorg(searchsh)),
             pointmark(sdest(searchsh)), pointmark(sapex(searchsh)));
    }

    // The three edges of the face need to be existed first.
    for (i = 0; i < 3; i++) {
      sspivot(searchsh, bdsegs[i]);
      if (bdsegs[i].sh != NULL) {
        // The segment must exist.
        sstpivot1(bdsegs[i], searchtet);
        if (searchtet.tet == NULL) {
          assert(0);
        }
      } else {
        // This edge is not a segment (due to a Steiner point).
        // Check whether it exists or not.
        success = 0;
        startpt = sorg(searchsh);
        endpt = sdest(searchsh);
        point2tetorg(startpt, searchtet);
        dir = finddirection(&searchtet, endpt);
        if (dir == ACROSSVERT) {
          if (dest(searchtet) == endpt) {
            success = 1;
          } else {
            //assert(0); // A PLC problem.
            terminateBoundaryRecovery(this, 3);
          }
        } else {
          // The edge is missing. Try to recover it.
          if (recoveredgebyflips(startpt, endpt, &searchtet, 0)) {
            success = 1;
          } else {
            if (recoveredgebyflips(endpt, startpt, &searchtet, 0)) {
              success = 1;
            }
          }
        }
        if (success) {
          // Insert a temporary segment to protect this edge.
          makeshellface(subsegs, &(bdsegs[i]));
          setshvertices(bdsegs[i], startpt, endpt, NULL);
          smarktest2(bdsegs[i]); // It's a temporary segment.
          // Insert this segment into surface mesh.
          ssbond(searchsh, bdsegs[i]);
          spivot(searchsh, neighsh);
          if (neighsh.sh != NULL) {
            ssbond(neighsh, bdsegs[i]);
          }
          // Insert this segment into tetrahedralization.
          sstbond1(bdsegs[i], searchtet);
          // Bond the segment to all tets containing it.
          spintet = searchtet;
          do {
            tssbond1(spintet, bdsegs[i]);
            fnextself(spintet);
          } while (spintet.tet != searchtet.tet);
        } else {
          // An edge of this subface is missing. Can't recover this subface.
          // Delete any temporary segment that has been created.
          for (j = (i - 1); j >= 0; j--) {
            if (smarktest2ed(bdsegs[j])) {
              spivot(bdsegs[j], neineish);
              assert(neineish.sh != NULL);
              //if (neineish.sh != NULL) {
                ssdissolve(neineish);
                spivot(neineish, neighsh);
                if (neighsh.sh != NULL) {
                  ssdissolve(neighsh);
                  // There should be only two subfaces at this segment.
                  spivotself(neighsh); // SELF_CHECK
                  assert(neighsh.sh == neineish.sh);
                }
	          //}
              sstpivot1(bdsegs[j], searchtet);
              assert(searchtet.tet != NULL);
              //if (searchtet.tet != NULL) {
                spintet = searchtet;
                while (1) {
                  tssdissolve1(spintet);
                  fnextself(spintet);
                  if (spintet.tet == searchtet.tet) break;
                }
	          //}
              shellfacedealloc(subsegs, bdsegs[j].sh);
            }
          } // j
          if (steinerflag) {
            // Add a Steiner point at the midpoint of this edge.
            if (b->verbose > 2) {
              printf("      Add a Steiner point in subedge (%d, %d).\n",
                     pointmark(startpt), pointmark(endpt));
            }
            makepoint(&steinerpt, FREEFACETVERTEX);
            for (j = 0; j < 3; j++) {
              steinerpt[j] = 0.5 * (startpt[j] + endpt[j]);
            }

            point2tetorg(startpt, searchtet); // Start from 'searchtet'.
            ivf.iloc = (int) OUTSIDE; // Need point location.
            ivf.bowywat = 1;
            ivf.lawson = 0;
            ivf.rejflag = 0;
            ivf.chkencflag = 0;
            ivf.sloc = (int) ONEDGE;
            ivf.sbowywat = 1; // Allow flips in facet.
            ivf.splitbdflag = 0;
            ivf.validflag = 1;
            ivf.respectbdflag = 1;
            ivf.assignmeshsize = b->metric;
            if (!insertpoint(steinerpt, &searchtet, &searchsh, NULL, &ivf)) {
              assert(0);
            }
            // Save this Steiner point (for removal).
            //   Re-use the array 'subvertstack'.
            subvertstack->newindex((void **) &parypt);
            *parypt = steinerpt;

            st_facref_count++;
            if (steinerleft > 0) steinerleft--;
          } // if (steinerflag)
          break;
        }
      }
      senextself(searchsh);
    } // i

    if (i == 3) {
      // Recover the subface.
      startpt = sorg(searchsh);
      endpt   = sdest(searchsh);
      apexpt  = sapex(searchsh);

      success = recoverfacebyflips(startpt,endpt,apexpt,&searchsh,&searchtet);

      // Delete any temporary segment that has been created.
      for (j = 0; j < 3; j++) {
        if (smarktest2ed(bdsegs[j])) {
          spivot(bdsegs[j], neineish);
          assert(neineish.sh != NULL);
          //if (neineish.sh != NULL) {
            ssdissolve(neineish);
            spivot(neineish, neighsh);
            if (neighsh.sh != NULL) {
              ssdissolve(neighsh);
              // There should be only two subfaces at this segment.
              spivotself(neighsh); // SELF_CHECK
              assert(neighsh.sh == neineish.sh);
            }
	      //}
          sstpivot1(bdsegs[j], neightet);
          assert(neightet.tet != NULL);
          //if (neightet.tet != NULL) {
            spintet = neightet;
            while (1) {
              tssdissolve1(spintet);
              fnextself(spintet);
              if (spintet.tet == neightet.tet) break;
            }
	      //}
          shellfacedealloc(subsegs, bdsegs[j].sh);
        }
      } // j

      if (success) {
        if (searchsh.sh != NULL) {
          // Face is recovered. Insert it.
          tsbond(searchtet, searchsh);
          fsymself(searchtet);
          sesymself(searchsh);
          tsbond(searchtet, searchsh);
        }
      } else {
        if (steinerflag) {
          // Add a Steiner point at the barycenter of this subface.
          if (b->verbose > 2) {
            printf("      Add a Steiner point in subface (%d, %d, %d).\n",
                   pointmark(startpt), pointmark(endpt), pointmark(apexpt));
          }
          makepoint(&steinerpt, FREEFACETVERTEX);
          for (j = 0; j < 3; j++) {
            steinerpt[j] = (startpt[j] + endpt[j] + apexpt[j]) / 3.0;
          }

          point2tetorg(startpt, searchtet); // Start from 'searchtet'.
          ivf.iloc = (int) OUTSIDE; // Need point location.
          ivf.bowywat = 1;
          ivf.lawson = 0;
          ivf.rejflag = 0;
          ivf.chkencflag = 0;
          ivf.sloc = (int) ONFACE;
          ivf.sbowywat = 1; // Allow flips in facet.
          ivf.splitbdflag = 0;
          ivf.validflag = 1;
          ivf.respectbdflag = 1;
          ivf.assignmeshsize = b->metric;
          if (!insertpoint(steinerpt, &searchtet, &searchsh, NULL, &ivf)) {
            assert(0);
          }
          // Save this Steiner point (for removal).
          //   Re-use the array 'subvertstack'.
          subvertstack->newindex((void **) &parypt);
          *parypt = steinerpt;

          st_facref_count++;
          if (steinerleft > 0) steinerleft--;
        } // if (steinerflag)
      }
    } else {
      success = 0;
    }

    if (!success) {
      if (misshlist != NULL) {
        // Save this subface.
        misshlist->newindex((void **) &parysh);
        *parysh = searchsh;
      }
    }

  } // while (subfacstack->objects > 0l)

  return 0;
}

int meshGRegionBoundaryRecovery::getvertexstar(int fullstar, point searchpt,
  arraypool* tetlist, arraypool* vertlist, arraypool* shlist)
{
  triface searchtet, neightet, *parytet;
  face checksh, *parysh;
  point pt, *parypt;
  int collectflag;
  int t1ver;
  int i, j;

  point2tetorg(searchpt, searchtet);

  // Go to the opposite face (the link face) of the vertex.
  enextesymself(searchtet);
  //assert(oppo(searchtet) == searchpt);
  infect(searchtet); // Collect this tet (link face).
  tetlist->newindex((void **) &parytet);
  *parytet = searchtet;
  if (vertlist != NULL) {
    // Collect three (link) vertices.
    j = (searchtet.ver & 3); // The current vertex index.
    for (i = 1; i < 4; i++) {
      pt = (point) searchtet.tet[4 + ((j + i) % 4)];
      pinfect(pt);
      vertlist->newindex((void **) &parypt);
      *parypt = pt;
    }
  }

  collectflag = 1;
  esym(searchtet, neightet);
  if (issubface(neightet)) {
    if (shlist != NULL) {
      tspivot(neightet, checksh);
      if (!sinfected(checksh)) {
        // Collect this subface (link edge).
        sinfected(checksh);
        shlist->newindex((void **) &parysh);
        *parysh = checksh;
      }
    }
    if (!fullstar) {
      collectflag = 0;
    }
  }
  if (collectflag) {
    fsymself(neightet); // Goto the adj tet of this face.
    esymself(neightet); // Goto the oppo face of this vertex.
    // assert(oppo(neightet) == searchpt);
    infect(neightet); // Collect this tet (link face).
    tetlist->newindex((void **) &parytet);
    *parytet = neightet;
    if (vertlist != NULL) {
      // Collect its apex.
      pt = apex(neightet);
      pinfect(pt);
      vertlist->newindex((void **) &parypt);
      *parypt = pt;
    }
  } // if (collectflag)

  // Continue to collect all tets in the star.
  for (i = 0; i < tetlist->objects; i++) {
    searchtet = * (triface *) fastlookup(tetlist, i);
    // Note that 'searchtet' is a face opposite to 'searchpt', and the neighbor
    //   tet at the current edge is already collected.
    // Check the neighbors at the other two edges of this face.
    for (j = 0; j < 2; j++) {
      collectflag = 1;
      enextself(searchtet);
      esym(searchtet, neightet);
      if (issubface(neightet)) {
        if (shlist != NULL) {
          tspivot(neightet, checksh);
          if (!sinfected(checksh)) {
            // Collect this subface (link edge).
            sinfected(checksh);
            shlist->newindex((void **) &parysh);
            *parysh = checksh;
          }
        }
        if (!fullstar) {
          collectflag = 0;
        }
      }
      if (collectflag) {
        fsymself(neightet);
        if (!infected(neightet)) {
          esymself(neightet); // Go to the face opposite to 'searchpt'.
          infect(neightet);
          tetlist->newindex((void **) &parytet);
          *parytet = neightet;
          if (vertlist != NULL) {
            // Check if a vertex is collected.
            pt = apex(neightet);
            if (!pinfected(pt)) {
              pinfect(pt);
              vertlist->newindex((void **) &parypt);
              *parypt = pt;
            }
          }
        } // if (!infected(neightet))
      } // if (collectflag)
    } // j
  } // i


  // Uninfect the list of tets and vertices.
  for (i = 0; i < tetlist->objects; i++) {
    parytet = (triface *) fastlookup(tetlist, i);
    uninfect(*parytet);
  }

  if (vertlist != NULL) {
    for (i = 0; i < vertlist->objects; i++) {
      parypt = (point *) fastlookup(vertlist, i);
      puninfect(*parypt);
    }
  }

  if (shlist != NULL) {
    for (i = 0; i < shlist->objects; i++) {
      parysh = (face *) fastlookup(shlist, i);
      suninfect(*parysh);
    }
  }

  return (int) tetlist->objects;
}

int meshGRegionBoundaryRecovery::getedge(point e1, point e2, triface *tedge)
{
  triface searchtet, neightet, *parytet;
  point pt;
  int done;
  int i, j;

  if (b->verbose > 2) {
    printf("      Get edge from %d to %d.\n", pointmark(e1), pointmark(e2));
  }

  // Quickly check if 'tedge' is just this edge.
  if (!isdeadtet(*tedge)) {
    if (org(*tedge) == e1) {
      if (dest(*tedge) == e2) {
        return 1;
      }
    } else if (org(*tedge) == e2) {
      if (dest(*tedge) == e1) {
        esymself(*tedge);
        return 1;
      }
    }
  }

  // Search for the edge [e1, e2].
  point2tetorg(e1, *tedge);
  finddirection(tedge, e2);
  if (dest(*tedge) == e2) {
    return 1;
  } else {
    // Search for the edge [e2, e1].
    point2tetorg(e2, *tedge);
    finddirection(tedge, e1);
    if (dest(*tedge) == e1) {
      esymself(*tedge);
      return 1;
    }
  }


  // Go to the link face of e1.
  point2tetorg(e1, searchtet);
  enextesymself(searchtet);
  //assert(oppo(searchtet) == e1);

  assert(cavebdrylist->objects == 0l); // It will re-use this list.
  arraypool *tetlist = cavebdrylist;

  // Search e2.
  for (i = 0; i < 3; i++) {
    pt = apex(searchtet);
    if (pt == e2) {
      // Found. 'searchtet' is [#,#,e2,e1].
      eorgoppo(searchtet, *tedge); // [e1,e2,#,#].
      return 1;
    }
    enextself(searchtet);
  }

  // Get the adjacent link face at 'searchtet'.
  fnext(searchtet, neightet);
  esymself(neightet);
  // assert(oppo(neightet) == e1);
  pt = apex(neightet);
  if (pt == e2) {
    // Found. 'neightet' is [#,#,e2,e1].
    eorgoppo(neightet, *tedge); // [e1,e2,#,#].
    return 1;
  }

  // Continue searching in the link face of e1.
  infect(searchtet);
  tetlist->newindex((void **) &parytet);
  *parytet = searchtet;
  infect(neightet);
  tetlist->newindex((void **) &parytet);
  *parytet = neightet;

  done = 0;

  for (i = 0; (i < tetlist->objects) && !done; i++) {
    parytet = (triface *) fastlookup(tetlist, i);
    searchtet = *parytet;
    for (j = 0; (j < 2) && !done; j++) {
      enextself(searchtet);
      fnext(searchtet, neightet);
      if (!infected(neightet)) {
        esymself(neightet);
        pt = apex(neightet);
        if (pt == e2) {
          // Found. 'neightet' is [#,#,e2,e1].
          eorgoppo(neightet, *tedge);
          done = 1;
        } else {
          infect(neightet);
          tetlist->newindex((void **) &parytet);
          *parytet = neightet;
        }
      }
    } // j
  } // i

  // Uninfect the list of visited tets.
  for (i = 0; i < tetlist->objects; i++) {
    parytet = (triface *) fastlookup(tetlist, i);
    uninfect(*parytet);
  }
  tetlist->restart();

  return done;
}

int meshGRegionBoundaryRecovery::reduceedgesatvertex(point startpt,
  arraypool* endptlist)
{
  triface searchtet;
  point *pendpt, *parypt;
  enum interresult dir;
  flipconstraints fc;
  int reduceflag;
  int count;
  int n, i, j;


  fc.remvert = startpt;
  fc.checkflipeligibility = 1;

  while (1) {

    count = 0;

    for (i = 0; i < endptlist->objects; i++) {
      pendpt = (point *) fastlookup(endptlist, i);
      if (*pendpt == dummypoint) {
        continue; // Do not reduce a virtual edge.
      }
      reduceflag = 0;
      // Find the edge.
      if (nonconvex) {
        if (getedge(startpt, *pendpt, &searchtet)) {
          dir = ACROSSVERT;
        } else {
          // The edge does not exist (was flipped).
          dir = INTERSECT;
        }
      } else {
        point2tetorg(startpt, searchtet);
        dir = finddirection(&searchtet, *pendpt);
      }
      if (dir == ACROSSVERT) {
        if (dest(searchtet) == *pendpt) {
          // Do not flip a segment.
          if (!issubseg(searchtet)) {
            n = removeedgebyflips(&searchtet, &fc);
            if (n == 2) {
              reduceflag = 1;
            }
          }
        } else {
          assert(0); // A plc problem.
        }
      } else {
        // The edge has been flipped.
        reduceflag = 1;
      }
      if (reduceflag) {
        count++;
        // Move the last vertex into this slot.
        j = endptlist->objects - 1;
        parypt = (point *) fastlookup(endptlist, j);
        *pendpt = *parypt;
        endptlist->objects--;
        i--;
      }
    } // i

    if (count == 0) {
      // No edge is reduced.
      break;
    }

  } // while (1)

  return (int) endptlist->objects;
}

int meshGRegionBoundaryRecovery::removevertexbyflips(point steinerpt)
{
  triface *fliptets = NULL, wrktets[4];
  triface searchtet, spintet, neightet;
  face parentsh, spinsh, checksh;
  face leftseg, rightseg, checkseg;
  point lpt = NULL, rpt = NULL, apexpt; //, *parypt;
  flipconstraints fc;
  enum verttype vt;
  enum locateresult loc;
  int valence, removeflag;
  int slawson;
  int t1ver;
  int n, i;

  vt = pointtype(steinerpt);

  if (vt == FREESEGVERTEX) {
    sdecode(point2sh(steinerpt), leftseg);
    assert(leftseg.sh != NULL);
    leftseg.shver = 0;
    if (sdest(leftseg) == steinerpt) {
      senext(leftseg, rightseg);
      spivotself(rightseg);
      assert(rightseg.sh != NULL);
      rightseg.shver = 0;
      assert(sorg(rightseg) == steinerpt);
    } else {
      assert(sorg(leftseg) == steinerpt);
      rightseg = leftseg;
      senext2(rightseg, leftseg);
      spivotself(leftseg);
      assert(leftseg.sh != NULL);
      leftseg.shver = 0;
      assert(sdest(leftseg) == steinerpt);
    }
    lpt = sorg(leftseg);
    rpt = sdest(rightseg);
    if (b->verbose > 2) {
      printf("      Removing Steiner point %d in segment (%d, %d).\n",
             pointmark(steinerpt), pointmark(lpt), pointmark(rpt));

    }
  } else if (vt == FREEFACETVERTEX) {
    if (b->verbose > 2) {
      printf("      Removing Steiner point %d in facet.\n",
             pointmark(steinerpt));
    }
  } else if (vt == FREEVOLVERTEX) {
    if (b->verbose > 2) {
      printf("      Removing Steiner point %d in volume.\n",
             pointmark(steinerpt));
    }
  } else if (vt == VOLVERTEX) {
    if (b->verbose > 2) {
      printf("      Removing a point %d in volume.\n",
             pointmark(steinerpt));
    }
  } else {
    // It is not a Steiner point.
    return 0;
  }

  // Try to reduce the number of edges at 'p' by flips.
  getvertexstar(1, steinerpt, cavetetlist, cavetetvertlist, NULL);
  cavetetlist->restart(); // This list may be re-used.
  if (cavetetvertlist->objects > 3l) {
    valence = reduceedgesatvertex(steinerpt, cavetetvertlist);
  } else {
    valence = cavetetvertlist->objects;
  }
  assert(cavetetlist->objects == 0l);
  cavetetvertlist->restart();

  removeflag = 0;

  if (valence == 4) {
    // Only 4 vertices (4 tets) left! 'p' is inside the convex hull of the 4
    //   vertices. This case is due to that 'p' is not exactly on the segment.
    point2tetorg(steinerpt, searchtet);
    loc = INTETRAHEDRON;
    removeflag = 1;
  } else if (valence == 5) {
    // There are 5 edges.
    if (vt == FREESEGVERTEX) {
      sstpivot1(leftseg, searchtet);
      if (org(searchtet) != steinerpt) {
        esymself(searchtet);
      }
      assert(org(searchtet) == steinerpt);
      assert(dest(searchtet) == lpt);
      i = 0; // Count the numbe of tet at the edge [p,lpt].
      neightet.tet = NULL; // Init the face.
      spintet = searchtet;
      while (1) {
        i++;
        if (apex(spintet) == rpt) {
          // Remember the face containing the edge [lpt, rpt].
          neightet = spintet;
        }
        fnextself(spintet);
        if (spintet.tet == searchtet.tet) break;
      }
      if (i == 3) {
        // This case has been checked below.
      } else if (i == 4) {
        // There are 4 tets sharing at [p,lpt]. There must be 4 tets sharing
        //   at [p,rpt].  There must be a face [p, lpt, rpt].
        if (apex(neightet) == rpt) {
          // The edge (segment) has been already recovered!
          // Check if a 6-to-2 flip is possible (to remove 'p').
          // Let 'searchtet' be [p,d,a,b]
          esym(neightet, searchtet);
          enextself(searchtet);
          // Check if there are exactly three tets at edge [p,d].
          wrktets[0] = searchtet; // [p,d,a,b]
          for (i = 0; i < 2; i++) {
            fnext(wrktets[i], wrktets[i+1]); // [p,d,b,c], [p,d,c,a]
          }
          if (apex(wrktets[0]) == oppo(wrktets[2])) {
            loc = ONFACE;
            removeflag = 1;
          }
        }
      }
    } else if (vt == FREEFACETVERTEX) {
      // It is possible to do a 6-to-2 flip to remove the vertex.
      point2tetorg(steinerpt, searchtet);
      // Get the three faces of 'searchtet' which share at p.
      //    All faces has p as origin.
      wrktets[0] = searchtet;
      wrktets[1] = searchtet;
      esymself(wrktets[1]);
      enextself(wrktets[1]);
      wrktets[2] = searchtet;
      eprevself(wrktets[2]);
      esymself(wrktets[2]);
      // All internal edges of the six tets have valance either 3 or 4.
      // Get one edge which has valance 3.
      searchtet.tet = NULL;
      for (i = 0; i < 3; i++) {
        spintet = wrktets[i];
        valence = 0;
        while (1) {
          valence++;
          fnextself(spintet);
          if (spintet.tet == wrktets[i].tet) break;
        }
        if (valence == 3) {
          // Found the edge.
          searchtet = wrktets[i];
          break;
        } else {
          assert(valence == 4);
        }
      }
      assert(searchtet.tet != NULL);
      // Note, we do not detach the three subfaces at p.
      // They will be removed within a 4-to-1 flip.
      loc = ONFACE;
      removeflag = 1;
    } else {
      // assert(0); DEBUG IT
    }
    //removeflag = 1;
  }

  if (!removeflag) {
    if (vt == FREESEGVERTEX) {
      // Check is it possible to recover the edge [lpt,rpt].
      // The condition to check is:  Whether each tet containing 'leftseg' is
      //   adjacent to a tet containing 'rightseg'.
      sstpivot1(leftseg, searchtet);
      if (org(searchtet) != steinerpt) {
        esymself(searchtet);
      }
      assert(org(searchtet) == steinerpt);
      assert(dest(searchtet) == lpt);
      spintet = searchtet;
      while (1) {
        // Go to the bottom face of this tet.
        eprev(spintet, neightet);
        esymself(neightet);  // [steinerpt, p1, p2, lpt]
        // Get the adjacent tet.
        fsymself(neightet);  // [p1, steinerpt, p2, rpt]
        if (oppo(neightet) != rpt) {
          // Found a non-matching adjacent tet.
          break;
        }
        fnextself(spintet);
        if (spintet.tet == searchtet.tet) {
          // 'searchtet' is [p,d,p1,p2].
          loc = ONEDGE;
          removeflag = 1;
          break;
        }
      }
    } // if (vt == FREESEGVERTEX)
  }

  if (!removeflag) {
    if (vt == FREESEGVERTEX) {
      // Check if the edge [lpt, rpt] exists.
      if (getedge(lpt, rpt, &searchtet)) {
        // We have recovered this edge. Shift the vertex into the volume.
        // We can recover this edge if the subfaces are not recovered yet.
        if (!checksubfaceflag) {
          // Remove the vertex from the surface mesh.
          //   This will re-create the segment [lpt, rpt] and re-triangulate
          //   all the facets at the segment.
          // Detach the subsegments from their surrounding tets.
          for (i = 0; i < 2; i++) {
            checkseg = (i == 0) ? leftseg : rightseg;
            sstpivot1(checkseg, neightet);
            spintet = neightet;
            while (1) {
              tssdissolve1(spintet);
              fnextself(spintet);
              if (spintet.tet == neightet.tet) break;
            }
            sstdissolve1(checkseg);
          } // i
          slawson = 1; // Do lawson flip after removal.
          spivot(rightseg, parentsh); // 'rightseg' has p as its origin.
          sremovevertex(steinerpt, &parentsh, &rightseg, slawson);
          // Clear the list for new subfaces.
          caveshbdlist->restart();
          // Insert the new segment.
          assert(org(searchtet) == lpt);
          assert(dest(searchtet) == rpt);
          sstbond1(rightseg, searchtet);
          spintet = searchtet;
          while (1) {
            tsspivot1(spintet, checkseg); // FOR DEBUG ONLY
            assert(checkseg.sh == NULL);  // FOR DEBUG ONLY
            tssbond1(spintet, rightseg);
            fnextself(spintet);
            if (spintet.tet == searchtet.tet) break;
          }
          // The Steiner point has been shifted into the volume.
          setpointtype(steinerpt, FREEVOLVERTEX);
          st_segref_count--;
          st_volref_count++;
          return 1;
        } // if (!checksubfaceflag)
      } // if (getedge(...))
    } // if (vt == FREESEGVERTEX)
  } // if (!removeflag)

  if (!removeflag) {
    return 0;
  }

  assert(org(searchtet) == steinerpt);

  if (vt == FREESEGVERTEX) {
    // Detach the subsegments from their surronding tets.
    for (i = 0; i < 2; i++) {
      checkseg = (i == 0) ? leftseg : rightseg;
      sstpivot1(checkseg, neightet);
      spintet = neightet;
      while (1) {
        tssdissolve1(spintet);
        fnextself(spintet);
        if (spintet.tet == neightet.tet) break;
      }
      sstdissolve1(checkseg);
    } // i
    if (checksubfaceflag) {
      // Detach the subfaces at the subsegments from their attached tets.
      for (i = 0; i < 2; i++) {
        checkseg = (i == 0) ? leftseg : rightseg;
        spivot(checkseg, parentsh);
        if (parentsh.sh != NULL) {
          spinsh = parentsh;
          while (1) {
            stpivot(spinsh, neightet);
            if (neightet.tet != NULL) {
              tsdissolve(neightet);
            }
            sesymself(spinsh);
            stpivot(spinsh, neightet);
            if (neightet.tet != NULL) {
              tsdissolve(neightet);
            }
            stdissolve(spinsh);
            spivotself(spinsh); // Go to the next subface.
            if (spinsh.sh == parentsh.sh) break;
          }
        }
      } // i
    } // if (checksubfaceflag)
  }

  if (loc == INTETRAHEDRON) {
    // Collect the four tets containing 'p'.
    fliptets = new triface[4];
    fliptets[0] = searchtet; // [p,d,a,b]
    for (i = 0; i < 2; i++) {
      fnext(fliptets[i], fliptets[i+1]); // [p,d,b,c], [p,d,c,a]
    }
    eprev(fliptets[0], fliptets[3]);
    fnextself(fliptets[3]); // it is [a,p,b,c]
    eprevself(fliptets[3]);
    esymself(fliptets[3]); // [a,b,c,p].
    // Remove p by a 4-to-1 flip.
    //flip41(fliptets, 1, 0, 0);
    flip41(fliptets, 1, &fc);
    //recenttet = fliptets[0];
  } else if (loc == ONFACE) {
    // Let the original two tets be [a,b,c,d] and [b,a,c,e]. And p is in
    //   face [a,b,c].  Let 'searchtet' be the tet [p,d,a,b].
    // Collect the six tets containing 'p'.
    fliptets = new triface[6];
    fliptets[0] = searchtet; // [p,d,a,b]
    for (i = 0; i < 2; i++) {
      fnext(fliptets[i], fliptets[i+1]); // [p,d,b,c], [p,d,c,a]
    }
    eprev(fliptets[0], fliptets[3]);
    fnextself(fliptets[3]); // [a,p,b,e]
    esymself(fliptets[3]);  // [p,a,e,b]
    eprevself(fliptets[3]); // [e,p,a,b]
    for (i = 3; i < 5; i++) {
      fnext(fliptets[i], fliptets[i+1]); // [e,p,b,c], [e,p,c,a]
    }
    if (vt == FREEFACETVERTEX) {
      // We need to determine the location of three subfaces at p.
      valence = 0; // Re-use it.
      // Check if subfaces are all located in the lower three tets.
      //   i.e., [e,p,a,b], [e,p,b,c], and [e,p,c,a].
      for (i = 3; i < 6; i++) {
        if (issubface(fliptets[i])) valence++;
      }
      if (valence > 0) {
        assert(valence == 2);
        // We must do 3-to-2 flip in the upper part. We simply re-arrange
        //   the six tets.
        for (i = 0; i < 3; i++) {
          esym(fliptets[i+3], wrktets[i]);
          esym(fliptets[i], fliptets[i+3]);
          fliptets[i] = wrktets[i];
        }
        // Swap the last two pairs, i.e., [1]<->[[2], and [4]<->[5]
        wrktets[1] = fliptets[1];
        fliptets[1] = fliptets[2];
        fliptets[2] = wrktets[1];
        wrktets[1] = fliptets[4];
        fliptets[4] = fliptets[5];
        fliptets[5] = wrktets[1];
      }
    }
    // Remove p by a 6-to-2 flip, which is a combination of two flips:
    //   a 3-to-2 (deletes the edge [e,p]), and
    //   a 4-to-1 (deletes the vertex p).
    // First do a 3-to-2 flip on [e,p,a,b],[e,p,b,c],[e,p,c,a]. It creates
    //   two new tets: [a,b,c,p] and [b,a,c,e].  The new tet [a,b,c,p] is
    //   degenerate (has zero volume). It will be deleted in the followed
    //   4-to-1 flip.
    //flip32(&(fliptets[3]), 1, 0, 0);
    flip32(&(fliptets[3]), 1, &fc);
    // Second do a 4-to-1 flip on [p,d,a,b],[p,d,b,c],[p,d,c,a],[a,b,c,p].
    //   This creates a new tet [a,b,c,d].
    //flip41(fliptets, 1, 0, 0);
    flip41(fliptets, 1, &fc);
    //recenttet = fliptets[0];
  } else if (loc == ONEDGE) {
    // Let the original edge be [e,d] and p is in [e,d]. Assume there are n
    //   tets sharing at edge [e,d] originally.  We number the link vertices
    //   of [e,d]: p_0, p_1, ..., p_n-1. 'searchtet' is [p,d,p_0,p_1].
    // Count the number of tets at edge [e,p] and [p,d] (this is n).
    n = 0;
    spintet = searchtet;
    while (1) {
      n++;
      fnextself(spintet);
      if (spintet.tet == searchtet.tet) break;
    }
    assert(n >= 3);
    // Collect the 2n tets containing 'p'.
    fliptets = new triface[2 * n];
    fliptets[0] = searchtet; // [p,b,p_0,p_1]
    for (i = 0; i < (n - 1); i++) {
      fnext(fliptets[i], fliptets[i+1]); // [p,d,p_i,p_i+1].
    }
    eprev(fliptets[0], fliptets[n]);
    fnextself(fliptets[n]); // [p_0,p,p_1,e]
    esymself(fliptets[n]);  // [p,p_0,e,p_1]
    eprevself(fliptets[n]); // [e,p,p_0,p_1]
    for (i = n; i <  (2 * n - 1); i++) {
      fnext(fliptets[i], fliptets[i+1]); // [e,p,p_i,p_i+1].
    }
    // Remove p by a 2n-to-n flip, it is a sequence of n flips:
    // - Do a 2-to-3 flip on
    //     [p_0,p_1,p,d] and
    //     [p,p_1,p_0,e].
    //   This produces:
    //     [e,d,p_0,p_1],
    //     [e,d,p_1,p] (degenerated), and
    //     [e,d,p,p_0] (degenerated).
    wrktets[0] = fliptets[0]; // [p,d,p_0,p_1]
    eprevself(wrktets[0]);    // [p_0,p,d,p_1]
    esymself(wrktets[0]);     // [p,p_0,p_1,d]
    enextself(wrktets[0]);    // [p_0,p_1,p,d] [0]
    wrktets[1] = fliptets[n]; // [e,p,p_0,p_1]
    enextself(wrktets[1]);    // [p,p_0,e,p_1]
    esymself(wrktets[1]);     // [p_0,p,p_1,e]
    eprevself(wrktets[1]);    // [p_1,p_0,p,e] [1]
    //flip23(wrktets, 1, 0, 0);
    flip23(wrktets, 1, &fc);
    // Save the new tet [e,d,p,p_0] (degenerated).
    fliptets[n] = wrktets[2];
    // Save the new tet [e,d,p_0,p_1].
    fliptets[0] = wrktets[0];
    // - Repeat from i = 1 to n-2: (n - 2) flips
    //   - Do a 3-to-2 flip on
    //       [p,p_i,d,e],
    //       [p,p_i,e,p_i+1], and
    //       [p,p_i,p_i+1,d].
    //     This produces:
    //       [d,e,p_i+1,p_i], and
    //       [e,d,p_i+1,p] (degenerated).
    for (i = 1; i < (n - 1); i++) {
      wrktets[0] = wrktets[1]; // [e,d,p_i,p] (degenerated).
      enextself(wrktets[0]);   // [d,p_i,e,p] (...)
      esymself(wrktets[0]);    // [p_i,d,p,e] (...)
      eprevself(wrktets[0]);   // [p,p_i,d,e] (degenerated) [0].
      wrktets[1] = fliptets[n+i];  // [e,p,p_i,p_i+1]
      enextself(wrktets[1]);       // [p,p_i,e,p_i+1] [1]
      wrktets[2] = fliptets[i]; // [p,d,p_i,p_i+1]
      eprevself(wrktets[2]);    // [p_i,p,d,p_i+1]
      esymself(wrktets[2]);     // [p,p_i,p_i+1,d] [2]
      //flip32(wrktets, 1, 0, 0);
      flip32(wrktets, 1, &fc);
      // Save the new tet [e,d,p_i,p_i+1].         // FOR DEBUG ONLY
      fliptets[i] = wrktets[0]; // [d,e,p_i+1,p_i] // FOR DEBUG ONLY
      esymself(fliptets[i]);    // [e,d,p_i,p_i+1] // FOR DEBUG ONLY
    }
    // - Do a 4-to-1 flip on
    //     [p,p_0,e,d],     [d,e,p_0,p],
    //     [p,p_0,d,p_n-1], [e,p_n-1,p_0,p],
    //     [p,p_0,p_n-1,e], [p_0,p_n-1,d,p], and
    //     [e,d,p_n-1,p].
    //   This produces
    //     [e,d,p_n-1,p_0] and
    //     deletes p.
    wrktets[3] = wrktets[1];  // [e,d,p_n-1,p] (degenerated) [3]
    wrktets[0] = fliptets[n]; // [e,d,p,p_0] (degenerated)
    eprevself(wrktets[0]);    // [p,e,d,p_0] (...)
    esymself(wrktets[0]);     // [e,p,p_0,d] (...)
    enextself(wrktets[0]);    // [p,p_0,e,d] (degenerated) [0]
    wrktets[1] = fliptets[n-1];   // [p,d,p_n-1,p_0]
    esymself(wrktets[1]);         // [d,p,p_0,p_n-1]
    enextself(wrktets[1]);        // [p,p_0,d,p_n-1] [1]
    wrktets[2] = fliptets[2*n-1]; // [e,p,p_n-1,p_0]
    enextself(wrktets[2]);        // [p_p_n-1,e,p_0]
    esymself(wrktets[2]);         // [p_n-1,p,p_0,e]
    enextself(wrktets[2]);        // [p,p_0,p_n-1,e] [2]
    //flip41(wrktets, 1, 0, 0);
    flip41(wrktets, 1, &fc);
    // Save the new tet [e,d,p_n-1,p_0]             // FOR DEBUG ONLY
    fliptets[n-1] = wrktets[0];  // [e,d,p_n-1,p_0] // FOR DEBUG ONLY
    //recenttet = fliptets[0];
  } else {
    assert(0); // Unknown location.
  } // if (iloc == ...)

  delete [] fliptets;

  if (vt == FREESEGVERTEX) {
    // Remove the vertex from the surface mesh.
    //   This will re-create the segment [lpt, rpt] and re-triangulate
    //   all the facets at the segment.
    // Only do lawson flip when subfaces are not recovery yet.
    slawson = (checksubfaceflag ? 0 : 1);
    spivot(rightseg, parentsh); // 'rightseg' has p as its origin.
    sremovevertex(steinerpt, &parentsh, &rightseg, slawson);

    // The original segment is returned in 'rightseg'.
    rightseg.shver = 0;
    assert(sorg(rightseg) == lpt);
    assert(sdest(rightseg) == rpt);

    // Insert the new segment.
    point2tetorg(lpt, searchtet);
    finddirection(&searchtet, rpt);
    assert(dest(searchtet) == rpt);
    sstbond1(rightseg, searchtet);
    spintet = searchtet;
    while (1) {
      tsspivot1(spintet, checkseg); // FOR DEBUG ONLY
      assert(checkseg.sh == NULL);  // FOR DEBUG ONLY
      tssbond1(spintet, rightseg);
      fnextself(spintet);
      if (spintet.tet == searchtet.tet) break;
    }

    if (checksubfaceflag) {
      // Insert subfaces at segment [lpt,rpt] into the tetrahedralization.
      spivot(rightseg, parentsh);
      if (parentsh.sh != NULL) {
        spinsh = parentsh;
        while (1) {
          if (sorg(spinsh) != lpt) {
            sesymself(spinsh);
            assert(sorg(spinsh) == lpt);
          }
          assert(sdest(spinsh) == rpt);
          apexpt = sapex(spinsh);
          // Find the adjacent tet of [lpt,rpt,apexpt];
          spintet = searchtet;
          while (1) {
            if (apex(spintet) == apexpt) {
              tsbond(spintet, spinsh);
              sesymself(spinsh); // Get to another side of this face.
              fsym(spintet, neightet);
              tsbond(neightet, spinsh);
              sesymself(spinsh); // Get back to the original side.
              break;
            }
            fnextself(spintet);
            assert(spintet.tet != searchtet.tet);
            //if (spintet.tet == searchtet.tet) break;
          }
          spivotself(spinsh);
          if (spinsh.sh == parentsh.sh) break;
        }
      }
    } // if (checksubfaceflag)

    // Clear the set of new subfaces.
    caveshbdlist->restart();
  } // if (vt == FREESEGVERTEX)

  // The point has been removed.
  if (pointtype(steinerpt) != UNUSEDVERTEX) {
    setpointtype(steinerpt, UNUSEDVERTEX);
    unuverts++;
  }
  if (vt != VOLVERTEX) {
    // Update the correspinding counters.
    if (vt == FREESEGVERTEX) {
      st_segref_count--;
    } else if (vt == FREEFACETVERTEX) {
      st_facref_count--;
    } else if (vt == FREEVOLVERTEX) {
      st_volref_count--;
    }
    if (steinerleft > 0) steinerleft++;
  }

  return 1;
}

int meshGRegionBoundaryRecovery::suppressbdrysteinerpoint(point steinerpt)
{
  face parentsh, spinsh, *parysh;
  face leftseg, rightseg;
  point lpt = NULL, rpt = NULL;
  int i;

  verttype vt = pointtype(steinerpt);

  if (vt == FREESEGVERTEX) {
    sdecode(point2sh(steinerpt), leftseg);
    leftseg.shver = 0;
    if (sdest(leftseg) == steinerpt) {
      senext(leftseg, rightseg);
      spivotself(rightseg);
      assert(rightseg.sh != NULL);
      rightseg.shver = 0;
      assert(sorg(rightseg) == steinerpt);
    } else {
      assert(sorg(leftseg) == steinerpt);
      rightseg = leftseg;
      senext2(rightseg, leftseg);
      spivotself(leftseg);
      assert(leftseg.sh != NULL);
      leftseg.shver = 0;
      assert(sdest(leftseg) == steinerpt);
    }
    lpt = sorg(leftseg);
    rpt = sdest(rightseg);
    if (b->verbose > 2) {
      printf("      Suppressing Steiner point %d in segment (%d, %d).\n",
             pointmark(steinerpt), pointmark(lpt), pointmark(rpt));
    }
    // Get all subfaces at the left segment [lpt, steinerpt].
    spivot(leftseg, parentsh);
    spinsh = parentsh;
    while (1) {
      cavesegshlist->newindex((void **) &parysh);
      *parysh = spinsh;
      // Orient the face consistently.
      if (sorg(*parysh)!= sorg(parentsh)) sesymself(*parysh);
      spivotself(spinsh);
      if (spinsh.sh == NULL) break;
      if (spinsh.sh == parentsh.sh) break;
    }
    if (cavesegshlist->objects < 2) {
      // It is a single segment. Not handle it yet.
      cavesegshlist->restart();
      return 0;
    }
  } else if (vt == FREEFACETVERTEX) {
    if (b->verbose > 2) {
      printf("      Suppressing Steiner point %d from facet.\n",
             pointmark(steinerpt));
    }
    sdecode(point2sh(steinerpt), parentsh);
    // A facet Steiner point. There are exactly two sectors.
    for (i = 0; i < 2; i++) {
      cavesegshlist->newindex((void **) &parysh);
      *parysh = parentsh;
      sesymself(parentsh);
    }
  } else {
    return 0;
  }

  triface searchtet, neightet, *parytet;
  point pa, pb, pc, pd;
  REAL v1[3], v2[3], len, u;

  REAL startpt[3] = {0,}, samplept[3] = {0,}, candpt[3] = {0,};
  REAL ori, minvol, smallvol;
  int samplesize;
  int it, j, k;

  int n = (int) cavesegshlist->objects;
  point *newsteiners = new point[n];
  for (i = 0; i < n; i++) newsteiners[i] = NULL;

  // Search for each sector an interior vertex.
  for (i = 0; i < cavesegshlist->objects; i++) {
    parysh = (face *) fastlookup(cavesegshlist, i);
    stpivot(*parysh, searchtet);
    // Skip it if it is outside.
    if (ishulltet(searchtet)) continue;
    // Get the "half-ball". Tets in 'cavetetlist' all contain 'steinerpt' as
    //   opposite.  Subfaces in 'caveshlist' all contain 'steinerpt' as apex.
    //   Moreover, subfaces are oriented towards the interior of the ball.
    setpoint2tet(steinerpt, encode(searchtet));
    getvertexstar(0, steinerpt, cavetetlist, NULL, caveshlist);
    // Calculate the searching vector.
    pa = sorg(*parysh);
    pb = sdest(*parysh);
    pc = sapex(*parysh);
    facenormal(pa, pb, pc, v1, 1, NULL);
    len = sqrt(dot(v1, v1));
    assert(len > 0.0);
    v1[0] /= len;
    v1[1] /= len;
    v1[2] /= len;
    if (vt == FREESEGVERTEX) {
      parysh = (face *) fastlookup(cavesegshlist, (i + 1) % n);
      pd = sapex(*parysh);
      facenormal(pb, pa, pd, v2, 1, NULL);
      len = sqrt(dot(v2, v2));
      assert(len > 0.0);
      v2[0] /= len;
      v2[1] /= len;
      v2[2] /= len;
      // Average the two vectors.
      v1[0] = 0.5 * (v1[0] + v2[0]);
      v1[1] = 0.5 * (v1[1] + v2[1]);
      v1[2] = 0.5 * (v1[2] + v2[2]);
    }
    // Search the intersection of the ray starting from 'steinerpt' to
    //   the search direction 'v1' and the shell of the half-ball.
    // - Construct an endpoint.
    len = distance(pa, pb);
    v2[0] = steinerpt[0] + len * v1[0];
    v2[1] = steinerpt[1] + len * v1[1];
    v2[2] = steinerpt[2] + len * v1[2];
    for (j = 0; j < cavetetlist->objects; j++) {
      parytet = (triface *) fastlookup(cavetetlist, j);
      pa = org(*parytet);
      pb = dest(*parytet);
      pc = apex(*parytet);
      // Test if the ray startpt->v2 lies in the cone: where 'steinerpt'
      //   is the apex, and three sides are defined by the triangle
      //   [pa, pb, pc].
      ori = orient3d(steinerpt, pa, pb, v2);
      if (ori >= 0) {
        ori = orient3d(steinerpt, pb, pc, v2);
        if (ori >= 0) {
          ori = orient3d(steinerpt, pc, pa, v2);
          if (ori >= 0) {
            // Found! Calculate the intersection.
            planelineint(pa, pb, pc, steinerpt, v2, startpt, &u);
            assert(u != 0.0);
            break;
          }
        }
      }
    } // j
    assert(j < cavetetlist->objects); // There must be an intersection.
    // Close the ball by adding the subfaces.
    for (j = 0; j < caveshlist->objects; j++) {
      parysh = (face *) fastlookup(caveshlist, j);
      stpivot(*parysh, neightet);
      cavetetlist->newindex((void **) &parytet);
      *parytet = neightet;
    }
    // Search a best point inside the segment [startpt, steinerpt].
    it = 0;
    samplesize = 100;
    v1[0] = steinerpt[0] - startpt[0];
    v1[1] = steinerpt[1] - startpt[1];
    v1[2] = steinerpt[2] - startpt[2];
    minvol = -1.0;
    while (it < 3) {
      for (j = 1; j < samplesize - 1; j++) {
        samplept[0] = startpt[0] + ((REAL) j / (REAL) samplesize) * v1[0];
        samplept[1] = startpt[1] + ((REAL) j / (REAL) samplesize) * v1[1];
        samplept[2] = startpt[2] + ((REAL) j / (REAL) samplesize) * v1[2];
        // Find the minimum volume for 'samplept'.
        smallvol = -1;
        for (k = 0; k < cavetetlist->objects; k++) {
          parytet = (triface *) fastlookup(cavetetlist, k);
          pa = org(*parytet);
          pb = dest(*parytet);
          pc = apex(*parytet);
          ori = orient3d(pb, pa, pc, samplept);
          if (ori <= 0) {
            break; // An invalid tet.
          }
          if (smallvol == -1) {
            smallvol = ori;
          } else {
            if (ori < smallvol) smallvol = ori;
          }
        } // k
        if (k == cavetetlist->objects) {
          // Found a valid point. Remember it.
          if (minvol == -1.0) {
            candpt[0] = samplept[0];
            candpt[1] = samplept[1];
            candpt[2] = samplept[2];
            minvol = smallvol;
          } else {
            if (minvol < smallvol) {
              // It is a better location. Remember it.
              candpt[0] = samplept[0];
              candpt[1] = samplept[1];
              candpt[2] = samplept[2];
              minvol = smallvol;
            } else {
              // No improvement of smallest volume.
              // Since we are searching along the line [startpt, steinerpy],
              // The smallest volume can only be decreased later.
              break;
            }
          }
        }
      } // j
      if (minvol > 0) break;
      samplesize *= 10;
      it++;
    } // while (it < 3)
    if (minvol == -1.0) {
      // Failed to find a valid point.
      cavetetlist->restart();
      caveshlist->restart();
      break;
    }
    // Create a new Steiner point inside this section.
    makepoint(&(newsteiners[i]), FREEVOLVERTEX);
    newsteiners[i][0] = candpt[0];
    newsteiners[i][1] = candpt[1];
    newsteiners[i][2] = candpt[2];
    cavetetlist->restart();
    caveshlist->restart();
  } // i

  if (i < cavesegshlist->objects) {
    // Failed to suppress the vertex.
    for (; i > 0; i--) {
      if (newsteiners[i - 1] != NULL) {
        pointdealloc(newsteiners[i - 1]);
      }
    }
    delete [] newsteiners;
    cavesegshlist->restart();
    return 0;
  }

  // Remove p from the segment or the facet.
  triface newtet, newface, spintet;
  face newsh, neighsh;
  face *splitseg, checkseg;
  int slawson = 0; // Do not do flip afterword.
  int t1ver;

  if (vt == FREESEGVERTEX) {
    // Detach 'leftseg' and 'rightseg' from their adjacent tets.
    //   These two subsegments will be deleted.
    sstpivot1(leftseg, neightet);
    spintet = neightet;
    while (1) {
      tssdissolve1(spintet);
      fnextself(spintet);
      if (spintet.tet == neightet.tet) break;
    }
    sstpivot1(rightseg, neightet);
    spintet = neightet;
    while (1) {
      tssdissolve1(spintet);
      fnextself(spintet);
      if (spintet.tet == neightet.tet) break;
    }
  }

  // Loop through all sectors bounded by facets at this segment.
  //   Within each sector, create a new Steiner point 'np', and replace 'p'
  //   by 'np' for all tets in this sector.
  for (i = 0; i < cavesegshlist->objects; i++) {
    parysh = (face *) fastlookup(cavesegshlist, i);
    // 'parysh' is the face [lpt, steinerpt, #].
    stpivot(*parysh, neightet);
    // Get all tets in this sector.
    setpoint2tet(steinerpt, encode(neightet));
    getvertexstar(0, steinerpt, cavetetlist, NULL, caveshlist);
    if (!ishulltet(neightet)) {
      // Within each tet in the ball, replace 'p' by 'np'.
      for (j = 0; j < cavetetlist->objects; j++) {
        parytet = (triface *) fastlookup(cavetetlist, j);
        setoppo(*parytet, newsteiners[i]);
      } // j
      // Point to a parent tet.
      parytet = (triface *) fastlookup(cavetetlist, 0);
      setpoint2tet(newsteiners[i], (tetrahedron) (parytet->tet));
      st_volref_count++;
      if (steinerleft > 0) steinerleft--;
    }
    // Disconnect the set of boundary faces. They're temporarily open faces.
    //   They will be connected to the new tets after 'p' is removed.
    for (j = 0; j < caveshlist->objects; j++) {
      // Get a boundary face.
      parysh = (face *) fastlookup(caveshlist, j);
      stpivot(*parysh, neightet);
      //assert(apex(neightet) == newpt);
      // Clear the connection at this face.
      dissolve(neightet);
      tsdissolve(neightet);
    }
    // Clear the working lists.
    cavetetlist->restart();
    caveshlist->restart();
  } // i
  cavesegshlist->restart();

  if (vt == FREESEGVERTEX) {
    spivot(rightseg, parentsh); // 'rightseg' has p as its origin.
    splitseg = &rightseg;
  } else {
    if (sdest(parentsh) == steinerpt) {
      senextself(parentsh);
    } else if (sapex(parentsh) == steinerpt) {
      senext2self(parentsh);
    }
    assert(sorg(parentsh) == steinerpt);
    splitseg = NULL;
  }
  sremovevertex(steinerpt, &parentsh, splitseg, slawson);

  if (vt == FREESEGVERTEX) {
    // The original segment is returned in 'rightseg'.
    rightseg.shver = 0;
  }

  // For each new subface, create two new tets at each side of it.
  //   Both of the two new tets have its opposite be dummypoint.
  for (i = 0; i < caveshbdlist->objects; i++) {
    parysh = (face *) fastlookup(caveshbdlist, i);
    sinfect(*parysh); // Mark it for connecting new tets.
    newsh = *parysh;
    pa = sorg(newsh);
    pb = sdest(newsh);
    pc = sapex(newsh);
    maketetrahedron(&newtet);
    maketetrahedron(&neightet);
    setvertices(newtet, pa, pb, pc, dummypoint);
    setvertices(neightet, pb, pa, pc, dummypoint);
    bond(newtet, neightet);
    tsbond(newtet, newsh);
    sesymself(newsh);
    tsbond(neightet, newsh);
  }
  // Temporarily increase the hullsize.
  hullsize += (caveshbdlist->objects * 2l);

  if (vt == FREESEGVERTEX) {
    // Connecting new tets at the recovered segment.
    spivot(rightseg, parentsh);
    assert(parentsh.sh != NULL);
    spinsh = parentsh;
    while (1) {
      if (sorg(spinsh) != lpt) sesymself(spinsh);
      // Get the new tet at this subface.
      stpivot(spinsh, newtet);
      tssbond1(newtet, rightseg);
      // Go to the other face at this segment.
      spivot(spinsh, neighsh);
      if (sorg(neighsh) != lpt) sesymself(neighsh);
      sesymself(neighsh);
      stpivot(neighsh, neightet);
      tssbond1(neightet, rightseg);
      sstbond1(rightseg, neightet);
      // Connecting two adjacent tets at this segment.
      esymself(newtet);
      esymself(neightet);
      // Connect the two tets (at rightseg) together.
      bond(newtet, neightet);
      // Go to the next subface.
      spivotself(spinsh);
      if (spinsh.sh == parentsh.sh) break;
    }
  }

  // Connecting new tets at new subfaces together.
  for (i = 0; i < caveshbdlist->objects; i++) {
    parysh = (face *) fastlookup(caveshbdlist, i);
    newsh = *parysh;
    //assert(sinfected(newsh));
    // Each new subface contains two new tets.
    for (k = 0; k < 2; k++) {
      stpivot(newsh, newtet);
      for (j = 0; j < 3; j++) {
        // Check if this side is open.
        esym(newtet, newface);
        if (newface.tet[newface.ver & 3] == NULL) {
          // An open face. Connect it to its adjacent tet.
          sspivot(newsh, checkseg);
          if (checkseg.sh != NULL) {
            // A segment. It must not be the recovered segment.
            tssbond1(newtet, checkseg);
            sstbond1(checkseg, newtet);
          }
          spivot(newsh, neighsh);
          if (neighsh.sh != NULL) {
            // The adjacent subface exists. It's not a dangling segment.
            if (sorg(neighsh) != sdest(newsh)) sesymself(neighsh);
            stpivot(neighsh, neightet);
            if (sinfected(neighsh)) {
              esymself(neightet);
              assert(neightet.tet[neightet.ver & 3] == NULL);
            } else {
              // Search for an open face at this edge.
              spintet = neightet;
              while (1) {
                esym(spintet, searchtet);
                fsym(searchtet, spintet);
                if (spintet.tet == NULL) break;
                assert(spintet.tet != neightet.tet);
              }
              // Found an open face at 'searchtet'.
              neightet = searchtet;
            }
          } else {
            // The edge (at 'newsh') is a dangling segment.
            assert(checkseg.sh != NULL);
            // Get an adjacent tet at this segment.
            sstpivot1(checkseg, neightet);
            assert(!isdeadtet(neightet));
            if (org(neightet) != sdest(newsh)) esymself(neightet);
            assert((org(neightet) == sdest(newsh)) &&
                   (dest(neightet) == sorg(newsh)));
            // Search for an open face at this edge.
            spintet = neightet;
            while (1) {
              esym(spintet, searchtet);
              fsym(searchtet, spintet);
              if (spintet.tet == NULL) break;
              assert(spintet.tet != neightet.tet);
            }
            // Found an open face at 'searchtet'.
            neightet = searchtet;
          }
          pc = apex(newface);
          if (apex(neightet) == steinerpt) {
            // Exterior case. The 'neightet' is a hull tet which contain
            //   'steinerpt'. It will be deleted after 'steinerpt' is removed.
            assert(pc == dummypoint);
            caveoldtetlist->newindex((void **) &parytet);
            *parytet = neightet;
            // Connect newface to the adjacent hull tet of 'neightet', which
            //   has the same edge as 'newface', and does not has 'steinerpt'.
            fnextself(neightet);
          } else {
            if (pc == dummypoint) {
              if (apex(neightet) != dummypoint) {
                setapex(newface, apex(neightet));
                // A hull tet has turned into an interior tet.
                hullsize--; // Must update the hullsize.
              }
            }
          }
          bond(newface, neightet);
        } // if (newface.tet[newface.ver & 3] == NULL)
        enextself(newtet);
        senextself(newsh);
      } // j
      sesymself(newsh);
    } // k
  } // i

  // Unmark all new subfaces.
  for (i = 0; i < caveshbdlist->objects; i++) {
    parysh = (face *) fastlookup(caveshbdlist, i);
    suninfect(*parysh);
  }
  caveshbdlist->restart();

  if (caveoldtetlist->objects > 0l) {
    // Delete hull tets which contain 'steinerpt'.
    for (i = 0; i < caveoldtetlist->objects; i++) {
      parytet = (triface *) fastlookup(caveoldtetlist, i);
      tetrahedrondealloc(parytet->tet);
    }
    // Must update the hullsize.
    hullsize -= caveoldtetlist->objects;
    caveoldtetlist->restart();
  }

  setpointtype(steinerpt, UNUSEDVERTEX);
  unuverts++;
  if (vt == FREESEGVERTEX) {
    st_segref_count--;
  } else { // vt == FREEFACETVERTEX
    st_facref_count--;
  }
  if (steinerleft > 0) steinerleft++;  // We've removed a Steiner points.


  point *parypt;
  int steinercount = 0;

  int bak_fliplinklevel = b->fliplinklevel;
  b->fliplinklevel = 100000; // Unlimited flip level.

  // Try to remove newly added Steiner points.
  for (i = 0; i < n; i++) {
    if (newsteiners[i] != NULL) {
      if (!removevertexbyflips(newsteiners[i])) {
        if (b->nobisect_param > 0) { // Not -Y0
          // Save it in subvertstack for removal.
          subvertstack->newindex((void **) &parypt);
          *parypt = newsteiners[i];
        }
        steinercount++;
      }
    }
  }

  b->fliplinklevel = bak_fliplinklevel;

  if (steinercount > 0) {
    if (b->verbose > 2) {
      printf("      Added %d interior Steiner points.\n", steinercount);
    }
  }

  delete [] newsteiners;

  return 1;
}


int meshGRegionBoundaryRecovery::suppresssteinerpoints()
{

  if (!b->quiet) {
    printf("Suppressing Steiner points ...\n");
  }

  point rempt, *parypt;

  int bak_fliplinklevel = b->fliplinklevel;
  b->fliplinklevel = 100000; // Unlimited flip level.
  int suppcount = 0, remcount = 0;
  int i;

  // Try to suppress boundary Steiner points.
  for (i = 0; i < subvertstack->objects; i++) {
    parypt = (point *) fastlookup(subvertstack, i);
    rempt = *parypt;
    if (pointtype(rempt) != UNUSEDVERTEX) {
      if ((pointtype(rempt) == FREESEGVERTEX) ||
          (pointtype(rempt) == FREEFACETVERTEX)) {
        if (suppressbdrysteinerpoint(rempt)) {
          suppcount++;
        }
      }
    }
  } // i

  if (suppcount > 0) {
    if (b->verbose) {
      printf("  Suppressed %d boundary Steiner points.\n", suppcount);
    }
  }

  if (b->nobisect_param > 0) { // -Y1
    for (i = 0; i < subvertstack->objects; i++) {
      parypt = (point *) fastlookup(subvertstack, i);
      rempt = *parypt;
      if (pointtype(rempt) != UNUSEDVERTEX) {
        if (pointtype(rempt) == FREEVOLVERTEX) {
          if (removevertexbyflips(rempt)) {
            remcount++;
          }
        }
      }
    }
  }

  if (remcount > 0) {
    if (b->verbose) {
      printf("  Removed %d interior Steiner points.\n", remcount);
    }
  }

  b->fliplinklevel = bak_fliplinklevel;

  if (b->nobisect_param > 1) { // -Y2
    // Smooth interior Steiner points.
    optparameters opm;
    triface *parytet;
    point *ppt;
    REAL ori;
    int smtcount, count, ivcount;
    int nt, j;

    // Point smooth options.
    opm.max_min_volume = 1;
    opm.numofsearchdirs = 20;
    opm.searchstep = 0.001;
    opm.maxiter = 30; // Limit the maximum iterations.

    smtcount = 0;

    do {

      nt = 0;

      while (1) {
        count = 0;
        ivcount = 0; // Clear the inverted count.

        for (i = 0; i < subvertstack->objects; i++) {
          parypt = (point *) fastlookup(subvertstack, i);
          rempt = *parypt;
          if (pointtype(rempt) == FREEVOLVERTEX) {
            getvertexstar(1, rempt, cavetetlist, NULL, NULL);
            // Calculate the initial smallest volume (maybe zero or negative).
            for (j = 0; j < cavetetlist->objects; j++) {
              parytet = (triface *) fastlookup(cavetetlist, j);
              ppt = (point *) &(parytet->tet[4]);
              ori = orient3dfast(ppt[1], ppt[0], ppt[2], ppt[3]);
              if (j == 0) {
                opm.initval = ori;
              } else {
                if (opm.initval > ori) opm.initval = ori;
              }
            }
            if (smoothpoint(rempt, cavetetlist, 1, &opm)) {
              count++;
            }
            if (opm.imprval <= 0.0) {
              ivcount++; // The mesh contains inverted elements.
            }
            cavetetlist->restart();
          }
        } // i

        smtcount += count;

        if (count == 0) {
          // No point has been smoothed.
          break;
        }

        nt++;
        if (nt > 2) {
          break; // Already three iterations.
        }
      } // while

      if (ivcount > 0) {
        // There are inverted elements!
        if (opm.maxiter > 0) {
          // Set unlimited smoothing steps. Try again.
          opm.numofsearchdirs = 30;
          opm.searchstep = 0.0001;
          opm.maxiter = -1;
          continue;
        }
      }

      break;
    } while (1); // Additional loop for (ivcount > 0)

    if (ivcount > 0) {
      printf("BUG Report!  The mesh contain inverted elements.\n");
    }

    if (b->verbose) {
      if (smtcount > 0) {
        printf("  Smoothed %d Steiner points.\n", smtcount);
      }
    }
  } // -Y2

  subvertstack->restart();

  return 1;
}

void meshGRegionBoundaryRecovery::recoverboundary(clock_t&)
{
  arraypool *misseglist, *misshlist;
  arraypool *bdrysteinerptlist;
  face searchsh, *parysh;
  face searchseg, *paryseg;
  point rempt, *parypt;
  long ms; // The number of missing segments/subfaces.
  int nit; // The number of iterations.
  int s, i;

  // Counters.
  long bak_segref_count, bak_facref_count, bak_volref_count;

  if (!b->quiet) {
    printf("Recovering boundaries...\n");
  }


  if (b->verbose) {
    printf("  Recovering segments.\n");
  }

  // Segments will be introduced.
  checksubsegflag = 1;

  misseglist = new arraypool(sizeof(face), 8);
  bdrysteinerptlist = new arraypool(sizeof(point), 8);

  // In random order.
  subsegs->traversalinit();
  for (i = 0; i < subsegs->items; i++) {
    s = randomnation(i + 1);
    // Move the s-th seg to the i-th.
    subsegstack->newindex((void **) &paryseg);
    *paryseg = * (face *) fastlookup(subsegstack, s);
    // Put i-th seg to be the s-th.
    searchseg.sh = shellfacetraverse(subsegs);
    paryseg = (face *) fastlookup(subsegstack, s);
    *paryseg = searchseg;
  }

  // The init number of missing segments.
  ms = subsegs->items;
  nit = 0;
  if (b->fliplinklevel < 0) {
    autofliplinklevel = 1; // Init value.
  }

  // First, trying to recover segments by only doing flips.
  while (1) {
    recoversegments(misseglist, 0, 0);

    if (misseglist->objects > 0) {
      if (b->fliplinklevel >= 0) {
        break;
      } else {
        if (misseglist->objects >= ms) {
          nit++;
          if (nit >= 3) {
            //break;
            // Do the last round with unbounded flip link level.
            b->fliplinklevel = 100000;
          }
        } else {
          ms = misseglist->objects;
          if (nit > 0) {
            nit--;
          }
        }
        for (i = 0; i < misseglist->objects; i++) {
          subsegstack->newindex((void **) &paryseg);
          *paryseg = * (face *) fastlookup(misseglist, i);
        }
        misseglist->restart();
        autofliplinklevel+=b->fliplinklevelinc;
      }
    } else {
      // All segments are recovered.
      break;
    }
  } // while (1)

  if (b->verbose) {
    printf("  %ld (%ld) segments are recovered (missing).\n",
           subsegs->items - misseglist->objects, misseglist->objects);
  }

  if (misseglist->objects > 0) {
    // Second, trying to recover segments by doing more flips (fullsearch).
    while (misseglist->objects > 0) {
      ms = misseglist->objects;
      for (i = 0; i < misseglist->objects; i++) {
        subsegstack->newindex((void **) &paryseg);
        *paryseg = * (face *) fastlookup(misseglist, i);
      }
      misseglist->restart();

      recoversegments(misseglist, 1, 0);

      if (misseglist->objects < ms) {
        // The number of missing segments is reduced.
        continue;
      } else {
        break;
      }
    }
    if (b->verbose) {
      printf("  %ld (%ld) segments are recovered (missing).\n",
             subsegs->items - misseglist->objects, misseglist->objects);
    }
  }

  if (misseglist->objects > 0) {
    // Third, trying to recover segments by doing more flips (fullsearch)
    //   and adding Steiner points in the volume.
    while (misseglist->objects > 0) {
      ms = misseglist->objects;
      for (i = 0; i < misseglist->objects; i++) {
        subsegstack->newindex((void **) &paryseg);
        *paryseg = * (face *) fastlookup(misseglist, i);
      }
      misseglist->restart();

      recoversegments(misseglist, 1, 1);

      if (misseglist->objects < ms) {
        // The number of missing segments is reduced.
        continue;
      } else {
        break;
      }
    }
    if (b->verbose) {
      printf("  Added %ld Steiner points in volume.\n", st_volref_count);
    }
  }

  if (misseglist->objects > 0) {
    // Last, trying to recover segments by doing more flips (fullsearch),
    //   and adding Steiner points in the volume, and splitting segments.
    long bak_inpoly_count = st_volref_count; //st_inpoly_count;
    for (i = 0; i < misseglist->objects; i++) {
      subsegstack->newindex((void **) &paryseg);
      *paryseg = * (face *) fastlookup(misseglist, i);
    }
    misseglist->restart();

    recoversegments(misseglist, 1, 2);

    if (b->verbose) {
      printf("  Added %ld Steiner points in segments.\n", st_segref_count);
      if (st_volref_count > bak_inpoly_count) {
        printf("  Added another %ld Steiner points in volume.\n",
               st_volref_count - bak_inpoly_count);
      }
    }
    assert(misseglist->objects == 0l);
  }


  if (st_segref_count > 0) {
    // Try to remove the Steiner points added in segments.
    bak_segref_count = st_segref_count;
    bak_volref_count = st_volref_count;
    for (i = 0; i < subvertstack->objects; i++) {
      // Get the Steiner point.
      parypt = (point *) fastlookup(subvertstack, i);
      rempt = *parypt;
      if (!removevertexbyflips(rempt)) {
        // Save it in list.
        bdrysteinerptlist->newindex((void **) &parypt);
        *parypt = rempt;
      }
    }
    if (b->verbose) {
      if (st_segref_count < bak_segref_count) {
        if (bak_volref_count < st_volref_count) {
          printf("  Suppressed %ld Steiner points in segments.\n",
                 st_volref_count - bak_volref_count);
        }
        if ((st_segref_count + (st_volref_count - bak_volref_count)) <
            bak_segref_count) {
          printf("  Removed %ld Steiner points in segments.\n",
                 bak_segref_count -
                   (st_segref_count + (st_volref_count - bak_volref_count)));
        }
      }
    }
    subvertstack->restart();
  }


  if (b->verbose) {
    printf("  Recovering facets.\n");
  }

  // Subfaces will be introduced.
  checksubfaceflag = 1;

  misshlist = new arraypool(sizeof(face), 8);

  // Randomly order the subfaces.
  subfaces->traversalinit();
  for (i = 0; i < subfaces->items; i++) {
    s = randomnation(i + 1);
    // Move the s-th subface to the i-th.
    subfacstack->newindex((void **) &parysh);
    *parysh = * (face *) fastlookup(subfacstack, s);
    // Put i-th subface to be the s-th.
    searchsh.sh = shellfacetraverse(subfaces);
    parysh = (face *) fastlookup(subfacstack, s);
    *parysh = searchsh;
  }

  ms = subfaces->items;
  nit = 0;
  b->fliplinklevel = -1; // Init.
  if (b->fliplinklevel < 0) {
    autofliplinklevel = 1; // Init value.
  }

  while (1) {
    recoversubfaces(misshlist, 0);

    if (misshlist->objects > 0) {
      if (b->fliplinklevel >= 0) {
        break;
      } else {
        if (misshlist->objects >= ms) {
          nit++;
          if (nit >= 3) {
            //break;
            // Do the last round with unbounded flip link level.
            b->fliplinklevel = 100000;
          }
        } else {
          ms = misshlist->objects;
          if (nit > 0) {
            nit--;
          }
        }
        for (i = 0; i < misshlist->objects; i++) {
          subfacstack->newindex((void **) &parysh);
          *parysh = * (face *) fastlookup(misshlist, i);
        }
        misshlist->restart();
        autofliplinklevel+=b->fliplinklevelinc;
      }
    } else {
      // All subfaces are recovered.
      break;
    }
  } // while (1)

  if (b->verbose) {
    printf("  %ld (%ld) subfaces are recovered (missing).\n",
           subfaces->items - misshlist->objects, misshlist->objects);
  }

  if (misshlist->objects > 0) {
    // There are missing subfaces. Add Steiner points.
    for (i = 0; i < misshlist->objects; i++) {
      subfacstack->newindex((void **) &parysh);
      *parysh = * (face *) fastlookup(misshlist, i);
    }
    misshlist->restart();

    recoversubfaces(NULL, 1);

    if (b->verbose) {
      printf("  Added %ld Steiner points in facets.\n", st_facref_count);
    }
  }


  if (st_facref_count > 0) {
    // Try to remove the Steiner points added in facets.
    bak_facref_count = st_facref_count;
    for (i = 0; i < subvertstack->objects; i++) {
      // Get the Steiner point.
      parypt = (point *) fastlookup(subvertstack, i);
      rempt = *parypt;
      if (!removevertexbyflips(*parypt)) {
        // Save it in list.
        bdrysteinerptlist->newindex((void **) &parypt);
        *parypt = rempt;
      }
    }
    if (b->verbose) {
      if (st_facref_count < bak_facref_count) {
        printf("  Removed %ld Steiner points in facets.\n",
               bak_facref_count - st_facref_count);
      }
    }
    subvertstack->restart();
  }


  if (bdrysteinerptlist->objects > 0) {
    if (b->verbose) {
      printf("  %ld Steiner points remained in boundary.\n",
             bdrysteinerptlist->objects);
    }
  } // if


  // Accumulate the dynamic memory.
  totalworkmemory += (misseglist->totalmemory + misshlist->totalmemory +
                      bdrysteinerptlist->totalmemory);

  delete bdrysteinerptlist;
  delete misseglist;
  delete misshlist;
}

////                                                                       ////
////                                                                       ////
//// steiner_cxx //////////////////////////////////////////////////////////////


//// reconstruct_cxx //////////////////////////////////////////////////////////
////                                                                       ////
////                                                                       ////

void meshGRegionBoundaryRecovery::carveholes()
{
  arraypool *tetarray, *hullarray;
  triface tetloop, neightet, *parytet, *parytet1;
  triface *regiontets = NULL;
  face checksh, *parysh;
  face checkseg;
  point ptloop, *parypt;
  int t1ver;
  int i, j, k;

  if (!b->quiet) {
    if (b->convex) {
      printf("Marking exterior tetrahedra ...\n");
    } else {
      printf("Removing exterior tetrahedra ...\n");
    }
  }

  // Initialize the pool of exterior tets.
  tetarray = new arraypool(sizeof(triface), 10);
  hullarray = new arraypool(sizeof(triface), 10);

  // Collect unprotected tets and hull tets.
  tetrahedrons->traversalinit();
  tetloop.ver = 11; // The face opposite to dummypoint.
  tetloop.tet = alltetrahedrontraverse();
  while (tetloop.tet != (tetrahedron *) NULL) {
    if (ishulltet(tetloop)) {
      // Is this side protected by a subface?
      if (!issubface(tetloop)) {
        // Collect an unprotected hull tet and tet.
        infect(tetloop);
        hullarray->newindex((void **) &parytet);
        *parytet = tetloop;
        // tetloop's face number is 11 & 3 = 3.
        decode(tetloop.tet[3], neightet);
        if (!infected(neightet)) {
          infect(neightet);
          tetarray->newindex((void **) &parytet);
          *parytet = neightet;
        }
      }
    }
    tetloop.tet = alltetrahedrontraverse();
  }

  // Collect all exterior tets (in concave place and in holes).
  for (i = 0; i < tetarray->objects; i++) {
    parytet = (triface *) fastlookup(tetarray, i);
    j = (parytet->ver & 3); // j is the current face number.
    // Check the other three adjacent tets.
    for (k = 1; k < 4; k++) {
      decode(parytet->tet[(j + k) % 4], neightet);
      // neightet may be a hull tet.
      if (!infected(neightet)) {
        // Is neightet protected by a subface.
        if (!issubface(neightet)) {
          // Not proected. Collect it. (It must not be a hull tet).
          infect(neightet);
          tetarray->newindex((void **) &parytet1);
          *parytet1 = neightet;
        } else {
          // Protected. Check if it is a hull tet.
          if (ishulltet(neightet)) {
            // A hull tet. Collect it.
            infect(neightet);
            hullarray->newindex((void **) &parytet1);
            *parytet1 = neightet;
            // Both sides of this subface are exterior.
            tspivot(neightet, checksh);
            // Queue this subface (to be deleted later).
            assert(!sinfected(checksh));
            sinfect(checksh); // Only queue it once.
            subfacstack->newindex((void **) &parysh);
            *parysh = checksh;
          }
        }
      } else {
        // Both sides of this face are in exterior.
        // If there is a subface. It should be collected.
        if (issubface(neightet)) {
          tspivot(neightet, checksh);
          if (!sinfected(checksh)) {
            sinfect(checksh);
            subfacstack->newindex((void **) &parysh);
            *parysh = checksh;
          }
        }
      }
    } // j, k
  } // i

  // Collect vertices which point to infected tets. These vertices
  //   may get deleted after the removal of exterior tets.
  //   If -Y1 option is used, collect all Steiner points for removal.
  //   The lists 'cavetetvertlist' and 'subvertstack' are re-used.
  points->traversalinit();
  ptloop = pointtraverse();
  while (ptloop != NULL) {
    if ((pointtype(ptloop) != UNUSEDVERTEX) &&
        (pointtype(ptloop) != DUPLICATEDVERTEX)) {
      decode(point2tet(ptloop), neightet);
      if (infected(neightet)) {
        cavetetvertlist->newindex((void **) &parypt);
        *parypt = ptloop;
      }
      if (b->nobisect && (b->nobisect_param > 0)) { // -Y1
        // Queue it if it is a Steiner point.
        //if (pointmark(ptloop) >
        //      (in->numberofpoints - (in->firstnumber ? 0 : 1))) {
        if (issteinerpoint(ptloop)) {
          subvertstack->newindex((void **) &parypt);
          *parypt = ptloop;
        }
      }
    }
    ptloop = pointtraverse();
  }

  if (!b->convex && (tetarray->objects > 0l)) { // No -c option.
    // Remove exterior tets. Hull tets are updated.
    arraypool *newhullfacearray;
    triface hulltet, casface;
    point pa, pb, pc;

    newhullfacearray = new arraypool(sizeof(triface), 10);

    // Create and save new hull tets.
    for (i = 0; i < tetarray->objects; i++) {
      parytet = (triface *) fastlookup(tetarray, i);
      for (j = 0; j < 4; j++) {
        decode(parytet->tet[j], tetloop);
        if (!infected(tetloop)) {
          // Found a new hull face (must be a subface).
          tspivot(tetloop, checksh);
          maketetrahedron(&hulltet);
          pa = org(tetloop);
          pb = dest(tetloop);
          pc = apex(tetloop);
          setvertices(hulltet, pb, pa, pc, dummypoint);
          bond(tetloop, hulltet);
          // Update the subface-to-tet map.
          sesymself(checksh);
          tsbond(hulltet, checksh);
          // Update the segment-to-tet map.
          for (k = 0; k < 3; k++) {
            if (issubseg(tetloop)) {
              tsspivot1(tetloop, checkseg);
              tssbond1(hulltet, checkseg);
              sstbond1(checkseg, hulltet);
            }
            enextself(tetloop);
            eprevself(hulltet);
          }
          // Update the point-to-tet map.
          setpoint2tet(pa, (tetrahedron) tetloop.tet);
          setpoint2tet(pb, (tetrahedron) tetloop.tet);
          setpoint2tet(pc, (tetrahedron) tetloop.tet);
          // Save the exterior tet at this hull face. It still holds pointer
          //   to the adjacent interior tet. Use it to connect new hull tets.
          newhullfacearray->newindex((void **) &parytet1);
          parytet1->tet = parytet->tet;
          parytet1->ver = j;
        } // if (!infected(tetloop))
      } // j
    } // i

    // Connect new hull tets.
    for (i = 0; i < newhullfacearray->objects; i++) {
      parytet = (triface *) fastlookup(newhullfacearray, i);
      fsym(*parytet, neightet);
      // Get the new hull tet.
      fsym(neightet, hulltet);
      for (j = 0; j < 3; j++) {
        esym(hulltet, casface);
        if (casface.tet[casface.ver & 3] == NULL) {
          // Since the boundary of the domain may not be a manifold, we
          //   find the adjacent hull face by traversing the tets in the
          //   exterior (which are all infected tets).
          neightet = *parytet;
          while (1) {
            fnextself(neightet);
            if (!infected(neightet)) break;
          }
          if (!ishulltet(neightet)) {
            // An interior tet. Get the new hull tet.
            fsymself(neightet);
            esymself(neightet);
          }
          // Bond them together.
          bond(casface, neightet);
        }
        enextself(hulltet);
        enextself(*parytet);
      } // j
    } // i

    if (subfacstack->objects > 0l) {
      // Remove all subfaces which do not attach to any tetrahedron.
      //   Segments which are not attached to any subfaces and tets
      //   are deleted too.
      face casingout, casingin;
      long delsegcount = 0l;

      for (i = 0; i < subfacstack->objects; i++) {
        parysh = (face *) fastlookup(subfacstack, i);
        if (i == 0) {
          if (b->verbose) {
            printf("Warning:  Removing an open face (%d, %d, %d)\n",
                   pointmark(sorg(*parysh)), pointmark(sdest(*parysh)),
                   pointmark(sapex(*parysh)));
          }
        }
        // Dissolve this subface from face links.
        for (j = 0; j < 3; j++) {
          spivot(*parysh, casingout);
          sspivot(*parysh, checkseg);
          if (casingout.sh != NULL) {
            casingin = casingout;
            while (1) {
              spivot(casingin, checksh);
              if (checksh.sh == parysh->sh) break;
              casingin = checksh;
            }
            if (casingin.sh != casingout.sh) {
              // Update the link: ... -> casingin -> casingout ->...
              sbond1(casingin, casingout);
            } else {
              // Only one subface at this edge is left.
              sdissolve(casingout);
            }
            if (checkseg.sh != NULL) {
              // Make sure the segment does not connect to a dead one.
              ssbond(casingout, checkseg);
            }
          } else {
            if (checkseg.sh != NULL) {
              // The segment is also dead.
              if (delsegcount == 0) {
                if (b->verbose) {
                  printf("Warning:  Removing a dangling segment (%d, %d)\n",
                       pointmark(sorg(checkseg)), pointmark(sdest(checkseg)));
                }
              }
              shellfacedealloc(subsegs, checkseg.sh);
              delsegcount++;
            }
          }
          senextself(*parysh);
        } // j
        // Delete this subface.
        shellfacedealloc(subfaces, parysh->sh);
      } // i
      if (b->verbose) {
        printf("  Deleted %ld subfaces.\n", subfacstack->objects);
        if (delsegcount > 0) {
          printf("  Deleted %ld segments.\n", delsegcount);
        }
      }
      subfacstack->restart();
    } // if (subfacstack->objects > 0l)

    if (cavetetvertlist->objects > 0l) {
      // Some vertices may lie in exterior. Marke them as UNUSEDVERTEX.
      long delvertcount = unuverts;
      long delsteinercount = 0l;

      for (i = 0; i < cavetetvertlist->objects; i++) {
        parypt = (point *) fastlookup(cavetetvertlist, i);
        decode(point2tet(*parypt), neightet);
        if (infected(neightet)) {
          // Found an exterior vertex.
          //if (pointmark(*parypt) >
          //      (in->numberofpoints - (in->firstnumber ? 0 : 1))) {
          if (issteinerpoint(*parypt)) {
            // A Steiner point.
            if (pointtype(*parypt) == FREESEGVERTEX) {
              st_segref_count--;
            } else if (pointtype(*parypt) == FREEFACETVERTEX) {
              st_facref_count--;
            } else {
              assert(pointtype(*parypt) == FREEVOLVERTEX);
              st_volref_count--;
            }
            delsteinercount++;
            if (steinerleft > 0) steinerleft++;
          }
          setpointtype(*parypt, UNUSEDVERTEX);
          unuverts++;
        }
      }

      if (b->verbose) {
        if (unuverts > delvertcount) {
          if (delsteinercount > 0l) {
            if (unuverts > (delvertcount + delsteinercount)) {
              printf("  Removed %ld exterior input vertices.\n",
                     unuverts - delvertcount - delsteinercount);
            }
            printf("  Removed %ld exterior Steiner vertices.\n",
                   delsteinercount);
          } else {
            printf("  Removed %ld exterior input vertices.\n",
                   unuverts - delvertcount);
          }
        }
      }
      cavetetvertlist->restart();
      // Comment: 'subvertstack' will be cleaned in routine
      //   suppresssteinerpoints().
    } // if (cavetetvertlist->objects > 0l)

    // Update the hull size.
    hullsize += (newhullfacearray->objects - hullarray->objects);

    // Delete all exterior tets and old hull tets.
    for (i = 0; i < tetarray->objects; i++) {
      parytet = (triface *) fastlookup(tetarray, i);
      tetrahedrondealloc(parytet->tet);
    }
    tetarray->restart();

    for (i = 0; i < hullarray->objects; i++) {
      parytet = (triface *) fastlookup(hullarray, i);
      tetrahedrondealloc(parytet->tet);
    }
    hullarray->restart();

    delete newhullfacearray;
  } // if (!b->convex && (tetarray->objects > 0l))

  if (b->convex && (tetarray->objects > 0l)) { // With -c option
    // In this case, all exterior tets get a region marker '-1'.
    assert(b->regionattrib > 0); // -A option must be enabled.
    int attrnum = numelemattrib - 1;

    for (i = 0; i < tetarray->objects; i++) {
      parytet = (triface *) fastlookup(tetarray, i);
      setelemattribute(parytet->tet, attrnum, -1);
    }
    tetarray->restart();

    for (i = 0; i < hullarray->objects; i++) {
      parytet = (triface *) fastlookup(hullarray, i);
      uninfect(*parytet);
    }
    hullarray->restart();

    if (subfacstack->objects > 0l) {
      for (i = 0; i < subfacstack->objects; i++) {
        parysh = (face *) fastlookup(subfacstack, i);
        suninfect(*parysh);
      }
      subfacstack->restart();
    }

    if (cavetetvertlist->objects > 0l) {
      cavetetvertlist->restart();
    }
  } // if (b->convex && (tetarray->objects > 0l))

  if (b->regionattrib) { // With -A option.
    if (!b->quiet) {
      printf("Spreading region attributes.\n");
    }
    REAL volume;
    int attr, maxattr = 0; // Choose a small number here.
    int attrnum = numelemattrib - 1;
    // Comment: The element region marker is at the end of the list of
    //   the element attributes.
    int regioncount = 0;

    // Set attributes for all tetrahedra.
    attr = maxattr + 1;
    tetrahedrons->traversalinit();
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
          for (k = 0; k < 4; k++) {
            decode(tetloop.tet[k], neightet);
            // Is the adjacent tet already checked?
            if (!infected(neightet)) {
              // Is this side protected by a subface?
              if (!issubface(neightet)) {
                infect(neightet);
                tetarray->newindex((void **) &parytet);
                *parytet = neightet;
              }
            }
          } // k
        } // j
        attr++; // Increase the attribute.
        regioncount++;
      }
      tetloop.tet = tetrahedrontraverse();
    }
    // Until here, every tet has a region attribute.

    // Uninfect processed tets.
    tetrahedrons->traversalinit();
    tetloop.tet = tetrahedrontraverse();
    while (tetloop.tet != (tetrahedron *) NULL) {
      uninfect(tetloop);
      tetloop.tet = tetrahedrontraverse();
    }

    if (b->verbose) {
      //assert(regioncount > 0);
      if (regioncount > 1) {
        printf("  Found %d subdomains.\n", regioncount);
      } else {
        printf("  Found %d domain.\n", regioncount);
      }
    }
  } // if (b->regionattrib)

  if (regiontets != NULL) {
    delete [] regiontets;
  }
  delete tetarray;
  delete hullarray;

  if (!b->convex) { // No -c option
    // The mesh is non-convex now.
    nonconvex = 1;

    // Push all hull tets into 'flipstack'.
    tetrahedrons->traversalinit();
    tetloop.ver = 11; // The face opposite to dummypoint.
    tetloop.tet = alltetrahedrontraverse();
    while (tetloop.tet != (tetrahedron *) NULL) {
      if ((point) tetloop.tet[7] == dummypoint) {
        fsym(tetloop, neightet);
        flippush(flipstack, &neightet);
      }
      tetloop.tet = alltetrahedrontraverse();
    }

    flipconstraints fc;
    fc.enqflag = 2;
    long sliver_peel_count = lawsonflip3d(&fc);

    if (sliver_peel_count > 0l) {
      if (b->verbose) {
        printf("  Removed %ld hull slivers.\n", sliver_peel_count);
      }
    }
    unflipqueue->restart();
  } // if (!b->convex)
}

////                                                                       ////
////                                                                       ////
//// reconstruct_cxx //////////////////////////////////////////////////////////

//// optimize_cxx /////////////////////////////////////////////////////////////
////                                                                       ////
////                                                                       ////

long meshGRegionBoundaryRecovery::lawsonflip3d(flipconstraints *fc)
{
  triface fliptets[5], neightet, hulltet;
  face checksh, casingout;
  badface *popface, *bface;
  point pd, pe, *pts;
  REAL sign, ori;
  long flipcount, totalcount = 0l;
  long sliver_peels = 0l;
  int t1ver;
  int i;


  while (1) {

    if (b->verbose > 2) {
      printf("      Lawson flip %ld faces.\n", flippool->items);
    }
    flipcount = 0l;

    while (flipstack != (badface *) NULL) {
      // Pop a face from the stack.
      popface = flipstack;
      fliptets[0] = popface->tt;
      flipstack = flipstack->nextitem; // The next top item in stack.
      flippool->dealloc((void *) popface);

      // Skip it if it is a dead tet (destroyed by previous flips).
      if (isdeadtet(fliptets[0])) continue;
      // Skip it if it is not the same tet as we saved.
      if (!facemarked(fliptets[0])) continue;

      unmarkface(fliptets[0]);

      if (ishulltet(fliptets[0])) continue;

      fsym(fliptets[0], fliptets[1]);
      if (ishulltet(fliptets[1])) {
        if (nonconvex) {
          // Check if 'fliptets[0]' it is a hull sliver.
          tspivot(fliptets[0], checksh);
          for (i = 0; i < 3; i++) {
            if (!isshsubseg(checksh)) {
              spivot(checksh, casingout);
              //assert(casingout.sh != NULL);
              if (sorg(checksh) != sdest(casingout)) sesymself(casingout);
              stpivot(casingout, neightet);
              if (neightet.tet == fliptets[0].tet) {
                // Found a hull sliver 'neightet'. Let it be [e,d,a,b], where
                //   [e,d,a] and [d,e,b] are hull faces.
                edestoppo(neightet, hulltet); // [a,b,e,d]
                fsymself(hulltet); // [b,a,e,#]
                if (oppo(hulltet) == dummypoint) {
                  pe = org(neightet);
                  if ((pointtype(pe) == FREEFACETVERTEX) ||
                      (pointtype(pe) == FREESEGVERTEX)) {
                    removevertexbyflips(pe);
                  }
                } else {
                  eorgoppo(neightet, hulltet); // [b,a,d,e]
                  fsymself(hulltet); // [a,b,d,#]
                  if (oppo(hulltet) == dummypoint) {
                    pd = dest(neightet);
                    if ((pointtype(pd) == FREEFACETVERTEX) ||
                        (pointtype(pd) == FREESEGVERTEX)) {
                      removevertexbyflips(pd);
                    }
                  } else {
                    // Perform a 3-to-2 flip to remove the sliver.
                    fliptets[0] = neightet;          // [e,d,a,b]
                    fnext(fliptets[0], fliptets[1]); // [e,d,b,c]
                    fnext(fliptets[1], fliptets[2]); // [e,d,c,a]
                    flip32(fliptets, 1, fc);
                    // Update counters.
                    flip32count--;
                    flip22count--;
                    sliver_peels++;
                    if (fc->remove_ndelaunay_edge) {
                      // Update the volume (must be decreased).
                      //assert(fc->tetprism_vol_sum <= 0);
                      tetprism_vol_sum += fc->tetprism_vol_sum;
                      fc->tetprism_vol_sum = 0.0; // Clear it.
                    }
                  }
                }
                break;
              } // if (neightet.tet == fliptets[0].tet)
            } // if (!isshsubseg(checksh))
            senextself(checksh);
          } // i
        } // if (nonconvex)
        continue;
      }

      if (checksubfaceflag) {
        // Do not flip if it is a subface.
        if (issubface(fliptets[0])) continue;
      }

      // Test whether the face is locally Delaunay or not.
      pts = (point *) fliptets[1].tet;
      sign = insphere_s(pts[4], pts[5], pts[6], pts[7], oppo(fliptets[0]));

      if (sign < 0) {
        // A non-Delaunay face. Try to flip it.
        pd = oppo(fliptets[0]);
        pe = oppo(fliptets[1]);

        // Check the convexity of its three edges. Stop checking either a
        //   locally non-convex edge (ori < 0) or a flat edge (ori = 0) is
        //   encountered, and 'fliptet' represents that edge.
        for (i = 0; i < 3; i++) {
          ori = orient3d(org(fliptets[0]), dest(fliptets[0]), pd, pe);
          if (ori <= 0) break;
          enextself(fliptets[0]);
        }

        if (ori > 0) {
          // A 2-to-3 flip is found.
          //   [0] [a,b,c,d],
          //   [1] [b,a,c,e]. no dummypoint.
          flip23(fliptets, 0, fc);
          flipcount++;
          if (fc->remove_ndelaunay_edge) {
            // Update the volume (must be decreased).
            //assert(fc->tetprism_vol_sum <= 0);
            tetprism_vol_sum += fc->tetprism_vol_sum;
            fc->tetprism_vol_sum = 0.0; // Clear it.
          }
          continue;
        } else { // ori <= 0
          // The edge ('fliptets[0]' = [a',b',c',d]) is non-convex or flat,
          //   where the edge [a',b'] is one of [a,b], [b,c], and [c,a].
          if (checksubsegflag) {
            // Do not flip if it is a segment.
            if (issubseg(fliptets[0])) continue;
          }
          // Check if there are three or four tets sharing at this edge.
          esymself(fliptets[0]); // [b,a,d,c]
          for (i = 0; i < 3; i++) {
            fnext(fliptets[i], fliptets[i+1]);
          }
          if (fliptets[3].tet == fliptets[0].tet) {
            // A 3-to-2 flip is found. (No hull tet.)
            flip32(fliptets, 0, fc);
            flipcount++;
            if (fc->remove_ndelaunay_edge) {
              // Update the volume (must be decreased).
              //assert(fc->tetprism_vol_sum <= 0);
              tetprism_vol_sum += fc->tetprism_vol_sum;
              fc->tetprism_vol_sum = 0.0; // Clear it.
            }
            continue;
          } else {
            // There are more than 3 tets at this edge.
            fnext(fliptets[3], fliptets[4]);
            if (fliptets[4].tet == fliptets[0].tet) {
              // There are exactly 4 tets at this edge.
              if (nonconvex) {
                if (apex(fliptets[3]) == dummypoint) {
                  // This edge is locally non-convex on the hull.
                  // It can be removed by a 4-to-4 flip.
                  ori = 0;
                }
              } // if (nonconvex)
              if (ori == 0) {
                // A 4-to-4 flip is found. (Two hull tets may be involved.)
                // Current tets in 'fliptets':
                //   [0] [b,a,d,c] (d may be newpt)
                //   [1] [b,a,c,e]
                //   [2] [b,a,e,f] (f may be dummypoint)
                //   [3] [b,a,f,d]
                esymself(fliptets[0]); // [a,b,c,d]
                // A 2-to-3 flip replaces face [a,b,c] by edge [e,d].
                //   This creates a degenerate tet [e,d,a,b] (tmpfliptets[0]).
                //   It will be removed by the followed 3-to-2 flip.
                flip23(fliptets, 0, fc); // No hull tet.
                fnext(fliptets[3], fliptets[1]);
                fnext(fliptets[1], fliptets[2]);
                // Current tets in 'fliptets':
                //   [0] [...]
                //   [1] [b,a,d,e] (degenerated, d may be new point).
                //   [2] [b,a,e,f] (f may be dummypoint)
                //   [3] [b,a,f,d]
                // A 3-to-2 flip replaces edge [b,a] by face [d,e,f].
                //   Hull tets may be involved (f may be dummypoint).
                flip32(&(fliptets[1]), (apex(fliptets[3]) == dummypoint), fc);
                flipcount++;
                flip23count--;
                flip32count--;
                flip44count++;
                if (fc->remove_ndelaunay_edge) {
                  // Update the volume (must be decreased).
                  //assert(fc->tetprism_vol_sum <= 0);
                  tetprism_vol_sum += fc->tetprism_vol_sum;
                  fc->tetprism_vol_sum = 0.0; // Clear it.
                }
                continue;
              } // if (ori == 0)
            }
          }
        } // if (ori <= 0)

        // This non-Delaunay face is unflippable. Save it.
        unflipqueue->newindex((void **) &bface);
        bface->tt = fliptets[0];
        bface->forg  = org(fliptets[0]);
        bface->fdest = dest(fliptets[0]);
        bface->fapex = apex(fliptets[0]);
      } // if (sign < 0)
    } // while (flipstack)

    if (b->verbose > 2) {
      if (flipcount > 0) {
        printf("      Performed %ld flips.\n", flipcount);
      }
    }
    // Accumulate the counter of flips.
    totalcount += flipcount;

    assert(flippool->items == 0l);
    // Return if no unflippable faces left.
    if (unflipqueue->objects == 0l) break;
    // Return if no flip has been performed.
    if (flipcount == 0l) break;

    // Try to flip the unflippable faces.
    for (i = 0; i < unflipqueue->objects; i++) {
      bface = (badface *) fastlookup(unflipqueue, i);
      if (!isdeadtet(bface->tt) &&
          (org(bface->tt) == bface->forg) &&
          (dest(bface->tt) == bface->fdest) &&
          (apex(bface->tt) == bface->fapex)) {
        flippush(flipstack, &(bface->tt));
      }
    }
    unflipqueue->restart();

  } // while (1)

  if (b->verbose > 2) {
    if (totalcount > 0) {
      printf("      Performed %ld flips.\n", totalcount);
    }
    if (sliver_peels > 0) {
      printf("      Removed %ld hull slivers.\n", sliver_peels);
    }
    if (unflipqueue->objects > 0l) {
      printf("      %ld unflippable edges remained.\n", unflipqueue->objects);
    }
  }

  return totalcount + sliver_peels;
}

void meshGRegionBoundaryRecovery::recoverdelaunay()
{
  arraypool *flipqueue, *nextflipqueue, *swapqueue;
  triface tetloop, neightet, *parytet;
  badface *bface, *parybface;
  point *ppt;
  flipconstraints fc;
  int i, j;

  if (!b->quiet) {
    printf("Recovering Delaunayness...\n");
  }

  tetprism_vol_sum = 0.0; // Initialize it.

  // Put all interior faces of the mesh into 'flipstack'.
  tetrahedrons->traversalinit();
  tetloop.tet = tetrahedrontraverse();
  while (tetloop.tet != NULL) {
    for (tetloop.ver = 0; tetloop.ver < 4; tetloop.ver++) {
      decode(tetloop.tet[tetloop.ver], neightet);
      if (!facemarked(neightet)) {
        flippush(flipstack, &tetloop);
      }
    }
    ppt = (point *) &(tetloop.tet[4]);
    tetprism_vol_sum += tetprismvol(ppt[0], ppt[1], ppt[2], ppt[3]);
    tetloop.tet = tetrahedrontraverse();
  }

  // Calulate a relatively lower bound for small improvement.
  //   Used to avoid rounding error in volume calculation.
  fc.bak_tetprism_vol = tetprism_vol_sum * b->epsilon * 1e-3;

  if (b->verbose) {
    printf("  Initial obj = %.17g\n", tetprism_vol_sum);
  }

  if (b->verbose > 1) {
    printf("    Recover Delaunay [Lawson] : %ld\n", flippool->items);
  }

  // First only use the basic Lawson's flip.
  fc.remove_ndelaunay_edge = 1;
  fc.enqflag = 2;

  lawsonflip3d(&fc);

  if (b->verbose > 1) {
    printf("    obj (after Lawson) = %.17g\n", tetprism_vol_sum);
  }

  if (unflipqueue->objects == 0l) {
    return; // The mesh is Delaunay.
  }

  fc.unflip = 1; // Unflip if the edge is not flipped.
  fc.collectnewtets = 1; // new tets are returned in 'cavetetlist'.
  fc.enqflag = 0;

  autofliplinklevel = 1; // Init level.
  b->fliplinklevel = -1; // No fixed level.

  // For efficiency reason, we limit the maximium size of the edge star.
  int bakmaxflipstarsize = b->flipstarsize;
  b->flipstarsize = 10; // default

  flipqueue = new arraypool(sizeof(badface), 10);
  nextflipqueue = new arraypool(sizeof(badface), 10);

  // Swap the two flip queues.
  swapqueue = flipqueue;
  flipqueue = unflipqueue;
  unflipqueue = swapqueue;

  while (flipqueue->objects > 0l) {

    if (b->verbose > 1) {
      printf("    Recover Delaunay [level = %2d] #:  %ld.\n",
             autofliplinklevel, flipqueue->objects);
    }

    for (i = 0; i < flipqueue->objects; i++) {
      bface  = (badface *) fastlookup(flipqueue, i);
      if (getedge(bface->forg, bface->fdest, &bface->tt)) {
        if (removeedgebyflips(&(bface->tt), &fc) == 2) {
          tetprism_vol_sum += fc.tetprism_vol_sum;
          fc.tetprism_vol_sum = 0.0; // Clear it.
          // Queue new faces for flips.
          for (j = 0; j < cavetetlist->objects; j++) {
            parytet = (triface *) fastlookup(cavetetlist, j);
            // A queued new tet may be dead.
            if (!isdeadtet(*parytet)) {
              for (parytet->ver = 0; parytet->ver < 4; parytet->ver++) {
                // Avoid queue a face twice.
                decode(parytet->tet[parytet->ver], neightet);
                if (!facemarked(neightet)) {
                  flippush(flipstack, parytet);
                }
              } // parytet->ver
            }
          } // j
          cavetetlist->restart();
          // Remove locally non-Delaunay faces. New non-Delaunay edges
          //   may be found. They are saved in 'unflipqueue'.
          fc.enqflag = 2;
          lawsonflip3d(&fc);
          fc.enqflag = 0;
          // There may be unflipable faces. Add them in flipqueue.
          for (j = 0; j < unflipqueue->objects; j++) {
            bface  = (badface *) fastlookup(unflipqueue, j);
            flipqueue->newindex((void **) &parybface);
            *parybface = *bface;
          }
          unflipqueue->restart();
        } else {
          // Unable to remove this edge. Save it.
          nextflipqueue->newindex((void **) &parybface);
          *parybface = *bface;
          // Normally, it should be zero.
          //assert(fc.tetprism_vol_sum == 0.0);
          // However, due to rounding errors, a tiny value may appear.
          fc.tetprism_vol_sum = 0.0;
        }
      }
    } // i

    if (b->verbose > 1) {
      printf("    obj (after level %d) = %.17g.\n", autofliplinklevel,
             tetprism_vol_sum);
    }
    flipqueue->restart();

    // Swap the two flip queues.
    swapqueue = flipqueue;
    flipqueue = nextflipqueue;
    nextflipqueue = swapqueue;

    if (flipqueue->objects > 0l) {
      // default 'b->delmaxfliplevel' is 1.
      if (autofliplinklevel >= b->delmaxfliplevel) {
        // For efficiency reason, we do not search too far.
        break;
      }
      autofliplinklevel+=b->fliplinklevelinc;
    }
  } // while (flipqueue->objects > 0l)

  if (flipqueue->objects > 0l) {
    if (b->verbose > 1) {
      printf("    %ld non-Delaunay edges remained.\n", flipqueue->objects);
    }
  }

  if (b->verbose) {
    printf("  Final obj  = %.17g\n", tetprism_vol_sum);
  }

  b->flipstarsize = bakmaxflipstarsize;
  delete flipqueue;
  delete nextflipqueue;
}

int meshGRegionBoundaryRecovery::gettetrahedron(point pa, point pb, point pc,
  point pd, triface *searchtet)
{
  triface spintet;
  int t1ver;

  if (getedge(pa, pb, searchtet)) {
    spintet = *searchtet;
    while (1) {
      if (apex(spintet) == pc) {
        *searchtet = spintet;
        break;
      }
      fnextself(spintet);
      if (spintet.tet == searchtet->tet) break;
    }
    if (apex(*searchtet) == pc) {
      if (oppo(*searchtet) == pd) {
        return 1;
      } else {
        fsymself(*searchtet);
        if (oppo(*searchtet) == pd) {
          return 1;
        }
      }
    }
  }

  return 0;
}

long meshGRegionBoundaryRecovery::improvequalitybyflips()
{
  arraypool *flipqueue, *nextflipqueue, *swapqueue;
  badface *bface, *parybface;
  triface *parytet;
  point *ppt;
  flipconstraints fc;
  REAL *cosdd, ncosdd[6], maxdd;
  long totalremcount, remcount;
  int remflag;
  int n, i, j, k;

  //assert(unflipqueue->objects > 0l);
  flipqueue = new arraypool(sizeof(badface), 10);
  nextflipqueue = new arraypool(sizeof(badface), 10);

  // Backup flip edge options.
  int bakautofliplinklevel = autofliplinklevel;
  int bakfliplinklevel = b->fliplinklevel;
  int bakmaxflipstarsize = b->flipstarsize;

  // Set flip edge options.
  autofliplinklevel = 1;
  b->fliplinklevel = -1;
  b->flipstarsize = 10; // b->optmaxflipstarsize;

  fc.remove_large_angle = 1;
  fc.unflip = 1;
  fc.collectnewtets = 1;
  fc.checkflipeligibility = 1;

  totalremcount = 0l;

  // Swap the two flip queues.
  swapqueue = flipqueue;
  flipqueue = unflipqueue;
  unflipqueue = swapqueue;

  while (flipqueue->objects > 0l) {

    remcount = 0l;

    while (flipqueue->objects > 0l) {
      if (b->verbose > 1) {
        printf("    Improving mesh qualiy by flips [%d]#:  %ld.\n",
               autofliplinklevel, flipqueue->objects);
      }

      for (k = 0; k < flipqueue->objects; k++) {
        bface  = (badface *) fastlookup(flipqueue, k);
        if (gettetrahedron(bface->forg, bface->fdest, bface->fapex,
                           bface->foppo, &bface->tt)) {
          //assert(!ishulltet(bface->tt));
          // There are bad dihedral angles in this tet.
          if (bface->tt.ver != 11) {
            // The dihedral angles are permuted.
            // Here we simply re-compute them. Slow!!.
            ppt = (point *) & (bface->tt.tet[4]);
            tetalldihedral(ppt[0], ppt[1], ppt[2], ppt[3], bface->cent,
                           &bface->key, NULL);
            bface->forg = ppt[0];
            bface->fdest = ppt[1];
            bface->fapex = ppt[2];
            bface->foppo = ppt[3];
            bface->tt.ver = 11;
          }
          if (bface->key == 0) {
            // Re-comput the quality values. Due to smoothing operations.
            ppt = (point *) & (bface->tt.tet[4]);
            tetalldihedral(ppt[0], ppt[1], ppt[2], ppt[3], bface->cent,
                           &bface->key, NULL);
          }
          cosdd = bface->cent;
          remflag = 0;
          for (i = 0; (i < 6) && !remflag; i++) {
            if (cosdd[i] < cosmaxdihed) {
              // Found a large dihedral angle.
              bface->tt.ver = edge2ver[i]; // Go to the edge.
              fc.cosdihed_in = cosdd[i];
              fc.cosdihed_out = 0.0; // 90 degree.
              n = removeedgebyflips(&(bface->tt), &fc);
              if (n == 2) {
                // Edge is flipped.
                remflag = 1;
                if (fc.cosdihed_out < cosmaxdihed) {
                  // Queue new bad tets for further improvements.
                  for (j = 0; j < cavetetlist->objects; j++) {
                    parytet = (triface *) fastlookup(cavetetlist, j);
                    if (!isdeadtet(*parytet)) {
                      ppt = (point *) & (parytet->tet[4]);
                      // Do not test a hull tet.
                      if (ppt[3] != dummypoint) {
                        tetalldihedral(ppt[0], ppt[1], ppt[2], ppt[3], ncosdd,
                                       &maxdd, NULL);
                        if (maxdd < cosmaxdihed) {
                          // There are bad dihedral angles in this tet.
                          nextflipqueue->newindex((void **) &parybface);
                          parybface->tt.tet = parytet->tet;
                          parybface->tt.ver = 11;
                          parybface->forg = ppt[0];
                          parybface->fdest = ppt[1];
                          parybface->fapex = ppt[2];
                          parybface->foppo = ppt[3];
                          parybface->key = maxdd;
                          for (n = 0; n < 6; n++) {
                            parybface->cent[n] = ncosdd[n];
                          }
                        }
                      } // if (ppt[3] != dummypoint)
                    }
                  } // j
                } // if (fc.cosdihed_out < cosmaxdihed)
                cavetetlist->restart();
                remcount++;
              }
            }
          } // i
          if (!remflag) {
            // An unremoved bad tet. Queue it again.
            unflipqueue->newindex((void **) &parybface);
            *parybface = *bface;
          }
        } // if (gettetrahedron(...))
      } // k

      flipqueue->restart();

      // Swap the two flip queues.
      swapqueue = flipqueue;
      flipqueue = nextflipqueue;
      nextflipqueue = swapqueue;
    } // while (flipqueues->objects > 0)

    if (b->verbose > 1) {
      printf("    Removed %ld bad tets.\n", remcount);
    }
    totalremcount += remcount;

    if (unflipqueue->objects > 0l) {
      //if (autofliplinklevel >= b->optmaxfliplevel) {
      if (autofliplinklevel >= b->optlevel) {
        break;
      }
      autofliplinklevel+=b->fliplinklevelinc;
      //b->flipstarsize = 10 + (1 << (b->optlevel - 1));
    }

    // Swap the two flip queues.
    swapqueue = flipqueue;
    flipqueue = unflipqueue;
    unflipqueue = swapqueue;
  } // while (flipqueues->objects > 0)

  // Restore original flip edge options.
  autofliplinklevel = bakautofliplinklevel;
  b->fliplinklevel = bakfliplinklevel;
  b->flipstarsize = bakmaxflipstarsize;

  delete flipqueue;
  delete nextflipqueue;

  return totalremcount;
}

int meshGRegionBoundaryRecovery::smoothpoint(point smtpt,
  arraypool *linkfacelist, int ccw, optparameters *opm)
{
  triface *parytet, *parytet1, swaptet;
  point pa, pb, pc;
  REAL fcent[3], startpt[3], nextpt[3], bestpt[3];
  REAL oldval, minval = 0.0, val;
  REAL maxcosd; // oldang, newang;
  REAL ori, diff;
  int numdirs, iter;
  int i, j, k;

  // Decide the number of moving directions.
  numdirs = (int) linkfacelist->objects;
  if (numdirs > opm->numofsearchdirs) {
    numdirs = opm->numofsearchdirs; // Maximum search directions.
  }

  // Set the initial value.
  if (!opm->max_min_volume) {
    assert(opm->initval >= 0.0);
  }
  opm->imprval = opm->initval;
  iter = 0;

  for (i = 0; i < 3; i++) {
    bestpt[i] = startpt[i] = smtpt[i];
  }

  // Iterate until the obj function is not improved.
  while (1) {

    // Find the best next location.
    oldval = opm->imprval;

    for (i = 0; i < numdirs; i++) {
      // Randomly pick a link face (0 <= k <= objects - i - 1).
      k = (int) randomnation(linkfacelist->objects - i);
      parytet = (triface *) fastlookup(linkfacelist, k);
      // Calculate a new position from 'p' to the center of this face.
      pa = org(*parytet);
      pb = dest(*parytet);
      pc = apex(*parytet);
      for (j = 0; j < 3; j++) {
        fcent[j] = (pa[j] + pb[j] + pc[j]) / 3.0;
      }
      for (j = 0; j < 3; j++) {
        nextpt[j] = startpt[j] + opm->searchstep * (fcent[j] - startpt[j]);
      }
      // Calculate the largest minimum function value for the new location.
      for (j = 0; j < linkfacelist->objects; j++) {
        parytet = (triface *) fastlookup(linkfacelist, j);
        if (ccw) {
          pa = org(*parytet);
          pb = dest(*parytet);
        } else {
          pb = org(*parytet);
          pa = dest(*parytet);
        }
        pc = apex(*parytet);
        ori = orient3d(pa, pb, pc, nextpt);
        if (ori < 0.0) {
          // Calcuate the objective function value.
          if (opm->max_min_volume) {
            //val = -ori;
            val = - orient3dfast(pa, pb, pc, nextpt);
          } else if (opm->min_max_aspectratio) {
            val = tetaspectratio(pa, pb, pc, nextpt);
          } else if (opm->min_max_dihedangle) {
            tetalldihedral(pa, pb, pc, nextpt, NULL, &maxcosd, NULL);
            if (maxcosd < -1) maxcosd = -1.0; // Rounding.
            val = maxcosd + 1.0; // Make it be positive.
          } else {
            // Unknown objective function.
            val = 0.0;
          }
        } else { // ori >= 0.0;
          // An invalid new tet.
          // This may happen if the mesh contains inverted elements.
          if (opm->max_min_volume) {
            //val = -ori;
            val = - orient3dfast(pa, pb, pc, nextpt);
          } else {
            // Discard this point.
            break; // j
          }
        } // if (ori >= 0.0)
        // Stop looping when the object value is not improved.
        if (val <= opm->imprval) {
          break; // j
        } else {
          // Remember the smallest improved value.
          if (j == 0) {
            minval = val;
          } else {
            minval = (val < minval) ? val : minval;
          }
        }
      } // j
      if (j == linkfacelist->objects) {
        // The function value has been improved.
        opm->imprval = minval;
        // Save the new location of the point.
        for (j = 0; j < 3; j++) bestpt[j] = nextpt[j];
      }
      // Swap k-th and (object-i-1)-th entries.
      j = linkfacelist->objects - i - 1;
      parytet  = (triface *) fastlookup(linkfacelist, k);
      parytet1 = (triface *) fastlookup(linkfacelist, j);
      swaptet = *parytet1;
      *parytet1 = *parytet;
      *parytet = swaptet;
    } // i

    diff = opm->imprval - oldval;
    if (diff > 0.0) {
      // Is the function value improved effectively?
      if (opm->max_min_volume) {
        //if ((diff / oldval) < b->epsilon) diff = 0.0;
      } else if (opm->min_max_aspectratio) {
        if ((diff / oldval) < 1e-3) diff = 0.0;
      } else if (opm->min_max_dihedangle) {
        //oldang = acos(oldval - 1.0);
        //newang = acos(opm->imprval - 1.0);
        //if ((oldang - newang) < 0.00174) diff = 0.0; // about 0.1 degree.
      } else {
        // Unknown objective function.
        assert(0); // Not possible.
      }
    }

    if (diff > 0.0) {
      // Yes, move p to the new location and continue.
      for (j = 0; j < 3; j++) startpt[j] = bestpt[j];
      iter++;
      if ((opm->maxiter > 0) && (iter >= opm->maxiter)) {
        // Maximum smoothing iterations reached.
        break;
      }
    } else {
      break;
    }

  } // while (1)

  if (iter > 0) {
    // The point has been smoothed.
    opm->smthiter = iter; // Remember the number of iterations.
    // The point has been smoothed. Update it to its new position.
    for (i = 0; i < 3; i++) smtpt[i] = startpt[i];
  }

  return iter;
}


long meshGRegionBoundaryRecovery::improvequalitybysmoothing(optparameters *opm)
{
  arraypool *flipqueue, *swapqueue;
  triface *parytet;
  badface *bface, *parybface;
  point *ppt;
  long totalsmtcount, smtcount;
  int smtflag;
  int iter, i, j, k;

  //assert(unflipqueue->objects > 0l);
  flipqueue = new arraypool(sizeof(badface), 10);

  // Swap the two flip queues.
  swapqueue = flipqueue;
  flipqueue = unflipqueue;
  unflipqueue = swapqueue;

  totalsmtcount = 0l;
  iter = 0;

  while (flipqueue->objects > 0l) {

    smtcount = 0l;

    if (b->verbose > 1) {
      printf("    Improving mesh quality by smoothing [%d]#:  %ld.\n",
             iter, flipqueue->objects);
    }

    for (k = 0; k < flipqueue->objects; k++) {
      bface  = (badface *) fastlookup(flipqueue, k);
      if (gettetrahedron(bface->forg, bface->fdest, bface->fapex,
                         bface->foppo, &bface->tt)) {
        // Operate on it if it is not in 'unflipqueue'.
        if (!marktested(bface->tt)) {
          // Here we simply re-compute the quality. Since other smoothing
          //   operation may have moved the vertices of this tet.
          ppt = (point *) & (bface->tt.tet[4]);
          tetalldihedral(ppt[0], ppt[1], ppt[2], ppt[3], bface->cent,
                         &bface->key, NULL);
          if (bface->key < cossmtdihed) { // if (maxdd < cosslidihed) {
            // It is a sliver. Try to smooth its vertices.
            smtflag = 0;
            opm->initval = bface->key + 1.0;
            for (i = 0; (i < 4) && !smtflag; i++) {
              if (pointtype(ppt[i]) == FREEVOLVERTEX) {
                getvertexstar(1, ppt[i], cavetetlist, NULL, NULL);
                opm->searchstep = 0.001; // Search step size
                smtflag = smoothpoint(ppt[i], cavetetlist, 1, opm);
                if (smtflag) {
                  while (opm->smthiter == opm->maxiter) {
                    opm->searchstep *= 10.0; // Increase the step size.
                    opm->initval = opm->imprval;
                    opm->smthiter = 0; // reset
                    smoothpoint(ppt[i], cavetetlist, 1, opm);
                  }
                  // This tet is modifed.
                  smtcount++;
                  if ((opm->imprval - 1.0) < cossmtdihed) {
                    // There are slivers in new tets. Queue them.
                    for (j = 0; j < cavetetlist->objects; j++) {
                      parytet = (triface *) fastlookup(cavetetlist, j);
                      assert(!isdeadtet(*parytet));
                      // Operate it if it is not in 'unflipqueue'.
                      if (!marktested(*parytet)) {
                        // Evaluate its quality.
                        // Re-use ppt, bface->key, bface->cent.
                        ppt = (point *) & (parytet->tet[4]);
                        tetalldihedral(ppt[0], ppt[1], ppt[2], ppt[3],
                                       bface->cent, &bface->key, NULL);
                        if (bface->key < cossmtdihed) {
                          // A new sliver. Queue it.
                          marktest(*parytet); // It is in unflipqueue.
                          unflipqueue->newindex((void **) &parybface);
                          parybface->tt = *parytet;
                          parybface->forg = ppt[0];
                          parybface->fdest = ppt[1];
                          parybface->fapex = ppt[2];
                          parybface->foppo = ppt[3];
                          parybface->tt.ver = 11;
                          parybface->key = 0.0;
                        }
                      }
                    } // j
                  } // if ((opm->imprval - 1.0) < cossmtdihed)
                } // if (smtflag)
                cavetetlist->restart();
              } // if (pointtype(ppt[i]) == FREEVOLVERTEX)
            } // i
            if (!smtflag) {
              // Didn't smooth. Queue it again.
              marktest(bface->tt); // It is in unflipqueue.
              unflipqueue->newindex((void **) &parybface);
              parybface->tt = bface->tt;
              parybface->forg = ppt[0];
              parybface->fdest = ppt[1];
              parybface->fapex = ppt[2];
              parybface->foppo = ppt[3];
              parybface->tt.ver = 11;
              parybface->key = 0.0;
            }
	      } // if (maxdd < cosslidihed)
        } // if (!marktested(...))
      } // if (gettetrahedron(...))
    } // k

    flipqueue->restart();

    // Unmark the tets in unflipqueue.
    for (i = 0; i < unflipqueue->objects; i++) {
      bface  = (badface *) fastlookup(unflipqueue, i);
      unmarktest(bface->tt);
    }

    if (b->verbose > 1) {
      printf("    Smooth %ld points.\n", smtcount);
    }
    totalsmtcount += smtcount;

    if (smtcount == 0l) {
      // No point has been smoothed.
      break;
    } else {
      iter++;
      if (iter == 2) { //if (iter >= b->optpasses) {
        break;
      }
    }

    // Swap the two flip queues.
    swapqueue = flipqueue;
    flipqueue = unflipqueue;
    unflipqueue = swapqueue;
  } // while

  delete flipqueue;

  return totalsmtcount;
}

int meshGRegionBoundaryRecovery::splitsliver(triface *slitet, REAL cosd,
  int chkencflag)
{
  triface *abtets;
  triface searchtet, spintet, *parytet;
  point pa, pb, steinerpt;
  optparameters opm;
  insertvertexflags ivf;
  REAL smtpt[3], midpt[3];
  int success;
  int t1ver;
  int n, i;

  // 'slitet' is [c,d,a,b], where [c,d] has a big dihedral angle.
  // Go to the opposite edge [a,b].
  edestoppo(*slitet, searchtet); // [a,b,c,d].

  // Do not split a segment.
  if (issubseg(searchtet)) {
    return 0;
  }

  // Count the number of tets shared at [a,b].
  // Do not split it if it is a hull edge.
  spintet = searchtet;
  n = 0;
  while (1) {
    if (ishulltet(spintet)) break;
    n++;
    fnextself(spintet);
    if (spintet.tet == searchtet.tet) break;
  }
  if (ishulltet(spintet)) {
    return 0; // It is a hull edge.
  }
  assert(n >= 3);

  // Get all tets at edge [a,b].
  abtets = new triface[n];
  spintet = searchtet;
  for (i = 0; i < n; i++) {
    abtets[i] = spintet;
    fnextself(spintet);
  }

  // Initialize the list of 2n boundary faces.
  for (i = 0; i < n; i++) {
    eprev(abtets[i], searchtet);
    esymself(searchtet); // [a,p_i,p_i+1].
    cavetetlist->newindex((void **) &parytet);
    *parytet = searchtet;
    enext(abtets[i], searchtet);
    esymself(searchtet); // [p_i,b,p_i+1].
    cavetetlist->newindex((void **) &parytet);
    *parytet = searchtet;
  }

  // Init the Steiner point at the midpoint of edge [a,b].
  pa = org(abtets[0]);
  pb = dest(abtets[0]);
  for (i = 0; i < 3; i++) {
    smtpt[i] = midpt[i] = 0.5 * (pa[i] + pb[i]);
  }

  // Point smooth options.
  opm.min_max_dihedangle = 1;
  opm.initval = cosd + 1.0; // Initial volume is zero.
  opm.numofsearchdirs = 20;
  opm.searchstep = 0.001;
  opm.maxiter = 100; // Limit the maximum iterations.

  success = smoothpoint(smtpt, cavetetlist, 1, &opm);

  if (success) {
    while (opm.smthiter == opm.maxiter) {
      // It was relocated and the prescribed maximum iteration reached.
      // Try to increase the search stepsize.
      opm.searchstep *= 10.0;
      //opm.maxiter = 100; // Limit the maximum iterations.
      opm.initval = opm.imprval;
      opm.smthiter = 0; // Init.
      smoothpoint(smtpt, cavetetlist, 1, &opm);
    }
  } // if (success)

  cavetetlist->restart();

  if (!success) {
    delete [] abtets;
    return 0;
  }


  // Insert the Steiner point.
  makepoint(&steinerpt, FREEVOLVERTEX);
  for (i = 0; i < 3; i++) steinerpt[i] = smtpt[i];

  // Insert the created Steiner point.
  for (i = 0; i < n; i++) {
    infect(abtets[i]);
    caveoldtetlist->newindex((void **) &parytet);
    *parytet = abtets[i];
  }

  searchtet = abtets[0]; // No need point location.
  if (b->metric) {
    locate(steinerpt, &searchtet); // For size interpolation.
  }

  delete [] abtets;

  ivf.iloc = (int) INSTAR;
  ivf.chkencflag = chkencflag;
  ivf.assignmeshsize = b->metric;


  if (insertpoint(steinerpt, &searchtet, NULL, NULL, &ivf)) {
    // The vertex has been inserted.
    st_volref_count++;
    if (steinerleft > 0) steinerleft--;
    return 1;
  } else {
    // The Steiner point is too close to an existing vertex. Reject it.
    pointdealloc(steinerpt);
    return 0;
  }
}

long meshGRegionBoundaryRecovery::removeslivers(int chkencflag)
{
  arraypool *flipqueue, *swapqueue;
  badface *bface, *parybface;
  triface slitet, *parytet;
  point *ppt;
  REAL cosdd[6], maxcosd;
  long totalsptcount, sptcount;
  int iter, i, j, k;

  //assert(unflipqueue->objects > 0l);
  flipqueue = new arraypool(sizeof(badface), 10);

  // Swap the two flip queues.
  swapqueue = flipqueue;
  flipqueue = unflipqueue;
  unflipqueue = swapqueue;

  totalsptcount = 0l;
  iter = 0;

  while ((flipqueue->objects > 0l) && (steinerleft != 0)) {

    sptcount = 0l;

    if (b->verbose > 1) {
      printf("    Splitting bad quality tets [%d]#:  %ld.\n",
             iter, flipqueue->objects);
    }

    for (k = 0; (k < flipqueue->objects) && (steinerleft != 0); k++) {
      bface  = (badface *) fastlookup(flipqueue, k);
      if (gettetrahedron(bface->forg, bface->fdest, bface->fapex,
                         bface->foppo, &bface->tt)) {
        if ((bface->key == 0) || (bface->tt.ver != 11)) {
          // Here we need to re-compute the quality. Since other smoothing
          //   operation may have moved the vertices of this tet.
          ppt = (point *) & (bface->tt.tet[4]);
          tetalldihedral(ppt[0], ppt[1], ppt[2], ppt[3], bface->cent,
                         &bface->key, NULL);
        }
        if (bface->key < cosslidihed) {
          // It is a sliver. Try to split it.
          slitet.tet = bface->tt.tet;
          //cosdd = bface->cent;
          for (j = 0; j < 6; j++) {
            if (bface->cent[j] < cosslidihed) {
              // Found a large dihedral angle.
              slitet.ver = edge2ver[j]; // Go to the edge.
              if (splitsliver(&slitet, bface->cent[j], chkencflag)) {
                sptcount++;
                break;
              }
            }
          } // j
          if (j < 6) {
            // A sliver is split. Queue new slivers.
            badtetrahedrons->traversalinit();
            parytet = (triface *) badtetrahedrons->traverse();
            while (parytet != NULL) {
              unmarktest2(*parytet);
              ppt = (point *) & (parytet->tet[4]);
              tetalldihedral(ppt[0], ppt[1], ppt[2], ppt[3], cosdd,
                             &maxcosd, NULL);
              if (maxcosd < cosslidihed) {
                // A new sliver. Queue it.
                unflipqueue->newindex((void **) &parybface);
                parybface->forg = ppt[0];
                parybface->fdest = ppt[1];
                parybface->fapex = ppt[2];
                parybface->foppo = ppt[3];
                parybface->tt.tet = parytet->tet;
                parybface->tt.ver = 11;
                parybface->key = maxcosd;
                for (i = 0; i < 6; i++) {
                  parybface->cent[i] = cosdd[i];
                }
              }
              parytet = (triface *) badtetrahedrons->traverse();
            }
            badtetrahedrons->restart();
          } else {
            // Didn't split. Queue it again.
            unflipqueue->newindex((void **) &parybface);
            *parybface = *bface;
          } // if (j == 6)
        } // if (bface->key < cosslidihed)
      } // if (gettetrahedron(...))
    } // k

    flipqueue->restart();

    if (b->verbose > 1) {
      printf("    Split %ld tets.\n", sptcount);
    }
    totalsptcount += sptcount;

    if (sptcount == 0l) {
      // No point has been smoothed.
      break;
    } else {
      iter++;
      if (iter == 2) { //if (iter >= b->optpasses) {
        break;
      }
    }

    // Swap the two flip queues.
    swapqueue = flipqueue;
    flipqueue = unflipqueue;
    unflipqueue = swapqueue;
  } // while

  delete flipqueue;

  return totalsptcount;
}

void meshGRegionBoundaryRecovery::optimizemesh()
{
  badface *parybface;
  triface checktet;
  point *ppt;
  int optpasses;
  optparameters opm;
  REAL ncosdd[6], maxdd;
  long totalremcount, remcount;
  long totalsmtcount, smtcount;
  long totalsptcount, sptcount;
  int chkencflag;
  int iter;
  int n;

  if (!b->quiet) {
    printf("Optimizing mesh...\n");
  }

  optpasses = ((1 << b->optlevel) - 1);

  if (b->verbose) {
    printf("  Optimization level  = %d.\n", b->optlevel);
    printf("  Optimization scheme = %d.\n", b->optscheme);
    printf("  Number of iteration = %d.\n", optpasses);
    printf("  Min_Max dihed angle = %g.\n", b->optmaxdihedral);
  }

  totalsmtcount = totalsptcount = totalremcount = 0l;

  cosmaxdihed = cos(b->optmaxdihedral / 180.0 * PI);
  cossmtdihed = cos(b->optminsmtdihed / 180.0 * PI);
  cosslidihed = cos(b->optminslidihed / 180.0 * PI);

  int attrnum = numelemattrib - 1;

  // Put all bad tetrahedra into array.
  tetrahedrons->traversalinit();
  checktet.tet = tetrahedrontraverse();
  while (checktet.tet != NULL) {
    if (b->convex) { // -c
      // Skip this tet if it lies in the exterior.
      if (elemattribute(checktet.tet, attrnum) == -1.0) {
        checktet.tet = tetrahedrontraverse();
        continue;
      }
    }
    ppt = (point *) & (checktet.tet[4]);
    tetalldihedral(ppt[0], ppt[1], ppt[2], ppt[3], ncosdd, &maxdd, NULL);
    if (maxdd < cosmaxdihed) {
      // There are bad dihedral angles in this tet.
      unflipqueue->newindex((void **) &parybface);
      parybface->tt.tet = checktet.tet;
      parybface->tt.ver = 11;
      parybface->forg = ppt[0];
      parybface->fdest = ppt[1];
      parybface->fapex = ppt[2];
      parybface->foppo = ppt[3];
      parybface->key = maxdd;
      for (n = 0; n < 6; n++) {
        parybface->cent[n] = ncosdd[n];
      }
    }
    checktet.tet = tetrahedrontraverse();
  }

  totalremcount = improvequalitybyflips();

  if ((unflipqueue->objects > 0l) &&
      ((b->optscheme & 2) || (b->optscheme & 4))) {
    // The pool is only used by removeslivers().
    badtetrahedrons = new memorypool(sizeof(triface), b->tetrahedraperblock,
                                     sizeof(void *), 0);

    // Smoothing options.
    opm.min_max_dihedangle = 1;
    opm.numofsearchdirs = 10;
    // opm.searchstep = 0.001;
    opm.maxiter = 30; // Limit the maximum iterations.
    //opm.checkencflag = 4; // Queue affected tets after smoothing.
    chkencflag = 4; // Queue affected tets after splitting a sliver.
    iter = 0;

    while (iter < optpasses) {
      smtcount = sptcount = remcount = 0l;
      if (b->optscheme & 2) {
        smtcount += improvequalitybysmoothing(&opm);
        totalsmtcount += smtcount;
        if (smtcount > 0l) {
          remcount = improvequalitybyflips();
          totalremcount += remcount;
        }
      }
      if (unflipqueue->objects > 0l) {
        if (b->optscheme & 4) {
          sptcount += removeslivers(chkencflag);
          totalsptcount += sptcount;
          if (sptcount > 0l) {
            remcount = improvequalitybyflips();
            totalremcount += remcount;
          }
        }
      }
      if (unflipqueue->objects > 0l) {
        if (remcount > 0l) {
          iter++;
        } else {
          break;
        }
      } else {
        break;
      }
    } // while (iter)

    delete badtetrahedrons;

  }

  if (unflipqueue->objects > 0l) {
    if (b->verbose > 1) {
      printf("    %ld bad tets remained.\n", unflipqueue->objects);
    }
    unflipqueue->restart();
  }

  if (b->verbose) {
    if (totalremcount > 0l) {
      printf("  Removed %ld edges.\n", totalremcount);
    }
    if (totalsmtcount > 0l) {
      printf("  Smoothed %ld points.\n", totalsmtcount);
    }
    if (totalsptcount > 0l) {
      printf("  Split %ld slivers.\n", totalsptcount);
    }
  }
}

////                                                                       ////
////                                                                       ////
//// optimize_cxx /////////////////////////////////////////////////////////////

void meshGRegionBoundaryRecovery::printtet(triface* tface)
{
  triface tmpface, prtface;
  shellface *shells;
  point tmppt;
  face checksh;
  int facecount;

  printf("Tetra x%lx ver %i loc %i:", (uintptr_t)(tface->tet),
	 tface->ver, tface->ver & 3);
  if (infected(*tface)) {
    printf(" (infected)");
  }
  if (marktested(*tface)) {
    printf(" (marked)");
  }
  if (marktest2ed(*tface)) {
    printf(" (qued)");
  }
  if (elemcounter(*tface) != 0) {
    printf(" c(%d)", elemcounter(*tface));
  }
  printf("\n");

  tmpface = *tface;
  facecount = 0;
  while(facecount < 4) {
    tmpface.ver = facecount;
    fsym(tmpface, prtface);
    if (prtface.tet != NULL) {
      printf("    [%i] x%lx  ver(%i)", facecount,
             (uintptr_t) (prtface.tet), prtface.ver);
      if((point) prtface.tet[7] == dummypoint) {
        printf(" (Outer space).");
      }

    } else {
      printf("    [%i] NULL!", facecount);
    }
    // Check if this face is marked.
    if (facemarked(tmpface)) {
      printf(" (marked)");
    }
    if ((tface->ver & 3) == facecount) {
      printf(" (*)");  // It is the current face.
    }
    printf("\n");
    facecount ++;
  }

  tmppt = org(*tface);
  if(tmppt == (point) NULL) {
    printf("    Org [%i] NULL\n", orgpivot[tface->ver] - 4);
  } else {
    printf("    Org [%i] x%lx (%.12g,%.12g,%.12g) %d\n",
           orgpivot[tface->ver] - 4, (uintptr_t)(tmppt), tmppt[0],
           tmppt[1], tmppt[2], pointmark(tmppt));
  }
  tmppt = dest(*tface);
  if(tmppt == (point) NULL) {
    printf("    Dest[%i] NULL\n", destpivot[tface->ver] - 4);
  } else {
    printf("    Dest[%i] x%lx (%.12g,%.12g,%.12g) %d\n",
           destpivot[tface->ver] - 4, (uintptr_t)(tmppt), tmppt[0],
           tmppt[1], tmppt[2], pointmark(tmppt));
  }
  tmppt = apex(*tface);
  if(tmppt == (point) NULL) {
    printf("    Apex[%i] NULL\n", apexpivot[tface->ver] - 4);
  } else {
    printf("    Apex[%i] x%lx (%.12g,%.12g,%.12g) %d\n",
           apexpivot[tface->ver] - 4, (uintptr_t)(tmppt), tmppt[0],
           tmppt[1], tmppt[2], pointmark(tmppt));
  }
  tmppt = oppo(*tface);
  if(tmppt == (point) NULL) {
    printf("    Oppo[%i] NULL\n", oppopivot[tface->ver] - 4);
  } else {
    printf("    Oppo[%i] x%lx (%.12g,%.12g,%.12g) %d\n",
           oppopivot[tface->ver] - 4, (uintptr_t)(tmppt), tmppt[0],
           tmppt[1], tmppt[2], pointmark(tmppt));
  }

  if (checksubsegflag) {
    if (tface->tet[8] != NULL) {
      shells = (shellface *) tface->tet[8];
      for (facecount = 0; facecount < 6; facecount++) {
        sdecode(shells[facecount], checksh);
        if (checksh.sh != NULL) {
          printf("      [%d] x%lx %d.", facecount, (uintptr_t) checksh.sh,
                 checksh.shver);
        } else {
          printf("      [%d] NULL.", facecount);
        }
        if (ver2edge[tface->ver] == facecount) {
          printf(" (*)");  // It is the current edge.
        }
        printf("\n");
      }
    }
  }
  if (checksubfaceflag) {
    if (tface->tet[9] != NULL) {
      shells = (shellface *) tface->tet[9];
      for (facecount = 0; facecount < 4; facecount++) {
        sdecode(shells[facecount], checksh);
        if (checksh.sh != NULL) {
          printf("      [%d] x%lx %d.", facecount, (uintptr_t) checksh.sh,
                 checksh.shver);
        } else {
          printf("      [%d] NULL.", facecount);
        }
        if ((tface->ver & 3) == facecount) {
          printf(" (*)");  // It is the current face.
        }
        printf("\n");
      }
    }
  }
}

// Only print the vertices of the tet.
void meshGRegionBoundaryRecovery::ptetv(triface* t)
{
  printf("  tet x%lx (%d, %d, %d, %d) %d\n", (uintptr_t) t->tet,
          pointmark(org(*t)), pointmark(dest(*t)), pointmark(apex(*t)),
          pointmark(oppo(*t)), t->ver);
}

void meshGRegionBoundaryRecovery::outmesh2medit(const char* mfilename)
{
  FILE *outfile;
  char mefilename[256];
  tetrahedron* tetptr;
  triface tface, tsymface;
  face segloop, checkmark;
  point ptloop, p1, p2, p3, p4;
  long ntets, faces;
  int shift = 0;
  int marker;

  if (mfilename != (char *) NULL && mfilename[0] != '\0') {
    strcpy(mefilename, mfilename);
  } else {
    strcpy(mefilename, "unnamed");
  }
  strcat(mefilename, ".mesh");

  if (!b->quiet) {
    printf("Writing %s.\n", mefilename);
  }
  outfile = fopen(mefilename, "w");
  if (outfile == (FILE *) NULL) {
    printf("File I/O Error:  Cannot create file %s.\n", mefilename);
    return;
  }

  fprintf(outfile, "MeshVersionFormatted 1\n");
  fprintf(outfile, "\n");
  fprintf(outfile, "Dimension\n");
  fprintf(outfile, "3\n");
  fprintf(outfile, "\n");

  fprintf(outfile, "\n# Set of mesh vertices\n");
  fprintf(outfile, "Vertices\n");
  fprintf(outfile, "%ld\n", points->items);

  points->traversalinit();
  ptloop = pointtraverse();
  //pointnumber = 1;
  while (ptloop != (point) NULL) {
    // Point coordinates.
    fprintf(outfile, "%.17g  %.17g  %.17g", ptloop[0], ptloop[1], ptloop[2]);
    fprintf(outfile, "    0\n");
    //setpointmark(ptloop, pointnumber);
    ptloop = pointtraverse();
    //pointnumber++;
  }

  // Medit need start number form 1.
  if (in->firstnumber == 1) {
    shift = 0;
  } else {
    shift = 1;
  }

  // Compute the number of faces.
  ntets = tetrahedrons->items - hullsize;
  faces = (ntets * 4l + hullsize) / 2l;

  /*
  fprintf(outfile, "\n# Set of Triangles\n");
  fprintf(outfile, "Triangles\n");
  fprintf(outfile, "%ld\n", faces);

  tetrahedrons->traversalinit();
  tface.tet = tetrahedrontraverse();
  while (tface.tet != (tetrahedron *) NULL) {
    for (tface.ver = 0; tface.ver < 4; tface.ver ++) {
      fsym(tface, tsymface);
      if (ishulltet(tsymface) ||
          (elemindex(tface.tet) < elemindex(tsymface.tet))) {
        p1 = org (tface);
        p2 = dest(tface);
        p3 = apex(tface);
        fprintf(outfile, "%5d  %5d  %5d",
          pointmark(p1)+shift, pointmark(p2)+shift, pointmark(p3)+shift);
        // Check if it is a subface.
        tspivot(tface, checkmark);
        if (checkmark.sh == NULL) {
          marker = 0;  // It is an inner face. It's marker is 0.
        } else {
          marker = 1; // The default marker for subface is 1.
        }
        fprintf(outfile, "    %d\n", marker);
      }
    }
    tface.tet = tetrahedrontraverse();
  }
  */

  fprintf(outfile, "\n# Set of Tetrahedra\n");
  fprintf(outfile, "Tetrahedra\n");
  fprintf(outfile, "%ld\n", ntets);

  tetrahedrons->traversalinit();
  tetptr = tetrahedrontraverse();
  while (tetptr != (tetrahedron *) NULL) {
    if (!b->reversetetori) {
      p1 = (point) tetptr[4];
      p2 = (point) tetptr[5];
    } else {
      p1 = (point) tetptr[5];
      p2 = (point) tetptr[4];
    }
    p3 = (point) tetptr[6];
    p4 = (point) tetptr[7];
    fprintf(outfile, "%5d  %5d  %5d  %5d",
            pointmark(p1)+shift, pointmark(p2)+shift,
            pointmark(p3)+shift, pointmark(p4)+shift);
    if (numelemattrib > 0) {
      fprintf(outfile, "  %.17g", elemattribute(tetptr, 0));
    } else {
      fprintf(outfile, "  0");
    }
    fprintf(outfile, "\n");
    tetptr = tetrahedrontraverse();
  }

  fprintf(outfile, "\nEnd\n");
  fclose(outfile);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// checkmesh()    Test the mesh for topological consistency.                 //
//                                                                           //
// If 'topoflag' is set, only check the topological connection of the mesh,  //
// i.e., do not report degenerated or inverted elements.                     //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

int meshGRegionBoundaryRecovery::checkmesh(int topoflag)
{
  triface tetloop, neightet, symtet;
  point pa, pb, pc, pd;
  REAL ori;
  int horrors, i;

  if (!b->quiet) {
    printf("  Checking consistency of mesh...\n");
  }

  horrors = 0;
  tetloop.ver = 0;
  // Run through the list of tetrahedra, checking each one.
  tetrahedrons->traversalinit();
  tetloop.tet = alltetrahedrontraverse();
  while (tetloop.tet != (tetrahedron *) NULL) {
    // Check all four faces of the tetrahedron.
    for (tetloop.ver = 0; tetloop.ver < 4; tetloop.ver++) {
      pa = org(tetloop);
      pb = dest(tetloop);
      pc = apex(tetloop);
      pd = oppo(tetloop);
      if (tetloop.ver == 0) {  // Only test for inversion once.
        if (!ishulltet(tetloop)) {  // Only do test if it is not a hull tet.
          if (!topoflag) {
            ori = orient3d(pa, pb, pc, pd);
            if (ori >= 0.0) {
              printf("  !! !! %s ", ori > 0.0 ? "Inverted" : "Degenerated");
              printf("  (%d, %d, %d, %d) (ori = %.17g)\n", pointmark(pa),
                     pointmark(pb), pointmark(pc), pointmark(pd), ori);
              horrors++;
            }
          }
        }
        if (infected(tetloop)) {
          // This may be a bug. Report it.
          printf("  !! (%d, %d, %d, %d) is infected.\n", pointmark(pa),
                 pointmark(pb), pointmark(pc), pointmark(pd));
          horrors++;
        }
        if (marktested(tetloop)) {
          // This may be a bug. Report it.
          printf("  !! (%d, %d, %d, %d) is marked.\n", pointmark(pa),
                 pointmark(pb), pointmark(pc), pointmark(pd));
          horrors++;
        }
      }
      if (tetloop.tet[tetloop.ver] == NULL) {
        printf("  !! !! No neighbor at face (%d, %d, %d).\n", pointmark(pa),
               pointmark(pb), pointmark(pc));
        horrors++;
      } else {
        // Find the neighboring tetrahedron on this face.
        fsym(tetloop, neightet);
        if (neightet.tet != NULL) {
          // Check that the tetrahedron's neighbor knows it's a neighbor.
          fsym(neightet, symtet);
          if ((tetloop.tet != symtet.tet) || (tetloop.ver != symtet.ver)) {
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
          // Check if they have the same apex.
          if (apex(neightet) != pc) {
            printf("  !! !! Wrong face-face bond:\n");
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
        } else {
          printf("  !! !! Tet-face has no neighbor (%d, %d, %d) - %d:\n",
                 pointmark(pa), pointmark(pb), pointmark(pc), pointmark(pd));
          horrors++;
        }
      }
      if (facemarked(tetloop)) {
        // This may be a bug. Report it.
        printf("  !! tetface (%d, %d, %d) %d is marked.\n", pointmark(pa),
               pointmark(pb), pointmark(pc), pointmark(pd));
      }
    }
    // Check the six edges of this tet.
    for (i = 0; i < 6; i++) {
      tetloop.ver = edge2ver[i];
      if (edgemarked(tetloop)) {
        // This may be a bug. Report it.
        printf("  !! tetedge (%d, %d) %d, %d is marked.\n",
               pointmark(org(tetloop)), pointmark(dest(tetloop)),
               pointmark(apex(tetloop)), pointmark(oppo(tetloop)));
      }
    }
    tetloop.tet = alltetrahedrontraverse();
  }
  if (horrors == 0) {
    if (!b->quiet) {
      printf("  In my studied opinion, the mesh appears to be consistent.\n");
    }
  } else {
    printf("  !! !! !! !! %d %s witnessed.\n", horrors,
           horrors > 1 ? "abnormity" : "abnormities");
  }

  return horrors;
}

///////////////////////////////////////////////////////////////////////////////

void meshGRegionBoundaryRecovery::unifysubfaces(face *f1, face *f2)
{
  if (b->psc) {
    // In this case, it is possible that two subfaces are identical.
    // While they must belong to two different surfaces.
    return;
  }

  point pa, pb, pc, pd;

  pa = sorg(*f1);
  pb = sdest(*f1);
  pc = sapex(*f1);
  pd = sapex(*f2);

  if (pc != pd) {
    printf("Found two facets intersect each other.\n");
    printf("  1st: [%d, %d, %d] #%d\n",
	       pointmark(pa), pointmark(pb), pointmark(pc), shellmark(*f1));
    printf("  2nd: [%d, %d, %d] #%d\n",
	       pointmark(pa), pointmark(pb), pointmark(pd), shellmark(*f2));
    terminateBoundaryRecovery(this, 3);
  } else {
    printf("Found two duplicated facets.\n");
    printf("  1st: [%d, %d, %d] #%d\n",
	       pointmark(pa), pointmark(pb), pointmark(pc), shellmark(*f1));
    printf("  2nd: [%d, %d, %d] #%d\n",
	       pointmark(pa), pointmark(pb), pointmark(pd), shellmark(*f2));
    terminateBoundaryRecovery(this, 3);
  }

}

void meshGRegionBoundaryRecovery::unifysegments()
{
  badface *facelink = NULL, *newlinkitem, *f1, *f2;
  face *facperverlist, sface;
  face subsegloop, testseg;
  point torg, tdest;
  REAL ori1, ori2, ori3;
  REAL n1[3], n2[3];
  int *idx2faclist;
  int idx, k, m;

  if (b->verbose > 1) {
    printf("  Unifying segments.\n");
  }

  // Create a mapping from vertices to subfaces.
  makepoint2submap(subfaces, idx2faclist, facperverlist);

  subsegloop.shver = 0;
  subsegs->traversalinit();
  subsegloop.sh = shellfacetraverse(subsegs);
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
              facenormal(torg, tdest, sapex(f1->ss), n1, 1, NULL);
              facenormal(torg, tdest, sapex(sface), n2, 1, NULL);
              if (dot(n1, n2) > 0) {
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
          facenormal(torg, tdest, sapex(f1->ss), n1, 1, NULL);
          facenormal(torg, tdest, sapex(sface), n2, 1, NULL);
          if (dot(n1, n2) > 0) {
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

    if (b->psc) {
      // Set Steiner point -to- segment map.
      if (pointtype(torg) == FREESEGVERTEX) {
        setpoint2sh(torg, sencode(subsegloop));
      }
      if (pointtype(tdest) == FREESEGVERTEX) {
        setpoint2sh(tdest, sencode(subsegloop));
      }
    }

    // Set the connection between this segment and faces containing it,
    //   at the same time, remove redundant segments.
    f1 = facelink;
    for (k = 0; k < flippool->items; k++) {
      sspivot(f1->ss, testseg);
      // If 'testseg' is not 'subsegloop' and is not dead, it is redundant.
      if ((testseg.sh != subsegloop.sh) && (testseg.sh[3] != NULL)) {
        shellfacedealloc(subsegs, testseg.sh);
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
        sbond1(f1->ss, f2->ss);
        f1 = f2;
      }
    }

    // All identified segments has an init marker "0".
    flippool->restart();

    subsegloop.sh = shellfacetraverse(subsegs);
  }

  delete [] idx2faclist;
  delete [] facperverlist;
}

void meshGRegionBoundaryRecovery::jettisonnodes()
{
  point pointloop;
  bool jetflag;
  int oldidx, newidx;
  int remcount;

  if (!b->quiet) {
    printf("Jettisoning redundant points.\n");
  }

  points->traversalinit();
  pointloop = pointtraverse();
  oldidx = newidx = 0; // in->firstnumber;
  remcount = 0;
  while (pointloop != (point) NULL) {
    jetflag = (pointtype(pointloop) == DUPLICATEDVERTEX) ||
      (pointtype(pointloop) == UNUSEDVERTEX);
    if (jetflag) {
      // It is a duplicated or unused point, delete it.
      pointdealloc(pointloop);
      remcount++;
    } else {
      // Re-index it.
      setpointmark(pointloop, newidx + in->firstnumber);
      /*
      if (in->pointmarkerlist != (int *) NULL) {
        if (oldidx < in->numberofpoints) {
          // Re-index the point marker as well.
          in->pointmarkerlist[newidx] = in->pointmarkerlist[oldidx];
        }
      }
      */
      newidx++;
    }
    oldidx++;
    pointloop = pointtraverse();
  }
  if (b->verbose) {
    printf("  %ld duplicated vertices are removed.\n", dupverts);
    printf("  %ld unused vertices are removed.\n", unuverts);
  }
  dupverts = 0l;
  unuverts = 0l;

  // The following line ensures that dead items in the pool of nodes cannot
  //   be allocated for the new created nodes. This ensures that the input
  //   nodes will occur earlier in the output files, and have lower indices.
  points->deaditemstack = (void *) NULL;
}

///////////////////////////////////////////////////////////////////////////////

void meshGRegionBoundaryRecovery::reconstructmesh(GRegion *_gr)
{
  std::vector<MVertex*> _vertices;

  // Get the set of vertices from GRegion.
  {
    std::set<MVertex*> all;
    std::list<GFace*> f = _gr->faces();
    for (std::list<GFace*>::iterator it = f.begin(); it != f.end(); ++it) {
	  GFace *gf = *it;
	  for (unsigned int i = 0;i< gf->triangles.size(); i++){
        all.insert(gf->triangles[i]->getVertex(0));
        all.insert(gf->triangles[i]->getVertex(1));
        all.insert(gf->triangles[i]->getVertex(2));
	  }
    }
    _vertices.insert(_vertices.begin(), all.begin(), all.end());
  }

  initializepools();

  std::vector<MTetrahedron*> tets;

if (1) {
  // Generate the DT.
  delaunayMeshIn3D(_vertices, tets, false);
}

{ //transfernodes();
  point pointloop;
  REAL x, y, z;
  int i;

  // Read the points.
  for (i = 0; i < _vertices.size(); i++) {
    makepoint(&pointloop, UNUSEDVERTEX);
    // Read the point coordinates.
    x = pointloop[0] = _vertices[i]->x();
    y = pointloop[1] = _vertices[i]->y();
    z = pointloop[2] = _vertices[i]->z();
    // Determine the smallest and largest x, y and z coordinates.
    if (i == 0) {
      xmin = xmax = x;
      ymin = ymax = y;
      zmin = zmax = z;
    } else {
      xmin = (x < xmin) ? x : xmin;
      xmax = (x > xmax) ? x : xmax;
      ymin = (y < ymin) ? y : ymin;
      ymax = (y > ymax) ? y : ymax;
      zmin = (z < zmin) ? z : zmin;
      zmax = (z > zmax) ? z : zmax;
    }
  }

  // 'longest' is the largest possible edge length formed by input vertices.
  x = xmax - xmin;
  y = ymax - ymin;
  z = zmax - zmin;
  longest = sqrt(x * x + y * y + z * z);
  if (longest == 0.0) {
    printf("Error:  The point set is trivial.\n");
    throw 3; //terminateBoundaryRecovery(this, 3);
  }

  // Two identical points are distinguished by 'lengthlimit'.
  if (b->minedgelength == 0.0) {
    b->minedgelength = longest * b->epsilon;
  }
} // transfernodes();

  point *idx2verlist;

  // Create a map from indices to vertices.
  makeindex2pointmap(idx2verlist);
  // 'idx2verlist' has length 'in->numberofpoints + 1'.
  if (in->firstnumber == 1) {
    idx2verlist[0] = dummypoint; // Let 0th-entry be dummypoint.
  }

if (1) {
  // Index the vertices.
  for (unsigned int i = 0; i < _vertices.size(); i++){
	_vertices[i]->setIndex(i);
  }

  tetrahedron *ver2tetarray;
  //point *idx2verlist;
  triface tetloop, checktet, prevchktet;
  triface hulltet, face1, face2;
  tetrahedron tptr;
  point p[4], q[3];
  REAL ori; //, attrib, volume;
  int bondflag;
  int t1ver;
  int idx, i, j, k;

  if (!b->quiet) {
    printf("Reconstructing mesh ...\n");
  }

  // Allocate an array that maps each vertex to its adjacent tets.
  ver2tetarray = new tetrahedron[_vertices.size() + 1];
  //for (i = 0; i < in->numberofpoints + 1; i++) {
  for (i = in->firstnumber; i < _vertices.size() + in->firstnumber; i++) {
    setpointtype(idx2verlist[i], VOLVERTEX); // initial type.
    ver2tetarray[i] = NULL;
  }

  // Create the tetrahedra and connect those that share a common face.
  for (i = 0; i < tets.size(); i++) {
    // Get the four vertices.
    for (j = 0; j < 4; j++) {
      p[j] = idx2verlist[tets[i]->getVertex(j)->getIndex()];
    }
    // Check the orientation.
    ori = orient3d(p[0], p[1], p[2], p[3]);
    if (ori > 0.0) {
      // Swap the first two vertices.
      q[0] = p[0]; p[0] = p[1]; p[1] = q[0];
    } else if (ori == 0.0) {
      if (!b->quiet) {
        printf("Warning:  Tet #%d is degenerate.\n", i + in->firstnumber);
      }
    }
    // Create a new tetrahedron.
    maketetrahedron(&tetloop); // tetloop.ver = 11.
    setvertices(tetloop, p[0], p[1], p[2], p[3]);
    // Try connecting this tet to others that share the common faces.
    for (tetloop.ver = 0; tetloop.ver < 4; tetloop.ver++) {
      p[3] = oppo(tetloop);
      // Look for other tets having this vertex.
      idx = pointmark(p[3]);
      tptr = ver2tetarray[idx];
      // Link the current tet to the next one in the stack.
      tetloop.tet[8 + tetloop.ver] = tptr;
      // Push the current tet onto the stack.
      ver2tetarray[idx] = encode(tetloop);
      decode(tptr, checktet);
      if (checktet.tet != NULL) {
        p[0] =  org(tetloop); // a
        p[1] = dest(tetloop); // b
        p[2] = apex(tetloop); // c
        prevchktet = tetloop;
        do {
          q[0] =  org(checktet); // a'
          q[1] = dest(checktet); // b'
          q[2] = apex(checktet); // c'
          // Check the three faces at 'd' in 'checktet'.
          bondflag = 0;
          for (j = 0; j < 3; j++) {
            // Go to the face [b',a',d], or [c',b',d], or [a',c',d].
            esym(checktet, face2);
            if (face2.tet[face2.ver & 3] == NULL) {
              k = ((j + 1) % 3);
              if (q[k] == p[0]) {   // b', c', a' = a
                if (q[j] == p[1]) { // a', b', c' = b
                  // [#,#,d] is matched to [b,a,d].
                  esym(tetloop, face1);
                  bond(face1, face2);
                  bondflag++;
                }
              }
              if (q[k] == p[1]) {   // b',c',a' = b
                if (q[j] == p[2]) { // a',b',c' = c
                  // [#,#,d] is matched to [c,b,d].
                  enext(tetloop, face1);
                  esymself(face1);
                  bond(face1, face2);
                  bondflag++;
                }
              }
              if (q[k] == p[2]) {   // b',c',a' = c
                if (q[j] == p[0]) { // a',b',c' = a
                  // [#,#,d] is matched to [a,c,d].
                  eprev(tetloop, face1);
                  esymself(face1);
                  bond(face1, face2);
                  bondflag++;
                }
              }
            } else {
              bondflag++;
            }
            enextself(checktet);
          } // j
          // Go to the next tet in the link.
          tptr = checktet.tet[8 + checktet.ver];
          if (bondflag == 3) {
            // All three faces at d in 'checktet' have been connected.
            // It can be removed from the link.
            prevchktet.tet[8 + prevchktet.ver] = tptr;
          } else {
            // Bakup the previous tet in the link.
            prevchktet = checktet;
          }
          decode(tptr, checktet);
        } while (checktet.tet != NULL);
      } // if (checktet.tet != NULL)
    } // for (tetloop.ver = 0; ...
  } // i

  // Remember a tet of the mesh.
  recenttet = tetloop;

  // Create hull tets, create the point-to-tet map, and clean up the
  //   temporary spaces used in each tet.
  hullsize = tetrahedrons->items;

  tetrahedrons->traversalinit();
  tetloop.tet = tetrahedrontraverse();
  while (tetloop.tet != (tetrahedron *) NULL) {
    tptr = encode(tetloop);
    for (tetloop.ver = 0; tetloop.ver < 4; tetloop.ver++) {
      if (tetloop.tet[tetloop.ver] == NULL) {
        // Create a hull tet.
        maketetrahedron(&hulltet);
        p[0] =  org(tetloop);
        p[1] = dest(tetloop);
        p[2] = apex(tetloop);
        setvertices(hulltet, p[1], p[0], p[2], dummypoint);
        bond(tetloop, hulltet);
        // Try connecting this to others that share common hull edges.
        for (j = 0; j < 3; j++) {
          fsym(hulltet, face2);
          while (1) {
            if (face2.tet == NULL) break;
            esymself(face2);
            if (apex(face2) == dummypoint) break;
            fsymself(face2);
          }
          if (face2.tet != NULL) {
            // Found an adjacent hull tet.
            assert(face2.tet[face2.ver & 3] == NULL);
            esym(hulltet, face1);
            bond(face1, face2);
          }
          enextself(hulltet);
        }
        //hullsize++;
      }
      // Create the point-to-tet map.
      setpoint2tet((point) (tetloop.tet[4 + tetloop.ver]), tptr);
      // Clean the temporary used space.
      tetloop.tet[8 + tetloop.ver] = NULL;
    }
    tetloop.tet = tetrahedrontraverse();
  }

  hullsize = tetrahedrons->items - hullsize;

  delete [] ver2tetarray;
  tets.clear(); // Release all memory in this vector.
} else {
  triface searchtet;
  point *permutarray, swapvertex;
  REAL v1[3], v2[3], n[3];
  REAL bboxsize, bboxsize2, bboxsize3, ori;
  int randindex;
  int ngroup = 0;
  int i, j;

  if (!b->quiet) {
    printf("Delaunizing vertices...\n");
  }

  // Form a random permuation (uniformly at random) of the set of vertices.
  permutarray = new point[_vertices.size()];
  points->traversalinit();

    if (b->verbose) {
      printf("  Permuting vertices.\n");
    }
    srand(_vertices.size());
    for (i = 0; i < _vertices.size(); i++) {
      randindex = rand() % (i + 1); // randomnation(i + 1);
      permutarray[i] = permutarray[randindex];
      permutarray[randindex] = (point) points->traverse();
    }
    if (b->brio_hilbert) { // -b option
      if (b->verbose) {
        printf("  Sorting vertices.\n");
      }
      hilbert_init(3);
      brio_multiscale_sort(permutarray, _vertices.size(), b->brio_threshold,
                           b->brio_ratio, &ngroup);
    }

  // Index the vertices.
  for (unsigned int i = 0; i < _vertices.size(); i++) {
	_vertices[i]->setIndex(i);
  }

  // Calculate the diagonal size of its bounding box.
  bboxsize = sqrt(norm2(xmax - xmin, ymax - ymin, zmax - zmin));
  bboxsize2 = bboxsize * bboxsize;
  bboxsize3 = bboxsize2 * bboxsize;

  // Make sure the second vertex is not identical with the first one.
  i = 1;
  while ((distance(permutarray[0],permutarray[i])/bboxsize)<b->epsilon) {
    i++;
    if (i == _vertices.size() - 1) {
      printf("Exception:  All vertices are (nearly) identical (Tol = %g).\n",
             b->epsilon);
      throw 10;
    }
  }
  if (i > 1) {
    // Swap to move the non-identical vertex from index i to index 1.
    swapvertex = permutarray[i];
    permutarray[i] = permutarray[1];
    permutarray[1] = swapvertex;
  }

  i = 2;
  for (j = 0; j < 3; j++) {
    v1[j] = permutarray[1][j] - permutarray[0][j];
    v2[j] = permutarray[i][j] - permutarray[0][j];
  }
  cross(v1, v2, n);
  while ((sqrt(norm2(n[0], n[1], n[2])) / bboxsize2) <
         (b->epsilon * b->epsilon)) {
    i++;
    if (i == _vertices.size() - 1) {
      printf("Exception:  All vertices are (nearly) collinear (Tol = %g).\n",
             b->epsilon);
      throw 10;
    }
    for (j = 0; j < 3; j++) {
      v2[j] = permutarray[i][j] - permutarray[0][j];
    }
    cross(v1, v2, n);
  }
  if (i > 2) {
    // Swap to move the non-identical vertex from index i to index 1.
    swapvertex = permutarray[i];
    permutarray[i] = permutarray[2];
    permutarray[2] = swapvertex;
  }

  // Make sure the fourth vertex is not coplanar with the first three.
  i = 3;
  ori = orient3dfast(permutarray[0], permutarray[1], permutarray[2],
                     permutarray[i]);
  while ((fabs(ori) / bboxsize3) < (b->epsilon * b->epsilon * b->epsilon)) {
    i++;
    if (i == _vertices.size()) {
      printf("Exception:  All vertices are coplanar (Tol = %g).\n",
             b->epsilon);
      throw 10;
    }
    ori = orient3dfast(permutarray[0], permutarray[1], permutarray[2],
                       permutarray[i]);
  }
  if (i > 3) {
    // Swap to move the non-identical vertex from index i to index 1.
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
  initialdelaunay(permutarray[0], permutarray[1], permutarray[2],
                  permutarray[3]);

  if (b->verbose) {
    printf("  Incrementally inserting vertices.\n");
  }
  insertvertexflags ivf;
  flipconstraints fc;

  // Choose algorithm: Bowyer-Watson (default) or Incremental Flip
  if (b->incrflip) {
    ivf.bowywat = 0;
    ivf.lawson = 1;
    fc.enqflag = 1;
  } else {
    ivf.bowywat = 1;
    ivf.lawson = 0;
  }

  for (i = 4; i < _vertices.size(); i++) {
    if (pointtype(permutarray[i]) == UNUSEDVERTEX) {
      setpointtype(permutarray[i], VOLVERTEX);
    }
    if (b->brio_hilbert || b->no_sort) { // -b or -b/1
      // Start the last updated tet.
      searchtet.tet = recenttet.tet;
    } else { // -b0
      // Randomly choose the starting tet for point location.
      searchtet.tet = NULL;
    }
    ivf.iloc = (int) OUTSIDE;
    // Insert the vertex.
    if (insertpoint(permutarray[i], &searchtet, NULL, NULL, &ivf)) {
      //if (flipstack != NULL) {
        //// Perform flip to recover Delaunayness.
        //incrementalflip(permutarray[i], (ivf.iloc == (int) OUTSIDE), &fc);
      //}
    } else {
      if (ivf.iloc == (int) ONVERTEX) {
        // The point already exists. Mark it and do nothing on it.
        swapvertex = org(searchtet);
        assert(swapvertex != permutarray[i]); // SELF_CHECK
        //if (b->object != tetgenbehavior::STL) {
          if (!b->quiet) {
            printf("Warning:  Point #%d is coincident with #%d. Ignored!\n",
                   pointmark(permutarray[i]), pointmark(swapvertex));
          }
        //}
        setpoint2ppt(permutarray[i], swapvertex);
        setpointtype(permutarray[i], DUPLICATEDVERTEX);
        dupverts++;
      } else if (ivf.iloc == (int) NEARVERTEX) {
        swapvertex = point2ppt(permutarray[i]);
        if (!b->quiet) {
          printf("Warning:  Point %d is replaced by point %d.\n",
                 pointmark(permutarray[i]), pointmark(swapvertex));
          printf("  Avoid creating a very short edge (len = %g) (< %g).\n",
                 permutarray[i][3], b->minedgelength);
          printf("  You may try a smaller tolerance (-T) (current is %g)\n",
                 b->epsilon);
          printf("  or use the option -M0/1 to avoid such replacement.\n");
        }
        // Remember it is a duplicated point.
        setpointtype(permutarray[i], DUPLICATEDVERTEX);
        // Count the number of duplicated points.
        dupverts++;
      }
    }
  }

  delete [] permutarray;
} // incrementaldelaunay()

  std::list<GFace*> f_list = _gr->faces();
  std::list<GEdge*> e_list = _gr->edges();

{
  if (!b->quiet) {
    printf("Creating surface mesh ...\n");
  }
  face newsh;
  face newseg;
  point p[4];
  int idx, i, j;

  for (std::list<GFace*>::iterator it = f_list.begin(); it != f_list.end(); ++it){
	GFace *gf = *it;
	for (i = 0;i< gf->triangles.size(); i++) {
      for (j = 0; j < 3; j++) {
        p[j] = idx2verlist[gf->triangles[i]->getVertex(j)->getIndex()];
        if (pointtype(p[j]) == VOLVERTEX) {
          setpointtype(p[j], FACETVERTEX);
        }
      }
      // Create an initial triangulation.
      makeshellface(subfaces, &newsh);
      setshvertices(newsh, p[0], p[1], p[2]);
      setshellmark(newsh, gf->tag()); // the GFace's tag.
      recentsh = newsh;
      for (j = 0; j < 3; j++) {
        makeshellface(subsegs, &newseg);
        setshvertices(newseg, sorg(newsh), sdest(newsh), NULL);
        // Set the default segment marker '-1'.
        setshellmark(newseg, -1);
        ssbond(newsh, newseg);
        senextself(newsh);
      }
	} // i
  } // it

  // Connecting triangles, removing redundant segments.
  unifysegments();

  if (!b->quiet) {
    printf("Identifying boundary edges ...\n");
  }
  face* shperverlist;
  int* idx2shlist;
  face searchsh, neighsh;
  face segloop, checkseg;
  point checkpt;

  // Construct a map from points to subfaces.
  makepoint2submap(subfaces, idx2shlist, shperverlist);

  // Process the set of PSC edges.
  // Remeber that all segments have default marker '-1'.
  for (std::list<GEdge*>::iterator it = e_list.begin(); it != e_list.end();
       ++it) {
    GEdge *ge = *it;
    for (i = 0; i < ge->lines.size(); i++) {
      for (j = 0; j < 2; j++) {
        p[j] = idx2verlist[ge->lines[i]->getVertex(j)->getIndex()];
        setpointtype(p[j], RIDGEVERTEX);
      }
      if (p[0] == p[1]) {
        // This is a potential problem in surface mesh.
        continue; // Skip this edge.
      }
      // Find a face contains the edge p[0], p[1].
      newseg.sh = NULL;
      searchsh.sh = NULL;
      idx = pointmark(p[0]) - in->firstnumber;
      for (j = idx2shlist[idx]; j < idx2shlist[idx + 1]; j++) {
        checkpt = sdest(shperverlist[j]);
        if (checkpt == p[1]) {
          searchsh = shperverlist[j];
          break; // Found.
        } else {
          checkpt = sapex(shperverlist[j]);
          if (checkpt == p[1]) {
            senext2(shperverlist[j], searchsh);
            sesymself(searchsh);
            break;
          }
        }
      } // j
      if (searchsh.sh != NULL) {
        // Check if this edge is already a segment of the mesh.
        sspivot(searchsh, checkseg);
        if (checkseg.sh != NULL) {
          // This segment already exist.
          newseg = checkseg;
        } else {
          // Create a new segment at this edge.
          makeshellface(subsegs, &newseg);
          setshvertices(newseg, p[0], p[1], NULL);
          ssbond(searchsh, newseg);
          spivot(searchsh, neighsh);
          if (neighsh.sh != NULL) {
            ssbond(neighsh, newseg);
          }
        }
      } else {
        // It is a dangling segment (not belong to any facets).
        // Check if segment [p[0],p[1]] already exists.
        // TODO: Change the brute-force search. Slow!
        point *ppt;
        subsegs->traversalinit();
        segloop.sh = shellfacetraverse(subsegs);
        while (segloop.sh != NULL) {
          ppt = (point *) &(segloop.sh[3]);
          if (((ppt[0] == p[0]) && (ppt[1] == p[1])) ||
              ((ppt[0] == p[1]) && (ppt[1] == p[0]))) {
            // Found!
            newseg = segloop;
            break;
          }
          segloop.sh = shellfacetraverse(subsegs);
        }
        if (newseg.sh == NULL) {
          makeshellface(subsegs, &newseg);
          setshvertices(newseg, p[0], p[1], NULL);
        }
      }
      setshellmark(newseg, ge->tag());
    } // i
  } // e_list

  delete [] shperverlist;
  delete [] idx2shlist;

  if (b->verbose) {
    printf("  %ld (%ld) subfaces (segments).\n", subfaces->items,
           subsegs->items);
  }

  // The total number of iunput segments.
  insegments = subsegs->items;
} // meshsurface()

  delete [] idx2verlist;

  ////////////////////////////////////////////////////////
  // Boundary recovery.
  clock_t t_tmp;

  recoverboundary(t_tmp);

  carveholes();

  if (subvertstack->objects > 0l) {
    suppresssteinerpoints();
  }

  recoverdelaunay();

  optimizemesh();

  if ((dupverts > 0l) || (unuverts > 0l)) {
    // Remove hanging nodes.
    jettisonnodes();
  }

  long tetnumber, facenumber;

  printf("\nStatistics:\n\n");
  printf("  Input points: %ld\n", _vertices.size());
  //if (b->refine) {
  //  printf("  Input tetrahedra: %d\n", in->numberoftetrahedra);
  //}
  if (b->plc) {
    printf("  Input facets: %ld\n", f_list.size());
    printf("  Input segments: %ld\n", e_list.size());
    //printf("  Input holes: %d\n", in->numberofholes);
    //printf("  Input regions: %d\n", in->numberofregions);
  }

  tetnumber = tetrahedrons->items - hullsize;
  facenumber = (tetnumber * 4l + hullsize) / 2l;

  if (b->weighted) { // -w option
    printf("\n  Mesh points: %ld\n", points->items - nonregularcount);
  } else {
    printf("\n  Mesh points: %ld\n", points->items);
  }
  printf("  Mesh tetrahedra: %ld\n", tetnumber);
  printf("  Mesh faces: %ld\n", facenumber);
  if (meshedges > 0l) {
    printf("  Mesh edges: %ld\n", meshedges);
  } else {
    if (!nonconvex) {
      long vsize = points->items - dupverts - unuverts;
      if (b->weighted) vsize -= nonregularcount;
      meshedges = vsize + facenumber - tetnumber - 1;
      printf("  Mesh edges: %ld\n", meshedges);
    }
  }

  if (b->plc || b->refine) {
    printf("  Mesh faces on facets: %ld\n", subfaces->items);
    printf("  Mesh edges on segments: %ld\n", subsegs->items);
    if (st_volref_count > 0l) {
      printf("  Steiner points inside domain: %ld\n", st_volref_count);
    }
    if (st_facref_count > 0l) {
      printf("  Steiner points on facets:  %ld\n", st_facref_count);
    }
    if (st_segref_count > 0l) {
      printf("  Steiner points on segments:  %ld\n", st_segref_count);
    }
  } else {
    printf("  Convex hull faces: %ld\n", hullsize);
    if (meshhulledges > 0l) {
      printf("  Convex hull edges: %ld\n", meshhulledges);
    }
  }
  if (b->weighted) { // -w option
    printf("  Skipped non-regular points: %ld\n", nonregularcount);
  }
  printf("\n");

  // Debug
  //outmesh2medit("dump");
  ////////////////////////////////////////////////////////

{
  ////////////////////////////////////////////////////////
  // Write mesh into to GRegion.
  point p[4];
  int i;

  // In some hard cases, the surface mesh may be modified.
  // Find the list of GFaces, GEdges that have been modified.
  std::set<int> l_faces, l_edges;

  if (points->items > _vertices.size()) {
    face parentseg, parentsh, spinsh;
    point pointloop;
    // Create newly added mesh vertices.
    // The new vertices must be added at the end of the point list.
    points->traversalinit();
    pointloop = pointtraverse();
    while (pointloop != (point) NULL) {
      if (issteinerpoint(pointloop)) {
        // Check if this Steiner point locates on boundary.
        if (pointtype(pointloop) == FREESEGVERTEX) {
          sdecode(point2sh(pointloop), parentseg);
          assert(parentseg.sh != NULL);
          l_edges.insert(shellmark(parentseg));
          // Get the GEdge containing this vertex.
          GEdge *ge = NULL; 
          GFace *gf = NULL;
          int etag = shellmark(parentseg);
          for (std::list<GEdge*>::iterator it = e_list.begin();
               it != e_list.end(); ++it) {
            if ((*it)->tag() == etag) {
              ge = *it;
              break;
            }
          }
          if (ge != NULL) {
            MEdgeVertex *v = new MEdgeVertex(pointloop[0], pointloop[1],
                                         pointloop[2], ge, 0);
            double uu = 0;
            if (reparamMeshVertexOnEdge(v, ge, uu)) {
              v->setParameter(0, uu);
            }
            v->setIndex(pointmark(pointloop));
            _gr->mesh_vertices.push_back(v);
            _vertices.push_back(v);
          }
          spivot(parentseg, parentsh);
          if (parentsh.sh != NULL) {
            if (ge == NULL) {
              // We treat this vertex a facet vertex.
              int ftag = shellmark(parentsh);
              for (std::list<GFace*>::iterator it = f_list.begin();
                   it != f_list.end(); ++it) {
                if ((*it)->tag() == ftag) {
                  gf = *it;
                  break;
                }
              }
              if (gf != NULL) {
                MFaceVertex *v = new MFaceVertex(pointloop[0], pointloop[1],
                                       pointloop[2], gf, 0, 0);
                SPoint2 param;
                if (reparamMeshVertexOnFace(v, gf, param)) {
                  v->setParameter(0, param.x());
                  v->setParameter(1, param.y());
                }
                v->setIndex(pointmark(pointloop));
                _gr->mesh_vertices.push_back(v);
                _vertices.push_back(v);
              }
            }
            // Record all the GFaces' tag at this segment.
            spinsh = parentsh;
            while (1) {
              l_faces.insert(shellmark(spinsh));
              spivotself(spinsh);
              if (spinsh.sh == parentsh.sh) break;
            }
          }
          if ((ge == NULL) && (gf == NULL)) {
            // Create an interior mesh vertex.
            MVertex *v = new MVertex(pointloop[0], pointloop[1], pointloop[2], _gr);
            v->setIndex(pointmark(pointloop));
            _gr->mesh_vertices.push_back(v);
            _vertices.push_back(v);
          }
        } else if (pointtype(pointloop) == FREEFACETVERTEX) {
          sdecode(point2sh(pointloop), parentsh);
          assert(parentsh.sh != NULL);
          l_faces.insert(shellmark(parentsh));
          // Get the GFace containing this vertex.
          GFace *gf = NULL;
          int ftag = shellmark(parentsh);
          for (std::list<GFace*>::iterator it = f_list.begin();
               it != f_list.end(); ++it) {
            if ((*it)->tag() == ftag) {
              gf = *it;
              break;
            }
          }
          if (gf != NULL) {
            MFaceVertex *v = new MFaceVertex(pointloop[0], pointloop[1],
                                         pointloop[2], gf, 0, 0);
            SPoint2 param;
            if (reparamMeshVertexOnFace(v, gf, param)) {
              v->setParameter(0, param.x());
              v->setParameter(1, param.y());
            }
            v->setIndex(pointmark(pointloop));
            _gr->mesh_vertices.push_back(v);
            _vertices.push_back(v);
          } else {
            // Create a mesh vertex.
            MVertex *v = new MVertex(pointloop[0], pointloop[1], pointloop[2], _gr);
            v->setIndex(pointmark(pointloop));
            _gr->mesh_vertices.push_back(v);
            _vertices.push_back(v);
          }
        } else {
          MVertex *v = new MVertex(pointloop[0], pointloop[1], pointloop[2], _gr);
          v->setIndex(pointmark(pointloop));
          _gr->mesh_vertices.push_back(v);
          _vertices.push_back(v);
        }
      }
      pointloop = pointtraverse();
    }
    assert(_vertices.size() == points->items);
  }

  if (l_edges.size() > 0) {
    // There are Steiner points on segments!
    face segloop;
    // Re-create the segment mesh in the corresponding GEdges.
    for (std::set<int>::iterator it=l_edges.begin(); it!=l_edges.end(); ++it) {
      // Find the GFace with tag = *it.
      GEdge *ge = NULL;
      int etag = *it;
      for (std::list<GEdge*>::iterator eit = e_list.begin();
           eit != e_list.end(); ++eit) {
        if ((*eit)->tag() == etag) {
          ge = (*eit);
          break;
        }
      }
      assert(ge != NULL);
      // Delete the old triangles.
      for(i = 0; i < ge->lines.size(); i++)
        delete ge->lines[i];
      ge->lines.clear();
      ge->deleteVertexArrays();
      // Create the new triangles.
      segloop.shver = 0;
      subsegs->traversalinit();
      segloop.sh = shellfacetraverse(subsegs);
      while (segloop.sh != NULL) {
        if (shellmark(segloop) == etag) {
          p[0] = sorg(segloop);
          p[1] = sdest(segloop);
          MVertex *v1 = _vertices[pointmark(p[0])];
          MVertex *v2 = _vertices[pointmark(p[1])];
          MLine *t = new MLine(v1, v2);
          ge->lines.push_back(t);
        }
        segloop.sh = shellfacetraverse(subsegs);
      }
    } // it
  }

  if (l_faces.size() > 0) {
    // There are Steiner points on facets!
    face subloop;
    // Re-create the surface mesh in the corresponding GFaces.
    for (std::set<int>::iterator it=l_faces.begin(); it!=l_faces.end(); ++it) {
      // Find the GFace with tag = *it.
      GFace *gf = NULL;
      int ftag = *it;
      for (std::list<GFace*>::iterator fit = f_list.begin();
           fit != f_list.end(); ++fit) {
        if ((*fit)->tag() == ftag) {
          gf = (*fit);
          break;
        }
      }
      assert(gf != NULL);
      // Delete the old triangles.
      for(i = 0; i < gf->triangles.size(); i++)
        delete gf->triangles[i];
      //for(i = 0; i < gf->quadrangles.size(); i++)
      //  delete gf->quadrangles[i];
      gf->triangles.clear();
      //gf->quadrangles.clear();
      gf->deleteVertexArrays();
      // Create the new triangles.
      subloop.shver = 0;
      subfaces->traversalinit();
      subloop.sh = shellfacetraverse(subfaces);
      while (subloop.sh != NULL) {
        if (shellmark(subloop) == ftag) {
          p[0] = sorg(subloop);
          p[1] = sdest(subloop);
          p[2] = sapex(subloop);
          MVertex *v1 = _vertices[pointmark(p[0])];
          MVertex *v2 = _vertices[pointmark(p[1])];
          MVertex *v3 = _vertices[pointmark(p[2])];
          MTriangle *t = new MTriangle(v1, v2, v3);
          gf->triangles.push_back(t);
        }
        subloop.sh = shellfacetraverse(subfaces);
      }
    } // it
  }

  triface tetloop;

  tetloop.ver = 11;
  tetrahedrons->traversalinit();
  tetloop.tet = tetrahedrontraverse();
  while (tetloop.tet != (tetrahedron *) NULL) {
    p[0] = org(tetloop);
    p[1] = dest(tetloop);
    p[2] = apex(tetloop);
    p[3] = oppo(tetloop);
    MVertex *v1 = _vertices[pointmark(p[0])];
    MVertex *v2 = _vertices[pointmark(p[1])];
    MVertex *v3 = _vertices[pointmark(p[2])];
    MVertex *v4 = _vertices[pointmark(p[3])];
    MTetrahedron *t = new  MTetrahedron(v1, v2, v3, v4);
    _gr->tetrahedra.push_back(t);
    tetloop.tet = tetrahedrontraverse();
  }
} // mesh output
}

void terminateBoundaryRecovery(void *, int exitcode)
{
  throw exitcode;
}
