%feature("autodoc", "1");
#pragma SWIG nowarn=312
%module gmshGeo

%include std_string.i
%include std_list.i
%include std_vector.i
%import "gmshtypemaps.i"

%{
  #undef HAVE_DLOPEN
  #include "GmshConfig.h"

  #include "GModel.h"
  #include "GPoint.h"
  #include "GEntity.h"
  #include "GVertex.h"
  #include "GEdge.h"
  #include "GFace.h"
  #include "GRegion.h"
  #include "discreteFace.h"
  #include "discreteEdge.h"
  #include "discreteRegion.h"
  #include "discreteVertex.h"
  #include "gmshLevelset.h"
  #include "MElement.h"
  #include "MElementOctree.h"
  #include "MVertex.h"
  #include "MTriangle.h"
  #include "MTetrahedron.h"
  #include "MPrism.h"
  #include "MPyramid.h"
  #include "MTrihedron.h"
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
  %template(MTriangleVector) vector< MTriangle *,std::allocator< MTriangle * > >;
  %template(MTetrahedronVector) vector< MTetrahedron *,std::allocator< MTetrahedron * > >;
  %template(MQuadrangleVector) vector< MQuadrangle *,std::allocator< MQuadrangle * > >;
  %template(MPyramidVector) vector< MPyramid *,std::allocator< MPyramid * > >;
  %template(MTrihedronVector) vector< MTrihedron *,std::allocator< MTrihedron * > >;
  %template(MHexahedronVector) vector< MHexahedron *,std::allocator< MHexahedron * > >;
  %template(MPrismVector) vector< MPrism *,std::allocator< MPrism * > >;
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

%rename(__add__) *::operator+;
%rename(__sub__) *::operator-;
%rename(__neg__) *::operator-();
%rename(_operator_mult) *::operator*;
%rename(_operator_assign) *::operator=;
%rename(_operator_equal) *::operator==;
%ignore operator+;
%ignore operator-;
%ignore operator*;
%ignore operator==;
%ignore operator!=;
%ignore operator double*;
%ignore *::operator[](int);
%rename(at) *::operator[];
%rename(_print) *::print;


%include "GmshConfig.h"
%include "simpleFunction.h"
%template(simpleFunctionDouble) simpleFunction<double>;
%include std_vector.i
namespace std {
 %template(simpleFunctionDoubleVector) vector<simpleFunction<double>*, std::allocator<simpleFunction<double>*> >;
}

%include "GModel.h"
%ignore GPoint::x();
%ignore GPoint::y();
%ignore GPoint::z();
%include "GPoint.h"
%include "GEntity.h"
%include "GVertex.h"
%apply std::vector<double> &OUTPUT{std::vector<double> &ts}
%apply std::vector<SPoint3> &OUTPUT{std::vector<SPoint3> &dpts}
%include "GEdge.h"
%ignore GFace::computeMeanPlane(std::vector< MVertex *>const&);
%include "GFace.h"
%include "GRegion.h"
%include "discreteFace.h"
%include "discreteEdge.h"
%include "discreteVertex.h"
%include "discreteRegion.h"
%include "SPoint3.h"
%include "MElement.h"
%ignore MElementOctree::MElementOctree(GModel*);
%include "MElementOctree.h"
%ignore MVertex::x();
%ignore MVertex::y();
%ignore MVertex::z();
%include "MVertex.h"
%include "MTriangle.h"
%include "MTetrahedron.h"
%include "MPrism.h"
%include "MPyramid.h"
%include "MTrihedron.h"
%include "MHexahedron.h"
%include "MQuadrangle.h"
%include "MLine.h"
%warnfilter(401) MEdgeEqual;
%warnfilter(401) MEdgeLessThan;
%include "MEdge.h"
%warnfilter(401) MFaceEqual;
%warnfilter(401) MFaceLessThan;
%include "MFace.h"
%include "MPoint.h"
%ignore SVector3::operator()(int);
%include "SVector3.h"
%include "SPoint2.h"
%include "SBoundingBox3d.h"
%include "gmshLevelset.h"
%include "GeomMeshMatcher.h"

%extend GModel {
  %apply std::vector<double> &OUTPUT {std::vector<double> &paramCoord}
  std::vector<MElement*> getMeshElementsByCoords(const std::vector<double> &p, std::vector<double> &paramCoord, int dim = -1, bool strict_ = true)
  {
    std::vector<MElement*> elements;
    for (unsigned int i = 0; i < p.size()/3; i++){
      SPoint3 P(p[i * 3], p[i * 3 + 1], p[i * 3 + 2]), U;
      MElement *e =  $self->getMeshElementByCoord(P, U, dim, strict_);
      elements.push_back(e);
      paramCoord.push_back(U.x());
      paramCoord.push_back(U.y());
      paramCoord.push_back(U.z());
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

%extend MElement {
  SPoint3 pnt(double xi0, double xi1, double xi2) {
    SPoint3 p;
    $self->pnt(xi0, xi1, xi2, p);
    return p;
  }
  std::vector<double> xyz2uvw(double x, double y, double z) {
    double xyz[3] = {x, y, z};
    std::vector<double> uvw(3, 0.);
    $self->xyz2uvw(xyz, &uvw[0]);
    return uvw;
  }
  std::vector<MVertex*> getVertices() {
    std::vector <MVertex*> vertices;
    $self->getVertices(vertices);
    return vertices;
  }
}

%extend GEdge {
  void setTransfinite(int nbPointsTransfinite, int typeTransfinite = 0, double coeffTransfinite = 1) {
    $self->meshAttributes.method = MESH_TRANSFINITE;
    $self->meshAttributes.typeTransfinite = typeTransfinite;
    $self->meshAttributes.nbPointsTransfinite = std::max(2, nbPointsTransfinite);
    $self->meshAttributes.coeffTransfinite = coeffTransfinite;
  }
}

%extend GFace {
  void setTransfinite() {
    $self->meshAttributes.method = MESH_TRANSFINITE;
  }
  void setRecombine() {
    $self->meshAttributes.recombine = 1;
  }
}

%extend GRegion {
  void setTransfinite() {
    $self->meshAttributes.method = MESH_TRANSFINITE;
  }
  void setRecombine() {
    $self->meshAttributes.recombine3D = 1;
  }
}
