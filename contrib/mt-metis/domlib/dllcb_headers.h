/**
 * @file dllcb_headers.h
 * @brief Function prototypes for live communication buffers 
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright (c) 2013-2015, Dominique LaSalle
 * @version 1
 * @date 2013-10-05
 */




#include "dldebug.h"




/******************************************************************************
* MISC MACROS *****************************************************************
******************************************************************************/


/* prefixing ugliness */
#define DLLCB_PRE2(prefix,suffix) prefix ## _ ## suffix
#define DLLCB_PRE1(prefix,suffix) DLLCB_PRE2(prefix,suffix)
#define DLLCB_PUB(name) DLLCB_PRE1(DLLCB_PREFIX,name)
#define DLLCB_PRI(name) DLLCB_PRE1(_,DLLCB_PRE1(DLLCB_PREFIX,name))


#ifndef CACHE_LINE_SIZE
#define CACHE_LINE_SIZE 64
#endif




/******************************************************************************
* TYPES ***********************************************************************
******************************************************************************/


typedef struct DLLCB_PRI(node_t) {
  DLLCB_TYPE_T val;
  struct DLLCB_PRI(node_t) * next;
} DLLCB_PRI(node_t);


typedef struct DLLCB_PRI(list_t) {
  DLLCB_PRI(node_t) * start;
  DLLCB_PRI(node_t) * laststart;
  DLLCB_PRI(node_t) * end;
} DLLCB_PRI(list_t);


typedef struct DLLCB_PRI(info_t) {
  int volatile finished;
  int volatile active;
  size_t maxmsgs;
  size_t lastmsg;
  DLLCB_PRI(node_t) * nodes;
  /* ensure the structure is 64 bytes to avoid false sharing */
  char _padding[CACHE_LINE_SIZE - \
      (sizeof(int)*2+sizeof(size_t)*2+sizeof(void*))];
} DLLCB_PRI(info_t);
DL_STATIC_ASSERT(sizeof(DLLCB_PRI(info_t)) == CACHE_LINE_SIZE);


typedef struct DLLCB_PUB(combuffer_t) {
  dlthread_comm_t comm;
  DLLCB_PRI(info_t) * infos;
  DLLCB_PRI(list_t) ** lists;
} DLLCB_PUB(combuffer_t);




#ifndef DLLCB_STATIC


/******************************************************************************
* FUNCTION PROTOTYPES *********************************************************
******************************************************************************/


DLLCB_PUB(combuffer_t) * DLLCB_PUB(combuffer_create)(
    size_t maxmsgs,
    dlthread_comm_t comm);


void DLLCB_PUB(combuffer_add)(
    size_t dst, 
    DLLCB_TYPE_T val,
    DLLCB_PUB(combuffer_t) * com);


int DLLCB_PUB(combuffer_next)(
    DLLCB_TYPE_T * r_next,
    DLLCB_PUB(combuffer_t) * com);


void DLLCB_PUB(combuffer_clear)(
    DLLCB_PUB(combuffer_t) * com);


void DLLCB_PUB(combuffer_free)(
    DLLCB_PUB(combuffer_t) * com);


#undef DLLCB_PRE2
#undef DLLCB_PRE1
#undef DLLCB_PUB
#undef DLLCB_PRI


#else


#undef DLLCB_PRE2
#undef DLLCB_PRE1
#undef DLLCB_PUB
#undef DLLCB_PRI


#define DLLCB_VISIBILITY static
#include "dllcb_funcs.h"
#undef DLLCB_VISIBILITY


#endif
