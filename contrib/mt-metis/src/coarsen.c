/**
 * @file coarsen.c
 * @brief Coarsening functions
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright 2013, Regents of the University of Minnesota
 * @version 1
 * @date 2013-05-03
 */




#ifndef MTMETIS_COARSEN_C
#define MTMETIS_COARSEN_C




#include "coarsen.h"
#include "aggregate.h"
#include "contract.h"
#include "check.h"




/******************************************************************************
* PUBLIC PARALLEL FUNCTIONS ***************************************************
******************************************************************************/


graph_type * par_coarsen_graph(
    ctrl_type * ctrl,
    graph_type * graph)
{
  vtx_type cnvtxs;
  vtx_type ** gmatch;
  vtx_type * fcmap;
  vtx_type * match;

  tid_type const nthreads = dlthread_get_nthreads(ctrl->comm);
  tid_type const myid = dlthread_get_id(ctrl->comm);

  if (graph->nvtxs <= 1) {
    return graph;
  }

  DL_ASSERT_EQUALS((size_t)ctrl->comm,(size_t)graph->comm,"%zu");

  if (myid == 0) { 
    dl_start_timer(&ctrl->timers.coarsening);
  }

  fcmap = vtx_alloc(graph->mynvtxs[myid]);
  match = vtx_init_alloc(NULL_VTX,graph->mynvtxs[myid]);

  DL_ASSERT(check_graph(graph),"Invalid graph");

  gmatch = dlthread_get_shmem(sizeof(vtx_type*)*nthreads,ctrl->comm);

  gmatch[myid] = match;

  par_vprintf(ctrl->verbosity,MTMETIS_VERBOSITY_HIGH,"Graph{%zu} has %" \
      PF_VTX_T"[%"PF_VTX_T"] vertices, %"PF_ADJ_T" edges, and %"PF_TWGT_T \
      " exposed edge weight.\n",graph->level,graph->nvtxs,ctrl->coarsen_to, \
      graph->nedges,graph->tadjwgt);

  /* allocate memory for cmap, if it has not already been done due to
     multiple cuts */
  if (myid == 0) {
    if (graph->cmap == NULL) {
      /* threads need to allocate their own chunk inside the matching 
       * functions */
      graph->cmap = r_vtx_alloc(nthreads);
    }

    /* set the maximum allowed coarsest vertex weight */
    ctrl->maxvwgt = \
        /* 1.5 * graph->tvwgt / ctrl->coarsen_to; */
        1.5*graph->tvwgt / dl_max(ctrl->coarsen_to,graph->nvtxs/4.0);
  }
  dlthread_barrier(ctrl->comm);

  cnvtxs = par_aggregate_graph(ctrl,graph,gmatch,fcmap);

  par_contract_graph(ctrl,graph,cnvtxs,(vtx_type const **)gmatch,fcmap);

  dlthread_free_shmem(gmatch,ctrl->comm);

  dl_free(fcmap);
  dl_free(match);

  DL_ASSERT(check_graph(graph->coarser),"Invalid graph");

  if (myid == 0) {
    dl_stop_timer(&ctrl->timers.coarsening);
  }

  return graph->coarser;
}




#endif
