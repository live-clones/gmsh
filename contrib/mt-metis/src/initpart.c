/**
 * @file initpart.c
 * @brief Parallel initial partitioning routines (see pmetis and kmetis)
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright 2014, Regents of the University of Minnesota
 * @version 1
 * @date 2012-07-06
 */




#ifndef MTMETIS_INITPART_C
#define MTMETIS_INITPART_C




#include "initpart.h"
#include "imetis.h"




/******************************************************************************
* PUBLIC FUNCTIONS ************************************************************
******************************************************************************/


wgt_type par_initpart_cut(
    ctrl_type * const ctrl,
    graph_type * const graph)
{
  vtx_type voff, idx;
  wgt_type cut;
  adj_type * xadj;
  vtx_type * adjncy;
  wgt_type * adjwgt, * vwgt;
  pid_type * where = NULL, ** r_where;

  tid_type const myid = dlthread_get_id(ctrl->comm);
  tid_type const nthreads = dlthread_get_nthreads(ctrl->comm);

  vtx_type const nvtxs = graph->nvtxs; 

  size_t const tcuts = ctrl->ninitsolutions; 

  size_t myncuts = (tcuts / nthreads);

  if (myid == 0) {
    dl_start_timer(&ctrl->timers.initpart);
  }

  r_where = dlthread_get_shmem(sizeof(pid_type*),ctrl->comm);

  par_graph_gather(graph,&xadj,&adjncy,&vwgt,&adjwgt,&voff);

  myncuts += (myid < (tcuts%nthreads)) ? 1 : 0;

  if (myncuts > 0) {
    where = pid_alloc(nvtxs);

    cut = metis_initcut(ctrl,ctrl->nparts,ctrl->tpwgts,myncuts,1, \
        nvtxs,xadj,adjncy,vwgt,adjwgt,where);
  } else {
    cut = graph->tadjwgt+1;
  }

  idx = wgt_dlthread_minreduce_index(cut,ctrl->comm);

  if (myid == idx) {
    DL_ASSERT(where != NULL,"Non-cutting thread chosen");
    graph->mincut = cut;
    *r_where = where;
  }
  dlthread_barrier(ctrl->comm);

  par_graph_alloc_partmemory(ctrl,graph);

  par_vprintf(ctrl->verbosity,MTMETIS_VERBOSITY_MEDIUM,"Selected initial " \
      "partition with cut of %"PF_WGT_T"\n",graph->mincut);

  /* save the best where */
  pid_copy(graph->where[myid],(*r_where)+voff,graph->mynvtxs[myid]);

  /* implicit barrier */
  dlthread_free_shmem(r_where,ctrl->comm);

  if (myid == 0) {
    /* free the gathered graph */
    dl_free(xadj);
    dl_free(adjncy);
    dl_free(vwgt);
    dl_free(adjwgt);
  }

  if (where) {
    dl_free(where);
  }

  if (myid == 0) {
    dl_stop_timer(&ctrl->timers.initpart);
  }

  return graph->mincut;
}


wgt_type par_initpart_vsep(
    ctrl_type * const ctrl,
    graph_type * const graph)
{
  vtx_type voff, idx;
  wgt_type sep;
  adj_type * xadj;
  vtx_type * adjncy;
  wgt_type * adjwgt, * vwgt;
  pid_type * where = NULL, ** r_where;

  tid_type const myid = dlthread_get_id(ctrl->comm);
  tid_type const nthreads = dlthread_get_nthreads(ctrl->comm);

  vtx_type const nvtxs = graph->nvtxs; 

  size_t const tseps = ctrl->ninitsolutions; 

  size_t mynseps = (tseps / nthreads);

  size_t a = tseps % nthreads, b = nthreads, c = a;

  if (myid == 0) {
    dl_start_timer(&ctrl->timers.initpart);
  }

  r_where = dlthread_get_shmem(sizeof(pid_type*),ctrl->comm);

  par_graph_gather(graph,&xadj,&adjncy,&vwgt,&adjwgt,&voff);

  /* factor */
  while (c > 0) {
    if (a % c == 0 && b % c == 0) {
      a /= c;
      b /= c;
    }
    --c;
  }
  mynseps += (myid % b < a) ? 1 : 0;

  if (mynseps > 0) {
    where = pid_alloc(nvtxs);

    sep = metis_initsep(ctrl,mynseps,nvtxs,xadj,adjncy,vwgt,adjwgt, \
        where);
  } else {
    sep = graph->tvwgt+1;
  }

  idx = wgt_dlthread_minreduce_index(sep,ctrl->comm);

  if (myid == idx) {
    DL_ASSERT(where != NULL,"Non-cutting thread chosen");
    graph->minsep = sep;
    *r_where = where;
  }
  dlthread_barrier(ctrl->comm);

  par_graph_alloc_partmemory(ctrl,graph);

  par_vprintf(ctrl->verbosity,MTMETIS_VERBOSITY_MEDIUM,"Selected initial " \
      "partition with separator of %"PF_WGT_T"\n",graph->minsep);

  /* save the best where */
  pid_copy(graph->where[myid],(*r_where)+voff,graph->mynvtxs[myid]);

  /* implicit barrier */
  dlthread_free_shmem(r_where,ctrl->comm);

  if (myid == 0) {
    /* free the gathered graph */
    dl_free(xadj);
    dl_free(adjncy);
    dl_free(vwgt);
    dl_free(adjwgt);
  }

  if (where) {
    dl_free(where);
  }

  if (myid == 0) {
    dl_stop_timer(&ctrl->timers.initpart);
  }

  return graph->minsep;
}




#endif
