/**
 * @file eseprefine.c
 * @brief Functions for performing refinement of two way edge separators.
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright 2015, Regents of the University of Minnesota
 * @version 1
 * @date 2015-02-26
 */





#ifndef MTMETIS_ESEPREFINE_C
#define MTMETIS_ESEPREFINE_C




#include "eseprefine.h"
#include "check.h"




/******************************************************************************
* TYPES ***********************************************************************
******************************************************************************/


typedef struct update_type {
  vtx_type v; 
  wgt_type w;
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


#define DLPQ_PREFIX vt
#define DLPQ_KEY_T wgt_type
#define DLPQ_VAL_T vtx_type
#define DLPQ_USE_HT
#define DLPQ_STATIC
#include "dlpq_headers.h"
#undef DLPQ_STATIC
#undef DLPQ_USE_HT
#undef DLPQ_VAL_T
#undef DLPQ_KEY_T
#undef DLPQ_PREFIX


#define DLLCB_PREFIX update
#define DLLCB_TYPE_T update_type
#define DLLCB_STATIC 1
#include "dllcb_headers.h"
#undef DLLCB_STATIC
#undef DLLCB_TYPE_T
#undef DLLCB_PREFIX


#define DLLCB_PREFIX vtx
#define DLLCB_TYPE_T vtx_type
#define DLLCB_STATIC 1
#include "dllcb_headers.h"
#undef DLLCB_STATIC
#undef DLLCB_TYPE_T
#undef DLLCB_PREFIX






/******************************************************************************
* CONSTANTS *******************************************************************
******************************************************************************/


static size_t const SERIAL_FM_FACTOR = 32768; /* 2^16 */




/******************************************************************************
* PRIVATE SERIAL FUNCTIONS ****************************************************
******************************************************************************/


static inline pid_type S_pick_side(
    graph_type const * const graph,
    real_type const * const tpwgts,
    wgt_type const * const maxpwgt,
    vw_pq_t * const * const q)
{
  vtx_type p, v, g;
  tid_type myid;
  pid_type side, other;

  wgt_type const * const pwgts = graph->pwgts;
  wgt_type const * const * const gvwgt = (wgt_type const **)graph->vwgt;

  /* part next move properties */
  vtx_type vtx[2];
  wgt_type wgt[2], pri[2];

  /* determine stats for each side */
  for (p=0;p<MTMETIS_ESEP_NPARTS;++p) {
    if (q[p]->size > 0) {
      g = vtx[p] = vw_pq_peek(q[p]);
      v = gvtx_to_lvtx(g,graph->dist);
      myid = gvtx_to_tid(g,graph->dist);
      pri[p] = vw_pq_top(q[p]);
      wgt[p] = pwgts[p] + gvwgt[myid][v];
    } else {
      pri[p] = -graph->tadjwgt; /* below a valid priority */
      vtx[p] = NULL_VTX;
      wgt[p] = NULL_WGT;
    }
  }

  /* figure out which side we'll use -- this seems like I could do it 
   * better */
  if (vtx[MTMETIS_ESEP_PARTA] == NULL_VTX && \
      vtx[MTMETIS_ESEP_PARTB] == NULL_VTX) {
    /* exit loop -- both queues are empty */
    return NULL_PID;
  } else if (pri[MTMETIS_ESEP_PARTA] > pri[MTMETIS_ESEP_PARTB]) {
    side = MTMETIS_ESEP_PARTA;
  } else if (pri[MTMETIS_ESEP_PARTA] < pri[MTMETIS_ESEP_PARTB]) {
    side = MTMETIS_ESEP_PARTB;
  } else {
    /* equal priorities */
    if (wgt[MTMETIS_ESEP_PARTA]*tpwgts[MTMETIS_ESEP_PARTB] < \
        wgt[MTMETIS_ESEP_PARTB]*tpwgts[MTMETIS_ESEP_PARTA]) {
      side = MTMETIS_ESEP_PARTA;
    } else if (wgt[MTMETIS_ESEP_PARTB]*tpwgts[MTMETIS_ESEP_PARTA] < \
        wgt[MTMETIS_ESEP_PARTA]*tpwgts[MTMETIS_ESEP_PARTB]) {
      side = MTMETIS_ESEP_PARTB;
    } else {
      /* alternate sides */
      side = (q[MTMETIS_ESEP_PARTA]->size + q[MTMETIS_ESEP_PARTB]->size) % 2;
    } 
  }

  other = side ^ 0x01;

  /* make sure we are not making things imbalanced */
  if (wgt[side] > maxpwgt[side] && \
      wgt[side]*tpwgts[other] > wgt[other]*tpwgts[side]) {
    side = other;
    if (vtx[side] == NULL_VTX) {
      /* the other side is empty, so do nothing */
      return NULL_PID;
    }
  }

  DL_ASSERT(q[side]->size > 0,"Choosing side with empty queue");

  if (vtx[side] == NULL_VTX) {
    return NULL_PID;
  } else {
    return side;
  }
}


static void S_move_vertex_1S(
    tid_type const myid,
    vtx_type const v,
    pid_type const side,
    graph_type * const graph,
    esnbrinfo_type * const * const gnbrinfo,
    vtx_iset_t * const * const gbnd,
    vw_pq_t * const q)
{
  vtx_type k, lvtx;
  adj_type j;
  tid_type nbrid;
  wgt_type gain;

  vtx_type const * const gmynvtxs = graph->mynvtxs;
  adj_type const * const * const gxadj = (adj_type const **)graph->xadj;
  vtx_type const * const * const gadjncy = (vtx_type const **)graph->adjncy;
  wgt_type const * const * const gvwgt = (wgt_type const **)graph->vwgt;
  wgt_type const * const * const gadjwgt = (wgt_type const **)graph->adjwgt;

  wgt_type * const pwgts = graph->pwgts;
  pid_type * const * const gwhere = graph->where;

  pid_type const other = side ^ 0x01;

  gwhere[myid][v] = side;

  pwgts[side] += gvwgt[myid][v];
  pwgts[other] -= gvwgt[myid][v];

  /* process edges */
  for (j=gxadj[myid][v];j<gxadj[myid][v+1];++j) {
    k = gadjncy[myid][j];
    if (k < gmynvtxs[myid]) {
      lvtx = k;
      nbrid = myid;
      k = lvtx_to_gvtx(k,myid,graph->dist);
    } else {
      lvtx = gvtx_to_lvtx(k,graph->dist);
      nbrid = gvtx_to_tid(k,graph->dist);
    }

    /* update connectivity */
    gnbrinfo[nbrid][lvtx].con[side] += gadjwgt[myid][j];
    gnbrinfo[nbrid][lvtx].con[other] -= gadjwgt[myid][j];

    /* remove or add to boundary */
    if (gwhere[nbrid][lvtx] == side) {
      if (gnbrinfo[nbrid][lvtx].con[other] == 0) {
        vtx_iset_remove(lvtx,gbnd[nbrid]);
      }
    } else {
      if (!vtx_iset_contains(lvtx,gbnd[nbrid])) {
        vtx_iset_add(lvtx,gbnd[nbrid]);
        /* add to queue */
        if (q) {
          gain = gnbrinfo[nbrid][lvtx].con[side] - \
              gnbrinfo[nbrid][lvtx].con[other];
          vw_pq_push(gain,k,q);
        }
      } else {
        if (q && vw_pq_contains(k,q)) {
          gain = gnbrinfo[nbrid][lvtx].con[side] - \
              gnbrinfo[nbrid][lvtx].con[other];
          vw_pq_update(gain,k,q);
        }
      }
    }
  }

  /* see if I need to be added to or removed from the boundary */
  if (gnbrinfo[myid][v].con[other] > 0) {
    if (!vtx_iset_contains(v,gbnd[myid])) {
      vtx_iset_add(v,gbnd[myid]);
    }
  } else if (gnbrinfo[myid][v].con[side] > 0) {
    /* Only non-island vertices get removed from the boundary */
    if (vtx_iset_contains(v,gbnd[myid])) {
      vtx_iset_remove(v,gbnd[myid]);
    }
  }
}


static void S_move_vertex_2S(
    tid_type const myid,
    vtx_type const v,
    pid_type const side,
    int * const * const lock,
    graph_type * const graph,
    esnbrinfo_type * const * const gnbrinfo,
    vtx_iset_t * const * const gbnd,
    vw_pq_t * const * const q)
{
  vtx_type k, lvtx;
  adj_type j;
  tid_type nbrid;
  wgt_type gain;

  vtx_type const * const gmynvtxs = graph->mynvtxs;
  adj_type const * const * const gxadj = (adj_type const **)graph->xadj;
  vtx_type const * const * const gadjncy = (vtx_type const **)graph->adjncy;
  wgt_type const * const * const gvwgt = (wgt_type const **)graph->vwgt;
  wgt_type const * const * const gadjwgt = (wgt_type const **)graph->adjwgt;

  wgt_type * const pwgts = graph->pwgts;
  pid_type * const * const gwhere = graph->where;

  pid_type const other = side ^ 0x01;

  lock[myid][v] = 1;
  gwhere[myid][v] = side;

  pwgts[side] += gvwgt[myid][v];
  pwgts[other] -= gvwgt[myid][v];

  /* process edges */
  for (j=gxadj[myid][v];j<gxadj[myid][v+1];++j) {
    k = gadjncy[myid][j];
    if (k < gmynvtxs[myid]) {
      lvtx = k;
      nbrid = myid;
      k = lvtx_to_gvtx(k,myid,graph->dist);
    } else {
      lvtx = gvtx_to_lvtx(k,graph->dist);
      nbrid = gvtx_to_tid(k,graph->dist);
    }

    /* update connectivity */
    gnbrinfo[nbrid][lvtx].con[side] += gadjwgt[myid][j];
    gnbrinfo[nbrid][lvtx].con[other] -= gadjwgt[myid][j];

    /* remove or add to boundary */
    if (gwhere[nbrid][lvtx] == side) {
      if (gnbrinfo[nbrid][lvtx].con[other] == 0) {
        vtx_iset_remove(lvtx,gbnd[nbrid]);
      } else {
        if (q && !lock[nbrid][lvtx]) {
          gain = gnbrinfo[nbrid][lvtx].con[other] - \
              gnbrinfo[nbrid][lvtx].con[side];
          if (vw_pq_contains(k,q[other])) {
            vw_pq_update(gain,k,q[other]);
          } else {
            vw_pq_push(gain,k,q[other]);
          }
        }
      }
    } else {
      if (!vtx_iset_contains(lvtx,gbnd[nbrid])) {
        vtx_iset_add(lvtx,gbnd[nbrid]);
        /* add to queue */
        if (q && !lock[nbrid][lvtx]) {
          gain = gnbrinfo[nbrid][lvtx].con[side] - \
              gnbrinfo[nbrid][lvtx].con[other];
          vw_pq_push(gain,k,q[side]);
        }
      } else {
        if (q && !lock[nbrid][lvtx] && vw_pq_contains(k,q[side])) {
          gain = gnbrinfo[nbrid][lvtx].con[side] - \
              gnbrinfo[nbrid][lvtx].con[other];
          vw_pq_update(gain,k,q[side]);
        }
      }
    }
  }

  /* see if I need to be added to or removed from the boundary */
  if (gnbrinfo[myid][v].con[other] > 0) {
    if (!vtx_iset_contains(v,gbnd[myid])) {
      vtx_iset_add(v,gbnd[myid]);
    }
  } else if (gnbrinfo[myid][v].con[side] > 0) {
    /* Only non-island vertices get removed from the boundary */
    if (vtx_iset_contains(v,gbnd[myid])) {
      vtx_iset_remove(v,gbnd[myid]);
    }
  }
}


static vtx_type S_eseprefine_FM1S(
    ctrl_type * const ctrl,
    graph_type * const graph,
    size_t const niter,
    esinfo_type * const esinfo,
    wgt_type const * const maxpwgt)
{
  vtx_type v, g, i, nmoves, totalmoves, minmove, ntotalmoves;
  wgt_type mincut, curcut, minbal, curbal, gain;
  pid_type side, other, o, d;
  tid_type myid;
  vtx_type * moves;
  esnbrinfo_type * myrinfo;
  size_t pass;
  vw_pq_t * q;
  esnbrinfo_type ** gnbrinfo;
  vtx_iset_t ** gbnd;

  tid_type const nthreads = graph->dist.nthreads;

  wgt_type const * const * const gvwgt = (wgt_type const **)graph->vwgt;
  real_type const * const tpwgts = ctrl->tpwgts;

  wgt_type * const pwgts = graph->pwgts;
  pid_type * const * const gwhere = graph->where;

  vtx_type const limit = dl_min(dl_max(0.01*graph->nvtxs,15), \
      ctrl->hillsize);

  myid = dlthread_get_id(ctrl->comm);

  gnbrinfo = dlthread_get_shmem((sizeof(esnbrinfo_type*)*nthreads) + \
      (sizeof(vtx_iset_t*)*nthreads),ctrl->comm);
  gbnd = (vtx_iset_t**)(gnbrinfo+nthreads);

  gnbrinfo[myid] = esinfo->nbrinfo;
  gbnd[myid] = esinfo->bnd;

  /* allocate stuff only needed by master thread */

  ntotalmoves = 0;

  /* make sure gbnd and gnbrinfo is set up */
  dlthread_barrier(ctrl->comm);

  if (myid == 0) {
    moves = vtx_alloc(graph->nvtxs);
    q = vw_pq_create(0,graph->gnvtxs);

    for (pass=0;pass<niter;++pass) {
      totalmoves = 0;

      if (pwgts[0]*tpwgts[1] > pwgts[1]*tpwgts[0]) {
        o = 1;
      } else if (pwgts[0]*tpwgts[1] < pwgts[1]*tpwgts[0]) {
        o = 0;
      } else {
        o = graph->level % 2;
      }

      for (d=0;d<2;++d) {
        side = (d+o) % 2;
        other = side ^ 0x01;

        /* move vertices to 'side' from 'other' */

        nmoves = 0;
        minmove = 0;
        minbal = wgt_abs_diff(pwgts[0]*tpwgts[1],pwgts[1]*tpwgts[0]);

        vw_pq_clear(q);
        for (myid=0;myid<nthreads;++myid) {
          for (i=0;i<gbnd[myid]->size;++i) {
            v = vtx_iset_get(i,gbnd[myid]); 
            /* only add vertices in other partition */
            if (gwhere[myid][v] == other) {
              myrinfo = gnbrinfo[myid] + v;
              g = lvtx_to_gvtx(v,myid,graph->dist);
              gain = myrinfo->con[side] - myrinfo->con[other];
              vw_pq_push(gain,g,q);
            }
          }
        }

        curcut = mincut = graph->mincut;

        /* make possible moves */
        while (q->size > 0) {
          g = vw_pq_pop(q);
          v = gvtx_to_lvtx(g,graph->dist);
          myid = gvtx_to_tid(g,graph->dist);

          DL_ASSERT_EQUALS(other,gwhere[myid][v],"%"PF_PID_T);

          if (pwgts[side] >= maxpwgt[side]) {
            break;
          }

          if (pwgts[side]+gvwgt[myid][v] > maxpwgt[side] && \
              (pwgts[side]+gvwgt[myid][v])*tpwgts[other] > \
              pwgts[other]*tpwgts[side]) {
            /* search for another vertex to move */
            continue;
          }

          myrinfo = gnbrinfo[myid] + v;

          curcut = curcut - (myrinfo->con[side] - myrinfo->con[other]);
          curbal = wgt_abs_diff((pwgts[side]+gvwgt[myid][v])*tpwgts[other], \
              (pwgts[other]-gvwgt[myid][v])*tpwgts[side]);

          if (curcut < mincut || \
              (curcut == mincut && curbal < minbal) || \
              (pwgts[other] > maxpwgt[other] && curbal < minbal)) {
            mincut = curcut;
            minmove = nmoves+1;
            /* we only need to abs this here, as if its negative, it means the
             * move increases the balance */
            minbal = curbal;
          } else {
            if (nmoves-minmove+1 > limit) {
              /* revert back to best cut */
              break; 
            }
          }
          
          /* move the vertex */
          moves[++nmoves] = g;

          S_move_vertex_1S(myid,v,side,graph,gnbrinfo,gbnd,q);
        }

        /* undo bad moves */
        while (nmoves > minmove) {
          g = moves[nmoves];

          v = gvtx_to_lvtx(g,graph->dist);
          myid = gvtx_to_tid(g,graph->dist);

          S_move_vertex_1S(myid,v,other,graph,gnbrinfo,gbnd,NULL);

          --nmoves;
        }
        graph->mincut = mincut;
        totalmoves += nmoves;
      }

      if (totalmoves == 0) {
        break;
      }
      ntotalmoves += totalmoves;
    }

    dl_free(moves);
    vw_pq_free(q);

    /* restore my id */
    myid = 0;
  }

  ntotalmoves = vtx_dlthread_broadcast(ntotalmoves,0,ctrl->comm);

  DL_ASSERT(check_esinfo(esinfo,graph,(pid_type const **)gwhere), \
      "Bad esinfo after refinement");
  DL_ASSERT(check_esbnd(gbnd[myid],graph),"Bad boundary after " \
      "refinement");

  dlthread_free_shmem(gnbrinfo,ctrl->comm);

  return ntotalmoves;
}


static vtx_type S_eseprefine_FM2S(
    ctrl_type * const ctrl,
    graph_type * const graph,
    size_t const niter,
    esinfo_type * const esinfo,
    wgt_type const * const maxpwgt)
{
  vtx_type v, g, i, nmoves, minmove, ntotalmoves;
  wgt_type mincut, curcut, minbal, curbal, gain;
  pid_type side, other;
  tid_type myid;
  vtx_type * moves;
  int ** lock;
  esnbrinfo_type * myrinfo;
  size_t pass;
  vw_pq_t * q[2];
  esnbrinfo_type ** gnbrinfo;
  vtx_iset_t ** gbnd;

  tid_type const nthreads = graph->dist.nthreads;

  wgt_type const * const * const gvwgt = (wgt_type const **)graph->vwgt;
  real_type const * const tpwgts = ctrl->tpwgts;

  wgt_type * const pwgts = graph->pwgts;
  pid_type * const * const gwhere = graph->where;
  wgt_type const maxbal = \
      (ctrl->ubfactor-1.0)*(dl_max(tpwgts[0],tpwgts[1])*graph->tvwgt) + \
      (graph->tvwgt/graph->nvtxs);

  vtx_type const limit = dl_min(dl_max(0.01*graph->nvtxs,15), \
      ctrl->hillsize);

  myid = dlthread_get_id(ctrl->comm);

  gnbrinfo = dlthread_get_shmem((sizeof(esnbrinfo_type*)*nthreads) + \
      (sizeof(vtx_iset_t*)*nthreads)+(sizeof(int*)*nthreads),ctrl->comm);
  gbnd = (vtx_iset_t**)(gnbrinfo+nthreads);
  lock = (int**)(gbnd+nthreads);

  gnbrinfo[myid] = esinfo->nbrinfo;
  gbnd[myid] = esinfo->bnd;
  lock[myid] = int_init_alloc(0,graph->mynvtxs[myid]);

  /* allocate stuff only needed by master thread */

  ntotalmoves = 0;

  if (myid == 0) {
    moves = vtx_alloc(graph->nvtxs);
    q[0] = vw_pq_create(0,graph->gnvtxs);
    q[1] = vw_pq_create(0,graph->gnvtxs);

    for (pass=0;pass<niter;++pass) {
      /* move vertices to 'side' from 'other' */
      nmoves = 0;
      minmove = 0;
      minbal = wgt_abs_diff(pwgts[0]*tpwgts[1],pwgts[1]*tpwgts[0]);

      vw_pq_clear(q[0]);
      vw_pq_clear(q[1]);
      for (myid=0;myid<nthreads;++myid) {
        for (i=0;i<gbnd[myid]->size;++i) {
          v = vtx_iset_get(i,gbnd[myid]); 
          /* only add vertices in other partition */
          other = gwhere[myid][v];
          side = other ^ 0x01;
          myrinfo = gnbrinfo[myid] + v;
          g = lvtx_to_gvtx(v,myid,graph->dist);
          gain = myrinfo->con[side] - myrinfo->con[other];
          vw_pq_push(gain,g,q[side]);
        }
      }

      curcut = mincut = graph->mincut;

      /* make possible moves */
      while (q[0]->size + q[1]->size > 0) {
        side = S_pick_side(graph,tpwgts,maxpwgt,q);
        other = side ^ 0x01;

        /* handles invalid moves */
        if (side == NULL_PID) {
          break;
        }

        g = vw_pq_pop(q[side]);

        v = gvtx_to_lvtx(g,graph->dist);
        myid = gvtx_to_tid(g,graph->dist);

        DL_ASSERT_EQUALS(other,gwhere[myid][v],"%"PF_PID_T);

        if (pwgts[side]+gvwgt[myid][v] > maxpwgt[side] && \
            (pwgts[side]+gvwgt[myid][v])*tpwgts[other] > \
                pwgts[other]*tpwgts[side]) {
          /* search for another vertex to move */
          continue;
        }

        myrinfo = gnbrinfo[myid] + v;

        curcut = curcut - (myrinfo->con[side] - myrinfo->con[other]);
        curbal = wgt_abs_diff((pwgts[side]+gvwgt[myid][v])*tpwgts[other], \
            (pwgts[other]-gvwgt[myid][v])*tpwgts[side]);

        if ((curcut < mincut && curbal < dl_max(maxbal,minbal)) || \
            (curcut == mincut && curbal < minbal) || \
            (minbal > maxbal && curbal < minbal)) {
          mincut = curcut;
          minmove = nmoves+1;
          /* we only need to abs this here, as if its negative, it means the
           * move increases the balance */
          minbal = curbal;
        } else {
          if (nmoves-minmove+1 > limit) {
            /* revert back to best cut */
            break; 
          }
        }
        
        /* move the vertex */
        moves[++nmoves] = g;

        S_move_vertex_2S(myid,v,side,lock,graph,gnbrinfo,gbnd,q);
      }

      /* undo bad moves */
      while (nmoves > minmove) {
        g = moves[nmoves];
        v = gvtx_to_lvtx(g,graph->dist);
        myid = gvtx_to_tid(g,graph->dist);

        other = gwhere[myid][v] ^ 0x01;

        S_move_vertex_1S(myid,v,other,graph,gnbrinfo,gbnd,NULL);

        /* unlock vertex */
        lock[myid][v] = 0;

        --nmoves;
      }
      /* unlock remaining vertices */
      for (i=1;i<=nmoves;++i) {
        g = moves[i];
        v = gvtx_to_lvtx(g,graph->dist);
        myid = gvtx_to_tid(g,graph->dist);

        lock[myid][v] = 0;
      }
      graph->mincut = mincut;

      if (nmoves == 0) {
        break;
      }
      ntotalmoves += nmoves;
    }

    dl_free(moves);
    vw_pq_free(q[0]);
    vw_pq_free(q[1]);
  }

  ntotalmoves = vtx_dlthread_broadcast(ntotalmoves,0,ctrl->comm);

  DL_ASSERT(check_esinfo(esinfo,graph,(pid_type const **)gwhere), \
      "Bad esinfo after refinement");
  DL_ASSERT(check_esbnd(gbnd[myid],graph),"Bad boundary after " \
      "refinement");

  dl_free(lock[myid]);

  dlthread_free_shmem(gnbrinfo,ctrl->comm);

  return ntotalmoves;
}




/******************************************************************************
* PRIVATE PARALLEL FUNCTIONS **************************************************
******************************************************************************/


static inline void S_par_sync_pwgts(
    tid_type const myid,
    wgt_type * const gpwgts,
    wgt_type * const lpwgts,
    dlthread_comm_t const comm)
{
  /* turn local pwgts into deltas */
  lpwgts[0] -= gpwgts[0];
  lpwgts[1] -= gpwgts[1];

  /* create global deltas */
  wgt_dlthread_sumareduce(lpwgts,3,comm);

  /* set local pwgts to be global pwgts */
  lpwgts[0] += gpwgts[0];
  lpwgts[1] += gpwgts[1];

  dlthread_barrier(comm);

  if (myid == 0) {
    /* re-sync global pwgts */
    gpwgts[0] = lpwgts[0];
    gpwgts[1] = lpwgts[1];
  }

  dlthread_barrier(comm);
}


static inline wgt_type S_par_update_neighbor(
    pid_type const side,
    vtx_type const v,
    adj_type const ewgt,
    pid_type const * const where,
    esnbrinfo_type * const nbrinfo,
    vtx_iset_t * const bnd,
    vw_pq_t * const q)
{
  wgt_type cut, gain;

  pid_type const other = side ^ 0x01;

  /* update connectivity */
  nbrinfo[v].con[side] += ewgt;
  nbrinfo[v].con[other] -= ewgt;

  /* remove or add to boundary */
  if (where[v] == side) {
    cut = -ewgt;
    if (nbrinfo[v].con[other] == 0) {
      vtx_iset_remove(v,bnd);
    }
  } else {
    cut = ewgt;
    if (!vtx_iset_contains(v,bnd)) {
      vtx_iset_add(v,bnd);
      /* add to queue */
      if (q) {
        gain = nbrinfo[v].con[side] - \
            nbrinfo[v].con[other];
        vw_pq_push(gain,v,q);
      }
    } else {
      if (q) {
        gain = nbrinfo[v].con[side] - \
            nbrinfo[v].con[other];
        if (vw_pq_contains(v,q)) {
          gain = nbrinfo[v].con[side] - \
              nbrinfo[v].con[other];
          vw_pq_update(gain,v,q);
        } else {
          vw_pq_push(gain,v,q);
        }
      }
    }
  }

  DL_ASSERT(nbrinfo[v].con[other] >= 0,"Negative con %"PF_WGT_T":%"PF_WGT_T \
      " ewgt = %"PF_WGT_T" for %"PF_TID_T":%"PF_VTX_T"\n",nbrinfo[v].con[0], \
      nbrinfo[v].con[1],ewgt,(tid_type)dlthread_get_id(DLTHREAD_COMM_ROOT),v);

  return cut;
}


static wgt_type S_par_move_vertex_1S(
    tid_type const myid,
    vtx_type const v,
    pid_type const side,
    graph_type * const graph,
    wgt_type * const pwgts,
    esnbrinfo_type * const nbrinfo,
    vtx_iset_t * const bnd,
    vw_pq_t * const q,
    update_combuffer_t * const combuffer)
{
  vtx_type k, lvtx;
  wgt_type cut;
  adj_type j;
  tid_type nbrid;
  update_type up;

  vtx_type const mynvtxs = graph->mynvtxs[myid];
  adj_type const * const xadj = graph->xadj[myid];
  vtx_type const * const adjncy = graph->adjncy[myid];
  wgt_type const * const vwgt = graph->vwgt[myid];
  wgt_type const * const adjwgt = graph->adjwgt[myid];

  pid_type * const where = graph->where[myid];

  pid_type const other = side ^ 0x01;

  cut = nbrinfo[v].con[other] - nbrinfo[v].con[side];

  where[v] = side;

  pwgts[side] += vwgt[v];
  pwgts[other] -= vwgt[v];

  /* process edges */
  for (j=xadj[v];j<xadj[v+1];++j) {
    k = adjncy[j];
    if (k < mynvtxs) {
      /* perform update myself */
      cut += S_par_update_neighbor(side,k,adjwgt[j],where,nbrinfo,bnd,q);
    } else {
      lvtx = gvtx_to_lvtx(k,graph->dist);
      nbrid = gvtx_to_tid(k,graph->dist);

      /* buffer update for neighbor */
      up.v = lvtx;
      up.w = adjwgt[j];
      update_combuffer_add(nbrid,up,combuffer);
    }
  }

  /* see if I need to be added to or removed from the boundary */
  if (nbrinfo[v].con[other] > 0) {
    if (!vtx_iset_contains(v,bnd)) {
      vtx_iset_add(v,bnd);
    }
  } else if (nbrinfo[v].con[side] > 0) {
    /* Only non-island vertices get removed from the boundary */
    if (vtx_iset_contains(v,bnd)) {
      vtx_iset_remove(v,bnd);
    }
  }

  return cut;
}


static vtx_type S_par_pass_GREEDY(
    pid_type const side,
    graph_type * const graph,
    wgt_type * const pwgts,
    real_type const * const tpwgts,
    wgt_type const * const maxpwgt,
    esnbrinfo_type * const nbrinfo,
    vtx_iset_t * const bnd,
    vw_pq_t * const q,
    update_combuffer_t * const combuffer,
    dlthread_comm_t const comm)
{
  vtx_type v, i, nmoves;
  pid_type other;
  wgt_type minbal, curbal, gain, cutdelta, mycut, ewgt;
  
  update_type up;
  esnbrinfo_type * myrinfo;

  tid_type const myid = dlthread_get_id(comm);
  tid_type const nthreads = dlthread_get_nthreads(comm);

  pid_type * const where = graph->where[myid];
  wgt_type const * const vwgt = graph->vwgt[myid];

  wgt_type const localmax = dl_min( \
      ((maxpwgt[side] - pwgts[side])/(double)nthreads) + \
      pwgts[side],maxpwgt[side]);

  other = side ^ 0x01;

  /* move vertices to 'side' from 'other' */

  mycut = 0;
  nmoves = 0;
  minbal = wgt_abs_diff(pwgts[0]*tpwgts[1],pwgts[1]*tpwgts[0]);

  vw_pq_clear(q);
  for (i=0;i<bnd->size;++i) {
    v = vtx_iset_get(i,bnd); 
    /* only add vertices in other partition */
    if (where[v] == other) {
      myrinfo = nbrinfo + v;
      gain = myrinfo->con[side] - myrinfo->con[other];
      vw_pq_push(gain,v,q);
    }
  }

  /* make possible moves */
  do {
    /* recieve updates from other threads */
    while (update_combuffer_next(&up,combuffer)) {
      v = up.v;
      ewgt = up.w;

      DL_ASSERT(v < graph->mynvtxs[myid],"Bad vertex attached to update: %" \
          PF_VTX_T"/%"PF_VTX_T,v,graph->mynvtxs[myid]);

      mycut += S_par_update_neighbor(side,v,ewgt,where,nbrinfo,bnd,q);
    }

    if (pwgts[side] < localmax && (q->size > 0 && vw_pq_top(q) >= 0)) {
      v = vw_pq_pop(q);

      DL_ASSERT_EQUALS(other,where[v],"%"PF_PID_T);

      if (pwgts[side]+vwgt[v] > localmax && \
          (pwgts[side]+vwgt[v])*tpwgts[other] > pwgts[other]*tpwgts[side]) {
        /* search for another vertex to move */
      } else {
        myrinfo = nbrinfo + v;

        cutdelta = (myrinfo->con[side] - myrinfo->con[other]);
        curbal = wgt_abs_diff((pwgts[side]+vwgt[v])*tpwgts[other], \
            (pwgts[other]-vwgt[v])*tpwgts[side]);

        if (cutdelta > 0 || \
            (cutdelta == 0 && curbal < minbal)) {
          minbal = curbal;
          ++nmoves;

          mycut += S_par_move_vertex_1S(myid,v,side,graph,pwgts,nbrinfo,bnd, \
              q,combuffer);
        }
      }
    }
  } while ((pwgts[side] < localmax && (q->size > 0 && vw_pq_top(q) >= 0)) || \
      !update_combuffer_finish(combuffer));

  DL_ASSERT_EQUALS(update_combuffer_next(NULL,combuffer),0,"%d");

  update_combuffer_clear(combuffer);

  /* implicit barrier */
  mycut = wgt_dlthread_sumreduce(mycut,comm) / 2;

  if (myid == 0) {
    DL_ASSERT(mycut <= 0,"Greedy refinement increasing cutsize by %" \
        PF_WGT_T,mycut);
    graph->mincut += mycut;
  }

  return nmoves;
}


static vtx_type S_par_eseprefine_GREEDY(
    ctrl_type * const ctrl,
    graph_type * const graph,
    size_t const niter,
    esinfo_type * const esinfo,
    wgt_type const * const maxpwgt)
{
  vtx_type totalmoves, ntotalmoves;
  pid_type side, o, d;
  size_t pass;
  wgt_type lpwgts[2];
  vw_pq_t * q;
  update_combuffer_t * combuffer;

  tid_type const myid = dlthread_get_id(ctrl->comm);

  esnbrinfo_type * const nbrinfo = esinfo->nbrinfo;
  vtx_iset_t * const bnd = esinfo->bnd;
  wgt_type * const pwgts = graph->pwgts;

  real_type const * const tpwgts = ctrl->tpwgts;

  combuffer = update_combuffer_create(graph->mynedges[myid],ctrl->comm);

  ntotalmoves = 0;
  q = vw_pq_create(0,graph->mynvtxs[myid]);

  for (pass=0;pass<niter;++pass) {
    totalmoves = 0;

    if (pwgts[0]*tpwgts[1] > pwgts[1]*tpwgts[0]) {
      o = 1;
    } else if (pwgts[0]*tpwgts[1] < pwgts[1]*tpwgts[0]) {
      o = 0;
    } else {
      o = graph->level % 2;
    }

    /* make sure all threads have selected the same 'o' */

    for (d=0;d<2;++d) {
      side = (d+o) % 2;

      wgt_copy(lpwgts,pwgts,2);

      dlthread_barrier(ctrl->comm);

      totalmoves += S_par_pass_GREEDY(side,graph,lpwgts,tpwgts,maxpwgt, \
          nbrinfo,bnd,q,combuffer,ctrl->comm);

      S_par_sync_pwgts(myid,pwgts,lpwgts,ctrl->comm);
    }

    totalmoves = vtx_dlthread_sumreduce(totalmoves,ctrl->comm);

    if (totalmoves == 0) {
      break;
    }
    ntotalmoves += totalmoves;
  }

  vw_pq_free(q);

  DL_ASSERT(check_esbnd(bnd,graph),"Bad boundary after refinement");
  DL_ASSERT(check_esinfo(esinfo,graph,(pid_type const **)graph->where), \
      "Bad esinfo after refinement");

  /* implicit barrier */
  update_combuffer_free(combuffer);

  return ntotalmoves;
}




/******************************************************************************
* PUBLIC PARALLEL FUNCTIONS ***************************************************
******************************************************************************/


vtx_type par_eseprefine(
    ctrl_type * const ctrl,
    graph_type * const graph,
    esinfo_type * const esinfo)
{
  vtx_type nmoves;
  wgt_type maxpwgt[2];

  wgt_type * const pwgts = graph->pwgts;

  DL_ASSERT(check_esinfo(esinfo,graph,(pid_type const **)graph->where), \
      "Bad esinfo before refinement");
  DL_ASSERT(check_esbnd(esinfo->bnd,graph),"Bad boundary before refinement");

  maxpwgt[0] = graph->tvwgt * ctrl->tpwgts[0] * ctrl->ubfactor;
  maxpwgt[1] = graph->tvwgt * ctrl->tpwgts[1] * ctrl->ubfactor;

  if (graph->nedges < SERIAL_FM_FACTOR*sqrt(graph->dist.nthreads)) {
    nmoves = S_eseprefine_FM1S(ctrl,graph,ctrl->nrefpass,esinfo,maxpwgt);
  } else {
    switch (ctrl->rtype) {
      case MTMETIS_RTYPE_FM:
        nmoves = S_eseprefine_FM1S(ctrl,graph,ctrl->nrefpass,esinfo,maxpwgt);
        break;
      case MTMETIS_RTYPE_GREEDY:
        nmoves = S_par_eseprefine_GREEDY(ctrl,graph,ctrl->nrefpass,esinfo, \
            maxpwgt);
        break;
      default:
        dl_error("Unknown refinement type for edge separators '%d'\n", \
            ctrl->rtype);
    }
  }

  DL_ASSERT_EQUALS(graph->mincut,par_graph_cut(graph, \
        (pid_type const **)graph->where),"%"PF_WGT_T);
  DL_ASSERT_EQUALS(wgt_lsum(graph->pwgts,2),graph->tvwgt,"%"PF_TWGT_T);
  DL_ASSERT(check_esbnd(esinfo->bnd,graph),"Bad boundary before refinement");

  par_vprintf(ctrl->verbosity,MTMETIS_VERBOSITY_HIGH,"%zu) [%"PF_VTX_T" %" \
      PF_ADJ_T"] {%"PF_WGT_T":%"PF_WGT_T" %"PF_WGT_T" # %"PF_WGT_T":%" \
      PF_WGT_T" %"PF_VTX_T"}\n",graph->level,graph->nvtxs,graph->nedges, \
      pwgts[0],pwgts[1],graph->mincut,maxpwgt[0],maxpwgt[1],nmoves);

  return nmoves;
}




#endif
