/**
 * @file dlsort_funcs.h
 * @brief Sorting functions
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright (c) 2014-2015, Dominique LaSalle
 * @version 1
 * @date 2014-05-12
 */




/* prefixing ugliness */
#define DLSORTKV_PRE2(prefix,suffix) prefix ## _ ## suffix
#define DLSORTKV_PRE1(prefix,suffix) DLSORTKV_PRE2(prefix,suffix)
#define DLSORTKV_PUB(name) DLSORTKV_PRE1(DLSORTKV_PREFIX,name)
#define DLSORTKV_PRI(name) DLSORTKV_PRE1(_,DLSORTKV_PRE1(DLSORTKV_PREFIX,name))



/******************************************************************************
* DOMLIB IMPORTS **************************************************************
******************************************************************************/


#ifndef DLSORTKV_SIZE_T
  #define DLSORTKV_SIZE_DEFAULT
  #define DLSORTKV_SIZE_T size_t
#endif


/* my prefix sum */
#define DLMATH_PREFIX DLSORTKV_PRI(count)
#define DLMATH_TYPE_T DLSORTKV_SIZE_T
#define DLMATH_DLTYPE DLTYPE_INTEGRAL
#define DLMATH_STATIC
#include "dlmath_headers.h"
#undef DLMATH_STATIC
#undef DLMATH_PREFIX
#undef DLMATH_TYPE_T
#undef DLMATH_DLTYPE




/******************************************************************************
* FUNCTIONS *******************************************************************
******************************************************************************/


#ifndef DLSORTKV_VISIBILITY
  #define DLSORTKV_DEFVIS
  #define DLSORTKV_VISIBILITY
#endif


DLSORTKV_VISIBILITY DLSORTKV_VAL_T * DLSORTKV_PUB(countingsort_kv)(
    DLSORTKV_KEY_T const * const keys, 
    DLSORTKV_VAL_T const * const vals,
    DLSORTKV_KEY_T const min,
    DLSORTKV_KEY_T const max,
    DLSORTKV_SIZE_T const n,
    DLSORTKV_VAL_T * const out,
    DLSORTKV_SIZE_T ** const r_counts)
{
  DLSORTKV_SIZE_T i; 
  const DLSORTKV_SIZE_T size = (DLSORTKV_SIZE_T)(max - min)+1; 
  DLSORTKV_SIZE_T * counts = calloc(size+1,sizeof(DLSORTKV_SIZE_T)); 
  /* avoid having to do offsets in each iteration */ 
  DLSORTKV_SIZE_T * const start = counts - ((ssize_t)min); 

  for (i=0;i<n;++i) { 
    ++start[keys[i]+1]; 
  } 

  DLSORTKV_PRI(count_prefixsum_exc)(counts+1,size); 

  for (i=0;i<n;++i) { 
    out[start[keys[i]+1]++] = vals[i]; 
  } 

  if (r_counts) {
    *r_counts = counts;
  } else {
    dl_free(counts); 
  }

  return out; 
}





#ifdef DLSORTKV_DEFVIS
  #undef DLSORTKV_DEFVIS
  #undef DLSORTKV_VISIBILITY
#endif


#ifdef DLSORTKV_SIZE_DEFAULT
  #undef DLSORTKV_SIZE_DEFAULT
  #undef DLSORTKV_SIZE_T
#endif

#undef DLSORTKV_PRE2
#undef DLSORTKV_PRE1
#undef DLSORTKV_PUB
#undef DLSORTKV_PRI


