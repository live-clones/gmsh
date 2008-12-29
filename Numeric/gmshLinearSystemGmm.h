// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _GMSH_LINEAR_SYSTEM_GMM_H_
#define _GMSH_LINEAR_SYSTEM_GMM_H_

// Interface to GMM++

#include "GmshMessage.h"
#include "gmshLinearSystem.h"

#if defined(HAVE_GMM)

#include <gmm.h>

class gmshLinearSystemGmm : public gmshLinearSystem {
  gmm::row_matrix<gmm::wsvector<double> > *_a;
  std::vector<double> *_b, *_x;
  double _prec;
  int _noisy;
  int _gmres;
public :
  gmshLinearSystemGmm () : _a(0), _b(0), _x(0), _prec(1.e-8), _noisy(0), _gmres(0) {}
  virtual bool isAllocated () const {return _a != 0;}
  virtual void allocate (int _nbRows)
  {
    if (_a) delete _a;
    if (_x) delete _x;
    if (_b) delete _b;
    _a = new  gmm::row_matrix< gmm::wsvector<double> >(_nbRows,_nbRows);
    _b = new  std::vector<double>(_nbRows);
    _x = new  std::vector<double>(_nbRows);    
  }
  virtual ~gmshLinearSystemGmm ()
  {
    delete _a;
    delete _b;
    delete _x;
  }
  virtual void  addToMatrix    (int _row, int _col, double _val) 
  {
    if (_val != 0.0) (*_a)(_row, _col) += _val;
  }
  virtual double getFromMatrix (int _row, int _col) const
  {
    return (*_a)(_row, _col);
  }
  virtual void  addToRightHandSide    (int _row, double _val) 
  {
    if (_val != 0.0) (*_b)[_row]+=_val;
  }
  virtual double getFromRightHandSide (int _row) const 
  {
    return (*_b)[_row];
  }
  virtual double getFromSolution (int _row) const 
  {
    return (*_x)[_row];
  }
  virtual void zeroMatrix () 
  {
    gmm::clear(*_a);
  }
  virtual void zeroRightHandSide () 
  {
    for (unsigned int i = 0; i < _b->size(); i++) (*_b)[i] = 0;
  }
  void setPrec(double p){_prec=p;}
  void setNoisy(int n){_noisy=n;}
  void setGmres(int n){_gmres=n;}
  virtual int systemSolve () 
  {
    // gmm::ilutp_precond< gmm::row_matrix< gmm::rsvector<double> > > P(*_a, 10,0.);
    gmm::ildltt_precond< gmm::row_matrix< gmm::wsvector<double> > > P(*_a, 2, 1.e-10);
    gmm::iteration iter(_prec);  // defines an iteration object, with a max residu of 1E-8
    iter.set_noisy(_noisy);
    if (_gmres)gmm::gmres(*_a, *_x, *_b, P, 100, iter);  // execute the GMRES algorithm
    else gmm::cg(*_a, *_x, *_b, P, iter);  // execute the CG algorithm
    return 1;
  }
};

#else

class gmshLinearSystemGmm : public gmshLinearSystem {
public :
  gmshLinearSystemGmm ()
  {
    Msg::Error("Gmm++ is not available on this version of gmsh");
  }
  virtual bool isAllocated () const { return false; }
  virtual void allocate (int nbRows) {}
  virtual void  addToMatrix    (int _row, int _col, double val) {}
  virtual double getFromMatrix (int _row, int _col) const { return 0.; }
  virtual void  addToRightHandSide    (int _row, double val) {}
  virtual double getFromRightHandSide (int _row) const { return 0.; }
  virtual double getFromSolution (int _row) const { return 0.; }
  virtual void zeroMatrix () {}
  virtual void zeroRightHandSide () {}
  virtual int systemSolve () { return 0; }
};

#endif
#endif
