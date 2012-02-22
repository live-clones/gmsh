%feature("autodoc", "1");
%module gmshSolver
%include std_string.i
%include std_vector.i
%import "gmshCommon.i"
%import "gmshNumeric.i"

%{
  #include "GmshConfig.h"
  #include "dofManager.h"
  #include "elasticitySolver.h"
  #include "linearSystem.h"
  #include "linearSystemCSR.h"
  #include "linearSystemFull.h"
  #include "linearSystemPETSc.h"
%}

%include "GmshConfig.h"

%include "dofManager.h"
%template(dofManagerDouble) dofManager<double>;
%include "elasticitySolver.h"
%include "linearSystem.h"
%template(linearSystemDouble) linearSystem<double>;
%template(linearSystemFullMatrixDouble) linearSystem<fullMatrix<double> >;
%include "linearSystemCSR.h"
%template(linearSystemCSRDouble) linearSystemCSR<double>;
%template(linearSystemTAUCSDouble) linearSystemCSRTaucs<double>;
%include "linearSystemFull.h"
%template(linearSystemFullDouble) linearSystemFull<double> ;
#ifdef HAVE_PETSC
%include "linearSystemPETSc.h"
%template(linearSystemPETScDouble) linearSystemPETSc<double>;
#endif
