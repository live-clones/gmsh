// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _GFACE_COMPOUND_H_
#define _GFACE_COMPOUND_H_

#include "GFace.h"
#include "GEdge.h"

/*
A GFaceCompound is a model face that is the compound of model faces.

The user selects 4 corners to the compound, which are mmapped to
points (0,0), (1,0), (1,1) and (0,1) of the compound parametric plane.

It is assumed that all the faces of the compound have been meshed
first. We use this discretization to solve 2 elliptic problems on the
compound. Those 2 problems enables to compute the parametric
coordinates of the mesh points. The parametrization of the compound
consist in a triangulation in the (u,v) space with parameter values at
nodes.

The compound can therefore be re-meshed using any surface mesh
generator of gmsh!
*/

class  GFaceCompoundTriangle {
public:
  SPoint3 p1, p2, p3;
  SPoint2 gfp1, gfp2, gfp3;
  SPoint3 v1, v2, v3;
  GFace *gf;
  GFaceCompoundTriangle () : gf(0)
  {}
} ;

class Octree;

class GFaceCompound : public GFace {
 public:
  typedef enum {ITERU=0,ITERV=1,ITERD=2} iterationStep;
 protected:
  std::list<GFace*> _compound;
  std::list<GEdge*> _U0, _U1, _V0, _V1;
  mutable GFaceCompoundTriangle *_gfct;
  mutable Octree *oct;
  mutable std::map<MVertex*,SPoint3> coordinates;
  mutable std::map<MVertex*,SVector3> _normals;
  void buildOct() const ;
  void parametrize() const ;
  void parametrize(iterationStep) const ;
  void computeNormals () const;
  void getBoundingEdges();
  void getTriangle(double u, double v, GFaceCompoundTriangle **lt, 
                   double &_u, double &_v) const;
  virtual double curvature(MTriangle *t) const;
public:
  typedef enum {UNITCIRCLE, SQUARE} typeOfIsomorphism;
  GFaceCompound(GModel *m, int tag, 
		std::list<GFace*> &compound,
		std::list<GEdge*> &U0,
		std::list<GEdge*> &U1,
		std::list<GEdge*> &V0,
		std::list<GEdge*> &V1);
  virtual ~GFaceCompound();
  Range<double> parBounds(int i) const { return Range<double>(0, 1); } 
  virtual GPoint point(double par1, double par2) const; 
  virtual Pair<SVector3,SVector3> firstDer(const SPoint2 &param) const; 
  virtual GEntity::GeomType geomType() const { return CompoundSurface; }
  ModelType getNativeType() const { return GmshModel; }
  void * getNativePtr() const { return 0; }
  SPoint2 getCoordinates(MVertex *v) const { 
    parametrize() ; 
    std::map<MVertex*,SPoint3>::iterator it = coordinates.find(v);
    return SPoint2(it->second.x(),it->second.y()); 
  }
  virtual bool buildRepresentationCross(){ return false; }
  virtual double curvature(const SPoint2 &param) const;
private:
  typeOfIsomorphism _type;
};

#endif
