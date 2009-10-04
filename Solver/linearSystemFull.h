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
  virtual void allocate(int nbRows)
  {
    clear();
    _a = new fullMatrix<scalar>(nbRows, nbRows);
    _b = new fullVector<scalar>(nbRows);
    _x = new fullVector<scalar>(nbRows);
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
  virtual void addToMatrix(int row, int col, scalar val)
  {
    if(val != 0.0) (*_a)(row, col) += val;
  }
  virtual scalar getFromMatrix(int row, int col) const
  {
    return (*_a)(row, col);
  }
  virtual void addToRightHandSide(int row, scalar val)
  {
    if(val != 0.0) (*_b)(row) += val;
  }
  virtual scalar getFromRightHandSide(int row) const 
  {
    return (*_b)(row);
  }
  virtual scalar getFromSolution(int row) const 
  {
    return (*_x)(row);
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
    return 1;
  }
};

#endif
