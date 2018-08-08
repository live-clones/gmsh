#ifndef _HXT_TETPOSTPRO_
#define _HXT_TETPOSTPRO_

#ifdef __cplusplus
extern "C" {
#endif

#include "hxt_mesh.h"

/**
* \file hxt_tetPospro.h postprocessing to keep only some part of a tetrahedra mesh
* \author Célestin Marot
*/

/** keep only tetrahedra whose intersection with a plane is not empty.
The plane is defined by 3 points. */
HXTStatus hxtTetPlaneIntersection(HXTMesh* mesh, double* p0, double* p1, double* p2);

/** keep only tetrahedra with at least two vertices on the positive side of the plane {p0,p1,p2}.
(p is on the positive side <=> orient3d(p0,p1,p2, p) > 0)
When seen from the negative side, p0,p1,p2 is counter-clockwise  */
HXTStatus hxtTetPlaneOrient(HXTMesh* mesh, double* p0, double* p1, double* p2);

/** keep only vertices that are either in the surface mesh or in the tetrahedra mesh */
HXTStatus hxtFilterVertices(HXTMesh* mesh, double* nodalSizes);


#ifdef __cplusplus
}
#endif

#endif
