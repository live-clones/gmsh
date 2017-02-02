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
 protected :
  // a temporary shape
  // FIXME will be removed
  TopoDS_Shape _shape;

  // all the (sub)shapes, updated dynamically when shapes need to be imported
  // into a GModel
  TopTools_IndexedMapOfShape _vmap, _emap, _wmap, _fmap, _shmap, _somap;

  // cache mapping TopoDS_Shapes to their corresponding GEntity tags
  TopTools_DataMapOfShapeInteger _vertexTag, _edgeTag, _faceTag, _solidTag;
  TopTools_DataMapOfIntegerShape _tagVertex, _tagEdge, _tagFace, _tagSolid;

  // get maximum tag number for each dimension
  int _getMaxTag(int dim) const;

  // add a shape and all its subshapes to _vmap, _emap, ..., _somap
  void _addShapeToMaps(TopoDS_Shape shape);

 public:
  // FIXME: will be removed with GModelFactory
  void _addShapeToLists(TopoDS_Shape shape){ _addShapeToMaps(shape); }

 public:
  enum BooleanOperator { Intersection, Cut, Section, Fuse };
  OCC_Internals() {}

  // add shapes only using internal OCC data
  void addVertex(int tag, double x, double y, double z);
  void addCircleArc(int tag, int startTag, int centerTag, int endTag);
  void addSphere(int tag, double xc, double yc, double zc, double radius);
  void addBlock(int tag, double x1, double y1, double z1,
                double x2, double y2, double z2);
  void addCylinder(int tag, double x1, double y1, double z1,
                   double x2, double y2, double z2, double r);
  void addThruSections(int tag, std::vector<std::vector<int> > edgeTags);

  // apply boolean operation
  std::vector<int> applyBooleanOperator(int tag,
                                        std::vector<int> shapeTags[4],
                                        std::vector<int> toolTags[4],
                                        BooleanOperator op,
                                        bool removeShape=true,
                                        bool removeTool=true);

  // import all the shapes into the model
  void importOCCInternals(GModel *model);

  void bind(TopoDS_Vertex vertex, int tag)
  {
    _vertexTag.Bind(vertex, tag);
    _tagVertex.Bind(tag, vertex);
  }
  void bind(TopoDS_Edge edge, int tag)
  {
    _edgeTag.Bind(edge, tag);
    _tagEdge.Bind(tag, edge);
  }
  void bind(TopoDS_Face face, int tag)
  {
    _faceTag.Bind(face, tag);
    _tagFace.Bind(tag, face);
  }
  void bind(TopoDS_Solid solid, int tag)
  {
    _solidTag.Bind(solid, tag);
    _tagSolid.Bind(tag, solid);
  }
  void unbind(TopoDS_Vertex vertex, int tag)
  {
    _vertexTag.UnBind(vertex);
    _tagVertex.UnBind(tag);
  }
  void unbind(TopoDS_Edge edge, int tag)
  {
    _edgeTag.UnBind(edge);
    _tagEdge.UnBind(tag);
  }
  void unbind(TopoDS_Face face, int tag)
  {
    _faceTag.UnBind(face);
    _tagFace.UnBind(tag);
  }
  void unbind(TopoDS_Solid solid, int tag)
  {
    _solidTag.UnBind(solid);
    _tagSolid.UnBind(tag);
  }
  GVertex *getOCCVertexByNativePtr(GModel *model, TopoDS_Vertex toFind);
  GEdge *getOCCEdgeByNativePtr(GModel *model, TopoDS_Edge toFind);
  GFace *getOCCFaceByNativePtr(GModel *model, TopoDS_Face toFind);
  GRegion *getOCCRegionByNativePtr(GModel *model, TopoDS_Solid toFind);
  GVertex *addVertexToModel(GModel *model, TopoDS_Vertex v);
  GEdge *addEdgeToModel(GModel *model, TopoDS_Edge e);
  GFace *addFaceToModel(GModel *model, TopoDS_Face f);
  GRegion *addRegionToModel(GModel *model, TopoDS_Solid r);


  // FIXME ************* OLD **************

  // perform boolean operation on _shape, using tool
  void applyBooleanOperator(TopoDS_Shape tool, const BooleanOperator &op);

  // manipulate _shape
  TopoDS_Shape getShape () { return _shape; }
  void buildLists();
  void buildShapeFromLists(TopoDS_Shape shape);

  void healGeometry(double tolerance, bool fixdegenerated,
                    bool fixsmalledges, bool fixspotstripfaces,
                    bool sewfaces, bool makesolids=false,
                    int connect=0, double scaling=0.0);
  void fillet(std::vector<TopoDS_Edge> &shapes, double radius);

  // I/O towards GModel
  void buildShapeFromGModel(GModel*);
  void buildGModel(GModel *gm);
  void loadBREP(const char *);
  void writeBREP(const char *);
  void loadSTEP(const char *);
  void writeSTEP(const char *);
  void loadIGES(const char *);
  void loadShape(const TopoDS_Shape *);
};

#else

class OCC_Internals {
public:
  enum BooleanOperator { Intersection, Cut, Section, Fuse };
  OCC_Internals(){}
  void addVertex(int tag, double x, double y, double z){}
  void addCircleArc(int tag, int tagStart, int tagCenter, int tagEnd){}
  void addSphere(int tag, double xc, double yc, double zc, double radius){};
  void addBlock(int tag, double x1, double y1, double z1,
                double x2, double y2, double z2){}
  void addCylinder(int tag, double x1, double y1, double z1,
                   double x2, double y2, double z2, double r){}
  void addThruSections(int tag, std::vector<std::vector<int> > tagEdges){}
  void importOCCInternals(GModel *model){}
  std::vector<int> applyBooleanOperator(int tag,
                                        std::vector<int> shapeTags[4],
                                        std::vector<int> toolTags[4],
                                        BooleanOperator op,
                                        bool removeShape=true,
                                        bool removeTool=true){}
};

#endif
#endif
