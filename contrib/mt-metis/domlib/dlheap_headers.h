/**
 * @file dlheap_headers.h
 * @brief Heap function prototypes
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright (c) 2013-2015, Dominique LaSalle
 * @version 1
 * @date 2013-10-04
 */


/* prefixing ugliness */
#define DLHEAP_PRE2(prefix,suffix) prefix ## _ ## suffix
#define DLHEAP_PRE1(prefix,suffix) DLHEAP_PRE2(prefix,suffix)
#define DLHEAP_PUB(name) DLHEAP_PRE1(DLHEAP_PREFIX,name)
#define DLHEAP_PRI(name) DLHEAP_PRE1(_,DLHEAP_PRE1(DLHEAP_PREFIX,name))




/******************************************************************************
* TYPES ***********************************************************************
******************************************************************************/

typedef struct DLHEAP_PUB(heap_t) {
  DLHEAP_TYPE_T * elements;
  size_t maxsize;
  size_t size;
} DLHEAP_PUB(heap_t);



#ifndef DLHEAP_STATIC

/******************************************************************************
* FUNCTION PROTOTYPES *********************************************************
******************************************************************************/


DLHEAP_PUB(heap_t) * DLHEAP_PUB(heap_create)(
    size_t n);


void DLHEAP_PUB(heap_expand)(
    DLHEAP_PUB(heap_t) * heap);


void DLHEAP_PUB(heap_free)(
    DLHEAP_PUB(heap_t) * heap);


void DLHEAP_PUB(heap_push)(
    DLHEAP_TYPE_T val, 
    DLHEAP_PUB(heap_t) * heap);


DLHEAP_TYPE_T DLHEAP_PUB(heap_pop)(
    DLHEAP_PUB(heap_t) * heap);


DLHEAP_TYPE_T DLHEAP_PUB(heap_peek)(
    DLHEAP_PUB(heap_t) const * heap);


#undef DLHEAP_PRE2
#undef DLHEAP_PRE1
#undef DLHEAP_PUB
#undef DLHEAP_PRI


#else


#undef DLHEAP_PRE2
#undef DLHEAP_PRE1
#undef DLHEAP_PUB
#undef DLHEAP_PRI


#define DLHEAP_VISIBILITY static
#include "dlheap_funcs.h"
#undef DLHEAP_VISIBILITY


#endif
