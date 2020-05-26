#ifndef HEXTREME_LINEAR_SYSTEM_H
#define HEXTREME_LINEAR_SYSTEM_H

#include <stdint.h>
#include "hxt_message.h"

typedef struct HXTLinearSystemStruct HXTLinearSystem;

HXTStatus hxtLinearSystemAddToMatrix(HXTLinearSystem *lsys, int el0, int el1, const double *localMatrix);
HXTStatus hxtLinearSystemAddMatrixEntry(HXTLinearSystem *lsys, int node0, int field0, int node1, int field1, double entry);
HXTStatus hxtLinearSystemAddToRhs(HXTLinearSystem *lsys, double *rhs, int el0, const double *localVector);
HXTStatus hxtLinearSystemSize(HXTLinearSystem *lsys, int *size);
HXTStatus hxtLinearSystemZeroMatrix(HXTLinearSystem *lsys);
HXTStatus hxtLinearSystemSolve(HXTLinearSystem *lsys, double *rhs, double *solution);
HXTStatus hxtLinearSystemSetMatrixRowIdentity(HXTLinearSystem *lsys, int node, int field);
HXTStatus hxtLinearSystemSetMatrixRowFieldCombinaison(HXTLinearSystem *system, int node, int field, double *coeff);
HXTStatus hxtLinearSystemSetRhsEntry(HXTLinearSystem *lsys, double *rhs, int node, int field, double v);
HXTStatus hxtLinearSystemAddRhsEntry(HXTLinearSystem *lsys, double *rhs, int node, int field, double v);
HXTStatus hxtLinearSystemDelete(HXTLinearSystem **pSystem);
HXTStatus hxtLinearSystemGetRhsNorm(HXTLinearSystem *lsys, double *rhs, double *norm);
HXTStatus hxtLinearSystemHasConverged(HXTLinearSystem *lsys, int *converged);

HXTStatus hxtLinearSystemCreateLU(HXTLinearSystem **sys, int nElement, int nNodesByElement, int nFields, uint32_t *elements);
#ifndef HEXTREME_LINEAR_SYSTEM_LU_H // to avoid illegal (in C) redefinition of typedef
typedef struct HXTLinearSystemLUStruct HXTLinearSystemLU;
#endif
HXTStatus hxtLinearSystemGetLinearSystemLU(HXTLinearSystem *sys, HXTLinearSystemLU **psys);

#ifdef HXT_HAVE_PETSC
typedef struct HXTLinearSystemPETScStruct HXTLinearSystemPETSc;
HXTStatus hxtLinearSystemCreatePETSc(HXTLinearSystem **sys, int nElement, int nNodesByElement, int nFields, uint32_t *elements, const char *petscOptions);
HXTStatus hxtLinearSystemGetLinearSystemPETSc(HXTLinearSystem *sys, HXTLinearSystemPETSc **psys);
#endif

HXTStatus hxtInitializeLinearSystems(int *argc, char ***argv);

#endif
