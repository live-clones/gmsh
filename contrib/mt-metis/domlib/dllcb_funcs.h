/**
 * @file dllcb_funcs.h
 * @brief Functions for live communication buffers
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright (c) 2013-2015, Dominique LaSalle
 * @version 1
 * @date 2013-10-05
 */




/* prefixing ugliness */
#define DLLCB_PRE2(prefix,suffix) prefix ## _ ## suffix
#define DLLCB_PRE1(prefix,suffix) DLLCB_PRE2(prefix,suffix)
#define DLLCB_PUB(name) DLLCB_PRE1(DLLCB_PREFIX,name)
#define DLLCB_PRI(name) DLLCB_PRE1(_,DLLCB_PRE1(DLLCB_PREFIX,name))
#define DLLCB_RPRI(name) DLLCB_PRE1(r__,DLLCB_PRE1(DLLCB_PREFIX,name))

/* For Gmsh: the lists are shared without locks, which needs explicit memory
 * ordering on weakly ordered processors (ARM): nodes are published with
 * release stores and read with acquire loads, and the termination flags are
 * sequentially consistent */
#ifndef DLLCB_ATOMICS
#define DLLCB_ATOMICS
#define DLLCB_LOAD(x) __atomic_load_n(&(x),__ATOMIC_ACQUIRE)
#define DLLCB_STORE(x,v) __atomic_store_n(&(x),(v),__ATOMIC_RELEASE)
#define DLLCB_GETFLAG(x) __atomic_load_n(&(x),__ATOMIC_SEQ_CST)
#define DLLCB_SETFLAG(x,v) __atomic_store_n(&(x),(v),__ATOMIC_SEQ_CST)
#endif




/******************************************************************************
* PUBLIC FUNCTIONS ************************************************************
******************************************************************************/


#ifndef DLLCB_VISIBILITY
  #define DLLCB_DEFVIS
  #define DLLCB_VISIBILITY
#endif




DLLCB_VISIBILITY DLLCB_PUB(combuffer_t) * DLLCB_PUB(combuffer_create)(
    size_t const maxmsgs,
    dlthread_comm_t comm)
{
  size_t i;
  DLLCB_PUB(combuffer_t) * com;

  size_t const nthreads = dlthread_get_nthreads(comm);
  size_t const myid = dlthread_get_id(comm);

  com = dlthread_get_shmem(sizeof(DLLCB_PUB(combuffer_t)),comm);

  if (myid == 0) {
    com->comm = comm;
    com->infos = malloc(sizeof(DLLCB_PRI(info_t))*nthreads);
    com->lists = malloc(sizeof(DLLCB_PRI(list_t)*)*nthreads);
  }
  dlthread_barrier(comm);

  com->infos[myid].active = 0;
  com->infos[myid].finished = 0;
  com->infos[myid].maxmsgs = maxmsgs;
  com->infos[myid].lastmsg = 0;
  com->infos[myid].nodes = malloc(sizeof(DLLCB_PRI(node_t))*maxmsgs);
  com->lists[myid] = malloc(sizeof(DLLCB_PRI(list_t))*nthreads);

  /* init lists */
  for (i=0;i<nthreads;++i) {
    com->lists[myid][i].start = NULL;
    com->lists[myid][i].laststart = NULL;
    com->lists[myid][i].end = NULL;
  }
  dlthread_barrier(comm);

  return com;
}


DLLCB_VISIBILITY void DLLCB_PUB(combuffer_add)(
    size_t const dst, 
    DLLCB_TYPE_T const val, 
    DLLCB_PUB(combuffer_t) * const com)
{
  DLLCB_PRI(node_t) * msg, * last;

  size_t const myid = dlthread_get_id(com->comm);
  DLLCB_PRI(info_t) * const info = com->infos+myid;

  DL_ASSERT(info->lastmsg < info->maxmsgs,"Overflowed combuffer");

  msg = info->nodes + (info->lastmsg++);
  msg->next = NULL;
  msg->val = val;

  if (com->lists[dst][myid].end == NULL) {
    com->lists[dst][myid].end = msg;
    DLLCB_STORE(com->lists[dst][myid].start,msg);
  } else {
    last = com->lists[dst][myid].end;
    DL_ASSERT(last != NULL,"Last element in list is null");
    DLLCB_STORE(last->next,msg);
    com->lists[dst][myid].end = msg;
  }

  /* mark this thread as active and unfinished */
  DLLCB_SETFLAG(com->infos[dst].finished,0);
  DLLCB_SETFLAG(com->infos[dst].active,1);
}


DLLCB_VISIBILITY int DLLCB_PUB(combuffer_next)(
    DLLCB_TYPE_T * const r_next,
    DLLCB_PUB(combuffer_t) * const com)
{
  size_t i;
  DLLCB_PRI(node_t) * msg;

  size_t const myid = dlthread_get_id(com->comm);
  size_t const nthreads = dlthread_get_nthreads(com->comm);
  DLLCB_PRI(info_t) * const info = com->infos+myid;

  if (1 || info->active) {
    /* initial mark me as inactive */
    DLLCB_SETFLAG(info->active,0);
    for (i=0;i<nthreads;++i) {
      if ((msg = DLLCB_LOAD(com->lists[myid][i].start)) != NULL || \
          (com->lists[myid][i].laststart != NULL && \
           (msg = DLLCB_LOAD(com->lists[myid][i].laststart->next)) != NULL)) {
        /* found an msg, mark me as actie */
        DLLCB_SETFLAG(info->active,1);
        if (r_next) {
          com->lists[myid][i].laststart = msg;
          /* if they passed in null, they just want to check */
          DLLCB_STORE(com->lists[myid][i].start,DLLCB_LOAD(msg->next));
          *r_next = msg->val;
        } else {
          /* fix anything broken */
          DLLCB_STORE(com->lists[myid][i].start,msg);
        }
        return 1;
      }
    }
  }

  return 0;
}


DLLCB_VISIBILITY void DLLCB_PUB(combuffer_clear)(
    DLLCB_PUB(combuffer_t) * const com)
{
  size_t i;

  size_t const myid = dlthread_get_id(com->comm);
  size_t const nthreads = dlthread_get_nthreads(com->comm);
  DLLCB_PRI(info_t) * const info = com->infos+myid;

  dlthread_barrier(com->comm);

  info->lastmsg = 0;
  info->finished = 0;
  info->active = 0;

  for (i=0;i<nthreads;++i) {
    com->lists[myid][i].start = NULL;
    com->lists[myid][i].laststart = NULL;
    com->lists[myid][i].end = NULL;
  }

  dlthread_barrier(com->comm);
}


DLLCB_VISIBILITY int DLLCB_PUB(combuffer_finish)(
    DLLCB_PUB(combuffer_t) * const com)
{
  size_t t;

  size_t const myid = dlthread_get_id(com->comm);
  size_t const nthreads = dlthread_get_nthreads(com->comm);
  DLLCB_PRI(info_t) * const info = com->infos+myid;

  /* check to make sure I really don't have anymore work */
  if (DLLCB_PUB(combuffer_next)(NULL,com)) {
    /* I'm not finished */
    DLLCB_SETFLAG(info->finished,0);
    return 0;
  } else if (DLLCB_GETFLAG(info->finished) == 0) {
    DLLCB_SETFLAG(info->finished,1);
  }

  /* I'm finished, wait for others */
  for (t=(myid+1)%nthreads;t!=myid;t=((t+1)%nthreads)) {
    while (DLLCB_GETFLAG(com->infos[t].finished) == 0) {
      /* found someone who's not finished */
      if (DLLCB_PUB(combuffer_next)(NULL,com)) {
        /* I have work I can do */
        DLLCB_SETFLAG(info->finished,0);
        return 0;
      } else if (DLLCB_GETFLAG(info->finished) == 0) {
        /* if someone invalidated me -- re-validate myself */
        DLLCB_SETFLAG(info->finished,1);
      }
      _mm_pause(); /* don't max out the cpu */
    }
  }
  /* do a final check to make sure I didn't overwrite myself */
  if (DLLCB_PUB(combuffer_next)(NULL,com)) {
    DLLCB_SETFLAG(info->finished,0);
    return 0;
  }

  /* everbody is finished -- move to second stage */
  DLLCB_SETFLAG(info->finished,2);

  if (DLLCB_PUB(combuffer_next)(NULL,com)) {
    /* someone gave me work */
    DLLCB_SETFLAG(info->finished,0);
    return 0;
  }

  /* I'm finished, wait for others */
  t = myid;
  do {
    t=(t+1)%nthreads;
    while (DLLCB_GETFLAG(com->infos[t].finished) != 2) {
      if (DLLCB_PUB(combuffer_next)(NULL,com)) {
        DLLCB_SETFLAG(info->finished,0);
        return 0;
      }
      _mm_pause(); /* don't max out the cpu */
    }
  } while (t != myid);

  return 1;
}


DLLCB_VISIBILITY void DLLCB_PUB(combuffer_free)(
    DLLCB_PUB(combuffer_t) * com)
{
  dlthread_comm_t comm;

  size_t const myid = dlthread_get_id(com->comm);

  comm = com->comm;

  dlthread_barrier(comm);

  dl_free(com->lists[myid]);
  dl_free(com->infos[myid].nodes);

  dlthread_barrier(com->comm);

  if (myid == 0) {
    dl_free(com->lists);
    dl_free(com->infos);
  }

  dlthread_free_shmem(com,comm);
}


#ifdef DLLCB_DEFVIS
  #undef DLLCB_DEFVIS
  #undef DLLCB_VISIBILITY
#endif



#undef DLLCB_PRE
#undef DLLCB_PRE
#undef DLLCB_PUB
#undef DLLCB_PRI
#undef DLLCB_RPRI
#undef DLLCB_BUFFER_FUNC



