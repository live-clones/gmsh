/**
 * @file vseprefine.c
 * @brief Vertex separator refinement routines
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright 2014, Regents of the University of Minnesota
 * @version 1
 * @date 2014-10-13
 */





#ifndef MTMETIS_REFINE_C
#define MTMETIS_REFINE_C




#include "vseprefine.h"
#include "check.h"




#define ONE_SIDED 1


#include <metis.h>




/******************************************************************************
* TYPES ***********************************************************************
******************************************************************************/


typedef enum lock_state_type {
  UNLOCKED = -1,
  PARTA_LOCKED = MTMETIS_VSEP_PARTA,
  PARTB_LOCKED = MTMETIS_VSEP_PARTB,
  SEP_LOCKED = MTMETIS_VSEP_SEP,
  BOUNDARY_LOCKED = MTMETIS_VSEP_SEP+1 
} lock_state_type;


typedef struct update_type {
  vtx_type v; 
} update_type;




/******************************************************************************
* DOMLIB IMPORTS **************************************************************
******************************************************************************/


#define DLPQ_PREFIX vw
#define DLPQ_KEY_T wgt_type
#define DLPQ_VAL_T vtx_type
#define DLPQ_STATIC
#include "dlpq_headers.h"
#undef DLPQ_STATIC
#undef DLPQ_VAL_T
#undef DLPQ_KEY_T
#undef DLPQ_PREFIX


#define DLBUFFER_PREFIX update
#define DLBUFFER_TYPE_T update_type
#define DLBUFFER_STATIC 1
#include "dlbuffer_headers.h"
#undef DLBUFFER_STATIC
#undef DLBUFFER_TYPE_T
#undef DLBUFFER_PREFIX


#define DLCB_PREFIX update
#define DLCB_TYPE_T update_type
#define DLCB_BUFFER_PREFIX update_buffer
#define DLCB_BUFFER_TYPE_T update_buffer_t
#define DLCB_STATIC 1
#include "dlcb_headers.h"
#undef DLCB_STATIC
#undef DLCB_BUFFER_TYPE_T
#undef DLCB_BUFFER_PREFIX
#undef DLCB_TYPE_T
#undef DLCB_PREFIX




/******************************************************************************
* CONSTANTS *******************************************************************
******************************************************************************/


static size_t const SERIAL_FM_FACTOR = 8192;




/******************************************************************************
* PRIVATE FUNCTIONS ***********************************************************
******************************************************************************/


static inline int S_valid_move(
    vtx_type const v,
    pid_type const side,
    int const * const locked)
{
  int l;

  l = locked[v];
  return (l == (int)(side) || l == UNLOCKED); 
}


static inline void S_lock(
    vtx_type const v,
    int * const locked,
    pid_type const side)
{
  locked[v] = side;
}


static inline void S_sync_pwgts(
    tid_type const myid,
    wgt_type * const gpwgts,
    wgt_type * const lpwgts,
    dlthread_comm_t const comm)
{
  /* turn local pwgts into deltas */
  lpwgts[0] -= gpwgts[0];
  lpwgts[1] -= gpwgts[1];
  lpwgts[MTMETIS_VSEP_SEP] -= gpwgts[MTMETIS_VSEP_SEP];

  /* create global deltas */
  wgt_dlthread_sumareduce(lpwgts,3,comm);

  /* set local pwgts to be global pwgts */
  lpwgts[0] += gpwgts[0];
  lpwgts[1] += gpwgts[1];
  lpwgts[MTMETIS_VSEP_SEP] += gpwgts[MTMETIS_VSEP_SEP];

  dlthread_barrier(comm);

  if (myid == 0) {
    /* re-sync global pwgts */
    gpwgts[0] = lpwgts[0];
    gpwgts[1] = lpwgts[1];
    gpwgts[MTMETIS_VSEP_SEP] = lpwgts[MTMETIS_VSEP_SEP];
  }

  dlthread_barrier(comm);
}


static inline void S_update_neighbor(
    pid_type const side,
    vtx_type const v,
    tid_type const myid,
    vw_pq_t * const q,
    vtx_iset_t * const bnd,
    vsnbrinfo_type * const * const gnbrinfo,
    wgt_type * const pwgts,
    graph_type const * const graph)
{
  vtx_type k, lvtx;
  adj_type j;
  tid_type nbrid;
  wgt_type gain;

  vtx_type const mynvtxs = graph->mynvtxs[myid];
  adj_type const * const xadj = graph->xadj[myid];
  vtx_type const * const adjncy = graph->adjncy[myid];
  wgt_type const * const * const gvwgt = (wgt_type const **)graph->vwgt;
  pid_type * const * const gwhere = graph->where;

  pid_type const other = side ^ 0x01;

  /* if I own the neighboring vertex, perform the update myself */
  if (gwhere[myid][v] == other) {
    /* re-calculate my nrbinfo */
    S_calc_conn(v,myid,mynvtxs,xadj,adjncy,gvwgt,(pid_type const **)gwhere, \
        graph->dist,gnbrinfo[myid][v].con);

    /* update neighbors of the vertices pulled into the separator */
    for (j=xadj[v];j<xadj[v+1];++j) {
      k = adjncy[j];
      if (k < mynvtxs) {
        lvtx = k;
        nbrid = myid;
      } else {
        lvtx = gvtx_to_lvtx(k,graph->dist);
        nbrid = gvtx_to_tid(k,graph->dist);
      }

      if (gwhere[nbrid][lvtx] == MTMETIS_VSEP_SEP) {
        /* update connectivity */
        #pragma omp atomic
        gnbrinfo[nbrid][lvtx].con[other] -= gvwgt[myid][v];
      }

      if (q && nbrid == myid && gwhere[nbrid][lvtx] == MTMETIS_VSEP_SEP) {
        /* this vertex is in the separator, and is now more likely 
         * to move. */
        gain = gvwgt[nbrid][lvtx] - gnbrinfo[nbrid][lvtx].con[other];
        if (vw_pq_contains(lvtx,q)) {
          vw_pq_update(gain,lvtx,q);
        } else {
          vw_pq_push(gain,lvtx,q);
        }
      }
    }

    /* pull this vertex into the separator after updating neighbors */
    gwhere[myid][v] = MTMETIS_VSEP_SEP;

    /* actually move the vertex */
    vtx_iset_add(v,bnd);

    /* add the vertex to the priority queue for further movement */
    if (q) {
      gain = gvwgt[myid][v] - gnbrinfo[myid][v].con[other];
      vw_pq_push(gain,v,q);
    }

    /* update the partition weights */
    pwgts[other] -= gvwgt[myid][v];
    pwgts[MTMETIS_VSEP_SEP] += gvwgt[myid][v];
  }
}


static inline pid_type S_pick_side_local(
    tid_type const myid,
    wgt_type const * const vwgt,
    wgt_type const * const pwgts,
    wgt_type const maxpwgt,
    vsnbrinfo_type const * const nbrinfo,
    vw_pq_t * const * const q)
{
  vtx_type p, v;
  pid_type side;

  /* part next move properties */
  vtx_type vtx[2];
  wgt_type wgt[2], pri[2];

  /* determine stats for each side */
  for (p=0;p<MTMETIS_VSEP_SEP;++p) {
    if (q[p]->size > 0) {
      v = vtx[p] = vw_pq_peek(q[p]);
      pri[p] = vwgt[v] - nbrinfo[v].con[p^0x01];
      DL_ASSERT(pri[p] == vw_pq_top(q[p]),"Vertex %"PF_VTX_T" has wrong " \
          "priority (%"PF_WGT_T" vs %"PF_WGT_T") in queue %"PF_PID_T"\n", \
          v,vw_pq_top(q[p]),pri[p],p);
      wgt[p] = pwgts[p] + vwgt[v];
    } else {
      pri[p] = -maxpwgt; /* below what is possible for a valid priority */
      vtx[p] = NULL_VTX;
      wgt[p] = NULL_WGT;
    }
  }

  /* figure out which side we'll use -- this seems like I could do it 
   * better */
  if (vtx[MTMETIS_VSEP_PARTA] == NULL_VTX && \
      vtx[MTMETIS_VSEP_PARTB] == NULL_VTX) {
    /* exit loop -- both queues are empty */
    return NULL_PID;
  } else if (pri[MTMETIS_VSEP_PARTA] > pri[MTMETIS_VSEP_PARTB]) {
    side = MTMETIS_VSEP_PARTA;
  } else if (pri[MTMETIS_VSEP_PARTA] < pri[MTMETIS_VSEP_PARTB]) {
    side = MTMETIS_VSEP_PARTB;
  } else {
    if (wgt[MTMETIS_VSEP_PARTA] < wgt[MTMETIS_VSEP_PARTB]) {
      side = MTMETIS_VSEP_PARTA;
    } else if (wgt[MTMETIS_VSEP_PARTA] > wgt[MTMETIS_VSEP_PARTB]) {
      side = MTMETIS_VSEP_PARTB;
    } else {
      /* alternate sides */
      side = (q[MTMETIS_VSEP_PARTA]->size + q[MTMETIS_VSEP_PARTB]->size) % 2;
    } 
  }

  /* make sure it will be balanced */
  if (wgt[side] > maxpwgt) {
    side = side ^ 0x01;
    if (vtx[side] == NULL_VTX) {
      /* the other side is empty */
      return NULL_PID;
    }
  }

  DL_ASSERT(q[side]->size > 0,"Choosing side with empty queue");

  return side;
}


static inline pid_type S_pick_side(
    graph_type const * const graph,
    wgt_type const * const pwgts,
    wgt_type const maxpwgt,
    vsnbrinfo_type const * const * const gnbrinfo,
    vw_pq_t * const * const q)
{
  vtx_type p, v, g;
  tid_type myid;
  pid_type side;

  /* part next move properties */
  vtx_type vtx[2];
  wgt_type wgt[2], pri[2];

  wgt_type const * const * const gvwgt = (wgt_type const **)graph->vwgt;

  /* determine stats for each side */
  for (p=0;p<MTMETIS_VSEP_SEP;++p) {
    if (q[p]->size > 0) {
      g = vtx[p] = vw_pq_peek(q[p]);
      v = gvtx_to_lvtx(g,graph->dist);
      myid = gvtx_to_tid(g,graph->dist);
      pri[p] = gvwgt[myid][v] - gnbrinfo[myid][v].con[p^0x01];
      DL_ASSERT(pri[p] == vw_pq_top(q[p]),"Vertex %"PF_VTX_T" has wrong " \
          "priority (%"PF_WGT_T" vs %"PF_WGT_T") in queue %"PF_PID_T"\n", \
          v,vw_pq_top(q[p]),pri[p],p);
      wgt[p] = pwgts[p] + gvwgt[myid][v];
    } else {
      pri[p] = -maxpwgt; /* below what is possible for a valid priority */
      vtx[p] = NULL_VTX;
      wgt[p] = NULL_WGT;
    }
  }

  /* figure out which side we'll use -- this seems like I could do it 
   * better */
  if (vtx[MTMETIS_VSEP_PARTA] == NULL_VTX && \
      vtx[MTMETIS_VSEP_PARTB] == NULL_VTX) {
    /* exit loop -- both queues are empty */
    return NULL_PID;
  } else if (pri[MTMETIS_VSEP_PARTA] > pri[MTMETIS_VSEP_PARTB]) {
    side = MTMETIS_VSEP_PARTA;
  } else if (pri[MTMETIS_VSEP_PARTA] < pri[MTMETIS_VSEP_PARTB]) {
    side = MTMETIS_VSEP_PARTB;
  } else {
    if (wgt[MTMETIS_VSEP_PARTA] < wgt[MTMETIS_VSEP_PARTB]) {
      side = MTMETIS_VSEP_PARTA;
    } else if (wgt[MTMETIS_VSEP_PARTA] > wgt[MTMETIS_VSEP_PARTB]) {
      side = MTMETIS_VSEP_PARTB;
    } else {
      /* alternate sides */
      side = (q[MTMETIS_VSEP_PARTA]->size + q[MTMETIS_VSEP_PARTB]->size) % 2;
    } 
  }

  /* make sure it will be balanced */
  if (wgt[side] > maxpwgt) {
    side = side ^ 0x01;
    if (vtx[side] == NULL_VTX) {
      /* the other side is empty */
      return NULL_PID;
    }
  }

  DL_ASSERT(q[side]->size > 0,"Choosing side with empty queue");

  return side;
}


static void S_fix_iface(
    ctrl_type * const ctrl,
    graph_type const * const graph,
    vsinfo_type * const vsinfo,
    vtx_type const * const iface,
    vtx_type const niface)
{
  vtx_type i, k, v;
  adj_type j;

  tid_type const myid = dlthread_get_id(ctrl->comm);

  vtx_type const mynvtxs = graph->mynvtxs[myid];
  adj_type const * const xadj = graph->xadj[myid];
  vtx_type const * const adjncy = graph->adjncy[myid];
  wgt_type const * const * const gvwgt = (wgt_type const **)graph->vwgt;

  vsnbrinfo_type * const nbrinfo = vsinfo->nbrinfo;
  vtx_iset_t * const bnd = vsinfo->bnd;

  if (iface == NULL || niface > bnd->size*7) {
    for (i=0;i<bnd->size;++i) {
      v = vtx_iset_get(i,bnd);
      for (j=xadj[v];j<xadj[v+1];++j) {
        k = adjncy[j];
        if (k >= mynvtxs) {
          S_calc_conn(v,myid,mynvtxs,xadj,adjncy,gvwgt, \
              (pid_type const **)graph->where,graph->dist,nbrinfo[v].con);
          break;
        }
      }
    }
  } else {
    for (i=0;i<niface;++i) {
      v = iface[i];
      if (graph->where[myid][v] == MTMETIS_VSEP_SEP) {
        S_calc_conn(v,myid,mynvtxs,xadj,adjncy,gvwgt, \
            (pid_type const **)graph->where,graph->dist,nbrinfo[v].con);
      }
    }
  }
}


static void S_metis_refine(
    ctrl_type const * const ctrl,
    graph_type * const graph,
    int const * const locked)
{
  vtx_type i, k;
  adj_type j;
  idx_t lnedges;
  wgt_type lpwgts[3];
  idx_t * xadj;
  idx_t * adjncy;

  tid_type const myid = dlthread_get_id(ctrl->comm);

  vtx_type const mynvtxs = graph->mynvtxs[myid];

  xadj = malloc(sizeof(idx_t)*(mynvtxs+1));
  adjncy = malloc(sizeof(idx_t)*(graph->xadj[myid][mynvtxs]));

  lnedges = 0;
  xadj[0] = lnedges;
  for (i=0;i<mynvtxs;++i) {
    for (j=graph->xadj[myid][i];j<graph->xadj[myid][i+1];++j) {
      k = graph->adjncy[myid][j];
      if (k < mynvtxs) {
        adjncy[lnedges] = k;
        ++lnedges;
      }
    }
    xadj[i+1] = lnedges;
  }

  __METIS_NodeRefine(graph->mynvtxs[myid],xadj,(idx_t*)graph->vwgt[myid], \
      adjncy,(idx_t*)graph->where[myid],(idx_t*)locked,1.03);


  wgt_set(lpwgts,0,3);
  for (i=0;i<mynvtxs;++i) {
    lpwgts[graph->where[myid][i]] += graph->vwgt[myid][i];
  }

  wgt_dlthread_sumareduce(lpwgts,3,ctrl->comm);

  if (myid == 0) {
    wgt_copy(graph->pwgts,lpwgts,3);
    graph->minsep = graph->pwgts[2];
  }
  dlthread_barrier(ctrl->comm);

  dl_free(adjncy);
  dl_free(xadj);
}



/******************************************************************************
* PARALLEL REFINEMENT PASSES **************************************************
******************************************************************************/


static vtx_type S_flow_GREEDY(
    ctrl_type * const ctrl, 
    graph_type * const graph,
    vsinfo_type * const vsinfo,
    vsnbrinfo_type * const * const gnbrinfo,
    update_combuffer_t * const combuffer,
    vw_pq_t * const q,
    pid_type const side,
    wgt_type * const lpwgts,
    wgt_type const maxpwgt)
{
  vtx_type i, k, v, nmoves, lvtx;
  adj_type j;
  wgt_type newwgt, gain;
  pid_type other;
  tid_type nbrid, o, t;
  update_type up;
  vsnbrinfo_type * myrinfo;
  update_buffer_t * updates;

  tid_type const myid = dlthread_get_id(ctrl->comm);
  tid_type const nthreads = dlthread_get_nthreads(ctrl->comm);

  vtx_type const mynvtxs = graph->mynvtxs[myid];
  adj_type const * const xadj = graph->xadj[myid];
  vtx_type const * const adjncy = graph->adjncy[myid];
  wgt_type const * const * const gvwgt = (wgt_type const **)graph->vwgt;

  pid_type * const * const gwhere = graph->where;

  vsnbrinfo_type * const nbrinfo = vsinfo->nbrinfo;
  vtx_iset_t * const bnd = vsinfo->bnd;

  /* the side I'm not moving to */
  other = side ^ 0x01;

  nmoves = 0;

  /* add my boundary vertices to the queue */ 
  vw_pq_clear(q);
  for (i=0;i<bnd->size;++i) {
    v = bnd->ind[i]; 
    DL_ASSERT_EQUALS(MTMETIS_VSEP_SEP,gwhere[myid][v],"%"PF_PID_T);
    myrinfo = nbrinfo + v;
    gain = gvwgt[myid][v] - myrinfo->con[other];
    vw_pq_push(gain,v,q);
  }

  /* make possible moves */
  while (q->size > 0) {
    v = vw_pq_pop(q);
    DL_ASSERT_EQUALS(MTMETIS_VSEP_SEP,gwhere[myid][v],"%"PF_PID_T);
    DL_ASSERT_EQUALS(vtx_iset_contains(v,bnd),1,"%d");

    myrinfo = nbrinfo + v;

    gain = gvwgt[myid][v] - myrinfo->con[other];
    if (gain < 0 || (gain == 0 && lpwgts[side] >= lpwgts[other])) {
      /* only move vertices with positive gain */
      break;
    }

    #if 0
    if (lpwgts[side] > lpwgts[other] && \
        gain < gvwgt[myid][v] - myrinfo->con[side]) {
      /* if its better to move this vertex to the other side, 
       * don't move it here */
      continue;
    }
    #endif

    newwgt = lpwgts[side] + gvwgt[myid][v];
    if (newwgt > maxpwgt) {
      /* this vertex will put us over the limit */
      continue;
    }

    /* Once we have selected a vertex to move, we need to update several
     * things:
     * -the partition and separator weights
     * -pull the neighboring vertices in 'other' into the separator
     * -update the priorities of the affected vertives
     */

    /* adjust partition weights */
    lpwgts[side] += gvwgt[myid][v];
    lpwgts[MTMETIS_VSEP_SEP] -= gvwgt[myid][v];

    ++nmoves;

    /* at this point, we have decided to make the move */
    gwhere[myid][v] = side;
    
    /* remove the vertex from the boundary */
    vtx_iset_remove(v,bnd);

    /* process edges */
    for (j=xadj[v];j<xadj[v+1];++j) {
      k = adjncy[j];
      if (k < mynvtxs) {
        lvtx = k;
        nbrid = myid;
      } else {
        lvtx = gvtx_to_lvtx(k,graph->dist);
        nbrid = gvtx_to_tid(k,graph->dist);
      }

      /* update priorities of neighboring */
      if (gwhere[nbrid][lvtx] == MTMETIS_VSEP_SEP) { 
        #pragma omp atomic
        gnbrinfo[nbrid][lvtx].con[side] += gvwgt[myid][v];
      }

      if (nbrid == myid) {
        S_update_neighbor(side,lvtx,myid,q,bnd,gnbrinfo,lpwgts,graph);
      } else {
        /* let the neighboring thread know about the move */
        up.v = lvtx;
        update_combuffer_add(nbrid,up,combuffer);
      }
    }
  }

  /* implicit barrier */
  update_combuffer_send(combuffer);

  /* recieve updates from other threads */
  for (o=1;o<nthreads;++o) {
    t = (myid + o) % nthreads;
    updates = update_combuffer_get(t,combuffer);
    for (i=0;i<(vtx_type)updates->size;++i) {
      up = updates->elements[i];
      v = up.v;
      S_update_neighbor(side,v,myid,NULL,bnd,gnbrinfo,lpwgts,graph);
    }
  }

  update_combuffer_clear(combuffer);

  return nmoves;
}


static vtx_type S_flow_GREEDYI(
    ctrl_type * const ctrl, 
    graph_type * const graph,
    vsinfo_type * const vsinfo,
    vsnbrinfo_type * const * const gnbrinfo,
    update_combuffer_t * const combuffer,
    vw_pq_t * const q,
    pid_type const side,
    wgt_type * const lpwgts,
    wgt_type const maxpwgt,
    vtx_type const * const iface,
    vtx_type const niface)
{
  vtx_type i, k, v, nmoves, lvtx;
  adj_type j;
  wgt_type newwgt, gain;
  pid_type other;
  tid_type nbrid, o, t;
  update_type up;
  vsnbrinfo_type * myrinfo;
  update_buffer_t * updates;

  tid_type const myid = dlthread_get_id(ctrl->comm);
  tid_type const nthreads = dlthread_get_nthreads(ctrl->comm);

  vtx_type const mynvtxs = graph->mynvtxs[myid];
  adj_type const * const xadj = graph->xadj[myid];
  vtx_type const * const adjncy = graph->adjncy[myid];
  wgt_type const * const * const gvwgt = (wgt_type const **)graph->vwgt;

  pid_type * const * const gwhere = graph->where;

  vsnbrinfo_type * const nbrinfo = vsinfo->nbrinfo;
  vtx_iset_t * const bnd = vsinfo->bnd;

  /* the side I'm not moving to */
  other = side ^ 0x01;

  nmoves = 0;

  /* add my boundary vertices to the queue */ 
  vw_pq_clear(q);
  for (i=0;i<niface;++i) {
    v = iface[i];
    if (gwhere[myid][v] == MTMETIS_VSEP_SEP) {
      myrinfo = nbrinfo + v;
      gain = gvwgt[myid][v] - myrinfo->con[other];
      vw_pq_push(gain,v,q);
    }
  }

  /* make possible moves */
  while (q->size > 0) {
    v = vw_pq_pop(q);
    DL_ASSERT_EQUALS(MTMETIS_VSEP_SEP,gwhere[myid][v],"%"PF_PID_T);
    DL_ASSERT_EQUALS(vtx_iset_contains(v,bnd),1,"%d");

    myrinfo = nbrinfo + v;

    gain = gvwgt[myid][v] - myrinfo->con[other];
    if (gain < 0 || (gain == 0 && lpwgts[side] >= lpwgts[other])) {
      /* only move vertices with positive gain */
      break;
    }

    #if 0
    if (lpwgts[side] > lpwgts[other] && \
        gain < gvwgt[myid][v] - myrinfo->con[side]) {
      /* if its better to move this vertex to the other side, 
       * don't move it here */
      continue;
    }
    #endif

    newwgt = lpwgts[side] + gvwgt[myid][v];
    if (newwgt > maxpwgt) {
      /* this vertex will put us over the limit */
      continue;
    }

    /* Once we have selected a vertex to move, we need to update several
     * things:
     * -the partition and separator weights
     * -pull the neighboring vertices in 'other' into the separator
     * -update the priorities of the affected vertives
     */

    /* adjust partition weights */
    lpwgts[side] += gvwgt[myid][v];
    lpwgts[MTMETIS_VSEP_SEP] -= gvwgt[myid][v];

    ++nmoves;

    /* at this point, we have decided to make the move */
    gwhere[myid][v] = side;
    
    /* remove the vertex from the boundary */
    vtx_iset_remove(v,bnd);

    /* process edges */
    for (j=xadj[v];j<xadj[v+1];++j) {
      k = adjncy[j];
      if (k < mynvtxs) {
        lvtx = k;
        nbrid = myid;
      } else {
        lvtx = gvtx_to_lvtx(k,graph->dist);
        nbrid = gvtx_to_tid(k,graph->dist);
      }

      /* update priorities of neighboring */
      if (gwhere[nbrid][lvtx] == MTMETIS_VSEP_SEP) { 
        #pragma omp atomic
        gnbrinfo[nbrid][lvtx].con[side] += gvwgt[myid][v];
      }

      if (nbrid == myid) {
        S_update_neighbor(side,lvtx,myid,NULL,bnd,gnbrinfo,lpwgts,graph);
      } else {
        /* let the neighboring thread know about the move */
        up.v = lvtx;
        update_combuffer_add(nbrid,up,combuffer);
      }
    }
  }

  /* implicit barrier */
  update_combuffer_send(combuffer);

  /* recieve updates from other threads */
  for (o=1;o<nthreads;++o) {
    t = (myid + o) % nthreads;
    updates = update_combuffer_get(t,combuffer);
    for (i=0;i<(vtx_type)updates->size;++i) {
      up = updates->elements[i];
      v = up.v;
      S_update_neighbor(side,v,myid,NULL,bnd,gnbrinfo,lpwgts,graph);
    }
  }

  update_combuffer_clear(combuffer);

  return nmoves;
}


static vtx_type S_flow_SFM(
    ctrl_type * const ctrl, 
    graph_type * const graph,
    vsinfo_type * const vsinfo,
    vtx_type * const moves,
    vtx_type * const pullmk,
    vtx_type * const pulled,
    vw_pq_t * const q,
    int * const locked,
    pid_type const side,
    wgt_type * const lpwgts,
    wgt_type const maxpwgt)
{
  vtx_type i, k, v, m, nmoves, minmove;
  adj_type j, npulled, l;
  wgt_type minsep, newbal, minbal, gain, cursep;
  pid_type p, other;
  vsnbrinfo_type * myrinfo;

  tid_type const myid = dlthread_get_id(ctrl->comm);
  tid_type const nthreads = dlthread_get_nthreads(ctrl->comm);

  vtx_type const mynvtxs = graph->mynvtxs[myid];
  adj_type const * const xadj = graph->xadj[myid];
  vtx_type const * const adjncy = graph->adjncy[myid];
  wgt_type const * const * const gvwgt = (wgt_type const **)graph->vwgt;
  wgt_type const * const vwgt = graph->vwgt[myid];

  pid_type * const * const gwhere = graph->where; 
  pid_type * const where = gwhere[myid]; 
  vsnbrinfo_type * const nbrinfo = vsinfo->nbrinfo;
  vtx_iset_t * const bnd = vsinfo->bnd;

  vtx_type const limit = ctrl->hillsize/sqrt(nthreads);

  other = side ^ 0x01;

  nmoves = 0;
  minmove = 0;
  npulled = 0;
  pullmk[1] = 0;
  minbal = wgt_abs_diff(lpwgts[0],lpwgts[1]);

  vw_pq_clear(q);
  for (i=0;i<bnd->size;++i) {
    v = bnd->ind[i];
    if (S_valid_move(v,side,locked)) {
      DL_ASSERT_EQUALS(MTMETIS_VSEP_SEP,where[v],"%"PF_PID_T);
      myrinfo = nbrinfo + v;
      gain = vwgt[v] - myrinfo->con[other];
      vw_pq_push(gain,v,q);
    }
  }

  cursep = minsep = graph->minsep;

  /* make possible moves */
  while (nmoves < mynvtxs && q->size > 0) {
    v = vw_pq_pop(q);

    DL_ASSERT(S_valid_move(v,side,locked),"Pulled a vertex " \
        "from %"PF_PID_T" but is locked to %"PF_PID_T,side,locked[v]);
    DL_ASSERT_EQUALS(MTMETIS_VSEP_SEP,where[v],"%"PF_PID_T);
    DL_ASSERT_EQUALS(vtx_iset_contains(v,bnd),1,"%d");

    if (lpwgts[side] >= maxpwgt) {
      break;
    }

    if (lpwgts[side] + vwgt[v] > maxpwgt) {
      continue;
    }

    /* make sure we have space to record the vertices added to the
     * separator */
    if (npulled + xadj[v+1] - xadj[v] >= 2*mynvtxs-1) {
      /* roll back to our best state */
      break;
    }

    /* update our minimum objective value or check to make sure we
     * haven't passed the search limit */
    cursep = cursep - (vwgt[v]-nbrinfo[v].con[other]);
    newbal = wgt_abs_diff(lpwgts[side]+vwgt[v], \
        lpwgts[other]-nbrinfo[v].con[other]);

    if (cursep < minsep || \
        (cursep == minsep && newbal < minbal)) {
      minsep = cursep;
      minmove = nmoves+1;
      /* we only need to abs this here, as if its negative, it means the
       * move increases the balance */
      minbal = newbal;
    } else {
      if (nmoves-minmove+1 > limit) {
        /* revert back to best cut */
        break; 
      }
    }


    /* Once we have selected a vertex to move, we need to update several
     * things:
     * -the partition and separator weights
     * -pull the neighboring vertices in 'other' into the separator
     * -update the priorities of the affected vertives
     */

    /* at this point, we have decided to make the move */
    myrinfo = nbrinfo + v;
    where[v] = side;
    moves[++nmoves] = v; /* count one up */
    
    /* remove the vertex from the boundary -- and opposing pq */
    vtx_iset_remove(v,bnd);

    /* adjust partition weights */
    lpwgts[side] += vwgt[v];
    lpwgts[MTMETIS_VSEP_SEP] -= vwgt[v];

    /* process edges */
    for (j=xadj[v];j<xadj[v+1];++j) {
      k = adjncy[j];
      if (k < mynvtxs) {
        if (where[k] == MTMETIS_VSEP_SEP) {
          /* update priorities of neighboring vertiecs */
          nbrinfo[k].con[side] += vwgt[v];

        } else if (where[k] == other) {
          /* pull this vertex into the separator */
          DL_ASSERT_EQUALS(vtx_iset_contains(k,bnd),0,"%d");

          /* record vertex being pulled into the separator */
          pulled[npulled++] = k;

          /* actually move the vertex */
          vtx_iset_add(k,bnd);
          where[k] = MTMETIS_VSEP_SEP;

          /* calculate the connectivity */
          S_calc_conn(k,myid,mynvtxs,xadj,adjncy,gvwgt, \
              (pid_type const **)gwhere,graph->dist,nbrinfo[k].con);

          /* update the partition weights */
          lpwgts[other] -= vwgt[k];
          lpwgts[MTMETIS_VSEP_SEP] += vwgt[k];

          /* add the vertex to the priority queue for further movement */
          if (S_valid_move(k,side,locked)) {
            gain = vwgt[k] - nbrinfo[k].con[other];
            vw_pq_push(gain,k,q);
          }

          /* update neighbors of the vertices pulled into the separator */
          for (l=xadj[k];l<xadj[k+1];++l) {
            m = adjncy[l];
            if (m < mynvtxs) {
              if (where[m] == MTMETIS_VSEP_SEP) {
                /* this vertex is in the separator, and is now more likely 
                 * to move. */

                /* update connectivity */
                nbrinfo[m].con[other] -= vwgt[k];

                if (S_valid_move(m,side,locked)) {
                  /* update the value for moving this vertex in the same
                   * diretion */
                  if (vw_pq_contains(m,q)) {
                    gain = vwgt[m] - nbrinfo[m].con[other];
                    vw_pq_update(gain,m,q);
                  }
                }
              }
            }
          }
        }
      }
    }
    /* mark the number of vertices I pulled into the boundary */
    pullmk[nmoves+1] = npulled;
  }
  par_dprintf("SFM1S: Pass %zu finished, sep = %"PF_WGT_T", rolling back %" \
      PF_VTX_T"/%"PF_VTX_T" moves\n",(size_t)0,lpwgts[MTMETIS_VSEP_SEP], \
      nmoves-minmove,nmoves);


  /* rollback until we are back at the maximum state -- moves must be
   * undone in reverse of the order in which they were made */
  while (nmoves > minmove) {
    v = moves[nmoves];

    DL_ASSERT(side != MTMETIS_VSEP_SEP,"ATtempting to unmove vertex %" \
        PF_VTX_T" in separator\n",v);

    /* unmove this vertex */
    lpwgts[MTMETIS_VSEP_SEP] += vwgt[v];
    lpwgts[side] -= vwgt[v];

    where[v] = MTMETIS_VSEP_SEP;
    vtx_iset_add(v,bnd);

    /* adjust priorities of neighboring vertices and re-calculate
     * connectivity */
    wgt_set(nbrinfo[v].con,0,2);
    for (j=xadj[v];j<xadj[v+1];++j) {
      k = adjncy[j];
      if (k < mynvtxs) {
        p = where[k];

        if (p == MTMETIS_VSEP_SEP) {
          nbrinfo[k].con[side] -= vwgt[v]; 
        }
      }
    }
    S_calc_conn(v,myid,mynvtxs,xadj,adjncy,gvwgt,(pid_type const **)gwhere, \
        graph->dist,nbrinfo[v].con);

    /* push nodes back out of the separator */ 
    for (i=pullmk[nmoves];i<pullmk[nmoves+1];++i) {
      k = pulled[i];

      DL_ASSERT_EQUALS(where[k],MTMETIS_VSEP_SEP,"%"PF_PID_T);

      /* move the vertex */
      where[k] = other;

      /* adjust partition weights */
      lpwgts[other] += vwgt[k];
      lpwgts[MTMETIS_VSEP_SEP] -= vwgt[k];

      /* remove the vertex from the boundary */
      vtx_iset_remove(k,bnd);

      /* update neighbor-neighbor connectivity */
      for (l=xadj[k];l<xadj[k+1];++l) {
        m = adjncy[l];

        if (m < mynvtxs) {
          if (where[m] == MTMETIS_VSEP_SEP) {
            nbrinfo[m].con[other] += vwgt[k];
          }
        }
      }

      S_calc_conn(k,myid,mynvtxs,xadj,adjncy,gvwgt,(pid_type const **)gwhere, \
          graph->dist,nbrinfo[k].con);
    }

    /* go to the next move */
    --nmoves;
  }

  return nmoves;
}



static void S_pass_BAL(
    ctrl_type * const ctrl, 
    graph_type * const graph,
    vsinfo_type * const vsinfo,
    wgt_type const maxpwgt)
{
  unsigned int seed;
  vtx_type i, k, v, nmoves, lvtx;
  adj_type j;
  wgt_type gain;
  tid_type o, nbrid, t;
  pid_type side, other;
  update_type up;
  wgt_type mvwgt;
  vtx_type * perm;
  vsnbrinfo_type * myrinfo;
  update_buffer_t * updates;
  wgt_type lpwgts[3];
  update_combuffer_t * combuffer;
  vsnbrinfo_type ** gnbrinfo;
  vw_pq_t * q;

  tid_type const myid = dlthread_get_id(ctrl->comm);
  tid_type const nthreads = dlthread_get_nthreads(ctrl->comm);

  vtx_type const nvtxs = graph->nvtxs;
  vtx_type const mynvtxs = graph->mynvtxs[myid];
  adj_type const * const xadj = graph->xadj[myid];
  vtx_type const * const adjncy = graph->adjncy[myid];
  wgt_type const * const * const gvwgt = (wgt_type const **)graph->vwgt;

  wgt_type * const pwgts = graph->pwgts;
  pid_type * const * const gwhere = graph->where;
  vsnbrinfo_type * const nbrinfo = vsinfo->nbrinfo;
  vtx_iset_t * const bnd = vsinfo->bnd;

  gnbrinfo = dlthread_get_shmem(sizeof(vsnbrinfo_type*)*nthreads,ctrl->comm);
  gnbrinfo[myid] = vsinfo->nbrinfo;

  combuffer = update_combuffer_create(ctrl->comm);

  q = vw_pq_create(0,mynvtxs);

  seed = ctrl->seed + myid;

  /* The overall algorithm for a balance bass work by prioritizing vertices and
   * moving them from the heavy side to the light until balanced is achieved.
   */

  perm = vtx_alloc(mynvtxs);

  wgt_copy(lpwgts,pwgts,3);

  /* initial tracking variables */
  if (lpwgts[0] > lpwgts[1]) {
    side = 1;
  } else {
    side = 0;
  }

  other = side ^ 0x01;

  /* how much weight I should move */
  mvwgt = (pwgts[other] - maxpwgt) / nthreads;

  vw_pq_clear(q);
  vtx_copy(perm,bnd->ind,bnd->size);
  vtx_pseudo_shuffle_r(perm,bnd->size/8,bnd->size,&seed);
  for (i=0;i<bnd->size;++i) {
    v = perm[i];
    DL_ASSERT_EQUALS(MTMETIS_VSEP_SEP,gwhere[myid][v],"%"PF_PID_T);
    myrinfo = nbrinfo + v;
    gain = gvwgt[myid][v] - myrinfo->con[other];
    vw_pq_push(gain,v,q);
  }

  nmoves = 0;

  /* make sure we got a good copy of the pwgts */
  dlthread_barrier(ctrl->comm);

  /* make possible moves */
  while (nmoves < nvtxs && q->size > 0) {
    v = vw_pq_pop(q);

    DL_ASSERT_EQUALS(MTMETIS_VSEP_SEP,gwhere[myid][v],"%"PF_PID_T);
    DL_ASSERT_EQUALS(vtx_iset_contains(v,bnd),1,"%d");

    /* we made the required moves */
    if (mvwgt < 0) {
      break;
    }

    gain = gvwgt[myid][v] - nbrinfo[v].con[other]; 

    if (gain < 0 && mvwgt > nbrinfo[v].con[other]/2) {
      continue;
    }

    if (gvwgt[myid][v] + lpwgts[side] >= maxpwgt) {
      /* moving this vertex will be bad, see other options */
      break;
    }

    /* Once we have selected a vertex to move, we need to update several
     * things:
     * -the partition and separator weights
     * -pull the neighboring vertices in 'other' into the separator
     * -update the priorities of the affected vertives
     */
    ++nmoves;

    /* we're increasing side by this amount */
    //mvwgt -= gvwgt[myid][v];

    /* we update location of a vertex leaving the separator, before updating
     * its neighbors */
    gwhere[myid][v] = side;

    /* at this point, we have decided to make the move */
    myrinfo = nbrinfo + v;
    
    /* remove the vertex from the boundary -- and opposing pq */
    vtx_iset_remove(v,bnd);

    /* adjust partition weights */
    lpwgts[side] += gvwgt[myid][v];
    lpwgts[MTMETIS_VSEP_SEP] -= gvwgt[myid][v];

    /* process edges */
    for (j=xadj[v];j<xadj[v+1];++j) {
      k = adjncy[j];
      if (k < mynvtxs) {
        lvtx = k;
        nbrid = myid;
      } else {
        lvtx = gvtx_to_lvtx(k,graph->dist);
        nbrid = gvtx_to_tid(k,graph->dist);
      }

      if (gwhere[nbrid][lvtx] == MTMETIS_VSEP_SEP) {
        /* update priorities of neighboring */
        gnbrinfo[nbrid][lvtx].con[side] += gvwgt[myid][v];
      }

      if (nbrid == myid) {
        S_update_neighbor(side,lvtx,myid,q,bnd,gnbrinfo,lpwgts,graph);
      } else {
        /* let the neighboring thread know about the move */
        up.v = lvtx;
        update_combuffer_add(nbrid,up,combuffer);
      }
      /* we're decreasing other by this amount */
      mvwgt -= gvwgt[nbrid][lvtx];
    }
  }

  /* implicit barrier */
  update_combuffer_send(combuffer);

  /* recieve updates from other threads */
  for (o=1;o<nthreads;++o) {
    t = (myid + o) % nthreads;
    updates = update_combuffer_get(t,combuffer);
    for (i=0;i<(vtx_type)updates->size;++i) {
      up = updates->elements[i];
      v = up.v;
      S_update_neighbor(side,v,myid,NULL,bnd,gnbrinfo,lpwgts,graph);
    }
  }

  update_combuffer_clear(combuffer);

  lpwgts[0] -= pwgts[0];
  lpwgts[1] -= pwgts[1];
  lpwgts[MTMETIS_VSEP_SEP] -= pwgts[MTMETIS_VSEP_SEP];
  
  wgt_dlthread_sumareduce(lpwgts,3,ctrl->comm);
  if (myid == 0) {
    pwgts[0] += lpwgts[0];
    pwgts[1] += lpwgts[1];
    graph->minsep = pwgts[MTMETIS_VSEP_SEP] += lpwgts[MTMETIS_VSEP_SEP];

    ctrl->seed = seed;
  }

  dlthread_free_shmem(gnbrinfo,ctrl->comm);
  update_combuffer_free(combuffer);
  vw_pq_free(q);
  dl_free(perm);

  S_fix_iface(ctrl,graph,vsinfo,NULL,0);

  DL_ASSERT(check_vsinfo(vsinfo,graph,(pid_type const **)gwhere), \
      "Bad vsinfo after balancing");
  DL_ASSERT(check_vsbnd(bnd,graph),"Bad boundary after balancing");
}


static vtx_type S_pass_SFM1S(
    ctrl_type * const ctrl, 
    graph_type * const graph,
    vsinfo_type * const vsinfo,
    vtx_type * const moves,
    vtx_type * const pullmk,
    vtx_type * const pulled,
    vw_pq_t * const q, 
    int * const locked,
    vtx_type const * const iface,
    vtx_type const niface,
    wgt_type const maxpwgt)
{
  size_t d, nnomoves;
  vtx_type nmoves, totalmoves;
  pid_type side, o;
  wgt_type lpwgts[3];

  tid_type const myid = dlthread_get_id(ctrl->comm);

  wgt_type * const pwgts = graph->pwgts;

  totalmoves = 0;

  /* initial tracking variables */
  if (pwgts[0] > pwgts[1]) {
    o = 1;
  } else if (pwgts[0] < pwgts[1]) {
    o = 0;
  } else {
    o = graph->level % 2;
  }

  wgt_copy(lpwgts,pwgts,3);

  nnomoves = 0;
  for (d=0;d<ctrl->nrefpass*2;++d) {
    side = (d + o) % 2;

    nmoves = S_flow_SFM(ctrl,graph,vsinfo,moves,pullmk,pulled,q,locked,side, \
        lpwgts,maxpwgt);

    if (nmoves == 0) {
      if (++nnomoves == 2) {
        break;
      }
    } else {
      totalmoves += nmoves;
      nnomoves = 0;
    }
  }

  S_sync_pwgts(myid,pwgts,lpwgts,ctrl->comm);

  if (myid == 0) {
    ctrl->seed = ctrl->seed+1;
  }

  S_fix_iface(ctrl,graph,vsinfo,iface,niface);

  /* implicit barrier */
  totalmoves = vtx_dlthread_sumreduce(totalmoves,ctrl->comm);

  DL_ASSERT(check_vsinfo(vsinfo,graph,(pid_type const **)graph->where), \
      "Bad vsinfo after refinement");
  DL_ASSERT(check_vsbnd(vsinfo->bnd,graph),"Bad boundary after " \
      "refinement");

  #ifdef USE_ASSERTS
  dlthread_barrier(ctrl->comm);
  #endif

  return totalmoves;
}


static vtx_type S_pass_GREEDY(
    ctrl_type * const ctrl, 
    graph_type * const graph,
    vsinfo_type * const vsinfo,
    vsnbrinfo_type * const * const gnbrinfo,
    update_combuffer_t * const combuffer,
    vw_pq_t * const q,
    vtx_type const * const iface,
    vtx_type const niface,
    wgt_type const maxpwgt,
    int const bnd)
{
  vtx_type nnone, dnmoves, nmoves;
  pid_type o, side, d;
  wgt_type lpwgts[3];

  tid_type const myid = dlthread_get_id(ctrl->comm);

  wgt_type * const pwgts = graph->pwgts;

  if (pwgts[0] > pwgts[1]) {
    o = 1;
  } else if (pwgts[0] < pwgts[1]) {
    o = 0;
  } else {
    o = graph->level % 2;
  }

  /* make local copies of the partition weights */
  wgt_copy(lpwgts,pwgts,MTMETIS_VSEP_NPARTS);

  nmoves = 0;
  nnone = 0;
  for (d=0;d<ctrl->nrefpass;++d) {

    side = (d + o) % 2;

    if (bnd) {
      /* interface only refinement */
      dnmoves = S_flow_GREEDYI(ctrl,graph,vsinfo,gnbrinfo,combuffer,q,side, \
          lpwgts,maxpwgt,iface,niface);
    } else {
      /* regular greedy refinment */
      dnmoves = S_flow_GREEDY(ctrl,graph,vsinfo,gnbrinfo,combuffer,q,side, \
          lpwgts,maxpwgt);
    }

    /* implicit barrier */
    dnmoves = vtx_dlthread_sumreduce(dnmoves,ctrl->comm);

    if (myid == 0) {
      ctrl->seed = ctrl->seed+1;
    }

    /* make sure have good information at the end of each half-pass */
    S_fix_iface(ctrl,graph,vsinfo,iface,niface);

    if (dnmoves == 0) {
      if (++nnone == 2) {
        break;
      }
    } else {
      nnone = 0;
      nmoves += dnmoves;
    }
  }

  /* implicit barrier */
  S_sync_pwgts(myid,pwgts,lpwgts,ctrl->comm);

  return nmoves;
}




/******************************************************************************
* PARALLEL REFINEMENT FUNCTIONS ***********************************************
******************************************************************************/


static vtx_type S_vseprefine_FM(
    ctrl_type * const ctrl, 
    graph_type * const graph,
    size_t const niter, 
    vsinfo_type * const vsinfo,
    wgt_type const maxpwgt)
{
  vtx_type i, k, g, v, m, nmoves, lvtx, olvtx, minmove, totalmoves, ntotalmoves;
  adj_type j, npulled, l;
  wgt_type minsep, newbal, minbal, gain, cursep;
  pid_type side, other, p;
  tid_type nbrid, onbrid, myid;
  vtx_type * moves, * pulled, * pullmk;
  vsnbrinfo_type * myrinfo;
  size_t pass;
  vw_pq_t * q[2];
  int ** glocked;
  vsnbrinfo_type ** gnbrinfo;
  vtx_iset_t ** gbnd;

  tid_type const nthreads = graph->dist.nthreads;

  vtx_type const nvtxs = graph->nvtxs;
  vtx_type const * const gmynvtxs = graph->mynvtxs;
  adj_type const * const * const gxadj = (adj_type const **)graph->xadj;
  vtx_type const * const * const gadjncy = (vtx_type const **)graph->adjncy;
  wgt_type const * const * const gvwgt = (wgt_type const **)graph->vwgt;

  wgt_type * const pwgts = graph->pwgts;
  pid_type * const * const gwhere = graph->where;

  vtx_type const limit = ctrl->hillsize;

  DL_ASSERT_EQUALS(nthreads,graph->dist.nthreads,"%"PF_TID_T);

  myid = dlthread_get_id(ctrl->comm);

  glocked = dlthread_get_shmem((sizeof(int*)*nthreads) + \
      (sizeof(vsnbrinfo_type*)*nthreads) + \
      (sizeof(vtx_iset_t*)*nthreads),ctrl->comm);

  gnbrinfo = (vsnbrinfo_type**)(glocked+nthreads);
  gbnd = (vtx_iset_t**)(gnbrinfo+nthreads);

  gnbrinfo[myid] = vsinfo->nbrinfo;
  glocked[myid] = int_alloc(gmynvtxs[myid]);
  gbnd[myid] = vsinfo->bnd;

  dlthread_barrier(ctrl->comm);

  /* allocate stuff only needed by master thread */
  if (myid == 0) {
    moves = vtx_alloc(nvtxs+1); /* we start at 1 not 0 */
    pullmk = vtx_alloc(nvtxs+2);
    pulled = vtx_alloc(nvtxs*3);

    /* setup priority queues */
    q[MTMETIS_VSEP_PARTA] = vw_pq_create(0,graph->gnvtxs);
    q[MTMETIS_VSEP_PARTB] = vw_pq_create(0,graph->gnvtxs);
  } else {
    /* suppress compiler warnings */
    moves = NULL;
    pullmk = NULL;
    pulled = NULL;
    q[MTMETIS_VSEP_PARTA] = NULL;
    q[MTMETIS_VSEP_PARTB] = NULL;
  }

  ntotalmoves = 0;

  for (pass=0;pass<niter;++pass) {
    /* The overall algorithm for a refinement pass looks as follows:
     * -Greedily select balanced moves to make, ensuring balance is maintained.
     * -Track the maximum objective state, and return to it at the end of each
     * pass.
     */

    /* reset locked state in parallel */
    myid = dlthread_get_id(ctrl->comm);
    int_set(glocked[myid],UNLOCKED,gmynvtxs[myid]);

    totalmoves = 0;

    dlthread_barrier(ctrl->comm);

    /* add boundary vertices to the queue */ 
    if (myid == 0) {
      /* initial tracking variables */
      nmoves = 0;
      npulled = 0;
      pullmk[1] = 0;
      minmove = 0;
      minbal = wgt_abs_diff(pwgts[0],pwgts[1]);
      cursep = minsep = graph->minsep;

      /* setup priority queues */
      for (p=0;p<MTMETIS_VSEP_SEP;++p) {
        vw_pq_clear(q[p]);
      }
      for (myid=0;myid<nthreads;++myid) {
        for (i=0;i<gbnd[myid]->size;++i) {
          v = vtx_iset_get(i,gbnd[myid]); 
          DL_ASSERT_EQUALS(MTMETIS_VSEP_SEP,gwhere[myid][v],"%"PF_PID_T);

          myrinfo = gnbrinfo[myid] + v;
          g = lvtx_to_gvtx(v,myid,graph->dist);
          for (p=0;p<MTMETIS_VSEP_SEP;++p) {
            gain = gvwgt[myid][v] - myrinfo->con[p^0x01];
            vw_pq_push(gain,g,q[p]);
          }
        }
      }

      /* make possible moves */
      while (nmoves < nvtxs) {
        side = S_pick_side(graph,pwgts,maxpwgt, \
            (vsnbrinfo_type const **)gnbrinfo,q);

        if (side == NULL_PID) {
          /* we've emptied the priority queues */
          break;
        }

        /* the side I'm not moving to */
        other = side ^ 0x01;

        g = vw_pq_pop(q[side]);
        v = gvtx_to_lvtx(g,graph->dist);
        myid = gvtx_to_tid(g,graph->dist);

        DL_ASSERT(glocked[myid][v] != (int)other,"Pulled a vertex " \
            "from %"PF_PID_T" but is locked to %"PF_PID_T,side,other);
        DL_ASSERT_EQUALS(MTMETIS_VSEP_SEP,gwhere[myid][v],"%"PF_PID_T);
        DL_ASSERT_EQUALS(vtx_iset_contains(v,gbnd[myid]),1,"%d");

        /* make sure we have space to record the vertices added to the
         * separator */
        if (npulled + gxadj[myid][v+1] - gxadj[myid][v] >= 2*nvtxs-1) {
          /* roll back to our best state */
          break;
        }

        /* update our minimum objective value or check to make sure we
         * haven't passed the search limit */
        cursep = cursep - (gvwgt[myid][v]-gnbrinfo[myid][v].con[other]);
        newbal = wgt_abs_diff(pwgts[side]+gvwgt[myid][v], \
            pwgts[other]-gnbrinfo[myid][v].con[other]);

        if (cursep < minsep || \
            (cursep == minsep && newbal < minbal)) {
          minsep = cursep;
          minmove = nmoves+1;
          /* we only need to abs this here, as if its negative, it means the
           * move increases the balance */
          minbal = newbal;
        } else {
          if (nmoves-minmove+1 > 2*limit || \
              (nmoves-minmove+1 > limit && cursep > 1.1*minsep)) {
            /* revert back to best cut */
            break; 
          }
        }

        /* Once we have selected a vertex to move, we need to update several
         * things:
         * -the partition and separator weights
         * -pull the neighboring vertices in 'other' into the separator
         * -update the priorities of the affected vertives
         */

        /* at this point, we have decided to make the move */
        myrinfo = gnbrinfo[myid] + v;
        gwhere[myid][v] = side;
        moves[++nmoves] = g; /* count one up */

        S_lock(v,glocked[myid],side);
        
        /* remove the vertex from the boundary -- and opposing pq */
        vtx_iset_remove(v,gbnd[myid]);
        if (vw_pq_contains(g,q[other])) {
          vw_pq_remove(g,q[other]);
        }

        /* adjust partition weights */
        pwgts[side] += gvwgt[myid][v];
        pwgts[MTMETIS_VSEP_SEP] -= gvwgt[myid][v];

        /* process edges */
        for (j=gxadj[myid][v];j<gxadj[myid][v+1];++j) {
          k = gadjncy[myid][j];
          if (k < gmynvtxs[myid]) {
            lvtx = k;
            nbrid = myid;
            k = lvtx_to_gvtx(lvtx,nbrid,graph->dist);
          } else {
            lvtx = gvtx_to_lvtx(k,graph->dist);
            nbrid = gvtx_to_tid(k,graph->dist);
          }
          /* from here k is a global vertex number */

          if (gwhere[nbrid][lvtx] == MTMETIS_VSEP_SEP) {
            /* update priorities of neighboring vertiecs */
            gnbrinfo[nbrid][lvtx].con[side] += gvwgt[myid][v];

            /* modify the gain/connectivity of other vertices in 
             * separator */
            if (glocked[nbrid][lvtx] != (int)side) {
              /* demote this vertex in the priority queue */
              gain = gvwgt[nbrid][lvtx] - \
                  gnbrinfo[nbrid][lvtx].con[side];
              vw_pq_update(gain,k,q[other]);
            }
            /* we do not need to update the 'side' priority queue, as the
             * gain associate with moving 'k' to 'side' remains the same */
          } else if (gwhere[nbrid][lvtx] == other) {
            /* pull this vertex into the separator */
            DL_ASSERT_EQUALS(vtx_iset_contains(lvtx,gbnd[nbrid]),0, \
                "%d");

            /* record vertex being pulled into the separator */
            pulled[npulled++] = k;

            /* actually move the vertex */
            vtx_iset_add(lvtx,gbnd[nbrid]);
            gwhere[nbrid][lvtx] = MTMETIS_VSEP_SEP;

            /* calculate the connectivity */
            wgt_set(gnbrinfo[nbrid][lvtx].con,0,2);
            for (l=gxadj[nbrid][lvtx];l<gxadj[nbrid][lvtx+1];++l) {
              m = gadjncy[nbrid][l];
              if (m < gmynvtxs[nbrid]) {
                olvtx = m;
                onbrid = nbrid;
              } else {
                olvtx = gvtx_to_lvtx(m,graph->dist);
                onbrid = gvtx_to_tid(m,graph->dist);
              }
              p = gwhere[onbrid][olvtx];
              if (p < MTMETIS_VSEP_SEP) {
                gnbrinfo[nbrid][lvtx].con[p] += gvwgt[onbrid][olvtx];
              }
            }

            /* update the partition weights */
            pwgts[other] -= gvwgt[nbrid][lvtx];
            pwgts[MTMETIS_VSEP_SEP] += gvwgt[nbrid][lvtx];

            /* add the vertex to the priority queue for further movement */
            if (glocked[nbrid][lvtx] != (int)other) {
              gain = gvwgt[nbrid][lvtx] - \
                     gnbrinfo[nbrid][lvtx].con[other];
              vw_pq_push(gain,k,q[side]);
            }
            if (glocked[nbrid][lvtx] != (int)side) {
              gain = gvwgt[nbrid][lvtx] - \
                     gnbrinfo[nbrid][lvtx].con[side];
              vw_pq_push(gain,k,q[other]);
            }

            /* update neighbors of the vertices pulled into the separator */
            for (l=gxadj[nbrid][lvtx];l<gxadj[nbrid][lvtx+1];++l) {
              m = gadjncy[nbrid][l];
              if (m < gmynvtxs[nbrid]) {
                /* local vertex */
                olvtx = m;
                onbrid = nbrid;
                m = lvtx_to_gvtx(olvtx,onbrid,graph->dist);
              } else {
                /* remote vertex */
                olvtx = gvtx_to_lvtx(m,graph->dist);
                onbrid = gvtx_to_tid(m,graph->dist);
              }

              if (gwhere[onbrid][olvtx] == MTMETIS_VSEP_SEP) {
                /* update connectivity */
                gnbrinfo[onbrid][olvtx].con[other] -= gvwgt[nbrid][lvtx];

                /* this vertex is in the separator, and is now more likely 
                 * to move. */
                if (glocked[onbrid][olvtx] != (int)other) {
                  /* update the value for moving this vertex in the same
                   * diretion */
                  gain = gvwgt[onbrid][olvtx] - \
                      gnbrinfo[onbrid][olvtx].con[other];
                  DL_ASSERT(vw_pq_contains(m,q[side]), \
                        "Vertex %"PF_VTX_T" not in queue for side %" \
                        PF_PID_T"\n",olvtx,side);
                  vw_pq_update(gain,m,q[side]);
                }
              }
            }
          }
        }

        /* mark the number of vertices I pulled into the boundary */
        pullmk[nmoves+1] = npulled;

        DL_ASSERT_EQUALS(pwgts[MTMETIS_VSEP_SEP],cursep,"%"PF_WGT_T);
      }

      dprintf("FM: Pass %zu finished, sep = %"PF_WGT_T", rolling back %" \
          PF_VTX_T"/%"PF_VTX_T" moves\n",pass,pwgts[MTMETIS_VSEP_SEP], \
          nmoves-minmove,nmoves);

      /* rollback until we are back at the maximum state -- moves must be
       * undone in reverse of the order in which they were made */
      while (nmoves > minmove) {
        g = moves[nmoves];

        v = gvtx_to_lvtx(g,graph->dist);
        myid = gvtx_to_tid(g,graph->dist);

        side = gwhere[myid][v];
        other = side ^ 0x01;

        DL_ASSERT(side != MTMETIS_VSEP_SEP,"ATtempting to unmove vertex %" \
            PF_VTX_T" in separator\n",v);

        /* unmove this vertex */
        pwgts[MTMETIS_VSEP_SEP] += gvwgt[myid][v];
        pwgts[side] -= gvwgt[myid][v];

        gwhere[myid][v] = MTMETIS_VSEP_SEP;
        vtx_iset_add(v,gbnd[myid]);

        /* calculate the connectivity */
        wgt_set(gnbrinfo[myid][v].con,0,2);
        for (j=gxadj[myid][v];j<gxadj[myid][v+1];++j) {
          k = gadjncy[myid][j];
          if (k < gmynvtxs[myid]) {
            lvtx = k;
            nbrid = myid;
          } else {
            lvtx = gvtx_to_lvtx(k,graph->dist);
            nbrid = gvtx_to_tid(k,graph->dist);
          }
          p = gwhere[nbrid][lvtx];

          /* adjust priorities of neighboring vertices */
          if (p == MTMETIS_VSEP_SEP) {
            gnbrinfo[nbrid][lvtx].con[side] -= gvwgt[myid][v]; 
          } else {
            gnbrinfo[myid][v].con[p] += gvwgt[nbrid][lvtx];
          }
        }

        /* push nodes back out of the separator */ 
        for (i=pullmk[nmoves];i<pullmk[nmoves+1];++i) {
          k = pulled[i];
          lvtx = gvtx_to_lvtx(k,graph->dist);
          nbrid = gvtx_to_tid(k,graph->dist);

          DL_ASSERT_EQUALS(gwhere[nbrid][lvtx],MTMETIS_VSEP_SEP,"%"PF_PID_T);

          /* move the vertex */
          gwhere[nbrid][lvtx] = other;

          /* adjust partition weights */
          pwgts[other] += gvwgt[nbrid][lvtx];
          pwgts[MTMETIS_VSEP_SEP] -= gvwgt[nbrid][lvtx];

          /* remove the vertex from the boundary */
          vtx_iset_remove(lvtx,gbnd[nbrid]);

          /* update neighbor-neighbor connectivity */
          for (l=gxadj[nbrid][lvtx];l<gxadj[nbrid][lvtx+1];++l) {
            m = gadjncy[nbrid][l];
            if (m < gmynvtxs[nbrid]) {
              /* local vertex */
              olvtx = m;
              onbrid = nbrid;
              m = lvtx_to_gvtx(olvtx,onbrid,graph->dist);
            } else {
              /* remote vertex */
              olvtx = gvtx_to_lvtx(m,graph->dist);
              onbrid = gvtx_to_tid(m,graph->dist);
            }

            if (gwhere[onbrid][olvtx] == MTMETIS_VSEP_SEP) {
              gnbrinfo[onbrid][olvtx].con[other] += gvwgt[nbrid][lvtx];
            }
          }
        }

        /* go to the next move */
        --nmoves;
      }

      DL_ASSERT_EQUALS(minsep,pwgts[MTMETIS_VSEP_SEP],"%"PF_WGT_T);

      graph->minsep = minsep;
      totalmoves += nmoves;
    }

    totalmoves = vtx_dlthread_sumreduce(totalmoves,ctrl->comm);

    if (totalmoves == 0) {
      /* exit the refinement pass if we do not make any moves */
      break;
    }

    ntotalmoves += totalmoves;
  }

  myid = dlthread_get_id(ctrl->comm);

  if (myid == 0) {
    dl_free(moves);
    dl_free(pulled);
    dl_free(pullmk);
    vw_pq_free(q[MTMETIS_VSEP_PARTA]);
    vw_pq_free(q[MTMETIS_VSEP_PARTB]);
  }

  DL_ASSERT(check_vsinfo(vsinfo,graph,(pid_type const **)gwhere), \
      "Bad vsinfo after refinement");
  DL_ASSERT(check_vsbnd(gbnd[myid],graph),"Bad boundary after " \
      "refinement");

  dl_free(glocked[myid]);

  dlthread_free_shmem(glocked,ctrl->comm);

  return ntotalmoves;
}


static vtx_type S_vseprefine_FM1S(
    ctrl_type * const ctrl, 
    graph_type * const graph,
    size_t const niter, 
    vsinfo_type * const vsinfo,
    wgt_type const maxpwgt)
{
  vtx_type i, k, g, v, m, nmoves, lvtx, olvtx, minmove, totalmoves, ntotalmoves;
  adj_type j, npulled, l;
  wgt_type minsep, newbal, minbal, gain, cursep;
  pid_type side, other, o, d, me;
  tid_type nbrid, onbrid, myid;
  vtx_type * moves, * pulled, * pullmk;
  vsnbrinfo_type * myrinfo;
  size_t pass;
  vw_pq_t * q;
  vsnbrinfo_type ** gnbrinfo;
  vtx_iset_t ** gbnd;

  tid_type const nthreads = graph->dist.nthreads;

  vtx_type const nvtxs = graph->nvtxs;
  vtx_type const * const gmynvtxs = graph->mynvtxs;
  adj_type const * const * const gxadj = (adj_type const **)graph->xadj;
  vtx_type const * const * const gadjncy = (vtx_type const **)graph->adjncy;
  wgt_type const * const * const gvwgt = (wgt_type const **)graph->vwgt;

  wgt_type * const pwgts = graph->pwgts;
  pid_type * const * const gwhere = graph->where;

  vtx_type const limit = ctrl->hillsize;

  DL_ASSERT_EQUALS(nthreads,graph->dist.nthreads,"%"PF_TID_T);

  myid = dlthread_get_id(ctrl->comm);

  gnbrinfo = dlthread_get_shmem((sizeof(vsnbrinfo_type*)*nthreads) + \
      (sizeof(vtx_iset_t*)*nthreads),ctrl->comm);
  gbnd = (vtx_iset_t**)(gnbrinfo+nthreads);

  gnbrinfo[myid] = vsinfo->nbrinfo;
  gbnd[myid] = vsinfo->bnd;

  /* allocate stuff only needed by master thread */
  if (myid == 0) {
    moves = vtx_alloc(nvtxs+1); /* we start at 1 not 0 */
    pullmk = vtx_alloc(nvtxs+2);
    pulled = vtx_alloc(nvtxs*3);

    /* setup priority queues */
    q = vw_pq_create(0,graph->gnvtxs);
  } else {
    /* suppress compiler warnings */
    moves = NULL;
    pullmk = NULL;
    pulled = NULL;
    q = NULL;
  }

  ntotalmoves = 0;

  for (pass=0;pass<niter;++pass) {
    /* The overall algorithm for a refinement pass looks as follows:
     * -Greedily select balanced moves to make, ensuring balance is maintained.
     * -Track the maximum objective state, and return to it at the end of each
     * pass.
     */

    /* reset locked state in parallel */
    myid = dlthread_get_id(ctrl->comm);

    totalmoves = 0;

    dlthread_barrier(ctrl->comm);

    /* add boundary vertices to the queue */ 
    if (myid == 0) {
      if (pwgts[0] > pwgts[1]) {
        o = 1;
      } else if (pwgts[0] < pwgts[1]) {
        o = 0;
      } else {
        o = graph->level % 2;
      }

      for (d=0;d<2;++d) {
        side = (d+o) % 2;
        other = side ^ 0x01;

        /* initial tracking variables */
        nmoves = 0;
        npulled = 0;
        pullmk[1] = 0;
        minmove = 0;
        minbal = wgt_abs_diff(pwgts[0],pwgts[1]);

        vw_pq_clear(q);
        for (myid=0;myid<nthreads;++myid) {
          for (i=0;i<gbnd[myid]->size;++i) {
            v = vtx_iset_get(i,gbnd[myid]); 
            DL_ASSERT_EQUALS(MTMETIS_VSEP_SEP,gwhere[myid][v],"%"PF_PID_T);

            myrinfo = gnbrinfo[myid] + v;
            g = lvtx_to_gvtx(v,myid,graph->dist);
            gain = gvwgt[myid][v] - myrinfo->con[other];
            vw_pq_push(gain,g,q);
          }
        }

        cursep = minsep = graph->minsep;

        /* make possible moves */
        while (nmoves < nvtxs && q->size > 0) {
          g = vw_pq_pop(q);
          v = gvtx_to_lvtx(g,graph->dist);
          myid = gvtx_to_tid(g,graph->dist);

          DL_ASSERT_EQUALS(MTMETIS_VSEP_SEP,gwhere[myid][v],"%"PF_PID_T);
          DL_ASSERT_EQUALS(vtx_iset_contains(v,gbnd[myid]),1,"%d");

          /* make sure we're not overweight */
          if (pwgts[side] >= maxpwgt) {
            break;
          }

          if (pwgts[side] + gvwgt[myid][v] > maxpwgt) {
            continue;
          }

          /* make sure we have space to record the vertices added to the
           * separator */
          if (npulled + gxadj[myid][v+1] - gxadj[myid][v] >= 2*nvtxs-1) {
            /* roll back to our best state */
            break;
          }

          /* update our minimum objective value or check to make sure we
           * haven't passed the search limit */
          cursep = cursep - (gvwgt[myid][v]-gnbrinfo[myid][v].con[other]);
          newbal = wgt_abs_diff(pwgts[side]+gvwgt[myid][v], \
              pwgts[other]-gnbrinfo[myid][v].con[other]);

          if (cursep < minsep || \
              (cursep == minsep && newbal < minbal)) {
            minsep = cursep;
            minmove = nmoves+1;
            /* we only need to abs this here, as if its negative, it means the
             * move increases the balance */
            minbal = newbal;
          } else {
            if (nmoves-minmove+1 > 3*limit ||
                (nmoves-minmove+1 > limit && cursep > minsep*1.1)) {
              /* revert back to best cut */
              break; 
            }
          }

          /* Once we have selected a vertex to move, we need to update several
           * things:
           * -the partition and separator weights
           * -pull the neighboring vertices in 'other' into the separator
           * -update the priorities of the affected vertives
           */

          /* at this point, we have decided to make the move */
          myrinfo = gnbrinfo[myid] + v;
          gwhere[myid][v] = side;
          moves[++nmoves] = g; /* count one up */
            
          /* remove the vertex from the boundary -- and opposing pq */
          vtx_iset_remove(v,gbnd[myid]);

          /* adjust partition weights */
          pwgts[side] += gvwgt[myid][v];
          pwgts[MTMETIS_VSEP_SEP] -= gvwgt[myid][v];

          /* process edges */
          for (j=gxadj[myid][v];j<gxadj[myid][v+1];++j) {
            k = gadjncy[myid][j];
            if (k < gmynvtxs[myid]) {
              lvtx = k;
              nbrid = myid;
              k = lvtx_to_gvtx(lvtx,nbrid,graph->dist);
            } else {
              lvtx = gvtx_to_lvtx(k,graph->dist);
              nbrid = gvtx_to_tid(k,graph->dist);
            }
            /* from here k is a global vertex number */

            if (gwhere[nbrid][lvtx] == MTMETIS_VSEP_SEP) {
              /* update priorities of neighboring vertiecs */
              gnbrinfo[nbrid][lvtx].con[side] += gvwgt[myid][v];

              /* we do not need to update the 'side' priority queue, as the
               * gain associate with moving 'k' to 'side' remains the same */
            } else if (gwhere[nbrid][lvtx] == other) {
              /* pull this vertex into the separator */
              DL_ASSERT_EQUALS(vtx_iset_contains(lvtx,gbnd[nbrid]),0, \
                  "%d");

              /* record vertex being pulled into the separator */
              pulled[npulled++] = k;

              /* actually move the vertex */
              vtx_iset_add(lvtx,gbnd[nbrid]);
              gwhere[nbrid][lvtx] = MTMETIS_VSEP_SEP;

              /* calculate the connectivity */
              S_calc_conn(lvtx,nbrid,gmynvtxs[nbrid],gxadj[nbrid], \
                  gadjncy[nbrid],gvwgt,(pid_type const **)gwhere,graph->dist, \
                  gnbrinfo[nbrid][lvtx].con);

              /* update the partition weights */
              pwgts[other] -= gvwgt[nbrid][lvtx];
              pwgts[MTMETIS_VSEP_SEP] += gvwgt[nbrid][lvtx];

              /* add the vertex to the priority queue for further movement */
              gain = gvwgt[nbrid][lvtx] - \
                     gnbrinfo[nbrid][lvtx].con[other];
              vw_pq_push(gain,k,q);

              /* update neighbors of the vertices pulled into the separator */
              for (l=gxadj[nbrid][lvtx];l<gxadj[nbrid][lvtx+1];++l) {
                m = gadjncy[nbrid][l];
                if (m < gmynvtxs[nbrid]) {
                  /* local vertex */
                  olvtx = m;
                  onbrid = nbrid;
                  m = lvtx_to_gvtx(olvtx,onbrid,graph->dist);
                } else {
                  /* remote vertex */
                  olvtx = gvtx_to_lvtx(m,graph->dist);
                  onbrid = gvtx_to_tid(m,graph->dist);
                }

                if (gwhere[onbrid][olvtx] == MTMETIS_VSEP_SEP) {
                  /* update connectivity */
                  gnbrinfo[onbrid][olvtx].con[other] -= gvwgt[nbrid][lvtx];

                  /* this vertex is in the separator, and is now more likely 
                   * to move. */

                  /* update the value for moving this vertex in the same
                   * diretion */
                  if (vw_pq_contains(m,q)) {
                    gain = gvwgt[onbrid][olvtx] - \
                        gnbrinfo[onbrid][olvtx].con[other];
                    vw_pq_update(gain,m,q);
                  }
                }
              }
            }
          }

          /* mark the number of vertices I pulled into the boundary */
          pullmk[nmoves+1] = npulled;

          DL_ASSERT_EQUALS(pwgts[MTMETIS_VSEP_SEP],cursep,"%"PF_WGT_T);
        }

        dprintf("FM1S: Pass %zu finished, sep = %"PF_WGT_T", rolling back %" \
            PF_VTX_T"/%"PF_VTX_T" moves\n",pass,pwgts[MTMETIS_VSEP_SEP], \
            nmoves-minmove,nmoves);

        /* rollback until we are back at the maximum state -- moves must be
         * undone in reverse of the order in which they were made */
        while (nmoves > minmove) {
          g = moves[nmoves];

          v = gvtx_to_lvtx(g,graph->dist);
          myid = gvtx_to_tid(g,graph->dist);

          DL_ASSERT(side != MTMETIS_VSEP_SEP,"ATtempting to unmove vertex %" \
              PF_VTX_T" in separator\n",v);

          /* unmove this vertex */
          pwgts[MTMETIS_VSEP_SEP] += gvwgt[myid][v];
          pwgts[side] -= gvwgt[myid][v];

          gwhere[myid][v] = MTMETIS_VSEP_SEP;
          vtx_iset_add(v,gbnd[myid]);

          /* calculate the connectivity */
          S_calc_conn(v,myid,gmynvtxs[myid],gxadj[myid],gadjncy[myid],gvwgt, \
              (pid_type const **)gwhere,graph->dist, \
              gnbrinfo[myid][v].con);

          /* adjust priorities of neighboring vertices */
          for (j=gxadj[myid][v];j<gxadj[myid][v+1];++j) {
            k = gadjncy[myid][j];
            if (k < gmynvtxs[myid]) {
              lvtx = k;
              nbrid = myid;
            } else {
              lvtx = gvtx_to_lvtx(k,graph->dist);
              nbrid = gvtx_to_tid(k,graph->dist);
            }
            me = gwhere[nbrid][lvtx];

            if (me == MTMETIS_VSEP_SEP) {
              gnbrinfo[nbrid][lvtx].con[side] -= gvwgt[myid][v]; 
            }
          }

          /* push nodes back out of the separator */ 
          for (i=pullmk[nmoves];i<pullmk[nmoves+1];++i) {
            k = pulled[i];
            lvtx = gvtx_to_lvtx(k,graph->dist);
            nbrid = gvtx_to_tid(k,graph->dist);

            DL_ASSERT_EQUALS(gwhere[nbrid][lvtx],MTMETIS_VSEP_SEP,"%"PF_PID_T);

            /* move the vertex */
            gwhere[nbrid][lvtx] = other;

            /* adjust partition weights */
            pwgts[other] += gvwgt[nbrid][lvtx];
            pwgts[MTMETIS_VSEP_SEP] -= gvwgt[nbrid][lvtx];

            /* remove the vertex from the boundary */
            vtx_iset_remove(lvtx,gbnd[nbrid]);

            /* update neighbor-neighbor connectivity */
            for (l=gxadj[nbrid][lvtx];l<gxadj[nbrid][lvtx+1];++l) {
              m = gadjncy[nbrid][l];
              if (m < gmynvtxs[nbrid]) {
                /* local vertex */
                olvtx = m;
                onbrid = nbrid;
                m = lvtx_to_gvtx(olvtx,onbrid,graph->dist);
              } else {
                /* remote vertex */
                olvtx = gvtx_to_lvtx(m,graph->dist);
                onbrid = gvtx_to_tid(m,graph->dist);
              }

              me = gwhere[onbrid][olvtx];

              if (me == MTMETIS_VSEP_SEP) {
                gnbrinfo[onbrid][olvtx].con[other] += gvwgt[nbrid][lvtx];
              }
            }
          }

          /* go to the next move */
          --nmoves;
        }
        DL_ASSERT_EQUALS(minsep,pwgts[MTMETIS_VSEP_SEP],"%"PF_WGT_T);

        graph->minsep = minsep;
        totalmoves += nmoves;
      }
    }

    totalmoves = vtx_dlthread_sumreduce(totalmoves,ctrl->comm);

    if (totalmoves == 0) {
      /* exit the refinement pass if we do not make any moves */
      break;
    }

    ntotalmoves += totalmoves;
  }

  myid = dlthread_get_id(ctrl->comm);

  if (myid == 0) {
    dl_free(moves);
    dl_free(pulled);
    dl_free(pullmk);
    vw_pq_free(q);
  }

  DL_ASSERT(check_vsinfo(vsinfo,graph,(pid_type const **)gwhere), \
      "Bad vsinfo after refinement");
  DL_ASSERT(check_vsbnd(gbnd[myid],graph),"Bad boundary after " \
      "refinement");

  dlthread_free_shmem(gnbrinfo,ctrl->comm);

  return ntotalmoves;
}


static vtx_type S_vseprefine_SFM(
    ctrl_type * const ctrl, 
    graph_type * const graph,
    size_t const niter, 
    vsinfo_type * const vsinfo,
    wgt_type const maxpwgt)
{
  vtx_type i, k, ntotalmoves, totalmoves, niface;
  adj_type j;
  size_t pass;
  vtx_type * moves, * pullmk, * pulled, * iface;
  vw_pq_t * q;
  int * locked;

  tid_type const myid = dlthread_get_id(ctrl->comm);

  vtx_type const mynvtxs = graph->mynvtxs[myid];
  adj_type const * const xadj = graph->xadj[myid];
  vtx_type const * const adjncy = graph->adjncy[myid];

  locked = int_init_alloc(UNLOCKED,mynvtxs);
  moves = vtx_alloc(mynvtxs+1);
  pullmk = vtx_alloc(mynvtxs+2);
  pulled = vtx_alloc(mynvtxs*2);

  /* setup priority queues */
  q = vw_pq_create(0,mynvtxs);
  iface = vtx_alloc(mynvtxs);

  /* determine locked vertices */
  niface = 0;
  for (i=0;i<mynvtxs;++i) {
    for (j=xadj[i];j<xadj[i+1];++j) {
      k = adjncy[j];
      if (k >= mynvtxs) {
        iface[niface++] = i;
        break;
      }
    }
  }

  ntotalmoves = 0;

  for (pass=0;pass<niter;++pass) {
    for (k=0;k<niface;++k) {
      i = iface[k];
      S_lock(i,locked,graph->where[myid][i]);
    }

    totalmoves = S_pass_SFM1S(ctrl,graph,vsinfo,moves,pullmk,pulled,q, \
        locked,iface,niface,maxpwgt);

    if (totalmoves == 0) {
      break;
    }

    ntotalmoves += totalmoves;
  }

  dl_free(moves);
  dl_free(pulled);
  dl_free(pullmk);
  dl_free(iface);
  vw_pq_free(q);

  if (myid == 0) {
    graph->minsep = graph->pwgts[MTMETIS_VSEP_SEP];
  }

  dl_free(locked);

  DL_ASSERT(check_vsinfo(vsinfo,graph,(pid_type const **)graph->where), \
      "Bad vsinfo after refinement");
  DL_ASSERT(check_vsbnd(vsinfo->bnd,graph),"Bad boundary after " \
      "refinement");

  dlthread_barrier(ctrl->comm);

  return ntotalmoves;
}


static vtx_type S_vseprefine_GREEDY(
    ctrl_type * const ctrl, 
    graph_type * const graph,
    size_t const niter, 
    vsinfo_type * const vsinfo,
    wgt_type const maxpwgt)
{
  vtx_type gnmoves, ntotalmoves, niface, i, k;
  adj_type j;
  vtx_type * iface;
  vsnbrinfo_type ** gnbrinfo;
  size_t pass;
  vw_pq_t * q;
  update_combuffer_t * combuffer;

  tid_type const myid = dlthread_get_id(ctrl->comm);
  tid_type const nthreads = dlthread_get_nthreads(ctrl->comm);

  vtx_type const mynvtxs = graph->mynvtxs[myid];
  adj_type const * const xadj = graph->xadj[myid];
  vtx_type const * const adjncy = graph->adjncy[myid];

  DL_ASSERT_EQUALS(nthreads,graph->dist.nthreads,"%"PF_TID_T);

  gnbrinfo = dlthread_get_shmem(sizeof(vsnbrinfo_type*)*nthreads,ctrl->comm);

  gnbrinfo[myid] = vsinfo->nbrinfo;

  q = vw_pq_create(0,mynvtxs);
  iface = vtx_alloc(mynvtxs);

  combuffer = update_combuffer_create(ctrl->comm);

  ntotalmoves = 0;

  dlthread_barrier(ctrl->comm);

  niface = 0;
  for (i=0;i<mynvtxs;++i) {
    for (j=xadj[i];j<xadj[i+1];++j) {
      k = adjncy[j];
      if (k >= mynvtxs) {
        iface[niface++] = i;
        break;
      }
    }
  }

  for (pass=0;pass<niter;++pass) {
    gnmoves = S_pass_GREEDY(ctrl,graph,vsinfo,gnbrinfo,combuffer,q,iface, \
        niface,maxpwgt,0);

    if (gnmoves == 0) {
      /* exit the refinement pass if we do not make any moves */
      break;
    }

    ntotalmoves += gnmoves;
  }

  if (myid == 0) {
    graph->minsep = graph->pwgts[MTMETIS_VSEP_SEP];
  }

  vw_pq_free(q);
  dl_free(iface);

  #ifdef USE_ASSERTS
  dlthread_barrier(ctrl->comm);
  #endif

  DL_ASSERT(check_vsinfo(vsinfo,graph,(pid_type const **)graph->where), \
      "Bad vsinfo after refinement");
  DL_ASSERT(check_vsbnd(vsinfo->bnd,graph),"Bad boundary after " \
      "refinement");

  dlthread_free_shmem(gnbrinfo,ctrl->comm);

  update_combuffer_free(combuffer);

  return ntotalmoves;
}


static vtx_type S_vseprefine_SFG(
    ctrl_type * const ctrl, 
    graph_type * const graph,
    size_t const niter, 
    vsinfo_type * const vsinfo,
    wgt_type const maxpwgt)
{
  vtx_type i, k, nmoves, niface;
  adj_type j;
  int * locked;
  vtx_type * moves, * pullmk, * pulled, * iface;
  vw_pq_t * q;
  update_combuffer_t * combuffer;
  vsnbrinfo_type ** gnbrinfo;

  tid_type const myid = dlthread_get_id(ctrl->comm);
  tid_type const nthreads = dlthread_get_nthreads(ctrl->comm);

  vtx_type const mynvtxs = graph->mynvtxs[myid];
  adj_type const * const xadj = graph->xadj[myid];
  vtx_type const * const adjncy = graph->adjncy[myid];

  DL_ASSERT_EQUALS(nthreads,graph->dist.nthreads,"%"PF_TID_T);

  gnbrinfo = dlthread_get_shmem(sizeof(vsnbrinfo_type*)*nthreads,ctrl->comm);

  gnbrinfo[myid] = vsinfo->nbrinfo;

  locked = int_init_alloc(UNLOCKED,mynvtxs);
  iface = vtx_alloc(mynvtxs);
  moves = vtx_alloc(mynvtxs);
  pullmk = vtx_alloc(mynvtxs+1);
  pulled = vtx_alloc(mynvtxs*2);

  /* setup priority queues */
  q = vw_pq_create(0,mynvtxs);

  /* determine locked vertices */
  niface = 0;
  for (i=0;i<mynvtxs;++i) {
    for (j=xadj[i];j<xadj[i+1];++j) {
      k = adjncy[j];
      if (k >= mynvtxs) {
        iface[niface++] = i;
        break;
      }
    }
  }

  combuffer = update_combuffer_create(ctrl->comm);

  nmoves = S_pass_GREEDY(ctrl,graph,vsinfo,gnbrinfo,combuffer,q, \
        iface,niface,maxpwgt,0);

  for (k=0;k<niface;++k) {
    i = iface[k];
    S_lock(i,locked,graph->where[myid][i]);
  }

  nmoves += S_pass_SFM1S(ctrl,graph,vsinfo,moves,pullmk,pulled,q,locked, \
      iface,niface,maxpwgt);

  if (myid == 0) {
    graph->minsep = graph->pwgts[MTMETIS_VSEP_SEP];
  }

  dl_free(moves);
  dl_free(pulled);
  dl_free(pullmk);
  dl_free(locked);
  dl_free(iface);
  vw_pq_free(q);

  #ifdef USE_ASSERTS
  dlthread_barrier(ctrl->comm);
  #endif

  DL_ASSERT(check_vsinfo(vsinfo,graph,(pid_type const **)graph->where), \
      "Bad vsinfo after refinement");
  DL_ASSERT(check_vsbnd(vsinfo->bnd,graph),"Bad boundary after " \
      "refinement");

  dlthread_free_shmem(gnbrinfo,ctrl->comm);
  update_combuffer_free(combuffer);

  return nmoves;
}




/******************************************************************************
* PUBLIC FUNCTIONS ************************************************************
******************************************************************************/


vtx_type par_vseprefine(
    ctrl_type * const ctrl,
    graph_type * const graph,
    vsinfo_type * const vsinfo)
{
  vtx_type nmoves;

  wgt_type const avgvtxwgt = graph->tvwgt/graph->nvtxs;
  wgt_type * const pwgts = graph->pwgts;

  wgt_type const maxpwgt = ctrl->ubfactor*(pwgts[0]+pwgts[1])*0.5;

  DL_ASSERT(check_separator(graph,(pid_type const **)graph->where), \
      "Bad separator before refinement");
  DL_ASSERT(check_vsinfo(vsinfo,graph,(pid_type const **)graph->where), \
      "Bad vsinfo before refinement");
  DL_ASSERT(check_vsbnd(vsinfo->bnd,graph),"Bad boundary before refinement");

  if (graph->nvtxs < SERIAL_FM_FACTOR*sqrt(graph->dist.nthreads)) {
    nmoves = S_vseprefine_FM1S(ctrl,graph,ctrl->nrefpass,vsinfo,maxpwgt);
  } else {
    /* disabled for now */
    if (0 && dl_max(pwgts[0],pwgts[1]) > maxpwgt*1.03 && \
         4*avgvtxwgt < wgt_abs_diff(pwgts[0],pwgts[1])) {
      S_pass_BAL(ctrl,graph,vsinfo,maxpwgt);
    }
    switch (ctrl->rtype) {
      case MTMETIS_RTYPE_GREEDY:
        nmoves = S_vseprefine_GREEDY(ctrl,graph,ctrl->nrefpass,vsinfo,maxpwgt);
        break;
      case MTMETIS_RTYPE_FM:
        nmoves = S_vseprefine_FM1S(ctrl,graph,ctrl->nrefpass,vsinfo,maxpwgt);
        break;
      case MTMETIS_RTYPE_SFM:
        nmoves = S_vseprefine_SFM(ctrl,graph,ctrl->nrefpass,vsinfo,maxpwgt);
        break;
      case MTMETIS_RTYPE_SFG:
        nmoves = S_vseprefine_SFG(ctrl,graph,ctrl->nrefpass,vsinfo,maxpwgt);
        break;
      default:
        dl_error("Unknown refinement type '%d'\n",ctrl->rtype);
    }
  }

  DL_ASSERT_EQUALS(wgt_lsum(graph->pwgts,3),graph->tvwgt,"%"PF_TWGT_T);
  DL_ASSERT_EQUALS(graph->pwgts[2],graph->minsep,"%"PF_WGT_T);
  DL_ASSERT(check_separator(graph,(pid_type const **)graph->where), \
      "Bad separator after refinement");

  par_vprintf(ctrl->verbosity,MTMETIS_VERBOSITY_HIGH,"%zu) [%"PF_VTX_T" %" \
      PF_ADJ_T"] {%"PF_WGT_T" %"PF_WGT_T" %"PF_WGT_T" # %"PF_WGT_T" %" \
      PF_VTX_T"}\n",graph->level,graph->nvtxs,graph->nedges,pwgts[0], \
      pwgts[1],pwgts[2],maxpwgt,nmoves);

  return nmoves;
}





#endif
