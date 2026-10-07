/**
 * @file kwayrefine.c
 * @brief KWay refinement routines
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright 2013-2015, Regents of the University of Minnesota
 * @version 1
 * @date 2013-05-20
 */





#ifndef MTMETIS_KWAYREFINE_C
#define MTMETIS_KWAYREFINE_C




#include "kwayrefine.h"
#include "check.h"




/******************************************************************************
* TYPES ***********************************************************************
******************************************************************************/


typedef struct move_type {
  pid_type to;
  vtx_type vtx;
} move_type;


typedef struct update_type {
  pid_type to;
  pid_type from;
  wgt_type ewgt;
  vtx_type nbr;
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


#define DLLCB_PREFIX move
#define DLLCB_TYPE_T move_type
#define DLLCB_STATIC 1
#include "dllcb_headers.h"
#undef DLLCB_STATIC
#undef DLLCB_TYPE_T
#undef DLLCB_PREFIX


#define DLLCB_PREFIX update
#define DLLCB_TYPE_T update_type
#define DLLCB_STATIC 1
#include "dllcb_headers.h"
#undef DLLCB_STATIC
#undef DLLCB_TYPE_T
#undef DLLCB_PREFIX


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


#define DLMSET_PREFIX vtx
#define DLMSET_TYPE_T vtx_type
#define DLMSET_STATIC
#include "dlmset_headers.h"
#undef DLMSET_STATIC
#undef DLMSET_TYPE_T
#undef DLMSET_PREFIX




/******************************************************************************
* CONSTANTS *******************************************************************
******************************************************************************/


static size_t const MIN_HILL_SIZE = 3;




/******************************************************************************
* PRIVATE FUNCTIONS ***********************************************************
******************************************************************************/


static inline pid_type S_partner(
    pid_type const side,
    pid_type const offset,
    pid_type const nparts,
    pid_type const d)
{
  pid_type other;

  pid_type const cycle = offset*2;
  pid_type const block = ((nparts/cycle)+(nparts%cycle ? 1 : 0))*cycle;

  /* figure out our side */
  if ((side / offset) % 2 == d) {
    other = (side + offset) % block;
  } else {
    other = ((block + side) - offset) % block;
  }

  return other;
}


static inline int S_right_side(
    int const dir,
    pid_type const to,
    pid_type const from)
{
  if (dir) {
    return to < from;
  } else {
    return to > from;
  }
}


/**
 * @brief Update a vertex incident the one being moved.
 *
 * @param ctrl The control structure.
 * @param k The vertex to update.
 * @param to The partition the vertex is being moved to.
 * @param from The partition the vertex is being moved from.
 * @param ewgt The edge connecting the moved vertex.
 * @param graph The graph.
 * @param bnd The boundary set of vertices.
 * @param queue The priority queue of vertices to move.
 *
 * @return The change in edgecut.
 */
static wgt_type S_update_vertex(
    ctrl_type * ctrl, 
    vtx_type const k, 
    pid_type const to, 
    pid_type const from, 
    wgt_type const ewgt, 
    graph_type * graph, 
    kwinfo_type * const kwinfo,
    vw_pq_t * queue)
{
  vtx_type l;
  wgt_type oed;
  real_type rgain;
  vtx_iset_t * bnd;
  kwnbrinfo_type * myrinfo;
  adjinfo_type * mynbrs;

  tid_type const myid = dlthread_get_id(ctrl->comm);

  pid_type * const where = graph->where[myid];
  pid_type const nparts = ctrl->nparts;
  pid_type const me = where[k];

  int const greedy = ctrl->rtype == MTMETIS_RTYPE_GREEDY;

  bnd = kwinfo->bnd;

  /* create my workspace */
  myrinfo = kwinfo->nbrinfo+k;

  oed = myrinfo->ed;
  
  mynbrs = kwinfo_get_nbrs(kwinfo,k, \
      dl_min(nparts,graph->xadj[myid][k+1]-graph->xadj[myid][k]));

  if (me == to) {
    myrinfo->id += ewgt;
    myrinfo->ed -= ewgt;
  } else if (me == from) {
    myrinfo->id -= ewgt;
    myrinfo->ed += ewgt;
  }
  /* add it to the boundary if necessary */
  if (!vtx_iset_contains(k,bnd)) {
    if (is_bnd(myrinfo->id,myrinfo->ed,greedy)) {
      vtx_iset_add(k,bnd);
    }
  } else if (!is_bnd(myrinfo->id,myrinfo->ed,greedy)) {
    vtx_iset_remove(k,bnd);
  }

  /* update nbrs */
  for (l=0;l<myrinfo->nnbrs;++l) {
    if (mynbrs[l].pid == from) {
      if (mynbrs[l].ed == ewgt) {
        mynbrs[l] = mynbrs[--myrinfo->nnbrs];
      } else {
        mynbrs[l].ed -= ewgt;
      }
      break;
    }
  }
  for (l=0;l<myrinfo->nnbrs;++l) {
    if (mynbrs[l].pid == to) {
      mynbrs[l].ed += ewgt;
      break;
    }
  }
  if (to != me && l == myrinfo->nnbrs) {
    mynbrs[myrinfo->nnbrs].ed = ewgt;
    mynbrs[myrinfo->nnbrs++].pid = to;
  }

  if (queue) {
    rgain = ((myrinfo->nnbrs > 0 ? \
          ((real_type)myrinfo->ed) / sqrt(myrinfo->nnbrs) : 0.0) \
          - myrinfo->id);

    if ((me == to || me == from)) {
      if (vw_pq_contains(k,queue)) {
        if ((!greedy && myrinfo->ed > 0) || rgain >= 0) {
          vw_pq_update(rgain,k,queue);
        } else {
          vw_pq_remove(k,queue);
        }
      }
    }
  }

  return oed - myrinfo->ed;
}


static wgt_type S_move_vertex(
    ctrl_type * const ctrl,
    graph_type * const graph,
    tid_type const myid,
    vtx_type const i,
    pid_type const to,
    kwinfo_type * const kwinfo,
    wgt_type * const pwgts,
    pid_type * const where,
    vw_pq_t * const q,
    update_combuffer_t * const combuffer)
{
  vtx_type k;
  adj_type j;
  wgt_type cut, ted, ewgt;
  tid_type nbrid;
  update_type up;
  adjinfo_type * mynbrs;

  pid_type const nparts = ctrl->nparts;
  vtx_type const mynvtxs = graph->mynvtxs[myid];
  adj_type const * const xadj = graph->xadj[myid];
  vtx_type const * const adjncy = graph->adjncy[myid];
  wgt_type const * const adjwgt = graph->adjwgt[myid];
  wgt_type const * const vwgt = graph->vwgt[myid];

  vtx_iset_t * const bnd = kwinfo->bnd;

  kwnbrinfo_type * const myrinfo = kwinfo->nbrinfo+i;
  pid_type const from = where[i];

  int const greedy = ctrl->rtype == MTMETIS_RTYPE_GREEDY;

  cut = 0;

  pwgts[to] += vwgt[i];
  pwgts[from] -= vwgt[i];
  where[i] = to;

  ted = myrinfo->ed;

  mynbrs = kwinfo_get_nbrs(kwinfo,i, \
      dl_min(nparts,graph->xadj[myid][i+1]-graph->xadj[myid][i]));

  for (k=0;k<myrinfo->nnbrs;++k) {
    if (mynbrs[k].pid == to) {
      break;
    }
  }
  if (k==myrinfo->nnbrs) {
    k = NULL_PID;
  }
  
  /* make the move */
  if (k != NULL_PID) {
    myrinfo->ed += myrinfo->id-mynbrs[k].ed;
    dl_swap(myrinfo->id,mynbrs[k].ed);
  } else if (myrinfo->id > 0) {
    myrinfo->ed += myrinfo->id;
    mynbrs[myrinfo->nnbrs].ed = myrinfo->id;
    k = myrinfo->nnbrs++;
    myrinfo->id = 0;
  }

  /* old minus new */
  cut += ted - myrinfo->ed;

  if (mynbrs[k].ed == 0) {
    mynbrs[k] = mynbrs[--myrinfo->nnbrs];
  } else {
    mynbrs[k].pid = from;
  }
 
  /* see if this vertex should be removed/added from the boundary */
  if (vtx_iset_contains(i,bnd)) {
    if (!is_bnd(myrinfo->id,myrinfo->ed,greedy)) {
      vtx_iset_remove(i,bnd);
    }
  } else {
    if (is_bnd(myrinfo->id,myrinfo->ed,greedy)) {
      vtx_iset_add(i,bnd);
    }
  }

  /* update neighbors */
  for(j=xadj[i];j<xadj[i+1];++j) {
    k = adjncy[j];
    ewgt = adjwgt[j];
    if (k < mynvtxs) {
      /* I own it */
      cut += S_update_vertex(ctrl,k,to,from,ewgt,graph,kwinfo,q);
    } else {
      /* notify my neighbor */
      nbrid = gvtx_to_tid(k,graph->dist);

      up.to = to;
      up.from = from;
      up.ewgt = ewgt;
      up.nbr = gvtx_to_lvtx(k,graph->dist);

      update_combuffer_add(nbrid,up,combuffer);
    }
  }

  return cut;
}


/**
 * @brief Update a vertex incident the one being moved in pairwise refinement.
 *
 * @param ctrl The control structure.
 * @param k The vertex to update.
 * @param to The partition the vertex is being moved to.
 * @param from The partition the vertex is being moved from.
 * @param ewgt The edge connecting the moved vertex.
 * @param graph The graph.
 * @param bnd The boundary set of vertices.
 * @param queue The priority queue of vertices to move.
 *
 * @return The change in edgecut.
 */
static wgt_type S_update_vertex_PW(
    ctrl_type * const ctrl, 
    graph_type * const graph, 
    tid_type const myid,
    vtx_type const v, 
    pid_type const to, 
    pid_type const from, 
    wgt_type const ewgt, 
    kwinfo_type * const kwinfo,
    vtx_mset_t * const bnd,
    vt_pq_t * queue)
{
  int isbnd;
  vtx_type l, g;
  wgt_type oed;
  real_type rgain;
  kwnbrinfo_type * myrinfo;
  adjinfo_type * mynbrs;

  pid_type * const where = graph->where[myid];
  pid_type const nparts = ctrl->nparts;
  pid_type const me = where[v];

  g = lvtx_to_gvtx(v,myid,graph->dist);

  /* create my workspace */
  myrinfo = kwinfo->nbrinfo+v;

  oed = myrinfo->ed;
  
  mynbrs = kwinfo_get_nbrs_lk(kwinfo,v, \
      dl_min(nparts,graph->xadj[myid][v+1]-graph->xadj[myid][v]));

  if (me == to) {
    myrinfo->id += ewgt;
    myrinfo->ed -= ewgt;
  } else if (me == from) {
    myrinfo->id -= ewgt;
    myrinfo->ed += ewgt;
  }

  /* update nbrs */
  isbnd = 1;
  for (l=0;l<myrinfo->nnbrs;++l) {
    if (mynbrs[l].pid == from) {
      if (mynbrs[l].ed == ewgt) {
        isbnd = 0;
        mynbrs[l] = mynbrs[--myrinfo->nnbrs];
      } else {
        mynbrs[l].ed -= ewgt;
      }
      break;
    }
  }
  for (l=0;l<myrinfo->nnbrs;++l) {
    if (mynbrs[l].pid == to) {
      mynbrs[l].ed += ewgt;
      break;
    }
  }
  if (to != me && l == myrinfo->nnbrs) {
    mynbrs[myrinfo->nnbrs].ed = ewgt;
    mynbrs[myrinfo->nnbrs++].pid = to;
    isbnd = 1;
  }

  /* add it to the boundary if necessary */
  if (!vtx_mset_contains(g,bnd)) {
    if (isbnd) {
      vtx_mset_add(g,bnd);
    }
  } else if (!isbnd) {
    vtx_mset_remove(g,bnd);
  }

  if (isbnd && queue && me == from) {
    rgain = 0;
    for (l=0;l<myrinfo->nnbrs;++l) {
      if (mynbrs[l].pid == to) {
        rgain = mynbrs[l].ed - myrinfo->id;
        break;
      }
    }
    DL_ASSERT(l<myrinfo->nnbrs,"Vertex not in boundary");

    if (vt_pq_contains(g,queue)) {
      vt_pq_update(rgain,g,queue);
    } else {
      vt_pq_push(rgain,g,queue);
    }
  }

  return oed - myrinfo->ed;
}


static wgt_type S_move_vertex_PW(
    ctrl_type * const ctrl,
    graph_type * const graph,
    tid_type const myid,
    vtx_type const i,
    pid_type const to,
    kwinfo_type * const * const gkwinfo,
    vtx_mset_t * const bnd,
    update_combuffer_t * const cb,
    vt_pq_t * const q)
{
  int isbnd;
  vtx_type k, g, lvtx;
  adj_type j;
  wgt_type cut, ted, ewgt;
  tid_type nbrid;
  update_type up;
  adjinfo_type * mynbrs;

  pid_type const nparts = ctrl->nparts;
  vtx_type const mynvtxs = graph->mynvtxs[myid];
  adj_type const * const xadj = graph->xadj[myid];
  vtx_type const * const adjncy = graph->adjncy[myid];
  wgt_type const * const adjwgt = graph->adjwgt[myid];
  wgt_type const * const vwgt = graph->vwgt[myid];

  pid_type * const * const gwhere = graph->where;
  wgt_type * const pwgts = graph->pwgts;
  pid_type const from = gwhere[myid][i];

  kwinfo_type * const kwinfo = gkwinfo[myid];
  kwnbrinfo_type * const myrinfo = kwinfo->nbrinfo+i;

  cut = 0;

  g = lvtx_to_gvtx(i,myid,graph->dist);

  pwgts[to] += vwgt[i];
  pwgts[from] -= vwgt[i];
  gwhere[myid][i] = to;

  ted = myrinfo->ed;

  mynbrs = kwinfo_get_nbrs_lk(kwinfo,i, \
      dl_min(nparts,graph->xadj[myid][i+1]-graph->xadj[myid][i]));

  for (k=0;k<myrinfo->nnbrs;++k) {
    if (mynbrs[k].pid == to) {
      break;
    }
  }
  if (k==myrinfo->nnbrs) {
    k = NULL_PID;
  }
  
  /* make the move */
  if (k != NULL_PID) {
    myrinfo->ed += myrinfo->id-mynbrs[k].ed;
    dl_swap(myrinfo->id,mynbrs[k].ed);
  } else if (myrinfo->id > 0) {
    myrinfo->ed += myrinfo->id;
    mynbrs[myrinfo->nnbrs].ed = myrinfo->id;
    k = myrinfo->nnbrs++;
    myrinfo->id = 0;
  }

  /* old minus new */
  cut += ted - myrinfo->ed;

  if (mynbrs[k].ed == 0) {
    isbnd = 0;
    mynbrs[k] = mynbrs[--myrinfo->nnbrs];
  } else {
    isbnd = 1;
    mynbrs[k].pid = from;
  }
 
  /* see if this vertex should be removed/added from the boundary */
  if (vtx_mset_contains(g,bnd)) {
    if (!isbnd) {
      vtx_mset_remove(g,bnd);
    }
  } else {
    if (isbnd) {
      vtx_mset_add(g,bnd);
    }
  }

  /* update neighbors */
  for(j=xadj[i];j<xadj[i+1];++j) {
    k = adjncy[j];
    ewgt = adjwgt[j];
    if (k < mynvtxs) {
      lvtx = k;
      nbrid = myid;
    } else {
      lvtx = gvtx_to_lvtx(k,graph->dist);
      nbrid = gvtx_to_tid(k,graph->dist);
    }

    if (gwhere[nbrid][lvtx] == to || gwhere[nbrid][lvtx] == from) {
      cut += S_update_vertex_PW(ctrl,graph,nbrid,lvtx,to,from,ewgt, \
          gkwinfo[nbrid],bnd,q);
    } else {
      /* this vertex is in another pair of partitions, and will be updated
       * later */
      up.to = to;
      up.from = from;
      up.ewgt = ewgt;
      up.nbr = lvtx;

      update_combuffer_add(nbrid,up,cb);
    }
  }

  return cut;
}


static vtx_type S_build_hill(
    ctrl_type * const ctrl,
    graph_type const * const graph,
    wgt_type const mingain,
    wgt_type const * const minpwgt,
    wgt_type const * const maxpwgt,
    vtx_type const v,
    kwinfo_type const * const * const gnbrinfo,
    pid_type const * const * const gwhere,
    wgt_type const * const pwgts,
    int * const * const hill,
    int * const * const traveled,
    int pass,
    vt_pq_t * const qh,
    vtx_type * const hlist,
    wgt_type * const con,
    pid_type * const r_to)
{
  vtx_type g,i,k,lvtx,hs,nsearched;
  adj_type j;
  tid_type nbrid,oid;
  wgt_type gain, hgain, cwgt, maxcon, exwgt, maxgain;
  pid_type to, p;
  kwnbrinfo_type const * myrinfo;
  adjinfo_type const * mynbrs;

  tid_type const myid = dlthread_get_id(ctrl->comm);

  vtx_type const limit = ctrl->hillsize;

  /* graph parts */
  vtx_type const * const gmynvtxs = graph->mynvtxs;
  adj_type const * const * const gxadj = (adj_type const **)graph->xadj;
  vtx_type const * const * const gadjncy = (vtx_type const **)graph->adjncy;
  wgt_type const * const * const gadjwgt= (wgt_type const **)graph->adjwgt;
  wgt_type const * const * const gvwgt = (wgt_type const **)graph->vwgt;

  pid_type const from = gwhere[myid][v];

  myrinfo = gnbrinfo[myid]->nbrinfo + v;

  gain = myrinfo->ed - myrinfo->id;
  g = lvtx_to_gvtx(v,myid,graph->dist);
  vt_pq_push(gain,g,qh);

  hs = 0;
  cwgt = 0;
  hgain = 0;
  exwgt = 0;
  wgt_set(con,0,ctrl->nparts);
  nsearched = 0;
  while (qh->size > 0 && (hs < MIN_HILL_SIZE || vt_pq_top(qh) >= mingain)) {
    gain = vt_pq_top(qh);

    g = vt_pq_pop(qh);
    i = gvtx_to_lvtx(g,graph->dist);
    oid = gvtx_to_tid(g,graph->dist);

    myrinfo = gnbrinfo[oid]->nbrinfo + i;
    mynbrs = kwinfo_get_nbrs_ro(gnbrinfo[oid],i, \
        dl_min(ctrl->nparts,gxadj[oid][i+1]-gxadj[oid][i]));

    if (hill[oid][i]) {
      /* someone else scooped up this vertex */
      continue;
    }

    cwgt += gvwgt[oid][i];
    if (pwgts[from] - cwgt < minpwgt[from]) {
      /* don't bother building heavy hills */
      break;
    }

    hgain += gain;
    exwgt += myrinfo->ed;

    hill[oid][i] = 1;
    hlist[hs++] = g;

    /* add connectivity info */
    maxcon = 0;
    if (mynbrs) { /* handle race condition */
      for (p=0;p<myrinfo->nnbrs;++p) {
        to = mynbrs[p].pid;
        if ((con[to] += mynbrs[p].ed) > maxcon && \
            pwgts[to]+cwgt < maxpwgt[to]) {
          maxcon = con[mynbrs[p].pid];
        }
      }
    }

    maxgain = hgain - exwgt + maxcon;
    if (maxgain > 0 || (maxgain == 0 && pwgts[from] > maxpwgt[from])) {
      break;
    }
    if (hs >= limit) {
      break;
    } 

    for (j=gxadj[oid][i];j<gxadj[oid][i+1];++j) {
      if (traveled[oid][j] < pass) {
        ++traveled[oid][j];
        k = gadjncy[oid][j];
        if (k < gmynvtxs[oid]) {
          lvtx = k;
          nbrid = oid;
          k = lvtx_to_gvtx(lvtx,nbrid,graph->dist);
        } else {
          lvtx = gvtx_to_lvtx(k,graph->dist);
          nbrid = gvtx_to_tid(k,graph->dist);
        }
        if (!hill[nbrid][lvtx]) {
          /* only consider unassigned vertices */
          if (gwhere[nbrid][lvtx] == from) {
            /* count edge weight twice as it detracts from current 
             * vertex connectivity and neighbor vertex connectivity */
            if (vt_pq_contains(k,qh)) {
              vt_pq_updateadd(2*gadjwgt[oid][j],k,qh);
            } else if (qh->size < qh->maxsize) {
              ++nsearched;
              myrinfo = gnbrinfo[nbrid]->nbrinfo + lvtx;
              gain = myrinfo->ed - myrinfo->id + 2*gadjwgt[oid][j];
              vt_pq_push(gain,k,qh);
            }
          }
        }
      }
    }
  }
  vt_pq_clear(qh);

  to = NULL_PID;
  /* find the best part to move this hill too */
  maxcon = exwgt - hgain;
  for (p=0;p<ctrl->nparts;++p) {
    if (con[p] > maxcon) {
      /* a gainful hill */
      if (pwgts[p] + cwgt <= maxpwgt[p]) {
        to = p;
        maxcon = con[p];
      }
    } else if (con[p] == maxcon && pwgts[from] >= maxpwgt[from]) {
      /* a balancing hill */
      if (to == NULL_PID) {
        if (pwgts[p]*ctrl->tpwgts[from] < pwgts[from]*ctrl->tpwgts[p]) {
          to = p;
        }
      } else if (pwgts[p]*ctrl->tpwgts[to] < pwgts[to]*ctrl->tpwgts[p]) {
        to = p;
      }
    }
  }

  /* make sure this hill is positive gain */
  hgain = hgain - exwgt + maxcon;
  if (hgain < 0) {
    to = NULL_PID;
  }

  if (to == NULL_PID) {
    for (k=0;k<hs;++k) {
      g = hlist[k];
      i = gvtx_to_lvtx(g,graph->dist);
      oid = gvtx_to_tid(g,graph->dist);
      hill[oid][i] = 0;
    }
    hs = 0;
  }

  *r_to = to;

  return hs;
}


static inline void S_par_sync_pwgts(
    tid_type const myid,
    pid_type const nparts,
    wgt_type * const gpwgts,
    wgt_type * const lpwgts,
    dlthread_comm_t const comm)
{
  pid_type p;

  /* turn local pwgts into deltas */
  for (p=0;p<nparts;++p) {
    lpwgts[p] -= gpwgts[p];
  }

  /* create global deltas */
  wgt_dlthread_sumareduce(lpwgts,nparts,comm);

  /* set local pwgts to be global pwgts */
  for (p=0;p<nparts;++p) {
    lpwgts[p] += gpwgts[p];
  }

  dlthread_barrier(comm);

  /* re-sync global pwgts */
  if (myid == 0) {
    for (p=0;p<nparts;++p) {
      gpwgts[p] = lpwgts[p];
    }
  }

  dlthread_barrier(comm);
}


static vtx_type S_pfm(
    ctrl_type * const ctrl,
    graph_type * const graph,
    kwinfo_type * const * const gkwinfo,
    wgt_type const * const maxpwgt,
    size_t const niter,
    pid_type const a,
    pid_type const b,
    vtx_mset_t * const bnd,
    update_combuffer_t * const cb)
{
  int d, nomoves;
  size_t pass;
  vtx_type i, v, g, k, nmoves, totalmoves, minmove;
  pid_type o, side, other, s;
  tid_type myid, oid;
  wgt_type cutdelta, minbal, gain, mincut, curbal;
  kwnbrinfo_type * myrinfo;
  adjinfo_type const * mynbrs;
  vtx_type * moves;
  vt_pq_t * q;

  vtx_type const limit = ctrl->hillsize;
  pid_type const nparts = ctrl->nparts;

  /* may limit refinement */
  vtx_type const pnvtxs = (graph->nvtxs*3)/nparts;

  wgt_type * const pwgts = graph->pwgts;

  pid_type * const * const gwhere = graph->where;
  wgt_type const * const * const gvwgt = (wgt_type const **)graph->vwgt;

  q = vt_pq_create(pnvtxs);
  moves = vtx_alloc(pnvtxs);

  totalmoves = 0;

  for (pass=0;pass<niter;++pass) {
    if (pwgts[a] > pwgts[b]) {
      o = 1;
    } else if (pwgts[a] < pwgts[b]) {
      o = 0;
    } else {
      o = graph->level % 2;
    }

    nomoves = 0;
    for (d=0;d<2;++d) {
      if (((d+o) % 2) == 0) {
        side = a;
        other = b;
      } else {
        side = b;
        other = a;
      }

      /* add vertices to priority queue */
      vt_pq_clear(q);
      myid = dlthread_get_id(ctrl->comm);
      for (i=0;i<bnd->info[myid].size;++i) {
        g = vtx_mset_get(i,bnd);
        v = gvtx_to_lvtx(g,graph->dist);
        oid = gvtx_to_tid(g,graph->dist);

        /* only add boundary vertices in 'other' */
        if (gwhere[oid][v] != other) {
          continue;
        }

        /* find the connecting neighbor */
        myrinfo = gkwinfo[oid]->nbrinfo + v;
        mynbrs = kwinfo_get_nbrs_ro(gkwinfo[oid],v, \
            dl_min(ctrl->nparts,graph->xadj[oid][v+1]-graph->xadj[oid][v]));

        for (s=0;s<myrinfo->nnbrs;++s) {
          if (mynbrs[s].pid == side) {
            break;
          }
        }
        DL_ASSERT(s < myrinfo->nnbrs,"Vertex %"PF_VTX_T"(%"PF_PID_T") in %" \
            PF_PID_T" not connected to %"PF_PID_T"\n",v,myrinfo->nnbrs,other, \
            side);

        gain = mynbrs[s].ed - myrinfo->id;
        vt_pq_push(gain,g,q);
      }

      nmoves = 0;
      minmove = 0;
      cutdelta = mincut = 0;
      minbal = wgt_abs_diff(pwgts[a],pwgts[b]);

      /* make possible moves */
      while (q->size > 0 && nmoves < pnvtxs) {
        g = vt_pq_pop(q);
        v = gvtx_to_lvtx(g,graph->dist);
        myid = gvtx_to_tid(g,graph->dist);

        DL_ASSERT_EQUALS(gwhere[myid][v],other,"%"PF_PID_T);

        if (pwgts[side] >= maxpwgt[side]) {
          break;
        }

        if (pwgts[side]+gvwgt[myid][v] > maxpwgt[side] && \
            pwgts[side]+gvwgt[myid][v] > pwgts[other]) {
          /* search for another vertex to move */
          continue;
        }

        myrinfo = gkwinfo[myid]->nbrinfo + v;
        mynbrs = kwinfo_get_nbrs_ro(gkwinfo[myid],v, \
            dl_min(ctrl->nparts,graph->xadj[myid][v+1]-graph->xadj[myid][v]));

        curbal = wgt_abs_diff(pwgts[side]+gvwgt[myid][v], \
            pwgts[other]-gvwgt[myid][v]);

        /* find side index */
        for (k=0;k<myrinfo->nnbrs;++k) {
          if (mynbrs[k].pid == side) {
            break;
          }
        }
        DL_ASSERT(k<myrinfo->nnbrs,"Edge not found");

        cutdelta = cutdelta - (mynbrs[k].ed - myrinfo->id);

        if (cutdelta < mincut || \
            (cutdelta == mincut && curbal < minbal)) {
          mincut = cutdelta;
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

        S_move_vertex_PW(ctrl,graph,myid,v,side,gkwinfo,bnd,cb,q);
      }

      /* undo bad moves */
      while (nmoves > minmove) {
        g = moves[nmoves];

        v = gvtx_to_lvtx(g,graph->dist);
        myid = gvtx_to_tid(g,graph->dist);


        S_move_vertex_PW(ctrl,graph,myid,v,other,gkwinfo,bnd,cb,NULL);

        --nmoves;
      }

      dprintf("Refinement pass %zu on %"PF_PID_T":%"PF_PID_T": %"PF_WGT_T \
          " improvement\n",pass,side,other,-mincut);

      if (nmoves > 0) {
        /* update move information */
        dlthread_exclude(ctrl->comm);
        graph->mincut += mincut;
        dlthread_unexclude(ctrl->comm);
        totalmoves += nmoves;
        nomoves = 0;
      } else {
        if (nomoves) {
          goto EXIT;
        } else {
          nomoves = 1;
        }
      }
    }
  }
  EXIT:

  dl_free(moves);
  vt_pq_free(q);

  return totalmoves;
}



/******************************************************************************
* REFINEMENT FUNCTIONS ********************************************************
******************************************************************************/


static vtx_type S_par_kwayrefine_GREEDY(
    ctrl_type * const ctrl, 
    graph_type * const graph,
    size_t const niter, 
    kwinfo_type * const kwinfo)
{
  vtx_type c, i, k, nmoved;
  adj_type j;
  wgt_type gain, wgt, mycut, ewgt;
  pid_type to, from;
  size_t pass;
  real_type rgain;
  wgt_type * lpwgts;
  kwnbrinfo_type * myrinfo;
  adjinfo_type const * mynbrs;
  vtx_iset_t * bnd;
  vw_pq_t * q;
  wgt_type * minwgt, * maxwgt;
  update_type up;
  update_combuffer_t * combuffer;

  tid_type const myid = dlthread_get_id(ctrl->comm);

  /* Link the graph fields */
  vtx_type const mynvtxs = graph->mynvtxs[myid];
  wgt_type const * const vwgt = graph->vwgt[myid];

  pid_type ** const gwhere = graph->where;
  wgt_type * const pwgts = graph->pwgts;
  
  pid_type const nparts = ctrl->nparts;

  kwnbrinfo_type * const nbrinfo = kwinfo->nbrinfo;
  pid_type * const where = gwhere[myid];
  real_type const * const tpwgts = ctrl->tpwgts;

  combuffer = update_combuffer_create(graph->mynedges[myid],ctrl->comm);

  lpwgts = wgt_alloc(nparts);
  wgt_copy(lpwgts,pwgts,nparts);

  minwgt = wgt_alloc(nparts);
  maxwgt = wgt_alloc(nparts);


  bnd = kwinfo->bnd;

  /* setup max/min partition weights */
  for (i=0;i<nparts;++i) {
    maxwgt[i]  = ctrl->tpwgts[i]*graph->tvwgt*ctrl->ubfactor;
    minwgt[i]  = ctrl->tpwgts[i]*graph->tvwgt*(1.0/ctrl->ubfactor);
  }

  DL_ASSERT(check_kwinfo(kwinfo,graph,(pid_type const **)gwhere),"Bad kwinfo");
  DL_ASSERT(check_kwbnd(kwinfo->bnd,graph,1),"Bad boundary");

  q = vw_pq_create(0,mynvtxs); 

  nmoved = 0;
  for (pass=0; pass<niter; pass++) {
    mycut = 0;
    for (c=0;c<2;++c) {
      dlthread_barrier(ctrl->comm);

      /* fill up my queue with my vertices */
      vw_pq_clear(q);
      for (i=0;i<bnd->size;++i) {
        k = vtx_iset_get(i,bnd);
        DL_ASSERT(k < mynvtxs,"Invalid border vertex %"PF_VTX_T,k);
        if (nbrinfo[k].nnbrs > 0) {
          /* only insert vertices with external neighbors */
          rgain = (1.0*nbrinfo[k].ed/sqrt(nbrinfo[k].nnbrs)) - nbrinfo[k].id;
          vw_pq_push(rgain,k,q);
        }
      }
      /* make moves */

      do {
        /* perform updates */
        while (update_combuffer_next(&up,combuffer)) {
          k = up.nbr;
          ewgt = up.ewgt;
          to = up.to;
          from = up.from;

          mycut += S_update_vertex(ctrl,k,to,from,ewgt,graph,kwinfo,q);
        }

        /* move a vertice */
        if (q->size > 0) {
          i = vw_pq_pop(q);

          myrinfo = kwinfo->nbrinfo+i;
          mynbrs = kwinfo_get_nbrs_ro(kwinfo,i, \
              dl_min(nparts,graph->xadj[myid][i+1]-graph->xadj[myid][i]));

          from = where[i];
          wgt = vwgt[i];

          if (myrinfo->id > 0 && lpwgts[from]-wgt < minwgt[from]) {
            continue;
          }

          /* find the first eligible partition */
          for (k=0;k<myrinfo->nnbrs; ++k) {
            to = mynbrs[k].pid;
            if (!S_right_side(c,to,from)) {
              continue;
            }
            if (lpwgts[to]+wgt <= maxwgt[to]) {
              if (mynbrs[k].ed >= myrinfo->id) {
                break;
              }
            }
          }
          if (k == myrinfo->nnbrs) {
            /* if there aren't any eligable partitions, abort */
            continue;
          }

          /* see if there is a better one from the eligable one */
          for (j=k+1; j<myrinfo->nnbrs; ++j) {
            to = mynbrs[j].pid;
            if (!S_right_side(c,to,from)) {
              continue;
            }
            if (mynbrs[j].ed >= mynbrs[k].ed) {
              gain = mynbrs[j].ed-myrinfo->id; 
              DL_ASSERT(gain >= 0, "Invalid gain of %"PF_WGT_T,gain);
              if ((gain > 0 && lpwgts[to]+wgt <= maxwgt[to]) \
                  || (mynbrs[j].ed == mynbrs[k].ed && \
                     tpwgts[mynbrs[k].pid]*lpwgts[to] < \
                     tpwgts[to]*lpwgts[mynbrs[k].pid])) {
                k = j;
              }
            }
          }
          to = mynbrs[k].pid;

          if (mynbrs[k].ed >= myrinfo->id) { 
            gain = mynbrs[k].ed-myrinfo->id;
            if (!(gain > 0 || (gain == 0 \
                      && (lpwgts[from] >= maxwgt[from]  \
                          || tpwgts[to]*lpwgts[from] > \
                          tpwgts[from]*(lpwgts[to]+wgt))))) {
              continue;
            }
          }

          if (lpwgts[to] + wgt > maxwgt[to] || 
              lpwgts[from] - wgt < minwgt[from]) {
            /* whatever you do, don't push the red button */
            continue;
          }

          /* make the move ***************************************************/
          ++nmoved;

          mycut += S_move_vertex(ctrl,graph,myid,i,to,kwinfo,lpwgts, \
              where,q,combuffer);
        } 
      } while ((q->size > 0 && vw_pq_top(q) >= 0) || \
          !update_combuffer_finish(combuffer));

      DL_ASSERT_EQUALS(update_combuffer_next(NULL,combuffer),0,"%d");

      update_combuffer_clear(combuffer);

      /* update my partition weights */
      S_par_sync_pwgts(myid,nparts,pwgts,lpwgts,ctrl->comm);

    } /* end directions */

    mycut = wgt_dlthread_sumreduce(mycut,ctrl->comm);

    par_vprintf(ctrl->verbosity,MTMETIS_VERBOSITY_HIGH, \
        "Refinement pass %zu: %"PF_WGT_T" improvement\n",pass,mycut);

    if (mycut == 0) {
      break;
    }

    if (myid == 0) {
      graph->mincut -= (mycut/2);
    }
  } /* end passes */

  nmoved = vtx_dlthread_sumreduce(nmoved,ctrl->comm);

  vw_pq_free(q);

  dl_free(minwgt);
  dl_free(maxwgt);
  dl_free(lpwgts);

  DL_ASSERT(check_kwinfo(kwinfo,graph,(pid_type const **)gwhere),"Bad kwinfo");
  DL_ASSERT(check_kwbnd(kwinfo->bnd,graph,1),"Bad boundary");
  DL_ASSERT(graph->mincut >= 0,"Invalid mincut of %"PF_WGT_T, \
      graph->mincut);
  DL_ASSERT_EQUALS(graph_cut(graph,(pid_type const**)gwhere), \
      graph->mincut,"%"PF_WGT_T);

  /* implicit barrier */
  update_combuffer_free(combuffer);

  return nmoved;
}


static vtx_type S_par_kwayrefine_HS(
    ctrl_type * const ctrl, 
    graph_type * const graph,
    size_t const niter, 
    kwinfo_type * const kwinfo)
{
  vtx_type c, i, k, nmoved, totalmoves, hs, h, l, lvtx, maxnhills;
  adj_type j;
  wgt_type gain, vwgt, mycut, ewgt, oldgain;
  pid_type to, from;
  tid_type nbrid;
  size_t pass;
  real_type rgain;
  wgt_type * lpwgts;
  kwnbrinfo_type * myrinfo;
  adjinfo_type * mynbrs;
  vtx_iset_t * bnd;
  vw_pq_t * q;
  vt_pq_t * qh;
  wgt_type * minwgt, * maxwgt;
  vtx_type * hlist;
  update_type up;
  move_type mv;
  update_combuffer_t * ucb;
  move_combuffer_t * mcb;
  kwinfo_type ** gnbrinfo;
  int ** hill;
  int ** traveled;
  wgt_type * con;
  vtx_type * moves;

  tid_type const myid = dlthread_get_id(ctrl->comm);
  tid_type const nthreads = dlthread_get_nthreads(ctrl->comm);

  /* Link the graph fields */
  vtx_type const * const gmynvtxs = graph->mynvtxs;
  wgt_type const * const * const gvwgt = (wgt_type const **)graph->vwgt;

  pid_type * const * const gwhere = graph->where;
  wgt_type * const pwgts = graph->pwgts;
  pid_type const nparts = ctrl->nparts;

  vtx_type const limit = ctrl->hillsize;
  
  real_type const * const tpwgts = ctrl->tpwgts;

  switch (ctrl->hs_stype) {
    case MTMETIS_HS_SCAN_SQRT:
      maxnhills = \
          dl_min(sqrt(kwinfo->bnd->size/nthreads),kwinfo->bnd->size*0.05);
      break;
    case MTMETIS_HS_SCAN_1PC:
      maxnhills = kwinfo->bnd->size*0.01;
      break;
    case MTMETIS_HS_SCAN_5PC:
      maxnhills = kwinfo->bnd->size*0.05;
      break;
    case MTMETIS_HS_SCAN_25PC:
      maxnhills = kwinfo->bnd->size*0.25;
      break;
    case MTMETIS_HS_SCAN_FULL:
      maxnhills = kwinfo->bnd->size;
      break;
    default:
      dl_error("Unknown scantype '%d'\n",ctrl->hs_stype);
  }

  ucb = update_combuffer_create(graph->mynedges[myid],ctrl->comm);
  mcb = move_combuffer_create(dl_min(graph->nvtxs, \
        gmynvtxs[myid]*limit),ctrl->comm);

  gnbrinfo = dlthread_get_shmem((sizeof(kwinfo_type*)*nthreads) + \
      (sizeof(int*)*nthreads)+(sizeof(int*)*nthreads),ctrl->comm);
  hill = (int**)(gnbrinfo+nthreads);
  traveled = (int**)(hill+nthreads);

  gnbrinfo[myid] = kwinfo;
  hill[myid] = int_init_alloc(0,gmynvtxs[myid]);
  traveled[myid] = int_init_alloc(-1,graph->mynedges[myid]);

  lpwgts = wgt_alloc(nparts);
  wgt_copy(lpwgts,pwgts,nparts);

  minwgt = wgt_alloc(nparts);
  maxwgt = wgt_alloc(nparts);

  hlist = vtx_alloc(limit);
  con = wgt_alloc(nparts);

  totalmoves = 0;

  bnd = kwinfo->bnd;

  moves = vtx_alloc(gmynvtxs[myid]);

  /* setup max/min partition weights */
  for (i=0;i<nparts;++i) {
    maxwgt[i]  = ctrl->tpwgts[i]*graph->tvwgt*ctrl->ubfactor;
    minwgt[i]  = ctrl->tpwgts[i]*graph->tvwgt*(1.0/ctrl->ubfactor);
  }

  DL_ASSERT(check_kwinfo(kwinfo,graph,(pid_type const **)gwhere),"Bad kwinfo");
  DL_ASSERT(check_kwbnd(kwinfo->bnd,graph,0),"Bad boundary");

  q = vw_pq_create(0,gmynvtxs[myid]); 
  qh = vt_pq_create(2*gmynvtxs[myid]);

  mycut = 0;
  totalmoves = 0;
  for (pass=0; pass<niter; pass++) {
    nmoved = 0;
    for (c=0;c<2;++c) {
      dlthread_barrier(ctrl->comm);

      /* fill up my queue with my vertices */
      vw_pq_clear(q);
      for (i=0;i<bnd->size;++i) {
        k = vtx_iset_get(i,bnd);
        DL_ASSERT(k < gmynvtxs[myid],"Invalid border vertex %"PF_VTX_T,k);
        myrinfo = kwinfo->nbrinfo + k;
        if (myrinfo->nnbrs > 0 && hill[myid][k] == 0) {
          /* only insert vertices with external neighbors */
          rgain = (myrinfo->ed/sqrt(myrinfo->nnbrs)) - myrinfo->id;
          vw_pq_push(rgain,k,q);
        }
      }
      /* make moves */

      l = 0;
      do {
        /* perform moves */
        while (move_combuffer_next(&mv,mcb)) {
          to = mv.to;
          i = mv.vtx;
          from = gwhere[myid][i];
          if (from != to) {
            if (vw_pq_contains(i,q)) {
              vw_pq_remove(i,q);
            }

            /* move the vertex */
            mycut += S_move_vertex(ctrl,graph,myid,i,to,kwinfo,lpwgts, \
                gwhere[myid],q,ucb);

            moves[nmoved++] = i;

            l = 0;
          }
        }

        /* perform updates */
        while (update_combuffer_next(&up,ucb)) {
          k = up.nbr;
          ewgt = up.ewgt;
          to = up.to;
          from = up.from;

          mycut += S_update_vertex(ctrl,k,to,from,ewgt,graph,kwinfo,q);
        }

        /* move a vertice */
        if (l < maxnhills && q->size > 0) {
          i = vw_pq_pop(q);

          myrinfo = kwinfo->nbrinfo+i;

          from = gwhere[myid][i];
          vwgt = gvwgt[myid][i];

          if (myrinfo->id > 0 && lpwgts[from]-vwgt < minwgt[from]) {
            continue;
          }

          mynbrs = kwinfo_get_nbrs(kwinfo,i, \
              dl_min(nparts,graph->xadj[myid][i+1]-graph->xadj[myid][i]));


          /* move normally if there is an eligable positive gain partition to
           * move to -- or build a hill and decide where to go from there */


          /* find the first eligible partition */
          oldgain = 0;
          for (k=0;k<myrinfo->nnbrs; ++k) {
            to = mynbrs[k].pid;
            if (!S_right_side(c,to,from)) {
              continue;
            }
            if (lpwgts[to]+vwgt <= maxwgt[to]) {
              oldgain = mynbrs[k].ed - myrinfo->id;
              break;
            }
          }
          if (k == myrinfo->nnbrs) {
            /* if there aren't any eligable partitions, abort */
            continue;
          }

          /* see if there is a better one from the eligable one */
          for (j=k+1; j<myrinfo->nnbrs; ++j) {
            to = mynbrs[j].pid;
            if (!S_right_side(c,to,from)) {
              continue;
            }
            gain = mynbrs[j].ed-myrinfo->id; 
            if ((gain > oldgain && lpwgts[to]+vwgt <= maxwgt[to]) \
                || (mynbrs[j].ed == mynbrs[k].ed && \
                   tpwgts[mynbrs[k].pid]*lpwgts[to] < \
                   tpwgts[to]*lpwgts[mynbrs[k].pid])) {
              k = j;
              oldgain = gain;
            }
          }
          to = mynbrs[k].pid;

          if (lpwgts[to] + vwgt > maxwgt[to] || 
              lpwgts[from] - vwgt < minwgt[from]) {
            /* whatever you do, don't push the red button */
            continue;
          }

          gain = mynbrs[k].ed-myrinfo->id; 

          if (gain > 0 || (gain == 0 && (lpwgts[from] >= maxwgt[from]  \
                          || tpwgts[to]*lpwgts[from] > \
                          tpwgts[from]*(lpwgts[to]+vwgt)))) {
            /* move the vertex by itself */
            hill[myid][i] = 1;
            moves[nmoved++] = i;

            mycut += S_move_vertex(ctrl,graph,myid,i,to,kwinfo,lpwgts, \
                gwhere[myid],q,ucb);

            l = 0;
          } else {
            ++l;

            /* explore the hill */
            if (q->size > 0) {
              gain = vw_pq_top(q);
            } else {
              gain = -graph->tadjwgt;
            }
            hs = S_build_hill(ctrl,graph,gain,minwgt,maxwgt,i, \
                (kwinfo_type const **)gnbrinfo,(pid_type const **)gwhere,lpwgts, \
                hill,traveled,pass,qh,hlist,con,&to); 

            if (hs > 0) {
              l = 0;
            }

            for (h=0;h<hs;++h) {
              k = hlist[h];
              lvtx = gvtx_to_lvtx(k,graph->dist);
              nbrid = gvtx_to_tid(k,graph->dist);
              if (nbrid == myid) {
                mycut += S_move_vertex(ctrl,graph,myid,lvtx,to,kwinfo,lpwgts, \
                    gwhere[myid],q,ucb);
                moves[nmoved++] = lvtx;
              } else {
                mv.to = to;
                mv.vtx = lvtx;

                move_combuffer_add(nbrid,mv,mcb);
              }
            }
          }
        } 
      } while ((l < maxnhills && q->size > 0) || \
          !move_combuffer_finish(mcb) || !update_combuffer_finish(ucb));

      move_combuffer_clear(mcb);
      update_combuffer_clear(ucb);

      /* update my partition weights */
      S_par_sync_pwgts(myid,nparts,pwgts,lpwgts,ctrl->comm);
    } /* end directions */

    /* flush my hill markings */
    for (h=0;h<nmoved;++h) {
      i = moves[h];
      hill[myid][i] = 0;
    }

    nmoved = vtx_dlthread_sumreduce(nmoved,ctrl->comm);

    par_vprintf(ctrl->verbosity,MTMETIS_VERBOSITY_HIGH, \
        "Refinement pass %zu: %"PF_VTX_T" moves\n",pass,nmoved);

    if (nmoved == 0) {
      break;
    }

    totalmoves += nmoved;
  } /* end passes */

  mycut = wgt_dlthread_sumreduce(mycut,ctrl->comm);

  if (myid == 0) { 
    /* update edgecut */
    graph->mincut -= (mycut/2);

    DL_ASSERT(graph->mincut >= 0,"Invalid mincut of %"PF_WGT_T, \
        graph->mincut);
    DL_ASSERT_EQUALS(graph_cut(graph,(pid_type const**)gwhere), \
        graph->mincut,"%"PF_WGT_T);
  }
  DL_ASSERT(check_kwinfo(kwinfo,graph,(pid_type const **)gwhere),"Bad kwinfo");

  vw_pq_free(q);
  vt_pq_free(qh);

  dl_free(minwgt);
  dl_free(maxwgt);
  dl_free(lpwgts);
  dl_free(hlist);
  dl_free(hill[myid]);
  dl_free(traveled[myid]);
  dl_free(con);

  DL_ASSERT(check_kwbnd(kwinfo->bnd,graph,0),"Bad boundary");

  /* implicit barrier */
  dlthread_free_shmem(gnbrinfo,ctrl->comm);
  move_combuffer_free(mcb);
  update_combuffer_free(ucb);

  return totalmoves;
}


static vtx_type S_par_kwayrefine_KPM(
    ctrl_type * const ctrl, 
    graph_type * const graph,
    size_t const niter, 
    kwinfo_type * const kwinfo)
{
  size_t pass;
  vtx_type i, v, nmoves, k;
  pid_type side, other, offset, p, d, to, from;
  wgt_type ewgt;
  vtx_type * bnds, * bndptr, * obndptr, * gbndptr;
  wgt_type * maxwgt, * minwgt;
  kwinfo_type ** gkwinfo;
  kwnbrinfo_type * myrinfo;
  adjinfo_type * mynbrs;
  vtx_mset_t * pbnd;
  update_type up;
  update_combuffer_t * cb;

  tid_type const myid = dlthread_get_id(ctrl->comm);
  tid_type const nthreads = dlthread_get_nthreads(ctrl->comm);

  pid_type const nparts = ctrl->nparts;
  vtx_iset_t * const bnd = kwinfo->bnd;

  tid_type const mynvtxs = graph->mynvtxs[myid];
  pid_type * const where = graph->where[myid];

  /* sizing this is problematic for partition pairs, but for the vast majority
   * of cases it should be plenty big. If I start getting mysterious segfaults
   * for large numbers of threads, this is a good candidate. */
  cb = update_combuffer_create(
      4*dl_max(graph->mynedges[myid],2.0*graph->nedges/nthreads),ctrl->comm);

  pbnd = vtx_mset_create(0,graph->gnvtxs, \
      (ctrl->ubfactor*3.0*graph->nvtxs)/nparts,ctrl->comm);

  minwgt = wgt_alloc(nparts);
  maxwgt = wgt_alloc(nparts);

  /* setup max/min partition weights */
  for (side=0;side<nparts;++side) {
    maxwgt[side]  = ctrl->tpwgts[side]*graph->tvwgt*ctrl->ubfactor;
    minwgt[side]  = ctrl->tpwgts[side]*graph->tvwgt*(1.0/ctrl->ubfactor);
  }

  /* allocate memory for partition boundaries */
  bnds = dlthread_get_shmem((sizeof(vtx_type)*graph->nvtxs) + \
      (sizeof(vtx_type)*(nparts+1)) + \
      (sizeof(kwinfo_type*)*nthreads),ctrl->comm);
  gbndptr = (vtx_type*)(bnds+graph->nvtxs);
  gkwinfo = (kwinfo_type**)(gbndptr+(nparts+1));

  gkwinfo[myid] = kwinfo;
  bndptr = vtx_alloc(nparts+1);
  obndptr = vtx_alloc(nparts+1);

  /* go through each possible pair of partitions */
  nmoves = 0;
  /* do half the passes here, and two for each pair */
  for (pass=0;pass<ctrl->nrefpass/2;++pass) {
    for (offset=1;offset<nparts/2;++offset) {
      for (d=0;d<2;++d) {
        vtx_set(bndptr,0,nparts+1);

        /* count boundary vertices for seeding */
        for (i=0;i<bnd->size;++i) {
          v = vtx_iset_get(i,bnd);
          side = where[v];

          other = S_partner(side,offset,nparts,d);

          myrinfo = kwinfo->nbrinfo + v;
          mynbrs = kwinfo_get_nbrs(kwinfo,v, \
              dl_min(nparts,graph->xadj[myid][v+1]-graph->xadj[myid][v]));

          for (p=0;p<myrinfo->nnbrs;++p) {
            if (mynbrs[p].pid == other) {
              ++bndptr[side];
              break;
            }
          }
        }

        /* build boundary for seeding */
        vtx_dlthread_prefixsum(bndptr,nparts+1,gbndptr,ctrl->comm);
        vtx_copy(obndptr,bndptr,nparts+1);
        for (i=0;i<bnd->size;++i) {
          v = vtx_iset_get(i,bnd);
          side = where[v];

          other = S_partner(side,offset,nparts,d);

          myrinfo = kwinfo->nbrinfo + v;
          mynbrs = kwinfo_get_nbrs(kwinfo,v, \
              dl_min(nparts,graph->xadj[myid][v+1]-graph->xadj[myid][v]));
          for (p=0;p<myrinfo->nnbrs;++p) {
            if (mynbrs[p].pid == other) {
              bnds[obndptr[side]++] = lvtx_to_gvtx(v,myid,graph->dist);
              break;
            }
          }
        }
        dlthread_barrier(ctrl->comm);

        /* perform fm */
        for (side=myid;side<nparts;side+=nthreads) {
          other = S_partner(side,offset,nparts,d);

          /* insert vertices into the boundary */
          if (side < other && (other < nparts)) {
            /* for some combinations some partitions aren't included */
            for (i=gbndptr[side];i<gbndptr[side+1];++i) {
              DL_ASSERT_EQUALS(graph->where[gvtx_to_tid(bnds[i],graph->dist)] \
                  [gvtx_to_lvtx(bnds[i],graph->dist)],side,"%"PF_PID_T);
              vtx_mset_add(bnds[i],pbnd);
            }
            for (i=gbndptr[other];i<gbndptr[other+1];++i) {
              DL_ASSERT_EQUALS(graph->where[gvtx_to_tid(bnds[i],graph->dist)] \
                  [gvtx_to_lvtx(bnds[i],graph->dist)],other,"%"PF_PID_T);
              vtx_mset_add(bnds[i],pbnd);
            }

            nmoves += S_pfm(ctrl,graph,gkwinfo,maxwgt,2,side, \
                other,pbnd,cb);

            vtx_mset_clear(pbnd);
          }
        }
        dlthread_barrier(ctrl->comm);
        
        /* perform updates */
        while (update_combuffer_next(&up,cb)) {
          k = up.nbr;
          ewgt = up.ewgt;
          to = up.to;
          from = up.from;

          /* this updates won't affect the cut */
          (void)S_update_vertex(ctrl,k,to,from,ewgt,graph,kwinfo,NULL);
        }
        update_combuffer_finish(cb);
        update_combuffer_clear(cb);

        /* re-scan my vertices and update my boundary */
        vtx_iset_clear(bnd);
        for (i=0;i<mynvtxs;++i) { 
          myrinfo = kwinfo->nbrinfo + i; 
          /* will need to figure how to not scan all vertices */
          if (is_bnd(myrinfo->id,myrinfo->ed,0)) {
            vtx_iset_add(i,bnd);
          }
        }

        dlthread_barrier(ctrl->comm);
      }
    }
  }

  vtx_mset_free(pbnd);

  dl_free(bndptr);
  dl_free(obndptr);
  dl_free(minwgt);
  dl_free(maxwgt);

  nmoves = vtx_dlthread_sumreduce(nmoves,ctrl->comm);
  update_combuffer_free(cb);
  dlthread_free_shmem(bnds,ctrl->comm);

  return nmoves;
}




/******************************************************************************
* PUBLIC PARALLEL FUNCTIONS ***************************************************
******************************************************************************/


vtx_type par_kwayrefine(
    ctrl_type * const ctrl,
    graph_type * const graph,
    kwinfo_type * const kwinfo)
{
  vtx_type nmoves; 

  nmoves = 0;

  switch (ctrl->rtype) {
    case MTMETIS_RTYPE_GREEDY:
      nmoves = S_par_kwayrefine_GREEDY(ctrl,graph,ctrl->nrefpass,kwinfo);
      break;
    case MTMETIS_RTYPE_HS:
      nmoves = S_par_kwayrefine_HS(ctrl,graph,ctrl->nrefpass,kwinfo);
      break;
    case MTMETIS_RTYPE_FM:
      /* use KPM version of FM */
      nmoves = S_par_kwayrefine_KPM(ctrl,graph,ctrl->nrefpass,kwinfo);
      break;
    default:
      dl_error("Unsupported refinement type '%d' for K-Way partitions.", \
          ctrl->rtype);
  }

  par_vprintf(ctrl->verbosity,MTMETIS_VERBOSITY_HIGH,"%zu) [%"PF_VTX_T" %" \
      PF_ADJ_T"] {%"PF_WGT_T" %"PF_VTX_T"}\n",graph->level,graph->nvtxs, \
      graph->nedges,graph->mincut,nmoves);

  return nmoves;
}




#endif
