#ifndef _FOURIER_MODEL_H_
#define _FOURIER_MODEL_H_

#include "GModel.h"

#if defined(HAVE_FOURIER_MODEL)

class fourierModel : public GModel {
 public:
  fourierModel(const std::string &name);
  virtual ~fourierModel();
};

#include "GFace.h"
#include "Range.h"

class fourierFace : public GFace {
 private:
  int _num;
 public:
  fourierFace(GModel *m, int num);
  virtual ~fourierFace(){}
  Range<double> parBounds(int i) const; 
  virtual int paramDegeneracies(int dir, double *par) { return 0; }
  
  virtual GPoint point(double par1, double par2) const; 
  virtual GPoint point(const SPoint2 &pt) const; 
  virtual GPoint closestPoint(const SPoint3 & queryPoint) ; 
  
  virtual int containsPoint(const SPoint3 &pt) const;  
  virtual int containsParam(const SPoint2 &pt) const; 
  
  virtual SVector3 normal(const SPoint2 &param) const; 
  virtual Pair<SVector3,SVector3> firstDer(const SPoint2 &param) const {throw;} 
  virtual double * nthDerivative(const SPoint2 &param, int n,  
 				 double *array) const {throw;}
  
  virtual GEntity::GeomType geomType() const; 
  virtual int geomDirection() const { return 1; }
  
  virtual bool continuous(int dim) const { return true; }
  virtual bool periodic(int dim) const { return false; }
  virtual bool degenerate(int dim) const { return false; }
  virtual double period(int dir) const {throw;}
  void * getNativePtr() const {throw;} 
  virtual bool surfPeriodic(int dim) const {throw;}
  virtual SPoint2 parFromPoint(const SPoint3 &) const;
};

#endif

#endif
