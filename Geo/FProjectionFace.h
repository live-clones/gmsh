#ifndef _F_PROJECTION_FACE_H_
#define _F_PROJECTION_FACE_H_

#include "GModel.h"
#include "Range.h"

#if defined(HAVE_FOURIER_MODEL)

#include "FM_ProjectionSurface.h"

class FProjectionFace : public GFace {
 protected:
  FM::ProjectionSurface *ps_;
 public:
  FProjectionFace(GModel *m, int num);
  FProjectionFace(GModel *m, int num, FM::ProjectionSurface* ps);
  ~FProjectionFace();
  Range<double> parBounds(int i) const;
  GPoint point(double par1, double par2) const; 
  SVector3 normal(const SPoint2 &param) const; 
  Pair<SVector3,SVector3> firstDer(const SPoint2 &param) const; 
  SPoint2 parFromPoint(const SPoint3 &) const;
  virtual int containsParam(const SPoint2 &pt) const { throw; }
  virtual GEntity::GeomType geomType() const { return GEntity::ProjectionFace; }
  ModelType getNativeType() const { return UnknownModel; }
  void *getNativePtr() const { return ps_; } 
};

#endif

#endif
