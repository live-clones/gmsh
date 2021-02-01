// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <stdio.h>
#include <math.h>
#include "linearSystemMUMPS.h"

#if defined(HAVE_MUMPS)

#define USE_COMM_WORLD -987654

void mumpserror(int id, int subid)
{
  if(id < 0) {
    Msg::Error("MUMPS INFO(1) = %d, INFO(2) = %d", id, subid);

    switch(id) {
    case -6:
      Msg::Error("Matrix is singular in structure, structural rank: %d", subid);
      break;
    case -10: Msg::Error("Matrix is numerically singular"); break;
    case -13: Msg::Error("Not enough memory"); break;
    case -40: Msg::Error("Matrix is not symmetric positive definite"); break;
    default: Msg::Error("Check MUMPS user's guide"); break;
    }
  }
}

linearSystemMUMPS<double>::linearSystemMUMPS()
{
  _n = 0;
  _nz = 0;
}

bool linearSystemMUMPS<double>::isAllocated() const
{
  if(_n > 0)
    return true;
  else
    return false;
}

void linearSystemMUMPS<double>::allocate(int nbRows)
{
  _n = nbRows;
  _b.resize(_n);
  _x.resize(_n);
  _a.reserve(10 * _n);
  _irn.reserve(10 * _n);
  _jcn.reserve(10 * _n);
  _ij.reserve(_n);
}

void linearSystemMUMPS<double>::clear()
{
  _x.clear();
  _a.clear();
  _b.clear();
  _n = 0;
  _nz = 0;
  _irn.clear();
  _jcn.clear();
  _ij.clear();
}

void linearSystemMUMPS<double>::zeroMatrix()
{
  _nz = 0;
  _a.clear();
  _ij.clear();
  _irn.clear();
  _jcn.clear();
}

void linearSystemMUMPS<double>::zeroRightHandSide()
{
  for(std::size_t i = 0; i < _b.size(); i++) _b[i] = 0.;
}

void linearSystemMUMPS<double>::zeroSolution()
{
  for(std::size_t i = 0; i < _x.size(); i++) _x[i] = 0.;
}

int linearSystemMUMPS<double>::systemSolve()
{
  // MUMPS will overwrite _b with the solution
  std::vector<DMUMPS_REAL> b = _b;

  DMUMPS_STRUC_C id;

  id.par = 1;
  const std::string sym = getParameter("symmetry");
  if(sym == "spd")
    id.sym = 1;
  else if(sym == "symmetric")
    id.sym = 2;
  else
    id.sym = 0;

  id.comm_fortran = USE_COMM_WORLD;

  Msg::Debug("MUMPS initialization");
  id.job = -1;
  dmumps_c(&id);
  mumpserror(id.info[0], id.info[1]);

  id.n = _n;
  id.nz = _nz;
  // Fortran indices start from 1
  for(std::size_t i = 0; i < _irn.size(); i++) _irn[i]++;
  for(std::size_t i = 0; i < _jcn.size(); i++) _jcn[i]++;
  id.irn = &*_irn.begin();
  id.jcn = &*_jcn.begin();
  id.a = &*_a.begin();
  id.rhs = &*_b.begin();

  // Fortran indices start from 1
  id.icntl[1 - 1] = -1;
  id.icntl[2 - 1] = -1;
  id.icntl[3 - 1] = -1;
  id.icntl[4 - 1] = 0;
  id.icntl[5 - 1] = 0;
  id.icntl[18 - 1] = 0;

  Msg::Debug("MUMPS analysis, LU factorization, and back substitution");
  id.job = 6;
  dmumps_c(&id);
  mumpserror(id.info[0], id.info[1]);

  Msg::Debug("MUMPS destroy");
  id.job = -2;
  dmumps_c(&id);
  Msg::Debug("MUMPS end");
  mumpserror(id.info[0], id.info[1]);

  _x.clear();
  _x = _b;
  _b = b;
  for(std::size_t i = 0; i < _irn.size(); i++) _irn[i]--;
  for(std::size_t i = 0; i < _jcn.size(); i++) _jcn[i]--;

  return 1;
}

void linearSystemMUMPS<double>::insertInSparsityPattern(int row, int col) {}

double linearSystemMUMPS<double>::normInfRightHandSide() const
{
  DMUMPS_REAL norm = 0.;
  for(std::size_t i = 0; i < _b.size(); i++) {
    DMUMPS_REAL temp = fabs(_b[i]);
    if(temp > norm) norm = temp;
  }
  return norm;
}

double linearSystemMUMPS<double>::normInfSolution() const
{
  DMUMPS_REAL norm = 0.;
  for(std::size_t i = 0; i < _x.size(); i++) {
    DMUMPS_REAL temp = fabs(_x[i]);
    if(temp > norm) norm = temp;
  }
  return norm;
}

void linearSystemMUMPS<double>::addToMatrix(int row, int col, const double &val)
{
  // MUMPS will sum entries with duplicate (row, col)
  /*_a.push_back(val);
  _irn.push_back(row);
  _jcn.push_back(col);
  _nz++;*/
  if((int)_ij.size() <= row) {
    _a.push_back(val);
    _irn.push_back(row);
    _jcn.push_back(col);
    _ij.resize(row + 1);
    _ij[row][col] = _a.size() - 1;
    _nz++;
    return;
  }
  auto it = _ij[row].find(col);
  if(it == _ij[row].end()) {
    _a.push_back(val);
    _irn.push_back(row);
    _jcn.push_back(col);
    _ij[row][col] = _a.size() - 1;
    _nz++;
  }
  else {
    _a[it->second] += val;
  }
}

void linearSystemMUMPS<double>::getFromMatrix(int row, int col,
                                              double &val) const
{
  // Msg::Error("getFromMatrix not implemented for linearSystemMUMPS");
  if((int)_ij.size() <= row) {
    val = 0.;
    return;
  }
  auto it = _ij[row].find(col);
  if(it == _ij[row].end())
    val = 0.;
  else
    val = _a[it->second];
}

void linearSystemMUMPS<double>::addToRightHandSide(int row, const double &val,
                                                   int ith)
{
  //  printf("adding %g to %d\n",val,row);
  if((int)_b.size() <= row) {
    _b.resize(row + 1);
    _b[row] = val;
  }
  else {
    _b[row] += val;
  }
}

void linearSystemMUMPS<double>::getFromRightHandSide(int row, double &val) const
{
  if((int)_b.size() <= row) val = 0.;
  val = _b[row];
}

void linearSystemMUMPS<double>::getFromSolution(int row, double &val) const
{
  //  printf("x[%d] = %g\n",row,_x[row]);
  if((int)_x.size() <= row)
    val = 0.;
  else
    val = _x[row];
}

void linearSystemMUMPS<double>::addToSolution(int row, const double &val)
{
  if((int)_x.size() <= row) {
    _x.resize(row + 1);
    _x[row] = val;
  }
  else {
    _x[row] += val;
  }
}

#endif
