// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "eigenSolver.h"

#if defined(HAVE_SLEPC)

#include <slepceps.h>

eigenSolver::eigenSolver(dofManager<double, double> *manager, std::string A, 
                         std::string B) : _A(0), _B(0)
{
  if(A.size()){
    _A = dynamic_cast<linearSystemPETSc<double>*>(manager->getLinearSystem(A));
    if(!_A) Msg::Error("Could not find PETSc system '%s'", A.c_str());
  }
  if(B.size()){
    _B = dynamic_cast<linearSystemPETSc<double>*>(manager->getLinearSystem(B));
    if(!_B) Msg::Error("Could not find PETSc system '%s'", B.c_str());
  }
}

void eigenSolver::solve()
{
  if(!_A) return;
  Mat A = _A->getMatrix();
  Mat B = _B ? _B->getMatrix() : PETSC_NULL;

  _try(MatAssemblyBegin(A, MAT_FINAL_ASSEMBLY));
  _try(MatAssemblyEnd(A, MAT_FINAL_ASSEMBLY));
  PetscInt N, M;
  _try(MatGetSize(A, &N, &M));

  // treatment of a generalized eigenvalue problem A x - \lambda B x = 0
  EPS eps;
  _try(EPSCreate(PETSC_COMM_WORLD, &eps));
  _try(EPSSetOperators(eps, A, B));
  // FIXME: check if hermitian (EPS_HEP or EPS_GHEP)
  //_try(EPSSetProblemType(eps, _B ? EPS_GNHEP : EPS_NHEP));
  _try(EPSSetProblemType(eps, _B ? EPS_GHEP : EPS_HEP));

  // set options
  //_try(EPSSetWhichEigenpairs(eps, EPS_LARGEST_MAGNITUDE));
  //_try(EPSSetWhichEigenpairs(eps, EPS_SMALLEST_REAL));
  _try(EPSSetTarget(eps, 0.)); // find eigenvalues close to given target
  PetscInt nev = 2; // number of eigenvalues to compute
  PetscInt mpd = nev; // max dim allowed for the projected problem
  PetscInt ncv = nev + mpd; // max dim of the subspace to be used by the solver
  _try(EPSSetDimensions(eps, nev, ncv, mpd));
  //_try(EPSSetType(eps, EPSPOWER));

  // override options at runtime, petsc-style
  _try(EPSSetFromOptions(eps));

  // print info
  const EPSType type;
  _try(EPSGetType(eps, &type));
  Msg::Info("SLEPc solution method: %s", type);
  _try(EPSGetDimensions(eps, &nev, &ncv, &mpd));
  Msg::Info("SLEPc number of requested eigenvalues: %d", nev);
  PetscReal tol;
  PetscInt maxit;
  _try(EPSGetTolerances(eps, &tol, &maxit));
  Msg::Info("SLEPc stopping condition: tol=%g, maxit=%d", tol, maxit);
 	
  Msg::Info("SLEPc solving...");
  _try(EPSSolve(eps));

  int its;
  _try(EPSGetIterationNumber(eps, &its));
  EPSConvergedReason reason;
  _try(EPSGetConvergedReason(eps, &reason));
  if(reason == EPS_CONVERGED_TOL)
    Msg::Info("SLEPc converged in %d iterations", its);
  else if(reason == EPS_DIVERGED_ITS)
    Msg::Error("SLEPc did not converge in %d iterations", its);
  else if(reason == EPS_DIVERGED_BREAKDOWN)
    Msg::Error("SLEPc generic breakdown in method");
  else if(reason == EPS_DIVERGED_NONSYMMETRIC)
    Msg::Error("The operator is nonsymmetric");
  
  // get number of converged approximate eigenpairs
  PetscInt nconv;
  _try(EPSGetConverged(eps, &nconv));
  Msg::Info("SLEPc number of converged eigenpairs: %d", nconv);

  // if number of converged solutions is greated than requested
  // discarded surplus solutions
  if(nconv > nev) nconv = nev;
  // if number of converged solutions is less than requested display
  // only converged solutions
  if(nconv < nev) nev = nconv;

  Vec xr, xi;
  _try(MatGetVecs(A, PETSC_NULL, &xr));
  _try(MatGetVecs(A, PETSC_NULL, &xi));
  Msg::Info("         Re[EigenValue]          Im[EigenValue]"
            "          Relative error");
  for (int i = nconv - 1; i > nconv - nev - 1; i--){
    std::vector<std::complex<double> > ev(N);
    PetscScalar kr, ki;
    _try(EPSGetEigenpair(eps, i, &kr, &ki, xr, xi));
    PetscReal error;
    _try(EPSComputeRelativeError(eps, i, &error));
#if defined(PETSC_USE_COMPLEX)
    PetscReal re = PetscRealPart(kr);
    PetscReal im = PetscImaginaryPart(kr);
#else
    PetscReal re = kr;
    PetscReal im = ki;
#endif
    // Output eigenvalues and relative error (= ||Ax - eig*Bx||/||eig*x||)
    Msg::Info("EIG %03d %s%.16e %s%.16e  %3.6e", (nconv - i), 
              (re < 0) ? "" : " ", re, (im < 0) ? "" : " ", im, error);
    _eigenValues.push_back(std::complex<double>(re, im));

    // Output eigenvector
    PetscScalar *tmpr, *tmpi;
    _try(VecGetArray(xr, &tmpr));
    _try(VecGetArray(xi, &tmpi));
    for(int i = 0; i < N; i++){
#if defined(PETSC_USE_COMPLEX)
      ev[i] = tmpr[i];
#else
      ev[i] = std::complex<double>(tmpr[i], tmpi[i]);
#endif
    }
    _eigenVectors.push_back(ev);
  }
  
  // Free work space
  _try(EPSDestroy(eps));
  _try(VecDestroy(xr));
  _try(VecDestroy(xi));
  _try(SlepcFinalize());
  Msg::Info("SLEPc done");
}

#endif
