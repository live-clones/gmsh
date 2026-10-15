/**
 * @file ctrl.c
 * @brief Functions for allocating, freeing, and manipulating control
 * structures.
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright 2014, Regents of the University of Minnesota
 * @version 1
 * @date 2014-09-17
 */




#ifndef MTMETIS_CTRL_C
#define MTMETIS_CTRL_C




#include <omp.h>
#include "ctrl.h"




/******************************************************************************
* CONSTANTS *******************************************************************
******************************************************************************/


static size_t const DEFAULT_NCUTS = 1; 
static size_t const DEFAULT_NRUNS = 1; 
static size_t const DEFAULT_NREFPASS = 8;
static real_type const DEFAULT_UBFACTOR = 1.03;
static size_t const DEFAULT_NINITSOLUTIONS = 8;
static vtx_type const DEFAULT_VSEP_HILLSIZE = 300;
static vtx_type const DEFAULT_ESEP_HILLSIZE = 100;
static vtx_type const DEFAULT_KWAY_HILLSIZE = 16;
static int const DEFAULT_HS_SCANTYPE = MTMETIS_HS_SCAN_SQRT;
static int const DEFAULT_GLOBAL_RELABEL = 0;
static int const DEFAULT_RUNSTATS = 0;
static int const DEFAULT_TIMING = 0;
static int const DEFAULT_CTYPE = MTMETIS_CTYPE_SHEM;
static int const DEFAULT_CONTYPE = MTMETIS_CONTYPE_CLS;
static int const DEFAULT_RTYPE = MTMETIS_RTYPE_GREEDY;
static int const DEFAULT_PTYPE = MTMETIS_PTYPE_KWAY;
static int const DEFAULT_VERBOSITY = MTMETIS_VERBOSITY_NONE;
static int const DEFAULT_DISTRIBUTION = MTMETIS_DISTRIBUTION_BLOCKCYCLIC;
static int const DEFAULT_METIS_SERIAL = 0;
static int const DEFAULT_PARTFACTOR = 5;
static double const DEFAULT_STOP_RATIO = 0.85;
static int const DEFAULT_REMOVEISLANDS = 0;
static int const DEFAULT_LEAFMATCH = 1;
static int const DEFAULT_VWGTDEGREE = 0;
static int const DEFAULT_IGNORE = MTMETIS_IGNORE_NONE;


static char const * trans_table_part[] = {
  [MTMETIS_PTYPE_KWAY] = MTMETIS_STR_PTYPE_KWAY,
  [MTMETIS_PTYPE_ESEP] = MTMETIS_STR_PTYPE_ESEP,
  [MTMETIS_PTYPE_RB] = MTMETIS_STR_PTYPE_RB,
  [MTMETIS_PTYPE_VSEP] = MTMETIS_STR_PTYPE_VSEP,
  [MTMETIS_PTYPE_ND] = MTMETIS_STR_PTYPE_ND
};


static char const * trans_table_coarsen[] = {
  [MTMETIS_CTYPE_RM] = MTMETIS_STR_CTYPE_RM,
  [MTMETIS_CTYPE_SHEM] = MTMETIS_STR_CTYPE_SHEM,
  [MTMETIS_CTYPE_FC] = MTMETIS_STR_CTYPE_FC
};


static char const * trans_table_contype[] = {
  [MTMETIS_CONTYPE_CLS] = MTMETIS_STR_CONTYPE_CLS,
  [MTMETIS_CONTYPE_DENSE] = MTMETIS_STR_CONTYPE_DENSE,
  [MTMETIS_CONTYPE_SORT] = MTMETIS_STR_CONTYPE_SORT
};


static char const * trans_table_refine[] = {
  [MTMETIS_RTYPE_GREEDY] = MTMETIS_STR_RTYPE_GREEDY,
  [MTMETIS_RTYPE_FM] = MTMETIS_STR_RTYPE_FM,
  [MTMETIS_RTYPE_SFM] = MTMETIS_STR_RTYPE_SFM,
  [MTMETIS_RTYPE_SFG] = MTMETIS_STR_RTYPE_SFG,
  [MTMETIS_RTYPE_HS] = MTMETIS_STR_RTYPE_HS
};


static char const * trans_table_verbosity[] = {
  [MTMETIS_VERBOSITY_NONE] = MTMETIS_STR_VERBOSITY_NONE,
  [MTMETIS_VERBOSITY_LOW] = MTMETIS_STR_VERBOSITY_LOW,
  [MTMETIS_VERBOSITY_MEDIUM] = MTMETIS_STR_VERBOSITY_MEDIUM,
  [MTMETIS_VERBOSITY_HIGH] = MTMETIS_STR_VERBOSITY_HIGH,
  [MTMETIS_VERBOSITY_MAXIMUM] = MTMETIS_STR_VERBOSITY_MAXIMUM,
};


static char const * trans_table_dtype[] = {
  [MTMETIS_DISTRIBUTION_BLOCK] = MTMETIS_STR_DISTRIBUTION_BLOCK,
  [MTMETIS_DISTRIBUTION_CYCLIC] = MTMETIS_STR_DISTRIBUTION_CYCLIC,
  [MTMETIS_DISTRIBUTION_BLOCKCYCLIC] = MTMETIS_STR_DISTRIBUTION_BLOCKCYCLIC,
};




/******************************************************************************
* PRIVATE FUNCTIONS ***********************************************************
******************************************************************************/


/* implicitly pass in size of array */
#define FIND_STRING(table,str) \
  S_find_string(table,sizeof(table)/sizeof(char*),str)


static inline int S_find_string(
    char const * const table[], 
    int const ntable,
    char const * const str)
{
  int i;

  if (str == NULL) {
    return -1;
  }
  for (i=0;i<ntable;++i) {
    if (strcmp(table[i],str) == 0) {
      break;
    }
  }
  if (i == ntable) {
    return -1;
  } else {
    return i;
  }
}


static void S_init_timers(
    ctrl_type * const ctrl)
{
  dl_init_timer(&(ctrl->timers.total)); 
  dl_init_timer(&(ctrl->timers.io)); 
  dl_init_timer(&(ctrl->timers.ordering)); 
  dl_init_timer(&(ctrl->timers.preprocess)); 
  dl_init_timer(&(ctrl->timers.postprocess)); 
  dl_init_timer(&(ctrl->timers.metis)); 
  dl_init_timer(&(ctrl->timers.partitioning)); 
  dl_init_timer(&(ctrl->timers.coarsening)); 
  dl_init_timer(&(ctrl->timers.matching)); 
  dl_init_timer(&(ctrl->timers.contraction)); 
  dl_init_timer(&(ctrl->timers.initpart)); 
  dl_init_timer(&(ctrl->timers.uncoarsening)); 
  dl_init_timer(&(ctrl->timers.projection)); 
  dl_init_timer(&(ctrl->timers.refinement)); 
  dl_init_timer(&(ctrl->timers.recursion));
}


/******************************************************************************
* PUBLIC FUNCTIONS SERIAL *****************************************************
******************************************************************************/


ctrl_type * ctrl_create(void)
{
  ctrl_type * ctrl;

  /* allocate my memory */
  ctrl = (ctrl_type*)calloc(1,sizeof(ctrl_type));

  ctrl->nthreads = omp_get_max_threads();
  ctrl->seed = (unsigned int)time(NULL);
  ctrl->ncuts = DEFAULT_NCUTS;
  ctrl->nruns = DEFAULT_NRUNS;
  ctrl->nrefpass = DEFAULT_NREFPASS;
  ctrl->hillsize = DEFAULT_KWAY_HILLSIZE;
  ctrl->global_relabel = DEFAULT_GLOBAL_RELABEL;
  ctrl->ubfactor = DEFAULT_UBFACTOR;
  ctrl->ninitsolutions = DEFAULT_NINITSOLUTIONS;
  ctrl->ctype = DEFAULT_CTYPE;
  ctrl->rtype = DEFAULT_RTYPE;
  ctrl->hs_stype = DEFAULT_HS_SCANTYPE;
  ctrl->ptype = DEFAULT_PTYPE;
  ctrl->verbosity = DEFAULT_VERBOSITY;
  ctrl->dist = DEFAULT_DISTRIBUTION;
  ctrl->runstats = DEFAULT_RUNSTATS;
  ctrl->time = DEFAULT_TIMING;
  ctrl->metis_serial = DEFAULT_METIS_SERIAL;
  ctrl->partfactor = DEFAULT_PARTFACTOR;
  ctrl->stopratio = DEFAULT_STOP_RATIO;
  ctrl->removeislands = DEFAULT_REMOVEISLANDS;
  ctrl->leafmatch = DEFAULT_LEAFMATCH;
  ctrl->vwgtdegree = DEFAULT_VWGTDEGREE;
  ctrl->contype = DEFAULT_CONTYPE;
  ctrl->ignore = DEFAULT_IGNORE;

  return ctrl;
}


void ctrl_setup(
    ctrl_type * const ctrl,
    real_type * const tpwgts,
    vtx_type const nvtxs)
{
  vtx_type i;
  pid_type nparts;

  tid_type const nthreads = ctrl->nthreads;

  if (ctrl->ptype == MTMETIS_PTYPE_VSEP || ctrl->ptype == MTMETIS_PTYPE_ND) {
    ctrl->nparts = 3;
  } else if (ctrl->ptype == MTMETIS_PTYPE_ESEP) {
    ctrl->nparts = 2;
  }

  nparts = ctrl->nparts;

  DL_ASSERT(nparts > 0,"Setting up ctrl with 0 parts");

  /* initialize tpwgts */
  if (tpwgts == NULL) {
    ctrl->tpwgts = real_alloc(nparts);
    if (ctrl->ptype == MTMETIS_PTYPE_VSEP || ctrl->ptype == MTMETIS_PTYPE_ND) {
      for (i=0;i<2;++i) {
        ctrl->tpwgts[i] = 0.5;
      }
      ctrl->tpwgts[2] = 1.0; /* this is screwy -- but neccessary */
    } else {
      for (i=0;i<nparts;++i) {
        ctrl->tpwgts[i] = 1.0 / nparts;
      }
    }
  } else {
    ctrl->tpwgts = tpwgts;
  }

  /* set various run parameters that depend on the graph */
  switch (ctrl->ptype) {
    case MTMETIS_PTYPE_ESEP:
    case MTMETIS_PTYPE_RB:
      ctrl->coarsen_to = 200;
      break;
    case MTMETIS_PTYPE_KWAY:
      ctrl->coarsen_to = dl_max(nvtxs/(20*pid_uplog2(nparts)),30*nparts);
      break;
    case MTMETIS_PTYPE_ND:
    case MTMETIS_PTYPE_VSEP:
      ctrl->coarsen_to = 1500*nthreads;
      break;
    default:
      dl_error("Unknown partition type '%d'\n",ctrl->ptype);
  }
}


int ctrl_parse(
    double const * const options,
    ctrl_type ** const r_ctrl)
{
  int rv;
  pid_type nparts;
  ctrl_type * ctrl = NULL;

  rv = MTMETIS_SUCCESS;

  ctrl = ctrl_create();

  /* decide how many threads to use */
  if (options[MTMETIS_OPTION_NTHREADS] != MTMETIS_VAL_OFF) {
    if (options[MTMETIS_OPTION_NTHREADS] < 1) {
      eprintf("Invalid number of threads: %"PF_TID_T"\n", \
          (tid_type)options[MTMETIS_OPTION_NTHREADS]);
      rv = MTMETIS_ERROR_INVALIDINPUT;
      goto CLEANUP;
    }
    ctrl->nthreads = (tid_type)options[MTMETIS_OPTION_NTHREADS];
  }

  if (options[MTMETIS_OPTION_PTYPE] != MTMETIS_VAL_OFF) {
    ctrl->ptype = (int)options[MTMETIS_OPTION_PTYPE];
    /* custom defaults */
    switch (ctrl->ptype) {
      case MTMETIS_PTYPE_VSEP:
      case MTMETIS_PTYPE_ND:
        if (ctrl->nthreads > 1) {
          ctrl->rtype = MTMETIS_RTYPE_SFG;
        } else {
          ctrl->rtype = MTMETIS_RTYPE_FM;
        }
        ctrl->nparts = 3;
        break;
      case MTMETIS_PTYPE_ESEP:
        ctrl->nparts = 2;
        break;
      case MTMETIS_PTYPE_RB:
        if (ctrl->nthreads > 1) {
          ctrl->rtype = MTMETIS_RTYPE_GREEDY;
        } else {
          ctrl->rtype = MTMETIS_RTYPE_FM;
        }
        break;
      case MTMETIS_PTYPE_KWAY:
        ctrl->rtype = MTMETIS_RTYPE_GREEDY;
        ctrl->nparts = 3;
        break;
    }
  }

  if (ctrl->ptype == MTMETIS_PTYPE_RB || \
      ctrl->ptype == MTMETIS_PTYPE_KWAY) {
    /* check the number of partitions */
    if (options[MTMETIS_OPTION_NPARTS] == MTMETIS_VAL_OFF) {
      eprintf("The number of partitions must be specified.\n");
      rv = MTMETIS_ERROR_INVALIDINPUT;
      goto CLEANUP;
    } else if (options[MTMETIS_OPTION_NPARTS] < 1) {
      eprintf("The number of partitions must be at least 1.\n");
      rv = MTMETIS_ERROR_INVALIDINPUT;
      goto CLEANUP;
    } 
    nparts = (pid_type)options[MTMETIS_OPTION_NPARTS];

    ctrl->nparts = nparts;
  }

  switch (ctrl->ptype) {
    case MTMETIS_PTYPE_VSEP:
    case MTMETIS_PTYPE_ND:
      ctrl->hillsize = DEFAULT_VSEP_HILLSIZE;
      break;
    case MTMETIS_PTYPE_ESEP:
    case MTMETIS_PTYPE_RB:
      ctrl->hillsize = DEFAULT_ESEP_HILLSIZE;
      break;
  }

  if (options[MTMETIS_OPTION_SEED] != MTMETIS_VAL_OFF) {
    ctrl->seed = (unsigned int)options[MTMETIS_OPTION_SEED];
  }

  if (options[MTMETIS_OPTION_NCUTS] != MTMETIS_VAL_OFF) {
    ctrl->ncuts = (size_t)options[MTMETIS_OPTION_NCUTS];
  }

  if (options[MTMETIS_OPTION_NRUNS] != MTMETIS_VAL_OFF) {
    ctrl->nruns = (size_t)options[MTMETIS_OPTION_NRUNS];
  }

  if (options[MTMETIS_OPTION_NITER] != MTMETIS_VAL_OFF) {
    ctrl->nrefpass = (size_t)options[MTMETIS_OPTION_NITER];
  }

  if (options[MTMETIS_OPTION_UBFACTOR] != MTMETIS_VAL_OFF) {
    ctrl->ubfactor = (real_type)options[MTMETIS_OPTION_UBFACTOR];
  } else {
    if (ctrl->ptype == MTMETIS_PTYPE_ND) {
      ctrl->ubfactor = 1.20;
    }
  }

  if (options[MTMETIS_OPTION_NINITSOLUTIONS] != MTMETIS_VAL_OFF) {
    ctrl->ninitsolutions = (size_t)options[MTMETIS_OPTION_NINITSOLUTIONS];
  }

  if (options[MTMETIS_OPTION_CTYPE] != MTMETIS_VAL_OFF) {
    ctrl->ctype = (int)options[MTMETIS_OPTION_CTYPE];
  }

  if (options[MTMETIS_OPTION_CONTYPE] != MTMETIS_VAL_OFF) {
    ctrl->contype = (int)options[MTMETIS_OPTION_CONTYPE];
  }

  if (options[MTMETIS_OPTION_LEAFMATCH] != MTMETIS_VAL_OFF) {
    ctrl->leafmatch = (int)options[MTMETIS_OPTION_LEAFMATCH];
  }

  if (options[MTMETIS_OPTION_RTYPE] != MTMETIS_VAL_OFF) {
    ctrl->rtype = (int)options[MTMETIS_OPTION_RTYPE];
  }

  if (options[MTMETIS_OPTION_HS_SCANTYPE] != MTMETIS_VAL_OFF) {
    ctrl->hs_stype = (int)options[MTMETIS_OPTION_HS_SCANTYPE];
  }

  if (options[MTMETIS_OPTION_HILLSIZE] != MTMETIS_VAL_OFF) {
    ctrl->hillsize = (int)options[MTMETIS_OPTION_HILLSIZE];
  }

  if (options[MTMETIS_OPTION_VERBOSITY] != MTMETIS_VAL_OFF) {
    ctrl->verbosity = (int)options[MTMETIS_OPTION_VERBOSITY];
  }

  if (options[MTMETIS_OPTION_DISTRIBUTION] != MTMETIS_VAL_OFF) {
    ctrl->dist = (int)options[MTMETIS_OPTION_DISTRIBUTION];
  }

  if (options[MTMETIS_OPTION_RUNSTATS] != MTMETIS_VAL_OFF) {
    if (ctrl->ptype != MTMETIS_PTYPE_ND) {
      ctrl->runstats = 1;
      ctrl->runs = wgt_alloc(ctrl->nruns);
    }
  }

  if (options[MTMETIS_OPTION_METIS] != MTMETIS_VAL_OFF) {
    ctrl->metis_serial = 1;
  }

  if (options[MTMETIS_OPTION_TIME] != MTMETIS_VAL_OFF) {
    ctrl->time = 1;
    S_init_timers(ctrl);
  }

  if (options[MTMETIS_OPTION_REMOVEISLANDS] != MTMETIS_VAL_OFF) {
    ctrl->removeislands = (int)options[MTMETIS_OPTION_REMOVEISLANDS];
  }

  if (options[MTMETIS_OPTION_VWGTDEGREE] != MTMETIS_VAL_OFF) {
    ctrl->vwgtdegree = 1;
  }

  if (options[MTMETIS_OPTION_IGNORE] != MTMETIS_VAL_OFF) {
    ctrl->ignore = (int)options[MTMETIS_OPTION_IGNORE];
  }

  *r_ctrl = ctrl;
  ctrl = NULL;

  CLEANUP:

  if (ctrl) {
    ctrl_free(ctrl);
  }

  return rv;
}


void ctrl_free(
    ctrl_type * ctrl)
{
  if (ctrl->tpwgts) {
    dl_free(ctrl->tpwgts);
  }
  if (ctrl->pijbm) {
    dl_free(ctrl->pijbm);
  }
  if (ctrl->runs) {
    dl_free(ctrl->runs);
  }
  dl_free(ctrl);
}


void ctrl_combine_timers(
    ctrl_type * const ctrl,
    ctrl_type const * const ctrl2)
{
  if (ctrl->ptype == MTMETIS_PTYPE_ND) {
    dl_combine_timer(&(ctrl->timers.partitioning), \
        &(ctrl2->timers.partitioning));
  }
  dl_combine_timer(&(ctrl->timers.metis),&(ctrl2->timers.metis));
  dl_combine_timer(&(ctrl->timers.preprocess),&(ctrl2->timers.preprocess));
  dl_combine_timer(&(ctrl->timers.postprocess),&(ctrl2->timers.postprocess));
  dl_combine_timer(&(ctrl->timers.coarsening),&(ctrl2->timers.coarsening));
  dl_combine_timer(&(ctrl->timers.matching),&(ctrl2->timers.matching));
  dl_combine_timer(&(ctrl->timers.contraction),&(ctrl2->timers.contraction));
  dl_combine_timer(&(ctrl->timers.initpart),&(ctrl2->timers.initpart));
  dl_combine_timer(&(ctrl->timers.uncoarsening),&(ctrl2->timers.uncoarsening));
  dl_combine_timer(&(ctrl->timers.projection),&(ctrl2->timers.projection));
  dl_combine_timer(&(ctrl->timers.refinement),&(ctrl2->timers.refinement));
  dl_combine_timer(&(ctrl->timers.recursion),&(ctrl2->timers.recursion));
}


void ser_ctrl_split(
    ctrl_type const * const ctrl,
    vtx_type const * const hnvtxs,
    ctrl_type ** const hctrls)
{
  pid_type side;
  ctrl_type * nctrl;
  pid_type hnparts[2];

  hnparts[0] = ctrl->nparts/2;
  hnparts[1] = ctrl->nparts - hnparts[0];

  for (side=0;side<2;++side) {
    nctrl = hctrls[side] = malloc(sizeof(ctrl_type));
    memcpy(hctrls[side],ctrl,sizeof(ctrl_type));

    nctrl->nparts = hnparts[side];

    /* make sure we don't touch the ctrl's memory */
    nctrl->tpwgts = NULL;
    nctrl->pijbm = NULL;
    nctrl->runs = NULL;

    /* set defaults */
    nctrl->runstats = 0;
    nctrl->nthreads = 1;

    /* set nparts */
    nctrl->nparts = hnparts[side];

    S_init_timers(nctrl);

    ctrl_setup(nctrl,nctrl->tpwgts,hnvtxs[side]);
  }
}


ctrl_type * ser_ctrl_rb(
    ctrl_type * const ctrl,
    pid_type const * const offset)
{
  pid_type p, k;
  ctrl_type * rbctrl;

  DL_ASSERT_EQUALS(offset[0],0,"%"PF_PID_T);
  DL_ASSERT_EQUALS(offset[2],ctrl->nparts,"%"PF_PID_T);
  DL_ASSERT(offset[0] <= offset[1],"Bad offset #1");
  DL_ASSERT(offset[1] <= offset[2],"Bad offset #2");

  rbctrl = malloc(sizeof(ctrl_type));

  memcpy(rbctrl,ctrl,sizeof(ctrl_type));

  rbctrl->ptype = MTMETIS_PTYPE_ESEP;
  rbctrl->tpwgts = malloc(sizeof(real_type)*2);
  rbctrl->tpwgts[0] = rbctrl->tpwgts[1] = 0;
  for (p=0;p<2;++p) {
    for (k=offset[p];k<offset[p+1];++k) {
      rbctrl->tpwgts[p] += ctrl->tpwgts[k];
    }
  }
  rbctrl->nparts = 2;

  /* convert cuts to runs */
  rbctrl->nruns = ctrl->ncuts;
  rbctrl->runstats = 0;
  rbctrl->runs = NULL;
  rbctrl->pijbm = NULL;

  S_init_timers(rbctrl);

  return rbctrl;
}




/******************************************************************************
* PUBLIC PARALLEL FUNCTIONS ***************************************************
******************************************************************************/


void par_ctrl_free(
    ctrl_type * ctrl)
{
  tid_type const myid = dlthread_get_id(ctrl->comm);

  dlthread_barrier(ctrl->comm);

  if (myid == 0) {
    ctrl_free(ctrl);
  }
}


ctrl_type * par_ctrl_split(
    ctrl_type const * const ctrl,
    vtx_type const nvtxs,
    pid_type const nparts,
    dlthread_comm_t comm)
{
  ctrl_type * nctrl;

  tid_type const myid = dlthread_get_id(comm);

  DL_ASSERT(dlthread_get_nthreads(comm) <= dlthread_get_nthreads(ctrl->comm), \
      "More threads on split control that root (%zu vs %zu)\n", \
      dlthread_get_nthreads(comm),dlthread_get_nthreads(ctrl->comm));

  nctrl = dlthread_get_shmem(sizeof(ctrl_type),comm);

  if (myid == 0) {
    memcpy(nctrl,ctrl,sizeof(ctrl_type));

    /* make sure we don't touch the ctrl's memory */
    nctrl->tpwgts = NULL;
    nctrl->pijbm = NULL;
    nctrl->runs = NULL;

    /* set defaults */
    nctrl->runstats = 0;
    nctrl->nthreads = dlthread_get_nthreads(comm);

    /* set nparts */
    nctrl->nparts = nparts;

    S_init_timers(nctrl);

    ctrl_setup(nctrl,nctrl->tpwgts,nvtxs);
    nctrl->comm = comm;
  }
  dlthread_barrier(comm);

  return nctrl;
}


int par_ctrl_parse(
    double const * const options,
    ctrl_type ** const r_ctrl,
    dlthread_comm_t comm)
{
  ctrl_type * ctrl, ** ptr;

  tid_type const myid = dlthread_get_id(comm);

  ptr = dlthread_get_shmem(sizeof(ctrl_type*),comm);

  if (myid == 0) {
    if (ctrl_parse(options,&ctrl) == MTMETIS_SUCCESS) {
      ctrl->comm = comm;
      ptr[0] = ctrl;
    } else {
      ptr[0] = NULL;
    }
  }

  dlthread_barrier(comm);

  *r_ctrl = ptr[0];

  dlthread_free_shmem(ptr,comm);

  if (*r_ctrl == NULL) {
    return MTMETIS_ERROR_INVALIDINPUT;
  } else {
    return MTMETIS_SUCCESS;
  }
}


void par_ctrl_setup(
    ctrl_type * const ctrl,
    real_type * const tpwgts,
    vtx_type const nvtxs)
{
  dlthread_barrier(ctrl->comm);
  if (dlthread_get_id(ctrl->comm) == 0) {
    ctrl_setup(ctrl,tpwgts,nvtxs);
  }
  dlthread_barrier(ctrl->comm);
}


ctrl_type * par_ctrl_rb(
    ctrl_type * const ctrl,
    pid_type const * const offset)
{
  ctrl_type ** r_ctrl;

  tid_type const myid = dlthread_get_id(ctrl->comm);

  r_ctrl = dlthread_get_buffer(sizeof(ctrl_type*),ctrl->comm);

  if (myid == 0) {
    *r_ctrl = ser_ctrl_rb(ctrl,offset);
  }

  dlthread_barrier(ctrl->comm);

  return *r_ctrl;
}




/******************************************************************************
* TRANSLATION FUNCTIONS *******************************************************
******************************************************************************/


char const * trans_ptype_string(
    const mtmetis_ptype_t type)
{
  return trans_table_part[type];
}


char const * trans_ctype_string(
    const mtmetis_ctype_t type)
{
  return trans_table_coarsen[type];
}


char const * trans_contype_string(
    const mtmetis_contype_t type)
{
  return trans_table_contype[type];
}


char const * trans_rtype_string(
    const mtmetis_rtype_t type)
{
  return trans_table_refine[type];
}


char const * trans_verbosity_string(
    const mtmetis_verbosity_t type)
{
  return trans_table_verbosity[type];
}


char const * trans_dtype_string(
    mtmetis_dtype_t const type)
{
  return trans_table_dtype[type];
}


mtmetis_ptype_t trans_string_ptype(
    char const * const str)
{
  int i;
  
  i = FIND_STRING(trans_table_part,str);
  if (i < 0) {
    dl_error("Unknown Partition Type '%s'\n",str);
  } else {
    return (mtmetis_ptype_t)i;
  }
}


mtmetis_ctype_t trans_string_ctype(
    char const * const str)
{
  int i;

  i = FIND_STRING(trans_table_coarsen,str);
  if (i < 0) {
    dl_error("Unknown Coarsening Type '%s'\n",str);
  } else {
    return (mtmetis_ctype_t)i;
  }
}


mtmetis_contype_t trans_string_contype(
    char const * const str)
{
  int i;

  i = FIND_STRING(trans_table_contype,str);
  if (i < 0) {
    dl_error("Unknown Contraction Type '%s'\n",str);
  } else {
    return (mtmetis_contype_t)i;
  }
}


mtmetis_rtype_t trans_string_rtype(
    char const * const str)
{
  int i;
  
  i = FIND_STRING(trans_table_refine,str);
  if (i < 0) {
    dl_error("Unknown Refinement Type '%s'\n",str);
  } else {
    return (mtmetis_rtype_t)i;
  }
}


mtmetis_verbosity_t trans_string_verbosity(
    char const * const str)
{
  int i;
  
  i = FIND_STRING(trans_table_verbosity,str);
  if (i < 0) {
    dl_error("Unknown Verbosity Level '%s'\n",str);
  } else {
    return (mtmetis_verbosity_t)i;
  }
}


mtmetis_dtype_t trans_string_dtype(
    char const * const str)
{
  int i;
  
  i = FIND_STRING(trans_table_dtype,str);
  if (i < 0) {
    dl_error("Unknown distribution type '%s'\n",str);
  } else {
    return (mtmetis_dtype_t)i;
  }
}


#endif
