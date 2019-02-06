%feature("autodoc", "1");
#pragma SWIG nowarn=312
%module gmshCommon

%include std_string.i
%include std_vector.i
%include std_map.i
%include cpointer.i
%import "gmshtypemaps.i"

%{
  #undef HAVE_DLOPEN
  #include "GmshConfig.h"

  #include "Context.h"
  #include "GmshGlobal.h"
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
      (level == "Info" ? std::cout : std::cerr) <<level<<" : "<<message<<std::endl;
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
#if defined(HAVE_FLTK)
%include "FlGui.h"
#endif
%include "GmshGlobal.h"
%include "GmshDefines.h"
%include "GmshMessage.h"
