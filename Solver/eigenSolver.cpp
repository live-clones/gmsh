// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include "eigenSolver.h"
#include "OS.h"

#if defined(HAVE_SLEPC)

#include <slepceps.h>
#if SLEPC_VERSION_RELEASE != 0 && (SLEPC_VERSION_MAJOR < 3  || (SLEPC_VERSION_MAJOR == 3 && SLEPC_VERSION_MINOR < 2))
#define EPSDestroy(e) EPSDestroy(*(e))
#endif

void eigenSolver::_try(int ierr) const
{
  CHKERRABORT(PETSC_COMM_WORLD, ierr);
}

eigenSolver::eigenSolver(dofManager<double> *manager, std::string A, std::string B,
                         bool hermitian)
  : _A(0), _B(0), _hermitian(hermitian)
{
  if (A.size()) {
    _A = dynamic_cast<linearSystemPETSc<double>*>(manager->getLinearSystem(A));
    if(!_A) Msg::Error("Could not find PETSc system '%s'", A.c_str());
  }
  if (B.size()) {
    _B = dynamic_cast<linearSystemPETSc<double>*>(manager->getLinearSystem(B));
    if(!_B) Msg::Error("Could not find PETSc system '%s'", B.c_str());
  }
}

eigenSolver::eigenSolver(linearSystemPETSc<double> *A, linearSystemPETSc<double> *B,
  bool hermitian) : _A(A), _B(B), _hermitian(hermitian) {}

bool eigenSolver::solve(int numEigenValues, std::string which, std::string method,
                        double tolVal, int iterMax)
{
  if(!_A) return false;
  Mat A = _A->getMatrix();
  Mat B = _B ? _B->getMatrix() : PETSC_NULL;

  PetscInt N, M;
  _try(MatAssemblyBegin(A, MAT_FINAL_ASSEMBLY));
  _try(MatAssemblyEnd(A, MAT_FINAL_ASSEMBLY));
  _try(MatGetSize(A, &N, &M));

  PetscInt N2, M2;
  if (_B) {
    _try(MatAssemblyBegin(B, MAT_FINAL_ASSEMBLY));
    _try(MatAssemblyEnd(B, MAT_FINAL_ASSEMBLY));
    _try(MatGetSize(B, &N2, &M2));
  }

  // generalized eigenvalue problem A x - \lambda B x = 0
  EPS eps;
  _try(EPSCreate(PETSC_COMM_WORLD, &eps));
  _try(EPSSetOperators(eps, A, B));
  if(_hermitian)
    _try(EPSSetProblemType(eps, _B ? EPS_GHEP : EPS_HEP));
  else
    _try(EPSSetProblemType(eps, _B ? EPS_GNHEP : EPS_NHEP));

  // set some default options
  _try(EPSSetDimensions(eps, numEigenValues, PETSC_DECIDE, PETSC_DECIDE));
  _try(EPSSetTolerances(eps, tolVal, iterMax));
  if (method=="krylovschur")
    _try(EPSSetType(eps, EPSKRYLOVSCHUR));
  else if (method=="arnoldi")
    _try(EPSSetType(eps, EPSARNOLDI));
  else if (method=="arpack")
    _try(EPSSetType(eps, EPSARPACK));
  else if (method=="power")
    _try(EPSSetType(eps, EPSPOWER));
  else
    Msg::Fatal("eigenSolver: method '%s' not available", method.c_str());

  // override these options at runtime, petsc-style
  _try(EPSSetFromOptions(eps));

  // force options specified directly as arguments
  if (numEigenValues)
    _try(EPSSetDimensions(eps, numEigenValues, PETSC_DECIDE, PETSC_DECIDE));
  if (which=="smallest")
    _try(EPSSetWhichEigenpairs(eps, EPS_SMALLEST_MAGNITUDE));
  else if (which=="smallestReal")
    _try(EPSSetWhichEigenpairs(eps, EPS_SMALLEST_REAL));
  else if (which=="largest")
    _try(EPSSetWhichEigenpairs(eps, EPS_LARGEST_MAGNITUDE));

  // print info
#if (SLEPC_VERSION_RELEASE == 0 || (SLEPC_VERSION_MAJOR > 3 || (SLEPC_VERSION_MAJOR == 3 && SLEPC_VERSION_MINOR >= 4)))
  EPSType type;
#else
  const EPSType type;
#endif
  _try(EPSGetType(eps, &type));
  Msg::Debug("SLEPc solution method: %s", type);

  PetscInt nev;
  _try(EPSGetDimensions(eps, &nev, PETSC_NULL, PETSC_NULL));
  Msg::Debug("SLEPc number of requested eigenvalues: %d", nev);
  PetscReal tol;
  PetscInt maxit;
  _try(EPSGetTolerances(eps, &tol, &maxit));
  Msg::Debug("SLEPc stopping condition: tol=%g, maxit=%d", tol, maxit);

  // solve
  Msg::Info("SLEPc solving...");
  double t1 = Cpu();
  _try(EPSSolve(eps));

  // check convergence
  int its;
  _try(EPSGetIterationNumber(eps, &its));
  EPSConvergedReason reason;
  _try(EPSGetConvergedReason(eps, &reason));
  if (reason==EPS_CONVERGED_TOL) {
    double t2=Cpu();
    Msg::Debug("SLEPc converged in %d iterations (%g s)", its, t2-t1);
  }
  else if (reason==EPS_DIVERGED_ITS)
    Msg::Error("SLEPc diverged after %d iterations", its);
  else if (reason==EPS_DIVERGED_BREAKDOWN)
    Msg::Error("SLEPc generic breakdown in method");
#if (SLEPC_VERSION_MAJOR < 3 || (SLEPC_VERSION_MAJOR == 3 && SLEPC_VERSION_MINOR < 2))
  else if (reason==EPS_DIVERGED_NONSYMMETRIC)
    Msg::Error("The operator is nonsymmetric");
#endif

  // get number of converged approximate eigenpairs
  PetscInt nconv;
  _try(EPSGetConverged(eps, &nconv));
  Msg::Debug("SLEPc number of converged eigenpairs: %d", nconv);

  // ignore additional eigenvalues if we get more than what we asked
  if (nconv>nev) nconv = nev;

  if (nconv>0) {
    Vec xr, xi;
#if (PETSC_VERSION_MAJOR == 3) && (PETSC_VERSION_MINOR < 6)
    _try(MatGetVecs(A, PETSC_NULL, &xr));
    _try(MatGetVecs(A, PETSC_NULL, &xi));
#else
  _try(MatCreateVecs(A, PETSC_NULL, &xr));
  _try(MatCreateVecs(A, PETSC_NULL, &xi));
#endif
    Msg::Debug("         Re[EigenValue]          Im[EigenValue]"
         "          Relative error");
    for (int i=0; i<nconv; i++) {
      PetscScalar kr, ki;
      _try(EPSGetEigenpair(eps, i, &kr, &ki, xr, xi));
      PetscReal error;
#if (PETSC_VERSION_MAJOR == 3) && (PETSC_VERSION_MINOR < 6)
      _try(EPSComputeRelativeError(eps, i, &error));
#else
      _try(EPSComputeError(eps, i, EPS_ERROR_RELATIVE, &error));
#endif
#if defined(PETSC_USE_COMPLEX)
      PetscReal re = PetscRealPart(kr);
      PetscReal im = PetscImaginaryPart(kr);
#else
      PetscReal re = kr;
      PetscReal im = ki;
#endif
      Msg::Debug("EIG %03d %s%.16e %s%.16e  %3.6e",
        i, (re<0) ? "" : " ", re, (im<0) ? "" : " ", im, error);

      // store eigenvalues and eigenvectors
      _eigenValues.push_back(std::complex<double>(re, im));
      PetscScalar *tmpr, *tmpi;
      _try(VecGetArray(xr, &tmpr));
      _try(VecGetArray(xi, &tmpi));
      std::vector<std::complex<double> > ev(N);
      for (int i=0; i<N; i++) {
#if defined(PETSC_USE_COMPLEX)
        ev[i] = tmpr[i];
#else
        ev[i] = std::complex<double>(tmpr[i], tmpi[i]);
#endif
      }
      _eigenVectors.push_back(ev);
    }
    _try(VecDestroy(&xr));
    _try(VecDestroy(&xi));
  }

  _try(EPSDestroy(&eps));

  if (reason==EPS_CONVERGED_TOL) {
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
  for (unsigned int imode=0; imode<modeView.size(); imode++) {
    int i = modeView[imode];
    double norm = 0.;
    for (unsigned int j=0; j<_eigenVectors[i].size(); j++) {
      std::complex<double> val = _eigenVectors[i][j];
      double normval = std::abs(val);
      if (normval>norm)
        norm = normval;
    }
    if (norm==0) {
      Msg::Error("zero eigenvector");
      return;
    }
    for (unsigned int j=0; j<_eigenVectors[i].size(); j++) {
      _eigenVectors[i][j] *= (scale/norm);
    }
  }
}

#endif
