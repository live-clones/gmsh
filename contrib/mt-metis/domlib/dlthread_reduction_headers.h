/**
 * @file dlthread_headers.h
 * @brief OpenMP reduction function prototypes and structures
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright (c) 2014-2015, Dominique LaSalle
 * @version 1
 * @date 2014-12-02
 */





/******************************************************************************
* FUNCTION PROTOTYPES *********************************************************
******************************************************************************/


#ifndef DLTHREAD_STATIC

/* prefixing ugliness */
#define DLTHREAD_PRE2(prefix,suffix) prefix ## _ ## suffix
#define DLTHREAD_PRE1(prefix,suffix) DLTHREAD_PRE2(prefix,suffix)
#define DLTHREAD_PUB(name) DLTHREAD_PRE1(DLTHREAD_PREFIX,name)




DLTHREAD_TYPE_T DLTHREAD_PUB(dlthread_sumreduce)(
    DLTHREAD_TYPE_T val,
    dlthread_comm_t comm);


DLTHREAD_TYPE_T DLTHREAD_PUB(dlthread_sumreduce_s)(
    DLTHREAD_TYPE_T val,
    size_t g,
    size_t n,
    dlthread_comm_t comm);


DLTHREAD_TYPE_T DLTHREAD_PUB(dlthread_maxreduce_value)(
    DLTHREAD_TYPE_T val,
    dlthread_comm_t comm);


size_t DLTHREAD_PUB(dlthread_maxreduce_index)(
    DLTHREAD_TYPE_T val,
    dlthread_comm_t comm);


DLTHREAD_TYPE_T DLTHREAD_PUB(dlthread_minreduce_value)(
    DLTHREAD_TYPE_T val,
    dlthread_comm_t comm);


size_t DLTHREAD_PUB(dlthread_minreduce_index)(
    DLTHREAD_TYPE_T val,
    dlthread_comm_t comm);


size_t DLTHREAD_PUB(dlthread_broadcast)(
    DLTHREAD_TYPE_T val,
    size_t root,
    dlthread_comm_t comm);


void DLTHREAD_PUB(dlthread_sumareduce)(
    DLTHREAD_TYPE_T * val,
    size_t n,
    dlthread_comm_t comm);


void DLTHREAD_PUB(dlthread_maxareduce)(
    DLTHREAD_TYPE_T * val,
    size_t n,
    dlthread_comm_t comm);


void DLTHREAD_PUB(dlthread_minareduce)(
    DLTHREAD_TYPE_T * val,
    size_t n,
    dlthread_comm_t comm);


/**
 * @brief Each thread calls this function with a set of counts in val. Upon
 * completition, val will contain the starting indexes for this thread, and if
 * provided, gval, will contain the starting indexes of each bucket.
 *
 * If two thread call this function with val arrays of:
 *   val1 = {3, 5} and val2 = {2, 4},
 * then after the call the val arrays and gval will be:
 *   val1 = {0, 3 + 2} val2 = {3, 3 + 2 + 5}, gval = {3 + 2, 3 + 2 + 5 + 4}.
 *
 * @param val Element counts for each bucket. 
 * @param n The number of buckets per thread.
 * @param gval The global bucket prefix (optional).
 * @param comm The thread communicator.
 */
void DLTHREAD_PUB(dlthread_prefixsum)(
    DLTHREAD_TYPE_T * val,
    size_t n,
    DLTHREAD_TYPE_T * const gval,
    dlthread_comm_t comm);




#undef DLTHREAD_PRE2
#undef DLTHREAD_PRE1
#undef DLTHREAD_PUB

#else

#define DLTHREAD_VISIBILITY static
#include "dlthread_reduction_funcs.h"
#undef DLTHREAD_VISIBILITY

#endif




