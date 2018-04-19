#ifndef _HXT_TETADJACENCIES_
#define _HXT_TETADJACENCIES_

#ifdef __cplusplus
extern "C" {
#endif

#include "hxt_mesh.h"

/* (re-)compute the adjacency of a mesh */
HXTStatus hxtComputeAdjacencies(HXTMesh* mesh);


#ifdef __cplusplus
}
#endif

#endif

