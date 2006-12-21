#ifndef _FOURIER_MODEL_H_
#define _FOURIER_MODEL_H_

#include "GModel.h"

#if defined(HAVE_FOURIER_MODEL)

#include "GVertex.h"
#include "GEdge.h"
#include "GFace.h"
#include "Range.h"

class fourierVertex : public GVertex {
 private:
  MVertex *_v;
 public:
  fourierVertex(GModel *m, MVertex *v) : GVertex(m, v->getNum()), _v(v)
  {
    mesh_vertices.push_back(v);
  }
  virtual ~fourierVertex() {}
  virtual GPoint point() const { return GPoint(_v->x(), _v->y(), _v->z(), this); }
  virtual double x() const { return _v->x(); }
  virtual double y() const { return _v->y(); }
  virtual double z() const { return _v->z(); }
  virtual double prescribedMeshSizeAtVertex() const { return 0.1; }
  ModelType getNativeType() const { return FourierModel; }
};

class fourierEdge : public GEdge {
 public:
  fourierEdge(GModel *m, int num, GVertex *v1, GVertex *v2);
  virtual ~fourierEdge() {}
  double period() const { throw ; }
  virtual bool periodic(int dim=0) const { return false; }
  virtual Range<double> parBounds(int i) const { throw; }
  virtual GeomType geomType() const { throw; }
  virtual bool degenerate(int) const { return false; }
  virtual bool continuous(int dim) const { return true; }
  virtual GPoint point(double p) const { throw; }
  virtual GPoint closestPoint(const SPoint3 & queryPoint) { throw; }
  virtual int containsPoint(const SPoint3 &pt) const { throw; }
  virtual int containsParam(double pt) const { throw; }
  virtual SVector3 firstDer(double par) const { throw; }
  virtual SPoint2 reparamOnFace(GFace * face, double epar, int dir) const { throw; }
  virtual double parFromPoint(const SPoint3 &pt) const { throw; }
  virtual int minimumMeshSegments () const { throw; }
  virtual int minimumDrawSegments () const { throw; }
  ModelType getNativeType() const { return FourierModel; }
};

class fourierFace : public GFace {
 private:
  // flag to know if is the face is already meshed
  int _discrete;
  // floag to know if the face is just a plane
  int _plane;
  // vertices and edges purely local to the face (not shared with the model)
  GVertex *_v[4];
  GEdge *_e[4];
 public:
  fourierFace(GModel *m, int num);
  fourierFace(GFace *f, std::vector<MVertex*> &loop, std::vector<MVertex*> &hole);
  virtual ~fourierFace();

  void meshBoundary();

  Range<double> parBounds(int i) const; 
  virtual int paramDegeneracies(int dir, double *par) { return 0; }
  
  virtual GPoint point(double par1, double par2) const; 
  virtual GPoint point(const SPoint2 &pt) const; 
  virtual GPoint closestPoint(const SPoint3 & queryPoint) const ; 
  
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
  ModelType getNativeType() const { return FourierModel; }
  void * getNativePtr() const {throw;} 
  virtual bool surfPeriodic(int dim) const {throw;}
  virtual SPoint2 parFromPoint(const SPoint3 &) const;
};

#endif

#endif
