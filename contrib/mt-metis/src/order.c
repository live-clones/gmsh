/**
 * @file order.c
 * @brief Functions for creating a partition induced ordering (such as nested
 * dissection).
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright 2014, Regents of the University of Minnesota
 * @version 1
 * @date 2014-10-13
 */




#ifndef MTMETIS_ORDER_C
#define MTMETIS_ORDER_C




#include "order.h"
#include "partition.h"
#include "imetis.h"





/******************************************************************************
* TYPES ***********************************************************************
******************************************************************************/


typedef struct arg_type {
  ctrl_type * ctrl;
  graph_type * graph;
  pid_type * perm;
  pid_type ** dperm;
} arg_type;




/******************************************************************************
* PRIVATE FUNCTIONS ***********************************************************
******************************************************************************/


static void S_unify_perm(
    pid_type const * const * const dperm,
    graph_type * const graph,
    pid_type * const perm)
{
  vtx_type i;

  tid_type const myid = dlthread_get_id(graph->comm);

  for (i=0;i<graph->mynvtxs[myid];++i) {
    perm[graph->label[myid][i]] = dperm[myid][i];
  }
}


static void S_ser_order_nd(
    ctrl_type * const ctrl,
    graph_type * const graph,
    pid_type const offset,
    pid_type * const * const perm) 
{
  vtx_type i;

  metis_nd(ctrl,graph,perm);

  /* add my offset */
  for (i=0;i<graph->mynvtxs[0];++i) {
    perm[0][i] += offset;
  }
}


static void S_par_order_nd(
    ctrl_type * const ctrl,
    graph_type * const graph,
    pid_type const offset,
    pid_type ** const perm) 
{
  vtx_type v, g, mynvtxs, lvtx, i, nsep, lastvtx;
  tid_type hmyid, mygroup, lid;
  dlthread_comm_t lcomm;
  pid_type hoff;
  vtx_type * prefix, * sep;
  ctrl_type * myctrl;

  graph_type ** hgraphs;
  pid_type *** hperm;

  tid_type const nthreads = dlthread_get_nthreads(ctrl->comm);
  tid_type const myid = dlthread_get_id(ctrl->comm);

  /* handle the serial case */
  if (nthreads == 1) {
    S_ser_order_nd(ctrl,graph,offset,perm);
    return;
  }

  /* initial bisection */
  par_partition_vertexseparator(ctrl,graph,perm);

  if (myid == 0) {
    dl_start_timer(&(ctrl->timers.recursion));
  }

  hgraphs = dlthread_get_shmem((sizeof(graph_type*)*2) + (sizeof(pid_type**)*2) + \
      (sizeof(vtx_type)*(nthreads+1)),ctrl->comm);

  hperm = (pid_type***)(hgraphs+2);
  prefix = (vtx_type*)(hperm+2);

  sep = vtx_alloc(graph->mynvtxs[myid]);
  nsep = 0;
  for (i=0;i<graph->mynvtxs[myid];++i) {
    if (perm[myid][i] == MTMETIS_VSEP_SEP) {
      sep[nsep++] = i;
    }
  }
  prefix[myid] = nsep;
  dlthread_barrier(graph->comm);
  
  if (myid == 0) {
    vtx_prefixsum_exc(prefix,nthreads);
  }

  /* extract subgraphs and structure based on number of calling threads */
  mygroup = par_graph_extract_halves(graph,(pid_type const **)perm,hgraphs);

  /* free graph structure */
  dl_free(graph->xadj[myid]);
  dl_free(graph->adjncy[myid]);
  dl_free(graph->adjwgt[myid]);
  dl_free(graph->vwgt[myid]);

  if (mygroup == 0) {
    hoff = offset;
  } else {
    hoff = hgraphs[0]->nvtxs + offset;
  }
  dlthread_barrier(ctrl->comm);

  if (myid == 0) {
    graph->free_xadj = 0;
    graph->free_adjncy = 0;
    graph->free_vwgt = 0;
    graph->free_adjwgt = 0;
  }

  /* order my portion of the separator */
  lastvtx = graph->nvtxs + offset - prefix[myid];
  for (i=0;i<nsep;++i) {
    perm[myid][sep[i]] = --lastvtx;
  }
  dl_free(sep);

  lcomm = hgraphs[mygroup]->comm;

  hmyid = dlthread_get_id(lcomm);

  myctrl = par_ctrl_split(ctrl,hgraphs[mygroup]->nvtxs,MTMETIS_VSEP_NPARTS, \
      lcomm);

  DL_ASSERT_EQUALS((size_t)myctrl->comm,(size_t)hgraphs[mygroup]->comm,"%zu");

  hperm[mygroup] = dlthread_get_shmem(sizeof(pid_type*)*nthreads,lcomm);
  hperm[mygroup][hmyid] = pid_alloc(hgraphs[mygroup]->mynvtxs[hmyid]);

  if (myid == 0) {
    dl_stop_timer(&(ctrl->timers.recursion));
  }

  S_par_order_nd(myctrl,hgraphs[mygroup],hoff,hperm[mygroup]);

  if (myid == 0) {
    ctrl_combine_timers(ctrl,myctrl);
  }

  par_ctrl_free(myctrl);

  /* project my newly ordered vertices */
  mynvtxs = hgraphs[mygroup]->mynvtxs[hmyid];
  for (v=0;v<mynvtxs;++v) {
    g = hgraphs[mygroup]->label[hmyid][v];
    lid = gvtx_to_tid(g,graph->dist);
    lvtx = gvtx_to_lvtx(g,graph->dist);
    perm[lid][lvtx] = hperm[mygroup][hmyid][v];
  }

  dl_free(hperm[mygroup][hmyid]);
  dlthread_free_shmem(hperm[mygroup],lcomm);

  par_graph_free(hgraphs[mygroup]);

  dlthread_comm_finalize(lcomm);
  dlthread_free_shmem(hgraphs,ctrl->comm);
}




/******************************************************************************
* PUBLIC FUNCTIONS ************************************************************
******************************************************************************/


void par_order_nd(
    ctrl_type * const ctrl,
    graph_type * const graph,
    pid_type ** const perm) 
{
  if (ctrl->nthreads > 1) {
    S_par_order_nd(ctrl,graph,0,perm);
  } else {
    S_ser_order_nd(ctrl,graph,0,perm);
  }
}




#endif
