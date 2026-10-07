/**
 * @file contract.c
 * @brief Functions for performing contraction
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright 2014, Regents of the University of Minnesota
 * @version 1
 * @date 2015-01-21
 */




#ifndef MTMETIS_CONTACT_C
#define MTMETIS_CONTACT_C




#include "contract.h"
#include "check.h"




/******************************************************************************
* TYPES ***********************************************************************
******************************************************************************/


typedef struct edge_type {
  vtx_type dst;
  wgt_type wgt;
} edge_type;




/******************************************************************************
* CONSTANTS *******************************************************************
******************************************************************************/


#define DEF_MASK_SIZE (0x2000)
static uint32_t const MASK_SIZE = DEF_MASK_SIZE;
static uint32_t const MASK = DEF_MASK_SIZE-1;
static vtx_type const MASK_MAX_DEG = DEF_MASK_SIZE >> 3;




/******************************************************************************
* DOMLIB IMPORTS **************************************************************
******************************************************************************/


#define DLSORT_PREFIX edge
#define DLSORT_TYPE_T edge_type
#define DLSORT_COMPARE(a,b) ((a).dst < (b).dst)
#define DLSORT_STATIC
#include "dlsort_headers.h"
#undef DLSORT_STATIC
#undef DLSORT_COMPARE
#undef DLSORT_TYPE_T
#undef DLSORT_PREFIX






/******************************************************************************
* INLINE FUNCTIONS ************************************************************
******************************************************************************/


/**
 * @brief Reverse the bits of a key for a given mask. Use for hashing into a
 * secondary hash table to prevent collisions.
 *
 * @param n The key to reverse.
 * @param mask The mask of the bits to be reversed.
 *
 * @return The reversed key.
 */
static inline vtx_type S_reverse(
    vtx_type const n, 
    vtx_type const mask)
{
  vtx_type r = vtx_reversebits(n);
  int const mb = vtx_downlog2(mask);
  int const vs = sizeof(vtx_type)*8;
  if (vs >= 2*mb) {
    return (r >> (vs - (2*mb))) & mask;
  } else {
    return r >> (vs - mb);
  }
}




/******************************************************************************
* PRIVATE FUNCTIONS ***********************************************************
******************************************************************************/


/**
 * @brief Adjust the coarse vertex map given new graph distribution paramters. 
 *
 * @param cmap The coarse vertex map.
 * @param mynvtxs The number of vertices this thread owns.
 * @param olddist The old graph distribution parameters.
 * @param newdist The new graph distribution parameters.
 */
static void S_adjust_cmap(
    vtx_type * const cmap, 
    vtx_type const mynvtxs, 
    graphdist_type const olddist, 
    graphdist_type const newdist)
{
  vtx_type i,k;
  tid_type o;

  for (i=0;i<mynvtxs;++i) {
    if (cmap[i] >= olddist.offset) { /* remote vertex */
      k = gvtx_to_lvtx(cmap[i],olddist);
      o = gvtx_to_tid(cmap[i],olddist);
      cmap[i] = lvtx_to_gvtx(k,o,newdist);
    }
  }
}


/**
 * @brief Perform contraction using a dense vector.
 *
 * @param ctrl The control structure.
 * @param graph The graph structure.
 * @param mycnvtxs The number of coarse vertices owned by this thread.
 * @param gmatch The global match array.
 * @param fcmap The first fine vertex for each coarse vertex.
 */
static void S_par_contract_DENSE(
    ctrl_type * const ctrl, 
    graph_type * const graph, 
    vtx_type const mycnvtxs, 
    vtx_type const * const * const gmatch, 
    vtx_type const * const fcmap)
{
  adj_type cnedges, l, maxdeg, j, i;
  tid_type o, t;
  vtx_type v, c, cg, k;
  wgt_type ewgt;
  adj_type * table;
  graph_type * cgraph;
  graphdist_type dist;

  tid_type const myid = dlthread_get_id(ctrl->comm);
  tid_type const nthreads = dlthread_get_nthreads(ctrl->comm);

  /* make accessing my old graph easy */
  vtx_type const mynvtxs = graph->mynvtxs[myid];
  adj_type const * const * const gxadj = (adj_type const * const *)graph->xadj;
  vtx_type const * const * const gadjncy = (vtx_type const * const *)graph->adjncy;
  wgt_type const * const * const gvwgt = (wgt_type const * const *)graph->vwgt;
  wgt_type const * const * const gadjwgt = (wgt_type const * const *)graph->adjwgt;

  vtx_type const * const * const gcmap = (vtx_type const **)graph->cmap;

  if (myid == 0) {
    dl_start_timer(&(ctrl->timers.contraction));
  }

  cgraph = par_graph_setup_coarse(graph,mycnvtxs);

  dist = cgraph->dist;

  S_adjust_cmap(graph->cmap[myid],mynvtxs,graph->dist,dist);

  /* count possible edges */
  cnedges = 0;
  maxdeg = 0;
  for (c=0;c<mycnvtxs;++c) {
    v = fcmap[c];
    o = myid;
    l = 0;
    do {
      l += gxadj[o][v+1] - gxadj[o][v];
      v = gmatch[o][v];
      if (v >= graph->mynvtxs[o]) {
        o = gvtx_to_tid(v,graph->dist);
        v = gvtx_to_lvtx(v,graph->dist);
      }
    } while (!(o == myid && v == fcmap[c]));
    dl_storemax(maxdeg,l);
    cnedges += l;
  }

  adj_type * const mycxadj = cgraph->xadj[myid];
  vtx_type * const mycadjncy = cgraph->adjncy[myid] = vtx_alloc(cnedges);
  wgt_type * const mycvwgt = cgraph->vwgt[myid];
  wgt_type * const mycadjwgt = cgraph->adjwgt[myid] = wgt_alloc(cnedges);

  table = NULL;

  table = adj_init_alloc(NULL_ADJ,graph->gnvtxs);

  cnedges = 0;
  mycxadj[0] = 0;

  dlthread_barrier(ctrl->comm);

  /* set max degree for the coarse graph */
  for (c=0;c<mycnvtxs;++c) {
    cg = lvtx_to_gvtx(c,myid,dist);
    /* initialize the coarse vertex */
    mycvwgt[c] = 0;

    v = fcmap[c];
    o = myid;
    DL_ASSERT_EQUALS(myid,gvtx_to_tid(lvtx_to_gvtx(v,myid,graph->dist),
        graph->dist),"%"PF_TID_T);
    do { 
      DL_ASSERT_EQUALS(c,gvtx_to_lvtx(gcmap[o][v],dist),"%"PF_VTX_T);

      /* transfer over vertex stuff from v and u */
      mycvwgt[c] += gvwgt[o][v];

      for (j=gxadj[o][v];j<gxadj[o][v+1];++j) {
        k = gadjncy[o][j];
        if (k < graph->mynvtxs[o]) {
          t = o;
        } else {
          t = gvtx_to_tid(k,graph->dist);
          k = gvtx_to_lvtx(k,graph->dist);
        }
        k = gcmap[t][k];
        if (gvtx_to_tid(k,dist) == myid) {
          k = gvtx_to_lvtx(k,dist);
        }
        if (k == c || k == cg) {
          /* internal edge */
        } else {
          /* external edge */
          i = table[k];
          ewgt = graph->uniformadjwgt ? 1 : gadjwgt[o][j];
          if (i == NULL_ADJ) {
            /* new edge */
            mycadjncy[cnedges] = k;
            mycadjwgt[cnedges] = ewgt;
            table[k] = cnedges++; 
          } else {
            /* duplicate edge */
            mycadjwgt[i] += ewgt;
          }
        }
      }

      v = gmatch[o][v];
      if (v >= graph->mynvtxs[o]) {
        o = gvtx_to_tid(v,graph->dist);
        v = gvtx_to_lvtx(v,graph->dist);
      }
    } while (!(myid == o && v == fcmap[c]));

    /* clear the table */
    for (j = cnedges;j > mycxadj[c];) {
      --j;
      k = mycadjncy[j];
      table[k] = NULL_ADJ;
    }

    mycxadj[c+1] = cnedges;
  }

  dl_free(table);

  cgraph->mynedges[myid] = cnedges;

  //graph_readjust_memory(cgraph,adjsize);

  dlthread_barrier(ctrl->comm);
  if (myid == 0) {
    cgraph->nedges = adj_sum(cgraph->mynedges,nthreads);
  }

  par_graph_setup_twgts(cgraph);
  
  if (myid == 0) {
    dl_stop_timer(&(ctrl->timers.contraction));
  }

  DL_ASSERT(check_graph(cgraph) == 1, "Bad graph generated in coarsening\n");
}


/**
 * @brief Perform contraction using a single hash table, performing a linear
 * scan on the edge list in the case of a collsion.
 *
 * @param ctrl The control structure.
 * @param graph The graph structure.
 * @param mycnvtxs The number of coarse vertices owned by this thread.
 * @param gmatch The global match array.
 * @param fcmap The first fine vertex for each coarse vertex.
 */
static void S_par_contract_CLS(
    ctrl_type * const ctrl, 
    graph_type * const graph, 
    vtx_type const mycnvtxs, 
    vtx_type const * const * const gmatch, 
    vtx_type const * const fcmap)
{
  adj_type cnedges, l, maxdeg, j, i, jj, start;
  tid_type o, t;
  vtx_type v, c, cg, k;
  wgt_type ewgt;
  graph_type * cgraph;
  graphdist_type dist;
  offset_type * htable;

  tid_type const myid = dlthread_get_id(ctrl->comm);
  tid_type const nthreads = dlthread_get_nthreads(ctrl->comm);

  /* make accessing my old graph easy */
  vtx_type const mynvtxs = graph->mynvtxs[myid];
  adj_type const * const * const gxadj = (adj_type const * const *)graph->xadj;
  vtx_type const * const * const gadjncy = (vtx_type const * const *)graph->adjncy;
  wgt_type const * const * const gvwgt = (wgt_type const * const *)graph->vwgt;
  wgt_type const * const * const gadjwgt = (wgt_type const * const *)graph->adjwgt;

  vtx_type const * const * const gcmap = (vtx_type const **)graph->cmap;

  /* count possible edges */
  cnedges = 0;
  maxdeg = 0;
  for (c=0;c<mycnvtxs;++c) {
    v = fcmap[c];
    o = myid;
    l = 0;
    do {
      l += gxadj[o][v+1] - gxadj[o][v];
      v = gmatch[o][v];
      if (v >= graph->mynvtxs[o]) {
        o = gvtx_to_tid(v,graph->dist);
        v = gvtx_to_lvtx(v,graph->dist);
      }
    } while (!(o == myid && v == fcmap[c]));
    dl_storemax(maxdeg,l);
    cnedges += l;
  }

  if (maxdeg > MASK_MAX_DEG) {
    S_par_contract_DENSE(ctrl,graph,mycnvtxs,gmatch,fcmap);
    return;
  }

  if (myid == 0) {
    dl_start_timer(&(ctrl->timers.contraction));
  }

  cgraph = par_graph_setup_coarse(graph,mycnvtxs);

  dist = cgraph->dist;

  S_adjust_cmap(graph->cmap[myid],mynvtxs,graph->dist,dist);

  adj_type * const mycxadj = cgraph->xadj[myid];
  vtx_type * const mycadjncy = cgraph->adjncy[myid] = vtx_alloc(cnedges);
  wgt_type * const mycvwgt = cgraph->vwgt[myid];
  wgt_type * const mycadjwgt = cgraph->adjwgt[myid] = wgt_alloc(cnedges);

  htable = offset_init_alloc(NULL_OFFSET,MASK_SIZE);

  cnedges = 0;
  mycxadj[0] = 0;

  dlthread_barrier(ctrl->comm);

  /* set max degree for the coarse graph */
  for (c=0;c<mycnvtxs;++c) {
    cg = lvtx_to_gvtx(c,myid,dist);
    /* initialize the coarse vertex */
    mycvwgt[c] = 0;

    v = fcmap[c];
    o = myid;
    DL_ASSERT_EQUALS(myid,gvtx_to_tid(lvtx_to_gvtx(v,myid,graph->dist),
        graph->dist),"%"PF_TID_T);
    start = cnedges;
    do {
      DL_ASSERT_EQUALS(c,gvtx_to_lvtx(gcmap[o][v],dist),"%"PF_VTX_T);

      /* transfer over vertex stuff from v and u */
      mycvwgt[c] += graph->uniformvwgt ? 1 : gvwgt[o][v];

      for (j=gxadj[o][v];j<gxadj[o][v+1];++j) {
        k = gadjncy[o][j];
        if (k < graph->mynvtxs[o]) {
          t = o;
        } else {
          t = gvtx_to_tid(k,graph->dist);
          k = gvtx_to_lvtx(k,graph->dist);
        }
        k = gcmap[t][k];
        if (gvtx_to_tid(k,dist) == myid) {
          k = gvtx_to_lvtx(k,dist);
        }
        if (k == c || k == cg) {
          /* internal edge */
        } else {
          /* external edge */
          l = k&MASK;
          i = htable[l];
          ewgt = graph->uniformadjwgt ? 1 : gadjwgt[o][j];
          if (i == NULL_OFFSET) {
            /* new edge */
            mycadjncy[cnedges] = k;
            mycadjwgt[cnedges] = ewgt;
            htable[l] = (offset_type)(cnedges - start); 
            ++cnedges;
          } else {
            i += start;
            /* search for existing edge */
            for (jj=i;jj<cnedges;++jj) {
              if (mycadjncy[jj] == k) {
                mycadjwgt[jj] += ewgt;
                break;
              }
            }
            if (jj == cnedges) {
              /* we didn't find the edge, so add it */
              mycadjncy[cnedges] = k;
              mycadjwgt[cnedges++] = ewgt;
            }
          }
        }
      }

      v = gmatch[o][v];
      if (v >= graph->mynvtxs[o]) {
        o = gvtx_to_tid(v,graph->dist);
        v = gvtx_to_lvtx(v,graph->dist);
      }
    } while (!(myid == o && v == fcmap[c]));

    /* clear the htable */
    for (j = cnedges;j > mycxadj[c];) {
      --j;
      k = mycadjncy[j];
      l = (k&MASK);
      htable[l] = NULL_OFFSET;
    }

    mycxadj[c+1] = cnedges;
  }

  dl_free(htable);

  cgraph->mynedges[myid] = cnedges;

  //graph_readjust_memory(cgraph,adjsize);

  dlthread_barrier(ctrl->comm);
  if (myid == 0) {
    cgraph->nedges = adj_sum(cgraph->mynedges,nthreads);
  }

  par_graph_setup_twgts(cgraph);
  
  if (myid == 0) {
    dl_stop_timer(&(ctrl->timers.contraction));
  }

  DL_ASSERT(check_graph(cgraph) == 1, "Bad graph generated in coarsening\n");
}


/**
 * @brief Perform contraction by sorting and merging lists.
 *
 * @param ctrl The control structure.
 * @param graph The graph structure.
 * @param mycnvtxs The number of coarse vertices owned by this thread.
 * @param gmatch The global match array.
 * @param fcmap The first fine vertex for each coarse vertex.
 */
static void S_par_contract_SORT(
    ctrl_type * const ctrl, 
    graph_type * const graph, 
    vtx_type const mycnvtxs, 
    vtx_type const * const * const gmatch, 
    vtx_type const * const fcmap)
{
  adj_type cnedges, maxdeg, j, l;
  tid_type o, t;
  vtx_type v, c, cg, k, nlst;
  graph_type * cgraph;
  graphdist_type dist;
  edge_type * lst;

  tid_type const myid = dlthread_get_id(ctrl->comm);
  tid_type const nthreads = dlthread_get_nthreads(ctrl->comm);

  /* make accessing my old graph easy */
  vtx_type const mynvtxs = graph->mynvtxs[myid];
  adj_type const * const * const gxadj = (adj_type const * const *)graph->xadj;
  vtx_type const * const * const gadjncy = (vtx_type const * const *)graph->adjncy;
  wgt_type const * const * const gvwgt = (wgt_type const * const *)graph->vwgt;
  wgt_type const * const * const gadjwgt = (wgt_type const * const *)graph->adjwgt;

  vtx_type const * const * const gcmap = (vtx_type const **)graph->cmap;

  if (myid == 0) {
    dl_start_timer(&(ctrl->timers.contraction));
  }

  cgraph = par_graph_setup_coarse(graph,mycnvtxs);

  dist = cgraph->dist;

  S_adjust_cmap(graph->cmap[myid],mynvtxs,graph->dist,dist);

  /* count possible edges */
  cnedges = 0;
  maxdeg = 0;
  for (c=0;c<mycnvtxs;++c) {
    v = fcmap[c];
    o = myid;
    l = 0;
    do {
      l += gxadj[o][v+1] - gxadj[o][v];
      v = gmatch[o][v];
      if (v >= graph->mynvtxs[o]) {
        o = gvtx_to_tid(v,graph->dist);
        v = gvtx_to_lvtx(v,graph->dist);
      }
    } while (!(o == myid && v == fcmap[c]));
    dl_storemax(maxdeg,l);
    cnedges += l;
  }

  adj_type * const mycxadj = cgraph->xadj[myid];
  vtx_type * const mycadjncy = cgraph->adjncy[myid] = vtx_alloc(cnedges);
  wgt_type * const mycvwgt = cgraph->vwgt[myid];
  wgt_type * const mycadjwgt = cgraph->adjwgt[myid] = wgt_alloc(cnedges);

  lst = malloc(sizeof(edge_type)*maxdeg);

  cnedges = 0;
  mycxadj[0] = 0;

  dlthread_barrier(ctrl->comm);

  /* set max degree for the coarse graph */
  for (c=0;c<mycnvtxs;++c) {
    cg = lvtx_to_gvtx(c,myid,dist);
    /* initialize the coarse vertex */
    mycvwgt[c] = 0;

    v = fcmap[c];
    o = myid;
    nlst = 0;
    DL_ASSERT_EQUALS(myid,gvtx_to_tid(lvtx_to_gvtx(v,myid,graph->dist),
        graph->dist),"%"PF_TID_T);
    do { 
      DL_ASSERT_EQUALS(c,gvtx_to_lvtx(gcmap[o][v],dist),"%"PF_VTX_T);

      /* transfer over vertex stuff from v and u */
      mycvwgt[c] += gvwgt[o][v];

      /* add coarse edges it list */
      for (j=gxadj[o][v];j<gxadj[o][v+1];++j) {
        k = gadjncy[o][j];
        if (k < graph->mynvtxs[o]) {
          t = o;
        } else {
          t = gvtx_to_tid(k,graph->dist);
          k = gvtx_to_lvtx(k,graph->dist);
        }
        k = gcmap[t][k];
        if (gvtx_to_tid(k,dist) == myid) {
          k = gvtx_to_lvtx(k,dist);
        }
        if (k == c || k == cg) {
          /* internal edge -- ignore */
        } else {
          lst[nlst].dst = k;
          lst[nlst].wgt = gadjwgt[o][j];
          ++nlst;
        }
      }

      v = gmatch[o][v];
      if (v >= graph->mynvtxs[o]) {
        o = gvtx_to_tid(v,graph->dist);
        v = gvtx_to_lvtx(v,graph->dist);
      }
    } while (!(myid == o && v == fcmap[c]));

    if (nlst > 0) {
      /* sort and process edges */
      edge_quicksort(lst,nlst);

      /* add first edge */
      --nlst;
      mycadjncy[cnedges] = lst[nlst].dst;
      mycadjwgt[cnedges] = lst[nlst].wgt;
      ++cnedges;

      /* process the rest */
      while (nlst > 0) {
        --nlst;
        if (mycadjncy[cnedges-1] == lst[nlst].dst) {
          /* combine edges */
          mycadjwgt[cnedges-1] += lst[nlst].wgt;
        } else {
          /* add new edge */
          mycadjncy[cnedges] = lst[nlst].dst;
          mycadjwgt[cnedges] = lst[nlst].wgt;
          ++cnedges;
        }
      }
    }

    mycxadj[c+1] = cnedges;
  }

  dl_free(lst);

  cgraph->mynedges[myid] = cnedges;

  //graph_readjust_memory(cgraph,adjsize);

  dlthread_barrier(ctrl->comm);
  if (myid == 0) {
    cgraph->nedges = adj_sum(cgraph->mynedges,nthreads);
  }

  par_graph_setup_twgts(cgraph);
  
  if (myid == 0) {
    dl_stop_timer(&(ctrl->timers.contraction));
  }

  DL_ASSERT(check_graph(cgraph) == 1, "Bad graph generated in coarsening\n");
}




/******************************************************************************
* PUBLIC FUNCTIONS ************************************************************
******************************************************************************/


void par_contract_graph(
    ctrl_type * const ctrl, 
    graph_type * const graph, 
    vtx_type const mycnvtxs, 
    vtx_type const * const * const gmatch, 
    vtx_type const * const fcmap)
{
  switch (ctrl->contype) {
    case MTMETIS_CONTYPE_CLS:
      S_par_contract_CLS(ctrl,graph,mycnvtxs,gmatch,fcmap);
      break;
    case MTMETIS_CONTYPE_DENSE:
      S_par_contract_DENSE(ctrl,graph,mycnvtxs,gmatch,fcmap);
      break;
    case MTMETIS_CONTYPE_SORT:
      S_par_contract_SORT(ctrl,graph,mycnvtxs,gmatch,fcmap);
      break;
    default:
      dl_error("Unknown contraction type '%d'\n",ctrl->contype);
  }
}




#endif
