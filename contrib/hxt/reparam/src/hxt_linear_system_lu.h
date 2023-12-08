#ifndef HEXTREME_LINEAR_SYSTEM_LU_H
#define HEXTREME_LINEAR_SYSTEM_LU_H

#include "hxt_message.h"
#include <stdint.h>

#ifndef HEXTREME_LINEAR_SYSTEM_H // to avoid illegal (in C) redefinition of typedef
typedef struct HXTLinearSystemLUStruct HXTLinearSystemLU;
#endif

HXTStatus hxtLinearSystemLUAddToMatrix(HXTLinearSystemLU *lsys, int el0, int el1, const double *localMatrix);
HXTStatus hxtLinearSystemLUAddMatrixEntry(HXTLinearSystemLU *lsys, int node0, int field0, int node1, int field1, double entry);
HXTStatus hxtLinearSystemLUAddToRhs(HXTLinearSystemLU *lsys, double *rhs, int el0, const double *localVector);
HXTStatus hxtLinearSystemLUZeroMatrix(HXTLinearSystemLU *lsys);
HXTStatus hxtLinearSystemLUSolve(HXTLinearSystemLU *lsys, double *rhs, double *solution);
HXTStatus hxtLinearSystemLUSetMatrixRowIdentity(HXTLinearSystemLU *lsys, int node, int field);
HXTStatus hxtLinearSystemLUSetMatrixRowFieldCombinaison(HXTLinearSystemLU *system, int node, int field, double *coeff);
HXTStatus hxtLinearSystemLUSetRhsEntry(HXTLinearSystemLU *lsys, double *rhs, int node, int field, double v);
HXTStatus hxtLinearSystemLUAddRhsEntry(HXTLinearSystemLU *lsys, double *rhs, int node, int field, double v);
HXTStatus hxtLinearSystemLUDelete(HXTLinearSystemLU **pSystem);
HXTStatus hxtLinearSystemLUHasConverged(HXTLinearSystemLU *lsys, int *converged); 
HXTStatus hxtLinearSystemLUGetRhsNorm(HXTLinearSystemLU *lsys, double *rhs, double *norm);
HXTStatus hxtLinearSystemLUCreate(HXTLinearSystemLU **pSystem, int nElements, int nNodesByElement, int nFields, uint32_t *elements);
HXTStatus hxtLinearSystemLUSize(HXTLinearSystemLU *lsys, int *size);

#endif
