#ifndef _F_FACE_H_
#define _F_FACE_H_

#include "GFace.h"
#include "GModel.h"
#include "Range.h"
#include "FEdge.h"

#if defined(HAVE_FOURIER_MODEL)

#include "FM_TopoFace.h"

class FFace : public GFace {
 protected:
  FM::TopoFace *face;
 public:
  FFace(GModel *m, FM::TopoFace *face_, int tag, std::list<GEdge*> l_edges_);
  FFace(GModel *m, FM::TopoFace *face_, int tag, std::list<GEdge*> l_edges_,
	std::list<int> l_dirs_);

  virtual ~FFace() {}

  Range<double> parBounds(int i) const; 
  virtual int paramDegeneracies(int dir, double *par) { return 0; }
  virtual GPoint point(double par1, double par2) const; 
  virtual GPoint point(const SPoint2 &pt) const; 
  virtual SPoint2 parFromPoint(const SPoint3 &p) const;
  virtual GPoint closestPoint(const SPoint3 & queryPoint) const; 
  virtual int containsPoint(const SPoint3 &pt) const;  
  virtual int containsParam(const SPoint2 &pt) const; 
  virtual SVector3 normal(const SPoint2 &param) const; 
  virtual GEntity::GeomType geomType() const;
  virtual Pair<SVector3,SVector3> 
    firstDer(const SPoint2 &param) const {throw;} 
  virtual double * nthDerivative
    (const SPoint2 &param, int n, double *array) const {throw;}  
  virtual int geomDirection() const { return 1; }
  virtual bool continuous(int dim) const { return true; }
  virtual bool periodic(int dim) const { return false; }
  virtual bool degenerate(int dim) const { return false; }
  virtual double period(int dir) const;
  ModelType getNativeType() const { return FourierModel; }
  void * getNativePtr() const {throw;} 
  virtual bool surfPeriodic(int dim) const;
  FM::TopoFace* GetFMFace() { return face; }
};

#endif

#endif

