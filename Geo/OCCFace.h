// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _OCC_FACE_H_
#define _OCC_FACE_H_

#include "GmshConfig.h"
#include "GFace.h"
#include "GModel.h"
#include "Range.h"

#if defined(HAVE_OCC)

#include <TopoDS_Face.hxx>

class OCCFace : public GFace {
 protected:
  TopoDS_Face _replaced;
  TopoDS_Face s;
  Handle(Geom_Surface) occface;
  double umin, umax, vmin, vmax;
  bool _periodic[2];
  double _period[2];
  bool buildSTLTriangulation(bool force=false);
  //  void replaceEdgesInternal (std::list<GEdge*> &);
  void setup();
  double _radius;
  SPoint3 _center;
 public:
  OCCFace(GModel *m, TopoDS_Face s, int num);
  virtual ~OCCFace();
  virtual SBoundingBox3d bounds() const;
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
  TopoDS_Face getTopoDS_Face () { return s; }
  TopoDS_Face getTopoDS_FaceOld () { return _replaced; }
  // tells if it's a sphere, and if it is, returns parameters
  virtual bool isSphere (double &radius, SPoint3 &center) const;
  virtual bool periodic(int dim) const { return _periodic[dim]; }
  virtual double period(int dim) const { return _period[dim]; }
  // true if the parameter value is interior to the face (taking into account boundaries)
  virtual bool containsParam(const SPoint2 &pt) ;
};

#endif

#endif
