/**
 * @file check.h
 * @brief Function prototypes for sanity checks.
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright 2014, Regents of the University of Minnesota
 * @version 1
 * @date 2014-09-16
 */




#ifndef MTMETIS_CHECK_H
#define MTMETIS_CHECK_H




#include "base.h"
#include "graph.h"
#include "esinfo.h"
#include "vsinfo.h"
#include "kwinfo.h"




/******************************************************************************
* FUNCTION PROTOTYPES *********************************************************
******************************************************************************/


#define check_kwinfo MTMETIS_check_kwinfo
/**
 * @brief Perform a sanity check on k-way refinement information.
 *
 * @param kwinfo The kwinfo to check.
 * @param graph The graph structure.
 * @param where The partition id of each vertex.
 *
 * @return 1 if the information is sane.
 */
int check_kwinfo(
    kwinfo_type const * kwinfo,
    graph_type const * graph,
    pid_type const * const * where);


#define check_vsinfo MTMETIS_check_vsinfo
/**
 * @brief Perform a sanity check on vertex separator refinement information.
 *
 * @param vsinfo The vsinfo to check.
 * @param graph The graph structure.
 * @param where The partition id of each vertex.
 *
 * @return 1 if the information is sane.
 */
int check_vsinfo(
    vsinfo_type const * vsinfo,
    graph_type const * graph,
    pid_type const * const * where);


#define check_esinfo MTMETIS_check_esinfo
/**
 * @brief Perform a sanity check on edge separator refinement information.
 *
 * @param esinfo The esinfo to check.
 * @param graph The graph structure.
 * @param where The partition id of each vertex.
 *
 * @return 1 if the information is sane.
 */
int check_esinfo(
    esinfo_type const * esinfo,
    graph_type const * graph,
    pid_type const * const * where);


#define check_graph MTMETIS_check_graph
/**
 * @brief Check the sanity of a graph structure.
 *
 * @param graph The graph structure.
 *
 * @return 1 if the graph is sane.
 */
int check_graph(
    graph_type const * graph);


#define check_kwbnd MTMETIS_check_kwbnd
/**
 * @brief Check the sanity of a boundary for kway greedy partitionings.
 *
 * @param graph The graph to check the boundary of.
 *
 * @return 1 if the boundary is sane.
 */
int check_kwbnd(
    vtx_iset_t const * bnd,
    graph_type const * graph,
    int greedy);


#define check_vsbnd MTMETIS_check_vsbnd
/**
 * @brief Check the sanity of a boundary for a vertex separator.
 *
 * @param graph The graph to check the boundary of.
 *
 * @return 1 if the boundary is sane.
 */
int check_vsbnd(
    vtx_iset_t const * bnd,
    graph_type const * graph);


#define check_esbnd MTMETIS_check_esbnd
/**
 * @brief Check the sanity of a boundary for an edge separator.
 *
 * @param graph The graph to check the boundary of.
 *
 * @return 1 if the boundary is sane.
 */
int check_esbnd(
    vtx_iset_t const * bnd,
    graph_type const * graph);




#define check_separator MTMETIS_check_separator
/**
 * @brief Check the sanity of a vertex separator.
 *
 * @param graph The graph to check the separator of.
 *
 * @return 1 if the separator is sane.
 */
int check_separator(
    graph_type const * graph,
    pid_type const * const * gwhere);



#endif
