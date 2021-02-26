#ifndef HXT_ORIENTATION3D_EXPLICIT_H
#define HXT_ORIENTATION3D_EXPLICIT_H

#include "hxt_mesh.h"
#include "hxt_linear_system.h"

#ifdef __cplusplus
extern "C" {
#endif
  
  typedef void (*ptrObjectiveFunction)(double*,double*,double*);
  typedef struct HXTOrientation3DExplStruct HXTOrientation3DExpl;

  /* int testLapackVP(); */
  /* void NelderMeadSimplex(double *var, int size, double *res, ptrObjectiveFunction ptrFct, double *inputData); */
  /* void objectiveFunctionTest(double *inputData, double *gamma, double *valueFctCout); */
  /* void objectiveFunctionTest2D(double *inputData, double *gamma, double *valueFctCout); */
  /* HXTStatus assembleSystemExplicit(HXTMesh *mesh, HXTLinearSystem *lsys); */
  /* HXTStatus projection(HXTOrientation3DExpl *or3D, HXTMesh *mesh, double *normals, double *frames, int *sortedVertices,int cptVbound); */
  /* HXTStatus projectionOnBoundary(HXTOrientation3DExpl *or3D, double *frames, double *normals, int nVert, int cptVbound, int *sortedVertices); */
  /* HXTStatus computeCrossOnEdges(HXTMesh *mesh, double *normals, double *frames, int *sortedVertices,int cptVbound); */
  HXTStatus hxtComputeFramesExplicit(HXTMesh *mesh, double *frames, double precision, int maxIter, int framesHasToBeInitialized, int flagFixNodes, double epsilon, int L, int P, int *isBoundaryCondition);

  HXTStatus hxtFitCrossesToQuadSurfMesh(HXTMesh *quadMesh, HXTMesh *tetMesh, double *frames);
#ifdef __cplusplus
}
#endif

#endif
