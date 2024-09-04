// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#if defined(HAVE_PETSC)

#include <petsc.h>
#include <petscksp.h>
#include "linearSystemPETSc.h"

#if((PETSC_VERSION_RELEASE == 0) ||                                            \
    ((PETSC_VERSION_MAJOR == 3) && (PETSC_VERSION_MINOR >= 7)))
#define PetscOptionsGetInt(A, B, C, D) PetscOptionsGetInt(NULL, A, B, C, D)
#define PetscOptionsInsertString(A) PetscOptionsInsertString(NULL, A)
#endif

static void _check(int ierr) { CHKERRABORT(PETSC_COMM_WORLD, ierr); }

template <class scalar>
int linearSystemPETSc<scalar>::_getBlockSizeFromParameters() const
{
  return 1;
}

template <class scalar> void linearSystemPETSc<scalar>::_kspCreate()
{
  // Set option given by the user in its (python script) without using argc,argv
  // or .petscrc
  if(this->_parameters.count("petsc_solver_options"))
    _check(PetscOptionsInsertString(
      this->_parameters["petsc_solver_options"].c_str()));
  _check(KSPCreate(_comm, &_ksp));
  PC pc;
  _check(KSPGetPC(_ksp, &pc));
  // set some default options
  //_check(PCSetType(pc, PCLU));//LU for direct solver and PCILU for indirect
  //solver
  /*    _check(PCFactorSetMatOrderingType(pc, MATORDERING_RCM));
        _check(PCFactorSetLevels(pc, 1));*/
  _check(
    KSPSetTolerances(_ksp, 1.e-8, PETSC_DEFAULT, PETSC_DEFAULT, PETSC_DEFAULT));
  // override the default options with the ones from the option
  // database (if any)
  if(this->_parameters.count("petscPrefix"))
    _check(
      KSPAppendOptionsPrefix(_ksp, this->_parameters["petscPrefix"].c_str()));
  _check(KSPSetFromOptions(_ksp));
  _check(PCSetFromOptions(pc));
  _kspAllocated = true;
}

template <class scalar>
int linearSystemPETSc<scalar>::getNumKspIteration() const
{
  PetscInt n;
  _check(KSPGetIterationNumber(_ksp, &n));
  return (int)n;
}

template <class scalar>
linearSystemPETSc<scalar>::linearSystemPETSc(MPI_Comm com)
{
  _comm = com;
  _isAllocated = false;
  _kspAllocated = false;
  _matrixChangedSinceLastSolve = true;
  _valuesNotAssembled = false;
  _entriesPreAllocated = false;
}

template <class scalar> linearSystemPETSc<scalar>::linearSystemPETSc()
{
  _comm = PETSC_COMM_WORLD;
  _isAllocated = false;
  _kspAllocated = false;
  _matrixChangedSinceLastSolve = true;
  _valuesNotAssembled = false;
  _entriesPreAllocated = false;
}

template <class scalar> linearSystemPETSc<scalar>::~linearSystemPETSc()
{
  clear();
  if(_kspAllocated) _check(KSPDestroy(&_ksp));
}

template <class scalar>
void linearSystemPETSc<scalar>::_assembleMatrixIfNeeded()
{
#if defined(HAVE_MPI)
  if(_comm == PETSC_COMM_WORLD) {
    if(Msg::GetCommSize() > 1) {
      int value = _valuesNotAssembled ? 1 : 0;
      int sumValue = 0;
      MPI_Allreduce((void *)&value, (void *)&sumValue, 1, MPI_INT, MPI_SUM,
                    _comm);
      if((sumValue > 0) && (sumValue < Msg::GetCommSize())) {
        _valuesNotAssembled = 1;
      }
    }
  }
#endif
  if(_valuesNotAssembled) {
    _check(MatAssemblyBegin(_a, MAT_FINAL_ASSEMBLY));
    _check(MatAssemblyEnd(_a, MAT_FINAL_ASSEMBLY));
    _matrixChangedSinceLastSolve = true;
    _valuesNotAssembled = false;
  }
}

template <class scalar>
void linearSystemPETSc<scalar>::insertInSparsityPattern(int i, int j)
{
  i -= _localRowStart;
  if(i < 0 || i >= _localSize) return;
  _sparsity.insertEntry(i, j);
}

template <class scalar> void linearSystemPETSc<scalar>::preAllocateEntries()
{
  if(_entriesPreAllocated) return;
  if(!_isAllocated){
    Msg::Error("System must be allocated first");
    return;
  }
  int blockSize = _getBlockSizeFromParameters();
  std::vector<PetscInt> nByRowDiag(_localSize), nByRowOffDiag(_localSize);
  if(_sparsity.getNbRows() == 0) {
    PetscInt prealloc = 300; // 8*27 = 216 for 8 2nd order hexas
    PetscBool set;
    PetscOptionsGetInt(nullptr, "-petsc_prealloc", &prealloc, &set);
    prealloc = std::min(prealloc, _localSize);
    nByRowDiag.resize(0);
    nByRowDiag.resize(_localSize, prealloc);
  }
  else {
    for(int i = 0; i < _localSize; i++) {
      int n;
      const int *r = _sparsity.getRow(i, n);
      for(int j = 0; j < n; j++) {
        if(r[j] >= _localRowStart && r[j] < _localRowEnd)
          nByRowDiag[i]++;
        else
          nByRowOffDiag[i]++;
      }
    }
    _sparsity.clear();
  }
  // MatXAIJSetPreallocation is not available in petsc < 3.3
  int commSize = 1;
  MPI_Comm_size(_comm, &commSize);
  if(commSize == 1) {
    if(blockSize == 1)
      _check(MatSeqAIJSetPreallocation(_a, 0, &nByRowDiag[0]));
    else
      _check(MatSeqBAIJSetPreallocation(_a, blockSize, 0, &nByRowDiag[0]));
  }
  else {
    if(blockSize == 1)
      _check(
        MatMPIAIJSetPreallocation(_a, 0, &nByRowDiag[0], 0, &nByRowOffDiag[0]));
    else
      _check(MatMPIBAIJSetPreallocation(_a, blockSize, 0, &nByRowDiag[0], 0,
                                        &nByRowOffDiag[0]));
  }
  if(blockSize > 1) _check(MatSetOption(_a, MAT_ROW_ORIENTED, PETSC_FALSE));
  _entriesPreAllocated = true;

#if ((PETSC_VERSION_MAJOR == 3) && (PETSC_VERSION_MINOR >= 3))
  // Preallocation routines automatically set now
  // MAT_NEW_NONZERO_ALLOCATION_ERR, which causes a problem when the mask of the
  // matrix changes.  We must disable the error generation and allow new
  // allocation (if needed)
  _check(MatSetOption(_a, MAT_NEW_NONZERO_ALLOCATION_ERR, PETSC_FALSE));
#endif
}

template <class scalar> void linearSystemPETSc<scalar>::allocate(int nbRows)
{
  int commSize;
  MPI_Comm_size(_comm, &commSize);
  int blockSize = _getBlockSizeFromParameters();
  clear();
  _check(MatCreate(_comm, &_a));
  _check(MatSetSizes(_a, blockSize * nbRows, blockSize * nbRows,
                     PETSC_DETERMINE, PETSC_DETERMINE));
  if(blockSize > 1) {
    if(commSize > 1) {
      _check(MatSetType(_a, MATMPIBAIJ));
    }
    else {
      _check(MatSetType(_a, MATSEQBAIJ));
    }
  }
  // override the default options with the ones from the option
  // database (if any)
  if(this->_parameters.count("petscOptions"))
    _check(PetscOptionsInsertString(this->_parameters["petscOptions"].c_str()));
  if(this->_parameters.count("petscPrefix"))
    _check(
      MatAppendOptionsPrefix(_a, this->_parameters["petscPrefix"].c_str()));
  _check(MatSetFromOptions(_a));
  // since PETSc 3.3 GetOwnershipRange and MatGetSize cannot be called before
  // MatXXXSetPreallocation
  _localSize = nbRows;
#if defined(HAVE_MPI)
  if(commSize > 1) {
    _localRowStart = 0;
    if(Msg::GetCommRank() != 0) {
      MPI_Status status;
      MPI_Recv((void *)&_localRowStart, 1, MPI_INT, Msg::GetCommRank() - 1, 1,
               MPI_COMM_WORLD, &status);
    }
    _localRowEnd = _localRowStart + nbRows;
    if(Msg::GetCommRank() != Msg::GetCommSize() - 1) {
      MPI_Send((void *)&_localRowEnd, 1, MPI_INT, Msg::GetCommRank() + 1, 1,
               MPI_COMM_WORLD);
    }
    MPI_Allreduce((void *)&_localSize, (void *)&_globalSize, 1, MPI_INT,
                  MPI_SUM, MPI_COMM_WORLD);
  }
  else {
    _localRowStart = 0;
    _localRowEnd = nbRows;
    _globalSize = _localSize;
  }
#else
  _localRowStart = 0;
  _localRowEnd = nbRows;
  _globalSize = _localSize;
#endif

  // preallocation option must be set after other options
  _check(VecCreate(_comm, &_x));
  _check(VecSetSizes(_x, blockSize * nbRows, PETSC_DETERMINE));
  // override the default options with the ones from the option
  // database (if any)
  if(this->_parameters.count("petscPrefix"))
    _check(
      VecAppendOptionsPrefix(_x, this->_parameters["petscPrefix"].c_str()));
  _check(VecSetFromOptions(_x));
  _check(VecDuplicate(_x, &_b));
  _isAllocated = true;
  _entriesPreAllocated = false;
}

template <class scalar> void linearSystemPETSc<scalar>::print()
{
  _assembleMatrixIfNeeded();
  _check(VecAssemblyBegin(_b));
  _check(VecAssemblyEnd(_b));

  /*
  PetscViewer fd;
  _check(PetscViewerASCIIOpen(PETSC_COMM_WORLD, "mat.m", &fd));
  _check(PetscViewerSetFormat(fd, PETSC_VIEWER_ASCII_MATLAB));
  _check(PetscObjectSetName((PetscObject)_a, "A"));
  _check(MatView(_a, fd));
  */

  if(Msg::GetCommRank() == 0) printf("a :\n");
  MatView(_a, PETSC_VIEWER_STDOUT_WORLD);
  if(Msg::GetCommRank() == 0) printf("b :\n");
  VecView(_b, PETSC_VIEWER_STDOUT_WORLD);
  if(Msg::GetCommRank() == 0) printf("x :\n");
  VecView(_x, PETSC_VIEWER_STDOUT_WORLD);
}

template <class scalar> void linearSystemPETSc<scalar>::clear()
{
  if(_isAllocated) {
    _check(MatDestroy(&_a));
    _check(VecDestroy(&_x));
    _check(VecDestroy(&_b));
  }
  _isAllocated = false;
}

template <class scalar>
void linearSystemPETSc<scalar>::getFromMatrix(int row, int col,
                                              scalar &val) const
{
  Msg::Error("getFromMatrix not implemented for PETSc");
}

template <class scalar>
void linearSystemPETSc<scalar>::addToRightHandSide(int row, const scalar &val,
                                                   int ith)
{
  PetscInt i = row;
  PetscScalar s = val;
  _check(VecSetValues(_b, 1, &i, &s, ADD_VALUES));
}
#if defined(PETSC_USE_COMPLEX)
// this specialization will cast to a double (take the real part) if "val" is a
// double wheras Petsc is built in complex mode.
template <>
void linearSystemPETSc<double>::getFromRightHandSide(int row,
                                                     double &val) const;
#endif

template <class scalar>
void linearSystemPETSc<scalar>::getFromRightHandSide(int row, scalar &val) const
{
  PetscInt r = row;
  _check(VecGetValues(_b, 1, &r, &val));
}

template <class scalar>
double linearSystemPETSc<scalar>::normInfRightHandSide() const
{
  PetscReal nor;
  VecAssemblyBegin(_b);
  VecAssemblyEnd(_b);
  _check(VecNorm(_b, NORM_INFINITY, &nor));
  return nor;
}

template <class scalar>
void linearSystemPETSc<scalar>::addToMatrix(int row, int col, const scalar &val)
{
  if(!_entriesPreAllocated) preAllocateEntries();
  PetscInt i = row, j = col;
  PetscScalar s = val;
  _check(MatSetValues(_a, 1, &i, 1, &j, &s, ADD_VALUES));
  _valuesNotAssembled = true;
}

template <class scalar>
void linearSystemPETSc<scalar>::addToSolution(int row, const scalar &val)
{
  PetscInt i = row;
  PetscScalar s = val;
  _check(VecSetValues(_x, 1, &i, &s, ADD_VALUES));
}
#if defined(PETSC_USE_COMPLEX)
// this specialization will cast to a double (take the real part) if "val" is a
// double wheras Petsc is built in complex mode.
template <>
void linearSystemPETSc<double>::getFromSolution(int row, double &val) const;
#endif

template <class scalar>
void linearSystemPETSc<scalar>::getFromSolution(int row, scalar &val) const
{
  PetscInt r = row;
  _check(VecGetValues(_x, 1, &r, &val));
}

template <class scalar> void linearSystemPETSc<scalar>::zeroMatrix()
{
#if defined(HAVE_MPI)
  if(_comm == PETSC_COMM_WORLD) {
    if(Msg::GetCommSize() > 1) {
      int value = _entriesPreAllocated ? 1 : 0;
      int sumValue = 0;
      MPI_Allreduce((void *)&value, (void *)&sumValue, 1, MPI_INT, MPI_SUM,
                    _comm);
      if((sumValue >= 0) && (sumValue < Msg::GetCommSize()) &&
         !_entriesPreAllocated) {
        preAllocateEntries();
      }
    }
  }
#endif
  if(_isAllocated && _entriesPreAllocated) {
    _assembleMatrixIfNeeded();
    _check(MatZeroEntries(_a));
  }
}

template <class scalar> void linearSystemPETSc<scalar>::zeroRightHandSide()
{
  if(_isAllocated) {
    _check(VecAssemblyBegin(_b));
    _check(VecAssemblyEnd(_b));
    _check(VecZeroEntries(_b));
  }
}

template <class scalar> void linearSystemPETSc<scalar>::zeroSolution()
{
  if(_isAllocated) {
    _check(VecAssemblyBegin(_x));
    _check(VecAssemblyEnd(_x));
    _check(VecZeroEntries(_x));
  }
}

template <class scalar> int linearSystemPETSc<scalar>::systemSolve()
{
  if(!_kspAllocated) _kspCreate();
  _assembleMatrixIfNeeded();
  if(!_matrixChangedSinceLastSolve ||
     linearSystem<scalar>::_parameters["matrix_reuse"] == "same_matrix")
    _check(KSPSetOperators(_ksp, _a, _a, SAME_PRECONDITIONER));
  else if(linearSystem<scalar>::_parameters["matrix_reuse"] == "same_sparsity")
    _check(KSPSetOperators(_ksp, _a, _a, SAME_NONZERO_PATTERN));
  else
    _check(KSPSetOperators(_ksp, _a, _a, DIFFERENT_NONZERO_PATTERN));
  _matrixChangedSinceLastSolve = false;
  /*MatInfo info;
    MatGetInfo(_a, MAT_LOCAL, &info);
    printf("mallocs %.0f    nz_allocated %.0f    nz_used %.0f    nz_unneeded
    %.0f\n", info.mallocs, info.nz_allocated, info.nz_used, info.nz_unneeded);*/
  _check(VecAssemblyBegin(_b));
  _check(VecAssemblyEnd(_b));
  _check(KSPSolve(_ksp, _b, _x));
  
  // check solver failed
  KSPConvergedReason reason;
  _check(KSPGetConvergedReason(_ksp, &reason));
  if (reason < 0) 
  {
      Msg::Error("The linear system of equations did not converge (PETSc reason : %d)", reason);
      return 0;
  };
  
  //_check(KSPView(ksp, PETSC_VIEWER_STDOUT_SELF));
  // PetscInt its;
  //_check(KSPGetIterationNumber(ksp, &its));
  // Msg::Info("%d iterations", its);
  return 1;
}

template <class scalar> int linearSystemPETSc<scalar>::matMult()
{
  _check(MatAssemblyBegin(_a, MAT_FINAL_ASSEMBLY));
  _check(MatAssemblyEnd(_a, MAT_FINAL_ASSEMBLY));
  _check(VecAssemblyBegin(_b));
  _check(VecAssemblyEnd(_b));
  _check(MatMult(_a, _b, _x));
  return 1;
}

template <class scalar>
void linearSystemPETSc<scalar>::printMatlab(const char *filename) const
{
  _check(MatAssemblyBegin(_a, MAT_FINAL_ASSEMBLY));
  _check(MatAssemblyEnd(_a, MAT_FINAL_ASSEMBLY));
  _check(VecAssemblyBegin(_b));
  _check(VecAssemblyEnd(_b));

  PetscViewer viewer;
  PetscViewerASCIIOpen(PETSC_COMM_WORLD, filename, &viewer);
  PetscViewerPushFormat(viewer, PETSC_VIEWER_ASCII_MATLAB);
  MatView(_a, viewer);
  PetscViewerDestroy(&viewer);
  return;
}

/*template <class scalar>
std::vector<scalar> linearSystemPETSc<scalar>::getData()
{
  _assembleMatrixIfNeeded();
  PetscScalar *v;
  _check(MatGetArray(_a,&v));
  MatInfo info;
  _check(MatGetInfo(_a,MAT_LOCAL,&info));
  std::vector<scalar> data; // Maybe I should reserve or resize (SAM)

#if defined(PETSC_USE_COMPLEX)
  for (int i = 0; i < info.nz_allocated; i++)
    data.push_back(v[i].real());
#else
  for (int i = 0; i < info.nz_allocated; i++)
    data.push_back(v[i]);
#endif
  _check(MatRestoreArray(_a,&v));
  return data;
}*/
/*
template <class scalar>
std::vector<int> linearSystemPETSc<scalar>::getRowPointers()
{
  _assembleMatrixIfNeeded();
  const PetscInt *rows;
  const PetscInt *columns;
  PetscInt n;
  PetscBool done;
  _check(MatGetRowIJ(_a,0,PETSC_FALSE,PETSC_FALSE,&n,&rows,&columns,&done));
//case done == PETSC_FALSE should be handled std::vector<int> rowPointers; //
Maybe I should reserve or resize (SAM) for (int i = 0; i <= n; i++)
    rowPointers.push_back(rows[i]);
  _check(MatRestoreRowIJ(_a,0,PETSC_FALSE,PETSC_FALSE,&n,&rows,&columns,&done));
  return rowPointers;
}

template <class scalar>
std::vector<int> linearSystemPETSc<scalar>::getColumnsIndices()
{
  _assembleMatrixIfNeeded();
  const PetscInt *rows;
  const PetscInt *columns;
  PetscInt n;
  PetscBool done;
  _check(MatGetRowIJ(_a,0,PETSC_FALSE,PETSC_FALSE,&n,&rows,&columns,&done));
//case done == PETSC_FALSE should be handled MatInfo info;
  _check(MatGetInfo(_a,MAT_LOCAL,&info));
  std::vector<int> columnIndices; // Maybe I should reserve or resize (SAM)
  for (int i = 0; i <  info.nz_allocated; i++)
    columnIndices.push_back(columns[i]);
  _check(MatRestoreRowIJ(_a,0,PETSC_FALSE,PETSC_FALSE,&n,&rows,&columns,&done));
  return columnIndices;
}
*/
#endif
