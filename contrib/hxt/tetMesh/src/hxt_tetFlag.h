// Hxt - Copyright (C)
// 2016 - 2020 UCLouvain
//
// See the LICENSE.txt file for license information.
//
// Contributor(s):
//   Célestin Marot

#ifndef HXT_TETFLAG_H
#define HXT_TETFLAG_H

#ifdef __cplusplus
extern "C" {
#endif

#include "hxt_mesh.h"

/* Get a mapping between triangles and tetrahedra
 * tri2TetMap must be an array of size: `mesh->triangles.num`
 *
 * if *nbMissing = 0 at the end of function:
 *    `tri2TetMap[i] = 4*tet+face | HXT_NO_ADJACENT` , where `4*tet+face`
 *    is a facet of tetrahedron `tet` that correspond
 *    to the triangle `i` in mesh->triangles.
 *    If there is no such tetrahedron (happens only if nbMissing!=0),
 *    it is set to HXT_NO_ADJACENT.
 *
 *    The tetrahedron on the other side is easily obtainable by doing
 *    `mesh->tetrahedra.neigh[tri2TetMap[i]]`
 */
HXTStatus hxtGetTri2TetMap(HXTMesh* mesh, uint64_t* tri2TetMap, uint64_t* nbMissing);

/* Same as above with lines and triangles: `lines2TriMap = 3*tri+edge | HXT_NO_ADJACENT`
  (edge is 0,1 or 2, and it correspond to the nodes 0-1, 1-2 and 2-0 of the triangles)
  Lines that begin and ends at the same point are not reported in nbMissing, but the mapping is
  set to HXT_NO_ADJACENT nevertheless */
HXTStatus hxtGetLines2TriMap(HXTMesh* mesh, uint64_t* lines2TriMap, uint64_t* nbMissing);

/* Same as above with lines and tets: `lines2TetMap = 6*tet+edge | HXT_NO_ADJACENT`
 (edge is a number between 0 & 5, explained below in "ANATOMY OF A TET.")
   Lines that begin and ends at the same point are not reported in nbMissing, but the mapping is
  set to HXT_NO_ADJACENT nevertheless

  !! DOES NOT WORK IF A TETRAHEDRON HAS NO NEIGHBOR !!
  => HXT_NO_ADJACENT not permitted: add ghost tetrahedra */
HXTStatus hxtGetLines2TetMap(HXTMesh* mesh, uint64_t* lines2TetMap, uint64_t* nbMissing);


/* Constrain facets of tetrahedra (set the right tetrahedra.flag)
 * that corresponding to a triangle.
 * tri2TetMap is the array that comes from hxtGetTri2TetMap() */
HXTStatus hxtConstrainTriangles(HXTMesh* mesh, uint64_t* tri2TetMap);


/*
 *   Constrain an edge in all tetrahedra surrounding it
 *
 * In single-thread cases, put edgeFlag==NULL.
 * This function will directly set the contraint bit corresponding to the edge
 * '6*firstTet+edge' on all tetrahedra surrounding this edge.
 *
 * In multi-threaded case, if multiple thread modify different edges of the
 * same tetrahedra, modifying the same flag would resuld in a race condition.
 * Therefore, in parallel section, you must give an array with a char per edge.
 * This function will set the edges corresponding to '6*firstTet+edge' to 1.
 *
  !! DOES NOT WORK IF A TETRAHEDRON HAS NO NEIGHBOR !!
  => HXT_NO_ADJACENT not permitted: add ghost tetrahedra */
HXTStatus hxtConstrainLine(HXTMesh* mesh, uint64_t tet, int edge, char* edgeFlag);

/* Constrain edges of tetrahedra (set the right tetrahedra.flag)
 * that corresponding to a line that isn't in any triangle.
 * lines2TetMap is the array that comes from hxtGetLines2TetMap()
 * lines2TriMap is the array that comes from hxtGetLines2TriMap()

  !! DOES NOT WORK IF A TETRAHEDRON HAS NO NEIGHBOR !!
  => HXT_NO_ADJACENT not permitted: add ghost tetrahedra */
HXTStatus hxtConstrainLinesNotInTriangles(HXTMesh* mesh, uint64_t* lines2TetMap, uint64_t* lines2TriMap);


/*****************************
 *  ANATOMY OF A TERAHEDRON  *
 *****************************

      node
       0
       |\`-_
       | \  `-_                   facet
       |  \    `-_                 1
       |   \      `2_              |
       |    0        `-_          /
       |     \   facet  `-_   <--'
       |      \    2       `-_
       1       \              `-_
       | facet  node_____4_______=> node
       |   3    /1              _-'  3
       |       /             _-'
       |      /  facet    _-'
       |     /    0    _-'
       |    3       _5'
       |   /     _-'
       |  /   _-'
       | / _-'
       |/-'
      node
       2

  orient3d(p_0, p_1, p_2, p_3) < 0 !!
  => orient3d gives the opposite of 6x the volume of a tetrahedron
  (maybe counter intuitive but standard)

  odd permutations gives a positive result and even permutations a negative result
  => orient3d(p_3, p0, p_1, p_2) > 0


  facets `i` is the facet that does not contain node `i`
  edge 0 contain node 0 & 1
  edge 1 contain node 0 & 2
  edge 2 contain node 0 & 3
  edge 3 contain node 1 & 2
  edge 4 contain node 1 & 3
  edge 5 contain node 2 & 3

  - - - - - - - - - - - - - - - - - - - - - - - - - - -

 ********************************
 *  mesh->tetrahedra.flag[tet]  *
 ********************************
 *  flag is a 16-bit number
 *
 *  0X1    | 0  edge between facet 0 and facet 1 is constrained, node 2-3
 *  0X2    | 1  edge betwwen facet 0 and facet 2 is constrained, node 1-3
 *  0X4    | 2  edge betwwen facet 0 and facet 3 is constrained, node 1-2
 *  0X8    | 3  edge betwwen facet 1 and facet 2 is constrained, node 0-3
 *  0X10   | 4  edge betwwen facet 1 and facet 3 is constrained, node 0-2
 *  0X20   | 5  edge between facet 2 and facet 3 is constrained, node 0-1
 *  0X40   | 6  the tetrahedron is deleted
 *  0X80   | 7  the tetrahedron has already been processed (a vertex was already inserted inside it and it failed)
 *  0X100  | 8  facet 0 is constrained
 *  0X200  | 9  facet 1 is constrained
 *  0X400  | 10 facet 2 is constrained
 *  0X800  | 11 facet 3 is constrained
 *  0X1000 | 12 unused 0
 *  0X2000 | 13 unused 1
 *  0X4000 | 14 unused 2
 *  0X8000 | 15 unused 3
 */
#define HXT_EDGE0_MASK UINT16_C(0x1)
#define HXT_EDGE1_MASK UINT16_C(0x2)
#define HXT_EDGE2_MASK UINT16_C(0x4)
#define HXT_EDGE3_MASK UINT16_C(0x8)
#define HXT_EDGE4_MASK UINT16_C(0x10)
#define HXT_EDGE5_MASK UINT16_C(0x20)
#define HXT_ALL_EDGES_MASK (HXT_EDGE0_MASK | \
                            HXT_EDGE1_MASK | \
                            HXT_EDGE2_MASK | \
                            HXT_EDGE3_MASK | \
                            HXT_EDGE4_MASK | \
                            HXT_EDGE5_MASK)

#define HXT_FACET0_MASK UINT16_C(0x100)
#define HXT_FACET1_MASK UINT16_C(0x200)
#define HXT_FACET2_MASK UINT16_C(0x400)
#define HXT_FACET3_MASK UINT16_C(0x800)
#define HXT_ALL_FACETS_MASK (HXT_FACET0_MASK | \
                             HXT_FACET1_MASK | \
                             HXT_FACET2_MASK | \
                             HXT_FACET3_MASK)

#define HXT_ALL_CONSTRAINTS_MASK UINT16_C(0xF3F)

#define HXT_DELETED_MASK UINT16_C(0x40)
#define HXT_PROCESSED_MASK UINT16_C(0X80)

#define HXT_UNUSED0_MASK UINT16_C(0x1000)
#define HXT_UNUSED1_MASK UINT16_C(0x2000)
#define HXT_UNUSED2_MASK UINT16_C(0x4000)
#define HXT_UNUSED3_MASK UINT16_C(0x8000)
#define HXT_ALL_UNUSED_MASK UINT16_C(0xF000)


/***************************
 * combined operations
 ***************************/

static inline uint16_t isAnyEdgeConstrained(HXTMesh* mesh, uint64_t tet) {
  return mesh->tetrahedra.flag[tet] & HXT_ALL_EDGES_MASK;
}

static inline uint16_t isAnyFacetConstrained(HXTMesh* mesh, uint64_t tet) {
  return mesh->tetrahedra.flag[tet] & HXT_ALL_FACETS_MASK;
}

static inline uint16_t isAnyThingConstrained(HXTMesh* mesh, uint64_t tet) {
  return mesh->tetrahedra.flag[tet] & HXT_ALL_CONSTRAINTS_MASK;
}


/***************************
 * edges operations
 ***************************/
static inline int getEdgeFromFacets(unsigned facet1, unsigned facet2) {
  HXT_ASSERT(facet1!=facet2);
  HXT_ASSERT(facet1<4 && facet2<4);

  static const int facets2EdgeNum[4][4] = {{-1, 0, 1, 2},
                                           { 0,-1, 3, 4},
                                           { 1, 3,-1, 5},
                                           { 2, 4, 5,-1}};
  return facets2EdgeNum[facet1][facet2];
}

static inline int getEdgeFromNodes(unsigned node0, unsigned node1) {
  return 5-getEdgeFromFacets(node0, node1);
}

static inline void getFacetsFromEdge(int edgeNum, unsigned* facetMin, unsigned* facetMax) {
  HXT_ASSERT(edgeNum<6);

  static const unsigned edgeNum2FacetMin[6] = { 0, 0, 0, 1, 1, 2};
  static const unsigned edgeNum2FacetMax[6] = { 1, 2, 3, 2, 3, 3};
  *facetMin = edgeNum2FacetMin[edgeNum];
  *facetMax = edgeNum2FacetMax[edgeNum];
}

static inline void getNodesFromEdge(int edgeNum, unsigned* nodeMin, unsigned* nodeMax) {
  getFacetsFromEdge(5-edgeNum, nodeMin, nodeMax);
}

static inline uint16_t getEdgeConstraint(HXTMesh* mesh, uint64_t tet, int edgeNum) {
  return mesh->tetrahedra.flag[tet] & (UINT16_C(1)<<edgeNum);
}

static inline void setEdgeConstraint(HXTMesh* mesh, uint64_t tet, int edgeNum) {
  mesh->tetrahedra.flag[tet] |= (UINT16_C(1)<<edgeNum);
}

static inline void unsetEdgeConstraint(HXTMesh* mesh, uint64_t tet, int edgeNum) {
  mesh->tetrahedra.flag[tet] &= ~(UINT16_C(1)<<edgeNum);
}


/***************************
 * facets operations
 ***************************/

/*
 gives the index of the nodes of a facet
 given in counter-clockwise order, as seen from the opposite vertex

 double* a = mesh->vertices.coord + 4*mesh->tetrahedra.node[4*tet+getNode0FromFacet(f)];
 double* b = mesh->vertices.coord + 4*mesh->tetrahedra.node[4*tet+getNode1FromFacet(f)];
 double* c = mesh->vertices.coord + 4*mesh->tetrahedra.node[4*tet+getNode2FromFacet(f)];
 double* d = mesh->vertices.coord + 4*mesh->tetrahedra.node[4*tet+f];

 => orient3d(a,b,c,d) < 0 for all f
 in other words, {getNode0FromFacet(f),getNode1FromFacet(f),getNode2FromFacet(f)),f}
 all are even permutations of {0,1,2,3}
*/
static inline unsigned getNode0FromFacet(unsigned facet) {
  return (facet+1)&3;
}

static inline unsigned getNode1FromFacet(unsigned facet) {
  return (facet&2)^3;
}

static inline unsigned getNode2FromFacet(unsigned facet) {
  return (facet+3)&2;
}

static inline void getOtherFacetFrom1(unsigned facet,
                                      unsigned *facet1,
                                      unsigned *facet2,
                                      unsigned *facet3) {
  *facet1 = (facet+1)&3;
  *facet2 = (facet+2)&3;
  *facet3 = (facet+3)&3;
}

// the two facet define an oriented edge (see hxt_edgeRemoval.c to see how
// they are defined)
static inline void getOtherFacetFrom2(unsigned in_facet, unsigned out_facet,
                                      unsigned *up_facet, unsigned *down_facet) {
  static const unsigned UP_FACET[4][4] = {{ 0, 2, 3, 1},
                                          { 3, 0, 0, 2},
                                          { 1, 3, 0, 0},
                                          { 2, 0, 1, 0}};
  *up_facet = UP_FACET[in_facet][out_facet];
  *down_facet = UP_FACET[out_facet][in_facet];
}


static inline uint16_t getFacetConstraint(HXTMesh* mesh, uint64_t tet, unsigned facet) {
  return mesh->tetrahedra.flag[tet] & (UINT16_C(1)<<(facet+8));
}

static inline void setFacetConstraint(HXTMesh* mesh, uint64_t tet, unsigned facet) {
  mesh->tetrahedra.flag[tet] |= (UINT16_C(1)<<(facet+8));
}

static inline void unsetFacetConstraint(HXTMesh* mesh, uint64_t tet, unsigned facet) {
  mesh->tetrahedra.flag[tet] &= ~(UINT16_C(1)<<(facet+8));
}


/***************************
 * deleted flag operations
 ***************************/
static inline uint16_t getDeletedFlag(HXTMesh* mesh, uint64_t tet) {
  return mesh->tetrahedra.flag[tet] & HXT_DELETED_MASK;
}

static inline void setDeletedFlag(HXTMesh* mesh, uint64_t tet) {
  mesh->tetrahedra.flag[tet] |= HXT_DELETED_MASK;
}

static inline void unsetDeletedFlag(HXTMesh* mesh, uint64_t tet) {
  mesh->tetrahedra.flag[tet] &= ~HXT_DELETED_MASK;
}


/***************************
 * processed flag operations
 ***************************/
static inline uint16_t getProcessedFlag(HXTMesh* mesh, uint64_t tet) {
  return mesh->tetrahedra.flag[tet] & HXT_PROCESSED_MASK;
}

static inline void setProcessedFlag(HXTMesh* mesh, uint64_t tet) {
  mesh->tetrahedra.flag[tet] |= HXT_PROCESSED_MASK;
}


static inline void unsetProcessedFlag(HXTMesh* mesh, uint64_t tet) {
  mesh->tetrahedra.flag[tet] &= ~HXT_PROCESSED_MASK;
}


/***************************
 * unused flags operations
 ***************************/
static inline uint16_t getUnusedFlag(HXTMesh* mesh, uint64_t tet, unsigned id) {
  HXT_ASSERT(id<4);
  return mesh->tetrahedra.flag[tet] & (UINT16_C(0x1000)<<id);
}

static inline void setUnusedFlag(HXTMesh* mesh, uint64_t tet, unsigned id) {
  HXT_ASSERT(id<4);
  mesh->tetrahedra.flag[tet] |= (UINT16_C(0x1000)<<id);
}

static inline void unsetUnusedFlag(HXTMesh* mesh, uint64_t tet, unsigned id) {
  HXT_ASSERT(id<4);
  mesh->tetrahedra.flag[tet] &= ~(UINT16_C(0x1000)<<id);
}


static inline void resetUnusedFlags(HXTMesh* mesh, uint64_t tet) {
  mesh->tetrahedra.flag[tet] &= ~(HXT_ALL_UNUSED_MASK);
}


#ifdef __cplusplus
}
#endif

#endif
