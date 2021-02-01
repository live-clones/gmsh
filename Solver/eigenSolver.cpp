// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "eigenSolver.h"
#include "OS.h"

#if defined(HAVE_SLEPC)

#include <slepceps.h>
#if SLEPC_VERSION_RELEASE != 0 &&                                              \
  (SLEPC_VERSION_MAJOR < 3 ||                                                  \
   (SLEPC_VERSION_MAJOR == 3 && SLEPC_VERSION_MINOR < 2))
#define EPSDestroy(e) EPSDestroy(*(e))
#endif

void eigenSolver::_check(int ierr) const { CHKERRABORT(PETSC_COMM_WORLD, ierr); }

eigenSolver::eigenSolver(dofManager<double> *manager, std::string A,
                         std::string B, bool hermitian)
  : _sysA(0), _sysB(0), _hermitian(hermitian)
{
  if(A.size()) {
    _sysA = dynamic_cast<linearSystemPETSc<double> *>(manager->getLinearSystem(A));
    if(!_sysA) Msg::Error("Could not find PETSc system '%s'", A.c_str());
  }
  if(B.size()) {
    _sysB = dynamic_cast<linearSystemPETSc<double> *>(manager->getLinearSystem(B));
    if(!_sysB) Msg::Error("Could not find PETSc system '%s'", B.c_str());
  }
}

eigenSolver::eigenSolver(linearSystemPETSc<double> *A,
                         linearSystemPETSc<double> *B, bool hermitian)
  : _sysA(A), _sysB(B), _hermitian(hermitian)
{
}

bool eigenSolver::solve(int numEigenValues, std::string which,
                        std::string method, double tolVal, int iterMax)
{
  if(!_sysA) return false;
  Mat A = _sysA->getMatrix();
  Mat B = _sysB ? _sysB->getMatrix() : PETSC_NULL;

  PetscInt N, M;
  _check(MatAssemblyBegin(A, MAT_FINAL_ASSEMBLY));
  _check(MatAssemblyEnd(A, MAT_FINAL_ASSEMBLY));
  _check(MatGetSize(A, &N, &M));

  PetscInt N2, M2;
  if(_sysB) {
    _check(MatAssemblyBegin(B, MAT_FINAL_ASSEMBLY));
    _check(MatAssemblyEnd(B, MAT_FINAL_ASSEMBLY));
    _check(MatGetSize(B, &N2, &M2));
  }

  // generalized eigenvalue problem A x - \lambda B x = 0
  EPS eps;
  _check(EPSCreate(PETSC_COMM_WORLD, &eps));
  _check(EPSSetOperators(eps, A, B));
  if(_hermitian)
    _check(EPSSetProblemType(eps, _sysB ? EPS_GHEP : EPS_HEP));
  else
    _check(EPSSetProblemType(eps, _sysB ? EPS_GNHEP : EPS_NHEP));

  // set some default options
  _check(EPSSetDimensions(eps, numEigenValues, PETSC_DECIDE, PETSC_DECIDE));
  _check(EPSSetTolerances(eps, tolVal, iterMax));
  if(method == "krylovschur")
    _check(EPSSetType(eps, EPSKRYLOVSCHUR));
  else if(method == "arnoldi")
    _check(EPSSetType(eps, EPSARNOLDI));
  else if(method == "arpack")
    _check(EPSSetType(eps, EPSARPACK));
  else if(method == "power")
    _check(EPSSetType(eps, EPSPOWER));
  else{
    Msg::Error("eigenSolver: method '%s' not available", method.c_str());
    _check(EPSSetType(eps, EPSKRYLOVSCHUR));
  }

  // override these options at runtime, petsc-style
  _check(EPSSetFromOptions(eps));

  // force options specified directly as arguments
  if(numEigenValues)
    _check(EPSSetDimensions(eps, numEigenValues, PETSC_DECIDE, PETSC_DECIDE));
  if(which == "smallest")
    _check(EPSSetWhichEigenpairs(eps, EPS_SMALLEST_MAGNITUDE));
  else if(which == "smallestReal")
    _check(EPSSetWhichEigenpairs(eps, EPS_SMALLEST_REAL));
  else if(which == "largest")
    _check(EPSSetWhichEigenpairs(eps, EPS_LARGEST_MAGNITUDE));

    // print info
#if(SLEPC_VERSION_RELEASE == 0 ||                                              \
    (SLEPC_VERSION_MAJOR > 3 ||                                                \
     (SLEPC_VERSION_MAJOR == 3 && SLEPC_VERSION_MINOR >= 4)))
  EPSType type;
#else
  const EPSType type;
#endif
  _check(EPSGetType(eps, &type));
  Msg::Debug("SLEPc solution method: %s", type);

  PetscInt nev;
  _check(EPSGetDimensions(eps, &nev, PETSC_NULL, PETSC_NULL));
  Msg::Debug("SLEPc number of requested eigenvalues: %d", nev);
  PetscReal tol;
  PetscInt maxit;
  _check(EPSGetTolerances(eps, &tol, &maxit));
  Msg::Debug("SLEPc stopping condition: tol=%g, maxit=%d", tol, maxit);

  // solve
  Msg::Info("SLEPc solving...");
  double t1 = Cpu(), w1 = TimeOfDay();
  _check(EPSSolve(eps));

  // check convergence
  int its;
  _check(EPSGetIterationNumber(eps, &its));
  EPSConvergedReason reason;
  _check(EPSGetConvergedReason(eps, &reason));
  if(reason == EPS_CONVERGED_TOL) {
    double t2 = Cpu(), w2 = TimeOfDay();
    Msg::Debug("SLEPc converged in %d iterations (Wall %gs, CPU %gs)", its,
               w2 - w1, t2 - t1);
  }
  else if(reason == EPS_DIVERGED_ITS)
    Msg::Error("SLEPc diverged after %d iterations", its);
  else if(reason == EPS_DIVERGED_BREAKDOWN)
    Msg::Error("SLEPc generic breakdown in method");
#if(SLEPC_VERSION_MAJOR < 3 ||                                                 \
    (SLEPC_VERSION_MAJOR == 3 && SLEPC_VERSION_MINOR < 2))
  else if(reason == EPS_DIVERGED_NONSYMMETRIC)
    Msg::Error("The operator is nonsymmetric");
#endif

  // get number of converged approximate eigenpairs
  PetscInt nconv;
  _check(EPSGetConverged(eps, &nconv));
  Msg::Debug("SLEPc number of converged eigenpairs: %d", nconv);

  // ignore additional eigenvalues if we get more than what we asked
  if(nconv > nev) nconv = nev;

  if(nconv > 0) {
    Vec xr, xi;
#if(PETSC_VERSION_MAJOR == 3) && (PETSC_VERSION_MINOR < 6)
    _check(MatGetVecs(A, PETSC_NULL, &xr));
    _check(MatGetVecs(A, PETSC_NULL, &xi));
#else
    _check(MatCreateVecs(A, PETSC_NULL, &xr));
    _check(MatCreateVecs(A, PETSC_NULL, &xi));
#endif
    Msg::Debug("         Re[EigenValue]          Im[EigenValue]"
               "          Relative error");
    for(int i = 0; i < nconv; i++) {
      PetscScalar kr, ki;
      _check(EPSGetEigenpair(eps, i, &kr, &ki, xr, xi));
      PetscReal error;
#if(PETSC_VERSION_MAJOR == 3) && (PETSC_VERSION_MINOR < 6)
      _check(EPSComputeRelativeError(eps, i, &error));
#else
      _check(EPSComputeError(eps, i, EPS_ERROR_RELATIVE, &error));
#endif
#if defined(PETSC_USE_COMPLEX)
      PetscReal re = PetscRealPart(kr);
      PetscReal im = PetscImaginaryPart(kr);
#else
      PetscReal re = kr;
      PetscReal im = ki;
#endif
      Msg::Debug("EIG %03d %s%.16e %s%.16e  %3.6e", i, (re < 0) ? "" : " ", re,
                 (im < 0) ? "" : " ", im, error);

      // store eigenvalues and eigenvectors
      _eigenValues.push_back(std::complex<double>(re, im));
      PetscScalar *tmpr, *tmpi;
      _check(VecGetArray(xr, &tmpr));
      _check(VecGetArray(xi, &tmpi));
      std::vector<std::complex<double> > ev(N);
      for(int i = 0; i < N; i++) {
#if defined(PETSC_USE_COMPLEX)
        ev[i] = tmpr[i];
#else
        ev[i] = std::complex<double>(tmpr[i], tmpi[i]);
#endif
      }
      _eigenVectors.push_back(ev);
    }
    _check(VecDestroy(&xr));
    _check(VecDestroy(&xi));
  }

  _check(EPSDestroy(&eps));

  if(reason == EPS_CONVERGED_TOL) {
    Msg::Debug("SLEPc done");
    return true;
  }
  else {
    Msg::Warning("SLEPc failed");
    return false;
  }
}

void eigenSolver::normalize_mode(std::vector<int> modeView, double scale)
{
  Msg::Info("Normalize all eigenvectors");
  for(std::size_t imode = 0; imode < modeView.size(); imode++) {
    int i = modeView[imode];
    double norm = 0.;
    for(std::size_t j = 0; j < _eigenVectors[i].size(); j++) {
      std::complex<double> val = _eigenVectors[i][j];
      double normval = std::abs(val);
      if(normval > norm) norm = normval;
    }
    if(norm == 0) {
      Msg::Error("zero eigenvector");
      return;
    }
    for(std::size_t j = 0; j < _eigenVectors[i].size(); j++) {
      _eigenVectors[i][j] *= (scale / norm);
    }
  }
}

#endif
