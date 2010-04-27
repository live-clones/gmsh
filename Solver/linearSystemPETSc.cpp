#include "GmshConfig.h"
#if defined HAVE_PETSC
#include "linearSystemPETSc.h"
#include "fullMatrix.h"
template <>
void linearSystemPETSc<fullMatrix<double> >::addToMatrix(int row, int col, fullMatrix<double> val)
{
  for (int ii = 0; ii<val.size1(); ii++)
    for (int jj = 0; jj < ii; jj ++) {
      double buff = val(ii,jj);
      val(ii,jj) = val (jj,ii);
      val(jj,ii) = buff;
    }
  PetscInt i = row, j = col;
  _try(MatSetValuesBlocked(_a, 1, &i, 1, &j, &val(0,0), ADD_VALUES));
}
template<>
void linearSystemPETSc<fullMatrix<double> >::addToRightHandSide(int row, fullMatrix<double> val)
{
  for (int ii = 0; ii < _blockSize; ii ++) {
    PetscInt i = row * _blockSize + ii;
    _try(VecSetValues(_b, 1, &i, &val(ii,0), ADD_VALUES));
  }
}

template<>
fullMatrix<double> linearSystemPETSc<fullMatrix<double> >::getFromMatrix(int row, int col) const
{
  Msg::Error("getFromMatrix not implemented for PETSc");
  return fullMatrix<double>(0,0);
}

template<>
fullMatrix<double> linearSystemPETSc<fullMatrix<double> >::getFromRightHandSide(int row) const
{
  fullMatrix<double> val(_blockSize,1);
  PetscScalar *tmp;
  _try(VecGetArray(_b, &tmp));
  for (int i=0; i<_blockSize; i++) {
    PetscScalar s = tmp[row*_blockSize+i];
#if defined(PETSC_USE_COMPLEX)
    val(i,0) = s.real();
#else
    val(i,0) = s;
#endif
  }
  _try(VecRestoreArray(_b, &tmp));
  return val;
}

template<>
fullMatrix<double> linearSystemPETSc<fullMatrix<double> >::getFromSolution(int row) const
{
  fullMatrix<double> val(_blockSize,1);
  PetscScalar *tmp;
  _try(VecGetArray(_x, &tmp));
  for (int i=0; i<_blockSize; i++) {
    PetscScalar s = tmp[row*_blockSize+i];
#if defined(PETSC_USE_COMPLEX)
    val(i,0) = s.real();
#else
    val(i,0) = s;
#endif
  }
  _try(VecRestoreArray(_x, &tmp));
  return val;
}

template<>
void linearSystemPETSc<fullMatrix<double> >::allocate(int nbRows) {
  clear();
  _try(MatCreate(PETSC_COMM_WORLD, &_a)); 
  _try(MatSetSizes(_a, PETSC_DECIDE, PETSC_DECIDE, nbRows*_blockSize, nbRows*_blockSize));
  _try(MatSetType(_a, MATSEQBAIJ));
  // override the default options with the ones from the option
  // database (if any)
  _try(MatSetFromOptions(_a));
  _try(MatSeqBAIJSetPreallocation(_a, _blockSize, 4, NULL)); //todo preAllocate off-diagonal part
  //_try(MatMPIBAIJSetPreallocation(_a, _blockSize, 4, NULL, 0, NULL)); //todo preAllocate off-diagonal part
  _try(VecCreate(PETSC_COMM_WORLD, &_x));
  _try(VecSetSizes(_x, PETSC_DECIDE, nbRows*_blockSize));
  // override the default options with the ones from the option
  // database (if any)
  _try(VecSetFromOptions(_x));
  _try(VecDuplicate(_x, &_b));
  _isAllocated = true;
}

#include "Bindings.h"
void linearSystemPETScRegisterBindings(binding *b) {
  classBinding *cb;
  methodBinding *cm;
  cb = b->addClass<linearSystemPETSc<double> >("linearSystemPETSc");
  cb->setDescription("A linear system solver, based on PETSc");
  cm = cb->setConstructor<linearSystemPETSc<double> >();
  cm->setDescription ("A new PETSc<double> solver");
  cb->setParentClass<linearSystem<double> >();
  cm->setArgNames(NULL);
  cm = cb->addMethod("systemSolve", &linearSystem<fullMatrix<double> >::systemSolve);
  cm->setDescription("compute x = A^{-1}b");

  cb = b->addClass<linearSystemPETSc<fullMatrix<double> > >("linearSystemPETScBlock");
  cb->setDescription("A linear system solver, based on PETSc");
  cm = cb->setConstructor<linearSystemPETSc<fullMatrix<double> >, int>();
  cm->setDescription ("A new PETScBlock<double> solver (we probably should get rid of the blockSize argument)");
  cm->setArgNames("blockSize", NULL);
  cm = cb->addMethod("systemSolve", &linearSystem<fullMatrix<double> >::systemSolve);
  cm->setDescription("compute x = A^{-1}b");
}
#endif // HAVE_PETSC
