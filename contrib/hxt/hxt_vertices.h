#ifndef _HEXTREME_VERTICES_
#define _HEXTREME_VERTICES_

#include "hxt_mesh.h"
#include "hxt_bbox.h"

typedef struct hxtVertexStruct{
  double coord[3];
  union {
    uint64_t hilbertDist;
    uint32_t index;
    HXTStatus status;
  } padding;
} hxtVertex;

typedef struct hxtNodeInfoStruct{
  uint64_t hilbertDist;
  uint32_t node;
  HXTStatus status; // is the vertex inserted ? true, false or try_again
} hxtNodeInfo;

uint32_t hxtAdvisedHilbertBits(const uint32_t n);
uint32_t hxtAdvancedHilbertBits(const uint32_t nInitial, const uint32_t nToSort, const uint32_t nPartitions, const uint32_t maxPartitions);

/* compute the hilbert distance of each vertex in vertex.dist 
 * @in bbox: the bounding box countaining the min and max values
 * @in vertices: an array of vertices corresponding to the bbox
 * @in n: the number of vertices
 * @in nbits: hint on the number of bits on which the hilbert distance must be computed
 *            use 0 if you want the function to find a good number of bits for you
 * @out nbits: the real number of bits on which the hilbert distance was computed
 */
HXTStatus hxtVerticesHilbertDist(hxtBbox* bbox, hxtVertex* vertices, const uint32_t n, uint32_t* nbits, const double shift[3]);


/* sort all vertex using their dist value using a parallel radix sort with multiple pass 
 * for the sort to be done properly, nbits>=(nbr. of bits in vertices[i].dist) for all i<n
 */
HXTStatus hxtVerticesSort(hxtVertex* const vertices, const uint32_t n, uint32_t nbits);
HXTStatus hxtNodeInfoSort(hxtNodeInfo* const array, const uint32_t n, uint32_t nbits);

HXTStatus hxtVerticesShuffle(hxtVertex* const vertices, const uint32_t n);
HXTStatus hxtNodeInfoShuffle(hxtNodeInfo* const array, const uint32_t n);

#endif
