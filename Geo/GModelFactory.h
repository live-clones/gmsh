// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _GMODEL_FACTORY_H_
#define _GMODEL_FACTORY_H_

#include <vector>
#include "GmshConfig.h"
#include "GmshMessage.h"

class GEntity;
class GVertex;
class GEdge;
class GFace;
class GRegion;
class GModel;
class SPoint3;

// Abstract CAD creation factory.
class GModelFactory {
 public:
  GModelFactory(){}
  virtual ~GModelFactory(){}

  // brep primitives
  enum arcCreationMethod {THREE_POINTS=1, CENTER_START_END=2};
  enum splineType {BEZIER=1, BSPLINE=2};
  virtual GVertex *addVertex(GModel *gm, double x, double y, double z, 
                             double lc) = 0;
  virtual GEdge *addLine(GModel *, GVertex *v1, GVertex *v2) = 0;
  virtual GFace *addPlanarFace(GModel *gm, std::vector<std::vector<GEdge *> > edges) = 0;
  virtual GRegion*addVolume(GModel *gm, std::vector<std::vector<GFace *> > faces) = 0;

  virtual GEdge *addCircleArc(GModel *gm, const arcCreationMethod &method,
                              GVertex *start, GVertex *end, 
                              const SPoint3 &aPoint)
  {
    Msg::Error("addCircleArc not implemented yet");
    return 0;
  }
  virtual GEdge *addSpline(GModel *gm,const splineType &type,
                           GVertex *start, 
                           GVertex *end, 
                           std::vector<std::vector<double> > controlPoints)
  {
    Msg::Error("addSpline not implemented yet");
    return 0;
  }
  virtual GEdge *addNURBS(GModel *gm, GVertex *start, GVertex *end,
			  std::vector<std::vector<double> > controlPoints, 
			  std::vector<double> knots,
			  std::vector<double> weights, 
			  std::vector<int> multiplicity)
  {
    Msg::Error("addNURBS not implemented yet");
    return 0;
  }
  // this one tries to build a model face with one single list of
  // faces. If boundaries are co-planar, then it's a plane, otherwise,
  // we tru ruled, sweep or other kind of surfaces
  virtual std::vector<GFace *> addRuledFaces(GModel *gm, 
					     std::vector<std::vector<GEdge *> > edges)
  {
    Msg::Error("addRuledFaces not implemented yet");
    return std::vector<GFace*>();
  }
  virtual GFace *addFace(GModel *gm, std::vector<GEdge *> edges, 
                         std::vector< std::vector<double > > points)
  {
    Msg::Error("addFace not implemented yet");
    return 0;
  }

  // sweep stuff
  virtual GEntity *revolve(GModel *gm, GEntity*, std::vector<double> p1, 
                           std::vector<double> p2, double angle)
  {
    Msg::Error("revolve not implemented yet");
    return 0;
  }
  virtual GEntity *extrude(GModel *gm, GEntity*, std::vector<double> p1, 
                           std::vector<double> p2)
  {
    Msg::Error("extrude not implemented yet");
    return 0;
  }
  virtual GEntity *addPipe(GModel *gm, GEntity *base, std::vector<GEdge *> wire)
  {
    Msg::Error("addPipe not implemented yet");
    return 0;
  }

  // solid primitives
  virtual GEntity *addSphere(GModel *gm, double cx, double cy, double cz, 
                             double radius)
  {
    Msg::Error("addSphere not implemented yet");
    return 0;
  }
  virtual GEntity *addCylinder(GModel *gm, std::vector<double> p1, 
                               std::vector<double> p2, double radius)
  {
    Msg::Error("addCylinder not implemented yet");
    return 0;
  }
  virtual GEntity *addTorus(GModel *gm, std::vector<double> p1, 
                            std::vector<double> p2, double radius1, 
                            double radius2)
  {
    Msg::Error("addTorus not implemented yet");
    return 0;
  }
  virtual GEntity *addBlock(GModel *gm, std::vector<double> p1,
                            std::vector<double> p2)
  {
    Msg::Error("addBlock not implemented yet");
    return 0;
  }
  virtual GEntity *addCone(GModel *gm, std::vector<double> p1,
                           std::vector<double> p2, double radius1,
                           double radius2)
  {
    Msg::Error("addCone not implemented yet");
    return 0;
  }

  // here, we should give a list of GEdges. Yet, I still can't figure out how
  // to get those automatically ... wait and see
  virtual void fillet(GModel *gm, std::vector<int> edges, double radius)
  {
    Msg::Error("fillet not implemented yet");
  }

  // rigid body motions
  virtual void translate(GModel *gm, std::vector<double> dx, int addToTheModel)
  {
    Msg::Error("translate not implemented yet");
  }
  virtual void rotate(GModel *gm, std::vector<double> p1,std::vector<double> p2,
                      double angle, int addToTheModel)
  {
    Msg::Error("rotate not implemented yet");
  }

  // boolean operators acting on 2 GModels
  virtual GModel *computeBooleanUnion(GModel *obj, GModel*tool, int createNewModel)
  {
    Msg::Error("computeBooleanUnion not implemented yet");
    return 0;
  }
  virtual GModel *computeBooleanIntersection(GModel *obj, GModel*tool,
                                             int createNewModel)
  {
    Msg::Error("computeBooleanIntersection not implemented yet");
    return 0;
  }
  virtual GModel *computeBooleanDifference(GModel *obj, GModel*tool, 
                                           int createNewModel)
  {
    Msg::Error("computeBooleanDifference not implemented yet");
    return 0;
  }
};

class GeoFactory : public GModelFactory {
 public:
  GeoFactory(){}
  GVertex *addVertex(GModel *gm,double x, double y, double z, double lc);
  GEdge *addLine(GModel *gm,GVertex *v1, GVertex *v2);
  GFace *addPlanarFace(GModel *gm, std::vector<std::vector<GEdge *> > edges);
  GRegion *addVolume(GModel *gm, std::vector<std::vector<GFace *> > faces); 
};


#if defined(HAVE_OCC)

class OCCFactory : public GModelFactory {
 public:
  OCCFactory(){}
  GVertex *addVertex(GModel *gm,double x, double y, double z, double lc);
  GEdge *addLine(GModel *gm,GVertex *v1, GVertex *v2);
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
  GRegion *addVolume(GModel *gm, std::vector<std::vector<GFace *> > faces); 
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
