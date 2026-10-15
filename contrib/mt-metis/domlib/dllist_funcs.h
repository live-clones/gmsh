/**
 * @file dlal_funcs.h
 * @brief Function for array lists
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright (c) 2013-2015, Dominique LaSalle
 * @version 1
 * @date 2013-10-07
 */




/* prefixing ugliness */
#define DLLIST_PRE2(prefix,suffix) prefix ## _ ## suffix
#define DLLIST_PRE1(prefix,suffix) DLLIST_PRE2(prefix,suffix)
#define DLLIST_PUB(name) DLLIST_PRE1(DLLIST_PREFIX,name)
#define DLLIST_PRI(name) DLLIST_PRE1(_,DLLIST_PRE1(DLLIST_PREFIX,name))



/******************************************************************************
* MEMORY FUNCTIONS ************************************************************
******************************************************************************/


#ifdef DLLIST_LINKED

#define DLMEM_PREFIX DLLIST_PRI(list_node)
#define DLMEM_TYPE_T DLLIST_PRI(list_node_t)
#define DLMEM_STATIC
#include "dlmem_headers.h"
#undef DLMEM_STATIC
#undef DLMEM_TYPE_T
#undef DLMEM_PREFIX

#endif


#define DLMEM_PREFIX DLLIST_PUB(list)
#define DLMEM_TYPE_T DLLIST_PUB(list_t)
#define DLMEM_STATIC
#include "dlmem_headers.h"
#undef DLMEM_STATIC
#undef DLMEM_TYPE_T
#undef DLMEM_PREFIX




/******************************************************************************
* PUBLIC FUNCTIONS ************************************************************
******************************************************************************/


#ifndef DLLIST_VISIBILITY
  #define DLLIST_DEFVIS
  #define DLLIST_VISIBILITY
#endif


#ifdef DLLIST_LINKED
DLLIST_PUB(list_t) * DLLIST_PUB(list_create)(void)
{
  DLLIST_PUB(list_t) * lst =  DLLIST_PUB(list_alloc)(1);
  lst->size = 0;
  lst->head = NULL;
  lst->tail = NULL;
  return lst;
}
#else
DLLIST_PUB(list_t) * DLLIST_PUB(list_create)(
    size_t const size)
{
  DLLIST_PUB(list_t) * lst = DLLIST_PUB(list_alloc)(1);
  lst->maxsize = size;
  lst->val = DLLIST_PUB(alloc)(lst->maxsize);
  lst->size = 0;
  lst->front = 0;
  return lst;
}
#endif


int DLLIST_PUB(list_add)(
    DLLIST_TYPE_T const item, 
    DLLIST_PUB(list_t) * const lst)
{
  #ifdef DLLIST_LINKED
  DLLIST_PRI(list_node_t) * node = DLLIST_PRI(list_node_calloc)(1);
  node->val = item;
  if (lst->size == 0) {
    lst->head = lst->tail = node;
  } else {
    node->prev = lst->tail;
    lst->tail->next = node;
    lst->tail = node;
  }
  #else
  size_t pos;
  DL_ASSERT(lst->size<lst->maxsize, \
      "Attempting to add to a full list of size "PF_SIZE_T"\n", lst->size);
  pos = (lst->front + lst->size) % lst->maxsize;
  lst->val[pos] = item;
  #endif
  ++lst->size;
  return 1;
}


int DLLIST_PUB(list_enqueue)(
    DLLIST_TYPE_T const item, 
    DLLIST_PUB(list_t) * const lst)
{
  return DLLIST_PUB(list_add)(item,lst);
}


int DLLIST_PUB(list_push)(
    DLLIST_TYPE_T const item, 
    DLLIST_PUB(list_t) * const lst)
{
  return DLLIST_PUB(list_add)(item,lst);
}


DLLIST_TYPE_T DLLIST_PUB(list_get)(
    size_t const idx, 
    DLLIST_PUB(list_t) * const lst)
{
  #ifdef DLLIST_LINKED
  size_t i;
  DLLIST_PRI(list_node_t) * node;
  if (idx > lst->size/2) {
    node = lst->tail;
    for (i=lst->size-1;i>idx;--i) {
      node = node->prev;
    }
  } else {
    node = lst->head;
    for (i=0;i<idx;++i) {
      node = node->next;
    }
  }
  return node->val;
  #else
  return lst->val[(lst->front+idx)%lst->maxsize];
  #endif
}


DLLIST_TYPE_T DLLIST_PUB(list_peek)(
    DLLIST_PUB(list_t) * const lst)
{
  #ifdef DLLIST_LINKED
  return lst->tail->val;
  #else
  return lst->val[(lst->front + lst->size -1) % lst->maxsize];
  #endif
}



DLLIST_TYPE_T DLLIST_PUB(list_front)(
    DLLIST_PUB(list_t) * const lst)
{
  #ifdef DLLIST_LINKED
  return lst->head->val;
  #else
  return lst->val[lst->front];
  #endif
}


DLLIST_TYPE_T DLLIST_PUB(list_remove)(
    size_t const idx, 
    DLLIST_PUB(list_t) * lst)
{
  DL_ASSERT(lst->size > 0, \
      "Attempt to remove item from an empty list\n");
  DLLIST_TYPE_T val;
  #ifdef DLLIST_LINKED
  size_t i;
  DLLIST_PRI(list_node_t) * node;
  if (idx > lst->size/2) {
    node = lst->tail;
    for (i=lst->size-1;i>idx;--i) {
      node = node->prev;
    }
  } else {
    node = lst->head;
    for (i=0;i<idx;++i) {
      node = node->next;
    }
  }
  val = node->val;
  /* remove node */
  if (idx > 0) {
    node->prev->next = node->next;
  } else {
    lst->head = node->next;
  }
  if (idx < lst->size-1) {
    node->next->prev = node->prev;
  } else {
    lst->tail = node->prev;
  }
  dl_free(node);
  #else
  val = lst->val[idx];
  memmove(lst->val+idx,lst->val+idx+1,(lst->size-idx-1)*sizeof(DLLIST_TYPE_T));
  #endif
  --lst->size;
  return val;
}


DLLIST_TYPE_T DLLIST_PUB(list_dequeue)(
    DLLIST_PUB(list_t) * const lst)
{
  return DLLIST_PUB(list_remove)(0,lst);
}


DLLIST_TYPE_T DLLIST_PUB(list_pop)(
    DLLIST_PUB(list_t) * const lst)
{
  return DLLIST_PUB(list_remove)(lst->size-1,lst);
}


DLLIST_TYPE_T DLLIST_PUB(list_replace)(
    DLLIST_TYPE_T const item, 
    size_t const idx,
    DLLIST_PUB(list_t) * const lst)
{
  DLLIST_TYPE_T oitem;
  #ifdef DLLIST_LINKED
  size_t i;
  DLLIST_PRI(list_node_t) * node;
  if (idx > lst->size/2) {
    node = lst->tail;
    for (i=lst->size-1;i>idx;--i) {
      node = node->prev;
    }
  } else {
    node = lst->head;
    for (i=0;i<idx;++i) {
      node = node->next;
    }
  }
  oitem = node->val;
  node->val = item;
  #else
  oitem = lst->val[(lst->front+idx)%lst->maxsize];
  #endif
  return oitem;
}


size_t DLLIST_PUB(list_clear)(
    DLLIST_PUB(list_t) * const lst)
{
  size_t size = lst->size;
  #ifdef DLLIST_LINKED
  while (lst->size > 0) {
    DLLIST_PUB(list_pop)(lst);
  }
  #else
  lst->size = lst->front = 0;
  #endif
  return size;
}

#if (!defined(DLLIST_DLTYPE) || DLLIST_DLTYPE != DLTYPE_STRUCT) || \
    defined(DLLIST_EQUALSFUNCTION)
ssize_t DLLIST_PUB(list_indexof)(
    DLLIST_TYPE_T const val, 
    DLLIST_PUB(list_t) const * const lst)
{
  size_t i;
  #ifdef DLLIST_LINKED
  i = 0;
  DLLIST_PRI(list_node_t) * node = lst->head;
  #if defined(DLLIST_DLTYPE) && DLLIST_DLTYPE == DLTYPE_STRUCT
  while (!DLLIST_EQUALSFUNCTION(node->val,val)) {
  #else
  while (node->val != val) {
  #endif
    if (node->next != NULL) {
      node = node->next; 
      ++i;
    } else {
      break;
    }
  }
  #if defined(DLLIST_DLTYPE) && DLLIST_DLTYPE == DLTYPE_STRUCT
  if (DLLIST_EQUALSFUNCTION(node->val,val)) {
  #else
  if (node->val == val) {
  #endif
    return (ssize_t)i;
  }
  #else
  for (i=0;i<lst->size;++i) {
    #if defined(DLLIST_DLTYPE) && DLLIST_DLTYPE == DLTYPE_STRUCT
    if (DLLIST_EQUALSFUNCTION(lst->val[(i+lst->front)%lst->maxsize],val)) {
    #else
    if (lst->val[(i+lst->front)%lst->maxsize] == val) {
    #endif
      return (ssize_t)i;
    }
  }
  #endif
  return -1;
}
#endif


void DLLIST_PUB(list_free)(
    DLLIST_PUB(list_t) * lst)
{
  #ifdef DLLIST_LINKED
  while (lst->size > 0) {
    DLLIST_PUB(list_pop)(lst);
  }
  #else
  dl_free(lst->val);
  #endif
  dl_free(lst);
}


#ifdef DLLIST_ARRAY

size_t DLLIST_PUB(list_expand)(
    DLLIST_PUB(list_t) * const lst,
    size_t const newsize)
{
  DL_ASSERT(lst->front<lst->maxsize, \
      "The front of the list is greater than the max size\n");
  size_t j;
  DLLIST_TYPE_T * newval;
  
  newval = DLLIST_PUB(alloc)(newsize);

  if (lst->front + lst->size <= lst->maxsize) {
    DLLIST_PUB(copy)(newval,lst->val+lst->front,lst->size);
  } else {
    j = lst->maxsize - lst->front;
    DLLIST_PUB(copy)(newval,lst->val+lst->front,j);
    DLLIST_PUB(copy)(newval+j,lst->val,lst->size-j);
  }

  dl_free(lst->val);
  lst->val = newval;
  lst->maxsize = newsize;
  lst->front = 0;

  return lst->size;
}

#endif




#ifdef DLLIST_DEFVIS
  #undef DLLIST_DEFVIS
  #undef DLLIST_VISIBILITY
#endif


#undef DLLIST_PRE2
#undef DLLIST_PRE1
#undef DLLIST_PUB
#undef DLLIST_PRI


