// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <stdio.h>
#include <math.h>
#include "linearSystemEigen.h"

#if defined(HAVE_EIGEN)

linearSystemEigen<double>::linearSystemEigen() { solverType = EigenSparseLU; }

bool linearSystemEigen<double>::isAllocated() const
{
  if(A.rows() > 0)
    return true;
  else
    return false;
}

void linearSystemEigen<double>::allocate(int nbRows)
{
  A.resize(nbRows, nbRows);
  B.resize(nbRows);
  X.resize(nbRows);
  B.fill(0.);
  X.fill(0.);
}

void linearSystemEigen<double>::clear()
{
  A.setZero();
  B.setZero();
  X.setZero();
}

void linearSystemEigen<double>::zeroMatrix()
{
  A.setZero();
  B.setZero();
  X.setZero();
}

void linearSystemEigen<double>::zeroRightHandSide() { B.fill(0.); }

void linearSystemEigen<double>::zeroSolution() { X.fill(0.); }

void linearSystemEigen<double>::setSolverType(
  linearSystemEigenSolver solverName)
{
  solverType = solverName;
}

int linearSystemEigen<double>::systemSolve()
{
  if(solverType == EigenCholeskyLLT) {
    Eigen::SimplicialLLT<Eigen::SparseMatrix<double> > solver;
    solver.compute(A);
    if(solver.info() != Eigen::ComputationInfo::Success) {
      Msg::Warning("Eigen: failed to solve linear system with CholeskyLLT");
      return -1;
    }
    X = solver.solve(B);
    if(solver.info() != Eigen::ComputationInfo::Success) {
      Msg::Warning("Eigen: failed to solve linear system with CholeskyLLT");
      return -1;
    }
  }
  else if(solverType == EigenCholeskyLDLT) {
    Eigen::SimplicialLDLT<Eigen::SparseMatrix<double> > solver;
    solver.compute(A);
    if(solver.info() != Eigen::ComputationInfo::Success) {
      Msg::Warning("Eigen: failed to solve linear system with CholeskyLDLT");
      return -1;
    }
    X = solver.solve(B);
    if(solver.info() != Eigen::ComputationInfo::Success) {
      Msg::Warning("Eigen: failed to solve linear system with CholeskyLDLT");
      return -1;
    }
  }
  else if(solverType == EigenSparseLU) {
    Eigen::SparseLU<Eigen::SparseMatrix<double> > solver;
    solver.compute(A);
    if(solver.info() != Eigen::ComputationInfo::Success) {
      Msg::Warning("Eigen: failed to solve linear system with SparseLU");
      return -1;
    }
    X = solver.solve(B);
    if(solver.info() != Eigen::ComputationInfo::Success) {
      Msg::Warning("Eigen: failed to solve linear system with SparseLU");
      return -1;
    }
  }
  else if(solverType == EigenSparseQR) {
    /* Note: maybe another ordering method is better, see Eigen documentation */
    Eigen::SparseQR<Eigen::SparseMatrix<double>, Eigen::NaturalOrdering<int> >
      solver;
    solver.compute(A);
    if(solver.info() != Eigen::ComputationInfo::Success) {
      Msg::Warning("Eigen: failed to solve linear system with SparseQR");
      return -1;
    }
    X = solver.solve(B);
    if(solver.info() != Eigen::ComputationInfo::Success) {
      Msg::Warning("Eigen: failed to solve linear system with SparseQR");
      return -1;
    }
  }
  else if(solverType == EigenCG) {
    Eigen::ConjugateGradient<Eigen::SparseMatrix<double> > solver;
    solver.compute(A);
    if(solver.info() != Eigen::ComputationInfo::Success) {
      Msg::Warning(
        "Eigen: failed to solve linear system with Conjugate Gradient");
      return -1;
    }
    X = solver.solve(B);
    if(solver.info() != Eigen::ComputationInfo::Success) {
      Msg::Warning(
        "Eigen: failed to solve linear system with Conjugate Gradient");
      return -1;
    }
  }
  else if(solverType == EigenCGLeastSquare) {
    Eigen::LeastSquaresConjugateGradient<Eigen::SparseMatrix<double> > solver;
    solver.compute(A);
    if(solver.info() != Eigen::ComputationInfo::Success) {
      Msg::Warning("Eigen: failed to solve linear system with Least Square "
                   "Conjugate Gradient");
      return -1;
    }
    X = solver.solve(B);
    if(solver.info() != Eigen::ComputationInfo::Success) {
      Msg::Warning("Eigen: failed to solve linear system with Least Square "
                   "Conjugate Gradient");
      return -1;
    }
  }
  else if(solverType == EigenBiCGSTAB) {
    Eigen::BiCGSTAB<Eigen::SparseMatrix<double> > solver;
    solver.compute(A);
    if(solver.info() != Eigen::ComputationInfo::Success) {
      Msg::Warning("Eigen: failed to solve linear system with BiCGSTAB");
      return -1;
    }
    X = solver.solve(B);
    if(solver.info() != Eigen::ComputationInfo::Success) {
      Msg::Warning("Eigen: failed to solve linear system with BiCGSTAB");
      return -1;
    }
  }
  return 1;
}

void linearSystemEigen<double>::insertInSparsityPattern(int row, int col) {}

double linearSystemEigen<double>::normInfRightHandSide() const
{
  return B.maxCoeff();
}

double linearSystemEigen<double>::normInfSolution() const
{
  return X.maxCoeff();
}

void linearSystemEigen<double>::addToMatrix(int row, int col, const double &val)
{
  A.coeffRef(row, col) += val; /* slow ! */
}

void linearSystemEigen<double>::getFromMatrix(int row, int col,
                                              double &val) const
{
  val = A.coeff(row, col);
}

void linearSystemEigen<double>::addToRightHandSide(int row, const double &val,
                                                   int ith)
{
  if((int)B.size() <= row) {
    B.resize(row + 1);
    B[row] = val;
  }
  else {
    B[row] += val;
  }
}

void linearSystemEigen<double>::getFromRightHandSide(int row, double &val) const
{
  if((int)B.size() <= row) val = 0.;
  val = B[row];
}

void linearSystemEigen<double>::getFromSolution(int row, double &val) const
{
  if((int)X.size() <= row)
    val = 0.;
  else
    val = X[row];
}

void linearSystemEigen<double>::addToSolution(int row, const double &val)
{
  if((int)X.size() <= row) {
    X.resize(row + 1);
    X[row] = val;
  }
  else {
    X[row] += val;
  }
}

#endif
