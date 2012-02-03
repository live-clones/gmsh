#include "GmshConfig.h"
#if defined(HAVE_PETSC)
#include "petsc.h"
#include "linearSystemPETSc.h"
#include "fullMatrix.h"
#include <stdlib.h>
#include "GmshMessage.h"

#include "linearSystemPETSc.hpp"

template class linearSystemPETSc<double>;
#ifdef PETSC_USE_COMPLEX
template class linearSystemPETSc<std::complex<double> >;
#endif



void linearSystemPETScBlockDouble::_kspCreate() {
  KSPCreate(PETSC_COMM_WORLD, &_ksp);
  if (this->_parameters.count("petscPrefix"))
    KSPAppendOptionsPrefix(_ksp, this->_parameters["petscPrefix"].c_str());
  KSPSetFromOptions(_ksp);
  _kspAllocated = true;
}

void linearSystemPETScBlockDouble::addToMatrix(int row, int col, const fullMatrix<double> &val)
{
  if (!_entriesPreAllocated)
    preAllocateEntries();
  #ifdef PETSC_USE_COMPLEX
  fullMatrix<std::complex<double> > modval(val.size1(), val.size2());
  for (int ii = 0; ii < val.size1(); ii++) {
    for (int jj = 0; jj < val.size1(); jj++) {
      modval(ii, jj) = val (jj, ii);
      modval(jj, ii) = val (ii, jj);
    }
  }
  #else
  fullMatrix<double> &modval = *const_cast<fullMatrix<double> *>(&val);
  for (int ii = 0; ii < val.size1(); ii++) {
    for (int jj = 0; jj < ii; jj++) {
      PetscScalar buff = modval(ii, jj);
      modval(ii, jj) = modval (jj, ii);
      modval(jj, ii) = buff;
    }
  }
  #endif
  PetscInt i = row, j = col;
  MatSetValuesBlocked(_a, 1, &i, 1, &j, &modval(0,0), ADD_VALUES);
  //transpose back so that the original matrix is not modified
  #ifndef PETSC_USE_COMPLEX
  for (int ii = 0; ii < val.size1(); ii++)
    for (int jj = 0; jj < ii; jj++) {
      PetscScalar buff = modval(ii,jj);
      modval(ii, jj) = modval (jj,ii);
      modval(jj, ii) = buff;
    }
  #endif
}

void linearSystemPETScBlockDouble::addToRightHandSide(int row, const fullMatrix<double> &val)
{
  for (int ii = 0; ii < _blockSize; ii++) {
    PetscInt i = row * _blockSize + ii;
    PetscScalar v = val(ii, 0);
    VecSetValues(_b, 1, &i, &v, ADD_VALUES);
  }
}

void linearSystemPETScBlockDouble::getFromMatrix(int row, int col, fullMatrix<double> &val ) const
{
  Msg::Error("getFromMatrix not implemented for PETSc");
}

void linearSystemPETScBlockDouble::getFromRightHandSide(int row, fullMatrix<double> &val) const
{
  for (int i = 0; i < _blockSize; i++) {
    int ii = row*_blockSize +i;
    #ifdef PETSC_USE_COMPLEX
    PetscScalar s;
    VecGetValues ( _b, 1, &ii, &s);
    val(i,0) = s.real();
    #else
    VecGetValues ( _b, 1, &ii, &val(i,0));
    #endif
  }
}

void linearSystemPETScBlockDouble::addToSolution(int row, const fullMatrix<double> &val)
{
  for (int ii = 0; ii < _blockSize; ii++) {
    PetscInt i = row * _blockSize + ii;
    PetscScalar v = val(ii, 0);
    VecSetValues(_x, 1, &i, &v, ADD_VALUES);
  }
}


void linearSystemPETScBlockDouble::getFromSolution(int row, fullMatrix<double> &val) const
{
  for (int i = 0; i < _blockSize; i++) {
    int ii = row*_blockSize +i;
    #ifdef PETSC_USE_COMPLEX
    PetscScalar s;
    VecGetValues ( _x, 1, &ii, &s);
    val(i,0) = s.real();
    #else
    VecGetValues ( _x, 1, &ii, &val(i,0));
    #endif
  }
}

void linearSystemPETScBlockDouble::allocate(int nbRows)
{
  if (this->_parameters.count("petscOptions"))
    PetscOptionsInsertString(this->_parameters["petscOptions"].c_str());
  _blockSize = strtol (_parameters["blockSize"].c_str(), NULL, 10);
  if (_blockSize == 0)
    Msg::Error ("'blockSize' parameters must be set for linearSystemPETScBlock");
  clear();
  MatCreate(PETSC_COMM_WORLD, &_a);
  MatSetSizes(_a,nbRows * _blockSize, nbRows * _blockSize, PETSC_DETERMINE, PETSC_DETERMINE);
  if (Msg::GetCommSize() > 1) {
    MatSetType(_a, MATMPIBAIJ);
  } else {
    MatSetType(_a, MATSEQBAIJ);
  }
  if (_parameters.count("petscPrefix"))
    MatAppendOptionsPrefix(_a, _parameters["petscPrefix"].c_str());
  MatSetFromOptions(_a);
  MatGetOwnershipRange(_a, &_localRowStart, &_localRowEnd);
  MatGetSize(_a, &_globalSize, &_localSize);
  _globalSize /= _blockSize;
  _localSize /= _blockSize;
  _localRowStart /= _blockSize;
  _localRowEnd /= _blockSize;
  // override the default options with the ones from the option
  // database (if any)
  VecCreate(PETSC_COMM_WORLD, &_x);
  VecSetSizes(_x, nbRows * _blockSize, PETSC_DETERMINE);
  // override the default options with the ones from the option
  // database (if any)
  if (_parameters.count("petscPrefix"))
    VecAppendOptionsPrefix(_x, _parameters["petscPrefix"].c_str());
  VecSetFromOptions(_x);
  VecDuplicate(_x, &_b);
  _isAllocated = true;
}

bool linearSystemPETScBlockDouble::isAllocated() const
{
  return _isAllocated;
}

void linearSystemPETScBlockDouble::clear()
{
  if(_isAllocated){
#if (PETSC_VERSION_RELEASE == 0 || ((PETSC_VERSION_MAJOR == 3) && (PETSC_VERSION_MINOR == 2))) // petsc-dev
    MatDestroy(&_a);
    VecDestroy(&_x);
    VecDestroy(&_b);
#else
    MatDestroy(_a);
    VecDestroy(_x);
    VecDestroy(_b);
#endif
  }
  _isAllocated = false;
}

int linearSystemPETScBlockDouble::systemSolve()
{
  if (!_kspAllocated)
    _kspCreate();
  if (_parameters["matrix_reuse"] == "same_sparsity")
    KSPSetOperators(_ksp, _a, _a, SAME_NONZERO_PATTERN);
  else if (_parameters["matrix_reuse"] == "same_matrix")
    KSPSetOperators(_ksp, _a, _a, SAME_PRECONDITIONER);
  else
    KSPSetOperators(_ksp, _a, _a, DIFFERENT_NONZERO_PATTERN);
  MatAssemblyBegin(_a, MAT_FINAL_ASSEMBLY);
  MatAssemblyEnd(_a, MAT_FINAL_ASSEMBLY);
  VecAssemblyBegin(_b);
  VecAssemblyEnd(_b);
  KSPSolve(_ksp, _b, _x);
  return 1;
}
void linearSystemPETScBlockDouble::insertInSparsityPattern (int i, int j) {
  i -= _localRowStart;
  if (i<0 || i>= _localSize) return;
  _sparsity.insertEntry (i,j);
}

void linearSystemPETScBlockDouble::preAllocateEntries()
{
  if (_entriesPreAllocated) return;
  if (!_isAllocated) Msg::Fatal("system must be allocated first");
  if (_sparsity.getNbRows() == 0) {
    PetscInt prealloc = 300;
    PetscTruth set;
    PetscOptionsGetInt(PETSC_NULL, "-petsc_prealloc", &prealloc, &set);
    if (_blockSize == 0) {
      MatSeqAIJSetPreallocation(_a, prealloc, PETSC_NULL);
    } else {
      MatSeqBAIJSetPreallocation(_a, _blockSize, 5, PETSC_NULL);
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
      MatSeqAIJSetPreallocation(_a, 0, &nByRowDiag[0]);
      MatMPIAIJSetPreallocation(_a, 0, &nByRowDiag[0], 0, &nByRowOffDiag[0]);
    } else {
      MatSeqBAIJSetPreallocation(_a, _blockSize, 0, &nByRowDiag[0]);
      MatMPIBAIJSetPreallocation(_a, _blockSize, 0, &nByRowDiag[0], 0, &nByRowOffDiag[0]);
    }
    _sparsity.clear();
  }
  _entriesPreAllocated = true;
}

void linearSystemPETScBlockDouble::zeroMatrix()
{
  if (_isAllocated && _entriesPreAllocated) {
    MatAssemblyBegin(_a, MAT_FINAL_ASSEMBLY);
    MatAssemblyEnd(_a, MAT_FINAL_ASSEMBLY);
    MatZeroEntries(_a);
  }
}

void linearSystemPETScBlockDouble::zeroRightHandSide()
{
  if (_isAllocated) {
    VecAssemblyBegin(_b);
    VecAssemblyEnd(_b);
    VecZeroEntries(_b);
  }
}

void linearSystemPETScBlockDouble::zeroSolution()
{
  if (_isAllocated) {
    VecAssemblyBegin(_x);
    VecAssemblyEnd(_x);
    VecZeroEntries(_x);
  }
}


linearSystemPETScBlockDouble::linearSystemPETScBlockDouble()
{
  _entriesPreAllocated = false;
  _isAllocated = false;
  _kspAllocated = false;
}

double linearSystemPETScBlockDouble::normInfRightHandSide() const
{
  PetscReal nor;
  VecAssemblyBegin(_b);
  VecAssemblyEnd(_b);
  VecNorm(_b, NORM_INFINITY, &nor);
  return nor;
}

#endif // HAVE_PETSC
