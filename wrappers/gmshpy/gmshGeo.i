%feature("autodoc", "1");
%module gmshGeo

%include std_string.i
%include std_list.i
%include std_vector.i
%import "gmshtypemaps.i"

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
  #include "discreteRegion.h"
  #include "discreteVertex.h"
  #include "gmshLevelset.h"
  #include "MElement.h"
  #include "MVertex.h"
  #include "MTriangle.h"
  #include "MPrism.h"
  #include "MHexahedron.h"
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
  #include "simpleFunction.h"
  #include "GeomMeshMatcher.h"
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
  %template(GLevelsetVector) vector<gLevelset *, std::allocator<gLevelset *> >;
  %template(IntVector) std::vector<int>;
  %template(DoubleVector) std::vector<double, std::allocator<double> >;
  %template(DoubleVectorVector) std::vector<std::vector<double, std::allocator<double> > >;
  %template(StringVector) std::vector<std::string, std::allocator<std::string> >;
  %template(SPoint3Vector) std::vector<SPoint3, std::allocator<SPoint3> >;
}

%include "GmshConfig.h"
%include "simpleFunction.h"
%template(simpleFunctionDouble) simpleFunction<double>;
%include std_vector.i
namespace std {
 %template(simpleFunctionDoubleVector) vector<simpleFunction<double>*, std::allocator<simpleFunction<double>*> >;
}

%include "GModel.h"
%include "GPoint.h"  
%include "GEntity.h"
%include "GVertex.h"
%apply std::vector<double> &OUTPUT{std::vector<double> &ts}
%apply std::vector<SPoint3> &OUTPUT{std::vector<SPoint3> &dpts}
%include "GEdge.h"
%include "GFace.h"
%include "GRegion.h"
%include "GPoint.h"
%include "discreteFace.h"
%include "discreteEdge.h"
%include "discreteVertex.h"
%include "discreteRegion.h"
%include "MElement.h"
%include "MVertex.h"
%include "MTriangle.h"
%include "MPrism.h"
%include "MHexahedron.h"
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
%include "gmshLevelset.h"
%include "GeomMeshMatcher.h"

%extend GModel {
  %apply std::vector<double> &OUTPUT {std::vector<double> &paramCoord}
  std::vector<MElement*> getMeshElementsByCoords(const std::vector<double> &p, std::vector<double> &paramCoord, int dim = -1, bool strict_ = true)
  {
    std::vector<MElement*> elements;
    for (unsigned int i = 0; i < p.size()/3; i++){
      SPoint3 P(p[i * 3], p[i * 3 + 1], p[i * 3 + 2]);
      MElement *e =  $self->getMeshElementByCoord(P, dim, strict_);
      double xyz[3] = {P.x(), P.y(), P.z()}, uvw[3] = {0., 0., 0.};
      e->xyz2uvw(xyz, uvw);
      elements.push_back(e);
      paramCoord.push_back(uvw[0]);
      paramCoord.push_back(uvw[1]);
      paramCoord.push_back(uvw[2]);
    }
    return elements;
  }

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

