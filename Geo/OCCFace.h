// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
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
  TopoDS_Face _replaced;
  TopoDS_Face s;
  Handle(Geom_Surface) occface;
  double umin, umax, vmin, vmax;
  bool _periodic[2];
  bool buildSTLTriangulation(bool force=false);
  void replaceEdgesInternal (std::list<GEdge*> &);
  void setup();
  bool _isSphere;
  double _radius;
  SPoint3 _center;
 public:
  OCCFace(GModel *m, TopoDS_Face s, int num);
  virtual ~OCCFace(){}
  Range<double> parBounds(int i) const; 
  virtual GPoint point(double par1, double par2) const; 
  virtual GPoint closestPoint(const SPoint3 & queryPoint, 
                              const double initialGuess[2]) const; 
  virtual bool containsPoint(const SPoint3 &pt) const;  
  virtual SVector3 normal(const SPoint2 &param) const; 
  virtual Pair<SVector3,SVector3> firstDer(const SPoint2 &param) const;
  virtual void secondDer(const SPoint2 &, SVector3 *, SVector3 *, SVector3 *) const;
  virtual GEntity::GeomType geomType() const; 
  ModelType getNativeType() const { return OpenCascadeModel; }
  void *getNativePtr() const { return (void*)&s; }
  virtual SPoint2 parFromPoint(const SPoint3 &, bool onSurface=true) const;
  virtual double curvatureMax(const SPoint2 &param) const;
  virtual double curvatures(const SPoint2 &param, SVector3 *dirMax, SVector3 *dirMin,
                            double *curvMax, double *curvMin) const;
  surface_params getSurfaceParams() const;
  TopoDS_Face getTopoDS_Face () {return s;}
  TopoDS_Face getTopoDS_FaceOld () {return _replaced;}
  // tells if it's a sphere, and if it is, returns parameters
  virtual bool isSphere (double &radius, SPoint3 &center) const;
};
GFace *getOCCFaceByNativePtr(GModel *model, TopoDS_Face toFind);

#endif

#endif
