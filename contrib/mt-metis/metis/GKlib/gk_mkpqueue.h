/*!
\file  gk_mkpqueue.h
\brief Templates for priority queues

\date   Started 4/09/07
\author George
\version\verbatim $Id: gk_mkpqueue.h 16221 2014-02-15 20:33:26Z karypis $ \endverbatim
*/


#ifndef _GK_MKPQUEUE_H
#define _GK_MKPQUEUE_H


#define GK_MKPQUEUE(FPRFX, PQT, KVT, KT, VT, KVMALLOC, KMAX, KEY_LT)\
/*************************************************************************/\
/*! This function creates and initializes a priority queue */\
/**************************************************************************/\
PQT *FPRFX ## Create(size_t maxnodes)\
{\
  PQT *queue; \
\
  queue = (PQT *)gk_malloc(sizeof(PQT), "gk_pqCreate: queue");\
  FPRFX ## Init(queue, maxnodes);\
\
  return queue;\
}\
\
\
/*************************************************************************/\
/*! This function initializes the data structures of the priority queue */\
/**************************************************************************/\
void FPRFX ## Init(PQT *queue, size_t maxnodes)\
{\
  queue->nnodes = 0;\
  queue->maxnodes = maxnodes;\
\
  queue->heap    = KVMALLOC(maxnodes, "gk_PQInit: heap");\
  queue->locator = gk_idxsmalloc(maxnodes, -1, "gk_PQInit: locator");\
}\
\
\
/*************************************************************************/\
/*! This function resets the priority queue */\
/**************************************************************************/\
void FPRFX ## Reset(PQT *queue)\
{\
  ssize_t i;\
  ssize_t *locator=queue->locator;\
  KVT *heap=queue->heap;\
\
  for (i=((ssize_t)queue->nnodes)-1; i>=0; i--)\
    locator[heap[i].val] = -1;\
  queue->nnodes = 0;\
}\
\
\
/*************************************************************************/\
/*! This function frees the internal datastructures of the priority queue */\
/**************************************************************************/\
void FPRFX ## Free(PQT *queue)\
{\
  if (queue == NULL) return;\
  gk_free((void **)&queue->heap, &queue->locator, LTERM);\
  queue->maxnodes = 0;\
}\
\
\
/*************************************************************************/\
/*! This function frees the internal datastructures of the priority queue \
    and the queue itself */\
/**************************************************************************/\
void FPRFX ## Destroy(PQT *queue)\
{\
  if (queue == NULL) return;\
  FPRFX ## Free(queue);\
  gk_free((void **)&queue, LTERM);\
}\
\
\
/*************************************************************************/\
/*! This function returns the length of the queue */\
/**************************************************************************/\
size_t FPRFX ## Length(PQT *queue)\
{\
  return queue->nnodes;\
}\
\
\
/*************************************************************************/\
/*! This function adds an item in the priority queue */\
/**************************************************************************/\
int FPRFX ## Insert(PQT *queue, VT node, KT key)\
{\
  ssize_t i, j;\
  ssize_t *locator=queue->locator;\
  KVT *heap=queue->heap;\
\
  ASSERT2(FPRFX ## CheckHeap(queue));\
\
  ASSERT(locator[node] == -1);\
\
  i = queue->nnodes++;\
  while (i > 0) {\
    j = (i-1)>>1;\
    if (KEY_LT(key, heap[j].key)) {\
      heap[i] = heap[j];\
      locator[heap[i].val] = i;\
      i = j;\
    }\
    else\
      break;\
  }\
  ASSERT(i >= 0);\
  heap[i].key   = key;\
  heap[i].val   = node;\
  locator[node] = i;\
\
  ASSERT2(FPRFX ## CheckHeap(queue));\
\
  return 0;\
}\
\
\
/*************************************************************************/\
/*! This function deletes an item from the priority queue */\
/**************************************************************************/\
int FPRFX ## Delete(PQT *queue, VT node)\
{\
  ssize_t i, j;\
  ssize_t nnodes;\
  KT newkey, oldkey;\
  ssize_t *locator=queue->locator;\
  KVT *heap=queue->heap;\
\
  ASSERT(locator[node] != -1);\
  ASSERT(heap[locator[node]].val == node);\
\
  ASSERT2(FPRFX ## CheckHeap(queue));\
\
  i = locator[node];\
  locator[node] = -1;\
\
  if (--queue->nnodes > 0 && heap[queue->nnodes].val != node) {\
    node   = heap[queue->nnodes].val;\
    newkey = heap[queue->nnodes].key;\
    oldkey = heap[i].key;\
\
    if (KEY_LT(newkey, oldkey)) { /* Filter-up */\
      while (i > 0) {\
        j = (i-1)>>1;\
        if (KEY_LT(newkey, heap[j].key)) {\
          heap[i] = heap[j];\
          locator[heap[i].val] = i;\
          i = j;\
        }\
        else\
          break;\
      }\
    }\
    else { /* Filter down */\
      nnodes = queue->nnodes;\
      while ((j=(i<<1)+1) < nnodes) {\
        if (KEY_LT(heap[j].key, newkey)) {\
          if (j+1 < nnodes && KEY_LT(heap[j+1].key, heap[j].key))\
            j++;\
          heap[i] = heap[j];\
          locator[heap[i].val] = i;\
          i = j;\
        }\
        else if (j+1 < nnodes && KEY_LT(heap[j+1].key, newkey)) {\
          j++;\
          heap[i] = heap[j];\
          locator[heap[i].val] = i;\
          i = j;\
        }\
        else\
          break;\
      }\
    }\
\
    heap[i].key   = newkey;\
    heap[i].val   = node;\
    locator[node] = i;\
  }\
\
  ASSERT2(FPRFX ## CheckHeap(queue));\
\
  return 0;\
}\
\
\
/*************************************************************************/\
/*! This function updates the key values associated for a particular item */ \
/**************************************************************************/\
void FPRFX ## Update(PQT *queue, VT node, KT newkey)\
{\
  ssize_t i, j;\
  ssize_t nnodes;\
  KT oldkey;\
  ssize_t *locator=queue->locator;\
  KVT *heap=queue->heap;\
\
  oldkey = heap[locator[node]].key;\
\
  ASSERT(locator[node] != -1);\
  ASSERT(heap[locator[node]].val == node);\
  ASSERT2(FPRFX ## CheckHeap(queue));\
\
  i = locator[node];\
\
  if (KEY_LT(newkey, oldkey)) { /* Filter-up */\
    while (i > 0) {\
      j = (i-1)>>1;\
      if (KEY_LT(newkey, heap[j].key)) {\
        heap[i] = heap[j];\
        locator[heap[i].val] = i;\
        i = j;\
      }\
      else\
        break;\
    }\
  }\
  else { /* Filter down */\
    nnodes = queue->nnodes;\
    while ((j=(i<<1)+1) < nnodes) {\
      if (KEY_LT(heap[j].key, newkey)) {\
        if (j+1 < nnodes && KEY_LT(heap[j+1].key, heap[j].key))\
          j++;\
        heap[i] = heap[j];\
        locator[heap[i].val] = i;\
        i = j;\
      }\
      else if (j+1 < nnodes && KEY_LT(heap[j+1].key, newkey)) {\
        j++;\
        heap[i] = heap[j];\
        locator[heap[i].val] = i;\
        i = j;\
      }\
      else\
        break;\
    }\
  }\
\
  heap[i].key   = newkey;\
  heap[i].val   = node;\
  locator[node] = i;\
\
  ASSERT2(FPRFX ## CheckHeap(queue));\
\
  return;\
}\
\
\
/*************************************************************************/\
/*! This function returns the item at the top of the queue and removes\
    it from the priority queue */\
/**************************************************************************/\
VT FPRFX ## GetTop(PQT *queue)\
{\
  ssize_t i, j;\
  ssize_t *locator;\
  KVT *heap;\
  VT vtx, node;\
  KT key;\
\
  ASSERT2(FPRFX ## CheckHeap(queue));\
\
  if (queue->nnodes == 0)\
    return -1;\
\
  queue->nnodes--;\
\
  heap    = queue->heap;\
  locator = queue->locator;\
\
  vtx = heap[0].val;\
  locator[vtx] = -1;\
\
  if ((i = queue->nnodes) > 0) {\
    key  = heap[i].key;\
    node = heap[i].val;\
    i = 0;\
    while ((j=2*i+1) < (ssize_t)queue->nnodes) {\
      if (KEY_LT(heap[j].key, key)) {\
        if (j+1 < (ssize_t)queue->nnodes && KEY_LT(heap[j+1].key, heap[j].key))\
          j = j+1;\
        heap[i] = heap[j];\
        locator[heap[i].val] = i;\
        i = j;\
      }\
      else if (j+1 < (ssize_t)queue->nnodes && KEY_LT(heap[j+1].key, key)) {\
        j = j+1;\
        heap[i] = heap[j];\
        locator[heap[i].val] = i;\
        i = j;\
      }\
      else\
        break;\
    }\
\
    heap[i].key   = key;\
    heap[i].val   = node;\
    locator[node] = i;\
  }\
\
  ASSERT2(FPRFX ## CheckHeap(queue));\
  return vtx;\
}\
\
\
/*************************************************************************/\
/*! This function returns the item at the top of the queue. The item is not\
    deleted from the queue. */\
/**************************************************************************/\
VT FPRFX ## SeeTopVal(PQT *queue)\
{\
  return (queue->nnodes == 0 ? -1 : queue->heap[0].val);\
}\
\
\
/*************************************************************************/\
/*! This function returns the key of the top item. The item is not\
    deleted from the queue. */\
/**************************************************************************/\
KT FPRFX ## SeeTopKey(PQT *queue)\
{\
  return (queue->nnodes == 0 ? KMAX : queue->heap[0].key);\
}\
\
\
/*************************************************************************/\
/*! This function returns the key of a specific item */\
/**************************************************************************/\
KT FPRFX ## SeeKey(PQT *queue, VT node)\
{\
  ssize_t *locator;\
  KVT *heap;\
\
  heap    = queue->heap;\
  locator = queue->locator;\
\
  return heap[locator[node]].key;\
}\
\
\
/*************************************************************************/\
/*! This function returns the first item in a breadth-first traversal of\
    the heap whose key is less than maxwgt. This function is here due to\
    hMETIS and is not general!*/\
/**************************************************************************/\
/*\
VT FPRFX ## SeeConstraintTop(PQT *queue, KT maxwgt, KT *wgts)\
{\
  ssize_t i;\
\
  if (queue->nnodes == 0)\
    return -1;\
\
  if (maxwgt <= 1000)\
    return FPRFX ## SeeTopVal(queue);\
\
  for (i=0; i<queue->nnodes; i++) {\
    if (queue->heap[i].key > 0) {\
      if (wgts[queue->heap[i].val] <= maxwgt)\
        return queue->heap[i].val;\
    }\
    else {\
      if (queue->heap[i/2].key <= 0)\
        break;\
    }\
  }\
\
  return queue->heap[0].val;\
\
}\
*/\
\
\
/*************************************************************************/\
/*! This functions checks the consistency of the heap */\
/**************************************************************************/\
int FPRFX ## CheckHeap(PQT *queue)\
{\
  ssize_t i, j;\
  ssize_t nnodes;\
  ssize_t *locator;\
  KVT *heap;\
\
  heap    = queue->heap;\
  locator = queue->locator;\
  nnodes  = queue->nnodes;\
\
  if (nnodes == 0)\
    return 1;\
\
  if (locator[heap[0].val] != 0) {\
    printf("locator[heap[0].val] != 0\n");\
    return 0;\
  }\
  for (i=1; i<nnodes; i++) {\
    if (locator[heap[i].val] != i) {\
      printf("locator[heap[i].val] != i\n");\
      return 0;\
    }\
    if (KEY_LT(heap[i].key,heap[(i-1)/2].key)) {\
      printf("KEY_LOT(heap[i].key,heap[(i-1)/2].key)\n");\
      return 0;\
    }\
  }\
  for (i=1; i<nnodes; i++) {\
    if (KEY_LT(heap[i].key,heap[0].key)){\
      printf("KEY_LT(heap[i].key,heap[0].key)\n");\
      return 0;\
    }\
  }\
\
  for (j=i=0; i<(ssize_t)queue->maxnodes; i++) {\
    if (locator[i] != -1){\
      j++;\
    }\
  }\
  if (j != nnodes) {\
    printf("j != nnodes: %zd %zd\n",j,nnodes);\
  }\
\
  return 1;\
}\


#define GK_MKPQUEUE_PROTO(FPRFX, PQT, KT, VT)\
  PQT *  FPRFX ## Create(size_t maxnodes);\
  void   FPRFX ## Init(PQT *queue, size_t maxnodes);\
  void   FPRFX ## Reset(PQT *queue);\
  void   FPRFX ## Free(PQT *queue);\
  void   FPRFX ## Destroy(PQT *queue);\
  size_t FPRFX ## Length(PQT *queue);\
  int    FPRFX ## Insert(PQT *queue, VT node, KT key);\
  int    FPRFX ## Delete(PQT *queue, VT node);\
  void   FPRFX ## Update(PQT *queue, VT node, KT newkey);\
  VT     FPRFX ## GetTop(PQT *queue);\
  VT     FPRFX ## SeeTopVal(PQT *queue);\
  KT     FPRFX ## SeeTopKey(PQT *queue);\
  KT     FPRFX ## SeeKey(PQT *queue, VT node);\
  VT     FPRFX ## SeeConstraintTop(PQT *queue, KT maxwgt, KT *wgts);\
  int    FPRFX ## CheckHeap(PQT *queue);\


/* This is how these macros are used
GK_MKPQUEUE(gk_dkvPQ, gk_dkvPQ_t, double, gk_idx_t, gk_dkvmalloc, DBL_MAX)
GK_MKPQUEUE_PROTO(gk_dkvPQ, gk_dkvPQ_t, double, gk_idx_t)
*/


#endif
