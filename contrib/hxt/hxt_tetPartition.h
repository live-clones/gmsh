#ifndef _HXT_TETPARTITION_
#define _HXT_TETPARTITION_

#ifdef __cplusplus
extern "C" {
#endif


#include "hxt_vertices.h"

typedef struct {
    uint64_t startDist;
    uint64_t lengthDist;
    uint64_t firstElem;
    uint64_t numElem;
} HXTPartition;


/* simple utility function to tell if a vertex is inside a partition,
 * given the partition start and it's length 'rel'
 * !!! Does not work with ghost vertex !!! */
static inline int vertexOutOfPartition(HXTVertex* vertices, uint32_t v, uint64_t lengthDist, uint64_t startDist) {
  // unsigned wrap around is defined by the standard
  return vertices[v].padding.hilbertDist - startDist >= lengthDist;
}


// HXTStatus hxtComputePartitions(HXTPartition* partitions[], int nThreads, uint64_t* hilbertDist, uint64_t n);


#ifdef __cplusplus
}
#endif

#endif
