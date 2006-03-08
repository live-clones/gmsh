#ifndef _H_GMSH_FACE_
#define _H_GMSH_FACE_

#include "gmshDefs.h"
#include "gmshModel.h"
#include "gmshVertex.h"
#include "Mesh.h"
#include "Range.h"

#ifdef _HAVE_SGMODEL_
#include "GFace.h"
static  SSList<GEdge*> e;
static  SSList<int> d;
#else
class GFace {
 public:
  GFace () 
    {};
};
#endif

class gmshFace : public GFace 
{
public:
#ifdef _HAVE_SGMODEL_
  gmshFace(SGModel *m,Surface * face):GFace (m,face->Num,e,d), s(face){}
#else
  gmshFace(SGModel *m,Surface * face): s(face){}
#endif
   virtual ~gmshFace(){}
   Range<double> parBounds(int i) const; 
   virtual int paramDegeneracies(int dir, double *par); 

   virtual SBoundingBox3d bounds() const; 
   virtual GFPoint point(double par1, double par2) const; 
   virtual GFPoint point(const SPoint2 &pt) const; 
   virtual GFPoint closestPoint(const SPoint3 & queryPoint); 

   virtual int containsPoint(const SPoint3 &pt) const;  
   virtual int containsParam(const SPoint2 &pt) const; 

   virtual SVector3 normal(const SPoint2 &param) const; 
   virtual Pair<SVector3,SVector3> firstDer(const SPoint2 &param) const; 
   virtual double * nthDerivative(const SPoint2 &param, int n,  
 				 double *array) const; 

   virtual GeomType::Value geomType() const; 
   virtual int geomDirection() const; 

   virtual Logical::Value continuous(int dim) const; 
   virtual Logical::Value periodic(int dim) const; 
   virtual Logical::Value degenerate(int dim) const; 
   virtual double period(int dir) const;	// 200306 
   virtual double tolerance() const; 
   virtual GeoRep * geometry() {return 0;}
   void * getNativePtr() const; 
   Surface *s;
   virtual Logical::Value surfPeriodic(int dim) const
   {throw;}
   virtual SPoint2 parFromPoint(const SPoint3 &) const;
protected:
};

#endif
