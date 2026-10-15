/**
 * @file dlmset_funcs.h
 * @brief ISet functions
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




/******************************************************************************
* CONSTANTS *******************************************************************
******************************************************************************/


#ifdef DLMSET_NULL_VALUE
static const DLMSET_TYPE_T DLMSET_PRI(mset_null_value) =
    (DLMSET_TYPE_T)DLMSET_NULL_VALUE;
#else
static const DLMSET_TYPE_T DLMSET_PRI(mset_null_value) = (DLMSET_TYPE_T)-1;
#endif




/******************************************************************************
* PUBLIC FUNCTIONS ************************************************************
******************************************************************************/


#ifndef DLMSET_VISIBILITY
  #define DLMSET_DEFVIS
  #define DLMSET_VISIBILITY
#endif


DLMSET_VISIBILITY DLMSET_PUB(mset_t) * DLMSET_PUB(mset_create)(
    DLMSET_TYPE_T const min, 
    DLMSET_TYPE_T const max,
    size_t const mysize,
    dlthread_comm_t comm)
{
  size_t n, i, start, end;
  DLMSET_PUB(mset_t) * set;

  size_t const myid = dlthread_get_id(comm);
  size_t const nthreads = dlthread_get_nthreads(comm);

  DL_ASSERT(min <= max, "Attempt to create a mset where min is greater "
      "than max\n");
  DL_ASSERT(((DLMSET_PRI(mset_null_value) < min) ||
        (DLMSET_PRI(mset_null_value) > max)), "Attempt to create"
      "a mset where NULL_VALUE is in  between min and max\n");

  set = dlthread_get_shmem(sizeof(DLMSET_PUB(mset_t)),comm);

  if (myid == 0) {
    set->comm = comm;
    set->min = min;
    set->max = max;
    set->info = malloc(sizeof(DLMSET_PRI(mset_info_t))*nthreads);
    set->ptr = malloc(sizeof(DLMSET_TYPE_T)*(max-min));
  }
  dlthread_barrier(comm);

  n = (size_t)(set->max - set->min);

  start = myid*((n/nthreads)+1);
  end = dl_min(n,(myid+1)*((n/nthreads)+1));
  for (i=start;i<end;++i) {
    set->ptr[i] = DLMSET_PRI(mset_null_value);
  }

  set->info[myid].size = 0;
  set->info[myid].ind = malloc(sizeof(DLMSET_TYPE_T)*mysize);

  dlthread_barrier(comm);

  return set;
}


DLMSET_VISIBILITY DLMSET_TYPE_T DLMSET_PUB(mset_get)(
    size_t const i,
    DLMSET_PUB(mset_t) const * const set)
{
  size_t const myid = dlthread_get_id(set->comm);

  DL_ASSERT(i < set->info[myid].size, \
      "Attempting to get item from beyond set end\n");

  return set->info[myid].ind[i];
}


DLMSET_VISIBILITY int DLMSET_PUB(mset_contains)(
    DLMSET_TYPE_T const item, 
    DLMSET_PUB(mset_t) const * const set)
{
  int rv;
  size_t idx;

  DL_ASSERT(item >= set->min, "Search for item less tham minimum in "
      "mset\n");
  DL_ASSERT(item < set->max, "Search for item greater tham maximum in "
      "mset\n");

  idx = (size_t)(item - set->min);

  rv = set->ptr[idx] != DLMSET_PRI(mset_null_value);

  return rv; 
}


DLMSET_VISIBILITY int DLMSET_PUB(mset_add)(
    DLMSET_TYPE_T const item, 
    DLMSET_PUB(mset_t) * const set)
{
  size_t idx;
  int rv;

  size_t const myid = dlthread_get_id(set->comm);

  DL_ASSERT(item >= set->min, "Trying to add item less tham minimum in "
      "mset\n");
  DL_ASSERT(item < set->max, "Trying to add  item greater tham maximum in "
      "mset\n");

  idx = (size_t)(item - set->min);

  if (set->ptr[idx] == DLMSET_PRI(mset_null_value)) {
    set->ptr[idx] = set->info[myid].size;
    set->info[myid].ind[(size_t)set->info[myid].size++] = item;
    rv = 1;
  } else {
    rv = 0;
  }

  return rv;
}


DLMSET_VISIBILITY int DLMSET_PUB(mset_remove)(
    DLMSET_TYPE_T const item,
    DLMSET_PUB(mset_t) * const set)
{
  size_t odx;
  size_t idx;

  size_t const myid = dlthread_get_id(set->comm);

  DL_ASSERT(item >= set->min, "Trying to delete item less than minimum in "
      "mset\n");
  DL_ASSERT(item < set->max, "Trying to delete item greater tham maximum "
      "in mset\n");
  
  idx = (size_t)(item - set->min);
  if (set->ptr[idx] == DLMSET_PRI(mset_null_value)) {
    return 0;
  } else {
    odx = set->info[myid].ind[set->ptr[idx]] = \
          set->info[myid].ind[--set->info[myid].size];
    set->ptr[odx-set->min] = set->ptr[idx];
    set->ptr[idx] = DLMSET_PRI(mset_null_value);

    return 1;
  }
}


DLMSET_VISIBILITY DLMSET_TYPE_T DLMSET_PUB(mset_remove_index)(
    size_t const idx,
    DLMSET_PUB(mset_t) * const set)
{
  DLMSET_TYPE_T item;
  size_t odx, rdx;

  size_t const myid = dlthread_get_id(set->comm);

  DL_ASSERT(idx < set->info[myid].size, "Trying to delete index greater " \
      "than maximum in mset\n");

  item = set->info[myid].ind[idx];
  rdx = (size_t)(item - set->min);
  odx = set->info[myid].ind[set->ptr[rdx]] = \
        set->info[myid].ind[--set->info[myid].size];
  set->ptr[odx-set->min] = set->ptr[rdx];
  set->ptr[rdx] = DLMSET_PRI(mset_null_value);

  return item;
}


DLMSET_VISIBILITY size_t DLMSET_PUB(mset_clear)(
    DLMSET_PUB(mset_t) * const set)
{
  size_t i;
  DLMSET_TYPE_T j;

  size_t const myid = dlthread_get_id(set->comm);

  size_t const n = set->info[myid].size;

  for (i=0;i<n;++i) {
    j = set->info[myid].ind[i];
    set->ptr[j] = DLMSET_PRI(mset_null_value);
  }
  set->info[myid].size = 0;

  return n;
}


DLMSET_VISIBILITY void DLMSET_PUB(mset_free)(
    DLMSET_PUB(mset_t) * set)
{
  size_t const myid = dlthread_get_id(set->comm);

  dl_free(set->info[myid].ind);
  dlthread_barrier(set->comm);
  if (myid == 0) {
    dl_free(set->ptr);
    dl_free(set->info);
    dl_free(set);
  }
}




#ifdef DLMSET_VISIBILITY
  #undef DLMSET_DEFVIS
  #undef DLMSET_VISIBILITY
#endif


#undef DLMSET_PRE2
#undef DLMSET_PRE1
#undef DLMSET_PRI
#undef DLMSET_PUB


