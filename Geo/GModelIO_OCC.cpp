// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "GmshConfig.h"
#include "GmshMessage.h"
#include "GModelIO_OCC.h"
#include "Context.h"
#include "OCCVertex.h"
#include "OCCEdge.h"
#include "OCCFace.h"
#include "OCCRegion.h"
#include "MElement.h"
#include "MLine.h"
#include "OpenFile.h"
#include "OCC_Connect.h"

#if defined(HAVE_OCC_MESH_CONSTRAINTS)
#include "MeshGmsh_Constrain.hxx"
#include "MeshGmsh_VertexConstrain.hxx"
#include "MeshGmsh_EdgeConstrain.hxx"
#endif

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

void OCC_Internals::healGeometry(double tolerance, bool fixsmalledges, 
                                 bool fixspotstripfaces, bool sewfaces, 
                                 bool makesolids, bool connect)
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

  Msg::Info("Healing geometry (tolerance=%g)", tolerance);

  if(fixsmalledges){
    Msg::Info("- fixing small edges");

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
          Msg::Info("Fixed small edge in wire %d", wmap.FindIndex(oldwire));
          TopoDS_Wire newwire = sfw->Wire();
          rebuild->Replace(oldwire, newwire, Standard_False);
        }
        if((sfw->StatusSmall(ShapeExtend_FAIL1)) ||
           (sfw->StatusSmall(ShapeExtend_FAIL2)) ||
           (sfw->StatusSmall(ShapeExtend_FAIL3)))
          Msg::Info("Failed to fix small edge in wire %d",  wmap.FindIndex(oldwire));
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
            Msg::Info("removing degenerated edge %d", emap.FindIndex(edge));
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
      Msg::Info("- fixing wire frames");
      if(sfwf->StatusSmallEdges(ShapeExtend_OK)) Msg::Info("no small edges found");
      if(sfwf->StatusSmallEdges(ShapeExtend_DONE1)) Msg::Info("some small edges fixed");
      if(sfwf->StatusSmallEdges(ShapeExtend_FAIL1)) Msg::Info("failed to fix some small edges");
    }
  
    if(sfwf->FixWireGaps()){
      Msg::Info("- fixing wire gaps");
      if(sfwf->StatusWireGaps(ShapeExtend_OK)) Msg::Info("no gaps found");
      if(sfwf->StatusWireGaps(ShapeExtend_DONE1)) Msg::Info("some 2D gaps fixed");
      if(sfwf->StatusWireGaps(ShapeExtend_DONE2)) Msg::Info("some 3D gaps fixed");
      if(sfwf->StatusWireGaps(ShapeExtend_FAIL1)) Msg::Info("failed to fix some 2D gaps");
      if(sfwf->StatusWireGaps(ShapeExtend_FAIL2)) Msg::Info("failed to fix some 3D gaps");
    }
    
    shape = sfwf->Shape();
  }
  
  if(fixspotstripfaces){
    Msg::Info("- fixing spot and strip faces");
    Handle(ShapeFix_FixSmallFace) sffsm = new ShapeFix_FixSmallFace;
    sffsm->Init(shape);
    sffsm->SetPrecision(tolerance);
    sffsm->Perform();
    
    shape = sffsm->FixShape();
  }
  
  if(sewfaces){
    Msg::Info("- sewing faces");

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
      Msg::Info(" not possible");
  }
  
  if(makesolids){  
    Msg::Info("- making solids");
    
    TopExp_Explorer exp0;
    
    BRepBuilderAPI_MakeSolid ms;
    int count = 0;
    for(exp0.Init(shape, TopAbs_SHELL); exp0.More(); exp0.Next()){
      count++;
      ms.Add(TopoDS::Shell(exp0.Current()));
    }
    
    if(!count){
      Msg::Info(" not possible (no shells)");
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
        Msg::Info(" not possible");
    }
  }

  if(connect) {
    OCC_Connect connect; 
    for(TopExp_Explorer p(shape,TopAbs_SOLID); p.More(); p.Next())
        connect.Add(p.Current()); 
    connect.Connect();
    shape=connect;
  }
}

void OCC_Internals::loadBREP(const char *fn)
{
  BRep_Builder aBuilder;
  BRepTools::Read(shape, (char*)fn, aBuilder);
  BRepTools::Clean(shape);
  healGeometry(CTX::instance()->geom.tolerance, 
               CTX::instance()->geom.occFixSmallEdges,
               CTX::instance()->geom.occFixSmallFaces,
               CTX::instance()->geom.occSewFaces,
               false,
               CTX::instance()->geom.occConnectFaces);
  BRepTools::Clean(shape);
  buildLists();
}

void OCC_Internals::writeBREP(const char *fn)
{
  BRepTools::Write(shape, (char*)fn);
}

void OCC_Internals::loadSTEP(const char *fn)
{
  STEPControl_Reader reader;
  reader.ReadFile((char*)fn);
  reader.NbRootsForTransfer();
  reader.TransferRoots(); 
  shape = reader.OneShape();  
  BRepTools::Clean(shape);
  healGeometry(CTX::instance()->geom.tolerance, 
               CTX::instance()->geom.occFixSmallEdges,
               CTX::instance()->geom.occFixSmallFaces,
               CTX::instance()->geom.occSewFaces,
               false,
               CTX::instance()->geom.occConnectFaces);
  BRepTools::Clean(shape);
  buildLists();
}

void OCC_Internals::writeSTEP(const char *fn)
{
  STEPControl_Writer writer;
  IFSelect_ReturnStatus status = writer.Transfer( shape, STEPControl_ManifoldSolidBrep ) ;
  if ( status == IFSelect_RetDone ) 
    status = writer.Write( (char*) fn) ;
}

void OCC_Internals::loadIGES(const char *fn)
{
  IGESControl_Reader reader;
  reader.ReadFile((char*)fn);
  reader.NbRootsForTransfer();
  reader.TransferRoots(); 
  shape = reader.OneShape();  
  BRepTools::Clean(shape);
  healGeometry(CTX::instance()->geom.tolerance, 
               CTX::instance()->geom.occFixSmallEdges,
               CTX::instance()->geom.occFixSmallFaces,
               CTX::instance()->geom.occSewFaces,
               false,
               CTX::instance()->geom.occConnectFaces);
  BRepTools::Clean(shape);
  buildLists();
}

void OCC_Internals::loadShape(const TopoDS_Shape *s)
{
  shape = *s;
  BRepTools::Clean(shape);
  buildLists();
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
    GVertex *v1 = model->getVertexByTag(i1);
    GVertex *v2 = model->getVertexByTag(i2);
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

void OCC_Internals::removeAllDuplicates(const double &tolerance)
{
}

static void addSimpleShapes(TopoDS_Shape theShape, TopTools_ListOfShape &theList)
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
        addSimpleShapes(aShape_i, theList);
      } 
      else {
        theList.Append(aShape_i);
      }
    }
  }
}

void GModel::addShape(std::string name, std::vector<double> &p, 
                      std::string op)
{
  if (!_occ_internals)
    _occ_internals = new OCC_Internals;
  
  OCC_Internals::BooleanOperator o = OCC_Internals::Intersection;
  if(op == "Cut") o = OCC_Internals::Cut;
  else if(op == "Section") o = OCC_Internals::Section;
  else if(op == "Fuse" || op == "Union") o = OCC_Internals::Fuse;
  else if(op == "Intersection") o = OCC_Internals::Intersection;
  
  try{
    if (name == "Sphere"){
      if (p.size() != 4){
        Msg::Error("4 parameters have to be defined for a sphere");
        return;
      }
      _occ_internals->Sphere(SPoint3(p[0],p[1],p[2]),p[3],o);
    }
    else if (name == "Cylinder"){
      if (p.size() != 8){
        Msg::Error("8 parameters have to be defined for a Cylinder");
        return;
      }
      _occ_internals->Cylinder(SPoint3(p[0],p[1],p[2]),
                               SVector3(p[3],p[4],p[5]),p[6],p[7],o);
    }
    else if (name == "Torus"){
      if (p.size() == 8){
        _occ_internals->Torus(SPoint3(p[0],p[1],p[2]),
                              SVector3(p[3],p[4],p[5]),p[6],p[7],o);
      }
      else if (p.size() == 9){
        _occ_internals->Torus(SPoint3(p[0],p[1],p[2]),
                              SVector3(p[3],p[4],p[5]),p[6],p[7],p[8],o);
      }
      else{
        Msg::Error("Wrong number of parameters for a Torus (8 or 9 is OK)");
        return;
      }
    }
    else if (name == "Cone"){
      if (p.size() != 9){
        Msg::Error("9 parameters have to be defined for a Cone");
        return;
      }
      _occ_internals->Cone(SPoint3(p[0],p[1],p[2]),
                           SVector3(p[3],p[4],p[5]),p[6],p[7],p[8],o);
    }
    else if (name == "Box"){
      if (p.size() != 6){
        Msg::Error("6 parameters have to be defined for a Box");
        return;
      }
      _occ_internals->Box(SPoint3(p[0],p[1],p[2]),
                          SPoint3(p[3],p[4],p[5]),o);
    }
    else if (name=="Fillet"){
      std::vector<int> edges;
      for (int i=0;i<p.size()-1;i++)edges.push_back((int)p[i]);
      addOCCFillet(edges,p[p.size()-1]);
    }
    else{
      return;
    }
    destroy();
    _occ_internals->buildLists();
    _occ_internals->buildGModel(this);
  }
  catch(Standard_Failure &err){
    Msg::Error("%s", err.GetMessageString());
  }


}

TopoDS_Shape  GlueFaces (const TopoDS_Shape& theShape,
			 const Standard_Real theTolerance)
{
  Msg::Error("glue !");
  return theShape;

//   Standard_Integer iErr, iWrn;
//   TopoDS_Shape aRes;
//   GEOMAlgo_Gluer aGluer;

//   aGluer.SetShape(theShape);
//   aGluer.SetTolerance(theTolerance);
//   aGluer.SetCheckGeometry(Standard_True);

//   aGluer.Perform();

//   iErr = aGluer.ErrorStatus();
//   if (iErr) {
//     switch (iErr) {
//     case 2:
//       Msg::Error("No vertices found in source shape");
//       break;
//     case 5:
//       Msg::Error("Source shape is Null");
//       break;
//     case 6:
//       Msg::Error("Result shape is Null");
//       break;
//     case 200:
//       Msg::Error("Error occured during check of geometric coincidence");
//       break;
//     default:
//       {
//         // description of all errors see in GEOMAlgo_Gluer.cxx
//         TCollection_AsciiString aMsg ("Error in GEOMAlgo_Gluer with code ");
//         aMsg += TCollection_AsciiString(iErr);
//         Msg::Error(aMsg.ToCString());
//         break;
//       }
//     }
//     return aRes;
//   }

//   aRes = aGluer.Result();

//   return aRes;
}

void OCC_Internals::Fillet(std::vector<TopoDS_Edge> & edgesToFillet,
			   double Radius){

  // create a tool for fillet
  BRepFilletAPI_MakeFillet fill (shape);
  for (int i=0;i<edgesToFillet.size();++i){
    fill.Add(edgesToFillet[i]);
  }
  for (int i = 1; i <= fill.NbContours(); i++) {
    fill.SetRadius(Radius, i, 1);
  }
  fill.Build();
  if (!fill.IsDone()) {
    Msg::Error("Fillet can't be computed on the given shape with the given radius");
    return;
  }
  shape = fill.Shape();

  if (shape.IsNull()) return;

  // Check shape validity
  BRepCheck_Analyzer ana (shape, false);
  if (!ana.IsValid()) {
    Msg::Error("Fillet algorithm have produced an invalid shape result");
  }


}


void GModel::addOCCFillet(std::vector<int> & edgesToFillet,
			  double &Radius)
{
  std::vector<TopoDS_Edge> toto;

  for (int i=0;i<edgesToFillet.size();++i){
    GEdge *ge = getEdgeByTag(edgesToFillet[i]);
    if (ge && ge->getNativeType() == GEntity::OpenCascadeModel){
      toto.push_back(*(TopoDS_Edge*)ge->getNativePtr());
    }  
  }
  _occ_internals->Fillet(toto,Radius);
}


void OCC_Internals::applyBooleanOperator(TopoDS_Shape tool, const BooleanOperator &op)
{
  if (tool.IsNull()) return;
  if (shape.IsNull()) shape = tool;
  else{
    switch(op){
    case OCC_Internals::Intersection :
      {
        TopoDS_Shape theNewShape;       
        BRep_Builder B;
        TopoDS_Compound C;
        B.MakeCompound(C);
        TopTools_ListOfShape listShape1, listShape2;
        addSimpleShapes(shape, listShape1);
        addSimpleShapes(tool, listShape2);
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
              Msg::Error("Boolean Intersection Operator can not be performed");
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
          addSimpleShapes(C, listShapeC);
          TopTools_ListIteratorOfListOfShape itSubC (listShapeC);
          bool isOnlySolids = true;
          for (; itSubC.More(); itSubC.Next()) {
            TopoDS_Shape aValueC = itSubC.Value();
            if (aValueC.ShapeType() != TopAbs_SOLID) isOnlySolids = false;
          }
          if (isOnlySolids)
            theNewShape = GlueFaces(C, Precision::Confusion());
          else
	    theNewShape = C;
        }
	shape = theNewShape;
      }
      break;
    case OCC_Internals::Cut :
      {
        TopoDS_Shape theNewShape;       
	BRep_Builder B;
	TopoDS_Compound C;
	B.MakeCompound(C);
	
	TopTools_ListOfShape listShapes, listTools;
	addSimpleShapes(shape, listShapes);
	addSimpleShapes(tool, listTools);
	
	Standard_Boolean isCompound = (listShapes.Extent() > 1);
	
	TopTools_ListIteratorOfListOfShape itSub1 (listShapes);
	for (; itSub1.More(); itSub1.Next()) {
	  TopoDS_Shape aCut = itSub1.Value();
	  // tools
	  TopTools_ListIteratorOfListOfShape itSub2 (listTools);
	  for (; itSub2.More(); itSub2.Next()) {
	    TopoDS_Shape aTool = itSub2.Value();
	    BRepAlgoAPI_Cut BO (aCut, aTool);
	    if (!BO.IsDone()) {
	      Msg::Error("Cut operation can not be performed on the given shapes");
	      return;
	    }
	    aCut = BO.Shape();
	  }
	  if (isCompound) {
	    if (aCut.ShapeType() == TopAbs_COMPOUND) {
	      TopoDS_Iterator aCompIter (aCut);
	      for (; aCompIter.More(); aCompIter.Next()) {
		B.Add(C, aCompIter.Value());
	      }
	    }
	    else {
	      B.Add(C, aCut);
	    }
	  }
	  else
	    theNewShape = aCut;
	}
	
	if (isCompound) {
	  TopTools_ListOfShape listShapeC;
	  addSimpleShapes(C, listShapeC);
	  TopTools_ListIteratorOfListOfShape itSubC (listShapeC);
	  bool isOnlySolids = true;
	  for (; itSubC.More(); itSubC.Next()) {
	    TopoDS_Shape aValueC = itSubC.Value();
	    if (aValueC.ShapeType() != TopAbs_SOLID) isOnlySolids = false;
	  }
	  if (isOnlySolids)
	    theNewShape = GlueFaces(C, Precision::Confusion());
	  else
	    theNewShape = C;
	}
	shape = theNewShape;
      }      
      break;
    case OCC_Internals::Fuse :
      {
	BRepAlgoAPI_Fuse BO (tool, shape);
	if (!BO.IsDone()) {
	  Msg::Error("Fuse operation can not be performed on the given shapes");
	}
	shape = BO.Shape();
      }
      break;
    case OCC_Internals::Section :
      {
	TopoDS_Shape theNewShape;
	BRep_Builder B;
	TopoDS_Compound C;
	B.MakeCompound(C);

	TopTools_ListOfShape listShapes, listTools;
	addSimpleShapes(shape, listShapes);
	addSimpleShapes(tool, listTools);
	
	Standard_Boolean isCompound = (listShapes.Extent() > 1);
	TopTools_ListIteratorOfListOfShape itSub1 (listShapes);
	for (; itSub1.More(); itSub1.Next()) {
	  TopoDS_Shape aValue1 = itSub1.Value();
	  TopTools_ListIteratorOfListOfShape itSub2 (listTools);
	  for (; itSub2.More(); itSub2.Next()) {
	    TopoDS_Shape aValue2 = itSub2.Value();
	    BRepAlgoAPI_Section BO (aValue1, aValue2, Standard_False);
	    BO.Approximation(Standard_True);
	    BO.Build();
	    if (!BO.IsDone()) {
	      Msg::Error("Section operation can not be performed on the given shapes");
	      return;
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
	if (isCompound)
	  theNewShape = C;
	shape = theNewShape;
      }
      break;
    default :
      Msg::Error("Requested boolean operation not implemented");
      break;
    }
  }
}
  
void OCC_Internals::Sphere(const SPoint3 &center, const double &radius,
                           const BooleanOperator &op)
{
  gp_Pnt aP(center.x(), center.y(), center.z());  
  TopoDS_Shape aShape = BRepPrimAPI_MakeSphere(aP, radius).Shape(); 
  // either add it to the current shape, or use it as a tool and remove the
  // sphere from the current shape
  applyBooleanOperator(aShape, op);
}

void OCC_Internals::Cylinder(const SPoint3 &p, const SVector3 &d, double R, double H,
			     const BooleanOperator &op)
{
  gp_Pnt aP(p.x(), p.y(), p.z());
  gp_Vec aV(d.x(), d.y(), d.z());
  gp_Ax2 anAxes(aP, aV);
  BRepPrimAPI_MakeCylinder MC (anAxes, R, H);
  MC.Build();
  if (!MC.IsDone()) {
    Msg::Error("Cylinder can't be computed from the given parameters");
    return;
  }
  TopoDS_Shape aShape = MC.Shape();
  if (aShape.IsNull()) return;
  applyBooleanOperator(aShape, op);
}

void OCC_Internals::Torus(const SPoint3 &p, const SVector3 &d, double R1, double R2,
			  const BooleanOperator &op)
{
  gp_Pnt aP(p.x(),p.y(),p.z());
  gp_Vec aV(d.x(),d.y(),d.z());
  gp_Ax2 anAxes (aP, aV);
  BRepPrimAPI_MakeTorus MC (anAxes, R1, R2);
  MC.Build();
  if (!MC.IsDone()) {
    Msg::Error("Torus can't be computed from the given parameters");
    return;
  }
  TopoDS_Shape aShape = MC.Shape();
  if (aShape.IsNull()) return;
  applyBooleanOperator(aShape, op);
}

void OCC_Internals::Torus(const SPoint3 &p, const SVector3 &d, double R1, double R2, 
			  double angle, const BooleanOperator &op)
{
  gp_Pnt aP(p.x(), p.y(), p.z());
  gp_Vec aV(d.x(), d.y(), d.z());
  gp_Ax2 anAxes(aP, aV);
  BRepPrimAPI_MakeTorus MC(anAxes, R1, R2, angle);
  MC.Build();
  if (!MC.IsDone()) {
    Msg::Error("Torus can't be computed from the given parameters");
    return;
  }
  TopoDS_Shape aShape = MC.Shape();
  if (aShape.IsNull()) return;
  applyBooleanOperator(aShape, op);
}

void OCC_Internals::Cone(const SPoint3 &p, const SVector3 &d, double R1, 
                         double R2, double H, const BooleanOperator &op)
{
  gp_Pnt aP(p.x(), p.y(), p.z());
  gp_Vec aV(d.x(), d.y(), d.z());
  gp_Ax2 anAxes(aP, aV);
  BRepPrimAPI_MakeCone MC(anAxes, R1, R2, H);
  MC.Build();
  if (!MC.IsDone()) {
    Msg::Error("Cone can't be computed from the given parameters");
    return;
  }
  TopoDS_Shape aShape = MC.Shape();
  if (aShape.IsNull()) return;
  applyBooleanOperator(aShape, op);
}

void OCC_Internals::Box(const SPoint3 &p1, const SPoint3 &p2,
			const BooleanOperator &op)
{
  gp_Pnt P1(p1.x(), p1.y(), p1.z());
  gp_Pnt P2(p2.x(), p2.y(), p2.z());
  BRepPrimAPI_MakeBox MB(P1, P2);
  MB.Build();
  if (!MB.IsDone()) {
    Msg::Error("Box can not be computed from the given point");
    return;
  }
  TopoDS_Shape  aShape = MB.Shape();
  applyBooleanOperator(aShape, op);
}

void GModel::_deleteOCCInternals()
{
  if(_occ_internals) delete _occ_internals;
  _occ_internals = 0;
}

int GModel::readOCCBREP(const std::string &fn)
{
  _occ_internals = new OCC_Internals;
  _occ_internals->loadBREP(fn.c_str());
  _occ_internals->buildGModel(this);
  snapVertices();
  return 1;
}

int GModel::readOCCSTEP(const std::string &fn)
{
  _occ_internals = new OCC_Internals;
  _occ_internals->loadSTEP(fn.c_str());
  _occ_internals->buildGModel(this);
  return 1;
}

int GModel::readOCCIGES(const std::string &fn)
{
  _occ_internals = new OCC_Internals;
  _occ_internals->loadIGES(fn.c_str());
  _occ_internals->buildGModel(this);
  return 1;
}

int GModel::writeOCCBREP(const std::string &fn)
{
  if (!_occ_internals){
    Msg::Error("No OCC Model Found");
    return 0;
  }
  else
    _occ_internals->writeBREP(fn.c_str());
  return 1;
}

int GModel::writeOCCSTEP(const std::string &fn)
{
  if (!_occ_internals){
    Msg::Error("No OCC Model Found");
    return 0;
  }
  else
    _occ_internals->writeSTEP(fn.c_str());
  return 1;
}

int GModel::importOCCShape(const void *shape)
{
  _occ_internals = new OCC_Internals;
  _occ_internals->loadShape((TopoDS_Shape*)shape);
  _occ_internals->buildGModel(this);
  snapVertices();
  SetBoundingBox();
  return 1;
}

#if defined(HAVE_OCC_MESH_CONSTRAINTS)

static void _applyOCCMeshConstraintsOnVertices
  (GModel *m, MeshGmsh_DataMapOfShapeOfVertexConstrain &constraints)
{ 
  for(GModel::viter it = m->firstVertex(); it != m->lastVertex(); ++it){
    GVertex *gv = *it;
    if(gv->getNativeType() != GEntity::OpenCascadeModel) continue;
    TopoDS_Shape *s = (TopoDS_Shape*)gv->getNativePtr();
    if(constraints.IsBound(*s)) {
      Msg::Debug("Found mesh contraints on vertex %d", gv->tag());
      const MeshGmsh_VertexConstrain &c(constraints.Find(*s));

      // 1) characteristic length constraint
      double lc = c.GetSize();
      if(lc >= 0.){
        Msg::Debug("... setting mesh size = %g", lc);
        gv->setPrescribedMeshSizeAtVertex(lc);
      }

      // 2) embedding constraint
      if(c.IsEmbedded() && !c.GetFace().IsNull()){
        TopoDS_Shape shape = c.GetFace();
        Standard_Integer nodeNum;
        c.GetNodeNumber(nodeNum);
        for(GModel::fiter it2 = m->firstFace(); it2 != m->lastFace(); ++it2){
          GFace *gf = *it2;
          if(gf->getNativeType() != GEntity::OpenCascadeModel) continue;
          TopoDS_Shape *shape2 = (TopoDS_Shape*)gf->getNativePtr();
          if(shape.IsSame(*shape2)){
            Msg::Debug("... embedding vertex %d in face %d", nodeNum, gf->tag());
            gv->mesh_vertices[0]->setNum(nodeNum);
            gf->addEmbeddedVertex(gv);
          }
        }
      }
    }
  }
}

static void _applyOCCMeshConstraintsOnEdges
  (GModel *m, MeshGmsh_DataMapOfShapeOfEdgeConstrain &constraints)
{
  for(GModel::eiter it = m->firstEdge(); it != m->lastEdge(); ++it){
    GEdge *ge = *it;
    if(ge->getNativeType() != GEntity::OpenCascadeModel) continue;
    TopoDS_Shape *s = (TopoDS_Shape*)ge->getNativePtr();
    if(constraints.IsBound(*s)) {
      Msg::Debug("Found mesh contraints on edge %d", ge->tag());
      const MeshGmsh_EdgeConstrain &c(constraints.Find(*s));

      // 1) prescribed mesh constraint
      if(c.IsMeshImposed()){
        TColStd_SequenceOfInteger nodeNum;
        c.GetNodesNumber(nodeNum);
        TColStd_SequenceOfReal nodePar;
        c.GetParameters(nodePar);
        int n = nodeNum.Length();
        if(n < 2){
          Msg::Error("We need at least two points in the edge constraint");
        }
        else if(nodePar.Length() != n){
          Msg::Error("Wrong number of parameters in edge constraint: %d != %d",
                     nodeNum.Length(), nodePar.Length());
        }
        else{
          // set the mesh as immutable
          ge->meshAttributes.Method == MESH_NONE;
          // set the correct tags on the boundary vertices
          bool invert = (nodePar.Value(1) > nodePar.Value(n));
          int numbeg = nodeNum.Value(invert ? n : 1);
          int numend = nodeNum.Value(invert ? 1 : n);
          Msg::Debug("... beg=%d end=%d", numbeg, numend);
          ge->getBeginVertex()->mesh_vertices[0]->setNum(numbeg);
          ge->getEndVertex()->mesh_vertices[0]->setNum(numend);
          // set the mesh on the edge
          for(int i = 2; i < n; i++){
            int num = nodeNum.Value(invert ? n - i + 1 : i);
            double u = nodePar.Value(invert ? n - i + 1 : i);
            GPoint p = ge->point(u);
            Msg::Debug("... adding mesh vertex num=%d u=%g xyz=(%g,%g,%g)",
                       num, u, p.x(), p.y(), p.z());
            MEdgeVertex *v = new MEdgeVertex(p.x(), p.y(), p.z(), ge, u);
            v->setNum(num);
            ge->mesh_vertices.push_back(v);
          }
          for(unsigned int i = 0; i < ge->mesh_vertices.size() + 1; i++){
            MVertex *v0 = (i == 0) ? 
              ge->getBeginVertex()->mesh_vertices[0] : ge->mesh_vertices[i - 1];
            MVertex *v1 = (i == ge->mesh_vertices.size()) ? 
              ge->getEndVertex()->mesh_vertices[0] : ge->mesh_vertices[i];
            ge->lines.push_back(new MLine(v0, v1));
          }
        }
      }

      // 2) embedding constraint
      if(c.IsEmbedded() && !c.GetFace().IsNull()){
        TopoDS_Shape shape = c.GetFace();
        for(GModel::fiter it2 = m->firstFace(); it2 != m->lastFace(); ++it2){
          GFace *gf = *it2;
          if(gf->getNativeType() != GEntity::OpenCascadeModel) continue;
          TopoDS_Shape *shape2 = (TopoDS_Shape*)gf->getNativePtr();
          if(shape.IsSame(*shape2)){
            Msg::Debug("... embedding edge in face %d", gf->tag());
            gf->addEmbeddedEdge(ge);
            // the surface might have this edge as an open wire: make
            // sure to remove it
            gf->delFreeEdge(ge);
          }
        }
      }
    }
  }

  // FIXME: compute better characteristic length for all edges with no
  // imposed mesh? Or mesh those edges directly (here?)
  for(GModel::eiter it = m->firstEdge(); it != m->lastEdge(); ++it){
    // ...
  }  
}
#endif

int GModel::applyOCCMeshConstraints(const void *constraints)
{
#if defined(HAVE_OCC_MESH_CONSTRAINTS)
  MeshGmsh_Constrain *c = (MeshGmsh_Constrain*)constraints;

  MeshGmsh_DataMapOfShapeOfVertexConstrain vertexConstraints;
  c->GetVertexConstrain(vertexConstraints);
  _applyOCCMeshConstraintsOnVertices(this,vertexConstraints);

  MeshGmsh_DataMapOfShapeOfEdgeConstrain edgeConstraints;
  c->GetEdgeConstrain(edgeConstraints);
  _applyOCCMeshConstraintsOnEdges(this,edgeConstraints);
  return 1;
#else
  return 0;
#endif
}

#else

void GModel::_deleteOCCInternals()
{
}

int GModel::readOCCBREP(const std::string &fn)
{
  Msg::Error("Gmsh must be compiled with OpenCascade support to load '%s'",
             fn.c_str());
  return 0;
}

int GModel::readOCCSTEP(const std::string &fn)
{
  Msg::Error("Gmsh must be compiled with OpenCascade support to load '%s'",
             fn.c_str());
  return 0;
}

int GModel::readOCCIGES(const std::string &fn)
{
  Msg::Error("Gmsh must be compiled with OpenCascade support to load '%s'",
             fn.c_str());
  return 0;
}

int GModel::writeOCCBREP(const std::string &fn)
{
  Msg::Error("Gmsh must be compiled with OpenCascade support to write '%s'",
             fn.c_str());
  return 0;
}

int GModel::writeOCCSTEP(const std::string &fn)
{
  Msg::Error("Gmsh must be compiled with OpenCascade support to write '%s'",
             fn.c_str());
  return 0;
}

int GModel::importOCCShape(const void *shape)
{
  Msg::Error("Gmsh must be compiled with OpenCascade support to import "
             "a TopoDS_Shape");
  return 0;
}

int GModel::applyOCCMeshConstraints(const void *constraints)
{
  Msg::Error("Gmsh must be compiled with OpenCascade support to apply "
             "OCC mesh constraints");
  return 0;
}

void GModel::addShape(std::string name, std::vector<double> &p, 
                      std::string op)
{
  Msg::Error("Gmsh must be compiled with OpenCascade support to apply "
             "Boolean Operators On Solids");
}

void GModel:: addOCCFillet(std::vector<int> & , double &){
  Msg::Error("Gmsh must be compiled with OpenCascade support to apply "
             "the Fillet operator");
}

#endif
