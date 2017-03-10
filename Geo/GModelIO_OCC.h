// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _GMODELIO_OCC_H_
#define _GMODELIO_OCC_H_

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
#include <TopTools_IndexedMapOfShape.hxx>
#include <TopTools_DataMapOfShapeInteger.hxx>
#include <TopTools_DataMapOfIntegerShape.hxx>
#include <BRepBuilderAPI_Transform.hxx>

class OCC_Internals {
 public:
  enum BooleanOperator { Union, Intersection, Difference, Section, Fragments };

 private :
  // have the internals changed since the last synchronisation
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

  // internal mesh attributes, linked to tags
  class meshAttribute {
  public:
    meshAttribute() : size(MAX_LC), extrude(0) {}
    double size;
    ExtrudeParams *extrude;
  };
  std::map<int, meshAttribute> _meshAttributes[4];

  // iterate on all bound entities and recompute the maximum tag
  void _recomputeMaxTag(int dim);

  // add a shape and all its subshapes to _vmap, _emap, ..., _somap
  void _addShapeToMaps(TopoDS_Shape shape);

  // apply various healing algorithms to try to fix the shape
  void _healShape(TopoDS_Shape &myshape, double tolerance, bool fixdegenerated,
                  bool fixsmalledges, bool fixspotstripfaces, bool sewfaces,
                  bool makesolids=false, double scaling=0.0);

  // apply a geometrical transformation
  void _transform(const std::vector<std::pair<int, int> > &inDimTags,
                  BRepBuilderAPI_Transform &tfo);

  // add circle or ellipse arc
  void _addArc(int tag, int startTag, int centerTag, int endTag, int mode);

  // add bezier or bspline
  void _addSpline(int tag, const std::vector<int> &vertexTags, int mode);

  // apply extrusion-like operations
  void _extrude(int mode, const std::vector<std::pair<int, int> > &inDimTags,
                double x, double y, double z, double dx, double dy, double dz,
                double ax, double ay, double az, double angle, int wireTag,
                std::vector<std::pair<int, int> > &outDimTags,
                ExtrudeParams *e=0);

 public:
  OCC_Internals();

  // have the internals changed since the last synchronisation?
  bool getChanged() const { return _changed; }

  // reset all maps
  void reset();

  // bind and unbind OpenCASCADE shapes to tags
  void bind(TopoDS_Vertex vertex, int tag);
  void bind(TopoDS_Edge edge, int tag);
  void bind(TopoDS_Wire wire, int tag);
  void bind(TopoDS_Face face, int tag);
  void bind(TopoDS_Shell shell, int tag);
  void bind(TopoDS_Solid solid, int tag);
  void bind(TopoDS_Shape shape, int dim, int tag);
  void unbind(TopoDS_Vertex vertex, int tag);
  void unbind(TopoDS_Edge edge, int tag);
  void unbind(TopoDS_Wire wire, int tag);
  void unbind(TopoDS_Face face, int tag);
  void unbind(TopoDS_Shell shell, int tag);
  void unbind(TopoDS_Solid solid, int tag);
  void unbind(TopoDS_Shape shape, int dim, int tag);
  void unbindRecursive(TopoDS_Shape shape, int dim, int tag);

  // bind (potentially) mutliple entities in shape and return the tags in
  // outTags. If tag > 0 and a single entity if found, use that; if
  // highestDimOnly is true, only bind the entities of the highest
  // dimension
  void bind(TopoDS_Shape shape, bool highestDimOnly, int tag,
            std::vector<std::pair<int, int> > &outDimTags);

  // is the entity of a given dimension and tag bound?
  bool isBound(int dim, int tag);

  // get the entity of a given dimension and tag
  TopoDS_Shape find(int dim, int tag);

  // set/get max tag of entity for each dimension (0, 1, 2, 3), as well as
  // -2 for shells and -1 for wires
  void setMaxTag(int dim, int val);
  int getMaxTag(int dim) const;

  // add shapes
  void addVertex(int tag, double x, double y, double z, double meshSize=MAX_LC);
  void addLine(int tag, int startTag, int endTag);
  void addLine(int tag, const std::vector<int> &vertexTags);
  void addCircleArc(int tag, int startTag, int centerTag, int endTag);
  void addCircle(int tag, double x, double y, double z, double r, double angle1,
                 double angle2);
  void addEllipseArc(int tag, int startTag, int centerTag, int endTag);
  void addEllipse(int tag, double x, double y, double z, double r1, double r2,
                  double angle1, double angle2);
  void addBezier(int tag, const std::vector<int> &vertexTags);
  void addBSpline(int tag, const std::vector<int> &vertexTags);
  void addWire(int tag, const std::vector<int> &edgeTags, bool checkClosed);
  void addLineLoop(int tag, const std::vector<int> &edgeTags);
  void addRectangle(int tag, double x1, double y1, double z1,
                    double x2, double y2, double z2, double roundedRadius=0.);
  void addDisk(int tag, double xc, double yc, double zc, double rx, double ry);
  void addPlaneSurface(int tag, const std::vector<int> &wireTags);
  void addSurfaceFilling(int tag, int wireTag);
  void addSurfaceLoop(int tag, const std::vector<int> &faceTags);
  void addVolume(int tag, const std::vector<int> &shellTags);
  void addSphere(int tag, double xc, double yc, double zc, double radius,
                 double angle1, double angle2, double angle3);
  void addBlock(int tag, double x1, double y1, double z1,
                double x2, double y2, double z2);
  void addCylinder(int tag, double x1, double y1, double z1, double x2, double y2,
                   double z2, double r, double angle);
  void addCone(int tag, double x1, double y1, double z1, double x2, double y2,
               double z2, double r1, double r2, double angle);
  void addWedge(int tag, double x, double y, double z, double dx, double dy,
                double dz, double ltx);
  void addTorus(int tag, double x, double y, double z, double r1, double r2,
                double angle);
  void addThruSections(int tag, const std::vector<int> &wireTags,
                       std::vector<std::pair<int, int> > &outDimTags,
                       bool makeSolid, bool makeRuled);
  void addThickSolid(int tag, int solidTag, const std::vector<int> &excludeFaceTags,
                     double offset);

  // extrude and revolve
  void extrude(const std::vector<std::pair<int, int> > &inDimTags,
               double dx, double dy, double dz,
               std::vector<std::pair<int, int> > &outDimTags,
               ExtrudeParams *e=0);
  void revolve(const std::vector<std::pair<int, int> > &inDimTags,
               double x, double y, double z, double ax, double ay, double az,
               double angle, std::vector<std::pair<int, int> > &outDimTags,
               ExtrudeParams *e=0);
  void addPipe(const std::vector<std::pair<int, int> > &inDimTags, int wireTag,
               std::vector<std::pair<int, int> > &outDimTags);

  // fillet
  void fillet(const std::vector<int> &regionTags, const std::vector<int> &edgeTags,
              double radius, std::vector<std::pair<int, int> > &ouDimTags);

  // apply boolean operator
  void applyBooleanOperator(int tag, BooleanOperator op,
                            const std::vector<std::pair<int, int> > &objectDimTags,
                            const std::vector<std::pair<int, int> > &toolDimTags,
                            std::vector<std::pair<int, int> > &outDimTags,
                            bool removeObject, bool removeTool);

  // apply transformations
  void translate(const std::vector<std::pair<int, int> > &inDimTags,
                 double dx, double dy, double dz);
  void rotate(const std::vector<std::pair<int, int> > &inDimTags,
              double x, double y, double z, double ax, double ay, double az,
              double angle);

  // copy and remove
  void copy(const std::vector<std::pair<int, int> > &inDimTags,
            std::vector<std::pair<int, int> > &outDimTags);
  void remove(int dim, int tag);
  void remove(const std::vector<std::pair<int, int> > &dimTags);

  // import shapes from file
  void importShapes(const std::string &fileName, bool highestDimOnly,
                    std::vector<std::pair<int, int> > &outDimTags,
                    const std::string &format="");

  // import shapes from TopoDS_Shape
  void importShapes(const TopoDS_Shape *shape, bool highestDimOnly,
                    std::vector<std::pair<int, int> > &outDimTags);

  // export all bound shapes to file
  void exportShapes(const std::string &fileName, const std::string &format="");

  // set meshing constraints
  void setMeshSize(int dim, int tag, double size);

  // synchronize internal CAD data with the given GModel
  void synchronize(GModel *model);

  // queries
  bool getVertex(int tag, double &x, double &y, double &z);

  GVertex *getOCCVertexByNativePtr(GModel *model, TopoDS_Vertex toFind);
  GEdge *getOCCEdgeByNativePtr(GModel *model, TopoDS_Edge toFind);
  GFace *getOCCFaceByNativePtr(GModel *model, TopoDS_Face toFind);
  GRegion *getOCCRegionByNativePtr(GModel *model, TopoDS_Solid toFind);

  // *** FIXME what follows will be removed ***
 private:
  TopoDS_Shape _shape;
 public:
  void _addShapeToLists(TopoDS_Shape shape){ _addShapeToMaps(shape); }
  void _healGeometry(double tolerance, bool fixdegenerated,
                     bool fixsmalledges, bool fixspotstripfaces, bool sewfaces,
                     bool makesolids=false, double scaling=0.0)
  {
    _healShape(_shape, tolerance, fixdegenerated, fixsmalledges,
               fixspotstripfaces, sewfaces, makesolids, scaling);
  }
  void applyBooleanOperator(TopoDS_Shape tool, const BooleanOperator &op);
  TopoDS_Shape getShape () { return _shape; }
  void buildLists();
  void buildShapeFromLists(TopoDS_Shape shape);
  void fillet(std::vector<TopoDS_Edge> &shapes, double radius);
  void buildShapeFromGModel(GModel*);
  void buildGModel(GModel *gm);
  void loadShape(const TopoDS_Shape *s)
  {
    std::vector<std::pair<int, int> > outDimTags;
    importShapes(s, false, outDimTags);
  }
  GVertex *addVertexToModel(GModel *model, TopoDS_Vertex v);
  GEdge *addEdgeToModel(GModel *model, TopoDS_Edge e);
  GFace *addFaceToModel(GModel *model, TopoDS_Face f);
  GRegion *addRegionToModel(GModel *model, TopoDS_Solid r);
  // *** FIXME end of stuff that will be removed ***
};

#else

class OCC_Internals {
private:
  void _error(std::string what)
  {
    Msg::Error("Gmsh requires OpenCASCADE to %s", what.c_str());
  }
public:
  enum BooleanOperator { Union, Intersection, Difference, Section, Fragments };
  OCC_Internals(){}
  bool getChanged() const { return false; }
  void reset(){}
  void setMaxTag(int dim, int val){}
  int getMaxTag(int dim) const { return 0; }
  void addVertex(int tag, double x, double y, double z, double meshSize=MAX_LC)
  {
    _error("add vertex");
  }
  void addLine(int tag, int startTag, int endTag)
  {
    _error("add line");
  }
  void addLine(int tag, const std::vector<int> &vertexTags)
  {
    _error("add line");
  }
  void addCircleArc(int tag, int startTag, int centerTag, int endTag)
  {
    _error("add circle arc");
  }
  void addCircle(int tag, double x, double y, double z, double r, double angle1,
                 double angle2)
  {
    _error("add circle");
  }
  void addEllipseArc(int tag, int startTag, int centerTag, int endTag)
  {
    _error("add ellipse arc");
  }
  void addEllipse(int tag, double x, double y, double z, double r1, double r2,
                  double angle1, double angle2)
  {
    _error("add ellipse");
  }
  void addBezier(int tag, const std::vector<int> &vertexTags)
  {
    _error("add Bezier");
  }
  void addBSpline(int tag, const std::vector<int> &vertexTags)
  {
    _error("add BSpline");
  }
  void addWire(int tag, const std::vector<int> &edgeTags, bool closed)
  {
    _error("add wire");
  }
  void addLineLoop(int tag, const std::vector<int> &edgeTags)
  {
    _error("add line loop");
  }
  void addRectangle(int tag, double x1, double y1, double z1,
                    double x2, double y2, double z2, double roundedRadius=0.)
  {
    _error("add rectangle");
  }
  void addDisk(int tag, double xc, double yc, double zc, double rx, double ry)
  {
    _error("add disk");
  }
  void addPlaneSurface(int tag, const std::vector<int> &wireTags)
  {
    _error("add plane surface");
  }
  void addSurfaceFilling(int tag, int wireTag)
  {
    _error("add surface filling");
  }
  void addSurfaceLoop(int tag, const std::vector<int> &faceTags)
  {
    _error("add surface loop");
  }
  void addVolume(int tag, const std::vector<int> &shellTags)
  {
    _error("add volume");
  }
  void addSphere(int tag, double xc, double yc, double zc, double radius,
                 double angle1, double angle2, double angle3)
  {
    _error("add sphere");
  }
  void addBlock(int tag, double x1, double y1, double z1,
                double x2, double y2, double z2)
  {
    _error("add block");
  }
  void addCylinder(int tag, double x1, double y1, double z1, double x2, double y2,
                   double z2, double r, double angle)
  {
    _error("add cylinder");
  }
  void addCone(int tag, double x1, double y1, double z1, double x2, double y2,
               double z2, double r1, double r2, double angle)
  {
    _error("add cone");
  }
  void addWedge(int tag, double x, double y, double z, double dx, double dy,
                double dz, double ltx)

  { _error("add wedge");
  }
  void addTorus(int tag, double x, double y, double z, double r1, double r2,
                double angle)
  {
    _error("add torus");
  }
  void addThruSections(int tag, const std::vector<int> &wireTags,
                       std::vector<std::pair<int, int> > &outDimTags,
                       bool makeSolid, bool makeRuled)
  {
    _error("add thrusection");
  }
  void addThickSolid(int tag, int solidTag, const std::vector<int> &excludeFaceTags,
                     double offset)
  {
    _error("add thick solid");
  }
  void extrude(const std::vector<std::pair<int, int> > &inDimTags,
               double dx, double dy, double dz,
               std::vector<std::pair<int, int> > &outDimTags,
               ExtrudeParams *e=0)
  {
    _error("extrude");
  }
  void revolve(const std::vector<std::pair<int, int> > &inDimTags,
               double x, double y, double z, double ax, double ay, double az,
               double angle, std::vector<std::pair<int, int> > &outDimTags,
               ExtrudeParams *e=0)
  {
    _error("revolve");
  }
  void addPipe(const std::vector<std::pair<int, int> > &inDimTags, int wireTag,
               std::vector<std::pair<int, int> > &outDimTags)
  {
    _error("add pipe");
  }
  void fillet(const std::vector<int> &regionTags, const std::vector<int> &edgeTags,
              double radius, std::vector<std::pair<int, int> > &outDimTags)
  {
    _error("create fillet");
  }
  void applyBooleanOperator(int tag, BooleanOperator op,
                            const std::vector<std::pair<int, int> > &objectDimTags,
                            const std::vector<std::pair<int, int> > &toolDimTags,
                            std::vector<std::pair<int, int> > &outDimTags,
                            bool removeObject, bool removeTool)
  {
    _error("apply boolean operator");
  }
  void translate(const std::vector<std::pair<int, int> > &inDimTags,
                 double dx, double dy, double dz)
  {
    _error("apply translation");
  }
  void rotate(const std::vector<std::pair<int, int> > &inDimTags,
              double x, double y, double z, double ax, double ay, double az,
              double angle)
  {
    _error("apply rotation");
  }
  void copy(const std::vector<std::pair<int, int> > &inDimTags,
            std::vector<std::pair<int, int> > &outDimTags)
  {
    _error("copy shape");
  }
  void remove(int dim, int tag){}
  void remove(const std::vector<std::pair<int, int> > &dimTags){}
  void importShapes(const std::string &fileName, bool highestDimOnly,
                    std::vector<std::pair<int, int> > &outDimTags,
                    const std::string &format="")
  {
    _error("import shape");
  }
  void exportShapes(const std::string &fileName, const std::string &format="")
  {
    _error("export shape");
  }
  void setMeshSize(int dim, int tag, double size){}
  void synchronize(GModel *model){}
  bool getVertex(int tag, double &x, double &y, double &z){ return false; }
};

#endif
#endif
