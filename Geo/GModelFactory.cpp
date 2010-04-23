#include "GModelFactory.h"

#if defined(HAVE_OCC)
#include "OCCIncludes.h"
#include "GModelIO_OCC.h"
#include "OCCVertex.h"
#include "OCCEdge.h"
#include "OCCRegion.h"
#include "BRepBuilderAPI_MakeVertex.hxx"
#include "BRepBuilderAPI_MakeEdge.hxx"
#include "BRepPrimAPI_MakeRevol.hxx"
#include "BRepPrimAPI_MakePrism.hxx"
#include <GC_MakeArcOfCircle.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <gce_MakeCirc.hxx>
#include <gce_MakePln.hxx>
#include <ElCLib.hxx>
#include <Geom_Circle.hxx>
#include <Geom_TrimmedCurve.hxx>
#include <Geom_BezierCurve.hxx>

OCCFactory::OCCFactory() : GModelFactory()
{
}


GVertex * OCCFactory::createVertex (GModel *_gm, double x, double y, double z, double lc){
  if (!_gm->_occ_internals)
    _gm->_occ_internals = new OCC_Internals;

  gp_Pnt aPnt;
  aPnt = gp_Pnt(x, y, z);
  BRepBuilderAPI_MakeVertex mkVertex (aPnt);
  TopoDS_Vertex occv =  mkVertex.Vertex();
  
  return _gm->_occ_internals->addVertexToModel(_gm,occv);
}


GEdge * OCCFactory::createLine (GModel *_gm, GVertex *start, GVertex *end){
  if (!_gm->_occ_internals)
    _gm->_occ_internals = new OCC_Internals;

  OCCVertex *occv1 = dynamic_cast<OCCVertex*>(start);
  OCCVertex *occv2 = dynamic_cast<OCCVertex*>(end);
  TopoDS_Edge occEdge;
  if (occv1 && occv2){
     occEdge = BRepBuilderAPI_MakeEdge(occv1->getShape(), 
				       occv2->getShape()).Edge();
  }
  else{
    gp_Pnt p1(start->x(),start->y(),start->z());
    gp_Pnt p2(end->x(),end->y(),end->z());
    TopoDS_Edge occEdge = BRepBuilderAPI_MakeEdge(p1, p2).Edge();
  }  
  return _gm->_occ_internals->addEdgeToModel(_gm,occEdge,start,end);
}


GEdge *OCCFactory::createCircleArc (GModel *_gm, const arcCreationMethod &method,
			       GVertex *start, 
			       GVertex *end, 
			       const SPoint3 &aPoint) {
  if (!_gm->_occ_internals)
    _gm->_occ_internals = new OCC_Internals;

  gp_Pnt aP1 (start->x(),start->y(),start->z());
  gp_Pnt aP2 (aPoint.x(),aPoint.y(),aPoint.z());
  gp_Pnt aP3 (end->x(),end->y(),end->z());

  if (method == GModelFactory::THREE_POINTS){
    GC_MakeArcOfCircle arc(aP1, aP2, aP3);
    TopoDS_Edge occEdge = BRepBuilderAPI_MakeEdge(arc).Edge();
    return _gm->_occ_internals->addEdgeToModel(_gm,occEdge,start,end);
  }
  else if (method == GModelFactory::CENTER_START_END){
    Standard_Real Radius = aP1.Distance(aP2);
    gce_MakeCirc MC(aP1,gce_MakePln(aP1, aP2, aP3).Value(),Radius);
    const gp_Circ& Circ = MC.Value();
    Standard_Real Alpha1 = ElCLib::Parameter(Circ,aP1);
    Standard_Real Alpha2 = ElCLib::Parameter(Circ,aP3);
    Handle(Geom_Circle) C = new Geom_Circle(Circ);
    Handle(Geom_TrimmedCurve) arc = new Geom_TrimmedCurve(C,Alpha1,Alpha2,false);
    TopoDS_Edge occEdge = BRepBuilderAPI_MakeEdge(arc).Edge();
    return _gm->_occ_internals->addEdgeToModel(_gm,occEdge,start,end);
  }
  return 0;
}

GEdge *OCCFactory::createSpline (GModel *_gm, const splineType &type,
				 GVertex *start, 
				 GVertex *end, 
				 fullMatrix<double> *points){
  if (!_gm->_occ_internals)
    _gm->_occ_internals = new OCC_Internals;

  OCCEdge *occEd = 0;
  int nbControlPoints = points->size1();
  TColgp_Array1OfPnt ctrlPoints (1, nbControlPoints+2);
  int index = 1;
  ctrlPoints.SetValue(index++,gp_Pnt(start->x(),start->y(),start->z()));  
  for (int i = 0; i < nbControlPoints; i++) {
    gp_Pnt aP((*points)(i,0),(*points)(i,1),(*points)(i,2));
    ctrlPoints.SetValue(index++, aP);
  }
  ctrlPoints.SetValue(index++,gp_Pnt(end->x(),end->y(),end->z()));  
  if (type == BEZIER) {
    Handle(Geom_BezierCurve) Bez = new Geom_BezierCurve(ctrlPoints);
    TopoDS_Edge bez = BRepBuilderAPI_MakeEdge(Bez).Edge();
    return _gm->_occ_internals->addEdgeToModel(_gm,bez,start,end);
  } 
  else {
    throw;
  }
  return 0;
}

GEntity *OCCFactory::revolve (GModel *_gm, GEntity* base, 
			      double x1, double y1, double z1, 
			      double x2, double y2, double z2,
			      double angle ){
  if (!_gm->_occ_internals)
    _gm->_occ_internals = new OCC_Internals;

  gp_Dir direction (x2-x1,y2-y1,z2-z1);
  gp_Ax1 axisOfRevolution (gp_Pnt (x1,y1,z1),direction);
  BRepPrimAPI_MakeRevol MR (*(TopoDS_Shape*)base->getNativePtr(), 
			    axisOfRevolution, angle, Standard_False);
  GEntity *ret;
  if (base->Cast2Vertex()){
    TopoDS_Edge result =  TopoDS::Edge(MR.Shape());
    ret  = _gm->_occ_internals->addEdgeToModel(_gm,result);
  }
  if (base->Cast2Edge()){
    TopoDS_Face result =  TopoDS::Face(MR.Shape());
    ret =  _gm->_occ_internals->addFaceToModel(_gm,result);    
  }
  if (base->Cast2Face()){
    TopoDS_Solid result =  TopoDS::Solid(MR.Shape());
    ret =  _gm->_occ_internals->addRegionToModel(_gm,result);    
  }
  _gm->glue(Precision::Confusion());
  return ret;
}

GEntity *OCCFactory::extrude (GModel *_gm, GEntity* base, 
			      double x1, double y1, double z1, 
			      double x2, double y2, double z2){
  if (!_gm->_occ_internals)
    _gm->_occ_internals = new OCC_Internals;

  gp_Vec direction (gp_Pnt (x1,y1,z1),gp_Pnt (x2,y2,z2));
  gp_Ax1 axisOfRevolution (gp_Pnt (x1,y1,z1),direction);

  BRepPrimAPI_MakePrism MP(*(TopoDS_Shape*)base->getNativePtr(), direction, Standard_False);

  GEntity *ret;
  
  if (base->Cast2Vertex()){
    TopoDS_Edge result =  TopoDS::Edge(MP.Shape());
    ret =  _gm->_occ_internals->addEdgeToModel(_gm,result);
  }
  if (base->Cast2Edge()){
    TopoDS_Face result =  TopoDS::Face(MP.Shape());
    ret = _gm->_occ_internals->addFaceToModel(_gm,result);    
  }
  if (base->Cast2Face()){
    TopoDS_Solid result =  TopoDS::Solid(MP.Shape());
    ret = _gm->_occ_internals->addRegionToModel(_gm,result);    
  }
  _gm->glue(Precision::Confusion());
  return ret;
}


GEntity *OCCFactory::sphere (GModel *_gm,  double xc, double yc, double zc, double radius){
  if (!_gm->_occ_internals)
    _gm->_occ_internals = new OCC_Internals;

  gp_Pnt aP(xc,yc,zc);  
  _gm->_occ_internals->buildShapeFromLists(BRepPrimAPI_MakeSphere(aP, radius).Shape());
  _gm->destroy();
  _gm->_occ_internals->buildLists();
  _gm->_occ_internals->buildGModel(_gm);  
}

GEntity *OCCFactory::cylinder (GModel *_gm,  std::vector<double> p1, std::vector<double> p2, double radius){
  if (!_gm->_occ_internals)
    _gm->_occ_internals = new OCC_Internals;

  const double x1 =p1[0]; 
  const double y1 =p1[1]; 
  const double z1 =p1[2]; 
  const double x2 =p2[0]; 
  const double y2 =p2[1]; 
  const double z2 =p2[2]; 

  gp_Pnt aP(x1,y1,z1);
  const double H = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)+(z2-z1)*(z2-z1)); 
  gp_Vec aV((x2-x1)/H,(y2-y1)/H,(z2-z1)/H);
  gp_Ax2 anAxes(aP, aV);
  BRepPrimAPI_MakeCylinder MC (anAxes, radius, H);
  MC.Build();
  if (!MC.IsDone()) {
    Msg::Error("Cylinder can't be computed from the given parameters");
    return 0;
  }
  _gm->_occ_internals->buildShapeFromLists(MC.Shape());
  _gm->destroy();
  _gm->_occ_internals->buildLists();
  _gm->_occ_internals->buildGModel(_gm);  
  return 0;
}

GEntity *OCCFactory::torus (GModel *_gm,  std::vector<double> p1, std::vector<double> p2, double radius1, double radius2){
  if (!_gm->_occ_internals)
    _gm->_occ_internals = new OCC_Internals;

  const double x1 =p1[0]; 
  const double y1 =p1[1]; 
  const double z1 =p1[2]; 
  const double x2 =p2[0]; 
  const double y2 =p2[1]; 
  const double z2 =p2[2]; 
  gp_Pnt aP(x1,y1,z1);
  const double H = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)+(z2-z1)*(z2-z1)); 
  gp_Vec aV((x2-x1)/H,(y2-y1)/H,(z2-z1)/H);
  gp_Ax2 anAxes(aP, aV);
  BRepPrimAPI_MakeTorus MC (anAxes, radius1, radius2);
  MC.Build();
  if (!MC.IsDone()) {
    Msg::Error("Cylinder can't be computed from the given parameters");
    return 0;
  }
  _gm->_occ_internals->buildShapeFromLists(MC.Shape());
  _gm->destroy();
  _gm->_occ_internals->buildLists();
  _gm->_occ_internals->buildGModel(_gm);  
  return 0;
}

GEntity *OCCFactory::cone (GModel *_gm,  std::vector<double> p1, std::vector<double> p2, double radius1, double radius2){
  if (!_gm->_occ_internals)
    _gm->_occ_internals = new OCC_Internals;

  const double x1 =p1[0]; 
  const double y1 =p1[1]; 
  const double z1 =p1[2]; 
  const double x2 =p2[0]; 
  const double y2 =p2[1]; 
  const double z2 =p2[2]; 

  gp_Pnt aP(x1,y1,z1);
  const double H = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)+(z2-z1)*(z2-z1)); 
  gp_Vec aV((x2-x1)/H,(y2-y1)/H,(z2-z1)/H);
  gp_Ax2 anAxes(aP, aV);
  BRepPrimAPI_MakeCone MC (anAxes, radius1, radius2, H);
  MC.Build();
  if (!MC.IsDone()) {
    Msg::Error("Cylinder can't be computed from the given parameters");
    return 0;
  }
  _gm->_occ_internals->buildShapeFromLists(MC.Shape());
  _gm->destroy();
  _gm->_occ_internals->buildLists();
  _gm->_occ_internals->buildGModel(_gm);  
  return 0;
}

GEntity *OCCFactory::block  (GModel *_gm, std::vector<double> p1, std::vector<double> p2){
  if (!_gm->_occ_internals)
    _gm->_occ_internals = new OCC_Internals;

  gp_Pnt P1(p1[0],p1[1],p1[2]);
  gp_Pnt P2(p2[0],p2[1],p2[2]);
  BRepPrimAPI_MakeBox MB(P1, P2);
  MB.Build();
  if (!MB.IsDone()) {
    Msg::Error("Box can not be computed from the given point");
    return 0;
  }
  _gm->_occ_internals->buildShapeFromLists(MB.Shape());
  _gm->destroy();
  _gm->_occ_internals->buildLists();
  _gm->_occ_internals->buildGModel(_gm);  
}

GModel *OCCFactory::booleanUnion (GModel* obj, GModel* tool, int createNewModel){

  OCC_Internals *occ_obj  = obj->getOCCInternals();
  OCC_Internals *occ_tool = tool->getOCCInternals();

  if (!occ_obj || !occ_tool)return NULL;

  if (createNewModel){
    GModel *temp = new GModel;
    temp->_occ_internals = new OCC_Internals;
    temp->_occ_internals->addShapeToLists(occ_obj->getShape());
    obj = temp;
  }
  obj->_occ_internals->applyBooleanOperator(occ_tool->getShape(),OCC_Internals::Fuse);
  obj->destroy();
  obj->_occ_internals->buildLists();
  obj->_occ_internals->buildGModel(obj);
  
  return obj;
}

GModel *OCCFactory::booleanDifference (GModel* obj, GModel* tool, int createNewModel){

  OCC_Internals *occ_obj  = obj->getOCCInternals();
  OCC_Internals *occ_tool = tool->getOCCInternals();

  if (!occ_obj || !occ_tool)return NULL;

  if (createNewModel){
    GModel *temp = new GModel;
    temp->_occ_internals = new OCC_Internals;
    temp->_occ_internals->addShapeToLists(occ_obj->getShape());
    obj = temp;
  }
  obj->getOCCInternals()->applyBooleanOperator(occ_tool->getShape(),OCC_Internals::Cut);
  obj->destroy();
  obj->_occ_internals->buildLists();
  obj->_occ_internals->buildGModel(obj);
  return obj;
}

GModel *OCCFactory::booleanIntersection (GModel* obj, GModel* tool, int createNewModel){

  OCC_Internals *occ_obj  = obj->getOCCInternals();
  OCC_Internals *occ_tool = tool->getOCCInternals();


  if (!occ_obj || !occ_tool)return NULL;

  if (createNewModel){
    GModel *temp = new GModel;
    temp->_occ_internals = new OCC_Internals;
    temp->_occ_internals->addShapeToLists(occ_obj->getShape());
    obj = temp;
  }
  obj->getOCCInternals()->applyBooleanOperator(occ_tool->getShape(),OCC_Internals::Intersection);
  obj->destroy();
  obj->_occ_internals->buildLists();
  obj->_occ_internals->buildGModel(obj);
  return obj;
}

#endif

#include "Bindings.h"
void GModelFactory::registerBindings (binding *b)
{
  classBinding *cb = b->addClass<GModelFactory>("GModelFactory");
  cb->setDescription("an interface to Gentity Construction");
  methodBinding *mb;
  mb = cb->addMethod("createVertex", &GModelFactory::createVertex);
  mb->setDescription("creates a GVertex");
  mb->setArgNames("model", "x", "y","z","lc",NULL);
  mb = cb->addMethod("createLine", &GModelFactory::createLine);
  mb->setDescription("creates a Line going from v1 to v2");
  mb->setArgNames("model","v1", "v2",NULL);
  mb = cb->addMethod("createBezierLine", &GModelFactory::createBezier);
  mb->setDescription("creates a Spline going from v1 to v2 and with some control points listed in a fullMatrix(N,3)");
  mb->setArgNames("model","v1", "v2", "controlPoints", NULL);
  mb = cb->addMethod("createCircleArcCenter", &GModelFactory::createCircleArcCenter);
  mb->setDescription("creates a circle arc going from v1 to v2 with its center Xc(x,y,z)");
  mb->setArgNames("model","x","y","z","v1", "v2", NULL);
  mb = cb->addMethod("createCircleArc3Points", &GModelFactory::createCircleArc3Points);
  mb->setDescription("creates a circle arc going from v1 to v2 with an intermediary point Xi(x,y,z)");
  mb->setArgNames("model","x","y","z","v1", "v2", NULL);
  mb = cb->addMethod("revolve", &GModelFactory::revolve_);
  mb->setDescription("revolves an entity of an angle. Axis is defined by 2 points in a full Matrix(2,3)");
  mb->setArgNames("model","entity", "angle", "axis",NULL);
  mb = cb->addMethod("extrude", &GModelFactory::extrude_);
  mb->setDescription("extrudes an entity. Axis is defined by 2 points in a full Matrix(2,3)");
  mb->setArgNames("model","entity", "axis",NULL);

  mb = cb->addMethod("sphere", &GModelFactory::sphere);
  mb->setDescription("builds a sphere");
  mb->setArgNames("model","xc","yc","zc","radius",NULL);

  mb = cb->addMethod("block", &GModelFactory::block);
  mb->setDescription("builds a block");
  mb->setArgNames("model","{x1,y1,z1}","{x2,y2,z2}",NULL);

  mb = cb->addMethod("cone", &GModelFactory::cone);
  mb->setDescription("builds a cone");
  mb->setArgNames("model","{x1,y1,z1}","{x2,y2,z2}","R1","R2",NULL);

  mb = cb->addMethod("cylinder", &GModelFactory::cylinder);
  mb->setDescription("builds a cylinder");
  mb->setArgNames("model","{x1,y1,z1}","{x2,y2,z2}", "R",NULL);

  mb = cb->addMethod("torus", &GModelFactory::torus);
  mb->setDescription("builds a torus");
  mb->setArgNames("model","{x1,y1,z1}","{x2,y2,z2}","R1","R2",NULL);

  mb = cb->addMethod("union", &GModelFactory::booleanUnion);
  mb->setDescription("returns a GModel that is the boolean union of 2 GModels. Third parameter tells if a new model has to be created");
  mb->setArgNames("g1","g2","createNewGModel",NULL);

  mb = cb->addMethod("intersection", &GModelFactory::booleanIntersection);
  mb->setDescription("returns a GModel that is the boolean intersection of 2 GModels. Third parameter tells if a new model has to be created");
  mb->setArgNames("g1","g2","createNewGModel",NULL);

  mb = cb->addMethod("difference", &GModelFactory::booleanDifference);
  mb->setDescription("returns a GModel that is the boolean difference of 2 GModels. Third parameter tells if a new model has to be created");
  mb->setArgNames("g1","g2","createNewGModel",NULL);
#if defined(HAVE_OCC)
  cb = b->addClass<OCCFactory>("OCCFactory");
  cb->setDescription("a GEntity Factory for OpenCascade");
  mb = cb->setConstructor<OCCFactory>();
  mb->setDescription("a GEntity Factory for OpenCascade");
  cb->setParentClass<GModelFactory>();
#endif
}

