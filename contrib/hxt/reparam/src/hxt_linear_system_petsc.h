#ifndef HEXTREME_LINEAR_SYSTEM_PETSC_H
#define HEXTREME_LINEAR_SYSTEM_PETSC_H

#include "hxt_message.h"
#include <stdint.h>
#include <petscmat.h>

typedef struct HXTLinearSystemPETScStruct HXTLinearSystemPETSc;

HXTStatus hxtLinearSystemPETScAddToMatrix(HXTLinearSystemPETSc *lsys, int el0, int el1, const double *localMatrix);
HXTStatus hxtLinearSystemPETScAddMatrixEntry(HXTLinearSystemPETSc *lsys, int node0, int field0, int node1, int field1, double entry);
HXTStatus hxtLinearSystemPETScAddToRhs(HXTLinearSystemPETSc *lsys, double *rhs, int el0, const double *localVector);
HXTStatus hxtLinearSystemPETScZeroMatrix(HXTLinearSystemPETSc *lsys);
HXTStatus hxtLinearSystemPETScSolve(HXTLinearSystemPETSc *lsys, double *rhs, double *solution);
HXTStatus hxtLinearSystemPETScSetMatrixRowIdentity(HXTLinearSystemPETSc *lsys, int node, int field);
HXTStatus hxtLinearSystemPETScSetMatrixRowFieldCombinaison(HXTLinearSystemPETSc *system, int node, int field, double *coeff);
HXTStatus hxtLinearSystemPETScSetRhsEntry(HXTLinearSystemPETSc *lsys, double *rhs, int node, int field, double v);
HXTStatus hxtLinearSystemPETScAddRhsEntry(HXTLinearSystemPETSc *lsys, double *rhs, int node, int field, double v);
HXTStatus hxtLinearSystemPETScDelete(HXTLinearSystemPETSc **pSystem);
HXTStatus hxtLinearSystemPETScGetRhsNorm(HXTLinearSystemPETSc *lsys, double *rhs, double *norm);
HXTStatus hxtLinearSystemPETScCreate(HXTLinearSystemPETSc **pSystem, int nElements, int nNodesByElement, int nFields, uint32_t *elements, const char *petscOptions);
HXTStatus hxtLinearSystemPETScHasConverged(HXTLinearSystemPETSc *lsys, int *converged);
HXTStatus hxtLinearSystemPETScSize(HXTLinearSystemPETSc *lsys, int *size);

HXTStatus hxtLinearSystemPETScGetMat(HXTLinearSystemPETSc *lsys, Mat *mat);
HXTStatus hxtLinearSystemPETScMapToVec(HXTLinearSystemPETSc *lsys, double *v, Vec vec);
HXTStatus hxtLinearSystemPETScMapFromVec(HXTLinearSystemPETSc *lsys, Vec vec, double *v);

HXTStatus hxtInitializePETSc(int *argc, char ***argv);

#endif
