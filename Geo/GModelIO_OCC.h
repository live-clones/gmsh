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
  // a temporary shape FIXME will be removed
  TopoDS_Shape _shape;

  // all the (sub) TopoDS_Shapes
  TopTools_IndexedMapOfShape _vmap, _emap, _wmap, _fmap, _shmap, _somap;
  // cache mapping TopoDS_Shapes to their corresponding GEntity tags
  TopTools_DataMapOfShapeInteger _gvNumCache, _geNumCache, _gfNumCache, _grNumCache;
  // mapping between indices of the (sub) shapes in the maps and the assigned tags
  std::map<int, int> _vTagIndex, _eTagIndex, _fTagIndex, _rTagIndex;
  std::map<int, int> _vIndexTag, _eIndexTag, _fIndexTag, _rIndexTag;

 public:
  // add shape and all sub-shapes in _maps
  // FIXME: this should be private, but is currently used in deprectated
  // GModelFactory
  void _addShapeToLists(TopoDS_Shape shape, std::vector<int> indices[4]=0);

 public:
  enum BooleanOperator { Intersection, Cut, Section, Fuse };
  OCC_Internals(){}

  // add shapes only using internal OCC data
  void addVertex(int tag, double x, double y, double z);
  void addCircleArc(int tag, int startTag, int centerTag, int endTag);
  void addSphere(int tag, double xc, double yc, double zc, double radius);
  void addThruSections(int tag, std::vector<std::vector<int> > edgeTags);

  // apply boolean operation
  void applyBooleanOperator(int tag,
                            std::vector<int> shapeTags[4],
                            std::vector<int> toolTags[4],
                            BooleanOperator op,
                            bool removeShape=true, bool removeTool=true);


  // perform boolean operation on _shape, using tool
  void applyBooleanOperator(TopoDS_Shape tool, const BooleanOperator &op);

  // import all the OCC shapes into the model
  void importOCCInternals(GModel *model);

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
  void bind(TopoDS_Vertex vertex, int num){ _gvNumCache.Bind(vertex, num); }
  void bind(TopoDS_Edge edge, int num){ _geNumCache.Bind(edge, num); }
  void bind(TopoDS_Face face, int num){ _gfNumCache.Bind(face, num); }
  void bind(TopoDS_Solid solid, int num){ _grNumCache.Bind(solid, num); }
  void unbind(TopoDS_Vertex vertex){ _gvNumCache.UnBind(vertex); }
  void unbind(TopoDS_Edge edge){ _geNumCache.UnBind(edge); }
  void unbind(TopoDS_Face face){ _gfNumCache.UnBind(face); }
  void unbind(TopoDS_Solid solid){ _grNumCache.UnBind(solid); }
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
  enum BooleanOperator { Intersection, Cut, Section, Fuse };
  OCC_Internals(){}
  void addVertex(int tag, double x, double y, double z){}
  void addCircleArc(int tag, int tagStart, int tagCenter, int tagEnd){}
	void addSphere(int tag, double xc, double yc, double zc, double radius){};
  void addThruSections(int tag, std::vector<std::vector<int> > tagEdges){}
  void importOCCInternals(GModel *model){}
	void applyBooleanOperator(int tag,
                            std::vector<int> shapeTags[4],
                            std::vector<int> toolTags[4],
                            BooleanOperator op,
                            bool removeShape=true, bool removeTool=true){};
};

#endif
#endif
