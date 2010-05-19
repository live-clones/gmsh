#include "functionDerivator.h"
#include "function.h"

void functionDerivator::compute() {
  _xRef = _x.get();
  _fRef = _f.get();
  _dfdx = fullMatrix<double>(_fRef.size1(),_fRef.size2()*_xRef.size2());
  for (int j=0;j<_xRef.size2();j++) {
    _xDx = _xRef;
    for (int i=0;i<_fRef.size1();i++)
      _xDx(i,j) += _epsilon;
    _x.set()=_xDx;
    const fullMatrix<double> &f = _f.get();
    for (int i=0; i<_fRef.size1(); i++) 
      for (int k=0; k<_fRef.size2(); k++) 
        _dfdx(i, k*_xRef.size2()+j) = (f(i,k)-_fRef(i,k))/_epsilon;
  }
  _x.set()=_xRef;
};
