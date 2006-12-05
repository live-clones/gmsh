#ifndef _PROJECTION_FACE_H_
#define _PROJECTION_FACE_H_

#include "GFace.h"

/*
What functions we need for this class and all derived classes:
1. given point in xyz space, compute xyz point on surface
2. given point in xyz on surface, compute uv co-ordinate
3. given point in uv, compute xyz co-ordinate on surface

functions 2 and 3 are already virtual functions associated with GFace so let's make sure we implement them correctly.
Specific to the derived classes, we're going to also need functions which can be used to easily adjust the parameters of the functions.
plus, we're going to have to implement all that stuff in GFace eventually.
*/
SVector3 scalePoint(SVector3 p, SVector3 s);
SVector3 rotatePoint(SVector3 p, SVector3 r);

class projectionFace : public GFace
{
 protected:
  	//Surface *s; //what is this?

	SVector3 rotation; //this vector holds the euler angles at which the surface is rotated
	SVector3 translation; //this vector holds the location of the reference point in xyz space
	SVector3 scaleFactor; //this vector holds the scaling factors w.r.t x,y,z
 public:

  projectionFace(GModel *m, int num);

  ~projectionFace();

	void rotate(SVector3 rot); //rotates the surface by the euler angles rot
	void translate(SVector3 trans);	//translates the surface by trans
	void scale(SVector3 sc);	//scales the surface along the (local?) x,y,z axes by sc



  
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

class parabolicCylinder : public projectionFace
{
  protected:
	double focalPoint; //the length from the vertex to the focal point
	//SPoint3 directrixPoint; //the point on the directrix opposite wrt the vertex of the focal point
	//SVector3 directrixLine; //the direction in which the directrix extends
//	double length; //the length of the parabola - just scaling factors
//	double height; //the height of the cylinder - just scaling factors
  public:

  parabolicCylinder(GModel *m, int num);

	~parabolicCylinder();

  Range<double> parBounds(int i) const;
  
  GPoint point(double par1, double par2) const; 
  GPoint point(const SPoint2 &pt) const; 
//  virtual GPoint closestPoint(const SPoint3 & queryPoint) const; 

  SVector3 normal(const SPoint2 &param) const; 
  Pair<SVector3,SVector3> firstDer(const SPoint2 &param) const; 
  //virtual double * nthDerivative(const SPoint2 &param, int n,  
 	//			 double *array) const {throw;}
  

//  virtual int geomDirection() const { return 1; }
  
//  virtual bool continuous(int dim) const { return true; }
//  virtual bool periodic(int dim) const { return false; }
//  virtual bool degenerate(int dim) const { return false; }
//  virtual double period(int dir) const {throw;}
//  ModelType getNativeType() const { return UnknownModel; }
//  void * getNativePtr() const {throw;} 
//  virtual bool surfPeriodic(int dim) const {throw;}

  SPoint2 parFromPoint(const SPoint3 &) const;
 	
};
#endif
