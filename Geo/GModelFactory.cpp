// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

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
#include <Geom_BSplineCurve.hxx>
#include <BRepBuilderAPI_Transform.hxx>
#include <TColgp_HArray1OfPnt.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <TColStd_HArray1OfInteger.hxx>

GVertex *OCCFactory::addVertex(GModel *gm, double x, double y, double z, double lc)
{
  if (!gm->_occ_internals)
    gm->_occ_internals = new OCC_Internals;

  gp_Pnt aPnt;
  aPnt = gp_Pnt(x, y, z);
  BRepBuilderAPI_MakeVertex mkVertex(aPnt);
  TopoDS_Vertex occv = mkVertex.Vertex();
  
  return gm->_occ_internals->addVertexToModel(gm, occv);
}

GEdge *OCCFactory::addLine(GModel *gm, GVertex *start, GVertex *end)
{
  if (!gm->_occ_internals)
    gm->_occ_internals = new OCC_Internals;

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
  return gm->_occ_internals->addEdgeToModel(gm,occEdge);
}

GEdge *OCCFactory::addCircleArc(GModel *gm, const arcCreationMethod &method,
                                GVertex *start, GVertex *end, 
                                const SPoint3 &aPoint)
{
  if (!gm->_occ_internals)
    gm->_occ_internals = new OCC_Internals;
  
  gp_Pnt aP1(start->x(), start->y(), start->z());
  gp_Pnt aP2(aPoint.x(), aPoint.y(), aPoint.z());
  gp_Pnt aP3(end->x(), end->y(), end->z());
  TopoDS_Edge occEdge;

  OCCVertex *occv1 = dynamic_cast<OCCVertex*>(start);
  OCCVertex *occv2 = dynamic_cast<OCCVertex*>(end);

  if (method == GModelFactory::THREE_POINTS){
    GC_MakeArcOfCircle arc(aP1, aP2, aP3);
    if (occv1 && occv2)
      occEdge = BRepBuilderAPI_MakeEdge(arc,occv1->getShape(), 
                                        occv2->getShape()).Edge();    
    else 
      occEdge = BRepBuilderAPI_MakeEdge(arc).Edge();
  }
  else if (method == GModelFactory::CENTER_START_END){
    Standard_Real Radius = aP1.Distance(aP2);
    gce_MakeCirc MC(aP1,gce_MakePln(aP1, aP2, aP3).Value(), Radius);
    const gp_Circ& Circ = MC.Value();
    Standard_Real Alpha1 = ElCLib::Parameter(Circ, aP1);
    Standard_Real Alpha2 = ElCLib::Parameter(Circ, aP3);
    Handle(Geom_Circle) C = new Geom_Circle(Circ);
    Handle(Geom_TrimmedCurve) arc = new Geom_TrimmedCurve(C, Alpha1, Alpha2, false);
    if (occv1 && occv2)
      occEdge = BRepBuilderAPI_MakeEdge(arc, occv1->getShape(),
                                        occv2->getShape()).Edge();    
    else 
      occEdge = BRepBuilderAPI_MakeEdge(arc).Edge();
  }
  return gm->_occ_internals->addEdgeToModel(gm,occEdge);
}

GEdge *OCCFactory::addSpline(GModel *gm, const splineType &type,
                             GVertex *start, GVertex *end, 
			     std::vector<std::vector<double> > points)
{
  if (!gm->_occ_internals)
    gm->_occ_internals = new OCC_Internals;

  TopoDS_Edge occEdge;

  OCCVertex *occv1 = dynamic_cast<OCCVertex*>(start);
  OCCVertex *occv2 = dynamic_cast<OCCVertex*>(end);

  OCCEdge *occEd = 0;
  int nbControlPoints = points.size();
  TColgp_Array1OfPnt ctrlPoints(1, nbControlPoints + 2);
  int index = 1;
  ctrlPoints.SetValue(index++, gp_Pnt(start->x(), start->y(), start->z()));  
  for (int i = 0; i < nbControlPoints; i++) {
    gp_Pnt aP(points[i][0],points[i][1],points[i][2]);
    ctrlPoints.SetValue(index++, aP);
  }
  ctrlPoints.SetValue(index++, gp_Pnt(end->x(), end->y(), end->z()));  
  if (type == BEZIER) {
    Handle(Geom_BezierCurve) Bez = new Geom_BezierCurve(ctrlPoints);
    if (occv1 && occv2)
      occEdge = BRepBuilderAPI_MakeEdge(Bez,occv1->getShape(),occv2->getShape()).Edge();    
    else
      occEdge = BRepBuilderAPI_MakeEdge(Bez).Edge();
  } 
  return gm->_occ_internals->addEdgeToModel(gm,occEdge);
}


GEdge *OCCFactory::addNURBS(GModel *gm, GVertex *start, GVertex *end,
			    std::vector<std::vector<double> > points, 
			    std::vector<double> knots,
			    std::vector<double> weights, 
			    std::vector<int> mult)
{
  try{ 
  if (!gm->_occ_internals)
    gm->_occ_internals = new OCC_Internals;
  
  OCCVertex *occv1 = dynamic_cast<OCCVertex*>(start);
  OCCVertex *occv2 = dynamic_cast<OCCVertex*>(end);
  
  int nbControlPoints = points.size() + 2;
  TColgp_Array1OfPnt  ctrlPoints(1, nbControlPoints);
  
  TColStd_Array1OfReal _knots(1, knots.size());
  TColStd_Array1OfReal _weights(1, weights.size());
  TColStd_Array1OfInteger  _mult(1, mult.size());
  
  for (int i = 0; i < knots.size(); i++) {
    _knots.SetValue(i+1, knots[i]);
  }
  for (int i = 0; i < weights.size(); i++) {
    _weights.SetValue(i+1, weights[i]);
  }
  int totKnots = 0;
  for (int i = 0; i < mult.size(); i++) {
    _mult.SetValue(i+1, mult[i]);   
    totKnots += mult[i];
  }

  const int degree = totKnots - nbControlPoints - 1;
  printf("creation of a nurbs of degree %d with %d control points\n",
         degree,nbControlPoints);
  
  int index = 1;
  ctrlPoints.SetValue(index++, gp_Pnt(start->x(), start->y(), start->z()));  
  for (int i = 0; i < points.size(); i++) {
    gp_Pnt aP(points[i][0],points[i][1],points[i][2]);
    ctrlPoints.SetValue(index++, aP);
  }
  ctrlPoints.SetValue(index++, gp_Pnt(end->x(), end->y(), end->z()));  
  Handle(Geom_BSplineCurve) NURBS = new Geom_BSplineCurve
    (ctrlPoints, _weights, _knots, _mult, degree, false);
  TopoDS_Edge occEdge;
  if (occv1 && occv2)
    occEdge = BRepBuilderAPI_MakeEdge(NURBS,occv1->getShape(),occv2->getShape()).Edge();    
  else
    occEdge = BRepBuilderAPI_MakeEdge(NURBS).Edge();
  return gm->_occ_internals->addEdgeToModel(gm, occEdge);
  }
  catch(Standard_Failure &err){
    Msg::Error("%s", err.GetMessageString());
  }
  return 0;
}

GEntity *OCCFactory::revolve(GModel *gm, GEntity* base,
                             std::vector<double> p1, 
                             std::vector<double> p2, double angle)
{
  if (!gm->_occ_internals)
    gm->_occ_internals = new OCC_Internals;

  const double x1 = p1[0];
  const double y1 = p1[1];
  const double z1 = p1[2];
  const double x2 = p2[0];
  const double y2 = p2[1];
  const double z2 = p2[2];

  gp_Dir direction(x2 - x1, y2 - y1, z2 - z1);
  gp_Ax1 axisOfRevolution(gp_Pnt(x1, y1, z1), direction);
  BRepPrimAPI_MakeRevol MR(*(TopoDS_Shape*)base->getNativePtr(), 
                           axisOfRevolution, angle, Standard_False);
  GEntity *ret;
  if (base->cast2Vertex()){
    TopoDS_Edge result = TopoDS::Edge(MR.Shape());
    ret = gm->_occ_internals->addEdgeToModel(gm, result);
  }
  if (base->cast2Edge()){
    TopoDS_Face result = TopoDS::Face(MR.Shape());
    ret = gm->_occ_internals->addFaceToModel(gm, result);
  }
  if (base->cast2Face()){
    TopoDS_Solid result = TopoDS::Solid(MR.Shape());
    ret = gm->_occ_internals->addRegionToModel(gm, result);
  }
  return ret;
}

GEntity *OCCFactory::extrude(GModel *gm, GEntity* base,
                             std::vector<double> p1, std::vector<double> p2)
{
  if (!gm->_occ_internals)
    gm->_occ_internals = new OCC_Internals;

  const double x1 = p1[0];
  const double y1 = p1[1];
  const double z1 = p1[2];
  const double x2 = p2[0];
  const double y2 = p2[1];
  const double z2 = p2[2];

  gp_Vec direction(gp_Pnt(x1, y1, z1), gp_Pnt(x2, y2, z2));
  gp_Ax1 axisOfRevolution(gp_Pnt(x1, y1, z1), direction);

  BRepPrimAPI_MakePrism MP(*(TopoDS_Shape*)base->getNativePtr(), direction, 
                           Standard_False);

  GEntity *ret;
  
  if (base->cast2Vertex()){
    TopoDS_Edge result = TopoDS::Edge(MP.Shape());
    ret = gm->_occ_internals->addEdgeToModel(gm, result);
  }
  if (base->cast2Edge()){
    TopoDS_Face result = TopoDS::Face(MP.Shape());
    ret = gm->_occ_internals->addFaceToModel(gm, result);    
  }
  if (base->cast2Face()){
    TopoDS_Solid result = TopoDS::Solid(MP.Shape());
    ret = gm->_occ_internals->addRegionToModel(gm, result);    
  }
  return ret;
}

GEntity *OCCFactory::addSphere(GModel *gm, double xc, double yc, double zc, double radius)
{
  if (!gm->_occ_internals)
    gm->_occ_internals = new OCC_Internals;

  gp_Pnt aP(xc, yc, zc);  
  TopoDS_Shape shape = BRepPrimAPI_MakeSphere(aP, radius).Shape();
  gm->_occ_internals->buildShapeFromLists(shape);
  gm->destroy();
  gm->_occ_internals->buildLists();
  gm->_occ_internals->buildGModel(gm);  
  return getOCCRegionByNativePtr(gm,TopoDS::Solid(shape));
}

GEntity *OCCFactory::addCylinder(GModel *gm, std::vector<double> p1,
                                 std::vector<double> p2, double radius)
{
  if (!gm->_occ_internals)
    gm->_occ_internals = new OCC_Internals;

  const double x1 = p1[0];
  const double y1 = p1[1];
  const double z1 = p1[2];
  const double x2 = p2[0];
  const double y2 = p2[1];
  const double z2 = p2[2];

  gp_Pnt aP(x1, y1, z1);
  const double H = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) + 
                        (z2 - z1) * (z2 - z1));
  gp_Vec aV((x2 - x1) / H, (y2 - y1) / H, (z2 - z1) / H);
  gp_Ax2 anAxes(aP, aV);
  BRepPrimAPI_MakeCylinder MC(anAxes, radius, H);
  MC.Build();
  if (!MC.IsDone()) {
    Msg::Error("Cylinder can't be computed from the given parameters");
    return 0;
  }
  TopoDS_Shape shape = MC.Shape();
  gm->_occ_internals->buildShapeFromLists(shape);
  gm->destroy();
  gm->_occ_internals->buildLists();
  gm->_occ_internals->buildGModel(gm);
  return getOCCRegionByNativePtr(gm,TopoDS::Solid(shape));
}

GEntity *OCCFactory::addTorus(GModel *gm, std::vector<double> p1, 
                              std::vector<double> p2, double radius1, 
                              double radius2)
{
  if (!gm->_occ_internals)
    gm->_occ_internals = new OCC_Internals;

  const double x1 = p1[0];
  const double y1 = p1[1];
  const double z1 = p1[2];
  const double x2 = p2[0];
  const double y2 = p2[1];
  const double z2 = p2[2];
  gp_Pnt aP(x1, y1, z1);
  const double H = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) +
                        (z2 - z1) * (z2 - z1)); 
  gp_Vec aV((x2 - x1) / H, (y2 - y1) / H, (z2 - z1) / H);
  gp_Ax2 anAxes(aP, aV);
  BRepPrimAPI_MakeTorus MC(anAxes, radius1, radius2);
  MC.Build();
  if (!MC.IsDone()) {
    Msg::Error("Cylinder can't be computed from the given parameters");
    return 0;
  }
  TopoDS_Shape shape = MC.Shape();
  gm->_occ_internals->buildShapeFromLists(shape);
  gm->destroy();
  gm->_occ_internals->buildLists();
  gm->_occ_internals->buildGModel(gm);
  return getOCCRegionByNativePtr(gm,TopoDS::Solid(shape));
}

GEntity *OCCFactory::addCone(GModel *gm,  std::vector<double> p1, 
                             std::vector<double> p2, double radius1, 
                             double radius2)
{
  if (!gm->_occ_internals)
    gm->_occ_internals = new OCC_Internals;

  const double x1 = p1[0];
  const double y1 = p1[1];
  const double z1 = p1[2];
  const double x2 = p2[0];
  const double y2 = p2[1];
  const double z2 = p2[2];

  gp_Pnt aP(x1, y1, z1);
  const double H = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) +
                        (z2 - z1) * (z2 - z1)); 
  gp_Vec aV((x2 - x1) / H, (y2 - y1) / H, (z2 - z1) / H);
  gp_Ax2 anAxes(aP, aV);
  BRepPrimAPI_MakeCone MC(anAxes, radius1, radius2, H);
  MC.Build();
  if (!MC.IsDone()) {
    Msg::Error("Cylinder can't be computed from the given parameters");
    return 0;
  }
  TopoDS_Shape shape = MC.Shape();
  gm->_occ_internals->buildShapeFromLists(shape);
  gm->destroy();
  gm->_occ_internals->buildLists();
  gm->_occ_internals->buildGModel(gm);  
  return getOCCRegionByNativePtr(gm,TopoDS::Solid(shape));
}

GEntity *OCCFactory::addBlock(GModel *gm, std::vector<double> p1, 
                              std::vector<double> p2)
{
  if (!gm->_occ_internals)
    gm->_occ_internals = new OCC_Internals;

  gp_Pnt P1(p1[0], p1[1], p1[2]);
  gp_Pnt P2(p2[0], p2[1], p2[2]);
  BRepPrimAPI_MakeBox MB(P1, P2);
  MB.Build();
  if (!MB.IsDone()) {
    Msg::Error("Box can not be computed from the given point");
    return 0;
  }
  TopoDS_Shape shape = MB.Shape();
  gm->_occ_internals->buildShapeFromLists(shape);
  gm->destroy();
  gm->_occ_internals->buildLists();
  gm->_occ_internals->buildGModel(gm);
  return getOCCRegionByNativePtr(gm,TopoDS::Solid(shape));
}

GModel *OCCFactory::computeBooleanUnion(GModel* obj, GModel* tool,
                                        int createNewModel)
{
  try{ 
    OCC_Internals *occ_obj  = obj->getOCCInternals();
    OCC_Internals *occ_tool = tool->getOCCInternals();
    
    if (!occ_obj || !occ_tool)return NULL;
    
    if (createNewModel){
      GModel *temp = new GModel;
      temp->_occ_internals = new OCC_Internals;
      temp->_occ_internals->addShapeToLists(occ_obj->getShape());
      obj = temp;
    }
    obj->_occ_internals->applyBooleanOperator(occ_tool->getShape(),
                                              OCC_Internals::Fuse);
    obj->destroy();
    obj->_occ_internals->buildLists();
    obj->_occ_internals->buildGModel(obj);
  }
  catch(Standard_Failure &err){
    Msg::Error("%s", err.GetMessageString());
  }
    
  return obj;
}

GModel *OCCFactory::computeBooleanDifference(GModel* obj, GModel* tool, 
                                             int createNewModel)
{
  try{ 
    OCC_Internals *occ_obj  = obj->getOCCInternals();
    OCC_Internals *occ_tool = tool->getOCCInternals();
    
    if (!occ_obj || !occ_tool)return NULL;
    
    if (createNewModel){
      GModel *temp = new GModel;
      temp->_occ_internals = new OCC_Internals;
      temp->_occ_internals->addShapeToLists(occ_obj->getShape());
      obj = temp;
    }
    obj->getOCCInternals()->applyBooleanOperator(occ_tool->getShape(),
                                                 OCC_Internals::Cut);
    obj->destroy();
    obj->_occ_internals->buildLists();
    obj->_occ_internals->buildGModel(obj);
  }
  catch(Standard_Failure &err){
    Msg::Error("%s", err.GetMessageString());
  }
  return obj;
}

GModel *OCCFactory::computeBooleanIntersection(GModel* obj, GModel* tool,
                                               int createNewModel)
{
  try{
    OCC_Internals *occ_obj  = obj->getOCCInternals();
    OCC_Internals *occ_tool = tool->getOCCInternals();
    
    if (!occ_obj || !occ_tool)return NULL;
    
    if (createNewModel){
      GModel *temp = new GModel;
      temp->_occ_internals = new OCC_Internals;
      temp->_occ_internals->addShapeToLists(occ_obj->getShape());
      obj = temp;
    }
    obj->getOCCInternals()->applyBooleanOperator(occ_tool->getShape(),
                                                 OCC_Internals::Intersection);
    obj->destroy();
    obj->_occ_internals->buildLists();
    obj->_occ_internals->buildGModel(obj);
  }
  catch(Standard_Failure &err){
    Msg::Error("%s", err.GetMessageString());
  }
  return obj;
}

void OCCFactory::fillet(GModel *gm, std::vector<int> edges, double radius)
{
  try{
    std::vector<TopoDS_Edge> edgesToFillet;
    for (int i=0;i<edges.size();i++){
      GEdge *ed = gm->getEdgeByTag(edges[i]);
      if (ed){
	OCCEdge *occed = dynamic_cast<OCCEdge*>(ed);
	if (occed)edgesToFillet.push_back(occed->getTopoDS_Edge());
    }
    }
    gm->_occ_internals->fillet(edgesToFillet,radius);
    gm->destroy();
    gm->_occ_internals->buildLists();
    gm->_occ_internals->buildGModel(gm);  
  }
  catch(Standard_Failure &err){
    Msg::Error("%s", err.GetMessageString());
  }
}

void OCCFactory::translate(GModel *gm, std::vector<double> dx, int addToTheModel)
{
  gp_Trsf transformation;
  transformation.SetTranslation(gp_Pnt (0,0,0),gp_Pnt (dx[0],dx[1],dx[2]));
  BRepBuilderAPI_Transform aTransformation(gm->_occ_internals->getShape(),
                                           transformation, Standard_False);
  TopoDS_Shape temp = aTransformation.Shape();
  if (!addToTheModel)gm->_occ_internals->loadShape(& temp);
  else gm->_occ_internals->buildShapeFromLists(temp);
  gm->destroy();
  gm->_occ_internals->buildLists();
  gm->_occ_internals->buildGModel(gm);    
}

void OCCFactory::rotate(GModel *gm, std::vector<double> p1,std::vector<double> p2,
                        double angle, int addToTheModel)
{
  const double x1 =p1[0]; 
  const double y1 =p1[1]; 
  const double z1 =p1[2]; 
  const double x2 =p2[0]; 
  const double y2 =p2[1]; 
  const double z2 =p2[2]; 

  if (!gm->_occ_internals)
    gm->_occ_internals = new OCC_Internals;

  gp_Trsf transformation;

  gp_Vec direction (gp_Pnt (x1,y1,z1),gp_Pnt (x2,y2,z2));
  gp_Ax1 axisOfRevolution (gp_Pnt (x1,y1,z1),direction);
  transformation.SetRotation(axisOfRevolution, angle);
  BRepBuilderAPI_Transform aTransformation(gm->_occ_internals->getShape(),
                                           transformation, Standard_False);
  TopoDS_Shape temp = aTransformation.Shape();
  if (!addToTheModel)gm->_occ_internals->loadShape(& temp);
  else gm->_occ_internals->buildShapeFromLists(temp);
  gm->destroy();
  gm->_occ_internals->buildLists();
  gm->_occ_internals->buildGModel(gm);    
}

#endif
