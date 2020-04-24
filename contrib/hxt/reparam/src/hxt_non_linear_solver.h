#ifndef HXT_NON_LINEAR_SOLVER_H
#define HXT_NON_LINEAR_SOLVER_H

#include "hxt_linear_system.h"

typedef HXTStatus HXTNonLinearSolverCallbackF(void *data, const double *solution, HXTLinearSystem *sys, double *f);
typedef HXTStatus HXTNonLinearSolverCallbackDF(void *data, const double *solution, HXTLinearSystem *sys);

HXTStatus hxtNewtonRaphson(HXTLinearSystem *nrSys, double *solution, int size, int maxiter, double tol, HXTNonLinearSolverCallbackF *fcb, HXTNonLinearSolverCallbackDF *dfcb, void *data);


#ifdef HXT_HAVE_PETSC
HXTStatus hxtNonLinearSolverPETSc(HXTLinearSystem *sys, double *solution, HXTNonLinearSolverCallbackF *f, HXTNonLinearSolverCallbackDF *df, void *data, const char *petscOptions);
typedef HXTStatus HXTOptimizationTaoCallbackF(void *data, const double *solution, double *f);
typedef HXTStatus HXTOptimizationTaoCallbackG(void *data, const double *solution, HXTLinearSystem *sys, double *f);
typedef HXTStatus HXTOptimizationTaoCallbackH(void *data, const double *solution, HXTLinearSystem *sys);
HXTStatus hxtOptimizationTao(HXTLinearSystem *sys, double *solution, HXTOptimizationTaoCallbackF *fcb, HXTOptimizationTaoCallbackG *gcb, HXTOptimizationTaoCallbackH *hcb, void *data, const char *petscOptions);
#endif

#endif
