/**
 * @file aggregate.h
 * @brief Functions for coarsening
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright 2012-2015, Regents of the University of Minnesota
 * @version 1
 * @date 2015-06-17
 */




#ifndef MTMETIS_AGGREGATE_H
#define MTMETIS_AGGREGATE_H




#include "base.h"
#include "ctrl.h"
#include "graph.h"




/******************************************************************************
* PARALLEL FUNCTION PROTOTYPES ************************************************
******************************************************************************/


#define par_aggregate_graph MTMETIS_par_aggregate_graph
/**
 * @brief Aggregate the vertices of a graph together for coarsening.
 *
 * @param ctrl The control containing aggregation parameters.
 * @param graph The graph to aggeragate.
 * @param gmatch The global matching/clustering array.
 * @param fcmap The first-vertex coarse map.
 *
 * @return The number of coarse vertices that will be generated when this
 * aggregation is contracted.
 */
vtx_type par_aggregate_graph(
    ctrl_type * ctrl,
    graph_type * graph,
    vtx_type * const * gmatch,
    vtx_type * fcmap);




#endif
