%feature("autodoc", "1");
%module gmshPost
%include typemaps.i
%include std_string.i

%{
  #include "GmshConfig.h"
  #include "fullMatrix.h"
  #include "PView.h"
  #include "PViewFactory.h"
  #include "PViewData.h"
%}

%include "GmshConfig.h"
%include "PView.h"

%include "PViewFactory.h"

%apply double &OUTPUT { double &val}
%include "PViewData.h"

