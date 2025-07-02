// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef LINEAR_SYSTEM_PETSC_H
#define LINEAR_SYSTEM_PETSC_H

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
#include <string.h>
#include <vector>

#if defined(HAVE_PETSC)

#ifndef SWIG
#include "petsc.h"
#include "petscksp.h"
#else
typedef struct _p_Mat *Mat;
typedef struct _p_Vec *Vec;
typedef struct _p_KSP *KSP;
#endif

// support old PETSc version, try to avoid using PETSC_VERSION in other places
#if PETSC_VERSION_RELEASE != 0 &&                                              \
  (PETSC_VERSION_MAJOR < 3 ||                                                  \
   (PETSC_VERSION_MAJOR == 3 && PETSC_VERSION_MINOR < 2))
#define KSPDestroy(k) KSPDestroy(*(k))
#define MatDestroy(m) MatDestroy(*(m))
#define VecDestroy(v) VecDestroy(*(v))
#define PetscViewerDestroy(v) PetscViewerDestroy(*(v))
#define PetscBool PetscTruth
#define PetscOptionsGetBool PetscOptionsGetTruth
#endif

// The petsc3.5 change log says:
// "KSPSetOperators() no longer has the MatStructure argument. The Mat objects
// now track that information themselves. Use KPS/PCSetReusePreconditioner() to
// prevent the recomputation of the preconditioner if the operator changed in
// the way that SAME_PRECONDITIONER did with KSPSetOperators()" So I guess this
// should be called with PETSC_TRUE as second argument only for
// SAME_PRECONDITIONER and false otherwise (i.e. for SAME_NONZERO_PATTERN,
// DIFFRENT_NONZERO_PATTERN) but it is a guess...
#if(PETSC_VERSION_MAJOR < 3 ||                                                 \
    (PETSC_VERSION_MAJOR == 3 && PETSC_VERSION_MINOR < 5))
#define KSPSetOperators(_ksp, _a, _b, SAME_PRECONDITIONER)                     \
  KSPSetOperators(_ksp, _a, _b, SAME_PRECONDITIONER)
#else
#define SAME_PRECONDITIONER 999
#define KSPSetOperators(_ksp, _a, _b, OPT_PRECON)                              \
  (KSPSetOperators(_ksp, _a, _b),                                              \
   KSPSetReusePreconditioner(_ksp,                                             \
                             PetscBool(OPT_PRECON == SAME_PRECONDITIONER)))
#endif

// Deprecated method PetscViewerSetFormat starts 3.7 the only instance we use
// can be replaced by PetscViewerPushFormat as we do not change the format of
// the same viewer in such a case PetscViewerPopFormat should be used and the
// following will not work
#if(PETSC_VERSION_MAJOR < 3 ||                                                 \
    (PETSC_VERSION_MAJOR == 3 && PETSC_VERSION_MINOR < 7))
#define PetscViewerPushFormat(viewer, format)                                  \
  PetscViewerSetFormat(viewer, format)
#endif

template <class scalar> class linearSystemPETSc : public linearSystem<scalar> {
protected:
  bool _isAllocated, _kspAllocated, _entriesPreAllocated;
  bool _matrixChangedSinceLastSolve;
  bool _valuesNotAssembled; // cannot use MatAssembled since MatAssembled return
                            // false for an empty matrix
  Mat _a;
  Vec _b, _x;
  KSP _ksp;
  PetscInt _localRowStart, _localRowEnd, _localSize, _globalSize;
  sparsityPattern _sparsity;
  void _kspCreate();
  void _assembleMatrixIfNeeded();
#ifndef SWIG
  MPI_Comm _comm;
#endif
  int _getBlockSizeFromParameters() const;

public:
  ~linearSystemPETSc();
  void insertInSparsityPattern(int i, int j);
  bool isAllocated() const { return _isAllocated; }
  void preAllocateEntries();
  virtual void allocate(int nbRows);
  void print();
  void clear();
  void getFromMatrix(int row, int col, scalar &val) const;
  void addToRightHandSide(int row, const scalar &val, int ith = 0);
  void getFromRightHandSide(int row, scalar &val) const;
  double normInfRightHandSide() const;
  int getNumKspIteration() const;
  void addToMatrix(int row, int col, const scalar &val);
  void addToSolution(int row, const scalar &val);
  void getFromSolution(int row, scalar &val) const;
  void zeroMatrix();
  void zeroRightHandSide();
  void zeroSolution();
  void printMatlab(const char *filename) const;
  virtual int systemSolve();
  Mat getMatrix() { return _a; }
  virtual int matMult();
// std::vector<scalar> getData();
// std::vector<int> getRowPointers();
// std::vector<int> getColumnsIndices();
#ifndef SWIG
  linearSystemPETSc(MPI_Comm com);
  MPI_Comm getComm() const { return _comm; }
#endif
  linearSystemPETSc();
};
#else

template <class scalar> class linearSystemPETSc : public linearSystem<scalar> {
public:
  linearSystemPETSc()
  {
    Msg::Error("PETSc is not available in this version of Gmsh");
  }
  bool isAllocated() const { return false; }
  void allocate(int nbRows) {}
  void clear() {}
  void addToMatrix(int row, int col, const scalar &val) {}
  void getFromMatrix(int row, int col, scalar &val) const {}
  void addToRightHandSide(int row, const scalar &val, int ith = 0) {}
  void addToSolution(int row, const scalar &val) {}
  void getFromRightHandSide(int row, scalar &val) const {}
  void getFromSolution(int row, scalar &val) const {}
  int getNumKspIteration() const { return 0; };
  void zeroMatrix() {}
  void zeroRightHandSide() {}
  void zeroSolution() {}
  void printMatlab(const char *filename) const {};
  virtual int systemSolve() { return 0; }
  double normInfRightHandSide() const { return 0; }
  virtual int matMult() { return 0; }
};
#endif
#endif
