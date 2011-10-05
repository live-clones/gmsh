// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
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
  TopoDS_Shape shape;
  TopTools_IndexedMapOfShape fmap, emap, vmap, somap, shmap, wmap;
 public:
  enum BooleanOperator { Intersection, Cut, Section, Fuse }; 
  OCC_Internals()
  {
    somap.Clear();
    shmap.Clear();
    fmap.Clear();
    wmap.Clear();
    emap.Clear();
    vmap.Clear();
  }
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
  GVertex *addVertexToModel(GModel *model, TopoDS_Vertex v);
  GEdge *addEdgeToModel(GModel *model, TopoDS_Edge e);
  GFace *addFaceToModel(GModel *model, TopoDS_Face f);
  GRegion *addRegionToModel(GModel *model, TopoDS_Solid r);
  void fillet(std::vector<TopoDS_Edge> &shapes, double radius);
  void applyBooleanOperator(TopoDS_Shape tool, const BooleanOperator &op);
};

#endif
#endif
