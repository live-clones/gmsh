/**
 * @file dlthread.c
 * @brief Functions for thread communicators.
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright (c) 2014-2015, Dominique LaSalle
 * @version 1
 * @date 2014-12-05
 */




#ifndef DLTHREAD_C
#define DLTHREAD_C




#include "dlthread.h"




/******************************************************************************
* THREAD LOCAL STORAGE ********************************************************
******************************************************************************/


#if __STDC_VERSION__ >= 201101L
  /* C11 */
  #define THREAD_LOCAL thread_local
#elif defined(__GNUC__) || defined (__GNUG__)
  /* GNU Compliant */  
  #define THREAD_LOCAL __thread
#elif defined(_MSC_VER)
  /* Microsoft */
  #define THREAD_LOCAL __declspec(thread)
#else
  /* break things */
  THIS WILL NOT WORK WITHOUT SOMETYPE OF THREAD LOCAL STORAGE 
  -- TRY A DIFFERENT COMPILER
#endif




/******************************************************************************
* OMP/PTHREAD SETUP ***********************************************************
******************************************************************************/


#ifndef CACHE_LINE_SIZE
#define CACHE_LINE_SIZE 64
#endif


#ifdef __DOMLIB_USE_PTHREADS

#include <pthread.h>


typedef pthread_barrier_t barrier_t;


/* perhaps change these to inline functions to eliminate possible warnings */
#define init_lock(lock) pthread_init_mutex(lock,NULL)
#define set_lock(lock) pthread_lock_mutex(lock)
#define unset_lock(lock) pthread_unlock_mutex(lock)
#define free_lock(lock) pthread_mutex_destroy(lock)
#define init_barrier(bar,nthreads) pthread_barrier_init(bar,NULL,nthreads)
#define free_barrier(bar) pthread_barrier_destroy(bar)


static inline int wait_barrier(
    barrier_t * const bar,
    size_t const myid)
{
  return pthread_barrier_wait(bar);
}


#else

#include <omp.h>


static size_t const IDX_OFFSET = CACHE_LINE_SIZE / sizeof(int);


typedef struct barrier_t {
  size_t nthreads;
  int volatile * vec;
} barrier_t;


/* perhaps change these to inline functions to eliminate possible warnings */
#define init_lock(lock) omp_init_lock(lock)
#define set_lock(lock) omp_set_lock(lock)
#define unset_lock(lock) omp_unset_lock(lock)
#define free_lock(lock) omp_destroy_lock(lock)


/* For Gmsh: the flags of the barrier order the memory accesses of the threads
 * also on weakly ordered processors (ARM): release stores, acquire loads */
#define BAR_LOAD(x) __atomic_load_n(&(x),__ATOMIC_ACQUIRE)
#define BAR_STORE(x,v) __atomic_store_n(&(x),(v),__ATOMIC_RELEASE)


static inline void init_barrier(
    barrier_t * const bar,
    size_t const nthreads)
{
  bar->nthreads = nthreads;
  bar->vec = calloc(nthreads,CACHE_LINE_SIZE);
}


static inline void free_barrier(
    barrier_t * const bar)
{
  size_t i;
  int volatile * mybar;

  mybar = bar->vec;

  /* check to make sure bar is not in use */
  for (i=0;i<bar->nthreads;++i) {
    while (mybar[i*IDX_OFFSET] != 0) {
      _mm_pause();  
    }
  }

  /* keep the compiler from whining about freeing volatile memory */
  dl_free((void*)bar->vec);
}


static inline void wait_barrier(
    barrier_t * const bar,
    size_t const myid)
{
  int volatile * mybar;
  size_t lc, rc;

  DL_ASSERT(myid<bar->nthreads,"Invalid thread num %zu/%zu in barrier\n", \
      myid,bar->nthreads);

  if (bar->nthreads == 1) {
    /* don't waste time for a single thread */
    return; 
  } else if ((int)bar->nthreads == omp_get_num_threads()) {
    /* all threads are in this barrier */
    #pragma omp barrier
  }

  mybar = bar->vec;

  lc = (myid*2)+1;
  rc = (myid*2)+2;

  if (lc >= bar->nthreads) {
    lc = 0;
  }
  if (rc >= bar->nthreads) {
    rc = 0;
  }

  /* wait for my children to reach the barrier */
  while ((lc && BAR_LOAD(mybar[lc*IDX_OFFSET]) != 1) || \
      (rc && BAR_LOAD(mybar[rc*IDX_OFFSET]) != 1)) {
    _mm_pause();
  }

  /* mark that I have reached the barrier */
  BAR_STORE(mybar[myid*IDX_OFFSET],1);

  /* wait for the root thread to be finished */
  while (BAR_LOAD(mybar[0]) != 1) {
    _mm_pause();
  }

  /* barrier achieved -- now reset */

  /* wait for my children to reset */
  while ((lc && BAR_LOAD(mybar[lc*IDX_OFFSET]) == 1) || \
      (rc && BAR_LOAD(mybar[rc*IDX_OFFSET]) == 1)) {
    _mm_pause();
  }

  /* reset myself */
  BAR_STORE(mybar[myid*IDX_OFFSET],2);

  /* wait for the root to reset */
  while (BAR_LOAD(mybar[0]) == 1) {
    _mm_pause(); 
  }

  /* so that when a barrier is free'd, we can be sure all threads are done
   * using the array */
  BAR_STORE(mybar[myid*IDX_OFFSET],0);

  /* make sure we protect against synchronization breaking optimiztions */
  __atomic_thread_fence(__ATOMIC_SEQ_CST); /* For Gmsh */
}


#endif




/******************************************************************************
* TYPES ***********************************************************************
******************************************************************************/


typedef struct comm_t {
  int in_use;
  size_t nthreads;
  size_t bufsize;
  size_t nlarray; /* lock array for each thread */
  void * buffer;
  dlthread_lock_t loc;
  dlthread_lock_t ** larray;
  barrier_t bar;
} comm_t;


typedef struct thread_arg_t {
  size_t id;
  void * ptr;
  void (*funptr)(void*);
} thread_arg_t;




/******************************************************************************
* CONSTANTS *******************************************************************
******************************************************************************/


static size_t const __DEFAULT_BYTES_PER_THREAD = 128;
#define __MAX_NCOMMS 1024




/******************************************************************************
* VARIABLES *******************************************************************
******************************************************************************/


static dlthread_lock_t * ncomms_lock = NULL;
static dlthread_comm_t last_free_comm = 1; /* space for root comm */
static comm_t my_comms[__MAX_NCOMMS];
static THREAD_LOCAL size_t my_ids[__MAX_NCOMMS];
static THREAD_LOCAL size_t __local_buffer_size = 0;
static THREAD_LOCAL void * __local_buffer = NULL;



/******************************************************************************
* PRIVATE FUNCTIONS ***********************************************************
******************************************************************************/


static void __config_comm(
    comm_t * const comm,
    size_t const nthreads)
{
  size_t maxthreads;

  comm->in_use = 1;
  comm->nthreads = nthreads;
  comm->larray = NULL;

  /* handle data types up to size 16 and round up to a power of two */
  maxthreads = size_uppow2(nthreads);
  comm->bufsize = size_uppow2((__DEFAULT_BYTES_PER_THREAD*maxthreads) + 4096);
  comm->buffer = malloc(comm->bufsize);

  init_lock(&comm->loc);
  init_barrier(&comm->bar,nthreads);
}


static void __thread_start(
    void * const ptr)
{
  size_t myid;
  thread_arg_t * arg;

  arg = ptr;

  myid = arg->id;

  /* set my thread id for this communicator */
  my_ids[DLTHREAD_COMM_ROOT] = myid;

  arg->funptr(arg->ptr);
}




/******************************************************************************
* PUBLIC FUNCTIONS ************************************************************
******************************************************************************/


void dlthread_launch(
    size_t const nthreads,
    void (*funptr)(void*),
    void * const ptr)
{
  size_t myid, i;
  comm_t * comm;

  comm = my_comms+DLTHREAD_COMM_ROOT;

  ncomms_lock = malloc(sizeof(dlthread_lock_t));
  init_lock(ncomms_lock);

  __config_comm(comm,nthreads); 

  #ifdef __DOMLIB_USE_PTHREADS  
  size_t i;
  pthread_t * threads;
  thread_arg_t * args;

  threads = malloc(sizeof(pthread_t)*nthreads);
  args = malloc(sizeof(thread_arg_t)*nthreads);

  for (i=0;i<nthreads;++i) {
    args[i].id = i;
    args[i].ptr = ptr;
    args[i].funptr = funptr;
    pthread_create(threads+i,NULL,&__thread_start,args+i);
  }
  for (i=0;i<nthreads;++i) {
    pthread_join(threads[i],NULL);
  }

  dl_free(threads);
  dl_free(args);
  #else
  #pragma omp parallel num_threads(nthreads)
  {
    thread_arg_t arg;
    arg.id = omp_get_thread_num();
    arg.ptr = ptr;
    arg.funptr = funptr;
    __thread_start(&arg);
  }
  #endif

  if (comm->larray) {
    for (myid=0;myid<nthreads;++myid) {
      /* destroy locks if they exist */
      for (i=0;i<comm->nlarray;++i) {
        free_lock(comm->larray[myid]+i);
      }
      dl_free(comm->larray[myid]);
    }

    dl_free(comm->larray);
  }

  dl_free(comm->buffer);
  free_barrier(&(comm->bar));
  free_lock(&(comm->loc));

  comm->in_use = 0;

  free_lock(ncomms_lock);
  dl_free(ncomms_lock);
}


void dlthread_exclude(
    dlthread_comm_t const comm_idx)
{
  comm_t * gcomm;

  if (comm_idx != DLTHREAD_COMM_SINGLE) {
    gcomm = my_comms+comm_idx;

    set_lock(&gcomm->loc);
  }
}


void dlthread_unexclude(
    dlthread_comm_t const comm_idx)
{
  comm_t * gcomm;

  if (comm_idx != DLTHREAD_COMM_SINGLE) {
    gcomm = my_comms+comm_idx;

    unset_lock(&gcomm->loc);
  }
}


void dlthread_init_lock(
    dlthread_lock_t * const lock)
{
  init_lock(lock);
}


void dlthread_free_lock(
    dlthread_lock_t * lock)
{
  free_lock(lock);
}


void dlthread_set_lock(
    dlthread_lock_t * const lock)
{
  set_lock(lock);
}


void dlthread_unset_lock(
    dlthread_lock_t * const lock)
{
  unset_lock(lock);
}


void dlthread_init_locks(
    size_t const lpt,
    dlthread_comm_t const comm_idx)
{
  size_t i, myid, nthreads;
  comm_t * gcomm;

  if (comm_idx != DLTHREAD_COMM_SINGLE) {
    myid = dlthread_get_id(comm_idx);
    nthreads = dlthread_get_nthreads(comm_idx);

    gcomm = my_comms+comm_idx;

    if (myid == 0) {
      gcomm->larray = malloc(sizeof(dlthread_lock_t*)*nthreads);
      gcomm->nlarray = lpt;
    }

    dlthread_barrier(comm_idx);

    gcomm->larray[myid] = malloc(sizeof(dlthread_lock_t)*lpt);

    for (i=0;i<lpt;++i) {
      init_lock(gcomm->larray[myid]+i);
    }

    dlthread_barrier(comm_idx);
  }
}


void dlthread_lock_index(
    size_t const tid,
    size_t const idx,
    dlthread_comm_t const comm_idx)
{
  size_t i;
  comm_t * gcomm;

  if (comm_idx != DLTHREAD_COMM_SINGLE) {
    gcomm = my_comms+comm_idx;

    i = idx % gcomm->nlarray;

    set_lock(gcomm->larray[tid]+i);
  }
}


void dlthread_unlock_index(
    size_t const tid,
    size_t const idx,
    dlthread_comm_t const comm_idx)
{
  size_t i;
  comm_t * gcomm;

  if (comm_idx != DLTHREAD_COMM_SINGLE) {
    gcomm = my_comms+comm_idx;

    i = idx % gcomm->nlarray;

    unset_lock(gcomm->larray[tid]+i);
  }
}


dlthread_comm_t dlthread_comm_split(
    size_t group,
    size_t ngroups,
    dlthread_comm_t const comm_idx)
{
  size_t i, lid, cidx, myid, nthreads;
  size_t volatile * tid;
  comm_t * lcomm;
  dlthread_comm_t volatile * gcom;
  dlthread_comm_t cid;

  if (comm_idx != DLTHREAD_COMM_SINGLE) {
    myid = dlthread_get_id(comm_idx);
    nthreads = dlthread_get_nthreads(comm_idx);

    DL_ASSERT(group < ngroups,"Invalid group %zu/%zu for thread %zu/%zu\n", \
        group,ngroups,myid,nthreads);

    gcom = dlthread_get_buffer((sizeof(dlthread_comm_t)*ngroups) + \
        (sizeof(size_t)*nthreads),comm_idx);
    tid = (size_t*)(gcom+ngroups);

    if (myid == 0) {
      /* number the new communicators */
      set_lock(ncomms_lock);
      for (i=0;i<ngroups;++i) {
        /* find the next free communicator */
        while (my_comms[last_free_comm].in_use == 1) {
          ++last_free_comm;
        }
        gcom[i] = last_free_comm++;
        /* initialize my comm */
        my_comms[gcom[i]].nthreads = 0;
        my_comms[gcom[i]].in_use = 1;
      }
      unset_lock(ncomms_lock);
    }

    /* I use an alarming number of barriers here -- someday reduce this */

    dlthread_barrier(comm_idx);

    cid = gcom[group];

    DL_ASSERT(cid < __MAX_NCOMMS,"Exceeded maximum number of communicators\n");

    lcomm = my_comms+cid;
    tid[myid] = group;

    dlthread_barrier(comm_idx);

    if (myid == 0) {
      /* number the threads per communicator */
      for (i=0;i<nthreads;++i) {
        cidx = gcom[tid[i]];
        tid[i] = my_comms[cidx].nthreads++;
      }
    }

    dlthread_barrier(comm_idx);

    lid = tid[myid];

    if (lid == 0) {
      /* root for each comm */
      __config_comm(lcomm,lcomm->nthreads);
    }

    my_ids[cid] = lid;

    dlthread_barrier(comm_idx);

    dprintf("[%zu:%zu] new communicator %zu with %zu threads\n",myid,lid, \
        (size_t)cid,lcomm->nthreads);
  } else {
    cid = DLTHREAD_COMM_SINGLE;
  } 

  return cid;
}


void dlthread_comm_finalize(
    dlthread_comm_t const comm_idx)
{
  size_t i, myid;
  comm_t * comm;

  if (comm_idx != DLTHREAD_COMM_SINGLE) {
    myid = dlthread_get_id(comm_idx);

    dlthread_barrier(comm_idx);

    comm = my_comms+comm_idx;

    if (comm->larray) {
      /* destroy locks if they exist */
      for (i=0;i<comm->nlarray;++i) {
        free_lock(comm->larray[myid]+i);
      }
      dl_free(comm->larray[myid]);

      dlthread_barrier(comm_idx);

      if (myid == 0) {
        dl_free(comm->larray);
      }
    }

    if (myid == 0) {
      dl_free(comm->buffer);
      free_barrier(&(comm->bar));
      free_lock(&(comm->loc));

      comm->in_use = 0;

      set_lock(ncomms_lock);
      if (comm_idx < last_free_comm) {
        last_free_comm = comm_idx;
      }
      unset_lock(ncomms_lock);
    }
  } else {
    /* clear this threads local buffer if it exists */
    if (__local_buffer) {
      dl_free(__local_buffer);
      __local_buffer = NULL;
      __local_buffer_size = 0;
    }
  }
}


size_t dlthread_get_id(
    dlthread_comm_t const comm)
{
  if (comm != DLTHREAD_COMM_SINGLE) {
    return my_ids[comm]; 
  } else {
    return 0;
  }
}


size_t dlthread_get_nthreads(
    dlthread_comm_t const comm)
{
  if (comm != DLTHREAD_COMM_SINGLE) {
    return my_comms[comm].nthreads;
  } else {
    return 1;
  }
}


void * dlthread_get_shmem(
    size_t nbytes,
    dlthread_comm_t const comm_idx)
{
  size_t myid;
  void * ptr;
  comm_t * comm;

  if (comm_idx != DLTHREAD_COMM_SINGLE) {
    myid = dlthread_get_id(comm_idx);

    comm = my_comms+comm_idx;

    DL_ASSERT(comm->buffer != NULL,"Null buffer on communicator %zu\n", \
        (size_t)comm_idx);

    if (myid == 0) {
      ptr = malloc(nbytes); 

      ((void**)comm->buffer)[0] = ptr;
    }

    dlthread_barrier(comm_idx);

    ptr = ((void**)comm->buffer)[0];

    dlthread_barrier(comm_idx);
  } else {
    ptr = malloc(nbytes);
  }

  return ptr;
}


void dlthread_free_shmem(
    void * ptr,
    dlthread_comm_t const comm_idx)
{
  size_t const myid = dlthread_get_id(comm_idx);

  dlthread_barrier(comm_idx);

  if (myid == 0) {
    dl_free(ptr);
  }
}


void dlthread_barrier(
    dlthread_comm_t const comm_idx)
{
  if (comm_idx != DLTHREAD_COMM_SINGLE) {
    wait_barrier(&(my_comms[comm_idx].bar),dlthread_get_id(comm_idx));
  }
}


void * dlthread_get_buffer(
    size_t const n,
    dlthread_comm_t const comm_idx)
{
  void * buffer;
  comm_t * comm;

  size_t const myid = dlthread_get_id(comm_idx);

  if (comm_idx != DLTHREAD_COMM_SINGLE) {
    comm = my_comms+comm_idx;

    if (comm->bufsize < n) {
      dlthread_barrier(comm_idx);
      if (myid == 0) {
        dl_free(comm->buffer);
        comm->buffer = malloc(n);
        comm->bufsize = n;
      }
      dlthread_barrier(comm_idx);
    }
    buffer = comm->buffer;
  } else {
    if (__local_buffer_size < n) {
      __local_buffer = realloc(__local_buffer,n);
      __local_buffer_size = n;
    }
    buffer = __local_buffer; 
  }
  return buffer;
}





#endif
