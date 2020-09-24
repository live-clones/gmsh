/*wrapGmsh.i*/
 %module WrapGmsh
 %{
 /* Put header files here or function declarations like below */
#include "GmshGlobal.h"
#include "GModel.h"
#include "Geo.h"
#include "GVertex.h"
#include "gmshVertex.h"
#include "GEntity.h"
#include "GEdge.h"
#include "GFace.h"
#include "GRegion.h"
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
%include "GVertex.h"
%include "gmshVertex.h"
%include "GEdge.h"
%include "GFace.h"
%include "GRegion.h"
%include "MVertex.h"
%include "GEntity.h"
%include "ListUtils.h"
extern int GmshInitialize(int argc, char **argv);
extern int GmshFinalize();

//use the Vector object defined in Java language to wrap the std vector.
%include "std_vector.i"
namespace std {
   %template(EdgeVector) std::vector<GEdge *>;
   %template(EdgeVectorOfVector) std::vector<std::vector<GEdge *> >;
   %template(FaceVector) std::vector<GFace *>;
   %template(FaceVectorOfVector) std::vector<std::vector<GFace *> >;
   %template(GVertexVector) std::vector<GVertex *>;
   %template(RegionVector) std::vector<GRegion *>;
   %template(GEntityVector) std::vector<GEntity*>;
   %template(MVertexVector) std::vector<MVertex*>;
   %template(MPointVector) std::vector<MPoint*>;
   %template(MLineVector) std::vector<MLine*>;
   %template(MTriangleVector) std::vector<MTriangle*>;
   %template(MTetrahedrVector) std::vector<MTetrahedron*>;
   %template(IntVector) std::vector<int>;
};


//wrap Set from std
%include "setWrapperGmsh.h"

%template (GVertexSetWrapper) SetWrapperGmsh<GVertex*, GEntityPtrLessThan>;
%template (GVertexSetIterator) SetIteratorGmsh<GVertex*, GEntityPtrLessThan>;

%template (GEdgeSetWrapper) SetWrapperGmsh<GEdge*, GEntityPtrLessThan>;
%template (GEdgeSetIterator) SetIteratorGmsh<GEdge*, GEntityPtrLessThan>;

%template (GFaceSetWrapper) SetWrapperGmsh<GFace*, GEntityPtrLessThan>;
%template (GFaceSetIterator) SetIteratorGmsh<GFace*, GEntityPtrLessThan>;

%template (GRegionSetWrapper) SetWrapperGmsh<GRegion*, GEntityPtrLessThan>;
%template (GRegionSetIterator) SetIteratorGmsh<GRegion*, GEntityPtrLessThan>;


//wrap List from std
%include "listWrapperGmsh.h"

%template (GVertexListWrapper) ListWrapperGmsh<GVertex*>;
%template (GVertexListIterator) ListIteratorGmsh<GVertex*>;

%template (GEdgeListWrapper) ListWrapperGmsh<GEdge*>;
%template (GEdgeListIterator) ListIteratorGmsh<GEdge*>;

%template (GFaceListWrapper) ListWrapperGmsh<GFace*>;
%template (GFaceListIterator) ListIteratorGmsh<GFace*>;

%template (GRegionListWrapper) ListWrapperGmsh<GRegion*>;
%template (GRegionListIterator) ListIteratorGmsh<GRegion*>;

%extend GModel {

  std::vector<GRegion*> bindingsGetRegions()
  {
    return std::vector<GRegion*> ($self->firstRegion(), $self->lastRegion());
  }

  std::vector<GFace*> bindingsGetFaces()
  {
    return std::vector<GFace*> ($self->firstFace(), $self->lastFace());
  }

  std::vector<GEdge*> bindingsGetEdges()
  {
    return std::vector<GEdge*> ($self->firstEdge(), $self->lastEdge());
  }

  std::vector<GVertex*> bindingsGetVertices()
  {
    return std::vector<GVertex*> ($self->firstVertex(), $self->lastVertex());
  }

}
