/**
 * @file dlist_headers.h
 * @brief Function prototypes for lists
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
* TYPES ***********************************************************************
******************************************************************************/
#ifdef DLLIST_LINKED
typedef struct DLLIST_PRI(list_node_t) {
  struct DLLIST_PRI(list_node_t) * next;
  struct DLLIST_PRI(list_node_t) * prev;
  DLLIST_TYPE_T val;
} DLLIST_PRI(list_node_t);
#endif


typedef struct DLLIST_PUB(list_t) {
#ifdef DLLIST_LINKED
  DLLIST_PRI(list_node_t) * head;
  DLLIST_PRI(list_node_t) * tail;
#else
  size_t maxsize;
  size_t front;
  DLLIST_TYPE_T * val;
#endif
  size_t size;
} DLLIST_PUB(list_t);


#ifndef DLLIST_STATIC


/******************************************************************************
* FUNCTION PROTOTYPES *********************************************************
******************************************************************************/

#ifdef DLLIST_LINKED
DLLIST_PUB(list_t) * DLLIST_PUB(list_create)(void);
#else
DLLIST_PUB(list_t) * DLLIST_PUB(list_create)(size_t size);
#endif

int DLLIST_PUB(list_add)(DLLIST_TYPE_T item, DLLIST_PUB(list_t) * lst);


int DLLIST_PUB(list_enqueue)(DLLIST_TYPE_T item, DLLIST_PUB(list_t) * lst);


int DLLIST_PUB(list_push)(DLLIST_TYPE_T item, DLLIST_PUB(list_t) * lst);


DLLIST_TYPE_T DLLIST_PUB(list_get)(size_t idx, DLLIST_PUB(list_t) * lst);


DLLIST_TYPE_T DLLIST_PUB(list_peek)(DLLIST_PUB(list_t) * lst);


DLLIST_TYPE_T DLLIST_PUB(list_front)(DLLIST_PUB(list_t) * lst);


DLLIST_TYPE_T DLLIST_PUB(list_remove)(size_t idx, DLLIST_PUB(list_t) * lst);


DLLIST_TYPE_T DLLIST_PUB(list_dequeue)(DLLIST_PUB(list_t) * lst);


DLLIST_TYPE_T DLLIST_PUB(list_pop)(DLLIST_PUB(list_t) * lst);


DLLIST_TYPE_T DLLIST_PUB(list_replace)(DLLIST_TYPE_T item, size_t idx,
    DLLIST_PUB(list_t) * lst);


size_t DLLIST_PUB(list_clear)(DLLIST_PUB(list_t) * lst);


ssize_t DLLIST_PUB(list_indexof)(DLLIST_TYPE_T val, 
    const DLLIST_PUB(list_t) * lst);


int DLLIST_PUB(list_contains)(DLLIST_TYPE_T val, 
    const DLLIST_PUB(list_t) * lst);



void DLLIST_PUB(list_free)(DLLIST_PUB(list_t) * lst);


#ifdef DLLIST_ARRAY

size_t DLLIST_PUB(list_expand)(DLLIST_PUB(list_t) * lst,
    size_t newsize);

#endif




#undef DLLIST_PRE2
#undef DLLIST_PRE1
#undef DLLIST_PUB
#undef DLLIST_PRI


#else


#undef DLLIST_PRE2
#undef DLLIST_PRE1
#undef DLLIST_PUB
#undef DLLIST_PRI


#define DLLIST_VISIBILITY static
#include "dllist_funcs.h"
#undef DLLIST_VISIBILITY


#endif
