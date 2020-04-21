// Hxt - Copyright (C) 
// 2016 - 2020 UCLouvain
//
// See the LICENSE.txt file for license information.
//
// Contributor(s):
//   Célestin Marot

#ifndef HXT_TETPARTITION_H
#define HXT_TETPARTITION_H

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


static inline int computeNumberOfThreads(double conflictRatio, int numThreads, uint64_t numElem, uint64_t smallestPass)
{
  const double maxBorders = 8.0;
  if(conflictRatio > (numThreads - 1) * maxBorders / ( numThreads * (maxBorders + 1) - 2.) ) {
    numThreads = (numThreads + 1) / 2;
  }

  int maxThreadsInRound = 1;
  {
    uint32_t tmp = numElem/smallestPass;
    while(tmp>1 && maxThreadsInRound < numThreads){
      tmp = tmp/2;
      maxThreadsInRound*=2;
    }
  }

  if(maxThreadsInRound < numThreads)
    return maxThreadsInRound;

  return numThreads;
}


// HXTStatus hxtComputePartitions(HXTPartition* partitions[], int nThreads, uint64_t* hilbertDist, uint64_t n);


#ifdef __cplusplus
}
#endif

#endif
