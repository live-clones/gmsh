// $Id: GModelIO_OCC.cpp,v 1.27 2008-02-20 09:20:45 geuzaine Exp $
//
// Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.

#include "GModelIO_OCC.h"
#include "Message.h"
#include "Context.h"
#include "OCCVertex.h"
#include "OCCEdge.h"
#include "OCCFace.h"
#include "OCCRegion.h"

extern Context_T CTX;

#if defined(HAVE_OCC)

void OCC_Internals::buildLists()
{
  TopExp_Explorer exp0, exp1, exp2, exp3, exp4, exp5;
  somap.Clear();
  shmap.Clear();
  fmap.Clear();
  wmap.Clear();
  emap.Clear();
  vmap.Clear();
  
  for(exp0.Init(shape, TopAbs_SOLID); exp0.More(); exp0.Next()){
    TopoDS_Solid solid = TopoDS::Solid(exp0.Current());
    if(somap.FindIndex(TopoDS::Solid(exp0.Current())) < 1){
      somap.Add(TopoDS::Solid(exp0.Current()));

      for(exp1.Init(exp0.Current(), TopAbs_SHELL); exp1.More(); exp1.Next()){
	TopoDS_Shell shell = TopoDS::Shell(exp1.Current().Composed(exp0.Current().Orientation()));
	if(shmap.FindIndex(shell) < 1){
	  shmap.Add(shell);

	  for(exp2.Init(shell, TopAbs_FACE); exp2.More(); exp2.Next()){
	    TopoDS_Face face = TopoDS::Face(exp2.Current().Composed(shell.Orientation()));
	    if(fmap.FindIndex(face) < 1){
	      fmap.Add(face);

	      for(exp3.Init(exp2.Current(), TopAbs_WIRE); exp3.More(); exp3.Next()){
		TopoDS_Wire wire = TopoDS::Wire(exp3.Current().Composed(face.Orientation()));
		if(wmap.FindIndex(wire) < 1){
		  wmap.Add(wire);

		  for(exp4.Init(exp3.Current(), TopAbs_EDGE); exp4.More(); exp4.Next()){
		    TopoDS_Edge edge = TopoDS::Edge(exp4.Current().Composed(wire.Orientation()));
		    if(emap.FindIndex(edge) < 1){
		      emap.Add(edge);

		      for(exp5.Init(exp4.Current(), TopAbs_VERTEX); exp5.More(); exp5.Next()){
			TopoDS_Vertex vertex = TopoDS::Vertex(exp5.Current());
			if(vmap.FindIndex(vertex) < 1)
			  vmap.Add(vertex);
		      }
		    }
		  }
		}
	      }
	    }
	  }
	}
      }
    }
  }
  
  // Free Shells
  for(exp1.Init(exp0.Current(), TopAbs_SHELL, TopAbs_SOLID); exp1.More(); exp1.Next()){
    TopoDS_Shape shell = exp1.Current().Composed(exp0.Current().Orientation());
    if(shmap.FindIndex(shell) < 1){
      shmap.Add(shell);

      for(exp2.Init(shell, TopAbs_FACE); exp2.More(); exp2.Next()){
	TopoDS_Face face = TopoDS::Face(exp2.Current().Composed(shell.Orientation()));
	if(fmap.FindIndex(face) < 1){
	  fmap.Add(face);
		  
	  for(exp3.Init(exp2.Current(), TopAbs_WIRE); exp3.More(); exp3.Next()){
	    TopoDS_Wire wire = TopoDS::Wire(exp3.Current());
	    if(wmap.FindIndex(wire) < 1){
	      wmap.Add(wire);

	      for(exp4.Init(exp3.Current(), TopAbs_EDGE); exp4.More(); exp4.Next()){
		TopoDS_Edge edge = TopoDS::Edge(exp4.Current());
		if(emap.FindIndex(edge) < 1){
		  emap.Add(edge);

		  for(exp5.Init(exp4.Current(), TopAbs_VERTEX); exp5.More(); exp5.Next()){
		    TopoDS_Vertex vertex = TopoDS::Vertex(exp5.Current());
		    if(vmap.FindIndex(vertex) < 1)
		      vmap.Add(vertex);
		  }
		}
	      }
	    }
	  }
	}
      }
    }
  }
    
  // Free Faces
  for(exp2.Init(shape, TopAbs_FACE, TopAbs_SHELL); exp2.More(); exp2.Next()){
    TopoDS_Face face = TopoDS::Face(exp2.Current());
    if(fmap.FindIndex(face) < 1){
      fmap.Add(face);
	  
      for(exp3.Init(exp2.Current(), TopAbs_WIRE); exp3.More(); exp3.Next()){
	TopoDS_Wire wire = TopoDS::Wire(exp3.Current());
	if(wmap.FindIndex(wire) < 1){
	  wmap.Add(wire);
	  
	  for(exp4.Init(exp3.Current(), TopAbs_EDGE); exp4.More(); exp4.Next()){
	    TopoDS_Edge edge = TopoDS::Edge(exp4.Current());
	    if(emap.FindIndex(edge) < 1){
	      emap.Add(edge);

	      for(exp5.Init(exp4.Current(), TopAbs_VERTEX); exp5.More(); exp5.Next()){
		TopoDS_Vertex vertex = TopoDS::Vertex(exp5.Current());
		if(vmap.FindIndex(vertex) < 1)
		  vmap.Add(vertex);
	      }
	    }
	  }
	}
      }
    }
  }

  // Free Wires
  for(exp3.Init(shape, TopAbs_WIRE, TopAbs_FACE); exp3.More(); exp3.Next()){
    TopoDS_Wire wire = TopoDS::Wire(exp3.Current());
    if(wmap.FindIndex(wire) < 1){
      wmap.Add(wire);
      
      for(exp4.Init(exp3.Current(), TopAbs_EDGE); exp4.More(); exp4.Next()){
	TopoDS_Edge edge = TopoDS::Edge(exp4.Current());
	if(emap.FindIndex(edge) < 1){
	  emap.Add(edge);

	  for(exp5.Init(exp4.Current(), TopAbs_VERTEX); exp5.More(); exp5.Next()){
	    TopoDS_Vertex vertex = TopoDS::Vertex(exp5.Current());
	    if(vmap.FindIndex(vertex) < 1)
	      vmap.Add(vertex);
	  }
	}
      }
    }
  }

  // Free Edges
  for(exp4.Init(shape, TopAbs_EDGE, TopAbs_WIRE); exp4.More(); exp4.Next()){
    TopoDS_Edge edge = TopoDS::Edge(exp4.Current());
    if(emap.FindIndex(edge) < 1){
      emap.Add(edge);

      for(exp5.Init(exp4.Current(), TopAbs_VERTEX); exp5.More(); exp5.Next()){
	TopoDS_Vertex vertex = TopoDS::Vertex(exp5.Current());
	if(vmap.FindIndex(vertex) < 1)
	  vmap.Add(vertex);
      }
    }
  }

  // Free Vertices
  for(exp5.Init(shape, TopAbs_VERTEX, TopAbs_EDGE); exp5.More(); exp5.Next()){
    TopoDS_Vertex vertex = TopoDS::Vertex(exp5.Current());
    if(vmap.FindIndex(vertex) < 1)
      vmap.Add(vertex);
  }    
  
}

void OCC_Internals::HealGeometry(double tolerance, bool fixsmalledges, 
				 bool fixspotstripfaces, bool sewfaces, 
				 bool makesolids)
{
  int nrc = 0, nrcs = 0;
  TopExp_Explorer e;
  for(e.Init(shape, TopAbs_COMPOUND); e.More(); e.Next()) nrc++;
  for(e.Init(shape, TopAbs_COMPSOLID); e.More(); e.Next()) nrcs++;

  double surfacecont = 0;

  for(int i = 1; i <= fmap.Extent(); i++){
    GProp_GProps system;
    BRepGProp::LinearProperties(fmap(i), system);
    surfacecont += system.Mass();
  }

  Msg(INFO, "Healing geometry (tolerance=%g)", tolerance);

  if(fixsmalledges){
    Msg(INFO, "- fixing small edges");

    Handle(ShapeFix_Wire) sfw;
    Handle_ShapeBuild_ReShape rebuild = new ShapeBuild_ReShape;
    rebuild->Apply(shape);
    
    for(int i = 1; i <= fmap.Extent(); i++){
      TopExp_Explorer exp1;
      for(exp1.Init(fmap(i), TopAbs_WIRE); exp1.More(); exp1.Next()){
	TopoDS_Wire oldwire = TopoDS::Wire(exp1.Current());
	sfw = new ShapeFix_Wire(oldwire, TopoDS::Face(fmap(i)), tolerance);
	sfw->ModifyTopologyMode() = Standard_True;
	
	if(sfw->FixSmall(false, tolerance)){
	  Msg(INFO, "Fixed small edge in wire %d", wmap.FindIndex(oldwire));
	  TopoDS_Wire newwire = sfw->Wire();
	  rebuild->Replace(oldwire, newwire, Standard_False);
	}
	if((sfw->StatusSmall(ShapeExtend_FAIL1)) ||
	   (sfw->StatusSmall(ShapeExtend_FAIL2)) ||
	   (sfw->StatusSmall(ShapeExtend_FAIL3)))
	  Msg(INFO, "Failed to fix small edge in wire %d",  wmap.FindIndex(oldwire));
      }
    }
    shape = rebuild->Apply(shape);
    
    {
      Handle_ShapeBuild_ReShape rebuild = new ShapeBuild_ReShape;
      rebuild->Apply(shape);
      TopExp_Explorer exp1;
      for(exp1.Init(shape, TopAbs_EDGE); exp1.More(); exp1.Next()){
	TopoDS_Edge edge = TopoDS::Edge(exp1.Current());
	if(vmap.FindIndex(TopExp::FirstVertex(edge)) == 
	   vmap.FindIndex(TopExp::LastVertex(edge))){
	  GProp_GProps system;
	  BRepGProp::LinearProperties(edge, system);
	  if(system.Mass() < tolerance){
	    Msg(INFO, "removing degenerated edge %d", emap.FindIndex(edge));
	    rebuild->Remove(edge, false);
	  }
	}
      }
      shape = rebuild->Apply(shape);
    }
    
    Handle(ShapeFix_Wireframe) sfwf = new ShapeFix_Wireframe;
    sfwf->SetPrecision(tolerance);
    sfwf->Load(shape);
    
    if(sfwf->FixSmallEdges()){
      Msg(INFO, "- fixing wire frames");
      if(sfwf->StatusSmallEdges(ShapeExtend_OK)) Msg(INFO, "no small edges found");
      if(sfwf->StatusSmallEdges(ShapeExtend_DONE1)) Msg(INFO, "some small edges fixed");
      if(sfwf->StatusSmallEdges(ShapeExtend_FAIL1)) Msg(INFO, "failed to fix some small edges");
    }
  
    if(sfwf->FixWireGaps()){
      Msg(INFO, "- fixing wire gaps");
      if(sfwf->StatusWireGaps(ShapeExtend_OK)) Msg(INFO, "no gaps found");
      if(sfwf->StatusWireGaps(ShapeExtend_DONE1)) Msg(INFO, "some 2D gaps fixed");
      if(sfwf->StatusWireGaps(ShapeExtend_DONE2)) Msg(INFO, "some 3D gaps fixed");
      if(sfwf->StatusWireGaps(ShapeExtend_FAIL1)) Msg(INFO, "failed to fix some 2D gaps");
      if(sfwf->StatusWireGaps(ShapeExtend_FAIL2)) Msg(INFO, "failed to fix some 3D gaps");
    }
    
    shape = sfwf->Shape();
  }
  
  if(fixspotstripfaces){
    Msg(INFO, "- fixing spot and strip faces");
    Handle(ShapeFix_FixSmallFace) sffsm = new ShapeFix_FixSmallFace();
    sffsm->Init(shape);
    sffsm->SetPrecision(tolerance);
    sffsm->Perform();
    
    shape = sffsm->FixShape();
  }
  
  if(sewfaces){
    Msg(INFO, "- sewing faces");

    TopExp_Explorer exp0;
    
    BRepOffsetAPI_Sewing sewedObj(tolerance);
    
    for(exp0.Init(shape, TopAbs_FACE); exp0.More(); exp0.Next()){
      TopoDS_Face face = TopoDS::Face(exp0.Current());
      sewedObj.Add(face);
    }
    
    sewedObj.Perform();
    
    if(!sewedObj.SewedShape().IsNull())
      shape = sewedObj.SewedShape();
    else
      Msg(INFO, " not possible");
  }
  
  if(makesolids){  
    Msg(INFO, "- making solids");
    
    TopExp_Explorer exp0;
    
    BRepBuilderAPI_MakeSolid ms;
    int count = 0;
    for(exp0.Init(shape, TopAbs_SHELL); exp0.More(); exp0.Next()){
      count++;
      ms.Add(TopoDS::Shell(exp0.Current()));
    }
    
    if(!count){
      Msg(INFO, " not possible (no shells)");
    }
    else{
      BRepCheck_Analyzer ba(ms);
      if(ba.IsValid()){
	Handle(ShapeFix_Shape) sfs = new ShapeFix_Shape;
	sfs->Init(ms);
	sfs->SetPrecision(tolerance);
	sfs->SetMaxTolerance(tolerance);
	sfs->Perform();
	shape = sfs->Shape();
	
	for(exp0.Init(shape, TopAbs_SOLID); exp0.More(); exp0.Next()){
	  TopoDS_Solid solid = TopoDS::Solid(exp0.Current());
	  TopoDS_Solid newsolid = solid;
	  BRepLib::OrientClosedSolid(newsolid);
	  Handle_ShapeBuild_ReShape rebuild = new ShapeBuild_ReShape;
	  // rebuild->Apply(shape);
	  rebuild->Replace(solid, newsolid, Standard_False);
	  TopoDS_Shape newshape = rebuild->Apply(shape, TopAbs_COMPSOLID, 1);
	  // TopoDS_Shape newshape = rebuild->Apply(shape);
	  shape = newshape;
	}
      }
      else
	Msg(INFO, " not possible");
    }
  }
  buildLists();
}

void OCC_Internals::loadBREP(const char *fn)
{
  BRep_Builder aBuilder;
  BRepTools::Read(shape, (char*)fn, aBuilder);
  BRepTools::Clean(shape);
  buildLists();
  HealGeometry(CTX.geom.tolerance, 
 	       CTX.geom.occ_fix_small_edges,
 	       CTX.geom.occ_fix_small_faces,
 	       CTX.geom.occ_sew_faces);
  BRepTools::Clean(shape);
}

void OCC_Internals::loadSTEP(const char *fn)
{
  STEPControl_Reader reader;
  reader.ReadFile((char*)fn);
  reader.NbRootsForTransfer();
  reader.TransferRoots(); 
  shape = reader.OneShape();  
  BRepTools::Clean(shape);
  buildLists();
  HealGeometry(CTX.geom.tolerance, 
 	       CTX.geom.occ_fix_small_edges,
 	       CTX.geom.occ_fix_small_faces,
 	       CTX.geom.occ_sew_faces);
  BRepTools::Clean(shape);
}

void OCC_Internals::loadIGES(const char *fn)
{
  IGESControl_Reader reader;
  reader.ReadFile((char*)fn);
  reader.NbRootsForTransfer();
  reader.TransferRoots(); 
  shape = reader.OneShape();  
  BRepTools::Clean(shape);
  buildLists();
  HealGeometry(CTX.geom.tolerance, 
	       CTX.geom.occ_fix_small_edges,
	       CTX.geom.occ_fix_small_faces,
	       CTX.geom.occ_sew_faces);
  BRepTools::Clean(shape);
}

void OCC_Internals::buildGModel(GModel *model)
{
  // building geom vertices
  int nvertices = vmap.Extent();
  for(int i = 1; i <= nvertices; i++){
    OCCVertex *v = new OCCVertex(model, i, TopoDS::Vertex(vmap(i)));
    model->add(v);
  }
  // building geom edges
  int nedges = emap.Extent();
  for(int i = 1; i <= nedges; i++){
    TopoDS_Edge edge = TopoDS::Edge(emap(i));
    int i1 = vmap.FindIndex(TopExp::FirstVertex(edge)); 
    int i2 = vmap.FindIndex(TopExp::LastVertex(edge));
    GVertex *v1 = model->getVertex(i1);
    GVertex *v2 = model->getVertex(i2);
    OCCEdge *e = new OCCEdge(model, edge, i, v1, v2);
    model->add(e);
  }
  // building geom faces
  int nfaces = fmap.Extent();
  for(int i = 1; i <= nfaces; i++){
    TopoDS_Face face = TopoDS::Face(fmap(i));
    OCCFace *f = new OCCFace(model, face, i, emap);
    model->add(f);
  }
  // building geom regions
  int nvolumes = somap.Extent();
  for(int i = 1; i <= nvolumes; i++){
    TopoDS_Solid solid = TopoDS::Solid(somap(i));
    OCCRegion *r = new OCCRegion(model, solid, i, fmap);
    model->add(r);
  }
}

int GModel::readOCCSTEP(const std::string &fn)
{
  _occ_internals = new OCC_Internals;
  _occ_internals->loadSTEP(fn.c_str());
  _occ_internals->buildLists();
  _occ_internals->buildGModel(this);
  return 1;
}

int GModel::readOCCIGES(const std::string &fn)
{
  _occ_internals = new OCC_Internals;
  _occ_internals->loadIGES(fn.c_str());
  _occ_internals->buildLists();
  _occ_internals->buildGModel(this);
  return 1;
}

int GModel::readOCCBREP(const std::string &fn)
{
  _occ_internals = new OCC_Internals;
  _occ_internals->loadBREP(fn.c_str());
  _occ_internals->buildLists();
  _occ_internals->buildGModel(this);
  snapGVertices();
  return 1;
}

void GModel::snapGVertices (void)
{
  viter vit = firstVertex();
  
  double tol = CTX.geom.tolerance; 	       
  
  while (vit != lastVertex()){
    std::list<GEdge*> edges = (*vit)->edges();
    for (std::list<GEdge*>::iterator it = edges.begin() ;
	 it != edges .end(); ++it){
      Range<double> parb = (*it)->parBounds(0);
      double t;	
      if ((*it)->getBeginVertex() == *vit){
	t = parb.low();
      }
      else if ((*it)->getEndVertex() == *vit){
	t = parb.high();
      }
      else throw;
      GPoint gp = (*it)->point(t);
      double d = sqrt ((gp.x()-(*vit)->x())*(gp.x()-(*vit)->x())+
		       (gp.y()-(*vit)->y())*(gp.y()-(*vit)->y())+
		       (gp.z()-(*vit)->z())*(gp.z()-(*vit)->z()));
      if (d > tol){
	(*vit)->setPosition(gp);
	Msg(WARNING, "Geom Vertex %d Corrupted (%12.5E)... Snap performed",(*vit)->tag(),d);
      }      
    }
    vit++;
  }
}

void GModel::deleteOCCInternals()
{
  if(_occ_internals) delete _occ_internals;
  _occ_internals = 0;
}

/*
  OCC Creation routines
*/

// This function has been inspired from SALOME
// It removes all duplicates from the geometry, starting
// from vertices, edges, faces, shells and solids
// This 
void OCC_Internals::removeAllDuplicates (const double &tolerance){
}


void AddSimpleShapes(TopoDS_Shape theShape, TopTools_ListOfShape& theList)
{
  if (theShape.ShapeType() != TopAbs_COMPOUND &&
      theShape.ShapeType() != TopAbs_COMPSOLID) {
    theList.Append(theShape);
    return;
  }

  TopTools_MapOfShape mapShape;
  TopoDS_Iterator It (theShape, Standard_True, Standard_True);

  for (; It.More(); It.Next()) {
    TopoDS_Shape aShape_i = It.Value();
    if (mapShape.Add(aShape_i)) {
      if (aShape_i.ShapeType() == TopAbs_COMPOUND ||
          aShape_i.ShapeType() == TopAbs_COMPSOLID) {
        AddSimpleShapes(aShape_i, theList);
      } else {
        theList.Append(aShape_i);
      }
    }
  }
}

void OCC_Internals::applyBooleanOperator(TopoDS_Shape tool,  const BooleanOperator & op)
{
  if (tool.IsNull()) return;
  if (shape.IsNull()) shape = tool;
  else{
    switch(op){
    case OCC_Internals::Add :
      {
	TopoDS_Shape theNewShape;	
	BRep_Builder B;
	TopoDS_Compound C;
	B.MakeCompound(C);
	TopTools_ListOfShape listShape1, listShape2;
	AddSimpleShapes(shape, listShape1);
	AddSimpleShapes(tool, listShape2);
	Standard_Boolean isCompound =
	  (listShape1.Extent() > 1 || listShape2.Extent() > 1);
	
	TopTools_ListIteratorOfListOfShape itSub1 (listShape1);
	for (; itSub1.More(); itSub1.Next()) {
	  TopoDS_Shape aValue1 = itSub1.Value();
	  TopTools_ListIteratorOfListOfShape itSub2 (listShape2);
	  for (; itSub2.More(); itSub2.Next()) {
	    TopoDS_Shape aValue2 = itSub2.Value();
	    BRepAlgoAPI_Common BO (aValue1, aValue2);
	    if (!BO.IsDone()) {
	      Msg(GERROR,"Boolean Add Operator can not be performed");
	    }
	    if (isCompound) {
	      TopoDS_Shape aStepResult = BO.Shape();
	      if (aStepResult.ShapeType() == TopAbs_COMPOUND) {
		TopoDS_Iterator aCompIter (aStepResult);
		for (; aCompIter.More(); aCompIter.Next()) {
		  B.Add(C, aCompIter.Value());
		}
	      }
	      else {
		B.Add(C, aStepResult);
	      }
	    }
	    else
	      theNewShape = BO.Shape();
	  }
	}
	if (isCompound) {
	  TopTools_ListOfShape listShapeC;
	  AddSimpleShapes(C, listShapeC);
	  TopTools_ListIteratorOfListOfShape itSubC (listShapeC);
	  bool isOnlySolids = true;
	  for (; itSubC.More(); itSubC.Next()) {
	    TopoDS_Shape aValueC = itSubC.Value();
	    if (aValueC.ShapeType() != TopAbs_SOLID) isOnlySolids = false;
	  }
	  if (isOnlySolids)
	    throw;
	    //	    theNewShape = GEOMImpl_GlueDriver::GlueFaces(C, Precision::Confusion());
	  else
	    theNewShape = C;
	}	
      }
      break;
    case OCC_Internals::Cut :
      {
      }
    default :
      throw;
    }
  }
}
  
void OCC_Internals::Sphere(const SPoint3 & center, const double & radius,
			   const BooleanOperator & op)
{
  // build a sphere
  gp_Pnt aP(center.x(), center.y(), center.z());  
  TopoDS_Shape aShape = BRepPrimAPI_MakeSphere(aP, radius).Shape(); 
  // either add it to the current shape, or use it as a tool and remove the
  // sphere from the current shape
  applyBooleanOperator(aShape,  op);
}

#else

int GModel::readOCCSTEP(const std::string &fn)
{
  Msg(GERROR, "Gmsh has to be compiled with OpenCascade support to load '%s'",
      fn.c_str());
  return 0;
}

int GModel::readOCCIGES(const std::string &fn)
{
  Msg(GERROR, "Gmsh has to be compiled with OpenCascade support to load '%s'",
      fn.c_str());
  return 0;
}

int GModel::readOCCBREP(const std::string &fn)
{
  Msg(GERROR, "Gmsh has to be compiled with OpenCascade support to load '%s'",
      fn.c_str());
  return 0;
}

void GModel::deleteOCCInternals()
{
}

#endif
