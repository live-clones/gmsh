#ifndef _FUNCTION_DERIVATOR_H_
#define _FUNCTION_DERIVATOR_H_

#include "fullMatrix.h"
#include "function.h"

class functionDerivator {
  dataCacheDouble &_f,&_x;
  fullMatrix<double> _fRef, _xRef,_xDx, _dfdx;
  double _epsilon;
  public:
  functionDerivator (dataCacheDouble &f, dataCacheDouble &x, double epsilon):
    _f(f),
    _x(x),
    _epsilon(epsilon)
    {}
  void compute();
  inline double get(int iQP, int iF, int iX) 
  {
    return _dfdx(iQP, iF*_xRef.size2()+iX);
  }
};

#endif
