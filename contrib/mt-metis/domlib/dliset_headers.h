/**
 * @file dliset_headers.h
 * @brief ISet function prototypes
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright (c) 2013-2015, Dominique LaSalle
 * @version 1
 * @date 2013-10-05
 */


/* prefixing ugliness */
#define DLISET_PRE2(prefix,suffix) prefix ## _ ## suffix
#define DLISET_PRE1(prefix,suffix) DLISET_PRE2(prefix,suffix)
#define DLISET_PUB(name) DLISET_PRE1(DLISET_PREFIX,name)
#define DLISET_PRI(name) DLISET_PRE1(_,DLISET_PRE1(DLISET_PREFIX,name))




typedef struct DLISET_PUB(iset_t) {
  size_t size;
  size_t maxsize;
  DLISET_TYPE_T min;
  DLISET_TYPE_T max;
  DLISET_TYPE_T * __DL_RESTRICT ind;
  DLISET_TYPE_T * __DL_RESTRICT ptr;
  #ifdef DLISET_SYNC
  omp_lock_t lock;
  #endif
} DLISET_PUB(iset_t);




#ifndef DLISET_STATIC


/******************************************************************************
* FUNCTION PROTOTYPES *********************************************************
******************************************************************************/


/**
 * @brief Allocate and initialize an ISet with a minimum and maximum element
 * value.
 *
 * @param min The minimum element (inclusive).
 * @param max The maximum element (exclusive).
 *
 * @return The ISet.
 */
DLISET_PUB(iset_t) * DLISET_PUB(iset_create)(
    DLISET_TYPE_T min, 
    DLISET_TYPE_T max);


DLISET_TYPE_T DLISET_PUB(iset_get)(
    size_t i, 
    DLISET_PUB(iset_t) const * set);


int DLISET_PUB(iset_contains)(
    DLISET_TYPE_T item, 
    DLISET_PUB(iset_t) const * set);


int DLISET_PUB(iset_add)(
    DLISET_TYPE_T item, 
    DLISET_PUB(iset_t) * set);


DLISET_PUB(iset_t) * DLISET_PUB(iset_clone)(
    DLISET_PUB(iset_t) * set);


int DLISET_PUB(iset_populate)(
    DLISET_PUB(iset_t) * set);


int DLISET_PUB(iset_remove)(
    DLISET_TYPE_T item, 
    DLISET_PUB(iset_t) * set);


DLISET_TYPE_T DLISET_PUB(iset_remove_index)(
    size_t idx, 
    DLISET_PUB(iset_t) * set);


void DLISET_PUB(iset_move_to_front)(
    DLISET_TYPE_T item,
    DLISET_PUB(iset_t) * set);


size_t DLISET_PUB(iset_clear)(
    DLISET_PUB(iset_t) * set);


DLISET_TYPE_T DLISET_PUB(iset_indexof)(
    DLISET_TYPE_T item, 
    DLISET_PUB(iset_t) const * set);


void DLISET_PUB(iset_expand)(
    DLISET_TYPE_T nmax,
    DLISET_PUB(iset_t) * set);


void DLISET_PUB(iset_free)(
    DLISET_PUB(iset_t) * ptr);


#undef DLISET_PRE2
#undef DLISET_PRE1
#undef DLISET_PRI
#undef DLISET_PUB


#else


#undef DLISET_PRE2
#undef DLISET_PRE1
#undef DLISET_PRI
#undef DLISET_PUB


#define DLISET_VISIBILITY static
#include "dliset_funcs.h"
#undef DLISET_VISIBILITY


#endif



