// Hxt - Copyright (C) 
// 2016 - 2020 UCLouvain
//
// See the LICENSE.txt file for license information.
//
// Contributor(s):
//   Célestin Marot

#include "hxt_tetSync.h"
#include "hxt_tetFlag.h"
#include "hxt_tools.h"

HXTStatus synchronizeReallocation(HXT2Sync* shared,
                                  int* threadFinishedLocal) {
  // threads cant be doing something while the realloc portion happen
  #pragma omp barrier
  
  // threadFinishedGlobal value changes constantly
  // we cannot know it's value at the time of the reallocation except here.
  // threadFinishedLocal (here in argument) will receive the precise value of threadFinishedGlobal.
  if(threadFinishedLocal!=NULL){
    *threadFinishedLocal = shared->threadFinished;
  }

  HXTStatus status = HXT_STATUS_OK;
  // make reallocations in a critical section
  #pragma omp single
  {
    HXTMesh* mesh = shared->mesh;
    uint64_t ntet = mesh->tetrahedra.num;
    if(ntet > mesh->tetrahedra.size){
      uint64_t size = ntet + (mesh->tetrahedra.size*shared->allocMore/8);

      HXT_ASSERT(size >= ntet); // possible overflow here ^

      status = hxtTetrahedraReserve(mesh, size);

      for (unsigned i=0; status==HXT_STATUS_OK && i<4; i++) {
        if(shared->otherArrays[i]!=NULL) {
          status = hxtAlignedRealloc(shared->otherArrays[i],
                                     shared->otherArraysElementSize[i]*size);
        }
      }
    }
  } // implicit barrier here

  if(status!=HXT_STATUS_OK)
    HXT_TRACE(status);
  
  return status;
}


// We wait in this loop to avoid blocking reallocation
// Indeed, all threads must reach the barrier in the reallocation.
// thus a thread cannot finish if there is a possible reallocation.
HXTStatus waitForPossibleReallocation(HXT2Sync* shared,
                                      int numThreads)
{
  #pragma omp atomic update
    shared->threadFinished++;

  int val = 0;
  do{
    // threads are waiting here for another thread's reallocation
    // untill all threads finished
    HXT_CHECK( synchronizeReallocation(shared, &val) );
  }while(val < numThreads);
  return HXT_STATUS_OK;
}


HXTStatus createNewDeleted(HXT2Sync* shared,
                           HXTDeleted* deleted,
                           uint64_t demand) {
  uint64_t needed = MAX(DELETED_BUFFER_SIZE, demand) - deleted->num;

  HXTMesh* mesh = shared->mesh;
  uint64_t ntet;

  // when multi-threading: atomic operation and critical sections
  #pragma omp atomic capture
  { ntet = mesh->tetrahedra.num; mesh->tetrahedra.num+=needed;}

  if(ntet + needed > mesh->tetrahedra.size) {
    HXT_CHECK( synchronizeReallocation(shared, NULL) );
  }
  HXT_CHECK( askForDeleted(deleted, needed) );

  #pragma omp simd
  for (uint64_t i=0; i<needed; i++){
    deleted->array[deleted->num+i] = ntet+i;
    mesh->tetrahedra.flag[ntet+i] = 0;
    setDeletedFlag(mesh, ntet+i);
  }

  for (int i=0; i<4; i++) {
    if(shared->otherArrays[i]!=NULL && shared->otherArraysSetDeleted[i]!=NULL) {
      shared->otherArraysSetDeleted[i](shared->otherArrays[i], ntet, ntet+needed);
    }
  }

  deleted->createdNew = 1;
  deleted->num += needed;
  return HXT_STATUS_OK;
}