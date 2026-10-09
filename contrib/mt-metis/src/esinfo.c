/**
 * @file esinfo.c
 * @brief Functions for manipulating esinfo structures.
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright 2015, Regents of the University of Minnesota
 * @version 1
 * @date 2015-02-26
 */




#ifndef MTMETIS_ESINFO_C
#define MTMETIS_ESINFO_C




#include "esinfo.h"





/******************************************************************************
* DOMLIB MACROS ***************************************************************
******************************************************************************/


#define DLMEM_PREFIX esnbrinfo
#define DLMEM_TYPE_T esnbrinfo_type
#include <dlmem_funcs.h>
#undef DLMEM_TYPE_T
#undef DLMEM_PREFIX




/******************************************************************************
* PUBLIC FUNCTIONS ************************************************************
******************************************************************************/


void esinfo_free(
    graph_type * const graph)
{
  tid_type myid;
  esinfo_type * esinfo;

  for (myid=0;myid<graph->dist.nthreads;++myid) {
    esinfo = graph->esinfo+myid;

    if (esinfo->bnd) {
      vtx_iset_free(esinfo->bnd);
    }
    if (esinfo->nbrinfo) {
      dl_free(esinfo->nbrinfo);
    }
  }

  dl_free(graph->esinfo);
  graph->esinfo = NULL;
}


void par_esinfo_create(
    ctrl_type * const ctrl,
    graph_type * const graph)
{
  esinfo_type * esinfo;

  tid_type const myid = dlthread_get_id(ctrl->comm);
  tid_type const nthreads = dlthread_get_nthreads(ctrl->comm);

  esinfo = dlthread_get_shmem(sizeof(esinfo_type)*nthreads,ctrl->comm);

  esinfo += myid;

  esinfo->bnd = vtx_iset_create(0,graph->mynvtxs[myid]);
  esinfo->nbrinfo = esnbrinfo_alloc(graph->mynvtxs[myid]);

  if (myid == 0) {
    graph->esinfo = esinfo;
  }

  dlthread_barrier(ctrl->comm);
}


void par_esinfo_free(
    graph_type * const graph)
{
  esinfo_type * esinfo;

  tid_type const myid = dlthread_get_id(graph->comm);

  esinfo = graph->esinfo+myid;

  if (esinfo->bnd) {
    vtx_iset_free(esinfo->bnd);
  }
  if (esinfo->nbrinfo) {
    dl_free(esinfo->nbrinfo);
  }

  dlthread_free_shmem(graph->esinfo,graph->comm);
  if (myid == 0) {
    graph->esinfo = NULL;
  }
}




#endif


