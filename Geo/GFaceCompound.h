// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _G_FACECOMPOUND_H_
#define _G_FACECOMPOUND_H_

#include "Geo.h"
#include "GFace.h"

/*
A GFaceCompound is a model face that is the
compound of model faces. 

The user selects 4 corners to the compound. 

Those 2 corners are mapped to points
(0,0), (1,0), (1,1) and (0,1)

of the compound parametric plane.

It is assumed that all the faces of the
compound have been meshed first. We use
this discretization to solve 2 elliptic
problems on the compound. Those 2 problems
enables to compute the parametric coordinates 
of the mesh points. The parametrization of
the compound consist in a triangulation in
the (u,v) space with parameter values at nodes.  

The compound can therefore be re-meshed using
any surface mesh generator of gmsh !

*/

#include "GFace.h"
#include "GEdge.h"
typedef struct {
  SPoint2 p1, p2, p3;
  MTriangle *t;
} GFaceCompoundTriangle;

class Octree;

class GFaceCompound : public GFace {
 protected:
  std::list<GFace*> _compound;
  std::list<GEdge*> _U0,_U1,_V0,_V1;
  mutable GFaceCompoundTriangle *_gfct;
  mutable Octree *oct;
  mutable std::map<MVertex*,SPoint2> coordinates;
  void buildOct()const ;
  void parametrize(bool) const ;
  void parametrize() const {
    if (!oct){
      parametrize(0);
      parametrize(1);
      buildOct();
    }
  }
  void getBoundingEdges();
  void getTriangle (double u, double v, MTriangle **t, double &_u, double &_v) const;
public:
  GFaceCompound(GModel *m, int tag, 
		std::list<GFace*> &compound,
		std::list<GEdge*> &U0,
		std::list<GEdge*> &U1,
		std::list<GEdge*> &V0,
		std::list<GEdge*> &V1);
  virtual ~GFaceCompound();
  Range<double> parBounds(int i) const{return Range<double>(0, 1);} 
  virtual GPoint point(double par1, double par2) const; 
  virtual GPoint closestPoint(const SPoint3 & queryPoint, const double initialGuess[2]) const{throw;}
  virtual Pair<SVector3,SVector3> firstDer(const SPoint2 &param) const; 
  virtual GEntity::GeomType geomType() const {return CompoundSurface;} 
  ModelType getNativeType() const { return GmshModel; }
  void * getNativePtr() const { return 0; }
  SPoint2 getCoordinates (MVertex *v) const { parametrize() ; return coordinates[v];}
  virtual bool buildRepresentationCross(){};
};

#endif
