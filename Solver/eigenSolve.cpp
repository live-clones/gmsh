// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "eigenSolve.h"

#if defined(HAVE_SLEPC)

#include <slepceps.h>

eigenSolve::eigenSolve(dofManager *manager, const char *A, const char *B)
{
  if(A){
    _A = manager->getLinearSystem(A);
    if(!_A) Msg::Error("Could not find system A");
  }
  if(B){
    _B = manager->getLinearSystem(B);
    if(!_B) Msg::Error("Could not find system B");
  }
}

void eigenSolve::solve()
{
  if(!_A) return;
  Mat A = _A->getMatrix();
  Mat B = _B ? _b->getMatrix() : PETSC_NULL;

  // treatment of a generalized eigenvalue problem A x - \lambda B x = 0
  EPS eps;
  _try(EPSCreate(PETSC_COMM_WORLD, &eps));
  _try(EPSSetOperators(eps, A, B));
  _try(EPSSetProblemType(eps, EPS_GNHEP));

  // set solver parameters at runtime
  _try(EPSSetFromOptions(eps));
 	
  Msg::Info("SLEPc solving...");
  _try(EPSSolve(eps));
  int its;
  _try(EPSGetIterationNumber(eps, &its));
  Msg::Info("Number of iterations of the method: %d", its);
  
  // get some information from the solver and display it
  EPSType type;
  _try(EPSGetType(eps, &type));
  Msg::Info("Solution method: %s", type);
  int nev;
  _try(EPSGetDimensions(eps, &nev, PETSC_NULL));
  Msg::Info("Number of requested eigenvalues: %d", nev);
  PetscReal tol;
  int maxit;
  _try(EPSGetTolerances(eps, &tol, &maxit));
  Msg::Info("Stopping condition: tol=%.4g, maxit=%d", tol, maxit);
   
  // get number of converged approximate eigenpairs
  int nconv;
  _try(EPSGetConverged(eps, &nconv));
  Msg::Info("Number of converged eigenpairs: %d", nconv);

  Msg::Info("Re[Eigenvalue] Im[Eigenvalue] Rel. error = ||Ax - eig*Bx||/||eig*x||");

  // if number of converged solutions is greated than requested
  // discarded surplus solutions
  if(nconv > nev) nconv = nev;
  // if number of converged solutions is less than requested display
  // only converged solutions
  if(nconv < nev) nev = nconv;

  Vec xr, xi;
  _try(MatGetVecs(A, PETSC_NULL, &xr));
  _try(MatGetVecs(A, PETSC_NULL, &xi));
  for (int i = nconv - 1; i > nconv - nev - 1; i--){
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
    // Output eigenvalues
    Msg::Info("EIG %03d  %s  %.16e  %s  %.16e  %3.6e", 
              (nconv-i), (re<0)? "" : " ", re, (im<0)? "" : " ", im,  error);

    // Output eigenvector
    PetscScalar *real_tmp, *imag_tmp;
    _try(VecGetArray(xr, &real_tmp));
    _try(VecGetArray(xi, &imag_tmp));
  }
  
  // Free work space
  _try(EPSDestroy(eps));
  _try(VecDestroy(xr));
  _try(VecDestroy(xi));
  _try(SlepcFinalize());
  Msg::Info("SLEPc done");
}

#endif
