#include "hxt_linear_system.h"
#include "hxt_tools.h"
#include "hxt_class_macro.h"

#define HXTLinearSystem_MEMBERS(operation, opdata) \
  operation(opdata,AddToMatrix,int,int,const double*,);\
  operation(opdata,AddMatrixEntry,int,int,int,int, double,);\
  operation(opdata,AddToRhs,double*,int,const double*,);\
  operation(opdata,ZeroMatrix,);\
  operation(opdata,Size,int*,);\
  operation(opdata,Solve,double*,double*,);\
  operation(opdata,SetMatrixRowIdentity,int,int,);\
  operation(opdata,SetMatrixRowFieldCombinaison,int,int,double*,);\
  operation(opdata,SetRhsEntry,double*,int,int,double,);\
  operation(opdata,AddRhsEntry,double*,int,int,double,);\
  operation(opdata,HasConverged,int*,);\
  operation(opdata,GetRhsNorm,double*,double*,);

HXT_DECLARE_INTERFACE(LinearSystem)

#include "hxt_linear_system_lu.h"
HXT_DECLARE_DERIVED_CLASS(LinearSystem, LinearSystemLU)

#ifdef HXT_HAVE_PETSC
#include "hxt_linear_system_petsc.h"
HXT_DECLARE_DERIVED_CLASS(LinearSystem, LinearSystemPETSc)
#endif

HXTStatus hxtInitializeLinearSystems(int *argc, char ***argv) {
#ifndef HXT_HAVE_PETSC
  HXT_UNUSED(argc);
  HXT_UNUSED(argv);
#endif

  HXT_CHECK(hxtLinearSystemLURegister());
#ifdef HXT_HAVE_PETSC
  HXT_CHECK(hxtInitializePETSc(argc, argv));
  HXT_CHECK(hxtLinearSystemPETScRegister());
#endif
  return HXT_STATUS_OK;
}

HXTStatus hxtLinearSystemCreateLU(HXTLinearSystem **sys, int nElement, int nNodesByElement, int nFields, uint32_t *elements) {
  if(hxtLinearSystemLUClass==NULL)
    HXT_ERROR_MSG(HXT_STATUS_FAILED,"linear system lu class not registred");
  HXTLinearSystemLU *syslu;
  HXT_CHECK(hxtLinearSystemLUCreate(&syslu, nElement, nNodesByElement, nFields, elements));
  HXT_CHECK(hxtLinearSystemCreate(sys, hxtLinearSystemLUClass, syslu));
  return HXT_STATUS_OK;
};

#ifdef HXT_HAVE_PETSC
HXTStatus hxtLinearSystemCreatePETSc(HXTLinearSystem **sys, int nElement, int nNodesByElement, int nFields, uint32_t *elements, const char *petscOptions) {
  if(hxtLinearSystemPETScClass==NULL)
    HXT_ERROR_MSG(HXT_STATUS_FAILED,"linear system petsc class not registred");
  HXTLinearSystemPETSc *syspetsc;
  HXT_CHECK(hxtLinearSystemPETScCreate(&syspetsc, nElement, nNodesByElement, nFields, elements, petscOptions));
  HXT_CHECK(hxtLinearSystemCreate(sys, hxtLinearSystemPETScClass, syspetsc));
  return HXT_STATUS_OK;
};

#endif


