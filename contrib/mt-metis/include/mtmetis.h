/**
 * @file mtmetis.h
 * @brief Library entry points
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright 2013, Regents of the University of Minnesota
 * @version 1
 * @date 2013-07-01
 */





#ifndef MTMETIS_H
#define MTMETIS_H




/******************************************************************************
* INCLUDES ********************************************************************
******************************************************************************/


#include <unistd.h>
#include <stdint.h>
#include <float.h>




/******************************************************************************
* MACROS **********************************************************************
******************************************************************************/


#define MTMETIS_VER_MAJOR 0
#define MTMETIS_VER_MINOR 6
#define MTMETIS_VER_SUBMINOR 0




/******************************************************************************
* TYPES ***********************************************************************
******************************************************************************/


/* For Gmsh: 64-bit edge indices, as the dual graphs of meshes of more than a
 * billion elements have more than 2^32 edges */
#ifndef MTMETIS_64BIT_EDGES
#define MTMETIS_64BIT_EDGES 1
#endif

#ifndef MTMETIS_GRAPH_TYPES_DEFINED
/* define these types for internal use */
#ifdef MTMETIS_64BIT_VERTICES
typedef uint64_t mtmetis_vtx_type;
#else
typedef uint32_t mtmetis_vtx_type;
#endif

#ifdef MTMETIS_64BIT_EDGES
typedef uint64_t mtmetis_adj_type;
#else
typedef uint32_t mtmetis_adj_type;
#endif

/* this must be signed for refinement to work */
#ifdef MTMETIS_64BIT_WEIGHTS
typedef int64_t mtmetis_wgt_type;
#else
typedef int32_t mtmetis_wgt_type;
#endif
#endif /* MTMETIS_GRAPH_TYPES_DEFINED */


#ifdef MTMETIS_64BIT_PARTITIONS
typedef uint64_t mtmetis_pid_type;
#else
typedef uint32_t mtmetis_pid_type;
#endif


#ifdef MTMETIS_DOUBLE_REAL
typedef double mtmetis_real_type;
#else
typedef float mtmetis_real_type;
#endif




/* enums *********************************************************************/

typedef enum mtmetis_error_t {
  MTMETIS_SUCCESS = 1,
  MTMETIS_ERROR_INVALIDINPUT,
  MTMETIS_ERROR_NOTENOUGHMEMORY,
  MTMETIS_ERROR_THREADING
} mtmetis_error_t;


typedef enum mtmetis_option_t {
  MTMETIS_OPTION_TIME,
  MTMETIS_OPTION_NPARTS,
  MTMETIS_OPTION_NTHREADS,
  MTMETIS_OPTION_SEED,
  MTMETIS_OPTION_NCUTS,
  MTMETIS_OPTION_NRUNS,
  MTMETIS_OPTION_NINITSOLUTIONS,
  MTMETIS_OPTION_NITER,
  MTMETIS_OPTION_UBFACTOR,
  MTMETIS_OPTION_CTYPE,
  MTMETIS_OPTION_CONTYPE,
  MTMETIS_OPTION_LEAFMATCH,
  MTMETIS_OPTION_RTYPE,
  MTMETIS_OPTION_PTYPE,
  MTMETIS_OPTION_VERBOSITY,
  MTMETIS_OPTION_DISTRIBUTION,
  MTMETIS_OPTION_RUNSTATS,
  MTMETIS_OPTION_METIS,
  MTMETIS_OPTION_REMOVEISLANDS,
  MTMETIS_OPTION_VWGTDEGREE,
  MTMETIS_OPTION_IGNORE,
  MTMETIS_OPTION_HILLSIZE,
  MTMETIS_OPTION_HS_SCANTYPE,
  /* used only be command line */
  MTMETIS_OPTION_VERSION,
  MTMETIS_OPTION_HELP,
  __MTMETIS_OPTION_TERM
} mtmetis_option_t;


typedef enum mtmetis_ctype_t {
  MTMETIS_CTYPE_RM,
  MTMETIS_CTYPE_SHEM,
  MTMETIS_CTYPE_SLEM,
  MTMETIS_CTYPE_MDM,
  MTMETIS_CTYPE_FC
} mtmetis_ctype_t;


typedef enum mtmetis_contype_t {
  MTMETIS_CONTYPE_CLS,
  MTMETIS_CONTYPE_DENSE,
  MTMETIS_CONTYPE_SORT
} mtmetis_contype_t;


typedef enum mtmetis_rtype_t {
  MTMETIS_RTYPE_GREEDY,
  MTMETIS_RTYPE_FM,
  MTMETIS_RTYPE_SFM,
  MTMETIS_RTYPE_SFG,
  MTMETIS_RTYPE_HS
} mtmetis_rtype_t;


typedef enum mtmetis_ptype_t {
  MTMETIS_PTYPE_KWAY,
  MTMETIS_PTYPE_ESEP,
  MTMETIS_PTYPE_RB,
  MTMETIS_PTYPE_VSEP,
  MTMETIS_PTYPE_ND
} mtmetis_ptype_t;


typedef enum mtmetis_hs_scan_t {
  MTMETIS_HS_SCAN_SQRT,
  MTMETIS_HS_SCAN_1PC,
  MTMETIS_HS_SCAN_5PC,
  MTMETIS_HS_SCAN_25PC,
  MTMETIS_HS_SCAN_FULL,
} mtmetis_hs_scan_t;


typedef enum mtmetis_verbosity_t {
  MTMETIS_VERBOSITY_NONE,
  MTMETIS_VERBOSITY_LOW,
  MTMETIS_VERBOSITY_MEDIUM,
  MTMETIS_VERBOSITY_HIGH,
  MTMETIS_VERBOSITY_MAXIMUM
} mtmetis_verbosity_t;


typedef enum mtmetis_dtype_t {
  MTMETIS_DISTRIBUTION_BLOCK,
  MTMETIS_DISTRIBUTION_CYCLIC,
  MTMETIS_DISTRIBUTION_BLOCKCYCLIC
} mtmetis_dtype_t;


typedef enum mtmetis_part_t {
  MTMETIS_VSEP_NULL = -1,
  MTMETIS_VSEP_PARTA = 0,
  MTMETIS_VSEP_PARTB = 1,
  MTMETIS_VSEP_SEP = 2,
  MTMETIS_VSEP_NPARTS = 3,
  MTMETIS_ESEP_PARTA = 0,
  MTMETIS_ESEP_PARTB = 1,
  MTMETIS_ESEP_NPARTS = 2
} mtmetis_part_t;


typedef enum mtmetis_ignore_t {
  MTMETIS_IGNORE_NONE = 0x00,
  MTMETIS_IGNORE_VERTEXWEIGHTS = 0x01,
  MTMETIS_IGNORE_EDGEWEIGHTS = 0x02
} mtmetis_ignore_t;




/******************************************************************************
* CONSTANTS *******************************************************************
******************************************************************************/


static size_t const MTMETIS_NOPTIONS = __MTMETIS_OPTION_TERM;
static double const MTMETIS_VAL_OFF = -DBL_MAX;




/******************************************************************************
* FUNCTION PROTOTYPES *********************************************************
******************************************************************************/


#ifdef __cplusplus
extern "C" {
#endif


/**
 * @brief Allocate and initialize a set of options for use with the
 * mtmetis_partkway_explicit() function.
 *
 * @return The allocated and initialized options. 
 */
double * mtmetis_init_options(void);


/**
 * @brief Create a partitioning of a graph using recursive bisection. 
 *
 * @param nvtxs The number of vertices in the graph.
 * @param ncon The number of balance constraints (only 1 is supported at 
 * this time).
 * @param xadj The adjacency list pointer (equivalent to rowptr in CSR).
 * @param adjncy The adjacency list.
 * @param vwgt The vertex weights.
 * @param vsize Unused.
 * @param adjwgt The edge weights.
 * @param nparts The number of partitions desired.
 * @param tpwgts The target partition weights (as a fraction of the total). 
 * @param ubvec The imbalance tolerance for each constraint (again, only 1 is
 * allowed currently). 
 * @param options The configuration options for this run.
 * @param r_edgecut The total cut edgeweight of the resulting partitioning
 * (output).
 * @param where The partition assignments for each vertex (output).
 *
 * @return MTMETIS_SUCCESS upon success partitioning generation. 
 */
int MTMETIS_PartGraphRecursive(
    mtmetis_vtx_type const * nvtxs,
    mtmetis_vtx_type const * ncon,
    mtmetis_adj_type const * xadj,
    mtmetis_vtx_type const * adjncy,
    mtmetis_wgt_type const * vwgt,
    mtmetis_vtx_type const * vsize,
    mtmetis_wgt_type const * adjwgt,
    mtmetis_pid_type const * nparts,
    mtmetis_real_type const * tpwgts,
    mtmetis_real_type const * ubvec,
    double const * options,
    mtmetis_wgt_type * r_edgecut,
    mtmetis_pid_type * where);


/**
 * @brief Create a direct k-way partitioning of a graph. 
 *
 * @param nvtxs The number of vertices in the graph.
 * @param ncon The number of balance constraints (only 1 is supported at 
 * this time).
 * @param xadj The adjacency list pointer (equivalent to rowptr in CSR).
 * @param adjncy The adjacency list.
 * @param vwgt The vertex weights.
 * @param vsize Unused.
 * @param adjwgt The edge weights.
 * @param nparts The number of partitions desired.
 * @param tpwgts The target partition weights (as a fraction of the total). 
 * @param ubvec The imbalance tolerance for each constraint (again, only 1 is
 * allowed currently). 
 * @param options The configuration options for this run.
 * @param r_edgecut The total cut edgeweight of the resulting partitioning
 * (output).
 * @param where The partition assignments for each vertex (output).
 *
 * @return MTMETIS_SUCCESS upon success partitioning generation. 
 */
int MTMETIS_PartGraphKway(
    mtmetis_vtx_type const * nvtxs,
    mtmetis_vtx_type const * ncon,
    mtmetis_adj_type const * xadj,
    mtmetis_vtx_type const * adjncy,
    mtmetis_wgt_type const * vwgt,
    mtmetis_vtx_type const * vsize,
    mtmetis_wgt_type const * adjwgt,
    mtmetis_pid_type const * nparts,
    mtmetis_real_type const * tpwgts,
    mtmetis_real_type const * ubvec,
    double const * options,
    mtmetis_wgt_type * r_edgecut,
    mtmetis_pid_type * where);


/**
 * @brief Create a nested dissection ordering of a graph.
 *
 * @param nvtxs The number of vertices in the graph.
 * @param xadj The adjacency list pointer (equivalent to rowptr in CSR).
 * @param adjncy The adjacency list.
 * @param vwgt The vertex weights.
 * @param options The options for the partitioning.
 * @param perm The permutation vector for re-ordering a sparse matrix (output).
 * @param iperm The permutation vector for mapping from a re-ordered
 * vector/matrix to the original ordering (output).
 *
 * @return MTMETIS_SUCCESS upon successful ordering generation.
 */
int MTMETIS_NodeND(
    mtmetis_vtx_type const * nvtxs,
    mtmetis_adj_type const * xadj,
    mtmetis_vtx_type const * adjncy,
    mtmetis_wgt_type const * vwgt,
    double const * options,
    mtmetis_pid_type * perm,
    mtmetis_pid_type * iperm);


/**
 * @brief Partition a graph using an explicit set of options detailing what
 * tupe of operation to perform.
 *
 * @param nvtxs The number of vertices in the graph.
 * @param xadj The adjacency list pointer.
 * @param adjncy The adjacency list.
 * @param vwgt The vertex weights.
 * @param adjwgt The edge weights.
 * @param options The set of options.
 * @param where The partition ID of each vertex (can be NULL, or of length
 * nvtxs)
 * @param r_edgecut A reference to the weight of cut edges (can be NULL).
 *
 * @return MTMETIS_SUCCESS unless an error was encountered.
 */
int mtmetis_partition_explicit(
    mtmetis_vtx_type nvtxs,
    mtmetis_adj_type const * xadj,
    mtmetis_vtx_type const * adjncy,
    mtmetis_wgt_type const * vwgt,
    mtmetis_wgt_type const * adjwgt,
    double const * options,
    mtmetis_pid_type * where,
    mtmetis_wgt_type * r_edgecut);




#ifdef __cplusplus
}
#endif



#endif
