// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _GFACE_COMPOUND_H_
#define _GFACE_COMPOUND_H_

#include <list>
#include <map>
#include "GFace.h"
#include "GEdge.h"
#include "GEdgeCompound.h"
#include "meshGFaceOptimize.h"
#include "linearSystem.h"

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
  MTriangle *tri;
  GFaceCompoundTriangle() : gf(0), tri(0) {}
};

class Octree;

class GFaceCompound : public GFace {
 public:
  typedef enum {ITERU=0,ITERV=1,ITERD=2} iterationStep;
  void computeNormals(std::map<MVertex*, SVector3> &normals) const;
 protected:
  std::list<GFace*> _compound;
  std::list<GEdge*> _U0, _U1, _V0, _V1;
  std::list<std::list<GEdge*> > _interior_loops;
  mutable int nbT;
  mutable GFaceCompoundTriangle *_gfct;
  mutable Octree *oct;
  mutable v2t_cont adjv;
  mutable bool mapv2Tri;
  mutable std::map<MVertex*, SPoint3> coordinates;
  mutable std::map<MVertex*, SVector3> _normals;
  void buildOct() const ;
  void parametrize() const ;
  void parametrize_conformal() const ;
  void compute_distance() const ;
  void parametrize(iterationStep) const ;
  bool checkOrientation() const;
  void one2OneMap() const;
  bool checkCavity(std::vector<MElement*> &vTri) const;
  void computeNormals () const;
  void getBoundingEdges();
  void getUniqueEdges(std::set<GEdge*> & _unique); 
  void computeALoop(std::set<GEdge*> & _unique, std::list<GEdge*> &);
  void getTriangle(double u, double v, GFaceCompoundTriangle **lt, 
                   double &_u, double &_v) const;
  virtual double curvature(MTriangle *t, double u, double v) const;
  void printStuff() const;
  bool trivial() const ;
  linearSystem <double> *_lsys;
 public:
  typedef enum {UNITCIRCLE, SQUARE} typeOfIsomorphism;
  GFaceCompound(GModel *m, int tag, std::list<GFace*> &compound,
                std::list<GEdge*> &U0, std::list<GEdge*> &U1,
                std::list<GEdge*> &V0, std::list<GEdge*> &V1,
		linearSystem<double>* lsys =0);
  virtual ~GFaceCompound();
  Range<double> parBounds(int i) const 
  { return trivial() ? (*(_compound.begin()))->parBounds(i) : Range<double>(-1, 1); }
  virtual GPoint point(double par1, double par2) const; 
  virtual Pair<SVector3,SVector3> firstDer(const SPoint2 &param) const;
  virtual void secondDer(const SPoint2 &, SVector3 *, SVector3 *, SVector3 *) const; 
  virtual GEntity::GeomType geomType() const { return CompoundSurface; }
  ModelType getNativeType() const { return GmshModel; }
  void * getNativePtr() const { return 0; }
  virtual SPoint2 getCoordinates(MVertex *v) const;
  virtual bool buildRepresentationCross(){ return false; }
  virtual double curvatureMax(const SPoint2 &param) const;
  virtual int genusGeom ();
 private:
  typeOfIsomorphism _type;
};

#endif
