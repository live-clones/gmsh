// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _OCC_FACE_H_
#define _OCC_FACE_H_

#include "GmshConfig.h"
#include "GFace.h"
#include "GModel.h"
#include "OCCVertex.h"
#include "OCCEdge.h"
#include "Range.h"

#if defined(HAVE_OCC)

class OCCFace : public GFace {
 protected:
  TopoDS_Face s;
  Handle(Geom_Surface) occface;
  double umin, umax, vmin, vmax;
  bool _periodic[2];
  bool buildSTLTriangulation ();
 public:
  OCCFace(GModel *m, TopoDS_Face s, int num, TopTools_IndexedMapOfShape &emap);
  virtual ~OCCFace(){}
  Range<double> parBounds(int i) const; 
  virtual GPoint point(double par1, double par2) const; 
  virtual GPoint closestPoint(const SPoint3 & queryPoint, const double initialGuess[2]) const; 
  virtual bool containsPoint(const SPoint3 &pt) const;  
  virtual SVector3 normal(const SPoint2 &param) const; 
  virtual Pair<SVector3,SVector3> firstDer(const SPoint2 &param) const; 
  virtual GEntity::GeomType geomType() const; 
  ModelType getNativeType() const { return OpenCascadeModel; }
  void * getNativePtr() const { return (void*)&s; }
  virtual SPoint2 parFromPoint(const SPoint3 &) const;
  virtual double curvature(const SPoint2 &param) const;
  surface_params getSurfaceParams() const;
};

#endif

#endif
