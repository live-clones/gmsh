%feature("autodoc", "1");
%module gmshNumeric

%include std_string.i
%include std_vector.i
%import "gmshtypemaps.i"

%{
  #include "GmshConfig.h"

  #include "GaussIntegration.h"
  #include "JacobianBasis.h"
  #include "fullMatrix.h"
  #include "nodalBasis.h"
  #include "BasisFactory.h"
  #include "simpleFunction.h"
  #include "simpleFunctionPython.h"
  #include "polynomialBasis.h"
  #include "pyramidalBasis.h"
%}

%rename("_assign=") operator();
%rename("_assign_operator=") operator=;
%include "GaussIntegration.h"
%include "JacobianBasis.h"
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
