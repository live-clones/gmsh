/**
 * @file kwinfo.h
 * @brief Types and function for uncoarsening information.
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright 2014, Regents of the University of Minnesota
 * @version 1
 * @date 2014-09-19
 */




#ifndef MTMETIS_KWINFO_H
#define MTMETIS_KWINFO_H




#include "base.h"
#include "graph.h"
#include "ctrl.h"




/******************************************************************************
* TYPES ***********************************************************************
******************************************************************************/


typedef struct adjinfo_type {
  wgt_type ed;
  pid_type pid;
} adjinfo_type;


typedef struct kwnbrinfo_type {
  wgt_type id;
  wgt_type ed;
  pid_type nnbrs;
  adj_type nbrstart;
} kwnbrinfo_type;


typedef struct kwinfo_type {
  pid_type nparts;
  vtx_iset_t * bnd;
  kwnbrinfo_type * nbrinfo;
  adj_type nnbrpool;
  adj_type basennbrs;
  size_t basebits;
  size_t npools;
  adjinfo_type ** nbrpools;
  dlthread_lock_t lock;
} kwinfo_type;




/******************************************************************************
* DOMLIB MACROS ***************************************************************
******************************************************************************/


#define DLMEM_PREFIX kwnbrinfo
#define DLMEM_TYPE_T kwnbrinfo_type
#include <dlmem_headers.h>
#undef DLMEM_TYPE_T
#undef DLMEM_PREFIX


#define DLMEM_PREFIX adjinfo
#define DLMEM_TYPE_T adjinfo_type
#include <dlmem_headers.h>
#undef DLMEM_TYPE_T
#undef DLMEM_PREFIX




/******************************************************************************
* FUNCTION PROTOTYPES *********************************************************
******************************************************************************/


#define par_kwinfo_create MTMETIS_par_kwinfo_create
/**
 * @brief Allocate the memory arrays for refinement. 
 *
 * @param ctrl The control structure.
 * @param graph The graph.
 */
void par_kwinfo_create(
    ctrl_type * ctrl,
    graph_type * graph);


#define par_kwinfo_free MTMETIS_par_kwinfo_free
/**
 * @brief Free a kwinfo and its associate memory owned by graph.
 *
 * @param graph The graph to free the kwinfo of.
 */
void par_kwinfo_free(
    graph_type * graph);




/******************************************************************************
* INLINE FUNCTIONS ************************************************************
******************************************************************************/


static inline adjinfo_type * kwinfo_get_nbrs(
    kwinfo_type * const kwinfo,
    vtx_type const v,
    pid_type const maxnnbrs)
{
  size_t pool;
  adj_type psize, pstart;
  kwnbrinfo_type * myrinfo;
  adjinfo_type * mynbrs;

  if (maxnnbrs == 0) {
    return NULL;
  }

  myrinfo = kwinfo->nbrinfo + v;

  if (myrinfo->nbrstart == NULL_ADJ) {
    myrinfo->nbrstart = kwinfo->nnbrpool;
    kwinfo->nnbrpool += maxnnbrs;
  }

  /* find the pool */
  pool = size_downlog2(((myrinfo->nbrstart+maxnnbrs-1)>>kwinfo->basebits)+1);
  psize = kwinfo->basennbrs << pool;
  pstart = psize-kwinfo->basennbrs;

  /* allocate new pool if it doesn't exist */
  if (kwinfo->nbrpools[pool] == NULL) {
    kwinfo->nbrpools[pool] = malloc(sizeof(adjinfo_type)*psize);
  }

  DL_ASSERT(myrinfo->nbrstart != NULL_ADJ,"Bad nbrstart");

  if (pstart > myrinfo->nbrstart) {
    /* Got pushed out of the previous pool - bump up nbrstart */
    myrinfo->nbrstart = pstart;
    kwinfo->nnbrpool = pstart+maxnnbrs;
    mynbrs = kwinfo->nbrpools[pool];
  } else {
    /* landed squarely in this pool */
    mynbrs =  kwinfo->nbrpools[pool] + (myrinfo->nbrstart - pstart);
  }

  DL_ASSERT(mynbrs < kwinfo->nbrpools[pool] + psize,"Bad mynbrs");
  DL_ASSERT(mynbrs >= kwinfo->nbrpools[pool],"Bad mynbrs");

  return mynbrs;
}


static inline adjinfo_type * kwinfo_get_nbrs_lk(
    kwinfo_type * const kwinfo,
    vtx_type const v,
    pid_type const maxnnbrs)
{
  size_t pool;
  adj_type psize, pstart;
  kwnbrinfo_type * myrinfo;
  adjinfo_type * mynbrs;

  if (maxnnbrs == 0) {
    return NULL;
  }

  myrinfo = kwinfo->nbrinfo + v;

  if (myrinfo->nbrstart == NULL_ADJ) {
    dlthread_set_lock(&(kwinfo->lock));
    myrinfo->nbrstart = kwinfo->nnbrpool;
    kwinfo->nnbrpool += maxnnbrs;
    dlthread_unset_lock(&(kwinfo->lock));
  }

  /* find the pool */
  pool = size_downlog2(((myrinfo->nbrstart+maxnnbrs-1)>>kwinfo->basebits)+1);
  psize = kwinfo->basennbrs << pool;
  pstart = psize-kwinfo->basennbrs;

  /* allocate new pool if it doesn't exist */
  if (kwinfo->nbrpools[pool] == NULL) {
    dlthread_set_lock(&(kwinfo->lock));
    if (kwinfo->nbrpools[pool] == NULL) {
      kwinfo->nbrpools[pool] = malloc(sizeof(adjinfo_type)*psize);
    }
    dlthread_unset_lock(&(kwinfo->lock));
  }

  DL_ASSERT(myrinfo->nbrstart != NULL_ADJ,"Bad nbrstart");

  if (pstart > myrinfo->nbrstart) {
    /* Got pushed out of the previous pool - bump up nbrstart */
    myrinfo->nbrstart = pstart;
    kwinfo->nnbrpool = pstart+maxnnbrs;
    mynbrs = kwinfo->nbrpools[pool];
  } else {
    /* landed squarely in this pool */
    mynbrs =  kwinfo->nbrpools[pool] + (myrinfo->nbrstart - pstart);
  }

  DL_ASSERT(mynbrs < kwinfo->nbrpools[pool] + psize,"Bad mynbrs");
  DL_ASSERT(mynbrs >= kwinfo->nbrpools[pool],"Bad mynbrs");

  return mynbrs;
}


static inline adjinfo_type const * kwinfo_get_nbrs_ro(
    kwinfo_type const * const kwinfo,
    vtx_type const v,
    pid_type const maxnnbrs)
{
  size_t pool;
  adj_type psize, pstart;
  kwnbrinfo_type * myrinfo;
  adjinfo_type * mynbrs;

  myrinfo = kwinfo->nbrinfo + v;

  if (maxnnbrs == 0 || myrinfo->nbrstart == NULL_ADJ) {
    return NULL;
  }

  /* find the pool */
  pool = size_downlog2(((myrinfo->nbrstart+maxnnbrs-1)>>kwinfo->basebits)+1);
  psize = kwinfo->basennbrs << pool;
  pstart = psize-kwinfo->basennbrs;

  mynbrs =  kwinfo->nbrpools[pool] + (myrinfo->nbrstart - pstart);

  DL_ASSERT(mynbrs < kwinfo->nbrpools[pool] + psize,"Bad mynbrs");
  DL_ASSERT(mynbrs >= kwinfo->nbrpools[pool],"Bad mynbrs");

  return mynbrs;
}



#endif
