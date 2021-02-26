#ifndef HXT_ORIENTATION3D_INTEGRABILITY_H
#define HXT_ORIENTATION3D_INTEGRABILITY_H

#include "hxt_mesh.h"

void getBuildingVectors(const double euler[3], double u[3], double v[3], double w[3], double uOrth[3], double vOrth[3], double wOrth[3], double uXY[3], double vXY[3], double wXY[3], double wPi2[3], double u1[3]);
double computeKnotchEnergy(const double dirG[9], const double eulerG[3], const double gradPsi[3], const double gradTheta[3], const double gradPhi[3]);
double computeKnotchEnergy2(const double dirG[9], const double eulerG[3], const double gradPsi[3], const double gradTheta[3], const double gradPhi[3]);
HXTStatus computeMeshEnergyKnotch(HXTMesh *mesh, const double *directions, double *energyKnotchPerTet);
HXTStatus computeMeshEnergyKnotch2(HXTMesh *mesh, double *directions, double *energyKnotchPerTet);
HXTStatus computeLocalOpIntegrabilityB(HXTMesh *mesh, uint32_t *tetNodes, double framesElemNew[9*4], double epsilon, double grad[9*4], double Hess[9*4*9*4]);
HXTStatus getGradFDEulerInt(HXTMesh *mesh, uint32_t *tetNodes, double framesElem[9*4], double grad[3*4]);
HXTStatus getGradEulerInt(HXTMesh *mesh, uint32_t *tetNodes, double framesElemNew[9*4], double grad[3*4]);
HXTStatus getGradConstScal(HXTMesh *mesh, uint32_t *tetNodes, double framesElem[9*4], double grad[3*4]);
HXTStatus testGradValue(HXTMesh *mesh, int *invSortedVertices, double *directionsSorted);
#endif
