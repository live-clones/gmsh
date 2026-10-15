/**
 * @file dlpq_headers.h
 * @brief Priority queue function prototypes
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




/******************************************************************************
* TYPES ***********************************************************************
******************************************************************************/


typedef struct DLPQ_PRI(pq_kv_t) {
  DLPQ_KEY_T key;
  DLPQ_VAL_T val;
} DLPQ_PRI(pq_kv_t);


typedef struct DLPQ_PUB(pq_t) {
  size_t maxsize;
  size_t size;
  DLPQ_PRI(pq_kv_t) * elements;
  #ifndef DLPQ_USE_HT
  DLPQ_VAL_T min;
  DLPQ_VAL_T max;
  size_t * index;
  #else
  void * ht;
  #endif
} DLPQ_PUB(pq_t);


#ifndef DLPQ_STATIC


/******************************************************************************
* FUNCTION PROTOTYPES *********************************************************
******************************************************************************/


#ifndef DLPQ_USE_HT
/**
 * @brief Create a priority queue with the given value range. 
 *
 * @param min The minimum value (inclusive).
 * @param max The maximum value (exclusive).
 *
 * @return The newly allocated and initialized priority queue.
 */
DLPQ_PUB(pq_t) * DLPQ_PUB(pq_create)(
    DLPQ_VAL_T min,
    DLPQ_VAL_T max);
#else
/**
 * @brief Create a priority queue with the given value range. 
 *
 * @param n The maximum number of elements to be added to the queue.
 *
 * @return The newly allocated and initialized priority queue.
 */
DLPQ_PUB(pq_t) * DLPQ_PUB(pq_create)(
    size_t n);
#endif


/**
 * @brief Add a value to the priority queue with a given priority.
 *
 * @param key The priority to add the value with.
 * @param val The value to add to the prioirty queue.
 * @param q The priority queue.
 */
void DLPQ_PUB(pq_push)(
    DLPQ_KEY_T key, 
    DLPQ_VAL_T val,
    DLPQ_PUB(pq_t) * q);


/**
 * @brief Remove and return the top value in the priority queue.
 *
 * @param q The priority queue.
 *
 * @return The top value.
 */
DLPQ_VAL_T DLPQ_PUB(pq_pop)(
    DLPQ_PUB(pq_t) *q);


/**
 * @brief Return the top value in the priority queue.
 *
 * @param q The priority queue.
 *
 * @return The top value.
 */
DLPQ_VAL_T DLPQ_PUB(pq_peek)(
    DLPQ_PUB(pq_t) const * q);


/**
 * @brief Return the top priority in the priority queue. 
 *
 * @param q The priority queue.
 *
 * @return The top priority.
 */
DLPQ_KEY_T DLPQ_PUB(pq_top)(
    DLPQ_PUB(pq_t) const * q);


/**
 * @brief Get the priority of a value in the priority queue. If the value is
 * not in the queue, the behavior is undefined (and likely segmenty).
 *
 * @param v The value to get the priority of.
 * @param q The the value is in.
 *
 * @return The priority assocaited with v. 
 */
DLPQ_KEY_T DLPQ_PUB(pq_priority)(
    DLPQ_VAL_T v,
    DLPQ_PUB(pq_t) const * q);


/**
 * @brief Update the priority of a value in the priority queue.
 *
 * @param p The new priority.
 * @param v The value to update.
 * @param q The priority queue.
 */
void DLPQ_PUB(pq_update)(
    DLPQ_KEY_T p, 
    DLPQ_VAL_T v,
    DLPQ_PUB(pq_t) * q);


/**
 * @brief Add to the value of the priority of a value in the priority queue.
 *
 * @param p The amount to add to the current priority.
 * @param v The value to update.
 * @param q The priority queue.
 */
void DLPQ_PUB(pq_updateadd)(
    DLPQ_KEY_T p, 
    DLPQ_VAL_T v,
    DLPQ_PUB(pq_t) * q);


/**
 * @brief Remove a value from the priority queue. 
 *
 * @param v The value to remove.
 * @param q The priority queue.
 */
void DLPQ_PUB(pq_remove)(
    DLPQ_VAL_T v, 
    DLPQ_PUB(pq_t) * q);


/**
 * @brief Clear/empty a priority queue of values.
 *
 * @param q The priority queue.
 */
void DLPQ_PUB(pq_clear)(
    DLPQ_PUB(pq_t) * q);


/**
 * @brief Check if a value is present in the priority queue. 
 *
 * @param v The value to check for.
 * @param q The priority queue.
 *
 * @return 1 if the value is present, 0 if it is not.
 */
int DLPQ_PUB(pq_contains)(
    DLPQ_VAL_T v, 
    DLPQ_PUB(pq_t) * q);


/**
 * @brief Free the memory associated with the priority queue.
 *
 * @param q The priority queue.
 */
void DLPQ_PUB(pq_free)(
    DLPQ_PUB(pq_t) * q);




#undef DLPQ_PRE2
#undef DLPQ_PRE1
#undef DLPQ_PUB
#undef DLPQ_PRI


#else


#undef DLPQ_PRE2
#undef DLPQ_PRE1
#undef DLPQ_PUB
#undef DLPQ_PRI


#define DLPQ_VISIBILITY static
#include "dlpq_funcs.h"
#undef DLPQ_VISIBILITY


#endif
