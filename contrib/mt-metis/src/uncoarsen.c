/**
 * @file uncoarsen.c
 * @brief Uncoarsening functions
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright 2013-2015, Regents of the University of Minnesota
 * @version 1
 * @date 2012-05-20
 */




#ifndef MTMETIS_UNCOARSEN_C
#define MTMETIS_UNCOARSEN_C




#include "uncoarsen.h"
#include "project.h"
#include "refine.h"




/******************************************************************************
* PUBLIC PARALLEL FUNCTIONS ***************************************************
******************************************************************************/


void par_uncoarsen_graph(
    ctrl_type * const ctrl,
    graph_type * const graph)
{
  tid_type const myid = dlthread_get_id(ctrl->comm);

  if (myid == 0) {
    dl_start_timer(&ctrl->timers.uncoarsening);
  }

  par_project_graph(ctrl,graph);

  par_refine_graph(ctrl,graph);

  switch (ctrl->ptype) {
    case MTMETIS_PTYPE_VSEP:
      par_vprintf(ctrl->verbosity,MTMETIS_VERBOSITY_HIGH,"Final partition " \
          "on graph %zu: %"PF_WGT_T" separator and %5.4lf balance\n", \
          graph->level,graph->minsep, \
          graph_imbalance(graph,ctrl->nparts,ctrl->pijbm));
      break;
    case MTMETIS_PTYPE_ESEP:
    case MTMETIS_PTYPE_RB:
    case MTMETIS_PTYPE_KWAY:
      par_vprintf(ctrl->verbosity,MTMETIS_VERBOSITY_HIGH,"Final partition " \
          "on graph %zu: %"PF_WGT_T" cut and %5.4lf balance\n",graph->level, \
          graph->mincut,graph_imbalance(graph,ctrl->nparts,ctrl->pijbm));
      break;
  }

  if (myid == 0) {
    dl_stop_timer(&ctrl->timers.uncoarsening);
  }
}




#endif
