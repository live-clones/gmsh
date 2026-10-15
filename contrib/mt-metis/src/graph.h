/**
 * @file graph.h
 * @brief Types and functions for distributed graph objects.
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright 2014, Regents of the University of Minnesota
 * @version 1
 * @date 2014-09-16
 */




#ifndef MTMETIS_GRAPH_H
#define MTMETIS_GRAPH_H




#include "base.h"
#include "ctrl.h"




/******************************************************************************
* TYPES ***********************************************************************
******************************************************************************/


typedef struct graphdist_type {
  tid_type nthreads;
  vtx_type mask;
  int shift;
  vtx_type offset;
} graphdist_type;


typedef struct graph_type {
  /* global counts */
  vtx_type nvtxs; 
  vtx_type gnvtxs;
  adj_type nedges;
  /* distribution information */
  dlthread_comm_t comm;
  graphdist_type dist;
  /* pre partitioning info */
  pid_type ** group;
  pid_type ngroup;
  /* distributed graph structure */
  vtx_type * mynvtxs;
  adj_type * mynedges;
  adj_type ** xadj;
  wgt_type ** vwgt;
  vtx_type ** adjncy;
  wgt_type ** adjwgt;
  /* graph info */
  int uniformvwgt;
  int uniformadjwgt;
  vtx_type * nislands;
  /* coarsening info */
  size_t level;
  vtx_type ** cmap;
  /* partition information */
  wgt_type * pwgts;
  pid_type ** where;
  struct kwinfo_type * kwinfo;
  struct esinfo_type * esinfo;
  struct vsinfo_type * vsinfo;
  /* total weight */
  twgt_type tvwgt, tadjwgt;
  real_type invtvwgt;
  /* aliasing */
  vtx_type ** rename;
  vtx_type ** label;
  /* metrics */
  wgt_type mincut, minsep;
  vtx_type minvol;
  /* "To free, or not free" */
  int free_xadj, free_vwgt, free_vsize, free_adjncy, free_adjwgt;
  /* graphs in the heirarchy */
  struct graph_type *coarser, *finer;
} graph_type;




/******************************************************************************
* SERIAL FUNCTION PROTOTYPES **************************************************
******************************************************************************/


#define graph_create MTMETIS_graph_create
/**
 * @brief Allocate and initialize a graph structure.
 *
 * @param nthreads The number of threads the graph will be used by.
 *
 * @return The allocated and initialized graph.
 */
graph_type * graph_create(
    tid_type nthreads);


#define graph_setup MTMETIS_graph_setup
/**
 * @brief Setup a graph structure given this threads parts of the graph.
 *
 * @param nvtxs The number of vertices in the graph.
 * @param xadj The adjacency list pointer.
 * @param adjncy The adjacency list.
 * @param adjwgt The edge weights.
 * @param vwgt The vertex weights.
 * @param nthreads The number of threads the graph is distributed across. 
 *
 * @return The setup graph structure.
 */
graph_type * graph_setup(
    vtx_type * nvtxs, 
    adj_type ** xadj, 
    vtx_type ** adjncy, 
    wgt_type ** adjwgt, 
    wgt_type ** vwgt,
    tid_type nthreads);


#define graph_distribute MTMETIS_graph_distribute
/**
 * @brief Distribute a csr based graph among threads. 
 *
 * @param dist The type of distribution to use.
 * @param nvtxs The number of vertices in the graph.
 * @param xadj The adjacency list poitner.
 * @param adjncy The adjacecny list.
 * @param vwgt The vertex weights.
 * @param adjwgt The edge weights.
 * @param nthreads The number of threads to distribute the graph between.
 *
 * @return The distributed graph. 
 */
graph_type * graph_distribute(
    int dist,
    vtx_type nvtxs, 
    adj_type const * xadj, 
    vtx_type const * adjncy, 
    wgt_type const * vwgt,
    wgt_type const * adjwgt, 
    tid_type nthreads);


#define graph_gather MTMETIS_graph_gather
/**
 * @brief Gather a copy of the graph to each thread. Alias is private to each
 * thread where the other three arrays are not.
 *
 * @param graph The distributed graph to gather.
 * @param r_xadj A refernce to the adjacency list pointer.
 * @param r_adjncy A reference to the adjacency list.
 * @param r_vwgt A reference to the vertex weight.
 * @param r_adjwgt A reference to the edge weight.
 * @param r_voff A reference to the offset of the vertices for this thread.
 */
void graph_gather(
  graph_type const * graph,
  adj_type ** r_xadj,
  vtx_type ** r_adjncy,
  wgt_type ** r_vwgt,
  wgt_type ** r_adjwgt,
  vtx_type ** r_voff);


#define graph_setup_coarse MTMETIS_graph_setup_coarse
/**
 * @brief Setup a coarse graph given the fine graph and the number of coarse
 * vertices.  
 *
 * @param graph The fine graph.
 * @param cnvtxs The number of coarse vertices for each thread.
 *
 * @return The allocated and setup coarse graph. 
 */
graph_type * graph_setup_coarse(
    graph_type * graph, 
    vtx_type * cnvtxs);


#define graph_setup_twgts MTMETIS_graph_setup_twgts
/**
 * @brief Calculate and save the tvwgts of a new graph.
 *
 * @param graph The graph.
 */
void graph_setup_twgts(
    graph_type * graph);


#define graph_alloc_partmemory MTMETIS_graph_alloc_partmemory
/**
 * @brief Allocate memory for partition informatin.
 *
 * @param ctrl The control structure containing nparts.
 * @param graph The graph.
 */
void graph_alloc_partmemory(
    ctrl_type * ctrl,
    graph_type * graph);

#define graph_free MTMETIS_graph_free
/**
 * @brief Free a graph structure and its associated memory.
 *
 * @param graph The graph to free.
 */
void graph_free(
    graph_type * graph);


#define graph_free_rdata MTMETIS_graph_free_rdata
/**
 * @brief Free partition/refinement data associated with a graph.
 *
 * @param graph The graph to free the associated partition/refinement data of.
 */
void graph_free_rdata(
    graph_type * graph);


#define graph_imbalance MTMETIS_graph_imbalance
/**
 * @brief Compute the load imbalance of a partitioning.
 *
 * @param graph The graph.
 * @param nparts The number of partitions.
 * @param pijbm The inverted average partition weight. 
 *
 * @return The imbalance of the partitioning.
 */
double graph_imbalance(
    graph_type const * graph,
    pid_type nparts,
    real_type const * pijbm);


#define graph_imbalance_diff MTMETIS_graph_imbalance_diff
/**
 * @brief Compute the amount the load imbalance of the graph violates the
 * constraint.
 *
 * @param graph The graph.
 * @param nparts The number of partitions.
 * @param pijbm The inverted average partition weight. 
 * @param ubfactor The allowed imbalance constraint.
 *
 * @return The amount of imbalance in excess of the constraint. 
 */
double graph_imbalance_diff(
    graph_type const * const graph,
    pid_type const nparts,
    real_type const * const pijbm,
    real_type const ubfactor);


#define graph_cut MTMETIS_graph_cut
/**
 * @brief Compute the edgecut of a partitioning.
 *
 * @param graph The graph structure.
 * @param where The partition labels.
 *
 * @return The total weight of cut edges.
 */
wgt_type graph_cut(
    graph_type const * graph,
    pid_type const * const * where);


#define graph_isbalanced MTMETIS_graph_isbalanced
/**
 * @brief Check if a partitioning of a graph is balanced within the given
 * constraint.
 *
 * @param ctrl The control structure.
 * @param graph The partitioned graph.
 * @param ffactor The balance constraint.
 *
 * @return 1 if the partitioning is balanced.
 */
int graph_isbalanced(
    ctrl_type const * ctrl, 
    graph_type const * graph, 
    real_type ffactor);


#define graph_readjust_memory MTMETIS_graph_readjust_memory
/**
 * @brief Re-adjust the memory used the by edge arrays of a graph. 
 *
 * @param graph The graph structure.
 * @param adjsize The current size of the adjacency arrays.
 */
void graph_readjust_memory(
    graph_type * const graph,
    adj_type adjsize);


#define graph_extract_halves MTMETIS_graph_extract_halves
/**
 * @brief Pull out partition 0 and partition 1 from a vertex separated graph or
 * edge bisected graph. Vertices with high partition labels than 1 are dropped.
 * This sets the label[][] array of the new graphs to be global vertex numbers
 * in the original graph, and sets the rename[][] array in the original graph
 * to be global vertex numbers in the new graph.
 *
 * @param graph The graph to extract subgraphs from.
 * @param where The partition ID's of each vertex.
 * @param halves The two extracted subgraphs (output).
 */
void graph_extract_halves(
    graph_type * graph,
    pid_type const * const * where,
    graph_type ** halves);


#define graph_size MTMETIS_graph_size
/**
 * @brief Determine the amount of memory required to store the graph.
 *
 * @param graph The graph to calculate the size of.
 *
 * @return The number of bytes required to store the graph.
 */
size_t graph_size(
    graph_type const * graph);


#define graph_calc_dist MTMETIS_graph_calc_dist
/**
 * @brief Configure the distribution structure.
 *
 * @param maxnvtxs The maximum number of vertices owned by a thread.
 * @param nthreads The number of threads.
 * @param dist The distribution structure to configure.
 */
void graph_calc_dist(
    vtx_type maxnvtxs, 
    tid_type nthreads,
    graphdist_type * dist);




/******************************************************************************
* PARALLEL FUNCTION PROTOTYPES ************************************************
******************************************************************************/


#define par_graph_create MTMETIS_par_graph_create
/**
 * @brief Allocate and initialize a graph structure.
 *
 * @param nthreads The thread communicator.
 *
 * @return The allocated and initialized graph.
 */
graph_type * par_graph_create(
    dlthread_comm_t comm);


#define par_graph_setup MTMETIS_par_graph_setup
/**
 * @brief Setup a graph structure given this threads parts of the graph.
 *
 * @param nvtxs The number of vertices in the graph.
 * @param xadj The adjacency list pointer.
 * @param adjncy The adjacency list.
 * @param adjwgt The edge weights.
 * @param vwgt The vertex weights.
 * @param comm The thread communicator.
 *
 * @return The setup graph structure.
 */
graph_type * par_graph_setup(
    vtx_type nvtxs, 
    adj_type * xadj, 
    vtx_type * adjncy, 
    wgt_type * adjwgt, 
    wgt_type * vwgt,
    dlthread_comm_t comm);


#define par_graph_gather MTMETIS_par_graph_gather
/**
 * @brief Gather a copy of the graph to each thread. Alias is private to each
 * thread where the other three arrays are not.
 *
 * @param graph The distributed graph to gather.
 * @param r_xadj A refernce to the adjacency list pointer.
 * @param r_adjncy A reference to the adjacency list.
 * @param r_vwgt A reference to the vertex weight.
 * @param r_adjwgt A reference to the edge weight.
 * @param r_voff A reference to the offset of the vertices for this thread.
 */
void par_graph_gather(
  graph_type const * graph,
  adj_type ** r_xadj,
  vtx_type ** r_adjncy,
  wgt_type ** r_vwgt,
  wgt_type ** r_adjwgt,
  vtx_type * r_voff);


#define par_graph_shuffle MTMETIS_par_graph_shuffle
/**
 * @brief Shuffle the vertices in a graph such that the partition matches the
 * owning thread. 
 *
 * @param ctrl The control structure.
 * @param graph The graph to shuffle.
 * @param where The partition (destination thread) ids of each vertex.
 * @param wgts Preserve the current weight information.
 */
void par_graph_shuffle(
    ctrl_type * ctrl,
    graph_type * graph,
    pid_type const * const * where,
    int wgts);


#define par_graph_setup_coarse MTMETIS_par_graph_setup_coarse
/**
 * @brief Setup a coarse graph given the fine graph and the number of coarse
 * vertices.  
 *
 * @param graph The fine graph.
 * @param cnvtxs The number of coarse vertices.
 *
 * @return The allocated and setup coarse graph. 
 */
graph_type * par_graph_setup_coarse(
    graph_type * const graph, 
    vtx_type cnvtxs);


#define par_graph_setup_twgts MTMETIS_par_graph_setup_twgts
/**
 * @brief Calculate and save the twgts of a new graph.
 *
 * @param graph The graph.
 */
void par_graph_setup_twgts(
    graph_type * graph);


#define par_graph_alloc_partmemory MTMETIS_par_graph_alloc_partmemory
/**
 * @brief Allocate memory for partition informatin.
 *
 * @param ctrl The control structure containing nparts.
 * @param graph The graph.
 */
void par_graph_alloc_partmemory(
    ctrl_type * ctrl,
    graph_type * graph);


#define par_graph_free MTMETIS_par_graph_free
/**
 * @brief Free a graph structure and its associated memory.
 *
 * @param graph The graph to free.
 */
void par_graph_free(
    graph_type * graph);


#define par_graph_free_rdata MTMETIS_par_graph_free_rdata
/**
 * @brief Free partition/refinement data associated with a graph.
 *
 * @param graph The graph to free the associated partition/refinement data of.
 */
void par_graph_free_rdata(
    graph_type * graph);


#define par_graph_readjust_memory MTMETIS_par_graph_readjust_memory
/**
 * @brief Re-adjust the memory used the by edge arrays of a graph. 
 *
 * @param graph The graph structure.
 * @param adjsize The current size of the adjacency arrays.
 */
void par_graph_readjust_memory(
    graph_type * const graph,
    adj_type adjsize);


#define par_graph_extract_halves MTMETIS_par_graph_extract_halves
/**
 * @brief Pull out partition 0 and partition 1 from a vertex separated graph or
 * edge bisected graph. Vertices with high partition labels than 1 are dropped.
 * This sets the label[][] array of the new graphs to be global vertex numbers
 * in the original graph, and sets the rename[][] array in the original graph
 * to be global vertex numbers in the new graph.
 *
 * @param graph The graph to extract subgraphs from.
 * @param where The partition ID's of each vertex.
 * @param halves The two extracted subgraphs (output).
 *
 * @return Which half of the graph this thread is assigned.
 */
tid_type par_graph_extract_halves(
    graph_type * graph,
    pid_type const * const * where,
    graph_type ** halves);


#define par_graph_extract_boundary MTMETIS_par_graph_extract_boundary
/**
 * @brief Extract a subgraph exposing the boundary of a bisection, where the
 * size of the boundary is determined by the maximum imbalanced allowed in the
 * partitioning parameters.
 *
 * Each thread will have two vertices represent the core of each partition, at
 * indices 0 and 1.
 *
 * @param ctrl The control structure.
 * @param graph The graph.
 * @param bnd The set of vertices on the immediate boundary.
 *
 * @return The extract boundary subgraph.
 */
graph_type * par_graph_extract_boundary(
    ctrl_type const * ctrl,
    graph_type const * graph,
    vtx_iset_t const * bnd);


#define par_graph_extract_separator MTMETIS_par_graph_extract_separator
/**
 * @brief Extract a subgraph consisting only the current separator and two
 * super vertices representing each half.
 *
 * Each thread will have two vertices represent the core of each partition, at
 * indices 0 and 1.
 *
 * @param ctrl The control structure.
 * @param graph The graph.
 * @param bnd The set of vertices on the immediate boundary.
 *
 * @return The extract boundary subgraph.
 */
graph_type * par_graph_extract_separator(
    ctrl_type const * ctrl,
    graph_type const * graph,
    vtx_iset_t const * bnd);


#define par_graph_extract_aseparator MTMETIS_par_graph_extract_aseparator
/**
 * @brief Extract a subgraph consisting only the current separator and two
 * super vertices representing each half.
 *
 * Each thread will have two vertices represent the core of each partition, at
 * indices 0 and 1.
 *
 * @param ctrl The control structure.
 * @param graph The graph.
 * @param bnd The set of vertices on the immediate boundary.
 *
 * @return The extract boundary subgraph.
 */
graph_type * par_graph_extract_aseparator(
    ctrl_type const * ctrl,
    graph_type const * graph,
    vtx_iset_t const * bnd);


#define par_graph_build_radj MTMETIS_par_graph_build_radj
/**
 * @brief Build a reverse adjacency index and store it in graph->radj.
 *
 * @param graph The graph to build the reverse adjacency list of.
 *
 * @return The reverse adjacecny index.
 */
adj_type * par_graph_build_radj(
    graph_type const * graph);


#define par_graph_contract MTMETIS_par_graph_contract
/**
* @brief Create a coarse graph given a matching using hash table to identify
*   edges to be merged
*
* @param ctrl The control structure.
* @param graph The fine graph.
* @param cnvtxs The number of coarse vertices in the coarse graph.
* @param match The matchings of vertices (match[match[v]] = v).
* @param fcmap The mapping of the coarse vertex number to the lowest number
*   fine vertex in the coarse vertex.
*/
void par_graph_contract(
    ctrl_type * ctrl, 
    graph_type * graph, 
    vtx_type const cnvtxs, 
    vtx_type const * const * gmatch, 
    vtx_type const * fcmap);


#define par_graph_intext_vtx MTMETIS_par_graph_intext_vtx
/**
 * @brief Count the number of internal and external (interface) vertices owned
 * by this thread.
 *
 * @param graph The graph.
 * @param r_nint A reference to the number of internal vertices.
 * @param r_next A reference to the number of external vertices.
 */
void par_graph_intext_vtx(
    graph_type const * const graph,
    vtx_type * const r_nint,
    vtx_type * const r_next);


#define par_graph_cut MTMETIS_par_graph_cut
/**
 * @brief Compute the edgecut of a partitioning in parallel.
 *
 * @param graph The graph structure.
 * @param where The partition labels.
 *
 * @return The total weight of cut edges.
 */
wgt_type par_graph_cut(
    graph_type const * graph,
    pid_type const * const * where);


#define par_graph_removeislands MTMETIS_par_graph_removeislands
/**
 * @brief Remove island vertices from a graph and adjust parameters.
 *
 * @param ctrl The control structure.
 * @param graph The graph structure.
 */
void par_graph_removeislands(
    ctrl_type * ctrl,
    graph_type * graph);


#define par_graph_restoreislands MTMETIS_par_graph_restoreislands
/**
 * @brief Restore island vertices and parameters to a graph.
 *
 * @param ctrl The control structure.
 * @param graph The graph structure.
 * @param gwhere The where vector (should be large enough to hold island
 * vertices).
 */
void par_graph_restoreislands(
    ctrl_type * ctrl,
    graph_type * graph,
    pid_type * const * gwhere);


#define par_graph_extract_parts MTMETIS_par_graph_extract_parts
/**
 * @brief Extract the partitions from a graph. If called with more threads than
 * partitions, the number of threads should be a multiple of number of
 * partitions. The supplied 'nparts' can be lower than the actual number of
 * partitions, an donly partitions with IDs lower than 'nparts' will be
 * extracted.
 *
 * @param graph The graph to extract partitions from.
 * @param gwhere The partition id of each vertex.
 * @param nparts The number of partitions to extract.
 * @param parts The extracted partitions (output), should be of lenght nparts.
 */
void par_graph_extract_parts(
    graph_type * const graph,
    pid_type const * const * const gwhere,
    pid_type const nparts,
    graph_type ** const parts);


#define par_graph_distribute MTMETIS_par_graph_distribute
/**
 * @brief Distribute a csr based graph among a set of active threads. 
 *
 * @param dist The type of distribution to use.
 * @param nvtxs The number of vertices in the graph.
 * @param xadj The adjacency list pointer.
 * @param adjncy The adjacecny list.
 * @param vwgt The vertex weights.
 * @param adjwgt The edge weights.
 * @param comm The active thread communicator.
 *
 * @return The distributed graph. 
 */
graph_type * par_graph_distribute(
    int distribution,
    vtx_type nvtxs, 
    adj_type const * xadj, 
    vtx_type const * adjncy, 
    wgt_type const * vwgt,
    wgt_type const * adjwgt, 
    dlthread_comm_t comm);



#endif
