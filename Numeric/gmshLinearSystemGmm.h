// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _GMSH_LINEAR_SYSTEM_GMM_H_
#define _GMSH_LINEAR_SYSTEM_GMM_H_

// Interface to GMM++

#include "GmshConfig.h"
#include "GmshMessage.h"
#include "gmshLinearSystem.h"

#if defined(HAVE_GMM)

#include <gmm.h>

template <class scalar>
class gmshLinearSystemGmm : public gmshLinearSystem<scalar> {
 private:
  gmm::row_matrix<gmm::wsvector<scalar> > *_a;
  std::vector<scalar> *_b, *_x;
  double _prec;
  int _noisy, _gmres;
 public:
  gmshLinearSystemGmm()
    : _a(0), _b(0), _x(0), _prec(1.e-8), _noisy(0), _gmres(0) {}
  virtual bool isAllocated() const { return _a != 0; }
  virtual void allocate(int _nbRows)
  {
    if(_a) delete _a;
    if(_x) delete _x;
    if(_b) delete _b;
    _a = new gmm::row_matrix< gmm::wsvector<scalar> >(_nbRows, _nbRows);
    _b = new std::vector<scalar>(_nbRows);
    _x = new std::vector<scalar>(_nbRows);
  }
  virtual ~gmshLinearSystemGmm()
  {
    delete _a;
    delete _b;
    delete _x;
  }
  virtual void  addToMatrix(int _row, int _col, scalar _val) 
  {
    if(_val != 0.0) (*_a)(_row, _col) += _val;
  }
  virtual scalar getFromMatrix (int _row, int _col) const
  {
    return (*_a)(_row, _col);
  }
  virtual void addToRightHandSide(int _row, scalar _val) 
  {
    if(_val != 0.0) (*_b)[_row] += _val;
  }
  virtual scalar getFromRightHandSide(int _row) const 
  {
    return (*_b)[_row];
  }
  virtual scalar getFromSolution(int _row) const
  {
    return (*_x)[_row];
  }
  virtual void zeroMatrix()
  {
    gmm::clear(*_a);
  }
  virtual void zeroRightHandSide() 
  {
    for(unsigned int i = 0; i < _b->size(); i++) (*_b)[i] = 0.;
  }
  void setPrec(double p){ _prec = p; }
  void setNoisy(int n){ _noisy = n; }
  void setGmres(int n){ _gmres = n; }
  virtual int systemSolve() 
  {
    //gmm::ilutp_precond<gmm::row_matrix<gmm::wsvector<scalar> > > P(*_a, 15, 0.);
    gmm::ildltt_precond<gmm::row_matrix<gmm::wsvector<scalar> > > P(*_a, 10, 1.e-10);
    gmm::iteration iter(_prec);
    iter.set_noisy(_noisy);
    if(_gmres) gmm::gmres(*_a, *_x, *_b, P, 100, iter);
    else gmm::cg(*_a, *_x, *_b, P, iter);
    return 1;
  }
};

#else

template <class scalar>
class gmshLinearSystemGmm : public gmshLinearSystem<scalar> {
public :
  gmshLinearSystemGmm()
  {
    Msg::Error("Gmm++ is not available in this version of Gmsh");
  }
  virtual bool isAllocated() const { return false; }
  virtual void allocate(int nbRows) {}
  virtual void addToMatrix(int _row, int _col, scalar val) {}
  virtual scalar getFromMatrix(int _row, int _col) const { return 0.; }
  virtual void addToRightHandSide(int _row, scalar val) {}
  virtual scalar getFromRightHandSide(int _row) const { return 0.; }
  virtual scalar getFromSolution(int _row) const { return 0.; }
  virtual void zeroMatrix() {}
  virtual void zeroRightHandSide() {}
  virtual int systemSolve() { return 0; }
  void setPrec(double p){}
  void setNoisy(int n){}
  void setGmres(int n){}
};

#endif

#endif
