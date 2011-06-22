%feature("autodoc", "1");
%module gmshPost
%include std_string.i

%{
  #include "GmshConfig.h"

  #include "fullMatrix.h"
  #include "PView.h"
  #include "PViewData.h"
  #include "PViewFactory.h"
%}

%include "GmshConfig.h"

%include "PView.h"
%include "PViewData.h"
%include "PViewFactory.h"
