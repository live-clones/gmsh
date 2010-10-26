#include "GmshConfig.h"

#if defined(HAVE_PETSC)
#include "linearSystemPETSc.h"
#include "fullMatrix.h"
#include <stdlib.h>
#include "GmshMessage.h"

template <>
void linearSystemPETSc<fullMatrix<PetscScalar> >::addToMatrix(int row, int col, const fullMatrix<PetscScalar> &val)
{
  if (!_entriesPreAllocated)
    preAllocateEntries();
  fullMatrix<PetscScalar> &modval = *const_cast<fullMatrix<PetscScalar> *>(&val);
  for (int ii = 0; ii < val.size1(); ii++)
    for (int jj = 0; jj < ii; jj++) {
      PetscScalar buff = modval(ii, jj);
      modval(ii, jj) = modval (jj, ii);
      modval(jj, ii) = buff;
    }
  PetscInt i = row, j = col;
  _try(MatSetValuesBlocked(_a, 1, &i, 1, &j, &modval(0,0), ADD_VALUES));
  //transpose back so that the original matrix is not modified
  for (int ii = 0; ii < val.size1(); ii++)
    for (int jj = 0; jj < ii; jj++) {
      PetscScalar buff = modval(ii,jj);
      modval(ii, jj) = modval (jj,ii);
      modval(jj, ii) = buff;
    }
}

template<>
void linearSystemPETSc<fullMatrix<PetscScalar> >::addToRightHandSide(int row, const fullMatrix<PetscScalar> &val)
{
  for (int ii = 0; ii < _blockSize; ii++) {
    PetscInt i = row * _blockSize + ii;
    PetscScalar v = val(ii, 0);
    _try(VecSetValues(_b, 1, &i, &v, ADD_VALUES));
  }
}

template<>
void linearSystemPETSc<fullMatrix<PetscScalar> >::getFromMatrix(int row, int col, fullMatrix<PetscScalar> &val ) const
{
  Msg::Error("getFromMatrix not implemented for PETSc");
}

template<>
void linearSystemPETSc<fullMatrix<PetscScalar> >::getFromRightHandSide(int row, fullMatrix<PetscScalar> &val) const
{
#if defined(PETSC_USE_COMPLEX)
  PetscScalar *tmp;
  _try(VecGetArray(_b, &tmp));
  for (int i = 0; i < _blockSize; i++) {
    PetscScalar s = tmp[row * _blockSize + i];
    val(i,0) = s.real();
  }
  _try(VecRestoreArray(_b, &tmp));
#else
  for (int i = 0; i < _blockSize; i++) {
    int ii = row*_blockSize +i;
    VecGetValues ( _b, 1, &ii, &val(i,0));
  }
#endif
}

template<>
void linearSystemPETSc<fullMatrix<PetscScalar> >::getFromSolution(int row, fullMatrix<PetscScalar> &val) const {
#if defined(PETSC_USE_COMPLEX)
  PetscScalar *tmp;
  _try(VecGetArray(_x, &tmp));
  for (int i = 0; i < _blockSize; i++) {
    PetscScalar s = tmp[row * _blockSize + i];
    val(i,0) = s.real();
  }
  _try(VecRestoreArray(_x, &tmp));
#else
  for (int i = 0; i < _blockSize; i++) {
    int ii = row*_blockSize +i;
    VecGetValues ( _x, 1, &ii, &val(i,0));
  }
#endif
}

template<>
void linearSystemPETSc<fullMatrix<PetscScalar> >::allocate(int nbRows) 
{
  _blockSize = strtol (_parameters["blockSize"].c_str(), NULL, 10);
  if (_blockSize == 0)
    Msg::Error ("'blockSize' parameters must be set for linearSystemPETScBlock");
  clear();
  //printf("allocate linear system petsc \n");
  //_try(PetscOptionsInsertString("-ksp_monitor_true_residual -ksp_rtol 1e-10"));
  _try(MatCreate(PETSC_COMM_WORLD, &_a)); 
  _try(MatSetSizes(_a,nbRows * _blockSize, nbRows * _blockSize, PETSC_DETERMINE, PETSC_DETERMINE));
  if (Msg::GetCommSize() > 1) {
    _try(MatSetType(_a, MATMPIBAIJ));
  } else {
    _try(MatSetType(_a, MATSEQBAIJ));
  }
  if (_parameters.count("petscPrefix"))
    _try(MatAppendOptionsPrefix(_a, _parameters["petscPrefix"].c_str()));
  _try(MatSetFromOptions(_a));
  _try(MatGetOwnershipRange(_a, &_localRowStart, &_localRowEnd));
  _try(MatGetSize(_a, &_globalSize, &_localSize));
  _globalSize /= _blockSize;
  _localSize /= _blockSize;
  _localRowStart /= _blockSize;
  _localRowEnd /= _blockSize;
  // override the default options with the ones from the option
  // database (if any)
  _try(VecCreate(PETSC_COMM_WORLD, &_x));
  _try(VecSetSizes(_x, nbRows * _blockSize, PETSC_DETERMINE));
  // override the default options with the ones from the option
  // database (if any)
  if (_parameters.count("petscPrefix"))
    _try(VecAppendOptionsPrefix(_x, _parameters["petscPrefix"].c_str()));
  _try(VecSetFromOptions(_x));
  _try(VecDuplicate(_x, &_b));
  _isAllocated = true;
}

#include "Bindings.h"
void linearSystemPETScRegisterBindings(binding *b) 
{
 // FIXME on complex arithmetic this crashes
  #if !defined(PETSC_USE_COMPLEX)
  classBinding *cb;
  methodBinding *cm;
  cb = b->addClass<linearSystemPETSc<PetscScalar> >("linearSystemPETSc");
  cb->setDescription("A linear system solver, based on PETSc");
  cm = cb->setConstructor<linearSystemPETSc<PetscScalar> >();
  cm->setDescription ("A new PETSc<PetscScalar> solver");
  cb->setParentClass<linearSystem<PetscScalar> >();
  cm->setArgNames(NULL);
  cb = b->addClass<linearSystemPETSc<fullMatrix<PetscScalar> > >("linearSystemPETScBlock");
  cb->setDescription("A linear system solver, based on PETSc");
  cm = cb->setConstructor<linearSystemPETSc<fullMatrix<PetscScalar> > >();
  cm->setDescription ("A new PETScBlock<PetscScalar> solver");
  cb->setParentClass<linearSystem<fullMatrix<PetscScalar> > >();
#endif // FIXME
}

#endif // HAVE_PETSC
