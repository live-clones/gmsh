%feature("autodoc", "1");
%module gmshSolver
%include std_string.i
%include std_vector.i
%include std_complex.i
%import "gmshtypemaps.i"

%{
  #undef HAVE_DLOPEN
  #include "GmshConfig.h"
#if defined(HAVE_SOLVER)
  #include "dofManager.h"
  #include "elasticitySolver.h"
  #include "thermicSolver.h"
  #include "frameSolver.h"
  #include "linearSystem.h"
  #include "linearSystemCSR.h"
  #include "linearSystemFull.h"
  #include "linearSystemPETSc.h"
  #include "eigenSolver.h"
#endif
%}

%rename ("_print") *::print;

%include "GmshConfig.h"
#if defined(HAVE_SOLVER)
%include "dofManager.h"
%template(dofManagerDouble) dofManager<double>;
%include "elasticitySolver.h"
%include "thermicSolver.h"
%include "frameSolver.h"
%include "linearSystem.h"
%template(linearSystemDouble) linearSystem<double>;
%template(linearSystemFullMatrixDouble) linearSystem<fullMatrix<double> >;
%include "linearSystemCSR.h"
%template(linearSystemCSRDouble) linearSystemCSR<double>;
%include "linearSystemFull.h"
%template(linearSystemFullDouble) linearSystemFull<double> ;
#if defined(HAVE_PETSC)
#if defined(HAVE_PETSC4PY)
%include petsc4py/petsc4py.i
#endif
%include "linearSystemPETSc.h"
%template(linearSystemPETScDouble) linearSystemPETSc<double>;
%template(linearSystemPETScBlockDouble) linearSystemPETSc<fullMatrix<double> >;
#endif
%template(vectorComplexDouble) std::vector<std::complex<double> >;
%include "eigenSolver.h"
#endif
