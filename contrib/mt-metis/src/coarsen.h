/**
 * @file coarsen.h
 * @brief Functions for coarsening
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright 2014, Regents of the University of Minnesota
 * @version 1
 * @date 2014-09-16
 */




#ifndef MTMETIS_COARSEN_H
#define MTMETIS_COARSEN_H




#include "ctrl.h"
#include "graph.h"




/******************************************************************************
* PARALLEL FUNCTION PROTOTYPES ************************************************
******************************************************************************/


#define par_coarsen_graph MTMETIS_par_coarsen_graph
/**
 * @brief Coarsen a graph. 
 *
 * @param ctrl The control structure specifying how to coarsen the graph.
 * @param graph The graph to coarsen.
 *
 * @return The coarse graph.
 */
graph_type * par_coarsen_graph(
    ctrl_type * ctrl,
    graph_type * graph);




#endif
