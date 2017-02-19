// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _GMODELIO_OCC_H_
#define _GMODELIO_OCC_H_

#include "GmshConfig.h"
#include "GmshMessage.h"
#include "GModel.h"
#include "OCCIncludes.h"

#if defined(HAVE_OCC)
#include <vector>

class OCC_Internals {
 public:
  enum BooleanOperator { Union, Intersection, Difference, Section, Fragments };

 private :
  // tag contraints coming from outside OCC_Internals (when using multiple CAD
  // kernels)
  int _maxTagConstraints[6];

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
  std::map<int, meshAttribute> meshAttributes[4];

  // add a shape and all its subshapes to _vmap, _emap, ..., _somap
  void _addShapeToMaps(TopoDS_Shape shape);

  // apply various healing algorithms to try to fix the shape
  void _healShape(TopoDS_Shape &myshape, double tolerance, bool fixdegenerated,
                  bool fixsmalledges, bool fixspotstripfaces, bool sewfaces,
                  bool makesolids=false, double scaling=0.0);

  // apply a geometrical transformation
  void _transform(std::vector<int> inTags[4], BRepBuilderAPI_Transform &tfo);

  // add circle or ellipse arc
  void _addArc(int tag, int startTag, int centerTag, int endTag, int mode);

  // add bezier or bspline
  void _addSpline(int tag, std::vector<int> vertexTags, int mode);

  // apply extrusion-like operations
  void _extrude(int tag, int mode, std::vector<int> inTags[4],
                double x, double y, double z,
                double dx, double dy, double dz, double angle,
                int wireTag, std::vector<int> outTags[4]);

 public:
  OCC_Internals();

  // reset all maps
  void reset()
  {
    for(int i = 0; i < 6; i++) _maxTagConstraints[i] = 0;
    for(int i = 0; i < 4; i++) meshAttributes[i].clear();
    _somap.Clear(); _shmap.Clear(); _fmap.Clear(); _wmap.Clear(); _emap.Clear();
    _vmap.Clear();
    _vertexTag.Clear(); _edgeTag.Clear(); _faceTag.Clear(); _solidTag.Clear();
    _tagVertex.Clear(); _tagEdge.Clear(); _tagFace.Clear(); _tagSolid.Clear();
    _wireTag.Clear(); _shellTag.Clear();
    _tagWire.Clear(); _tagShell.Clear();
  }

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

  // bind (potentially) mutliple entities in shape and return the tags in
  // outTags. If tag > 0 and a single entity if found, use that; if
  // highestDimOnly is true, only bind the entities of the highest
  // dimension
  void bind(TopoDS_Shape shape, bool highestDimOnly, int tag,
            std::vector<int> outTags[4]);

  // is the entity of a given dimension and tag bound?
  bool isBound(int dim, int tag);

  // get the entity of a given dimension and tag
  TopoDS_Shape find(int dim, int tag);

  // set constraints on tags
  void setTagConstraints(int dim, int val);

  // get maximum tag number for each dimension
  int getMaxTag(int dim) const;

  // add shapes
  void addVertex(int tag, double x, double y, double z, double meshSize=MAX_LC);
  void addLine(int tag, int startTag, int endTag);
  void addLine(int tag, std::vector<int> vertexTags);
  void addCircleArc(int tag, int startTag, int centerTag, int endTag);
  void addCircle(int tag, double x, double y, double z, double r, double angle1,
                 double angle2);
  void addEllipseArc(int tag, int startTag, int centerTag, int endTag);
  void addEllipse(int tag, double x, double y, double z, double r1, double r2,
                  double angle1, double angle2);
  void addBezier(int tag, std::vector<int> vertexTags);
  void addBSpline(int tag, std::vector<int> vertexTags);
  void addWire(int tag, std::vector<int> edgeTags, bool checkClosed);
  void addLineLoop(int tag, std::vector<int> edgeTags);
  void addRectangle(int tag, double x1, double y1, double z1,
                    double x2, double y2, double z2, double roundedRadius=0.);
  void addDisk(int tag, double xc, double yc, double zc, double rx, double ry);
  void addPlaneSurface(int tag, std::vector<int> wireTags);
  void addSurfaceFilling(int tag, int wireTag);
  void addSurfaceLoop(int tag, std::vector<int> faceTags);
  void addVolume(int tag, std::vector<int> shellTags);
  void addSphere(int tag, double xc, double yc, double zc, double radius,
                 double angle);
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
  void addThruSections(int tag, std::vector<int> wireTags,
                       std::vector<int> outTags[4],
                       bool makeSolid, bool makeRuled);
  void addThickSolid(int tag, int solidTag, std::vector<int> excludeFaceTags,
                     double offset);

  // extrude and revolve
  void extrude(int tag, std::vector<int> inTags[4],
               double dx, double dy, double dz,
               std::vector<int> outTags[4]);
  void revolve(int tag, std::vector<int> inTags[4],
               double x, double y, double z, double dx, double dy, double dz,
               double angle, std::vector<int> outTags[4]);
  void addPipe(int tag, std::vector<int> inTags[4], int wireTag,
               std::vector<int> outTags[4]);

  // fillet
  void fillet(std::vector<int> regionTags, std::vector<int> edgeTags,
              double radius, std::vector<int> outTags[4]);

  // apply boolean operator
  void applyBooleanOperator(int tag, BooleanOperator op,
                            std::vector<int> shapeTags[4],
                            std::vector<int> toolTags[4],
                            std::vector<int> outTags[4],
                            bool removeShape=true,
                            bool removeTool=true);

  // get boundary of shapes of dimension dim (this will bind the boundary parts
  // to new tags, returned in outTags)
  void getBoundary(std::vector<int> inTags[4], std::vector<int> outTags[4],
                   bool combined=false);

  // apply transformations
  void translate(std::vector<int> inTags[4], double dx, double dy, double dz);
  void rotate(std::vector<int> inTags[4], double x, double y, double z,
              double dx, double dy, double dz, double angle);

  // copy and remove
  void copy(std::vector<int> inTags[4], std::vector<int> outTags[4]);
  void remove(std::vector<int> inTags[4]);

  // import shapes from file
  void importShapes(const std::string &fileName, bool highestDimOnly,
                    std::vector<int> outTags[4], const std::string &format="");

  // import shapes from TopoDS_Shape
  void importShapes(const TopoDS_Shape *shape, bool highestDimOnly,
                    std::vector<int> outTags[4]);

  // export all bound shapes to file
  void exportShapes(const std::string &fileName, const std::string &format="");

  // synchronize internal CAD data with the given GModel
  void synchronize(GModel *model);

  // get the GEntity corresponding to an OCC shape
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
    std::vector<int> tags[4]; importShapes(s, false, tags);
  }
  GVertex *addVertexToModel(GModel *model, TopoDS_Vertex v);
  GEdge *addEdgeToModel(GModel *model, TopoDS_Edge e);
  GFace *addFaceToModel(GModel *model, TopoDS_Face f);
  GRegion *addRegionToModel(GModel *model, TopoDS_Solid r);
  // *** FIXME end of stuff that will be removed ***
};

#else

class OCC_Internals {
public:
  enum BooleanOperator { Union, Intersection, Difference, Section, Fragments };
  OCC_Internals(){}
  void reset(){}
  void setTagConstraints(int dim, int val){}
  int getMaxTag(int dim) const { return 0; }
  void addVertex(int tag, double x, double y, double z, double meshSize=MAX_LC){}
  void addLine(int tag, int startTag, int endTag){}
  void addLine(int tag, std::vector<int> vertexTags){}
  void addCircleArc(int tag, int startTag, int centerTag, int endTag){}
  void addCircle(int tag, double x, double y, double z, double r, double angle1,
                 double angle2){}
  void addEllipseArc(int tag, int startTag, int centerTag, int endTag){}
  void addEllipse(int tag, double x, double y, double z, double r1, double r2,
                  double angle1, double angle2){}
  void addBezier(int tag, std::vector<int> vertexTags){};
  void addBSpline(int tag, std::vector<int> vertexTags){};
  void addWire(int tag, std::vector<int> edgeTags, bool closed){}
  void addLineLoop(int tag, std::vector<int> edgeTags){}
  void addRectangle(int tag, double x1, double y1, double z1,
                    double x2, double y2, double z2, double roundedRadius=0.){}
  void addDisk(int tag, double xc, double yc, double zc, double rx, double ry){}
  void addPlaneSurface(int tag, std::vector<int> wireTags){}
  void addSurfaceFilling(int tag, int wireTag){}
  void addSurfaceLoop(int tag, std::vector<int> faceTags){}
  void addVolume(int tag, std::vector<int> shellTags){}
  void addSphere(int tag, double xc, double yc, double zc, double radius,
                 double angle){};
  void addBlock(int tag, double x1, double y1, double z1,
                double x2, double y2, double z2){}
  void addCylinder(int tag, double x1, double y1, double z1, double x2, double y2,
                   double z2, double r, double angle){}
  void addCone(int tag, double x1, double y1, double z1, double x2, double y2,
               double z2, double r1, double r2, double angle){}
  void addWedge(int tag, double x, double y, double z, double dx, double dy,
                double dz, double ltx){}
  void addTorus(int tag, double x, double y, double z, double r1, double r2,
                double angle){}
  void addThruSections(int tag, std::vector<int> wireTags,
                       std::vector<int> outTags[4],
                       bool makeSolid, bool makeRuled){}
  void addThickSolid(int tag, int solidTag, std::vector<int> excludeFaceTags,
                     double offset){}
  void extrude(int tag, std::vector<int> inTags[4],
               double dx, double dy, double dz,
               std::vector<int> outTags[4]){}
  void revolve(int tag, std::vector<int> inTags[4],
               double x, double y, double z, double dx, double dy, double dz,
               double angle, std::vector<int> outTags[4]){};
  void addPipe(int tag, std::vector<int> inTags[4], int wireTag,
               std::vector<int> outTags[4]){}
  void fillet(std::vector<int> regionTags, std::vector<int> edgeTags,
              double radius, std::vector<int> outTags[4]){}
  void applyBooleanOperator(int tag, BooleanOperator op,
                            std::vector<int> shapeTags[4],
                            std::vector<int> toolTags[4],
                            std::vector<int> outTags[4],
                            bool removeShape=true,
                            bool removeTool=true){}
  void getBoundary(std::vector<int> inTags[4], std::vector<int> outTags[4],
                   bool combined=false){}
  void translate(std::vector<int> inTags[4], double dx, double dy, double dz){}
  void rotate(std::vector<int> inTags[4], double x, double y, double z,
              double dx, double dy, double dz, double angle){}
  void copy(std::vector<int> inTags[4], std::vector<int> outTags[4]){}
  void remove(std::vector<int> inTags[4]){}
  void importShapes(const std::string &fileName, bool highestDimOnly,
                    std::vector<int> outTags[4], const std::string &format="")
  {
    Msg::Error("Gmsh requires OpenCASCADE to import '%s'", fileName.c_str());
  }
  void exportShapes(const std::string &fileName, const std::string &format="")
  {
    Msg::Error("Gmsh requires OpenCASCADE to export '%s'", fileName.c_str());
  }
  void synchronize(GModel *model){}
};

#endif
#endif
