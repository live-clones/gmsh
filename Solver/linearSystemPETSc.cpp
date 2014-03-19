// Gmsh - Copyright (C) 1997-2014 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

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
#endif

template<>
int linearSystemPETSc<fullMatrix<double> >::_getBlockSizeFromParameters() const
{
  if ( _parameters.find("blockSize") == _parameters.end())
    Msg::Error ("'blockSize' parameters must be set for linearSystemPETScBlock");
  int blockSize = strtol(_parameters.find("blockSize")->second.c_str(), NULL, 10);
  return blockSize;
}


template<>
void linearSystemPETSc<fullMatrix<double> >::addToMatrix(int row, int col,
                                               const fullMatrix<double> &val)
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
  _valuesNotAssembled = true;
}

template<>
void linearSystemPETSc<fullMatrix<double> >::addToRightHandSide(int row,
                                                      const fullMatrix<double> &val)
{
  if (!_entriesPreAllocated)
    preAllocateEntries();
  int blockSize;
  _try(MatGetBlockSize(_a, &blockSize));
  for (int ii = 0; ii < blockSize; ii++) {
    PetscInt i = row * blockSize + ii;
    PetscScalar v = val(ii, 0);
    VecSetValues(_b, 1, &i, &v, ADD_VALUES);
  }
}

template<>
void linearSystemPETSc<fullMatrix<double > >::getFromRightHandSide(int row,
                                                        fullMatrix<double> &val) const
{
  int blockSize;
  _try(MatGetBlockSize(_a, &blockSize));
  for (int i = 0; i < blockSize; i++) {
    int ii = row*blockSize +i;
    #ifdef PETSC_USE_COMPLEX
    PetscScalar s;
    VecGetValues ( _b, 1, &ii, &s);
    val(i,0) = s.real();
    #else
    VecGetValues ( _b, 1, &ii, &val(i,0));
    #endif
  }
}

template<>
void linearSystemPETSc<fullMatrix<double> >::addToSolution(int row, const fullMatrix<double> &val)
{
  int blockSize;
  _try(MatGetBlockSize(_a, &blockSize));
  for (int ii = 0; ii < blockSize; ii++) {
    PetscInt i = row * blockSize + ii;
    PetscScalar v = val(ii, 0);
    VecSetValues(_x, 1, &i, &v, ADD_VALUES);
  }
}

template<>
void linearSystemPETSc<fullMatrix<double> >::getFromSolution(int row, fullMatrix<double> &val) const
{
  int blockSize;
  _try(MatGetBlockSize(_a, &blockSize));
  for (int i = 0; i < blockSize; i++) {
    int ii = row*blockSize +i;
    #ifdef PETSC_USE_COMPLEX
    PetscScalar s;
    VecGetValues ( _x, 1, &ii, &s);
    val(i,0) = s.real();
    #else
    VecGetValues ( _x, 1, &ii, &val(i,0));
    #endif
  }
}

template class linearSystemPETSc<fullMatrix<double> >;
#endif // HAVE_PETSC
