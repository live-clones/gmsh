/**
 * @file dliset_funcs.h
 * @brief ISet functions
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




/******************************************************************************
* CONSTANTS *******************************************************************
******************************************************************************/


#ifdef DLISET_NULL_VALUE
static const DLISET_TYPE_T DLISET_PRI(iset_null_value) =
    (DLISET_TYPE_T)DLISET_NULL_VALUE;
#else
static const DLISET_TYPE_T DLISET_PRI(iset_null_value) = (DLISET_TYPE_T)-1;
#endif




/******************************************************************************
* MEMORY FUNCTIONS ************************************************************
******************************************************************************/


#define DLMEM_PREFIX DLISET_PUB(iset)
#define DLMEM_TYPE_T DLISET_PUB(iset_t)
#define DLMEM_STATIC
#include "dlmem_headers.h"
#undef DLMEM_STATIC
#undef DLMEM_TYPE_T
#undef DLMEM_PREFIX


#define DLMEM_PREFIX DLISET_PRI(element)
#define DLMEM_TYPE_T DLISET_TYPE_T
#define DLMEM_STATIC
#include "dlmem_headers.h"
#undef DLMEM_STATIC
#undef DLMEM_TYPE_T
#undef DLMEM_PREFIX




/******************************************************************************
* PUBLIC FUNCTIONS ************************************************************
******************************************************************************/


#ifndef DLISET_VISIBILITY
  #define DLISET_DEFVIS
  #define DLISET_VISIBILITY
#endif


DLISET_VISIBILITY DLISET_PUB(iset_t) * DLISET_PUB(iset_create)(
    DLISET_TYPE_T const min, 
    DLISET_TYPE_T const max)
{
  DL_ASSERT(min <= max, "Attempt to create a iset where min is greater "
      "than max\n");
  DL_ASSERT(((DLISET_PRI(iset_null_value) < min) ||
        (DLISET_PRI(iset_null_value) > max)), "Attempt to create"
      "a iset where NULL_VALUE is in  between min and max\n");
  DLISET_PUB(iset_t) * set = DLISET_PUB(iset_alloc)(1);
  set->min = min;
  set->max = max;
  set->maxsize = (size_t)(set->max - set->min);
  set->size = 0;
  set->ind = DLISET_PRI(element_alloc)(set->maxsize);
  set->ptr = DLISET_PRI(element_init_alloc)(DLISET_PRI(iset_null_value),
      set->maxsize);
  #ifdef DLISET_SYNC
  omp_init_lock(&set->lock);
  #endif
  return set;
}


DLISET_VISIBILITY DLISET_PUB(iset_t) * DLISET_PUB(iset_clone)(
    DLISET_PUB(iset_t) * const set)
{
  DLISET_PUB(iset_t) * nset = DLISET_PUB(iset_alloc)(1);

  nset->min = set->min;
  nset->max = set->max;
  nset->maxsize = nset->maxsize;
  nset->size = set->size;
  nset->ind = DLISET_PRI(element_duplicate)(set->ind,set->maxsize);
  nset->ptr = DLISET_PRI(element_duplicate)(set->ptr,set->maxsize);
  #ifdef DLISET_SYNC
  omp_init_lock(&nset->lock);
  #endif
  return nset;
}


DLISET_VISIBILITY DLISET_TYPE_T DLISET_PUB(iset_get)(
    size_t const i,
    DLISET_PUB(iset_t) const * const set)
{
  DL_ASSERT(i < set->size,"Attempting to get item from beyond set end\n");

  return set->ind[i];
}


DLISET_VISIBILITY int DLISET_PUB(iset_contains)(
    DLISET_TYPE_T const item, 
    DLISET_PUB(iset_t) const * const set)
{
  DL_ASSERT(item >= set->min, "Search for item less tham minimum in "
      "iset\n");
  DL_ASSERT(item < set->max, "Search for item greater tham maximum in "
      "iset\n");

  int rv;
  size_t idx;
  
  idx = (size_t)(item - set->min);

  rv = set->ptr[idx] != DLISET_PRI(iset_null_value);

  return rv; 
}


DLISET_VISIBILITY int DLISET_PUB(iset_add)(
    DLISET_TYPE_T const item, 
    DLISET_PUB(iset_t) * const set)
{
  DL_ASSERT(item >= set->min, "Trying to add item less tham minimum in "
      "iset\n");
  DL_ASSERT(item < set->max, "Trying to add  item greater tham maximum in "
      "iset\n");

  size_t idx;
  int rv;
  
  idx = (size_t)(item - set->min);

  #ifdef DLISET_SYNC
  omp_set_lock(&set->lock);
  #endif

  if (set->ptr[idx] == DLISET_PRI(iset_null_value)) {
    set->ptr[idx] = set->size;
    set->ind[(size_t)set->size++] = item;
    rv = 1;
  } else {
    rv = 0;
  }

  #ifdef DLISET_SYNC
  omp_unset_lock(&set->lock);
  #endif

  return rv;
}


DLISET_VISIBILITY int DLISET_PUB(iset_remove)(
    DLISET_TYPE_T const item,
    DLISET_PUB(iset_t) * const set)
{
  DL_ASSERT(item >= set->min, "Trying to delete item less than minimum in "
      "iset\n");
  DL_ASSERT(item < set->max, "Trying to delete item greater tham maximum "
      "in iset\n");

  size_t odx;
  size_t idx;
  
  idx = (size_t)(item - set->min);
  if (set->ptr[idx] == DLISET_PRI(iset_null_value)) {
    return 0;
  } else {
    #ifdef DLISET_SYNC
    omp_set_lock(&set->lock);
    #endif

    odx = set->ind[set->ptr[idx]] = set->ind[--set->size];
    set->ptr[odx-set->min] = set->ptr[idx];
    set->ptr[idx] = DLISET_PRI(iset_null_value);

    #ifdef DLISET_SYNC
    omp_unset_lock(&set->lock);
    #endif
    return 1;
  }
}


DLISET_VISIBILITY DLISET_TYPE_T DLISET_PUB(iset_remove_index)(
    size_t const idx,
    DLISET_PUB(iset_t) * const set)
{
  DL_ASSERT(idx < set->size, "Trying to delete index greater than maximum in "
      "iset\n");

  DLISET_TYPE_T item;
  size_t odx, rdx;

  #ifdef DLISET_SYNC
  omp_set_lock(&set->lock);
  #endif

  item = set->ind[idx];
  rdx = (size_t)(item - set->min);
  odx = set->ind[set->ptr[rdx]] = set->ind[--set->size];
  set->ptr[odx-set->min] = set->ptr[rdx];
  set->ptr[rdx] = DLISET_PRI(iset_null_value);

  #ifdef DLISET_SYNC
  omp_unset_lock(&set->lock);
  #endif

  return item;
}


DLISET_VISIBILITY void DLISET_PUB(iset_move_to_front)(
    DLISET_TYPE_T const item,
    DLISET_PUB(iset_t) * const set)
{
  size_t idx, odx;

  /* extract item index */
  idx = (size_t)(item - set->min);

  #ifdef DLISET_SYNC
  omp_set_lock(&set->lock);
  #endif

  /* move the old item to the new items place */
  odx = set->ind[set->ptr[idx]] = set->ind[0];
  set->ptr[odx-set->min] = set->ptr[idx];

  /* place our item at the front */
  set->ptr[idx] = 0;
  set->ind[0] = idx;

  #ifdef DLISET_SYNC
  omp_unset_lock(&set->lock);
  #endif
}


DLISET_VISIBILITY int DLISET_PUB(iset_populate)(
    DLISET_PUB(iset_t) * const set)
{
  size_t i;

  #ifdef DLISET_SYNC
  omp_set_lock(&set->lock);
  #endif

  const size_t n = set->maxsize;

  for (i=0;i<n;++i) {
    set->ptr[i] = i;
    set->ind[i] = i+set->min;
  }
  set->size = n;

  #ifdef DLISET_SYNC
  omp_unset_lock(&set->lock);
  #endif

  return 1;
}


DLISET_VISIBILITY size_t DLISET_PUB(iset_clear)(
    DLISET_PUB(iset_t) * const set)
{
  size_t i;
  DLISET_TYPE_T j;

  #ifdef DLISET_SYNC
  omp_set_lock(&set->lock);
  #endif

  const size_t n = set->size;

  for (i=0;i<n;++i) {
    j = set->ind[i];
    set->ptr[j] = DLISET_PRI(iset_null_value);
  }
  set->size = 0;

  #ifdef DLISET_SYNC
  omp_unset_lock(&set->lock);
  #endif

  return n;
}


DLISET_VISIBILITY DLISET_TYPE_T DLISET_PUB(iset_indexof)(
    DLISET_TYPE_T const item, 
    DLISET_PUB(iset_t) const * const set)
{
  DL_ASSERT(item >= set->min, "Trying to find item less tham minimum in "
      "iset\n");
  DL_ASSERT(item < set->max, "Trying to find item greater tham maximum in "
      "iset\n");

  size_t idx;
  
  idx = (size_t)(item - set->min);
  return set->ptr[idx];
}


DLISET_VISIBILITY void DLISET_PUB(iset_expand)(
    DLISET_TYPE_T nmax,
    DLISET_PUB(iset_t) * const set)
{
  size_t i, nmaxsize;

  if (nmax <= set->max) {
    /* do nothing */
    return;
  }

  nmaxsize = set->maxsize + (nmax - set->max);

  /* expand arrays */
  set->ind = realloc(set->ind,sizeof(*(set->ind))*nmaxsize);
  set->ptr = realloc(set->ptr,sizeof(*(set->ptr))*nmaxsize);

  /* initialize tail of ptr */
  for (i=set->maxsize;i<nmaxsize;++i) {
    set->ptr[i] = DLISET_PRI(iset_null_value);
  }

  set->max = nmax; 
  set->maxsize = nmaxsize;
}


DLISET_VISIBILITY void DLISET_PUB(iset_free)(
    DLISET_PUB(iset_t) * set)
{
  #ifdef DLISET_SYNC
  omp_destroy_lock(&set->lock);
  #endif

  dl_free(set->ptr);
  dl_free(set->ind);
  dl_free(set);
}




#ifdef DLISET_VISIBILITY
  #undef DLISET_DEFVIS
  #undef DLISET_VISIBILITY
#endif


#undef DLISET_PRE2
#undef DLISET_PRE1
#undef DLISET_PRI
#undef DLISET_PUB


