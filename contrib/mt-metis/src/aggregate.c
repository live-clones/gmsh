/**
 * @file aggregate.c
 * @brief Functions for matching and grouping vertices together (aggregation). 
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright 2012-2015, Regents of the University of Minnesota
 * @version 1
 * @date 2012-01-08
 */




#ifndef MTMETIS_AGGREGATE_C
#define MTMETIS_AGGREGATE_C



#include "aggregate.h"
#include "check.h"




/******************************************************************************
* TYPES ***********************************************************************
******************************************************************************/


typedef struct adjhash_type {
  vtx_type val;
  uint64_t key;
} adjhash_type;




/******************************************************************************
* DOMLIB IMPORTS **************************************************************
******************************************************************************/


#define DLSORTKV_PREFIX vv
#define DLSORTKV_KEY_T vtx_type
#define DLSORTKV_VAL_T vtx_type
#define DLSORTKV_STATIC
#include "dlsortkv_headers.h"
#undef DLSORTKV_STATIC
#undef DLSORTKV_VAL_T
#undef DLSORTKV_KEY_T
#undef DLSORTKV_PREFIX


#define DLSORT_PREFIX ah
#define DLSORT_TYPE_T adjhash_type
#define DLSORT_COMPARE(a,b) ((a).key < (b).key)
#define DLSORT_STATIC
#include "dlsort_headers.h"
#undef DLSORT_STATIC
#undef DLSORT_COMPARE
#undef DLSORT_TYPE_T
#undef DLSORT_PREFIX


#define DLHT_PREFIX vw
#define DLHT_KEY_T vtx_type
#define DLHT_VAL_T wgt_type
#define DLHT_STATIC
#include "dlht_headers.h"
#undef DLHT_STATIC
#undef DLHT_VAL_T
#undef DLHT_KEY_T
#undef DLHT_PREFIX




/******************************************************************************
* CONSTANTS *******************************************************************
******************************************************************************/


#define CYCLE_MASK_SIZE (0x100000)
static vtx_type const CYCLE_MASK = CYCLE_MASK_SIZE-1;
static vtx_type const MAX_CYCLE_SIZE = CYCLE_MASK_SIZE >> 1;
static double const LEAF_MATCH_RATIO = 0.25;
static vtx_type const MAXDEG_LEAF = 1;
static vtx_type const MAXDEG_TWIN = 64;





/******************************************************************************
* INLINE FUNCTIONS ************************************************************
******************************************************************************/


/**
 * @brief Determine if v is the 'lead' vertex. That is, if the thread owning v
 * will own the resulting coarse vertex.
 *
 * @param v The vertex this thread owns.
 * @param u The neighboring vertex being collapsed with v.
 * @param dv The degree of v.
 * @param du The degree of u.
 *
 * @return 1 if v is lead vertex, and 0 if u is the lead vertex. 
 */
static inline int my_cvtx(
    vtx_type const v,
    vtx_type const u,
    vtx_type const dv,
    vtx_type const du)
{
  if (v == u) {
    /* I own my vertex if it's matched with itself */
    return 1;
  } else if (dv > du) {
    /* The greater degree vertex stays */
    return 1;
  } else if (dv == du) {
    /* break ties */
    if ((v+u)%2 == 0) {
      if (v > u) {
        return 1;
      } else {
        return 0;
      }
    } else {
      if (v < u) {
        return 1;
      } else {
        return 0;
      }
    }
  } else {
    /* someone else's vertex */
    return 0;
  } 
}


/**
 * @brief Determine if enough vertices have been aggregated together.
 *
 * @param nvtxs The number of vertices in the graph.
 * @param collapsed The number of vertices that have been collapsed.
 * @param max_agg_rate The minimum ratio of coarse vertices to fine vertices.
 *
 * @return 1 if aggregation should stop.
 */
static inline int S_agg_limit_reached(
    vtx_type const nvtxs, 
    vtx_type const collapsed, 
    double const max_agg_rate)
{
  double agg_rate;
  
  agg_rate = (double)(nvtxs - collapsed);
  return (agg_rate < (double)(max_agg_rate*nvtxs));
}


/**
 * @brief Find an index in the hash table corresponding to the key.
 *
 * @param i The key.
 * @param htable The hashtable.
 *
 * @return The index corresponding to the key.
 */
static inline vtx_type S_htable_idx(
    vtx_type const i, 
    vtx_type const * const htable)
{
  vtx_type idx,m,j;

  idx = i&CYCLE_MASK;
  m = htable[idx];

  if (m == NULL_VTX || m == i) {
    return idx;
  } else {
    for (j=(idx+1)&CYCLE_MASK;;j=(j+1)&CYCLE_MASK) {
      if (htable[j] == NULL_VTX || htable[j] == i) {
        break;
      }
    }
    return j;
  }
}


/**
 * @brief Add a vertex i to the same cluster as the vertex maxidx.
 *
 * @param i The vertex to add.
 * @param maxidx The vertex who's cluster to join.
 * @param myid The calling thread's id.
 * @param match The matching vector.
 * @param graph The graph.
 *
 * @return The number of vertices collapsed (1 if formed a cluster, 0 if
 * aggreagted with itself). 
 */
static inline vtx_type S_cluster(
    vtx_type const i, 
    vtx_type const maxidx,
    tid_type const myid, 
    vtx_type * const * const match, 
    graph_type const * const graph)
{
  vtx_type l, matched;
  tid_type o;
  vtx_type const mynvtxs = graph->mynvtxs[myid];
  if (maxidx == i) {
    /* if we didn't match */
    match[myid][i] = i;
    return 0;
  } else if (maxidx < mynvtxs) {
    /* if I'm matching with something local */
    matched = match[myid][maxidx];
    if (matched == NULL_VTX) {
      match[myid][i] = maxidx;
      match[myid][maxidx] = i;
      return 1;
    } else {
      match[myid][i] = matched;
      match[myid][maxidx] = i;
      return 1;
    }
  } else {
    /* matching with something remote */
    o = gvtx_to_tid(maxidx,graph->dist);
    l = gvtx_to_lvtx(maxidx,graph->dist);
    matched = match[o][l];
    if (matched == NULL_VTX) {
      /* setting up a single match */
      match[myid][i] = maxidx;
      match[o][l] = lvtx_to_gvtx(i,myid,graph->dist);
      return 1;
    } else {
      /* joining a cluster */
      if (matched < graph->mynvtxs[o]) { /* o owns it */
        match[myid][i] = lvtx_to_gvtx(matched,o,graph->dist);
        match[o][l] = lvtx_to_gvtx(i,myid,graph->dist);
      } else if (gvtx_to_tid(matched,graph->dist) == myid) { /* i own it */
        match[myid][i] = gvtx_to_lvtx(matched,graph->dist);
        match[o][l] = lvtx_to_gvtx(i,myid,graph->dist);
      } else { /* third party */
        match[myid][i] = matched;
        match[o][l] = lvtx_to_gvtx(i,myid,graph->dist);
      }
      return 1;
    }
  }
}



/******************************************************************************
* PRIVATE FUNCTIONS ***********************************************************
******************************************************************************/


/**
 * @brief Cleanup broken matchings after a parallel aggregation step.
 *
 * @param graph The graph to cleanup the matching on.
 * @param gmatch The global matching vector.
 * @param gcmap The global coarse map vector.
 * @param fcmap The first-vertex coarse map vector.
 *
 * @return The number of coarse vertices that will be generated during
 * contraction.
 */
static vtx_type S_cleanup_match(
    graph_type const * const graph,
    vtx_type * const * const gmatch,
    vtx_type * const * const gcmap,
    vtx_type * const fcmap)
{
  vtx_type i, lvtx, gvtx, cnvtxs, maxidx;
  tid_type nbrid;

  tid_type const myid = dlthread_get_id(graph->comm);

  vtx_type const mynvtxs = graph->mynvtxs[myid];
  adj_type const * const * const gxadj = (adj_type const * const *)graph->xadj;

  cnvtxs = 0;
  for (i=0;i<mynvtxs;++i) {
    gvtx = lvtx_to_gvtx(i,myid,graph->dist);
    DL_ASSERT(gvtx_to_lvtx(gvtx,graph->dist) == i,"Mismatch local-global " \
        "vertex id");
    maxidx = gmatch[myid][i];
    if (maxidx == NULL_VTX) {
      /* match any unmatched vertices with themselves */
      gmatch[myid][i] = i;
    } else if (maxidx < mynvtxs) {
      if (gmatch[myid][maxidx] != i) {
        gmatch[myid][i] = i;
      }
    } else {
      nbrid = gvtx_to_tid(maxidx,graph->dist);
      lvtx = gvtx_to_lvtx(maxidx,graph->dist);
      if (gmatch[nbrid][lvtx] != gvtx) {
        /* match vertices in broken matches with themselves */
        gmatch[myid][i] = i;
      } else {
        if (my_cvtx(gvtx,gmatch[myid][i],gxadj[myid][i+1]-gxadj[myid][i],
            gxadj[nbrid][lvtx+1]-gxadj[nbrid][lvtx])) {
          /* use global cmap[i] id */
          gcmap[myid][i] = lvtx_to_gvtx(cnvtxs,myid,graph->dist); 
          fcmap[cnvtxs++] = i;
        }
      }
    }

    if (gmatch[myid][i] < mynvtxs && i < gmatch[myid][i]) {
      /* use global cmap[i] id */
      gcmap[myid][i] = lvtx_to_gvtx(cnvtxs,myid,graph->dist); 
      fcmap[cnvtxs++] = i;
    }
  }

  dlthread_barrier(graph->comm);
  /* tries to avoid false sharing */
  for (i=mynvtxs;i>0;) {
    --i;
    gvtx = lvtx_to_gvtx(i,myid,graph->dist);
    maxidx = gmatch[myid][i];
    if (maxidx < mynvtxs) {
      nbrid = myid;
      lvtx = maxidx;
    } else {
      nbrid = gvtx_to_tid(maxidx,graph->dist);
      lvtx = gvtx_to_lvtx(maxidx,graph->dist);
    }
    if (i > gmatch[myid][i] || (gmatch[myid][i] >= mynvtxs && \
        !my_cvtx(gvtx,gmatch[myid][i],gxadj[myid][i+1]-gxadj[myid][i], \
        gxadj[nbrid][lvtx+1]-gxadj[nbrid][lvtx]))) {
      gcmap[myid][i] = gcmap[nbrid][lvtx];
    }
  }

  return cnvtxs;
}


/**
 * @brief Cleanup broken clusters by removing tail vertices on cluster cycles.
 *
 * @param mynvtxs The number of vertices the calling thread owns.
 * @param myid The id of the calling thread.
 * @param match The global match vector.
 * @param cmap The global coarse vertex map.
 * @param fmap The global fine vertex map.
 * @param graph The graph.
 *
 * @return The number of coarse vertices this thread owns.
 */
static vtx_type S_cleanup_cluster(
    vtx_type const mynvtxs,
    tid_type const myid,
    vtx_type * const * const match, 
    vtx_type * const * const cmap, 
    vtx_type * const * const fmap, 
    graph_type const * const graph)
{
  vtx_type i, g, maxidx, idx, l, j, gvtx, ncycle, minvtx, mycnvtxs, cnvtxs;
  tid_type o, maxtid;

  vtx_type * vtxs = vtx_init_alloc(NULL_VTX,CYCLE_MASK_SIZE);
  vtx_type * ptxs = vtx_alloc(MAX_CYCLE_SIZE);

  ncycle = 0;
  mycnvtxs = 0;
  for (i=0;i<mynvtxs;++i) {
    DL_ASSERT_EQUALS(ncycle,(vtx_type)0,"%"PF_VTX_T);
    maxidx = match[myid][i];
    if (maxidx == NULL_VTX) { /* if we didn't get matched */
      match[myid][i] = i;
    } else if (match[myid][i] == i) {
      /* ignore self matches */
    } else if (cmap[myid][i] == NULL_VTX) {
      /* check if the vertex is part of a cycle --
       * if it is, and I own the minimum lvtx (ties go to lower tid's) in that 
       * cycle, assign the cmap and the fmap
       */
      minvtx = i;
      maxtid = myid;
      gvtx = lvtx_to_gvtx(i,myid,graph->dist);
      idx = S_htable_idx(gvtx,vtxs);
      vtxs[idx] = gvtx;
      ptxs[ncycle++] = idx;
      o = myid;
      do {
        DL_ASSERT(maxidx<max_gvtx(graph),"Invalid maxidx of %"PF_VTX_T"\n",
            maxidx);

        if (maxidx < graph->mynvtxs[o]) {
          g = lvtx_to_gvtx(maxidx,o,graph->dist);
        } else {
          o = gvtx_to_tid(maxidx,graph->dist); 
          g = maxidx;
          maxidx = gvtx_to_lvtx(maxidx,graph->dist);
        }

        DL_ASSERT_EQUALS(gvtx_to_lvtx(g,graph->dist),maxidx,"%"PF_VTX_T);
        DL_ASSERT_EQUALS(gvtx_to_tid(g,graph->dist),o,"%"PF_VTX_T);
        DL_ASSERT_EQUALS(lvtx_to_gvtx(maxidx,o,graph->dist),g,"%"PF_VTX_T);

        idx = S_htable_idx(g,vtxs);
        if (vtxs[idx] == NULL_VTX) {
          /* no cycle yet -- will stay in do-while */
          if (maxidx < minvtx || (maxidx == minvtx && o > maxtid)) {
            /* set as owner of the cycle */
            minvtx = maxidx;
            maxtid = o;
          }
          /* record vertex */
          vtxs[idx] = g;
          ptxs[ncycle++] = idx;
          /* jump to next */
          maxidx = match[o][maxidx];
          DL_ASSERT(maxidx < graph->mynvtxs[o] ||
              maxidx > graph->dist.mask,"Invalid match of %"PF_VTX_T"/%" \
              PF_VTX_T" for thread with only %"PF_VTX_T" vertices\n",maxidx, \
              graph->dist.mask,graph->mynvtxs[o]);
        } else {
          /* found a cycle -- will exit do-while */
          if (g == gvtx) {
            /* found the cycle gvtx is a part of */
            if (maxtid == myid) {
              fmap[myid][mycnvtxs] = i;
              cnvtxs = lvtx_to_gvtx(mycnvtxs,myid,graph->dist);
              for (j=0;j<ncycle;++j) {
                o = gvtx_to_tid(vtxs[ptxs[j]],graph->dist);
                l = gvtx_to_lvtx(vtxs[ptxs[j]],graph->dist);
                DL_ASSERT_EQUALS(cmap[o][l],NULL_VTX,"%"PF_VTX_T);
                cmap[o][l] = cnvtxs;
              }
              ++mycnvtxs;
            }
            break;
          } else {
            /* gvtx is not part of a cycle */
            match[myid][i] = i;
            break;
          }
        }
        if (ncycle >= MAX_CYCLE_SIZE) {
          /* maximum cycle size reached */
          match[myid][i] = i;
          break;
        }
      } while (1);
      /* now I need to cleanup my garbage */
      if (ncycle < MAX_CYCLE_SIZE) {
        while (ncycle > 0) {
          vtxs[ptxs[--ncycle]] = NULL_VTX;
        }
      } else {
        vtx_set(vtxs,NULL_VTX,CYCLE_MASK_SIZE);
        ncycle = 0;
      }
    }
  }

  dl_free(vtxs);
  dl_free(ptxs);

  return mycnvtxs;
}


/**
 * @brief Match together leaf vertices that are two hops away from each
 * other. 
 * 
 * This is based off of the algorithm implemented in Metis's Match_2HopAny(). 
 *
 * @param ctrl The control structure specifying runtime parameters.
 * @param graph The graph to partition.
 * @param gmatch The global matching vector.
 * @param fcmap The first-vertex coarse map.
 * @param cnvtxs The number of coarse vertices generated so far.
 * @param maxdeg The maximum degree of an eligible leaf.
 *
 */
static vtx_type S_coarsen_match_leaves(
    ctrl_type * const ctrl, 
    graph_type const * const graph,
    vtx_type * const * const gmatch, 
    vtx_type * const fcmap,
    vtx_type cnvtxs,
    vtx_type const leafdegree) 
{
  vtx_type i, k, m, l, npivot, mask;
  adj_type j, jj;
  vtx_type * ind, * hash, * id;
  adj_type * ptr;

  tid_type const myid = dlthread_get_id(ctrl->comm);

  vtx_type const mynvtxs = graph->mynvtxs[myid];
  adj_type const * const xadj = graph->xadj[myid];
  vtx_type const * const adjncy = graph->adjncy[myid];
  wgt_type const * const vwgt = graph->vwgt[myid];

  wgt_type const maxvwgt = ctrl->maxvwgt;

  vtx_type * const cmap = graph->cmap[myid];
  vtx_type * const match = gmatch[myid];

  /* this function is based on the algorithm implemented in Metis 5.1.0,
   * but hashes neighbor ids and only lets vertices owned by the same thread
   * match */

  mask = (vtx_type)(2.3*mynvtxs);

  ptr = adj_init_alloc(0,mynvtxs+1);
  ind = vtx_alloc(graph->mynedges[myid]);
  hash = vtx_init_alloc(NULL_VTX,mask);
  id = vtx_alloc(mynvtxs);

  /* build an umatched neighbor graph -- bipartitish */
  npivot = 0;
  for (i=0;i<mynvtxs;++i) {
    if (gmatch[myid][i] == i && xadj[i+1] - xadj[i] <= leafdegree && \
        vwgt[i] < maxvwgt) {
      for (j=xadj[i];j<xadj[i+1];++j) {
        k = adjncy[j];
        m = k % mask;
        if ((l = hash[m]) == NULL_VTX) {
          if (npivot == mynvtxs) {
            /* we're full -- ignore neighbor */
            continue;
          }
          /* insert vertex */
          id[npivot] = k;
          l = hash[m] = npivot++;
        } else if (id[l] != k) {
          /* we have a hash collision -- ignore neighbor */
          continue;
        }
        ++ptr[l+1];
      }
    }
  }
  adj_prefixsum_exc(ptr+1,npivot);
  for (i=0;i<mynvtxs;++i) {
    if (gmatch[myid][i] == i && xadj[i+1] - xadj[i] <= leafdegree && \
        vwgt[i] < maxvwgt) {
      for (j=xadj[i];j<xadj[i+1];++j) {
        k = adjncy[j];
        m = k % mask;
        l = hash[m];
        if (l == NULL_VTX || id[l] != k) {
          /* skip ignored vertices */
          continue;
        }
        ind[ptr[l+1]++] = i;
      }
    }
  }

  dl_free(hash);
  dl_free(id);

  /* go through hashed vertices matching all vertices I can */
  for (l=0;l<npivot;++l) {
    if (ptr[l+1] - ptr[l] < 2) {
      /* not enough vertices to match */
      continue;
    }
    /* find matches from the end */
    jj = ptr[l+1];
    for (j=ptr[l];j<jj;++j) {
      i = ind[j];
      if (match[i] == i) {
        --jj;
        for (;jj>j;--jj) {
          k = ind[jj];
          if (match[k] == k && vwgt[i] + vwgt[k] < maxvwgt) {
            fcmap[cnvtxs] = i;
            cmap[i] = cmap[k] = lvtx_to_gvtx(cnvtxs,myid,graph->dist);
            match[i] = k;
            match[k] = i;
            ++cnvtxs;
            break;
          }
        }
      }
    }
  }

  dl_free(ptr);
  dl_free(ind);

  return cnvtxs;
}


/**
 * @brief Match together identical vertices that are two hops away from each
 * other. We need not be concerned that the vertices will have an edge between
 * them as they would have been matched in a previous scheme.
 * 
 * This is based off of the algorithm implemented in Metis's Match_2HopAll().
 * The largest difference is instead of using a dense map for vertices, is
 * sorting the adjacency lists for comparison. 
 *
 * @param ctrl The control structure specifying runtime parameters.
 * @param graph The graph to partition.
 * @param gmatch The global matching vector.
 * @param fcmap The first-vertex coarse map.
 * @param cnvtxs The number of coarse vertices generated so far.
 * @param maxdeg The maximum degree of an eligible twin.
 *
 */
static vtx_type S_coarsen_match_twins(
    ctrl_type * const ctrl, 
    graph_type const * const graph,
    vtx_type * const * const gmatch, 
    vtx_type * const fcmap,
    vtx_type cnvtxs,
    vtx_type const maxdeg)
{
  uint64_t h;
  vtx_type i, v, u, k, deg, l, ntwin;
  adj_type j;
  wgt_type wgt;
  vtx_type * lista, * listb;
  adjhash_type * twins;

  uint64_t const mask = UINT64_MAX / (maxdeg+1);

  tid_type const myid = dlthread_get_id(ctrl->comm);

  vtx_type const mynvtxs = graph->mynvtxs[myid];
  adj_type const * const xadj = graph->xadj[myid];
  vtx_type const * const adjncy = graph->adjncy[myid];
  wgt_type const * const vwgt = graph->vwgt[myid];

  vtx_type * const match = gmatch[myid];
  vtx_type * const cmap = graph->cmap[myid];

  wgt_type const maxvwgt = ctrl->maxvwgt;

  lista = vtx_alloc(maxdeg);
  listb = vtx_alloc(maxdeg);

  twins = malloc(sizeof(adjhash_type)*mynvtxs);

  /* hash adjacency lists for eligible vertices */
  ntwin = 0;
  for (i=0;i<mynvtxs;++i) {
    if (match[i] == i && xadj[i+1] - xadj[i] <= maxdeg && vwgt[i] < maxvwgt) {
      twins[ntwin].val = i;
      h = xadj[i+1] - xadj[i];
      for (j=xadj[i];j<xadj[i+1];++j) {
        k = adjncy[j];
        h += k * ((k % mask)+1);
      }
      twins[ntwin].key = h;
      ++ntwin;
    }
  }

  if (ntwin > 0) {
    /* sort the hashes */
    ah_quicksort(twins,ntwin);

    /* find vertices with matching hashes */
    for (i=0;i<ntwin-1;++i) {
      v = twins[i].val;

      if (match[v] != v) {
        /* already matched */
        continue;
      }

      k=i+1;

      if (twins[i].key != twins[k].key) {
        /* I don't match anyone's keys, so don't bother */
        continue;
      }

      deg = xadj[v+1] - xadj[v];
      u = twins[k].val;
      wgt = maxvwgt - vwgt[v];

      if (deg != xadj[u+1] - xadj[u] || vwgt[u] >= wgt) {
        /* I don't have the same number of neighbors as anyone with my same 
         * key */
        continue;
      }

      /* sort my adjaceny list */
      vtx_copy(lista,adjncy+xadj[v],deg);
      vtx_quicksort(lista,deg);

      /* search vertices with matching keys */
      do {
        if (match[u] == u && vwgt[u] < wgt) {
          /* sort the neighbors adjaceny list */
          vtx_copy(listb,adjncy+xadj[u],deg);
          vtx_quicksort(listb,deg);

          /* compare lists */
          for (l=0;l<deg;++l) {
            if (lista[l] != listb[l]) {
              break;
            }
          }
          if (l == deg) {
            /* match */
            fcmap[cnvtxs] = v;
            cmap[v] = cmap[u] = lvtx_to_gvtx(cnvtxs,myid,graph->dist);
            match[u] = v;
            match[v] = u;
            ++cnvtxs;
            break;
          }
        }
        
        /* I should come up with a better way of doing these checks */
        ++k;
        if (k == ntwin) {
          break;
        }

        u = twins[k].val;
        if (twins[i].key != twins[k].key) {
          break;
        }

        if (deg != xadj[u+1]-xadj[u]) {
          break;
        }
      } while (1);
    }
  }

  dl_free(twins);
  dl_free(lista);
  dl_free(listb);

  return cnvtxs;
}


/**
 * @brief Create a vertex aggregation by randomly matching vertices across
 * edges.
 *
 * @param ctrl The control structure specifying partitioning parameters.
 * @param graph The graph to partition.
 * @param gmatch The global matching vector.
 * @param fcmap The first-vertex coarse map.
 *
 * @return The number of coarse vertices that will be generated during
 * contraction. 
 */
static vtx_type S_coarsen_match_RM(
    ctrl_type * const ctrl, 
    graph_type const * const graph,
    vtx_type * const * const gmatch, 
    vtx_type * const fcmap) 
{
  int unsigned seed;
  vtx_type i, pi, k, maxidx, last_unmatched, lvtx, gvtx, cnvtxs;
  adj_type j, start;
  tid_type nbrid;
  vtx_type * match, * perm;

  tid_type const myid = dlthread_get_id(ctrl->comm);

  adj_type const * const * const gxadj = (adj_type const **)graph->xadj;
  wgt_type const * const * const gvwgt = (wgt_type const **)graph->vwgt;
  vtx_type const * const * const gadjncy = (vtx_type const **)graph->adjncy;
  vtx_type ** const gcmap = graph->cmap;

  wgt_type const maxvwgt = ctrl->maxvwgt;

  /* local graph pointers */
  vtx_type const mynvtxs = graph->mynvtxs[myid];
  adj_type const * const xadj = gxadj[myid];
  wgt_type const * const vwgt = gvwgt[myid];
  vtx_type const * const adjncy = gadjncy[myid];

  DL_ASSERT_EQUALS(graph->dist.nthreads, \
      (tid_type)dlthread_get_nthreads(ctrl->comm),"%"PF_TID_T);

  gcmap[myid] = perm = vtx_alloc(mynvtxs);

  k = 0;
  seed = ctrl->seed + myid;

  vtx_incset(perm,0,1,mynvtxs);
  vtx_pseudo_shuffle_r(perm,mynvtxs/8,mynvtxs,&seed);

  last_unmatched=0; /* this is private but ... */

  match = gmatch[myid];

  for (pi=0; pi<mynvtxs;++pi) {
    /* request my matches */
    i = perm[pi];

    if (match[i] == NULL_VTX) { /* Unmatched */
      gvtx = lvtx_to_gvtx(i,myid,graph->dist);
      maxidx = gvtx;
      
      if (vwgt[i] < maxvwgt) {
        /* Deal with island vertices. Match locally */
        if (xadj[i+1] == xadj[i]) { 
          last_unmatched = dl_max(pi, last_unmatched)+1;
          for (; last_unmatched<mynvtxs; last_unmatched++) {
            k = perm[last_unmatched];
            if (match[k] == NULL_VTX) {
              maxidx = lvtx_to_gvtx(k,myid,graph->dist);
              break;
            }
          }
        } else {
          /* Find a heavy-edge matching, subject to maxvwgt constraints */
          start = (pi+xadj[i]) % (xadj[i+1]-xadj[i]) + xadj[i];
          j = start;
          do {
            k = adjncy[j];
            if (k < mynvtxs) {
              lvtx = k;
              nbrid = myid;
            } else {
              nbrid = gvtx_to_tid(k,graph->dist);
              lvtx = gvtx_to_lvtx(k,graph->dist);
            }
            if (vwgt[i]+gvwgt[nbrid][lvtx] <= maxvwgt && 
                (gmatch[nbrid][lvtx] == NULL_VTX)) {
              maxidx = k;
              break;
            }
            ++j;
            if (j == xadj[i+1]) {
              j = xadj[i];
            }
          } while (j != start);
        }
      }
      if (maxidx < mynvtxs) {
        match[i] = maxidx;
        match[maxidx] = i;
      } else {
        nbrid = gvtx_to_tid(maxidx,graph->dist);
        lvtx = gvtx_to_lvtx(maxidx,graph->dist);
        if (gvtx < maxidx) {
          match[i] = maxidx;
          gmatch[nbrid][lvtx] = gvtx;
        } else if (gvtx > maxidx) {
          gmatch[nbrid][lvtx] = gvtx;
          match[i] = maxidx;
        }
      }
    }
  } /* outer match loop */
  dlthread_barrier(ctrl->comm);

  cnvtxs = S_cleanup_match(graph,gmatch,gcmap,fcmap);

  return cnvtxs;
}


/*
 * @brief Match the vertices in a graph using attempting to match across the
 * heaviest edges.
 *
 * @param ctrl The control structure specifying partitioning parameters.
 * @param graph The graph to partition.
 * @param gmatch The global matching vector.
 * @param fcmap The first-vertex coarse map.
 *
 * @return The number of coarse vertices that will be generated during
 * contraction. 
 */
static vtx_type S_coarsen_match_SHEM(
    ctrl_type * const ctrl, 
    graph_type const * const graph,
    vtx_type * const * const gmatch, 
    vtx_type * const fcmap) 
{
  unsigned int seed;
  vtx_type cnvtxs, i, pi, k, maxidx, last_unmatched, \
      lvtx, gvtx;
  wgt_type mywgt, ewgt, maxwgt;
  tid_type nbrid;
  adj_type j, avgdegree;
  vtx_type * perm, * tperm, * degrees;

  tid_type const myid = dlthread_get_id(ctrl->comm);

  vtx_type ** const gcmap = graph->cmap;

  wgt_type const maxvwgt  = ctrl->maxvwgt;

  adj_type const * const * const gxadj = (adj_type const **)graph->xadj;
  vtx_type const * const * const gadjncy = (vtx_type const **)graph->adjncy;
  wgt_type const * const * const gvwgt = (wgt_type const **)graph->vwgt;
  wgt_type const * const * const gadjwgt = (wgt_type const **)graph->adjwgt;

  /* thread local graph pointers */
  vtx_type const mynvtxs = graph->mynvtxs[myid];
  adj_type const * const xadj = gxadj[myid];
  vtx_type const * const adjncy = gadjncy[myid];
  wgt_type const * const vwgt = gvwgt[myid];
  wgt_type const * const adjwgt = gadjwgt[myid];
  vtx_type * const match = gmatch[myid];

  /* matching vectors */

  k = 0;
  cnvtxs = 0;

  /* calculate the degree of each vertex, truncating to the average */
  if (mynvtxs > 0) {
    perm = vtx_alloc(mynvtxs);
    tperm = vtx_alloc(mynvtxs);
    degrees = vtx_alloc(mynvtxs);

    avgdegree = (0.7*(graph->mynedges[myid]/mynvtxs))+1;
    for (i=0;i<mynvtxs;++i) {
      j = xadj[i+1] - xadj[i];
      degrees[i] = (j > avgdegree ? avgdegree : j);
    }

    /* create a pre-permutation array */
    vtx_incset(tperm,0,1,mynvtxs);

    /* shuffle permutation array and degrees the same */
    seed = ctrl->seed + myid;
    vtx_pseudo_shuffle_r(tperm,mynvtxs/8,mynvtxs,&seed);
    seed = ctrl->seed + myid;
    vtx_pseudo_shuffle_r(degrees,mynvtxs/8,mynvtxs,&seed);

    DL_ASSERT_EQUALS(degrees[0], \
        dl_min(avgdegree,xadj[tperm[0]+1]-xadj[tperm[0]]),"%"PF_ADJ_T);

    /* create permutation */
    vv_countingsort_kv(degrees,tperm,0,avgdegree,mynvtxs,perm,NULL);

    DL_ASSERT(mynvtxs < 2 || dl_min(xadj[perm[0]+1] - xadj[perm[0]],avgdegree) \
        <= xadj[perm[mynvtxs-1]+1] - xadj[perm[mynvtxs-1]],"Sorting failed\n");

    /* free scratch space */
    dl_free(tperm);
    dl_free(degrees);
  } else {
    perm = NULL;
  }

  last_unmatched=0; 

  for (pi=0; pi<mynvtxs;++pi) {
    /* request my matches */
    i = perm[pi];
      
    if (match[i] == NULL_VTX) {  /* Unmatched */
      mywgt = vwgt[i];
      maxwgt = 0;
      gvtx = lvtx_to_gvtx(i,myid,graph->dist);
      maxidx = gvtx;

      if (mywgt < maxvwgt) {
        /* Deal with island vertices. Find a non-island and match it with. 
           The matching ignores ctrl->maxvwgt requirements */
        if (xadj[i+1] == xadj[i]) { 
          last_unmatched = dl_max(pi, last_unmatched)+1;
          for (; last_unmatched<mynvtxs; last_unmatched++) {
            k = perm[last_unmatched];
            if (match[k] == NULL_VTX) {
              maxidx = k;
              break;
            }
          }
        } else {
          /* Find a heavy-edge matching, subject to maxvwgt constraints */
          for (j=xadj[i]; j<xadj[i+1]; ++j) {
            k = adjncy[j];
            ewgt = adjwgt[j];
            if (k < mynvtxs) {
              lvtx = k;
              nbrid = myid;
            } else {
              nbrid = gvtx_to_tid(k,graph->dist);
              lvtx = gvtx_to_lvtx(k,graph->dist);
            }
            if (maxwgt < ewgt + (wgt_type)((pi+xadj[i])%2) && \
                mywgt+gvwgt[nbrid][lvtx] <= maxvwgt && \
                gmatch[nbrid][lvtx] == NULL_VTX) {
              maxidx = k;
              maxwgt = ewgt;
            }
          }
        }
      }
      /* handle unmatched vertices later */
      if (maxidx < mynvtxs) {
        match[i] = maxidx;
        match[maxidx] = i;
      } else {
        nbrid = gvtx_to_tid(maxidx,graph->dist);
        lvtx = gvtx_to_lvtx(maxidx,graph->dist);
        if (gvtx < maxidx) {
          match[i] = maxidx;
          gmatch[nbrid][lvtx] = gvtx;
        } else if (gvtx > maxidx) {
          gmatch[nbrid][lvtx] = gvtx;
          match[i] = maxidx;
        }
      }
    }
  } /* outer match loop */
  dlthread_barrier(ctrl->comm);

  gcmap[myid] = perm;

  cnvtxs = S_cleanup_match(graph,gmatch,gcmap,fcmap);

  return cnvtxs;
}


/*
 * @brief Cluster the vertices in a graph attempting to cluster across the
 * heaviest edges.
 *
 * @param ctrl The control structure specifying partitioning parameters.
 * @param graph The graph to partition.
 * @param gmatch The global matching vector.
 * @param fcmap The first-vertex coarse map.
 *
 * @return The number of coarse vertices that will be generated during
 * contraction. 
 */
static vtx_type S_coarsen_cluster_FC(
    ctrl_type * const ctrl, 
    graph_type const * const graph,
    vtx_type * const * const gmatch, 
    vtx_type * const fcmap)
{
  unsigned int seed;
  vtx_type v, i, k, l, cl, cg, maxidx, mycnvtxs, maxdeg, last_unmatched, \
      collapsed;
  tid_type o,co;
  adj_type j, astart,aend;
  wgt_type cwgt, twgt, nvwgt, maxwgt;
  wgt_type ** cvwgt;
  vtx_type ** gfcmap;

  vw_ht_t * conn;

  tid_type const myid = dlthread_get_id(ctrl->comm);
  tid_type const nthreads = dlthread_get_nthreads(ctrl->comm);

  /* set up graph stuff */
  vtx_type const nvtxs = graph->nvtxs;
  vtx_type const mynvtxs = graph->mynvtxs[myid];
  adj_type const * const * const gxadj = (adj_type const * const *)graph->xadj;
  vtx_type const * const * const gadjncy = (vtx_type const * const *)graph->adjncy;
  wgt_type const * const * const gvwgt = (wgt_type const * const *)graph->vwgt;
  wgt_type const * const * const gadjwgt = (wgt_type const * const *)graph->adjwgt;

  adj_type const * myxadj = gxadj[myid];
  vtx_type const * myadjncy = gadjncy[myid];
  wgt_type const * myadjwgt = gadjwgt[myid];

  vtx_type ** const gcmap = graph->cmap;

  wgt_type const maxvwgt = ctrl->maxvwgt;

  vtx_type * perm = vtx_alloc(nvtxs);

  /* do the real work */
  vtx_set(gmatch[myid],NULL_VTX,mynvtxs);

  /* store total degree of coarse vertices */
  cvwgt = dlthread_get_shmem((sizeof(vtx_type*)*nthreads) + \
      (sizeof(wgt_type*)*nthreads),ctrl->comm);
  gfcmap = (vtx_type**)(cvwgt+nthreads);

  cvwgt[myid] = wgt_alloc(mynvtxs);
  gfcmap[myid] = fcmap;
  gcmap[myid] = vtx_alloc(mynvtxs);

  seed = ctrl->seed+myid;

  dlthread_barrier(ctrl->comm);

  /* determine maximum degree */
  maxdeg = 0;
  for (v=0;v<mynvtxs;++v) {
    if (myxadj[v+1] - myxadj[v] > maxdeg) {
      maxdeg = myxadj[v+1] - myxadj[v];
    }
  }

  conn = vw_ht_create(maxdeg,maxdeg/4);

  last_unmatched=0; /* this is private but ... */
  mycnvtxs = 0;
  collapsed = 0;

  vtx_incset(perm,0,1,mynvtxs);
  vtx_shuffle_r(perm,mynvtxs,&seed);

  for (v=0;v<mynvtxs;++v) {
    if (S_agg_limit_reached(mynvtxs,collapsed,0.7)) {
      break;
    }
    i = perm[v];
    if (gmatch[myid][i] == NULL_VTX) {
      maxidx = i;
      maxwgt = 0;
      nvwgt = graph->tvwgt;
      astart = myxadj[i];
      aend = myxadj[i+1];
      if (astart == aend) {
        last_unmatched = dl_max(v, last_unmatched)+1;
        for (; last_unmatched<mynvtxs; last_unmatched++) {
          k = perm[last_unmatched];
          if (gmatch[myid][k] == NULL_VTX) {
            maxidx = k;
            break;
          }
        }
      } else if (astart == aend+1) {
        /* if we only have one option, always match it. Brandes et al. '08
         * "On Modularity", showed that 1-degree vertices should never be in
         * their own cluster. */
        maxidx = myadjncy[astart];
      } else {
        /* hopefully for many graphs this will fit in cache */
        for (j=astart;j<aend;++j) {
          k = myadjncy[j];
          if (k < mynvtxs) {
            o = myid;
            l = k;
          } else {
            o = gvtx_to_tid(k,graph->dist);
            l = gvtx_to_lvtx(k,graph->dist);
          }
          if (gmatch[o][l] != NULL_VTX) {
            cg = gcmap[o][l];
            vw_ht_add(cg,myadjwgt[j],conn);
          }
        }
        for (j=astart;j<aend;++j) {
          k = myadjncy[j];
          if (k < mynvtxs) {
            o = myid;
            l = k;
          } else {
            o = gvtx_to_tid(k,graph->dist);
            l = gvtx_to_lvtx(k,graph->dist);
          }
          if (gmatch[o][l] == NULL_VTX) {
            cwgt = myadjwgt[j];
            twgt = gvwgt[o][l];
          } else {
            cg = gcmap[o][l];
            cl = gvtx_to_lvtx(cg,graph->dist);
            co = gvtx_to_tid(cg,graph->dist);
            twgt = cvwgt[co][cl];
            cwgt = vw_ht_get(cg,conn);
          }
          cwgt = (double)ceil(cwgt / sqrt(twgt));
          if (twgt + gvwgt[myid][i] < maxvwgt && (cwgt > maxwgt || \
              (cwgt == maxwgt && twgt < nvwgt))) {
            maxidx = k;
            maxwgt = cwgt;
            nvwgt = twgt;
          }
        }
        /* clear the conn map */
        vw_ht_clear_chains(conn);
        for (j=astart;j<aend;++j) {
          k = myadjncy[j];
          if (k < mynvtxs) {
            o = myid;
            l = k;
          } else {
            o = gvtx_to_tid(k,graph->dist);
            l = gvtx_to_lvtx(k,graph->dist);
          }
          if (gmatch[o][l] != NULL_VTX) {
            vw_ht_clear_slot(gcmap[o][l],conn);
          }
        }
      }
      /* match maker make me a match */
      if (maxidx == i) {
        cvwgt[myid][mycnvtxs] = gvwgt[myid][i];
        gcmap[myid][i] = lvtx_to_gvtx(mycnvtxs,myid,graph->dist);
        DL_ASSERT(gcmap[myid][i]>=graph->dist.offset,"Generated global "
            "coarse vertex number is smaller than graph offset (gvtx = %"
            PF_VTX_T", offset = %"PF_VTX_T"\n",v,graph->dist.offset);
        ++mycnvtxs;
      } else {
        if (maxidx < mynvtxs) {
          o = myid;
          l = maxidx;
        } else {
          o = gvtx_to_tid(maxidx,graph->dist);
          l = gvtx_to_lvtx(maxidx,graph->dist);
        }
        if (gmatch[o][l] == NULL_VTX) { /* duh */
          cg = lvtx_to_gvtx(mycnvtxs,myid,graph->dist);
          cl = gvtx_to_lvtx(cg,graph->dist);
          co = gvtx_to_tid(cg,graph->dist);
          cvwgt[co][cl] = gvwgt[o][l] + gvwgt[myid][i];
          DL_ASSERT(cg>=graph->dist.offset,"Generated global coarse vertex "
              "number is smaller than graph offset (gvtx = %"PF_VTX_T
              ", offset = %"PF_VTX_T"\n",cg,graph->dist.offset);
          gcmap[myid][i] = gcmap[o][l] = cg;
          ++mycnvtxs;
        } else {
          cg = gcmap[myid][i] = gcmap[o][l];
          cl = gvtx_to_lvtx(cg,graph->dist);
          co = gvtx_to_tid(cg,graph->dist);
          cvwgt[co][cl] += gvwgt[myid][i];
        }
      }
      collapsed += S_cluster(i,maxidx,myid,gmatch,graph);
    }
  }
  vw_ht_free(conn);

  dlthread_barrier(ctrl->comm);

  /* reset the cmap so I perform cycle clean up */
  vtx_set(gcmap[myid],NULL_VTX,mynvtxs);

  dl_free(perm);

  dlthread_barrier(ctrl->comm);

  mycnvtxs = S_cleanup_cluster(mynvtxs,myid,gmatch,gcmap,gfcmap,graph);

  /* implicit barrier */ 
  dl_free(cvwgt[myid]);
  dlthread_free_shmem(cvwgt,ctrl->comm);

  if (myid == 0) {
    ++ctrl->seed;
  }

  return mycnvtxs;
}


/*
 * @brief Cluster the vertices in a graph randomly across edges.
 *
 * @param ctrl The control structure specifying partitioning parameters.
 * @param graph The graph to partition.
 * @param gmatch The global matching vector.
 * @param fcmap The first-vertex coarse map.
 *
 * @return The number of coarse vertices that will be generated during
 * contraction. 
 */
static vtx_type S_coarsen_cluster_RC(
    ctrl_type * const ctrl, 
    graph_type const * const graph,
    vtx_type * const * const gmatch, 
    vtx_type * const fcmap) 
{
  unsigned int seed;
  vtx_type v, i, k, l, cl, cg, maxidx, mycnvtxs, maxdeg, last_unmatched, \
      collapsed;
  tid_type o,co;
  adj_type j, astart,aend;
  wgt_type twgt;
  wgt_type ** cvwgt;
  vtx_type ** gfcmap;

  tid_type const myid = dlthread_get_id(ctrl->comm);
  tid_type const nthreads = dlthread_get_nthreads(ctrl->comm);

  /* set up graph stuff */
  vtx_type const nvtxs = graph->nvtxs;
  vtx_type const mynvtxs = graph->mynvtxs[myid];
  adj_type const * const * const gxadj = (adj_type const * const *)graph->xadj;
  vtx_type const * const * const gadjncy = (vtx_type const * const *)graph->adjncy;
  wgt_type const * const * const gvwgt = (wgt_type const * const *)graph->vwgt;

  adj_type const * myxadj = gxadj[myid];
  vtx_type const * myadjncy = gadjncy[myid];

  vtx_type ** const gcmap = graph->cmap;

  wgt_type const maxvwgt = ctrl->maxvwgt;

  vtx_type * perm = vtx_alloc(nvtxs);

  /* do the real work */
  vtx_set(gmatch[myid],NULL_VTX,mynvtxs);

  /* store total degree of coarse vertices */
  cvwgt = dlthread_get_shmem((sizeof(vtx_type*)*nthreads) + \
      (sizeof(wgt_type*)*nthreads),ctrl->comm);
  gfcmap = (vtx_type**)(cvwgt+nthreads);

  cvwgt[myid] = wgt_alloc(mynvtxs);
  gfcmap[myid] = fcmap;
  gcmap[myid] = vtx_alloc(mynvtxs);

  seed = ctrl->seed+myid;

  dlthread_barrier(ctrl->comm);

  /* determine maximum degree */
  maxdeg = 0;
  for (v=0;v<mynvtxs;++v) {
    if (myxadj[v+1] - myxadj[v] > maxdeg) {
      maxdeg = myxadj[v+1] - myxadj[v];
    }
  }

  last_unmatched=0; /* this is private but ... */
  mycnvtxs = 0;
  collapsed = 0;

  vtx_incset(perm,0,1,mynvtxs);
  vtx_shuffle_r(perm,mynvtxs,&seed);

  for (v=0;v<mynvtxs;++v) {
    if (S_agg_limit_reached(mynvtxs,collapsed,0.7)) {
      break;
    }
    i = perm[v];
    if (gmatch[myid][i] == NULL_VTX) {
      maxidx = i;
      astart = myxadj[i];
      aend = myxadj[i+1];
      if (astart == aend) {
        last_unmatched = dl_max(v, last_unmatched)+1;
        for (; last_unmatched<mynvtxs; last_unmatched++) {
          k = perm[last_unmatched];
          if (gmatch[myid][k] == NULL_VTX) {
            maxidx = k;
            break;
          }
        }
      } else if (astart == aend+1) {
        maxidx = myadjncy[astart];
      } else {
        for (j=astart;j<aend;++j) {
          k = myadjncy[j];
          if (k < mynvtxs) {
            o = myid;
            l = k;
          } else {
            o = gvtx_to_tid(k,graph->dist);
            l = gvtx_to_lvtx(k,graph->dist);
          }
          if (gmatch[o][l] == NULL_VTX) {
            twgt = gvwgt[o][l];
          } else {
            cg = gcmap[o][l];
            cl = gvtx_to_lvtx(cg,graph->dist);
            co = gvtx_to_tid(cg,graph->dist);
            twgt = cvwgt[co][cl];
          }
          if (twgt + gvwgt[myid][i] < maxvwgt) {
            maxidx = k;
            break;
          }
        }
      }
      /* match maker make me a match */
      if (maxidx == i) {
        cvwgt[myid][mycnvtxs] = gvwgt[myid][i];
        gcmap[myid][i] = lvtx_to_gvtx(mycnvtxs,myid,graph->dist);
        DL_ASSERT(gcmap[myid][i]>=graph->dist.offset,"Generated global "
            "coarse vertex number is smaller than graph offset (gvtx = %"
            PF_VTX_T", offset = %"PF_VTX_T"\n",v,graph->dist.offset);
        ++mycnvtxs;
      } else {
        if (maxidx < mynvtxs) {
          o = myid;
          l = maxidx;
        } else {
          o = gvtx_to_tid(maxidx,graph->dist);
          l = gvtx_to_lvtx(maxidx,graph->dist);
        }
        if (gmatch[o][l] == NULL_VTX) { /* duh */
          cg = lvtx_to_gvtx(mycnvtxs,myid,graph->dist);
          cl = gvtx_to_lvtx(cg,graph->dist);
          co = gvtx_to_tid(cg,graph->dist);
          cvwgt[co][cl] = gvwgt[o][l] + gvwgt[myid][i];
          DL_ASSERT(cg>=graph->dist.offset,"Generated global coarse vertex "
              "number is smaller than graph offset (gvtx = %"PF_VTX_T
              ", offset = %"PF_VTX_T"\n",cg,graph->dist.offset);
          gcmap[myid][i] = gcmap[o][l] = cg;
          ++mycnvtxs;
        } else {
          cg = gcmap[myid][i] = gcmap[o][l];
          cl = gvtx_to_lvtx(cg,graph->dist);
          co = gvtx_to_tid(cg,graph->dist);
          cvwgt[co][cl] += gvwgt[myid][i];
        }
      }
      collapsed += S_cluster(i,maxidx,myid,gmatch,graph);
    }
  }
  dlthread_barrier(ctrl->comm);

  /* reset the cmap so I perform cycle clean up */
  vtx_set(gcmap[myid],NULL_VTX,mynvtxs);

  dl_free(perm);

  dlthread_barrier(ctrl->comm);

  mycnvtxs = S_cleanup_cluster(mynvtxs,myid,gmatch,gcmap,gfcmap,graph);

  /* implicit barrier */ 
  dl_free(cvwgt[myid]);
  dlthread_free_shmem(cvwgt,ctrl->comm);

  if (myid == 0) {
    ++ctrl->seed;
  }

  return mycnvtxs;
}




/******************************************************************************
* PUBLIC PARALLEL FUNCTIONS ***************************************************
******************************************************************************/


vtx_type par_aggregate_graph(
    ctrl_type * const ctrl,
    graph_type * const graph,
    vtx_type * const * const gmatch,
    vtx_type * const fcmap)
{
  vtx_type i, cnvtxs, nunmatched;

  tid_type const myid = dlthread_get_id(ctrl->comm);

  vtx_type const mynvtxs = graph->mynvtxs[myid];

  if (myid == 0) { 
    dl_start_timer(&ctrl->timers.matching);
  }

  /* suppress compiler warnings -- logically, initial value will never be 
   * used. */
  cnvtxs = 0;

  /* coarsening scheme selection used to go here */
  switch(ctrl->ctype) {
    case MTMETIS_CTYPE_RM:
      cnvtxs = S_coarsen_match_RM(ctrl,graph,gmatch,fcmap);
      break;
    case MTMETIS_CTYPE_SHEM:
      if (graph->uniformadjwgt) {
        cnvtxs = S_coarsen_match_RM(ctrl,graph,gmatch,fcmap);
      } else {
        cnvtxs = S_coarsen_match_SHEM(ctrl,graph,gmatch,fcmap);
      }
      break;
    case MTMETIS_CTYPE_FC:
      if (graph->uniformadjwgt) {
        cnvtxs = S_coarsen_cluster_RC(ctrl,graph,gmatch,fcmap);
      } else {
        cnvtxs = S_coarsen_cluster_FC(ctrl,graph,gmatch,fcmap);
      }
      break;
    default:
      dl_error("Unknown ctype: %d\n",ctrl->ctype);
  }

  nunmatched = mynvtxs - (cnvtxs*2);

  /* fix leaves */
  if (ctrl->leafmatch && nunmatched > LEAF_MATCH_RATIO * mynvtxs) {
    cnvtxs = S_coarsen_match_leaves(ctrl,graph,gmatch,fcmap,cnvtxs, \
        MAXDEG_LEAF);
    cnvtxs = S_coarsen_match_twins(ctrl,graph,gmatch,fcmap,cnvtxs, \
        MAXDEG_TWIN);

    nunmatched = mynvtxs - (cnvtxs*2);
    if (nunmatched > 1.5*LEAF_MATCH_RATIO*mynvtxs) {
      cnvtxs = S_coarsen_match_leaves(ctrl,graph,gmatch,fcmap,cnvtxs, \
          2*MAXDEG_LEAF);
    }
    nunmatched = mynvtxs - (cnvtxs*2);
    if (nunmatched > 2.0*LEAF_MATCH_RATIO*mynvtxs) {
      cnvtxs = S_coarsen_match_leaves(ctrl,graph,gmatch,fcmap,cnvtxs, \
          2*MAXDEG_LEAF);
    }
  }

  /* fix unmatched vertices */
  for (i=0;i<mynvtxs;++i) {
    if (gmatch[myid][i] == i) {
      graph->cmap[myid][i] = lvtx_to_gvtx(cnvtxs,myid,graph->dist);
      fcmap[cnvtxs] = i;
      ++cnvtxs;
    }
  }

  dlthread_barrier(ctrl->comm);

  if (myid == 0) {
    dl_stop_timer(&(ctrl->timers.matching));
  }

  return cnvtxs;
}


#endif

