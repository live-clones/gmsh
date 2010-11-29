%feature("autodoc", "1");
%module gmshpy
%include std_string.i
%include std_vector.i
%{
  #include "GModel.h"
  #include "fullMatrix.h"
  #include "function.h"
  #include "dofManager.h"
  #include "linearSystem.h"
  #include "linearSystemPETSc.h"
  #include "linearSystemPETSc.cpp" // needed for the specialization
  #include "GEntity.h"
  #include "GVertex.h"
  #include "GEdge.h"
  #include "GFace.h"
  #include "GRegion.h"
  #include "GPoint.h"
  #include "MElement.h"
  #include "MVertex.h"
  #include "MTriangle.h"
  #include "MPrism.h"
  #include "MQuadrangle.h"
  #include "MLine.h"
  #include "GmshMessage.h"
  #include "polynomialBasis.h"
  #include "Gauss.h"
  #include "meshPartitionOptions.h"
  #include "linearSystemCSR.h"
  #include "elasticitySolver.h"
  #include "PView.h"
  #include "PViewData.h"
  #include "PViewFactory.h"
  #include "DivideAndConquer.h"
  #include "Gmsh.h"
  #include "functionPython.h"
  class errorHandler: public GmshMessage {
    void operator()(std::string level, std::string message){
      //const char *color = colorDefault;
      std::cout<<level<<" : "<<message<<std::endl;
      if (level=="Error" || level == "Fatal") {
        //color = colorRed;
        //color confuses ctest/cdash
        //std::cout<<color<<level<<" : "<<message<<colorDefault<<"\n";
        throw;
      }
    }
  };
%}

%init %{
  errorHandler *eH = new errorHandler;
  Msg::SetCallback(eH);
  GmshInitialize();
%}

namespace std {
   %template(IntVector) vector<int>;
   %template(DoubleVector) vector<double, std::allocator<double> >;
   %template(VectorFunctionConst) vector<const function*, std::allocator<const function*> >;
}

%include "fullMatrix.h"
%include "dofManager.h"
%include "GModel.h"
%include "function.h"
%include "linearSystem.h"
%include "linearSystemPETSc.h"
%include "GEntity.h"
%include "GVertex.h"
%include "GEdge.h"
%include "GFace.h"
%include "GRegion.h"
%include "GPoint.h"
%include "MElement.h"
%include "MVertex.h"
%include "MTriangle.h"
%include "MPrism.h"
%include "MQuadrangle.h"
%include "MLine.h"
%include "GmshMessage.h"
%include "polynomialBasis.h"
%include "Gauss.h"
%include "meshPartitionOptions.h"
%include "linearSystemCSR.h"
%include "elasticitySolver.h"
%include "PView.h"
%include "PViewData.h"
%include "PViewFactory.h"
%include "DivideAndConquer.h"
%include "Gmsh.h"

%template(dofManagerDouble) dofManager<double>;
%template(linearSystemDouble) linearSystem<double>;
%template(linearSystemFullMatrixDouble) linearSystem<fullMatrix<double> >;
%template(linearSystemPETScDouble) linearSystemPETSc<double>;
%template(fullMatrixDouble) fullMatrix<double>;
%template(linearSystemPETScBlockDouble) linearSystemPETSc<fullMatrix<double> >;
%include "functionPython.h"

