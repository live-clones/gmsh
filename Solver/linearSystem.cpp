#include "GmshConfig.h"
#include "linearSystemFull.h"
#include "linearSystemCSR.h"
#include "linearSystemGMM.h"
#include "linearSystemPETSc.h"

#include "Bindings.h"

template<>
void linearSystem<double>::registerBindings(binding *b){
  classBinding *cb = b->addClass<linearSystem<double> >("linearSystem");
  cb->setDescription("An abstraction of a linear system Ax = b.");
  methodBinding *cm;
  cm = cb->addMethod("systemSolve", &linearSystem<double>::systemSolve);
  cm->setDescription("compute x = A^{-1}b");
  
#ifdef HAVE_TAUCS
  cb = b->addClass<linearSystemCSRTaucs<double> >("linearSystemCSRTaucs");
  cb->setDescription("A linear system solver, based on TAUCS, and that is ok for SDP sparse matrices.");
  cm = cb->setConstructor<linearSystemCSRTaucs<double> >();
  cm->setDescription ("A new TAUCS<double> solver");
  cm->setArgNames(NULL);
  cb->setParentClass<linearSystem<double> >();
#endif

#ifdef HAVE_PETSC
  cb = b->addClass<linearSystemPETSc<double> >("linearSystemPETSc");
  cb->setDescription("A linear system solver, based on PETSc");
  cm = cb->setConstructor<linearSystemPETSc<double> >();
  cm->setDescription ("A new PETSc<double> solver");
  cm->setArgNames(NULL);
  cb->setParentClass<linearSystem<double> >();
#endif

  cb = b->addClass<linearSystemFull<double> >("linearSystemFull");
  cb->setDescription("A linear system solver, based on LAPACK (full matrices)");
  cm = cb->setConstructor<linearSystemFull<double> >();
  cm->setDescription ("A new Lapack based <double> solver");
  cm->setArgNames(NULL);
  cb->setParentClass<linearSystem<double> >();
}
