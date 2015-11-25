%feature("autodoc", "1");
%module gmshNumeric
#pragma SWIG nowarn=325

%include std_string.i
%include std_vector.i
%import "gmshtypemaps.i"

%{
  #undef HAVE_DLOPEN
  #include "GmshConfig.h"

  #include "GaussIntegration.h"
  #include "JacobianBasis.h"
  #include "fullMatrix.h"
  #include "nodalBasis.h"
  #include "BasisFactory.h"
  #include "CondNumBasis.h"
  #include "simpleFunction.h"
  #include "simpleFunctionPython.h"
  #include "polynomialBasis.h"
  #include "pyramidalBasis.h"
%}

%rename("_operator_assign") *::operator=;
%rename("_print") *::print;
%include "GaussIntegration.h"
%include "JacobianBasis.h"
%ignore fullMatrix<double>::operator()(int, int);
%ignore fullVector<double>::operator()(int);
%include "fullMatrix.h"
%include "simpleFunction.h"
%template(fullMatrixDouble) fullMatrix<double>;
%template(fullVectorDouble) fullVector<double>;
%template(simpleFunctionDouble) simpleFunction<double>;
%include "simpleFunctionPython.h"
%include "nodalBasis.h"
%include "polynomialBasis.h"
%include "pyramidalBasis.h"
%include "BasisFactory.h"
%include "CondNumBasis.h"
%extend nodalBasis {
  fullMatrix<double> F(const fullMatrix<double> &xi) {
    fullMatrix<double> psi;
    $self->f(xi, psi);
    return psi;
  }
  fullMatrix<double> DF(const fullMatrix<double> &xi) {
    fullMatrix<double> dpsi;
    $self->df(xi, dpsi);
    return dpsi;
  }
}
