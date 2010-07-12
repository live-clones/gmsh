// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _LINEAR_SYSTEM_PETSC_H_
#define _LINEAR_SYSTEM_PETSC_H_

// Interface to PETSc 3.x

// Options for PETSc can be provided on the command line, or in the
// file ~/.petscrc. By default, we use the following options (GMRES
// with ILU(6) preconditioner and RCMK renumbering):
//
//   -ksp_type gmres
//   -pc_type ilu
//   -pc_factor_levels 6
//   -pc_factor_mat_ordering rcm
//   -ksp_rtol 1.e-8
//
// Other useful options include:
//
//   -ksp_gmres_restart 100
//   -ksp_monitor
//
// To use a direct solver (a sparse lu) instead of an iterative
// solver, use
//
//   -ksp_type preonly
//   -pc_type lu
//
// When PETSc is compiled with external direct solvers (UMFPACK,
// SuperLU, etc.), they can be selected like this:
//
//   -pc_factor_mat_solver_package umfpack

#include "GmshConfig.h"
#include "GmshMessage.h"
#include "linearSystem.h"

#if defined(HAVE_PETSC)
#include <petsc.h>
#include <petscksp.h>

template <class scalar>
class linearSystemPETSc : public linearSystem<scalar> {
  int _blockSize; // for block Matrix
  bool _isAllocated, _kspAllocated;
  Mat _a;
  Vec _b, _x;
  KSP _ksp;
  void _try(int ierr) const { CHKERRABORT(PETSC_COMM_WORLD, ierr); }
  void _kspCreate() {
    _try(KSPCreate(PETSC_COMM_WORLD, &_ksp));
    PC pc;
    _try(KSPGetPC(_ksp, &pc));
    // set some default options
    _try(PCSetType(pc, PCILU));
    _try(PCFactorSetMatOrderingType(pc, MATORDERING_RCM));
    _try(PCFactorSetLevels(pc, 1));
    _try(KSPSetTolerances(_ksp, 1.e-8, PETSC_DEFAULT, PETSC_DEFAULT, PETSC_DEFAULT));
    // override the default options with the ones from the option
    // database (if any)
    _try(KSPSetFromOptions(_ksp));
    _kspAllocated = true;
  }
 public:
  linearSystemPETSc() : _isAllocated(false) {_blockSize = 0; _kspAllocated = false;}
  virtual ~linearSystemPETSc(){
    clear();
    if (_kspAllocated)
      _try (KSPDestroy (_ksp));
  }
  virtual bool isAllocated() const { return _isAllocated; }
  virtual void allocate(int nbRows)
  {
    clear();
    _try(MatCreate(PETSC_COMM_WORLD, &_a));
    _try(MatSetSizes(_a, PETSC_DECIDE, PETSC_DECIDE, nbRows, nbRows));
    // override the default options with the ones from the option
    // database (if any)
    _try(MatSetFromOptions(_a));
    // preallocation option must be set after other options
    PetscInt prealloc = 300;
    PetscTruth set;
    PetscOptionsGetInt(PETSC_NULL, "-petsc_prealloc", &prealloc, &set);
    _try(MatSeqAIJSetPreallocation(_a, prealloc, PETSC_NULL));
    _try(VecCreate(PETSC_COMM_WORLD, &_x));
    _try(VecSetSizes(_x, PETSC_DECIDE, nbRows));
    // override the default options with the ones from the option
    // database (if any)
    _try(VecSetFromOptions(_x));
    _try(VecDuplicate(_x, &_b));
    _isAllocated = true;
  }
  virtual void clear()
  {
    if(_isAllocated){
      _try(MatDestroy(_a));
      _try(VecDestroy(_x));
      _try(VecDestroy(_b));
    }
    _isAllocated = false;
  }
  virtual void getFromMatrix(int row, int col, scalar &val) const
  {
    Msg::Error("getFromMatrix not implemented for PETSc");
  }
  virtual void addToRightHandSide(int row, const scalar &val)
  {
    PetscInt i = row;
    PetscScalar s = val;
    _try(VecSetValues(_b, 1, &i, &s, ADD_VALUES));
  }
  virtual void getFromRightHandSide(int row, scalar &val) const
  {
    PetscScalar *tmp;
    _try(VecGetArray(_b, &tmp));
    PetscScalar s = tmp[row];
    _try(VecRestoreArray(_b, &tmp));
    // FIXME specialize this routine
#if defined(PETSC_USE_COMPLEX)
    val = s.real();
#else
    val = s;
#endif
  }
  virtual double normInfRightHandSide() const
  {
    PetscReal nor;
    _try(VecNorm(_b, NORM_INFINITY, &nor));
    return nor;
  }
  virtual void addToMatrix(int row, int col, const scalar &val)
  {
    PetscInt i = row, j = col;
    PetscScalar s = val;
    _try(MatSetValues(_a, 1, &i, 1, &j, &s, ADD_VALUES));
  }
  virtual void getFromSolution(int row, scalar &val) const
  {
    PetscScalar *tmp;
    _try(VecGetArray(_x, &tmp));
    PetscScalar s = tmp[row];
    _try(VecRestoreArray(_x, &tmp));
#if defined(PETSC_USE_COMPLEX)
    val = s.real();
#else
    val = s;
#endif
  }
  virtual void zeroMatrix()
  {
    if (_isAllocated) {
      _try(MatAssemblyBegin(_a, MAT_FINAL_ASSEMBLY));
      _try(MatAssemblyEnd(_a, MAT_FINAL_ASSEMBLY));
      _try(MatZeroEntries(_a));
    }
  }
  virtual void zeroRightHandSide()
  {
    if (_isAllocated) {
      _try(VecAssemblyBegin(_b));
      _try(VecAssemblyEnd(_b));
      _try(VecZeroEntries(_b));
    }
  }
  int systemSolve()
  {
    if (!_kspAllocated)
      _kspCreate();
    if (linearSystem<scalar>::_parameters["matrix_reuse"] == "same_sparsity")
      _try(KSPSetOperators(_ksp, _a, _a, SAME_NONZERO_PATTERN));
    else if (linearSystem<scalar>::_parameters["matrix_reuse"] == "same_matrix")
      _try(KSPSetOperators(_ksp, _a, _a, SAME_PRECONDITIONER));
    else
      _try(KSPSetOperators(_ksp, _a, _a, DIFFERENT_NONZERO_PATTERN));
    _try(MatAssemblyBegin(_a, MAT_FINAL_ASSEMBLY));
    _try(MatAssemblyEnd(_a, MAT_FINAL_ASSEMBLY));
    _try(VecAssemblyBegin(_b));
    _try(VecAssemblyEnd(_b));
    _try(KSPSolve(_ksp, _b, _x));
    //_try(KSPView(ksp, PETSC_VIEWER_STDOUT_SELF));
    //PetscInt its;
    //_try(KSPGetIterationNumber(ksp, &its));
    //Msg::Info("%d iterations", its);
    // add line to destroy unused data
    _try(KSPDestroy(_ksp));
    return 1;
  }
  Mat &getMatrix(){ return _a; }
};

class binding;
void linearSystemPETScRegisterBindings(binding *b);


#else

template <class scalar>
class linearSystemPETSc : public linearSystem<scalar> {
 public :
  linearSystemPETSc()
  {
    Msg::Error("PETSc is not available in this version of Gmsh");
  }
  virtual bool isAllocated() const { return false; }
  virtual void allocate(int nbRows) {}
  virtual void clear(){}
  virtual void addToMatrix(int row, int col, const scalar &val) {}
  virtual void getFromMatrix(int row, int col, scalar &val) const { return 0.; }
  virtual void addToRightHandSide(int row, const scalar &val) {}
  virtual void getFromRightHandSide(int row, scalar &val) const { return 0.; }
  virtual void getFromSolution(int row, scalar &val) const { return 0.; }
  virtual void zeroMatrix() {}
  virtual void zeroRightHandSide() {}
  virtual int systemSolve() { return 0; }
};

#endif

#endif
