#ifndef HXT_ORIENTATION3D_H
#define HXT_ORIENTATION3D_H
/*! \file hxt_crossfield_tensor.h
  \brief This module compute a 3D crossfield on a 3D domain meshed with tetrahedra.

  Functions of this module allow user to compute a 3D crossfield on a 3D domain meshed with tetrahedra.
  Two functions are available. The first one is computing it, the second one write a ".pos" file which allow user to view it using GMSH software.
  
  \author Alexandre.C
*/
#include "hxt_mesh.h"

/*! compute 3D crossfield on the 3D tetrahedral mesh HXTmesh. Results are stored in double *directions. This results has to be post treated as they are not yet explicit description of the 3D crossfield. 

size of direction array is mesh->vertices.num*9.
Data are stored following the pattern direction[9*currentVert + k], k=0..8 */
HXTStatus hxtOr3DComputeFrames(HXTMesh *mesh, double *frames, double precision, int maxIter, int solveType, double epsilon, int L, int P, int *isBoundaryCondition);
HXTStatus hxtOr3DFitCrossesToQuadSurfMesh(HXTMesh *quadMesh, HXTMesh *tetMesh, double *frames);
HXTStatus hxtOr3DScaleCrossFromFrames(HXTMesh *mesh, double *frames, double *directionsScaled, double *smoothnessIndicator);
HXTStatus hxtOr3DScaleCrossFromFramesQuadBC(HXTMesh *mesh, HXTMesh *quadMesh, double *frames, double *directionsScaled, double *smoothnessIndicator);

#endif



