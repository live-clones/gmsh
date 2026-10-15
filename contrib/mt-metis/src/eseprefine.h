/**
 * @file eseprefine.h
 * @brief Functions for refining edge bisections.
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright 2015, Regents of the University of Minnesota
 * @version 1
 * @date 2015-02-26
 */





#ifndef MTMETIS_ESEPREFINE_H
#define MTMETIS_ESEPREFINE_H




#include "base.h"
#include "graph.h"
#include "ctrl.h"
#include "esinfo.h"




/******************************************************************************
* FUNCTION PROTOTYPES *********************************************************
******************************************************************************/


#define par_eseprefine MTMETIS_par_eseprefine
/**
 * @brief Refine an edge separator using the parameters specified in ctrl.
 *
 * @param ctrl The control structure specifying refinemnet parameters.
 * @param graph The partitioned graph.
 * @param esinfo The edge separator refinement information.
 *
 * @return The number of vertices moved during refinement.
 */
vtx_type par_eseprefine(
    ctrl_type * ctrl,
    graph_type * graph,
    esinfo_type * esinfo);




#endif
