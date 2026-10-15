/**
 * @file dldjset_headers.h
 * @brief Function prototypes for disjoint sets
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
* TYPES ***********************************************************************
******************************************************************************/


typedef struct DLDJSET_PRI(djset_node_t) {
  size_t root;
  size_t rank;
} DLDJSET_PRI(djset_node_t);


typedef struct DLDJSET_PUB(djset_t) {
  DLDJSET_TYPE_T min, max;
  DLDJSET_PRI(djset_node_t) * nodes;
  size_t nsets;
} DLDJSET_PUB(djset_t);




/******************************************************************************
* FUNCTION PROTOTYPES *********************************************************
******************************************************************************/


#ifndef DLDJSET_STATIC


/**
 * @brief Allocate and initial a disjoint set with minimum and maximum values.
 *
 * @param min The minimum value (inclusive) to be stored in the disjoint set.
 * @param max The maximum values (exclusive) to be stored in the disjoint set.
 *
 * @return The created disjoint set.
 */
DLDJSET_PUB(djset_t) * DLDJSET_PUB(djset_create)(
    DLDJSET_TYPE_T min, 
    DLDJSET_TYPE_T max);


/**
 * @brief Find the set to which the given item belongs.
 *
 * @param item The item to query with.
 * @param set The disjoint set structure.
 *
 * @return The item at the root of the set to which the passed in item belongs.
 */
DLDJSET_TYPE_T DLDJSET_PUB(djset_find)(
    DLDJSET_TYPE_T item, 
    DLDJSET_PUB(djset_t) * set);


/**
 * @brief Join two items (or their sets).
 *
 * @param itema The first item.
 * @param itemb The second item.
 * @param set The disjoint set structure. 
 *
 * @return The item that became the new root of the joined set. 
 */
DLDJSET_TYPE_T DLDJSET_PUB(djset_join)(
    DLDJSET_TYPE_T itema, 
    DLDJSET_TYPE_T itemb,
    DLDJSET_PUB(djset_t) * set);


/**
 * @brief Add a single item to a set. The set automatically becomes the new
 * root.
 *
 * @param singleton The single item to add.
 * @param group An item from the set to add the single item to.
 * @param set The disjoint set structure. 
 */
void DLDJSET_PUB(djset_add)(
    DLDJSET_TYPE_T singleton, 
    DLDJSET_TYPE_T group,
    DLDJSET_PUB(djset_t) * set);


/**
 * @brief Reset the disjoint set structure such that each item is its own set. 
 *
 * @param set The disjoint set. 
 */
void DLDJSET_PUB(djset_reset)(
    DLDJSET_PUB(djset_t) * set);


/**
 * @brief Free the disjoint set structure and associate memory.
 *
 * @param set The disjoint set.
 */
void DLDJSET_PUB(djset_free)(
    DLDJSET_PUB(djset_t) * set);




#undef DLDJSET_PRE1
#undef DLDJSET_PRE2
#undef DLDJSET_PUB
#undef DLDJSET_PRI


#else


#undef DLDJSET_PRE1
#undef DLDJSET_PRE2
#undef DLDJSET_PUB
#undef DLDJSET_PRI


#define DLDJSET_VISIBILITY static
#include "dldjset_funcs.h"
#undef DLDJSET_VISIBILITY


#endif
