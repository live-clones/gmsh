%feature("autodoc", "1");
%module gmshNumeric

%include std_string.i
%include std_vector.i

%{
  #include "GmshConfig.h"

  #include "GaussIntegration.h"
  #include "JacobianBasis.h"
  #include "fullMatrix.h"
  #include "nodalBasis.h"
  #include "simpleFunction.h"
  #include "simpleFunctionPython.h"
  #include "polynomialBasis.h"
  #include "pyramidalBasis.h"
%}

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
