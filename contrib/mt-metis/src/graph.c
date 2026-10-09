/**
* @file graph.c
* @brief routine for handling dgraphs
* @author Dominique LaSalle <lasalle@cs.umn.edu>
* @copyright 2014, Regents of the University of Minnesota
* @version 1
* @date 2012-06-12
*/




#ifndef MTMETIS_GRAPH_C
#define MTMETIS_GRAPH_C




#include "graph.h"
#include "check.h"





/******************************************************************************
* PRIVATE TYPES ***************************************************************
******************************************************************************/


typedef struct gau_ptrs_type {
  adj_type * xadj;
  vtx_type * adjncy;
  wgt_type * vwgt;
  wgt_type * adjwgt;
  vtx_type * prefix;
  adj_type * nedges;
} gau_ptrs_type;




/******************************************************************************
* DOMLIB IMPORTS **************************************************************
******************************************************************************/


#define DLPQ_PREFIX vv
#define DLPQ_KEY_T vtx_type
#define DLPQ_VAL_T vtx_type
#define DLPQ_MIN 1
#define DLPQ_STATIC
#include "dlpq_headers.h"
#undef DLPQ_STATIC
#undef DLPQ_MIN
#undef DLPQ_KEY_T
#undef DLPQ_VAL_T
#undef DLPQ_PREFIX


#define DLSORT_PREFIX adj
#define DLSORT_TYPE_T adj_type
#define DLSORT_STATIC
#include "dlsort_headers.h"
#undef DLSORT_STATIC
#undef DLSORT_TYPE_T
#undef DLSORT_PREFIX




/******************************************************************************
* CONSTANTS *******************************************************************
******************************************************************************/


/* if we can get a 1 percent increase in our balance constraint, it is probably
 * worth it */
static double const MIN_ISLAND_WEIGHT = 0.01;




/******************************************************************************
* PRIVATE FUNCTIONS ***********************************************************
******************************************************************************/


/**
 * @brief Allocate the structures for a unified graph (from a distributed one).
 *
 * @param graph The distributed graph.
 * @param r_uxadj A reference to the unified adjacency list pointer.
 * @param r_uadjncy A reference to the unified adjacecny indexes.
 * @param r_uvwgt A reference to the unified vertex weights.
 * @param r_uadjwgt A reference to the unified edges weights.
 * @param r_uprefix A reference to the prefix sum of vertices (per thread).
 * @param r_unedges A reference to the prefix sum of edges (per thread).
 */
static void S_par_graph_alloc_unified(
    graph_type const * const graph,
    adj_type ** const r_uxadj,
    vtx_type ** const r_uadjncy,
    wgt_type ** const r_uvwgt,
    wgt_type ** const r_uadjwgt,
    vtx_type ** const r_uprefix,
    adj_type ** const r_unedges)
{
  tid_type t;
  gau_ptrs_type * ptr;

  tid_type const myid = dlthread_get_id(graph->comm);
  tid_type const nthreads = dlthread_get_nthreads(graph->comm);

  ptr = dlthread_get_shmem(sizeof(gau_ptrs_type),graph->comm);
  if (myid == 0) {
    ptr->xadj = adj_alloc(graph->nvtxs+1); 
    ptr->adjncy = vtx_alloc(graph->nedges); 
    ptr->vwgt = wgt_alloc(graph->nvtxs); 
    ptr->adjwgt = wgt_alloc(graph->nedges);
    ptr->prefix = vtx_alloc(nthreads+1);
    ptr->nedges = adj_alloc(nthreads+1);

    /* create a prefix sum for placing vertices */
    ptr->prefix[0] = 0;
    for (t=0;t<nthreads;++t) {
      ptr->prefix[t+1] = ptr->prefix[t] + graph->mynvtxs[t];
    }
    /* create a prefix sptr->m for placing edges */
    ptr->nedges[0] = 0;
    for (t=0;t<nthreads;++t) {
      ptr->nedges[t+1] = ptr->nedges[t] + graph->mynedges[t];
    }
    /* cap the xadj array */
    ptr->xadj[graph->nvtxs] = graph->nedges;
  }
  dlthread_barrier(graph->comm);

  *r_uxadj = ptr->xadj; 
  *r_uadjncy = ptr->adjncy; 
  *r_uvwgt = ptr->vwgt; 
  *r_uadjwgt = ptr->adjwgt; 
  *r_uprefix = ptr->prefix; 
  *r_unedges = ptr->nedges; 

  dlthread_barrier(graph->comm);
  dlthread_free_shmem(ptr,graph->comm);
}


/**
 * @brief Free the part of the graph that thread 'myid' owns.
 *
 * @param graph The graph.
 * @param myid The thread id.
 */
static void S_graph_free_part(
    graph_type * const graph,
    tid_type const myid)
{
  /* free graph structure */
  if (graph->free_xadj) {
    dl_free(graph->xadj[myid]);
  }
  if (graph->free_vwgt) { 
    dl_free(graph->vwgt[myid]);
  }
  if (graph->free_adjncy) {
    dl_free(graph->adjncy[myid]);
  }
  if (graph->free_adjwgt) {
    dl_free(graph->adjwgt[myid]);
  }

  /* free auxillery things */
  if (graph->label) {
    dl_free(graph->label[myid]);
  }
  if (graph->group) {
    dl_free(graph->group[myid]);
  }
}


/**
 * @brief Distribute the vertices of a graph in continigous blocks. 
 *
 * @param nvtxs The number of vertices.
 * @param xadj The adjacecny list pointer.
 * @param nthreads The number of threads to distribute the vertices over.
 * @param mynvtxs The number of vertices owned by each thread.
 * @param mynedges The number of edges owned by each thread.
 * @param lvtx The local vertex numbers.
 * @param owner The array assigning vertices to threads.
 */
static void S_distribute_block(
    vtx_type const nvtxs,
    adj_type const * const xadj,
    tid_type const nthreads,
    vtx_type * const mynvtxs,
    adj_type * const mynedges,
    vtx_type * const lvtx,
    tid_type * const owner)
{
  vtx_type v;
  tid_type myid;
  adj_type j, nedgesleft;

  adj_type const nedges = xadj[nvtxs];
  adj_type const avgnedges = nedges / nthreads;

  /* distribute vertices based on edge count */
  nedgesleft = nedges;
  myid = 0;
  for (v =0;v<nvtxs;++v) {
    if ((nthreads-myid-1)*avgnedges > nedgesleft) {
      ++myid;
    }
    owner[v] = myid;
    j = xadj[v+1] - xadj[v]; 
    mynedges[myid] += j;
    nedgesleft -= j;
  }
  for (v =0;v<nvtxs;++v) {
    myid = owner[v];
    lvtx[v] = mynvtxs[myid]++;
  }
}


/**
 * @brief Distribute the vertices of a graph cyclicly. 
 *
 * @param nvtxs The number of vertices.
 * @param xadj The adjacecny list pointer.
 * @param nthreads The number of threads to distribute the vertices over.
 * @param mynvtxs The number of vertices owned by each thread.
 * @param mynedges The number of edges owned by each thread.
 * @param lvtx The local vertex numbers.
 * @param owner The array assigning vertices to threads.
 */
static void S_distribute_cyclic(
    vtx_type const nvtxs,
    adj_type const * const xadj,
    tid_type const nthreads,
    vtx_type * const mynvtxs,
    adj_type * const mynedges,
    vtx_type * const lvtx,
    tid_type * const owner)
{
  vtx_type i, v;
  tid_type myid;
  adj_type j, nedgesleft;
  vtx_type * perm;

  adj_type const nedges = xadj[nvtxs];
  adj_type const avgnedges = nedges / nthreads;

  perm = vtx_alloc(nvtxs);

  vtx_cyclicperm(perm,nthreads,nvtxs);

  /* distribute vertices based on edge count */
  nedgesleft = nedges;
  myid = 0;
  for (i =0;i<nvtxs;++i) {
    if ((nthreads-myid-1)*avgnedges > nedgesleft) {
      ++myid;
    }
    v = perm[i];
    owner[v] = myid;
    j = xadj[v+1] - xadj[v]; 
    mynedges[myid] += j;
    nedgesleft -= j;
  }
  for (i =0;i<nvtxs;++i) {
    myid = owner[i];
    lvtx[i] = mynvtxs[myid]++;
  }

  dl_free(perm);
}


/**
 * @brief Distribute the vertices of a graph block-cyclicly. 
 *
 * @param nvtxs The number of vertices.
 * @param xadj The adjacecny list pointer.
 * @param nthreads The number of threads to distribute the vertices over.
 * @param mynvtxs The number of vertices owned by each thread.
 * @param mynedges The number of edges owned by each thread.
 * @param lvtx The local vertex numbers.
 * @param owner The array assigning vertices to threads.
 * @param block This size of a block.
 */
static void S_distribute_blockcyclic(
    vtx_type const nvtxs,
    adj_type const * const xadj,
    tid_type const nthreads,
    vtx_type * const mynvtxs,
    adj_type * const mynedges,
    vtx_type * const lvtx,
    tid_type * const owner,
    vtx_type block)
{
  vtx_type i, v;
  tid_type myid;
  adj_type j, nedgesleft;
  vtx_type * perm;

  adj_type const nedges = xadj[nvtxs];
  adj_type const avgnedges = nedges / nthreads;

  perm = vtx_alloc(nvtxs);

  /* create cyclic permutation */
  if (nthreads * block > nvtxs) {
    /* adjust the block if it will be imbalanced */
    block = dl_max(1,nvtxs/nthreads);
  }
  vtx_blockcyclicperm(perm,nthreads,block,nvtxs);

  /* distribute vertices based on edge count */
  nedgesleft = nedges;
  myid = 0;
  for (i =0;i<nvtxs;++i) {
    if ((nthreads-myid-1)*avgnedges > nedgesleft) {
      ++myid;
    }
    v = perm[i];
    owner[v] = myid;
    j = xadj[v+1] - xadj[v]; 
    mynedges[myid] += j;
    nedgesleft -= j;
  }
  for (i =0;i<nvtxs;++i) {
    myid = owner[i];
    lvtx[i] = mynvtxs[myid]++;
  }

  dl_free(perm);
}



/**
* @brief Initializes the graph
*
* @param graph The graph to initialize
* @param nthreads The number of threads to use
*/
static void S_graph_init(
    graph_type * const graph,
    tid_type const nthreads) 
{
  graph->level = 0;

  /* graph size constants */
  graph->nvtxs = 0;
  graph->nedges = 0;
  graph->mincut = 0;
  graph->minvol = 0;
  graph->dist.nthreads = nthreads;

  /* pre partitioning info */
  graph->ngroup = 0;
  graph->group = NULL;

  /* memory for the graph structure */
  if (nthreads > 0) {
    graph->mynvtxs = vtx_alloc(nthreads);
    graph->mynedges = adj_alloc(nthreads);
    graph->xadj = r_adj_alloc(nthreads);
    graph->vwgt = r_wgt_alloc(nthreads);
    graph->adjncy = r_vtx_alloc(nthreads);
    graph->adjwgt = r_wgt_alloc(nthreads);
  }
  graph->label = NULL;
  graph->rename = NULL;
  graph->cmap = NULL;
  graph->nislands = NULL;
  graph->uniformvwgt = 0;
  graph->uniformadjwgt = 0;
  graph->tvwgt = 0;
  graph->invtvwgt = 0;

  /* nullify partition data */
  graph->where = NULL;
  graph->pwgts = NULL;
  graph->vsinfo = NULL;
  graph->esinfo = NULL;
  graph->kwinfo = NULL;

  /* by default these are set to true, but the can be explicitly changed 
   * afterwards */
  graph->free_xadj = 1;
  graph->free_vwgt = 1;
  graph->free_adjncy = 1;
  graph->free_adjwgt = 1;

  /* linked-list structure */
  graph->coarser = NULL;
  graph->finer = NULL;
}


static void S_cuthillmckee(
    vtx_type const mynvtxs,
    adj_type const * const xadj,
    vtx_type const * const adjncy,
    pid_type * const perm)
{
  vtx_type i,k,d,nordered,sr;
  adj_type j;
  vtx_type * deg;
  vv_pq_t * q, * rem;

  q = vv_pq_create(0,mynvtxs);
  rem = vv_pq_create(0,mynvtxs);

  /* offset pointer */
  deg = vtx_alloc(mynvtxs);

  /* find my lowest degree vertex */
  for (i=0;i<mynvtxs;++i) {
    d = 0;
    for (j=xadj[i];j<xadj[i+1];++j) {
      k = adjncy[j]; 
      if (k >= mynvtxs) {
        ++d;
      }
    }
    deg[i] = d;
    vv_pq_push(d,i,rem);
  }

  sr = nordered = mynvtxs;

  /* loop through connected components */
  while (rem->size > 0) {
    i = vv_pq_pop(rem);
    perm[nordered++] = i;

    /* perform bfs */
    while (sr < nordered) {
      i = perm[sr++];
      for (j=xadj[i];j<xadj[i+1];++j) {
        k = adjncy[j]; 
        if (k >= mynvtxs && vv_pq_contains(k,rem)) {
          /* local non-zero */
          vv_pq_remove(k,rem);
          vv_pq_push(deg[k],k,q);
        }
      }
      /* add rows/vertices in ascending order of local degree */
      while (q->size > 0) {
        k = vv_pq_pop(q);
        perm[nordered++] = k;
      }
    }
  }

  vv_pq_free(q);
  vv_pq_free(rem);
  /* un-offset */
  dl_free(deg);
}





/******************************************************************************
* PRIVATE PARALLEL FUNCTIONS **************************************************
******************************************************************************/


static void S_par_graph_init(
    graph_type * const graph,
    dlthread_comm_t comm)
{
  tid_type const myid = dlthread_get_id(comm);
  tid_type const nthreads = dlthread_get_nthreads(comm);

  if (myid == 0) {
    S_graph_init(graph,nthreads);
    graph->comm = comm;
  }
  dlthread_barrier(comm);
}


static graph_type * S_par_graph_bndgraph(
    ctrl_type const * const ctrl,
    graph_type const * const graph,
    int const * const * const include)
{
  vtx_type i, v, k, ninc, lvtx, maxnvtxs;
  adj_type j, l, con[2], incon[2];
  pid_type p;
  tid_type nbrid;
  adj_type nedges;
  wgt_type hwgt[2];
  adj_type * myxadj;
  vtx_type * myadjncy, * rename, ** label;
  wgt_type * myvwgt, * myadjwgt;
  graphdist_type dist;
  graph_type * bndgraph;

  tid_type const myid = dlthread_get_id(ctrl->comm);
  tid_type const nthreads = dlthread_get_nthreads(ctrl->comm);

  vtx_type const mynvtxs = graph->mynvtxs[myid];
  adj_type const * const xadj = graph->xadj[myid];
  vtx_type const * const adjncy = graph->adjncy[myid];
  wgt_type const * const vwgt = graph->vwgt[myid];
  wgt_type const * const adjwgt = graph->adjwgt[myid];
  pid_type const * const * const gwhere = (pid_type const **)graph->where;

  /* construct boundary graph --
   *   the general strategy for constructing this graph is that the two super
   *   nodes will go first [0] and [1], followed [0]'s neighbors, and then
   *   [1]'s neighbors, then followed copying the interior points from the
   *   original graph. */

  rename = vtx_alloc(mynvtxs+2);

  label = dlthread_get_shmem(sizeof(vtx_type*)*nthreads,ctrl->comm);
  label[myid] = vtx_alloc(mynvtxs);

  /* count number of vertices each thread has in the boundary graph */
  ninc = 2;
  hwgt[0] = hwgt[1] = 0;
  for (i=0;i<mynvtxs;++i) {
    if (include[myid][i]) {
      label[myid][i] = ninc;
      rename[ninc++] = i;
    } else {
      hwgt[gwhere[myid][i]] += vwgt[i];
    }
  }

  myxadj = adj_init_alloc(0,ninc+1);
  myvwgt = wgt_alloc(ninc);
  myvwgt[0] = hwgt[0];
  myvwgt[1] = hwgt[1];

  nedges = 0;

  /* we'll add these as we insert the other end of edges */
  for (i=2;i<ninc;++i) {
    v = rename[i];
    myvwgt[i] = vwgt[v];
    con[0] = con[1] = NULL_ADJ;
    for (j=xadj[v];j<xadj[v+1];++j) {
      k = adjncy[j];
      if (k < mynvtxs) {
        lvtx = k;
        nbrid = myid;
      } else {
        lvtx = gvtx_to_lvtx(k,graph->dist);
        nbrid = gvtx_to_tid(k,graph->dist);
      }
      if (include[nbrid][lvtx]) { 
        ++myxadj[i+1];
      } else {
        p = gwhere[nbrid][lvtx];
        if (con[p] == NULL_ADJ) {
          con[p] = 1;
          ++myxadj[i+1];
          /* increase the size of the super-vertex */
          ++myxadj[p+1];
        }
      }
    }
  }

  /* implicit barrier neccessary to ensure label is populated */
  maxnvtxs = vtx_dlthread_maxreduce_value(ninc,ctrl->comm);

  graph_calc_dist(maxnvtxs,nthreads,&dist);

  nedges = adj_prefixsum_exc(myxadj+1,ninc);

  myadjncy = vtx_alloc(nedges);
  myadjwgt = wgt_alloc(nedges);

  for (i=2;i<ninc;++i) {
    v = rename[i];
    con[0] = con[1] = NULL_ADJ;
    l = myxadj[i+1];
    for (j=xadj[v];j<xadj[v+1];++j) {
      k = adjncy[j];
      if (k < mynvtxs) {
        lvtx = k;
        nbrid = myid;
      } else {
        lvtx = gvtx_to_lvtx(k,graph->dist);
        nbrid = gvtx_to_tid(k,graph->dist);
      }
      if (include[nbrid][lvtx]) { 
        if (nbrid == myid) {
          myadjncy[l] = label[nbrid][lvtx];
        } else {
          myadjncy[l] = lvtx_to_gvtx(label[nbrid][lvtx],nbrid,dist);
        }
        myadjwgt[l] = adjwgt[j];
        ++l;
      } else {
        p = gwhere[nbrid][lvtx];
        if (con[p] == NULL_ADJ) {
          myadjncy[l] = p; 
          myadjwgt[l] = adjwgt[j];
          con[p] = l++;
          /* reverse edge -- supernode */
          incon[p] = myxadj[p+1]++;
          myadjncy[incon[p]] = i;
          myadjwgt[incon[p]] = adjwgt[j];
        } else {
          myadjwgt[con[p]] += adjwgt[j];
          myadjwgt[incon[p]] += adjwgt[j];
        }
        DL_ASSERT_EQUALS(myadjwgt[con[p]],myadjwgt[incon[p]],"%"PF_WGT_T);
      }
    }
    myxadj[i+1] = l;
  }
  DL_ASSERT_EQUALS(myxadj[ninc],nedges,"%"PF_ADJ_T);
  dlthread_barrier(ctrl->comm);

  dl_free(label[myid]);

  dlthread_free_shmem(label,ctrl->comm);

  bndgraph = par_graph_setup(ninc,myxadj,myadjncy,myvwgt,myadjwgt,ctrl->comm);

  if (myid == 0) {
    bndgraph->label = r_vtx_alloc(nthreads);
  }
  dlthread_barrier(ctrl->comm);

  bndgraph->label[myid] = rename;

  dlthread_barrier(ctrl->comm);

  return bndgraph;
}


static tid_type S_par_graph_extract_halves_nogroup(
    graph_type * const graph,
    pid_type const * const * const where,
    graph_type ** const halves)
{
  vtx_type i, k, hnvtxs, deg, g, v, u;
  adj_type j, l;
  pid_type w;
  tid_type o;
  tid_type hmyid, hnthreads, mygroup;
  dlthread_comm_t hcomm;
  vtx_type ** vprefix;
  vtx_type ** vsuffix;
  vtx_type nvtxs[2], hmynvtxs[2];
  adj_type nedges[2];

  tid_type const myid = dlthread_get_id(graph->comm);
  tid_type const nthreads = dlthread_get_nthreads(graph->comm);

  tid_type const fnthreads = nthreads / 2;

  /* create my vertex and edge counts */
  nvtxs[0] = nvtxs[1] = 0;
  nedges[0] = nedges[1] = 0;
  for (i=0;i<graph->mynvtxs[myid];++i) {
    w = where[myid][i];
    if (w < 2) {
      ++nvtxs[w];
    }
  }

  /* determine group assignements */
  if (myid < fnthreads) {
    mygroup = 0;
    hnthreads = fnthreads;
  } else {
    mygroup = 1;
    hnthreads = nthreads - fnthreads;
  }

  vprefix = dlthread_get_shmem(sizeof(vtx_type*)*4,graph->comm);
  vsuffix = vprefix+2;

  /* split the thread groups */
  hcomm = dlthread_comm_split(mygroup,2,graph->comm);

  DL_ASSERT_EQUALS((size_t)hnthreads,dlthread_get_nthreads(hcomm),"%zu");

  hmyid = dlthread_get_id(hcomm);

  halves[mygroup] = par_graph_create(hcomm);

  if (hmyid == 0) {
    /* lead threads only */
    vprefix[mygroup] = vtx_alloc(nthreads+1);
    halves[mygroup]->label = r_vtx_alloc(hnthreads);
  }

  if (myid == 0) {
    graph->rename = r_vtx_alloc(nthreads);
  }

  dlthread_barrier(graph->comm);

  /* vertices */
  vprefix[0][myid] = nvtxs[0]; 
  vprefix[1][myid] = nvtxs[1]; 

  /* rename vectors */
  graph->rename[myid] = vtx_alloc(graph->mynvtxs[myid]);

  dlthread_barrier(graph->comm);
  if (hmyid == 0) {
    /* create prefixsums of the vertices and edges */
    vprefix[mygroup][nthreads] = 0;
    vtx_prefixsum_exc(vprefix[mygroup],nthreads+1);

    hnvtxs = vprefix[mygroup][nthreads];

    /* create prefixsums for actual insertion into split graphs */
    vsuffix[mygroup] = vtx_alloc(hnthreads);
    for (o=0;o<hnthreads;++o) {
      vsuffix[mygroup][o] = vtx_chunkstart(o,hnthreads,hnvtxs);
      halves[mygroup]->mynvtxs[o] = vtx_chunksize(o,hnthreads,hnvtxs);
    }

    graph_calc_dist(vtx_max_value(halves[mygroup]->mynvtxs,hnthreads),hnthreads, \
        &(halves[mygroup]->dist));
  }
  dlthread_barrier(graph->comm);

  /* allocate vwgt and xadj */
  hnvtxs = halves[mygroup]->mynvtxs[hmyid];
  halves[mygroup]->xadj[hmyid] = adj_alloc(hnvtxs+1);
  halves[mygroup]->vwgt[hmyid] = wgt_alloc(hnvtxs);
  halves[mygroup]->label[hmyid] = vtx_alloc(hnvtxs);

  dlthread_barrier(graph->comm);
  /* insert vertex information into graphs */
  hmynvtxs[0] = hmynvtxs[1] = 0;
  for (i=0;i<graph->mynvtxs[myid];++i) {
    w = where[myid][i];
    if (w < 2) {
      u = hmynvtxs[w]++;
      hnvtxs = vprefix[w][nthreads];
      hnthreads = (w == 0 ? fnthreads : nthreads - fnthreads);
      
      /* get total vertex number */
      g = u + vprefix[w][myid];

      DL_ASSERT(g < hnvtxs,"Got vertex number of %"PF_VTX_T"/%"PF_VTX_T" " \
          "from %"PF_VTX_T" and %"PF_VTX_T"\n",g,hnvtxs,u, \
          vprefix[w][myid]);

      /* get new local vertex number */
      hmyid = vtx_chunkid(g,hnthreads,hnvtxs); 

      DL_ASSERT(hmyid < hnthreads,"Got chunk id of %"PF_TID_T"/%"PF_TID_T" " \
          "from %"PF_VTX_T", %"PF_TID_T", %"PF_VTX_T"\n",hmyid,hnthreads, \
          g,hnthreads,hnvtxs);

      v = g - vsuffix[w][hmyid];

      /* set rename */
      graph->rename[myid][i] = lvtx_to_gvtx(v,hmyid,halves[w]->dist);

      /* set alias as global vertex ID */
      halves[w]->label[hmyid][v] = lvtx_to_gvtx(i,myid,graph->dist);

      /* copy vertex weight */
      halves[w]->vwgt[hmyid][v] = graph->vwgt[myid][i];

      /* copy xadj info */
      deg = 0;
      for (j=graph->xadj[myid][i];j<graph->xadj[myid][i+1];++j) {
        k = graph->adjncy[myid][j];
        if (k < graph->mynvtxs[myid]) {
          o = myid;
        } else {
          o = gvtx_to_tid(k,graph->dist);
          k = gvtx_to_lvtx(k,graph->dist);
        }
        if (where[o][k] == w) {
          ++deg;
        }
      }
      halves[w]->xadj[hmyid][v] = deg;
    }
  }

  dlthread_barrier(graph->comm);

  /* fix respective xadj's */
  if (myid < fnthreads) {
    mygroup = 0;
    hmyid = myid; 
    hnthreads = fnthreads;
  } else {
    mygroup = 1;
    hmyid = myid - fnthreads;
    hnthreads = nthreads - fnthreads;
  }

  hnvtxs = halves[mygroup]->mynvtxs[hmyid];
  halves[mygroup]->xadj[hmyid][hnvtxs] = 0;
  adj_prefixsum_exc(halves[mygroup]->xadj[hmyid],hnvtxs+1);

  halves[mygroup]->adjncy[hmyid] = \
      vtx_alloc(halves[mygroup]->xadj[hmyid][hnvtxs]);
  halves[mygroup]->adjwgt[hmyid] = \
      wgt_alloc(halves[mygroup]->xadj[hmyid][hnvtxs]);

  halves[mygroup]->mynedges[hmyid] = halves[mygroup]->xadj[hmyid][hnvtxs];

  dlthread_barrier(graph->comm);
  /* insert edge information into graphs */
  hmynvtxs[0] = hmynvtxs[1] = 0;
  for (i=0;i<graph->mynvtxs[myid];++i) {
    w = where[myid][i];
    if (w < 2) {
      u = hmynvtxs[w]++;
      hnvtxs = vprefix[w][nthreads];
      hnthreads = (w == 0 ? fnthreads : nthreads - fnthreads);
      
      /* get total vertex number */
      g = u + vprefix[w][myid];

      /* get new local vertex number */
      hmyid = vtx_chunkid(g,hnthreads,hnvtxs); 
      v = g - vsuffix[w][hmyid];

      l = halves[w]->xadj[hmyid][v];
      for (j=graph->xadj[myid][i];j<graph->xadj[myid][i+1];++j) {
        k = graph->adjncy[myid][j];
        if (k < graph->mynvtxs[myid]) {
          o = myid;
        } else {
          o = gvtx_to_tid(k,graph->dist);
          k = gvtx_to_lvtx(k,graph->dist);
        }
        if (where[o][k] == w) {
          /* calcuate new endpoint */
          u = graph->rename[o][k];
          o = gvtx_to_tid(u,halves[w]->dist);
          if (o == hmyid) {
            k = gvtx_to_lvtx(u,halves[w]->dist);
          } else {
            k = u;
          }

          /* process edge */
          halves[w]->adjncy[hmyid][l] = k;
          halves[w]->adjwgt[hmyid][l] = graph->adjwgt[myid][j];
          ++l;
        }
      }
    }
  }
  dlthread_barrier(graph->comm);

  if (myid < fnthreads) {
    hmyid = myid; 
    mygroup = 0;
    hnthreads = fnthreads;
  } else {
    hmyid = myid - fnthreads;
    mygroup = 1;
    hnthreads = nthreads - fnthreads;
  }

  if (hmyid == 0) {
    /* lead threads only */
    halves[mygroup]->nvtxs = vtx_sum(halves[mygroup]->mynvtxs,hnthreads);
    halves[mygroup]->gnvtxs = max_gvtx(halves[mygroup]); 
    halves[mygroup]->nedges = adj_sum(halves[mygroup]->mynedges,hnthreads);

    dl_free(vprefix[mygroup]);
    dl_free(vsuffix[mygroup]);
  }

  par_graph_setup_twgts(halves[mygroup]);

  /* implicit barrier */
  dlthread_free_shmem(vprefix,graph->comm); /* vsuffix is part of this */

  return mygroup;
}


static tid_type S_par_graph_extract_halves_group(
    graph_type * const graph,
    pid_type const * const * const gwhere,
    graph_type ** const halves)
{
  vtx_type i, k, hnvtxs, g, v, u, lvtx, maxgvtx;
  adj_type j, hnedges;
  pid_type d, other;
  tid_type hmyid, hnthreads, mygroup, o, t, nbrid;
  dlthread_comm_t hcomm;
  graph_type * mygraph;
  vtx_type * gvtxs;
  vtx_type * mydist[2];

  tid_type const myid = dlthread_get_id(graph->comm);
  tid_type const nthreads = dlthread_get_nthreads(graph->comm);

  tid_type const fnthreads = nthreads / 2;

  vtx_type const * const gmynvtxs = graph->mynvtxs;
  adj_type const * const * const gxadj = (adj_type const **)graph->xadj;
  vtx_type const * const * const gadjncy = (vtx_type const **)graph->adjncy;
  wgt_type const * const * const gvwgt = (wgt_type const **)graph->vwgt;
  wgt_type const * const * const gadjwgt = (wgt_type const **)graph->adjwgt;

  pid_type const ngroup = graph->ngroup;
  pid_type const * const * const group = (pid_type const **)graph->group;

  /* don't bother with weights on the base graph */
  int const do_wgt = graph->level > 0; /* this is a bug! */

  /* Create a global array of vertices by distribution id here ***************/

  /* allocate my rename vector first to use natural vectors */
  if (myid == 0) {
    graph->rename = r_vtx_alloc(nthreads);
  }

  gvtxs = dlthread_get_shmem(graph->nvtxs*sizeof(vtx_type),graph->comm);

  mydist[0] = vtx_init_alloc(0,ngroup*2+1);
  mydist[1] = mydist[0] + ngroup;

  /* create my vertex and edge counts */
  for (i=0;i<gmynvtxs[myid];++i) {
    other = gwhere[myid][i];
    if (other < 2) {
      /* count my vertices per dist */
      ++mydist[other][group[myid][i]];
    }
  }

  /* each thread owns disjoint distributions, so there really is a faster way
   * to do this */
  vtx_dlthread_sumareduce(mydist[0],2*ngroup,graph->comm);

  /* create a prefix sum of each mydist array to index into a global array of
   * vertices */
  vtx_prefixsum_exc(mydist[0],(2*ngroup)+1);

  /* insert my vertices global id numbers into the global array */
  for (i=0;i<gmynvtxs[myid];++i) {
    g = lvtx_to_gvtx(i,myid,graph->dist);
    other = gwhere[myid][i];
    if (other < 2) {
      v = mydist[other][group[myid][i]]++;
      gvtxs[v] = g;
    }
  }

  /* re-synchronize the mydist vector */
  vtx_dlthread_minareduce(mydist[0],2*ngroup,graph->comm);


  /* work on splitting the comm and graph here *******************************/

  /* determine group assignements */
  if (myid < fnthreads) {
    mygroup = 0;
    hnthreads = fnthreads;
  } else {
    mygroup = 1;
    hnthreads = nthreads - fnthreads;
  }

  /* split the thread groups */
  hcomm = dlthread_comm_split(mygroup,2,graph->comm);

  DL_ASSERT_EQUALS((size_t)hnthreads,dlthread_get_nthreads(hcomm),"%zu");

  hmyid = dlthread_get_id(hcomm);


  /* start constructing each half here ***************************************/

  mygraph = halves[mygroup] = par_graph_create(hcomm);

  if (hmyid == 0) {
    /* lead threads only */
    mygraph->label = r_vtx_alloc(hnthreads);
    mygraph->group = r_pid_alloc(hnthreads);
    mygraph->ngroup = graph->ngroup;
  }

  /* rename vectors */
  graph->rename[myid] = vtx_alloc(graph->mynvtxs[myid]);

  dlthread_barrier(graph->comm);

  hnvtxs = 0;
  hnedges = 0;

  /* each thread is now responsible for building its own part of the new 
   * graph -- first count my edges and vertices */
  for (d=hmyid;d<ngroup;d+=hnthreads) {
    /* go through each distribution and copy it */
    for (i=mydist[mygroup][d];i<mydist[mygroup][d+1];++i) {
      g = gvtxs[i];
      v = gvtx_to_lvtx(g,graph->dist);
      o = gvtx_to_tid(g,graph->dist);

      ++hnvtxs;
      for (j=gxadj[o][v];j<gxadj[o][v+1];++j) {
        k = gadjncy[o][j];
        if (k < gmynvtxs[o]) {
          lvtx = k;
          nbrid = o;
        } else {
          lvtx = gvtx_to_lvtx(k,graph->dist);
          nbrid = gvtx_to_tid(k,graph->dist);
        }
        other = gwhere[nbrid][lvtx];
        if (other == mygroup) {
          ++hnedges;
        }
      }
    }
  }

  maxgvtx = vtx_dlthread_sumreduce(hnvtxs,hcomm);

  if (hmyid == 0) {
    graph_calc_dist(maxgvtx,hnthreads,&(mygraph->dist));
  }

  /* allocate vwgt and xadj */
  mygraph->mynvtxs[hmyid] = hnvtxs;
  mygraph->mynedges[hmyid] = hnedges;
  mygraph->xadj[hmyid] = adj_alloc(hnvtxs+1);
  mygraph->vwgt[hmyid] = wgt_alloc(hnvtxs);
  mygraph->label[hmyid] = vtx_alloc(hnvtxs);
  mygraph->adjncy[hmyid] = vtx_alloc(hnedges);
  mygraph->adjwgt[hmyid] = wgt_alloc(hnedges);
  mygraph->group[hmyid] = pid_alloc(hnvtxs);

  /* sync so we can write to rename */
  dlthread_barrier(graph->comm);

  hnvtxs = 0;
  for (d=hmyid;d<ngroup;d+=hnthreads) {
    for (i=mydist[mygroup][d];i<mydist[mygroup][d+1];++i) {
      g = gvtxs[i];
      v = gvtx_to_lvtx(g,graph->dist);
      o = gvtx_to_tid(g,graph->dist);

      /* set rename */
      graph->rename[o][v] = lvtx_to_gvtx(hnvtxs,hmyid,mygraph->dist);
      ++hnvtxs;
    }
  }

  /* sync so we can read from rename */
  dlthread_barrier(graph->comm);

  /* populate edges */
  hnvtxs = 0;
  hnedges = 0;

  mygraph->xadj[hmyid][0] = 0;

  if (do_wgt) {
    for (d=hmyid;d<ngroup;d+=hnthreads) {
      for (i=mydist[mygroup][d];i<mydist[mygroup][d+1];++i) {
        g = gvtxs[i];
        v = gvtx_to_lvtx(g,graph->dist);
        o = gvtx_to_tid(g,graph->dist);

        mygraph->vwgt[hmyid][hnvtxs] = gvwgt[o][v];
        mygraph->label[hmyid][hnvtxs] = g;
        mygraph->group[hmyid][hnvtxs] = group[o][v];

        for (j=gxadj[o][v];j<gxadj[o][v+1];++j) {
          k = gadjncy[o][j];
          if (k < gmynvtxs[o]) {
            lvtx = k;
            nbrid = o;
          } else {
            lvtx = gvtx_to_lvtx(k,graph->dist);
            nbrid = gvtx_to_tid(k,graph->dist);
          }
          other = gwhere[nbrid][lvtx];
          if (other == mygroup) {
            /* calcuate new endpoint */
            u = graph->rename[nbrid][lvtx];
            t = gvtx_to_tid(u,mygraph->dist);
            if (t == hmyid) {
              k = gvtx_to_lvtx(u,mygraph->dist);
            } else {
              k = u;
            }
            
            mygraph->adjncy[hmyid][hnedges] = k;
            mygraph->adjwgt[hmyid][hnedges] = gadjwgt[o][j];
            ++hnedges;
          }
        }

        ++hnvtxs;
        mygraph->xadj[hmyid][hnvtxs] = hnedges;
      }
    }
  } else {
    for (d=hmyid;d<ngroup;d+=hnthreads) {
      for (i=mydist[mygroup][d];i<mydist[mygroup][d+1];++i) {
        g = gvtxs[i];
        v = gvtx_to_lvtx(g,graph->dist);
        o = gvtx_to_tid(g,graph->dist);

        mygraph->label[hmyid][hnvtxs] = g;
        mygraph->group[hmyid][hnvtxs] = group[o][v];

        for (j=gxadj[o][v];j<gxadj[o][v+1];++j) {
          k = gadjncy[o][j];
          if (k < gmynvtxs[o]) {
            lvtx = k;
            nbrid = o;
          } else {
            lvtx = gvtx_to_lvtx(k,graph->dist);
            nbrid = gvtx_to_tid(k,graph->dist);
          }
          other = gwhere[nbrid][lvtx];
          if (other == mygroup) {
            /* calcuate new endpoint */
            u = graph->rename[nbrid][lvtx];
            t = gvtx_to_tid(u,mygraph->dist);
            if (t == hmyid) {
              k = gvtx_to_lvtx(u,mygraph->dist);
            } else {
              k = u;
            }
            
            mygraph->adjncy[hmyid][hnedges] = k;
            ++hnedges;
          }
        }

        ++hnvtxs;
        mygraph->xadj[hmyid][hnvtxs] = hnedges;
      }
    }
    wgt_set(mygraph->vwgt[hmyid],1,hnvtxs);
    wgt_set(mygraph->adjwgt[hmyid],1,hnedges);
  }

  if (hmyid == 0) {
    /* lead threads only */
    mygraph->nvtxs = vtx_sum(mygraph->mynvtxs,hnthreads);
    mygraph->gnvtxs = max_gvtx(mygraph); 
    mygraph->nedges = adj_sum(mygraph->mynedges,hnthreads);
  }

  par_graph_setup_twgts(mygraph);

  dl_free(mydist[0]);
  dlthread_free_shmem(gvtxs,graph->comm);

  DL_ASSERT(check_graph(mygraph),"Bad graph extracted");

  return mygroup;
}


/**
 * @brief Distribute the vertices of a graph in contigous blocks. This function
 * outputs to five arrays. 'mynvtxs' and 'mynedges' will contain the number of
 * vertices and edges assigned to each thread. 'label' will contain the
 * original vertex number for each distributed vertex. The second level
 * pointers will be allocated. 'lvtx' will contain the
 * local vertex number for each original vertex. 'owner' will contain the
 * owning thread id for each original vertex.
 *
 *
 * @param nvtxs The number of vertices.
 * @param xadj The adjacecny list pointer.
 * @param mynvtxs The number of vertices owned by each thread.
 * @param mynedges The number of edges owned by each thread.
 * @param label The labels for each vertex in the distributed graph.
 * @param lvtx The local vertex numbers.
 * @param owner The array assigning vertices to threads.
 * @param comm The thread communicator.
 */
static void S_par_distribute_block(
    vtx_type const nvtxs,
    adj_type const * const xadj,
    vtx_type * const mynvtxs,
    adj_type * const mynedges,
    vtx_type ** const label,
    vtx_type * const rename,
    tid_type * const owner,
    dlthread_comm_t const comm)
{
  vtx_type i, v, chunkstart, chunkend;
  adj_type sum;
  adj_type * prefixsum;
  vtx_type * vtxdist;

  tid_type const myid = dlthread_get_id(comm);
  tid_type const nthreads = dlthread_get_nthreads(comm);

  adj_type const nedges = xadj[nvtxs];
  adj_type const targetnedges = ((nedges+(nthreads-1)) / nthreads)*(myid+1);

  prefixsum = dlthread_get_shmem((sizeof(*prefixsum)*(nvtxs + 1)) + \
      (sizeof(*vtxdist)*(nthreads + 1)),comm);
  vtxdist = (vtx_type*)(prefixsum + nvtxs + 1);

  if (myid == 0) {
    vtxdist[0] = 0;
    prefixsum[nvtxs] = 0;
  }

  /* create a prefixsum of the edge counts */
  chunkstart = vtx_chunkstart(myid,nthreads,nvtxs);
  chunkend = chunkstart + vtx_chunksize(myid,nthreads,nvtxs);
  sum = 0;
  for (v=chunkstart;v<chunkend;++v) {
    prefixsum[v] = xadj[v+1] - xadj[v];
    sum += xadj[v+1] - xadj[v];
  }
  adj_dlthread_prefixsum(&sum,1,NULL,comm);
  for (v=chunkstart;v<chunkend;++v) {
    sum += prefixsum[v];
    prefixsum[v] = sum - prefixsum[v];
  }
  if (myid == nthreads-1) {
    prefixsum[nvtxs] = sum;
    DL_ASSERT_EQUALS(sum,xadj[nvtxs],"%"PF_ADJ_T);
    dprintf("Sum = %"PF_ADJ_T"\n",sum);
  }
  dlthread_barrier(comm);

  /* each thread binary searches to find its chunk */
  vtxdist[myid+1] = adj_binarysearch(prefixsum,targetnedges,nvtxs+1);

  dlthread_barrier(comm);

  mynedges[myid] = prefixsum[vtxdist[myid+1]] - prefixsum[vtxdist[myid]];
  mynvtxs[myid] = vtxdist[myid+1] - vtxdist[myid];

  label[myid] = vtx_alloc(mynvtxs[myid]);

  /* each thread populates its array portions */
  v = 0;
  for (i=vtxdist[myid];i<vtxdist[myid+1];++i) {
    label[myid][v] = i;
    rename[i] = v++;
    owner[i] = myid;
  }

  dlthread_free_shmem(prefixsum,comm);
}


static void S_par_distribute_cyclic(
    vtx_type const nvtxs,
    adj_type const * const xadj,
    vtx_type * const mynvtxs,
    adj_type * const mynedges,
    vtx_type ** const label,
    vtx_type * const rename,
    tid_type * const owner,
    dlthread_comm_t const comm)
{
  vtx_type i, v, k, chunkstart, chunkend, start;
  adj_type sum;
  adj_type * prefixsum;
  vtx_type * vtxdist, * perm;

  tid_type const myid = dlthread_get_id(comm);
  tid_type const nthreads = dlthread_get_nthreads(comm);

  adj_type const nedges = xadj[nvtxs];
  adj_type const targetnedges = ((nedges+(nthreads-1)) / nthreads)*(myid+1);

  prefixsum = dlthread_get_shmem((sizeof(*prefixsum)*(nvtxs + 1)) + \
      (sizeof(*vtxdist)*(nthreads + 1)) + (sizeof(*perm)*nvtxs),comm);
  vtxdist = (vtx_type*)(prefixsum + nvtxs + 1);
  perm = (vtx_type*)(vtxdist + nthreads + 1);

  if (myid == 0) {
    vtxdist[0] = 0;
    prefixsum[nvtxs] = 0;

    vtx_cyclicperm(perm,nthreads,nvtxs);
  }
  dlthread_barrier(comm);

  /* create a prefixsum of the edge counts */
  chunkstart = vtx_chunkstart(myid,nthreads,nvtxs);
  chunkend = chunkstart + vtx_chunksize(myid,nthreads,nvtxs);
  sum = 0;
  for (v=chunkstart;v<chunkend;++v) {
    i = perm[v];
    prefixsum[v] = xadj[i+1] - xadj[i];
    sum += xadj[i+1] - xadj[i];
  }
  adj_dlthread_prefixsum(&sum,1,NULL,comm);
  for (v=chunkstart;v<chunkend;++v) {
    sum += prefixsum[v];
    prefixsum[v] = sum - prefixsum[v];
  }
  if (myid == nthreads-1) {
    prefixsum[nvtxs] = sum;
  }
  dlthread_barrier(comm);

  /* each thread binary searches to find its chunk */
  vtxdist[myid+1] = adj_binarysearch(prefixsum,targetnedges,nvtxs+1);

  dlthread_barrier(comm);

  mynedges[myid] = prefixsum[vtxdist[myid+1]] - prefixsum[vtxdist[myid]];
  mynvtxs[myid] = vtxdist[myid+1] - vtxdist[myid];

  label[myid] = vtx_alloc(mynvtxs[myid]);

  /* each thread populates its array portions -- start offset to avoid false
   * sharing */
  v = 0;
  start = (mynvtxs[myid])*(myid/(double)nthreads);
  for (k=0;k<mynvtxs[myid];++k) {
    i = perm[((k+start) % mynvtxs[myid]) + vtxdist[myid]];
    label[myid][v] = i;
    rename[i] = v++;
    owner[i] = myid;
  }

  dlthread_free_shmem(prefixsum,comm);
}


static void S_par_distribute_blockcyclic(
    vtx_type const nvtxs,
    adj_type const * const xadj,
    vtx_type * const mynvtxs,
    adj_type * const mynedges,
    vtx_type ** const label,
    vtx_type * const rename,
    tid_type * const owner,
    vtx_type const block,
    dlthread_comm_t const comm)
{
  vtx_type i, v, k, chunkstart, chunkend;
  adj_type sum;
  adj_type * prefixsum;
  vtx_type * vtxdist, * perm;

  tid_type const myid = dlthread_get_id(comm);
  tid_type const nthreads = dlthread_get_nthreads(comm);

  adj_type const nedges = xadj[nvtxs];
  adj_type const targetnedges = ((nedges+(nthreads-1)) / nthreads)*(myid+1);

  prefixsum = dlthread_get_shmem((sizeof(*prefixsum)*(nvtxs + 1)) + \
      (sizeof(*vtxdist)*(nthreads + 1)) + (sizeof(*perm)*nvtxs),comm);
  vtxdist = (vtx_type*)(prefixsum + nvtxs + 1);
  perm = (vtx_type*)(vtxdist + nthreads + 1);

  if (myid == 0) {
    vtxdist[0] = 0;
    prefixsum[nvtxs] = 0;
    /* will need to parallelize this someday - not high priority as its an O(n)
     * operation rather than the O(m) operations which dominate */
    vtx_blockcyclicperm(perm,nthreads,block,nvtxs);
  }

  /* make sure everyone can access the perm */
  dlthread_barrier(comm);

  /* create a prefixsum of the edge counts */
  chunkstart = vtx_chunkstart(myid,nthreads,nvtxs);
  chunkend = chunkstart + vtx_chunksize(myid,nthreads,nvtxs);
  sum = 0;
  for (v=chunkstart;v<chunkend;++v) {
    i = perm[v];
    prefixsum[v] = xadj[i+1] - xadj[i];
    sum += xadj[i+1] - xadj[i];
  }
  adj_dlthread_prefixsum(&sum,1,NULL,comm);
  for (v=chunkstart;v<chunkend;++v) {
    sum += prefixsum[v];
    prefixsum[v] = sum - prefixsum[v];
  }
  if (myid == nthreads-1) {
    prefixsum[nvtxs] = sum;
  }
  dlthread_barrier(comm);

  /* each thread binary searches to find its chunk */
  vtxdist[myid+1] = adj_binarysearch(prefixsum,targetnedges,nvtxs+1);

  dlthread_barrier(comm);

  mynedges[myid] = prefixsum[vtxdist[myid+1]] - prefixsum[vtxdist[myid]];
  mynvtxs[myid] = vtxdist[myid+1] - vtxdist[myid];

  label[myid] = vtx_alloc(mynvtxs[myid]);

  /* each thread populates its array portions */
  v = 0;
  for (k=vtxdist[myid];k<vtxdist[myid+1];++k) {
    i = perm[k];
    label[myid][v] = i;
    rename[i] = v++;
    owner[i] = myid;
  }

  dlthread_free_shmem(prefixsum,comm);
}



/******************************************************************************
* PUBLIC SERIAL FUNCTIONS *****************************************************
******************************************************************************/


graph_type * graph_create(
    tid_type const nthreads)
{
  graph_type * graph;

  graph = (graph_type*)calloc(1,sizeof(graph_type));

  S_graph_init(graph,nthreads);

  return graph; 
}


graph_type * graph_setup(
    vtx_type * const nvtxs, 
    adj_type ** const xadj, 
    vtx_type ** const adjncy, 
    wgt_type ** const adjwgt, 
    wgt_type ** const vwgt,
    tid_type const nthreads) 
{
  tid_type myid;
  graph_type * graph;

  graph = graph_create(0);

  graph->mynvtxs = nvtxs;
  graph->xadj = xadj;
  graph->adjncy = adjncy;
  if (adjwgt) {
    graph->adjwgt = adjwgt;
  } else {
    graph->adjwgt = r_wgt_alloc(nthreads);
    for (myid=0;myid<nthreads;++myid) {
      graph->adjwgt[myid] = wgt_init_alloc(1,xadj[myid][nvtxs[myid]]);
    }
    graph->uniformadjwgt = 1;
    graph->free_adjwgt = 1;
  }
  if (vwgt) {
    graph->vwgt = vwgt;
  } else {
    graph->vwgt = r_wgt_alloc(nthreads);
    for (myid=0;myid<nthreads;++myid) {
      graph->vwgt[myid] = wgt_init_alloc(1,nvtxs[myid]);
    }
    graph->uniformvwgt = 1;
    graph->free_vwgt = 1;
  }

  for (myid=0;myid<nthreads;++myid) {
    graph->mynedges[myid] = xadj[myid][nvtxs[myid]];
  }

  graph->nvtxs = vtx_sum(graph->mynvtxs,nthreads);
  graph->nedges = adj_sum(graph->mynedges,nthreads);

  graph_calc_dist(vtx_max_value(graph->mynvtxs,nthreads),nthreads,&(graph->dist));

  graph_setup_twgts(graph);

  DL_ASSERT(check_graph(graph),"Bad graph");

  return graph;
}


graph_type * graph_distribute(
    int const distribution,
    vtx_type const nvtxs, 
    adj_type const * const xadj, 
    vtx_type const * const adjncy, 
    wgt_type const * const vwgt,
    wgt_type const * const adjwgt, 
    tid_type const nthreads)
{
  vtx_type i,k,v,deg,mynvtxs;
  adj_type j,l;
  tid_type myid;
  vtx_type * dmynvtxs;
  adj_type * dmynedges;
  adj_type ** dxadj;
  vtx_type ** dadjncy, ** dlabel;
  wgt_type ** dadjwgt = NULL, ** dvwgt = NULL;
  graphdist_type dist;
  graph_type * graph;

  DL_ASSERT(nvtxs>0, "distribute_graph() called with nvtxs = %"PF_VTX_T"\n", \
      nvtxs);

  vtx_type * lvtx = vtx_alloc(nvtxs);
  tid_type * owner = tid_alloc(nvtxs);

  graph = graph_create(nthreads);

  /* set arrays from graph*/
  dmynvtxs = graph->mynvtxs;
  dmynedges = graph->mynedges;
  dxadj = graph->xadj;
  dadjncy = graph->adjncy;
  dadjwgt = graph->adjwgt;
  dvwgt = graph->vwgt;

  /* labels must be explicityl allocated */
  dlabel = graph->label = r_vtx_alloc(nthreads);

  /* zero out vertices and edges */
  vtx_set(dmynvtxs,0,nthreads);
  adj_set(dmynedges,0,nthreads);

  switch(distribution) {
    case MTMETIS_DISTRIBUTION_BLOCK:
      S_distribute_block(nvtxs,xadj,nthreads,dmynvtxs,dmynedges, \
          lvtx,owner);
      break;
    case MTMETIS_DISTRIBUTION_CYCLIC:
      S_distribute_cyclic(nvtxs,xadj,nthreads,dmynvtxs,dmynedges, \
          lvtx,owner);
      break;
    case MTMETIS_DISTRIBUTION_BLOCKCYCLIC:
      S_distribute_blockcyclic(nvtxs,xadj,nthreads,dmynvtxs, \
          dmynedges,lvtx,owner,4096);
      break;
    default:
      dl_error("Unknown distribution '%d'\n",distribution);
  }

  graph_calc_dist(vtx_max_value(dmynvtxs,nthreads),nthreads,&dist);

  /* allocate arrays */
  for (myid =0;myid<nthreads;++myid) {
    mynvtxs = dmynvtxs[myid];
    dxadj[myid] = adj_alloc(mynvtxs+1);
    dxadj[myid][0] = 0;
    dlabel[myid] = vtx_alloc(mynvtxs);
    dadjncy[myid] = vtx_alloc(dmynedges[myid]);
    dvwgt[myid] = wgt_alloc(mynvtxs);
    dadjwgt[myid] = wgt_alloc(dmynedges[myid]);
    /* zero counts for insertion later */
    dmynvtxs[myid] = 0;
    dmynedges[myid] = 0;
  }

  /* set xadj and iadjwgt */
  for (v =0;v<nvtxs;++v) { 
    myid = owner[v];
    i = dmynvtxs[myid]++; 
    dlabel[myid][i] = v;
    DL_ASSERT_EQUALS(i,lvtx[v],"%"PF_VTX_T);
    deg = xadj[v+1] - xadj[v];
    dxadj[myid][i+1] = dxadj[myid][i] + deg;
    l = dmynedges[myid];
    if (adjwgt) {
      for (j =xadj[v];j<xadj[v+1];++j) {
        k = adjncy[j];
        if (owner[k] == myid) {
          dadjncy[myid][l] = lvtx[k];
        } else {
          dadjncy[myid][l] = lvtx_to_gvtx(lvtx[k],owner[k],dist);
        }
        dadjwgt[myid][l++] = adjwgt[j]; 
      }
    } else {
      for (j =xadj[v];j<xadj[v+1];++j) {
        k = adjncy[j];
        if (owner[k] == myid) {
          dadjncy[myid][l] = lvtx[k];
        } else {
          dadjncy[myid][l] = lvtx_to_gvtx(lvtx[k],owner[k],dist);
        }
        dadjwgt[myid][l++] = 1;
      }
    }
    DL_ASSERT_EQUALS(dxadj[myid][i+1],l,"%"PF_ADJ_T);
    dmynedges[myid] = l;
    if (vwgt) {
      dvwgt[myid][i] = vwgt[v];
    } else {
      dvwgt[myid][i] = 1;
    }
  }

  dl_free(owner);
  dl_free(lvtx);

  /* setup the graph */
  graph->gnvtxs = lvtx_to_gvtx(vtx_max_value(dmynvtxs,nthreads),nthreads-1, \
      dist);
  graph->nvtxs = nvtxs;
  graph->nedges = xadj[nvtxs];
  graph->dist = dist;

  /* setup tvwgt */
  graph->tvwgt = 0;
  if (vwgt) {
    for (myid=0;myid<nthreads;++myid) {
      graph->tvwgt += wgt_sum(graph->vwgt[myid],graph->mynvtxs[myid]);
    }
  } else {
    graph->tvwgt = graph->nvtxs;
    graph->uniformvwgt = 1;
  }
  graph->invtvwgt = 1.0/(graph->tvwgt > 0 ? graph->tvwgt : 1);

  /* setup tadjwgt */
  graph->tadjwgt = 0;
  if (adjwgt) {
    for (myid=0;myid<nthreads;++myid) {
      graph->tadjwgt += wgt_sum(graph->adjwgt[myid],dmynedges[myid]);
    }
  } else {
    graph->tadjwgt = graph->nedges;
    graph->uniformadjwgt = 1;
  }

  /* set free configuration */
  graph->free_xadj = 1;
  graph->free_adjncy = 1;
  graph->free_adjwgt = 1;
  graph->free_vwgt = 1;

  DL_ASSERT(check_graph(graph),"Bad graph");

  return graph;
}


void graph_gather(
  graph_type const * const graph,
  adj_type ** const r_xadj,
  vtx_type ** const r_adjncy,
  wgt_type ** const r_vwgt,
  wgt_type ** const r_adjwgt,
  vtx_type ** const r_voff)
{
  vtx_type i, k, v, g;
  adj_type j, l;
  tid_type t, myid;
  adj_type * gxadj;
  vtx_type * gadjncy, * prefix;
  wgt_type * gvwgt, * gadjwgt;

  tid_type const nthreads = graph->dist.nthreads;

  vtx_type const * const mynvtxs = graph->mynvtxs;
  adj_type const * const mynedges = graph->mynedges;
  adj_type const * const * const xadj = (adj_type const **)graph->xadj;
  vtx_type const * const * const adjncy = (vtx_type const **)graph->adjncy;
  wgt_type const * const * const vwgt = (wgt_type const **)graph->vwgt;
  wgt_type const * const * const adjwgt = (wgt_type const **)graph->adjwgt;

  int const do_vwgt = !graph->uniformvwgt;
  int const do_adjwgt = !graph->uniformadjwgt;

  /* DL_ASSERT_EQUALS(mynedges,xadj[mynvtxs],"%"PF_ADJ_T); */
  DL_ASSERT_EQUALS(adj_sum(graph->mynedges,nthreads),graph->nedges, \
      "%"PF_ADJ_T);

  gxadj = adj_alloc(graph->nvtxs+1);
  gadjncy = vtx_alloc(graph->nedges);
  gvwgt = wgt_alloc(graph->nvtxs);
  gadjwgt = wgt_alloc(graph->nedges);

  /* create the vertex offsets */
  prefix = vtx_duplicate(mynvtxs,nthreads);
  vtx_prefixsum_exc(prefix,nthreads);

  /* vertex ids are purely based on thread offsets */
  gxadj[0] = 0;
  g = 0;
  l = 0;
  for (myid=0;myid<nthreads;++myid) {
    if (do_vwgt) {
      wgt_copy(gvwgt+g,vwgt[myid],mynvtxs[myid]);
    } else {
      wgt_set(gvwgt+g,1,mynvtxs[myid]);
    }
    if (do_adjwgt) {
      wgt_copy(gadjwgt+l,adjwgt[myid],mynedges[myid]);
    } else {
      wgt_set(gadjwgt+l,1,mynedges[myid]);
    }
    /* insert edges into graph */
    for (i=0;i<mynvtxs[myid];++i) {
      for (j=xadj[myid][i];j<xadj[myid][i+1];++j) {
        k = adjncy[myid][j];
        if (k < mynvtxs[myid]) {
          t = myid;
          v = k;
        } else {
          t = gvtx_to_tid(k,graph->dist);
          v = gvtx_to_lvtx(k,graph->dist);
        }
        gadjncy[l++] = v + prefix[t];
      }
      gxadj[++g] = l;
    }
  }

  /* assign pointers */
  *r_xadj = gxadj;
  *r_adjncy = gadjncy;
  *r_vwgt = gvwgt;
  *r_adjwgt = gadjwgt;

  if (r_voff) {
    *r_voff = prefix;
  } else {
    dl_free(prefix);
  }
}


graph_type * graph_setup_coarse(
    graph_type * const graph, 
    vtx_type * const cnvtxs)
{
  graph_type * cgraph;
  tid_type myid;

  tid_type const nthreads = graph->dist.nthreads;

  cgraph = graph_create(nthreads);

  graph->coarser = cgraph;
  cgraph->finer = graph;

  cgraph->level = graph->level + 1;

  DL_ASSERT_EQUALS(nthreads,graph->dist.nthreads,"%"PF_TID_T);

  graph_calc_dist(vtx_max_value(cgraph->mynvtxs,nthreads),nthreads, \
      &cgraph->dist);

  cgraph->tvwgt = graph->tvwgt;
  cgraph->invtvwgt = graph->invtvwgt;

  DL_ASSERT(cgraph != NULL,"cgraph is NULL");

  for (myid=0;myid<nthreads;++myid) {
    cgraph->mynvtxs[myid] = cnvtxs[myid];

    cgraph->xadj[myid] = adj_alloc(cnvtxs[myid]+1);
    if (cgraph->mynvtxs[myid] > 0) {
      cgraph->vwgt[myid] = wgt_alloc(cnvtxs[myid]);
    } else {
      cgraph->xadj[myid][0] = 0;
      cgraph->vwgt[myid] = NULL;
    }

    cgraph->adjncy[myid] = NULL;
    cgraph->adjwgt[myid] = NULL;
  }

  cgraph->gnvtxs = cgraph->gnvtxs;
  cgraph->nvtxs = vtx_sum(cgraph->mynvtxs,nthreads);

  DL_ASSERT(cgraph->gnvtxs >= cgraph->nvtxs,"Bad gnvtxs");

  return cgraph;
}


void graph_setup_twgts(
    graph_type * const graph)
{
  vtx_type i;
  adj_type j;
  twgt_type vsum,asum;
  tid_type myid;

  tid_type const nthreads = graph->dist.nthreads;

  if (graph->uniformvwgt) {
    vsum = graph->nvtxs;
  } else {
    vsum = 0;
    for (myid=0;myid<nthreads;++myid) {
      for (i=0;i<graph->mynvtxs[myid];++i) {
        vsum += graph->vwgt[myid][i];
      }
    }
  }

  if (graph->uniformadjwgt) {
    asum = graph->nedges;
  } else {
    asum = 0;
    for (myid=0;myid<nthreads;++myid) {
      for (j=0;j<graph->mynedges[myid];++j) {
        asum += graph->adjwgt[myid][j];
      }
    }
  }

  graph->tvwgt = vsum;
  graph->tadjwgt = asum;
  graph->invtvwgt = 1.0/(graph->tvwgt > 0 ? graph->tvwgt : 1);
}


void graph_alloc_partmemory(
    ctrl_type * const ctrl,
    graph_type * const graph)
{
  tid_type myid;

  tid_type const nthreads = graph->dist.nthreads;

  /* memory for the partition/refinement structure */
  graph->where = r_pid_alloc(nthreads);
  graph->pwgts = wgt_alloc(ctrl->nparts);

  for (myid=0;myid<nthreads;++myid) {
    graph->where[myid] = pid_alloc(graph->mynvtxs[myid]);
  }
}


void graph_free(
    graph_type * graph)
{
  tid_type myid;

  /* free partition/refinement structure */
  graph_free_rdata(graph);

  /* free individual arrays */
  for (myid=0;myid<graph->dist.nthreads;++myid) {
    S_graph_free_part(graph,myid);
  }

  dl_free(graph->xadj);
  dl_free(graph->adjncy);
  dl_free(graph->vwgt);
  dl_free(graph->adjwgt);
  dl_free(graph->mynvtxs);
  dl_free(graph->mynedges);

  if (graph->cmap) {
    dl_free(graph->cmap);
  }
  if (graph->label) {
    dl_free(graph->label);
  }
  if (graph->group) {
    dl_free(graph->group);
  }

  dl_free(graph);
}


void graph_free_rdata(
    graph_type * graph)
{
  tid_type myid;
  
  for (myid=0;myid<graph->dist.nthreads;++myid) {
    if (graph->where) {
      dl_free(graph->where[myid]);
    }
    if (graph->rename) {
      dl_free(graph->rename[myid]);
    }
    if (graph->cmap) {
      dl_free(graph->cmap[myid]);
    }
  }

  /* free partition/refinement structure */
  if (graph->pwgts) {
    dl_free(graph->pwgts);
    graph->pwgts = NULL;
  }
  if (graph->where) {
    dl_free(graph->where);
    graph->where = NULL;
  }
  if (graph->rename) {
    dl_free(graph->rename);
    graph->rename = NULL;
  }
  if (graph->cmap) {
    dl_free(graph->cmap);
    graph->cmap = NULL;
  }
  if (graph->vsinfo) {
    vsinfo_free(graph);
  }
  if (graph->esinfo) {
    esinfo_free(graph);
  }
  if (graph->kwinfo) {
    par_kwinfo_free(graph);
  }
}


double graph_imbalance(
    graph_type const * const graph,
    pid_type const nparts,
    real_type const * const pijbm)
{
  vtx_type k;
  double max, cur;

  DL_ASSERT_EQUALS(wgt_lsum(graph->pwgts,nparts),graph->tvwgt,"%"PF_TWGT_T);

  max = 0;

  for (k=0;k<nparts;++k) {
    cur = graph->pwgts[k]*pijbm[k];
    if (cur > max) {
      max = cur;
    }
  }

  return max;
}


double graph_imbalance_diff(
    graph_type const * const graph,
    pid_type const nparts,
    real_type const * const pijbm,
    real_type const ubfactor)
{
  vtx_type k;
  double max, cur;

  DL_ASSERT_EQUALS(wgt_lsum(graph->pwgts,nparts),graph->tvwgt,"%"PF_TWGT_T);

  max = 0;

  for (k =0;k<nparts;++k) {
    cur = graph->pwgts[k]*pijbm[k]-ubfactor;
    if (cur > max) {
      max = cur;
    }
  }

  return max;
}


wgt_type graph_cut(
    graph_type const * const graph,
    pid_type const * const * const gwhere)
{
  vtx_type i, k, lvtx, nbrid;
  adj_type j;
  wgt_type cut;
  tid_type myid;

  tid_type const nthreads = dlthread_get_nthreads(graph->comm);

  vtx_type const * const gmynvtxs = graph->mynvtxs;
  adj_type const * const * const gxadj = (adj_type const **)graph->xadj;
  vtx_type const * const * const gadjncy = (vtx_type const **)graph->adjncy;
  wgt_type const * const * const gadjwgt = (wgt_type const **)graph->adjwgt;

  DL_ASSERT_EQUALS((int)graph->dist.nthreads,(int)nthreads,"%d");

  cut = 0;
  if (graph->uniformadjwgt || graph->adjwgt == NULL) {
    for (myid=0;myid<nthreads;++myid) {
      for (i=0;i<gmynvtxs[myid];++i) {
        for (j=gxadj[myid][i];j<gxadj[myid][i+1];++j) {
          k = gadjncy[myid][j]; 
          if (k < gmynvtxs[myid]) {
            lvtx = k;
            nbrid = myid;
          } else {
            nbrid = gvtx_to_tid(gadjncy[myid][j],graph->dist);
            lvtx = gvtx_to_lvtx(gadjncy[myid][j],graph->dist);
          }
          if (gwhere[myid][i] != gwhere[nbrid][lvtx]) {
            ++cut;
          }
        }
      }
    }
  } else {
    for (myid=0;myid<nthreads;++myid) {
      for (i=0;i<gmynvtxs[myid];++i) {
        for (j=gxadj[myid][i];j<gxadj[myid][i+1];++j) {
          k = gadjncy[myid][j]; 
          if (k < gmynvtxs[myid]) {
            lvtx = k;
            nbrid = myid;
          } else {
            nbrid = gvtx_to_tid(gadjncy[myid][j],graph->dist);
            lvtx = gvtx_to_lvtx(gadjncy[myid][j],graph->dist);
          }
          if (gwhere[myid][i] != gwhere[nbrid][lvtx]) {
            cut += gadjwgt[myid][j];
          }
        }
      }
    }
  }

  return cut/2;
}


int graph_isbalanced(
    ctrl_type const * const ctrl, 
    graph_type const * const graph, 
    real_type const ffactor)
{
  return (graph_imbalance_diff(graph,ctrl->nparts,ctrl->pijbm, \
      ctrl->ubfactor) <= ffactor);
}


void graph_readjust_memory(
    graph_type * const graph,
    adj_type adjsize)
{
  int const myid = dlthread_get_id(graph->comm);
  adj_type const nedges = graph->xadj[myid][graph->mynvtxs[myid]];

  if (adjsize > 4096 && adjsize * 0.75 > nedges) {
    graph->adjncy[myid] = vtx_realloc(graph->adjncy[myid],nedges);
    graph->adjwgt[myid] = wgt_realloc(graph->adjwgt[myid],nedges);
  }
}


size_t graph_size(
    graph_type const * const graph)
{
  size_t nbytes;

  tid_type const nthreads = graph->dist.nthreads;
  vtx_type const nvtxs = graph->nvtxs;
  adj_type const nedges = graph->nedges;

  nbytes = sizeof(graph_type);

  if (graph->group) {
    nbytes += (sizeof(pid_type)*nvtxs) + (sizeof(pid_type*)*nthreads);
  }

  if (graph->mynvtxs) {
    nbytes += sizeof(vtx_type)*nthreads;
  }

  if (graph->mynedges) {
    nbytes += sizeof(adj_type)*nthreads;
  }

  if (graph->xadj) {
    nbytes += (sizeof(adj_type)*(nvtxs+1)) + (sizeof(adj_type*)*nthreads);
  }

  if (graph->vwgt) {
    nbytes += (sizeof(wgt_type)*nvtxs) + (sizeof(wgt_type*)*nthreads);
  }

  if (graph->adjncy) {
    nbytes += (sizeof(vtx_type)*nedges) + (sizeof(vtx_type*)*nthreads);
  }

  if (graph->adjwgt) {
    nbytes += (sizeof(wgt_type)*nedges) + (sizeof(wgt_type*)*nthreads);
  }

  if (graph->cmap) {
    nbytes += (sizeof(vtx_type)*nvtxs) + (sizeof(vtx_type*)*nthreads);
  }

  /* where and pwgts will be ignored for now as they should be moved to a
   * different structure */ 

  if (graph->nislands) {
    nbytes += sizeof(vtx_type)*nthreads;
  }

  if (graph->rename) {
    nbytes += (sizeof(vtx_type)*nvtxs) + (sizeof(vtx_type*)*nthreads);
  }

  if (graph->label) {
    nbytes += (sizeof(vtx_type)*nvtxs) + (sizeof(vtx_type*)*nthreads);
  }

  return nbytes;
}


void graph_calc_dist(
    vtx_type const maxnvtxs, 
    tid_type const nthreads,
    graphdist_type * const dist) 
{
  dist->nthreads = nthreads;
  dist->offset = vtx_uppow2(maxnvtxs+1);
  dist->mask = dist->offset - 1;
  dist->shift = vtx_downlog2(dist->offset);

  DL_ASSERT(maxnvtxs < (vtx_type)(1<<dist->shift),"Shift of %d for %"PF_VTX_T
      " vertices\n",dist->shift,maxnvtxs);
  DL_ASSERT_EQUALS(dist->offset,(vtx_type)(1<<dist->shift),"%"PF_VTX_T);
}




/******************************************************************************
* PUBLIC PARALLEL FUNCTIONS ***************************************************
******************************************************************************/


graph_type * par_graph_create(
    dlthread_comm_t const comm)
{
  graph_type * graph;

  graph = dlthread_get_shmem(sizeof(graph_type),comm);

  S_par_graph_init(graph,comm);

  return graph; 
}


graph_type * par_graph_setup(
    vtx_type const nvtxs, 
    adj_type * const xadj, 
    vtx_type * const adjncy, 
    wgt_type * const vwgt,
    wgt_type * const adjwgt, 
    dlthread_comm_t const comm) 
{
  wgt_type asum, vsum;
  graph_type * graph;

  tid_type const myid = dlthread_get_id(comm);
  tid_type const nthreads = dlthread_get_nthreads(comm);

  graph = par_graph_create(comm);


  graph->mynvtxs[myid] = nvtxs;
  graph->mynedges[myid] = xadj[nvtxs];
  graph->xadj[myid] = xadj;
  graph->adjncy[myid] = adjncy;
  if (adjwgt) {
    graph->adjwgt[myid] = adjwgt;
    asum = wgt_sum(graph->adjwgt[myid],graph->mynedges[myid]);
    asum = wgt_dlthread_sumreduce(asum,graph->comm);
    graph->free_adjwgt = 0;
  } else {
    asum = xadj[nvtxs];
    graph->adjwgt[myid] = wgt_init_alloc(1,xadj[nvtxs]);
    graph->uniformadjwgt = 1;
  }
  if (vwgt) {
    graph->vwgt[myid] = vwgt;
    vsum = wgt_sum(graph->vwgt[myid],graph->mynvtxs[myid]);
    vsum = wgt_dlthread_sumreduce(vsum,graph->comm);
    graph->free_vwgt = 0;
  } else {
    vsum = nvtxs;
    graph->vwgt[myid] = wgt_init_alloc(1,nvtxs);
    graph->uniformvwgt = 1;
  }


  dlthread_barrier(comm);
  if (myid == 0) {
    graph->nvtxs = vtx_sum(graph->mynvtxs,nthreads);
    graph->nedges = adj_sum(graph->mynedges,nthreads);
    graph_calc_dist(vtx_max_value(graph->mynvtxs,nthreads),nthreads, \
        &(graph->dist));

    graph->gnvtxs = lvtx_to_gvtx(vtx_max_value(graph->mynvtxs,nthreads), \
        nthreads-1,graph->dist);

    if (graph->free_adjwgt) {
      /* we have all 1's for edge weight */
      graph->tadjwgt = graph->nedges;
    }
    if (graph->free_vwgt) {
      /* we have all 1's for vertex wegiht */
      graph->tvwgt = graph->nvtxs;
    }
    graph->invtvwgt = 1.0/(graph->tvwgt > 0 ? graph->tvwgt : 1);
  }
  dlthread_barrier(comm);

  par_graph_setup_twgts(graph);

  DL_ASSERT(check_graph(graph),"Bad graph");

  return graph;
}


void par_graph_setup_twgts(
    graph_type * const graph)
{
  vtx_type i;
  adj_type j;
  twgt_type vsum, asum;

  tid_type const myid = dlthread_get_id(graph->comm);

  if (graph->uniformvwgt) {
    vsum = graph->nvtxs;
  } else {
    vsum = 0;
    for (i=0;i<graph->mynvtxs[myid];++i) {
      vsum += graph->vwgt[myid][i];
    }
    vsum = twgt_dlthread_sumreduce(vsum,graph->comm);
  }
  if (graph->uniformadjwgt) {
    asum = graph->nedges;
  } else {
    asum = 0;
    for (j=0;j<graph->mynedges[myid];++j) {
      asum += graph->adjwgt[myid][j];
    }
    asum = twgt_dlthread_sumreduce(asum,graph->comm);
  }

  if (myid == 0) {
    graph->tvwgt = vsum;
    graph->tadjwgt = asum;
    graph->invtvwgt = 1.0/(graph->tvwgt > 0 ? graph->tvwgt : 1);
  }
  dlthread_barrier(graph->comm);
}


void par_graph_free(
    graph_type * graph)
{
  tid_type const myid = dlthread_get_id(graph->comm);

  S_graph_free_part(graph,myid);

  /* free partition/refinement structure */
  par_graph_free_rdata(graph);

  dlthread_barrier(graph->comm);
  if (myid == 0) {
    dl_free(graph->xadj);
    dl_free(graph->adjncy);
    dl_free(graph->vwgt);
    dl_free(graph->adjwgt);
    dl_free(graph->mynvtxs);
    dl_free(graph->mynedges);

    if (graph->cmap) {
      dl_free(graph->cmap);
    }
    if (graph->label) {
      dl_free(graph->label);
    }
    if (graph->group) {
      dl_free(graph->group);
    }

    dl_free(graph);
  }
}


void par_graph_free_rdata(
    graph_type * graph)
{
  tid_type const myid = dlthread_get_id(graph->comm);

  if (graph->where) {
    dl_free(graph->where[myid]);
  }
  if (graph->rename) {
    dl_free(graph->rename[myid]);
  }
  if (graph->cmap) {
    dl_free(graph->cmap[myid]);
  }

  if (graph->vsinfo) {
    par_vsinfo_free(graph);
  }
  if (graph->esinfo) {
    par_esinfo_free(graph);
  }
  if (graph->kwinfo) {
    par_kwinfo_free(graph);
  }

  dlthread_barrier(graph->comm);

  if (myid == 0) {
    /* free partition/refinement structure */
    if (graph->pwgts) {
      dl_free(graph->pwgts);
      graph->pwgts = NULL;
    }
    if (graph->where) {
      dl_free(graph->where);
      graph->where = NULL;
    }
    if (graph->rename) {
      dl_free(graph->rename);
      graph->rename = NULL;
    }
    if (graph->cmap) {
      dl_free(graph->cmap);
      graph->cmap = NULL;
    }
  }
}


void par_graph_gather(
  graph_type const * const graph,
  adj_type ** const r_xadj,
  vtx_type ** const r_adjncy,
  wgt_type ** const r_vwgt,
  wgt_type ** const r_adjwgt,
  vtx_type * const r_voff)
{
  vtx_type i, k, voff, v;
  adj_type j, eoff;
  tid_type t;
  adj_type * gxadj;
  vtx_type * gadjncy;
  wgt_type * gvwgt, * gadjwgt;

  /* unified graph parts */
  adj_type * uxadj;
  vtx_type * uadjncy;
  wgt_type * uvwgt;
  wgt_type * uadjwgt;
  vtx_type * uprefix;
  adj_type * unedges;

  tid_type const myid = dlthread_get_id(graph->comm);

  vtx_type const mynvtxs = graph->mynvtxs[myid];
  adj_type const mynedges = graph->mynedges[myid];
  adj_type const * const xadj = graph->xadj[myid];
  vtx_type const * const adjncy = graph->adjncy[myid];
  wgt_type const * const vwgt = graph->vwgt[myid];
  wgt_type const * const adjwgt = graph->adjwgt[myid];

  int const do_vwgt = !graph->uniformvwgt;
  int const do_adjwgt = !graph->uniformadjwgt;

  DL_ASSERT_EQUALS(mynedges,xadj[mynvtxs],"%"PF_ADJ_T);
  DL_ASSERT_EQUALS(adj_sum(graph->mynedges,graph->dist.nthreads), \
      graph->nedges,"%"PF_ADJ_T);

  S_par_graph_alloc_unified(graph,&uxadj,&uadjncy,&uvwgt,&uadjwgt,&uprefix, \
      &unedges);

  voff = uprefix[myid];
  eoff = unedges[myid];
  gxadj = uxadj + voff;
  gadjncy = uadjncy + eoff;
  gvwgt = uvwgt + voff;
  gadjwgt = uadjwgt + eoff;

  /* vertex ids are purely based on thread offsets */
  eoff = gxadj[0] = unedges[myid];
  for (i=1;i<mynvtxs;++i) {
    gxadj[i] = xadj[i] + eoff; 
  }

  /* insert edges into graph */
  for (i=0;i<mynvtxs;++i) {
    for (j=xadj[i];j<xadj[i+1];++j) {
      k = adjncy[j];
      if (k < mynvtxs) {
        t = myid;
        v = k;
      } else {
        t = gvtx_to_tid(k,graph->dist);
        v = gvtx_to_lvtx(k,graph->dist);
      }
      gadjncy[j] = v + uprefix[t];
    }
  }

  /* propagate weights */
  if (do_vwgt) {
    wgt_copy(gvwgt,vwgt,mynvtxs);
  } else {
    wgt_set(gvwgt,1,mynvtxs);
  }
  if (do_adjwgt) {
    wgt_copy(gadjwgt,adjwgt,mynedges);
  } else {
    wgt_set(gadjwgt,1,mynedges);
  }

  dlthread_barrier(graph->comm);
  if (myid == 0) {
    dl_free(unedges);
    dl_free(uprefix);
  }

  /* assign pointers */
  *r_xadj = uxadj;
  *r_adjncy = uadjncy;
  *r_vwgt = uvwgt;
  *r_adjwgt = uadjwgt;
  *r_voff = voff;
}


void par_graph_shuffle(
    ctrl_type * const ctrl,
    graph_type * const graph,
    pid_type const * const * const gwhere,
    int const wgts)
{
  vtx_type v, g, i, k, l, lvtx, smynvtxs, maxnvtxs;
  adj_type j, smynedges;
  tid_type nbrid, t, o;
  pid_type me;
  graphdist_type dist;
  pid_type * group = NULL;
  vtx_type * adjncy, * label, * vold;
  adj_type * myeprefix, * xadj;
  wgt_type * vwgt, * adjwgt;
  vtx_type ** vprefix, ** vlist, ** grename, ** myvprefix;
  adj_type ** eprefix;

  tid_type const nthreads = dlthread_get_nthreads(ctrl->comm);
  tid_type const myid = dlthread_get_id(ctrl->comm);

  vtx_type const * const gmynvtxs = graph->mynvtxs;
  adj_type const * const * const gxadj = (adj_type const **)graph->xadj;
  vtx_type const * const * const gadjncy = (vtx_type const **)graph->adjncy; 
  wgt_type const * const * const gvwgt = (wgt_type const **)graph->vwgt;
  wgt_type const * const * const gadjwgt = (wgt_type const **)graph->adjwgt;
  vtx_type const * const * const glabel = (vtx_type const **)graph->label;

  /* should change this to intelligently think about the weights  --
  int const do_vwgt = !graph->uniformvwgt;
  int const do_adjwgt = !graph->uniformadjwgt; */

  vprefix = dlthread_get_shmem((sizeof(vtx_type*)*nthreads) + \
      (sizeof(adj_type*)*nthreads) + (sizeof(vtx_type*)*nthreads) + \
      (sizeof(vtx_type*)*nthreads) + (sizeof(vtx_type*)*nthreads),ctrl->comm);
  eprefix = (adj_type**)(vprefix+nthreads);
  vlist = (vtx_type**)(eprefix+nthreads);
  grename = (vtx_type**)(vlist+nthreads);
  myvprefix = (vtx_type**)(grename+nthreads);

  vprefix[myid] = vtx_init_alloc(0,nthreads+1);
  eprefix[myid] = adj_init_alloc(0,nthreads);
  myvprefix[myid] = vtx_alloc(nthreads+1);

  vprefix[myid][nthreads] = 0;

  vlist[myid] = vtx_alloc(gmynvtxs[myid]);
  grename[myid] = vtx_alloc(gmynvtxs[myid]);

  /* We first go through and count how many vertices and edges each thread is 
   * going to own. */
  for (i=0;i<gmynvtxs[myid];++i) {
    me = gwhere[myid][i]; 
    ++vprefix[myid][me];
    eprefix[myid][me] += gxadj[myid][i+1] - gxadj[myid][i];
  }

  myeprefix = adj_alloc(nthreads+1);
  vold = vtx_alloc(nthreads);

  dlthread_barrier(ctrl->comm);

  /* each thread then gathers its totals */
  for (o=0;o<nthreads;++o) {
    t = (o + myid) % nthreads;
    myvprefix[myid][t] = vprefix[t][myid];
    myeprefix[t] = eprefix[t][myid];
  }
  myvprefix[myid][nthreads] = 0;
  myeprefix[nthreads] = 0;

  vtx_prefixsum_exc(myvprefix[myid],nthreads+1);
  adj_prefixsum_exc(myeprefix,nthreads+1);

  smynvtxs = myvprefix[myid][nthreads];
  smynedges = myeprefix[nthreads];

  /* implicit barrier */
  maxnvtxs = vtx_dlthread_maxreduce_value(smynvtxs,ctrl->comm);
  graph_calc_dist(maxnvtxs,nthreads,&dist);

  /* thread creates an incoming and outgoing prefixsum */
  vtx_prefixsum_exc(vprefix[myid],nthreads+1);

  /* copy our initial offsets */
  vtx_copy(vold,vprefix[myid],nthreads);

  /* create outgoing vlist and rename vectors */
  for (i=0;i<gmynvtxs[myid];++i) {
    me = gwhere[myid][i]; 
    l = myvprefix[me][myid] + (vprefix[myid][me] - vold[me]);
    DL_ASSERT(l<myvprefix[me][nthreads],"Bad local vertex number: %"PF_VTX_T \
        "/%"PF_VTX_T"\n",l,myvprefix[me][nthreads]);
    /* the global vertex is determined by the myvprefix of the destination
     * thread */
    grename[myid][i] = lvtx_to_gvtx(l,me,dist);
    vlist[myid][vprefix[myid][me]++] = i;
  }

  /* de-shift vprefix */
  for (t=nthreads;t>0;--t) {
    vprefix[myid][t] = vprefix[myid][t-1];
  }
  vprefix[myid][0] = 0;

  dlthread_barrier(ctrl->comm);

  /* allocate arrays for my new graph */
  xadj = adj_alloc(smynvtxs+1);
  adjncy = vtx_alloc(smynedges);
  label = vtx_alloc(smynvtxs);

  /* copy group information */
  if (graph->group) {
    group = pid_alloc(smynvtxs);
    smynvtxs = 0;
    for (t=0;t<nthreads;++t) {
      for (i=vprefix[t][myid];i<vprefix[t][myid+1];++i) {
        v = vlist[t][i];
        group[smynvtxs] = graph->group[t][v];
        ++smynvtxs;
      }
    }
  }

  /* build my graph using the prefix sum arrays */
  if (wgts) {
    vwgt = wgt_alloc(smynvtxs);
    adjwgt = wgt_alloc(smynedges);
    smynvtxs = 0;
    smynedges = 0;
    for (t=0;t<nthreads;++t) {
      DL_ASSERT_EQUALS(smynvtxs,myvprefix[myid][t],"%"PF_VTX_T);
      for (i=vprefix[t][myid];i<vprefix[t][myid+1];++i) {
        v = vlist[t][i];
        label[smynvtxs] = glabel[t][v];
        vwgt[smynvtxs] = gvwgt[t][v];
        xadj[smynvtxs] = smynedges;
        for (j=gxadj[t][v];j<gxadj[t][v+1];++j) {
          k = gadjncy[t][j];
          if (k < gmynvtxs[t]) {
            lvtx = k;
            nbrid = t;
          } else {
            lvtx = gvtx_to_lvtx(k,graph->dist);
            nbrid = gvtx_to_tid(k,graph->dist);
          }
          /* the rename array contains the global vertex number */
          g = grename[nbrid][lvtx];
          if (gvtx_to_tid(g,dist) == myid) {
            adjncy[smynedges] = gvtx_to_lvtx(g,dist);
          } else {
            adjncy[smynedges] = g;
          }
          adjwgt[smynedges] = gadjwgt[nbrid][lvtx];
          ++smynedges;
        }
        ++smynvtxs;
      }
    }
  } else {
    vwgt = NULL;
    adjwgt = NULL;
    smynvtxs = 0;
    smynedges = 0;
    for (t=0;t<nthreads;++t) {
      DL_ASSERT_EQUALS(smynvtxs,myvprefix[myid][t],"%"PF_VTX_T);
      for (i=vprefix[t][myid];i<vprefix[t][myid+1];++i) {
        v = vlist[t][i];
        label[smynvtxs] = glabel[t][v];
        xadj[smynvtxs] = smynedges;
        for (j=gxadj[t][v];j<gxadj[t][v+1];++j) {
          k = gadjncy[t][j];
          if (k < gmynvtxs[t]) {
            lvtx = k;
            nbrid = t;
          } else {
            lvtx = gvtx_to_lvtx(k,graph->dist);
            nbrid = gvtx_to_tid(k,graph->dist);
          }
          /* the rename array contains the global vertex number */
          g = grename[nbrid][lvtx];
          if (gvtx_to_tid(g,dist) == myid) {
            adjncy[smynedges] = gvtx_to_lvtx(g,dist);
          } else {
            adjncy[smynedges] = g;
          }
          ++smynedges;
        }
        ++smynvtxs;
      }
    }
  }
  xadj[smynvtxs] = smynedges;

  dlthread_barrier(ctrl->comm);

  /* free intermediate data */
  dl_free(vold);
  dl_free(myeprefix);
  dl_free(myvprefix[myid]);
  dl_free(grename[myid]);
  dl_free(vprefix[myid]);
  dl_free(eprefix[myid]);
  dl_free(vlist[myid]);

  /* free the old graph components */
  dl_free(graph->xadj[myid]);
  dl_free(graph->adjncy[myid]);
  dl_free(graph->vwgt[myid]);
  dl_free(graph->adjwgt[myid]);
  dl_free(graph->label[myid]);

  /* set the new components */
  graph->mynvtxs[myid] = smynvtxs;
  graph->mynedges[myid] = smynedges;
  graph->xadj[myid] = xadj;
  graph->adjncy[myid] = adjncy;
  if (vwgt) {
    graph->vwgt[myid] = vwgt;
  } else {
    graph->vwgt[myid] = wgt_init_alloc(1,smynvtxs);
  }
  if (adjwgt) {
    graph->adjwgt[myid] = adjwgt;
  } else {
    graph->adjwgt[myid] = wgt_init_alloc(1,smynedges);
  }
  graph->label[myid] = label;
  graph->dist = dist;

  if (graph->group) {
    dl_free(graph->group[myid]);
    graph->group[myid] = group;
  }

  /* implicit barrier */
  dlthread_free_shmem(vprefix,ctrl->comm);

  DL_ASSERT(check_graph(graph),"Invalid graph after shuffle");
}


graph_type * par_graph_setup_coarse(
    graph_type * const graph, 
    vtx_type const cnvtxs)
{
  vtx_type mynvtxs;
  graph_type * cgraph;

  tid_type const myid = dlthread_get_id(graph->comm);
  tid_type const nthreads = dlthread_get_nthreads(graph->comm);

  cgraph = par_graph_create(graph->comm);

  if (myid == 0) {
    graph->coarser = cgraph;
    cgraph->finer = graph;

    cgraph->level = graph->level + 1;

    cgraph->tvwgt = graph->tvwgt;
    cgraph->invtvwgt = graph->invtvwgt;
  }
  dlthread_barrier(graph->comm);

  cgraph = graph->coarser;

  DL_ASSERT(cgraph != NULL,"cgraph is NULL");

  cgraph->mynvtxs[myid] = cnvtxs;

  /* Allocate memory for the coarser graph */
  mynvtxs = cnvtxs;

  cgraph->xadj[myid] = adj_alloc(mynvtxs+1);
  cgraph->vwgt[myid] = wgt_alloc(mynvtxs);

  cgraph->adjncy[myid] = NULL;
  cgraph->adjwgt[myid] = NULL;

  mynvtxs = vtx_dlthread_sumreduce(mynvtxs,graph->comm);

  if (myid == 0) {
    graph_calc_dist(vtx_max_value(cgraph->mynvtxs,nthreads),nthreads, \
        &cgraph->dist);

    cgraph->gnvtxs = max_gvtx(cgraph);
    cgraph->nvtxs = mynvtxs;
    DL_ASSERT(cgraph->gnvtxs >= cgraph->nvtxs,"Bad gnvtxs of %"PF_VTX_T"/%" \
        PF_VTX_T,cgraph->gnvtxs,cgraph->nvtxs);
    cgraph->comm = graph->comm;
  }
  dlthread_barrier(graph->comm);

  DL_ASSERT(cgraph->finer != NULL,"Failed to set cgraph->finer");
  DL_ASSERT(graph->coarser != NULL,"Failed to set graph->coarser");

  return cgraph;
}


void par_graph_alloc_partmemory(
    ctrl_type * const ctrl,
    graph_type * const graph)
{
  tid_type const nthreads = dlthread_get_nthreads(graph->comm);
  tid_type const myid = dlthread_get_id(graph->comm);

  DL_ASSERT_EQUALS(nthreads,graph->dist.nthreads,"%"PF_TID_T);

  if (myid == 0) {
    /* memory for the partition/refinement structure */
    graph->where = r_pid_alloc(nthreads);
    graph->pwgts = wgt_alloc(ctrl->nparts);
  }
  dlthread_barrier(graph->comm);

  graph->where[myid] = pid_alloc(graph->mynvtxs[myid]);
}


tid_type par_graph_extract_halves(
    graph_type * const graph,
    pid_type const * const * const gwhere,
    graph_type ** const halves)
{
  tid_type mygroup;

  if (graph->group) {
    mygroup = S_par_graph_extract_halves_group(graph,gwhere,halves);
  } else {
    mygroup = S_par_graph_extract_halves_nogroup(graph,gwhere,halves);
  }

  return mygroup;
}


adj_type * par_graph_build_radj(
    graph_type const * const graph)
{
  vtx_type i, k, kk, lvtx, olvtx;
  tid_type nbrid, onbrid;
  adj_type j, jj;
  adj_type * radj;

  tid_type const myid = dlthread_get_id(graph->comm);

  vtx_type const mynvtxs = graph->mynvtxs[myid];
  adj_type const nedges = graph->xadj[myid][mynvtxs];

  vtx_type const * const gmynvtxs = graph->mynvtxs;
  adj_type const * const * const gxadj = (adj_type const **)graph->xadj;
  vtx_type const * const * const gadjncy = (vtx_type const **)graph->adjncy;

  radj = adj_alloc(nedges);

  /* populate my radj */
  for (i=0;i<mynvtxs;++i) {
    for (j=gxadj[myid][i];j<gxadj[myid][i+1];++j) {
      k = gadjncy[myid][j];
      if (k < mynvtxs) {
        lvtx = k;
        nbrid = myid;
      } else {
        lvtx = gvtx_to_lvtx(k,graph->dist);
        nbrid = gvtx_to_tid(k,graph->dist);
      }
      for (jj=gxadj[nbrid][lvtx];jj<gxadj[nbrid][lvtx+1];++jj) {
        kk = gadjncy[nbrid][jj];
        if (kk < gmynvtxs[nbrid]) {
          olvtx = kk;
          onbrid = nbrid;
        } else {
          olvtx = gvtx_to_lvtx(kk,graph->dist);
          onbrid = gvtx_to_tid(kk,graph->dist);
        }
        if (onbrid == myid && olvtx == i) {
          radj[j] = jj;
          break;
        }
      }
    }
  }

  return radj;
}


void par_graph_intext_vtx(
    graph_type const * const graph,
    vtx_type * const r_nint,
    vtx_type * const r_next)
{
  vtx_type i, k;
  adj_type j;
  vtx_type next, nint;
  
  tid_type const myid = dlthread_get_id(graph->comm);

  vtx_type const mynvtxs = graph->mynvtxs[myid];
  adj_type const * const xadj = graph->xadj[myid];
  vtx_type const * const adjncy = graph->adjncy[myid];

  next = 0;
  nint = 0;

  for (i=0;i<mynvtxs;++i) {
    for (j=xadj[i];j<xadj[i+1];++j) {
      k = adjncy[j];
      if (k >= mynvtxs) {
        ++next;
        break;
      }
    }
    if (j == xadj[i+1]) {
      ++nint;
    }
  }

  if (r_nint) {
    *r_nint = nint;
  }
  if (r_next) {
    *r_next = next;
  }
}


wgt_type par_graph_cut(
    graph_type const * const graph,
    pid_type const * const * const where)
{
  vtx_type i, k, lvtx, nbrid;
  adj_type j;
  wgt_type cut;

  tid_type const myid = dlthread_get_id(graph->comm);

  vtx_type const mynvtxs = graph->mynvtxs[myid];
  adj_type const * const xadj = graph->xadj[myid];
  vtx_type const * const adjncy = graph->adjncy[myid];
  wgt_type const * const adjwgt = graph->adjwgt[myid];
  pid_type const * const mywhere = where[myid];

  DL_ASSERT_EQUALS((int)graph->dist.nthreads, \
      (int)dlthread_get_nthreads(graph->comm),"%d");

  cut = 0;

  if (graph->uniformadjwgt || graph->adjwgt == NULL) {
    for (i =0; i<mynvtxs; ++i) {
      for (j =xadj[i]; j<xadj[i+1]; ++j) {
        k = adjncy[j]; 
        if (k < mynvtxs) {
          lvtx = k;
          nbrid = myid;
        } else {
          nbrid = gvtx_to_tid(adjncy[j],graph->dist);
          lvtx = gvtx_to_lvtx(adjncy[j],graph->dist);
        }
        if (mywhere[i] != where[nbrid][lvtx]) {
          ++cut;
        }
      }
    }
  } else {
    for (i =0; i<mynvtxs; ++i) {
      for (j =xadj[i]; j<xadj[i+1]; ++j) {
        k = adjncy[j];
        if (k < mynvtxs) {
          lvtx = k;
          nbrid = myid;
        } else {
          nbrid = gvtx_to_tid(adjncy[j],graph->dist);
          lvtx = gvtx_to_lvtx(adjncy[j],graph->dist);
        }
        if (mywhere[i] != where[nbrid][lvtx]) {
          cut += adjwgt[j];
        }
      }
    }
  }
  cut = wgt_dlthread_sumreduce(cut,graph->comm);

  return cut/2;
}


void par_graph_removeislands(
    ctrl_type * const ctrl,
    graph_type * const graph)
{
  vtx_type i, k, nislands, nvtxs, lvtx, mynvtxs;
  adj_type j;
  pid_type p;
  tid_type nbrid;
  wgt_type iwgt;
  adj_type * xadj; 
  wgt_type * vwgt, * ivwgt;
  vtx_type * rename, * adjncy;
  vtx_type ** grename, ** glabel;

  tid_type const myid = dlthread_get_id(ctrl->comm);
  tid_type const nthreads = dlthread_get_nthreads(ctrl->comm);

  int const do_vwgt = !graph->uniformvwgt;

  mynvtxs = graph->mynvtxs[myid];
  xadj = graph->xadj[myid];
  adjncy = graph->adjncy[myid];
  vwgt = graph->vwgt[myid];

  /* see if there are islands */
  iwgt = 0;
  for (i=0;i<mynvtxs;++i) {
    if (xadj[i+1] == xadj[i]) {
      if (do_vwgt) {
        iwgt += vwgt[i]; 
      } else {
        ++iwgt;
      }
    }
  }

  /* implicit barrier */
  iwgt = wgt_dlthread_sumreduce(iwgt,ctrl->comm);

  if (iwgt < MIN_ISLAND_WEIGHT * graph->tvwgt) {
    /* not worth it */
    par_dprintf("Not removing islands: %0.03lf%%\n", \
        100.0*iwgt/(double)graph->tvwgt);
    return;
  }

  par_dprintf("Removing islands: %0.03lf%%\n", \
      100.0*iwgt/(double)graph->tvwgt);

  grename = dlthread_get_shmem(nthreads*sizeof(vtx_type*),ctrl->comm);
  grename[myid] = rename = vtx_alloc(mynvtxs);

  glabel = dlthread_get_shmem(nthreads*sizeof(vtx_type*),ctrl->comm);
  glabel[myid] = vtx_alloc(mynvtxs);

  if (do_vwgt) {
    ivwgt = wgt_alloc(mynvtxs);
  } else {
    ivwgt = NULL;
  }

  /* remove islands */
  iwgt = 0;
  nvtxs = 0;
  nislands = 0;
  for (i=0;i<mynvtxs;++i) {
    if (xadj[i+1] == xadj[i]) {
      ++nislands;
      iwgt += vwgt[i]; 
      /* starts at mynvtxs-1 */
      rename[i] = mynvtxs-nislands;
      if (graph->label) {
        glabel[myid][mynvtxs-nislands] = graph->label[myid][i];
      } else {
        glabel[myid][mynvtxs-nislands] = i;
      }
      if (do_vwgt) {
        ivwgt[mynvtxs-nislands] = vwgt[i];
      }
    } else {
      if (do_vwgt) {
        vwgt[nvtxs] = vwgt[i];
      }
      xadj[nvtxs+1] = xadj[i+1];
      rename[i] = nvtxs;
      if (graph->label) {
        glabel[myid][nvtxs] = graph->label[myid][i];
      } else {
        glabel[myid][nvtxs] = i;
      }
      ++nvtxs;
    }
  }

  dlthread_barrier(ctrl->comm);

  /* adjust edges */
  for (i=0;i<nvtxs;++i) {
    for (j=xadj[i];j<xadj[i+1];++j) {
      k = adjncy[j];
      if (k < mynvtxs) {
        adjncy[j] = rename[k];
      } else {
        lvtx = gvtx_to_lvtx(k,graph->dist);
        nbrid = gvtx_to_tid(k,graph->dist);
        adjncy[j] = lvtx_to_gvtx(grename[nbrid][lvtx],nbrid,graph->dist);  
      }
    }
  }

  /* insert islands at the end */
  if (do_vwgt) {
    wgt_copy(vwgt+nvtxs,ivwgt+nvtxs,nislands);
    dl_free(ivwgt);
  }

  if (graph->label) {
    dl_free(graph->label[myid]);
    dlthread_barrier(ctrl->comm);
  }

  /* adjust ctrl */
  if (myid == 0) {
    ctrl->ubfactor *= graph->tvwgt/(real_type)(graph->tvwgt - iwgt);

    graph->tvwgt -= iwgt;
    graph->invtvwgt = 1.0 / graph->tvwgt;

    if (ctrl->pijbm) {
      for (p=0;p<ctrl->nparts;++p) {
        ctrl->pijbm[p] = graph->invtvwgt / ctrl->tpwgts[p];
      }
    }

    if (graph->label) {
      dl_free(graph->label);
    }
    graph->label = glabel;
    graph->nislands = vtx_alloc(nthreads);
  }
  dlthread_barrier(ctrl->comm);

  /* adjust numbers */
  graph->mynvtxs[myid] = nvtxs;
  graph->nislands[myid] = nislands;

  /* implicit barrier */
  dl_free(rename);
  dlthread_free_shmem(grename,ctrl->comm);

  if (myid == 0) {
    graph->nvtxs = vtx_sum(graph->mynvtxs,nthreads);
  }

  par_dprintf("Removed %"PF_VTX_T" islands for new balance constraint of %" \
      PF_REAL_T"\n",nislands,ctrl->ubfactor);
}


void par_graph_restoreislands(
    ctrl_type * const ctrl,
    graph_type * const graph,
    pid_type * const * const gwhere)
{
  vtx_type i, mynvtxs;
  pid_type p, nparts;
  wgt_type iwgt, excess, twgt, uwgt;
  wgt_type * lpwgts;
  double * fpwgts;

  tid_type const myid = dlthread_get_id(ctrl->comm);
  tid_type const nthreads = dlthread_get_nthreads(ctrl->comm);

  wgt_type const * const vwgt = graph->vwgt[myid];

  int const do_vwgt = !graph->uniformvwgt;

  switch (ctrl->ptype) {
    case MTMETIS_PTYPE_ND:
    case MTMETIS_PTYPE_VSEP:
      nparts = 2;
      break;
    case MTMETIS_PTYPE_ESEP:
    case MTMETIS_PTYPE_RB:
    case MTMETIS_PTYPE_KWAY:
    default:
      nparts = ctrl->nparts;
  }

  mynvtxs = graph->mynvtxs[myid];
  lpwgts = wgt_init_alloc(0,nparts);

  /* restore */
  if (do_vwgt) {
    iwgt = wgt_sum(vwgt+mynvtxs,graph->nislands[myid]);
    twgt = wgt_dlthread_sumreduce(iwgt,ctrl->comm);
  } else {
    iwgt = graph->nislands[myid];
    twgt = vtx_sum(graph->nislands,nthreads);
  }
  graph->mynvtxs[myid] += graph->nislands[myid];

  if (myid == 0) {
    ctrl->ubfactor *= graph->tvwgt/(real_type)(graph->tvwgt + twgt);

    graph->tvwgt += twgt;
    graph->invtvwgt = 1.0 / graph->tvwgt;

    if (ctrl->pijbm) {
      for (p=0;p<ctrl->nparts;++p) {
        ctrl->pijbm[p] = graph->invtvwgt / ctrl->tpwgts[p];
      }
    }
  }

  /* calculate fillable pwgts */
  fpwgts = dlthread_get_shmem(nparts*sizeof(double),ctrl->comm);
  if (myid == 0) {
    excess = 0;
    for (p=0;p<nparts;++p) {
      uwgt = (ctrl->tpwgts[p]*graph->tvwgt)-graph->pwgts[p];
      if (uwgt < 0) {
        uwgt = 0;
      }
      fpwgts[p] = uwgt;
      excess += uwgt;
    }
    for (p=0;p<nparts;++p) {
      fpwgts[p] /= excess;
    }
  }
  dlthread_barrier(ctrl->comm);

  /* assign my island vertices to partitions */
  p = myid % nparts;
  for (i=0;i<graph->nislands[myid];++i) {
    while ((lpwgts[p]/(double)iwgt) >= fpwgts[p]) {
      p = (p+1)%nparts;
    }
    gwhere[myid][i+mynvtxs] = p;
    if (do_vwgt) {
      lpwgts[p] += vwgt[i+mynvtxs];
    } else {
      lpwgts[p] += 1;
    }
  }

  wgt_dlthread_sumareduce(lpwgts,nparts,ctrl->comm);
  
  if (myid == 0) {
    graph->nvtxs = vtx_sum(graph->mynvtxs,nthreads);
    for (p=0;p<nparts;++p) {
      graph->pwgts[p] += lpwgts[p];
    }
    dl_free(graph->nislands);
  }

  dl_free(lpwgts);

  /* free unused stuff */
  dlthread_free_shmem(fpwgts,ctrl->comm);
}


void par_graph_extract_parts(
    graph_type * const graph,
    pid_type const * const * const gwhere,
    pid_type const nparts,
    graph_type ** const parts)
{
  /* This funciton needs to handle cases where nparts < nthreads and 
   * nparts > nthreads. The latter will imply that it can be executed serially
   * without issue. We will assume that in hte case that nthreads > nparts,
   * nthreads is divisible by nparts. */
  vtx_type i, k, pnvtxs, deg, g, v, u;
  adj_type j, l;
  pid_type w;
  tid_type o, pmyid, pid, pnthreads;
  dlthread_comm_t hcomm;
  vtx_type ** vprefix;
  vtx_type ** vsuffix;
  vtx_type * nvtxs, * pmynvtxs;

  tid_type const myid = dlthread_get_id(graph->comm);
  tid_type const nthreads = dlthread_get_nthreads(graph->comm);

  /* create my vertex and edge counts */
  nvtxs = vtx_init_alloc(0,nparts);
  for (i=0;i<graph->mynvtxs[myid];++i) {
    w = gwhere[myid][i];
    if (w < nparts) { /* allow for the excluding of separators */
      ++nvtxs[w];
    }
  }

  /* allocate space for prefix and suffix arrays for all parts */
  vprefix = dlthread_get_shmem(sizeof(vtx_type*)*2*nparts,graph->comm);
  vsuffix = vprefix+nparts;

  for (pid=myid%nparts;pid<nparts;pid+=nthreads) { /* everythread */

    /* some make this evenly distribute threads based on partition size */
    pnthreads = (nthreads / nparts) + (nthreads % nparts > 0 ? 1 : 0);

    /* create communicators for my new graphs */
    if (pnthreads > 1) {
      /* each thread will only work on its partition */
      hcomm = dlthread_comm_split(pid,nparts,graph->comm);
    } else {
      /* each thread may work on more than one partition */
      hcomm = DLTHREAD_COMM_SINGLE;
    }

    /* all threads with their respective part(s) */
    parts[pid] = par_graph_create(hcomm);
  }

  for (pid=myid;pid<nparts;pid+=nthreads) { /* lead threads only */
    vprefix[pid] = vtx_alloc(nthreads+1);
    pnthreads = dlthread_get_nthreads(parts[pid]->comm);
    parts[pid]->label = r_vtx_alloc(pnthreads);
  }

  /* setup rename */
  if (myid == 0) {
    graph->rename = r_vtx_alloc(nthreads);
  }
  dlthread_barrier(graph->comm);
  graph->rename[myid] = vtx_alloc(graph->mynvtxs[myid]);

  /* assign prefixes */
  for (pid=0;pid<nparts;++pid) {
    vprefix[pid][myid] = nvtxs[pid]; 
  }

  dlthread_barrier(graph->comm);
  for (pid=myid;pid<nparts;pid+=nthreads) { /* lead threads only */
    pnthreads = dlthread_get_nthreads(parts[pid]->comm);

    /* create prefixsums of the vertices and edges */
    vprefix[pid][nthreads] = 0;
    vtx_prefixsum_exc(vprefix[pid],nthreads+1);

    pnvtxs = vprefix[pid][nthreads];

    /* create prefixsums for actual insertion into split graphs */
    vsuffix[pid] = vtx_alloc(pnthreads);
    for (o=0;o<pnthreads;++o) {
      vsuffix[pid][o] = vtx_chunkstart(o,pnthreads,pnvtxs);
      parts[pid]->mynvtxs[o] = vtx_chunksize(o,pnthreads,pnvtxs);
    }

    graph_calc_dist(vtx_max_value(parts[pid]->mynvtxs,pnthreads),pnthreads, \
        &(parts[pid]->dist));
  }
  dlthread_barrier(graph->comm);

  /* allocate vwgt and xadj */
  for (pid=myid%nparts;pid<nparts;pid+=nthreads) {
    pmyid = dlthread_get_id(parts[pid]->comm);
    pnvtxs = parts[pid]->mynvtxs[pmyid];
    parts[pid]->xadj[pmyid] = adj_alloc(pnvtxs+1);
    parts[pid]->vwgt[pmyid] = wgt_alloc(pnvtxs);
    parts[pid]->label[pmyid] = vtx_alloc(pnvtxs);
  }

  dlthread_barrier(graph->comm);
  /* insert vertex information into graphs */
  pmynvtxs = vtx_init_alloc(0,nparts);
  for (i=0;i<graph->mynvtxs[myid];++i) {
    w = gwhere[myid][i];
    if (w < nparts) {
      u = pmynvtxs[w]++;

      DL_ASSERT_EQUALS(parts[w]->dist.nthreads, \
          (tid_type)dlthread_get_nthreads(parts[w]->comm),"%"PF_TID_T);

      pnvtxs = vprefix[w][nthreads];
      
      /* get total vertex number */
      g = u + vprefix[w][myid];

      DL_ASSERT(g < pnvtxs,"Got vertex number of %"PF_VTX_T"/%"PF_VTX_T" " \
          "from %"PF_VTX_T" and %"PF_VTX_T"\n",g,pnvtxs,u, \
          vprefix[w][myid]);

      /* get new local vertex number */
      pmyid = vtx_chunkid(g,parts[w]->dist.nthreads,pnvtxs); 

      DL_ASSERT(pmyid < parts[w]->dist.nthreads,"Got chunk id of %"PF_TID_T \
          "/%"PF_TID_T" from %"PF_VTX_T", %"PF_TID_T", %"PF_VTX_T"\n",pmyid, \
          parts[w]->dist.nthreads,g,pnthreads,pnvtxs);

      v = g - vsuffix[w][pmyid];

      /* set rename */
      graph->rename[myid][i] = lvtx_to_gvtx(v,pmyid,parts[w]->dist);

      /* set alias as global vertex ID */
      parts[w]->label[pmyid][v] = lvtx_to_gvtx(i,myid,graph->dist);

      /* copy vertex weight */
      parts[w]->vwgt[pmyid][v] = graph->vwgt[myid][i];

      /* copy xadj info */
      deg = 0;
      for (j=graph->xadj[myid][i];j<graph->xadj[myid][i+1];++j) {
        k = graph->adjncy[myid][j];
        if (k < graph->mynvtxs[myid]) {
          o = myid;
        } else {
          o = gvtx_to_tid(k,graph->dist);
          k = gvtx_to_lvtx(k,graph->dist);
        }
        if (gwhere[o][k] == w) {
          ++deg;
        }
      }
      parts[w]->xadj[pmyid][v] = deg;
    }
  }

  dlthread_barrier(graph->comm);

  /* fix respective xadj's */
  for (pid=myid%nparts;pid<nparts;pid+=nthreads) { /* every thread */
    pmyid = dlthread_get_id(parts[pid]->comm);
    pnvtxs = parts[pid]->mynvtxs[pmyid];
    parts[pid]->xadj[pmyid][pnvtxs] = 0;
    adj_prefixsum_exc(parts[pid]->xadj[pmyid],pnvtxs+1);

    parts[pid]->adjncy[pmyid] = \
        vtx_alloc(parts[pid]->xadj[pmyid][pnvtxs]);
    parts[pid]->adjwgt[pmyid] = \
        wgt_alloc(parts[pid]->xadj[pmyid][pnvtxs]);

    parts[pid]->mynedges[pmyid] = parts[pid]->xadj[pmyid][pnvtxs];
  }

  dlthread_barrier(graph->comm);
  /* insert edge information into graphs */
  vtx_set(pmynvtxs,0,nparts);
  for (i=0;i<graph->mynvtxs[myid];++i) {
    w = gwhere[myid][i];
    if (w < nparts) {
      u = pmynvtxs[w]++;
      pnvtxs = vprefix[w][nthreads];
      
      /* get total vertex number */
      g = u + vprefix[w][myid];

      /* get new local vertex number */
      pmyid = vtx_chunkid(g,parts[w]->dist.nthreads,pnvtxs); 
      v = g - vsuffix[w][pmyid];

      l = parts[w]->xadj[pmyid][v];
      for (j=graph->xadj[myid][i];j<graph->xadj[myid][i+1];++j) {
        k = graph->adjncy[myid][j];
        if (k < graph->mynvtxs[myid]) {
          o = myid;
        } else {
          o = gvtx_to_tid(k,graph->dist);
          k = gvtx_to_lvtx(k,graph->dist);
        }
        if (gwhere[o][k] == w) {
          /* calcuate new endpoint */
          u = graph->rename[o][k];
          o = gvtx_to_tid(u,parts[w]->dist);
          if (o == pmyid) {
            k = gvtx_to_lvtx(u,parts[w]->dist);
          } else {
            k = u;
          }

          /* process edge */
          parts[w]->adjncy[pmyid][l] = k;
          parts[w]->adjwgt[pmyid][l] = graph->adjwgt[myid][j];
          ++l;
        }
      }
    }
  }
  dl_free(nvtxs);
  dl_free(pmynvtxs);
  dlthread_barrier(graph->comm);

  for (pid=myid;pid<nparts;pid+=nthreads) { /* lead threads only */
    parts[pid]->nvtxs = vtx_sum(parts[pid]->mynvtxs,parts[pid]->dist.nthreads);
    parts[pid]->gnvtxs = max_gvtx(parts[pid]); 
    parts[pid]->nedges = adj_sum(parts[pid]->mynedges, \
        parts[pid]->dist.nthreads);

    dl_free(vprefix[pid]);
    dl_free(vsuffix[pid]);
  }

  for (pid=myid%nparts;pid<nparts;pid+=nthreads) {
    par_graph_setup_twgts(parts[pid]);
  }

  /* implicit barrier */
  dlthread_free_shmem(vprefix,graph->comm); /* vsuffix is part of this */
}


graph_type * par_graph_distribute(
    int const distribution,
    vtx_type const nvtxs, 
    adj_type const * const xadj, 
    vtx_type const * const adjncy, 
    wgt_type const * const vwgt,
    wgt_type const * const adjwgt, 
    dlthread_comm_t const comm)
{
  vtx_type i, k, v, deg, mynvtxs, lvtx;
  adj_type j,l;
  tid_type nbrid;
  tid_type * owner;
  vtx_type * dmynvtxs, * rename;
  adj_type * dmynedges;
  adj_type ** dxadj;
  vtx_type ** dadjncy, ** dlabel;
  wgt_type ** dadjwgt = NULL, ** dvwgt = NULL;
  graphdist_type dist;
  graph_type * graph;

  tid_type const myid = dlthread_get_id(comm);
  tid_type const nthreads = dlthread_get_nthreads(comm);

  graph = par_graph_create(comm);

  owner = dlthread_get_shmem((sizeof(*owner)*nvtxs) + \
      (sizeof(*rename)*nvtxs),comm);
  rename = (vtx_type*)(owner + nvtxs);

  /* set arrays from graph*/
  dmynvtxs = graph->mynvtxs;
  dmynedges = graph->mynedges;
  dxadj = graph->xadj;
  dadjncy = graph->adjncy;
  dadjwgt = graph->adjwgt;
  dvwgt = graph->vwgt;

  if (myid == 0) {
    /* labels must be explicitly allocated */
    graph->label = r_vtx_alloc(nthreads);

    /* zero out vertices and edges */
    vtx_set(dmynvtxs,0,nthreads);
    adj_set(dmynedges,0,nthreads);
  }
  dlthread_barrier(comm);
  dlabel = graph->label;

  /* handle different distributions */
  switch(distribution) {
    case MTMETIS_DISTRIBUTION_BLOCK:
      S_par_distribute_block(nvtxs,xadj,dmynvtxs,dmynedges,dlabel,rename, \
          owner,comm);
      break;
    case MTMETIS_DISTRIBUTION_CYCLIC:
      S_par_distribute_cyclic(nvtxs,xadj,dmynvtxs,dmynedges,dlabel,rename, \
          owner,comm);
      break;
    case MTMETIS_DISTRIBUTION_BLOCKCYCLIC:
      S_par_distribute_blockcyclic(nvtxs,xadj,dmynvtxs,dmynedges,dlabel, \
         rename,owner,4096,comm);
      break;
    default:
      dl_error("Unknown distribution '%d'\n",distribution);
  }

  graph_calc_dist(vtx_max_value(dmynvtxs,nthreads),nthreads,&dist);

  /* allocate arrays */
  mynvtxs = dmynvtxs[myid];
  dxadj[myid] = adj_alloc(mynvtxs+1);
  dxadj[myid][0] = 0;
  dadjncy[myid] = vtx_alloc(dmynedges[myid]);
  dvwgt[myid] = wgt_alloc(mynvtxs);
  dadjwgt[myid] = wgt_alloc(dmynedges[myid]);

  /* zero counts for insertion later */
  dmynedges[myid] = 0;

  /* populate edge arrays */
  l = 0;
  dxadj[myid][0] = 0;
  for (v=0;v<mynvtxs;++v) {
    i = dlabel[myid][v];
    deg = xadj[i+1] - xadj[i];
    dxadj[myid][v+1] = dxadj[myid][v] + deg;
    for (j=xadj[i];j<xadj[i+1];++j) {
      k = adjncy[j];
      nbrid = owner[k];
      lvtx = rename[k];
      if (nbrid == myid) {
        dadjncy[myid][l] = lvtx;
      } else {
        dadjncy[myid][l] = lvtx_to_gvtx(lvtx,nbrid,dist);
      }
      if (adjwgt) {
        dadjwgt[myid][l++] = adjwgt[j];
      } else {
        dadjwgt[myid][l++] = 1;
      }
    }
    dmynedges[myid] = l;
  }

  /* populate vertex weights */
  if (vwgt) {
    for (v=0;v<mynvtxs;++v) {
      i = dlabel[myid][v];
      dvwgt[myid][v] = vwgt[i];
    }
  } else {
    wgt_set(dvwgt[myid],1,mynvtxs);
  }

  /* free owner and rename */
  dlthread_free_shmem(owner,comm);

  if (myid == 0) {
    /* setup the graph */
    graph->gnvtxs = lvtx_to_gvtx(vtx_max_value(dmynvtxs,nthreads),nthreads-1, \
        dist);
    graph->nvtxs = nvtxs;
    graph->nedges = xadj[nvtxs];
    graph->dist = dist;

    /* set free configuration */
    graph->free_xadj = 1;
    graph->free_adjncy = 1;
    graph->free_adjwgt = 1;
    graph->free_vwgt = 1;
  }

  par_graph_setup_twgts(graph);

  return graph;
}




#endif
