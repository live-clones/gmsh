// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef LINEAR_SYSTEM_MUMPS2_H
#define LINEAR_SYSTEM_MUMPS2_H

// Interface to a linear system with MUMPS

#include "GmshConfig.h"
#include "GmshMessage.h"
#include "linearSystem.h"

#if defined(HAVE_MUMPS)
#include "dmumps_c.h"
#include "zmumps_c.h"

template <class scalar> class linearSystemMUMPS2 : public linearSystem<scalar> {
public:
  linearSystemMUMPS2()
  {
    Msg::Info("linearSystemMUMPS2 not implemented for this element type");
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

template <> class linearSystemMUMPS2<double> : public linearSystem<double> {
private:
  int _n;
  int _nz;

  std::vector<int> _irn;
  std::vector<int> _jcn;

  std::vector<DMUMPS_REAL> _x;
  std::vector<DMUMPS_REAL> _b;
  std::vector<DMUMPS_REAL> _a;

  // _ij[i][j] is the index of _a that is the (i, j) element of
  // the system matrix
  std::vector<std::map<int, int> > _ij;

  DMUMPS_STRUC_C id;

public:
  linearSystemMUMPS2();

  virtual bool isAllocated() const;
  virtual void allocate(int nbRows);
  virtual void clear();
  virtual void zeroMatrix();

  virtual void zeroRightHandSide();
  virtual void zeroSolution();
  virtual int systemFactorize();
  virtual int systemComputeSolution();
  virtual int systemSolve();
  virtual int systemDestroy();
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
