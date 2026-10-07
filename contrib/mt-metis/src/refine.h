/**
 * @file refine.h
 * @brief Refinement functions
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright 2015, Regents of the University of Minnesota
 * @version 1
 * @date 2015-05-20
 */




#ifndef MTMETIS_REIFNE_H
#define MTMETIS_REFINE_H




#include "ctrl.h"
#include "graph.h"




/******************************************************************************
* FUNCTION PROTOTYPES *********************************************************
******************************************************************************/


#define par_refine_graph MTMETIS_par_refine_graph
/**
 * @brief Refine the partition of a graph.
 *
 * @param ctrl The control structure with partitioning parameters.
 * @param graph The graph to refine the partition on.
 *
 * @return The number of vertices moved while refining the partition.
 */
vtx_type par_refine_graph(
    ctrl_type * ctrl,
    graph_type * graph);




#endif
