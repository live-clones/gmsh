#include "hxt_non_linear_solver.h"
#include "hxt_tools.h"

HXTStatus hxtNewtonRaphson(HXTLinearSystem *nrSys, double *solution, int size, int maxiter, double tol, HXTNonLinearSolverCallbackF *fcb, HXTNonLinearSolverCallbackDF *dfcb, void *data) {
  double *delta, *rhs;
  HXT_CHECK(hxtAlignedMalloc(&delta,size*sizeof(double)));
  HXT_CHECK(hxtAlignedMalloc(&rhs,size*sizeof(double))); 
  for(int n=0; n<maxiter; n++){
    HXT_CHECK(hxtLinearSystemZeroMatrix(nrSys));
    HXT_CHECK(fcb(data,solution,nrSys,rhs));
    HXT_CHECK(dfcb(data,solution,nrSys));
    HXT_CHECK(hxtLinearSystemSolve(nrSys,rhs,delta));
    double nrNorm = 0.;
    for(int ie=0; ie< size; ie++){
      solution[ie] -= delta[ie];
      nrNorm += delta[ie]*delta[ie];
    }
    nrNorm = sqrt(nrNorm);
    HXT_INFO("__NR iter %i norm %g\n",n,nrNorm);
    if(nrNorm<tol)
      break;
  }
  HXT_CHECK(hxtAlignedFree(&delta));
  HXT_CHECK(hxtAlignedFree(&rhs));
  return HXT_STATUS_OK;
}

#ifdef HXT_HAVE_PETSC

#include "hxt_linear_system_petsc.h"
#include <petscsnes.h>

#define HXT_PETSC_CHECK(status) HXT_CHECK_MSG(status == 0 ? HXT_STATUS_OK : HXT_STATUS_FAILED, "PETSc error")

typedef struct {
  void *data;
  HXTNonLinearSolverCallbackF *f;
  HXTNonLinearSolverCallbackDF *df;
  HXTLinearSystem *sys;
  double *solution;
} SNESData;

PetscErrorCode petsc_f_cb(SNES snes, Vec x, Vec f, void *ctx) {
  SNESData *data = (SNESData*) ctx;
  double *fd;
  HXTLinearSystemPETSc* petscsys;
  HXT_CHECK(hxtLinearSystemGetLinearSystemPETSc(data->sys, &petscsys));
  HXT_CHECK(hxtLinearSystemPETScMapFromVec(petscsys,x,data->solution));
  HXT_PETSC_CHECK(VecGetArray(f, &fd));
  HXT_CHECK(data->f(data->data, data->solution, data->sys, fd));
  HXT_PETSC_CHECK(VecRestoreArray(f, &fd));
  return HXT_STATUS_OK;
}

PetscErrorCode petsc_df_cb(SNES snes, Vec x, Mat a, Mat b, void *ctx) {
  SNESData *data = (SNESData*) ctx;
  HXTLinearSystemPETSc* petscsys;
  HXT_CHECK(hxtLinearSystemGetLinearSystemPETSc(data->sys, &petscsys));
  HXT_CHECK(hxtLinearSystemPETScMapFromVec(petscsys,x,data->solution));
  HXT_CHECK(hxtLinearSystemZeroMatrix(data->sys));
  HXT_CHECK(data->df(data->data, data->solution, data->sys));
  HXT_PETSC_CHECK(MatAssemblyBegin(a, MAT_FINAL_ASSEMBLY));
  HXT_PETSC_CHECK(MatAssemblyEnd(a, MAT_FINAL_ASSEMBLY));
  return HXT_STATUS_OK;
}

HXTStatus hxtNonLinearSolverPETSc(HXTLinearSystem *sys, double *solution, HXTNonLinearSolverCallbackF *fcb, HXTNonLinearSolverCallbackDF *dfcb, void *data, const char *petscOptions) {
  int size;
  HXT_CHECK(hxtLinearSystemSize(sys, &size));
  HXTLinearSystemPETSc* petscsys;
  HXT_CHECK(hxtLinearSystemGetLinearSystemPETSc(sys, &petscsys));
  if (petscsys == NULL)
    return HXT_ERROR_MSG(HXT_STATUS_FAILED, "A PETSc linear system is required.");
  SNESData snes_data = {data, fcb, dfcb, sys, solution};
  Mat a;
  HXT_CHECK(hxtLinearSystemPETScGetMat(petscsys, &a));
  SNES snes;
  HXT_PETSC_CHECK(SNESCreate(MPI_COMM_WORLD, &snes));
  static int prefixid = 0;
  char prefix[256];
  sprintf(prefix, "hxtsnes%i", prefixid++);
  #if PETSC_VERSION_MINOR < 7
  HXT_PETSC_CHECK(PetscOptionsPrefixPush(prefix));
  HXT_PETSC_CHECK(PetscOptionsInsertString(petscOptions));
  HXT_PETSC_CHECK(PetscOptionsPrefixPop());
  #else
  HXT_PETSC_CHECK(PetscOptionsPrefixPush(NULL, prefix));
  HXT_PETSC_CHECK(PetscOptionsInsertString(NULL, petscOptions));
  HXT_PETSC_CHECK(PetscOptionsPrefixPop(NULL));
  #endif
  HXT_PETSC_CHECK(SNESSetOptionsPrefix(snes, prefix));
  HXT_PETSC_CHECK(SNESSetFromOptions(snes));
  Vec f, b, x;
  HXT_PETSC_CHECK(VecCreate(MPI_COMM_WORLD, &f));
  HXT_PETSC_CHECK(VecSetSizes(f, size, PETSC_DETERMINE));
  HXT_PETSC_CHECK(VecSetOptionsPrefix(f, prefix));
  HXT_PETSC_CHECK(VecSetFromOptions(f));
  HXT_PETSC_CHECK(VecCreate(MPI_COMM_WORLD, &b));
  HXT_PETSC_CHECK(VecSetSizes(b, size, PETSC_DETERMINE));
  HXT_PETSC_CHECK(VecSetOptionsPrefix(b, prefix));
  HXT_PETSC_CHECK(VecSetFromOptions(b));
  HXT_PETSC_CHECK(VecCreate(MPI_COMM_WORLD, &x));
  HXT_PETSC_CHECK(VecSetSizes(x, size, PETSC_DETERMINE));
  HXT_PETSC_CHECK(VecSetOptionsPrefix(x, prefix));
  HXT_PETSC_CHECK(VecSetFromOptions(x));
  HXT_PETSC_CHECK(VecSet(b, 0.));
  HXT_CHECK(hxtLinearSystemPETScMapToVec(petscsys, solution, x));
  HXT_PETSC_CHECK(SNESSetFunction(snes, f, petsc_f_cb, &snes_data));
  HXT_PETSC_CHECK(SNESSetJacobian(snes, a, a, petsc_df_cb, &snes_data));
  HXT_PETSC_CHECK(SNESSolve(snes, b, x));
  SNESConvergedReason reason;
  HXT_PETSC_CHECK(SNESGetConvergedReason(snes, &reason));
  if (reason < 0)
    HXT_WARNING("non linear solver diverged : %i", reason);
  HXT_CHECK(hxtLinearSystemPETScMapFromVec(petscsys, x, solution));
  HXT_PETSC_CHECK(SNESDestroy(&snes));
  HXT_PETSC_CHECK(VecDestroy(&x));
  HXT_PETSC_CHECK(VecDestroy(&b));
  HXT_PETSC_CHECK(VecDestroy(&f));
  return HXT_STATUS_OK;
}

#include <petsctao.h>
typedef struct {
  void *data;
  HXTOptimizationTaoCallbackF *f;
  HXTOptimizationTaoCallbackG *g;
  HXTOptimizationTaoCallbackH *h;
  HXTLinearSystem *sys;
  double *solution;
} TaoData;

PetscErrorCode petsc_tao_fg_cb(Tao tao, Vec x, double *f, Vec g, void *ctx) {
  TaoData *data = (TaoData*) ctx;
  double *gd;
  HXTLinearSystemPETSc* petscsys;
  HXT_CHECK(hxtLinearSystemGetLinearSystemPETSc(data->sys, &petscsys));
  HXT_CHECK(hxtLinearSystemPETScMapFromVec(petscsys,x,data->solution));
  HXT_PETSC_CHECK(VecGetArray(g, &gd));
  HXT_CHECK(data->f(data->data, data->solution, f));
  HXT_CHECK(data->g(data->data, data->solution, data->sys, gd));
  HXT_PETSC_CHECK(VecRestoreArray(g, &gd));
  return HXT_STATUS_OK;
}

PetscErrorCode petsc_tao_h_cb(Tao tao, Vec x, Mat a, Mat b, void *ctx) {
  TaoData *data = (TaoData*) ctx;
  HXTLinearSystemPETSc* petscsys;
  HXT_CHECK(hxtLinearSystemGetLinearSystemPETSc(data->sys, &petscsys));
  HXT_CHECK(hxtLinearSystemPETScMapFromVec(petscsys,x,data->solution));
  HXT_CHECK(hxtLinearSystemZeroMatrix(data->sys));
  HXT_CHECK(data->h(data->data, data->solution, data->sys));
  HXT_PETSC_CHECK(MatAssemblyBegin(a, MAT_FINAL_ASSEMBLY));
  HXT_PETSC_CHECK(MatAssemblyEnd(a, MAT_FINAL_ASSEMBLY));
  return HXT_STATUS_OK;
}

HXTStatus hxtOptimizationTao(HXTLinearSystem *sys, double *solution, HXTOptimizationTaoCallbackF *fcb, HXTOptimizationTaoCallbackG *gcb, HXTOptimizationTaoCallbackH *hcb, void *data, const char *petscOptions) {
  int size;
  HXT_CHECK(hxtLinearSystemSize(sys, &size));
  HXTLinearSystemPETSc* petscsys;
  HXT_CHECK(hxtLinearSystemGetLinearSystemPETSc(sys, &petscsys));
  if (petscsys == NULL)
    return HXT_ERROR_MSG(HXT_STATUS_FAILED, "A PETSc linear system is required.");
  TaoData tao_data = {data, fcb, gcb, hcb, sys, solution};
  Mat a;
  HXT_CHECK(hxtLinearSystemPETScGetMat(petscsys, &a));
  Tao tao;
  HXT_PETSC_CHECK(TaoCreate(MPI_COMM_WORLD, &tao));
  static int prefixid = 0;
  char prefix[256];
  sprintf(prefix, "hxttao%i", prefixid++);
  #if PETSC_VERSION_MINOR < 7
  HXT_PETSC_CHECK(PetscOptionsPrefixPush(prefix));
  HXT_PETSC_CHECK(PetscOptionsInsertString(petscOptions));
  HXT_PETSC_CHECK(PetscOptionsPrefixPop());
  #else
  HXT_PETSC_CHECK(PetscOptionsPrefixPush(NULL, prefix));
  HXT_PETSC_CHECK(PetscOptionsInsertString(NULL, petscOptions));
  HXT_PETSC_CHECK(PetscOptionsPrefixPop(NULL));
  #endif
  HXT_PETSC_CHECK(TaoSetOptionsPrefix(tao, prefix));
  HXT_PETSC_CHECK(TaoSetFromOptions(tao));
  Vec x;
  HXT_PETSC_CHECK(VecCreate(MPI_COMM_WORLD, &x));
  HXT_PETSC_CHECK(VecSetSizes(x, size, PETSC_DETERMINE));
  HXT_PETSC_CHECK(VecSetOptionsPrefix(x, prefix));
  HXT_PETSC_CHECK(VecSetFromOptions(x));
  Vec y;
  HXT_PETSC_CHECK(VecCreate(MPI_COMM_WORLD, &y));
  HXT_PETSC_CHECK(VecSetSizes(y, size/2, PETSC_DETERMINE));
  HXT_PETSC_CHECK(VecSetOptionsPrefix(y, prefix));
  HXT_PETSC_CHECK(VecSetFromOptions(y));


  HXT_CHECK(hxtLinearSystemPETScMapToVec(petscsys, solution, x));
  HXT_PETSC_CHECK(TaoSetInitialVector(tao, x));
  HXT_PETSC_CHECK(TaoSetObjectiveAndGradientRoutine(tao, petsc_tao_fg_cb, &tao_data));
  HXT_PETSC_CHECK(TaoSetHessianRoutine(tao, a, a, petsc_tao_h_cb, &tao_data));
  HXT_PETSC_CHECK(TaoSolve(tao));
  TaoConvergedReason reason;
  HXT_PETSC_CHECK(TaoGetConvergedReason(tao, &reason));
  if (reason < 0)
    HXT_WARNING("optimization solver diverged : %i", reason);
  HXT_CHECK(hxtLinearSystemPETScMapFromVec(petscsys, x, solution));
  HXT_PETSC_CHECK(TaoDestroy(&tao));
  HXT_PETSC_CHECK(VecDestroy(&x));
  return HXT_STATUS_OK;
}
#endif
