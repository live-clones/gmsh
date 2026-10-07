/**
 * @file vsinfo.h
 * @brief Tupes and function prototypes for vertex separator info. 
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright 2014, Regents of the University of Minnesota
 * @version 1
 * @date 2014-11-11
 */




#ifndef MTMETIS_VSINFO_H
#define MTMETIS_VSINFO_H




#include "base.h"
#include "graph.h"
#include "ctrl.h"




/******************************************************************************
* TYPES ***********************************************************************
******************************************************************************/


typedef struct vsnbrinfo_type {
  /* no need to store information about connectivity to separator */
  wgt_type con[2];
} vsnbrinfo_type;


typedef struct vsinfo_type {
  vtx_iset_t * bnd;
  vsnbrinfo_type * nbrinfo;
} vsinfo_type;




/******************************************************************************
* DOMLIB MACROS ***************************************************************
******************************************************************************/


#define DLMEM_PREFIX vsnbrinfo
#define DLMEM_TYPE_T vsnbrinfo_type
#include <dlmem_headers.h>
#undef DLMEM_TYPE_T
#undef DLMEM_PREFIX




/******************************************************************************
* FUNCTION PROTOTYPES *********************************************************
******************************************************************************/


#define vsinfo_free MTMETIS_vsinfo_free
/**
 * @brief Free a vsinfo and its associate memory.
 *
 * @param graph The graph to free the vsinfo of.
 */
void vsinfo_free(
    graph_type * graph);


#define par_vsinfo_create MTMETIS_par_vsinfo_create
/**
 * @brief Allocate the memory arrays for refinement of a vertex separator. 
 *
 * @param ctrl The control structure.
 * @param graph The graph to create vsinfo for.
 */
void par_vsinfo_create(
    ctrl_type * ctrl,
    graph_type * graph);


#define par_vsinfo_free MTMETIS_par_vsinfo_free
/**
 * @brief Free a vsinfo and its associate memory.
 *
 * @param graph The graph to free the vsinfo of.
 */
void par_vsinfo_free(
    graph_type * graph);




/******************************************************************************
* INLINE FUNCTIONS ************************************************************
******************************************************************************/


static inline void S_calc_conn(
    vtx_type const v,
    tid_type const myid,
    vtx_type const mynvtxs,
    adj_type const * const xadj,
    vtx_type const * const adjncy,
    wgt_type const * const * const gvwgt,
    pid_type const * const * const gwhere,
    graphdist_type const dist,
    wgt_type * const con)
{
  vtx_type k, lvtx;
  adj_type j;
  tid_type nbrid;
  pid_type nbr;
  wgt_type a, b, w;

  a = 0;
  b = 0;

  for (j=xadj[v];j<xadj[v+1];++j) {
    k = adjncy[j];
    if (k < mynvtxs) {
      lvtx = k;
      nbrid = myid;
    } else {
      lvtx = gvtx_to_lvtx(k,dist);
      nbrid = gvtx_to_tid(k,dist);
    }
    nbr = gwhere[nbrid][lvtx];
    w = gvwgt[nbrid][lvtx];
    switch (nbr) {
      case 0:
        a += w; 
        break;
      case 1:
        b += w;
        break;
    }
  }

  con[0] = a;
  con[1] = b;
}




#endif
