/**
 * @file project.c
 * @brief Projection functions. 
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright 2015, Regents of the University of Minnesota
 * @version 1
 * @date 2015-05-20
 */




#ifndef PROJECT_C
#define PROJECT_C




#include "project.h"




/******************************************************************************
* PRIVATE FUNCTIONS ***********************************************************
******************************************************************************/


/**
 * @brief Project a kway partitioning.
 *
 * @param ctrl The control structure containing runtime parameters.
 * @param graph The partitioned graph to project the partition from.
 */
static void S_project_kway(
    ctrl_type * const ctrl,
    graph_type * const graph)
{
  vtx_type i, k, pi, lvtx, nbrid, ned, nid;
  adj_type j, l, istart, iend;
  pid_type me, other, na;
  wgt_type tid, ted;
  kwnbrinfo_type * myrinfo;
  adjinfo_type * mynbrs;
  vtx_type * id, * ed;
  pid_type * htable;
  vtx_iset_t * bnd;
  kwnbrinfo_type * nbrinfo;
  kwinfo_type * gkwinfo, * kwinfo;

  tid_type const myid = dlthread_get_id(ctrl->comm);

  pid_type const nparts = ctrl->nparts;
  graph_type * const cgraph = graph->coarser;
  vtx_type * const * const gcmap = graph->cmap;
  adj_type const * const * const gxadj = (adj_type const **)graph->xadj;
  vtx_type const * const * const gadjncy = (vtx_type const **)graph->adjncy;
  wgt_type const * const * const gadjwgt = (wgt_type const **)graph->adjwgt;

  int const greedy = ctrl->rtype == MTMETIS_RTYPE_GREEDY;

  pid_type ** const gwhere = graph->where;
  pid_type * const where = gwhere[myid];

  vtx_type const mynvtxs = graph->mynvtxs[myid];

  vtx_type * const cmap = gcmap[myid];

  adj_type const * const xadj = gxadj[myid];
  vtx_type const * const adjncy = gadjncy[myid];
  wgt_type const * const adjwgt = gadjwgt[myid];

  gkwinfo = cgraph->kwinfo;
  
  ed = vtx_alloc(mynvtxs);
  id = vtx_alloc(mynvtxs);

  ned = nid = 0;
  for (i=0;i<mynvtxs;++i) {
    k = cmap[i];
    if (k < cgraph->mynvtxs[myid]) {
      lvtx = k;
      nbrid = myid;
    } else {
      lvtx = gvtx_to_lvtx(k,cgraph->dist);
      nbrid = gvtx_to_tid(k,cgraph->dist);
    }
    if (gkwinfo[nbrid].nbrinfo[lvtx].ed > 0) {
      ed[ned++] = i;
    } else {
      id[nid++] = i;
    }
  }

  dlthread_barrier(ctrl->comm);
  if (myid == 0) {
    wgt_copy(graph->pwgts,cgraph->pwgts,nparts);

    /* migrate old kwinfo */
    graph->kwinfo = gkwinfo;
    cgraph->kwinfo = NULL;
  }
  dlthread_barrier(ctrl->comm);

  kwinfo = gkwinfo+myid;

  /* Compute the required info for refinement */
  kwinfo->nnbrpool = 0;

  /* expanpd nbrinfo */
  dl_free(kwinfo->nbrinfo);
  vtx_iset_free(kwinfo->bnd);
  nbrinfo = kwinfo->nbrinfo = kwnbrinfo_alloc(mynvtxs);
  
  for (i=0;i<mynvtxs;++i) {
    myrinfo = nbrinfo + i;
    myrinfo->nnbrs = 0;
    myrinfo->id = 0;
    myrinfo->ed = 0;
    myrinfo->nbrstart = NULL_ADJ;
  }

  bnd = kwinfo->bnd = vtx_iset_create(0,mynvtxs);

  htable = pid_init_alloc(NULL_PID,nparts);

  for (pi=0;pi<nid;++pi) {
    i = id[pi];
    istart = xadj[i];
    iend = xadj[i+1];

    myrinfo = nbrinfo+i;

    for (tid=0, j=istart; j<iend; j++) {
      tid += adjwgt[j];
    }
    myrinfo->id = tid;
    if (tid == 0) {
      /* keep islands on the border */
      vtx_iset_add(i,bnd);
    }
    DL_ASSERT_EQUALS(myrinfo->ed,0,"%"PF_WGT_T);
    DL_ASSERT_EQUALS(myrinfo->nnbrs,0,"%"PF_PID_T);
    DL_ASSERT_EQUALS(myrinfo->nbrstart,NULL_ADJ,"%"PF_ADJ_T);
  }
  for (pi=0;pi<ned;++pi) {
    i = ed[pi];

    istart = xadj[i];
    iend = xadj[i+1];

    myrinfo = nbrinfo+i;

    DL_ASSERT_EQUALS(myrinfo->nbrstart,NULL_ADJ,"%"PF_ADJ_T);

    na = dl_min(nparts,xadj[i+1]-xadj[i]);
    mynbrs = kwinfo_get_nbrs(kwinfo,i,na); 

    me = where[i];
    tid = 0;
    ted = 0;
    for (j=istart; j<iend; ++j) {
      k = adjncy[j];
      if (k < mynvtxs) {
        lvtx = k;
        nbrid = myid;
      } else {
        lvtx = gvtx_to_lvtx(k,graph->dist);
        nbrid = gvtx_to_tid(k,graph->dist);
      }
      other = gwhere[nbrid][lvtx];
      if (me == other) {
        tid += adjwgt[j];
      } else {
        ted += adjwgt[j];
        if ((l = htable[other]) == NULL_PID) {
          htable[other] = myrinfo->nnbrs;
          mynbrs[myrinfo->nnbrs].pid = other;
          mynbrs[myrinfo->nnbrs].ed = adjwgt[j];
          ++myrinfo->nnbrs;
        } else {
          mynbrs[l].ed += adjwgt[j];
        }
      }
      DL_ASSERT(myrinfo->nnbrs <= na,"Maxnnbrs = %"PF_PID_T", nnbrs = %" \
          PF_PID_T" for vertex %"PF_TID_T":%"PF_VTX_T"\n",na,myrinfo->nnbrs, \
          myid,i);
    }
    myrinfo->id = tid;
    myrinfo->ed = ted;

    if (ted > 0) {
      if (is_bnd(tid,ted,greedy)) {
        vtx_iset_add(i,bnd);
      }
      for (j=0; j<myrinfo->nnbrs; ++j) {
        htable[mynbrs[j].pid] = NULL_ADJ;
      }
    } else if (tid == 0) {
      vtx_iset_add(i,bnd);
    }
    if (myrinfo->nnbrs == 0) {
      kwinfo->nnbrpool -= na;
      myrinfo->nbrstart = NULL_ADJ;
    }
  }

  dl_free(htable);
  dl_free(ed);
  dl_free(id);

  DL_ASSERT((dlthread_barrier(ctrl->comm),check_kwinfo(kwinfo,graph, \
          (pid_type const **)gwhere)),"Bad info");

  dlthread_barrier(ctrl->comm);
}


/**
 * @brief Project an edge separator.
 *
 * @param ctrl The control structure containing runtime parameters.
 * @param graph The partitioned graph to project the partition (edge
 * separator) from.
 */
static void S_project_esep(
    ctrl_type * const ctrl,
    graph_type * const graph)
{
  vtx_type i, k, lvtx, nbrid;
  adj_type j;
  pid_type me, other;
  vtx_iset_t * bnd;
  esnbrinfo_type * myrinfo;
  esnbrinfo_type * nbrinfo;
  esinfo_type * esinfo;

  tid_type const myid = dlthread_get_id(ctrl->comm);

  graph_type * const cgraph = graph->coarser;
  vtx_type * const * const gcmap = graph->cmap;
  adj_type const * const * const gxadj = (adj_type const **)graph->xadj;
  vtx_type const * const * const gadjncy = (vtx_type const **)graph->adjncy;
  wgt_type const * const * const gadjwgt = (wgt_type const **)graph->adjwgt;

  adj_type const * const xadj = gxadj[myid];
  vtx_type const * const adjncy = gadjncy[myid];
  wgt_type const * const adjwgt = gadjwgt[myid];

  vtx_type const mynvtxs = graph->mynvtxs[myid];

  vtx_type * const cmap = gcmap[myid];

  pid_type ** const gwhere = graph->where;
  pid_type * const where = gwhere[myid];

  /* expand boundary */
  bnd = vtx_iset_create(0,mynvtxs);

  if (myid == 0) {
    wgt_copy(graph->pwgts,cgraph->pwgts,MTMETIS_ESEP_NPARTS);
  }

  /* project where and find boundary */
  for (i=0;i<mynvtxs;++i) {
    k = cmap[i];
    if (k < cgraph->mynvtxs[myid]) {
      lvtx = k;
      nbrid = myid;
    } else {
      lvtx = gvtx_to_lvtx(k,cgraph->dist);
      nbrid = gvtx_to_tid(k,cgraph->dist);
    }
    if (vtx_iset_contains(lvtx,cgraph->esinfo[nbrid].bnd)) {
      /* add it to my local boundary for filtering */
      vtx_iset_add(i,bnd);
    }
  }

  dlthread_barrier(ctrl->comm);
  if (myid == 0) {
    graph->esinfo = cgraph->esinfo;
    cgraph->esinfo = NULL;
  }
  dlthread_barrier(ctrl->comm);

  esinfo = graph->esinfo + myid;

  /* expanpd nbrinfo */
  dl_free(esinfo->nbrinfo);
  vtx_iset_free(esinfo->bnd);
  nbrinfo = esinfo->nbrinfo = esnbrinfo_alloc(mynvtxs);
  esinfo->bnd = bnd;

  for (i=0;i<mynvtxs;++i) {
    me = where[i];

    /* clear myrinfo */
    myrinfo = nbrinfo+i;

    myrinfo->con[0] = myrinfo->con[1] = 0;

    if (vtx_iset_contains(i,bnd)) {
      /* potential boundary vertex */
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
        myrinfo->con[other] += adjwgt[j];
      }
      if (myrinfo->con[me ^ 0x01] == 0) {
        /* internal vertex -- remove from boundary */
        vtx_iset_remove(i,bnd);
      }
    } else {
      /* internal vertex */
      for (j=xadj[i];j<xadj[i+1];++j) {
        myrinfo->con[me] += adjwgt[j];
      }
    }
  }

  DL_ASSERT(check_esinfo(esinfo,graph,(pid_type const **)gwhere),"Bad info");
  DL_ASSERT(check_esbnd(esinfo->bnd,graph),"Bad boundary");
}


/**
 * @brief Project a vertex separator.
 *
 * @param ctrl The control structure containing runtime parameters.
 * @param graph The partitioned graph to project the partition (vertex
 * separator) from.
 */
static void S_project_vsep(
    ctrl_type * const ctrl,
    graph_type * const graph)
{
  vtx_type i;
  pid_type me;
  vsnbrinfo_type * myrinfo;
  vtx_iset_t * bnd;
  vsnbrinfo_type * nbrinfo;
  vsinfo_type * vsinfo;

  tid_type const myid = dlthread_get_id(ctrl->comm);

  graph_type * const cgraph = graph->coarser;
  adj_type const * const * const gxadj = (adj_type const **)graph->xadj;
  vtx_type const * const * const gadjncy = (vtx_type const **)graph->adjncy;
  wgt_type const * const * const gvwgt = (wgt_type const **)graph->vwgt;

  pid_type ** const gwhere = graph->where;
  pid_type * const where = gwhere[myid];

  vtx_type const mynvtxs = graph->mynvtxs[myid];

  adj_type const * const xadj = gxadj[myid];
  vtx_type const * const adjncy = gadjncy[myid];

  graph->minsep = cgraph->minsep;

  if (myid == 0) {
    graph->vsinfo = cgraph->vsinfo;
    cgraph->vsinfo = NULL;
  }

  dlthread_barrier(ctrl->comm);

  vsinfo = graph->vsinfo + myid;

  /* expand boundary */
  vtx_iset_free(vsinfo->bnd);
  dl_free(vsinfo->nbrinfo);
  bnd = vsinfo->bnd = vtx_iset_create(0,mynvtxs);

  /* expanpd nbrinfo */
  nbrinfo = vsinfo->nbrinfo = vsnbrinfo_alloc(mynvtxs);

  if (myid == 0) {
    wgt_copy(graph->pwgts,cgraph->pwgts,MTMETIS_VSEP_NPARTS);
  }
  
  for (i=0;i<mynvtxs;++i) {
    me = where[i];

    /* clear myrinfo */
    myrinfo = nbrinfo+i;

    if (me == MTMETIS_VSEP_SEP) {
      /* have to compute connectivity */
      S_calc_conn(i,myid,mynvtxs,xadj,adjncy,gvwgt,(pid_type const **)gwhere, \
          graph->dist,myrinfo->con);

      vtx_iset_add(i,bnd);
    }
  }

  DL_ASSERT(check_vsinfo(vsinfo,graph,(pid_type const **)gwhere),"Bad info");
  DL_ASSERT(check_vsbnd(vsinfo->bnd,graph),"Bad boundary");
}




/******************************************************************************
* PUBLIC PARALLEL FUNCTIONS ***************************************************
******************************************************************************/


void par_project_graph(
    ctrl_type * const ctrl,
    graph_type * const graph)
{
  vtx_type i, k, lvtx;
  tid_type nbrid;
  pid_type * where;

  tid_type const myid = dlthread_get_id(ctrl->comm);

  vtx_type const * const cmap = graph->cmap[myid];

  vtx_type const mynvtxs = graph->mynvtxs[myid];
  graph_type const * const cgraph = graph->coarser;
  vtx_type const mycnvtxs = cgraph->mynvtxs[myid];
  pid_type const * const * const gcwhere = (pid_type const **)cgraph->where;

  if (myid == 0) {
    dl_start_timer(&(ctrl->timers.projection));
  }

  par_graph_alloc_partmemory(ctrl,graph);

  where = graph->where[myid];

  for (i=0;i<mynvtxs;++i) {
    k = cmap[i];
    if (k < mycnvtxs) {
      lvtx = k;
      nbrid = myid;
    } else {
      lvtx = gvtx_to_lvtx(k,cgraph->dist);
      nbrid = gvtx_to_tid(k,cgraph->dist);
    }
    where[i] = gcwhere[nbrid][lvtx];
  }

  /* project refinement information */
  switch (ctrl->ptype) {
    case MTMETIS_PTYPE_ND:
    case MTMETIS_PTYPE_VSEP:
      graph->minsep = cgraph->minsep;
      S_project_vsep(ctrl,graph);
      break;
    case MTMETIS_PTYPE_RB:
    case MTMETIS_PTYPE_ESEP:
      graph->mincut = cgraph->mincut;
      S_project_esep(ctrl,graph);
      break;
    case MTMETIS_PTYPE_KWAY:
      graph->mincut = cgraph->mincut;
      S_project_kway(ctrl,graph);
      break;
    default:
      dl_error("Unknown partition type '%d'\n",ctrl->ptype);
  }

  par_graph_free(graph->coarser);

  if (myid == 0) {
    graph->coarser = NULL;
    dl_stop_timer(&(ctrl->timers.projection));
  }
}




#endif
