// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
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
#include "petsc.h"
#include <petscksp.h>
template <class scalar>
class linearSystemPETSc : public linearSystem<scalar> {
  protected:
  MPI_Comm _comm;
  int _blockSize; // for block Matrix
  bool _isAllocated, _kspAllocated, _entriesPreAllocated, _matrixModified;
  Mat _a;
  Vec _b, _x;
  KSP _ksp;
  int _localRowStart, _localRowEnd, _localSize, _globalSize;
  sparsityPattern _sparsity;
  void _kspCreate();
 public:
  linearSystemPETSc(MPI_Comm com = PETSC_COMM_WORLD);
  virtual ~linearSystemPETSc();
  void insertInSparsityPattern (int i, int j);
  virtual bool isAllocated() const { return _isAllocated; }
  virtual void preAllocateEntries();
  virtual void allocate(int nbRows);
  void print();
  virtual void clear();
  virtual void getFromMatrix(int row, int col, scalar &val) const;
  virtual void addToRightHandSide(int row, const scalar &val);
  virtual void getFromRightHandSide(int row, scalar &val) const;
  virtual double normInfRightHandSide() const;
  virtual void addToMatrix(int row, int col, const scalar &val);
  virtual void addToSolution(int row, const scalar &val);
  virtual void getFromSolution(int row, scalar &val) const;
  virtual void zeroMatrix();
  virtual void zeroRightHandSide();
  virtual void zeroSolution();
  virtual int systemSolve();
  Mat &getMatrix(){ return _a; }
  std::vector<scalar> getData();
  std::vector<int> getRowPointers();
  std::vector<int> getColumnsIndices();
};

class linearSystemPETScBlockDouble : public linearSystem<fullMatrix<double> > {
  bool _entriesPreAllocated, _isAllocated, _kspAllocated, _matrixModified;
  sparsityPattern _sparsity;
  Mat _a;
  Vec _b, _x;
  KSP _ksp;
  int _blockSize, _localRowStart, _localRowEnd, _globalSize, _localSize;
  bool _sequential;
  public:
  void _kspCreate();
  void print();
  virtual void addToMatrix(int row, int col, const fullMatrix<double> &val);
  virtual void addToRightHandSide(int row, const fullMatrix<double> &val);
  virtual void addToSolution(int row,  const fullMatrix<double> &val);
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
  void zeroSolution();
  double normInfRightHandSide() const;
  void insertInSparsityPattern (int i, int j);
  linearSystemPETScBlockDouble(bool sequential = false);
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
  virtual void addToSolution(int row, const scalar &val) {}
  virtual void getFromRightHandSide(int row, scalar &val) const {}
  virtual void getFromSolution(int row, scalar &val) const {}
  virtual void zeroMatrix() {}
  virtual void zeroRightHandSide() {}
  virtual void zeroSolution() {}
  virtual int systemSolve() { return 0; }
  virtual double normInfRightHandSide() const{return 0;}
};
#endif
#endif
