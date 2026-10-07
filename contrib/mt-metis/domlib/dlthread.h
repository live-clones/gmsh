/**
 * @file dlthread.h
 * @brief Function prototypes and types for thread communicators.
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright (c) 2014-2015, Dominique LaSalle
 * @version 1
 * @date 2014-12-05
 */




#ifndef DLTHREAD_H
#define DLTHREAD_H




#include "domlib.h"




/* see which implementation to use */
#if defined(DOMLIB_USE_PTHREADS) && DOMLIB_USE_PTHREADS == 1
#define __DOMLIB_USE_PTHREADS 1
#include <pthread.h>
#else
#include <omp.h>
#endif




/******************************************************************************
* TYPES ***********************************************************************
******************************************************************************/


typedef int dlthread_comm_t;
#ifdef __DOMLIB_USE_PTHREADS
typedef pthread_mutex_t dlthread_lock_t;
#else
typedef omp_lock_t dlthread_lock_t;
#endif



/******************************************************************************
* CONSTANTS *******************************************************************
******************************************************************************/


static dlthread_comm_t const DLTHREAD_COMM_NULL = (dlthread_comm_t)-1;
static dlthread_comm_t const DLTHREAD_COMM_SINGLE = (dlthread_comm_t)-2;
static dlthread_comm_t const DLTHREAD_COMM_ROOT = (dlthread_comm_t)0;




/******************************************************************************
* FUNCTION PROTOTYPES *********************************************************
******************************************************************************/


void dlthread_launch(
    size_t nthreads,
    void (*funptr)(void*),
    void * ptr);


void dlthread_exclude(
    dlthread_comm_t comm);


void dlthread_unexclude(
    dlthread_comm_t comm);


void dlthread_init_lock(
    dlthread_lock_t * lock);


void dlthread_free_lock(
    dlthread_lock_t * lock);


void dlthread_set_lock(
    dlthread_lock_t * lock);


void dlthread_unset_lock(
    dlthread_lock_t * lock);


void dlthread_init_locks(
    size_t lpt,
    dlthread_comm_t comm_idx);


void dlthread_lock_index(
    size_t tid,
    size_t idx,
    dlthread_comm_t comm);


void dlthread_unlock_index(
    size_t tid,
    size_t idx,
    dlthread_comm_t comm);


dlthread_comm_t dlthread_comm_split(
    size_t group,
    size_t ngroups,
    dlthread_comm_t comm);


void dlthread_comm_finalize(
    dlthread_comm_t comm);


size_t dlthread_get_id(
  dlthread_comm_t comm);


size_t dlthread_get_nthreads(
  dlthread_comm_t comm);


void dlthread_barrier(
    dlthread_comm_t comm);


void * dlthread_get_buffer(
    size_t nbytes,
    dlthread_comm_t comm);


void dlthread_free_shmem(
    void * ptr,
    dlthread_comm_t comm_idx);


void * dlthread_get_shmem(
    size_t nbytes,
    dlthread_comm_t comm_idx);


#ifdef __DOMLIB_USE_PTHREADS
#define dlthread_atomic_add(a,comm) \
  do { \
    dlthread_exclude(comm); \
    ++(a); \
    dlthread_unexclude(comm); \
  } while (0)
#else
#define dlthread_atomic_add(a,comm) \
  do { \
    _Pragma("omp atomic") \
    ++(a); \
  } while (0)
#endif


#endif
