/**
 * @file dlpq_funcs.h
 * @brief Functions for priority queues
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright (c) 2013-2015, Dominique LaSalle
 * @version 1
 * @date 2013-10-04
 */




/* prefixing ugliness */
#define DLPQ_PRE2(prefix,suffix) prefix ## _ ## suffix
#define DLPQ_PRE1(prefix,suffix) DLPQ_PRE2(prefix,suffix)
#define DLPQ_PUB(name) DLPQ_PRE1(DLPQ_PREFIX,name)
#define DLPQ_PRI(name) DLPQ_PRE1(_,DLPQ_PRE1(DLPQ_PREFIX,name))


#ifndef DLPQ_VISIBILITY
  #define DLPQ_VISIBILITY
  #define DLPQ_DEFVIS
#endif




/******************************************************************************
* MACROS **********************************************************************
******************************************************************************/


#define __DL_HEAP_EMPTY_SLOT (-1)
#define __LEFTCHILDINDEX(i) ((2*i)+1)
#define __RIGHTCHILDINDEX(i) ((2*i)+2)
#define __PARENTINDEX(i) ((i-1)>>1)
#define __ISLESS(a,b) (a < b)
#define __ISMORE(a,b) (a > b)
#define __ISLESSKV(a,b) (a.key < b.key)
#define __ISMOREKV(a,b) (a.key > b.key)
#define __ADJINDEX(i,q) \
  (((ssize_t)i) - ((ssize_t)((q)->min)))





/******************************************************************************
* META MACROS *****************************************************************
******************************************************************************/


#define __HEAP_FIX_DOWN(i,val,heap,isorder,move,set) \
  do { \
    size_t k,j; \
    while (1) { \
      set(i,val,heap); \
      j = __LEFTCHILDINDEX(i); \
      k = __RIGHTCHILDINDEX(i); \
      if (j < heap->size) { \
        if (k < heap->size && !isorder(val,heap->elements[k]) &&  \
            !isorder(heap->elements[j],heap->elements[k])) { \
          move(i,k,heap); \
          i = k; \
        } else if (!isorder(val,heap->elements[j])) { \
          move(i,j,heap); \
          i = j; \
        } else { \
          break; \
        } \
      } else { \
        break; \
      } \
    } \
  } while(0)


#define __HEAP_FIX_UP(i,val,heap,isorder,move,set) \
  do { \
    size_t j =__PARENTINDEX(i); \
    while (i > 0 && !isorder(heap->elements[j],val)) { \
      move(i,j,heap); \
      i = j; \
      j = __PARENTINDEX(i); \
    } \
    set(i,val,heap); \
  } while (0)




/******************************************************************************
* MEMORY FUNCTIONS ************************************************************
******************************************************************************/


#define DLMEM_PREFIX DLPQ_PRI(pq_kv)
#define DLMEM_TYPE_T DLPQ_PRI(pq_kv_t)
#define DLMEM_STATIC
#include "dlmem_headers.h"
#undef DLMEM_STATIC
#undef DLMEM_TYPE_T
#undef DLMEM_PREFIX




/******************************************************************************
* CONSTANTS *******************************************************************
******************************************************************************/


static size_t const DLPQ_PRI(pq_empty_slot) = (size_t)-1;




/******************************************************************************
* PRIVATE FUNCTIONS ***********************************************************
******************************************************************************/


#ifdef DLPQ_USE_HT

#define DLHT_PREFIX DLPQ_PRI(pq)
#define DLHT_KEY_T DLPQ_VAL_T
#define DLHT_VAL_T size_t
#define DLHT_STATIC 1
#include "dlht_headers.h"
#undef DLHT_STATIC
#undef DLHT_VAL_T
#undef DLHT_KEY_T
#undef DLHT_PREFIX

#endif


static inline void DLPQ_PRI(moveindexful)(
    size_t const i,
    size_t const j,
    DLPQ_PUB(pq_t) * const h) 
{
  h->elements[i] = h->elements[j];
  #ifndef DLPQ_USE_HT
  h->index[__ADJINDEX(h->elements[j].val,h)] = i;
  #else
  DLPQ_PRI(pq_ht_put)(h->elements[j].val,i,h->ht);
  #endif
}


static inline void DLPQ_PRI(setindexful)(
    size_t const i,
    DLPQ_PRI(pq_kv_t) const v,
    DLPQ_PUB(pq_t) * const h)
{
  h->elements[i] = v;
  #ifndef DLPQ_USE_HT
  h->index[__ADJINDEX(v.val,h)] = i;
  #else
  DLPQ_PRI(pq_ht_put)(v.val,i,h->ht);
  #endif
}




/******************************************************************************
* PUBLIC FUNCTIONS ************************************************************
******************************************************************************/


#ifndef DLPQ_USE_HT
DLPQ_VISIBILITY DLPQ_PUB(pq_t) * DLPQ_PUB(pq_create)(
    DLPQ_VAL_T const min, 
    DLPQ_VAL_T const max)
{
  DLPQ_PUB(pq_t) * q;

  size_t const n = (size_t)(((ssize_t)max) - ((ssize_t)min));

  q = malloc(sizeof(DLPQ_PUB(pq_t)));

  q->min = min;
  q->max = max;
  q->maxsize = n;
  q->size = 0;
  q->elements = DLPQ_PRI(pq_kv_alloc)(q->maxsize);
  q->index = size_init_alloc(DLPQ_PRI(pq_empty_slot),q->maxsize);

  return q;
}
#else
DLPQ_VISIBILITY DLPQ_PUB(pq_t) * DLPQ_PUB(pq_create)(
    size_t const n)
{
  DLPQ_PUB(pq_t) * q;

  q = malloc(sizeof(DLPQ_PUB(pq_t)));

  q->maxsize = n;
  q->size = 0;
  q->elements = DLPQ_PRI(pq_kv_alloc)(q->maxsize);

  q->ht = DLPQ_PRI(pq_ht_create)(n,n);

  return q;
}
#endif


DLPQ_VISIBILITY void DLPQ_PUB(pq_push)(
    DLPQ_KEY_T const key, 
    DLPQ_VAL_T const val, 
    DLPQ_PUB(pq_t) * const q)
{
  #ifndef DLPQ_USE_HT
  DL_ASSERT(val >= q->min,"Attempting to add value below minimum to "
      "priority queue\n");
  DL_ASSERT(val < q->max,"Attempting to add value above maximum to "
      "priority queue\n");
  DL_ASSERT(q->index[__ADJINDEX(val,q)] == DLPQ_PRI(pq_empty_slot),
      "Value already exists in priority queue\n");
  #else
  DL_ASSERT(q->size < q->maxsize,"Adding to full queue");
  #endif

  DLPQ_PRI(pq_kv_t) kv;

  kv.key = key;
  kv.val = val;
  size_t i = q->size++;

  #if defined(DLPQ_MIN)
  __HEAP_FIX_UP(i,kv,q,__ISLESSKV,DLPQ_PRI(moveindexful), \
      DLPQ_PRI(setindexful));
  #else
  __HEAP_FIX_UP(i,kv,q,__ISMOREKV,DLPQ_PRI(moveindexful), \
      DLPQ_PRI(setindexful));
  #endif
}


DLPQ_VISIBILITY DLPQ_VAL_T DLPQ_PUB(pq_pop)(
    DLPQ_PUB(pq_t) * const q)
{
  DL_ASSERT(q->size > 0,"Trying to pop() from an empty queue\n");

  size_t i;
  
  i = 0;
  DLPQ_PRI(pq_kv_t) kv = q->elements[i];
  DLPQ_PRI(pq_kv_t) val = q->elements[--q->size];

  #if defined(DLPQ_MIN)
  __HEAP_FIX_DOWN(i,val,q,__ISLESSKV,DLPQ_PRI(moveindexful), \
      DLPQ_PRI(setindexful));
  #else
  __HEAP_FIX_DOWN(i,val,q,__ISMOREKV,DLPQ_PRI(moveindexful), \
      DLPQ_PRI(setindexful));
  #endif

  #ifndef DLPQ_USE_HT
  q->index[__ADJINDEX(kv.val,q)] = DLPQ_PRI(pq_empty_slot);
  #else
  DLPQ_PRI(pq_ht_remove)(kv.val,q->ht);
  #endif

  return kv.val;
}


DLPQ_VISIBILITY DLPQ_VAL_T DLPQ_PUB(pq_peek)(
    DLPQ_PUB(pq_t) const * const q)
{
  DL_ASSERT(q->size > 0,"Attempting to look at first element of an empty " \
      "priority queue\n");

  return q->elements[0].val;
}


DLPQ_VISIBILITY DLPQ_KEY_T DLPQ_PUB(pq_top)(
    DLPQ_PUB(pq_t) const * const q)
{
  DL_ASSERT(q->size > 0,"Attempting to look at first element of an empty " \
      "priority queue\n");

  return q->elements[0].key;
}


DLPQ_VISIBILITY DLPQ_KEY_T DLPQ_PUB(pq_priority)(
    DLPQ_VAL_T const val,
    DLPQ_PUB(pq_t) const * const q)
{
  size_t i;

  #ifndef DLPQ_USE_HT
  DL_ASSERT(q->index[__ADJINDEX(val,q)] != DLPQ_PRI(pq_empty_slot), \
      "Can't get priority of value (%zu) not in priority queue\n",(size_t)val);

  i = q->index[__ADJINDEX(val,q)];
  #else
  i = DLPQ_PRI(pq_ht_get)(val,q->ht);
  #endif

  return q->elements[i].key;
}


DLPQ_VISIBILITY void DLPQ_PUB(pq_update)(
    DLPQ_KEY_T const key, 
    DLPQ_VAL_T const val, 
    DLPQ_PUB(pq_t) * const q)
{
  size_t i; 
  DLPQ_PRI(pq_kv_t) kv;

  #ifndef DLPQ_USE_HT
  DL_ASSERT(q->index[__ADJINDEX(val,q)] != DLPQ_PRI(pq_empty_slot), \
      "Can't update value (%zu) not in priority queue\n",(size_t)val);

  i = q->index[__ADJINDEX(val,q)];
  #else
  i = DLPQ_PRI(pq_ht_get)(val,q->ht);
  #endif

  kv.key = key;
  kv.val = val;

  #if defined(DLPQ_MIN)
  if (__ISLESSKV(kv,q->elements[i])) { /* goes up */
    __HEAP_FIX_UP(i,kv,q,__ISLESSKV,DLPQ_PRI(moveindexful), \
        DLPQ_PRI(setindexful));
  } else {
    __HEAP_FIX_DOWN(i,kv,q,__ISLESSKV,DLPQ_PRI(moveindexful), \
        DLPQ_PRI(setindexful));
  } /* otherwise do nothing */
  #else
  if (__ISMOREKV(kv,q->elements[i])) { /* goes up */
    __HEAP_FIX_UP(i,kv,q,__ISMOREKV,DLPQ_PRI(moveindexful), \
        DLPQ_PRI(setindexful));
  } else {
    __HEAP_FIX_DOWN(i,kv,q,__ISMOREKV,DLPQ_PRI(moveindexful), \
        DLPQ_PRI(setindexful));
  } /* otherwise do nothing */
  #endif
}


DLPQ_VISIBILITY void DLPQ_PUB(pq_updateadd)(
    DLPQ_KEY_T const key, 
    DLPQ_VAL_T const val, 
    DLPQ_PUB(pq_t) * const q)
{
  size_t i; 
  DLPQ_PRI(pq_kv_t) kv;

  #ifndef DLPQ_USE_HT
  DL_ASSERT(q->index[__ADJINDEX(val,q)] != DLPQ_PRI(pq_empty_slot), \
      "Can't update value (%zu) not in priority queue\n",(size_t)val);

  i = q->index[__ADJINDEX(val,q)];
  #else
  i = DLPQ_PRI(pq_ht_get)(val,q->ht);
  #endif

  kv.key = key + q->elements[i].key;
  kv.val = val;

  #if defined(DLPQ_MIN)
  if (__ISLESSKV(kv,q->elements[i])) { /* goes up */
    __HEAP_FIX_UP(i,kv,q,__ISLESSKV,DLPQ_PRI(moveindexful), \
        DLPQ_PRI(setindexful));
  } else {
    __HEAP_FIX_DOWN(i,kv,q,__ISLESSKV,DLPQ_PRI(moveindexful), \
        DLPQ_PRI(setindexful));
  } /* otherwise do nothing */
  #else
  if (__ISMOREKV(kv,q->elements[i])) { /* goes up */
    __HEAP_FIX_UP(i,kv,q,__ISMOREKV,DLPQ_PRI(moveindexful), \
        DLPQ_PRI(setindexful));
  } else {
    __HEAP_FIX_DOWN(i,kv,q,__ISMOREKV,DLPQ_PRI(moveindexful), \
        DLPQ_PRI(setindexful));
  } /* otherwise do nothing */
  #endif
}


DLPQ_VISIBILITY void DLPQ_PUB(pq_remove)(
    DLPQ_VAL_T const v,
    DLPQ_PUB(pq_t) * const q)
{
  size_t i;
  DLPQ_PRI(pq_kv_t) val;

  val = q->elements[--q->size];

  #ifndef DLPQ_USE_HT
  DL_ASSERT(q->index[__ADJINDEX(v,q)] !=  DLPQ_PRI(pq_empty_slot), \
      "Can't remove value not in priority queue\n");

  i = q->index[__ADJINDEX(v,q)];
  #else
  i = DLPQ_PRI(pq_ht_get)(v,q->ht);
  #endif

  #if defined(DLPQ_MIN)
  if (val.key < q->elements[i].key) {
    __HEAP_FIX_UP(i,val,q,__ISLESSKV,DLPQ_PRI(moveindexful), \
        DLPQ_PRI(setindexful));
  } else {
    __HEAP_FIX_DOWN(i,val,q,__ISLESSKV,DLPQ_PRI(moveindexful), \
        DLPQ_PRI(setindexful));
  }
  #else
  if (val.key > q->elements[i].key) {
    __HEAP_FIX_UP(i,val,q,__ISMOREKV,DLPQ_PRI(moveindexful), \
        DLPQ_PRI(setindexful));
  } else {
    __HEAP_FIX_DOWN(i,val,q,__ISMOREKV,DLPQ_PRI(moveindexful), \
        DLPQ_PRI(setindexful));
  }
  #endif

  #ifndef DLPQ_USE_HT
  q->index[__ADJINDEX(v,q)] = DLPQ_PRI(pq_empty_slot);
  #else
  DLPQ_PRI(pq_ht_remove)(v,q->ht);
  #endif
}


DLPQ_VISIBILITY void DLPQ_PUB(pq_clear)(
    DLPQ_PUB(pq_t) * const q)
{
  DLPQ_VAL_T v;

  #ifndef DLPQ_USE_HT
  if (q->size > 0.125 * q->maxsize) {
    size_set(q->index,DLPQ_PRI(pq_empty_slot),q->maxsize);
    q->size = 0;
  } else {
    while (q->size>0) {
      v = q->elements[--q->size].val;
      q->index[__ADJINDEX(v,q)] = DLPQ_PRI(pq_empty_slot);
    }
  }
  #else
  if (q->size > 0.25 * q->maxsize) {
    DLPQ_PRI(pq_ht_clear)(q->ht);
    q->size = 0;
  } else {
    while (q->size>0) {
      v = q->elements[--q->size].val;
      DLPQ_PRI(pq_ht_remove)(v,q->ht);
    }
  }

  #endif
}


DLPQ_VISIBILITY int DLPQ_PUB(pq_contains)(
    DLPQ_VAL_T const v, 
    DLPQ_PUB(pq_t) * const q)
{
  #ifndef DLPQ_USE_HT
  return q->index[__ADJINDEX(v,q)] != DLPQ_PRI(pq_empty_slot);
  #else
  return DLPQ_PRI(pq_ht_get)(v,q->ht) != DLPQ_PRI(pq_ht_null_value);
  #endif
}


DLPQ_VISIBILITY void DLPQ_PUB(pq_free)(
    DLPQ_PUB(pq_t) * q)
{
  dl_free(q->elements);
  #ifndef DLPQ_USE_HT
  dl_free(q->index);
  #else
  DLPQ_PRI(pq_ht_free)(q->ht);
  #endif
  dl_free(q);
}


#ifdef DLPQ_DEFVIS
  #undef DLPQ_VISIBILITY
  #undef DLPQ_DEFVIS
#endif


#undef DLPQ_PRE2
#undef DLPQ_PRE1
#undef DLPQ_PUB
#undef DLPQ_PRI



