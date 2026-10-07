/**
 * @file uncoarsen.h
 * @brief Uncoarsening functions.
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright 2014-2015, Regents of the University of Minnesota
 * @version 1
 * @date 2014-09-18
 */




#ifndef MTMETIS_UNCOARSEN_H
#define MTMETIS_UNCOARSEN_H




#include "graph.h"
#include "ctrl.h"




/******************************************************************************
* FUNCTION PROTOTYPES *********************************************************
******************************************************************************/


#define par_uncoarsen_graph MTMETIS_par_uncoarsen_graph
/**
 * @brief Uncoarsen a partitioning on a graph (from graph->coarser to graph).
 *
 * @param ctrl The control structure containing runtime parameters.
 * @param graph The original graph to uncoarsen the partition to.
 */
void par_uncoarsen_graph(
    ctrl_type * ctrl,
    graph_type * graph);




#endif
