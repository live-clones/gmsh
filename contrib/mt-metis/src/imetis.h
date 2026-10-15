/**
 * @file imetis.h
 * @brief Metis wrappers. 
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright 2015, Regents of the University of Minnesota
 * @version 1
 * @date 2015-06-08
 */




#ifndef MTMETIS_IMETIS_H
#define MTMETIS_IMETIS_H



#include "ctrl.h"
#include "graph.h"




/******************************************************************************
* FUNCTION PROTOTYPES *********************************************************
******************************************************************************/


/**
 * @brief Generate an initial partitioning.
 *
 * @param ctrl The control structure with parameters.
 * @param nparts The number of parittions in the partitioning.
 * @param tpwgts The target partition weights.
 * @param ncuts The number of partitionings to make.
 * @param rb Use recursive bisection to generate k-way partitionings.
 * @param nvtxs The number of vertices in the graph.
 * @param xadj The adjacency list pointer.
 * @param adjncy The adjacency list.
 * @param vwgt The vertex weights.
 * @param adjwgt The adjacecny weights.
 * @param where The partition ids of each vertex (output).
 *
 * @return The weight of the separator.
 */
wgt_type metis_initcut(
    ctrl_type * const ctrl,
    pid_type const nparts,
    real_type * tpwgts,
    size_t const ncuts,
    int const rb,
    vtx_type nvtxs,
    adj_type * const xadj,
    vtx_type * const adjncy,
    wgt_type * const vwgt,
    wgt_type * const adjwgt,
    pid_type * const where);


/**
 * @brief Generate an initial vertex separator using metis.
 *
 * @param ctrl The control structure with parameters.
 * @param nseps The number of separators to generate.
 * @param nvtxs The number of vertices in the graph.
 * @param xadj The adjacency list pointer.
 * @param adjncy The adjacency list.
 * @param vwgt The vertex weights.
 * @param adjwgt The adjacecny weights.
 * @param where The partition ids of each vertex (output).
 *
 * @return The weight of the separator.
 */
wgt_type metis_initsep(
    ctrl_type * ctrl,
    size_t nseps,
    vtx_type nvtxs,
    adj_type * xadj,
    vtx_type * adjncy,
    wgt_type * vwgt,
    wgt_type * adjwgt,
    pid_type * where);


/**
 * @brief Serially generate a k-way partition using metis (direct k-way
 * parittioning).
 *
 * @param ctrl The control structure containing partitioning parameters.
 * @param graph The graph to partition.
 * @param where The partition id for each vertex (output).
 * @param rb Whether or not to use recursive bisection. 
 *
 * @return The weight of the edgecut. 
 */
wgt_type metis_kway(
    ctrl_type * ctrl,
    graph_type * graph,
    pid_type * const * where,
    int rb);


/**
 * @brief Serially generate a 2-way edge separator using metis.
 *
 * @param ctrl The control structure containing partitioning parameters.
 * @param graph The graph to partition.
 * @param where The partition id for each vertex (output).
 *
 * @return The weight of the edge separator.
 */
wgt_type metis_esep(
    ctrl_type * ctrl,
    graph_type * graph,
    pid_type * const * where);


/**
 * @brief Serially generate a 2-way vertex separator using metis.
 *
 * @param ctrl The control structure containing partitioning parameters.
 * @param graph The graph to partition.
 * @param where The partition id for each vertex (output).
 *
 * @return The weight of the vertex separator.
 */
wgt_type metis_vsep(
    ctrl_type * ctrl,
    graph_type * graph,
    pid_type * const * where);


/**
 * @brief Generate a nested dissection, spawning parallel tasks if called by
 * multiple threads.
 *
 * @param ctrl The control structure.
 * @param graph The graph structure.
 * @param perm The resulting permutation.
 */
void metis_nd(
    ctrl_type * ctrl,
    graph_type * graph,
    pid_type * const * perm);




#endif
