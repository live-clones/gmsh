/**
 * @file order.h
 * @brief Functions for creating a partition induced ordering (such as nested
 * dissection).
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright 2014, Regents of the University of Minnesota
 * @version 1
 * @date 2014-10-13
 */





#ifndef MTMETIS_ORDER_H
#define MTMETIS_ORDER_H




#include "base.h"
#include "ctrl.h"
#include "graph.h"





/******************************************************************************
* FUNCTION PROTOTYPES *********************************************************
******************************************************************************/


/**
 * @brief Create a permutation of a graph using nested dissection. 
 *
 * @param ctrl The control structure specifying parameters.
 * @param graph The graph to order.
 * @param perm The permutation vector (output, but pre-allocated).
 */
void par_order_nd(
    ctrl_type * ctrl,
    graph_type * graph,
    pid_type ** perm);




#endif
