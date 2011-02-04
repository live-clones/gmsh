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
#include "sparsityPattern.h"
#include "fullMatrix.h"
#include <vector>

#if defined(HAVE_PETSC)
#include <petsc.h>
#include <petscksp.h>

template <class scalar>
class linearSystemPETSc : public linearSystem<scalar> {
  protected:
  int _blockSize; // for block Matrix
  bool _isAllocated, _kspAllocated, _entriesPreAllocated;
  Mat _a;
  Vec _b, _x;
  KSP _ksp;
  int _localRowStart, _localRowEnd, _localSize, _globalSize;
  sparsityPattern _sparsity;
  static void _try(int ierr) { CHKERRABORT(PETSC_COMM_WORLD, ierr); }
  void _kspCreate() {
    _try(KSPCreate(PETSC_COMM_WORLD, &_ksp));
    PC pc;
    _try(KSPGetPC(_ksp, &pc));
    // set some default options
    //_try(PCSetType(pc, PCLU));//LU for direct solver and PCILU for indirect solver
/*    _try(PCFactorSetMatOrderingType(pc, MATORDERING_RCM));
    _try(PCFactorSetLevels(pc, 1));*/
    _try(KSPSetTolerances(_ksp, 1.e-8, PETSC_DEFAULT, PETSC_DEFAULT, PETSC_DEFAULT));
    // override the default options with the ones from the option
    // database (if any)
    if (this->_parameters.count("petscPrefix"))
      _try(KSPAppendOptionsPrefix(_ksp, this->_parameters["petscPrefix"].c_str()));
    _try(KSPSetFromOptions(_ksp));
    _try(PCSetFromOptions(pc));
    _kspAllocated = true;
  }
 public:
  linearSystemPETSc() : _isAllocated(false) {_blockSize = 0; _kspAllocated = false;}
  virtual ~linearSystemPETSc(){
    clear();
    if (_kspAllocated)
      _try (KSPDestroy (_ksp));
  }
  void insertInSparsityPattern (int i, int j) {
    i -= _localRowStart;
    if (i<0 || i>= _localSize) return;
    _sparsity.insertEntry (i,j);
  }
  virtual bool isAllocated() const { return _isAllocated; }
  virtual void preAllocateEntries() {
    if (_entriesPreAllocated) return;
    if (!_isAllocated) Msg::Fatal("system must be allocated first");
    if (_sparsity.getNbRows() == 0) {
      PetscInt prealloc = 300;
      PetscTruth set;
      PetscOptionsGetInt(PETSC_NULL, "-petsc_prealloc", &prealloc, &set);
      if (_blockSize == 0) {
        _try(MatSeqAIJSetPreallocation(_a, prealloc, PETSC_NULL));
      } else {
        _try(MatSeqBAIJSetPreallocation(_a, _blockSize, 5, PETSC_NULL));
      }
    } else {
      std::vector<int> nByRowDiag (_localSize), nByRowOffDiag (_localSize);
      for (int i = 0; i < _localSize; i++) {
        int n;
        const int *r = _sparsity.getRow(i, n);
        for (int j = 0; j < n; j++) {
          if (r[j] >= _localRowStart && r[j] < _localRowEnd)
            nByRowDiag[i] ++;
          else
            nByRowOffDiag[i] ++;
        }
      }
      if (_blockSize == 0) {
        _try(MatSeqAIJSetPreallocation(_a, 0, &nByRowDiag[0]));
        _try(MatMPIAIJSetPreallocation(_a, 0, &nByRowDiag[0], 0, &nByRowOffDiag[0]));
      } else {
        _try(MatSeqBAIJSetPreallocation(_a, _blockSize, 0, &nByRowDiag[0]));
        _try(MatMPIBAIJSetPreallocation(_a, _blockSize, 0, &nByRowDiag[0], 0, &nByRowOffDiag[0]));
      }
      _sparsity.clear();
    }
    _entriesPreAllocated = true;
  }
  virtual void allocate(int nbRows)
  {
    clear();
    _try(MatCreate(PETSC_COMM_WORLD, &_a));
    _try(MatSetSizes(_a, nbRows, nbRows, PETSC_DETERMINE, PETSC_DETERMINE));
    // override the default options with the ones from the option
    // database (if any)
    if (this->_parameters.count("petscOptions"))
      _try(PetscOptionsInsertString(this->_parameters["petscOptions"].c_str()));
    if (this->_parameters.count("petscPrefix"))
      _try(MatAppendOptionsPrefix(_a, this->_parameters["petscPrefix"].c_str()));
    _try(MatSetFromOptions(_a));
    _try(MatGetOwnershipRange(_a, &_localRowStart, &_localRowEnd));
    _try(MatGetSize(_a, &_globalSize, &_localSize));
    // preallocation option must be set after other options
    _try(VecCreate(PETSC_COMM_WORLD, &_x));
    _try(VecSetSizes(_x, nbRows, PETSC_DETERMINE));
    // override the default options with the ones from the option
    // database (if any)
    if (this->_parameters.count("petscPrefix"))
      _try(VecAppendOptionsPrefix(_x, this->_parameters["petscPrefix"].c_str()));
    _try(VecSetFromOptions(_x));
    _try(VecDuplicate(_x, &_b));
    _isAllocated = true;
    _entriesPreAllocated = false;
  }
  void print() {
      _try(MatAssemblyBegin(_a, MAT_FINAL_ASSEMBLY));
      _try(MatAssemblyEnd(_a, MAT_FINAL_ASSEMBLY));
      _try(VecAssemblyBegin(_b));
      _try(VecAssemblyEnd(_b));
    if(Msg::GetCommRank()==0)
    printf("a :\n");
    MatView(_a, PETSC_VIEWER_STDOUT_WORLD);
    if(Msg::GetCommRank()==0)
    printf("b :\n");
    VecView(_b, PETSC_VIEWER_STDOUT_WORLD);
    if(Msg::GetCommRank()==0)
    printf("x :\n");
    VecView(_x, PETSC_VIEWER_STDOUT_WORLD);
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
#if defined(PETSC_USE_COMPLEX)
    PetscScalar *tmp;
    _try(VecGetArray(_b, &tmp));
    PetscScalar s = tmp[row];
    _try(VecRestoreArray(_b, &tmp));
    // FIXME specialize this routine
    val = s.real();
#else
    VecGetValues(_b, 1, &row, &val);
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
    if (!_entriesPreAllocated)
      preAllocateEntries();
    PetscInt i = row, j = col;
    PetscScalar s = val;
    _try(MatSetValues(_a, 1, &i, 1, &j, &s, ADD_VALUES));
  }
  virtual void getFromSolution(int row, scalar &val) const
  {
#if defined(PETSC_USE_COMPLEX)
    PetscScalar *tmp;
    _try(VecGetArray(_x, &tmp));
    PetscScalar s = tmp[row];
    _try(VecRestoreArray(_x, &tmp));
    val = s.real();
#else
    VecGetValues(_x, 1, &row, &val);
#endif
  }
  virtual void zeroMatrix()
  {
    if (_isAllocated && _entriesPreAllocated) {
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
  virtual int systemSolve()
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
    /*MatInfo info;
    MatGetInfo(_a, MAT_LOCAL, &info);
    printf("mallocs %.0f    nz_allocated %.0f    nz_used %.0f    nz_unneeded %.0f\n", info.mallocs, info.nz_allocated, info.nz_used, info.nz_unneeded);*/
    _try(VecAssemblyBegin(_b));
    _try(VecAssemblyEnd(_b));
    _try(KSPSolve(_ksp, _b, _x));
    //_try(KSPView(ksp, PETSC_VIEWER_STDOUT_SELF));
    //PetscInt its;
    //_try(KSPGetIterationNumber(ksp, &its));
    //Msg::Info("%d iterations", its);
    return 1;
  }
  Mat &getMatrix(){ return _a; }
};

class binding;
void linearSystemPETScRegisterBindings(binding *b);

class linearSystemPETScBlockDouble : public linearSystem<fullMatrix<double> > {
  bool _entriesPreAllocated, _isAllocated, _kspAllocated;
  sparsityPattern _sparsity;
  Mat _a;
  Vec _b, _x;
  KSP _ksp;
  int _blockSize, _localRowStart, _localRowEnd, _globalSize, _localSize;
  public:
  void _kspCreate();
  virtual void addToMatrix(int row, int col, const fullMatrix<double> &val);
  virtual void addToRightHandSide(int row, const fullMatrix<double> &val);
  virtual void getFromMatrix(int row, int col, fullMatrix<double> &val ) const;
  virtual void getFromRightHandSide(int row, fullMatrix<double> &val) const;
  virtual void getFromSolution(int row, fullMatrix<double> &val) const;
  void allocate(int nbRows);
  bool isAllocated() const;
  int systemSolve();
  void preAllocateEntries();
  void clear();
  void zeroMatrix();
  void zeroRightHandSide();
  double normInfRightHandSide() const;
  void insertInSparsityPattern (int i, int j);
  linearSystemPETScBlockDouble();
};

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
  virtual void getFromMatrix(int row, int col, scalar &val) const {}
  virtual void addToRightHandSide(int row, const scalar &val) {}
  virtual void getFromRightHandSide(int row, scalar &val) const {}
  virtual void getFromSolution(int row, scalar &val) const {}
  virtual void zeroMatrix() {}
  virtual void zeroRightHandSide() {}
  virtual int systemSolve() { return 0; }
  virtual double normInfRightHandSide() const{return 0;}
};


#endif


#endif
