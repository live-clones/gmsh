%feature("autodoc", "1");
%module gmshPost
%include typemaps.i
%include std_string.i

%{
  #include "GmshConfig.h"
  #include "fullMatrix.h"
#if defined(HAVE_POST)
  #include "PView.h"
  #include "PViewFactory.h"
  #include "PViewData.h"
#endif
%}

%include "GmshConfig.h"
#if defined(HAVE_POST)
%include "PView.h"
%include "PViewFactory.h"
%apply double &OUTPUT { double &val}
%include "PViewData.h"
#endif

