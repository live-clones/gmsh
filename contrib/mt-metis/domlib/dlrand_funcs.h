/**
 * @file dlrand_funcs.h
 * @brief Functions for generating random numbers and shuffling
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright (c) 2013-2015, Dominique LaSalle
 * @version 1
 * @date 2013-10-06
 */



#ifndef __USE_POSIX
#define __USE_POSIX 1
#endif


#ifndef _XOPEN_SOURCE
#define _XOPEN_SOURCE 1
#endif


#include <stdlib.h>
#include "dlutil.h"


/* prefixing ugliness */
#define DLRAND_PRE2(prefix,suffix) prefix ## _ ## suffix
#define DLRAND_PRE1(prefix,suffix) DLRAND_PRE2(prefix,suffix)
#define DLRAND_PUB(name) DLRAND_PRE1(DLRAND_PREFIX,name)
#define DLRAND_PRI(name) DLRAND_PRE1(_,DLRAND_PRE1(DLRAND_PREFIX,name))



/******************************************************************************
* PRIVATE FUNCTIONS ***********************************************************
******************************************************************************/
static uint32_t DLRAND_PRI(rand_int_r)(
    unsigned int * const seed)
{
  uint16_t state[3];
  state[0] = (uint16_t)(*seed);
  state[1] = (uint16_t)((*seed) >> 16);
  state[2] = (uint16_t)((*seed) >> 8);

  uint32_t const r = ((uint32_t)nrand48(state));

  *seed = state[0] + (state[1] << 16);

  return r;
}


static uint64_t DLRAND_PRI(rand_long_r)(
    unsigned int * const seed)
{
  uint16_t state[3];
  state[0] = (uint16_t)(*seed);
  state[1] = (uint16_t)((*seed) >> 16);
  state[2] = (uint16_t)((*seed) >> 8);

  uint64_t const r = ((uint64_t)nrand48(state)) + (((uint64_t)nrand48(state)) << 32);

  *seed = state[0] + (state[1] << 16);

  return r;
}




/******************************************************************************
* PUBLIC FUNCTIONS ************************************************************
******************************************************************************/


#ifndef DLRAND_VISIBILITY
  #define DLRAND_DEFVIS
  #define DLRAND_VISIBILITY
#endif


DLRAND_VISIBILITY DLRAND_TYPE_T DLRAND_PUB(rand_r)(
    DLRAND_TYPE_T const min, 
    DLRAND_TYPE_T const max, 
    unsigned int * const seed)
{
  if (min == max) {
    return min;
  } else if (sizeof(DLRAND_TYPE_T) <= sizeof(int)) {
    #if defined(DLRAND_DLTYPE) && DLRAND_DLTYPE == DLTYPE_FLOAT
    return ((max - min) * 
        (DLRAND_PRI(rand_int_r)(seed)/(DLRAND_TYPE_T)RAND_MAX)) + min;
    #else
    return ( ((DLRAND_TYPE_T)DLRAND_PRI(rand_int_r)(seed)) % 
        (max - min)) + min;
    #endif
  } else {
    #if defined(DLRAND_DLTYPE) && DLRAND_DLTYPE == DLTYPE_FLOAT
    return ((max - min) *
        (DLRAND_PRI(rand_long_r)(seed)/(DLRAND_TYPE_T)RAND_MAX)) + min;
    #else
    return ( ((DLRAND_TYPE_T)DLRAND_PRI(rand_long_r)(seed)) % 
        (max - min)) + min;
    #endif
  }
}


DLRAND_VISIBILITY DLRAND_TYPE_T DLRAND_PUB(rand)(
    DLRAND_TYPE_T const min, 
    DLRAND_TYPE_T const max)
{
  return DLRAND_PUB(rand_r)(min,max,dl_get_rand());
}


DLRAND_VISIBILITY DLRAND_TYPE_T * DLRAND_PUB(shuffle_r)(
    DLRAND_TYPE_T * const ptr, 
    size_t const n, 
    unsigned int * const seed)
{
  size_t i,j,nidx;
  if (n > 0) {
    DLRAND_TYPE_T * bkup = DLRAND_PUB(duplicate)(ptr,n);
    nidx = n;
    for (i=0;i<n-1;++i) {
      j = size_rand_r(0,nidx,seed);
      ptr[i] = bkup[j];
      bkup[j] = bkup[--nidx];
    }
    /* save me 1 call to rand() */
    ptr[i] = bkup[0];
    dl_free(bkup);
  }
  return ptr;
}


DLRAND_VISIBILITY DLRAND_TYPE_T * DLRAND_PUB(shuffle)(
    DLRAND_TYPE_T * const ptr, 
    size_t const n)
{
  return DLRAND_PUB(shuffle_r)(ptr,n,dl_get_rand());
}


DLRAND_VISIBILITY DLRAND_TYPE_T * DLRAND_PUB(pseudo_shuffle_r)(
    DLRAND_TYPE_T * const ptr, 
    size_t const nshuffles, 
    size_t const n, 
    unsigned int * const seed)
{
  size_t i,u,v;
  double r,d;
  if (n > 0) {
    if (nshuffles > n) {
      wprintf("PSUEDO_SHUFFLE: nshuffles > nelements -- " \
          "calling normal shuffle\n");
      DLRAND_PUB(shuffle_r)(ptr,n,seed);
    } else if (n < 10) {
      for (i=0;i<n;++i) {
        u = size_rand_r(0,n,seed);
        v = size_rand_r(0,n,seed);
        dl_swap(ptr[u],ptr[v]);
      }
    } else {
      r = ((n-3) / (double)nshuffles);
      for (i=0,d=0;i<nshuffles;++i,d+=r) {
        u = (size_t)d;
        v = size_rand_r(0,n-3,seed);
        dl_swap(ptr[u],ptr[v+1]);
        dl_swap(ptr[u+1],ptr[v+3]);
        dl_swap(ptr[u+2],ptr[v+0]);
        dl_swap(ptr[u+3],ptr[v+2]);
      }
    }
  }
  return ptr;
}


DLRAND_VISIBILITY DLRAND_TYPE_T * DLRAND_PUB(pseudo_shuffle)(
    DLRAND_TYPE_T * const ptr, 
    size_t const nshuffles, 
    size_t const n)
{
  return DLRAND_PUB(pseudo_shuffle_r)(ptr,nshuffles,n,dl_get_rand());
}


DLRAND_VISIBILITY DLRAND_TYPE_T * DLRAND_PUB(fill_rand_r)(
    DLRAND_TYPE_T const min, 
    DLRAND_TYPE_T const max, 
    DLRAND_TYPE_T * const ptr, 
    size_t const n, 
    unsigned int * seed)
{
  size_t i;
  for (i=0;i<n;++i) {
    ptr[i] = DLRAND_PUB(rand_r)(min,max,seed);
  }
  return ptr;
}


DLRAND_VISIBILITY DLRAND_TYPE_T * DLRAND_PUB(fill_rand)(
    DLRAND_TYPE_T const min, 
    DLRAND_TYPE_T const max, 
    DLRAND_TYPE_T * const ptr, 
    size_t const n)
{
  return DLRAND_PUB(fill_rand_r)(min,max,ptr,n,dl_get_rand());
}


#ifdef DLRAND_DEFVIS
  #undef DLRAND_DEFVIS
  #undef DLRAND_VISIBILITY
#endif


#undef DLRAND_PRE2
#undef DLRAND_PRE1
#undef DLRAND_PUB
#undef DLRAND_PRI


