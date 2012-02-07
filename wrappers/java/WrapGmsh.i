/*wrapGmsh.i*/
 %module WrapGmsh
 %{
 /* Put header files here or function declarations like below */
#include "Gmsh.h"
#include "GModel.h"
#include "Geo.h"
#include "GVertex.h"
#include "gmshVertex.h"
#include "GEntity.h"
#include "GModelFactory.h"
#include "GEdge.h"
#include "GFace.h"
#include "GRegion.h"
#include "GeoStringInterface.h"
#include "GEntity.h"
#include "setWrapperGmsh.h"
#include "listWrapperGmsh.h"
#include "MPoint.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MFace.h"
#include "MTetrahedron.h"
#include "GModelIO_Mesh.cpp"

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
%include "GModelFactory.h"
%include "GEdge.h"
%include "GFace.h"
%include "GRegion.h"
%include "MVertex.h"    
%include "GEntity.h"
%include "ListUtils.h"
extern int GModel::getNumElementsMSH(GModel *m, bool saveAll, int saveSinglePartition);
extern int GModel::indexMeshVertices(bool all, int singlePartition);
extern int GmshInitialize(int argc, char **argv);
extern int GmshFinalize();
extern Vertex *Create_Vertex(int Num, double X, double Y, double Z, double lc, double u); 
extern void add_physical(std::string type, List_T *list, std::string fileName);

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

%template (GVertexSetWrapper) SetWrapperGmsh<GVertex*, GEntityLessThan>; 
%template (GVertexSetIterator) SetIteratorGmsh<GVertex*, GEntityLessThan>;

%template (GEdgeSetWrapper) SetWrapperGmsh<GEdge*, GEntityLessThan>; 
%template (GEdgeSetIterator) SetIteratorGmsh<GEdge*, GEntityLessThan>;

%template (GFaceSetWrapper) SetWrapperGmsh<GFace*, GEntityLessThan>; 
%template (GFaceSetIterator) SetIteratorGmsh<GFace*, GEntityLessThan>;

%template (GRegionSetWrapper) SetWrapperGmsh<GRegion*, GEntityLessThan>; 
%template (GRegionSetIterator) SetIteratorGmsh<GRegion*, GEntityLessThan>;


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









