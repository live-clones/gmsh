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
class binding;

class GModelFactory {
 protected :
 public:
  // constructor takes the GModel as input
  GModelFactory (){}
  // creation methods
  enum arcCreationMethod {THREE_POINTS=1, CENTER_START_END=2};
  enum splineType {BEZIER=1, CATMULL_ROM=2};

  virtual GVertex* createVertex (GModel *gm, double x, double y, double z, double lc) = 0;

  virtual GEdge *createLine (GModel *, GVertex *v1, GVertex *v2) = 0;


  virtual GEdge *createCircleArc (GModel *gm, const arcCreationMethod &method,
				  GVertex *start, 
				  GVertex *end, 
				  const SPoint3 &aPoint)= 0;
  inline GEdge *createCircleArcCenter (GModel *gm, double x, double y, double z,
				       GVertex *start, 
				       GVertex *end){
    return createCircleArc (gm, CENTER_START_END,start,end,SPoint3(x,y,z));
  }

  inline GEdge *createCircleArc3Points (GModel *gm, double x, double y, double z,
					GVertex *start, 
					GVertex *end){
    return createCircleArc (gm, THREE_POINTS,start,end,SPoint3(x,y,z));
  }
  virtual GEdge *createSpline (GModel *gm,const splineType &type,
			       GVertex *start, 
			       GVertex *end, 
			       fullMatrix<double> *controlPoints)= 0;
  inline GEdge *createBezier ( GModel *gm, GVertex *start, 
			       GVertex *end, 
			       fullMatrix<double> *controlPoints){
    return createSpline(gm, BEZIER,start, end, controlPoints);
  }

  virtual GEntity* revolve (GModel *gm, GEntity*, 
			    double x1, double y1, double z1, 
			    double x2, double y2, double z2,
			    double angle ) = 0;
  virtual GEntity* extrude (GModel *gm, GEntity*, 
			    double x1, double y1, double z1, 
			    double x2, double y2, double z2) = 0;

  inline GEntity* revolve_ (GModel *gm, GEntity* e, 
			    double angle,
			    fullMatrix<double> *axis){
    revolve (gm, e, (*axis)(0,0),(*axis)(0,1),(*axis)(0,2),
	     (*axis)(1,0),(*axis)(1,1),(*axis)(1,2),angle);
  }
  inline GEntity* extrude_ (GModel *gm, GEntity* e, 
			    fullMatrix<double> *axis){
    extrude (gm, e, (*axis)(0,0),(*axis)(0,1),(*axis)(0,2),
	     (*axis)(1,0),(*axis)(1,1),(*axis)(1,2));
  }
  // primitives
  virtual GEntity * sphere   (GModel *gm, double cx, double cy, double cz, double radius) = 0; 
  virtual GEntity * cylinder (GModel *gm, std::vector<double> p1, std::vector<double> p2, 
			      double radius) = 0; 
  virtual GEntity * torus   (GModel *gm, std::vector<double> p1, std::vector<double> p2, 
			     double radius1, double radius2) = 0; 
  virtual GEntity * block  (GModel *gm, std::vector<double> p1, std::vector<double> p2) = 0;
  virtual GEntity * cone   (GModel *gm, std::vector<double> p1, std::vector<double> p2,
			    double radius1, double radius2) = 0; 

  // boolean operators acting on 2 GEntities
  virtual GModel * booleanUnion (GModel *obj, GModel*tool, int createNewModel) = 0;
  virtual GModel * booleanIntersection (GModel *obj, GModel*tool, int createNewModel) = 0;
  virtual GModel * booleanDifference (GModel *obj, GModel*tool, int createNewModel) = 0;
  

  // bindings
  static void registerBindings(binding *b);
};

#if defined(HAVE_OCC)
class OCCFactory : public GModelFactory {
 public:
  OCCFactory ();
  GVertex *createVertex (GModel *gm,double x, double y, double z, double lc);
  virtual GEdge *createLine (GModel *gm,GVertex *v1, GVertex *v2);
  GEdge *createCircleArc (GModel *gm,const arcCreationMethod &method,				  
			  GVertex *start, 
			  GVertex *end, 
			  const SPoint3 &aPoint);
  GEdge *createSpline (GModel *gm,const splineType &type,
		       GVertex *start, 
		       GVertex *end, 
		       fullMatrix<double> *controlPoints);

  GEntity* revolve (GModel *gm,GEntity*, 
		    double x1, double y1, double z1, 
		    double x2, double y2, double z2,
		    double angle );

  GEntity* extrude (GModel *gm,GEntity*, 
		    double x1, double y1, double z1, 
		    double x2, double y2, double z2);

  GEntity * sphere   (GModel *gm,double cx, double cy, double cz, double radius); 
  GEntity * cylinder (GModel *gm,std::vector<double> p1, std::vector<double> p2, 
		      double radius); 
  GEntity * torus   (GModel *gm,std::vector<double> p1, std::vector<double> p2, 
		     double radius1, double radius2); 
  GEntity * block  (GModel *gm,std::vector<double> p1, std::vector<double> p2); 
  GEntity * cone   (GModel *gm,std::vector<double> p1, std::vector<double> p2, double radius1, double radius2); 
  // booleans
  GModel * booleanUnion (GModel *obj, GModel*tool, int createNewModel);
  GModel * booleanIntersection (GModel *obj, GModel*tool, int createNewModel);
  GModel * booleanDifference (GModel *obj, GModel*tool, int createNewModel);
};
#endif

#endif
