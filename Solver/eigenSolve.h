// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _EIGEN_SOLVE_H_
#define _EIGEN_SOLVE_H_

#include <string>
#include <complex>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "dofManager.h"

#if defined(HAVE_SLEPC)

#include "linearSystemPETSc.h"
#include <slepc.h>

class eigenSolve{
 private:
  linearSystemPETSc<double> *_A, *_B;
  std::vector<std::complex<double> > _eigenValues;
  std::vector<std::vector<std::complex<double> > > _eigenVectors;
  void _try(int ierr) const { CHKERRABORT(PETSC_COMM_WORLD, ierr); }
 public:
  eigenSolve(dofManager<double, double> *manager, std::string A, 
             std::string B="");
  void solve();
  std::complex<double> getEigenValue(int num){ return _eigenValues[num]; }
  std::vector<std::complex<double> > &getEigenVector(int num){ return _eigenVectors[num]; }
};

#else

class eigenSolve{
 private:
  std::vector<std::complex<double> > _dummy;
 public:
  eigenSolve(dofManager<double, double> *manager, std::string A, 
             std::string B=""){}
  void solve(){ Msg::Error("Eigen solver requires SLEPc"); }
  std::complex<double> getEigenValue(int num){ return 0.; }
  std::vector<std::complex<double> > &getEigenVector(int num){ return _dummy; }
};

#endif

#endif
