// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _GMODELIO_OCC_H_
#define _GMODELIO_OCC_H_

#include "GmshConfig.h"
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
  int _maxTagConstraints[4];

 protected :
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

  // add a shape and all its subshapes to _vmap, _emap, ..., _somap
  void _addShapeToMaps(TopoDS_Shape shape);

  // apply various healing algorithms to try to fix the shape
  void _healShape(TopoDS_Shape &myshape, double tolerance, bool fixdegenerated,
                  bool fixsmalledges, bool fixspotstripfaces, bool sewfaces,
                  bool makesolids=false, double scaling=0.0);


  // *** FIXME will be removed ***
 protected :
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
  void loadBREP(const char *);
  void loadSTEP(const char *);
  void loadIGES(const char *);
  void loadShape(const TopoDS_Shape *s)
  {
    std::vector<int> tags[4]; importShapes(s, tags);
  }
  // *** FIXME end of stuff that will be removed ***

 public:
  OCC_Internals();

  // bind and unbind OpenCASCADE shapes to tags
  void bind(TopoDS_Vertex vertex, int tag);
  void bind(TopoDS_Edge edge, int tag);
  void bind(TopoDS_Wire wire, int tag);
  void bind(TopoDS_Face face, int tag);
  void bind(TopoDS_Shell shell, int tag);
  void bind(TopoDS_Solid solid, int tag);
  void unbind(TopoDS_Vertex vertex, int tag);
  void unbind(TopoDS_Edge edge, int tag);
  void unbind(TopoDS_Wire wire, int tag);
  void unbind(TopoDS_Face face, int tag);
  void unbind(TopoDS_Shell shell, int tag);
  void unbind(TopoDS_Solid solid, int tag);

  // bind highest-dimensional entities in shape to tags
  void bindHighest(TopoDS_Shape shape, std::vector<int> tags[4]);

  // set constraints on tags
  void setTagConstraints(int maxTags[4]);

  // get maximum tag number for each dimension
  int getMaxTag(int dim) const;

  // add shapes only using internal OCC data
  void addVertex(int tag, double x, double y, double z);
  void addLine(int tag, int startTag, int endTag);
  void addCircleArc(int tag, int startTag, int centerTag, int endTag);
  void addLineLoop(int tag, std::vector<int> edgeTags);
  void addSurfaceLoop(int tag, std::vector<int> faceTags);
  void addSphere(int tag, double xc, double yc, double zc, double radius);
  void addBlock(int tag, double x1, double y1, double z1,
                double x2, double y2, double z2);
  void addCylinder(int tag, double x1, double y1, double z1,
                   double x2, double y2, double z2, double r);
  void addThruSections(int tag, std::vector<int> wireTags);

  // apply boolean operator
  void applyBooleanOperator(int tag, BooleanOperator op,
                            std::vector<int> shapeTags[4],
                            std::vector<int> toolTags[4],
                            std::vector<int> outTags[4],
                            bool removeShape=true,
                            bool removeTool=true);

  // get boundary of shapes of dimension dim (this will create tag for the
  // boundary parts)
  void getBoundary(std::vector<int> inTags[4], std::vector<int> outTags[4],
                   bool combined=false);

  // import shapes from file
  void importShapes(const std::string &fileName, std::vector<int> outTags[4]);

  // import shapes from TopoDS_Shape
  void importShapes(const TopoDS_Shape *shape, std::vector<int> outTags[4]);

  // export all tagged shapes to file
  void exportShapes(const std::string &fileName);

  // synchronize all shapes in maps with the given GModel
  void synchronize(GModel *model);

  GVertex *getOCCVertexByNativePtr(GModel *model, TopoDS_Vertex toFind);
  GEdge *getOCCEdgeByNativePtr(GModel *model, TopoDS_Edge toFind);
  GFace *getOCCFaceByNativePtr(GModel *model, TopoDS_Face toFind);
  GRegion *getOCCRegionByNativePtr(GModel *model, TopoDS_Solid toFind);
  GVertex *addVertexToModel(GModel *model, TopoDS_Vertex v);
  GEdge *addEdgeToModel(GModel *model, TopoDS_Edge e);
  GFace *addFaceToModel(GModel *model, TopoDS_Face f);
  GRegion *addRegionToModel(GModel *model, TopoDS_Solid r);
};

#else

class OCC_Internals {
public:
  enum BooleanOperator { Union, Intersection, Difference, Section, Fragments };
  OCC_Internals(){}
  void setTagConstraints(int maxTags[4]){}
  int getMaxTag(int dim) const { return 0; }
  void addVertex(int tag, double x, double y, double z){}
  void addLine(int tag, int startTag, int endTag){}
  void addCircleArc(int tag, int startTag, int centerTag, int endTag){}
  void addLineLoop(int tag, std::vector<int> edgeTags){}
  void addSurfaceLoop(int tag, std::vector<int> faceTags){}
  void addSphere(int tag, double xc, double yc, double zc, double radius){};
  void addBlock(int tag, double x1, double y1, double z1,
                double x2, double y2, double z2){}
  void addCylinder(int tag, double x1, double y1, double z1,
                   double x2, double y2, double z2, double r){}
  void addThruSections(int tag, std::vector<int> wireTags){}
  void applyBooleanOperator(int tag, BooleanOperator op,
                            std::vector<int> shapeTags[4],
                            std::vector<int> toolTags[4],
                            std::vector<int> outTags[4],
                            bool removeShape=true,
                            bool removeTool=true){}
  void getBoundary(std::vector<int> inTags[4], std::vector<int> outTags[4],
                   bool combined=false){}
  void importShapes(const std::string &fileName, std::vector<int> outTags[4]){}
  void exportShapes(const std::string &fileName){}
  void synchronize(GModel *model){}
};

#endif
#endif
