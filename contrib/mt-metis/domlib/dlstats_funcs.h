/**
 * @file dlstats_funcs.h
 * @brief Functions for calculating statistics
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright (c) 2013-2015, Dominique LaSalle
 * @version 1
 * @date 2013-10-06
 */



/* prefixing ugliness */
#define DLSTATS_PRE2(prefix,suffix) prefix ## _ ## suffix
#define DLSTATS_PRE1(prefix,suffix) DLSTATS_PRE2(prefix,suffix)
#define DLSTATS_PUB(name) DLSTATS_PRE1(DLSTATS_PREFIX,name)
#define DLSTATS_PRI(name) DLSTATS_PRE1(_,DLSTATS_PRE1(DLSTATS_PREFIX,name))


/******************************************************************************
* SORTING FUNCTIONS ***********************************************************
******************************************************************************/


#ifdef DLSTATS_DLSIGN
  #define DLSTATS_DEFSIGN
  #define DLSTATS_DLSIGN DLSIGN_SIGNED
#endif


#define DLMEM_PREFIX DLSTATS_PRI(stat)
#define DLMEM_TYPE_T DLSTATS_TYPE_T
#define DLMEM_STATIC
#include "dlmem_headers.h"
#undef DLMEM_STATIC
#undef DLMEM_PREFIX
#undef DLMEM_TYPE_T


#define DLSORT_PREFIX DLSTATS_PRI(stat)
#define DLSORT_TYPE_T DLSTATS_TYPE_T
#define DLSORT_DLSIGN DLSTATS_DLSIGN
#define DLSORT_STATIC
#include "dlsort_headers.h"
#undef DLSORT_PREFIX
#undef DLSORT_TYPE_T
#undef DLSORT_DLSIGN
#undef DLSORT_STATIC


#ifdef DLSTATS_DEFSIGN
  #undef DLSTATS_DEFSIGN
  #undef DLSTATS_DLSIGN
#endif


/******************************************************************************
* PUBLIC FUNCTIONS ************************************************************
******************************************************************************/


#ifndef DLSTATS_VISIBILITY
  #define DLSTATS_DEFVIS
  #define DLSTATS_VISIBILITY
#endif


DLSTATS_VISIBILITY double DLSTATS_PUB(arithmetic_mean)(
    DLSTATS_TYPE_T const * const ptr, 
    size_t const n)
{
  double avg = 0;
  size_t i;
  for (i=0;i<n;++i) {
    avg += (double)ptr[i];
  }
  return (avg/(double)n);
}


DLSTATS_VISIBILITY double DLSTATS_PUB(geometric_mean)(
    DLSTATS_TYPE_T const * const ptr, 
    size_t const n)
{
  double lm = 0;
  size_t i;
  for (i=0;i<n;++i) {
    lm += log2((double)ptr[i]);
  }
  return pow(2,lm/(double)n);
}


DLSTATS_VISIBILITY double DLSTATS_PUB(stddev)(
    DLSTATS_TYPE_T const * const ptr,
    size_t const n)
{
  size_t i;
  double mean;
  double delta;
  double var;
  if (n == 0) {
    return 0.0;
  }
  var = 0.0;
  mean = (double)ptr[0];
  for (i=1;i<n;++i) {
    delta = ptr[i] - mean;
    mean += (delta/(i+1));
    var += delta*(ptr[i]-mean);
  }
  return sqrt(var/(i-1));
}


DLSTATS_VISIBILITY DLSTATS_TYPE_T DLSTATS_PUB(median)(
    DLSTATS_TYPE_T const * const ptr, 
    size_t const n)
{
  DL_ASSERT(n > 0, "Can't find the median of an empty array");
  DLSTATS_TYPE_T median;
  DLSTATS_TYPE_T * sorted;

  /* special cases */
  if (n == 1) {
    median = ptr[0];
  } else if (n == 2) {
    median = (ptr[0] + ptr[1]) / 2;
  } else {
    sorted = DLSTATS_PRI(stat_duplicate)(ptr,n);
    DLSTATS_PRI(stat_radixsort)(sorted,n);
    if (n % 2 == 0) {
      median = (sorted[n/2] + sorted[(n/2)+1]) / 2;
    } else {
      median = sorted[n/2];
    }
    dl_free(sorted);
  }

  return median;
}




#ifdef DLSTATS_DEFVIS
  #undef DLSTATS_DEFVIS
  #undef DLSTATS_VISIBILITY
#endif


#undef DLSTATS_PRE2
#undef DLSTATS_PRE1
#undef DLSTATS_PUB
#undef DLSTATS_PRI


