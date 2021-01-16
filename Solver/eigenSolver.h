// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef EIGEN_SOLVER_H
#define EIGEN_SOLVER_H

#include <string>
#include <complex>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "dofManager.h"

#if defined(HAVE_SLEPC)

#include "linearSystemPETSc.h"

class eigenSolver {
private:
  linearSystemPETSc<double> *_sysA, *_sysB;
  bool _hermitian;
  std::vector<std::complex<double> > _eigenValues;
  std::vector<std::vector<std::complex<double> > > _eigenVectors;
  void _check(int ierr) const;

public:
  eigenSolver(dofManager<double> *manager, std::string A, std::string B = "",
              bool hermitian = true);
  eigenSolver(linearSystemPETSc<double> *A, linearSystemPETSc<double> *B = NULL,
              bool hermitian = true);
  bool solve(int numEigenValues = 0, std::string which = "",
             std::string method = "krylovschur", double tolVal = 1.e-7,
             int iterMax = 20);

  int getNumEigenValues() { return _eigenValues.size(); }
  int getNumberEigenvectors() { return _eigenVectors.size(); }

  std::complex<double> getEigenValue(int num) { return _eigenValues[num]; }
  std::complex<double> getEigenVectorComp(int num, int com)
  {
    return _eigenVectors[num][com];
  };
  std::vector<std::complex<double> > &getEigenVector(int num)
  {
    return _eigenVectors[num];
  }

  void normalize_mode(std::vector<int> modeView, double scale = 1.);

  void clear()
  {
    _eigenValues.clear();
    _eigenVectors.clear();
  };
};

#else

#include "linearSystemPETSc.h"

class eigenSolver {
private:
  std::vector<std::complex<double> > _dummy;

public:
  eigenSolver(dofManager<double> *manager, std::string A, std::string B = "",
              bool hermitian = false)
  {
  }
  eigenSolver(linearSystemPETSc<double> *A, linearSystemPETSc<double> *B = nullptr,
              bool hermitian = false)
  {
  }
  bool solve(int = 0, std::string = "", std::string = "", double = 0, int = 0)
  {
    Msg::Error("Eigen solver requires SLEPc");
    return false;
  }
  int getNumEigenValues() { return 0; }
  int getNumberEigenvectors() { return 0; }
  std::complex<double> getEigenValue(int num) { return 0.; }
  std::complex<double> getEigenVectorComp(int num, int com) { return 0.; }
  std::vector<std::complex<double> > &getEigenVector(int num) { return _dummy; }
  void normalize_mode(std::vector<int> modeView, double scale = 1.) {}
  void clear() {}
};

#endif

#endif
