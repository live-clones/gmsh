/**
 * @file dlbinarytree_headers.h
 * @brief Tree prototypes
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright (c) 2013-2015, Dominique LaSalle
 * @version 1
 * @date 2013-10-03
 */




/* this is ugly but neccessary */
#define DLTREE_PRE2(prefix,suffix) prefix ## _ ## suffix
#define DLTREE_PRE1(prefix,suffix) DLTREE_PRE2(prefix,suffix)
#define DLTREE_PUB(name) DLTREE_PRE1(DLTREE_PREFIX,name)
#define DLTREE_PRI(name) \
  DLTREE_PRE1(_,DLTREE_PRE1(DLTREE_PREFIX,name))


#ifndef DLTREE_WIDTH
#define DLTREE_WIDTH 5
#endif

/******************************************************************************
* TYPES ***********************************************************************
******************************************************************************/


typedef struct DLTREE_PRI(tree_node_t) {
  DLTREE_KEY_T key[DLTREE_WIDTH];
  DLTREE_VAL_T val[DLTREE_WIDTH];
  struct DLTREE_PRI(tree_node_t) * children[DLTREE_WIDTH+1];
  size_t nelements;
  size_t nchildren;
} DLTREE_PRI(tree_node_t);


typedef struct DLTREE_PUB(tree_t) {
  DLTREE_PRI(tree_node_t) * root;
  size_t size;
  int (*compar)(DLTREE_KEY_T const, DLTREE_KEY_T const);
} DLTREE_PUB(tree_t);




#ifndef DLTREE_STATIC


DLTREE_PUB(tree_t) * DLTREE_PUB(tree_create)(
    int (*compar)(DLTREE_KEY_T const, DLTREE_KEY_T const));


void DLTREE_PUB(tree_free)(
    DLTREE_PUB(tree_t) * tree);


int DLTREE_PUB(tree_add)(
    DLTREE_KEY_T const key, 
    DLTREE_VAL_T const val, 
    DLTREE_PUB(tree_t) * tree);


DLTREE_VAL_T DLTREE_PUB(tree_remove)(
    DLTREE_KEY_T const key, 
    DLTREE_PUB(tree_t) * tree);


DLTREE_VAL_T DLTREE_PUB(tree_get)(
    DLTREE_KEY_T const key, 
    DLTREE_PUB(tree_t) * tree);


#undef DLTREE_PUB
#undef DLTREE_PRI
#undef DLTREE_PRE1
#undef DLTREE_PRE2

#else

#undef DLTREE_PUB
#undef DLTREE_PRI
#undef DLTREE_PRE1
#undef DLTREE_PRE2

#define DLTREE_VISIBILITY static
#include "dltree_funcs.h"
#undef DLTREE_VISIBILITY

#endif


