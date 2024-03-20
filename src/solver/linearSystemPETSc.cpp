// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"
#include <string.h>

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

// this specialization will cast to a double (take the real part) if "val" is a
// double wheras Petsc is built in complex mode.
template <>
void linearSystemPETSc<double>::getFromRightHandSide(int row, double &val) const
{
  PetscScalar *tmp;
  _check(VecGetArray(_b, &tmp));
  PetscScalar s = tmp[row];
  _check(VecRestoreArray(_b, &tmp));
  val = s.real();
}

// this specialization will cast to a double (take the real part) if "val" is a
// double wheras Petsc is built in complex mode.
template <>
void linearSystemPETSc<double>::getFromSolution(int row, double &val) const
{
  PetscScalar *tmp;
  _check(VecGetArray(_x, &tmp));
  PetscScalar s = tmp[row];
  _check(VecRestoreArray(_x, &tmp));
  val = s.real();
}
#endif

template <>
int linearSystemPETSc<fullMatrix<double> >::_getBlockSizeFromParameters() const
{
  if(_parameters.find("blockSize") == _parameters.end())
    Msg::Error("'blockSize' parameters must be set for linearSystemPETScBlock");
  int blockSize =
    strtol(_parameters.find("blockSize")->second.c_str(), nullptr, 10);
  return blockSize;
}

template <>
void linearSystemPETSc<fullMatrix<double> >::addToMatrix(
  int row, int col, const fullMatrix<double> &val)
{
  if(!_entriesPreAllocated) preAllocateEntries();
  PetscInt i = row, j = col;
#ifdef PETSC_USE_COMPLEX
  fullMatrix<std::complex<double> > modval(val.size1(), val.size2());
  for(int ii = 0; ii < val.size1(); ii++) {
    for(int jj = 0; jj < val.size1(); jj++) {
      modval(ii, jj) = val(ii, jj);
    }
  }
  MatSetValuesBlocked(_a, 1, &i, 1, &j, modval.getDataPtr(), ADD_VALUES);
#else
  MatSetValuesBlocked(_a, 1, &i, 1, &j, val.getDataPtr(), ADD_VALUES);
#endif

  _valuesNotAssembled = true;
}

template <>
void linearSystemPETSc<fullMatrix<double> >::addToRightHandSide(
  int row, const fullMatrix<double> &val, int ith)
{
  if(!_entriesPreAllocated) preAllocateEntries();
  PetscInt blockSize;
  _check(MatGetBlockSize(_a, &blockSize));
  for(int ii = 0; ii < blockSize; ii++) {
    PetscInt i = row * blockSize + ii;
    PetscScalar v = val(ii, 0);
    VecSetValues(_b, 1, &i, &v, ADD_VALUES);
  }
}

template <>
void linearSystemPETSc<fullMatrix<double> >::getFromRightHandSide(
  int row, fullMatrix<double> &val) const
{
  PetscInt blockSize;
  _check(MatGetBlockSize(_a, &blockSize));
  for(int i = 0; i < blockSize; i++) {
    PetscInt ii = row * blockSize + i;
#ifdef PETSC_USE_COMPLEX
    PetscScalar s;
    VecGetValues(_b, 1, &ii, &s);
    val(i, 0) = s.real();
#else
    VecGetValues(_b, 1, &ii, &val(i, 0));
#endif
  }
}

template <>
void linearSystemPETSc<fullMatrix<double> >::addToSolution(
  int row, const fullMatrix<double> &val)
{
  PetscInt blockSize;
  _check(MatGetBlockSize(_a, &blockSize));
  for(int ii = 0; ii < blockSize; ii++) {
    PetscInt i = row * blockSize + ii;
    PetscScalar v = val(ii, 0);
    VecSetValues(_x, 1, &i, &v, ADD_VALUES);
  }
}

template <>
void linearSystemPETSc<fullMatrix<double> >::getFromSolution(
  int row, fullMatrix<double> &val) const
{
  PetscInt blockSize;
  _check(MatGetBlockSize(_a, &blockSize));
  for(int i = 0; i < blockSize; i++) {
    PetscInt ii = row * blockSize + i;
#ifdef PETSC_USE_COMPLEX
    PetscScalar s;
    VecGetValues(_x, 1, &ii, &s);
    val(i, 0) = s.real();
#else
    VecGetValues(_x, 1, &ii, &val(i, 0));
#endif
  }
}

template class linearSystemPETSc<fullMatrix<double> >;
#endif // HAVE_PETSC
