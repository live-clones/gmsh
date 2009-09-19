// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _LINEAR_SYSTEM_FULL_H_
#define _LINEAR_SYSTEM_FULL_H_

// Interface to a linear system with a FULL matrix

#include "GmshMessage.h"
#include "linearSystem.h"
#include "fullMatrix.h"
#include <stdlib.h>
#include <set>

template <class scalar>
class linearSystemFull : public linearSystem<scalar> {
 private:
  fullMatrix<scalar> *_a;
  fullVector<scalar> *_b, *_x;
 public :
  linearSystemFull() : _a(0), _b(0), _x(0){}
  virtual bool isAllocated() const { return _a != 0; }
  virtual void allocate(int _nbRows)
  {
    clear();
    _a = new fullMatrix<scalar>(_nbRows, _nbRows);
    _b = new fullVector<scalar>(_nbRows);
    _x = new fullVector<scalar>(_nbRows);
  }
  virtual ~linearSystemFull()
  {
    clear();
  }
  virtual void clear()
  {
    if(_a){
      delete _a;
      delete _b;
      delete _x;
    }
    _a = 0;
  }
  virtual void addToMatrix(int _row, int _col, scalar _val)
  {
    if(_val != 0.0) (*_a)(_row, _col) += _val;
  }
  virtual scalar getFromMatrix(int _row, int _col) const
  {
    return (*_a)(_row, _col);
  }
  virtual void addToRightHandSide(int _row, scalar _val)
  {
    if(_val != 0.0) (*_b)(_row) += _val;
  }
  virtual scalar getFromRightHandSide(int _row) const 
  {
    return (*_b)(_row);
  }
  virtual scalar getFromSolution(int _row) const 
  {
    return (*_x)(_row);
  }
  virtual void zeroMatrix() 
  {
    _a->set_all(0.);
  }
  virtual void zeroRightHandSide()
  {
    for(int i = 0; i < _b->size(); i++) (*_b)(i) = 0.;
  }
  virtual int systemSolve() 
  {
    if (_b->size())
      _a->lu_solve(*_b, *_x);
    // _x->print("********* mySol");
    return 1;
  }
};

#endif
