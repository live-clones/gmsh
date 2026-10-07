/**
 * @file dlcombuffer_headers.h
 * @brief Function prototypes for communication buffers 
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright (c) 2013-2015, Dominique LaSalle
 * @version 1
 * @date 2013-10-05
 */




/* prefixing ugliness */
#define DLCB_PRE2(prefix,suffix) prefix ## _ ## suffix
#define DLCB_PRE1(prefix,suffix) DLCB_PRE2(prefix,suffix)
#define DLCB_PUB(name) DLCB_PRE1(DLCB_PREFIX,name)
#define DLCB_PRI(name) DLCB_PRE1(_,DLCB_PRE1(DLCB_PREFIX,name))


#define DLBUFFER_PREFIX DLCB_PRI(cb)
#define DLBUFFER_TYPE_T DLCB_TYPE_T
#include "dlbuffer_headers.h"
#undef DLBUFFER_PREFIX
#undef DLBUFFER_TYPE_T


typedef struct DLCB_PUB(combuffer_t) {
  dlthread_comm_t comm;
  size_t defbufsize;
  #ifdef DLCB_BUFFER_TYPE_T
  DLCB_BUFFER_TYPE_T ** buffers;
  #else
  DLCB_PRI(cb_buffer_t) ** buffers;
  #endif
} DLCB_PUB(combuffer_t);


#ifndef DLCB_STATIC


/******************************************************************************
* FUNCTION PROTOTYPES *********************************************************
******************************************************************************/


DLCB_PUB(combuffer_t) * DLCB_PUB(combuffer_create)(
    dlthread_comm_t comm);


void DLCB_PUB(combuffer_add)(
    size_t dst, 
    DLCB_TYPE_T val,
    DLCB_PUB(combuffer_t) * com);


void DLCB_PUB(combuffer_send)(
    DLCB_PUB(combuffer_t) * com);


void DLCB_PUB(combuffer_clear)(
    DLCB_PUB(combuffer_t) * com);


void DLCB_PUB(combuffer_free)(
    DLCB_PUB(combuffer_t) * com);


#ifdef DLCB_BUFFER_TYPE_T
DLCB_BUFFER_TYPE_T * DLCB_PUB(combuffer_get)(
    size_t idx, 
    const DLCB_PUB(combuffer_t) * com);
#endif


#undef DLCB_PRE2
#undef DLCB_PRE1
#undef DLCB_PUB
#undef DLCB_PRI


#else


#undef DLCB_PRE2
#undef DLCB_PRE1
#undef DLCB_PUB
#undef DLCB_PRI


#define DLCB_VISIBILITY static
#include "dlcb_funcs.h"
#undef DLCB_VISIBILITY


#endif
