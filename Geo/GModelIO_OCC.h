// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMODELIO_OCC_H
#define GMODELIO_OCC_H

#include <vector>
#include <map>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "GModel.h"

class ExtrudeParams;

#if defined(HAVE_OCC)

#include <TopoDS_Shape.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Wire.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Shell.hxx>
#include <TopoDS_Solid.hxx>
#include <TopoDS_Compound.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <TopTools_DataMapOfShapeInteger.hxx>
#include <TopTools_DataMapOfIntegerShape.hxx>

class BRepSweep_Prism;
class BRepSweep_Revol;
class BRepBuilderAPI_Transform;
class BRepBuilderAPI_GTransform;
class OCCAttributesRTree;

class OCC_Internals {
public:
  enum BooleanOperator { Union, Intersection, Difference, Section, Fragments };

private:
  // have the internals changed since the last synchronisation?
  bool _changed;

  // maximum tags for each bound entity (shell, wire, vertex, edge, face, solid)
  int _maxTag[6];

  // all the (sub)shapes, updated dynamically when shapes need to be imported
  // into a GModel
  TopTools_IndexedMapOfShape _vmap, _emap, _wmap, _fmap, _shmap, _somap;

  // cache mapping TopoDS_Shapes to their corresponding (future) GEntity tags
  TopTools_DataMapOfShapeInteger _vertexTag, _edgeTag, _faceTag, _solidTag;
  TopTools_DataMapOfIntegerShape _tagVertex, _tagEdge, _tagFace, _tagSolid;

  // cache mapping TopoDS_Shapes to tags for internal use during geometry
  // construction
  TopTools_DataMapOfShapeInteger _wireTag, _shellTag;
  TopTools_DataMapOfIntegerShape _tagWire, _tagShell;

  // cache of <dim,tag> pairs corresponding to entities that will need to be
  // removed from the model at the next synchronization
  std::set<std::pair<int, int> > _toRemove;

  // cache of <dim,tag> pairs corresponding to entities that should not be
  // unbound during boolean operations
  std::set<std::pair<int, int> > _toPreserve;

  // mesh attributes
  OCCAttributesRTree *_attributes;

  // get tag of shape, but search for other candidates at the same location if
  // the actual shape is not found
  int _getFuzzyTag(int dim, const TopoDS_Shape &s);

  // iterate on all bound entities and recompute the maximum tag
  void _recomputeMaxTag(int dim);

  // bind (potentially) mutliple entities in shape and return the tags in
  // outTags. If tag > 0 and a single entity if found, use that; if
  // highestDimOnly is true, only bind the entities (and sub-entities, if
  // recursive is set) of the highest dimension; if returnNewOnly is set, only
  // return newly bound entities in outDimTags.
  void _multiBind(const TopoDS_Shape &shape, int tag,
                  std::vector<std::pair<int, int> > &outDimTags,
                  bool returnHighestDimOnly, bool recursive = false,
                  bool returnNewOnly = false);

  // is the entity of a given dimension and tag bound?
  bool _isBound(int dim, int tag);

  // is the entity of a given dimension and shape bound?
  bool _isBound(int dim, const TopoDS_Shape &shape);

  // get the entity of a given dimension and tag
  TopoDS_Shape _find(int dim, int tag);

  // get the tag of a shape of a given dimension
  int _find(int dim, const TopoDS_Shape &shape);

  // get maximum dimension of shapes bound to tags
  int _getMaxDim();

  // get (dim,tag) of all shapes (that will be) bound to tags
  void _getAllDimTags(std::vector<std::pair<int, int> > &dimTags, int dim = 99);

  // add a shape and all its subshapes to _vmap, _emap, ..., _somap
  void _addShapeToMaps(const TopoDS_Shape &shape);

  // apply various healing algorithms to try to fix the shape
  void _healShape(TopoDS_Shape &myshape, double tolerance, bool fixDegenerated,
                  bool fixSmallEdges, bool fixSmallFaces, bool sewFaces,
                  bool makeSolids, double scaling = 0.0);

  // apply a geometrical transformation
  bool _transform(const std::vector<std::pair<int, int> > &inDimTags,
                  BRepBuilderAPI_Transform *tfo,
                  BRepBuilderAPI_GTransform *gtfo);

  // add bspline
  bool _addBSpline(int &tag, const std::vector<int> &pointTags, int mode,
                   const int degree = -1,
                   const std::vector<double> &weights = std::vector<double>(),
                   const std::vector<double> &knots = std::vector<double>(),
                   const std::vector<int> &multiplicities = std::vector<int>());

  // apply extrusion-like operations
  bool _extrudePerDim(int mode, int inDim, const std::vector<int> &inTags,
                      double x, double y, double z, double dx, double dy,
                      double dz, double ax, double ay, double az, double angle,
                      int wireTag,
                      std::vector<std::pair<int, int> > &outDimTags,
                      ExtrudeParams *e, const std::string &trihedron);
  bool _extrude(int mode, const std::vector<std::pair<int, int> > &inDimTags,
                double x, double y, double z, double dx, double dy, double dz,
                double ax, double ay, double az, double angle, int wireTag,
                std::vector<std::pair<int, int> > &outDimTags,
                ExtrudeParams *e = nullptr, const std::string &trihedron = "");

  // apply fillet-like operations
  bool _fillet(int mode, const std::vector<int> &volumeTags,
               const std::vector<int> &curveTags,
               const std::vector<int> &surfaceTags,
               const std::vector<double> &param,
               std::vector<std::pair<int, int> > &outDimTags,
               bool removeVolume);

  // set extruded mesh attributes
  void _setExtrudedAttributes(const TopoDS_Compound &c, BRepSweep_Prism *p,
                              BRepSweep_Revol *r, ExtrudeParams *e, double x,
                              double y, double z, double dx, double dy,
                              double dz, double ax, double ay, double az,
                              double angle);
  void _copyExtrudedAttributes(TopoDS_Edge edge, GEdge *ge);
  void _copyExtrudedAttributes(TopoDS_Face face, GFace *gf);
  void _copyExtrudedAttributes(TopoDS_Solid solid, GRegion *gr);

  // bounding box
  bool _getBoundingBox(const TopoDS_Shape &s, double &xmin, double &ymin,
                       double &zmin, double &xmax, double &ymax, double &zmax);

  // STL
  bool _makeSTL(const TopoDS_Shape &s, std::vector<SPoint3> &vertices,
                std::vector<SVector3> &normals, std::vector<int> &triangles);

public:
  OCC_Internals();
  ~OCC_Internals();

  // have the internals changed since the last synchronisation?
  bool getChanged() const { return _changed; }

  // reset all maps
  void reset();

  // bind and unbind OpenCASCADE shapes to tags (these methods will become
  // private)
  void bind(const TopoDS_Vertex &vertex, int tag, bool recursive = false);
  void bind(const TopoDS_Edge &edge, int tag, bool recursive = false);
  void bind(const TopoDS_Wire &wire, int tag, bool recursive = false);
  void bind(const TopoDS_Face &face, int tag, bool recursive = false);
  void bind(const TopoDS_Shell &shell, int tag, bool recursive = false);
  void bind(const TopoDS_Solid &solid, int tag, bool recursive = false);
  void bind(TopoDS_Shape shape, int dim, int tag, bool recursive = false);
  void unbind(const TopoDS_Vertex &vertex, int tag, bool recursive = false);
  void unbind(const TopoDS_Edge &edge, int tag, bool recursive = false);
  void unbind(const TopoDS_Wire &wire, int tag, bool recursive = false);
  void unbind(const TopoDS_Face &face, int tag, bool recursive = false);
  void unbind(const TopoDS_Shell &shell, int tag, bool recursive = false);
  void unbind(const TopoDS_Solid &solid, int tag, bool recursive = false);
  void unbind(TopoDS_Shape shape, int dim, int tag, bool recursive = false);
  void unbind();

  // set/get max tag of entity for each dimension (0, 1, 2, 3), as well as
  // -2 for shells and -1 for wires
  void setMaxTag(int dim, int val);
  int getMaxTag(int dim) const;

  // add shapes (if tag is < 0, a new tag is automatically created and returned)
  bool addVertex(int &tag, double x, double y, double z,
                 double meshSize = MAX_LC);
  bool addLine(int &tag, int startTag, int endTag);
  bool addLine(int &tag, const std::vector<int> &pointTags);
  bool addCircleArc(int &tag, int startTag, int centerTag, int endTag);
  bool addCircle(int &tag, double x, double y, double z, double r,
                 double angle1, double angle2);
  bool addEllipseArc(int &tag, int startTag, int centerTag, int majorTag,
                     int endTag);
  bool addEllipse(int &tag, double x, double y, double z, double r1, double r2,
                  double angle1, double angle2);
  bool addSpline(int &tag, const std::vector<int> &pointTags);
  bool addBezier(int &tag, const std::vector<int> &pointTags);
  bool addBSpline(int &tag, const std::vector<int> &pointTags,
                  const int degree = -1,
                  const std::vector<double> &weights = std::vector<double>(),
                  const std::vector<double> &knots = std::vector<double>(),
                  const std::vector<int> &multiplicities = std::vector<int>());
  bool addWire(int &tag, const std::vector<int> &curveTags, bool checkClosed);
  bool addCurveLoop(int &tag, const std::vector<int> &curveTags);
  bool addRectangle(int &tag, double x, double y, double z, double dx,
                    double dy, double roundedRadius = 0.);
  bool addDisk(int &tag, double xc, double yc, double zc, double rx, double ry);
  bool addPlaneSurface(int &tag, const std::vector<int> &wireTags);
  bool addSurfaceFilling(
    int &tag, int wireTag,
    const std::vector<int> &pointTags = std::vector<int>(),
    const std::vector<int> &surfaceTags = std::vector<int>(),
    const std::vector<int> &surfaceContinuity = std::vector<int>());
  bool addBSplineFilling(int &tag, int wireTag, const std::string &type = "");
  bool addBezierFilling(int &tag, int wireTag, const std::string &type = "");
  bool addBSplineSurface(int &tag, const std::vector<int> &pointTags,
                         const int numPointsU, const int degreeU,
                         const int degreeV, const std::vector<double> &weights,
                         const std::vector<double> &knotsU,
                         const std::vector<double> &knotsV,
                         const std::vector<int> &multiplicitiesU,
                         const std::vector<int> &multiplicitiesV,
                         const std::vector<int> &wireTags = std::vector<int>(),
                         bool wire3D = true);
  bool addBezierSurface(int &tag, const std::vector<int> &pointTags,
                        const int numPointsU,
                        const std::vector<int> &wireTags = std::vector<int>(),
                        bool wire3D = true);
  bool addTrimmedSurface(int &tag, int surfaceTag,
                         const std::vector<int> &wireTags, bool wire3D);
  bool addSurfaceLoop(int &tag, const std::vector<int> &surfaceTags,
                      bool sewing);
  bool addVolume(int &tag, const std::vector<int> &shellTags);
  bool addSphere(int &tag, double xc, double yc, double zc, double radius,
                 double angle1, double angle2, double angle3);
  bool addBox(int &tag, double x, double y, double z, double dx, double dy,
              double dz);
  bool addCylinder(int &tag, double x, double y, double z, double dx, double dy,
                   double dz, double r, double angle);
  bool addCone(int &tag, double x, double y, double z, double dx, double dy,
               double dz, double r1, double r2, double angle);
  bool addWedge(int &tag, double x, double y, double z, double dx, double dy,
                double dz, double ltx);
  bool addTorus(int &tag, double x, double y, double z, double r1, double r2,
                double angle);

  // thrusections and thick solids (can create multiple entities)
  bool addThruSections(int tag, const std::vector<int> &wireTags,
                       bool makeSolid, bool makeRuled,
                       std::vector<std::pair<int, int> > &outDimTags,
                       int maxDegree = -1);
  bool addThickSolid(int tag, int solidTag,
                     const std::vector<int> &excludeFaceTags, double offset,
                     std::vector<std::pair<int, int> > &outDimTags);

  // extrude and revolve
  bool extrude(const std::vector<std::pair<int, int> > &inDimTags, double dx,
               double dy, double dz,
               std::vector<std::pair<int, int> > &outDimTags,
               ExtrudeParams *e = nullptr);
  bool revolve(const std::vector<std::pair<int, int> > &inDimTags, double x,
               double y, double z, double ax, double ay, double az,
               double angle, std::vector<std::pair<int, int> > &outDimTags,
               ExtrudeParams *e = nullptr);
  bool addPipe(const std::vector<std::pair<int, int> > &inDimTags, int wireTag,
               std::vector<std::pair<int, int> > &outDimTags,
               const std::string &trihedron = "");

  // fillet
  bool fillet(const std::vector<int> &volumeTags,
              const std::vector<int> &curveTags,
              const std::vector<double> &radii,
              std::vector<std::pair<int, int> > &outDimTags, bool removeVolume);

  // chamfer
  bool chamfer(const std::vector<int> &volumeTags,
               const std::vector<int> &curveTags,
               const std::vector<int> &surfaceTags,
               const std::vector<double> &distances,
               std::vector<std::pair<int, int> > &outDimTags,
               bool removeVolume);

  // apply boolean operator
  bool booleanOperator(
    int tag, BooleanOperator op,
    const std::vector<std::pair<int, int> > &objectDimTags,
    const std::vector<std::pair<int, int> > &toolDimTags,
    std::vector<std::pair<int, int> > &outDimTags,
    std::vector<std::vector<std::pair<int, int> > > &outDimTagsMap,
    bool removeObject, bool removeTool);
  bool
  booleanUnion(int tag, const std::vector<std::pair<int, int> > &objectDimTags,
               const std::vector<std::pair<int, int> > &toolDimTags,
               std::vector<std::pair<int, int> > &outDimTags,
               std::vector<std::vector<std::pair<int, int> > > &outDimTagsMap,
               bool removeObject, bool removeTool);
  bool booleanIntersection(
    int tag, const std::vector<std::pair<int, int> > &objectDimTags,
    const std::vector<std::pair<int, int> > &toolDimTags,
    std::vector<std::pair<int, int> > &outDimTags,
    std::vector<std::vector<std::pair<int, int> > > &outDimTagsMap,
    bool removeObject, bool removeTool);
  bool booleanDifference(
    int tag, const std::vector<std::pair<int, int> > &objectDimTags,
    const std::vector<std::pair<int, int> > &toolDimTags,
    std::vector<std::pair<int, int> > &outDimTags,
    std::vector<std::vector<std::pair<int, int> > > &outDimTagsMap,
    bool removeObject, bool removeTool);
  bool booleanFragments(
    int tag, const std::vector<std::pair<int, int> > &objectDimTags,
    const std::vector<std::pair<int, int> > &toolDimTags,
    std::vector<std::pair<int, int> > &outDimTags,
    std::vector<std::vector<std::pair<int, int> > > &outDimTagsMap,
    bool removeObject, bool removeTool);

  // coherence (shortcut for booleanFragments)
  void removeAllDuplicates();
  bool mergeVertices(const std::vector<int> &tags);

  // apply transformations
  bool translate(const std::vector<std::pair<int, int> > &inDimTags, double dx,
                 double dy, double dz);
  bool rotate(const std::vector<std::pair<int, int> > &inDimTags, double x,
              double y, double z, double ax, double ay, double az,
              double angle);
  bool dilate(const std::vector<std::pair<int, int> > &inDimTags, double x,
              double y, double z, double a, double b, double c);
  bool symmetry(const std::vector<std::pair<int, int> > &inDimTags, double a,
                double b, double c, double d);
  bool affine(const std::vector<std::pair<int, int> > &inDimTags,
              const std::vector<double> &mat);

  // copy and remove
  bool copy(const std::vector<std::pair<int, int> > &inDimTags,
            std::vector<std::pair<int, int> > &outDimTags);
  bool remove(int dim, int tag, bool recursive = false);
  bool remove(const std::vector<std::pair<int, int> > &dimTags,
              bool recursive = false);

  // import shapes from file
  bool importShapes(const std::string &fileName, bool highestDimOnly,
                    std::vector<std::pair<int, int> > &outDimTags,
                    const std::string &format = "");

  // import shapes from TopoDS_Shape
  bool importShapes(const TopoDS_Shape *shape, bool highestDimOnly,
                    std::vector<std::pair<int, int> > &outDimTags);

  // apply various healing algorithms to try to fix the shapes
  bool healShapes(const std::vector<std::pair<int, int> > &inDimTags,
                  std::vector<std::pair<int, int> > &outDimTags,
                  double tolerance, bool fixDegenerated, bool fixSmallEdges,
                  bool fixSmallFaces, bool sewFaces, bool makeSolids);

  // set meshing constraints
  void setMeshSize(int dim, int tag, double size);

  // synchronize internal CAD data with the given GModel
  void synchronize(GModel *model);

  // export all bound shapes to file
  bool exportShapes(GModel *model, const std::string &fileName,
                    const std::string &format = "");

  // queries
  bool getEntities(std::vector<std::pair<int, int> > &dimTags, int dim);
  bool getVertex(int tag, double &x, double &y, double &z);
  bool getBoundingBox(int dim, int tag, double &xmin, double &ymin,
                      double &zmin, double &xmax, double &ymax, double &zmax);
  bool getEntitiesInBoundingBox(double xmin, double ymin, double zmin,
                                double xmax, double ymax, double zmax,
                                std::vector<std::pair<int, int> > &dimTags,
                                int dim);
  bool getMass(int dim, int tag, double &mass);
  bool getCenterOfMass(int dim, int tag, double &x, double &y, double &z);
  bool getMatrixOfInertia(int dim, int tag, std::vector<double> &mat);
  GVertex *getVertexForOCCShape(GModel *model, const TopoDS_Vertex &toFind);
  GEdge *getEdgeForOCCShape(GModel *model, const TopoDS_Edge &toFind);
  GFace *getFaceForOCCShape(GModel *model, const TopoDS_Face &toFind);
  GRegion *getRegionForOCCShape(GModel *model, const TopoDS_Solid &toFind);

  // STL utilities
  bool makeFaceSTL(const TopoDS_Face &s, std::vector<SPoint2> &vertices_uv,
                   std::vector<int> &triangles);
  bool makeFaceSTL(const TopoDS_Face &s, std::vector<SPoint2> &vertices_uv,
                   std::vector<SPoint3> &vertices,
                   std::vector<SVector3> &normals, std::vector<int> &triangles);
  bool makeFaceSTL(const TopoDS_Face &s, std::vector<SPoint3> &vertices,
                   std::vector<SVector3> &normals, std::vector<int> &triangles);
  bool makeEdgeSTLFromFace(const TopoDS_Edge &c, const TopoDS_Face &s,
                           std::vector<SPoint3> *vertices);
  bool makeRectangleSTL(double x, double y, double z, double dx, double dy,
                        double roundedRadius, std::vector<SPoint3> &vertices,
                        std::vector<SVector3> &normals,
                        std::vector<int> &triangles);
  bool makeDiskSTL(double xc, double yc, double zc, double rx, double ry,
                   std::vector<SPoint3> &vertices,
                   std::vector<SVector3> &normals, std::vector<int> &triangles);
  bool makeSphereSTL(double xc, double yc, double zc, double radius,
                     double angle1, double angle2, double angle3,
                     std::vector<SPoint3> &vertices,
                     std::vector<SVector3> &normals,
                     std::vector<int> &triangles);
  bool makeBoxSTL(double x, double y, double z, double dx, double dy, double dz,
                  std::vector<SPoint3> &vertices,
                  std::vector<SVector3> &normals, std::vector<int> &triangles);
  bool makeCylinderSTL(double x, double y, double z, double dx, double dy,
                       double dz, double r, double angle,
                       std::vector<SPoint3> &vertices,
                       std::vector<SVector3> &normals,
                       std::vector<int> &triangles);
  bool makeConeSTL(double x, double y, double z, double dx, double dy,
                   double dz, double r1, double r2, double angle,
                   std::vector<SPoint3> &vertices,
                   std::vector<SVector3> &normals, std::vector<int> &triangles);
  bool makeWedgeSTL(double x, double y, double z, double dx, double dy,
                    double dz, double ltx, std::vector<SPoint3> &vertices,
                    std::vector<SVector3> &normals,
                    std::vector<int> &triangles);
  bool makeTorusSTL(double x, double y, double z, double r1, double r2,
                    double angle, std::vector<SPoint3> &vertices,
                    std::vector<SVector3> &normals,
                    std::vector<int> &triangles);
  void fixSTLBounds(double &xmin, double &ymin, double &zmin, double &xmax,
                    double &ymax, double &zmax);
};

#else

class OCC_Internals {
private:
  bool _error(std::string what)
  {
    Msg::Error("Gmsh requires OpenCASCADE to %s", what.c_str());
    return false;
  }

public:
  enum BooleanOperator { Union, Intersection, Difference, Section, Fragments };
  OCC_Internals() {}
  bool getChanged() const { return false; }
  void reset() {}
  void setMaxTag(int dim, int val) {}
  int getMaxTag(int dim) const { return 0; }
  bool addVertex(int &tag, double x, double y, double z,
                 double meshSize = MAX_LC)
  {
    return _error("add vertex");
  }
  bool addLine(int &tag, int startTag, int endTag)
  {
    return _error("add line");
  }
  bool addLine(int &tag, const std::vector<int> &pointTags)
  {
    return _error("add line");
  }
  bool addCircleArc(int &tag, int startTag, int centerTag, int endTag)
  {
    return _error("add circle arc");
  }
  bool addCircle(int &tag, double x, double y, double z, double r,
                 double angle1, double angle2)
  {
    return _error("add circle");
  }
  bool addEllipseArc(int &tag, int startTag, int centerTag, int majorTag,
                     int endTag)
  {
    return _error("add ellipse arc");
  }
  bool addEllipse(int &tag, double x, double y, double z, double r1, double r2,
                  double angle1, double angle2)
  {
    return _error("add ellipse");
  }
  bool addSpline(int &tag, const std::vector<int> &pointTags)
  {
    return _error("add spline");
  }
  bool addBezier(int &tag, const std::vector<int> &pointTags)
  {
    return _error("add Bezier");
  }
  bool addBSpline(int &tag, const std::vector<int> &pointTags,
                  const int degree = -1,
                  const std::vector<double> &weights = std::vector<double>(),
                  const std::vector<double> &knots = std::vector<double>(),
                  const std::vector<int> &multiplicities = std::vector<int>())
  {
    return _error("add BSpline");
  }
  bool addWire(int &tag, const std::vector<int> &curveTags, bool closed)
  {
    return _error("add wire");
  }
  bool addCurveLoop(int &tag, const std::vector<int> &curveTags)
  {
    return _error("add line loop");
  }
  bool addRectangle(int &tag, double x, double y, double z, double dx,
                    double dy, double roundedRadius = 0.)
  {
    return _error("add rectangle");
  }
  bool addDisk(int &tag, double xc, double yc, double zc, double rx, double ry)
  {
    return _error("add disk");
  }
  bool addPlaneSurface(int &tag, const std::vector<int> &wireTags)
  {
    return _error("add plane surface");
  }
  bool addSurfaceFilling(
    int &tag, int wireTag,
    const std::vector<int> &pointTags = std::vector<int>(),
    const std::vector<int> &surfaceTags = std::vector<int>(),
    const std::vector<int> &surfaceContinuity = std::vector<int>())
  {
    return _error("add surface filling");
  }
  bool addBSplineFilling(int &tag, int wireTag, const std::string &type = "")
  {
    return _error("add BSpline filling");
  }
  bool addBezierFilling(int &tag, int wireTag, const std::string &type = "")
  {
    return _error("add Bezier filling");
  }
  bool addBSplineSurface(int &tag, const std::vector<int> &pointTags,
                         const int numPointsU, const int degreeU,
                         const int degreeV, const std::vector<double> &weights,
                         const std::vector<double> &knotsU,
                         const std::vector<double> &knotsV,
                         const std::vector<int> &multiplicitiesU,
                         const std::vector<int> &multiplicitiesV,
                         const std::vector<int> &wireTags = std::vector<int>(),
                         bool wire3D = true)
  {
    return _error("add BSpline surface");
  }
  bool addBezierSurface(int &tag, const std::vector<int> &pointTags,
                        const int numPointsU,
                        const std::vector<int> &wireTags = std::vector<int>(),
                        bool wire3D = true)
  {
    return _error("add Bezier surface");
  }
  bool addTrimmedSurface(int &tag, int surfaceTag,
                         const std::vector<int> &wireTags, bool wire3D)
  {
    return _error("add trimmed surface");
  }
  bool addSurfaceLoop(int &tag, const std::vector<int> &surfaceTags,
                      bool sewing)
  {
    return _error("add surface loop");
  }
  bool addVolume(int &tag, const std::vector<int> &shellTags)
  {
    return _error("add volume");
  }
  bool addSphere(int &tag, double xc, double yc, double zc, double radius,
                 double angle1, double angle2, double angle3)
  {
    return _error("add sphere");
  }
  bool addBox(int &tag, double x, double y, double z, double dx, double dy,
              double dz)
  {
    return _error("add block");
  }
  bool addCylinder(int &tag, double x, double y, double z, double dx, double dy,
                   double dz, double r, double angle)
  {
    return _error("add cylinder");
  }
  bool addCone(int &tag, double x, double y, double z, double dx, double dy,
               double dz, double r1, double r2, double angle)
  {
    return _error("add cone");
  }
  bool addWedge(int &tag, double x, double y, double z, double dx, double dy,
                double dz, double ltx)

  {
    return _error("add wedge");
  }
  bool addTorus(int &tag, double x, double y, double z, double r1, double r2,
                double angle)
  {
    return _error("add torus");
  }
  bool addThruSections(int tag, const std::vector<int> &wireTags,
                       bool makeSolid, bool makeRuled,
                       std::vector<std::pair<int, int> > &outDimTags,
                       int maxDegree = -1)
  {
    return _error("add thrusection");
  }
  bool addThickSolid(int tag, int solidTag,
                     const std::vector<int> &excludeFaceTags, double offset,
                     std::vector<std::pair<int, int> > &outDimTags)
  {
    return _error("add thick solid");
  }
  bool extrude(const std::vector<std::pair<int, int> > &inDimTags, double dx,
               double dy, double dz,
               std::vector<std::pair<int, int> > &outDimTags,
               ExtrudeParams *e = 0)
  {
    return _error("extrude");
  }
  bool revolve(const std::vector<std::pair<int, int> > &inDimTags, double x,
               double y, double z, double ax, double ay, double az,
               double angle, std::vector<std::pair<int, int> > &outDimTags,
               ExtrudeParams *e = 0)
  {
    return _error("revolve");
  }
  bool addPipe(const std::vector<std::pair<int, int> > &inDimTags, int wireTag,
               std::vector<std::pair<int, int> > &outDimTags,
               const std::string &trihedron = "")
  {
    return _error("add pipe");
  }
  bool fillet(const std::vector<int> &volumeTags,
              const std::vector<int> &curveTags,
              const std::vector<double> &radii,
              std::vector<std::pair<int, int> > &outDimTags, bool removeVolume)
  {
    return _error("create fillet");
  }
  bool chamfer(const std::vector<int> &volumeTags,
               const std::vector<int> &curveTags,
               const std::vector<int> &surfaceTags,
               const std::vector<double> &distances,
               std::vector<std::pair<int, int> > &outDimTags, bool removeVolume)
  {
    return _error("create chamfer");
  }
  bool booleanOperator(
    int tag, BooleanOperator op,
    const std::vector<std::pair<int, int> > &objectDimTags,
    const std::vector<std::pair<int, int> > &toolDimTags,
    std::vector<std::pair<int, int> > &outDimTags,
    std::vector<std::vector<std::pair<int, int> > > &outDimTagsMap,
    bool removeObject, bool removeTool)
  {
    return _error("apply boolean operator");
  }
  bool
  booleanUnion(int tag, const std::vector<std::pair<int, int> > &objectDimTags,
               const std::vector<std::pair<int, int> > &toolDimTags,
               std::vector<std::pair<int, int> > &outDimTags,
               std::vector<std::vector<std::pair<int, int> > > &outDimTagsMap,
               bool removeObject, bool removeTool)
  {
    return _error("apply boolean union");
  }
  bool booleanIntersection(
    int tag, const std::vector<std::pair<int, int> > &objectDimTags,
    const std::vector<std::pair<int, int> > &toolDimTags,
    std::vector<std::pair<int, int> > &outDimTags,
    std::vector<std::vector<std::pair<int, int> > > &outDimTagsMap,
    bool removeObject, bool removeTool)
  {
    return _error("apply boolean intersection");
  }
  bool booleanDifference(
    int tag, const std::vector<std::pair<int, int> > &objectDimTags,
    const std::vector<std::pair<int, int> > &toolDimTags,
    std::vector<std::pair<int, int> > &outDimTags,
    std::vector<std::vector<std::pair<int, int> > > &outDimTagsMap,
    bool removeObject, bool removeTool)
  {
    return _error("apply boolean difference");
  }
  bool booleanFragments(
    int tag, const std::vector<std::pair<int, int> > &objectDimTags,
    const std::vector<std::pair<int, int> > &toolDimTags,
    std::vector<std::pair<int, int> > &outDimTags,
    std::vector<std::vector<std::pair<int, int> > > &outDimTagsMap,
    bool removeObject, bool removeTool)
  {
    return _error("apply boolean fragments");
  }
  void removeAllDuplicates() { _error("remove all duplicates"); }
  bool mergeVertices(const std::vector<int> &tags)
  {
    return _error("merge vertices");
  }
  bool translate(const std::vector<std::pair<int, int> > &inDimTags, double dx,
                 double dy, double dz)
  {
    return _error("apply translation");
  }
  bool rotate(const std::vector<std::pair<int, int> > &inDimTags, double x,
              double y, double z, double ax, double ay, double az, double angle)
  {
    return _error("apply rotation");
  }
  bool dilate(const std::vector<std::pair<int, int> > &inDimTags, double x,
              double y, double z, double a, double b, double c)
  {
    return _error("apply dilatation");
  }
  bool symmetry(const std::vector<std::pair<int, int> > &inDimTags, double a,
                double b, double c, double d)
  {
    return _error("apply symmetry");
  }
  bool affine(const std::vector<std::pair<int, int> > &inDimTags,
              const std::vector<double> &mat)
  {
    return _error("apply affine transform");
  }
  bool copy(const std::vector<std::pair<int, int> > &inDimTags,
            std::vector<std::pair<int, int> > &outDimTags)
  {
    return _error("copy shape");
  }
  bool remove(int dim, int tag, bool recursive = false) { return false; }
  bool remove(const std::vector<std::pair<int, int> > &dimTags,
              bool recursive = false)
  {
    return false;
  }
  bool importShapes(const std::string &fileName, bool highestDimOnly,
                    std::vector<std::pair<int, int> > &outDimTags,
                    const std::string &format = "")
  {
    return _error("import shape");
  }
  bool healShapes(const std::vector<std::pair<int, int> > &inDimTags,
                  std::vector<std::pair<int, int> > &outDimTags,
                  double tolerance, bool fixDegenerated, bool fixSmallEdges,
                  bool fixSmallFaces, bool sewFaces, bool makeSolids)
  {
    return _error("heal shapes");
  }
  void setMeshSize(int dim, int tag, double size) {}
  void synchronize(GModel *model) {}
  bool exportShapes(GModel *model, const std::string &fileName,
                    const std::string &format = "")
  {
    return _error("export shape");
  }
  bool getEntities(std::vector<std::pair<int, int> > &dimTags, int dim)
  {
    return false;
  }
  bool getVertex(int tag, double &x, double &y, double &z) { return false; }
  bool getBoundingBox(int dim, int tag, double &xmin, double &ymin,
                      double &zmin, double &xmax, double &ymax, double &zmax)
  {
    return false;
  }
  bool getEntitiesInBoundingBox(double xmin, double ymin, double zmin,
                                double xmax, double ymax, double zmax,
                                std::vector<std::pair<int, int> > &dimTags,
                                int dim)
  {
    return false;
  }
  bool getMass(int dim, int tag, double &mass) { return false; }
  bool getCenterOfMass(int dim, int tag, double &x, double &y, double &z)
  {
    return false;
  }
  bool getMatrixOfInertia(int dim, int tag, std::vector<double> &mat)
  {
    return false;
  }
  bool makeRectangleSTL(double x, double y, double z, double dx, double dy,
                        double roundedRadius, std::vector<SPoint3> &vertices,
                        std::vector<SVector3> &normals,
                        std::vector<int> &triangles)
  {
    return false;
  }
  bool makeDiskSTL(double xc, double yc, double zc, double rx, double ry,
                   std::vector<SPoint3> &vertices,
                   std::vector<SVector3> &normals, std::vector<int> &triangles)
  {
    return false;
  }
  bool makeSphereSTL(double xc, double yc, double zc, double radius,
                     double angle1, double angle2, double angle3,
                     std::vector<SPoint3> &vertices,
                     std::vector<SVector3> &normals,
                     std::vector<int> &triangles)
  {
    return false;
  }
  bool makeBoxSTL(double x, double y, double z, double dx, double dy, double dz,
                  std::vector<SPoint3> &vertices,
                  std::vector<SVector3> &normals, std::vector<int> &triangles)
  {
    return false;
  }
  bool makeCylinderSTL(double x, double y, double z, double dx, double dy,
                       double dz, double r, double angle,
                       std::vector<SPoint3> &vertices,
                       std::vector<SVector3> &normals,
                       std::vector<int> &triangles)
  {
    return false;
  }
  bool makeConeSTL(double x, double y, double z, double dx, double dy,
                   double dz, double r1, double r2, double angle,
                   std::vector<SPoint3> &vertices,
                   std::vector<SVector3> &normals, std::vector<int> &triangles)
  {
    return false;
  }
  bool makeWedgeSTL(double x, double y, double z, double dx, double dy,
                    double dz, double ltx, std::vector<SPoint3> &vertices,
                    std::vector<SVector3> &normals, std::vector<int> &triangles)
  {
    return false;
  }
  bool makeTorusSTL(double x, double y, double z, double r1, double r2,
                    double angle, std::vector<SPoint3> &vertices,
                    std::vector<SVector3> &normals, std::vector<int> &triangles)
  {
    return false;
  }
};

#endif
#endif
