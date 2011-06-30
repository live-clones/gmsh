%feature("autodoc", "1");
%module gmshCommon

%include std_string.i
%include std_vector.i
%include cpointer.i 

%{
  #include "GmshConfig.h"

  #include "Context.h"
  #include "DefaultOptions.h"
  #include "Gmsh.h"
  #include "GmshDefines.h"
  #include "GmshMessage.h"
#if defined(HAVE_FLTK)
  #include "FlGui.h"
#endif
  class errorHandler: public GmshMessage {
    void operator()(std::string level, std::string message){
#if defined(HAVE_FLTK)
      // don't output anything special if we're running in a gui
      if(FlGui::available()) return;
#endif
      std::cout<<level<<" : "<<message<<std::endl;
      if (level == "Fatal") 
        Msg::Exit(1);
    }
  };
%}

%init %{
  errorHandler *eH = new errorHandler;
  Msg::SetCallback(eH);
%}

namespace std {
  %template(IntVector) std::vector<int>;
  %template(DoubleVector) std::vector<double, std::allocator<double> >;
  %template(DoubleVectorVector) std::vector<std::vector<double, std::allocator<double> > >;
  %template(StringVector) std::vector<std::string, std::allocator<std::string> >;
}
%pointer_functions(double,doublep)
%pointer_functions(int,intp)

%include "GmshConfig.h"

%include "Context.h"
#include "DefaultOptions.h"
#if defined(HAVE_FLTK)
%include "FlGui.h"
#endif
%include "Gmsh.h"
%include "GmshDefines.h"
%include "GmshMessage.h"
