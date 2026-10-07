/**
 * @file dlmset_headers.h
 * @brief MSet function prototypes. An MSet, or multi-set, is an iset which
 * stores a large range of elements in a shared ptr array between threads.
 * However, each thread has its own set (and items cannot be in multiple sets).
 *
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright (c) 2013-2015, Dominique LaSalle
 * @version 1
 * @date 2013-10-05
 */


/* prefixing ugliness */
#define DLMSET_PRE2(prefix,suffix) prefix ## _ ## suffix
#define DLMSET_PRE1(prefix,suffix) DLMSET_PRE2(prefix,suffix)
#define DLMSET_PUB(name) DLMSET_PRE1(DLMSET_PREFIX,name)
#define DLMSET_PRI(name) DLMSET_PRE1(_,DLMSET_PRE1(DLMSET_PREFIX,name))




#include "dlthread.h"




/******************************************************************************
* TYPES ***********************************************************************
******************************************************************************/


typedef struct DLMSET_PRI(mset_info_t) {
  size_t size;
  DLMSET_TYPE_T * ind;
  /* ensure the structure is 64 bytes to avoid false sharing */
  char _padding[CACHE_LINE_SIZE - (sizeof(size_t)+sizeof(DLMSET_TYPE_T*))];
} DLMSET_PRI(mset_info_t);
DL_STATIC_ASSERT(sizeof(DLMSET_PRI(mset_info_t)) == CACHE_LINE_SIZE);


typedef struct DLMSET_PUB(mset_t) {
  DLMSET_TYPE_T min;
  DLMSET_TYPE_T max;
  DLMSET_PRI(mset_info_t) * info;
  DLMSET_TYPE_T * __DL_RESTRICT ptr;
  dlthread_comm_t comm;
} DLMSET_PUB(mset_t);




#ifndef DLMSET_STATIC


/******************************************************************************
* FUNCTION PROTOTYPES *********************************************************
******************************************************************************/


/**
 * @brief Allocate and initialize an MSet with a minimum and maximum element
 * value. The minimum and maximum are only used from the thread with id 0. 
 *
 * @param min The minimum element (inclusive).
 * @param max The maximum element (exclusive).
 * @param size The maximum number of elements this thread will have in the set. 
 * @param comm The thread communicator.
 *
 * @return The MSet.
 */
DLMSET_PUB(mset_t) * DLMSET_PUB(mset_create)(
    DLMSET_TYPE_T min, 
    DLMSET_TYPE_T max,
    size_t size,
    dlthread_comm_t comm);


DLMSET_TYPE_T DLMSET_PUB(mset_get)(
    size_t i, 
    DLMSET_PUB(mset_t) const * set);


int DLMSET_PUB(mset_contains)(
    DLMSET_TYPE_T item, 
    DLMSET_PUB(mset_t) const * set);


int DLMSET_PUB(mset_add)(
    DLMSET_TYPE_T item, 
    DLMSET_PUB(mset_t) * set);


int DLMSET_PUB(mset_remove)(
    DLMSET_TYPE_T item, 
    DLMSET_PUB(mset_t) * set);


DLMSET_TYPE_T DLMSET_PUB(mset_remove_index)(
    size_t idx, 
    DLMSET_PUB(mset_t) * set);


size_t DLMSET_PUB(mset_clear)(
    DLMSET_PUB(mset_t) * set);


void DLMSET_PUB(mset_free)(
    DLMSET_PUB(mset_t) * ptr);


#undef DLMSET_PRE2
#undef DLMSET_PRE1
#undef DLMSET_PRI
#undef DLMSET_PUB


#else


#undef DLMSET_PRE2
#undef DLMSET_PRE1
#undef DLMSET_PRI
#undef DLMSET_PUB


#define DLMSET_VISIBILITY static
#include "dlmset_funcs.h"
#undef DLMSET_VISIBILITY


#endif



