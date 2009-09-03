// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _GMSH_LINEAR_SYSTEM_FULL_H_
#define _GMSH_LINEAR_SYSTEM_FULL_H_

// Interface to a linear system with a FULL matrix

#include "GmshMessage.h"
#include "gmshLinearSystem.h"
#include "GmshMatrix.h"
#include <stdlib.h>
#include <set>

template <class scalar>
class gmshLinearSystemFull : public gmshLinearSystem<scalar> {
 private:
  gmshMatrix<scalar> *_a;
  gmshVector<scalar> *_b, *_x;
 public :
  gmshLinearSystemFull() : _a(0), _b(0), _x(0){}
  virtual bool isAllocated() const { return _a != 0; }
  virtual void allocate(int _nbRows)
  {
    clear();
    _a = new gmshMatrix<scalar>(_nbRows, _nbRows);
    _b = new gmshVector<scalar>(_nbRows);
    _x = new gmshVector<scalar>(_nbRows);
  }

  virtual ~gmshLinearSystemFull()
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
  virtual int checkSystem() 
  {
    //a->print("myMatrix");
    //_b->print("myVector");

    int nbNonConvex=0;
    for(int i = 0; i < _b->size(); i++){

      double diag = (*_a)(i, i);
      double offDiag = 0.0;
      bool convex = true;
      std::set<int> Ni;
      for(int j = 0; j < _b->size(); j++){
        if ( (j !=i) &&  (*_a)(i, j)  > 0.0 ) convex = false;
        if (  j !=i && (*_a)(i, j) != 0.0){
          offDiag += (*_a)(i, j);
          Ni.insert(j);
        }
      }
      if (fabs(offDiag+diag) > 1.e-10 && fabs(offDiag) > 1.e-10 ) convex= false;
     
      if (convex == false){
        nbNonConvex+=1;
        printf("*** WARNING NON CONVEX LINE !!!!!\n");
        printf("*** i=%d : diag=%g offDiag=%g diff=%g convex=%s size Ni=%d\n", i , diag, offDiag, fabs(offDiag+diag), (convex)?"true":"false", Ni.size());
        for (std::set<int>::iterator it = Ni.begin(); it != Ni.end(); ++it)   (*_a)(i, *it) = -1.0;
        (*_a)(i, i) = Ni.size();
      }
    }

    printf("nonConvex=%d total=%d ratio=%g\n ",nbNonConvex, _b->size(), nbNonConvex/(double)_b->size());
    //_a->print("myMatrix AFTER !!! ");

    return 1;
  }
};

#endif
