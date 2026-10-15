/**
 * @file dlcb_funcs.h
 * @brief Functions for communication buffers
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
#define DLCB_RPRI(name) DLCB_PRE1(r__,DLCB_PRE1(DLCB_PREFIX,name))




/******************************************************************************
* INCLUDES ********************************************************************
******************************************************************************/


#ifndef DLCB_BUFFER_TYPE_T

#define DLBUFFER_PREFIX DLCB_PRI(cb)
#define DLBUFFER_TYPE_T DLCB_TYPE_T
#include "dlbuffer_funcs.h"
#undef DLBUFFER_PREFIX
#undef DLBUFFER_TYPE_T

#define DLCB_BUFFER_FUNC(func) DLCB_PRE1(DLCB_PRI(cb_buffer),func)

#else

#define DLCB_BUFFER_FUNC(func) DLCB_PRE1(DLCB_BUFFER_PREFIX,func)

#endif


#define DLMEM_PREFIX DLCB_PUB(combuffer)
#define DLMEM_TYPE_T DLCB_PUB(combuffer_t)
#define DLMEM_STATIC
#include "dlmem_headers.h"
#undef DLMEM_STATIC
#undef DLMEM_PREFIX
#undef DLMEM_TYPE_T




/******************************************************************************
* PUBLIC FUNCTIONS ************************************************************
******************************************************************************/


#ifndef DLCB_VISIBILITY
  #define DLCB_DEFVIS
  #define DLCB_VISIBILITY
#endif




DLCB_VISIBILITY DLCB_PUB(combuffer_t) * DLCB_PUB(combuffer_create)(
    dlthread_comm_t comm)
{
  size_t i;
  DLCB_PUB(combuffer_t) * cbc;

  size_t const nthreads = dlthread_get_nthreads(comm);
  size_t const myid = dlthread_get_id(comm);

  cbc = dlthread_get_shmem(sizeof(DLCB_PUB(combuffer_t)),comm);

  if (myid == 0) {
    cbc->comm = comm;
    cbc->buffers = malloc(sizeof(void*)*nthreads);
  }
  dlthread_barrier(comm);

  cbc->buffers[myid] = DLCB_BUFFER_FUNC(alloc)(nthreads);
  for (i=0;i<nthreads;++i) {
    if (i != myid) { 
      DLCB_BUFFER_FUNC(init)(nthreads,cbc->buffers[myid]+i);
    } else {
      cbc->buffers[myid][i].maxsize = 0;
      cbc->buffers[myid][i].defsize = 0;
      cbc->buffers[myid][i].size = 0;
      cbc->buffers[myid][i].elements = NULL;
    }
  }

  return cbc;
}


DLCB_VISIBILITY void DLCB_PUB(combuffer_add)(
    size_t const dst, 
    DLCB_TYPE_T const val, 
    DLCB_PUB(combuffer_t) * const com)
{
  size_t const myid = dlthread_get_id(com->comm);

  DLCB_BUFFER_FUNC(add)(val,com->buffers[myid]+dst);
}


DLCB_VISIBILITY void DLCB_PUB(combuffer_send)(
    DLCB_PUB(combuffer_t) * const com)
{
  size_t i,j;
  DLCB_BUFFER_FUNC(t) buf;

  size_t const myid = dlthread_get_id(com->comm);
  size_t const nthreads = dlthread_get_nthreads(com->comm);

  dlthread_barrier(com->comm);
  if (myid == 0) {
    for (i=0;i<nthreads-1;++i) {
      for (j=i+1;j<nthreads;++j) {
        buf = com->buffers[j][i];
        com->buffers[j][i] = com->buffers[i][j];
        com->buffers[i][j] = buf;
      }
    }
  }
  dlthread_barrier(com->comm);
}


DLCB_VISIBILITY void DLCB_PUB(combuffer_clear)(DLCB_PUB(combuffer_t) * com)
{
  size_t i;

  size_t const myid = dlthread_get_id(com->comm);
  size_t const nthreads = dlthread_get_nthreads(com->comm);

  for (i=0;i<nthreads;++i) {
    DLCB_BUFFER_FUNC(clear)(com->buffers[myid]+i);
  }
}


DLCB_VISIBILITY void DLCB_PUB(combuffer_free)(DLCB_PUB(combuffer_t) * com)
{
  size_t i;
  dlthread_comm_t comm;

  size_t const myid = dlthread_get_id(com->comm);
  size_t const nthreads = dlthread_get_nthreads(com->comm);

  comm = com->comm;

  for (i=0;i<nthreads;++i) {
    if (i!=myid) {
      dl_free(com->buffers[myid][i].elements);
    }
  }
  dl_free(com->buffers[myid]);
  dlthread_barrier(com->comm);

  if (myid == 0) {
    dl_free(com->buffers);
  }

  dlthread_free_shmem(com,comm);
}


#ifdef DLCB_BUFFER_TYPE_T

DLCB_VISIBILITY DLCB_BUFFER_TYPE_T * DLCB_PUB(combuffer_get)(
    size_t const idx, 
    DLCB_PUB(combuffer_t) const * const com)
{
  size_t const myid = dlthread_get_id(com->comm);

  return com->buffers[myid]+idx;
}

#endif



#ifdef DLCB_DEFVIS
  #undef DLCB_DEFVIS
  #undef DLCB_VISIBILITY
#endif



#undef DLCB_PRE
#undef DLCB_PRE
#undef DLCB_PUB
#undef DLCB_PRI
#undef DLCB_RPRI
#undef DLCB_BUFFER_FUNC



