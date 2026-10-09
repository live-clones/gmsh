/**
 * @file partition.c
 * @brief Partitioning functions
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright 2014, Regents of the University of Minnesota
 * @version 1
 * @date 2013-05-20
 */




#ifndef MTMETIS_PARTITION_C
#define MTMETIS_PARTITION_C




#include "partition.h"
#include "coarsen.h"
#include "initpart.h"
#include "uncoarsen.h"
#include "refine.h"
#include "check.h"
#include "imetis.h"




/******************************************************************************
* CONSTANTS *******************************************************************
******************************************************************************/


static double const MIN_UFACTOR = 1.002;




/******************************************************************************
* PRIVATE SERIAL FUNCTIONS ****************************************************
******************************************************************************/


/**
 * @brief Calcuate teh edgecut of a partitioning, serially.
 *
 * @param graph The graph.
 * @param where The partition ids.
 *
 * @return  The total weight of cut edges.
 */
static wgt_type S_ser_calc_cut(
    graph_type const * const graph,
    pid_type const * const * const where)
{
  vtx_type i,k,l,mynvtxs;
  adj_type j;
  wgt_type cut;
  pid_type me, other;
  tid_type myid, o;

  tid_type const nthreads = graph->dist.nthreads;

  cut = 0;
  for (myid=0;myid<nthreads;++myid) {
    mynvtxs = graph->mynvtxs[myid];
    for (i=0;i<mynvtxs;++i) {
      me = where[myid][i];
      for (j=graph->xadj[myid][i];j<graph->xadj[myid][i+1];++j) {
        k = graph->adjncy[myid][j];
        if (k > mynvtxs) {
          l = gvtx_to_lvtx(k,graph->dist);
          o = gvtx_to_tid(k,graph->dist);
        } else {
          l = k;
          o = myid;
        }
        other = where[o][l];
        if (other != me) {
          cut += graph->adjwgt[myid][j];
        }
      }
    }
  }

  return cut/2;
}


/**
 * @brief Calculate the communication volume of partitioning (serially).
 *
 * @param graph The partitioned graph.
 * @param where The partition IDs.
 * @param nparts The number of partitions.
 *
 * @return The communication volume. 
 */
static vtx_type S_ser_calc_comvol(
    graph_type const * const graph,
    pid_type const * const * const where,
    pid_type const nparts)
{
  vtx_type vol, i, k, l, mynvtxs, g;
  adj_type j;
  pid_type me, other;
  tid_type o, myid;
  vtx_type * marker;

  tid_type const nthreads = graph->dist.nthreads;

  marker = vtx_init_alloc(NULL_VTX,nparts);

  vol = 0;
  for (myid=0;myid<nthreads;++myid) {
    mynvtxs = graph->mynvtxs[myid];
    for (i=0;i<mynvtxs;++i) {
      me = where[myid][i];
      g = lvtx_to_gvtx(i,myid,graph->dist);
      marker[me] = g; 
      for (j=graph->xadj[myid][i];j<graph->xadj[myid][i+1];++j) {
        k = graph->adjncy[myid][j];
        if (k > mynvtxs) {
          l = gvtx_to_lvtx(k,graph->dist);
          o = gvtx_to_tid(k,graph->dist);
        } else {
          l = k;
          o = myid;
        }
        other = where[o][l];
        if (marker[other] != g) {
          marker[other] = g;
          ++vol;
        }
      }
    }
  }

  dl_free(marker);

  return vol;
}


/**
 * @brief Calculate the size of the vertex separator.
 *
 * @param graph The partitioned graph.
 * @param where The partition ids of all vertices.
 *
 * @return The weight of the vertex separator.
 */
static wgt_type S_ser_calc_vsep(
    graph_type const * const graph,
    pid_type const * const * const where)
{
  vtx_type mynvtxs, i;
  pid_type me;
  tid_type myid;
  wgt_type sep;

  tid_type const nthreads = graph->dist.nthreads;

  sep = 0;

  for (myid=0;myid<nthreads;++myid) {
    mynvtxs = graph->mynvtxs[myid];
    for (i=0;i<mynvtxs;++i) {
      me = where[myid][i];
      if (me == MTMETIS_VSEP_SEP) {
        sep += graph->vwgt[myid][i];
      }
    }
  }

  return sep;
}




/******************************************************************************
* PRIVATE PARALLEL FUNCTIONS **************************************************
******************************************************************************/


static wgt_type S_par_partition_mlevel(
    ctrl_type * const ctrl,
    graph_type * const graph)
{
  wgt_type obj;
  double ratio;
  graph_type * cgraph;

  /* coaresn this level */
  cgraph = par_coarsen_graph(ctrl,graph);

  /* if we reduce total graph size, or just vertices keep going */
  ratio = dl_min(graph_size(cgraph)/(double)(graph_size(graph)), \
      cgraph->nvtxs/(double)graph->nvtxs);

  if (cgraph->nvtxs <= ctrl->coarsen_to || ratio > ctrl->stopratio) {
    par_vprintf(ctrl->verbosity,MTMETIS_VERBOSITY_HIGH,"Coarsest graph{%zu} " \
        "has %"PF_VTX_T" vertices, %"PF_ADJ_T" edges, and %"PF_TWGT_T \
        " exposed edge weight.\n",graph->level,graph->nvtxs, \
        graph->nedges,graph->tadjwgt);

    switch (ctrl->ptype) {
      case MTMETIS_PTYPE_ND:
      case MTMETIS_PTYPE_VSEP:
        par_initpart_vsep(ctrl,cgraph);
        break;
      case MTMETIS_PTYPE_ESEP:
      case MTMETIS_PTYPE_RB:
      case MTMETIS_PTYPE_KWAY:
        par_initpart_cut(ctrl,cgraph);
        break;
      default:
        dl_error("Unknown partition type '%d'\n",ctrl->ptype);
    }

    par_refine_graph(ctrl,cgraph);
  } else {
    /* recurse */
    S_par_partition_mlevel(ctrl,cgraph);
  }

  /* uncoarsen this level */
  par_uncoarsen_graph(ctrl, graph);

  dlthread_barrier(ctrl->comm);

  switch (ctrl->ptype) {
    case MTMETIS_PTYPE_ND:
    case MTMETIS_PTYPE_VSEP:
      obj = graph->minsep;
      break;
    case MTMETIS_PTYPE_ESEP:
    case MTMETIS_PTYPE_RB:
    case MTMETIS_PTYPE_KWAY:
      obj = graph->mincut;
      break;
    default:
      dl_error("Unknown partition type '%d'\n",ctrl->ptype);
  }

  return obj;
}


/**
 * @brief Create a partitioning via recursive bisection.
 *
 * @param ctrl The control structure containing partitioning information.
 * @param graph The graph to partition.
 * @param gwhere The partition id for each vertex (output).
 * @param ratio The ratio of the weight of this subgraph versus its target
 * weight (1.0 for no recursive cases).
 *
 * @return The weight of the edgecut. 
 */
static wgt_type S_par_partition_mlevel_rb(
    ctrl_type * const ctrl,
    graph_type * const graph,
    pid_type ** const gwhere,
    real_type const ratio) 
{
  vtx_type v, g, mynvtxs, lvtx;
  tid_type hmyid, lid;
  dlthread_comm_t lcomm;
  pid_type p, pid;
  wgt_type cut;
  pid_type * offset;
  ctrl_type * myctrl;
  wgt_type htwgt[2];

  graph_type ** hgraphs;
  pid_type *** hgwhere;

  tid_type const nthreads = dlthread_get_nthreads(ctrl->comm);
  tid_type const myid = dlthread_get_id(ctrl->comm);

  if (ctrl->nparts == 1) {
    /* each thread just assign a label to its vertices */
    pid_set(gwhere[myid],0,graph->mynvtxs[myid]);
    if (myid == 0) {
      graph->mincut = 0;
      graph->pwgts = wgt_init_alloc(graph->tvwgt,1);
    }
  } else {
    offset = pid_init_alloc(0,3);
    for (p=0;p<ctrl->nparts;++p) {
      pid = (p/(double)ctrl->nparts)*2;
      ++offset[pid];
    }
    pid_prefixsum_exc(offset,3);

    /* initial bisection */
    myctrl = par_ctrl_rb(ctrl,offset);
    htwgt[0] = myctrl->tpwgts[0]*graph->tvwgt;
    htwgt[1] = myctrl->tpwgts[1]*graph->tvwgt;
    myctrl->ubfactor = dl_max( \
        pow(ctrl->ubfactor,1.0/pid_downlog2(ctrl->nparts))/ratio,MIN_UFACTOR);
    par_dprintf("Using ufactor of %"PF_REAL_T" for %"PF_PID_T" parts\n", \
        myctrl->ubfactor,ctrl->nparts);
    par_partition_edgeseparator(myctrl,graph,gwhere);
    if (myid == 0)  {
      ctrl_combine_timers(ctrl,myctrl);
    }
    par_ctrl_free(myctrl);

    /* handle the case where we've made our final bisection */
    if (ctrl->nparts > 2) {
      if (myid == 0) {
        dl_start_timer(&(ctrl->timers.recursion));
      }

      hgraphs = dlthread_get_shmem((sizeof(graph_type*)*2) + \
          (sizeof(pid_type**)*2),ctrl->comm);
      hgwhere = (pid_type***)(hgraphs+2);

      /* extract subgraphs and structure based on number of calling threads */
      par_graph_extract_parts(graph,(pid_type const **)gwhere,2,hgraphs);

      if (myid == 0) {
        dl_stop_timer(&(ctrl->timers.recursion));
      }

      for (pid=myid%2;pid<2;pid+=nthreads) {
        lcomm = hgraphs[pid]->comm;

        hmyid = dlthread_get_id(lcomm);

        myctrl = par_ctrl_split(ctrl,hgraphs[pid]->nvtxs, \
            offset[pid+1]-offset[pid],lcomm);

        /* setup pijbm */
        if (hmyid == 0) {
          if (!myctrl->pijbm) {
            myctrl->pijbm = real_alloc(myctrl->nparts);
          }
          for (p=0;p<myctrl->nparts;++p) {
            myctrl->pijbm[p] = hgraphs[pid]->invtvwgt / myctrl->tpwgts[p];
          }
        }

        DL_ASSERT_EQUALS((size_t)myctrl->comm,(size_t)hgraphs[pid]->comm, \
            "%zu");

        hgwhere[pid] = dlthread_get_shmem(sizeof(pid_type*)*nthreads,lcomm);
        hgwhere[pid][hmyid] = pid_alloc(hgraphs[pid]->mynvtxs[hmyid]);

        cut = S_par_partition_mlevel_rb(myctrl,hgraphs[pid], \
            hgwhere[pid],hgraphs[pid]->tvwgt/(real_type)htwgt[pid]);

        if (myid == 0) {
          ctrl_combine_timers(ctrl,myctrl);
        }

        par_ctrl_free(myctrl);

        /* project my newly partitioned vertices */
        mynvtxs = hgraphs[pid]->mynvtxs[hmyid];
        for (v=0;v<mynvtxs;++v) {
          g = hgraphs[pid]->label[hmyid][v];
          lid = gvtx_to_tid(g,graph->dist);
          lvtx = gvtx_to_lvtx(g,graph->dist);
          gwhere[lid][lvtx] = hgwhere[pid][hmyid][v] + offset[pid];
        }

        if (hmyid == 0) {
          dlthread_exclude(ctrl->comm);
          graph->mincut += cut;
          dlthread_unexclude(ctrl->comm);
        }

        dl_free(hgwhere[pid][hmyid]);
        dlthread_free_shmem(hgwhere[pid],lcomm);

        par_graph_free(hgraphs[pid]);

        dlthread_comm_finalize(lcomm);
      }
      dlthread_free_shmem(hgraphs,ctrl->comm);
    }
    dl_free(offset);
  }

  dlthread_barrier(ctrl->comm);

  return graph->mincut;
}


/**
 * @brief Top level partitioning function. Given a graph and a control
 * structure, generate a partitioning according to paramters. 
 *
 * @param ctrl The control structure containing partitioning paramters.
 * @param graph The graph to partition.
 * @param where The partition IDs of each vertex (output).
 *
 * @return The objective (weight of edge or vertex separator).
 */
static wgt_type S_par_partition(
    ctrl_type * const ctrl,
    graph_type * const graph,
    pid_type * const * const where)
{
  size_t run;
  vtx_type i;
  wgt_type curobj, bestobj;
  double curbal, bestbal;
  wgt_type * pwgts, * lpwgts;
  pid_type ** gwhere;

  tid_type const myid = dlthread_get_id(ctrl->comm);
  tid_type const nthreads = dlthread_get_nthreads(ctrl->comm);

  pwgts = NULL;

  if (ctrl->removeislands) {
    if (myid == 0) {
      dl_start_timer(&ctrl->timers.preprocess);
    }

    par_graph_removeislands(ctrl,graph);

    pwgts = dlthread_get_shmem(sizeof(wgt_type)*ctrl->nparts,ctrl->comm);

    if (myid == 0) {
      dl_stop_timer(&ctrl->timers.preprocess);
    }
  }

  if (myid == 0) {
    dl_start_timer(&ctrl->timers.partitioning);
  }

  curobj = bestobj = 0;
  curbal = bestbal = 0;

  for (run=0;run<ctrl->nruns;++run) {
    if (nthreads == 1 && ctrl->metis_serial) {
      /* create where */
      graph->where = r_pid_alloc(1);
      graph->where[0] = pid_alloc(graph->mynvtxs[0]);

      switch (ctrl->ptype) { 
        case MTMETIS_PTYPE_ND:
        case MTMETIS_PTYPE_VSEP:
          curobj = metis_vsep(ctrl,graph,graph->where);
          break;
        case MTMETIS_PTYPE_ESEP:
          curobj = metis_esep(ctrl,graph,graph->where);
          break;
        case MTMETIS_PTYPE_RB:
          curobj = metis_kway(ctrl,graph,graph->where,1);
          break;
        case MTMETIS_PTYPE_KWAY:
          curobj = metis_kway(ctrl,graph,graph->where,0);
          break;
        default:
          dl_error("Unknown partitoin type '%d'\n",ctrl->ptype);
      }

      /* compute pwgts */
      graph->pwgts = wgt_init_alloc(0,ctrl->nparts);
      for (i=0;i<graph->mynvtxs[0];++i) {
        graph->pwgts[graph->where[0][i]] += graph->vwgt[0][i]; 
      }
    } else {
      switch (ctrl->ptype) {
        case MTMETIS_PTYPE_RB: /* special case */
          /* create where */
          gwhere = dlthread_get_shmem(sizeof(pid_type*)*nthreads,ctrl->comm);
          gwhere[myid] = pid_alloc(graph->mynvtxs[myid]);

          curobj = S_par_partition_mlevel_rb(ctrl,graph,gwhere,1.0);

          /* compute pwgts */
          lpwgts = wgt_init_alloc(0,ctrl->nparts);
          for (i=0;i<graph->mynvtxs[myid];++i) {
            lpwgts[gwhere[myid][i]] += graph->vwgt[myid][i]; 
          }

          wgt_dlthread_sumareduce(lpwgts,ctrl->nparts,ctrl->comm);

          /* assign where */
          if (myid == 0) {
            graph->where = gwhere;
            graph->pwgts = lpwgts;
          } else {
            dl_free(lpwgts);
          }

          dlthread_barrier(ctrl->comm);
          break;
        case MTMETIS_PTYPE_ND:
        case MTMETIS_PTYPE_VSEP:
        case MTMETIS_PTYPE_ESEP:
        case MTMETIS_PTYPE_KWAY:
        default:
          /* everyone else works fine with this */
          curobj = S_par_partition_mlevel(ctrl,graph);
      }
    }

    curbal = graph_imbalance_diff(graph,ctrl->nparts,ctrl->pijbm, \
        ctrl->ubfactor);

    if (run == 0 \
        || (curbal <= 0.0005 && bestobj > curobj) \
        || (bestbal > 0.0005 && curbal < bestbal)) {
      pid_copy(where[myid],graph->where[myid],graph->mynvtxs[myid]);
      bestobj = curobj;
      bestbal = curbal;
      if (pwgts && myid == 0) {
        wgt_copy(pwgts,graph->pwgts,ctrl->nparts);
      }
    }

    par_graph_free_rdata(graph);

    ++ctrl->seed;

    if (ctrl->runstats) {
      ctrl->runs[run] = curobj;
    }

    if (bestobj == 0 && curbal <= 0.0005) {
      break;
    }
  }

  if (myid == 0) {
    dl_stop_timer(&ctrl->timers.partitioning);
  }

  if (graph->nislands) {
    if (myid == 0) {
      dl_start_timer(&ctrl->timers.preprocess);
      graph->pwgts = pwgts;
    }

    par_graph_restoreislands(ctrl,graph,where);

    if (myid == 0) {
      graph->pwgts = NULL;
      dl_stop_timer(&ctrl->timers.preprocess);
    }
  }

  if (pwgts) {
    dlthread_free_shmem(pwgts,ctrl->comm);
  }

  return bestobj;
}



/******************************************************************************
* PUBLIC SERIAL FUNCTIONS *****************************************************
******************************************************************************/


void partition_print_info(
    ctrl_type const * ctrl,
    graph_type const * graph,
    pid_type const * const * where)
{
  vtx_type i, k, mynvtxs;
  pid_type nparts, p, q;
  tid_type myid;
  wgt_type tvwgt, mvwgt;
  wgt_type * kpwgts;
  real_type * tpwgts;
  double unbalance;
  const wgt_type *vwgt; 
  const pid_type *mywhere;

  nparts = ctrl->nparts;
  tpwgts = ctrl->tpwgts;

  dl_print_footer('*');
  printf(" size of vtx_type: %zu, adj_type: %zu, wgt_type: %zu, pid_type: %zu, tid_type: " \
      "%zu, real_type: %zu\n",8*sizeof(vtx_type), 8*sizeof(adj_type), 8*sizeof(wgt_type), \
      8*sizeof(pid_type), 8*sizeof(tid_type), 8*sizeof(real_type));
  printf("\n");

  printf("\n");
  if (ctrl->ptype == MTMETIS_PTYPE_KWAY || ctrl->ptype == MTMETIS_PTYPE_ESEP \
      || ctrl->ptype == MTMETIS_PTYPE_RB) {

    switch (ctrl->ptype) {
      case MTMETIS_PTYPE_KWAY:
        dl_print_header("Direct k-way Partitioning",'-');
        break;
      case MTMETIS_PTYPE_RB:
        dl_print_header("Recursive Bisection Partitioning",'-');
        break;
      case MTMETIS_PTYPE_ESEP:
        dl_print_header("Direct Bisection Partitioning",'-');
        break;
    }

    /* Compute objective-related infomration */
    printf(" - Edgecut: %"PF_WGT_T", communication volume: %"PF_VTX_T".\n\n", \
      S_ser_calc_cut(graph,where),S_ser_calc_comvol(graph,where, \
        nparts));


    /* Compute constraint-related information */
    kpwgts = wgt_init_alloc(0,nparts);

    for (myid=0;myid<graph->dist.nthreads;++myid) {
      mynvtxs = graph->mynvtxs[myid];
      vwgt = graph->vwgt[myid];
      mywhere = where[myid];
      for (i=0; i<mynvtxs; ++i) {
        kpwgts[mywhere[i]] += vwgt[i];
      }
    }

    /* Report on balance */
    printf(" - Balance:\n");
    tvwgt = wgt_sum(kpwgts,nparts);
    q = 0;
    unbalance = 1.0*kpwgts[q]/(tpwgts[q]*tvwgt);
    for (p=1;p<nparts;++p) {
      if (unbalance < 1.0*kpwgts[p]/(tpwgts[p]*tvwgt)) {
        unbalance = 1.0*kpwgts[p]/(tpwgts[p]*tvwgt);
        k = i;
      }
    }
    mvwgt = 0;
    for (myid=0;myid<graph->dist.nthreads;++myid) {
      if ((mynvtxs = graph->mynvtxs[myid]) > 0) {
        vwgt = graph->vwgt[myid];
        k = wgt_max_index(vwgt,mynvtxs);
        if (vwgt[k] > mvwgt) {
          mvwgt = vwgt[k];
        }
      }
    }

    printf("     constraint #0:  %5.3lf out of %5.3lf\n", \
        unbalance, 1.0*nparts*mvwgt/ (1.0*tvwgt));
    printf("\n");
    p=0; 
    unbalance=kpwgts[p]/(tpwgts[p]*tvwgt);
    for (q=1;q<nparts;++q) {
      if (unbalance < kpwgts[q]/(tpwgts[q]*tvwgt)) {
        unbalance = kpwgts[q]/(tpwgts[q]*tvwgt);
        p = q;
      }
    }

    printf(" - Most overweight partition:\n");
    printf("     pid: %"PF_PID_T", actual: %"PF_WGT_T", desired: %"PF_WGT_T \
           ", ratio: %.2lf\n",p,kpwgts[p],(wgt_type)(tvwgt*tpwgts[p]),unbalance);
    printf("\n");

  } else if (ctrl->ptype == MTMETIS_PTYPE_VSEP) {
    dl_print_header("Vertex Separator",'-');

    printf(" - Separator Size: %"PF_WGT_T".\n\n", \
        S_ser_calc_vsep(graph,where));

    kpwgts = wgt_init_alloc(0,3);

    for (myid=0;myid<graph->dist.nthreads;++myid) {
      mynvtxs = graph->mynvtxs[myid];
      vwgt = graph->vwgt[myid];
      mywhere = where[myid];
      for (i=0; i<mynvtxs; ++i) {
        kpwgts[mywhere[i]] += vwgt[i];
      }
    }

    printf(" - Balance:\n");

    tvwgt = wgt_sum(kpwgts,2);
    if (kpwgts[0] > kpwgts[1]) {
      p = 0;
    } else {
      p = 1;
    }
    unbalance = 2.0*kpwgts[p]/tvwgt;
    
    printf(" - Most overweight partition:\n");
    printf("     pid: %"PF_PID_T", actual: %"PF_WGT_T", desired: %"PF_WGT_T \
           ", ratio: %.2lf\n",p,kpwgts[p],(wgt_type)(tvwgt*0.5),unbalance);
    printf("\n");
  } else {
    dl_error("Unknown partition type '%d'\n",ctrl->ptype);
  }

  dl_free(kpwgts);

  dl_print_footer('*');
}            




/******************************************************************************
* PUBLIC PARALLEL FUNCTIONS ***************************************************
******************************************************************************/


void par_partition_kway(
    ctrl_type * const ctrl, 
    graph_type * const graph, 
    pid_type ** const where)
{
  pid_type i;
  wgt_type cut;

  tid_type const myid = dlthread_get_id(ctrl->comm);

  /* set up multipliers for making balance computations easier */
  if (myid == 0) {
    if (!ctrl->pijbm) {
      ctrl->pijbm = real_alloc(ctrl->nparts);
    }
    for (i=0;i<ctrl->nparts;++i) {
      ctrl->pijbm[i] = graph->invtvwgt / ctrl->tpwgts[i];
    }
  }
  dlthread_barrier(ctrl->comm);

  cut = S_par_partition(ctrl,graph,where); 

  if (myid == 0) {
    graph->mincut = cut;
  }

  dlthread_barrier(ctrl->comm);
}


void par_partition_rb(
    ctrl_type * const ctrl,
    graph_type * const graph,
    pid_type ** const where)
{
  pid_type i;
  wgt_type cut;

  tid_type const myid = dlthread_get_id(ctrl->comm);

  /* set up multipliers for making balance computations easier */
  if (myid == 0) {
    if (!ctrl->pijbm) {
      ctrl->pijbm = real_alloc(ctrl->nparts);
    }
    for (i=0;i<ctrl->nparts;++i) {
      ctrl->pijbm[i] = graph->invtvwgt / ctrl->tpwgts[i];
    }
  }
  dlthread_barrier(ctrl->comm);

  cut = S_par_partition(ctrl,graph,where);

  if (myid == 0) {
    graph->mincut = cut;
  }

  dlthread_barrier(ctrl->comm);
}


void par_partition_vertexseparator(
    ctrl_type * const ctrl, 
    graph_type * const graph, 
    pid_type ** const where)
{
  pid_type i;
  tid_type const myid = dlthread_get_id(ctrl->comm);

  /* set up multipliers for making balance computations easier */
  if (myid == 0) {
    if (!ctrl->pijbm) {
      ctrl->pijbm = real_alloc(ctrl->nparts);
    }
    for (i=0;i<ctrl->nparts;++i) {
      ctrl->pijbm[i] = graph->invtvwgt / ctrl->tpwgts[i];
    }
  }
  dlthread_barrier(ctrl->comm);

  S_par_partition(ctrl,graph,where);
}


void par_partition_edgeseparator(
    ctrl_type * const ctrl, 
    graph_type * const graph, 
    pid_type ** const where)
{
  wgt_type cut;
  pid_type i;

  tid_type const myid = dlthread_get_id(ctrl->comm);

  /* set up multipliers for making balance computations easier */
  if (myid == 0) {
    if (!ctrl->pijbm) {
      ctrl->pijbm = real_alloc(MTMETIS_ESEP_NPARTS);
    }
    for (i=0;i<MTMETIS_ESEP_NPARTS;++i) {
      ctrl->pijbm[i] = graph->invtvwgt / ctrl->tpwgts[i];
    }
  }
  dlthread_barrier(ctrl->comm);

  cut = S_par_partition(ctrl,graph,where);
  if (myid == 0) {
    graph->mincut = cut;
  }

  dlthread_barrier(ctrl->comm);
}


void par_partition_pre(
    ctrl_type * const ctrl,
    graph_type * const graph)
{
  vtx_type i;
  double options[MTMETIS_NOPTIONS];
  ctrl_type * sctrl;
  pid_type ** dperm;

  tid_type const myid = dlthread_get_id(graph->comm);
  tid_type const nthreads = dlthread_get_nthreads(graph->comm);

  if (myid == 0) {
    dl_start_timer(&ctrl->timers.preprocess);

    graph->ngroup = nthreads*ctrl->partfactor;
    graph->group = r_pid_alloc(nthreads);

    double_set(options,MTMETIS_VAL_OFF,MTMETIS_NOPTIONS);
    options[MTMETIS_OPTION_NTHREADS] = ctrl->nthreads;
    options[MTMETIS_OPTION_NPARTS] = graph->ngroup; 
    options[MTMETIS_OPTION_NITER] = 3;
  }
  dperm = dlthread_get_shmem(sizeof(pid_type*)*nthreads,ctrl->comm);

  graph->group[myid] = pid_alloc(graph->mynvtxs[myid]);

  par_ctrl_parse(options,&sctrl,ctrl->comm);
  par_ctrl_setup(sctrl,NULL,graph->nvtxs);
  par_partition_kway(sctrl,graph,graph->group);
  par_ctrl_free(sctrl);

  dperm[myid] = pid_alloc(graph->mynvtxs[myid]);
  for (i=0;i<graph->mynvtxs[myid];++i) {
    dperm[myid][i] = graph->group[myid][i] % nthreads;
  }

  par_graph_shuffle(ctrl,graph,(pid_type const **)dperm,0);

  dl_free(dperm[myid]);

  if (myid == 0) {
    dl_stop_timer(&ctrl->timers.preprocess);
  }
  dlthread_free_shmem(dperm,ctrl->comm);
}





#endif

