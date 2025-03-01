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
  #include "GVertex.h"
  #include "GEntity.h"
  #include "GPoint.h"
  #include "GCurve.h"
  #include "GSurface.h"
  #include "GVolume.h"
  #include "discreteFace.h"
  #include "discreteEdge.h"
  #include "discreteRegion.h"
  #include "discreteVertex.h"
  #include "gmshLevelset.h"
  #include "MElement.h"
  #include "MElementOctree.h"
  #include "MNode.h"
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
  %template(GVertexVector) vector<GPoint*, std::allocator<GPoint*> >;
  %template(GEdgeVector) vector<GCurve*, std::allocator<GCurve*> >;
  %template(GFaceVector) vector<GSurface*, std::allocator<GSurface*> >;
  %template(GRegionVector) vector<GVolume*, std::allocator<GVolume*> >;
  %template(MVertexVector) vector< MNode *,std::allocator< MNode * > >;
  %template(MElementVector) vector< MElement *,std::allocator< MElement * > >;
  %template(MTriangleVector) vector< MTriangle *,std::allocator< MTriangle * > >;
  %template(MTetrahedronVector) vector< MTetrahedron *,std::allocator< MTetrahedron * > >;
  %template(MQuadrangleVector) vector< MQuadrangle *,std::allocator< MQuadrangle * > >;
  %template(MPyramidVector) vector< MPyramid *,std::allocator< MPyramid * > >;
  %template(MTrihedronVector) vector< MTrihedron *,std::allocator< MTrihedron * > >;
  %template(MHexahedronVector) vector< MHexahedron *,std::allocator< MHexahedron * > >;
  %template(MPrismVector) vector< MPrism *,std::allocator< MPrism * > >;
  %template(GEdgeVectorVector) vector< std::vector< GCurve *,std::allocator< GCurve * > >,std::allocator< std::vector< GCurve *,std::allocator< GCurve * > > > >;
  %template(GFaceVectorVector) vector< std::vector< GSurface *,std::allocator< GSurface * > >,std::allocator< std::vector< GSurface *,std::allocator< GSurface * > > > >;
  %template(GFaceList) list<GSurface*, std::allocator<GSurface*> >;
  %template(GEdgeList) list<GCurve*, std::allocator<GCurve*> >;
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
%ignore GVertex::x();
%ignore GVertex::y();
%ignore GVertex::z();
%include "GVertex.h"
%include "GEntity.h"
%include "GPoint.h"
%apply std::vector<double> &OUTPUT{std::vector<double> &ts}
%apply std::vector<SPoint3> &OUTPUT{std::vector<SPoint3> &dpts}
%include "GCurve.h"
%ignore GSurface::computeMeanPlane(std::vector< MNode *>const&);
%include "GSurface.h"
%include "GVolume.h"
%include "discreteFace.h"
%include "discreteEdge.h"
%include "discreteVertex.h"
%include "discreteRegion.h"
%include "SPoint3.h"
%include "MElement.h"
%ignore MElementOctree::MElementOctree(GModel*);
%include "MElementOctree.h"
%ignore MNode::x();
%ignore MNode::y();
%ignore MNode::z();
%include "MNode.h"
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
  std::vector<MNode*> getVertices() {
    std::vector <MNode*> vertices;
    $self->getVertices(vertices);
    return vertices;
  }
}

%extend GCurve {
  void setTransfinite(int nbPointsTransfinite, int typeTransfinite = 0, double coeffTransfinite = 1) {
    $self->meshAttributes.method = MESH_TRANSFINITE;
    $self->meshAttributes.typeTransfinite = typeTransfinite;
    $self->meshAttributes.nbPointsTransfinite = std::max(2, nbPointsTransfinite);
    $self->meshAttributes.coeffTransfinite = coeffTransfinite;
  }
}

%extend GSurface {
  void setTransfinite() {
    $self->meshAttributes.method = MESH_TRANSFINITE;
  }
  void setRecombine() {
    $self->meshAttributes.recombine = 1;
  }
}

%extend GVolume {
  void setTransfinite() {
    $self->meshAttributes.method = MESH_TRANSFINITE;
  }
  void setRecombine() {
    $self->meshAttributes.recombine3D = 1;
  }
}
