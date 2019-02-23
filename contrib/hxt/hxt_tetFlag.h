#ifndef _HXT_TETFLAG_
#define _HXT_TETFLAG_

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
  set to HXT_NO_ADJACENT nevertheless */
HXTStatus hxtGetLines2TetMap(HXTMesh* mesh, uint64_t* lines2TetMap, uint64_t* nbMissing);


/* Constrain facets of tetrahedra (set the right tetrahedra.flag)
 * that corresponding to a triangle.
 * tri2TetMap is the array that comes from hxtGetTri2TetMap() */
HXTStatus hxtConstrainTriangles(HXTMesh* mesh, uint64_t* tri2TetMap);

/* Constrain edges of tetrahedra (set the right tetrahedra.flag)
 * that corresponding to a line that isn't in any triangle.
 * lines2TetMap is the array that comes from hxtGetLines2TetMap()
 * lines2TriMap is the array that comes from hxtGetLines2TriMap() */
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
 *  0  edge between facet 0 and facet 1 is constrained
 *  1  edge betwwen facet 0 and facet 2 is constrained
 *  2  edge betwwen facet 0 and facet 3 is constrained
 *  3  edge betwwen facet 1 and facet 2 is constrained
 *  4  edge betwwen facet 1 and facet 3 is constrained
 *  5  edge between facet 2 and facet 3 is constrained
 *  6  the tetrahedron is deleted
 *  7  the tetrahedron has already been processed (a vertex was already inserted inside it and it failed)
 *  8  facet 0 is constrained
 *  9  facet 1 is constrained
 *  10 facet 2 is constrained
 *  11 facet 3 is constrained
 *  12 -unused-
 *  13 -unused-
 *  14 -unused-
 *  15 -unused-
 */


/***************************
 * combined operations
 ***************************/

static inline uint16_t isAnyEdgeConstrained(HXTMesh* mesh, uint64_t tet) {
  return mesh->tetrahedra.flag[tet] & UINT16_C(0x3F);
}

static inline uint16_t isAnyFacetConstrained(HXTMesh* mesh, uint64_t tet) {
  return mesh->tetrahedra.flag[tet] & UINT16_C(0xF00);
}

static inline uint16_t isAnyThingConstrained(HXTMesh* mesh, uint64_t tet) {
  return mesh->tetrahedra.flag[tet] & UINT16_C(0xF3F);
}


/***************************
 * edges operations
 ***************************/
static inline int getEdgeFromFacets(unsigned facet1, unsigned facet2) {
  static const int facets2EdgeNum[4][4] = {{-1, 0, 1, 2},
                                           { 0,-1, 3, 4},
                                           { 1, 3,-1, 5},
                                           { 2, 4, 5,-1}};
  return facets2EdgeNum[facet1][facet2];
}

static inline void getFacetsFromEdge(int edgeNum, unsigned* facetMin, unsigned* facetMax) {
  static const unsigned edgeNum2FacetMin[6] = { 0, 0, 0, 1, 1, 2};
  static const unsigned edgeNum2FacetMax[6] = { 1, 2, 3, 2, 3, 3};
  *facetMin = edgeNum2FacetMin[edgeNum];
  *facetMax = edgeNum2FacetMax[edgeNum];
}

static inline void getNodesFromEdge(int edgeNum, unsigned* nodeMin, unsigned* nodeMax) {
  getFacetsFromEdge(5-edgeNum, nodeMin, nodeMax);
}

static inline uint16_t getEdgeConstraint(HXTMesh* mesh, uint64_t tet, int edgeNum) {
  return mesh->tetrahedra.flag[tet] & (1U<<edgeNum);
}

static inline void setEdgeConstraint(HXTMesh* mesh, uint64_t tet, int edgeNum) {
  mesh->tetrahedra.flag[tet] |= (1U<<edgeNum);
}

static inline void unsetEdgeConstraint(HXTMesh* mesh, uint64_t tet, int edgeNum) {
  mesh->tetrahedra.flag[tet] &= ~(1U<<edgeNum);
}


/***************************
 * facets operations
 ***************************/
static inline unsigned getNode0FromFacet(unsigned facet) {
  return (facet+1)&3;
}

static inline unsigned getNode1FromFacet(unsigned facet) {
  return (facet+3)&2;
}

static inline unsigned getNode2FromFacet(unsigned facet) {
  return (facet&2)^3;
}

static inline uint16_t getFacetConstraint(HXTMesh* mesh, uint64_t tet, unsigned facet) {
  return mesh->tetrahedra.flag[tet] & (1U<<(facet+8));
}

static inline void setFacetConstraint(HXTMesh* mesh, uint64_t tet, unsigned facet) {
  mesh->tetrahedra.flag[tet] |= (1U<<(facet+8));
}

static inline void unsetFacetConstraint(HXTMesh* mesh, uint64_t tet, unsigned facet) {
  mesh->tetrahedra.flag[tet] &= ~(1U<<(facet+8));
}


/***************************
 * deleted flag operations
 ***************************/
static inline uint16_t getDeletedFlag(HXTMesh* mesh, uint64_t tet) {
  return mesh->tetrahedra.flag[tet] & UINT16_C(0x40);
}

static inline void setDeletedFlag(HXTMesh* mesh, uint64_t tet) {
  mesh->tetrahedra.flag[tet] |= UINT16_C(0x40);
}

static inline void unsetDeletedFlag(HXTMesh* mesh, uint64_t tet) {
  mesh->tetrahedra.flag[tet] &= ~UINT16_C(0x40);
}


/***************************
 * processed flag operations
 ***************************/
static inline uint16_t getProcessedFlag(HXTMesh* mesh, uint64_t tet) {
  return mesh->tetrahedra.flag[tet] & UINT16_C(0x80);
}

static inline void setProcessedFlag(HXTMesh* mesh, uint64_t tet) {
  mesh->tetrahedra.flag[tet] |= UINT16_C(0x80);
}


static inline void unsetProcessedFlag(HXTMesh* mesh, uint64_t tet) {
  mesh->tetrahedra.flag[tet] &= ~UINT16_C(0x80);
}


#ifdef __cplusplus
}
#endif

#endif
