#include "functionDerivator.h"
#include "function.h"

const fullMatrix<double> &functionDerivator::compute() {
  _xRef = _x.get();
  _fRef = _f.get();
  _dfdx.resize(_fRef.size1(),_fRef.size2()*_xRef.size2(), false);
  for (int j=0;j<_xRef.size2();j++) {
    fullMatrix<double> &x =_x.set();
    for (int i=0;i<_fRef.size1();i++)
      x(i,j) += _epsilon;
    const fullMatrix<double> &f = _f.get();
    for (int k=0; k<_fRef.size2(); k++) 
      for (int i=0; i<_fRef.size1(); i++) 
        _dfdx(i, k*_xRef.size2()+j) = (f(i,k)-_fRef(i,k))/_epsilon;
    for (int i=0;i<_fRef.size1();i++)
      x(i,j) = _xRef(i,j);
  }
  _x.set();
  return _dfdx;
};
