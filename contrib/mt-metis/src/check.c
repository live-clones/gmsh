/**
 * @file check.c
 * @brief This file contains various sanity checks intended for ASSERT
 * statements
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright 2012, Regents of the University of Minnesota
 * @version 1
 * @date 2012-07-02
 */




#ifndef MTMETIS_CHECK_C
#define MTMETIS_CHECK_C




#include "check.h"




/******************************************************************************
* PUBLIC FUNCTIONS ************************************************************
******************************************************************************/


int check_kwinfo(
    kwinfo_type const * const kwinfo,
    graph_type const * const graph,
    pid_type const * const * const where)
{
  vtx_type i,k,mynvtxs,gvtx,lvtx;
  adj_type j;
  wgt_type ted, tid, m;
  pid_type me, other, nnbrs, nbrid, p;
  adj_type const * xadj;
  vtx_type const * adjncy;
  wgt_type const * adjwgt;
  pid_type const * mywhere;
  kwnbrinfo_type const * myrinfo;
  adjinfo_type const * mynbrs;

  pid_type const nparts = kwinfo->nparts;

  tid_type const myid = dlthread_get_id(graph->comm);

  wgt_type htable[nparts];

  mynvtxs = graph->mynvtxs[myid];
  xadj = graph->xadj[myid];
  adjncy = graph->adjncy[myid];
  adjwgt = graph->adjwgt[myid];
  mywhere = where[myid];
  for (i=0;i<mynvtxs;++i) {
    nnbrs = tid = ted = 0;
    wgt_set(htable,NULL_WGT,nparts);
    me = mywhere[i];
    gvtx = lvtx_to_gvtx(i,myid,graph->dist);
    for (j=xadj[i];j<xadj[i+1];++j) {
      k = adjncy[j];
      if (k < mynvtxs) {
        lvtx = k;
        nbrid = myid;
      } else {
        lvtx = gvtx_to_lvtx(k,graph->dist);
        nbrid = gvtx_to_tid(k,graph->dist);
      }
      other = where[nbrid][lvtx];
      if (other != me) {
        if ((m = htable[other]) != NULL_WGT) {
          htable[other] += adjwgt[j];
        } else {
          htable[other] = adjwgt[j];
          ++nnbrs;
        }
        ted += adjwgt[j];
      } else {
        tid += adjwgt[j];
      }
    }
    myrinfo = kwinfo->nbrinfo + i;
    mynbrs = kwinfo_get_nbrs_ro(kwinfo,i,dl_min(nparts,xadj[i+1]-xadj[i]));

    if (myrinfo->id != tid) {
      printf("[%"PF_TID_T"] Mismatch of internal degree of vertex %" \
          PF_VTX_T"(%"PF_VTX_T") in p%"PF_PID_T" (expected [%"PF_WGT_T \
          ":%"PF_WGT_T"], but got [%"PF_WGT_T":%"PF_WGT_T"])\n",myid,gvtx, \
          i,me,tid,ted,myrinfo->id,myrinfo->ed);
      printf("[%"PF_TID_T"] R-Neighbors = {",myid);
      for (p=0;p<nparts;++p) {
        if (htable[p] > 0) {
          printf("[p%"PF_PID_T",w%"PF_WGT_T"]",p,htable[p]);
        }
      }
      printf("}\n");
      printf("[%"PF_TID_T"] E-Neighbors = {",myid);
      for (i=0;i<myrinfo->nnbrs;++i) {
        printf("[p%"PF_PID_T",w%"PF_WGT_T"]",mynbrs[i].pid,mynbrs[i].ed);
      }
      printf("}\n");

      return 0;
    } else if (myrinfo->ed != ted) {
      printf("[%"PF_TID_T"] Mismatch of external degree of vertex %" \
          PF_VTX_T"(%"PF_VTX_T") in p%"PF_PID_T" (expected [%"PF_WGT_T":%" \
          PF_WGT_T"], but got [%"PF_WGT_T":%"PF_WGT_T"])\n",myid,gvtx,i,me, \
          tid,ted,myrinfo->id,myrinfo->ed);
      printf("[%"PF_TID_T"] R-Neighbors = {",myid);
      for (p=0;p<nparts;++p) {
        if (htable[p] > 0) {
          printf("[p%"PF_PID_T",w%"PF_WGT_T"]",p,htable[p]);
        }
      }
      printf("}\n");
      printf("[%"PF_TID_T"] E-Neighbors = {",myid);
      for (i=0;i<myrinfo->nnbrs;++i) {
        printf("[p%"PF_PID_T",w%"PF_WGT_T"]",mynbrs[i].pid,mynbrs[i].ed);
      }
      printf("}\n");

      return 0;
    } else if (myrinfo->nnbrs != nnbrs) {
      printf("[%"PF_TID_T"] Mismatch of number of neighbors of vertex %" \
          PF_VTX_T"(%"PF_VTX_T") in %"PF_PID_T" (expected %"PF_PID_T", " \
          "but got %"PF_PID_T")\n",myid,gvtx,i,me,nnbrs,myrinfo->nnbrs);
      printf("[%"PF_TID_T"] R-Neighbors = {",myid);
      for (p=0;p<nparts;++p) {
        if (htable[p] > 0) {
          printf("[p%"PF_PID_T",w%"PF_WGT_T"]",p,htable[p]);
        }
      }
      printf("}\n");
      printf("[%"PF_TID_T"] E-Neighbors = {",myid);
      for (i=0;i<myrinfo->nnbrs;++i) {
        printf("[p%"PF_PID_T",w%"PF_WGT_T"]",mynbrs[i].pid,mynbrs[i].ed);
      }
      printf("}\n");
      return 0;
    } else {
      for (j=0;j<nnbrs;++j) {
        other = mynbrs[j].pid;
        if (htable[other] == NULL_WGT) {
          printf("[%"PF_TID_T"] Vertex %"PF_VTX_T"(%"PF_VTX_T")[p%"PF_PID_T \
              "] thinks its connected to %"PF_PID_T"/%"PF_WGT_T"\n",myid, \
              gvtx,i,me,other,mynbrs[j].ed);
          printf("R : {");
          for (p=0;p<nparts;++p) {
            if (htable[p] != NULL_WGT) {
              printf("[p%"PF_PID_T":w%"PF_WGT_T"]",p,htable[p]);
            }
          }
          printf("}\n");
          printf("E : {");
          for (p=0;p<myrinfo->nnbrs;++p) {
            printf("[p%"PF_PID_T":w%"PF_WGT_T"]",mynbrs[p].pid,mynbrs[p].ed);
          }
          printf("}\n");

          return 0;
        } else if (htable[other] != mynbrs[j].ed) {
          printf("[%"PF_TID_T"] Mismatch of neighbor p%"PF_PID_T" weight " \
              "of vertex %"PF_VTX_T"(%"PF_VTX_T") of p%"PF_PID_T" " \
              "(expected %"PF_WGT_T", but got %"PF_WGT_T")\n",myid,other, \
              gvtx,i,me,htable[other],mynbrs[j].ed);
          return 0;
        }
      }
    }
  }
  return 1;
}


int check_vsinfo(
    vsinfo_type const * const vsinfo,
    graph_type const * const graph,
    pid_type const * const * const where)
{
  int rv;
  vtx_type i, k, lvtx;
  adj_type j;
  pid_type me, p;
  tid_type nbrid;
  wgt_type con[3];

  tid_type const myid = dlthread_get_id(graph->comm);

  vtx_type const mynvtxs = graph->mynvtxs[myid];
  adj_type const * const xadj = graph->xadj[myid];
  vtx_type const * const adjncy = graph->adjncy[myid];

  wgt_type const * const * const gvwgt = (wgt_type const **)graph->vwgt;

  rv = 1;

  for (i=0;i<mynvtxs;++i) {
    me = where[myid][i];

    if (me == MTMETIS_VSEP_SEP) {
      wgt_set(con,0,3);

      /* count connectivity */
      for (j=xadj[i];j<xadj[i+1];++j) {
        k = adjncy[j];
        if (k < mynvtxs) {
          lvtx = k;
          nbrid = myid;
        } else {
          lvtx = gvtx_to_lvtx(k,graph->dist);
          nbrid = gvtx_to_tid(k,graph->dist);
        }
        con[where[nbrid][lvtx]] += gvwgt[nbrid][lvtx];
      }

      if (where[myid][i] != MTMETIS_VSEP_SEP) {
        if (con[MTMETIS_VSEP_PARTA] > 0 && con[MTMETIS_VSEP_PARTB] > 0) {
          eprintf("Vertex %"PF_VTX_T" is in %"PF_PID_T" but is connected to " \
              "both sides (%"PF_WGT_T":%"PF_WGT_T":%"PF_WGT_T")",i, \
              where[myid][i],con[MTMETIS_VSEP_PARTA],con[MTMETIS_VSEP_PARTB], \
              con[MTMETIS_VSEP_SEP]);
          rv = 0;
        }
      }

      if (vsinfo->nbrinfo) {
        for (p=0;p<MTMETIS_VSEP_SEP;++p) {
          if (con[p] != vsinfo->nbrinfo[i].con[p]) {
            eprintf("Wrong connectivity to %"PF_PID_T" of %"PF_WGT_T" " \
                "(should be %"PF_WGT_T") for vertex %"PF_TID_T":%"PF_VTX_T \
                " in %"PF_PID_T"\n",p,vsinfo->nbrinfo[i].con[p],con[p],myid, \
                i,me);
            rv = 0;
          }
        }
      }
      if (rv == 0) {
        return 0;
      }
    }
  }
  
  return 1;
}


int check_esinfo(
    esinfo_type const * const esinfo,
    graph_type const * const graph,
    pid_type const * const * const gwhere)
{
  int rv;
  vtx_type i, k, p, lvtx;
  adj_type j;
  pid_type other;
  tid_type nbrid;
  wgt_type con[2];

  tid_type const myid = dlthread_get_id(graph->comm);

  vtx_type const mynvtxs = graph->mynvtxs[myid];
  adj_type const * const xadj = graph->xadj[myid];
  vtx_type const * const adjncy = graph->adjncy[myid];
  wgt_type const * const adjwgt = graph->adjwgt[myid];

  esnbrinfo_type const * const nbrinfo = esinfo->nbrinfo;
  vtx_iset_t const * const bnd = esinfo->bnd;

  rv = 1;

  for (p=0;p<bnd->size;++p) {
    i = vtx_iset_get(p,bnd);

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
    if (nbrinfo[i].con[0] != con[0] || nbrinfo[i].con[1] != con[1]) {
      eprintf("Vertex %"PF_TID_T":%"PF_VTX_T" in %"PF_PID_T" has " \
          "connectivity of [%"PF_WGT_T":%"PF_WGT_T"] but thinks it has [%" \
          PF_WGT_T":%"PF_WGT_T"]\n",myid,i,gwhere[myid][i],con[0],con[1], \
          nbrinfo[i].con[0],nbrinfo[i].con[1]);
      rv = 0;       
      break;
    }
  }
  
  return rv;
}


int check_graph(
    graph_type const * const graph)
{
  vtx_type mynvtxs, i, v, u, k, m, nvtxs;
  adj_type j, l, nedges;
  tid_type myid, nbrid;
  twgt_type tvwgt, tadjwgt;
  adj_type * xadj, * xudj;
  vtx_type * adjncy, * udjncy;
  wgt_type * adjwgt, * udjwgt;

  /* simple check */
  nvtxs = vtx_sum(graph->mynvtxs,graph->dist.nthreads);
  if (nvtxs != graph->nvtxs) {
    printf("Bad nvtxs: %"PF_VTX_T":%"PF_VTX_T"\n",nvtxs,graph->nvtxs);
    return 0;
  }
  nedges = adj_sum(graph->mynedges,graph->dist.nthreads);
  if (nedges != graph->nedges) {
    printf("Bad nedges: %"PF_ADJ_T":%"PF_ADJ_T"\n",nedges,graph->nedges);
    return 0;
  }

  tvwgt = 0;
  tadjwgt = 0;

  for (myid=0;myid<graph->dist.nthreads;++myid) {
    mynvtxs = graph->mynvtxs[myid];
    xadj = graph->xadj[myid];
    adjncy = graph->adjncy[myid];
    adjwgt = graph->adjwgt[myid];
    tvwgt += wgt_lsum(graph->vwgt[myid],mynvtxs);
    tadjwgt += wgt_lsum(graph->adjwgt[myid],xadj[mynvtxs]);

    /* simple check */
    if (xadj[mynvtxs] != graph->mynedges[myid]) {
      printf("[%"PF_TID_T"] Bad mynedges: %"PF_ADJ_T":%"PF_ADJ_T"\n",myid, \
          xadj[mynvtxs],graph->mynedges[myid]);
      return 0;
    }

    /* check structure */
    for (i=0;i<mynvtxs;++i) {
      v = lvtx_to_gvtx(i,myid,graph->dist);
      for (j=xadj[i];j<xadj[i+1];++j) {
        u = adjncy[j];
        if (u < mynvtxs) {
          k = u;
          nbrid = myid;
        } else {
          k = gvtx_to_lvtx(u,graph->dist);
          nbrid = gvtx_to_tid(u,graph->dist);
          if (nbrid == myid) {
            printf("Local vertex is stored as remote\n");
            return 0;
          }
        }
        xudj = graph->xadj[nbrid];
        udjncy = graph->adjncy[nbrid];
        udjwgt = graph->adjwgt[nbrid];
        /* find the reverse edge */
        for (l=xudj[k];l<xudj[k+1];++l) {
          m = udjncy[l];
          if (m < graph->mynvtxs[nbrid]) {
            m = lvtx_to_gvtx(m,nbrid,graph->dist);
          }
          if (m == v) {
            if (udjwgt[l] != adjwgt[j]) {
              printf("[%"PF_TID_T"] Adjwgt of edge {%"PF_VTX_T"/%"PF_VTX_T \
                  ":%"PF_TID_T",%"PF_VTX_T"/%"PF_VTX_T":%"PF_TID_T"} is " \
                  "uneven (%"PF_WGT_T":%"PF_WGT_T")\n",myid,i,mynvtxs,myid,k, \
                  graph->mynvtxs[nbrid],nbrid,adjwgt[j],udjwgt[l]);
              return 0;
            } else {
              break;
            }
          }
        }
        if (l == xudj[k+1]) {
          printf("[%"PF_TID_T"] Edge {%"PF_VTX_T"/%"PF_VTX_T":%"PF_TID_T",%" \
              PF_VTX_T"/%"PF_VTX_T":%"PF_TID_T"} is only in one direction\n", \
              myid,i,mynvtxs,myid,k,graph->mynvtxs[nbrid],nbrid);
          return 0;
        }
      }
    }
  }

  /* check sums */
  if (graph->tvwgt != tvwgt) {
    printf("Total vertex weight is %"PF_TWGT_T", but graph " \
        "thinks it is %"PF_TWGT_T"\n",tvwgt,graph->tvwgt);
    return 0;
  }
  if (graph->tadjwgt != tadjwgt) {
    printf("Total edge weight is %"PF_TWGT_T", but graph " \
        "thinks it is %"PF_TWGT_T"\n",tadjwgt,graph->tadjwgt);
    return 0;
  }
  if ((int)(graph->invtvwgt * tvwgt * 1.01) != 1) {
    printf("Inverse vertex weight is %lf, but graph " \
        "thinks it is %lf\n",1.0/tvwgt,graph->invtvwgt);
    return 0;
  }

  return 1;
}


int check_kwbnd(
    vtx_iset_t const * const bnd,
    graph_type const * const graph,
    int const greedy)
{
  vtx_type mynvtxs, i, lvtx, gvtx, k;
  adj_type j;
  pid_type nbrid, me, other;
  wgt_type tid, ted;
  adj_type * xadj;
  vtx_type * adjncy;
  wgt_type * adjwgt;

  pid_type const * const * const gwhere = (pid_type const **)graph->where;
  tid_type const myid = dlthread_get_id(graph->comm);
  
  xadj = graph->xadj[myid];
  adjncy = graph->adjncy[myid];
  adjwgt = graph->adjwgt[myid];
  mynvtxs = graph->mynvtxs[myid];
  for (i=0;i<mynvtxs;++i) {
    tid = ted =0;
    gvtx = lvtx_to_gvtx(i,myid,graph->dist);
    me = gwhere[myid][i];
    for (j=xadj[i];j<xadj[i+1];++j) {
      k = adjncy[j];
      if (k <mynvtxs) {
        lvtx = k;
        nbrid = myid;
      } else {
        lvtx = gvtx_to_lvtx(k,graph->dist);
        nbrid = gvtx_to_tid(k,graph->dist);
      }
      other = gwhere[nbrid][lvtx];
      if (me != other) {
        ted += adjwgt[j];
      } else {
        tid += adjwgt[j];
      }
    }
    if (is_bnd(tid,ted,greedy)) {
      if (!vtx_iset_contains(i,bnd)) {
        printf("[%"PF_TID_T"] vertex %"PF_VTX_T"(%"PF_VTX_T") should be " \
            "on the border [%"PF_WGT_T":%"PF_WGT_T"]\n",myid,gvtx,i,tid,ted);
        return 0;
      }
    } else if (vtx_iset_contains(i,bnd)) {
      printf("[%"PF_TID_T"] vertex %"PF_VTX_T"(%"PF_VTX_T") should not be " \
          "on the border [%"PF_WGT_T":%"PF_WGT_T"]\n",myid,gvtx,i,tid,ted);
      return 0;
    }
  }

  return 1;
}


int check_vsbnd(
    vtx_iset_t const * const bnd,
    graph_type const * const graph)
{
  vtx_type i;

  tid_type const myid = dlthread_get_id(graph->comm);
  pid_type const * const where = graph->where[myid];
  vtx_type const mynvtxs = graph->mynvtxs[myid];
  
  for (i=0;i<mynvtxs;++i) {
    if (where[i] == MTMETIS_VSEP_SEP) {
      if (!vtx_iset_contains(i,bnd)) {
        eprintf("Vertex %"PF_TID_T":%"PF_VTX_T" is in separator but not in " \
            " boundary\n",myid,i);
        return 0;
      }
    } else {
      if (vtx_iset_contains(i,bnd)) {
        eprintf("Vertex %"PF_TID_T":%"PF_VTX_T" is in partition %"PF_PID_T \
            " but is in boundary\n",myid,i,where[i]);
        return 0;
      }
    }
  }

  return 1;
}


int check_esbnd(
    vtx_iset_t const * const bnd,
    graph_type const * const graph)
{
  vtx_type i, k, lvtx;
  adj_type j;
  tid_type nbrid;
  pid_type me, other;

  tid_type const myid = dlthread_get_id(graph->comm);
  vtx_type const mynvtxs = graph->mynvtxs[myid];
  adj_type const * const xadj = graph->xadj[myid];
  vtx_type const * const adjncy = graph->adjncy[myid];

  pid_type const * const * const gwhere = (pid_type const **)graph->where;
  
  for (i=0;i<mynvtxs;++i) {
    me = gwhere[myid][i];
    for (j=xadj[i];j<xadj[i+1];++j) {
      k = adjncy[j];
      if (k <mynvtxs) {
        lvtx = k;
        nbrid = myid;
      } else {
        lvtx = gvtx_to_lvtx(k,graph->dist);
        nbrid = gvtx_to_tid(k,graph->dist);
      }
      other = gwhere[nbrid][lvtx];
      if (other != me) {
        if (!vtx_iset_contains(i,bnd)) {
          eprintf("Vertex %"PF_TID_T":%"PF_VTX_T" is connected to the other " \
              "side (%"PF_PID_T") but is not in the boundary\n",myid,i, \
              gwhere[myid][i]^0x01);
          return 0;
        }
        break;
      } 
    }
    if (j == xadj[i+1]) {
      if (j == xadj[i]) {
        /* island vertex */
        if (!vtx_iset_contains(i,bnd)) {
          eprintf("Vertex %"PF_TID_T":%"PF_VTX_T" is an island but is not " \
              "the boundary\n",myid,i);
          return 0;
        }
      } else {
        /* internal vertex */
        if (vtx_iset_contains(i,bnd)) {
          eprintf("Vertex %"PF_TID_T":%"PF_VTX_T" is not connected to the " \
              "other side (%"PF_PID_T") but is in the boundary\n",myid,i, \
              gwhere[myid][i]^0x01);
          return 0;
        }
      }
    }
  }

  return 1;
}


int check_separator(
    graph_type const * const graph,
    pid_type const * const * const gwhere)
{
  vtx_type i, k, lvtx, mynvtxs;
  adj_type j;
  pid_type me, other;
  tid_type nbrid, myid;
  adj_type * xadj;
  vtx_type * adjncy;

  tid_type const nthreads = dlthread_get_nthreads(graph->comm);

  for (myid=0;myid<nthreads;++myid) {
    mynvtxs = graph->mynvtxs[myid];
    xadj = graph->xadj[myid];
    adjncy = graph->adjncy[myid];
    for (i=0;i<mynvtxs;++i) {
      me = gwhere[myid][i];
      if (me != MTMETIS_VSEP_SEP) {
        for (j=xadj[i];j<xadj[i+1];++j) {
          k = adjncy[j];
          if (k <mynvtxs) {
            lvtx = k;
            nbrid = myid;
          } else {
            lvtx = gvtx_to_lvtx(k,graph->dist);
            nbrid = gvtx_to_tid(k,graph->dist);
          }
          other = gwhere[nbrid][lvtx];
          if (other != me && other != MTMETIS_VSEP_SEP) {
            eprintf("Non-separator vertex %"PF_TID_T":%"PF_VTX_T" in %" \
                PF_PID_T" is connected to %"PF_PID_T"\n",myid,i,me,other);
            return 0;
          }
        }
      }
    }
  }

  return 1;
}


#endif
