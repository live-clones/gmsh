// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <stdlib.h>
#include "GModelFactory.h"
#include "ListUtils.h"
#include "Context.h"
#include "GVertex.h"
#include "gmshVertex.h"
#include "gmshEdge.h"
#include "gmshFace.h"
#include "gmshRegion.h"
#include "GEdgeCompound.h"
#include "MLine.h"
#include "GModel.h"
#include "Numeric.h"
#include "ExtrudeParams.h"
#include "Geo.h"

GVertex *GeoFactory::addVertex(GModel *gm, double x, double y, double z, double lc)
{
  int num =  gm->getMaxElementaryNumber(0) + 1;

  x *= CTX::instance()->geom.scalingFactor;
  y *= CTX::instance()->geom.scalingFactor;
  z *= CTX::instance()->geom.scalingFactor;
  lc *= CTX::instance()->geom.scalingFactor;
  if(lc == 0.) lc = MAX_LC; // no mesh size given at the point
  Vertex *p;
  p = Create_Vertex(num, x, y, z, lc, 1.0);
  Tree_Add(gm->getGEOInternals()->Points, &p);
  p->Typ = MSH_POINT;
  p->Num = num;

  GVertex *v = new gmshVertex(gm, p);
  gm->add(v);

  return v;
}

GEdge *GeoFactory::addLine(GModel *gm, GVertex *start, GVertex *end)
{
  int num =  gm->getMaxElementaryNumber(1) + 1;
  List_T *iList = List_Create(2, 2, sizeof(int));
  int tagBeg = start->tag();
  int tagEnd = end->tag();
  List_Add(iList, &tagBeg);
  List_Add(iList, &tagEnd);

  Curve *c = Create_Curve(num, MSH_SEGM_LINE, 1, iList, NULL,
			  -1, -1, 0., 1.);
  Tree_Add(gm->getGEOInternals()->Curves, &c);
  CreateReversedCurve(c);
  List_Delete(iList);
  c->Typ = MSH_SEGM_LINE;
  c->Num = num;

  GEdge *e = new gmshEdge(gm, c, start, end);
  gm->add(e);

  return e;
}

GFace *GeoFactory::addPlanarFace(GModel *gm, std::vector< std::vector<GEdge *> > edges)
{

  //create line loops
  int nLoops = edges.size();
  std::vector<EdgeLoop *> vecLoops;
  for (int i=0; i< nLoops; i++){
    int ne=(int)edges[i].size();
    List_T *temp = List_Create(ne, ne, sizeof(int));
    for(int j = 0; j < ne; j++){
      GEdge *ge = edges[i][j];
      int numEdge = ge->tag();
      //create curve if it does not exist
      Curve *c = FindCurve(numEdge);
      if(!c){
	GVertex *gvb = ge->getBeginVertex();
	GVertex *gve = ge->getEndVertex();
	Vertex *vertb = FindPoint(abs(gvb->tag()));
	Vertex *verte = FindPoint(abs(gve->tag()));
	if (!vertb){
	  vertb = Create_Vertex(gvb->tag(), gvb->x(), gvb->y(), gvb->z(),
				gvb->prescribedMeshSizeAtVertex(), 1.0);
	  Tree_Add(gm->getGEOInternals()->Points, &vertb);
	  vertb->Typ = MSH_POINT;
	  vertb->Num = gvb->tag();
	 }
	if (!verte){
	  verte = Create_Vertex(gve->tag(), gve->x(), gve->y(), gve->z(),
				gve->prescribedMeshSizeAtVertex(), 1.0);
	  Tree_Add(gm->getGEOInternals()->Points, &verte);
	  verte->Typ = MSH_POINT;
	  verte->Num = gve->tag();
	}

	if (ge->geomType() == GEntity::Line){
	  c = Create_Curve(numEdge, MSH_SEGM_LINE, 1, NULL, NULL, -1, -1, 0., 1.);
	}
	else if (ge->geomType() == GEntity::DiscreteCurve){
	  c = Create_Curve(numEdge, MSH_SEGM_DISCRETE, 1, NULL, NULL, -1, -1, 0., 1.);
	}
	else if(ge->geomType() == GEntity::CompoundCurve){
	  c = Create_Curve(numEdge, MSH_SEGM_COMPOUND, 1, NULL, NULL, -1, -1, 0., 1.);
	  std::vector<GEdge*> gec = ((GEdgeCompound*)ge)->getCompounds();
	  for(unsigned int i = 0; i < gec.size(); i++)
	    c->compound.push_back(gec[i]->tag());
	}
	else{
	  c = Create_Curve(numEdge, MSH_SEGM_DISCRETE, 1, NULL, NULL, -1, -1, 0., 1.);
	}

	c->Control_Points = List_Create(2, 1, sizeof(Vertex *));
	List_Add(c->Control_Points, &vertb);
	List_Add(c->Control_Points, &verte);
	c->beg = vertb;
	c->end = verte;
	End_Curve(c);

	Tree_Add(gm->getGEOInternals()->Curves, &c);
	CreateReversedCurve(c);
      }
      List_Add(temp, &numEdge);
    }

    int numl = gm->getMaxElementaryNumber(1) + i;
    while (FindEdgeLoop(numl)){
      numl++;
      if (!FindEdgeLoop(numl)) break;
    }
    sortEdgesInLoop(numl, temp, true);
    EdgeLoop *l = Create_EdgeLoop(numl, temp);
    vecLoops.push_back(l);
    Tree_Add(gm->getGEOInternals()->EdgeLoops, &l);
    l->Num = numl;
    List_Delete(temp);
  }

  //create surface
  int numf  = gm->getMaxElementaryNumber(2)+1;
  Surface *s = Create_Surface(numf, MSH_SURF_PLAN);
  List_T *temp = List_Create(nLoops, nLoops, sizeof(int));
  for (unsigned int i=0; i< nLoops; i++){
    int numl = vecLoops[i]->Num;
    List_Add(temp, &numl);
  }

  setSurfaceGeneratrices(s, temp);
  List_Delete(temp);
  End_Surface(s);
  Tree_Add(gm->getGEOInternals()->Surfaces, &s);

  //gmsh surface
  GFace *gf = new gmshFace(gm,s);
  gm->add(gf);

  return gf;
}

GRegion* GeoFactory::addVolume (GModel *gm, std::vector<std::vector<GFace *> > faces)
{

  //create surface loop
  int nLoops = faces.size();
  std::vector<SurfaceLoop *> vecLoops;
  for (int i=0; i< nLoops; i++){
    int nl=(int)faces[i].size();
    List_T *temp = List_Create(nl, nl, sizeof(int));
    for(int j = 0; j < nl; j++){
      int numFace = faces[i][j]->tag();
      List_Add(temp, &numFace);
    }
    int numfl = gm->getMaxElementaryNumber(2) + 1;
    while (FindSurfaceLoop(numfl)){
      numfl++;
      if (!FindSurfaceLoop(numfl)) break;
    }
    SurfaceLoop *l = Create_SurfaceLoop(numfl, temp);
    vecLoops.push_back(l);
    Tree_Add(gm->getGEOInternals()->SurfaceLoops, &l);
    List_Delete(temp);
  }

  //create volume
  int numv = gm->getMaxElementaryNumber(3) + 1;
  Volume *v = Create_Volume(numv, MSH_VOLUME);
  List_T *temp = List_Create(nLoops, nLoops, sizeof(int));
  for (unsigned int i = 0; i < vecLoops.size(); i++){
    int numl = vecLoops[i]->Num;
    List_Add(temp, &numl);
  }
  setVolumeSurfaces(v, temp);
  List_Delete(temp);
  Tree_Add(gm->getGEOInternals()->Volumes, &v);
  v->Typ = MSH_VOLUME;
  v->Num = numv;

  //gmsh volume
  GRegion *gr = new gmshRegion(gm,v);
  gm->add(gr);

  return gr;
}

GEdge* GeoFactory::addCircleArc(GModel *gm,GVertex *begin, GVertex *center, GVertex *end)
{
  int num =  gm->getMaxElementaryNumber(1) + 1;
  List_T *iList = List_Create(2, 2, sizeof(int));
  int tagBeg = begin->tag();
  int tagMiddle = center->tag();
  int tagEnd = end->tag();
  List_Add(iList, &tagBeg);
  List_Add(iList, &tagMiddle);
  List_Add(iList, &tagEnd);

  Curve *c = Create_Curve(num, MSH_SEGM_CIRC, 1, iList, NULL,
			  -1, -1, 0., 1.);
  Tree_Add(gm->getGEOInternals()->Curves, &c);
  CreateReversedCurve(c);
  List_Delete(iList);
  c->Typ = MSH_SEGM_CIRC;
  c->Num = num;

  GEdge *e = new gmshEdge(gm, c, begin, end);
  gm->add(e);

  return e;
}

std::vector<GFace *> GeoFactory::addRuledFaces(GModel *gm,
                                               std::vector<std::vector<GEdge *> > edges)
{
  //create line loops
  std::vector<EdgeLoop *> vecLoops;
  int nLoops = edges.size();
  for (int i=0; i< nLoops; i++){
    int numl = gm->getMaxElementaryNumber(1) + i;
    while (FindEdgeLoop(numl)){
      numl++;
      if (!FindEdgeLoop(numl)) break;
    }
    int nl=(int)edges[i].size();
    List_T *temp = List_Create(nl, nl, sizeof(int));
    for(int j = 0; j < nl; j++){
      int numEdge = edges[i][j]->tag();
      List_Add(temp, &numEdge);
    }
    int type=ENT_LINE;
    if(select_contour(type, edges[i][0]->tag(), temp))
    {
        sortEdgesInLoop(numl, temp);
        EdgeLoop *l = Create_EdgeLoop(numl, temp);
        vecLoops.push_back(l);
        Tree_Add(gm->getGEOInternals()->EdgeLoops, &l);
        l->Num = numl;
    }
    List_Delete(temp);
  }

  //create plane surfaces
  int numf = gm->getMaxElementaryNumber(2) + 1;
  Surface *s = Create_Surface(numf, MSH_SURF_TRIC);
  List_T *iList = List_Create(nLoops, nLoops, sizeof(int));
  for (unsigned int i=0; i< vecLoops.size(); i++){
    int numl = vecLoops[i]->Num;
    List_Add(iList, &numl);
  }
  setSurfaceGeneratrices(s, iList);
  End_Surface(s);
  Tree_Add(gm->getGEOInternals()->Surfaces, &s);
  s->Typ= MSH_SURF_TRIC;
  s->Num = numf;
  List_Delete(iList);

  //gmsh surface
  GFace *gf = new gmshFace(gm,s);
  gm->add(gf);

  std::vector<GFace*> faces;
  faces.push_back(gf);

  return faces;
}

GEntity* GeoFactory::extrudeBoundaryLayer(GModel *gm, GEntity *e, int nbLayers, double hLayer, int dir, int view)
{

  ExtrudeParams ep;
  ep.mesh.BoundaryLayerIndex = dir;
  ep.mesh.ViewIndex = view;
  ep.mesh.NbLayer = 1; //this may be more general for defining different layers
  ep.mesh.hLayer.clear();
  ep.mesh.hLayer.push_back(hLayer);
  ep.mesh.NbElmLayer.clear(); 
  ep.mesh.NbElmLayer.push_back(nbLayers);
  ep.mesh.ExtrudeMesh = true;
  ep.geo.Source = e->tag();

  int type  = BOUNDARY_LAYER; 
  double T0=0., T1=0., T2=0.;
  double A0=0., A1=0., A2=0.;
  double X0=0., X1=0., X2=0.,alpha=0.;

  //extrude shape dans geo.cpp
  Shape shape;
  if(e->dim() == 0){
    Vertex *v = FindPoint(e->tag());
    if(!v) printf("vertex %d not found \n", e->tag());
    shape.Num = v->Num;
    shape.Type = v->Typ;
  }
  else if (e->dim() == 1){
    ((GEdge*)e)->meshAttributes.extrude = &ep;
    Curve *c = FindCurve(e->tag());
    if(!c) printf("curve %d not found \n", e->tag());
     shape.Num = c->Num;
     shape.Type = c->Typ;
  }
  else if (e->dim() == 2){
    ((GFace*)e)->meshAttributes.extrude = &ep;
    Surface *s = FindSurface(e->tag());

    Msg::Info("Geo internal model has:");
    List_T *points = Tree2List(gm->getGEOInternals()->Points);
    List_T *curves = Tree2List(gm->getGEOInternals()->Curves);
    List_T *surfaces = Tree2List(gm->getGEOInternals()->Surfaces);
    Msg::Info("%d Vertices", List_Nbr(points));
    Msg::Info("%d Edges", List_Nbr(curves));
    Msg::Info("%d Faces", List_Nbr(surfaces));
    for(int i = 0; i < List_Nbr(surfaces); i++) {
      Surface *s;
      List_Read(surfaces, i, &s);
      printf("surface %d \n", s->Num);
    }
    if(!s) {
      printf("surface %d NOT found \n", e->tag());
      exit(1);
    }
    else printf("surface %d found type =%d\n", e->tag(), s->Typ);

    shape.Num = s->Num;
    shape.Type = s->Typ;
  }

  //extrude shape
  List_T *list_out= List_Create(2, 1, sizeof(Shape));
  List_T *tmp = List_Create(1, 1, sizeof(Shape));
  List_Add(tmp, &shape);
  ExtrudeShapes(type, tmp,
                T0, T1, T2,
                A0, A1, A2,
                X0, X1, X2, alpha,
                &ep,
                list_out);

  Msg::Info("AFTER EXTRUDE Geo internal model has:");
  List_T *points = Tree2List(gm->getGEOInternals()->Points);
  List_T *curves = Tree2List(gm->getGEOInternals()->Curves);
  List_T *surfaces = Tree2List(gm->getGEOInternals()->Surfaces);
  Msg::Info("%d Vertices", List_Nbr(points));
  Msg::Info("%d Edges", List_Nbr(curves));
  Msg::Info("%d Faces", List_Nbr(surfaces));
  for(int i = 0; i < List_Nbr(surfaces); i++) {
    Surface *s;
    List_Read(surfaces, i, &s);
    printf("surface %d \n", s->Num);
  }

  //create GEntities 
  gm->importGEOInternals();

  //return the new created entity
  GEntity *newEnt=0;
  if (e->dim() == 1){
   for(GModel::eiter it = gm->firstEdge(); it != gm->lastEdge(); it++){
     GEdge *ge = *it;
    if(ge->getNativeType() == GEntity::GmshModel &&
       ge->geomType() == GEntity::BoundaryLayerCurve){
      ExtrudeParams *ep = ge->meshAttributes.extrude;
      if(ep && ep->mesh.ExtrudeMesh && ep->geo.Mode == COPIED_ENTITY &&
	std::abs(ep->geo.Source) ==e->tag() )
	  newEnt = ge;
      }
    }
  }
  else if (e->dim() ==2){
    for(GModel::fiter it = gm->firstFace(); it != gm->lastFace(); it++){
      GFace *gf = *it;
      if(gf->getNativeType() == GEntity::GmshModel &&
	 gf->geomType() == GEntity::BoundaryLayerSurface){
	ExtrudeParams *ep = gf->meshAttributes.extrude;
	if(ep && ep->mesh.ExtrudeMesh && ep->geo.Mode == COPIED_ENTITY 
	   && std::abs(ep->geo.Source) == e->tag())
	  newEnt = gf;
      }
    }
  }

  return newEnt;

};

#if defined(HAVE_OCC)
#include "OCCIncludes.h"
#include "GModelIO_OCC.h"
#include "OCCVertex.h"
#include "OCCEdge.h"
#include "OCCFace.h"
#include "OCCRegion.h"
#include "BRepBuilderAPI_MakeVertex.hxx"
#include "BRepOffsetAPI_MakePipe.hxx"
#include "BRepBuilderAPI_MakeEdge.hxx"
#include "BRepPrimAPI_MakeRevol.hxx"
#include "BRepPrimAPI_MakePrism.hxx"
#include "BRepBuilderAPI_MakeWire.hxx"
#include "BRepOffsetAPI_ThruSections.hxx"
#include "BRepOffsetAPI_MakeFilling.hxx"
#include "BRepBuilderAPI_MakeFace.hxx"
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
    gce_MakeCirc MC(aP2,gce_MakePln(aP1, aP2, aP3).Value(), Radius);
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
  return gm->_occ_internals->addEdgeToModel(gm, occEdge);
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

  for (unsigned i = 0; i < knots.size(); i++) {
    _knots.SetValue(i+1, knots[i]);
  }
  for (unsigned i = 0; i < weights.size(); i++) {
    _weights.SetValue(i+1, weights[i]);
  }
  int totKnots = 0;
  for (unsigned i = 0; i < mult.size(); i++) {
    _mult.SetValue(i+1, mult[i]);
    totKnots += mult[i];
  }

  const int degree = totKnots - nbControlPoints - 1;
  Msg::Debug("creation of a nurbs of degree %d with %d control points",
	     degree,nbControlPoints);

  int index = 1;
  ctrlPoints.SetValue(index++, gp_Pnt(start->x(), start->y(), start->z()));
  for (unsigned i = 0; i < points.size(); i++) {
    gp_Pnt aP(points[i][0],points[i][1],points[i][2]);
    ctrlPoints.SetValue(index++, aP);
  }
  ctrlPoints.SetValue(index++, gp_Pnt(end->x(), end->y(), end->z()));
  Handle(Geom_BSplineCurve) NURBS = new Geom_BSplineCurve
    (ctrlPoints, _weights, _knots, _mult, degree, false);
  TopoDS_Edge occEdge;
  if (occv1 && occv2)
    occEdge = BRepBuilderAPI_MakeEdge(NURBS, occv1->getShape(),
                                      occv2->getShape()).Edge();
  else
    occEdge = BRepBuilderAPI_MakeEdge(NURBS).Edge();
  return gm->_occ_internals->addEdgeToModel(gm, occEdge);
  }
  catch(Standard_Failure &err){
    Msg::Error("%s", err.GetMessageString());
  }
  return 0;
}

/*
GEdge *OCCFactory::addBezierSurface(GModel *gm,
				    std::vector<GEdge *> & wires, // four edges indeed
				    std::vector<std::vector<double> > points)
{

  TColgp_Array2OfPnt ctrlPoints(1, nbControlPoints + 2);
  int index = 1;
  ctrlPoints.SetValue(index++, gp_Pnt(start->x(), start->y(), start->z()));
  for (int i = 0; i < nbControlPoints; i++) {
    gp_Pnt aP(points[i][0],points[i][1],points[i][2]);
    ctrlPoints.SetValue(index++, aP);
  }


  BRepBuilderAPI_MakeFace aGenerator (aBezierSurface);
  BRepBuilderAPI_MakeWire wire_maker;
  for (unsigned j = 0; j < wires.size(); j++) {
    GEdge *ge = wires[j];
    OCCEdge *occe = dynamic_cast<OCCEdge*>(ge);
    if (occe){
      wire_maker.Add(occe->getTopoDS_Edge());
    }
  }
  TopoDS_Wire myWire = wire_maker.Wire();
  aGenerator.Add (myWire);
  aGenerator.Build();
  TopoDS_Shape aResult = aGenerator.Shape();
  return gm->_occ_internals->addFaceToModel(gm, TopoDS::Face(aResult));
}
*/
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
  GEntity *ret = 0;
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
  BRepPrimAPI_MakePrism MP(*(TopoDS_Shape*)base->getNativePtr(), direction,
                           Standard_False);
  GEntity *ret = 0;
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
  return getOCCRegionByNativePtr(gm, TopoDS::Solid(shape));
}

GRegion* OCCFactory::addVolume (GModel *gm, std::vector<std::vector<GFace *> > faces)
{
  Msg::Error("add Volume not implemented yet for OCCFactory");
  return 0;
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
  return getOCCRegionByNativePtr(gm, TopoDS::Solid(shape));
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
  return getOCCRegionByNativePtr(gm, TopoDS::Solid(shape));
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
  return getOCCRegionByNativePtr(gm, TopoDS::Solid(shape));
}

GModel *OCCFactory::computeBooleanUnion(GModel* obj, GModel* tool,
                                        int createNewModel)
{
  try{
    OCC_Internals *occ_obj = obj->getOCCInternals();
    OCC_Internals *occ_tool = tool->getOCCInternals();

    if (!occ_obj || !occ_tool) return NULL;

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
    OCC_Internals *occ_obj = obj->getOCCInternals();
    OCC_Internals *occ_tool = tool->getOCCInternals();

    if (!occ_obj || !occ_tool) return NULL;

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
    OCC_Internals *occ_obj = obj->getOCCInternals();
    OCC_Internals *occ_tool = tool->getOCCInternals();

    if (!occ_obj || !occ_tool) return NULL;

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
    for (unsigned i = 0; i < edges.size(); i++){
      GEdge *ed = gm->getEdgeByTag(edges[i]);
      if (ed){
	OCCEdge *occed = dynamic_cast<OCCEdge*>(ed);
	if (occed)edgesToFillet.push_back(occed->getTopoDS_Edge());
      }
    }
    gm->_occ_internals->fillet(edgesToFillet, radius);
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
  if (!addToTheModel) gm->_occ_internals->loadShape(& temp);
  else gm->_occ_internals->buildShapeFromLists(temp);
  gm->destroy();
  gm->_occ_internals->buildLists();
  gm->_occ_internals->buildGModel(gm);
}

void OCCFactory::rotate(GModel *gm, std::vector<double> p1, std::vector<double> p2,
                        double angle, int addToTheModel)
{
  const double x1 = p1[0];
  const double y1 = p1[1];
  const double z1 = p1[2];
  const double x2 = p2[0];
  const double y2 = p2[1];
  const double z2 = p2[2];

  if (!gm->_occ_internals)
    gm->_occ_internals = new OCC_Internals;

  gp_Trsf transformation;

  gp_Vec direction(gp_Pnt(x1, y1, z1), gp_Pnt(x2, y2, z2));
  gp_Ax1 axisOfRevolution(gp_Pnt(x1, y1, z1), direction);
  transformation.SetRotation(axisOfRevolution, angle);
  BRepBuilderAPI_Transform aTransformation(gm->_occ_internals->getShape(),
                                           transformation, Standard_False);
  TopoDS_Shape temp = aTransformation.Shape();
  if (!addToTheModel) gm->_occ_internals->loadShape(&temp);
  else gm->_occ_internals->buildShapeFromLists(temp);
  gm->destroy();
  gm->_occ_internals->buildLists();
  gm->_occ_internals->buildGModel(gm);
}

std::vector<GFace *> OCCFactory::addRuledFaces(GModel *gm,
					      std::vector< std::vector<GEdge *> > wires)
{
  std::vector<GFace*> faces;
  Standard_Boolean anIsSolid = Standard_False;
  Standard_Boolean anIsRuled = Standard_True;
  BRepOffsetAPI_ThruSections aGenerator (anIsSolid,anIsRuled);

  for (unsigned i=0;i<wires.size();i++) {
    BRepBuilderAPI_MakeWire wire_maker;
    for (unsigned j=0;j<wires[i].size();j++) {
      GEdge *ge = wires[i][j];
      OCCEdge *occe = dynamic_cast<OCCEdge*>(ge);
      if (occe){
	wire_maker.Add(occe->getTopoDS_Edge());
      }
    }
    aGenerator.AddWire (wire_maker.Wire());
  }

  aGenerator.CheckCompatibility (Standard_False);

  aGenerator.Build();

  TopoDS_Shape aResult = aGenerator.Shape();

  TopExp_Explorer exp2;
  for(exp2.Init(TopoDS::Shell(aResult), TopAbs_FACE); exp2.More(); exp2.Next()){
    TopoDS_Face face = TopoDS::Face(exp2.Current());
    GFace *ret = gm->_occ_internals->addFaceToModel(gm, face);
    faces.push_back(ret);
  }
  return faces;
}

GFace *OCCFactory::addFace(GModel *gm, std::vector<GEdge *> edges,
                           std::vector< std::vector<double > > points)
{
  BRepOffsetAPI_MakeFilling aGenerator;

  for (unsigned i = 0; i < edges.size(); i++) {
    GEdge *ge = edges[i];
    OCCEdge *occe = dynamic_cast<OCCEdge*>(ge);
    if (occe){
      aGenerator.Add(occe->getTopoDS_Edge(), GeomAbs_C0);
    }
  }
  for (unsigned i = 0; i < points.size(); i++) {
    gp_Pnt aPnt(points[i][0], points[i][1], points[i][2]);
    aGenerator.Add(aPnt);
  }

  aGenerator.Build();

  TopoDS_Shape aResult = aGenerator.Shape();
  return gm->_occ_internals->addFaceToModel(gm, TopoDS::Face(aResult));
}

GFace *OCCFactory::addPlanarFace(GModel *gm, std::vector< std::vector<GEdge *> > wires)
{

  std::set<GVertex*> verts;
  for (unsigned i = 0; i < wires.size(); i++) {
    for (unsigned j = 0; j < wires[i].size(); j++) {
      GEdge *ge = wires[i][j];
      verts.insert(ge->getBeginVertex());
      verts.insert(ge->getEndVertex());
    }
  }
  std::vector<SPoint3> points;
  std::set<GVertex*>::iterator it = verts.begin();
  for ( ; it != verts.end(); ++it){
    points.push_back(SPoint3((*it)->x(), (*it)->y(), (*it)->z()));
  }

  mean_plane meanPlane;
  computeMeanPlaneSimple(points, meanPlane);

  gp_Pln aPlane (meanPlane.a,meanPlane.b,meanPlane.c,meanPlane.d);
  BRepBuilderAPI_MakeFace aGenerator (aPlane);

  for (unsigned i = 0; i < wires.size() ;i++) {
    BRepBuilderAPI_MakeWire wire_maker;
    for (unsigned j = 0; j < wires[i].size(); j++) {
      GEdge *ge = wires[i][j];
      OCCEdge *occe = dynamic_cast<OCCEdge*>(ge);
      if (occe){
	wire_maker.Add(occe->getTopoDS_Edge());
      }
    }
    TopoDS_Wire myWire = wire_maker.Wire();
    //if (i)myWire.Reverse();
    aGenerator.Add (myWire);
  }

  aGenerator.Build();
  TopoDS_Shape aResult = aGenerator.Shape();

  return gm->_occ_internals->addFaceToModel(gm, TopoDS::Face(aResult));

}

GEntity *OCCFactory::addPipe(GModel *gm, GEntity *base, std::vector<GEdge *> wire)
{
  BRepBuilderAPI_MakeWire wire_maker;
  for (unsigned j = 0; j < wire.size(); j++) {
    GEdge *ge = wire[j];
    OCCEdge *occe = dynamic_cast<OCCEdge*>(ge);
    if (occe){
      wire_maker.Add(occe->getTopoDS_Edge());
    }
  }
  TopoDS_Wire myWire = wire_maker.Wire();

  GEntity *ret = 0;
  if (base->cast2Vertex()){
    OCCVertex *occv = dynamic_cast<OCCVertex*>(base);
    BRepOffsetAPI_MakePipe myNiceLittlePipe (myWire, occv->getShape());
    TopoDS_Edge result = TopoDS::Edge(myNiceLittlePipe.Shape());
    ret = gm->_occ_internals->addEdgeToModel(gm, result);
  }
  if (base->cast2Edge()){
    OCCEdge *occe = dynamic_cast<OCCEdge*>(base);
    BRepOffsetAPI_MakePipe myNiceLittlePipe (myWire, occe->getTopoDS_Edge());
    TopoDS_Face result = TopoDS::Face(myNiceLittlePipe.Shape());
    ret = gm->_occ_internals->addFaceToModel(gm, result);
  }
  if (base->cast2Face()){
    OCCFace *occf = dynamic_cast<OCCFace*>(base);
    BRepOffsetAPI_MakePipe myNiceLittlePipe (myWire, occf->getTopoDS_Face());
    TopoDS_Solid result = TopoDS::Solid(myNiceLittlePipe.Shape());
    ret = gm->_occ_internals->addRegionToModel(gm, result);
  }
  return ret;
}

#endif
