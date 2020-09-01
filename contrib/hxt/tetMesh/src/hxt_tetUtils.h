// Hxt - Copyright (C) 
// 2016 - 2020 UCLouvain
//
// See the LICENSE.txt file for license information.
//
// Contributor(s):
//   Célestin Marot

#ifndef HXT_TETUTILS_H
#define HXT_TETUTILS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "hxt_mesh.h"
#include "hxt_tools.h"

/**
* \file tetUtils.h utility for the tetrahedral mesh
* \author Célestin Marot
*/

/* usefull macros */
#define ABS(x) ((x) >= 0 ? (x) : -(x))
#define MAX(x,y) ((x)>(y) ? (x) : (y))
#define MIN(x,y) ((x)<(y) ? (x) : (y))

/**
 * Reserve memory space for tetrahedra assuming ntet tetrahedra will be added to the triangulation
 * it is efficient to give ntet = ~8 times the number of vertices to be added
 * as in average, the number of tetrahedra is ~6.5x greater than the number of vertices
 */
static inline HXTStatus hxtTetrahedraReserve(HXTMesh* mesh, uint64_t totalTet){
  if(totalTet > mesh->tetrahedra.size){
    HXT_CHECK( hxtAlignedRealloc(&mesh->tetrahedra.flag, totalTet*sizeof(uint16_t)) );
    if(mesh->tetrahedra.color != NULL) {
      HXT_CHECK( hxtAlignedRealloc(&mesh->tetrahedra.color, totalTet*sizeof(uint32_t)) );
    }
    HXT_CHECK( hxtAlignedRealloc(&mesh->tetrahedra.node,   totalTet*4*sizeof(uint32_t)) );
    HXT_CHECK( hxtAlignedRealloc(&mesh->tetrahedra.neigh,  totalTet*4*sizeof(uint64_t)) );
    mesh->tetrahedra.size = totalTet;
  }
  return HXT_STATUS_OK;
}


/**
 * Remove tetrahedra 't' whose flag indicates they are deleted
 * it updates the adjacency of the neighbors of 't' referencing 't' 
 * to HXT_NO_ADJACENT.
 * You must set the adjacency of 't' to HXT_NO_ADJACENT if you don't want this behavior
 */
HXTStatus hxtRemoveDeleted(HXTMesh* mesh);


#ifdef __cplusplus
}
#endif

#endif
