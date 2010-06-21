// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _GMODEL_FACTORY_H_
#define _GMODEL_FACTORY_H_

#include <vector>
#include "GmshConfig.h"
#include "fullMatrix.h"
#include "SPoint3.h"
#include "GEntity.h"

class GVertex;
class GEdge;
class GModel;

// Abstract CAD creation factory.
class GModelFactory {
 public:
  GModelFactory(){}
  virtual ~GModelFactory(){}

  // brep primitives
  enum arcCreationMethod {THREE_POINTS=1, CENTER_START_END=2};
  enum splineType {BEZIER=1, BSPLINE=2};
  // vertex primitive
  virtual GVertex *addVertex(GModel *gm, double x, double y, double z, 
                             double lc) = 0;
  // edge primitives
  virtual GEdge *addLine(GModel *, GVertex *v1, GVertex *v2) = 0;
  virtual GEdge *addCircleArc(GModel *gm, const arcCreationMethod &method,
                              GVertex *start, GVertex *end, 
                              const SPoint3 &aPoint) = 0;
  virtual GEdge *addSpline(GModel *gm,const splineType &type,
                           GVertex *start, 
                           GVertex *end, 
                           std::vector<std::vector<double> > controlPoints) = 0;
  virtual GEdge *addNURBS(GModel *gm, GVertex *start, GVertex *end,
			  std::vector<std::vector<double> > controlPoints, 
			  std::vector<double> knots,
			  std::vector<double> weights, 
			  std::vector<int> multiplicity) = 0;
  // faces primitives
  // this one tries to build a model face with one single list
  // of faces. If boundaries are co-planar, then it's a plane, 
  // otherwise, we tru ruled, sweep or other kind of surfaces
  virtual std::vector<GFace *> addRuledFaces(GModel *gm, 
                                             std::vector<std::vector<GEdge *> > edges) = 0; 
  virtual GFace *addFace(GModel *gm, std::vector<GEdge *> edges, 
                         std::vector< std::vector<double > > points) = 0;
  virtual GFace *addPlanarFace(GModel *gm, std::vector<std::vector<GEdge *> > edges) = 0;
  // sweep stuff
  virtual GEntity *revolve(GModel *gm, GEntity*, std::vector<double> p1, 
                           std::vector<double> p2, double angle) = 0;
  virtual GEntity *extrude(GModel *gm, GEntity*, std::vector<double> p1, 
                           std::vector<double> p2) = 0;
  virtual GEntity *addPipe(GModel *gm, GEntity *base, std::vector<GEdge *> wire) = 0;

  // solid primitives
  virtual GEntity *addSphere(GModel *gm, double cx, double cy, double cz, 
                             double radius) = 0; 
  virtual GEntity *addCylinder(GModel *gm, std::vector<double> p1, 
                               std::vector<double> p2, double radius) = 0; 
  virtual GEntity *addTorus(GModel *gm, std::vector<double> p1, 
                            std::vector<double> p2, double radius1, 
                            double radius2) = 0; 
  virtual GEntity *addBlock(GModel *gm, std::vector<double> p1,
                            std::vector<double> p2) = 0;
  virtual GEntity *addCone(GModel *gm, std::vector<double> p1,
                           std::vector<double> p2, double radius1,
                           double radius2) = 0; 

  // here, we should give a list of GEdges. Yet, I still can't figure out how
  // to get those automatically ... wait and see
  virtual void fillet(GModel *gm, std::vector<int> edges, double radius) = 0; 

  // rigid body motions
  virtual void translate(GModel *gm, std::vector<double> dx, int addToTheModel) = 0;
  virtual void rotate(GModel *gm, std::vector<double> p1,std::vector<double> p2,
                      double angle, int addToTheModel) = 0;

  // boolean operators acting on 2 GModels
  virtual GModel *computeBooleanUnion(GModel *obj, GModel*tool, int createNewModel) = 0;
  virtual GModel *computeBooleanIntersection(GModel *obj, GModel*tool,
                                             int createNewModel) = 0;
  virtual GModel *computeBooleanDifference(GModel *obj, GModel*tool, 
                                           int createNewModel) = 0;
};

#if defined(HAVE_OCC)

class OCCFactory : public GModelFactory {
 public:
  OCCFactory(){}
  GVertex *addVertex(GModel *gm,double x, double y, double z, double lc);
  virtual GEdge *addLine(GModel *gm,GVertex *v1, GVertex *v2);
  GEdge *addCircleArc(GModel *gm,const arcCreationMethod &method,
                      GVertex *start, GVertex *end, 
                      const SPoint3 &aPoint);
  GEdge *addSpline(GModel *gm,const splineType &type,
                   GVertex *start, GVertex *end, 
                   std::vector<std::vector<double> > controlPoints);
  GEdge *addNURBS(GModel *gm,
		  GVertex *start, GVertex *end,
		  std::vector<std::vector<double> > controlPoints, 
		  std::vector<double> knots,
		  std::vector<double> weights, 
		  std::vector<int> multiplicity);
  GEntity *revolve(GModel *gm, GEntity*,std::vector<double> p1, 
                   std::vector<double> p2, double angle);
  GEntity *extrude(GModel *gm, GEntity*,std::vector<double> p1,
                   std::vector<double> p2);
  GEntity *addPipe(GModel *gm, GEntity *base, std::vector<GEdge *> wire);
  GEntity *addSphere(GModel *gm,double cx, double cy, double cz, double radius); 
  GEntity *addCylinder(GModel *gm,std::vector<double> p1, std::vector<double> p2, 
                       double radius); 
  std::vector<GFace *> addRuledFaces(GModel *gm, std::vector<std::vector<GEdge *> > edges); 
  GFace *addFace(GModel *gm, std::vector<GEdge *> edges,
                 std::vector< std::vector<double > > points);
  GFace *addPlanarFace(GModel *gm, std::vector<std::vector<GEdge *> > edges);
  GEntity *addTorus(GModel *gm,std::vector<double> p1, std::vector<double> p2, 
		     double radius1, double radius2); 
  GEntity *addBlock(GModel *gm,std::vector<double> p1, std::vector<double> p2); 
  GEntity *addCone(GModel *gm,std::vector<double> p1, std::vector<double> p2,
                   double radius1, double radius2); 
  void translate(GModel *gm, std::vector<double> dx, int addToTheModel);
  void rotate(GModel *gm, std::vector<double> p1,std::vector<double> p2,
              double angle, int addToTheModel);
  GModel *computeBooleanUnion(GModel *obj, GModel *tool, int createNewModel);
  GModel *computeBooleanIntersection(GModel *obj, GModel *tool, int createNewModel);
  GModel *computeBooleanDifference(GModel *obj, GModel *tool, int createNewModel);
  void fillet(GModel *gm, std::vector<int> edges, double radius);
};

#endif

#endif
