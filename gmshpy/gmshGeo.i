%feature("autodoc", "1");
%module gmshGeo

%include std_string.i
%include std_list.i
%include std_vector.i
%import "gmshCommon.i"

%{
  #include "GmshConfig.h"

  #include "GModel.h"
  #include "GPoint.h"  
  #include "GEntity.h"
  #include "GVertex.h"
  #include "GEdge.h"
  #include "GFace.h"
  #include "GRegion.h"
  #include "GPoint.h"
  #include "discreteFace.h"
  #include "discreteEdge.h"
  #include "discreteVertex.h"
  #include "MElement.h"
  #include "MVertex.h"
  #include "MTriangle.h"
  #include "MPrism.h"
  #include "MQuadrangle.h"
  #include "MLine.h"
  #include "MEdge.h"
  #include "MFace.h"
  #include "MPoint.h"
  #include "SVector3.h"
  #include "SPoint3.h"
  #include "SPoint2.h"
  #include "SBoundingBox3d.h"
  #include "Curvature.h"
%}

namespace std {
  %template(GEntityVector) vector<GEntity*, std::allocator<GEntity*> >;
  %template(GVertexVector) vector<GVertex*, std::allocator<GVertex*> >;
  %template(GEdgeVector) vector<GEdge*, std::allocator<GEdge*> >;
  %template(GFaceVector) vector<GFace*, std::allocator<GFace*> >;
  %template(GRegionVector) vector<GRegion*, std::allocator<GRegion*> >;
  %template(MVertexVector) vector< MVertex *,std::allocator< MVertex * > >;
  %template(MElementVector) vector< MElement *,std::allocator< MElement * > >;
  %template(GEdgeVectorVector) vector< std::vector< GEdge *,std::allocator< GEdge * > >,std::allocator< std::vector< GEdge *,std::allocator< GEdge * > > > >;
  %template(GFaceVectorVector) vector< std::vector< GFace *,std::allocator< GFace * > >,std::allocator< std::vector< GFace *,std::allocator< GFace * > > > >;
  %template(GFaceList) list<GFace*, std::allocator<GFace*> >;
  %template(GEdgeList) list<GEdge*, std::allocator<GEdge*> >;
}

%include "GmshConfig.h"

%include "GModel.h"
%include "GPoint.h"  
%include "GEntity.h"
%include "GVertex.h"
%include "GEdge.h"
%include "GFace.h"
%include "GRegion.h"
%include "GPoint.h"
%include "discreteFace.h"
%include "discreteEdge.h"
%include "discreteVertex.h"
%include "MElement.h"
%include "MVertex.h"
%include "MTriangle.h"
%include "MPrism.h"
%include "MQuadrangle.h"
%include "MLine.h"
%include "MEdge.h"
%include "MFace.h"
%include "MPoint.h"
%include "SVector3.h"
%include "SPoint3.h"
%include "SPoint2.h"
%include "SBoundingBox3d.h"
%include "Curvature.h"
