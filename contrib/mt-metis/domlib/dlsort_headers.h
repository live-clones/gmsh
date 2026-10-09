/**
 * @file dlsort_headers.h
 * @brief Sorting function prototypes
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright (c) 2013-2015, Dominique LaSalle
 * @version 1
 * @date 2013-10-06
 */




/******************************************************************************
* FUNCTION PROTOTYPES *********************************************************
******************************************************************************/


#ifndef DLSORT_STATIC


/* prefixing ugliness */
#define DLSORT_PRE2(prefix,suffix) prefix ## _ ## suffix
#define DLSORT_PRE1(prefix,suffix) DLSORT_PRE2(prefix,suffix)
#define DLSORT_PUB(name) DLSORT_PRE1(DLSORT_PREFIX,name)
#define DLSORT_RPI(name) DLSORT_PRE1(_,DLSORT_PRE1(DLSORT_PREFIX,name))


ssize_t DLSORT_PUB(binarysearch)(const DLSORT_TYPE_T * a, DLSORT_TYPE_T v,
    size_t n);


DLSORT_TYPE_T * DLSORT_PUB(radixsort)(DLSORT_TYPE_T * a, size_t n);


DLSORT_TYPE_T * DLSORT_PUB(insertionsort)(DLSORT_TYPE_T * a, size_t n);


DLSORT_TYPE_T * DLSORT_PUB(quicksort)(DLSORT_TYPE_T * a, size_t n);


#undef DLSORT_PRE2
#undef DLSORT_PRE1
#undef DLSORT_PUB
#undef DLSORT_PRI


#else


#define DLSORT_VISIBILITY static
#include "dlsort_funcs.h"
#undef DLSORT_VISIBILITY


#endif
