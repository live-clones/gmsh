#ifndef _HXT_TETREPAIR_
#define _HXT_TETREPAIR_

#ifdef __cplusplus
extern "C" {
#endif

#include "hxt_mesh.h"

/**
* \file hxt_tetRepair.h Repair a tetrahedra mesh
* \author Célestin Marot
*/

/** (re-)compute the adjacency of a mesh */
HXTStatus hxtTetAdjacencies(HXTMesh* mesh);

/** orient tetrahedra correctly
 \warning The mesh cannot contain any ghost vertex */
HXTStatus hxtTetOrientNodes(HXTMesh* mesh);

/** verify the consistency of a tetrahedral mesh */
HXTStatus hxtTetVerify(HXTMesh* mesh);

/** reorder tetrahedra in a reproducible manner */
HXTStatus hxtTetReorder(HXTMesh* mesh);


#ifdef __cplusplus
}
#endif

#endif

