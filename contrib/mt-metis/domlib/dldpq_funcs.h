/**
 * @file dldpq_funcs.h
 * @brief Functions for discrete priority queues
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright (c) 2013-2015, Dominique LaSalle
 * @version 1
 * @date 2013-08-21
 */




/* this is ugly but neccessary */
#define DLDPQ_PRE2(prefix,suffix) prefix ## _ ## suffix
#define DLDPQ_PRE1(prefix,suffix) DLDPQ_PRE2(prefix,suffix)
#define DLDPQ_PUB(name) DLDPQ_PRE1(DLDPQ_PREFIX,name)
#define DLDPQ_PRI(name) DLDPQ_PRE1(_,DLDPQ_PRE1(DLDPQ_PREFIX,name))




/******************************************************************************
* MEMORY FUNCTIONS ************************************************************
******************************************************************************/


#define DLMEM_PREFIX DLDPQ_PRI(dldpq_node)
#define DLMEM_TYPE_T DLDPQ_PRI(dldpq_node_t)
#include "dlmem_funcs.h"
#undef DLMEM_PREFIX
#undef DLMEM_TYPE_T


#define DLMEM_PREFIX DLDPQ_PRI(dldpq_bucket)
#define DLMEM_TYPE_T DLDPQ_PRI(dldpq_bucket_t)
#include "dlmem_funcs.h"
#undef DLMEM_PREFIX
#undef DLMEM_TYPE_T


#define DLMEM_PREFIX DLDPQ_PUB(dldpq)
#define DLMEM_TYPE_T DLDPQ_PUB(dldpq_t)
#include "dlmem_funcs.h"
#undef DLMEM_PREFIX
#undef DLMEM_TYPE_T




/******************************************************************************
* CONSTANTS *******************************************************************
******************************************************************************/


static const size_t DLDPQ_PRI(EMPTY) = (size_t)-1;
static void * const DLDPQ_PRI(FIRSTNODE) = (void*)1;
static void * const DLDPQ_PRI(REMOVEDNODE) = (void*)2;
static const size_t DLDPQ_PRI(MIN_PSEUDO_SHUFFLE) = 64;



/******************************************************************************
* PRIVATE FUNCTIONS ***********************************************************
******************************************************************************/

#ifdef DLDPQ_VISIBILITY
  /* we call it out of order for assertions */
  static int DLDPQ_PUB(dldpq_check)(DLDPQ_PUB(dldpq_t) * dpq);
#endif


static void DLDPQ_PRI(dldpq_bucket_remove)(
    DLDPQ_PRI(dldpq_bucket_t) * const bucket, DLDPQ_PUB(dldpq_t) * const dpq)
{
  if (bucket->next == NULL && bucket->prev == NULL) {
    DL_ASSERT(dpq->bmin == (size_t)bucket->key,"Found bucket with no "
        "previous, key = "PF_SIZE_T" but bmin = "PF_SIZE_T"\n",
        (size_t)bucket->key,dpq->bmin);
    DL_ASSERT(dpq->bmax == (size_t)bucket->key,"Found bucket with no next, "
        "key = "PF_SIZE_T" but bmax = "PF_SIZE_T"\n",(size_t)bucket->key,
        dpq->bmax);
    DL_ASSERT(bucket->start == NULL,"Attempt to remove a non-empty bucket\n");
    /* we're empty */
    dpq->bmin = DLDPQ_PRI(EMPTY);
    dpq->bmax = DLDPQ_PRI(EMPTY);
  } else if (bucket->prev == NULL) {
    DL_ASSERT(dpq->bmin == (size_t)bucket->key,"Found bucket with no "
        "previous, key = "PF_SIZE_T" but bmin = "PF_SIZE_T"\n",
        (size_t)bucket->key,dpq->bmin);
    /* if its the first bucket */
    bucket->next->prev = NULL;
    dpq->bmin = (size_t)bucket->next->key;
  } else if (bucket->next == NULL) {
    DL_ASSERT(dpq->bmax == (size_t)bucket->key,"Found bucket with no next, "
        "key = "PF_SIZE_T" but bmax = "PF_SIZE_T"\n",(size_t)bucket->key,
        dpq->bmax);
    /* if its teh last bucket */
    bucket->prev->next = NULL;
    dpq->bmax = (size_t)bucket->prev->key;
    DL_ASSERT(dpq->bmax < (size_t)(dpq->kmax - dpq->kmin),"Invalid bmax "
        "assigned during remvoal of "PF_SIZE_T"--"PF_SIZE_T" with "PF_SIZE_T
        " buckets\n",(size_t)(bucket->key-dpq->kmin),dpq->bmax,
        (size_t)(dpq->kmax - dpq->kmin));
  } else {
    bucket->prev->next = bucket->next;
    bucket->next->prev = bucket->prev;
  }

  bucket->next = NULL;
  bucket->prev = NULL;
}


static void DLDPQ_PRI(dldpq_node_remove)(DLDPQ_PRI(dldpq_node_t) * const node, 
    DLDPQ_PUB(dldpq_t) * const dpq)
{
  size_t k;
  DLDPQ_PRI(dldpq_bucket_t) * bucket;

  DL_ASSERT(DLDPQ_PUB(dldpq_check)(dpq) == 1,"Attempting a remove a node from "
      "an invalid DLDPQ\n");
  DL_ASSERT(node->prev != DLDPQ_PRI(REMOVEDNODE),"Attempting to remove a node "
      "marked as removed ["PF_SIZE_T":"PF_SIZE_T"]\n",(size_t)node->key,
      (size_t)node->val);

  k = (size_t)node->key; 
  bucket = dpq->buckets+k;

  if (bucket->start == node) {
    DL_ASSERT(node->prev == DLDPQ_PRI(FIRSTNODE),"Starting node for bucket "
        PF_SIZE_T" is not marked as first\n",(size_t)bucket->key);
    /* it's at the start */ 
    if (node->next == NULL) { 
      /* it's the only node -- remove it */ 
      bucket->start = NULL;
      DLDPQ_PRI(dldpq_bucket_remove)(bucket,dpq);
    } else { 
      /* it has nodes after it */ 
      node->next->prev = DLDPQ_PRI(FIRSTNODE); 
    } 
    bucket->start = node->next; 
  } else { 
    DL_ASSERT(node->prev != DLDPQ_PRI(FIRSTNODE),"Non-starting node for "
        "bucket "PF_SIZE_T" is marked as first\n",(size_t)bucket->key);
    /* it's not at the start */ 
    if (node->next == NULL) { 
      /* it's the last node */ 
    } else { 
      /* it has nodes after it */ 
      node->next->prev = node->prev; 
    } 
    DL_ASSERT(node->prev != NULL,"Node ["PF_SIZE_T":"PF_SIZE_T"] is not at "
        "the start of bucket "PF_SIZE_T" but has null 'prev' pointer\n",
        (size_t)node->key,(size_t)node->val,k); 
    node->prev->next = node->next; 
  } 

  node->prev = DLDPQ_PRI(REMOVEDNODE);

  DL_ASSERT(DLDPQ_PUB(dldpq_check)(dpq) == 1,"Invalid DLDPQ after removing "
      "node with key = "PF_SIZE_T"\n",(size_t)k);
}


static void DLDPQ_PRI(dldpq_bucket_addnext)(
    DLDPQ_PRI(dldpq_bucket_t) * newbucket, 
    DLDPQ_PRI(dldpq_bucket_t) * prevbucket, DLDPQ_PUB(dldpq_t) * dpq)
{
  if (prevbucket == NULL) { /* must be the last bucket */
    newbucket->prev = NULL;
    if (dpq->bmin != DLDPQ_PRI(EMPTY)) {
      newbucket->next = dpq->buckets + dpq->bmin;
    } else {
      newbucket->next = NULL;
    }
    dpq->bmin = (size_t)newbucket->key;
  } else {
    newbucket->prev = prevbucket;
    newbucket->next = prevbucket->next;
    prevbucket->next = newbucket;     
  }

  if (((size_t)newbucket->key) > dpq->bmax || dpq->bmax == DLDPQ_PRI(EMPTY)) {
    /* we're adding a new top bucket */
    dpq->bmax = (size_t)newbucket->key;
    DL_ASSERT(newbucket->next == NULL,"New max bucket has next pointer\n");
    DL_ASSERT(dpq->bmax < (size_t)(dpq->kmax - dpq->kmin),"Invalid bmax "
        "assigned during addition of "PF_SIZE_T"--"PF_SIZE_T" with "PF_SIZE_T
        " buckets\n",(size_t)(newbucket->key-dpq->kmin),dpq->bmax,
        (size_t)(dpq->kmax - dpq->kmin));
  } else {
    newbucket->next->prev = newbucket;
  }
}


static void DLDPQ_PRI(dldpq_bucket_moveup)(
    DLDPQ_PRI(dldpq_node_t) * const node, DLDPQ_PUB(dldpq_t) * const dpq)
{
  DLDPQ_PRI(dldpq_bucket_t) * oldbucket, * newbucket, * prevbucket;

  DL_ASSERT(DLDPQ_PUB(dldpq_check)(dpq) == 1,"Attempting to move a node in an "
      "invalid DLDPQ\n");

  oldbucket = dpq->buckets+node->key;
  newbucket = oldbucket+1;

  DL_ASSERT(oldbucket == dpq->buckets+oldbucket->key,"Bad key on old "
      "bucket\n");
  DL_ASSERT(newbucket == dpq->buckets+newbucket->key,"Bad key on new "
      "bucket\n");

  /* remove it from its current location */ 
  prevbucket = oldbucket->prev;
  DLDPQ_PRI(dldpq_node_remove)(node,dpq);
  if (oldbucket->start != NULL) {
    prevbucket = oldbucket;
  }

  if (newbucket->start == NULL) { 
    /* the bucket is empty, so the node doesn't point to anyone */ 
    DLDPQ_PRI(dldpq_bucket_addnext)(newbucket,prevbucket,dpq);
    node->next = NULL; 
  } else { 
    /* the bucket is not empty */ 
    node->next = newbucket->start; 
    newbucket->start->prev = node; 
  } 
  node->key = newbucket->key;
  newbucket->start = node; 
  node->prev = DLDPQ_PRI(FIRSTNODE);

  DL_ASSERT(DLDPQ_PUB(dldpq_check)(dpq) == 1,"Invalid DLDPQ after increment "
      "a node with k = "PF_SIZE_T" and v = "PF_SIZE_T" from bucket "PF_SIZE_T
      " to "PF_SIZE_T"\n",(size_t)node->key,(size_t)node->val,
      (size_t)oldbucket->key,(size_t)newbucket->key);
}


static void DLDPQ_PRI(dldpq_bucket_addprev)(
    DLDPQ_PRI(dldpq_bucket_t) * newbucket, 
    DLDPQ_PRI(dldpq_bucket_t) * nextbucket, DLDPQ_PUB(dldpq_t) * dpq)
{
  if (nextbucket == NULL) { 
    newbucket->next = NULL;
    if (dpq->bmax != DLDPQ_PRI(EMPTY)) {
      newbucket->prev = dpq->buckets + dpq->bmax;
    } else {
      newbucket->prev = NULL;
    }
    dpq->bmax = (size_t)newbucket->key;
  } else {
    newbucket->next = nextbucket;     
    newbucket->prev = nextbucket->prev;
    nextbucket->prev = newbucket;
  }

  if (((size_t)newbucket->key) < dpq->bmin || dpq->bmin == DLDPQ_PRI(EMPTY)) {
    /* we're adding a new top bucket */
    dpq->bmin = (size_t)newbucket->key;
    DL_ASSERT(newbucket->prev == NULL,"New min bucket has prev pointer\n");
    DL_ASSERT(dpq->bmin < (size_t)(dpq->kmax - dpq->kmin),"Invalid bmin "
        "assigned during addition of "PF_SIZE_T"--"PF_SIZE_T" with "PF_SIZE_T
        " buckets\n",(size_t)(newbucket->key-dpq->kmin),dpq->bmin,
        (size_t)(dpq->kmax - dpq->kmin));

  } else {
    newbucket->prev->next = newbucket;
  }
}


static void DLDPQ_PRI(dldpq_bucket_movedown)(
    DLDPQ_PRI(dldpq_node_t) * const node, DLDPQ_PUB(dldpq_t) * const dpq)
{
  DLDPQ_PRI(dldpq_bucket_t) * oldbucket, * newbucket, * nextbucket;

  DL_ASSERT(DLDPQ_PUB(dldpq_check)(dpq) == 1,"Attempting to move a node in an "
      "invalid DLDPQ\n");

  oldbucket = dpq->buckets + node->key;
  newbucket = oldbucket-1;

  DL_ASSERT(oldbucket == dpq->buckets+oldbucket->key,"Bad key on old "
      "bucket\n");
  DL_ASSERT(newbucket == dpq->buckets+newbucket->key,"Bad key on new "
      "bucket\n");

  /* remove it from its current location */ 
  nextbucket = oldbucket->next;
  DLDPQ_PRI(dldpq_node_remove)(node,dpq);
  if (oldbucket->start != NULL) {
    nextbucket = oldbucket;
  }

  if (newbucket->start == NULL) { 
    /* the bucket is empty, so the node doesn't point to anyone */ 
    DLDPQ_PRI(dldpq_bucket_addprev)(newbucket,nextbucket,dpq);
    node->next = NULL; 
  } else { 
    /* the bucket is not empty */ 
    node->next = newbucket->start; 
    newbucket->start->prev = node; 
  } 
  node->key = newbucket->key;
  newbucket->start = node; 
  node->prev = DLDPQ_PRI(FIRSTNODE);

  DL_ASSERT(DLDPQ_PUB(dldpq_check)(dpq) == 1,"Invalid DLDPQ after decrement "
      "a node with k = "PF_SIZE_T" and v = "PF_SIZE_T"\n",(size_t)node->key,
      (size_t)node->val);
}


/******************************************************************************
* DLDPQ_PUBLIC FUNCTIONS ******************************************************
******************************************************************************/


#ifndef DLDPQ_VISIBILITY
  #define DLDPQ_DEFVIS
  #define DLDPQ_VISIBILITY
#endif


/**
 * @brief Check the state of the DLDPQ and ensure that it is valid.
 *
 * @param DLDPQ_PUB(dldpq_t) dpq
 *
 * @return 0 if it is invalid, 1 other wise
 */
DLDPQ_VISIBILITY int DLDPQ_PUB(dldpq_check)(DLDPQ_PUB(dldpq_t) * dpq)
{
  size_t k, j;
  DLDPQ_PRI(dldpq_bucket_t) * bucket;
  DLDPQ_PRI(dldpq_node_t) * node;
  const size_t n = (size_t)(dpq->kmax - dpq->kmin);

  if (dpq->bmax == DLDPQ_PRI(EMPTY)) {
    if (dpq->bmin != DLDPQ_PRI(EMPTY)) {
      eprintf("bmax set to DLDPQ_PRI(EMPTY), but bmin set to "PF_SIZE_T
          ", kmin = "PF_SSIZE_T" and kmax = "PF_SSIZE_T"\n",(size_t)dpq->bmin,
          (ssize_t)dpq->kmin,(ssize_t)dpq->kmax);
      return 0;
    }
  } else if (dpq->bmax > (size_t)(dpq->kmax - dpq->kmin)) {
    eprintf("Invalid bmax of "PF_SIZE_T" with "PF_SIZE_T" buckets\n",dpq->bmax,
        (size_t)(dpq->kmax - dpq->kmin));
    return 0;
  }

  for (k=0;k<n;++k) {
    bucket = dpq->buckets+k;
    /* check bucket info */
    if (k != (size_t)bucket->key) {
      eprintf("Bukcet with wrong key buckets["PF_SIZE_T"]->key = "PF_SIZE_T
          "\n",k,(size_t)bucket->key);
      return 0;
    } else if (k < dpq->bmin) {
      if (bucket->start != NULL) {
        eprintf("Non-empty bucket ("PF_SIZE_T", with starting node ["PF_SIZE_T
            ":"PF_SIZE_T"]) before bmin ("PF_SIZE_T")\n",k,
            (size_t)bucket->start->key,(size_t)bucket->start->val,dpq->bmin);
        return 0;
      } else if (bucket->prev != NULL || bucket->next != NULL) {
        eprintf("Bucket ("PF_SIZE_T") below bmin ("PF_SIZE_T") with prev or "
            "next pointers\n",k,dpq->bmin);
        return 0;
      }
    } else if (k > dpq->bmax) {
      if (bucket->start != NULL) {
        eprintf("Non-empty bucket ("PF_SIZE_T", with starting node ["PF_SIZE_T
            ":"PF_SIZE_T"]) after bmax ("PF_SIZE_T")\n",k,
            (size_t)bucket->start->key,(size_t)bucket->start->val,dpq->bmax);
        return 0;
      } else if (bucket->prev != NULL || bucket->next != NULL) {
        eprintf("Bucket ("PF_SIZE_T") below bmin ("PF_SIZE_T") with prev or "
            "next pointers\n",k,dpq->bmax);
        return 0;
      }
    }
    /* check node info */
    node = bucket->start;
    j = 0;
    while (node != NULL) {
      if (bucket->start == node) {
        if (node->prev != DLDPQ_PRI(FIRSTNODE)) {
          eprintf("Starting node for bucket "PF_SIZE_T
              " is not marked as first\n",(size_t)bucket->key);
          return 0;
        }
      } else if (node->prev == DLDPQ_PRI(FIRSTNODE)) {
          eprintf("Non-starting node for bucket "PF_SIZE_T
              " is marked as first\n",(size_t)bucket->key);
          return 0;
      } else if (node->prev == NULL) {
          eprintf("Node with null prev pointer: ["PF_SIZE_T":"PF_SIZE_T"]\n",
              (size_t)node->key,(size_t)node->val);
          return 0;
      }
      if (((size_t)node->key) != k) {
        eprintf("Node with key = "PF_SIZE_T" in bucket "PF_SIZE_T"\n",
            (size_t)node->key,k);
        return 0;
      } else if (node->prev == NULL && node != bucket->start) {
        eprintf("Node ["PF_SIZE_T":"PF_SIZE_T"] with missing previous pointer "
            "is in position "PF_SIZE_T" in bucket "PF_SIZE_T"\n",
            (size_t)node->key,(size_t)node->val,j,(size_t)bucket->key);
        return 0;
      }
      ++j;
      node = node->next;
    }
  }

  return 1;
}


/**
 * @brief Allocate the memory for a DLDPQ. Before the resutling queue is used, 
 * dldpq_fill_min or dldpq_fill_max should be called.
 *
 * @param kmin The minimum value of a key (inclusive)
 * @param kmax The maximum value of a key (exclusive)
 * @param vmin The minimum value to be stored (inclusive) 
 * @param vmax The maximum value to be stored (exclusive)
 *
 * @return The allocated queue 
 */
DLDPQ_VISIBILITY DLDPQ_PUB(dldpq_t) * DLDPQ_PUB(dldpq_create)(
    const DLDPQ_KEY_T kmin, const DLDPQ_KEY_T kmax, const DLDPQ_VAL_T vmin, 
    const DLDPQ_VAL_T vmax) 
{ 
  const DLDPQ_KEY_T n = kmax - kmin; 
  const DLDPQ_VAL_T m = vmax - vmin; 
  DLDPQ_PUB(dldpq_t) * q = DLDPQ_PUB(dldpq_alloc)(1); 
  q->buckets = DLDPQ_PRI(dldpq_bucket_alloc)(n); 
  q->nodes = DLDPQ_PRI(dldpq_node_alloc)(m); 
  q->kmin = kmin; 
  q->kmax = kmax; 
  q->vmin = vmin; 
  q->vmax = vmax; 
  q->bmin = DLDPQ_PRI(EMPTY);
  q->bmax = DLDPQ_PRI(EMPTY);
  return q; 
} 


/**
 * @brief Free the memory associated with a DLDPQ 
 *
 * @param dpq A pointer to the DLDPQ to free
 */
DLDPQ_VISIBILITY void DLDPQ_PUB(dldpq_free)(DLDPQ_PUB(dldpq_t) * dpq) 
{ 
  dl_free(dpq->buckets); 
  dl_free(dpq->nodes); 
  dl_free(dpq); 
} 


/**
 * @brief Increment the key of an item in the DLDPQ
 *
 * @param v The value whose key should be incremented 
 * @param dpq The queue the value resides in
 */
DLDPQ_VISIBILITY void DLDPQ_PUB(dldpq_inc)(const DLDPQ_VAL_T ov, 
    DLDPQ_PUB(dldpq_t) * const dpq) 
{ 
  const DLDPQ_VAL_T v = ov - dpq->vmin; 

  DLDPQ_PRI(dldpq_node_t) * const node = dpq->nodes+v;

  if (node->prev == DLDPQ_PRI(REMOVEDNODE)) {
    ++node->key;
  } else {
    /* insert the node in the new location */ 
    DLDPQ_PRI(dldpq_bucket_moveup)(node,dpq);
  }
} 


/**
 * @brief Decrement the key of an item in the DLDPQ
 *
 * @param v The value whose key should be decremented 
 * @param dpq The queue the value resides in
 */
DLDPQ_VISIBILITY void DLDPQ_PUB(dldpq_dec)(const DLDPQ_VAL_T ov, 
    DLDPQ_PUB(dldpq_t) * const dpq) 
{ 
  const DLDPQ_VAL_T v = ov - dpq->vmin; 

  DLDPQ_PRI(dldpq_node_t) * const node = dpq->nodes+v;

  if (node->prev == DLDPQ_PRI(REMOVEDNODE)) {
    --node->key;
  } else {
    /* insert the node in the new location */ 
    DLDPQ_PRI(dldpq_bucket_movedown)(node,dpq);
  }
} 


/**
 * @brief Fill the DLDPQ with the full range of values, and set their keys to
 * the minimum key.
 *
 * @param dpq The queue to fill 
 */
DLDPQ_VISIBILITY void DLDPQ_PUB(dldpq_fill_min)(DLDPQ_PUB(dldpq_t) * const dpq) 
{ 
  size_t v; 
  size_t k; 
  DLDPQ_PRI(dldpq_node_t) * ln; 

  const size_t n = (size_t)(dpq->kmax - dpq->kmin); 
  const size_t m = (size_t)(dpq->vmax - dpq->vmin); 

  /* reset the buckets */ 
  for (k=0;k<n;++k) { 
    dpq->buckets[k].start = NULL; 
    dpq->buckets[k].next = NULL; 
    dpq->buckets[k].prev = NULL; 
    dpq->buckets[k].key = (DLDPQ_KEY_T)k;
  } 

  /* set the first node */
  ln = dpq->buckets[0].start = dpq->nodes; 
  ln->prev = DLDPQ_PRI(FIRSTNODE); 
  ln->key = 0; 
  ln->val = 0; 

  /* reset the nodes */ 
  for (v=1;v<m;++v) { 
    ln->next = dpq->nodes+v; 
    dpq->nodes[v].prev = ln; 
    ln = dpq->nodes+v; 
    ln->key = 0; 
    ln->val = (DLDPQ_VAL_T)v; 
  } 
  ln->next = NULL; 

  dpq->bmax = 0; 
  dpq->bmin = 0; 

  DL_ASSERT(DLDPQ_PUB(dldpq_check)(dpq) == 1,"Invalid DLDPQ after filling\n");
} 


/**
 * @brief Fill the DLDPQ with the full range of values, and set their keys to
 * the maximum key.
 *
 * @param dpq The queue to fill 
 */
DLDPQ_VISIBILITY void DLDPQ_PUB(dldpq_fill_max)(DLDPQ_PUB(dldpq_t) * const dpq) 
{
  size_t v; 
  size_t k; 
  DLDPQ_PRI(dldpq_node_t) * ln; 

  const size_t n = (size_t)(dpq->kmax - dpq->kmin); 
  const size_t m = (size_t)(dpq->vmax - dpq->vmin); 

  /* reset the buckets */ 
  for (k=0;k<n;++k) { 
    dpq->buckets[k].start = NULL; 
    dpq->buckets[k].next = NULL; 
    dpq->buckets[k].prev = NULL; 
    dpq->buckets[k].key = (DLDPQ_KEY_T)k;
  }

  /* set the first node */
  ln = dpq->buckets[n-1].start = dpq->nodes; 
  ln->prev = DLDPQ_PRI(FIRSTNODE); 
  ln->key = (DLDPQ_KEY_T)n-1; 
  ln->val = 0; 

  /* reset the nodes */ 
  for (v=1;v<m;++v) { 
    ln->next = dpq->nodes+v; 
    dpq->nodes[v].prev = ln; 
    ln = dpq->nodes+v; 
    ln->key = (DLDPQ_KEY_T)(n-1); 
    ln->val = (DLDPQ_VAL_T)v; 
  } 
  ln->next = NULL; 
   
  dpq->bmax = n-1; 
  dpq->bmin = n-1; 

  DL_ASSERT(DLDPQ_PUB(dldpq_check)(dpq) == 1,"Invalid DLDPQ after filling\n");
} 


/**
 * @brief Fill the DLDPQ with the full range of values, and set their keys to
 * the minimum key in randomly permuted order.
 *
 * @param dpq The queue to fill 
 */
DLDPQ_VISIBILITY void DLDPQ_PUB(dldpq_fill_min_perm)(
    DLDPQ_PUB(dldpq_t) * const dpq) 
{ 
  size_t v,i; 
  size_t k; 
  DLDPQ_PRI(dldpq_node_t) * ln; 
  size_t * perm;

  const size_t n = (size_t)(dpq->kmax - dpq->kmin); 
  const size_t m = (size_t)(dpq->vmax - dpq->vmin); 

  /* reset the buckets */ 
  for (k=0;k<n;++k) { 
    dpq->buckets[k].start = NULL; 
    dpq->buckets[k].next = NULL; 
    dpq->buckets[k].prev = NULL; 
    dpq->buckets[k].key = (DLDPQ_KEY_T)k;
  } 

  perm = size_alloc(m);
  size_incset(perm,0,1,m);
  if (m < DLDPQ_PRI(MIN_PSEUDO_SHUFFLE)) {
    size_shuffle(perm,m);
  } else {
    size_pseudo_shuffle(perm,m/8,m);
  }

  /* set the first node */
  ln = dpq->buckets[0].start = dpq->nodes+perm[0]; 
  ln->prev = DLDPQ_PRI(FIRSTNODE); 
  ln->key = 0; 
  ln->val = (DLDPQ_VAL_T)perm[0]; 

  /* reset the nodes */ 
  for (i=1;i<m;++i) { 
    v = perm[i];
    ln->next = dpq->nodes+v; 
    dpq->nodes[v].prev = ln; 
    ln = dpq->nodes+v; 
    ln->key = 0; 
    ln->val = (DLDPQ_VAL_T)v; 
  } 
  ln->next = NULL; 

  dl_free(perm);

  dpq->bmax = 0; 
  dpq->bmin = 0; 

  DL_ASSERT(DLDPQ_PUB(dldpq_check)(dpq) == 1,"Invalid DLDPQ after filling\n");
} 


/**
 * @brief Fill the DLDPQ with the full range of values, and set their keys to
 * the maximum key in randomly permuted order.
 *
 * @param dpq The queue to fill 
 */
DLDPQ_VISIBILITY void DLDPQ_PUB(dldpq_fill_max_perm)(
    DLDPQ_PUB(dldpq_t) * const dpq) 
{ 
  size_t v,i; 
  size_t k; 
  DLDPQ_PRI(dldpq_node_t) * ln; 
  size_t * perm;

  const size_t n = (size_t)(dpq->kmax - dpq->kmin); 
  const size_t m = (size_t)(dpq->vmax - dpq->vmin); 

  /* reset the buckets */ 
  for (k=0;k<n;++k) { 
    dpq->buckets[k].start = NULL; 
    dpq->buckets[k].next = NULL; 
    dpq->buckets[k].prev = NULL; 
    dpq->buckets[k].key = (DLDPQ_KEY_T)k;
  } 

  perm = size_alloc(m);
  size_incset(perm,0,1,m);
  if (m < DLDPQ_PRI(MIN_PSEUDO_SHUFFLE)) {
    size_shuffle(perm,m);
  } else {
    size_pseudo_shuffle(perm,m/8,m);
  }

  /* set the first node */
  ln = dpq->buckets[n-1].start = dpq->nodes+perm[0]; 
  ln->prev = DLDPQ_PRI(FIRSTNODE); 
  ln->key = (DLDPQ_KEY_T)(n-1); 
  ln->val = (DLDPQ_VAL_T)perm[0]; 

  /* reset the nodes */ 
  for (i=1;i<m;++i) { 
    v = perm[i];
    ln->next = dpq->nodes+v; 
    dpq->nodes[v].prev = ln; 
    ln = dpq->nodes+v; 
    ln->key = (DLDPQ_KEY_T)(n-1); 
    ln->val = (DLDPQ_VAL_T)v; 
  } 
  ln->next = NULL; 

  dl_free(perm);

  dpq->bmax = n-1; 
  dpq->bmin = n-1;

  DL_ASSERT(DLDPQ_PUB(dldpq_check)(dpq) == 1,"Invalid DLDPQ after filling\n");
} 


/**
 * @brief Remove the entry associated with a given value in the queue.
 *
 * @param val The value to remove
 * @param dpq The queue to remove the value from
 *
 * @return The key associated with the removed value
 */
DLDPQ_VISIBILITY DLDPQ_KEY_T DLDPQ_PUB(dldpq_remove)(const DLDPQ_VAL_T ov, 
    DLDPQ_PUB(dldpq_t) * const dpq) 
{ 
  const DLDPQ_VAL_T v = ov - dpq->vmin; 
  const DLDPQ_KEY_T k = dpq->nodes[v].key; 

  DLDPQ_PRI(dldpq_node_t) * node = dpq->nodes+v; 

  /* remove the node */
  DLDPQ_PRI(dldpq_node_remove)(node,dpq); 

  return k + dpq->kmin; 
} 


/**
 * @brief Remove the entry with the largest key in the queue.
 *
 * @param dpq The queue to remove the maximum entry from.
 *
 * @return The value associated with the maximum key.
 */
DLDPQ_VISIBILITY DLDPQ_VAL_T DLDPQ_PUB(dldpq_remove_max)(
    DLDPQ_PUB(dldpq_t) * const dpq) 
{ 
  DLDPQ_PRI(dldpq_node_t) * node; 

  if (dpq->bmax != DLDPQ_PRI(EMPTY)) {
    node = dpq->buckets[dpq->bmax].start; 
    DL_ASSERT(node != NULL,"Empty bucket at bmax = "PF_SIZE_T"/"PF_SIZE_T"\n",
        dpq->bmax,(size_t)(dpq->kmax - dpq->kmin));
    DLDPQ_PRI(dldpq_node_remove)(node,dpq); 
    return node->val + dpq->vmin; 
  } else {
    return (DLDPQ_VAL_T)dpq->vmin-1;
  }
} 


/**
 * @brief Remove the entry with the smallest key in the queue.
 *
 * @param dpq The queue to remove the minimum entry from.
 *
 * @return The value associated with the minimum key.
 */
DLDPQ_VISIBILITY DLDPQ_VAL_T DLDPQ_PUB(dldpq_remove_min)(
    DLDPQ_PUB(dldpq_t) * const dpq) 
{ 
  DLDPQ_PRI(dldpq_node_t) * node; 

  if (dpq->bmin != DLDPQ_PRI(EMPTY)) {
    node = dpq->buckets[dpq->bmin].start; 
    DL_ASSERT(node != NULL,"Empty bucket at bmin = "PF_SIZE_T"/"PF_SIZE_T"\n",
        dpq->bmin,(size_t)(dpq->kmax - dpq->kmin));
    DLDPQ_PRI(dldpq_node_remove)(node,dpq); 
    return node->val + dpq->vmin; 
  } else {
    return (DLDPQ_VAL_T)dpq->vmin-1;
  }
} 


/**
 * @brief Retrieve the value associated with the maximum key. That is, return
 * the value that will be removed by a call to dldpq_remove_max.
 *
 * @param dpq The queue of which to peek at.
 *
 * @return The value associated with the maximum key in the queue.
 */
DLDPQ_VISIBILITY DLDPQ_VAL_T DLDPQ_PUB(dldpq_peek_max)(
    DLDPQ_PUB(dldpq_t) * const dpq) 
{ 
  DLDPQ_VAL_T v; 
  DLDPQ_PRI(dldpq_node_t) * node; 
  if (dpq->bmax != DLDPQ_PRI(EMPTY)) { 
    node = dpq->buckets[dpq->bmax].start; 
    v = node->val + dpq->vmin; 
    return v; 
  } else {
    return (DLDPQ_VAL_T)dpq->vmin-1;
  }
} 


/**
 * @brief Retrieve the value associated with the minimum key. That is, return
 * the value that will be removed by a call to dldpq_remove_min.
 *
 * @param dpq The queue of which to peek at.
 *
 * @return The value associated with the minimum key in the queue.
 */
DLDPQ_VISIBILITY DLDPQ_VAL_T DLDPQ_PUB(dldpq_peek_min)(
    DLDPQ_PUB(dldpq_t) * const dpq) 
{ 
  DLDPQ_VAL_T v; 
  DLDPQ_PRI(dldpq_node_t) * node; 
  if (dpq->bmin != DLDPQ_PRI(EMPTY)) { 
    node = dpq->buckets[dpq->bmin].start; 
    v = node->val + dpq->vmin; 
    return v; 
  } else {
    return (DLDPQ_VAL_T)dpq->vmin-1;
  }
} 


/**
 * @brief Retrieve the key associated with a given value in the queue.
 *
 * @param v The value to search for.
 * @param dpq The queue being searched.
 *
 * @return The key associated with the given value.
 */
DLDPQ_VISIBILITY DLDPQ_KEY_T DLDPQ_PUB(dldpq_peek)(const DLDPQ_VAL_T ov, 
    DLDPQ_PUB(dldpq_t) * const dpq) 
{ 
  const DLDPQ_VAL_T v = ov - dpq->vmin; 
  const DLDPQ_KEY_T k = dpq->nodes[v].key; 
  return k + dpq->kmin; 
}




/* handle visibility */
#ifdef DLDPQ_DEFVIS
  #undef DLDPQ_VISIBILITY
  #undef DLDPQ_DEFVIS
#endif

#undef DLDPQ_PUB
#undef DLDPQ_PRI
#undef DLDPQ_PRE1
#undef DLDPQ_PRE2
