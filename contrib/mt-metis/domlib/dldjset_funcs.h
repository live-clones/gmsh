/**
 * @file dldjset_funcs.h
 * @brief Functions for disjoint sets
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright (c) 2013-2015, Dominique LaSalle
 * @version 1
 * @date 2013-10-06
 */




/* prefixing ugliness */
#define DLDJSET_PRE2(prefix,suffix) prefix ## _ ## suffix
#define DLDJSET_PRE1(prefix,suffix) DLDJSET_PRE2(prefix,suffix)
#define DLDJSET_PUB(name) DLDJSET_PRE1(DLDJSET_PREFIX,name)
#define DLDJSET_PRI(name) DLDJSET_PRE1(_,DLDJSET_PRE1(DLDJSET_PREFIX,name))




/******************************************************************************
* CONSTANTS *******************************************************************
******************************************************************************/


static const size_t DLDJSET_PRI(djset_noparent) = (size_t)-1;




/******************************************************************************
* MEMORY FUNCTIONS ************************************************************
******************************************************************************/


#define DLMEM_PREFIX DLDJSET_PRI(djset_node)
#define DLMEM_TYPE_T DLDJSET_PRI(djset_node_t)
#define DLMEM_STATIC
#include "dlmem_headers.h"
#undef DLMEM_PREFIX
#undef DLMEM_TYPE_T
#undef DLMEM_STATIC


#define DLMEM_PREFIX DLDJSET_PUB(djset)
#define DLMEM_TYPE_T DLDJSET_PUB(djset_t)
#define DLMEM_STATIC
#include "dlmem_headers.h"
#undef DLMEM_PREFIX
#undef DLMEM_TYPE_T
#undef DLMEM_STATIC




/******************************************************************************
* PRIVATE FUNCTIONS ***********************************************************
******************************************************************************/


static inline size_t DLDJSET_PRI(djset_findidx)(
    DLDJSET_TYPE_T const item,
    DLDJSET_PUB(djset_t) * const set)
{
  size_t root, node, next;

  DL_ASSERT(item < set->max,"Invalid item (max) for djset (%zu/%zu)\n", \
      (size_t)item,(size_t)set->max);
  DL_ASSERT(item >= set->min,"Invalid item (min) for djset (%zu/%zu)\n", \
      (size_t)item,(size_t)set->min);

  node = root = (size_t)(item - set->min);

  while ((next = set->nodes[root].root) != DLDJSET_PRI(djset_noparent)) {
    root = next;
  }

  while ((next = set->nodes[node].root) != DLDJSET_PRI(djset_noparent)) {
    set->nodes[node].root = root;
    node = next;
  }

  DL_ASSERT_EQUALS(set->nodes[root].root,DLDJSET_PRI(djset_noparent), \
      PF_SIZE_T);

  return root;
}




/******************************************************************************
* PUBLIC FUNCTIONS ************************************************************
******************************************************************************/


#ifndef DLDJSET_VISIBILITY
  #define DLDJSET_DEFVIS
  #define DLDJSET_VISIBILITY
#endif


DLDJSET_VISIBILITY DLDJSET_TYPE_T DLDJSET_PUB(djset_find)(
    DLDJSET_TYPE_T const item, 
    DLDJSET_PUB(djset_t) * const set)
{
  size_t root;
  root = DLDJSET_PRI(djset_findidx)(item,set);
  return (DLDJSET_TYPE_T)(root+set->min);
}


DLDJSET_VISIBILITY DLDJSET_TYPE_T DLDJSET_PUB(djset_join)(
    DLDJSET_TYPE_T const itema, 
    DLDJSET_TYPE_T const itemb,
    DLDJSET_PUB(djset_t) * const set)
{
  size_t ia, ib, root;

  ia = DLDJSET_PRI(djset_findidx)(itema,set);
  ib = DLDJSET_PRI(djset_findidx)(itemb,set);

  DL_ASSERT(ia != ib,"Attempting to join two items from the same set\n");

  if (set->nodes[ia].rank > set->nodes[ib].rank) {
    set->nodes[ib].root = ia;
    root = ia;
  } else if (set->nodes[ia].rank < set->nodes[ib].rank) {
    set->nodes[ia].root = ib;
    root = ib;
  } else {
    set->nodes[ib].root = ia;
    root = ia;
    ++(set->nodes[ib].rank);
  }

  --(set->nsets);

  return (DLDJSET_TYPE_T)(root+set->min);
}


DLDJSET_VISIBILITY void DLDJSET_PUB(djset_add)(
    DLDJSET_TYPE_T const singleton, 
    DLDJSET_TYPE_T const group,
    DLDJSET_PUB(djset_t) * const set)
{
  size_t ia, ib;

  ia = (size_t)(singleton - set->min);
  ib = DLDJSET_PRI(djset_findidx)(group,set);

  DL_ASSERT(ia != ib,"Attempting to join two items from the same set\n");

  set->nodes[ia].root = ib;

  --(set->nsets);
}


DLDJSET_VISIBILITY void DLDJSET_PUB(djset_reset)(
    DLDJSET_PUB(djset_t) * const set)
{
  size_t i;
  const size_t n = (size_t)(set->max - set->min);

  for (i=0;i<n;++i) {
    set->nodes[i].root = DLDJSET_PRI(djset_noparent);
    set->nodes[i].rank = 0;
  }
  set->nsets = n;
}


DLDJSET_VISIBILITY DLDJSET_PUB(djset_t) * DLDJSET_PUB(djset_create)(
    DLDJSET_TYPE_T const min, 
    DLDJSET_TYPE_T const max)
{
  DLDJSET_PUB(djset_t) * set;

  DL_ASSERT(min < max, "Invalid min/max values for djset\n");

  const size_t n = (size_t)(max - min);
  set = DLDJSET_PUB(djset_alloc)(1);
  set->min = min;
  set->max = max;
  set->nodes = DLDJSET_PRI(djset_node_alloc)(n);
  DLDJSET_PUB(djset_reset)(set);

  return set;
}


DLDJSET_VISIBILITY void DLDJSET_PUB(djset_free)(
    DLDJSET_PUB(djset_t) * set)
{
  dl_free(set->nodes);
  dl_free(set);
}




#ifdef DLDJSET_DEFVIS
  #undef DLDJSET_DEFVIS
  #undef DLDJSET_VISIBILITY
#endif


#undef DLDJSET_PRE2
#undef DLDJSET_PRE1
#undef DLDJSET_PUB
#undef DLDJSET_PRI



