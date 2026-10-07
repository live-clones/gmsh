/**
 * @file ctrl.h
 * @brief Type and function prototypes for the ctrl structure.
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright 2014, Regents of the University of Minnesota
 * @version 1
 * @date 2014-09-17
 */




#ifndef MTMETIS_CTRL_H
#define MTMETIS_CTRL_H




#include "base.h"




/******************************************************************************
* TYPES ***********************************************************************
******************************************************************************/


typedef struct timers_type {
  dl_timer_t total;
  dl_timer_t io;
  dl_timer_t preprocess;
  dl_timer_t postprocess;
  dl_timer_t metis;
  dl_timer_t ordering;
  dl_timer_t partitioning;
  dl_timer_t coarsening;
  dl_timer_t matching;
  dl_timer_t contraction;
  dl_timer_t initpart;
  dl_timer_t uncoarsening;
  dl_timer_t projection;
  dl_timer_t refinement;
  dl_timer_t recursion;
} timers_type;


typedef struct ctrl_type {
  /* runtime parameters */
  unsigned int seed;
  tid_type nthreads;
  int verbosity;
  int time;
  int runstats;
  int dist;
  timers_type timers;
  wgt_type * runs;
  int vwgtdegree;
  int ignore;
  /* thread communication structures */
  dlthread_comm_t comm;
  /* partitioning parameters */
  int ptype;
  pid_type nparts;
  size_t nruns;
  size_t ncuts;
  real_type * tpwgts;
  real_type * pijbm;
  real_type ubfactor;
  int metis_serial;
  int removeislands;
  /* coarsening parameters */
  int ctype;
  int contype;
  int leafmatch;
  vtx_type coarsen_to;
  wgt_type maxvwgt;
  double stopratio;
  /* initial partitiong parameters */
  size_t ninitsolutions;
  /* refinement parameters */
  int rtype;
  size_t nrefpass;
  vtx_type hillsize;
  int hs_stype;
  int global_relabel;
  /* pre-partitioning parameters */
  size_t partfactor;
} ctrl_type;




/******************************************************************************
* SERIAL FUNCTION PROTOTYPES **************************************************
******************************************************************************/


#define ctrl_create MTMETIS_ctrl_create
/**
 * @brief Allocate and initialize a control structure.
 *
 * @return The new control structure.
 */
ctrl_type * ctrl_create(void);


#define ctrl_setup MTMETIS_ctrl_setup
/**
 * @brief Setup a control structure to partition a graph with a specified
 * number of vertices. The structure should already be configured with nthreads
 * and nparts.
 *
 * @param ctrl  The control structure to configure.
 * @param tpwgts The target partition weights for this control (can be NULL).
 * @param nvtxs The number of vertices in the graph to partition.
 */
void ctrl_setup(
    ctrl_type * ctrl,
    real_type * tpwgts,
    vtx_type nvtxs);


#define ctrl_parse MTMETIS_ctrl_parse
/**
 * @brief Create a control structure using the specified set of options.
 *
 * @param options The options specifying how to setup the ctrl.
 * @param ctrl A reference to the control structure to allocate and configure.
 *
 * @return MTMETIS_SUCCESS if the options array is valid.
 */
int ctrl_parse(
    double const * options,
    ctrl_type ** ctrl);


#define ctrl_free MTMETIS_ctrl_free
/**
 * @brief Free a control structure and its associated memory.
 *
 * @param ctrl The control structure to free.
 */
void ctrl_free(
    ctrl_type * ctrl);


#define ctrl_combine_timers MTMETIS_ctrl_combine_timers
/**
 * @brief Combine the times of the two timers into the first.
 *
 * @param ctrl The timer to recieve the combined times.
 * @param ctrl2 The timer to combine times with.
 */
void ctrl_combine_timers(
    ctrl_type * ctrl,
    ctrl_type const * ctrl2);


#define ser_ctrl_split MTMETIS_ser_ctrl_split
/**
 * @brief Split the control structure serially for recursive bisection or
 * nested dissection.
 *
 * @param ctrl The base control to split.
 * @param hnvtxs The number of vertices in each graph.
 * @param hctrl The two resulting ctrls (output).
 */
void ser_ctrl_split(
    ctrl_type const * ctrl,
    vtx_type const * hnvtxs,
    ctrl_type ** hctrls);


#define ser_ctrl_rb MTMETIS_ser_ctrl_rb
/**
 * @brief Create a new control for creating an edge separator. 
 *
 * @param ctrl The control to parse options from.
 * @param offset The prefixsum of the number of partitions per half (lengh 3).
 * This is an exclusive prefixsum so offset[0] = 0, and 
 * offset[2] = ctrl->nparts.
 *
 * @return The new control.
 */
ctrl_type * ser_ctrl_rb(
    ctrl_type * ctrl,
    pid_type const * offset);




/******************************************************************************
* PARALLEL FUNCTION PROTOTYPES ************************************************
******************************************************************************/


#define par_ctrl_split MTMETIS_par_ctrl_split
/**
 * @brief Duplicate a control structure.
 *
 * @param ctrl The control structure to split.
 * @param nvtxs The new number of starting vertices.
 * @param nparts The new number of partitions.
 * @param comm The new thread communicator.
 *
 * @return The duplicated contrl structure. 
 */
ctrl_type * par_ctrl_split(
    ctrl_type const * ctrl,
    vtx_type nvtxs,
    pid_type nparts,
    dlthread_comm_t comm);


#define par_ctrl_free MTMETIS_par_ctrl_free
/**
 * @brief Free a control structure and its associated memory.
 *
 * @param ctrl The control structure to free.
 */
void par_ctrl_free(
    ctrl_type * ctrl);


#define par_ctrl_parse MTMETIS_par_ctrl_parse
/**
 * @brief Parse a control structure options in parallel.
 *
 * @param options The options to parse.
 * @param r_ctrl A reference to the ctrl pointer.
 * @param comm The thread communicator for the current thread group.
 *
 * @return MTMETIS_SUCCESS if the options are valid.
 */
int par_ctrl_parse(
    double const * options,
    ctrl_type ** r_ctrl,
    dlthread_comm_t comm);


#define par_ctrl_setup MTMETIS_par_ctrl_setup
/**
 * @brief Setup a control structure in parallel.
 *
 * @param ctrl The control structure.
 * @param tpwgts The target partition weights for this control (can be NULL).
 * @param nvtxs The number of vertices in the graph.
 */
void par_ctrl_setup(
    ctrl_type * ctrl,
    real_type * tpwgts,
    vtx_type nvtxs);


#define par_ctrl_rb MTMETIS_par_ctrl_rb
/**
 * @brief Create a new control for creating an edge separator. 
 *
 * @param ctrl The control to parse options from.
 * @param offset The prefixsum of the number of partitions per half (lengh 3).
 * This is an exclusive prefixsum so offset[0] = 0, and 
 * offset[2] = ctrl->nparts.
 *
 * @return The new control.
 */
ctrl_type * par_ctrl_rb(
    ctrl_type * ctrl,
    pid_type const * offset);



/******************************************************************************
* TRANSLATION PROTOTYPES ******************************************************
******************************************************************************/


char const * trans_ptype_string(
    mtmetis_ptype_t type);


char const * trans_ctype_string(
    mtmetis_ctype_t type);


char const * trans_contype_string(
    mtmetis_contype_t type);


char const * trans_rtype_string(
    mtmetis_rtype_t type);


char const * trans_verbosity_string(
    mtmetis_verbosity_t type);


char const * trans_dtype_string(
    mtmetis_dtype_t type);


mtmetis_ptype_t trans_string_ptype(
    char const * str);


mtmetis_ctype_t trans_string_ctype(
    char const * str);


mtmetis_contype_t trans_string_contype(
    char const * str);


mtmetis_rtype_t trans_string_rtype(
    char const * str);


mtmetis_verbosity_t trans_string_verbosity(
    char const * str);


mtmetis_dtype_t trans_string_dtype(
    char const * str);




#endif
