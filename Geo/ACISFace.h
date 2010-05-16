// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _ACIS_FACE_H_
#define _ACIS_FACE_H_

#include "GmshConfig.h"
#include "GFace.h"
#include "GModel.h"
#include "ACISVertex.h"
#include "ACISEdge.h"
#include "Range.h"

#if defined(HAVE_ACIS)
#include <face.hxx>
#include <surface.hxx>
class ACISFace : public GFace {
 protected:
  FACE *_f;
  double umin, umax, vmin, vmax;
  bool _periodic[2];
 public:
  ACISFace(GModel *m, FACE *f, int num);
  virtual ~ACISFace(){}
  Range<double> parBounds(int i) const; 
  virtual GPoint point(double par1, double par2) const; 
  virtual GPoint closestPoint(const SPoint3 & queryPoint, const double initialGuess[2]) const; 
  virtual bool containsPoint(const SPoint3 &pt) const;  
  virtual SVector3 normal(const SPoint2 &param) const; 
  virtual Pair<SVector3,SVector3> firstDer(const SPoint2 &param) const;
  virtual void secondDer(const SPoint2 &, SVector3 *, SVector3 *, SVector3 *) const;
  virtual GEntity::GeomType geomType() const; 
  ModelType getNativeType() const { return AcisModel; }
  void *getNativePtr() const { return (void*)_f; }
  virtual SPoint2 parFromPoint(const SPoint3 &) const;
  virtual double curvatureMax(const SPoint2 &param) const;
  virtual double curvatures(const SPoint2 &param, SVector3 *dirMax, SVector3 *dirMin,
                            double *curvMax, double *curvMin) const;
  bool buildSTLTriangulation(bool force);
  FACE* getFACE () {return _f;}
};
GFace *getACISFaceByNativePtr(GModel *model, FACE *);

#endif

#endif
