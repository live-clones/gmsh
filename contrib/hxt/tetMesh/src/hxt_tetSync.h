// Hxt - Copyright (C) 
// 2016 - 2020 UCLouvain
//
// See the LICENSE.txt file for license information.
//
// Contributor(s):
//   Célestin Marot

#ifndef HXT_TETSYNC_H
#define HXT_TETSYNC_H

#ifdef __cplusplus
extern "C" {
#endif

#include "hxt_tetUtils.h"

#define DELETED_BUFFER_SIZE 8182

/* Structure allowing to share tetrahedra data between threads
 * If there are additional data per tetrahedron
 * it is possible to fill `otherArrays` accordingly
 *
 * this structure must be shared between all threads
 * thread FinishedGlobal will contain the number of threads
 * that finished it every thread correctly call
 * waitForPossibleReallocation() at the end  */
typedef struct {
	HXTMesh* mesh; // we will sync every array in tetrahedra


  // 0: reallocate what's needed
  // x: reallocate what's needed + x/8 of the size
  // x<=0 not allowed
  // => x should generally be between 0 and 8...
  int allocMore;

	void** otherArrays[4]; // all NULL if no other array to sync
  size_t otherArraysElementSize[4];

  // function that will initialize otherArray to default value on [a,b[
  void (*otherArraysSetDeleted[4])(void** ar_ptr, uint64_t a, uint64_t b);
  int threadFinished; // must be initialized to zero at beginning !!!
} HXT2Sync;


/* Simple vector of deleted tets */
typedef struct {
	uint64_t* array;
	uint64_t num;
	uint64_t size;
  int createdNew; // just a flag that tells if createNewDeleted was called
} HXTDeleted;


/**************************************************************************
                    re-allocation functions
 **************************************************************************/
HXTStatus waitForPossibleReallocation(HXT2Sync* shared,
                                      int numThreads);

HXTStatus createNewDeleted(HXT2Sync* shared,
                           HXTDeleted* deleted,
                           uint64_t demand);


static inline HXTStatus askForDeleted(HXTDeleted* deleted, uint64_t needed) {
  needed += deleted->num;
  if(needed>deleted->size) {
    HXT_CHECK( hxtAlignedRealloc(&deleted->array, sizeof(uint64_t)*2*needed) );
    deleted->size = 2*needed;
  }
  return HXT_STATUS_OK;
}

#ifdef __cplusplus
}
#endif

#endif
