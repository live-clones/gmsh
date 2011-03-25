%{
  #include "mlaw.h"
  #include "simpleFunction.h"
  #include "timeFunction.h"
  #include "nonLinearBC.h"
  #include "partDomain.h"
  #include "contactDomain.h"
  #include "nonLinearMechSolver.h"
%}
%nodefaultctor materialLaw;
%nodefaultctor partDomain;
%nodefaultctor dgPartDomain;
%nodefaultctor contactDomain;
%nodefaultctor rigidCylinderContactDomain;
%include "mlaw.h"
%include "simpleFunction.h"
%include "timeFunction.h"
%include "nonLinearBC.h"
%include "partDomain.h"
%include "contactDomain.h"
%include "nonLinearMechSolver.h"
%template(doubleSimpleFunction) simpleFunction<double>;
%template(doubleSimpleFunctionTime) simpleFunctionTime<double>;
