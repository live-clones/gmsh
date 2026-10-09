/**
 * @file dlthread_pool.h
 * @brief A custom thread pool.
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright (c) 2014-2015, Dominique LaSalle
 * @version 1
 * @date 2015-01-17
 */




#ifndef DLTHREAD_POOL_H
#define DLTHREAD_POOL_H




#include "domlib.h"




/******************************************************************************
* TYPES ***********************************************************************
******************************************************************************/


typedef enum dlthread_pool_ts_t {
  DLTHREAD_POOL_TS_LLRL = 0x00,
  DLTHREAD_POOL_TS_LLRF = 0x01,
  DLTHREAD_POOL_TS_LFRL = 0x02,
  DLTHREAD_POOL_TS_LFRF = 0x03,
  __DLTHREAD_POOL_TS_TERM
} dlthread_pool_ts_t;




/******************************************************************************
* FUNCTION PROTOTYPES *********************************************************
******************************************************************************/


void dlthread_pool_init(
    size_t nthreads);


void dlthread_pool_set_schedule(
    int schedule);


void dlthread_pool_finalize(void);


size_t dlthread_pool_add(
    void (* func)(void*ptr),
    void * ptr);


void dlthread_pool_wait(
    size_t task);




#endif
