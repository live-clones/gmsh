/**
 * @file dldpq_headers.h
 * @brief Discrete priority queue types and function prototypes
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright (c) 2013-2015, Dominique LaSalle
 * @version 1
 * @date 2013-09-05
 */




/* prefixing ugliness */
#define DLDPQ_PRE2(prefix,suffix) prefix ## _ ## suffix
#define DLDPQ_PRE1(prefix,suffix) DLDPQ_PRE2(prefix,suffix)
#define DLDPQ_PUB(name) DLDPQ_PRE1(DLDPQ_PREFIX,name)
#define DLDPQ_PRI(name) DLDPQ_PRE1(_,DLDPQ_PRE1(DLDPQ_PREFIX,name))


/******************************************************************************
* TYPES ***********************************************************************
******************************************************************************/


typedef struct DLDPQ_PRI(dldpq_node_t) { 
  DLDPQ_KEY_T key; 
  DLDPQ_VAL_T val; 
  struct DLDPQ_PRI(dldpq_node_t) * next; 
  struct DLDPQ_PRI(dldpq_node_t) * prev; 
} DLDPQ_PRI(dldpq_node_t); 


typedef struct DLDPQ_PRI(dldpq_bucket_t) { 
  DLDPQ_KEY_T key; 
  struct DLDPQ_PRI(dldpq_node_t) * start; 
  struct DLDPQ_PRI(dldpq_bucket_t) * next; 
  struct DLDPQ_PRI(dldpq_bucket_t) * prev; 
} DLDPQ_PRI(dldpq_bucket_t); 


typedef struct DLDPQ_PUB(dldpq_t) { 
  struct DLDPQ_PRI(dldpq_bucket_t) * buckets; 
  struct DLDPQ_PRI(dldpq_node_t) * nodes; 
  DLDPQ_KEY_T kmin; 
  DLDPQ_KEY_T kmax; 
  DLDPQ_VAL_T vmin; 
  DLDPQ_VAL_T vmax; 
  size_t bmin; 
  size_t bmax; 
} DLDPQ_PUB(dldpq_t); 




/******************************************************************************
* MEMORY HEADERS **************************************************************
******************************************************************************/


/* size_t */
#define DLMEM_PREFIX DLDPQ_PRI(dldpq_node)
#define DLMEM_TYPE_T DLDPQ_PRI(dldpq_node_t)
#include "dlmem_headers.h"
#undef DLMEM_PREFIX
#undef DLMEM_TYPE_T

/* ssize_t */
#define DLMEM_PREFIX DLDPQ_PRI(dldpq_bucket)
#define DLMEM_TYPE_T DLDPQ_PRI(dldpq_bucket_t)
#include "dlmem_headers.h"
#undef DLMEM_PREFIX
#undef DLMEM_TYPE_T

/* int */
#define DLMEM_PREFIX DLDPQ_PUB(dldpq)
#define DLMEM_TYPE_T DLDPQ_PUB(dldpq_t)
#include "dlmem_headers.h"
#undef DLMEM_PREFIX
#undef DLMEM_TYPE_T




/******************************************************************************
* FUNCTION PROTOTYPES *********************************************************
******************************************************************************/


#ifndef DLDPQ_STATIC


/**
 * @brief Check the state of the DLDPQ and ensure that it is valid.
 *
 * @param DLDPQ_PUB(dldpq_t) dpq
 *
 * @return 0 if it is invalid, 1 other wise
 */
int DLDPQ_PUB(dldpq_check)(DLDPQ_PUB(dldpq_t) * dpq);


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
DLDPQ_PUB(dldpq_t) * DLDPQ_PUB(dldpq_create)(DLDPQ_KEY_T kmin, DLDPQ_KEY_T kmax, 
    DLDPQ_VAL_T vmin, DLDPQ_VAL_T vmax); 


/**
 * @brief Free the memory associated with a DLDPQ 
 *
 * @param dpq A pointer to the DLDPQ to free
 */
void DLDPQ_PUB(dldpq_free)(DLDPQ_PUB(dldpq_t) * dpq); 


/**
 * @brief Increment the key of an item in the DLDPQ
 *
 * @param v The value whose key should be incremented 
 * @param dpq The queue the value resides in
 */
void DLDPQ_PUB(dldpq_inc)(DLDPQ_VAL_T v, DLDPQ_PUB(dldpq_t) * dpq); 


/**
 * @brief Decrement the key of an item in the DLDPQ
 *
 * @param v The value whose key should be decremented 
 * @param dpq The queue the value resides in
 */
void DLDPQ_PUB(dldpq_dec)(DLDPQ_VAL_T v, DLDPQ_PUB(dldpq_t) * dpq); 


/**
 * @brief Fill the DLDPQ with the full range of values, and set their keys to
 * the minimum key.
 *
 * @param dpq The queue to fill 
 */
void DLDPQ_PUB(dldpq_fill_min)(DLDPQ_PUB(dldpq_t) * dpq); 


/**
 * @brief Fill the DLDPQ with the full range of values, and set their keys to
 * the maximum key.
 *
 * @param dpq The queue to fill 
 */
void DLDPQ_PUB(dldpq_fill_max)(DLDPQ_PUB(dldpq_t) * dpq); 


/**
 * @brief Fill the DLDPQ with the full range of values, and set their keys to
 * the minimum key in randomly permuted order.
 *
 * @param dpq The queue to fill 
 */
void DLDPQ_PUB(dldpq_fill_min_perm)(DLDPQ_PUB(dldpq_t) * dpq);


/**
 * @brief Fill the DLDPQ with the full range of values, and set their keys to
 * the maximum key in randomly permuted order.
 *
 * @param dpq The queue to fill 
 */
void DLDPQ_PUB(dldpq_fill_max_perm)(DLDPQ_PUB(dldpq_t) * dpq);


/**
 * @brief Remove the entry associated with a given value in the queue.
 *
 * @param val The value to remove
 * @param dpq The queue to remove the value from
 *
 * @return The key associated with the removed value
 */
DLDPQ_KEY_T DLDPQ_PUB(dldpq_remove)(DLDPQ_VAL_T val, DLDPQ_PUB(dldpq_t) * dpq); 


/**
 * @brief Remove the entry with the largest key in the queue.
 *
 * @param dpq The queue to remove the maximum entry from.
 *
 * @return The value associated with the maximum key.
 */
DLDPQ_VAL_T DLDPQ_PUB(dldpq_remove_max)(DLDPQ_PUB(dldpq_t) * dpq); 


/**
 * @brief Remove the entry with the smallest key in the queue.
 *
 * @param dpq The queue to remove the minimum entry from.
 *
 * @return The value associated with the minimum key.
 */
DLDPQ_VAL_T DLDPQ_PUB(dldpq_remove_min)(DLDPQ_PUB(dldpq_t) * dpq); 


/**
 * @brief Retrieve the value associated with the maximum key. That is, return
 * the value that will be removed by a call to dldpq_remove_max.
 *
 * @param dpq The queue of which to peek at.
 *
 * @return The value associated with the maximum key in the queue.
 */
DLDPQ_VAL_T DLDPQ_PUB(dldpq_peek_max)(DLDPQ_PUB(dldpq_t) * dpq); 


/**
 * @brief Retrieve the value associated with the minimum key. That is, return
 * the value that will be removed by a call to dldpq_remove_min.
 *
 * @param dpq The queue of which to peek at.
 *
 * @return The value associated with the minimum key in the queue.
 */
DLDPQ_VAL_T DLDPQ_PUB(dldpq_peek_min)(DLDPQ_PUB(dldpq_t) * dpq); 


/**
 * @brief Retrieve the key associated with a given value in the queue.
 *
 * @param v The value to search for.
 * @param dpq The queue being searched.
 *
 * @return The key associated with the given value.
 */
DLDPQ_KEY_T DLDPQ_PUB(dldpq_peek)(DLDPQ_VAL_T v, DLDPQ_PUB(dldpq_t) * dpq);


#undef DLDPQ_PUB
#undef DLDPQ_PRE1
#undef DLDPQ_PRE2
#undef DLDPQ_PRI


#else


#undef DLDPQ_PUB
#undef DLDPQ_PRE1
#undef DLDPQ_PRE2
#undef DLDPQ_PRI


/* include the functions and make use of the static prefix */
#define DLDPQ_VISIBILITY static
#include "dldpq_funcs.h"
#undef DLDPQ_VISIBILITY


#endif


