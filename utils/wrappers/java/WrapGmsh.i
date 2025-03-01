/*wrapGmsh.i*/
 %module WrapGmsh
 %{
 /* Put header files here or function declarations like below */
#include "GmshGlobal.h"
#include "GModel.h"
#include "Geo.h"
#include "GPoint.h"
#include "gmshVertex.h"
#include "GEntity.h"
#include "GCurve.h"
#include "GSurface.h"
#include "GVolume.h"
#include "scriptStringInterface.h"
#include "GEntity.h"
#include "setWrapperGmsh.h"
#include "listWrapperGmsh.h"
#include "MPoint.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MFace.h"
#include "MTetrahedron.h"

 %}

//declares meshGenerationStatus enumeration
%include "enums.swg"
%javaconst(1);
enum meshGenerationStatus {PENDING, DONE, FAILED};

//these fonctions/classes must be wrapped
%include "std_string.i"
%include "MElement.h"
%include "MPoint.h"
%include "MLine.h"
%include "MFace.h"
%include "MTriangle.h"
%include "MTetrahedron.h"
%include "GEntity.h"
%include "GModel.h"
%include "Geo.h"
%include "GPoint.h"
%include "gmshVertex.h"
%include "GCurve.h"
%include "GSurface.h"
%include "GVolume.h"
%include "MNode.h"
%include "GEntity.h"
%include "ListUtils.h"
extern int GmshInitialize(int argc, char **argv);
extern int GmshFinalize();

//use the Vector object defined in Java language to wrap the std vector.
%include "std_vector.i"
namespace std {
   %template(EdgeVector) std::vector<GCurve *>;
   %template(EdgeVectorOfVector) std::vector<std::vector<GCurve *> >;
   %template(FaceVector) std::vector<GSurface *>;
   %template(FaceVectorOfVector) std::vector<std::vector<GSurface *> >;
   %template(GVertexVector) std::vector<GPoint *>;
   %template(RegionVector) std::vector<GVolume *>;
   %template(GEntityVector) std::vector<GEntity*>;
   %template(MVertexVector) std::vector<MNode*>;
   %template(MPointVector) std::vector<MPoint*>;
   %template(MLineVector) std::vector<MLine*>;
   %template(MTriangleVector) std::vector<MTriangle*>;
   %template(MTetrahedrVector) std::vector<MTetrahedron*>;
   %template(IntVector) std::vector<int>;
};


//wrap Set from std
%include "setWrapperGmsh.h"

%template (GVertexSetWrapper) SetWrapperGmsh<GPoint*, GEntityPtrLessThan>;
%template (GVertexSetIterator) SetIteratorGmsh<GPoint*, GEntityPtrLessThan>;

%template (GEdgeSetWrapper) SetWrapperGmsh<GCurve*, GEntityPtrLessThan>;
%template (GEdgeSetIterator) SetIteratorGmsh<GCurve*, GEntityPtrLessThan>;

%template (GFaceSetWrapper) SetWrapperGmsh<GSurface*, GEntityPtrLessThan>;
%template (GFaceSetIterator) SetIteratorGmsh<GSurface*, GEntityPtrLessThan>;

%template (GRegionSetWrapper) SetWrapperGmsh<GVolume*, GEntityPtrLessThan>;
%template (GRegionSetIterator) SetIteratorGmsh<GVolume*, GEntityPtrLessThan>;


//wrap List from std
%include "listWrapperGmsh.h"

%template (GVertexListWrapper) ListWrapperGmsh<GPoint*>;
%template (GVertexListIterator) ListIteratorGmsh<GPoint*>;

%template (GEdgeListWrapper) ListWrapperGmsh<GCurve*>;
%template (GEdgeListIterator) ListIteratorGmsh<GCurve*>;

%template (GFaceListWrapper) ListWrapperGmsh<GSurface*>;
%template (GFaceListIterator) ListIteratorGmsh<GSurface*>;

%template (GRegionListWrapper) ListWrapperGmsh<GVolume*>;
%template (GRegionListIterator) ListIteratorGmsh<GVolume*>;

%extend GModel {

  std::vector<GVolume*> bindingsGetRegions()
  {
    return std::vector<GVolume*> ($self->firstRegion(), $self->lastRegion());
  }

  std::vector<GSurface*> bindingsGetFaces()
  {
    return std::vector<GSurface*> ($self->firstFace(), $self->lastFace());
  }

  std::vector<GCurve*> bindingsGetEdges()
  {
    return std::vector<GCurve*> ($self->firstEdge(), $self->lastEdge());
  }

  std::vector<GPoint*> bindingsGetVertices()
  {
    return std::vector<GPoint*> ($self->firstVertex(), $self->lastVertex());
  }

}
