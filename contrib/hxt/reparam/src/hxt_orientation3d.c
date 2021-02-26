#include "hxt_orientation3d_NL.h"
#include "hxt_orientation3d_scaling.h"
#include "hxt_orientation3d_explicit.h"
/* #include "hxt_orientation3d_implicit.h" */
#include "hxt_orientation3d_NL.h"
// #include "hxt_api.h"
#include "hxt_mesh.h"
#include "hxt_tools.h"
#include "hxt_linear_system.h"
#include "hxt_orientation3d_tools.h"
#include <math.h>
#include <stdio.h>
#include <time.h>

HXTStatus hxtOr3DComputeFrames(HXTMesh *mesh, double *frames, double precision, int maxIter, int solveType, double epsilon, int L, int P, int *isBoundaryCondition)
{
  switch(solveType){
  case 0:
    for (uint64_t i = 0; i < mesh->vertices.num*9; ++i)
      frames[i] = 0;
    hxtComputeFramesExplicit(mesh, frames, precision, maxIter, 0, 0, epsilon, L, P, isBoundaryCondition);
    break;
  case 1:
    hxtComputeFramesExplicit(mesh, frames, precision, maxIter, 1, 0, epsilon, L, P, isBoundaryCondition);
    break;
  case 2:
    for (uint64_t i = 0; i < mesh->vertices.num*9; ++i)
      frames[i] = 0;
    computeFramesNL(mesh, frames,0,epsilon);
    break;
  case 3:
    computeFramesNL(mesh, frames,1,epsilon);
    break;
  case 4:
    hxtComputeFramesExplicit(mesh, frames, precision, maxIter, 1, 0, epsilon, L, P, isBoundaryCondition);
    computeFramesEulerIntNL(mesh, frames,0,epsilon);
    break;
  case 5:
    /* solveAndWriteDBG2DRect(mesh); */
    /* computeFramesEulerNL(mesh, frames, 1, epsilon); */
    /* computeFramesEulerMixedNL(mesh, frames, 1, epsilon); */
    /* computeFramesEulerConstScalNL(mesh, frames,1,epsilon); */
    hxtComputeFramesExplicit(mesh, frames, precision, maxIter, 0, 1, epsilon, L, P, isBoundaryCondition);
    break;
  } 
  return HXT_STATUS_OK;
}

HXTStatus hxtOr3DFitCrossesToQuadSurfMesh(HXTMesh *quadMesh, HXTMesh *tetMesh, double *frames){
  printf("fitting crosses on quad mesh\n");
  hxtFitCrossesToQuadSurfMesh(quadMesh, tetMesh, frames);
  return HXT_STATUS_OK;
}
  
HXTStatus hxtOr3DScaleCrossFromFrames(HXTMesh *mesh, double *frames, double *directionsScaled, double *smoothnessIndicator){
  hxtScaleCrossesFromFrames(mesh, frames, directionsScaled, smoothnessIndicator);
  return HXT_STATUS_OK;
}

HXTStatus hxtOr3DScaleCrossFromFramesQuadBC(HXTMesh *mesh, HXTMesh *quadMesh, double *frames, double *directionsScaled, double *smoothnessIndicator){
  hxtScaleCrossesFromFramesQuadBC(mesh, quadMesh, frames, directionsScaled, smoothnessIndicator);
  return HXT_STATUS_OK;
}
