/**
 * @file refine.c
 * @brief Refinement functions
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright 2015, Regents of the University of Minnesota
 * @version 1
 * @date 2015-05-20
 */




#ifndef MTMETIS_REIFNE_C
#define MTMETIS_REFINE_C




#include "refine.h"
#include "kwayrefine.h"
#include "eseprefine.h"
#include "vseprefine.h"
#include "check.h"




/******************************************************************************
* PRIVATE FUNCTIONS ***********************************************************
******************************************************************************/


/**
 * @brief Compute the parameters for performing kway partitioning.
 *
 * @param ctrl The control structure.
 * @param graph The graph.
 */
static void S_partparams_kway(
    ctrl_type * const ctrl,
    graph_type * const graph)
{
  vtx_type other,me,i,k,lvtx,nbrid,na;
  adj_type j, l;
  wgt_type mincut;
  kwnbrinfo_type * nbrinfo; 
  kwnbrinfo_type * myrinfo;
  adjinfo_type * mynbrs;
  vtx_iset_t * bnd;
  kwinfo_type * kwinfo;
  wgt_type * mypwgts;
  wgt_type ** gpwgts;

  tid_type const myid = dlthread_get_id(ctrl->comm);
  tid_type const nthreads = dlthread_get_nthreads(ctrl->comm);

  pid_type const nparts = ctrl->nparts;

  adj_type const * const * const gxadj = (adj_type const **)graph->xadj;
  vtx_type const * const * const gadjncy = (vtx_type const **)graph->adjncy;
  wgt_type const * const * const gvwgt = (wgt_type const **)graph->vwgt;
  wgt_type const * const * const gadjwgt = (wgt_type const **)graph->adjwgt;

  pid_type const * const * const gwhere  = (pid_type const **)graph->where;

  wgt_type * const pwgts = graph->pwgts;

  vtx_type const mynvtxs = graph->mynvtxs[myid];

  adj_type const * const xadj = gxadj[myid];
  vtx_type const * const adjncy = gadjncy[myid];
  wgt_type const * const vwgt = gvwgt[myid];
  wgt_type const * const adjwgt = gadjwgt[myid];
  pid_type const * const where = gwhere[myid];

  int const greedy = ctrl->rtype == MTMETIS_RTYPE_GREEDY;

  DL_ASSERT(graph->pwgts != NULL,"Non-allocated pwgts");
  DL_ASSERT(graph->where != NULL,"Non-allocated where");

  par_kwinfo_create(ctrl,graph);

  gpwgts = dlthread_get_shmem(sizeof(wgt_type*)*nthreads,ctrl->comm);

  mypwgts = gpwgts[myid] = wgt_init_alloc(0,nparts);

  /* reset the size of neighbor infor array */
  kwinfo = graph->kwinfo + myid; 
  nbrinfo = kwinfo->nbrinfo;
  kwinfo->nnbrpool = 0;
  bnd = kwinfo->bnd;

  mincut = 0;
  vtx_iset_clear(bnd);

  /* calculate partition weights */
  for (i=0;i<mynvtxs;++i) {
    mypwgts[where[i]] += vwgt[i];
  }
  dlthread_barrier(ctrl->comm);

  if (myid == 0) {
    /* someday I need to parallelize this via dlthreads */
    for (i=0; i<nparts;++i) {
      k = 0;
      for (j=0; j<nthreads;++j) {
        k += gpwgts[j][i];
      }
      pwgts[i] = k;
    }
  }

  /* calculate nbrinfo for vertices */
  for (i=0; i<mynvtxs; ++i) {
    myrinfo = nbrinfo+i;
    myrinfo->nnbrs = 0;
    myrinfo->id = 0;
    myrinfo->ed = 0;
    myrinfo->nbrstart = NULL_ADJ;

    na = dl_min(nparts,xadj[i+1]-xadj[i]);
    mynbrs = kwinfo_get_nbrs(kwinfo,i,na);

    me = where[i];

    for (j=xadj[i];j<xadj[i+1];++j) {
      k = adjncy[j];
      if (k < mynvtxs) {
        lvtx = k;
        nbrid = myid;
      } else {
        nbrid = gvtx_to_tid(k,graph->dist);
        lvtx = gvtx_to_lvtx(k,graph->dist); 
      }
      if (me == gwhere[nbrid][lvtx]) {
        myrinfo->id += adjwgt[j];
      } else {
        myrinfo->ed += adjwgt[j];
      }
    }

    /* Time to compute the particular external degrees */
    if (myrinfo->ed > 0) {
      mincut += myrinfo->ed;
      for (j=xadj[i]; j<xadj[i+1]; ++j) {
        k = adjncy[j];
        if (k < mynvtxs) {
          lvtx = k;
          nbrid = myid;
        } else {
          nbrid = gvtx_to_tid(k,graph->dist);
          lvtx = gvtx_to_lvtx(k,graph->dist); 
        }
        other = gwhere[nbrid][lvtx];
        if (me != other) {
          for (l=0; l<myrinfo->nnbrs; l++) {
            if (mynbrs[l].pid == other) {
              mynbrs[l].ed += adjwgt[j];
              break;
            }
          }
          if (l == myrinfo->nnbrs) {
            mynbrs[l].pid = other;
            mynbrs[l].ed  = adjwgt[j];
            myrinfo->nnbrs++;
          }
        }
      }

      /* Only ed-id>=0 nodes are considered to be in the boundary */
      if (is_bnd(myrinfo->id,myrinfo->ed,greedy)) {
        vtx_iset_add(i,bnd);
      }
      DL_ASSERT(myrinfo->nnbrs > 0,"No neighbors.");
    } else if (myrinfo->id == 0) {
      vtx_iset_add(i,bnd);
    } else {
      myrinfo->nbrstart = NULL_ADJ;
      kwinfo->nnbrpool -= na;
      DL_ASSERT_EQUALS(myrinfo->nnbrs,0,"%"PF_ADJ_T);
    }
  } 

  mincut = wgt_dlthread_sumreduce(mincut,ctrl->comm);

  dl_free(gpwgts[myid]);

  dlthread_barrier(ctrl->comm);
  if (myid == 0) {
    graph->mincut = mincut/2;
  }

  dlthread_free_shmem(gpwgts,ctrl->comm);

  /* the checks */
  DL_ASSERT(check_kwinfo(kwinfo,graph,(pid_type const **)gwhere),"Bad info");
}


/**
 * @brief Compute the parameters for performing vsep partitioning.
 *
 * @param ctrl The control structure.
 * @param graph The graph.
 * 
 * @return The newly setup vsinfo.
 */
static void S_partparams_vsep(
    ctrl_type * const ctrl,
    graph_type * const graph)
{
  vtx_type me,i,k;
  adj_type j;
  wgt_type minsep;
  vsnbrinfo_type * nbrinfo; 
  vsnbrinfo_type * myrinfo;
  vtx_iset_t * bnd;
  vsinfo_type * vsinfo;
  wgt_type * mypwgts;
  wgt_type ** gpwgts;

  adj_type const * const * const gxadj = (adj_type const **)graph->xadj;
  vtx_type const * const * const gadjncy = (vtx_type const **)graph->adjncy;
  wgt_type const * const * const gvwgt = (wgt_type const **)graph->vwgt;

  pid_type const * const * const gwhere  = (pid_type const **)graph->where;

  tid_type const myid = dlthread_get_id(ctrl->comm);
  tid_type const nthreads = dlthread_get_nthreads(ctrl->comm);

  wgt_type * const pwgts = graph->pwgts;

  vtx_type const mynvtxs = graph->mynvtxs[myid];

  adj_type const * const xadj = gxadj[myid];
  vtx_type const * const adjncy = gadjncy[myid];
  wgt_type const * const vwgt = gvwgt[myid];
  pid_type const * const where = gwhere[myid];

  DL_ASSERT(graph->pwgts != NULL,"Non-allocated pwgts");
  DL_ASSERT(graph->where != NULL,"Non-allocated where");

  gpwgts = dlthread_get_shmem(sizeof(wgt_type*)*nthreads,ctrl->comm);

  dlthread_barrier(ctrl->comm);

  mypwgts = gpwgts[myid] = wgt_init_alloc(0,MTMETIS_VSEP_NPARTS);

  par_vsinfo_create(ctrl,graph);

  vsinfo = graph->vsinfo+myid;
  nbrinfo = vsinfo->nbrinfo;
  bnd = vsinfo->bnd;

  minsep = 0;
  vtx_iset_clear(bnd);

  /* calculate partition weights */
  for (i=0;i<mynvtxs;++i) {
    mypwgts[where[i]] += vwgt[i];
  }
  dlthread_barrier(ctrl->comm);

  if (myid == 0) {
    /* someday I need to parallelize this via dlthreads */
    for (i=0;i<MTMETIS_VSEP_NPARTS;++i) {
      k = 0;
      for (j=0; j<nthreads;++j) {
        k += gpwgts[j][i];
      }
      pwgts[i] = k;
    }
  }

  /* calculate nbrinfo for vertices */
  for (i=0;i<mynvtxs;++i) {
    myrinfo = nbrinfo+i;
    me = where[i];

    if (me == MTMETIS_VSEP_SEP) {
      S_calc_conn(i,myid,mynvtxs,xadj,adjncy,gvwgt,gwhere,graph->dist, \
          myrinfo->con);
      minsep += vwgt[i];
      vtx_iset_add(i,bnd);
    }
  }

  minsep = wgt_dlthread_sumreduce(minsep,ctrl->comm);

  dl_free(gpwgts[myid]);

  dlthread_barrier(ctrl->comm);
  if (myid == 0) {
    graph->minsep = minsep;
  }

  dlthread_free_shmem(gpwgts,ctrl->comm);

  /* the checks */
  DL_ASSERT(check_vsinfo(vsinfo,graph,(pid_type const **)gwhere),"Bad info");
  DL_ASSERT(check_vsbnd(vsinfo->bnd,graph),"Bad boundary");
}


/**
 * @brief Compute the parameters for performing esep partitioning.
 *
 * @param ctrl The control structure.
 * @param graph The graph.
 */
static void S_partparams_esep(
    ctrl_type * const ctrl,
    graph_type * const graph)
{
  vtx_type me,i,k,lvtx;
  adj_type j;
  pid_type other;
  tid_type nbrid;
  wgt_type mincut;
  wgt_type con[2];
  esnbrinfo_type * nbrinfo; 
  esnbrinfo_type * myrinfo;
  vtx_iset_t * bnd;
  esinfo_type * esinfo;
  wgt_type * mypwgts;
  wgt_type ** gpwgts;

  adj_type const * const * const gxadj = (adj_type const **)graph->xadj;
  vtx_type const * const * const gadjncy = (vtx_type const **)graph->adjncy;
  wgt_type const * const * const gvwgt = (wgt_type const **)graph->vwgt;
  wgt_type const * const * const gadjwgt = (wgt_type const **)graph->adjwgt;

  pid_type const * const * const gwhere  = (pid_type const **)graph->where;

  tid_type const myid = dlthread_get_id(ctrl->comm);
  tid_type const nthreads = dlthread_get_nthreads(ctrl->comm);

  wgt_type * const pwgts = graph->pwgts;

  vtx_type const mynvtxs = graph->mynvtxs[myid];

  adj_type const * const xadj = gxadj[myid];
  vtx_type const * const adjncy = gadjncy[myid];
  wgt_type const * const vwgt = gvwgt[myid];
  wgt_type const * const adjwgt = gadjwgt[myid];
  pid_type const * const where = gwhere[myid];

  DL_ASSERT(graph->pwgts != NULL,"Non-allocated pwgts");
  DL_ASSERT(graph->where != NULL,"Non-allocated where");

  gpwgts = dlthread_get_shmem(sizeof(wgt_type*)*nthreads,ctrl->comm);

  dlthread_barrier(ctrl->comm);

  DL_ASSERT_EQUALS(ctrl->nparts,MTMETIS_ESEP_NPARTS,"%"PF_PID_T);

  mypwgts = gpwgts[myid] = wgt_init_alloc(0,ctrl->nparts);

  /* reset the size of neighbor infor array */
  par_esinfo_create(ctrl,graph);

  esinfo = graph->esinfo + myid;
  nbrinfo = esinfo->nbrinfo;
  bnd = esinfo->bnd;

  mincut = 0;
  vtx_iset_clear(bnd);

  /* calculate partition weights */
  for (i=0; i<mynvtxs; ++i) {
    mypwgts[where[i]] += vwgt[i];
  }
  dlthread_barrier(ctrl->comm);

  if (myid == 0) {
    /* someday I need to parallelize this via dlthreads */
    for (i=0;i<MTMETIS_ESEP_NPARTS;++i) {
      k = 0;
      for (j=0; j<nthreads;++j) {
        k += gpwgts[j][i];
      }
      pwgts[i] = k;
    }
  }

  /* calculate nbrinfo for vertices */
  for (i=0;i<mynvtxs;++i) {
    myrinfo = nbrinfo+i;
    me = where[i];

    con[0] = con[1] = 0;
    for (j=xadj[i];j<xadj[i+1];++j) {
      k = adjncy[j];
      if (k < mynvtxs) {
        lvtx = k;
        nbrid = myid;
      } else {
        lvtx = gvtx_to_lvtx(k,graph->dist);
        nbrid = gvtx_to_tid(k,graph->dist);
      }
      other = gwhere[nbrid][lvtx];
      con[other] += adjwgt[j];
    }
    if (con[me ^ 0x01] != 0) {
      /* boundary vertex */
      mincut += con[me ^ 0x01];
      vtx_iset_add(i,bnd);
    }

    /* copy over weights */
    myrinfo->con[0] = con[0];
    myrinfo->con[1] = con[1];
  }

  mincut = wgt_dlthread_sumreduce(mincut,ctrl->comm) / 2;

  dl_free(gpwgts[myid]);

  dlthread_barrier(ctrl->comm);
  if (myid == 0) {
    graph->mincut = mincut;
  }

  dlthread_free_shmem(gpwgts,ctrl->comm);

  /* the checks */
  DL_ASSERT(check_esinfo(esinfo,graph,(pid_type const **)gwhere),"Bad info");
  DL_ASSERT(check_esbnd(esinfo->bnd,graph),"Bad boundary");
}




/******************************************************************************
* PUBLIC FUNCTIONS ************************************************************
******************************************************************************/


vtx_type par_refine_graph(
    ctrl_type * const ctrl,
    graph_type * const graph)
{
  vtx_type nmoves; 

  tid_type const myid = dlthread_get_id(ctrl->comm);

  nmoves = 0;

  if (myid == 0) {
    dl_start_timer(&(ctrl->timers.refinement));
  }

  switch (ctrl->ptype) {
    case MTMETIS_PTYPE_ND:
    case MTMETIS_PTYPE_VSEP:
      if (graph->vsinfo == NULL) {
        S_partparams_vsep(ctrl,graph);
      }
      nmoves = par_vseprefine(ctrl,graph,graph->vsinfo+myid);
      break;
    case MTMETIS_PTYPE_RB:
    case MTMETIS_PTYPE_ESEP:
      if (graph->esinfo == NULL) {
        S_partparams_esep(ctrl,graph);
      }
      nmoves = par_eseprefine(ctrl,graph,graph->esinfo+myid);
      break;
    case MTMETIS_PTYPE_KWAY:
      if (graph->kwinfo == NULL) {
        S_partparams_kway(ctrl,graph);
      }
      nmoves = par_kwayrefine(ctrl,graph,graph->kwinfo+myid);
      break;
    default:
      dl_error("Unknown partition type '%d'\n",ctrl->ptype);
  }

  if (myid == 0) {
    dl_stop_timer(&(ctrl->timers.refinement));
  }

  return nmoves;
}




#endif
