/**
 * @file imetis.c
 * @brief Metis wrappers 
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright 2015, Regents of the University of Minnesota
 * @version 1
 * @date 2015-06-08
 */




#ifndef MTMETIS_IMETIS_C
#define MTMETIS_IMETIS_C




#include "imetis.h"
#include "../metis/include/metis.h"




/******************************************************************************
* PRIVATE FUNCTIONS ***********************************************************
******************************************************************************/


static void S_create_arrays(
    vtx_type const nvtxs,
    adj_type const * const xadj,
    vtx_type const * const adjncy,
    wgt_type const * const vwgt,
    wgt_type const * const adjwgt,
    pid_type * const where,
    idx_t ** r_xadj,
    idx_t ** r_adjncy,
    idx_t ** r_vwgt,
    idx_t ** r_adjwgt,
    idx_t ** r_where)
{
  vtx_type i;
  adj_type j;

  /* copy xadj if need be */
  if (sizeof(**r_xadj) != sizeof(*xadj)) {
    *r_xadj = malloc(sizeof(**r_xadj)*(nvtxs+1));
    for (i=0;i<nvtxs+1;++i) {
      (*r_xadj)[i] = (idx_t)xadj[i];
    }
  } else {
    *r_xadj = (idx_t*)xadj; 
  }

  /* copy adjncy if need-be */
  if (sizeof(**r_adjncy) != sizeof(*adjncy)) {
    *r_adjncy = malloc(sizeof(**r_adjncy)*xadj[nvtxs]);
    for (j=0;j<xadj[nvtxs];++j) {
      (*r_adjncy)[j] = (idx_t)adjncy[j];
    }
  } else {
    *r_adjncy = (idx_t*)adjncy;
  }

  /* copy vertex weights if need-be -- the comparison of 0.5 is a ugly hack to
   * see if we're using floats */
  if (sizeof(**r_vwgt) != sizeof(*vwgt) ||
      (idx_t)0.5 != (wgt_type)0.5) {
    *r_vwgt = malloc(sizeof(**r_vwgt)*nvtxs);
    for (i=0;i<nvtxs;++i) {
      (*r_vwgt)[i] = (idx_t)vwgt[i];
    }
  } else {
    *r_vwgt = (idx_t*)vwgt;
  }

  /* copy edge weights if the output vector is given the comparison of 0.5 is 
   * a ugly hack to see if we're using floats */
  if (r_adjwgt) {
    if (!adjwgt) {
      *r_adjwgt = malloc(sizeof(**r_adjwgt)*xadj[nvtxs]);
      for (j=0;j<xadj[nvtxs];++j) {
        (*r_adjwgt)[j] = 1;
      }
    } else if (sizeof(**r_adjwgt) != sizeof(*adjwgt) || \
        (idx_t)0.5 != (wgt_type)0.5) {
      *r_adjwgt = malloc(sizeof(**r_adjwgt)*xadj[nvtxs]);
      for (j=0;j<xadj[nvtxs];++j) {
        (*r_adjwgt)[j] = (idx_t)adjwgt[j];
      }
    } else {
      *r_adjwgt = (idx_t*)adjwgt;
    }
  }

  /* setup the where vector if need be */
  if (sizeof(**r_where) != sizeof(*where)) {
    *r_where = malloc(sizeof(**r_where)*nvtxs);
  } else {
    *r_where = (idx_t*)where;
  }
}


static void S_destroy_arrays(
    vtx_type const nvtxs,
    pid_type * const where,
    idx_t * m_xadj,
    idx_t * m_adjncy,
    idx_t * m_vwgt,
    idx_t * m_adjwgt,
    idx_t * m_where)
{
  vtx_type i;

  /* free and copy idx_t junk */
  if (sizeof(idx_t) != sizeof(vtx_type)) {
    dl_free(m_adjncy);
  }
  if (sizeof(idx_t) != sizeof(adj_type)) {
    dl_free(m_xadj);
  }
  if (sizeof(idx_t) != sizeof(wgt_type)) {
    dl_free(m_vwgt);
    if (m_adjwgt) {
      dl_free(m_adjwgt);
    }
  }
  if (sizeof(idx_t) != sizeof(pid_type)) {
    for (i=0;i<nvtxs;++i) {
      where[i] = (pid_type)m_where[i];
    }
    dl_free(m_where);
  }
}




/******************************************************************************
* PUBLIC PARALLEL FUNCTIONS ***************************************************
******************************************************************************/


wgt_type metis_initcut(
    ctrl_type * const ctrl,
    pid_type const nparts,
    real_type * tpwgts,
    size_t const ncuts,
    int const rb,
    vtx_type const nvtxs,
    adj_type * const xadj,
    vtx_type * const adjncy,
    wgt_type * const vwgt,
    wgt_type * const adjwgt,
    pid_type * const where)
{
  pid_type p;
  idx_t m_nvtxs, m_nparts, cut, m_ncon, status;
  idx_t options[METIS_NOPTIONS];
  real_t ubf;
  real_t * m_tpwgts;
  idx_t * m_xadj, * m_adjncy, * m_vwgt, * m_adjwgt, * m_where;

  tid_type const myid = dlthread_get_id(ctrl->comm);

  __METIS_SetDefaultOptions(options);

  m_ncon = 1;

  options[METIS_OPTION_NITER] = 10;
  options[METIS_OPTION_OBJTYPE] = METIS_OBJTYPE_CUT;
  options[METIS_OPTION_SEED] = ctrl->seed + myid;
  options[METIS_OPTION_NCUTS] = ncuts;
  options[METIS_OPTION_DBGLVL] = 0;
  options[METIS_OPTION_NO2HOP] = !ctrl->leafmatch;

  m_nparts = (idx_t)nparts;
  m_nvtxs = (idx_t)nvtxs;
  ubf = pow(ctrl->ubfactor,1.0/log(nparts));

  S_create_arrays(nvtxs,xadj,adjncy,vwgt,adjwgt,where,&m_xadj,&m_adjncy, \
      &m_vwgt,&m_adjwgt,&m_where);

  /* see if we need to re-allocate tpwgts to metis size */
  if (sizeof(real_type) != sizeof(real_t)) {
    m_tpwgts = malloc(sizeof(*m_tpwgts)*nparts);
    for (p=0;p<nparts;++p) {
      m_tpwgts[p] = tpwgts[p];
    }
  } else {
    m_tpwgts = (real_t*)tpwgts;
  }

  status = METIS_OK;
  if (rb || nparts == 2) {
    options[METIS_OPTION_RTYPE] = METIS_RTYPE_FM;
    status = __METIS_PartGraphRecursive(&m_nvtxs,&m_ncon,m_xadj, \
        m_adjncy,m_vwgt,NULL,m_adjwgt,&m_nparts,m_tpwgts, \
        &ubf,options,&cut,m_where);
  } else {
    status = __METIS_PartGraphKway(&m_nvtxs,&m_ncon,m_xadj, \
        m_adjncy,m_vwgt,NULL,m_adjwgt,&m_nparts,m_tpwgts, \
        &ubf,options,&cut,m_where);
  }

  /* discard allocated memory */
  if ((void*)m_tpwgts != (void*)tpwgts) {
    dl_free(m_tpwgts);
  }

  S_destroy_arrays(nvtxs,where,m_xadj,m_adjncy,m_vwgt,m_adjwgt,m_where);

  if (status != METIS_OK) {
    dl_error("Metis returned '%"PRIDX"' during initial partitioning\n",status);
  }

  return (wgt_type)cut;
}


wgt_type metis_initsep(
    ctrl_type * const ctrl,
    size_t const nseps,
    vtx_type const nvtxs,
    adj_type * const xadj,
    vtx_type * const adjncy,
    wgt_type * const vwgt,
    wgt_type * const adjwgt,
    pid_type * const where)
{
  idx_t sep, m_nvtxs;
  idx_t options[METIS_NOPTIONS];
  idx_t * m_xadj, * m_adjncy, * m_vwgt, * m_where;

  tid_type const myid = dlthread_get_id(ctrl->comm);

  __METIS_SetDefaultOptions(options);

  options[METIS_OPTION_NITER] = 10;
  options[METIS_OPTION_DBGLVL] = 0;
  options[METIS_OPTION_SEED] = ctrl->seed + myid;
  options[METIS_OPTION_NSEPS] = nseps;
  options[METIS_OPTION_NCUTS] = nseps;
  options[METIS_OPTION_UFACTOR] = 1000*(ctrl->ubfactor - 1.0);

  options[METIS_OPTION_OBJTYPE] = METIS_OBJTYPE_NODE;

  m_nvtxs = nvtxs;

  S_create_arrays(nvtxs,xadj,adjncy,vwgt,NULL,where,&m_xadj,&m_adjncy, \
      &m_vwgt,NULL,&m_where);

  __METIS_ComputeVertexSeparator(&m_nvtxs,m_xadj,m_adjncy, \
      m_vwgt,options,&sep,m_where);

  S_destroy_arrays(nvtxs,where,m_xadj,m_adjncy,m_vwgt,NULL,m_where);

  return (wgt_type)sep;
}


wgt_type metis_kway(
    ctrl_type * const ctrl,
    graph_type * const graph,
    pid_type * const * const where,
    int const rb)
{
  idx_t m_nparts, m_nvtxs, cut, m_ncon;
  idx_t options[METIS_NOPTIONS];
  real_t ubf;
  idx_t * m_xadj, * m_adjncy, * m_vwgt, * m_adjwgt, * m_where;

  tid_type const myid = dlthread_get_id(ctrl->comm);

  if (myid == 0) {
    dl_start_timer(&(ctrl->timers.metis));
  }

  __METIS_SetDefaultOptions(options);

  m_ncon = 1;

  options[METIS_OPTION_NITER] = ctrl->nrefpass;
  options[METIS_OPTION_OBJTYPE] = METIS_OBJTYPE_CUT;
  options[METIS_OPTION_SEED] = ctrl->seed + myid;
  options[METIS_OPTION_NCUTS] = ctrl->ncuts;
  options[METIS_OPTION_NO2HOP] = !ctrl->leafmatch;
  options[METIS_OPTION_DBGLVL] = 0;
  m_nparts = ctrl->nparts;
  ubf = ctrl->ubfactor;

  S_create_arrays(graph->mynvtxs[0],graph->xadj[0],graph->adjncy[0], \
      graph->vwgt[0],graph->adjwgt[0],where[0],&m_xadj,&m_adjncy, \
      &m_vwgt,&m_adjwgt,&m_where);

  m_nvtxs = graph->mynvtxs[0];

  if (rb) {
    options[METIS_OPTION_RTYPE] = METIS_RTYPE_FM;
    __METIS_PartGraphRecursive(&m_nvtxs,&m_ncon,m_xadj,m_adjncy,m_vwgt,NULL, \
        m_adjwgt,&m_nparts,NULL,&ubf,options,&cut,m_where);
  } else {
    __METIS_PartGraphKway(&m_nvtxs,&m_ncon,m_xadj,m_adjncy,m_vwgt,NULL, \
        m_adjwgt,&m_nparts,NULL,&ubf,options,&cut,m_where);
  }

  S_destroy_arrays(graph->mynvtxs[0],where[0],m_xadj,m_adjncy,m_vwgt, \
      m_adjwgt,m_where);

  if (myid == 0) {
    dl_stop_timer(&(ctrl->timers.metis));
  }

  graph->mincut = cut;

  return cut;
}


wgt_type metis_esep(
    ctrl_type * const ctrl,
    graph_type * const graph,
    pid_type * const * const where)
{
  vtx_type i;
  pid_type me;
  idx_t curobj, m_nvtxs;
  idx_t options[METIS_NOPTIONS];
  idx_t ncon = 1, nparts = 2;
  real_t ubf = 1.0;
  idx_t * m_xadj, * m_adjncy, * m_vwgt, * m_adjwgt, * m_where;

  tid_type const myid = dlthread_get_id(ctrl->comm);

  if (myid == 0) {
    dl_stop_timer(&(ctrl->timers.metis));
  }

  __METIS_SetDefaultOptions(options);

  options[METIS_OPTION_NITER] = 10;
  if (ctrl->verbosity == MTMETIS_VERBOSITY_MAXIMUM) {
    options[METIS_OPTION_DBGLVL] = 15;
  } else {
    options[METIS_OPTION_DBGLVL] = 0;
  }
  options[METIS_OPTION_NSEPS] = 1;
  options[METIS_OPTION_NCUTS] = 1;
  options[METIS_OPTION_NITER] = ctrl->nrefpass;
  options[METIS_OPTION_UFACTOR] = 1000*(ctrl->ubfactor - 1.0);
  options[METIS_OPTION_OBJTYPE] = METIS_OBJTYPE_CUT;

  ubf = ctrl->ubfactor;

  options[METIS_OPTION_SEED] = ctrl->seed;

  graph->pwgts = wgt_init_alloc(0,2);
  graph->where = r_pid_alloc(1);
  graph->where[0] = pid_alloc(graph->mynvtxs[0]);

  S_create_arrays(graph->mynvtxs[0],graph->xadj[0],graph->adjncy[0], \
      graph->vwgt[0],graph->adjwgt[0],where[0],&m_xadj,&m_adjncy, \
      &m_vwgt,&m_adjwgt,&m_where);

  m_nvtxs = (idx_t)graph->mynvtxs[0];

  __METIS_PartGraphRecursive(&m_nvtxs,&ncon, \
      m_xadj,m_adjncy,m_vwgt,NULL,m_adjwgt,&nparts,NULL, \
      &ubf,options,&curobj,m_where);

  S_destroy_arrays(graph->mynvtxs[0],where[0],m_xadj,m_adjncy,m_vwgt, \
      m_adjwgt,m_where);

  for (i=0;i<graph->mynvtxs[0];++i) {
    me = graph->where[0][i];
    graph->pwgts[me] += graph->vwgt[0][i];
  }

  if (myid == 0) {
    dl_stop_timer(&(ctrl->timers.metis));
  }

  return (wgt_type)curobj;
}


wgt_type metis_vsep(
    ctrl_type * const ctrl,
    graph_type * const graph,
    pid_type * const * const where)
{
  vtx_type i;
  pid_type me;
  idx_t curobj, m_nvtxs;
  idx_t options[METIS_NOPTIONS];
  idx_t * m_xadj, * m_adjncy, * m_vwgt, * m_where;

  tid_type const myid = dlthread_get_id(ctrl->comm);

  if (myid == 0) {
    dl_start_timer(&(ctrl->timers.metis));
  }

  __METIS_SetDefaultOptions(options);

  options[METIS_OPTION_NITER] = 10;
  if (ctrl->verbosity == MTMETIS_VERBOSITY_MAXIMUM) {
    options[METIS_OPTION_DBGLVL] = 15;
  } else {
    options[METIS_OPTION_DBGLVL] = 0;
  }
  options[METIS_OPTION_NSEPS] = 1;
  options[METIS_OPTION_NCUTS] = 1;
  options[METIS_OPTION_NITER] = ctrl->nrefpass;
  options[METIS_OPTION_UFACTOR] = 1000*(ctrl->ubfactor - 1.0);
  options[METIS_OPTION_OBJTYPE] = METIS_OBJTYPE_NODE;

  options[METIS_OPTION_SEED] = ctrl->seed;

  graph->pwgts = wgt_init_alloc(0,3);
  graph->where = r_pid_alloc(1);
  graph->where[0] = pid_alloc(graph->mynvtxs[0]);

  m_nvtxs = graph->mynvtxs[0];

  S_create_arrays(graph->mynvtxs[0],graph->xadj[0],graph->adjncy[0], \
      graph->vwgt[0],NULL,where[0],&m_xadj,&m_adjncy, \
      &m_vwgt,NULL,&m_where);

  __METIS_ComputeVertexSeparator(&m_nvtxs,m_xadj,m_adjncy, \
      m_vwgt,options,&curobj,m_where);

  S_destroy_arrays(graph->mynvtxs[0],where[0],m_xadj,m_adjncy,m_vwgt, \
      NULL,m_where);

  for (i=0;i<graph->mynvtxs[0];++i) {
    me = graph->where[0][i];
    graph->pwgts[me] += graph->vwgt[0][i];
  }

  if (myid == 0) {
    dl_stop_timer(&(ctrl->timers.metis));
  }

  return (wgt_type)curobj;
}


void metis_nd(
    ctrl_type * const ctrl,
    graph_type * const graph,
    pid_type * const * const perm)
{
  idx_t m_nvtxs;
  idx_t options[METIS_NOPTIONS];
  idx_t * m_xadj, * m_adjncy, * m_vwgt, * m_perm, * m_fperm;

  tid_type const myid = dlthread_get_id(ctrl->comm);

  DL_ASSERT_EQUALS(graph->dist.nthreads,1,"%"PF_TID_T);

  /* make sure nvtxs fits in pid_type */
  if (((size_t)graph->nvtxs) != (size_t)((pid_type)graph->nvtxs)) {
    dl_error("Graph is too large for current pid_type size");
  }

  m_fperm = malloc(sizeof(*m_fperm)*graph->mynvtxs[0]);

  if (myid == 0) {
    dl_start_timer(&(ctrl->timers.metis));
  }

  dlthread_pool_init(omp_get_num_threads());

  __METIS_SetDefaultOptions(options);

  options[METIS_OPTION_NITER] = ctrl->nrefpass;
  options[METIS_OPTION_DBGLVL] = 0;
  options[METIS_OPTION_SEED] = ctrl->seed + myid;
  options[METIS_OPTION_NSEPS] = ctrl->ncuts;
  options[METIS_OPTION_UFACTOR] = 1000*(ctrl->ubfactor - 1.0);

  S_create_arrays(graph->mynvtxs[0],graph->xadj[0],graph->adjncy[0], \
      graph->vwgt[0],NULL,perm[0],&m_xadj,&m_adjncy, \
      &m_vwgt,NULL,&m_perm);

  m_nvtxs = (idx_t)graph->mynvtxs[0];
  __METIS_NodeND(&m_nvtxs,m_xadj,m_adjncy,m_vwgt,options,m_fperm,m_perm);

  S_destroy_arrays(graph->mynvtxs[0],perm[0],m_xadj,m_adjncy,m_vwgt, \
      NULL,m_perm);
  
  dlthread_pool_finalize();

  if (myid == 0) {
    dl_stop_timer(&(ctrl->timers.metis));
  }

  dl_free(m_fperm);
}





#endif






