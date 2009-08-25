// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
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
  void healGeometry(double tolerance, bool fixsmalledges, 
                    bool fixspotstripfaces, bool sewfaces, 
                    bool makesolids=false, bool connect=false);
  void loadBREP(const char *);  
  void writeBREP(const char *);  
  void loadSTEP(const char *);
  void writeSTEP(const char *);  
  void loadIGES(const char *);
  void loadShape(const TopoDS_Shape *);
  void buildGModel(GModel *gm);
  void buildLists();
  void removeAllDuplicates(const double &tolerance);

  void Cone(const SPoint3 &p1, const SPoint3 &p2, const BooleanOperator &op);
  void Box(const SPoint3 &p1, const SPoint3 &p2, const BooleanOperator &op);
  void Sphere(const SPoint3 &center, const double &radius, const BooleanOperator &op);
  void Cylinder(const SPoint3 &bottom_center, const SVector3 &dir, double R, double H,
		const BooleanOperator &op);
  void Cone(const SPoint3 &bottom_center, const SVector3 &dir, double R1, double R2, 
	     double H,  const BooleanOperator &op);
  void Torus(const SPoint3 &bottom_center, const SVector3 &dir, double R1, double R2, 
	     const BooleanOperator &op);
  void Torus(const SPoint3 &bottom_center, const SVector3 &dir, double R1, double R2, 
	     double angle,  const BooleanOperator &op);
  void applyBooleanOperator(TopoDS_Shape tool, const BooleanOperator &op);
};

#endif
#endif
