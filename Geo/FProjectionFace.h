#ifndef _F_PROJECTION_FACE_H_
#define _F_PROJECTION_FACE_H_

#include "GModel.h"
#include "Range.h"

#if defined(HAVE_FOURIER_MODEL)

#include "FM_ProjectionSurface.h"

class FProjectionFace : public GFace {
 protected:
  FM::ProjectionSurface* ps_;

 public:
  FProjectionFace(GModel *m, int num);
  FProjectionFace(GModel *m, int num, FM::ProjectionSurface* ps);
  ~FProjectionFace();

  Range<double> parBounds(int i) const;
  GPoint point(double par1, double par2) const; 
  SVector3 normal(const SPoint2 &param) const; 
  Pair<SVector3,SVector3> firstDer(const SPoint2 &param) const; 
  SPoint2 parFromPoint(const SPoint3 &) const;

  virtual int paramDegeneracies(int dir, double *par) { return 0; }
  virtual GPoint closestPoint(const SPoint3 & queryPoint) const {throw;}
  virtual int containsPoint(const SPoint3 &pt) const {throw;}  
  virtual int containsParam(const SPoint2 &pt) const {throw;}
  virtual GEntity::GeomType geomType() const 
  { return GEntity::ProjectionFace; }
  virtual int geomDirection() const { return 1; }
  virtual bool continuous(int dim) const { return true; }
  virtual bool periodic(int dim) const { return false; }
  virtual bool degenerate(int dim) const { return false; }
  virtual double period(int dir) const {throw;}
  ModelType getNativeType() const { return UnknownModel; }
  void * getNativePtr() const {throw;} 
  virtual bool surfPeriodic(int dim) const {throw;}

  inline FM::ProjectionSurface* GetProjectionSurface() { return ps_; }
};

#endif

#endif
