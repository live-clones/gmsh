%feature("autodoc", "1");
%module gmshpy
%include std_string.i
%include std_vector.i
%include std_list.i
%{
  #include "GmshConfig.h"
  #include "GModel.h"
  #include "DefaultOptions.h"
  #include "fullMatrix.h"
  #include "function.h"
  #include "dofManager.h"
  #include "linearSystem.h"
  #include "linearSystemFull.h"
  #include "linearSystemPETSc.h"
  #include "linearSystemCSR.h"
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
  #include "meshGFaceLloyd.h"
  #include "PView.h"
  #include "PViewData.h"
  #include "PViewFactory.h"
  #include "DivideAndConquer.h"
  #include "Gmsh.h"
  #include "functionPython.h"
  #include "Context.h"
  #include "SVector3.h"
  #include "SPoint3.h"
  #include "SPoint2.h"
  #include "GPoint.h"  
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
        throw;
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
   %template(VectorOfDoubleVector) vector<vector<double, std::allocator<double> > >;
   %template(StringVector) vector<std::string, std::allocator<std::string> >;
   %template(GEntityVector) vector<GEntity*, std::allocator<GEntity*> >;
   %template(GVertexVector) vector<GVertex*, std::allocator<GVertex*> >;
   %template(GEdgeVector) vector<GEdge*, std::allocator<GEdge*> >;
   %template(GFaceVector) vector<GFace*, std::allocator<GFace*> >;
   %template(GRegionVector) vector<GRegion*, std::allocator<GRegion*> >;
   %template(MVertexVector) vector< MVertex *,std::allocator< MVertex * > >;
   %template(MElementVector) vector< MElement *,std::allocator< MElement * > >;
   %template(VectorFunctionConst) vector<const function*, std::allocator<const function*> >;
   %template(GEdgeVectorVector) vector< std::vector< GEdge *,std::allocator< GEdge * > >,std::allocator< std::vector< GEdge *,std::allocator< GEdge * > > > >;
   %template(GFaceList) list<GFace*, std::allocator<GFace*> >;
   %template(GEdgeList) list<GEdge*, std::allocator<GEdge*> >;
}

%include "GmshConfig.h"
%include "Context.h"
%include "fullMatrix.h"
%template(fullMatrixDouble) fullMatrix<double>;
%template(fullVectorDouble) fullVector<double>;
%include "dofManager.h"
%template(dofManagerDouble) dofManager<double>;
%include "GModel.h"
%include "function.h"
%include "linearSystem.h"
%template(linearSystemDouble) linearSystem<double>;
%template(linearSystemFullMatrixDouble) linearSystem<fullMatrix<double> >;
%include "linearSystemFull.h"
%template(linearSystemFullDouble) linearSystemFull<double> ;
%include "linearSystemPETSc.h"
%template(linearSystemPETScDouble) linearSystemPETSc<double>;
%include "linearSystemCSR.h"
%template(linearSystemTAUCSDouble) linearSystemCSRTaucs<double>;
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
%include "elasticitySolver.h"
%include "PView.h"
%include "PViewData.h"
%include "PViewFactory.h"
%include "DivideAndConquer.h"
%include "Gmsh.h"
%include "SVector3.h"
%include "SPoint3.h"
%include "SPoint2.h"
%include "GPoint.h"  
%include "functionPython.h"
%include "meshGFaceLloyd.h"
%include "DefaultOptions.h"
#if defined(HAVE_FLTK)
%include "FlGui.h"
#endif
