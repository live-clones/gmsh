#if defined(HAVE_PETSC)

#include <petsc.h>
#include <petscksp.h>
#include "linearSystemPETSc.h"

#if ((PETSC_VERSION_RELEASE == 0) || ((PETSC_VERSION_MAJOR == 3) && (PETSC_VERSION_MINOR >= 7)))
#define PetscOptionsGetInt(A, B, C, D) PetscOptionsGetInt(NULL, A, B, C, D)
#define PetscOptionsInsertString(A) PetscOptionsInsertString(NULL, A)
#endif

static void _try(int ierr)
{
  CHKERRABORT(PETSC_COMM_WORLD, ierr);
}

template <class scalar>
int linearSystemPETSc<scalar>::_getBlockSizeFromParameters() const
{
  return 1;
}

template <class scalar>
void linearSystemPETSc<scalar>::_kspCreate()
{
  // Set option given by the user in its (python script) without using argc,argv or .petscrc
  if(this->_parameters.count("petsc_solver_options"))
    _try(PetscOptionsInsertString(this->_parameters["petsc_solver_options"].c_str()));
  _try(KSPCreate(_comm, &_ksp));
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

template <class scalar>
int linearSystemPETSc<scalar>::getNumKspIteration() const
{
  int n;
  _try(KSPGetIterationNumber(_ksp, &n));
  return n;
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

template <class scalar>
linearSystemPETSc<scalar>::linearSystemPETSc()
{
  _comm = PETSC_COMM_WORLD;
  _isAllocated = false;
  _kspAllocated = false;
  _matrixChangedSinceLastSolve = true;
  _valuesNotAssembled = false;
  _entriesPreAllocated = false;
}

template <class scalar>
linearSystemPETSc<scalar>::~linearSystemPETSc()
{
  clear();
  if(_kspAllocated)
    _try(KSPDestroy(&_ksp));
}

template <class scalar>
void linearSystemPETSc<scalar>::_assembleMatrixIfNeeded()
{
#if defined(HAVE_MPI)
  if (_comm == PETSC_COMM_WORLD){
    if (Msg::GetCommSize() > 1){
      int value = _valuesNotAssembled ? 1 : 0;
      int sumValue = 0;
      MPI_Allreduce((void*)&value, (void*)&sumValue, 1, MPI_INT, MPI_SUM, _comm);
      if ((sumValue > 0) &&(sumValue < Msg::GetCommSize())){
        _valuesNotAssembled = 1;
      }
    }
  }
#endif
  if (_valuesNotAssembled) {
    _try(MatAssemblyBegin(_a, MAT_FINAL_ASSEMBLY));
    _try(MatAssemblyEnd(_a, MAT_FINAL_ASSEMBLY));
    _matrixChangedSinceLastSolve = true;
    _valuesNotAssembled = false;
  }
}

template <class scalar>
void linearSystemPETSc<scalar>::insertInSparsityPattern (int i, int j)
{
  i -= _localRowStart;
  if (i<0 || i>= _localSize) return;
  _sparsity.insertEntry (i,j);
}

template <class scalar>
void linearSystemPETSc<scalar>::preAllocateEntries()
{
  if (_entriesPreAllocated) return;
  if (!_isAllocated) Msg::Fatal("system must be allocated first");
  int blockSize = _getBlockSizeFromParameters();
  std::vector<int> nByRowDiag (_localSize), nByRowOffDiag (_localSize);
  if (_sparsity.getNbRows() == 0) {
    PetscInt prealloc = 500;
    PetscBool set;
    PetscOptionsGetInt(PETSC_NULL, "-petsc_prealloc", &prealloc, &set);
    prealloc = std::min(prealloc, _localSize);
    nByRowDiag.resize(0);
    nByRowDiag.resize(_localSize, prealloc);
  } else {
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
    _sparsity.clear();
  }
  //MatXAIJSetPreallocation is not available in petsc < 3.3
  int commSize = 1;
  MPI_Comm_size(_comm, &commSize);
  if (commSize == 1){
    if (blockSize == 1)
      _try(MatSeqAIJSetPreallocation(_a, 0,  &nByRowDiag[0]));
    else
      _try(MatSeqBAIJSetPreallocation(_a, blockSize, 0, &nByRowDiag[0]));
  }
  else {
    if (blockSize == 1)
      _try(MatMPIAIJSetPreallocation(_a, 0, &nByRowDiag[0], 0, &nByRowOffDiag[0]));
    else
      _try(MatMPIBAIJSetPreallocation(_a, blockSize, 0, &nByRowDiag[0], 0, &nByRowOffDiag[0]));
  }
  if (blockSize > 1)
    _try(MatSetOption(_a, MAT_ROW_ORIENTED, PETSC_FALSE));
  _entriesPreAllocated = true;
}

template <class scalar>
void linearSystemPETSc<scalar>::allocate(int nbRows)
{
  int commSize;
  MPI_Comm_size(_comm, &commSize);
  int blockSize = _getBlockSizeFromParameters();
  clear();
  _try(MatCreate(_comm, &_a));
  _try(MatSetSizes(_a, blockSize * nbRows, blockSize * nbRows, PETSC_DETERMINE, PETSC_DETERMINE));
  if (blockSize > 1) {
    if (commSize > 1) {
      _try(MatSetType(_a, MATMPIBAIJ));
    }
    else {
      _try(MatSetType(_a, MATSEQBAIJ));
    }
  }
  // override the default options with the ones from the option
  // database (if any)
  if (this->_parameters.count("petscOptions"))
    _try(PetscOptionsInsertString(this->_parameters["petscOptions"].c_str()));
  if (this->_parameters.count("petscPrefix"))
    _try(MatAppendOptionsPrefix(_a, this->_parameters["petscPrefix"].c_str()));
  _try(MatSetFromOptions(_a));
  //since PETSc 3.3 GetOwnershipRange and MatGetSize cannot be called before MatXXXSetPreallocation
  _localSize = nbRows;
#if defined(HAVE_MPI)
  if (commSize > 1){
    _localRowStart = 0;
    if (Msg::GetCommRank() != 0) {
      MPI_Status status;
      MPI_Recv((void*)&_localRowStart, 1, MPI_INT, Msg::GetCommRank() - 1, 1, MPI_COMM_WORLD, &status);
    }
    _localRowEnd = _localRowStart + nbRows;
    if (Msg::GetCommRank() != Msg::GetCommSize() - 1) {
      MPI_Send((void*)&_localRowEnd, 1, MPI_INT, Msg::GetCommRank() + 1, 1, MPI_COMM_WORLD);
    }
    MPI_Allreduce((void*)&_localSize, (void*)&_globalSize, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
  }
  else{
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
  _try(VecCreate(_comm, &_x));
  _try(VecSetSizes(_x, blockSize * nbRows, PETSC_DETERMINE));
  // override the default options with the ones from the option
  // database (if any)
  if (this->_parameters.count("petscPrefix"))
    _try(VecAppendOptionsPrefix(_x, this->_parameters["petscPrefix"].c_str()));
  _try(VecSetFromOptions(_x));
  _try(VecDuplicate(_x, &_b));
  _isAllocated = true;
  _entriesPreAllocated = false;
}

template <class scalar>
void linearSystemPETSc<scalar>::print()
{
  _assembleMatrixIfNeeded();
  _try(VecAssemblyBegin(_b));
  _try(VecAssemblyEnd(_b));

  /*
  PetscViewer fd;
  _try(PetscViewerASCIIOpen(PETSC_COMM_WORLD, "mat.m", &fd));
  _try(PetscViewerSetFormat(fd, PETSC_VIEWER_ASCII_MATLAB));
  _try(PetscObjectSetName((PetscObject)_a, "A"));
  _try(MatView(_a, fd));
  */

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

template <class scalar>
void linearSystemPETSc<scalar>::clear()
{
  if(_isAllocated){
    _try(MatDestroy(&_a));
    _try(VecDestroy(&_x));
    _try(VecDestroy(&_b));
  }
  _isAllocated = false;
}

template <class scalar>
void linearSystemPETSc<scalar>::getFromMatrix(int row, int col, scalar &val) const
{
  Msg::Error("getFromMatrix not implemented for PETSc");
}

template <class scalar>
void linearSystemPETSc<scalar>::addToRightHandSide(int row, const scalar &val, int ith)
{
  PetscInt i = row;
  PetscScalar s = val;
  _try(VecSetValues(_b, 1, &i, &s, ADD_VALUES));
}
#if defined(PETSC_USE_COMPLEX)
// this specialization will cast to a double (take the real part) if "val" is a double wheras Petsc is built in complex mode.
template <>
void linearSystemPETSc<double>::getFromRightHandSide(int row, double &val) const;
#endif

template <class scalar>
void linearSystemPETSc<scalar>::getFromRightHandSide(int row, scalar &val) const
{
  _try(VecGetValues(_b, 1, &row, &val));
}

template <class scalar>
double linearSystemPETSc<scalar>::normInfRightHandSide() const
{
  PetscReal nor;
  VecAssemblyBegin(_b);
  VecAssemblyEnd(_b);
  _try(VecNorm(_b, NORM_INFINITY, &nor));
  return nor;
}

template <class scalar>
void linearSystemPETSc<scalar>::addToMatrix(int row, int col, const scalar &val)
{
  if (!_entriesPreAllocated)
    preAllocateEntries();
  PetscInt i = row, j = col;
  PetscScalar s = val;
  _try(MatSetValues(_a, 1, &i, 1, &j, &s, ADD_VALUES));
  _valuesNotAssembled = true;
}

template <class scalar>
void linearSystemPETSc<scalar>::addToSolution(int row, const scalar &val)
{
  PetscInt i = row;
  PetscScalar s = val;
  _try(VecSetValues(_x, 1, &i, &s, ADD_VALUES));
}
#if defined(PETSC_USE_COMPLEX)
// this specialization will cast to a double (take the real part) if "val" is a double wheras Petsc is built in complex mode.
template <>
void linearSystemPETSc<double>::getFromSolution(int row, double &val) const;
#endif

template <class scalar>
void linearSystemPETSc<scalar>::getFromSolution(int row, scalar &val) const
{
  _try(VecGetValues(_x, 1, &row, &val));
}

template <class scalar>
void linearSystemPETSc<scalar>::zeroMatrix()
{
#if defined(HAVE_MPI)
  if (_comm == PETSC_COMM_WORLD){
    if (Msg::GetCommSize() > 1){
      int value = _entriesPreAllocated ? 1 : 0;
      int sumValue = 0;
      MPI_Allreduce((void*)&value, (void*)&sumValue, 1, MPI_INT, MPI_SUM, _comm);
      if ((sumValue >= 0) &&(sumValue < Msg::GetCommSize()) && !_entriesPreAllocated){
        preAllocateEntries();
      }
    }
  }
#endif
  if (_isAllocated && _entriesPreAllocated) {
    _assembleMatrixIfNeeded();
    _try(MatZeroEntries(_a));
  }
}

template <class scalar>
void linearSystemPETSc<scalar>::zeroRightHandSide()
{
  if (_isAllocated) {
    _try(VecAssemblyBegin(_b));
    _try(VecAssemblyEnd(_b));
    _try(VecZeroEntries(_b));
  }
}

template <class scalar>
void linearSystemPETSc<scalar>::zeroSolution()
{
  if (_isAllocated) {
    _try(VecAssemblyBegin(_x));
    _try(VecAssemblyEnd(_x));
    _try(VecZeroEntries(_x));
  }
}


template <class scalar>
int linearSystemPETSc<scalar>::systemSolve()
{
  if (!_kspAllocated)
    _kspCreate();
  _assembleMatrixIfNeeded();
  if (!_matrixChangedSinceLastSolve || linearSystem<scalar>::_parameters["matrix_reuse"] == "same_matrix")
    _try(KSPSetOperators(_ksp, _a, _a, SAME_PRECONDITIONER));
  else if (linearSystem<scalar>::_parameters["matrix_reuse"] == "same_sparsity")
    _try(KSPSetOperators(_ksp, _a, _a, SAME_NONZERO_PATTERN));
  else
    _try(KSPSetOperators(_ksp, _a, _a, DIFFERENT_NONZERO_PATTERN));
  _matrixChangedSinceLastSolve = false;
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

template <class scalar>
int linearSystemPETSc<scalar>::matMult()
{
  _try(MatAssemblyBegin(_a, MAT_FINAL_ASSEMBLY));
  _try(MatAssemblyEnd(_a, MAT_FINAL_ASSEMBLY));
  _try(VecAssemblyBegin(_b));
  _try(VecAssemblyEnd(_b));
  _try(MatMult(_a,_b,_x));
  return 1;
}


template <class scalar>
void linearSystemPETSc<scalar>::printMatlab(const char *filename) const
{
  _try(MatAssemblyBegin(_a, MAT_FINAL_ASSEMBLY));
  _try(MatAssemblyEnd(_a, MAT_FINAL_ASSEMBLY));
  _try(VecAssemblyBegin(_b));
  _try(VecAssemblyEnd(_b));

  PetscViewer viewer;
  PetscViewerASCIIOpen(PETSC_COMM_WORLD, filename, &viewer);
  PetscViewerPushFormat(viewer,PETSC_VIEWER_ASCII_MATLAB);
  MatView(_a, viewer);
  PetscViewerDestroy(&viewer);
  return;
}

/*template <class scalar>
std::vector<scalar> linearSystemPETSc<scalar>::getData()
{
  _assembleMatrixIfNeeded();
  PetscScalar *v;
  _try(MatGetArray(_a,&v));
  MatInfo info;
  _try(MatGetInfo(_a,MAT_LOCAL,&info));
  std::vector<scalar> data; // Maybe I should reserve or resize (SAM)

#if defined(PETSC_USE_COMPLEX)
  for (int i = 0; i < info.nz_allocated; i++)
    data.push_back(v[i].real());
#else
  for (int i = 0; i < info.nz_allocated; i++)
    data.push_back(v[i]);
#endif
  _try(MatRestoreArray(_a,&v));
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
  _try(MatGetRowIJ(_a,0,PETSC_FALSE,PETSC_FALSE,&n,&rows,&columns,&done));        //case done == PETSC_FALSE should be handled
  std::vector<int> rowPointers; // Maybe I should reserve or resize (SAM)
  for (int i = 0; i <= n; i++)
    rowPointers.push_back(rows[i]);
  _try(MatRestoreRowIJ(_a,0,PETSC_FALSE,PETSC_FALSE,&n,&rows,&columns,&done));
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
  _try(MatGetRowIJ(_a,0,PETSC_FALSE,PETSC_FALSE,&n,&rows,&columns,&done));        //case done == PETSC_FALSE should be handled
  MatInfo info;
  _try(MatGetInfo(_a,MAT_LOCAL,&info));
  std::vector<int> columnIndices; // Maybe I should reserve or resize (SAM)
  for (int i = 0; i <  info.nz_allocated; i++)
    columnIndices.push_back(columns[i]);
  _try(MatRestoreRowIJ(_a,0,PETSC_FALSE,PETSC_FALSE,&n,&rows,&columns,&done));
  return columnIndices;
}
*/
#endif
