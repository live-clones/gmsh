#ifndef HXT_POINT_GEN_ORIENTATION_H
#define HXT_POINT_GEN_ORIENTATION_H

#include "hxt_api.h"
#include "hxt_mesh.h"

/* in a tri, directions may not be ordered "coherently" at the different vertices,
 * this function orders them well */
HXTStatus hxtGetCoherentDirectionsInTri(HXTMesh* m, const double* directions, uint64_t tri, double triDirs[3][9]);

/* in a tet, directions may not be ordered "coherently" at the different vertices,
 * this function orders them well */
HXTStatus hxtGetCoherentDirectionsInTet(HXTMesh* m, const double* directions, uint64_t tet, double tetDirs[4][9]);

/* directions[9*i+3*j] is a unit direction (3 consecutive doubles) associated to the j-th branch of the i-th 3D cross */
HXTStatus hxtOrientationFieldToDirections(uint32_t n, const double* orientation3d, double* directions);

#endif
