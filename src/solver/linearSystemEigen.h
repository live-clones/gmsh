// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef LINEAR_SYSTEM_EIGEN_H
#define LINEAR_SYSTEM_EIGEN_H

// Interface to solve a linear system with Eigen

#include "GmshConfig.h"
#include "GmshMessage.h"
#include "linearSystem.h"

#if defined(HAVE_EIGEN)

#include <Eigen/Sparse>

template <class scalar> class linearSystemEigen : public linearSystem<scalar> {
public:
  linearSystemEigen()
  {
    Msg::Info("linearSystemEigen not implemented for this element type");
  }

  virtual bool isAllocated() const { return false; }
  virtual void allocate(int nbRows) {}
  virtual void clear() {}
  virtual void zeroMatrix() {}
  virtual void zeroRightHandSide() {}
  virtual void zeroSolution() {}
  virtual int systemSolve() { return 1; }
  virtual void insertInSparsityPattern(int row, int col) {}
  virtual double normInfRightHandSide() const { return 0.; }
  virtual double normInfSolution() const { return 0.; }

  virtual void addToMatrix(int row, int col, const double &val) {}
  virtual void getFromMatrix(int row, int col, double &val) const {}
  virtual void addToRightHandSide(int row, const scalar &val, int ith = 0) {}
  virtual void getFromRightHandSide(int row, scalar &val) const {}
  virtual void getFromSolution(int row, scalar &val) const {}
  virtual void addToSolution(int row, const scalar &val) {}
};

enum linearSystemEigenSolver {
  EigenCholeskyLLT,
  EigenCholeskyLDLT,
  EigenSparseLU,
  EigenSparseQR,
  /* warning: no preconditionner for iterative solver by default, should be
     changed */
  EigenCG,
  EigenCGLeastSquare,
  EigenBiCGSTAB
};

template <> class linearSystemEigen<double> : public linearSystem<double> {
private:
  Eigen::VectorXd X;
  Eigen::VectorXd B;
  Eigen::SparseMatrix<double> A;
  linearSystemEigenSolver solverType;

public:
  linearSystemEigen();

  void setSolverType(linearSystemEigenSolver solverName);

  virtual bool isAllocated() const;
  virtual void allocate(int nbRows);
  virtual void clear();
  virtual void zeroMatrix();

  virtual void zeroRightHandSide();
  virtual void zeroSolution();
  virtual int systemSolve();
  virtual void insertInSparsityPattern(int row, int col);
  virtual double normInfRightHandSide() const;
  virtual double normInfSolution() const;

  virtual void addToMatrix(int row, int col, const double &val);
  virtual void getFromMatrix(int row, int col, double &val) const;
  virtual void addToRightHandSide(int row, const double &val, int ith = 0);
  virtual void getFromRightHandSide(int row, double &val) const;
  virtual void getFromSolution(int row, double &val) const;
  virtual void addToSolution(int row, const double &val);
};

#endif

#endif
