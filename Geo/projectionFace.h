#ifndef _PROJECTION_FACE_H_
#define _PROJECTION_FACE_H_

#include "GFace.h"

/* Specific to the derived classes, we're going to need functions
   which can be used to easily adjust the parameters of the functions.
   plus, we're going to have to implement all that stuff in GFace
   eventually. */
SVector3 scalePoint(SVector3 p, SVector3 s);
SVector3 rotatePoint(SVector3 p, SVector3 r);

class projectionFace : public GFace {
 protected:
  SVector3 rotation; //this vector holds the euler angles at which the surface is rotated
  SVector3 translation; //this vector holds the location of the reference point in xyz space
  SVector3 scaleFactor; //this vector holds the scaling factors w.r.t x,y,z
 public:
  projectionFace(GModel *m, int num);
  ~projectionFace();

  void rotate(SVector3 rot); //rotates the surface by the euler angles rot
  void translate(SVector3 trans); //translates the surface by trans
  void scale(SVector3 sc); //scales the surface along the (local?) x,y,z axes by sc
  void setScale(SVector3 sc);
  void setRotation(SVector3 r);
  void setTranslation(SVector3 t);
  
  Range<double> parBounds(int i) const {throw;} 
  virtual int paramDegeneracies(int dir, double *par) { return 0; }
  virtual GPoint point(double par1, double par2) const {throw;} 
  virtual GPoint point(const SPoint2 &pt) const {throw;} 
  virtual GPoint closestPoint(const SPoint3 & queryPoint) const {throw;}
  virtual int containsPoint(const SPoint3 &pt) const {throw;}  
  virtual int containsParam(const SPoint2 &pt) const {throw;} 
  virtual SVector3 normal(const SPoint2 &param) const {throw;} 
  virtual Pair<SVector3,SVector3> firstDer(const SPoint2 &param) const {throw;} 
  virtual double * nthDerivative(const SPoint2 &param, int n,  
 				 double *array) const {throw;}
  virtual GEntity::GeomType geomType() const { return GEntity::ProjectionSurface; }
  virtual int geomDirection() const { return 1; }
  virtual bool continuous(int dim) const { return true; }
  virtual bool periodic(int dim) const { return false; }
  virtual bool degenerate(int dim) const { return false; }
  virtual double period(int dir) const {throw;}
  ModelType getNativeType() const { return UnknownModel; }
  void * getNativePtr() const {throw;} 
  virtual bool surfPeriodic(int dim) const {throw;}
  virtual SPoint2 parFromPoint(const SPoint3 &) const {throw;}  
};

class parabolicCylinder : public projectionFace {
 protected:
  double focalPoint; //the length from the vertex to the focal point
 public:
  parabolicCylinder(GModel *m, int num);
  ~parabolicCylinder();
  Range<double> parBounds(int i) const;
  GPoint point(double par1, double par2) const; 
  GPoint point(const SPoint2 &pt) const; 
  SVector3 normal(const SPoint2 &param) const; 
  Pair<SVector3,SVector3> firstDer(const SPoint2 &param) const; 
  SPoint2 parFromPoint(const SPoint3 &) const;
};

#endif
