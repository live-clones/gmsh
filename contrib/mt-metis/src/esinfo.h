/**
 * @file esinfo.h
 * @brief Types and function prototypes for edge separator refinement 
 * information.
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright 2015, Regents of the University of Minnesota
 * @version 1
 * @date 2015-02-26
 */





#ifndef MTMETIS_ESINFO_H
#define MTMETIS_ESINFO_H




#include "base.h"
#include "graph.h"
#include "ctrl.h"





/******************************************************************************
* TYPES ***********************************************************************
******************************************************************************/


typedef struct esnbrinfo_type {
  wgt_type con[2];
} esnbrinfo_type;


typedef struct esinfo_type {
  vtx_iset_t * bnd;
  esnbrinfo_type * nbrinfo;
} esinfo_type;




/******************************************************************************
* DOMLIB MACROS ***************************************************************
******************************************************************************/


#define DLMEM_PREFIX esnbrinfo
#define DLMEM_TYPE_T esnbrinfo_type
#include <dlmem_headers.h>
#undef DLMEM_TYPE_T
#undef DLMEM_PREFIX




/******************************************************************************
* FUNCTION PROTOTYPES *********************************************************
******************************************************************************/


#define esinfo_free MTMETIS_esinfo_free
/**
 * @brief Free an esinfo and its associated memory.
 *
 * @param graph The graph to free the esinfo of.
 */
void esinfo_free(
    graph_type * graph);


#define par_esinfo_create MTMETIS_par_esinfo_create
/**
 * @brief Allocate the memory arrays for refinement of an edge separator.
 *
 * @param ctrl The control structure.
 * @param graph The graph.
 */
void par_esinfo_create(
    ctrl_type * ctrl,
    graph_type * graph);


#define par_esinfo_free MTMETIS_par_esinfo_free
/**
 * @brief Free an esinfo and its associated memory.
 *
 * @param graph The graph to free the esinfo of.
 */
void par_esinfo_free(
    graph_type * graph);




#endif
