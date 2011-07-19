#include "functionDerivator.h"
#include "function.h"

const fullMatrix<double> &functionDerivator::compute() {
  const int nbColX = _x.get().size2();
  const double o_eps = 1. / _epsilon;
  _fRef = _f.get();
  _dfdx.resize(_fRef.size1(),_fRef.size2() * nbColX, false);
  for (int j = 0; j < nbColX; ++j) {
    fullMatrix<double> &x =_x.set();
    for (int i=0;i<_fRef.size1();i++)
      x(i,j) += _epsilon;
    const fullMatrix<double> &f = _f.get();
    for (int k=0; k<_fRef.size2(); k++) 
      for (int i=0; i<_fRef.size1(); i++) 
        _dfdx(i, k * nbColX + j) = (f(i,k)-_fRef(i,k)) * o_eps;
    for (int i=0;i<_fRef.size1();i++)
      x(i,j) -= _epsilon;
  }
  _x.set();
  return _dfdx;
};
