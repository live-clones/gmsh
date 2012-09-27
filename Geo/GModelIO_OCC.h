// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _GMODELIO_OCC_H_
#define _GMODELIO_OCC_H_

#include "GmshConfig.h"
#include "GModel.h"
#include "OCCIncludes.h"

#if defined(HAVE_OCC)
#include <vector>

class OCC_Internals {
 protected :
  // the shape
  TopoDS_Shape shape;
  // all the (sub) TopoDS_Shapes in 'shape'
  TopTools_IndexedMapOfShape fmap, emap, vmap, somap, shmap, wmap;
  // cache mapping TopoDS_Shapes to their corresponding GEntity tags
  TopTools_DataMapOfShapeInteger gvNumCache, geNumCache, gfNumCache, grNumCache;
 public:
  enum BooleanOperator { Intersection, Cut, Section, Fuse };
  OCC_Internals(){}
  TopoDS_Shape getShape () { return shape; }
  void buildLists();
  void buildShapeFromLists(TopoDS_Shape _shape);
  void addShapeToLists(TopoDS_Shape shape);
  void healGeometry(double tolerance, bool fixdegenerated,
                    bool fixsmalledges, bool fixspotstripfaces,
                    bool sewfaces, bool makesolids=false,
                    bool connect=false);
  void loadBREP(const char *);
  void writeBREP(const char *);
  void loadSTEP(const char *);
  void writeSTEP(const char *);
  void loadIGES(const char *);
  void loadShape(const TopoDS_Shape *);
  void buildGModel(GModel *gm);
  void bind(TopoDS_Vertex vertex, int num){ gvNumCache.Bind(vertex, num); }
  void bind(TopoDS_Edge edge, int num){ geNumCache.Bind(edge, num); }
  void bind(TopoDS_Face face, int num){ gfNumCache.Bind(face, num); }
  void bind(TopoDS_Solid solid, int num){ grNumCache.Bind(solid, num); }
  void unbind(TopoDS_Vertex vertex){ gvNumCache.UnBind(vertex); }
  void unbind(TopoDS_Edge edge){ geNumCache.UnBind(edge); }
  void unbind(TopoDS_Face face){ gfNumCache.UnBind(face); }
  void unbind(TopoDS_Solid solid){ grNumCache.UnBind(solid); }
  GVertex *getOCCVertexByNativePtr(GModel *model, TopoDS_Vertex toFind);
  GEdge *getOCCEdgeByNativePtr(GModel *model, TopoDS_Edge toFind);
  GFace *getOCCFaceByNativePtr(GModel *model, TopoDS_Face toFind);
  GRegion *getOCCRegionByNativePtr(GModel *model, TopoDS_Solid toFind);
  GVertex *addVertexToModel(GModel *model, TopoDS_Vertex v);
  GEdge *addEdgeToModel(GModel *model, TopoDS_Edge e);
  GFace *addFaceToModel(GModel *model, TopoDS_Face f);
  GRegion *addRegionToModel(GModel *model, TopoDS_Solid r);
  void fillet(std::vector<TopoDS_Edge> &shapes, double radius);
  void applyBooleanOperator(TopoDS_Shape tool, const BooleanOperator &op);
};

#endif
#endif
