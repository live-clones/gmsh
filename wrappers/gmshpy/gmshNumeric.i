%feature("autodoc", "1");
%module gmshNumeric

%include std_string.i
%include std_vector.i

%{
  #include "GmshConfig.h"

  #include "DivideAndConquer.h"
  #include "GaussIntegration.h"
  #include "JacobianBasis.h"
  #include "fullMatrix.h"
  #include "polynomialBasis.h"
%}

%include "DivideAndConquer.h"
%include "GaussIntegration.h"
%include "JacobianBasis.h"  
%include "fullMatrix.h"
%template(fullMatrixDouble) fullMatrix<double>;
%template(fullVectorDouble) fullVector<double>;
%include "polynomialBasis.h"
