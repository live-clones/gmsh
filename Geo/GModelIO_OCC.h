// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _GMODELIO_OCC_H_
#define _GMODELIO_OCC_H_

#include "GModel.h"
#include "OCCIncludes.h"

#if defined(HAVE_OCC)

class OCC_Options {
 private:
  int _dummy;
 public:
  OCC_Options(int dummy) : _dummy(dummy){}
};

class OCC_Internals {
 protected :
  TopoDS_Shape shape;
  TopTools_IndexedMapOfShape fmap, emap, vmap, somap, shmap, wmap;
 public:
  enum BooleanOperator { Add, Cut }; 
  OCC_Internals()
  {
    somap.Clear();
    shmap.Clear();
    fmap.Clear();
    wmap.Clear();
    emap.Clear();
    vmap.Clear();
  }
  void healGeometry(double tolerance, bool fixsmalledges, 
                    bool fixspotstripfaces, bool sewfaces, 
                    bool makesolids=false);
  void loadBREP(const char *);  
  void loadSTEP(const char *);
  void loadIGES(const char *);
  void loadShape(const TopoDS_Shape *);
  void buildGModel(GModel *gm);
  void buildLists();
  void removeAllDuplicates(const double &tolerance);

  void Sphere(const SPoint3 &center, const double &radius, const BooleanOperator &op);
  void Cylinder(const SPoint3 &bottom_center, const SVector3 &dir, const BooleanOperator &op);
  void applyBooleanOperator(TopoDS_Shape tool, const BooleanOperator &op);
};

#endif
#endif
