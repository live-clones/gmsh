#ifndef _HXT_TETFLAG_
#define _HXT_TETFLAG_

#ifdef __cplusplus
extern "C" {
#endif

#include "hxt_mesh.h"

// Verify if all facets are present in a tetrahedrization, missing is the number of missing facets
// it then set tetrahedra.flag to account for the contrains on the facets
HXTStatus hxtConstrainTriangles(HXTMesh* mesh, uint64_t* missing);
HXTStatus hxtConstrainEdgesNotInTriangles(HXTMesh* mesh, uint64_t* missing);


/* flag is a 16-bit number
 *
 *  0  facet 0 is contrained
 *  1  edge between facet 0 and facet 1 is contrained
 *  2  edge betwwen facet 0 and facet 2 is contrained
 *  3  edge betwwen facet 0 and facet 3 is contrained
 *  4  facet 1 is contrained
 *  5  
 *  6  edge betwwen facet 1 and facet 2 is contrained
 *  7  edge betwwen facet 1 and facet 3 is contrained
 *  8  facet 2 is contrained
 *  9 
 *  10 
 *  11 edge between facet 2 and facet 3 is contrained
 *  12 facet 3 is contrained
 *  13
 *  14 the tetrahedron has already been processed (a vertex was already inserted inside it and if failed)
 *  15 the tetrahedron is deleted
 */


static inline uint16_t isAnyEdgeConstrained(HXTMesh* mesh, uint64_t tet) {
  return mesh->tetrahedra.flag[tet] & UINT16_C(0x8CE);
}

static inline uint16_t isAnyEdgeOfFacetConstrained(HXTMesh* mesh, uint64_t facet) {
  static uint16_t mask[4] = {0xE, 0xC2, 0x844, 0x888};
  return mesh->tetrahedra.flag[facet/4] & mask[facet%4];
}

// static inline uint16_t isAnyThingConstrained(HXTMesh* mesh, uint64_t tet) {
//   return mesh->tetrahedra.flag[tet] & 0x19DF;
// }

static inline uint16_t isAnyFacetConstrained(HXTMesh* mesh, uint64_t tet) {
  return mesh->tetrahedra.flag[tet] & UINT16_C(0x1111);
}

static inline uint16_t isEdgeConstrained(HXTMesh* mesh, uint64_t tet, unsigned facetmin, unsigned facetmax) {
  return mesh->tetrahedra.flag[tet] & (1U<<(facetmin*4+facetmax));
}

static inline uint16_t isEdgeConstrainedSafe(HXTMesh* mesh, uint64_t tet, unsigned facet1, unsigned facet2) {
  return mesh->tetrahedra.flag[tet] & (1U<<(facet1<facet2?facet1*4+facet2:facet2*4+facet1));
}

static inline void constrainEdge(HXTMesh* mesh, uint64_t tet, unsigned facetmin, unsigned facetmax) {
  mesh->tetrahedra.flag[tet] |= (1U<<(facetmin*4+facetmax));
}

static inline void unconstrainEdge(HXTMesh* mesh, uint64_t tet, unsigned facetmin, unsigned facetmax) {
  mesh->tetrahedra.flag[tet] &= ~(1U<<(facetmin*4+facetmax));
}

// here facet = 4*tet + facett
static inline uint16_t isFacetConstrained(HXTMesh* mesh, uint64_t facet) {
  return mesh->tetrahedra.flag[facet/4] & (1U<<(facet%4*4));
}

static inline void constrainFacet(HXTMesh* mesh, uint64_t facet) {
  mesh->tetrahedra.flag[facet/4] |= (1U<<(facet%4*4));
}

static inline uint16_t isTetDeleted(HXTMesh* mesh, uint64_t tet) {
  return mesh->tetrahedra.flag[tet] & (1U<<15);
}

static inline void markTetAsDeleted(HXTMesh* mesh, uint64_t tet) {
  mesh->tetrahedra.flag[tet] |= (1U<<15);
}

static inline void unmarkTetAsDeleted(HXTMesh* mesh, uint64_t tet) {
  mesh->tetrahedra.flag[tet] &= ~(1U<<15);
}

static inline uint16_t isTetProcessed(HXTMesh* mesh, uint64_t tet) {
  return mesh->tetrahedra.flag[tet] & (1U<<14);
}

static inline void markTetAsProcessed(HXTMesh* mesh, uint64_t tet) {
  mesh->tetrahedra.flag[tet] |= (1U<<14);
}


static inline void unmarkTetAsProcessed(HXTMesh* mesh, uint64_t tet) {
  mesh->tetrahedra.flag[tet] &= ~(1U<<14);
}


#ifdef __cplusplus
}
#endif

#endif
