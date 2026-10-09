/**
 * @file dlmem.h
 * @brief Memory functio prototypes
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright (c) 2013-2015, Dominique LaSalle
 * @version 1
 * @date 2013-08-19
 */




/******************************************************************************
* FUNCTION PROTOTYPES *********************************************************
******************************************************************************/


#ifndef DLMEM_STATIC

/* prefixing ugliness */
#define DLMEM_PRE2(prefix,suffix) prefix ## _ ## suffix
#define DLMEM_PRE1(prefix,suffix) DLMEM_PRE2(prefix,suffix)
#define DLMEM_PUB(name) DLMEM_PRE1(DLMEM_PREFIX,name)
#define DLMEM_RPUB(name) DLMEM_PRE1(r,DLMEM_PRE1(DLMEM_PREFIX,name))


DLMEM_TYPE_T * DLMEM_PUB(alloc)(
    size_t n); 


DLMEM_TYPE_T * DLMEM_PUB(calloc)(
    size_t n); 


void DLMEM_PUB(copy)(
    DLMEM_TYPE_T * __DL_RESTRICT dst, 
    const DLMEM_TYPE_T * __DL_RESTRICT src, 
    size_t n); 


void DLMEM_PUB(move)(
    DLMEM_TYPE_T * __DL_RESTRICT dst, 
    const DLMEM_TYPE_T * __DL_RESTRICT src, 
    size_t n); 


void DLMEM_PUB(set)(
    DLMEM_TYPE_T * dst, 
    DLMEM_TYPE_T val, 
    size_t n); 


DLMEM_TYPE_T * DLMEM_PUB(init_alloc)(
    DLMEM_TYPE_T val, 
    size_t n); 


DLMEM_TYPE_T * DLMEM_PUB(realloc)(
    DLMEM_TYPE_T * ptr, 
    size_t newsize); 


DLMEM_TYPE_T * DLMEM_PUB(duplicate)(
    const DLMEM_TYPE_T * src, 
    size_t n); 


DLMEM_TYPE_T ** DLMEM_RPUB(alloc)(
    size_t n); 


DLMEM_TYPE_T ** DLMEM_RPUB(calloc)(
    size_t n); 


DLMEM_TYPE_T ** DLMEM_RPUB(dalloc)(
    void const * vec, 
    size_t svec, 
    size_t nvec); 


DLMEM_TYPE_T ** DLMEM_RPUB(dcalloc)(
    void const * vec, 
    size_t svec, 
    size_t nvec); 


void DLMEM_RPUB(copy)(
    DLMEM_TYPE_T ** __DL_RESTRICT dst, 
    DLMEM_TYPE_T * const * __DL_RESTRICT src, 
    size_t n); 


void DLMEM_RPUB(move)(
    DLMEM_TYPE_T ** dst, 
    DLMEM_TYPE_T * const * src, 
    size_t n); 


void DLMEM_RPUB(set)(
    DLMEM_TYPE_T ** dst, 
    DLMEM_TYPE_T * val, 
    size_t n); 


DLMEM_TYPE_T ** DLMEM_RPUB(init_alloc)(
    DLMEM_TYPE_T * val, 
    size_t n); 


DLMEM_TYPE_T ** DLMEM_RPUB(init_dalloc)(
    DLMEM_TYPE_T val, 
    void const * vec, 
    size_t svec, 
    size_t nvec); 


DLMEM_TYPE_T ** DLMEM_RPUB(sym_alloc)(
    size_t m, 
    size_t n); 


DLMEM_TYPE_T ** DLMEM_RPUB(sym_calloc)(
    size_t m, 
    size_t n); 


DLMEM_TYPE_T ** DLMEM_RPUB(sym_init_alloc)(
    DLMEM_TYPE_T val, 
    size_t m, 
    size_t n); 


DLMEM_TYPE_T ** DLMEM_RPUB(realloc)(
    DLMEM_TYPE_T ** ptr, 
    size_t newsize); 


void DLMEM_RPUB(free)(
    DLMEM_TYPE_T ** ptr, 
    size_t n);


#undef DLMEM_PRE2
#undef DLMEM_PRE1
#undef DLMEM_PUB
#undef DLMEM_RPUB

#else

#define DLMEM_VISIBILITY static
#include "dlmem_funcs.h"
#undef DLMEM_VISIBILITY

#endif


